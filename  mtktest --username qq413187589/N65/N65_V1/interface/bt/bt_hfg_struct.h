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
 * bt_hfg_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for hfg adp sap
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_HFG_STRUCT_H
#define BT_HFG_STRUCT_H




#ifndef BT_DM_STRUCT_H
#error "bt_dm_struct.h should be included"
#endif
/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#define HFG_CONNECT_GUARD_TIMER         20000 /* 20 sec */
#define HFG_SCO_CONNECT_GUARD_TIMER     5000000  /* 5 sec */

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef enum
{
	hfg_idle, /* hfg_deactivated */
	hfg_activated,
	hfg_connected,
	hfg_sco_connected,

	hfg_activating,
	hfg_deactivating,
	hfg_connecting,
	hfg_disconnecting,
	hfg_sco_connecting,
	hfg_sco_disconnecting
		
} bt_hfg_state;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
} bt_hfg_activate_cnf_struct;


typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
} bt_hfg_deactivate_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
} bt_hfg_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;    
} bt_hfg_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_connect_ind_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_connect_ind_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;    
} bt_hfg_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_disconnect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       connection_id;
} bt_hfg_sco_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16			result;
	kal_uint8 	       connection_id;
} bt_hfg_sco_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       connection_id;
} bt_hfg_sco_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	//bt_dm_addr_struct bt_addr;
	kal_uint8 	       connection_id;
} bt_hfg_sco_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 	       result;
	kal_uint8 	       connection_id;
} bt_hfg_sco_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       connection_id;
} bt_hfg_sco_disconnect_ind_struct;

typedef enum
{
	BT_HFG_RESULT_OK = 0,
	BT_HFG_RESULT_FAIL
	
} BT_HFG_RESULT_ENUM;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_speaker_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    kal_uint32          connection_id;
} bt_hfg_speaker_gain_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_speaker_gain_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_mic_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    kal_uint32          connection_id;
} bt_hfg_mic_gain_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_mic_gain_ind_struct;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/             
                                                                                           
/*****************************************************************************              
* Functions                                                                    
*****************************************************************************/     



#endif//BT_HFG_STRUCT_H

