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
 * IrdaMMI.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI irda service.
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
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_IRDA_SUPPORT__

/*  Include: MMI header file */
#include "ProtocolEvents.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "SettingProfile.h"     /* ERROR_TONE */
#include "ProfileGprots.h"      /* PlayRequestTone */

/* Trace Header Files */

/* External Device Header Files */
#include "ExtDeviceDefs.h"
#include "IrdaMMIGprots.h"
#include "IrdaMMI.h"
#include "IrdaMMIScr.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 
#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
#include "FileManagerGProt.h"
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#include "vObjects.h"


/*  Include: PS header file */
#ifdef __MTK_TARGET__
#include "Irda.h"
#include "obex_app_enums.h"
#include "app2obex_struct.h"
#include "obex2app_struct.h"
//#include "gprs_flc_kal.h"  /* Flow control buffer fucntion prototype */
//#include "gprs_flc_kal_data_types.h" /* Flow control buffer type def */

/* File Type Categories (sync with file manager) */
#include "FileMgr.h"
// #include "fmt_def.h"  /* Has been included in FileMgr.h */
#endif /* __MTK_TARGET__ */ 

/***************************************************************************** 
* External Variable
*****************************************************************************/

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
extern S8 gIrdaStorageLocation;
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

extern fmgr_filter_struct fmgr_filter[];    /* file type/extension mapping table */
extern S8 nPrintableStr[];                  /* for file name buffer */

/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_IRDA_CONTEX g_mmi_irda_cntx;
MMI_IRDA_CONTEX *const g_mmi_irda_cntx_p = &g_mmi_irda_cntx;

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
irda_is_disk_full_enum gThemeRcvOnDiskFull;
#endif 

/* Register aplication callbacks after received object  */

/* An default vCard for debugging the IrDA transmission */
#ifdef __MMI_IRDA_DEBUG__
static kal_uint8 out_buf[] = 
{
    0x42, 0x45, 0x47, 0x49, 0x4E, 0x3A, 0x56, 0x43, 0x41, 0x52, 0x44, 0x0D, 0x0A,
    0x56, 0x45, 0x52, 0x53, 0x49, 0x4F, 0x4E, 0x3A, 0x32, 0x2E, 0x31, 0x0D, 0x0A,
    0x4E, 0x3B, 0x43, 0x48, 0x41, 0x52, 0x53, 0x45, 0x54, 0x3D, 0x55, 0x54, 0x46, 0x2D, 0x38, 0x3A, 0x44, 0x41, 0x4E,
        0x4E, 0x59, 0x0D, 0x0A,
    0x54, 0x45, 0x4C, 0x3A, 0x30, 0x39, 0x31, 0x30, 0x30, 0x31, 0x32, 0x35, 0x34, 0x37, 0x0D, 0x0A,
    0x45, 0x4E, 0x44, 0x3A, 0x56, 0x43, 0x41, 0x52, 0x44, 0x0D, 0x0A
};
#endif /* __MMI_IRDA_DEBUG__ */ 

/*
 * 
 * extern MMI_IRDA_NFY_TYPE mmi_vobj_irda_receive_ind( void* path_src);
 * MMI_IRDA_NFY_TYPE mmi_irda_play_notify_tone( void * path)
 * {
 * playRequestedTone(MESSAGE_TONE);
 * return MMI_IRDA_NFY_UNRECOGNIZED;
 * }
 * 
 * mmi_irda_obj_notify_fptr reg_notify_app[] = {
 * mmi_irda_play_notify_tone,
 * mmi_vobj_irda_receive_ind
 * };
 */

/* 
 * Initial functions
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_init_cntx
 * DESCRIPTION
 *  This function is to initialize the mmi irda context.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_FUNC_INIT_CNTX);

    /* MMI_IRDA_INIT_CTX(g_mmi_irda_cntx); */

    MMI_IRDA_CTX(act) = MMI_IRDA_ACT_CLOSE;
    MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_UNKNOW;
    MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_UNKNOW;
    MMI_IRDA_CTX(app_callback_fp) = NULL;
    MMI_IRDA_CTX(h_snd) = (FS_HANDLE) NULL;
    MMI_IRDA_CTX(h_recv) = (FS_HANDLE) NULL;
    MMI_IRDA_CTX(h_recv_folder) = (FS_HANDLE) NULL;
    MMI_IRDA_CTX(obj_cntx_p) = NULL;
    MMI_IRDA_CTX(fcnt) = 0;
    MMI_IRDA_CTX(total_obj_len) = 0;
    MMI_IRDA_CTX(remain_put_len) = 0;

    MMI_IRDA_CTX(first_pkt_flag) = MMI_FALSE;
    /* Shall not reset to zero. Maybe screen is still (Reveived N files) */
    /* MMI_IRDA_CTX(recv_file_cnt) = 0; */
    MMI_IRDA_CTX(flag) = 0x00000000;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_init_protocol_event
 * DESCRIPTION
 *  This function is to register protocol event handler.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_init_protocol_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    S16 error = 0;
#endif /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_FUNC_INIT_PROTOCOL_EVENT);

    /* Place here for test recving... */
    /* mmi_irda_ir_open(0xFFFF); */

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
    ReadValue(NVRAM_IRDA_STORAGE, &gIrdaStorageLocation, DS_BYTE, &error);

    if ( (FS_GetDevStatus((UINT) gIrdaStorageLocation , FS_MOUNT_STATE_ENUM) != FS_NO_ERROR) || 
        !(mmi_fmgr_is_drive_letter_valid((S8) gIrdaStorageLocation)))
    {
       gIrdaStorageLocation = (U8) MMI_PUBLIC_DRV;
    }
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

    /* Command Confirm from OBEX */
    SetProtocolEventHandler(mmi_irda_obex_connect_cnf_handler, MSG_ID_OBEX_CONNECT_CNF);
    SetProtocolEventHandler(mmi_irda_obex_put_object_cnf_handler, MSG_ID_OBEX_PUT_OBJECT_CNF);

    /* Data indication from OBEX */
    SetProtocolEventHandler(mmi_irda_obex_connect_ind_handler, MSG_ID_OBEX_CONNECT_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_irda_obex_put_object_ind_handler, MSG_ID_OBEX_PUT_OBJECT_IND);
    SetProtocolEventHandler(mmi_irda_obex_disconnect_ind_handler, MSG_ID_OBEX_DISCONNECT_IND);

    /* H/W close indication */
    SetProtocolEventHandler(mmi_irda_ir_close_ind_handler, MSG_ID_IRDA_CLOSE_IND);
#ifdef __MTK_TARGET__
    SetProtocolEventHandler(mmi_irda_ircomm_connect_handler, MSG_ID_MMI_EQ_IRCOMM_CONNECT_IND);
    SetProtocolEventHandler(mmi_irda_ircomm_discon_handler, MSG_ID_MMI_EQ_IRCOMM_DISCONNECT_IND);
#endif /* __MTK_TARGET__ */ 

    /* Checking Received folder exist */
    MMIIRDA_SET_FLAG(MMIIRDA_MASK_FS_SANITY);
    mmi_irda_init_received_folder();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_init_fs_recover
 * DESCRIPTION
 *  This function is to handle if create received folder fail.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS : NONE.(?)
 *  GLOBALS AFFECTED :(?)
 *****************************************************************************/
void mmi_irda_init_fs_recover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO... */
    /* Shall be implement after FS sanity check mechanism done */

    /* After recover, shall create folder again */
    MMI_IRDA_MAKE_RECV_PATH(nPrintableStr);
    ret = FS_CreateDir((kal_uint16*) nPrintableStr);

    if (ret == FS_NO_ERROR)
    {
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_DISK_FULL);
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
    }
    else if (ret == FS_DISK_FULL)
    {
        /* Remove assert prevent from bother other modules */
        /* mmi_irda_assert(0); */
        MMIIRDA_SET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
        MMIIRDA_SET_FLAG(MMIIRDA_MASK_DISK_FULL);
    }
    else if (ret == FS_ROOT_DIR_FULL)
    {
        /* Remove assert prevent from bother other modules */
        /* mmi_irda_assert(0); */
        MMIIRDA_SET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
        MMIIRDA_SET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
    }
    else
    {
        MMIIRDA_SET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_init_received_folder
 * DESCRIPTION
 *  This function is to create received folder if not exist.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS : NONE.(?)
 *  GLOBALS AFFECTED :(?)
 *****************************************************************************/
void mmi_irda_init_received_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    MMI_IRDA_MAKE_RECV_PATH(nPrintableStr);
    h = FS_Open((kal_uint16*) nPrintableStr, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_DISK_FULL);
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((kal_uint16*) nPrintableStr);

        if (ret == FS_NO_ERROR)
        {
            MMIIRDA_RESET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
            MMIIRDA_RESET_FLAG(MMIIRDA_MASK_DISK_FULL);
            MMIIRDA_RESET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
        }
        else if (ret == FS_DISK_FULL)
        {
            /* Remove assert prevent from bother other modules */
            /* mmi_irda_assert(0); */
            MMIIRDA_SET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
            MMIIRDA_SET_FLAG(MMIIRDA_MASK_DISK_FULL);
        }
        else if (ret == FS_ROOT_DIR_FULL)
        {
            /* Remove assert prevent from bother other modules */
            /* mmi_irda_assert(0); */
            MMIIRDA_SET_FLAG(MMIIRDA_MASK_FOLDER_ERR);
            MMIIRDA_SET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
        }
        else
        {
            /* File system fatal error, has to do sanity check or format FS */
            if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_FS_SANITY) == MMI_TRUE);
            mmi_irda_init_fs_recover();
        }

    }   /* End of error handling */

    /* Only first boot up do FS sanity check */
    MMIIRDA_RESET_FLAG(MMIIRDA_MASK_FS_SANITY);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_ir_open
 * DESCRIPTION
 *  This function is to open infrared H/W.
 * PARAMETERS
 *  duration        [IN]        
 *  (IN) U16 Duration : Infrared H/W open duraion in minute, 0xFFFF means open always(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_ir_open(U16 duration)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    irda_local_para_struct *msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IRDA_CTX(act) != MMI_IRDA_ACT_CLOSE)
    {
        return;
    }

    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_FUNC_OPEN_IR);

    msg_ptr = construct_local_para(sizeof(irda_local_para_struct), TD_UL);

    /* duration = 0xFFFF means always on */
    if (duration == MMI_IRDA_OPEN_ALWAYS)
    {
        msg_ptr->open_time = MMI_IRDA_OPEN_ALWAYS;
    }
    else
    {
        msg_ptr->open_time = duration;
    }

    mmi_irda_send_msg_to_lmp(MSG_ID_IRDA_OPEN, (void*)msg_ptr, NULL);

#endif /* __MTK_TARGET__ */ 

    MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_ir_close
 * DESCRIPTION
 *  This function is to close infra-red H/W.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_ir_close(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * if( MMI_IRDA_CTX(act) != MMI_IRDA_ACT_IDLE )
     * return;
     */
    mmi_irda_obex_snd_disconnect(MMI_IRDA_ERR_USER);

    /* Send IRDA close message to lower layer */
    mmi_irda_send_msg_to_lmp(MSG_ID_IRDA_CLOSE, NULL, NULL);

    /* Clean up padding session (callback, file handler...etc)  */
    mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_USER);

    /* Hide status icon ( Caller will hide status icon itself, it is not necessary now ) */
    /* mmi_irda_scr_irda_close_ind(); */

    /* Clean up irda context, state trans back to MMI_IRDA_CLOSE */
    mmi_irda_init_cntx();

    /* Change state to close in mmi_irda_ir_close_ind_handler() func */
    /* MMI_IRDA_STATE_TRANS( MMI_IRDA_ACT_CLOSE ); */

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_snd_abort
 * DESCRIPTION
 *  This is common function to abort sending object
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_snd_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_SND_ABORT);

    /*
     * Send Disconnect message to OBEX because there is no ABORT interface in between 
     * * Use DISCONNECT instead.
     * * Could not be bidicrectional connection, OBEX module does not support bidirectional connection 
     */
    mmi_irda_obex_snd_disconnect(MMI_IRDA_ERR_USER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_snd_disconnect
 * DESCRIPTION
 *  This is common function to disconnect
 * PARAMETERS
 *  cause       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_snd_disconnect(MMI_IRDA_SND_ERR_TYPE cause)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    obex_disconnect_req_struct *msg_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = construct_local_para(sizeof(obex_disconnect_req_struct), TD_UL);

    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_SND_DISCONNECT);

    if (cause == MMI_IRDA_ERR_SUCCESS)
    {
        msg_ptr->disconnect_reason = OBEX_TRANSMISSION_FINISHED;
    }
    else
    {
        msg_ptr->disconnect_reason = OBEX_USER_CANCELLED;
    }
    mmi_irda_send_msg_to_obex(MSG_ID_OBEX_DISCONNECT_REQ, (local_para_struct*) msg_ptr, NULL);
    /* Deal with terminated a connection */
    mmi_irda_obex_connection_terminated(cause);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_connection_terminated
 * DESCRIPTION
 *  This is common function to deal with obex disconnect
 * PARAMETERS
 *  cause       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_connection_terminated(MMI_IRDA_SND_ERR_TYPE cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_SND_CONNECT_TERM);

    switch (MMI_IRDA_CTX(act))
    {
        case MMI_IRDA_ACT_SND:
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);
            MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_DISCONNECTED;
            break;

        case MMI_IRDA_ACT_RECV:
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);
            MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
            break;

        case MMI_IRDA_ACT_IDLE:
        case MMI_IRDA_ACT_CLOSE:
            /*
             * User terminated, back to idle state, 
             * *  might received disconnect indication for under layer 
             * *  Do nothing...
             */
            break;

        case MMI_IRDA_ACT_BIDIR:
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_RECV);
            MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_DISCONNECTED;
            MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
    #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
            break;
    #endif 

        default:
            MMI_IRDA_LOG_STATE_ERR();
            break;
    }

    if (MMI_IRDA_CTX(h_snd))
    {
        FS_Close(MMI_IRDA_CTX(h_snd));
        MMI_IRDA_CTX(h_snd) = (FS_HANDLE) NULL;
    }

    mmi_irda_obex_close_recv_file_handlers();

    /* Execute application callback function if any */
    if (MMI_IRDA_CTX(app_callback_fp))
    {
        (*(MMI_IRDA_CTX(app_callback_fp))) (MMI_IRDA_CTX(obj_cntx_p), cause);
        MMI_IRDA_CTX(app_callback_fp) = NULL;
    }

    /* Notify MMI Screen */
    mmi_irda_scr_data_stop_ind();
}

/* 
 * Lib functions
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_get_file_name_ext
 * DESCRIPTION
 *  This function is to abstract file name.
 * PARAMETERS
 *  pathfileName        [?]             
 *  type                [IN]            
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
S8 *mmi_irda_get_file_name_ext(S8 *pathfileName, MMI_IRDA_GET_FILE_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NameLength = (U16) mmi_ucs2strlen(pathfileName);
    S16 *UniPathName = (S16*) pathfileName;
    U16 deter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case IRDA_FILE_GET_NAME:
            deter = '\\';
            break;

        case IRDA_FILE_GET_EXT:
            deter = '.';
            break;

        default:
            deter = '\\';
            break;
    }

    while (NameLength > 0)
    {
        NameLength--;
        if (memcmp(UniPathName + NameLength, &deter, 2) == 0)
        {
            break;
        }
    }
    return ((S8*) (UniPathName + NameLength + 1));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_retrieve_put_prog_percentage
 * DESCRIPTION
 *  This function is to retrieve the file put progress.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_irda_retrieve_put_prog_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_irda_assert( ); */
    /* Total length of a object */

    if (MMI_IRDA_CTX(total_obj_len) == 0)
    {
        return 0;
    }

    return (U8) (((double)(MMI_IRDA_CTX(total_obj_len) - MMI_IRDA_CTX(remain_put_len)) /
                  (double)MMI_IRDA_CTX(total_obj_len)) * 100.0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_set_recv_files_cnt
 * DESCRIPTION
 *  This function is to set received files count.
 *  
 *  PARAMETERS: U8 cnt
 *  cnt     [IN]        
 *  RETURNS: viod(?)
 *****************************************************************************/
void mmi_irda_set_recv_files_cnt(U8 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IRDA_CTX(recv_file_cnt) = cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_get_recv_files_cnt
 * DESCRIPTION
 *  This function is to get received files count.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
U8 mmi_irda_get_recv_files_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_IRDA_CTX(recv_file_cnt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_get_cur_action
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
MMI_IRDA_MAJOR_ACT_TYPE mmi_irda_get_cur_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_IRDA_CTX(act);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_is_ircomm_active
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
BOOL mmi_irda_is_ircomm_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMIIRDA_GET_FLAG(MMIIRDA_MASK_IRCOMM_ACTIVE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_is_sending
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
BOOL mmi_irda_is_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IRDA_ACT_SND == MMI_IRDA_CTX(act))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_is_recving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
BOOL mmi_irda_is_recving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IRDA_ACT_RECV == MMI_IRDA_CTX(act))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_retrieve_obj_type
 * DESCRIPTION
 *  This function is to retrieve file type by file extension.
 *  
 *  PARAMETERS:
 *  obj_name        [?]     
 *  (S8 *obj_name) ( IN ) : UCS2, null terminated string(?)
 *  RETURNS:(?)
 *  FMGR_TYPE_XXX(?)
 *****************************************************************************/
U32 mmi_irda_retrieve_obj_type(S8 *obj_name)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i, j;
    S8 *p;
    S8 ext_buf[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = mmi_irda_get_file_name_ext(obj_name, IRDA_FILE_GET_EXT);
    if (!p)
    {
        return FMGR_TYPE_UNKNOW;
    }

    /* kal_wsprintf(ext_buf, "%s", fmgr_filter[i].ext ); */
    memset(ext_buf, 0, sizeof(ext_buf));
    mmi_ucs2_n_to_asc(ext_buf, p, 5 * ENCODING_LENGTH);

    /* make upper */
    for (j = 0; j < 5; j++)
    {
        if (ext_buf[j] != 0)
        {
            if (ext_buf[j] >= 'a')
            {
                ext_buf[j] -= 'a' - 'A';
            }
        }
    }

    for (i = 0; i < FMGR_MAX_FILTER_COUNT; i++)
    {
        if (strcmp((S8*) fmgr_filter[i].ext, (S8*) ext_buf) == 0)
        {
            return fmgr_filter[i].type;
        }
    }

#endif /* __MTK_TARGET__ */ 

    return FMGR_TYPE_UNKNOW;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_notify_register_app
 * DESCRIPTION
 *  This function is to notify proper application after received object.
 *  
 *  PARAMETERS:
 *  path        [?]     
 *  (S8 *path) ( IN ) : UCS2, null terminated string(?)
 *  RETURNS:(?)
 *****************************************************************************/
void mmi_irda_notify_register_app(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * U8 i, cnt_func;
     * cnt_func = sizeof( reg_notify_app ) / sizeof( reg_notify_app[0] );
     * for( i=0; i<cnt_func; i++ )
     * {
     * (reg_notify_app[i])(path_buf);
     * }
     */
    U32 obj_type = mmi_irda_retrieve_obj_type(MMI_IRDA_CTX(obj_name));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* It is application duty to play received tone */

    switch (obj_type)
    {

    #if ( defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__))
    #ifdef __MMI_VCARD__
        case FMGR_TYPE_VCF:
    #endif
    #ifdef __MMI_VCALENDAR__
        case FMGR_TYPE_VCS:
    #endif
    #ifdef __MMI_VBOOKMARK__
        case FMGR_TYPE_URL:
        case FMGR_TYPE_VBM:
    #endif
            mmi_vobj_irda_receive_ind((void*)path, obj_type);
            break;
    #endif /* ( defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)) */ 
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        case FMGR_TYPE_THEME:
            if (gThemeRcvOnDiskFull == DISK_EMPTY)
            {
                mmi_irda_theme_idle_notify_scr((void*)path, (void*)MMI_IRDA_CTX(obj_name));   /* added by shantanu  */
            }
            else if (gThemeRcvOnDiskFull == DISK_FULL)
            {
                gThemeRcvOnDiskFull = DISK_EMPTY;
            }
            break;
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

        default:
            /* mmi_irda_assert(0); */
            mmi_irda_obj_receive_ind((void*)path, (void*)MMI_IRDA_CTX(obj_name));
            break;
    }

}

/*
 * Functions export to other applications
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_send_obj
 * DESCRIPTION
 *  This function is to send a given object.
 *  
 *  PARAMETERS:
 *  obj_p           [?]         object content pointer
 *  len             [IN]        object length
 *  obj_name_p      [?]         object name, Unicode encoding if NULL, will use default object name (MMI_IRDA_SND_DEFAULT_OBJNAME)
 *  fp              [IN]        Callback function when finish
 *  RETURNS: void(?)
 *****************************************************************************/
MMI_IRDA_SND_ERR_TYPE mmi_irda_send_obj(void *obj_p, U32 len, S8 *obj_name_p, mmi_irda_sendobj_callback_fptr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_FUNC_SND_OBJ);

    /* Send message to OBEX task and Change MMI Irda State */
    switch (MMI_IRDA_CTX(act))
    {
        case MMI_IRDA_ACT_CLOSE:    /* open IR and pass through to  MMI_IRDA_ACT_IDLE... */
            /* mmi_irda_ir_open( MMI_IRDA_OPEN_PERIOD ); */
            mmi_irda_scr_open_func();
        case MMI_IRDA_ACT_IDLE:
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_SND);
            MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_CONNECT_WAITING;
            break;

        case MMI_IRDA_ACT_RECV:
    #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_BIDIR);
            MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_CONNECT_WAITING;
            break;
    #else
            return MMI_IRDA_ERR_BIDIR;
    #endif 
        default:
            MMI_IRDA_LOG_STATE_ERR();
    }

    /* Store the object passed by application */
    MMI_IRDA_CTX(obj_cntx_p) = obj_p;
    MMI_IRDA_CTX(h_snd) = (FS_HANDLE) NULL;

    /* Store the total length of object */
    MMI_IRDA_CTX(total_obj_len) = MMI_IRDA_CTX(remain_put_len) = len;

    /* Store the object name if exist */
    memset(MMI_IRDA_CTX(obj_name), 0, sizeof(MMI_IRDA_CTX(obj_name)));
    if (obj_name_p)
    {
        memcpy(MMI_IRDA_CTX(obj_name), obj_name_p, sizeof(MMI_IRDA_CTX(obj_name)) - 1);
    }
    else
    {
        kal_wsprintf((U16*) MMI_IRDA_CTX(obj_name), "%s", MMI_IRDA_SND_DEFAULT_OBJNAME);
    }

    /* Store the callback function if any */
    MMI_IRDA_CTX(app_callback_fp) = fp;

    /* Display Sending screen */
    /* mmi_irda_show_sending_screen(); */

    mmi_irda_send_msg_to_obex(MSG_ID_OBEX_CONNECT_REQ, NULL, NULL);

    return MMI_IRDA_ERR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_send_file_obj
 * DESCRIPTION
 *  This function is to send file object.
 * PARAMETERS
 *  path        [?]             
 *  fp          [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_IRDA_SND_ERR_TYPE mmi_irda_send_file_obj(S8 *path, mmi_irda_sendobj_callback_fptr fp)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_uint32 len;
    S8 *filename_p;
#endif /* __MTK_TARGET__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    PopupNoSupport();
    return MMI_IRDA_ERR_SENDING;
#endif /* __MTK_TARGET__ */ 
    if (mmi_irda_is_ircomm_active() == MMI_TRUE)
    {
        (*(fp)) (NULL, MMI_IRDA_ERR_SENDING);
        return MMI_IRDA_ERR_SENDING;
    }

    /* Change MMI Irda state */
    switch (MMI_IRDA_CTX(act))
    {
        case MMI_IRDA_ACT_CLOSE:    /* open IR and pass through to  MMI_IRDA_ACT_IDLE... */
            /* mmi_irda_ir_open( MMI_IRDA_OPEN_PERIOD ); */
            mmi_irda_scr_open_func();
        case MMI_IRDA_ACT_IDLE:
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_SND);
            MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_CONNECT_WAITING;
            break;

        case MMI_IRDA_ACT_RECV:
    #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_BIDIR);
            MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_CONNECT_WAITING;
            break;
    #else /* __MMI_IRDA_BIDIRECT_ENABLE__ */ 
            /* mmi_irda_obex_connection_terminated( MMI_IRDA_ERR_BIDIR ); */
            (*(fp)) (NULL, MMI_IRDA_ERR_BIDIR);
            return MMI_IRDA_ERR_BIDIR;
    #endif /* __MMI_IRDA_BIDIRECT_ENABLE__ */ 
        case MMI_IRDA_ACT_SND:
            /* Incorrect state, callback and return error */
            (*(fp)) (NULL, MMI_IRDA_ERR_SENDING);
            return MMI_IRDA_ERR_SENDING;

        default:    /* Incorrect state */
            MMI_IRDA_LOG_STATE_ERR();
    }

    /* First, store the callback function if any */
    /* In case send fail, clean up function will be able to callback */
    MMI_IRDA_CTX(app_callback_fp) = fp;

    /* file path is null, return to application */
    if (!path)
    {
        mmi_irda_assert(0); /* assert! for easy debuging */
        mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_BAD_FILE);
        return MMI_IRDA_ERR_BAD_FILE;
    }

#ifdef __MTK_TARGET__

    h = FS_Open((U16*) path, FS_READ_ONLY);

    /* File open error, return to application */
    if (h < 0)
    {
        mmi_irda_assert(0); /* assert! for easy debuging */
        mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_BAD_FILE);
        return MMI_IRDA_ERR_BAD_FILE;
    }

    /* Store the file handler */
    MMI_IRDA_CTX(h_snd) = h;
    MMI_IRDA_CTX(obj_cntx_p) = NULL;

    /* Store the object length (file size) */
    FS_GetFileSize(MMI_IRDA_CTX(h_snd), &len);
    MMI_IRDA_CTX(total_obj_len) = MMI_IRDA_CTX(remain_put_len) = len;

    /*
     * if( len == 0 )
     * {
     */
    /* file will be closed in mmi_irda_obex_connection_terminated() */
    /*
     * mmi_irda_obex_connection_terminated( MMI_IRDA_ERR_EMPTY_FILE );
     * return MMI_IRDA_ERR_EMPTY_FILE;
     * }
     */

    /* Get object name */
    memset(MMI_IRDA_CTX(obj_name), 0, sizeof(MMI_IRDA_CTX(obj_name)));
    filename_p = mmi_irda_get_file_name_ext(path, IRDA_FILE_GET_NAME);
    if (filename_p)
    {
        //S8 unicode_buf[32];
        //memset( unicode_buf, 0, sizeof(unicode_buf) );
        //memcpy( unicode_buf, filename_p, 30 );
        //mmi_ucs2_to_asc(MMI_IRDA_CTX( obj_name ), unicode_buf );
        //      memcpy( MMI_IRDA_CTX( obj_name ), filename_p, sizeof( MMI_IRDA_CTX( obj_name ) ) -2 ); //Priyesh - #276
        //Priyesh - #276
        if (mmi_ucs2strlen((S8*) filename_p) * 2 > (sizeof(MMI_IRDA_CTX(obj_name)) - 2))
        {
            memcpy(
                MMI_IRDA_CTX(obj_name),
                filename_p + (mmi_ucs2strlen((S8*) filename_p) * 2) - (sizeof(MMI_IRDA_CTX(obj_name)) - 2),
                sizeof(MMI_IRDA_CTX(obj_name)) - 2);
        }
        else
        {
            memcpy(MMI_IRDA_CTX(obj_name), filename_p, sizeof(MMI_IRDA_CTX(obj_name)) - 2);
        }
        /* Priyesh - #276 */
    }
    else
    {
        kal_wsprintf((U16*) MMI_IRDA_CTX(obj_name), "%s", MMI_IRDA_SND_DEFAULT_OBJNAME);
    }

    mmi_irda_send_msg_to_obex(MSG_ID_OBEX_CONNECT_REQ, NULL, NULL);

#endif /* __MTK_TARGET__ */ 

    return MMI_IRDA_ERR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_ircomm_disconnect_request
 * DESCRIPTION
 *  This function is to send disconnect request to IRCOMM
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_ircomm_disconnect_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_send_msg_to_ircomm(MSG_ID_IRCOMM_DISCONNECT_REQ, NULL, NULL);
}

/* 
 * Event Handler IRCOMM -> MMI
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_ircomm_connect_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_ircomm_connect_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMIIRDA_SET_FLAG(MMIIRDA_MASK_IRCOMM_ACTIVE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_ircomm_discon_handler
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_ircomm_discon_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMIIRDA_RESET_FLAG(MMIIRDA_MASK_IRCOMM_ACTIVE);
}

/* 
 * Event Handler OBEX -> MMI
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_ir_close_ind_handler
 * DESCRIPTION
 *  This function is event handler for ir hw close indication (MSG_ID_DISCONNECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_ir_close_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clean up padding session (callback, file handler...etc)  */
    mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_USER);

    /* Hide status icon ( Notify IrdaMMIScr ) */
    mmi_irda_scr_irda_close_ind();

    /* Clean up irda context, Change state to MMI_IRDA_ACT_CLOSE */
    mmi_irda_init_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_connect_ind_handler
 * DESCRIPTION
 *  This function is event handler for obex connect indication (MSG_ID_OBEX_CONNECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_connect_ind_handler(void *msg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    obex_connect_rsp_struct *msg_ptr = NULL;
    kal_bool res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_CONNECT_IND_HDLR);

    switch (MMI_IRDA_CTX(act))
    {
        case MMI_IRDA_ACT_CLOSE:
            /* User might close Infrared when IRDA is establishing connecting... */
            res = KAL_FALSE;
            break;

        case MMI_IRDA_ACT_IDLE:
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_RECV);
            MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_CONNECTED;
            break;

        case MMI_IRDA_ACT_SND:
    #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
            MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_BIDIR);
            MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_CONNECTED;
            break;
    #endif 

        case MMI_IRDA_ACT_BIDIR:
        case MMI_IRDA_ACT_RECV:
        default:
            /* Send failed connect response to OBEX task (Only single way transmission is allowed) */
            msg_ptr = construct_local_para(sizeof(obex_connect_rsp_struct), TD_UL);
            msg_ptr->result = KAL_FALSE;
            mmi_irda_send_msg_to_obex(MSG_ID_OBEX_CONNECT_RSP, (local_para_struct*) msg_ptr, NULL);
            MMI_TRACE(MMI_TRACE_ERROR, MMI_IRDA_STATE_ERROR, MMI_IRDA_CTX(act));
            return;
    }

    /* Send success connect response to OBEX task */
    msg_ptr = construct_local_para(sizeof(obex_connect_rsp_struct), TD_UL);
    msg_ptr->result = res;
    mmi_irda_send_msg_to_obex(MSG_ID_OBEX_CONNECT_RSP, (local_para_struct*) msg_ptr, NULL);

    /* Check received folder */
    mmi_irda_init_received_folder();

    /* Notify MMI Screen */
    mmi_irda_scr_data_passing_ind();
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    gThemeRcvOnDiskFull = DISK_EMPTY;
#endif 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_connect_cnf_handler
 * DESCRIPTION
 *  This function is event handler for obex connect confirm (MSG_ID_OBEX_CONNECT_CNF)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_connect_cnf_handler(void *msg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    obex_connect_cnf_struct *recv_msg_ptr;
    obex_put_object_req_struct *msg_ptr = NULL;
    peer_buff_struct *peer_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_CONNECT_CNF_HDLR);

    recv_msg_ptr = (obex_connect_cnf_struct*) msg;

    if (recv_msg_ptr->result == MMI_TRUE)
    {
        /* Connection is established successfully  */
        switch (MMI_IRDA_CTX(act))
        {

        #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
            case MMI_IRDA_ACT_BIDIR:
        #endif 

            case MMI_IRDA_ACT_SND:
            {
                /* The connection is establish for sending object */
                MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_CONNECTED;

                /* g_mmi_irda_cntx_p->remain_put_len = sizeof(out_buf) ; */
                msg_ptr = construct_local_para(sizeof(obex_put_object_req_struct), TD_UL);

                /* send first put packet when connect confirm */
                msg_ptr->pkt_type = OBEX_FIRST_PKT;
                msg_ptr->total_obj_size = MMI_IRDA_CTX(total_obj_len);
                /* kal_wstrcpy((kal_uint16 *)msg_ptr->obj_name,  (kal_uint16 *)MMI_IRDA_CTX(obj_name) ); */
                memcpy(msg_ptr->obj_name, MMI_IRDA_CTX(obj_name), sizeof(msg_ptr->obj_name));
                mmi_irda_send_msg_to_obex(MSG_ID_OBEX_PUT_OBJECT_REQ, (local_para_struct*) msg_ptr, peer_ptr);
                /* Notify MMI Screen */
                mmi_irda_scr_data_passing_ind();
                break;
            }

            case MMI_IRDA_ACT_CLOSE:
                mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_USER);
                break;

            case MMI_IRDA_ACT_IDLE:
                /* Wrong state, Ignore */
                break;

            default:
                MMI_IRDA_LOG_STATE_ERR();
        }
    }
    else
    {
        /* Connection establish fail  */
        /* mmi_irda_obex_snd_connect_terminated( MMI_IRDA_ERR_REJECT ); */
        mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_REJECT);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_disconnect_ind_handler
 * DESCRIPTION
 *  This function is event handler for obex disconnect (MSG_ID_OBEX_DISCONNECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_DISCONNECT_IND_HDLR);

    mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_DISCONNECT);

    /*
     * switch( MMI_IRDA_CTX(act)  )
     * {
     * case MMI_IRDA_ACT_RECV:
     * MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);
     * MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
     * break;
     * 
     * case MMI_IRDA_ACT_BIDIR:
     * MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_SND);
     * MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
     * #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
     * break;
     * #endif         
     * 
     * case MMI_IRDA_ACT_IDLE:
     * case MMI_IRDA_ACT_SND:
     * default:
     * MMI_IRDA_LOG_STATE_ERR();
     * break;
     * }
     */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_put_object_ind_handler
 * DESCRIPTION
 *  This function is event handler for obex put object indication (MSG_ID_OBEX_PUT_OBJECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  mod_src     [IN]            
 *  ilm_p       [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_put_object_ind_handler(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MTK_TARGET__

    ilm_struct *mmi_ilm_ptr = (ilm_struct*) ilm_p;
    obex_put_object_ind_struct *recv_msg_ptr = (obex_put_object_ind_struct*) msg;
    obex_put_object_rsp_struct *msg_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* construct response struct */
    msg_ptr = construct_local_para(sizeof(obex_put_object_rsp_struct), TD_UL);
    mmi_irda_assert(msg_ptr != NULL);

    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_PUT_OBJ_IND_HDLR);

    if (mmi_irda_is_ircomm_active() == MMI_TRUE)
    {
        msg_ptr->rsp_code = OBEX_APP_RES_FAILED_F;
        MMIIRDA_SET_FLAG(MMIIRDA_MASK_DISK_FULL);
        goto MMIIRDA_PUT_OBJ_IND_CLEANUP;
    }

    /* Change Irda MMI state */
    if (MMI_IRDA_CTX(recv_act) == MMI_IRDA_MINACT_RECV_CONNECTED
        || MMI_IRDA_CTX(recv_act) == MMI_IRDA_MINACT_RECV_OBJ_FIN)
    {
        MMI_IRDA_CTX(first_pkt_flag) = MMI_TRUE;
    }
    else
    {
        MMI_IRDA_CTX(first_pkt_flag) = MMI_FALSE;
    }

    MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_OBJ_RECVED;

    /* Save to file... */

    /* First packet, create file */
    if (MMI_IRDA_CTX(first_pkt_flag) == MMI_TRUE)
    {
        U8 fcnt;
        FS_HANDLE h, k;
        S8 *path_buf;

        /* Reset the flag at initial transaction */
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_DISK_FULL);
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
        MMIIRDA_RESET_FLAG(MMIIRDA_MASK_WRITE_FILE_FAIL);

        /* Check default folder again */
        if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_FOLDER_ERR) == MMI_TRUE)
        {
            mmi_irda_init_received_folder();

            /* if after reinit, folder still get problem, return fail */
            if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_FOLDER_ERR) == MMI_TRUE)
            {
                msg_ptr->rsp_code = OBEX_APP_RES_FAILED_F;
                /* MMIIRDA_SET_FLAG(MMIIRDA_MASK_DISK_FULL); */
                goto MMIIRDA_PUT_OBJ_IND_CLEANUP;
            }
        }

        /* Save object name to context */
        memset(MMI_IRDA_CTX(obj_name), 0, sizeof(MMI_IRDA_CTX(obj_name)));
        if (mmi_ucs2strlen((S8*) recv_msg_ptr->obj_name) > 0)
        {
            memcpy(MMI_IRDA_CTX(obj_name), recv_msg_ptr->obj_name, sizeof(MMI_IRDA_CTX(obj_name)) - 1);
        }

        /* Set path and file name, check file exist */
        fcnt = 0;
        path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        mmi_irda_assert(path_buf != NULL);
        while (fcnt < 0xFF)
        {
            MMI_IRDA_MAKE_RECV_FILENAME(path_buf, fcnt);
            h = FS_Open((kal_uint16*) path_buf, FS_READ_ONLY);
            if (h > 0)
            {
                FS_Close(h);
                fcnt++;
            }
            else
            {
                break;
            }
        }

        /* Create file */
        MMI_IRDA_CTX(fcnt) = fcnt;
        h = FS_Open((kal_uint16*) path_buf, (FS_READ_WRITE | FS_CREATE_ALWAYS));
        MMI_IRDA_MAKE_RECV_PATH(path_buf);
        k = FS_Open((kal_uint16*) path_buf, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        OslMfree(path_buf);

        if (h <= 0)
        {
            /* File open error. Error handling */
            if (k >= 0)
                FS_Close(k);
            /* mmi_irda_assert(0); */
            msg_ptr->rsp_code = OBEX_APP_RES_FAILED_F;
            if (h == FS_ROOT_DIR_FULL)
            {
                MMIIRDA_SET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
            }
            else
            {
                MMIIRDA_SET_FLAG(MMIIRDA_MASK_DISK_FULL);
            }
            goto MMIIRDA_PUT_OBJ_IND_CLEANUP;
        }
        else
        {
            MMI_IRDA_CTX(h_recv) = h;
            MMI_IRDA_CTX(h_recv_folder) = k;
        }

    }   /* End of first Packet */

    if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_DISK_FULL) || MMIIRDA_GET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL))
    {
        /* Send failed response to OBEX */
        msg_ptr->rsp_code = OBEX_APP_RES_FAILED_F;
        mmi_irda_send_msg_to_obex(MSG_ID_OBEX_PUT_OBJECT_RSP, (local_para_struct*) msg_ptr, NULL);
        mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_USER);

        return; /* stop receiving until another first packet comes */
    }

    /* Write object context to file */
    if (mmi_ilm_ptr->peer_buff_ptr)
    {
        void *data_p;
        U16 len;
        U32 len_written;
        S16 ret;

        data_p = get_pdu_ptr(mmi_ilm_ptr->peer_buff_ptr, &len);

        if (MMI_IRDA_CTX(h_recv))
        {
            ret = FS_Write(MMI_IRDA_CTX(h_recv), data_p, len, (kal_uint32*) & len_written);

            if (ret < 0)
            {
                /* mmi_irda_assert(0); */
                msg_ptr->rsp_code = OBEX_APP_RES_FAILED_F;
                mmi_irda_obex_close_recv_file_handlers();
                if (ret == FS_ROOT_DIR_FULL)
                {
                    MMIIRDA_SET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL);
                }
                else if (ret == FS_DRIVE_NOT_READY)
                {
                    MMIIRDA_SET_FLAG(MMIIRDA_MASK_WRITE_FILE_FAIL);
                }
                else
                {
                    MMIIRDA_SET_FLAG(MMIIRDA_MASK_DISK_FULL);
                }
                goto MMIIRDA_PUT_OBJ_IND_CLEANUP;
            }
        }
    }

    /* Final packet, Receive Finished !! */
    if (recv_msg_ptr->is_final_pkt == KAL_TRUE)
    {
        U8 *path_buf;

        MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_OBJ_FIN;

        msg_ptr->rsp_code = OBEX_APP_RES_SUCCESS_F;

        /* close file */
        mmi_irda_obex_close_recv_file_handlers();

        /* nofify register appications */
        path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        mmi_irda_assert(path_buf != NULL);

        MMI_IRDA_MAKE_RECV_FILENAME(path_buf, MMI_IRDA_CTX(fcnt));

        mmi_irda_notify_register_app((U16*) path_buf);

        OslMfree(path_buf);
    }
    else
    {
        msg_ptr->rsp_code = OBEX_APP_RES_CONTINUE_F;
    }

  MMIIRDA_PUT_OBJ_IND_CLEANUP:

   /********************************************/
    /* Robin 20040901 */
    /* The flow-ctrl end point move to obex     */
    /* Here is normal ctrl buffer */
   /********************************************/
    /* Release peer buffer */
    /*
     * if( mmi_ilm_ptr->peer_buff_ptr )
     * {
     * mmi_ilm_ptr->peer_buff_ptr->ref_count = 1;
     * gprs_flc_free_peer_buff(IRDA_DATA, 0, GPRS_FLC_DL, 0, mmi_ilm_ptr->peer_buff_ptr);
     * mmi_ilm_ptr->peer_buff_ptr = NULL;
     * }
     */
    {
        U8 *path_buf;

        path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        MMI_IRDA_MAKE_RECV_FILENAME(path_buf, MMI_IRDA_CTX(fcnt));
        FS_Delete((const WCHAR*)path_buf);
        OslMfree(path_buf);
    }
    /* Notify Disk full Screen */
    if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_DISK_FULL))
    {
    #if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
        gThemeRcvOnDiskFull = DISK_FULL;
    #endif 
        /* Notify MMI Screen */
        mmi_irda_scr_data_stop_ind();
        MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);
        MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
        mmi_irda_notify_recv_err(MMI_IRDA_NFY_DISK_FULL);
    }
    /* Notify Root Directory full Screen */
    else if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_ROOT_DIR_FULL))
    {
        /* Notify MMI Screen */
        mmi_irda_scr_data_stop_ind();
        MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);
        MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
        mmi_irda_notify_recv_err(MMI_IRDA_NFY_ROOT_DIR_FULL);
    }
    /* Notify File Write Failed Screen */
    else if (MMIIRDA_GET_FLAG(MMIIRDA_MASK_WRITE_FILE_FAIL))
    {
        /* Notify MMI Screen */
        mmi_irda_scr_data_stop_ind();
        MMI_IRDA_STATE_TRANS(MMI_IRDA_ACT_IDLE);
        MMI_IRDA_CTX(recv_act) = MMI_IRDA_MINACT_RECV_DISCONNECTED;
        mmi_irda_notify_recv_err(MMI_IRDA_NFY_WRITE_FILE_FAIL);
    }

    /* Send response to OBEX */
    msg_ptr->need_ack = recv_msg_ptr->need_ack;
    if (msg_ptr->rsp_code == OBEX_APP_RES_FAILED_F)
    {
        if (msg_ptr != NULL)
        {
            free_local_para((local_para_struct*) msg_ptr);
        }
        mmi_irda_obex_snd_disconnect(MMI_IRDA_ERR_REJECT);
    }
    else
    {
        mmi_irda_send_msg_to_obex(MSG_ID_OBEX_PUT_OBJECT_RSP, (local_para_struct*) msg_ptr, NULL);
    }

#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_set_send_pkt_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  send_pkt_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_set_send_pkt_size(U16 send_pkt_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IRDA_CTX(send_obex_pkt_size) = send_pkt_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_put_object_cnf_handler
 * DESCRIPTION
 *  This function is event handler for obex put object confirm (MSG_ID_OBEX_PUT_OBJECT_CNF)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_put_object_cnf_handler(void *msg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    obex_put_object_cnf_struct *recv_msg_ptr = NULL;
    obex_put_object_req_struct *msg_ptr = NULL;
    peer_buff_struct *peer_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_OBEX_FUNC_PUT_OBJ_CNF_HDLR);

    recv_msg_ptr = (obex_put_object_cnf_struct*) msg;

    /* Change MMI sub state */
    /*
     * #ifdef __MMI_IRDA_BIDIRECT_ENABLE__
     * || MMI_IRDA_CTX(act) == MMI_IRDA_ACT_BIDIR
     * #endif
     */

    if (MMI_IRDA_CTX(act) == MMI_IRDA_ACT_SND)
    {
        MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_PUT_OBJ_CNF;
    }
    else
    {
        mmi_irda_obex_snd_disconnect(MMI_IRDA_ERR_DISCONNECT);
        return;
    }

    switch (recv_msg_ptr->rsp_code)
    {
        case OBEX_APP_RES_CONTINUE_F:
        case OBEX_APP_RES_SUCCESS_F:
        {
            if (MMI_IRDA_CTX(remain_put_len) > 0)
            {
                U16 len;
                U8 *pdu_ptr = NULL;

                msg_ptr = construct_local_para(sizeof(obex_put_object_req_struct), TD_UL);

                if ((MMI_IRDA_CTX(send_obex_pkt_size) == 0) || (OBEX_MAX_APP_DATA < MMI_IRDA_CTX(send_obex_pkt_size)))
                {
                    mmi_irda_set_send_pkt_size(OBEX_MAX_APP_DATA);
                }

                /* Pending data */
                msg_ptr->total_obj_size = MMI_IRDA_CTX(total_obj_len);
                /* strcpy((kal_char *)msg_ptr->obj_name, MMI_IRDA_CTX(obj_name)); */
                memcpy(msg_ptr->obj_name, MMI_IRDA_CTX(obj_name), sizeof(msg_ptr->obj_name));

                if (MMI_IRDA_CTX(remain_put_len) > MMI_IRDA_CTX(send_obex_pkt_size))
                {

                    /* Remain data is more than one packet */

                    /* construct buffers for obex tast */
                    msg_ptr->pkt_type = OBEX_NORMAL_PKT;
                    peer_ptr = construct_peer_buff(MMI_IRDA_CTX(send_obex_pkt_size), 0, 0, TD_UL);
                    mmi_irda_assert(NULL != peer_ptr);
                    pdu_ptr = get_pdu_ptr(peer_ptr, &len);

                    if (MMI_IRDA_CTX(h_snd) != 0)
                    {
                        /* From File */
                        kal_uint32 read_len;
                        kal_int32 errno;

                        errno = FS_Read(MMI_IRDA_CTX(h_snd), pdu_ptr, MMI_IRDA_CTX(send_obex_pkt_size), &read_len);

                        /* Read error! Could be removable device */
                        if (errno < 0 || read_len != MMI_IRDA_CTX(send_obex_pkt_size))
                        {
                            /* mmi_irda_assert(0); */
                            mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_BAD_FILE);
                        }

                    }
                    else
                    {
                        /* From given object */
                        kal_mem_cpy(
                            pdu_ptr,
                            ((S8*) (MMI_IRDA_CTX(obj_cntx_p)) + (MMI_IRDA_CTX(total_obj_len)) - (MMI_IRDA_CTX(remain_put_len))),
                            MMI_IRDA_CTX(send_obex_pkt_size));
                    }

                    MMI_IRDA_CTX(remain_put_len) -= MMI_IRDA_CTX(send_obex_pkt_size);
                }
                else
                {

                    /* Last packet */
                    MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_PUT_OBJ_FIN_WAITING;

                    /* Construct buffers for obex task */
                    msg_ptr->pkt_type = OBEX_FINAL_PKT;
                    peer_ptr = construct_peer_buff((kal_uint16) (MMI_IRDA_CTX(remain_put_len)), 0, 0, TD_UL);
                    mmi_irda_assert(NULL != peer_ptr);
                    pdu_ptr = get_pdu_ptr(peer_ptr, &len);

                    /* kal_mem_cpy(pdu_ptr, out_buf, g_mmi_irda_cntx_p->remain_put_len); */
                    if (MMI_IRDA_CTX(h_snd) != 0)
                    {
                        /* From file */
                        kal_uint32 read_len;
                        kal_int32 errno;

                        errno = FS_Read(MMI_IRDA_CTX(h_snd), pdu_ptr, MMI_IRDA_CTX(remain_put_len), &read_len);

                        /* Read error! */
                        if (errno < 0 || read_len != MMI_IRDA_CTX(remain_put_len))
                        {
                            mmi_irda_assert(0);
                            mmi_irda_obex_connection_terminated(MMI_IRDA_ERR_BAD_FILE);
                        }

                    }
                    else
                    {
                        /* From given object */
                        kal_mem_cpy(pdu_ptr, MMI_IRDA_CTX(obj_cntx_p), MMI_IRDA_CTX(remain_put_len));
                    }

                    MMI_IRDA_CTX(remain_put_len) = 0;

                }

                /* Change MMI sub state */
                MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_PUT_OBJ_WAITING;

                mmi_irda_send_msg_to_obex(MSG_ID_OBEX_PUT_OBJECT_REQ, (local_para_struct*) msg_ptr, peer_ptr);

            }
            else
            {
                /* No remain data, Finish PUT */
                MMI_IRDA_CTX(snd_act) = MMI_IRDA_MINACT_SND_PUT_OBJ_FIN_CNF;
                /* Due to this might happen from some abnormal OBEX client, we remove this assert and send disconnect to the peer side */
                /* mmi_irda_assert( recv_msg_ptr->rsp_code == OBEX_APP_RES_SUCCESS_F ); */
                mmi_irda_obex_snd_disconnect(MMI_IRDA_ERR_SUCCESS);
            }
        }
            break;

        case OBEX_APP_RES_FAILED_F:
        default:
            /* Server return fail */
            mmi_irda_obex_snd_disconnect(MMI_IRDA_ERR_REJECT);
            /* mmi_irda_assert( 0 ); */
            break;
    }

#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_is_open
 * DESCRIPTION
 *  This function is to send ir open message to LMP without state check
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_irda_is_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IRDA_CTX(act) == MMI_IRDA_ACT_CLOSE || MMI_IRDA_CTX(act) == MMI_IRDA_ACT_UNKNOW)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_force_ir_open
 * DESCRIPTION
 *  This function is to send ir open message to LMP without state check
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_force_ir_open(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    irda_local_para_struct *msg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_ptr = construct_local_para(sizeof(irda_local_para_struct), TD_UL);
    msg_ptr->open_time = MMI_IRDA_OPEN_ALWAYS;

    mmi_irda_send_msg_to_lmp(MSG_ID_IRDA_OPEN, (void*)msg_ptr, NULL);

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_force_ir_close
 * DESCRIPTION
 *  This function is to send ir close message to LMP without state check
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_force_ir_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_irda_send_msg_to_lmp(MSG_ID_IRDA_CLOSE, NULL, NULL);
}

/* 
 * Send Message to Others
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_send_msg_to_obex
 * DESCRIPTION
 *  This function is to send message to obex task
 * PARAMETERS
 *  msg_id              [IN]            
 *  p_local_para        [?]             
 *  p_peer_buff         [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_send_msg_to_obex(U16 msg_id, void *p_local_para, void *p_peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_FUNC_SEND_MSG_TO_OBEX);

    Message.oslMsgId = msg_id;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_OBEX;

    switch (msg_id)
    {
        case MSG_ID_OBEX_CONNECT_REQ:
            SetProtocolEventHandler(mmi_irda_obex_connect_cnf_handler, MSG_ID_OBEX_CONNECT_CNF);
            break;
        case MSG_ID_OBEX_PUT_OBJECT_REQ:
            SetProtocolEventHandler(mmi_irda_obex_put_object_cnf_handler, MSG_ID_OBEX_PUT_OBJECT_CNF);
            break;

        case MSG_ID_OBEX_DISCONNECT_REQ:
        case MSG_ID_OBEX_GET_OBJECT_REQ:
            break;

        case MSG_ID_OBEX_CONNECT_RSP:
        case MSG_ID_OBEX_PUT_OBJECT_RSP:
        case MSG_ID_OBEX_GET_OBJECT_RSP:
            break;

        default:
            mmi_irda_assert(0);
            break;
    }

    Message.oslDataPtr = (oslParaType*) p_local_para;
    Message.oslPeerBuffPtr = p_peer_buff;

    OslMsgSendExtQueue(&Message);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_send_msg_to_lmp
 * DESCRIPTION
 *  This function is to send message to lmp task
 * PARAMETERS
 *  msg_id              [IN]            
 *  p_local_para        [?]             
 *  p_peer_buff         [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_send_msg_to_lmp(U16 msg_id, void *p_local_para, void *p_peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_IRDA_FUNC_SEND_MSG_TO_LMP);

    Message.oslMsgId = msg_id;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_LMP;

    switch (msg_id)
    {
        case MSG_ID_IRDA_OPEN:
        case MSG_ID_IRDA_CLOSE:
            break;
        default:
            mmi_irda_assert(0);
            break;
    }

    Message.oslDataPtr = (oslParaType*) p_local_para;
    Message.oslPeerBuffPtr = p_peer_buff;

    OslMsgSendExtQueue(&Message);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_send_msg_to_ircomm
 * DESCRIPTION
 *  This function is to send message to ircomm task
 * PARAMETERS
 *  msg_id              [IN]            
 *  p_local_para        [?]             
 *  p_peer_buff         [?]             
 *  a(?)                [IN/OUT]        First variable, used as returns
 *  b(?)                [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_send_msg_to_ircomm(U16 msg_id, void *p_local_para, void *p_peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = msg_id;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_IRCOMM;

    switch (msg_id)
    {
        case MSG_ID_IRCOMM_DISCONNECT_REQ:
            break;
        default:
            mmi_irda_assert(0);
            break;
    }

    Message.oslDataPtr = (oslParaType*) p_local_para;
    Message.oslPeerBuffPtr = p_peer_buff;

    OslMsgSendExtQueue(&Message);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_irda_obex_close_recv_file_handlers
 * DESCRIPTION
 *  This function is to close the opened file/folder handlers in OBEX server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_irda_obex_close_recv_file_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_IRDA_CTX(h_recv))
    {
        FS_Close(MMI_IRDA_CTX(h_recv));
        MMI_IRDA_CTX(h_recv) = (FS_HANDLE) NULL;
    }
    if (MMI_IRDA_CTX(h_recv_folder))
    {
        FS_Close(MMI_IRDA_CTX(h_recv_folder));
        MMI_IRDA_CTX(h_recv_folder) = (FS_HANDLE) NULL;
    }
}


/* 
 * Application will handle the screen processing
 */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#endif /* __MMI_IRDA_SUPPORT__ */ 

