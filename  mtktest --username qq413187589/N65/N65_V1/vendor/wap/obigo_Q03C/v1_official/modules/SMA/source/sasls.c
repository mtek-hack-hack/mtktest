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
/* MMS */
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_def.h"    /* MSF: Global definitions */ 
#include "msf_core.h"   /* MSF: System core call */ 
#include "msf_dcvt.h"   /* MSF: Type conversion routines */ 
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */ 

#include "Mms_def.h"
#include "Mmsl_if.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* SMA */
#include "sma_if.h"
#include "sma_cfg.h"  /* for SMA_CFG_SUPPORTED_MEDIA_TYPES */
#include "satypes.h"
#include "samem.h"
#include "samain.h"
#include "sasls.h"
#include "saui.h"
#include "saattach.h"  /* smaIsSupportedAttachment */
#if SMA_USE_BEST_SLIDE_DURATION == 1
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "widget.h"
#include "msf_file.h"
#include "fs_errcode.h"
#include "wapadp.h"
#endif

/*--- Definitions/Declarations ---*/

/*--- Types ---*/
typedef struct
{
    SlsMediaType type;          /*!< Type of MO */	
    MSF_UINT32   size;          /*!< Size of MO in bytes */
    MSF_UINT32   offset;        /*!< Offset of MO in the MO data file */
    char		 *fileName;     /*!< FileName */
    char         *boundary;     /*!< The boundary, used for DRM */

    SlsRegion    region;        /*!< Positioning of the MO  */
    char		 *alt;	        /*!< alt param */
    MSF_UINT32   charset;       /*!< Char-set of text */
    MSF_UINT32   color;			/*!< Text color */
} SmaCommMediaObject;

/*--- Constants ---*/
#define SMA_DEFOUT_AUDIO_DURATION   3

/*--- Forwards ---*/

/*--- Externs ---*/
extern const char *meaFileName2MimeType(const char *filename);  /* Steal MEA function. It's utility function, should be fine ... */
extern void meaTransformIllegalFileName(char *name);
extern MmsFileType fldrGetFileSuffix(MmsMsgId msgId);

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

/*--- Functions ---*/
void updateRegion(SmaObjectInfo *object);
static SlsUnrefItemList *copySlsUnrefList(SlsUnrefItemList *sourceList);
SlsMediaType getSlsMediaTypeFromFileName(const char *filename);

/*! \brief handle information about the smil message and 
 *   prepare to retrieve media objects
 *  \return result of the operation
 *****************************************************************************/
SmaResult handleOpenSmilRsp (SmaPlayerInfo *playerInfo, 
    const SlsOpenSmilRsp *openSmilRsp)
{
    SmaResult result = SMA_RESULT_OK;

	if (openSmilRsp == NULL)
	{
		MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
			SASLS_DD5C38D1A168F246E47E25F529D0E0A3, "SMA: SLS failed to open SMIL in SLS_OPEN_SMIL_RSP\n"));
        return SMA_RESULT_ERROR;
	} /* if */

#if SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES//==1
    if ((openSmilRsp->result == SLS_RESULT_OK ||  openSmilRsp->result ==SLS_RESULT_TO_MANY_SLIDES )&& 
        openSmilRsp->noOfSlides > 0)
#else
     if (openSmilRsp->result == SLS_RESULT_OK && openSmilRsp->noOfSlides > 0)

#endif 
    {
		playerInfo->result = openSmilRsp->result;
        playerInfo->noOfSlides = openSmilRsp->noOfSlides;
        playerInfo->currentSlide = SMA_FIRST_SLIDE;
        playerInfo->rootSize.height = openSmilRsp->rootLayout.cy.value;
        playerInfo->rootSize.width = openSmilRsp->rootLayout.cx.value;
        playerInfo->filePath = SMA_ALLOC(strlen(openSmilRsp->file) + 1);
        playerInfo->rootBgColor = openSmilRsp->rootLayout.bgColor;
		strcpy(playerInfo->filePath, openSmilRsp->file);

		playerInfo->unrefList = copySlsUnrefList(openSmilRsp->unrefItems);
        
        /* first get information about the SMIL message, start with first 
           slide */
        if (SLSif_getSlideInfo(MSF_MODID_SMA, SMA_FIRST_SLIDE) != 
            SLS_RESULT_OK)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
                SASLS_458B4FADEEB3814E0D63C4010CC1F807, "SMA: SLS_getSlideInfo failed\n"));
            result = SMA_RESULT_ERROR;
        } /* if */
    }
#if !SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES
//#if SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES!=1
    else if (SLS_RESULT_TO_MANY_SLIDES == openSmilRsp->result)
    {
		MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SASLS_B32E4769A84E8CC0010107BFBBA1135E, "SMA: Too many slides in SMIL message\n"));
		result = SMA_RESULT_TO_MANY_SLIDES;
	}
#endif
	else
	{
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SASLS_DD5C38D1A168F246E47E25F529D0E0A3, "SMA: SLS failed to open SMIL in SLS_OPEN_SMIL_RSP\n"));
        result = SMA_RESULT_ERROR;
    } /* if */

    return result;
} /* handleOpenSmilRsp */


static SlsUnrefItemList *copySlsUnrefList(SlsUnrefItemList *sourceList)
{
	SlsUnrefItemList *destList;
	SlsUnrefItemList *destListStart;
	if (sourceList == NULL)
	{
		return NULL;
	} /* if */
	
	destList = SMA_ALLOC(sizeof(SlsUnrefItemList));
	memset(destList, 0x00, sizeof(SlsUnrefItemList));

	destListStart = destList;
		
	while (sourceList != NULL)
	{
		destList->offset = sourceList->offset;
		destList->size = sourceList->size;
		destList->mediaType = sourceList->mediaType;
		if (sourceList->boundary)
		{
			destList->boundary = msf_cmmn_strdup(MSF_MODID_SMA, 
				sourceList->boundary);
		} /* if */
		
		if (sourceList->fileName)
		{
			destList->fileName = msf_cmmn_strdup(MSF_MODID_SMA, 
				sourceList->fileName);
		    meaTransformIllegalFileName(destList->fileName);
		} /* if */
      	if (sourceList->contentType)
		{
			destList->contentType = msf_cmmn_strdup(MSF_MODID_SMA, 
				sourceList->contentType);
		} /* if */

        if (smaIsSupportedAttachment(destList->contentType) == FALSE)  /* fault tolerance */
        {
            const char *mime = NULL;
            destList->mediaType = getSlsMediaTypeFromFileName(destList->fileName);
            if ((mime = meaFileName2MimeType(destList->fileName)) != NULL)
            {
                SMA_FREE(destList->contentType);
                destList->contentType = msf_cmmn_strdup(MSF_MODID_SMA, mime);
            }
            else if ((mime = meaFileName2MimeType(destList->contentType)) != NULL)
            {
                SMA_FREE(destList->contentType);
                destList->contentType = msf_cmmn_strdup(MSF_MODID_SMA, mime);
            }
        }

		if(sourceList->next != NULL)
		{
			destList->next = SMA_ALLOC(sizeof(SlsUnrefItemList));
			memset(destList->next, 0x00, sizeof(SlsUnrefItemList));
			destList = destList->next;
		} /* if */
		sourceList = sourceList->next;
	} /* while */

	return destListStart;
} /* copySlsUnrefList */

/*! \brief Dealloctes the attachemnt list
 *
 * \param attach The attachemnt list to deallocate.
 *****************************************************************************/
void smaFreeAttachmentList(SlsUnrefItemList **list)
{
    SlsUnrefItemList *current;
    SlsUnrefItemList *tmp;
    if ((NULL != list) && (NULL != *list))
    {
        current = *list;
        while(NULL != current)
        {
            if (NULL != current->fileName)
            {
                SMA_FREE(current->fileName);
            }
            if (NULL != current->boundary)
            {
                SMA_FREE(current->boundary);
            }
            /* Next item */
            tmp = current;
            current = current->next;
            SMA_FREE(tmp);
        }
        *list = NULL;
    }
}

#ifdef WAP_SUPPORT
/*! \brief Get SLS media type from file name (extension) for fault tolerance.
 *         If the contentType cannot tell what the media type is, we use filename extension.
 *  \param filename (IN)
 *  \return SlsMediaType
 *****************************************************************************/
SlsMediaType getSlsMediaTypeFromFileName(const char *filename)
{
    int i = 0;
    const char *mimeType = NULL;
    const SmaMediaTypeItem smaSupportedMediaTypes[] = SMA_CFG_SUPPORTED_MEDIA_TYPES;

    if(filename != NULL && (mimeType = meaFileName2MimeType(filename)) != NULL)
    {
        while(smaSupportedMediaTypes[i].slsMediaType != SLS_NOT_USED)
        {
            if(msf_cmmn_strcmp_nc(mimeType, smaSupportedMediaTypes[i].mimeType) == 0)
            {
                return smaSupportedMediaTypes[i].slsMediaType;
            }
            i++;
        }
    }

    return SLS_UNKNOWN;
}
#endif
/*! \brief Copies an sls region
 *  \param source The source region
 *  \paramn destination The destination region
 *****************************************************************************/
void copyRegion(const SlsRegion *source, SlsRegion *destination )
{
    if (source == NULL || destination == NULL) 
    {
        /* no input */
        return;
    } /* if */
    
    destination->position.cx.type = source->position.cx.type;
    destination->position.cx.value= source->position.cx.value;
    destination->position.cy.type = source->position.cy.type;
    destination->position.cy.value= source->position.cy.value;

    destination->size.cx.type = source->size.cx.type;
    destination->size.cx.value= source->size.cx.value;
    destination->size.cy.type = source->size.cy.type;
    destination->size.cy.value= source->size.cy.value;

	destination->fit= (SmaFit)source->fit;

} /* copyRegion */

static SmaCommMediaObject *smaSetSlsObj(const SlsSlideInfo *slsInfo, SlsMediaObjectType objectType)
{
    SmaCommMediaObject *slsObj = NULL;

    slsObj = (SmaCommMediaObject *)SMA_ALLOC(sizeof(SmaCommMediaObject));
    memset(slsObj, 0x00, sizeof(SmaCommMediaObject));

    switch(objectType)
    {
    case SLS_OBJECT_TYPE_TEXT:
        slsObj->charset = slsInfo->text.charset;
        slsObj->color = slsInfo->text.color;
        slsObj->offset = slsInfo->text.offset;
        slsObj->size = slsInfo->text.size;
        copyRegion(&slsInfo->text.region, &slsObj->region);
        slsObj->fileName = slsInfo->text.fileName;
        slsObj->boundary = slsInfo->text.boundary;
        slsObj->type = slsInfo->text.type;         
        if(slsObj->type == SLS_UNKNOWN)  /* fault tolerance */
        {
            slsObj->type = getSlsMediaTypeFromFileName(slsObj->fileName);
        }
    	break;
    case SLS_OBJECT_TYPE_IMAGE:
        slsObj->offset = slsInfo->image.offset;
        slsObj->size = slsInfo->image.size;
      
        copyRegion(&slsInfo->image.region, &slsObj->region);
        slsObj->fileName = slsInfo->image.fileName;
        slsObj->boundary = slsInfo->image.boundary;
        slsObj->alt = slsInfo->image.alt;
        slsObj->type = slsInfo->image.type;         
        if(slsObj->type == SLS_UNKNOWN)  /* fault tolerance */
        {
            slsObj->type = getSlsMediaTypeFromFileName(slsObj->fileName);
        }
    	break;
    case SLS_OBJECT_TYPE_AUDIO:
        slsObj->offset = slsInfo->audio.offset;
        slsObj->size = slsInfo->audio.size;
        slsObj->fileName = slsInfo->audio.fileName;
        slsObj->boundary = slsInfo->audio.boundary;
        slsObj->type = slsInfo->audio.type;         
        if(slsObj->type == SLS_UNKNOWN)  /* fault tolerance */
        {
            slsObj->type = getSlsMediaTypeFromFileName(slsObj->fileName);
        }
        break;
    case SLS_OBJECT_TYPE_VIDEO:
        slsObj->offset = slsInfo->video.offset;
        slsObj->size = slsInfo->video.size;
        copyRegion(&slsInfo->video.region, &slsObj->region);
        slsObj->fileName = slsInfo->video.fileName;
        slsObj->boundary = slsInfo->video.boundary;
        slsObj->alt = slsInfo->video.alt;
        slsObj->type = slsInfo->video.type;         
        if(slsObj->type == SLS_UNKNOWN)  /* fault tolerance */
        {
            slsObj->type = getSlsMediaTypeFromFileName(slsObj->fileName);
        }
        break;
    default:
        break;
    }           

    return slsObj;
}

static void smaSetObjectInfo(SmaCommMediaObject *slsObj, SmaObjectInfo *object, 
    SlsMediaObjectType objectType, MSF_UINT32 rootBgColor)
{
    object->type = objectType;

    switch(objectType)
    {
    case SLS_OBJECT_TYPE_TEXT:
        object->info.text.charset = slsObj->charset;
        object->info.text.textColor = slsObj->color;
        object->info.text.offset = slsObj->offset;
        object->info.text.size = slsObj->size;
        object->info.text.type = slsObj->type;     
        object->info.text.bgColor = rootBgColor;
        
        copySlsRegion(&slsObj->region, &object->info.text.region);
        if (slsObj->fileName != NULL)
        {
            object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->fileName);
            meaTransformIllegalFileName(object->fileName);
        }
        if (slsObj->boundary != NULL)
        {
             object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->boundary);
        }        
        break;
    case SLS_OBJECT_TYPE_IMAGE:
        object->info.image.offset = slsObj->offset;
        object->info.image.size = slsObj->size;
        object->info.image.type = slsObj->type;         
        object->info.image.bgColor = rootBgColor;
        
        copySlsRegion(&slsObj->region, &object->info.image.region);
        if (slsObj->fileName != NULL)
        {
            object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->fileName);
            meaTransformIllegalFileName(object->fileName);
        }
        if (slsObj->boundary != NULL)
        {
            object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->boundary);
        }        
        if (slsObj->alt != NULL)
        {
            object->info.image.alt = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->alt);
        }
        break;
    case SLS_OBJECT_TYPE_AUDIO:
        object->info.audio.offset = slsObj->offset;
        object->info.audio.size = slsObj->size;
        object->info.audio.type = slsObj->type;         
        object->info.audio.bgColor = rootBgColor;
        
        if (slsObj->fileName != NULL)
        {
            object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->fileName);
            meaTransformIllegalFileName(object->fileName);
        }
        if (slsObj->boundary != NULL)
        {
            object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->boundary);
        }        
        break;
    case SLS_OBJECT_TYPE_VIDEO:
        object->info.video.offset = slsObj->offset;
        object->info.video.size = slsObj->size;
        object->info.video.type = slsObj->type;         
        object->info.video.bgColor = rootBgColor;
        
        copySlsRegion(&slsObj->region, &object->info.video.region);
        if (slsObj->fileName != NULL)
        {
            object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->fileName);
            meaTransformIllegalFileName(object->fileName);
        }
        if (slsObj->boundary != NULL)
        {
            object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->boundary);
        }        
        if (slsObj->alt != NULL)
        {
            object->info.video.alt = msf_cmmn_strdup(MSF_MODID_SMA, slsObj->alt);
        }
        break;
    default:
        break;
    }           
    
    SMA_FREE(slsObj);
    return;
}

/*! \brief Handles the response from the SlsGetSlideInfo call.
 *  \param slsInfo (IN): The information about the SMIL
 *  \param slide (OUT): The information converted for use with Sma
 *  \return TRUE on success or if the module is of no importance. FALSE on error.
 *****************************************************************************/
SmaResult handleGetSlideInfoRsp(const SlsSlideInfo *slsInfo, 
    SmaSlideInfo *slide )
{
    SmaObjectInfo *object;
    MSF_BOOL firstUsed = FALSE;
	SmaPlayerInfo *playerInfo = getPlayerInfo();
    SlsMediaObjectType objType;
    SmaCommMediaObject *slsObj = NULL;
    SlsMediaType type;

    if (slide == NULL || slsInfo == NULL)
    {
        /* incorrect values */
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
            SASLS_8EE387C3F1B56806310B63E5085FD32B, "SMA - handleGetSlideInfoRsp: incorrect parameters\n"));
        return SMA_RESULT_ERROR;
    } /* if */


	slide->bgColor = playerInfo->rootBgColor;
#if SMA_USE_BEST_SLIDE_DURATION == 1
    /* This design: Only the last slide is exempted from sliding duration limitation */
    /* we will check audio duration every time */
/*    if (playerInfo->currentSlide < playerInfo->noOfSlides - 1)
    {
        slide->displayTime = slsInfo->duration;
    }
    else*/
    {
        if (slsInfo->audio.type != SLS_NOT_USED && slsInfo->audio.fileName != NULL)
        {
            MSF_INT32 fileHandle = -1;
            unsigned int audio_duration = 0;        
            char *vFileName = NULL;
            char *filepath;  
            
            vFileName = SMA_ALLOC(WIDGET_RAWFILE_NAMELEN+1);
            ASSERT(vFileName != NULL);
            memset(vFileName, 0x00, WIDGET_RAWFILE_NAMELEN+1);
            
            slide->displayTime = 0;
    
            filepath = (char *)MMSlib_getMessageFullPath(MSF_MODID_SMA, playerInfo->msgId, fldrGetFileSuffix(playerInfo->msgId));
            if (filepath != NULL)
            {
                fileHandle = MSF_FILE_OPEN( MSF_MODID_SMA, filepath, MSF_FILE_SET_RDONLY, 0);
                if(fileHandle < 0)
                {
                    SMA_FREE(filepath);
                    fileHandle = 0;
                }
                else
                {
                    if (HDIa_fileGenVirtualFileName(
                                    fileHandle,
                                    (char*)vFileName,
                                    (unsigned int)WIDGET_RAWFILE_NAMELEN,
                                    (unsigned int)slsInfo->audio.offset, 
                                    (unsigned int)slsInfo->audio.size) != HDI_FILE_OK)//FS_NO_ERROR)
                    {
                        SMA_FREE(vFileName);
                    }
                    else
                    {                 
                        char *mo_ext = strrchr(slsInfo->audio.fileName, '.');
                        if (mo_ext != NULL)
                        {
                            char *c;

                            if ((c = strrchr(vFileName, '.')) == NULL)
                            {
                                c = strrchr(vFileName, '\0');
                            }
                            strcpy(c, mo_ext);
                            ASSERT(strlen(vFileName) <= WIDGET_RAWFILE_NAMELEN);
                            if (HDIa_widgetExtSoundGetDuration((void *)vFileName, &audio_duration))
                            {
                                if (audio_duration == 0 )
                                {
                                    slide->displayTime = SMA_DEFOUT_AUDIO_DURATION;
                                }
                                else if (((audio_duration/1000)+1) > slsInfo->duration)
                                {
                                    slide->displayTime  = ((audio_duration/1000)+1);
                                }
                            }
                        }
                        SMA_FREE(vFileName);                       
                    }                
                    SMA_FREE(filepath);
                    MSF_FILE_CLOSE(fileHandle);
                    fileHandle = -1;                
                }            
            }
        }
        if (slide->displayTime < slsInfo->duration)
        {
            slide->displayTime = slsInfo->duration;
        }    
    }
#else
    slide->displayTime = slsInfo->duration;
#endif
    
    
    object = &slide->object;

    if (slsInfo->image.type != SLS_NOT_USED)
    {
        type = slsInfo->image.type;
        if(type == SLS_UNKNOWN)  /* fault tolerance */
        {
            type = getSlsMediaTypeFromFileName(slsInfo->image.fileName);
        }
        objType = smaGetObjectType(type);
        if(objType != SLS_OBJECT_TYPE_IMAGE && objType != SLS_OBJECT_TYPE_DRM && objType != SLS_OBJECT_TYPE_NONE)
        {
            slsObj = smaSetSlsObj(slsInfo, SLS_OBJECT_TYPE_IMAGE);
            smaSetObjectInfo(slsObj, object, objType, playerInfo->rootBgColor);
        }    
        else
        {    
            /* Image or video object */
            object->info.image.offset = slsInfo->image.offset;
            copySlsRegion(&slsInfo->image.region, &object->info.image.region);
            object->info.image.size = slsInfo->image.size;
            object->info.image.type = slsInfo->image.type;

            if(object->info.image.type == SLS_UNKNOWN)  /* fault tolerance */
            {
                object->info.image.type = getSlsMediaTypeFromFileName(slsInfo->image.fileName);
            }

            if (slsInfo->image.fileName != NULL)
		    {
                object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->image.fileName);
		        meaTransformIllegalFileName(object->fileName);
		    }
		    if (slsInfo->image.alt != NULL)
		    {
                object->info.image.alt = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->image.alt);
		    }
            if (NULL != slsInfo->image.boundary)
            {
                object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->image.boundary);
            }
		    
		    object->type = SLS_OBJECT_TYPE_IMAGE;
            object->info.image.bgColor = playerInfo->rootBgColor;
        }
        
        firstUsed = TRUE;
    }  /* if */

	if (slsInfo->video.type != SLS_NOT_USED)
    {
        if (firstUsed)
        {
            object->next = SMA_ALLOC(sizeof(SmaObjectInfo));
            memset(object->next, 0x00, sizeof(SmaObjectInfo));
            object = object->next;
        } /* if */

        type = slsInfo->video.type;
        if(type == SLS_UNKNOWN)  /* fault tolerance */
        {
            type = getSlsMediaTypeFromFileName(slsInfo->video.fileName);
        }
        objType = smaGetObjectType(type);
        if(objType != SLS_OBJECT_TYPE_VIDEO && objType != SLS_OBJECT_TYPE_DRM && objType != SLS_OBJECT_TYPE_NONE)
        {
            slsObj = smaSetSlsObj(slsInfo, SLS_OBJECT_TYPE_VIDEO);
            smaSetObjectInfo(slsObj, object, objType, playerInfo->rootBgColor);
        }    
        else
        {
            /* Image or video object */
            object->info.video.offset = slsInfo->video.offset;
            copySlsRegion(&slsInfo->video.region, &object->info.video.region);
            object->info.video.size = slsInfo->video.size;
            object->info.video.type = slsInfo->video.type;

            if(object->info.video.type == SLS_UNKNOWN)  /* fault tolerance */
            {
                object->info.video.type = getSlsMediaTypeFromFileName(slsInfo->video.fileName);
            }
        
            if (slsInfo->video.fileName != NULL)
		    {
                object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->video.fileName);
		        meaTransformIllegalFileName(object->fileName);
		    }
		    if (slsInfo->video.alt != NULL)
		    {
                object->info.video.alt = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->video.alt);
		    }
            if (NULL != slsInfo->video.boundary)
            {
                object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->video.boundary);
            }
		    /* video type */
		    object->type = SLS_OBJECT_TYPE_VIDEO;
            object->info.video.bgColor = playerInfo->rootBgColor;
        }        
        firstUsed = TRUE;
    }  /* if */
    
    if (slsInfo->audio.type != SLS_NOT_USED)
    {
        if (firstUsed)
        {
            object->next = SMA_ALLOC(sizeof(SmaObjectInfo));
            memset(object->next, 0x00, sizeof(SmaObjectInfo));
            object = object->next;
        } /* if */

        type = slsInfo->audio.type;
        if(type == SLS_UNKNOWN)  /* fault tolerance */
        {
            type = getSlsMediaTypeFromFileName(slsInfo->audio.fileName);
        }
        objType = smaGetObjectType(type);
        if(objType != SLS_OBJECT_TYPE_AUDIO && objType != SLS_OBJECT_TYPE_DRM && objType != SLS_OBJECT_TYPE_NONE)
        {
            slsObj = smaSetSlsObj(slsInfo, SLS_OBJECT_TYPE_AUDIO);
            smaSetObjectInfo(slsObj, object, objType, playerInfo->rootBgColor);
        }    
        else
        {
            /* Audio object */
            object->info.audio.offset = slsInfo->audio.offset;
            object->info.audio.size = slsInfo->audio.size;
            object->info.audio.type = slsInfo->audio.type;
            /* set slide type */

            if(object->info.audio.type == SLS_UNKNOWN)  /* fault tolerance */
            {
                object->info.audio.type = getSlsMediaTypeFromFileName(slsInfo->audio.fileName);
            }

            if (slsInfo->audio.fileName != NULL)
		    {
                object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->audio.fileName);
		        meaTransformIllegalFileName(object->fileName);
		    } /* if */
            if (NULL != slsInfo->audio.boundary)
            {
                object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->audio.boundary);
            }
            object->type = SLS_OBJECT_TYPE_AUDIO;
            object->info.audio.bgColor = playerInfo->rootBgColor;
        }
        firstUsed = TRUE;
    } /* if */
    
    if (slsInfo->text.type != SLS_NOT_USED)
    {
        if (firstUsed)
        {
            object->next = SMA_ALLOC(sizeof(SmaObjectInfo));
            memset(object->next, 0x00, sizeof(SmaObjectInfo));
            object = object->next;
        } /* if */

        type = slsInfo->text.type;
        if(slsInfo->text.type == SLS_UNKNOWN)  /* fault tolerance */
        {
            type = getSlsMediaTypeFromFileName(slsInfo->text.fileName);
        }
        objType = smaGetObjectType(type);
        if(objType != SLS_OBJECT_TYPE_TEXT && objType != SLS_OBJECT_TYPE_DRM && objType != SLS_OBJECT_TYPE_NONE)
        {
            slsObj = smaSetSlsObj(slsInfo, SLS_OBJECT_TYPE_TEXT);
            smaSetObjectInfo(slsObj, object, objType, playerInfo->rootBgColor);
        }    
        else
        {
            object->info.text.offset = slsInfo->text.offset;
            object->info.text.size = slsInfo->text.size;
            object->info.text.charset = slsInfo->text.charset;
            copySlsRegion(&slsInfo->text.region, &object->info.text.region);
            object->info.text.type = slsInfo->text.type;
		    object->info.text.textColor = slsInfo->text.color;

            if(object->info.text.type == SLS_UNKNOWN)  /* fault tolerance */
            {
                object->info.text.type = getSlsMediaTypeFromFileName(slsInfo->text.fileName);
            }

            /* set slide type */
		    if (slsInfo->text.fileName != NULL)
		    {
                object->fileName = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->text.fileName);
		        meaTransformIllegalFileName(object->fileName);
		    } /* if */
            if (NULL != slsInfo->text.boundary)
            {
                object->boundary = msf_cmmn_strdup(MSF_MODID_SMA, 
                    slsInfo->text.boundary);
            }
            object->type = SLS_OBJECT_TYPE_TEXT;
            object->info.text.bgColor = playerInfo->rootBgColor;
        }        
    } /* if */
    
	updateRegion(&slide->object);
    
	slide->next = NULL;
    return SMA_RESULT_OK;
} /* handleGetSlideInfoRsp */


void updateRegion(SmaObjectInfo *object)
{	
	SmaRegion *reg1 = NULL;
	SmaRegion *reg2 = NULL;
	SmaRegion *tmpReg = NULL;
	MsfSize size;
	
	
	/* Update the region if its not correct */
	/* Only two regions are possible */
	while (object)
	{
		switch (object->type)
		{
		case SLS_OBJECT_TYPE_IMAGE:
			tmpReg = &(object->info.image.region);
			if (tmpReg != NULL)
			{
                            tmpReg->size.cx.value = 100;
                            tmpReg->size.cx.type= 1;
                            tmpReg->size.cy.value = 100;
                            tmpReg->size.cy.type= 1;
                        }
			break;			
		case SLS_OBJECT_TYPE_VIDEO:
			tmpReg = &(object->info.video.region);
			break;
		case SLS_OBJECT_TYPE_TEXT:
			tmpReg = &(object->info.text.region);
			break;
		case SLS_OBJECT_TYPE_AUDIO:
		case SLS_OBJECT_TYPE_DRM:
		case SLS_OBJECT_TYPE_ATTACMENT:
		default:
			/* do nothing */
			break;
		} /* switch */
		
		if (tmpReg != NULL && reg1 == NULL)
		{
			reg1 = tmpReg;
		}
		else if (tmpReg != NULL && reg2 == NULL)
		{
			reg2 = tmpReg;
			/* should only be two regions, break */
			break;
		} /* if */
		tmpReg = NULL;
		object = object->next;
	} /* while */
	
	//getSlideDisplaySize(&size);
    size.width = (MSF_INT16)getPlayerInfo()->rootSize.width;
    size.height = (MSF_INT16)getPlayerInfo()->rootSize.height;

	if (reg1 == NULL)
	{
		/* no region, should never happen, just return */	
		return;
	} /* if */

	/* if anything is corrupt with the region, just split the display in 
	half and set size */
#ifdef WAP_SUPPORT
	if (reg1->size.cx.value == 0 || reg1->size.cy.value == 0 ||
		(reg1->position.cx.type == 0 &&
		 reg1->position.cx.value + reg1->size.cx.value > size.width) ||
		(reg1->size.cy.type == 0 &&
		 reg1->position.cy.value + reg1->size.cy.value > size.height) ||
		reg2 == NULL ||	
                reg2->size.cx.value == 0 || reg2->size.cy.value == 0 ||
		(reg2->position.cx.type == 0 &&
		 reg2->position.cx.value + reg2->size.cx.value > size.width) ||
		(reg2->position.cy.type == 0 &&
		 reg2->position.cy.value + reg2->size.cy.value > size.height) ||
		(reg1 && reg2 && reg1->size.cy.type && reg2->size.cy.type && 
		 reg1->size.cy.value + reg2->size.cy.value > 100)
		)
#else
	if (reg1->size.cx.value == 0 ||
		reg1->size.cy.value == 0 ||
		reg1->position.cx.value + reg1->size.cx.value > size.width ||
		reg1->position.cy.value + reg1->size.cy.value > size.height ||
		reg2 == NULL ||	
		reg2->position.cx.value + reg2->size.cx.value > size.width ||
		reg2->position.cy.value + reg2->size.cy.value > size.height 
		)
#endif /* WAP_SUPPORT */
	{
		/* corrupt region */
#ifdef WAP_SUPPORT
		if (reg2 == NULL)
		{
			reg1->size.cx.value = 100;
			reg1->size.cx.type= 1;
			reg1->size.cy.value = 100;
			reg1->size.cy.type= 1;
			reg1->position.cx.value = 0;
			reg1->position.cx.type= 1;
			reg1->position.cy.value = 0;
			reg1->position.cy.type = 1;
		}
		else
		{
			/* Split display in half */
			reg1->size.cx.value = 100;
			reg1->size.cx.type= 1;
			reg1->size.cy.value = 100;
			reg1->size.cy.type= 1;
			reg1->position.cx.value = 0;
			reg1->position.cx.type= 1;
			reg1->position.cy.type = 1;

			reg2->size.cx.value = 100;
			reg2->size.cx.type= 1;
			reg2->size.cy.value = 100;
			reg2->size.cy.type= 1;			
			reg2->position.cx.value = 0;
			reg2->position.cx.type= 1;
			reg2->position.cy.type = 1;

			if(reg1->position.cy.value > reg2->position.cy.value)	/* keep original layout */
			{
				reg1->position.cy.value = 50;
				reg2->position.cy.value = 0;
			}
			else
			{
				reg1->position.cy.value = 0;
				reg2->position.cy.value = 50;
			}
		} /* if */
#endif		
	} /* if */
} /* updateRegion */


/*! \brief Copies an sls region
 *  \param source The source region
 *  \paramn destination The destination region
 *****************************************************************************/
void copySlsRegion(const SlsRegion *source, SmaRegion *destination )
{
    if (source == NULL || destination == NULL) 
    {
        /* no input */
        return;
    } /* if */
    
    destination->position.cx.type = source->position.cx.type;
    destination->position.cx.value= source->position.cx.value;
    destination->position.cy.type = source->position.cy.type;
    destination->position.cy.value= source->position.cy.value;

    destination->size.cx.type = source->size.cx.type;
    destination->size.cx.value= source->size.cx.value;
    destination->size.cy.type = source->size.cy.type;
    destination->size.cy.value= source->size.cy.value;

	destination->fit= (SmaFit)source->fit;

} /* copySlsRegion */


