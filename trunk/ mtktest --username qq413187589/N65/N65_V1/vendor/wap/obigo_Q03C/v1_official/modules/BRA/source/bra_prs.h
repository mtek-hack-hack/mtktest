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
 * bra_prs.h
 *
 * Created by Tomas Mandorf	20021120	15:42
 *
 * 
 * Description:
 *		This file contains code to handle provisioning data.
 *
 */


#ifndef _bra_prs_h
#define _bra_prs_h

#ifndef _bra_cfg_h
#include "bra_cfg.h" 
#endif

#ifdef BRA_CONFIG_PROVISIONING


/**********************************************************************
 * Constants
 **********************************************************************/
#define BRA_PRS_NEW_PINNED_PROV_STAGE_NULL          0
#define BRA_PRS_NEW_PINNED_PROV_STAGE_SHOW_ALERT    1
#define BRA_PRS_NEW_PINNED_PROV_STAGE_WAIT_PIN_CONF 2
#define BRA_PRS_NEW_PINNED_PROV_STAGE_ABORT         3


/**********************************************************************
 * Provisioning Fields Max Length Constants
 **********************************************************************/
#define BRA_MAXCHAR_STR_TITLE            BRA_CFG_MAX_NBR_CHARS_TITLE
#define BRA_MAXCHAR_STR_URL              BRA_CFG_MAX_NBR_CHARS_URL
//#define BRA_MAXCHAR_STR_HOMEURL          BRA_CFG_MAX_NBR_CHARS_URL
//#define BRA_MAXCHAR_STR_MMSURL           BRA_CFG_MAX_NBR_CHARS_URL
#define BRA_MAXCHAR_STR_PROFILE_NAME     40
//#define BRA_MAXCHAR_STR_PX_ADDRESS       
//#define BRA_MAXCHAR_STR_PX_PORT          
//#define BRA_MAXCHAR_STR_PX_SERVICE       
//#define BRA_MAXCHAR_STR_PX_TYPE          
#define BRA_MAXCHAR_STR_PX_AUTH_NAME     30
#define BRA_MAXCHAR_STR_PX_AUTH_SECRET   30
//#define BRA_MAXCHAR_STR_ADR_BEARER       
#define BRA_MAXCHAR_STR_ISP_NAME         31
//#define BRA_MAXCHAR_STR_PPP_AUTHTYPE     
#define BRA_MAXCHAR_STR_PPP_AUTHNAME     31
#define BRA_MAXCHAR_STR_PPP_AUTHPW       31
//#define BRA_MAXCHAR_STR_CSD_CALLTYPE     
//#define BRA_MAXCHAR_STR_CSD_CALLSPEED    
#define BRA_MAXCHAR_STR_CSD_DAILSTRING   20
#define BRA_MAXCHAR_STR_GPRS_APN         99
#define BRA_MAXCHAR_STR_WAP_NAP_ADDR     BRA_MAXCHAR_STR_CSD_DAILSTRING
//#define BRA_MAXCHAR_STR_WAP_NAP_ADDRTYPE 
//#define BRA_MAXCHAR_STR_WAP_APP_APPID    
#define BRA_MAXCHAR_STR_WAP_APP_ADDR     BRA_CFG_MAX_NBR_CHARS_URL
#define BRA_MAXCHAR_STR_WAP_APP_RES_URI  BRA_CFG_MAX_NBR_CHARS_URL
#define BRA_MAXCHAR_STR_WAP_APP_RES_NAME BRA_CFG_MAX_NBR_CHARS_TITLE


void
bra_prs_init (void);

void 
bra_prs_terminate (void);

/*
 * This function continues the installation of provisioning data
 *
 * PARAMETERS
 *
 * data      : Provisioning data (msf_registry_response_t)
 *
 * RETURN    : void
 */
void 
bra_prs_continue (void *data);

/*
 * This functin is called when the BRA module receives provisioining data.
 * This function will display a sequence of dialogs asking the user to 
 * confirm the installation of the provisioning data and to select a profile
 * to install the data in. When this is finished the handling of the data will
 * begin. After an item have been processed a signal to continue will be sent
 * and received in the above function. If the user cancels the installation 
 * process the data will be destroyed
 *
 * PARAMETERS
 *
 * data      : Provisioning data (msf_registry_response_t)
 *
 * RETURN    : void
 */
void
bra_prs_handle_provisining_data (void *data);

int
bra_prs_if_instal_dialog_exist(void);

void
bra_prs_handle_destruy_ui (void);

void
bra_prs_notify_pinned_prov(void *sig);

void
bra_prs_handle_invalid_prov(int type);

void
bra_prs_register_prov_auth(void *sig);

void
bra_prs_cancel_prov_conf(void);

int
bra_prs_get_bra_sim_id(int prs_sim_id);

int
bra_prs_is_insall_new_setting_string(MsfStringHandle text);





#endif /* BRA_CONFIG_PROVISIONING */

#endif /* _bra_prs_h */


