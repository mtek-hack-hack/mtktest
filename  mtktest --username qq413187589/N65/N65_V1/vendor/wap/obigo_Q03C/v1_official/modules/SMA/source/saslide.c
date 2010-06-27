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
/* MSF */
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_hdr.h"
#include "msf_chrs.h"
#include "msf_wid.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* MMS */
#include "mms_def.h"
#include "msig.h"
#include "fldmgr.h"

/* SMA */
#include "sma_cfg.h"
#include "saintsig.h"
#include "saasync.h"
#include "sma_if.h"
#include "samem.h"
#include "satypes.h"
#include "samain.h"
#include "saslide.h"
#include "saui.h"
#include "salnk.h"
#include "saph.h"
#include "sauidia.h"
#ifdef WAP_SUPPORT
#include "smtrrend.h" //for smaSetImageOnTop
#endif /* WAP_SUPPORT */

#ifdef __DRM_SUPPORT__
#include "fs_type.h"
#include "fs_errcode.h"
#include "../../drm/include/drm_def.h"
#include "../../drm/include/drm_gprot.h"
#include "../../drm/include/drm_main.h"
#include "msf_file.h"  //for MSF_FILE_ERROR_PATH
#include "mea_cfg.h"  //for MMS_DRM_FOLDER
#include "mea_def.h"  /* for meaMediaType */

/* Steal MEA function. It's utility function, should be fine... */
extern const char *meaFileName2MimeType(const char *filename);
extern MeaMediaType meaMime2MediaType(const char *mime);
extern SlsMediaType meaConvertMediaTypeToSls(MeaMediaType mediaType);
#endif /* __DRM_SUPPORT__ */

#ifdef MMS_TMPLATES_MULTIPLE_LANG_SUPPORT
#include "wap.h"
extern MmsMsgId meaMMCGetCurrentActiveMsg(void);
#endif /* MMS_TMPLATES_MULTIPLE_LANG_SUPPORT */

#include "widget.h"		//for virtual file definition

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
#include "msf_core.h"
#define SMA_SLIDE_GET_TEXT_HEIGHT_TIMER_DUR   5
#endif

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mmsadp.h"
#endif

/*--- Definitions/Declarations ---*/

#define SMA_MAX_BOUNDARY_SIZE       (2 + 70 + 2)    /* '-' '-' boundary 'CR' 'LF' */

#define SMA_UTF16_BOM_LEN                 2
#define SMA_UTF16_BOM_BIG                  "\xFE\xFF"                  
#define SMA_UTF16_BOM_LITTELE              "\xFF\xFE"

/*--- Types ---*/

/* \struct SlideInstanceData Used to hold information between states */
typedef struct
{
    MSF_UINT32              callingFsm;     /*<! The calling FSM */
    MSF_INT32               returnSig;      /*<! The return signal */

    SmaAsyncOperationHandle asioReadHandle; /*<! Async read handle */
    SmaAsyncOperationHandle drmReadHandle; /*<! Async read handle */
    char                    *buffer;        /*<! Buffer used to hold data */
    MSF_UINT32              bufferSize;     /*<! Size of buffer */
    MSF_UINT32              textSize;     /*<! Size of buffer */
    MSF_UINT32              readPos;        /*<! Current position in file */
    MSF_UINT32              leftToRead;     /*<! Number of bytes left to read */
    MSF_UINT32              slideNumber;    /*<! Current slide */
    SmaObjectInfo           *objectInfo;    /*<! Information about the object */

    char                    *drmPipePath;   /*!< The path to the pipe */
    MsfImageHandle          imageHandle;    /*!< Used when creating an image from file using a buffer */
    MsfSoundHandle          audioHandle;    /*!< Used when creating an image from file using a buffer */
    MsfVideoHandle          videoHandle;    /*!< Used when creating an image from file using a buffer */
}SlideInstanceData;

/*--- Constants ---*/
#ifdef WAP_SUPPORT
#define SLASH_CHAR                  ((unsigned char)'/')
#endif /* WAP_SUPPORT */

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

static SlideInstanceData *slideInstance;
#ifndef __DRM_SUPPORT__
static const SlsCharsetItem supportedCharsets[] = SLS_CFG_SUPPORTED_CHARSET;
#endif /* __DRM_SUPPORT__ */

static MSF_BOOL isTextTrunc = FALSE;

/******************************************************************************
 * Function prototypes
 *****************************************************************************/
static void  smaSlideMain(SmaSignal *sig);
static MSF_BOOL handleSlideReadOperation(SlideInstanceData *instance, 
    MSF_UINT32 bytesRead);
static void generateObject(SmaObjectInfo *object);
static void generateObjectContinue(void);
static void freeSlideInstanceData(SlideInstanceData *instance);
static MSF_UINT32 getDreOffset(const SmaObjectInfo *object);
static void smaHandleNextObject(SmaObjectInfo *object, SmaStateMachine fsm, 
    int signal, SmaResult result);
static void handleFailedToDisplayDrm(SmaObjectInfo *object);
static void smaSlideSetTextTrunc(MSF_BOOL isTrunc);
static MSF_BOOL smaSlideIsTextTrunc(void);

#ifdef __DRM_SUPPORT__	/* temp for compile error */
static void generateDRMObject(SmaObjectInfo *object);
#endif
/*!
 *\brief Initiates the sma slide handler
 *
 *****************************************************************************/
void smaSlideInit(void)
{
    smaSignalRegisterDst(SMA_FSM_SLIDE, smaSlideMain);
    slideInstance = SMA_ALLOC(sizeof(SlideInstanceData));
    memset(slideInstance, 0x00, sizeof(SlideInstanceData));
    
    /* data-buffer is used for all slides */
    slideInstance->buffer = SMA_ALLOC(SMA_MAX_CHUNK_SIZE);
    slideInstance->bufferSize = SMA_MAX_CHUNK_SIZE;	
    memset(slideInstance->buffer, 0x0, SMA_MAX_CHUNK_SIZE);
} /* smaSbpInit */


/*!
 *\brief Terminates the content routing handler
 *
 *****************************************************************************/
void smaSlideTerminate(void)
{
    /* Remove any instance data */
    if (slideInstance == NULL)
    {
        return;
    } /* if */

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SASLIDE_EEDE775F10BA3A7D3CCD271F324B96EC, "[TEXT HEIGHT] smaSlideTerminate\n"));

    MSF_TIMER_RESET (MSF_MODID_SMA, SMA_GET_TOTAL_TEXT_HEIGHT_TIMER_ID);
    HDIa_widgetExtCloseTransitionAnimation();
#endif

    HDIa_widgetExtRegisterSwitchWidgetScreenCallback(NULL);
    freeSlideInstanceData(slideInstance);
    SMA_FREE(slideInstance);
    slideInstance = NULL;
    smaSignalDeregister(SMA_FSM_SLIDE);
} /* smaSbpTerminate */


/*!
 *\brief Free slide instance data
 *****************************************************************************/
static void freeSlideInstanceData(SlideInstanceData *instance)
{
    if (instance == NULL)
    {
        return;
    } /* if */

    if (instance->asioReadHandle != 0)
    {
        smaAsyncOperationStop(&instance->asioReadHandle);
    } /* if */

    if (instance->drmReadHandle != 0)
    {
        smaAsyncOperationStop(&instance->drmReadHandle);
    } /* if */

    if (instance->buffer != NULL)
    {
        SMA_FREE(instance->buffer);
        instance->buffer = NULL;
    } /* if */
    if (instance->drmPipePath) 
    {
        SMA_FREE(instance->drmPipePath);
        instance->drmPipePath = NULL;
    }
    
    /* we are not responsible for this one */
    instance->objectInfo = NULL;
    memset(instance, 0x00, sizeof(SlideInstanceData));
} /* freeSlideInstanceData */

#ifndef __DRM_SUPPORT__
/*! \brief Extracts the content-type of the DRM object and sets the Sma object
 *         accordingly.
 *
 * \param drmHeader The DRM header, delivered from the DRM package.
 * \param object The current object.
 * \return TRUE if the DRM can be handled, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL handleDrmHeader(char *drmHeader, SmaObjectInfo *object)
{
    msf_hdr_t *hdr;
    const char *value;
    char *paramValue;
    MSF_UINT32 intValue;
    unsigned int i;
    unsigned int j;
    const SmaMediaTypeItem *items;
    const SlsCharsetItem *charItems;

    if (NULL == (hdr = msf_hdr_create(MSF_MODID_SMA)))
    {
        return FALSE;
    }
    /* Set the DRM header */
    if (!msf_hdr_add_headers_from_text(hdr, drmHeader))
    {
        msf_hdr_delete(hdr);
        return FALSE;
    }
    if (NULL == (value = msf_hdr_get_string(hdr, MSF_HDR_CONTENT_TYPE)))
    {
        msf_hdr_delete(hdr);
        return FALSE;
    }
    /* Verify the content type */
    i = 0;
    items = smaGetSupportedMediaTypes();
    while(SLS_NOT_USED != items[i].slsMediaType)
    {
        /* Check that the object type is correct and that the content type
           can be handled. Note that the strncmp_nc needs to be performed
           since the parameters can be present in the content type */
        if ((items[i].slsObjectType == object->type) &&
            (0 == msf_cmmn_strncmp_nc(value, items[i].mimeType, 
            strlen(items[i].mimeType))))
        {
            switch (object->type)
            {
            case SLS_OBJECT_TYPE_IMAGE:
                object->info.image.type = items[i].slsMediaType;
                break;
            case SLS_OBJECT_TYPE_VIDEO:
				object->info.video.type = items[i].slsMediaType;
                break;
            case SLS_OBJECT_TYPE_AUDIO:
                object->info.audio.type = items[i].slsMediaType;
                break;
            case SLS_OBJECT_TYPE_TEXT:
                /* Verify the character set */
                if (NULL != (paramValue = msf_hdr_get_parameter(hdr, 
                    MSF_HDR_CONTENT_TYPE, "charset")))
                {
                    /* Check if the charset is supported */
                    j = 0;
                    charItems = supportedCharsets;
                    intValue = msf_charset_str2int(paramValue, strlen(paramValue));
                    SMA_FREE(paramValue);
                    while(MSF_CHARSET_UNKNOWN != charItems[j].msfCharset)
                    {
                        if (charItems[j].msfCharset == intValue)
                        {
                            /* Supported charset found */
                            object->info.text.charset = intValue;
                            msf_hdr_delete(hdr);
                            return TRUE;
                        }
                        ++j;
                    }
                    /* Charset could not be found or are not supported */
                    msf_hdr_delete(hdr);
                    return FALSE;
                }
                break;
            }
            msf_hdr_delete(hdr);
            return TRUE;
        }
        ++i;
    }
    return FALSE;
}
#endif /* __DRM_SUPPORT__ */

/*! Tries to find the DRM boundary in a buffer
 *
 * \param boundary A pointer to the buffer where the boundary can be present
 * \param length The length of the buffer
 * \return TRUE if a boundary is found, the boundary buffer contains a '\0' 
 *         terminated boundary string. Otherwise FALSE is returned and the 
 *         buffer is released and the pointer is set to NULL.
 *****************************************************************************/
MSF_BOOL extractBoundary(char **boundary, MSF_UINT32 length)
{
    char *start;
    char *endCr;
    char *endLf;
    char *end;
    unsigned int i;

    /* Find start, i.e., "--" */
    if ((NULL != (start = msf_cmmn_strnchr(*boundary, '-', length))) && 
        (NULL != (start = msf_cmmn_strnchr(start, '-', length - 1))))
    {
        length -= (int)(start - *boundary) - 2;
        (void)memmove(*boundary, start + 2, length);
        /* Find end */
        endCr = msf_cmmn_strnchr(*boundary, 0x0d, length);
        endLf = msf_cmmn_strnchr(*boundary, 0x0a, length);
        if ((NULL != endCr) && (NULL != endLf))
        {
            end = (endCr < endLf) ? endCr: endLf;
            end[0] = '\0';
            /* Strip white-space at the end */
            start = *boundary;
            i = strlen(start) - 1;
            while(start[i] == ' ')
            {
                start[i] = '\0';
                --i;
            }
            return TRUE;
        }
    }

    SMA_FREE(*boundary);
    *boundary = NULL;
    return FALSE;
}

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
extern void SetSMILTotalTextHeightValue(int totalHeight);

#ifdef __MMI_CHSET_GB2312__
static MSF_UINT32 smaAdjustCharset(unsigned char *buffer, MSF_UINT32 length)
{
    MSF_UINT32 numUTF8 = 0, numGB = 0;
    MSF_BOOL isUTF8 = FALSE;
    
    while (length > 0)
    {
        isUTF8 = FALSE;
        if(*buffer > 80)
        {
            if((*buffer & 0xF0) == 0xE0)
            {
                if((length >= 3) && ((*(buffer + 1) & 0xC0) == 0x80)
                    && ((*(buffer + 2) & 0xC0) == 0x80))
                {
                    numUTF8 ++;
                    buffer += 3;
                    length -= 3;
                    isUTF8 = TRUE;
                }
            }
            else if ((*buffer & 0xE0) == 0xC0)
            {
                if((length >= 2) && ((*(buffer + 1) & 0xC0) == 0x80))
                {
                    numUTF8 ++;
                    buffer += 2;
                    length -= 2;
                    isUTF8 = TRUE;
                }
            }
            if(!isUTF8)
            {
                if((length >= 2) && (*buffer >= 0xA0) && (*buffer <= 0xFE)
                    && ((*(buffer + 1)) >= 0xA0) && ((*(buffer + 1)) <= 0xFE))
                {
                    numGB ++;
                    buffer += 2;
                    length -= 2;
                }
                else
                {
                    buffer++;
                    length--;
                }
            }
        }
        else
        {
            buffer++;
            length--;
        }
    }
    
    if(numUTF8 >= numGB)
        return SMA_UTF8;
    else
        return SMA_GB2312;
}
#endif

static MSF_BOOL smaSlideDisplayText(SlideInstanceData *instance)
{
    MSF_BOOL result = TRUE;
    char *destBuf = NULL;
    MSF_UINT32 destSize = 0;

    if((instance->objectInfo->info.text.charset == SMA_US_ASCII) ||
	    (instance->objectInfo->info.text.charset == SMA_UNKNOWN_CHARSET))
    {
        if((instance->textSize > SMA_UTF16_BOM_LEN) &&
            ((memcmp((char *)instance->buffer, SMA_UTF16_BOM_BIG, SMA_UTF16_BOM_LEN) == 0) ||
            (memcmp((char *)instance->buffer, SMA_UTF16_BOM_LITTELE, SMA_UTF16_BOM_LEN) == 0)))
        {
            instance->objectInfo->info.text.charset = SMA_UTF16;
        }
#ifdef __MMI_CHSET_GB2312__
        else
        {
            instance->objectInfo->info.text.charset = smaAdjustCharset((unsigned char *)instance->buffer, instance->textSize);
        }
#endif

    }

    /* if not UTF8, try to convert the text */
    if ((instance->objectInfo->info.text.charset == SMA_UTF8) ||
        (instance->objectInfo->info.text.charset == SMA_US_ASCII) ||
	    (instance->objectInfo->info.text.charset == SMA_UNKNOWN_CHARSET))	/* UNKNOWN CHARSET will be recogzied as UTF8*/
    {
	    instance->objectInfo->info.text.charset = SMA_UTF8;
	    destBuf = instance->buffer;
	    destSize = instance->textSize;
    }
    else														/* convert text to charset utf8 */
    {
        destBuf = convertToUTF8(instance->objectInfo->info.text.charset, instance->buffer, &instance->textSize, &destSize);
    }
    
    if (NULL != destBuf)	/* Check for links */
    {
        if (NULL == instance->objectInfo->info.text.links)	/* Create a new list*/
            instance->objectInfo->info.text.links = smaCreateUrlList(destBuf, destSize);
    }
   
    if (!displayTextObject(SMA_GADGET_STRING, instance->objectInfo, destBuf))	 /* Text object */
    {
        result = FALSE;		/* unable to display text object */
    } 
    destBuf = NULL;
    //instance->leftToRead = 0;			/* It's not possible to get text in chunks. Just get the next object */
    //instance->readPos += bytesRead;

    return result;
}
#endif

/*!
 *\brief Signal-handler for the content routing FSM.
 *
 * \param sig The signal received.
 *****************************************************************************/
static void smaSlideMain(SmaSignal *sig)
{		
#ifndef __DRM_SUPPORT__
    MSF_BOOL    useBuffer;
    MSF_UINT32  destSize;
    MSF_UINT32  srcSize;
    char  *drmHeader;
    char        *textBuffer;
#endif /* __DRM_SUPPORT__ */
#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    int ret;
#endif

    if (NULL == sig)
    {
        /* no signal - just return */
        return;
    } /* if */

    switch (sig->type)
    {
    case SMA_SIG_SLIDE_READ_RSP:
#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
        if (SMA_ASIO_RESULT_OK != (SmaAsioResult)sig->u_param1 || !(ret = handleSlideReadOperation(slideInstance, sig->u_param2)))
#else
        if (SMA_ASIO_RESULT_OK != (SmaAsioResult)sig->u_param1 || !handleSlideReadOperation(slideInstance, sig->u_param2))
#endif
        {
            if(slideInstance->objectInfo->type == SLS_OBJECT_TYPE_IMAGE)
            {
                displayImageObject(slideInstance->objectInfo, MSF_WIDGET_IMAGE_GET_PREDEFINED(MEA_IMG_IMAGE_ERROR, NULL));
            }
            else if(slideInstance->objectInfo->type == SLS_OBJECT_TYPE_VIDEO)
            {
                displayImageObject(slideInstance->objectInfo, MSF_WIDGET_IMAGE_GET_PREDEFINED(MEA_IMG_VIDEO_ERROR, NULL));
            }
            /* Async operation failed, Exit!*/
            smaHandleNextObject(slideInstance->objectInfo, 
                slideInstance->callingFsm, slideInstance->returnSig, 
                SMA_RESULT_ERROR);
        } 
        else
        {
#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
            if (ret > 0) /* If ret < 0, will get text height first*/
            {
#endif
            if (slideInstance->leftToRead > 0)
            {
                /* get more data for this object */
                generateObjectContinue();
            }
            else 
            {
                smaHandleNextObject(slideInstance->objectInfo, 
                    slideInstance->callingFsm, slideInstance->returnSig, 
                    SMA_RESULT_OK);
            } /* if */
#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
            } /* if (ret > 0)*/
            else
            {
            }
#endif
        }/* if */
        break;
#ifndef __DRM_SUPPORT__
	case SMA_SIG_SLIDE_DRE_MSG_RSP:
		if (SMA_RESULT_OK != (SmaResult)sig->u_param1)
		{
			/* Async operation failed, Exit!*/
            smaHandleNextObject(slideInstance->objectInfo, 
                slideInstance->callingFsm, slideInstance->returnSig, 
                SMA_RESULT_ERROR);
		}
		else if (NULL != sig->p_param)
		{						
            drmHeader = ((SmaDreResultItem *)sig->p_param)->httpHeader;
            SMA_FREE(((SmaDreResultItem *)sig->p_param)->drmRights);
            SMA_FREE(sig->p_param);
            slideInstance->objectInfo->offset += sig->u_param2;
            /* Check the header */
            if (!handleDrmHeader((char *)drmHeader, slideInstance->objectInfo))
            {
                if (drmHeader) 
                {
                    SMA_FREE(drmHeader);
                }
                smaHandleNextObject(slideInstance->objectInfo, 
                    slideInstance->callingFsm, slideInstance->returnSig, 
                    SMA_RESULT_ERROR);
                break;
            }
            if (drmHeader) 
            {
                SMA_FREE(drmHeader);
            }
            /* Use buffer for the text object */
            useBuffer = (SLS_OBJECT_TYPE_TEXT == slideInstance->objectInfo->type);
            /* Get the object*/
			if (!smaDreGetObject(SMA_FSM_SLIDE, SMA_SIG_SLIDE_DRE_OBJ_RSP,
				getPlayerInfo()->filePath, &slideInstance->drmPipePath, 
				(char *)drmHeader, slideInstance->objectInfo->boundary, 
                slideInstance->objectInfo->offset, useBuffer))
			{
                smaHandleNextObject(slideInstance->objectInfo, 
                    slideInstance->callingFsm, slideInstance->returnSig, 
                    SMA_RESULT_ERROR);
			} /* if */
            else
            {
                displayDrmObject(slideInstance->drmPipePath, slideInstance->objectInfo);
            }
            /* We must free the path when we have used it in case there are
             * more DRM objects on the slide */
            if (slideInstance->drmPipePath) 
            {
                SMA_FREE(slideInstance->drmPipePath);
                slideInstance->drmPipePath = NULL;
            }
		}				
		break;

	case SMA_SIG_SLIDE_DRE_OBJ_RSP:
		if (SMA_RESULT_OK != (SmaResult)sig->u_param1)
		{
            smaHandleNextObject(slideInstance->objectInfo, 
                slideInstance->callingFsm, slideInstance->returnSig, 
                SMA_RESULT_ERROR);
		}
		else
		{
            /* Check if it was a Text part that was handled */
            if (NULL != sig->p_param)
            {
                /* The text part is extracted as a buffer */
                srcSize = (MSF_UINT32)sig->u_param2;
                textBuffer = convertToUTF8(
                    slideInstance->objectInfo->info.text.charset, sig->p_param,
                    &srcSize, &destSize);
                SMA_FREE(sig->p_param);
                sig->p_param = NULL;
                (void)displayTextObject(SMA_GADGET_STRING, 
                    slideInstance->objectInfo, textBuffer);
            }
			/* DRE operation complete */
            smaHandleNextObject(slideInstance->objectInfo, 
                slideInstance->callingFsm, slideInstance->returnSig, 
                SMA_RESULT_OK);

		} /* else */
		break;
#endif /* __DRM_SUPPORT__ */
    case SMA_SIG_READ_BOUNDARY_RSP:
        if (SMA_ASIO_RESULT_OK == sig->u_param1)
        {
            if (extractBoundary(&slideInstance->objectInfo->boundary, sig->u_param2))
            {
                /* Try to extract the object again */
                generateObject(slideInstance->objectInfo);
            }
            else
            {
                /* No boundary found, check the next object */
                handleFailedToDisplayDrm(slideInstance->objectInfo);
            }
        }
        /* Clean-up the file operation */
        smaAsyncOperationStop(slideInstance->drmReadHandle);
        slideInstance->drmReadHandle = 0;
        break;
    case SMA_SIG_GADGET_GOT_FOCUS:
        smaHandleNotif(MsfNotifyFocus, sig->u_param1);
        break;

    case SMA_SIG_GADGET_LOST_FOCUS:
        smaHandleNotif(MsfNotifyLostFocus, sig->u_param1);
        break;

#ifdef WAP_SUPPORT
    case SMA_SIG_EVENT_KEY_RIGHT:
        {
            /* Right key will show next slide */
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
            SmaResult result;
            SmaPlayerInfo * playerInfo = getPlayerInfo();
#ifdef __UNIFIED_MESSAGE_MANUAL_PLAY_SLIDE__
            playerInfo->isPlaying = TRUE;
            updateSlideFormActions(playerInfo->isPlaying);
#endif
            result = displayNextSlide(playerInfo);
#else
            SmaResult result = displayNextSlide(getPlayerInfo());
#endif

            if ( SMA_RESULT_OK != result)
                    /* unable to show next slide */
                    EXIT_SMIL_PLAYER(result);
            break;
        }
    case SMA_SIG_EVENT_KEY_LEFT:
        {
            /* Right left will show previous slide */
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
            SmaResult result;
            SmaPlayerInfo * playerInfo = getPlayerInfo();
#ifdef __UNIFIED_MESSAGE_MANUAL_PLAY_SLIDE__
            playerInfo->isPlaying = TRUE;
            updateSlideFormActions(playerInfo->isPlaying);
#endif
            result = displayPreviousSlide(playerInfo);
#else
            SmaResult result = displayPreviousSlide(getPlayerInfo());
#endif

            if ( SMA_RESULT_OK != result)
                    /* unable to show next slide */
                    EXIT_SMIL_PLAYER(result);
            break;

        }
#endif /* WAP_SUPPORT */

#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
    case SMA_SIG_EVENT_SCROLL:
		smaGetScrollOffset();
		break;
#endif /* WIDGET_SLIDING_SMIL_VBAR && __MMI_TOUCH_SCREEN__ */

    case SMA_SIG_EVENT_KEY_DOWN:
        smaHandleEvent(MsfKey_Down, sig->u_param1);
        break;

    case SMA_SIG_EVENT_KEY_UP:
        smaHandleEvent(MsfKey_Up, sig->u_param1);
        break;

    case SMA_SIG_LOAD_NEXT_OBJECT:
        if (SMA_RESULT_ERROR == sig->i_param)
        {
            /* show alternative objects or broken image */
            if ((slideInstance->objectInfo->info.image.alt == NULL) ||
                (!displayAlternativeTextObject(slideInstance->objectInfo)))
			{
                displayImageObject(slideInstance->objectInfo, MSF_WIDGET_IMAGE_GET_PREDEFINED(MEA_IMG_IMAGE_ERROR, NULL));
            } /* if */
        } /* if */
        smaHandleNextObject(slideInstance->objectInfo, 
            slideInstance->callingFsm, slideInstance->returnSig, 
            SMA_RESULT_OK);
        break;

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)

    case SMA_SIG_GET_TOTAL_TEXT_HEIGHT:
        {
            MSF_UINT32  bytesRead = (MSF_UINT32)sig->i_param;
            char* destBuf = NULL;
            MSF_UINT32 destLen;
            
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SASLIDE_65851C2AF25FA7F9FCBDB88761690B3A, "[TEXT HEIGHT] SMA_SIG_GET_TOTAL_TEXT_HEIGHT\n"));
        
        if (!slideInstance)
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SASLIDE_EBE944CF93523CA0D63E278BBAA038D4, "[TEXT HEIGHT] !slideInstance\n"));
            HDIa_widgetExtCloseTransitionAnimation();
            break;
        }

        if((slideInstance->objectInfo->info.text.charset == SMA_US_ASCII) ||
            (slideInstance->objectInfo->info.text.charset == SMA_UNKNOWN_CHARSET))
        {
            if((bytesRead > SMA_UTF16_BOM_LEN) &&
                ((memcmp((char *)slideInstance->buffer, SMA_UTF16_BOM_BIG, SMA_UTF16_BOM_LEN) == 0) ||
                (memcmp((char *)slideInstance->buffer, SMA_UTF16_BOM_LITTELE, SMA_UTF16_BOM_LEN) == 0)))
            {
                slideInstance->objectInfo->info.text.charset = SMA_UTF16;
            }
#ifdef __MMI_CHSET_GB2312__
            else
            {
                slideInstance->objectInfo->info.text.charset = smaAdjustCharset((unsigned char *)slideInstance->buffer, bytesRead);
            }
#endif
        }
        /* convert to utf8 first*/
        if ((slideInstance->objectInfo->info.text.charset == SMA_UTF8) ||
            (slideInstance->objectInfo->info.text.charset == SMA_US_ASCII) ||
            (slideInstance->objectInfo->info.text.charset == SMA_UNKNOWN_CHARSET))	/* UNKNOWN CHARSET will be recogzied as UTF8*/
        {
		    slideInstance->objectInfo->info.text.charset = SMA_UTF8;
		    destBuf = slideInstance->buffer;
		    destLen = bytesRead;
        }
        else														/* convert text to charset utf8 */
        {
            destBuf = convertToUTF8(slideInstance->objectInfo->info.text.charset, 
                slideInstance->buffer, &bytesRead, &destLen);
            bytesRead = destLen;
        }

        if (NULL != destBuf)
        {
            if (smaUiCreateGetTextHeightInst(slideInstance->objectInfo, destBuf, bytesRead) == TRUE)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_887D29D95468CE712A1CFD4E3928777A, "[TEXT HEIGHT] Send SMA_SIG_GET_TOTAL_TEXT_HEIGHT_CONTINUE\n"));
                (void)SMA_SIGNAL_SENDTO(SMA_FSM_SLIDE,SMA_SIG_GET_TOTAL_TEXT_HEIGHT_CONTINUE);
            }
            else
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_FC5160327EC3B2189CD2520743C25DEC, "[TEXT HEIGHT] Send SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED\n"));
                
                SetSMILTotalTextHeightValue(-1);
                (void)SMA_SIGNAL_SENDTO(SMA_FSM_SLIDE,SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED);
            }
        } /* if (NULL != destBuf)*/
        else
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SASLIDE_FC5160327EC3B2189CD2520743C25DEC, "[TEXT HEIGHT] Send SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED\n"));
            
            SetSMILTotalTextHeightValue(-1);
            (void)SMA_SIGNAL_SENDTO(SMA_FSM_SLIDE,SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED);
        }/* if (NULL != destBuf)*/

        }/* */
        break;
        
    case SMA_SIG_GET_TOTAL_TEXT_HEIGHT_CONTINUE:
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SASLIDE_5EC06DBDAD2F4196E353373516B069F0, "[TEXT HEIGHT] SMA_SIG_GET_TOTAL_TEXT_HEIGHT_CONTINUE\n"));

            if (!slideInstance)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_3DBA1DD1E38073234A3F92FC6BDE4598, "[TEXT HEIGHT] no slideInstance\n"));
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            
            if (smaUiGetTextHeight() == FALSE)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_7C84DA59C78E1D53FE72AA704F9016E9, "[TEXT HEIGHT] set timer\n"));
                
                MSF_TIMER_SET (MSF_MODID_SMA, SMA_GET_TOTAL_TEXT_HEIGHT_TIMER_ID, 
                    SMA_SLIDE_GET_TEXT_HEIGHT_TIMER_DUR);
            }
            else
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_574B442F7C63172644B4CF19BB1B6555, "[TEXT HEIGHT] send SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED\n"));
                (void)SMA_SIGNAL_SENDTO(SMA_FSM_SLIDE,SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED);
            }
        }
        break;
        
    case SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED:
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SASLIDE_61CEFF702B5C65A7B5A3EB52FAFEDC8F, "[TEXT HEIGHT] SMA_SIG_GET_TOTAL_TEXT_HEIGHT_FINISHED\n"));
            
            if (!slideInstance)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_3DBA1DD1E38073234A3F92FC6BDE4598, "[TEXT HEIGHT] no slideInstance\n"));
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            
            smaUiSetTotalTextHeightValue();
            
            //slideInstance->currentMo->isWaitWidgetRead = 0;

            if (!smaSlideDisplayText(slideInstance))
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_2F076B3F598329F2A63677A35934CC2B, "[TEXT HEIGHT] displayTextObject failed\n"));

                smaUiDeleteGetTextHeightInst();
                smaHandleNextObject(slideInstance->objectInfo, 
                    slideInstance->callingFsm, slideInstance->returnSig, 
                    SMA_RESULT_ERROR);
            }
            else
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASLIDE_82EC413DFAE5F4D6D8E54FD2EACBF4C7, "[TEXT HEIGHT] displayTextObject ok, next obj\n"));
                smaUiDeleteGetTextHeightInst();
                
                if (slideInstance->leftToRead > 0)
                {
                    /* get more data for this object */
                    generateObjectContinue();
                }
                else 
                {
                    smaHandleNextObject(slideInstance->objectInfo, 
                        slideInstance->callingFsm, slideInstance->returnSig, 
                        SMA_RESULT_OK);
                } /* if */
             }

             //HDIa_widgetExtCloseTransitionAnimation();
        }
        break;
        
#endif

    default:
        /* unknown signal */
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SASLIDE_D1A0EFC5990B833A4D7B9F3C054504AD, "(%s) (%d) Unknown signal!\n", __FILE__, __LINE__));
        break;
    } /* switch */

    /* Deallocate the signal */
    smaSignalDelete(sig);
} /* smaSlideMain */


/*!
 * \brief Handles the async read response. I.e. displays an image and 
 *        retrieves the next part
 * \param instance Current instance
 * \param bytesRead Bytes read in read operation. (For virtual file resource, bytesRead = 0)
 *****************************************************************************/
static MSF_BOOL handleSlideReadOperation(SlideInstanceData *instance, MSF_UINT32 bytesRead)
{
    MSF_BOOL result = TRUE;
    SmaPlayerInfo *playerInfo;
    char *destBuf = NULL;
    MSF_UINT32 destSize = 0;

    playerInfo = getPlayerInfo();
    instance->slideNumber = playerInfo->currentSlide;

    if (instance->objectInfo->type == SLS_OBJECT_TYPE_TEXT)
    {
#ifndef  SMA_CFG_USER_TEMPLATE_SUPPORT
#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
    if (1<=meaMMCGetCurrentActiveMsg() && meaMMCGetCurrentActiveMsg()<=__MMI_MMS_TEMPLATES_NUM__)
    {
        char *Ptr;
        unsigned char *mediaPtr;	
        int mediaSize=0;
        Ptr = NULL;
        mediaPtr = NULL;		
        
        Ptr = GetString((MSF_UINT16)(meaMMCGetCurrentActiveMsg()+MMS_STR_ID_TEMPLATES_TITLE_01-1));
        if (!Ptr) 
        {
            return FALSE;
        }
        else
        {
            mediaSize = widget_ucs2_length((kal_uint8*)Ptr)*2;
            mediaPtr = SMA_ALLOC(mediaSize+2);
            if (!mediaPtr)
                return FALSE;
            memset(mediaPtr,0x00,mediaSize+2);
            memcpy(mediaPtr,Ptr,mediaSize+1);
            mediaSize=widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
            
            memset(instance->buffer, 0x0, SMA_MAX_CHUNK_SIZE);
            widget_ucs2_to_utf8_string((kal_uint8*)instance->buffer,mediaSize+1,(kal_uint8*)mediaPtr);
            SMA_FREE(mediaPtr);
            instance->objectInfo->info.text.size=strlen(instance->buffer);
            {
                int i=instance->objectInfo->info.text.size;
                int j;					
                for (j=0; j<i; j++)
                {
                    if (*(instance->buffer+j)&0x80)
                    {
                        instance->objectInfo->info.text.charset = SMA_UTF8;
                        break;
                    }
                }
            }	
        }
    }
#endif /* defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT) && defined(__MMI_MMS_TEMPLATES_NUM__) */
#endif /* SMA_CFG_USER_TEMPLATE_SUPPORT*/

#ifndef  SMA_CFG_USER_TEMPLATE_SUPPORT
#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
        if (1<=meaMMCGetCurrentActiveMsg() && meaMMCGetCurrentActiveMsg()<=__MMI_MMS_TEMPLATES_NUM__)
        {
#endif
        /* if not UTF8, try to convert the text */
        if ((instance->objectInfo->info.text.charset == SMA_UTF8) ||
		(instance->objectInfo->info.text.charset == SMA_US_ASCII) || /* UTF-8 and US-ASCII has same format, just change */
		(instance->objectInfo->info.text.charset == SMA_UNKNOWN_CHARSET))	/* UNKNOWN CHARSET will be recogzied as UTF8*/
        {
		instance->objectInfo->info.text.charset = SMA_UTF8;
		destBuf = instance->buffer;
		destSize = bytesRead;
        }
        else														/* convert text to charset utf8 */
        {
            destBuf = convertToUTF8(instance->objectInfo->info.text.charset, instance->buffer, &bytesRead, &destSize);
        }
        
        if (NULL != destBuf)	/* Check for links */
        {
            if (NULL == instance->objectInfo->info.text.links)	/* Create a new list*/
                instance->objectInfo->info.text.links = smaCreateUrlList(destBuf, destSize);
        }
       
        if (!displayTextObject(SMA_GADGET_STRING, instance->objectInfo, destBuf))	 /* Text object */
        {
            result = FALSE;		/* unable to display text object */
        } 
        destBuf = NULL;
        instance->leftToRead = 0;			/* It's not possible to get text in chunks. Just get the next object */
        instance->readPos += bytesRead;

#endif /* #if (!defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) || (!defined(__MMI_MMS_TEMPLATES_NUM__))*/
#endif /* SMA_CFG_USER_TEMPLATE_SUPPORT*/

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
#ifndef  SMA_CFG_USER_TEMPLATE_SUPPORT

#if (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))
        }
        else
#endif /* (defined(MMS_TMPLATES_MULTIPLE_LANG_SUPPORT)) && (defined(__MMI_MMS_TEMPLATES_NUM__))*/
#endif /* SMA_CFG_USER_TEMPLATE_SUPPORT*/
        {
            instance->leftToRead = 0;			/* It's not possible to get text in chunks. Just get the next object */
            instance->readPos += bytesRead;
            result = -1;
            (void)SMA_SIGNAL_SENDTO_I(SMA_FSM_SLIDE,SMA_SIG_GET_TOTAL_TEXT_HEIGHT, bytesRead);
        }
#endif
    }
    else if (instance->objectInfo->type == SLS_OBJECT_TYPE_AUDIO)				/* Audio object */
    {
        if(!setAudioObject(instance->audioHandle))  /* we don't play it now, but in showSlideForm() to sync the playing */
        {
            result = FALSE;		/* unable to play audio object */
        }
        //(void)MSF_WIDGET_RELEASE(instance->audioHandle);	/* audio will be pending, so should not be released now, but when it's stopped */
        instance->audioHandle = 0;							/* audio handle is taken over by smaSlideForm.audioHandle in saui.c */
        instance->leftToRead = 0;
//        instance->readPos += bytesRead;
        instance->readPos += instance->objectInfo->info.audio.size;
    }
    else if (instance->objectInfo->type == SLS_OBJECT_TYPE_IMAGE)
    {
        if(!displayImageObject(instance->objectInfo, instance->imageHandle))
        {
            if (instance->objectInfo->info.image.alt != NULL)			/* Display the alternative text object instead if unable to display image object */
            {
                displayAlternativeTextObject(instance->objectInfo);	
            }
            else
                result = FALSE;		/* even unable to display substitute object */
        }
        (void)MSF_WIDGET_RELEASE(instance->imageHandle);
        instance->imageHandle = 0;
        instance->leftToRead = 0;
//        instance->readPos += bytesRead;
        instance->readPos += instance->objectInfo->info.image.size;
    } 
    else if (instance->objectInfo->type == SLS_OBJECT_TYPE_VIDEO)
    {
        if(!playVideoObject(instance->objectInfo, instance->videoHandle))
        {
            if (instance->objectInfo->info.video.alt != NULL)			/* Display the alternative text object instead if unable to display image object */
            {
                displayAlternativeTextObject(instance->objectInfo);	
            }
            else
                result = FALSE;		/* even unable to display substitute object */
        }
        //(void)MSF_WIDGET_RELEASE(instance->videoHandle);
        instance->videoHandle = 0;
        instance->leftToRead = 0;
//        instance->readPos += bytesRead;
        instance->readPos += instance->objectInfo->info.video.size;
    } 
    else if (instance->objectInfo->type != SLS_OBJECT_TYPE_NONE)					/* Unknown object type */
    {
        result = FALSE;
    }
   
    return result;
} /* handleSlideReadOperation */

/*! This function is called when DRM content can not be displayed.
 *
 * \param object The current object.
 *****************************************************************************/
static void handleFailedToDisplayDrm(SmaObjectInfo *object)
{
    /* Failed to handle the DRM content */
    switch(object->type)
    {
	case SLS_OBJECT_TYPE_IMAGE:
        displayImageObject(slideInstance->objectInfo, MSF_WIDGET_IMAGE_GET_PREDEFINED(MEA_IMG_IMAGE_ERROR, NULL));
        break;
    case SLS_OBJECT_TYPE_VIDEO:
        displayImageObject(slideInstance->objectInfo, MSF_WIDGET_IMAGE_GET_PREDEFINED(MEA_IMG_VIDEO_ERROR, NULL));
        break;
	case SLS_OBJECT_TYPE_TEXT:
        displayTextObject(SMA_GADGET_STRING, object, NULL);
        break;
    }
    /* Next object ? */
    smaHandleNextObject(slideInstance->objectInfo, 
        slideInstance->callingFsm, slideInstance->returnSig, 
        SMA_RESULT_ERROR);
} /* handleFailedToDisplayDrm */

/*!
 *\brief Start the retrieval of a media object
 * \param sig The signal received.
 *****************************************************************************/
static void generateObject(SmaObjectInfo *object)
{
	MSF_UINT32 sizeToRead = 0;
	MsfPartialFileData* data = NULL;	
	char *fileName = getPlayerInfo()->filePath;
	MSF_INT32 msfType = 0;
	
	slideInstance->objectInfo = object;

	if(slideInstance->objectInfo == NULL)
	{
		SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
		return;	
	}

	/* sanity check */
	switch (slideInstance->objectInfo->type)  /* tag: <img>/<text>/<audio>/<video> */
	{
		case SLS_OBJECT_TYPE_IMAGE:	
			msfType = convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.image.type);
			if(slideInstance->objectInfo->info.image.size == 0 || msfType == -1 ||
			    isKnownType(slideInstance->objectInfo->info.image.type, SLS_OBJECT_TYPE_IMAGE) == FALSE)
			{
				SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
				return; 
			}
			break;
		case SLS_OBJECT_TYPE_AUDIO: 
			msfType = convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.audio.type);
			if(slideInstance->objectInfo->info.audio.size == 0 || msfType == -1 ||
			    isKnownType(slideInstance->objectInfo->info.audio.type, SLS_OBJECT_TYPE_AUDIO) == FALSE)
			{
				SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
				return; 
			}
			break;
		case SLS_OBJECT_TYPE_VIDEO:
			msfType = convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.video.type);
			if(slideInstance->objectInfo->info.video.size == 0 || msfType == -1 ||
			    isKnownType(slideInstance->objectInfo->info.video.type, SLS_OBJECT_TYPE_VIDEO) == FALSE)
			{
				SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
				return; 
			}
			break;
		case SLS_OBJECT_TYPE_TEXT:
			if(slideInstance->objectInfo->info.text.size == 0 || 
			    isKnownType(slideInstance->objectInfo->info.text.type, SLS_OBJECT_TYPE_TEXT) == FALSE)
			{
				SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
				return; 
			}
			break;
	}
	
	/* Image, audio and video use partial(virtual) file interface */
	if(slideInstance->objectInfo->type == SLS_OBJECT_TYPE_IMAGE || slideInstance->objectInfo->type == SLS_OBJECT_TYPE_AUDIO
		|| slideInstance->objectInfo->type == SLS_OBJECT_TYPE_VIDEO)
	{
		data = SMA_ALLOC(sizeof(MsfPartialFileData));		
		if(!data)
			return;				
		data->filename = SMA_ALLOC(strlen(fileName)+1);
		if(!data->filename)
		{
			SMA_FREE(data);
			return;
		}
		strcpy(data->filename,fileName);
	}

	switch (slideInstance->objectInfo->type)       
	{
		case SLS_OBJECT_TYPE_IMAGE:		/* Use virtual file interface */
			data->start_offset=slideInstance->objectInfo->info.image.offset;
			data->data_size=slideInstance->objectInfo->info.image.size;
			slideInstance->readPos = slideInstance->objectInfo->info.image.offset;
			slideInstance->leftToRead =0;
			slideInstance->imageHandle=MSF_WIDGET_IMAGE_CREATE_RESOURCE (MSF_MODID_SMA, (char*)data, 
							(MsfResourceType)MsfResourcePartialFile, (MsfImageFormat)msfType);

			if(slideInstance->imageHandle == 0)
			{
				(void)SMA_SIGNAL_SENDTO_U( SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
			}
			SMA_FREE(data->filename);
			SMA_FREE(data);
			break;

		case SLS_OBJECT_TYPE_AUDIO:		/* Use virtual file interface */
			data->start_offset=slideInstance->objectInfo->info.audio.offset;
			data->data_size=slideInstance->objectInfo->info.audio.size;
			slideInstance->readPos = slideInstance->objectInfo->info.audio.offset;
			slideInstance->leftToRead =0;
			slideInstance->audioHandle=MSF_WIDGET_SOUND_CREATE_RESOURCE (MSF_MODID_SMA, (char*)data, 
							(MsfResourceType)MsfResourcePartialFile, (MsfSoundFormat)msfType);

			if(slideInstance->audioHandle == 0)
			{
				(void)SMA_SIGNAL_SENDTO_U( SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
			}
			SMA_FREE(data->filename);
			SMA_FREE(data);
	        	break;

		case SLS_OBJECT_TYPE_VIDEO:		/* Use virtual file interface */
			data->start_offset=slideInstance->objectInfo->info.video.offset;
			data->data_size=slideInstance->objectInfo->info.video.size;
			slideInstance->readPos = slideInstance->objectInfo->info.video.offset;
			slideInstance->leftToRead =0;
			slideInstance->videoHandle=MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE (MSF_MODID_SMA, (char*)data, 
							(MsfResourceType)MsfResourcePartialFile, (MsfVideoFormat)msfType);

			if(slideInstance->videoHandle == 0)
			{
				(void)SMA_SIGNAL_SENDTO_U( SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
			}
			SMA_FREE(data->filename);
			SMA_FREE(data);
	        	break;

		case SLS_OBJECT_TYPE_TEXT:		/* Use buffer: read at most 4095 byte per slide */
			slideInstance->readPos = slideInstance->objectInfo->info.text.offset;
			slideInstance->leftToRead = slideInstance->objectInfo->info.text.size;
			if(slideInstance->leftToRead > SMA_MAX_CHUNK_SIZE - 1)
            {
				sizeToRead = SMA_MAX_CHUNK_SIZE - 1;
                smaSlideSetTextTrunc(TRUE);
            }
			else
            {
                sizeToRead = slideInstance->leftToRead;
                smaSlideSetTextTrunc(FALSE);
            }
            slideInstance->textSize = sizeToRead;

                     if(sizeToRead > 0)
                     {
                         memset(slideInstance->buffer, 0x0, SMA_MAX_CHUNK_SIZE);
			    smaAsyncRead(slideInstance->asioReadHandle, (MSF_INT32)slideInstance->readPos, slideInstance->buffer, sizeToRead);
                     }
                     else
                     {
                         smaAsyncOperationStop(&slideInstance->asioReadHandle);
			    SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                     }
			break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		default:
			SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
			break;
	    } /* switch */
} /* generateObject */

#ifdef __DRM_SUPPORT__
static void generateDRMObject(SmaObjectInfo *object)
{
    MSF_INT32 fileHandle = 0;
    MSF_INT32 fileSize = 0;
    MmsMsgId currentMsgId = getPlayerInfo()->msgId;
    char *fileName = getPlayerInfo()->filePath;	/* MMS file */
    char fileNameUTF8[WIDGET_RAWFILE_NAMELEN];					/* encrypted DCF (UTF8) */
    char *vFileName = NULL;					/* vitual file name */
    unsigned char * externalVFileName = NULL;	/* translated vitual file name */
    SlsMediaType slsType = SLS_UNKNOWN;

    slideInstance->objectInfo = object;

    if(slideInstance->objectInfo == NULL)
    {
        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        return;
    }

    if (slideInstance->objectInfo->type == SLS_OBJECT_TYPE_IMAGE)
    {
        fileSize = slideInstance->objectInfo->info.image.size;
        slsType = slideInstance->objectInfo->info.image.type;
    }
    else if (slideInstance->objectInfo->type == SLS_OBJECT_TYPE_VIDEO)
    {
        fileSize = slideInstance->objectInfo->info.video.size;
        slsType = slideInstance->objectInfo->info.video.type;
    }
    else if (slideInstance->objectInfo->type == SLS_OBJECT_TYPE_AUDIO)
    {
        fileSize = slideInstance->objectInfo->info.audio.size;
        slsType = slideInstance->objectInfo->info.audio.type;
    }
    else if (slideInstance->objectInfo->type == SLS_OBJECT_TYPE_TEXT)
    {
        fileSize = slideInstance->objectInfo->info.text.size;
        slsType = slideInstance->objectInfo->info.text.type;
    }
    else
    {
        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        return;
    }

    slideInstance->objectInfo->isDrm = TRUE;
    slideInstance->objectInfo->offset = getDreOffset(slideInstance->objectInfo);

    vFileName = SMA_ALLOC(WIDGET_RAWFILE_NAMELEN);
    ASSERT(vFileName != NULL);

    /*generate virtual file */
    fileHandle = MSF_FILE_OPEN( MSF_MODID_SMA, fileName, MSF_FILE_SET_RDONLY, 0);
    if(fileHandle < 0)
    {
        SMA_FREE(vFileName);
        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        return;
    }
    
    if(HDIa_fileGenVirtualFileName(fileHandle, vFileName, WIDGET_RAWFILE_NAMELEN, slideInstance->objectInfo->offset, fileSize) != HDI_FILE_OK)
    {
        SMA_FREE(vFileName);
        MSF_FILE_CLOSE(fileHandle);
        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        return;
    }
    
    externalVFileName = HDI_FileNameTranslate(vFileName);

    /* DRM process from virtual file to generate encrypted DCF file */
    if (slsType == SLS_DRM_MESSAGE)
    {
        MSF_INT32 offset = 0;
        MSF_UINT32 size = 0;
        SlsMediaType drmType = SLS_UNKNOWN;

#ifdef MTK_TMP_PATCH  /* To fix issue casued by DRM interface change for Jataayu */
        char *outputFile = NULL;    /* encrypted DCF (UCS2) */

        memset(fileNameUTF8, 0, WIDGET_RAWFILE_NAMELEN);
        sprintf(fileNameUTF8, "%s%lx-%lx.vvvvvvvvvv", MMS_FOLDER, currentMsgId, slideInstance->objectInfo->offset);
        outputFile = (char *)HDI_FileNameTranslate(fileNameUTF8);
        offset = DRM_process_direct_file((kal_uint8 *)"application/vnd.oma.drm.message", (kal_wchar *) externalVFileName, (kal_wchar *) outputFile, (kal_uint32 *)&size);
        widget_ucs2_to_utf8_string((kal_uint8 *)fileNameUTF8, WIDGET_RAWFILE_NAMELEN, (kal_uint8 *)outputFile);
        drmType= meaConvertMediaTypeToSls(meaMime2MediaType(meaFileName2MimeType(fileNameUTF8)));
        sprintf(outputFile, "%s%s", HDI_EXTERNAL_PATH, fileNameUTF8);
        MSF_FILE_REMOVE(outputFile);
        HDI_FileNameFree((kal_uint8 *)outputFile);
#else
        static unsigned char fileNameUCS2[200];					/* encrypted DCF (UCS2) */
        sprintf(fileNameUTF8, "%lx-%lx.vvvvvvvvvv", currentMsgId, slideInstance->objectInfo->offset);
        widget_utf8_to_ucs2_string(fileNameUCS2, 200, (const kal_uint8 *)fileNameUTF8);
        offset = DRM_process_direct_file((kal_uint8 *)"application/vnd.oma.drm.message", (kal_wchar *) externalVFileName, (kal_wchar *) fileNameUCS2, (kal_uint32 *)&size);
        widget_ucs2_to_utf8_string((kal_uint8 *)fileNameUTF8, 100, fileNameUCS2);
        drmType= meaConvertMediaTypeToSls(meaMime2MediaType(meaFileName2MimeType(fileNameUTF8)));
#endif

        slideInstance->objectInfo->info.image.drmType = drmType;
        
        if(drmType != SLS_UNKNOWN && drmType != SLS_NOT_USED && offset >= DRM_RESULT_OK)
        {
            MsfPartialFileData* data = NULL;
            data = SMA_ALLOC(sizeof(MsfPartialFileData));
            ASSERT(data != NULL);
            data->filename = SMA_ALLOC(strlen(fileName)+1);
            ASSERT(data->filename != NULL);
            strcpy(data->filename,fileName);

            data->start_offset = slideInstance->objectInfo->offset + offset;
            data->data_size = size;

            switch (slideInstance->objectInfo->type)
            {
                case SLS_OBJECT_TYPE_IMAGE:		/* Use virtual file interface */
                    slideInstance->imageHandle=HDIa_widgetImageCreateResource (MSF_MODID_SMA, (char*)data, 
                    (MsfResourceType)MsfResourcePartialFile, 
                    (MsfImageFormat)convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.image.drmType));
                    if(slideInstance->imageHandle == 0)
                    {
                        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                    }
                    break;
                
                case SLS_OBJECT_TYPE_AUDIO:		/* Use virtual file interface */
                    slideInstance->audioHandle=HDIa_widgetSoundCreateResource (MSF_MODID_SMA, (char*)data, 
                    (MsfResourceType)MsfResourcePartialFile, 
                    (MsfSoundFormat)convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.audio.drmType));
                    if(slideInstance->audioHandle == 0)
                    {
                        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                    }

                    break;

                case SLS_OBJECT_TYPE_VIDEO:		/* Use virtual file interface */
                    slideInstance->videoHandle=HDIa_widgetExtVideoCreateResource (MSF_MODID_SMA, (char*)data, 
                    (MsfResourceType)MsfResourcePartialFile, 
                    (MsfVideoFormat)convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.video.drmType));
                    if(slideInstance->videoHandle == 0)
                    {
                        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                    }
                    break;
                
                default:
                    SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                    break;
            }
            SMA_FREE(data->filename);
            SMA_FREE(data);
        }
        else
        {
            SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        }
    }    
    else if (slsType == SLS_DRM_CONTENT)
    {
        SlsMediaType drmType = SLS_UNKNOWN;
        
        DRM_process_virtual_file ((kal_uint8 *)"application/vnd.oma.drm.content", (kal_wchar *) externalVFileName, NULL); /* generate RO */
        drmType = meaConvertMediaTypeToSls(meaMime2MediaType((char*)DRM_get_content_type(0, (kal_wchar *) externalVFileName)));
        slideInstance->objectInfo->info.image.drmType = drmType;
        if(drmType != SLS_UNKNOWN)
        {
            MSF_UINT8 permission = (kal_uint8)((slideInstance->objectInfo->type == SLS_OBJECT_TYPE_IMAGE) ? DRM_PERMISSION_DISPLAY : DRM_PERMISSION_PLAY);
            if(DRM_validate_permission(0, (kal_wchar *) externalVFileName, permission))
            {
                switch (slideInstance->objectInfo->type)
                {
                    case SLS_OBJECT_TYPE_IMAGE:
                        slideInstance->imageHandle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_SMA, vFileName, 
                         MsfResourceDRMFile, 
                         (MsfImageFormat)convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.image.drmType));
                        if(slideInstance->imageHandle == 0)
                        {
                            SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                        }
                        break;
                        
                    case SLS_OBJECT_TYPE_AUDIO:
                        slideInstance->audioHandle=MSF_WIDGET_SOUND_CREATE_RESOURCE (MSF_MODID_SMA, vFileName, 
                        (MsfResourceType)MsfResourceDRMFile, 
                        (MsfSoundFormat)convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.audio.drmType));
                        if(slideInstance->audioHandle == 0)
                        {
                            SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                        }
                        break;

                    case SLS_OBJECT_TYPE_VIDEO:		/* Use virtual file interface */
                        slideInstance->videoHandle=MSF_WIDGET_EXT_VIDEO_CREATE_RESOURCE (MSF_MODID_SMA, vFileName, 
                        (MsfResourceType)MsfResourceDRMFile, 
                        (MsfVideoFormat)convertSmaToMsfMediaTypes(slideInstance->objectInfo->info.video.drmType));
                        if(slideInstance->videoHandle == 0)
                        {
                            SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                        }
                        break;
                    
                    default:
                        SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
                        break;
                	}
            }
            else
            {
                SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
            }
        }
        else
        {
            SMA_SIGNAL_SENDTO_U(SMA_FSM_SLIDE, SMA_SIG_SLIDE_READ_RSP, SMA_ASIO_RESULT_ERROR);
        }
    }
    else
    {
        ASSERT(0);
    }

    HDI_FileNameFree(externalVFileName);
    SMA_FREE(vFileName);
    MSF_FILE_CLOSE(fileHandle);
}
#endif /* __DRM_SUPPORT__ */

/*! Handles the next object on the current slide, if no other object exists
 *  a call-back signal is generated. 
 *
 * \param object The current object.
 * \param fsm The call-back FSM
 * \param signal The call-back signal.
 * \param result The call-back result
 *****************************************************************************/
static void smaHandleNextObject(SmaObjectInfo *object, SmaStateMachine fsm, 
    int signal, SmaResult result)
{
    if (object->next != NULL)
    {
#ifdef __DRM_SUPPORT__
        if(getDreOffset(object->next) == 0)
#endif
        {
            generateObject(object->next);
        }
#ifdef __DRM_SUPPORT__
        else
        {
            generateDRMObject(object->next);
        }
#endif
    }
    else
    {
        if (smaSlideIsTextTrunc())
        {
            (void)smaShowPopup(MEA_STR_ID_CONTENT_TRUNCATED, MsfAlert);
        }
        showSlideForm();
        (void)SMA_SIGNAL_SENDTO_U(fsm, signal, result);    /* send signal back */
    }
} 

/*!
 *\brief Continues the retrieval of a media object
 * \param sig The signal received.
 *****************************************************************************/
static void generateObjectContinue()
{
    MSF_UINT32 sizeToRead = slideInstance->bufferSize;

    if (slideInstance->leftToRead < slideInstance->bufferSize)
    {
        sizeToRead = slideInstance->leftToRead;
    } /* if */
    smaAsyncRead(slideInstance->asioReadHandle, (MSF_INT32)slideInstance->readPos,
        slideInstance->buffer, sizeToRead);
} /* generateObjectContinue */

/*!
 * \brief Get data for slide
 * \param number The slide to show.
 * \param playerInfo Information about the smil.
 * \param callingFsm FSM requesting to play the smil
 * \param returnSig Return signal.
 *****************************************************************************/
void generateSlide(MSF_UINT8 number, SmaPlayerInfo *playerInfo, 
    MSF_UINT32 callingFsm, int returnSig)
{
    SmaSlideInfo *slide;	
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
	SmaObjectInfo *currentObject = NULL;
	SmaObjectInfo *textObject = NULL;
	SmaObjectInfo *imageObject = NULL;
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */
#ifdef WAP_SUPPORT
	MsfStringHandle strHandle;
	char *str = NULL;
	unsigned int len;
	/* Calculate the length for the string */
	len = (strlen("20") * 2) + sizeof(SLASH_CHAR) + 1;
	str = SMA_ALLOC((MSF_UINT32)len);
	if (str == NULL)
		return;
	/* Format string */
	sprintf(str, "%d%c%d", number+1, SLASH_CHAR, playerInfo->noOfSlides);
	strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, str, MsfUtf8, 
        (int)strlen(str) + 1, 0);

       (void)MSF_WIDGET_SET_TITLE(getSlideFormHandle(), strHandle);
       SMA_FREE(str);
#endif /* WAP_SUPPORT */

	if (playerInfo == NULL || number > playerInfo->noOfSlides) { return; } 
	
    smaSlideSetTextTrunc(FALSE);
	clearSlideForm();
	slide = getSlideInfo(number, playerInfo);

	slideInstance->callingFsm = callingFsm;
	slideInstance->returnSig = returnSig;

#ifdef WIDGET_SLIDING_SMIL_SUPPORT 
	currentObject = &slide->object;

	if(currentObject == NULL)    /* The slide is empty */
	{
		showSlideForm();
		(void)SMA_SIGNAL_SENDTO_U(slideInstance->callingFsm, slideInstance->returnSig, SMA_RESULT_OK);
		return;
	}
	
	while (currentObject)
	{
		switch (currentObject->type)
		{
			case SLS_OBJECT_TYPE_TEXT:
				textObject = currentObject;
				break;
			case SLS_OBJECT_TYPE_IMAGE:
			case SLS_OBJECT_TYPE_VIDEO:
				imageObject = currentObject;
				break;
			default:
				break;
		}
		currentObject = currentObject->next;
	}
	if (textObject && imageObject && 
		(imageObject->info.image.region.position.cy.value > textObject->info.text.region.position.cy.value))
	{
        smaSetImageOnTop(FALSE);  /* smtrrend.c may update sliding info */
        HDIa_widgetExtFormSetSlidingSMIL(getSlideFormHandle(), KAL_FALSE, 0);
	}
	else
	{
        smaSetImageOnTop(TRUE);  /* smtrrend.c may update sliding info */
        HDIa_widgetExtFormSetSlidingSMIL(getSlideFormHandle(), KAL_TRUE, 0);
	}
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */

	if (slideInstance->asioReadHandle == 0)
	{
	    slideInstance->asioReadHandle = 
	    smaAsyncOperationStart(playerInfo->filePath, SMA_FSM_SLIDE, 0L, 
	    SMA_SIG_SLIDE_READ_RSP, SMA_ASYNC_MODE_READ);
	}

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    if (!MMA_IS_UNIFIED_COMPOSER_ACTIVE() || 
        playerInfo->currentSlide != number || number != 0)
#endif
    smaUiShowWaitScreen();

#ifdef __DRM_SUPPORT__
    if(getDreOffset(&slide->object) != 0)
    {
        generateDRMObject(&slide->object);
    }
    else
#endif
    generateObject(&slide->object);
    playerInfo->currentSlide = number;           
} /* generateSlide */

/*! Checks if the content is DRM protected
 *
 * \param mediaType
 * \return TRUE if the content is DRM protected
 *****************************************************************************/
static MSF_BOOL isDrmContent(SlsMediaType mediaType)
{
    unsigned int i;
    const SmaMediaTypeItem *items;
    items = smaGetSupportedMediaTypes();
    i = 0;
    while(SLS_NOT_USED != items[i].slsMediaType)
    {
        /* Find the current item */
        if (mediaType == items[i].slsMediaType)
        {
            /* Check if it is a DRM type */
            return (items[i].slsObjectType == SLS_OBJECT_TYPE_DRM) ? TRUE: FALSE;
        }
        ++i;
    }
    return FALSE;
}

/*!
 * \brief Tells weather the object is of DRM type or not, return offset.
 * \param slide slide to check.
 * \return offset in file if object is DRM, 0 otherwise
 *****************************************************************************/
static MSF_UINT32 getDreOffset(const SmaObjectInfo *object)
{
    MSF_UINT32 ret = 0;

    switch(object->type)
    {
    case SLS_OBJECT_TYPE_IMAGE:
        if (object->isDrm || isDrmContent(object->info.image.type))
        {
            ret = object->info.image.offset;
        }
        break;
    case SLS_OBJECT_TYPE_AUDIO:
        if (object->isDrm || isDrmContent(object->info.audio.type))
        {
            ret = object->info.audio.offset;
        }
        break;
    case SLS_OBJECT_TYPE_TEXT:
        if (object->isDrm || isDrmContent(object->info.text.type))
        {
            ret = object->info.text.offset;
        }
        break;
    case SLS_OBJECT_TYPE_VIDEO:
        if (object->isDrm || isDrmContent(object->info.video.type))
        {
            ret = object->info.video.offset;
        }
        break;
    }
    return ret;
} /* objectIsDrm */

static void smaSlideSetTextTrunc(MSF_BOOL isTrunc)
{
    isTextTrunc = isTrunc;
}

static MSF_BOOL smaSlideIsTextTrunc(void)
{
    return isTextTrunc;
}

