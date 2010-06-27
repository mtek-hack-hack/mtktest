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
 * BTMMIBppGprot.h
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

#ifndef __BT_MMI_BPP_GPROT_H__
#define __BT_MMI_BPP_GPROT_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef BT_MMI_CM_H
#error "BTMMICm.h should be included"
#endif 


#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BPP_SUPPORT__)

#include "BTMMIBppXhtmlGprot.h"

/*****************************************************************
    Define
*****************************************************************/
#define MMI_BPP_PROG_UPD_DUR        (2000)
#define MMI_BPP_TIMER_DUR           (10000)
#define MMI_BPP_OBEX_TIMER_DUR      (120000)
#define MMI_BPP_DISC_TIMER_DUR      (15000)
#define MMI_BPP_CONNECT_TIMER_DUR   (65000)


/*****************************************************************
    Enum
*****************************************************************/
typedef enum
{
    MMI_BPP_APP_NONE,       //None
    MMI_BPP_APP_IMG,        //Image_Viewer
    MMI_BPP_APP_BOOK,       //E-Book
    MMI_BPP_APP_CALENDAR,   //v-Calendar
    MMI_BPP_APP_PHB,        //v-Card
    MMI_BPP_APP_MAIL,       //E-Mail
    MMI_BPP_APP_EMS,        //SMS/EMS
    MMI_BPP_APP_MMS,        //MMS
    MMI_BPP_APP_TOTAL  
} mmi_bpp_app_enum;

typedef enum
{
    MMI_BPP_PRINT_STATUS_IDLE,
    MMI_BPP_PRINT_STATUS_BUSY,
    MMI_BPP_PRINT_STATUS_TOTAL  
} mmi_bpp_print_status_enum;

typedef enum
{
    MMI_BPP_DOC_COMPOSE_DONE,
    MMI_BPP_DOC_COMPOSE_FAILED,
    MMI_BPP_DOC_COMPOSE_TOTAL  
} mmi_bpp_doc_compose_enum;


/*****************************************************************
    Structure
*****************************************************************/

/*****************************************************************
    Extern Global Function
*****************************************************************/
/* For CM */
void mmi_bt_bpp_init(void);                                         //global bpp init for CM
void mmi_bt_bpp_deinit(void);                                       //global bpp init for BT panic
void mmi_bt_bpp_connect_printer(mmi_bth_bt_addr bd_addr);           //global bpp connect function for CM
void mmi_bt_bpp_disconnect_printer(mmi_bth_bt_addr bd_addr, U32 g_conn_id);           //global bpp disconnect function for CM
void mmi_bt_bpp_foreground_print(void);
/* for CM callback */
void mmi_bt_bpp_printing(U16 nap, U8 uap,U32 lap);
void mmi_bt_bpp_cm_timer_expire_hdlr(void);

/* for FM callback */
void mmi_bt_bpp_plug_out_hdlr(void);
MMI_BOOL mmi_bt_bpp_can_format_drive(PS8 file_path);

/* For Applications */
mmi_bpp_print_status_enum mmi_bt_bpp_app_is_printing(void);         //global bpp query function for app
void mmi_bt_bpp_app_print(mmi_bpp_app_enum app, ap_callback callback);    //global bpp register callback function for app
void mmi_bt_bpp_busy_popup(void);                                   //global bpp pop up function for app
void mmi_bt_bpp_format_warning_popup(void);


/* Event handler */
void mmi_bt_bpp_connect_cnf_hdlr(void* msg);
void mmi_bt_bpp_auth_ind_hdlr(void* msg);
void mmi_bt_bpp_get_printer_attr_cnf_hdlr(void* msg);
void mmi_bt_bpp_disconnect_ind_hdlr(void* msg);
void mmi_bt_bpp_create_job_cnf_hdlr(void* msg);
void mmi_bt_bpp_event_ind_hdlr(void* msg);
void mmi_bt_bpp_send_doc_cnf_hdlr(void* msg);
void mmi_bt_bpp_prog_update_ind_hdlr(void* msg);
void mmi_bt_bpp_timer_expire_hdlr(void);
void mmi_bt_bpp_obex_timer_expire_hdlr(void);
void mmi_bt_bpp_connect_timer_expire_hdlr(void);
void mmi_bt_bpp_disc_timer_expire_hdlr(void);

/* XHTML */
void mmi_bt_bpp_document_compose_done(mmi_bpp_doc_compose_enum doc_flag);   //notify bpp the document composing operation done

#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */
#endif /* __BT_MMI_BPP_GPROT_H__ */ 
