/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * fm_radio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      FM Radio Driver
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "am.h"
#include "afe.h"

void  ktLock( void );
void  ktUnlock( void );
void  FMDrv_PowerOnReset(void);
void  FMDrv_PowerOffProc(void);
uint8 FMDrv_ValidStop(int16 freq, int8 signalvl, bool is_step_up);
void  FMDrv_SetFreq( int16 curf );
uint8 FMDrv_GetSigLvl( int16 curf );
void  FMDrv_Mute(uint8 mute);
void  FMDrv_ChipInit(void);
bool  FMDrv_IsChipValid(void);
void  FMDrv_SetVolumeLevel(uint8 level);
void  FMDrv_EvaluateRSSIThreshold(void);
void  FMDrv_radio_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
uint16 FMDrv_GetIF( int16 curf);
uint16 FMDrv_ReadByte(uint8 addr);
bool FMDrv_WriteByte(uint8 addr, uint16 data);
void FMDrv_SoftMuteOnOff(bool On_Off);
void FMDrv_SoftMuteStage(uint8 stage);
void FMDrv_StereoBlendStage(uint8 stage);
uint8 FMDrv_GetChipID(void);
uint8 FMDrv_Get_H_L_side(kal_int16 curf);
uint8 FMDrv_Get_stereo_mono(void);


#if defined(ANALOG_TV_SUPPORT)
extern void  TLG1100_FM_PowerOn(void);
extern kal_bool Is_TV_Chip_Work_On(void);
extern kal_bool mmi_get_analog_tv_current_state(void);
int TLG_SetAudioEnable(uint32 base_addr, uint16 val);
#endif

//#if (defined(FM_RADIO_ENABLE))

static bool isFmActive;
static bool isSpeakerOn = false;

#if defined(HORSERACE_SUPPORT)
extern kal_bool  tv_fm_camera_is_power_on;
#endif /* HORSERACE_SUPPORT */

void FMR_PowerOn()
{
#if (defined(FM_RADIO_ENABLE))
	isFmActive = true;
	ktLock();

#if defined(FM_RADIO_WITH_TV)

#if defined(NOKE_DEBUG)
	noke_dbg_printf("\rFMR_PowerOn ... \n");
#endif

	TLG1100_FM_PowerOn();
#else
	FMDrv_PowerOnReset();

#if defined(HORSERACE_SUPPORT)
	tv_fm_camera_is_power_on = KAL_TRUE;
#endif /* HORSERACE_SUPPORT */

#endif
	/// If MT6205B or MT6208, FM path is opened now.
	/// Otherwise, AFE will be turned on after the first time the frequency is set.
#endif
}

void FMR_PowerOff()
{
#if (defined(FM_RADIO_ENABLE))
	isFmActive = false;
#if !defined(MT6205B)
	AFE_TurnOffSpeaker(L1SP_FM_RADIO);
	isSpeakerOn = false;
#endif
	/// If MT6205B or MT6208, FM path is closed in FMDrv_PowerOffProc(...).


#if defined(FM_RADIO_WITH_TV)
	if((mmi_get_analog_tv_current_state()==true)&&(Is_TV_Chip_Work_On()==true)) //pjqadd  070120
	{
		/*In this case,we need not to power off tv,switch between fm and tv directly*/
	}
	else
	{
		TLG1100_PowerOff();  
	}
#else
	FMDrv_PowerOffProc();

#if defined(HORSERACE_SUPPORT)
	tv_fm_camera_is_power_on = KAL_FALSE;
#endif /* HORSERACE_SUPPORT */

#endif
	ktUnlock();
#endif
}

 /* signal level range is 0 ~ 15 , 5767 has 16 levels ADC */
kal_uint8 FMR_ValidStop(int16 freq, int8 signalvl, bool is_step_up)
{
#if (defined(FM_RADIO_ENABLE))
 #if defined(FM_RADIO_WITH_TV)
 int16 chan;
 chan=freq;//-875+1;
 return TLGAPP_SetChannel(chan);
 #else
   return FMDrv_ValidStop(freq, signalvl, is_step_up);
#endif
#endif
}

void FMR_SetFreq( int16 curf ) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
#if (defined(FM_RADIO_ENABLE))
 #if defined(FM_RADIO_WITH_TV)
 int16  chan;
  chan=curf;//-875+1;
  TLGAPP_SetChannel(chan);
 #else
   FMDrv_SetFreq( curf );
 #endif
#if !defined(MT6205B)
   if (false == isSpeakerOn) {
      AFE_TurnOnSpeaker(L1SP_FM_RADIO);
      isSpeakerOn = true;
   }
#endif
#endif
}
#if defined(FM_RADIO_WITH_TV)
kal_uint16 FMR_GetSignalLevel( kal_uint16 curf )
#else
kal_uint8  FMR_GetSignalLevel( kal_uint16 curf )//UNI@bw_0719_BEIW1
#endif
{
#if (defined(FM_RADIO_ENABLE))

 #if defined(FM_RADIO_WITH_TV)
  #if 1
	TLGAPP_SetChannel(curf);
	return  TLG_GetFMLevel() ; 
  #else //hongzhe.liu
    return  TLG_GetFMLevel() ; 
  #endif  //#if 1
 #else
   return FMDrv_GetSigLvl(curf);
 #endif   //FM_RADIO_WITH_TV

#else
	return 0;
#endif   //FM_RADIO_ENABLE
}

void FMR_Mute( uint8 mute )
{
#if (defined(FM_RADIO_ENABLE))
  #if defined(FM_RADIO_WITH_TV)
  TLG_SetAudioEnable(0x2c,mute);  
  #else
   FMDrv_Mute(mute);
 #endif

   if (mute) {
#if !defined(MT6205B)
      AFE_TurnOffSpeaker(L1SP_FM_RADIO);
      isSpeakerOn = false;
#endif
       #if defined(FM_RADIO_WITH_TV)
    TLG_SetAudioEnable(0x2c,0);  
	#else  
      FMDrv_Mute(1);
       #endif
   } else {

   #if defined(FM_RADIO_WITH_TV)
   TLG_SetAudioEnable(0x2c,1);  
    #else	
      FMDrv_Mute(0);
  #endif
#if !defined(MT6205B)
      AFE_TurnOnSpeaker(L1SP_FM_RADIO);
      isSpeakerOn = true;
#endif
   }
#endif
}

void FMR_Init(uint16 aud_id)
{
#if (defined(FM_RADIO_ENABLE))

#if !defined(FM_RADIO_WITH_TV)
   FMDrv_ChipInit();
#endif

#endif
}
/*------------------------------------------------------------------------------*/

void FMR_SetOutputDevice( uint8 device )
{
#if !defined(MT6205B)
   AFE_SetOutputDevice( L1SP_FM_RADIO, device );
#else
   /// The output path of FM on MT6205 platform is fixed.
#endif
}

void FMR_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if (defined(FM_RADIO_ENABLE))
#if !defined(MT6205B)
   AFE_SetOutputVolume( L1SP_FM_RADIO, volume1, digital_gain_index );
#else
   FMDrv_SetVolumeLevel(volume1/20);
#endif
#endif
}

/*
  FMR_IsChipValid could be called to confirm if FM chip dose exist.
  Return ture if FM chip is valid, return false otherwise.
*/

bool FMR_IsChipValid(void)
{
#if (defined(FM_RADIO_ENABLE))
  #if defined(FM_RADIO_WITH_TV)
	return true;
  #else
	return FMDrv_IsChipValid();
  #endif

#else
	return 0;
#endif
}

bool FMR_IsActive(void)
{
   return isFmActive;
}

void FMR_EvaluateRSSIThreshold(void)
{
#if defined(MT6189A1)
    FMDrv_EvaluateRSSIThreshold();
#endif
}

void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value)
{
#if defined(MT6189A1) || defined(MT6188A1)
    FMDrv_radio_item_info(group_idx, item_idx, item_value);
#endif
}

kal_uint16 FMR_GetIFCount(kal_int16 curf)
{
#if defined(MT6189A1) || defined(MT6188A1)
    return FMDrv_GetIF(curf);
#else
    return 0;
#endif
}

kal_uint16 FMR_ReadByte(kal_uint8 addr)
{
#if defined(MT6189A1) || defined(MT6188A1)
    return FMDrv_ReadByte(addr);
#else
    return 0;
#endif
}

void FMR_WriteByte(kal_uint8 addr, kal_uint16 data)
{
#if defined(MT6189A1) || defined(MT6188A1)
     FMDrv_WriteByte(addr, data);
#endif
}

void FMR_SoftMuteOnOff(kal_uint8 On_Off)	//On:1, Off:0
{
#if defined(MT6188A1)
    FMDrv_SoftMuteOnOff(On_Off);
#endif
}

void FMR_SoftMuteStage(kal_uint8 stage)	//stage1~3
{
#if defined(MT6188A1)
    FMDrv_SoftMuteStage(stage);
#endif
}

void FMR_StereoBlendStage(kal_uint8 stage)	//stage1~3
{
#if defined(MT6188A1)
    FMDrv_StereoBlendStage(stage);
#endif
}

kal_uint8 FMR_GetChipID(void)
{
#if defined(MT6189A1) || defined(MT6188A1)
	return FMDrv_GetChipID();
#else
    return 0;
#endif
}

kal_uint8 FMR_Get_H_L_side(kal_int16 curf) /* input value: 875 - 1080 ( 87.5 MHz - 108.0 MHz)*/
{
#if defined(MT6189A1) || defined(MT6188A1)
	return FMDrv_Get_H_L_side(curf);//1:H side, 0:L side
#else 
    return 0;
#endif
}

kal_uint8 FMR_Get_stereo_mono(void)
{
#if defined(MT6189A1) || defined(MT6188A1)
	return FMDrv_Get_stereo_mono();//1:stereo, 0:mono
#else
    return 0;
#endif
}

kal_uint8 FMR_CheckOption(void)
{
#if (defined(FM_RADIO_ENABLE))
	return 0;
#else
	return 1;
#endif	
}
//#endif // defined(FM_RADIO_ENABLE)


#if defined(ANALOG_TV_SUPPORT)

void analog_tv_SetOutputDevice( uint8 device )
{

  AFE_SetOutputDevice( L1SP_FM_RADIO, device );

}
void analog_tv_Mute( uint8 mute )
{
  
   if (mute) 
   {
     //analog tv mute function  enable
     TLG_SetAudioEnable(0x2c,0/*TLG_MUTE*/); 
      AFE_TurnOffSpeaker(L1SP_FM_RADIO);
      //isSpeakerOn = false;
   }
   else 
   {
     //analog tv mute function disable
     TLG_SetAudioEnable(0x2c,1/*TLG_ENABLE*/); 
     AFE_TurnOnSpeaker(L1SP_FM_RADIO);
      //isSpeakerOn = true;
    }
}

#endif