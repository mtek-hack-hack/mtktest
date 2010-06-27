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
 *  MMSViewerDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Viewer APP's internals
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
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

#ifndef __MMSVIEWERDEFS_H__
#define __MMSVIEWERDEFS_H__
#ifdef __MMI_MMS_2__
#include "MMSViewerAPPDefs.h"
#include "wgui_categories_mms_viewer.h"

/**************************/
/*   XML PARSER OPTIONS   */
/**************************/
#define MMI_MV_MSG_PARSER_DO_BEST_FIT 0x00000001
#define MMI_MV_MSG_PARSER_IGNORE_SLIDES 0x00000002

/*******************/
/*   APP Defines   */
/*******************/
#define MMI_MV_UNBLOCK_TIME (50)
#define MMI_MV_XML_MAX_ADDR_LEN (MMI_MV_MAX_ADDRESS_LEN)
#define MMI_MV_DEFAULT_BG_COLOR (MMA_DEFAULT_SMIL_BG_COLOR)
#define MMI_MV_DEFAULT_FG_COLOR (MMA_DEFAULT_SMIL_FG_COLOR)
#define MMI_MV_DEFAULT_IMAGE_LAYOUT    (MMA_LAYOUT_IMAGE_ON_TOP)
#define MMI_MV_MAX_ALT_STR_LEN (20)
/*MMI_MV_TEMP_PATH_LEN is 12 out of which 7 for D:\_mv and 5 for ext */
#define MMI_MV_TEMP_FOLDER ("_MV\\")
#define MMI_MV_TEMP_PATH_BUFFER_LEN (12*ENCODING_LENGTH)

typedef enum
{
    MMI_MV_START_VIEW=1,
    MMI_MV_ENTER_ASM_SCR,
    MMI_MV_EXIT_ASM_SCR,
    MMI_MV_GET_CONTENT
}mmi_mv_app_state;

typedef enum
{
    MMI_MV_FILE_ERROR,
    MMI_MV_OUT_OF_MEM,
    MMI_MV_PARSER_ERROR,
    MMI_MV_OBJ_LIMIT_REACHED,
    MMI_MV_ROOT_DIR_FULL
} mmi_mv_exit_reason;

typedef enum
{
    MMI_MV_CHARSET_UNKNOWN,
    MMI_MV_CHARSET_ASCII,
    MMI_MV_CHARSET_ISO_8859_1,
    MMI_MV_CHARSET_UTF8,
    MMI_MV_CHARSET_UCS2,
    MMI_MV_CHARSET_UTF16BE,
    MMI_MV_CHARSET_UTF16LE,
    MMI_MV_CHARSET_UTF16
} mmi_mv_charset_enum;

typedef struct
{
   S32 vf_handle; /* parent file handle for any vf used */
   U16 vfname[MMI_MV_VFN_NUM_OF_WCHAR];  /* VF Filename */
   U8 serial; /* current serial from DRM Engine: can use to cancel */
} mmi_mv_drm_process_cntx_struct;

typedef struct
{
    mmi_mv_get_use_details_rsp_struct use_detail_rsp;
    wgui_mv_slide_struct *current_slide;
    PU8 p_ucs2_buffer;
    U32 ucs2_buffer_len;
    U32 total_count;    /* total use details found */
    U32 count;          /* no of use details found on current slide */
    U16 progress_screen_id;
    mmi_mv_get_use_details_enum state;
} mmi_mv_use_details_cntx_struct;

typedef struct
{
    XML_PARSER_STRUCT *xml_parser;
    wgui_mv_slide_struct *slide;
    mmi_mv_object_struct *object;
    S32 addr_type;  /* APPLIB_ADDR_TYPE_EMAIL, APPLIB_ADDR_TYPE_URL and APPLIB_ADDR_TYPE_PHONENUMBER */
    U32 flags;
} mmi_mv_msg_parser_cntx_struct;

typedef struct
{
    PU8 ptr_asm_pool;
    PU8 slide_txt_buffer; /* final buffer with UCS2 encoding */
    PU8 src_buffer; /* buffer with source encoding */
    PU8 inputbox_buffer;
    wgui_mv_xml_msg_struct *msg_cntx;
    U32 obj_iterator;
    void (*lsk_fn) (void);
    void (*rsk_fn) (void);
    mmi_mv_attachment_info_struct *attachment_head;

    KAL_ADM_ID adm_pool_id;
    U32 request_id;
    U32 msg_id;
    mma_msg_type_enum msg_type;
    U32 buffer_index;

    U16 progress_scr_id;
    U16 lsk_str_id;
    U16 total_object_num; /* Number actually found */
    U16 reported_object_num; /* Number reported by MMA used to allocate array of pointer for objs: mmi_mv_object */
    U16 total_attachment_num;

    BOOL send_read_report;
    BOOL set_readmark;
    BOOL add_slides;
    mmi_mv_exit_reason exit_reason;
    /* MAUI_00539316 */
    BOOL deinit_on_exit;
    /* MAUI_00539316 */    
    mmi_mv_app_state app_state;
} mmi_mv_context_struct;

#endif /* __MMI_MMS_2__ */
#endif /* __MMSVIEWERDEFS_H__ */

