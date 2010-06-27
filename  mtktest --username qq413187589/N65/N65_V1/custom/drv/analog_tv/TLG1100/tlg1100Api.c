/*****************************************************************************
* FILENAME
* tlg1100Api.c
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

#include "tlg1100Api.h"
#include "tlg1100Hal.h"
#include "tlg1100i2c.h"

#ifdef TLG_USE_SHADOW_REGISTERS
uint16 _TLG_shadow_reg[TLG_MAX_REG_ADDR+1];
uint8  _TLG_shadow_reg_use[TLG_MAX_REG_ADDR+1]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0};
#endif /* TLG_SHADOW_REGISTER_SIZE */

#ifdef TLG_SUPPORT_RUNTIME_CHECK
int g_tlg_chip_ver = TLG_NO_VERS;
#endif /* TLG_SUPPORT_RUNTIME_CHECK */

/*****************************************************************************
* REGISTER LOGGING FACILITY
*
* To enable register logging.
* - TLG_DO_REG_LOGGING must be defined in tlg1100Api.h
* - TLG_WriteLog() must be written. This is a customizable function
*   that must be written for the target system in question.
* - Alternatively TLG_REG_LOG may be re-written as well
*
*****************************************************************************/



/*****************************************************************************
* TLG_GetVersion
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetVersion(uint32 base_addr, uint16 *major, uint16 *minor, uint16 *patch)
{
    TLG_NULLPTR_CHECK(major);
    TLG_NULLPTR_CHECK(minor);
    TLG_NULLPTR_CHECK(patch);

    *major = TLG_VERSION_MAJOR;
    *minor = TLG_VERSION_MINOR;
    *patch = TLG_VERSION_PATCH;

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetChipVersion
*
* 0xffff 1.1
* 0xrfff 1.2 rev r
* 0xr3ff 1.3 rev r
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetChipVersion(uint32 base_addr, uint32 *chip_vers)
{
    uint16 reg, rev, ver;

    TLG_NULLPTR_CHECK(chip_vers);

#ifdef TLG_SUPPORT_RUNTIME_CHECK
    if (g_tlg_chip_ver == TLG_NO_VERS)
    {
#endif /* TLG_SUPPORT_RUNTIME_CHECK */

        TLG_WriteReg(base_addr,     TLG1100_VERS_CHECK, 0xffff);
        TLG_ReadRegNS(base_addr,    TLG1100_VERS_CHECK, &reg);
        TLGHAL_GET(rev, reg,        TLG1100_VERS_CHECK_REV_SHIFT, 
                                    TLG1100_VERS_CHECK_REV_MASK);
        TLGHAL_GET(ver, reg,        TLG1100_VERS_CHECK_VER_SHIFT, 
                                    TLG1100_VERS_CHECK_VER_MASK);
        if (rev == TLG1100_VERS_CHECK_NOREV)
            *chip_vers = TLG1100_VERS_1_1;
        else if (ver == TLG1100_VERS_CHECK_NOREV)
            *chip_vers = TLG1100_VERS_1_2 | rev;
        else
            *chip_vers = TLG1100_VERS_1_3 | rev;
#ifdef TLG_SUPPORT_RUNTIME_CHECK
        g_tlg_chip_ver = *chip_vers;
        TLG_REG_LOG((b,"chip version = 0x%x, rev=%x\n", g_tlg_chip_ver, rev));
    } else
        *chip_vers = g_tlg_chip_ver;
#endif /* TLG_SUPPORT_RUNTIME_CHECK */

    return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_SoftReset
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SoftResetASYNC(uint32 base_addr, tlg_statep state, int *ms)
{
#if 1
    TLG_CHIP_VERS_1_3_BEGIN
        #ifdef TLG_CMP_CHIP_1_3
        TLG_WriteReg(base_addr, 0x0001,0x0001);
        TLG_WriteReg(base_addr, 0x0001,0x0000);
        state[0] = TLG_STATE_FINAL;
        *ms      = 0;
        #endif /* TLG_CMP_CHIP_1_3 */
    TLG_CHIP_VERS_1_2_ELSE
#else
    TLG_CHIP_VERS_1_2_BEGIN
#endif
        #ifdef TLG_CMP_CHIP_1_2
        uint16      filt_cal_override;
        uint16      old_search_limit;
        uint16      filt_r_val;
        uint16      trkfilt_cal_code;
        uint16     *adc_val = &state[1];
        uint16      reg;
        uint16      force_coef_load;
        int         i;

        switch (state[0])
       {
        case TLG_STATE0:
        /* state[0]     - state variable for this function
         * state[1..12] - adc_val[]
         * state[13]    - old_search_limit
         */
        TLG_ReadReg(base_addr, TLG1100_ATOP_FILT_CAL_2, &reg);
        TLGHAL_GET(filt_cal_override, reg, TLG1100_ATOP_FILT_CAL_2_FRC_FC_SHIFT,
                                           TLG1100_ATOP_FILT_CAL_2_FRC_FC_MASK);
        if (filt_cal_override == 0)
        {
            TLG_ReadReg(base_addr, TLG1100_ATOP_FILCAL_STATUS1, &reg);
            TLGHAL_GET(filt_r_val, reg, 
                        TLG1100_ATOP_FILCAL_STATUS1_RCAL_SHIFT_1_2,
                        TLG1100_ATOP_FILCAL_STATUS1_RCAL_MASK_1_2);
        } else {
            TLG_ReadReg(base_addr, TLG1100_ATOP_FILT_CAL_1,&reg);
            TLGHAL_GET(filt_r_val, reg,
                        TLG1100_ATOP_FILT_CAL_1_FRC_FC_VAL_SHIFT,
                        TLG1100_ATOP_FILT_CAL_1_FRC_FC_VAL_MASK);
        }
        TLG_ReadReg(base_addr, TLG1100_ATOP_TRKFIL_CAL_4, &old_search_limit);
        state[13] = old_search_limit;

        TLG_ReadRegNS(base_addr, TLG1100_ATOP_TRKFIL_CAL_STATUS6,
                        &trkfilt_cal_code);

    
        TLG_ReadReg(base_addr, TLG1100_ATOP_ADC_CAL_13, &adc_val[11]);
        TLGHAL_GET(force_coef_load, adc_val[11], 
                    TLG1100_ATOP_ADC_CAL_13_FRC_LD_SHIFT,
                    TLG1100_ATOP_ADC_CAL_13_FRC_LD_MASK);

        if (force_coef_load)
        {
            for(i = 0; i < 11; i++)
                TLG_ReadReg(base_addr, TLG1100_ATOP_ADC_CAL_2 + i, &adc_val[i]);
        } else {
            for(i = 0; i < 10; i++)
                TLG_ReadRegNS(base_addr, TLG1100_ATOP_ADCCAL_STATUS1 + i,
                              &adc_val[i]);
            TLGHAL_CLEAR(adc_val[0], TLG1100_ATOP_ADCCAL_COEF_10_MASK);
            TLG_ReadRegNS(base_addr, TLG1100_ATOP_ADCCAL_STATUS12,&adc_val[10]);
        }

        TLG_WriteReg(base_addr, 0x0001,1);

        /** re-calibrate */
        TLG_ReadReg(base_addr, TLG1100_ATOP_FILT_CAL_1, &reg);
        TLGHAL_SET(reg, filt_r_val, TLG1100_ATOP_FILT_CAL_1_FRC_FC_VAL_SHIFT,
                                    TLG1100_ATOP_FILT_CAL_1_FRC_FC_VAL_MASK);
        TLG_WriteReg(base_addr, TLG1100_ATOP_FILT_CAL_1, reg);

        TLG_ReadReg(base_addr,  TLG1100_ATOP_FILT_CAL_2, &reg);
        TLGHAL_SET(reg, TLG_ON, TLG1100_ATOP_FILT_CAL_2_FRC_FC_SHIFT,
                                TLG1100_ATOP_FILT_CAL_2_FRC_FC_MASK); 
        TLG_WriteReg(base_addr, TLG1100_ATOP_FILT_CAL_2, reg);

        TLG_WriteReg(base_addr, TLG1100_ATOP_TRKFIL_CAL_4, 0x0000);
        TLG_WriteReg(base_addr, TLG1100_ATOP_TRKFIL_CAL_3, trkfilt_cal_code);

        *ms      = 5;
        state[0] = TLG_STATE1;
        break;

        case TLG_STATE1:
        /* state[0]     - state variable for this function
         * state[1..12] - adc_val[]
         * state[13]    - old_search_limit
         */
        old_search_limit = state[13];
        TLG_WriteReg(base_addr, TLG1100_ATOP_TRKFIL_CAL_4, old_search_limit);
   
        for( i= 0; i <11; i++)
            TLG_WriteReg(base_addr, TLG1100_ATOP_ADC_CAL_2 + i, adc_val[i]);
        TLG_WriteReg(base_addr, TLG1100_ATOP_ADC_CAL_13, 
                                TLG1100_ATOP_ADC_CAL_13_FRC_LD_MASK);
        state[0] = TLG_STATE_FINAL;
        *ms      = 0;
        break;

        default:
        break;
        }
        #endif /* TLG_CMP_CHIP_1_2 */
    TLG_CHIP_VERS_1_1_ELSE
        #ifdef TLG_CMP_CHIP_1_1
        TLG_WriteReg(base_addr, 0x0001,0x0001);
        state[0] = TLG_STATE_FINAL;
        *ms      = 0;
        #endif /* TLG_CMP_CHIP_1_1 */
    TLG_CHIP_VERS_END

    return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_SoftReset
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SoftReset(uint32 base_addr)
{
    tlg_statep  state;
    int         ms    = 0;

#ifndef TLG_EMBEDDED_TIMERS
    return(TLG_ERR_NOT_SUPPORTED);
#else
    state[0] = TLG_STATE0;
    do {
        TLG_SoftResetASYNC(base_addr, state, &ms);
        if (ms)
            TLG_Delay((uint16)ms);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug TLG_SoftReset() ......\r\n");	
#endif
    } while (state[0] != TLG_STATE_FINAL);
    return(TLG_ERR_SUCCESS);
#endif /* TLG_EMBEDDED_TIMERS */
}
/*****************************************************************************
* TLG_InitASYNC
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_InitASYNC(uint32 base_addr, tlg_statep state, int *ms)
{
	uint16 data;
	uint16 data1;

    TLG_NULLPTR_CHECK(state);
    TLG_NULLPTR_CHECK(ms);

    switch (state[0])
    {
    case TLG_STATE0:
#ifdef TLG_SUPPORT_RUNTIME_CHECK
    {uint32 version;
    TLG_GetChipVersion(base_addr, &version);}
#endif /* TLG_SUPPORT_RUNTIME_CHECK */
    TLG_CHIP_VERS_1_2_BEGIN
        #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_1_2)
        TLG_WriteReg(base_addr, 0x0,0x4012);
        TLG_ReadReg(base_addr,  TLG1100_DEMOD_HPF, &data);
        TLGHAL_SET(data,TLG_ON, TLG1100_DEMOD_HPF_NTCH_DBL_SHIFT,
                                TLG1100_DEMOD_HPF_NTCH_DBL_MASK);
        TLG_WriteReg(base_addr, TLG1100_DEMOD_HPF,data);
        #endif /* TLG_CMP_CHIP_1_2 */
    TLG_CHIP_VERS_1_1_ELSE
        #ifdef TLG_CMP_CHIP_1_1
        TLG_WriteReg(base_addr, 0x0,0x10);
        #endif /* TLG_CMP_CHIP_1_1 */
    TLG_CHIP_VERS_END
    TLG_WriteReg(base_addr, TLG1100_MXS_POWER,0xfffe);
    TLG_CHIP_VERS_1_2_BEGIN
        #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_1_2)
        TLG_WriteReg(base_addr, 0x181,0x0e1f);
        #endif /* TLG_CMP_CHIP_1_2 */
    TLG_CHIP_VERS_1_1_ELSE
        #ifdef TLG_CMP_CHIP_1_1
        TLG_WriteReg(base_addr, 0x181,0x0e3f);
        #endif /* TLG_CMP_CHIP_1_1 */
    TLG_CHIP_VERS_END
    state[0] = TLG_STATE1;
    *ms    = 5;
    break;

    case TLG_STATE1:
    TLG_WriteReg(base_addr, TLG1100_MXS_POWER,0xe81e);
    state[0] = TLG_STATE2;
    *ms    = 5;
    break;

    case TLG_STATE2:
    TLG_ReadReg(base_addr, TLG1100_ADC_BIAS, &data1);
    TLGHAL_SET(data1, TLG_ON, TLG1100_ADC_NULL_SHIFT, TLG1100_ADC_NULL_MASK);
    TLG_WriteReg(base_addr, TLG1100_ADC_BIAS, data1);
    TLG_WriteReg(base_addr, 0x197,0x04);
    TLG_WriteReg(base_addr, 0x03,0x2493);
    state[0] = TLG_STATE3;
    *ms    = 5;
    break;

    case TLG_STATE3:
    TLG_WriteReg(base_addr, TLG1100_MXS_POWER,0xe85e);
    TLG_WriteReg(base_addr, 0x197,0x0);
    TLG_WriteReg(base_addr, 0x1a7,0x0144);
    TLG_ReadReg(base_addr, TLG1100_ADC_BIAS, &data1);
    TLGHAL_CLEAR(data1, TLG1100_ADC_NULL_MASK);
    TLG_WriteReg(base_addr, TLG1100_ADC_BIAS, data1);
    /* end of powerup calibration */
    TLG_WriteReg(base_addr, 0x18d,0x0081);
    TLG_WriteReg(base_addr, 0x036,0x30af);
    TLG_WriteReg(base_addr, 0x037,0xeed0); 
    TLG_WriteReg(base_addr, 0x039,0x3f0);

    TLG_ReadReg(base_addr,      TLG1100_ATOP_SARADC, &data);
    TLGHAL_SET(data,            TLG1100_SARADC_FREEZE_SEL_VAL, 
                                TLG1100_SARADC_FREEZE_SEL_SHIFT, 
                                TLG1100_SARADC_FREEZE_SEL_MASK);
    TLG_WriteReg(base_addr,     TLG1100_ATOP_SARADC, data);

    TLG_ReadReg(base_addr,      TLG1100_SOUND_DEMOD2, &data);
    TLGHAL_SET(data, 0x84,      TLG1100_SOUND_DEMOD2_LOCK_SHIFT,
                                TLG1100_SOUND_DEMOD2_LOCK_MASK);
    TLGHAL_CLEAR(data,          TLG1100_SOUND_DEMOD2_HPF_HOLD_MASK);
    TLGHAL_CLEAR(data,          TLG1100_SOUND_DEMOD2_HPF_GAIN_MASK);
    TLG_WriteReg(base_addr,     TLG1100_SOUND_DEMOD2, data);

    TLG_ReadReg(base_addr,      TLG1100_SOUND_DEMOD3, &data);
    TLGHAL_SET(data, 1,         TLG1100_SOUND_DEEMP2_EN_SHIFT,
                                TLG1100_SOUND_DEEMP2_EN_MASK); 
    TLGHAL_SET(data, 4,         TLG1100_SOUND_DEEMP2_SEL_SHIFT,
                                TLG1100_SOUND_DEEMP2_SEL_MASK); 
    TLGHAL_SET(data, 10,        TLG1100_SOUND_DEEMP_SEL_SHIFT,
                                TLG1100_SOUND_DEEMP_SEL_MASK); 
    TLG_WriteReg(base_addr,     TLG1100_SOUND_DEMOD3, data);

    state[0] = TLG_STATE4;
    *ms    = 5;
    break;

    case TLG_STATE4:
    state[0] = TLG_STATE_FINAL;
    *ms    = 0;
    break;

    default:
    break;
    }
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_Init
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_Init(uint32 base_addr)
{
    tlg_statep  state;
    int         ms    = 0;

#ifndef TLG_EMBEDDED_TIMERS
    return(TLG_ERR_NOT_SUPPORTED);
#else
    state[0] = TLG_STATE0;
    do {
        TLG_InitASYNC(base_addr, state, &ms);
        if (ms)
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);
    return(TLG_ERR_SUCCESS);
#endif /* TLG_EMBEDDED_TIMERS */
}


    

/*****************************************************************************
* TLG_ReInitFromDeepSleep
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_ReInitFromDeepSleep(uint32 base_addr)
{
    tlg_statep  state;
    int         ms    = 0;

#ifndef TLG_EMBEDDED_TIMERS
    return(TLG_ERR_NOT_SUPPORTED);
#else
    state[0] = TLG_STATE1;
    do {
        TLG_InitASYNC(base_addr, state, &ms);
        if (ms)
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);
    return(TLG_ERR_SUCCESS);
#endif /* TLG_EMBEDDED_TIMERS */
}
/*****************************************************************************
* TLG_GetYUVScale
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetYUVScale(uint32 base_addr, uint16 *y, uint16 *u, uint16 *v)
{
    uint16 chromaScale;
    uint16 lumaScale;

    TLG_NULLPTR_CHECK(y);
    TLG_NULLPTR_CHECK(u);
    TLG_NULLPTR_CHECK(v);

    TLG_ReadReg(base_addr, TLG1100_CHRMA_SCALE, &chromaScale);
    TLG_ReadReg(base_addr, TLG1100_LUMA_SCALE, &lumaScale);
    TLGHAL_GET(*v, chromaScale, TLG1100_CHRMA_SCALE_V_SHIFT,
                TLG1100_CHRMA_SCALE_V_MASK);
    TLGHAL_GET(*u, chromaScale, TLG1100_CHRMA_SCALE_U_SHIFT,
                TLG1100_CHRMA_SCALE_U_MASK);
    TLGHAL_GET(*y, lumaScale, TLG1100_LUMA_SCALE_Y_SHIFT,
                TLG1100_LUMA_SCALE_Y_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetYUVScale
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetYUVScale(uint32 base_addr, uint16 y,uint16 u, uint16 v)
{
    uint16 chromaScale;
    uint16 lumaScale;

    TLG_BOUNDS_CHECK(y, TLG_Y_MAX);
    TLG_BOUNDS_CHECK(u, TLG_U_MAX);
    TLG_BOUNDS_CHECK(v, TLG_V_MAX);

    TLG_ReadReg(base_addr, TLG1100_CHRMA_SCALE, &chromaScale);
    TLG_ReadReg(base_addr, TLG1100_LUMA_SCALE, &lumaScale);
    TLGHAL_SET(chromaScale, v, TLG1100_CHRMA_SCALE_V_SHIFT,
                TLG1100_CHRMA_SCALE_V_MASK);
    TLGHAL_SET(chromaScale, u, TLG1100_CHRMA_SCALE_U_SHIFT,
                TLG1100_CHRMA_SCALE_U_MASK);
    TLGHAL_SET(lumaScale, y, TLG1100_LUMA_SCALE_Y_SHIFT,
                TLG1100_LUMA_SCALE_Y_MASK);
    TLG_WriteReg(base_addr, TLG1100_CHRMA_SCALE, chromaScale);
    TLG_WriteReg(base_addr, TLG1100_LUMA_SCALE, lumaScale);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetBWVideoMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetBWVideoMode(uint32 base_addr, uint16 *val)
{
    uint16 videoConfig3;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &videoConfig3);
    TLGHAL_GET(*val, videoConfig3, TLG1100_VID_CONFIG3_BWMODE_SHIFT,
            TLG1100_VID_CONFIG3_BWMODE_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetBWVideoMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetBWVideoMode(uint32 base_addr, uint16 val)
{
    uint16 videoConfig3;

    TLG_BOUNDS_CHECK(val, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &videoConfig3);
    TLGHAL_SET(videoConfig3, val, TLG1100_VID_CONFIG3_BWMODE_SHIFT,
            TLG1100_VID_CONFIG3_BWMODE_MASK);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG3, videoConfig3);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetVideoTestPatternState
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetVideoTestPatternState(uint32 base_addr, uint16 *val)
{
    uint16 videoConfig3;
    uint16 videoConfig5;
    uint16 freezeFrame;
    uint16 useRom;

    TLG_NULLPTR_CHECK(val);
    
    /* determine test pattern state on basis of ff/favg and Rom */
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG5,  &videoConfig5);
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3,  &videoConfig3);
    TLGHAL_GET(freezeFrame, videoConfig5, TLG1100_VID_CONFIG5_FF_EN_SHIFT,
               TLG1100_VID_CONFIG5_FF_EN_MASK);

    TLGHAL_GET(useRom, videoConfig3, TLG1100_VID_CONFIG3_FF_ROM_SHIFT,
               TLG1100_VID_CONFIG3_FF_ROM_MASK);

    *val = (freezeFrame == TLG_ON) && (useRom == TLG_ON);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetVideoTestPatternState
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVideoTestPatternState(uint32 base_addr, uint16 val)
{
    uint16  videoConfig2,
            videoConfig3,
            videoConfig5,
            videoConfig6,
            videoConfig9,
            videoConfig10;

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3,  &videoConfig3);
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG5,  &videoConfig5);
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG9,  &videoConfig9);
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG10, &videoConfig10);

    if (val == TLG_ON)
    {
        /* turn on Test Pattern: */
        TLG_ReadReg(base_addr, TLG1100_VID_CONFIG2,  &videoConfig2);
        TLG_ReadReg(base_addr, TLG1100_VID_CONFIG6,  &videoConfig6);

        /* turn off auto compensation, on ff */
        TLGHAL_CLEAR(videoConfig10, TLG1100_VID_CONFIG10_FAVG_EN_MASK);
        TLGHAL_SET(videoConfig5, TLG_ON, TLG1100_VID_CONFIG5_FF_EN_SHIFT,
                    TLG1100_VID_CONFIG5_FF_EN_MASK);

        /* Turn on ff always reading (could be in ini) */
        TLGHAL_SET(videoConfig5, TLG1100_VID_CONFIG5_FF_BUF_CTL_FREEZE,
                    TLG1100_VID_CONFIG5_FF_BUF_CTL_SHIFT,
                    TLG1100_VID_CONFIG5_FF_BUF_CTL_MASK);

        /* turn off ff aging (could be in ini) */
        TLGHAL_CLEAR(videoConfig6, TLG1100_VID_CONFIG6_FF_AGE_BUF_MASK);
 
        /* Enforce min off time (could be in ini) */
        TLGHAL_SET(videoConfig2, TLG_ON, TLG1100_VID_CONFIG2_FF_MIN_OFF_SHIFT,
                    TLG1100_VID_CONFIG2_FF_MIN_OFF_MASK);
       
        /*  turn on enforce ff min width fill (could be in ini) */
        TLGHAL_SET(videoConfig3, TLG_ON, TLG1100_VID_CONFIG3_FF_FILLWD_SHIFT,
                    TLG1100_VID_CONFIG3_FF_FILLWD_MASK);

        /* turn off use external counters */
        TLGHAL_CLEAR(videoConfig9, TLG1100_VID_CONFIG9_FF_EXT_CNTR_MASK);

        /* turn on use ROM */
        TLGHAL_SET(videoConfig3, TLG_ON, TLG1100_VID_CONFIG3_FF_ROM_SHIFT,
                    TLG1100_VID_CONFIG3_FF_ROM_MASK);

        TLG_WriteReg(base_addr, TLG1100_VID_CONFIG2, videoConfig2);
        TLG_WriteReg(base_addr, TLG1100_VID_CONFIG3, videoConfig3);
        TLG_WriteReg(base_addr, TLG1100_VID_CONFIG6, videoConfig6);
    } else {
        /* turn off Test Pattern:
         * turn off use ROM
         */
        TLGHAL_CLEAR(videoConfig3, TLG1100_VID_CONFIG3_FF_ROM_MASK);

         /* turn on auto compensation, off ff */
       TLGHAL_CLEAR(videoConfig5, TLG1100_VID_CONFIG5_FF_EN_MASK);
       TLGHAL_SET(videoConfig10, TLG_ON, TLG1100_VID_CONFIG10_FAVG_EN_SHIFT,
                    TLG1100_VID_CONFIG10_FAVG_EN_MASK);

        /* turn on use external counters */
        TLGHAL_SET(videoConfig9, TLG_ON, TLG1100_VID_CONFIG9_FF_EXT_CNTR_SHIFT,
                    TLG1100_VID_CONFIG9_FF_EXT_CNTR_MASK);

    }
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG3,  videoConfig3);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG5,  videoConfig5);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG9,  videoConfig9);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG10, videoConfig10);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_Get601VideoOutClock
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_Get601VideoOutClock(uint32 base_addr, uint16 *val)
{
    uint16 videoConfig3;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &videoConfig3);
    TLGHAL_GET(*val, videoConfig3, TLG1100_VID_CONFIG3_INV601_SHIFT,
            TLG1100_VID_CONFIG3_INV601_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_Set601VideoOutClock
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_Set601VideoOutClock(uint32 base_addr, uint16 val)
{
    uint16 videoConfig3;

    TLG_BOUNDS_CHECK(val, TLG_INVERT);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &videoConfig3);
    TLGHAL_SET(videoConfig3, val, TLG1100_VID_CONFIG3_INV601_SHIFT,
            TLG1100_VID_CONFIG3_INV601_MASK);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG3, videoConfig3);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetChromaLumaOrder
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetChromaLumaOrder(uint32 base_addr, uint16 *val)
{
    uint16 videoConfig2;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG2, &videoConfig2);
    TLGHAL_GET(*val, videoConfig2, TLG1100_VID_CONFIG2_SWAPCH_SHIFT,
            TLG1100_VID_CONFIG2_SWAPCH_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetChromaLumaOrder
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetChromaLumaOrder(uint32 base_addr, uint16 val)
{
    uint16 videoConfig2;

    TLG_BOUNDS_CHECK(val, TLG_CHRLUM_SWAP);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG2, &videoConfig2);
    TLGHAL_SET(videoConfig2, val, TLG1100_VID_CONFIG2_SWAPCH_SHIFT,
            TLG1100_VID_CONFIG2_SWAPCH_MASK);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG2, videoConfig2);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetCbCrOrder
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetCbCrOrder(uint32 base_addr, uint16 *val)
{
    uint16 videoConfig3;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &videoConfig3);
    TLGHAL_GET(*val, videoConfig3, TLG1100_VID_CONFIG3_FLIBCB_SHIFT,
            TLG1100_VID_CONFIG3_SWAPCB_MASK);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetCbCrOrder
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetCbCrOrder(uint32 base_addr, uint16 val)
{
    uint16 videoConfig3;

    TLG_BOUNDS_CHECK(val, TLG_CBCR_SWAP);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &videoConfig3);
    TLGHAL_SET(videoConfig3, val, TLG1100_VID_CONFIG3_FLIBCB_SHIFT,
            TLG1100_VID_CONFIG3_SWAPCB_MASK);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG3, videoConfig3);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetVideoResolution
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetVideoResolution(uint32 base_addr, uint16 *h, uint16 *v)
{
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetVideoResolution
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVideoResolution(uint32 base_addr, uint16 h, uint16 v, uint16 vmode)
{
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetAudioChan
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioChan(uint32 base_addr, uint16 *val)
{
    uint16 soundDsmDac;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DSMDAC, &soundDsmDac);
    TLGHAL_GET(*val, soundDsmDac, TLG1100_SOUND_DSMDAC_2CHAN_SHIFT,
                TLG1100_SOUND_DSMDAC_2CHAN_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioChan
*
* 
* DAC MODE ONLY
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioChan(uint32 base_addr, uint16 val)
{
    uint16 soundDsmDac;

    TLG_BOUNDS_CHECK(val, TLG_LEFT_RIGHT);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DSMDAC, &soundDsmDac);
    TLGHAL_SET(soundDsmDac, val, TLG1100_SOUND_DSMDAC_2CHAN_SHIFT,
                TLG1100_SOUND_DSMDAC_2CHAN_MASK);
    TLG_WriteReg(base_addr, TLG1100_SOUND_DSMDAC, soundDsmDac);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetAudioEnable
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioEnable(uint32 base_addr, uint16 *val)
{
    uint16 soundDemod1;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);

    TLGHAL_GET(*val, soundDemod1, TLG1100_SOUND_DEMOD1_SOUND_EN_SHIFT,
                TLG1100_SOUND_DEMOD1_SOUND_EN_MASK);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioEnable
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioEnable(uint32 base_addr, uint16 val)
{
    uint16 soundDemod1;

    TLG_BOUNDS_CHECK(val, TLG_ENABLE);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_CLEAR(soundDemod1, TLG1100_SOUND_DEMOD1_SOUND_EN_MASK);
    TLGHAL_SET(soundDemod1, val, TLG1100_SOUND_DEMOD1_SOUND_EN_SHIFT,
               TLG1100_SOUND_DEMOD1_SOUND_EN_MASK);
    TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD1, soundDemod1);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetAudioMode
*
* master   enable    mode
*   0        0       slave
*   0        1       DAC
*   1        0       master
*   1        1       undefined
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioMode(uint32 base_addr, uint16 *val)
{
    uint16 soundDemod1;
    uint16 soundDsmDac;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLG_ReadReg(base_addr, TLG1100_SOUND_DSMDAC, &soundDsmDac);

    /*** Decode according to logic table above */
    if (soundDemod1 & TLG1100_SOUND_DEMOD1_MASTER_MASK)
        if (soundDsmDac & TLG1100_SOUND_DSMDAC_ENABLE_MASK) /* never! */
            *val = TLG_UNDEFINED;
        else    
            *val = TLG_MASTER;
    else
        if (soundDsmDac & TLG1100_SOUND_DSMDAC_ENABLE_MASK)
            *val = TLG_DAC;
        else
            *val = TLG_SLAVE;
    if (*val == TLG_UNDEFINED) 
        return(TLG_ERR_FAIL);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioMode(uint32 base_addr, uint16 val)
{
    uint16 soundDemod1;
    uint16 soundDsmDac;

    TLG_BOUNDS_CHECK(val, TLG_DAC);
    
    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLG_ReadReg(base_addr, TLG1100_SOUND_DSMDAC, &soundDsmDac);
    switch (val)
    {
        case TLG_MASTER:
        TLGHAL_SET(soundDemod1, 1, TLG1100_SOUND_DEMOD1_MASTER_SHIFT,
                   TLG1100_SOUND_DEMOD1_MASTER_MASK);
        TLGHAL_CLEAR(soundDsmDac, TLG1100_SOUND_DSMDAC_ENABLE_MASK);
        break;

        case TLG_SLAVE:
        TLGHAL_CLEAR(soundDsmDac, TLG1100_SOUND_DSMDAC_ENABLE_MASK);
        TLGHAL_CLEAR(soundDemod1, TLG1100_SOUND_DEMOD1_MASTER_MASK);
        break;
      
        case TLG_DAC:
        TLGHAL_CLEAR(soundDemod1, TLG1100_SOUND_DEMOD1_MASTER_MASK);
        TLGHAL_SET(soundDsmDac, 1, TLG1100_SOUND_DSMDAC_ENABLE_SHIFT,
                    TLG1100_SOUND_DSMDAC_ENABLE_MASK);
        break;

        default:
#ifdef TLG_DO_ERROR_CHECKING
        return(TLG_ERR_PARAM);
#else
        break;
#endif /* TLG_DO_ERROR_CHECKING */
    }
    TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD1, soundDemod1);
    TLG_WriteReg(base_addr, TLG1100_SOUND_DSMDAC, soundDsmDac);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetAudioGain
*
* For TLG_MASTER/TLG_SLAVE:
*
* gain = 2*pll + aud :for gain=(0..9)
*
* Recommended settings:
* pll	aud	  gain
* 0	    0	  0
* 0	    1	  1
* 0	    2	  2
* 0	    3	  3
* 0	    4	  4
* 0	    5	  5
* 0	    6	  6
* 0	    7	  7
* 1	    6	  8
* 1	    7	  9
*
* Gain on chip is 2^gain (i.e. 1..2048)
*
* for TLG_DAC:
*
* gain = 2*pll + (3-aud): for gain=(0..5)
* Recommended settings:
* pll	aud	  gain
* 0	    3	  0
* 0	    2	  1
* 0	    1	  2
* 0	    0	  3
* 1	    1	  4
* 1	    0	  5
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioGain(uint32 base_addr, uint16 aud_mode, uint16 *gain) 
{
    uint16 soundDemod2;
    uint16 dsmDac;
    uint16 pll, aud;

    TLG_NULLPTR_CHECK(gain);
    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD2, &soundDemod2);
    TLGHAL_GET(pll, soundDemod2, TLG1100_SOUND_DEMOD2_PLL_GAIN_SHIFT, 
               TLG1100_SOUND_DEMOD2_PLL_GAIN_MASK);
    switch (aud_mode)
    {
    case TLG_MASTER:
    case TLG_SLAVE:
            TLGHAL_GET(aud, soundDemod2, TLG1100_SOUND_DEMOD2_AUD_GAIN_SHIFT, 
                        TLG1100_SOUND_DEMOD2_AUD_GAIN_MASK);
            break;
    case TLG_DAC:
            TLG_ReadReg(base_addr, TLG1100_SOUND_DSMDAC, &dsmDac);
            TLGHAL_GET(aud, dsmDac, TLG1100_SOUND_DSMDAC_SCALE_SHIFT, 
                        TLG1100_SOUND_DSMDAC_SCALE_MASK);
            aud = 3 - aud;
            break;
    default:
            return TLG_ERR_PARAM;
    }

    *gain = 2*pll + aud; /* formula according to tlg1100 specs. */
    
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioGain
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioGain(uint32 base_addr, uint16 aud_mode, uint16 gain)
{
    uint16 soundDemod2;
    uint16 dsmDac;
    uint16 pll, aud, max_gain=0;

    
    switch (aud_mode)
    {
    case TLG_MASTER:
    case TLG_SLAVE:
                max_gain = TLG_MAX_AUD_GAIN_DIG;
            break;
    case TLG_DAC:
                max_gain = TLG_MAX_AUD_GAIN_DAC;
            break;
    default:
            return TLG_ERR_PARAM;
    }
    TLG_BOUNDS_CHECK(gain, max_gain);

    /* calculate the proper internal gain settings according to table above  */
    if (gain > (max_gain-2))
    {
        pll = 1;
        aud = gain - 2;
    } else {
        pll = 0;
        aud = gain;
    }
    /* update register(s)                                                    */
    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD2, &soundDemod2);
    TLGHAL_SET(soundDemod2, pll, TLG1100_SOUND_DEMOD2_PLL_GAIN_SHIFT, 
               TLG1100_SOUND_DEMOD2_PLL_GAIN_MASK);
    switch (aud_mode)
    {
    case TLG_MASTER:
    case TLG_SLAVE:
            TLGHAL_SET(soundDemod2, aud, TLG1100_SOUND_DEMOD2_AUD_GAIN_SHIFT, 
                        TLG1100_SOUND_DEMOD2_AUD_GAIN_MASK);
            break;
    case TLG_DAC:
            TLG_ReadReg(base_addr, TLG1100_SOUND_DSMDAC, &dsmDac);
            TLGHAL_SET(dsmDac, (3-aud), TLG1100_SOUND_DSMDAC_SCALE_SHIFT, 
                        TLG1100_SOUND_DSMDAC_SCALE_MASK);
            TLG_WriteReg(base_addr, TLG1100_SOUND_DSMDAC, dsmDac);
            break;
    default:
            return TLG_ERR_PARAM;
    }
    TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD2, soundDemod2);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetAudioTestToneMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioTestToneMode(uint32 base_addr, uint16 *val)
{
    uint16 soundDemod1;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_GET(*val, soundDemod1, TLG1100_SOUND_DEMOD1_TTONE_EN_SHIFT,
               TLG1100_SOUND_DEMOD1_TTONE_EN_MASK);    

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioTestToneMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioTestToneMode(uint32 base_addr, uint16 val)
{
    uint16 soundDemod1;

    TLG_BOUNDS_CHECK(val, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_SET(soundDemod1, val, TLG1100_SOUND_DEMOD1_TTONE_EN_SHIFT,
               TLG1100_SOUND_DEMOD1_TTONE_EN_MASK);    
    TLGHAL_SET(soundDemod1, val, TLG1100_SOUND_DEMOD1_2CHN_EN_SHIFT,
                TLG1100_SOUND_DEMOD1_2CHN_EN_MASK);
    TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD1, soundDemod1);

    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_GetAudioTestToneL
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioTestToneL(uint32 base_addr, uint16 *val)
{
    uint16 soundDemod1;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_GET(*val, soundDemod1, TLG1100_SOUND_DEMOD1_LTONE_SHIFT, 
               TLG1100_SOUND_DEMOD1_LTONE_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioTestToneL
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioTestToneL(uint32 base_addr, uint16 val)
{ 
    uint16 soundDemod1;

    TLG_BOUNDS_CHECK(val, TLG_8KHZ);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_SET(soundDemod1, val, TLG1100_SOUND_DEMOD1_LTONE_SHIFT,
               TLG1100_SOUND_DEMOD1_LTONE_MASK);
    TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD1, soundDemod1);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetAudioTestToneR
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioTestToneR(uint32 base_addr, uint16 *val)
{
    uint16 soundDemod1;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_GET(*val, soundDemod1, TLG1100_SOUND_DEMOD1_RTONE_SHIFT, 
               TLG1100_SOUND_DEMOD1_RTONE_MASK);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetAudioTestToneR
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioTestToneR(uint32 base_addr, uint16 val)
{ 
    uint16 soundDemod1;

    TLG_BOUNDS_CHECK(val, TLG_8KHZ);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD1, &soundDemod1);
    TLGHAL_SET(soundDemod1, val, TLG1100_SOUND_DEMOD1_RTONE_SHIFT,
               TLG1100_SOUND_DEMOD1_RTONE_MASK);
    TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD1, soundDemod1);

    return(TLG_ERR_SUCCESS);
}




/*****************************************************************************
* TLG_GetExtHSync
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetExtHSync(uint32 base_addr, 
                    uint16 *assert_start,        uint16 *assert_end,
                    uint16 *deassert1_start,     uint16 *deassert1_end,
                    uint16 *deassert2_start,     uint16 *deassert2_end)
{

    TLG_NULLPTR_CHECK(assert_start);
    TLG_NULLPTR_CHECK(assert_end);
    TLG_NULLPTR_CHECK(deassert1_start);
    TLG_NULLPTR_CHECK(deassert1_end);
    TLG_NULLPTR_CHECK(deassert2_start);
    TLG_NULLPTR_CHECK(deassert2_end);

    TLG_ReadReg(base_addr, TLG1100_EXT_HSYNC_CTL1, assert_start);
    TLG_ReadReg(base_addr, TLG1100_EXT_HSYNC_CTL2, assert_end);
    TLG_ReadReg(base_addr, TLG1100_EXT_HSYNC_CTL3, deassert1_start);
    TLG_ReadReg(base_addr, TLG1100_EXT_HSYNC_CTL4, deassert1_end);
    TLG_ReadReg(base_addr, TLG1100_EXT_HSYNC_CTL5, deassert2_start);
    TLG_ReadReg(base_addr, TLG1100_EXT_HSYNC_CTL6, deassert2_end);

    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_GetExtVSync
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetExtVSync(uint32 base_addr, 
                    uint16 *assert1_start,       uint16 *assert1_end,
                    uint16 *assert2_start,       uint16 *assert2_end,
                    uint16 *assert3_start,       uint16 *assert3_end)
{
    TLG_NULLPTR_CHECK(assert1_start);
    TLG_NULLPTR_CHECK(assert1_end);
    TLG_NULLPTR_CHECK(assert2_start);
    TLG_NULLPTR_CHECK(assert2_end);
    TLG_NULLPTR_CHECK(assert3_start);
    TLG_NULLPTR_CHECK(assert3_end);

    TLG_ReadReg(base_addr, TLG1100_EXT_VSYNC_CTL1, assert1_start);
    TLG_ReadReg(base_addr, TLG1100_EXT_VSYNC_CTL2, assert1_end);
    TLG_ReadReg(base_addr, TLG1100_EXT_VSYNC_CTL3, assert2_start);
    TLG_ReadReg(base_addr, TLG1100_EXT_VSYNC_CTL4, assert2_end);
    TLG_ReadReg(base_addr, TLG1100_EXT_VSYNC_CTL5, assert3_start);
    TLG_ReadReg(base_addr, TLG1100_EXT_VSYNC_CTL6, assert3_end);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetExtHSync
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetExtHSync(uint32 base_addr, 
                    uint16 assert_start,        uint16 assert_end,
                    uint16 deassert1_start,     uint16 deassert1_end,
                    uint16 deassert2_start,     uint16 deassert2_end)
{
    TLG_WriteReg(base_addr, TLG1100_EXT_HSYNC_CTL1, assert_start);
    TLG_WriteReg(base_addr, TLG1100_EXT_HSYNC_CTL2, assert_end);
    TLG_WriteReg(base_addr, TLG1100_EXT_HSYNC_CTL3, deassert1_start);
    TLG_WriteReg(base_addr, TLG1100_EXT_HSYNC_CTL4, deassert1_end);
    TLG_WriteReg(base_addr, TLG1100_EXT_HSYNC_CTL5, deassert2_start);
    TLG_WriteReg(base_addr, TLG1100_EXT_HSYNC_CTL6, deassert2_end);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetExtVSync
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetExtVSync(uint32 base_addr, 
                    uint16 assert1_start,       uint16 assert1_end,
                    uint16 assert2_start,       uint16 assert2_end,
                    uint16 assert3_start,       uint16 assert3_end)
{
    TLG_WriteReg(base_addr, TLG1100_EXT_VSYNC_CTL1, assert1_start);
    TLG_WriteReg(base_addr, TLG1100_EXT_VSYNC_CTL2, assert1_end);
    TLG_WriteReg(base_addr, TLG1100_EXT_VSYNC_CTL3, assert2_start);
    TLG_WriteReg(base_addr, TLG1100_EXT_VSYNC_CTL4, assert2_end);
    TLG_WriteReg(base_addr, TLG1100_EXT_VSYNC_CTL5, assert3_start);
    TLG_WriteReg(base_addr, TLG1100_EXT_VSYNC_CTL6, assert3_end);

    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_SetHDecimate
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetHDecimate(uint32 base_addr, uint16 decimate)
{
    uint16 vidConfig4;

    TLG_BOUNDS_CHECK(decimate, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG4, &vidConfig4);
    TLGHAL_SET(vidConfig4, decimate, TLG1100_VID_CONFIG4_HDECI_SHIFT,
               TLG1100_VID_CONFIG4_HDECI_MASK);    
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG4, vidConfig4);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetHDecimate
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetHDecimate(uint32 base_addr, uint16 *decimate)
{
    uint16 vidConfig4;

    TLG_NULLPTR_CHECK(decimate);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG4, &vidConfig4);
    TLGHAL_GET(*decimate, vidConfig4, TLG1100_VID_CONFIG4_HDECI_SHIFT,
               TLG1100_VID_CONFIG4_HDECI_MASK);    
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetVidOutType
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetVidOutType(uint32 base_addr, uint16 *vidOutType)
{
    uint16 vidConfig3;

    TLG_NULLPTR_CHECK(vidOutType);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &vidConfig3);
    TLGHAL_GET(*vidOutType, vidConfig3, TLG1100_VID_CONFIG3_SMP_ADJ_ALG_SHIFT,
                TLG1100_VID_CONFIG3_SMP_ADJ_ALG_MASK);
    return(TLG_ERR_SUCCESS);
}



/*****************************************************************************
* TLG_SetVidOutType
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVidOutType(uint32 base_addr, uint16 vidOutType)
{
    uint16 vidConfig3;

    TLG_BOUNDS_CHECK(vidOutType, TLG_VID_DENC);

    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG3, &vidConfig3);
    TLGHAL_SET(vidConfig3, vidOutType, TLG1100_VID_CONFIG3_SMP_ADJ_ALG_SHIFT,
                TLG1100_VID_CONFIG3_SMP_ADJ_ALG_MASK);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG3, vidConfig3);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetVGA_601_NTSC
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVGA_601_NTSC(uint32 base_addr)
{
    TLG_SetExtHSync(base_addr, 139, 858, 1, 25, 264, 287);
    TLG_SetExtVSync(base_addr, 1, 25, 264, 287, 287, 287);
    TLG_SetVidOutType(base_addr, TLG_VID_DENC);
    TLG_Set601VideoOutClock(base_addr, TLG_INVERT);
    TLG_SetHDecimate(base_addr, TLG_OFF);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetVGA_601_PAL
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVGA_601_PAL(uint32 base_addr)
{
    TLG_SetExtHSync(base_addr, 143, 864, 1, 22, 311, 335);
    TLG_SetExtVSync(base_addr, 1, 22, 311, 335, 264, 265);
    TLG_SetVidOutType(base_addr, TLG_VID_DENC);
    TLG_Set601VideoOutClock(base_addr, TLG_INVERT);
    TLG_SetHDecimate(base_addr, TLG_OFF);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_Set240x240_LCD_NTSC
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_Set240x240_LCD_NTSC(uint32 base_addr)
{

    TLG_SetExtHSync(base_addr, 195, 674, 1, 21, 262, 525);
    TLG_SetExtVSync(base_addr, 1, 19, 0, 0, 0, 0);
    TLG_SetHDecimate(base_addr, TLG_ON);
    TLG_Set601VideoOutClock(base_addr, TLG_NORMAL);
    TLG_SetVidOutType(base_addr, TLG_VID_LCD);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_Set240x240_LCD_PAL
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_Set240x240_LCD_PAL(uint32 base_addr)
{

    TLG_SetExtHSync(base_addr, 197, 676, 1, 46, 287, 625);
    TLG_SetExtVSync(base_addr, 1, 19, 0, 0, 0, 0);
    TLG_SetHDecimate(base_addr, TLG_ON);
    TLG_Set601VideoOutClock(base_addr, TLG_NORMAL);
    TLG_SetVidOutType(base_addr, TLG_VID_LCD);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetQVGA_NTSC
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetQVGA_NTSC(uint32 base_addr)
{

//360*244
    TLG_SetExtHSync(base_addr, 139,858, 1, 19, 264, 525);
    TLG_SetExtVSync(base_addr, 1, 19, 0, 0, 0, 0);

#if 0	
    TLG_SetHDecimate(base_addr, TLG_ON);
    TLG_Set601VideoOutClock(base_addr, TLG_NORMAL);
    TLG_SetVidOutType(base_addr, TLG_VID_LCD);
#else
    TLG_SetVidOutType(base_addr, TLG_VID_DENC);
    TLG_Set601VideoOutClock(base_addr, TLG_NORMAL);
    TLG_SetHDecimate(base_addr, TLG_ON);
#endif

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetQVGA_PAL
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetQVGA_PAL(uint32 base_addr)
{
   //360*288
    TLG_SetExtHSync(base_addr, 146, 864, 1, 22, 311, 625);
    TLG_SetExtVSync(base_addr, 1, 22, 0, 0, 0, 0);

#if 0
    TLG_SetHDecimate(base_addr, TLG_ON);
    TLG_Set601VideoOutClock(base_addr, TLG_NORMAL);
    TLG_SetVidOutType(base_addr, TLG_VID_LCD);
#else
    TLG_SetVidOutType(base_addr, TLG_VID_DENC); 
    TLG_Set601VideoOutClock(base_addr, TLG_NORMAL);
    TLG_SetHDecimate(base_addr, TLG_ON);
#endif

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetHSyncPolarity
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetHSyncPolarity(uint32 base_addr, uint16 *polarity)
{

    uint16 syncCfg;

    TLG_NULLPTR_CHECK(polarity);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_GET(*polarity, syncCfg, TLG1100_EXT_SYNC_CFG_H_SHIFT,
                TLG1100_EXT_SYNC_CFG_H_MASK);
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_SetHSyncPolarity
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetHSyncPolarity(uint32 base_addr, uint16 polarity)
{
    uint16 syncCfg;

    TLG_BOUNDS_CHECK(polarity, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_SET(syncCfg, polarity, TLG1100_EXT_SYNC_CFG_H_SHIFT,
                TLG1100_EXT_SYNC_CFG_H_MASK);
    TLG_WriteReg(base_addr, TLG1100_EXT_SYNC_CFG, syncCfg);
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_GetVSyncPolarity
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetVSyncPolarity(uint32 base_addr, uint16 *polarity)
{
    uint16 syncCfg;

    TLG_NULLPTR_CHECK(polarity);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_GET(*polarity, syncCfg, TLG1100_EXT_SYNC_CFG_V_SHIFT,
                TLG1100_EXT_SYNC_CFG_V_MASK);
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_SetVSyncPolarity
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVSyncPolarity(uint32 base_addr, uint16 polarity)
{
    uint16 syncCfg;

    TLG_BOUNDS_CHECK(polarity, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_SET(syncCfg, polarity, TLG1100_EXT_SYNC_CFG_V_SHIFT,
                TLG1100_EXT_SYNC_CFG_V_MASK);
    TLG_WriteReg(base_addr, TLG1100_EXT_SYNC_CFG, syncCfg);
    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetGPIOEnable
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetGPIOEnable(uint32 base_addr, uint16 *value)
{
    uint16 gpioEnable;

    TLG_NULLPTR_CHECK(value);

    TLG_ReadReg(base_addr, TLG1100_GPIO_ENABLE, &gpioEnable);
    TLGHAL_GET(*value, gpioEnable, TLG1100_GPIO_ENABLE_USER_SHIFT,
                TLG1100_GPIO_ENABLE_USER_MASK);

    return (TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetGPIOEnable
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetGPIOEnable(uint32 base_addr, uint16 mask, uint16 value)
{
    uint16 gpioEnable;
    uint16 gpios;

    TLG_BOUNDS_CHECK(mask,  TLG_GPIO1|TLG_GPIO2|TLG_GPIO3);
    TLG_BOUNDS_CHECK(value, TLG_GPIO1|TLG_GPIO2|TLG_GPIO3);

    TLG_ReadReg(base_addr, TLG1100_GPIO_ENABLE, &gpioEnable);
    TLGHAL_GET(gpios, gpioEnable, TLG1100_GPIO_ENABLE_USER_SHIFT,
                TLG1100_GPIO_ENABLE_USER_MASK);
    value = (value & mask) | (gpios & ~mask);
    TLGHAL_SET(gpioEnable, value, TLG1100_GPIO_ENABLE_USER_SHIFT,
                TLG1100_GPIO_ENABLE_USER_MASK);
    TLG_WriteReg(base_addr, TLG1100_GPIO_ENABLE, gpioEnable);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetGPIOOutput
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetGPIOOutput(uint32 base_addr, uint16 *value)
{
    uint16 gpioOutput;

    TLG_NULLPTR_CHECK(value);

    TLG_ReadReg(base_addr, TLG1100_GPIO_OUTPUT, &gpioOutput);
    TLGHAL_GET(*value, gpioOutput, TLG1100_GPIO_OUTPUT_USER_SHIFT,
                TLG1100_GPIO_OUTPUT_USER_MASK);

    return (TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_SetGPIOOutput
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetGPIOOutput(uint32 base_addr, uint16 mask, uint16 value)
{
    uint16 gpioOutput;
    uint16 gpios;

    TLG_BOUNDS_CHECK(mask,  TLG_GPIO1|TLG_GPIO2|TLG_GPIO3);
    TLG_BOUNDS_CHECK(value, TLG_GPIO1|TLG_GPIO2|TLG_GPIO3);

    TLG_ReadReg(base_addr, TLG1100_GPIO_OUTPUT, &gpioOutput);
    TLGHAL_GET(gpios, gpioOutput, TLG1100_GPIO_OUTPUT_USER_SHIFT,
                TLG1100_GPIO_OUTPUT_USER_MASK);
    value = (value & mask) | (gpios & ~mask);
    TLGHAL_SET(gpioOutput, value, TLG1100_GPIO_OUTPUT_USER_SHIFT,
                TLG1100_GPIO_OUTPUT_USER_MASK);
    TLG_WriteReg(base_addr, TLG1100_GPIO_OUTPUT, gpioOutput);

    return(TLG_ERR_SUCCESS);
}

                              /*   26.367  32.143  44.118  48.214  52.734 */   
const uint8 tlg_aud_cic_rate[]  = {   0,    210,    153,    140,    128};
const uint8 tlg_aud_deci2_sel[] = {   0,      0,      1,      1,      1};
const uint8 tlg_aud_mlen[]      = {   8,     12,      9,      8,      4};
const uint8 tlg_aud_slen[]      = {   0,     35,     34,     35,      0};


/*****************************************************************************
* TLG_GetAudioSampleRate
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetAudioSampleRate(uint32 base_addr, uint16 *rate)
{
    uint16 cic_rate, deci2_sel, mlen, slen, reg;
    int i;

    TLG_NULLPTR_CHECK(rate);

    *rate = TLG_AUD_RATE_NONE;
 
    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD4,  &reg);
    TLGHAL_GET(cic_rate, reg, 
                    TLG1100_SOUND_DEMOD4_CIC_RATE_SHIFT, 
                    TLG1100_SOUND_DEMOD4_CIC_RATE_MASK);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD5,  &reg);
    TLGHAL_GET(deci2_sel, reg, 
                    TLG1100_SOUND_DECI2_SEL_SHIFT, 
                    TLG1100_SOUND_DECI2_SEL_MASK);

    TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD12, &reg);
    TLGHAL_GET(mlen, reg, TLG1100_SOUND_MLEN_SHIFT, TLG1100_SOUND_MLEN_MASK);
    TLGHAL_GET(slen, reg, TLG1100_SOUND_SLEN_SHIFT, TLG1100_SOUND_SLEN_MASK);

    for (i = 0; i < TLG_AUD_RATE_52_734KHZ; i++)
    {
        if (cic_rate  == tlg_aud_cic_rate[i]  &&
            deci2_sel == tlg_aud_deci2_sel[i] &&
            mlen      == tlg_aud_mlen[i]      &&
            slen      == tlg_aud_slen[i])
            {
                *rate = i + 1;
                break;
            }
    }

    return TLG_ERR_SUCCESS;
}


/*****************************************************************************
* TLG_SetAudioSampleRate
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetAudioSampleRate(uint32 base_addr, uint16 rate)
{
    uint16 reg;

    TLG_BOUNDS_CHECK(rate, TLG_AUD_RATE_52_734KHZ);

    if (rate != TLG_AUD_RATE_NONE) 
    {
        TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD4, &reg);
        TLGHAL_SET(reg, tlg_aud_cic_rate[rate-1], 
                    TLG1100_SOUND_DEMOD4_CIC_RATE_SHIFT, 
                    TLG1100_SOUND_DEMOD4_CIC_RATE_MASK);
        TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD4, reg);

        TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD5, &reg);
        TLGHAL_SET(reg, tlg_aud_deci2_sel[rate-1],
                    TLG1100_SOUND_DECI2_SEL_SHIFT, 
                    TLG1100_SOUND_DECI2_SEL_MASK);
        TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD5, reg);

        TLG_ReadReg(base_addr, TLG1100_SOUND_DEMOD12, &reg);
        TLGHAL_SET(reg, tlg_aud_mlen[rate-1],
                    TLG1100_SOUND_MLEN_SHIFT, TLG1100_SOUND_MLEN_MASK);
        TLGHAL_SET(reg, tlg_aud_slen[rate-1],
                    TLG1100_SOUND_SLEN_SHIFT, TLG1100_SOUND_SLEN_MASK);
        TLG_WriteReg(base_addr, TLG1100_SOUND_DEMOD12, reg);
    }

    return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_DeepSleep
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_DeepSleep(uint32 base_addr, tlg_statep state)
{
    uint16 reg;

    TLG_NULLPTR_CHECK(state);

    if (state[0] != TLG_STATE0)
        return TLG_ERR_FAIL;
    
    /* powerdown the analog section */
    TLG_ReadReg(base_addr,  TLG1100_MXS_POWER,      &state[1]);
    TLG_ReadReg(base_addr,  TLG1100_SYN_VCO_PWR,    &state[2]);
    TLG_ReadReg(base_addr,  TLG1100_SYN_CTRL,       &state[3]);
    TLG_ReadReg(base_addr,  TLG1100_SYN_REGULATOR,  &state[4]);

    TLG_WriteReg(base_addr, TLG1100_MXS_POWER,      0xffff);

    TLG_ReadReg(base_addr,  TLG1100_TRKCTRL,        &reg);
    if (reg & (TLG1100_TRKCTRL_CAL_EN|TLG1100_TRKCTRL_POWERUP_DAC))
    {
        TLGHAL_CLEAR(reg,       TLG1100_TRKCTRL_CAL_EN);
        TLGHAL_CLEAR(reg,       TLG1100_TRKCTRL_POWERUP_DAC);
        TLG_WriteReg(base_addr, TLG1100_TRKCTRL,        reg);
    }
    TLG_WriteReg(base_addr, TLG1100_SYN_VCO_PWR,    0xffff);

    TLG_ReadReg(base_addr,  TLG1100_SYN_CTRL,       &reg);
    TLGHAL_CLEAR(reg,       TLG1100_SYN_CTRL_RST_MASK);
    TLG_WriteReg(base_addr, TLG1100_SYN_CTRL,       reg);

    reg = state[4];
    TLGHAL_CLEAR(reg,       TLG1100_SYN_REGULATOR_VOLT_MASK);
    TLG_WriteReg(base_addr, TLG1100_SYN_REGULATOR,  reg);

    /* power down the digital section */
    TLG_ReadReg(base_addr,  TLG1100_PWR, &reg);
    TLGHAL_SET(reg, TLG_ON, TLG1100_PWR_SPORT_ATOP_SHIFT,
                            TLG1100_PWR_SPORT_ATOP_MASK);
    TLG_WriteReg(base_addr, TLG1100_PWR, reg);
    TLGHAL_SET(reg, TLG_ON, TLG1100_PWR_VDD_CORE_SHIFT,
                            TLG1100_PWR_VDD_CORE_MASK);
    TLGHAL_SET(reg, TLG_ON, TLG1100_PWR_XTL_SHIFT,
                            TLG1100_PWR_XTL_MASK);
    TLG_WriteReg(base_addr, TLG1100_PWR, reg);

    TLG_ClearRegShadow(base_addr);

    state[0] = TLG_STATE1;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n Huyanwei Debug TLG_DeepSleep \r\n");
#endif
    return TLG_ERR_SUCCESS;
}
/*****************************************************************************
* TLG_ReturnFromDeepSleep
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_ReturnFromDeepSleep(uint32 base_addr, tlg_statep state)
{
    uint16 data;
    uint16 pwr_reg;
    int         ms    = 0;

    TLG_NULLPTR_CHECK(state);

    if (state[0] != TLG_STATE1)
        return TLG_ERR_FAIL;

    /* power up the digital section */
    TLG_ReadReg(base_addr,      TLG1100_PWR,                    &pwr_reg);
    TLGHAL_SET(pwr_reg, TLG_OFF,TLG1100_PWR_VDD_CORE_SHIFT,
                                TLG1100_PWR_VDD_CORE_MASK);
    TLGHAL_SET(pwr_reg, TLG_OFF,TLG1100_PWR_XTL_SHIFT,
                                TLG1100_PWR_XTL_MASK);
    TLGHAL_SET(pwr_reg, TLG_ON, TLG1100_PWR_JTAG_SHIFT,
                                TLG1100_PWR_JTAG_MASK);
    TLG_WriteReg(base_addr,     TLG1100_PWR,                    pwr_reg);
    TLGHAL_SET(pwr_reg, TLG_OFF,TLG1100_PWR_SPORT_ATOP_SHIFT,
                                TLG1100_PWR_SPORT_ATOP_MASK);
    TLG_WriteReg(base_addr,     TLG1100_PWR,                    pwr_reg);

    /* power up  the analog section */
    TLG_WriteReg(base_addr,     TLG1100_MXS_POWER,              state[1]);
    TLG_WriteReg(base_addr,     TLG1100_SYN_REGULATOR,          state[4]);
    TLG_WriteReg(base_addr,     TLG1100_SYN_VCO_PWR,            state[2]);
    TLG_WriteReg(base_addr,     TLG1100_SYN_CTRL,               state[3]);

    /* reset digital registers to default values */
    TLGHAL_SET(pwr_reg, TLG_ON, TLG1100_PWR_SRST_DTOP_SHIFT,
                                TLG1100_PWR_SRST_DTOP_MASK);
    TLG_WriteReg(base_addr,     TLG1100_PWR,                    pwr_reg);
    TLGHAL_SET(pwr_reg, TLG_OFF,TLG1100_PWR_SRST_DTOP_SHIFT,
                                TLG1100_PWR_SRST_DTOP_MASK);
    TLG_WriteReg(base_addr,     TLG1100_PWR,                    pwr_reg);
    
    TLG_CHIP_VERS_1_2_BEGIN
        #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_1_2)
        TLG_ReadReg(base_addr,  TLG1100_DEMOD_HPF,              &data);
        TLGHAL_SET(data,TLG_ON, TLG1100_DEMOD_HPF_NTCH_DBL_SHIFT,
                                TLG1100_DEMOD_HPF_NTCH_DBL_MASK);
        TLG_WriteReg(base_addr, TLG1100_DEMOD_HPF,              data);
        #endif /* TLG_CMP_CHIP_1_2 */
    TLG_CHIP_VERS_END

    TLG_WriteReg(base_addr,     0x03,                           0x2493);
    TLG_WriteReg(base_addr,     0x036,                          0x30af);
    TLG_WriteReg(base_addr,     0x037,                          0xeed0); 
    TLG_WriteReg(base_addr,     0x039,                          0x3f0);
    TLG_ReadReg(base_addr,      TLG1100_SOUND_DEMOD2,           &data);
    TLGHAL_SET(data, 0x84,      TLG1100_SOUND_DEMOD2_LOCK_SHIFT,
                                TLG1100_SOUND_DEMOD2_LOCK_MASK);
    TLGHAL_CLEAR(data,          TLG1100_SOUND_DEMOD2_HPF_HOLD_MASK);
    TLGHAL_CLEAR(data,          TLG1100_SOUND_DEMOD2_HPF_GAIN_MASK);
    TLG_WriteReg(base_addr,     TLG1100_SOUND_DEMOD2,           data);

    TLG_ReadReg(base_addr,      TLG1100_SOUND_DEMOD3,           &data);
    TLGHAL_SET(data, 1,         TLG1100_SOUND_DEEMP2_EN_SHIFT,
                                TLG1100_SOUND_DEEMP2_EN_MASK); 
    TLGHAL_SET(data, 4,         TLG1100_SOUND_DEEMP2_SEL_SHIFT,
                                TLG1100_SOUND_DEEMP2_SEL_MASK); 
    TLGHAL_SET(data, 10,        TLG1100_SOUND_DEEMP_SEL_SHIFT,
                                TLG1100_SOUND_DEEMP_SEL_MASK); 
    TLG_WriteReg(base_addr,     TLG1100_SOUND_DEMOD3,           data);

    /* do all but initial powerup portion of TLG_Init() */
    state[0] = TLG_STATE1;
    do {
        TLG_InitASYNC(base_addr, state, &ms);
        if (ms)
            TLG_Delay((uint16)ms);
    } while (state[0] != TLG_STATE_FINAL);

    state[0] = TLG_STATE_FINAL;

    return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_GetLowPowerHsync
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetHsyncLowPower(uint32 base_addr, uint16 *val)
{
    uint16 syncCfg;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_GET(*val, syncCfg, TLG1100_EXT_SYNC_CFG_HL_SHIFT,
                TLG1100_EXT_SYNC_CFG_HL_MASK);
	return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_SetLowPowerHsync
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetHsyncLowPower(uint32 base_addr, uint16 val)
{   
    uint16 syncCfg;

	TLG_BOUNDS_CHECK(val, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
	/*syncCfg &= TLG1100_EXT_SYNC_CFG_H_MASK;*/
	if (syncCfg & TLG1100_EXT_SYNC_CFG_H_MASK)
	{
		TLGHAL_CLEAR(syncCfg, TLG1100_EXT_SYNC_CFG_HL_MASK);
		TLGHAL_SET(syncCfg, val, TLG1100_EXT_SYNC_CFG_HH_SHIFT,
                TLG1100_EXT_SYNC_CFG_HH_MASK);
	} else {
		TLGHAL_CLEAR(syncCfg, TLG1100_EXT_SYNC_CFG_HH_MASK);
		TLGHAL_SET(syncCfg, val, TLG1100_EXT_SYNC_CFG_HL_SHIFT,
                TLG1100_EXT_SYNC_CFG_HL_MASK);
	}
	TLG_WriteReg(base_addr, TLG1100_EXT_SYNC_CFG, syncCfg);
    return TLG_ERR_SUCCESS;
}
/*****************************************************************************
* TLG_GetVDecimate
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetVDecimate(uint32 base_addr, uint16 *val)
{
    uint16 syncCfg;

    TLG_NULLPTR_CHECK(val);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_GET(*val, syncCfg, TLG1100_EXT_SYNC_CFG_SL_SHIFT,
                TLG1100_EXT_SYNC_CFG_SL_MASK);
	return TLG_ERR_SUCCESS;
}
/*****************************************************************************
* TLG_SetVDecimate
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetVDecimate(uint32 base_addr, uint16 val)
{    
	uint16 syncCfg;

	TLG_BOUNDS_CHECK(val, TLG_ON);

    TLG_ReadReg(base_addr, TLG1100_EXT_SYNC_CFG, &syncCfg);
    TLGHAL_SET(syncCfg, val, TLG1100_EXT_SYNC_CFG_SL_SHIFT,
                TLG1100_EXT_SYNC_CFG_SL_MASK);
    TLG_WriteReg(base_addr, TLG1100_EXT_SYNC_CFG, syncCfg);
    return TLG_ERR_SUCCESS;
}

#ifdef TLG_ENABLE_I2C_QUAL_TESTS

/**
 * Default Values of all TLG registers for rev 1.2
 */
uint16 *tlg_defreg_val;
uint16 tlg_defreg1_2_val[] = {
/*         0       1      2       3       4       5       6        7 */
/*         8       9      a       b       c       d       e        f */
/*000*/ 0x0010, 0x0000, 0x0000, 0x2093, 0x0001, 0x0002, 0x0004, 0x0008, 
/*000*/ 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0001,
/*001*/ 0x8080, 0x8010, 0x1010, 0x0000, 0x0000, 0x0040, 0x0040, 0x0040,
/*001*/ 0x0040, 0x1010, 0x0810, 0x0000, 0x0000, 0x0000, 0x0021, 0x6600,
/*002*/ 0x0000, 0x8000, 0x1364, 0x0000, 0x0000, 0x0020, 0x0040, 0x0040,
/*002*/ 0x0000, 0x0000, 0x0000, 0x0020, 0x0010, 0x0010, 0x0000, 0x0000,
/*003*/ 0x0000, 0x0040, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*003*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x00a8, 0x0005, 0x0000, 0x0000, 
/*004*/ 0x0007, 0x000c, 0x00f9, 0x0064, 0x000c, 0x0033, 0x0064, 0x000c,
/*004*/ 0x0062, 0x0064, 0x0040, 0xa5ed, 0x0400, 0x0000, 0x0400, 0x060c,
/*005*/ 0x0014, 0x000a, 0x02e2, 0x61d1, 0x80c8, 0x2130, 0x0450, 0x8000,
/*005*/ 0x4000, 0x8056, 0x1488, 0x1044, 0x7808, 0xa3a3, 0x810f, 0x0000,
/*006*/ 0x1864, 0x0120, 0xfc04, 0x4001, 0x43e1, 0x000c, 0x4096, 0x000c,
/*006*/ 0x9eeb, 0x0016, 0x0160, 0x03c6, 0x0380, 0x160c, 0x00d8, 0x30c0,
/*007*/ 0x8634, 0x8c6a, 0x4000, 0x8160, 0x0452, 0x0200, 0x0080, 0x003c,
/*007*/ 0x0002, 0x0108, 0x020d, 0x020d, 0x020d, 0x020d, 0x020d, 0x0089,
/*008*/ 0x035a, 0x020e, 0x020e, 0x020e, 0x020e, 0x0001, 0x0019, 0x0108,
/*008*/ 0x011f, 0x011f, 0x011f, 0x0001, 0x8440, 0x1144, 0x0000, 0x0000,
/*009*/ 0x031c, 0x0593, 0x1555, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 
/*009*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00a*/ 0x2306, 0x0498, 0x0800, 0x0229, 0x06cd, 0x0fff, 0x0000, 0x2180,
/*00a*/ 0x8080, 0x7f80, 0x0229, 0x0999, 0x0001, 0x0000, 0x0000, 0x0000,
/*00b*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00b*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00c*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00c*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00d*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00d*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00e*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00e*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00f*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00f*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*010*/ 0x0001, 0x4002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 
/*010*/ 0x0100, 0x0200, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000,
/*011*/ 0x0000, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*011*/ 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
/*012*/ 0x0000, 0x0000, 0x000a, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 
/*012*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x4000, 0x0000, 0x0004,
/*013*/ 0x0000, 0x0200, 0x0000, 0x0000, 0x0000, 0x4000, 0x0000, 0x0000, 
/*013*/ 0x0000, 0x0600, 0x0000, 0x0040, 0x0000, 0x0000, 0x0001, 0x0001,
/*014*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*014*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*015*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*015*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*016*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*016*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*017*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*017*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*018*/ 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0052, 0x0000, 0x0000, 
/*018*/ 0x0052, 0x0000, 0x0000, 0x0052, 0x0000, 0x0000, 0x0000, 0xaa80,
/*019*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*019*/ 0x0063, 0x0000, 0x0000, 0x9400, 0x0000, 0x0000, 0x0000, 0x0000,
/*01a*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0202, 0x0390, 0x1a6c, 0x0044, 
/*01a*/ 0x048a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*01b*/ 0x0000, 0x0040, 0x1f90, 0x27b0, 0x0061, 0x0244, 0x0000, 0x06c1, 
/*01b*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

uint16 tlg_defreg1_3_val[] = {
/*         0       1      2       3       4       5       6        7 */
/*         8       9      a       b       c       d       e        f */
/*000*/ 0x0010, 0x0000, 0x0000, 0x2093, 0x0001, 0x0002, 0x0004, 0x0008, 
/*000*/ 0x0010, 0x0020, 0x0040, 0x0080, 0x0100, 0x0200, 0x0400, 0x0001,
/*001*/ 0x8080, 0x8010, 0x1010, 0x0000, 0x0000, 0x0040, 0x0040, 0x0040,
/*001*/ 0x0040, 0x1010, 0x0810, 0x0000, 0x0000, 0x0000, 0x0021, 0x6600,
/*002*/ 0x0000, 0x8000, 0x1364, 0x0000, 0x0000, 0x0020, 0x0040, 0x0040,
/*002*/ 0x0000, 0x0000, 0x0000, 0x0020, 0x0010, 0x0010, 0x0000, 0x0000,
/*003*/ 0x0000, 0x0040, 0x0040, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*003*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x00a8, 0x0005, 0x0000, 0x0000, 
/*004*/ 0x0007, 0x000c, 0x00f9, 0x0064, 0x000c, 0x0033, 0x0064, 0x000c,
/*004*/ 0x0062, 0x0064, 0x0040, 0xa5ed, 0x0400, 0x0000, 0x0400, 0x060c,
/*005*/ 0x0014, 0x000a, 0x02e2, 0x61d1, 0x80c8, 0x2130, 0x0450, 0x8000,
/*005*/ 0x4000, 0x8056, 0x1488, 0x1044, 0x7808, 0xa3a3, 0x810f, 0x0000,
/*006*/ 0x1864, 0x0120, 0xfc04, 0x4001, 0x43e1, 0x000c, 0x4096, 0x000c,
/*006*/ 0x9eeb, 0x0016, 0x0160, 0x03c6, 0x0380, 0x160c, 0x00d8, 0x30c0,
/*007*/ 0x8634, 0x8c6a, 0x4000, 0x8160, 0x0452, 0x0200, 0x0080, 0x003c,
/*007*/ 0x0002, 0x0108, 0x020d, 0x020d, 0x020d, 0x020d, 0x020d, 0x0089,
/*008*/ 0x035a, 0x020e, 0x020e, 0x020e, 0x020e, 0x0001, 0x0019, 0x0108,
/*008*/ 0x011f, 0x011f, 0x011f, 0x0001, 0x8440, 0x1144, 0x0000, 0x0000,
/*009*/ 0x031c, 0x0593, 0x1555, 0x0000, 0x0000, 0x0000, 0x0800, 0x0000, 
/*009*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00a*/ 0x2306, 0x0498, 0x0800, 0x0229, 0x06cd, 0x0fff, 0x0000, 0x2180,
/*00a*/ 0x8080, 0x7f80, 0x0229, 0x0999, 0x0001, 0x0000, 0x0000, 0x0000,
/*00b*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00b*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00c*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00c*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00d*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00d*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00e*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00e*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00f*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*00f*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*010*/ 0x0001, 0x4002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, 
/*010*/ 0x0100, 0x0200, 0x0000, 0x0400, 0x0000, 0x0000, 0x0000, 0x0000,
/*011*/ 0x0000, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*011*/ 0x0000, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000,
/*012*/ 0x0000, 0x0000, 0x000a, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 
/*012*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0400, 0x4000, 0x0000, 0x0004,
/*013*/ 0x0000, 0x0200, 0x0000, 0x0000, 0x0000, 0x4000, 0x0000, 0x0000, 
/*013*/ 0x0000, 0x0600, 0x0000, 0x0040, 0x0000, 0x0000, 0x0001, 0x0001,
/*014*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*014*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*015*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*015*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*016*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*016*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*017*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*017*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*018*/ 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0052, 0x0000, 0x0000, 
/*018*/ 0x0052, 0x0000, 0x0000, 0x0052, 0x0000, 0x0000, 0x0000, 0xaa80,
/*019*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
/*019*/ 0x0063, 0x0000, 0x0000, 0x9400, 0x0000, 0x0000, 0x0000, 0x0000,
/*01a*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0202, 0x0390, 0x1a6c, 0x0044, 
/*01a*/ 0x048a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
/*01b*/ 0x0000, 0x0040, 0x1f90, 0x27b0, 0x0061, 0x0244, 0x0000, 0x06c1, 
/*01b*/ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

#define TLG_VALID_DEF_REG(a) (((0x0000 <= (a) <= 0x00ac) || \
                               (0x0100 <= (a) <= 0x0148) || \
                               (0x0180 <= (a) <= 0x01b8)) && \
                              ((a) != 0x00ac && (a) != 0x0001 && \
							   (a) != 0x0135 && (a) != 0x4000 && \
							   (a) != 0x0139 && (a) != 0x0600 && \
							   (a) != 0x010e && (a) != 0x0110 && \
                               (a) != 0x0114 && (a) != 0x011b && \
                               (a) != 0x0124 && (a) != 0x0125 && \
                               (a) != 0x0128 && (a) != 0x0129 && \
                               (a) != 0x012a && (a) != 0x012c && \
                               (a) != 0x0132 && (a) != 0x010d && \
                               (a) != 0x011e && (a) != 0x0121 && \
                               (a) != 0x012b && (a) != 0x0000 && \
                               (a) != 0x010c && (a) != 0x018e))

TLG1100DLL_API int TLG_TestRegVal_Init(uint32 base_addr)
{
#ifdef TLG_SUPPORT_RUNTIME_CHECK
    {uint32 version;
    TLG_GetChipVersion(base_addr, &version);};
#endif /* TLG_SUPPORT_RUNTIME_CHECK */
TLG_CHIP_VERS_1_3_BEGIN
    #if defined(TLG_CMP_CHIP_1_3)
		TLG_REG_LOG((b,"setting defreg to 1.3\n"));
		tlg_defreg_val = tlg_defreg1_3_val;
    #endif /* TLG_CMP_CHIP_1_3 */
TLG_CHIP_VERS_ELSE
    #if defined(TLG_CMP_CHIP_1_2)
		TLG_REG_LOG((b,"setting defreg to 1.2\n"));
        tlg_defreg_val = tlg_defreg1_2_val;
    #endif /* !TLG_CMP_CHIP_1_3 */
TLG_CHIP_VERS_END

	return 0;
}

TLG1100DLL_API int TLG_TestRegVal(uint32 base_addr, uint16 reg, uint16 val)
{
    uint16 regval;

	TLG_ReadRegNS(base_addr, reg, &regval);

    if (regval != val)
    {
        TLG_REG_LOG((b,"ERROR: Val for Register 0x%x: Expected 0x%x, Received 0x%x\n",
                      reg, val, regval));
        return 1;
    }
    return 0;
}


TLG1100DLL_API void TLG_TestDefRegs(uint32 base_addr)
{
    uint16  reg;
    int     test_errors = 0;

	TLG_TestRegVal_Init(base_addr);
    TLG_REG_LOG((b, "START TLG DEFAULT REGISTER TESTS\n"));
    for (reg=0; reg <= 0x01b8; reg++)
        if (TLG_VALID_DEF_REG(reg))
            test_errors += TLG_TestRegVal(base_addr, reg, tlg_defreg_val[reg]);
    TLG_REG_LOG((b, "TOTAL DEFAULT REG VAL TEST ERRORS: %d\n", test_errors));
    TLG_REG_LOG((b, "END TLG DEFAULT REGISTER TESTS\n"));
}

TLG1100DLL_API void TLG_TestWriteRegs(uint32 base_addr)
{
    int            test_errors = 0;
    uint16         reg;
    unsigned short regval = 0;

	TLG_TestRegVal_Init(base_addr);
    TLG_REG_LOG((b, "START TLG WRITE REGISTER TESTS\n"));
    for (reg = 0x5; reg <= 0xe; reg++)
    {
        /* walking 1 */
        for (regval = 1; 1; regval = 2*regval)
        {
            TLG_WriteReg(base_addr, reg, regval);
            test_errors += TLG_TestRegVal(base_addr, reg, regval);
            if (regval == 0x8000) break;
        }
         /* walking 3 */
        for (regval = 3; 1; regval = 2*regval)
        {
            TLG_WriteReg(base_addr, reg, regval);
            test_errors += TLG_TestRegVal(base_addr, reg, regval);
            if (regval == 0xc000) break;
        }
       /* growing 1 */
        for (regval = 1; 1; regval = 2*regval + 1)
        {
            TLG_WriteReg(base_addr, reg, regval);
            test_errors += TLG_TestRegVal(base_addr, reg, regval);
            if (regval == 0xffff) break;
        }
        /* walking even bits */
        for (regval = 1; 1; regval = 4*regval + 1)
        {
            TLG_WriteReg(base_addr, reg, regval);
            test_errors += TLG_TestRegVal(base_addr, reg, regval);
            if (regval == 0x5555) break;
        }
        /* walking odd bits */
        for (regval = 2; 1; regval = 4*regval + 2)
        {
            TLG_WriteReg(base_addr, reg, regval);
            test_errors += TLG_TestRegVal(base_addr, reg, regval);
            if (regval == 0xaaaa) break;
        }
		/* restore default value */
		TLG_WriteReg(base_addr, reg, tlg_defreg_val[reg]); 
    }
    TLG_REG_LOG((b, "TOTAL WRITE REG VAL TEST ERRORS: %d\n", test_errors));
    TLG_REG_LOG((b, "END TLG WRITE REGISTER TESTS\n"));
}
#endif /* TLG_ENABLE_I2C_QUAL_TESTS */

/*****************************************************************************
* TLG_GetMobileVidEnhancement
*
*
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetMobileVidEnhancement(uint32 base_addr, uint16 *mode, 
                                                uint16 *val) {
    uint16 videoConfig10;
    uint16 fAvg;
    uint16 fAvg_auto;
    uint16 fAvg_auto2;

    
    TLG_NULLPTR_CHECK(mode);
    TLG_NULLPTR_CHECK(val);
    
    TLG_ReadReg(base_addr, TLG1100_FAVG,  &fAvg);
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG10,  &videoConfig10);

    TLGHAL_GET(fAvg_auto, fAvg, TLG1100_FAVG_AUTO_SHIFT,
                        TLG1100_FAVG_AUTO_MASK);
    TLGHAL_GET(fAvg_auto2, fAvg, TLG1100_FAVG_AUTO2_SHIFT,
                        TLG1100_FAVG_AUTO2_MASK);
    *mode = (fAvg_auto == TLG_ON) && (fAvg_auto2 == TLG_ON);
    
    TLGHAL_GET(*val, videoConfig10, TLG1100_VID_CONFIG10_FAVG_ALPHA_SHIFT,
                        TLG1100_VID_CONFIG10_FAVG_ALPHA_MASK);
                        
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_SetMobileVidEnhancement
*
*
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_SetMobileVidEnhancement(uint32 base_addr, uint16 mode,
                                                uint16 val) {
    uint16  fAvg,
            videoConfig10;
    
    TLG_BOUNDS_CHECK(val, TLG_MVE_A_MAX);
	TLG_BOUNDS_CHECK(mode, TLG_MVE_MAX);
    
    TLG_ReadReg(base_addr, TLG1100_FAVG,  &fAvg);
    TLG_ReadReg(base_addr, TLG1100_VID_CONFIG10,  &videoConfig10);
    
    if (mode == TLG_MVE_AUTO) {
        
        TLGHAL_SET(fAvg, TLG_ON, TLG1100_FAVG_AUTO_SHIFT,
                    TLG1100_FAVG_AUTO_MASK);
        TLGHAL_SET(fAvg, TLG_ON, TLG1100_FAVG_AUTO2_SHIFT,
                    TLG1100_FAVG_AUTO2_MASK);
        TLGHAL_SET(videoConfig10, TLG_ON, TLG1100_VID_CONFIG10_FAVG_EN_SHIFT,
                    TLG1100_VID_CONFIG10_FAVG_EN_MASK);
        TLGHAL_SET(videoConfig10, 0x38, TLG1100_VID_CONFIG10_FAVG_ALPHA_SHIFT,
                    TLG1100_VID_CONFIG10_FAVG_ALPHA_MASK);
    }
    else {     
        TLGHAL_SET(fAvg, TLG_OFF, TLG1100_FAVG_AUTO_SHIFT,
                    TLG1100_FAVG_AUTO_MASK);
        TLGHAL_SET(fAvg, TLG_OFF, TLG1100_FAVG_AUTO2_SHIFT,
                    TLG1100_FAVG_AUTO2_MASK);
        TLGHAL_SET(videoConfig10, TLG_ON, TLG1100_VID_CONFIG10_FAVG_EN_SHIFT,
                    TLG1100_VID_CONFIG10_FAVG_EN_MASK);
        TLGHAL_SET(videoConfig10, val, TLG1100_VID_CONFIG10_FAVG_ALPHA_SHIFT,
                    TLG1100_VID_CONFIG10_FAVG_ALPHA_MASK);
    }
    TLG_WriteReg(base_addr, TLG1100_FAVG, fAvg);
    TLG_WriteReg(base_addr, TLG1100_VID_CONFIG10, videoConfig10);
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_HardReset
*****************************************************************************/

TLG1100DLL_API int TLG_HardReset(uint32 base_addr)
{
#ifdef TLG_CMP_CHIP_1_3
    
	uint16 reg;
	int retval;

    /* Send STOP condition on I2C */
    retval = TLG_ReadRegNS(base_addr,TLG1100_PWR,&reg);
    TLG_Delay(5);

    /* Toggle SP_Reg0[6] to reset sport registers in DTOP */
    TLG_ReadReg(base_addr,TLG1100_PWR, &reg);
    TLGHAL_SET(reg,1,TLG1100_PWR_SRST_DTOP_SHIFT,TLG1100_PWR_SRST_DTOP_MASK);
    TLG_WriteReg(base_addr,TLG1100_PWR,reg);
    TLG_Delay(5);

    TLG_ReadReg(base_addr,TLG1100_PWR, &reg);
    TLGHAL_SET(reg,0,TLG1100_PWR_SRST_DTOP_SHIFT,TLG1100_PWR_SRST_DTOP_MASK);
    TLG_WriteReg(base_addr,TLG1100_PWR,reg);
    TLG_Delay(5);

    /* Write SP_Reg1[0] to 1 (self-clearing) */
    TLG_ReadReg(base_addr,TLG1100_SRST, &reg);
    TLGHAL_SET(reg,1,TLG1100_SRST_SOFT_RST_SHIFT,TLG1100_SRST_SOFT_RST_MASK);
    TLG_WriteReg(base_addr,TLG1100_SRST,reg);
    TLG_Delay(5);

    /* Write all ATOP Registers with their default values */
    TLG_WriteReg(base_addr, 0x180, 0xffff);
    TLG_WriteReg(base_addr, 0x181, 0xffff);
    TLG_WriteReg(base_addr, 0x182, 0x0000);
    TLG_WriteReg(base_addr, 0x183, 0x0000);
    TLG_WriteReg(base_addr, 0x184, 0x0000);
    TLG_WriteReg(base_addr, 0x185, 0x0052);
    TLG_WriteReg(base_addr, 0x186, 0x0000);
    TLG_WriteReg(base_addr, 0x187, 0x0000);
    TLG_WriteReg(base_addr, 0x188, 0x0052);
    TLG_WriteReg(base_addr, 0x189, 0x0000);
    TLG_WriteReg(base_addr, 0x18a, 0x0000);
    TLG_WriteReg(base_addr, 0x18b, 0x0052);
    TLG_WriteReg(base_addr, 0x18c, 0x0000);
    TLG_WriteReg(base_addr, 0x18e, 0x0300);
    TLG_WriteReg(base_addr, 0x18f, 0xaa80);
    TLG_WriteReg(base_addr, 0x190, 0x0000);
    TLG_WriteReg(base_addr, 0x191, 0x0000);
    TLG_WriteReg(base_addr, 0x192, 0x0000);
    TLG_WriteReg(base_addr, 0x193, 0x0000);
    TLG_WriteReg(base_addr, 0x194, 0x0000);
    TLG_WriteReg(base_addr, 0x195, 0x0000);
    TLG_WriteReg(base_addr, 0x196, 0x0000);
    TLG_WriteReg(base_addr, 0x197, 0x0000);
    TLG_WriteReg(base_addr, 0x198, 0x0063);
    TLG_WriteReg(base_addr, 0x199, 0x0000);
    TLG_WriteReg(base_addr, 0x19a, 0x0000);
    TLG_WriteReg(base_addr, 0x19b, 0x9400);
    TLG_WriteReg(base_addr, 0x19c, 0x0000);
    TLG_WriteReg(base_addr, 0x19d, 0x0000);
    TLG_WriteReg(base_addr, 0x19e, 0x0000);
    TLG_WriteReg(base_addr, 0x19f, 0x0000);
    TLG_WriteReg(base_addr, 0x1a0, 0x0000);
    TLG_WriteReg(base_addr, 0x1a1, 0x0000);
    TLG_WriteReg(base_addr, 0x1a2, 0x0000);
    TLG_WriteReg(base_addr, 0x1a3, 0x0000);
    TLG_WriteReg(base_addr, 0x1a4, 0x0202);
    TLG_WriteReg(base_addr, 0x1a5, 0x0390);
    TLG_WriteReg(base_addr, 0x1a6, 0x1a6c);
    TLG_WriteReg(base_addr, 0x1a7, 0x0044);
    TLG_WriteReg(base_addr, 0x1a8, 0x048a);
    TLG_WriteReg(base_addr, 0x1a9, 0x0000);
    TLG_WriteReg(base_addr, 0x1aa, 0x0000);
    TLG_WriteReg(base_addr, 0x1ab, 0x0000);
    TLG_WriteReg(base_addr, 0x1ac, 0x0000);
    TLG_WriteReg(base_addr, 0x1ad, 0x0000);
    TLG_WriteReg(base_addr, 0x1ae, 0x0000);
    TLG_WriteReg(base_addr, 0x1af, 0x0000);
    TLG_WriteReg(base_addr, 0x1b0, 0x0000);
    TLG_WriteReg(base_addr, 0x1b1, 0x0040);
    TLG_WriteReg(base_addr, 0x1b2, 0x1f90);
    TLG_WriteReg(base_addr, 0x1b3, 0x27b0);
    TLG_WriteReg(base_addr, 0x1b4, 0x0061);
    TLG_WriteReg(base_addr, 0x1b5, 0x0244);
    TLG_WriteReg(base_addr, 0x1b6, 0x0000);
    TLG_WriteReg(base_addr, 0x1b7, 0x06c1);
    TLG_WriteReg(base_addr, 0x1b8, 0x0000);
	
	return TLG_ERR_SUCCESS;
#else
	return TLG_ERR_NOT_SUPPORTED
#endif /* TLG_CMP_CHIP_1_3 */
}

/*****************************************************************************
* TLG_LockVScreen
*****************************************************************************/

TLG1100DLL_API int TLG_LockVScreen(uint32 base_addr)
{
    uint16 reg;
    uint16 valTmp;

	TLG_ReadReg(base_addr, TLG1100_VID_CONFIG4, &reg);
	TLGHAL_GET(valTmp,reg,TLG1100_VID_V_WIN_SHIFT,TLG1100_VID_V_WIN_MASK);
    if (valTmp) {
        TLGHAL_SET(reg, 0, TLG1100_VID_V_WIN_SHIFT,
                    TLG1100_VID_V_WIN_MASK);
        TLG_WriteReg(base_addr, TLG1100_VID_CONFIG4, reg);
    }
    return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_UnlockVScreen
*****************************************************************************/

TLG1100DLL_API int TLG_UnlockVScreen(uint32 base_addr)
{
    uint16 reg;
    uint16 valTmp;

	TLG_ReadReg(base_addr, TLG1100_VID_CONFIG4, &reg);
	TLGHAL_GET(valTmp,reg,TLG1100_VID_V_WIN_SHIFT,TLG1100_VID_V_WIN_MASK);
    if (valTmp==0) {
        TLGHAL_SET(reg, 6, TLG1100_VID_V_WIN_SHIFT,
                    TLG1100_VID_V_WIN_MASK);
        TLG_WriteReg(base_addr, TLG1100_VID_CONFIG4, reg);
    }
    return TLG_ERR_SUCCESS;
}
