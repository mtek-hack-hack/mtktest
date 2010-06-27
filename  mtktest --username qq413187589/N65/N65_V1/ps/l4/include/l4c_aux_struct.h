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
 *	l4c_aux_struct.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _L4C_AUX_STRUCT_H
#define _L4C_AUX_STRUCT_H

#include "l4c2uem_struct.h"
#include "nvram_common_defs.h"

#ifndef NVRAM_PHB_SIZE
#if defined(__L4_MAX_NAME_60__)
#define NVRAM_PHB_SIZE 116 //same as NVRAM_EF_PHB_SIZE
#else
#define NVRAM_PHB_SIZE 86 //same as NVRAM_EF_PHB_SIZE
#endif
#endif

#ifndef PHB_EMAIL_SIZE
#define PHB_EMAIL_SIZE 66
#endif
#ifndef PHB_ANR_SIZE
#define PHB_ANR_SIZE 49
#endif
#ifndef GAS_MAX_ENTRIES_COUNT
#define GAS_MAX_ENTRIES_COUNT          5
#endif


#define DTMF_SEPARATOR     rmmi_char_p
#define MAX_DTMF_LENGTH    10

#define L4C_DEFAULT_NPI    1
#define L4C_DEFAULT_ODD_EVEN_IND    1

typedef struct
{
   kal_uint8 call_id;
   kal_uint8 call_state;
   kal_uint8 mpty;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4c_call_list_entry_struct;

typedef struct
{
   kal_uint8 length;
   l4c_call_list_entry_struct list[L4C_MAX_CALL_LIST_LEN];
} l4c_call_list_struct;

typedef struct
{
   kal_uint8 type;
   kal_uint8 length;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4c_number_struct;

typedef struct
{
   kal_uint8 type;
   kal_uint8 length;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4c_sub_addr_struct;

typedef struct {
   kal_uint8 storage;
   kal_uint8 type;
   kal_uint16 index;
   kal_uint16 record_index;
   l4c_number_struct tel;
   l4_name_struct alpha_id;
} l4c_phb_entry_struct;

typedef struct {
	 kal_uint8 email_length;
    kal_uint16 record_index; /* Record index in physical storage*/
    kal_uint16 adn_record_index; /* L4 PHB will convert to sfi and record_id */
    kal_uint8 email_address[61]; /* email address */
} l4c_phb_email_struct;

typedef struct {
   kal_uint8 storage;
   kal_uint8 type;
   kal_uint16 index;
   kal_uint16 record_index;
   l4_addr_bcd_struct tel;
   l4_name_struct alpha_id;
} l4c_phb_bcd_entry_struct;

typedef struct
{
	kal_uint16 num_of_entry;
	l4c_phb_bcd_entry_struct	phb_entry[2000/NVRAM_PHB_SIZE];
} l4c_phb_entries_struct;

typedef struct
{
	kal_uint16 num_of_entry;
	l4c_phb_email_struct	email_entry[2000/PHB_EMAIL_SIZE];
} l4c_phb_email_entries_struct;

typedef struct {
    kal_uint16 record_index; /* Record index in physical storage*/
    kal_uint16 adn_record_index; /* adn record index */
    kal_uint8 anr_type; /* ANRA, ANRB or ANRC */
    //kal_uint8 type;
    kal_uint8 aas_id; /* anr alhpha id identifier */
    l4c_number_struct tel_number; /* Telephone number*/
} l4c_phb_anr_struct;

typedef struct {
    kal_uint16 record_index; /* Record index in physical storage*/
    kal_uint16 adn_record_index; /* adn record index */
    kal_uint8 anr_type; /* ANRA, ANRB or ANRC */
    //kal_uint8 type;
    kal_uint8 aas_id; /* anr alhpha id identifier */
    l4_addr_bcd_struct tel_number; /* Telephone number*/
    kal_uint8 cap_cnf_id; /* Capability/Configuration identifier*/
} l4c_phb_bcd_anr_struct;

typedef struct {
#if defined(__VOIP__) || defined(__3G_VIDEO_CALL__)
   kal_uint8 address_type;
   union
   {
      l4c_number_struct tel;
      kal_uint8 uri[VOIP_URI_LEN];
   } address;
#else
   l4c_number_struct tel;
#endif /* defined(__VOIP__) || defined(__3G_VIDEO_CALL__) */
   l4_name_struct alpha_id;
   rtc_format_struct time;
   kal_uint8 count;
   kal_uint8 call_status;
   kal_int32 call_duration;
} l4c_phb_ln_entry_struct;

/* for AT/MMI */
typedef struct {
   kal_uint8   plmn_id[7];
   kal_uint8   status; /*l4c_cops_status_enum*/
} l4c_plmn_info_struct;

typedef struct {
   kal_uint8   plmn_id[7];
   kal_uint8   status; /*l4c_cops_status_enum*/
   kal_uint8 rat;
} l4c_rat_plmn_info_struct;

typedef struct {
   kal_uint16 mid[40];
   kal_uint16 dcs[15];
   kal_uint16 mir[30];
   kal_uint8 mid_mask[40];
   kal_uint8 mir_mask[15];
   kal_uint8 dcs_mask[15];
   kal_uint8 para_ind; /* used in set_cb_mode_req only */

   kal_bool is_all_language_on;

   /* used in get_cb_mode_cnf */
   kal_bool     is_cb_ready;
   kal_bool     is_sim_change;
} l4c_cb_info_struct;

// 030613 mtk00468 add for get sms mailbox number 
typedef struct {
   l4_name_struct name;
   l4c_number_struct number_info;
} l4c_sms_mailbox_info_struct;

typedef struct {
		
    kal_uint32 PWM1_freq_Level_Info[5];
	kal_uint32 PWM1_duty_Level_Info[5]; 
	kal_uint32 PWM2_freq_Level_Info[5]; 
	kal_uint32 PWM2_duty_Level_Info[5];
	kal_uint32 PWM3_freq_Level_Info[5]; 
	kal_uint32 PWM3_duty_Level_Info[5]; 

	kal_uint8   MainLCD_Contrast_Level_Info[15];
	kal_uint8   MainLCD_Bias_Level_Info[5];
	kal_uint8   MainLCD_Linerate_Level_Info[5];
	kal_uint8   MainLCD_Temp_Level_Info[5];
   
	kal_uint8   SubLCD_Contrast_Level_Info[15];
	kal_uint8   SubLCD_Bias_Level_Info[5];
	kal_uint8   SubLCD_Linerate_Level_Info[5];
	kal_uint8   SubLCD_Temp_Level_Info[5];

	kal_uint32   Battery_Level_Info[10];

} 
l4c_hw_profile_struct;

typedef struct l4c_nw_time_zone_time_struct
{
	kal_uint8 year;
	kal_uint8 month;
	kal_uint8 day;
	kal_uint8 hour;
	kal_uint8 min;
	kal_uint8 sec;
	kal_uint8 time_zone;
} l4c_nw_time_zone_time_struct;

typedef struct mmi_at_alarm_info_struct
{
   kal_uint8 alarm_index;
   kal_uint8 recurr;
   rtc_format_struct date_time;
} mmi_at_alarm_info_struct;


#endif /* l4c_aux_struct.h*/


