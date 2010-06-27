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
#include "msf_file.h"

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

#include "sma_cfg.h"
#include "sma_if.h"
#include "sma_rc.h"
#include "satypes.h"
#include "samain.h"
#include "samem.h"
#include "saui.h"
#include "sma_cfg.h"
#include "saintsig.h"
#include "saasync.h"
#include "sasbp.h"
#include "sauilnk.h"
#include "sauidia.h"
#include "sapipe.h"
#include "saslide.h"
#include "sauisig.h"
#include "samenu.h"
#include "saattach.h"
#include "salnk.h"
#include "smtr.h"

#include "widget.h"

#ifdef WAP_SUPPORT
#include "mea_def.h"    /* for MEA_SMIL_FILE_NAME */
#include "mea_cfg.h"    /* for MEA_CFG_MESSAGE_SIZE_MAXIMUM */
#include "mms_def.h"    /* for MMS_MEDIA_TYPE_STRING_SMIL */
#ifdef __UNIFIED_MSG_SUPPORT__
#include "mea_if.h"
extern MSF_BOOL getMmsMsgSubAddr(MSF_UINT8 modId,MmsMsgId msgId, char** subject, char** address,int MaxBufSize);
extern MeaAddrType meaGetAddrType(const char *addr);
extern void mms_enter_sms_editor_handler(void *p);
#endif
#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mmsadp.h"
extern void wap_send_mmi_mms_start_uc_req(kal_uint8 mode, kal_uint32 msg_id);
#endif
extern MSF_BOOL meaSmilEditorIsActive(void);
#endif

#ifndef __UNIFIED_COMPOSER_SUPPORT__
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                extern void meaDeleteMhNavMenu(void);
  #endif
#endif


/*--- Types ---*/

/******************************************************************************
 * Constants
 *****************************************************************************/
static const MsfPosition      posLeftTop     = {0, 0};


/*! Menu information */
typedef struct
{
    MsfWindowHandle menuHandle;
    MsfActionHandle actionOk;
    MsfActionHandle actionBack;
    int listItems[SMA_SLIDE_MENU_NO_OF_ITEMS];
    int listIndex;
} SmaSlideMenuView;

/* Slide form information */
typedef struct
{
    MsfWindowHandle formHandle;
#ifdef WAP_SUPPORT
    MSF_BOOL displayWaitingAnimation;
#endif /* WAP_SUPPORT */
    
    /* actions */
    MsfActionHandle actionOk;
    MsfActionHandle actionStop;
    MsfActionHandle actionMenu;

    /* gadgets */
#ifndef WAP_SUPPORT
    MsfGadgetHandle iconGadgetHandle;
#endif /* ~WAP_SUPPORT */
    MsfGadgetHandle imageGadgetHandle;  /* for both video and image */
    MsfGadgetHandle stringGadgetHandle;
    int stringGadgetInstance;
    MsfStringHandle stringHandle;
    MsfGadgetHandle altStringGadgetHandle;
    int altStringGadgetInstance;
    MsfStringHandle altStringHandle;

    MsfImageHandle imageHandle;
    MsfSoundHandle audioHandle;
    MsfVideoHandle videoHandle;

    MsfGadgetHandle currentGadget;
    SmtrLinkEntry *selectedLink;
} SmaSlideFormView;

typedef struct 
{
    const SmaObjectInfo   *objectInfo;
    MSF_UINT32      retFsm;
    MSF_UINT32      retSig;
} LoadVideoInstanceData;

/* main window */
typedef struct
{
    MsfScreenHandle screenHandle;
    MsfDeviceProperties deviceProperties;
} SmaScreenView;

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
typedef struct
{
    char* text;
    //char* textBuffer;
    char* tPos;
    MsfStringHandle stringHandle;
    int textLen;
    int totalHeight;
    int onelineHeight;
    MsfSize maxSize;
    int index;
    int strPos;
    MSF_UINT32 bytesRead;
    char* newStringStart;
    int tmpRN;
    char* rnPos;
    int lenOfRN;
    MSF_BOOL hasNormalChar;
}SmaUiGetTextHeightInstance;

static SmaUiGetTextHeightInstance *saUiGetTextHeightInst = NULL;
#endif 

/*--- Static variables ---*/
static SmaSlideMenuView smaSlideMenu;
static SmaSlideFormView smaSlideForm;
static SmaScreenView smaScreen;
#ifndef WAP_SUPPORT
static char *altAttrTextBuf;
#else
#ifdef __UNIFIED_MSG_SUPPORT__
static MsfWindowHandle smaPropView = 0;
#endif /*__UNIFIED_MSG_SUPPORT__*/
#endif /* ~WAP_SUPPORT */
static SmaMenu attachmentMenu;
static LoadVideoInstanceData loadVideoInstance;

/*--- Definitions/Declarations ---*/

#define SMA_TEXT_GADGET_PADDING (3)
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
    /* SMA_IMAGE_GADGET_PADDING should be the same with WIDGET_SLIDING_SMIL_TOP that is defined in widget.h */
    #if defined(WIDGET_LARGE_RESOLUTION) && !defined (WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING)
    #define SMA_IMAGE_GADGET_PADDING (3)
    #else
    #define SMA_IMAGE_GADGET_PADDING (1)
    #endif
#else
    #define SMA_IMAGE_GADGET_PADDING (3)
#endif /* WAP_SUPPORT */

/*--- Prototypes ---*/
static void initHandles(void);
static SmaResult handleSlideFormAction(MSF_UINT32 action, SmaPlayerInfo *playerInfo);
static SmaResult  handleSlideMenuAction(MSF_UINT32 action, SmaPlayerInfo *playerInfo);
static void initSlideMenu(void);
static MSF_BOOL addSlideMenuItem(MsfStringHandle itemStrHandle, int contextValue);
static int getSlideMenuItem(void);
static MSF_BOOL createSlideMenuActions(void);
static void initSlideForm(void);
static void deleteSlideForm(void);
#ifndef WAP_SUPPORT
static MSF_BOOL createStatusIconHandle(void);
#endif /* ~WAP_SUPPORT */
static MsfImageZoom getImageZoom(const SmaObjectInfo *object);
#ifndef __UNIFIED_MSG_SUPPORT__
static const char *getMimeType(SlsMediaType mediaType);
static MSF_BOOL getObjectInfo(MSF_UINT32 *size, MSF_UINT32 *startPos, 
	MSF_UINT32 *fileType, char **fileName, char **boundary, 
    const SmaObjectInfo *objInfo, SlsMediaObjectType objType);
#endif
static void deleteSlideMenu(void);
static MSF_BOOL createSlideFormActions(MSF_BOOL isPlaying);
static MSF_BOOL integerToMsfColor(MSF_UINT32 color, MsfColor *mColor);
static void deleteSlideFormActions(void);
static void loadVideoSuccessCallback(MsfWindowHandle handle);
static void loadVideoFailCallback(MsfWindowHandle handle);

#ifndef __UNIFIED_MSG_SUPPORT__
static void smaWriteMessage(const char *number);
#endif

/*Properties*/
#ifdef __UNIFIED_MSG_SUPPORT__
static void smaPropViewGoBack(ctk_screen_handle scrid);
static void smaDeletePropView(void);
#endif

/*!
 * \brief Initiates the UI signal handler
 *****************************************************************************/
void smaUiInit(void)
{
    initHandles();
#ifndef WAP_SUPPORT
	altAttrTextBuf = SMA_ALLOC(SLS_MAX_ALT_ATTR_LEN);	
#endif /* ~WAP_SUPPORT */
    memset(&attachmentMenu, 0x00, sizeof(SmaMenu));
    smaInitLinkMenu();
    smaInitWidgetSignalHandler();
} /* smaSbpInit */


/*!
 * \brief Terminate function for the Sma UI FSM
 *****************************************************************************/
void smaUiTerminate(void)
{
    /* Delete all GUI */
    smaTerminateLinkMenu();
#ifdef WAP_SUPPORT
    widget_disable_status_bar(WIDGET_STATUS_BAR_SOUND_IND);
#else
    deleteStatusIconHandle();
#endif /* ~WAP_SUPPORT */
    clearSlideForm();
    widgetDeleteScreen();
    smaTerminateWidgetSignalHandler();
    
    /* delete attachment menu */
    if (attachmentMenu.menuHandle != 0)
    {
        smaRemoveMenu(&attachmentMenu);
    } /* if */
   
#ifndef WAP_SUPPORT
	if (altAttrTextBuf != NULL)
	{
		SMA_FREE(altAttrTextBuf);
		altAttrTextBuf = NULL;
	}
#endif /* ~WAP_SUPPORT */

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_BA83DAAED986EA5208642908444657EB, "[TEXT HEIGHT] smaUiTerminate\n"));

    smaUiDeleteGetTextHeightInst();
    HDIa_widgetExtCloseTransitionAnimation();
#endif
} /* smaUiTerminate */

#ifdef WAP_SUPPORT
MsfWindowHandle getSlideFormHandle(void)
{
    return smaSlideForm.formHandle;
}

MsfImageHandle smaGetImageHandle(void)
{
    return HDIa_widgetExtGetImageFromGadget(smaSlideForm.imageGadgetHandle);
}
#endif /* WAP_SUPPORT */
#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
static void smaScrollNotif(void)
{
    (void)SMA_SIGNAL_SENDTO(SMA_FSM_SLIDE, SMA_SIG_EVENT_SCROLL);
}

void smaRegisterScrollNotif(void)
{
    HDIa_widgetExtFormRegisterSlidingSMILScrollNotification(getSlideFormHandle(), smaScrollNotif);
}

void smaHandleScrollEvent(MsfNotificationType event)
{
    MSF_BOOL lostFocus;
    (void)smtrRedraw(smaSlideForm.stringGadgetInstance, event, 
        &lostFocus);
}
#endif /* WIDGET_SLIDING_SMIL_VBAR && __MMI_TOUCH_SCREEN__ */

/*! \brief creates the screen. 
 *\return Result of the operation
 *****************************************************************************/
SmaResult createGUI(void)
{
    SmaResult result = SMA_RESULT_OK;

    /*init all handles*/
    initHandles();

    /* create screen */
    smaScreen.screenHandle = MSF_WIDGET_SCREEN_CREATE(MSF_MODID_SMA, FALSE, 0);
 
    if (smaScreen.screenHandle == (MsfScreenHandle)0)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_5F59129AAD58671734B7BE910DF85DD2, "SMA: unable to "
            "create screen in createGUI\n"));
        return SMA_RESULT_ERROR;
    } /* if */
    
    if (-1 == MSF_WIDGET_DEVICE_GET_PROPERTIES(&(smaScreen.deviceProperties)))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_25BB3904283F01D9889FAAB4C5BFEBDC, "SMA: unable to get "
            "device properies in createGUI\n"));
        return SMA_RESULT_ERROR;
    } /* if */

    return result;
} /* createGUI */

/*!
 * \brief Removes the slide menu
 *****************************************************************************/
static void deleteSlideMenu(void)
{
	/* release actions */
	if (smaSlideMenu.actionBack != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideMenu.actionBack);
        smaSlideMenu.actionBack  = 0;
    } /* if */
    if (smaSlideMenu.actionOk != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideMenu.actionOk);
        smaSlideMenu.actionOk  = 0;
    } /* if */

	/* remove the menu */
	if (smaSlideMenu.menuHandle != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaScreen.screenHandle, smaSlideMenu.menuHandle);
        (void)MSF_WIDGET_RELEASE(smaSlideMenu.menuHandle);
		smaSlideMenu.menuHandle  = 0;
    } /* if */

    memset(&smaSlideMenu, 0x00, sizeof(smaSlideMenu));
} /* deleteSlideMenu */


/*! \brief Deletes all handles and actions in the widget screen
 *****************************************************************************/
void widgetDeleteScreen(void)
{
    deleteSlideForm();
    deleteSlideMenu();
#ifdef __UNIFIED_MSG_SUPPORT__
    smaDeletePropView();
#endif

    if (smaScreen.screenHandle != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaScreen.screenHandle);
        smaScreen.screenHandle = 0;
    } /* if */

    memset (&smaScreen, 0x00, sizeof(smaScreen));

} /* widgetDeleteScreen */


/*! \brief Deletes all handles and actions in the slide form
 *****************************************************************************/
static void deleteSlideForm(void)
{
	clearSlideForm();

	/* release actions */
	deleteSlideFormActions();
#ifdef WAP_SUPPORT
	if (smaSlideForm.displayWaitingAnimation == TRUE)
	{
	    HDIa_widgetExtCloseTransitionAnimation();
	} /* if */
	//(void)smaDeleteUserEvent(smaSlideForm.formHandle, MsfKey_Up);
	//(void)smaDeleteUserEvent(smaSlideForm.formHandle, MsfKey_Down);
	(void)smaDeleteUserEvent(smaSlideForm.formHandle, MsfKey_Right);
	(void)smaDeleteUserEvent(smaSlideForm.formHandle, MsfKey_Left);        
#endif /* WAP_SUPPORT */
	if (smaSlideForm.actionMenu != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideForm.actionMenu);
        smaSlideForm.actionMenu = 0;
    } /* if */
	if (smaSlideForm.actionOk != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideForm.actionOk);
        smaSlideForm.actionOk = 0;
    } /* if */
	if (smaSlideForm.actionStop != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideForm.actionStop);
        smaSlideForm.actionStop = 0;
    } /* if */
	
#ifndef WAP_SUPPORT
	/* status icon */
	if (smaSlideForm.iconGadgetHandle != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, 
			smaSlideForm.iconGadgetHandle);
		(void)MSF_WIDGET_RELEASE(smaSlideForm.iconGadgetHandle);
        smaSlideForm.iconGadgetHandle = 0;
    } /* if */
#endif /* ~WAP_SUPPORT */	

	/* remove the form */
	if (smaSlideForm.formHandle != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaScreen.screenHandle, smaSlideForm.formHandle);
        (void)MSF_WIDGET_RELEASE(smaSlideForm.formHandle);
        smaSlideForm.formHandle = 0;
    } /* if */
    smaSlideForm.currentGadget = 0;
    smtrFreeSmtrLinkEntry(&smaSlideForm.selectedLink);
} /* smaDeleteSlideForm */


  /*! \brief Removes and releases all actions for the slide form
*****************************************************************************/
static void deleteSlideFormActions(void)
{
	/* remove and release actions if allreade exist */
	if (smaSlideForm.actionMenu != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, 
			smaSlideForm.actionMenu);
		(void)MSF_WIDGET_RELEASE(smaSlideForm.actionMenu);
        smaSlideForm.actionMenu = 0;
    } /* if */
	if (smaSlideForm.actionOk != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, 
			smaSlideForm.actionOk);
		(void)MSF_WIDGET_RELEASE(smaSlideForm.actionOk);
        smaSlideForm.actionOk = 0;
    } /* if */
	if (smaSlideForm.actionStop != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, 
			smaSlideForm.actionStop);
        (void)MSF_WIDGET_RELEASE(smaSlideForm.actionStop);
        smaSlideForm.actionStop = 0;
    } /* if */
} /* deleteSlideFormActions */

/*! \brief Initializes all handles for the slide form
 *****************************************************************************/
static void initSlideForm(void)
{
    memset(&smaSlideForm, 0, sizeof(SmaSlideFormView));
    /* These should not be 0 init */
    smaSlideForm.stringGadgetInstance = -1;
    smaSlideForm.altStringGadgetInstance = -1;
} /* smaInitSlideForm */

/*! \brief Finds selected index in a IMPLICIT menu
 *  \param choiceHandle Handle to a menu to find selected in.
 *  \return index of the selection.
 *****************************************************************************/
int widgetGetSelected(MSF_UINT32 choiceHandle)
{
    int index = 0;
    int numberOfElements = 0;
    
    numberOfElements = MSF_WIDGET_CHOICE_SIZE(choiceHandle);
    
    for (index = 0; index < numberOfElements; index++)
    {
        if (MSF_CHOICE_ELEMENT_SELECTED & 
            MSF_WIDGET_CHOICE_GET_ELEM_STATE(choiceHandle, index))
        {
            return index;
        } /* if */
    } /* for */

    return -1;
} /* widgetGetSelected */


/*! \brief Initiates all handles 
 *****************************************************************************/
static void initHandles(void)
{
    /* screen */
    smaScreen.screenHandle = 0;

    initSlideMenu();
    initSlideForm();
} /* initHandles */


#ifdef WAP_SUPPORT
void smaGetSlideDisplaySize(MsfSize *size)
{
	HDIa_widgetExtFormGetSmilDisplaySize(size);
    size->height = (MSF_INT16)(size->height);
}
#else /* WAP_SUPPORT */
/*! \brief Calculates and sets the region of a gadget object.
 *  \param action Type of action that has been requested
 *  \return TRUE on OK else FASLE
 *****************************************************************************/
MSF_BOOL showStatusIcon(SmaActionType action)
{
    MSF_BOOL status = TRUE;
    int size = 0;
    MsfPosition gadgetPosition = {0,0};
    MsfImageHandle imgHandle;
    MsfSize actionImageSize = {24,20};
    char *data = NULL;

    if (action == SMA_ACTION_PLAY)
    {
        data = (char *)smaPlayImage;
        size = SMA_PLAY_IMAGE_SIZE;
    } 
    else if (action == SMA_ACTION_STOP)
    {
        data = (char *)smaStopImage;
        size = SMA_STOP_IMAGE_SIZE;
    } /* if */

    /* delete old action image - if it exist */
    deleteStatusIconHandle();
    if (!createStatusIconHandle())
    {
        return FALSE;
    } /* if */
    
    //imgHandle = MSF_WIDGET_IMAGE_GET_PREDEFINED(WAP_IMAGE_WAP_LOGO, NULL);
    imgHandle = MSF_WIDGET_IMAGE_CREATE(MSF_MODID_SMA, data, 
        size, MsfBmp, FALSE, 0);

    if (imgHandle == 0)
    {
        status = FALSE;
    }
    else
    {
        if (-1 == MSF_WIDGET_IMAGE_GADGET_SET(smaSlideForm.iconGadgetHandle, 
            imgHandle, MsfImageZoom100))
        {
            status = FALSE;
        }
        else if (-1 == MSF_WIDGET_SET_SIZE(smaSlideForm.iconGadgetHandle, 
            &actionImageSize))
        {
            status = FALSE;
        } 
        else if (-1 == MSF_WIDGET_WINDOW_ADD_GADGET(smaSlideForm.formHandle, 
            smaSlideForm.iconGadgetHandle, &gadgetPosition, NULL))
        {
            status = FALSE;
        }
        
        else if (-1 == MSF_WIDGET_GADGET_SET_PROPERTIES(
            smaSlideForm.iconGadgetHandle, MSF_GADGET_PROPERTY_ALWAYSONTOP))
        {
            status = FALSE;
        } 
        else
        {
            /* time in tenth of seconds */
            MSF_TIMER_SET (MSF_MODID_SMA, SMA_ACTION_IMAGE_TIMER_ID, 
                (SMA_ACTION_IMAGE_TIME / 100));
        } /* if */
    } /* if */
    
    if (imgHandle != 0)
    {
        (void)MSF_WIDGET_RELEASE(imgHandle);
        imgHandle = 0;
    } /* if */

    return status;
} /* showStatusIcon */
#endif /* WAP_SUPPORT */

/*! \brief Updates slide form actions 
 *  \param isPlaying TRUE if currently in play mode
 *****************************************************************************/
void updateSlideFormActions(MSF_BOOL isPlaying)
{
	(void)createSlideFormActions(isPlaying);
} /* updateSlideFormActions */

/*! \brief Create and adds actions to the slide form
 *  \return TRUE on OK else FASLE
 *****************************************************************************/
static MSF_BOOL createSlideFormActions(MSF_BOOL isPlaying)
{
    MSF_BOOL ret = TRUE;
	
	/* remove and release actions if allready exist */
	deleteSlideFormActions();
	
	if (isPlaying)
    {
#ifdef WAP_SUPPORT
		HDIa_widgetExtFormDisableGadgetBorder(smaSlideForm.formHandle, KAL_TRUE);
#endif /*WAP_SUPPORT*/
        /* create action */
		smaSlideForm.actionStop = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
            SMA_GET_STR_ID(SMA_STR_ID_SLIDE_ACTION_STOP), 
            MsfStop, 0, MSF_ACTION_PROPERTY_ENABLED);

		/* add action */
		if((smaSlideForm.actionStop == 0) || 
			(0 > MSF_WIDGET_ADD_ACTION(smaSlideForm.formHandle, 
			smaSlideForm.actionStop)))
		{
			/* unable to create and add action */
			ret = FALSE;
		} /* if */
	}
    else
    {
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
        HDIa_widgetExtFormDisableGadgetBorder(smaSlideForm.formHandle, KAL_TRUE);
#endif
		/* create action */
#ifdef __UNIFIED_COMPOSER_SUPPORT__
        if(MMA_IS_UNIFIED_COMPOSER_ACTIVE())
#else
        if (meaSmilEditorIsActive())
#endif
        {
            //HDIa_widgetExtFormDisableGadgetBorder(smaSlideForm.formHandle, FALSE);
		    smaSlideForm.actionOk = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
                SMA_GET_STR_ID(SMA_STR_ID_SLIDE_ACTION_PLAY), //option
                MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);
        }
		else
		{
            //HDIa_widgetExtFormDisableGadgetBorder(smaSlideForm.formHandle, FALSE);
		    smaSlideForm.actionOk = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
                SMA_GET_STR_ID(MEA_STR_ID_OPTIONS), //option
                MsfOk, 0, MSF_ACTION_PROPERTY_ENABLED);
		}
      
        smaSlideForm.actionStop = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
            SMA_GET_STR_ID(SMA_STR_ID_SLIDE_ACTION_EXIT), 
            MsfStop, 0, MSF_ACTION_PROPERTY_ENABLED);

		smaSlideForm.actionMenu = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
			SMA_GET_STR_ID(SMA_STR_ID_EMPTY_STRING), 
			MsfMenu, 0, MSF_ACTION_PROPERTY_ENABLED);

		/* add actions */
		if((smaSlideForm.actionOk == 0) || 
			(smaSlideForm.actionStop == 0) ||
			(smaSlideForm.actionMenu == 0) ||
			(0 > MSF_WIDGET_ADD_ACTION(smaSlideForm.formHandle, smaSlideForm.actionOk)) ||
			(0 > MSF_WIDGET_ADD_ACTION(smaSlideForm.formHandle, smaSlideForm.actionStop)) ||
			(0 > MSF_WIDGET_ADD_ACTION(smaSlideForm.formHandle, smaSlideForm.actionMenu)))
		{
			/* unable to create and add action */
			ret = FALSE;	
		} /* if */
    } /* if */
    
    
    if (ret == FALSE)
	{
		/* something went wrong */
		deleteSlideFormActions();
	} /* if */
	
    return ret;
} /* createSlideFormActions */



/*! \brief Creates a form
 *  \return TRUE on OK else FASLE
 *****************************************************************************/
SmaResult createSlideForm(void)
{
    SmaResult ret = SMA_RESULT_OK;
    MsfPosition formPosition = {0,0};
	SmaPlayerInfo *playerInfo;
    MsfStyleHandle style;	
    MsfColor bgColor = {255, 255, 255};
    playerInfo = getPlayerInfo();
    
    (void)integerToMsfColor(playerInfo->rootBgColor, &bgColor);

    if (0 == (style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, NULL, 
        &bgColor, NULL, NULL, NULL, NULL, NULL)))
    {
        return SMA_RESULT_ERROR;
    }

    smaSlideForm.formHandle = MSF_WIDGET_FORM_CREATE(MSF_MODID_SMA, 
        NULL, 0, style);
    (void)MSF_WIDGET_RELEASE(style);
    
    if (smaSlideForm.formHandle == 0)
    {
        ret = SMA_RESULT_ERROR;
    }
    else if (!createSlideFormActions(playerInfo->isPlaying))
    {
        ret = SMA_RESULT_ERROR;
    }
    else if (-1 == MSF_WIDGET_SCREEN_ADD_WINDOW (smaScreen.screenHandle, 
        smaSlideForm.formHandle, &formPosition, 0, 0))
    {
        ret = SMA_RESULT_ERROR;
    }
    else if (smaRegisterUserEvent(smaSlideForm.formHandle, MsfKey_Right, NULL, SMA_FSM_SLIDE, 
        SMA_SIG_EVENT_KEY_RIGHT) < 0)
    {
        return SMA_RESULT_ERROR;
    }
    /* Handle the event for the "left" key */
    else if (smaRegisterUserEvent(smaSlideForm.formHandle, MsfKey_Left, NULL, SMA_FSM_SLIDE, 
        SMA_SIG_EVENT_KEY_LEFT) < 0)
    {
        return SMA_RESULT_ERROR;
    }
	else
	{
		(void)MSF_WIDGET_SET_IN_FOCUS(smaScreen.screenHandle, TRUE);
		(void)MSF_WIDGET_SET_IN_FOCUS(smaSlideForm.formHandle, TRUE);
	} /* if */

#ifndef __UNIFIED_COMPOSER_SUPPORT__
    HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
    smaSlideForm.displayWaitingAnimation = TRUE;
#endif

    MSF_WIDGET_WINDOW_SET_PROPERTIES(smaSlideForm.formHandle,
		MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY | MSF_WINDOW_PROPERTY_TITLE);

	if (ret != SMA_RESULT_OK)
	{
		/* Error handling */
		if(smaSlideForm.formHandle != 0)
		{
			(void)MSF_WIDGET_RELEASE(smaSlideForm.formHandle);
		} /* if */
		
	} /* if */

    return  ret;
} /* createSlideForm */


/*! \brief Converts an integer (hex RRGGBB) representing a color 
 * (rgb 8-bit each) into a MsfColor.
 *
 * \param color The color to convert into a MsfColor.
 * \param mColor destination color
 *
 * \return TRUE if color is used, else FALSE
 *****************************************************************************/
static MSF_BOOL integerToMsfColor(MSF_UINT32 color, MsfColor *mColor)
{
	if (color == SLS_COLOR_NOT_USED)
	{
		return FALSE;
	} /* if */
	mColor->r = (color >> 16) & 0xff;
	mColor->g = (color >>  8) & 0xff;
	mColor->b = (color >>  0) & 0xff;
	return TRUE;
} /* inegerToMsfColor */



#ifndef WAP_SUPPORT
/*! \brief Creates gadget handle for Status Icons
 *  \return TRUE on OK else FASLE
 *****************************************************************************/
static MSF_BOOL createStatusIconHandle(void)
{
    MsfImageHandle tmpHandle;
    MSF_BOOL ret = TRUE;
    MsfSize  zeroSize = {0,0};

	/* Creates an empty image, just to be able to create an image gadget. */
	tmpHandle = MSF_WIDGET_IMAGE_CREATE_EMPTY(MSF_MODID_SMA, 
		&zeroSize, 0);
	
	if(tmpHandle == (MsfImageHandle)0)
	{
		MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_FD01802BF4F1AA89FE420C7A8D2DE392, "SMA: unable to "
			"create empty image in createSlideForm\n"));
		ret = FALSE;
	}
	else
	{
		smaSlideForm.iconGadgetHandle = MSF_WIDGET_IMAGE_GADGET_CREATE(
			MSF_MODID_SMA, tmpHandle, &zeroSize, MsfImageZoom100, 0, 0);
	} /* if */
	
	if (tmpHandle != 0)
	{
		(void)MSF_WIDGET_RELEASE(tmpHandle);
		tmpHandle= 0;
	} /* if */

	if (smaSlideForm.iconGadgetHandle == 0)
	{
		/* unable to create handles */
		ret = FALSE;
	} /* if */

    return ret;
} /* createStatusIconHandle */
#endif /* ~WAP_SUPPORT */



/*! \brief Create and adds actions to the slide menu
 *  \return TRUE on OK else FASLE
 *****************************************************************************/
static MSF_BOOL createSlideMenuActions(void)
{
    MSF_BOOL ret = TRUE;

 	smaSlideMenu.actionBack = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
        SMA_GET_STR_ID(SMA_STR_ID_SLIDE_MENU_ACTION_BACK), 
        MsfStop, 0, MSF_ACTION_PROPERTY_ENABLED);

    if (smaSlideMenu.actionBack == 0)
    {
        /* unable to create action */
        ret = FALSE;
    }
    else if (-1 == MSF_WIDGET_ADD_ACTION(smaSlideMenu.menuHandle, 
        smaSlideMenu.actionBack))
    {
        /* unable to add action */
        ret = FALSE;
    } /* if */

    return ret;
} /* createSlideMenuActions */


/*! \brief creates the smil menu
 *  \return Result of the operation
 *****************************************************************************/
#ifdef __UNIFIED_MSG_SUPPORT__
SmaResult createSlideMenu(SmaPlayerInfo *playerInfo)
{
    MsfPosition   menuPositionTestM = {0,0};
    SmaSlideInfo *slide = getSlideInfo(playerInfo->currentSlide, playerInfo);
    MmsFileType msgType = (MmsFileType)playerInfo->fileType;
    char *subject = NULL, *address = NULL;
    MeaAddrType addrType = MEA_ADDR_TYPE_NONE;

    getMmsMsgSubAddr(MSF_MODID_SMA, playerInfo->msgId, &subject, &address, 250);
    addrType = meaGetAddrType(address);

    /* if menu allready exist - delete it */
    deleteSlideMenu();
	
    /* create ok-action */
    smaSlideMenu.actionOk = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, SMA_GET_STR_ID(SMA_STR_ID_OK), 
        MsfSelect, 0, MSF_ACTION_PROPERTY_ENABLED);
  
    if (smaSlideMenu.actionOk == 0)
    {
        ASSERT(0);
    }

	/* create the slide menu */
    smaSlideMenu.menuHandle  = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_SMA, 
        smaSlideMenu.actionOk, NULL, MSF_CHOICE_ELEMENT_STRING_1, MSF_WINDOW_PROPERTY_TITLE, 0);
    if (smaSlideMenu.menuHandle  == 0)
    {
        ASSERT(0);
    }
    
    if (!createSlideMenuActions())
    {
        ASSERT(0);
    }

    if (-1 == MSF_WIDGET_SET_TITLE (smaSlideMenu.menuHandle, SMA_GET_STR_ID(MEA_STR_ID_OPTIONS)))
    {
        ASSERT(0);
    }

    /*---------------- Add menu items ---------------*/
    /* PLAY */
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
    if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_SLIDE_ACTION_PLAY), SMA_SLIDE_MENU_PLAY))
#else
    if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_VIEW), SMA_SLIDE_MENU_PLAY))
#endif
    {
        ASSERT(0);
    }
#ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
    if (playerInfo->folder == MMS_USRDEF_TEMPLATES)
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_NEW_MSG_FROM_TEMPL), SMA_SLIDE_MENU_USE_TEMPLATE))
        {
            return SMA_RESULT_ERROR;
        }
    }
#endif

    /* SEND */
    if ((msgType == MMS_SUFFIX_SEND_REQ) && 
        (MMS_TEMPLATES != playerInfo->folder) && 
        (MMS_SENT != playerInfo->folder)
#ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
        && (MMS_USRDEF_TEMPLATES != playerInfo->folder) 
#endif
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    && (MMS_ARCHIVE!= playerInfo->folder)
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    )
    {
       if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_SEND), SMA_SLIDE_MENU_SEND))
       {
           ASSERT(0);
       }
    }
#ifndef __UNIFIED_MESSAGE_MMS_REPLY_BY_SMS_FIRST__    
    /* REPLY */
    if ((msgType == MMS_SUFFIX_MSG) && (addrType != MEA_ADDR_TYPE_NONE))
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_REPLY), SMA_SLIDE_MENU_REPLY))
        {
            ASSERT(0);
        }
    }
#endif

    /* REPLY BY SMS*/
    if ((msgType == MMS_SUFFIX_MSG) && (addrType == MEA_ADDR_TYPE_PLMN))
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_REPLY_SMS), SMA_SLIDE_MENU_REPLY_SMS))
        {
            ASSERT(0);
        }
    }

#ifdef __UNIFIED_MESSAGE_MMS_REPLY_BY_SMS_FIRST__   
    /* REPLY */
    if ((msgType == MMS_SUFFIX_MSG) && (addrType != MEA_ADDR_TYPE_NONE))
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_REPLY), SMA_SLIDE_MENU_REPLY))
        {
            ASSERT(0);
        }
    }
#endif

    /* REPLY_ALL - should only be visible when several recipients exists: CR to be written */
    if ((msgType == MMS_SUFFIX_MSG) && (addrType != MEA_ADDR_TYPE_NONE))
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_REPLY_TO_ALL), SMA_SLIDE_MENU_REPLY_ALL))
        {
            ASSERT(0);
        }
    }

    /* FORWARD */
    if (((msgType == MMS_SUFFIX_MSG) || (MMS_SENT == playerInfo->folder)
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    || ((MMS_ARCHIVE == playerInfo->folder) && (msgType != MMS_SUFFIX_DELIVERYREPORT))
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    )
    && (!playerInfo->forwardLock)
    )
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_FORWARD), SMA_SLIDE_MENU_FORWARD))
        {
            ASSERT(0);
        }
    }
    
    if (MMS_TEMPLATES != playerInfo->folder)
    {
    /* EDIT */
#ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
        if (MMS_USRDEF_TEMPLATES != playerInfo->folder)
        {
#endif
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_EDIT), SMA_SLIDE_MENU_EDIT))
        {
            ASSERT(0);
        }
#ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
        }
#endif

    /* DELETE */
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_DELETE), SMA_SLIDE_MENU_DELETE))
        {
            ASSERT(0);
        }

    /* DELETE ALL */
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_DELETE_ALL), SMA_SLIDE_MENU_DELETE_ALL))
        {
            ASSERT(0);
        }
        /* MOVE TO ARCHIVE */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if( (playerInfo->folder == MMS_SENT || playerInfo->folder == MMS_INBOX ) && msgType == MMS_SUFFIX_MSG)
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_MOVE_TO_ARCHIVE), SMA_SLIDE_MENU_MOVE_TO_ARCHIVE))
        {
            ASSERT(0);
        }
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

        /* PROPERTIES */
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_PROPERTIES), SMA_SLIDE_MENU_PROPERTIES))
        {
            ASSERT(0);
        }
    }
        
    /* SAVE OBJECT */
    {
        SlsUnrefItemList *unref = playerInfo->unrefList;
        MSF_UINT32 attachmentNo = 0;
        SmaObjectInfo *mo = &slide->object;
        for(; unref != NULL; unref = unref->next)
        {
            if(msf_cmmn_strcmp_nc(unref->contentType, MMS_MEDIA_TYPE_STRING_SMIL) != 0)
            {
                attachmentNo++;
            }
        }

        for(; mo != NULL; mo = mo->next)
        {
            if(mo->type != SLS_OBJECT_TYPE_NONE)
            {
                break;
            }
        }
        
        if(mo || attachmentNo > 0)
        {
        
            if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_OBJECT), SMA_SLIDE_MENU_SAVE_OBJECT))
            {
                ASSERT(0);
            }
        }
    }
    
    /* USE NUMBER*/
    if(MMS_TEMPLATES != playerInfo->folder)
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(MEA_STR_ID_USE_DETAILS), SMA_SLIDE_MENU_USE_NUMBER))
        {
            ASSERT(0);
        }
    }
    
    if (-1 == MSF_WIDGET_SCREEN_ADD_WINDOW (smaScreen.screenHandle, smaSlideMenu.menuHandle , &menuPositionTestM, 0, 0))
    {
        ASSERT(0);
    }
    
    if (SMA_RESULT_OK != showSlideMenu())
    {
        ASSERT(0);
    }
    
    SMA_FREE(subject);
    SMA_FREE(address);
    return SMA_RESULT_OK;
} /* createSlideMenu */

#else
SmaResult createSlideMenu(SmaPlayerInfo *playerInfo)
{
    MsfPosition   menuPositionTestM = {0,0};
    SmaResult result = SMA_RESULT_OK;
    SmaSlideInfo *slide;
	char *linkStr = NULL;
    SlideMenuItem item = SMA_SLIDE_MENU_NO_OF_ITEMS;
    MsfStringHandle strHandle;
    
    /* if menu allready exist - delete it */
	deleteSlideMenu();
    
    slide = getSlideInfo(playerInfo->currentSlide, playerInfo);
	
    /* create ok-action */
    smaSlideMenu.actionOk = MSF_WIDGET_ACTION_CREATE(MSF_MODID_SMA, 
    SMA_GET_STR_ID(SMA_STR_ID_OK), 
    MsfSelect, 0, MSF_ACTION_PROPERTY_ENABLED);
  
    if (smaSlideMenu.actionOk == 0)
    {
        return SMA_RESULT_ERROR;
    }

    /* create the slide menu */
    smaSlideMenu.menuHandle  = MSF_WIDGET_MENU_APP_CREATE(MSF_MODID_SMA, 
        smaSlideMenu.actionOk, NULL, MSF_CHOICE_ELEMENT_STRING_1, 
        MSF_WINDOW_PROPERTY_TITLE, 0);

    if (smaSlideMenu.menuHandle  == 0)
    {
        return SMA_RESULT_ERROR;
    } 
    else if (!createSlideMenuActions())
    {
        return SMA_RESULT_ERROR;
    }

    if (-1 == MSF_WIDGET_SET_TITLE (smaSlideMenu.menuHandle, SMA_GET_STR_ID(MEA_STR_ID_OPTIONS)))
    {
        return SMA_RESULT_ERROR;
    }

    /* Add menu items */

    /* Links */	
    if (smaSlideForm.selectedLink) 
    {
        /* needed to convert handle to string */
        int strHandleLength;
        MsfStringHandle localStrHandle;
        char* str = NULL;

        switch (smaSlideForm.selectedLink->scheme) 
        {
        case SMTR_SCHEME_HTTP:
        case SMTR_SCHEME_HTTPS:
        case SMTR_SCHEME_WWW:
            if (!isInCall() || (isInCall() && GetWapCallPresent()))
            {
                localStrHandle = SMA_GET_STR_ID(SMA_STR_ID_UI_OPEN);
                strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (localStrHandle, TRUE, MsfUtf8);
                str = SMA_ALLOC(strHandleLength+1);
                MSF_WIDGET_STRING_GET_DATA (localStrHandle, str, MsfUtf8);
                linkStr = msf_cmmn_str3cat(MSF_MODID_SMA, str, " ", smaSlideForm.selectedLink->link);
                item = SMA_SLIDE_MENU_LINK_BRA;
            }
            break;
        case SMTR_SCHEME_PHONE:
            if (!isInCall() || (isInCall() && GetWapCallPresent()))
            {
                localStrHandle = SMA_GET_STR_ID(SMA_STR_ID_UI_CALL);
                strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (localStrHandle, TRUE, MsfUtf8);
                str = SMA_ALLOC(strHandleLength+1);
                MSF_WIDGET_STRING_GET_DATA (localStrHandle, str, MsfUtf8);
                linkStr = msf_cmmn_strcat(MSF_MODID_SMA, str, smaSlideForm.selectedLink->link);
                item = SMA_SLIDE_MENU_LINK_CALL;
            }
            break;
        case SMTR_SCHEME_MAIL:
            localStrHandle = SMA_GET_STR_ID(MEA_STR_ID_WRITE_MESSAGE);
            strHandleLength = MSF_WIDGET_STRING_GET_LENGTH (localStrHandle, TRUE, MsfUtf8);
            str = SMA_ALLOC(strHandleLength+1);
            MSF_WIDGET_STRING_GET_DATA (localStrHandle, str, MsfUtf8);
            linkStr = str;
            str = NULL;
            item = SMA_SLIDE_MENU_LINK_WRITE;
            break;
        default:
            linkStr = NULL;
            item = SMA_SLIDE_MENU_NO_OF_ITEMS;
            break;
        }

        if (str!=NULL)
        {
            SMA_FREE(str);
        }

        if (item < SMA_SLIDE_MENU_NO_OF_ITEMS)
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, 
                linkStr, MsfUtf8, 
                strlen(linkStr) + 1, 0)))
            {
                SMA_FREE(linkStr);
                return SMA_RESULT_ERROR;
            }
            SMA_FREE(linkStr);
            if (!addSlideMenuItem(strHandle, item))
            {
                (void)MSF_WIDGET_RELEASE(strHandle);
                return SMA_RESULT_ERROR;
            } /* if */
            (void)MSF_WIDGET_RELEASE(strHandle);        
        }
    }

    /* PLAY */
    if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_PLAY),
        SMA_SLIDE_MENU_PLAY))
    {
        return SMA_RESULT_ERROR;
    } /* if */

    /* PREVIOUS */
    if (playerInfo->currentSlide > SMA_FIRST_SLIDE)
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_PREVIOUS), SMA_SLIDE_MENU_PREVIOUS))
        {
            return SMA_RESULT_ERROR;
        }
    }

    /* NEXT */
    if (playerInfo->currentSlide<(playerInfo->noOfSlides-1))
    {
        if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_NEXT), SMA_SLIDE_MENU_NEXT))
        {
            return SMA_RESULT_ERROR;
        }
    }

    if (!meaSmilEditorIsActive())
    {
        /* SAVE Text */
        if (0)//(checkObjectType(SLS_OBJECT_TYPE_TEXT, slide))
        {
            /* Item exists, show menu item for save text */
            if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_TEXT), SMA_SLIDE_MENU_SAVE_TEXT_AS))
            {
                return SMA_RESULT_ERROR;
            }
        }

        /* SAVE IMAGE AS */
        if(checkObjectType(SLS_OBJECT_TYPE_IMAGE, slide))
        {
            /* Item exists, show menu item for save image */
            if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_IMAGE), SMA_SLIDE_MENU_SAVE_IMAGE_AS))
            {
                return SMA_RESULT_ERROR;
            }
        }

	/* SAVE VIDEO AS */
        if(checkObjectType(SLS_OBJECT_TYPE_VIDEO, slide))
        {
            /* Item exists, show menu item for save image */
            if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_VIDEO), SMA_SLIDE_MENU_SAVE_VIDEO_AS))
            {
                return SMA_RESULT_ERROR;
            }
        }

        /* SAVE AUDIO AS */
        if(checkObjectType(SLS_OBJECT_TYPE_AUDIO, slide))
        {
            /* Item exists, show menu item for save audio */
            if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_MENU_SAVE_AUDIO), SMA_SLIDE_MENU_SAVE_AUDIO_AS))
            {
                return SMA_RESULT_ERROR;
            }
        }
    }
    
    /* VIEW ATTACHMENT */
    if (!meaSmilEditorIsActive() && playerInfo->unrefList != NULL)
    {
        SlsUnrefItemList *unref = playerInfo->unrefList;
        for(; unref != NULL && unref->contentType != NULL && msf_cmmn_strcmp_nc(unref->contentType, MMS_MEDIA_TYPE_STRING_SMIL) == 0; unref = unref->next);
        
        if(unref)
        {
            /* there is attachment - show attachement menu item */
            if (!addSlideMenuItem(SMA_GET_STR_ID(SMA_STR_ID_ATTACHMENTS), SMA_SLIDE_MENU_VIEW_ATTACHMENTS))
            {
                return SMA_RESULT_ERROR;
            }
        }
    }

    if (-1 == MSF_WIDGET_SCREEN_ADD_WINDOW (smaScreen.screenHandle, smaSlideMenu.menuHandle , &menuPositionTestM, 0, 0))
    {
        result = SMA_RESULT_ERROR;
    }
    
    if (SMA_RESULT_OK != showSlideMenu())
    {
        result = SMA_RESULT_ERROR;
    }
    return result;
} /* createSlideMenu */

#endif
#ifndef WAP_SUPPORT
/*! \brief delete all action handles
 *****************************************************************************/                   
void deleteStatusIconHandle(void)
{
    if (smaSlideForm.iconGadgetHandle != 0)
    {
        (void)MSF_WIDGET_REMOVE((MSF_UINT32)smaSlideForm.formHandle, 
            (MSF_UINT32)smaSlideForm.iconGadgetHandle);
		(void)MSF_WIDGET_RELEASE(smaSlideForm.iconGadgetHandle);
        smaSlideForm.iconGadgetHandle = 0;
    } /* if */
} /* deleteStatusIconHandle */
#endif /* ~WAP_SUPPORT */	

/*! \brief Removes old text, image and audio widgets
 *  \return TRUE on OK else FALSE
 *****************************************************************************/
void clearSlideForm(void)
{   
	/* nothing to do if remove fails. */

    stopSound();
#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
    stopVideo(TRUE);
#endif
#ifdef WIDGET_SLIDING_SMIL_SUPPORT
	HDIa_widgetExtFormClearSlidingSMIL(smaSlideForm.formHandle);
	/* 
	 * 1. Image(Up) & Text(Down) - Focus on text
	 * 2. Stop -> Option -> Play
	 * 3. ClearSlideForm() - Delete user events in MSF_WIDGET_REMOVE
	 * 4. Add image gadget and focus to it (text gadget not exists, it does not send MsfNotifyLostFocus)
	 * 5. Add text gadget (image gadget is still focused)
	 */
#endif

	/* release and remove handles */
    if (smaSlideForm.imageHandle != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideForm.imageHandle);
        smaSlideForm.imageHandle = 0;
    } /* if */

#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
    if (smaSlideForm.audioHandle != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideForm.audioHandle);
        smaSlideForm.audioHandle = 0;
    }

    if (smaSlideForm.videoHandle != 0)
    {
        (void)MSF_WIDGET_RELEASE(smaSlideForm.videoHandle);
        smaSlideForm.videoHandle = 0;
    }
#endif

    if (smaSlideForm.stringGadgetHandle != 0)
    {
        /* delete focus events */
        smaDeleteNotification(smaSlideForm.stringGadgetHandle);
        smaHandleNotif(MsfNotifyLostFocus, smaSlideForm.stringGadgetHandle);
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, smaSlideForm.stringGadgetHandle);

        /* The response is voided because the only error is when the instance is not valid and then we still cannot do anything */
        (void)smtrDeleteTextBox(smaSlideForm.stringGadgetInstance);
        smaSlideForm.stringGadgetHandle = 0;
        smaSlideForm.stringGadgetInstance = -1;
        if (smaSlideForm.stringHandle != 0) 
        {
            HDIa_widgetExtStringClearCacheGetVisible(smaSlideForm.stringHandle);
            (void)MSF_WIDGET_RELEASE(smaSlideForm.stringHandle);            
        }
    }
	
    if (smaSlideForm.altStringGadgetHandle != 0)
    {
        smaDeleteNotification(smaSlideForm.altStringGadgetHandle);
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, smaSlideForm.altStringGadgetHandle);
        /* The response is voided because the only error is when the instance is not valid and then we still cannot do anything */
        (void)smtrDeleteTextBox(smaSlideForm.stringGadgetInstance);
		smaSlideForm.altStringGadgetHandle = 0;
        smaSlideForm.altStringGadgetInstance = -1;
        if (smaSlideForm.altStringHandle != 0) 
        {
            (void)MSF_WIDGET_RELEASE(smaSlideForm.altStringHandle);            
        }
    } /* if */
    
    if (smaSlideForm.imageGadgetHandle != 0)
    {
        smaDeleteNotification(smaSlideForm.imageGadgetHandle);
        (void)MSF_WIDGET_REMOVE(smaSlideForm.formHandle, smaSlideForm.imageGadgetHandle);
        (void)MSF_WIDGET_RELEASE(smaSlideForm.imageGadgetHandle);
        smaSlideForm.imageGadgetHandle = 0;
    }

    if(smaSlideForm.selectedLink)
        smtrFreeSmtrLinkEntry(&smaSlideForm.selectedLink);
} /* clearSlideForm */

/*! \brief Handles a video object.
 * \param object Object information
 * \param handle The video handle
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL playVideoObject(const SmaObjectInfo *object, MsfVideoHandle handle)
{
    MsfSize videoSize = {0,0};
    MsfSize gadgetSize = {0,0};
    MsfPosition gadgetPosition = {0,0}; 
    MsfImageZoom imageZoom;
    MsfStyleHandle style;
    MsfColor color = {-1, -1, -1};
    MSF_BOOL   status = TRUE;
    
    if (handle == 0)
    {
        return FALSE;
    }

    smaSlideForm.videoHandle = handle;
    (void)integerToMsfColor(object->info.image.bgColor, &color);
    style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, NULL, &color, NULL, NULL, NULL, NULL, NULL);
    
    setGadgetRegion(&gadgetSize, &gadgetPosition, object);
    (void)MSF_WIDGET_GET_SIZE(handle, &videoSize);

    /* Set gadget position & size */
    if (0 == videoSize.height || 0 == videoSize.width) 
    {
        imageZoom = MsfImageZoomAutofit;
    }
    else if (videoSize.height > gadgetSize.height || videoSize.width > gadgetSize.width)  /* Check if the video can fit horizontally on the display  */
    {
        MSF_UINT16 old_width = gadgetSize.width;
        MSF_UINT16 old_height = gadgetSize.height;
        imageZoom = MsfImageZoomAutofit;

        gadgetSize.width = (gadgetSize.width > videoSize.width) ? videoSize.width : gadgetSize.width;
        gadgetSize.height = (gadgetSize.height > videoSize.height) ? videoSize.height : gadgetSize.height;
        
        if ((int)gadgetSize.height * videoSize.width > (int)gadgetSize.width * videoSize.height)  /* video is wide / short */
        {
            gadgetSize.height = (MSF_INT16) (((int)gadgetSize.width * videoSize.height) / videoSize.width);
        }
        else  /* video is narrow / long */
        {
            gadgetSize.width = (MSF_INT16) (((int)gadgetSize.height * videoSize.width) / videoSize.height);
        }
        
        if (gadgetSize.width < old_width)
        {
            gadgetPosition.x = (MSF_UINT16)(gadgetPosition.x + ((old_width - gadgetSize.width )>>1));  /* centered */
        }

        if (gadgetSize.height < old_height)
        {
            gadgetPosition.y = (MSF_UINT16)(gadgetPosition.y + ((old_height - gadgetSize.height )>>1));
        }
    }
    else if (MsfImageZoomAutofit != (imageZoom = getImageZoom(object)))
    {
        /* Image position */
        gadgetPosition.x = (MSF_INT16)(gadgetPosition.x + ((gadgetSize.width - videoSize.width)>>1));
        gadgetPosition.y = (MSF_INT16)(gadgetPosition.y + ((gadgetSize.height - videoSize.height)>>1));
        memcpy(&gadgetSize, &videoSize, sizeof(MsfSize));
    }

    /* Center gadget */
    if (gadgetPosition.y == 0)
    {
        gadgetPosition.y = (MSF_INT16)(gadgetPosition.y + SMA_IMAGE_GADGET_PADDING);
    }

    if (gadgetSize.height == 0 || gadgetSize.width == 0)  /* size is 0 so nothing will be shown. */
    {
        return TRUE;
    }
    
    /* Create gadget handle if it does not exist */
    if (!smaSlideForm.imageGadgetHandle)
    {
        smaSlideForm.imageGadgetHandle = MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_SMA, handle, &gadgetSize, imageZoom, 0, style);
        if (smaSlideForm.imageGadgetHandle == 0) 
        {
            (void)MSF_WIDGET_RELEASE(style);
            return FALSE;
        }
    }
    else
    {
        if (-1 == MSF_WIDGET_IMAGE_GADGET_SET(smaSlideForm.imageGadgetHandle, handle, imageZoom))
        {
            (void)MSF_WIDGET_RELEASE(style);
            return FALSE;
        }
    }

    (void)MSF_WIDGET_RELEASE(style);

    if (-1 == MSF_WIDGET_SET_SIZE(smaSlideForm.imageGadgetHandle, &gadgetSize))
    {
        status = FALSE;
    } 
    else if (-1 == MSF_WIDGET_GADGET_SET_PROPERTIES (smaSlideForm.imageGadgetHandle, MSF_GADGET_PROPERTY_FOCUS))
    {
        status = FALSE;
    }
    else if (-1 == MSF_WIDGET_WINDOW_ADD_GADGET(smaSlideForm.formHandle, smaSlideForm.imageGadgetHandle, &gadgetPosition, NULL))
    {
        status = FALSE;
    }

    if (getPlayerInfo()->isPlaying)
    {
        (void)MSF_WIDGET_EXT_PLAY_VIDEO(handle);
    }
    else
    {
        MSF_WIDGET_EXT_DISABLE_VIDEO_PLAY(handle);
    }

    return status;
}

/*!
 * \brief Stop playing a video clip
 *****************************************************************************/
void stopVideo(MSF_BOOL clearForm)
{
    if (smaSlideForm.videoHandle != 0)
    {
        MSF_WIDGET_EXT_STOP_VIDEO(smaSlideForm.videoHandle);

        if(clearForm == TRUE)
        {
            (void)MSF_WIDGET_RELEASE(smaSlideForm.videoHandle);
            smaSlideForm.videoHandle = 0;
        }
        else
    	{
    	    MSF_WIDGET_EXT_DISABLE_VIDEO_PLAY(smaSlideForm.videoHandle);
    	}
    }
}

/*! \brief Handles a audio object.
 * \param object Object information
 * \param data Audio data
 * \param size of data
 * \param moreData TRUE if more data for this part, else FALSE
 * \param handle The handle of the sound object, or 0 if the data is provided 
 *               as a buffer.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
MSF_BOOL setAudioObject(MsfSoundHandle handle)
{
    if(!handle)
        return FALSE;

    smaSlideForm.audioHandle = handle;
    return TRUE;
}
#endif

int playAudioObjectCallback(void)
{
    HDIa_widgetExtFromSetAudioCallBack(smaSlideForm.formHandle, NULL);
    return HDIa_widgetExtSoundPlayOnWindow(smaSlideForm.audioHandle, smaSlideForm.formHandle);
}

MSF_BOOL playAudioObject(const SmaAudioObject *object, char *data, 
    MSF_UINT32 size, MSF_BOOL moreData, MsfSoundHandle handle)
{
    MSF_BOOL status = TRUE;

    if (object == NULL)
    {
        /* no data */
        return TRUE;
    } /* if */

    if (isKnownType(object->type, SLS_OBJECT_TYPE_AUDIO))
    {
        if (smaSlideForm.audioHandle == 0)
        {
            if (NULL != data)
            {
                smaSlideForm.audioHandle = MSF_WIDGET_SOUND_CREATE(MSF_MODID_SMA,
                    data, (MsfSoundFormat)convertSmaToMsfMediaTypes(object->type),
                    (int)size, moreData);
                if (smaSlideForm.audioHandle == 0)
                {
                    status = FALSE;
                } /* if */
            }
            else
            {
                smaSlideForm.audioHandle = handle;
                status = TRUE;
            }
        }
        else
        {
            if (-1 == MSF_WIDGET_SOUND_NEXT_PART(smaSlideForm.audioHandle, 
                data, (int)size, moreData))
            {
                status = FALSE;
            } /* if */
        } /* if */
        
        if (status == TRUE && moreData == FALSE && 
            smaSlideForm.audioHandle != 0 && getPlayerInfo()->isPlaying)
        {
            HDIa_widgetExtFromSetAudioCallBack(smaSlideForm.formHandle, playAudioObjectCallback);
            widget_enable_status_bar(WIDGET_STATUS_BAR_SOUND_IND);
        } /* if */
    } /* if */

    return status;
} /* playAudioObject */



/*! \brief Handles an image object.
 * \param object Object information
 * \param imgHandle The image handle is only returned when moreData is FALSE,
 *      i.e. when there is no more data and the operation is complete. 
 *      When the image handle is returned, the caller is responsible to 
 *      release it.
 * \param data Image data, or NULL if the image handle is provided.
 * \param size of data
 * \param moreData TRUE if more data for this part, else FALSE
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL loadImageObject(const SmaObjectInfo *object, MsfImageHandle *imgHandle,
    char *data, MSF_UINT32 size, MSF_BOOL moreData)
{
    
	if (object == NULL)
    {
        return 0;
    } /* if */
    
    if (!isKnownType(object->info.image.type, SLS_OBJECT_TYPE_IMAGE) || data == NULL)
    {
        /* unknown image format or no data supplied */
        /* clean up */
        if (smaSlideForm.imageGadgetHandle != 0)
        {
            (void)MSF_WIDGET_RELEASE(smaSlideForm.imageHandle);
            smaSlideForm.imageHandle = 0;
        } /* if */
        *imgHandle = 0;
        return 0;
    } /* if */	
    else
    {
        if (smaSlideForm.imageHandle == 0)
        {
            /* no current image handle, create a new one */
                smaSlideForm.imageHandle = MSF_WIDGET_IMAGE_CREATE(MSF_MODID_SMA, 
                    data, (int)size, 
                    (MsfImageFormat)convertSmaToMsfMediaTypes(object->info.image.type), 
                    moreData, 0);
        
            if (smaSlideForm.imageHandle == 0)
            {
                /* failed to create image handle */
                *imgHandle = 0;
                    return FALSE;
            } /* if */
        }
        else
        {
            /* Image handle already exists */
            if (MSF_WIDGET_IMAGE_NEXT_PART(smaSlideForm.imageHandle, data, 
                (int)size, moreData) == -1)
            {
                /* failed to create the image */
                (void)MSF_WIDGET_RELEASE(smaSlideForm.imageHandle);
                smaSlideForm.imageHandle = 0;
                *imgHandle = 0;
                return FALSE;
            } /* if */
        } /* if */
    } /* if */
    
    *imgHandle = 0;
    if (moreData == FALSE)
    {
        *imgHandle = smaSlideForm.imageHandle;
        smaSlideForm.imageHandle = 0;
    } /* if */
    return TRUE;
} /* loadImageObject */

/*! \brief Handles an image object.
 * \param object Object information
 * \param data Image data, or NULL if the image handle is provided.
 * \param The image handle if the the image already exists, or 0 if the image
 *        handle must be created.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL displayImageObject(const SmaObjectInfo *object, MsfImageHandle handle)
{
    MsfSize     gadgetSize = {0,0};
    MsfPosition gadgetPosition = {0,0}; 
    MSF_BOOL   status = TRUE;
	MsfSize		imgSize = {0,0};
    MsfImageZoom imageZoom;
    MsfStyleHandle style;
    MsfColor color = {-1, -1, -1};
    
    if (handle == 0)
    {
        return FALSE;
    } /* if */

#ifdef WIDGET_PRECACHE_IMAGE
    HDIa_widgetExtEnablePreCacheImage(handle);
#endif /* WIDGET_PRECACHE_IMAGE */
#ifdef WIDGET_ANIMATION_ON_SMIL_PLAYING
    if (getPlayerInfo()->isPlaying)
        HDIa_widgetExtEnableImageAnimation(handle);
    else
        HDIa_widgetExtDisableImageAnimation(handle);
#endif /* WIDGET_ANIMATION_ON_SMIL_PLAYING */
    if (handle > 0)
    {
        (void)integerToMsfColor(object->info.image.bgColor, &color);
        style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, NULL, 
            &color, NULL, NULL, NULL, NULL, NULL);
        
        setGadgetRegion(&gadgetSize, &gadgetPosition, object);
    
		(void)MSF_WIDGET_GET_SIZE(handle, &imgSize);

        if (0 == imgSize.height || 0 == imgSize.width) 
        {
            imageZoom = MsfImageZoomAutofit;
        }
		/* Check if the image can fit horizontally on the display  */
#ifdef WAP_SUPPORT
        else if (imgSize.height > gadgetSize.height || 
			imgSize.width > gadgetSize.width)
        {
            MSF_UINT32 old_width = gadgetSize.width;
			MSF_UINT32 old_height = gadgetSize.height;
            kal_int32 output_x, output_y;
            kal_int32 output_width, output_height;

            imageZoom = MsfImageZoomAutofit;
			if (gadgetSize.width > imgSize.width)
			{
				gadgetSize.width = imgSize.width;
			}
			if (gadgetSize.height > imgSize.height)
			{
				gadgetSize.height = imgSize.height;
			}
            old_width = gadgetSize.width;
            /* image and padding of top & bottom need to be in display area */
            old_height = gadgetSize.height - SMA_IMAGE_GADGET_PADDING * 2;

            HDIa_widgetExtImageUtilFixBox(
                old_width,
                old_height,
                imgSize.width,
                imgSize.height,
                &output_x,
                &output_y,
                &output_width,
                &output_height);
            gadgetSize.width = (MSF_UINT16)output_width;
            gadgetSize.height = (MSF_UINT16)output_height;
            gadgetPosition.x = (MSF_UINT16)output_x;
            gadgetPosition.y = (MSF_UINT16)output_y;
        }
#else
		else if (imgSize.width > gadgetSize.width)
		{
			/* Scale using the same aspect */
            gadgetSize.height = (MSF_INT16)((imgSize.height * gadgetSize.width)/imgSize.width);
            imageZoom = MsfImageZoomAutofit;
		}
#endif /* WAP_SUPPORT */
        else if (MsfImageZoomAutofit != (imageZoom = getImageZoom(object)))
        {
		    /* Image position */
		    gadgetPosition.x = (MSF_INT16)(gadgetPosition.x + 
                ((gadgetSize.width - imgSize.width)>>1));
		    gadgetPosition.y = (MSF_INT16)(gadgetPosition.y + 
                ((gadgetSize.height - imgSize.height)>>1));
            memcpy(&gadgetSize, &imgSize, sizeof(MsfSize));
        }


        if (gadgetSize.height == 0 || gadgetSize.width == 0)
        {
            /* size is 0 so nothing will be shown. */
            return TRUE;
        }
        
        /* Create gadget handle if it does not exist */
        if (!smaSlideForm.imageGadgetHandle)
        {
            smaSlideForm.imageGadgetHandle = MSF_WIDGET_IMAGE_GADGET_CREATE(
                MSF_MODID_SMA, handle, &gadgetSize, 
                imageZoom, 0, style);
            if (smaSlideForm.imageGadgetHandle == 0) 
            {
                (void)MSF_WIDGET_RELEASE(style);
                return FALSE;
            } /* if */
        }
        else
        {
            if (-1 == MSF_WIDGET_IMAGE_GADGET_SET(smaSlideForm.imageGadgetHandle, 
                handle, imageZoom))
            {
                (void)MSF_WIDGET_RELEASE(style);
                return FALSE;
            } /* if */
        }
        (void)MSF_WIDGET_RELEASE(style);
        
#ifdef WAP_SUPPORT
        /* Center gadget */
        if (gadgetPosition.y == 0)
        {
            gadgetPosition.y = (MSF_INT16)(gadgetPosition.y + SMA_IMAGE_GADGET_PADDING);
        }
#endif /* WAP_SUPPORT */        
        if (-1 == MSF_WIDGET_SET_SIZE(smaSlideForm.imageGadgetHandle, 
            &gadgetSize))
        {
            status = FALSE;
        } 
#ifdef WIDGET_SLIDING_SMIL_SUPPORT /* Before MSF_WIDGET_WINDOW_ADD_GADGET */
        else if (-1 == MSF_WIDGET_GADGET_SET_PROPERTIES (
            smaSlideForm.imageGadgetHandle, MSF_GADGET_PROPERTY_FOCUS))
        {
            status = FALSE;
        }
#endif /* Sliding SMIL support require the image gadget to be set focus */
        else if (-1 == MSF_WIDGET_WINDOW_ADD_GADGET(smaSlideForm.formHandle,
               smaSlideForm.imageGadgetHandle, &gadgetPosition, NULL))
        {
            status = FALSE;
        }
#ifndef WAP_SUPPORT
        else if (-1 == MSF_WIDGET_GADGET_SET_PROPERTIES (
            smaSlideForm.imageGadgetHandle, MSF_GADGET_PROPERTY_FOCUS))
        {
            status = FALSE;
        }
#endif /* WAP_SUPPORT */
    } /* if */
    return status;
} /* displayImageObject */


/*! \brief Handles an video object.
 * \param filePath path to video file
 * \param offset video obj offset in file
 * \param size of data
 *****************************************************************************/
void displayVideoObject(const SmaObjectInfo *objectInfo, 
    const char *filePath, MSF_UINT32 retFsm, MSF_UINT32 retSig)
{
	MsfImageHandle videoHandle = 0;
	const char *mimeType;
	MsfCreateData createData;
	const SmaImageObject *videoObj;

    memset(&loadVideoInstance, 0x00, sizeof(LoadVideoInstanceData));

    loadVideoInstance.objectInfo = objectInfo;
    loadVideoInstance.retFsm = retFsm;
    loadVideoInstance.retSig = retSig;

	videoObj = &objectInfo->info.image;

    
	if ((0 == objectInfo->info.image.size) ||
		(NULL == filePath))
	{
		/* invalid input */
#ifdef WAP_SUPPORT
		(void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)loadVideoInstance.retFsm, 
			loadVideoInstance.retSig, SMA_RESULT_ERROR);
#endif
		return;	
	} /* if */

	mimeType = convertSlsToMimeType(objectInfo->info.image.type);
	if (mimeType == NULL)
	{
#ifdef WAP_SUPPORT
		(void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)loadVideoInstance.retFsm, 
			loadVideoInstance.retSig, SMA_RESULT_ERROR);
#endif
		return;
	} /* if */
	
	if (smaCreatePipeOperation(SMA_PIPE_NAME))
	{	
		createData.resource = SMA_PIPE_NAME;
		/* create video object here */
		videoHandle = MSF_WIDGET_IMAGE_CREATE_FORMAT(MSF_MODID_SMA, &createData, 
			mimeType, MsfResourcePipe, 0);
		
		if (videoHandle == 0)
		{
#ifdef WAP_SUPPORT
            (void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)loadVideoInstance.retFsm, 
                loadVideoInstance.retSig, SMA_RESULT_ERROR);
#endif /* WAP_SUPPORT */
			/* failed to create videoHandle */
			smaClosePipeOperation();
		} 
		else
		{
			/* videoHandle created, register for event and feed the pipe */
			(void)smaRegisterEvent(videoHandle, SMA_NOTIFICATION_EVENT,
				0, MsfNotifyResourceLoaded, (MsfEventType)0, loadVideoSuccessCallback, 0,0);
			(void)smaRegisterEvent(videoHandle, SMA_NOTIFICATION_EVENT,
				0, MsfNotifyResourceFailed, (MsfEventType)0, loadVideoFailCallback, 0,0);

			smaCopyFileToPipe(filePath, videoObj->offset, videoObj->size, 
				FALSE, (SmaStateMachine)0, 0);
		} /* if */
	} /* if */

} /* displayVideoObject */

/* video object loaded */
static void loadVideoSuccessCallback(MsfWindowHandle handle)
{
    SmaResult result = SMA_RESULT_OK;

    smaClosePipeOperation();

    if (!displayImageObject(loadVideoInstance.objectInfo, handle))
    {
        if (handle != 0)
        {
            (void)MSF_WIDGET_RELEASE(handle);
            handle = 0;
        } /* if */
        result = SMA_RESULT_ERROR;
    } /* if */
    
    /* Contintue with the next part */
    (void)SMA_SIGNAL_SENDTO_I(SMA_FSM_SLIDE, SMA_SIG_LOAD_NEXT_OBJECT, result);
} /* loadVideoDoneCallback */

/* failed to load object, show alternative text or broken video */
static void loadVideoFailCallback(MsfWindowHandle handle)
{
    smaClosePipeOperation();
    
    if (handle != 0)
    {
        (void)MSF_WIDGET_RELEASE(handle);
        handle = 0;
    } /* if */

    (void)SMA_SIGNAL_SENDTO_I(loadVideoInstance.retFsm, loadVideoInstance.retSig, SMA_RESULT_ERROR);

    (void)handle;
} /* loadVideoDoneCallback */


/*! \brief Handles a text object.
 * \param object Object information
 * \param data Text data, data MUST be NULL terminated
 * \param size of data
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL displayTextObject(SmaGadgetType gadgetType, 
	const SmaObjectInfo *object, const char *data) 
{
    MsfSize     gadgetSize = {0,0};
    MsfPosition gadgetPosition = {0,0}; 
    MSF_BOOL usePredefined;
	MsfStringHandle stringHandle;
	MsfStyleHandle style = 0;
    MsfColor color = {0, 0, 0};
    MsfColor bgColor = {255, 255, 255};
    SmtrCreateRspData *rsp = NULL;
    SmtrCreateTextBoxProperties prop;
    SmaPlayerInfo *playerInfo;

    if (object == NULL)
    {
        return TRUE;
    } /* if */ 

    usePredefined = (data == NULL) ? TRUE: FALSE;
   
    setGadgetRegion(&gadgetSize, &gadgetPosition, object);
    if (gadgetSize.height == 0 || gadgetSize.width == 0)
    {
        /* size if 0 so nothing will be shown. */
        return TRUE;
    } 
    playerInfo = getPlayerInfo();
	if (integerToMsfColor(object->info.text.textColor, &color))
	{
        /*  Get background color. NOTE! This color must be changed when region color
         *  support is implemented */
        playerInfo = getPlayerInfo();
        if (integerToMsfColor(playerInfo->rootBgColor, &bgColor))
        {
            style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, &color, 
                &bgColor, NULL, NULL, NULL, NULL, NULL);
        }
        else
        {
            style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, &color, 
                NULL, NULL, NULL, NULL, NULL, NULL);
        }
	} /* if */
    else if (integerToMsfColor(playerInfo->rootBgColor, &bgColor))
    {
        style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, NULL, 
            &bgColor, NULL, NULL, NULL, NULL, NULL);
    }
    else
    {
        style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_SMA, NULL, 
            NULL, NULL, NULL, NULL, NULL, NULL);
    }
    if (usePredefined)
    {
        stringHandle = SMA_GET_STR_ID(SMA_STR_ID_UNKNOWN_TEXT);
    } 
    else
    {
        stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, 
            data, MsfUtf8, (int)strlen(data) + 1, style);
    } /* if */
    
   	/* release style */
	if (style != 0)
	{
		(void)MSF_WIDGET_RELEASE(style);
	} /* if */

    if (stringHandle == 0)
    {
        return FALSE;
    }
#ifdef WAP_SUPPORT
    HDIa_widgetExtStringSetCacheGetVisible(stringHandle);
#endif /* WAP_SUPPORT */
    (void)MSF_WIDGET_GET_COLOR(stringHandle, &bgColor, 1);
    (void)MSF_WIDGET_GET_COLOR(stringHandle, &color, 0);
        /* create text gadget */
    memset(&prop, 0, sizeof(SmtrCreateTextBoxProperties));
#ifdef WAP_SUPPORT
    prop.alignment = MsfLeft;  //doesn't work though
#else
    prop.alignment = MsfCenter;
#endif /*WAP_SUPPORT*/
    prop.flags = SMTR_PROP_RENDER_LINKS | SMTR_PROP_VERTICAL_RESIZE | 
        SMTR_PROP_HORIZONTAL_RESIZE;
    //prop.schemes = SMTR_SCHEME_PHONE; //useless
    prop.schemes = 0x7FFFFFFF; /* All schemes */
    memcpy(&prop.size, &gadgetSize, sizeof(MsfSize));
    prop.size.width -= (2 * SMA_TEXT_GADGET_PADDING);
    memcpy(&prop.textColor, &color, sizeof(MsfColor));
    memcpy(&prop.bgColor, &bgColor, sizeof(MsfColor));
    
    if (SMTR_RESULT_OK != smtrCreateTextBox(stringHandle, &prop, &rsp)) 
    {
        if (rsp) 
        {
            smtrFreeSmtrCreateRspData(&rsp);
        }	
        return FALSE;
    }
    if (smaRegisterNotification(rsp->gadgetHandle, MsfNotifyFocus, 0, 
        SMA_FSM_SLIDE, SMA_SIG_GADGET_GOT_FOCUS) < 0)
    {
        if (rsp) 
        {
            smtrFreeSmtrCreateRspData(&rsp);
        }	
        return FALSE;
    }
    if (smaRegisterNotification(rsp->gadgetHandle, MsfNotifyLostFocus, 0, 
        SMA_FSM_SLIDE, SMA_SIG_GADGET_LOST_FOCUS) < 0)
    {
        if (rsp) 
        {
            smtrFreeSmtrCreateRspData(&rsp);
        }	
        return FALSE;
    }
    /* Center gadget */
	gadgetPosition.x = (MSF_INT16)
        ((gadgetSize.width - rsp->gadgetSize.width) >> 1);
	gadgetPosition.y = (MSF_INT16)(gadgetPosition.y + 
        ((gadgetSize.height - rsp->gadgetSize.height) >> 1));
    if (-1 == MSF_WIDGET_WINDOW_ADD_GADGET(smaSlideForm.formHandle, 
        rsp->gadgetHandle, &gadgetPosition, NULL))
    {
        if (rsp) 
        {
            smtrFreeSmtrCreateRspData(&rsp);
        }	
        return FALSE;
    } 
    if (SMA_GADGET_ALT == gadgetType) 
    {
        smaSlideForm.altStringGadgetHandle = rsp->gadgetHandle;
        smaSlideForm.altStringGadgetInstance = rsp->instance;
        smaSlideForm.altStringHandle = stringHandle;
    }
    else
    {
        smaSlideForm.stringGadgetHandle = rsp->gadgetHandle;
        smaSlideForm.stringGadgetInstance = rsp->instance;
        smaSlideForm.stringHandle = stringHandle;
    }

    {    /* reset/set selected link in the string gadget if there is */
        if(smaSlideForm.selectedLink)
            smtrFreeSmtrLinkEntry(&smaSlideForm.selectedLink);
    	
        (void)smtrHasActiveLink(smaSlideForm.stringGadgetInstance, &smaSlideForm.selectedLink);
    }
#ifndef WIDGET_SLIDING_SMIL_SUPPORT
    (void)MSF_WIDGET_SET_IN_FOCUS(rsp->gadgetHandle, 1);
#endif /* ~WIDGET_SLIDING_SMIL_SUPPORT */
    if (rsp) 
    {
        smtrFreeSmtrCreateRspData(&rsp);
    }	
    return TRUE;
} /* displayTextObject */


/*! \brief Handles an alternative text object.
 * \param object Object information
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL displayAlternativeTextObject(SmaObjectInfo *object )
{
	MSF_BOOL ret = FALSE;
#ifndef WAP_SUPPORT
	MSF_UINT32 altBufSize = strlen(object->info.image.alt) +1;
	SmaObjectInfo *altObjectInfo = SMA_ALLOC(sizeof(SmaObjectInfo));

	altAttrTextBuf = object->info.image.alt;

	altObjectInfo->info.text.region.position.cx.value = 
		object->info.text.region.position.cx.value;
	altObjectInfo->info.text.region.position.cx.type = 
		object->info.text.region.position.cx.type;
	altObjectInfo->info.text.region.position.cy.value = 
		object->info.text.region.position.cy.value;
	altObjectInfo->info.text.region.position.cy.type = 
		object->info.text.region.position.cy.type;

	altObjectInfo->info.text.region.size.cx.value = object->info.text.region.size.cx.value;
	altObjectInfo->info.text.region.size.cx.type = object->info.text.region.size.cx.type;
	altObjectInfo->info.text.region.size.cy.value = object->info.text.region.size.cy.value;
	altObjectInfo->info.text.region.size.cy.type = object->info.text.region.size.cy.type;

	altObjectInfo->fileName = object->fileName;

	/* Clear image object */
	memset(object, 0, sizeof(object));

	object->type = SLS_OBJECT_TYPE_TEXT;
	object->info.text.type = SLS_TEXT_PLAIN;
	object->info.text.size = altBufSize;
	object->info.text.offset = 0;
	object->info.text.charset = SMA_UTF8;

	object->info.text.region.position.cx.value = 
		altObjectInfo->info.image.region.position.cx.value;
	object->info.text.region.position.cx.type = 
		altObjectInfo->info.image.region.position.cx.type;
	object->info.text.region.position.cy.value = 
		altObjectInfo->info.image.region.position.cy.value;
	object->info.text.region.position.cy.type = 
		altObjectInfo->info.image.region.position.cy.type;

	object->info.text.region.size.cx.value = 
		altObjectInfo->info.image.region.size.cx.value;
	object->info.text.region.size.cx.type = 
		altObjectInfo->info.image.region.size.cx.type;
	object->info.text.region.size.cy.value = 
		altObjectInfo->info.image.region.size.cy.value;
	object->info.text.region.size.cy.type = 
		altObjectInfo->info.image.region.size.cy.type;

	object->fileName = altObjectInfo->fileName;

	SMA_FREE(altObjectInfo);

	ret = displayTextObject(SMA_GADGET_ALT, object, altAttrTextBuf);
#endif /* ~WAP_SUPPORT */

	return ret;
} /* displayAlternativeTextObject */ 


/*! \brief Gets the image zoom factor
 * \param object object to search
 * \return enum MsfImageZoom
 *****************************************************************************/
static MsfImageZoom getImageZoom(const SmaObjectInfo *object)
{
	/*lint -e{788} */
	switch (object->info.image.region.fit)
	{
	case SMA_ATTR_FILL:
		return MsfImageZoomAutofit;
	default:
		return MsfImageZoom100;
	} /* switch */
} /* getImageZoom */


/*!
 * \brief Stop playing a sound
 *****************************************************************************/
void stopSound(void)
{
    if (smaSlideForm.audioHandle != 0)
    {
        (void)MSF_WIDGET_SOUND_STOP(smaSlideForm.audioHandle);
        /* clean up */
        (void)MSF_WIDGET_RELEASE(smaSlideForm.audioHandle);
        smaSlideForm.audioHandle = 0;

        widget_disable_status_bar(WIDGET_STATUS_BAR_SOUND_IND);
    } /* if */
} /* stopSound */


/*! \brief Check the source for the widget action
 * \param action message ID of the MMS to show SMIL in.
 * \param window Handle to the active window
 * \param playerInfo information about the SMIL and the screen.
 * \return Result of the operation
 *****************************************************************************/
SmaResult widgetActionHandler(MSF_UINT32 action, MSF_UINT32 window, 
    SmaPlayerInfo *playerInfo)
{
    SmaResult result = SMA_RESULT_OK;

    if (window == smaSlideMenu.menuHandle )
    {
        result = handleSlideMenuAction(action, playerInfo);
    }
    else if (window == smaSlideForm.formHandle)
    {
        result = handleSlideFormAction(action, playerInfo);
    }
    else if (smaLinkMenuHandleActions(window, action))
    {
        result = SMA_RESULT_OK;
    }
    else
    {
        /* unknown window */
    } /* if */

    return result;
} /* widgetActionHandler */
#ifdef __UNIFIED_MSG_SUPPORT__
static void smaPropViewGoBack(ctk_screen_handle scrid)
{
	if (smaPropView != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaScreen.screenHandle, smaPropView);
        (void)MSF_WIDGET_RELEASE(smaPropView);
        smaPropView = 0;
    }
}

static void smaDeletePropView(void)
{
    if (smaPropView != 0)
    {
        (void)MSF_WIDGET_REMOVE(smaScreen.screenHandle, smaPropView);
        (void)MSF_WIDGET_RELEASE(smaPropView);
        smaPropView = 0;
    }
}
#endif /*__UNIFIED_MSG_SUPPORT__*/
/*!
 * \brief Handle action for the Main form
 * 
 * \param action The action that was performed.
 * \param playerInfo Information about the device and the smil.
 *****************************************************************************/
static SmaResult handleSlideFormAction(MSF_UINT32 action, 
	SmaPlayerInfo *playerInfo)
{
    SmaResult result = SMA_RESULT_OK;
    MsfActionHandle  smaAction = (MsfActionHandle)action;

    if (action == smaSlideForm.actionOk)
    {
        /* do not accept play action if in play mode */
        if (!playerInfo->isPlaying)
        {
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            if(MMA_IS_UNIFIED_COMPOSER_ACTIVE())
#else
            if (meaSmilEditorIsActive())
#endif                
            {
                if (smaSlideForm.displayWaitingAnimation == FALSE)
                {
                    HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
                    smaSlideForm.displayWaitingAnimation = TRUE;
                }
                result = playSmil(playerInfo);
                playerInfo->isPlaying = TRUE;
            }
            else
            {
                result = createSlideMenu(playerInfo);
            }
        } /* if */
    }
    else if (smaAction == smaSlideForm.actionStop)
    {
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
			SmaPlayerInfo * playerInfo = getPlayerInfo();
#ifdef __UNIFIED_COMPOSER_SUPPORT__
            if(!MMA_IS_UNIFIED_COMPOSER_ACTIVE())
#else
            if ( !meaSmilEditorIsActive())
#endif
			    playerInfo->isAutoplay = FALSE;
#endif
        /* stop smil or exit smil player */
        if (playerInfo->isPlaying == TRUE)
        {
            /* We are in play mode and user asked to stop SMIL*/
            result = stopSmil(playerInfo);
        }
        else
        {
            /* user asked to exit SMIL player */
			EXIT_SMIL_PLAYER(SMA_RESULT_OK);
        } /* if */
    }
    else if (smaAction == smaSlideForm.actionMenu)
    {
        if (playerInfo->isPlaying == FALSE)
        {
            result = createSlideMenu(playerInfo);
        } /* if */
    }
    else
    {
        /* unknown action */

    } /* if */
    return result;
}  /* handleSlideFormAction */

/*!
 * \brief Handle action for the slide menu
 * 
 * \param action The action that was performed.
 * \param playerInfo Information about the device and the smil.
 *****************************************************************************/
#ifdef __UNIFIED_MSG_SUPPORT__
 static SmaResult handleSlideMenuAction(MSF_UINT32 action, SmaPlayerInfo *playerInfo)
{
    MsfActionHandle  smaAction = (MsfActionHandle)action;
    SmaSlideInfo *slide = getSlideInfo(playerInfo->currentSlide, playerInfo);
    SmaResult result = SMA_RESULT_OK;
    int index = 0;

    if (smaAction == smaSlideMenu.actionOk)
    {
        /* an item is selected */
        index = getSlideMenuItem();

        switch (index)
        {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
            case SMA_SLIDE_MENU_MOVE_TO_ARCHIVE:
            {
                smaShowConfirmDialog(MEA_STR_ID_MOVE_TO_ARCHIVE_QUERY, SMA_FSM_MAIN, SMA_SIG_MH_MOVE_TO_ARCHIVE, playerInfo->msgId);
                break;
            }
#endif  /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/    
            case SMA_SLIDE_MENU_PLAY: /* PLAY */
            {
                if (smaSlideForm.displayWaitingAnimation == FALSE)
                {
                    HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
                    smaSlideForm.displayWaitingAnimation = TRUE;
                }
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
                playerInfo->isAutoplay = TRUE;
#endif
                deleteSlideMenu();
                result = playSmil(playerInfo);
                playerInfo->isPlaying = TRUE;
                break;
            }

#ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
            case SMA_SLIDE_MENU_USE_TEMPLATE:
            {
                if(playerInfo->forwardLock)
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD_LOCK), MsfError, 0);
                }
                else
                {
                    deleteSlideMenu();
                    MEAif_editMessage(MSF_MODID_SMA, playerInfo->msgId);  /* need to check creation mode */
#ifndef __UNIFIED_COMPOSER_SUPPORT__  /* wait til UC can be started successfully */
                    EXIT_SMIL_PLAYER(SMA_RESULT_OK);
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                    meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
  #endif
#endif
                }
                break;
            }
#endif /* SMA_CFG_USER_TEMPLATE_SUPPORT*/
            case SMA_SLIDE_MENU_SEND: /* SEND */
            {
                deleteSlideMenu();
                MEAif_sendMessage(MSF_MODID_SMA, playerInfo->msgId);  /* need to check creation mode */
//#ifndef __UNIFIED_COMPOSER_SUPPORT__
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
  #endif
//#endif
                break;
            }
            
            case SMA_SLIDE_MENU_REPLY:
            {
                deleteSlideMenu();
#ifdef __UNIFIED_COMPOSER_SUPPORT__
                wap_send_mmi_mms_start_uc_req(MMA_MODE_REPLY, playerInfo->msgId);
#else
                MEAif_replyMessage(MSF_MODID_SMA, playerInfo->msgId);
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
  #endif
#endif
                break;
            }

            case SMA_SLIDE_MENU_REPLY_SMS:
            {
                char *subject = NULL, *address = NULL;
                extern void meaTerminateApp(void);

                deleteSlideMenu();
                getMmsMsgSubAddr(MSF_MODID_WIDGET, playerInfo->msgId, &subject, &address, 250);
                if (msf_cmmn_utf8_strlen(address) > 20)  /* 20: MAX_DIGITS_SMS */
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_NUMBER_TOO_LONG), MsfError, 0);
                    MSF_MEM_FREE(MSF_MODID_WIDGET, subject);
                    MSF_MEM_FREE(MSF_MODID_WIDGET, address);
                    break;
                }
                MSF_MEM_FREE(MSF_MODID_WIDGET, subject);
                widget_execute_MMI_p(mms_enter_sms_editor_handler, (void *)address, FALSE);

#ifndef __UNIFIED_COMPOSER_SUPPORT__
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
#endif /*__UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__*/
#endif /*__UNIFIED_COMPOSER_SUPPORT__*/

/*                meaTerminateApp();*/
                break;
            }
            
            case SMA_SLIDE_MENU_REPLY_ALL:
            {
                deleteSlideMenu();
#ifdef __UNIFIED_COMPOSER_SUPPORT__
                wap_send_mmi_mms_start_uc_req(MMA_MODE_REPLY_ALL, playerInfo->msgId);
#else
                MEAif_replyMessageAll(MSF_MODID_SMA, playerInfo->msgId);
                EXIT_SMIL_PLAYER(SMA_RESULT_OK);
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
 #endif
#endif
                break;
            }
            
            case SMA_SLIDE_MENU_FORWARD:
            {
                if(playerInfo->forwardLock)
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD), MsfError, 0);
                }
                else if(MSF_FILE_GETSIZE(playerInfo->filePath) > (MEA_CFG_MESSAGE_SIZE_MAXIMUM+1024))	/*1KB margin*/
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_TO_FORWARD), MsfError, 0);
                }
                else
                {
                    deleteSlideMenu();
                    MEAif_forwardMessage(MSF_MODID_SMA, playerInfo->msgId);  /* need to check creation mode */
#ifndef __UNIFIED_COMPOSER_SUPPORT__
                    EXIT_SMIL_PLAYER(SMA_RESULT_OK);
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                    meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
  #endif
#endif
                }
                break;
            }
            
            case SMA_SLIDE_MENU_EDIT:
            {
                if(playerInfo->forwardLock)
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_FORWARD_LOCK), MsfError, 0);
                }
                else if(MSF_FILE_GETSIZE(playerInfo->filePath) > (MEA_CFG_MESSAGE_SIZE_MAXIMUM+1024))	/*1KB margin*/
                {
                    HDIa_widgetExtShowPopup(MSF_MODID_SMA, SMA_GET_STR_ID(MEA_STR_ID_FAILED_TO_EDIT), MsfError, 0);
                }
                else
                {
                    deleteSlideMenu();
                    MEAif_editMessage(MSF_MODID_SMA, playerInfo->msgId);  /* need to check creation mode */
#ifndef __UNIFIED_COMPOSER_SUPPORT__  /* wait til UC can be started successfully */
                    EXIT_SMIL_PLAYER(SMA_RESULT_OK);
  #ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
                    meaDeleteMhNavMenu();  /* not good but the only timing to do it here */
  #endif
#endif
                }
                break;
            }
            
            case SMA_SLIDE_MENU_DELETE:
            {
                smaShowConfirmDialog(MEA_STR_ID_DELETE_MSG_QUEST, SMA_FSM_MAIN, SMA_SIG_MH_DELETE_MM, playerInfo->msgId);
                break;
            }
            
            case SMA_SLIDE_MENU_DELETE_ALL:
            {
                MSF_UINT32 strId;
                switch (playerInfo->folder)
                {
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__                
                    case MMS_ARCHIVE:
                        strId = MEA_STR_ID_DELETE_ALL_ARCHIVE;
                        break;
#endif  /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/                       
                    case MMS_INBOX:
                        strId = MEA_STR_ID_DELETE_ALL_INBOX;
                        break;
                    case MMS_DRAFTS:
                        strId = MEA_STR_ID_DELETE_ALL_DRAFTS;
                        break;
                    case MMS_OUTBOX:
                        strId = MEA_STR_ID_DELETE_ALL_OUTBOX;
                        break;
                    case MMS_SENT:
                        strId = MEA_STR_ID_DELETE_ALL_SENT;
                        break;
                    case MMS_TEMPLATES:
                        strId = MEA_STR_ID_DELETE_ALL_TEMPLATE;
                        break;
                #ifdef SMA_CFG_USER_TEMPLATE_SUPPORT
                    case MMS_USRDEF_TEMPLATES:
                        strId = MEA_STR_ID_DELETE_ALL_TEMPLATE;
                        break;
                #endif
                    default:
                        return SMA_RESULT_ERROR;
                }
            	
                smaShowConfirmDialog(strId, SMA_FSM_MAIN, SMA_SIG_MH_DELETE_ALL_MM, playerInfo->folder);
                break;
            }
            
            case SMA_SLIDE_MENU_PROPERTIES:
            {
                ctk_screen_handle   scrid;
                ctk_string_id       titleid;
                kal_uint8           *text;
                MsfPosition propPosition = {0,0};
                extern MmsFileType fldrGetFileSuffix(MmsMsgId msgId);
                extern char *meaCreateNotifPropText(MmsMsgId msgId);
                extern char *meaCreateMsgPropText(MmsMsgId msgId);
                
                if (0 != smaPropView)
                {
                    return FALSE;
                }
                memset(&smaPropView, 0, sizeof(MsfWindowHandle));

                if(fldrGetFileSuffix(playerInfo->msgId) == MMS_SUFFIX_NOTIFICATION)
                {
                    text = (kal_uint8 *)meaCreateNotifPropText(playerInfo->msgId);
                }
                else
                {
                    text = (kal_uint8 *)meaCreateMsgPropText(playerInfo->msgId); 
                }
                
                /* Create widow */
                titleid = MEA_STR_ID_PROPERTIES;
                smaPropView = HDIa_widgetExtCreateTextViewSeparator(MSF_MODID_SMA, text, titleid , 0); 
                MSF_MEM_FREE(MSF_MODID_MEA, text);
                
                /* Set Key */
                scrid = HDIa_widgetCtkGetScreenHandle(smaPropView);
                ctk_screen_addRSK_UA(scrid, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, smaPropViewGoBack, KAL_TRUE);
                ctk_screen_add_key_UA(scrid, KEY_LEFT_ARROW, NULL, smaPropViewGoBack, KAL_TRUE);
                if (-1 == MSF_WIDGET_SCREEN_ADD_WINDOW (smaScreen.screenHandle, smaPropView , &propPosition, 0, 0))
                {
                    return SMA_RESULT_ERROR;
                }

                (void)MSF_WIDGET_SET_IN_FOCUS(smaScreen.screenHandle, TRUE);
                (void)MSF_WIDGET_SET_IN_FOCUS (smaPropView, TRUE);
                break;
            }
            
            case SMA_SLIDE_MENU_SAVE_OBJECT:
            {
                if(!smaCreateObjectMenu(slide))
                {
                    deleteSlideMenu();
                }
                break;
            }
            
            case SMA_SLIDE_MENU_USE_NUMBER:
            {
                MEAif_useNumber(MSF_MODID_SMA, playerInfo->msgId);
                break;
            }
            
            default :
            {
                /* unknown selection */
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_B86B57E87349BEFE062BBE835E115769, "SMA: unknown menu selection in widgetAction\n"));
                result = SMA_RESULT_ERROR;
                EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
                break;
            }
        } /* switch */
    }
    else if (smaAction == smaSlideMenu.actionBack)
    {
        deleteSlideMenu();
        result = showSlideForm();
    }
    else
    {
        /* unknown action */
        result = SMA_RESULT_OK;
    }

    return result;
} /* handleSlideMenuAction */

#else
static SmaResult handleSlideMenuAction(MSF_UINT32 action, 
    SmaPlayerInfo *playerInfo)
{

    SmaResult result = SMA_RESULT_OK;
    MsfActionHandle  smaAction = (MsfActionHandle)action;
    const char *mimeType;
    int index = 0;
    SmaSlideInfo *slideInfo = NULL;
    MSF_UINT32 size = 0;
    MSF_UINT32 startPos = 0;
    MSF_UINT32 type = 0;
    char *fileName;
    char *boundary = NULL;
    SlsMediaObjectType objType = SLS_OBJECT_TYPE_NONE;

    if (smaAction == smaSlideMenu.actionOk)
    {
        /* an item is selected */
        index = getSlideMenuItem();

        switch (index)
        {
        case SMA_SLIDE_MENU_PLAY:    /* PLAY */
#ifdef WAP_SUPPORT
            /* Otherwise showSlideForm() might set focus to the current gadget and send MsfNotifyFocus */
            if (smaSlideForm.displayWaitingAnimation == FALSE)
            {
                HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
                    smaSlideForm.displayWaitingAnimation = TRUE;
            }
#else
            (void)showSlideForm();    /* generate the last object will call showSlideForm, so we mark it here */
#endif
            deleteSlideMenu();
            result = playSmil(playerInfo);
            playerInfo->isPlaying = TRUE;
            break;
            
#ifndef WAP_SUPPORT
        case SMA_SLIDE_MENU_REWIND:    /* REWIND */
            /* (void)showSlideForm(); */	 /* generate the last object will call showSlideForm(), so we comment it out here. Or it'd cause focus error */
            result = rewindSmil(playerInfo);
            deleteSlideMenu();
            break;
#endif /* ~WAP_SUPPORT */

        case SMA_SLIDE_MENU_PREVIOUS:    /* PREVIOUS */
            /* (void)showSlideForm(); */	/* generate the last object will call showSlideForm(), so we comment it out here. Or it'd cause focus error */
            result = displayPreviousSlide(playerInfo);
            deleteSlideMenu();
            break;
            
        case SMA_SLIDE_MENU_NEXT:    /* NEXT */
            /* (void)showSlideForm(); */	/* generate the last object will call showSlideForm(), so we comment it out here. Or it'd cause focus error */
            result = displayNextSlide(playerInfo);
            deleteSlideMenu();
            break;
            
        case SMA_SLIDE_MENU_SAVE_TEXT_AS:
        case SMA_SLIDE_MENU_SAVE_IMAGE_AS:    /* SAVE IMAGE AS */
        case SMA_SLIDE_MENU_SAVE_VIDEO_AS:    /* SAVE VIDEO AS */
        case SMA_SLIDE_MENU_SAVE_AUDIO_AS:    /* SAVE AUDIO AS */
            switch(index)
            {
            case SMA_SLIDE_MENU_SAVE_TEXT_AS:
                objType = SLS_OBJECT_TYPE_TEXT;
                break;
            case SMA_SLIDE_MENU_SAVE_IMAGE_AS:
                objType = SLS_OBJECT_TYPE_IMAGE;
                break;
            case SMA_SLIDE_MENU_SAVE_VIDEO_AS:
                objType = SLS_OBJECT_TYPE_VIDEO;
                break;
            case SMA_SLIDE_MENU_SAVE_AUDIO_AS:
                objType = SLS_OBJECT_TYPE_AUDIO;
                break;
            default:
                objType = SLS_OBJECT_TYPE_NONE;    /* shouldn't be here */
                break;              	
            }

            (void)showSlideForm();
#ifdef WAP_SUPPORT
            deleteSlideMenu();
#endif
            slideInfo = getSlideInfo(playerInfo->currentSlide, playerInfo);
            if (slideInfo)
            {
                SlsUnrefItemList *objPtr = NULL;
                if (!getObjectInfo(&size, &startPos, &type, &fileName, &boundary, &slideInfo->object, objType))
                {
                    /* If no information is available do not save the object */
                    if (slideInfo->object.isDrm)
                    {
                        (void)smaShowDialog(SMA_STR_ID_FAILED_TO_SAVE_DRM, SMA_DIALOG_ERROR);
                    }
                    else
                    {
                        (void)smaShowDialog(SMA_STR_ID_FAILED_TO_SAVE, SMA_DIALOG_ERROR);
                    }
                    break;
                }
                mimeType = getMimeType((SlsMediaType)type);
#ifdef MMS_SLIM_MEM
                
                objPtr = SMA_ALLOC(sizeof(SlsUnrefItemList));
                if (objPtr)
                {
                    objPtr->contentType = msf_cmmn_strdup(MSF_MODID_SMA, mimeType);
                    objPtr->fileName = msf_cmmn_strdup(MSF_MODID_SMA, fileName);
                    objPtr->mediaType = (SlsMediaType)type;
                    objPtr->next = NULL;
                    objPtr->offset = startPos;
                    objPtr->size = size;
                    startContentRouting(objPtr);
                }
                else
                {
                    /* unable to get slide info */
                    (void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)SMA_FSM_MAIN, 
                        SMA_SIG_MH_SBP_COMPLETE, SMA_RESULT_ERROR);
                }
#else
                saveBodyPart(fileName, mimeType, playerInfo->filePath, 
                    startPos, size, SMA_FSM_MAIN, SMA_SIG_MH_SBP_COMPLETE, 
                    boundary);
#endif /* MMS_SLIM_MEM */

                if (fileName != NULL)
                {
                    SMA_FREE(fileName);
                    fileName = NULL;
                } /* if */
            } 
            else
            {
                /* unable to get slide info */
                (void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)SMA_FSM_MAIN, 
                    SMA_SIG_MH_SBP_COMPLETE, SMA_RESULT_ERROR);
            } /* if */
            break;			
            
        case SMA_SLIDE_MENU_LINK_BRA:
            if (smaSlideForm.selectedLink && smaSlideForm.selectedLink->link) 
            {
                smaStartBra(smaSlideForm.selectedLink->link);
            }
            deleteSlideMenu();
            break;
            
        case SMA_SLIDE_MENU_LINK_CALL:
            if (smaSlideForm.selectedLink && smaSlideForm.selectedLink->link) 
            {
                smaMakeCall(smaSlideForm.selectedLink->link);
            }
            deleteSlideMenu();
            break;

        case SMA_SLIDE_MENU_LINK_WRITE:
            if (smaSlideForm.selectedLink && smaSlideForm.selectedLink->link) 
            {
                if( msf_cmmn_utf8_strlen(smaSlideForm.selectedLink->link) > MEA_ME_MAX_EMAIL_ADDRESS_SIZE)
                {
                    (void)smaShowPopup(MEA_STR_ID_INVALID_RECIP_ADDRESS, MsfError);

                    break;
                }
                smaWriteMessage(smaSlideForm.selectedLink->link);
            }
//            deleteSlideMenu();
            break;

        case SMA_SLIDE_MENU_VIEW_ATTACHMENTS:
            /* display attachment list */
            (void)smaCreateAttachmentMenu();
            deleteSlideMenu();
            break;
            
#ifndef WAP_SUPPORT
        case SMA_SLIDE_MENU_EXIT:
            /* EXIT */
            result = SMA_RESULT_OK;
            EXIT_SMIL_PLAYER(SMA_RESULT_OK);
            break; 
#endif /* ~WAP_SUPPORT */

        default :
            /* unknown selection */
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_B86B57E87349BEFE062BBE835E115769, "SMA: "
                "unknown menu selection in widgetAction\n"));
            result = SMA_RESULT_ERROR;
            EXIT_SMIL_PLAYER(SMA_RESULT_ERROR);
            break;
        } /* switch */
    }
    else if (smaAction == smaSlideMenu.actionBack)
    {
        deleteSlideMenu();
        result = showSlideForm();
    }
    else
    {
        /* unknown action */
        /* Do nothing */
        result = SMA_RESULT_OK;
    } /* if */

    return result;
} /* handleSlideMenuAction */
#endif

#ifndef __UNIFIED_MSG_SUPPORT__
/*!
 * \brief Get the MIME type.
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
 * \brief Get information about a media object.
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
            if (objType == SLS_OBJECT_TYPE_TEXT)
            {
                *size = objInfo->info.text.size;
                *startPos = objInfo->info.text.offset;
                *fileType = objInfo->info.text.type;
                
                if (SLS_NOT_USED == *fileType)
                {
                    break;
                } /* if */
            }
            else if (objType == SLS_OBJECT_TYPE_IMAGE)
            {
                *size = objInfo->info.image.size;
                *startPos = objInfo->info.image.offset;
                *fileType = objInfo->info.image.type;

				if (SLS_NOT_USED == *fileType)
				{
					break;
				} /* if */
			}
			else if (objType == SLS_OBJECT_TYPE_VIDEO)
            {
                *size = objInfo->info.video.size;
                *startPos = objInfo->info.video.offset;
                *fileType = objInfo->info.video.type;

				if (SLS_NOT_USED == *fileType)
				{
					break;
				} /* if */
			}
            else if (objType == SLS_OBJECT_TYPE_AUDIO)
            {
                *size = objInfo->info.audio.size;
                *startPos = objInfo->info.audio.offset;
                *fileType = objInfo->info.audio.type;
				
				if (SLS_NOT_USED == *fileType)
				{
					break;
				} /* if */
            }
            else
            {
                return FALSE;
            } /* if */
            		
			/* copy the filename */
			if (objInfo->fileName != NULL)
			{
                *fileName = msf_cmmn_strdup(MSF_MODID_SMA, objInfo->fileName);
			} /* if */
			/* copy the boundary pointer */
            *boundary = objInfo->boundary;

			return TRUE;
        } 
        else
        {
            objInfo = objInfo->next;
        } /* if */
    } /* while */
    return FALSE;
} /* getObjectnfo */
#endif 

/*!\brief Returns the selected item in a menu.
 *
 * \return The item that is curently selected or -1 if no selected item could
 *         be extracted.
 *****************************************************************************/
static int getSlideMenuItem(void)
{
    int index;
    if (0 == smaSlideMenu.menuHandle)
        return -1;
    index = widgetGetSelected(smaSlideMenu.menuHandle);
    if ((index < 0) || (index >= SMA_SLIDE_MENU_NO_OF_ITEMS))
        return -1;
    return smaSlideMenu.listItems[index];
} /* getSlideMenuItem */



/*!\brief Sets focus on the slide form.
 *
 * \return The result of the operation
 *****************************************************************************/
SmaResult showSlideForm(void)
{
    SmaResult result = SMA_RESULT_OK;
    SmaPlayerInfo   *playerInfo = getPlayerInfo();

    if (smaSlideForm.displayWaitingAnimation)
    {
        HDIa_widgetExtCloseTransitionAnimation();
        smaSlideForm.displayWaitingAnimation = FALSE;
    }

    if(playerInfo->noOfSlides > 1)  /* Register left/right key */
    {
        MSF_BOOL left = FALSE, right = FALSE;

        /* Left / Right arrow indicator */
        if(playerInfo->currentSlide == SMA_FIRST_SLIDE)
        {
            right = TRUE;
        }
        else if(playerInfo->currentSlide + 1 >= playerInfo->noOfSlides)
        {
            left = TRUE;
        }
        else
        {
            left = right = TRUE;
        }
        
        HDIa_widgetExtFormSetArrowIndication(smaSlideForm.formHandle, left, right, FALSE, FALSE);
    }

#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
    if (playerInfo->isPlaying && smaSlideForm.audioHandle != 0)
    {
        HDIa_widgetExtFromSetAudioCallBack(smaSlideForm.formHandle, playAudioObjectCallback);
        widget_enable_status_bar(WIDGET_STATUS_BAR_SOUND_IND);
    }
#endif

    if (!MSF_WIDGET_HAS_FOCUS(smaSlideForm.formHandle))
    {
        if (-1 == MSF_WIDGET_SET_IN_FOCUS (smaSlideForm.formHandle, TRUE))
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_EC79487E6188F37329D2960933A4A729, "SMA: "
                "unable to set form in focus in widgetAction\n"));
            result = SMA_RESULT_ERROR;
            EXIT_SMIL_PLAYER(result);
        } /* if */
        else
        {
#ifndef WIDGET_SLIDING_SMIL_SUPPORT
			/* Focus controlled by widget */
            (void)MSF_WIDGET_SET_IN_FOCUS(smaSlideForm.stringGadgetHandle, TRUE);
#endif /* ~WIDGET_SLIDING_SMIL_SUPPORT */
        }
    } /* if */

#ifdef __UNIFIED_COMPOSER_SUPPORT__
        if(MMA_IS_UNIFIED_COMPOSER_ACTIVE() == TRUE)  /* SMA notify UC that it took over the screen */
        {
            void *sig;
            sig = MSF_SIGNAL_CREATE (SMA_SIG_PLAY_SMIL_IND, MSF_MODID_SMA, playerInfo->sourceModule, 0);
            MSF_SIGNAL_SEND (sig);
        }
#endif

    HDIa_widgetExtRegisterSwitchWidgetScreenCallback(smaInterruptHandler);
    return result;
} /* showSlideForm */



/*!\brief Sets focus on the slide menu.
 *
 * \return The result of the operation
 *****************************************************************************/
SmaResult showSlideMenu(void)
{
    SmaResult result = SMA_RESULT_OK;

    if (-1 == MSF_WIDGET_CHOICE_SET_ELEM_STATE(smaSlideMenu.menuHandle , 0, 
        MSF_CHOICE_ELEMENT_SELECTED))
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_SMA, SAUI_C59227293D7C67E8AEDF5107C67F0F7B, "SMA: "
            "unable to set menu in focus\n"));
        result = SMA_RESULT_ERROR;
    }
    (void)MSF_WIDGET_SET_IN_FOCUS(smaScreen.screenHandle, TRUE);
    (void)MSF_WIDGET_SET_IN_FOCUS (smaSlideMenu.menuHandle , TRUE);

    return result;
} /* showSlideMenu */


/*!\brief Adds a item at the end of a previously created menu.
 *
 * \param itemStrHandle The string that are displayed to the user.
 * \param conextValue A value that vill be returned when meaGetNavMenuItem is
 *                    called.
 * \return TRUE if the item is genereted successfully, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL addSlideMenuItem(MsfStringHandle itemStrHandle, int contextValue)
{
    if (smaSlideMenu.listIndex >= SMA_SLIDE_MENU_NO_OF_ITEMS)
        return FALSE;
#ifdef WAP_SUPPORT
    if (-1 == MSF_WIDGET_CHOICE_SET_ELEMENT(smaSlideMenu.menuHandle, 
        smaSlideMenu.listIndex, itemStrHandle, SMA_GET_STR_ID(SMA_STR_ID_EMPTY_STRING), 
        smaGetListNumImage(smaSlideMenu.listIndex), 0, TRUE))
#else
    if (-1 == MSF_WIDGET_CHOICE_SET_ELEMENT(smaSlideMenu.menuHandle, 
        smaSlideMenu.listIndex, itemStrHandle, 
        SMA_GET_STR_ID(SMA_STR_ID_EMPTY_STRING), 0, 0, TRUE))
#endif /* WAP_SUPPORT */
        return FALSE;
    smaSlideMenu.listItems[smaSlideMenu.listIndex] = contextValue;
    smaSlideMenu.listIndex++;
    return TRUE;
} /* addSlideMenuItem */


/*!
 * \brief Initiates data structures for the navigation menu.
 *
 *****************************************************************************/
static void initSlideMenu(void)
{
    
	memset(&smaSlideMenu, 0, sizeof(SmaSlideMenuView));
} /* initSlideMenu */

/*!
 * \brief Returns the size of the display.
 *
 * \return size of the display
 *****************************************************************************/
void getSlideDisplaySize(MsfSize *size)
{
    (void)MSF_WIDGET_WINDOW_SPECIFIC_SIZE(smaSlideForm.formHandle, size, 0);
} /* getSlideDisplaySize */

/*!
* \brief Gets the screen handle of the main screen.
*
* \return The screen handle of the main screen, if no screen handle is 
*         available 0 is returned.
*****************************************************************************/
MsfScreenHandle smaGetScreenHandle()
{
    return smaScreen.screenHandle;
} /* smaGetScreenHandle */

/*\brief Returns the position for widget placemnt left, top.
 *
 *\return A pointer to a MsfPostion = {0,0}.
 *****************************************************************************/
MsfPosition *smaGetPosLeftTop()
{
    return (MsfPosition *)&posLeftTop;
} /* *smaGetPosLeftTop */

/*!
 * \brief Binds a window the the SMA screen handle and sets the window in 
 *        focus.
 *
 * \param WindowHandle The handle of the window to show.
 * \param pos A pointer to the position the window should be displayed.
 * \return TRUE if the operation was successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL smaBindAndShowWindow(MsfWindowHandle windowHandle, const MsfPosition *pos)
{
    if (-1 != MSF_WIDGET_SCREEN_ADD_WINDOW(smaGetScreenHandle(), 
        windowHandle, (MsfPosition *)pos, 0, 0))
    {
        (void)MSF_WIDGET_SET_IN_FOCUS(smaGetScreenHandle(), TRUE);
        (void)MSF_WIDGET_SET_IN_FOCUS(windowHandle, TRUE);
        return TRUE;
    }
    else
    {
        return FALSE;
    } /* if */
} /* smaBindAndShowWindow */


/*! \brief Handles a DRM object.
 * \return TRUE on OK else FALSE
 *****************************************************************************/
MSF_BOOL displayDrmObject(char *pipePath, const SmaObjectInfo *objectInfo)
{
    unsigned int i;
    const SmaMediaTypeItem *items;
    MsfImageHandle imageHandle;
	MsfImageHandle videoHandle;
    MsfSoundHandle soundHandle;
    SlsMediaType mediaType;
	const char *mimeType;
	MsfCreateData createData;
    MSF_BOOL result;

    switch(objectInfo->type)
    {
	case SLS_OBJECT_TYPE_AUDIO:
        mediaType = objectInfo->info.audio.type;
        break;
    case SLS_OBJECT_TYPE_IMAGE:
        mediaType = objectInfo->info.image.type;
        break;
	case SLS_OBJECT_TYPE_VIDEO:	
		mediaType = objectInfo->info.video.type;
        break;
    case SLS_OBJECT_TYPE_TEXT:
        mediaType = objectInfo->info.text.type;
        break;
	case SLS_OBJECT_TYPE_DRM:
    case SLS_OBJECT_TYPE_ATTACMENT:
	default:
        return FALSE;
    }

    items = smaGetSupportedMediaTypes();
    i = 0;
    while(SLS_NOT_USED != items[i].slsMediaType)
    {
        if (items[i].slsMediaType == mediaType)
        {
            break;
        } 
        ++i;
    }
    if (items[i].slsMediaType == SLS_NOT_USED)
    {
        return FALSE;
    }
    switch(items[i].slsObjectType)
    {
    case SLS_OBJECT_TYPE_IMAGE:
        if (0 == (imageHandle = MSF_WIDGET_IMAGE_CREATE_RESOURCE(MSF_MODID_SMA,
            pipePath, MsfResourcePipe,  items[i].msfFormat.image)))
        {
            return FALSE;
        }
        result = displayImageObject(objectInfo, imageHandle);
        
        if (imageHandle != 0)
        {
            (void)MSF_WIDGET_RELEASE(imageHandle);
            imageHandle = 0;
        } /* if */
        
        return result;
	
	case SLS_OBJECT_TYPE_VIDEO:	
		mimeType = convertSlsToMimeType(objectInfo->info.video.type);
		if (mimeType == NULL)
		{
			return FALSE;
		} /* if */
		
		createData.resource = SMA_PIPE_NAME;

		if (0 == (videoHandle = MSF_WIDGET_IMAGE_CREATE_FORMAT(MSF_MODID_SMA,
			&createData, mimeType, MsfResourcePipe, 0)))
        {
            return FALSE;
        }
        result = displayImageObject(objectInfo, videoHandle);
        
        if (videoHandle != 0)
        {
            (void)MSF_WIDGET_RELEASE(videoHandle);
            videoHandle = 0;
        } /* if */
        return result;
    case SLS_OBJECT_TYPE_AUDIO:
        if (0 == (soundHandle = MSF_WIDGET_SOUND_CREATE_RESOURCE(MSF_MODID_SMA,
            pipePath, MsfResourcePipe,  items[i].msfFormat.audio)))
        {
            return FALSE;
        }
        return playAudioObject(&(objectInfo->info.audio), NULL, 0, FALSE, 
            soundHandle);

    case SLS_OBJECT_TYPE_TEXT:
        /* The text is provided as a buffer, i.e., not handled here */
        break;
	case SLS_OBJECT_TYPE_DRM:	
	default:		
		return FALSE;
    } /* switch */
    return FALSE;
} /* displayDrmObject */

/*! \brief 
 *
 * \return The type of media that is currently "selected", or 
 *         MEA_MEDIA_GROUP_NONE if no object is selected.
 *****************************************************************************/
void smaHandleEvent(MsfEventType event, MSF_UINT32 handle)
{
    MSF_BOOL lostFocus;
    (void)handle;
    if (MsfKey_Down == event || MsfKey_Up == event)
    {
        if (smaSlideForm.currentGadget == smaSlideForm.altStringGadgetHandle) 
        {
            (void)smtrRedraw(smaSlideForm.altStringGadgetInstance, event, 
                &lostFocus);
        }
        else
        {
            (void)smtrRedraw(smaSlideForm.stringGadgetInstance, event, 
                &lostFocus);
        }
        /* Check if we lost focus and if we have at least one more object
         * on the form we can give control to high level API */
        if (lostFocus)
        {
            if (smaSlideForm.currentGadget == 
                smaSlideForm.altStringGadgetHandle) 
            {
                if (smaSlideForm.stringGadgetHandle || 
                    smaSlideForm.imageGadgetHandle) 
                {
                    (void)smaDeleteUserEvent(smaSlideForm.formHandle, 
                        MsfKey_Down);
                    (void)smaDeleteUserEvent(smaSlideForm.formHandle, 
                        MsfKey_Up);
                }
            }
            else
            {
                if (smaSlideForm.altStringGadgetHandle || 
                    smaSlideForm.imageGadgetHandle) 
                {
                    (void)smaDeleteUserEvent(smaSlideForm.formHandle, 
                        MsfKey_Down);
                    (void)smaDeleteUserEvent(smaSlideForm.formHandle, 
                        MsfKey_Up);
                }
            }
        }
        else
        {
            smtrFreeSmtrLinkEntry(&smaSlideForm.selectedLink);
            if (smaSlideForm.currentGadget == 
                smaSlideForm.altStringGadgetHandle) 
            {
                (void)smtrHasActiveLink(smaSlideForm.altStringGadgetInstance,
                    &smaSlideForm.selectedLink);            
            }
            else
            {
                (void)smtrHasActiveLink(smaSlideForm.stringGadgetInstance,
                    &smaSlideForm.selectedLink);            
            }
        }
    }
}

/*! \brief 
 *
 * \return The type of media that is currently "selected", or 
 *         MEA_MEDIA_GROUP_NONE if no object is selected.
 *****************************************************************************/
void smaHandleNotif(MsfNotificationType notif, MSF_UINT32 handle)
{
    if (MsfNotifyFocus == notif) 
    {
        /* Register user events */
        (void)smaRegisterUserEvent(smaSlideForm.formHandle, MsfKey_Down, NULL, 
            SMA_FSM_SLIDE, SMA_SIG_EVENT_KEY_DOWN);
        (void)smaRegisterUserEvent(smaSlideForm.formHandle, MsfKey_Up, NULL, 
            SMA_FSM_SLIDE, SMA_SIG_EVENT_KEY_UP);
        
        smaSlideForm.currentGadget = handle;
        smtrFreeSmtrLinkEntry(&smaSlideForm.selectedLink);
        if (handle == smaSlideForm.altStringGadgetHandle) 
        {
            (void)smtrHasActiveLink(smaSlideForm.altStringGadgetInstance,
                &smaSlideForm.selectedLink);
        }
        else
        {
            (void)smtrHasActiveLink(smaSlideForm.stringGadgetInstance,
                &smaSlideForm.selectedLink);
        }
    }
    else if (MsfNotifyLostFocus == notif)
    {
        smaSlideForm.currentGadget = 0;
        (void)smaDeleteUserEvent(smaSlideForm.formHandle, MsfKey_Down);
        (void)smaDeleteUserEvent(smaSlideForm.formHandle, MsfKey_Up);        
    }
}


/*!\brief Creates a string handle.
 *
 * \param str The content of the string to create.
 *****************************************************************************/
MsfStringHandle smaCreateString(const char *str)
{
    if ( (NULL != str) && (0 != strlen(str)))
    {
        return MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, str, MsfUtf8, 
            (int)(strlen(str) + 1), 0);
    }
    else
    {
        return MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, (char *)"", MsfUtf8, 
            1, 0);
    } /* if */
} /* smaCreateString */


/*!
 * \brief Finds the first selected choice index.
 *
 * \param choiceHandle The handle of a choiceGroup.
 * \return The index of the first selected item, -1 if no item is selected.
 *          
 *****************************************************************************/
MSF_INT32 smaGetSelectedChoiceIndex(MSF_UINT32 choiceHandle)
{
    MSF_INT32 i;
	int count;

    if (0 == choiceHandle)
        return -1;
    count = MSF_WIDGET_CHOICE_SIZE(choiceHandle);
    for (i=0; i < count; i++)
    {
        if (MSF_CHOICE_ELEMENT_SELECTED & MSF_WIDGET_CHOICE_GET_ELEM_STATE(
            choiceHandle, i))
            return i;
    }
    return -1;
} /* smaGetSelectedChoiceIndex */

void smaUiShowWaitScreen(void)
{
    if (smaSlideForm.displayWaitingAnimation == TRUE)
        return;
    
    HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
    smaSlideForm.displayWaitingAnimation = TRUE;
}

void smaUiRemoveWaitScreen(void)
{
    HDIa_widgetExtCloseTransitionAnimation();
    smaSlideForm.displayWaitingAnimation = FALSE;    
}

#if defined(SMA_GET_TEXT_TOTAL_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)

#define QUANTUM_IN_TICKS              (KAL_TICKS_1_SEC /4)
#if defined( __MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)//041205 Calvin modified
#define SAUI_BASELINE_SIZE        (2)
#else
#define SAUI_BASELINE_SIZE        (0)
#endif
#define IS_NEWLINE(c) ((c)==0x0A||(c)==0x0D)

extern void SetSMILTotalTextHeightValue(int totalHeight);
extern char *smtrGetStringBufferFromHandle(MsfStringHandle strHandle);

MSF_BOOL smaUiCreateGetTextHeightInst(const SmaObjectInfo *object, const char* text, MSF_UINT32 len)
{
    MsfFont font;
    int tmp;
    int fontHeight;
    MsfSize     gadgetSize = {0,0};
    MsfPosition gadgetPosition = {0,0}; 
    
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_94AF8E4E6FB9E0D34BFE3D9A4D5491F2, "[TEXT HEIGHT] smaUiCreateGetTextHeightInst\n"));
    
    if (!text || !object)
    {
        ASSERT(0);
        return FALSE;
    }

    saUiGetTextHeightInst = SMA_ALLOC(sizeof(SmaUiGetTextHeightInstance));
    if (!saUiGetTextHeightInst)
    {
        ASSERT(0);
        return FALSE;
    }
    memset(saUiGetTextHeightInst, 0, sizeof(SmaUiGetTextHeightInstance));

    setGadgetRegion(&gadgetSize, &gadgetPosition, object);
    if (gadgetSize.height == 0 || gadgetSize.width == 0)
    {
        /* size if 0 so nothing will be shown. */
        SetSMILTotalTextHeightValue(-1);
        return TRUE;
    }
    
    /* text area size*/
    saUiGetTextHeightInst->maxSize.width = (MSF_INT16)gadgetSize.width - 
                        (2 * SMA_TEXT_GADGET_PADDING);
    saUiGetTextHeightInst->maxSize.height = (MSF_INT16)gadgetSize.height;
    
/*   #ifdef __MMI_TOUCH_SCREEN__
   uiMobGetTextHeightInst->maxSize.height = (MSF_INT16)(meaUiMobWindow->displaySize.height -
        MEA_MOB_MARKER_SIZE);
   #else
   uiMobGetTextHeightInst->maxSize.height = (MSF_INT16)(meaUiMobWindow->displaySize.height -
        MEA_MOB_MARKER_SIZE);
   #endif
*/
    
    /* create string*/
    if (0 == (saUiGetTextHeightInst->stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, 
        text, MsfUtf8, len + 1, 0)))
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_CB08113948E51950CC53B4E588956FDE, "[TEXT HEIGHT] create string failed\n"));
        return FALSE;
    }

    /* get line height*/
    if (MSF_WIDGET_GET_FONT(saUiGetTextHeightInst->stringHandle, &font) < 0) 
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_02DE5D9A5FB93248E8572F8AA5A3A7C6, "[TEXT HEIGHT] get font failed\n"));
        (void)MSF_WIDGET_RELEASE(saUiGetTextHeightInst->stringHandle);
        saUiGetTextHeightInst->stringHandle = 0;
        return FALSE;
    }

    /* text info*/
    saUiGetTextHeightInst->text = smtrGetStringBufferFromHandle(saUiGetTextHeightInst->stringHandle);
    /*saUiGetTextHeightInst->textLen = strlen(saUiGetTextHeightInst->text);*/
    saUiGetTextHeightInst->bytesRead = MSF_WIDGET_STRING_GET_LENGTH(saUiGetTextHeightInst->stringHandle, 0, MsfUtf8);
    
    /* string pos info*/
    saUiGetTextHeightInst->strPos = 0;
    saUiGetTextHeightInst->tPos = saUiGetTextHeightInst->text;
    saUiGetTextHeightInst->newStringStart = saUiGetTextHeightInst->text;

    (void)MSF_WIDGET_RELEASE(saUiGetTextHeightInst->stringHandle);
        saUiGetTextHeightInst->stringHandle = 0;
        
    if (MSF_WIDGET_FONT_GET_VALUES(&font, &tmp, &fontHeight, &tmp) < 0)
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_07F13BEA124FC0AFA63C6DABE7031A83, "[TEXT HEIGHT] get font values failed\n"));
        
        return FALSE;
    }
    
    /*get one-line height*/
    saUiGetTextHeightInst->onelineHeight = fontHeight + SAUI_BASELINE_SIZE;

    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_317CA9D026259AC9B99F2D57E2134C77, "[TEXT HEIGHT] inst ok\n"));
    
    return TRUE;
}

void smaUiDeleteGetTextHeightInst(void)
{
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_6ECE80FFC8E2DA441B5CC726AA11E93A, "[TEXT HEIGHT] smaUiDeleteGetTextHeightInst\n"));
    
    if (!saUiGetTextHeightInst)
    {
        return;
    }

    if (saUiGetTextHeightInst->text != NULL)
    {
        SMA_FREE(saUiGetTextHeightInst->text);
    }
    if (saUiGetTextHeightInst->stringHandle != 0)
    {
        (void)MSF_WIDGET_RELEASE(saUiGetTextHeightInst->stringHandle);
    }
    MSF_TIMER_RESET (MSF_MODID_SMA, SMA_GET_TOTAL_TEXT_HEIGHT_TIMER_ID);

    SMA_FREE(saUiGetTextHeightInst);
    saUiGetTextHeightInst = NULL;
}
#if 0 /* to avoid compile warning */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
static char* smaUiFindNewLine(char *strBuf, int *len)
{
    char *p = NULL;
    char *old = NULL;
    
    if (!strBuf)
        return NULL;

    *len = 0;
    p = strBuf;
    
    while(p && (*p != 0))
    {
        if (IS_NEWLINE(*p)) /* find it*/
        {
            *len = 1;

            /* Check if the next is also a new line*/
            if ((*(p + 1) != 0) && IS_NEWLINE(*(p + 1))) 
            {
                *len = 2;
            }
            return p;
        }

        old = p;
        p = msf_cmmn_utf8_str_incr(p, 1);
        /* Avoid infinite loops */
        p += (old == p ? 1 : 0); 
        while ((old < p) && (*old != 0))
        {
            old++;
        }
        if (*old == 0)
        {
            break;
        }
    } /* while(p)*/

    return NULL;
}

MSF_BOOL smaUiGetTextHeight(void)
{
    int lastIndex, visibleChars, tmp;
    kal_uint32 last_ticks, ticks;
    
    if (!saUiGetTextHeightInst)
    {
        return TRUE;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                SAUI_F71C9A9C41E8FB7FB4B47D65B5013D99, "!!!!!!!!!!!!!!!!!!!!![TEXT HEIGHT] smaUiGetTextHeight, index(%d)/total(%d)\n",
                saUiGetTextHeightInst->index, saUiGetTextHeightInst->textLen));

    kal_get_time(&last_ticks);

    do
    {
        kal_get_time(&ticks);
        if (ticks > last_ticks)
        {
            if (ticks - last_ticks > QUANTUM_IN_TICKS)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                    SAUI_14F24D5E9140A3D7C5497B64318BDD42, "[TEXT HEIGHT] take too long the time, return FALSE here1\n"));
                return FALSE;
            }
        }
        else
        {
            last_ticks = ticks;
        }

        /* Create string handle at first*/
        if (saUiGetTextHeightInst->stringHandle == 0)
        {
            saUiGetTextHeightInst->rnPos = smaUiFindNewLine(saUiGetTextHeightInst->newStringStart,
                &saUiGetTextHeightInst->lenOfRN);

            if (!saUiGetTextHeightInst->rnPos) /* No new line found*/
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_54360A559A49040809AB122413017673, "[TEXT HEIGHT] no new line found\n"));

                /* Create string handle by total texts left*/
                if (0 == (saUiGetTextHeightInst->stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, 
                    saUiGetTextHeightInst->newStringStart, MsfUtf8, 0, 0)))
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_CB08113948E51950CC53B4E588956FDE, "[TEXT HEIGHT] create string failed\n"));
                    return TRUE;
                }
                saUiGetTextHeightInst->tmpRN = 0;
            }
            else /* Find a new line*/
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_9E3DA5FA91EE0F98073CE57E7C9C674C, "[TEXT HEIGHT] new line found\n"));

                /* Starting by a new line*/
                if (saUiGetTextHeightInst->rnPos == saUiGetTextHeightInst->newStringStart)
                {
                    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_9C7A0645D90FA62578C22B58B61B13AC, "[TEXT HEIGHT] starting by a new line, hasNormalChar=%d\n", saUiGetTextHeightInst->hasNormalChar));

                    /* Jump over new line*/
                    saUiGetTextHeightInst->newStringStart += saUiGetTextHeightInst->lenOfRN;
                    /* Jump to next string start*/
                    saUiGetTextHeightInst->strPos = saUiGetTextHeightInst->newStringStart - 
                        saUiGetTextHeightInst->text;
                    saUiGetTextHeightInst->tPos = saUiGetTextHeightInst->newStringStart;
                
                    if (saUiGetTextHeightInst->hasNormalChar)
                    {
                        if (IS_NEWLINE(*saUiGetTextHeightInst->newStringStart))
                        {
                            saUiGetTextHeightInst->totalHeight = (saUiGetTextHeightInst->totalHeight + 
			                    saUiGetTextHeightInst->onelineHeight);
                        }
                    }
                    else
                    {
                        saUiGetTextHeightInst->totalHeight = (saUiGetTextHeightInst->totalHeight + 
			                    saUiGetTextHeightInst->onelineHeight);
                    }

                    continue;
                }

                saUiGetTextHeightInst->tmpRN = *(saUiGetTextHeightInst->rnPos + saUiGetTextHeightInst->lenOfRN);
                *(saUiGetTextHeightInst->rnPos + saUiGetTextHeightInst->lenOfRN) = 0;
                saUiGetTextHeightInst->hasNormalChar = TRUE;

                /* Create string handle by texts until new line*/
                if (0 == (saUiGetTextHeightInst->stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_SMA, 
                    saUiGetTextHeightInst->newStringStart, MsfUtf8, 0, 0)))
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_955AE17915ABF9CD8DEF9338256E8FEE, "[TEXT HEIGHT] create string failed1\n"));
                    return TRUE;
                }

                saUiGetTextHeightInst->strPos = saUiGetTextHeightInst->newStringStart - 
                    saUiGetTextHeightInst->text;
                saUiGetTextHeightInst->tPos = saUiGetTextHeightInst->newStringStart;
            }

            saUiGetTextHeightInst->textLen = MSF_WIDGET_STRING_GET_LENGTH(saUiGetTextHeightInst->stringHandle, 0, MsfUtf8);
            saUiGetTextHeightInst->index = 0; 
        }
        
        if (saUiGetTextHeightInst->index < saUiGetTextHeightInst->textLen)
        {
            do 
            {
                kal_get_time(&ticks);
                if (ticks > last_ticks)
                {
                    if (ticks - last_ticks > QUANTUM_IN_TICKS)
                    {
                        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                            SAUI_2E49FB3E93D51BAA78E10F4BDE6FA41B, "[TEXT HEIGHT] take too long the time, return FALSE here\n"));
                        return FALSE;
                    }
                }
                else
                {
                    last_ticks = ticks;
                }
            
			    lastIndex = saUiGetTextHeightInst->index;
			    /* oneLineTextHeight = fontHeight + SMTR_BASELINE_SIZE */
			    saUiGetTextHeightInst->totalHeight = (saUiGetTextHeightInst->totalHeight + 
			            saUiGetTextHeightInst->onelineHeight);
			    /* Check how many characters that can be displayed */
        
			    if (MSF_WIDGET_STRING_GET_VISIBLE(saUiGetTextHeightInst->stringHandle, 0, 
                            &saUiGetTextHeightInst->maxSize, 
				    saUiGetTextHeightInst->index, 1, &visibleChars, &tmp, &tmp) < 0)
			    {
			        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_BEB1067FC361961DA9DECBB4D2C467BA, "[TEXT HEIGHT] get visible failed\n"));
				    return FALSE;
			    }
			    /* Check for new-line characters */
/*			    if (0 <= (nextIndex = smaUiNewLineExists(saUiGetTextHeightInst->strPos, visibleChars, &tmp, 
				    &saUiGetTextHeightInst->strPos))) 
			    {
				    visibleChars = nextIndex;
				    saUiGetTextHeightInst->index += visibleChars + tmp;
				    saUiGetTextHeightInst->strPos += tmp;
				    continue;
			    }
			    else*/
			    {
				    saUiGetTextHeightInst->tPos = &saUiGetTextHeightInst->text[saUiGetTextHeightInst->strPos];
				    saUiGetTextHeightInst->tPos = msf_cmmn_utf8_str_incr(saUiGetTextHeightInst->tPos, visibleChars);
				    saUiGetTextHeightInst->strPos = (saUiGetTextHeightInst->tPos - 
                                        &saUiGetTextHeightInst->text[saUiGetTextHeightInst->strPos]) + 
                                        saUiGetTextHeightInst->strPos;
			    }
			    /* Prevent infinite loops */
			    if (!visibleChars) 
			    {
			        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_5CD2D56A414E5882E967A16D69FB5358, "[TEXT HEIGHT] !visibleChars\n"));
				    break;
			    }
			    /* NOTE! If links are rendered much different than the text we need
			     * to take that extra size into account when calculating the size */

			    saUiGetTextHeightInst->index += visibleChars;
                if (IS_NEWLINE(*(saUiGetTextHeightInst->tPos - 1)) && IS_NEWLINE(*(saUiGetTextHeightInst->tPos)))
                {
                    break;
                }
    		    /* Iterate until all characters are visible */
		    } while (saUiGetTextHeightInst->index < saUiGetTextHeightInst->textLen);
	    }

        if (saUiGetTextHeightInst->stringHandle)
        {
            (void)MSF_WIDGET_RELEASE(saUiGetTextHeightInst->stringHandle);
            saUiGetTextHeightInst->stringHandle = 0;
        }

        if (saUiGetTextHeightInst->tmpRN != 0) /* Has new line*/
        {
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_410EC4B27E5CF3BDC967C8EB4391991C, "[TEXT HEIGHT] had a new line\n"));

            /* Set back rnPos value*/
            if (saUiGetTextHeightInst->rnPos + saUiGetTextHeightInst->lenOfRN)
            {
                *(saUiGetTextHeightInst->rnPos + saUiGetTextHeightInst->lenOfRN) = saUiGetTextHeightInst->tmpRN;
            }
            /* Set new string start pos*/
            saUiGetTextHeightInst->newStringStart = 
                saUiGetTextHeightInst->rnPos + saUiGetTextHeightInst->lenOfRN;

            if (IS_NEWLINE(*saUiGetTextHeightInst->newStringStart))
            {
                saUiGetTextHeightInst->totalHeight = (saUiGetTextHeightInst->totalHeight + 
			        saUiGetTextHeightInst->onelineHeight);
            }
        }
        else
        {
            break;
        }
    } while(*saUiGetTextHeightInst->newStringStart != 0); /* do, will continue if there are more texts*/
    
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
                        SAUI_6EEDA2AAB82BEFF8EC2F0EFC99E2B58B, "[TEXT HEIGHT] get total text height end\n"));
	return TRUE;
}

void smaUiSetTotalTextHeightValue(void)
{
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_00DC01B96C96392489E28DAD6D0F44D7, "[TEXT HEIGHT] smaUiSetTotalTextHeightValue\n"));

    if (!saUiGetTextHeightInst)
    {
        SetSMILTotalTextHeightValue(-1);
        return;
    }
    
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_8AA48D3547105328D6A24402512FB1F8, "[TEXT HEIGHT] totalHeight = %d\n", saUiGetTextHeightInst->totalHeight));

    SetSMILTotalTextHeightValue(saUiGetTextHeightInst->totalHeight);
}

MSF_UINT32 smaUiGetBytesRead(void)
{
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_085CF3554FAF82F66B27CACF0C75A7E6, "[TEXT HEIGHT] smaUiGetBytesRead\n"));
    if (!saUiGetTextHeightInst)
        return 0;

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA, 
            SAUI_F57676AFEB66648F6EFEEDE02A7F367D, "[TEXT HEIGHT] bytesRead=%d\n", saUiGetTextHeightInst->bytesRead));

    return saUiGetTextHeightInst->bytesRead;
}

#endif

#ifndef __UNIFIED_MSG_SUPPORT__
static void smaWriteMessage(const char *number)
{
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    extern void mms_address_insert_hdlr(char *address);
    int len = (widget_utf8_length((kal_uint8 *)number) + 1) * UCS2_ENCODING_LENGTH;
    char *str = SMA_ALLOC(len);
    widget_utf8_to_ucs2_string((kal_uint8 *)str, len, (kal_uint8 *)number);
    mms_address_insert_hdlr(str);
    MEA_FREE(str);

#else
    extern void meaMhWriteMessageByMail(const char *mail);
    meaMhWriteMessageByMail(number);
#endif
    EXIT_SMIL_PLAYER(SMA_RESULT_OK);
}
#endif

