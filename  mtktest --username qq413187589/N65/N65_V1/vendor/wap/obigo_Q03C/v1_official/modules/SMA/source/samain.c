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
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_chrs.h"
#include "msf_tel.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for video */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* SMA */
#include "sma_if.h"
#include "sma_cfg.h"
#include "samem.h"
#include "satypes.h"
#include "samain.h"
#include "saui.h"
#include "saintsig.h"
#include "saslide.h"
#include "saasync.h"
#include "sasbp.h"
#include "salnk.h"
#include "sauidia.h"
#include "sma_def.h"
#include "sma_rc.h"
#include "saph.h"
#include "sapipe.h"
#include "saattach.h"
#include "sasls.h"

#if defined (__DRM_SUPPORT__) || defined (__UNIFIED_MSG_SUPPORT__)
#include "mms_def.h" //for MmsMsgId
#include "mea_cfg.h" //for MMS_DRM_FOLDER 
#endif /* __DRM_SUPPORT__ */

#ifdef __UNIFIED_MSG_SUPPORT__
#include "mms_cfg.h"
#include "mms_if.h"
#include "mea_def.h" /* MeaFolder */
#include "mea_if.h"
#include "wap_um.h"
#endif

/* MMA */
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mmsadp.h"
#endif

/*--- Definitions/Declarations ---*/
/* Define the highest number a long can hold. 
   This is for function convertToUTF8() */
#define SMA_MAXIMUM_LONG_POSITIVE_VALUE	0x7FFFFFFF

/*! Defines the optional UTF-8 identifier */
#define SMA_UTF8_BOM                    "\xEF\xBB\xBF"

/*! Defines the first slide */

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/
#ifdef WAP_SUPPORT
static int smaCountDownTime=0;
#endif /* WAP_SUPPORT */

static const SmaMediaTypeItem supportedMediaTypes[] = 
    SMA_CFG_SUPPORTED_MEDIA_TYPES;

/* Information about the smil player and the current state. */
static SmaPlayerInfo smaInfo;
static MSF_BOOL isRunning = FALSE;
static MSF_BOOL isInitialized = FALSE;

/* result code for exit operation */
static SmaResult    sma_exit_result;

/* Buffer used for longjumps */
static jmp_buf *panicJmpbuf;

/* Variable for keeping panic code */
int smaPanicMode = SMA_PANIC_NO_DIALOG;

/* Buffer used for text convertion in function convertToUTF8()*/
static char *smaDestBuffer = NULL;
/*--- Prototypes ---*/

static void mainSignalHandler(SmaSignal *sig);
static void freeSmaObjectInfo(SmaObjectInfo *object);
static void freeSmaSlideInfo(SmaSlideInfo *slide);
static void freeSmaData(SmaData *data);


/*****************************************************************************
 * Exported functions                                                        *
 *****************************************************************************/

/*! \brief Initiates the SMA module. 
*****************************************************************************/
MSF_BOOL smaMainInit(void)
{
    /* register signal handler */
    smaSignalRegisterDst(SMA_FSM_MAIN, mainSignalHandler);

    memset(&smaInfo, 0x00, sizeof(smaInfo));
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    if (MMA_IS_UNIFIED_COMPOSER_ACTIVE() == TRUE)
#else
	if ( meaSmilEditorIsActive() )
#endif
    {
        smaInfo.isAutoplay = TRUE;
    }
	else
    {
	    smaInfo.isAutoplay = FALSE;
    }
#endif

    smaInfo.data.buffer = SMA_ALLOC( SMA_MAX_CHUNK_SIZE);
    smaInfo.data.bufferSize = SMA_MAX_CHUNK_SIZE;
    if (smaInfo.data.buffer == NULL)
    {
        smaMainTerminate();
        return FALSE;
    } /* if */	
    return TRUE;
} /* smaMainInit */


/*! \brief Exit the SMIL player, NOTE the SMA module is not terminated 
 *         when this function is called. This function should only be called
 *         from internal functions.
 * \param mode termination mode.
 * \param result the result code 
 *****************************************************************************/ 
                  
void smaPanic( int mode, SmaResult result)
{
    sma_exit_result = result;
    smaPanicMode = mode;
	longjmp( *panicJmpbuf, SMA_PANIC);	
} /* smaPanic */


/*! \brief Gets the sma_exit_result
 *
 * \return sma_exit_result
*****************************************************************************/
SmaResult getSmaExitResult(void)
{
	return sma_exit_result;
} /* getSmaExitResult */


/*! \brief Must be called prior to smaPanic, to set the buffer for longjump
 *
*****************************************************************************/
void smaSetJumpBuffer(jmp_buf *jmpbuf)
{
	panicJmpbuf = jmpbuf;
}


/*****************************************************************************
 * Internal functions                                                        *
 *****************************************************************************/


/*! \brief Free all memory in SmaPlayerInfo
 *
 * \param playerInfo Pointer to the structure to free.
 *****************************************************************************/
void freeSmaPlayerInfo(SmaPlayerInfo *playerInfo)
{
    if (!playerInfo)
    {
        return;
    } /* if */
    
    if (playerInfo->filePath)
    {
        SMA_FREE( playerInfo->filePath);
        playerInfo->filePath = NULL;
    } /* if */
   
    freeSmaSlideInfo(&playerInfo->slideInfo);

    freeSmaData(&playerInfo->data);
    smaFreeAttachmentList(&(playerInfo->unrefList));
} /* freeSmaPlayerInfo */


/*! \brief Free all memory in SmaData
 *
 * \param data Pointer to the structure to free.
 *****************************************************************************/
static void freeSmaData( SmaData *data)
{
    if ( !data)
    {
        return;
    } /* if */

    if ( data->buffer)
    {
        SMA_FREE( data->buffer);
        data->buffer = NULL;
    } /* if */
} /* freeSmaData */

/*! \brief Removes the optional UTF-8 mark if it is present
 *
 * \param str The string to remove the "possible" UTF-8 mark from.
 *****************************************************************************/
static void handleUtf8Bom(char *str)
{
    if (NULL != str)
    {
        /* Check if the optional UTF-8 identifier is present */
        if ((strlen(str) > strlen(SMA_UTF8_BOM)) && 
            (memcmp(str, SMA_UTF8_BOM, strlen(SMA_UTF8_BOM)) == 0))
        {
            /* Move the content back in the buffer so that the identifier is
               removed */
            memmove(str, &(str[strlen(SMA_UTF8_BOM)]), 
                strlen(str) - strlen(SMA_UTF8_BOM) + 1);
        }
    }
}

/*!
 * \brief Converts a buffer to UTF8. This function can only be used if the 
 *        caller knows that the result buffer will be less or equal in size
 *        then SMA_MAX_TEXT_SIZE.
 * 
 * \param charset Charset of srcData buffer
 * \param srcData Buffer containing text to be converted
 * \param srcSize srcData buffer size
 * \param dstSize Size of the returned destination buffer
 * \return dstData Buffer containing converted text UTF8. 
 *         The caller must free this buffer, NULL if not converted
 ****************************************************************************/
char *convertToUTF8( MSF_UINT32 charset, const char *srcData, 
    MSF_UINT32 *srcSize, MSF_UINT32 *dstSize)
{
    /* MMS to MSF type conversion */
    msf_charset_convert_t *convFunc;
	int length;	
	/* Set destSize to the highest number a long can hold.
	   This is to make the first convFunc() call write a 
	   correct value to destSize. If destSize is not set or 
	   set to 0, the first destSize will be 0 after convFunc(). */
    long destSize = SMA_MAXIMUM_LONG_POSITIVE_VALUE;

    if ( (charset == MSF_CHARSET_UTF_8))
    {
        return NULL;
    }

    length = (int)*srcSize;

    convFunc = msf_charset_find_function_bom((int)charset, 
        MSF_CHARSET_UTF_8, (char *)srcData, &length);
    if (NULL != convFunc)
    {
        /* Find buffer size */
        if (0 != convFunc((const char *)srcData, (long *)srcSize, NULL, &destSize))
        {
            return NULL;
        }
        /* Allocate buffer */
        smaDestBuffer = SMA_ALLOC((unsigned long)destSize+1);
        if (NULL == smaDestBuffer)
        {
            return NULL;
        }

        /* Do the conversion */
        if (0 != convFunc((const char *)srcData, (long *)srcSize, smaDestBuffer, 
            &destSize))
        {
            /*lint -e{774}*/
            SMA_FREE(smaDestBuffer);
            return NULL;
        }

        /* Append Null character just in case */
        smaDestBuffer[destSize] = 0;
        ++destSize;

        *srcSize = (MSF_UINT32)length;
		*dstSize = (MSF_UINT32)destSize;
        /* Removes the option UTF8 identifier if present */
        handleUtf8Bom(smaDestBuffer);        
        return smaDestBuffer;
    }
    return smaDestBuffer;
} /* convertToUTF8 */


/*! \brief Clear all current the SMIL player information, NOTE the SMA module 
 *   is not terminated by this function.
 *
 * \param result The result code to return
 * \sendRsp TRUE if the result signal should be sent to be sent, else FALSE
 *****************************************************************************/                   
void exitSmilPlayer(SmaResult result, MSF_BOOL sendRsp)
{
    SmaPlayerInfo *playerInfo;
	MSF_UINT8 sourceModule;

	playerInfo = getPlayerInfo();
	sourceModule = playerInfo->sourceModule;

    HDIa_widgetExtRegisterSwitchWidgetScreenCallback(NULL);

	/* nothing to do if failed to stop playing */
    (void)stopSmil( &smaInfo);
    
    smaUiTerminate();
    smaSbpTerminate();
	smaPipeTerminate();
    smaAttachmentTerminate();
	if (sendRsp)
	{
		sendResult( sourceModule, result);
	} /* if */
	if (NULL != smaDestBuffer)
	{
		SMA_FREE(smaDestBuffer);
		smaDestBuffer = NULL;
	}
    smaSlideTerminate();
	smaAsyncTerminate();
	smaTerminateDia();	
	smaSignalTerminate();
    smaMainTerminate();
    setSmaIsRunning(FALSE);
	smaPhTerminate(TRUE);
    setSmaIsInitialized(FALSE);
} /* exitSmilPlayer */


/*! \brief Terminate the Sma Core.
 *****************************************************************************/    
void smaMainTerminate( void)
{
    freeSmaPlayerInfo( &smaInfo);
    memset( &smaInfo, 0x00, sizeof(smaInfo));
} /* smaMainTerminate */



/*!
 * \brief Plays a smil
 * 
 * \param playerInfo A pointer to the information about the smil.
 *
 * \return The result of the operation.
 *****************************************************************************/
SmaResult playSmil( SmaPlayerInfo *playerInfo)
{
    SmaResult result = SMA_RESULT_OK;
    if ( playerInfo->isPlaying == TRUE)
    {
        /* already running */
        return result;
    } /* if */
    
    playerInfo->isPlaying = TRUE;
	updateSlideFormActions(playerInfo->isPlaying);
    
#ifndef WAP_SUPPORT
    if ( playerInfo->currentSlide == (playerInfo->noOfSlides - 1))
    {   
        /* on last slide */
        playerInfo->currentSlide = SMA_FIRST_SLIDE;
    } /* if */

    (void)showStatusIcon(SMA_ACTION_PLAY);
#endif /* ~WAP_SUPPORT */
    generateSlide( playerInfo->currentSlide, playerInfo, 
        SMA_FSM_MAIN, SMA_SIG_MH_SET_TIMER);

    return result;
} /* playSmil */


/*!
 * \brief Displays the previous slide
 * 
 * \param playerInfo A pointer to the information about the smil.
 *
 * \return The result of the operation.
 *****************************************************************************/
SmaResult displayPreviousSlide( SmaPlayerInfo *playerInfo)
{
    SmaResult result = SMA_RESULT_OK;
    MSF_UINT8 prevSlide;

#ifdef WAP_SUPPORT
    MSF_BOOL renderView = TRUE;

    HDIa_widgetExtRegisterSwitchWidgetScreenCallback(NULL);
    
    if ( playerInfo->isPlaying &&  
        (playerInfo->currentSlide == SMA_FIRST_SLIDE))
    {
        /* in playmode and on last slide */
        /* STOP */
        result = stopSmil( playerInfo);
        renderView = FALSE;
    }
    else if ( playerInfo->isPlaying == FALSE &&
        (playerInfo->currentSlide == SMA_FIRST_SLIDE))
    {
        renderView = FALSE;
    } 
    else
    {
        /* NOT first slide */
        prevSlide = playerInfo->currentSlide - 1;
        renderView = TRUE;
    }

    /* Stop sliding timer here*/
    stopPlayTimer();

    if ( renderView && playerInfo->isPlaying) 
        generateSlide( prevSlide, playerInfo, 
            SMA_FSM_MAIN, SMA_SIG_MH_SET_TIMER);
    else if ( renderView)
#else
    result = stopSmil (playerInfo);
    
    if ( playerInfo->currentSlide == SMA_FIRST_SLIDE)
    {
        playerInfo->currentSlide = (MSF_UINT8)(playerInfo->noOfSlides - 1);
    } 
    else
    {
        prevSlide = playerInfo->currentSlide - 1;
    }/* if */
#endif /* WAP_SUPPORT */

    generateSlide( prevSlide, playerInfo, 
        SMA_FSM_MAIN, SMA_SIG_MH_NO_TIMER);
    
    return result;
} /* displayPreviousSlide */


/*! \brief Sends result to calling module
 *  \param senderModule module to send result to
 *  \param result Result code to send to calling module
 *****************************************************************************/
void sendResult(MSF_UINT8 senderModule, SmaResult result)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    /* nothing to do if failed to stop playing */
    (void)stopSmil( &smaInfo);
    
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&result))
    {
        return;
    } /* if */

    length = (MSF_UINT16)cvt.pos;

    sig = MSF_SIGNAL_CREATE (SMA_SIG_PLAY_SMIL_RSP, MSF_MODID_SMA, 
        senderModule, length);
    
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, MSF_MODID_SMA);
    
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&result))
    {
        return;
    } /* if */

    MSF_SIGNAL_SEND (sig);
} /* sendResult */


/*!
 * \brief Rewinds the smil message
 * 
 * \param playerInfo A pointer to the information about the smil.
 *
 * \return The result of the operation.
 *****************************************************************************/
SmaResult rewindSmil( SmaPlayerInfo *playerInfo)
{
    SmaResult result = SMA_RESULT_OK;

    if ((playerInfo->isPlaying == FALSE) && 
        playerInfo->currentSlide != SMA_FIRST_SLIDE)
    {
        /* NOT in play mode and NOT on first slide */
        playerInfo->currentSlide = SMA_FIRST_SLIDE;
        generateSlide( playerInfo->currentSlide, playerInfo, 
            SMA_FSM_MAIN, SMA_SIG_MH_NO_TIMER);
    } /* if */
    return result;
} /* rewindSmil */


/*!
 * \brief Stop playing the smil
 * 
 * \param playerInfo A pointer to the information about the smil.
 *
 * \return The result of the operation.
 *****************************************************************************/
SmaResult stopSmil( SmaPlayerInfo *playerInfo)
{
    SmaResult result = SMA_RESULT_OK;
    
#ifdef WIDGET_ANIMATION_ON_SMIL_PLAYING
    MsfImageHandle imageHandle = smaGetImageHandle();
    if (imageHandle > 0)
        HDIa_widgetExtDisableImageAnimation(imageHandle);
#endif
    if (playerInfo->isPlaying == FALSE)  /* not currently running */
    {
        return result;
    }
    
    playerInfo->isPlaying = FALSE;
    updateSlideFormActions(playerInfo->isPlaying);
    stopPlayTimer();  /* reset the timer */
    stopSound();
#ifdef WIDGET_VIRTUAL_FILE_SUPPORT    
    stopVideo(FALSE);
#endif
    displayCountDown(FALSE);

    return result;
} /* stopSmil */

#ifdef WAP_SUPPORT
MSF_BOOL displayCountDown(MSF_BOOL isShow)
{
    if (!isShow)
    {
        HDIa_widgetExtFormSetSmilRemainTime(getSlideFormHandle(), -1);
        return FALSE;
    }
    smaCountDownTime--;
    HDIa_widgetExtFormSetSmilRemainTime(getSlideFormHandle(),smaCountDownTime);
    if (smaCountDownTime >0)
    {
        MSF_TIMER_SET (MSF_MODID_SMA, SMA_SLIDE_TIMER_ID, 
            SMA_ACTION_COUNT_DOWN_TIME);
        return TRUE;
    }
    else
        return FALSE;
}
#endif /* WAP_SUPPORT */
/*!
 * \brief Set the slide timer 
 * 
 * \param duration Delay time.
 *****************************************************************************/
void setPlayTimer( MSF_UINT32 duration)
{     
    if (SMA_MIN_SLIDE_DURATION > duration)
    {
        return;  //if 0, don't set timer
    } /* if */

#ifdef WAP_SUPPORT
    if (SMA_MAX_SLIDE_DURATION < duration)
    {
        smaCountDownTime = SMA_MAX_SLIDE_DURATION;
    }
    else
    {
        smaCountDownTime = duration + 1;
    }

    HDIa_widgetExtFormSetSmilTotalTime(getSlideFormHandle(), duration);
    displayCountDown(TRUE);
    MSF_TIMER_SET (MSF_MODID_SMA, SMA_SLIDE_TIMER_ID, 
                    SMA_ACTION_COUNT_DOWN_TIME);
#else
    MSF_TIMER_SET (MSF_MODID_SMA, SMA_SLIDE_TIMER_ID, 
                    duration * 10);
#endif /* WAP_SUPPORT */
} /* setPlayTimer */

void stopPlayTimer( void)
{
    MSF_TIMER_RESET(MSF_MODID_SMA, SMA_SLIDE_TIMER_ID);
#ifdef WAP_SUPPORT
    //MSF_TIMER_RESET (MSF_MODID_SMA, SMA_ACTION_IMAGE_TIMER_ID);
    smaCountDownTime = 0;
#endif /* WAP_SUPPORT */
} /* stopPlayTimer */



/*!
 * \brief Display the next slide.
 * 
 * \param playerInfo A pointer to the information about the smil.
 *
 * \return The result of the operation.
 *****************************************************************************/
SmaResult displayNextSlide( SmaPlayerInfo *playerInfo)
{

    SmaResult result = SMA_RESULT_OK;
    MSF_BOOL renderView = TRUE;

    HDIa_widgetExtRegisterSwitchWidgetScreenCallback(NULL);

    if ( playerInfo->isPlaying && (playerInfo->currentSlide == ( playerInfo->noOfSlides -1)))
    {
        /* in playmode and on last slide */
        /* STOP */
        result = stopSmil( playerInfo);
        renderView = FALSE;
    }
    else if ( playerInfo->isPlaying == FALSE && (playerInfo->currentSlide == ( playerInfo->noOfSlides -1)))
    {
        renderView = FALSE;
    } 
    else
    {
        /* NOT on last slide */
        playerInfo->currentSlide++;
        renderView = TRUE;
    } /* if */

    /* Stop sliding timer here*/
    stopPlayTimer();

    if ( renderView && playerInfo->isPlaying) 
    {
        generateSlide( playerInfo->currentSlide, playerInfo, 
            SMA_FSM_MAIN, SMA_SIG_MH_SET_TIMER);
    }
    else if ( renderView)
    {
        generateSlide( playerInfo->currentSlide, playerInfo, 
            SMA_FSM_MAIN, SMA_SIG_MH_NO_TIMER);
    } /* if */    
   
    return result;
} /* displayNextSlide */


/*!
 * \brief Display the next slide.
 * 
 * \param objType The object type
 * \param slide information about the slide
 *
 * \return The result, TRUE on ok, else FALSE
 *****************************************************************************/
MSF_BOOL checkObjectType(SlsMediaObjectType objType, SmaSlideInfo *slide)
{
    SmaObjectInfo *object;
    if (slide == NULL)
    {
        return FALSE;
    } /* if */
    
    object = &slide->object;

    while (object)
    {
        if (object->type == objType)
        {
            switch (object->type)
            {
            case SLS_OBJECT_TYPE_IMAGE:
                /* Image type */
                if (object->info.image.size > 0)
                {
                    return TRUE;
                } /* if */
                break;

            case SLS_OBJECT_TYPE_VIDEO:
                /* video uses the same region as image */
                if (object->info.video.size > 0)
                {
                    return TRUE;
                } /* if */
                break;

            case SLS_OBJECT_TYPE_AUDIO:
                if (object->info.audio.size > 0)
                {
                    return TRUE;
                } /* if */
                break;

            case SLS_OBJECT_TYPE_TEXT:
                if (object->info.text.size > 0)
                {
                    return TRUE;
                }
            break;
            case SLS_OBJECT_TYPE_ATTACMENT:
            /* todo - how to do this */
            break;
            case SLS_OBJECT_TYPE_DRM:
            default:
            /* nothing to do here */
            break;
			}
        } /* if */
        object = object->next;
    } /* while */

    return FALSE;
} /* checkObjectType */

/*!
 * \brief Get the smaPlayer information
 * 
 * \return Information about the smil.
 *****************************************************************************/
SmaPlayerInfo *getPlayerInfo(void)
{
    return &smaInfo;
} /* getPlayerInfo */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
void meaMoveToArchive(MSF_UINT8 sender, MSF_UINT32 msgId)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, sender, SAMAIN_EC522D9B080224B9132013B3D0C9D047, "meaMoveToArchive(%d, %d)\n", sender, msgId));

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    length = (MSF_UINT16)cvt.pos;
    sig = MSF_SIGNAL_CREATE (MEA_SIG_MOVE_TO_ARCHIVE, sender, MSF_MODID_MEA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (!msf_dcvt_uint32(&cvt, (MSF_UINT32 *)&msgId))
    {
        return;
    }

    MSF_SIGNAL_SEND (sig);

}
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
/*!
 * \brief Signal handler
 * 
 * \param sig the signal
 *****************************************************************************/
static void mainSignalHandler( SmaSignal *sig)
{
    SmaPlayerInfo *playerInfo;
    SmaSlideInfo *slideInfo;
	SmaResult result = SMA_RESULT_OK;
    switch (sig->type) 
    {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__      
    case SMA_SIG_MH_MOVE_TO_ARCHIVE:
    {
        if ((SmaConfirmDialogResult)sig->u_param1 == SMA_CONFIRM_DIALOG_OK)
            if(sig->u_param2 != 0)
            {
                widgetDeleteScreen();
                smaSlideTerminate();  /* close opened files*/
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                meaDeleteMhNavMenu();  
#endif
                meaMoveToArchive(MSF_MODID_SMA, sig->u_param2);
            }
        break;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  */    
    case SMA_SIG_MH_NO_TIMER:
        stopPlayTimer();
        break;
    case SMA_SIG_MH_SET_TIMER:
        /* set timer */
        playerInfo = getPlayerInfo();
        slideInfo = getSlideInfo( playerInfo->currentSlide, playerInfo);
        setPlayTimer( slideInfo->displayTime);
        break;
    case SMA_SIG_MH_SBP_COMPLETE:
        /* set focus on menu again. */
#ifndef WAP_SUPPORT //slide menu has been removed
        result = showSlideMenu();
#endif /* WAP_SUPPORT */
        if ( SMA_RESULT_OK != result)
        {
			EXIT_SMIL_PLAYER(result);
        } /* if */
        break;
    case SMA_SIG_MH_TERMINATE_APP:
        if (SMA_TERM_EXIT == sig->u_param1) 
        {
            playerInfo = getPlayerInfo();
            sendResult(playerInfo->sourceModule, (SmaResult)sig->i_param);
        }
        else if (SMA_TERM_SLS == sig->u_param1)
        {
            /* We always close SLS since it cannot exist in several instances */
            MSF_MODULE_TERMINATE(MSF_MODID_SMA, MSF_MODID_SLS);            
        }
        else
        {
            smaSignalDelete(sig);
            smaPanic(SMA_PANIC_TERMINATE, (SmaResult)sig->i_param);
        }
        break;
#ifdef __UNIFIED_MSG_SUPPORT__
    case SMA_SIG_MH_DELETE_MM:
        if ((SmaConfirmDialogResult)sig->u_param1 == SMA_CONFIRM_DIALOG_OK)
        {
            widgetDeleteScreen();
            smaSlideTerminate();  /* close opened files */
            EXIT_SMIL_PLAYER(SMA_RESULT_OK);
            MEAif_deleteMessage(MSF_MODID_SMA, sig->u_param2);
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, SAMAIN_0BBA7C6428843FB2001464D022D95171, "(%s) (%d) Trying to delete msgId=%d\n", 
                __FILE__, __LINE__, sig->u_param2));
        }
        break;
    case SMA_SIG_MH_DELETE_ALL_MM:
        if ((SmaConfirmDialogResult)sig->u_param1 == SMA_CONFIRM_DIALOG_OK)
        {
        #ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
            extern MeaFolder mmsFolder2MeaFolder(MmsFolderType folder);
            if (getPlayerInfo()->folder == MMS_USRDEF_TEMPLATES)
            {
                smaSlideTerminate();  /* close opened files */
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
                MEAif_deleteFolder(MSF_MODID_SMA, 
                    mmsFolder2MeaFolder(getPlayerInfo()->folder));
            }
            else
        #endif
            {
            extern MeaFolder mmsFolder2MeaFolder(MmsFolderType folder);            
            widgetDeleteScreen();
            smaSlideTerminate();  /* close opened files */
            EXIT_SMIL_PLAYER(SMA_RESULT_OK);
            wap_send_mmi_mms_delete_all_ind(mmsFolder2MeaFolder(getPlayerInfo()->folder));
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, SAMAIN_BEED8287D5C36899A24102A8CD232F0B, "(%s) (%d) Tell UM to delete msg in folder=%d\n", 
                __FILE__, __LINE__, sig->u_param2));
            }
        }
        break;
#endif
    default:
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, 
            SAMAIN_A49CA232578830AA1196C009236D7E1D, "MMSSYST: received unknown signal: %d\n", sig->type));
    }
    smaSignalDelete( sig);
} /* mainSignalHandler */


/*!
 * \brief Returs the the status of SLS
 * 
 * \return TRUE if sls is running, else FALSE.
 *****************************************************************************/
MSF_BOOL slsIsRunning(void)
{
    return smaInfo.slsIsRunning;
} /* slsIsRunning */


/*!
 * \brief Set information about SLS.
 * 
 * \param TRUE if sls is running, else FALSE
 *****************************************************************************/
void setSlsIsRunnig( MSF_BOOL value)
{
    smaInfo.slsIsRunning = value;
} /* setSlsIsRunnig */


/*!
 * \brief Free memory in SmaSlideInfo
 * 
 * \return the SmaSlideInfo to free.
 *****************************************************************************/
static void freeSmaSlideInfo( SmaSlideInfo *slide)
{
    SmaSlideInfo *tmp;
    SmaSlideInfo *root;
    if ( slide == NULL)
    {
        return;
    } /* if */
    
    root = slide;
    
    while ( slide)
    {
        tmp = slide;
        freeSmaObjectInfo( &slide->object);
        slide = slide->next;
        /* do not free root slide */
        if ( tmp != root)
        {
            SMA_FREE( tmp);
        } /* if */
    } /* while */

    memset( root, 0x00, sizeof(SmaSlideInfo));
    
} /* freeSmaSlideInfo */


/*!
 * \brief Free memory in SmaObjectInfo
 * 
 * \return the SmaObjectInfo to free.
 *****************************************************************************/
static void freeSmaObjectInfo( SmaObjectInfo *object)
{
    SmaObjectInfo *tmp;
    SmaObjectInfo *root;
    if (object == NULL)
    {
        return;
    } /* if */
    
    root = object;
    /* do not free "root" */
    
    while ( object)
    {
        if (object->fileName != NULL)
		{
			SMA_FREE(object->fileName);
		} /* if */
        if (object->boundary != NULL)
		{
			SMA_FREE(object->boundary);
            object->boundary = NULL;
		} /* if */
        if ( (SLS_OBJECT_TYPE_TEXT == object->type) && (NULL != object->info.text.links))
        {
            smaDeleteUrlList(&object->info.text.links);
        }
		tmp = object;
        object = object->next;

        
        /* dont free root object */
        if ( tmp != root)
        {
            SMA_FREE(tmp);
        } /* if */
    } /* while */
    object = NULL;
    memset( root, 0x00, sizeof(SmaObjectInfo));
} /* freeSmaObjectInfo */

/*!
 * \brief Gets the links of the current slide.
 *****************************************************************************/
SmaLinkItem *getCurrentLinks(void)
{	
	SmaLinkItem *link;
    SmaSlideInfo *curr;		
	SmaObjectInfo *object;	
    curr = getSlideInfo(smaInfo.currentSlide, &smaInfo);
	object = &curr->object;	
    while(NULL != object) 
    {		
        if (SLS_OBJECT_TYPE_TEXT == object->type)
		{
			link = object->info.text.links;
			while (NULL != link)
			{
				return link;	
			}			
		}
		object = object->next;
	}
	return NULL;
}


/*!
 * \brief Returns information about the slide.
 * 
 * \param number Number of the slide to get information about.
 * \param playerInfo Information about the smil
 *
 * \return Slide information
 *****************************************************************************/
SmaSlideInfo *getSlideInfo( MSF_UINT32 number, SmaPlayerInfo *playerInfo)
{
    SmaSlideInfo *slide = NULL;
    MSF_UINT8 i;

    if ( number > playerInfo->noOfSlides)
    {
        /* error */
        return NULL;
    } /* if */

    slide = &playerInfo->slideInfo;
    for ( i = 0; i < number; i++)
    {
        slide = slide->next;
        if ( slide == NULL)
        {
            /* corrupt */
            return NULL;
        } /* if */
    } /* for */
    return slide;
} /* getSlideInfo */




/*! \brief Calculates and sets the region of a gadget object.
 *  \param gadgetSize Size of the gadget is set in this param
 *  \param gadgetPosition Position of the gadget is set in this param
 *  \param object information about the current object
 *****************************************************************************/
void setGadgetRegion(MsfSize *gadgetSize, MsfPosition *gadgetPosition,
    const SmaObjectInfo *object)
{
    MSF_INT16 offset = 0;
    MSF_INT32  rootWidth = 0;
    MSF_INT32  rootHeight = 0;
    MSF_UINT32 positionX = 0;
    MSF_UINT32 positionY = 0;
    MSF_UINT16 height = 0;
    MSF_UINT16 width = 0;
    MSF_UINT16 positionXType = 0;
    MSF_UINT16 positionYType = 0;
    MSF_UINT16 heightType = 0;
    MSF_UINT16 widthType = 0;
    SlsMediaObjectType objectType; 
    MsfSize displaySize;
    
#ifdef WAP_SUPPORT
    smaGetSlideDisplaySize(&displaySize);
#else
    getSlideDisplaySize(&displaySize);
#endif /* WAP_SUPPORT */
    
    objectType = object->type;
    

    rootWidth = (MSF_INT16)smaInfo.rootSize.width;
    rootHeight = (MSF_INT16)smaInfo.rootSize.height;
    
#ifdef WIDGET_SLIDING_SMIL_VBAR
    displaySize.width -= MSF_CFG_SCROLLBAR_WIDTH;
#endif /* WIDGET_SLIDING_SMIL_VBAR */

    if (objectType == SLS_OBJECT_TYPE_IMAGE || objectType == SLS_OBJECT_TYPE_VIDEO)
    {
        /* check if image position is larger than the display */
        if ( object->info.image.region.position.cx.value > 
            displaySize.width)
        {
            positionX = 0;
        }
        else
        {
            positionX = object->info.image.region.position.cx.value;
        } /* if */
        if ( object->info.image.region.position.cy.value > 
            displaySize.height)
        {
            positionY = 0;
        }
        else
        {
            positionY = object->info.image.region.position.cy.value;
        } /* if */

        height = object->info.image.region.size.cy.value;
        width = object->info.image.region.size.cx.value;
        positionXType = object->info.image.region.position.cx.type;
        positionYType = object->info.image.region.position.cy.type;
        heightType = object->info.image.region.size.cy.type;
        widthType = object->info.image.region.size.cx.type;
    }
    else
    {
        /* check if text position is larger than the display */
        if ( object->info.text.region.position.cx.value > 
            displaySize.width)
        {
            positionX = 0;
        }
        else
        {
            positionX = object->info.text.region.position.cx.value;
        } /* if */
        if ( object->info.text.region.position.cy.value > 
            displaySize.height)
        {
            if ( object->info.text.region.position.cy.type == SLS_ABS)
            {
                positionY = (MSF_UINT16)(displaySize.height / 2);
            }
            else 
            {
                /* position i relative and outside display, so 50% in hight will be fine. */
                positionY = 50;
            } /* if */
        }
        else
        {
            positionY = object->info.text.region.position.cy.value;
        } /* if */
        
        height = object->info.text.region.size.cy.value;
        width = object->info.text.region.size.cx.value;
        positionXType = object->info.text.region.position.cx.type;
        positionYType = object->info.text.region.position.cy.type;
        heightType = object->info.text.region.size.cy.type;
        widthType = object->info.text.region.size.cx.type;
    } /* if */

    if (rootWidth <= 0)
    {
        /* if there are no root layout width, the width of the source 
         * display will be the same width as ours
         */
        rootWidth = displaySize.width;
    } /* if */

    if (rootHeight <= 0)
    {
        /* if there are no root layout height, the height of the source 
         * display will be the same height as ours
         */
        rootHeight = displaySize.height;
    } /* if */

    /* position */
    if (positionXType == SLS_ABS)
    {
        /* absolute X position */
        offset = (MSF_INT16)((positionX * 100) / rootWidth);
        gadgetPosition->x = (MSF_INT16)(offset * displaySize.width);
        gadgetPosition->x = (MSF_INT16)(gadgetPosition->x / 100);
    }
    else
    {
        /* relative X (%) position*/
        offset = (MSF_INT16)(positionX);
        gadgetPosition->x = (MSF_INT16)(offset * displaySize.width);
        gadgetPosition->x = (MSF_INT16)(gadgetPosition->x / 100);
    } /* if */
    
    if (positionYType == SLS_ABS)
    {
        /* absolute Y position */
        offset = (MSF_INT16)((positionY * 100) / rootHeight);
        gadgetPosition->y = (MSF_INT16)(offset * displaySize.height);
        gadgetPosition->y = (MSF_INT16)(gadgetPosition->y / 100);
    }
    else
    {
        /* relative Y (%) position*/
        offset = (MSF_INT16)(positionY);
        gadgetPosition->y = (MSF_INT16)(offset * displaySize.height);
        gadgetPosition->y = (MSF_INT16)(gadgetPosition->y / 100);
    } /* if */
    

    /* size */
    if (widthType == SLS_ABS)
    {
        /* absolute X size */
        offset = (MSF_INT16)((width * 100) / rootWidth);
        if (offset < 0)
        {
            offset = 100;
        } /* if */
        else if (offset > 100) /* Ensure that content could be shown within screen*/
        {
            offset = 100;
        }

        gadgetSize->width = (MSF_INT16)(offset * displaySize.width);
        gadgetSize->width = (MSF_INT16)(gadgetSize->width / 100);
        gadgetSize->width = (gadgetSize->width)?gadgetSize->width:1;
    }
    else 
    {
        /* relative X (%) size*/
        offset = (MSF_INT16)(width);
        if (offset < 0 || offset > 100)
        {
            offset = 100;
        } /* if */

        gadgetSize->width = (MSF_INT16)(offset * displaySize.width);
        gadgetSize->width = (MSF_INT16)(gadgetSize->width / 100);
        gadgetSize->width = (gadgetSize->width)?gadgetSize->width:1;
    } /* if */
    
    if (heightType == SLS_ABS)
    {
        /* absolute Y size */
        offset = (MSF_INT16)((height * 100) / rootHeight);
        if (offset < 0)
        {
            offset = 50;
        } /* if */
        gadgetSize->height = (MSF_INT16)(offset * displaySize.height);
        gadgetSize->height = (MSF_INT16)(gadgetSize->height / 100);
        gadgetSize->height = (gadgetSize->height)?gadgetSize->height:1;
    }
    else
    {
        /* relative Y (%) size*/
        offset = (MSF_INT16)(height);
        if (offset < 0 || offset > 100)
        {
            offset = 50;
        } /* if */
        gadgetSize->height = (MSF_INT16)(offset * displaySize.height);
        gadgetSize->height = (MSF_INT16)(gadgetSize->height / 100);
        gadgetSize->height = (gadgetSize->height)?gadgetSize->height:1;
    } /* if */
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    if (objectType == SLS_OBJECT_TYPE_TEXT)
    {
        gadgetSize->height = displaySize.height;  //maximum text size
    }
#endif /* WIDGET_SLIDING_SMIL_SUPPORT */

} /* setGadgetRegion */


/*!
 * \brief Initialize the SMA
 * 
 *****************************************************************************/
void initializeSma(void)
{
    /* initialize internal signal handling */
    smaSignalInit();

    /* initialize the Message handling FSM */
    if ( smaMainInit() == FALSE || 
         smaAsyncInit() == FALSE)
    {
        EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
    } /* if */
    smaSlideInit();
    smaSbpInit();
	smaPipeInit();
    smaAttachmentInit();
    smaUiInit();
	smaInitDia();	
    setSmaIsInitialized(TRUE);
	/* Packages */
    if (!smaPhInit())
    {
        EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
    }
} /* initializeSma */

/*!
 * \brief Returns the busy state of the SMA
 * 
 * \return TRUE if the SMA is busy, else FALSE
 *****************************************************************************/
MSF_BOOL smaIsRunning(void)
{
    return isRunning;
} /* smaIsRunning */

/*!
 * \brief Set the busy state of the SMA
 * 
 * \param state TRUE if the SMA is busy, else FALSE
 *****************************************************************************/
void setSmaIsRunning( MSF_BOOL state)
{
    isRunning = state;
} /* setSmaIsRunning */

/*!
 * \brief Returns the busy state of the SMA
 * 
 * \return TRUE if the SMA is busy, else FALSE
 *****************************************************************************/
MSF_BOOL smaIsInitialized(void)
{
    return isInitialized;
} /* smaIsRunning */

/*!
 * \brief Set the busy state of the SMA
 * 
 * \param state TRUE if the SMA is busy, else FALSE
 *****************************************************************************/
void setSmaIsInitialized( MSF_BOOL state)
{
    isInitialized = state;
} /* setSmaIsRunning */

/*!
 * \brief Check if media type is of audio type
 * 
 * \param state TRUE if Audio else FALSE
 *****************************************************************************/
MSF_BOOL isKnownType(SlsMediaType mediaType, SlsMediaObjectType objType)
{
    int i;
    const SmaMediaTypeItem *item = supportedMediaTypes;

    i = 0;
    while(SLS_NOT_USED != item[i].slsMediaType)
    {
        if (mediaType == item[i].slsMediaType)
        {
            if (objType == item[i].slsObjectType)
            {
                return TRUE;
                //break;
            }
        }
        ++i;
    }
    return FALSE;
} /* isKnownType */

SlsMediaObjectType smaGetObjectType(SlsMediaType mediaType)
{
    int i;
    const SmaMediaTypeItem *item = supportedMediaTypes;
    
    i = 0;
    while(SLS_NOT_USED != item[i].slsMediaType)
    {
        if (mediaType == item[i].slsMediaType)
        {
            return item[i].slsObjectType;
        }
        ++i;
    }
    return SLS_OBJECT_TYPE_NONE;
} /* smaGetObjectType */


/*!
 * \brief convert from Msf to SLS media types. Text is not counted as a
 *        as a valid media type in this function. 
 * 
 * \param slsMediaType SLS media type
 * \return MSF media type or -1 if unknown type
 ****************************************************************************/
MSF_INT32 convertSmaToMsfMediaTypes(SlsMediaType slsMediaType)
{	
    unsigned int i;
    const SmaMediaTypeItem *item;
    i = 0;
    item = smaGetSupportedMediaTypes();
    while(SLS_NOT_USED != item[i].slsMediaType)
    {
        if (item[i].slsMediaType == slsMediaType)
        {
            if (SLS_OBJECT_TYPE_IMAGE == item[i].slsObjectType)
            {
                return item[i].msfFormat.image;
            }
            else if (SLS_OBJECT_TYPE_AUDIO == item[i].slsObjectType)
            {
                return item[i].msfFormat.audio;
            }
            else if (SLS_OBJECT_TYPE_VIDEO == item[i].slsObjectType)
            {
                return item[i].msfFormat.video;
            }
        }
        ++i;
    }
    return -1;
} /* convertSmaToMsfMediaTypes */

/*!
 * \brief convert from SLS media type to mime type. On success the mime type
 *  is returned, else NULL
 * 
 * \param slsMediaType SLS media type
 * \return mime type
 ****************************************************************************/
const char *convertSlsToMimeType(SlsMediaType slsMediaType)
{	
    unsigned int i;
    const SmaMediaTypeItem *item;
    i = 0;
    item = smaGetSupportedMediaTypes();

    while(SLS_NOT_USED != item[i].slsMediaType)
    {
        if (item[i].slsMediaType == slsMediaType)
        {
            return item[i].mimeType;
        } /* if */
        ++i;
    } /* while */
    return NULL;
} /* convertSlsToMimeType */

/*!
 * \brief Find matching error dialog and display it
 * 
 * \param result result of SMA operation
 * \return TRUE if match is found, FALSE otherwise
 ****************************************************************************/
MSF_BOOL handleSmaErr( SmaResult result)
{
	MSF_BOOL ret = FALSE;
	switch (result)
	{
	case SMA_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:		
		ret = smaShowDialog(SMA_STR_ID_ERR_NO_MEMORY, SMA_DIALOG_ERROR);
		break;
	case SMA_RESULT_ERROR:		
		ret = smaShowDialog(SMA_STR_ID_ERR_WRITING_FILE, SMA_DIALOG_ERROR);
		break;
	case SMA_RESULT_OK:
		break;
	case SMA_RESULT_BUSY:
		break;
	case SMA_RESULT_TO_MANY_SLIDES:
		ret = smaShowDialog(SMA_STR_ID_NOT_ABLE_PLAY_ALL_SLIDES, SMA_DIALOG_ERROR);
	default :
		break;
	}
	return ret;
} /* handleSmaErr */

/*! \brief returns the list of supported media types
 *
 * \return The list of supported media types.
 *****************************************************************************/
const SmaMediaTypeItem *smaGetSupportedMediaTypes(void)
{
    return supportedMediaTypes;
} /* smaGetSupportedMediaTypes */

/*!
 * \brief Calls the MSF Telephone API function MSF_TEL_MAKE_CALL. 
 *        Result is passed as TRUE/FALSE in u_param1 using the requested 
 *        return signal. Multiple calls using the same callback FSM/signal 
 *        combination is not possible!
 * 
 * \param fsm       The callback FSM.
 * \param signal    The callback signal.
 * \param number    The number to call
 * \param id        The id of this call operation
 *****************************************************************************/
void smaMakeCall(const char *number)
{
//    MSF_TEL_MAKE_CALL((MSF_UINT8)MSF_MODID_SMA, 0, number);
    extern void wtai_telMakeCall(MSF_UINT8 modId, MSF_UINT16 telId, const char *number);
    wtai_telMakeCall((MSF_UINT8)MSF_MODID_MEA, 0, number);
} /* smaMakeCall */

/*!
 * \brief Handles the response signal for the MSF_TEL_MAKE_CALL operation
 * 
 * \param callRsp   The response data
 *****************************************************************************/
void smaMakeCallRsp(const msf_tel_make_call_resp_t *callRsp)
{
    MSF_BOOL ret;

    /* Analyze the callback data */
    ret = (MSF_TEL_OK == callRsp->result);

    /* Show dialogs on error */
    if ((FALSE == ret) && (NULL != callRsp))
    {
#ifndef WAP_SUPPORT //wtai and MMI would show error msg
        switch (callRsp->result)
        {
        case MSF_TEL_ERROR_CALLED_PARTY_IS_BUSY:
        case MSF_TEL_ERROR_CALLED_PARTY_NO_ANSWER:
            /* The called party is busy*/
            (void)smaShowDialog(SMA_STR_ID_CALL_BUSY, SMA_DIALOG_ERROR);    
            break;
        case MSF_TEL_ERROR_NETWORK_NOT_AVAILABLE:
        case MSF_TEL_ERROR_INVALID:
        case MSF_TEL_ERROR_UNSPECIFIED:
        default:
            (void)smaShowDialog(SMA_STR_ID_CALL_FAILED, SMA_DIALOG_ERROR);    
            break;
        } /* switch */
#endif /* WAP_SUPPORT */
    }
    else if (NULL == callRsp)
    {
        (void)smaShowDialog(SMA_STR_ID_CALL_FAILED, SMA_DIALOG_ERROR);    
    } /* if */

} /* smaMakeCallRsp */


#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
/*!
 * \brief Display the Current slide.
 * 
 * \param playerInfo A pointer to the information about the smil.
 *
 * \return The result of the operation.
 *****************************************************************************/
SmaResult displayCurrentSlide( SmaPlayerInfo *playerInfo)
{

    SmaResult result = SMA_RESULT_OK;
    MSF_BOOL renderView = TRUE;

    if ( (playerInfo->currentSlide < 0) || (playerInfo->currentSlide >= playerInfo->noOfSlides) )
        return FALSE;

    if ( playerInfo->isPlaying) 
    {
        generateSlide( playerInfo->currentSlide, playerInfo, 
            SMA_FSM_MAIN, SMA_SIG_MH_SET_TIMER);
    }
    else 
    {
        generateSlide( playerInfo->currentSlide, playerInfo, 
            SMA_FSM_MAIN, SMA_SIG_MH_NO_TIMER);
    } /* if */    
   
    return result;
} /* displayCurrentSlide */


#endif

void smaInterruptHandler(U16 param)
{
    if (param == WAP_LEAVE_WIDGET_SCREEN)
    {
        stopSmil(getPlayerInfo());
    }
    else if (param == WAP_GOBACK_WIDGET_SCREEN)
    {
    }
    else
    {
        ASSERT(0);
    }
}
