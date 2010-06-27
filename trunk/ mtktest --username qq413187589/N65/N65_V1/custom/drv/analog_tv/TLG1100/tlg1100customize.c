#include "tlg1100Hal.h"
#include "tlg1100Api.h"
#include "tlg1100App.h"
#include "tlg1100i2c.h"

#include "tlg1100.h"

void TLGAPP_InitVideoAndAudio(void)
{
    /*
     * BEGIN CUSTOM SECTION: Channel Mode
     * This is the area where a customer sets up their default operating
     * mode, video standard, bandwidth, etc.
     */
    TLG_SetChnStandard(tlg_i2c_addr, TLG_VSTD_PAL_D /*TLG_VSTD_NTSC_M*/);
    TLG_SetChnBandwidth(tlg_i2c_addr, TLG_BW_8);

    /*
     * BEGIN CUSTOM SECTION: Audio Out Mode
     * Set up default audio settings here.
     */
    tlg_cur_gain     = TLG_MAX_AUD_GAIN_DAC;    //  3;       
    tlg_cur_aud_mode = TLG_DAC;
    if (tlg_cur_aud_mode != TLG_DAC)
        TLG_SetAudioSampleRate(tlg_i2c_addr, TLG_AUD_RATE_26_367KHZ);
    TLG_SetAudioMode(tlg_i2c_addr, tlg_cur_aud_mode);
    TLG_SetAudioGain(tlg_i2c_addr, tlg_cur_aud_mode, tlg_cur_gain);
    /* 
     * BEGIN CUSTOM SECTION: Video Out Mode
     * Set up default video settings here
     * This example sets up 320x240 NTSC 30fps
     * Other options include:
     * TLG_SetVGA_601_PAL()
     * TLG_SetVGA_601_NTSC()
     * TLG_Set240x240_LCD_NTSC()
     * TLG_Set240x240_LCD_PAL()
     */

#if 1
    //TLG_Set240x240_LCD_PAL(tlg_i2c_addr);
    //TLG_SetVGA_601_NTSC(tlg_i2c_addr);
#elif 0
    TLG_SetExtHSync(tlg_i2c_addr, 147, 867, 526, 526, 526, 526);
    TLG_SetExtVSync(tlg_i2c_addr, 1, 18, 0, 0, 0, 0);
    TLG_Set601VideoOutClock(tlg_i2c_addr, TLG_NORMAL);
    TLG_SetHDecimate(tlg_i2c_addr, TLG_ON);
    TLG_SetVidOutType(tlg_i2c_addr, TLG_VID_LCD);
#else 
    TLG_SetExtHSync(tlg_i2c_addr, 147, 867, 526, 526, 526, 526);
    TLG_SetExtVSync(tlg_i2c_addr, 1, 18, 0, 0, 0, 0);
    TLG_Set601VideoOutClock(tlg_i2c_addr, TLG_NORMAL);
    TLG_SetHDecimate(tlg_i2c_addr, TLG_ON);
    TLG_SetVidOutType(tlg_i2c_addr, TLG_VID_LCD);
#endif

    TLG_SetChromaLumaOrder(tlg_i2c_addr, TLG_CHRLUM_NORMAL);
    //TLG_SetVSyncPolarity(tlg_i2c_addr, TLG_ACTIVE_HIGH); //high
    //TLG_SetHSyncPolarity(tlg_i2c_addr, TLG_ACTIVE_HIGH); //high
    TLG_SetVSyncPolarity(tlg_i2c_addr, TLG_ACTIVE_LOW);
    TLG_SetHSyncPolarity(tlg_i2c_addr, TLG_ACTIVE_LOW);

    TLG_SetHsyncLowPower(tlg_i2c_addr, TLG_ON);

    /*
     * BEGIN CUSTOM SECTION: Antenna Initialization. This is where you set up
     * the antenna behaviour and perform any GPIO (or other) manipulations to
     * to intialize any LNA/switching devices.
     */
    TLG_SetAntennaType(tlg_i2c_addr, TLG_ANTENNA_DEF);
	TLG_SetMobileVidEnhancement(tlg_i2c_addr, TLG_MVE_MANUAL, 50 );
	
    /* GPIO setup done here                                                 */

}

/*****************************************************************************
* TLGAPP_SetLnaGpio
* BEGIN CUSTOM SECTION: This procedure is called to perform LNA switching.
* It may be customized for a given build.
*****************************************************************************/

TLG1100DLL_API void TLGAPP_SetLnaGpio(uint32 hz)
{

    if (hz > TLG_UHF_CUTOFF_HZ)
    {
        if (tlg_cur_lna != TLG_LNA_UHF)
        {
            tlg_cur_lna = TLG_LNA_UHF;
            /** BEGIN CUSTOM SECTION: DO GPIO FOR UHF SWITCH HERE          **/
			TLG_SetGPIOEnable( tlg_i2c_addr, TLG_GPIO1 | TLG_GPIO2|TLG_GPIO3, TLG_GPIO1_SET|TLG_GPIO2_SET|TLG_GPIO3_SET);
			TLG_SetGPIOOutput( tlg_i2c_addr, TLG_GPIO1 | TLG_GPIO2|TLG_GPIO3, TLG_GPIO1_SET|TLG_GPIO2_CLR|TLG_GPIO3_CLR);
        }

    } else if (hz > TLG_VHF2_CUTOFF_HZ) {
        if (tlg_cur_lna != TLG_LNA_VHF2)
        {
            tlg_cur_lna = TLG_LNA_VHF2;
			TLG_SetGPIOEnable( tlg_i2c_addr, TLG_GPIO1 | TLG_GPIO2|TLG_GPIO3, TLG_GPIO1_SET|TLG_GPIO2_SET|TLG_GPIO3_SET);
			TLG_SetGPIOOutput( tlg_i2c_addr, TLG_GPIO1 | TLG_GPIO2|TLG_GPIO3, TLG_GPIO1_CLR|TLG_GPIO2_SET|TLG_GPIO3_CLR);
       /** BEGIN CUSTOM SECTION: DO GPIO FOR VHF2 SWITCH HERE         **/
        }

    } else {
        if (tlg_cur_lna != TLG_LNA_VHF1)
        {
            tlg_cur_lna = TLG_LNA_VHF1;
			TLG_SetGPIOEnable( tlg_i2c_addr, TLG_GPIO1 | TLG_GPIO2|TLG_GPIO3, TLG_GPIO1_SET|TLG_GPIO2_SET|TLG_GPIO3_SET);
			TLG_SetGPIOOutput( tlg_i2c_addr, TLG_GPIO1 | TLG_GPIO2|TLG_GPIO3, TLG_GPIO1_CLR|TLG_GPIO2_CLR|TLG_GPIO3_SET);
     
            /** BEGIN CUSTOM SECTION: DO GPIO FOR VHF1 SWITCH HERE         **/
       }
    }
}

/*****************************************************************************
* TLGAPP_ScanChanFound
* BEGIN CUSTOM SECTION: This procedure is called when TLGAPP_ScanChannels()
*                       has found a new channel.
* It may be customized for a given build.
*****************************************************************************/

TLG1100DLL_API void TLGAPP_ScanChanFound(int chn)
{
    /** BEGIN CUSTOM SECTION: Provide actions to be performed when a channel
     **                       has been found.                              **/
}

/*****************************************************************************
* TLG_ClearRegShadow
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_ClearRegShadow(uint32 base_addr)
{
#ifdef TLG_USE_SHADOW_REGISTERS
    int i;
    for (i=0; i < TLG_MAX_REG_ADDR; i++)
        _TLG_shadow_reg_use[i] = TLG_OFF;
#endif /* TLG_USE_SHADOW_REGISTERS */
    return TLG_ERR_SUCCESS;
}
        
/*****************************************************************************
* TLG_ReadReg
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_ReadReg(uint32 base_addr, uint32 reg_addr, uint16 *val)
{
    TLG_NULLPTR_CHECK(val);
    TLG_BOUNDS_CHECK(reg_addr, TLG_MAX_REG_ADDR);

#ifdef TLG_USE_SHADOW_REGISTERS
    if (_TLG_shadow_reg_use[reg_addr] == TLG_ON)
    {
        *val = _TLG_shadow_reg[reg_addr];
        TLG_REG_LOG((b, "READ(Cache) 0x%04x = 0x%04x\n", reg_addr, *val));
    } else
#endif /* TLG_USE_SHADOW_REGISTERS */
    TLG_ReadRegNS(base_addr, reg_addr, val);

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_ReadRegNS
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_ReadRegNS(uint32 base_addr, uint32 reg_addr, uint16 *val)
{
    TLG_NULLPTR_CHECK(val);
    TLG_BOUNDS_CHECK(reg_addr, TLG_MAX_REG_ADDR);

    TLGI2C_ReadReg(base_addr, reg_addr, val);

#ifdef TLG_USE_SHADOW_REGISTERS
    _TLG_shadow_reg[reg_addr]     = *val;
    _TLG_shadow_reg_use[reg_addr] = TLG_ON;
#endif /* TLG_USE_SHADOW_REGISTERS */

    TLG_REG_LOG((b, "READ  0x%04x = 0x%04x\n", reg_addr, *val));

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_WriteReg
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_WriteReg(uint32 base_addr, uint32 reg_addr, uint16 val)
{
    TLG_BOUNDS_CHECK(reg_addr, TLG_MAX_REG_ADDR);

    TLGI2C_WriteReg(base_addr, reg_addr, val);

#ifdef TLG_USE_SHADOW_REGISTERS
    _TLG_shadow_reg[reg_addr]     = val;
    _TLG_shadow_reg_use[reg_addr] = TLG_ON;
#endif /* TLG_USE_SHADOW_REGISTERS */

    TLG_REG_LOG((b, "WRITE 0x%04x = 0x%04x\n", reg_addr, val));

    return(TLG_ERR_SUCCESS);
}


/*****************************************************************************
* TLG_BurstWrite
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_BurstWrite(uint32 base_addr, uint32 start_addr, int len, uint16 *val)
{
    TLG_NULLPTR_CHECK(val);
    TLG_BOUNDS_CHECK(start_addr, TLG_MAX_REG_ADDR);
    TLG_BOUNDS_CHECK(start_addr+len-1, TLG_MAX_REG_ADDR);

    TLGI2C_WriteBurst(base_addr, start_addr, len, val);

#ifdef TLG_USE_SHADOW_REGISTERS
    {   
        int i;
        for (i = 0; i < len; i++)
        {
            _TLG_shadow_reg[start_addr+i]     = val[i];
            _TLG_shadow_reg_use[start_addr+i] = TLG_ON;
        }
    }
#endif /* TLG_USE_SHADOW_REGISTERS */
#ifdef TLG_DO_REG_LOGGING
    {   
        int i;
        for (i = 0; i < len; i++)
        {
            TLG_REG_LOG((b, "WRITE 0x%04x = 0x%04x\n", start_addr+i, val[i]));
        }
    }
#endif /* TLG_DO_REG_LOGGING */
            
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLG_BurstRead
*
* 
*
*
*****************************************************************************/
TLG1100DLL_API int TLG_BurstRead(uint32 base_addr, uint32 start_addr, int len, uint16 *val)
{
    TLG_NULLPTR_CHECK(val);
    TLG_BOUNDS_CHECK(start_addr, TLG_MAX_REG_ADDR);
    TLG_BOUNDS_CHECK(start_addr+len-1, TLG_MAX_REG_ADDR);

    TLGI2C_ReadBurst(base_addr, start_addr, len, val);

#ifdef TLG_USE_SHADOW_REGISTERS
    {   
        int i;
        for (i = 0; i < len; i++)
        {
            _TLG_shadow_reg[start_addr+i]     = val[i];
            _TLG_shadow_reg_use[start_addr+i] = TLG_ON;
        }
    }
#endif /* TLG_USE_SHADOW_REGISTERS */
#ifdef TLG_DO_REG_LOGGING
    {   
        int i;
        for (i = 0; i < len; i++)
        {
            TLG_REG_LOG((b, "READ  0x%04x = 0x%04x\n", start_addr+i, val[i]));
        }
    }
#endif /* TLG_DO_REG_LOGGING */

    return(TLG_ERR_SUCCESS);
}

void TLG_Delay(uint16 milliseconds)
{
    /** BEGIN CUSTOM SECTION: Perform millisecond delay                    **/
	LCD_Delayms(milliseconds);
}

void TLG_WriteLog(char *str)
{
    /** BEGIN CUSTOM SECTION: Write logging string                         **/
#if defined(NOKE_DEBUG)
	//noke_dbg_printf( str, 0);
#endif	
	//Test_UART_SendData("\n\r", 0 );
}
