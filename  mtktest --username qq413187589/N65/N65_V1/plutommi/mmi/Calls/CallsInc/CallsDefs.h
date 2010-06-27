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
 * CallsDefs.h
 *
 * Project:
 * --------
 *   MAUI
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

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Calls_Defs.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : PixTel

   DATE     : Jan 15,02

**************************************************************/
#ifndef _PIXTEL_CALLDEFS_H
#define _PIXTEL_CALLDEFS_H

#define GET_LAST_NUMBER_REQ         mmi_phb_get_last_number_req_struct
#define GET_LAST_NUMBER_RSP         mmi_phb_get_last_number_rsp_struct
#define SET_LAST_NUMBER_REQ         mmi_phb_set_last_number_req_struct
#define SET_LAST_NUMBER_RSP         mmi_phb_set_last_number_rsp_struct
#define DEL_LAST_NUMBER_REQ         mmi_phb_del_last_number_req_struct
#define DEL_LAST_NUMBER_RSP         mmi_phb_del_last_number_rsp_struct

#define RESULTSTRUCT                mmi_cc_set_max_acm_rsp_struct

#define PHB_LN_ENTRY                l4c_phb_ln_entry_struct
#define CALL_LOG_RTCTIMEFORMAT      rtc_format_struct

#define CS_NOTIFYDURATION        1000
#define MAX_PASSWORD_LENGTH      16
#define MAX_GET_STRING_LEN       16

#define TOT_SIZE_OF_ONE_LN_LIST 10

#define TOT_SIZE_OF_DIALED_LIST  MAX_PHB_LN_ENTRY
#define TOT_SIZE_OF_MISSED_LIST  MAX_PHB_LN_ENTRY
#define TOT_SIZE_OF_RECVD_LIST   MAX_PHB_LN_ENTRY
#define TOT_SIZE_OF_CALLS_LIST   MAX_PHB_LN_ENTRY

#ifdef __MMI_CH_MIXED_CALL_LOG__

#if (MAX_PHB_LN_ENTRY > 20)
#ifndef __PHB_LN_SINGLE_COUNT__
#define __PHB_LN_SINGLE_COUNT__
#endif 
#define TOT_SIZE_OF_MIXED_LIST   60
#else /* (MAX_PHB_LN_ENTRY > 20) */ 
#define TOT_SIZE_OF_MIXED_LIST   TOT_SIZE_OF_DIALED_LIST + \
                                 TOT_SIZE_OF_MISSED_LIST + \
                                 TOT_SIZE_OF_RECVD_LIST
#endif /* (MAX_PHB_LN_ENTRY > 20) */ 
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

#endif /* _PIXTEL_CALLDEFS_H */ 

