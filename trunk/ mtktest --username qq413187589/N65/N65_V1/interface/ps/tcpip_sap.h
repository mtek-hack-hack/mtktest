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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   tcpip.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   tcpip related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*---------------TCPIP_MSG_CODE_BEGIN---------------------------*/
    MSG_ID_SOC_TCPIP_BEARER_REQ = MSG_ID_TCPIP_CODE_BEGIN,
    MSG_ID_SOC_TCPIP_ATTACH_REQ,
    MSG_ID_SOC_TCPIP_BIND_REQ,
    MSG_ID_SOC_TCPIP_CONNECT_REQ,
    MSG_ID_SOC_TCPIP_DISCONNECT_REQ,
    MSG_ID_SOC_TCPIP_LISTEN_REQ,
    MSG_ID_SOC_TCPIP_ACCEPT_RES,
    MSG_ID_SOC_TCPIP_SEND_REQ,
    MSG_ID_SOC_TCPIP_DETACH_REQ,
    MSG_ID_SOC_TCPIP_SHUTDOWN_REQ,	
    MSG_ID_SOC_TCPIP_SRPDU_RELEASE_RES,
    MSG_ID_SOC_TCPIP_OPTION_REQ,
    MSG_ID_TCPIP_TCM_DATA_IND,
    MSG_ID_TCPIP_PPP_DATA_IND,
    MSG_ID_SOC_TCPIP_SET_ACCT_REQ,/*add for cbm to set net work id*/

    /* DHCP probe host by ARP request */
    MSG_ID_DHCP_TCPIP_ARP_PROBE_REQ,
    MSG_ID_DHCP_TCPIP_ARP_PROBE_CNF,
    MSG_ID_DHCP_TCPIP_ARP_QUERY_REQ,
    MSG_ID_DHCP_TCPIP_ARP_QUERY_CNF,
    MSG_ID_DHCP_TCPIP_GW_ARP_PROBE_REQ,
    MSG_ID_DHCP_TCPIP_GW_ARP_PROBE_CNF,


    /* ABM get bearer information request */
    MSG_ID_ABM_TCPIP_GET_BEARER_INFO_REQ,
    MSG_ID_ABM_TCPIP_GET_BEARER_INFO_CNF,
    
    
    /* Joseph WiFi Modification */
    MSG_ID_TCPIP_WNDRV_DATA_IND,

    /* Flow Control */
    MSG_ID_FLC_TCPIP_UL_TPDU_RESUME,
    MSG_ID_SOC_TCPIP_DL_SRPDU_RESUME,
    MSG_ID_SOC_DL_SRPDU_HIGH_THRESHOLD_HIT,
		
    MSG_ID_TCPIP_CODE_END = MSG_ID_SOC_DL_SRPDU_HIGH_THRESHOLD_HIT,
/*---------------TCPIP_MSG_CODE_END---------------------------*/

