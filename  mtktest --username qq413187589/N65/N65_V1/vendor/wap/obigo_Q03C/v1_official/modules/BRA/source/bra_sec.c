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

#include "bra_cfg.h"
#ifdef BRA_CONFIG_SECURITY
#include "bra_cmn.h"
#include "bra_win.h"
#include "bra_sif.h"
#include "msf_int.h"
#include "msf_wid.h"

#include "sec_if.h"
#include "sec_cfg.h"

/************************************************************
 * Local Types
 ************************************************************/

/* menu type*/
typedef struct {
  MsfWindowHandle window;
  MsfActionHandle accept;
  MsfActionHandle back;
} bra_sec_menu_t;

/************************************************************
 * Function definitions
 ************************************************************/

static void
bra_sec_delete_sec_menu (bra_win_t *win)
{
  bra_sec_menu_t *p;
  p = (bra_sec_menu_t *)(win);

 	MSF_WIDGET_REMOVE (bra_win_get_screen (), p->window); 

	MSF_WIDGET_RELEASE (p->window); 
	MSF_WIDGET_RELEASE (p->accept);
	MSF_WIDGET_RELEASE (p->back);

  BRA_FREE (p);

}

static void
bra_sec_action_sec_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
  bra_sec_menu_t *p;
  int i = 0;

  p = (bra_sec_menu_t *)(win);

  if (bra_action == p->back)
  {
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
  }
  else if (bra_action == p->accept)
  {
#if (defined SEC_CFG_WTLS_CLASS_3) || (defined SEC_CFG_TLS) || (defined SEC_CFG_CAN_SIGN_TEXT)

    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*View Certificates*/
      SECif_viewCertNames(MSF_MODID_BRA, bra_sif_get_brs_id (), SEC_GET_USER_CERT | SEC_GET_ROOT_CERT );
    }
    else 
#endif
#if (defined SEC_CFG_WTLS_CLASS_3) || (defined SEC_CFG_TLS)
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Change Authentication Pin*/
      SECif_changePin(MSF_MODID_BRA, bra_sif_get_brs_id (), SEC_AUTHENTICATION_KEY);
    }
    else 
#endif
#if (defined SEC_CFG_CAN_SIGN_TEXT)
    if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Change SignText Pin*/
      SECif_changePin(MSF_MODID_BRA, bra_sif_get_brs_id (), SEC_NON_REPUDIATION_KEY);
    }
    else 
#endif
      if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*Session Info*/
        if (bra_sif_sec_info_available () > 0)
          SECif_viewSessionInfo(MSF_MODID_BRA, bra_sif_get_brs_id (), bra_sif_get_security_id ());
      }
      else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
      {
        /*View current Certificate*/
        if (bra_sif_sec_cert_available () > 0)
          SECif_viewCurrentCert(MSF_MODID_BRA, bra_sif_get_brs_id (), bra_sif_get_security_id ());
      }
#if (defined SEC_CFG_CAN_SIGN_TEXT && defined SEC_CFG_STORE_CONTRACTS)
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Contracts*/
      SECif_viewContracts(MSF_MODID_BRA, bra_sif_get_brs_id ());
    }
#endif
#ifdef BRA_CONFIG_TEST
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Clear Sessioninfo*/
      SECif_sessionClear(MSF_MODID_BRA, bra_sif_get_brs_id ());
    }
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Generate RSA Auth. keys*/
      SECif_generateKeyPair(MSF_MODID_BRA, bra_sif_get_brs_id (), SEC_AUTHENTICATION_KEY, SEC_TLS_CERT_RSA_SIGN);
    }
    else if (MSF_WIDGET_CHOICE_GET_ELEM_STATE (p->window, i++) & MSF_CHOICE_ELEMENT_SELECTED)
    {
      /*Generate DSS SignText keys*/
      SECif_generateKeyPair(MSF_MODID_BRA, bra_sif_get_brs_id (), SEC_NON_REPUDIATION_KEY, SEC_TLS_CERT_RSA_SIGN);
    }
#endif
#endif
  }
     
}

/*
 * This function creates the security options menu.
 *
 * Note! This function is only availabe when the Security 
 *       package is used.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bra_sec_create_menu (void)
{
  bra_sec_menu_t *win;
  MsfPosition pos = BRA_CFG_MENU_POS;
  int i = 0;
  MsfDeviceProperties prop;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  
  win = BRA_ALLOCTYPE (bra_sec_menu_t);

	win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                         BRA_STR_ACCEPT,
                                         MsfSelect,
                                         1, 
                                         0x8000);
	win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, 
                                       BRA_STR_BACK,
                                       MsfBack,
                                       1, 
                                       0x8000);
	win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA,
                                       MsfImplicitChoice,
												               &prop.displaySize,
												               win->accept,
                                       0, /*Element Position*/
                                       MSF_CHOICE_ELEMENT_STRING_1, /*Bit Mask*/
                                       0x8000, /*Property Mask*/
                                       0 /*Default Style*/);

#if (defined SEC_CFG_WTLS_CLASS_3) || (defined SEC_CFG_TLS) || (defined SEC_CFG_CAN_SIGN_TEXT)
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CERTIFICATES, 0, bra_cmn_get_list_num_image(i), 0, TRUE);
  i++;
#endif

#if (defined SEC_CFG_WTLS_CLASS_3) || (defined SEC_CFG_TLS)
  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CHANGE_AUTH_PIN,   0, bra_cmn_get_list_num_image(i), 0, TRUE);
  i++;
#endif

#if (defined SEC_CFG_CAN_SIGN_TEXT)
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CHANGE_SIGN_TEXT_PIN,   0, bra_cmn_get_list_num_image(i), 0, TRUE);
	i++;
#endif

	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_SESSION_INFO, 0, bra_cmn_get_list_num_image(i), 0, TRUE);
	i++;
  if (bra_sif_sec_info_available () == 0)
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, (i - 1), MSF_CHOICE_ELEMENT_DISABLED);

	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CURENT_CERT,  0, bra_cmn_get_list_num_image(i), 0, TRUE);
	i++;
  if (bra_sif_sec_cert_available () == 0)
    MSF_WIDGET_CHOICE_SET_ELEM_STATE (win->window, (i - 1), MSF_CHOICE_ELEMENT_DISABLED);

#if (defined SEC_CFG_CAN_SIGN_TEXT && defined SEC_CFG_STORE_CONTRACTS)
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, BRA_STR_CONTRACTS,    0, bra_cmn_get_list_num_image(i), 0, TRUE);
	i++;
#endif
#ifdef BRA_CONFIG_TEST
	MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_SEC_CLEAR_SESSION,    0, 0, 0, TRUE);
#if( (defined(SEC_CFG_WTLS_CLASS_3) && defined(SEC_CFG_WTLS)) || defined(SEC_CFG_TLS)||defined(SEC_CFG_CAN_SIGN_TEXT) )
   {
     MsfStringHandle ms;
     ms = BRA_STRCONV("Generate Auth. Keys");
	  MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, ms,    0, 0, 0, TRUE);
     MSF_WIDGET_RELEASE(ms);
     ms = BRA_STRCONV("Generate SignText Keys");
     MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, ms,    0, 0, 0, TRUE);
     MSF_WIDGET_RELEASE(ms);
   }
#endif
#endif
	MSF_WIDGET_SET_TITLE (win->window,BRA_STR_SECURITY);
	MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window,MSF_WINDOW_PROPERTY_TITLE);
  
	MSF_WIDGET_ADD_ACTION (win->window, win->back);

   /*Show dialog*/
  bra_win_show_window (BRA_WIN_ID_SEC_MENU, 
                    (bra_win_t*)win, 
                    &pos, 
                    bra_sec_delete_sec_menu, 
                    NULL,
                    bra_sec_action_sec_menu);
}

#endif /*BRA_CONFIG_SECURITY */


