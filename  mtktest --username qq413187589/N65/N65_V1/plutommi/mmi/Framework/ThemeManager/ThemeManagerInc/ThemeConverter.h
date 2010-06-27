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
 *   ThemeConverter.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Header file for the ThemeConverter of DLT project
 *
 * Author:
 * -------
 * -------
 * -------
 *   
 *==============================================================================
 *             HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/* if some header should be include before this one */

#include "gui_data_types.h"
#include "MMIDataType.h"
#include "CustThemesRes.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/***************************************************************************** 
* Define of Vikas

*****************************************************************************/
#define MAX_MODEL_ID_LEN 20
#define MAX_PHONE_MODELS 10

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef void (*xml_tag_handler_hdlr) (U8 **, void *);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#define DLT_PTR(x)      (&(g_tc_theme_DLT.x))
extern MMI_theme g_tc_theme_DLT;

/**************  flash tables   ****************/
/* We wll form table containing the all tags and their corresponding function pointers */
typedef struct
{
    PS8 xml_tag;
    xml_tag_handler_hdlr tag_handler;
    void *info1;
    void *info2;
} tc_all_tags_index_struct;

/* The table for the image tag and all the image attributes is defined below */
typedef struct
{
    PS8 image_tag;
    U16 imageId;
} tc_image_tags_index_struct;

/* The Table for the searching for getting the required image ID */
typedef struct
{
    U8 index;
    U8 no_of_elements;
} tc_search_image_all_tags_struct;

/* Table for the Deviceinfo */
typedef struct
{
    U8 model_ID[MAX_PHONE_MODELS][MAX_MODEL_ID_LEN];
    U32 lcdwidth;
    U32 lcdht;
} tc_deviceinfo_struct;

typedef struct
{
    U8 *name_p;
    FLOAT version;
} tc_theme_download_info_struct;

/*************** end of flash tables ********************/

/***********  Context structure **************************/
extern void mmi_tc_theme_imageid_image_handler(U16 imageid, U32 image_offset);
extern PU8 mmi_tc_theme_non_imageid_image_handler(U32 image_offset);
extern void mmi_tc_play_audio_funcptr(U32 audio_offset);

/******** end of the context structure   ***************/

/*********  function prototypes ***************/
extern BOOL mmi_tc_convert_theme_file_to_mmi_theme(MMI_theme **theme_p, U32 file_handle);

extern void mmi_tc_generic_dummy_handler(U8 **attr_p, void *para);

/* common tag handler */
extern void mmi_tc_color_tag_handler(U8 **, void *);
extern void mmi_tc_filler_tag_handler(U8 **, void *);
extern void mmi_tc_font_tag_handler(U8 **, void *);
extern void mmi_tc_s32_tag_handler(U8 **, void *);
extern void mmi_tc_pu8_tag_handler(U8 **, void *);

/* specific tag handler */
extern void mmi_tc_image_list_tag_handler(U8 **, void *);
extern void mmi_tc_tones_list_tag_handler(U8 **, void *);
extern void mmi_tc_deviceinfo_tag_handler(U8 **, void *);
extern void mmi_tc_device_theme_ver_info(U8 **, void *);

extern U8 mmi_tc_extract_no_of_bits(U8 *Data_p, U16 Offset, U16 Bits);
extern U8 mmi_tc_ascii_to_hex_convert(S8 character);
extern void mmi_tc_my_xml_elem_end_hdlr(void *data_p, const char *el_p, S32 err_code);
extern void mmi_tc_my_xml_elem_start_hdlr(void *data_p, const char *el_p, const char **attr_p, S32 err_code);

/*********  end of function prototypes ***************/

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

