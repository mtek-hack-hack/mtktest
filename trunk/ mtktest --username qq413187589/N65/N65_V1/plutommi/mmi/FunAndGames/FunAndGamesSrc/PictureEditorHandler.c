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
 *  PictureEditorHandler.c
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

   FILENAME : PictureEditorHandler.c

   PURPOSE     : Main functions of the Picture Editor Key Handlers

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : Jan-13-2004

**************************************************************/
#include "MMI_include.h"

#include "PictureEditorDefs.h"
#include "PictureEditorProts.h"
#include "CustDataProts.h"
#include "MainMenuDef.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "gui.h"
/* [~PMT  MANISH   20050314 */
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#include "gui_buttons.h"
#include "wgui_softkeys.h"
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* ~] */
#include "FileMgr.h"    /* Should include FileMgr.h before ProfileMgrGprot.h */
#include "FileManagerGProt.h"

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__

/* [~PMT  MANISH   20050314 */
#ifdef __MMI_TOUCH_SCREEN__
extern PicEditMarkBox gPicEditZoomWindow;
extern void (*left_softkey_functions[]) (void);
extern void (*right_softkey_functions[]) (void);

enum PEN_ON_CONTROL
{
    NONE_IE = 0,
    LSK_IE,                     /* LSK on Image Editor Screen */
    RSK_IE,                     /* RSK on Image Editor Screen */
    IMAGE_EDITOR_AREA           /* Image Area on Image Editor Screen (Also set if pen event is on Title of Image Editor */
};
static int image_pen_control;   /* Specifies on which part of Image Editor Screen Pen Event occurs */
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* ~] */

/**********************Defines************************/
#define PIC_EDIT_READ_PIXEL(nIndex,nColumn,nData,dataBuffer,nBitsPerPixel) {                            \
   switch(nBitsPerPixel){                                                                               \
   case 4: if((nColumn)%2)nData=(U32)(dataBuffer[nIndex]&0x0F);                                         \
         else nData=(U32)((dataBuffer[nIndex]&0xF0)>>nBitsPerPixel);                                    \
         break;                                                                                         \
   case 8: nData=(U32)(dataBuffer[nIndex]);                                                             \
         break;                                                                                         \
   case 16:nData=(U32)(((U32)dataBuffer[nIndex]<<8)|(dataBuffer[nIndex+1]));                            \
         break;                                                                                         \
   case 24: nData=(((U32)dataBuffer[nIndex]<<16)|((U32)dataBuffer[nIndex+1]<<8)|(dataBuffer[nIndex+2]));\
         break;                                                                                         \
   default: nData=(U32)(-1);                                                                            \
         break;                                                                                         \
   }                                                                                                    \
   }

#define PIC_EDIT_WRITE_PIXEL(nIndex,nColumn,nData,dataBuffer,nBitsPerPixel) {                    \
   switch(nBitsPerPixel){                                                                        \
   case 4: if((nColumn)%2)dataBuffer[nIndex]=(U8)(0xF0&dataBuffer[nIndex])|(0x0F& (U8)nData);    \
         else dataBuffer[nIndex]=(U8)(0x0F&dataBuffer[nIndex])|((0x0F&(U8)nData)<<nBitsPerPixel);\
         break;                                                                                  \
   case 8: dataBuffer[nIndex]=(U8)nData;break;                                                   \
   case 16:dataBuffer[nIndex]=(U8)(nData>>8);                                                    \
         dataBuffer[nIndex+1]=(U8)nData;break;                                                   \
   case 24:dataBuffer[nIndex]=(U8)(nData>>16);                                                   \
         dataBuffer[(nIndex+1)]=(U8)(nData>>8);                                                  \
         dataBuffer[nIndex+2]=(U8)nData;break;                                                   \
   default: dataBuffer[nIndex]=(U8)(0x00);break;                                                 \
   }                                                                                             \
   }

/**********************Local Variables************************/
/* 051605 Calvin modified */
// #ifdef __USE_MAIN_MENU_MATRIX_BUFFER
#if defined (__USE_MAIN_MENU_MATRIX_BUFFER) && !defined(__MMI_MAINLCD_240X320__)
/* Calvin end */
extern U8 matrix_main_menu_highlight_bitmap_data[];
U8 *gPEBackupImageData = matrix_main_menu_highlight_bitmap_data;        /* make sure the buffer is less then the matrix menu buffer size */
#else /* defined (__USE_MAIN_MENU_MATRIX_BUFFER) && !defined(__MMI_MAINLCD_240X320__) */ 
static U8 gPEBackupImageData[MAX_IMAGE_HEADER_LENGTH + PIC_EDIT_FILE_BUFF];
#endif /* defined (__USE_MAIN_MENU_MATRIX_BUFFER) && !defined(__MMI_MAINLCD_240X320__) */ 
static U8 gPEImageData[MAX_IMAGE_HEADER_LENGTH + PIC_EDIT_FILE_BUFF];

/* static U8 gPEBackupImageData[MAX_IMAGE_HEADER_LENGTH+PIC_EDIT_FILE_BUFF]; */
static PictureEditorPen gPicEditPen;
static PictureEditorPen gPicEditBackupPen;

/* 010306 image editor Calvin Start */
#if defined (__MMI_MAINLCD_240X320__)
static U8 gPicEditFillColorIndex;
static U8 gPicEditFillBackupColorIndex;
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
/* Calvin end */

/**********************Global Variables************************/
U8 *gpPEFileBuff = &gPEImageData[MAX_IMAGE_HEADER_LENGTH];
U8 *gpPEBackupFileBuff; /* =&gPEBackupImageData[MAX_IMAGE_HEADER_LENGTH]; */
PU8 gpPEBackupDataBuff = (PU8) hintData;

PictureEditorPen *gpPicEditBackupPen = &gPicEditBackupPen;
PictureEditorPen *gpPicEditPen = &gPicEditPen;
PicEditMarkBox gPicEditMark;
U8 gPEBitsPerPixel = 4;

/* 010306 image editor Calvin Start */
#if defined (__MMI_MAINLCD_240X320__)
U8 *gpPicEditFillColorIndex = &gPicEditFillColorIndex;
U8 *gpPicEditFillBackupColorIndex = &gPicEditFillBackupColorIndex;
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
/* Calvin end */

/**********************Extern Variables************************/
extern U16 gPEAttrib;
extern U8 gPECurrentAction;

extern S16 gPEImageWidth;
extern S16 gPEImageHeight;
extern U32 gPEColorRGB[];
extern U8 gPEZoomFactor;
extern S16 gPEImageWidth_bak;
extern S16 gPEImageHeight_bak;


/*****************************************************************************
 * FUNCTION
 *  InitPicEditKeyHandlers
 * DESCRIPTION
 *  Initialize Key Handlers for editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitPicEditKeyHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(DrawPicOnKey_1, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_2, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_3, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_4, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_5, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_6, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_7, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_8, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(DrawPicOnKey_9, KEY_9, KEY_EVENT_DOWN);

    SetKeyHandler(ChangePEZoomFactor, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(ChangePEPenSize, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(ChangePEPenColor, KEY_POUND, KEY_EVENT_DOWN);

    SetKeyHandler(DrawPicOnKey_1, KEY_1, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_2, KEY_2, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_3, KEY_3, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_4, KEY_4, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_6, KEY_6, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_7, KEY_7, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_8, KEY_8, KEY_REPEAT);
    SetKeyHandler(DrawPicOnKey_9, KEY_9, KEY_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  InitPicEditHiliteHandlers
 * DESCRIPTION
 *  Initialize Hilite Handlers for Image Editor Options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitPicEditHiliteHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_PE_EDIT_OPT_SAVE_PIC, SelPEEditOptSavePic);
    SetHiliteHandler(MENU_PE_EDIT_OPT_SAVE_PIC_AS, SelPEEditOptSavePicAs);
    SetHiliteHandler(MENU_PE_EDIT_OPT_PEN_SETTING, SelPEEditOptPenSetting);
    SetHiliteHandler(MENU_PE_EDIT_OPT_FILL_PIC, SelPEEditOptFillPic);
    SetHiliteHandler(MENU_PE_EDIT_OPT_MARK, SelPEEditOptMark);
    SetHiliteHandler(MENU_PE_EDIT_OPT_CUT, SelPEEditOptCut);
    SetHiliteHandler(MENU_PE_EDIT_OPT_COPY, SelPEEditOptCopy);
    SetHiliteHandler(MENU_PE_EDIT_OPT_PASTE, SelPEEditOptPaste);
    SetHiliteHandler(MENU_PE_EDIT_OPT_UNDO, SelPEEditOptUndo);
    SetHiliteHandler(MENU_PE_EDIT_OPT_REDO, SelPEEditOptRedo);
    SetHiliteHandler(MENU_PE_EDIT_OPT_ZOOM, SelPEEditOptZoom);
    SetHiliteHandler(MENU_PE_EDIT_OPT_FULL_SIZE, SelPEEditOptFullSize);
    SetHiliteHandler(MENU_PE_EDIT_OPT_RESIZE, SelPEEditOptResize);
    SetHiliteHandler(MENU_PE_EDIT_OPT_HELP, SelPEEditOptHelp);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_1
 * DESCRIPTION
 *  Handles Key 1 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(1);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_2
 * DESCRIPTION
 *  Handles Key 2 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(2);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_3
 * DESCRIPTION
 *  Handles Key 3 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(3);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_4
 * DESCRIPTION
 *  Handles Key 4 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(4);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_5
 * DESCRIPTION
 *  Handles Key 5 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE) || (gPECurrentAction == SEL_PE_EDIT_OPT_MARK))
    {
        return;
    }
    TOGGLE_PE_PEN_DOWN(gPEAttrib);
    if (IS_PE_PEN_DOWN(gPEAttrib))
    {
        SavePEContext();
        PutPixtelInBuff(
            gpPicEditPen->penX,
            gpPicEditPen->penY,
            (U16) (gpPicEditPen->penX + gpPicEditPen->penPixel),
            (U16) (gpPicEditPen->penY + gpPicEditPen->penPixel),
            &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE]);
        SET_PE_IMAGE_CHANGED(gPEAttrib);
    }

    RedrawPicEditTitleBar();
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_6
 * DESCRIPTION
 *  Handles Key 6 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(6);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_7
 * DESCRIPTION
 *  Handles Key 7 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(7);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_8
 * DESCRIPTION
 *  Handles Key 8 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(8);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPicOnKey_9
 * DESCRIPTION
 *  Handles Key 9 Down Event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPicOnKey_9(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawPECursor(9);
}


/*****************************************************************************
 * FUNCTION
 *  DrawPECursor
 * DESCRIPTION
 *  Common function to Handle all key events on image editor screen
 *  
 *  Called for key 1-9 event handlers on image editor
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPECursor(U16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 lastMov;
    U8 xMov = CUR_NO_MOVE;
    U8 yMov = CUR_NO_MOVE;
    U8 nCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PE_PEN_DOWN(gPEAttrib))
    {
        if (gPECurrentAction != SEL_PE_EDIT_OPT_MARK)
        {
            if (gPECurrentAction == SEL_PE_EDIT_OPT_UNDO || gPECurrentAction == SEL_PE_EDIT_OPT_REDO)
            {
                SavePEContext();
                gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
            }
            else
            {
                if (lastMov != key)
                {
                    SavePEContext();
                }
            }
        }
    }

    lastMov = (U8) key;

    switch (key)
    {
        case 1:
            xMov = yMov = CUR_DECREMENT;
            break;
        case 2:
            yMov = CUR_DECREMENT;
            break;
        case 3:
            xMov = CUR_INCREMENT;
            yMov = CUR_DECREMENT;
            break;
        case 4:
            xMov = CUR_DECREMENT;
            break;
        case 6:
            xMov = CUR_INCREMENT;
            break;
        case 7:
            xMov = CUR_DECREMENT;
            yMov = CUR_INCREMENT;
            break;
        case 8:
            yMov = CUR_INCREMENT;
            break;
        case 9:
            xMov = yMov = CUR_INCREMENT;
            break;
        default:
            break;
    }

    if ((gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE) || (gPECurrentAction == SEL_PE_EDIT_OPT_MARK))
    {
        if (!CheckPenMove(xMov, yMov))
        {
            playRequestedTone(WARNING_TONE);
            return;
        }
        SetPenMove(xMov, yMov);
        if (IS_PE_ZOOM_IMAGE(gPEAttrib))
        {
            SetPicEditZoomWindow(FALSE);
        }
    }
    else
    {
        for (nCount = 0; nCount < gpPicEditPen->penMove; nCount++)
        {
            if (!CheckPenMove(xMov, yMov))
            {
                if (nCount)
                {
                    break;
                }
                else
                {
                    playRequestedTone(WARNING_TONE);
                    return;
                }
            }
            SetPenMove(xMov, yMov);
            if (IS_PE_ZOOM_IMAGE(gPEAttrib))
            {
                SetPicEditZoomWindow(FALSE);
            }
        }
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

/* [~PMT  MANISH   20050302 Function for setting pen position */
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL pe_in_draw_line = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  SetPenPosition
 * DESCRIPTION
 *  Sets Pen's penx and peny according to location of Pen Event
 *  
 *  Calculate gpPicEditPen's penX and penY according to the position of pen event
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPenPosition(U16 x, U16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prevX, prevY;
    U16 minX, minY, maxX, maxY, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PE_ZOOM_IMAGE(gPEAttrib))
    {
        if (((gPicEditZoomWindow.maxX - gPicEditZoomWindow.minX) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
        {
            minX = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
            maxX = minX + PE_SCR_SIZE_MAX;
        }
        else
        {
            minX = SET_WINDOW_MINX((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
            maxX = minX + ((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
        }

        if (((gPicEditZoomWindow.maxY - gPicEditZoomWindow.minY) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
        {
            minY = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);
            maxY = minY + PE_SCR_SIZE_MAX;
        }
        else
        {
            minY = SET_WINDOW_MINY((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
            maxY = minY + ((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
        }

        /* Previous position of cursor */
        prevX = minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor;
        prevY = minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor;

        if (x > prevX + gpPicEditPen->penPixel * gPEZoomFactor - 1)
        {
            j = pixtel_highdivide(
                    x - (prevX + gpPicEditPen->penPixel * gPEZoomFactor - 1),
                    gpPicEditPen->penPixel * gPEZoomFactor);
            gpPicEditPen->penX += (j) * gpPicEditPen->penPixel;
        }
        if (x < prevX)
        {
            j = pixtel_highdivide(prevX - x, gpPicEditPen->penPixel * gPEZoomFactor);
            gpPicEditPen->penX -= (j) * gpPicEditPen->penPixel;
        }
        if (y > prevY + gpPicEditPen->penPixel * gPEZoomFactor - 1)
        {
            j = pixtel_highdivide(
                    y - (prevY + gpPicEditPen->penPixel * gPEZoomFactor - 1),
                    gpPicEditPen->penPixel * gPEZoomFactor);
            gpPicEditPen->penY += (j) * gpPicEditPen->penPixel;
        }
        if (y < prevY)
        {
            j = pixtel_highdivide(prevY - y, gpPicEditPen->penPixel * gPEZoomFactor);
            gpPicEditPen->penY -= (j) * gpPicEditPen->penPixel;
        }

    }
    else    /* Normal Image */
    {
        prevX = gpPicEditPen->penX;
        prevY = gpPicEditPen->penY;

        if (x > prevX + gpPicEditPen->penPixel - 1)
        {
            j = pixtel_highdivide(x - (prevX + gpPicEditPen->penPixel - 1), gpPicEditPen->penPixel);
            gpPicEditPen->penX += (j) * gpPicEditPen->penPixel;

        }
        if (x < prevX)
        {
            j = pixtel_highdivide(prevX - x, gpPicEditPen->penPixel);
            gpPicEditPen->penX -= (j) * gpPicEditPen->penPixel;
        }
        if (y > prevY + gpPicEditPen->penPixel - 1)
        {
            j = pixtel_highdivide(y - (prevY + gpPicEditPen->penPixel - 1), gpPicEditPen->penPixel);
            gpPicEditPen->penY += (j) * gpPicEditPen->penPixel;
        }
        if (y < prevY)
        {
            j = pixtel_highdivide(prevY - y, gpPicEditPen->penPixel);
            gpPicEditPen->penY -= (j) * gpPicEditPen->penPixel;
        }
    }
    /* Check Pen Position Before putting pixel in the image buffer
       Need to recheck here because of Pen Move Events */
    if (gpPicEditPen->penX < gpPicEditPen->minX)
    {
        gpPicEditPen->penX = gpPicEditPen->minX;
        PRINT_INFORMATION("\n<<PENX LESS	SETTING TO MIN>>");
    }
    if (gpPicEditPen->penY < gpPicEditPen->minY)
    {
        gpPicEditPen->penY = gpPicEditPen->minY;
        PRINT_INFORMATION("\n<<PENY LESS	SETTING TO MIN>>");
    }
    if ((gpPicEditPen->penX + gpPicEditPen->penPixel) > gpPicEditPen->maxX)
    {
        if (gPECurrentAction == SEL_PE_EDIT_OPT_MARK)
        {
            gpPicEditPen->penX = gpPicEditPen->maxX - 1;
        }
        else
        {
            gpPicEditPen->penX = gpPicEditPen->maxX - gpPicEditPen->penPixel;
        }
        PRINT_INFORMATION("\n<<PENX MORE	SETTING To MAXX>>");
    }
    if ((gpPicEditPen->penY + gpPicEditPen->penPixel) > gpPicEditPen->maxY)
    {
        if (gPECurrentAction == SEL_PE_EDIT_OPT_MARK)
        {
            gpPicEditPen->penY = gpPicEditPen->maxY - 1;
        }
        else
        {
            gpPicEditPen->penY = gpPicEditPen->maxY - gpPicEditPen->penPixel;
        }
        PRINT_INFORMATION("\n<<PENY MORE	SETTING TO MAXY>>");
    }
    if (IS_PE_PEN_DOWN(gPEAttrib) && (gPECurrentAction != SEL_PE_EDIT_OPT_MARK))
    {
        PutPixtelInBuff(
            gpPicEditPen->penX,
            gpPicEditPen->penY,
            (U16) (gpPicEditPen->penX + gpPicEditPen->penPixel),
            (U16) (gpPicEditPen->penY + gpPicEditPen->penPixel),
            &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE]);
    }
}

/* ~] */

/* [~PMT  MANISH   20050302 Function For Drawing cursor at x,y location in Touch Screen */


/*****************************************************************************
 * FUNCTION
 *  DrawPECursorAt
 * DESCRIPTION
 *  Function to Draw cursor at x,y location
 *  
 *  Called for Touch Screen Functionality where user can point pen anywhere,
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void DrawPECursorAt(U16 x, U16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* static U8 oldxMov=CUR_NO_MOVE,oldyMov=CUR_NO_MOVE; */
    U8 xMov = CUR_NO_MOVE;
    U8 yMov = CUR_NO_MOVE;
    U16 oldX, oldY;
    U16 minX, minY;
    U16 base_x, base_y;
    U16 temp_x, temp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PE_ZOOM_IMAGE(gPEAttrib))
    {
        if (((gPicEditZoomWindow.maxX - gPicEditZoomWindow.minX) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
        {
            minX = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
        }
        else
        {
            minX = SET_WINDOW_MINX((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
        }
        if (((gPicEditZoomWindow.maxY - gPicEditZoomWindow.minY) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
        {
            minY = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);
        }
        else
        {
            minY = SET_WINDOW_MINY((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
        }

        base_x = oldX = minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor;
        base_y = oldY = minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor;

        if (x > (oldX + gpPicEditPen->penPixel * gPEZoomFactor - 1))
        {
            xMov = CUR_INCREMENT;
            base_x = (x - gPicEditPen.minX) / gPEZoomFactor + gPicEditZoomWindow.minX - gpPicEditPen->penPixel;
        }
        if (x < oldX)
        {
            xMov = CUR_DECREMENT;
            base_x = (x - gPicEditPen.minX) / gPEZoomFactor + gPicEditZoomWindow.minX + gpPicEditPen->penPixel;
        }
        if (y > (oldY + gpPicEditPen->penPixel * gPEZoomFactor - 1))
        {
            yMov = CUR_INCREMENT;
            base_y = (y - gPicEditPen.minY) / gPEZoomFactor + gPicEditZoomWindow.minY - gpPicEditPen->penPixel;
        }
        if (y < oldY)
        {
            yMov = CUR_DECREMENT;
            base_y = (y - gPicEditPen.minY) / gPEZoomFactor + gPicEditZoomWindow.minY + gpPicEditPen->penPixel;
        }
    }
    else
    {
        oldX = gpPicEditPen->penX;
        oldY = gpPicEditPen->penY;
        if (x > oldX + gpPicEditPen->penPixel - 1)
        {
            xMov = CUR_INCREMENT;
            base_x = x - gpPicEditPen->penPixel;
        }
        if (x < oldX)
        {
            xMov = CUR_DECREMENT;
            base_x = x + gpPicEditPen->penPixel;
        }
        if (y > oldY + gpPicEditPen->penPixel - 1)
        {
            yMov = CUR_INCREMENT;
            base_y = y - gpPicEditPen->penPixel;
        }
        if (y < oldY)
        {
            yMov = CUR_DECREMENT;
            base_y = y + gpPicEditPen->penPixel;
        }
    }

    if (xMov == CUR_NO_MOVE && yMov == CUR_NO_MOVE) /* Position Not Changed */
    {
        return;
    }
    if (IS_PE_PEN_DOWN(gPEAttrib))
    {
        if (gPECurrentAction != SEL_PE_EDIT_OPT_MARK)
        {
            if (gPECurrentAction == SEL_PE_EDIT_OPT_UNDO || gPECurrentAction == SEL_PE_EDIT_OPT_REDO)
            {
                PRINT_INFORMATION("SAVING CONTEXT");
                SavePEContext();
                gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
            }
            else
            {
                /* Performance issue  PMT   MANISH   20050329
                   Save context only when pen is in UP state after pen DOWN event.
                   Undo/Redo will undo/redo the whole pen move (with pen down) */
                if (!gpPicEditPen->penContextSaved)
                {
                    PRINT_INFORMATION("SAVING CONTEXT");
                    SavePEContext();
                    gpPicEditPen->penContextSaved = MMI_TRUE;   /* penContextSaved is set to FALSE when pen state is UP */
                }
            }
        }
    }
    if (pe_in_draw_line == MMI_FALSE)
    {
        if ((gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE) || (gPECurrentAction == SEL_PE_EDIT_OPT_MARK))
        {
            temp_x = gpPicEditPen->penX;
            temp_y = gpPicEditPen->penY;
            gpPicEditPen->penX = base_x;
            gpPicEditPen->penY = base_y;
            if (!CheckPenMove(xMov, yMov))
            {
                playRequestedTone(WARNING_TONE);
                gpPicEditPen->penX = temp_x;
                gpPicEditPen->penY = temp_y;
                return;
            }
            gpPicEditPen->penX = temp_x;
            gpPicEditPen->penY = temp_y;
            SetPenPosition(x, y);
            if (IS_PE_ZOOM_IMAGE(gPEAttrib))
            {
                SetPicEditZoomWindow(FALSE);
            }
        }
        else
        {
            /* PenPixel is taken care of in SetPosition function and Need not take in to account pen move 
               as move matters only when user moves from one location to neighbour location. In touch screen user
               can point pen anywhere */
            temp_x = gpPicEditPen->penX;
            temp_y = gpPicEditPen->penY;
            gpPicEditPen->penX = base_x;
            gpPicEditPen->penY = base_y;
            if (!CheckPenMove(xMov, yMov))
            {
                playRequestedTone(WARNING_TONE);
                PRINT_INFORMATION("\nCHECK MOVE FAIL");
                gpPicEditPen->penX = temp_x;
                gpPicEditPen->penY = temp_y;
                return;
            }
            gpPicEditPen->penX = temp_x;
            gpPicEditPen->penY = temp_y;
            SetPenPosition(x, y);
            if (IS_PE_ZOOM_IMAGE(gPEAttrib))
            {
                SetPicEditZoomWindow(FALSE);
            }
        }

        gdi_layer_lock_frame_buffer();

        ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);

        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
    else
    {
        SetPenPosition(x, y);
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* ~] */
   


/*****************************************************************************
 * FUNCTION
 *  ChangePEZoomFactor
 * DESCRIPTION
 *  Toggles Zoom factor between 2 and 4
 *  
 *  Called for key 0 event handler on image editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePEZoomFactor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gPEZoomFactor = (gPEZoomFactor == 2) ? 4 : 2;
}


/*****************************************************************************
 * FUNCTION
 *  ChangePEPenSize
 * DESCRIPTION
 *  Changes Pen Size
 *  
 *  Called for key * event handler on image editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePEPenSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gpPicEditPen->penPixel)
    {
        case PIC_EDIT_PEN_PIXEL_1:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_2;
            break;
        case PIC_EDIT_PEN_PIXEL_2:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_3;
            break;
        case PIC_EDIT_PEN_PIXEL_3:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_4;
            break;
        case PIC_EDIT_PEN_PIXEL_4:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_1;
            break;
        default:
            gpPicEditPen->penPixel = PIC_EDIT_PEN_PIXEL_1;
            break;
    }
    RedrawPicEditTitleBar();
}


/*****************************************************************************
 * FUNCTION
 *  ChangePEPenColor
 * DESCRIPTION
 *  Changes Pen Color
 *  
 *  Called for key # event handler on image editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePEPenColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpPicEditPen->penColorIndex =
        (gpPicEditPen->penColorIndex >= (MAX_TYPE_PEN_COLOR - 1)) ? 1 : gpPicEditPen->penColorIndex + 1;
    RedrawPicEditTitleBar();
}

/* 051605 Calvin added */
#if defined (__MMI_MAINLCD_240X320__)


/*****************************************************************************
 * FUNCTION
 *  ChangePEFillColor
 * DESCRIPTION
 *  Changes Fill Color
 *  
 *  Called for key # event handler on image editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePEFillColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *gpPicEditFillColorIndex =
        (*gpPicEditFillColorIndex >= (MAX_TYPE_PEN_COLOR - 1)) ? 0 : (*gpPicEditFillColorIndex) + 1;
    RedrawPicEditTitleBar();
}
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
/* Calvin end */


/*****************************************************************************
 * FUNCTION
 *  CheckPenMove
 * DESCRIPTION
 *  Checks if the pen can be  moved in the input direction
 *  
 *  Returns false if cannot be moved in that direction
 * PARAMETERS
 *  movX        [IN]        
 *  movY        [IN]        
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
BOOL CheckPenMove(U8 movX, U8 movY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPECurrentAction)
    {
        case SEL_PE_EDIT_OPT_MARK:
            switch (movX)
            {
                case CUR_INCREMENT:
                    if (gpPicEditPen->penX >= (gpPicEditPen->maxX - 1))
                    {
                        return FALSE;
                    }
                    break;
                case CUR_DECREMENT:
                    if (gpPicEditPen->penX <= gpPicEditPen->minX)
                    {
                        return FALSE;
                    }
                    break;
            }
            switch (movY)
            {
                case CUR_INCREMENT:
                    if (gpPicEditPen->penY >= (gpPicEditPen->maxY - 1))
                    {
                        return FALSE;
                    }
                    break;
                case CUR_DECREMENT:
                    if (gpPicEditPen->penY <= gpPicEditPen->minY)
                    {
                        return FALSE;
                    }
                    break;
            }
            return TRUE;
        case SEL_PE_EDIT_OPT_RESIZE:
            switch (movX)
            {
                case CUR_INCREMENT:
                    if ((gpPicEditPen->penX + gPicEditMark.maxX - gPicEditMark.minX) >= gpPicEditPen->maxX - 1)
                    {
                        return FALSE;
                    }
                    break;
                case CUR_DECREMENT:
                    if (gpPicEditPen->penX <= gpPicEditPen->minX)
                    {
                        return FALSE;
                    }
                    break;
            }
            switch (movY)
            {
                case CUR_INCREMENT:
                    if ((gpPicEditPen->penY + gPicEditMark.maxY - gPicEditMark.minY) >= (gpPicEditPen->maxY - 1))
                    {
                        return FALSE;
                    }
                    break;
                case CUR_DECREMENT:
                    if (gpPicEditPen->penY <= gpPicEditPen->minY)
                    {
                        return FALSE;
                    }
                    break;
            }
            return TRUE;
        default:
            switch (movX)
            {
                case CUR_INCREMENT:
                    if ((gpPicEditPen->penX + gpPicEditPen->penPixel) >= gpPicEditPen->maxX)
                    {
                        return FALSE;
                    }
                    break;
                case CUR_DECREMENT:
                    if (gpPicEditPen->penX <= gpPicEditPen->minX)
                    {
                        return FALSE;
                    }
                    break;
            }
            switch (movY)
            {
                case CUR_INCREMENT:
                    if ((gpPicEditPen->penY + gpPicEditPen->penPixel) >= gpPicEditPen->maxY)
                    {
                        return FALSE;
                    }
                    break;
                case CUR_DECREMENT:
                    if (gpPicEditPen->penY <= gpPicEditPen->minY)
                    {
                        return FALSE;
                    }
                    break;
            }
            return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetPenMove
 * DESCRIPTION
 *  Moves the Pen to the direction inputs
 * PARAMETERS
 *  movX        [IN]        
 *  movY        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPenMove(U8 movX, U8 movY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (movX)
    {
        case CUR_INCREMENT:
            gpPicEditPen->penX += gpPicEditPen->penPixel;
            break;
        case CUR_DECREMENT:
            gpPicEditPen->penX -= gpPicEditPen->penPixel;
			break;
    }

    switch (movY)
    {
        case CUR_INCREMENT:
            gpPicEditPen->penY += gpPicEditPen->penPixel;
            break;
        case CUR_DECREMENT:
            gpPicEditPen->penY -= gpPicEditPen->penPixel;
            break;
    }
    if (IS_PE_PEN_DOWN(gPEAttrib) && (gPECurrentAction != SEL_PE_EDIT_OPT_MARK))
    {
        PutPixtelInBuff(
            gpPicEditPen->penX,
            gpPicEditPen->penY,
            (U16) (gpPicEditPen->penX + gpPicEditPen->penPixel),
            (U16) (gpPicEditPen->penY + gpPicEditPen->penPixel),
            &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE]);
    }
}

/* File Handlers */


/*****************************************************************************
 * FUNCTION
 *  ParseImageBuffer
 * DESCRIPTION
 *  Parse the image buffer passed and sets the structures
 *  
 *  returns Pointer to the data buffer
 * PARAMETERS
 *  imageBuffer         [?]         
 *  imageFileHeader     [?]         
 *  imageInfoHeader     [?]         
 *  byte(?)             [IN]        *,PE_File_Header,PE_Info_Header
 * RETURNS
 *  byte*
 *****************************************************************************/
U8 *ParseImageBuffer(U8 *imageBuffer, PE_File_Header *imageFileHeader, PE_Info_Header *imageInfoHeader)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 width, height;
    U16 BitPerPixel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((S8*) imageFileHeader, (S8*) imageBuffer, 2);
    memcpy(((S8*) imageFileHeader) + 4, imageBuffer + 2, 12);
    memcpy(imageInfoHeader, imageBuffer + 14, sizeof(PE_Info_Header));
    width = imageInfoHeader->width;
    height = imageInfoHeader->height;
    BitPerPixel = imageInfoHeader->bits_per_pixel;
    if (width > PE_SCR_SIZE_MAX || height > PE_SCR_SIZE_MAX || BitPerPixel != 4)
    {
        return NULL;
    }
    return &imageBuffer[imageFileHeader->bitmap_offset];
}


/*****************************************************************************
 * FUNCTION
 *  SetImageBuffer
 * DESCRIPTION
 *  Sets the imageBuffer with the imputs
 * PARAMETERS
 *  imageBuffer         [?]     
 *  imageFileHeader     [?]     
 *  imageInfoHeader     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SetImageBuffer(S8 *imageBuffer, PE_File_Header *imageFileHeader, PE_Info_Header *imageInfoHeader)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 infoPalette[MAX_TYPE_PEN_COLOR * 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((S8*) imageBuffer, (S8*) imageFileHeader, 2);
    memcpy(imageBuffer + 2, ((char*)imageFileHeader) + 4, 12);
    memcpy(imageBuffer + 14, imageInfoHeader, sizeof(PE_Info_Header));
    GetPaletteInfo(infoPalette);
    memcpy(imageBuffer + 54, &infoPalette, MAX_TYPE_PEN_COLOR * 4);
}


/*****************************************************************************
 * FUNCTION
 *  PasteBoxInImageBuffer
 * DESCRIPTION
 *  Paste the box into the image
 * PARAMETERS
 *  destBuffer      [?]     
 *  srcBuffer       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PasteBoxInImageBuffer(U8 *destBuffer, U8 *srcBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sx2, sy2, sx1 = gPicEditMark.minX, sy1 = gPicEditMark.minY;
    U16 dx2, dy2, dx1 = gpPicEditPen->penX, dy1 = gpPicEditPen->penY;
    U16 xCount, yCount, sIndex, dIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gpPicEditPen->penX + gPicEditMark.maxX - gPicEditMark.minX) <= gpPicEditPen->maxX)
    {
        sx2 = gPicEditMark.maxX;
        dx2 = gpPicEditPen->penX + gPicEditMark.maxX - gPicEditMark.minX;
    }
    else
    {
        sx2 = gPicEditMark.minX + gpPicEditPen->maxX - gpPicEditPen->penX;
        /* dx2=gpPicEditPen->maxX; */
        dx2 = gpPicEditPen->maxX - 1;
    }

    if ((gpPicEditPen->penY + gPicEditMark.maxY - gPicEditMark.minY) <= gpPicEditPen->maxY)
    {
        sy2 = gPicEditMark.maxY;
        dy2 = gpPicEditPen->penY + gPicEditMark.maxY - gPicEditMark.minY;
    }
    else
    {
        sy2 = gPicEditMark.minY + gpPicEditPen->maxY - gpPicEditPen->penY;
        dy2 = gpPicEditPen->maxY;
    }

    for (xCount = dx1; xCount <= dx2; xCount++)
        for (yCount = dy1; yCount <= dy2; yCount++)
        {
            U32 data = 0;

            dIndex =
                (gpPicEditPen->maxY - yCount - 1) * (GetImageWidth(gpPicEditPen->minX, gpPicEditPen->maxX)) +
                (U16) (((xCount - gpPicEditPen->minX) * gPEBitsPerPixel) >> 3);
            sIndex =
                (gpPicEditPen->maxY - (sy1 + yCount - dy1) -
                 1) * (GetImageWidth(
                        gpPicEditPen->minX,
                        gpPicEditPen->maxX)) + (U16) ((((sx1 + xCount - dx1) -
                                                                     gpPicEditPen->minX) * gPEBitsPerPixel) >> 3);
            PIC_EDIT_READ_PIXEL(sIndex, ((sx1 + xCount - dx1) - gpPicEditPen->minX), data, srcBuffer, gPEBitsPerPixel);
            PIC_EDIT_WRITE_PIXEL(dIndex, (xCount - gpPicEditPen->minX), data, destBuffer, gPEBitsPerPixel);
        }
}


/*****************************************************************************
 * FUNCTION
 *  DrawZoomImage
 * DESCRIPTION
 *  Draws Zoomed  Image using the inputs
 * PARAMETERS
 *  inBuffer            [?]         
 *  nImage_X            [IN]        
 *  nImage_Y            [IN]        
 *  nZoom_Factor        [IN]        
 *  nScr_X              [IN]        
 *  nScr_Y              [IN]        
 *  nScr_Height         [IN]        
 *  nScr_Width          [IN]        
 *  bute(?)             [IN]        *,U32,U32,U8,U32,U32,U32,U32
 * RETURNS
 *  void
 *****************************************************************************/
void DrawZoomImage(
        U8 *inBuffer,
        U32 nImage_X,
        U32 nImage_Y,
        U8 nZoom_Factor,
        U32 nScr_X,
        U32 nScr_Y,
        U32 nScr_Height,
        U32 nScr_Width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PE_File_Header fileHeader;
    PE_Info_Header infoHeader;

    U8 *fDataBuff = ParseImageBuffer(inBuffer, &fileHeader, &infoHeader);
    U16 nBits_Per_Pixel = infoHeader.bits_per_pixel;
    U32 iCount = 0, jCount = 0, nRow = nScr_Y, nCol = nScr_X;
    U8 xLen = (U8) GetImageWidth(0, (U16) infoHeader.width);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(nScr_X, nScr_Y, nScr_X + nScr_Width, nScr_Y + nScr_Height);
    for (jCount = nImage_Y; jCount < (nImage_Y + nScr_Height / nZoom_Factor); jCount++) /* For Image Row */
    {
        nCol = nScr_X;
        for (iCount = nImage_X; iCount < (nImage_X + nScr_Width / nZoom_Factor); iCount++)      /* For Image Colomn */
        {
            U32 nIndex = ((infoHeader.height - jCount - 1) * xLen + (U16) ((iCount * nBits_Per_Pixel) >> 3));
            S32 lCount = 0, mCount = 0;
            U32 nData = 0;

            PIC_EDIT_READ_PIXEL(nIndex, iCount, nData, fDataBuff, (U8) nBits_Per_Pixel);
            for (lCount = 0; lCount < nZoom_Factor; lCount++)
            {
                for (mCount = 0; mCount < nZoom_Factor; mCount++)
                {
                    gui_putpixel(nCol + lCount, nRow + mCount, GetPEColor(gPEColorRGB[nData]));
                }
            }
            nCol += nZoom_Factor;
        }
        nRow += nZoom_Factor;
    }
}


/*****************************************************************************
 * FUNCTION
 *  PutPixtelInBuff
 * DESCRIPTION
 *  sets color data into the box passed
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 *  pBuff       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void PutPixtelInBuff(U16 x1, U16 y1, U16 x2, U16 y2, U8 *pBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 xCount, yCount, nIndex;
    U8 xLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x1 > x2)
    {
        xCount = x1;
        x1 = x2;
        x2 = xCount;
    }

    if (y1 > y2)
    {
        yCount = y1;
        y1 = y2;
        y2 = yCount;
    }

    xLen = (U8) GetImageWidth(gpPicEditPen->minX, gpPicEditPen->maxX);
    for (xCount = x1; xCount < x2; xCount++)
        for (yCount = y1; yCount < y2; yCount++)
        {
            nIndex =
                (gpPicEditPen->maxY - yCount - 1) * xLen +
                (U16) (((xCount - gpPicEditPen->minX) * gPEBitsPerPixel) >> 3);
            if (xCount >= gpPicEditPen->minX && xCount < gpPicEditPen->maxX && yCount >= gpPicEditPen->minY &&
                yCount < gpPicEditPen->maxY)
            {
                PIC_EDIT_WRITE_PIXEL(
                    nIndex,
                    (xCount - gpPicEditPen->minX),
                    gpPicEditPen->penColorIndex,
                    pBuff,
                    gPEBitsPerPixel);
                SET_PE_IMAGE_EDIT(gPEAttrib);
            }
        }
}


/*****************************************************************************
 * FUNCTION
 *  InitRedoUndoBuffers
 * DESCRIPTION
 *  Initializes the backup buffers pointers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitRedoUndoBuffers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 051605 Calvin added to make sure buffer is big enough */
#if 0
#if defined (__USE_MAIN_MENU_MATRIX_BUFFER) && !defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
#endif
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Calvin end */
    gpPicEditBackupPen = &gPicEditBackupPen;
    gpPicEditPen = &gPicEditPen;
    gpPEFileBuff = &gPEImageData[MAX_IMAGE_HEADER_LENGTH];
    gpPEBackupFileBuff = &gPEBackupImageData[MAX_IMAGE_HEADER_LENGTH];
#if defined (__MMI_MAINLCD_240X320__)
    gpPicEditFillBackupColorIndex = &gPicEditFillBackupColorIndex;      /* 010306 image editor Calvin */
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  SavePEContext
 * DESCRIPTION
 *  Saves the data into backup buffers required for undo/redo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL gPEImageResized;
void SavePEContext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        (gpPEBackupFileBuff - MAX_IMAGE_HEADER_LENGTH),
        (gpPEFileBuff - MAX_IMAGE_HEADER_LENGTH),
        PIC_EDIT_FILE_BUFF + MAX_IMAGE_HEADER_LENGTH);
    memcpy(gpPicEditBackupPen, gpPicEditPen, sizeof(PictureEditorPen));
#if defined (__MMI_MAINLCD_240X320__)
    *gpPicEditFillBackupColorIndex = *gpPicEditFillColorIndex;  /* 010306 image editor Calvin */
#endif 

    /* when resizing, width and height are already backuped */
    if (gPEImageResized == MMI_FALSE)
    {
        gPEImageWidth_bak = gPEImageWidth;
        gPEImageHeight_bak = gPEImageHeight;
    }
    else
    {
        gPEImageResized = MMI_FALSE;
    }

    UNSET_PE_IMAGE_EDIT(gPEAttrib);
}


/*****************************************************************************
 * FUNCTION
 *  ExchangePEContext
 * DESCRIPTION
 *  Exchanges the buffers to undo/redo the changes in image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExchangePEContext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pTemp = gpPEFileBuff;
    PictureEditorPen *pPicEditBuffTemp = gpPicEditBackupPen;

#if defined (__MMI_MAINLCD_240X320__)
    U8 *pPicEditFillTempColorIndex = gpPicEditFillBackupColorIndex;     /* 010306 image editor Calvin */
#endif 
    S16 ImageWidth = gPEImageWidth, ImageHeight = gPEImageHeight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpPEFileBuff = gpPEBackupFileBuff;
    gpPEBackupFileBuff = pTemp;
    gpPicEditBackupPen = gpPicEditPen;
    gpPicEditPen = pPicEditBuffTemp;
#if defined (__MMI_MAINLCD_240X320__)
    gpPicEditFillBackupColorIndex = gpPicEditFillColorIndex;    /* 010306 image editor Calvin */
    gpPicEditFillColorIndex = pPicEditFillTempColorIndex;
#endif /* defined (__MMI_MAINLCD_240X320__) */ 

    gPEImageWidth = gPEImageWidth_bak;
    gPEImageHeight = gPEImageHeight_bak;
    gPEImageWidth_bak = ImageWidth;
    gPEImageHeight_bak = ImageHeight;

    /* update width */
    gpPEFileBuff[18] = (U8) gPEImageWidth;
    gpPEFileBuff[22] = (U8) gPEImageHeight;

    TOGGLE_PE_UNDO_IMAGE(gPEAttrib);
}


/*****************************************************************************
 * FUNCTION
 *  SaveDataBuffer
 * DESCRIPTION
 *  Saves image data to backup data buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveDataBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(gpPEBackupDataBuff, &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE], PIC_EDIT_FILE_MAX_DATA_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditEmptyImageDataBuff
 * DESCRIPTION
 *  Sets the image data buffer with the empty image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditEmptyImageDataBuff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PE_File_Header fileHeaderstruct;
    PE_Info_Header bitInfoHeader;
    U16 nWidth = GetImageWidth(gpPicEditPen->minX, gpPicEditPen->maxX), nHeight =
        (gpPicEditPen->maxY - gpPicEditPen->minY);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) & gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH], 0xFF, MAX_IMAGE_HEADER_LENGTH + PIC_EDIT_FILE_BUFF);

    fileHeaderstruct.file_type1 = 0x42;
    fileHeaderstruct.file_type2 = 0x4d;
    fileHeaderstruct.file_size = (U32) (PIC_EDIT_FILE_HEADER_SIZE + nWidth * nHeight);
    fileHeaderstruct.reserved1 = 0;
    fileHeaderstruct.reserved2 = 0;
    fileHeaderstruct.bitmap_offset = PIC_EDIT_FILE_HEADER_SIZE; /* 14+40+64 */

    bitInfoHeader.header_size = 40;
    bitInfoHeader.width = gpPicEditPen->maxX - gpPicEditPen->minX;
    bitInfoHeader.height = nHeight;
    bitInfoHeader.bits_per_pixel = gPEBitsPerPixel;
    bitInfoHeader.compression = 0;
    bitInfoHeader.bitmap_size = nWidth * nHeight;
    bitInfoHeader.device_width = bitInfoHeader.width;
    bitInfoHeader.device_height = bitInfoHeader.height;
    bitInfoHeader.number_of_colors = MAX_TYPE_PEN_COLOR;
    bitInfoHeader.number_of_important_colors = bitInfoHeader.number_of_colors;
    bitInfoHeader.number_of_planes = 1;

    gPEImageWidth = (U16) bitInfoHeader.width;
    gPEImageHeight = (U16) bitInfoHeader.height;

    gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH] = IMAGE_TYPE_BMP;
    memcpy(
        (S8*) & gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH + 2],
        &fileHeaderstruct.file_size,
        sizeof(fileHeaderstruct.file_size));

    gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH + 1] = 0xFF;

    SetImageBuffer((S8*) gpPEFileBuff, &fileHeaderstruct, &bitInfoHeader);
    /* memset(&gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE],((gpPicEditPen->penBackgrdColorIndex)|(gpPicEditPen->penBackgrdColorIndex<<4)),PIC_EDIT_FILE_MAX_DATA_SIZE); */
    memset(
        &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE],
        ((gpPicEditPen->penBackgrdColorIndex) | (gpPicEditPen->penBackgrdColorIndex << 4)),
        fileHeaderstruct.file_size);
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditImageDataBuff
 * DESCRIPTION
 *  Sets the image data buffer with the image passed
 *  
 *  Returns False if not able to open the file passed
 * PARAMETERS
 *  fileName        [?]     
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
BOOL SetPicEditImageDataBuff(U8 *fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileNameBuf[100 * ENCODING_LENGTH];  /* padding for filepath */
    S8 imagePath[100];
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(imagePath, 0, sizeof(imagePath));
    sprintf(imagePath, "%c:\\", MMI_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) fileNameBuf, (S8*) imagePath);
    mmi_ucs2cat((S8*) fileNameBuf, (S8*) FMGR_DEFAULT_FOLDER_IMAGES);
    mmi_ucs2cat((S8*) fileNameBuf, (S8*) fileName);

    fileHandle = FS_Open((kal_wchar*)fileNameBuf, FS_READ_ONLY);

    if (fileHandle < 0)
    {
        U32 wByte = 0;
        PE_File_Header fileHeaderstruct;
        PE_Info_Header bitInfoHeader;

        InitRedoUndoBuffers();
        memset(gPEImageData, 0xFF, MAX_IMAGE_HEADER_LENGTH + PIC_EDIT_FILE_BUFF);
        gPEImageData[0] = IMAGE_TYPE_BMP;
        FS_Read(fileHandle, gpPEFileBuff, PIC_EDIT_FILE_BUFF, &wByte);
        FS_Close(fileHandle);
        if (ParseImageBuffer((U8*) gpPEFileBuff, &fileHeaderstruct, &bitInfoHeader) == NULL)
        {
            return FALSE;
        }
        memcpy((S8*) gPEImageData + 2, &fileHeaderstruct.file_size, sizeof(fileHeaderstruct.file_size));
        gPEImageData[1] = 0xFF;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ResizePicEditImageDataBuff
 * DESCRIPTION
 *  Resizes the image and sets the data buffer with new params
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResizePicEditImageDataBuff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PE_File_Header fileHeaderstruct;
    PE_Info_Header bitInfoHeader;

    U16 nWidth, nHeight;
    U16 dxCount, dyCount, sxCount, syCount, sIndex, dIndex;
    U16 sMinX, sMaxX, sMinY, sMaxY;
    U16 sxLen, dxLen = 0;

    U8 *fDataBuff = &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE];
    U8 *fBackUpDataBuff = (U8*) ParseImageBuffer((U8*) gpPEBackupFileBuff, &fileHeaderstruct, &bitInfoHeader);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nWidth = GetImageWidth(gpPicEditPen->minX, gpPicEditPen->maxX);
    nHeight = gpPicEditPen->maxY - gpPicEditPen->minY;

    memset(
        &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE],
        ((gpPicEditPen->penBackgrdColorIndex) | (gpPicEditPen->penBackgrdColorIndex << 4)),
        (nWidth * nHeight) /* PIC_EDIT_FILE_MAX_DATA_SIZE */ );

    dxLen = nWidth;
    sxLen = GetImageWidth(gpPicEditBackupPen->minX, gpPicEditBackupPen->maxX);

    if (gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE)
    {
        sMinX = gPicEditMark.minX;
        sMaxX = gPicEditMark.maxX;
        sMinY = gPicEditMark.minY;
        sMaxY = gPicEditMark.maxY;
    }
    else
    {
        sMinX = gpPicEditBackupPen->minX;
        sMaxX = gpPicEditBackupPen->maxX;
        sMinY = gpPicEditBackupPen->minY;
        sMaxY = gpPicEditBackupPen->maxY;
    }

    for (dxCount = 0, sxCount = sMinX; (dxCount < (gpPicEditPen->maxX - gpPicEditPen->minX)) && (sxCount < sMaxX);
         dxCount++, sxCount++)
        for (dyCount = 0, syCount = sMinY; (dyCount < (gpPicEditPen->maxY - gpPicEditPen->minY)) && (syCount < sMaxY);
             dyCount++, syCount++)
        {
            U32 nData = 0;

            dIndex =
                (gpPicEditPen->maxY - gpPicEditPen->minY - dyCount - 1) * dxLen +
                (U16) ((dxCount * gPEBitsPerPixel) >> 3);
            sIndex =
                (gpPicEditBackupPen->maxY - syCount - 1) * sxLen +
                (U16) (((sxCount - gpPicEditBackupPen->minX) * gPEBitsPerPixel) >> 3);
            PIC_EDIT_READ_PIXEL(sIndex, (sxCount - gpPicEditBackupPen->minX), nData, fBackUpDataBuff, gPEBitsPerPixel);
            PIC_EDIT_WRITE_PIXEL(dIndex, dxCount, nData, fDataBuff, gPEBitsPerPixel);
        }

    fileHeaderstruct.file_size = (U32) (PIC_EDIT_FILE_HEADER_SIZE + (nWidth * nHeight));

    bitInfoHeader.width = gpPicEditPen->maxX - gpPicEditPen->minX;
    bitInfoHeader.height = nHeight;
    bitInfoHeader.bits_per_pixel = gPEBitsPerPixel;
    bitInfoHeader.compression = 0;
    bitInfoHeader.bitmap_size = nWidth * nHeight;
    bitInfoHeader.device_width = bitInfoHeader.width;
    bitInfoHeader.device_height = bitInfoHeader.height;
    bitInfoHeader.number_of_colors = MAX_TYPE_PEN_COLOR;
    bitInfoHeader.number_of_important_colors = bitInfoHeader.number_of_colors;
    bitInfoHeader.number_of_planes = 1;

    gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH] = IMAGE_TYPE_BMP;
    memcpy(
        (S8*) & gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH + 2],
        &fileHeaderstruct.file_size,
        sizeof(fileHeaderstruct.file_size));

    gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH + 1] = 0xFF;
    SetImageBuffer((S8*) gpPEFileBuff, &fileHeaderstruct, &bitInfoHeader);
    SetPicEditPenAtCenter(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  GetPaletteInfo
 * DESCRIPTION
 *  Fills the paletteinfo in the structure passed
 * PARAMETERS
 *  info_palette        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetPaletteInfo(U8 *info_palette)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (nCount = 0; nCount < MAX_TYPE_PEN_COLOR; nCount++)
    {
        info_palette[nCount * 4] = (U8) ((0x0000FF00 & gPEColorRGB[nCount]) >> 8);
        info_palette[nCount * 4 + 1] = (U8) ((0x00FF0000 & gPEColorRGB[nCount]) >> 16);
        info_palette[nCount * 4 + 2] = (U8) ((0xFF000000 & gPEColorRGB[nCount]) >> 24);
        info_palette[nCount * 4 + 3] = (U8) (0x000000FF & gPEColorRGB[nCount]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentImageParams
 * DESCRIPTION
 *  Sets the global variable with the current image parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentImageParams(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PE_File_Header fileHeaderstruct;
    PE_Info_Header bitInfoHeader;
    U8 infoPalette[MAX_TYPE_PEN_COLOR * 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ParseImageBuffer((U8*) gpPEFileBuff, &fileHeaderstruct, &bitInfoHeader);
    memcpy((S8*) & infoPalette, (U8*) & gpPEFileBuff[54], MAX_TYPE_PEN_COLOR * 4);

    gPEColorRGB[PE_COLOR_CUSTOM_1] &= 0x000000FF;
    gPEColorRGB[PE_COLOR_CUSTOM_1] |=
        ((((U32) infoPalette[PE_COLOR_CUSTOM_1 * 4]) << 8) |
         (((U32) infoPalette[PE_COLOR_CUSTOM_1 * 4 + 1]) << 16) | (((U32) infoPalette[PE_COLOR_CUSTOM_1 * 4 + 2])
                                                                      << 24));

    gPEImageWidth = (U16) bitInfoHeader.width;
    gPEImageHeight = (U16) bitInfoHeader.height;
}


/*****************************************************************************
 * FUNCTION
 *  GetImageWidth
 * DESCRIPTION
 *  Get the image width adding the padding if required
 * PARAMETERS
 *  xMin        [IN]        
 *  xMax        [IN]        
 * RETURNS
 *  Width of the image with padding if required
 *****************************************************************************/
U16 GetImageWidth(U16 xMin, U16 xMax)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 xLen, padBuff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    xLen = (xMax - xMin) * gPEBitsPerPixel;
    padBuff = xLen >> 3;
    if (xLen % 8)
    {
        xLen = padBuff + 1;
    }
    else
    {
        xLen = padBuff;
    }

    padBuff = gPEBitsPerPixel - (xLen % 4);
    if (padBuff == 4)
    {
        padBuff = 0;
    }

    xLen += padBuff;

    return xLen;
}


/*****************************************************************************
 * FUNCTION
 *  GetPEColor
 * DESCRIPTION
 *  To get value of RGB in color structure
 * PARAMETERS
 *  selColor        [IN]        
 *  color(?)        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
color GetPEColor(U32 selColor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color selPicEditColor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selPicEditColor.r = (0xFF000000 & selColor) >> 24;
    selPicEditColor.g = (0x00FF0000 & selColor) >> 16;
    selPicEditColor.b = (0x0000FF00 & selColor) >> 8;
    selPicEditColor.alpha = (0x000000FF & selColor);

    return gui_color(selPicEditColor.r, selPicEditColor.g, selPicEditColor.b);
}


/*****************************************************************************
 * FUNCTION
 *  SyncPicEditFileSystem
 * DESCRIPTION
 *  To retrive empty solts in Image Editor
 * PARAMETERS
 *  DirPath     [?]         
 *  dynInfo     [?]         
 *  U8(?)       [OUT]       
 * RETURNS
 *  No of free Image slot(?)
 *****************************************************************************/
void SyncPicEditFileSystem(S8 *DirPath, DYNAMICINFO *dynInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 SearchString[MAX_IMAGE_NAME_PATH_WIDTH + MAX_SEARCH_STR_LENGTH];
    S8 tempString[MAX_IMAGE_NAME_PATH_WIDTH + MAX_SEARCH_STR_LENGTH];
    S8 FileName[MAX_IMAGE_NAME_WIDTH];
    FS_DOSDirEntry file_info;
    FS_HANDLE fileHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(FileName, 0, MAX_IMAGE_NAME_WIDTH);
    memset(SearchString, 0, MAX_IMAGE_NAME_PATH_WIDTH + MAX_SEARCH_STR_LENGTH);
    memset(tempString, 0, MAX_IMAGE_NAME_PATH_WIDTH + MAX_SEARCH_STR_LENGTH);

    gui_strcpy((UI_string_type) SearchString, (UI_string_type) DirPath);
    gui_strcat((UI_string_type) SearchString, L"*.*");  /* AST_SEARCH_STR ); */
    fileHandle = FS_FindFirst((PU16) SearchString, 0, 0, &file_info, (PU16) FileName, MAX_IMAGE_NAME_WIDTH);
    if (fileHandle < 0)
    {
        return;
    }
    else
    {
        U8 nCount = 0;
        BOOL bFound;

        do
        {
            bFound = FALSE;
            for (nCount = 0; nCount < MAXIMUM_PICTURE_EDITOR_IMAGES; nCount++)
            {
                if (((PS8) dynInfo->DYNINFOUNION.ImageInfo[nCount].ImagesId) &&
                    (mmi_ucs2cmp((PS8) dynInfo->DYNINFOUNION.ImageInfo[nCount].ImageName, FileName) == 0))
                {
                    bFound = TRUE;
                    break;
                }
            }
            /* MTK Leo start, no need to delete non-PE files */
        #if (0)
/* under construction !*/
/* under construction !*/
					#ifdef __ASCII
/* under construction !*/
/* under construction !*/
					#else
/* under construction !*/
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* (0) */ 
            /* MTK Leo end */
        } while (!FS_FindNext(fileHandle, &file_info, (U16*) FileName, MAX_IMAGE_NAME_WIDTH));
    }
    FS_FindClose(fileHandle);
}

/* [~  PMT   MANISH   20050304 */
#ifdef __MMI_TOUCH_SCREEN__
S32 pre_x1 = -1, pre_y1 = -1;


/*****************************************************************************
 * FUNCTION
 *  mmi_pe_draw_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pe_draw_line(S16 x1, S16 y1, S16 x2, S16 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_diff = abs(x2 - x1);
    S16 y_diff = abs(y2 - y1);
    S16 x_incr, y_incr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pe_in_draw_line = MMI_TRUE;
    if (x1 > x2)
    {
        x_incr = -1;
    }
    else
    {
        x_incr = 1;
    }
    if (y1 > y2)
    {
        y_incr = -1;
    }
    else
    {
        y_incr = 1;
    }

    if (x_diff >= y_diff)
    {
        S16 pr_diff = y_diff << 1;
        S16 pru_diff = pr_diff - (x_diff << 1);
        S16 p = pr_diff - x_diff;

        for (; x_diff >= 0; x_diff--)
        {
            DrawPECursorAt(x1, y1);
            if (p > 0)
            {
                x1 += x_incr;
                y1 += y_incr;
                p += pru_diff;
            }
            else
            {
                x1 += x_incr;
                p += pr_diff;
            }
        }
    }
    else
    {
        S16 pr_diff = x_diff << 1;
        S16 pru_diff = pr_diff - (y_diff << 1);
        S16 p = pr_diff - y_diff;

        for (; y_diff >= 0; y_diff--)
        {
            DrawPECursorAt(x1, y1);
            if (p > 0)
            {
                x1 += x_incr;
                y1 += y_incr;
                p += pru_diff;
            }
            else
            {
                y1 += y_incr;
                p += pr_diff;
            }
        }
    }

    ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    pe_in_draw_line = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_register_image_editor_pen_handlers
 * DESCRIPTION
 *  To Register Pen Event Handlers for Image Editor
 *  
 *  Repeat and Long Tap Events are not handled for LSK,RSK and Image Editor,therefore
 *  registering Dummy Handlers for these Events.
 *  
 *  NOTICE !! IN CASE REPEAT AND LONG TAP HANDLING IS PROVIDED FOR LSK,RSK ,NEED
 * TO MODIFY THIS FUNCTION TO HANDLE THAT ACCORDINGLY
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_register_image_editor_pen_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* These pen event handlers will be used for handling pen events in Image Editor */
    mmi_pen_register_up_handler(mmi_image_editor_pen_up_handler);
    mmi_pen_register_down_handler(mmi_image_editor_pen_down_handler);
    mmi_pen_register_move_handler(mmi_image_editor_pen_move_handler);
    mmi_pen_register_abort_handler(mmi_image_editor_pen_abort_handler);
    mmi_pen_register_repeat_handler(mmi_pen_dummy_hdlr);

    /* 051605 Calvin added */
#if 0   /* should be defined (__MMI_MAINLCD_240X320__) */
/* under construction !*/
#else /* 0 */ 
    mmi_pen_register_long_tap_handler(mmi_pen_dummy_hdlr);
#endif /* 0 */ 
    /* Calvin end */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_image_editor_pen_up_handler
 * DESCRIPTION
 *  To Handle UP Pen Event for Image Editor
 *  
 *  Handle Pen Up Events on Image Editor Screen
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_image_editor_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_pen_control == LSK_IE)
    {
        translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_UP, point.x, point.y, &button_event);

        if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
        {
            execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        }
    }
    else if (image_pen_control == RSK_IE)
    {
        translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_UP, point.x, point.y, &button_event);

        if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
        {
            redraw_right_softkey();
            execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
        }
    }
    /* [~PMT  MANISH   20050329 */
    else if (image_pen_control == IMAGE_EDITOR_AREA)
    {
        pre_x1 = -1;
        pre_y1 = -1;
        if (IS_PE_PEN_DOWN(gPEAttrib))
        {
            if (gpPicEditPen->penContextSaved)
            {
                gpPicEditPen->penContextSaved = MMI_FALSE;
            }
        }
    }
    /* ~] */
    image_pen_control = NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_image_editor_pen_abort_handler
 * DESCRIPTION
 *  To Handle ABORT Pen Event for Image Editor
 *  
 *  Handle Pen Abort Events on Image Editor Screen
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_image_editor_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_pen_control == LSK_IE)
    {
        translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_ABORT, point.x, point.y, &button_event);
    }
    else if (image_pen_control == RSK_IE)
    {
        translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_ABORT, point.x, point.y, &button_event);
    }

    image_pen_control = NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_image_editor_pen_down_handler
 * DESCRIPTION
 *  To Handle DOWN Pen Event for Image Editor
 *  
 *  Handle Pen Down Events on Image Editor Screen
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_image_editor_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* 051605 Calvin modified */
    /* pBOOL ret; */
    BOOL ret;

    /* Calvin end */
    mmi_image_editor_pen_enum image_editor_event;
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_pen_control = NONE;

    ret = translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_DOWN, point.x, point.y, &button_event);

    if (ret)
    {
        image_pen_control = LSK_IE;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
        }
        return;
    }

    ret = translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_DOWN, point.x, point.y, &button_event);

    if (ret)
    {
        image_pen_control = RSK_IE;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
        }
        return;
    }

    ret = mmi_general_image_editor_pen_handler(MMI_PEN_EVENT_DOWN, point.x, point.y, &image_editor_event);
    if (ret)
    {
        if (image_editor_event == GUI_IMAGE_EDITOR_PEN_TITLE_EVENT)
        {
            HandleImageEditorTitleEvent(point.x, point.y);
        }
        else
        {
            image_pen_control = IMAGE_EDITOR_AREA;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_image_editor_pen_move_handler
 * DESCRIPTION
 *  To Handle MOVE Pen Event for Image Editor
 *  
 *  Handle Pen Move Events on Image Editor Screen
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_image_editor_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_image_editor_pen_enum image_editor_event;
    gui_button_pen_enum button_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_pen_control == LSK_IE)
    {
        translate_softkey_pen_event(MMI_LEFT_SOFTKEY, MMI_PEN_EVENT_MOVE, point.x, point.y, &button_event);
    }
    else if (image_pen_control == RSK_IE)
    {
        translate_softkey_pen_event(MMI_RIGHT_SOFTKEY, MMI_PEN_EVENT_MOVE, point.x, point.y, &button_event);
    }
    else if (image_pen_control == IMAGE_EDITOR_AREA)
    {
        mmi_general_image_editor_pen_handler(MMI_PEN_EVENT_MOVE, point.x, point.y, &image_editor_event);
    }
}

/* 051605 Calvin added */
#if 0   /* should be defined(__MMI_MAINLCD_240X320__) */
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
		#if defined (__MMI_MAINLCD_240X320__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
/* Calvin end */


/*****************************************************************************
 * FUNCTION
 *  mmi_general_image_editor_pen_handler
 * DESCRIPTION
 *  To Handle All Pen Events on Image Editor Screen
 *  
 *  Handle All pen Events on Image Editor Screen excluding LSK,RSK
 * PARAMETERS
 *  pen_event               [IN]        
 *  x                       [IN]        
 *  y                       [IN]        
 *  image_editor_event      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_general_image_editor_pen_handler(
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        mmi_image_editor_pen_enum *image_editor_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL ret, i, j;
    U16 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = MMI_FALSE;

    if (gpPicEditPen == NULL)
    {
        return ret;
    }

    if (IS_PE_VIEW_IMAGE(gPEAttrib))
    {
        /* Don't Handle Pen Events in case user is viewing Image */
        return ret;
    }
    if (IS_PE_ZOOM_IMAGE(gPEAttrib))    /* Set bounds according to image mode */
    {
        if (((gPicEditZoomWindow.maxX - gPicEditZoomWindow.minX) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
        {
            x1 = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
            x2 = x1 + PE_SCR_SIZE_MAX;
        }
        else
        {
            x1 = SET_WINDOW_MINX((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
            x2 = x1 + ((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
        }
        if (((gPicEditZoomWindow.maxY - gPicEditZoomWindow.minY) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
        {
            y1 = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);
            y2 = y1 + PE_SCR_SIZE_MAX;
        }
        else
        {
            y1 = SET_WINDOW_MINY((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
            y2 = y1 + ((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
        }
    }
    else    /* Image is of original Size */
    {
        x1 = gpPicEditPen->minX;
        y1 = gpPicEditPen->minY;
        x2 = gpPicEditPen->maxX;
        y2 = gpPicEditPen->maxY;
    }

    *image_editor_event = GUI_IMAGE_EDITOR_PEN_NONE;

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            /* 051605 Calvin modified */
            // if(PEN_CHECK_BOUND(x,y,0,0,UI_device_height-1,PIC_EDITOR_TITLE_HEIGHT-1))    /*Handle Down event on Title of Image Editor*/
            if (PEN_CHECK_BOUND(x, y, 0, PIC_EDITOR_TITLE_Y, UI_device_width - 1, PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT - 1))    /* Handle Down event on Title of Image Editor */
                /* Calvin end */
            {
                /* Event inside title of Image Editor */
                *image_editor_event = GUI_IMAGE_EDITOR_PEN_TITLE_EVENT;
                ret = MMI_TRUE;
            }
            else if (PEN_CHECK_BOUND(x, y, x1, y1, (x2 - x1), (y2 - y1)))       /* Event is inside the Image Area */
            {
                pre_x1 = x;
                pre_y1 = y;
                DrawPECursorAt(x, y);
                ret = MMI_TRUE;
            }
            break;
        case MMI_PEN_EVENT_UP:
            /* Do Nothing */
            break;
        case MMI_PEN_EVENT_MOVE:
            if (PEN_CHECK_BOUND(x, y, x1, y1, (x2 - x1 + 1), (y2 - y1 + 1)))    /* Event is inside the Image */
            {
                if (pre_x1 != -1 && pre_y1 != -1)
                {
                    mmi_pe_draw_line((S16) pre_x1, (S16) pre_y1, (S16) x, (S16) y);
                }
                else
                {
                    DrawPECursorAt(x, y);
                }
                pre_x1 = x;
                pre_y1 = y;
                ret = MMI_TRUE;
            }
            else
            {
                if (IS_PE_ZOOM_IMAGE(gPEAttrib))    /* In case zoom we can move to other part of picture which is not displayed currently */
                {
                    /* Make sure that pen is not at boundary positon */
                    i = ((gpPicEditPen->penX >= gpPicEditPen->minX) &&
                         ((gpPicEditPen->penX + gpPicEditPen->penPixel) <= gpPicEditPen->maxX));
                    j = ((gpPicEditPen->penY >= gpPicEditPen->minY) &&
                         ((gpPicEditPen->penY + gpPicEditPen->penPixel) <= gpPicEditPen->maxY));
                    if (i || j)
                    {
                        DrawPECursorAt(x, y);
                        ret = MMI_TRUE;
                    }
                }
            }
            break;
        case MMI_PEN_EVENT_LONG_TAP:
            /* 051605 Calvin modified */
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            /* Calvin end */
            break;

        case MMI_PEN_EVENT_REPEAT:
            /* Do nothing */
            break;

        case MMI_PEN_EVENT_ABORT:
            /* Do nothing */
            break;
        default:
            MMI_ASSERT(0);
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 
/* ~] */
#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 

