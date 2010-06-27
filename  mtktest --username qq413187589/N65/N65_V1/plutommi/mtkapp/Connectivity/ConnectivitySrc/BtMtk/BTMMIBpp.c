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
 * BTMMIBpp.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BPP service.
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
#include "MMI_include.h"
#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BPP_SUPPORT__)
/*  Include: MMI header file */
#include "Conversions.h"
//#include "FileSystemDef.h"

/* Trace Header Files */

#include "FileManagerGProt.h"

/* File Type Categories (sync with file manager) */
#include "FileMgr.h"
#include "xml_def.h"
#include "BTMMIScrGprots.h"
#include "BTMMICm.h"
#include "BTMMICmGprots.h"
#include "Bluetooth_struct.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppScr.h"
#include "BTMMIBpp.h"
#include "BTMMIBppXhtmlGprot.h"
#include "Bluetooth_bm_struct.h"
#include "ExtDeviceDefs.h"
#include "BTMMICustDef.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 


/***************************************************************************** 
* External Variable & Functions
*****************************************************************************/
extern int isInCall(void);

/***************************************************************************** 
* Local Variable & Functions
*****************************************************************************/
static void mmi_bt_bpp_get_printer_attr(void);
static void mmi_bt_bpp_set_printer_attr(bt_bpp_get_printer_attr_cnf_struct* cnf);
static void mmi_bt_bpp_create_job(void);
static void mmi_bt_bpp_cntx_init(void);
static void mmi_bt_bpp_event_hdlr_init(void);
static void mmi_bt_bpp_cm_call_back(MMI_BOOL result, U32 uap, U8 lap, U16 nap);

/***************************************************************************** 
* CONTEXT
*****************************************************************************/
mmi_bpp_cntx_struct g_mmi_bpp_cntx;
mmi_bpp_cntx_struct *const mmi_bpp_cntx_p = &g_mmi_bpp_cntx;

/***************************************************************************** 
* MACROS
*****************************************************************************/
#define BPP_MEMSET(local_para_ptr)    do {                              \
    memset((kal_uint8*)(local_para_ptr) + sizeof(local_para_struct), 0, \
           (local_para_ptr)->msg_len - sizeof(local_para_struct));      \
    } while(0)

#define MMI_BPP_STATUS_ERR()            \
{                                       \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BPP_STATUS_ERROR, mmi_bpp_cntx_p->status);\
}

#define MMI_BPP_STATUS_TRANS(x)         \
{                                       \
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BPP_STATUS_TRANSITION, mmi_bpp_cntx_p->status, x);\
    mmi_bpp_cntx_p->status = (x);       \
}

#define MMI_BPP_XHTML_FILE     ("@bpp\\bpp_xhtml_file") //for printing document
#define BPP_MAKE_TEMP_FILE(x)                 \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s",  \
      MMI_PUBLIC_DRV, MMI_BPP_XHTML_FILE );


/***************************************************************************** 
* GLOBAL FUNCTION
*****************************************************************************/
#define GLOBAL_API
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_init
 * DESCRIPTION
 *  This function is to init the bpp context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_INIT);

    mmi_bt_bpp_cntx_init();
    mmi_bt_bpp_scr_cntx_init();
    mmi_bt_bpp_event_hdlr_init();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_deinit
 * DESCRIPTION
 *  This function is to deinit the bpp screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DEINIT);

    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_COMPOSING)
    {
        bpp_cancel_xhtml_composing();        
    }
    
    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_NONE);
    mmi_bt_bpp_deinit_clear_scrs();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_cntx_init
 * DESCRIPTION
 *  This function is to init the bpp context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CNTX_INIT);

    /* check status */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_COMPOSING)
    {
        /* cancel xhtml composing process */
        bpp_cancel_xhtml_composing();
    }

    //FS_Delete((WCHAR *) mmi_bpp_cntx_p->xhtml_file);

    if (mmi_bpp_cntx_p->timer_flag)
    {
        StopTimer(BT_BPP_PRINTING_TIMER);
        mmi_bpp_cntx_p->timer_flag = 0;
    }

    if(!mmi_bpp_cntx_p->printer.got_attr)
    {
        memset(mmi_bpp_cntx_p->printer_name, 0, GOEP_MAX_DEV_NAME);
        memset(&(mmi_bpp_cntx_p->printer), 0, sizeof(mmi_bpp_printer_struct));
    }

    mmi_bpp_cntx_p->cur_app = 0;
    mmi_bpp_cntx_p->status = 0;
    mmi_bpp_cntx_p->job_id = 0;
    mmi_bpp_cntx_p->g_conn_id = 0;
    mmi_bpp_cntx_p->cm_disc_flag = MMI_FALSE;
    mmi_bpp_cntx_p->app_callback = NULL;
    BPP_MAKE_TEMP_FILE(mmi_bpp_cntx_p->xhtml_file);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_reset
 * DESCRIPTION
 *  This function is to reset the bpp context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_RESET);

    mmi_bpp_cntx_p->app_callback = NULL;
    mmi_bpp_cntx_p->cur_app = MMI_BPP_APP_NONE;
    mmi_bpp_cntx_p->status = MMI_BPP_STATUS_NONE;

    /* check printer */
    if (!mmi_bpp_cntx_p->printer.got_attr)
    {
        memset(&(mmi_bpp_cntx_p->printer), 0, sizeof(mmi_bpp_printer_struct));
    }
    mmi_bt_bpp_scr_cntx_init();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_event_hdlr_init
 * DESCRIPTION
 *  This function is to reset the bpp event hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_event_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_EVENT_HDLR_INIT);

    ClearProtocolEventHandler(MSG_ID_BT_BPP_CONNECT_CNF);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_AUTHENTICATION_IND);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_DISCONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_GET_PRINTER_ATTR_CNF);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_CREATE_JOB_CNF);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_SEND_DOC_CNF);
    ClearProtocolEventHandler(MSG_ID_BT_BPP_PROG_UPDATE_IND);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_document_compose_done
 * DESCRIPTION
 *  This function is to notify the comsposing process is finished
 * PARAMETERS
 *  mmi_bpp_doc_compose_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_document_compose_done(mmi_bpp_doc_compose_enum doc_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_send_doc_req_struct*  req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_DOCUMENT_COMPOSE_DONE, doc_flag);

    switch(doc_flag)
    {
        case MMI_BPP_DOC_COMPOSE_DONE:            
            if (mmi_bpp_cntx_p->timer_flag)
            {
                /* start bpp mmi timer */
                StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_TIMER_DUR, mmi_bt_bpp_timer_expire_hdlr);
            }
            else
            {
                /* register protocol event hdlr */
                SetProtocolEventHandler(mmi_bt_bpp_event_ind_hdlr, MSG_ID_BT_BPP_EVENT_IND);
            }

            /* blinking */            
            mmi_bt_bpp_blinking(MMI_BPP_BLINK_START);                    
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_FORE_GROUND_PRINT);
            mmi_bpp_cntx_p->total_send_doc_len = 0;
            mmi_bpp_cntx_p->remain_send_doc_len = 0;

            /* clear screen */
            if (isInCall() != MMI_TRUE)
            {
                mmi_bt_bpp_entry_printing();
                mmi_bt_bpp_del_scr(SCR_BPP_COMPOSING);
            }
            else
            {
                mmi_bt_bpp_history_replace(SCR_BPP_COMPOSING, SCR_BPP_PRINTING);
            }            

            /* send doc to printer */
            req = (bt_bpp_send_doc_req_struct*)OslConstructDataPtr(sizeof(bt_bpp_send_doc_req_struct));
            BPP_MEMSET(req);
            req->cm_conn_id = mmi_bpp_cntx_p->g_conn_id;
            req->job_id = mmi_bpp_cntx_p->job_id;            

            /* for testing */
            //kal_wsprintf((U16*)req->file_path, "D:\\@bpp\\bpp_xhtml_file");
            memcpy(req->file_path, mmi_bpp_cntx_p->xhtml_file, BPP_FMGR_MAX_PATH_LEN*BPP_ENCODING_LENGTH);

            if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.DocFormat, BPP_ADP_DOC_FORMAT_MASK_XHTML_MULTI) && mmi_bpp_cntx_p->printer.got_attr)
            {
                req->doc_type = BT_BPP_TYPE_XHTML_MULTI;
            }
            else
            {
                req->doc_type = BT_BPP_TYPE_XHTML;
            }

            /* send disconnect req to BT */
            mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_SEND_DOC_REQ, req);           

            /* register protocol event hdlr */
            SetProtocolEventHandler(mmi_bt_bpp_send_doc_cnf_hdlr, MSG_ID_BT_BPP_SEND_DOC_CNF);
            SetProtocolEventHandler(mmi_bt_bpp_prog_update_ind_hdlr, MSG_ID_BT_BPP_PROG_UPDATE_IND);                        
            break;
            
        case MMI_BPP_DOC_COMPOSE_FAILED:
            mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_COMPOSE_FAILED);
            mmi_bt_bpp_clear_scr_db(SCR_BPP_COMPOSING);
            /* disconnect process */
            mmi_bt_bpp_send_disconnect();
            if (isInCall() != MMI_TRUE)
            {
                mmi_bt_bpp_disconnect_clear_scrs();
                mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
            }
            else
            {
                mmi_bt_bpp_history_replace(SCR_BPP_COMPOSING, SCR_BPP_DISCONNECTING);
            }
            break;
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_app_is_printing
 * DESCRIPTION
 *  This function is to query the availability of bpp print service
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_print_status_enum
 *****************************************************************************/
mmi_bpp_print_status_enum mmi_bt_bpp_app_is_printing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG2(MMI_BPP_APP_IS_PRINTING, mmi_bpp_cntx_p->cur_app, mmi_bpp_cntx_p->status);

    switch(mmi_bpp_cntx_p->status)
    {
        case MMI_BPP_STATUS_NONE:
            return MMI_BPP_PRINT_STATUS_IDLE;

        default:
            return MMI_BPP_PRINT_STATUS_BUSY;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_app_print
 * DESCRIPTION
 *  This function is to access the print service and register the print callback function to BPP
 * PARAMETERS
 *  mmi_bpp_app_enum, void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_app_print(mmi_bpp_app_enum app, ap_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG2(MMI_BPP_APP_PRINT, app, callback);

    switch(mmi_bpp_cntx_p->status)
    {
        case MMI_BPP_STATUS_NONE:
            if((app != MMI_BPP_APP_NONE) && (callback != NULL))
            {
                mmi_bpp_cntx_p->app_callback = (ap_callback)callback;
                mmi_bpp_cntx_p->cur_app = app;
                MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_SEARCHING);

                /* entry printer device select screen */
                mmi_bt_entry_cod_device_with_service_select_screen( 
                    MMI_BT_RENDERING_MAJOR_SERVICE_MASK |MMI_BT_IMAGING_MAJOR_DEVICE_MASK |MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS, 
                    0, 
                    (void *)mmi_bt_bpp_cm_call_back);
                
                return;
            }           
        default:
            MMI_BPP_STATUS_ERR();
            ASSERT(0);
    }    
}

 #if 1
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_printing
 * DESCRIPTION
 *  This function is to connect printer
 * PARAMETERS
 *  U16, U8, U32
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_printing(U16 nap, U8 uap,U32 lap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_bt_addr bd_addr;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bd_addr.lap = lap;
    bd_addr.uap = uap;
    bd_addr.nap = nap;
    
    mmi_bt_bpp_connect_printer(bd_addr);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_connect_printer
 * DESCRIPTION
 *  This function is to connect printer
 * PARAMETERS
 *  mmi_bth_bt_addr
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_connect_printer(mmi_bth_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_connect_req_struct*  req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CONNECT_PRINTER);    
    
#ifdef __USB_IN_NORMAL_MODE__    
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* in mass storage mode */         
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   
            return;
        }        
#endif /* __USB_IN_NORMAL_MODE__ */ 
        /* check bpp status */
	    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_NONE)
        {
            mmi_bpp_cntx_p->status = MMI_BPP_STATUS_SEARCHING;
        }
        ASSERT(mmi_bpp_cntx_p->status == MMI_BPP_STATUS_SEARCHING);
        mmi_bpp_cntx_p->status = MMI_BPP_STATUS_CONNECTING;
        //add trace for state trans
        
        /* update context */
        mmi_bpp_cntx_p->bd_addr.lap = bd_addr.lap;
        mmi_bpp_cntx_p->bd_addr.uap = bd_addr.uap;
        mmi_bpp_cntx_p->bd_addr.nap = bd_addr.nap;

        /* connect printer */
        req = (bt_bpp_connect_req_struct*)OslConstructDataPtr(sizeof(bt_bpp_connect_req_struct));
        BPP_MEMSET(req);
        req->bd_addr.lap = bd_addr.lap;
        req->bd_addr.uap = bd_addr.uap;
        req->bd_addr.nap = bd_addr.nap;        

        /* send connect req to BT */
        mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_CONNECT_REQ, req);            

        /* start bpp timer */   
        StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_CONNECT_TIMER_DUR, mmi_bt_bpp_connect_timer_expire_hdlr);

        /* register protocol event handler */
        SetProtocolEventHandler(mmi_bt_bpp_connect_cnf_hdlr, MSG_ID_BT_BPP_CONNECT_CNF);
        SetProtocolEventHandler(mmi_bt_bpp_auth_ind_hdlr, MSG_ID_BT_BPP_AUTHENTICATION_IND);

        /* entry connecting screen */
        mmi_bt_bpp_entry_connecting();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_disconnect_printer
 * DESCRIPTION
 *  This function is to disconnect printer
 * PARAMETERS
 *  mmi_bth_bt_addr, U32
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_disconnect_printer(mmi_bth_bt_addr bd_addr, U32 g_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DISCONNECT_PRINTER);

    /* set disconnect flag */
    mmi_bpp_cntx_p->cm_disc_flag = MMI_TRUE;
    
    switch(mmi_bpp_cntx_p->status)
    {
        case MMI_BPP_STATUS_PRINTED:
        case MMI_BPP_STATUS_DISCONNECTING:
            return;
        case MMI_BPP_STATUS_BACK_GROUND_PRINT:
        case MMI_BPP_STATUS_BACK_GROUND_STOPPED:
            mmi_bt_bpp_send_disconnect();
        case MMI_BPP_STATUS_CANCELED:
        case MMI_BPP_STATUS_JOB_CANCELED:
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_DISCONNECTING);
            if (mmi_bpp_cntx_p->timer_flag)
            {
                StopTimer(BT_BPP_PRINTING_TIMER);
            }
            else
            {
                ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
            }
            ClearProtocolEventHandler(MSG_ID_BT_BPP_PROG_UPDATE_IND);
            return;
        case MMI_BPP_STATUS_CHALLENGE:
        case MMI_BPP_STATUS_COMPOSING:
        case MMI_BPP_STATUS_CONNECTING:
        case MMI_BPP_STATUS_AUTHENTICATED:
        case MMI_BPP_STATUS_CONNECTED:
        case MMI_BPP_STATUS_GETTING:
        case MMI_BPP_STATUS_SETTING:
        case MMI_BPP_STATUS_CREATING:
        case MMI_BPP_STATUS_FORE_GROUND_PRINT:
        case MMI_BPP_STATUS_FORE_GROUND_STOPPED:
            mmi_bth_disconnect_cnf_hdler(MMI_FALSE, 
                                        mmi_bpp_cntx_p->bd_addr.lap,
                                        mmi_bpp_cntx_p->bd_addr.uap,
                                        mmi_bpp_cntx_p->bd_addr.nap,
                                        (U32)MMI_BTH_BASIC_PRINTING,
                                        mmi_bpp_cntx_p->g_conn_id); 
           break;
        default:
            MMI_BPP_STATUS_ERR();
            //ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_background_print
 * DESCRIPTION
 *  This function is to enter the background printing mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_foreground_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_FOREGROUND_PRINT, mmi_bpp_cntx_p->status);

    /* status check */
    switch(mmi_bpp_cntx_p->status)
    {        
        case MMI_BPP_STATUS_BACK_GROUND_STOPPED:
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_FORE_GROUND_STOPPED);
            mmi_bt_bpp_entry_trouble();
            mmi_bt_bpp_add_history(SCR_BPP_PRINTING);
            break;
        case MMI_BPP_STATUS_BACK_GROUND_PRINT:
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_FORE_GROUND_PRINT);
        case MMI_BPP_STATUS_PRINTED:
            mmi_bt_bpp_entry_printing();
            break;
        case MMI_BPP_STATUS_JOB_CANCELED:
        case MMI_BPP_STATUS_DISCONNECTING:
        case MMI_BPP_STATUS_COMPOSING:
            mmi_bt_bpp_entry_disconnecting();
            break;
        default:
            MMI_BPP_STATUS_ERR();
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_usb_handle
 * DESCRIPTION
 *  This function is to handle the usb plug in case
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bpp_usb_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__    
    /*only usb mass can delete the connecting/getting screen*/
    if (mmi_usb_is_in_mass_storage_mode())
    {
        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_DISCONNECTING);

        /*notify app to free the resource*/
        if(mmi_bpp_cntx_p->app_callback)
        {
            mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
        }
        return MMI_FALSE;
    }        
#endif /* __USB_IN_NORMAL_MODE__ */
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_can_format_drive
 * DESCRIPTION
 *  This function is to handle the formatting operation from FM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_bt_bpp_can_format_drive(PS8 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2ncmp((PS8)file_path, (PS8)mmi_bpp_cntx_p->xhtml_file, 3) == 0) &&
        (mmi_bt_bpp_app_is_printing() == MMI_BPP_PRINT_STATUS_BUSY))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


#define BPP_SCREEN_API
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_is_connecting
 * DESCRIPTION
 *  This function is to query the connecting status of BPP
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_bpp_is_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG2(MMI_BPP_IS_CONNECTING, mmi_bpp_cntx_p->cur_app, mmi_bpp_cntx_p->status);

    /* Connected or canceled */
    if ((mmi_bpp_cntx_p->status != MMI_BPP_STATUS_CONNECTING) &&
        (mmi_bpp_cntx_p->status != MMI_BPP_STATUS_CHALLENGE) &&
        (mmi_bpp_cntx_p->status != MMI_BPP_STATUS_AUTHENTICATED))
    {
        return MMI_FALSE;
    }
    /* Connecting */
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_status
 * DESCRIPTION
 *  This function is to check the status of bpp
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_status_enum
 *****************************************************************************/
mmi_bpp_status_enum mmi_bt_bpp_get_status(void)
{
    return mmi_bpp_cntx_p->status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_set_status
 * DESCRIPTION
 *  This function is to set the status of bpp
 * PARAMETERS
 *  mmi_bpp_status_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_set_status(mmi_bpp_status_enum status)
{
    MMI_BPP_STATUS_TRANS(status);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_printer_name
 * DESCRIPTION
 *  This function is to get the printer name buff pointer for bpp screen
 * PARAMETERS
 *  void
 * RETURNS
 *  PU8
 *****************************************************************************/
PU8 mmi_bt_bpp_get_printer_name(void)
{

    return (U8*) mmi_bpp_cntx_p->printer_name;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_printer
 * DESCRIPTION
 *  This function is to get the printer attributes for print setting
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_printer_struct*
 *****************************************************************************/
mmi_bpp_printer_struct* mmi_bt_bpp_get_printer(void)
{
    return  &(mmi_bpp_cntx_p->printer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_stopped_reason
 * DESCRIPTION
 *  This function is to get the printer stopped reason for troubleshooting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  bt_bpp_printer_reason_enum
 *****************************************************************************/
bt_bpp_printer_reason_enum mmi_bt_bpp_get_stopped_reason(void)
{
    return  mmi_bpp_cntx_p->stopped_reason;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_timer
 * DESCRIPTION
 *  This function is to get the timer flag 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_bt_bpp_get_timer(void)
{
    return  mmi_bpp_cntx_p->timer_flag;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_send_disconnect
 * DESCRIPTION
 *  This function is to send a disconnect req to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_send_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_disconnect_req_struct* req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (bt_bpp_disconnect_req_struct*)OslConstructDataPtr(sizeof(bt_bpp_disconnect_req_struct));
    BPP_MEMSET(req);
    req->cm_conn_id = mmi_bpp_cntx_p->g_conn_id;  

    /* send disconnect req to BT */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_DISCONNECT_REQ, req); 
    /* start timer */
    StopTimer(BT_BPP_PRINTING_TIMER);
    StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_DISC_TIMER_DUR, mmi_bt_bpp_disc_timer_expire_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_auth_send
 * DESCRIPTION
 *  This function is to send a authentication response to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_auth_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_authentication_rsp_struct* rsp;
    U8 *auth_buff;
    U8 tmp_ascii_buf[MMI_BPP_AUTH_INPUT_BUFF_SIZE/2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_AUTH_SEND);
    rsp = (bt_bpp_authentication_rsp_struct*)OslConstructDataPtr(sizeof(bt_bpp_authentication_rsp_struct));
    BPP_MEMSET(rsp);
    auth_buff = mmi_bt_bpp_get_auth_buff();
    rsp->passwd_len = (U16)mmi_ucs2strlen((S8*)auth_buff);
    mmi_ucs2_to_asc((S8*)tmp_ascii_buf, (S8*)auth_buff);
    memcpy(rsp->passwd, tmp_ascii_buf, rsp->passwd_len);
    
    /* send authentication response to BT */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_AUTHENTICATION_RSP, rsp); 
    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_AUTHENTICATED);

    mmi_bt_bpp_go_back_history();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_auth_reject
 * DESCRIPTION
 *  This function is to send a authentication response with cancel flag to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_auth_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_authentication_rsp_struct* rsp;
    U16 key_code;
    U16 key_type;         
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_AUTH_REJECT);
    rsp = (bt_bpp_authentication_rsp_struct*)OslConstructDataPtr(sizeof(bt_bpp_authentication_rsp_struct));
    BPP_MEMSET(rsp);
    rsp->cancel = MMI_TRUE;

    /* send authentication response to BT */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_AUTHENTICATION_RSP, rsp);

    /* clear cntx */
    mmi_bt_bpp_reset();

    /* clear screen, if RSK in auth, notify to app through connect_del_cbk */
    /* if usb mass, also throuth connect_del_cbk to notify app*/
    mmi_bt_bpp_del_scr(SCR_BPP_CONNECTING);
    GetkeyInfo(&key_code, &key_type);
    if (key_code == KEY_END)
    {
        mmi_bt_bpp_display_idle();
    }
    else
    {
        mmi_bt_bpp_go_back_history();
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_print
 * DESCRIPTION
 *  This function is to start printing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_PRINT);

    /* create job */
    mmi_bt_bpp_create_job();

    /* register protocol event handler */
    SetProtocolEventHandler(mmi_bt_bpp_create_job_cnf_hdlr, MSG_ID_BT_BPP_CREATE_JOB_CNF);
    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_CREATING);
    mmi_bt_bpp_entry_creating();

    /* start bpp timer */   
    StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_OBEX_TIMER_DUR, mmi_bt_bpp_obex_timer_expire_hdlr);

    /* clear screens */
    mmi_bt_bpp_del_scr(SCR_BPP_PRINT_SETTING);
    mmi_bt_bpp_del_scr(SCR_BPP_LAYOUT_PREVIEW);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_send_msg
 * DESCRIPTION
 *  This function is to send msg to BT task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_send_msg(U32 msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send = allocate_ilm(MOD_MMI);   
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = MOD_BT;
    ilm_send->sap_id = BT_BPP_SAP;
    ilm_send->msg_id = (kal_uint16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;    
    msg_send_ext_queue(ilm_send);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_retrieve_prog_percentage
 * DESCRIPTION
 *  This function is to retrieve the printing progress.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 ~ 100  The percentage of put process.
 *****************************************************************************/
U8 mmi_bt_bpp_retrieve_prog_percentage(void)
{
    /* Total length of a object */
    if (mmi_bpp_cntx_p->total_send_doc_len == 0)
    {
        return 0;
    }
    return (U8)((((double)mmi_bpp_cntx_p->total_send_doc_len - (double)mmi_bpp_cntx_p->remain_send_doc_len) / (double)mmi_bpp_cntx_p->total_send_doc_len) * 100.0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_background_print
 * DESCRIPTION
 *  This function is to enter the background printing mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_background_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_BACKGROUND_PRINT);

    /* background printing mode on */
    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_BACK_GROUND_PRINT);

    /* clear screens */
    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_BACKGROUND_PRINTING);
    mmi_bt_bpp_del_scr(SCR_BPP_PRINTING);
    StopTimer(FMGR_PROG_UPDATE_TIMER);    
}

#define EVENT_HDLR
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the connect confirm primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_connect_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_connect_cnf_struct* cnf = (bt_bpp_connect_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear protocol event handler */
    ClearProtocolEventHandler(MSG_ID_BT_BPP_CONNECT_CNF);
    StopTimer(BT_BPP_PRINTING_TIMER);    

    /* handle usb mode */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_DISCONNECTING)
    {    
        switch(cnf->cnf_code)
        {
            case BT_BPP_CNF_SUCCESS:
                /* register protocol event handler */
                SetProtocolEventHandler(mmi_bt_bpp_disconnect_ind_hdlr, MSG_ID_BT_BPP_DISCONNECT_IND);
                mmi_bt_bpp_send_disconnect();
                break;
            default:                
                mmi_bt_bpp_reset();
                break;
        }
        return;
    }

    switch(cnf->cnf_code)
    {
        case BT_BPP_CNF_SUCCESS:
            
            /* update context */
            mmi_bpp_cntx_p->g_conn_id = cnf->cm_conn_id;            
            memset(mmi_bpp_cntx_p->printer_name, 0, GOEP_MAX_DEV_NAME);
            strcpy((PS8)(mmi_bpp_cntx_p->printer_name),(PS8)cnf->dev_name);
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_CONNECTED);

            /* connect cnf to CM */
            mmi_bth_connect_ind_hdler(mmi_bpp_cntx_p->bd_addr.lap, 
                                    mmi_bpp_cntx_p->bd_addr.uap, 
                                    mmi_bpp_cntx_p->bd_addr.nap, 
                                    mmi_bpp_cntx_p->printer_name, 
                                    (U32) MMI_BTH_BASIC_PRINTING, 
                                    cnf->cm_conn_id);
            
            /* register protocol event handler */
            SetProtocolEventHandler(mmi_bt_bpp_disconnect_ind_hdlr, MSG_ID_BT_BPP_DISCONNECT_IND);

            /* get printer attributes */
            mmi_bt_bpp_get_printer_attr();

 	     mmi_bt_bpp_clear_scr_db(SCR_BPP_CONNECTING);
            /* clear screen */
            mmi_bt_bpp_del_scr(SCR_BPP_CONNECTING);
            return;
            
        case BT_BPP_CNF_AUTH_FAILED:
            /* reject/cancel case */
            if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_NONE)
            {
                break;
            }

            /* connect failed reset */
            mmi_bt_bpp_reset();

            /*notify app to free the resource*/
            if(mmi_bpp_cntx_p->app_callback)
            {
                mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
            }

            /* clear screen */
            mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_AUTH_FAILED);
            mmi_bt_bpp_del_scr(SCR_BPP_CONNECTING);
            break;

        case BT_BPP_CNF_SCO_REJECT:
            /* reject/cancel case */
            if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_NONE)
            {
                break;
            }
        
            /* connect failed reset */
            mmi_bt_bpp_reset();

            /*notify app to free the resource*/
            if(mmi_bpp_cntx_p->app_callback)
            {
                mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
            }
        
            /* clear screen */
            /* sco link support for MT6601 */
            mmi_bt_popup_operation_not_allowed();
            mmi_bt_bpp_del_scr(SCR_BPP_CONNECTING);
            break;

        default:            
            /* connect failed reset */
            mmi_bt_bpp_reset();

            /*notify app to free the resource*/
            if(mmi_bpp_cntx_p->app_callback)
            {
                mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
            }

            /* clear screen */
            mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_CONNECT_FAILED);
            mmi_bt_bpp_del_scr(SCR_BPP_CONNECTING);
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_auth_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the authentication indication primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_auth_ind_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_authentication_rsp_struct* rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear protocol event handler */
    ClearProtocolEventHandler(MSG_ID_BT_BPP_AUTHENTICATION_IND);

    /* handle usb mode */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_DISCONNECTING)
    {    
        rsp = (bt_bpp_authentication_rsp_struct*)OslConstructDataPtr(sizeof(bt_bpp_authentication_rsp_struct));
        BPP_MEMSET(rsp);
        rsp->cancel = MMI_TRUE;
        
        /* send authentication response to BT */
        mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_AUTHENTICATION_RSP, rsp);
        
        /* clear cntx */
        mmi_bt_bpp_reset();
        return;
    }

    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_CHALLENGE);
    /* entry authenticating screen */
    mmi_bt_bpp_entry_authenticating();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_printer_attr_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the get printer attribute confirm primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_get_printer_attr_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_get_printer_attr_cnf_struct* cnf = (bt_bpp_get_printer_attr_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear protocol event handler */
    ClearProtocolEventHandler(MSG_ID_BT_BPP_GET_PRINTER_ATTR_CNF);
    StopTimer(BT_BPP_PRINTING_TIMER);
    
    /* handle usb mode */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_DISCONNECTING)
    {    
        /* register protocol event handler */
        SetProtocolEventHandler(mmi_bt_bpp_disconnect_ind_hdlr, MSG_ID_BT_BPP_DISCONNECT_IND);
        mmi_bt_bpp_send_disconnect();        
        return;
    }

    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_SETTING);
    /* get printer attributes success */
    if (cnf->cnf_code == BT_BPP_CNF_SUCCESS)
    {
        mmi_bt_bpp_set_printer_attr(cnf);
    }

    /* entry print setting screen */
    mmi_bt_bpp_pre_entry_print_setting(mmi_bpp_cntx_p->printer.got_attr);

    /* clear the getting screen */
    mmi_bt_bpp_del_scr(SCR_BPP_GETTING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_create_job_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the create job confirm primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_create_job_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_create_job_cnf_struct* cnf = (bt_bpp_create_job_cnf_struct*)msg;
    mmi_bpp_xhtml_rsp_enum xhtml_rsp;
    mmi_bpp_xhtml_media_enum Media = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_BT_BPP_CREATE_JOB_CNF);
    StopTimer(BT_BPP_PRINTING_TIMER);

    /* handle usb mode */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_DISCONNECTING)
    {    
        /* wait disconnect ind */
        return;
    }

    switch(cnf->cnf_code)
    {
        case BT_BPP_CNF_STATUS_FAILED:
            mmi_bpp_cntx_p->timer_flag = MMI_TRUE;
        case BT_BPP_CNF_SUCCESS:
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_COMPOSING);
            mmi_bpp_cntx_p->job_id = cnf->job_id;

            /* clear screen */
            if (isInCall() != MMI_TRUE)
            {
                mmi_bt_bpp_entry_composing();
                mmi_bt_bpp_del_scr(SCR_BPP_CREATING);
            }
            else
            {
                mmi_bt_bpp_history_replace(SCR_BPP_CREATING, SCR_BPP_COMPOSING);
            }

            /* compose xhtml file header */
            switch(mmi_bt_bpp_get_media_setting())
            {
                case 0:   /* first one */
                    if (mmi_bpp_cntx_p->printer.got_attr)
                    {
                        if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_A4))
                        {
                            Media = MMI_BPP_XHTML_MEDIA_A4;
                            break;
                        }
                        if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_US))
                        {
                            Media = MMI_BPP_XHTML_MEDIA_US;
                            break;
                        }
                        Media = MMI_BPP_XHTML_MEDIA_4X6;
                    }
                    else
                    {
                        Media = MMI_BPP_XHTML_MEDIA_A4;
                    }
                    break;                        
                case 1:   /* second one (media can only be 3, 5, 6, 7)*/
                    if (mmi_bpp_cntx_p->printer.got_attr)
                    {
                        if ((BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_A4)) && 
                            (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_US)))
                        {
                            /* if A4 and US coexist, implies the second one is US */
                            Media = MMI_BPP_XHTML_MEDIA_US;
                        }
                        else
                        {
                            /* if only A4 or US exists, implies the second one is 4X6 */
                            Media = MMI_BPP_XHTML_MEDIA_4X6;
                        }
                    }
                    else
                    {
                        Media = MMI_BPP_XHTML_MEDIA_US;
                    }
                    break;            
                case 2:
                    Media = MMI_BPP_XHTML_MEDIA_4X6;            
                    break;            
                default:
                    ASSERT(0);
            }
            xhtml_rsp = bpp_compose_xhtml_file_header(Media);
            if (xhtml_rsp != MMI_BPP_XHTML_RSP_DONE)
            {
                /* notify user */
				bpp_cancel_xhtml_composing();		  
		    	mmi_bt_bpp_entry_terminated(MMI_BPP_POPUP_CAUSE_COMPOSE_FAILED);
                break;
            }
        
            /* callback app for composing xhtml document */            
            ASSERT(mmi_bpp_cntx_p->app_callback);
            mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_DONE);
            break;
        default:
            mmi_bt_bpp_clear_scr_db(SCR_BPP_CREATING);

            /*notify app to free the resource*/
            if(mmi_bpp_cntx_p->app_callback)
            {
                mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
            }

            if (isInCall() != MMI_TRUE)
            {
                /* notify user */
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_CREATE_JOB_FAILED);

                /* disconnect process */
                mmi_bt_bpp_send_disconnect();
                mmi_bt_bpp_disconnect_clear_scrs();
                mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
            }
            else
            {
                /* disconnect process */
                mmi_bt_bpp_send_disconnect();
                mmi_bt_bpp_disconnect_clear_scrs();
            }
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the event indication primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_event_ind_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_event_ind_struct* ind = (bt_bpp_event_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_BPP_LOG1(MMI_BPP_EVENT_IND_HDLR, mmi_bpp_cntx_p->status);

    /* handle usb mode */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_DISCONNECTING)
    {    
        /* wait disconnect ind */
        ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
        return;
    }

    switch(ind->cnf_code)
    {
        /* status channel disconencted */
        case BT_BPP_CNF_STATUS_FAILED:
            ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
            StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_TIMER_DUR, mmi_bt_bpp_timer_expire_hdlr);
            mmi_bpp_cntx_p->timer_flag = MMI_TRUE;
            break;
            
        case BT_BPP_CNF_SUCCESS:
            /* job canceled case */
            if ((ind->job_state == BT_BPP_JOB_STATE_ABORTED) ||
                (ind->job_state == BT_BPP_JOB_STATE_CANCELED)||
                (ind->job_state == BT_BPP_JOB_STATE_UNKNOWN) )
            {            
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_CANCELED);

                switch(mmi_bpp_cntx_p->status)
                {                    
                    case MMI_BPP_STATUS_COMPOSING:
                        /* cancel composing process */
                        bpp_cancel_xhtml_composing();
                        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_JOB_CANCELED);
                        
                        /* disconnect */
                        mmi_bt_bpp_send_disconnect();
                         
                        /* add disconnect screen to history */
                        if (isInCall() != MMI_TRUE)
                        {
                            mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
                        }
                        else
                        {
                            mmi_bt_bpp_history_replace(SCR_BPP_COMPOSING, SCR_BPP_DISCONNECTING);
                        }
                        
                        /* clear bpp screens */
                        mmi_bt_bpp_disconnect_clear_scrs();
                        break;
                        
                    case MMI_BPP_STATUS_FORE_GROUND_PRINT:
                    case MMI_BPP_STATUS_FORE_GROUND_STOPPED:
                        /* disconnect */
                        mmi_bt_bpp_send_disconnect();
                        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_JOB_CANCELED);
                        
                        if (isInCall() != MMI_TRUE)
                        {                        
                            mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
                        }
                        else
                        {
                            mmi_bt_bpp_history_replace(SCR_BPP_PRINTING, SCR_BPP_DISCONNECTING);                            
                        }
                        
                        /* clear bpp screens */
                        mmi_bt_bpp_disconnect_clear_scrs();
                        break;                        
                        
                    case MMI_BPP_STATUS_BACK_GROUND_PRINT:
                    case MMI_BPP_STATUS_BACK_GROUND_STOPPED:
                        /* disconnect */
                        mmi_bt_bpp_send_disconnect();
                        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_JOB_CANCELED);
                        break;
                        
                    default:
                        MMI_BPP_STATUS_ERR();
                        break;
                }
            }

            /* job ok -> check printer */
            if ((ind->job_state == BT_BPP_JOB_STATE_PRINTING) && (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_FORE_GROUND_STOPPED))
            {
                /* check current screen */
                if(GetActiveScreenId()== SCR_BPP_TROUBLE)
                {
                    mmi_bt_bpp_go_back_history();
                }
                else
                {
                    mmi_bt_bpp_del_scr(SCR_BPP_TROUBLE);
                }
                
                mmi_bt_bpp_blinking(MMI_BPP_BLINK_START);
                MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_FORE_GROUND_PRINT);
                break;
            }
            if ((ind->job_state == BT_BPP_JOB_STATE_PRINTING) && (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_BACK_GROUND_STOPPED))
            {
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_PRINTING);
                mmi_bt_bpp_blinking(MMI_BPP_BLINK_START);
                MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_BACK_GROUND_PRINT);
                break;
            }            
            if ((ind->job_state == BT_BPP_JOB_STATE_STOPPED) && (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_FORE_GROUND_PRINT))
            {
                mmi_bpp_cntx_p->stopped_reason = ind->printer_reason;
                /* check current screen */
                if(GetActiveScreenId()== SCR_BPP_PRINTING)
                {
                    mmi_bt_bpp_entry_trouble();
                }
                else
                {
                    mmi_bt_bpp_insert_before_history(SCR_BPP_PRINTING, SCR_BPP_TROUBLE);
                }
                
                mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
                MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_FORE_GROUND_STOPPED);
                break;
            }
            if ((ind->job_state == BT_BPP_JOB_STATE_STOPPED) && (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_BACK_GROUND_PRINT))
            {
                mmi_bpp_cntx_p->stopped_reason = ind->printer_reason;
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_TROUBLE);
                mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
                MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_BACK_GROUND_STOPPED);
                break;
            }      
            break;
            
        case BT_BPP_CNF_FAILED:
        case BT_BPP_CNF_WRITE_FILE_FAILED:
            MMI_BPP_LOG(MMI_BPP_EVENT_IND_HDLR_ERROR_EVENT);
            break;
            
        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_send_doc_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle the send document confirm primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_send_doc_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_send_doc_cnf_struct* cnf = (bt_bpp_send_doc_cnf_struct*)msg;
    U16 cur_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ClearProtocolEventHandler(MSG_ID_BT_BPP_SEND_DOC_CNF);

    /* handle usb mode */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_DISCONNECTING)
    {    
        /* wait disconnect ind */        
        ClearProtocolEventHandler(MSG_ID_BT_BPP_PROG_UPDATE_IND);
        ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
        StopTimer(BT_BPP_PRINTING_TIMER);
        return;
    }

    if ((cnf->cnf_code == BT_BPP_CNF_WRITE_FILE_FAILED))
    {
        FS_Delete((WCHAR *) mmi_bpp_cntx_p->xhtml_file);
        ClearProtocolEventHandler(MSG_ID_BT_BPP_PROG_UPDATE_IND);

        cur_id = GetActiveScreenId();
        switch(cur_id)
        {
            case SCR_BPP_CONNECTING:
            case SCR_BPP_AUTHENTICATING:
            case SCR_BPP_COMPOSING:
            case SCR_BPP_GETTING:
            case SCR_BPP_PRINT_SETTING:
            case SCR_BPP_LAYOUT_PREVIEW:
            case SCR_BPP_CREATING:
                ASSERT(0);
                break;

            /* printing */
            case SCR_BPP_PRINTING:
            case SCR_BPP_TROUBLE:
                /* popup FS error */
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_READ_FILE_FAILED);

                /* disconnect process */
                /* add disconnect screen to history*/
                MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_JOB_CANCELED);
                mmi_bt_bpp_send_disconnect();
                mmi_bt_bpp_disconnect_clear_scrs();
                mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);            
                break;
                
            case SCR_BPP_DISCONNECTING:
                break;

            /* other screens */                
            default:
                /* popup FS error */
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_READ_FILE_FAILED);
                switch(mmi_bpp_cntx_p->status)
                {
                    case MMI_BPP_STATUS_FORE_GROUND_PRINT:
                    case MMI_BPP_STATUS_FORE_GROUND_STOPPED:
                        /* disconnect */
                        mmi_bt_bpp_send_disconnect();
                        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_JOB_CANCELED);
                        
                        if (isInCall() != MMI_TRUE)
                        {                        
                            mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
                        }
                        else
                        {
                            mmi_bt_bpp_history_replace(SCR_BPP_PRINTING, SCR_BPP_DISCONNECTING);                            
                        }
                        
                        /* clear bpp screens */
                        mmi_bt_bpp_disconnect_clear_scrs();                        
                        break;

                    case MMI_BPP_STATUS_BACK_GROUND_PRINT:                        
                    case MMI_BPP_STATUS_BACK_GROUND_STOPPED:
                        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_JOB_CANCELED);
                        mmi_bt_bpp_send_disconnect();
                        mmi_bt_bpp_disconnect_clear_scrs();
                        break;
                        
                    case MMI_BPP_STATUS_JOB_CANCELED:
                    case MMI_BPP_STATUS_PRINTED:
                    case MMI_BPP_STATUS_DISCONNECTING:
                        break;
                        
                    default:
                        ASSERT(0);
                        break;
                }
                break;
        }    
        mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
        return;
    }

    if ((cnf->cnf_code != BT_BPP_CNF_SUCCESS)  ||
        (cnf->job_id!= mmi_bpp_cntx_p->job_id) ||
        (cnf->cm_conn_id != mmi_bpp_cntx_p->g_conn_id))
    {
        ASSERT(0);
    }

    /* success case */
    if (mmi_bpp_cntx_p->status == MMI_BPP_STATUS_CANCELED)
    {
        if (mmi_bpp_cntx_p->timer_flag)
        {
            StopTimer(BT_BPP_PRINTING_TIMER);
        }
        else
        {
            ClearProtocolEventHandler(MSG_ID_BT_BPP_EVENT_IND);
        }
        ClearProtocolEventHandler(MSG_ID_BT_BPP_PROG_UPDATE_IND);
    }

    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_PRINTED);
    mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_prog_update_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the progress update indication primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_prog_update_ind_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_prog_update_ind_struct* ind = (bt_bpp_prog_update_ind_struct*)msg;
    bt_bpp_prog_update_rsp_struct* rsp;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if ((ind->cm_conn_id == mmi_bpp_cntx_p->g_conn_id) &&
        (ind->job_id == mmi_bpp_cntx_p->job_id))
    {
        if (mmi_bpp_cntx_p->total_send_doc_len == 0)
            mmi_bpp_cntx_p->total_send_doc_len = ind->remain_len;
        mmi_bpp_cntx_p->remain_send_doc_len = ind->remain_len;
    }
    else
    {
        MMI_BPP_LOG4(MMI_BPP_PROG_UPDATE_IND_ERROR, ind->cm_conn_id, mmi_bpp_cntx_p->g_conn_id, ind->job_id ,mmi_bpp_cntx_p->job_id);
    }

    rsp = (bt_bpp_prog_update_rsp_struct*)OslConstructDataPtr(sizeof(bt_bpp_prog_update_rsp_struct));
    BPP_MEMSET(rsp);
    rsp->cm_conn_id = ind->cm_conn_id;
    rsp->job_id = ind->job_id;
    
    /* send prog_update rsp */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_PROG_UPDATE_RSP, rsp);     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_disconnect_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the disconnect indication primitive from BT
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_disconnect_ind_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ClearProtocolEventHandler(MSG_ID_BT_BPP_DISCONNECT_IND);    
    StopTimer(BT_BPP_PRINTING_TIMER);
    mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);

    cur_id = GetActiveScreenId();
    MMI_BPP_LOG2(MMI_BPP_DISCONNECT_IND_HDLR, cur_id, mmi_bpp_cntx_p->status);    

    switch(cur_id)
    {
        case SCR_BPP_CONNECTING:
        case SCR_BPP_AUTHENTICATING:
            ASSERT(0);
            
        case SCR_BPP_COMPOSING:
            bpp_cancel_xhtml_composing();
        case SCR_BPP_GETTING:
        case SCR_BPP_PRINT_SETTING:
        case SCR_BPP_LAYOUT_PREVIEW:
        case SCR_BPP_CREATING:
            mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_DISCONNECTED);
            mmi_bt_bpp_clear_scr_db(cur_id);
            mmi_bth_disconnect_ind_hdler(mmi_bpp_cntx_p->bd_addr.lap,
                                        mmi_bpp_cntx_p->bd_addr.uap,
                                        mmi_bpp_cntx_p->bd_addr.nap,
                                        (U32)MMI_BTH_BASIC_PRINTING,
                                        mmi_bpp_cntx_p->g_conn_id);              //call CM
            break;
            
        case SCR_BPP_PRINTING:
        case SCR_BPP_TROUBLE:
        case SCR_BPP_DISCONNECTING:
        default:
            if (mmi_bpp_cntx_p->cm_disc_flag)
            {
                mmi_bth_disconnect_cnf_hdler(MMI_TRUE, 
                                        mmi_bpp_cntx_p->bd_addr.lap,
                                        mmi_bpp_cntx_p->bd_addr.uap,
                                        mmi_bpp_cntx_p->bd_addr.nap,
                                        (U32)MMI_BTH_BASIC_PRINTING,
                                        mmi_bpp_cntx_p->g_conn_id);
                mmi_bpp_cntx_p->cm_disc_flag = MMI_FALSE;
            }
            else
            {
                mmi_bth_disconnect_ind_hdler(mmi_bpp_cntx_p->bd_addr.lap,
                                        mmi_bpp_cntx_p->bd_addr.uap,
                                        mmi_bpp_cntx_p->bd_addr.nap,
                                        (U32)MMI_BTH_BASIC_PRINTING,
                                        mmi_bpp_cntx_p->g_conn_id);              //call CM
            }

            switch(mmi_bpp_cntx_p->status)
            {
                case MMI_BPP_STATUS_PRINTED:
                    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_PRINTED);
                    /* to handle cancel print receive send doc cnf case */
                    DeleteScreenIfPresent(SCR_BPP_DISCONNECTING);
                    break;

                case MMI_BPP_STATUS_DISCONNECTING:
                case MMI_BPP_STATUS_NONE:
                    mmi_bt_bpp_init();
                    mmi_bt_bpp_disconnect_clear_scrs();
                    return;

                case MMI_BPP_STATUS_SETTING:
                    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_DISCONNECTED);
                    mmi_bt_bpp_reset();
                    mmi_bt_bpp_disconnect_clear_scrs();
                    return;

                /* handle pop up too fast case */
                case MMI_BPP_STATUS_CREATING:
                case MMI_BPP_STATUS_COMPOSING:
                case MMI_BPP_STATUS_JOB_CANCELED:
                case MMI_BPP_STATUS_CANCELED:
                    if (cur_id == SCR_BPP_DISCONNECTING)
                    {
                        //mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_DISCONNECTED);
                        DeleteScreenIfPresent(SCR_BPP_DISCONNECTING);
                        mmi_bt_bpp_go_back_history();
                    }
                    else
                    {
                        DeleteScreenIfPresent(SCR_BPP_DISCONNECTING);
                    }                                             
                    break;
                    
                default:
                    mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_DISCONNECTED);
                    break;
            }
            break;
    }
    mmi_bt_bpp_disconnect_clear_scrs();
    mmi_bt_bpp_init();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_timer_expire_hdlr
 * DESCRIPTION
 *  This function is to handle the bpp printing timer expires event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_timer_expire_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_TIMER_EXPIRE_HDLR);

    mmi_bpp_cntx_p->stopped_reason = BT_BPP_PRINTER_REASON_ATTENTION;
    switch (mmi_bpp_cntx_p->status)
    {
        case MMI_BPP_STATUS_FORE_GROUND_PRINT:
            /* check current screen */
            if(GetActiveScreenId()== SCR_BPP_PRINTING)
            {
                mmi_bt_bpp_entry_trouble();
            }
            else
            {
                mmi_bt_bpp_insert_before_history(SCR_BPP_PRINTING, SCR_BPP_TROUBLE);
            }

            mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_FORE_GROUND_STOPPED);            
            break;
            
        case MMI_BPP_STATUS_BACK_GROUND_PRINT:            
            mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_TROUBLE);
            mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
            MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_BACK_GROUND_STOPPED);
            break;
            
        case MMI_BPP_STATUS_DISCONNECTING:
            mmi_bt_bpp_blinking(MMI_BPP_BLINK_STOP);
            return;
            
        default:
            break;
    }
    StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_TIMER_DUR, mmi_bt_bpp_timer_expire_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_cm_timer_expire_hdlr
 * DESCRIPTION
 *  This function is to handle the bpp timer expires event for cm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_cm_timer_expire_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_TIMER_EXPIRE_HDLR);

    mmi_bt_bpp_clear_scr_db(SCR_BPP_DUMMY);
    cur_id = GetActiveScreenId();
    switch(cur_id)
    {
        case SCR_BPP_DUMMY:
            mmi_bt_bpp_go_back_history();
	     break;
	 default:
            DeleteScreenIfPresent(SCR_BPP_DUMMY);
            break; 	     
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_obex_timer_expire_hdlr
 * DESCRIPTION
 *  This function is to handle the bpp obex timer expires event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_obex_timer_expire_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_TIMER_EXPIRE_HDLR);

    switch (mmi_bpp_cntx_p->status)
    {
        case MMI_BPP_STATUS_GETTING:
            ClearProtocolEventHandler(MSG_ID_BT_BPP_GET_PRINTER_ATTR_CNF);
            /* disconnect process */
            mmi_bt_bpp_send_disconnect();            
            break;
            
        case MMI_BPP_STATUS_CREATING:
            ClearProtocolEventHandler(MSG_ID_BT_BPP_CREATE_JOB_CNF);
            mmi_bt_bpp_clear_scr_db(SCR_BPP_CREATING);
            if (isInCall() != MMI_TRUE)
            {
                /* notify user */
                mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_CREATE_JOB_FAILED);

                /* disconnect process */
                mmi_bt_bpp_send_disconnect();
                mmi_bt_bpp_disconnect_clear_scrs();
                mmi_bt_bpp_add_history(SCR_BPP_DISCONNECTING);
            }
            else
            {
                /* disconnect process */
                mmi_bt_bpp_send_disconnect();
                mmi_bt_bpp_disconnect_clear_scrs();
            }
            break;

        /* handle usb case -> wait disconnect ind */
        case MMI_BPP_STATUS_DISCONNECTING:
            return;

        default:
            ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_connect_timer_expire_hdlr
 * DESCRIPTION
 *  This function is to handle the bpp connect timer expires event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_connect_timer_expire_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CONNECT_TIMER_EXPIRE_HDLR);

    switch (mmi_bpp_cntx_p->status)
    {
        case MMI_BPP_STATUS_CONNECTING:
            ClearProtocolEventHandler(MSG_ID_BT_BPP_AUTHENTICATION_IND);
            /* disconnect process */
            mmi_bt_bpp_send_disconnect();            
            break;
            
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_disc_timer_expire_hdlr
 * DESCRIPTION
 *  This function is to handle the bpp disconnect timer expires event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_disc_timer_expire_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_disconnect_req_struct* req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_DISC_TIMER_EXPIRE_HDLR);
    req = (bt_bpp_disconnect_req_struct*)OslConstructDataPtr(sizeof(bt_bpp_disconnect_req_struct));
    BPP_MEMSET(req);
    req->cm_conn_id = mmi_bpp_cntx_p->g_conn_id;
    req->disc_timeout = MMI_TRUE;

    /* send disconnect req to BT */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_DISCONNECT_REQ, req);
}

#define INTERNAL_API
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_create_job
 * DESCRIPTION
 *  This function is to send a create job request to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_create_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bpp_create_job_req_struct* req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_CREATE_JOB);
    req = (bt_bpp_create_job_req_struct*)OslConstructDataPtr(sizeof(bt_bpp_create_job_req_struct));
    BPP_MEMSET(req);
    req->cm_conn_id = mmi_bpp_cntx_p->g_conn_id;
    req->Copies = (U16)gui_atoi(mmi_bt_bpp_get_copies_setting());

    if (mmi_bpp_cntx_p->printer.got_attr)
    {
        if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.DocFormat, BPP_ADP_DOC_FORMAT_MASK_XHTML_MULTI))
        {
            req->DocFormat = BPP_ADP_DOC_FORMAT_MASK_XHTML_MULTI;
        }
        else
        {
            req->DocFormat = BPP_ADP_DOC_FORMAT_MASK_XHTML;
            MMI_BPP_LOG(MMI_BPP_CREATE_JOB_CANT_SUPPORT_INLINE);
        }
    }
    else
    {
        req->DocFormat = BPP_ADP_DOC_FORMAT_MASK_XHTML_MULTI;
    }
        
    /* user option must be arranged as A4 -> US -> 4X6 */
    /* therefore the searching way is according to this feature */
    switch(mmi_bt_bpp_get_media_setting())
    {
        case 0:   /* first one */
            if (mmi_bpp_cntx_p->printer.got_attr)
            {
                if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_A4))
                {
                    req->Media = BPP_ADP_MEDIA_MASK_A4;
                    break;
                }
                if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_US))
                {
                    req->Media = BPP_ADP_MEDIA_MASK_US;
                    break;
                }
                if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_4X6))
                {
                    req->Media = BPP_ADP_MEDIA_MASK_4X6;
                    break;
                }
                req->Media = BPP_ADP_MEDIA_MASK_4X6_IOT;
            }
            else
            {
                req->Media = BPP_ADP_MEDIA_MASK_A4;
            }
            break;                        
        case 1:   /* second one */
            if (mmi_bpp_cntx_p->printer.got_attr)
            {
                if ((BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_A4)) && 
                    (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_US)))
                {
                    /* if A4 and US coexist, implies the second one is US */
                    req->Media = BPP_ADP_MEDIA_MASK_US;
                }
                else
                {
                    /* if only A4 or US exists, implies the second one is 4X6 */
                    if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_4X6))
                    {
                        req->Media = BPP_ADP_MEDIA_MASK_4X6;
                        break;
                    }
                    req->Media = BPP_ADP_MEDIA_MASK_4X6_IOT;
                }
            }
            else
            {
                req->Media = BPP_ADP_MEDIA_MASK_US;
            }
            break;            
        case 2:             
            if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_MEDIA_MASK_4X6))
            {
                req->Media = BPP_ADP_MEDIA_MASK_4X6;
                break;
            }
            req->Media = BPP_ADP_MEDIA_MASK_4X6_IOT;           
            break;            
        default:
            ASSERT(0);
    }

    /* user option must be arranged as High -> Normal -> Draft */
    switch(mmi_bt_bpp_get_quality_setting())
    {
        case 0:   /* first one */
            if (mmi_bpp_cntx_p->printer.got_attr)
            {
                if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Quality, BPP_ADP_QUALITY_MASK_HIGH))
                {
                    req->Quality = BPP_ADP_QUALITY_MASK_HIGH;
                    break;
                }
                if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Quality, BPP_ADP_QUALITY_MASK_NORMAL))
                {
                    req->Quality = BPP_ADP_QUALITY_MASK_NORMAL;
                    break;
                }
                req->Quality = BPP_ADP_QUALITY_MASK_DRAFT;
            }
            else
            {
                req->Quality = BPP_ADP_QUALITY_MASK_HIGH;
            }
            break;                        
        case 1:   /* second one (quality can only be 3, 5, 6, 7)*/
            if (mmi_bpp_cntx_p->printer.got_attr)
            {
                if ((BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_QUALITY_MASK_HIGH)) && 
                    (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Media, BPP_ADP_QUALITY_MASK_NORMAL)))
                {
                    /* if High and Normal coexist, implies the second one is Normal */
                    req->Quality = BPP_ADP_QUALITY_MASK_NORMAL;
                }
                else
                {
                    /* if only High or Normal exists, implies the second one is Draft */
                    req->Quality = BPP_ADP_QUALITY_MASK_DRAFT;
                }
            }
            else
            {
                req->Quality = BPP_ADP_QUALITY_MASK_NORMAL;
            }
            break;            
        case 2:
            req->Quality = BPP_ADP_QUALITY_MASK_DRAFT;            
            break;            
        default:
            ASSERT(0);
    }
    
    switch(mmi_bt_bpp_get_preview_img())
    {
        case IMG_BPP_LAYOUT_L_S1_C1:   /* L_S1_1page */
        case IMG_BPP_LAYOUT_L_S1_C2:   /* L_S1_2page */              
        case IMG_BPP_LAYOUT_L_S1_C4:   /* L_S1_4page */              
        case IMG_BPP_LAYOUT_L_S2_C1:   /* L_S2_1page */
        case IMG_BPP_LAYOUT_L_S2_C2:   /* L_S2_2page */
        case IMG_BPP_LAYOUT_L_S2_C4:   /* L_S2_4page */
            req->Orientation = BPP_ADP_ORIENTATION_MASK_L;
            goto SIDES;
        /* Portrait */
        default:
            req->Orientation = BPP_ADP_ORIENTATION_MASK_P;
            goto SIDES;
    }
    
SIDES:
    switch(mmi_bt_bpp_get_preview_img())
    {
        case IMG_BPP_LAYOUT_L_S1_C1:   /* L_S1_1page */
        case IMG_BPP_LAYOUT_L_S1_C2:   /* L_S1_2page */              
        case IMG_BPP_LAYOUT_L_S1_C4:   /* L_S1_4page */              
        case IMG_BPP_LAYOUT_P_S1_C1:   /* P_S1_1page */
        case IMG_BPP_LAYOUT_P_S1_C2:   /* P_S1_2page */
        case IMG_BPP_LAYOUT_P_S1_C4:   /* P_S1_4page */
            req->Sides = BPP_ADP_SIDES_MASK_ONE;
            goto PAGES;
        /* two-sided */
        default:
            if (BPP_GET_FLAG(mmi_bpp_cntx_p->printer.Sides, BPP_ADP_SIDES_MASK_TWO_SHORT))
            {
                req->Sides = BPP_ADP_SIDES_MASK_TWO_SHORT;
            }
            else
            {
                req->Sides = BPP_ADP_SIDES_MASK_TWO_LONG;
            }
            goto PAGES;
    }

PAGES:
    switch(mmi_bt_bpp_get_preview_img())
    {
        case IMG_BPP_LAYOUT_L_S1_C1:   /* L_S1_1page */
        case IMG_BPP_LAYOUT_L_S2_C1:   /* L_S2_1page */            
        case IMG_BPP_LAYOUT_P_S1_C1:   /* P_S1_1page */
        case IMG_BPP_LAYOUT_P_S2_C1:   /* P_S2_1page */        
            req->NumberUp = BPP_ADP_NUMBER_UP_MASK_1;
            break;
        case IMG_BPP_LAYOUT_L_S1_C2:   /* L_S1_2page */
        case IMG_BPP_LAYOUT_L_S2_C2:   /* L_S2_2page */
        case IMG_BPP_LAYOUT_P_S1_C2:   /* P_S1_2page */                        
        case IMG_BPP_LAYOUT_P_S2_C2:   /* P_S2_2page */            
            req->NumberUp = BPP_ADP_NUMBER_UP_MASK_2;
            break;            
        case IMG_BPP_LAYOUT_L_S1_C4:   /* L_S1_4page */
        case IMG_BPP_LAYOUT_L_S2_C4:   /* L_S2_4page */        
        case IMG_BPP_LAYOUT_P_S1_C4:   /* P_S1_4page */            
        case IMG_BPP_LAYOUT_P_S2_C4:   /* P_S2_4page */
            req->NumberUp = BPP_ADP_NUMBER_UP_MASK_4;
            break;
        default:
            ASSERT(0);
    } 
         
    /* send create job request */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_CREATE_JOB_REQ, req);     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_set_printer_attr
 * DESCRIPTION
 *  This function is to set the printer attributes from confirm primitive
 * PARAMETERS
 *  bt_bpp_get_printer_attr_cnf_struct*
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_set_printer_attr(bt_bpp_get_printer_attr_cnf_struct* cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG(MMI_BPP_SET_PRINTER_ATTR);

    /* Document Format default xhtml only now */
    ASSERT( BPP_GET_FLAG(cnf->DocFormat, BPP_ADP_DOC_FORMAT_MASK_XHTML) ||
            BPP_GET_FLAG(cnf->DocFormat, BPP_ADP_DOC_FORMAT_MASK_XHTML_MULTI));

    /* set attributes */
    mmi_bpp_cntx_p->printer.got_attr = MMI_TRUE;
    mmi_bpp_cntx_p->printer.DocFormat = cnf->DocFormat;    
    mmi_bpp_cntx_p->printer.Copies = cnf->Copies;
    mmi_bpp_cntx_p->printer.Media = cnf->Media;
    mmi_bpp_cntx_p->printer.NumberUp = cnf->NumberUp;
    mmi_bpp_cntx_p->printer.Orientation = cnf->Orientation;
    mmi_bpp_cntx_p->printer.Quality = cnf->Quality;
    mmi_bpp_cntx_p->printer.Sides = cnf->Sides;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_get_printer_attr
 * DESCRIPTION
 *  This function is to connect printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_get_printer_attr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG1(MMI_BPP_GET_PRINTER_ATTR, mmi_bpp_cntx_p->printer.got_attr);

    /* check associated printer bd_addr */
    if (memcmp(&(mmi_bpp_cntx_p->bd_addr.lap), &(mmi_bpp_cntx_p->printer.bd_addr.lap), 4) ||
        memcmp(&(mmi_bpp_cntx_p->bd_addr.uap), &(mmi_bpp_cntx_p->printer.bd_addr.uap), 1) ||
        memcmp(&(mmi_bpp_cntx_p->bd_addr.nap), &(mmi_bpp_cntx_p->printer.bd_addr.nap), 2))
    {      
        /* set new associated printer */
        memset(&(mmi_bpp_cntx_p->printer), 0, sizeof(mmi_bpp_printer_struct));
        memcpy(&(mmi_bpp_cntx_p->printer.bd_addr), &(mmi_bpp_cntx_p->bd_addr), sizeof(goep_bd_addr_struct));

        /* Trigger get operation */
        goto GET_ATTR;
    }
    /*  the same printer -> check got attributes flag  */
    if (mmi_bpp_cntx_p->printer.got_attr)
    {
        MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_SETTING);
        mmi_bt_bpp_pre_entry_print_setting(mmi_bpp_cntx_p->printer.got_attr);
        return;
    }    
    else
    {
        goto GET_ATTR;   
    }
    
GET_ATTR:
{
    bt_bpp_get_printer_attr_req_struct* req;

    req = (bt_bpp_get_printer_attr_req_struct*)OslConstructDataPtr(sizeof(bt_bpp_get_printer_attr_req_struct));
    BPP_MEMSET(req);
    req->cm_conn_id = mmi_bpp_cntx_p->g_conn_id;
    req->DocFormat = req->Sides = req->Copies = req->NumberUp = req->Orientation = req->Media = req->Quality = MMI_TRUE;

    /* send get printer attribute req to BT */
    mmi_bt_bpp_send_msg(MSG_ID_BT_BPP_GET_PRINTER_ATTR_REQ, req);     
    
    /* register protocol event handler */
    SetProtocolEventHandler(mmi_bt_bpp_get_printer_attr_cnf_hdlr, MSG_ID_BT_BPP_GET_PRINTER_ATTR_CNF);
    MMI_BPP_STATUS_TRANS(MMI_BPP_STATUS_GETTING);
    mmi_bpp_cntx_p->printer.got_attr = MMI_FALSE;

    /* start bpp timer */   
    StartTimer(BT_BPP_PRINTING_TIMER, MMI_BPP_OBEX_TIMER_DUR, mmi_bt_bpp_obex_timer_expire_hdlr);

    if (isInCall() != MMI_TRUE)
    {                    
        mmi_bt_bpp_entry_getting();
    }
    else
    {
        mmi_bt_bpp_history_replace(SCR_BPP_CONNECTING, SCR_BPP_GETTING);
    }
}
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_set_printer_attr
 * DESCRIPTION
 *  This function is LSK when select dev success
 * PARAMETERS
 *  bt_bpp_get_printer_attr_cnf_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_bpp_cm_call_back(MMI_BOOL result, U32 lap, U8 uap, U16 nap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bth_bt_addr bd_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BPP_LOG4(MMI_BPP_CALL_BACK_APP, result, lap, uap, nap);

    /* MMI_TRUE:  searching result is okay, go on*/
    if(result)
    {
        bd_addr.lap = lap;
        bd_addr.uap = uap;
        bd_addr.nap = nap;

        mmi_bt_bpp_connect_printer(bd_addr);
    }
    else
    {
//     mmi_bt_bpp_popup(MMI_BPP_POPUP_CAUSE_CANCELED);
        if(mmi_bpp_cntx_p->app_callback)
        {
            mmi_bpp_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
        }

        mmi_bt_bpp_reset();
    }
}


#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /*__MMI_BT_MTK_SUPPORT__*/
