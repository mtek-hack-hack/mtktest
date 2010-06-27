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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef DOWNLOAD_AGENT_WPS_H
#define DOWNLOAD_AGENT_WPS_H


/****************************************************************************
* Define
*****************************************************************************/

#define MMI_DA_INVALID_SESSION_HANDLE  0x00000000

/****************************************************************************
* Typedef
*****************************************************************************/

typedef U32 wps_session_handle;

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

/****************************************************************************
*                       Typedef - function
*****************************************************************************/

typedef void (*mmi_da_wps_session_created_funcptr_type)(wps_session_handle session, U32 arg);

typedef void (*mmi_da_wps_http_response_funcptr_type)(U32 arg, U8 result, U16 status, 
                                                      S8 *content_type, U32 context_len);
typedef void (*mmi_da_wps_http_auth_ind_funcptr_type)(U32 arg);
typedef void (*mmi_da_wps_dl_progress_funcptr_type)(U32 arg, U8 status, U32 curr_size, S32 cause);
typedef void (*mmi_da_wps_session_aborted_funcptr_type)(U32 arg);

/****************************************************************************
*                       Global Function
*****************************************************************************/

extern void mmi_da_wps_init(void);

extern void mmi_da_wps_create_session(U32 arg, 
                                      mmi_da_wps_session_created_funcptr_type callback1,
                                      mmi_da_wps_http_response_funcptr_type callback2,
                                      mmi_da_wps_http_auth_ind_funcptr_type callback3,
                                      mmi_da_wps_dl_progress_funcptr_type callback4);

extern void mmi_da_wps_cancel_create_session(U32 arg);

extern MMI_BOOL mmi_da_wps_http_req(wps_session_handle session, 
                                U8 method,
                                S8 *url,
                                S8 *post_data,
                                U16 *filepath,
                                U8 reply_type);

extern MMI_BOOL mmi_da_wps_session_auth(wps_session_handle session, U8 *username, U8 *password);
extern MMI_BOOL mmi_da_wps_session_auth_UCS2(wps_session_handle session, U16 *username, U16 *password);

//extern MMI_BOOL mmi_da_wps_session_abort(wps_session_handle session);

extern void mmi_da_wps_close_session(wps_session_handle session,
                                     mmi_da_wps_session_aborted_funcptr_type callback5);

extern S16 mmi_da_wps_get_session_id(wps_session_handle session);

#endif /* DOWNLOAD_AGENT_WPS_H */

