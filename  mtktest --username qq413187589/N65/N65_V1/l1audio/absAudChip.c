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
 * absAudChip.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1 Audio Adaptation Layer abtract architecture 
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

#if defined(EXT_AUDIO_CHIP)

#include "media.h" 

static struct {
   mediaControl      *ctrl;
   uint16            aud_id;
   uint8             volume;              
} extAudChip;

static AudChipControl audCtrl;

void AbsExtAudChip_Init( uint16 aud_id ) 
{
   extAudChip.aud_id = aud_id;
   L1Audio_SetEventHandler(extAudChip.aud_id , NULL);
   extAudChip.volume = 255;
   ExtAudChip_Init();
}    
      
Media_Status AbsExtAudChip_Play( mediaControl *ctrl )
{  
   AudChip_Status retval;
   extAudChip.ctrl = ctrl;
   audCtrl.format = ctrl -> format;
   if(audCtrl.format == MEDIA_FORMAT_SMF || audCtrl.format == MEDIA_FORMAT_MMF)
   {
      audCtrl.melody_data = ctrl->param.smf.smffile;
      audCtrl.data_length = ctrl->param.smf.filesize;
      audCtrl.repeat_times = ctrl->param.smf.repeats; 
   }
   else if(audCtrl.format == MEDIA_FORMAT_IMELODY)
   {
      audCtrl.melody_data = ctrl->param.imy.imyfile;
      audCtrl.data_length = ctrl->param.imy.filesize;
      audCtrl.repeat_times = ctrl->param.imy.repeats; 
   }   
   retval = ExtAudChip_Play( &audCtrl );
   return retval;
}

Media_Status AbsExtAudChip_Stop( mediaControl *ctrl )
{  
   AudChip_Status retval;   
   retval = ExtAudChip_Stop( &audCtrl );
   return retval;
}

Media_Status AbsExtAudChip_Pause( mediaControl *ctrl )
{  
   AudChip_Status retval;   
   retval = ExtAudChip_Pause( &audCtrl );
   return retval;
}

Media_Status AbsExtAudChip_Resume( mediaControl *ctrl )
{  
   AudChip_Status retval;   
   retval = ExtAudChip_Resume( &audCtrl );
   return retval;
}

Media_Status AbsExtAudChip_SetVolume( mediaControl *ctrl , uint8 volume )
{  
   AudChip_Status retval;   
   extAudChip.volume = volume;
   retval = ExtAudChip_SetVolume( &audCtrl , volume );
   return retval;
}


void ExtAudChip_SetEventHandler(void(*eventHandler)(void *param))
{
   L1Audio_SetEventHandler(extAudChip.aud_id , eventHandler);
}

void ExtAudChip_SetEvent(void *param)
{
   L1Audio_LSetEvent(extAudChip.aud_id , param);
}   


void ExtAudChip_NotifyError( void )
{
   mediaHandler( (void*)MEDIA_ERROR );
}

void ExtAudChip_NotifyStop( void )
{
/*   mediaHandler( (void*)MEDIA_TERMINATED );   Removed by Phil */
}

void ExtAudChip_NotifyEOF( void )
{
   mediaHandler((void*)MEDIA_END );
}

void ExtAudChip_NotifyRepeated( void )
{
   mediaHandler( (void*)MEDIA_REPEATED );
}


#else
char dummy_absaudchip_c;    /* define a dummy variable to avoid warning message */
#endif 

