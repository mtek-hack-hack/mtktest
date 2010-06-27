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
 * BTMMIBppXhtml.h
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

#ifndef __BT_MMI_BPP_XHTML_H__
#define __BT_MMI_BPP_XHTML_H__

#ifndef __MMI_FEATURES__
#error "MMI_features.h should be included"
#endif 

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BPP_SUPPORT__)

/*****************************************************************
    Define
*****************************************************************/
#define CHK                     ("\r\nCHK ")
#define CHK_MORE                ("MORE\r\n")
#define CHK_LAST                ("LAST\r\n")
#define XHTML_HEAD_START        ("<head>\r\n")
#define XHTML_TITLE             ("<title>MTK BPP</title>\r\n")
#define XHTML_HEAD_END          ("</head>\r\n\r\n")
#define XHTML_STYLE_START       ("<style type=\"text/css\">\r\n")
#define XHTML_STYLE_END         ("</style>\r\n")
#define XHTML_CENTER_START      ("<div align=\"center\">\r\n")
#define XHTML_CENTER_END        ("</div><br/>\r\n")
#define XHTML_BODY_START        ("<body>\r\n")
#define XHTML_BODY_END          ("</body>\r\n")
#define XHTML_CAPTION_START     ("<caption>")
#define XHTML_CAPTION_END       ("</caption>\r\n")
#define XHTML_ROW_START         ("<tr>\r\n")
#define XHTML_ROW_END           ("</tr>\r\n")
#define XHTML_CELL_END          ("</td>\r\n")
#define XHTML_DIV_START         ("<div")
#define XHTML_DIV_END           ("</div>")
#define XHTML_TABLE_START       ("<table>\r\n")
#define XHTML_TABLE_END         ("</table>\r\n")
#define XHTML_FILE_END          ("</html>\r\n\r\nCHK 0 0 LAST\r\n")
#define XHTML_PAGE_STYLE_A4     ("@page { size: 210mm 277mm; counter-increment: page; margin-left: 12mm; margin-top: 15mm; margin-bottom: 10mm;\r\n")
#define XHTML_PAGE_STYLE_US     ("@page { size: 8.5in 10.2in; counter-increment: page; margin-left: 12mm; margin-top: 15mm; margin-bottom: 10mm;\r\n")
#define XHTML_PAGE_STYLE_4X6    ("@page { size: 4in 6in; counter-increment: page;\r\n")
#define XHTML_PAGE_STYLE_END    ("@bottom { text-align: center; vertical-align: bottom; content: counter(page); }\r\n}\r\n")
#define XHTML_STYLE_COMMON  ("table { border-collapse: collapse; border-spacing: 0pt; }\r\n")
#define XHTML_STYLE_CENTER  ("div.center { text-align: center; }\r\n")
#define XHTML_DOC_TYPE_HDR  ("Content-Type: application/vnd.pwg-multiplexed; type=application/vnd.pwg-xhtml-print+xml\r\n")
#define XHTML_DOC_BODY_HDR  ("Content-Type: application/vnd.pwg-xhtml-print+xml\r\nContent-Location: bpp.xhtml\
\r\n\r\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
\r\n<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML-Print 1.0//EN\"\
\r\n\"http://www.w3.org/MarkUp/DTD/xhtml-print10.dtd\">\
\r\n<html xmlns=\"http://www.w3.org/1999/xhtml\">\r\n\r\n")
#define TEXT_ALIGN          ("text-align: ")
#define VERTICAL_ALIGN      ("vertical-align: ")
#define ALIGN_BOTTOM        ("bottom; ")
#define ALIGN_TOP           ("top; ")
#define ALIGN_LEFT          ("left; ")
#define ALIGN_RIGHT         ("right; ")
#define ALIGN_MIDDLE        ("middle; ")
#define ALIGN_CENTER        ("center; ")
#define BRACE               ("}\r\n")
#define CONTENT_TYPE        ("Content-Type: ")
#define CONTENT_LOCATION    ("Content-Location: ")
#define CLASS_ATTR          (" class=\"")
#define COL_SPAN_ATTR       (" colspan=\"")
#define ROW_SPAN_ATTR       (" rowspan=\"")
#define IMAGE_JPEG_TYPE     ("image/jpeg\r\n")
#define IMAGE_GIF_TYPE      ("image/gif\r\n")
#define IMAGE_BMP_TYPE      ("image/bmp\r\n")
#define IMAGE_WBMP_TYPE     ("image/vnd.wap.wbmp\r\n")
#define IMAGE_PNG_TYPE      ("image/png\r\n")
#define IMAGE_SVG_TYPE      ("image/svg+xml\r\n")
#define IMAGE_START         ("<img")
#define IMAGE_SRC_START     (" src=\"bpp/inline_image")
#define IMAGE_SRC_EXT_JPG   (".jpg")
#define IMAGE_SRC_EXT_GIF   (".gif")
#define IMAGE_SRC_EXT_BMP   (".bmp")
#define IMAGE_SRC_EXT_WBMP   (".wbmp")
#define IMAGE_SRC_EXT_PNG   (".png")
#define IMAGE_SRC_EXT_SVG   (".svg")
#define IMAGE_SRC_END       ("\"/>")

#define XHTML_WRITE_THRSHOLD    (2048)  
#define XHTML_MAX_CSS_SIZE      (300)

/*****************************************************************
    Enum
*****************************************************************/
typedef enum
{
    MMI_BPP_XHTML_TD_STATUS_NONE,
    MMI_BPP_XHTML_TD_STATUS_COMPOSING,
    MMI_BPP_XHTML_TD_STATUS_TOTAL
} mmi_bpp_xhtml_td_status_enum;

typedef enum
{
    MMI_BPP_XHTML_DATA_ATTR_DIV,
    MMI_BPP_XHTML_DATA_ATTR_NEW,
    MMI_BPP_XHTML_DATA_ATTR_TOTAL
} mmi_bpp_xhtml_data_attr_enum;

typedef enum
{
    MMI_BPP_XHTML_CHK_MORE,
    MMI_BPP_XHTML_CHK_LAST,
    MMI_BPP_XHTML_CHK_TOTAL
} mmi_bpp_xhtml_chk_enum;

/*****************************************************************
    Structure
*****************************************************************/
typedef struct
{
    FS_HANDLE                       xhtml_file;         //document file
    U32                             buf_tmp_len;        //write buffer length
    void*                           tmp_buff;           //write buffer
    U32                             remain_file_size;   //remain file length of data element
    FS_HANDLE                       tmp_file;           //file handle of data element
    void*                           tmp_data;           //data pointer of data element
    ap_callback                     app_callback;       //application callback function
    U8                              chk_count;          //chunk number
    U8                              cur_msg;            //current message id
    U32                             cur_offset;         //current message offset
    mmi_bpp_xhtml_media_enum        media;              //page type
    mmi_bpp_xhtml_td_status_enum    status;             //td status    
    MMI_BOOL                        div_flag;           //div flag
    MMI_BOOL                        cancel_flag;        //cancel flag
} mmi_bpp_xhtml_cntx_struct;


/*****************************************************************
    Global Function
*****************************************************************/


#endif /* defined(__MMI_BPP_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */
#endif /* __BT_MMI_BPP_XHTML_H__ */ 
