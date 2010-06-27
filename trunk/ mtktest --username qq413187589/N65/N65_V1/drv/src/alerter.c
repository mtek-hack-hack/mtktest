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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    alerter.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the alerter driver(buzzer).
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "alerter_hw.h"
#include "alerter_sw.h"
#include "melody.h"
#include "gpt_sw.h"
#include "drvpdn.h"
#include "custom_hw_default.h"

static kal_uint8  ALTER_LEVEL_SAVE;
#if !defined(__FUE__)
   #if !defined(DRV_ALERTER_NOT_EXIST)
ALterNoteStruct ALterNote;
static kal_uint8 AlerVolume=0xff;
   #endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
extern const kal_uint16 MusicalNoteTable_C1[];
extern const kal_uint16 MusicalNoteTable_C2[];
extern const kal_uint16 MusicalNoteTable_Thres[];
void Alter_PlayOnNotes(void *parameter);
void Alter_PlayOffNotes(void *parameter);
void StopAlterNotes(void);

/*
* FUNCTION                                                            
*  ALERTER_PWROPEN
*
* DESCRIPTION                                                           
*     This function is to open or close the alerter power
*
* CALLS  
*  It is called to open or close the alerter power
*
* PARAMETERS
*  ENABLE : KAL_TRUE,power on.
*      KAL_FALSE,power off.
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void ALERTER_PWROPEN(kal_bool ENABLE)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   if (ENABLE == KAL_TRUE)
   {
      DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);   //Open ALERTER power
   }
   else
   {
      DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
   }
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}
#endif /*!defined(__FUE__)*/

/*
* FUNCTION                                                            
*  ALERTER_Output
*
* DESCRIPTION                                                           
*     This function is to set Alerter output is pdm or pwm
*
* CALLS  
*  It is called to set Alerter output
*
* PARAMETERS
*  outtype : pwm, pdm
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void ALERTER_Output(kal_uint8 outtype)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   if (outtype == pdm)
   {
      DRV_Reg(ALERTER_CTRL) |= ALERTER_CTRL_PDMOUTPUT;
   }
   else
   {
      DRV_Reg(ALERTER_CTRL) &= ~ALERTER_CTRL_PDMOUTPUT;
   }
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

/*
* FUNCTION                                                            
*  ALERTER_Config
*
* DESCRIPTION                                                           
*     Alerter initial function
*
* CALLS  
*  It is called before access the alerter.
*
* PARAMETERS
*  mode: m1,m2,m3
*  Clock:   c13_1MHZ,
*     c13_2MHZ,
*     c13_4MHZ,
*     c13_8MHZ 
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void ALERTER_Config(ALMode mode, ALClock Clock)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   kal_uint16 tmp = DRV_Reg(ALERTER_CTRL);
   switch(Clock)
   {
      case c13_1MHZ:
         tmp |= ALERTER_CTRL_CLK_1;
         break;
      case c13_2MHZ:
         tmp |= ALERTER_CTRL_CLK_2;
         break;
      case c13_4MHZ:
         tmp |= ALERTER_CTRL_CLK_4;
         break;
      case c13_8MHZ:
         tmp |= ALERTER_CTRL_CLK_8;
         break;
      default:
         break;
   }
   
   switch(mode)
   {
      case m1:
         tmp &= ~ALERTER_CTRL_MODEMASK;
         tmp |= ALERTER_CTRL_MODE1;
         break;
      case m2:
         tmp &= ~ALERTER_CTRL_MODEMASK;
         tmp |= ALERTER_CTRL_MODE2;
         break;
      case m3:
         tmp &= ~ALERTER_CTRL_MODEMASK;
         tmp |= ALERTER_CTRL_MODE3;
         break;
      default:
         break;
   }
   DRV_WriteReg(ALERTER_CTRL,tmp);
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

#if !defined(__FUE__)
/*
* FUNCTION                                                            
*  Alter_PlayNotes
*
* DESCRIPTION                                                           
*     This function is to play the notes from alerter
*
* CALLS  
*
* PARAMETERS
*  note: note value
*  volume: note volume, 0~7
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
/*volume = 0-7*/
void Alter_PlayNotes(kal_uint8 note, kal_uint8 volume)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   kal_uint16 level;

   if (volume > 7)
      volume = 7;
      
   level = (0x0001 << volume);

   if (note > (kal_uint8)B7)
   {
      DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
   }
   else
   {
      ALERTER_setCNT1(MusicalNoteTable_C1[note]);
      if (volume == 0)
      {
         ALERTER_setTHRES(1); /*Mute*/
      }
      else
      {
         ALERTER_setTHRES((MusicalNoteTable_Thres[note]*level));
      }
      ALERTER_setCNT2(MusicalNoteTable_C2[note]);
      DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
   }
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

/*
* FUNCTION                                                            
*  Alter_PlayOnNotes
*
* DESCRIPTION                                                           
*     This function is to play the note during ON period.
*     This function is a callback function from GPT module.
*
* CALLS  
*
* PARAMETERS
*  *parameter: GPT parameter
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Alter_PlayOnNotes(void *parameter)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   kal_bool result;
   kal_uint8 volume;
   ALterNoteStruct *ALterNoteData=(ALterNoteStruct *)parameter;
   
   GPTI_StopItem(ALterNoteData->handle);
   
   if (ALterNoteData->stop)
   {
      StopAlterNotes();
      ALterNoteData->EndofAlterPlay();
      return;
   }
   
   result = ALterNoteData->GetNotesCallbac(&ALterNoteData->NotesData);   
   
   if (result == 0)  /* The latest one */
   {
      ALterNoteData->stop = KAL_TRUE;
   }
   
   if (AlerVolume == 0xff) /*May be changed if each tone each volume*/
   {
         volume = ALterNoteData->NotesData.volume;
   }
   else
   {
         volume = AlerVolume;
   }

   Alter_PlayNotes(ALterNoteData->NotesData.pitch,
                   volume);
                   
   if (ALterNoteData->NotesData.off_duration != 0)
   {
      GPTI_StartItem(ALterNoteData->handle,
               (ALterNoteData->NotesData.on_duration/gptimer_interval),
               Alter_PlayOffNotes, &ALterNote);
   }
   else
   {
      GPTI_StartItem(ALterNoteData->handle,
         (ALterNoteData->NotesData.on_duration/gptimer_interval),
         Alter_PlayOnNotes, &ALterNote);
   }
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

/*
* FUNCTION                                                            
*  Alter_PlayOffNotes
*
* DESCRIPTION                                                           
*     This function is to play the note during OFF period.
*     This function is a callback function from GPT module.
*
* CALLS  
*
* PARAMETERS
*  *parameter: GPT parameter
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Alter_PlayOffNotes(void *parameter)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   ALterNoteStruct *ALterNoteData=(ALterNoteStruct *)parameter;

   GPTI_StopItem(ALterNoteData->handle);
   
   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
   GPTI_StartItem(ALterNoteData->handle,
         (ALterNoteData->NotesData.off_duration/gptimer_interval),
         Alter_PlayOnNotes,&ALterNote);
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

/*
* FUNCTION                                                            
*  PlayAlterNotes
*
* DESCRIPTION                                                           
*     This function is the main function to play the audio from buzzer.
*
* CALLS  
*
* PARAMETERS
*  GetNotecallbac: callback function, when we need note information
*  endofAlter: callback function, when the audio is end.
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void PlayAlterNotes(kal_bool (*GetNotecallbac)(BuzNoteStruct *Buz), void (*endofAlter)(void))
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   GPTI_StopItem(ALterNote.handle);
   ALterNote.stop = KAL_FALSE;
   ALterNote.GetNotesCallbac = GetNotecallbac;
   ALterNote.EndofAlterPlay = endofAlter;
   
   #ifdef MTK_SLEEP_ENABLE
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
   #endif
   GPTI_StartItem(ALterNote.handle,1,Alter_PlayOnNotes,&ALterNote);
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

/*
* FUNCTION                                                            
*  StopAlterNotes
*
* DESCRIPTION                                                           
*     This function is stop the audio from buzzer.
*
* CALLS  
*
* PARAMETERS
*  None
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void StopAlterNotes(void)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   GPTI_StopItem(ALterNote.handle);
   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

/*
* FUNCTION                                                            
*  SetBuzVolume
*
* DESCRIPTION                                                           
*     This function is stop the audio from buzzer.
*
* CALLS  
*
* PARAMETERS
*  volumn: the Buzzer volume
*  
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void SetBuzVolume(kal_uint8 volumn)
{
#if !defined(DRV_ALERTER_NOT_EXIST)   
   volumn >>= 5;
   AlerVolume = volumn;
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}
#endif /*!defined(__FUE__)*/

/*The below apis are used only when in PWM mode*/
/*duty=50 ==> 50%*/
void Alter_Configure(kal_uint32 freq, kal_uint8 duty)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
   kal_uint32 clock;
   kal_uint32 tmp;
   kal_uint16 clkdiv;
   kal_uint16 reg;
   
   
 
    
   ASSERT(duty <= 100);
   reg = DRV_Reg(ALERTER_CTRL);

   ASSERT((reg&0x0018) == 0x0010);
   clkdiv = (1 << (reg & 0x0003));
   
   if (reg & 0x0004)
      clock = 32000;
   else
      clock = 13000000;
   
   clock = clock/clkdiv;
   if(0==freq)
      tmp = clock/(freq+1);
   else 
      tmp = clock/(freq);    
      
   tmp--;
   DRV_WriteReg(ALERTER_CNT1,(kal_uint16)tmp);
   tmp = ((tmp+1)*duty)/100;
   DRV_WriteReg(ALERTER_THRES,(kal_uint16)tmp);
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

void Alter_Start(void)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
#if !defined(__FUE__)
   DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
#else
   DRV_WriteReg(DRVPDN_CON1+0x20,(kal_uint16)DRVPDN_CON1_ALTER);
#endif
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

void Alter_Stop(void)
{
#if !defined(DRV_ALERTER_NOT_EXIST)
#if !defined(__FUE__)
   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_ALTER,PDN_ALTER);
#else
   DRV_WriteReg(DRVPDN_CON1+0x10,(kal_uint16)DRVPDN_CON1_ALTER);
#endif
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

void Alter_level(kal_uint8 level)
{
   if (level > 5)
      ASSERT(0);
   
   ALTER_LEVEL_SAVE = level;
#if !defined(DRV_ALERTER_NOT_EXIST)
   if (level)
   {
      Alter_Configure(Alter_Level_Info[level-1][0],Alter_Level_Info[level-1][1]);
      Alter_Start();
   }
   else
   {
      Alter_Stop();
   }
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}

kal_uint8 Alter_GetCurrentLevel(void)
{
   return ALTER_LEVEL_SAVE;
}

