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
 * bt_dm_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of bluetooth device manager
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_DM_STRUCT_H
#define BT_DM_STRUCT_H

/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#define BT_CNF_RESULT_SUCCESS 		(1)
#define BT_CNF_RESULT_FAILED 			(0)

#define BT_SPP_PROFILE_UUID						(0x1101 )
#define BT_LAP_PROFILE_UUID						(0x1102 )
#define BT_DUN_PROFILE_UUID						(0x1103 )
#define BT_OBEX_IR_MC_SYNC_SERVICE_UUID		    (0x1104 )
#define BT_OBEX_OBJECT_PUSH_SERVICE_UUID		(0x1105 )
#define BT_OBEX_FILE_TRANSFER_UUID				(0x1106 )
#define BT_HS_PROFILE_UUID						(0x1108 )
#define BT_CTP_PROFILE_UUID						(0x1109 )
#define BT_AUDIO_SOURCE_UUID					(0x110A )
#define BT_AUDIO_SINK_UUID						(0x110B )
#define BT_AV_REMOTE_CONTROL_TARGET_UUID		(0x110C )
#define BT_ADVANCED_AUDIO_PROFILE_UUID		    (0x110D )
#define BT_AV_REMOTE_CONTROL_UUID				(0x110E )
#define BT_ICP_PROFILE_UUID						(0x1110 )
#define BT_FAX_PROFILE_UUID						(0x1111 )
#define BT_HSG_SERVICE_UUID				        (0x1112 )
#define BT_PAN_PANU_PROFILE_UUID				(0x1115 )
#define BT_PAN_NAP_PROFILE_UUID					(0x1116 )
#define BT_PAN_GN_PROFILE_UUID					(0x1117 )
#define BT_DIRECT_PRINTING						(0x1118 )
#define BT_OBEX_IMAGING_UUID					(0x111A )
#define BT_OBEX_IMAGING_RESPONDER_UUID		    (0x111B )
#define BT_HF_PROFILE_UUID						(0x111E )
#define BT_HFG_PROFILE_UUID						(0x111F )
#define BT_BASIC_PRINTING						(0x1122 )
#define BT_HID_PROFILE_UUID						(0x1124 )
#define BT_SIM_ACCESS_PROFILE_UUID				(0x112D )
#define BT_OBEX_PBA_PROFILE_UUID				(0x1401 )
#define BT_OBEX_BPPS_PROFILE_UUID				(0x1118 )

/***************************************************************************** 
* Structure 
*****************************************************************************/
typedef struct
{
    kal_uint32 lap;		/* Lower Address Part:  bit 00...23 */
    kal_uint8  uap;      	/* upper Address Part:  bit 24...31 */
    kal_uint16 nap;		/* Non-significant Part: bit 32...47 */
} bt_dm_addr_struct;




/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/             
                                                                                           
/*****************************************************************************              
* Functions                                                                    
*****************************************************************************/     


#endif//BT_DM_STRUCT_H

