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
 * BTMMIBppXhtml.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for BPP Xhtml composer service.
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
#include "BTMMICm.h"
#include "Bluetooth_struct.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBpp.h"
#include "BTMMIBppXhtmlGprot.h"
#include "BTMMIBppXhtml.h"
#include "DRM_gprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 
#include "ExtDeviceDefs.h"

/***************************************************************************** 
* External Variable & Functions
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/


/***************************************************************************** 
* CONTEXT
*****************************************************************************/
mmi_bpp_xhtml_cntx_struct g_mmi_bpp_xhtml_cntx;
mmi_bpp_xhtml_cntx_struct *const mmi_bpp_xhtml_cntx_p = &g_mmi_bpp_xhtml_cntx;


/***************************************************************************** 
* MACROS
*****************************************************************************/


/***************************************************************************** 
* MMI TRACE MACROS
*****************************************************************************/
#define MMI_XHTML_LOG(x)                                                    \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x);                                      \
}
#define MMI_XHTML_LOG1(x, x1)                                               \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1);                                  \
}
#define MMI_XHTML_LOG2(x, x1, x2)                                           \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2);                              \
}
#define MMI_XHTML_LOG3(x, x1, x2, x3)                                       \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3);                          \
}
#define MMI_XHTML_LOG4(x, x1, x2, x3, x4)                                   \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4);                      \
}
#define MMI_XHTML_LOG6(x, x1, x2, x3, x4, x5, x6)                           \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6);              \
}
#define MMI_XHTML_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                       \
{                                                                           \
    MMI_TRACE(MMI_TRACE_G7_MISC, x, x1, x2, x3, x4, x5, x6, x7);          \
}


/***************************************************************************** 
* INTERNAL STATIC FUNCTION
*****************************************************************************/
static kal_uint32 bpp_compose_xhtml_write_color(kal_uint8* tmp_buf, kal_uint32  tmp_buf_len, mmi_bpp_xhtml_color_enum color);
static int bpp_compose_xhtml_chunk_header(kal_uint8 chk_num, kal_uint32 len, mmi_bpp_xhtml_chk_enum chk_flag);
static int bpp_compose_xhtml_chunk_payload(kal_uint8* tmp_buf, kal_uint32 tmp_buf_len);
static kal_uint32 bpp_compose_xhtml_new_data_element_attr(mmi_bpp_xhtml_data_element_struct* data, void* tmp_buf, U32 tmp_len, mmi_bpp_xhtml_data_attr_enum type);
static void bpp_compose_xhtml_new_image_header(mmi_bpp_xhtml_type_enum type, U32 obj_len);
static void bpp_compose_xhtml_new_image_link(mmi_bpp_xhtml_type_enum type, int width);
static kal_uint32 bpp_compose_xhtml_calculate_tmp_buff_len(mmi_bpp_xhtml_data_element_struct* data, mmi_bpp_xhtml_data_attr_enum type);
static kal_uint32 bpp_compose_xhtml_calculate_ref_buff_len(mmi_bpp_xhtml_type_enum type, int* width, int img_box);
static kal_uint32 bpp_compose_xhtml_calculate_img_offset(mmi_bpp_xhtml_type_enum type);
static kal_uint32 bpp_compose_xhtml_scan_jpeg_file(void);
static mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_new_txt_data(mmi_bpp_xhtml_data_element_struct* data, MMI_BOOL write_file_flag, kal_uint8* tmp_buf, kal_uint32 tmp_buf_len);
static mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_new_img_data(mmi_bpp_xhtml_data_element_struct* data, MMI_BOOL write_file_flag, kal_uint8* tmp_buf, kal_uint32 tmp_buf_len);
static mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_data_element(mmi_bpp_xhtml_data_element_struct* data);
static void bpp_compose_xhtml_data_pause(void);
static void bpp_compose_xhtml_cntx_reset(void);
static kal_bool bpp_xhtml_work_folder_init(void);
static void app_compose_xhtml_file_end_cb(mmi_bpp_xhtml_rsp_enum rsp_code);
static int bpp_compose_xhtml_write_txt_data(U8* data, U32 data_len);
static void bpp_compose_xhtml_copy_txt_data(U8* dest_buf, U8* src_buf, U32 data_len);
static kal_uint32 bpp_compose_xhtml_parse_special_chars(U8* data, U32 data_len);
static int bpp_compose_xhtml_calculate_width(int width);

#define XHTML_FILE_HDR_LIB
/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_file_header
 * DESCRIPTION
 *  This function is to compose the xhtml common file header
 * PARAMETERS
 *  mmi_bpp_xhtml_media_enum
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_file_header(mmi_bpp_xhtml_media_enum media)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  written;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_COMPOSE_FILE_HEADER, media);
    
    /* reset the cntx */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len = 0;
    mmi_bpp_xhtml_cntx_p->status = MMI_BPP_XHTML_TD_STATUS_NONE;
    mmi_bpp_xhtml_cntx_p->tmp_buff = NULL;
    mmi_bpp_xhtml_cntx_p->tmp_file = NULL;
    mmi_bpp_xhtml_cntx_p->remain_file_size = 0;
    mmi_bpp_xhtml_cntx_p->chk_count = 1;
    mmi_bpp_xhtml_cntx_p->cur_msg = 0;    
    mmi_bpp_xhtml_cntx_p->app_callback = NULL;
    mmi_bpp_xhtml_cntx_p->div_flag = MMI_FALSE;
    mmi_bpp_xhtml_cntx_p->cancel_flag = MMI_FALSE;

    SetProtocolEventHandler((PsFuncPtr)bpp_compose_xhtml_data_resume_hdlr, MSG_ID_BT_BPP_SEND_DOC_REQ);

    /* set media to cntx */
    mmi_bpp_xhtml_cntx_p->media = media;

    /* bpp folder init */
    if (!bpp_xhtml_work_folder_init())
    {
        /* init failed */
        MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_FILE_HEADER_INIT_FAILED);
        return MMI_BPP_XHTML_RSP_FILE_ERR;        
    }

    /* open xhtml file */
    if (mmi_bpp_xhtml_cntx_p->xhtml_file)
    {
        FS_Close(mmi_bpp_xhtml_cntx_p->xhtml_file);
        FS_Delete((kal_uint16*)mmi_bpp_cntx_p->xhtml_file);
    }
    mmi_bpp_xhtml_cntx_p->xhtml_file = FS_Open((kal_uint16*)mmi_bpp_cntx_p->xhtml_file, (FS_READ_WRITE | FS_CREATE_ALWAYS));
    if (mmi_bpp_xhtml_cntx_p->xhtml_file < 0)
    {
        MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_COMPOSE_FILE_HEADER_OPEN_FAILED, mmi_bpp_xhtml_cntx_p->xhtml_file); 
        return MMI_BPP_XHTML_RSP_FILE_ERR;
    }

    /* XHTML_DOC_TYPE_HDR */
    ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, XHTML_DOC_TYPE_HDR, strlen(XHTML_DOC_TYPE_HDR), &(written));
    /* FS_Write error */    
    if (ret < 0)
    {   
        MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_COMPOSE_FILE_HEADER_WRITE_FAILED, ret);
        FS_Close(mmi_bpp_xhtml_cntx_p->xhtml_file);
        return MMI_BPP_XHTML_RSP_FILE_ERR;
    }

    /* get_ctrl_buffer */
    mmi_bpp_xhtml_cntx_p->tmp_buff = get_ctrl_buffer(XHTML_WRITE_THRSHOLD);

    /* XHTML_DOC_BODY_HDR */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_DOC_BODY_HDR);
    /* XHTML_HEAD_START */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_HEAD_START);
    /* XHTML_TITLE */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_TITLE);
    /* XHTML_STYLE_START */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_STYLE_START);

    /* xhtml_media_style according media */
    switch(media)
    {
        case MMI_BPP_XHTML_MEDIA_A4:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_PAGE_STYLE_A4);
            break;            
        case MMI_BPP_XHTML_MEDIA_US:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_PAGE_STYLE_US);
            break;
        case MMI_BPP_XHTML_MEDIA_4X6:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_PAGE_STYLE_4X6);
            break;
        default:
            break;
    }
    /* XHTML_PAGE_STYLE_END*/
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_PAGE_STYLE_END);
    
    /* XHTML_STYLE_COMMON */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_STYLE_COMMON);
    
    /* XHTML_STYLE_CENTER */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_STYLE_CENTER);

    return MMI_BPP_XHTML_RSP_DONE;
}

#define XHTML_CSS_LIB
/*****************************************************************************
 * FUNCTION
 *  app_config_table_css
 * DESCRIPTION
 *  This function is to config the css of application table
 * PARAMETERS
 *  mmi_bpp_xhtml_table_css_struct*
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_config_table_css(mmi_bpp_xhtml_table_css_struct* tab_css)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG4(MMI_BPP_XHTML_APP_COMPOSE_TABLE_CSS, tab_css->caption_side, tab_css->text_align, tab_css->caption_margin, tab_css->font_size);

    if (tab_css->caption_side == MMI_BPP_XHTML_ALIGN_NONE)
        return MMI_BPP_XHTML_RSP_DONE;         

    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                "caption { ");

    /* caption setting */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                "caption-side: ");    
    switch(tab_css->caption_side)
    {
        case MMI_BPP_XHTML_ALIGN_TOP:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, 
                                                        ALIGN_TOP);
            if (tab_css->caption_margin > 0)
            {
                mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                            "margin-bottom: %d%%; ",tab_css->caption_margin);
            }
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                        TEXT_ALIGN);
            switch(tab_css->text_align)
            {
                case MMI_BPP_XHTML_ALIGN_LEFT:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_LEFT);
                    break;
                case MMI_BPP_XHTML_ALIGN_RIGHT:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_RIGHT);
                    break;
                case MMI_BPP_XHTML_ALIGN_CENTER:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_CENTER);
                    break;                    
            }            
            break;
            
        case MMI_BPP_XHTML_ALIGN_BOTTOM:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                        ALIGN_BOTTOM);
            if (tab_css->caption_margin > 0)
            {
                mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                            "margin-top: %d%%; ",tab_css->caption_margin);
            }
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                        TEXT_ALIGN);
            switch(tab_css->text_align)
            {
                case MMI_BPP_XHTML_ALIGN_LEFT:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_LEFT);
                    break;
                case MMI_BPP_XHTML_ALIGN_RIGHT:                
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_RIGHT);
                    break;
                case MMI_BPP_XHTML_ALIGN_CENTER:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_CENTER);
                    break;                    
            }
            break;
            
        case MMI_BPP_XHTML_ALIGN_RIGHT:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                        ALIGN_RIGHT);
            if (tab_css->caption_margin > 0)
            {
                mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                            "margin-left: %d%%; ",tab_css->caption_margin);
            }
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                        VERTICAL_ALIGN);

            switch(tab_css->text_align)
            {
                case MMI_BPP_XHTML_ALIGN_TOP:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, 
                                                                ALIGN_TOP);
                    break;
                case MMI_BPP_XHTML_ALIGN_BOTTOM:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_BOTTOM);
                    break;
                case MMI_BPP_XHTML_ALIGN_MIDDLE:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_MIDDLE);
                    break;
            }
            break;
            
        case MMI_BPP_XHTML_ALIGN_LEFT:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                        ALIGN_LEFT);
            if (tab_css->caption_margin > 0)
            {
                mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, 
                                                            "margin-right: %d%%; ",tab_css->caption_margin);
            }
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                   VERTICAL_ALIGN);
            switch(tab_css->text_align)
            {
                case MMI_BPP_XHTML_ALIGN_TOP:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, 
                                                                ALIGN_TOP);
                    break;
                case MMI_BPP_XHTML_ALIGN_BOTTOM:                
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_BOTTOM);
                    break;
                case MMI_BPP_XHTML_ALIGN_MIDDLE:
                    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                                ALIGN_MIDDLE);
                    break;                    
            }
            break;    
    }
    
    /* set the table width */  
    if (tab_css->table_width > 0)
    {   
        width = bpp_compose_xhtml_calculate_width(tab_css->table_width);
        mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                    "width: %dmm; ", width);
    }
    if (tab_css->font_size > 0)
    {
        mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, 
                                                    "font-size: %dem;",tab_css->font_size);
    }

    /* text color */
    if (tab_css->text_color != MMI_BPP_XHTML_COLOR_NONE)
    {
        mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len,
                                                    "color: ");
        mmi_bpp_xhtml_cntx_p->buf_tmp_len += bpp_compose_xhtml_write_color((kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff,
                                                    mmi_bpp_xhtml_cntx_p->buf_tmp_len, tab_css->text_color);
    }
    
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, 
                                                "}\r\n");
    return MMI_BPP_XHTML_RSP_DONE; 
}

/*****************************************************************************
 * FUNCTION
 *  app_config_style_class
 * DESCRIPTION
 *  This function is to config the css of given class name
 * PARAMETERS
 *  mmi_bpp_xhtml_style_class_struct*
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_config_style_class(mmi_bpp_xhtml_style_class_struct* obj_css)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int     ret;
    int     width = 0;
    kal_uint8*  tmp_buf;
    kal_uint32  tmp_buf_len;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_STYLE_CLASS);

    /* check cntx buffer size */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - XHTML_MAX_CSS_SIZE))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(512);
        tmp_buf_len = 0;
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }
    
    /* class name */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ".");
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len,  (const char*)(obj_css->class_name));
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, " {");
    /* width */
    if (obj_css->width)
    {
        width = bpp_compose_xhtml_calculate_width(obj_css->width);
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "width: %dmm; ", width);    
    }
    /* padding-left */
    if (obj_css->padding_left)
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "padding-left: %d%%; ", obj_css->padding_left);

    /* padding-right */
    if (obj_css->padding_right)
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "padding-right: %d%%; ", obj_css->padding_right);

    /* left border settings */  
    if (obj_css->left_border.border_width)
    {
        if (obj_css->left_border.border_style == MMI_BPP_XHTML_BORDER_SOLID)
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-left: solid %dpx ", obj_css->left_border.border_width);
        else
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-left: dashed %dpx ", obj_css->left_border.border_width);
        tmp_buf_len += bpp_compose_xhtml_write_color(tmp_buf, tmp_buf_len, obj_css->left_border.border_color);        
    }

    /* right border settings */  
    if (obj_css->right_border.border_width)
    {
        if (obj_css->right_border.border_style == MMI_BPP_XHTML_BORDER_SOLID)
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-right: solid %dpx ", obj_css->right_border.border_width);
        else
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-right: dashed %dpx ", obj_css->right_border.border_width);
        tmp_buf_len += bpp_compose_xhtml_write_color(tmp_buf, tmp_buf_len, obj_css->right_border.border_color);
    }

    /* top border settings */  
    if (obj_css->top_border.border_width)
    {
        if (obj_css->top_border.border_style == MMI_BPP_XHTML_BORDER_SOLID)
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-top: solid %dpx ", obj_css->top_border.border_width);
        else
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-top: dashed %dpx ", obj_css->top_border.border_width);
        tmp_buf_len += bpp_compose_xhtml_write_color(tmp_buf, tmp_buf_len, obj_css->top_border.border_color);        
    }

    /* right border settings */  
    if (obj_css->bottom_border.border_width)
    {
        if (obj_css->bottom_border.border_style == MMI_BPP_XHTML_BORDER_SOLID)    
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-bottom: solid %dpx ", obj_css->bottom_border.border_width);
        else
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "border-bottom: dashed %dpx ", obj_css->bottom_border.border_width);
        tmp_buf_len += bpp_compose_xhtml_write_color(tmp_buf, tmp_buf_len, obj_css->bottom_border.border_color);
    }    

    /* back-ground color */
    if (obj_css->bg_color != MMI_BPP_XHTML_COLOR_NONE)
    {
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "background-color: ");
        tmp_buf_len += bpp_compose_xhtml_write_color(tmp_buf, tmp_buf_len, obj_css->bg_color);
    }

    /* text color */    
    if (obj_css->text_color != MMI_BPP_XHTML_COLOR_NONE)
    {
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "color: ");
        tmp_buf_len += bpp_compose_xhtml_write_color(tmp_buf, tmp_buf_len, obj_css->text_color);
    }
    
    /* text-v-align */
    if (obj_css->txt_v_align != MMI_BPP_XHTML_ALIGN_NONE)
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, VERTICAL_ALIGN);
    switch(obj_css->txt_v_align)
    {
        case MMI_BPP_XHTML_ALIGN_TOP:
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ALIGN_TOP);
            break;
        case MMI_BPP_XHTML_ALIGN_BOTTOM:            
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ALIGN_BOTTOM);
            break;            
        case MMI_BPP_XHTML_ALIGN_MIDDLE:
        case MMI_BPP_XHTML_ALIGN_CENTER:
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ALIGN_MIDDLE);
            break;            
    }

    /* text-h-align */
    if (obj_css->txt_h_align != MMI_BPP_XHTML_ALIGN_NONE)
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, TEXT_ALIGN);
    switch(obj_css->txt_h_align)
    {
        case MMI_BPP_XHTML_ALIGN_LEFT:
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ALIGN_LEFT);
            break;
        case MMI_BPP_XHTML_ALIGN_RIGHT:            
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ALIGN_RIGHT);
            break;            
        case MMI_BPP_XHTML_ALIGN_MIDDLE:
        case MMI_BPP_XHTML_ALIGN_CENTER:
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ALIGN_CENTER);
            break;            
    }
    /* class end */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, BRACE);

    /* write file or memory criteria */
    if (write_file_flag)
    {
        if ((tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len) >= XHTML_WRITE_THRSHOLD)
        {   
            /* write chunk header to file */            
            ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
            /* FS_Write error */    
            if (ret < 0)
            {       
                goto CSS_WRITE_FAILED;               
            }

            /* write chunk payload to file */
            ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
            /* FS_Write error */    
            if (ret < 0)
            {       
                goto CSS_WRITE_FAILED;               
            }                 
        }
        else
        {
            /* copy tmp buffer to cntx buffer */
            memcpy(((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len), tmp_buf, tmp_buf_len);
            /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += tmp_buf_len;
        }
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    
    return MMI_BPP_XHTML_RSP_DONE;

    /* only occurs while the write_file_flag is set */
    CSS_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_STYLE_CLASS_WRITE_FAILED, ret);
    /* release the temp buffer */
    free_ctrl_buffer(tmp_buf);
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    return MMI_BPP_XHTML_RSP_FILE_ERR;
}


#define XHTML_TAG_LIB
/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_file_start
 * DESCRIPTION
 *  This function is to compose the file start element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_file_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint8*  tmp_buf;
    kal_uint32  tmp_buf_len;
    mmi_bpp_xhtml_style_class_struct*   logo_css;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    mmi_bpp_xhtml_rsp_enum              rsp;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_FILE_START);

    /* config logo style for customization */
    logo_css = (mmi_bpp_xhtml_style_class_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_style_class_struct));
    memset(logo_css, 0, sizeof(mmi_bpp_xhtml_style_class_struct));
    sprintf((char*)logo_css->class_name, "%s", "logo");

    rsp = app_config_style_class(logo_css);
    free_ctrl_buffer(logo_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {               
        return rsp;
    }
    
    /* check cntx buffer size, 49 = strlen(XHTML_STYLE_END + XHTML_HEAD_END + XHTML_CENTER_START + XHTML_BODY_START) */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - 50))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(64);
        tmp_buf_len = 0;
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }

    /* XHTML_STYLE_END */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_STYLE_END);
    /* XHTML_HEAD_END */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_HEAD_END);
    /* XHTML_BODY_START */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_BODY_START);
    /* XHTML_CENTER_START */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_CENTER_START);

    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto FILE_START_WRITE_FAILED;               
        }

        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
           goto FILE_START_WRITE_FAILED;            
        }
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;

    /* only occurs while the write_file_flag is set */
    FILE_START_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_FILE_START_WRITE_FAILED, ret);
    /* release the temp buffer */
    free_ctrl_buffer(tmp_buf);
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    return MMI_BPP_XHTML_RSP_FILE_ERR;
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_file_failed
 * DESCRIPTION
 *  This function is to handle error case of XHTML-Print document composing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void app_compose_xhtml_file_failed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_FILE_FAILED);
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_file_end
 * DESCRIPTION
 *  This function is to compose the file end element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_file_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    mmi_bpp_xhtml_data_element_struct*  data = NULL;
    mmi_bpp_xhtml_rsp_enum              rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_FILE_END);

    /* check cntx buffer size, 17 = strlen(DIV + logo class) */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - 18))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(32);
        tmp_buf_len = 0;
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }
    
#ifdef __MMI_BPP_LOGO_SUPPORT__    
    /* inline LOGO */  
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_DIV_START);
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, " class=\"logo\">");
    
    /* compose logo image */
    data = (mmi_bpp_xhtml_data_element_struct*)get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
    memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));
    data->app_callback = app_compose_xhtml_file_end_cb;
    data->data_element = gdi_image_get_buf_ptr_from_id(IMG_BPP_DEFAULT_LOGO);
    data->obj_len = gdi_image_get_buf_len_from_id(IMG_BPP_DEFAULT_LOGO);
    data->type = MMI_BPP_XHTML_TYPE_JPG;
    data->img_box = 10;

    rsp = bpp_compose_xhtml_new_img_data(data, write_file_flag, tmp_buf, tmp_buf_len);
    free_ctrl_buffer(data);
#else
    rsp = MMI_BPP_XHTML_RSP_DONE;
#endif
    switch (rsp)
    {
        case MMI_BPP_XHTML_RSP_DONE:
            app_compose_xhtml_file_end_cb(rsp);
        case MMI_BPP_XHTML_RSP_WRITING:
            return MMI_BPP_XHTML_RSP_DONE;
        default:
            return MMI_BPP_XHTML_RSP_FILE_ERR;
    }
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_file_end_cb
 * DESCRIPTION
 *  This function is the callback function of file end element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
void app_compose_xhtml_file_end_cb(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  chk_len = 0;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_FILE_END_CB);

    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    
    tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
    tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
#ifdef __MMI_BPP_LOGO_SUPPORT__    
    /* inline LOGO */    
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_DIV_END);    
#endif    
    /* XHTML_BODY_END */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_BODY_END);
    /* XHTML_FILE_END */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, XHTML_FILE_END);

    /* chunk length should minus the last chunk data (\r\nCHK 0 0 LAST\r\n) = 16 */
    chk_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len - 16;

    /* write chunk header to file */
    ret = bpp_compose_xhtml_chunk_header(1, chk_len, MMI_BPP_XHTML_CHK_LAST);
    /* FS_Write error */    
    if (ret < 0)
    {       
        goto FILE_END_WRITE_FAILED;               
    }

    /* temp buffer exist? */
    if (write_file_flag)
    {
        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto FILE_END_WRITE_FAILED;           
        }
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(NULL, 0);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto FILE_END_WRITE_FAILED;           
        }
    }
    
    /* reset cntx */
    bpp_compose_xhtml_cntx_reset();
    ClearProtocolEventHandler(MSG_ID_BT_BPP_SEND_DOC_REQ);
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_DONE);
    return;

    FILE_END_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_FILE_END_WRITE_FAILED, ret);
    /* release the temp buffer and cntx buffer */
    if(write_file_flag && tmp_buf)
    {
        free_ctrl_buffer(tmp_buf);
    }
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_table_element_start
 * DESCRIPTION
 *  This function is to compose the table start element of XHTML-Print document
 * PARAMETERS
 *  kal_uint8*
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_table_element_start(kal_uint8* caption, kal_uint8 cap_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    kal_uint8   tmp_buf_size; 
    kal_uint32  parsed_length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_TABLE_ELEMENT_START);

     /* caption exist? */
    if (caption == NULL)
    {       
        /* check cntx buffer size, 9 = strlen(XHTML_TABLE_START) */
        tmp_buf_size = 10;
    }
    else
    {        
        /* check raw data */
        parsed_length = bpp_compose_xhtml_parse_special_chars((U8*)caption, cap_len);
        /* check cntx buffer size, 30 = strlen(XHTML_TABLE_START + XHTML_CAPTION_START + XHTML_CAPTION_END) */
        tmp_buf_size = 31 + parsed_length;
    }

    /* tmp buffer required? */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - tmp_buf_size))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(tmp_buf_size);
        tmp_buf_len = 0;
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }
    
    /* XHTML_TABLE_START */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_TABLE_START);

    /* caption */
    if (caption != NULL)
    {
        /* XHTML_CAPTION_START */
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_CAPTION_START);
        /* XHTML_CAPTION according to parm caption */
        //tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, (const char*)caption);
        bpp_compose_xhtml_copy_txt_data((U8*)tmp_buf + tmp_buf_len, (U8*)caption, cap_len);
        tmp_buf_len += parsed_length;

        /* XHTML_CAPTION_END */
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_CAPTION_END);
    }

    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto TABLE_START_WRITE_FAILED;               
        }

        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
           goto TABLE_START_WRITE_FAILED;            
        }   
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;

    /* write_file_flag go to */
    TABLE_START_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_TABLE_START_WRITE_FAILED, ret);
    if (tmp_buf)
        free_ctrl_buffer(tmp_buf);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    return MMI_BPP_XHTML_RSP_FILE_ERR;    
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_table_element_end
 * DESCRIPTION
 *  This function is to compose the table end element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_table_element_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_TABLE_ELEMENT_END);

    /* check cntx buffer size, 23 = strlen(XHTML_TABLE_END) */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - 24))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(16);
        tmp_buf_len = 0;
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }

    /* XHTML_TABLE_END */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_TABLE_END);
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_CENTER_END);

    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto TABLE_END_WRITE_FAILED;               
        }

        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
           goto TABLE_END_WRITE_FAILED;            
        }
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;

    TABLE_END_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_TABLE_END_WRITE_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    return MMI_BPP_XHTML_RSP_FILE_ERR;    
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_row_element_start
 * DESCRIPTION
 *  This function is to compose the row start element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_row_element_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_ROW_ELEMENT_START);

    /* check cntx buffer size, 6 = strlen(XHTML_ROW_START) */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - 7))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(8);
        tmp_buf_len = 0;        
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }

    /* XHTML_ROW_START */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_ROW_START);

    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto ROW_START_WRITE_FAILED;               
        }

        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
           goto ROW_START_WRITE_FAILED;            
        }
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;

    ROW_START_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_ROW_START_WRITE_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    return MMI_BPP_XHTML_RSP_FILE_ERR;        
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_row_element_end
 * DESCRIPTION
 *  This function is to compose the row end element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_row_element_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_ROW_ELEMENT_END);

    /* check cntx buffer size, 7 = strlen(XHTML_ROW_END) */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - 8))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(8);
        tmp_buf_len = 0;        
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }

    /* XHTML_ROW_START */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_ROW_END);

    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto ROW_END_WRITE_FAILED;               
        }

        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
           goto ROW_END_WRITE_FAILED;            
        }   
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;

    ROW_END_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_ROW_END_WRITE_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);    
    return MMI_BPP_XHTML_RSP_FILE_ERR;            
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_data_element_start
 * DESCRIPTION
 *  This function is to compose the data start element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_DATA_ELEMENT_START);
    
    /* check cntx buffer size, 3 = strlen("<td") */
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - 4))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(4);
        tmp_buf_len = 0;        
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }

    /* "<td " */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "<td");
    
    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto DATA_START_WRITE_FAILED;               
        }

        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
           goto DATA_START_WRITE_FAILED;            
        }
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;
    
    DATA_START_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_DATA_START_WRITE_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);    
    return MMI_BPP_XHTML_RSP_FILE_ERR;     
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_data_element_end
 * DESCRIPTION
 *  This function is to compose the data end element of XHTML-Print document
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  tmp_buf_len;
    kal_uint8*  tmp_buf;
    MMI_BOOL    write_file_flag = MMI_FALSE;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_DATA_ELEMENT_END);

    if (mmi_bpp_xhtml_cntx_p->div_flag)
    {
        /* check cntx buffer size, 13 = strlen(XHTML_CELL_END) + strlen(XHTML_DIV_END) */
        tmp_buf_len = 13;
    }
    else
    {
        /* check cntx buffer size, 7 = strlen(XHTML_CELL_END) */
        tmp_buf_len = 8;
    }
    
    if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - tmp_buf_len))
    {        
        /* get_ctrl_buffer */
        tmp_buf = get_ctrl_buffer(tmp_buf_len);
        tmp_buf_len = 0;
        write_file_flag = MMI_TRUE;
    }
    else
    {
        tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
        tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
    }

    if (mmi_bpp_xhtml_cntx_p->div_flag)
    {
        /* XHTML_DIV_END */
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_DIV_END);
        mmi_bpp_xhtml_cntx_p->div_flag = MMI_FALSE;
    }    
    
    /* XHTML_CELL_END */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, XHTML_CELL_END);
    /* set status of cntx to none for inline data operation */
    mmi_bpp_xhtml_cntx_p->status = MMI_BPP_XHTML_TD_STATUS_NONE;    

    /* write file or memory criteria */
    if (write_file_flag)
    {
        /* write chunk header to file */
        ret = bpp_compose_xhtml_chunk_header(1, (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len), MMI_BPP_XHTML_CHK_MORE);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto DATA_END_WRITE_FAILED;               
        }
    
        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        /* FS_Write error */    
        if (ret < 0)
        {       
            goto DATA_END_WRITE_FAILED;            
        }
          
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
        /* update mmi_bpp_xhtml_cntx_p->buf_tmp_len */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
    }
    return MMI_BPP_XHTML_RSP_DONE;
        
    DATA_END_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_APP_COMPOSE_DATA_END_WRITE_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);    
    return MMI_BPP_XHTML_RSP_FILE_ERR;     
}

#define XHTML_INLINE_DATA
/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_data_element_from_file
 * DESCRIPTION
 *  This function is to compose the data element content from file
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_from_file(mmi_bpp_xhtml_data_element_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_bpp_xhtml_rsp_enum          rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_DATA_ELEMENT_FROM_FILE);

    /* open the file and save the file handle */
    mmi_bpp_xhtml_cntx_p->tmp_file = data->file_element;
    ASSERT(data->file_element > 0);
    mmi_bpp_xhtml_cntx_p->remain_file_size = data->obj_len;
    mmi_bpp_xhtml_cntx_p->app_callback = data->app_callback;

    /* compose data element */
    rsp = bpp_compose_xhtml_data_element(data);
    return rsp;
}

/*****************************************************************************
 * FUNCTION
 *  app_compose_xhtml_data_element_from_buff
 * DESCRIPTION
 *  This function is to compose the data element content from buffer
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_from_buff(mmi_bpp_xhtml_data_element_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum          rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_APP_COMPOSE_DATA_ELEMENT_FROM_BUFF);

    /* save the data buffer pointer */
    mmi_bpp_xhtml_cntx_p->tmp_data = data->data_element;
    ASSERT(data->data_element);
    mmi_bpp_xhtml_cntx_p->remain_file_size = data->obj_len;
    mmi_bpp_xhtml_cntx_p->app_callback = data->app_callback;

    /* compose data element */
    rsp = bpp_compose_xhtml_data_element(data);
    return rsp;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_data_element
 * DESCRIPTION
 *  This function is to compose the data element content
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_data_element(mmi_bpp_xhtml_data_element_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  tmp_buf_len = 0;
    kal_uint8*  tmp_buf = NULL;
    MMI_BOOL    write_file_flag = MMI_FALSE;    
    mmi_bpp_xhtml_rsp_enum          rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG3(MMI_BPP_XHTML_BPP_COMPOSE_DATA_ELEMENT, data->type, mmi_bpp_xhtml_cntx_p->status, data->new_line);

    /* check cancel flag */
    if (mmi_bpp_xhtml_cntx_p->cancel_flag)
    {
        bpp_compose_xhtml_cntx_reset();
        /* return canceled */
        return MMI_BPP_XHTML_RSP_CANCELED;
    }

    if (mmi_bpp_xhtml_cntx_p->status == MMI_BPP_XHTML_TD_STATUS_COMPOSING)
    {
        /* new div */
        if (data->new_line) 
        {
            /* add div class */
            tmp_buf_len += bpp_compose_xhtml_calculate_tmp_buff_len(data, MMI_BPP_XHTML_DATA_ATTR_DIV);
    
            if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - tmp_buf_len))
            {        
                tmp_buf = get_ctrl_buffer(tmp_buf_len);
                tmp_buf_len = 0;
                write_file_flag = MMI_TRUE;
            }
            else
            {
                tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
                tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
            }
            tmp_buf_len = bpp_compose_xhtml_new_data_element_attr(data, tmp_buf, tmp_buf_len, MMI_BPP_XHTML_DATA_ATTR_DIV);
        }
        else
        {
            /* contine composing the same TD */
            tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
            tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
        }
    }
    /* set status of cntx to composing for inline data operation */
    else 
    {    
        mmi_bpp_xhtml_cntx_p->status = MMI_BPP_XHTML_TD_STATUS_COMPOSING;
    
        /* add td class and settings */
        tmp_buf_len += bpp_compose_xhtml_calculate_tmp_buff_len(data, MMI_BPP_XHTML_DATA_ATTR_NEW);
    
        if (mmi_bpp_xhtml_cntx_p->buf_tmp_len > (XHTML_WRITE_THRSHOLD - tmp_buf_len))
        {        
            tmp_buf = get_ctrl_buffer(tmp_buf_len);
            tmp_buf_len = 0;
            write_file_flag = MMI_TRUE;
        }
        else
        {
            tmp_buf = (kal_uint8*)mmi_bpp_xhtml_cntx_p->tmp_buff;
            tmp_buf_len = mmi_bpp_xhtml_cntx_p->buf_tmp_len;
        }
        tmp_buf_len = bpp_compose_xhtml_new_data_element_attr(data, tmp_buf, tmp_buf_len, MMI_BPP_XHTML_DATA_ATTR_NEW);
    }

    /* data element content */
    switch(data->type)
    {
        case MMI_BPP_XHTML_TYPE_TXT:
            rsp = bpp_compose_xhtml_new_txt_data(data, write_file_flag, tmp_buf, tmp_buf_len);
            break;
        default:
            rsp = bpp_compose_xhtml_new_img_data(data, write_file_flag, tmp_buf, tmp_buf_len);
            break;         
    }

    /* check error code */
    if (rsp == MMI_BPP_XHTML_RSP_FILE_ERR)
    {
        mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
        bpp_compose_xhtml_cntx_reset();
    }
    return rsp;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_new_txt_data
 * DESCRIPTION
 *  This function is to compose the new text data element content
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*, MMI_BOOL, kal_uint32
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_new_txt_data(mmi_bpp_xhtml_data_element_struct* data, MMI_BOOL write_file_flag, kal_uint8* tmp_buf, kal_uint32 tmp_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  read;
    kal_uint32  written;
    kal_uint32  chk_len = 0;
    kal_uint32  parsed_length = 0;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG2(MMI_BPP_XHTML_BPP_COMPOSE_NEW_TXT_DATA, write_file_flag, data->app_callback);

    /* check raw data */
    parsed_length = bpp_compose_xhtml_parse_special_chars((U8*)data->data_element, data->obj_len);

    /* Write file flag */
    if (write_file_flag)
    {
        /* chunk length == buffer + obj */
        if(data->app_callback == NULL)
            chk_len = (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len + parsed_length);
        else
            chk_len = (tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len);

        /* write cntx buffer + tmp buffer to file */
        ret = bpp_compose_xhtml_chunk_header(1, chk_len, MMI_BPP_XHTML_CHK_MORE);
        if (ret < 0)            /* FS_Write error */    
        {       
           goto NEW_TXT_WRITE_FAILED;               
        }        
        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        if (ret < 0)            /* FS_Write error */    
        {       
            goto NEW_TXT_WRITE_FAILED;            
        }
                      
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);

        if(data->app_callback == NULL)
        {   
            if (mmi_bpp_xhtml_cntx_p->tmp_file != NULL)
            {
                goto NEW_TXT_WRITE_WHOLE_FILE;
            }
            else
            {
                goto NEW_TXT_WRITE_WHOLE_BUFF;
            }
        }            
        /* send message to self for file writing */
        mmi_bpp_xhtml_cntx_p->cur_msg = 1;
        bpp_compose_xhtml_data_pause();
        return MMI_BPP_XHTML_RSP_WRITING;      
    }
    else
    {
        kal_uint32 remain_buff_size;
		mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
        remain_buff_size = (XHTML_WRITE_THRSHOLD - mmi_bpp_xhtml_cntx_p->buf_tmp_len);
        
        if (parsed_length < remain_buff_size)
        {
            if (mmi_bpp_xhtml_cntx_p->tmp_file != NULL)
            {
                /* copy the file data to buffer */
                ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, ((U8*)tmp_buf + tmp_buf_len), data->obj_len, &read);
                if (ret < 0)            /* FS_Read error */    
                {       
                    goto NEW_TXT_READ_FAILED;            
                }
            }
            else
            {
                //memcpy(((U8*)tmp_buf + tmp_buf_len), (U8*)mmi_bpp_xhtml_cntx_p->tmp_data, data->obj_len);
                bpp_compose_xhtml_copy_txt_data((U8*)(tmp_buf + tmp_buf_len), (U8*)mmi_bpp_xhtml_cntx_p->tmp_data, data->obj_len);
            }
            
            mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len += parsed_length;
            return MMI_BPP_XHTML_RSP_DONE;
        }

        /* parsed_length > remain_buff_size */
        if(data->app_callback)
        {
            if (mmi_bpp_xhtml_cntx_p->buf_tmp_len)
            {
                /* write cntx buffer + tmp buffer to file */
                ret = bpp_compose_xhtml_chunk_header(1, mmi_bpp_xhtml_cntx_p->buf_tmp_len, MMI_BPP_XHTML_CHK_MORE);
                if (ret < 0)            /* FS_Write error */    
                {       
                    goto NEW_TXT_WRITE_FAILED;               
                }        
                /* write chunk payload to file */
                ret = bpp_compose_xhtml_chunk_payload(NULL, 0);
                if (ret < 0)            /* FS_Write error */    
                {       
                    goto NEW_TXT_WRITE_FAILED;            
                }
            }
            
            /* send message to self for file writing */
            mmi_bpp_xhtml_cntx_p->cur_msg = 1;
            mmi_bpp_xhtml_cntx_p->cur_offset = 0;
            //mmi_bpp_xhtml_cntx_p->cur_offset = remain_buff_size;
            //mmi_bpp_xhtml_cntx_p->remain_file_size -= remain_buff_size;
            bpp_compose_xhtml_data_pause();
            return MMI_BPP_XHTML_RSP_WRITING;                
        }
        else
        {
		    chk_len = (mmi_bpp_xhtml_cntx_p->buf_tmp_len + parsed_length);
            /* write cntx buffer + tmp buffer to file */
            ret = bpp_compose_xhtml_chunk_header(1, chk_len, MMI_BPP_XHTML_CHK_MORE);
            if (ret < 0)            /* FS_Write error */    
            {       
               goto NEW_TXT_WRITE_FAILED;               
            }            
            /* write chunk payload to file */
            ret = bpp_compose_xhtml_chunk_payload(NULL, 0);
            if (ret < 0)            /* FS_Write error */    
            {       
                goto NEW_TXT_WRITE_FAILED;            
            }            
            if (mmi_bpp_xhtml_cntx_p->tmp_file != NULL)
            {
                goto NEW_TXT_WRITE_WHOLE_FILE;
            }
            else
            {
                goto NEW_TXT_WRITE_WHOLE_BUFF;
            }
        }
    }

    NEW_TXT_WRITE_WHOLE_BUFF:
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_NEW_TXT_WRITE_WHOLE_BUFF);
    if (data->obj_len > 0)
    {
        /* write the chk buffer to file */
        if (parsed_length == data->obj_len)
        {
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, mmi_bpp_xhtml_cntx_p->tmp_data, data->obj_len, &(written));
            if (ret < 0)            /* FS_Write error */    
            {       
                goto NEW_TXT_WRITE_FAILED;
            }
        }
        else
        {
            ret = bpp_compose_xhtml_write_txt_data((U8*)mmi_bpp_xhtml_cntx_p->tmp_data, data->obj_len);
            if (ret < 0)            /* FS_Write error */    
            {       
                goto NEW_TXT_WRITE_FAILED;
            }
        }        
    }
    mmi_bpp_xhtml_cntx_p->tmp_data = NULL;
    mmi_bpp_xhtml_cntx_p->remain_file_size = 0;
    return MMI_BPP_XHTML_RSP_DONE;

    NEW_TXT_WRITE_WHOLE_FILE:
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_NEW_TXT_WRITE_WHOLE_FILE);
    /* read file to buffer then write file */
    while (mmi_bpp_xhtml_cntx_p->remain_file_size > XHTML_WRITE_THRSHOLD)
    {
        mmi_bpp_xhtml_cntx_p->remain_file_size -= XHTML_WRITE_THRSHOLD;
        ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, mmi_bpp_xhtml_cntx_p->tmp_buff, XHTML_WRITE_THRSHOLD, &read);
        if (ret < 0)            /* FS_Read error */    
        {       
            goto NEW_TXT_READ_FAILED;            
        }
        /* write the chk buffer to file */
        ret = bpp_compose_xhtml_write_txt_data(mmi_bpp_xhtml_cntx_p->tmp_buff, XHTML_WRITE_THRSHOLD);
        if (ret < 0)            /* FS_Write error */    
        {       
            goto NEW_TXT_WRITE_FAILED;            
        }
    }    
    
    if (mmi_bpp_xhtml_cntx_p->remain_file_size > 0)
    {                
        ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, mmi_bpp_xhtml_cntx_p->tmp_buff, mmi_bpp_xhtml_cntx_p->remain_file_size, &read);
        if (ret < 0)            /* FS_Read error */    
        {       
            goto NEW_TXT_READ_FAILED;            
        }
        /* write the chk buffer to file */
        ret = bpp_compose_xhtml_write_txt_data(mmi_bpp_xhtml_cntx_p->tmp_buff, mmi_bpp_xhtml_cntx_p->remain_file_size);
        if (ret < 0)            /* FS_Write error */    
        {       
            goto NEW_TXT_WRITE_FAILED;            
        }
    }
    if (mmi_bpp_xhtml_cntx_p->tmp_file)
    {
        DRM_close_file(mmi_bpp_xhtml_cntx_p->tmp_file);
        mmi_bpp_xhtml_cntx_p->tmp_file = NULL;
    }
    mmi_bpp_xhtml_cntx_p->remain_file_size = 0;
    return MMI_BPP_XHTML_RSP_DONE;

    NEW_TXT_WRITE_FAILED:    
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_NEW_TXT_WRITE_FAILED, ret);
    /* release the temp buffer */
    if (write_file_flag && tmp_buf)
    {
        free_ctrl_buffer(tmp_buf);
    }
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    return MMI_BPP_XHTML_RSP_FILE_ERR;

    NEW_TXT_READ_FAILED:     
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_NEW_TXT_READ_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    return MMI_BPP_XHTML_RSP_FILE_ERR;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_new_img_data
 * DESCRIPTION
 *  This function is to compose the new image header element content
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*, MMI_BOOL, kal_uint32
 * RETURNS
 *  mmi_bpp_xhtml_rsp_enum
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_new_img_data(mmi_bpp_xhtml_data_element_struct* data, MMI_BOOL write_file_flag, kal_uint8* tmp_buf, kal_uint32 tmp_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  read;
    kal_uint32  chk_len = 0; 
    kal_uint32  offset;
    int         width = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG2(MMI_BPP_XHTML_BPP_COMPOSE_NEW_IMG_DATA, write_file_flag, data->app_callback);

    /* set cntx */
    mmi_bpp_xhtml_cntx_p->chk_count++;
    chk_len = bpp_compose_xhtml_calculate_ref_buff_len(data->type, &width, data->img_box);
    
    /* ------- write chk 1 data to file -------*/
    if (write_file_flag)
    {
        chk_len += tmp_buf_len + mmi_bpp_xhtml_cntx_p->buf_tmp_len;
        /* write cntx buffer + tmp buffer to file */
        ret = bpp_compose_xhtml_chunk_header(1, chk_len, MMI_BPP_XHTML_CHK_MORE);
        if (ret < 0)            /* FS_Write error */    
        {       
           goto NEW_IMG_WRITE_FAILED;               
        }        
        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(tmp_buf, tmp_buf_len);
        if (ret < 0)            /* FS_Write error */    
        {       
            goto NEW_IMG_WRITE_FAILED;            
        }            
           
        /* release the temp buffer */
        free_ctrl_buffer(tmp_buf);
    }
    else
    {
		mmi_bpp_xhtml_cntx_p->buf_tmp_len = tmp_buf_len;
        chk_len += mmi_bpp_xhtml_cntx_p->buf_tmp_len;        
        /* write cntx buffer + tmp buffer to file */
        ret = bpp_compose_xhtml_chunk_header(1, chk_len, MMI_BPP_XHTML_CHK_MORE);
        if (ret < 0)            /* FS_Write error */    
        {       
           goto NEW_IMG_WRITE_FAILED;               
        }        
        /* write chunk payload to file */
        ret = bpp_compose_xhtml_chunk_payload(NULL, 0);
        if (ret < 0)            /* FS_Write error */    
        {       
            goto NEW_IMG_WRITE_FAILED;            
        }                
    }

    /* write inline reference link */
    bpp_compose_xhtml_new_image_link(data->type, width);
    ret = bpp_compose_xhtml_chunk_payload(NULL, 0);
    if (ret < 0)            /* FS_Write error */    
    {       
        goto NEW_IMG_WRITE_FAILED;            
    }

    bpp_compose_xhtml_new_image_header(data->type, data->obj_len);

    /* for logo case -> assign the callback and tmp_data */
    mmi_bpp_xhtml_cntx_p->tmp_file = data->file_element;
    mmi_bpp_xhtml_cntx_p->tmp_data = data->data_element;
    mmi_bpp_xhtml_cntx_p->remain_file_size = data->obj_len;
    mmi_bpp_xhtml_cntx_p->app_callback = data->app_callback;

    /* get image header offset */
    offset = bpp_compose_xhtml_calculate_img_offset(data->type);
    /* non-JPEG may happens */
    if (offset > data->obj_len)
    {
        offset = data->obj_len;
    }

    if (mmi_bpp_xhtml_cntx_p->tmp_file != NULL)
    {
        /* copy the file data to buffer */
        ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, ((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len), offset, &read);
        if (ret < 0)            /* FS_Read error */    
        {       
            goto NEW_IMG_READ_FAILED;            
        }              
    }
    else
    {
        memcpy(((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len), (U8*)mmi_bpp_xhtml_cntx_p->tmp_data, offset);
    }
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += offset;
    mmi_bpp_xhtml_cntx_p->remain_file_size -= offset;

    /* write buffer to file */
    if (mmi_bpp_xhtml_cntx_p->remain_file_size > 0)
        bpp_compose_xhtml_chunk_header(mmi_bpp_xhtml_cntx_p->chk_count, mmi_bpp_xhtml_cntx_p->buf_tmp_len, MMI_BPP_XHTML_CHK_MORE);
    else
        bpp_compose_xhtml_chunk_header(mmi_bpp_xhtml_cntx_p->chk_count, mmi_bpp_xhtml_cntx_p->buf_tmp_len, MMI_BPP_XHTML_CHK_LAST);

    ret = bpp_compose_xhtml_chunk_payload(NULL, 0);
    if (ret < 0)          
    {       
        goto NEW_IMG_WRITE_FAILED;
    }
    if (mmi_bpp_xhtml_cntx_p->remain_file_size == 0)
    {
        return MMI_BPP_XHTML_RSP_DONE;
    }

    ASSERT(data->app_callback);
    /* send message to self for file writing */
    mmi_bpp_xhtml_cntx_p->cur_msg = mmi_bpp_xhtml_cntx_p->chk_count;
    mmi_bpp_xhtml_cntx_p->cur_offset = offset;
    bpp_compose_xhtml_data_pause();
    return MMI_BPP_XHTML_RSP_WRITING;      
     
    NEW_IMG_WRITE_FAILED:
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_NEW_IMG_WRITE_FAILED, ret);
    /* release the temp buffer */
    if (write_file_flag && tmp_buf)
    {
        free_ctrl_buffer(tmp_buf);
    }
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    return MMI_BPP_XHTML_RSP_FILE_ERR;

    NEW_IMG_READ_FAILED:     
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_NEW_IMG_READ_FAILED, ret);
    /* reset the context */
    bpp_compose_xhtml_cntx_reset();
    return MMI_BPP_XHTML_RSP_FILE_ERR;
}

#define XHTML_WRITER
/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_chunk_header
 * DESCRIPTION
 *  This function is to write the chunk header to file
 * PARAMETERS
 *  kal_uint8, kal_uint32, mmi_bpp_xhtml_chk_enum
 * RETURNS
 *  int
 *****************************************************************************/
int bpp_compose_xhtml_chunk_header(kal_uint8 chk_num, kal_uint32 len, mmi_bpp_xhtml_chk_enum chk_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  written;
    U8          chk_buffer[20];
    U8          chk_tmp_len = 0;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG3(MMI_BPP_XHTML_BPP_COMPOSE_CHK_HEADER, chk_num, len, chk_flag);

    /* CHK INFO */
    chk_tmp_len += sprintf((char*)chk_buffer + chk_tmp_len, CHK);
    chk_tmp_len += sprintf((char*)chk_buffer + chk_tmp_len, "%d %d ", chk_num, len);
    if ( chk_flag == MMI_BPP_XHTML_CHK_MORE)
    {
        chk_tmp_len += sprintf((char*)chk_buffer + chk_tmp_len, CHK_MORE);                    
    }
    else
    {
        chk_tmp_len += sprintf((char*)chk_buffer + chk_tmp_len, CHK_LAST);                    
    }

    /* write the chk buffer to file */
    ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, chk_buffer, chk_tmp_len, &(written));    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_chunk_payload
 * DESCRIPTION
 *  This function is to write the chunk payload to file
 * PARAMETERS
 *  kal_uint8*, kal_uint32
 * RETURNS
 *  int
 *****************************************************************************/
int bpp_compose_xhtml_chunk_payload(kal_uint8* tmp_buf, kal_uint32 tmp_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int         ret;
    kal_uint32  written;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG2(MMI_BPP_XHTML_BPP_COMPOSE_CHK_PAYLOAD, tmp_buf, tmp_buf_len);

    /* write the cntx buffer and tmp buffer to file */                       
    ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, mmi_bpp_xhtml_cntx_p->tmp_buff, (mmi_bpp_xhtml_cntx_p->buf_tmp_len), &(written));
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_CHK_PAYLOAD_CNTX_BUFF);

    /* update cntx */
    mmi_bpp_xhtml_cntx_p->buf_tmp_len = 0;

    if ((tmp_buf == NULL) || (ret < 0))
    {   
        return ret;              
    }    
    ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, tmp_buf, tmp_buf_len, &(written));
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_CHK_PAYLOAD_TMP_BUFF);
    return ret;
}


#define XHTML_UTILITY
/*****************************************************************************
 * FUNCTION
 *  bpp_xhtml_work_folder_init
 * DESCRIPTION
 *  This function is to initialize BPP xhtml work folder
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool bpp_xhtml_work_folder_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  xhtml_folder[FMGR_MAX_PATH_LEN*ENCODING_LENGTH];           
    FS_HANDLE   h;
    kal_int32   ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_XHTML_LOG(MMI_BPP_XHTML_WORK_FOLDER_INIT);

#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        MMI_XHTML_LOG(MMI_BPP_XHTML_WORK_FOLDER_INIT_USB_MS);
        return KAL_FALSE;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    BPP_MAKE_TEMP_FOLDER(xhtml_folder);    
    h = FS_Open((kal_uint16*) xhtml_folder, FS_READ_ONLY | FS_OPEN_DIR);
    if (h >= FS_NO_ERROR)
    {
        FS_Close(h);
        return KAL_TRUE;
    }
    else    /* Error handling */
    {
        ret = FS_CreateDir((kal_uint16*) xhtml_folder);
        if (ret < 0)
        {
            MMI_XHTML_LOG(MMI_BPP_XHTML_WORK_FOLDER_INIT_OPEN_ERROR);
            return KAL_FALSE;            
        }        
        FS_SetAttributes((unsigned short*)xhtml_folder, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        return KAL_TRUE;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_write_color
 * DESCRIPTION
 *  This function is to write the border color to buffer
 * PARAMETERS
 *  kal_uint8*, kal_uint32, mmi_bpp_xhtml_color_enum
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_write_color(kal_uint8* tmp_buf, kal_uint32  tmp_buf_len, mmi_bpp_xhtml_color_enum color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  tmp_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_COMPOSE_COLOR, color);
    switch(color)
    {       
        case MMI_BPP_XHTML_COLOR_RED:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Red; ");
            break;
        case MMI_BPP_XHTML_COLOR_YELLOW:                
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Yellow; ");
            break;                
        case MMI_BPP_XHTML_COLOR_BLUE:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Blue; ");
            break;
        case MMI_BPP_XHTML_COLOR_BLACK:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Black; ");
            break;
        case MMI_BPP_XHTML_COLOR_GRAY:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Gray; ");
            break;
        case MMI_BPP_XHTML_COLOR_PURPLE:                
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Purple; ");
            break;                
        case MMI_BPP_XHTML_COLOR_MAROON:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Maroon; ");
            break;
        case MMI_BPP_XHTML_COLOR_GREEN:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Green; ");
            break;
        case MMI_BPP_XHTML_COLOR_NAVY:
            tmp_len = sprintf((char*)tmp_buf + tmp_buf_len, "Navy; ");
            break;
    }
    return tmp_len;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_write_txt_data
 * DESCRIPTION
 *  This function is to write txt data
 * PARAMETERS
 *  U8*, U32
 * RETURNS
 *  int
 *****************************************************************************/
int bpp_compose_xhtml_write_txt_data(U8* data, U32 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  written;
    U8*         temp;
    int         offset = 0;
    int         i;
    int         ret = 0;
    char        temp2[6] = {0,0,0,0,0,0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = data;
    
    for (i = 0; i < data_len; i++)
    {
        if (temp[0] == '&')
        {
            strncpy(temp2, "&amp;", 5);
            if (i - offset > 0)
            {
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, (data + offset), (i - offset), &(written));
                if (ret < 0)
                    break;
            }
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, temp2, 5, &(written));
            if (ret < 0)
                break;
            offset = i+1;
        }
        if (temp[0] == '<')
        {
            strncpy(temp2, "&lt;", 4);
            if (i - offset > 0)
            {
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, (data + offset), (i - offset), &(written));
                if (ret < 0)
                    break;
            }
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, temp2, 4, &(written));
            if (ret < 0)
                break;
            offset = i+1;
        }
        if (temp[0] == '>')
        {
            strncpy(temp2, "&gt;", 4);
            if (i - offset > 0)
            {
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, (data + offset), (i - offset), &(written));
                if (ret < 0)
                    break;
            }
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, temp2, 4, &(written));
            if (ret < 0)
                break;
            offset = i+1;
        }
        if (temp[0] == '\'')
        {
            strncpy(temp2, "&apos;", 6);
            if (i - offset > 0)
            {
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, (data + offset), (i - offset), &(written));
                if (ret < 0)
                    break;
            }
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, temp2, 6, &(written));
            if (ret < 0)
                break;
            offset = i+1;
        }
        if (temp[0] == '\"')
        {
            strncpy(temp2, "&quot;", 6);
            if (i - offset > 0)
            {
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, (data + offset), (i - offset), &(written));
                if (ret < 0)
                    break;
            }
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, temp2, 6, &(written));
            if (ret < 0)
                break;
            offset = i+1;
        }
        
        temp++;
    }

    if (i - offset > 0)
        ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, (data + offset), (i - offset), &(written));

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_copy_txt_data
 * DESCRIPTION
 *  This function is to copy txt data to buffer
 * PARAMETERS
 *  U8*, U32
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_compose_xhtml_copy_txt_data(U8* dest_buf, U8* src_buf, U32 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*         temp;
    int         offset = 0;
    int         i;
    char        temp2[6] = {0,0,0,0,0,0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = src_buf;
    
    for (i = 0; i < data_len; i++)
    {
        if (temp[0] == '&')
        {
            strncpy(temp2, "&amp;", 5);
            if (i - offset > 0)
            {
                memcpy(dest_buf, (src_buf + offset), (i - offset));
                dest_buf += (i - offset);
            }
            memcpy(dest_buf, temp2, 5);
            dest_buf += 5;
            offset = i+1;
        }
        if (temp[0] == '<')
        {
            strncpy(temp2, "&lt;", 4);
            if (i - offset > 0)
            {
                memcpy(dest_buf, (src_buf + offset), (i - offset));
                dest_buf += (i - offset);
            }
            memcpy(dest_buf, temp2, 4);
            dest_buf += 4;            
            offset = i+1;
        }
        if (temp[0] == '>')
        {
            strncpy(temp2, "&gt;", 4);
            if (i - offset > 0)
            {
                memcpy(dest_buf, (src_buf + offset), (i - offset));
                dest_buf += (i - offset);
            }
            memcpy(dest_buf, temp2, 4);
            dest_buf += 4;
            offset = i+1;
        }
        if (temp[0] == '\'')
        {
            strncpy(temp2, "&apos;", 6);
            if (i - offset > 0)
            {
                memcpy(dest_buf, (src_buf + offset), (i - offset));
                dest_buf += (i - offset);
            }
            memcpy(dest_buf, temp2, 6);
            dest_buf += 6;
            offset = i+1;
        }
        if (temp[0] == '\"')
        {
            strncpy(temp2, "&quot;", 6);
            if (i - offset > 0)
            {
                memcpy(dest_buf, (src_buf + offset), (i - offset));
                dest_buf += (i - offset);
            }
            memcpy(dest_buf, temp2, 6);
            dest_buf += 6;
            offset = i+1;
        }        
        temp++;
    }
    if (i - offset > 0)
        memcpy(dest_buf, (src_buf + offset), (i - offset));
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_parse_special_chars
 * DESCRIPTION
 *  This function is to calculate the obj_len after transcode the special chars
 * PARAMETERS
 *  U8*, U32
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_parse_special_chars(U8* data, U32 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* temp;
    int parsed_length = 0;
    int i;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = data;
    for (i = 0; i < data_len; i++)
    {
        if (temp[0] == '&')
        {
            parsed_length += 4;
        }
        else if ((temp[0] == '<') || (temp[0] == '>'))
        {
            parsed_length += 3;
        }
        else if ((temp[0] == '\'') || (temp[0] == '\"'))
        {
            parsed_length += 5;
        }
        parsed_length++;
        temp++;
    }
    return (U32)parsed_length;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_calculate_tmp_buff_len
 * DESCRIPTION
 *  This function is to calculate the tmp buffer size required
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*, mmi_bpp_xhtml_data_attr_enum
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_calculate_tmp_buff_len(mmi_bpp_xhtml_data_element_struct* data, mmi_bpp_xhtml_data_attr_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  tmp_buf_len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_CALCULATE_TMP_BUFF_LEN);

    switch(type)
    {
        case MMI_BPP_XHTML_DATA_ATTR_DIV:
            if (mmi_bpp_xhtml_cntx_p->div_flag)
            {
                /* check cntx buffer size, 6 = strlen("</div>") */
                tmp_buf_len += 6;                    
            }
            else
            {
                mmi_bpp_xhtml_cntx_p->div_flag = MMI_TRUE;
            }
            /* check cntx buffer size, 4 = strlen("<div") */
            tmp_buf_len += 4;
            goto DIV;
        default:
            break;
    }
    
    if(data->col_span != 0)
    {
        /* check cntx buffer size, 13 = strlen(" colspan="  "") */
        tmp_buf_len += 13; 
    }
    if(data->row_span != 0)
    {
        /* check cntx buffer size, 13 = strlen(" colspan="  "") */
        tmp_buf_len += 13; 
    }
    
DIV:
    if(data->class_name != NULL)
    {
        /* check cntx buffer size, 9 = strlen(" class="") */
        tmp_buf_len += 9;
        tmp_buf_len += data->name_len;
    }

    /* ">" and '\0' */
    tmp_buf_len += 2;
    return tmp_buf_len;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_calculate_ref_buff_len
 * DESCRIPTION
 *  This function is to calculate the ref buffer size required
 * PARAMETERS
 *  mmi_bpp_xhtml_type_enum, int*, int
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_calculate_ref_buff_len(mmi_bpp_xhtml_type_enum type, int* width, int img_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  tmp_buf_len = 0;
    kal_uint32  chk_num = 0;
    U8          tmp_buffer[5];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_CALCULATE_REF_BUFF_LEN);

    /* chk number */
    chk_num += sprintf((char*)tmp_buffer, "%d", mmi_bpp_xhtml_cntx_p->chk_count);

    /* IMAGE_START */
    /* check cntx buffer size, 4 = strlen("<img") */
    /* IMAGE_SRC_START */
    /* check cntx buffer size, 22 = strlen(" src=\"bpp/inline_image") */
    /* append chk num to img src */
    /* check cntx buffer size, chk_num */
    /* IMAGE_SRC_EXT_END */
    /* check cntx buffer size, 3 = strlen("\"/>") */
    tmp_buf_len += (chk_num + 29);

    /* IMAGE_SRC_EXT_XXX */
    /* check cntx buffer size, strlen(".xxx") */
    switch(type)
    {        
        case MMI_BPP_XHTML_TYPE_WBMP:
            tmp_buf_len += 5;
            break;
        case MMI_BPP_XHTML_TYPE_TXT:
            ASSERT(0);
        case MMI_BPP_XHTML_TYPE_TOTAL:
            mmi_bt_bpp_format_warning_popup();
        default:            
            tmp_buf_len += 4;
            break;
    }

    /* IMG_STYLE */
    /* check cntx buffer size, 18 = strlen(" style=\"width:mm;\"") */
    if (img_box)
    {
        *width = bpp_compose_xhtml_calculate_width(img_box);
        tmp_buf_len += 18;
        tmp_buf_len += sprintf((char*)tmp_buffer, "%d", *width);
    }
    return tmp_buf_len;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_calculate_img_offset
 * DESCRIPTION
 *  This function is to calculate the img file header offset
 * PARAMETERS
 *  mmi_bpp_xhtml_type_enum
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_calculate_img_offset(mmi_bpp_xhtml_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  offset = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_CALCULATE_IMG_OFFSET);

    switch (type)
    {
        case MMI_BPP_XHTML_TYPE_JPG:
            offset = bpp_compose_xhtml_scan_jpeg_file();
            break;
            
        case MMI_BPP_XHTML_TYPE_TXT:
            ASSERT(0);
            
        default:
            offset = (U32)1024;
            break;
    }
    return offset;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_calculate_width
 * DESCRIPTION
 *  This function is to calculate the width of current media
 * PARAMETERS
 *  int
 * RETURNS
 *  int
 *****************************************************************************/
int bpp_compose_xhtml_calculate_width(int width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int bbox_width = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_bpp_xhtml_cntx_p->media)
    {
        case MMI_BPP_XHTML_MEDIA_A4:
            bbox_width = (int)(210 * ((double)width /100 ));
            /* *height = (int)(297 * ((double)img_box /100 )); */
            break;
        case MMI_BPP_XHTML_MEDIA_US:                
            bbox_width = (int)(216 * ((double)width /100 ));
            /* *height = (int)(279 * ((double)img_box /100 )); */
            break;
        case MMI_BPP_XHTML_MEDIA_4X6:                
            bbox_width = (int)(102 * ((double)width /100 ));
            /* *height = (int)(152 * ((double)img_box /100 )); */
            break;
        default:
            ASSERT(0);
    }
    return bbox_width;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_scan_jpeg_file
 * DESCRIPTION
 *  This function is to scan jpeg file header
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_scan_jpeg_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8*  img_buff;
    kal_uint32  read;
    int         ret;
    kal_uint32  offset = 0;
    kal_uint8   type;
    MMI_BOOL    done = MMI_FALSE;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bpp_xhtml_cntx_p->tmp_file)
    {
        if (mmi_bpp_xhtml_cntx_p->remain_file_size > 1024)
        {
            img_buff = get_ctrl_buffer(1024);
            ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, img_buff, 1024, &read);
        }
        else
        {
            img_buff = get_ctrl_buffer(mmi_bpp_xhtml_cntx_p->remain_file_size);
            ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, img_buff, mmi_bpp_xhtml_cntx_p->remain_file_size, &read);
        }

        DRM_seek_file(mmi_bpp_xhtml_cntx_p->tmp_file, 0, FS_FILE_BEGIN);
        if (ret < 0)
        {
            /* treat it as normal case */            
            return (U32)1024;
        }
    }
    else    
        img_buff = mmi_bpp_xhtml_cntx_p->tmp_data;    

    do 
    {
        if (img_buff[offset] != 0xff)
        {
          ++offset;
          continue;
        }
        offset++;
    
        switch ((type = img_buff[offset++])) 
        {
            case 0xda: 
            {
                kal_uint32 len = img_buff[offset] << 8 | img_buff[offset + 1];
                offset += len;
                done = MMI_TRUE;
                break;
            }
    
            case 0xc0:
            case 0xc1:
            case 0xc2:
            case 0xc3:
            case 0xc5:
            case 0xc6:
            case 0xc7:
            case 0xc9:
            case 0xca:
            case 0xcb:
            case 0xcd:
            case 0xce:
            case 0xcf:     
            /* app markers */
            case 0xe0:
            case 0xe1:
            case 0xe2:
            case 0xe3:
            case 0xe4:
            case 0xe5:
            case 0xe6:
            case 0xe7:
            case 0xe8:
            case 0xe9:
            case 0xea:
            case 0xeb:
            case 0xec:
            case 0xed:
            case 0xee:
            case 0xef:
            /* comment */
            case 0xff:
            /* DAC */
            case 0xcc:
            case 0xde:
            case 0xc4:
            case 0x01:
            case 0xd9:
            case 0xdb:
            case 0xfe: 
            {
                kal_uint32 len = img_buff[offset] << 8 | img_buff[offset + 1];
                offset += len;
                break;
            }
            
            case 0xdc:
            case 0xdd:
                offset += 4;
                break;
            case 0xdf:
                offset += 3;
                break;        
            default:
            break;
        } 
    
    } while (!done && offset < 1024);

    if (mmi_bpp_xhtml_cntx_p->tmp_file)
    {
        free_ctrl_buffer(img_buff);
    }

    if (!done)
        offset = (U32)1024;

    return (U32)offset;
}


/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_new_data_element_attr
 * DESCRIPTION
 *  This function is to compose the new data element attribute
 * PARAMETERS
 *  mmi_bpp_xhtml_data_element_struct*, void*, U32, mmi_bpp_xhtml_data_attr_enum
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 bpp_compose_xhtml_new_data_element_attr(mmi_bpp_xhtml_data_element_struct* data, void* tmp_buf, U32 tmp_len, mmi_bpp_xhtml_data_attr_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  tmp_buf_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_NEW_DATA_ELEMENT_ATTR);

    tmp_buf_len = tmp_len;
    
    /* class name */
    if(data->class_name[0] != '\0')
    {
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CLASS_ATTR);
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, (const char*)data->class_name); 
        tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "\"");
    }
    if (type != MMI_BPP_XHTML_DATA_ATTR_DIV)
    {
        /* colspan */    
        if(data->col_span != 0)
        {
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, COL_SPAN_ATTR);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "%d", data->col_span); 
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "\"");
        }
        /* rowspan */    
        if(data->row_span != 0)
        {
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ROW_SPAN_ATTR);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "%d", data->row_span); 
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "\"");
        }
    }
    /* ">" */
    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, ">");

    return tmp_buf_len;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_new_image_header
 * DESCRIPTION
 *  This function is to compose the new image header
 * PARAMETERS
 *  mmi_bpp_xhtml_type_enum, U32
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_compose_xhtml_new_image_header(mmi_bpp_xhtml_type_enum type, U32 obj_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_COMPOSE_NEW_IMAGE_HEADER, type);

    /* ------- write chk header and image header to buffer -------*/
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_TYPE);
    switch (type)
    {
        case MMI_BPP_XHTML_TYPE_JPG:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_JPEG_TYPE);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_LOCATION);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "bpp/inline_image%d", mmi_bpp_xhtml_cntx_p->chk_count);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_JPG);
            break;
        case MMI_BPP_XHTML_TYPE_GIF:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_GIF_TYPE);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_LOCATION);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "bpp/inline_image%d", mmi_bpp_xhtml_cntx_p->chk_count);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_GIF);
            break;
        case MMI_BPP_XHTML_TYPE_BMP:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_BMP_TYPE);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_LOCATION);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "bpp/inline_image%d", mmi_bpp_xhtml_cntx_p->chk_count);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_BMP);
            break;
        case MMI_BPP_XHTML_TYPE_WBMP:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_WBMP_TYPE);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_LOCATION);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "bpp/inline_image%d", mmi_bpp_xhtml_cntx_p->chk_count);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_WBMP);
            break;
        case MMI_BPP_XHTML_TYPE_PNG:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_PNG_TYPE);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_LOCATION);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "bpp/inline_image%d", mmi_bpp_xhtml_cntx_p->chk_count);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_PNG);
            break;
         case MMI_BPP_XHTML_TYPE_SVG:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SVG_TYPE);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, CONTENT_LOCATION);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "bpp/inline_image%d", mmi_bpp_xhtml_cntx_p->chk_count);
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_SVG);
            break;            
    }
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "\r\n\r\n");
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_new_image_link
 * DESCRIPTION
 *  This function is to compose the new image link
 * PARAMETERS
 *  mmi_bpp_xhtml_type_enum, int
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_compose_xhtml_new_image_link(mmi_bpp_xhtml_type_enum type, int width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* write reference link to buffer */    
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_START);

    /* check the bounding block settings */
    if (width > 0)
    {
        /*
        mmi_bpp_xhtml_cntx_p->buf_tmp_len += 
            sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, " style=\"width:%dmm; height:%dmm;\"", width, height);
            */
        mmi_bpp_xhtml_cntx_p->buf_tmp_len += 
            sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, " style=\"width:%dmm;\"", width);
            
    }

    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_START);
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, "%d", mmi_bpp_xhtml_cntx_p->chk_count);
    switch (type)
    {
        case MMI_BPP_XHTML_TYPE_JPG:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_JPG);
            break;
        case MMI_BPP_XHTML_TYPE_GIF:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_GIF);
            break;
        case MMI_BPP_XHTML_TYPE_BMP:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_BMP);
            break;
        case MMI_BPP_XHTML_TYPE_WBMP:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_WBMP);
            break;
        case MMI_BPP_XHTML_TYPE_PNG:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_PNG);
            break;
        case MMI_BPP_XHTML_TYPE_SVG:
            mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_EXT_SVG);
            break;
    }
    mmi_bpp_xhtml_cntx_p->buf_tmp_len += sprintf((char*)mmi_bpp_xhtml_cntx_p->tmp_buff + mmi_bpp_xhtml_cntx_p->buf_tmp_len, IMAGE_SRC_END);
}


/*****************************************************************************
 * FUNCTION
 *  bpp_cancel_xhtml_composing
 * DESCRIPTION
 *  This function is to cancel the xhtml composing operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_cancel_xhtml_composing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/           

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_CANCEL_COMPOSE);
    /* set cancel flag */
    mmi_bpp_xhtml_cntx_p->cancel_flag = MMI_TRUE;
    bpp_compose_xhtml_cntx_reset();
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_cntx_reset
 * DESCRIPTION
 *  This function is to reset the cntx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_compose_xhtml_cntx_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/           

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_CNTX_RESET);

    /* reset cntx */  
    if (mmi_bpp_xhtml_cntx_p->tmp_buff)
    {
        free_ctrl_buffer(mmi_bpp_xhtml_cntx_p->tmp_buff);
        mmi_bpp_xhtml_cntx_p->tmp_buff = NULL;
    }
    
    mmi_bpp_xhtml_cntx_p->remain_file_size = 0;
    mmi_bpp_xhtml_cntx_p->tmp_data = NULL;

    FS_Close(mmi_bpp_xhtml_cntx_p->xhtml_file);
    if (mmi_bpp_xhtml_cntx_p->tmp_file)
    {
        DRM_close_file(mmi_bpp_xhtml_cntx_p->tmp_file);
        mmi_bpp_xhtml_cntx_p->tmp_file = NULL;
    }
}

#define XHTML_DATA_HDLR
/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_data_pause
 * DESCRIPTION
 *  This function is to pause the data composing operation by sending msg to self
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_compose_xhtml_data_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE msg;            

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_DATA_PAUSE);

    msg.oslSrcId   = MOD_MMI;
    msg.oslDestId  = MOD_MMI;
    msg.oslMsgId   = MSG_ID_BT_BPP_SEND_DOC_REQ;
    msg.oslSapId   = INVALID_SAP;
    msg.oslDataPtr = NULL;
    msg.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&msg);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_compose_xhtml_data_resume_hdlr
 * DESCRIPTION
 *  This function is to resume the data composing operation by sending msg to self
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
void bpp_compose_xhtml_data_resume_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/           
    int         ret;
    kal_uint32  read;
    kal_uint32  written;
    kal_uint8*  tmp_buf;
    kal_uint32  tmp_buf_len = 0;
    kal_uint32  parsed_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_XHTML_LOG(MMI_BPP_XHTML_BPP_COMPOSE_DATA_RESUME);

    if (mmi_bpp_xhtml_cntx_p->app_callback == NULL)
    {
        /* withoit callback function */
        ASSERT(0);
    }

    if (mmi_bpp_xhtml_cntx_p->cancel_flag)
    {
        bpp_compose_xhtml_cntx_reset();
        /* return canceled */
        mmi_bpp_xhtml_cntx_p->app_callback(MMI_BPP_XHTML_RSP_CANCELED);
        return;
    }

    /* check buffer based or file based */
    if (mmi_bpp_xhtml_cntx_p->tmp_file)
    {
        /* read file to buffer then write file */
        if (mmi_bpp_xhtml_cntx_p->remain_file_size > XHTML_WRITE_THRSHOLD)
        {
            mmi_bpp_xhtml_cntx_p->remain_file_size -= XHTML_WRITE_THRSHOLD;
            ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, mmi_bpp_xhtml_cntx_p->tmp_buff, XHTML_WRITE_THRSHOLD, &read);
            if (ret < 0)            /* FS_Read error */    
            {       
                goto DATA_RESUME_READ_FAILED;
            }
            
            /* get_ctrl_buffer */
            tmp_buf = get_ctrl_buffer(64);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK);
            if (mmi_bpp_xhtml_cntx_p->cur_msg == 1)
            {
                /* check raw data */
                parsed_length = bpp_compose_xhtml_parse_special_chars((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff, XHTML_WRITE_THRSHOLD);
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "1 %d ", parsed_length);
            }
            else                
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "%d 2048 ", mmi_bpp_xhtml_cntx_p->cur_msg);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK_MORE);

            /* write the chk header to file */
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, tmp_buf, tmp_buf_len, &(written));
            if (ret < 0)            /* FS_Write error */    
            {       
                goto DATA_RESUME_WRITE_FAILED;            
            }
            free_ctrl_buffer(tmp_buf);

            /* write the chk buffer to file */
            if (mmi_bpp_xhtml_cntx_p->cur_msg != 1)
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, mmi_bpp_xhtml_cntx_p->tmp_buff, XHTML_WRITE_THRSHOLD, &(written));
            else
                ret = bpp_compose_xhtml_write_txt_data((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff, XHTML_WRITE_THRSHOLD);

            if (ret < 0)            /* FS_Write error */    
            {       
                goto DATA_RESUME_WRITE_FAILED;            
            }
            /* send message to self for file writing */
            bpp_compose_xhtml_data_pause();
            return;
        }    
        else
        {                
            ret = DRM_read_file(mmi_bpp_xhtml_cntx_p->tmp_file, mmi_bpp_xhtml_cntx_p->tmp_buff, mmi_bpp_xhtml_cntx_p->remain_file_size, &read);
            if (ret < 0)            /* FS_Read error */    
            {       
                goto DATA_RESUME_READ_FAILED;            
            }

            /* get_ctrl_buffer */
            tmp_buf = get_ctrl_buffer(64);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK);
            
            if (mmi_bpp_xhtml_cntx_p->cur_msg == 1)
            {
                /* check raw data */
                parsed_length = bpp_compose_xhtml_parse_special_chars((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff, mmi_bpp_xhtml_cntx_p->remain_file_size);
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "1 %d ", parsed_length);
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK_MORE);                
            }
            else
            {
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "%d %d ", mmi_bpp_xhtml_cntx_p->cur_msg, mmi_bpp_xhtml_cntx_p->remain_file_size);
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK_LAST);
            }

            /* write the chk header to file */
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, tmp_buf, tmp_buf_len, &(written));
            if (ret < 0)            /* FS_Write error */    
            {       
                goto DATA_RESUME_WRITE_FAILED;            
            }
            free_ctrl_buffer(tmp_buf);
            
            /* write the chk buffer to file */
            if (mmi_bpp_xhtml_cntx_p->cur_msg != 1)
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, mmi_bpp_xhtml_cntx_p->tmp_buff, mmi_bpp_xhtml_cntx_p->remain_file_size, &(written));
            else
                ret = bpp_compose_xhtml_write_txt_data((U8*)mmi_bpp_xhtml_cntx_p->tmp_buff, mmi_bpp_xhtml_cntx_p->remain_file_size);

            if (ret < 0)            /* FS_Write error */    
            {       
                goto DATA_RESUME_WRITE_FAILED;            
            }
            DRM_close_file(mmi_bpp_xhtml_cntx_p->tmp_file);
            mmi_bpp_xhtml_cntx_p->tmp_file = NULL;
            mmi_bpp_xhtml_cntx_p->remain_file_size = 0;
            if (mmi_bpp_xhtml_cntx_p->cur_msg == 1)
                mmi_bpp_xhtml_cntx_p->cur_msg = 0;
            mmi_bpp_xhtml_cntx_p->app_callback(MMI_BPP_XHTML_RSP_DONE);
            return;
        }        
    }
    else
    {
        if (mmi_bpp_xhtml_cntx_p->remain_file_size >= XHTML_WRITE_THRSHOLD)
        {
            /* get_ctrl_buffer */
            tmp_buf = get_ctrl_buffer(64);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK);
            if (mmi_bpp_xhtml_cntx_p->cur_msg == 1)
            {
                /* check raw data */
                parsed_length = bpp_compose_xhtml_parse_special_chars(((U8*)mmi_bpp_xhtml_cntx_p->tmp_data + mmi_bpp_xhtml_cntx_p->cur_offset), XHTML_WRITE_THRSHOLD);
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "1 %d ", parsed_length);
            }
            else
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "%d 2048 ", mmi_bpp_xhtml_cntx_p->cur_msg);
            tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK_MORE);


            /* write the chk header to file */
            ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, tmp_buf, tmp_buf_len, &(written));
            if (ret < 0)            /* FS_Write error */    
            {       
                goto DATA_RESUME_WRITE_FAILED;            
            }
            free_ctrl_buffer(tmp_buf);

            /* write the chk buffer to file */
            if (mmi_bpp_xhtml_cntx_p->cur_msg == 1)
                ret = bpp_compose_xhtml_write_txt_data(((U8*)mmi_bpp_xhtml_cntx_p->tmp_data + mmi_bpp_xhtml_cntx_p->cur_offset), XHTML_WRITE_THRSHOLD);
            else
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file,
                                ((char*)mmi_bpp_xhtml_cntx_p->tmp_data + mmi_bpp_xhtml_cntx_p->cur_offset), 
                                XHTML_WRITE_THRSHOLD, &(written));
            if (ret < 0)
            {       
                goto DATA_RESUME_WRITE_FAILED;            
            }

            mmi_bpp_xhtml_cntx_p->remain_file_size -= XHTML_WRITE_THRSHOLD;
            mmi_bpp_xhtml_cntx_p->cur_offset += XHTML_WRITE_THRSHOLD;

            /* send message to self for file writing */
            bpp_compose_xhtml_data_pause();
            return;
        }    
        else
        {                
            if (mmi_bpp_xhtml_cntx_p->remain_file_size > 0)
            {
                /* get_ctrl_buffer */
                tmp_buf = get_ctrl_buffer(64);
                tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK);
				if (mmi_bpp_xhtml_cntx_p->cur_msg == 1)
                {
                    /* check raw data */
                    parsed_length = bpp_compose_xhtml_parse_special_chars(((U8*)mmi_bpp_xhtml_cntx_p->tmp_data + mmi_bpp_xhtml_cntx_p->cur_offset), mmi_bpp_xhtml_cntx_p->remain_file_size);
                    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "1 %d ", parsed_length);
                    tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK_MORE);
                }
				else
				{
					tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, "%d %d ", mmi_bpp_xhtml_cntx_p->cur_msg, mmi_bpp_xhtml_cntx_p->remain_file_size);
					tmp_buf_len += sprintf((char*)tmp_buf + tmp_buf_len, CHK_LAST);
				}
                
                /* write the chk header to file */
                ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file, tmp_buf, tmp_buf_len, &(written));
                if (ret < 0)            /* FS_Write error */    
                {       
                    goto DATA_RESUME_WRITE_FAILED;            
                }
                free_ctrl_buffer(tmp_buf);

                /* write the chk buffer to file */
                if (mmi_bpp_xhtml_cntx_p->cur_msg != 1)
                    ret = FS_Write(mmi_bpp_xhtml_cntx_p->xhtml_file,
                                    ((char*)mmi_bpp_xhtml_cntx_p->tmp_data + mmi_bpp_xhtml_cntx_p->cur_offset),
                                    mmi_bpp_xhtml_cntx_p->remain_file_size, &(written));
                else            
                    ret = bpp_compose_xhtml_write_txt_data(((U8*)mmi_bpp_xhtml_cntx_p->tmp_data + mmi_bpp_xhtml_cntx_p->cur_offset), mmi_bpp_xhtml_cntx_p->remain_file_size);

                if (ret < 0)
                {       
                   goto DATA_RESUME_WRITE_FAILED;            
                }
                mmi_bpp_xhtml_cntx_p->remain_file_size = 0;
                mmi_bpp_xhtml_cntx_p->cur_offset = 0;
            }
            mmi_bpp_xhtml_cntx_p->tmp_data = NULL;
            mmi_bpp_xhtml_cntx_p->buf_tmp_len = 0;
            mmi_bpp_xhtml_cntx_p->app_callback(MMI_BPP_XHTML_RSP_DONE);            
            return;
        }        
    }

    DATA_RESUME_WRITE_FAILED:
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_DATA_RESUME_WRITE_FAILED, ret);
    goto DATA_RESUME_FILE_ERROR;

    DATA_RESUME_READ_FAILED:
    MMI_XHTML_LOG1(MMI_BPP_XHTML_BPP_DATA_RESUME_READ_FAILED, ret);
    goto DATA_RESUME_FILE_ERROR;

    DATA_RESUME_FILE_ERROR:    
    bpp_compose_xhtml_cntx_reset();
    mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);
    mmi_bpp_xhtml_cntx_p->app_callback(MMI_BPP_XHTML_RSP_FILE_ERR);    
}

#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /*__MMI_BT_MTK_SUPPORT__*/
