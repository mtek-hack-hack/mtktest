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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
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

/* MSF */
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* SMA */
#include "saintsig.h"
#include "saasync.h"
#include "samem.h"
#include "sma_if.h"
#include "satypes.h"
#include "sma_def.h"
#include "sasbp.h"
#include "saph.h"

/******************************************************************************
 * Constants
 *****************************************************************************/


/******************************************************************************
 * Data-types
 *****************************************************************************/

/* \struct SbpRequest holds instance data when saving a body-part */
typedef struct
{
    MSF_UINT32              callingFsm;		/*!< calling fsm*/
    int                     returnSig;		/*!< return signal */
    unsigned char           *buffer;	    /*!< buffer used for data */
    MSF_UINT32              bufferSize;		/*!< size of buffer */
    MSF_UINT32              readPos;		/*!< current position in source file */
    MSF_UINT32              leftToRead;		/*!< Number of bytes left to read */

    char                    *drmRights;     /*!< The DRM rights (from DRE) or 
                                                 NULL if not protected */
    const char              *boundary;      /*!< The boundary for this object 
                                             */

    SmaAsyncOperationHandle asioReadHandle; /*!< Async read handle */

    const char *sourceFile;                 /*!< The source file to read from */
    char *fileName;
    char *saveMimeType;
}SbpReqInstance;

/******************************************************************************
 * Static variables
 *****************************************************************************/
static SbpReqInstance   *sbpInstance;

/******************************************************************************
 * Function prototypes
 *****************************************************************************/

static void sbpMain(SmaSignal *sig);
static MSF_BOOL sbpCreateInstance(MSF_UINT32 dataSize);
static MSF_BOOL handleReadOperation(SbpReqInstance *instance, 
    int bytesRead, SmaAsioResult result);
static void sbpClean( void);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 *\brief Initiates the Save body-part handler
 *
 *****************************************************************************/
void smaSbpInit(void)
{
    smaSignalRegisterDst( SMA_FSM_SBP, sbpMain);
    sbpInstance = NULL;
} /* smaSbpInit */


/*!
 *\brief Terminates the Save body-part handler
 *
 *****************************************************************************/
void smaSbpTerminate(void)
{
    sbpClean();
    smaSignalDeregister( SMA_FSM_SBP);
} /* smaSbpTerminate */


/*!
 *\brief Cleans memory used and close async operations used by Sbp.
 *
 *****************************************************************************/
static void sbpClean( void)
{
    if ( sbpInstance == NULL)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASBP_DC0B40A4F56428F26F75F4CE908206E7, "sbpClean: no instance"));
        return;
    } /* if */

    /* Remove any instance data */
    if ( sbpInstance->asioReadHandle)
    {
        smaAsyncOperationStop( &sbpInstance->asioReadHandle);
    } /* if */

	if (NULL != sbpInstance->buffer)
	{
		SMA_FREE(sbpInstance->buffer);
		sbpInstance->buffer = NULL;
	}
	/* Release filename */
	if (NULL != sbpInstance->fileName)
	{
		SMA_FREE(sbpInstance->fileName);
		sbpInstance->fileName = NULL;
	}
    /* Mime type*/
	if (NULL != sbpInstance->saveMimeType)
	{
		SMA_FREE(sbpInstance->saveMimeType);
		sbpInstance->saveMimeType = NULL;
	}
    /* DRM rights */
	if (NULL != sbpInstance->drmRights)
	{
		SMA_FREE(sbpInstance->drmRights);
		sbpInstance->drmRights = NULL;
	}

    SMA_FREE(sbpInstance);
    sbpInstance = NULL;
} /* sbpClean */

/*!
 *\brief Initializes the save body-part operation
 *
 * \param sourceFilePath    Full path to source file.
 * \param startPos          Start position for data to store.
 * \param dataSize          Size of data.
 * \param callingFsm        FSM requesting the operation
 * \param boundary          If the boundary is set then the content is 
 *                          protected 
 * \param returnSig         Expected return signal
 *****************************************************************************/
void saveBodyPart(const char *fileName, const char *mimeType, 
    const char *sourceFilePath, MSF_UINT32 startPos, 
    MSF_UINT32 dataSize, MSF_UINT32 callingFsm, int returnSig, 
    const char *boundary)
{
    MSF_UINT32 bytesToRead = 0;

    /* initialize memory */
    if (!sbpCreateInstance(dataSize))
    {
        /* currently busy */
        (void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)callingFsm, returnSig, 
            SMA_RESULT_BUSY);
        return;
    } /* if */	

    sbpInstance->callingFsm  = callingFsm;
    sbpInstance->returnSig   = returnSig;
    sbpInstance->readPos     = startPos;
    sbpInstance->leftToRead  = dataSize;
    sbpInstance->sourceFile  = sourceFilePath;
    sbpInstance->boundary    = boundary;
    sbpInstance->fileName = msf_cmmn_strdup(MSF_MODID_SMA, fileName);
    sbpInstance->saveMimeType = msf_cmmn_strdup(MSF_MODID_SMA, mimeType);

    if (sbpInstance->saveMimeType == NULL)
    {
        /* no mimeType ERROR */
        /* Failed, return */
        (void)SMA_SIGNAL_SENDTO_I( SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
            SMA_RESULT_ERROR);
    } 
    /* Check if the object needs to extracted */
    else if (NULL != boundary)
    {
        if (!smaDreGetMsgHeader(SMA_FSM_SBP, SMA_SIG_SBP_DRM_HEAD_RSP, 
            (char *)sourceFilePath, startPos, boundary))
        {
            /* currently busy */
            (void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)callingFsm, returnSig, 
                SMA_RESULT_ERROR);
        }
    }
    else
    {
        /* read first part of the file */
        if (sbpInstance->leftToRead < sbpInstance->bufferSize)
        {
	          bytesToRead = sbpInstance->leftToRead;
        }
        else
        {
	        bytesToRead = sbpInstance->bufferSize;
        } /* if */
        sbpInstance->buffer = SMA_ALLOC(sbpInstance->bufferSize);
	    /* create read async operation */
	    sbpInstance->asioReadHandle = 
	        smaAsyncOperationStart(sourceFilePath, SMA_FSM_SBP, 0L, 
	        SMA_SIG_SBP_READ_RSP, SMA_ASYNC_MODE_READ);
        /* Perform the read operation */
	    smaAsyncRead( sbpInstance->asioReadHandle, (MSF_INT32)sbpInstance->readPos,
		    sbpInstance->buffer, bytesToRead);
    }
} /* saveBodyPart */


/*!
 *\brief Signal-handler for the content routing FSM.
 *
 * \param sig The signal received.
 *****************************************************************************/
static void sbpMain( SmaSignal *sig)
{
    MSF_UINT32 bytesRead = 0;
    SmaDreResultItem *resItem = NULL;

    if (NULL == sig)
    {
        /* no signal - just return */
        return;
    } /* if */

    switch (sig->type)
    {
    case SMA_SIG_SBP_READ_RSP:
        bytesRead = sig->u_param2;
        if ( !handleReadOperation( sbpInstance, (int)bytesRead, 
            (SmaAsioResult)sig->u_param1))
        {
            /* Failed to read from file */
            /* End saving, just clean up and return */
            (void)SMA_SIGNAL_SENDTO_I(SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
                    SMA_RESULT_ERROR);
        }
		else
        {
			/* now save it */			
			if (0 == smaCreateSaveAs(SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
			    sbpInstance->saveMimeType, sbpInstance->fileName, 
                (char*)sbpInstance->buffer, bytesRead, NULL))
            {
                /* Failed, return */
                (void)SMA_SIGNAL_SENDTO_I(SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
                        SMA_RESULT_ERROR);
            }

        }/* else */        			          
        break;

    case SMA_SIG_SBP_DRM_HEAD_RSP:
        if (SMA_RESULT_OK != (SmaResult)sig->u_param1)
        {
            /* Operation failed, exit */
            (void)SMA_SIGNAL_SENDTO_I(SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
                    SMA_RESULT_ERROR);
            break;
        }
        /* Extract the DRM object */
        sbpInstance->readPos += sig->u_param2;
        resItem = sig->p_param;
        if (!smaDreGetObject(SMA_FSM_SBP, SMA_SIG_SBP_DRM_BODY_RSP,
            (char *)sbpInstance->sourceFile, NULL, resItem->httpHeader, 
            sbpInstance->boundary, sbpInstance->readPos, TRUE))
        {
            /* Operation failed, exit */
            (void)SMA_SIGNAL_SENDTO_I( SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
                    SMA_RESULT_ERROR);
        }
        /* Get the DRM rights provided by the DRE module, this information is
           used later when the data is saved */
        sbpInstance->drmRights = resItem->drmRights;
        /* De-allocate the structure used to transport the DRM data */
        SMA_FREE(sig->p_param);
        break;

    case SMA_SIG_SBP_DRM_BODY_RSP:
        if (SMA_RESULT_OK == (SmaResult)sig->u_param1)
        {
		    /* now save it */			
		    if (0 == smaCreateSaveAs(SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
		        sbpInstance->saveMimeType, sbpInstance->fileName, sig->p_param,
                sig->u_param2, sbpInstance->drmRights))
            {
                /* Operation failed, exit */
                (void)SMA_SIGNAL_SENDTO_I( SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
                        SMA_RESULT_ERROR);
            }
        }
        else
        {
            /* Operation failed, exit */
            (void)SMA_SIGNAL_SENDTO_I( SMA_FSM_SBP, SMA_SIG_SBP_COMPLETE, 
                    SMA_RESULT_ERROR);
        }
        break;

    case SMA_SIG_SBP_COMPLETE:
        /* signal back to the calling fsm */
        (void)SMA_SIGNAL_SENDTO_I( (SmaStateMachine)sbpInstance->callingFsm, 
            sbpInstance->returnSig, sig->i_param);
	    sbpClean();
        break;

    default:
        /* unknown signal */
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
            SASBP_D1A0EFC5990B833A4D7B9F3C054504AD, "(%s) (%d) Unknown signal!\n", __FILE__, __LINE__));
        break;
    } /* switch */

        
    /* Deallocate the signal */
    smaSignalDelete(sig);
} /* sbpMain */


/*!
 *\brief Checks the result of the read operation.
 *
 * \param instance Instance information, e.g. information about the 
 *         current transaction.
 * \param bytesRead Number of bytes read in last read operation.
 * \param result Result of the read operation operation
 *
 * \return TRUE if successful, else FALSE
 *****************************************************************************/
static MSF_BOOL handleReadOperation( SbpReqInstance *instance, 
    int bytesRead, SmaAsioResult result)
{
    MSF_BOOL status = TRUE;
    
    switch( result)
    {
        case SMA_ASIO_RESULT_OK:
        case SMA_ASIO_RESULT_EOF:
            /* write data to file */
            instance->readPos += (MSF_UINT32)bytesRead;
            instance->leftToRead -= (MSF_UINT32)bytesRead;
            status = TRUE;
            break;
        case SMA_ASIO_RESULT_FILE_NOT_FOUND:
        case SMA_ASIO_RESULT_ERROR:
        case SMA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            status = FALSE;
            break;
        case SMA_ASIO_RESULT_DELAYED:
            /*lint -fallthrough */
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA,
                SASBP_2C0F4DBC670F72C7BFBD96C395E7017E, "SMA_SIG_SBP_READ invalid result code (%d)\n", 
                result));
            status = FALSE;
    } /* switch */
    return status;
} /* handleReadOperation */

/*!
 * \brief Initiates the save body part instance
 *
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL sbpCreateInstance(MSF_UINT32 dataSize)
{
    /* Check that no operation is in progress */
    if (NULL != sbpInstance)
    {
        return FALSE;
    }
    /* Allocate memory */
    sbpInstance = SMA_ALLOC(sizeof(SbpReqInstance));
    memset(sbpInstance, 0, sizeof(SbpReqInstance));
    /* Setup initial data */
    sbpInstance->readPos = 0;
    sbpInstance->bufferSize = dataSize;
    return TRUE;
} /* sbpCreateInstance */

/*!
 * \brief Convert from SmaAsioResult to SmaResult
 * 
 * \param asioRes (IN): the SmaAsioResult code
 *
 * \return The corresponding SmaResult code
 *****************************************************************************/
SmaResult convertAsio2SmaRes(SmaAsioResult asioRes)
{
	switch (asioRes)
	{
	case SMA_ASIO_RESULT_OK:
		return SMA_RESULT_OK;
	case SMA_ASIO_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
		return SMA_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
	case SMA_ASIO_RESULT_EOF:
		return SMA_RESULT_ERROR;
	case SMA_ASIO_RESULT_ERROR:
		return SMA_RESULT_ERROR;
	case SMA_ASIO_RESULT_DELAYED:
		return SMA_RESULT_ERROR;
	case SMA_ASIO_RESULT_FILE_NOT_FOUND:
		return SMA_RESULT_ERROR;
	default :
		return SMA_RESULT_ERROR;
	}
} /* convertAsio2SmaRes */

