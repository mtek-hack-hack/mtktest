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
 * BTMMIBpp.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_MMI_BPP_H__
#define __BT_MMI_BPP_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 

#ifndef __BT_MMI_BPP_GPROT_H__
#error "BTMMIBppGprot.h should be included"
#endif 

#ifndef __BLUETOOTH_STRUCT_H_
#error "Bluetooth_struct.h should be included"
#endif


/******************************************************************************
    Enum Value
******************************************************************************/
/* BPP Status Enum */
typedef enum
{
    MMI_BPP_STATUS_NONE,                //BPP initial status
    MMI_BPP_STATUS_SEARCHING,           //BPP searching status
    MMI_BPP_STATUS_CONNECTING,          //BPP connecting status    
    MMI_BPP_STATUS_CHALLENGE,           //BPP challenge status
    MMI_BPP_STATUS_AUTHENTICATED,       //BPP authenticated status
    MMI_BPP_STATUS_CONNECTED,           //BPP connected status
    MMI_BPP_STATUS_GETTING,             //BPP getting status
    MMI_BPP_STATUS_SETTING,             //BPP setting status
    MMI_BPP_STATUS_CREATING,            //BPP greating status
    MMI_BPP_STATUS_COMPOSING,           //BPP composing status
    MMI_BPP_STATUS_FORE_GROUND_PRINT,   //BPP foreground printing status    
    MMI_BPP_STATUS_BACK_GROUND_PRINT,   //BPP background printing status    
    MMI_BPP_STATUS_FORE_GROUND_STOPPED, //BPP foreground stopped status    
    MMI_BPP_STATUS_BACK_GROUND_STOPPED, //BPP background stopped status
    MMI_BPP_STATUS_CANCELED,            //BPP cancel print job
    MMI_BPP_STATUS_JOB_CANCELED,        //Printer cancel print job    
    MMI_BPP_STATUS_PRINTED,             //BPP printed status
    MMI_BPP_STATUS_DISCONNECTING,       //BPP disconnecting by CM status    
    MMI_BPP_STATUS_END_OF_ENUM
} mmi_bpp_status_enum;


/*****************************************************************
    Definitions
*****************************************************************/
#define BPP_GET_FLAG(flag, a)   ((flag & a) == 0 ? MMI_FALSE : MMI_TRUE)

#define MMI_BPP_LOG(x)                                                      \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x);                                      \
}
#define MMI_BPP_LOG1(x, x1)                                                 \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1);                                  \
}
#define MMI_BPP_LOG2(x, x1, x2)                                             \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2);                              \
}
#define MMI_BPP_LOG3(x, x1, x2, x3)                                         \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3);                          \
}
#define MMI_BPP_LOG4(x, x1, x2, x3, x4)                                     \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4);                      \
}
#define MMI_BPP_LOG6(x, x1, x2, x3, x4, x5, x6)                             \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6);              \
}
#define MMI_BPP_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                         \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6, x7);          \
}

/******************************************************************************
    Structure
******************************************************************************/
typedef struct
{
    goep_bd_addr_struct bd_addr;              //saving bt device address
    /* printer capabilities */
    U16         Copies;
    U8          DocFormat;        
    U8          Sides;    
    U8          NumberUp;    
    U8          Orientation;
    U8          Media;
    U8          Quality;
    MMI_BOOL    got_attr;
} mmi_bpp_printer_struct;

/******************************************************************************
    MMI BPP CONTEXT
******************************************************************************/
typedef struct
{
    mmi_bpp_app_enum            cur_app;                    //current application
    mmi_bpp_status_enum         status;                     //bpp status
    bt_bpp_printer_reason_enum  stopped_reason;             //to remember stoppped reason
    MMI_BOOL                    timer_flag;                 //set timer flag to trigger watch dog
    goep_bd_addr_struct         bd_addr;                    //saving bt device address
    U32                         job_id;                     //print job id
    U32                         g_conn_id;                  //global connection id
    U32                         total_send_doc_len;         //total length of sending document
    U32                         remain_send_doc_len;        //remain length of sending document
    ap_callback                app_callback;               //app data allocation function pointer
    U8                          printer_name[GOEP_MAX_DEV_NAME];//printer name
    mmi_bpp_printer_struct      printer;                    //to set a printer device capabilities
    MMI_BOOL                    cm_disc_flag;               //set CM disconnect flag
    U16                         xhtml_file[FMGR_MAX_PATH_LEN];     
} mmi_bpp_cntx_struct;


/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/
extern mmi_bpp_cntx_struct *const mmi_bpp_cntx_p;

/******************************************************************************
    MMI BPP FUNCTIONS
******************************************************************************/
/* For BPP Screen */
MMI_BOOL mmi_bt_bpp_is_connecting(void);
MMI_BOOL mmi_bt_bpp_get_timer(void);
mmi_bpp_status_enum mmi_bt_bpp_get_status(void);
mmi_bpp_printer_struct* mmi_bt_bpp_get_printer(void);
void mmi_bt_bpp_send_disconnect(void);
void mmi_bt_bpp_auth_send(void);                                    
void mmi_bt_bpp_auth_reject(void);
void mmi_bt_bpp_send_msg(U32 msg_id, void *p_local_para);
void mmi_bt_bpp_print(void);
void mmi_bt_bpp_background_print(void);
U8 mmi_bt_bpp_retrieve_prog_percentage(void);
PU8 mmi_bt_bpp_get_printer_name(void);
bt_bpp_printer_reason_enum mmi_bt_bpp_get_stopped_reason(void);
void mmi_bt_bpp_init(void);
void mmi_bt_bpp_reset(void);
void mmi_bt_bpp_set_status(mmi_bpp_status_enum status);
MMI_BOOL mmi_bt_bpp_usb_handle(void);


#endif /* __BT_MMI_BPP_H__ */ 

