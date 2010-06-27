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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * bra_inse.c
 *
 * Description:
 *		This file contains code for the Internet Services menu
 */
#include "bra_main.h"
#include "bra_win.h"
#include "bra_view.h"
#include "bra_req.h"
#include "bra_set.h"
#include "bra_sig.h"
#include "bra_cmn.h"
#include "bra_str.h"
#include "bra_inse.h"
#include "bra_bkm.h"
#include "bra_prof.h"
#include "bra_dlg.h"
#include "bra_rpl.h"
#include "bra_sif.h"
#include "bra_int.h" 

#ifdef BRA_CONFIG_SECURITY
#include "bra_sec.h"
#endif

#ifdef BRA_CFG_OFFLINE_PAGES
#include "bra_ofln.h"
#endif

#include "wap.h"

#include "msf_lib.h"
#include "msf_core.h"

#include "DLAgentResDef.h"

/************************************************************
 * Local Types
 ************************************************************/

/* start menu */
typedef struct {
  MsfWindowHandle windowHandle;
  MsfActionHandle selectActionHandle;
  MsfActionHandle backActionHandle;
} bra_inse_menu_t;

/************************************************************
 * Global Variables
 ************************************************************/

static MSF_BOOL show_download;

#ifdef WAP_MEM_DEBUG

static MSF_UINT8 dump;

typedef struct {
  MsfWindowHandle windowHandle;
  MsfActionHandle selectActionHandle;
  MsfActionHandle backActionHandle;
} bra_mem_logging_menu_t;

/************************************************************
 * Memory Logging Function 
 ************************************************************/

static void
bra_widget_action_mem_logging_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_mem_logging_menu_t *p;
  MSF_UINT8 i = 0;

  p = (bra_mem_logging_menu_t *)(win);

	if (bra_action == p->backActionHandle)
	{
      bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
	}
	else if (bra_action == p->selectActionHandle)
	{
      extern void wap_set_mem_debug_mod(MSF_UINT8 modId);

		if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Memory Dump to Catcher*/
      dump = 0;      
      }
#ifndef __MTK_TARGET__
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Memory Dump to File*/      
      dump = 1;
      }
#endif
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set MSM as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_MSM);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set STK as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_STK);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set BRS as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_BRS);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set BRA as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_BRA);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set PHS as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_PHS);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set UIS as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_UIS);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set PRS as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_PRS);
		}
#ifdef BRA_CONFIG_SECURITY
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set SEC as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_SEC);
		}
#endif
#ifdef BRA_CONFIG_MMS
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set MMS as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_MMS);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set MEA as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_MEA);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set SLS as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_SLS);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set SMA as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_SMA);
		}
#endif
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Set WIDGET as Memory Logging Module*/
      wap_set_mem_debug_mod(MSF_MODID_WIDGET);
		}
      bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
	}
}

static void
bra_delete_mem_logging_menu (bra_win_t *win)
{
  extern void wap_mem_debug_dump_catcher(void);
#ifndef __MTK_TARGET__
  extern void wap_mem_debug_dump_file(void);
#endif
  bra_mem_logging_menu_t *p;

  p = (bra_mem_logging_menu_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

	MSF_WIDGET_RELEASE (p->windowHandle); 
	MSF_WIDGET_RELEASE (p->selectActionHandle);
	MSF_WIDGET_RELEASE (p->backActionHandle);

  BRA_FREE (p);

  if(dump == 0)
     wap_mem_debug_dump_catcher();
#ifndef __MTK_TARGET__
  else if(dump == 1)
     wap_mem_debug_dump_file();
#endif     
}

void
bra_create_mem_logging_menu (void)
{
  bra_mem_logging_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;
  MsfStringHandle ms;
  extern unsigned int wapadp_alloc_mem[WAP_MEM_POOL_NUM];
  extern unsigned int wapadp_max_mem[WAP_MEM_POOL_NUM];
  char s[32];

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
	
  /*remove menu key action from screen*/
  bra_view_disable ();

  win = BRA_ALLOCTYPE (bra_mem_logging_menu_t);
  
	win->selectActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->windowHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
                                             &prop.displaySize,
                                             win->selectActionHandle,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);

   ms = BRA_STRCONV("Dump to Catcher");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
#ifndef __MTK_TARGET__
   ms = BRA_STRCONV("Dump to File");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
#endif
   ms = BRA_STRCONV("Logging MSM");
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging STK");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging BRS");
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging BRA");
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging PHS");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging UIS");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging PRS");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
#ifdef BRA_CONFIG_SECURITY   
   ms = BRA_STRCONV("Logging SEC");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
#endif   
#ifdef BRA_CONFIG_MMS
   ms = BRA_STRCONV("Logging MMS");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging MEA");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging SLS");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
   ms = BRA_STRCONV("Logging SMA");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);
#endif
   ms = BRA_STRCONV("Logging WIDGET");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
   MSF_WIDGET_RELEASE (ms);

   sprintf(s, "current:%d", wapadp_alloc_mem[WAP_MEM_POOL]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

#ifdef WAP_USE_ASM
   sprintf(s, "current(app):%d", wapadp_alloc_mem[WAP_APP_MEM_POOL]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
#endif   

   sprintf(s, "Maximum:%d", wapadp_max_mem[WAP_MEM_POOL]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
   
#ifdef WAP_USE_ASM
   sprintf(s, "Maximum(app):%d", wapadp_max_mem[WAP_APP_MEM_POOL]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
#endif      

   ms = BRA_STRCONV("Memory Logging"); 
	MSF_WIDGET_SET_TITLE(win->windowHandle, ms);
   MSF_WIDGET_RELEASE (ms);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);
	
  bra_win_show_window (BRA_WIN_ID_INSE,  
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_mem_logging_menu, 
                      NULL,
                      bra_widget_action_mem_logging_menu);
}

static void
bra_widget_action_mem_status_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_mem_logging_menu_t *p;
  MSF_UINT8 i = 0;

  p = (bra_mem_logging_menu_t *)(win);

  bra_win_close_window(BRA_WIN_CLOSE_CURRENT, 0);
}

static void
bra_delete_mem_status_menu (bra_win_t *win)
{
  bra_mem_logging_menu_t *p;

  p = (bra_mem_logging_menu_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

	MSF_WIDGET_RELEASE (p->windowHandle); 
	MSF_WIDGET_RELEASE (p->selectActionHandle);
	MSF_WIDGET_RELEASE (p->backActionHandle);

  BRA_FREE (p);
}

void
bra_create_mem_status_menu (int type)
{
  bra_mem_logging_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;
  MsfStringHandle ms;
  extern unsigned int wapadp_alloc_mem[WAP_MEM_POOL_NUM];
  extern unsigned int wapadp_alloc_bytes[MSF_NUMBER_OF_MODULES];
  extern unsigned int wapadp_max_bytes[MSF_NUMBER_OF_MODULES];
  unsigned int alloc_mem = wapadp_alloc_mem[WAP_MEM_POOL];
  unsigned int msf_alloc_mem = 0;
  unsigned int other_max_mem = 0;
  unsigned int alloc_bytes[MSF_NUMBER_OF_MODULES];
  unsigned int max_bytes[MSF_NUMBER_OF_MODULES];
  unsigned int msf_alloc_bytes[MSF_NUMBER_OF_MODULES];
  char s[64];

  for(i = 0;i < MSF_NUMBER_OF_MODULES;i++)
  {
    msf_alloc_bytes[i] = msf_mem_allocated_bytes(i);
    msf_alloc_mem += msf_alloc_bytes[i];
    alloc_bytes[i] = wapadp_alloc_bytes[i];
    max_bytes[i] = wapadp_max_bytes[i];
    if(i == MSF_MODID_BRS || i == MSF_MODID_WIDGET)
      continue;
    other_max_mem += max_bytes[i];
  }

  i = 0;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
	
  /*remove menu key action from screen*/
  bra_view_disable ();

  win = BRA_ALLOCTYPE (bra_mem_logging_menu_t);
  
	win->selectActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->windowHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
                                             &prop.displaySize,
                                             win->selectActionHandle,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);

   if(type == 0)
     sprintf(s, "BW:%d(%d)", 
             alloc_bytes[MSF_MODID_BRS]+alloc_bytes[MSF_MODID_WIDGET],
             msf_alloc_bytes[MSF_MODID_BRS]+msf_alloc_bytes[MSF_MODID_WIDGET]);
   else
     sprintf(s, "BW:%d", max_bytes[MSF_MODID_BRS]+max_bytes[MSF_MODID_WIDGET]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
#ifdef WAP_USE_ASM
     sprintf(s, "OT:%d(%d)", 
             alloc_mem,
             msf_alloc_mem - (msf_alloc_bytes[MSF_MODID_BRS]+msf_alloc_bytes[MSF_MODID_WIDGET]));
#else   
     sprintf(s, "OT:%d(%d)", 
             alloc_mem - (alloc_bytes[MSF_MODID_BRS]+alloc_bytes[MSF_MODID_WIDGET]),
             msf_alloc_mem - (msf_alloc_bytes[MSF_MODID_BRS]+msf_alloc_bytes[MSF_MODID_WIDGET]));
#endif             
   else
     sprintf(s, "OT:%d", other_max_mem);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "BRS:%d(%d)", alloc_bytes[MSF_MODID_BRS], msf_alloc_bytes[MSF_MODID_BRS]);
   else
     sprintf(s, "BRS:%d", max_bytes[MSF_MODID_BRS]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "WIDGET:%d(%d)", alloc_bytes[MSF_MODID_WIDGET], msf_alloc_bytes[MSF_MODID_WIDGET]);
   else
     sprintf(s, "WIDGET:%d", max_bytes[MSF_MODID_WIDGET]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "STK:%d(%d)", alloc_bytes[MSF_MODID_STK], msf_alloc_bytes[MSF_MODID_STK]);
   else
     sprintf(s, "STK:%d", max_bytes[MSF_MODID_STK]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "MSM:%d(%d)", alloc_bytes[MSF_MODID_MSM], msf_alloc_bytes[MSF_MODID_MSM]);
   else
     sprintf(s, "MSM:%d", max_bytes[MSF_MODID_MSM]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "BRA:%d(%d)", alloc_bytes[MSF_MODID_BRA], msf_alloc_bytes[MSF_MODID_BRA]);
   else
     sprintf(s, "BRA:%d", max_bytes[MSF_MODID_BRA]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
#ifdef BRA_CONFIG_SECURITY
   if(type == 0)
     sprintf(s, "SEC:%d(%d)", alloc_bytes[MSF_MODID_SEC], msf_alloc_bytes[MSF_MODID_SEC]);
   else
     sprintf(s, "SEC:%d", max_bytes[MSF_MODID_SEC]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
#endif
   if(type == 0)
     sprintf(s, "UIS:%d(%d)", alloc_bytes[MSF_MODID_UIS], msf_alloc_bytes[MSF_MODID_UIS]);
   else
     sprintf(s, "UIS:%d", max_bytes[MSF_MODID_UIS]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "PHS:%d(%d)", alloc_bytes[MSF_MODID_PHS], msf_alloc_bytes[MSF_MODID_PHS]);
   else
     sprintf(s, "PHS:%d", max_bytes[MSF_MODID_PHS]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

   if(type == 0)
     sprintf(s, "PRS:%d(%d)", alloc_bytes[MSF_MODID_PRS], msf_alloc_bytes[MSF_MODID_PRS]);
   else
     sprintf(s, "PRS:%d", max_bytes[MSF_MODID_PRS]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   

#ifdef MMS_SUPPORT
   if(type == 0)
     sprintf(s, "MMS:%d(%d)", alloc_bytes[MSF_MODID_MMS], msf_alloc_bytes[MSF_MODID_MMS]);
   else
     sprintf(s, "MMS:%d", max_bytes[MSF_MODID_MMS]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
#endif

/*
#ifdef __J2ME__
   if(type == 0)
     sprintf(s, "JAS:%d(%d)", alloc_bytes[MSF_MODID_JAS], msf_alloc_bytes[MSF_MODID_JAS]);
   else
     sprintf(s, "JAS:%d", max_bytes[MSF_MODID_JAS]);
   ms = BRA_STRCONV(s);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, 0, 0, TRUE);   
   MSF_WIDGET_RELEASE (ms);   
#endif
*/      
   ms = BRA_STRCONV("Memory Status"); 
	MSF_WIDGET_SET_TITLE(win->windowHandle, ms);
   MSF_WIDGET_RELEASE (ms);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

	//MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);
	
  bra_win_show_window (BRA_WIN_ID_INSE,  
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_mem_status_menu, 
                      NULL,
                      bra_widget_action_mem_status_menu);
}
#endif

/************************************************************
 * Function 
 ************************************************************/
static void
bra_inse_exit_download_confirmation (MsfActionType response)
{
     if(response == MsfOk)
     {
         bra_destroy_ui();
     }
     else
     {
         bra_da_wap_notify_display_list();
     }
 }
 
static void
bra_widget_action_int_serv_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_inse_menu_t *p;
  MSF_UINT8 i = 0, j = 0;
#ifdef BRA_CFG_OFFLINE_PAGES
  extern kal_bool  global_offline_page;
#endif

  p = (bra_inse_menu_t *)(win);

	if (bra_action == p->backActionHandle)
	{
        if (bra_get_da_download_active_job_count() > 0)
        {
            bra_dlg_create_dlg (MsfConfirmation,
                BRA_STR_SUSPEND_DOWNLOAD, 
                BRA_STR_YES,
                BRA_STR_NO,
                0, 
                bra_inse_exit_download_confirmation);
        }
        else
        {
      /* no page has been loaded, so exit UI*/
      bra_destroy_ui();
	}
	}
	else if (bra_action == p->selectActionHandle)
	{
        /*download*/
      if (show_download && MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        bra_da_wap_notify_display_list();
        return;
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Home*/
      if (bra_prof_is_profile_loaded (0) == 0)
      {
        bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_ERR_SELECT_PROFILE, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
        return;
      }

      if(!check_url((bra_cmn_get_homepage())->url) || !bra_cmn_url_is_valid((bra_cmn_get_homepage())->url)) 
      {
        bra_dlg_create_dlg (MsfError,
                            BRA_STR_INVALID_URL, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
        return;
		}

      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
			bra_send_request((bra_cmn_get_homepage())->url);
		}
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Bookmarks*/
			bra_bkm_create_bkm_menu();
		}
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Recent pages list*/
      if (bra_prof_is_profile_loaded (0) == 0)
      {        
        bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_ERR_SELECT_PROFILE, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
        return;

      }        
      bra_rpl_create_rpl_menu (TRUE);
     }
#ifdef BRA_CFG_OFFLINE_PAGES
		else if (global_offline_page && (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED))
		{
      /*Offline Pages*/
      bra_ofln_create_ofln_menu();
      }
#endif
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Enter Address*/
      if (bra_prof_is_profile_loaded (0) == 0)
      {
        bra_dlg_create_dlg (MsfWarning,
                            BRA_STR_ERR_SELECT_PROFILE, 
                            BRA_STR_OK, 
                            0,
                            0, 
                            NULL);
        return;
      }
      bra_req_init_address_list();

      for (j = 0; j < BRA_CFG_N_ADDRESS_ITEMS; j++)
      {
        if (bra_req_get_address_item(j) != NULL)
          break;
      }
      if(j < BRA_CFG_N_ADDRESS_ITEMS)
        bra_create_select_url_menu();
      else
        bra_create_url_form(NULL, bra_req_edit_url_response, BRA_WIN_ID_VIEWPORT);
		}
#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
      /*Push Inbox*/
         extern void bra_psl_create_push_inbox(void);
         bra_psl_create_push_inbox();
      }
#endif      
		else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
		{
      /*Settings*/
			bra_create_settings_menu();
		}
#ifdef WAP_MEM_DEBUG
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
      /* memory logging option*/
         bra_create_mem_logging_menu();
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
      /* max memory logging option*/
         bra_create_mem_status_menu(1);
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE(p->windowHandle, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
      /* cur memory logging option*/
         bra_create_mem_status_menu(0);
      }
#endif
	}
}

static void
bra_delete_int_serv_menu (bra_win_t *win)
{
  bra_inse_menu_t *p;

  p = (bra_inse_menu_t *)(win);

  MSF_WIDGET_REMOVE (bra_win_get_screen (), p->windowHandle); 

	MSF_WIDGET_RELEASE (p->windowHandle); 
	MSF_WIDGET_RELEASE (p->selectActionHandle);
	MSF_WIDGET_RELEASE (p->backActionHandle);

  BRA_FREE (p);
}

static void
bra_set_int_serv_menu_in_focus (bra_win_t *win)
{
  bra_inse_menu_t *p;

  p = (bra_inse_menu_t *)(win);

  if (show_download == 1 && bra_get_da_download_job_count() == 0)
  {
    show_download = 0;
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT(p->windowHandle, 0);
  }
  
  /*Make sure the homepage has not changed*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void
bra_create_int_serv_menu ()
{
  bra_inse_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  MsfDeviceProperties prop;
  MSF_UINT8 i = 0;
#ifdef BRA_CFG_OFFLINE_PAGES
  extern kal_bool  global_offline_page;
#endif  

  BRAa_setBearerType(bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID));
  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
	
  /*remove menu key action from screen*/
  bra_view_disable ();
  
  bra_sif_init();

  win = BRA_ALLOCTYPE (bra_inse_menu_t);
  
	win->selectActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK,MsfSelect,1, 0x8000);
	win->backActionHandle = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK,MsfBack,1, 0x8000);
	win->windowHandle = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                             MsfImplicitChoice,
                                             &prop.displaySize,
                                             win->selectActionHandle,
                                             0, /*Element Position*/
                                             MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                             0x8000, /*Property Mask*/
                                             0 /*Default Style*/);
   if (bra_get_da_download_job_count() > 0)
   {
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_DOWNLOAD, 0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_DOWNLOAD,0), 0, TRUE);
     show_download = 1;
   }
   else
   {
     show_download = 0;
   }
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_HOMEPAGE, 0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_HOMEPAGE,0), 0, TRUE);
   HDIa_widgetExtChoiceSetElemFlag(win->windowHandle, i-1, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_BOOKMARKS,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_BOOKMARK,0), 0, TRUE);
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_RECENT_PAGES,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
#ifdef BRA_CFG_OFFLINE_PAGES
   if(global_offline_page)
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_OFFLINE_PAGES,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_OFFLINE_PAGE,0), 0, TRUE);
#endif
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_ENTER_ADDRESS,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_EDIT_ADDRESS,0), 0, TRUE);
#if !defined(__UNIFIED_MSG_SUPPORT__) || defined(BRA_CONFIG_DOUBLE_PUSH_BOX)
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_PUSH_INBOX, 0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_PUSH_INBOX,0), 0, TRUE);
#endif   
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, BRA_STR_SETTINGS,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_SETTING,0), 0, TRUE);
#ifdef WAP_MEM_DEBUG
   {
   MsfStringHandle ms;
   /* memory logging option */
   ms = BRA_STRCONV("Memory Logging");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
   MSF_WIDGET_RELEASE(ms);
   /* max memory status option */
   ms = BRA_STRCONV("Max Mem Status");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
   MSF_WIDGET_RELEASE(ms);
   /* cur memory status option */
   ms = BRA_STRCONV("Cur Mem Status");
   MSF_WIDGET_CHOICE_SET_ELEMENT (win->windowHandle, i++, ms,  0, HDIa_widgetImageGetPredefined(WAP_IMAGE_SW_RECENT_PAGE,0), 0, TRUE);
   MSF_WIDGET_RELEASE(ms);
   }
#endif

	MSF_WIDGET_SET_TITLE(win->windowHandle,BRA_STR_START_TITLE);
	MSF_WIDGET_WINDOW_SET_PROPERTIES(win->windowHandle,MSF_WINDOW_PROPERTY_TITLE);

	MSF_WIDGET_ADD_ACTION(win->windowHandle, win->backActionHandle);
	
  bra_win_show_window (BRA_WIN_ID_INSE,  
                      (bra_win_t*)win, 
                      &pos, 
                      bra_delete_int_serv_menu, 
                      bra_set_int_serv_menu_in_focus,
                      bra_widget_action_int_serv_menu);
}

void
bra_inse_remove_download_item(void)
{
    if (show_download == 1 && bra_get_da_download_job_count() == 0)
    {
        show_download = 0;
        MSF_WIDGET_CHOICE_REMOVE_ELEMENT(((bra_inse_menu_t*)bra_win_get_window(BRA_WIN_ID_INSE))->windowHandle, 0);
    }
}
