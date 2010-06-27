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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef DOWNLOAD_AGENT_OMA_H
#define DOWNLOAD_AGENT_OMA_H

#if defined (__MMI_OMA_DD_DOWNLOAD__)

#ifndef _FILE_MGR_H_
#error "Please include FileMgr.h first"
#endif

#ifndef DOWNLOAD_AGENT_DEF_H
#error "Please include DLAgentDef.h first"
#endif

#ifndef DOWNLOAD_AGENT_GPROT_H
#error "Please include DLAgentGprot.h first"
#endif

#ifdef __DRM_SUPPORT__
#ifndef DRM_DEF_H
#error "Please include drm_def.h first"
#endif
#endif

/****************************************************************************
* Define
*****************************************************************************/

#define DD_VERSION              10
#ifdef __MMI_OMA_DD2_DOWNLOAD__
#define DD2_VERSION             20
#endif

/****************************************************************************
* Macro
*****************************************************************************/


/****************************************************************************
* Typedef - Enum
*****************************************************************************/

typedef enum
{
    MMI_DA_OMA_SUCCESS                       = 0
    ,MMI_DA_OMA_INSUFFICIENT_MEM             = -1
    ,MMI_DA_OMA_USER_CANCELLED               = -2
    ,MMI_DA_OMA_LOSS_OF_SERVICE              = -3
    ,MMI_DA_OMA_ATTRIBUTE_MISMATCH           = -4
    ,MMI_DA_OMA_INVALID_DESCRIPTOR           = -5
    ,MMI_DA_OMA_INVALID_DDVSERSION           = -6
    ,MMI_DA_OMA_DEVICE_ABORTED               = -7
    ,MMI_DA_OMA_NON_ACCEPTABLE_CONTENT       = -8
    ,MMI_DA_OMA_LOADER_ERROR                 = -9
    ,MMI_DA_OMA_AUTHORIZATION_FAIL           = -10
    ,MMI_DA_OMA_INSUFFICIENT_STORAGE         = -11
    ,MMI_DA_OMA_FILE_ACCESS_ERROR            = -12
} mmi_da_oma_error_enum;

enum
{
    DD_ELEM_TYPE,
    DD_ELEM_OBJECT_URI,
    DD_ELEM_NOTIFY_URI,
    DD_ELEM_NEXT_URL,
    DD_ELEM_VERSION,
    DD_ELEM_NAME,
    DD_ELEM_DESCRIPTION,
    DD_ELEM_VENDOR,
    DD_ELEM_INFO_URL,
    DD_ELEM_ICON_URI,
    DD_ELEM_INSTALL_PARAM,
    DD_ELEM_SIZE,
    
    DD_ELEM_NUM
};

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct
{
    wps_session_handle  session;
    S32                 error;
    S8                  *installNotifyURI;
    mmi_da_job_struct   *job;

} mmi_da_oma_report_struct;

#ifdef __MMI_OMA_DD2_DOWNLOAD__
typedef struct
{
    S8  *name;
    S8  *description;
    /* text x N */
    S8  *infoURL;
    S8  *iconURI;
    S8  *installParam;
    S8  *installNotifyURI;
    S8  *environment;
    S8  *downloadNotifyURI;
    S8  *deleteNotifyURI;
    S8  *mediaURI;
    S32 suppressUserConfirmation;

#if 0   // not implemented yet
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
} mmi_da_oma_dd2_meta_struct;

typedef struct _mmi_da_oma_dd2_mo
{
    struct _mmi_da_oma_dd2_mo   *next;
    
    U32     size;
    S8      *type[4];                   /* only support 4 type */
    U32     installSize;
    S8      *objectId;
    S32     progressiveDownloadflag;
    S8      *objectVersion;
    S8      *objectURI;
    S8      *more_objectURI;            /* not used */
    void    *parent_ptr;                /* pointer to parent product */
    
    mmi_da_oma_dd2_meta_struct *meta_info;
    
} mmi_da_oma_dd2_mo_struct;

typedef struct
{
    S8  *timestamp;
    S8  *downloadTime;
    S8  *timeInterval;
    S8  *timeIntervalExpire;
    S8  *reservationNotifyURI;

} mmi_da_oma_dd2_reserve_struct;

typedef struct _mmi_da_oma_dd2_product
{
    struct _mmi_da_oma_dd2_product  *next;
    
    mmi_da_oma_dd2_meta_struct      *meta_info;

    mmi_da_oma_dd2_mo_struct        *mo_list;
    U32                             mo_num;

    BOOL                            is_compund;

} mmi_da_oma_dd2_product_struct;


typedef struct
{
    U32 DDVersion;
    
    S8  *vendorName;     /* NULL if not present */
    S8  *vendorHome;
    S8  *vendorLogo;
    S8  *vendorSupport;

    S8  *nextURL;
    S8  *updatedDDURI;
    U32 encoding;       /* this may be UCS2, depend on encoding, pay more attention */
    
    mmi_da_oma_dd2_product_struct   *product_list;
    U32                             product_num;

    mmi_da_oma_dd2_reserve_struct   *reserve;
    
} mmi_da_oma_dd2_struct;
#endif


typedef BOOL (*mmi_da_oma_install_check_hdlr) (mmi_da_oma_dd_struct * item);
typedef struct
{
    applib_mime_type_enum mime_type;
    applib_mime_subtype_enum mime_subtype;
    mmi_da_oma_install_check_hdlr handler;
} mmi_da_oma_install_check_tbl_struct;

/****************************************************************************
*                       Typedef - function
*****************************************************************************/


/****************************************************************************
*                       Global Function
*****************************************************************************/
extern MMI_BOOL mmi_da_oma_parse_dd(U16 * filename, mmi_da_job_struct *job, mmi_da_oma_dd_struct *dd_info, S8* urlbase);
#ifdef __MMI_OMA_DD2_DOWNLOAD__
extern MMI_BOOL mmi_da_oma_parse_dd2(U16 * filename, mmi_da_job_struct *job, mmi_da_oma_dd2_struct *dd_info, S8* urlbase);
#endif

extern void mmi_da_oma_report_map_string(S32 error, U16 *strId_p, S8** str_pp);

extern const mmi_da_oma_install_check_tbl_struct *mmi_da_oma_search_install_check_handler(const applib_mime_type_struct* type);
    
#endif /* __MMI_OMA_DD_DOWNLOAD__ */
#endif /* DOWNLOAD_AGENT_OMA_H */

