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
 * sp_enhance.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   speech enhancement functions (moved from am.c)  
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "media.h"
#include "afe.h"

// KH: Must synchronize with DEFAULT_SPEECH_NORMAL_PARA in \mcu\custom\common\audcoeff_default.h (asked by Pancho)
#define DSP_SUPPORT_DRC ( defined(MT6229_S02) || defined(MT6230_S02) )

#if defined(MT6228) || defined(MT6225) 
#define DSP_DRC_PARAM_IN_ADDR    0x3F95
#elif defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6235) || defined(MT6238)
#define DSP_DRC_PARAM_IN_ADDR    0x3EB4
#elif defined(MT6223) || defined(MT6223P) 
#define DSP_DRC_PARAM_IN_ADDR    0x3994
#endif    

#if DSP_SUPPORT_DRC
const int16 DRC_PARAM_Table[70] = {
     2,    10,    63,  20479,     0,  0,    50,    90,   120,   400, 
    0,    0,    0,    0,  1280,   512, 31129, 31129, 24575, 24575,
  2048,  1024, 27852, 32439, 32439, 25886, 25886,    50,    90,   150,   
   800,     0,     0,     0,     0,  1280,   512, 31129, 31129, 24575, 
 24575,  1024,   512, 27852, 32439, 26214, 25886, 25886,     0,  -512, 
     0,  4096, -3840,   768,   768,   256,   512,    -5,  -512,     0, 
  3840, -3329,   768,   768,   256,   512,   128,  6100,   128,  7300
};
#endif 

#if defined(MT6223) || defined(MT6223P)
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 16384,     1,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 16384,     0,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif



/* ========================================================================= */
/*   SBSD control Functions                                            */
/* ========================================================================= */
#if  defined(MT6217) || defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
void SPE_SetSBSD( bool state )
{
   if ( state )       
      *DP_SBSD_CTRL |= 0x12;   
   else
      *DP_SBSD_CTRL &= ~0x12;
}
#endif
/* ========================================================================= */


/* ========================================================================= */
/*   EC/AEC/EES control Functions                                            */
/* ========================================================================= */
#define  FLAG_EC_SUPP         1
#define  FLAG_DDL_UL_ENTRY    2
#define  FLAG_DDL_DL_ENTRY    4

#define  SPE_IDLE_STATE       0  /* MCU: 0 -> 1 */ 
#define  SPE_READY_STATE      1  /* DSP: 1 -> 2 */    
#define  SPE_WORKING_STATE    2  /* MCU: 2 -> 3 */ 
#define  SPE_STOP_STATE       3  /* DSP: 3 -> 0 */  

#define _set_state_( _CTRL_REGISTER, STATE )  \
   _CTRL_REGISTER = STATE;

static uint8 spe_check = 0;
#define _wait_state_change_( _CTRL_REGISTER, STATE )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( _CTRL_REGISTER == STATE )  \
         break;  \
      if( I == 20 ){ \
         spe_check = 1; \
         *SHARE_DSPCON &= ~0x4; \
      } \
      kal_sleep_task( 2 );  \
   }  \
}
void spe_wait_state_change(volatile uint16 *spe_reg, uint16 wait_state )
{
   uint32 I;
   for( I = 0; ; I++ ) {
      if( *spe_reg == wait_state )
         break;
      ASSERT( I < 20 );
      kal_sleep_task( 2 );
   }
}

#if !defined(MT6205B)

static uint16 spe_m_para7;
void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS] )
{
   uint16 *para;
   volatile uint16* dsp_ptr;
   int I;

   if(c_para)
   {
      para = c_para;      
      dsp_ptr = DSP_CPARA_ADDR;      
      for(I = NUM_COMMON_PARAS; --I >= 0 ; )
         *dsp_ptr++ = *para++;
   }

   if(m_para)
   {
      para = m_para;      
      dsp_ptr = DSP_MPARA_ADDR;       
      for(I = NUM_MODE_PARAS; --I >= 0 ; )
         *dsp_ptr++ = *para++; 
      spe_m_para7 = m_para[7];   
   }
}

void SPE_LoadLimiterPara(uint16 para)
{
   volatile uint16 *ptr = DSP_CPARA_ADDR;
   ptr[1] = para;
}

#endif

void SPE_LoadSpeechPara_ES( uint16 timeConst, uint16 volConst )
{
   *DP_ES_Time_Const  = timeConst;
   *DP_ES_Vol_Const   = volConst;
}

/* ========================================================================= */
#if !defined(MT6205B)
extern const unsigned short Speech_Normal_Mode_Para[8];
#endif
void SPE_Init( void )
{
   *DP_EC_SUPP = 0;
#if !defined(MT6205B)
   *DP_SPE_DL_DLL_ENTRY = 0; 
   spe_m_para7 = 0;  

   SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para);
#endif    
}

void SPE_TurnOnProcess(uint8 on_state)
{
#if defined(MT6205B)
   ASSERT( on_state == SPE_ES_FLAG ); 
   *DP_EC_SUPP = FLAG_EC_SUPP;
#elif (defined(MT6218) || defined(MT6218B) || defined(MT6217) || defined(MT6219) || defined(MT6227_S00))
          
   switch(on_state)
   {
      case SPE_AEC_FLAG: 
         *DP_EC_SUPP |= FLAG_DDL_UL_ENTRY;
         _set_state_(*DP_AEC_CTRL , SPE_READY_STATE);
         spe_wait_state_change(DP_AEC_CTRL , SPE_WORKING_STATE); 
         break;
      case SPE_EES_FLAG: 
         *DP_EC_SUPP |= FLAG_DDL_UL_ENTRY; 
         _set_state_(*DP_EES_CTRL , SPE_READY_STATE);
         spe_wait_state_change(DP_EES_CTRL , SPE_WORKING_STATE);   
         break;
      case SPE_ES_FLAG: 
         *DP_EC_SUPP |= FLAG_EC_SUPP;
         break;
      default: 
         ASSERT(false);    
   }   
#else // MT6228 , MT6229 , MT6226 , MT6227 , MT6226M , MT6225

#if DSP_SUPPORT_DRC
   if(on_state & (SPE_UL_NR_FLAG + SPE_DL_NR_FLAG))
   {
      volatile uint16* dsp_ptr;
      const int16 *table_ptr;
      int32 I; 
      
      table_ptr = DRC_PARAM_Table;
      dsp_ptr = DSP_PM_ADDR(0,DSP_DRC_PARAM_IN_ADDR);
      for(I = 70; --I >= 0 ; )
         *dsp_ptr ++ = *table_ptr++;       
   }
#endif    

   if(on_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG))
      *DP_EC_SUPP |= FLAG_DDL_UL_ENTRY; 
   
   if(on_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG))
      *DP_SPE_DL_DLL_ENTRY |= FLAG_DDL_DL_ENTRY;


   if(on_state & SPE_UL_NR_FLAG)
      _set_state_(*DP_UL_NR_CTRL , SPE_READY_STATE);   
   if(on_state & SPE_DL_NR_FLAG)
      _set_state_(*DP_DL_NR_CTRL , SPE_READY_STATE);      
      

   if(on_state & ( SPE_AEC_FLAG + SPE_EES_FLAG + SPE_ES_FLAG ))
   {
      switch(on_state & ( SPE_AEC_FLAG + SPE_EES_FLAG + SPE_ES_FLAG ))
      {
         case SPE_AEC_FLAG: 
         #if defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227D)
            _set_state_(*DP_AEC2_CTRL , SPE_READY_STATE);
            spe_wait_state_change(DP_AEC2_CTRL , SPE_WORKING_STATE);           
         #else 
            if(spe_m_para7 & 0x1)
            {
               _set_state_(*DP_AEC_CTRL , SPE_READY_STATE);
               spe_wait_state_change(DP_AEC_CTRL , SPE_WORKING_STATE);             
            }               
            else 
            {
               _set_state_(*DP_AEC2_CTRL , SPE_READY_STATE);
               spe_wait_state_change(DP_AEC2_CTRL , SPE_WORKING_STATE); 
            }
         #endif    
            break;
         case SPE_EES_FLAG:          
            _set_state_(*DP_EES_CTRL , SPE_READY_STATE);
            spe_wait_state_change(DP_EES_CTRL , SPE_WORKING_STATE);   
            break;
         case SPE_ES_FLAG: 
            *DP_EC_SUPP |= FLAG_EC_SUPP;
            break;
         default: 
            ASSERT(false);    
      }   
   }
   
   if(on_state & SPE_UL_NR_FLAG)
      spe_wait_state_change(DP_UL_NR_CTRL , SPE_WORKING_STATE);  
   if(on_state & SPE_DL_NR_FLAG)
      spe_wait_state_change(DP_DL_NR_CTRL , SPE_WORKING_STATE);  
#endif       
}


void SPE_TurnOffProcess(uint8 off_state)
{
   AM_EnterSpeechOff();
#if defined(MT6205B)
   ASSERT( off_state == SPE_ES_FLAG ); 
   *DP_EC_SUPP &= ~(FLAG_EC_SUPP);   
#elif (defined(MT6218) || defined(MT6218B) || defined(MT6217) || defined(MT6219) || defined(MT6227_S00))     
      
   switch(off_state)
   {
      case SPE_AEC_FLAG:       
         _set_state_(*DP_AEC_CTRL , SPE_STOP_STATE);
         spe_wait_state_change(DP_AEC_CTRL , SPE_IDLE_STATE);
         break;
      case SPE_EES_FLAG: 
         _set_state_(*DP_EES_CTRL , SPE_STOP_STATE);    
         spe_wait_state_change(DP_EES_CTRL , SPE_IDLE_STATE);     
         break;
      case SPE_ES_FLAG: 
         *DP_EC_SUPP &= ~(FLAG_EC_SUPP);
         break;
      default: 
         ASSERT(false);    
   }                                 
#else  // MT6228, MT6229, MT6226, MT6227, MT6226M, MT6225, MT6223, MT6223P  
   
   if(off_state & SPE_UL_NR_FLAG)
      _set_state_(*DP_UL_NR_CTRL , SPE_STOP_STATE);   
   if(off_state & SPE_DL_NR_FLAG)
      _set_state_(*DP_DL_NR_CTRL , SPE_STOP_STATE);            
   
   if(off_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_ES_FLAG))
   { 
      switch(off_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_ES_FLAG))
      {
         case SPE_AEC_FLAG: 
         #if defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227D)
            _set_state_(*DP_AEC2_CTRL , SPE_STOP_STATE);
            spe_wait_state_change(DP_AEC2_CTRL , SPE_IDLE_STATE);         
         #else 
            if(spe_m_para7 & 0x1) 
            {
               _set_state_(*DP_AEC_CTRL , SPE_STOP_STATE);
               spe_wait_state_change(DP_AEC_CTRL , SPE_IDLE_STATE);            
            }
            else 
            {
               _set_state_(*DP_AEC2_CTRL , SPE_STOP_STATE);
               spe_wait_state_change(DP_AEC2_CTRL , SPE_IDLE_STATE);               
            }      
         #endif    
            break;
         case SPE_EES_FLAG: 
            _set_state_(*DP_EES_CTRL , SPE_STOP_STATE);    
            spe_wait_state_change(DP_EES_CTRL , SPE_IDLE_STATE);     
            break;
         case SPE_ES_FLAG: 
            *DP_EC_SUPP &= ~(FLAG_EC_SUPP);
            break;
         default: 
            ASSERT(false);    
      }
   }                      
                                             
   if(off_state & SPE_UL_NR_FLAG)
      spe_wait_state_change(DP_UL_NR_CTRL , SPE_IDLE_STATE);  
   if(off_state & SPE_DL_NR_FLAG)
      spe_wait_state_change(DP_DL_NR_CTRL , SPE_IDLE_STATE);  
      
#endif
   AM_LeaveSpeechOff();
}

#if !defined(MT6205B)
void SPE_Clear_DLL_Entry(uint8 cur_state)
{
   if(!(cur_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG)))
      *DP_EC_SUPP &= ~FLAG_DDL_UL_ENTRY; 
   
   #if !(defined(MT6217) || defined(MT6219) || defined(MT6227_S00) || defined(MT6226_S00) || defined(MT6226M_S00) )  
   if(!(cur_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG)))
      *DP_SPE_DL_DLL_ENTRY &= ~FLAG_DDL_DL_ENTRY;        
   #endif    
}
#endif 

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
void SPE_SetULNR( bool ec )
{
#if !(defined(MT6227_S00) || defined(MT6226_S00) || defined(MT6226M_S00))   
   if( ec )
   {  
#if DSP_SUPPORT_DRC
      volatile uint16* dsp_ptr;
      const int16 *table_ptr;
      int32 I; 
      
      table_ptr = DRC_PARAM_Table;
      dsp_ptr = DSP_PM_ADDR(0,DSP_DRC_PARAM_IN_ADDR);
      for(I = 70; --I >= 0 ; )
         *dsp_ptr ++ = *table_ptr++;
#endif
      *DP_EC_SUPP |= FLAG_DDL_UL_ENTRY;      
      if( *DP_UL_NR_CTRL == SPE_IDLE_STATE )
      {
         L1SP_LoadSpeechPara();
         _set_state_(*DP_UL_NR_CTRL , SPE_READY_STATE);
         spe_wait_state_change(DP_UL_NR_CTRL , SPE_WORKING_STATE); 
      }   
   }
   else
   {
      if( *DP_UL_NR_CTRL != SPE_IDLE_STATE )
      {
         _set_state_(*DP_UL_NR_CTRL , SPE_STOP_STATE);
         spe_wait_state_change(DP_UL_NR_CTRL , SPE_IDLE_STATE);
         *DP_EC_SUPP &= ~(FLAG_DDL_UL_ENTRY);
      }
   }
#endif    
}
#endif 
