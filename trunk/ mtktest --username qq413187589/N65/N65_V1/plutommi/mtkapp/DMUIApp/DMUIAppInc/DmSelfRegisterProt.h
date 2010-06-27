/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*	DmSelfRegisterProt.h
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file for DM Self-Register application internal header file.
*
* Author:
* -------
*	Mude Lin (MBJ06016)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/
#ifndef _DM_SELF_REGISTER_PROT_H_
#define _DM_SELF_REGISTER_PROT_H_

#include "MMI_features.h"

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#include "MMIDataType.h"
#include "nvram_user_defs.h"

#define DM_SR_SCR_PORT 					16998
#define DM_SR_DES_PORT 					16998
#define DM_SR_CMCC_OP_NUM_1				"46000"
#define DM_SR_CMCC_OP_NUM_2				"46002"
#define DM_SR_OP_NUM_LEN				5
#define DM_SR_REPEAT_TIMES				0

#define DM_SR_MAX_SMS_LEN				134 

#define DM_SR_IMSI_SIZE					17
#define DM_SR_IMEI_SIZE					16
#define DM_SR_MANUFACTURER_SIZE			30
#define DM_SR_DEVICE_MODEL_SIZE			30
#define DM_SR_SOFTWARE_VERSION_SIZE		30

#define DM_SR_REPEAT_SEND_SMS_TIME		500

#define DM_SR_SMS_HEADER				"IMEI:"

typedef struct
{
	S8 des_number[NVRAM_EF_DM_SR_NUMBER_SIZE];
	S8 IMSI_number[DM_SR_IMSI_SIZE];
	S8 IMEI_string[DM_SR_IMEI_SIZE];
	S8 manufacture_name[DM_SR_MANUFACTURER_SIZE];
	S8 device_model[DM_SR_DEVICE_MODEL_SIZE];
	S8 software_version[DM_SR_SOFTWARE_VERSION_SIZE];
	U8 pre_delivery_repy_states[2];
	U8 is_self_reg_succuss;
	U8 is_need_reset_delivery_states;
	U8 check_get_info_type;
	U8 repeat_send_sms_times;
}mmi_dm_sr_info_struct;

typedef enum
{
	DM_SR_GET_IMEI_REQ = 0,
	DM_SR_GET_MANUFACTOR_REQ,
	DM_SR_GET_DEVICE_MODEL_REQ,
	DM_SR_GET_SOFTWARE_VERSION_REQ,
	DM_SR_GET_INFO_REQ_TOTAL
}mmi_dm_sr_get_info_type_enum;

#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#endif /* _DM_SELF_REGISTER_PROT_H_ */
