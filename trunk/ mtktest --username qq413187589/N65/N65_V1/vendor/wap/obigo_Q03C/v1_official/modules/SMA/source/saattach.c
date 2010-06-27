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

/*--- Include files ---*/
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_mem.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"    /* Widget*/
#endif

#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

#include "sma_if.h"
#include "sma_rc.h"
#include "satypes.h"
#include "samain.h"
#include "samem.h"
#include "saui.h"
#include "sma_cfg.h"
#include "saintsig.h"
#include "sapipe.h"
#include "sauisig.h"
#include "samenu.h"
#include "saattach.h"
#ifdef WAP_SUPPORT
#ifdef __UNIFIED_MSG_SUPPORT__
#include "smtrcmn.h"
#endif
#include "sauidia.h"    /* for SMA_DIALOG_ALERT */
#include "mea_def.h"    /* for MEA_SMIL_FILE_NAME */
#include "mms_def.h"    /* for MMS_MEDIA_TYPE_STRING_SMIL */
extern MSF_BOOL meaSmilEditorIsActive(void);

#include "msf_pck.h"    /* for msf_pck_result_t */
#include "msf_act.h"    /*for msf_act_init */
#include "msf_file.h"  /* For MSF_FILE_OPEN */
#include "widget.h"  /* for virtual file */

static msf_pck_handle_t* smaActHandle;
#endif /* WAP_SUPPORT */
/*--- Types ---*/
typedef struct 
{

    SlsUnrefItemList *attachmentList;
#ifdef __UNIFIED_MSG_SUPPORT__
    SlsUnrefItemList *image;
    SlsUnrefItemList *audio;
    SlsUnrefItemList *video;
    SlsUnrefItemList *text;
#else
    SlsUnrefItemList *crData;
#endif
    MSF_INT32 fileHandle;  /* MMS file handle to create virtual file */
}InstanceData;
/******************************************************************************
 * Constants
 *****************************************************************************/
static const SmaAttachmentTypeItem supportedAttachmentTypes[] = 
    SMA_CFG_ATTACHMENT_MEDIA_TYPES;

static SmaMenu attachmentMenu;
static InstanceData instData;

/*--- Definitions/Declarations ---*/
/*--- Prototypes ---*/
static void attachmentMenuOkActionHandler(MsfWindowHandle winHandle);
static void attachmentMenuBackActionHandler(MsfWindowHandle winHandle);
static void sigHandler(SmaSignal *sig);
static char *smaCreateFileName(const char *extension);
static const char *getFileEndingFromMimeType(char *mimeType);
#ifdef __UNIFIED_MSG_SUPPORT__
static void releaseObject(void);
#else
static MSF_BOOL createAttachmenMenuItems(SmaMenu *smaMenuHandle, 
    SlsUnrefItemList *attachmentList);
#endif


/*!
 * \brief Initialize the SMA_FSM_ATTACHMENT.
 *****************************************************************************/
void smaAttachmentInit(void)
{
    smaSignalRegisterDst(SMA_FSM_ATTACHMENT, sigHandler);
    memset(&attachmentMenu, 0x00, sizeof(SmaMenu));
    memset(&instData, 0x00, sizeof(InstanceData));
   
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
        SAATTACH_D0941CBE6CC4993092FAFC54EA2BCB07, "SMA_FSM_ATTACHMENT: initialized\n"));
} /* smaAttachmentInit */

/*!
 * \brief Terminate the M_FSM_CORE_MAIN FSM.
 *****************************************************************************/
void smaAttachmentTerminate(void)
{
	smaSignalDeregister(SMA_FSM_ATTACHMENT);
    smaRemoveMenu(&attachmentMenu);
#ifdef __UNIFIED_MSG_SUPPORT__
    releaseObject();
#endif
    MSF_FILE_CLOSE(instData.fileHandle);
    instData.fileHandle = 0;
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
        SAATTACH_7A3D0269135D5FFBF3E0749A71D28D30, "SMA_FSM_ATTACHMENT: terminated\n"));
} /* smaAttachmentTerminate */

MSF_BOOL smaIsSupportedAttachment(char *mimeType)
{
    int i = 0;

    if(mimeType == NULL)
    {
        return FALSE;
    }
    
    while(NULL != supportedAttachmentTypes[i].mimeType)
    {
        if(msf_cmmn_strcmp_nc(mimeType, supportedAttachmentTypes[i].mimeType) == 0)
        {
            return TRUE;
        }
        ++i;
    }
    return FALSE;
}
/*!
 * \brief Signal handler for the SMA_FSM_PIPE.
 *****************************************************************************/
static void sigHandler(SmaSignal *sig)
{
    switch (sig->type)
    {
    case SMA_SIG_ATTACHMENT_CR_SEND:
        startContentRouting((SlsUnrefItemList *)sig->p_param);
        break;
    default:
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
            SAATTACH_56EFFEC58A26281E333C474FFA98FE74, "(%s) (%d) Erroneous signal recieved in SMA_FSM_PIPE:sigHanlder\n", 
            __FILE__, __LINE__));
        break;
    } /* switch */
	smaSignalDelete(sig);
} /* sigHandler */

void smaActTerminate(void)
{
  if (smaActHandle)
  {
    msf_act_terminate (smaActHandle);
    smaActHandle = NULL;
  }
}

void startContentRouting(SlsUnrefItemList *attachment)
{

    SmaPlayerInfo   *playerInfo;
    MSF_INT32             actId;
    msf_pck_result_t      result;
    char *vFileName = NULL;

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, SAATTACH_F0D4A639B7152F6732D8AAB9F3B5E552, "(%s) (%d) startContentRouting(): %s (Type %d)\n", 
        __FILE__, __LINE__, attachment->fileName, attachment->mediaType));

    playerInfo = getPlayerInfo();

    vFileName = SMA_ALLOC(WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);

    if(instData.fileHandle <= 0)
    {
        instData.fileHandle = MSF_FILE_OPEN( MSF_MODID_SMA, playerInfo->filePath, MSF_FILE_SET_RDONLY, 0);
        if(instData.fileHandle < 0)
        {
            SMA_FREE(vFileName);
            instData.fileHandle = 0;
            HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(SMA_STR_ID_FAILED_TO_SAVE), MsfAlert, 0);
            return;
        }
    }

    if(HDIa_fileGenVirtualFileName(instData.fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, attachment->offset, attachment->size) != HDI_FILE_OK)
    {
        SMA_FREE(vFileName);
        MSF_FILE_CLOSE(instData.fileHandle);
        instData.fileHandle = 0;
        HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(SMA_STR_ID_FAILED_TO_SAVE), MsfAlert, 0);
        return;
    }
    
    smaActHandle = (msf_pck_handle_t*)msf_act_init(MSF_MODID_SMA);
    actId = msf_act_object_action_drm (smaActHandle,
                   0,
                   attachment->contentType,
                   MsfResourceFile,
                   NULL,
                   attachment->size,
                   vFileName,
                   NULL,
                   attachment->fileName,
                   0, //for drm
                   smaGetScreenHandle(),
                   NULL,
                   NULL,
                   0);

    msf_act_get_result (smaActHandle, actId, &result);
    msf_act_result_free (smaActHandle, &result);
    smaActTerminate();
    SMA_FREE(vFileName);
} /* startContentRouting */

msf_pck_handle_t* smaGetActHandle(void)
{
    return smaActHandle;
}

/*!
 * \brief Creates the context sensitive menu for the message handler.
 *
 * \param  folder The folder that i currently active.
 * \return TRUE if the operation was successful, otherwise FALSE.
  *****************************************************************************/
#ifdef __UNIFIED_MSG_SUPPORT__
/*!
 * \brief Get a media object in a slide by its object type
 * 
 * \param objType (IN): Type of object.
 * \param slideInfo (IN): Information about the slide
 * \return the object if there's matched object otherwise NULL.
 *****************************************************************************/
static SmaObjectInfo *getObjectByType(SlsMediaObjectType objType, SmaSlideInfo *slideInfo)
{
    SmaObjectInfo *objInfo = &slideInfo->object;

    if(slideInfo == NULL || objType == SLS_OBJECT_TYPE_NONE)
    {
        return NULL;
    }

    while (objInfo)
    {
        if (objInfo->type == objType) 
        {
            return objInfo;
        }
        
        objInfo = objInfo->next;
    }
    return NULL;
}

static void releaseObject()
{
    /* attachment need not to be released cuz it uses slide structure */
    if(instData.image)
    {
        SMA_FREE(instData.image);
        instData.image = NULL;
    }
    
    if(instData.audio)
    {
        SMA_FREE(instData.audio);
        instData.audio = NULL;
    }
    
    if(instData.video)
    {
        SMA_FREE(instData.video);
        instData.video = NULL;
    }

    if(instData.text)
    {
        SMA_FREE(instData.text);
        instData.text = NULL;
    }
}

/*!
 * \brief Get the MIME type for image/audio/video object.
 * 
 * \param mediaType SmaMediaType to get mime type to.
 * \return MIME type.
 *****************************************************************************/
static const char *getMimeType(SlsMediaType mediaType)
{
    unsigned int i;
    const SmaMediaTypeItem *item;

    i = 0;
    item = smaGetSupportedMediaTypes();
    while(SLS_NOT_USED != item[i].slsMediaType)
    {
        if (mediaType == item[i].slsMediaType)
        {
            return item[i].mimeType;
        }
        ++i;
    }
    return MEA_UNKNOWN_MIME_STR;
}

/*!
 * \brief Get information about a media object (image/audio/video).
 * 
 * \param size (OUT): The size of the media object
 * \param startPos (OUT): The start position for the media object
 * \param fileType (OUT): Media type, e.g. jpg, wav
 * \param fileName	(OUT): file	Name for the object.
 * \param boundary (OUT): The DRM boundary or NULL.
 * \param objInfo (IN): Information about the media object
 * \param objType (IN): Type of object.
 * \return TRUE if object info is available otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL getObjectInfo(MSF_UINT32 *size, MSF_UINT32 *startPos, 
    MSF_UINT32 *fileType, char **fileName, char **boundary,
	const SmaObjectInfo *objInfo, SlsMediaObjectType objType)
{
    *fileName = NULL;
    while (objInfo)
    {
        if (objInfo->type == objType) 
        {
            if (objType == SLS_OBJECT_TYPE_IMAGE)
            {
                *size = objInfo->info.image.size;
                *startPos = objInfo->info.image.offset;
                *fileType = objInfo->info.image.type;

                if (SLS_NOT_USED == *fileType)
                {
                    break;
                }
            }
            else if (objType == SLS_OBJECT_TYPE_VIDEO)
            {
                *size = objInfo->info.video.size;
                *startPos = objInfo->info.video.offset;
                *fileType = objInfo->info.video.type;

                if (SLS_NOT_USED == *fileType)
                {
                    break;
                }
            }
            else if (objType == SLS_OBJECT_TYPE_AUDIO)
            {
                *size = objInfo->info.audio.size;
                *startPos = objInfo->info.audio.offset;
                *fileType = objInfo->info.audio.type;
                
                if (SLS_NOT_USED == *fileType)
                {
                    break;
                }
            }
            else if (objType == SLS_OBJECT_TYPE_TEXT)
            {
                *size = objInfo->info.text.size;
                *startPos = objInfo->info.text.offset;
                *fileType = objInfo->info.text.type;
                
                if (SLS_NOT_USED == *fileType)
                {
                    break;
                }
            }
            else
            {
                return FALSE;
            }
            		
            /* copy the filename */
            if (objInfo->fileName != NULL)
            {
                *fileName = msf_cmmn_strdup(MSF_MODID_SMA, objInfo->fileName);
            }
    
            /* copy the boundary pointer */
            *boundary = objInfo->boundary;
    
            return TRUE;
        } 
        else
        {
            objInfo = objInfo->next;
        }
    } /* while */
    return FALSE;
} /* getObjectnfo */

/*!
 * \brief Creates content route information for image/audio/video object
 *
 * \param obj image/audio/video object
 * \return content route data by using SlsUnrefItemList structure
 *****************************************************************************/
static SlsUnrefItemList *createContentRoutingData(SmaObjectInfo *obj)
{
    MSF_UINT32 size = 0, startPos = 0, type = 0;
    char *fileName = NULL, *boundary = NULL;
    SlsUnrefItemList *data = NULL;

    /* get information for content routing operation */
    getObjectInfo(&size, &startPos, &type, &fileName, &boundary, obj, obj->type);

    /* create content routing structure */
    {
        const char *mimeType = getMimeType((SlsMediaType)type);
        data = SMA_ALLOC(sizeof(SlsUnrefItemList));
        ASSERT(data != NULL);
        
        if (data)
        {
            data->contentType = msf_cmmn_strdup(MSF_MODID_SMA, mimeType);
            data->fileName = msf_cmmn_strdup(MSF_MODID_SMA, fileName);
            data->mediaType = (SlsMediaType)type;
            data->next = NULL;
            data->offset = startPos;
            data->size = size;
        }
    }                    

    if (fileName != NULL)
    {
        SMA_FREE(fileName);
        fileName = NULL;
    }

    return data;
}

/*!
 * \brief Creates menu items
 *
 * \param  smaMenuHandle The menu to add items to.
 * \param attachmentList The list of items to add.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createObjectMenuItems(SmaMenu *smaMenuHandle, SmaSlideInfo *slide, SlsUnrefItemList *attachmentList)
{
    int index = 0;
    MSF_UINT32 strHandle = 0;
    const char *ending;

    releaseObject();  /* release content rounting data allocated last time */
    instData.attachmentList = attachmentList;
    
    /* Add content to the menu*/
    if ((smaMenuHandle == NULL) || (attachmentList == NULL && slide == NULL)) 
    {
        return FALSE;
    }

    /* image / audio / video /text */
    if(slide != NULL)
    {
        /* Save text */
        if(checkObjectType(SLS_OBJECT_TYPE_TEXT, slide))
        {
            instData.text = createContentRoutingData(getObjectByType(SLS_OBJECT_TYPE_TEXT, slide));
            if (instData.text == NULL || !smaAddMenuItem(smaMenuHandle, SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_TEXT), index))
            {
                return FALSE;
            }
            index++;
        }

        /* Save image */
        if(checkObjectType(SLS_OBJECT_TYPE_IMAGE, slide))
        {
            instData.image = createContentRoutingData(getObjectByType(SLS_OBJECT_TYPE_IMAGE, slide));
            if (instData.image == NULL || !smaAddMenuItem(smaMenuHandle, SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_IMAGE), index))
            {
                return FALSE;
            }
            index++;
        }

        /* Save audio */
        if(checkObjectType(SLS_OBJECT_TYPE_AUDIO, slide))
        {
            instData.audio = createContentRoutingData(getObjectByType(SLS_OBJECT_TYPE_AUDIO, slide));
            if (instData.audio == NULL || !smaAddMenuItem(smaMenuHandle, SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_AUDIO), index))
            {
                return FALSE;
            }
            index++;
        }

        /* Save video */
        if(checkObjectType(SLS_OBJECT_TYPE_VIDEO, slide))
        {
            instData.video = createContentRoutingData(getObjectByType(SLS_OBJECT_TYPE_VIDEO, slide));
            if (instData.video == NULL || !smaAddMenuItem(smaMenuHandle, SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_VIDEO), index))
            {
                return FALSE;
            }
            index++;
        }
    }

    /* create menu item for attachment */
    while (attachmentList != NULL)
    {
        strHandle = 0;
        if(msf_cmmn_strcmp_nc(attachmentList->contentType, MMS_MEDIA_TYPE_STRING_SMIL) == 0)
        {
            attachmentList = attachmentList->next;
            continue;
        }
        else if (attachmentList->fileName != NULL)
        {
            char *prefix = NULL, *str = NULL;
            if (NULL == (prefix = smtrGetStringBufferFromHandle(SMA_GET_STR_ID(MEA_STR_ID_ATTACH_TITLE))))
            {
                return FALSE;
            }

            str = msf_cmmn_str3cat(MSF_MODID_SMA, prefix, (char *)"-", attachmentList->fileName);
            strHandle = smaCreateString(str);
            SMA_FREE(str);
            SMA_FREE(prefix);
        }
        else     /* generate a name */
        {
            char *fileName = NULL;
            ending = getFileEndingFromMimeType(attachmentList->contentType);
            fileName = smaCreateFileName(ending);
            if(fileName)
            {
                char *prefix = NULL, *str = NULL;
                if (NULL == (prefix = smtrGetStringBufferFromHandle(SMA_GET_STR_ID(MEA_STR_ID_ATTACH_TITLE))))
                {
                    return FALSE;
                }
                str = msf_cmmn_str3cat(MSF_MODID_SMA, prefix, (char *)"-", fileName);
                strHandle = smaCreateString(str);
                SMA_FREE(str);
                SMA_FREE(prefix);
                SMA_FREE(fileName);
                fileName = NULL;
            }
        }
         
        if(strHandle)
        {
            if (!smaAddMenuItem(smaMenuHandle, strHandle, index))
            {
                // return FALSE;
                break;  /* Exceeds 20 items */
            }
            index++;
        }
        attachmentList = attachmentList->next;
    } /* while */

    if(index == 0)
    {
        HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_EMPTY), MsfPromptEmpty, 0);
        return FALSE;
    }
    return TRUE;
} /* createAttachmenMenuItems */

MSF_BOOL smaCreateObjectMenu(SmaSlideInfo *slide)
{
    MsfActionHandle handle = 0;
    SmaPlayerInfo *playerInfo;

    playerInfo = getPlayerInfo();

    if (attachmentMenu.menuHandle != 0)
    {
        return FALSE;
    }
    
    /* Create menu */
    if (!smaCreateMenu(&attachmentMenu, SMA_NAV_MENU, SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_OBJECT), 
        SMA_GET_STR_ID(SMA_STR_ID_SLIDE_MENU_ACTION_SELECT), attachmentMenuOkActionHandler))
    {
        smaRemoveMenu(&attachmentMenu);
        return FALSE;
    }

    handle  = smaCreateAction(attachmentMenu.menuHandle, MsfBack, 
        attachmentMenuBackActionHandler, 0, 0, SMA_STR_ID_SLIDE_MENU_ACTION_BACK);

    if (handle == 0)
    {
        smaRemoveMenu(&attachmentMenu);
        return FALSE;
    }
	
    if (!createObjectMenuItems(&attachmentMenu, slide, playerInfo->unrefList))
    {
        releaseObject();
        smaRemoveMenu(&attachmentMenu);
        return FALSE;
    }
	
    smaMenuSetSelected(&attachmentMenu, 0);
	
    if (!smaShowMenu(attachmentMenu.menuHandle))
    {
        releaseObject();
        smaRemoveMenu(&attachmentMenu);
        return FALSE;
    }
    return TRUE;
} /* createAttachmentMenu */

#else
MSF_BOOL smaCreateAttachmentMenu(void)
{
    MsfActionHandle handle = 0;
    SmaPlayerInfo *playerInfo;

    playerInfo = getPlayerInfo();
    playerInfo->isNotified = TRUE;

	if (attachmentMenu.menuHandle != 0)
    {
        return FALSE;
    } /* if */
    
    /* Create menu */
#ifdef WAP_SUPPORT
    if (!smaCreateMenu(&attachmentMenu, SMA_NAV_MENU, 
        SMA_GET_STR_ID(SMA_STR_ID_ATTACHMENT_LIST), 
        (meaSmilEditorIsActive())?0:SMA_GET_STR_ID(SMA_STR_ID_SLIDE_MENU_ACTION_SELECT), 
        attachmentMenuOkActionHandler))
#else
    if (!smaCreateMenu(&attachmentMenu, SMA_NAV_MENU, 
        SMA_GET_STR_ID(SMA_STR_ID_ATTACHMENT_LIST), 
        SMA_GET_STR_ID(SMA_STR_ID_SLIDE_MENU_ACTION_SELECT), 
        attachmentMenuOkActionHandler))
#endif
    {
        smaRemoveMenu(&attachmentMenu);
        return FALSE;
    } /* if */

    handle  = smaCreateAction(attachmentMenu.menuHandle, MsfBack, 
        attachmentMenuBackActionHandler, 0, 0, SMA_STR_ID_SLIDE_MENU_ACTION_BACK);

	if (handle == 0)
	{
		smaRemoveMenu(&attachmentMenu);
        return FALSE;
	} /* if */
	
    if (!createAttachmenMenuItems(&attachmentMenu, playerInfo->unrefList))
    {
		/* error */
		smaRemoveMenu(&attachmentMenu);
        return FALSE;
    } /* if */
	
	smaMenuSetSelected(&attachmentMenu, 0);
	
	if (!smaShowMenu(attachmentMenu.menuHandle))
    {
        smaRemoveMenu(&attachmentMenu);
        return FALSE;
    } /* if */
    return TRUE;
} /* createAttachmentMenu */

/*!
 * \brief Creates menu items
 *
 * \param  smaMenuHandle The menu to add items to.
 * \param attachmentList The list of items to add.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createAttachmenMenuItems(SmaMenu *smaMenuHandle, SlsUnrefItemList *attachmentList)
{
    int index = 0;
    MSF_UINT32 strHandle = 0;
    const char *ending;

    instData.attachmentList = attachmentList;
    
    /* Add content to the menu*/
    if ((smaMenuHandle == NULL) || (attachmentList == NULL)) 
    {
        return FALSE;
    }

    while (attachmentList != NULL && index < SMA_MAX_CONTEXT_LIST_ITEMS)
    {
        strHandle = 0;
        
        if(msf_cmmn_strcmp_nc(attachmentList->contentType, MMS_MEDIA_TYPE_STRING_SMIL) == 0)
        {
            attachmentList = attachmentList->next;
            continue;
        }
        
        if (attachmentList->fileName != NULL)
        {
            strHandle = smaCreateString(attachmentList->fileName);
        }
        else     /* generate a name */
        {
            char *fileName = NULL;
            ending = getFileEndingFromMimeType(attachmentList->contentType);
            fileName = smaCreateFileName(ending);
            if(fileName)
            {
                strHandle = smaCreateString(fileName);
                SMA_FREE(fileName);
                fileName = NULL;
            }
        }
         
        if(strHandle)
        {
            if (!smaAddMenuItem(smaMenuHandle, strHandle, index))
            {
                return FALSE;
            }
        }
        attachmentList = attachmentList->next;
        index++;
    } /* while */
    return TRUE;
} /* createAttachmenMenuItems */
#endif


static const char *getFileEndingFromMimeType(char *mimeType)
{
    int i = 0;

    while(NULL != supportedAttachmentTypes[i].mimeType)
    {
        if(msf_cmmn_strcmp_nc(mimeType, supportedAttachmentTypes[i].mimeType) == 0)
        {
            return supportedAttachmentTypes[i].ending;
        }
        ++i;
    }
    return NULL;
} /* getFileEndingFromMediaType */

/*!
 * \brief Action handler for "Ok"-operation.
 *
 *****************************************************************************/
static void attachmentMenuOkActionHandler(MsfWindowHandle winHandle)
{
    int                 contextIndex    = 0;
    SlsUnrefItemList    *listPtr        = instData.attachmentList;

#ifdef __UNIFIED_MSG_SUPPORT__
    /* the link list order is the SAME as menu item order */
    if(instData.video)
    {
        instData.video->next = listPtr;
        listPtr = instData.video;
    }

    if(instData.audio)
    {
        instData.audio->next = listPtr;
        listPtr = instData.audio;
    }

    if(instData.image)
    {
        instData.image->next = listPtr;
        listPtr = instData.image;
    }

    if(instData.text)
    {
        instData.text->next = listPtr;
        listPtr = instData.text;
    }

    if (listPtr->mediaType == SLS_NOT_USED)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, SAATTACH_DCA88B568478B08A68E4CD8A56B06207, "(%s) (%d) Unknown type\n", __FILE__, __LINE__));
        (void)smaShowDialog(SMA_STR_ID_FAILED_TO_SAVE, SMA_DIALOG_ERROR);
        smaRemoveMenu(&attachmentMenu);
        return;
    }
#endif

    (void)winHandle;
    
	contextIndex = smaGetMenuItem(&attachmentMenu);

    while(NULL != listPtr)
    {
        if(msf_cmmn_strcmp_nc(listPtr->contentType, MMS_MEDIA_TYPE_STRING_SMIL) == 0)
        {
            listPtr = listPtr->next;
            continue;
        }

        if(contextIndex > 0)
        {
            listPtr = listPtr->next;
            --contextIndex;
        }
        else
        {
            break;
        }
    }
    
    if (listPtr)
    {
        (void)SMA_SIGNAL_SENDTO_P(SMA_FSM_ATTACHMENT, SMA_SIG_ATTACHMENT_CR_SEND, listPtr);
        smaRemoveMenu(&attachmentMenu);
    }
    else
    {
        /* just delete current menu, should never happen... */
        smaRemoveMenu(&attachmentMenu);        
    }
    
} /* attachmentMenuOkActionHandler */


/*!
 * \brief Action handler for "Back"-operation.
 *
 *****************************************************************************/
static void attachmentMenuBackActionHandler(MsfWindowHandle winHandle)
{
    (void)winHandle;

	smaRemoveMenu(&attachmentMenu); /* delete current menu */
#ifdef __UNIFIED_MSG_SUPPORT__
	releaseObject();
#endif
}


/*!
 * \brief Generates a name for a file
 * \param extension What extension to set on the file. (max 3 char)
 * \return The name or NULL on error
 *****************************************************************************/
static char *smaCreateFileName(const char *extension)
{
    char *name = NULL;
    unsigned int size = 0;
    static MSF_UINT32 counter; /* Initialized to zero at start-up */
    MSF_UINT32 currentTime = 0;
    unsigned int extensionSize = 0;

    if (NULL == extension)
    {
        return NULL;
    }

    extensionSize = strlen(extension);
    /* create name for text */
    currentTime = MSF_TIME_GET_CURRENT();

    /* current-time + "." + extension + NULL */
    size = (sizeof(MSF_UINT32)*2 + 1 + extensionSize + 1);
    
    name = SMA_ALLOC((unsigned long)size);
    memset(name, 0, size);
    /*lint -e{727} */
    sprintf(name, "%lx.%s", (long)(currentTime<<8)|(counter&0xff), 
        extension);
    /* Use a counter to prevent problems if the CPU is to fast, i.e., 
       the timer has not been increased between two calls, 256 calls
       to meaCreatefileName during the same time is not likely */
    ++counter;
    return name;
} /* smaCreateFileName */

char *smaGetAttachment(char *filename)
{
    SmaPlayerInfo *playerInfo = getPlayerInfo();
    SlsUnrefItemList *attachmentList = playerInfo->unrefList;
    int index = 0;
 
    while (attachmentList != NULL && index < SMA_MAX_CONTEXT_LIST_ITEMS)
    {
        if(msf_cmmn_strcmp_nc(attachmentList->fileName, filename) == 0)
        {
            char *vFileName = NULL;
            
            vFileName = SMA_ALLOC(WIDGET_RAWFILE_NAMELEN);
            ASSERT(vFileName != NULL);

            if(instData.fileHandle <= 0)
            {
                instData.fileHandle = MSF_FILE_OPEN( MSF_MODID_SMA, playerInfo->filePath, MSF_FILE_SET_RDONLY, 0);
                if(instData.fileHandle < 0)
                {
                    SMA_FREE(vFileName);
                    instData.fileHandle = 0;
                    return NULL;
                }
            }

            if(HDIa_fileGenVirtualFileName(instData.fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, attachmentList->offset, attachmentList->size) != HDI_FILE_OK)
            {
                SMA_FREE(vFileName);
                MSF_FILE_CLOSE(instData.fileHandle);
                instData.fileHandle = 0;
                return NULL;
            }
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, SAATTACH_439AE7B67A814DA7A4C958BA877D867D, "(%s) (%d) smaGetAttachment(%s) found\n", __FILE__, __LINE__, filename));
                return vFileName;  /* should be released in caller */
            }
        }
        attachmentList = attachmentList->next;
        index++;
    }
	return NULL;
}
