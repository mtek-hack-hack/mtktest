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
 * Filename:
 * ---------
 * JProvNE.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Nokia\Ericsson provisioning.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JPROVNE_H
#define _JPROVNE_H

#if defined (JATAAYU_SUPPORT)
#include <ddl.h>
#ifndef __MMI_JATAAYU_CCA_SUPPORT__

#ifndef _JPROVWAP_H
#error "JProvWap.h should be included first"
#endif 

/*****************************************************************************/

#define PROV_NE_CHARACTERISTIC_NUM           (6)

#define NE_ROOT_TAG                       "characteristic-list"
#define CHARACTERISTIC                    "characteristic"

#define PROXY              "PROXY"
#define PORT               "PORT"
#define BEARER             "BEARER"
#define GPRS_ACCESSPOINTNAME  "GPRS_ACCESSPOINTNAME"
#define PPP_AUTHTYPE       "PPP_AUTHTYPE"
#define PPP_AUTHNAME       "PPP_AUTHNAME"
#define PPP_AUTHSECRET        "PPP_AUTHSECRET"
#define PPP_LOGINTYPE         "PPP_LOGINTYPE"
#define PROXY_AUTHNAME        "PROXY_AUTHNAME"
#define PROXY_AUTHSECRET      "PROXY_AUTHSECRET"
#define PROXY_LOGINTYPE       "PROXY_LOGINTYPE"
#define ISP_NAME           "ISP_NAME"
#define NAME_PARM          "NAME"
#define URL                "URL"
#define CSD_DIALSTRING        "CSD_DIALSTRING"
#define GPRS               "GPRS"
#define GSMCSD             "GSM/CSD"
#define CSD_CALLSPEED         "CSD_CALLSPEED"
#define CSD_CALLTYPE       "CSD_CALLTYPE"
#define ANALOGUE           "ANALOGUE"
#define AUTO               "AUTO"

extern void mmi_prov_NE_handle_settings(S8 *provBuffer, U32 provLength);
extern PROV_RETCODE mmi_prov_NE_insert_settings_parm(TAG *pRoot);
extern PROV_RETCODE mmi_prov_NE_handle_address_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_NE_handle_url_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_NE_handle_name_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_NE_handle_bookmark_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_NE_handle_mmsurl_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_NE_handle_id_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_NE_handle_address_tag(TAG **next_node);

extern void mmi_prov_NE_handle_csd_calltype(ATTRIBUTE *attr_p);
extern void mmi_prov_NE_handle_csd_callspeed(ATTRIBUTE *attr_p);
extern void mmi_prov_NE_handle_csd_dialstring(ATTRIBUTE *attr_p);
extern void mmi_prov_NE_handle_gprs_apn(ATTRIBUTE *attr_p);
extern void mmi_prov_NE_handle_proxy_authname(ATTRIBUTE *attr_p);
extern void mmi_prov_NE_handle_proxy_authsecret(ATTRIBUTE *attr_p);

extern void mmi_prov_NE_handle_WSP_headers(U8 **provBuffer, U32 *provLength);

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ /* #ifndef __MMI_JATAAYU_CCA_SUPPORT__ */

#endif /* defined (JATAAYU_SUPPORT) */ // #if defined (JATAAYU_SUPPORT)
#endif /* _JPROVNE_H */ 

