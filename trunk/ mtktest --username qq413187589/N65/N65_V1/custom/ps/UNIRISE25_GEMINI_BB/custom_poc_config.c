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
 * custom_poc_config.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the PoC customization functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"    /* local/peer struct */

#ifdef __POC__

#include "sip_msg_api.h"
#include "sip_ua_api.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "app2sip_struct.h"
#include "app2xdm_struct.h"
#include "mmi2poc_struct.h"
#include "custom_poc_config.h"

/* Presence Subscription Context */
poc_pres_sub_slot_struct poc_sub_slot[POC_MAX_PRES_SUB_NUM];

#ifndef __POC_USE_APP_MEM__
kal_uint32 poc_buf[((POC_MEM_POOL_SIZE+(POC_MAX_PRES_SUB_NUM*POC_PRES_SUB_MEM_LEN)+4)/4)+1];  
#endif

poc_group_file_struct custom_poc_group_file[MAX_POC_GROUP_FILE_NUM];
kal_uint8 custom_poc_entry_mask[POC_MAX_CONTACT_DISPLAY_NUM];
poc_talk_group_file_struct custom_poc_talk_group_file[MAX_POC_TALK_GROUP_FILE_NUM];

mmi_poc_contact_struct custom_mmi_contact_list[MAX_POC_GROUP_FILE_NUM*MAX_POC_GROUPS_PER_FILE_NUM];
mmi_poc_contact_list_disp custom_mmi_contact_list_disp[POC_MAX_CONTACT_DISPLAY_NUM];
kal_uint8 custom_mmi_adhoc_sel_disp[POC_MAX_CONTACT_DISPLAY_NUM]; 
poc_talk_group_struct  custom_mmi_talk_group_list[MAX_POC_TALK_GROUP_FILE_NUM*MAX_POC_TALK_GROUPS_PER_FILE_NUM];   
poc_talk_group_entry_struct custom_mmi_talk_group_entries[POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM];

kal_char	g_poc_adhoc_str[POC_AD_HOC_STR_MAX_LEN];

/*****************************************************************************
* FUNCTION
*  custom_get_poc_max_contact_num 
* DESCRIPTION
*   This function is used to get the max POC contact number.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 custom_get_poc_max_contact_num()
{
   return POC_MAX_CONTACT_DISPLAY_NUM;
}


/*****************************************************************************
* FUNCTION
*  poc_custom_get_client_ua
* DESCRIPTION
*   This function returns SIP User-Agent string.
*
* PARAMETERS
*  none
* RETURNS
*  pointer of SIP User-Agent string
* GLOBALS AFFECTED
*  none
*****************************************************************************/
const kal_char* poc_custom_get_client_ua(void)
{
   return (const kal_char*)POC_UAC_STRING;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_server_ua
* DESCRIPTION
*   This function returns SIP Server string.
*
* PARAMETERS
*  none
* RETURNS
*  pointer of SIP Server string
* GLOBALS AFFECTED
*  none
*****************************************************************************/
const kal_char* poc_custom_get_server_ua(void)
{
   return (const kal_char*)POC_UAS_STRING;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_register_expire
* DESCRIPTION
*   This function returns register expires value. 
*   This value shall be in order of secord.
*
* PARAMETERS
*  none
* RETURNS
*  # of secords
*  -1: use default value
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int32 poc_custom_get_register_expire(void)
{
   return POC_REGISTER_EXPIRE;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_pres_publication_expire
* DESCRIPTION
*   This function returns presence publication expires value. 
*   This value shall be in order of secord.
*
* PARAMETERS
*  none
* RETURNS
*  # of secords
*  -1: use default value
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int32 poc_custom_get_pres_publication_expire(void)
{
   return POC_PRES_PUBLICATION_EXPIRE;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_pres_subscription_expire
* DESCRIPTION
*   This function returns presence subscription expires value. 
*   This value shall be in order of secord.
*
* PARAMETERS
*  none
* RETURNS
*  # of secords
*  -1: use default value
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int32 poc_custom_get_pres_subscription_expire(void)
{
   return POC_PRES_SUBSCRIPTION_EXPIRE;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_conf_info_expire
* DESCRIPTION
*   This function returns conference-info expires value. 
*   This value shall be in order of secord.
*
* PARAMETERS
*  none
* RETURNS
*  # of secords
*  -1: use default value
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int32 poc_custom_get_conf_info_expire(void)
{
   return POC_CONFERENCE_INFO_EXPIRE;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_session_expire
* DESCRIPTION
*   This function returns Session expires value. 
*   This value shall be in order of secord.
*
* PARAMETERS
*  none
* RETURNS
*  # of secords
*  -1: use default value
* GLOBALS AFFECTED
*  none
*****************************************************************************/
kal_int32 poc_custom_get_session_expire(void)
{
   return POC_SESSION_EXPIRE;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_unknown_talker
* DESCRIPTION
*   This function returns string for unknown talker.
*
* PARAMETERS
*  none
* RETURNS
*  pointer of unknown talker string
* GLOBALS AFFECTED
*  none
*****************************************************************************/
const kal_char* poc_custom_get_unknown_talker(void)
{
   return (const kal_char*)POC_UNKNOWN_TALKER;
}

/*****************************************************************************
* FUNCTION
*  poc_custom_set_conference_factory_uri
* DESCRIPTION
*   This function sets the string for Conference-Factory-URI.
*
* PARAMETERS
*  none
* RETURNS
*  pointer of unknown talker string
* GLOBALS AFFECTED
*  none
*****************************************************************************/
void poc_custom_set_conference_factory_uri(kal_char* value)
{
	strncpy(g_poc_adhoc_str, value, POC_AD_HOC_STR_MAX_LEN - 1);
}

/*****************************************************************************
* FUNCTION
*  poc_custom_get_conference_factory_uri
* DESCRIPTION
*   This function returns string for Conference-Factory-URI.
*
* PARAMETERS
*  none
* RETURNS
*  pointer of unknown talker string
* GLOBALS AFFECTED
*  none
*****************************************************************************/
const kal_char* poc_custom_get_conference_factory_uri(void)
{
#if 1
   return (const kal_char*)g_poc_adhoc_str;
#else
/* under construction !*/
#endif
}

/*****************************************************************************
* FUNCTION
*  custom_get_poc_max_pres_subscription_num 
* DESCRIPTION
*   This function is used to get the max POC Presence Subscription Number number.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 custom_get_poc_max_pres_subscription_num()
{
   return POC_MAX_PRES_SUB_NUM;
}

#endif /* __POC__ */
