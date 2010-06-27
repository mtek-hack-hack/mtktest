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
 * custom_poc_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for include file of POC customization parameters. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_POC_CONFIG_H
#define _CUSTOM_POC_CONFIG_H

#ifdef __POC__

/*===========================================================
 *
 * PoC MMI Configuration Macros
 *
 *===========================================================*/
#define MAX_POC_GROUP_FILE_NUM					1
#define MAX_POC_GROUPS_PER_FILE_NUM				1
#define POC_GROUP_LOCAL_MAX_ENTRIES_NUM 		30
#define POC_MAX_CONTACT_DISPLAY_NUM				MAX_POC_GROUP_FILE_NUM*MAX_POC_GROUPS_PER_FILE_NUM*POC_GROUP_LOCAL_MAX_ENTRIES_NUM
#define MAX_POC_TALK_GROUP_FILE_NUM				5
#define MAX_POC_TALK_GROUPS_PER_FILE_NUM		1
#define POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM 	10

/*===========================================================
 *
 * PoC Protocol Configuration Macros
 *
 *===========================================================*/
 
#define POC_UAC_STRING          "PoC-client/OMA1.0 MTK/v1.0"
#define POC_UAS_STRING          "PoC-serv/OMA1.0 MTK/v1.0"
#define POC_UNKNOWN_TALKER      "Unknown" //(length+null)<=POC_MAX_URI_LEN
#define POC_AD_HOC_STR          "ad-hoc"  //< POC_AD_HOC_STR_MAX_LEN
#define POC_AD_HOC_STR_MAX_LEN 	30

/* Expire macros: 
  * (1) -1 : use default 
  * (2) > 0 : unit is second
  * (3) MUST not set to "zero"
  */
#define POC_REGISTER_EXPIRE          (-1)
#define POC_CONFERENCE_INFO_EXPIRE   (-1)
#define POC_PRES_SUBSCRIPTION_EXPIRE (-1)
#define POC_PRES_PUBLICATION_EXPIRE  (-1)
#define POC_SESSION_EXPIRE           (-1)


/*===========================================================
 *
 * PoC Protocol System Macros (DO NOT change!!)
 *
 *===========================================================*/

#ifdef APPMEM_SUPPORT
#define __POC_USE_APP_MEM__
#endif

#define POC_MEM_POOL_SIZE (20*1024)

/* Max Presence Subscription Number */
/* +1: one-shot subscribe */
#ifndef __POC_NON_RLS__
#define POC_MAX_PRES_SUB_NUM (1+1)
#else
#define POC_MAX_PRES_SUB_NUM (1+POC_MAX_CONTACT_DISPLAY_NUM)
#endif

/* Memory expense per Presence Subscription, DO NOT change */
#define POC_PRES_SUB_MEM_LEN (1300)

extern kal_uint32 custom_get_poc_max_contact_num(void);
extern kal_uint32 custom_get_poc_max_pres_subscription_num(void);

extern const kal_char* poc_custom_get_client_ua(void);
extern const kal_char* poc_custom_get_server_ua(void);
extern const kal_char* poc_custom_get_unknown_talker(void);
extern void poc_custom_set_conference_factory_uri(kal_char* value);
extern const kal_char* poc_custom_get_conference_factory_uri(void);
extern kal_int32 poc_custom_get_register_expire(void);
extern kal_int32 poc_custom_get_pres_publication_expire(void);
extern kal_int32 poc_custom_get_pres_subscription_expire(void);
extern kal_int32 poc_custom_get_conf_info_expire(void);
extern kal_int32 poc_custom_get_session_expire(void);

struct poc_presence_subscribe_req_struct__;

typedef struct
{   
   kal_int32 version;     //version with network
   kal_int32 mmi_version; //version with mmi

   kal_uint8 state;
   kal_bool still_valid;

   kal_uint8 curr_pinfo; //current pinfo index
   kal_uint8 num_pinfo;  //total pinfo

   kal_int32 fd;

} poc_pres_info_struct;

typedef struct poc_pres_sub_slot_struct__
{
   //for storing result/cause for pending notify
   kal_uint8 result;
   kal_int32 cause;

   kal_uint8 id;
   kal_uint8 action;
   kal_uint8 state;
   kal_char  *uri;
   sip_ua_uac_req_subscribe_class    *sub_obj;
   poc_pres_info_struct              *pres_info;
   struct poc_presence_subscribe_req_struct__ *subscribe_req;

} poc_pres_sub_slot_struct;

extern poc_pres_sub_slot_struct poc_sub_slot[POC_MAX_PRES_SUB_NUM];

#ifndef __POC_USE_APP_MEM__
extern kal_uint32 poc_buf[((POC_MEM_POOL_SIZE+(POC_MAX_PRES_SUB_NUM*POC_PRES_SUB_MEM_LEN)+4)/4)+1];  
#endif


typedef struct 
{
   kal_uint8 valid;
   kal_uint8 list_name[POC_MAX_DISP_LEN];
   kal_uint8 no_entries;
   poc_group_entry_struct entries[POC_GROUP_LOCAL_MAX_ENTRIES_NUM];
} poc_group_struct;


typedef struct 
{
   kal_uint8 valid;
   kal_uint8 no_groups;
   poc_group_struct groups[MAX_POC_GROUPS_PER_FILE_NUM];
   kal_uint8   xml_file_name[MAX_POC_GROUP_XML_NAME_LEN];
} poc_group_file_struct;

typedef struct 
{
   kal_uint8 valid;
   kal_uint8 list_uri[POC_MAX_URI_LEN];
   kal_uint8 display_name_lang;
   kal_uint8 display_name[POC_MAX_DISP_LEN];
   kal_uint8 max_participant_count;
   kal_uint8 invite_member;
   poc_group_param_struct default_rule;
   kal_uint8 no_entries;
   poc_talk_group_entry_struct entries[POC_TALK_GROUP_LOCAL_MAX_ENTRIES_NUM];
} poc_talk_group_struct;

typedef struct 
{
   kal_uint8 valid;
   kal_uint8 no_groups;
   poc_talk_group_struct groups[MAX_POC_TALK_GROUPS_PER_FILE_NUM];
   kal_uint8   xml_file_name[MAX_POC_GROUP_XML_NAME_LEN];
} poc_talk_group_file_struct;

typedef struct
{
   kal_bool activity_present;
   kal_uint8 activity; //poc_activity_enum  
   kal_bool mood_present;
   kal_uint8 mood; //poc_mood_enum
}mmi_poc_person_pinfo_struct;

typedef struct
{
   kal_uint8 is_active;
   mmi_poc_person_pinfo_struct person;
} mmi_poc_presence_struct;

typedef struct
{
   kal_uint8 allow_invite;
   kal_uint8 sub_pres;
   poc_pres_authrule_struct auth_rule;
   kal_uint8 uri[POC_MAX_URI_LEN];
   kal_uint8 display_name[POC_MAX_DISP_LEN];
   mmi_poc_presence_struct pres;
} mmi_poc_contact_entry_struct;

typedef struct
{
   kal_uint8 group_id;
   kal_uint8 entry_id;
} mmi_poc_contact_list_disp;

typedef struct
{
   kal_uint8 valid;
   kal_uint8 list_name[POC_MAX_DISP_LEN];
   kal_uint8 no_entries;
   mmi_poc_contact_entry_struct entries[POC_GROUP_LOCAL_MAX_ENTRIES_NUM];
} mmi_poc_contact_struct;


extern poc_group_file_struct custom_poc_group_file[];
extern kal_uint8 custom_poc_entry_mask[];
extern poc_talk_group_file_struct custom_poc_talk_group_file[];

extern mmi_poc_contact_struct custom_mmi_contact_list[];
extern mmi_poc_contact_list_disp custom_mmi_contact_list_disp[];
extern kal_uint8 custom_mmi_adhoc_sel_disp[]; 
extern poc_talk_group_struct  custom_mmi_talk_group_list[];   
extern poc_talk_group_entry_struct custom_mmi_talk_group_entries[];


#endif /* __POC__ */

#endif /* _CUSTOM_POC_CONFIG_H */

