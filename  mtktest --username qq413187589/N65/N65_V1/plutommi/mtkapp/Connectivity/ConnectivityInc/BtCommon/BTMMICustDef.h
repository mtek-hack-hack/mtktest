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
 * BTMMICustDef.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file to identify different bluetooth solution
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BT_MMI_CUST_DEF_H__
#define __BT_MMI_CUST_DEF_H__


#ifdef __MMI_BT_MTK_SUPPORT__
#ifndef BT_MMI_CM_H
#error "btmmicm.h should be included"
#endif 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

/***************************************************************************** 
* feature compile option definition
*****************************************************************************/
/* prohibit data services while real time service(a2dp) is active */

/***************************************************************************** 
* Definations
*****************************************************************************/
/* MMI BT flag bit-wise flag defination(stored in NVRAM) */
#define MMI_BT_MASK_GUARD        MMI_BTH_MASK_GUARD
#define MMI_BT_MASK_ACTIVATED    MMI_BTH_MASK_ACTIVATED
#define MMI_BT_MASK_VIS          MMI_BTH_MASK_VIS
#define MMI_BT_MASK_AUTH         MMI_BTH_MASK_AUTH
#define MMI_BT_MASK_AUDPATH      MMI_BTH_MASK_AUDPATH

/* MMI BT flag bit-wise ram flag defination(Not stored in NVRAM) */
#define MMI_BT_RAMMASK_IS_SWAP2BT            MMI_BTH_RAMMASK_IS_SWAP2BT
#define MMI_BT_RAMMASK_IS_AUTO_PWR_SWTICH    MMI_BTH_RAMMASK_IS_AUTO_PWR_SWTICH
#define MMI_BT_RAMMASK_IS_READY              MMI_BTH_RAMMASK_IS_READY
#define MMI_BT_RAMMASK_IS_ICON_BLINKING      MMI_BTH_RAMMASK_IS_ICON_BLINKING
#define MMI_BT_RAMMASK_REACH_MAX_ACL_LINK    MMI_BTH_RAMMASK_REACH_MAX_ACL_LINK


/* and the max lenght of BD name is 30 bytes */
/* 10 chinese characters need 30 byte in utf8 encoding */
#define MMI_BT_BD_NAME_LEN                                     MMI_BTH_BD_FNAME_LEN
#define MMI_BT_MAX_PAIRED_DEVICE_LIST                          MMI_BTH_MAX_PAIRED_DEVICE_LIST
#define MMI_BT_MAX_INQUIRY_RESULTS_IN_LIST                     MMI_BTH_MAX_DISCOVERY_RESULTS_IN_LIST

/* allow 10(15) chinese characters or 20(30) english characters  */
/* so for UCS2 encoding, need 40+2(62)(NULL terminate) bytes */
#define MMI_BT_SCR_BD_NAME_LEN                                 (((MMI_BTH_BD_FNAME_LEN-2)/3)*ENCODING_LENGTH*ENCODING_LENGTH+ENCODING_LENGTH)


/* number of supported profiles */
#define MMI_BT_MAX_HOST_SUPPORTED_PROFILE                      MMI_BTH_MAX_HOST_SUPPORTED_PROFILE

/***************************************************************************** 
* Enum
*****************************************************************************/
typedef enum
{
    MMI_BT_NO_CONNECTION = MMI_BTH_NO_CONNECTION,
    MMI_BT_HFP_CONNECTION = MMI_BTH_HFP_CONNECTION,
    MMI_BT_HSP_CONNECTION = MMI_BTH_HSP_CONNECTION,
    MMI_BT_SPP_CONNECTION = MMI_BTH_SPP_CONNECTION,
    MMI_BT_DUN_CONNECTION = MMI_BTH_DUN_CONNECTION,
    MMI_BT_FTP_CONNECTION = MMI_BTH_FTP_CONNECTION,
    MMI_BT_OPP_CONNECTION = MMI_BTH_OPP_CONNECTION,
    MMI_BT_A2DP_CONNECTION = MMI_BTH_A2DP_CONNECTION,
    MMI_BT_AVRCP_CONNECTION = MMI_BTH_AVRCP_CONNECTION,
    MMI_BT_AVRCP_CT_CONNECTION = MMI_BTH_AVRCP_CT_CONNECTION,
    MMI_BT_BPP_CONNECTION = MMI_BTH_BPP_CONNECTION,
    MMI_BT_SIMAP_CONNECTION = MMI_BTH_SIMAP_CONNECTION, 
    MMI_BT_FAX_CONNECTION = MMI_BTH_FAX_CONNECTION,     
    MMI_BT_HID_CONNECTION = MMI_BTH_HID_CONNECTION,         
    MMI_BT_BIP_CONNECTION = MMI_BTH_BIP_CONNECTION,
    MMI_BT_LAST_CONNECTOIN_TYPE = MMI_BTH_LAST_CONNECTOIN_TYPE
} mmi_bt_connection_type;

typedef enum
{
    MMI_BT_STAT_INIT_ON = MMI_BTH_STAT_INIT_ON,
    MMI_BT_STAT_INIT_OFF = MMI_BTH_STAT_INIT_OFF,
    MMI_BT_STAT_DEACTIVATING = MMI_BTH_STAT_DEACTIVATING,
    MMI_BT_STAT_ACTIVATE_SWITCHING = MMI_BTH_STAT_ACTIVATING,
    MMI_BT_STAT_ACTIVATING_WRITE_SCAN_ENABLE = MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_ENABLE,
    MMI_BT_STAT_ACTIVATING_WRITE_SCAN_DISABLE = MMI_BTH_STAT_ACTIVATING_WRITE_SCAN_DISABLE,
    MMI_BT_STAT_IDLE = MMI_BTH_STAT_IDLE,
    MMI_BT_STAT_INQUIRING = MMI_BTH_STAT_INQUIRING,
    MMI_BT_STAT_INQUIR_RES_IND = MMI_BTH_STAT_INQUIR_RES_IND,
    MMI_BT_STAT_BONDING = MMI_BTH_STAT_BONDING,
    MMI_BT_STAT_PAIRING = MMI_BTH_STAT_PAIRING,
    MMI_BT_STAT_SDC_SEARCHING = MMI_BTH_STAT_SDC_SEARCHING,
    MMI_BT_STAT_CONNECTING = MMI_BTH_STAT_CONNECTING,
    MMI_BT_STAT_DEBONDING = MMI_BTH_STAT_DEBONDING,
    MMI_BT_STAT_DEBONDING_ALL = MMI_BTH_STAT_DEBONDING_ALL,
    MMI_BT_STAT_DISCONNECTING = MMI_BTH_STAT_DISCONNECTING,
    MMI_BT_STAT_DISCONNECTING_2ND_HFG = MMI_BTH_STAT_DISCONNECTING_2ND_HFG,
    MMI_BT_STAT_AUDIO_CON_ESTAB = MMI_BTH_STAT_AUDIO_CON_ESTAB,
    MMI_BT_STAT_PASSKEY_IND = MMI_BTH_STAT_PASSKEY_IND,
    MMI_BT_STAT_PASSKEY_RES = MMI_BTH_STAT_PASSKEY_RES,
    MMI_BT_STAT_SDC_REFRESHING = MMI_BTH_STAT_SDC_REFRESHING,
    MMI_BT_STAT_RELEASE_ALL_CONNECTION = MMI_BTH_STAT_RELEASE_ALL_CONNECTION,
    MMI_BT_STAT_RELEASE_DEV_CONNECTION = MMI_BTH_STAT_RELEASE_DEV_CONNECTION,
    MMI_BT_STAT_RELEASE_OPP_CONNECTION = MMI_BTH_STAT_RELEASE_OPP_CONNECTION,
    MMI_BT_STAT_RELEASE_FTP_CONNECTION = MMI_BTH_STAT_RELEASE_FTP_CONNECTION,
    MMI_BT_STAT_RELEASE_SPP_CONNECTION = MMI_BTH_STAT_RELEASE_SPP_CONNECTION,
    MMI_BT_STAT_RELEASE_DUN_CONNECTION = MMI_BTH_STAT_RELEASE_DUN_CONNECTION,
    MMI_BT_STAT_HFP_DEACTIVATING = MMI_BTH_STAT_HFP_DEACTIVATING,
    MMI_BT_STAT_A2DP_DEACTIVATING = MMI_BTH_STAT_A2DP_DEACTIVATING,
    MMI_BT_STAT_PANIC_RECOVERING = MMI_BTH_STAT_PANIC_RECOVERING,
    MMI_BT_STAT_ACTIVATING_SIMAP = MMI_BTH_STAT_ACTIVATING_SIMAP,
    MMI_BT_STAT_DEACTIVATING_SIMAP = MMI_BTH_STAT_DEACTIVATING_SIMAP
	
    
} mmi_bt_state_enum;

#endif /* __BT_MMI_CUST_DEF_H__ */ /* end of __BT_MMI_CUST_DEF_H__ */

