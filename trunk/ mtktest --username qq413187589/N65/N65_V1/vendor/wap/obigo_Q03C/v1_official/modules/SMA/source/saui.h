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
 
#ifndef _SAUI_H
#define _SAUI_H

#ifndef _SATYPES_H
#error satypes.h must be included berfore saui.h!
#endif
#ifndef _SMA_DEF_H
#error sma_def.h must be included berfore saui.h!
#endif

/*--- Definitions/Declarations ---*/

/* Macros */
#define SMA_GET_STR_ID(strId)       MSF_WIDGET_STRING_GET_PREDEFINED(strId)

/*--- Types ---*/

/* \enum SmaGadgetType Defines diferent gadgets for output */
typedef enum
{
	SMA_GADGET_ICON,	/* Gadget to use for icons */
    SMA_GADGET_IMAGE,	/* Gadget to use for image */
	SMA_GADGET_STRING,	/* Gadget to use for string text */
	SMA_GADGET_ALT		/* Gadget to use for alternative text attribute */
} SmaGadgetType;

/* \enum SmaDialogType Defines actions that have been requested */
typedef enum
{
    SMA_ACTION_STOP,
    SMA_ACTION_PLAY
} SmaActionType;

#ifdef __UNIFIED_MSG_SUPPORT__
typedef enum
{
    SMA_SLIDE_MENU_PLAY,
    SMA_SLIDE_MENU_SEND,
    SMA_SLIDE_MENU_REPLY,
    SMA_SLIDE_MENU_REPLY_SMS,
    SMA_SLIDE_MENU_REPLY_ALL,
    SMA_SLIDE_MENU_FORWARD,
    SMA_SLIDE_MENU_EDIT,
    SMA_SLIDE_MENU_DELETE,
    SMA_SLIDE_MENU_DELETE_ALL,
    SMA_SLIDE_MENU_PROPERTIES,
    SMA_SLIDE_MENU_SAVE_OBJECT,
    SMA_SLIDE_MENU_USE_NUMBER,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SMA_SLIDE_MENU_MOVE_TO_ARCHIVE,
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
#ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
    SMA_SLIDE_MENU_USE_TEMPLATE,
#endif
    SMA_SLIDE_MENU_NO_OF_ITEMS    /* Should be the last enum */
} SlideMenuItem;

#else
typedef enum
{
    SMA_SLIDE_MENU_PLAY ,
#ifndef WAP_SUPPORT
    SMA_SLIDE_MENU_REWIND,
#endif /* ~WAP_SUPPORT */
    SMA_SLIDE_MENU_PREVIOUS,
    SMA_SLIDE_MENU_NEXT,
    SMA_SLIDE_MENU_LINK_CALL,
    SMA_SLIDE_MENU_LINK_BRA,
    SMA_SLIDE_MENU_LINK_WRITE,
#ifndef WAP_SUPPORT
    SMA_SLIDE_MENU_EXIT,
#endif /* ~WAP_SUPPORT */
    SMA_SLIDE_MENU_SAVE_TEXT_AS,
    SMA_SLIDE_MENU_SAVE_IMAGE_AS,
    SMA_SLIDE_MENU_SAVE_VIDEO_AS,
    SMA_SLIDE_MENU_SAVE_AUDIO_AS,
    SMA_SLIDE_MENU_VIEW_ATTACHMENTS,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    SMA_SLIDE_MENU_MOVE_TO_ARCHIVE,
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    SMA_SLIDE_MENU_NO_OF_ITEMS    /* Should be the last enum */
} SlideMenuItem;
#endif
/*********************************************
 * Exported function
 *********************************************/

#ifndef WAP_SUPPORT
MSF_BOOL showStatusIcon(SmaActionType action);
void deleteStatusIconHandle(void);
#endif /* ~WAP_SUPPORT */
SmaResult displayNextSlide(SmaPlayerInfo *playerInfo);
void stopSound(void);

#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
SmaResult displayCurrentSlide( SmaPlayerInfo *playerInfo);
#endif


MSF_BOOL loadImageObject(const SmaObjectInfo *object, MsfImageHandle *imgHandle,
    char *data, MSF_UINT32 size, MSF_BOOL moreData);
MSF_BOOL displayImageObject(const SmaObjectInfo *object, MsfImageHandle handle);

#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
MSF_BOOL setAudioObject(MsfSoundHandle handle);
#endif
void stopVideo(MSF_BOOL clearForm);
MSF_BOOL playAudioObject( const SmaAudioObject *object, char *data, 
    MSF_UINT32 size, MSF_BOOL moreData, MsfSoundHandle handle);
MSF_BOOL displayTextObject(SmaGadgetType gadgetType, 
    const SmaObjectInfo *object, const char *data);



SmaResult widgetActionHandler(MSF_UINT32 action, MSF_UINT32 window, 
    SmaPlayerInfo *playerInfo);
void widgetDeleteScreen(void);
SmaResult createGUI(void);
SmaResult createSlideMenu(SmaPlayerInfo *playerInfo);
SmaResult createSlideForm(void);

void smaUiInit(void);
void smaUiTerminate(void);
void getSlideDisplaySize(MsfSize *size);
void clearSlideForm(void);
SmaResult showSlideMenu( void);
int widgetGetSelected(MSF_UINT32 choiceHandle);
#ifdef WAP_SUPPORT
void smaGetSlideDisplaySize(MsfSize *size);
MsfWindowHandle getSlideFormHandle(void);
MsfImageHandle smaGetImageHandle(void);
MSF_BOOL playVideoObject(const SmaObjectInfo *object, MsfVideoHandle handle);
#endif /* WAP_SUPPORT */
#ifdef MMS_SLIM_MEM
void smaActTerminate(void);
#endif /* MMS_SLIM_MEM */
#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
MSF_BOOL setAudioObject(MsfSoundHandle handle);
#endif
MsfPosition *smaGetPosLeftTop(void);
int smaBindAndShowWindow(MsfWindowHandle windowHandle, 
	const MsfPosition *pos);
MSF_BOOL displayAlternativeTextObject( SmaObjectInfo *object );
MsfScreenHandle smaGetScreenHandle(void);
MSF_BOOL displayDrmObject(char *pipePath, const SmaObjectInfo *objectInfo);
void updateSlideFormActions(MSF_BOOL isPlaying);
SmaResult showSlideForm(void);
void displayVideoObject(const SmaObjectInfo *object, const char *filePath,
    MSF_UINT32 retFsm, MSF_UINT32 retSig);
/* User interaction */
void smaHandleEvent(MsfEventType event, MSF_UINT32 handle);
void smaHandleNotif(MsfNotificationType notif, MSF_UINT32 handle);
MSF_INT32 smaGetSelectedChoiceIndex(MSF_UINT32 choiceHandle);
MsfStringHandle smaCreateString(const char *str);

void smaUiShowWaitScreen(void);
void smaUiRemoveWaitScreen(void);

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
MSF_BOOL smaUiCreateGetTextHeightInst(const SmaObjectInfo *object, const char* text, MSF_UINT32 len);
void smaUiDeleteGetTextHeightInst(void);
MSF_BOOL smaUiGetTextHeight(void);
void smaUiSetTotalTextHeightValue(void);
MSF_UINT32 smaUiGetBytesRead(void);
#endif

#endif /* _SAUI_H */


