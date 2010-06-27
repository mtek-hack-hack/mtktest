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
 * BTMMIBppScr.h
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

#ifndef __BT_MMI_BPP_SCR_H__
#define __BT_MMI_BPP_SCR_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifndef __BT_MMI_BPP_GPROT_H__
#error "BTMMIBppGprot.h should be included"
#endif 



/******************************************************************************
    Enum Value
******************************************************************************/
/* BPP popup cause enum */
typedef enum
{
    MMI_BPP_POPUP_CAUSE_PRINTER_BUSY,
    MMI_BPP_POPUP_CAUSE_AUTH_FAILED,
    MMI_BPP_POPUP_CAUSE_CONNECT_FAILED,
    MMI_BPP_POPUP_CAUSE_GET_ATTR_FAILED,
    MMI_BPP_POPUP_CAUSE_CREATE_JOB_FAILED,    
    MMI_BPP_POPUP_CAUSE_COMPOSE_FAILED,
    MMI_BPP_POPUP_CAUSE_READ_FILE_FAILED,
    MMI_BPP_POPUP_CAUSE_TROUBLE,
    MMI_BPP_POPUP_CAUSE_PRINTING,
    MMI_BPP_POPUP_CAUSE_BACKGROUND_PRINTING,
    MMI_BPP_POPUP_CAUSE_PRINTED,
    MMI_BPP_POPUP_CAUSE_CANCELED,
    MMI_BPP_POPUP_CAUSE_DISCONNECTED,
    MMI_BPP_POPUP_CAUSE_FORMAT_WARNING,
    MMI_BPP_POPUP_CAUSE_UNKNOW,
    MMI_BPP_POPUP_CAUSE_TOTAL
} mmi_bpp_popup_cause_enum;

/* BPP Blink action enum */
typedef enum
{
    MMI_BPP_BLINK_START,
    MMI_BPP_BLINK_STOP,    
    MMI_BPP_BLINK_END_OF_ENUM
} mmi_bpp_blink_enum;

/******************************************************************************
    Definitions
******************************************************************************/
#define MMI_BPP_MAX_COPIES              (4)     /* 3 digits + NULL */
#define MMI_BPP_SIDES_LIST              (2)
#define MMI_BPP_NUMBER_UP_LIST          (3)
#define MMI_BPP_ORIENTATION_LIST        (2)
#define MMI_BPP_MEDIA_LIST              (3)
#define MMI_BPP_QUALITY_LIST            (3)
#define MMI_BPP_PRINT_SETTING_ICONS     (12)    /* setting screen number of icons */
#define MMI_BPP_AUTH_UI_BUFF_SIZE       (102)   /* "Password Exchange("device_name"):" + NULL = 50*2 + 2 */
#define MMI_BPP_AUTH_INPUT_BUFF_SIZE    (34)    /* (GOEP_MAX_PASSWD_SIZE + 1)*2 */


/******************************************************************************
    Structure
******************************************************************************/
typedef struct
{
    U16 Copies[MMI_BPP_MAX_COPIES];                 /* Inline sturcture for copies string, 3 == 2 digits + NULL */
    U8  *sides_list[MMI_BPP_SIDES_LIST];            /* Inline selection list for "One-Sided" and "Two-Sided" */
    U8  *NumberUp_list[MMI_BPP_NUMBER_UP_LIST];     /* Inline selection list for "1" , "2" and "4" */
    U8  *Orientation_list[MMI_BPP_ORIENTATION_LIST];/* Inline selection list for "Protrait" and "Landscape" */
    U8  *Media_list[MMI_BPP_MEDIA_LIST];            /* Inline selection list for "A4", "US" and "4X6" */
    U8  *Quality_list[MMI_BPP_QUALITY_LIST];        /* Inline selection list for "High", "Normal" and "Draft" */
 } mmi_bpp_print_setting_struct;


/******************************************************************************
    MMI BPP CONTEXT
******************************************************************************/
typedef struct
{
    mmi_bpp_print_setting_struct    *print_setting; /* print job setting structure */
    kal_int32                       Sides;	        /* sides selected */
    kal_int32                       NumberUp;	    /* number up selected */
    kal_int32                       Orientation;	/* orientation selected */
    kal_int32                       Media;	        /* media selected */
    kal_int32                       Quality;	    /* quality selected */
    U16                             img_id;         /* save the img_id of preview */
    /* for authentication screen realm + device name */
    U8 auth_scr_ui_buff[MMI_BPP_AUTH_UI_BUFF_SIZE];
    /* for authentication screen input buffer*/
    U8 auth_scr_input_buff[MMI_BPP_AUTH_INPUT_BUFF_SIZE];
} mmi_bpp_scr_cntx_struct;


/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/


/******************************************************************************
    MMI FTP FUNCTIONS
******************************************************************************/
/* utility function */
void mmi_bt_bpp_popup(mmi_bpp_popup_cause_enum cause);
void mmi_bt_bpp_del_scr(U16 scr_id);
void mmi_bt_bpp_go_back_history(void);
void mmi_bt_bpp_display_idle(void);
void mmi_bt_bpp_disconnect_clear_scrs(void);
void mmi_bt_bpp_deinit_clear_scrs(void);
void mmi_bt_bpp_add_history(U16 scr_id);
void mmi_bt_bpp_blinking(mmi_bpp_blink_enum action);
void mmi_bt_bpp_clear_scr_db(U16 scr_id);
void mmi_bt_bpp_history_replace(U16 out_scr, U16 in_scr);
void mmi_bt_bpp_insert_before_history(U16 ref_scr, U16 in_scr);

/* entry function */
void mmi_bt_pre_entry_printer_device_select_screen(void);
void mmi_bt_bpp_entry_connecting(void);
void mmi_bt_bpp_entry_authenticating(void);
void mmi_bt_bpp_entry_getting(void);
void mmi_bt_bpp_pre_entry_print_setting(MMI_BOOL got_printer_attr);
void mmi_bt_bpp_entry_print_setting(void);
void mmi_bt_bpp_entry_preview(void);
void mmi_bt_bpp_entry_disconnecting(void);
void mmi_bt_bpp_exit_authenticating(void);
void mmi_bt_bpp_exit_print_setting(void);
void mmi_bt_bpp_entry_creating(void);
void mmi_bt_bpp_entry_composing(void);
void mmi_bt_bpp_entry_printing(void);
void mmi_bt_bpp_entry_trouble(void);

/* bpp operation */
PU8 mmi_bt_bpp_get_auth_buff(void);
U16 mmi_bt_bpp_get_preview_img(void);
PU16 mmi_bt_bpp_get_copies_setting(void);
U8 mmi_bt_bpp_get_media_setting(void);
U8 mmi_bt_bpp_get_quality_setting(void);
void mmi_bt_bpp_scr_cntx_init(void);
void mmi_bt_bpp_entry_terminated(mmi_bpp_popup_cause_enum cause);

#endif /* __BT_MMI_BPP_SCR_H__ */ 

