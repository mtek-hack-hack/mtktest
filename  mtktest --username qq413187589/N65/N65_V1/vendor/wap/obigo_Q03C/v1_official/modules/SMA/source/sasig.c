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
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_log.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
#include "sls_def.h"

/* SMA */
#include "sma_if.h"
#include "sma_cfg.h"
#include "samem.h"
#include "satypes.h"        /* SMA: */
#include "samain.h"
#include "saintsig.h"
#include "saasync.h"
#include "sasls.h"
#include "sasig.h"
#include "saui.h"
#include "sasls.h"
#include "saph.h"
#include "sapipe.h"
#include "sauisig.h"
#include "saslide.h"

#ifdef WAP_SUPPORT
#include "sma_cfg.h"
#include "mms_def.h"
#include "mmsl_if.h"
#include "msig.h"
#include "fldmgr.h"

/* MMA */
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "msf_wid.h"
#include "mmsadp.h"
#include "mma_if.h"
#endif

#ifdef MMS_SLIM_MEM
#include "msf_pck.h" //for MSF_PACKAGE_SIGNAL_HANDLED
#include "msf_act.h" //for msf_act_handle_signal

extern msf_pck_handle_t* smaGetActHandle(void);
#endif /* MMS_SLIM_MEM */
#endif /* WAP_SUPPORT */


/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

/*--- Prototypes ---*/
static MSF_UINT8 handleModuleStatus (MSF_UINT8 status, MSF_UINT8 module);


#ifdef __UNIFIED_MSG_SUPPORT__
static MSF_UINT32 smaAddressCount(MmsAddressList *list)
{
    MSF_UINT32 count = 0;
    for(; list != NULL; list = list->next, count++);

    return count;
}
#endif

/*! \brief Receive external signals.
 *  \param srcModule Source module calling SMA.
 *  \param signal The signal to handle
 *  \param p Buffer containing signal data
 *****************************************************************************/
void smaReceiveExtSignal(MSF_UINT8 srcModule, MSF_UINT16 signal, void* p)
{
    SmaResult result = SMA_RESULT_OK;       /* default value */
    SmaPlayerInfo *playerInfo = getPlayerInfo();
	msf_pipe_notify_t *pn;

	/* Check if the package handler consumes this signal */
    if (smaPhHandleSignal(signal, p))
    {
        MSF_SIGNAL_DESTRUCT(MSF_MODID_SMA, signal, p);
        return;
    }
    
    switch (signal) 
    {
    case MSF_SIG_MODULE_TERMINATE:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_64DF14BF763210DD0A80CAC97376D79A, "SMA: received  "
            "signal MSF_SIG_MODULE_TERMINATE\n"));

        /* terminate the smil service */
        TERMINATE_SMIL_PLAYER(SMA_RESULT_OK, SMA_TERM_SLS);
        break;
    case MSF_SIG_MODULE_STATUS:
        {
            /* received module status */
            msf_module_status_t *str = (msf_module_status_t*)p;

            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_1EF6140BB17115F56C0DA84954D37D63, "SMA: received "
                "signal MSF_SIG_MODULE_STATUS\n"));            
            
            /* handle the received module status */
            if ( !handleModuleStatus(str->status, str->modId))
            {
                /* SMA Should terminate */
                TERMINATE_SMIL_PLAYER(SMA_RESULT_OK, SMA_TERM_DIE);
            } 
            else
            {
                if (!smaIsInitialized()) 
                {
                    initializeSma();                
                }
                setSlsIsRunnig( TRUE);
            } /* if */
            
            break;
        }
    case MSF_SIG_FILE_NOTIFY:
		if (!smaIsRunning())
		{
			/* sma is not currently initialized and running, skip this signal */
			break;
		} /* if */
        (void)SMA_SIGNAL_SENDTO_IU(SMA_FSM_ASYNC, SMA_SIG_ASYNC_NOTIFY,
            ((msf_file_notify_t *)p)->eventType, 
            (MSF_UINT32)((msf_file_notify_t *)p)->fileHandle);
        break;
	case MSF_SIG_PIPE_NOTIFY:
		pn = (msf_pipe_notify_t *)p;
		(void)SMA_SIGNAL_SENDTO_UU(SMA_FSM_PIPE, SMA_SIG_PIPE_NOTIFY, 
			(MSF_UINT32)pn->handle, pn->eventType);
		break;
    case SMA_SIG_PLAY_SMIL_REQ:
        {
            SmaPlaySmilReq *message = (SmaPlaySmilReq *)p;
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_1598B625D5F178196E24C2351EC3C290, "SMA: received "
                "signal SMA_SIG_PLAY_SMIL\n"));            
            
            if ( smaIsRunning())
            {
                sendResult(srcModule, SMA_RESULT_BUSY);
            }
            else
            {
                if (!smaIsInitialized()) 
                {
                    initializeSma();                
                }
                setSmaIsRunning(TRUE);
                setSlsIsRunnig(TRUE);
                playerInfo->msgId = message->msgId;
                playerInfo->sourceModule = srcModule; 
                playerInfo->fileType = message->fileType;
#ifdef __UNIFIED_MSG_SUPPORT__
                {
                    MmsMsgHandle m_handle;  /* MmsMessage */
                    MmsTransactionHandle t_handle;
                    MmsGetHeader header;
                    if (MMSlib_transactionOpen(MSF_MODID_SMA, &t_handle) != MMS_RESULT_OK)
                    {
                        EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
                        break;
                    } 
                    else if (MMSlib_messageOpen(MSF_MODID_SMA, playerInfo->msgId, fldrGetFileSuffix(playerInfo->msgId), 
                        &m_handle) != MMS_RESULT_OK)
                    {
                        (void)MMSlib_transactionClose(MSF_MODID_SMA, &t_handle);
                        EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
                        break;
                    } 

                    if(MMSlib_getMessageHeader(MSF_MODID_SMA, &header, &m_handle, &t_handle) != MMS_RESULT_OK)
                    {
                        (void)MMSlib_messageClose(MSF_MODID_SMA, &m_handle);
                        (void)MMSlib_transactionClose(MSF_MODID_SMA, &t_handle);
                        EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
                        break;
                    }
                    (void)MMSlib_messageClose(MSF_MODID_SMA, &m_handle);
                    (void)MMSlib_transactionClose(MSF_MODID_SMA, &t_handle);

                    playerInfo->folder = fldrGetFolderId(playerInfo->msgId);
                    playerInfo->recipientNo = smaAddressCount(header.to) + smaAddressCount(header.cc) + 
                        smaAddressCount(header.bcc);
                    playerInfo->forwardLock = header.forwardLock;
                }
#endif
                result = createGUI();
                if (result == SMA_RESULT_OK)
                {
                    /* now open the smil message */
                    if (SLS_RESULT_OK != SLSif_openSmil( 
                        MSF_MODID_SMA, playerInfo->msgId, playerInfo->fileType)) 
                    {
                        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
                            SASIG_E652292EA5F3061C01A3EA1C9DC63C89, "SMA: SLS_openSmil failed\n"));
                        result = SMA_RESULT_ERROR;
                        EXIT_SMIL_PLAYER(result);
                    } /* if */
                } /* if */
            } /* if */
            break;
        }

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    case MMA_SIG_START_UC_RSP:
        {
            mma_uc_start_rsp_struct *rsp = (mma_uc_start_rsp_struct *)p;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, SASIG_65F4D4BF2E010DF6413C558633FCD04A, "SMA: received signal MMA_SIG_START_UC_RSP (%d, %d)\n", 
                rsp->result, rsp->mode));

            switch(rsp->result)
            {
            case MMA_RESULT_OK:
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
                HDIa_widgetExtDeleteWidgetScreenIfPresent();
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
  #endif
  #if defined(SMA_CFG_USER_TEMPLATE_SUPPORT) && defined(__UNIFIED_MSG_SUPPORT__)
                meaDeleteMhInst();
                meaDeleteTemplatesFolderList();
  #endif
                break;
            case MMA_RESULT_FAIL_IN_CALL:
                break;
            default:
                switch(rsp->mode)
                {
                case MMA_MODE_EDIT:
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MsfError, 0);
                    break;
                case MMA_MODE_SEND:
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_TO_SEND), MsfError, 0);
                    break;
                case MMA_MODE_REPLY:
                case MMA_MODE_REPLY_ALL:
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_TO_REPLY), MsfError, 0);
                    break;
                case MMA_MODE_FORWARD:
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD), MsfError, 0);
                    break;
                default:
                    break;
                }
                break;
            }
            break;
        }
#endif
    case MSF_SIG_WIDGET_ACTION:
    case MSF_SIG_WIDGET_NOTIFY:
    case MSF_SIG_WIDGET_USEREVT:
        {
			if (!smaIsRunning())
			{
				/* sma is not currently initialized and running, skip this signal */
				break;
			} /* if */

			smaWidgetSignalHandler(signal, p);
            break;
        }
    case MSF_SIG_TIMER_EXPIRED:
        {
			msf_timer_expired_t *timer = (msf_timer_expired_t *)p;
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_6B6EC80873332B8FD117D82099D10579, "SMA: received "
                "signal MSF_SIG_TIMER_EXPIRED\n"));
			if (!smaIsRunning())
			{
				/* sma is not currently initialized and running, skip this signal */
				break;
			} /* if */
			
			
            if (timer->timerID == SMA_SLIDE_TIMER_ID)
            {
#ifdef WAP_SUPPORT
                MSF_BOOL stillHaveTime = displayCountDown(TRUE);

                if (GetActiveScreenId() != WAP_SCREEN_WIDGET) /* Interrupt happen*/
                {
                    result = stopSmil(getPlayerInfo());
                    break;
                }

                if (!stillHaveTime)
                {
#endif /* WAP_SUPPORT */

#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
                    SmaPlayerInfo * playerinfo = getPlayerInfo();
                    if ( !playerinfo->isAutoplay )
                    {
                        result = stopSmil(playerinfo);
                    } else {
#endif

                    /* Slide timer expired, show next slide */
                    result = displayNextSlide( getPlayerInfo());
                    if ( SMA_RESULT_OK != result)
                    {
                        /* unable to show next slide */
                        EXIT_SMIL_PLAYER(result);
                    } /* if */
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
                    }
#endif

#ifdef WAP_SUPPORT
                }
#endif /* WAP_SUPPORT */
            }
            else if (timer->timerID == SMA_DIALOG_TIMER_ID && 
                playerInfo->isPlaying)
            {
                /* Dialog timer expired, kill dialog screen */
                widgetDeleteScreen();
            } 
            else if (timer->timerID == SMA_ACTION_IMAGE_TIMER_ID)
            {
#ifndef WAP_SUPPORT
                /* Action Image timer expired, remove the action icon */
                deleteStatusIconHandle();
#endif /* ~WAP_SUPPORT */
            } /* if */
#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
            else if (timer->timerID == SMA_GET_TOTAL_TEXT_HEIGHT_TIMER_ID)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SASIG_7206E2A049C3E38DEC709F5940C2CA47, "[TEXT HEIGHT] MEA_MOB_TEXT_HEIGHT_TIMER_ID\n"));
            
                (void)SMA_SIGNAL_SENDTO(SMA_FSM_SLIDE,
                    SMA_SIG_GET_TOTAL_TEXT_HEIGHT_CONTINUE);
            }
#endif
            break;
        }
    case MSF_SIG_MODULE_EXECUTE_COMMAND:
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_24BC4A055B5792912076DD916105F069, "SMA: received "
            "signal MSF_SIG_MODULE_START\n"));
        
            /* starting SMIL Service */
            MSF_MODULE_START(MSF_MODID_SMA, MSF_MODID_SLS, NULL, NULL, NULL);
            break;
        }
    case SLS_OPEN_SMIL_RSP:
        {
            /* Got some smile information */
            SlsOpenSmilRsp *openSmilRsp = (SlsOpenSmilRsp *)p;
            
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_05237E33B3EDF7DA1B38D25576C9DEF3, "SMA: received "
                " signal SLS_OPEN_SMIL_RSP\n"));
            
            result = handleOpenSmilRsp( playerInfo, openSmilRsp);

            if ( result != SMA_RESULT_OK)
            {
                EXIT_SMIL_PLAYER(result);
            } /* if */

            if ((result = createSlideForm()) != SMA_RESULT_OK)
            {
                EXIT_SMIL_PLAYER(result);
            } /* if */
            break;
        }
    case SLS_GET_SLIDE_INFO_RSP:
        {
			/* Got some Slide information */
            SlsGetSlideInfoRsp *rsp = (SlsGetSlideInfoRsp *)p;
            SmaSlideInfo *slide;

			if (!smaIsRunning())
			{
				/* sma is not currently initialized and running, skip this signal */
				break;
			} /* if */
			
            slide = getSlideInfo( playerInfo->currentSlide, playerInfo);

            if ( rsp == NULL || slide == NULL || 
                rsp->result != SLS_RESULT_OK)
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_340FFD36EF830115392AF09C76385E40, "SMA: SLS "
                    "failed to get slide info in SLS_GET_SLIDE_INFO_RSP\n"));
                EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
            }
            else
            {
                /* set slide data */
                if ( SMA_RESULT_OK != handleGetSlideInfoRsp( &rsp->slideInfo, 
                    slide))
                {
                    /* error parsing slide information */
                    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_13CC547BB252E76B64D8207F572BABB5, "SMA: \
                        failed to get parse info in SLS_GET_SLIDE_INFO_RSP\n"));
                    EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
                } 
                else
                {
                    /* done with current slide */
                    if ( playerInfo->currentSlide < playerInfo->noOfSlides-1)
                    {
                        /* there is more slides */
                        /* allocate memory for next slide */
                        slide->next = SMA_ALLOC( sizeof( SmaSlideInfo));
                        memset( slide->next, 0x00, sizeof( SmaSlideInfo));
                        playerInfo->currentSlide++;
                        /* get slide info for next slide */
                        if (SLSif_getSlideInfo( MSF_MODID_SMA, 
                            playerInfo->currentSlide) != SLS_RESULT_OK)
                        {
                            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
                                SASIG_458B4FADEEB3814E0D63C4010CC1F807, "SMA: SLS_getSlideInfo failed\n"));
                            result = SMA_RESULT_ERROR;
                        } /* if */
                    }
                    else
                    {
                        #if SLS_ALWAYS_VIEW_MAX_NBR_OF_SLIDES//==1
							if(playerInfo->result == SLS_RESULT_TO_MANY_SLIDES)
							{
								handleSmaErr(SMA_RESULT_TO_MANY_SLIDES);
							}
						#endif
                        /* no more slides - start playing */
                        (void)SLSif_closeSmil( MSF_MODID_SMA);
                        playerInfo->currentSlide = 0;
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
                        if ( playerInfo->isAutoplay )
                            result = playSmil( playerInfo);
                        else {
#ifdef __UNIFIED_MESSAGE_MANUAL_PLAY_SLIDE__
                            playerInfo->isPlaying = TRUE;
                            updateSlideFormActions(playerInfo->isPlaying);
#endif
                            result = displayCurrentSlide( playerInfo);
                        }
#else
                        result = playSmil( playerInfo);
#endif


#ifdef __UNIFIED_COMPOSER_SUPPORT__
                        if(MMA_IS_UNIFIED_COMPOSER_ACTIVE() == TRUE)  /* SMA notify UC that it took over the screen */
                        {
                            void *sig;
                            sig = MSF_SIGNAL_CREATE (SMA_SIG_PLAY_SMIL_IND, MSF_MODID_SMA, playerInfo->sourceModule, 0);
                            MSF_SIGNAL_SEND (sig);
                        }
#endif
                    } /* if */

                } /* if */
            }
            break;
        }
    case SLS_CLOSE_SMIL_RSP:
        {
	        SlsCloseSmilRsp *closeSmilRsp = (SlsCloseSmilRsp *)p;

            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
                SASIG_A2D62B56D3C9C00FA19C7B35C7D225D6, "SMA: received signal SLS_CLOSE_SMIL_RSP\n"));

			if (!smaIsRunning())
			{
				/* sma is not currently initialized and running, skip this signal */
				break;
			} /* if */
			
			if ( closeSmilRsp == NULL)
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, 
                    SASIG_28BF43FF9366FD551860436802BA026B, "SMA: SLS failed to close SMIL in SLS_CLOSE_SMIL_RSP\n"));
                EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
            } 
            else if ( closeSmilRsp->result != SLS_RESULT_OK)
            {
                result = SMA_RESULT_ERROR;    
            }/* if */
            break;
        }
    case MSF_SIG_TEL_MAKE_CALL_RESPONSE:
        smaMakeCallRsp((msf_tel_make_call_resp_t *)p);
        break;
    default:
        {
            /* This was not a signal that we are interested in */
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SASIG_72F34523A56357CCA0CB023178754204, "SMA: received "
                "unknown signal: %d\n", signal));
            break;
        }
    } /* switch */
    
    if (p != NULL)
    {
        MSF_SIGNAL_DESTRUCT (MSF_MODID_SMA, signal, p);
    } /* if */
} /* smaReceiveExtSignal */



/*! \brief Handles module status information. Only information about
 *         the SLS module is used. On all other modules TRUE is returned. 
 *  \param status Status of the module.
 *  \paramn module The module to check status on.
 *  \return TRUE on success or if the module is of no importance. FALSE if SMA
 *          should terminate.
 *****************************************************************************/
static MSF_UINT8 handleModuleStatus (MSF_UINT8 status, MSF_UINT8 module)
{
    MSF_UINT8 result = TRUE;
    
    if ( module == MSF_MODID_SLS)
    {
        if (status == MODULE_STATUS_ACTIVE)
        {
            /* SLS is running, activate SMA */
            MSF_MODULE_IS_ACTIVE(MSF_MODID_SMA); 
            if (SLS_RESULT_OK != SLSif_startInterface())
            {
                result = FALSE;
            } /* if */
            setSlsIsRunnig( TRUE);
        } 
        else if ( status == MODULE_STATUS_TERMINATED)
        {
            result = FALSE;
            setSlsIsRunnig( FALSE);
        } /* if */
    } /* if */
    return result;
} /* handleModuleStatus */


