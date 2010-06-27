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
 * rohm_8788_aal.c
 *
 * Project:
 * --------
 *   CHICAGO
 *
 * Description:
 * ------------
 *   L1 Audio Adaptation Layer Implementation for ROHM BU8788KN  melody chip   
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(EXT_AUDIO_CHIP) && defined(ROHM_8788)

#include "fmp.h" 
#include "eint.h" 
#include "rhm_register.h"
#include "format_id.h"
#include "media.h"
#include "afe.h"

extern void GPIO_Melody_Set(kal_uint8 pin,kal_uint8 on);
extern void Rohm8788_TurnOnClock(void);
extern void Rohm8788_TurnOffClock(void);
extern void Rohm8788_SetEnv(void);
extern void Rohm8788_MaskINT(void);
extern void Rohm8788_UnMaskINT(void);  


#define DEFAULT_VOLUME 0x6F

static uint8 rohm_volume;
static fmp_work_t        fmp_work;





/* ROHM Interrupt Process */

static void rohm8788_Stop(void);

static void fmp_callback(fmp_cbcmd_t *cmd)
{
   if (cmd->status == FMP_CBSTATUS_TAIL) 
   {
	   rohm8788_Stop();
	   ExtAudChip_NotifyEOF();
	}    
}	


void Rohm8788_InterruptHandler( void )
{
  Rohm8788_MaskINT();
  ExtAudChip_SetEvent((void*) 0);	  	
}  	


void rohm8788Handler(void *data)
{    		    		
    fmp_cmd_proc(&fmp_work, fmp_callback);   
    Rohm8788_UnMaskINT();
}


/* L1 Audio Adapatation Layer for ROHM_8788 */ 



void ExtAudChip_Init()
{
   ExtAudChip_SetEventHandler(rohm8788Handler);
   
   Rohm8788_SetEnv();
   
   rohm_volume = DEFAULT_VOLUME;
   
   RegWrite(REG_COMMON_SETUP, 0x0F);   // mute sound  
   RegWrite(REG_MIDI_FIFO_STATUS, 0x00); // stop MIDI sequencer  	
   RegWrite(REG_ADPCM_FIFO_STATUS, 0x04); // stop ADPCM sequencer 
   RegWrite(REG_SEQU_CTRL, 0x40); // enter standby mode     
}   


AudChip_Status ExtAudChip_SetVolume(AudChipControl *audCtrl, uint8 volume)
{
   rohm_volume = volume;
   RegWrite(REG_MIDI_WAVEVOL, rohm_volume);
   
   ExtAudChip_ReturnSuccess;   
}   

AudChip_Status ExtAudChip_Play(AudChipControl *audCtrl)
{
   uint16 repeats;
   
   Rohm8788_TurnOnClock();
   
   AFE_TurnOnExtAmplifier();

   
   RegWrite(REG_SEQU_CTRL, 0x00); // release standby mode  
   kal_sleep_task(3);
   RegWrite(REG_SEQU_CTRL, 0x80); // enter normal mode 
 
   if(fmp_open(&fmp_work, NULL)!=0)
   {
  	   ExtAudChip_NotifyError();
      ExtAudChip_ReturnFail; 
   }   
  
   switch(audCtrl->format){ 
  	case MEDIA_FORMAT_SMF:	  		
   	if(fmp_cmd_setdata(&fmp_work, (uint8 *)audCtrl->melody_data, audCtrl->data_length, FMTID_SMF)!=0)
   	{
  			ExtAudChip_NotifyError();
         ExtAudChip_ReturnFail; 
  		}	
  		if(audCtrl->repeat_times == 0) 
  			repeats = 1; 
  		else 
  			repeats = 0;	   
  		break;
  	case MEDIA_FORMAT_IMELODY: 
  		if(fmp_cmd_setdata(&fmp_work, (uint8 *)audCtrl->melody_data, audCtrl->data_length, FMTID_IMELODY)!=0)	
  		{	
  			ExtAudChip_NotifyError();
         ExtAudChip_ReturnFail; 
  		}	
  		if(audCtrl->repeat_times == 0) 
  			repeats = 1; 
  		else 
  			repeats = 0;	   	 	
		break;
   } 			
   		
   if(fmp_cmd_play(&fmp_work, repeats)!=0)
   {
   	ExtAudChip_NotifyError();
      ExtAudChip_ReturnFail;
   }	
   RegWrite(REG_MIDI_WAVEVOL, rohm_volume);
   ExtAudChip_ReturnSuccess; 
}
  


static void rohm8788_Stop( void )
{   
   fmp_close(&fmp_work);
   RegWrite(REG_COMMON_SETUP, 0x0F);   // mute sound   
   RegWrite(REG_MIDI_FIFO_STATUS, 0x00); // stop MIDI sequencer  	
   RegWrite(REG_ADPCM_FIFO_STATUS, 0x04); // stop ADPCM sequencer 
   RegWrite(REG_SEQU_CTRL, 0x40); // enter standby mode 

   AFE_TurnOffExtAmplifier();
   Rohm8788_TurnOffClock();
}


AudChip_Status ExtAudChip_Stop( AudChipControl *audCtrl )
{
   rohm8788_Stop();
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
   rohm8788_Stop();
}

#else
char dummy_rohm_8788_c;    /* define a dummy variable to avoid warning message */
#endif 


