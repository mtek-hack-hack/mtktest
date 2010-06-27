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
 * BTMMIBipGprots.h
 *
 * Project:
 * --------
 *   BT BIP MMI
 *
 * Description:
 * ------------
 *   
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

#ifndef __BT_MMI_BIP_GPROTS_H__
#define __BT_MMI_BIP_GPROTS_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifdef __MMI_BT_MTK_SUPPORT__

#if defined(__MMI_BIP_SUPPORT__)

#ifndef BT_MMI_CM_H
#include "BTMMICm.h"
#endif

typedef void (*mmi_bt_bip_send_img_callback) (void *p, U32 result);

/* sending error type */
typedef enum
{
    MMI_BIP_SUCCESS,                /* Success */
    MMI_BIP_ERR_CANCELED_BY_USER,   /* Canceled by user */
    MMI_BIP_ERR_TIMEOUT,            /* BIP Request time out */
    MMI_BIP_ERR_XML_GEN_FAIL,       /* xml generate error */
    MMI_BIP_ERR_FILE_OPEN_FAIL,     /* File OPEN error */
    MMI_BIP_ERR_FILE_READ_FAIL,     /* File Read error */
    MMI_BIP_ERR_FILE_WRITE_FAIL,    /* File Write error */
    MMI_BIP_ERR_DISK_FULL,          /* Disk full */
    MMI_BIP_ERR_ROOT_DIR_FULL,      /* Root dir full */
    MMI_BIP_ERR_REJECT_BY_SERVER,   /* Reject by Server */
    MMI_BIP_ERR_DISCONNECTED,       /* transport layer disconnected */
    MMI_BIP_ERR_BUSY,               /* bipi is busy: sending or getting */
    MMI_BIP_ERR_SCO_REJECT,         /* rejected by SCO */
    MMI_BIP_ERR_INVALID_STATUS,     /* Invalid status */

    MMI_BIP_ERR_LAST    /* the last error */
} mmi_bt_bip_error_enum;

/************************************************************************
    Extern Global Function
*************************************************************************/
extern void mmi_bt_bip_init(void);      /* global bip init function for CM */
extern void mmi_bt_bip_deinit(void);    /* global bip deinit function for CM */
extern void mmi_bt_bip_event_hdlr(msg_type msg_id, void *msg);  /* protocol event hdlr */

extern void mmi_bt_bipr_activate(void);                     /* server activate function for CM */
extern void mmi_bt_bipr_deactivate(void);                   /* server deactivate function for CM */
extern void mmi_bt_bipr_disconnect_client(mmi_bth_bt_addr bd_addr, U32 g_conn_id);      /* server disconnect function for CM */
extern void mmi_bt_bipr_sdp_register_cnf_hdlr(void *msg);   /* server register confirm function for CM */
extern void mmi_bt_bipr_sdp_deregister_cnf_hdlr(void *msg); /* server deregister confirm function for CM */

extern BOOL mmi_bt_bip_server_is_receiving(void);   /* check if BIP responder is sending or recieving data */

extern void mmi_bt_bipi_connect_pull_responder(mmi_bth_bt_addr bd_addr);        /* global bip initiator connect function for CM */

U8 mmi_bt_bip_get_recv_images_cnt(void);
void mmi_bt_bip_set_recv_images_cnt(U8 cnt);

/* adapter API of BIP PUSH and OPP */
typedef void (*mmi_bt_send_file_callback) (void *p, U32 result);
void mmi_bt_send_file_through_BT(S8 *file_path, mmi_bt_send_file_callback callback_f);

#endif /* defined(__MMI_BIP_SUPPORT__) */ 

#endif /* __MMI_BT_MTK_SUPPORT__ */ 
#endif /* __BT_MMI_BIP_GPROTS_H__ */ 

