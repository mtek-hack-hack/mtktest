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
 * l4c_hz_context.h
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
 *============================================================================
 *             HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _L4C_HZ_CONTEXT_H
#define _L4C_HZ_CONTEXT_H

#ifdef __HOMEZONE_SUPPORT__

typedef enum {
    HZ_INIT,
    HZ_SIM_NOT_ALLOW,
    HZ_READY
} hz_sim_status_enum;

typedef enum {
    HZ_SIM_ACCESS_NONE = 0,
    HZ_READ_FILE_INFO_FILE_VID_IDX,
    HZ_READ_FILE_INFO_FILE_HZ_CACHE1_IDX,
    HZ_READ_FILE_INFO_FILE_HZ_CACHE2_IDX,
    HZ_READ_FILE_INFO_FILE_HZ_CACHE3_IDX,
    HZ_READ_FILE_INFO_FILE_HZ_CACHE4_IDX,
    HZ_READ_SIM_FILE_HZ_IDX,
    HZ_READ_SIM_FILE_HZ_CACHE1_IDX,
    HZ_READ_SIM_FILE_HZ_CACHE2_IDX,
    HZ_READ_SIM_FILE_HZ_CACHE3_IDX,
    HZ_READ_SIM_FILE_HZ_CACHE4_IDX,
    HZ_WRITE_SIM_FILE
} hz_sim_access_enum;

typedef struct
{
    kal_uint8 lac[2];
    kal_uint16 cell_id;
} l4c_hz_sim_cache_struct;

typedef struct
{
    kal_uint8 lac[2];
    kal_uint16 cell_id;
    kal_uint8 hz_number; /* 1-4, 0 for not in homezone */
} l4c_hz_dynamic_cache_struct;

typedef struct
{
    kal_bool active_flag;
    kal_bool is_cz;
    kal_uint32 xh;
    kal_uint32 yh;
    kal_uint32 r2h;
    kal_uint8 tag[12];
    kal_uint8 sim_cache_size;
    l4c_hz_sim_cache_struct   sim_cache[21];
} l4c_hz_struct;

typedef struct
{
    hz_sim_status_enum hz_sim_status;

    l4c_hz_struct hz[4];

    l4c_hz_dynamic_cache_struct dynamic_cache[5];
    kal_uint8 dynamic_cache_lastest;
    kal_uint8 dynamic_cache_size;

    hz_sim_access_enum hz_sim_access; 
    kal_uint8 hz_read_sim_cache_iterator;

    kal_bool is_dedicated_mode;
    kal_bool is_pkt_transfer_mode;

    plmn_id_struct currrent_plmn_id;
    kal_uint8 current_lac[2];
    kal_uint16 current_cell_id;
    kal_uint8 current_gsm_status;
    kal_uint8 current_hz_number; /* 1-4, 0 for not in homezone */
    
    kal_bool queue_cb;
    kal_uint32 queue_xc;
    kal_uint32 queue_yc;
    
    kal_bool hz_init_finished;	    
} l4c_hz_context_struct;

#endif

#endif /* l4c_hz_context.h */
