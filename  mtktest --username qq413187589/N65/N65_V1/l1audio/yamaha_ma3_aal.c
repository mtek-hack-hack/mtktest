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
 * yamaha_ma3_aal.c
 *
 * Project:
 * --------
 *   KLM
 *
 * Description:
 * ------------
 *   L1 Audio Adaptation Layer Implementation for YAMAHA MA3 melody chip   
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


#if defined(EXT_AUDIO_CHIP)
#if defined(YAMAHA_MA3) 

#include "media.h"
#include "masound.h"
#include "madefs.h" 

extern UINT8 	machdep_WriteStatusFlagReg		( UINT8 data );
extern UINT8	machdep_ReadStatusFlagReg		( void );
extern void		machdep_WriteDataReg			( UINT8 data );
extern UINT8	machdep_ReadDataReg				( void );
extern void 	machdep_Wait					( UINT32 wait_time );
void MaDevDrv_TaskGenerateData( uint8 read_data );
void MaDevDrv_IntHandler( void );
int32	MaDevDrv_PowerManagement	(uint8 sw ); 

extern uint8 YamahaMa3_GetSpkVolume(void);  
extern void YamahaMa3_TurnOnClock(void);
extern void YamahaMa3_TurnOffClock(void);
extern void YamahaMa3_SetEnv(void);  

static uint8 Ma3Mode = 0x80;

static struct {
   uint8             sp_gpt;
   int32             func_id;
   int32             file_id;
   uint8             volume;              
} ma3;


static void ma3SpkSetVolume(void *data)
{
   uint8 volume = (uint8)(int32)data;
   ASSERT( MaSound_DeviceControl( MASMW_EQ_VOLUME, 0x00, 0, 0 ) >= 0 );
   ASSERT( MaSound_DeviceControl( MASMW_HP_VOLUME, 1, 0x00, 0x00 ) >= 0 );
   ASSERT( MaSound_DeviceControl( MASMW_SP_VOLUME, volume >> 3, 0, 0 ) >= 0 );           
}
    
void YamahaMa3_SpkAmpOn(void) 
{
   if(Ma3Mode & 0x81) 
      return; 
   
   if(Ma3Mode & 0x2)
      return;
   else      
      ExtAudChip_SetEvent((void*) 0x100);
      
   
}


void YamahaMa3_SpkAmpOff(void) 
{
   if(Ma3Mode & 0x81) 
      return;
   
   if(Ma3Mode & 0x2)    
      ExtAudChip_SetEvent((void*) 0x000);
}


AudChip_Status ExtAudChip_SetVolume(AudChipControl *audCtrl, uint8 volume)
{
   ma3.volume = volume >> 3;
   if(Ma3Mode & 0x1)
      ASSERT( MaSound_DeviceControl( MASMW_SP_VOLUME, ma3.volume, 0, 0 ) >= 0 );
      
   ExtAudChip_ReturnSuccess;   
}           

static void ma3Handler( void *data )     /* This function works in L1Audio Task */
{
   uint16 event_data = (uint16)(int32)data;
   uint16 status = event_data >> 8;
   uint8 spk_volume;
   
   if(status == 1)  // Turn On Ma3Spk 
   {   
      Ma3Mode |= 0x2;   
      machdep_WriteStatusFlagReg(MA_POWER_MANAGEMENT_ANALOG_REG);
      machdep_WriteDataReg(MA_PLLPD | MA_AP4R | MA_AP4L | MA_AP3 | MA_AP2 );				
		machdep_Wait( 10 * 1000 );/* wait 10us */
      machdep_WriteDataReg(MA_PLLPD | MA_AP4R | MA_AP4L | MA_AP3 );	
      spk_volume = YamahaMa3_GetSpkVolume();    
      GPTI_StartItem(ma3.sp_gpt, 6, ma3SpkSetVolume, (void*)spk_volume);             
   }
   else if(status == 0) // Turn Off Ma3Spk    
   {
      Ma3Mode &= ~0x2;
      GPTI_StopItem(ma3.sp_gpt);
      ASSERT( MaSound_DeviceControl( MASMW_SP_VOLUME, 0x00, 0, 0 ) >= 0 );      
      machdep_WriteStatusFlagReg(MA_POWER_MANAGEMENT_ANALOG_REG);
      machdep_WriteDataReg(MA_PLLPD | MA_AP4R | MA_AP4L | MA_AP3 | MA_AP2 | MA_AP1 | MA_AP0);
   }
   else if(status == 2) 
      MaDevDrv_TaskGenerateData( (uint8)(event_data & 0xFF) );
}

void YamahaMa3_SetEvent( uint8 read_data )
{
   ExtAudChip_SetEvent((void*) (0x200+read_data));
}

void YamahaMa3_InterruptHandler( void )
{
   MaDevDrv_IntHandler();
}


void ExtAudChip_Init()
{
   ExtAudChip_SetEventHandler(ma3Handler);
   YamahaMa3_SetEnv();   
   YamahaMa3_TurnOnClock();   
   ASSERT( MaSound_Initialize() == 0 );
   ma3.volume = 0x1F;
   YamahaMa3_TurnOffClock();
   GPTI_GetHandle(&ma3.sp_gpt);
   Ma3Mode &= ~0x80;
}   
   
static void YamahaMa3_Stop( void )
{   
   MaSound_Stop( ma3.func_id, ma3.file_id, NULL );
   MaSound_Close( ma3.func_id, ma3.file_id, NULL );
   MaSound_Unload( ma3.func_id, ma3.file_id, NULL );
   MaSound_Delete( ma3.func_id );
   ASSERT( MaSound_DeviceControl( MASMW_EQ_VOLUME, 0x00, 0, 0 ) >= 0 );
   ASSERT( MaSound_DeviceControl( MASMW_HP_VOLUME, 1, 0x00, 0x00 ) >= 0 );
   ASSERT( MaSound_DeviceControl( MASMW_SP_VOLUME, 0x00, 0, 0 ) >= 0 );
   MaDevDrv_PowerManagement(2);

   YamahaMa3_TurnOffClock();  
               
   Ma3Mode &= ~0x01;
}   


static signed long ma3Callback(unsigned char id)
{
   if( id == 126 )
      ExtAudChip_NotifyRepeated();
   else if( id == 127 )
   {
      YamahaMa3_Stop();
      ExtAudChip_NotifyEOF();
   }
   return 0;
}



AudChip_Status ExtAudChip_Play(AudChipControl *audCtrl)
{
   kal_bool smfFail, smafFail;
   
   Ma3Mode |= 0x1;   
   smfFail = KAL_FALSE;
   smafFail = KAL_FALSE;
         
   YamahaMa3_TurnOnClock();  
   
   MaDevDrv_PowerManagement(3);
   
   machdep_WriteStatusFlagReg(MA_POWER_MANAGEMENT_ANALOG_REG);
   machdep_WriteDataReg(MA_AP4R | MA_AP4L);
   

   if( (ma3.func_id = MaSound_Create( MASMW_CNVID_MID )) < 0 )  
   {     
      smfFail = KAL_TRUE;
   }   
   
   if(!smfFail) 
   {
      if( (ma3.file_id = MaSound_Load( ma3.func_id, (uint8 *)audCtrl->melody_data, audCtrl->data_length, 0, ma3Callback, NULL )) < 0 )
      {
         MaSound_Delete( ma3.func_id );
         smfFail = KAL_TRUE;
      }       
   }    
      
   if(smfFail) 
   {
      if( (ma3.func_id = MaSound_Create( MASMW_CNVID_MMF )) < 0 )
      {     
         smafFail = KAL_TRUE;         
      }   
      
      if(!smafFail) 
      {
         if( (ma3.file_id = MaSound_Load( ma3.func_id, (uint8 *)audCtrl->melody_data, audCtrl->data_length, 0, ma3Callback, NULL )) < 0 )
         {
            MaSound_Delete( ma3.func_id );
            smafFail = KAL_TRUE;
         }           
      }
   } 
   
   if(smfFail && smafFail)
   {
      ExtAudChip_NotifyError();
      ExtAudChip_ReturnFail;
   }
   
   if( MaSound_Open( ma3.func_id, ma3.file_id, 0, NULL ) < 0 )
   {
      
      MaSound_Unload( ma3.func_id, ma3.file_id, NULL );
      MaSound_Delete( ma3.func_id );
      ExtAudChip_NotifyError();
      ExtAudChip_ReturnFail;
   }
   if( MaSound_Standby( ma3.func_id, ma3.file_id, NULL ) < 0 )
   {
      MaSound_Close( ma3.func_id, ma3.file_id, NULL );
      MaSound_Unload( ma3.func_id, ma3.file_id, NULL );
      MaSound_Delete( ma3.func_id );
      ExtAudChip_NotifyError();
      ExtAudChip_ReturnFail;
   }
   MaSound_Start( ma3.func_id, ma3.file_id, audCtrl->repeat_times, NULL );
   ASSERT( MaSound_DeviceControl( MASMW_EQ_VOLUME, 0x1F, 0, 0 ) >= 0 );
   ASSERT( MaSound_DeviceControl( MASMW_SP_VOLUME, ma3.volume , 0, 0 ) >= 0 );
   ExtAudChip_ReturnSuccess;   
}

AudChip_Status ExtAudChip_Stop( AudChipControl *audCtrl )
{
   YamahaMa3_Stop();
   ExtAudChip_NotifyStop();
   ExtAudChip_ReturnSuccess;
}    

AudChip_Status ExtAudChip_Pause( AudChipControl *audCtrl )
{ 
   ExtAudChip_ReturnSuccess;
}

AudChip_Status ExtAudChip_Resume( AudChipControl *audCtrl )
{
   ExtAudChip_ReturnSuccess;
}   

AudChip_Status ExtAudChip_Control( AudChipControl *audCtrl )
{
   ExtAudChip_ReturnSuccess;
}

void ExtAudChip_Reset( void )
{
   YamahaMa3_Stop();
}   
      

#endif 
#else
char dummy_yamaha_ma3_aal_c;    /* define a dummy variable to avoid warning message */
#endif 


