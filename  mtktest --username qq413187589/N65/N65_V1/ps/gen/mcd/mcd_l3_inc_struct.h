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
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES
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
 * MCD_L3_INC_STRUCT_H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _MCD_L3_INC_STRUCT_H
#define _MCD_L3_INC_STRUCT_H

/* 
 * L3 buffers sharing with SMS, SS, CC , 
 * protected by l3_buffer_mutex
 */
#define GET_L3_BUFFER_MUTEX kal_take_mutex(l3_buffer_mutex)
#define RELEASE_L3_BUFFER_MUTEX kal_give_mutex(l3_buffer_mutex)
#define GET_L3_BUFFER_MUTEX_2 kal_take_mutex(l3_buffer_mutex_2)
#define RELEASE_L3_BUFFER_MUTEX_2 kal_give_mutex(l3_buffer_mutex_2)
#define L3_MSG_BUFF_SIZE ((2048+256)/4)
#define L3_PUN_BUFF_SIZE ((2048+256)/4)

extern kal_mutexid l3_buffer_mutex;
extern kal_mutexid l3_buffer_mutex_2;
extern kal_uint32 l3_msg_buff[L3_MSG_BUFF_SIZE];
extern kal_uint32 l3_pun_buff[L3_PUN_BUFF_SIZE];                          
extern kal_uint32 l3_msg_buff_2[L3_MSG_BUFF_SIZE];
extern kal_uint32 l3_pun_buff_2[L3_PUN_BUFF_SIZE];   
typedef struct imeisv_struct
{
	kal_uint8 length;
	kal_uint8 digit0;
	kal_uint8 odd_or_even;
	kal_uint8 identity_type;
	kal_uint8 digit_byte[8];
} imeisv_struct;


typedef struct plmn_id_struct
{
	kal_uint8 mcc2;
	kal_uint8 mcc1;
	kal_uint8 mnc3;
	kal_uint8 mcc3;
	kal_uint8 mnc2;
	kal_uint8 mnc1;
} plmn_id_struct;


typedef struct plmn_id_rat_struct
{
	plmn_id_struct plmn_id;
	kal_uint8 rat;
} plmn_id_rat_struct;


typedef struct lai_struct
{
	plmn_id_struct plmn_id;
	kal_uint8 la_code[2];
} lai_struct;


#endif /*_MCD_L3_INC_STRUCT_H*/
