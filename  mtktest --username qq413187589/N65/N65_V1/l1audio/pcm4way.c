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
 * pcm4way.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PCM4WAY/PCM2WAY interface 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#include "l1audio_def.h"
#include "am.h"

#define DSP_PCM_EX_LEN 160
#define PCM4WAY_STATE 0x1 
#define PCM2WAY_STATE 0x2

#if defined(MT6223) || defined(MT6223P)
#define PCMNWAY_DM_ADDR(x)		DSP2_DM_ADDR(1, (x))
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
#define PCMNWAY_DM_ADDR(x)		DSP2_DM_ADDR(3, (x))
#else
#define PCMNWAY_DM_ADDR(x)		DSP_DM_ADDR(2, (x))
#endif

static struct{
   void (*hdlr)(void);
   uint32 state; 
}pcmEx; 
   
void pcmEx_hisrHdlr(void *param) 
{
   if(DP_PCM_EX_CTRL == 0) 
      return;
      
   if(pcmEx.state == PCM4WAY_STATE)
   {   
      ASSERT(DP_PCM_EX_CTRL == 0x102);    
   }
   else if(pcmEx.state == PCM2WAY_STATE) 
   {
      ASSERT(DP_PCM_EX_CTRL == 0x120);
   }   
   else 
      ASSERT(false);      
   ASSERT(DP_PCM_EX_UL_LEN == DSP_PCM_EX_LEN); 
   ASSERT(DP_PCM_EX_DL_LEN == DSP_PCM_EX_LEN);   
   pcmEx.hdlr();   
}

//************** PCM 4-WAY *******************

void PCM4WAY_Start(void (*pcm4way_hdlr)(void), uint32 type)
{
   uint32 I;
   
   AM_PCM_EX_On(type);
   
   ASSERT(DP_PCM_EX_CTRL == 0); 
   
   L1Audio_HookHisrHandler(DP_D2C_PCM_EX,(L1Audio_EventHandler)pcmEx_hisrHdlr, 0);
   pcmEx.hdlr = pcm4way_hdlr; 
   pcmEx.state = PCM4WAY_STATE;
   DP_PCM_EX_CTRL = 0x101; 
   for(I = 0; ;I ++)
   {
      if(DP_PCM_EX_CTRL == 0x102)
         break;
#ifndef L1D_TEST
      ASSERT(I < 22);  // wait 200ms  
      kal_sleep_task(2);
#endif
   }                          
            
}

void PCM4WAY_Stop(uint32 type)
{
   ASSERT(DP_PCM_EX_CTRL == 0x102);   
   DP_PCM_EX_CTRL = 0;         
   AM_PCM_EX_Off(type);
   L1Audio_UnhookHisrHandler(DP_D2C_PCM_EX); 
   pcmEx.hdlr = NULL;
   pcmEx.state = 0;       
}

////////////////////////////////////////////////////////////////////////////////

void PCM4WAY_GetFromMic(uint16 *ul_buf)
{
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR);
   *ul_buf = *ptr;   // dummy read
   for( I = DSP_PCM_EX_LEN; I > 0; I-- )    
       *ul_buf++ = *ptr++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
  
void PCM4WAY_PutToSE(const uint16 *ul_data)  
{
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   *ptr++ = *ul_data++;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = *ul_data++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void PCM4WAY_FillSE(uint16 value)  
{
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   *ptr++ = value;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = value;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void PCM4WAY_GetFromSD(uint16 *dl_buf)
{
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 640);
   *dl_buf = *ptr;   // dummy read
   for( I = DSP_PCM_EX_LEN; I > 0; I-- )
      *dl_buf++ = *ptr++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void PCM4WAY_PutToSpk(const uint16 *dl_data)
{
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 960);
   *ptr++ = *dl_data++;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = *dl_data++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void PCM4WAY_FillSpk(uint16 value)  
{
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 960);
   *ptr++ = value;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = value;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

//************** PCM 2-WAY *******************

void PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type)
{
   uint32 I;

   ASSERT(type==1 || type==2);
   AM_PCM_EX_On(type);
   
   ASSERT(DP_PCM_EX_CTRL == 0); 
   
   L1Audio_HookHisrHandler(DP_D2C_PCM_EX, (L1Audio_EventHandler)pcmEx_hisrHdlr, 0);
   pcmEx.hdlr = pcm2way_hdlr;
   pcmEx.state = PCM2WAY_STATE; 
   DP_PCM_EX_CTRL = 0x110; 
   for(I = 0; ;I ++)
   {
      if(DP_PCM_EX_CTRL == 0x120)
         break;
      ASSERT(I < 22);  // wait 200ms  
      kal_sleep_task(2);
   }                                                      
}

void PCM2WAY_Stop(uint32 type)
{
   ASSERT(type==1 || type==2);
   ASSERT(DP_PCM_EX_CTRL == 0x120);      
   DP_PCM_EX_CTRL = 0;         
   AM_PCM_EX_Off(type);    
   L1Audio_UnhookHisrHandler(DP_D2C_PCM_EX); 
   pcmEx.hdlr = NULL ;
   pcmEx.state = 0;           
}


void PCM2WAY_GetFromMic(uint16 *ul_buf)
{
   uint32 I;      

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR);
   *ul_buf = *ptr;   // dummy read
   for( I = DSP_PCM_EX_LEN; I > 0; I-- )    
       *ul_buf++ = *ptr++;
#else             
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
} 

void PCM2WAY_PutToSpk(const uint16 *dl_data)
{
   uint32 I;      

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   *ptr++ = *dl_data++;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = *dl_data++;
#else   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void PCM2WAY_FillSpk(uint16 value)
{
   uint32 I;   
#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   *ptr++ = value;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = value;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#else                                                                        
char dummy_pcm4way_c;    /* define a dummy variable to avoid warning message */
#endif 