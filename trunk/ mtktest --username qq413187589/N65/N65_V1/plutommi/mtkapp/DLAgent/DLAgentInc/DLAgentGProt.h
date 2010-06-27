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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#ifndef DOWNLOAD_AGENT_GPROT_H
#define DOWNLOAD_AGENT_GPROT_H

#ifndef _FILE_MGR_H_
#error "Please include FileMgr.h first"
#endif

#ifndef DOWNLOAD_AGENT_DEF_H
#error "please include DLAgentDef.h"
#endif

/****************************************************************************
* Define
*****************************************************************************/


/****************************************************************************
* Typedef - function
*****************************************************************************/

typedef BOOL (*mmi_da_filepath_hdlr)(
	S32 session_id,
	S32 mime_type,
	S32 mime_subtype,
	U16	*filepath);

typedef void (*mmi_da_report_hdlr)(
	S32	session_id,
	S32	status,
	S32	cause,
	U32	seq_num,
	U32	acc_size);

typedef void (*mmi_da_dispatch_hdlr)(
	S32 session_id,
	S32 mime_type,              /* applib_mime_type_enum */
	S32 mime_subtype,           /* applib_mime_subtype_enum */
	S32 action,
	U16 *filepath,              /* FMGR_MAX_PATH_LEN */
	S8  *url,                    /* WAP_DL_MAX_URL_LEN */
	S8  *mime_type_string        /* WAP_DL _MAX_MIME_TYPE_LEN */
);

/* Hook_patch */
typedef BOOL (*mmi_da_hook_dispatch_hdlr)(
	S32	session_id,
	S32	mime_type,              /* applib_mime_type_enum */
	S32	mime_subtype,           /* applib_mime_subtype_enum */
	S32 action,
	PU16 filepath,              /* FMGR_MAX_PATH_LEN */
	PS8	url,                    /* WAP_DL_MAX_URL_LEN */
	PS8	mime_type_string        /* WAP_DL _MAX_MIME_TYPE_LEN */
);

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

 
/*    OLD Bypass enum vs NEW Boolean
    
                    FALSE   Lv1     Lv2     Lv3
                
    conf_dispatch   Yes     No      No      No

    conf_overwrite  Yes     Yes     No      No

    is_push         Yes     Yes     Yes     No (if Yes, can insert RB for later handle
                                                 if No, must handle immediatedly)
    can_background  Yes     Yes     No      No     

    Remove after    No      No      Yes     Yes
    dispatch
*/

/* default_filename = true ,                        => use default filename */
/* default_filename = false, length of filenme = 0  => User input */
/* default_filename = false, has filename           => use given filename */
typedef struct
{
    S32     drv;
    S32     storage;                         /* mmi_da_storage_enum*/
    U16     folder[FMGR_MAX_FILE_LEN + 1];
    U16     filename[FMGR_MAX_FILE_LEN + 1];
    BOOL    default_filename;

    BOOL    do_dispatch;        /* if FALSE, treat as normal file */
    BOOL    confirm_dispatch;
    BOOL    confirm_push;
    BOOL    can_minimize;

    mmi_da_filepath_hdlr    filepath_hdlr;
    mmi_da_report_hdlr      report_hdlr;

    /* below are obsolete member */
    BOOL   percentage_bar;                  /* obsolete */
    S32    bypass;                          /* obsolete */
    BOOL   keepfile;                        /* obsolete */
} mmi_da_setting_struct;


typedef void (*mmi_da_setting_hdlr)(
	S32 session_id,
	S32 mime_type,                  /* applib_mime_type_enum */
	S32 mime_subtype,               /* applib_mime_subtype_enum */
	S32 action,
	U32 filesize,
	S8  *url,                        /* WAP_DL_MAX_URL_LEN */
	S8  *mime_type_string,           /* WAP_DL _MAX_MIME_TYPE_LEN */
	U32 content_len,
	S8  *content,
	mmi_da_setting_struct *setting
);

/****************************************************************************
* Global Function
*****************************************************************************/

extern void mmi_da_default_setting(S32 session_id,
    S32 mime_type,S32 mime_subtype, S32 action,
	U32 filesize,PS8 url,PS8 mime_type_string, U32 content_len,
	PS8	content,mmi_da_setting_struct *setting);

extern void mmi_da_bypass_setting(S32 session_id,
    S32 mime_type,S32 mime_subtype, S32 action,
	U32 filesize,PS8 url,PS8 mime_type_string, U32 content_len,
	PS8	content,mmi_da_setting_struct *setting);

extern void mmi_da_push_setting(S32 session_id,
    S32 mime_type,S32 mime_subtype, S32 action,
	U32 filesize,PS8 url,PS8 mime_type_string, U32 content_len,
	PS8	content,mmi_da_setting_struct *setting);

/* ======================================  OMA =======================  */
typedef struct
{
    S32 ntype;
    S8 *type[4];
    S8 *objectURI;
    S8 *installNotifyURI;
    S8 *nextURL;
    S32 DDVersion;
    S8 *name;
    S8 *description;
    S8 *vendor;
    S8 *infoURL;
    S8 *iconURI;
    S8 *installParam;
    U32 size;

    U8  attr_order[20];
    U8  attr_num;

} mmi_da_oma_dd_struct;

extern U8 mmi_da_launch_ring_buffer_check(void);
extern void mmi_da_entry_new_push_ind(void);
extern void mmi_da_enter_idle_screen_notify(void);

extern S32 mmi_da_stop_dl(S32 session_id);

#ifdef __USB_IN_NORMAL_MODE__
extern void mmi_da_usb_mode_on(void);
#endif

#endif /* DOWNLOAD_AGENT_GPROT_H */

