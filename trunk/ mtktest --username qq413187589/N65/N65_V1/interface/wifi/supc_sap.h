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
 *  supc_sap.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Related message identity definition between FT/SUPC and WNDRV
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
1) adaptation/include/stack_common.h
=================================
#define WNDRV_MSG_CODE_BEGIN       (MSG_ID_???_CODE_BEGIN + MSG_ID_???_CODE_RANGE)
#define WNDRV_MSG_CODE_RANGE       100

typedef enum 
{
   INVALID_SAP = 0,
   ...
   FT_WNDRV_SAP,
   SUPC_WNDRV_SAP,
   ...      
   LAST_SAP_CODE
} sap_type;

2) Add this header file in stack_msg.h
*/

/****************************************************************************
 *  Indication Messages: ABM -> SUPC
 ****************************************************************************/   

MSG_ID_SUPC_ABM_WIFI_INIT_REQ = SUPC_MSG_CODE_BEGIN,
MSG_ID_SUPC_ABM_WIFI_DEINIT_REQ,
MSG_ID_SUPC_ABM_WIFI_CONNECT_REQ,
MSG_ID_SUPC_ABM_WIFI_DISCONNECT_REQ,
MSG_ID_SUPC_ABM_WIFI_AP_LIST_REQ,

MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND,


/****************************************************************************
 *  Indication Messages: WNDRV -> SUPC
 ****************************************************************************/   

MSG_ID_WNDRV_SUPC_DATA_IND,
MSG_ID_WNDRV_SUPC_INIT_CNF,
MSG_ID_WNDRV_SUPC_DEINIT_CNF,
MSG_ID_WNDRV_SUPC_SITE_SURVEY_IND,
MSG_ID_WNDRV_SUPC_NETWORK_CONNECT_IND,
MSG_ID_WNDRV_SUPC_NETWORK_CONNECT_FAIL_IND,
MSG_ID_WNDRV_SUPC_NETWORK_DISCONNECT_IND,
MSG_ID_WNDRV_SUPC_NETWORK_STATISTICS_IND,
MSG_ID_WNDRV_SUPC_PMKID_CANDIDATE_IND,
MSG_ID_WNDRV_SUPC_STATUS_IND,



