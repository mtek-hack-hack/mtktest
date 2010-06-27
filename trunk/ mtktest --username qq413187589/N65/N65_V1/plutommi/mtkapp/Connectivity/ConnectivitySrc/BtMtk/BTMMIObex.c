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
 * BTMMIObex.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for dispatch primitive from goep obex to different applications.
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
#if defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)

/*  Include: MMI header file */
#include "FileManagerGProt.h"
/* Trace Header Files */
#include "FileMgr.h"
#include "xml_def.h"
#include "BTMMIScrGprots.h"
#include "BTMMICm.h"
#include "Bluetooth_struct.h"
#include "BTMMIOppGprots.h"
#include "BTMMIFtpGprots.h"
#include "BTMMIFtpScr.h"
#include "BTMMIFtp.h"
#include "BTMMIObex.h"

#ifdef __MMI_GOEP_AUTH__

extern void mmi_bt_obex_auth_ind_hdlr(goep_auth_ind_struct *auth_ind);

static auth_ind_handler_struct *g_auth_ind_handler_list;

kal_uint8 mmi_register_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len, AUTH_IND_HANDLER auth_chal_handler);

void mmi_deregister_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len);

static AUTH_IND_HANDLER find_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len);

#define UUID_EQUAL(uuid1, uuid2, uuid_len)                          \
   ((uuid1 && uuid2 && kal_mem_cmp(uuid1, uuid2, uuid_len) == 0) || \
         (((uuid1 == 0 || uuid1[0] == 0) && uuid_len == 0) && uuid2 == 0))

#endif /* __MMI_GOEP_AUTH__ */ 

/*****************************************************************
    INTERNAL STATIC FUNCTIONS
*****************************************************************/
static void mmi_bt_obex_msg_hdlr(void *msg, int mod_src, void *ilm_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_event_hdlr_init
 * DESCRIPTION
 *  This function is to initialize FTP protocol event hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_obex_event_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OBEX_DEBUG(kal_print("MMI_OBEX EVENT HDLR INIT\n");)    

    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_REGISTER_SERVER_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_DEREGISTER_SERVER_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_CONNECT_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PUSH_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PULL_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_SET_FOLDER_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_ABORT_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_AUTHORIZE_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_CONNECT_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PUSH_RSP);    
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PULL_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_SET_FOLDER_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_ABORT_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_DISCONNECT_IND); 

#ifdef __MMI_GOEP_AUTH__
    SetProtocolEventHandler((PsFuncPtr) mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_AUTH_IND);
#endif 
}

#define OBEX_HANDLER_FUNCTION

#ifdef __MMI_GOEP_AUTH__

kal_bool DefAuthHandling = KAL_FALSE;

extern void mmi_bt_obex_auth_ind_hdlr(goep_auth_ind_struct *auth_ind);
extern void mmi_bt_obex_disconnect_ind_hdlr(goep_disconnect_ind_struct *disconnect_ind);
#endif /* __MMI_GOEP_AUTH__ */ 


#define OBEX_HANDLER_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_msg_hdlr
 * DESCRIPTION
 *  This function is to handle obex msg to profile
 * PARAMETERS
 *  msg         [IN]         
 *  mod_src     [IN]        
 *  ilm_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_obex_msg_hdlr(void *msg, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_obex_msg_struct* obex_msg = (mmi_obex_msg_struct*)msg;
    ilm_struct* mmi_ilm_ptr = (ilm_struct*) ilm_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OBEX_DEBUG(kal_print("MMI_OBEX_MSG DISPATCHER\n");
        )
#ifdef __MMI_GOEP_AUTH__
        /* check if the msg is GOEP_AUTH_IND */
        if (mmi_ilm_ptr->msg_id == MSG_ID_GOEP_AUTH_IND)
    {
        AUTH_IND_HANDLER auth_ind_handler = find_auth_ind_handler(obex_msg->uuid, obex_msg->uuid_len);

        if (auth_ind_handler)
        {
            auth_ind_handler((goep_auth_ind_struct*) msg);
        }
        else
        {
            DefAuthHandling = KAL_TRUE;

            /* process GOEP_AUTH_IND msg as default */
            mmi_bt_obex_auth_ind_hdlr((goep_auth_ind_struct*) msg);
        }
        return;
    }
    else if (mmi_ilm_ptr->msg_id == MSG_ID_GOEP_DISCONNECT_IND && DefAuthHandling)
    {
        mmi_bt_obex_disconnect_ind_hdlr((goep_disconnect_ind_struct*) msg);
        DefAuthHandling = KAL_FALSE;
    }
#endif /* __MMI_GOEP_AUTH__ */ 

    /* OPP */
    if (obex_msg->uuid_len == 0 && obex_msg->uuid[0] == '\0')
    {
    #if defined(__MMI_OPP_SUPPORT__)        
        MMI_OBEX_DEBUG(kal_print("MMI_OBEX_MSG DISPATCH TO OPP\n");)    
        mmi_bt_opp_event_hdlr(mmi_ilm_ptr->msg_id, msg);
        return;
    #endif /* defined(__MMI_OPP_SUPPORT__) */ 
    }        
    /* FTP */
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)        
    if ( strncmp( (const char*)OBEX_FTP_UUID, (const char*)obex_msg->uuid, 16 ) == 0 )
    {
        MMI_OBEX_DEBUG(kal_print("MMI_OBEX_MSG DISPATCH TO FTP\n");)    
        mmi_bt_ftp_event_hdlr(mmi_ilm_ptr->msg_id, msg);
		return;
    }
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

	MMI_OBEX_DEBUG(kal_print("MMI_OBEX_MSG DISPATCHER NOT FTP\n");)
}

#ifdef __MMI_GOEP_AUTH__


/*****************************************************************************
 * FUNCTION
 *  mmi_register_auth_ind_handler
 * DESCRIPTION
 *  This function is to register AUTH_IND msg handler
 * PARAMETERS
 *  uuid                    [IN]         profile's OBEX uuid
 *  uuid_len                [IN]        length of uuid
 *  auth_ind_handler        [IN]        
 *  auth_chal_handler: func to process AUTH_IND msg(?)
 * RETURNS
 *  1: success
 *  0: fail
 *****************************************************************************/
kal_uint8 mmi_register_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len, AUTH_IND_HANDLER auth_ind_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    auth_ind_handler_struct *item = get_ctrl_buffer(sizeof(auth_ind_handler_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (uuid && uuid[0] != 0)
    {
        kal_mem_cpy(item->uuid, uuid, uuid_len);
        item->uuid_len = uuid_len;
    }
    else
    {
        item->uuid[0] = 0;
        item->uuid_len = 0;
    }
    item->auth_ind_handler = auth_ind_handler;
    item->next = NULL;

    if (g_auth_ind_handler_list == NULL)
    {
        g_auth_ind_handler_list = item;
    }
    else
    {
        item->next = g_auth_ind_handler_list;
        g_auth_ind_handler_list = item;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_deregister_auth_ind_handler
 * DESCRIPTION
 *  This function is to deregister AUTH_IND msg handler
 * PARAMETERS
 *  uuid            [IN]        profile's OBEX uuid
 *  uuid_len        [IN]        length of uuid
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_deregister_auth_ind_handler(kal_uint8 *uuid, kal_uint8 uuid_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    auth_ind_handler_struct *item = g_auth_ind_handler_list;
    auth_ind_handler_struct *prev = item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the uuid */
    while (item != NULL)
    {

        if (UUID_EQUAL(uuid, item->uuid, uuid_len))
        {
            if (item == g_auth_ind_handler_list)
            {
                g_auth_ind_handler_list = item->next;
            }
            else
            {
                prev->next = item->next;
            }
            /* free memory */
            free_ctrl_buffer(item);

            break;  /* OK */
        }
        prev = item;
        item = item->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  find_auth_ind_handler
 * DESCRIPTION
 *  search auth_ind handler according uuid
 * PARAMETERS
 *  uuid            [IN]         
 *  uuid_len        [IN]        
 * RETURNS
 *   not NULL: success
 *   NULL: fail
 *****************************************************************************/
static AUTH_IND_HANDLER find_auth_ind_handler(kal_uint8 uuid[], kal_uint8 uuid_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    auth_ind_handler_struct *item = g_auth_ind_handler_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the uuid */
    while (item != NULL)
    {
        if (UUID_EQUAL(uuid, item->uuid, uuid_len))
        {
            return item->auth_ind_handler;
        }
        item = item->next;
    }
    return NULL;
}
#endif /* __MMI_GOEP_AUTH__ */ 

#if defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) 
static U8 mmi_bt_obex_profile_share_buffer[MMI_OBEX_PROFILE_SHARE_BUF_SIZE];
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_get_profile_shared_buffer
 * DESCRIPTION
 *  To return all foreground profiles used buffer ptr.
 * PARAMETERS
 *  uuid            [IN]         
 *  uuid_len        [IN]        
 * RETURNS
 *   not NULL: success
 *   NULL: fail
 *****************************************************************************/
U8 *mmi_bt_obex_get_profile_shared_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_MMI_OBEX_GET_PROFILE_SHARED_BUF);
    
    memset(mmi_bt_obex_profile_share_buffer, 0, MMI_OBEX_PROFILE_SHARE_BUF_SIZE);
    return mmi_bt_obex_profile_share_buffer;
}

#endif /* (__MMI_FTC_SUPPORT__) || (__MMI_OPP_SUPPORT__) */

#endif /* (__MMI_FTS_SUPPORT__) || (__MMI_FTC_SUPPORT__) || (__MMI_OPP_SUPPORT__) */
#endif /*__MMI_BT_MTK_SUPPORT__*/

