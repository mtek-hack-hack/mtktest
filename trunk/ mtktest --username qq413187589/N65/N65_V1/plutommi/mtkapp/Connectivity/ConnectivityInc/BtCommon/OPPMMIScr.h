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
 * OPPMMIScr.h
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MMI_OPP_SUPPORT__

#ifndef __OPP_MMI_SCR_H__
#define __OPP_MMI_SCR_H__

/***************************************************************************** 
* Predefine header checking
*****************************************************************************/
#ifndef _MMI_DATA_TYPE_H
#error "MMIDataType.h should be included"
#endif 
#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 
#ifndef __OPP_MMI_GPROTS_H__
#error "OPPMMIGprots.h should be included"
#endif 

/***************************************************************************** 
* MMI OPP Client/Server status
*****************************************************************************/

/***************************************************************************** 
* MMI OPP Scr Context
*****************************************************************************/
typedef struct
{
    /* Total pending received objects counter */
    U32 flag;   
    /* Store END key handler void(*)(void) */
    FuncPtr keydown_fp;
    FuncPtr keyup_fp;
} MMI_OPP_SCR_CONTEX;

extern MMI_OPP_SCR_CONTEX *mmi_opp_scr_cntx_p;

#define MMI_OPP_SCR_CNTX(a) (mmi_opp_scr_cntx_p->a)

/***************************************************************************** 
* MMI OPP Scr flag defination and operation
*****************************************************************************/
/* MMI OPP flag bit-wise flag defination */
#define MMIOPPSRC_MASK_RESERVED_0      0x00000001
#define MMIOPPSRC_MASK_RESERVED_1      0x00000002
#define MMIOPPSRC_MASK_RESERVED_2      0x00000004
#define MMIOPPSRC_MASK_RESERVED_3      0x00000008
#define MMIOPPSRC_MASK_RESERVED_4      0x00000010
#define MMIOPPSRC_MASK_RESERVED_5      0x00000020
#define MMIOPPSRC_MASK_RESERVED_6      0x00000040
#define MMIOPPSRC_MASK_RESERVED_7      0x00000080

/* MMI usb context bit-wise flag operation */
#define MMIOPPSRC_GET_FLAG(a)       ( ((mmi_opp_scr_cntx_p->flag) & a) == 0 ? MMI_FALSE : MMI_TRUE )
#define MMIOPPSRC_SET_FLAG(a)       ( (mmi_opp_scr_cntx_p->flag) |=  a )
#define MMIOPPSRC_RESET_FLAG(a)   ( (mmi_opp_scr_cntx_p->flag) &=  ~a )

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern MMI_OPP_NFY_TYPE mmi_opp_obj_receive_ind(void *path_src, void *filename);
extern U8 mmi_opp_retrieve_put_prog_percentage(void);

/* Unused */
extern void mmi_opp_scr_data_transfer_ind(MMI_BT_PROFILE_ROLE opp_role);
extern void mmi_opp_scr_data_stop_ind(MMI_BT_PROFILE_ROLE opp_role);
extern void mmi_opp_entry_recv_confirm_scr(void);

extern void mmi_opp_notify_scr_goback_func(void);
extern void mmi_opp_notify_scr_endkey_func(void);
extern void mmi_opp_notify_scr_browse(void);
extern void mmi_opp_notify_scr_browse_cb(void *filename, int isShort);
extern void mmi_opp_request_timeout_callback(void);
extern void mmi_opp_entry_abort_fwd(void);
extern void mmi_opp_entry_fmgr_fwd(void);
extern void mmi_opp_entry_disconnting(void);
//extern void mmi_bt_opp_exe_endkey_hdlr(void);

#endif /* __OPP_MMI_SCR_H__ */ 

#endif /* __MMI_OPP_SUPPORT__ */ 

