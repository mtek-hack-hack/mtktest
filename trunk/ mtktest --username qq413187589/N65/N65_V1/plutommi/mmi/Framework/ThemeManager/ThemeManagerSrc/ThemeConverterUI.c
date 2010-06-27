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
 *   ThemeConverterUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Contains function fort he filling of the MMI_theme structure
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "GlobalDefs.h"
#include "FrameworkGprot.h"         
#include "FrameworkProt.h"   
#include "Fat_fs.h"
#include "SettingProfile.h"
#include "gui_data_types.h"
#include "PixcomFontEngine.h"
#include "CustThemesRes.h"
#include "xml_def.h"
#include "MainMenuDef.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

/* set default value to local buffer or not */
//#define DLT_DEFAULT_VALUE_SUPPORT

/****************************************************************************
MMI theme structure filled using the Downloaded theme file 
*****************************************************************************/
MMI_theme g_tc_theme_DLT;
MMI_theme *g_tc_theme_converter_p = &g_tc_theme_DLT;

extern MMI_theme **MMI_themes;
extern XML_PARSER_STRUCT g_tc_parser;

/* ... Add More MMI header */

extern U16 g_tm_checkThemeVersion;
U8 g_tc_audiothmfileformat; /* ritesh */

/*************************************************************/

/* Theme Versioning Structures */

tc_deviceinfo_struct g_tc_deviceInfo;
tc_theme_download_info_struct g_tc_themeInfo;

/*****************************************************************************
 * FUNCTION
 *  mmi_tc_ascii_to_hex_convert
 * DESCRIPTION
 *  (S8  character)
 *  converts a given character from ascii to hex value
 * PARAMETERS
 *  character       [IN]        Value
 * RETURNS
 *  hex equivalent of the ascii character
 *****************************************************************************/
U8 mmi_tc_ascii_to_hex_convert(S8 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (character > 47 && character < 58)   /* Digits 0..9 */
    {
        return (character - 48);
    }
    else if (character > 64 && character < 71)  /* Characters A..F */
    {
        return (character - 55);
    }
    else if (character > 96 && character < 103) /* Characters a..f */
    {
        return (character - 87);
    }
    else
    {
        return (0xFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_convert_ascii_hex_to_dec
 * DESCRIPTION
 *  Converts Ascii value to Decimal value
 * PARAMETERS
 *  character       [IN]        Ascii value
 * RETURNS
 *  decimal equivalent of the ascii character
 *****************************************************************************/
U8 mmi_tc_convert_ascii_hex_to_dec(S8 character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (character > 47 && character < 58)   /* Digits 0..9 */
    {
        return (character - 48);
    }
    else if (character > 64 && character < 71)  /* Characters A..F */
    {
        return (character - 55);
    }
    else if (character > 96 && character < 103) /* Characters a..f */
    {
        return (character - 87);
    }
    else
    {
        return (0xFF);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_extract_no_of_bits
 * DESCRIPTION
 *  (U8  *Data,U16  Offset, U16  Bits)
 *  This function extracts given no of bits form the string provided
 * PARAMETERS
 *  Data_p      [?]         
 *  Offset      [IN]        
 *  Bits        [IN]        
 *  character(?)
 * RETURNS
 *  extracted number of bits
 *****************************************************************************/
U8 mmi_tc_extract_no_of_bits(U8 *Data_p, U16 Offset, U16 Bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 BITSPERVAL = 4;
    U8 ClearBits[] = {0x0, 0x1, 0x3, 0x7, 0xf};
    U8 val1 = 0;
    U8 val2 = 0;
    U8 returnval = 0;
    U16 index = Offset / BITSPERVAL;
    U8 BitsfromFirstIndex = BITSPERVAL - (Offset % BITSPERVAL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Bits > 2 * BITSPERVAL)
    {
        return 0;
    }

    val1 = mmi_tc_ascii_to_hex_convert(Data_p[index]);
    val1 &= ClearBits[BitsfromFirstIndex];

    if (BitsfromFirstIndex < Bits)
    {
        /* Do nothing  */
    }
    else if (BitsfromFirstIndex == Bits)
    {
        return val1;
    }
    else    /* (BitsfromFirstIndex > Bits) */
    {
        return (val1 >> (BitsfromFirstIndex - Bits));
    }

    val2 = mmi_tc_convert_ascii_hex_to_dec(Data_p[index + 1]);
    returnval = val1 << BITSPERVAL | val2;

    if ((BitsfromFirstIndex + BITSPERVAL) >= Bits)
    {
        returnval >>= (BITSPERVAL - Bits + BitsfromFirstIndex);
    }
    else
    {
        returnval <<= (Bits - BitsfromFirstIndex - BITSPERVAL);
        val1 = mmi_tc_convert_ascii_hex_to_dec(Data_p[index + 2]);
        val1 >>= ((2 * BITSPERVAL) + BitsfromFirstIndex - Bits);
        returnval |= val1;
    }

    return returnval;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_tones_list_tag_handler
 * DESCRIPTION
 *  (U8** attr_p)
 *  Function for handling the downloaded audio file
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_tones_list_tag_handler(U8 **attr_p, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 attrCount = 0;
    char audio_file_name[25];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strncmp((PS8) attr_p[attrCount], "name", strlen("name")))
    {
        /* if(!strncmp((PS8)attr_p[attrCount+1],"inc_call",strlen("inc_call")))
           { */
        U32 offset = 0, size = 0;

        strcpy(audio_file_name, (PS8) attr_p[attrCount + 1]);
        offset = (U32) atoi((PS8) attr_p[attrCount + 3]);
        size = (U32) atoi((PS8) attr_p[attrCount + 5]);

        if ((strstr(audio_file_name, ".wav") != NULL) || (strstr(audio_file_name, ".WAV") != NULL))
        {
            g_tc_audiothmfileformat = THEME_AUDIO;
        }
        else if ((strstr(audio_file_name, ".mid") != NULL) || (strstr(audio_file_name, ".MID") != NULL))
        {
            g_tc_audiothmfileformat = THEME_MIDI;
        }
        else if ((strstr(audio_file_name, ".mp3") != NULL) || (strstr(audio_file_name, ".MP3") != NULL))
        {
            g_tc_audiothmfileformat = THEME_MP3;
        }
        mmi_tm_handle_audio(offset, size);
        /* } */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_deviceinfo_tag_handler
 * DESCRIPTION
 *  (U8** attr_p)
 *  Gives the information about the device structurewhich is downloading the theme
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_check_theme_file_lcd_dimension_compatibiltiy(U32 lcd_width, U32 lcd_height);

void mmi_tc_deviceinfo_tag_handler(U8 **attr_p, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 attrCount = 0;

    U8 nmodel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_tc_deviceInfo.model_ID, 0, sizeof(g_tc_deviceInfo.model_ID));
    while (attr_p[attrCount])
    {
        if (!strncmp((PS8) attr_p[attrCount], "model_ID", strlen("model_ID")))
        {
            if (nmodel < MAX_PHONE_MODELS)
            {
                strncpy((PS8) g_tc_deviceInfo.model_ID[nmodel], (PS8) attr_p[attrCount + 1], MAX_MODEL_ID_LEN);
                ++nmodel;
            }
        }
        if (!strncmp((PS8) attr_p[attrCount], "am", strlen("am")))
        {
            if (nmodel < MAX_PHONE_MODELS)
            {
                strncpy((PS8) g_tc_deviceInfo.model_ID[nmodel], (PS8) attr_p[attrCount + 1], MAX_MODEL_ID_LEN);
                ++nmodel;
            }
        }
        if (!strncmp((PS8) attr_p[attrCount], "lcdwidth", strlen("lcdwidth")))
        {
            g_tc_deviceInfo.lcdwidth = (U32) atoi((PS8) attr_p[attrCount + 1]);

        }
        if (!strncmp((PS8) attr_p[attrCount], "lcdht", strlen("lcdht")))
        {
            g_tc_deviceInfo.lcdht = (U32) atoi((PS8) attr_p[attrCount + 1]);
        }
        attrCount += 2;
    }
}


extern U16 mmi_check_theme_file_version_compatibility(FLOAT theme_version);


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_device_theme_ver_info
 * DESCRIPTION
 *  (U8** attr_p)
 *  fill the MMI theme structure for device_theme
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_device_theme_ver_info(U8 **attr_p, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 attrCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (attr_p[attrCount])
    {
        if (!strncmp((PS8) attr_p[attrCount], "name", strlen("name")))
        {
            g_tc_themeInfo.name_p = attr_p[attrCount + 1];
        }
        if (!strncmp((PS8) attr_p[attrCount], "version", strlen("version")))
        {
            g_tc_themeInfo.version = (FLOAT) atoi((PS8) attr_p[attrCount + 1]);
        }
        attrCount += 2;
    }

    if (g_tm_checkThemeVersion)
    {
        xml_free_parse(&g_tc_parser);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_color_converter
 * DESCRIPTION
 *  convert color type
 * PARAMETERS
 *  color_ptr   [OUT]   converted color data
 *  data_ptr    [IN]    raw data
 * RETURNS
 *  void
 *****************************************************************************/
__inline void mmi_tc_color_converter(color *color_ptr, U8 *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(color_ptr != NULL);
    color_ptr->r        = mmi_tc_extract_no_of_bits(data_ptr, 0, 8);
    color_ptr->g        = mmi_tc_extract_no_of_bits(data_ptr, 8, 8);
    color_ptr->b        = mmi_tc_extract_no_of_bits(data_ptr, 16, 8);
    color_ptr->alpha    = mmi_tc_extract_no_of_bits(data_ptr, 24, 8);
} 
 

/*****************************************************************************
 * FUNCTION
 *  mmi_tc_font_converter
 * DESCRIPTION
 *  convert font type
 * PARAMETERS
 *  font        [OUT]   converted font data
 *  data_ptr    [IN]    raw data
 * RETURNS
 *  void
 *****************************************************************************/
__inline void mmi_tc_font_converter(UI_font_type font, U8 *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(font != NULL);
    font->bold      = mmi_tc_extract_no_of_bits(data_ptr, 0, 4);
    font->italic    = mmi_tc_extract_no_of_bits(data_ptr, 4, 4);
    font->underline = mmi_tc_extract_no_of_bits(data_ptr, 8, 4);
    font->size      = mmi_tc_extract_no_of_bits(data_ptr, 12, 4);
    font->color     = mmi_tc_extract_no_of_bits(data_ptr, 16, 4);
    font->type      = mmi_tc_extract_no_of_bits(data_ptr, 20, 4);
    font->oblique   = mmi_tc_extract_no_of_bits(data_ptr, 24, 4);
    font->smallCaps = mmi_tc_extract_no_of_bits(data_ptr, 28, 4);
}


#ifdef DLT_DEFAULT_VALUE_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_tc_init_local_buffer
 * DESCRIPTION
 *  initializa local buffer from given source pointer
 * PARAMETERS
 *  local_ptr   [IN]    data pointer to local buffer
 *  src_ptr     [IN]    data pointer to source
 *  size        [IN]    local buffer size
 * RETURNS
 *  void
 *****************************************************************************/
__inline void mmi_tc_init_local_buffer(void *local_ptr, void *src_ptr, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    MMI_ASSERT(local_ptr != NULL);

    /* initializa only when source and local ptr are diff. and size isn't 0 */
    if (size && (src_ptr != local_ptr))
    {
        /* only do initialization if source ptr isn't NULL */
        if (src_ptr != NULL)
        {
            memcpy(local_ptr, src_ptr, size);
        }
    } 
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_color_tag_handler
 * DESCRIPTION
 *  color tag handler
 * PARAMETERS
 *  attr_p      [IN]    attribute name
 *  arg         [IN]    pointer to tag info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_color_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tc_all_tags_index_struct *tag_info = (tc_all_tags_index_struct*)arg;
    color **dlt_ptr = (color **)tag_info->info1;
    color *buff_ptr = (color *)tag_info->info2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dlt_ptr != NULL);

    if (!strcmp((PS8) attr_p[0], "value"))
    {
        mmi_tc_color_converter(buff_ptr, attr_p[1]);
    }
    else
    {
        /* attribute type not supported */
        MMI_ASSERT("attribute type not supported" && 0);
    }

    /* update DLT data */
    *dlt_ptr = buff_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_filler_tag_handler
 * DESCRIPTION
 *  filler tag handler
 * PARAMETERS
 *  attr_p      [IN]    attribute name
 *  arg         [IN]    pointer to tag info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_filler_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 attrCount = 0;
    PS8 attr_name;
    U8 *data_ptr = NULL;
    tm_image_load_type_enum image_load_type = THEME_IMG_LOAD_END;
    tc_all_tags_index_struct *tag_info = (tc_all_tags_index_struct*)arg;
    UI_filled_area **dlt_ptr = (UI_filled_area **)tag_info->info1;
    UI_filled_area *buff_ptr = (UI_filled_area *)tag_info->info2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(dlt_ptr != NULL);

#ifdef DLT_DEFAULT_VALUE_SUPPORT
    /* initialize local buffer first */
    mmi_tc_init_local_buffer((void *)buff_ptr, (void *)*dlt_ptr, sizeof(UI_filled_area));
#endif

    while ((attr_name = (PS8)attr_p[attrCount]) != 0)
    {
        data_ptr = attr_p[attrCount + 1];

        if (!strcmp(attr_name, "c"))
        {
            mmi_tc_color_converter(&buff_ptr->c, data_ptr);
        }
        else if (!strcmp(attr_name, "flags"))
        {
            buff_ptr->flags = atoi((PS8)data_ptr);
        }
        else if (!strcmp(attr_name, "border_color"))
        {
            mmi_tc_color_converter(&buff_ptr->border_color, data_ptr);
        }
        else if (!strcmp(attr_name, "b"))
        {
            /* before set image, the load-type should be set */
            MMI_ASSERT(image_load_type < THEME_IMG_LOAD_END);
            buff_ptr->b = mmi_tm_create_non_imageid_image((U32) atoi((PS8)data_ptr), image_load_type);
        }
        else if (!strcmp(attr_name, "img_load_type"))
        {
            image_load_type = atoi((PS8)data_ptr);
        }
        else
        {
            /* attribute name not supported */
            MMI_ASSERT("attr. name not supported!" && 0);
        }

        attrCount += 2;
    }    

    /* update DLT data */
    *dlt_ptr = buff_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_font_tag_handler
 * DESCRIPTION
 *  font tag handler
 * PARAMETERS
 *  attr_p      [IN]    attribute name
 *  arg         [IN]    pointer to tag info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_font_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tc_all_tags_index_struct *tag_info = (tc_all_tags_index_struct*)arg;
    UI_font_type *dlt_ptr = (UI_font_type *)tag_info->info1;
    UI_font_type buff_ptr = (UI_font_type)tag_info->info2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dlt_ptr != NULL);

    if (!strcmp((PS8) attr_p[0], "value"))
    {
        mmi_tc_font_converter(buff_ptr, attr_p[1]);
    }
    else
    {
        /* attribute type not supported */
        MMI_ASSERT("attribute type not supported" && 0);
    }

    /* update DLT data */
    *dlt_ptr = buff_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_s32_tag_handler
 * DESCRIPTION
 *  S32 type tag handler
 * PARAMETERS
 *  attr_p      [IN]    attribute name
 *  arg         [IN]    pointer to tag info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_s32_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tc_all_tags_index_struct *tag_info = (tc_all_tags_index_struct*)arg;
    S32 *dlt_ptr = (S32 *)tag_info->info1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dlt_ptr != NULL);

    if (!strcmp((PS8) attr_p[0], "value"))
    {
        /* update DLT data */
        *dlt_ptr = (S32) atoi((PS8)attr_p[1]);
    }
    else
    {
        /* attribute type not supported */
        MMI_ASSERT("attribute type not supported" && 0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_pu8_tag_handler
 * DESCRIPTION
 *  PU8 type tag handler
 * PARAMETERS
 *  attr_p      [IN]    attribute name
 *  arg         [IN]    pointer to tag info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_pu8_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 attrCount = 0;
    PS8 attr_name;
    U8 *data_ptr = NULL;
    tm_image_load_type_enum image_load_type = THEME_IMG_LOAD_END;
    tc_all_tags_index_struct *tag_info = (tc_all_tags_index_struct*)arg;
    PU8 *dlt_ptr = (PU8 *)tag_info->info1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dlt_ptr != NULL);

    while ((attr_name = (PS8)attr_p[attrCount]) != 0)
    {
        data_ptr = attr_p[attrCount+1];

        if (!strcmp(attr_name, "b"))
        {
            /* before set image, the load-type should be set */
            MMI_ASSERT(image_load_type < THEME_IMG_LOAD_END);

            /* update DLT data */
            *dlt_ptr = mmi_tm_create_non_imageid_image((U32) atoi((PS8)data_ptr), image_load_type);
        }
        else if (!strcmp(attr_name, "img_load_type"))
        {
            image_load_type = atoi((PS8)data_ptr);
        }
        else
        {
            /* attribute type not supported */
            MMI_ASSERT("attribute type not supported" && 0);
        }

        attrCount += 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_generic_dummy_handler
 * DESCRIPTION
 *  dummy tag handler
 * PARAMETERS
 *  attr_p      [IN]    attribute name
 *  para        [IN]    pointer to tag info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_generic_dummy_handler(U8 **attr_p, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_convert_theme_file_to_mmi_theme
 * DESCRIPTION
 *  (MMI_theme** theme, U32 file_handle)
 *  fills the MMI theme structure by parsing the downloaded theme file
 * PARAMETERS
 *  theme           [IN]        
 *  file_handle     [IN]        
 * RETURNS
 *  true if successfully converted otherwise false
 *****************************************************************************/
extern const theme_details_struct mtk_MMI_themes[];

BOOL mmi_tc_convert_theme_file_to_mmi_theme(MMI_theme **theme, U32 file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Initialize local MMI_theme structure */
#ifdef __MMI_THEMES_V2_SUPPORT__
    memcpy(g_tc_theme_converter_p, mtk_MMI_themes[0].theme, sizeof(MMI_theme));
#else
    memcpy(g_tc_theme_converter_p, mtk_MMI_themes[0], sizeof(MMI_theme));
#endif

    if (xml_new_parser(&g_tc_parser) == -1)
    {
        return FALSE;
    }
    xml_register_element_handler(&g_tc_parser, mmi_tc_my_xml_elem_start_hdlr, mmi_tc_my_xml_elem_end_hdlr);
    g_tc_parser.pos = THEME_FILE_SIZE_HEADER + THEME_CHECKSUM_HEADER_SIZE;

    xml_parse_file_from_offset(&g_tc_parser, file_handle);
    xml_close_parser_offset(&g_tc_parser);

    *theme = &g_tc_theme_DLT;
    return TRUE;
}

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* MMI theme downloadable support */

