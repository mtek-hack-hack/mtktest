/*****************************************************************************
* FILENAME
* tlg1100Mfg.c
*
*
* ABSTRACT
* This file contains Application Programmer's Interface library support for
* manufacturing floor tests of the TLG1100 Ultra Low Power NTSC/PAL
* Tuner/Decoder Front End.
*
* $Revision: 1.2 $
*
* (c) 2006 Telegent Systems
*****************************************************************************/

#include "tlg1100Api.h"
#include "tlg1100Hal.h"
#include "tlg1100i2c.h"

/*****************************************************************************
* TLG_FreezeAgcLoops
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_FreezeAgcLoops(uint32 base_addr, int minmax, tlg_statep state)
{
    uint16 lna2_gain, bb1_gain, bb2_gain;

    if (minmax == TLG_FREEZE_MAX)
    {
        lna2_gain = 0x1200;
        bb1_gain  = 0xf800;
        bb2_gain  = 0xd400;
    } else {
        lna2_gain = 0x0000;
        bb1_gain  = 0x0000;
        bb2_gain  = 0x0000;
    }
    TLG_ReadReg(base_addr, TLG1100_ATOP_LNACAL_7,       &state[1]);
    TLG_WriteReg(base_addr,TLG1100_ATOP_LNACAL_6,       lna2_gain);
    TLG_WriteReg(base_addr,TLG1100_ATOP_LNACAL_7,       0xc000);
    TLG_ReadReg(base_addr, TLG1100_ATOP_AGC_CAL_12,     &state[2]);
    TLG_WriteReg(base_addr,TLG1100_ATOP_AGC_CAL_14,     bb1_gain);
    TLG_WriteReg(base_addr,TLG1100_ATOP_AGC_CAL_13,     bb2_gain);
    TLG_WriteReg(base_addr,TLG1100_ATOP_AGC_CAL_12,     0x0003);

	state[0] = TLG_STATE1;
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_RestoreAgcLoops
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_RestoreAgcLoops(uint32 base_addr, tlg_statep state)
{
    if (state[0] != TLG_STATE1)
        return (TLG_ERR_PARAM);
    TLG_WriteReg(base_addr, TLG1100_ATOP_LNACAL_7,      state[1]);
    TLG_WriteReg(base_addr, TLG1100_ATOP_AGC_CAL_12,    state[2]);
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_EnterAdcMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_EnterAdcMode(uint32 base_addr, tlg_statep state)
{
    uint16 reg;

#ifdef TLG_SUPPORT_RUNTIME_CHECK
    {uint32 version; TLG_GetChipVersion(base_addr, &version);}
#endif /* TLG_SUPPORT_RUNTIME_CHECK */
TLG_CHIP_VERS_1_2_BEGIN
    #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_2)
    TLG_ReadReg(base_addr, TLG1100_PWR, &state[1]);
    reg = state[1];
    TLGHAL_CLEAR(reg, TLG1100_PWR_CLK27_MASK);
    TLG_WriteReg(base_addr, TLG1100_PWR, reg);
    #endif /* TLG_CMP_CHIP_1_2 */
 TLG_CHIP_VERS_1_1_ELSE
    #ifdef TLG_CMP_CHIP_1_1
    TLG_ReadReg(base_addr, TLG1100_PWR, &state[1]);
    reg = state[1];
    TLGHAL_SET(reg, TLG_ON, TLG1100_PWR_CLK27_SHIFT, TLG1100_PWR_CLK27_MASK);
    TLG_WriteReg(base_addr, TLG1100_PWR, reg);
    #endif /* TLG_CMP_CHIP_1_1 */
 TLG_CHIP_VERS_END

    TLG_ReadReg(base_addr, TLG1100_MODES, &state[2]);
    reg = state[2];
    TLGHAL_SET(reg, TLG1100_MODES_ALT_ADC, TLG1100_MODES_ALT_SHIFT,
                                           TLG1100_MODES_ALT_MASK);
    TLG_WriteReg(base_addr, TLG1100_MODES, reg);

    state[0] = TLG_STATE1;
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_ExitAdcMode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_ExitAdcMode(uint32 base_addr, tlg_statep state)
{
    if (state[0] != TLG_STATE1)
        return(TLG_ERR_PARAM);
    TLG_WriteReg(base_addr, TLG1100_PWR,        state[1]);
    TLG_WriteReg(base_addr, TLG1100_MODES,      state[2]);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_GetTFCalCode
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetTFCalCode(uint32 base_addr, uint16 *tfCalCode)
{
    TLG_NULLPTR_CHECK(tfCalCode);
    /* Tracking Filter cal code */
    TLG_ReadRegNS(base_addr,    TLG1100_ATOP_TRKFIL_CAL_STATUS6,   tfCalCode);
    return TLG_ERR_SUCCESS;
}

/*****************************************************************************
* TLG_GetPeakAgcGain
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetPeakAgcGain(uint32 base_addr, uint16 *peakAgcGain)
{
    TLG_NULLPTR_CHECK(peakAgcGain);
    TLG_ReadRegNS(base_addr, TLG1100_PEAK_RMS_AGC_STAT3, peakAgcGain);
    return TLG_ERR_SUCCESS;
}


/*****************************************************************************
* TLG_GetTotalGain
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_GetTotalGain(uint32 base_addr, uint16 *ttlGain)
{
    uint16 bb1, bb2, lna1, lna2, lna_mode, m6db;
    int res = TLG_ERR_SUCCESS;
    int lna_gain, bb_gain, fix;

    TLG_NULLPTR_CHECK(ttlGain);

    /* Calculate the total gain */
    TLG_ReadRegNS(base_addr,    TLG1100_ATOP_AGCCAL_STATUS3, &bb1);
    TLG_ReadRegNS(base_addr,    TLG1100_ATOP_AGCCAL_STATUS2, &bb2);
    TLGHAL_GET(bb1, bb1,        TLG1100_ATOP_AGCCAL_LOOP1_ACC_SHIFT,
                                TLG1100_ATOP_AGCCAL_LOOP1_ACC_MASK);
    TLGHAL_GET(bb2, bb2,        TLG1100_ATOP_AGCCAL_LOOP2_ACC_SHIFT,
                                TLG1100_ATOP_AGCCAL_LOOP2_ACC_MASK);

#ifdef TLG_SUPPORT_RUNTIME_CHECK
    {uint32 version; TLG_GetChipVersion(base_addr, &version);}
#endif /* TLG_SUPPORT_RUNTIME_CHECK */
TLG_CHIP_VERS_1_2_BEGIN
    #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_1_2)
    TLG_ReadRegNS(base_addr,    TLG1100_VIDSTAT2, &lna1);
    TLGHAL_GET(lna1, lna1,      TLG1100_LNA1_GAIN_SHIFT_1_2,
                                TLG1100_LNA1_GAIN_MASK_1_2);
    #endif /* TLG_CMP_CHIP_1_2 */
 TLG_CHIP_VERS_1_1_ELSE
    #ifdef TLG_CMP_CHIP_1_1
    TLG_ReadRegNS(base_addr,    TLG1100_LNACAL_STAT1, &lna1);
    TLGHAL_GET(lna1, lna1,      TLG1100_LNA1_GAIN_SHIFT_1_1,
                                TLG1100_LNA1_GAIN_MASK_1_1);
    #endif /* TLG_CMP_CHIP_1_1 */
 TLG_CHIP_VERS_END
    TLG_ReadRegNS(base_addr,    TLG1100_LNACAL_STAT2, &lna2);
    TLGHAL_GET(lna2, lna2,      TLG1100_LNA2_GAIN_SHIFT,
                                TLG1100_LNA2_GAIN_MASK);
    TLG_ReadReg(base_addr,      TLG1100_MXS_POWER, &lna_mode);
    TLGHAL_GET(lna_mode, lna_mode,  TLG1100_LNA_MODE_SHIFT,
                                    TLG1100_LNA_MODE_MASK);
    TLG_ReadReg(base_addr,      TLG1100_BBFIL_BIAS, &m6db);
    TLGHAL_GET(m6db, m6db,      TLG1100_BBFIL_M6DB_SHIFT,
                                TLG1100_BBFIL_M6DB_MASK);

    lna_gain    = -20*min(2,(3-lna1)) + -2*max(0, 9-lna2);
    bb_gain     = (bb1 + bb2)/2;
    switch (lna_mode)
    {
    case TLG_LNA_UHF : fix = 11; break;
    case TLG_LNA_VHF2: fix = 12; break;
    case TLG_LNA_VHF1: fix = 13; break;
    default: res = TLG_ERR_FAIL; break;
    }
    if (res == TLG_ERR_SUCCESS)
    {
        fix += (m6db) ? 5 : 11;
        *ttlGain = lna_gain + bb_gain + fix + 21;
    }
    return(res);
}

