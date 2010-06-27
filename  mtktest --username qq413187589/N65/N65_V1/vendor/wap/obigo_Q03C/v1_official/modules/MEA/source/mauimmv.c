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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/* !\file mauimmv.c
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_core.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "maintsig.h"
#include "mautils.h"
#include "mauicmn.h"
#include "mauimenu.h"
#include "mammv.h"
#include "mauimmv.h"
#include "mamob.h"
#ifdef WAP_SUPPORT
#include "mauidia.h"
#include "mamh.h" /* MH FSM signal */
#endif

#ifdef MMS_SLIM_MEM
#include "widget_extension.h"
#include "msig.h"     //for fldmgr.h
#include "fldmgr.h" //for MMS_FOLDER
#include "msf_mem.h" //for mamem.h
#include "mamem.h" //for allocate and free memory
#include "mamv.h"     //for meaMMCGetCurrentActiveMsg
#include "mtr.h"      //for mauimob.h
#include "mauimob.h"  //for getMixedMoInfo
#endif /* MMS_SLIM_MEM */

#include "widget.h"  /* For isInCall() */

#ifdef __UNIFIED_MSG_SUPPORT__
#include "mamr.h" /* mame.h */
#include "mame.h" /* ME FSM signal */
#include "maaddr.h"
#include "madel.h"
#include "macore.h"  /* MEA_SIG_CORE_TERMINATE_APP */
#include "widget.h"
#include "mms_aapp.h"
extern MSF_BOOL meaCreateDetailListView(MmsMsgId msgId, SlsUnrefItemList *unrefItems);
extern void mms_enter_sms_editor_handler(void *p);
#endif
#ifndef __UNIFIED_COMPOSER_SUPPORT__
#include "mms_if.h"
#include "mtr_cmn.h"
#include "masrh.h"
#include "macore.h"
#include "bra_if.h"  /* for BRAif_createUI */
#endif
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mmsadp.h"
extern void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id);
#endif
#ifndef __UNIFIED_COMPOSER_SUPPORT__
extern MtrParseResult *mtrGetSelectedLink();
#endif
/******************************************************************************
 * Data-structures
 *****************************************************************************/

/******************************************************************************
 * Variables
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

static MSF_BOOL createMenuItems(const MeaMoDataItem *mo);

#ifdef __UNIFIED_MSG_SUPPORT__
static void exitMobPlayer()
{
    (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);  /* Stop MOB(player) -> it'll evoke MEA_SIG_MMV_DEACTIVATE */
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
    (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_NAV_DEACTIVATE);  /* Stop MOB */
#endif
}
#endif
/*!
 * \brief Signal converter for the navigation menu.
 * 
 * \param actionType The type of action, MEA_NAV_ACTION_BACK or 
 *  MEA_NAV_ACTION_OK.
 *****************************************************************************/
static void navMenuSignalConverter(MeaNavAction actionType)
{
    if (actionType == MEA_NAV_ACTION_BACK)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
        return;
    }
    if (actionType == MEA_NAV_ACTION_OK)
    {
#ifndef __UNIFIED_COMPOSER_SUPPORT__
        MtrParseResult *selectedLink = mtrGetSelectedLink();
#endif
        switch(meaGetMmvNavMenuItem())
        {
#ifndef __UNIFIED_COMPOSER_SUPPORT__
        case MEA_MMV_LINK_BRA:
            if (selectedLink && selectedLink->link) 
            {
                char *url = NULL, *tmp = NULL;
                
                url = msf_cmmn_strdup(MSF_MODID_MEA, selectedLink->link);
                tmp = url;
                while ((tmp = strstr(tmp, ":\\\\")) != NULL)
                {
                    *(tmp + 1) = '/';
                    *(tmp + 2) = '/';
                    tmp += 3;
                }
                
                (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
                BRAif_createUI(BRA_UI_GOTO_URL, (const char *)url);
                MEA_FREE(url);
            }
            break;
            
        case MEA_MMV_LINK_CALL:
            if (selectedLink && selectedLink->link) 
            {
                meaSrhMakeCall(MEA_MH_FSM, MEA_SIG_MH_MAKE_CALL_RSP, (const char *)selectedLink->link);
            }
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            break;
            
        case MEA_MMV_LINK_WRITE:
            if (selectedLink && selectedLink->link) 
            {
                meaMhWriteMessageByMail((const char *)selectedLink->link);
            }
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            break;
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MEA_MMV_MOVE_TO_ARCHIVE:
                (void)meaShowConfirmDialog(MEA_STR_ID_MOVE_TO_ARCHIVE_QUERY, NULL, MEA_MH_FSM, MEA_SIG_MH_MOVE_TO_ARCHIVE, meaGetActiveMm()->msgId);
                (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
            break;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        case MEA_MMV_NEXT_SLIDE:
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_KEY_RIGHT);
            break;
        case MEA_MMV_PREVIOUS_SLIDE:
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_KEY_LEFT);
            break;
        case MEA_MMV_PLAY_SOUND:
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_PLAY_AUDIO);
            break;
        case MEA_MMV_PLAY_VIDEO:
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_PLAY_VIDEO);
            break;
#ifdef __UNIFIED_MSG_SUPPORT__
        case MEA_MMV_SEND:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MH_FSM, MEA_SIG_MH_SEND_MSG_MR_START, (unsigned long)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
            exitMobPlayer();
#endif
            break;
        case MEA_MMV_REPLY:
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            wap_send_mmi_mms_start_uc_req(MMA_MODE_REPLY, (unsigned long)meaGetActiveMm()->msgId);
#else
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                meaGetActiveMm()->fileType, MEA_ME_STARTUP_REPLY, (unsigned long)meaGetActiveMm()->msgId);
            exitMobPlayer();
#endif
            break;
        case MEA_MMV_REPLY_SMS:
        {
            char *subject = NULL, *address = NULL;
            getMmsMsgSubAddr(MSF_MODID_WIDGET, (unsigned long)meaGetActiveMm()->msgId, &subject, &address, 250);
            if (msf_cmmn_utf8_strlen(address) > 20)  /* 20: MAX_DIGITS_SMS */
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_NUMBER_TOO_LONG), MsfError, 0);
                MSF_MEM_FREE(MSF_MODID_WIDGET, subject);
                MSF_MEM_FREE(MSF_MODID_WIDGET, address);
                break;
            }
            MSF_MEM_FREE(MSF_MODID_WIDGET, subject);
            widget_execute_MMI_p(mms_enter_sms_editor_handler, (void *)address, FALSE);
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
            break;
        }
        
        case MEA_MMV_REPLY_ALL:
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            wap_send_mmi_mms_start_uc_req(MMA_MODE_REPLY_ALL, (unsigned long)meaGetActiveMm()->msgId);
#else
            (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                meaGetActiveMm()->fileType, MEA_ME_STARTUP_REPLY_ALL, (unsigned long)meaGetActiveMm()->msgId);
            exitMobPlayer();
#endif
            break;
        case MEA_MMV_FORWARD:
            if(meaGetActiveMm()->forwardLock)
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD), MsfError, 0);
            }
            else if(fldrGetMsgSize(meaGetActiveMm()->msgId) > (MEA_CFG_MESSAGE_SIZE_MAXIMUM + 1024)) /*1KB margin*/
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_FORWARD), MsfError, 0);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                    meaGetActiveMm()->fileType, MEA_ME_STARTUP_FORWARD, (unsigned long)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                exitMobPlayer();
#endif
            }
            break;
        case MEA_MMV_EDIT:
            if(meaGetActiveMm()->forwardLock)
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD_LOCK), MsfError, 0);
            }
            else if(fldrGetMsgSize(meaGetActiveMm()->msgId) > (MEA_CFG_MESSAGE_SIZE_MAXIMUM + 1024)) /*1KB margin*/
            {
                HDIa_widgetExtShowPopup(MSF_MODID_MEA, MEA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MsfError, 0);
            }
            else
            {
                (void)MEA_SIGNAL_SENDTO_IUU(MEA_ME_FSM, MEA_SIG_ME_ACTIVATE, 
                        meaGetActiveMm()->fileType, MEA_ME_STARTUP_EDIT, (unsigned int)meaGetActiveMm()->msgId);
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                exitMobPlayer();
#endif
            }
            break;
        case MEA_MMV_DELETE:
            /* Delete message */
            (void)meaShowConfirmDialog(MEA_STR_ID_DELETE_MSG_QUEST, NULL, MEA_MH_FSM, 
                MEA_SIG_MH_DELETE_MSG, meaGetActiveMm()->msgId);
            /* Here just close menu. Only exit player after user choose to delete the msg */
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
            break;
        case MEA_MMV_DELETE_ALL:
        {
            meaDeleteAllMsg(meaGetCurrentFolder());
            /* Here just close menu. Only exit player after user choose to delete the msg */
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);  /* Delete menu */
            break;
        }
        case MEA_MMV_PROPERTIES:
            (void)MEA_SIGNAL_SENDTO_U(MEA_MV_FSM, MEA_SIG_MV_PROP_VIEW, meaGetActiveMm()->msgId);
            break;
        case MEA_MMV_USE_NUMBER:
            /* Start the SLS module, continue when the SLS is started */
            meaModuleStart(MSF_MODID_SLS, TRUE, MEA_MH_FSM, MEA_SIG_MH_SLS_RSP);        
            break;
#endif
        case MEA_MMV_SAVE:
            /* save attachment */
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_SAVE);
            break;
        case MEA_MMV_BACK:
            /* Delete menu */
            (void)MEA_SIGNAL_SENDTO(MEA_MMV_FSM, MEA_SIG_MMV_NAV_DEACTIVATE);
            break;
            
        default:
            break;
        }
    }
}            


/*!
 * \brief Create and view attachment menu 
 * \brief mo The current media object
 * \return TRUE upon success
 *****************************************************************************/
static MSF_BOOL createMenuItems(const MeaMoDataItem *mo)
{
    MeaMediaGroupType gType = MEA_MEDIA_GROUP_NONE;
    char *subject = NULL, *address = NULL;
    MeaAddrType addrType = MEA_ADDR_TYPE_NONE;
    MSF_UINT32 itemStrId = 0;
    MeaMediaGroupType drmGType = MEA_MEDIA_GROUP_NONE;

    getMmsMsgSubAddr(MSF_MODID_MEA, meaGetActiveMm()->msgId, &subject, &address, 250);
    addrType = meaGetAddrType(address);

    if (NULL != mo)
    {
        int pages = meaMobGetMoCount();
#ifndef __UNIFIED_COMPOSER_SUPPORT__
        MtrParseResult *link = mtrGetSelectedLink();

        if (link != NULL)
        {
            /* needed to convert handle to string */
            int strHandleLength;
            MsfStringHandle localStrHandle;
            char *linkStr = NULL;
            char *str = NULL;
            int item = MEA_MMV_NAV_MENU_COUNT;
            MsfStringHandle strHandle;
            
            switch (link->scheme) 
            {
            case MTR_SCHEME_HTTP:
            case MTR_SCHEME_HTTPS:
            case MTR_SCHEME_WWW:
                if (!isInCall() || (isInCall() && GetWapCallPresent()))
                {
                    localStrHandle = MEA_GET_STR_ID(SMA_STR_ID_UI_OPEN);
                    strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (localStrHandle, TRUE, MsfUtf8);
                    str = MEA_ALLOC(strHandleLength + 1);
                    MSF_WIDGET_STRING_GET_DATA (localStrHandle, str, MsfUtf8);
                    linkStr = msf_cmmn_str3cat(MSF_MODID_MEA, str, " ", link->link);
                    item = MEA_MMV_LINK_BRA;
                }
                 break;
            case MTR_SCHEME_PHONE:
                if (!isInCall() || (isInCall() && GetWapCallPresent()))
                {
                    localStrHandle = MEA_GET_STR_ID(SMA_STR_ID_UI_CALL);
                    strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (localStrHandle, TRUE, MsfUtf8);
                    str = MEA_ALLOC(strHandleLength + 1);
                    MSF_WIDGET_STRING_GET_DATA (localStrHandle, str, MsfUtf8);
                    linkStr = msf_cmmn_strcat(MSF_MODID_MEA, str, link->link);
                    item = MEA_MMV_LINK_CALL;
                }
                break;
            case MTR_SCHEME_MAIL:
                localStrHandle = MEA_GET_STR_ID(MEA_STR_ID_WRITE_MESSAGE);
                strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (localStrHandle, TRUE, MsfUtf8);
                str = MEA_ALLOC(strHandleLength + 1);
                MSF_WIDGET_STRING_GET_DATA (localStrHandle, str, MsfUtf8);
                linkStr = str;
                str = NULL;
                item = MEA_MMV_LINK_WRITE;
                break;
            default:
                linkStr = NULL;
                item = MEA_MMV_NAV_MENU_COUNT;
                break;
            }
            
            if (str != NULL)
            {
                MEA_FREE(str);
            }
            
            if (item < MEA_MMV_NAV_MENU_COUNT)
            {
                if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                    linkStr, MsfUtf8, strlen(linkStr) + 1, 0)))
                {
                    MEA_FREE(linkStr);
                    return FALSE;
                }
                MEA_FREE(linkStr);
                if (!meaAddMmvNavMenuItem(strHandle, item))
                {
                    (void)MSF_WIDGET_RELEASE(strHandle);
                    return FALSE;
                } /* if */
                (void)MSF_WIDGET_RELEASE(strHandle);        
            }

        }
#endif
        if(pages > 1)
        {
            if(meaMobGetMoIndex(mo) < pages - 1)
            {
                if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_NEXT_SLIDE), MEA_MMV_NEXT_SLIDE))
                {
                    ASSERT(0);
                }
            }
        
            if(meaMobGetMoIndex(mo) > 0)
            {
                if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PREVIOUS_SLIDE), MEA_MMV_PREVIOUS_SLIDE))
                {
                    ASSERT(0);
                }
            }
        }

        gType = meaMediaType2ObjType(mo->content.type);


#ifdef __DRM_SUPPORT__
        if (gType == MEA_MEDIA_GROUP_DRM)
        {
            gType = meaMediaType2ObjType(mo->content.drmType);
        }
#endif

        if (gType == MEA_MEDIA_GROUP_AUDIO)
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PLAY_SOUND), MEA_MMV_PLAY_SOUND))
            {
                ASSERT(0);
            }
        }

        if (gType == MEA_MEDIA_GROUP_VIDEO)
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PLAY_VIDEO), MEA_MMV_PLAY_VIDEO))
            {
                ASSERT(0);
            }
        }

    }
#ifdef __UNIFIED_MSG_SUPPORT__
    {
        MmsFileType mType = meaGetActiveMm()->fileType;
        MmsFolderType folder = fldrGetFolderId(meaGetActiveMm()->msgId);
        	
        /* SEND */
        if ((mType == MMS_SUFFIX_SEND_REQ) && (MEA_FOLDER_TEMPLATE != folder) && (MEA_FOLDER_SENT != folder)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        && (MEA_FOLDER_ARCHIVE!= folder)
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        && (MEA_FOLDER_USER_TEMPLATE != folder)
#endif
        )
        {
           if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_SEND), MEA_MMV_SEND))
           {
               ASSERT(0);
           }
        }
        
#ifndef __UNIFIED_MESSAGE_MMS_REPLY_BY_SMS_FIRST__
        /* REPLY */
        if ((mType == MMS_SUFFIX_MSG) && (addrType != MEA_ADDR_TYPE_NONE))
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY), MEA_MMV_REPLY))
            {
                ASSERT(0);
            }
        }
#endif

        /* REPLY by SMS */
        if ((mType == MMS_SUFFIX_MSG) && (addrType == MEA_ADDR_TYPE_PLMN))
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY_SMS), MEA_MMV_REPLY_SMS))
            {
                ASSERT(0);
            }
        }

#ifdef __UNIFIED_MESSAGE_MMS_REPLY_BY_SMS_FIRST__
        /* REPLY */
        if ((mType == MMS_SUFFIX_MSG) && (addrType != MEA_ADDR_TYPE_NONE))
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY), MEA_MMV_REPLY))
            {
                ASSERT(0);
            }
        }
#endif
        
        /* REPLY_ALL - should only be visible when several recipients exists: CR to be written */
        if ((mType == MMS_SUFFIX_MSG) && (addrType != MEA_ADDR_TYPE_NONE))
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_REPLY_TO_ALL), MEA_MMV_REPLY_ALL))
            {
                ASSERT(0);
            }
        }
    
        /* FORWARD */
        if (((mType == MMS_SUFFIX_MSG) || (MEA_FOLDER_SENT == folder)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            || ((MEA_FOLDER_ARCHIVE == folder) && (mType != MMS_SUFFIX_DELIVERYREPORT))
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
            )
            && (!meaGetActiveMm()->forwardLock)
        )
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_FORWARD), MEA_MMV_FORWARD))
            {
                ASSERT(0);
            }
        }
        
        /* EDIT */
        if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT), MEA_MMV_EDIT))
        {
            ASSERT(0);
        }
    
        /* DELETE */
        if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE), MEA_MMV_DELETE))
        {
            ASSERT(0);
        }
    
        /* DELETE ALL */
        if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_ALL), MEA_MMV_DELETE_ALL))
        {
            ASSERT(0);
        }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (MEA_FOLDER_INBOX == folder || MEA_FOLDER_SENT == folder)
        {
            if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_MOVE_TO_ARCHIVE), MEA_MMV_MOVE_TO_ARCHIVE))
            {
                ASSERT(0);
            }
        }         
#endif  /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/ 
        /* PROPERTIES */
        if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_PROPERTIES), MEA_MMV_PROPERTIES))
        {
            ASSERT(0);
        }
    }
#endif

    /* Save Object */
    if(mo != NULL && mo->size > 0)
    {
        if (gType == MEA_MEDIA_GROUP_TEXT)
        {
            itemStrId = SMA_STR_ID_MENU_SAVE_TEXT;
        }
        else if (gType == MEA_MEDIA_GROUP_IMAGE)
        {
            itemStrId = SMA_STR_ID_MENU_SAVE_IMAGE;
        }
        else if (gType == MEA_MEDIA_GROUP_AUDIO)
        {
            itemStrId = SMA_STR_ID_MENU_SAVE_AUDIO;
        }
        else if (gType == MEA_MEDIA_GROUP_VIDEO)
        {
            itemStrId = SMA_STR_ID_MENU_SAVE_VIDEO;
        }
    #ifdef __DRM_SUPPORT__
        else if (gType == MEA_MEDIA_GROUP_DRM)
        {
            drmGType = meaMediaType2ObjType(mo->content.drmType);
            switch(drmGType)
            {
            case MEA_MEDIA_GROUP_TEXT:
                itemStrId = SMA_STR_ID_MENU_SAVE_TEXT;
                break;
            case MEA_MEDIA_GROUP_IMAGE:
                itemStrId = SMA_STR_ID_MENU_SAVE_IMAGE;
                break;
            case MEA_MEDIA_GROUP_AUDIO:
                itemStrId = SMA_STR_ID_MENU_SAVE_AUDIO;
                break;
            case SMA_STR_ID_MENU_SAVE_VIDEO:
                itemStrId = SMA_STR_ID_MENU_SAVE_VIDEO;
                break;
            default:
                itemStrId = SMA_STR_ID_MENU_SAVE_OBJECT;
            }
        }
    #endif
        else
        {
            itemStrId = SMA_STR_ID_MENU_SAVE_OBJECT;
        }

        if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(itemStrId), MEA_MMV_SAVE))
        {
            return FALSE;
        }
    }

#ifdef __UNIFIED_MSG_SUPPORT__
    /* USE NUMBER*/
    if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_USE_DETAILS), MEA_MMV_USE_NUMBER))
    {
        ASSERT(0);
    }
#endif
#ifndef __UNIFIED_MSG_SUPPORT__
    /* Back */
    if ((NULL == mo ) && meaMobGetMoCount() <= 1) /* no need to create menu */
    {
        if (!meaAddMmvNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_BACK), MEA_MMV_BACK))
        {
            ASSERT(0);
        }
    }
#endif /* ~__UNIFIED_MSG_SUPPORT__ */

    MEA_FREE(subject);
    MEA_FREE(address);
    return TRUE;
}

/*!
 * \brief Create and view attachment menu 
 * \brief mo The current media object
 * \return TRUE upon success
 *****************************************************************************/
MSF_BOOL meaUiMmvCreateMenu(const MeaMoDataItem *mo)
{
  /* title will be set in meaShowMmvNavMenu */
	if (!meaCreateMmvNavMenu(0,   navMenuSignalConverter))
    {
        meaRemoveMmvNavMenu();
        return FALSE;  
    }
    else if (!createMenuItems(mo))
    {
        meaRemoveMmvNavMenu();
        return FALSE;
    }
    else if (!meaShowMmvNavMenu())
    {
        meaRemoveMmvNavMenu();
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief Deletes the navigation menu for the multipart/mixed msg viewer.
 *
 *****************************************************************************/
void meaUiMmvDeleteMenu(void)
{
    meaRemoveMmvNavMenu();
}


/*!
 * \brief Initiates the data-structures for the multipart/mixed message viewer.
 *****************************************************************************/
void meaMmvUiInit(void)
{
    return;
}

