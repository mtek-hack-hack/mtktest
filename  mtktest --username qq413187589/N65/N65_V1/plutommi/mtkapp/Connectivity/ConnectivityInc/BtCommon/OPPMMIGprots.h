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
 * OPPMMIGprots.h
 *
 * Project:
 * --------
 *   MMI
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
#ifdef __MMI_OPP_SUPPORT__

#ifndef __OPP_MMI_GPROTS_H__
#define __OPP_MMI_GPROTS_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

/***************************************************************************** 
* Definations
*****************************************************************************/

/*****************************************/
/* Error cause for Object Send error     */
/****************************************/
typedef enum
{

    MMI_OPP_ERR_SUCCESS,    /* Success */
    MMI_OPP_ERR_USER,       /* User termanited */
    MMI_OPP_ERR_TIMEOUT,    /* OPP Response time out */
    MMI_OPP_ERR_BAD_FILE,   /* File operating error */
    MMI_OPP_ERR_EMPTY_FILE, /* File operating error */
    MMI_OPP_ERR_REJECT,     /* Reject by Server */
    MMI_OPP_ERR_BIDIR,      /* Bidirection connection. Not support currently */
    MMI_OPP_ERR_DISCONNECT, /* Under layer disconnect */
    MMI_OPP_ERR_SENDING     /* Under layer disconnect */
} MMI_OPP_SND_ERR_TYPE;

/************************************/
/* Error cause for Received object  */
/* Notify applications              */
/***********************************/
typedef enum
{

    MMI_OPP_NFY_SUCCESS,                    /* Success and file removed */
    MMI_OPP_NFY_UNRECOGNIZED,               /* Unrecognized type for object */
    MMI_OPP_NFY_MOVE_FAIL,                  /* Application move object fial. */
    MMI_OPP_NFY_DISK_FULL,                  /* Disk full. */
    MMI_OPP_NFY_CONNECTION_DISCONNECTED,    /* Failure occurs in bluetooth connection disconnected */
    MMI_OPP_NFY_CONNECTION_BUSY,

    MMI_OPP_NFY_LAST    /* This is the last error type */
} MMI_OPP_NFY_TYPE;

/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/
#define OPPC_PROG_UPD_DUR               (30000)


/* Type for application callback function pointer */
typedef void (*mmi_opp_sendobj_callback_fptr) (void *, U32);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#if defined(__MMI_BT_MTK_SUPPORT__)
/* Used for OPP client */
extern void mmi_opp_entry_opp_device_discovery(void);
extern MMI_OPP_SND_ERR_TYPE mmi_opp_discovery_device(S8 *path, mmi_opp_sendobj_callback_fptr fp);
extern void mmi_opp_fmgr_forward_to_opp_callback(void *buf_p, U32 result);

/* Used for OPP server */
extern void mmi_opp_entry_idle_notify_scr(void);
extern void mmi_opp_entry_idle_notify_scr_keylock(U16 lsk_img_id, U16 lsk_str_id, U16 rsk_img_id, U16 rsk_str_id);
extern U8 mmi_opp_get_recv_files_cnt(void);
extern void mmi_opp_notify_recv_err(MMI_OPP_NFY_TYPE cause);

#endif
#endif /* __OPP_MMI_GPROTS_H__ */ 

#endif /* __MMI_OPP_SUPPORT__ */ 


#if defined __MMI_OPP_SUPPORT__ || defined __MMI_BIP_SUPPORT__

/* APIs used in IdleApp.c */
U8 mmi_bt_get_recv_files_cnt(void);
void mmi_bt_entry_idle_notify_scr(void);

#endif

