/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeHandler.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__

/* for debeg messages */
#ifdef DEMO_PROJECT
#define __MMI_PICT_BRIDGE_KEEP_XML_DATA__
#endif


#include "FileManagerGProt.h"

#include "wgui_status_icons.h"

#ifdef __MTK_TARGET__
#include "Usbimage_drv.h"
#endif

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeGProt.h"
#include "PictBridgeStruct.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif


/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_setting_struct g_pict_bridge_setting;


/*
 * Local Variable
 */
#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
static S8 image_file_path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
#endif
#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
static S8 ansii_file_path[FMGR_MAX_PATH_LEN + 1];
#endif


#ifdef __MTK_TARGET__

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_init
 * DESCRIPTION
 *  PictBridge initialization function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_protocol_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_pict_dps_discovery_ind, MSG_ID_USB_MMI_DPS_DISCOVERY_IND);
    SetProtocolEventHandler(mmi_pict_receive_dps_operation_ind, MSG_ID_USB_MMI_DPS_HRESPONSE_IND);
    SetProtocolEventHandler(mmi_pict_receive_dps_event_ind, MSG_ID_USB_MMI_DPS_HREQUEST_IND);
    SetProtocolEventHandler(mmi_pict_send_dps_operation_rsp, MSG_ID_USB_MMI_DPS_DREQUEST_CONF);
    SetProtocolEventHandler(mmi_pict_send_dps_event_rsp, MSG_ID_USB_MMI_DPS_DRESPONSE_CONF);

    SetProtocolEventHandler(mmi_pict_connect_to_pc_ind, MSG_ID_USB_MMI_PTP_CONNECT_TO_PC_IND);
    SetProtocolEventHandler(mmi_pict_open_file_fail_ind, MSG_ID_USB_MMI_PTP_OPEN_FILE_FAIL_IND);
    SetProtocolEventHandler(mmi_pict_host_reset, MSG_ID_USB_MMI_PTP_HOST_RESET_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_operation_rsp
 * DESCRIPTION
 *  Response from USB task of DPS operation to the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_operation_rsp(void *info)
{

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_operation_req
 * DESCRIPTION
 *  Send DPS operation to the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_operation_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    usb_image_xml_struct *dps_operation_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.next_operation_request == NULL)
    {
        return;
    }

    /* prepare XML package */
    (*g_pict_bridge_context.next_operation_request) ();

    if (g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_start_job)
    {
        MMI_ASSERT(strlen(g_pict_bridge_context.xml_operation_cmd) < g_pict_bridge_context.xml_start_job_cmd_size);
    }
    else
    {
        MMI_ASSERT(strlen(g_pict_bridge_context.xml_operation_cmd) < g_pict_bridge_context.xml_operation_cmd_size);
    }

    /* temporarily ignore DPS event from printer after DPS operation is sent */
    ClearProtocolEventHandler(MSG_ID_USB_MMI_DPS_HREQUEST_IND);
    /* ignore the pending message in queue because DPS operation is sent by the user manually */
    ClearProtocolEventHandler(MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_USB;
    Message.oslMsgId = MSG_ID_MMI_USB_DPS_DREQUEST_REQ;
    dps_operation_req = (usb_image_xml_struct*) OslConstructDataPtr(sizeof(usb_image_xml_struct));
    dps_operation_req->xml_address = (U8*) g_pict_bridge_context.xml_operation_cmd;
    dps_operation_req->xml_packet_size = strlen(g_pict_bridge_context.xml_operation_cmd);
    Message.oslDataPtr = (oslParaType*) dps_operation_req;
    Message.oslPeerBuffPtr = NULL;

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_operation_req->xml_address, dps_operation_req->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_receive_dps_operation_res
 * DESCRIPTION
 *  Response to the USB task of DPS operation result from the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_receive_dps_operation_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_USB;
    Message.oslMsgId = MSG_ID_MMI_USB_DPS_HRESPONSE_CONF;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_receive_dps_operation_ind
 * DESCRIPTION
 *  Receive DPS operation result from the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_receive_dps_operation_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_image_xml_struct *dps_operation_ind;

    FS_HANDLE fs_handle;
    U32 written_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dps_operation_ind = (usb_image_xml_struct*) info;

    /* Continue to wait DPS event from printer */
    SetProtocolEventHandler(mmi_pict_receive_dps_event_ind, MSG_ID_USB_MMI_DPS_HREQUEST_IND);

    fs_handle = FS_Open((U16*) PICT_XML_PATH, FS_CREATE | FS_READ_WRITE);
    FS_Write(fs_handle, (void*) dps_operation_ind->xml_address, dps_operation_ind->xml_packet_size, &written_length);
    FS_Truncate(fs_handle); 
    FS_Close(fs_handle);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_operation_ind->xml_address, dps_operation_ind->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif

    mmi_pict_parse_xml_script();

    mmi_pict_receive_dps_operation_res();

    //mmi_pict_send_dps_operation_req();
    mmi_pict_send_pending_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_operation_rsp
 * DESCRIPTION
 *  Response from USB task of DPS event result to the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_event_rsp(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.next_event_request = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_dps_event_req
 * DESCRIPTION
 *  Send DPS event result to the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_dps_event_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    usb_image_xml_struct *dps_event_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.next_event_request == NULL)
    {
        return;
    }

    /* prepare XML package */
    (*g_pict_bridge_context.next_event_request) ();

    MMI_ASSERT(strlen(g_pict_bridge_context.xml_event_cmd) < g_pict_bridge_context.xml_event_cmd_size);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_USB;
    Message.oslMsgId = MSG_ID_MMI_USB_DPS_DRESPONSE_REQ;
    dps_event_req = (usb_image_xml_struct*) OslConstructDataPtr(sizeof(usb_image_xml_struct));
    dps_event_req->xml_address = (U8*) g_pict_bridge_context.xml_event_cmd;
    dps_event_req->xml_packet_size = strlen(g_pict_bridge_context.xml_event_cmd);
    Message.oslDataPtr = (oslParaType*) dps_event_req;
    Message.oslPeerBuffPtr = NULL;

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_event_req->xml_address, dps_event_req->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif

    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_receive_dps_event_res
 * DESCRIPTION
 *  Response to the USB task of DPS event from the printer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_receive_dps_event_res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_USB;
    Message.oslMsgId = MSG_ID_MMI_USB_DPS_HREQUEST_CONF;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_receive_dps_event_ind
 * DESCRIPTION
 *  Receive DPS event from the printer
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_receive_dps_event_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_image_xml_struct *dps_event_ind;

    FS_HANDLE fs_handle;
    U32 written_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dps_event_ind = (usb_image_xml_struct*) info;

    fs_handle = FS_Open((U16*) PICT_XML_PATH, FS_CREATE | FS_READ_WRITE);
    FS_Write(fs_handle, (void*) dps_event_ind->xml_address, dps_event_ind->xml_packet_size, &written_length); 
    FS_Truncate(fs_handle);
    FS_Close(fs_handle);

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_write_xml_data_to_file(dps_event_ind->xml_address, dps_event_ind->xml_packet_size);
#else
    kal_sleep_task(KAL_TICKS_50_MSEC);
#endif

    mmi_pict_parse_xml_script();

    mmi_pict_receive_dps_event_res();

    mmi_pict_send_dps_event_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dps_disconnect_ind
 * DESCRIPTION
 *  DPS disconnect indication from USB application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_dps_disconnect_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("PictBridge: USB removed");

    HideStatusIcon(STATUS_ICON_PRINT); /* hide print icon */
    HideStatusIcon(STATUS_ICON_PRINT_FAIL); /* hide print error icon */
    UpdateStatusIcons();

    /*
     * Entry a dummy screen to delete all printing related screens.
     * USB removed popup comes later to replace this dummy screen.
     */
    EntryNewScreen(SCR_ID_PICT_DUMMY, NULL, NULL, NULL);
    mmi_pict_delete_print_screens();

    memset(&g_pict_bridge_context, 0, sizeof(pict_bridge_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dps_discovery_ind
 * DESCRIPTION
 *  DPS discovery indication from USB task
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_dps_discovery_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    usb_mmi_dps_discovery_ind_struct *dps_discovery_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dps_discovery_ind = (usb_mmi_dps_discovery_ind_struct *) info;

    g_pict_bridge_context.xml_operation_cmd = (S8*) dps_discovery_ind->dps_xml_request_address;
    g_pict_bridge_context.xml_event_cmd = (S8*) dps_discovery_ind->dps_xml_response_address;

    g_pict_bridge_context.xml_operation_cmd_size = dps_discovery_ind->dps_xml_request_buffer_size;
    g_pict_bridge_context.xml_event_cmd_size = dps_discovery_ind->dps_xml_response_buffer_size;

    g_pict_bridge_context.xml_start_job_cmd_size = dps_discovery_ind->dps_xml_start_job_buffer_size;

    if (g_pict_bridge_context.xml_operation_cmd == NULL || g_pict_bridge_context.xml_event_cmd == NULL)
    {
        MMI_ASSERT(0);
    }

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    mmi_pict_delete_xml_data_file();
#endif

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    mmi_pict_entry_printer_connected();
#endif

    g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_configure_print_service;

    mmi_pict_send_dps_operation_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_start_job_req
 * DESCRIPTION
 *  Notification to USB task of starting a print job
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_start_job_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_USB;
    Message.oslMsgId = MSG_ID_MMI_USB_START_JOB_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_close_job_req
 * DESCRIPTION
 *  Notification to USB task of closing a print job
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_close_job_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_USB;
    Message.oslMsgId = MSG_ID_MMI_USB_CLOSE_JOB_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_proc_pending_message
 * DESCRIPTION
 *  Send a message to MMI to pending the next operation because there might be an incoming event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_proc_pending_message(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT);
    /* 
     * To get capability of the printer, MMI needs to continuously send DREQUEST to the printer.
     * To prevent from an incoming HREQUEST after HRESPONSE, MMI sends a message to itself.
     */
    mmi_pict_send_dps_operation_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_send_pending_message
 * DESCRIPTION
 *  Process the pending operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_send_pending_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sleep_task(KAL_TICKS_100_MSEC * 3); /* sleep 300 msec to ensure that no DPS event from printer */

    SetProtocolEventHandler(mmi_pict_proc_pending_message, MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_PICT_BRIDGE_PENDING_EVENT;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_connect_to_pc_ind
 * DESCRIPTION
 *  PC connection indication from USB task
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_connect_to_pc_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_entry_error_connection_to_pc();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_open_file_fail_ind
 * DESCRIPTION
 *  Open file failure indication from USB task
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_open_file_fail_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
    {
        mmi_pict_entry_print_done(MMI_FALSE, STR_ID_PICT_INCOMPATIBLE_FILE);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_host_reset
 * DESCRIPTION
 *  USB host reset
 * PARAMETERS
 *  info            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_host_reset(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_pict_is_dps_device_present())
    {
        mmi_pict_dps_disconnect_ind();
        mmi_pict_host_reset_popop();

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_USB;
        Message.oslMsgId = MSG_ID_MMI_USB_PTP_HOST_RESET_CNF;
        Message.oslDataPtr = NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_drm_consume_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_drm_consume_callback(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_print_file_handle_with_filename
 * DESCRIPTION
 *  Return image file hander to USB task for printing
 * PARAMETERS
 *  obj_handle      [IN]
 *  filename        [OUT]
 *  max_length      [IN/OUT]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE mmi_pict_return_print_file_handle_with_filename(kal_uint32 obj_handle,  kal_uint16 *filename, kal_uint16 *max_filename_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle = NULL;

#ifdef __DRM_SUPPORT__
    S32 right_id;
#endif

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__

    U8 i, j;
    U16 file_id_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(image_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(image_file_path);

    if (g_pict_bridge_setting.page_format == 1) /* multiple */
    {
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            for (j = 1; ; j++)
            {
                file_id_count++;
                if ((j == 1 && g_pict_bridge_setting.layout == 0) ||
                    (j == 2 && g_pict_bridge_setting.layout == 1) ||
                    (j == 4 && g_pict_bridge_setting.layout == 2))
                {
                    break;
                }
            }

            if (file_id_count >= (U16) obj_handle)
            {
                break;
            }
        }
    }
    else /* standard or index */
    {
        i = (U8) (obj_handle - 1);
    }

    mmi_ucs2cat(image_file_path, (S8*) g_pict_bridge_context.multi_file_path[i]);
#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) image_file_path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
    if (g_pict_bridge_context.multi_file_consume[i] == 0)
    {
        right_id = DRM_consume_rights(fs_handle, DRM_PERMISSION_PRINT, mmi_pict_drm_consume_callback);
        DRM_stop_consume(right_id);
        g_pict_bridge_context.multi_file_consume[i] = 1;
    }
#else /* __DRM_SUPPORT__ */
    fs_handle = FS_Open((U16*) image_file_path, FS_READ_ONLY);
#endif /* __DRM_SUPPORT__ */
    mmi_ucs2cpy((S8*) filename, mmi_fmgr_extract_file_name(image_file_path));
    *max_filename_length = mmi_ucs2strlen((S8*) filename) + 1; /* USB task requires to count the null-terminator */

#else /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
    if (g_pict_bridge_context.drm_consume_cnt == 0)
    {
        right_id = DRM_consume_rights(fs_handle, DRM_PERMISSION_PRINT, mmi_pict_drm_consume_callback);
        DRM_stop_consume(right_id);
        g_pict_bridge_context.drm_consume_cnt = 1;
    }
#else /* __DRM_SUPPORT__ */
    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
#endif /* __DRM_SUPPORT__ */
    mmi_ucs2cpy((S8*) filename, mmi_fmgr_extract_file_name((S8*) g_pict_bridge_context.printing_filepath));
    *max_filename_length = mmi_ucs2strlen((S8*) filename) + 1; /* USB task requires to count the null-terminator */

#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
    /* print debug message */
    #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
        mmi_ucs2_to_asc(ansii_file_path, image_file_path);
    #else
        mmi_ucs2_to_asc(ansii_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    #endif
        PRINT_INFORMATION("PictBridge: image %d: %s, handle: %d", obj_handle, ansii_file_path, fs_handle);
#endif /* __MMI_PICT_BRIDGE_KEEP_XML_DATA__ */

    return fs_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_print_file_handle_with_filepath
 * DESCRIPTION
 *  Return image file hander to USB task for printing
 * PARAMETERS
 *  obj_handle      [IN]
 *  filepath        [OUT]
 *  max_length      [IN/OUT]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE mmi_pict_return_print_file_handle_with_filepath(kal_uint32 obj_handle, kal_uint16 *filepath, kal_uint16 *max_filepath_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle = NULL;
#ifdef __DRM_SUPPORT__
    FS_FileInfo	file_info;
#endif

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__

    U8 i, j;
    U16 file_id_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(image_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(image_file_path);

    if (g_pict_bridge_setting.page_format == 1) /* multiple */
    {
        for (i = 0; i < g_pict_bridge_context.multi_file_select; i++)
        {
            for (j = 1; ; j++)
            {
                file_id_count++;
                if ((j == 1 && g_pict_bridge_setting.layout == 0) ||
                    (j == 2 && g_pict_bridge_setting.layout == 1) ||
                    (j == 4 && g_pict_bridge_setting.layout == 2))
                {
                    break;
                }
            }

            if (file_id_count >= (U16) obj_handle)
            {
                break;
            }
        }
    }
    else /* standard or index */
    {
        i = (U8) (obj_handle - 1);
    }

    mmi_ucs2cat(image_file_path, (S8*) g_pict_bridge_context.multi_file_path[i]);

#ifdef __DRM_SUPPORT__
    fs_handle = FS_Open((U16*) image_file_path, FS_READ_ONLY);
    FS_GetFileInfo(fs_handle, &file_info);
    memcpy((void *) &g_pict_bridge_context.printing_file_info, (void *) file_info.DirEntry, sizeof(FS_DOSDirEntry));
    FS_Close(fs_handle);
#endif /* __DRM_SUPPORT__ */

#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) image_file_path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
#else
    fs_handle = FS_Open((U16*) image_file_path, FS_READ_ONLY);
#endif
    mmi_ucs2cpy((S8*) filepath, image_file_path);
    *max_filepath_length = mmi_ucs2strlen((S8*) filepath) + 1; /* USB task requires to count the null-terminator */

#else /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#ifdef __DRM_SUPPORT__
    fs_handle = DRM_open_file((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY, DRM_PERMISSION_PRINT);
#else
    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
#endif
    mmi_ucs2cpy((S8*) filepath, (S8*) g_pict_bridge_context.printing_filepath);
    *max_filepath_length = mmi_ucs2strlen((S8*) filepath) + 1; /* USB task requires to count the null-terminator */

#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

    return fs_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_current_print_file_info
 * DESCRIPTION
 *  Return file info to USB task for printing
 * PARAMETERS
 *  info            [OUT]
 * RETURNS
 *  int
 *****************************************************************************/
int mmi_pict_return_current_print_file_info(FS_DOSDirEntry *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    memcpy((void *) info, (void *) &g_pict_bridge_context.printing_file_info, sizeof(FS_DOSDirEntry));
    return FS_NO_ERROR;
#else
    return FS_FILE_NOT_FOUND;
#endif
}


#ifdef __MMI_PICT_BRIDGE_KEEP_XML_DATA__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_write_xml_data_to_file
 * DESCRIPTION
 *  Write XML data to file
 * PARAMETERS
 *  data_addr       [IN]
 *  data_len        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_write_xml_data_to_file(U8 *data_addr, U32 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    U32 written_length;
    kal_wchar root_dir[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(root_dir, "%c:\\", (S8) (MMI_PUBLIC_DRV));
    mmi_ucs2cat((S8*)root_dir, (const S8*)(L"Received\\pict.xml"));
    fs_handle = FS_Open((U16*) root_dir, FS_CREATE | FS_READ_WRITE);
    FS_Seek(fs_handle, 0, FS_FILE_END);
    FS_Write(fs_handle, (void*) data_addr, data_len, &written_length); 
    FS_Truncate(fs_handle);
    FS_Close(fs_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_delete_xml_data_file
 * DESCRIPTION
 *  Delete XML data file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_delete_xml_data_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar root_dir[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(root_dir, "%c:\\", (S8) (MMI_PUBLIC_DRV));
    mmi_ucs2cat((S8*)root_dir, (const S8*)(L"Received\\pict.xml"));
    FS_Delete((U16*) root_dir);
}

#endif /* __MMI_PICT_BRIDGE_KEEP_XML_DATA__ */


#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_is_dps_device_present
 * DESCRIPTION
 *  Check if DPS printer is present
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_pict_is_dps_device_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    return ((g_pict_bridge_context.xml_operation_cmd == NULL || g_pict_bridge_context.xml_event_cmd == NULL) ? MMI_FALSE : MMI_TRUE);
#else
    return 1;
#endif
}


#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

