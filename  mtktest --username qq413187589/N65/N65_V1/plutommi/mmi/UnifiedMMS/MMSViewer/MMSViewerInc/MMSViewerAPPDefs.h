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
 *  MMSViewerAPPDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Viewer APP Exports
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

#ifndef __MMSVIEWERAPPDEFS_H__
#define __MMSVIEWERAPPDEFS_H__
#ifdef __MMI_MMS_2__
/* Definitions of 'MMA_.*' */ 
#include "Mmsadp.h" 
/* Definition of applib_address_node_struct */
#include "App_usedetails.h"
/* Definition of FMGR_MAX_EXT_LEN */
#include "FileMgr.h"
/* Definition of MMI_MV_MAX_ADDRESS_LEN */
#include "MMSViewerMem.h" 

/* FS_GenVFN_SIZE buffer size for Virtual File (include NULL tail)*/
/* FS_GenVFN_SIZE + 1 for '.' dot + FMGR_MAX_EXT_LEN */
#define MMI_MV_VFN_NUM_OF_WCHAR ((FS_GenVFN_SIZE/ENCODING_LENGTH) + 1 + FMGR_MAX_EXT_LEN)

/***********************/
/* Use Details Related */
/***********************/
typedef enum 
{
    MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT,
    MMI_MV_GET_USE_DETAILS_SLIDE_ALL,
    MMI_MV_GET_USE_DETAILS_MSG_HEADERS,
    MMI_MV_GET_USE_DETAIL_MAX_TYPES
} mmi_mv_get_use_details_enum;

typedef enum 
{
    MMI_MV_GET_USE_DETAILS_RESULT_SUCCESS,
    MMI_MV_GET_USE_DETAILS_RESULT_OUT_OF_MEM,
    MMI_MV_GET_USE_DETAILS_RESULT_FAILED,
    MMI_MV_GET_USE_DETAILS_RESULT_MAX
} mmi_mv_get_use_details_result_enum;

typedef struct 
{
    LOCAL_PARA_HDR applib_address_node_struct *num_list;
    applib_address_node_struct *email_list;
    applib_address_node_struct *url_list;

    applib_address_node_struct *header_num_list; /*UNUSED*/
    applib_address_node_struct *header_email_list; /*UNUSED*/

    mmi_mv_get_use_details_enum returned_type;
    mmi_mv_get_use_details_result_enum result;
} mmi_mv_get_use_details_rsp_struct;

typedef struct 
{
    LOCAL_PARA_HDR mmi_mv_get_use_details_enum request_type;
    U32 progress_screen_id;
} mmi_mv_get_use_details_req_struct;


/*******************************/
/* Object & Attachment Related */
/*******************************/
typedef enum
{
    MMI_MV_OBJECT_TYPE_IMAGE,
    MMI_MV_OBJECT_TYPE_AUDIO,
    MMI_MV_OBJECT_TYPE_VIDEO,
    MMI_MV_OBJECT_TYPE_TEXT,
    MMI_MV_OBJECT_TYPE_ATTACHMENT,
    MMI_MV_OBJECT_TYPE_UNKNOWN,
    MMI_MV_OBJECT_TYPE_MAX
} mmi_mv_object_type_enum;


typedef struct
{
/* WARNING:: sizeof(mmi_mv_object_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
    U32 consume_id;
    U32 offset;
    U32 size;       /* file size for non-text object. UTF8 size for text object */
    U32 drm_offset;
    U32 drm_size;
    U16 drm_ext[FMGR_MAX_EXT_LEN];
    U16 *file_path; /* NULL terminator is needed. */
    U16 *file_name;

    U16 reference_count;
    mmi_mv_object_type_enum type;
    U8 drm_type;    /* mma_drm_type_enum */
    U8 encoding_scheme;
    
    MMI_BOOL consume_only_timed;
    MMI_BOOL rights_expired;
    MMI_BOOL is_virtual_file;
/* WARNING:: sizeof(mmi_mv_object_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
} mmi_mv_object_struct;

typedef mmi_mv_object_struct * p_mv_object;

typedef struct mmi_mv_attachment_info_struct_t
{
/* WARNING:: sizeof(mmi_mv_attachment_info_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
    struct mmi_mv_attachment_info_struct_t *next;
    struct mmi_mv_attachment_info_struct_t *previous;
    mmi_mv_object_struct *object;
/* WARNING:: sizeof(mmi_mv_attachment_info_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
} mmi_mv_attachment_info_struct;

/*************************/
/*   External API Used   */
/*************************/
extern pBOOL ComparePhoneNum(PU8 src, PU8 dst);
extern void mdi_audio_drm_disable_consume_count(void);

/********************/
/*   Exported API   */
/********************/

/* Following three called from dispatcher */
extern void mmi_mv_send_read_report_rsp(void *inMsg);
extern void mmi_mv_set_readmark_rsp(void *inMsg);
extern void mmi_mv_get_mms_content_rsp(void *inMsg);

/* Used to init asm mem at bootup */
extern void mmi_mv_init_mms_viewer_at_bootup(void);

/* Used to Deinit MMS Viewer */
extern void mmi_mv_deinit_viewer(void);

/* Used to view message from MMS APP */
extern void mmi_mv_view_message(U32 msg_id, mma_folder_enum msg_folder, mma_msg_type_enum msg_type, BOOL is_already_read, BOOL send_read_report,
                                U16 progress_scr_id, void (*lsk_fn) (void), U16 lsk_str_id);
/* Used to Preview Msg from UC */
extern void mmi_mv_preview_msg(U32 msg_id, U16 scr_id, void (*lsk_fn) (void), U16 lsk_str_id);

/* Used by MMS APP & UC Both to review an already parsed MMS */
extern void mmi_mv_review_msg(void);

/* Used to get pointer to the attachment list and num of attachments */
extern void mmi_mv_get_attachment_list(mmi_mv_attachment_info_struct **attachment_list, PU32 num_of_attachments);

/* Used to get pointer to objects on current slide */
extern void mmi_mv_get_objects_from_current_slide(
                mmi_mv_object_struct **image,
                mmi_mv_object_struct **video,
                mmi_mv_object_struct **audio,
                mmi_mv_object_struct **text);

/* Used to show a particular slide */
extern void mmi_mv_goto_slide(U16 slide_num);

/* Used to get total number of slide, useful to display slide list (slide 1, slide 2 ... slide N) */
extern U16 mmi_mv_get_total_slide_num(void);

/* Used to get the current slide's number */
extern U16 mmi_mv_get_current_slide_num(void);

/* Used to find out whether viewer screen is in history or not */
extern BOOL mmi_mv_is_viewer_in_history(void);

/* Used to check if viewer running eventually deprecates above function */
extern BOOL mmi_mv_is_viewer_init(void);

#endif /* __MMI_MMS_2__ */
#endif /* __MMSVIEWERAPPDEFS_H__ */ 

