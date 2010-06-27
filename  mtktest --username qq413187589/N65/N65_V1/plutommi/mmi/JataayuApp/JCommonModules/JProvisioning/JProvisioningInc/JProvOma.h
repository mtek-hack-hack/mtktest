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
 * JProvOma.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for OMA OTA provisioning specific.
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

#ifndef _JPROVOMA_H
#define _JPROVOMA_H

#if defined (JATAAYU_SUPPORT)
#include <ddl.h>
#ifndef __MMI_JATAAYU_CCA_SUPPORT__

#ifndef _JPROVWAP_H
#error "JProvWap.h should be included first"
#endif 

#define PROV_APPLICATION_SUPPORTED_NUM       (2)
#define PROV_OMA_CHARACTERISTIC_NUM          (9-5)
#define  PROV_SEC_TYPE_SUPP_NUM              (4)

#define PROV_BYTES_TO_SHIFT_TO_SEC_PARM         (2)
#define PROV_BYTES_TO_SHIFT_TO_MAC_PARM         (11)

#define PROV_OMA_NO_OF_MAC_VALUE_BYTES       (40)

#define OMA_ROOT_TAG       "wap-provisioningdoc"
#define CHARACTERISTIC        "characteristic"

#define PXPHYSICAL            "PXPHYSICAL"
#define PXLOGICAL            "PXLOGICAL"
#define PXAUTHINFO            "PXAUTHINFO"
#define NAPAUTHINFO           "NAPAUTHINFO"
#define PORT               "PORT"
#define RESOURCE           "RESOURCE"
#define BOOTSTRAP            "BOOTSTRAP"
#define NAPDEF           "NAPDEF"
#define APPLICATION               "APPLICATION"

#define NAME_PARM          "NAME"
#define INTERNET           "INTERNET"
#define STARTPAGE          "STARTPAGE"
#define TO_NAPID           "TO-NAPID"
#define PORTNBR               "PORTNBR"
#define SERVICE               "SERVICE"
#define APPID              "APPID"
#define TO_PROXY           "TO-PROXY"
#define URI                "URI"
#define NAP_ADDRESS           "NAP-ADDRESS"
#define NAP_ADDRTYPE       "NAP-ADDRTYPE"
#define CALLTYPE           "CALLTYPE"
#define AUTHTYPE           "AUTHTYPE"
#define AUTHNAME           "AUTHNAME"
#define AUTHSECRET            "AUTHSECRET"
#define LINGER             "LINGER"
#define BEARER             "BEARER"
#define NAPID              "NAPID"
#define PROXY_ID           "PROXY-ID"
#define PROXY_PROVIDER_ID     "PROXY-PROVIDER-ID"
#define PHYSICAL_PROXY_ID     "PHYSICAL-PROXY-ID"

#define PROV_DOMAIN           "DOMAIN"
#define PXADDR             "PXADDR"
#define PXADDRTYPE            "PXADDRTYPE"
#define LINKSPEED          "LINKSPEED"
#define PXAUTH_PW          "PXAUTH-PW"
#define PXAUTH_ID          "PXAUTH-ID"
#define PXAUTH_TYPE           "PXAUTH-TYPE"
#define  MAX_SDU_SIZE         "MAX-SDU-SIZE"

#define GSM_CSD               "GSM-CSD"
#define GSM__CSD            "GSM_CSD"
#define GSM_GPRS           "GSM-GPRS"
#define GSM__GPRS           "GSM_GPRS"

#define  ANALOG_MODEM         "ANALOG-MODEM"
#define AUTOBAUDING           "AUTOBAUDING"
#define ADDR               "ADDR"
#define BRW_APPL           "w2"
#define MMS_APPL           "w4"

#define SEMI_COLAN_SEPARATER  ';'

#define SEC_NETWPIN           "SEC=0"
#define SEC_USERPIN           "SEC=1"
#define SEC_USERNETWPIN       "SEC=2"
#define SEC_USERPINMAC        "SEC=3"

#define PROV_APPLICATION_APP_NAME_LEN     (PROV_PROFILE_PROFILE_NAME_LEN)
#define PROV_APPLICATION_APP_ID_LEN       (16)
#define PROV_PROXY_ID_LEN              (32)
#define PROV_NAP_ID_LEN                (16)
#define PROV_MMSC_ADD_LEN              (PROV_PROFILE_MMSC_URL_LEN)
#define PROV_PHYSICAL_PROXY_ID_LEN        (16)
#define PROV_PX_ADDR_LEN               (40)
#define PROV_PROXY_NAME_LEN               (31)
#define PROV_PX_AUTH_ID_LEN               (16)
#define PROV_PX_AUTH_PWD_LEN           (16)

#define PROV_OMA_MIN_SIZE_REQ          (64)

#define PROV_NO_APPLICATION               (0x00)
#define PROV_BROWSER_APPLICATION       (0x01)
#define PROV_MMS_APPLICATION           (0x02)
/* add other application here in this sequence if needed */

#define PROV_OMA_MIN_PASSWORD_LENGTH      (0x04)        /* check  value ..temp added */
#define PROV_OMA_MAX_PASSWD_LEN           (0x0A)        /* check  value ..temp added */

#define PROV_OMA_IGNORE_OTHER_WAP_APPL    (0x01)
#define PROV_OMA_IGNORE_OTHER_MMS_APPL    (0x02)

#define PROV_OMA_IGNORE_OTHER_TO_NAPID    (0x01)

/* flags for APPLICATION characteristics parm tags */
#define PROV_OMA_APPL_IGNORE_OTHER_ADDR      (0x01)
#define PROV_OMA_APPL_IGNORE_OTHER_TO_NAPID  (0x02)
#define PROV_OMA_APPL_IGNORE_OTHER_TO_PROXY  (0x04)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    U8 app_id[PROV_APPLICATION_APP_ID_LEN];
    U8 application_name[PROV_APPLICATION_APP_NAME_LEN];
    U8 proxy_id[PROV_PROXY_ID_LEN];
    U8 mmsc_address[PROV_MMSC_ADD_LEN];
    U8 nap_id[PROV_NAP_ID_LEN];
    U8 flags;
} application_data;

typedef struct
{
    U32 port;
    U8 connType;
} prov_proxy_port_struct;

typedef struct
{
    U8 physicalProxyID[PROV_PHYSICAL_PROXY_ID_LEN];
    U8 pxAddr[PROV_PX_ADDR_LEN];
    U8 toNapID[PROV_NAP_ID_LEN];
    U8 phyProxyCount;
    U32 port;
    U8 connType;
} prov_phy_proxy_data_struct;

typedef struct prov_physical_proxy_link_struct
{
    prov_phy_proxy_data_struct phyProxyData;
    struct prov_physical_proxy_link_struct *nextPhyProxy_p;
} prov_physical_proxy_struct;

typedef struct
{
    U8 proxy_id[PROV_PROXY_ID_LEN];
    U8 proxy_name[PROV_PROFILE_PROFILE_NAME_LEN];
    U8 homepage_url[PROV_PROFILE_HOMEPAGE_URL_LEN];
    U8 is_invalid_auth_info;
    U8 px_auth_id[PROV_PROFILE_USERNAME_LEN];
    U8 px_auth_pwd[PROV_PROFILE_PASSWORD_LEN];
    prov_physical_proxy_struct *physicalProxy;
} prov_log_proxy_data_struct;

typedef struct prov_logical_proxy_link_struct
{
    prov_log_proxy_data_struct logProxyData;
    struct prov_logical_proxy_link_struct *nextLogProxy_p;
} prov_logical_proxy_struct;

typedef struct
{
    U8 csdDialString[MAX_DIAL_NUM_LEN];
    U8 csdDialNumType;
    U8 callType;
    U32 linkSpeed;
    U32 timeOut;
    U8 dns_ip[4];
} data_account_csd_struct;

#ifdef __MMI_GPRS_FEATURES__
typedef struct
{
    U8 apn[MAX_GPRS_MMI_APN_LEN];
} data_account_gprs_struct;
#endif /* __MMI_GPRS_FEATURES__ */ 

typedef struct
{
    U8 napid[PROV_NAP_ID_LEN];
    U8 name[MAX_DATA_ACCOUNT_NAME_LEN];
    U8 bearer;
    U8 authType;
    U8 userName[PROV_MAX_USER_LEN];
    U8 password[PROV_MAX_PASSWD_LEN];
    union
    {
        data_account_csd_struct csdAccount;
    #ifdef __MMI_GPRS_FEATURES__
        data_account_gprs_struct gprsAccount;
    #endif 
    } dataAccountType;
} prov_data_account_data_struct;

typedef struct prov_napdef_link_struct
{
    prov_data_account_data_struct accountData;
    struct prov_napdef_link_struct *nextNapdef_p;
} prov_napdef_struct;

typedef struct
{
    S8 *secId;
      PROV_RETCODE(*sec_hdlr) (S8 *contentType, S8 *provBuff);
} security_parm_handler_struct;

extern application_data *g_prov_app_brw_p;
extern application_data *g_prov_app_mms_p;

extern prov_data_account_data_struct *g_prov_dataAccountData_p;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void mmi_prov_oma_handle_settings(S8 *provBuffer, U32 provLength, S8 *contentType);
extern void mmi_prov_oma_save_received_settings(S8 *prov_buff_p, U32 prov_buff_len);
extern PROV_RETCODE mmi_prov_oma_insert_settings_parm(TAG *pRoot);

/* security related API's */
extern PROV_RETCODE mmi_prov_oma_handle_netwpin(S8 *contentType, S8 *provBuff);
extern PROV_RETCODE mmi_prov_oma_handle_userpin(S8 *contentType, S8 *provBuff);
extern PROV_RETCODE mmi_prov_oma_handle_usernetwpin(S8 *contentType, S8 *provBuff);
extern PROV_RETCODE mmi_prov_oma_handle_userpinmac(S8 *contentType, S8 *provBuff);
extern PROV_RETCODE mmi_prov_extract_security_data(S8 *contentType, S8 *provBuffer, U32 provLength);
extern void mmi_prov_oma_get_imsi_req(void);
extern void mmi_prov_oma_get_imsi_rsp(void *inMsg);
extern void mmi_prov_oma_entry_enter_pin(void);
extern void mmi_prov_oma_exit_enter_pin(void);
extern void mmi_prov_oma_validate_entered_pin(void);
extern void mmi_prov_oma_pin_length_validation(U8 *text, U8 *cursor, S32 length);

/* APIS's for the various characteristics in the OMA provisioing */
extern PROV_RETCODE mmi_prov_oma_handle_bootstrap_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_oma_handle_napdef_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_oma_handle_pxlogical_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_oma_handle_pxphysical_tag(TAG **next_node);

/* PROV_RETCODE mmi_prov_oma_handle_port_tag(TAG**  next_node); */
extern PROV_RETCODE mmi_prov_oma_handle_port_tag(TAG **nextroot_p, prov_phy_proxy_data_struct **phyProxyData_p);
extern PROV_RETCODE mmi_prov_oma_handle_application_tag(TAG **next_node);

/* PROV_RETCODE mmi_prov_oma_handle_napauthinfo_tag(TAG**  next_node); */
extern PROV_RETCODE mmi_prov_oma_handle_napauthinfo_tag(
                        TAG **nextroot_p,
                        prov_data_account_data_struct **data_account_data_p);
/* PROV_RETCODE mmi_prov_oma_handle_pxauthinfo_tag(TAG **  next_node); */
extern PROV_RETCODE mmi_prov_oma_handle_pxauthinfo_tag(TAG **nextroot_p, prov_log_proxy_data_struct **logProxyData_p);
extern PROV_RETCODE mmi_prov_oma_handle_resource_tag(TAG **next_node);
extern PROV_RETCODE mmi_prov_oma_handle_unsupported_tag(TAG **next_node);

extern void mmi_prov_oma_handle_csd_calltype(ATTRIBUTE *attr_p);
extern void mmi_prov_oma_handle_csd_callspeed(ATTRIBUTE *attr_p);

/* API's for Appilaction characteristic handling */
extern void mmi_prov_oma_show_install_application_settings_dialog(void);
extern void mmi_prov_oma_check_pending_application(void);
extern void mmi_prov_oma_check_pending_application_callback(void);
extern void mmi_prov_oma_handle_install_application(void);
extern PROV_RETCODE mmi_prov_oma_get_application_data(application_data *appData_p);

extern void mmi_prov_oma_add_napdef_info(
                prov_napdef_struct **napdef_data_p,
                prov_data_account_data_struct *accountData_p);
extern void mmi_prov_oma_add_logical_proxy_info(
                prov_logical_proxy_struct **logProxy_p,
                prov_log_proxy_data_struct *logProxyData_p);
extern void mmi_prov_oma_add_physical_proxy_info(
                prov_physical_proxy_struct **phyProxy_p,
                prov_phy_proxy_data_struct *phyProxyData_p);
extern void mmi_prov_oma_add_pxauth_info(
                prov_logical_proxy_struct **logProxy_p,
                prov_log_proxy_data_struct *logProxyData_p);

extern PROV_RETCODE mmi_prov_oma_search_and_fill_proxy_data(application_data *appData_p);
extern PROV_RETCODE mmi_prov_oma_search_physical_proxy(prov_log_proxy_data_struct *logProxy_p);
extern PROV_RETCODE mmi_prov_oma_get_physical_proxy_data(prov_phy_proxy_data_struct *phy_Proxy_p);
extern void mmi_prov_oma_get_logical_proxy_data(prov_log_proxy_data_struct *log_Proxy_p);

extern PROV_RETCODE mmi_prov_oma_compare_phproxy_napdef_napid(prov_phy_proxy_data_struct *phyProxyData_p);
extern PROV_RETCODE mmi_prov_oma_compare_appl_napdef_napid(application_data *appData_p);

#ifdef __MMI_GPRS_FEATURES__
extern void mmi_prov_oma_fill_gprs_data_account_info(
                prov_data_account_data_struct *dataAccountData_p,
                mmi_ps_set_gprs_data_account_req_struct **set_gprs_req_p);
#endif /* __MMI_GPRS_FEATURES__ */ 

extern void mmi_prov_oma_fill_csd_data_account_info(
                prov_data_account_data_struct *dataAccountData_p,
                mmi_cc_set_csd_profile_req_struct **set_csd_req_p);

extern void mmi_prov_oma_free_napdef_info(void);
extern void mmi_prov_oma_free_proxy_info(void);

extern U8 mmi_prov_oma_get_physical_proxy_count(prov_physical_proxy_struct *phyProxy_p);
extern U8 mmi_prov_oma_get_logical_proxy_count(prov_logical_proxy_struct *logProxy_p);

/* check for the redundant parameters */
extern U8 mmi_prov_oma_check_if_redundant_physical_proxy(
            prov_physical_proxy_struct *phyProxy_p,
            prov_phy_proxy_data_struct *phyProxyData_p);
extern U8 mmi_prov_oma_check_if_redundant_napdef(
            prov_napdef_struct *napdef_data_p,
            prov_data_account_data_struct *accountData_p);
extern U8 mmi_prov_oma_check_if_redundant_logical_proxy(
            prov_logical_proxy_struct *logProxy_p,
            prov_log_proxy_data_struct *logProxyData_p);

/* MAUI_00355388 Start */
extern void mmi_prov_oma_update_wap_profile_homepage_url(JC_UINT8 *uri);
extern void mmi_prov_oma_update_mms_profile_mmsc_url(JC_UINT8 *uri);

/* MAUI_00355388 End */

#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
#endif /* defined (JATAAYU_SUPPORT) */ // #if defined (JATAAYU_SUPPORT)
#endif /* _JPROVOMA_H */ 

