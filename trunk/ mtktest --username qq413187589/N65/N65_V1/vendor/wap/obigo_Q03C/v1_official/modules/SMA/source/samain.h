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

#ifndef _SAMAIN_H
#define _SAMAIN_H


#ifndef _SLS_IF_H
#error sls_if.h must be included berfore samain.h!
#endif

/*--- Definitions/Declarations ---*/
#define SMA_FIRST_SLIDE 0

/*! Panic code for longjmp */
#define SMA_PANIC 1
/*! Should only be used internally. SMA is out of memory */
#define SMA_PANIC_OUT_OF_MEMORY 1
/*! Should only be used internally. Just exit (dont terminate application)*/
#define SMA_PANIC_NO_DIALOG 3
/*! Should only be used internally. Terminate SMA application */
#define SMA_PANIC_TERMINATE 4

/* Shut down states */
/*! Should only be used internally. Terminate SLS */
#define SMA_TERM_SLS    0
/*! Should only be used internally. Terminate SMA application */
#define SMA_TERM_DIE    1
/*! Should only be used internally. Exit SMA application and return signal
 *  to caller, but no shutdown */
#define SMA_TERM_EXIT   2

/*! Inform MEA to exit the smil player (MEA keeps state which needs to be updated)*/
#define EXIT_SMIL_PLAYER(result) (void)SMA_SIGNAL_SENDTO_IU(SMA_FSM_MAIN, \
    SMA_SIG_MH_TERMINATE_APP, (result), SMA_TERM_EXIT)

/*! Terminate the smil player */
#define TERMINATE_SMIL_PLAYER(result, state) (void)SMA_SIGNAL_SENDTO_IU(SMA_FSM_MAIN, \
    SMA_SIG_MH_TERMINATE_APP, (result), (state))

 #ifdef WAP_SUPPORT
#define SMA_ACTION_COUNT_DOWN_TIME 10
 #endif /* WAP_SUPPORT */

/*--- Types ---*/

typedef enum
{
    /*! Set play timer
     *  - Param I : -  
     *  - Param U1: -
     *  - Param U2: -
     *  - Param P : -
     */
    SMA_SIG_MH_SET_TIMER,
    /*! Set play timer
     *  - Param I : -  
     *  - Param U1: -
     *  - Param U2: -
     *  - Param P : -
     */
    SMA_SIG_MH_NO_TIMER,

    /*! Save body part is complete 
     *  - Param I : -  
     *  - Param U1: Result of the operation
     *  - Param U2: -
     *  - Param P : -
     */
    SMA_SIG_MH_SBP_COMPLETE,

    /*! Terminate SMA 
     */
    SMA_SIG_MH_TERMINATE_APP

#ifdef __UNIFIED_MSG_SUPPORT__
    ,SMA_SIG_MH_DELETE_MM,
    SMA_SIG_MH_DELETE_ALL_MM
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    ,SMA_SIG_MH_MOVE_TO_ARCHIVE
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#endif
} SmaStates;

extern int smaPanicMode;

/*********************************************
 * Exported function
 *********************************************/

MSF_BOOL smaMainInit(void);
void smaMainTerminate(void);
void exitSmilPlayer(SmaResult result, MSF_BOOL sendRsp);
char *convertToUTF8(MSF_UINT32 charset, const char *srcData, 
    MSF_UINT32 *srcSize, MSF_UINT32 *dstSize);
SmaPlayerInfo *getPlayerInfo(void);
SmaResult playSmil(SmaPlayerInfo *playerInfo);
SmaResult stopSmil(SmaPlayerInfo *playerInfo);
SmaResult rewindSmil(SmaPlayerInfo *playerInfo);
SmaResult displayPreviousSlide(SmaPlayerInfo *playerInfo);
void setGadgetRegion(MsfSize *gadgetSize, MsfPosition *gadgetPosition,
    const SmaObjectInfo *object);
MSF_BOOL slsIsRunning(void);
void setSlsIsRunnig( MSF_BOOL value);
void sendResult(MSF_UINT8 senderModule, SmaResult result); 
MSF_BOOL isFirstData( const SmaPlayerInfo *playerInfo);
SmaSlideInfo *getSlideInfo( MSF_UINT32 number, SmaPlayerInfo *playerInfo);
void stopPlayTimer( void);
#ifdef WAP_SUPPORT
MSF_BOOL displayCountDown(MSF_BOOL isShow);
#endif /* WAP_SUPPORT */
void setPlayTimer( MSF_UINT32 duration);
MSF_BOOL checkObjectType(SlsMediaObjectType objType, SmaSlideInfo *slide);
void initializeSma(void);
MSF_BOOL smaIsRunning(void);
void setSmaIsRunning( MSF_BOOL state);
MSF_BOOL isKnownType(SlsMediaType mediaType, SlsMediaObjectType objType);
SlsMediaObjectType smaGetObjectType(SlsMediaType mediaType);
MSF_INT32 convertSmaToMsfMediaTypes(SlsMediaType slsMediaType);
SmaLinkItem *getCurrentLinks(void);
MSF_BOOL createLinksMenu(void);
MSF_BOOL handleSmaErr( SmaResult result);
SmaResult getSmaExitResult(void);
void smaSetJumpBuffer(jmp_buf *jmpbuf);
const SmaMediaTypeItem *smaGetSupportedMediaTypes(void);
const char *convertSlsToMimeType(SlsMediaType slsMediaType);
void smaMakeCall(const char *number);
void smaMakeCallRsp(const msf_tel_make_call_resp_t *callRsp);
MSF_BOOL smaIsInitialized(void);
void setSmaIsInitialized( MSF_BOOL state);
void smaInterruptHandler(U16 param);

/*!
 * \brief This function should be used internally (i.e. be called by the SMA)
 *
 *****************************************************************************/
void smaPanic( int mode, SmaResult result);


#endif /* _SAMAIN_H */


