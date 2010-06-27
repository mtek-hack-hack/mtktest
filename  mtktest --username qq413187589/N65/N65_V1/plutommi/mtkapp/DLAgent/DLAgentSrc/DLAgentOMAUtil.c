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
 *
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "MMI_include.h"

#if defined (__MMI_OMA_DD_DOWNLOAD__)

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"
#include "FileMgr.h"
#include "drm_def.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"
#include "DLAgentWPS.h"
#include "DLAgentOMA.h"
#include "XML_def.h"

#include "Conversions.h"
#include "FileManagerDef.h"             /*FMGR_FS_ACCESS_DENIED_TEXT*/
#include "FileManagerGProt.h"

/****************************************************************************
* Define
*****************************************************************************/

#define DD_SHORT_STRING_LEN     40
#define DD_LONG_STRING_LEN      192
#define DD_VERYLONG_STRING_LEN  255
#define DD_URI_LEN              512
#define DD_INTEGER_LEN          32
#define DD_BOOLEAN_LEN          10      /* "true" or "false", 1 or 0 */
#define DD_DATETIME_LEN         30

/****************************************************************************
* Define - Macro
*****************************************************************************/

#define offsetof(type, mem) ((size_t) ((char*)&((type*)0)->mem - (char*)((type*)0)))

#define DD_IS_TAG(tagname, el)  (mime_stricmp((kal_char *)tagname, (kal_char *)el) == 0)

#define DD_FIND_ATTR(attrname, attrlist, idx) \
    idx = 0; \
    while(attrlist[idx]) \
    { \
        if (DD_IS_TAG(attrname, attrlist[i])) \
            break; \
        idx+=2; \
    } \

#define DD_CONVERT_STRING(value, len, target) \
    (target) = OslMalloc( (len + 1) * ENCODING_LENGTH ); \
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (S8*)value, (S8*)(target), (len + 1)*ENCODING_LENGTH)
    
/****************************************************************************
* Typedef - Enum
*****************************************************************************/

enum
{
    DD_PARSING_STATE_NONE = -1,
    DD_PARSING_STATE_MEDIA,

#ifdef __MMI_OMA_DD2_DOWNLOAD__
    DD2_PARSING_STATE_NONE = -1,
    DD2_PARSING_STATE_MEDIA,
    DD2_PARSING_STATE_VENDOR,
    DD2_PARSING_STATE_PRODUCT,
    DD2_PARSING_STATE_META,
    DD2_PARSING_STATE_MO,
    DD2_PARSING_STATE_RESERVE,
    DD2_PARSING_STATE_OBJ_URI,
#endif

    DD_PARSING_LEVEL_MAX = 12
};

enum
{
    DD_XSD_TYPE_SHORT_STRING,
    DD_XSD_TYPE_LONG_STRING,
    DD_XSD_TYPE_VERYLONG_STRING,
    DD_XSD_TYPE_URI,
    DD_XSD_TYPE_URI_UCS2,
    DD_XSD_TYPE_INTEGER,
    DD_XSD_TYPE_BOOLEAN,
    DD_XSD_TYPE_DATETIME,

    DD_XSD_TYPE_NUM
};

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef BOOL (*mmi_da_oma_dd_elem_handler)(const S8* value, S32 len, void* obj, U16 offset);

typedef struct
{
    S32 errorNo;
    UI_string_ID_type stringId;         /* for displaypopup */
    S8 *report_msg;                     /* for send report */
} mmi_da_oma_error_entry_struct;

typedef struct
{
    S8  *item;
    U16 type;
    U16 offset;
} dd_data_table_struct;

typedef struct
{
    S32                         max_len;
    mmi_da_oma_dd_elem_handler  func;
} dd_type_table_struct;

typedef struct
{
    BOOL                        dd_parse_busy;
    BOOL                        dd_parse_error;

    S8                          *dd_url_base;
    mmi_da_job_struct           *curr_job;

    mmi_da_oma_dd_struct        *dd_info;   // current parsing dd
    
#ifdef __MMI_OMA_DD2_DOWNLOAD__
    S32                         dd2_product_idx;
    S32                         dd2_mo_idx;
    mmi_da_oma_dd2_struct       *dd2_info;   // current parsing dd
    U8                          dd2_state_stack[DD_PARSING_LEVEL_MAX];
    S32                         dd2_state_level;
    S32                         dd2_skip;
#endif    
} mmi_da_omautil_context_struct;

/****************************************************************************
* Static Variable
*****************************************************************************/

static mmi_da_omautil_context_struct da_omautil_context = {0};

/* *FORMATTER-DISABLE* */
const static mmi_da_oma_error_entry_struct oma_error_tbl[]=
{
    {MMI_DA_OMA_INSUFFICIENT_MEM      ,STR_ID_DA_OMA_INSUFFICIENT_MEM_MSG,           "901 Insufficient Memory"    },
    {MMI_DA_OMA_USER_CANCELLED        ,STR_ID_DA_OMA_USER_CANCELLED_MSG,             "902 User Cancelled"         },
    {MMI_DA_OMA_LOSS_OF_SERVICE       ,STR_ID_DA_OMA_LOSS_OF_SERVICE_MSG,            "903 Loss of Service"        },
    {MMI_DA_OMA_ATTRIBUTE_MISMATCH    ,STR_ID_DA_OMA_ATTRIBUTE_MISMATCH_MSG,         "905 Attribute Mismatch"     },
    {MMI_DA_OMA_INVALID_DESCRIPTOR    ,STR_ID_DA_OMA_INVALID_DESCRIPTOR_MSG,         "906 Invalid descriptor"     },
    {MMI_DA_OMA_INVALID_DDVSERSION    ,STR_ID_DA_OMA_INVALID_DDVSERSION_MSG,         "951 Invalid DDVersion"      },
    {MMI_DA_OMA_DEVICE_ABORTED        ,STR_ID_DA_OMA_DEVICE_ABORTED_MSG,             "952 Device Aborted"         },
    {MMI_DA_OMA_NON_ACCEPTABLE_CONTENT,STR_ID_DA_OMA_NON_ACCEPTABLE_CONTENT_MSG,     "953 Non-Acceptable Content" },
    {MMI_DA_OMA_LOADER_ERROR          ,STR_ID_DA_OMA_LOADER_ERROR_MSG,               "954 Loader Error"           },
    {MMI_DA_OMA_AUTHORIZATION_FAIL    ,STR_ID_DA_OMA_AUTHORIZATION_FAILURE_MSG,      "952 Device Aborted"         },
    {MMI_DA_OMA_INSUFFICIENT_STORAGE  ,STR_ID_DA_OMA_INSUFFICIENT_STORAGE_MSG,       "901 Insufficient Memory"    },
    {MMI_DA_OMA_FILE_ACCESS_ERROR     ,FMGR_FS_ACCESS_DENIED_TEXT,                "952 Device Aborted"         },
    {MMI_DA_OMA_SUCCESS               ,STR_GLOBAL_DONE,                           "900 Success"                }
};

static BOOL _dd_extract_string(const S8* value, S32 len, void* obj, U16 offset);
static BOOL _dd_extract_url(const S8* value, S32 len, void* obj, U16 offset);
static BOOL _dd_extract_url_ucs2(const S8* value, S32 len, void* obj, U16 offset);
static BOOL _dd_extract_integer(const S8* value, S32 len, void* obj, U16 offset);
static BOOL _dd_extract_boolean(const S8* value, S32 len, void* obj, U16 offset);
static BOOL _dd_extract_datetime(const S8* value, S32 len, void* obj, U16 offset);

const static dd_type_table_struct dd_xsd_type_info_table[DD_XSD_TYPE_NUM] =
{
     {DD_SHORT_STRING_LEN,      _dd_extract_string}
    ,{DD_LONG_STRING_LEN,       _dd_extract_string}
    ,{DD_VERYLONG_STRING_LEN,   _dd_extract_string}
    ,{DD_URI_LEN,               _dd_extract_url}
    ,{DD_URI_LEN,               _dd_extract_url_ucs2}
    ,{DD_INTEGER_LEN,           _dd_extract_integer}
    ,{DD_BOOLEAN_LEN,           _dd_extract_boolean}
    ,{DD_DATETIME_LEN,          _dd_extract_datetime}
};

const static dd_data_table_struct dd_elem_media_table[]=
{
    {"type"             ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(mmi_da_oma_dd_struct, type)},
    {"objectURI"        ,DD_XSD_TYPE_URI            ,offsetof(mmi_da_oma_dd_struct, objectURI)},
    {"installNotifyURI" ,DD_XSD_TYPE_URI            ,offsetof(mmi_da_oma_dd_struct, installNotifyURI)},
    {"nextURL"          ,DD_XSD_TYPE_URI_UCS2       ,offsetof(mmi_da_oma_dd_struct, nextURL)},
    {"DDVersion"        ,DD_XSD_TYPE_INTEGER        ,offsetof(mmi_da_oma_dd_struct, DDVersion)},
    {"name"             ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(mmi_da_oma_dd_struct, name)},
    {"description"      ,DD_XSD_TYPE_LONG_STRING    ,offsetof(mmi_da_oma_dd_struct, description)},
    {"vendor"           ,DD_XSD_TYPE_SHORT_STRING   ,offsetof(mmi_da_oma_dd_struct, vendor)},
    {"infoURL"          ,DD_XSD_TYPE_URI            ,offsetof(mmi_da_oma_dd_struct, infoURL)},
    {"iconURI"          ,DD_XSD_TYPE_URI            ,offsetof(mmi_da_oma_dd_struct, iconURI)},
    {"installParam"     ,DD_XSD_TYPE_VERYLONG_STRING,offsetof(mmi_da_oma_dd_struct, installParam)},
    {"size"             ,DD_XSD_TYPE_INTEGER        ,offsetof(mmi_da_oma_dd_struct, size)},
    {NULL, 0, 0}
};

#ifdef __MMI_OMA_DD2_DOWNLOAD__
const static dd_data_table_struct dd2_complex_elem_table[]=
{
    {"media"                 ,DD2_PARSING_STATE_MEDIA    ,0},
    {"vendor"                ,DD2_PARSING_STATE_VENDOR   ,0},
    {"product"               ,DD2_PARSING_STATE_PRODUCT  ,0},
    {"meta"                  ,DD2_PARSING_STATE_META     ,0},
    {"mediaObject"           ,DD2_PARSING_STATE_MO       ,0},
    {"objectURI"             ,DD2_PARSING_STATE_OBJ_URI  ,0},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_vendor_table[]=
{
    {"name"                  ,DD_XSD_TYPE_LONG_STRING  ,offsetof(mmi_da_oma_dd2_struct, vendorName)},
    {"home"                  ,DD_XSD_TYPE_URI          ,offsetof(mmi_da_oma_dd2_struct, vendorHome)},
    {"logo"                  ,DD_XSD_TYPE_URI          ,offsetof(mmi_da_oma_dd2_struct, vendorLogo)},
    {"support"               ,DD_XSD_TYPE_URI          ,offsetof(mmi_da_oma_dd2_struct, vendorSupport)},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_meta_table[]=
{
    {"name"                  ,DD_XSD_TYPE_LONG_STRING      ,offsetof(mmi_da_oma_dd2_meta_struct, name)},
    {"description"           ,DD_XSD_TYPE_LONG_STRING      ,offsetof(mmi_da_oma_dd2_meta_struct, description)},
//    {"id"                    ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(mmi_da_oma_dd2_meta_struct, name)},
//    {"display"               ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(mmi_da_oma_dd2_meta_struct, name)},
    {"infoURL"               ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_meta_struct, infoURL)},
    {"media"                 ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_meta_struct, mediaURI)},
    {"installParam"          ,DD_XSD_TYPE_VERYLONG_STRING  ,offsetof(mmi_da_oma_dd2_meta_struct, installParam)},
    {"installNotifyURI"      ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_meta_struct, installNotifyURI)},
    {"downloadNotifyURI"     ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_meta_struct, downloadNotifyURI)},
    {"deleteNotifyURI"       ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_meta_struct, deleteNotifyURI)},
    {"suppressUserConfirmation",DD_XSD_TYPE_BOOLEAN        ,offsetof(mmi_da_oma_dd2_meta_struct, suppressUserConfirmation)},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_mo_table[]=
{
    {"size"                  ,DD_XSD_TYPE_INTEGER          ,offsetof(mmi_da_oma_dd2_mo_struct, size)},
    {"installSize"           ,DD_XSD_TYPE_INTEGER          ,offsetof(mmi_da_oma_dd2_mo_struct, installSize)},
    {"type"                  ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(mmi_da_oma_dd2_mo_struct, type)},
    {"objectID"              ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_mo_struct, objectId)},
    {"objectVersion"         ,DD_XSD_TYPE_SHORT_STRING     ,offsetof(mmi_da_oma_dd2_mo_struct, objectVersion)},
    {"progressiveDownloadFlag",DD_XSD_TYPE_BOOLEAN         ,offsetof(mmi_da_oma_dd2_mo_struct, progressiveDownloadflag)},
//    {"objectValidityTime"    ,DD_XSD_TYPE_DATETIME         ,offsetof(mmi_da_oma_dd2_mo_struct, xx)},
    {"server"                ,DD_XSD_TYPE_URI              ,offsetof(mmi_da_oma_dd2_mo_struct, objectURI)},
    {NULL, 0, 0}
};

const static dd_data_table_struct dd2_elem_media_table[]=
{
    {"nextURL"               ,DD_XSD_TYPE_URI_UCS2         ,offsetof(mmi_da_oma_dd2_struct, nextURL)},
    {NULL, 0, 0}
};
#endif

#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
extern BOOL mmi_ta_da_oma_install_check_hdlr(mmi_da_oma_dd_struct*);
#endif

const static mmi_da_oma_install_check_tbl_struct mmi_da_oma_install_check_tbl[] =
{
#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    {MIME_TYPE_APPLICATION,  MIME_SUBTYPE_THEME, mmi_ta_da_oma_install_check_hdlr},
#endif
    {MIME_TYPE_APPLICATION,  MIME_SUBTYPE_UNRECOGNIZED, NULL}
};
const static S32 mmi_da_oma_install_check_hdlr_num = sizeof(mmi_da_oma_install_check_tbl) / sizeof(mmi_da_oma_install_check_tbl_struct);
/* *FORMATTER-ENABLE* */

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Global Function
*****************************************************************************/

extern kal_int8 mime_stricmp(kal_char *src, kal_char *dest);
extern kal_uint8 mime_strnicmp(kal_char *src, kal_char *dest, kal_int32 maxlen);

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

#define END_OF_FUNCTION_DECLARATION

static BOOL _dd_extract_string(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 **string_pp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_pp = (S8**)((S8*)obj + offset);

    if(*string_pp)
        return FALSE;

    DD_CONVERT_STRING(value, len, *string_pp);
    return TRUE;
}

static BOOL _dd_extract_url(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 **string_pp;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_pp = (S8**)((S8*)obj + offset);

    if(*string_pp)
        return FALSE;

    if( mime_strnicmp( (kal_char*)value, "http://", 7) ==0 ||
        mime_strnicmp( (kal_char*)value, "http:\\\\", 7) ==0 )
    {
        /* Absolute URL */
        *string_pp = get_ctrl_buffer(len + 1);
        strcpy(*string_pp, value);
    }
    else if(mime_strnicmp( (kal_char*)da_omautil_context.dd_url_base, "http://", 7) ==0 ||
               mime_strnicmp( (kal_char*)da_omautil_context.dd_url_base, "http:\\\\", 7) ==0 )
    {
        /* Relative URL */
        if(value[0] == '/' || value[0] == '\\')
        {
            // find server address
            for(i=7; da_omautil_context.dd_url_base[i]; i++)
            {
                if(da_omautil_context.dd_url_base[i] == '/' ||
                    da_omautil_context.dd_url_base[i] == '\\')
                    break;
            }
            
            *string_pp = get_ctrl_buffer(len + i + 1);
            strncpy(*string_pp, da_omautil_context.dd_url_base, i);
            strncpy(*string_pp + i, value, len);
            (*string_pp)[i+len] = 0;
        }
        else
        {
            /* related path, add dd url base */
            *string_pp = get_ctrl_buffer(len + strlen(da_omautil_context.dd_url_base) + 1);
            sprintf(*string_pp, "%s%s", da_omautil_context.dd_url_base, value);
        }
    }
    else
    {
        ASSERT(0);
    }
    return TRUE;
}

static BOOL _dd_extract_url_ucs2(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    S8 **string_pp;
    S8 *newstr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = _dd_extract_url(value, len, obj, offset);
    if(ret)
    {
        string_pp = (S8**)((S8*)obj + offset);
        newstr = get_ctrl_buffer((strlen(*string_pp)+1)*ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*)newstr, (S8*)(*string_pp));
        free_ctrl_buffer(*string_pp);
        *string_pp = newstr;
    }
    return ret;
}


static BOOL _dd_extract_integer(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *result_p;
    S32 v;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_p = (S32*)((S8*)obj + offset);

    if(*result_p)
        return FALSE;

    v = atoi(value);
    if(v <= 0)
        da_omautil_context.dd_parse_error = TRUE;

    *result_p = v;
    return TRUE;
}

static BOOL _dd_extract_boolean(const S8* value, S32 len, void* obj, U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *result_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_p = (S32*)((S8*)obj + offset);

    if(mime_stricmp((kal_char *)"true", (kal_char *)value) == 0)
        *result_p = TRUE;
    else if(mime_stricmp((kal_char *)"false", (kal_char *)value) == 0)
        *result_p = FALSE;
    else
        da_omautil_context.dd_parse_error = TRUE;
    return TRUE;
}

static BOOL _dd_extract_datetime(const S8* value, S32 len, void* obj, U16 offset)
{
    ASSERT(0);
    return FALSE;
}

/*****************************************************************************
* FUNCTION
*   dd_read_end_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd_read_end_element(void *no_used, const char *el, S32 error)
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
*   dd_read_start_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd_read_start_element(void *no_used, const char *el, const char **attr, S32 error)
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
*   dd_read_data_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*
* RETURNS
*   void
*****************************************************************************/
static void _dd_read_data_element(void *no_used, const S8 * el, const S8 * value, S32 len, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             i;
    mmi_da_oma_dd_struct            *dd_info;
    BOOL                            pre_handled;
    BOOL                            add_to_list;
    
    void                            *obj;
    const dd_data_table_struct      *table;
    const dd_type_table_struct      *type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_omautil_context.dd_parse_error)
        return;

    if(!el)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    dd_info = da_omautil_context.dd_info;

    obj = dd_info;
    table = dd_elem_media_table;
    pre_handled = FALSE;
    add_to_list = FALSE;

    if(DD_IS_TAG("type", el))
    {
        for(i=0;i<4;i++)
        {
            if(!dd_info->type[i])
            {
                dd_info->type[i] = OslMalloc( len + 1 );
                strcpy(dd_info->type[i], value);
                break;
            }
        }
        add_to_list = (i==0) ? TRUE : FALSE;
        pre_handled = TRUE;
    }
    else if(DD_IS_TAG("DDVersion", el))
    {
        if(dd_info->DDVersion == 0)
        {
            if( !value ||
                strlen(value) != 3 ||
    		    value[1] != '.' ||
    		    value[0] < '0' || value[0] > '9' ||
    		    value[2] < '0' || value[2] > '9')
            {
                da_omautil_context.dd_parse_error = TRUE;
            }
            else
            {
                dd_info->DDVersion = (value[0] - '0') * 10 + (value[2] - '0');
            }
            add_to_list = TRUE;
        }
        pre_handled = TRUE;
    }

    i = 0;
    while(table->item)
    {
        if(DD_IS_TAG(table->item, el))
            break;
        table++;
        i++;
    }

    if(!table->item)
        return;

    DA_TRACE_FUNC1(_dd_read_data_element, i);

    /* found */
    type = &dd_xsd_type_info_table[table->type];
    
    if(!len || len > type->max_len)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    ASSERT(type->func);
    ASSERT(table->offset % 4 == 0);
    if(!pre_handled)
        add_to_list = type->func(value, len, obj, table->offset);

    if(add_to_list)
    {
        dd_info->attr_order[dd_info->attr_num] = i;
        dd_info->attr_num++;
    }

}

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_parse_dd
* DESCRIPTION
*   the main function to parse a dd file
* PARAMETERS
*   filename    IN      The path of dd file
*   item        OUT     Output the result to item
* RETURNS
*   MMI_TRUE :  OK
*   MMI_FALSE:  FAIL
*****************************************************************************/
MMI_BOOL mmi_da_oma_parse_dd(U16 * filename, mmi_da_job_struct *job, mmi_da_oma_dd_struct *dd_info, S8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT           parser;
    S32                         ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
        return MMI_FALSE;

    if (da_omautil_context.dd_parse_busy)
        return MMI_FALSE;

    da_omautil_context.dd_parse_busy = MMI_TRUE;
    da_omautil_context.dd_info = dd_info;
    da_omautil_context.curr_job = job;
    da_omautil_context.dd_parse_error = MMI_FALSE;

    ANSI_STR_MALLOC_COPY(da_omautil_context.dd_url_base, url);
    /* find URL base, remove filename */
    for(i = strlen(da_omautil_context.dd_url_base) - 1; i>=0 ;i--)
    {
        if(da_omautil_context.dd_url_base[i] == '/' ||  da_omautil_context.dd_url_base[i] == '\\' )
        {
            da_omautil_context.dd_url_base[i+1] = 0;
            break;
        }
    }

    xml_new_parser(&parser);
    xml_register_element_handler(&parser, _dd_read_start_element, _dd_read_end_element);
    xml_register_data_handler(&parser, _dd_read_data_element);
    ret = xml_parse(&parser, filename);
    xml_stop_parse(&parser);
    xml_close_parser(&parser);

    da_omautil_context.curr_job = NULL;
    da_omautil_context.dd_parse_busy = MMI_FALSE;
    DA_FREE_BUFFER(da_omautil_context.dd_url_base);

    if(dd_info->DDVersion == 0)
        dd_info->DDVersion = DD_VERSION;

    if (ret == XML_RESULT_OK && !da_omautil_context.dd_parse_error)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#ifdef __MMI_OMA_DD2_DOWNLOAD__
/*****************************************************************************
* FUNCTION
*   dd_read_end_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd2_read_end_element(void *no_used, const char *el, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const dd_data_table_struct     *table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_omautil_context.dd_parse_error)
        return;
    
    table = dd2_complex_elem_table;
    while(table->item)
    {
        if (DD_IS_TAG(table->item, el))
            break;
        table++;
    }
    if(!table->item)
        return;

    ASSERT(da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level] == table->type);
    da_omautil_context.dd2_state_level--;

    switch(table->type)
    {
    case DD2_PARSING_STATE_PRODUCT:
        if(da_omautil_context.dd2_skip > 0)
            da_omautil_context.dd2_skip--;
        da_omautil_context.dd2_product_idx = -1;
        break;

    case DD2_PARSING_STATE_MO:
        if(da_omautil_context.dd2_skip > 0)
            da_omautil_context.dd2_skip--;
        da_omautil_context.dd2_mo_idx = -1;
        break;
    }

}

/*****************************************************************************
* FUNCTION
*   dd_read_start_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static void _dd2_read_start_element(void *no_used, const char *el, const char **attr, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             i;
    mmi_da_oma_dd2_struct           *dd2_info;
    mmi_da_oma_dd2_product_struct   *product;
    mmi_da_oma_dd2_mo_struct        *mo;
    mmi_da_oma_dd2_meta_struct      *meta;

    const dd_data_table_struct     *table;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(da_omautil_context.dd_parse_error)
        return;

    dd2_info = da_omautil_context.dd2_info;
    table = dd2_complex_elem_table;

    while(table->item)
    {
        if (DD_IS_TAG(table->item, el))
            break;
        table++;
    }

    if(!table->item)
        return;

    da_omautil_context.dd2_state_level++;
    da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level] = table->type;

    switch(da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level])
    {
    case DD2_PARSING_STATE_MEDIA:
        /* <media>, search for DDVersion */
        DD_FIND_ATTR("DDVersion", attr, i);
        if(attr[i])
        {
            i++;
            if( !attr[i] ||
                strlen(attr[i]) != 3 ||
    		    attr[i][1] != '.' ||
    		    attr[i][0] < '0' || attr[i][0] > '9' ||
    		    attr[i][2] < '0' || attr[i][2] > '9')
            {
                da_omautil_context.dd_parse_error = TRUE;
                return;
            }

            dd2_info->DDVersion = (attr[i][0] - '0') * 10 + (attr[i][2] - '0');
        }
        else
            dd2_info->DDVersion = 10;
        break;

    case DD2_PARSING_STATE_PRODUCT:
        /* in skip mode */
        if(da_omautil_context.dd2_skip)
        {
            da_omautil_context.dd2_skip++;
            return;
        }

        /* <product>, check compund, new a product object */
        if(dd2_info->product_num)    // TODO: only accept 1 product for now
        {
            ASSERT(da_omautil_context.dd2_skip==0);
            da_omautil_context.dd2_skip++;
            return; 
        }

        DA_ALLOC_OBJ(product, mmi_da_oma_dd2_product_struct);
        dd2_info->product_list = product;
        dd2_info->product_num = 1;
        da_omautil_context.dd2_product_idx = 0;
        
        DD_FIND_ATTR("compound", attr, i);
        if(attr[i])
        {
            // TODO: parse compound flag attr[i+1]
            i++;
        }
        break;

    case DD2_PARSING_STATE_MO:
        /* in skip mode */
        if(da_omautil_context.dd2_skip)
        {
            da_omautil_context.dd2_skip++;
            return;
        }

        // TODO: same, support 1 mo only for now 
        product = dd2_info->product_list;
        if(product->mo_num)
        {
            ASSERT(da_omautil_context.dd2_skip==0);
            da_omautil_context.dd2_skip++;
            return;
        }

        DA_ALLOC_OBJ(mo, mmi_da_oma_dd2_mo_struct);
        product->mo_list = mo;
        product->mo_num = 1;
        da_omautil_context.dd2_mo_idx = 0;
        break;
        
    case DD2_PARSING_STATE_META:
        /* in skip mode */
        if(da_omautil_context.dd2_skip)
            return;

        DA_ALLOC_OBJ(meta, mmi_da_oma_dd2_meta_struct);

        ASSERT(da_omautil_context.dd2_product_idx >= 0);
        product = dd2_info->product_list;
        if(da_omautil_context.dd2_mo_idx >= 0)
        {
            mo = product->mo_list;
            mo->meta_info = meta;
        }
        else
        {
            product->meta_info = meta;
        }
        break;
        
    }
}

/*****************************************************************************
* FUNCTION
*   dd_read_data_element
* DESCRIPTION
*   a callback function for XML parser, parse dd file
* PARAMETERS
*
* RETURNS
*   void
*****************************************************************************/
static void _dd2_read_data_element(void *no_used, const S8 * el, const S8 * value, S32 len, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             i;
    mmi_da_oma_dd2_struct           *dd2_info;
    mmi_da_oma_dd2_product_struct   *product;
    mmi_da_oma_dd2_mo_struct        *mo;
    mmi_da_oma_dd2_meta_struct      *meta;
    
    void                            *obj;
    const dd_data_table_struct      *table;
    const dd_type_table_struct      *type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(da_omautil_context.dd_parse_error || da_omautil_context.dd2_skip)
        return;

    if(!el)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    dd2_info = da_omautil_context.dd2_info;

    product = da_omautil_context.dd2_product_idx >= 0 ? dd2_info->product_list : NULL;
    mo = (product && da_omautil_context.dd2_mo_idx >= 0) ? product->mo_list : NULL;
    meta = mo ? mo->meta_info : (product ? product->meta_info : NULL);

    switch(da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level])
    {
    case DD2_PARSING_STATE_VENDOR:
        obj = dd2_info;
        table = dd2_elem_vendor_table;
        break;

    case DD2_PARSING_STATE_META:
        obj = meta;
        table = dd2_elem_meta_table;
        break;

    case DD2_PARSING_STATE_MO:
        // TODO: if there are many multiple, handle it in table
        /* special case for "type" */
        if(DD_IS_TAG("type", el))
        {
            for(i=0;i<4;i++)
            {
                if(!mo->type[i])
                {
                    mo->type[i] = OslMalloc( len + 1 );
                    strcpy(mo->type[i], value);
                    break;
                }
            }
            return;
        }
        /* continue */
        
    case DD2_PARSING_STATE_OBJ_URI:
        obj = mo;
        table = dd2_elem_mo_table;
        break;

    case DD2_PARSING_STATE_MEDIA:
        obj = dd2_info;
        table = dd2_elem_media_table;
        break;

    default:
        return;
    }

    i = 0;
    while(table->item)
    {
        if(DD_IS_TAG(table->item, el))
            break;
        table++;
        i++;
    }

    if(!table->item)
        return;

    /* found */
    DA_TRACE_FUNC2(_dd2_read_data_element, i, da_omautil_context.dd2_state_stack[da_omautil_context.dd2_state_level]);
    type = &dd_xsd_type_info_table[table->type];
    
    if(!len || len > type->max_len)
    {
        da_omautil_context.dd_parse_error = MMI_TRUE;
        return;
    }

    ASSERT(type->func);
    ASSERT(table->offset % 4 == 0);
    type->func(value, len, obj, table->offset);

}

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_parse_dd
* DESCRIPTION
*   the main function to parse a dd file
* PARAMETERS
*   filename    IN      The path of dd file
*   item        OUT     Output the result to item
* RETURNS
*   MMI_TRUE :  OK
*   MMI_FALSE:  FAIL
*****************************************************************************/
MMI_BOOL mmi_da_oma_parse_dd2(U16 * filename, mmi_da_job_struct *job, mmi_da_oma_dd2_struct *dd2_info, S8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT           parser;
    S32                         ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
        return MMI_FALSE;
    
    if (da_omautil_context.dd_parse_busy)
        return MMI_FALSE;

    da_omautil_context.dd_parse_busy = MMI_TRUE;

    da_omautil_context.dd2_info = dd2_info;
    da_omautil_context.dd2_state_level = -1;
    da_omautil_context.dd2_skip = 0;
    da_omautil_context.dd2_mo_idx = -1;
    da_omautil_context.dd2_product_idx = -1;

    da_omautil_context.curr_job = job;
    da_omautil_context.dd_parse_error = MMI_FALSE;

    ANSI_STR_MALLOC_COPY(da_omautil_context.dd_url_base, url);
    /* find URL base, remove filename */
    for(i = strlen(da_omautil_context.dd_url_base) - 1; i>=0 ;i--)
    {
        if(da_omautil_context.dd_url_base[i] == '/' ||  da_omautil_context.dd_url_base[i] == '\\' )
        {
            da_omautil_context.dd_url_base[i+1] = 0;
            break;
        }
    }

    xml_new_parser(&parser);
    xml_register_element_handler(&parser, _dd2_read_start_element, _dd2_read_end_element);
    xml_register_data_handler(&parser, _dd2_read_data_element);
    ret = xml_parse(&parser, filename);
    xml_stop_parse(&parser);
    xml_close_parser(&parser);

    da_omautil_context.curr_job = NULL;
    da_omautil_context.dd_parse_busy = MMI_FALSE;
    DA_FREE_BUFFER(da_omautil_context.dd_url_base)

    if(dd2_info->DDVersion == 0)
        dd2_info->DDVersion = DD2_VERSION;

    if (ret == XML_RESULT_OK)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif

#define OMA_UTIL

void mmi_da_oma_report_map_string(S32 error, U16 *strId_p, S8** str_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 stringId = 0;
    S8  *string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(error > 0)
    {
        stringId = GetFileSystemErrorString(-error);
        error = MMI_DA_OMA_DEVICE_ABORTED;
    }
    
    for (i = 0; ; i++)
    {
        if (oma_error_tbl[i].errorNo == error)
        {
            if(stringId == 0)
                stringId = oma_error_tbl[i].stringId;
            string = oma_error_tbl[i].report_msg;
            break;
        }

        if(!oma_error_tbl[i].errorNo)
            break;
    }
    ASSERT(stringId && string);

    if(strId_p)
        *strId_p = stringId;
    if(str_pp)
        *str_pp = string;
}

#define OMA_APP_CHECK

/*****************************************************************************
* FUNCTION
*   mmi_da_oma_search_install_check_handler
* DESCRIPTION
*   Handler: to find if there is corresponding instal callback funtion
* PARAMETERS
*   type    [IN]    the mime type of file
* RETURNS
*   return the callback function
*****************************************************************************/
const mmi_da_oma_install_check_tbl_struct *mmi_da_oma_search_install_check_handler(const applib_mime_type_struct * type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == NULL)
    {
        return NULL;
    }

    for (i = mmi_da_oma_install_check_hdlr_num - 1; i >= 0; i--)
    {
        if (mmi_da_oma_install_check_tbl[i].mime_subtype == type->mime_subtype)
        {
            return &mmi_da_oma_install_check_tbl[i];
        }
    }

    return NULL;
}

#endif /* __MMI_OMA_DD_DOWNLOAD__ */

