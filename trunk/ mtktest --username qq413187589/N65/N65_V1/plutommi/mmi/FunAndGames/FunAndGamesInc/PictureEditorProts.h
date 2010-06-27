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
 *  PictureEditorProts.h
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

   FILENAME : PictureEditorProts.h

   PURPOSE     : Funtion Prototypes for the Picture Editor Application

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : Jan-13-2004

**************************************************************/

#ifndef PICTUREEDITORPROTS_H
#define PICTUREEDITORPROTS_H

#include "gui_data_types.h"
#include "PictureEditorDefs.h"
#include "DownloadDefs.h"

/* [~PMT  MANISH   20050302 */
#ifdef __MMI_TOUCH_SCREEN__

#include "kal_non_specific_general_types.h"
#include "TouchScreenGprot.h"

typedef enum
{
    GUI_IMAGE_EDITOR_PEN_NONE,
    GUI_IMAGE_EDITOR_PEN_TITLE_EVENT
} mmi_image_editor_pen_enum;

#endif /* __MMI_TOUCH_SCREEN__ */ 
/* ~] */
/**********************Global function prototypes************************/
/* Picture Editor */
extern void InitPictureEditor(void);
extern void InitPicEditPen(void);
extern void EntryScr4PicEditSelectMenu(void);
extern void ExitScr4PicEditSelectMenu(void);
extern void ChangePicEditSelectMenuSoftKey(S32 nIndex);
extern void EntryPicEditAddPic(void);

extern void ShowPicEditPrevImage(void);
extern void ShowPicEditNextImage(void);
extern void ShowPicEditImage(void);
extern void EntryScr4PicEditViewOpt(void);
extern void ExitScr4PicEditViewOpt(void);
extern void SelPEViewOptEdit(void);
extern void SelPEViewOptDelete(void);
extern void SelPEViewOptDeleteAll(void);
extern void EntryPicEditViewOpt(void);
extern void EntryScr4PicEditDeleteConfirm(void);
extern void ExitScr4PicEditDeleteConfirm(void);
extern void PicEditDeleteImage(void);
extern MMI_BOOL SetDeletePicEditImage(void);
extern void EntryScr4PicEditDeleteAllConfirm(void);
extern void ExitScr4PicEditDeleteAllConfirm(void);
extern void PicEditDeleteAllImages(void);
extern void SetDeleteAllPicEditImage(void);

extern void EntryScr4PicEditEditOpt(void);
extern void ExitScr4PicEditEditOpt(void);
extern void SelPEEditOptSavePic(void);
extern void SelPEEditOptSavePicAs(void);
extern void SelPEEditOptPenSetting(void);
extern void SelPEEditOptFillPic(void);
extern void SelPEEditOptMark(void);
extern void SelPEEditOptCut(void);
extern void SelPEEditOptCopy(void);
extern void SelPEEditOptPaste(void);
extern void SelPEEditOptUndo(void);
extern void SelPEEditOptRedo(void);
extern void SelPEEditOptZoom(void);
extern void SelPEEditOptFullSize(void);
extern void SelPEEditOptResize(void);
extern void SelPEEditOptHelp(void);
extern void EntryPEEditOpt(void);
extern void EntryScr4PicEditSaveAs(void);
extern void ExitScr4PicEditSaveAs(void);
extern void SetPicEditCurrPic(S32 nIndex);
extern void PicEditSaveImageAs(void);
extern void EntryScr4PicEditSaveAsConfirm(void);
extern void ExitScr4PicEditSaveAsConfirm(void);
extern void GoBackPicEditSaveAsConfirmHistory(void);
extern void ReplacePicEditSelectedImage(void);
extern void EntryScr4PicEditPenSetting(void);
extern void ExitScr4PicEditPenSetting(void);
extern void GoBackPicEditPenSettingHistory(void);
extern void PicEditPenSettingInlineEdit(S32 nIndex);
extern void PicEditPenSettingSelectInlineEdit(S32 index);
extern void ChangePenSettingSoftkey(void);
extern void EntryScr4PicEditPenSettingSaveConfirm(void);
extern void ExitScr4PicEditPenSettingSaveConfirm(void);
extern void GoBackPicEditPenSettingConfirmHistory(void);
extern void SavePicEditPenSetting(void);
extern void EntryScr4PicEditFillPic(void);
extern void ExitScr4PicEditFillPic(void);
extern void ChangeSoftkeyFillPic(S32 index);
extern void PicEditFillPicSelectInlineEdit(S32 index);
extern void EntryScr4PicEditFillPicSaveConfirm(void);
extern void ExitScr4PicEditFillPicSaveConfirm(void);
extern void GoBackPicEditFillPicConfirmHistory(void);
extern void SavePicEditFillPic(void);
extern void EntryScr4PicEditScrResize(void);
extern void ExitScr4PicEditScrResize(void);
extern void FillPicEditResizeInLine(InlineItem *ResizeInline);
extern void HighlightResizeInlineItemHandler(S32 index);
extern void ChangeResizeSoftKey(S32 nIndex);
extern void SetResizeInlineItemValues(void);
extern void ValidateScrWidthHeight(void);
extern void EntryScr4PicEditHelp(void);
extern void ExitScr4PicEditHelp(void);
extern void EntryScr4PicEditCustomColor(void);
extern void ExitScr4PicEditCustomColor(void);
extern void SavePicEditCustomColor(void);
extern void EntryScr4PicEditSaveImageConfirm(void);
extern void ExitScr4PicEditSaveImageConfirm(void);
extern void GoBackPicEditSaveImageConfirmHistory(void);
extern void PicEditSaveImage(void);
extern void SetPicEditPenAtCenter(BOOL bFlag);
extern void SetPicEditPenBoundary(void);
extern U8 SearchPicEditFileName(S8 *sFile);
extern U8 *GetPicEditCurrentImageName(void);
extern U16 GetPicEditCurrentImageId(void);
extern BOOL SetPicEditPenMarkBoundary(void);
extern U8 GetPicEditScr(void);
extern BOOL CheckPicEditPenSettingChange(void);
extern void ReadPicEditListFromNVRAM(void);
extern void WritePicEditListToNVRAM(void);
extern S8 AddPictureEditorImage(S8 *fileName);
extern S8 AddPictureEditorImageAtIndex(S8 *fileName, U8 nIndex);
extern S8 DeletePictureEditorImage(U32 ImageId);
extern U8 GetPictureEditorImageInfo(DYNIMAGEINFO **pictureEditorInfo);
extern S8 *GetPictureEditorImageNameInFileSystem(U32 ImageId);
extern S8 *GetPictureEditorImageNameWithPathInFileSystem(U32 ImageId);

/* Picture Editor Engine */
extern void ShowCategoryScr4PicEdit(
                U16 colorStringId,
                color penColor,
                U16 pixelStringId,
                U8 penPixel,
                U16 penImageId,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 background_imageid,
                U8 *imageData);
extern void ShowPicEditTitleBar(U16 colorStringId, color penColor, U16 pixelStringId, U8 penPixel, U16 penImageId);
extern void RedrawPicEditTitleBar(void);
extern void ShowPicEditImageWindow(U8 *imageData);
extern void ShowPicEditMarkBox(U16 scrMinX, U16 scrMinY);
extern void DisplayPECursor(void);
extern void EntryScr4PicEditShowImage(void);
extern void ExitScr4PicEditShowImage(void);
extern void ChangePicEditShowImageSoftkey(void);
extern void EntryScr4PicEditEditImage(void);
extern void ExitScr4PicEditEditImage(void);
extern void ChangePicEditEditImageSoftkey(void);
extern void GoBackHistory4PicEditEditImage(void);
extern void PECommitLastAction(void);
extern void PECancelLastAction(void);
extern void SetPicEditZoomWindow(BOOL bFlag);

/* Picture Editor Handlers - Key */
extern void InitPicEditKeyHandlers(void);
extern void InitPicEditHiliteHandlers(void);
extern void DrawPicOnKey_1(void);
extern void DrawPicOnKey_2(void);
extern void DrawPicOnKey_3(void);
extern void DrawPicOnKey_4(void);
extern void DrawPicOnKey_5(void);
extern void DrawPicOnKey_6(void);
extern void DrawPicOnKey_7(void);
extern void DrawPicOnKey_8(void);
extern void DrawPicOnKey_9(void);
extern void DrawPECursor(U16 key);
extern void ChangePEZoomFactor(void);
extern void ChangePEPenSize(void);
extern void ChangePEPenColor(void);

/* 051605 Calvin added */
#if defined (__MMI_MAINLCD_240X320__)
extern void ChangePEFillColor(void);
#endif 
/* Calvin end */
extern BOOL CheckPenMove(U8 movX, U8 movY);
extern void SetPenMove(U8 movX, U8 movY);

/* [~PMT  MANISH   20050302 */

#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_register_image_editor_pen_handlers(void);
extern void mmi_image_editor_pen_up_handler(mmi_pen_point_struct point);
extern void mmi_image_editor_pen_down_handler(mmi_pen_point_struct point);
extern void mmi_image_editor_pen_move_handler(mmi_pen_point_struct point);
extern void mmi_image_editor_pen_abort_handler(mmi_pen_point_struct point);

/* 051605 Calvin added */
#if 0   /* should be defined(__MMI_MAINLCD_240X320__) */
/* under construction !*/
#endif /* 0 */ 
/* Calvin end */
extern pBOOL mmi_general_image_editor_pen_handler(
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                mmi_image_editor_pen_enum *image_editor_event);
extern pBOOL HandleImageEditorTitleEvent(U16 X, U16 Y);
extern void SetPenPosition(U16 movX, U16 movY);
extern void DrawPECursorAt(U16 x, U16 y);

#endif /* __MMI_TOUCH_SCREEN__ */ /* __MMI_TOUCH_SCREEN_ */
/* ~] */

/* Picture Editor Handlers - File */
extern U8 *ParseImageBuffer(U8 *imageBuffer, PE_File_Header *imageFileHeader, PE_Info_Header *imageInfoHeader);
extern void SetImageBuffer(S8 *fileBuff, PE_File_Header *imageFileHeader, PE_Info_Header *imageInfoHeader);
extern void PasteBoxInImageBuffer(U8 *destBuffer, U8 *srcBuffer);
extern void DrawZoomImage(
                U8 *inBuffer,
                U32 nImage_X,
                U32 nImage_Y,
                U8 nZoom_Factor,
                U32 nScr_X,
                U32 nScr_Y,
                U32 nScr_Height,
                U32 nScr_Width);
extern void PutPixtelInBuff(U16 x1, U16 y1, U16 x2, U16 y2, U8 *pBuff);
extern void InitRedoUndoBuffers(void);
extern void SavePEContext(void);
extern void ExchangePEContext(void);
extern void SaveDataBuffer(void);
extern void SetPicEditEmptyImageDataBuff(void);
extern BOOL SetPicEditImageDataBuff(U8 *fileName);
extern void ResizePicEditImageDataBuff(void);
extern void GetPaletteInfo(U8 *info_palette);
extern void SetCurrentImageParams(void);
extern U16 GetImageWidth(U16 xMin, U16 xMax);
extern color GetPEColor(U32 selColor);
extern void SyncPicEditFileSystem(S8 *DirPath, DYNAMICINFO *dynInfo);

/**********************Extern Global Variables************************/
extern U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];

extern void UI_draw_dashed_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);

#endif /* PICTUREEDITORPROTS_H */ 

