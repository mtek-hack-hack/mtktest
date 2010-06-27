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
 * IrdaMMIScr.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IRDA_MMI_SCR_H__
#define __IRDA_MMI_SCR_H__

/***************************************************************************** 
* Predefine header checking
*****************************************************************************/
#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 
#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 
#ifndef __IRDA_MMI_GPROTS_H__
#error "IrdaMMIGprots.h should be included"
#endif 

#ifdef __MMI_IRDA_SUPPORT__

/***************************************************************************** 
* MMI IRDA Scr Ir port Status
*****************************************************************************/
typedef enum
{

    MMIR_SCR_IROPEN = 0,
    MMIR_SCR_IRCLOSE,
    MMIR_SCR_IRPERIOD,

    MMIR_SCR_IRLAST
} MMIR_SCR_IRSTATUS;

/***************************************************************************** 
* MMI IRDA Scr Context
*****************************************************************************/
typedef struct
{

    /* Total pending received objects counter */
    U32 flag;

    MMIR_SCR_IRSTATUS irda_state;

} MMI_IRDA_SCR_CONTEX;

extern MMI_IRDA_SCR_CONTEX *mmi_irda_scr_cntx_p;

#define MMI_IRDASCR_CNTX(a) (mmi_irda_scr_cntx_p->a)

/***************************************************************************** 
* MMI IRDA Scr flag defination and operation
*****************************************************************************/
/* MMI IrDA flag bit-wise flag defination */
#define MMIIRDASRC_MASK_RESERVED_0      0x00000001
#define MMIIRDASRC_MASK_RESERVED_1      0x00000002
#define MMIIRDASRC_MASK_RESERVED_2      0x00000004
#define MMIIRDASRC_MASK_RESERVED_3      0x00000008
#define MMIIRDASRC_MASK_RESERVED_4      0x00000010
#define MMIIRDASRC_MASK_RESERVED_5      0x00000020
#define MMIIRDASRC_MASK_RESERVED_6      0x00000040
#define MMIIRDASRC_MASK_RESERVED_7      0x00000080

/* MMI usb context bit-wise flag operation */
#define MMIIRDASRC_GET_FLAG(a)       ( ((mmi_irda_scr_cntx_p->flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMIIRDASRC_SET_FLAG(a)       ( (mmi_irda_scr_cntx_p->flag) |=  a )
#define MMIIRDASRC_RESET_FLAG(a)   ( (mmi_irda_scr_cntx_p->flag) &=  ~a )

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_irda_setup_highlight_handler(void);
extern void mmi_irda_setup_selection_highlight_handler(S32 index);
extern void mmi_irda_entry_setup_menu(void);
extern void mmi_irda_exec_open_menu(void);
extern void mmi_irda_exec_close_menu(void);
extern void mmi_irda_exec_period_menu(void);
extern void mmi_irda_scr_data_passing_ind(void);
extern void mmi_irda_scr_data_stop_ind(void);
extern void mmi_irda_scr_irda_close_ind(void);

/* MMI_IRDA_NFY_TYPE mmi_vobj_irda_receive_ind(void* path_src); */
extern MMI_IRDA_NFY_TYPE mmi_irda_obj_receive_ind(void *path_src, void *filename);

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/* Shantanu-Added for DLT support  */
extern void mmi_irda_theme_idle_notify_scr(void *, void *);
extern int SetIrdaThmDownloadStroageType(void *);
extern void irda_theme_activate_function(void);
extern void ActivateThemeDownloadedFromIRDA(void);

/* Shantanu-Added for DLT support  */
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

extern void mmi_irda_notify_scr_goback_func(void);
extern void mmi_irda_notify_scr_endkey_func(void);
extern void mmi_irda_notify_scr_browse(void);

/* void mmi_irda_notify_scr_browse_cb(void* filename); */
extern void mmi_irda_notify_scr_browse_cb(void *filename, int isShort);

extern void mmi_irda_entry_fmgr_fwd(void);      /* PMT PANKAJ START - Moved Code From FileMgr.c */
extern void mmi_irda_exit_fmgr_fwd(void);
extern U8 mmi_irda_sending_screen_del_cb(void *p);
extern void mmi_irda_fmgr_forward_to_irda_callback(void *buf_p, U32 result);
extern void mmi_irda_update_prog_tohdlr(void);  /* PMT PANKAJ END - Moved Code From FileMgr.c */

#if defined(__MMI_IRDA_CARD_SUPPORT__)  /* Priyesh - Memory Card Support */
extern void mmi_irda_entry_setup_menu(void);
extern void mmi_msg_set_Irda_menu_highlight_handler(void);
extern void HighlightIrdaActivationHandler(void);
extern void HighlightIrdaStorageHandler(void);
extern void mmi_irda_entry_activation_menu(void);
extern void mmi_irda_entry_storage_menu(void);
extern void mmi_irda_storage_exec(void);
extern void HintIrdaActivation(U16);
extern void HintIrdaStorageLocation(U16);
extern void mmi_irda_storage_selection_highlight_handler(S32);
#endif /* defined(__MMI_IRDA_CARD_SUPPORT__) */ /* __MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support */

#endif /* __MMI_IRDA_SUPPORT__ */ 

#endif /* __IRDA_MMI_SCR_H__ */ 

