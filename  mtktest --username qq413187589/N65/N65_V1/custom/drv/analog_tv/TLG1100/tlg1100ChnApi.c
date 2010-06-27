/*****************************************************************************
* FILENAME
* tlg1100ChnApi.c
*
*
* ABSTRACT
* This file contains the code for the TLG1100 Ultra Low Power NTSC/PAL
* Tuner/Decoder Front End Application Programmer's Interface library.
*
* $Revision: 1.38 $
*
* (c) 2006 Telegent Systems
*****************************************************************************/


#include "tlg1100Hal.h"
#include "tlg1100Api.h"

int TLG_ReadAudioNotchPwr(uint32 base_addr, int read_num);
TLG1100DLL_API uint32 tlg_cur_fm_ssi = 0;

/*****************************************************************************
* ceil_log2
*
* 
*
*
*****************************************************************************/

/*
 * return the integer log2 of the given number. 
 * ceil==FALSE, truncated value (e.g ceil_log2(3, FALSE) = 1)
 * ceil==TRUE, ceiling value (e.g. ceil_log2(3, TRUE) = 2
 */
uint32 ceil_log2(uint32 a, bool ceil)
{
    uint32 pwr = ((uint32)1)<<31;
    int    l2  = 31;
    
    if (a == 0) return 0;

    /* find the highest power in a, that's its log2() */
    while ((a & pwr) == 0)
    {
        l2--;
        pwr >>= 1;
    }
    /* see if there is a remainder, if so add 1 for ceil() */
    if (ceil)
        if (a & ~pwr) /* any other bits besides first one? */
            l2++;
    return(l2);
}

/*****************************************************************************
* TLG_AvgFiltInit
*
* 
*
*
*****************************************************************************/

static int TLG_AvgFiltInit(p_tlg_avg_filter_t filter)
{
    int i;

    TLG_NULLPTR_CHECK(filter);

    for (i = 0; i < TLG_AVG_FILTER_DEPTH; i++)
        filter->taps[i] = 0;
    filter->num_sample  = 0;
    filter->cur_tap     = 0;

    return TLG_ERR_SUCCESS;
}


/*****************************************************************************
* TLG_AvgFiltGetNext
*
* This procedure keeps a running average of the last TLG_AVG_FILTER_DEPTH
* values supplied to it. It operates in two modes: startup mode and steady
* state mode. Startup mode is when there have been less than the required
* samples entered. When in this mode, totals are kept and averages are
* calculated on the closest power of 2 divisor. Here is an example of the
* tap fill pattern for TLG_AVG_FILTER_DEPTH == 16 (the x's indicate which
* samples are summed in the given tap). 
*                      num_sample
*     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
*  0  x
*  1  x  x
*  2     x  x
*  3  x  x  x  x
*  4     x  x  x  x
*  5        x  x  x  x
*t 6           x  x  x  x
*a 7  x  x  x  x  x  x  x  x
*p 8     x  x  x  x  x  x  x  x
*s 9        x  x  x  x  x  x  x  x
* 10           x  x  x  x  x  x  x  x
* 11              x  x  x  x  x  x  x  x
* 12                 x  x  x  x  x  x  x  x
* 13                    x  x  x  x  x  x  x  x
* 14                       x  x  x  x  x  x  x  x
* 15  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x  x
*
* The procedure returns the sum and the divisor (power of 2) rather than
* performing the averaging directly so additional calculations may be
* combined prior to applying the divide to maximize the precision of 
* integer math calculations.
* 
*****************************************************************************/


static uint32 TLG_AvgFiltGetNext(p_tlg_avg_filter_t filter, uint32 *val,
                                 uint32 *divisor)
{
    int bucket_start, bucket_end;
    int    i;

    TLG_NULLPTR_CHECK(filter);
    TLG_NULLPTR_CHECK(divisor);
    TLG_NULLPTR_CHECK(val);

    *divisor = 1;           /* 2^0 */

    if (filter->num_sample == TLG_AVG_FILTER_DEPTH)
    {
        /* tap steady state. Keep sum of last TLG_AVG_FILTER_DEPTH values.   */
        for (i = 0; i < TLG_AVG_FILTER_DEPTH; i++)
        {
            filter->taps[i] += *val;
        }
        *divisor = TLG_AVG_FILTER_DEPTH;
    } else {
        /* tap startup. Fill taps by creating buckets on 2^n boundaries      */
        filter->num_sample++;
        bucket_start = 1;       /* 2^0 */
        bucket_end   = 2;       /* 2^1 */
        while (bucket_start < TLG_AVG_FILTER_DEPTH*2)
        {
            if (filter->num_sample < bucket_start)
                for (i = bucket_start; i < bucket_start + filter->num_sample; i++)
                {
                    filter->taps[TLG_AVG_FILTER_IDX(i-1)] += *val;
                }
            else if (bucket_start <= filter->num_sample < bucket_end)
            {
                /*
                 * found bucket sample is in. Use this as divisor and fill
                 * taps (including those for next set of tap values)
                 */
                *divisor = bucket_start;
                for (i = filter->num_sample; i < bucket_end; i++)
                {
                    filter->taps[TLG_AVG_FILTER_IDX(i-1)] += *val;
                }
            }
            bucket_start   = bucket_end;
            bucket_end    *= 2;
        }
    }
    /** get current sum, and reset tap */
    *val                          = filter->taps[filter->cur_tap];
    filter->taps[filter->cur_tap] = 0;
    filter->cur_tap               = TLG_AVG_FILTER_IDX(filter->cur_tap + 1);
    return TLG_ERR_SUCCESS;
}
  
tlg_avg_filter_t    tlg_agc1_filt, tlg_agc2_filt, tlg_lock_filt;


/*****************************************************************************
* TLG_GetTVSSI
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_GetTVSSI(uint32 base_addr, uint16 *metric)
{
    uint16  reg, lock;
    uint32  agc1, agc2;
    uint32  divisor;
    bool    restart;
    int     agc_metric, vsync_metric;
    uint32  agc1_max =  TLG1100_ATOP_AGCCAL_LOOP1_ACC_MASK
                     >> TLG1100_ATOP_AGCCAL_LOOP1_ACC_SHIFT;
    uint32  agc2_max =  TLG1100_ATOP_AGCCAL_LOOP2_ACC_MASK
                     >> TLG1100_ATOP_AGCCAL_LOOP2_ACC_SHIFT;
/*   uint32  lock_max =  (TLG1100_LOCK_MASK&~TLG1100_VSYNC_SLOCK) 
//                     >> TLG1100_LOCK_SHIFT; */

    TLG_NULLPTR_CHECK(metric);

    TLG_ReadRegNS(base_addr, TLG1100_ATOP_AGCCAL_STATUS2, &reg);
    TLGHAL_GET(agc2, reg,    TLG1100_ATOP_AGCCAL_LOOP2_ACC_SHIFT,
                             TLG1100_ATOP_AGCCAL_LOOP2_ACC_MASK);

    TLG_ReadRegNS(base_addr, TLG1100_ATOP_AGCCAL_STATUS3, &reg);
    TLGHAL_GET(agc1, reg,    TLG1100_ATOP_AGCCAL_LOOP1_ACC_SHIFT,
                             TLG1100_ATOP_AGCCAL_LOOP1_ACC_MASK);

    TLG_REG_LOG((b, "raw: agc1=%d, agc2 = %d\n", agc1, agc2));
    TLG_AvgFiltGetNext(&tlg_agc2_filt, &agc2, &divisor);
    TLG_AvgFiltGetNext(&tlg_agc1_filt, &agc1, &divisor);
    agc1 /= divisor;    
    agc2 /= divisor;
    
    TLG_ReadRegNS(base_addr, TLG1100_LOCK_DETECTOR, &lock);

    /** If the agc2 loop is over half its max value, then the              **
     ** metric is weighted .75 agc2, .25 agc1. Otherwise the agc           **
     ** loop values are treated equally. If there are video lock           **
     ** issues, the metric is halved                                       **/
    if (agc2 >= agc2_max/2)
        agc_metric = (2 - (agc1*2)/agc1_max) + (6 - (agc2*6)/agc2_max);
    else
        agc_metric = 8 - (8*(agc1 + agc2))/(agc1_max + agc2_max);
    /** obtain avg quality measure of vsync and scale it 0-8               **/
    /** metric is weighted 2/3 agc gain power, 1/3 vsync quality           **/
    TLG_ReadRegNS(base_addr, TLG1100_VSYNC_STAT2, &reg);
    vsync_metric = min(8,max(0, 8 - (reg - 64)/70));
    *metric = (vsync_metric + 2*agc_metric)/3;
    /** if vsync isn't locked then max rssi is 1                           **/
    if (!(lock & TLG1100_VSYNC_LOCK))
        *metric = min(1, agc_metric);
    /** if no chroma lock, then visually quality is 1 less than normal     **/
    else if (!(lock & TLG1100_CHROMA_LOCK))
        (*metric)--;
    TLG_REG_LOG((b,"agc_metric=%d, vsync_metric=0x%x, metric=%d\n", 
                 agc_metric, vsync_metric, *metric));
    if (*metric > 8) *metric = 8;
    
    TLG_GetChnRestartStatus(base_addr, &restart);
    if (restart) {
        TLG_SoftReset(base_addr);
    }
    
#ifdef TLG_VSCREEN_LOCK
    TLG_LockVScreen(base_addr);
#endif

    return TLG_ERR_SUCCESS;
}


/*****************************************************************************
* TLG_GetFMSSI
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_GetFMSSI(uint32 base_addr, uint16 *metric)
{
    int i, start = 60;

    *metric = TLG_ReadAudioNotchPwr(base_addr, 10);
#if 0 //hongzhe.liu
    for (i = 2; i < TLG_NUM_SSI_METRIC; i++)
    {
        if (*metric <= start)
            break;
        start += i*10;
    }
    *metric = i;
#endif
    return TLG_ERR_SUCCESS;
}


/* bandwith setting begin */

/*****************************************************************************
* TLG_GetChnBandwidth
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_GetChnBandwidth(uint32 base_addr,  uint16 *bw)
{
    uint16 reg22;
    uint16 forceVal;

    TLG_NULLPTR_CHECK(bw); 

    TLG_ReadReg(base_addr, TLG1100_ATOP_FILT_CAL_2, &reg22);
    TLGHAL_GET(forceVal, reg22, EDGE_CNT_FORCE_VAL_SHIFT, EDGE_CNT_FORCE_VAL_MASK);

    switch(forceVal)
    {
    case EDGE_CNT_FORCE_VAL_8: /*8 MHZ*/
         *bw = TLG_BW_8;
         break;
    case EDGE_CNT_FORCE_VAL_6: /*6MHZ*/
          *bw = TLG_BW_6;
          break;
    case EDGE_CNT_FORCE_VAL_5: /*5MHz*/
          *bw = TLG_BW_5;
          break;
    default: 
          return (TLG_ERR_FAIL);
    }
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetChnBandwidth
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetChnBandwidth(uint32 base_addr, uint16 bw)
{
    switch(bw)
    {
    case TLG_BW_8: /*8 MHZ*/
    case TLG_BW_7: /*7 MHZ*/
        TLG_WriteReg(base_addr,TLG1100_ATOP_FILT_CAL_1, FILT_FORCE_FC_VAL);
        TLG_WriteReg(base_addr,TLG1100_ATOP_FILT_CAL_2, EDGE_CNT_FORCE_VAL_8);
        break;

    case TLG_BW_6: /*6MHZ*/
        TLG_WriteReg(base_addr, TLG1100_ATOP_FILT_CAL_1,
                                    FILT_FORCE_FC_VAL | FILT_FC_F3P0);
        TLG_WriteReg(base_addr,TLG1100_ATOP_FILT_CAL_2, EDGE_CNT_FORCE_VAL_6);
        break;

    case TLG_BW_5:/*5MHz*/
        TLG_WriteReg(base_addr, TLG1100_ATOP_FILT_CAL_1,
                         FILT_FORCE_FC_VAL | FILT_FC_F3P0 | FILT_FC_F2P5);
        TLG_WriteReg(base_addr,TLG1100_ATOP_FILT_CAL_2, EDGE_CNT_FORCE_VAL_5); 
        break;
    default:
        return (TLG_ERR_PARAM); 
    }
    return(TLG_ERR_SUCCESS);
 }

/* bandwidth setting end */


/* mode setting begin*/



/*****************************************************************************
* TLG_TVAudioSetup
*
* 
*
*
*****************************************************************************/

static void TLG_TVAudioSetup(uint32 base_addr)
{
    uint16 data;

    TLG_ReadReg(base_addr,TLG1100_LUMA_PLL,&data);
    TLGHAL_SET(data, 1, TLG1100_LUNA_EN_SHIFT, TLG1100_LUNA_EN_MASK);  
    TLG_WriteReg(base_addr,TLG1100_LUMA_PLL,data);

    TLG_ReadReg(base_addr, TLG1100_DEMOD_HPF, &data);
    TLGHAL_CLEAR(data,TLG1100_DEMOD_HPF_CHN_FIL_MASK);
    TLGHAL_CLEAR(data,TLG1100_DEMOD_HPF_VID_PWR_MASK);
    TLG_WriteReg(base_addr,TLG1100_DEMOD_HPF,data);

    TLG_ReadReg(base_addr,TLG1100_SOUND_DEMOD3,&data);
    TLGHAL_CLEAR(data, TLG1100_SOUND_DEEMP_EN_MASK);
    TLG_WriteReg(base_addr,TLG1100_SOUND_DEMOD3,data);

}


/*****************************************************************************
* TLG_FMAudioSetup
*
* 
*
*
*****************************************************************************/

static void TLG_FMAudioSetup(uint32 base_addr)
{
    uint16 data;

    TLG_ReadReg(base_addr,TLG1100_LUMA_PLL,&data);
    TLGHAL_CLEAR(data,TLG1100_LUNA_EN_MASK);  
    TLG_WriteReg(base_addr,TLG1100_LUMA_PLL,data);

    TLG_ReadReg(base_addr,TLG1100_DEMOD_HPF,&data);
    TLGHAL_SET(data, 1, TLG1100_DEMOD_HPF_CHN_FIL_SHIFT,
                TLG1100_DEMOD_HPF_CHN_FIL_MASK);
    TLGHAL_SET(data, 1, TLG1100_DEMOD_HPF_VID_PWR_SHIFT, 
                TLG1100_DEMOD_HPF_VID_PWR_MASK);
    TLG_WriteReg(base_addr,TLG1100_DEMOD_HPF,data);

    TLG_ReadReg(base_addr,TLG1100_SOUND_DEMOD3,&data);
    TLGHAL_SET(data, 1, TLG1100_SOUND_DEEMP_EN_SHIFT,
                TLG1100_SOUND_DEEMP_EN_MASK); 
    TLG_WriteReg(base_addr,TLG1100_SOUND_DEMOD3,data);

}

/*****************************************************************************
* TLG_SetChnMode
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetChnMode(uint32 base_addr, uint16 mode)
{
    if      (mode == TLG_MODE_ANALOG_TV) TLG_TVAudioSetup(base_addr);
    else if (mode == TLG_MODE_FM_RADIO)  TLG_FMAudioSetup(base_addr);
    else return (TLG_ERR_PARAM);
    return(TLG_ERR_SUCCESS);
}

/* mode setting end */


/* standard setting begin*/

/*****************************************************************************
* TLG_SetChnStandard
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetChnStandard(uint32 base_addr, uint16 mode)
{
    uint16 videoStandard; 
    
    TLG_BOUNDS_CHECK(mode, TLG_VSTD_NONE);
   
    TLG_ReadReg(base_addr,TLG1100_VIDEO_STANDARD,&videoStandard);
    TLGHAL_SET(videoStandard, mode, 0,
            TLG1100_VIDEO_STANDARD_MASK );
    TLG_WriteReg(base_addr, TLG1100_VIDEO_STANDARD, videoStandard);
      
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_GetChnStandard
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_GetChnStandard(uint32 base_addr, uint16 *mode)
{
    uint16 videoStandard; 

    TLG_NULLPTR_CHECK(mode);
   
    TLG_ReadReg(base_addr,TLG1100_VIDEO_STANDARD,&videoStandard);
    TLGHAL_GET(*mode, videoStandard, 0,
            TLG1100_VIDEO_STANDARD_MASK );   
      
    return(TLG_ERR_SUCCESS);
}

/* standard setting end */



/* set TV Frequency begin */

#define ADJUST_TIME         30   /*adjust for calibartion delay*/ 
#define WAIT_DONE_TIMEOUT   20



/* The integer math takes place in several domains depending on what the correct
 * scaling and precision required is:
 * HZ domain    - All input into external API calls will be in HZ. This has the 
 *                necessary precision, but many calculations will overflow a
 *                uint32.
 * MHZ domain   - A lot of TLG_USE_FLOATING_POINT, some constants, and even
 *                a few integer calculations are done with values in MHZ.
 *                However, only floating point can deal with the decimal numbers
 *                required.
 * CVT domain   - This is a domain between HZ and MHZ that has been shown to
 *                have the precision required, but not overflow a uint32. By
 *                default CVT values in 100's of HZ (e.g. 1000HZ in CVT domain
 *                is 10).
 */
#define HZCVTUNITS  (100)  /* CVT domain in units of 100s Hz */

/* convert MHZ to CVT domain */
#define MHZCVT(a)  ((uint32)((a)*((uint32)1000000/(uint32)HZCVTUNITS)))

/* convert HZ to CVT domain */
#define HZCVT(a)   ((uint32)(((uint32)(a))/(uint32)HZCVTUNITS))

/* convert CVT domain to MHZ (note since its uint32, will trucate) */
#define CVTMHZ(a)  ((uint32)((((uint32)(a))*HZCVTUNITS)/(uint32)1000000))

#define BBFILCAL_F1         (54)                  /* MHZ */
#define BBFILCAL_F1_CVT     (MHZCVT(BBFILCAL_F1))
#define BBFILCAL_RF2        (753)                 /*  376.5*2 */
#define BBFILCAL_RLSB       (16000)               /* 8000*2   */
#define BBFILCAL_RCODEMAX   (31)
#define BBFILCAL_ROFFSET_1_1    (4)
#define BBFILCAL_ROFFSET_1_2    (-2)

static uint32 tlg_bbfilcal_mul[] = {   
                        (100), /* values are all scaled by *100 */
                        (111), /* 1.11 */
                        (124), /* 1.11*1.12 */
                        (142), /* 1.11*1.12*1.15*/
                        (167), /* 1.11*1.12*1.15*1.17 */
                        (202), /* 1.11*1.12*1.15*1.17*1.21 */
                        (257), /* 1.11*1.12*1.15*1.17*1.21*1.27 */
                        (354), /* 1.11*1.12*1.15*1.17*1.21*1.27*1.38 */
                        (599), /* 1.11*1.12*1.15*1.17*1.21*1.27*1.38*1.69*/
                        };



/*****************************************************************************
* TLG_BBFilter_Cal
*
* 
*
*
*****************************************************************************/

static void TLG_BBFilter_Cal(uint32 base_addr, uint32 freq_hz)
{
    uint32 freq_cvt = HZCVT(freq_hz);
    uint16 filcalStat;
    uint16 rcal;
    uint32 f_cvt, fb_cvt, f1b_cvt, fc, f;
    int    i;
    uint16 r=31, c=0;
    uint16 vhf2Hz, vhf1Hz;
    uint16 vhf2Cal, vhf1Cal;
    int32  BBFILCAL_ROFFSET;

    if (freq_cvt > MHZCVT(333))
    {
        TLG_ReadReg(base_addr,      TLG1100_VHF2_FREQ_CONTROL, &vhf2Hz);
        TLGHAL_SET(vhf2Hz, c,       TLG1100_VHF2_RCCAL_CAP_SHIFT,
                                    TLG1100_VHF2_RCCAL_CAP_MASK);
        TLG_WriteReg(base_addr,     TLG1100_VHF2_FREQ_CONTROL, vhf2Hz);

        TLG_ReadReg(base_addr,      TLG1100_VHF2_CAL_OVERRIDE, &vhf2Cal);
        TLGHAL_SET(vhf2Cal, r,      TLG1100_VHF2_CAL_OVERRIDE_RES_SHIFT,
                                    TLG1100_VHF2_CAL_OVERRIDE_RES_MASK);
        TLG_WriteReg(base_addr,     TLG1100_VHF2_CAL_OVERRIDE, vhf2Cal);

        TLG_ReadReg(base_addr,      TLG1100_VHF1_FREQ_CONTROL, &vhf1Hz);
        TLGHAL_SET(vhf1Hz, TLG_ON,  TLG1100_VHF1_FREQ_CTL_KILL_H3_SHIFT,
                                    TLG1100_VHF1_FREQ_CTL_KILL_H3_MASK);
        TLG_WriteReg(base_addr,     TLG1100_VHF1_FREQ_CONTROL, vhf1Hz);
        return;
    }
    /*  handle < 333 */

    TLG_ReadRegNS(base_addr, TLG1100_ATOP_FILCAL_STATUS1, &filcalStat);
    TLG_CHIP_VERS_1_2_BEGIN
        #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_1_2)
        TLGHAL_GET(rcal, filcalStat, TLG1100_ATOP_FILCAL_STATUS1_RCAL_SHIFT_1_2,
                                     TLG1100_ATOP_FILCAL_STATUS1_RCAL_MASK_1_2);
        BBFILCAL_ROFFSET = BBFILCAL_ROFFSET_1_2;
        #endif /* TLG_CMP_CHIP_1_2 */
    TLG_CHIP_VERS_1_1_ELSE
        #ifdef TLG_CMP_CHIP_1_1
        TLGHAL_GET(rcal, filcalStat, TLG1100_ATOP_FILCAL_STATUS1_RCAL_SHIFT_1_1,
                                     TLG1100_ATOP_FILCAL_STATUS1_RCAL_MASK_1_1);
        BBFILCAL_ROFFSET = BBFILCAL_ROFFSET_1_1;
        #endif /* TLG_CMP_CHIP_1_1 */
    TLG_CHIP_VERS_END
    
    f_cvt   = BBFILCAL_F1_CVT;
    f1b_cvt = (2124522000 /* pre-calculated numerator */
               /(BBFILCAL_RLSB + (BBFILCAL_ROFFSET + rcal)*BBFILCAL_RF2))*10;

    if (freq_cvt <= f_cvt)
    {
        /* scale f, fc by 1/100 to account for integer overflow */
        fc = freq_cvt/100;
        f  = ((BBFILCAL_F1_CVT * tlg_bbfilcal_mul[0])/100)/100;
        c  = 8;
        r  = (uint16)((fc*BBFILCAL_RLSB)/f
               + (fc*(rcal + BBFILCAL_ROFFSET)*BBFILCAL_RF2)/f
               - BBFILCAL_RLSB + (BBFILCAL_RF2-1))/BBFILCAL_RF2;
        if (r < 0) r = 0;
    } else
        for (i=0; i < 9; i++)
        {
            fb_cvt = (f1b_cvt * tlg_bbfilcal_mul[i])/100;
            if (freq_cvt > f_cvt && freq_cvt <= fb_cvt)
            {
                /* scale f, fc by 1/100 to account for integer overflow */
                fc = freq_cvt/100;
                f  = ((BBFILCAL_F1_CVT * tlg_bbfilcal_mul[i])/100)/100;
                c  = 8 - i;
                r  = (uint16)((fc*BBFILCAL_RLSB)/f
                    + (fc*(rcal + BBFILCAL_ROFFSET)*BBFILCAL_RF2)/f
                    - BBFILCAL_RLSB + (BBFILCAL_RF2-1))/BBFILCAL_RF2;
                break;
            }
            f_cvt  = fb_cvt;
        } 
    
    /* if no range found above, then c=0, r=31 */      
    TLG_ReadReg(base_addr, TLG1100_VHF2_FREQ_CONTROL, &vhf2Hz);
    TLGHAL_SET(vhf2Hz, c, TLG1100_VHF2_RCCAL_CAP_SHIFT,
                TLG1100_VHF2_RCCAL_CAP_MASK);
    TLG_WriteReg(base_addr, TLG1100_VHF2_FREQ_CONTROL, vhf2Hz);

    TLG_ReadReg(base_addr, TLG1100_VHF2_CAL_OVERRIDE, &vhf2Cal);
    TLGHAL_SET(vhf2Cal, r, TLG1100_VHF2_CAL_OVERRIDE_RES_SHIFT,
                TLG1100_VHF2_CAL_OVERRIDE_RES_MASK);
    TLG_WriteReg(base_addr, TLG1100_VHF2_CAL_OVERRIDE, vhf2Cal);

    TLG_ReadReg(base_addr, TLG1100_VHF1_FREQ_CONTROL, &vhf1Hz);
    TLGHAL_SET(vhf1Hz, c, TLG1100_VHF1_RCCAL_CAP_SHIFT,
                TLG1100_VHF1_RCCAL_CAP_MASK);
    TLGHAL_CLEAR(vhf1Hz, TLG1100_VHF1_FREQ_CTL_KILL_H5_MASK);
    TLGHAL_CLEAR(vhf1Hz, TLG1100_VHF1_FREQ_CTL_KILL_H3_MASK);
    TLG_WriteReg(base_addr, TLG1100_VHF1_FREQ_CONTROL, vhf1Hz);

    TLG_ReadReg(base_addr, TLG1100_VHF1_CAL_OVERRIDE, &vhf1Cal);
    TLGHAL_SET(vhf1Cal, r, TLG1100_VHF1_CAL_OVERRIDE_RES_SHIFT,
                TLG1100_VHF1_CAL_OVERRIDE_RES_MASK);
    TLG_WriteReg(base_addr, TLG1100_VHF1_CAL_OVERRIDE, vhf1Cal);
}

static       uint16  tlg_antenna = TLG_ANTENNA_DEF;

#ifdef TLG_TF_CALC_DCYCLE_BY_HZ
#define TLG_PAK_TF2DCYCLE(tf, clk_div)  ((((clk_div)&0x3) << 12) | ((tf)&0x3ff))
#define TLG_UNPAK_TF(a)                 ((a)&0x3ff)
#define TLG_UNPAK_CLKDIV(a) (           ((a)>>12)&0x3)
#define TLG_MAX_TF_CODE                 (0x3ff)

/*uint16 tlg_tfcal_2_dcycle[] = {
    TLG_PAK_TF2DCYCLE( 53, 1),
    TLG_PAK_TF2DCYCLE(119, 1),
    TLG_PAK_TF2DCYCLE(163, 1),
    TLG_PAK_TF2DCYCLE(196, 1),
    TLG_PAK_TF2DCYCLE(222, 2),
    TLG_PAK_TF2DCYCLE(244, 2),
    TLG_PAK_TF2DCYCLE(262, 2),
    TLG_PAK_TF2DCYCLE(278, 2),
    TLG_PAK_TF2DCYCLE(293, 2),
    TLG_PAK_TF2DCYCLE(306, 2),
    TLG_PAK_TF2DCYCLE(318, 2),
    TLG_PAK_TF2DCYCLE(328, 2),
    TLG_PAK_TF2DCYCLE(338, 2),
    TLG_PAK_TF2DCYCLE(348, 3),
    TLG_PAK_TF2DCYCLE(356, 3),
    TLG_PAK_TF2DCYCLE(364, 3),
    TLG_PAK_TF2DCYCLE(372, 3),
    TLG_PAK_TF2DCYCLE(379, 3),
    TLG_PAK_TF2DCYCLE(386, 3),
    TLG_PAK_TF2DCYCLE(393, 3),
    TLG_PAK_TF2DCYCLE(399, 3),
    TLG_PAK_TF2DCYCLE(405, 3),
    TLG_PAK_TF2DCYCLE(410, 3), 
    TLG_PAK_TF2DCYCLE(416, 3),
    TLG_PAK_TF2DCYCLE(421, 3),
    TLG_PAK_TF2DCYCLE(426, 3),
    TLG_PAK_TF2DCYCLE(TLG_MAX_TF_CODE, 3)
    };

int TLG_TFCal2Dcycle(uint16 cal_code, uint16 *dcycle, uint16 *clk_div)
{
    int i          = 0;
    uint16 tf_code = TLG_UNPAK_TF(tlg_tfcal_2_dcycle[0]);

    TLG_NULLPTR_CHECK(dcycle);
    TLG_NULLPTR_CHECK(clk_div);

    *dcycle  = 31;
    *clk_div = 3;

    while (tf_code != TLG_MAX_TF_CODE)
    {
        if (cal_code < tf_code)
        {
            *dcycle  = 5 + i;
            *clk_div = TLG_UNPAK_CLKDIV(tlg_tfcal_2_dcycle[i]);
            TLG_REG_LOG((b,"calcode=%d, dcycle=%d, clk_div=%d, pak=0x%x\n", cal_code, *dcycle, *clk_div, tlg_tfcal_2_dcycle[i]));
            break;
        } else {
            tf_code = TLG_UNPAK_TF(tlg_tfcal_2_dcycle[++i]);
        }
    }
    return TLG_ERR_SUCCESS;
}
*/

int TLG_TFCal2Dcycle(uint16 cal_code, uint16 *dcycle, uint16 *clk_div) {
    
    if      (cal_code <= 100)                   *dcycle = 3;
    else if (cal_code > 100 && cal_code <= 150) *dcycle = 4;
    else if (cal_code > 150 && cal_code <= 300) *dcycle = 5;
    else if (cal_code > 300 && cal_code <= 400) *dcycle = 6;
    else if (cal_code > 400 && cal_code <= 500) *dcycle = 7;
    else if (cal_code > 500 && cal_code <= 600) *dcycle = 8;
    else if (cal_code > 600 && cal_code <= 700) *dcycle = 10;
    else                                        *dcycle = 16;
    
    if (*dcycle <= 4)       *clk_div = 0;
    else if (*dcycle <=8)   *clk_div = 1;
    else if (*dcycle <=16)  *clk_div = 2;
    else                    *clk_div = 3;

    TLG_REG_LOG((b,"calcode=%d, dcycle=%d, clk_div=%d\n", cal_code, *dcycle, *clk_div));
    return TLG_ERR_SUCCESS;
}


TLG1100DLL_API int TLG_SetAntennaType(uint32 base_addr, uint16 antenna_type)
{
    tlg_antenna = antenna_type;
    return TLG_ERR_SUCCESS;
}

TLG1100DLL_API int TLG_GetAntennaType(uint32 base_addr, uint16 *antenna_type)
{
    TLG_NULLPTR_CHECK(antenna_type);
    *antenna_type = tlg_antenna;
    return TLG_ERR_SUCCESS;
}
#else 
/** 
 * dcycle calculation. The calculation of this value depends on which type
 * of antenna is being used. A paramaterized if then else tree is walked with
 * the values tuned for each antenna type.
 */
enum {
    VHF1_DCYCLE4_I=0,
    VHF1_DCYCLE6_I,
    VHF1_DCYCLE8_I,
    VHF2_DCYCLE4_I,
    VHF2_DCYCLE6_I,
    VHF2_DCYCLE8_I,
    UHF_DCYCLE4_I,
    UHF_DCYCLE6_I,
    UHF_DCYCLE8_I,
    UHF_DCYCLE12_I,
    DCYCLE_I_MAX
};

/** dcycle parameters for the default anntena TLG_ANTENNA_DEF:
*/
    #define  VHF1_DCYCLE4_MHZ  (66)
    #define  VHF1_DCYCLE6_MHZ  (82)
    #define  VHF1_DCYCLE8_MHZ  (108)

    #define  VHF2_DCYCLE4_MHZ  (186)
    #define  VHF2_DCYCLE6_MHZ  (216)
    #define  VHF2_DCYCLE8_MHZ  (280)

    #define  UHF_DCYCLE4_MHZ   (494)
    #define  UHF_DCYCLE6_MHZ   (620)
    #define  UHF_DCYCLE8_MHZ   (674)
    #define  UHF_DCYCLE12_MHZ  (734)

    #define  VHF1_DCYCLE4_CVT MHZCVT(VHF1_DCYCLE4_MHZ)
    #define  VHF1_DCYCLE6_CVT MHZCVT(VHF1_DCYCLE6_MHZ)
    #define  VHF1_DCYCLE8_CVT MHZCVT(VHF1_DCYCLE8_MHZ)

    #define  VHF2_DCYCLE4_CVT MHZCVT(VHF2_DCYCLE4_MHZ)
    #define  VHF2_DCYCLE6_CVT MHZCVT(VHF2_DCYCLE6_MHZ)
    #define  VHF2_DCYCLE8_CVT MHZCVT(VHF2_DCYCLE8_MHZ)

    #define  UHF_DCYCLE4_CVT  MHZCVT(UHF_DCYCLE4_MHZ)
    #define  UHF_DCYCLE6_CVT  MHZCVT(UHF_DCYCLE6_MHZ)
    #define  UHF_DCYCLE8_CVT  MHZCVT(UHF_DCYCLE8_MHZ)
    #define  UHF_DCYCLE12_CVT MHZCVT(UHF_DCYCLE12_MHZ)

static const uint32 dcycleAntennaDef[DCYCLE_I_MAX] = {
    VHF1_DCYCLE4_CVT,
    VHF1_DCYCLE6_CVT,
    VHF1_DCYCLE8_CVT,

    VHF2_DCYCLE4_CVT,
    VHF2_DCYCLE6_CVT,
    VHF2_DCYCLE8_CVT,

    UHF_DCYCLE4_CVT,
    UHF_DCYCLE6_CVT,
    UHF_DCYCLE8_CVT,
    UHF_DCYCLE12_CVT
};

/** dcycle parameters for the special TLG_ANTENNA_HDPH.
*/
    #define  VHF1_DCYCLE4_HDPH_MHZ  (0)
    #define  VHF1_DCYCLE6_HDPH_MHZ  (0)
    #define  VHF1_DCYCLE8_HDPH_MHZ  (66)

    #define  VHF2_DCYCLE4_HDPH_MHZ  (150)
    #define  VHF2_DCYCLE6_HDPH_MHZ  (151)
    #define  VHF2_DCYCLE8_HDPH_MHZ  (178)

    #define  VHF1_DCYCLE4_HDPH_CVT MHZCVT(VHF1_DCYCLE4_HDPH_MHZ)
    #define  VHF1_DCYCLE6_HDPH_CVT MHZCVT(VHF1_DCYCLE6_HDPH_MHZ)
    #define  VHF1_DCYCLE8_HDPH_CVT MHZCVT(VHF1_DCYCLE8_HDPH_MHZ)

    #define  VHF2_DCYCLE4_HDPH_CVT MHZCVT(VHF2_DCYCLE4_HDPH_MHZ)
    #define  VHF2_DCYCLE6_HDPH_CVT MHZCVT(VHF2_DCYCLE6_HDPH_MHZ)
    #define  VHF2_DCYCLE8_HDPH_CVT MHZCVT(VHF2_DCYCLE8_HDPH_MHZ)

static const uint32 dcycleAntennaHdPh[DCYCLE_I_MAX] = {
    VHF1_DCYCLE4_HDPH_CVT,
    VHF1_DCYCLE6_HDPH_CVT,
    VHF1_DCYCLE8_HDPH_CVT,

    VHF2_DCYCLE4_HDPH_CVT,
    VHF2_DCYCLE6_HDPH_CVT,
    VHF2_DCYCLE8_HDPH_CVT,

    UHF_DCYCLE4_CVT,
    UHF_DCYCLE6_CVT,
    UHF_DCYCLE8_CVT,
    UHF_DCYCLE12_CVT
};

static const uint32 *antenna_dcycle_parmlist[] = {
        dcycleAntennaDef,                       /* TLG_ANTENNA_DEF  */
        dcycleAntennaHdPh                       /* TLG_ANTENNA_HDPH */
};
static const uint32 *dcycle_parm = dcycleAntennaDef;


/*****************************************************************************
* TLG_SetAntennaType
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetAntennaType(uint32 base_addr, uint16 antenna_type)
{
    TLG_BOUNDS_CHECK(antenna_type, TLG_ANTENNA_MAX);
    tlg_antenna = antenna_type;
    dcycle_parm = antenna_dcycle_parmlist[tlg_antenna];
    return TLG_ERR_SUCCESS;
}


/*****************************************************************************
* TLG_GetAntennaType
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_GetAntennaType(uint32 base_addr, uint16 *antenna_type)
{
    TLG_NULLPTR_CHECK(antenna_type);
    *antenna_type = tlg_antenna;
    return TLG_ERR_SUCCESS;
}



/*****************************************************************************
* TLG_GetDcycle
*
* 
*
*
*****************************************************************************/

static uint8 TLG_GetDcycle(uint32 freq_cvt, uint16 lna_mode)
{
    uint8 dcycle = 31;

    switch(lna_mode)
    {
      case TLG_LNA_VHF1:
          if(freq_cvt < dcycle_parm[VHF1_DCYCLE4_I])
             dcycle = 4;
          else if(freq_cvt < dcycle_parm[VHF1_DCYCLE6_I])
             dcycle = 6;
          else if(freq_cvt < dcycle_parm[VHF1_DCYCLE8_I])
             dcycle = 8;
          else 
              dcycle = 16;
           break;
      case TLG_LNA_VHF2:        
          if(freq_cvt < dcycle_parm[VHF2_DCYCLE4_I])
             dcycle = 4;
          else if(freq_cvt < dcycle_parm[VHF2_DCYCLE6_I])
             dcycle = 6;
          else if(freq_cvt < dcycle_parm[VHF2_DCYCLE8_I])
             dcycle = 8;
          else 
              dcycle = 16;
            break;
      case TLG_LNA_UHF:
          if(freq_cvt < dcycle_parm[UHF_DCYCLE4_I])
             dcycle = 4;
          else if(freq_cvt < dcycle_parm[UHF_DCYCLE6_I])
             dcycle = 6;
          else if(freq_cvt < dcycle_parm[UHF_DCYCLE8_I])
             dcycle = 8;
          else if(freq_cvt < dcycle_parm[UHF_DCYCLE12_I])
             dcycle = 16;
          else 
              dcycle = 31;
          break;
    }
    return dcycle;
}

#endif /* TLG_TF_CALC_DCYCLE_BY_HZ */

/*****************************************************************************
* TLG_TFCalibrationASYNC
*
* 
*
*
*****************************************************************************/
static void TLG_TFCalibrationASYNC( uint32 base_addr, 
                                    uint32 freq_hz, 
                                    uint16 lna_mode,
                                    tlg_statep state,
                                    int *ms)
{
    /* math in this routine is in CVT domain */
    uint32  freq_cvt = HZCVT(freq_hz);
    uint16   dcycle;
    uint8   sett_time; 
    uint8   disch_time;
    uint16  wait_time;
    uint16  search_limit;
    uint16  clk_div; 
    uint16  regData;
    uint16  reg18d,reg33,reg30;
    uint16  trkfilCal1;
    uint16  trkfilt_cal_code;
    uint16  old_search_limit;
    uint16  freeze_db;
    uint8   wait_done = 0;
      
    switch (state[0])
    {
    case TLG_STATE0:
    /* state[0] - state variable for this function
     * state[1] - old value of reg33 to restore at end of cal
     * state[2] - old value of reg30 to restore at end of cal
     * state[3] - old value of reg18d to restore at end of cal
     */
#ifdef TLG_TF_CALC_DCYCLE_BY_HZ
    dcycle = 16;
#else
    dcycle = TLG_GetDcycle(freq_cvt, lna_mode);
#endif
#define MIXER_OFF_FOR_TFCAL
#ifdef MIXER_OFF_FOR_TFCAL
    TLG_ReadReg(base_addr, TLG1100_MXS_POWER, &regData);
    TLGHAL_SET(regData, TLG_ON, 12, BIT12);
    TLG_WriteReg(base_addr, TLG1100_MXS_POWER, regData);
#endif /* MIXER_OFF_FOR_TFCAL */
    TLG_ReadReg(base_addr, TLG1100_ATOP_TRKFIL_CAL_2, &regData);
    TLGHAL_GET(sett_time, regData, TLG1100_TRKFIL_SETT_TIME_SHIFT,
                                  TLG1100_TRKFIL_SETT_TIME_MASK);  

    TLG_ReadReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_4, &search_limit);
    TLG_ReadReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_1, &trkfilCal1);
    TLGHAL_GET(disch_time, trkfilCal1, TLG1100_ATOP_TRKFIL_DISCH_TIME_SHIFT,
                                   TLG1100_ATOP_TRKFIL_DISCH_TIME_MASK);  
    wait_time = (uint16)(((int32)(1000*(pow2(disch_time+8) + search_limit*pow2(sett_time+8)))+
                    (27000000-1))/27000000 + ADJUST_TIME);

    /* determine db to freeze on */

    if      (freq_hz >= TLG_UHF_CUTOFF_HZ)      freeze_db = 0x0c00;
    else if (freq_hz >= TLG_VHF2_CUTOFF_HZ)     freeze_db = 0x0600;
    else if (freq_hz >= TLG_VHF1_MID_CUTOFF_HZ) freeze_db = 0x0800;
    else                                        freeze_db = 0x0a00;

    /* save the registers */
    TLG_ReadReg(base_addr, TLG1100_ATOP_LNACAL_7,   &reg30);
    TLG_ReadReg(base_addr, TLG1100_TRKCTRL,         &reg18d);
    TLG_ReadReg(base_addr, TLG1100_ATOP_SARADC,     &reg33);
    TLG_WriteReg(base_addr,TLG1100_ATOP_LNACAL_5,   0x0600);
    TLG_WriteReg(base_addr,TLG1100_ATOP_LNACAL_6,   freeze_db);
    TLG_WriteReg(base_addr,TLG1100_ATOP_LNACAL_7,   0xc000);
    TLG_WriteReg(base_addr,TLG1100_TRKCTRL,         TLG1100_TRKCTRL_CAL_SETTING);
   
    regData  = reg33;
    TLGHAL_SET(regData, 1, TLG1100_SARADC_FREEZE_MUX_SHIFT,
                TLG1100_SARADC_FREEZE_MUX_MASK);
    TLG_WriteReg(base_addr,TLG1100_ATOP_SARADC,regData);
   
#ifdef TLG_TF_CALC_DCYCLE_BY_HZ
    clk_div = 2;
#else
    /* ckl_div=max(0, floor(log2(dcycle) - 1.1)) dcycle={4,6,8,16,31} */
    switch (dcycle)
    {
        case 4: clk_div=0;break;
        case 6: clk_div=1;break;
        case 8: clk_div=1;break;
        case 16:clk_div=2;break;
        case 31:clk_div=3;break;
        default:clk_div=3;break; /* should never happen */
    }
#endif
    TLGHAL_SET(trkfilCal1, dcycle, TLG1100_ATOP_TRKFIL_DCYLE_SHIFT,
                TLG1100_ATOP_TRKFIL_DCYLE_MASK );  
    TLGHAL_SET(trkfilCal1, clk_div, TLG1100_ATOP_TRKFIL_CMP_CLK_DIV_SHIFT,
                TLG1100_ATOP_TRKFIL_CMP_CLK_DIV_MASK );  
    TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_1,trkfilCal1);
    TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_3, 0);

    state[ 1] = reg33;
    state[ 2] = reg30;
    state[ 3] = reg18d;
#ifdef TLG_TF_CALC_DCYCLE_BY_HZ
    state[ 4] = trkfilCal1;
#endif

    state[ 0] = TLG_STATE2;
    *ms       = wait_time;
    break;

    case TLG_STATE2: 
    /* state[0] - state variable for this function
     * state[1] - old value of reg33 to restore at end of cal
     * state[2] - old value of reg30 to restore at end of cal
     * state[3] - old value of reg18d to restore at end of cal
     * state[4] - old_search_limit
     */
    TLG_WriteReg(base_addr, TLG1100_ATOP_SARADC,    state[ 1]);
    TLG_WriteReg(base_addr, TLG1100_ATOP_LNACAL_7,  state[ 2]);
    TLG_WriteReg(base_addr, TLG1100_TRKCTRL,        state[ 3]);
    TLG_WriteReg(base_addr, TLG1100_ATOP_LNACAL_6,  0x1200);

    TLG_ReadReg(base_addr,   TLG1100_ATOP_TRKFIL_CAL_4,       &old_search_limit);
    TLG_ReadRegNS(base_addr, TLG1100_ATOP_TRKFIL_CAL_STATUS6, &trkfilt_cal_code); 
    TLG_WriteReg(base_addr,  TLG1100_ATOP_TRKFIL_CAL_4,       0);
#ifdef TLG_TF_CALC_DCYCLE_BY_HZ
    TLG_TFCal2Dcycle(trkfilt_cal_code, &dcycle, &clk_div);
    TLG_REG_LOG((b,"cal_code=%d, dcycle=%d, clk_div=%d\n",trkfilt_cal_code, dcycle, clk_div));
    trkfilCal1 = state[4];
    TLGHAL_SET(trkfilCal1, dcycle, TLG1100_ATOP_TRKFIL_DCYLE_SHIFT,
                TLG1100_ATOP_TRKFIL_DCYLE_MASK );  
    TLGHAL_SET(trkfilCal1, clk_div, TLG1100_ATOP_TRKFIL_CMP_CLK_DIV_SHIFT,
                TLG1100_ATOP_TRKFIL_CMP_CLK_DIV_MASK );  
    TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_1,trkfilCal1);
#endif
    TLG_WriteReg(base_addr,  TLG1100_ATOP_TRKFIL_CAL_3,       trkfilt_cal_code); 
    state[0] = TLG_STATE3;
    state[4] = old_search_limit; /* save to restore after delay */
    *ms      = 5;
    break;

    case TLG_STATE3:
    /* state[0] - state variable for this function
     * state[4] - old_search_limit
     */
    old_search_limit = state[4];
    TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_4,old_search_limit);
#ifdef MIXER_OFF_FOR_TFCAL
    TLG_ReadReg(base_addr, TLG1100_MXS_POWER, &regData);
    TLGHAL_CLEAR(regData, BIT12);
    TLG_WriteReg(base_addr, TLG1100_MXS_POWER, regData);
#endif /* MIXER_OFF_FOR_TFCAL */
    state[0] = TLG_STATE_FINAL;
    *ms      = 0;
    break;

    default: 
    TLG_REG_LOG((b,"TLG_TFCalibrationASYNC: %d BADSTATE!\n", state[0]));
    break;
    }
}


#define BASE_VALUE_MHZ      ((uint32)1600)
#define BASE_VALUE_CVT      (MHZCVT(BASE_VALUE_MHZ))
#define NR_REF_DIVIDE       ((uint32)108)  /* IF CHANGED, INTEGER MATH MUST BE REDONE */


    /* these values have all been pre-scaled by ICP-SCALE */
    #define ICP_SCALE      ((uint32)10000)
    #define LO_SLOPE       ((uint32)1185)
    #define LO_OFFSET      ((uint32)346980)
    #define MID_SLOPE      ((uint32)1174)
    #define MID_OFFSET     ((uint32)443638)
    #define HI_SLOPE       ((uint32)1246)
    #define HI_OFFSET      ((uint32)625761)
    #define TARGET         ((uint32)30) 
    #define HALF_SYS_CLOCK_CVT  (HZCVT(13500000))


/*****************************************************************************
* getICP
*
* 
*
*
*****************************************************************************/

static int32 getICP(uint32 base_addr, uint16 ndiv)
{
 /* ICP is an interesting mix. It is not being done in CVT domain. Instead the
  * thresholds for slope/offset are in CVT, but the actual math for slope and
  * offset are being done with an independent scaling factor. This is because
  * CVT is the wrong precision, and the slopes aren't in the frequency domain
  * anyway. Finally, the kvco stuff is done in the MHZ domain because the CVT
  * domain combined with the scaling factor would overflow! 
  */ 
    
    uint32 vco_freq_cvt;
    int32  vco_freq_mhz;
    uint32 i_fcomp;
    uint32 vco_thresh_lomid_cvt;
    uint32 vco_thresh_midhi_cvt;
    int32  itarget = (TARGET*4);
    int32  icp_denom;
    int32  i_icp;
    uint16 reg1b2, reg1b3;

    vco_freq_cvt  = (MHZCVT(27)*ndiv)/NR_REF_DIVIDE;
    vco_freq_mhz  = (27*ndiv)/NR_REF_DIVIDE;
    i_fcomp       = (27000000 /NR_REF_DIVIDE);
  
    TLG_ReadReg(base_addr,TLG1100_VCOL_BS_NLO, &reg1b2);
    TLG_ReadReg(base_addr,TLG1100_VCOL_BS_NHI, &reg1b3);
    reg1b2 &=TLG1100_VCOL_BS_VALUE_MASK;
    reg1b3 &=TLG1100_VCOL_BS_VALUE_MASK;

    vco_thresh_lomid_cvt = MHZCVT(reg1b2)/(1000000/i_fcomp);
    vco_thresh_midhi_cvt = MHZCVT(reg1b3)/(1000000/i_fcomp);
    /*
     * convert vco HZ to MHZ for the icp calc. offset will be in MHZ too
     * we can do this because its always around 1-2MHZ
     */
    if (vco_freq_cvt < vco_thresh_lomid_cvt)
        icp_denom = (vco_freq_mhz*LO_SLOPE - 4*LO_OFFSET);
    else if (vco_freq_cvt < vco_thresh_midhi_cvt)
        icp_denom = (vco_freq_mhz*MID_SLOPE - 4*MID_OFFSET);
    else 
        icp_denom = (vco_freq_mhz*HI_SLOPE - 4*HI_OFFSET);

    i_icp = (((4*2*itarget*ndiv)+icp_denom))/(2*icp_denom);
  
    return max(2, i_icp);
}




/*****************************************************************************
* TLG_SetNotch
*
* 
*
*
*****************************************************************************/

static void  TLG_SetNotch(uint32 base_addr, uint32 center_freq_in)
{
    uint32 center_freq_cvt         = HZCVT(center_freq_in);
    
    int32 iF;
    int32 itF;
    uint16 bw; 
    uint16 regData;

    TLG_GetChnBandwidth(base_addr,  &bw);
    
    iF = center_freq_cvt % HALF_SYS_CLOCK_CVT;
    iF = (iF >= HALF_SYS_CLOCK_CVT/2) ? -iF + HALF_SYS_CLOCK_CVT : -iF;
    itF = (iF < 0) ? -iF : iF;
    
    regData = (uint16)((itF*0x10000+HALF_SYS_CLOCK_CVT/2)/HALF_SYS_CLOCK_CVT);

    if (iF < 0)
        regData |= (1<<15);
    else 
        regData &= ~(1<<15);
        
    TLG_WriteReg(base_addr,TLG1100_TONE_NOTCH2,regData);
}

/*****************************************************************************
* TLG_SetChnFreqASYNC
*
* 
*
*
*****************************************************************************/

static void  TLG_SetChnFreqASYNC(uint32 base_addr, uint32 center_freq_in, 
                            bool isCallCali, uint16 trk_code,
                            tlg_statep state, int *ms)
{
    uint32 center_freq         = HZCVT(center_freq_in);

    const uint32   UHF_CUTOFF_CVT  = HZCVT(TLG_UHF_CUTOFF_HZ);
    const uint32   VHF2_CUTOFF_CVT = HZCVT(TLG_VHF2_CUTOFF_HZ);

    uint16 lodiv;
    int32  icp;
    uint16 reg1a5, reg1a6;    
    uint16 lna_mode, mix_mode, vhf_cap_code;      
    uint16 log2lodiv;         
    uint16 regData; 
        

    switch (state[0])
    {
    case TLG_STATE0:
    TLG_AvgFiltInit(&tlg_agc1_filt);
    TLG_AvgFiltInit(&tlg_agc2_filt);
    TLG_AvgFiltInit(&tlg_lock_filt);
    lodiv     = (uint16)max(4, pow2(ceil_log2((BASE_VALUE_CVT+(center_freq-1))/center_freq, 1)));
    log2lodiv = ceil_log2(lodiv, 0);
    reg1a5    = (uint16)((lodiv*center_freq*NR_REF_DIVIDE + MHZCVT(27)/2)/MHZCVT(27));
    icp       = getICP(base_addr, reg1a5);
    TLG_REG_LOG((b,"hz=%d, lodiv=%d, icp=%d\n", center_freq_in, lodiv, icp));

    reg1a6 = (uint16)  ( ( (uint16)(log2lodiv - 2 ) << 11) |
             ( (uint16)(icp - 2) << 8  ) | NR_REF_DIVIDE);

    if (center_freq > UHF_CUTOFF_CVT)
    {
        lna_mode     = TLG_LNA_UHF;
        mix_mode     = 1;
        vhf_cap_code = 0;
    }
    else if (center_freq > VHF2_CUTOFF_CVT)
    {
        lna_mode     = TLG_LNA_VHF2;
        mix_mode     = 0;
        vhf_cap_code = 1;   
    }
    else
    {
        lna_mode = TLG_LNA_VHF1;
        mix_mode = 0;
        /** code = round(684/freq - 4)   */
        vhf_cap_code = (uint16)((2*(MHZCVT(684) - 4*center_freq) + center_freq)/(2*center_freq));
    }
	state[1] = lna_mode; /* save to use in TLG_STATE1 */

    TLG_WriteReg(base_addr,TLG1100_SYN_RDIVIDER,reg1a6);
    TLG_WriteReg(base_addr,TLG1100_SYN_NDIVIDER,reg1a5);
      
    TLG_ReadReg(base_addr,TLG1100_MXS_POWER, &regData);
    TLGHAL_SET(regData,lna_mode, TLG1100_LNA_MODE_SHIFT, TLG1100_LNA_MODE_MASK);
    TLG_WriteReg(base_addr,TLG1100_MXS_POWER,regData);

    TLG_ReadReg(base_addr,TLG1100_MIXER_BIAS, &regData);
    TLGHAL_SET(regData,mix_mode, TLG1100_MIX_UHFSEL_SHIFT, TLG1100_MIX_UHFSEL_MASK);
    TLG_WriteReg(base_addr,TLG1100_MIXER_BIAS,regData);

    TLG_ReadReg(base_addr,TLG1100_VHF2_FREQ_CONTROL, &regData);
    TLGHAL_SET(regData,vhf_cap_code, 0, TLG1100_VHF2_RCCAL_CAP_MASK);
    TLG_WriteReg(base_addr,TLG1100_VHF2_FREQ_CONTROL,regData);
      
    TLG_ReadReg(base_addr,TLG1100_VHF1_FREQ_CONTROL, &regData);
    TLGHAL_SET(regData,vhf_cap_code, 0, TLG1100_VHF1_RCCAL_CAP_MASK);
    TLG_WriteReg(base_addr,TLG1100_VHF1_FREQ_CONTROL,regData);   

	TLG_SetNotch(base_addr, center_freq_in);
    TLG_BBFilter_Cal(base_addr, center_freq_in);

    state[2] = TLG_STATE0; /* starts state vector for TFCalibrationASYNC() */                     

    state[0] = TLG_STATE1;
    *ms      = 5;       /* delay before starting tracking filter cal */
    break;

    case TLG_STATE1:
    /* state[0] - state variable for this function
     * state[1] - lna_mode
     * state[2] - state variable for TLG_TFCalibrationASYNC()
     */
    /* loop on TF_Calibration State machine */
    if (isCallCali && (trk_code == 0))
    {
		lna_mode = state[1]; /* carried over from TLG_STATE0 */
        TLG_TFCalibrationASYNC(base_addr, center_freq_in, lna_mode, &state[2], ms);
        if (state[2] != TLG_STATE_FINAL)
        {
            break;
        }
    }
    /* end of TF_Calibration State machine */
    /* state vector definition change:
     * state[0] : state variable for this function
     * state[1] : trk_code variable
     * state[2] : old_search_limit
     * state[3] : state variable for TLG_SoftResetASYNC()
     */
    state[1] = trk_code;        /* flag trk_code delay loop state machine     */
    state[0] = TLG_STATE2;      /* go to state 2                              */
    state[3] = TLG_STATE0;      /* starts state vector for TLG_SoftResetASYNC */
    
    /* if trk_code, then need a delay to settle tf cal */
    if (trk_code)
    {
        uint16  old_search_limit;
   
        TLG_ReadReg(base_addr, TLG1100_ATOP_TRKFIL_CAL_4, &old_search_limit);
        TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_4, 0);
        TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_3, trk_code); 
        state[2] = old_search_limit; /* save to restore in TLG_STATE2 */
        *ms      = 5;
        break;
    }
    
    case TLG_STATE2:
    /* state[0] : state variable for this function
     * state[1] : trk_code variable
     * state[2] : old_search_limit
     * state[3] : state variable for TLG_SoftResetASYNC()
     */
    /* if we are in the trk_code delay loop, restore old track code first */
    if (state[1])
    {
        TLG_WriteReg(base_addr,TLG1100_ATOP_TRKFIL_CAL_4,state[2]);
        state[1] = 0; /* clear trk_code delay loop condition */
    }

    /* loop through soft reset delay */
    TLG_SoftResetASYNC(base_addr, &state[3], ms);
    if (state[3] != TLG_STATE_FINAL)
        break;

    state[0] = TLG_STATE_FINAL;
    *ms      = 0;
    break;
    
    default: TLG_REG_LOG((b,"TLG_SetChnFreqASYNC: %d BADSTATE!\n", state[0]));
    break;
    }
}



/*****************************************************************************
* TLG_SetAVNotch
*
* 
*
*
*****************************************************************************/

static void TLG_SetAVNotch(uint32 base_addr, int32 freq_hz, uint16 bw, uint16 byp)
{
    uint16 regData;
    uint16 negfreq;
    uint32 freq_khz;
    uint16 toneHz;

    if(freq_hz <0)
    {
        negfreq = TLG_ON;
        freq_hz = -freq_hz;
    }
    else
        negfreq = TLG_OFF;

    freq_khz = freq_hz/1000;
    regData  = 0;
    toneHz = (uint16)((freq_khz<<16)/13500); /* khz*2^16/13500KHz */
    TLGHAL_SET(regData, toneHz, TLG1100_TONE_NOTCH2_HZ_SHIFT,
                TLG1100_TONE_NOTCH2_HZ_MASK);
    TLGHAL_SET(regData, negfreq, TLG1100_TONE_NOTCH2_NEG_SHIFT,
                TLG1100_TONE_NOTCH2_NEG_MASK);
    TLG_WriteReg(base_addr, TLG1100_TONE_NOTCH2, regData);

    TLG_ReadReg(base_addr, TLG1100_TONE_NOTCH1, &regData);
    TLGHAL_SET(regData, bw, TLG1100_TONE_NOTCH1_BW_SHIFT,
                TLG1100_TONE_NOTCH1_BW_MASK);
    TLGHAL_SET(regData, TLG_ON, TLG1100_TONE_NOTCH1_BYP_SHIFT,
                TLG1100_TONE_NOTCH1_BYP_MASK);
    TLGHAL_SET(regData, TLG_ON, TLG1100_TONE_NOTCH1_EN_SHIFT,
                TLG1100_TONE_NOTCH1_EN_MASK);    
    TLG_WriteReg(base_addr, TLG1100_TONE_NOTCH1, regData);

}


/*****************************************************************************
* TLG_ReadAudioNotchPwr
*
* 
*
*
*****************************************************************************/

int TLG_ReadNotchPwr(uint32 base_addr, int32 freq_hz, int read_num)
{
    int32  avg_ssi = 0;
    int32  pwr;
    uint16 notch1;
    uint16 notch2;
    uint16 notchStat2;
    uint16 agcStat3;
    int    i;
  

    TLG_ReadReg(base_addr, TLG1100_TONE_NOTCH1, &notch1);
    TLG_ReadReg(base_addr, TLG1100_TONE_NOTCH2, &notch2);

    TLG_SetAVNotch(base_addr, freq_hz, 0, 1);

    for(i = 0; i < read_num ; i++)
    {
       TLG_ReadRegNS(base_addr, TLG1100_TONE_NOTCH_STAT2, &notchStat2);
       TLG_ReadRegNS(base_addr, TLG1100_PEAK_RMS_AGC_STAT3, &agcStat3);
       avg_ssi += notchStat2 * agcStat3;
    }

    TLG_WriteReg(base_addr, TLG1100_TONE_NOTCH1, notch1);
    TLG_WriteReg(base_addr, TLG1100_TONE_NOTCH2, notch2);

    pwr = (avg_ssi>>10)/read_num;

    return (pwr);
}

int TLG_ReadLumaNotchPwr(uint32 base_addr, int read_num)
{
    int32  freq_hz=0;
    uint16 vstd;

    TLG_GetChnStandard(base_addr, &vstd);
    
    switch(vstd)
    {
    case TLG_VSTD_PAL_B  : freq_hz = -2250000; break;
    case TLG_VSTD_NTSC_M : 
    case TLG_VSTD_PAL_M  :
    case TLG_VSTD_PAL_N  : freq_hz = -1750000; break;
    default              : freq_hz = -2750000; break;
    }

    return TLG_ReadNotchPwr(base_addr, freq_hz, read_num);
}

int TLG_ReadAudioNotchPwr(uint32 base_addr, int read_num)
{
    int32  freq_hz;
    uint16 vstd;

    TLG_GetChnStandard(base_addr, &vstd);

    switch(vstd)
    {
    case TLG_VSTD_PAL_B     : 
    case TLG_VSTD_PAL_I     : freq_hz = 3250000; break;
    case TLG_VSTD_PAL_D     :
    case TLG_VSTD_PAL_D1    :
    case TLG_VSTD_PAL_K     : freq_hz = 3750000; break;
    default                 : freq_hz = 2750000; break;
    }

    return TLG_ReadNotchPwr(base_addr, freq_hz, read_num);
}


/*****************************************************************************
* TLG_SetTVChnFreqASYNC
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetTVChnFreqASYNC(uint32 base_addr, uint32 center_freq_hz, 
                          tlg_statep state, int *ms)
{
    uint16 reg;
    int    lf2=0;

    TLG_ReadReg(base_addr,TLG1100_LUMA_PLL3, &reg);
    TLGHAL_GET(lf2,reg,TLG1100_LUMA_PLL3_BYPLF2_SHIFT,TLG1100_LUMA_PLL3_BYPLF2_MASK);
    if (!lf2) {
        TLGHAL_SET(reg,1,TLG1100_LUMA_PLL3_BYPLF2_SHIFT,TLG1100_LUMA_PLL3_BYPLF2_MASK);
        TLG_WriteReg(base_addr,TLG1100_LUMA_PLL3,reg);
    }
    
    TLG_SetChnFreqASYNC(base_addr, center_freq_hz, true, 0, state, ms);

    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_SetTVChnFreq
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetTVChnFreq(uint32 base_addr, uint32 center_freq_hz)
{
    int res = TLG_ERR_NOT_SUPPORTED;
#ifdef TLG_EMBEDDED_TIMERS
    tlg_statep state;
    int        ms;

    state[0] = TLG_STATE0;
    do {
        res = TLG_SetTVChnFreqASYNC(base_addr, center_freq_hz, state, &ms);
        if (res != TLG_ERR_SUCCESS) break;
        if (ms) 

            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);
#endif /* TLG_EMBEDDED_TIMERS */

    return res;
}

/** set TV Frequency end */



/** set FM Frequency begin */

#define CHANNEL_FREQ_OFFSET_HZ ((uint32)2750000)    /* 2.75 MHZ */


/*****************************************************************************
* TLG_SetFMChnFreqASYNC
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetFMChnFreqASYNC(uint32 base_addr, uint32 center_freq_hz,
                     int32 slope, int32 offset, tlg_statep state, int *ms)
{
    uint16 reg;
    int    lf2=0;

    TLG_ReadReg(base_addr,TLG1100_LUMA_PLL3, &reg);
    TLGHAL_GET(lf2,reg,TLG1100_LUMA_PLL3_BYPLF2_SHIFT,TLG1100_LUMA_PLL3_BYPLF2_MASK);
    if (lf2) {
        TLGHAL_SET(reg,0,TLG1100_LUMA_PLL3_BYPLF2_SHIFT,TLG1100_LUMA_PLL3_BYPLF2_MASK);
        TLG_WriteReg(base_addr,TLG1100_LUMA_PLL3,reg);
    }
    
    switch (state[0])
    {
    case TLG_STATE0:
    /* state[0] - state variable for this function
     * state[1] - interpolated track code
     * state[2] - state variable for TLG_SetChnFreqASYNC() 
     */
    state[1] = 0;            /* track_code */
    state[2] = TLG_STATE0;   /* TLG_SetChnFreqASYNC() state machine */

    case TLG_STATE1:
    /* state[0] - state variable for this function
     * state[1] - interpolated track code
     * state[2] - state variable for TLG_SetChnFreqASYNC() 
     */
    /* if slope and offset provided then use them to calc track code
       else do TLG_SetChnFreqASYNC() on Luma chan to get initial track code */
    if (slope && offset)
    {
        state[1] = (uint16)(HZCVT(center_freq_hz)*slope + offset  + 500000)/(1000000);
    } else {
        TLG_SetChnFreqASYNC(base_addr, center_freq_hz, true, 0, &state[2], ms);
        if (state[2] != TLG_STATE_FINAL)
        {
            state[0] = TLG_STATE1;
            break;
        }
    } 
    state[2] = TLG_STATE0;   /* Reset TLG_SetChnFreqASYNC() state machine */
    
    case TLG_STATE2:
    /* state[0] - state variable for this function
     * state[1] - interpolated track code
     * state[2] - state variable for TLG_SetChnFreqASYNC() 
     */
    /* do chn change on audio carrier using supplied track code */
    TLG_SetChnFreqASYNC(base_addr, center_freq_hz - CHANNEL_FREQ_OFFSET_HZ, false, state[1], &state[2], ms);
    if (state[2] != TLG_STATE_FINAL)
    {
        state[0] = TLG_STATE2;
    } else {
        state[0] = TLG_STATE_FINAL;
    }
    break;

    default: TLG_REG_LOG((b,"TLG_SetFMChnFreqASYNC: %d BADSTATE!\n", state[0]));
    break;
    }
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetFMChnFreq
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_SetFMChnFreq(uint32 base_addr, uint32 center_freq_hz,
                     int32 slope, int32 offset)
{
    int res = TLG_ERR_NOT_SUPPORTED;

#ifdef TLG_EMBEDDED_TIMERS
    tlg_statep state;
    int        ms;

    state[0] = TLG_STATE0;
    do {
        res = TLG_SetFMChnFreqASYNC(base_addr, center_freq_hz, slope, offset,
                                    state, &ms);
        if (res != TLG_ERR_SUCCESS) break;
        if (ms) 
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);
#endif /* TLG_EMBEDDED_TIMERS */

    return(res);
}


/** set FM Frequency end */

#define CHANNEL_EXIST      1
#define CHANNEL_NOT_EXIST  0

/** This value can be customized to allow additional wait time for
    chroma/luma lock if needed.                                        **/
#define FAST_TVSCAN_WAITFOR_LOCK_TIMEOUT1    0  /* in interval of 30 ms */


/*****************************************************************************
* TLG_FastScanTVChnASYNC
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_FastScanTVChnASYNC(uint32 base_addr, 
                                          uint32 center_freq_hz, 
                                          tlg_statep state, int *ms)
{
    uint16 regData;
    int    pwr;
    int    res = CHANNEL_NOT_EXIST;

    TLG_NULLPTR_CHECK(state);
    TLG_NULLPTR_CHECK(ms);

    switch (state[0])
    {
    case TLG_STATE0:
    /* state[0] - state variable for this function
     * state[1] - state variable for TLG_SetTVChnFreqASYNC()
     */
    state[1] = TLG_STATE0; /* state vector for TLG_SetTVChnFreqASYNC() */

    case TLG_STATE1:
    /* state[0] - state variable for this function
     * state[1] - state variable for TLG_SetTVChnFreqASYNC()
     */
    TLG_SetTVChnFreqASYNC(base_addr, center_freq_hz, &state[1], ms);
    if (state[1] != TLG_STATE_FINAL)
    {
        state[0] = TLG_STATE1;
        break;
    }

    /* if not enough luma energy, then reject */
    pwr = TLG_ReadLumaNotchPwr(base_addr, 5);
    if (pwr < 150)
    {
        state[0] = TLG_STATE_FINAL;
        *ms      = 0;
        break;
    }
    state[1] = 0; /* loop variable for state 2 */

    /* transition to state 2... */

    case TLG_STATE2:
    /* state[0] - state variable for this function
     * state[1] - loop variable to limit times through lock detector 
     */
    /* loop to detect channel based on chroma/luma/vsync lock */
    TLG_ReadRegNS(base_addr, TLG1100_LOCK_DETECTOR,&regData);
    if (regData & (TLG1100_VSYNC_LOCK|TLG1100_LUMA_LOCK|TLG1100_CHROMA_LOCK))
    {
        state[0] = TLG_STATE_FINAL;
        *ms      = 0;
        res      = CHANNEL_EXIST;
    } else {
        if ((int)state[1] < FAST_TVSCAN_WAITFOR_LOCK_TIMEOUT1)
        {
            state[1]++;
            state[0] = TLG_STATE2;
            *ms      = 30;
        } else {
            state[0] = TLG_STATE_FINAL;
            *ms      = 0;
        }
    }   
    break;

    default: TLG_REG_LOG((b,"TLG_ScanTVChnASYNC: %d BADSTATE!\n", state[0]));
    break;
    }

    return res;
}


/*****************************************************************************
* TLG_FastScanTVChn
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_FastScanTVChn(uint32 base_addr, uint32 center_freq_hz)
{
    int        res = CHANNEL_NOT_EXIST;

#ifdef TLG_EMBEDDED_TIMERS
    tlg_statep state;
    int        ms=0;

#ifdef TLG_VSCREEN_LOCK
	TLG_UnlockVScreen(base_addr);
#endif

    state[0] = TLG_STATE0;
    do {
        res = TLG_FastScanTVChnASYNC(base_addr, center_freq_hz, state, &ms);
        if (res != TLG_ERR_SUCCESS) break;
        if (ms)
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);

#ifdef TLG_NO_SSI_READOUT
	TLG_LockVScreen(base_addr);
#endif

#endif /* TLG_EMBEDDED_TIMERS */

    return res;
}


#define TVSCAN_WAITFOR_LOCK_TIMEOUT1    3  /* in 100s ms */
#define TVSCAN_WAITFOR_LOCK_TIMEOUT2    6  /* in 100s ms */

/*****************************************************************************
* TLG_ScanTVChnASYNC
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_ScanTVChnASYNC(uint32 base_addr, uint32 center_freq_hz, 
                       tlg_statep state, int *ms)
{
    uint16 regData;
    
    TLG_NULLPTR_CHECK(state);
    TLG_NULLPTR_CHECK(ms);
	
    switch (state[0])
    {
    case TLG_STATE0:
    state[1] = TLG_STATE0; /* state vector for TLG_SetTVChnFreqASYNC() */

    case TLG_STATE1:
    TLG_SetTVChnFreqASYNC(base_addr, center_freq_hz, &state[1], ms);
    if (state[1] != TLG_STATE_FINAL)
    {
        state[0] = TLG_STATE1;
        break;
    }
    state[1] = 0 ;

    case TLG_STATE2:
    /* first status detection loop */
    TLG_ReadRegNS(base_addr, TLG1100_LOCK_DETECTOR,&regData);
    if(!(regData & (TLG1100_VSYNC_LOCK|TLG1100_LUMA_LOCK|TLG1100_CHROMA_LOCK)))
    {              
        if (state[1]++ >= TVSCAN_WAITFOR_LOCK_TIMEOUT1)
        {
            state[0] = TLG_STATE_FINAL;
            *ms      = 0;
        } else {
            state[0] = TLG_STATE2; /* loop with 100ms delay */
            *ms      = 100;
        }
        return CHANNEL_NOT_EXIST;
    }
    TLG_REG_LOG((b,"First Lock Loop=%d ms\n", (state[1]-1)*100));
    state[1] = 0;  /* timeout loop counter */

    case TLG_STATE3:
    /* second detection loop */
    TLG_ReadRegNS(base_addr, TLG1100_LOCK_DETECTOR,&regData);
    if(regData & TLG1100_VSYNC_LOCK)
    {
        state[0] = TLG_STATE_FINAL;
        *ms      = 0;
        TLG_REG_LOG((b,"Second Lock Loop=%d ms\n", (state[1]-1)*100));

        return CHANNEL_EXIST;   
    } else {
        if (state[1]++ >= TVSCAN_WAITFOR_LOCK_TIMEOUT2)
        {
            state[0] = TLG_STATE_FINAL;
            *ms      = 0;
        } else {
            state[0] = TLG_STATE3; /* loop with 50ms delay */
            *ms      = 100;
        }
    }
    break;

    default: TLG_REG_LOG((b,"TLG_ScanTVChnASYNC: %d BADSTATE!\n", state[0]));
    break;
    }
    return CHANNEL_NOT_EXIST;
}

/*****************************************************************************
* TLG_ScanTVChn
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_ScanTVChn(uint32 base_addr, uint32 center_freq_hz)
{
    int        res = CHANNEL_NOT_EXIST;

#ifdef TLG_EMBEDDED_TIMERS
    tlg_statep state;
    int        ms=0;

#ifdef TLG_VSCREEN_LOCK
	TLG_UnlockVScreen(base_addr);
#endif

    state[0] = TLG_STATE0;
    do {
        res = TLG_ScanTVChnASYNC(base_addr, center_freq_hz, state, &ms);
        if (res != TLG_ERR_SUCCESS) break;
        if (ms)
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);

#ifdef TLG_NO_SSI_READOUT
	TLG_LockVScreen(base_addr);
#endif

#endif /* TLG_EMBEDDED_TIMERS */

    return res;
}

/*****************************************************************************
* TLG_InitScanFMChnASYNC
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_InitScanFMChnASYNC(uint32 base_addr, uint32 min_hz, uint32 max_hz,
                      int32 *slope, int32 *offset, tlg_statep state, int *ms)
{
    uint32 maxhz_cvt, minhz_cvt, last_cvt, first_cvt;
    uint16 last_code, first_code;

    TLG_NULLPTR_CHECK(slope);
    TLG_NULLPTR_CHECK(offset);
    TLG_BOUNDS_CHECK(min_hz, max_hz); 

    switch (state[0])
    {
    case TLG_STATE0:
    state[4] = TLG_STATE0;    /* state vector for TLG_SetFMChnFreqASYNC() */

    case TLG_STATE1:
    /* get endpoints of curve */
    TLG_SetFMChnFreqASYNC(base_addr, max_hz, 0, 0, &state[4], ms);
    if (state[4] != TLG_STATE_FINAL)
    {
        state[0] = TLG_STATE1;
        break;
    }
    TLG_ReadRegNS(base_addr, 0x11c, &last_code);  
    state[1] = last_code;     /* cache last_code for later                */
    state[4] = TLG_STATE0;    /* state vector for TLG_SetFMChnFreqASYNC() */

    case TLG_STATE2:
    TLG_SetFMChnFreqASYNC(base_addr, min_hz, 0, 0, &state[4], ms);
    if (state[4] != TLG_STATE_FINAL)
    {
        state[0] = TLG_STATE2;
        break;
    } else {
        state[0] = TLG_STATE_FINAL;
    }
    TLG_ReadRegNS(base_addr, 0x11c, &first_code); 
    last_code = state[1];

    maxhz_cvt = HZCVT(max_hz);
    minhz_cvt = HZCVT(min_hz);
    last_cvt  = MHZCVT(last_code);
    first_cvt = MHZCVT(first_code);
    /* slope*100 */
    *slope    = (100*(last_cvt - first_cvt))/(maxhz_cvt - minhz_cvt);
    /* offset*100*10000 */
    *offset   = (100*(first_cvt) - (*slope) * minhz_cvt);
    TLG_REG_LOG((b,"min=%d, max=%d, first=%d, last=%d, slope=%d, offset=%d\n",
                   minhz_cvt, maxhz_cvt, first_cvt, last_cvt, *slope, *offset));
    break;

    default: TLG_REG_LOG((b,"TLG_InitScanFMChnASYNC: %d BADSTATE!\n", state[0]));
    break;
    }

   return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_InitScanFMChn
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_InitScanFMChn(uint32 base_addr, uint32 min_hz, uint32 max_hz,
                      int32 *slope, int32 *offset)
{
    int res = TLG_ERR_NOT_SUPPORTED;

#ifdef TLG_EMBEDDED_TIMERS
    tlg_statep state;
    int        ms=0;
    
    state[0] = TLG_STATE0;
    do {
        res = TLG_InitScanFMChnASYNC(base_addr, min_hz, max_hz, slope, offset, state, &ms);
        if (res != TLG_ERR_SUCCESS) break;
        if (ms != 0)
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);
#endif /* TLG_EMBEDDED_TIMERS */

    return res;
}


/*****************************************************************************
* TLG_ScanFMChnASYNC
*
* 
*
*
*****************************************************************************/

#define MAX_NUM 10
#define FOUND_AUDIO_THRESHOLD 1

TLG1100DLL_API int TLG_ScanFMChnASYNC(uint32 base_addr, uint32 center_freq_hz, 
                       int32 slope, int32 offset, tlg_statep state, int *ms)
{
    /* loop on this call until final state */
    TLG_SetFMChnFreqASYNC(base_addr, center_freq_hz, slope, offset, state, ms);
    if (state[0] != TLG_STATE_FINAL)
        return CHANNEL_NOT_EXIST;

    tlg_cur_fm_ssi = TLG_ReadAudioNotchPwr(base_addr, MAX_NUM);
    TLG_REG_LOG((b,"FM STRENGTH for %d = %d\n", center_freq_hz, tlg_cur_fm_ssi));
    if (tlg_cur_fm_ssi > 65)
        return CHANNEL_EXIST;
    else
        tlg_cur_fm_ssi = 0;
    
    return CHANNEL_NOT_EXIST;
}


/*****************************************************************************
* TLG_ScanFMChn
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_ScanFMChn(uint32 base_addr, uint32 center_freq_hz, 
                       int32 slope, int32 offset)
{
    int res = TLG_ERR_NOT_SUPPORTED;

#ifdef TLG_EMBEDDED_TIMERS
    tlg_statep state;
    int        ms=0;

    state[0] = TLG_STATE0;
    do {
        res = TLG_ScanFMChnASYNC(base_addr, center_freq_hz, slope, offset, state, &ms);
        if (res != TLG_ERR_SUCCESS) break;
        if (ms != 0) 
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);
#endif /* TLG_EMBEDDED_TIMERS */

    return res;
}

/*****************************************************************************
* TLG_GetChnStatus
*
* 
*
*
*****************************************************************************/

TLG1100DLL_API int TLG_GetChnStatus(uint32 base_addr, bool *isLock)
{
  
  uint16 regData;

  TLG_NULLPTR_CHECK(isLock);
    
  TLG_ReadRegNS(base_addr, TLG1100_LOCK_DETECTOR,&regData);

  *isLock = (regData >> TLG1100_VSYNC_LOCK_SHIFT ) & 1;

   return(TLG_ERR_SUCCESS);

}

/*****************************************************************************
* TLG_GetChnRestartStatus
*
* 
*
*
*****************************************************************************/

#ifdef TLG_RESTART_THRESH_DEV
TLG1100DLL_API int TLG_RESTART_THRESH = TLG_RESTART_THRESH_DEF_VAL;
#endif /* TLG_RESTART_THRESH_DEV */

TLG1100DLL_API int TLG_GetChnRestartStatus(uint32 base_addr, bool *lockStat)
{
    uint16  reg;
    uint16  lumaStat;
    uint16  c3;
    int     thresh;
      
    TLG_NULLPTR_CHECK(lockStat);

    /* check for luma lock */
    TLG_ReadRegNS(base_addr, TLG1100_LOCK_DETECTOR, &reg);
    *lockStat = !(reg & TLG1100_LUMA_LOCK);
    if (*lockStat)
    {
        /* lumaStat = |lumaStat| */
        TLG_ReadRegNS(base_addr, TLG1100_LUMA_PLL_STAT2, (uint16*) &lumaStat);
        if (lumaStat & 0x8000) lumaStat = ~(lumaStat-1) & 0xffff;

        /* check luma pll is in range THRESH*2^(25-c3)/13500 */
        TLG_ReadReg(base_addr, TLG1100_LUMA_PLL2, &c3);
        TLGHAL_GET(c3, c3, TLG1100_LUMA_PLL2_C3_SHIFT,
                           TLG1100_LUMA_PLL2_C3_MASK);
        thresh    = (TLG_RESTART_THRESH*(1<<(25-c3)))/13500;
        *lockStat = (lumaStat > thresh);
    }

    return(TLG_ERR_SUCCESS);

}

/*****************************************************************************
* TLG_GetLockStatus
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetLockStatus(uint32 base_addr, uint16 lockTypes, uint16 *locks)
{
    uint16  bsCode;
    TLG_NULLPTR_CHECK(locks);
    *locks = 0;

    /* Get the Locking Status */
    /*     get vsync, vid, chroma, luma, hsysnc */
    if (lockTypes & (TLG_LOCK_STATE_VSYNC|TLG_LOCK_STATE_VIDEO|
                     TLG_LOCK_STATE_CHROMA | TLG_LOCK_STATE_LUMA))
    {
        TLG_ReadRegNS(base_addr,    TLG1100_LOCK_DETECTOR,         locks);
    }
    /*     get synth lock */
    if (lockTypes & TLG_LOCK_STATE_SYNTH)
    {
        TLG_ReadRegNS(base_addr,    TLG1100_VCO_BS_STAT,           &bsCode);
        TLGHAL_GET(bsCode, bsCode,  TLG1100_SYNTH_LOCK_SHIFT,
                                    TLG1100_SYNTH_LOCK_MASK);
        TLGHAL_SET(*locks, bsCode,  TLG1100_SYNTH_LOCK_SHIFT,              
                                    TLG1100_SYNTH_LOCK_MASK);
    }

    /*     get audio lock */
    if (lockTypes & TLG_LOCK_STATE_AUDIO)
    {
        TLGHAL_SET(*locks, (TLG_ReadAudioNotchPwr(base_addr, 10) > 65),
                                    TLG1100_SOUND_LOCK_SHIFT,
                                    TLG1100_SOUND_LOCK);
    }

    return TLG_ERR_SUCCESS;
}
