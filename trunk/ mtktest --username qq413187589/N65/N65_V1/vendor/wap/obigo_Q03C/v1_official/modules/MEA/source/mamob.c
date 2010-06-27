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

/*! \file mamob.c
 *  \brief Media object browser
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_mem.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "maintsig.h"
#include "mamem.h"
#include "mamob.h"
#include "mtr.h"
#include "mauimob.h"

#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
#include "mtr_rend.h"
#endif

#if defined(MEA_MAX_SUBJECT_LENGTH) && defined(WIDGET_SLIDING_SMIL_VBAR)
#include "msf_core.h"
#define MEA_MOB_GET_TEXT_HEIGHT_TIMER_DUR   10
#endif
   
#if defined(MMS_SLIM_MEM) || defined(__DRM_SUPPORT__)
#include "widget_extension.h" //for kal_uint8 type
#endif /* defined(MMS_SLIM_MEM) || defined(__DRM_SUPPORT__) */
#ifdef MMS_SLIM_MEM
#include "mauicmn.h"	//for macro MEA_GET_IMG_ID(resId)   
#include "maasync.h"	//for meaAsyncOperation
#include "mamr.h"		//for isForMeaReadMessagePart
#include "mauidia.h"	//for meaShowDialog //remove it later
#include "maph.h" 		//for isForMeaAfiLoadFromFile
#include "mamv.h" 		//for meaMMCGetCurrentActiveMsg
#include "mms_def.h" 	//for mautils.h- MmsKnownMediaType
#include "sls_cfg.h"	//for mautils.h
#include "sls_if.h"		//for mautils.h
#include "mautils.h"	//for meaMediaType2ObjType

#include "msf_wid.h" //for release unused Mixed Mo resource handle
#endif /* MMS_SLIM_MEM */
#ifdef __DRM_SUPPORT__
#include "fs_type.h"       //for drm_def.h and FS_READ_ONLY
#include "../../drm/include/drm_gprot.h" //for DRM_process_file
#include "../../drm/include/drm_def.h" //for DRM_METHOD_FORWARD_LOCK
extern MSF_BOOL generateDRMObject(MeaMoDataItem *object);
#endif /* __DRM_SUPPORT__ */
/******************************************************************************
 * Data-structures
 *****************************************************************************/

/*! \struct MeaMobPageInfo
 * Data-structure for information about each rendered page of attachments
 */
typedef struct MeaMobPageInfoSt
{
    unsigned moOffset;             /*!< offset in # of objects for this page */
    struct MeaMobPageInfoSt *prev; /*!< previous page in list */
}MeaMobPageInfo;

/*! \struct MeaMobInstance
 * Data-structure for storing multipart/mixed viewer instances
 */
typedef struct 
{
    MeaStateMachine   fsm;             /*!< the fsm that wants info about MOB
                                            activitty */
    int               returnSignal;    /*!< signal to use for sending info
                                            about MOB activity */
    MeaMoDataItem     *currentMo;      /*!< current media object in list */
    unsigned          moOffset;        /*!< offset in objects for current page
                                            in list, 0 = first page */
    unsigned          noOfMoOnPage;    /*!< number of media objects on page */
    unsigned          totalPageHeight; /*!< current page height in pixels */
    MeaMoDataItem     *moList;         /*!< media object list */
    MeaMobSpecialOp   sop;             /*!< extra special operations */
    MeaMobSpecialOp   sopToAdd;        /*!< special operations to add */
    MeaMobPageInfo    *pages;          /*!< list of page information */
    MsfStringHandle   winTitle;        /*!< window title */
}MeaMobInstance;

/******************************************************************************
 * Variables
 *****************************************************************************/

static MeaMobInstance *mobInstance;   /*!< The current MOB instance */
static MSF_BOOL textTrunc = FALSE;

/******************************************************************************
 * Prototypes
 *****************************************************************************/

static void pushPage(MeaMobInstance *inst);
static void popPage(MeaMobInstance *inst);
static MeaMobSpecialOp findSpecialOp(MeaMobSpecialOp opbits);
static void clearSpecialOp(MeaMobSpecialOp *opbits, MeaMobSpecialOp op);
static void resetSpecialOps(MeaMobInstance *inst);
static MeaMoDataItem *findMoAtOffset(const MeaMobInstance *inst);
static void gotoFirstPage(MeaMobInstance *inst);
static void gotoNextPage(MeaMobInstance *inst);
static void gotoPrevPage(MeaMobInstance *inst);
static void meaMobCreateInstance(MeaMobInstance **instance,
    MeaMobActivation *mob);
static void meaMobDeleteInstance(MeaMobInstance **instance);
static MSF_BOOL moLimitExceeded(const MeaMobInstance *inst);
static MeaMobSignalId addNextSpecialOp(MeaMobInstance *inst);
static MeaMobSignalId getNextMediaObject(MeaMobInstance *inst);
static int checkFocus(const MeaMobInstance *inst);
static void handleMobMenu(const MeaMobInstance *inst);
static void handleMobOk(MeaMobInstance *inst);
static void meaMobMain(MeaSignal *sig);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Push information about current page on page stack
 * \param inst  the current instance
 *****************************************************************************/
static void pushPage(MeaMobInstance *inst)
{
    MeaMobPageInfo *page;

    if (NULL == inst->pages)
    {
        MEA_CALLOC(inst->pages, sizeof(MeaMobPageInfo));
    }
    else
    {
        page = inst->pages;
        MEA_CALLOC(inst->pages, sizeof(MeaMobPageInfo));
        inst->pages->prev = page;
    }
    inst->pages->moOffset = inst->moOffset;
}

/*!
 * \brief Pop information about previous page from stack
 * \param inst  the current instance
 *****************************************************************************/
static void popPage(MeaMobInstance *inst)
{
    MeaMobPageInfo *page;
    
    if (NULL == inst->pages)
    {
        return;
    }

    page = inst->pages->prev;   
    inst->moOffset = inst->pages->moOffset;
    MEA_FREE(inst->pages);
    inst->pages = page;
}

/*!
 * \brief Extract next special operation from bitmask
 * \param opbits The bitmask of special operations. 
 * \return the next special operation, or MEA_MOB_SOP_NO_OP if none found.
 *****************************************************************************/
static MeaMobSpecialOp findSpecialOp(MeaMobSpecialOp opbits)
{
    if ((opbits & MEA_MOB_SOP_ADD_MO) > 0)
    {
        return MEA_MOB_SOP_ADD_MO;
    }
    else if ((opbits & MEA_MOB_SOP_NEXT_PAGE) > 0)
    {
        return MEA_MOB_SOP_NEXT_PAGE;
    }
    else if ((opbits & MEA_MOB_SOP_PREV_PAGE) > 0) 
    {
        return MEA_MOB_SOP_PREV_PAGE;
    }

    return MEA_MOB_SOP_NO_OP;
}

/*!
 * \brief Clear a specific special operation from a special op bitmask
 * \param opbits The bitmask of special operations. 
 * \param op The operation to clear
 *****************************************************************************/
static void clearSpecialOp(MeaMobSpecialOp *opbits, MeaMobSpecialOp op)
{
     MSF_UINT32 bitmask;

     bitmask = (MSF_UINT32)*opbits;
     *opbits = (MeaMobSpecialOp)(~((MSF_UINT32)op) & bitmask);
}

/* \brief Reset special operations to the initial special ops 
 * \param inst The current instance
 *****************************************************************************/
static void resetSpecialOps(MeaMobInstance *inst)
{    
    inst->sopToAdd = inst->sop;
    clearSpecialOp(&inst->sopToAdd, MEA_MOB_SOP_NEXT_PAGE);
    clearSpecialOp(&inst->sopToAdd, MEA_MOB_SOP_PREV_PAGE);
}

/*!
 * \brief Return the media object at the current offset
 * \param inst   the current instance
 * \return The data item at the current offset
 *****************************************************************************/
static MeaMoDataItem *findMoAtOffset(const MeaMobInstance *inst)
{
    MeaMoDataItem *item;
    unsigned i;

    item = inst->moList;
    i = inst->moOffset;
    while (item != NULL && i > 0)
    {
        i--;
        item = item->next;
    }
    return item;
}

/*!
 * \brief Switch to the first page of attachments
 * \param inst  the current instance
 *****************************************************************************/
static void gotoFirstPage(MeaMobInstance *inst)
{
    inst->noOfMoOnPage = 0;
    inst->currentMo = inst->moList;
    resetSpecialOps(inst);
}

/*!
 * \brief Switch to the next page of attachments
 * \param inst  the current instance
 *****************************************************************************/
static void gotoNextPage(MeaMobInstance *inst)
{
    /* save current page on stack */
    pushPage(inst);

    /* adjust offset so we pass all objects previously shown */
    inst->moOffset += inst->noOfMoOnPage;   
    inst->noOfMoOnPage = 0;
    inst->currentMo = findMoAtOffset(inst);
    resetSpecialOps(inst);
}

/*!
 * \brief Switch to the previous page of attachments
 * \param inst  the current instance
 *****************************************************************************/
static void gotoPrevPage(MeaMobInstance *inst)
{
    /* pop previous page off stack */
    popPage(inst);
    inst->noOfMoOnPage = 0;
    inst->currentMo = findMoAtOffset(inst);
    resetSpecialOps(inst);
}

/*!
 * \brief Creates a new instance used for the media object browser
 * \param instance    The current instance.
 * \param mob         Mob activation information
 *****************************************************************************/
static void meaMobCreateInstance(MeaMobInstance **instance,
                                 MeaMobActivation *mob)
{    
    MEA_CALLOC(*instance, sizeof(MeaMobInstance));

    /* Copy data into structure */
    (*instance)->fsm            = mob->fsm;
    (*instance)->returnSignal   = mob->signal;
    (*instance)->moList         = mob->moList;
    (*instance)->sop            = mob->sop;
    (*instance)->winTitle       = mob->winTitle;

    MEA_FREE(mob);
}

/*!
 * \brief Deletes media object browser instance 
 *
 * \param instance The current instance.
 *****************************************************************************/
static void meaMobDeleteInstance(MeaMobInstance **instance)
{
    MeaMobInstance *inst;
    
    if (*instance != NULL)
    {
        inst = *instance;

        MEA_FREE(inst);
        *instance = NULL;
    }
}

/*!
 * \brief Checks if adding a new media object would exceed page limits
 * \param instance The current instance.
 * \return TRUE if limit would be exceeded 
 *****************************************************************************/
static MSF_BOOL moLimitExceeded(const MeaMobInstance *inst)
{
    return (MEA_MAX_NUMBER_OF_MO_ON_PAGE <= inst->noOfMoOnPage ||
            MEA_MAX_PAGE_HEIGHT <= inst->totalPageHeight);
}

/*!
 * \brief Add next special operation to widget
 * \param inst The current instance.
 * \return Signal telling what to do next
 *****************************************************************************/
static MeaMobSignalId addNextSpecialOp(MeaMobInstance *inst)
{
    MeaMobSpecialOp op = findSpecialOp(inst->sopToAdd);
    clearSpecialOp(&inst->sopToAdd, op);
#ifndef WAP_SUPPORT
    if (!meaUiMobAddSpecialOp(op))
    {
        return MEA_SIG_MOB_DEACTIVATE;
    }
#endif /*WAP_SUPPORT*/

    if (findSpecialOp(inst->sopToAdd))
    {
        return MEA_SIG_MOB_ADD_NEXT_SOP;        
    }

    return MEA_SIG_MOB_FINALIZE_WINDOW;
}

#ifdef MMS_SLIM_MEM
/*!
 *\brief Initializes the copy of the body (For DRM)
 *
 * \param dstFilePath Full path to destination file.
 * \param sourceFilePath Full path to source file.
 * \param startPos Start position for data to read from the source file.
 * \param dataSize Size of data in source file.
 * \param instance The current instance 
 *****************************************************************************/
MSF_BOOL meaCopyDrmMo(const char *dstFilePath, const char *sourceFilePath, MeaMoDataItem *mo, 
    MeaStateMachine fsm, unsigned int readRetSig, unsigned int writeRetSig)
{
    //MSF_UINT32 bytesToRead = 0;
    if (mo->data)    	
	    MEA_FREE(mo->data);    
    MEA_CALLOC(mo->data, MEA_ASIO_COPY_BUFFER_SIZE);
    if (!mo->data)
    	return FALSE;
    mo->bufsize = MEA_ASIO_COPY_BUFFER_SIZE;
    if (!mo->file)
    	return FALSE;

    if(mo->file->pos==0 ||mo->file->size==0)
    {
    	return FALSE;
    }

	if (mo->meaAsioReader)
		meaAsyncOperationStop(&mo->meaAsioReader);
	if (mo->meaAsioWriter)
		meaAsyncOperationStop(&mo->meaAsioReader);
    /* create read async operation */
    mo->meaAsioReader= 
        meaAsyncOperationStart(sourceFilePath, fsm, 0L, readRetSig, MEA_ASYNC_MODE_READ);
    if (!mo->meaAsioReader) 
   	    return FALSE;
     /* create write async operation */
    mo->meaAsioWriter = 
        meaAsyncOperationStart(dstFilePath, fsm, 0L, writeRetSig, MEA_ASYNC_MODE_APPEND);
    if (!mo->meaAsioWriter) 
   	    return FALSE;

    /* read first part of the file */
    if (mo->file->size <= MEA_ASIO_COPY_BUFFER_SIZE)
    {	
        mo->bytesInBuf = mo->file->size;
    }
    else
    {
        mo->bytesInBuf = MEA_ASIO_COPY_BUFFER_SIZE;
    } /* if */

    meaAsyncRead( mo->meaAsioReader,  mo->file->pos,mo->data,mo->bytesInBuf);
    return TRUE;
} /* meaCopyBody */

void meaReadMixedMoFinished(MSF_UINT32  handle, MsfNotificationType notificationType)
{
	if(mobInstance && mobInstance->currentMo)
	{
		MeaMoDataItem *mo=mobInstance->currentMo;
		if(mo->reshandle==handle && mo->isWaitWidgetRead==1)
		{
			(void)MEA_SIGNAL_SENDTO_IU(MEA_MOB_FSM, MEA_SIG_MOB_READ_FINISHED, handle,notificationType);   
		}
	}
	isForMeaAfiLoadFromFile(handle, notificationType);
	isForMeaReadMessagePart(handle, notificationType);
#ifdef __UNIFIED_MSG_SUPPORT__
	isForMeaReadMixedBodyPart(handle, notificationType);
#endif
}
#endif /* MMS_SLIM_MEM */

/*!
 * \brief Retrieve next media object from message
 * \param inst  the current instance
 * \return Signal telling what to do next
 *****************************************************************************/
static MeaMobSignalId getNextMediaObject(MeaMobInstance *inst)
{       
    if (!meaUiMobAddWidget(inst->currentMo))
    { 
        return MEA_SIG_MOB_DEACTIVATE;
    }
#ifdef MMS_SLIM_MEM
    if (inst->currentMo->isWaitWidgetRead==0)
    {
#endif /* MMS_SLIM_MEM */
    inst->currentMo = inst->currentMo->next;
    inst->noOfMoOnPage++;
    /* inst->totalPageHeight = ? ; */

    if (NULL == inst->currentMo || moLimitExceeded(inst))
    {
        /* Done with media objects, add special operations, or create window 
         if there are none */

        if (inst->moOffset > 0)                
        {
            inst->sopToAdd |= MEA_MOB_SOP_PREV_PAGE;
        }
        if (inst->currentMo && moLimitExceeded(inst))
        {
            inst->sopToAdd |= MEA_MOB_SOP_NEXT_PAGE;
        }
        if (inst->sopToAdd)
        {
            return MEA_SIG_MOB_ADD_NEXT_SOP;
        }
        else
        {
            return MEA_SIG_MOB_FINALIZE_WINDOW;
        }
    }
	/* More media objects, keep on adding */    
	return MEA_SIG_MOB_ADD_NEXT_MO;
#ifdef MMS_SLIM_MEM
	}
	else
	{
	    return MEA_SIG_MOB_WAIT_WIDGET;
	}
#endif /* MMS_SLIM_MEM */
}


/*!
 * \brief Find out which attachment was selected when pressing Menu or Yes
 * \param inst  the current instance
 * \return The attachment no., or -1 when no focused object can be found
 *****************************************************************************/
static int checkFocus(const MeaMobInstance *inst)
{
    int i = meaUiMobCheckFocus();

    if (i > -1)
    {
        i += (int)inst->moOffset;
    }
    return i;
}

/*!
 * \brief Handle a "MENU" button press
 * \param inst  the current instance
 *****************************************************************************/
static void handleMobMenu(const MeaMobInstance *inst)
{
    int i;

    i = checkFocus(inst);
    /* Pass the index of the object or -1 to the originating FSM */
    if (meaUiMobGetSpecialOp() != MEA_MOB_SOP_NO_OP)
    {
        i = -1;
    }
    (void)MEA_SIGNAL_SENDTO_IU(inst->fsm, inst->returnSignal, i, 
        (unsigned long)MEA_MOB_MENU);
}

/*!
 * \brief Handle an "OK" button press
 * \param inst  the current instance
 *****************************************************************************/
static void handleMobOk(MeaMobInstance *inst)
{
    int i;
    MeaMobSpecialOp sop;

    /* find out if user selected some special op or just an attachment */
    sop = meaUiMobGetSpecialOp();    
    switch (sop)
    {            
    case MEA_MOB_SOP_NEXT_PAGE: /* switch to next page */
    case MEA_MOB_SOP_PREV_PAGE: /* switch to previous page */
        if (MEA_MOB_SOP_NEXT_PAGE == sop)
        {
            gotoNextPage(inst);
        }
        else
        {
            gotoPrevPage(inst);
        }
        meaUiMobDeleteAll();
        /* First, initiate window */
        if (!meaUiInitializeForm())
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMOB_9C1CEC4B4CB4AC7457A763324AA0EB82, "%s(%d): Could not initialize form\n", 
                __FILE__, __LINE__));       
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            break;
        }
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, getNextMediaObject(inst));
        break;

    case MEA_MOB_SOP_NO_OP:     /* send selected item to fsm */
        i = checkFocus(inst);  
        if (i >= 0)
        {
            (void)MEA_SIGNAL_SENDTO_IUP(inst->fsm, inst->returnSignal, i,
                (unsigned long)MEA_MOB_SELECT, (void *)meaUiMobGetLink(i));
        }
#ifdef __UNIFIED_MSG_SUPPORT__
        else  /* empty MMS */
        {
            (void)MEA_SIGNAL_SENDTO_IUP(inst->fsm, inst->returnSignal, i, (unsigned long)MEA_MOB_SELECT, NULL);
        }
#endif
        break;

    case MEA_MOB_SOP_ADD_MO:    /* user defined special ops, send to fsm*/
        (void)MEA_SIGNAL_SENDTO_IU(inst->fsm, inst->returnSignal, sop,
            (unsigned long)MEA_MOB_SPECIAL_OP);
        break;

    default:                    
        /* some other, unhandled operation.. */
        break;
    }
}

/*!
 * \brief Signal handler for the multipart mixed message viewer 
 * \param sig The received signal 
 *****************************************************************************/
static void meaMobMain(MeaSignal *sig)
{
    /* reality check - MOB must be active before handling non-activation signals */
    if (NULL == mobInstance && (MeaMobSignalId) sig->type != MEA_SIG_MOB_ACTIVATE)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMOB_B5470DADECB01B2A44ABE81A61069C93, "%s(%d): Received signal %d without being active (ignored)!\n", __FILE__, __LINE__, sig->type));       
        return;
    }

    switch ((MeaMobSignalId) sig->type)
    {
    /* --- Activation/deactivation */

    case MEA_SIG_MOB_ACTIVATE:      /* Startup the mob */                
        meaMobCreateInstance(&mobInstance, (MeaMobActivation*)sig->p_param);       
        meaUiMobInit();
        gotoFirstPage(mobInstance);

        /* First, initiate window */
        if (!meaUiInitializeForm())
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMOB_9C1CEC4B4CB4AC7457A763324AA0EB82, "%s(%d): Could not initialize form\n", __FILE__, __LINE__));       
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            break;
        }       

        /* Then, if there are objects, start adding them */
        if (mobInstance->currentMo)
        {
            /* start adding media objects to list */       
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_ADD_NEXT_MO);        
        }
        /* ... otherwise just add special operations, if any */
        else if (findSpecialOp(mobInstance->sopToAdd))
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_ADD_NEXT_SOP);            
        }
        /* ...or else, with no objects or specials, just show blank window */
        else
        {
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_FINALIZE_WINDOW);
        }
        break;

    case MEA_SIG_MOB_DEACTIVATE:    /* Kill the mob */   
        /* Inform actor that MOB is done */
        (void)MEA_SIGNAL_SENDTO_UU(mobInstance->fsm, mobInstance->returnSignal,(unsigned long)MEA_MOB_DEACTIVATED, 0);        
        /* Kill widgets */
        meaUiMobTerminate();
        /* Clean-up the mob instance */
        meaMobDeleteInstance(&mobInstance);
        textTrunc = FALSE;
        break;

    /* --- Internal FSM states */
#ifdef MMS_SLIM_MEM
    case MEA_SIG_MOB_READ_FINISHED:		
        if(sig->u_param1==MsfNotifyResourceLoaded)
        {
            MeaMoDataItem *mo=mobInstance->currentMo;
            mo->isWaitWidgetRead = 0;
            switch (meaMediaType2ObjType(mo->content.type))
            {
                case MEA_MEDIA_GROUP_IMAGE:	
                    addWidget(mobInstance->currentMo->reshandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
                    break;
                case MEA_MEDIA_GROUP_VIDEO:	
                    addWidget(mobInstance->currentMo->reshandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_VIDEO, MEA_MOB_SOP_NO_OP);
                    break;
                case MEA_MEDIA_GROUP_AUDIO:
                    addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_AUDIO, MEA_MOB_SOP_NO_OP);
                    break;
    #ifdef __DRM_SUPPORT__
                case MEA_MEDIA_GROUP_DRM:
                    if(meaMediaType2ObjType(mo->content.drmType) == MEA_MEDIA_GROUP_IMAGE)
                    {
                        addWidget(mobInstance->currentMo->reshandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
                    }
                    else if(meaMediaType2ObjType(mo->content.drmType) == MEA_MEDIA_GROUP_AUDIO)
                    {
                        addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_AUDIO, MEA_MOB_SOP_NO_OP);
                    }
                    else if(meaMediaType2ObjType(mo->content.drmType) == MEA_MEDIA_GROUP_VIDEO)
                    {
                        addWidget(mobInstance->currentMo->reshandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_VIDEO, MEA_MOB_SOP_NO_OP);
                    }
                    break;
    #endif
            }
            /* After addWidget(), the MO handle belongs to meaUiMobWindow. Should be released with meaUiMobWindow */
            mobInstance->currentMo->reshandle = 0;
            mobInstance->currentMo = mobInstance->currentMo->next;
            mobInstance->noOfMoOnPage++;
    
            if (NULL == mo || moLimitExceeded(mobInstance))
            {
                /* Done with media objects, add special operations, or create window if there are none */
                if (mobInstance->moOffset > 0)                
                {
                    mobInstance->sopToAdd |= MEA_MOB_SOP_PREV_PAGE;
                }
    
                if (mo && moLimitExceeded(mobInstance))
                {
                    mobInstance->sopToAdd |= MEA_MOB_SOP_NEXT_PAGE;
                }
                
                if (mobInstance->sopToAdd)
                {
                    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_ADD_NEXT_SOP);
                    break;
                }
                else
                {
                    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_FINALIZE_WINDOW);
                    break;
                }
            }
    
    	 /* More media objects, keep on adding */    
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_ADD_NEXT_MO);
            break;		
        }
        else  /* if(sig->u_param1==MsfNotifyResourceLoaded) */
        {
            MeaMoDataItem *mo=mobInstance->currentMo;
            MSF_WIDGET_RELEASE(sig->i_param);  /* release load failed handle */
            switch (meaMediaType2ObjType(mo->content.type))
            {
                case MEA_MEDIA_GROUP_IMAGE:
                    mo->reshandle=MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR);
                    break;
                case MEA_MEDIA_GROUP_VIDEO:
                    mo->reshandle=MEA_GET_IMG_ID(MEA_IMG_VIDEO_ERROR);
                    break;
                case MEA_MEDIA_GROUP_AUDIO:
                    mo->reshandle=MEA_GET_IMG_ID(MEA_IMG_AUDIO_ERROR);
                    break;
                case MEA_MEDIA_GROUP_DRM:
                    mo->reshandle=MEA_GET_IMG_ID(MEA_IMG_BROKEN_IMAGE);
                    break;
            }
            mo->isWaitWidgetRead=0;
            (void)MEA_SIGNAL_SENDTO_IU(MEA_MOB_FSM, MEA_SIG_MOB_READ_FINISHED, mo->reshandle,MsfNotifyResourceLoaded); 
            break;
        }		
#endif /* MMS_SLIM_MEM */

    case MEA_SIG_MOB_ADD_NEXT_MO:   /* Create widget for next media object */ 
#ifdef MMS_SLIM_MEM
        {
            int mobSignal = getNextMediaObject(mobInstance);
            if (mobSignal != MEA_SIG_MOB_WAIT_WIDGET)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, mobSignal);
            }
        }
#else
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, getNextMediaObject(mobInstance));
#endif /* MMS_SLIM_MEM */
        break;

    case MEA_SIG_MOB_ADD_NEXT_SOP:  /* Create widget for next special op */
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, addNextSpecialOp(mobInstance));
        break;

    case MEA_SIG_MOB_FINALIZE_WINDOW: /* Create window with widgets */
        if (!meaUiMobFinalizeForm(mobInstance->moOffset))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MAMOB_CBE8B6A70562887DCA0F147C5E66B2C6, "%s(%d): Could not finalize form\n", 
                __FILE__, __LINE__));       

            HDIa_widgetExtCloseTransitionAnimation();

            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
        }

        if (textTrunc)
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_CONTENT_TRUNCATED), MEA_DIALOG_ALERT);
            textTrunc = FALSE;
        }
        HDIa_widgetExtCloseTransitionAnimation();
        break;

    /* --- UI related signals */
    case MEA_SIG_MOB_KEY_LEFT:      /* Left key pressed */
        if (mobInstance->moOffset <1)
        {
            break;
        }

        gotoPrevPage(mobInstance);
        meaUiMobDeleteAll();
        if (!meaUiInitializeForm())
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMOB_9C1CEC4B4CB4AC7457A763324AA0EB82, "%s(%d): Could not initialize form\n",  __FILE__, __LINE__));       
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            break;
        }
#ifdef MMS_SLIM_MEM
		{
			int mobSignal=getNextMediaObject(mobInstance);
			if (mobSignal!=MEA_SIG_MOB_WAIT_WIDGET)
			{
        		(void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, mobSignal);
			}
		}
#else
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, getNextMediaObject(mobInstance));
#endif /* MMS_SLIM_MEM */
        break;

    case MEA_SIG_MOB_KEY_RIGHT:    /* Right key pressed */
        if (!(mobInstance->currentMo && moLimitExceeded(mobInstance)))
        {
            break;
        }

        gotoNextPage(mobInstance);
        meaUiMobDeleteAll();
        if (!meaUiInitializeForm())
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMOB_9C1CEC4B4CB4AC7457A763324AA0EB82, "%s(%d): Could not initialize form\n", __FILE__, __LINE__));       
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            break;
        }
#ifdef MMS_SLIM_MEM
        {
            int mobSignal=getNextMediaObject(mobInstance);
            if (mobSignal!=MEA_SIG_MOB_WAIT_WIDGET)
            {
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, mobSignal);
            }
        }
#else
        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, getNextMediaObject(mobInstance));
#endif
        break;

#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
    case MEA_SIG_MOB_EVENT_SCROLL:
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMOB_D4A0ABA721780B3CE766982FDF3318C4, "MEA MMV Scroll: MEA_SIG_MOB_EVENT_SCROLL\n"));
        meaGetScrollOffset();
        break;
#endif

    case MEA_SIG_MOB_PLAY_AUDIO:
        meaUiMobPlayAudio();
        break;

    case MEA_SIG_MOB_PLAY_VIDEO:
        meaUiMobUpdateForm(TRUE);
        break;

    case MEA_SIG_MOB_MENU_SELECTED: /* User pressed Menu button */
        handleMobMenu(mobInstance);
        break;

    case MEA_SIG_MOB_OK_SELECTED: /* User pressed Ok button */
        meaUiMobStopAudio();
        handleMobOk(mobInstance);
        break;        

    case MEA_SIG_MOB_STOP_SELECTED: /* User pressed Stop LSK button */
        meaUiMobUpdateForm(FALSE);  /* LSK Stop -> LSK Option */
        break;        
       
    case MEA_SIG_MOB_FOCUS_ACTIVITY: /* audio widget lost focus */
        (void)MEA_SIGNAL_SENDTO_U(mobInstance->fsm, 
            mobInstance->returnSignal, MEA_MOB_FOCUS_ACTIVITY);            
        break;

#if defined(MMS_SLIM_MEM) && defined(__DRM_SUPPORT__)
	case MEA_SIG_MOB_READ_DRM_MO_RSP:
		if(sig->u_param1==MEA_ASIO_RESULT_OK)
		{
			MeaMoDataItem *mo=mobInstance->currentMo;
			meaAsyncWrite(mo->meaAsioWriter, -1, mo->data, mo->bytesInBuf);		
		}
		else
		{
			(void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_DEACTIVATE);
		}
		break;
	case MEA_SIG_MOB_WRITE_DRM_MO_RSP:
		if(sig->u_param1==MEA_ASIO_RESULT_OK)
		{
			MeaMoDataItem *mo=mobInstance->currentMo;
			mo->file->size-=mo->bytesInBuf;
			mo->file->pos+=mo->bytesInBuf;
			if(mo->file->size>0)
			{
				if(mo->file->size>MEA_ASIO_COPY_BUFFER_SIZE)
				{
					mo->bytesInBuf=MEA_ASIO_COPY_BUFFER_SIZE;					
				}
				else
				{
					mo->bytesInBuf=mo->file->size;
				}
				meaAsyncRead(mo->meaAsioReader, mo->file->pos, mo->data, mo->bytesInBuf);		
			}
			else
			{
				meaAsyncOperationStop(&mo->meaAsioReader);
				meaAsyncOperationStop(&mo->meaAsioWriter);
				MEA_CFREE(mo->data);
				//(void)MEA_SIGNAL_SENDTO_IU(MEA_MOB_FSM, MEA_SIG_MOB_COPY_DRM_FINISHED, 0, MsfNotifyResourceLoaded);
				(void)MEA_SIGNAL_SENDTO_I(MEA_MOB_FSM, MEA_SIG_MOB_COPY_DRM_FINISHED, TRUE);
			}
		}
		else
		{
			(void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_DEACTIVATE);
		}
				break;

	case MEA_SIG_MOB_COPY_DRM_FINISHED:
	{
           generateDRMObject(mobInstance->currentMo);	/* DRM phase 1 exclusive: Seperate delivery needs additional copy as before */

            if(!mobInstance->currentMo->isWaitWidgetRead)	/* Audio: need to call meaUiMobFinalizeForm() self, not by widget */
            {
                mobInstance->currentMo = mobInstance->currentMo->next;
                mobInstance->noOfMoOnPage++;
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_FINALIZE_WINDOW);
            }
	}
#endif /* defined(MMS_SLIM_MEM) && defined(__DRM_SUPPORT__) */

#ifdef MEA_GET_MIXED_TEXT_HEIGHT
#ifdef WIDGET_SLIDING_SMIL_VBAR

    case MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT:
        {
        textTrunc = (MSF_UINT32)sig->i_param;

        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAMOB_59AE1CACF2B57D715328A885B9E228C5, "[TEXT HEIGHT] MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT\n"));
        
        if (!mobInstance)
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAMOB_52809A11AB36DC390CA17CE5356A06D1, "[TEXT HEIGHT] !mobInstance\n"));
            HDIa_widgetExtCloseTransitionAnimation();
            break;
        }

        if (meaUiMobCreateGetTextHeightInst((char*)mobInstance->currentMo->data) == TRUE)
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAMOB_A34BBAD1CA764BF2C16D853A8A523525, "[TEXT HEIGHT] Send MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_CONTINUE\n"));
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_CONTINUE);
        }
        else
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAMOB_C6C73DAE03C8A4F1E59AE1D81C518FF6, "[TEXT HEIGHT] Send MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED\n"));
            (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED);
        }
        }
        break;
        
    case MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_CONTINUE:
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAMOB_C8DFD5824141F46F15DD91156BBCFD44, "[TEXT HEIGHT] MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_CONTINUE\n"));

            if (!mobInstance)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAMOB_EAEC21A2D3C32766CF05D15F7DD418C1, "[TEXT HEIGHT] no mobInstance\n"));
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            
            if (meaUiMobGetTextHeight() == FALSE)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAMOB_7C84DA59C78E1D53FE72AA704F9016E9, "[TEXT HEIGHT] set timer\n"));
                
                MSF_TIMER_SET (MSF_MODID_MEA, MEA_MOB_TEXT_HEIGHT_TIMER_ID, 
                    MEA_MOB_GET_TEXT_HEIGHT_TIMER_DUR);
            }
            else
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAMOB_7853CCAF34C0D6C84BA29101C7DAC176, "[TEXT HEIGHT] send MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED\n"));
                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM,MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED);
            }
        }
        break;
        
    case MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED:
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAMOB_796CDAE5E171E37CC5DE66EAB7083BF0, "[TEXT HEIGHT] MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT_FINISHED\n"));
            
            if (!mobInstance)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAMOB_EAEC21A2D3C32766CF05D15F7DD418C1, "[TEXT HEIGHT] no mobInstance\n"));
                HDIa_widgetExtCloseTransitionAnimation();
                break;
            }
            
            meaUiMobSetTotalTextHeightValue();
            meaUiMobDeleteGetTextHeightInst();

            mobInstance->currentMo->isWaitWidgetRead = 0;
            
            if (!meaUiMobAddTextWidget(mobInstance->currentMo))
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAMOB_0C33BADF04D66487A2DDD661EED71121, "[TEXT HEIGHT] meaUiMobAddTextWidget failed\n"));

                HDIa_widgetExtCloseTransitionAnimation();

                (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE);
            }
            else
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAMOB_F0D092CE7E6024E62EDE578B7DEDA9E3, "[TEXT HEIGHT] meaUiMobAddTextWidget ok\n"));
                
                mobInstance->currentMo = mobInstance->currentMo->next;
                mobInstance->noOfMoOnPage++;

                if (NULL == mobInstance->currentMo || moLimitExceeded(mobInstance))
                {
                    /* Done with media objects, add special operations, or create window 
                     if there are none */
                    if (mobInstance->moOffset > 0)                
                    {
                        mobInstance->sopToAdd |= MEA_MOB_SOP_PREV_PAGE;
                    }
                    if (mobInstance->currentMo && moLimitExceeded(mobInstance))
                    {
                        mobInstance->sopToAdd |= MEA_MOB_SOP_NEXT_PAGE;
                    }
                    if (mobInstance->sopToAdd)
                    {
                        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                            MAMOB_9B6490B8EB8CFD5C762E2A334AF489E4, "[TEXT HEIGHT] send MEA_SIG_MOB_ADD_NEXT_SOP\n"));
                        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_ADD_NEXT_SOP);
                    }
                    else
                    {
                        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                            MAMOB_A176A95D5C7868EF419C03033BD94F9C, "[TEXT HEIGHT] send MEA_SIG_MOB_FINALIZE_WINDOW\n"));
                        (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_FINALIZE_WINDOW);
                    }
                }
             }

             //HDIa_widgetExtCloseTransitionAnimation();

        }
        break;
        
#endif
#endif //MEA_GET_MIXED_TEXT_HEIGHT

    /* --- Unknown signals */       
    default: 
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAMOB_4314C7BDD4E35DC8E4592FBE7FBF2AFC, "%s(%d): meaMobMain erroneous signal received(%d)\n", 
            __FILE__, __LINE__, sig->type));       
        break;
    }
    meaSignalDelete(sig);
}

#ifdef WAP_SUPPORT
/*!
 * \brief Get media object current index
 * \param moList   media object list
 * \return The media object index
 *****************************************************************************/
int meaMobGetMoIndex(const MeaMoDataItem *mo)
{
    MSF_INT32 index = 0;
    MeaMoDataItem *mediaObjects = mobInstance->moList;

    if(mo == NULL || mediaObjects == NULL)
        return -1;
    
    while (mediaObjects != NULL && mediaObjects != mo)
    {
        index++;
        mediaObjects = mediaObjects->next;
    }
    return index;
}

/*!
 * \brief Get media object total count
 * \param
 * \return The media object total count
 *****************************************************************************/
unsigned int meaMobGetMoCount()
{
    int count = 0;
    MeaMoDataItem *mo = mobInstance->moList;
    while (mo != NULL)
    {
        count++;
        mo = mo->next;
    }
    return count;
}

/*
MSF_BOOL meaMobCheckIsText(void)
{
	int i;
	MeaMoDataItem *currentMoDataItem = mobInstance->moList;
	if (!mobInstance->moList)
		return FALSE;
	for (i=mobInstance->moOffset;i>0;i--)
		currentMoDataItem = currentMoDataItem->next;
	return (currentMoDataItem->content.type == MEA_MEDIA_TYPE_TEXT_PLAIN);
}
*/

#ifndef __UNIFIED_MSG_SUPPORT__
MSF_BOOL meaMobCheckIsEmpty(void)
{
	int i;
	MeaMoDataItem *currentMoDataItem = mobInstance->moList;

        if (currentMoDataItem == NULL)
            return TRUE;

	if (meaMediaType2ObjType(currentMoDataItem->content.type) == MEA_MEDIA_GROUP_TEXT && currentMoDataItem->next == NULL)
	{
        if (currentMoDataItem->size == 0)
        {
    		return TRUE;
        }
        else
        {
            return FALSE;
        }
	}

	for (i=mobInstance->moOffset; i>0; i--)
	{
		currentMoDataItem = currentMoDataItem->next;
	}
	return (currentMoDataItem->size == 0);
}
#endif /* __UNIFIED_MSG_SUPPORT__ */
#endif /*WAP_SUPPORT*/
/*!
 * \brief Activate the Mob
 * \param moList   media object list
 * \param sop      bit mask of special operations to add. 
 * \param winTitle title of Mob window. 
 * \param fsm      fsm to send signal to
 * \param signal   signal to send to fsm
 *****************************************************************************/
void meaMobActivate(MeaMoDataItem *moList, MeaMobSpecialOp sop, 
                    MSF_UINT32 winTitle, MeaStateMachine fsm, int signal)
{
    MeaMobActivation *mob;

    mob = MEA_ALLOC(sizeof(MeaMobActivation));
    mob->moList = moList;    
    mob->sop = sop;
    mob->winTitle = winTitle;
    mob->fsm = fsm;
    mob->signal = signal;

    (void)MEA_SIGNAL_SENDTO_P(MEA_MOB_FSM, MEA_SIG_MOB_ACTIVATE, mob);     
}

/*!
 * \brief Registers signal handler
 *****************************************************************************/
void meaMobInit(void)
{
    mobInstance = NULL;
    meaSignalRegisterDst(MEA_MOB_FSM, meaMobMain); /* set sig-handler */
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAMOB_B1BB07A6A3807EF64996E717D7AB3012, "MEA MOB: initialized\n"));
}

/*!
 * \brief Terminates, by de-registering signal handler
 *****************************************************************************/
void meaMobTerminate(void)
{
#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    /* Kill Timer*/
    MSF_TIMER_RESET (MSF_MODID_MEA, MEA_MOB_TEXT_HEIGHT_TIMER_ID);
    HDIa_widgetExtCloseTransitionAnimation();
#endif

    /* Kill widgets */
    meaUiMobTerminate();
    /* Clean-up the mob instance */
    meaMobDeleteInstance(&mobInstance);
    textTrunc = FALSE;
    /* Deregister signal handler */
    meaSignalDeregister(MEA_MOB_FSM);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MAMOB_2457FD7A8270D48077BBA1F90D358F3F, "MEA MOB: terminated\n"));
}

MSF_BOOL meaMobIsActive(void)
{
    return (mobInstance != NULL);
}


















