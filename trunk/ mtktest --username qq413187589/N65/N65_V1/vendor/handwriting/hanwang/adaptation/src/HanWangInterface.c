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
 * HanWangInterface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Pen Function in Editor
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
 *============================================================================
 ****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/vendor/handwriting/hanwang/adaptation/src/HanWangInterface.c,v 1.6 2007/08/02 05:07:21 bw Exp $
*
* $Id: HanWangInterface.c,v 1.6 2007/08/02 05:07:21 bw Exp $
*
* $Date: 2007/08/02 05:07:21 $
*
* $Name: 1.6 $
*
* $Locker$
*
* $Revision: 1.6 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: HanWangInterface.c,v $
* Revision 1.6  2007/08/02 05:07:21  bw
* UNI@bw_0802_0002 [所有项目][所有客户]增加泰文输入法
*
* Revision 1.5  2007/08/02 03:06:53  bw
* UNI@bw_0802_0002 [所有项目][所有客户]增加泰文手写输入法
*
* Revision 1.4  2007/06/22 01:20:32  bw
* UNI@bw_20070621c 15:02:22 保证PC 上可以编译
*
* Revision 1.3  2007/06/07 05:23:46  bw
* UNI@bw 0607 增加捷通手写识别
*
* Revision 1.3  2006/09/27 04:48:22  bw
* P_U6_M31_bw_Z0006 合并6226修改(更新到2006-09-26日版本)到U6.
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _HANWANG_INTERFACE_C
#define _HANWANG_INTERFACE_C

/*  Include: MMI header file */
#include "MMI_features.h" 
#if defined(__MMI_TOUCH_SCREEN__)||defined(__MMI_HANDWRITING_PAD__)
//#include "EditorPen.h"
#include "EditorPenGprot.h"
#include "EditorPenProt.h"
#include "kal_non_specific_general_types.h"
#include "gui_data_types.h"
#include "hw.h"


#if defined(LANG_TH_HANDWRITE_AS_ENGLISH_SUPPORT)
	#include "HWAPI.h"
#else
	#if defined(__MTK_TARGET__) 
	#include "hw_edit.h"
	#endif
#endif

#ifdef __MMI_LANG_THAI__
	//Huyanwei Add It For THAI
	#if defined(LANG_TH_HANDWRITE_SUPPORT)
	#include "HWAPI.h"
	#endif
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#if !defined(__MTK_TARGET__)
#define __align(X)
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/*__align(4) */unsigned char bufRam[12*1024] ; 

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_pen_editor_hand_writing_initailize
* DESCRIPTION
*   This function is used to hanwang hand writing.
*
* PARAMETERS
*  None
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/


void mmi_pen_editor_hand_writing_deinitialize(void)
{

}


void mmi_pen_editor_hand_writing_initialize(void )
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
#if defined(__USE_JIETONG_HANDWRITING__)
  static int justInitOnce =0;
  if(justInitOnce==0)  
  {
     justInitOnce++;
  #if defined(__MTK_TARGET__) /*UNI@bw_20070621c 15:02:22 保证PC 上可以编译*/
     HZInitCharacterRecognition((void *)hand_writing_data);
  #else
    HWSetDictionary( (DWORD)bufRam, 0 );
  #endif
  }   
#else//__USE_JIETONG_HANDWRITING__

#if !defined(LANG_TH_HANDWRITE_AS_ENGLISH_SUPPORT)
//Huyanwei Add it 
  #if defined(__MTK_TARGET__)
     HWSetDictionary( (DWORD)bufRam, (DWORD)hand_writing_data );
  #else
     HWSetDictionary( (DWORD)bufRam, 0 );
  #endif
#else
     HWSetDictionary( (DWORD)bufRam, 0 );
#endif
  
#endif

} /* end of mmi_pen_editor_hand_writing_initailize*/


#if defined(LANG_TH_HANDWRITE_AS_ENGLISH_SUPPORT)
//Huyanwei Add It 
	long pRam[HWRERAMSIZE / 4]; /* align on 4-byte boundary */
#else
	#ifdef __MMI_LANG_THAI__
	//Huyanwei Add It For THAI
	#if defined(LANG_TH_HANDWRITE_SUPPORT)
	long pRam[HWRERAMSIZE / 4]; /* align on 4-byte boundary */
	#endif
	#endif
#endif


/*****************************************************************************
* FUNCTION
*  mmi_pen_editor_hand_writing_initailize
* DESCRIPTION
*   This function is used to hanwang hand writing.
*
* PARAMETERS
*  None
*  
* RETURNS
*  None
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
#if !defined(LANG_TH_HANDWRITE_AS_ENGLISH_SUPPORT)

s32 mmi_pen_editor_hand_writing_get_candidates(U16* stroke_buffer,UI_character_type* candidate_array,mmi_pen_editor_input_type_enum h_w_type,s32 number)
{
#if defined(__USE_JIETONG_HANDWRITING__)
   int num = 0,i=0;
   unsigned short szResult[PEN_EDITOR_MAX_CANDIDATE_SIZE];
   szResult[11] = 0;
  
   if (PEN_EDITOR_SIMPLIFIED_CHINESE==h_w_type)
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_GB | RECOG_RANGE_SYMBOL | RECOG_RANGE_NUMBER);
   }

   else if (PEN_EDITOR_TRADITIONAL_CHINESE==h_w_type)
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_BIG5  | RECOG_RANGE_SYMBOL | RECOG_RANGE_NUMBER);
   }
   else if (PEN_EDITOR_LOWER_CASE_ENGLISH==h_w_type)
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_SYMBOL);
   }
   else if (PEN_EDITOR_UPPER_CASE_ENGLISH==h_w_type)
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_SYMBOL);
   }
   else if (PEN_EDITOR_NUMBER==h_w_type)
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_NUMBER);
   }
   else if (PEN_EDITOR_PUNCTUATION==h_w_type)
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_INTERPUNCTION);
   }
//UNI@bw_0802_0002 增加泰文手写输入法   
#ifdef __MMI_LANG_THAI__
   else if(PEN_EDITOR_THAI == h_w_type)
   {
   	//num = WD_HwOnIdentify_Ex(stroke_buffer,candidate_array, 0);   	
   	   num = 9;
   }	   
#endif
   else
   {
      num = HZCharacterRecognize((short *)stroke_buffer,szResult,number,RECOG_RANGE_GESTURE);     
   }
   if(PEN_EDITOR_THAI != h_w_type)//UNI@bw_0802_0002 增加泰文手写输入法 
   {   
   for (i=0;i<num;i++)
   {
      if((szResult[i]>0xFF00)&&(szResult[i]<=0xFF65))
        candidate_array[i] = szResult[i]-0xFEE0;
      else
        candidate_array[i] = szResult[i];
   }
   }
   return num;
#else
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    int num = 0,i=0;
   unsigned char szResult[PEN_EDITOR_MAX_CANDIDATE_SIZE*2];
   UI_character_type curCh;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   if (PEN_EDITOR_SIMPLIFIED_CHINESE==h_w_type)
   {
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, HWX_COMMON_SIMPLE_CHS | HWX_RARE_SIMPLE_CHS | HWX_TRADITIONAL_TO_SIMPLE | HWX_LOW_ENG|HWX_UP_ENG|HWX_NUM );//P_U6_M31_bw_Z0001 从6226移植 汉字手写时支持数字和字母 
   }
   else if (PEN_EDITOR_TRADITIONAL_CHINESE==h_w_type)
   {
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, HWX_COMMON_TRADITIONAL_CHS | HWX_RARE_TRADITIONAL_CHS | HWX_SIMPLE_TO_TRADITIONAL | HWX_LOW_ENG|HWX_UP_ENG|HWX_NUM  );//P_U6_M31_bw_Z0001 从6226移植 汉字手写时支持数字和字母
   }
   else if (PEN_EDITOR_LOWER_CASE_ENGLISH==h_w_type)
   {
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, HWX_LOW_ENG|HWX_UP_ENG|HWX_NUM/*|HWX_COMMON_PUNC|HWX_COMMON_SYM*/ );
   }
   else if (PEN_EDITOR_UPPER_CASE_ENGLISH==h_w_type)
   {
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, HWX_LOW_ENG|HWX_UP_ENG|HWX_NUM/*|HWX_COMMON_PUNC|HWX_COMMON_SYM8*/ );
   }
   else if (PEN_EDITOR_NUMBER==h_w_type)
   {
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, /*HWX_LOW_ENG|HWX_UP_ENG|*/HWX_NUM/*|HWX_COMMON_PUNC|HWX_COMMON_SYM*/ );
   }
   else if (PEN_EDITOR_PUNCTUATION==h_w_type)
   {
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, HWX_COMMON_PUNC|HWX_COMMON_SYM );
   }
//UNI@bw_0802_0002 增加泰文手写输入法   
#ifdef __MMI_LANG_THAI__
   else if(PEN_EDITOR_THAI == h_w_type)
   {
#if defined(LANG_TH_HANDWRITE_SUPPORT)   
	#if 0
		//Huyanwei Modify it For THAI Hand Write
		//num = WD_HwOnIdentify_Ex(stroke_buffer,candidate_array, 0);   	
	#else
	THAI_THWAttribute attr;
	//unsigned short Result[MAXCANDNUM];
	int count = 0 ;
	attr.iCandidateNum = MAXCANDNUM;
	attr.dwRange = CHARSET_THAILAND;
	attr.iBoxWidth = 0;
	attr.iBoxHeight = 0;
	attr.pRam = (unsigned char*)pRam;
	
	#if !defined(WIN32)
	num = HWRecognizeThai((const THWPoint* )stroke_buffer, &attr, candidate_array);
	#endif
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n return num  =%d\r\n",num);	
#endif
	while( count  < num )
      {
#if defined(NOKE_DEBUG)
	 	  noke_dbg_printf("\r\n candidate_array[%d] = 0x%04x\r\n",count ,candidate_array[count ]);
#endif
	  	  count  ++;   	   	
	 }   	   
	#endif   	 
#else
	num = 0;
#endif	
	
   }	   
#endif
   else
   {
      /*MMI_ASSERT(0)??*/
      num = HWRecognize( (U16*)stroke_buffer, (char*)szResult, number, HWX_GES );
   }
   if(PEN_EDITOR_THAI != h_w_type)//UNI@bw_0802_0002 增加泰文手写输入法 
   {
   for (;i<num*2;i+=2)
   {
      U16 c1 = szResult[i];
      U16 c2 = szResult[i+1];
      curCh = c1 | (c2 << 8);
      candidate_array[i>>1] = curCh;
   }
   }
   return num;
#endif   
} /* end of mmi_pen_editor_hand_writing_get_candidates*/
#else

s32 mmi_pen_editor_hand_writing_get_candidates(U16* stroke_buffer,UI_character_type* candidate_array,mmi_pen_editor_input_type_enum h_w_type,s32 number)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    int num = 0,i=0;
   unsigned char szResult[PEN_EDITOR_MAX_CANDIDATE_SIZE*2];
   UI_character_type curCh;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   if ( (PEN_EDITOR_UPPER_CASE_ENGLISH==h_w_type) || (PEN_EDITOR_LOWER_CASE_ENGLISH==h_w_type) )
   {
	THAI_THWAttribute attr;
	//unsigned short Result[MAXCANDNUM];
	int count = 0 ;
	attr.iCandidateNum = MAXCANDNUM;
	attr.dwRange = CHARSET_ENGLISH;
	attr.iBoxWidth = 0;
	attr.iBoxHeight = 0;
	attr.pRam = (unsigned char*)pRam;	
	#if !defined(WIN32)
	num = HWRecognizeThai((const THWPoint* )stroke_buffer, &attr, candidate_array);
	#else
	num = 0 ;
	#endif		
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n return num  =%d\r\n",num);	
#endif
	
   }
   #ifdef __MMI_LANG_THAI__
   else if(PEN_EDITOR_THAI == h_w_type)
   {
#if defined(LANG_TH_HANDWRITE_SUPPORT)   
	THAI_THWAttribute attr;
	//unsigned short Result[MAXCANDNUM];
	int count = 0 ;
	attr.iCandidateNum = MAXCANDNUM;
	attr.dwRange = CHARSET_THAILAND;
	attr.iBoxWidth = 0;
	attr.iBoxHeight = 0;
	attr.pRam = (unsigned char*)pRam;
	
	#if !defined(WIN32)
	num = HWRecognizeThai((const THWPoint* )stroke_buffer, &attr, candidate_array);
	#endif

#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n return num  =%d\r\n",num);	
#endif
	while( count  < num )
      {
#if defined(NOKE_DEBUG)
	 	  noke_dbg_printf("\r\n candidate_array[%d] = 0x%04x\r\n",count ,candidate_array[count ]);
#endif	 	  
	  	  count  ++;   	   	
	 }   	   
#else
	num = 0;
#endif		
   }	   
   #endif
   else 
   {
	num = 0;
   }	         
   
   return num;
   
} /* end of mmi_pen_editor_hand_writing_get_candidates*/

#endif


#endif /*__MMI_TOUCH_SCREEN__*/
#endif
