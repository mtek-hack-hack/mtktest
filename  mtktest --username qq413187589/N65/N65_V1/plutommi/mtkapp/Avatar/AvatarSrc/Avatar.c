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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Avatar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Avatar Applications v0.1
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_AVATAR__)
/****************************************************************************
* Include M3D header files 
*****************************************************************************/
#if defined(M3D_MMI_SUPPORT) 
#include "m3d_object3d.h"
#include "m3d_parser.h"
#include "m3d_graphics3d.h"
#include "m3d_class.h"
#endif /* defined(M3D_MMI_SUPPORT)*/ 
#include "math.h"


#define __NEWSIMULATOR

#include "stdC.h"
#include "L4Dr1.h"
#include "GlobalDefs.h"

#include "lcd_if.h"     /* LCD layer enable flag */
#include "lcd_sw_rnd.h" /* for LCD size */



#include "NVRAMProt.h"  /* NVRAM access fucntions */

#ifdef __MTK_TARGET__
#include "MMI_trc.h"
#endif /* __MTK_TARGET__ */ 

/* framework related headers */
#include "CustMenuRes.h"
#include "GlobalConstants.h"    /* KEY ID define */
#include "GlobalDefs.h" /* Golbal Image and String ID. */
#include "gui.h"        /* Gui functions */
#include "wgui_categories.h"
#include "HistoryGprot.h"       /* Screen history */
#include "Unicodexdcl.h"        /* Unicode transform functions */
#include "EventsGprot.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "wgui.h"       /* for GetDateTime() */
#include "CommonScreens.h"      /* DisplayPopup() */
#include "DebugInitDef.h"       /* MMI_ASSERT */
#include "ScrMemMgrGprot.h"     /* screen memeory manager */
#include "wgui_categories_inputs.h"
#include "Fat_fs.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"   /* file path */
#include "FileMgr.h"
#include "DRM_gprot.h"
#include "FileMgrStruct.h"
#include "KeyBrd.h"     /* keypad tone related interface */
#include "MMIDataType.h"
#include "Wgui_categories_fmgr.h"
#include "MainMenuDef.h"
/* gdi, mid headers */
#include "gdi_include.h"        /* graphic library */

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /* __MMI_TOUCH_SCREEN__ */


#include "AppMemMgrGprot.h"

#include "Avatar.h"
#include "AvatarGprot.h"
#include "AvatarResDef.h"


extern BOOL r2lMMIFlag;

#undef __NEWSIMULATOR
/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/

extern void gdi_image_m3d_avatar_get_all_var(void** c,void** world, void** head,void** hair,void** body);
extern void _m3d_Graphics3D_release_texobj(st_m3d_image2d* image);
extern void hide_status_icon_bar(U8 status_bar_ID);

/***************************************************************************** 
* Define
*****************************************************************************/
/****************************************************************************
* Setting command map                                                                
*****************************************************************************/
/***************************************************************************** 
* Enum
*****************************************************************************/
/***************************************************************************** 
* Local variable
*****************************************************************************/

static mmi_avatar_cntx_struct g_avatar_cntx;
/***************************************************************************** 
* Functions declaration
*****************************************************************************/
/***************************************************************************** 
* Local Functions Implementation
*****************************************************************************/
/*******************************************************************************
 * Global Definition
 *******************************************************************************/
/****************************************************************************
 * Global Data
 ****************************************************************************/
extern st_m3d_world *m3d_world;

#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
	avatar_osd_layout_struct g_avatar_osd_cntx =
	{
		/****** title ******/
		{TRUE,30, 23, 116, 24},		

        {TRUE,12, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* head */
        {TRUE,34, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* hair */
        {TRUE,78, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* eye */
        {TRUE,56, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* brow */
        {TRUE,100, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* lip */
        {TRUE,145, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* decoration */
        {TRUE,123, 0, 21, 34, AVATAR_ICON_STATUS_ENABLE},    /* body */

        {TRUE,143, 45, 28, 40, AVATAR_ICON_STATUS_DISABLE},    /* magnify */
        {TRUE,97, 45, 28, 40, AVATAR_ICON_STATUS_DISABLE},    /* minify */
        {TRUE,120, 103, 26, 28, AVATAR_ICON_STATUS_DISABLE},   /* color */
        {TRUE,120, 80, 28, 33, AVATAR_ICON_STATUS_DISABLE},   /* moveup */
        {TRUE,120, 126, 28, 33, AVATAR_ICON_STATUS_DISABLE},   /* movedown */
        {TRUE,143, 103, 29, 26, AVATAR_ICON_STATUS_DISABLE},   /* stretch */
        {TRUE,97, 103, 29, 26, AVATAR_ICON_STATUS_DISABLE},   /* shrink */
        {TRUE,0, 165, 10, 17, AVATAR_ICON_STATUS_DISABLE},    /* larrow */
        {TRUE,166, 165, 10, 17, AVATAR_ICON_STATUS_DISABLE},   /* rarrow */       
		{TRUE,25,23,19,17,AVATAR_ICON_STATUS_ENABLE},	    /* left arrow */
		{TRUE,134,23,19,17,AVATAR_ICON_STATUS_ENABLE},		/* right arrow */

#ifndef __MMI_TOUCH_SCREEN__
        {TRUE,148, 201, 10, 17, AVATAR_ICON_STATUS_DISABLE}, /* toogle */
#endif

	};
/***********************************
* Bottom icon customization
************************************/
#define MMI_AVATAR_BOTTOM_ICON_START_POSITION_X 17
#define MMI_AVATAR_BOTTOM_ICON_START_POSITION_Y 158
#define MMI_AVATAR_BOTTOM_ICON_SIZE 36
#define MMI_AVATAR_BOTTOM_LARGE_ICON_SIZE 44
#define MMI_AVATAR_BOTTOM_ICON_SIZE_OFFSET 4

#define MMI_AVATAR_ITOM_COUNT_PER_PAGE 4

/***********************************
* Feature icon count 
************************************/
#define MMI_AVATAR_COUNT_OF_ANIMATION 3
#define MMI_AVATAR_COUNT_OF_HEAD 3
#define MMI_AVATAR_COUNT_OF_HAIR 5
#define MMI_AVATAR_COUNT_OF_EYE 10
#define MMI_AVATAR_COUNT_OF_BROW 6
#define MMI_AVATAR_COUNT_OF_BODY 2
#define MMI_AVATAR_COUNT_OF_LIP 10
#define MMI_AVATAR_COUNT_OF_DECORATION 4
#define MMI_AVATAR_COLOR_COUNT_OF_FACE 5
#define MMI_AVATAR_COLOR_COUNT_OF_DRESS 6


/***********************************
* Camera position
************************************/
#define MMI_AVATAR_CAMERA_HEAD_OFFSET_Y (-110.712)
#define MMI_AVATAR_CAMERA_HEAD_OFFSET_Z (126.134)

#define MMI_AVATAR_CAMERA_BODY_OFFSET_Y (-260.712)
#define MMI_AVATAR_CAMERA_BODY_OFFSET_Z (81.134)

/***********************************
* Title offset 
************************************/

#define MMI_AVATAR_TITLE_OFFSET_X (27)
#define MMI_AVATAR_TITLE_OFFSET_Y (25)
#define MMI_AVATAR_TITLE_WIDTH (116)
#define MMI_AVATAR_TITLE_HEIGHT (24)

#ifndef __MMI_TOUCH_SCREEN__
#define REC_1_X1 (95)
#define REC_1_Y1 (45)
#define REC_1_X2 (167)
#define REC_1_Y2 (147)

#define REC_2_X1 (10)
#define REC_2_Y1 (154)
#define REC_2_X2 (165)
#define REC_2_Y2 (199)
#endif


#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
	avatar_osd_layout_struct g_avatar_osd_cntx =
	{
		/****** title ******/
		{TRUE,50, 23, 140, 24},		

        {TRUE,11, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* head */
        {TRUE,42, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* hair */
        {TRUE,106, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* eye */
        {TRUE,74, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* brow */
        {TRUE,138, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* lip */
        {TRUE,200, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* decoration */
        {TRUE,169, 0, 30, 49, AVATAR_ICON_STATUS_ENABLE},    /* body */

        {TRUE,202, 56, 28, 40, AVATAR_ICON_STATUS_DISABLE},    /* magnify */
        {TRUE,144, 56, 28, 40, AVATAR_ICON_STATUS_DISABLE},    /* minify */
        {TRUE,172, 160, 26, 28, AVATAR_ICON_STATUS_DISABLE},   /* color */
        {TRUE,172, 118, 28, 33, AVATAR_ICON_STATUS_DISABLE},   /* moveup */
        {TRUE,172, 195, 28, 33, AVATAR_ICON_STATUS_DISABLE},   /* movedown */
        {TRUE,202, 160, 29, 26, AVATAR_ICON_STATUS_DISABLE},   /* stretch */
        {TRUE,139, 160, 29, 26, AVATAR_ICON_STATUS_DISABLE},   /* shrink */
        {TRUE,13, 257, 10, 17, AVATAR_ICON_STATUS_DISABLE},    /* larrow */
        {TRUE,217, 257, 10, 17, AVATAR_ICON_STATUS_DISABLE},   /* rarrow */       
		{TRUE,25, 25,19,17,AVATAR_ICON_STATUS_ENABLE},	    /* left arrow */
		{TRUE,195,25,19,17,AVATAR_ICON_STATUS_ENABLE},		/* right arrow */

#ifndef __MMI_TOUCH_SCREEN__
        {TRUE,193, 298, 10, 17, AVATAR_ICON_STATUS_DISABLE}, /* toogle */
#endif

	};


/***********************************
* Bottom icon customization
************************************/
#define MMI_AVATAR_BOTTOM_ICON_START_POSITION_X 33
#define MMI_AVATAR_BOTTOM_ICON_START_POSITION_Y 245
#define MMI_AVATAR_BOTTOM_ICON_SIZE 44
#define MMI_AVATAR_BOTTOM_LARGE_ICON_SIZE 58
#define MMI_AVATAR_BOTTOM_ICON_SIZE_OFFSET 7

#define MMI_AVATAR_ITOM_COUNT_PER_PAGE 4

/***********************************
* Feature icon count 
************************************/
#define MMI_AVATAR_COUNT_OF_ANIMATION 3
#define MMI_AVATAR_COUNT_OF_HEAD 3
#define MMI_AVATAR_COUNT_OF_HAIR 5
#define MMI_AVATAR_COUNT_OF_EYE 10
#define MMI_AVATAR_COUNT_OF_BROW 6
#define MMI_AVATAR_COUNT_OF_BODY 2
#define MMI_AVATAR_COUNT_OF_LIP 10
#define MMI_AVATAR_COUNT_OF_DECORATION 4
#define MMI_AVATAR_COLOR_COUNT_OF_FACE 5
#define MMI_AVATAR_COLOR_COUNT_OF_DRESS 6


/***********************************
* Camera position
************************************/
#define MMI_AVATAR_CAMERA_HEAD_OFFSET_Y (-110.712)
#define MMI_AVATAR_CAMERA_HEAD_OFFSET_Z (126.134)

#define MMI_AVATAR_CAMERA_BODY_OFFSET_Y (-260.712)
#define MMI_AVATAR_CAMERA_BODY_OFFSET_Z (81.134)

/***********************************
* Title offset 
************************************/

#define MMI_AVATAR_TITLE_OFFSET_X (50)
#define MMI_AVATAR_TITLE_OFFSET_Y (23)
#define MMI_AVATAR_TITLE_WIDTH (140)
#define MMI_AVATAR_TITLE_HEIGHT (24)
#ifndef __MMI_TOUCH_SCREEN__
#define REC_1_X1 (136)
#define REC_1_Y1 (50)
#define REC_1_X2 (235)
#define REC_1_Y2 (230)

#define REC_2_X1 (11)
#define REC_2_Y1 (235)
#define REC_2_X2 (230)
#define REC_2_Y2 (297)
#endif


#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
	avatar_osd_layout_struct g_avatar_osd_cntx =
	{
        /****** title ******/
        {TRUE,50, 23, 140, 24},		

        {TRUE,0, 3, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* head */
        {TRUE,0, 33, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* hair */
        {TRUE,0, 93, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* eye */
        {TRUE,0, 63, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* brow */
        {TRUE,0, 123, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* lip */
        {TRUE,0, 183, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* decoration */
        {TRUE,0, 153, 49, 29, AVATAR_ICON_STATUS_ENABLE},    /* body */

        {TRUE,276, 3, 30, 34, AVATAR_ICON_STATUS_DISABLE},    /* magnify */
        {TRUE,213, 3, 30, 34, AVATAR_ICON_STATUS_DISABLE},    /* minify */
        {TRUE,245, 83, 26, 28, AVATAR_ICON_STATUS_DISABLE},   /* color */
        {TRUE,243, 46, 30, 34, AVATAR_ICON_STATUS_DISABLE},   /* moveup */
        {TRUE,243, 114, 30, 34, AVATAR_ICON_STATUS_DISABLE},   /* movedown */
        {TRUE,276, 80, 30, 34, AVATAR_ICON_STATUS_DISABLE},   /* stretch */
        {TRUE,212, 80, 30, 34, AVATAR_ICON_STATUS_DISABLE},   /* shrink */
        {TRUE,62, 175, 10, 17, AVATAR_ICON_STATUS_DISABLE},    /* larrow */
        {TRUE,307, 175, 10, 17, AVATAR_ICON_STATUS_DISABLE},   /* rarrow */       
        {TRUE,52, 9,19,17,AVATAR_ICON_STATUS_ENABLE},	    /* left arrow */
        {TRUE,249,9,19,17,AVATAR_ICON_STATUS_ENABLE},		/* right arrow */

#ifndef __MMI_TOUCH_SCREEN__
        {TRUE,193, 298, 10, 17, AVATAR_ICON_STATUS_DISABLE}, /* toogle */
#endif

	};


/***********************************
* Bottom icon customization
************************************/
#define MMI_AVATAR_BOTTOM_ICON_START_POSITION_X 80
#define MMI_AVATAR_BOTTOM_ICON_START_POSITION_Y 160
#define MMI_AVATAR_BOTTOM_ICON_SIZE 44
#define MMI_AVATAR_BOTTOM_LARGE_ICON_SIZE 58
#define MMI_AVATAR_BOTTOM_ICON_SIZE_OFFSET 7

#define MMI_AVATAR_ITOM_COUNT_PER_PAGE 5

/***********************************
* Feature icon count 
************************************/
#define MMI_AVATAR_COUNT_OF_ANIMATION 3
#define MMI_AVATAR_COUNT_OF_HEAD 3
#define MMI_AVATAR_COUNT_OF_HAIR 5
#define MMI_AVATAR_COUNT_OF_EYE 10
#define MMI_AVATAR_COUNT_OF_BROW 6
#define MMI_AVATAR_COUNT_OF_BODY 2
#define MMI_AVATAR_COUNT_OF_LIP 10
#define MMI_AVATAR_COUNT_OF_DECORATION 4
#define MMI_AVATAR_COLOR_COUNT_OF_FACE 5
#define MMI_AVATAR_COLOR_COUNT_OF_DRESS 6


/***********************************
* Camera position
************************************/
#define MMI_AVATAR_CAMERA_HEAD_OFFSET_Y (-110.712)
#define MMI_AVATAR_CAMERA_HEAD_OFFSET_Z (126.134)

#define MMI_AVATAR_CAMERA_BODY_OFFSET_Y (-260.712)
#define MMI_AVATAR_CAMERA_BODY_OFFSET_Z (81.134)

/***********************************
* Title offset 
************************************/

#define MMI_AVATAR_TITLE_OFFSET_X (73)
#define MMI_AVATAR_TITLE_OFFSET_Y (3)
#define MMI_AVATAR_TITLE_WIDTH (174)
#define MMI_AVATAR_TITLE_HEIGHT (28)
#ifndef __MMI_TOUCH_SCREEN__
#define REC_1_X1 (57)
#define REC_1_Y1 (150)
#define REC_1_X2 (318)
#define REC_1_Y2 (212)

#define REC_2_X1 (210)
#define REC_2_Y1 (1)
#define REC_2_X2 (306)
#define REC_2_Y2 (149)
#endif




#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
/* for cache image list */
mmi_avatar_cntx_struct *avatar_cntx_p = &g_avatar_cntx;
avatar_osd_layout_struct *avatar_osd_cntx_p = &g_avatar_osd_cntx;

fmgr_thumb_image_cache_struct *g_avatar_image_cache_list_buffer;
fmgr_thumb_image_handle_struct *g_avatar_image_handle_list_buffer;
fmgr_image_cache_struct *avatar_image_cache_p ;
fmgr_delay_decode_struct *avatar_delay_decoder_p;

extern S32 GUI_current_fixed_icontext_menuitem_x, GUI_current_fixed_icontext_menuitem_y;


/***************************************************************
*  M3D render engine related functions
****************************************************************/

/***************************************************************
*  Avatar list display related functions 
****************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_get_id_from_idx
 * DESCRIPTION
 *  return AvatarID by highlighted idx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_avatar_get_id_from_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, head_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    head_idx = avatar_cntx_p->meta_manager.head;

    for (i=0;i<idx;i++)
    {
        head_idx = avatar_cntx_p->meta_manager.meta_header[head_idx].next;
    }

    return (U32)head_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_get_avatar_name_by_idx
 * DESCRIPTION
 *  get avatar name from highlight idx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_get_avatar_name_by_idx(S32 idx, S8* avatarname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = mmi_avatar_get_id_from_idx(idx);    
    mmi_ucs2cpy((PS8) avatarname, (PS8) avatar_cntx_p->avatar_list[id].filename);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_get_filename_by_idx 
 * DESCRIPTION
 *  get file name from highlight idx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_get_filename_by_idx (S32 idx, S8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id;
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id = mmi_avatar_get_id_from_idx(idx);    
    sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.jpg",avatar_cntx_p->meta_manager.meta_header[id].serial_number);
    mmi_asc_to_ucs2((PS8) filename, (PS8) buf_filename);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_create_thumb_image_cache
 * DESCRIPTION
 *  create thumb image cache resource.
 * PARAMETERS
 *  image_size      [IN]        Menuitem height, this is used to caculate image resource.
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_avatar_create_thumb_image_cache(S32 image_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cache_size;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calcuate thumb image size */
    avatar_image_cache_p->image_size = image_size;
    cache_size = (avatar_image_cache_p->image_size * avatar_image_cache_p->image_size * GDI_LAYER.act_bit_per_pixel) >> 3;
    ASSERT(cache_size > 0);

    /* sub 1 for overhead usage */
    avatar_image_cache_p->image_cache_item_count = (U16) (mmi_frm_scrmem_get_available_size() / cache_size) - 1;

    if (avatar_image_cache_p->image_cache_item_count > AVATAR_THUMB_IMAGE_CACHE_MAX_COUNT)
    {
        avatar_image_cache_p->image_cache_item_count = AVATAR_THUMB_IMAGE_CACHE_MAX_COUNT;
    }

    /* init seq number */
    avatar_image_cache_p->image_decode_seq_num = 0;

    /* allocate buffer for list data */
    for (i = 0; i < avatar_image_cache_p->image_cache_item_count; i++)
    {
        avatar_image_cache_p->image_cache_list[i] = &g_avatar_image_cache_list_buffer[i];
        avatar_image_cache_p->image_cache_list[i]->is_used = FALSE;
        avatar_image_cache_p->image_cache_list[i]->unused_duration = 0;
        avatar_image_cache_p->image_cache_list[i]->bmp.buf_ptr = mmi_frm_scrmem_alloc(cache_size);
    }

    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        avatar_image_cache_p->image_handle_list[i] = &g_avatar_image_handle_list_buffer[i];
        avatar_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_free_thumb_image_cache
 * DESCRIPTION
 *  free thumb image cache resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_avatar_free_thumb_image_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset delay decoder */
    avatar_cntx_p->delay_decode_index = 0;
    StopTimer(AVATAR_DELAY_DECODE_0);
    StopTimer(AVATAR_DELAY_DECODE_1);
    StopTimer(AVATAR_DELAY_DECODE_2);
    StopTimer(AVATAR_DELAY_DECODE_3);
    StopTimer(AVATAR_DELAY_DECODE_4);
    StopTimer(AVATAR_DELAY_DECODE_5);
    StopTimer(AVATAR_DELAY_DECODE_6);
    StopTimer(AVATAR_DELAY_DECODE_7);
    StopTimer(AVATAR_DELAY_DECODE_8);
    StopTimer(AVATAR_DELAY_DECODE_9);

    /* free all allocated memory */
    for (i = 0; i < avatar_image_cache_p->image_cache_item_count; i++)
    {
        if (avatar_image_cache_p->image_cache_list[i]->bmp.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(avatar_image_cache_p->image_cache_list[i]->bmp.buf_ptr);
            avatar_image_cache_p->image_cache_list[i]->bmp.buf_ptr = NULL;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
	avatar_image_cache_p->image_cache_item_count = 0;


}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_menuitem_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_draw_menuitem_callback(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 str_width, str_height;
    S32 medium_font_height;
    S32 text_spacing;
    S32 text_offset_x;
    S32 r2l_x1;
    S32 r2l_x2;
    S32 filename_offset_y;
    S32 img_width, img_height;
    PU8 icon_ptr;
    S32 image_offset_x;
    S32 image_offset_y;
    color text_color;
    color text_shadow_color;
    //S32 i,head_idx;

    S8 buffer_UCS2[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* lock and push clip */
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "[Avatar] draw menu item callback, item_idx: %d, is_hilight: %d, x1: %d, y1: %d, x2: %d, y2: %d\n",item_idx, is_hilighted,x1,y1,x2,y2);

    /*
     * this function will draw thumb image menuitem .
     * --------------------------------------
     * | #####                               |    
     * | #####   Avatar's Name               |    <--- Medium Font
     * | #####                               |
     * --------------------------------------
     */

    box_height = y2 - y1 - MMI_AVATAR_UI_IMAGE_BOX_SPACING * 2 + 1;
    box_width = box_height;

    box_offset_y = MMI_AVATAR_UI_IMAGE_BOX_SPACING;

    #ifdef __MTK_TARGET__
    if (r2lMMIFlag)
    #else
    if (r2lMMIFlag==0)
    #endif
    {
        box_offset_x = x2 - box_width - MMI_AVATAR_UI_IMAGE_BOX_SPACING;
    }
    else
    {
        box_offset_x = MMI_AVATAR_UI_IMAGE_BOX_SPACING;
    }

    /*----------------------------------------------------------------*/
    /* Calcuate text position here                                    */
    /*----------------------------------------------------------------*/

    mmi_avatar_get_avatar_name_by_idx(item_idx, &buffer_UCS2[0]);

    gui_set_font(&MMI_medium_font);
    medium_font_height = gui_get_string_height((UI_string_type) buffer_UCS2);
    gui_measure_string((UI_string_type) buffer_UCS2, &str_width, &str_height);

    text_spacing = (y2 - y1 + 1) / 3;

    text_offset_x = x1 + box_width + MMI_AVATAR_UI_TEXT_SPACING;

    r2l_x1 = x1 + MMI_fixed_list_menu.vbar.width + 2;
    r2l_x2 = x2 - (y2 - y1 + 1) - text_spacing;

    filename_offset_y = y1 + text_spacing;
    

    if (is_hilighted)
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
    }
    else
    {
        text_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
        text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
    }

    /*----------------------------------------------------------------*/
    /* Draw File Name                                                 */
    /*----------------------------------------------------------------*/
    if (is_hilighted)
    {
        mmi_ucs2ncpy((PS8) avatar_cntx_p->scrolling_text_ptr, (PS8) buffer_UCS2, mmi_ucs2strlen(buffer_UCS2)*ENCODING_LENGTH);
        avatar_cntx_p->scrolling_text_ptr[mmi_ucs2strlen(buffer_UCS2)*ENCODING_LENGTH + 1] = 0;
        #ifdef __MTK_TARGET__
        if (r2lMMIFlag)
        #else
        if (r2lMMIFlag==0)
        #endif
        {
            gui_create_scrolling_text(
                &avatar_cntx_p->scrolling_text,
                r2l_x1 + 4,                                 /* x */
                filename_offset_y,                          /* y */
                r2l_x2 - r2l_x1 + 4,                        /* width */
                medium_font_height + 2,                     /* height */
                (UI_string_type) avatar_cntx_p->scrolling_text_ptr,     /* string */
                mmi_avatar_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                mmi_avatar_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }
        else
        {
            gui_create_scrolling_text(
                &avatar_cntx_p->scrolling_text,
                text_offset_x,                        /* x */
                filename_offset_y,                          /* y */
                x2 - text_offset_x - 8,               /* width */
                medium_font_height + 2,                     /* height */
                (UI_string_type) avatar_cntx_p->scrolling_text_ptr,     /* string */
                mmi_avatar_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                mmi_avatar_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                text_color,                                 /* text color */
                MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
        }

        avatar_cntx_p->scrolling_text.text_font = MMI_medium_font;
        gui_show_scrolling_text(&avatar_cntx_p->scrolling_text);
    }
    else
    {
        gui_set_font(&MMI_medium_font);

        /* set text clip, avoid draw to overlap scroll bar */
        gui_set_text_color(text_color);

        #ifdef __MTK_TARGET__
        if (r2lMMIFlag)
        #else
        if (r2lMMIFlag==0)
        #endif
        {
            gui_set_text_clip(r2l_x1, filename_offset_y, r2l_x2, filename_offset_y + medium_font_height + 1);

            gui_move_text_cursor(r2l_x2, filename_offset_y);
        }
        else
        {
            gui_set_text_clip(
                text_offset_x,
                filename_offset_y,
                x2 - 1,
                filename_offset_y + medium_font_height + 1);

            gui_move_text_cursor(text_offset_x, filename_offset_y);
        }

        gui_print_text((UI_string_type) buffer_UCS2);
    }

    /*----------------------------------------------------------------*/
    /* Draw Large Icon                                                */
    /*----------------------------------------------------------------*/
    icon_ptr = (PU8) GetImage(IMG_ID_AVATAR_AVATAR_ICON);

    gdi_image_get_dimension(icon_ptr, &img_width, &img_height);
    image_offset_x = (box_width - img_width) >> 1;
    image_offset_y = (box_height - img_height) >> 1;

    if (is_hilighted)
    {
        {
            #ifdef __MTK_TARGET__
            if (r2lMMIFlag)
            #else
            if (r2lMMIFlag==0)
            #endif
                x1 = 0;        
            mmi_avatar_show_thumb_image(
                item_idx,
                x1,
                y1,
                box_offset_x,
                box_offset_y,
                box_width,
                box_height,
                icon_ptr,
                is_hilighted,
                0);
        }
    }
    else
    {
        /* draw thumb image */
        {
            #ifdef __MTK_TARGET__
            if (r2lMMIFlag)
            #else
            if (r2lMMIFlag==0)
            #endif
                x1 = 0;               
            mmi_avatar_show_thumb_image(
                item_idx,
                x1,
                y1,
                box_offset_x,
                box_offset_y,
                box_width,
                box_height,
                icon_ptr,
                is_hilighted,
                0);
        }
    }

    /* pop clip , unlock and blt */
    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_hide_menuitem_callback
 * DESCRIPTION
 *  mmi_avatar_hide_menuitem_callback 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_hide_menuitem_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* stop scroll text */
    gui_scrolling_text_stop(&avatar_cntx_p->scrolling_text);



    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    avatar_cntx_p->delay_decode_index = 0;
    StopTimer(AVATAR_DELAY_DECODE_0);
    StopTimer(AVATAR_DELAY_DECODE_1);
    StopTimer(AVATAR_DELAY_DECODE_2);
    StopTimer(AVATAR_DELAY_DECODE_3);
    StopTimer(AVATAR_DELAY_DECODE_4);
    StopTimer(AVATAR_DELAY_DECODE_5);
    StopTimer(AVATAR_DELAY_DECODE_6);
    StopTimer(AVATAR_DELAY_DECODE_7);
    StopTimer(AVATAR_DELAY_DECODE_8);
    StopTimer(AVATAR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        avatar_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_decode_thumb_image_result_hdlr
 * DESCRIPTION
 *  decode image result handler
 * PARAMETERS
 *  decode_result       [IN]        Return cause
 *  handle              [IN]        Image's handle
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static void mmi_avatar_decode_thumb_image_result_hdlr(GDI_RESULT decode_result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 cache_entry_idx = 0;
    S32 max_unused_duration = 0;
    S32 unused_duration;
    S32 min_seq_number;
    BOOL has_cache_entry;
    color* color_ptr;
    gdi_color bg_color = GDI_COLOR_BLACK;
    S32 image_x1, image_y1, image_x2, image_y2;
    S32 clear_x1, clear_y1, clear_x2, clear_y2; /* previous region need to clear */
    S32 blt_x1, blt_y1, blt_x2, blt_y2;

    fmgr_thumb_image_handle_struct *handle_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_reset_clip();

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] Start decode result, handle: %d\n",handle);

    if (decode_result != GDI_JPEG_SUCCEED)
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((avatar_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (avatar_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* decode failed */
                handle_ptr = avatar_image_cache_p->image_handle_list[i];

                /* get color from theme */
                if (handle_ptr->is_hilighted)
                {
                    color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                    bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                }
                else
                {
                #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__)
                    bg_color = GDI_COLOR_TRANSPARENT;
                #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                    color_ptr = &(current_MMI_theme->list_background_filler->c);
                    bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                }
                avatar_image_cache_p->image_handle_list[i]->is_used = FALSE;
            
                PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] decode fail\n");


                gdi_draw_solid_rect(avatar_image_cache_p->image_handle_list[i]->draw_pos_x,
                                    avatar_image_cache_p->image_handle_list[i]->draw_pos_y,
                                    avatar_image_cache_p->image_handle_list[i]->draw_pos_x + avatar_image_cache_p->image_handle_list[i]->resized_width,
                                    avatar_image_cache_p->image_handle_list[i]->draw_pos_y + avatar_image_cache_p->image_handle_list[i]->resized_height,
                                    bg_color);
                PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] decode fail draw rect, x1: %d, y1: %d, x2: %d, y2: %d\n",avatar_image_cache_p->image_handle_list[i]->draw_pos_x,avatar_image_cache_p->image_handle_list[i]->draw_pos_y,avatar_image_cache_p->image_handle_list[i]->draw_pos_x + avatar_image_cache_p->image_handle_list[i]->resized_width,avatar_image_cache_p->image_handle_list[i]->draw_pos_x + avatar_image_cache_p->image_handle_list[i]->resized_height);

                gdi_image_draw(avatar_image_cache_p->image_handle_list[i]->icon_offset_x,
                               avatar_image_cache_p->image_handle_list[i]->icon_offset_y,
                               avatar_image_cache_p->image_handle_list[i]->icon_ptr);                

                PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] decode fail decode draw img, x1: %d, y1: %d \n",avatar_image_cache_p->image_handle_list[i]->icon_offset_x,avatar_image_cache_p->image_handle_list[i]->icon_offset_y);

                break;  /* break the loop */
            }
        }
    }
    else
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((avatar_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (avatar_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* 
                 * decode success,
                 * (1) Stop animated icon
                 * (1) Wipe out icon by backgroup color.
                 * (2) Draw photo frame.
                 * (3) Find an oldest image cache, and cache the image. 
                 */
                PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] decode successfully\n");

                handle_ptr = avatar_image_cache_p->image_handle_list[i];

                image_x1 = handle_ptr->draw_pos_x;
                image_y1 = handle_ptr->draw_pos_y;
                image_x2 = handle_ptr->draw_pos_x + handle_ptr->resized_width - 1;
                image_y2 = handle_ptr->draw_pos_y + handle_ptr->resized_height - 1;

                /* clear icon by bg color */
                /* since photo is already draw, only draw region not coverd by photo */
                {
                    clear_x1 = handle_ptr->icon_offset_x;
                    clear_y1 = handle_ptr->icon_offset_y;
                    clear_x2 = handle_ptr->icon_offset_x + handle_ptr->icon_width - 1;
                    clear_y2 = handle_ptr->icon_offset_y + handle_ptr->icon_height - 1;
                }

                if (handle_ptr->is_hilighted)
                {
                    color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                    bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                }
                else
                {
                #if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__)
                    bg_color = GDI_COLOR_TRANSPARENT;
                #else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                    color_ptr = &(current_MMI_theme->list_background_filler->c);
                    bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                #endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
                }

                /* left region */
                if (clear_x1 < image_x1 - 1)
                {
                    if (handle_ptr->is_hilighted)
                    {   /* support image highlight only in the list style */
                        mmi_avatar_draw_hilight_menuitem_bg_callback(clear_x1, clear_y1, image_x1 - 1, clear_y2);
                    }
                    else
                    {
                    gdi_draw_solid_rect(clear_x1, clear_y1, image_x1 - 1, clear_y2, bg_color);
                }
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] clean left, x1: %d, y1: %d, x2: %d, y2: %d \n",clear_x1, clear_y1,image_x1-1,clear_y2);
                }

                /* right region */
                if (clear_x2 > image_x2 + 1)
                {
                    if (handle_ptr->is_hilighted)
                    {   /* support image highlight only in the list style */
                        mmi_avatar_draw_hilight_menuitem_bg_callback(image_x2 + 1, clear_y1, clear_x2, clear_y2);
                    }
                    else
                    {
                    gdi_draw_solid_rect(image_x2 + 1, clear_y1, clear_x2, clear_y2, bg_color);
                }
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] clean right, x1: %d, y1: %d, x2: %d, y2: %d \n",image_x2+1, clear_y1,clear_x2,clear_y2);
                }

                /* up region */
                if (clear_y1 < image_y1 - 1)
                {
                    if (handle_ptr->is_hilighted)
                    {   /* support image highlight only in the list style */
                        mmi_avatar_draw_hilight_menuitem_bg_callback(clear_x1, clear_y1, clear_x2, image_y1 - 1);
                    }
                    else
                    {
                    gdi_draw_solid_rect(clear_x1, clear_y1, clear_x2, image_y1 - 1, bg_color);
                }
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] clean up, x1: %d, y1: %d, x2: %d, y2: %d \n",clear_x1, clear_y1, clear_x2, image_y1-1);
                }

                /* down region */
                if (clear_y2 > image_y2 + 1)
                {
                    if (handle_ptr->is_hilighted)
                    {   /* support image highlight only in the list style */
                        mmi_avatar_draw_hilight_menuitem_bg_callback(clear_x1, image_y2 + 1, clear_x2, clear_y2);
                    }
                    else
                    {
                    gdi_draw_solid_rect(clear_x1, image_y2 + 1, clear_x2, clear_y2, bg_color);
                }
                    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] clean down, x1: %d, y1: %d, x2: %d, y2: %d \n",clear_x1, image_y2+1, clear_x2, clear_y2);
                }

                /* draw frame */
                gdi_draw_rect(image_x1 - 1, image_y1 - 1, image_x2 + 1, image_y2 + 1, GDI_COLOR_BLACK);

                {
                    /* calc max blt region (+1 for photo frame) */
                    blt_x1 = (image_x1 - 1 > clear_x1) ? clear_x1 : image_x1 - 1;
                    blt_y1 = (image_y1 - 1 > clear_y1) ? clear_y1 : image_y1 - 1;
                    blt_x2 = (image_x2 + 1 > clear_x2) ? image_x2 + 1 : clear_x2;
                    blt_y2 = (image_y2 + 1 > clear_y2) ? image_y2 + 1 : clear_y2;
                }

                gdi_layer_blt_previous(blt_x1, blt_y1, blt_x2, blt_y2);

                /* check if has valid cache index */
                has_cache_entry = FALSE;
                for (j = 0; j < avatar_image_cache_p->image_cache_item_count; j++)
                {
                    if (avatar_image_cache_p->image_cache_list[j]->is_used == FALSE)
                    {
                        has_cache_entry = TRUE;
                        cache_entry_idx = j;
                        break;
                    }
                }

                /* if not in cache, we will replace the oldest one in cache */
                if (!has_cache_entry)
                {
                    /* find max unused counter */
                    max_unused_duration = 0;
                    for (j = 0; j < avatar_image_cache_p->image_cache_item_count; j++)
                    {
                        if (avatar_image_cache_p->image_cache_list[j]->is_used == TRUE)
                        {
                            unused_duration = avatar_image_cache_p->image_cache_list[j]->unused_duration;
                            max_unused_duration =
                                (max_unused_duration > unused_duration) ? max_unused_duration : unused_duration;
                        }
                    }

                    min_seq_number = 65535;
                    /* find the one with max unused duration will the smallest decode seq number */
                    for (j = 0; j < avatar_image_cache_p->image_cache_item_count; j++)
                    {
                        if ((avatar_image_cache_p->image_cache_list[j]->is_used == TRUE) &&
                            (avatar_image_cache_p->image_cache_list[j]->unused_duration == max_unused_duration))
                        {
                            /* find the one with smallest seq number, which means is the oldest */
                            if (avatar_image_cache_p->image_cache_list[j]->seq_number < min_seq_number)
                            {
                                cache_entry_idx = j;
                                min_seq_number = avatar_image_cache_p->image_cache_list[j]->seq_number;
                            }
                        }
                    }
                }

                /* increase decode seq number */
                if (avatar_image_cache_p->image_decode_seq_num >= 65534)
                {
                    avatar_image_cache_p->image_decode_seq_num = 0;
                }
                else
                {
                    avatar_image_cache_p->image_decode_seq_num++;
                }

                gdi_image_cache_bmp_get(
                    handle_ptr->draw_pos_x,
                    handle_ptr->draw_pos_y,
                    handle_ptr->draw_pos_x + handle_ptr->resized_width - 1,
                    handle_ptr->draw_pos_y + handle_ptr->resized_height - 1,
                    &avatar_image_cache_p->image_cache_list[cache_entry_idx]->bmp);

                avatar_image_cache_p->image_cache_list[cache_entry_idx]->is_used = TRUE;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->unused_duration = 0;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->menuitem_idx = handle_ptr->menuitem_idx;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->resized_offset_x = handle_ptr->resized_offset_x;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->resized_offset_y = handle_ptr->resized_offset_y;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->resized_width = handle_ptr->resized_width;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->resized_height = handle_ptr->resized_height;
                avatar_image_cache_p->image_cache_list[cache_entry_idx]->seq_number =
                avatar_image_cache_p->image_decode_seq_num;

                avatar_image_cache_p->image_handle_list[i]->is_used = FALSE;

                break;  /* break the for loop */
            }           /* if */
        }               /* for */

        if (i >= FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] decode successfully but not found entry\n");
        }
        
    }                   /* if */
    
    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA,"[Avatar] End decode result, handle: %d\n",handle);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_delay_decode_image
 * DESCRIPTION
 *  decode image for delay decoder, avoid UI hang too long
 * PARAMETERS
 *  item_idx                [IN]        Item index
 *  menuitem_offset_x       [IN]        Menu item's offset x
 *  menuitem_offset_y       [IN]        Menu item's offset y
 *  box_offset_x            [IN]        Image box's offset x
 *  box_offset_y            [IN]        Image box's offset y
 *  box_width               [IN]        Image box's width
 *  box_height              [IN]        Image box's height
 *  icon_offset_x           [IN]        Icon's offset x
 *  icon_offset_y           [IN]        Icon's offset y
 *  icon_width              [IN]        Icon's width
 *  icon_height             [IN]        Icon's height
 *  icon_ptr                [IN]        Image ptr
 *  is_hilighted            [IN]        Is highlight flag
 *  ui_style                [IN]        UI style
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
 static void mmi_avatar_delay_decode_image(
                    S32 item_idx,
                    S32 menuitem_offset_x,
                    S32 menuitem_offset_y,
                    S32 box_offset_x,
                    S32 box_offset_y,
                    S32 box_width,
                    S32 box_height,
                    S32 icon_offset_x,
                    S32 icon_offset_y,
                    S32 icon_width,
                    S32 icon_height,
                    PU8 icon_ptr,
                    BOOL is_hilighted,
                    U16 ui_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S8 buffer_UCS2[FMGR_PATH_BUFFER_SIZE];
    GDI_RESULT ret;
    S32 img_width, img_height;
    S32 resized_width, resized_height;
    S32 resized_offset_x, resized_offset_y;
    S32 handle_idx;
    S32 draw_pos_x, draw_pos_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get filename */
    mmi_avatar_get_filename_by_idx(item_idx, &buffer_UCS2[0]);

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* find a vlid decode handle slot */
    for (handle_idx = 0; handle_idx < AVATAR_THUMB_IMAGE_HANDLE_MAX_COUNT; handle_idx++)
    {
        if (avatar_image_cache_p->image_handle_list[handle_idx]->is_used == FALSE)
        {
            break;
        }
    }

    /* valid handle chcek */
    ASSERT(handle_idx < AVATAR_THUMB_IMAGE_HANDLE_MAX_COUNT);

    /* get jpeg width and height */
    ret = gdi_image_get_dimension_file((PS8)buffer_UCS2 , &img_width, &img_height);

    /* check if is a valid image or not */
    /* TODO: Adapt to File limit */
    if ((ret < 0) || (img_width <= 0) || (img_height <= 0))    /* file too large */
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        gdi_layer_pop_clip();
        return;
    }

    /* can get dimesion from file, must be a valid jpeg file, then draw it */

    /* fit it into a bounding box */
    /* reserver 1 pixel at each side to draw boundry */
    gdi_image_util_fit_bbox(
        box_width - 2,
        box_height - 2,
        img_width,
        img_height,
        &resized_offset_x,
        &resized_offset_y,
        &resized_width,
        &resized_height);

    draw_pos_x = box_offset_x + 1 + resized_offset_x;
    draw_pos_y = box_offset_y + 1 + resized_offset_y;
    resized_width--;

    ret = gdi_image_decoder_decode_file(
            draw_pos_x,
            draw_pos_y,
            resized_width,
            resized_height,
            FALSE,
            (PS8) buffer_UCS2,
            &(avatar_image_cache_p->image_handle_list[handle_idx]->handle));

    if (ret >= 0)
    {
        avatar_image_cache_p->image_handle_list[handle_idx]->is_used = TRUE;
        avatar_image_cache_p->image_handle_list[handle_idx]->draw_pos_x = draw_pos_x;
        avatar_image_cache_p->image_handle_list[handle_idx]->draw_pos_y = draw_pos_y;
        avatar_image_cache_p->image_handle_list[handle_idx]->resized_offset_x = resized_offset_x;
        avatar_image_cache_p->image_handle_list[handle_idx]->resized_offset_y = resized_offset_y;
        avatar_image_cache_p->image_handle_list[handle_idx]->resized_width = resized_width;
        avatar_image_cache_p->image_handle_list[handle_idx]->resized_height = resized_height;
        avatar_image_cache_p->image_handle_list[handle_idx]->box_offset_x = box_offset_x;
        avatar_image_cache_p->image_handle_list[handle_idx]->box_offset_y = box_offset_y;
        avatar_image_cache_p->image_handle_list[handle_idx]->box_width = box_width;
        avatar_image_cache_p->image_handle_list[handle_idx]->box_height = box_height;
        avatar_image_cache_p->image_handle_list[handle_idx]->icon_offset_x = icon_offset_x;
        avatar_image_cache_p->image_handle_list[handle_idx]->icon_offset_y = icon_offset_y;
        avatar_image_cache_p->image_handle_list[handle_idx]->icon_width = icon_width;
        avatar_image_cache_p->image_handle_list[handle_idx]->icon_height = icon_height;
        avatar_image_cache_p->image_handle_list[handle_idx]->icon_ptr = icon_ptr;
        avatar_image_cache_p->image_handle_list[handle_idx]->menuitem_idx = (U16) item_idx;
        avatar_image_cache_p->image_handle_list[handle_idx]->is_hilighted = is_hilighted;
        avatar_image_cache_p->image_handle_list[handle_idx]->ui_style = ui_style;
    }
    else
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

    gdi_layer_pop_clip();
    return;

}



/***************************************************************
*  Avatar Screen functions
****************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_enter_editor
 * DESCRIPTION
 *  Avatar Editor app entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_enter_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if new, find a free slot for editing */
    if (avatar_cntx_p->state == AVATAR_STATE_NEW)
    {
        /* save current avatar id for later editing */
        avatar_cntx_p->current_avatar_id = avatar_cntx_p->selected_avatar_id;

        for (i=0;i<MMI_AVATAR_COUNT;i++)
        {
            if (avatar_cntx_p->meta_manager.meta_header[i].is_slot_free ==TRUE)
            break;
        }

        avatar_cntx_p->selected_avatar_id = i;
    }
    else if (avatar_cntx_p->state == AVATAR_STATE_MODIFYING)
    {


    }

    avatar_cntx_p->app_callback_ptr(avatar_cntx_p->selected_avatar_id,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_list_screen
 * DESCRIPTION
 *  show avatar list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_select_path_and_enter(MMI_AVATAR_APP_EDITOR, mmi_avatar_entry_editor_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_exit_list_screen
 * DESCRIPTION
 *  exit avatar list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_exit_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_free_thumb_image_cache();

    /* free jpeg decoder */
    if (avatar_cntx_p->is_decoder_create)
    {
        gdi_image_decoder_free();
        avatar_cntx_p->is_decoder_create = FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_editor_timeout_hdlr
 * DESCRIPTION
 *  avatar entry editor first time timeout hdlr 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_editor_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_unlock_frame_buffer();
    avatar_cntx_p->is_gdi_locked = FALSE;
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle, 0, 0);

#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#else
    SetKeyHandler(mmi_avatar_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_rsk_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_lsk_release, KEY_LSK, KEY_EVENT_UP);
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_TOUCH_SCREEN__
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_avatar_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_avatar_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_avatar_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_editor_screen_internal
 * DESCRIPTION
 *  avatar entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_editor_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8                          *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* allocate memory from App-Based ASM */
    if (avatar_cntx_p->app_mem_pool==NULL)
    {
        avatar_cntx_p->app_mem_pool 
            = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AVATAR, MMI_AVATAR_APP_MEMORY_SIZE );

        if (avatar_cntx_p->app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_AVATAR,
                IMG_ID_AVATAR_APP_ICON,
                MMI_AVATAR_APP_MEMORY_SIZE ,
                mmi_avatar_app_mem_success_callback);
            return;
        }       
    }

    /* entry new screen */
    EntryNewScreen(
        SCR_ID_AVATAR_APP,
        mmi_avatar_exit_editor_screen,
        mmi_avatar_entry_editor_screen_internal,
        NULL);

    SetDelScrnIDCallbackHandler(SCR_ID_AVATAR_APP, mmi_avatar_del_scr_callback);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_AVATAR_APP);

    avatar_cntx_p->m3d_screen_offset_x = MMI_AVATAR_DISPLAY_WINDOW_OFFSET_X;
    avatar_cntx_p->m3d_screen_offset_y = MMI_AVATAR_DISPLAY_WINDOW_OFFSET_Y;
    avatar_cntx_p->m3d_screen_width = MMI_AVATAR_DISPLAY_WINDOW_WIDTH;
    avatar_cntx_p->m3d_screen_height = MMI_AVATAR_DISPLAY_WINDOW_HEIGHT;

    /* create layers */
    {
        PU8 buf_ptr;

        /******************************************************************
        * Init foreground layer
        ******************************************************************/
        buf_ptr  = (PU8) avatar_cntx_p->app_mem_pool;
        if (avatar_cntx_p->drawing_layer_handle == GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_create_using_outside_memory(
                0,
                0,
                avatar_cntx_p->m3d_screen_width,
                avatar_cntx_p->m3d_screen_height,
                &avatar_cntx_p->drawing_layer_handle,
                (PU8) buf_ptr,
                avatar_cntx_p->m3d_screen_width*avatar_cntx_p->m3d_screen_height*2);
        }
        gdi_layer_push_and_set_active(avatar_cntx_p->drawing_layer_handle);
        gdi_layer_set_position(avatar_cntx_p->m3d_screen_offset_x,avatar_cntx_p->m3d_screen_offset_y);
        #ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_set_background(GDI_COLOR_BLACK);
        #endif    
        gdi_layer_pop_and_restore_active();

       /******************************************************************
        * Init OSD layer
        ******************************************************************/
        avatar_cntx_p->osd_layer_buf_ptr = mmi_frm_scrmem_alloc(MMI_AVATAR_OSD_BUFFER_SIZE);
        gdi_layer_create_using_outside_memory(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &avatar_cntx_p->osd_layer_handle,
            (PU8) avatar_cntx_p->osd_layer_buf_ptr,
            MMI_AVATAR_OSD_BUFFER_SIZE );

        gdi_layer_push_and_set_active(avatar_cntx_p->osd_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);    
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();


        /******************************************************************
        * Init texture layer
        ******************************************************************/
        avatar_cntx_p->image_buffer_ptr = mmi_frm_scrmem_alloc(MMI_AVATAR_TEXTURE_BUFFER_SIZE);

        gdi_layer_create_using_outside_memory(
            0,
            0,
            128,
            128,
            &avatar_cntx_p->image_buffer_handle,
            (PU8) avatar_cntx_p->image_buffer_ptr,
            MMI_AVATAR_TEXTURE_BUFFER_SIZE);

        gdi_layer_push_and_set_active(avatar_cntx_p->image_buffer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_GREEN);    
        gdi_layer_pop_and_restore_active();

    }

#ifndef __MMI_TOUCH_SCREEN__
    if (guiBuffer == NULL)
        avatar_cntx_p->is_editor_phase1 = TRUE;
#endif
    avatar_cntx_p->editor_m3d.resourceid = IMG_ID_AVATAR_M3D_EDITOR_ANIMATION;
    /**************************************************************
     * There should be a default setting of new avatar,
     **************************************************************/
    if (avatar_cntx_p->state == AVATAR_STATE_NEW)
    {
        mmi_avatar_load_avatar_default_setting();        
        avatar_cntx_p->state = AVATAR_STATE_NEW_EDITING;
    }
    /**************************************************************
     * If just reboot or not be initialized before, 
     * editor should load the avatar's setting from METAFILES
     **************************************************************/
    else if ( guiBuffer!= NULL || avatar_cntx_p->state == AVATAR_STATE_CHECK_IF_SAVE || avatar_cntx_p->state == AVATAR_STATE_EDITOR_OPTION)
    {       
        /* we will load setting later */
        avatar_cntx_p->editor_m3d.serial_number = 0;
    }
    else
    {
        avatar_cntx_p->last_error = mmi_avatar_load_avatar_setting(&(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]),avatar_cntx_p->selected_avatar_id);
        avatar_cntx_p->editor_m3d.serial_number 
            = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number;
    }

    
    gdi_layer_set_blt_layer(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle, 0, 0);

    gdi_layer_lock_frame_buffer();

    avatar_cntx_p->is_gdi_locked = TRUE;
    
    gdi_layer_push_and_set_active(avatar_cntx_p->drawing_layer_handle);
    gdi_anim_draw_mem_resized(0,
                              0,
                              avatar_cntx_p->m3d_screen_width,
                              avatar_cntx_p->m3d_screen_height,//
                              (PS8)&(avatar_cntx_p->editor_m3d),
                              GDI_IMAGE_TYPE_AVATAR,
                              0, //NO-USE
                              &avatar_cntx_p->anim_handle);
    gdi_layer_pop_and_restore_active();

    gdi_image_m3d_avatar_get_all_var((void**)&(avatar_cntx_p->m3d_camera),
                                     (void**)&(m3d_world),                        
                                     (void**)&(avatar_cntx_p->m3d_world_head),
                                     (void**)&(avatar_cntx_p->m3d_world_hair),
                                     (void**)&(avatar_cntx_p->m3d_world_body));

    {
        float tmpf = (float)avatar_cntx_p->m3d_screen_width/avatar_cntx_p->m3d_screen_height;
        M3D_Camera_setPerspective(avatar_cntx_p->m3d_camera, 39.27,tmpf , 1, 1000);
        if (avatar_cntx_p->selected_top_object == AVATAR_TOUCH_BODY)
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_BODY_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_BODY_OFFSET_Z);
        else
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);

    }

    if (guiBuffer!= NULL || avatar_cntx_p->state == AVATAR_STATE_CHECK_IF_SAVE || avatar_cntx_p->state == AVATAR_STATE_EDITOR_OPTION)
    {
        if (avatar_cntx_p->state == AVATAR_STATE_CHECK_IF_SAVE || avatar_cntx_p->state == AVATAR_STATE_EDITOR_OPTION)
            avatar_cntx_p->state = avatar_cntx_p->prev_state;
        mmi_avatar_apply_setting_to_avatar();
    }

    /* 1st time enter, we need to load default selection */
    if (guiBuffer == NULL)
    {
        mmi_avatar_reset_top_icon();
        avatar_cntx_p->page_of_head = 0;
        avatar_cntx_p->page_of_hair = 0;
        avatar_cntx_p->page_of_eye = 0;
        avatar_cntx_p->page_of_lip = 0;
        avatar_cntx_p->page_of_brow = 0;
        avatar_cntx_p->page_of_decoration = 0;
        avatar_cntx_p->page_of_body = 0;    
        avatar_cntx_p->selected_top_object = AVATAR_TOUCH_HEAD;
        avatar_osd_cntx_p->head.is_press = AVATAR_ICON_STATUS_CLICKED ;
        mmi_avatar_bottom_icon_page_change(0);   
    }
    mmi_avatar_draw_osd();

    /* block card-in interrupt only */
    mmi_frm_block_general_interrupt_event(MMI_FRM_INT_FMGR_CARD);
    ClearInputEventHandler(MMI_DEVICE_KEY);
    gui_start_timer(100,mmi_avatar_editor_timeout_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_avatar_editor_screen
 * DESCRIPTION
 *  show avatar list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_editor_screen(U32 avatar_id, U32 serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_entry_editor_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_select_path_and_enter_internal
 * DESCRIPTION
 *  mmi_avatar_select_path_and_enter_internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_select_path_and_enter_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 box_width;
    S32 box_height;
    S32 high_light_idx;
    U16 lsk_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_AVATAR_LIST_MENU,mmi_avatar_exit_list_screen,mmi_avatar_select_path_and_enter_internal,NULL);

    ClearInputEventHandler(MMI_DEVICE_KEY);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_AVATAR_LIST_MENU);

    if (guiBuffer == NULL)
        high_light_idx = 0;
    else
    {
        if ((avatar_cntx_p->app_type == MMI_AVATAR_APP_EDITOR)&&(avatar_cntx_p->state == AVATAR_STATE_SAVING_NEW))
        {
            high_light_idx = avatar_cntx_p->meta_manager.total_count-1; 
        }
        else
        {
            if (avatar_cntx_p->meta_manager.total_count <= avatar_cntx_p->high_light_idx)
                high_light_idx = avatar_cntx_p->meta_manager.total_count -1;
            else
                high_light_idx = avatar_cntx_p->high_light_idx;
        }
    }
    RegisterHighlightHandler(mmi_avatar_list_highlight_hdlr);

    /***************************************************************************
     * Background decode image: Create Resource & init GDI related Jobs        *
     **************************************************************************/
    GetCategory214BoxSize(3, 3, &box_width, &box_height);

    /* create image cache */
    mmi_avatar_create_thumb_image_cache((box_width > box_height) ? box_width : box_height);

    if (avatar_cntx_p->is_decoder_create == FALSE)
    {
        /* create jpeg decoder */
        gdi_image_decoder_create(100, 100, mmi_avatar_decode_thumb_image_result_hdlr);
        avatar_cntx_p->is_decoder_create = TRUE;
    }

    if (avatar_cntx_p->app_type == MMI_AVATAR_APP_EDITOR)
    {
        lsk_id = STR_GLOBAL_OPTIONS;
    }
    else
    {
        if (avatar_cntx_p->meta_manager.total_count == 0)
            lsk_id = 0;
        else
            lsk_id = STR_GLOBAL_OK;
    }

    /******************************************
     * CategoryScreen213 shows the list menu  *
     *****************************************/
     ShowCategory213Screen(
        STR_ID_AVATAR_APP_NAME,
        GetRootTitleIcon(MENU_ID_AVATAR_EDITOR),
        lsk_id,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        avatar_cntx_p->meta_manager.total_count,
        mmi_avatar_draw_menuitem_callback,
        mmi_avatar_hide_menuitem_callback,
        high_light_idx,
        CAT213_ARROW_ALL,
        guiBuffer);

    switch (avatar_cntx_p->app_type)
    {
        case MMI_AVATAR_APP_CALLER_PICTURE:
            if (avatar_cntx_p->meta_manager.total_count > 0)
            {
                SetLeftSoftkeyFunction(mmi_avatar_set_caller_picture, KEY_EVENT_UP);
                SetKeyHandler(mmi_avatar_set_caller_picture, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
            break;
        case MMI_AVATAR_APP_WALLPAPER:
        case MMI_AVATAR_APP_CALLER_VIDEO:
        case MMI_AVATAR_APP_SCREENSAVER:
        case MMI_AVATAR_APP_POWERON_ANIMATION:
        case MMI_AVATAR_APP_POWEROFF_ANIMATION:
            if (avatar_cntx_p->meta_manager.total_count > 0)
            {
                avatar_cntx_p->state = AVATAR_STATE_SELECT_ANIMATION;
                SetLeftSoftkeyFunction(mmi_avatar_entry_select_animation_screen, KEY_EVENT_UP);
                SetKeyHandler(mmi_avatar_entry_select_animation_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            }
            break;
        case MMI_AVATAR_APP_EDITOR:
            SetLeftSoftkeyFunction(mmi_avatar_entry_option_menu_screen, KEY_EVENT_UP);
            SetKeyHandler(mmi_avatar_entry_option_menu_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        default:
            break;
    }

    ClearKeyEvents();
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_exit_editor_screen
 * DESCRIPTION
 *  avatar ooxx function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_exit_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_cntx_p->is_gdi_locked == TRUE)
    {
        gdi_layer_unlock_frame_buffer();
        avatar_cntx_p->is_gdi_locked = FALSE;
        gui_cancel_timer(mmi_avatar_editor_timeout_hdlr);
    }

	
    gdi_layer_flatten_to_base(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);
    
	if (avatar_cntx_p->is_scrolling_title == TRUE)
        gui_scrolling_text_stop(&avatar_cntx_p->scrolling_text);

#if 0
/* under construction !*/
/* under construction !*/
#else

    gdi_anim_stop(avatar_cntx_p->anim_handle);
    avatar_cntx_p->anim_handle = GDI_NULL_HANDLE;

    if (avatar_cntx_p->osd_layer_buf_ptr!= NULL)
    {
        mmi_frm_scrmem_free((void*)avatar_cntx_p->osd_layer_buf_ptr);
        avatar_cntx_p->osd_layer_buf_ptr = NULL;
    }

    if (avatar_cntx_p->osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(avatar_cntx_p->osd_layer_handle );
        avatar_cntx_p->osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (avatar_cntx_p->image_buffer_ptr != NULL)
    {
        mmi_frm_scrmem_free((void*)avatar_cntx_p->image_buffer_ptr);
        avatar_cntx_p->image_buffer_ptr = NULL;
    }

    if (avatar_cntx_p->image_buffer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(avatar_cntx_p->image_buffer_handle);
        avatar_cntx_p->image_buffer_handle = GDI_LAYER_EMPTY_HANDLE;
    }


#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_init_option_menu
 * DESCRIPTION
 *  Init menus hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_init_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_AVATAR_OPTION_NEW, mmi_avatar_highlight_new);
    SetHiliteHandler(MENU_ID_AVATAR_OPTION_EDIT, mmi_avatar_highlight_edit);
    SetHiliteHandler(MENU_ID_AVATAR_OPTION_PLAY, mmi_avatar_highlight_play);
    SetHiliteHandler(MENU_ID_AVATAR_OPTION_DELETE, mmi_avatar_highlight_delete);
    SetHiliteHandler(MENU_ID_AVATAR_OPTION_RENAME, mmi_avatar_highlight_rename);
    SetHiliteHandler(MENU_ID_AVATAR_OPTION_DELETE_ALL, mmi_avatar_highlight_delete_all);


    SetHiliteHandler(MENU_ID_AVATAR_EDITOR_OPTION_SAVE, mmi_avatar_highlight_save);
    SetHiliteHandler(MENU_ID_AVATAR_EDITOR_OPTION_EXIT, mmi_avatar_highlight_exit);

    SetHiliteHandler(MENU_ID_AVATAR_EDITOR_RENAME_DONE, mmi_avatar_hilight_text_edit_done);
    SetHiliteHandler(MENU_ID_AVATAR_EDITOR_RENAME_INPUT_METHOD, mmi_avatar_hilight_text_sel_inp_method);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_hilight_text_sel_inp_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_hilight_text_sel_inp_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_hilight_text_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_hilight_text_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (avatar_cntx_p->state)
    {
        case AVATAR_STATE_NEW_EDITING:
            SetLeftSoftkeyFunction(mmi_avatar_save_new_avatar, KEY_EVENT_UP);
        break;
        case AVATAR_STATE_RENAME:
            SetLeftSoftkeyFunction(mmi_avatar_rename_avatar, KEY_EVENT_UP);
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_option_menu_screen
 * DESCRIPTION
 *  option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_option_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AVATAR_OPTION_MENU, NULL, mmi_avatar_entry_option_menu_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AVATAR_OPTION_MENU);

    /* restore correct avatar id */
    if (guiBuffer != NULL )
        avatar_cntx_p->selected_avatar_id = avatar_cntx_p->current_avatar_id;
	else 
        avatar_cntx_p->current_avatar_id = avatar_cntx_p->selected_avatar_id;

    if (avatar_cntx_p->meta_manager.total_count==0)
    {
        mmi_frm_hide_menu_item(MENU_ID_AVATAR_OPTION_EDIT);
        mmi_frm_hide_menu_item(MENU_ID_AVATAR_OPTION_PLAY);
        mmi_frm_hide_menu_item(MENU_ID_AVATAR_OPTION_DELETE);
        mmi_frm_hide_menu_item(MENU_ID_AVATAR_OPTION_RENAME);
        mmi_frm_hide_menu_item(MENU_ID_AVATAR_OPTION_DELETE_ALL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_AVATAR_OPTION_EDIT);
        mmi_frm_unhide_menu_item(MENU_ID_AVATAR_OPTION_PLAY);
        mmi_frm_unhide_menu_item(MENU_ID_AVATAR_OPTION_DELETE);
        mmi_frm_unhide_menu_item(MENU_ID_AVATAR_OPTION_RENAME);
        mmi_frm_unhide_menu_item(MENU_ID_AVATAR_OPTION_DELETE_ALL);
    }

    if (avatar_cntx_p->meta_manager.total_count == MMI_AVATAR_COUNT)
    {
        mmi_frm_hide_menu_item(MENU_ID_AVATAR_OPTION_NEW);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_AVATAR_OPTION_NEW);
    }
    
    nItems = GetNumOfChild_Ext(MENU_ID_AVATAR_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_AVATAR_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_AVATAR_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_AVATAR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_AVATAR_OPTION, PopUpList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_AVATAR_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    ClearKeyEvents();
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_exit_editor_option
 * DESCRIPTION
 *  EXIT option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_exit_editor_option(void)
{
    DeleteUptoScrID(SCR_ID_AVATAR_EDITOR);
    DeleteNHistory(2);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_option_menu_screen
 * DESCRIPTION
 *  option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_editor_option_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AVATAR_EDITOR_OPTION_MENU, NULL, mmi_avatar_entry_editor_option_menu_screen, NULL);


    guiBuffer = GetCurrGuiBuffer(SCR_ID_AVATAR_EDITOR_OPTION_MENU);

    if (guiBuffer == NULL)
    {
        avatar_cntx_p->prev_state = avatar_cntx_p->state;
        avatar_cntx_p->state = AVATAR_STATE_EDITOR_OPTION;
    }

    /* restore correct avatar id */
    nItems = GetNumOfChild_Ext(MENU_ID_AVATAR_EDITOR_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_AVATAR_EDITOR_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_AVATAR_EDITOR_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_AVATAR_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_AVATAR_EDITOR_OPTION, PopUpList);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_AVATAR_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    ClearKeyEvents();
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_save_by_option_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_save_by_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->state = avatar_cntx_p->prev_state ;
    if (avatar_cntx_p->state == AVATAR_STATE_NEW_EDITING )
    {
        mmi_avatar_entry_editing_name_screen();
    }
    else if (avatar_cntx_p->state == AVATAR_STATE_MODIFYING)
    {
        /* clear all keys */
        ClearInputEventHandler(MMI_DEVICE_KEY);

        /* encode avatar's head into a Jpeg file */
        mmi_avatar_encode_jpeg();



        ret = mmi_avatar_save_avatar_setting(&(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]),avatar_cntx_p->selected_avatar_id);
        
        if (ret < 0)
        {
            mmi_avatar_display_error_popup(ret);
        }

        mmi_avatar_save_meta_manager();

        DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_SAVING), 
                            IMG_GLOBAL_SAVE, 
                            1, 
                            ST_NOTIFYDURATION, 
                            0, 
                            mmi_avatar_saving_timeout_by_option_menu);

        DeleteUptoScrID(SCR_ID_AVATAR_EDITOR);
        DeleteNHistory(3);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_editing_name_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_editing_name_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AVATAR_EDITING_NAME, NULL, mmi_avatar_entry_editing_name_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_AVATAR_EDITING_NAME);

    /* reset */
    if (gui_buffer == NULL)
    {
        if (avatar_cntx_p->state == AVATAR_STATE_RENAME)
            mmi_ucs2cpy((PS8)avatar_cntx_p->avatar_name,avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].filename);
        else if (avatar_cntx_p->state == AVATAR_STATE_NEW_EDITING)
            avatar_cntx_p->avatar_name[0] = 0;
    }

    ShowCategory5Screen(
        STR_ID_AVATAR_APP_NAME,
        GetRootTitleIcon(MENU_ID_AVATAR_EDITOR),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) &(avatar_cntx_p->avatar_name[0]),
        AVATAR_MAX_NAME_LEN,
        gui_buffer);

    ClearKeyEvents();
    SetLeftSoftkeyFunction(mmi_avatar_entry_edit_option_screen, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_avatar_return_to_editor_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_return_to_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_return_to_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_edit_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_entry_edit_option_screen(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AVATAR_EDITING_NAME_OPTION, 0, mmi_avatar_entry_edit_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_AVATAR_EDITING_NAME_OPTION);

    mmi_avatar_show_option52(MENU_ID_AVATAR_EDITOR_RENAME_OPTION, STR_GLOBAL_OPTIONS, gui_buffer);
    ClearKeyEvents();
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    if (avatar_cntx_p->state == AVATAR_STATE_SAVING_NEW)
    {
        mmi_avatar_saving_timeout();
        DeleteUptoScrID(SCR_ID_AVATAR_OPTION_MENU);
        DeleteNHistory(1);
    }
    /* ToDo: FRAME_TEXT_PROPERTY will write later after other part done. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_show_option52
 * DESCRIPTION
 *  interal use for showing option52 screen.
 * PARAMETERS
 *  id_menu         [IN]        Menu id
 *  id_str          [IN]        String id
 *  gui_buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_show_option52(U16 id_menu, U16 id_str, PU8 gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 i;
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nItems = GetNumOfChild_Ext(id_menu);
    GetSequenceStringIds_Ext(id_menu, ItemList);
    for (i = 0; i < nItems; i++)
    {
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }
    SetParentHandler(id_menu);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        id_str,
        GetRootTitleIcon(MENU_ID_AVATAR_EDITOR),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,  /* hint list */
        0,
        0,
        gui_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_exit_select_animation_screen
 * DESCRIPTION
 *  exit select animation screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_exit_select_animation_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
    #endif 

    gdi_layer_flatten_to_base(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    
    gdi_anim_stop(avatar_cntx_p->anim_handle);
    avatar_cntx_p->anim_handle = GDI_NULL_HANDLE;

    avatar_cntx_p->drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    if (avatar_cntx_p->osd_layer_buf_ptr!= NULL)
    {
        mmi_frm_scrmem_free((void*)avatar_cntx_p->osd_layer_buf_ptr);
        avatar_cntx_p->osd_layer_buf_ptr = NULL;
    }

    if (avatar_cntx_p->osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(avatar_cntx_p->osd_layer_handle );
        avatar_cntx_p->osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /* this will force title status to redraw */
    entry_full_screen();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_entry_select_animation_screen
 * DESCRIPTION
 *  test touch screen icon
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_entry_select_animation_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
    EntryNewScreen(
        SCR_ID_AVATAR_SELECT_ANIMATION,
        mmi_avatar_exit_select_animation_screen,
        mmi_avatar_entry_select_animation_screen,
        NULL);

    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
    #endif 

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AVATAR_SELECT_ANIMATION);

    if (avatar_cntx_p->is_reload == TRUE && gui_buffer == NULL)
    {       
        avatar_cntx_p->editor_m3d.image_type = GDI_IMAGE_TYPE_AVATAR;
        avatar_cntx_p->editor_m3d.serial_number = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number;
        avatar_cntx_p->editor_m3d.resourceid = IMG_ID_AVATAR_M3D_ANIMATION_1 + avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_animation;
        avatar_cntx_p->selected_animation = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_animation;
    }
    else
    {
        avatar_cntx_p->editor_m3d.resourceid = IMG_ID_AVATAR_M3D_ANIMATION_1 + avatar_cntx_p->selected_animation;
    }

    gdi_layer_get_base_handle(&(avatar_cntx_p->drawing_layer_handle));

    /******************************************************************
    * Init OSD layer
    ******************************************************************/
    avatar_cntx_p->osd_layer_buf_ptr = mmi_frm_scrmem_alloc(MMI_AVATAR_OSD_BUFFER_SIZE);
    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &avatar_cntx_p->osd_layer_handle,
        (PU8) avatar_cntx_p->osd_layer_buf_ptr,
        MMI_AVATAR_OSD_BUFFER_SIZE );

    gdi_layer_push_and_set_active(avatar_cntx_p->osd_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);    
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(avatar_cntx_p->drawing_layer_handle, avatar_cntx_p->osd_layer_handle, 0, 0);
    /* set rsk to ENABLE */
    avatar_cntx_p->rsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_layer_push_and_set_active(avatar_cntx_p->drawing_layer_handle);

    ret = gdi_anim_draw_mem(
            0,
            0,
            (PS8)&(avatar_cntx_p->editor_m3d),
            GDI_IMAGE_TYPE_AVATAR,
            0, // NO USE
            &avatar_cntx_p->anim_handle);
    gdi_layer_pop_and_restore_active();    

    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
    {
        SetKeyHandler(mmi_avatar_lsk_press, KEY_LSK,KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_set_animation, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_avatar_set_animation, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetKeyHandler(mmi_avatar_rsk_press, KEY_RSK,KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_rsk_release_from_select_animation_screen, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    SetKeyHandler(mmi_avatar_top_rarrow_icon_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_top_larrow_icon_press, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_top_rarrow_icon_release, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_top_larrow_icon_release, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_top_rarrow_icon_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_top_larrow_icon_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_top_rarrow_icon_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_top_larrow_icon_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    /* register pen down/up/move event */
    wgui_register_pen_down_handler(mmi_avatar_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_avatar_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_avatar_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* block card-in interrupt only */
    mmi_frm_block_general_interrupt_event(MMI_FRM_INT_FMGR_CARD);

}


/***************************************************************
*  High light handler functions
****************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_app
 * DESCRIPTION
 *  app menu item hilight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_avatar_entry_list_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_entry_list_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_list_highlight_hdlr
 * DESCRIPTION
 *  avatar list highlight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_list_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->high_light_idx = idx;
    avatar_cntx_p->selected_avatar_id = mmi_avatar_get_id_from_idx(idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_new
 * DESCRIPTION
 *  high light new menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->state = AVATAR_STATE_NEW;
   
    SetLeftSoftkeyFunction(mmi_avatar_enter_editor, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_enter_editor, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_edit
 * DESCRIPTION
 *  high light edit menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->state = AVATAR_STATE_MODIFYING;
    SetLeftSoftkeyFunction(mmi_avatar_enter_editor, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_enter_editor, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_play
 * DESCRIPTION
 *  high light play menu item
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->state = AVATAR_STATE_DISPLAYING;
    SetLeftSoftkeyFunction(mmi_avatar_entry_select_animation_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_entry_select_animation_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_delete
 * DESCRIPTION
 *  high light delete menu item
 * PARAMETERS
 *  high light delete menu item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_avatar_delete_avatar_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_delete_avatar_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_delete
 * DESCRIPTION
 *  high light delete menu item
 * PARAMETERS
 *  high light delete menu item
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_avatar_delete_all_avatar_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_delete_all_avatar_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_rename
 * DESCRIPTION
 *  high light rename menu item
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->state = AVATAR_STATE_RENAME;
    SetLeftSoftkeyFunction(mmi_avatar_entry_editing_name_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_entry_editing_name_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_save
 * DESCRIPTION
 *  high light rename menu item
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_avatar_save_by_option_menu, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_save_by_option_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_highlight_exit
 * DESCRIPTION
 *  high light rename menu item
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_highlight_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_avatar_exit_editor_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_exit_editor_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/***************************************************************
*  OSD related functions
****************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_osd
 * DESCRIPTION
 *  Draw OSD layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define DRAW_OSD_ICON(a,A)\
    do {\
        if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_CLICKED )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x,avatar_osd_cntx_p->##a##.offset_y,IMG_ID_AVATAR_##A##_SELECTED);\
            mmi_avatar_draw_bottom_icon();\
        }\
    } while(0)

#define DRAW_OSD_ICON2(a,A)\
    do {\
        if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_CLICKED )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x,avatar_osd_cntx_p->##a##.offset_y,IMG_ID_AVATAR_##A##_SELECTED);\
        }\
        else if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_ENABLE )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x,avatar_osd_cntx_p->##a##.offset_y,IMG_ID_AVATAR_##A##_ON);\
        }\
    } while(0)

#define DRAW_OSD_ICON3(a,A)\
    do {\
        if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_CLICKED )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x+2,avatar_osd_cntx_p->##a##.offset_y+2,IMG_ID_AVATAR_##A##_SELECTED);\
        }\
        else if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_ENABLE )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x,avatar_osd_cntx_p->##a##.offset_y,IMG_ID_AVATAR_##A##_ON);\
        }\
    } while(0)

#define DRAW_OSD_ICON4(a,A)\
    do {\
        if (avatar_cntx_p->is_editor_phase1 == TRUE)\
        {/* DO NOTHING*/}\
        else if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_CLICKED )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x,avatar_osd_cntx_p->##a##.offset_y,IMG_ID_AVATAR_##A##_SELECTED);\
        }\
        else if(avatar_osd_cntx_p->##a##.is_press == AVATAR_ICON_STATUS_ENABLE )\
        {\
            gdi_image_draw_id(avatar_osd_cntx_p->##a##.offset_x,avatar_osd_cntx_p->##a##.offset_y,IMG_ID_AVATAR_##A##_ON);\
        }\
    } while(0)


    gdi_layer_push_and_set_active(avatar_cntx_p->osd_layer_handle);
    /* toggle double buffer */
    gdi_layer_toggle_double();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);


    if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING || avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
    {
        mmi_avatar_draw_osd_sofekey();
        mmi_avatar_draw_osd_title();
        DRAW_OSD_ICON3(top_larrow,TOP_LARROW);
        DRAW_OSD_ICON3(top_rarrow,TOP_RARROW);
    }
    else
    {

        /* draw background */
        gdi_image_draw_id(0, 0, IMG_ID_AVATAR_BG);

        mmi_avatar_draw_osd_sofekey();

#ifndef __MMI_TOUCH_SCREEN__
        DRAW_OSD_ICON(head,HEAD);
        DRAW_OSD_ICON(hair,HAIR);
        DRAW_OSD_ICON(eye,EYE);
        DRAW_OSD_ICON(decoration,DECORATION);
        DRAW_OSD_ICON(brow,BROW);
        DRAW_OSD_ICON(lip,LIP);
        DRAW_OSD_ICON(body,BODY);

        DRAW_OSD_ICON4(moveup,MOVEUP);
        DRAW_OSD_ICON4(movedown,MOVEDOWN);
        DRAW_OSD_ICON4(stretch,STRETCH);
        DRAW_OSD_ICON4(shrink,SHRINK);
        DRAW_OSD_ICON4(magnify,MAGNIFY);
        DRAW_OSD_ICON4(minify,MINIFY);

        if(avatar_cntx_p->is_editor_phase1==FALSE)
        {
            gdi_draw_rect(REC_1_X1,REC_1_Y1,REC_1_X2,REC_1_Y2,GDI_COLOR_RED);
        }
        else
        {
            gdi_draw_rect(REC_2_X1,REC_2_Y1,REC_2_X2,REC_2_Y2,GDI_COLOR_RED);
        }


        if(avatar_cntx_p->is_editor_phase1!= TRUE && avatar_osd_cntx_p->color.is_press == AVATAR_ICON_STATUS_ENABLE)
        {
            switch (avatar_cntx_p->selected_top_object)
            {
                case AVATAR_TOUCH_HEAD:      
                gdi_image_draw_id(avatar_osd_cntx_p->color.offset_x,
                                  avatar_osd_cntx_p->color.offset_y,
                                  IMG_ID_AVATAR_FACE_1 + avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face);
                break;
                case AVATAR_TOUCH_BODY:
                gdi_image_draw_id(avatar_osd_cntx_p->color.offset_x,
                                  avatar_osd_cntx_p->color.offset_y,
                                  IMG_ID_AVATAR_DRESS_1 + avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress);
                break;
            }
        }


#else
        DRAW_OSD_ICON(head,HEAD);
        DRAW_OSD_ICON(hair,HAIR);
        DRAW_OSD_ICON(eye,EYE);
        DRAW_OSD_ICON(decoration,DECORATION);
        DRAW_OSD_ICON(brow,BROW);
        DRAW_OSD_ICON(lip,LIP);
        DRAW_OSD_ICON(body,BODY);

        DRAW_OSD_ICON2(moveup,MOVEUP);
        DRAW_OSD_ICON2(movedown,MOVEDOWN);
        DRAW_OSD_ICON2(stretch,STRETCH);
        DRAW_OSD_ICON2(shrink,SHRINK);
        DRAW_OSD_ICON2(magnify,MAGNIFY);
        DRAW_OSD_ICON2(minify,MINIFY);

        DRAW_OSD_ICON2(rarrow,RARROW);
        DRAW_OSD_ICON2(larrow,LARROW); 

        if(avatar_osd_cntx_p->color.is_press == AVATAR_ICON_STATUS_ENABLE)
        {
            switch (avatar_cntx_p->selected_top_object)
            {
                case AVATAR_TOUCH_HEAD:      
                gdi_image_draw_id(avatar_osd_cntx_p->color.offset_x,
                                  avatar_osd_cntx_p->color.offset_y,
                                  IMG_ID_AVATAR_FACE_1 + avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face);
                break;
                case AVATAR_TOUCH_BODY:
                gdi_image_draw_id(avatar_osd_cntx_p->color.offset_x,
                                  avatar_osd_cntx_p->color.offset_y,
                                  IMG_ID_AVATAR_DRESS_1 + avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress);
                break;
            }
        }
#endif

    }        
#undef DRAW_OSD_ICON2
#undef DRAW_OSD_ICON

    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_osd_sofekey
 * DESCRIPTION
 *  draw preview softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_osd_sofekey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    U16 lsk_id = 0;
    U16 rsk_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION ||avatar_cntx_p->state == AVATAR_STATE_DISPLAYING )
        rsk_id = STR_GLOBAL_BACK;
    else
    {
    #ifndef __MMI_TOUCH_SCREEN__
        rsk_id = STR_ID_AVATAR_OPTION_TOGGLE;
    #else
        rsk_id = STR_GLOBAL_BACK;
    #endif
    }


    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        lsk_id = STR_GLOBAL_OK;
    else if (avatar_cntx_p->state != AVATAR_STATE_DISPLAYING)
    {
    #ifndef __MMI_TOUCH_SCREEN__
        lsk_id = STR_GLOBAL_OPTIONS;
    #else
        lsk_id = STR_GLOBAL_SAVE;
    #endif
    }
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    gui_set_font(&MMI_medium_font);

    if (avatar_cntx_p->state != AVATAR_STATE_DISPLAYING)
    {
        /* lsk */
        str_ptr = (PS8) GetString(lsk_id);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        wgui_softkey_get_offset((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY);

        /* check r2lMMIFlag flag to correct offset_x of string, due to we will do the change in 
         * mmi_camera_draw_style_text() */
        #ifdef __MTK_TARGET__
        if (r2lMMIFlag)
        #else
        if (r2lMMIFlag==0)
        #endif
        {
            lsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
        }

        if (avatar_cntx_p->lsk.is_press == AVATAR_ICON_STATUS_CLICKED)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }

        mmi_avatar_draw_style_text(
            str_ptr,
            lsk_offset_x ,
            lsk_offset_y );


        avatar_cntx_p->lsk.offset_x = lsk_offset_x;
        avatar_cntx_p->lsk.offset_y = lsk_offset_y;
        avatar_cntx_p->lsk.width = str_width;
        avatar_cntx_p->lsk.height = str_height;
    }
    /* rsk */

    #ifndef __MMI_TOUCH_SCREEN__
    if (((avatar_cntx_p->selected_top_object != AVATAR_TOUCH_HAIR) 
        && !((avatar_cntx_p->selected_top_object == AVATAR_TOUCH_DECORATION) && (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_decoration ==0)))
        || (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING ||avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION))
    #endif
    {
        str_ptr = (PS8) GetString(rsk_id);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        wgui_softkey_get_offset((UI_string_type) str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY);

        #ifdef __MTK_TARGET__
        if (r2lMMIFlag)
        #else
        if (r2lMMIFlag==0)
        #endif
        {
            rsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
        }

        if (avatar_cntx_p->rsk.is_press == AVATAR_ICON_STATUS_CLICKED)
        {
            rsk_offset_x++;
            rsk_offset_y++;
        }

        mmi_avatar_draw_style_text(
            str_ptr,
            rsk_offset_x,
            rsk_offset_y);

        avatar_cntx_p->rsk.offset_x = rsk_offset_x;
        avatar_cntx_p->rsk.offset_y = rsk_offset_y;
        avatar_cntx_p->rsk.width = str_width;
        avatar_cntx_p->rsk.height = str_height;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_style_text
 * DESCRIPTION
 *  draw style text 
 * PARAMETERS
 *  str          [IN]        String to be draw    
 *  offset_x     [IN]        x position
 *  offset_y     [IN]        y position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_style_text(PS8 str, S32 offset_x, S32 offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MTK_TARGET__
    if (r2lMMIFlag)
    #else
    if (r2lMMIFlag==0)
    #endif
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    gui_move_text_cursor(offset_x, offset_y);
    gui_set_text_color(gui_color(67,87,153));
    gui_set_text_border_color(gui_color(255,255,255));
    gui_print_bordered_text((UI_string_type) str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_bottom_icon
 * DESCRIPTION
 *  draw bottom icons
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_bottom_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_idx = 0;
    U16 img_id = 0,img_large_id = 0,count_of_itom = 0;
    S16 i;
    S32 offset_x,offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_HEAD:     
            start_idx = (avatar_cntx_p->page_of_head)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_HEAD_1;
            img_large_id = IMG_ID_AVATAR_HEAD_1_SELECTED;
            count_of_itom = MMI_AVATAR_COUNT_OF_HEAD;
        break;
        case AVATAR_TOUCH_HAIR:     
            start_idx = (avatar_cntx_p->page_of_hair)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_HAIR_1;
            img_large_id = IMG_ID_AVATAR_HAIR_1_SELECTED;            
            count_of_itom = MMI_AVATAR_COUNT_OF_HAIR;
            break;
        case AVATAR_TOUCH_LIP:
            start_idx = (avatar_cntx_p->page_of_lip)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_LIP_1;
            img_large_id = IMG_ID_AVATAR_LIP_1_SELECTED;
            count_of_itom = MMI_AVATAR_COUNT_OF_LIP;
            break;
        case AVATAR_TOUCH_EYE:     
            start_idx = (avatar_cntx_p->page_of_eye)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_EYE_1;
            img_large_id = IMG_ID_AVATAR_EYE_1_SELECTED;
            count_of_itom = MMI_AVATAR_COUNT_OF_EYE;
        break;
        case AVATAR_TOUCH_DECORATION:
            start_idx = (avatar_cntx_p->page_of_decoration)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_DECORATION_1;
            img_large_id = IMG_ID_AVATAR_DECORATION_1_SELECTED;
            count_of_itom = MMI_AVATAR_COUNT_OF_DECORATION;
        break;
        case AVATAR_TOUCH_BODY:     
            start_idx = (avatar_cntx_p->page_of_body)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_BODY_1;
            img_large_id = IMG_ID_AVATAR_BODY_1_SELECTED;
            count_of_itom = MMI_AVATAR_COUNT_OF_BODY;
        break;
        case AVATAR_TOUCH_BROW:     
            start_idx = (avatar_cntx_p->page_of_brow)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
            img_id = IMG_ID_AVATAR_BROW_1;
            img_large_id = IMG_ID_AVATAR_BROW_1_SELECTED;
            count_of_itom = MMI_AVATAR_COUNT_OF_BROW;
        break;
    }

    offset_x = MMI_AVATAR_BOTTOM_ICON_START_POSITION_X;

    if (avatar_cntx_p->is_highlighted)
        offset_x -= MMI_AVATAR_BOTTOM_ICON_SIZE_OFFSET;
    
    for (i=0;i<MMI_AVATAR_ITOM_COUNT_PER_PAGE;i++)
    {
        if (i == avatar_cntx_p->selected_itom_idx && avatar_cntx_p->is_highlighted)
        {
            /* decide Y position */
            offset_y = MMI_AVATAR_BOTTOM_ICON_START_POSITION_Y - MMI_AVATAR_BOTTOM_ICON_SIZE_OFFSET;
            gdi_image_draw_id(offset_x,offset_y,img_large_id+start_idx);
            /* decide next X position */
            offset_x += MMI_AVATAR_BOTTOM_LARGE_ICON_SIZE;
        }
        else
        {
            /* decide Y position */
            offset_y = MMI_AVATAR_BOTTOM_ICON_START_POSITION_Y;
            gdi_image_draw_id(offset_x,offset_y,img_id+start_idx);
            /* decide next X position */
            offset_x += MMI_AVATAR_BOTTOM_ICON_SIZE;
        }    

        start_idx++;
        if (start_idx >= count_of_itom)
            break;
    }

    if (avatar_osd_cntx_p->larrow.is_press == AVATAR_ICON_STATUS_ENABLE)
        gdi_image_draw_id(avatar_osd_cntx_p->larrow.offset_x,avatar_osd_cntx_p->larrow.offset_y,IMG_ID_AVATAR_LARROW_ON);
    else if (avatar_osd_cntx_p->larrow.is_press == AVATAR_ICON_STATUS_CLICKED)
        gdi_image_draw_id(avatar_osd_cntx_p->larrow.offset_x,avatar_osd_cntx_p->larrow.offset_y,IMG_ID_AVATAR_LARROW_SELECTED);


    if (avatar_osd_cntx_p->rarrow.is_press == AVATAR_ICON_STATUS_ENABLE)
        gdi_image_draw_id(avatar_osd_cntx_p->rarrow.offset_x,avatar_osd_cntx_p->rarrow.offset_y,IMG_ID_AVATAR_RARROW_ON);
    else if (avatar_osd_cntx_p->rarrow.is_press == AVATAR_ICON_STATUS_CLICKED)
        gdi_image_draw_id(avatar_osd_cntx_p->rarrow.offset_x,avatar_osd_cntx_p->rarrow.offset_y,IMG_ID_AVATAR_RARROW_SELECTED);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_osd_title
 * DESCRIPTION
 *  draw osd title 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_osd_title(void)
{
    S32 str_width, str_height;
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) GetString(STR_GLOBAL_1), &str_width, &str_height);

    if ( str_width > MMI_AVATAR_TITLE_WIDTH )
    {
        gui_create_scrolling_text(
            &avatar_cntx_p->scrolling_text,
            MMI_AVATAR_TITLE_OFFSET_X,
            MMI_AVATAR_TITLE_OFFSET_Y,
            MMI_AVATAR_TITLE_WIDTH,
            MMI_AVATAR_TITLE_HEIGHT,
            (UI_string_type) GetString(STR_GLOBAL_1+avatar_cntx_p->selected_animation),
            mmi_avatar_draw_hilight_menuitem_timer_callback,
            mmi_avatar_strolling_text_redraw_bg,
            gui_color(67,87,153),
            gui_color(255, 255, 255));

        avatar_cntx_p->scrolling_text.flags |=UI_SCROLLING_TEXT_BORDERED_TEXT;
        gui_show_scrolling_text(&avatar_cntx_p->scrolling_text);
        avatar_cntx_p->is_scrolling_title = TRUE;
    }
    else
    {
        S32 offset_x ;
        gdi_draw_solid_rect(MMI_AVATAR_TITLE_OFFSET_X,
                            MMI_AVATAR_TITLE_OFFSET_Y,
                            MMI_AVATAR_TITLE_WIDTH,
                            MMI_AVATAR_TITLE_HEIGHT,
                            GDI_COLOR_TRANSPARENT);


        offset_x = (MMI_AVATAR_TITLE_WIDTH - str_width)>>1;

        mmi_avatar_draw_style_text(
            GetString(STR_GLOBAL_1+avatar_cntx_p->selected_animation),
            MMI_AVATAR_TITLE_OFFSET_X+offset_x,
            MMI_AVATAR_TITLE_OFFSET_Y);
               
    }
}


/***************************************************************
*  Avatar editing or misc functions
****************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of avatar applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_avatar_del_scr_callback(void* ptr)
{
    mmi_avatar_free_app_mem();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_free_app_mem
 * DESCRIPTION
 *  Free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_free_app_mem(void)
{
    applib_mem_ap_free((void*)avatar_cntx_p->app_mem_pool);
    avatar_cntx_p->app_mem_pool = NULL;    

    if (avatar_cntx_p->drawing_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        return;
    }
    
    gdi_layer_free(avatar_cntx_p->drawing_layer_handle);
    avatar_cntx_p->drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_app_mem_stop_callback
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_app_mem_stop_callback(void)
{
    /* Free Memory */
    mmi_avatar_free_app_mem();

    ASSERT(avatar_cntx_p->app_mem_pool != NULL);

    /* free app-based memory */
    applib_mem_ap_free((void*)avatar_cntx_p->app_mem_pool);
    avatar_cntx_p->app_mem_pool = NULL;    

    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_AVATAR,KAL_TRUE);
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_app_mem_success_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->app_mem_pool 
        = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AVATAR, MMI_AVATAR_APP_MEMORY_SIZE);
    ASSERT(avatar_cntx_p->app_mem_pool!=NULL); /* It should provide enough memory */
    mmi_avatar_entry_editor_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_save_avatar_setting
 * DESCRIPTION
 *  save avatar setting from meta file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mmi_avatar_save_avatar_setting(mmi_avatar_avatar_struct* avatar_list_p,U32 avatar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    U32 written;
    S8 UCS2_buffer[FMGR_PATH_BUFFER_SIZE*2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.atr",avatar_cntx_p->meta_manager.meta_header[avatar_id].serial_number);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);
    file_handle = FS_Open((U16*) UCS2_buffer, FS_CREATE | FS_READ_WRITE);

    if (file_handle > 0)
    {
        FS_Write(file_handle, 
                    (void*)avatar_list_p,
                    sizeof(mmi_avatar_avatar_struct) , 
                    (U32*) & written);
        FS_Close(file_handle);
        return 0;
    }
    else 
    {
        return -1;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_load_avatar_setting
 * DESCRIPTION
 *  load avatar setting from meta file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mmi_avatar_load_avatar_setting(mmi_avatar_avatar_struct* avatar_list_p,U32 avatar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    U32 written;
    S8 UCS2_buffer[FMGR_PATH_BUFFER_SIZE*2];
    S32 serial_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    serial_number = avatar_cntx_p->meta_manager.meta_header[avatar_id].serial_number;

    sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.atr",serial_number);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

    file_handle = FS_Open((U16*) UCS2_buffer, FS_CREATE | FS_READ_WRITE);

    if (file_handle > 0)
    {
        FS_Read(file_handle, 
                    (void*)avatar_list_p,
                    sizeof(mmi_avatar_avatar_struct) , 
                    (U32*) & written);
        FS_Close(file_handle);
        return 0;
    }
    else
    {    
        return -1;
    }
}


static void mmi_avatar_load_avatar_default_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].image_type = GDI_IMAGE_TYPE_AVATAR;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number = 0;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].resourceid = IMG_ID_AVATAR_M3D_EDITOR_ANIMATION;

#ifndef __MMI_TOUCH_SCREEN__
    avatar_cntx_p->is_editor_phase1 = TRUE;
#endif
    avatar_cntx_p->editor_m3d.image_type = GDI_IMAGE_TYPE_AVATAR;
    avatar_cntx_p->editor_m3d.serial_number = 0;
    avatar_cntx_p->editor_m3d.resourceid = IMG_ID_AVATAR_M3D_EDITOR_ANIMATION;

    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_animation = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_eye = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_brow = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_lip = 0;
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_decoration = 0;

    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y = 0;    

    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip = 0;    
    avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration = 0;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_apply_change
 * DESCRIPTION
 *  apply change on avater
 * PARAMETERS
 *  old item idx     [IN]        
 *  new item idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_apply_change(S16 old_itom_idx, S16 new_itom_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	st_m3d_node *node;
    st_m3d_node *node2;
    st_m3d_group *parent;
    float tx,ty,tz;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_HEAD:     
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,201+old_itom_idx);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)avatar_cntx_p->m3d_world_head,201+new_itom_idx);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
                    2);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];

        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);

        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)avatar_cntx_p->m3d_world_head,node);
        M3D_Group_removeChild((st_m3d_group*)avatar_cntx_p->m3d_world_head,node2);
        M3D_Group_addChild(parent,node2);

        mmi_avatar_apply_facial_texture_change();

        break;
        case AVATAR_TOUCH_HAIR:     
        /* do the change thing */
        /* switch head mesh */
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,101+old_itom_idx);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)avatar_cntx_p->m3d_world_hair,101+new_itom_idx);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
            1);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)avatar_cntx_p->m3d_world_hair,node);
        M3D_Group_removeChild((st_m3d_group*)avatar_cntx_p->m3d_world_hair,node2);
        M3D_Group_addChild(parent,node2);

        /* change HAIR only, can return from here */
        return;

        break;
        case AVATAR_TOUCH_BODY:     

        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,301+old_itom_idx);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)avatar_cntx_p->m3d_world_body,301+new_itom_idx);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
                    3);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)avatar_cntx_p->m3d_world_body,node);
        M3D_Group_removeChild((st_m3d_group*)avatar_cntx_p->m3d_world_body,node2);
        M3D_Group_addChild(parent,node2);

        mmi_avatar_apply_body_texture_change();
    
        break;
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_apply_facial_texture_change
 * DESCRIPTION
 *  apply new facial texture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_apply_facial_texture_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	st_m3d_node *node;
    st_m3d_appearance* app;
    st_m3d_texture2d* t2d;
    st_m3d_image2d * i2d;

    GDI_RESULT gdi_ret;

    U16 eyeid,lipid,faceid,browid,decorationid,headid;
    S16 sl_eye, sl_lip, sl_brow, sl_decoration;
    S32 offset_x, offset_y, resized_width, resized_height, img_width, img_height;

    PU8 src;
    PU8 dest;
    U16 src_width, src_height, src_pitch;
    S32 src_offset_x, src_offset_y;
    S32 dest_pitch, dest_offset_x, dest_offset_y;
    gdi_rect_struct dest_clip;

    gdi_handle old_abm_src_layer_handle;

    /*----------------------------------------------------- -----------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    eyeid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_eye;
    faceid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face;
    browid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_brow;
    lipid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_lip;
    decorationid =avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_decoration;
    headid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head;

    sl_eye = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye;
    sl_brow = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow;
    sl_lip = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip;
    sl_decoration = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration;

    node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
        201+headid);
    app = M3D_Mesh_getAppearance((st_m3d_mesh *)node,1);
    
    t2d = app->textures[0];
    i2d = t2d->image;
    /* set ABM source layer handle */
    old_abm_src_layer_handle = gdi_image_abm_set_source_layer(avatar_cntx_p->image_buffer_handle);

    gdi_layer_push_and_set_active(avatar_cntx_p->image_buffer_handle);

    gdi_ret = gdi_image_draw_id(0,0,IMG_ID_AVATAR_M_FACE_1 + faceid);

    gdi_layer_set_clip(0,0,127,127);

    {
        U16 sid;
        sid = IMG_ID_AVATAR_M_L_BROWS_1_3 + sl_brow;
        gdi_ret = gdi_image_draw_id(MMI_AVATAR_L_BROW_OFFSET_X+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x*5,MMI_AVATAR_L_BROW_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y*5,sid + browid*5);
        sid = IMG_ID_AVATAR_M_R_BROWS_1_3 + sl_brow;
        gdi_ret = gdi_image_draw_id(MMI_AVATAR_R_BROW_OFFSET_X-avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x*5,MMI_AVATAR_R_BROW_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y*5,sid + browid*5);
    }

    {
        U16 eid;
        eid = IMG_ID_AVATAR_M_L_EYE_1_3 + sl_eye;
        gdi_ret = gdi_image_draw_id(MMI_AVATAR_L_EYE_OFFSET_X+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x*5,MMI_AVATAR_L_EYE_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y*5,eid + eyeid*5);
        eid = IMG_ID_AVATAR_M_R_EYE_1_3 + sl_eye;
        gdi_ret = gdi_image_draw_id(MMI_AVATAR_R_EYE_OFFSET_X-avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x*5,MMI_AVATAR_R_EYE_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y*5,eid + eyeid*5);
    }


    {
        U16 lid;        
        lid = IMG_ID_AVATAR_M_LIP_1_3 + sl_lip;
        gdi_ret = gdi_image_draw_id(MMI_AVATAR_LIP_OFFSET_X,MMI_AVATAR_LIP_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y*5,lid + lipid*5);

    }

    if (decorationid>0)
    {
        if (sl_decoration == 0)    
            gdi_ret = gdi_image_draw_id(MMI_AVATAR_DECORATION_OFFSET_X,MMI_AVATAR_DECORATION_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y*5,IMG_ID_AVATAR_M_DECORATION_1 + decorationid);
        else
        {
            gdi_image_get_dimension_id(IMG_ID_AVATAR_M_DECORATION_1+decorationid,&img_width,&img_height);
            resized_width = (img_width * (10+sl_decoration))/10;
            resized_height = (img_height * (10+sl_decoration))/10;
            offset_x = (img_width - resized_width)/2;
            offset_y = (img_height - resized_height)/2;
            gdi_ret = gdi_image_draw_resized_id(
                offset_x + MMI_AVATAR_DECORATION_OFFSET_X,
                offset_y + MMI_AVATAR_DECORATION_OFFSET_Y+avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y*5,
                resized_width,
                resized_height,
                IMG_ID_AVATAR_M_DECORATION_1 + decorationid);        
        }
    }

    dest = i2d->pixels;
    src = avatar_cntx_p->image_buffer_ptr;

    src_pitch = 128;
    dest_pitch = 128;
    dest_clip.x1 = 0;
    dest_clip.y1 = 0;
    dest_clip.x2 = 127;
    dest_clip.y2 = 127;
    src_offset_x = 0;
    src_offset_y = 0;
    src_width = 128;
    src_height = 128;
    dest_offset_y = 0;
    dest_offset_x = 0;

    gdi_2d_memory_blt(
        src,
        src_pitch,
        src_offset_x,
        src_offset_y,
        src_width,
        src_height,
        dest,
        dest_pitch,
        dest_offset_x,
        dest_offset_y,
        dest_clip,
        GDI_MAINLCD_BIT_PER_PIXEL);            

    /* restore old ABM source layer handle */
    gdi_image_abm_set_source_layer(old_abm_src_layer_handle);

    gdi_layer_pop_and_restore_active();  


    

    /* IMPORTANT!, must call _m3d_Graphics3D_release_texobj to let DRV free cache of image buffer */
    _m3d_Graphics3D_release_texobj(i2d);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_apply_body_texture_change
 * DESCRIPTION
 *  apply new body texture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_apply_body_texture_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   	st_m3d_node *node;
    st_m3d_appearance* app;
    st_m3d_texture2d* t2d;
    st_m3d_image2d * i2d;

    GDI_RESULT gdi_ret;
    PU8 src;
    PU8 dest;
    U16 src_width, src_height, src_pitch;
    S32 src_offset_x, src_offset_y;
    S32 dest_pitch, dest_offset_x, dest_offset_y;
    gdi_rect_struct dest_clip;

    U16 dressid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dressid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress;

    node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
        401);
    app = M3D_Mesh_getAppearance((st_m3d_mesh *)node,0);
    t2d = app->textures[0];
    i2d = t2d->image;

            
    gdi_layer_push_and_set_active(avatar_cntx_p->image_buffer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_ret = gdi_image_draw_id(0,0,IMG_ID_AVATAR_M_DRESS_1 + dressid);
    gdi_layer_pop_and_restore_active();

    dest = i2d->pixels;
    src = avatar_cntx_p->image_buffer_ptr;

    src_pitch = 128;
    dest_pitch = 64;
    dest_clip.x1 = 0;
    dest_clip.y1 = 0;
    dest_clip.x2 = 63;
    dest_clip.y2 = 63;
    src_offset_x = 0;
    src_offset_y = 0;
    src_width = 64;
    src_height = 64;
    dest_offset_y = 0;
    dest_offset_x = 0;

    gdi_2d_memory_blt(
        src,
        src_pitch,
        src_offset_x,
        src_offset_y,
        src_width,
        src_height,
        dest,
        dest_pitch,
        dest_offset_x,
        dest_offset_y,
        dest_clip,
        GDI_MAINLCD_BIT_PER_PIXEL);            
   

    /* IMPORTANT!, must call _m3d_Graphics3D_release_texobj to let DRV free cache of image buffer */
    _m3d_Graphics3D_release_texobj(i2d);
        

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_apply_setting_to_avatar
 * DESCRIPTION
 *  apply all setting on avatar 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_apply_setting_to_avatar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 headid,hairid,bodyid,dressid;
    float tx,ty,tz;
   	st_m3d_node *node;
    st_m3d_node *node2;
    st_m3d_group *parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dressid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress;
    headid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head;
    hairid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair;
    bodyid = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body;
    
    /* Head */
    if (headid != 0)
    {
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,201);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)avatar_cntx_p->m3d_world_head,201+headid);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
                    2);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)avatar_cntx_p->m3d_world_head,node);
        M3D_Group_removeChild((st_m3d_group*)avatar_cntx_p->m3d_world_head,node2);
        M3D_Group_addChild(parent,node2);
    }

    /* Hair */
    if (hairid != 0)
    {
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,101);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)avatar_cntx_p->m3d_world_hair,101+hairid);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
            1);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)avatar_cntx_p->m3d_world_hair,node);
        M3D_Group_removeChild((st_m3d_group*)avatar_cntx_p->m3d_world_hair,node2);
        M3D_Group_addChild(parent,node2);
    }

    /* Body */
    if (bodyid != 0)
    {
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,301);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)avatar_cntx_p->m3d_world_body,301+bodyid);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
            3);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)avatar_cntx_p->m3d_world_body,node);
        M3D_Group_removeChild((st_m3d_group*)avatar_cntx_p->m3d_world_body,node2);
        M3D_Group_addChild(parent,node2);
    }

    /* dress */
    {
        mmi_avatar_apply_body_texture_change();
    }
   
    mmi_avatar_apply_facial_texture_change();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_load_meta_manager
 * DESCRIPTION
 *  load meta manager from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_load_meta_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    ReadRecord(
        NVRAM_EF_AVATAR_SETTING_LID,
        1,
        (void*)&avatar_cntx_p->meta_manager,
        NVRAM_EF_AVATAR_SETTING_SIZE,
        &error);

    /* first time init */
    //avatar_cntx_p->meta_manager.total_count= 0xffffffff;
    if (avatar_cntx_p->meta_manager.total_count == 0xffffffff)
    {
        mmi_avatar_restore_meta_manager();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_save_meta_manager
 * DESCRIPTION
 *  save metamanager to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_save_meta_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
    NVRAM_EF_AVATAR_SETTING_LID,
    1,
    (void*)&(avatar_cntx_p->meta_manager),
    NVRAM_EF_AVATAR_SETTING_SIZE,
    &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_restore_meta_manager
 * DESCRIPTION
 *  restore avatar setting to default value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_restore_meta_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->meta_manager.total_count = 0;
    avatar_cntx_p->meta_manager.head = 0;
    avatar_cntx_p->meta_manager.tail = 0;
    avatar_cntx_p->meta_manager.serial_number = 0;
    avatar_cntx_p->meta_manager.delete_all = FALSE;
    memset(avatar_cntx_p->meta_manager.meta_header,0xff,MMI_AVATAR_COUNT*sizeof(mmi_avatar_meta_header_struct));

    for (i=0;i<MMI_AVATAR_COUNT;i++)
    {
        avatar_cntx_p->meta_manager.meta_header[i].is_slot_free = TRUE;
    }

    avatar_cntx_p->meta_manager.wp.is_slot_free = TRUE;
    avatar_cntx_p->meta_manager.ss.is_slot_free = TRUE;
    avatar_cntx_p->meta_manager.pwron.is_slot_free = TRUE;
    avatar_cntx_p->meta_manager.pwroff.is_slot_free = TRUE;

    mmi_avatar_save_meta_manager();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_load_avatar_list
 * DESCRIPTION
 *  load avatar list from file according to meta_manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_load_avatar_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i,head_idx;
    S16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    head_idx = avatar_cntx_p->meta_manager.head;

    for (i=0;i<avatar_cntx_p->meta_manager.total_count;i++)
    {

        ret = mmi_avatar_load_avatar_setting(&(avatar_cntx_p->avatar_list[head_idx]), head_idx);
        if (ret <0)
        {
            mmi_avatar_display_error_popup(ret);
            return;
        }       

        head_idx = avatar_cntx_p->meta_manager.meta_header[head_idx].next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_saving_timeout
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_saving_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), 
                        IMG_GLOBAL_ACTIVATED, 
                        1, 
                        ST_NOTIFYDURATION, 
                        0 
                        );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_saving_timeout_by_option_menu
 * DESCRIPTION
 *  functions to ooxx
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_saving_timeout_by_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), 
                        IMG_GLOBAL_ACTIVATED, 
                        1, 
                        ST_NOTIFYDURATION, 
                        0 
                        );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_rename_avatar
 * DESCRIPTION
 *  rename avatar and save to avatar_list and meta file
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_rename_avatar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8)avatar_cntx_p->avatar_name)<=0)
    {
        DisplayPopup((PU8) GetString(STR_ID_AVATAR_EMPTY_AVATAR_NAME),
                    IMG_GLOBAL_ERROR, 
                    1, 
                    ST_NOTIFYDURATION, 
                    ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_AVATAR_EDITING_NAME_OPTION);
        return;
    }

    mmi_ucs2cpy((PS8)avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].filename, (PS8)avatar_cntx_p->avatar_name);

    mmi_avatar_save_avatar_setting(&(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]),avatar_cntx_p->selected_avatar_id);

    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_SAVING), 
                        IMG_GLOBAL_SAVE, 
                        1, 
                        ST_NOTIFYDURATION, 
                        0, 
                        mmi_avatar_saving_timeout);
    DeleteUptoScrID(SCR_ID_AVATAR_OPTION_MENU);
    DeleteNHistory(1);

    avatar_cntx_p->state = AVATAR_STATE_SAVING;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_save_new_avatar
 * DESCRIPTION
 *  save new avatar (including save meta file and meta manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_save_new_avatar(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i,head_idx;
    S16 ret; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8)avatar_cntx_p->avatar_name)<=0)
    {
        DisplayPopup((PU8) GetString(STR_ID_AVATAR_EMPTY_AVATAR_NAME),
                    IMG_GLOBAL_ERROR, 
                    1, 
                    ST_NOTIFYDURATION, 
                    ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_AVATAR_EDITING_NAME_OPTION);
        return;
    }
    avatar_cntx_p->meta_manager.serial_number++;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].image_type = GDI_IMAGE_TYPE_AVATAR;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].is_slot_free = FALSE;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].resourceid = IMG_ID_AVATAR_M3D_ANIMATION_1;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number = avatar_cntx_p->meta_manager.serial_number;
    avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].idx = avatar_cntx_p->selected_avatar_id;

    mmi_ucs2cpy((PS8)avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].filename,(PS8) avatar_cntx_p->avatar_name);

    head_idx = avatar_cntx_p->meta_manager.head;

    /* find the last slot */
    for (i=0;i<avatar_cntx_p->meta_manager.total_count;i++)
    {
        if (avatar_cntx_p->meta_manager.meta_header[head_idx].next==(S16)0xffff)
        {
            /* the last is found */     
            avatar_cntx_p->meta_manager.meta_header[head_idx].next = avatar_cntx_p->selected_avatar_id;
            avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].prev = head_idx;
            avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].next = (S16)0xffff;
            break;
        }       
        else
        {
            /* find next */
            head_idx = avatar_cntx_p->meta_manager.meta_header[head_idx].next;
        }
    }
    avatar_cntx_p->meta_manager.total_count++;

    mmi_avatar_encode_jpeg();


    ret = mmi_avatar_save_avatar_setting(&(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]),avatar_cntx_p->selected_avatar_id);

    if ( ret >= 0)
    {
        mmi_avatar_save_meta_manager();
    }
    else
    {
        mmi_avatar_display_error_popup(ret);
        return;
    }

    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_SAVING), 
                        IMG_GLOBAL_SAVE, 
                        1, 
                        ST_NOTIFYDURATION, 
                        0, 
                        mmi_avatar_saving_timeout);

    DeleteUptoScrID(SCR_ID_AVATAR_OPTION_MENU);
    DeleteNHistory(1);


    avatar_cntx_p->state = AVATAR_STATE_SAVING_NEW;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_encode_jpeg
 * DESCRIPTION
 *  encode current avatar into a jpeg file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_encode_jpeg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    GDI_RESULT ret;
    S8 UCS2_buffer[FMGR_PATH_BUFFER_SIZE*2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.jpg",avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

    ret = gdi_image_encode_layer_to_jpeg (avatar_cntx_p->drawing_layer_handle,UCS2_buffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_delete_avatar
 * DESCRIPTION
 *  confirm if delete or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_delete_all_avatar_confirm(void)
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
    get_string(STR_GLOBAL_DELETE_ALL),
    IMG_GLOBAL_QUESTION,
    WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_avatar_delete_all_avatar, KEY_EVENT_UP);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_delete_avatar
 * DESCRIPTION
 *  confirm if delete or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_delete_avatar_confirm(void)
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

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_avatar_delete_avatar, KEY_EVENT_UP);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_update_setting_mh
 * DESCRIPTION
 *  update avatar of phone settings 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_update_setting_mh(S16 serial_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_cntx_p->meta_manager.wp.serial_number == serial_number)
        avatar_cntx_p->meta_manager.wp.is_slot_free = TRUE;

    if (avatar_cntx_p->meta_manager.ss.serial_number == serial_number)
        avatar_cntx_p->meta_manager.ss.is_slot_free = TRUE;

    if (avatar_cntx_p->meta_manager.pwron.serial_number == serial_number)
        avatar_cntx_p->meta_manager.pwron.is_slot_free = TRUE;

    if (avatar_cntx_p->meta_manager.pwroff.serial_number == serial_number)
        avatar_cntx_p->meta_manager.pwroff.is_slot_free = TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_delete_avatar
 * DESCRIPTION
 *  delete current highlighted avatar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_delete_avatar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    S8 UCS2_buffer[FMGR_PATH_BUFFER_SIZE*2];
    S16 head_idx;
    S16 prev_idx,next_idx,current_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(avatar_cntx_p->meta_manager.total_count>0);

    /*************************************************
     * Delete avatar_list relate file 
     *************************************************/
    sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.atr",avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

    file_handle = FS_Delete((U16*) UCS2_buffer);

    if (file_handle >= 0)
    {
        /* clear all keys */
        ClearInputEventHandler(MMI_DEVICE_KEY);
        DisplayPopupCallBack((PU8) GetString(STR_ID_AVATAR_DELETING), 
                        IMG_GLOBAL_DELETED, 
                        1, 
                        ST_NOTIFYDURATION, 
                        0, 
                        mmi_avatar_saving_timeout);

        DeleteUptoScrID(SCR_ID_AVATAR_OPTION_MENU);
        DeleteNHistory(1);
    
    }
    else
    {
        mmi_avatar_display_error_popup(file_handle);
        return;
    }

    mmi_avatar_update_setting_mh(avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number);

    /*************************************************
     * Update meta data
     *************************************************/   
    head_idx = avatar_cntx_p->meta_manager.head;
    prev_idx = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].prev;
    next_idx = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].next;
    current_idx = avatar_cntx_p->selected_avatar_id;

    /* if first one */
    if (head_idx == avatar_cntx_p->selected_avatar_id)
    {       
        avatar_cntx_p->meta_manager.head = (avatar_cntx_p->meta_manager.meta_header[head_idx].next==(S16)0xffff)?
                                            0:avatar_cntx_p->meta_manager.meta_header[head_idx].next;
    }
    else
    {
        if ( prev_idx != (S16)0xffff)
            avatar_cntx_p->meta_manager.meta_header[prev_idx].next = next_idx;

        if ( next_idx != (S16)0xffff)
            avatar_cntx_p->meta_manager.meta_header[next_idx].prev = prev_idx;
    }
    
    /* reduce total_count */
    if (avatar_cntx_p->meta_manager.total_count > 0)
    avatar_cntx_p->meta_manager.total_count--;
    
    memset(&(avatar_cntx_p->meta_manager.meta_header[current_idx]),0xff,sizeof(mmi_avatar_meta_header_struct));
    avatar_cntx_p->meta_manager.meta_header[current_idx].is_slot_free = TRUE;

    mmi_avatar_save_meta_manager();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_delete_all_avatar
 * DESCRIPTION
 *  delete current highlighted avatar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_delete_all_avatar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    S8 UCS2_buffer[FMGR_PATH_BUFFER_SIZE*2];
    S16 head_idx,i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(avatar_cntx_p->meta_manager.total_count>0);

    /*************************************************
     * Delete avatar_list relate file 
     *************************************************/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    avatar_cntx_p->meta_manager.delete_all = TRUE;
    mmi_avatar_save_meta_manager();

    /* TO DO: DELETE ALL *.ATR */
    head_idx = avatar_cntx_p->meta_manager.head;
    for (i=0;i<avatar_cntx_p->meta_manager.total_count;i++)
    {
        sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.atr",avatar_cntx_p->meta_manager.meta_header[head_idx].serial_number);
        mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

        file_handle = FS_Delete((U16*) UCS2_buffer);

        if (avatar_cntx_p->meta_manager.meta_header[head_idx].next==(S16)0xffff)
        {
            /* the last is found */     
            break;
        }       
        else
        {
            /* find next */
            head_idx = avatar_cntx_p->meta_manager.meta_header[head_idx].next;
        }
    }

    if (i == avatar_cntx_p->meta_manager.total_count - 1)
    {
        DisplayPopupCallBack((PU8) GetString(STR_ID_AVATAR_DELETING), 
                        IMG_GLOBAL_DELETED, 
                        1, 
                        ST_NOTIFYDURATION, 
                        0, 
                        mmi_avatar_saving_timeout);
    }
    else
    {
        mmi_avatar_display_error_popup(0);
        return;
    }

    /*************************************************
     * RESET meta data
     *************************************************/   
    mmi_avatar_restore_meta_manager();

    avatar_cntx_p->meta_manager.delete_all = FALSE;
    mmi_avatar_save_meta_manager();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_display_error_popup
 * DESCRIPTION
 *  display error popup
 * PARAMETERS
 *  err_code     [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_display_error_popup(U16 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err_code == FS_DISK_FULL)
    {
    }
    else if (err_code == FS_ROOT_DIR_FULL)
    {
    }
    else if (err_code == FS_WRITE_PROTECTION)
    {
    }
    else
    {

    }

    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_ERROR),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_set_caller_picture
 * DESCRIPTION
 *  set caller picture function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_set_caller_picture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[50];
    S8 UCS2_buffer[100];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((PS8) buffer, "Z:\\@avatar\\%d.jpg",avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);
    avatar_cntx_p->app_callback_ptr((U32)UCS2_buffer,avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number);
    DeleteScreenIfPresent(SCR_ID_AVATAR_LIST_MENU);
    DeleteScreenIfPresent(SCR_ID_AVATAR_SELECT_ANIMATION);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_set_animation
 * DESCRIPTION
 *  set animation callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_set_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 callback_ptr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;
    avatar_cntx_p->lsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    else        
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

    mmi_avatar_save_avatar_setting(&(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]),avatar_cntx_p->selected_avatar_id);

    switch (avatar_cntx_p->app_type)
    {
        case MMI_AVATAR_APP_CALLER_VIDEO:
            avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].resourceid = IMG_ID_AVATAR_M3D_ANIMATION_1+avatar_cntx_p->selected_animation;
            callback_ptr = (U32) &(avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id]);
            break;
        case MMI_AVATAR_APP_WALLPAPER:
            avatar_cntx_p->meta_manager.wp.image_type = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].image_type;
            avatar_cntx_p->meta_manager.wp.size = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].size;
            avatar_cntx_p->meta_manager.wp.resourceid= IMG_ID_AVATAR_M3D_ANIMATION_1+avatar_cntx_p->selected_animation;
            avatar_cntx_p->meta_manager.wp.serial_number = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number;
            avatar_cntx_p->meta_manager.wp.idx = avatar_cntx_p->selected_avatar_id;
            avatar_cntx_p->meta_manager.wp.is_slot_free = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].is_slot_free ;
            callback_ptr = (U32) &(avatar_cntx_p->meta_manager.wp);
            break;
        case MMI_AVATAR_APP_SCREENSAVER:
            avatar_cntx_p->meta_manager.ss.image_type = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].image_type;
            avatar_cntx_p->meta_manager.ss.size = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].size;
            avatar_cntx_p->meta_manager.ss.resourceid= IMG_ID_AVATAR_M3D_ANIMATION_1+avatar_cntx_p->selected_animation;
            avatar_cntx_p->meta_manager.ss.serial_number = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number;
            avatar_cntx_p->meta_manager.ss.idx = avatar_cntx_p->selected_avatar_id;
            avatar_cntx_p->meta_manager.ss.is_slot_free = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].is_slot_free;
            callback_ptr = (U32) &(avatar_cntx_p->meta_manager.ss);
            break;
        case MMI_AVATAR_APP_POWERON_ANIMATION:
            avatar_cntx_p->meta_manager.pwron.image_type = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].image_type;
            avatar_cntx_p->meta_manager.pwron.size = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].size;
            avatar_cntx_p->meta_manager.pwron.resourceid= IMG_ID_AVATAR_M3D_ANIMATION_1+avatar_cntx_p->selected_animation;
            avatar_cntx_p->meta_manager.pwron.serial_number = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number;
            avatar_cntx_p->meta_manager.pwron.idx = avatar_cntx_p->selected_avatar_id;
            avatar_cntx_p->meta_manager.pwron.is_slot_free = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].is_slot_free;
            callback_ptr = (U32) &(avatar_cntx_p->meta_manager.pwron);
            break;
        case MMI_AVATAR_APP_POWEROFF_ANIMATION:
            avatar_cntx_p->meta_manager.pwroff.image_type = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].image_type;
            avatar_cntx_p->meta_manager.pwroff.size = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].size;
            avatar_cntx_p->meta_manager.pwroff.resourceid= IMG_ID_AVATAR_M3D_ANIMATION_1+avatar_cntx_p->selected_animation;
            avatar_cntx_p->meta_manager.pwroff.serial_number = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number;
            avatar_cntx_p->meta_manager.pwroff.idx = avatar_cntx_p->selected_avatar_id;
            avatar_cntx_p->meta_manager.pwroff.is_slot_free = avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].is_slot_free;
            callback_ptr = (U32) &(avatar_cntx_p->meta_manager.pwroff);
            break;
        case MMI_AVATAR_APP_EDITOR:
        case MMI_AVATAR_APP_CALLER_PICTURE:
            ASSERT(0);
            break;
        default:
            break;
    }
    mmi_avatar_save_meta_manager();

    avatar_cntx_p->app_callback_ptr(callback_ptr,avatar_cntx_p->meta_manager.meta_header[avatar_cntx_p->selected_avatar_id].serial_number);
    DeleteScreenIfPresent(SCR_ID_AVATAR_LIST_MENU);
    DeleteScreenIfPresent(SCR_ID_AVATAR_SELECT_ANIMATION);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_show_thumb_image
 * DESCRIPTION
 *  show thumb image
 * PARAMETERS
 *  item_idx                [IN]        Item index
 *  menuitem_offset_x       [IN]        Menu item's offset x
 *  menuitem_offset_y       [IN]        Menu item's offset y
 *  box_offset_x            [IN]        Image box offset x
 *  box_offset_y            [IN]        Image box offset y
 *  box_width               [IN]        Image box width
 *  box_height              [IN]        Image box height
 *  icon_ptr                [IN]        Icon's image ptr
 *  is_hilighted            [IN]        Is highlight flag
 *  ui_style                [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_avatar_show_thumb_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_image_in_cache;
    S32 icon_offset_x, icon_offset_y;
    S32 icon_width, icon_height;
    S32 cache_index;
    S32 draw_pos_x, draw_pos_y;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    gdi_image_get_dimension((PU8) icon_ptr, &icon_width, &icon_height);

    icon_offset_x = ((box_width - icon_width) >> 1) + menuitem_offset_x + box_offset_x;
    icon_offset_y = ((box_height - icon_height) >> 1) + menuitem_offset_y + box_offset_y;

    box_offset_x += menuitem_offset_x;
    box_offset_y += menuitem_offset_y;


    /* test if is in the cache */
    is_image_in_cache = FALSE;

    for (cache_index = 0; cache_index < avatar_image_cache_p->image_cache_item_count; cache_index++)
    {
        if ((avatar_image_cache_p->image_cache_list[cache_index]->is_used == TRUE) &&
            (avatar_image_cache_p->image_cache_list[cache_index]->menuitem_idx == item_idx))
        {
            is_image_in_cache = TRUE;
            break;
        }
    }

    /* if can find image in cache, draw it from cache */
    if (is_image_in_cache == TRUE)
    {
        {
            draw_pos_x = box_offset_x + avatar_image_cache_p->image_cache_list[cache_index]->resized_offset_x + 1;
            draw_pos_y = box_offset_y + avatar_image_cache_p->image_cache_list[cache_index]->resized_offset_y + 1;

            /* draw frame */
            gdi_draw_rect(
                draw_pos_x - 1,
                draw_pos_y - 1,
                draw_pos_x + avatar_image_cache_p->image_cache_list[cache_index]->resized_width,
                draw_pos_y + avatar_image_cache_p->image_cache_list[cache_index]->resized_height,
                GDI_COLOR_BLACK);

            gdi_image_cache_bmp_draw(draw_pos_x, draw_pos_y, &avatar_image_cache_p->image_cache_list[cache_index]->bmp);
        }

        /* make other unused duration increase one */
        for (i = 0; i < avatar_image_cache_p->image_cache_item_count; i++)
        {
            avatar_image_cache_p->image_cache_list[i]->unused_duration++;
        }

        avatar_image_cache_p->image_cache_list[cache_index]->unused_duration = 0;

    }
    else
    {
        /* not in cache */
        gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);


        /* Start of Marco for switch case */
#define AVATAR_DELAY_DECODER_SWITCH(_idx_)                                                                    \
         case _idx_:                                                                                              \
         {                                                                                                        \
            StartTimer(AVATAR_DELAY_DECODE_##_idx_, AVATAR_UI_DELAY_DECODE_DURATION, mmi_avatar_delay_decode_##_idx_##);\
            avatar_delay_decoder_p[##_idx_##].item_idx            = item_idx;                               \
            avatar_delay_decoder_p[##_idx_##].menuitem_offset_x   = menuitem_offset_x;                      \
            avatar_delay_decoder_p[##_idx_##].menuitem_offset_y   = menuitem_offset_y;                      \
            avatar_delay_decoder_p[##_idx_##].box_offset_x        = box_offset_x;                           \
            avatar_delay_decoder_p[##_idx_##].box_offset_y        = box_offset_y;                           \
            avatar_delay_decoder_p[##_idx_##].box_width           = box_width;                              \
            avatar_delay_decoder_p[##_idx_##].box_height          = box_height;                             \
            avatar_delay_decoder_p[##_idx_##].icon_offset_x       = icon_offset_x;                          \
            avatar_delay_decoder_p[##_idx_##].icon_offset_y       = icon_offset_y;                          \
            avatar_delay_decoder_p[##_idx_##].icon_width          = icon_width;                             \
            avatar_delay_decoder_p[##_idx_##].icon_height         = icon_height;                            \
            avatar_delay_decoder_p[##_idx_##].icon_ptr            = icon_ptr;                               \
            avatar_delay_decoder_p[##_idx_##].is_hilighted        = is_hilighted;                           \
            avatar_delay_decoder_p[##_idx_##].ui_style            = 0;                               \
            break;                                                                                                \
         }
        /* end of Macro */

        /* start delay decode timer */
        switch (avatar_cntx_p->delay_decode_index)
        {
                AVATAR_DELAY_DECODER_SWITCH(0);
                AVATAR_DELAY_DECODER_SWITCH(1);
                AVATAR_DELAY_DECODER_SWITCH(2);
                AVATAR_DELAY_DECODER_SWITCH(3);
                AVATAR_DELAY_DECODER_SWITCH(4);
                AVATAR_DELAY_DECODER_SWITCH(5);
                AVATAR_DELAY_DECODER_SWITCH(6);
                AVATAR_DELAY_DECODER_SWITCH(7);
                AVATAR_DELAY_DECODER_SWITCH(8);
                AVATAR_DELAY_DECODER_SWITCH(9);
            default:
                MMI_ASSERT(0);
        }

        avatar_cntx_p->delay_decode_index++;

    }

    gui_pop_clip();


    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_hilight_menuitem_bg_callback
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_draw_filled_area(
        GUI_current_fixed_icontext_menuitem_x,
        GUI_current_fixed_icontext_menuitem_y,
        x2,
        y2,
        MMI_fixed_icontext_menuitem.selected_filler);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_draw_hilight_menuitem_timer_callback
 * DESCRIPTION
 *  draw hilight menuitem text, callback function for scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_draw_hilight_menuitem_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&avatar_cntx_p->scrolling_text);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_strolling_text_redraw_bg
 * DESCRIPTION
 *  draw hilight menuitem text, callback function for scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_avatar_strolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/***************************************************************
*  Avatar Editor key or touch related functions
****************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_touch_scr_hit_test
 * DESCRIPTION
 *  test touch screen icon
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_avatar_touch_scr_hit_test(S32 pos_x, S32 pos_y, avatar_osd_icon_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_pen_down_hdlr
 * DESCRIPTION
 *  avatar pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_idx = 0,count_of_itom = 0,current_page = 0;
    S16 i;
    S16 *add_itom = 0;
    S32 offset_x,offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->is_pen_down = TRUE;
    avatar_cntx_p->pen_down_x = pos.x;
    avatar_cntx_p->pen_down_y = pos.y;

    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;

    /* LSK */
    if (mmi_avatar_touch_scr_hit_test(pos.x, pos.y, &(avatar_cntx_p->lsk)) == MMI_TRUE)
    {
        /* if in display state there is no lsk */
        if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING )
        {
            avatar_cntx_p->is_pen_down = FALSE;
            return;
        }
        
        mmi_avatar_lsk_press();
        return;
    }

    /* RSK */
    if (mmi_avatar_touch_scr_hit_test(pos.x, pos.y, &(avatar_cntx_p->rsk)) == MMI_TRUE)
    {
        mmi_avatar_rsk_press();
        return;
    }

    /* osd test */
#define ICON_TOUCH_TEST(a,A)\
    do {\
        if(avatar_osd_cntx_p->##a##.is_press==AVATAR_ICON_STATUS_ENABLE)\
        {\
            if(mmi_avatar_touch_scr_hit_test(pos.x, pos.y, &(avatar_osd_cntx_p->##a##)) == MMI_TRUE)\
            {\
                mmi_avatar_##a##_icon_press();\
                avatar_cntx_p->touch_object = AVATAR_TOUCH_##A;\
                return;\
            }\
        }\
    } while(0)


    if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING || avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
    {
        ICON_TOUCH_TEST(top_larrow,TOP_LARROW);
        ICON_TOUCH_TEST(top_rarrow,TOP_RARROW);
    }
    else
    {
        ICON_TOUCH_TEST(head,HEAD);
        ICON_TOUCH_TEST(hair,HAIR);
        ICON_TOUCH_TEST(eye,EYE);
        ICON_TOUCH_TEST(brow,BROW);
        ICON_TOUCH_TEST(decoration,DECORATION);
        ICON_TOUCH_TEST(lip,LIP);
        ICON_TOUCH_TEST(body,BODY);
        ICON_TOUCH_TEST(stretch,STRETCH);
        ICON_TOUCH_TEST(shrink,SHRINK);
        ICON_TOUCH_TEST(moveup,MOVEUP);
        ICON_TOUCH_TEST(movedown,MOVEDOWN);
        ICON_TOUCH_TEST(magnify,MAGNIFY);
        ICON_TOUCH_TEST(minify,MINIFY);

        ICON_TOUCH_TEST(color,COLOR);
        ICON_TOUCH_TEST(larrow,LARROW);
        ICON_TOUCH_TEST(rarrow,RARROW);
        
    }

        #undef ICON_TOUCH_TEST


    if (avatar_cntx_p->state != AVATAR_STATE_DISPLAYING && avatar_cntx_p->state != AVATAR_STATE_SELECT_ANIMATION)
    {
        switch (avatar_cntx_p->selected_top_object)
        {
            case AVATAR_TOUCH_HEAD:     
                start_idx = (avatar_cntx_p->page_of_head)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_HEAD;
                current_page = avatar_cntx_p->page_of_head;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head); 
            break;
            case AVATAR_TOUCH_HAIR:     
                start_idx = (avatar_cntx_p->page_of_hair)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_HAIR;
                current_page = avatar_cntx_p->page_of_hair;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair); 
                break;
            case AVATAR_TOUCH_LIP:
                start_idx = (avatar_cntx_p->page_of_lip)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_LIP;
                current_page = avatar_cntx_p->page_of_lip;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_lip); 
                break;
            case AVATAR_TOUCH_EYE:     
                start_idx = (avatar_cntx_p->page_of_eye)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_EYE;
                current_page = avatar_cntx_p->page_of_eye;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_eye); 
            break;
            case AVATAR_TOUCH_DECORATION:
                start_idx = (avatar_cntx_p->page_of_decoration)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_DECORATION;
                current_page = avatar_cntx_p->page_of_decoration;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_decoration); 
            break;
            case AVATAR_TOUCH_BODY:     
                start_idx = (avatar_cntx_p->page_of_body)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_BODY;
                current_page = avatar_cntx_p->page_of_body;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body); 
            break;
            case AVATAR_TOUCH_BROW:     
                start_idx = (avatar_cntx_p->page_of_brow)*MMI_AVATAR_ITOM_COUNT_PER_PAGE;
                count_of_itom = MMI_AVATAR_COUNT_OF_BROW;
                current_page = avatar_cntx_p->page_of_brow;
                add_itom = &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_brow); 
            break;
        }

        /* decide Y position */
        offset_y = MMI_AVATAR_BOTTOM_ICON_START_POSITION_Y;

        if (avatar_cntx_p->is_highlighted)
            offset_x = MMI_AVATAR_BOTTOM_ICON_START_POSITION_X - MMI_AVATAR_BOTTOM_ICON_SIZE_OFFSET;
        else 
            offset_x = MMI_AVATAR_BOTTOM_ICON_START_POSITION_X;

        for (i=0;i<MMI_AVATAR_ITOM_COUNT_PER_PAGE;i++)
        {
            if (i == avatar_cntx_p->selected_itom_idx && avatar_cntx_p->is_highlighted)
            {
                offset_x += MMI_AVATAR_BOTTOM_LARGE_ICON_SIZE;
            }
            else
            {
                if (pos.x > offset_x && pos.x < offset_x + MMI_AVATAR_BOTTOM_ICON_SIZE &&
                    pos.y > offset_y && pos.y < offset_y + MMI_AVATAR_BOTTOM_ICON_SIZE)
                {
                    /* HIT!! */
                    S16 old_itom_idx = *add_itom;
                    *add_itom = current_page*MMI_AVATAR_ITOM_COUNT_PER_PAGE + i;

                    avatar_cntx_p->selected_itom_idx = i;
                    avatar_cntx_p->selected_itom_page = current_page;
                    avatar_cntx_p->is_highlighted = TRUE;
                    if (avatar_cntx_p->selected_top_object == AVATAR_TOUCH_HEAD ||
                        avatar_cntx_p->selected_top_object == AVATAR_TOUCH_HAIR ||
                        avatar_cntx_p->selected_top_object == AVATAR_TOUCH_BODY )
                    {   
                        mmi_avatar_apply_change(old_itom_idx,*add_itom);
                    }
                    else
                    {
                        mmi_avatar_apply_facial_texture_change();
                    }
                    
                    mmi_avatar_draw_osd();
                    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
                    return;    
                }
                else
                {
                    /* decide next X position */
                    offset_x += MMI_AVATAR_BOTTOM_ICON_SIZE;
                }
            }    

            start_idx++;
            if (start_idx >= count_of_itom)
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_pen_up_hdlr
 * DESCRIPTION
 *  avatar pen up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->is_pen_down = FALSE;

    switch(avatar_cntx_p->touch_object)
    {
    case AVATAR_TOUCH_HEAD:
        break;
    case AVATAR_TOUCH_HAIR:
        break;
    case AVATAR_TOUCH_EYE:
        break;
    case AVATAR_TOUCH_BROW:
        break;
    case AVATAR_TOUCH_LIP:
        break;
    case AVATAR_TOUCH_DECORATION:
        break;
    case AVATAR_TOUCH_BODY:
        break;
    case AVATAR_TOUCH_TOP_LARROW:
        mmi_avatar_top_larrow_icon_release();
        break;
    case AVATAR_TOUCH_TOP_RARROW:
        mmi_avatar_top_rarrow_icon_release();
        break;
    case AVATAR_TOUCH_COLOR:
        avatar_osd_cntx_p->color.is_press = AVATAR_ICON_STATUS_ENABLE;
        mmi_avatar_draw_osd();
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
        break;
    case AVATAR_TOUCH_MOVEUP:
        mmi_avatar_moveup_icon_release();
        break;
    case AVATAR_TOUCH_MOVEDOWN:
        mmi_avatar_movedown_icon_release();
        break;
    case AVATAR_TOUCH_STRETCH:
        mmi_avatar_stretch_icon_release();
        break;
    case AVATAR_TOUCH_SHRINK:
        mmi_avatar_shrink_icon_release();
        break;
    case AVATAR_TOUCH_MAGNIFY:
        mmi_avatar_magnify_icon_release();
        break;
    case AVATAR_TOUCH_MINIFY:
        mmi_avatar_minify_icon_release();
        break;
    case AVATAR_TOUCH_LARROW:
        if (avatar_osd_cntx_p->larrow.is_press == AVATAR_ICON_STATUS_CLICKED)
        {
            avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_ENABLE;
            mmi_avatar_bottom_icon_page_change(-1);
            mmi_avatar_draw_osd();
            gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);               
        }           
        break;
    case AVATAR_TOUCH_RARROW:
        if (avatar_osd_cntx_p->rarrow.is_press == AVATAR_ICON_STATUS_CLICKED)
        {
            avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_ENABLE;
            mmi_avatar_bottom_icon_page_change(1);
            mmi_avatar_draw_osd();
            gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
        }    
        break;

    case AVATAR_TOUCH_RSK:
        avatar_cntx_p->rsk.is_press = AVATAR_ICON_STATUS_ENABLE;
        mmi_avatar_draw_osd();
        
        if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING || avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
            gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
        else        
            gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

        if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING || avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
            GoBackHistory();
        else
        {
            mmi_avatar_rsk_release();
        }
        break;
    case AVATAR_TOUCH_LSK:
        avatar_cntx_p->lsk.is_press = AVATAR_ICON_STATUS_ENABLE;
        mmi_avatar_draw_osd();

        if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING || avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
            gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
        else        
            gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

        if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        {
            mmi_avatar_set_animation();
        }
        else
            mmi_avatar_lsk_release();
        break;
    default:
        break;
        
    }

    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_pen_move_hdlr
 * DESCRIPTION
 *  avatar pen move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_rarrow_icon_press
 * DESCRIPTION
 *  rarrow icon prssed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_rarrow_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   

}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_larrow_icon_press
 * DESCRIPTION
 *  larrow icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_larrow_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}


static pBOOL mmi_avatar_check_if_modified(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_avatar_avatar_struct tmp_struct;
    S8* src;
    S8* dest;
    pBOOL ret ;
    S16 size = sizeof(mmi_avatar_avatar_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FALSE;

    mmi_avatar_load_avatar_setting(&(tmp_struct),avatar_cntx_p->selected_avatar_id);

    src = (PS8) &(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]);
    dest = (PS8) &tmp_struct;
    while(size-- >0)
    {       
        if (*src++ != *dest++)
        {
            ret = TRUE;
            break;
        }
    }
    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#if 0
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
#endif

#ifndef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  mmi_avtar_lsk_release_enter_option
 * DESCRIPTION
 *  reset and initialize for differenct editor phase
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avtar_lsk_release_enter_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;
    avatar_cntx_p->lsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    else        
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);


    mmi_avatar_entry_editor_option_menu_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_set_editor_phase_setting
 * DESCRIPTION
 *  reset and initialize for differenct editor phase
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_set_editor_phase_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();

    SetKeyHandler(mmi_avatar_head_icon_press, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_hair_icon_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_brow_icon_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_eye_icon_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_lip_icon_press, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_body_icon_press, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_decoration_icon_press, KEY_7, KEY_EVENT_DOWN);    

    if ((avatar_cntx_p->selected_top_object == AVATAR_TOUCH_HAIR) 
        || ((avatar_cntx_p->selected_top_object == AVATAR_TOUCH_DECORATION) && (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_decoration ==0)))   
    {
        avatar_cntx_p->is_editor_phase1 = TRUE;
    }
    else
        SetKeyHandler(mmi_avatar_toggle_editor_phase, KEY_RSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_avtar_lsk_release_enter_option, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_avatar_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_avatar_rsk_press, KEY_RSK, KEY_EVENT_DOWN);


    if (avatar_cntx_p->is_editor_phase1)
    {
        SetKeyHandler(mmi_avatar_select_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_select_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {                
        SetKeyHandler(mmi_avatar_stretch_icon_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_shrink_icon_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_moveup_icon_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_movedown_icon_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_magnify_icon_press, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_minify_icon_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_avatar_color_icon_press, KEY_IP, KEY_EVENT_DOWN);

        SetKeyHandler(mmi_avatar_stretch_icon_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_avatar_shrink_icon_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_avatar_moveup_icon_release, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_avatar_movedown_icon_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_avatar_magnify_icon_release, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_avatar_minify_icon_release, KEY_VOL_DOWN, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_toggle_editor_phase
 * DESCRIPTION
 *  toggle editor phase
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_toggle_editor_phase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->rsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;

    avatar_cntx_p->is_editor_phase1 = !avatar_cntx_p->is_editor_phase1;
    mmi_avatar_set_editor_phase_setting();
    mmi_avatar_right_icon_update();
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_select_next_item
 * DESCRIPTION
 *  select next item (bottom)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_select_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 new_itom_idx = 0, old_itom_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define AVATAR_CHECK_ARROW_BOTTOM2(a,A)\
do{\
    if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a <MMI_AVATAR_COUNT_OF_##A-1)\
        avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a++;\
    avatar_cntx_p->page_of_##a = avatar_cntx_p->selected_itom_page =avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a/MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->selected_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a%MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->is_highlighted = TRUE;\
    if ( avatar_cntx_p->page_of_##a > 0)\
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
    if ( (1+avatar_cntx_p->page_of_##a)*MMI_AVATAR_ITOM_COUNT_PER_PAGE < MMI_AVATAR_COUNT_OF_##A)\
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
}while(0)


    switch(avatar_cntx_p->selected_top_object)
    {
    case AVATAR_TOUCH_HEAD:
        old_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head;
        AVATAR_CHECK_ARROW_BOTTOM2(head,HEAD);
        new_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head;
        if (old_itom_idx != new_itom_idx)
        mmi_avatar_apply_change(old_itom_idx,new_itom_idx);
        break;
    case AVATAR_TOUCH_HAIR:
        old_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair;
        AVATAR_CHECK_ARROW_BOTTOM2(hair,HAIR);
        new_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair;
        if (old_itom_idx != new_itom_idx)
        mmi_avatar_apply_change(old_itom_idx,new_itom_idx);
        break;
    case AVATAR_TOUCH_EYE:
        AVATAR_CHECK_ARROW_BOTTOM2(eye,EYE);
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_BROW:
        AVATAR_CHECK_ARROW_BOTTOM2(brow,BROW);
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_LIP:
        AVATAR_CHECK_ARROW_BOTTOM2(lip,LIP);
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_DECORATION:
        AVATAR_CHECK_ARROW_BOTTOM2(decoration,DECORATION);
        mmi_avatar_set_editor_phase_setting();
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_BODY:
        old_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body;
        AVATAR_CHECK_ARROW_BOTTOM2(body,BODY);
        new_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body;
        if (old_itom_idx != new_itom_idx)
        mmi_avatar_apply_change(old_itom_idx,new_itom_idx);
        break;    
    }
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

#undef AVATAR_CHECK_ARROW_BOTTOM2

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_select_previous_item
 * DESCRIPTION
 *  select previous item (bottom)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_select_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 new_itom_idx = 0, old_itom_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define AVATAR_CHECK_ARROW_BOTTOM2(a,A)\
do{\
    if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a > 0)\
        avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a--;\
    avatar_cntx_p->page_of_##a = avatar_cntx_p->selected_itom_page =avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a/MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->selected_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a%MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->is_highlighted = TRUE;\
    if ( avatar_cntx_p->page_of_##a > 0)\
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
    if ( (1+avatar_cntx_p->page_of_##a)*MMI_AVATAR_ITOM_COUNT_PER_PAGE < MMI_AVATAR_COUNT_OF_##A)\
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
}while(0)


    switch(avatar_cntx_p->selected_top_object)
    {
    case AVATAR_TOUCH_HEAD:
        old_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head;
        AVATAR_CHECK_ARROW_BOTTOM2(head,HEAD);
        new_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_head;
        if (old_itom_idx != new_itom_idx)
        mmi_avatar_apply_change(old_itom_idx,new_itom_idx);
        break;
    case AVATAR_TOUCH_HAIR:
        old_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair;
        AVATAR_CHECK_ARROW_BOTTOM2(hair,HAIR);
        new_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_hair;
        if (old_itom_idx != new_itom_idx)
        mmi_avatar_apply_change(old_itom_idx,new_itom_idx);
        break;
    case AVATAR_TOUCH_EYE:
        AVATAR_CHECK_ARROW_BOTTOM2(eye,EYE);
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_BROW:
        AVATAR_CHECK_ARROW_BOTTOM2(brow,BROW);
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_LIP:
        AVATAR_CHECK_ARROW_BOTTOM2(lip,LIP);
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_DECORATION:
        AVATAR_CHECK_ARROW_BOTTOM2(decoration,DECORATION);
        mmi_avatar_set_editor_phase_setting();
        mmi_avatar_apply_facial_texture_change();
        break;
    case AVATAR_TOUCH_BODY:
        old_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body;
        AVATAR_CHECK_ARROW_BOTTOM2(body,BODY);
        new_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_body;
        if (old_itom_idx != new_itom_idx)
        mmi_avatar_apply_change(old_itom_idx,new_itom_idx);
        break;    
    }
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

#undef AVATAR_CHECK_ARROW_BOTTOM2

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_reset_right_icon
 * DESCRIPTION
 *  reset right icon to disable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_reset_right_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;
    avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;
    avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_DISABLE;
    avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_DISABLE;
    avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;
    avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;
    avatar_osd_cntx_p->color.is_press = AVATAR_ICON_STATUS_DISABLE;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_right_icon_update
 * DESCRIPTION
 *  update right icon to their correct state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_right_icon_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_reset_right_icon();
    if (!avatar_cntx_p->is_editor_phase1)
    {
        switch(avatar_cntx_p->selected_top_object)
        {
        case AVATAR_TOUCH_HEAD:
            avatar_osd_cntx_p->color.is_press = AVATAR_ICON_STATUS_ENABLE;      
            break;    
        case AVATAR_TOUCH_BODY:
            avatar_osd_cntx_p->color.is_press = AVATAR_ICON_STATUS_ENABLE;      
            break;    
        case AVATAR_TOUCH_DECORATION:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y > -4)
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y < 4)
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;
            
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration < 0)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration > -4)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;
            break;
        case AVATAR_TOUCH_HAIR:
            //DO NOTHING
            break;
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y > -4)
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y < 4)
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x > -3)
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x < 3)
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_DISABLE
                ;
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye <2)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye > -2)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;           
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y > -4)
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;

            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y < 4)
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x > -3)
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x < 3)
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_DISABLE;
            
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow <2)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow > -2)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;           
            break;
        case AVATAR_TOUCH_LIP:
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip <2)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip > -2)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;           

            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y > -4)  
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;

            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y < 4)  
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;
            break;
        }
    }
#else
    mmi_avatar_reset_right_icon();

        switch(avatar_cntx_p->selected_top_object)
        {
        case AVATAR_TOUCH_HEAD:
            avatar_osd_cntx_p->color.is_press = AVATAR_ICON_STATUS_ENABLE;      
            break;    
        case AVATAR_TOUCH_BODY:
            avatar_osd_cntx_p->color.is_press = AVATAR_ICON_STATUS_ENABLE;      
            break;    
        case AVATAR_TOUCH_DECORATION:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y > -4)
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y < 4)
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;
            
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration < 0)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration > -4)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;
            break;
        case AVATAR_TOUCH_HAIR:
            //DO NOTHING
            break;
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y > -4)
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y < 4)
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x > -3)
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x < 3)
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_ENABLE;
            else 
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_DISABLE
                ;
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye <2)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye > -2)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;           
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y > -4)
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;

            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y < 4)
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x > -3)
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x < 3)
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_DISABLE;
            
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow <2)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow > -2)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;           
            break;
        case AVATAR_TOUCH_LIP:
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip <2)
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_DISABLE;

            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip > -2)
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;    
            else 
                avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_DISABLE;           

            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y > -4)  
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_DISABLE;

            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y < 4)  
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
            else
                avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_DISABLE;
            break;
        }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_reset_top_icon
 * DESCRIPTION
 *  reset top icon to enable state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_reset_top_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   avatar_osd_cntx_p->head.is_press = AVATAR_ICON_STATUS_ENABLE;
   avatar_osd_cntx_p->hair.is_press = AVATAR_ICON_STATUS_ENABLE ;
   avatar_osd_cntx_p->eye.is_press = AVATAR_ICON_STATUS_ENABLE ;   
   avatar_osd_cntx_p->brow.is_press = AVATAR_ICON_STATUS_ENABLE ;   
   avatar_osd_cntx_p->lip.is_press = AVATAR_ICON_STATUS_ENABLE ;   
   avatar_osd_cntx_p->decoration.is_press = AVATAR_ICON_STATUS_ENABLE ;   
   avatar_osd_cntx_p->body.is_press = AVATAR_ICON_STATUS_ENABLE ;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_bottom_icon_page_change
 * DESCRIPTION
 *  apply bottom icon to its correct state and 
 * PARAMETERS
 *  diff     [IN]        page change (0:do not change, +1 next page...)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_bottom_icon_page_change(S16 diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
#define AVATAR_CHECK_ARROW_BOTTOM(a,A)\
do{\
    avatar_cntx_p->page_of_##a += diff;\
    avatar_cntx_p->selected_itom_page = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a/MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->selected_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a%MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->is_highlighted = (avatar_cntx_p->selected_itom_page == avatar_cntx_p->page_of_##a)? TRUE:FALSE;\
    if ( avatar_cntx_p->page_of_##a > 0)\
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
    if ( (1+avatar_cntx_p->page_of_##a)*MMI_AVATAR_ITOM_COUNT_PER_PAGE < MMI_AVATAR_COUNT_OF_##A)\
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
}while(0)
#else
#define AVATAR_CHECK_ARROW_BOTTOM(a,A)\
do{\
    avatar_cntx_p->page_of_##a = avatar_cntx_p->selected_itom_page = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a/MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->selected_itom_idx = avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_##a%MMI_AVATAR_ITOM_COUNT_PER_PAGE;\
    avatar_cntx_p->is_highlighted = (avatar_cntx_p->selected_itom_page == avatar_cntx_p->page_of_##a)? TRUE:FALSE;\
    if ( avatar_cntx_p->page_of_##a > 0)\
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->larrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
    if ( (1+avatar_cntx_p->page_of_##a)*MMI_AVATAR_ITOM_COUNT_PER_PAGE < MMI_AVATAR_COUNT_OF_##A)\
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_ENABLE;\
    else \
        avatar_osd_cntx_p->rarrow.is_press = AVATAR_ICON_STATUS_DISABLE;\
}while(0)
#endif
    switch(avatar_cntx_p->selected_top_object)
    {
    case AVATAR_TOUCH_HEAD:
        AVATAR_CHECK_ARROW_BOTTOM(head,HEAD);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        break;
    case AVATAR_TOUCH_HAIR:
        AVATAR_CHECK_ARROW_BOTTOM(hair,HAIR);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        break;
    case AVATAR_TOUCH_EYE:
        AVATAR_CHECK_ARROW_BOTTOM(eye,EYE);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        break;
    case AVATAR_TOUCH_BROW:
        AVATAR_CHECK_ARROW_BOTTOM(brow,BROW);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        break;
    case AVATAR_TOUCH_LIP:
        AVATAR_CHECK_ARROW_BOTTOM(lip,LIP);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        break;
    case AVATAR_TOUCH_DECORATION:
        AVATAR_CHECK_ARROW_BOTTOM(decoration,DECORATION);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        break;
    case AVATAR_TOUCH_BODY:
        AVATAR_CHECK_ARROW_BOTTOM(body,BODY);
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_BODY_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_BODY_OFFSET_Z);
        break;    
    }


    /* INIT right icon */
    mmi_avatar_right_icon_update();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_head_icon_press
 * DESCRIPTION
 *  head icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_head_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_HEAD;
    avatar_osd_cntx_p->head.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_hair_icon_press
 * DESCRIPTION
 *  hair icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_hair_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_HAIR;
    avatar_osd_cntx_p->hair.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_eye_icon_press
 * DESCRIPTION
 *  eye icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_eye_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_EYE;
    avatar_osd_cntx_p->eye.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_brow_icon_press
 * DESCRIPTION
 *  brow icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_brow_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_BROW;
    avatar_osd_cntx_p->brow.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_decoration_icon_press
 * DESCRIPTION
 *  decoration icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_decoration_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_DECORATION;
    avatar_osd_cntx_p->decoration.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_lip_icon_press
 * DESCRIPTION
 *  lip icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_lip_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_LIP;
    avatar_osd_cntx_p->lip.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_body_icon_press
 * DESCRIPTION
 *  body icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_body_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_avatar_reset_top_icon();
    avatar_cntx_p->selected_top_object = AVATAR_TOUCH_BODY;
    avatar_osd_cntx_p->body.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_bottom_icon_page_change(0);
#ifndef __MMI_TOUCH_SCREEN__
    mmi_avatar_set_editor_phase_setting();
#endif
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_stretch_icon_press
 * DESCRIPTION
 *  stretch icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_stretch_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->stretch.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_shrink_icon_press
 * DESCRIPTION
 *  shrink icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_shrink_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->shrink.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_moveup_icon_press
 * DESCRIPTION
 *  moveup icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_moveup_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->moveup.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_movedown_icon_press
 * DESCRIPTION
 *  movedown icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_movedown_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->movedown.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_magnify_icon_press
 * DESCRIPTION
 *  magnify icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_magnify_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->magnify.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;
    
    avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_minify_icon_press
 * DESCRIPTION
 *  minify icon pressed 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_minify_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->minify.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_color_icon_press
 * DESCRIPTION
 *  color icon prssed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_color_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->color.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_HEAD:
            avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face++;
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face >= MMI_AVATAR_COLOR_COUNT_OF_FACE)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_face = 0;

            mmi_avatar_bottom_icon_page_change(0);
            mmi_avatar_apply_facial_texture_change();   
            mmi_avatar_draw_osd();
            gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
        break;
        case AVATAR_TOUCH_BODY:
            avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress++;
            if (avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress >= MMI_AVATAR_COLOR_COUNT_OF_DRESS)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].selected_dress = 0;

            mmi_avatar_bottom_icon_page_change(0);
            mmi_avatar_apply_body_texture_change();   
            mmi_avatar_draw_osd();
            gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_top_larrow_icon_press
 * DESCRIPTION
 *  top larrow icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_top_larrow_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->top_larrow.is_press = AVATAR_ICON_STATUS_CLICKED ;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_top_rarrow_icon_press
 * DESCRIPTION
 *  top rarrow icon pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_top_rarrow_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->top_rarrow.is_press = AVATAR_ICON_STATUS_CLICKED ;    
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_lsk_press
 * DESCRIPTION
 *  lsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->touch_object = AVATAR_TOUCH_LSK;
    avatar_cntx_p->lsk.is_press = AVATAR_ICON_STATUS_CLICKED;
    mmi_avatar_draw_osd();
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    else        
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_rsk_press
 * DESCRIPTION
 *  rsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->touch_object = AVATAR_TOUCH_RSK;
    avatar_cntx_p->rsk.is_press = AVATAR_ICON_STATUS_CLICKED;
    mmi_avatar_draw_osd();
    if (avatar_cntx_p->state == AVATAR_STATE_DISPLAYING || avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    else        
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_rsk_release_from_select_animation_screen
 * DESCRIPTION
 *  rsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_rsk_release_from_select_animation_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;
    avatar_cntx_p->rsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_stretch_icon_release
 * DESCRIPTION
 *  stretch icon released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_stretch_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->stretch.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x > -3)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x--;
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x > -3)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x--;
            break;
    }
    mmi_avatar_apply_facial_texture_change();
    mmi_avatar_right_icon_update();
    avatar_osd_cntx_p->shrink.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_shrink_icon_release
 * DESCRIPTION
 *  shrink icon released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_shrink_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->shrink.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x < 3)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_x++;
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x < 3)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_x++;
            break;
    }
    mmi_avatar_apply_facial_texture_change();
    mmi_avatar_right_icon_update();
    avatar_osd_cntx_p->stretch.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_moveup_icon_release
 * DESCRIPTION
 *  moveup icon released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_moveup_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->moveup.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y > -4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y--;
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y > -4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y--;
            break;
        case AVATAR_TOUCH_LIP:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y > -4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y--;            
            break;
        case AVATAR_TOUCH_DECORATION:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y > -4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y--;
            break;
    }
    mmi_avatar_apply_facial_texture_change();
    mmi_avatar_right_icon_update();
    avatar_osd_cntx_p->movedown.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   

}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_movedown_icon_release
 * DESCRIPTION
 *  movedown icon released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_movedown_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->movedown.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y < 4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_eye_y++;
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y < 4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_brow_y++;
            break;
        case AVATAR_TOUCH_LIP:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y < 4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_lip_y++;            
            break;
        case AVATAR_TOUCH_DECORATION:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y < 4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].offset_decoration_y++;
            break;
    }
    mmi_avatar_apply_facial_texture_change();    
    mmi_avatar_right_icon_update();
    avatar_osd_cntx_p->moveup.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   

}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_magnify_icon_release
 * DESCRIPTION
 *  magnify icon released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_magnify_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->magnify.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye < 2)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye++;
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow < 2)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow++;
            break;
        case AVATAR_TOUCH_LIP:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip < 2)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip++;            
            break;
        case AVATAR_TOUCH_DECORATION:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration < 0)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration++;
            break;
    }
    mmi_avatar_right_icon_update();
    mmi_avatar_apply_facial_texture_change();

    avatar_osd_cntx_p->minify.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_minify_icon_release
 * DESCRIPTION
 *  minify icon released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_minify_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (avatar_osd_cntx_p->minify.is_press == AVATAR_ICON_STATUS_DISABLE)
        return;

    switch (avatar_cntx_p->selected_top_object)
    {
        case AVATAR_TOUCH_EYE:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye > -2)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_eye--;
            break;
        case AVATAR_TOUCH_BROW:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow > -2)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_brow--;
            break;
        case AVATAR_TOUCH_LIP:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip > -2)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_lip--;            
            break;
        case AVATAR_TOUCH_DECORATION:
            if(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration > -4)
                avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id].s_level_decoration--;
            break;
    }

    mmi_avatar_right_icon_update();
    mmi_avatar_apply_facial_texture_change();
    avatar_osd_cntx_p->magnify.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_top_larrow_icon_release
 * DESCRIPTION
 *  top left arrow released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_top_larrow_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->top_larrow.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);        

    if(MMI_AVATAR_COUNT_OF_ANIMATION==0)
        return;

    if(avatar_cntx_p->selected_animation == 0)
        avatar_cntx_p->selected_animation = MMI_AVATAR_COUNT_OF_ANIMATION-1;       
    else
        avatar_cntx_p->selected_animation--;    
    
    EntryNewScreen(SCR_ID_AVATAR_SELECT_ANIMATION, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_AVATAR_SELECT_ANIMATION);
    avatar_cntx_p->is_reload = FALSE;
    mmi_avatar_entry_select_animation_screen();
    avatar_cntx_p->is_reload = TRUE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_top_rarrow_icon_release
 * DESCRIPTION
 *  lsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_top_rarrow_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_osd_cntx_p->top_rarrow.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);   

    if(MMI_AVATAR_COUNT_OF_ANIMATION==0)
        return;

    avatar_cntx_p->selected_animation++;


    if(avatar_cntx_p->selected_animation >= MMI_AVATAR_COUNT_OF_ANIMATION)
        avatar_cntx_p->selected_animation = 0;


    EntryNewScreen(SCR_ID_AVATAR_SELECT_ANIMATION, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_AVATAR_SELECT_ANIMATION);
    avatar_cntx_p->is_reload = FALSE;
    mmi_avatar_entry_select_animation_screen();
    avatar_cntx_p->is_reload = TRUE;
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_lsk_release
 * DESCRIPTION
 *  lsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;
    avatar_cntx_p->lsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    else        
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

    if (avatar_cntx_p->state == AVATAR_STATE_NEW_EDITING )
    {
        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                    ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                    MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                    MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
        //mmi_avatar_render();
        mmi_avatar_entry_editing_name_screen();
    }
    else if (avatar_cntx_p->state == AVATAR_STATE_MODIFYING)
    {
        /* clear all keys */
        ClearInputEventHandler(MMI_DEVICE_KEY);

        M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);

        /* encode avatar's head into a Jpeg file */
        mmi_avatar_encode_jpeg();


        gdi_layer_flatten_to_base(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);   

        avatar_cntx_p->state = AVATAR_STATE_SAVING;


        ret = mmi_avatar_save_avatar_setting(&(avatar_cntx_p->avatar_list[avatar_cntx_p->selected_avatar_id]),avatar_cntx_p->selected_avatar_id);
        
        if (ret < 0)
        {
            mmi_avatar_display_error_popup(ret);
        }
        mmi_avatar_save_meta_manager();

        DisplayPopupCallBack((PU8) GetString(STR_GLOBAL_SAVING), 
                            IMG_GLOBAL_SAVE, 
                            1, 
                            ST_NOTIFYDURATION, 
                            0, 
                            mmi_avatar_saving_timeout);

        DeleteUptoScrID(SCR_ID_AVATAR_OPTION_MENU);
        DeleteNHistory(1);


    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_rsk_release
 * DESCRIPTION
 *  rsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_avatar_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    pBOOL is_modified = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    avatar_cntx_p->touch_object = AVATAR_TOUCH_NONE;
    avatar_cntx_p->rsk.is_press = AVATAR_ICON_STATUS_ENABLE;
    mmi_avatar_draw_osd();
    if (avatar_cntx_p->state == AVATAR_STATE_SELECT_ANIMATION)
        gdi_lcd_blt(avatar_cntx_p->drawing_layer_handle,avatar_cntx_p->osd_layer_handle,0,0);
    else        
        gdi_lcd_blt(avatar_cntx_p->osd_layer_handle,avatar_cntx_p->drawing_layer_handle,0,0);

    M3D_Transformable_setTranslation((st_m3d_transformable*)avatar_cntx_p->m3d_camera,
                                        ((st_m3d_transformable*)avatar_cntx_p->m3d_camera)->_translation[0],
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Y,
                                        MMI_AVATAR_CAMERA_HEAD_OFFSET_Z);
    is_modified = mmi_avatar_check_if_modified();

    if (is_modified == TRUE)
    {

        avatar_cntx_p->prev_state = avatar_cntx_p->state ;
        avatar_cntx_p->state = AVATAR_STATE_CHECK_IF_SAVE;

        DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_AVATAR_EXIT_EDITOR_WITHOUT_SVAE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_avatar_exit_editor_without_save, KEY_EVENT_UP);        
    }
    else
    {
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_exit_editor_without_save
 * DESCRIPTION
 *  exit_editor_without save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_exit_editor_without_save(void)
{
    GoBacknHistory(2);
}

#endif

/***************************************************************************** 
* External Functions Implementation
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_init
 * DESCRIPTION
 *  avatar init function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    FS_HANDLE file_handle;
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    S8 UCS2_buffer[FMGR_PATH_BUFFER_SIZE*2];
    S16 head_idx,i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sprintf((PS8) buf_filename, "Z:\\@avatar");
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

    avatar_cntx_p->is_meta_manager_loaded = FALSE;


    file_handle = FS_Open((kal_uint16*) UCS2_buffer, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    else
    {
        fs_ret = FS_CreateDir((PU16) UCS2_buffer);
        if (fs_ret < 0)
        {
            return ;
        }
    }

    if (!avatar_cntx_p->is_meta_manager_loaded)
    {
        mmi_avatar_load_meta_manager();

        if (avatar_cntx_p->meta_manager.delete_all==TRUE)
        {
            head_idx = avatar_cntx_p->meta_manager.head;
            for (i=0;i<avatar_cntx_p->meta_manager.total_count;i++)
            {
                sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.atr",avatar_cntx_p->meta_manager.meta_header[head_idx].serial_number);
                mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

                file_handle = FS_Delete((U16*) UCS2_buffer);

                if (avatar_cntx_p->meta_manager.meta_header[head_idx].next==(S16)0xffff)
                {
                    /* the last is found */     
                    break;
                }       
                else
                {
                    /* find next */
                    head_idx = avatar_cntx_p->meta_manager.meta_header[head_idx].next;
                }
            }
            mmi_avatar_restore_meta_manager();

            avatar_cntx_p->meta_manager.delete_all = FALSE;
            mmi_avatar_save_meta_manager();

        }
        else
            mmi_avatar_load_avatar_list();
        avatar_cntx_p->is_meta_manager_loaded = TRUE;
    }    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_init_app
 * DESCRIPTION
 *  avatar init function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    my_time = 0;
    applib_mem_ap_register(APPLIB_MEM_AP_ID_AVATAR,STR_ID_AVATAR_APP_NAME 
                ,IMG_ID_AVATAR_APP_ICON ,mmi_avatar_app_mem_stop_callback);

    SetHiliteHandler(MENU_ID_AVATAR_EDITOR, mmi_avatar_highlight_app);

    mmi_fmgr_get_fmgr_cache_struct ((void**)&g_avatar_image_cache_list_buffer,
                                    (void**)&g_avatar_image_handle_list_buffer ,
                                    (void**)&avatar_image_cache_p,
                                    (void**)&avatar_delay_decoder_p);

    
    avatar_cntx_p->editor_m3d.image_type = GDI_IMAGE_TYPE_AVATAR;
    avatar_cntx_p->editor_m3d.serial_number = 0;
    avatar_cntx_p->editor_m3d.resourceid = IMG_ID_AVATAR_M3D_EDITOR_ANIMATION;
    /* init option menu */
    mmi_avatar_init_option_menu();

#ifndef __MMI_TOUCH_SCREEN__
avatar_cntx_p->is_editor_phase1 = TRUE;

#endif

    avatar_cntx_p->drawing_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    avatar_cntx_p->is_reload = TRUE;
    avatar_cntx_p->m3d_world_head = NULL;
    avatar_cntx_p->m3d_world_hair = NULL;
    avatar_cntx_p->m3d_world_body = NULL;
    avatar_cntx_p->last_error = MMI_AVATAR_FAILED;
#ifdef __MMI_TOUCH_SCREEN__
    avatar_cntx_p->movement_x = 0;
    avatar_cntx_p->movement_y = 0;
#endif
}
/* MUST MODIFY FOR UP/DOWN.... */


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_select_path_and_enter 
 * DESCRIPTION
 *  show avatar list --> mmi_avatar_select_path_and_enter_internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avatar_select_path_and_enter (mmi_avatar_app_type_enum app_type,avatar_callback func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_cntx_p->app_type = app_type;
    avatar_cntx_p->app_callback_ptr = func_ptr;
    mmi_avatar_select_path_and_enter_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_is_avatar_existed
 * DESCRIPTION
 *  show avatar list --> mmi_avatar_select_path_and_enter_internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_avatar_is_avatar_existed(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_avatar_meta_header_struct    *avatar_mh_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_mh_p = (mmi_avatar_meta_header_struct*) id;
    return !avatar_mh_p->is_slot_free;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_is_avatar_valid
 * DESCRIPTION
 *  show avatar list --> mmi_avatar_select_path_and_enter_internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern pBOOL mmi_avatar_is_avatar_valid(U32 id, U32 serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_avatar_meta_header_struct    *avatar_mh_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_mh_p = (mmi_avatar_meta_header_struct*) id;

    if (avatar_mh_p->serial_number == serial_num && avatar_mh_p->is_slot_free == FALSE)
        return TRUE;
    else
        return FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_avatar_is_avatar_existed
 * DESCRIPTION
 *  show avatar list --> mmi_avatar_select_path_and_enter_internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_avater_get_name_by_avatarid(U32 id, PS8 name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_avatar_meta_header_struct    *avatar_mh_p;
    U16 avatarid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avatar_mh_p = (mmi_avatar_meta_header_struct*) id;
    avatarid = avatar_mh_p->idx;
    mmi_ucs2cpy(name,avatar_cntx_p->avatar_list[avatarid].filename);
}


/*****************************************************************************
* FUNCTION
*   mmi_fmgr_delay_decode_x()
* DESCRIPTION
*   delay decode callback function for timer expire
* PARAMETERS
*   void
* RETURNS
*   BOOL
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#define AVATAR_DELAY_DECODE_FUNCTION(_idx_)                                                      \
      static void mmi_avatar_delay_decode_##_idx_##(void)                                        \
      {                                                                                          \
         mmi_avatar_delay_decode_image(avatar_delay_decoder_p[##_idx_##].item_idx,         \
                                       avatar_delay_decoder_p[##_idx_##].menuitem_offset_x,\
                                       avatar_delay_decoder_p[##_idx_##].menuitem_offset_y,\
                                       avatar_delay_decoder_p[##_idx_##].box_offset_x,     \
                                       avatar_delay_decoder_p[##_idx_##].box_offset_y,     \
                                       avatar_delay_decoder_p[##_idx_##].box_width,        \
                                       avatar_delay_decoder_p[##_idx_##].box_height,       \
                                       avatar_delay_decoder_p[##_idx_##].icon_offset_x,    \
                                       avatar_delay_decoder_p[##_idx_##].icon_offset_y,    \
                                       avatar_delay_decoder_p[##_idx_##].icon_width,       \
                                       avatar_delay_decoder_p[##_idx_##].icon_height,      \
                                       avatar_delay_decoder_p[##_idx_##].icon_ptr,         \
                                       avatar_delay_decoder_p[##_idx_##].is_hilighted,     \
                                       avatar_delay_decoder_p[##_idx_##].ui_style);        \
      }
   /* end of macro */

/* delay decode function */
AVATAR_DELAY_DECODE_FUNCTION(0)
AVATAR_DELAY_DECODE_FUNCTION(1)
AVATAR_DELAY_DECODE_FUNCTION(2)
AVATAR_DELAY_DECODE_FUNCTION(3)
AVATAR_DELAY_DECODE_FUNCTION(4)
AVATAR_DELAY_DECODE_FUNCTION(5)
AVATAR_DELAY_DECODE_FUNCTION(6) 
AVATAR_DELAY_DECODE_FUNCTION(7) 
AVATAR_DELAY_DECODE_FUNCTION(8) 
AVATAR_DELAY_DECODE_FUNCTION(9)

#endif /* __MMI_AVATAR__ */ 

