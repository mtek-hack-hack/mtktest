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
 *	l4c2phb_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between PHB and L4C.
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


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : l4c2phb_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2PHB_STRUCT_H
#define _L4C2PHB_STRUCT_H

#include "l4c2uem_struct.h"

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


typedef struct {
    kal_uint16 index; /* index maintained by PHB*/
    kal_uint8 storage; /* phb_storage_enum; Physical storage*/
    kal_uint8 type; /* amanda add */
    kal_uint16 record_index; /* Record index in physical storage*/
    l4_name_struct alpha_id; /* Alpha identifier*/
    l4_addr_bcd_struct tel_number; /* Telephone number*/
    kal_uint8 cap_cnf_id; /* Capability/Configuration identifier*/
} phb_entry_struct;

typedef struct {
    kal_uint16 no_array;
    kal_uint16 array_size;
    phb_entry_struct *array; /* Array of raw data entry(ies), each element is type of phb_entry_struct.*/
} l4cphb_phb_entry_array_struct;

typedef struct {
    kal_uint8 email_length;
    kal_uint16 record_index; /* Record index in physical storage*/
    kal_uint16 adn_record_index; /* adn record index */
    kal_uint8 email_address[61]; /* email address */
} phb_email_struct;

typedef struct {
    kal_uint16 record_index; /* Record index in physical storage*/
    kal_uint16 adn_record_index; /* adn record index */
    kal_uint8 anr_type; /* ANRA, ANRB or ANRC */
    kal_uint8 aas_id; /* anr alhpha id identifier */
    l4_addr_bcd_struct tel_number; /* Telephone number*/
    kal_uint8 cap_cnf_id; /* Capability/Configuration identifier*/
} phb_anr_struct;

typedef struct {
    kal_uint16 no_array;
    kal_uint16 array_size;
    phb_email_struct *array; /* Array of raw data entry(ies), each element is type of phb_entry_struct.*/
} l4cphb_phb_email_array_struct;

typedef struct {
    kal_uint16 no_array;
    kal_uint16 array_size;
    phb_ln_entry_struct *array; /* Array of raw data entry(ies), each element is type of phb_entry_struct.*/
} l4cphb_phb_ln_entry_array_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 dn_type; /* Dial number type*/
} l4cphb_startup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 adn_size;
    kal_uint16 phb_size;
    kal_uint8 adn_alpha_length;
    kal_uint8 fdn_alpha_length;
    kal_uint8 bdn_alpha_length;
    kal_uint8 msisdn_alpha_length;
    kal_uint8 is_sim_refresh;
} l4cphb_startup_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 adn_size;
    kal_uint16 phb_size;
    kal_uint8 adn_alpha_length;
    kal_uint8 fdn_alpha_length;
    kal_uint8 bdn_alpha_length;
    kal_uint8 msisdn_alpha_length;
    kal_bool is_usim;
    kal_bool is_group_support;
    kal_uint8 anra_support_type;
    kal_uint8 anrb_support_type;
    kal_uint8 anrc_support_type;
    kal_uint8 sne_support_type;
    kal_uint8 email_support_type;
    kal_uint8 group_alpha_length;
    kal_uint8 sne_alpha_length;
    kal_uint8 email_length;
    kal_uint16 anra_size;
    kal_uint16 anrb_size;
    kal_uint16 anrc_size;
    kal_uint16 sne_size;
    kal_uint16 email_size;
    kal_uint16 gas_size;
} l4cphb_startup_phase1_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
} l4cphb_startup_read_next_usim_field_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 num_of_entry;
    phb_anr_struct anr_entry[2000/PHB_ANR_SIZE];
    kal_uint8 access_id;
}l4cphb_startup_read_anr_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 num_of_entry;
    phb_email_struct email_entry[2000/PHB_EMAIL_SIZE];
    kal_uint8 access_id;
}l4cphb_startup_read_email_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint8 num_of_entry;
    phb_entry_struct gas_entry[5];
    kal_uint8 access_id;
}l4cphb_startup_read_gas_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 grp[1000];
    kal_uint8 access_id;
}l4cphb_startup_read_grp_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 num_of_entry;
    phb_entry_struct phb_entry[2000/NVRAM_PHB_SIZE];
    kal_uint8 access_id;
} l4cphb_startup_read_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 access_id;
} l4cphb_startup_read_next_req_struct;

typedef l4cphb_startup_cnf_struct l4cphb_init_ln_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    kal_uint16 index; /* Index of phone number entries*/
    kal_uint16 total; /* Number of entries to read*/
    kal_uint8 storage; /* Specifies storage*/
    kal_uint16 record_index; /* Record index of physical storage*/
} l4cphb_read_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The 'src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint16 total; /* Number of entries*/
} l4cphb_read_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    kal_uint16 total; /* Number of entires to piggyback*/
} l4cphb_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    kal_uint8 index;
    kal_uint8 total; /* Number of entires to piggyback*/
} l4cphb_write_ln_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    kal_uint8 index;
    kal_uint8 total; /* Number of entires to piggyback*/
    kal_uint8 seq_id; /* Sequence id */
} l4cphb_read_ln_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The 'src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint8 total; /* Number of entries*/
    kal_uint8 type;
    kal_bool more_data;
} l4cphb_read_ln_cnf_struct;

typedef l4cphb_write_ln_req_struct l4cphb_delete_ln_req_struct;
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The 'src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint16 total; /* Number of entries*/
    kal_uint8 type;
} l4cphb_write_ln_cnf_struct;
typedef l4cphb_read_cnf_struct l4cphb_delete_ln_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The `src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint16 total; /* Number of entries*/
    kal_uint16 old_index;
} l4cphb_write_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    kal_uint16 index; /* Index of phone number entries*/
    kal_uint16 total; /* Number of entries*/
    kal_uint8 storage;
    kal_uint8 total_piggyback; /* Number of entires to piggyback*/
} l4cphb_delete_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The 'src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint16 total; /* Number of entries*/
    kal_uint16 old_index;
} l4cphb_delete_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint16 total; /* Number of entires to piggyback*/
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    phb_query_method_enum pattern_tag;
    union {
        l4_name_struct alpha_id;
        l4_addr_bcd_struct tel_number;
    } pattern_value;
} l4cphb_search_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The 'src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint16 total; /* Number of entries*/
} l4cphb_search_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    l4_addr_bcd_struct tel_number; /* The telephone number to be approved*/
    kal_uint8 is_retrieve; /* Whether retrieving the hit entry of the given number is required*/
} l4cphb_approve_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The `src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
} l4cphb_approve_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    //kal_uint8 direct_mapping;
    kal_uint16 record_index; /* Index of phone number entries*/
    kal_uint16 total; /* Number of entries to read*/
} l4cphb_read_email_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* The 'src_id' of the corresponding reqest is forwarded back in this field.*/
    kal_uint8 result; /* phb_errno_enum; Operation result*/
    kal_uint16 cause;
    kal_uint16 total; /* Number of entries*/
} l4cphb_read_email_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint16 record_index; /* Index of phone number entries*/
    kal_uint8 group_type;
} l4cphb_set_grp_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id; /* Required for L4C*/
    kal_uint8 result;
    kal_uint16 record_index; /* Index of phone number entries*/
    kal_uint8 group_type;
} l4cphb_set_grp_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 type; /* phb_type_enum; Type of phone number entries*/
    kal_uint16 total; /* Number of entires to piggyback*/
    kal_uint8 update_field;
    phb_anr_struct anra;
    phb_anr_struct anrb;
    phb_anr_struct anrc;
    phb_email_struct email;
    l4_name_struct sne;
    kal_uint8 group_type;
    kal_uint8 hidden_info;
} l4cphb_write_usim_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint16 cause; //johnny?
    kal_uint16 total;
    kal_uint16 old_index; //johnny?  
    kal_uint8 update_field; //johnny?
    phb_anr_struct anra; //johnny?
    phb_anr_struct anrb; //johnny?
    phb_anr_struct anrc; //johnny?
    //l4c_phb_anr_struct anra; //johnny?
    //l4c_phb_anr_struct anrb; //johnny?
    //l4c_phb_anr_struct anrc; //johnny?   
    phb_email_struct email;
    l4_name_struct sne;
    kal_uint8 group_type;
    kal_uint8 hidden_info;
} l4cphb_write_usim_cnf_struct;

#endif


