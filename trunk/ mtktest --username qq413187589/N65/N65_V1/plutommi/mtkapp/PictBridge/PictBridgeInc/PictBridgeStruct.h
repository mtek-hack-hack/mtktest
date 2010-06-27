/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeStruct.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __PICT_BRIDGE_STRUCT_H__
#define __PICT_BRIDGE_STRUCT_H__

#ifdef __MMI_PICT_BRIDGE_SUPPORT__

#include "FileMgr.h"

#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
#include "XML_def.h"
#endif

typedef struct
{
    S8 *xml_operation_cmd;
    S8 *xml_event_cmd;

    U32 xml_operation_cmd_size;
    U32 xml_event_cmd_size;
    U32 xml_start_job_cmd_size; /* special size for start job command */

    U8 xml_capability_index;
    U8 xml_layout_index;

    U8 dps_status; /* 0: idle, 1: busy */
    U8 printing; /* 0: not, 1: printing now, 2: error */
    U16 error_string_id;

    S32 image_width;
    S32 image_height;

    FuncPtr next_operation_request;
    FuncPtr next_event_request;

#ifdef __DRM_SUPPORT__
    FS_DOSDirEntry printing_file_info;
#endif

    U8 printing_capability[10]; /* IOT: HP cannot support all capabilities, 0: supported, 1: not */
    U8 printing_percentage[32 * ENCODING_LENGTH]; /* with null terminator */
    U8 printing_filepath[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH]; /* with null terminator */

#ifndef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    U8 printing_filedate[(PICT_MAX_DATE_LEN + 1) * ENCODING_LENGTH]; /* 2007/12/25 */
#ifdef __DRM_SUPPORT__
    U8 drm_consume_cnt;
#endif 
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    U8 *multi_file_value; /* on/off buffer for category */
    U8 *multi_file_cache; /* image decode buffer for category */
    U8  multi_file_select; /* selected image number */
    U16 multi_file_index;
    U32 multi_file_total;
#ifdef __FS_SORT_SUPPORT__
    U16 multi_file_sort;
    U8  multi_file_xreset;
#endif /* __FS_SORT_SUPPORT__ */
    U8  multi_file_path[PICT_MAX_MULTI_FILES][(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    U8  multi_file_date[PICT_MAX_MULTI_FILES][11 * ENCODING_LENGTH];
    U32 multi_file_size[PICT_MAX_MULTI_FILES];
#ifdef __DRM_SUPPORT__
    U8 multi_file_consume[PICT_MAX_MULTI_FILES];
#endif 
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#ifndef __MTK_TARGET__
    U8 xml_modis_buffer[20480];
#endif
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
   XML_PARSER_STRUCT *parser;
#endif
} pict_bridge_context_struct;


typedef struct
{
    U32 xml_result;
    U8 xml_cmd;
    U8 xml_attr;

/* configurePrintService */
    /* ignore vendorName, vendorSpecificVersion, and serialNo*/
    pBOOL service_available;
    S8 dps_version[PICT_MAX_DPS_VERSION_LEN + 1];   /* 1.0 + NULL */
    S8 product_name[PICT_MAX_PRODUCT_NAME_LEN + 1]; /* 31 words + NULL */

/* getCapability */
    U8 qualities;
    U8 paper_sizes;
    U8 file_types;
    U8 date_prints;
    U8 filename_prints;
    U8 image_optimizes;
    U8 croppings;
    U8 paper_types[PICT_PAPER_MAX]; /* default, postcard, 4x6, letter, A4 */
    U8 layouts[PICT_PAPER_MAX];     /* default, postcard, 4x6, letter, A4 */

/* notifyDeviceStatus */
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    U32 nds_service_status;
    U32 nds_error_status;
    U32 nds_error_reason;
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
} pict_bridge_xml_struct;


typedef struct
{
    S32 paper_size;
    S32 number_of_copies;
    S32 page_format;
    S32 layout;
    S32 border;
    S32 date_print;
    S32 filename_print;
    S32 cropping;
    S32 fixed_size;

    S32 x_coordinate;
    S32 y_coordinate;
    S32 x_arix;
    S32 y_arix;
    U8 x_coordinate_display[(PICT_MAX_IMAGE_LEN + 1) * ENCODING_LENGTH];
    U8 y_coordinate_display[(PICT_MAX_IMAGE_LEN + 1) * ENCODING_LENGTH];
    U8 x_arix_display[(PICT_MAX_IMAGE_LEN + 1) * ENCODING_LENGTH];
    U8 y_arix_display[(PICT_MAX_IMAGE_LEN + 1) * ENCODING_LENGTH];

    U8 *paper_list[PICT_PAPER_MAX]; /* default, postcard, 4x6, letter, A4 */
    U8 *copies_list[10];             /* 1 ~ 10 */
    U8 *format_list[3];             /* standard, multiple, index */
#ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
    U8 *layout_list[4];             /* 1, 2, 4, All */
#else
    U8 *layout_list[4];             /* 1, 2, 4 */
#endif
    U8 *border_list[3];             /* default, on, off */
    U8 *date_list[3];               /* default, on, off */
    U8 *filename_list[3];           /* default, on, off */
    U8 *fixed_list[1];              /* disable */
    U8 *cropping_list[3];           /* default, on, off */
} pict_bridge_setting_struct;


#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

#endif /* __PICT_BRIDGE_STRUCT_H__ */

