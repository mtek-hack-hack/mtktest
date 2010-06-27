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
 * BTMMIBppXhtmlGprot.h
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

#ifndef __BT_MMI_BPP_XHTML_GPROT_H__
#define __BT_MMI_BPP_XHTML_GPROT_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BPP_SUPPORT__)

/*****************************************************************
    Define
*****************************************************************/
/* common class name */
#define XHTML_CLASS_NAME_SIZE   (40)
#define MMI_BPP_XHTML_FOLDER   ("@bpp\\")               //for printing document
#define BPP_MAKE_TEMP_FOLDER(x)                   \
       kal_wsprintf( (kal_uint16 *)x, "%c:\\%s",  \
          MMI_PUBLIC_DRV, MMI_BPP_XHTML_FOLDER);

/*****************************************************************
    Enum
*****************************************************************/
typedef enum
{
    MMI_BPP_XHTML_RSP_DONE, 
    MMI_BPP_XHTML_RSP_WRITING,
    MMI_BPP_XHTML_RSP_PARM_ERR,
    MMI_BPP_XHTML_RSP_FILE_ERR,
    MMI_BPP_XHTML_RSP_CANCELED,
    MMI_BPP_XHTML_RSP_TOTAL  
} mmi_bpp_xhtml_rsp_enum;

typedef enum
{
    MMI_BPP_XHTML_ALIGN_NONE,
    MMI_BPP_XHTML_ALIGN_LEFT,
    MMI_BPP_XHTML_ALIGN_RIGHT,
    MMI_BPP_XHTML_ALIGN_TOP,
    MMI_BPP_XHTML_ALIGN_BOTTOM,
    MMI_BPP_XHTML_ALIGN_CENTER,
    MMI_BPP_XHTML_ALIGN_MIDDLE,
    MMI_BPP_XHTML_ALIGN_TOTAL  
} mmi_bpp_xhtml_align_enum;

typedef enum
{
    MMI_BPP_XHTML_COLOR_NONE,
    MMI_BPP_XHTML_COLOR_BLUE,
    MMI_BPP_XHTML_COLOR_YELLOW,
    MMI_BPP_XHTML_COLOR_RED,
    MMI_BPP_XHTML_COLOR_BLACK,
    MMI_BPP_XHTML_COLOR_GRAY,
    MMI_BPP_XHTML_COLOR_PURPLE,
    MMI_BPP_XHTML_COLOR_MAROON,
    MMI_BPP_XHTML_COLOR_GREEN,
    MMI_BPP_XHTML_COLOR_NAVY,
    MMI_BPP_XHTML_COLOR_TOTAL  
} mmi_bpp_xhtml_color_enum;

typedef enum
{
    MMI_BPP_XHTML_TYPE_TXT,
    MMI_BPP_XHTML_TYPE_JPG,
    MMI_BPP_XHTML_TYPE_GIF,
    MMI_BPP_XHTML_TYPE_BMP,
    MMI_BPP_XHTML_TYPE_WBMP,
    MMI_BPP_XHTML_TYPE_PNG,
    MMI_BPP_XHTML_TYPE_SVG,
    MMI_BPP_XHTML_TYPE_TOTAL
} mmi_bpp_xhtml_type_enum;

typedef enum
{
    MMI_BPP_XHTML_MEDIA_A4,
    MMI_BPP_XHTML_MEDIA_US,
    MMI_BPP_XHTML_MEDIA_4X6,
    MMI_BPP_XHTML_MEDIA_TOTAL  
} mmi_bpp_xhtml_media_enum;

typedef enum
{
    MMI_BPP_XHTML_BORDER_SOLID,
    MMI_BPP_XHTML_BORDER_DASHED,
    MMI_BPP_XHTML_BORDER_TOTAL  
} mmi_bpp_xhtml_border_enum;

/* callback function */
typedef void (*ap_callback)(mmi_bpp_xhtml_rsp_enum rsp_code);

/*****************************************************************
    Structure
*****************************************************************/
typedef struct
{
    int                         table_width;    //%
    mmi_bpp_xhtml_align_enum    caption_side;
    mmi_bpp_xhtml_align_enum    text_align;
    mmi_bpp_xhtml_color_enum    text_color;
    U8                          font_size;      //em
    U8                          caption_margin; //%
} mmi_bpp_xhtml_table_css_struct;

typedef struct
{
    mmi_bpp_xhtml_color_enum    border_color;
    mmi_bpp_xhtml_border_enum   border_style;
    U8                          border_width;      //px
} mmi_bpp_xhtml_border_css_struct;

typedef struct
{
    U8  class_name[XHTML_CLASS_NAME_SIZE];  //utf-8(ascii) encoded and null terminated!
    int width;                           //%
    U8  padding_left;                       //%
    U8  padding_right;                      //%
    mmi_bpp_xhtml_border_css_struct left_border;
    mmi_bpp_xhtml_border_css_struct right_border;
    mmi_bpp_xhtml_border_css_struct top_border;
    mmi_bpp_xhtml_border_css_struct bottom_border;
    mmi_bpp_xhtml_color_enum    bg_color;
    mmi_bpp_xhtml_color_enum    text_color;
    mmi_bpp_xhtml_align_enum    txt_h_align;
    mmi_bpp_xhtml_align_enum    txt_v_align;    
} mmi_bpp_xhtml_style_class_struct;

typedef struct
{
    U8          class_name[XHTML_CLASS_NAME_SIZE];  //utf-8(ascii) encoded
    U8          name_len;                           //class name length
    U8          row_span;                           //how many rows spanned of this cell
    U8          col_span;                           //how many columns spanned of this cell
    kal_bool    new_line;                           //new line flag
    FS_HANDLE   file_element;                       //file handle of file
    void*       data_element;                       //point data buffer    
    U32         obj_len;                            //length of obj(buffer len or file size)
    ap_callback app_callback;                       //callback function for this cell registered by app
    int         img_box;                            //%
    mmi_bpp_xhtml_type_enum     type;               //object type
} mmi_bpp_xhtml_data_element_struct;

/*****************************************************************
    Global Function
*****************************************************************/
/* XHTML FILE Level */
mmi_bpp_xhtml_rsp_enum bpp_compose_xhtml_file_header(mmi_bpp_xhtml_media_enum media);

/* XHTML CSS Level */
mmi_bpp_xhtml_rsp_enum app_config_table_css(mmi_bpp_xhtml_table_css_struct* tab_css);
mmi_bpp_xhtml_rsp_enum app_config_style_class(mmi_bpp_xhtml_style_class_struct* obj_css);

/* XHTML Content Level */
/* start function */
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_file_start(void);
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_table_element_start(kal_uint8* caption, kal_uint8 cap_len);    //utf-8(ascii) encoded
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_row_element_start(void);
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_start(void);

/* compose function */
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_from_file(mmi_bpp_xhtml_data_element_struct* data);
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_from_buff(mmi_bpp_xhtml_data_element_struct* data);
void bpp_compose_xhtml_data_resume_hdlr(void* msg);

/* end function */
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_file_end(void);
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_table_element_end(void);
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_row_element_end(void);
mmi_bpp_xhtml_rsp_enum app_compose_xhtml_data_element_end(void);

/* cancel function*/
void bpp_cancel_xhtml_composing(void);
void app_compose_xhtml_file_failed(void);

#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */
#endif /* __BT_MMI_BPP_XHTML_GPROT_H__ */ 
