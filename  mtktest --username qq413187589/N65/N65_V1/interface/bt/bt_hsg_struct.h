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
 * bt_hsg_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for hsg adp sap
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_HSG_STRUCT_H
#define BT_HSG_STRUCT_H


/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef enum
{
	hsg_idle, /* hsg_deactivated */
	hsg_activated,
	hsg_connected,
	hsg_sco_connected,

	hsg_activating,
	hsg_deactivating,
	hsg_connecting,
	hsg_disconnecting,
	hsg_sco_connecting,
	hsg_sco_disconnecting
		
} bt_hsg_state;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
} bt_hsg_activate_cnf_struct;


typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
} bt_hsg_deactivate_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
} bt_hsg_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16        result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_connect_ind_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16        result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_connect_ind_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16        result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hsg_disconnect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hsg_speaker_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    kal_uint32          connection_id;
} bt_hsg_speaker_gain_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hsg_speaker_gain_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hsg_mic_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    kal_uint32          connection_id;
} bt_hsg_mic_gain_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hsg_mic_gain_ind_struct;


typedef enum
{
	BT_HSG_RESULT_OK = 0,
	BT_HSG_RESULT_FAIL
} BT_HSG_RESULT_ENUM;


/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/             
                                                                                           
/*****************************************************************************              
* Functions                                                                    
*****************************************************************************/     



#endif//BT_HSG_STRUCT_H

