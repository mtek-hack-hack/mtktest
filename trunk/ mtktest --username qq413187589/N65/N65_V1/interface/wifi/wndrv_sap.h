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
 *  wndrv_sap.h
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
 *  Request Messages: FT/SUPC -> WNDRV
 ****************************************************************************/   
/* Be careful: do not change the sequence of request messages */
MSG_ID_WNDRV_TEST_SET_REQ = WNDRV_MSG_CODE_BEGIN,
MSG_ID_WNDRV_TEST_QUERY_REQ,
MSG_ID_WNDRV_SUPC_DATA_REQ,
MSG_ID_WNDRV_SUPC_INIT_REQ,
MSG_ID_WNDRV_SUPC_DEINIT_REQ,
MSG_ID_WNDRV_SUPC_SITE_SURVEY_REQ,
MSG_ID_WNDRV_SUPC_JOIN_NETWORK_REQ,
MSG_ID_WNDRV_SUPC_DISJOIN_NETWORK_REQ,
MSG_ID_WNDRV_SUPC_COUNTRY_SETTING_REQ,
MSG_ID_WNDRV_SUPC_REMOVE_KEY_REQ,
MSG_ID_WNDRV_SUPC_ADD_KEY_REQ,
MSG_ID_WNDRV_SUPC_PMKID_UPDATE_REQ,
MSG_ID_WNDRV_SUPC_AUTH_STATE_UPDATE_REQ,
MSG_ID_WNDRV_SUPC_BLACKLIST_UPDATE_REQ, // Kinki change for the blacklist
MSG_ID_WNDRV_SUPC_CHIP_POWERON_REQ,
MSG_ID_WNDRV_SUPC_CHIP_POWEROFF_REQ,
MSG_ID_TCPIP_WNDRV_DATA_REQ,
MSG_ID_TCPIP_WNDRV_SETBEARER_REQ,

/****************************************************************************
 *  Confirm Messages: WNDRV -> FT
 ****************************************************************************/   
MSG_ID_WNDRV_TEST_SET_CNF,
MSG_ID_WNDRV_TEST_QUERY_CNF,

/****************************************************************************
 *  Indication Messages: WNDRV -> WNDRV
 ****************************************************************************/   
MSG_ID_WNDRV_SCAN_INDICATION,
MSG_ID_WNDRV_STATISTIC_INDICATION,

/****************************************************************************
 *  Indication Messages: WNDRV_HISR -> WNDRV
 ****************************************************************************/   
MSG_ID_WNDRV_INTERRUPT_IND,

/****************************************************************************
 *  Indication Messages: FLC -> WNDRV
 ****************************************************************************/  
MSG_ID_SOC_WNDRV_DL_SRPDU_RESUME,

/****************************************************************************
 *  Request Messages: MMI -> WNDRV
 ****************************************************************************/  
MSG_ID_WNDRV_MMI_POWEROFF_REQ,
MSG_ID_WNDRV_MMI_POWEROFF_RSP,
