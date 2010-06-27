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

/*******************************************************************************
 * Filename:
 * ---------
 *  PictureEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : PictureEditor.c

   PURPOSE     : Main functions of the Picture Editor application

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : Jan-13-2004

**************************************************************/
#include "MMI_include.h"

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
#include "PictureEditorDefs.h"
#include "PictureEditorDecl.h"
#include "PictureEditorProts.h"
#include "CustDataProts.h"
#include "MainMenuDef.h"
#include "CommonScreens.h"
#include "Downloaddefs.h"
#include "DownloadProtos.h"
#include "FileMgr.h"    /* Should include FileMgr.h before ProfileMgrGprot.h */
#include "SettingProfile.h"
#include "FunAndGamesDefs.h"
#include "ProfileGprots.h"
#include "FileManagerGProt.h"
#include "FileManagerDef.h"

/**********************Defines************************/

/**********************Local Variables************************/
static DYNIMAGEINFO gPicEditorInfo[MAXIMUM_PICTURE_EDITOR_IMAGES];
static S32 g_pe_color_index = 0;

static U8 nSelPEPenSetting;
static U8 nSelPEEditOpt;
static U8 nSelPEViewOpt;

static S32 nInlinePenSize = 0;
static S32 nInlinePenMoveFactor = 0;
static S32 nInlinePenColorIndex = 0;
static U8 *pInlinePenSizeList[MAX_TYPE_PEN_PIXEL];

#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 */
static U8 *pInlinePenMoveFactorList[MAX_TYPE_PEN_MOVE];
#endif 
static U8 *pInlinePenColorIndexList[MAX_TYPE_PEN_COLOR - 1];
static U8 inlinePERGBlist[MAX_TYPE_PEN_COLOR][3];
static U8 inlineCustomRGB[3];
static mmi_cat91_color_slider_enum highlighted_slider = MMI_CAT91_COLOR_SLIDER_RED_COLOR;

static InlineItem PicEditInLineItems[MAX_RESIZE_INLINE_EDIT];
static S32 nInlinePEScr = PE_SCR_2;
static U8 *pInlinePEScrList[MAX_TYPE_SCR_TYPE];
static U8 nInlinePEScrWidth[4 * ENCODING_LENGTH];
static U8 nInlinePEScrHeight[4 * ENCODING_LENGTH];

static U8 TempImageName[MAX_IMAGE_NAME_WIDTH];

/**********************Local Functions************************/
static void SavePicEditImageAndShowResult(void);
static void SavePicEditImage(void);
static void InputPicEditImageFileName(void);
static S32 SavePicEditImageDataBuff(void);
static void pe_return_to_editor(void);
static void entry_pe_editor_option(void);
static void highlight_pe_input_method(void);
static void highlight_pe_done(void);



/**********************Global Variables************************/
U16 gPEAttrib = 0;
U8 gPicEditCurrPic;
U8 gPicEditSelectedPic;
U8 gPEImageCount = 0;
U8 gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
S16 gPEImageWidth = PE_SCR_SIZE_2;
S16 gPEImageHeight = PE_SCR_SIZE_2;
S16 gPEImageWidth_bak = PE_SCR_SIZE_2;
S16 gPEImageHeight_bak = PE_SCR_SIZE_2;
MMI_BOOL gPEImageResized = MMI_FALSE;

/**********************Extern Variables************************/
extern PU8 gpPEBackupDataBuff;
extern PictureEditorPen *gpPicEditPen;
extern PictureEditorPen *gpPicEditBackupPen;
extern PicEditMarkBox gPicEditMark;
extern U8 *gpPEFileBuff;
extern U8 gPEBitsPerPixel;

/* 051605 Calvin added */
#if defined(__MMI_MAINLCD_240X320__)
extern U8 *gpPicEditFillColorIndex;
#endif 
/* Calvin end */


/*****************************************************************************
 * FUNCTION
 *  InitPictureEditor
 * DESCRIPTION
 *  Initializes the NVRAM buffer for Image Editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitPictureEditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitRedoUndoBuffers();
    ReadPicEditListFromNVRAM();
}


/*****************************************************************************
 * FUNCTION
 *  InitPicEditPen
 * DESCRIPTION
 *  Initializes the Image Editor Pen setting to default values
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitPicEditPen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPEAttrib &= ~(PE_IMAGE_EDIT | PE_UNDO_IMAGE | PE_ZOOM_IMAGE | PE_PEN_DOWN | PE_MARK_IMAGE | PE_COPY_IMAGE);
    gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
    nInlinePEScr = PE_SCR_2;
    gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_1;
    gpPicEditPen->penColorIndex = PE_COLOR_BLACK;
    gpPicEditPen->penBackgrdColorIndex = PE_COLOR_WHITE;
    gpPicEditPen->penMove = PIC_EDIT_PEN_MOVE_1;
#ifdef __MMI_TOUCH_SCREEN__
    gpPicEditPen->penContextSaved = MMI_FALSE;
#endif 

    gpPicEditBackupPen->penPixel = PIC_EDIT_PEN_PIXEL_1;
    gpPicEditBackupPen->penColorIndex = PE_COLOR_BLACK;
    gpPicEditBackupPen->penBackgrdColorIndex = PE_COLOR_WHITE;
    gpPicEditBackupPen->penMove = PIC_EDIT_PEN_MOVE_1;
#ifdef __MMI_TOUCH_SCREEN__
    gpPicEditBackupPen->penContextSaved = MMI_FALSE;
#endif 

#if defined(__MMI_MAINLCD_240X320__)
    *gpPicEditFillColorIndex = PE_COLOR_WHITE;
#endif 
    gPEColorRGB[PE_COLOR_CUSTOM_1] = 0x00408000;
    SetPicEditPenBoundary();
    SetPicEditPenAtCenter(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditSelectMenu
 * DESCRIPTION
 *  Entry function for image editor select image menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditSelectMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 jCount;
    DYNAMICINFO dynInfo;
    U8 *pPicEditList[MAXIMUM_PICTURE_EDITOR_IMAGES];
    S8 imagePath[100];
    S8 imageData[100 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitPicEditPen();
    EntryNewScreen(SCR_PE_SELECT_PIC_MENU, ExitScr4PicEditSelectMenu, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_SELECT_PIC_MENU);

    SetParentHandler(0);

    RegisterHighlightHandler(ChangePicEditSelectMenuSoftKey);
    ReadPicEditListFromNVRAM();

    if (guiBuffer == NULL)
    {
        dynInfo.DynInfoType = IMAGEINFO;
        dynInfo.DYNINFOUNION.ImageInfo = gPicEditorInfo;
        dynInfo.NoOfEntries = gPEImageCount;
        memset(imagePath, 0, sizeof(imagePath));
        sprintf(imagePath, "%c:\\", MMI_PUBLIC_DRV);
        mmi_asc_to_ucs2(imageData, imagePath);
        mmi_ucs2cat((S8*) imageData, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
        SyncPicEditFileSystem(imageData, &dynInfo);
    }

    /*
     * for (jCount=0; jCount<gPEImageCount; jCount++)
     * {
     * pPicEditList[jCount] = (U8*)gPicEditorInfo[jCount].ImageName;
     * }
     * 
     * for (jCount=gPEImageCount; jCount<MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
     * {
     * pPicEditList[jCount] = (U8*)GetString(STR_GLOBAL_EMPTY_LIST);
     * }
     */

    for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
    {
        if (((gPicEditorInfo[jCount].ImagesId >= (U16) PICTURE_EDITOR_IMAGE_BASE) &&
             (gPicEditorInfo[jCount].ImagesId <= PICTURE_EDITOR_IMAGE_BASE_END)))
        {
            pPicEditList[jCount] = (U8*) gPicEditorInfo[jCount].ImageName;
        }
        else
        {
            pPicEditList[jCount] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }

    ShowCategory84Screen(
        STR_PE_DRAW_PICTURE,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAXIMUM_PICTURE_EDITOR_IMAGES,
        (U8 **) pPicEditList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetExitHandler (SCR_PE_SELECT_PIC_MENU, ExitScr4PicEditSelectMenu); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditSelectMenu
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditSelectMenu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditSelectMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_SELECT_PIC_MENU;
    h.entryFuncPtr = EntryScr4PicEditSelectMenu;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  ChangePicEditSelectMenuSoftKey
 * DESCRIPTION
 *  Changes softkey according to the selected image
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePicEditSelectMenuSoftKey(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetPicEditCurrPic(nIndex);
    /* if(gPicEditCurrPic<gPEImageCount) */
    if (gPicEditorInfo[nIndex].ImagesId)
        /* if (((gPicEditorInfo[gPicEditCurrPic].ImagesId>=(U16)PICTURE_EDITOR_IMAGE_BASE)&&(gPicEditorInfo[gPicEditCurrPic].ImagesId<=PICTURE_EDITOR_IMAGE_BASE_END))) */
    {
        ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntryScr4PicEditShowImage, KEY_EVENT_UP);
        SetKeyHandler(EntryScr4PicEditShowImage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ADD, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntryPicEditAddPic, KEY_EVENT_UP);
        SetKeyHandler(EntryPicEditAddPic, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SET_PE_ADD_IMAGE(gPEAttrib);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryPicEditAddPic
 * DESCRIPTION
 *  Entry function for add image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPicEditAddPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitRedoUndoBuffers();
    InitPicEditPen();
    SetPicEditEmptyImageDataBuff();
    SavePEContext();
    SetCurrentImageParams();
    UNSET_PE_IMAGE_CHANGED(gPEAttrib);
    EntryScr4PicEditEditImage();
}


/*****************************************************************************
 * FUNCTION
 *  ShowPicEditPrevImage
 * DESCRIPTION
 *  Shows previous image on image viewing window
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPicEditPrevImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPEImageCount == 1)
    {
        return;
    }

    do
    {
        gPicEditCurrPic = gPicEditCurrPic ? gPicEditCurrPic - 1 : MAXIMUM_PICTURE_EDITOR_IMAGES - 1;
    } while (!gPicEditorInfo[gPicEditCurrPic].ImagesId);
    ShowPicEditImage();
}


/*****************************************************************************
 * FUNCTION
 *  ShowPicEditNextImage
 * DESCRIPTION
 *  Shows Next image on image viewing window
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPicEditNextImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPEImageCount == 1)
    {
        return;
    }

    do
    {
        gPicEditCurrPic = (gPicEditCurrPic == (MAXIMUM_PICTURE_EDITOR_IMAGES - 1)) ? 0 : gPicEditCurrPic + 1;
    } while (!gPicEditorInfo[gPicEditCurrPic].ImagesId);
    ShowPicEditImage();
}


/*****************************************************************************
 * FUNCTION
 *  ShowPicEditImage
 * DESCRIPTION
 *  Show image on view image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPicEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPicEditorInfo[gPicEditCurrPic].ImagesId)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(EntryScr4PicEditViewOpt, KEY_EVENT_UP);
        SetKeyHandler(EntryScr4PicEditViewOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetPicEditImageDataBuff(gPicEditorInfo[gPicEditCurrPic].ImageName);
    }
    else
    {
        ChangeLeftSoftkey((U16) NULL, (U16) NULL);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        nInlinePEScr = PE_SCR_2;
        SetPicEditPenBoundary();
        SetPicEditEmptyImageDataBuff();
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditViewOpt
 * DESCRIPTION
 *  Entry function for View image option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditViewOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;

    U16 nPEViewOptList[13];
    U16 noOfChildren;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    noOfChildren = GetNumOfChild(MENU_PE_VIEW_OPT);

    guiBuffer = GetCurrGuiBuffer(SCR_PE_VIEW_OPTION);

    /* ExecuteCurrExitHandler (); */
    EntryNewScreen(SCR_PE_VIEW_OPTION, ExitScr4PicEditViewOpt, NULL, NULL);
    GetSequenceStringIds(MENU_PE_VIEW_OPT, nPEViewOptList);
    SetParentHandler(MENU_PE_VIEW_OPT);

    SetHiliteHandler(MENU_PE_VIEW_OPT_EDIT, SelPEViewOptEdit);
    SetHiliteHandler(MENU_PE_VIEW_OPT_DELETE, SelPEViewOptDelete);
    SetHiliteHandler(MENU_PE_VIEW_OPT_DELETEALL, SelPEViewOptDeleteAll);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noOfChildren,
        nPEViewOptList,
        (PU16) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryPicEditViewOpt, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetExitHandler (SCR_PE_VIEW_OPTION, ExitScr4PicEditViewOpt); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditViewOpt
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditViewOpt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditViewOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_VIEW_OPTION;
    h.entryFuncPtr = EntryScr4PicEditViewOpt;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEViewOptEdit
 * DESCRIPTION
 *  Hilite handler for option screen of view image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEViewOptEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEViewOpt = SEL_PE_VIEW_OPT_EDIT;
}


/*****************************************************************************
 * FUNCTION
 *  SelPEViewOptDelete
 * DESCRIPTION
 *  Hilite handler for option screen of view image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEViewOptDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEViewOpt = SEL_PE_VIEW_OPT_DELETE;
}


/*****************************************************************************
 * FUNCTION
 *  SelPEViewOptDeleteAll
 * DESCRIPTION
 *  Hilite handler for option screen of view image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEViewOptDeleteAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEViewOpt = SEL_PE_VIEW_OPT_DELETEALL;
}


/*****************************************************************************
 * FUNCTION
 *  EntryPicEditViewOpt
 * DESCRIPTION
 *  Entry function depending of the selected option of view image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPicEditViewOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nSelPEViewOpt)
    {
        case SEL_PE_VIEW_OPT_EDIT:  /* Edit */
            UNSET_PE_ADD_IMAGE(gPEAttrib);
            InitRedoUndoBuffers();
            InitPicEditPen();
            if (SetPicEditImageDataBuff(gPicEditorInfo[gPicEditCurrPic].ImageName) == MMI_FALSE)
            {
                DisplayPopup((U8*) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_NO, 0, 1000, (U8) ERROR_TONE);
                break;
            }
            SavePEContext();
            SetCurrentImageParams();
            UNSET_PE_IMAGE_CHANGED(gPEAttrib);
            EntryScr4PicEditEditImage();
            break;
        case SEL_PE_VIEW_OPT_DELETE:    /* Delete */
            EntryScr4PicEditDeleteConfirm();
            break;
        case SEL_PE_VIEW_OPT_DELETEALL: /* Delete All */
            EntryScr4PicEditDeleteAllConfirm();
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditDeleteConfirm
 * DESCRIPTION
 *  Entry function for delete image confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditDeleteConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(PicEditDeleteImage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditDeleteConfirm
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditDeleteConfirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditDeleteConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;  /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    h.scrnID = SCR_PE_DELETE_CONFIRM;
    h.entryFuncPtr = EntryScr4PicEditDeleteConfirm;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  PicEditDeleteImage
 * DESCRIPTION
 *  Deletes the image and shows a pop up for success
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditDeleteImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SetDeletePicEditImage() == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            PE_NOTIFYDURATION,
            WARNING_TONE);
    }
    else
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
    }
    DeleteUptoScrID(SCR_PE_SELECT_PIC_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  SetDeletePicEditImage
 * DESCRIPTION
 *  Sets the image delete in nvram buffers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL SetDeletePicEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pFileName;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFileName = GetPictureEditorImageNameWithPathInFileSystem(gPicEditorInfo[gPicEditCurrPic].ImagesId);
    if (pFileName && FS_Delete((kal_wchar*)pFileName))
    {
        if (FS_Open((U16*) pFileName, FS_READ_ONLY) < 0)
        {
            DeletePictureEditorImage(gPicEditorInfo[gPicEditCurrPic].ImagesId);
            WritePicEditListToNVRAM();
            return MMI_TRUE;
        }
        PRINT_INFORMATION("Error Deleting File");
        return MMI_FALSE;
    }
    else
    {
        DeletePictureEditorImage(gPicEditorInfo[gPicEditCurrPic].ImagesId);
        WritePicEditListToNVRAM();
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditDeleteAllConfirm
 * DESCRIPTION
 *  Entry function  for delete all image confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditDeleteAllConfirm(void)
{
#if (0)
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
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_DELETE_ALL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(PicEditDeleteAllImages, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //      playRequestedTone(WARNING_TONE) ;
    //SetExitHandler(SCR_PE_DELETE_ALL_CONFIRM, ExitScr4PicEditDeleteAllConfirm);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditDeleteAllConfirm
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditDeleteAllConfirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditDeleteAllConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;  /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    h.scrnID = SCR_PE_DELETE_ALL_CONFIRM;
    h.entryFuncPtr = EntryScr4PicEditDeleteAllConfirm;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  PicEditDeleteAllImages
 * DESCRIPTION
 *  Calls a fucntion to delete all images and shows pop up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditDeleteAllImages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDeleteAllPicEditImage();
    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_PE_SELECT_PIC_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  SetDeleteAllPicEditImage
 * DESCRIPTION
 *  Sets NVRAM buffer for delete all images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetDeleteAllPicEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pFileName;
    U8 jCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
    {
        if (gPicEditorInfo[gPicEditCurrPic].ImagesId)
        {
            pFileName = GetPictureEditorImageNameWithPathInFileSystem(gPicEditorInfo[jCount].ImagesId);
            if (pFileName && FS_Delete((kal_wchar*)pFileName))
            {
                PRINT_INFORMATION("Error Deleting File");
            }
        }
    }
    memset(&gPicEditorInfo, '\0', NVRAM_PICTURE_EDITOR_SIZE);
    WritePicEditListToNVRAM();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditEditOpt
 * DESCRIPTION
 *  Entry function for Options screen for edit image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditEditOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;

    U16 nPEOptionList[13];
    U16 noOfChildren;
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = gPECurrentAction;

    if (!IS_PE_ZOOM_IMAGE(gPEAttrib))
    {
        if (!IS_PE_MARK_IMAGE(gPEAttrib))
        {
            if (!IS_PE_IMAGE_EDIT(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_1;
            }
            else if (!IS_PE_UNDO_IMAGE(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_2;
            }
            else
            {
                menuId = MENU_PE_EDIT_OPT_3;
            }
        }
        else
        {
            if (!IS_PE_COPY_IMAGE(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_4;
            }
            else if (!IS_PE_IMAGE_EDIT(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_5;
            }
            else if (!IS_PE_UNDO_IMAGE(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_6;
            }
            else
            {
                menuId = MENU_PE_EDIT_OPT_7;
            }
        }
    }
    else
    {
        if (!IS_PE_MARK_IMAGE(gPEAttrib))
        {
            if (!IS_PE_IMAGE_EDIT(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_8;
            }
            else if (!IS_PE_UNDO_IMAGE(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_9;
            }
            else
            {
                menuId = MENU_PE_EDIT_OPT_10;
            }
        }
        else
        {
            if (!IS_PE_COPY_IMAGE(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_11;
            }
            else if (!IS_PE_IMAGE_EDIT(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_12;
            }
            else if (!IS_PE_UNDO_IMAGE(gPEAttrib))
            {
                menuId = MENU_PE_EDIT_OPT_13;
            }
            else
            {
                menuId = MENU_PE_EDIT_OPT_14;
            }
        }
    }

    noOfChildren = GetNumOfChild(menuId);

    guiBuffer = GetCurrGuiBuffer(SCR_PE_EDIT_PIC_OPT);

    /* ExecuteCurrExitHandler (); */
    EntryNewScreen(SCR_PE_EDIT_PIC_OPT, ExitScr4PicEditEditOpt, NULL, NULL);

    GetSequenceStringIds(menuId, nPEOptionList);
    SetParentHandler(menuId);
    InitPicEditHiliteHandlers();
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noOfChildren,
        nPEOptionList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryPEEditOpt, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* SetExitHandler (SCR_PE_EDIT_PIC_OPT, ExitScr4PicEditEditOpt); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditEditOpt
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditEditOpt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditEditOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_EDIT_PIC_OPT;
    h.entryFuncPtr = EntryScr4PicEditEditOpt;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptSavePic
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptSavePic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_SAVE_PIC;
    SetKeyHandler(EntryPEEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptSavePicAs
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptSavePicAs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_SAVE_PIC_AS;
    SetKeyHandler(EntryPEEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptPenSetting
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptPenSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_PEN_SETTING;
    SetKeyHandler(EntryPEEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptFillPic
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptFillPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_FILL_PIC;
    SetKeyHandler(EntryPEEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptMark
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptMark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_MARK;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptCut
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptCut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_CUT;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptCopy
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptCopy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_COPY;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptPaste
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptPaste(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_PASTE;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptUndo
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptUndo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_UNDO;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptRedo
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptRedo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_REDO;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptZoom
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptZoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_ZOOM;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptFullSize
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptFullSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_FULL_SIZE;
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptResize
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptResize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_RESIZE;
    SetKeyHandler(EntryPEEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  SelPEEditOptHelp
 * DESCRIPTION
 *  Hilite handler fucntion for option screen of edit/draw image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SelPEEditOptHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEEditOpt = SEL_PE_EDIT_OPT_HELP;
    SetKeyHandler(EntryPEEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryPEEditOpt
 * DESCRIPTION
 *  Selects the entry functions depending on the option selected of image edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryPEEditOpt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nSelPEEditOpt)
    {
        case SEL_PE_EDIT_OPT_SAVE_PIC:  /* Save */
            gPECurrentAction = nSelPEEditOpt;
            SavePicEditImage();            
            break;
        case SEL_PE_EDIT_OPT_SAVE_PIC_AS:   /* Save As */
            gPECurrentAction = nSelPEEditOpt;
            EntryScr4PicEditSaveAs();
            break;
        case SEL_PE_EDIT_OPT_PEN_SETTING:   /* Pen Setting */
            EntryScr4PicEditPenSetting();
            break;
        case SEL_PE_EDIT_OPT_FILL_PIC:      /* Fill Picture */
            gPECurrentAction = nSelPEEditOpt;
            /* Pixtel patch */
            nInlinePenColorIndex = gpPicEditPen->penBackgrdColorIndex - 1;
            EntryScr4PicEditFillPic();
            break;
        case SEL_PE_EDIT_OPT_MARK:          /* Mark */
            gPECurrentAction = nSelPEEditOpt;
            gPicEditMark.minX = gpPicEditPen->penX;
            gPicEditMark.minY = gpPicEditPen->penY;
            gPicEditMark.maxX = gpPicEditPen->penX;
            gPicEditMark.maxY = gpPicEditPen->penY;
            UNSET_PE_PEN_DOWN(gPEAttrib);
            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_CUT:           /* Cut */
            gPECurrentAction = nSelPEEditOpt;
            SavePEContext();
            SaveDataBuffer();
            gpPicEditPen->penColorIndex = gpPicEditPen->penBackgrdColorIndex;
            PutPixtelInBuff(
                gPicEditMark.minX,
                gPicEditMark.minY,
                (U16) (gPicEditMark.maxX + 1),
                (U16) (gPicEditMark.maxY + 1),
                &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE]);
            gpPicEditPen->penColorIndex = gpPicEditBackupPen->penColorIndex;
            UNSET_PE_PEN_DOWN(gPEAttrib);
            SET_PE_IMAGE_EDIT(gPEAttrib);
            SET_PE_COPY_IMAGE(gPEAttrib);

            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_COPY:      /* Copy */
            gPECurrentAction = nSelPEEditOpt;
            UNSET_PE_PEN_DOWN(gPEAttrib);
            SaveDataBuffer();
            SET_PE_COPY_IMAGE(gPEAttrib);
            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_PASTE:     /* Paste */
            gPECurrentAction = nSelPEEditOpt;
            SavePEContext();
            PasteBoxInImageBuffer(&gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE], gpPEBackupDataBuff);
            UNSET_PE_PEN_DOWN(gPEAttrib);
            SET_PE_IMAGE_EDIT(gPEAttrib);
            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_UNDO:      /* Undo */
        case SEL_PE_EDIT_OPT_REDO:      /* Redo */
            gPECurrentAction = nSelPEEditOpt;
            ExchangePEContext();
            SetPicEditZoomWindow(TRUE);
            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_ZOOM:      /* Zoom */
            gPECurrentAction = nSelPEEditOpt;
            SetPicEditZoomWindow(TRUE);
            SET_PE_ZOOM_IMAGE(gPEAttrib);
            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_FULL_SIZE: /* Full Size */
            gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
            UNSET_PE_ZOOM_IMAGE(gPEAttrib);
            GoBackHistory();
            break;
        case SEL_PE_EDIT_OPT_RESIZE:    /* Resize */
            SetResizeInlineItemValues();
            EntryScr4PicEditScrResize();
            break;
        case SEL_PE_EDIT_OPT_HELP:      /* Help */
            EntryScr4PicEditHelp();
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PicEditCancelSaveAs
 * DESCRIPTION
 *  restore current pic if user cancel "save as" option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditCancelSaveAs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPicEditSelectedPic != gPicEditCurrPic)
    {
        gPicEditCurrPic = gPicEditSelectedPic;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditSaveAs
 * DESCRIPTION
 *  Entry function image editor select image menu for save as
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditSaveAs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 jCount;
    DYNAMICINFO dynInfo;
    U8 *pPicEditList[MAXIMUM_PICTURE_EDITOR_IMAGES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_PE_EDIT_SAVE_AS, ExitScr4PicEditSaveAs, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_EDIT_SAVE_AS);
    SetParentHandler(0);
    gPicEditSelectedPic = gPicEditCurrPic;
    RegisterHighlightHandler(SetPicEditCurrPic);
    ReadPicEditListFromNVRAM();

    if (guiBuffer == NULL)
    {
        dynInfo.DynInfoType = IMAGEINFO;
        dynInfo.DYNINFOUNION.ImageInfo = gPicEditorInfo;
        dynInfo.NoOfEntries = gPEImageCount;
        SyncPicEditFileSystem(PICTURE_EDITOR_PATH, &dynInfo);
    }

    /*
     * for (jCount=0; jCount<gPEImageCount; jCount++)
     * {
     * pPicEditList[jCount] = (U8*)gPicEditorInfo[jCount].ImageName;
     * }
     * 
     * for (jCount=gPEImageCount; jCount<MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
     * {
     * pPicEditList[jCount] = (U8*)GetString(STR_GLOBAL_EMPTY);
     * }
     */

    for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
    {
        if (((gPicEditorInfo[jCount].ImagesId >= (U16) PICTURE_EDITOR_IMAGE_BASE) &&
             (gPicEditorInfo[jCount].ImagesId <= PICTURE_EDITOR_IMAGE_BASE_END)))
        {
            pPicEditList[jCount] = (U8*) gPicEditorInfo[jCount].ImageName;
        }
        else
        {
            pPicEditList[jCount] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        }
    }

    ShowCategory84Screen(
        STR_PE_EDIT_OPT_SAVE_PIC_AS,
        MAIN_MENU_TITLE_FUNANDGAMES_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAXIMUM_PICTURE_EDITOR_IMAGES,
        (U8 **) pPicEditList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(PicEditSaveImageAs, KEY_EVENT_UP);
    SetRightSoftkeyFunction(PicEditCancelSaveAs, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* SetExitHandler (SCR_PE_EDIT_SAVE_AS, ExitScr4PicEditSaveAs); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditSaveAs
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditSaveAs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditSaveAs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_EDIT_SAVE_AS;
    h.entryFuncPtr = EntryScr4PicEditSaveAs;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditCurrPic
 * DESCRIPTION
 *  Sets the global varibale for current image
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditCurrPic(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Task # : %d", nIndex);
    gPicEditCurrPic = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  PicEditSaveImageAs
 * DESCRIPTION
 *  Saves Image and shows a pop up for success else if replace image, confirms for replacement
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditSaveImageAs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if(gPicEditCurrPic<gPEImageCount) */
    if (gPicEditorInfo[gPicEditCurrPic].ImagesId)
    {
        UNSET_PE_ADD_IMAGE(gPEAttrib);
        EntryScr4PicEditSaveAsConfirm();
    }
    else
    {
        SET_PE_ADD_IMAGE(gPEAttrib);
        SavePicEditImage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditSaveAsConfirm
 * DESCRIPTION
 *  Confirmation screen for confirming to replace selected image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditSaveAsConfirm(void)
{
#if (0)
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
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_PE_EDIT_OPT_REPLACE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ReplacePicEditSelectedImage, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackPicEditSaveAsConfirmHistory, KEY_EVENT_UP);

    /* playRequestedTone(WARNING_TONE) ; */

    /* SetExitHandler(SCR_PE_EDIT_SAVE_AS_CONFIRM, ExitScr4PicEditSaveAsConfirm); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditSaveAsConfirm
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditFillPicSaveConfirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditSaveAsConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;  /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    h.scrnID = SCR_PE_EDIT_SAVE_AS_CONFIRM;
    h.entryFuncPtr = EntryScr4PicEditSaveAsConfirm;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  GoBackPicEditSaveAsConfirmHistory
 * DESCRIPTION
 *  Go Back history function for the confirmation screen for Save As image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackPicEditSaveAsConfirmHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPicEditSelectedPic != gPicEditCurrPic)
    {
        if (!gPicEditorInfo[gPicEditSelectedPic].ImagesId)
        {
            SET_PE_ADD_IMAGE(gPEAttrib);
        }
        gPicEditCurrPic = gPicEditSelectedPic;
    }
    DeleteUptoScrID(SCR_PE_EDIT_PIC_OPT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ReplacePicEditSelectedImage
 * DESCRIPTION
 *  Replace selected image with the current image buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReplacePicEditSelectedImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SavePicEditImage();    
}


/*****************************************************************************
 * FUNCTION
 *  PicEditPenColorHiLiteHandler
 * DESCRIPTION
 *  hilight handler of category92
 * PARAMETERS
 *  index       [IN]        Selected color index
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditPenColorHiLiteHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pe_color_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditPenSettingInlineItemData
 * DESCRIPTION
 *  Setup inline item data for Pen Setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditPenSettingInlineItemData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&PicEditInLineItems[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&PicEditInLineItems[i++], (U8*) (get_string(STR_PE_PEN_SIZE)));

    SetInlineItemActivation(&PicEditInLineItems[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&PicEditInLineItems[i++], MAX_TYPE_PEN_PIXEL, pInlinePenSizeList, &nInlinePenSize);

#ifndef __MMI_TOUCH_SCREEN__
    SetInlineItemActivation(&PicEditInLineItems[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&PicEditInLineItems[i++], (PU8) (get_string(STR_PE_PEN_MOVE_FACTOR)));

    SetInlineItemActivation(&PicEditInLineItems[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&PicEditInLineItems[i++], MAX_TYPE_PEN_MOVE, pInlinePenMoveFactorList, &nInlinePenMoveFactor);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    SetInlineItemActivation(&PicEditInLineItems[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&PicEditInLineItems[i++], (PU8) (get_string(STR_PE_PEN_COLOR)));

    SetInlineItemActivation(&PicEditInLineItems[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &PicEditInLineItems[i],
        MAX_TYPE_PEN_COLOR - 1,
        pInlinePenColorIndexList,
        &nInlinePenColorIndex);
    RegisterInlineSelectHighlightHandler(&PicEditInLineItems[i], PicEditPenColorHiLiteHandler);

    /* g_cat92_n_items = i; */
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditPenSetting
 * DESCRIPTION
 *  Entry function for Pen setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditPenSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    U8 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_PE_PEN_SETTING, ExitScr4PicEditPenSetting, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_PEN_SETTING);

    InitializeCategory57Screen();

    for (iCount = 0; iCount < MAX_TYPE_PEN_PIXEL; ++iCount)
    {
        pInlinePenSizeList[iCount] = (U8*) GetString((U16) (iCount + STR_PE_PEN_SIZE_1));
    }

#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 */
    for (iCount = 0; iCount < MAX_TYPE_PEN_MOVE; ++iCount)
    {
        pInlinePenMoveFactorList[iCount] = (U8*) GetString((U16) (iCount + STR_PE_PEN_MOVE_1));
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    nInlinePenColorIndex = gpPicEditPen->penColorIndex - 1;

    switch (gpPicEditPen->penPixel)
    {
        case PIC_EDIT_PEN_PIXEL_1:
            nInlinePenSize = 0;
            break;
        case PIC_EDIT_PEN_PIXEL_2:
            nInlinePenSize = 1;
            break;
        case PIC_EDIT_PEN_PIXEL_3:
            nInlinePenSize = 2;
            break;
        case PIC_EDIT_PEN_PIXEL_4:
            nInlinePenSize = 3;
            break;
        default:
            nInlinePenSize = 0;
            break;
    }
#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 */
    switch (gpPicEditPen->penMove)
    {
        case PIC_EDIT_PEN_MOVE_1:
            nInlinePenMoveFactor = 0;
            break;
        case PIC_EDIT_PEN_MOVE_2:
            nInlinePenMoveFactor = 1;
            break;
        case PIC_EDIT_PEN_MOVE_3:
            nInlinePenMoveFactor = 2;
            break;
        case PIC_EDIT_PEN_MOVE_4:
            nInlinePenMoveFactor = 3;
            break;
        default:
            nInlinePenMoveFactor = 0;
            break;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    for (iCount = 0; iCount < MAX_TYPE_PEN_COLOR; ++iCount)
    {
        pInlinePenColorIndexList[iCount] = (U8*) GetString((U16) (iCount + 1 + STR_PE_COLOR_NONE));
        inlinePERGBlist[iCount][0] = (U8) ((0xFF000000 & gPEColorRGB[iCount + 1]) >> 24);
        inlinePERGBlist[iCount][1] = (U8) ((0x00FF0000 & gPEColorRGB[iCount + 1]) >> 16);
        inlinePERGBlist[iCount][2] = (U8) ((0x0000FF00 & gPEColorRGB[iCount + 1]) >> 8);
    }
    inlinePERGBlist[iCount - 1][0] = (U8) ((0xFF000000 & gPEColorRGB[iCount - 1]) >> 24);
    inlinePERGBlist[iCount - 1][1] = (U8) ((0x00FF0000 & gPEColorRGB[iCount - 1]) >> 16);
    inlinePERGBlist[iCount - 1][2] = (U8) ((0x0000FF00 & gPEColorRGB[iCount - 1]) >> 8);

    inputBuffer = GetCurrNInputBuffer(SCR_PE_PEN_SETTING, &inputBufferSize);    /* added for inline edit history */

    RegisterHighlightHandler(PicEditPenSettingInlineEdit);
    g_pe_color_index = nInlinePenColorIndex + 1;

    SetPicEditPenSettingInlineItemData();
    if (inputBuffer != NULL)
        SetCategory57Data(PicEditInLineItems,
#ifdef __MMI_TOUCH_SCREEN__
                          4,
#else 
                          6,
#endif 
                          inputBuffer);

    ShowCategory57Screen(STR_PE_EDIT_OPT_PEN_SETTING, GetRootTitleIcon(MENU_PICTURE_EDITOR),
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
#ifdef __MMI_TOUCH_SCREEN__
                         4,
#else 
                         6,
#endif 
                         NULL, PicEditInLineItems, 0, guiBuffer);

    DisableCategory57ScreenDone();

    RegisterInlineSelectHighlightHandler(&PicEditInLineItems[PE_PEN_SIZE_SELECT], PicEditPenSettingSelectInlineEdit);
#ifndef __MMI_TOUCH_SCREEN__
    RegisterInlineSelectHighlightHandler(&PicEditInLineItems[PE_PEN_MOVE_SELECT], PicEditPenSettingSelectInlineEdit);
#endif 
    RegisterInlineSelectHighlightHandler(&PicEditInLineItems[PE_PEN_COLOR_SELECT], PicEditPenSettingSelectInlineEdit);
    PicEditPenSettingSelectInlineEdit(-1);

    /* SetExitHandler(SCR_PE_PEN_SETTING, ExitScr4PicEditPenSetting); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditPenSetting
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditPenSetting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditPenSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_PE_PEN_SETTING;
    h.entryFuncPtr = EntryScr4PicEditPenSetting;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    AddNHistory(h, inputBufferSize);                    /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  GoBackPicEditPenSettingHistory
 * DESCRIPTION
 *  Go Back function for Pen settign screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackPicEditPenSettingHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  PicEditPenSettingInlineEdit
 * DESCRIPTION
 *  Changes the softkeys for pen setting screen
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditPenSettingInlineEdit(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSelPEPenSetting = (U8) nIndex;
    ChangePenSettingSoftkey();
}


/*****************************************************************************
 * FUNCTION
 *  PicEditPenSettingSelectInlineEdit
 * DESCRIPTION
 *  changes softkey when inline item selected on pen setting screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditPenSettingSelectInlineEdit(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((nSelPEPenSetting == PE_PEN_COLOR_SELECT) && (index != -1))
    {
        g_pe_color_index = index;
    }
    ChangePenSettingSoftkey();
}


/*****************************************************************************
 * FUNCTION
 *  ChangePenSettingSoftkey
 * DESCRIPTION
 *  Changes softkey on pen setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePenSettingSoftkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CheckPicEditPenSettingChange())
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(EntryScr4PicEditPenSettingSaveConfirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackPicEditPenSettingHistory, KEY_EVENT_UP);
    }

    if ((nSelPEPenSetting == PE_PEN_COLOR_SELECT) && (g_pe_color_index + 1 == PE_COLOR_CUSTOM_1))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetCategory57LeftSoftkeyFunction(EntryScr4PicEditCustomColor);
    }
    else
    {
        ChangeLeftSoftkey((U16) NULL, (U16) NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditPenSettingSaveConfirm
 * DESCRIPTION
 *  Confirmation screen for save pen settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditPenSettingSaveConfirm(void)
{
#if (0)
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
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(SavePicEditPenSetting, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackPicEditPenSettingConfirmHistory, KEY_EVENT_UP);

    /* playRequestedTone(WARNING_TONE) ; */

    /* SetExitHandler(SCR_PE_PEN_SETTING_SAVE, ExitScr4PicEditPenSettingSaveConfirm); */

}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditPenSettingSaveConfirm
 * DESCRIPTION
 *  Exit function EntryScr4PicEditPenSettingSaveConfirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditPenSettingSaveConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;  /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    h.scrnID = SCR_PE_PEN_SETTING_SAVE;
    h.entryFuncPtr = EntryScr4PicEditPenSettingSaveConfirm;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  GoBackPicEditPenSettingConfirmHistory
 * DESCRIPTION
 *  Go Back History for save pen setting coonfirmatioon screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackPicEditPenSettingConfirmHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    DeleteUptoScrID(SCR_PE_EDIT_PIC_OPT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  SavePicEditPenSetting
 * DESCRIPTION
 *  Saves Pen setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SavePicEditPenSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 infoPalette[MAX_TYPE_PEN_COLOR * 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpPicEditPen->penColorIndex = (U8) nInlinePenColorIndex + 1;
    switch (nInlinePenSize)
    {
        case 0:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_1;
            break;
        case 1:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_2;
            break;
        case 2:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_3;
            break;
        case 3:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_4;
            break;
        default:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_1;
            break;
    }
#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 */
    switch (nInlinePenMoveFactor)
    {
        case 0:
            gpPicEditPen->penMove = PIC_EDIT_PEN_MOVE_1;
            break;
        case 1:
            gpPicEditPen->penMove = PIC_EDIT_PEN_MOVE_2;
            break;
        case 2:
            gpPicEditPen->penMove = PIC_EDIT_PEN_MOVE_3;
            break;
        case 3:
            gpPicEditPen->penMove = PIC_EDIT_PEN_MOVE_4;
            break;
        default:
            gpPicEditPen->penMove = PIC_EDIT_PEN_MOVE_1;
            break;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    CloseCategory57Screen();

    GetPaletteInfo(infoPalette);
    memcpy(gpPEFileBuff + 54, &infoPalette, MAX_TYPE_PEN_COLOR * gPEBitsPerPixel);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_PE_EDIT_PIC);
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditFillPicInlineItemData
 * DESCRIPTION
 *  Setup inline item data for fill image background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditFillPicInlineItemData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&PicEditInLineItems[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&PicEditInLineItems[0], (PU8) (get_string(STR_PE_EDIT_OPT_FILL_PIC)));

    SetInlineItemActivation(&PicEditInLineItems[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &PicEditInLineItems[1],
        MAX_TYPE_PEN_COLOR - 1,
        pInlinePenColorIndexList,
        &nInlinePenColorIndex);
    RegisterInlineSelectHighlightHandler(&PicEditInLineItems[1], PicEditPenColorHiLiteHandler);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditFillPic
 * DESCRIPTION
 *  Entry function for filling image with selected color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditFillPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    U8 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_PE_FILL_PIC, ExitScr4PicEditFillPic, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_FILL_PIC);

    //Pixtel patch
    //      nInlinePenColorIndex=gpPicEditPen->penBackgrdColorIndex;

    for (iCount = 0; iCount < MAX_TYPE_PEN_COLOR; iCount++)
    {
        pInlinePenColorIndexList[iCount] = (U8*) GetString((U16) (iCount + 1 + STR_PE_COLOR_NONE));
        inlinePERGBlist[iCount][0] = (U8) ((0xFF000000 & gPEColorRGB[iCount + 1]) >> 24);
        inlinePERGBlist[iCount][1] = (U8) ((0x00FF0000 & gPEColorRGB[iCount + 1]) >> 16);
        inlinePERGBlist[iCount][2] = (U8) ((0x0000FF00 & gPEColorRGB[iCount + 1]) >> 8);
    }

    inputBuffer = GetCurrNInputBuffer(SCR_PE_FILL_PIC, &inputBufferSize);       /* added for inline edit history */

    RegisterHighlightHandler(ChangeSoftkeyFillPic);
    g_pe_color_index = nInlinePenColorIndex + 1;

    InitializeCategory57Screen();
    SetPicEditFillPicInlineItemData();
    if (inputBuffer != NULL)
    {
        SetCategory57Data(PicEditInLineItems, 2, inputBuffer);
    }

    ShowCategory57Screen(
        STR_PE_EDIT_OPT_FILL_PIC,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        NULL,
        PicEditInLineItems,
        0,
        guiBuffer);
    EnableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(EntryScr4PicEditFillPicSaveConfirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditFillPic
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditFillPic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditFillPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_PE_FILL_PIC;
    h.entryFuncPtr = EntryScr4PicEditFillPic;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    AddNHistory(h, inputBufferSize);                    /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  ChangeSoftkeyFillPic
 * DESCRIPTION
 *  Changes softkeys when inline item selected
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeSoftkeyFillPic(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gpPicEditPen->penBackgrdColorIndex != (U8) g_pe_color_index)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, IMG_GLOBAL_BACK);
        ChangeLeftSoftkey((U16) NULL, (U16) NULL);
        SetRightSoftkeyFunction(EntryScr4PicEditFillPicSaveConfirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        /* ChangeLeftSoftkey(STR_GLOBAL_OK,IMG_GLOBAL_OK); */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetCategory57LeftSoftkeyFunction(EntryScr4PicEditFillPicSaveConfirm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  PicEditFillPicSelectInlineEdit
 * DESCRIPTION
 *  Changes softkeys when inline item selected
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditFillPicSelectInlineEdit(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pe_color_index = index + 1;
    ChangeSoftkeyFillPic(index);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditFillPicSaveConfirm
 * DESCRIPTION
 *  Confirmation screen for filling image with color selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditFillPicSaveConfirm(void)
{
#if (0)
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
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_PE_EDIT_OPT_FILL_PIC),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(SavePicEditFillPic, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackPicEditFillPicConfirmHistory, KEY_EVENT_UP);

    /* playRequestedTone(WARNING_TONE) ; */

    /* SetExitHandler(SCR_PE_FILL_PIC_SAVE, ExitScr4PicEditFillPicSaveConfirm); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditFillPicSaveConfirm
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditFillPicSaveConfirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditFillPicSaveConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;  /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    h.scrnID = SCR_PE_FILL_PIC_SAVE;
    h.entryFuncPtr = EntryScr4PicEditFillPicSaveConfirm;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  GoBackPicEditFillPicConfirmHistory
 * DESCRIPTION
 *  Go Back history function for the confirmation screen for filling image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackPicEditFillPicConfirmHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    DeleteUptoScrID(SCR_PE_EDIT_PIC_OPT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  SavePicEditFillPic
 * DESCRIPTION
 *  Fills image with the color selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SavePicEditFillPic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 infoPalette[MAX_TYPE_PEN_COLOR * 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpPicEditPen->penBackgrdColorIndex = (U8) nInlinePenColorIndex + 1;
    CloseCategory57Screen();
    GetPaletteInfo(infoPalette);

    gPEImageWidth_bak = gPEImageWidth;
    gPEImageHeight_bak = gPEImageHeight;
    SET_PE_IMAGE_EDIT(gPEAttrib);
    UNSET_PE_MARK_IMAGE(gPEAttrib);
    UNSET_PE_COPY_IMAGE(gPEAttrib);

    memcpy(&gpPEFileBuff[54], &infoPalette, MAX_TYPE_PEN_COLOR * gPEBitsPerPixel);
    memset(
        &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE],
        ((gpPicEditPen->penBackgrdColorIndex) | (gpPicEditPen->penBackgrdColorIndex << 4)),
        (gpPicEditPen->maxY - gpPicEditPen->minY) * GetImageWidth(gpPicEditPen->minX, gpPicEditPen->maxX));
    SavePEContext();
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_PE_EDIT_PIC);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditScrResize
 * DESCRIPTION
 *  Entry screen for resize image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditScrResize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 iCount;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_PE_SCR_RESIZE, ExitScr4PicEditScrResize, NULL, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_PE_SCR_RESIZE);

    //Pixtel patch
    //      memset( (void *)PicEditInLineItems, 0, sizeof( InlineItem )*MAX_RESIZE_INLINE_EDIT );

    for (iCount = 0; iCount < MAX_TYPE_SCR_TYPE; ++iCount)
    {
    #ifdef __MMI_MAINLCD_240X320__
        pInlinePEScrList[iCount] = (U8*) GetString((U16) (iCount + STR_PE_RESIZE_32)); /* 110805 resize region Calvin added */
    #else 
        pInlinePEScrList[iCount] = (U8*) GetString((U16) (iCount + STR_PE_RESIZE_16));
    #endif 
    }
    inputBuffer = GetCurrNInputBuffer(SCR_PE_SCR_RESIZE, &inputBufferSize);     /* added for inline edit history */

    //Pixtel patch
    //      FillPicEditResizeInLine(PicEditInLineItems);
    RegisterHighlightHandler(ChangeResizeSoftKey);

    /* Pixtel patch */
    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(PicEditInLineItems, MAX_RESIZE_INLINE_EDIT, inputBuffer);     /* sets the data */
    }
    else
    {
        memset((void*)PicEditInLineItems, 0, sizeof(InlineItem) * MAX_RESIZE_INLINE_EDIT);
        FillPicEditResizeInLine(PicEditInLineItems);
    }
    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_PE_EDIT_OPT_RESIZE,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_RESIZE_INLINE_EDIT,
        (U16*) NULL,
        PicEditInLineItems,
        0,
        guiBuffer);

    DisableCategory57ScreenDone();
    SetLeftSoftkeyFunction(ValidateScrWidthHeight, KEY_EVENT_UP);
    SetCategory57RightSoftkeyFunctions(ValidateScrWidthHeight, GoBackHistory);
    /* SetExitHandler(SCR_PE_SCR_RESIZE, ExitScr4PicEditScrResize); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditScrResize
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditScrResize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditScrResize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_PE_SCR_RESIZE;
    h.entryFuncPtr = EntryScr4PicEditScrResize;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    AddNHistory(h, inputBufferSize);                    /* added for inline edit history */

}


/*****************************************************************************
 * FUNCTION
 *  FillPicEditResizeInLine
 * DESCRIPTION
 *  Fills the Inline buffer for resize image screen
 * PARAMETERS
 *  ResizeInline        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void FillPicEditResizeInLine(InlineItem *ResizeInline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&ResizeInline[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&ResizeInline[0], (PU8) (GetString(STR_PE_RESIZE_TO)));

    SetInlineItemActivation(&ResizeInline[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&ResizeInline[1], (S32) MAX_TYPE_SCR_TYPE, pInlinePEScrList, &nInlinePEScr);
    RegisterInlineSelectHighlightHandler(&ResizeInline[1], HighlightResizeInlineItemHandler);

    SetInlineItemActivation(&ResizeInline[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&ResizeInline[2], (PU8) (GetString(STR_PE_RESIZE_WIDTH)));

    SetInlineItemActivation(&ResizeInline[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&ResizeInline[3], (PU8) nInlinePEScrWidth, PE_RESIZE_BUF_SIZE, INPUT_TYPE_NUMERIC);   /* 100405 image editor Calvin */
    RightJustifyInlineItem(&ResizeInline[3]);
    EnableInlineItemBoundary(&ResizeInline[3]);

    SetInlineItemActivation(&ResizeInline[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&ResizeInline[4], (PU8) (GetString(STR_PE_RESIZE_HEIGHT)));

    SetInlineItemActivation(&ResizeInline[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&ResizeInline[5], (PU8) nInlinePEScrHeight, PE_RESIZE_BUF_SIZE, INPUT_TYPE_NUMERIC);  /* 100405 image editor Calvin */
    RightJustifyInlineItem(&ResizeInline[5]);
    EnableInlineItemBoundary(&ResizeInline[5]);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightResizeInlineItemHandler
 * DESCRIPTION
 *  Highlight Handler for Inline Item selected
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightResizeInlineItemHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 scrWParam[4 * ENCODING_LENGTH], scrHParam[4 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == PE_SCR_4)
    {
        if (!nInlinePenColorIndex)
        {
            /* Leo start 20050824 */
            //                      sprintf((PS8)scrWParam,"%d",nInlinePenSize);
            //                      sprintf((PS8)scrHParam,"%d",nInlinePenMoveFactor);
            /* Leo end 20050824 */
            sprintf((PS8) scrWParam, "%d", gPEImageWidth);
            sprintf((PS8) scrHParam, "%d", gPEImageHeight);
            nInlinePenColorIndex = 1;
            mmi_asc_to_ucs2((PS8) nInlinePEScrWidth, (PS8) scrWParam);
            mmi_asc_to_ucs2((PS8) nInlinePEScrHeight, (PS8) scrHParam);
            EnableInlineItem(PicEditInLineItems, 3);
            EnableInlineItem(PicEditInLineItems, 5);
        }
    }
    else
    {
        if (nInlinePenColorIndex)
        {
            mmi_ucs2_to_asc((PS8) scrWParam, (PS8) nInlinePEScrWidth);
            mmi_ucs2_to_asc((PS8) scrHParam, (PS8) nInlinePEScrHeight);
            nInlinePenSize = (U16) atoi((PS8) scrWParam);
            nInlinePenMoveFactor = (U16) atoi((PS8) scrHParam);
            nInlinePenColorIndex = 0;
        }
        sprintf((PS8) scrWParam, "");
        sprintf((PS8) scrHParam, "");
        mmi_asc_to_ucs2((PS8) nInlinePEScrWidth, (PS8) scrWParam);
        mmi_asc_to_ucs2((PS8) nInlinePEScrHeight, (PS8) scrHParam);
        DisableInlineItem(PicEditInLineItems, 3);
        DisableInlineItem(PicEditInLineItems, 5);
    }
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  ChangeResizeSoftKey
 * DESCRIPTION
 *  Change softkey for Resize screen
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeResizeSoftKey(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(ValidateScrWidthHeight);
}


/*****************************************************************************
 * FUNCTION
 *  SetResizeInlineItemValues
 * DESCRIPTION
 *  Sets Resize Inline item values
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetResizeInlineItemValues(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nInlinePEScr = (U32) GetPicEditScr();
    //nInlinePenSize used as temp buffer for inline Width
    //      nInlinePenSize =(S32)gPEImageWidth;     
    //      gPEImageWidth_bak =(S32)gPEImageWidth;     
    //nInlinePenMoveFactor used as temp buffer for inline Height
    //      nInlinePenMoveFactor =(S32)gPEImageHeight;
    //      gPEImageHeight_bak =(S32)gPEImageHeight;
    //nInlinePenColorIndex used as flag for Inline Resize Screen
    nInlinePenColorIndex = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ValidateScrWidthHeight
 * DESCRIPTION
 *  Validates and sets the values for width and height of image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ValidateScrWidthHeight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 scrWParam[4 * ENCODING_LENGTH], scrHParam[4 * ENCODING_LENGTH];
    U16 nWidth, nHeight;
    BOOL bFlag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    gPEImageWidth_bak = gPEImageWidth;
    gPEImageHeight_bak = gPEImageHeight;
    gPEImageResized = MMI_TRUE;
    switch (nInlinePEScr)
    {
        case PE_SCR_1:
            gPEImageWidth = PE_SCR_SIZE_1;
            gPEImageHeight = PE_SCR_SIZE_1;
            break;
        case PE_SCR_2:
            gPEImageWidth = PE_SCR_SIZE_2;
            gPEImageHeight = PE_SCR_SIZE_2;
            break;
        case PE_SCR_3:
            gPEImageWidth = PE_SCR_SIZE_MAX;
            gPEImageHeight = PE_SCR_SIZE_MAX;
            break;
        case PE_SCR_4:
            mmi_ucs2_to_asc((PS8) scrWParam, (PS8) nInlinePEScrWidth);
            mmi_ucs2_to_asc((PS8) scrHParam, (PS8) nInlinePEScrHeight);

            nWidth = (U16) atoi((PS8) scrWParam);
            nHeight = (U16) atoi((PS8) scrHParam);

            if (((nWidth >= PE_SCR_SIZE_MIN) && (nWidth <= PE_SCR_SIZE_MAX)) &&
                ((nHeight >= PE_SCR_SIZE_MIN) && (nHeight <= PE_SCR_SIZE_MAX)))
            {
                gPEImageWidth = nWidth;
                gPEImageHeight = nHeight;
            }
            else
            {
                /* 092005 Image Editor Size Calvin */
            #ifdef __MMI_MAINLCD_240X320__
                DisplayPopup(
                    (U8*) GetString(STR_PE_RESIZE_ERROR_BIG),
                    IMG_GLOBAL_WARNING,
                    0,
                    PE_NOTIFYDURATION,
                    (U8) WARNING_TONE);
            #else /* __MMI_MAINLCD_240X320__ */ 
                DisplayPopup(
                    (U8*) GetString(STR_PE_RESIZE_ERROR),
                    IMG_GLOBAL_WARNING,
                    0,
                    PE_NOTIFYDURATION,
                    (U8) WARNING_TONE);
            #endif /* __MMI_MAINLCD_240X320__ */ 
                /* 092005 Calvin end */
                bFlag = TRUE;
            }
            break;
        default:
            gPEImageWidth = PE_SCR_SIZE_2;
            gPEImageHeight = PE_SCR_SIZE_2;
            break;
    }

    if (!bFlag)
    {
        /* CloseCategory57Screen(); */
        UNSET_PE_PEN_DOWN(gPEAttrib);

        /* check if image is resized to smaller size */
        if (!SetPicEditPenMarkBoundary())
        {
            SavePEContext();
            gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
            SetPicEditPenBoundary();
            ResizePicEditImageDataBuff();
            if (IS_PE_ZOOM_IMAGE(gPEAttrib))
            {
                SetPicEditZoomWindow(FALSE);
            }
            SET_PE_IMAGE_EDIT(gPEAttrib);
            UNSET_PE_MARK_IMAGE(gPEAttrib);
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
            DeleteUptoScrID(SCR_PE_EDIT_PIC);
        }
        else
        {
            gPECurrentAction = SEL_PE_EDIT_OPT_RESIZE;
            DeleteUptoScrID(SCR_PE_EDIT_PIC);
            GoBackHistory();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditHelp
 * DESCRIPTION
 *  Entry screen for help
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *buffer;
    S32 bufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_PE_HELP, ExitScr4PicEditHelp, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_HELP);
    /* Leo add 20050705 start */
#ifdef __MMI_TOUCH_SCREEN__
    buffer = GetString(STR_PE_HELP_DESCRIPTION_TOUCH);
#else 
    buffer = GetString(STR_PE_HELP_DESCRIPTION);
#endif 
    /* Leo add 20050705 end */
    bufferSize = mmi_ucs2strlen(buffer);

    ShowCategory74Screen(
        STR_PE_EDIT_OPT_HELP,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) buffer,
        bufferSize,
        guiBuffer);

    /* go back to option menu */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetExitHandler (SCR_PE_HELP,ExitScr4PicEditHelp); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditHelp
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditHelp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_HELP;
    h.entryFuncPtr = EntryScr4PicEditHelp;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditCustomColor
 * DESCRIPTION
 *  Entry screen function for custom color setting change
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditCustomColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_PE_CUSTOM_COLOR, ExitScr4PicEditCustomColor, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_CUSTOM_COLOR);

    inlineCustomRGB[0] = inlinePERGBlist[PE_COLOR_CUSTOM_1][0];
    inlineCustomRGB[1] = inlinePERGBlist[PE_COLOR_CUSTOM_1][1];
    inlineCustomRGB[2] = inlinePERGBlist[PE_COLOR_CUSTOM_1][2];

    ShowCategory91Screen(
        STR_PE_COLOR_SEL,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        &inlineCustomRGB[0],
        &inlineCustomRGB[1],
        &inlineCustomRGB[2],
        &highlighted_slider,
        guiBuffer);

    SetLeftSoftkeyFunction(SavePicEditCustomColor, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* SetExitHandler(SCR_PE_CUSTOM_COLOR, ExitScr4PicEditCustomColor); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditCustomColor
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditCustomColor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditCustomColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_CUSTOM_COLOR;
    h.entryFuncPtr = EntryScr4PicEditCustomColor;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  SavePicEditCustomColor
 * DESCRIPTION
 *  Saves custom color settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SavePicEditCustomColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 infoPalette[MAX_TYPE_PEN_COLOR * 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inlinePERGBlist[PE_COLOR_CUSTOM_1][0] = inlineCustomRGB[0];
    inlinePERGBlist[PE_COLOR_CUSTOM_1][1] = inlineCustomRGB[1];
    inlinePERGBlist[PE_COLOR_CUSTOM_1][2] = inlineCustomRGB[2];
    gPEColorRGB[PE_COLOR_CUSTOM_1] &= 0x000000FF;
    gPEColorRGB[PE_COLOR_CUSTOM_1] |=
        ((((U32) inlineCustomRGB[0]) << 24) | (((U32) inlineCustomRGB[1]) << 16) |
         (((U32) inlineCustomRGB[2]) << 8));

    /* Removed by Leo               gpPicEditPen->penColorIndex=(U8)nInlinePenColorIndex+1; */
    GetPaletteInfo(infoPalette);
    memcpy(gpPEFileBuff + 54, &infoPalette, MAX_TYPE_PEN_COLOR * gPEBitsPerPixel);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditSaveImageConfirm
 * DESCRIPTION
 *  Confirmation screen for Saving image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditSaveImageConfirm(void)
{
#if (0)
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
#endif /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(PicEditSaveImage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackPicEditSaveImageConfirmHistory, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
    /* SetExitHandler(SCR_PE_SAVE_IMAGE_CONFIRM, ExitScr4PicEditPenSettingSaveConfirm); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditSaveImageConfirm
 * DESCRIPTION
 *  Exit screen function for EntryScr4PicEditSaveImageConfirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditSaveImageConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;  /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    h.scrnID = SCR_PE_SAVE_IMAGE_CONFIRM;
    h.entryFuncPtr = EntryScr4PicEditSaveImageConfirm;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  GoBackPicEditSaveImageConfirmHistory
 * DESCRIPTION
 *  Go back histroy fucntion for saving image confirmation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackPicEditSaveImageConfirmHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitPicEditPen();
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  PicEditSaveImage
 * DESCRIPTION
 *  Saves image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PicEditSaveImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SavePicEditImage();
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditPenAtCenter
 * DESCRIPTION
 *  Sets Pen at the center of the image if bflag TRUE
 * PARAMETERS
 *  bFlag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditPenAtCenter(BOOL bFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bFlag)
    {
        gpPicEditPen->penX = (U16) (UI_device_width / 2) + PE_IMAGE_WIDTH_EXTRA;
        gpPicEditPen->penY = (U16) (UI_device_height / 2) + PE_IMAGE_HEIGHT_EXTRA;
    }
    else
    {
        gpPicEditPen->penX = gpPicEditPen->minX;
        gpPicEditPen->penY = gpPicEditPen->minY;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditPenBoundary
 * DESCRIPTION
 *  Sets Pen boundary wrt to the image size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditPenBoundary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nWidth, nHeight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nInlinePEScr)
    {
        case PE_SCR_1:
            nWidth = PE_SCR_SIZE_1;
            nHeight = PE_SCR_SIZE_1;
            break;
        case PE_SCR_2:
            nWidth = PE_SCR_SIZE_2;
            nHeight = PE_SCR_SIZE_2;
            break;
        case PE_SCR_3:
            nWidth = PE_SCR_SIZE_MAX;
            nHeight = PE_SCR_SIZE_MAX;
            break;
        case PE_SCR_4:
            nWidth = gPEImageWidth;
            nHeight = gPEImageHeight;
            break;
        default:
            nWidth = PE_SCR_SIZE_2;
            nHeight = PE_SCR_SIZE_2;
            break;
    }

    gpPicEditPen->minX = SET_WINDOW_MINX(nWidth);
    gpPicEditPen->maxX = gpPicEditPen->minX + (U16) nWidth;
    gpPicEditPen->minY = SET_WINDOW_MINY(nHeight);
    gpPicEditPen->maxY = gpPicEditPen->minY + (U16) nHeight;
}


/*****************************************************************************
 * FUNCTION
*  SavePicEditImageAndShowResult
* DESCRIPTION
*  save new picture edit image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void SavePicEditImageAndShowResult(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if (IS_PE_ADD_IMAGE(gPEAttrib))    
    {
        mmi_ucs2cat((S8*) TempImageName,(S8*) L".bmp");
        mmi_ucs2cpy((S8*) gPicEditorInfo[gPicEditCurrPic].ImageName, (S8*) TempImageName);
    }
    
    result = SavePicEditImageDataBuff();
	
    if (result == FS_NO_ERROR)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) get_string(GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            1,
            PE_NOTIFYDURATION,
            ERROR_TONE);
    }
	DeleteUptoScrID(SCR_PE_SELECT_PIC_MENU);
	InitPicEditPen();
}


/*****************************************************************************
* FUNCTION
*  SavePicEditImage
* DESCRIPTION
*  save picture edit image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void SavePicEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 localBuffer[30 * ENCODING_LENGTH];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PE_ADD_IMAGE(gPEAttrib))
    {
        sprintf(localBuffer, "Picture%d", gPicEditCurrPic + 1);
        mmi_asc_to_ucs2((S8*) TempImageName, (S8*) localBuffer);    
        InputPicEditImageFileName();
    }
    else
    {
        SavePicEditImageAndShowResult();
    }
}


/*****************************************************************************
* FUNCTION
*  InputPicEditImageFileName
* DESCRIPTION
*  input file name
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void InputPicEditImageFileName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *guiBuffer = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	EntryNewScreen(SCR_PE_EDIT_INPUT_FILENAME, NULL, InputPicEditImageFileName, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_PE_EDIT_INPUT_FILENAME);
	
    ShowCategory5Screen(
        STR_GLOBAL_FILENAME,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (INPUT_TYPE_ALPHANUMERIC_UPPERCASE),
        (PU8)TempImageName,
        MAX_IMAGE_NAME_WIDTH,
        guiBuffer);
	
    SetLeftSoftkeyFunction(entry_pe_editor_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetHiliteHandler(MENU_PE_FILENAME_EDITOR_DONE, highlight_pe_done);
    SetHiliteHandler(MENU_PE_FILENAME_EDITOR_INPUT_METHOD, highlight_pe_input_method);
}


/*****************************************************************************
 * FUNCTION
 *  pe_return_to_editor
 * DESCRIPTION
 *  return to editor from input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void pe_return_to_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  entry_pe_editor_option
 * DESCRIPTION
 *  entry picture editor filename option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void entry_pe_editor_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem, imageId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_PE_EDIT_INPUT_FILENAME_OPTION, NULL, entry_pe_editor_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_PE_EDIT_INPUT_FILENAME_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild(MENU_PE_FILENAME_EDITOR_OPTION);
    GetSequenceStringIds(MENU_PE_FILENAME_EDITOR_OPTION, nStrItemList);
    SetParentHandler(MENU_PE_FILENAME_EDITOR_OPTION);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_PICTURE_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(pe_return_to_editor);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    return;

}


/*****************************************************************************
 * FUNCTION
 *  highlight_pe_input_method
 * DESCRIPTION
 *  highlight handler for change input method in editor option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void highlight_pe_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}
/*****************************************************************************
 * FUNCTION
 *  highlight_pe_done
 * DESCRIPTION
 *  highlight handler for done in editor option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void highlight_pe_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(SavePicEditImageAndShowResult, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  SavePicEditImageDataBuff
 * DESCRIPTION
 *  Saves Image data buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 SavePicEditImageDataBuff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle;
    S8 fileBuf[100 * ENCODING_LENGTH];  /* padding for filepath */
    S8 fileName[100 * ENCODING_LENGTH]; /* padding for filepath */
    U32 wByte = 0;
    S32 result;
    U16 image_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ASCII
    mmi_ucs2cpy((PS8) fileName, PICTURE_EDITOR_PATH);
#else 
    mmi_asc_to_ucs2((PS8) fileName, PICTURE_EDITOR_PATH);
#endif 

    memset(fileName, 0, sizeof(fileName));
    sprintf(fileBuf, "%c:\\", MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) fileName, (S8*) fileBuf);
    mmi_ucs2cat((S8*) fileName, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);

    fileHandle = FS_Open((U16*) fileName, FS_OPEN_DIR | FS_READ_ONLY);

    if (fileHandle < 0)
    {
        fileHandle = FS_CreateDir((kal_wchar*)fileName);
        FS_Close(fileHandle);
    }
    else
    {
        FS_Close(fileHandle);
    }

    mmi_ucs2cpy((S8*) fileBuf, (S8*) gPicEditorInfo[gPicEditCurrPic].ImageName);
    mmi_ucs2cat((S8*) fileName, (S8*) fileBuf);

    if ((fileHandle = FS_Open((PU16) fileName, FS_READ_WRITE | FS_CREATE_ALWAYS)) < 0)
    {
        return fileHandle;
    }
    image_size = PIC_EDIT_FILE_HEADER_SIZE + ((GetImageWidth(0, gPEImageWidth) * gPEImageHeight));
    memcpy((S8*) & gpPEFileBuff[2], &image_size, 2);

    result = FS_Write(fileHandle, gpPEFileBuff, image_size, &wByte); 
    if (result < 0)
    {
        FS_Close(fileHandle);
        return result;
    }
    FS_Close(fileHandle);
    if (IS_PE_ADD_IMAGE(gPEAttrib))
    {
        /* AddPictureEditorImage(( S8*)fileBuf); */
        AddPictureEditorImageAtIndex((S8*) fileBuf, gPicEditCurrPic);
    }
    WritePicEditListToNVRAM();

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  SearchPicEditFileName
 * DESCRIPTION
 *  Search file name in the images already present
 * PARAMETERS
 *  sFile       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 SearchPicEditFileName(S8 *sFile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 jCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for (jCount=0;jCount<gPEImageCount;jCount++) */
    for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
    {
        if ((gPicEditorInfo[jCount].ImagesId) &&
            (!mmi_ucs2cmp((S8*) sFile, (S8*) gPicEditorInfo[jCount].ImageName)))
        {
            return 1;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetPicEditCurrentImageName
 * DESCRIPTION
 *  Gets the image name for image selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *GetPicEditCurrentImageName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPicEditorInfo[gPicEditCurrPic].ImageName;
}


/*****************************************************************************
 * FUNCTION
 *  GetPicEditCurrentImageId
 * DESCRIPTION
 *  Gets the image id for image selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetPicEditCurrentImageId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gPicEditorInfo[gPicEditCurrPic].ImagesId;
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditPenMarkBoundary
 * DESCRIPTION
 *  Sets the mark boundary
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern PicEditMarkBox gPicEditZoomWindow;

BOOL SetPicEditPenMarkBoundary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nWidth, nHeight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nInlinePEScr)
    {
        case PE_SCR_1:
            nWidth = PE_SCR_SIZE_1;
            nHeight = PE_SCR_SIZE_1;
            break;
        case PE_SCR_2:
            nWidth = PE_SCR_SIZE_2;
            nHeight = PE_SCR_SIZE_2;
            break;
        case PE_SCR_3:
            nWidth = PE_SCR_SIZE_MAX;
            nHeight = PE_SCR_SIZE_MAX;
            break;
        case PE_SCR_4:
            nWidth = gPEImageWidth;
            nHeight = gPEImageHeight;
            break;
        default:
            nWidth = PE_SCR_SIZE_2;
            nHeight = PE_SCR_SIZE_2;
            break;
    }

    if (((gpPicEditPen->maxX - gpPicEditPen->minX) >= nWidth) && ((gpPicEditPen->maxY - gpPicEditPen->minY) >= nHeight))
    {
        gPicEditZoomWindow.minX = gPicEditMark.minX = gpPicEditPen->penX = gpPicEditPen->minX;
        gPicEditZoomWindow.minY = gPicEditMark.minY = gpPicEditPen->penY = gpPicEditPen->minY;
        gPicEditZoomWindow.maxX = gPicEditMark.maxX = gPicEditMark.minX + nWidth;
        gPicEditZoomWindow.maxY = gPicEditMark.maxY = gPicEditMark.minY + nHeight;

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetPicEditScr
 * DESCRIPTION
 *  Gets the image size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetPicEditScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gPEImageWidth == PE_SCR_SIZE_1) && (gPEImageHeight == PE_SCR_SIZE_1))
    {
        return PE_SCR_1;
    }
    else if ((gPEImageWidth == PE_SCR_SIZE_2) && (gPEImageHeight == PE_SCR_SIZE_2))
    {
        return PE_SCR_2;
    }
    else if ((gPEImageWidth == PE_SCR_SIZE_MAX) && (gPEImageHeight == PE_SCR_SIZE_MAX))
    {
        return PE_SCR_3;
    }
    else
    {
        return PE_SCR_4;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CheckPicEditPenSettingChange
 * DESCRIPTION
 *  Checks if pen setting changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL CheckPicEditPenSettingChange(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 penPixel;

#ifndef __MMI_TOUCH_SCREEN__
    U8 penMove;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nInlinePenColorIndex != gpPicEditPen->penColorIndex - 1)
    {
        return TRUE;
    }

    switch (nInlinePenSize)
    {
        case 0:
            penPixel = PIC_EDIT_PEN_PIXEL_1;
            break;
        case 1:
            penPixel = PIC_EDIT_PEN_PIXEL_2;
            break;
        case 2:
            penPixel = PIC_EDIT_PEN_PIXEL_3;
            break;
        case 3:
            penPixel = PIC_EDIT_PEN_PIXEL_4;
            break;
        default:
            penPixel = PIC_EDIT_PEN_PIXEL_1;
            break;
    }
#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 */
    switch (nInlinePenMoveFactor)
    {
        case 0:
            penMove = PIC_EDIT_PEN_MOVE_1;
            break;
        case 1:
            penMove = PIC_EDIT_PEN_MOVE_2;
            break;
        case 2:
            penMove = PIC_EDIT_PEN_MOVE_3;
            break;
        case 3:
            penMove = PIC_EDIT_PEN_MOVE_4;
            break;
        default:
            penMove = PIC_EDIT_PEN_MOVE_1;
            break;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    if (gpPicEditPen->penPixel != penPixel)
    {
        return TRUE;
    }
#ifndef __MMI_TOUCH_SCREEN__
    if (gpPicEditPen->penMove != penMove)
    {
        return TRUE;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ReadPicEditListFromNVRAM
 * DESCRIPTION
 *  Reads image names present from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReadPicEditListFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    int nCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Reading Picture List from NVRAM");

    gPEImageCount = 0;

    if (ReadRecord(NVRAM_PICTURE_EDITOR_LID, (U16) (1), (void*)&gPicEditorInfo, NVRAM_PICTURE_EDITOR_SIZE, &error) < 0)
    {
        PRINT_INFORMATION("PICTURE EDITOR : ReadRecord failed (ecode %d)", (int)error);
        memset(&gPicEditorInfo, '\0', NVRAM_PICTURE_EDITOR_SIZE);
        WriteRecord(NVRAM_PICTURE_EDITOR_LID, (U16) (1), (void*)&gPicEditorInfo, NVRAM_PICTURE_EDITOR_SIZE, &error);
    }
    for (nCount = 0; nCount < MAXIMUM_PICTURE_EDITOR_IMAGES; nCount++)
        if (gPicEditorInfo[nCount].ImagesId)
        {
            gPEImageCount++;
        }
}


/*****************************************************************************
 * FUNCTION
 *  WritePicEditListToNVRAM
 * DESCRIPTION
 *  Writes the image names in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WritePicEditListToNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("Picture Name List To Write Record NVRAM");

    if (WriteRecord(
            NVRAM_PICTURE_EDITOR_LID,
            (U16) (1),
            (void*)&gPicEditorInfo,
            NVRAM_PICTURE_EDITOR_SIZE,
            &error) != NVRAM_PICTURE_EDITOR_SIZE)
    {
        PRINT_INFORMATION("PICTURE EDITOR : WriteRecord failed (ecode %d)", (int)error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  AddPictureEditorImage
 * DESCRIPTION
 *  Add image to the image editor pictures
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S8 AddPictureEditorImage(S8 *fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 searchId, jCount, nIndex = 0;
    BOOL bFound = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gPEImageCount) == MAXIMUM_PICTURE_EDITOR_IMAGES)
    {
        return 0;
    }

    for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
    {
        if (!
            ((gPicEditorInfo[jCount].ImagesId >= (U16) PICTURE_EDITOR_IMAGE_BASE) &&
             (gPicEditorInfo[jCount].ImagesId <= PICTURE_EDITOR_IMAGE_BASE_END)))
        {
            nIndex = jCount;
            break;
        }
    }
    if (!nIndex)
    {
        return 0;
    }

    for (searchId = (U16) PICTURE_EDITOR_IMAGE_BASE; searchId <= PICTURE_EDITOR_IMAGE_BASE_END; searchId++)
    {
        bFound = FALSE;
        for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
        {
            if (gPicEditorInfo[jCount].ImagesId == searchId)
            {
                bFound = TRUE;
                break;
            }
        }
        if (bFound == FALSE)
        {
            break;
        }
    }

    gPicEditorInfo[nIndex].ImagesId = searchId;
    memset((S8*) gPicEditorInfo[nIndex].ImageName, '\0', sizeof(U8) * MAX_IMAGE_NAME_WIDTH);
    mmi_ucs2cpy((S8*) gPicEditorInfo[nIndex].ImageName, fileName);
    gPEImageCount++;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  AddPictureEditorImageAtIndex
 * DESCRIPTION
 *  Add image to the image editor pictures
 * PARAMETERS
 *  fileName        [IN]        
 *  nIndex          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S8 AddPictureEditorImageAtIndex(S8 *fileName, U8 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 searchId, jCount;
    BOOL bFound = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!
        ((gPicEditorInfo[nIndex].ImagesId >= (U16) PICTURE_EDITOR_IMAGE_BASE) &&
         (gPicEditorInfo[nIndex].ImagesId <= PICTURE_EDITOR_IMAGE_BASE_END)))
    {
        if ((gPEImageCount) == MAXIMUM_PICTURE_EDITOR_IMAGES)
        {
            return 0;
        }
        for (searchId = (U16) PICTURE_EDITOR_IMAGE_BASE; searchId <= PICTURE_EDITOR_IMAGE_BASE_END; searchId++)
        {
            bFound = FALSE;
            for (jCount = 0; jCount < MAXIMUM_PICTURE_EDITOR_IMAGES; jCount++)
            {
                if (gPicEditorInfo[jCount].ImagesId == searchId)
                {
                    bFound = TRUE;
                    break;
                }
            }
            if (bFound == FALSE)
            {
                break;
            }
        }
        gPicEditorInfo[nIndex].ImagesId = searchId;
        gPEImageCount++;
    }
    memset((S8*) gPicEditorInfo[nIndex].ImageName, '\0', sizeof(U8) * MAX_IMAGE_NAME_WIDTH);
    mmi_ucs2cpy((S8*) gPicEditorInfo[nIndex].ImageName, fileName);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  DeletePictureEditorImage
 * DESCRIPTION
 *  Deletes Image from image editor images
 *  
 *  Returns FALSE if fail else TRUE
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  S8
 *****************************************************************************/
S8 DeletePictureEditorImage(U32 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 iCount,jCount; */
    U8 iCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for(iCount=0;iCount<gPEImageCount;iCount++) */
    for (iCount = 0; iCount < MAXIMUM_PICTURE_EDITOR_IMAGES; iCount++)
    {
        if (gPicEditorInfo[iCount].ImagesId == ImageId)
        {
            break;
        }
    }
    /* if(iCount==gPEImageCount) return 0; */
    if (iCount == MAXIMUM_PICTURE_EDITOR_IMAGES)
    {
        return 0;
    }
    //      for(jCount=iCount;jCount<gPEImageCount-1;jCount++)
    //              memcpy(&gPicEditorInfo[jCount],&gPicEditorInfo[jCount+1],sizeof(DYNIMAGEINFO));
    //      gPEImageCount--;
    //      memset(&gPicEditorInfo[gPEImageCount],0,sizeof(DYNIMAGEINFO));
    memset(&gPicEditorInfo[iCount], 0, sizeof(DYNIMAGEINFO));
    gPEImageCount--;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GetPictureEditorImageInfo
 * DESCRIPTION
 *  Gets Image editor Info (Common function)
 *  
 *  Return image count
 * PARAMETERS
 *  pictureEditorInfo       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 GetPictureEditorImageInfo(DYNIMAGEINFO **pictureEditorInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pictureEditorInfo = gPicEditorInfo;
    return gPEImageCount;
}


/*****************************************************************************
 * FUNCTION
 *  GetPictureEditorImageNameInFileSystem
 * DESCRIPTION
 *  Gets image name of the image by image id input
 *  
 *  Returns NULL if not found else pointer to the image name
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  S8*
 *****************************************************************************/
S8 *GetPictureEditorImageNameInFileSystem(U32 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int nCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ImageId >= PICTURE_EDITOR_IMAGE_BASE && ImageId <= PICTURE_EDITOR_IMAGE_BASE_END)
    {
        /* for(nCount=0;nCount<gPEImageCount;nCount++) */
        for (nCount = 0; nCount < MAXIMUM_PICTURE_EDITOR_IMAGES; nCount++)
        {
            if (gPicEditorInfo[nCount].ImagesId == ImageId)
            {
                return (S8*) gPicEditorInfo[nCount].ImageName;
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetPictureEditorImageNameWithPathInFileSystem
 * DESCRIPTION
 *  Get image name with full path by image id input
 *  
 *  returns poiinter to the image name with full path if found else NULL
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  S8*
 *****************************************************************************/
S8 *GetPictureEditorImageNameWithPathInFileSystem(U32 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *fileName = NULL;
    static S8 imageData[MAX_IMAGE_NAME_PATH_WIDTH + MAX_IMAGE_NAME_WIDTH];
    S8 imagePath[100];
    int nCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ImageId >= PICTURE_EDITOR_IMAGE_BASE && ImageId <= PICTURE_EDITOR_IMAGE_BASE_END)
    {
        /* for(nCount=0;nCount<gPEImageCount;nCount++) */
        for (nCount = 0; nCount < MAXIMUM_PICTURE_EDITOR_IMAGES; nCount++)
        {
            if (gPicEditorInfo[nCount].ImagesId == ImageId)
            {
                fileName = (U8*) gPicEditorInfo[nCount].ImageName;
                break;
            }
        }
        /* if(nCount==gPEImageCount) return NULL; */
        if (nCount == MAXIMUM_PICTURE_EDITOR_IMAGES)
        {
            return NULL;
        }

        memset(imagePath, 0, sizeof(imagePath));
        sprintf(imagePath, "%c:\\", MMI_PUBLIC_DRV);
        mmi_asc_to_ucs2(imageData, imagePath);
        mmi_ucs2cat((S8*) imageData, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
        mmi_ucs2cat((PS8) imageData, (PS8) fileName);
        return imageData;
    }
    return NULL;
}

#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 

