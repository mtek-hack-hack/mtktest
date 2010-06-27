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
 *	 Res_Vdoeditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Generate Video editor Resources
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_VIDEO_EDITOR__)

#include "MMI_features_video.h"

#include "PopulateRes.h"			/* menuitem ID */
#include "CustResDef.h"				/* resource path define */
			 
#include "VdoEdtResDef.h"             /* vdo editor */

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#include "MainMenuDef.h"
#endif


#if defined(__MMI_VIDEO_EDITOR__)
/*****************************************************************************
* FUNCTION
*	PopulateVdoEdtStrRes
* DESCRIPTION
*	Generate Video Editor String Resource
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
****************************************************************************/
void PopulateVdoEdtStrRes(void)
{
    /* app name */
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_APP,  "Video Editor", "[App Name]");
    /* preview option */
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_PREVIEW,  "Preview", "[Menu-PlayOption: Preview]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_NEW_W7E,  "New Workspace","[Menu-PlayOption: New WorkSpace]");
#ifdef __MMI_VDOEDT_CUSTOM_AUD__    
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUDIO,    "Audio",        "[Menu-PlayOption: Enter Audio Menu]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_PLAY, "Play", "[Menu-Audio: Play]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_CHANGE, "Change", "[Menu-Audio:change audio]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_REMOV_AUD, "Remove Audio", "[Menu-Remove audio]");

    #ifdef __MMI_VDOEDT_D5T_AUD__
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUD_DEFAULT,  "Default Audios",   "[Menu-PlayOptin,Audio: Select Default audios]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUD1, "Audio 1", "[Menu-DefaultAudio: Music1]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUD2, "Audio 2", "[Menu-DefaultAudio: Music2]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUD3, "Comedy", "[Menu-DefaultAudio: Music3]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUD4, "Action", "[Menu-DefaultAudio: Music2]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_AUD5, "Romance", "[Menu-DefaultAudio: Music2]");
    #endif /* __MMI_VDOEDT_D5T_AUD__ */
#endif /* __MMI_VDOEDT_CUSTOM_AUD__ */    
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_SEL_FROM_FILE,"Select From File", "[Menu-PlayOption,ImageInsert: from file]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_REMOVE, "Remove", "[Menu-Audio,Video_option,Frame_edit_option: Remove audio/video/Frame]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_REMOVE_CONFIRM, "Remove this shot?", "[MENU-remove confirm]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_REMOV_SHOT, "Remove the Shot", "[Menu-remove shot");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_REMOV_FRMTXT, "Remove Frame/Text", "[Menu-remove frame and text]");    
    /* video edit option */
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_INS_VDO, "Insert Video", "[Menu-Vdo_option: inset video]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_INS_IMG, "Insert Image", "[Menu-Vdo_option: inset image]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_CUT_VDO, "Cut Video", "[Menu-Vdo_option: Cut Video]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_FRAME, "Edit Frame/Text", "[Menu-Vdo_option: enter frame/text menu]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_DUR, "Change Duration", "[Menu-Vdo_option: image duration]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_IMG_DUR_1, "2 Seconds", "[Menu-Image_duration: duration1]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_IMG_DUR_2, "3 Seconds", "[Menu-Image_duration: duration2]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_IMG_DUR_3, "4 Seconds", "[Menu-Image_duration: duration3]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_IMG_DUR_4, "5 Seconds", "[Menu-Image_duration: duration4]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_IMG_DUR_5, "6 Seconds", "[Menu-Image_duration: duration5]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_LAST_FRAME, "Last Pic of previous shot", "[Menu-Image_insert_option: last pic of prevoius shot]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_FIRST_FRAME,"First Pic of this shot", "[Menu-Image_insert_option: first pic of this shot]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_COLOR, "Select Color", "[Menu-Image_insert_option: Select Color]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT, "Edit Trans. Effect", "[Menu-Video_option: shot effect]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_IN, "In Effect", "[Menu-Video_option: shot in effect]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_OUT, "Out Effect", "[Menu-Video_option: shot out effect]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_PLAY, "Video Effect", "Menu-Video_option: Video effect]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_NONE, "None",  "[Menu-Video_edit_effect: no effect]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_FROM_BLACK, "From Black", "[Menu-Video_effect: fade in from black]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_FROM_WHITE, "From White", "[Menu-Video_effect: fade in from white]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_2_BLACK, "To Black", "[Menu-Video_effect: fade out to black]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_2_WHITE, "To White", "[Menu-Video_effect: fade out to white]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_GRAYSCALE, "Grayscale", "[Menu-Video_effect: grayscale]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_SEPIA, "Sepia", "[Menu-Video_effect: Sepiia]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_SEPIAGREEN, "Sepia Green", "[Menu-Video_effect: Sepia green]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_SEPIABLUE, "Sepia Blue", "[Menu-Video_effect: sepia blue]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_COLORINV, "Color Invert", "[Menu-Video_effect: color inv]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EFFECT_GRAYINV, "Gray Invert", "[Menu-Video_effect: Gray invert]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT, "Add/Edit Text", "[Menu-Frame_edit_option: Edit/add text]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_FRAME_TXT, "Text Option", "[Menu-Frame_text_properties]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_FRAME_EDT, "Edit Duration","[Menu-Frame_length]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_COLOR, "Text Color", "[Menu-Frame_text_properties: text color]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_POSITION, "Position", "[Menu-Frame_text_properties: text position]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_SIZE, "Font Size", "[Menu-Frame_text_properties: font size]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_PLZ_INS_VDO, "Please Insert Video", "[empty preview screen string]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_L, "Large Font", "[textsize-L]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_M, "Medium Font", "[textsize-M]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_S, "Small Font", "[textsize-S]");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_ALIGN_TOP, "Top", "text align-top");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_ALIGN_CEN, "Center", "text align-top");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_ALIGN_BTM, "Buttom", "text align-top");    
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_TXT_CHOOSE_FRM, "Select a Frame", "frame select string");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_CREATE_DIR_FAIL, "Disk Space not Enough", "can't create folder");    
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_ENCODING, "Estimated Remain Time", "encoding");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_2_CARD, "To Card", "save to card");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_2_PHONE, "To Phone", "save to phone");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EXIT, "Exit", "exit application");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EXIT_CONFIRM_MSG, "Exit Video Editor?", "exit confirm prompt msg");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_OUTPUT_VDO, "Output Video", "exit confirm prompt msg");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_O7E_CNF, "File already exists, overwrite?", "overwrite confirm msg");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_NO_SAVE_SPACE, "Not enough space", "save space not enough msg");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_INVALID_VDO, "Invalid Video", "invalid vdo");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_FILE_NOT_FOUND, "File not found", "can't find file");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_ENC_FAILED, "Saving Aborted", "can't save");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_WHITE, "White", "text color - white");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_BLACK, "Black", "text color - Black");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_EMPTY_STRING, "Empty String!", "notify - custom text is empty");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_BAD_VDO_REMOVE_NOTIFY, "Video is invalid, removed from editor.", "notify - inserted file is gone or invalid, will be remove");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_VDO_IS_TOO_SHORT, "Duration is too short", "notify- video is too short to cut");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_UNABLE_TO_OVERWRITE, "unable to overwrite", "file may opened or write protected."); 
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_ERR_TOO_SHORT, "Video is too short", "notify - video too short");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_ERR_TOO_LONG, "Video is too long", "notify - video too long");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_ERR_RESOLUTION, "Unsupported resolution", "notify - wrong resolution");
    ADD_APPLICATION_STRING2(STR_ID_VDOEDT_ERR_UNSUP_FORMAT, "Unsupported format", "notify - driver not support");
}

/*****************************************************************************
* FUNCTION
*   PopulateVdoEdtImgRes
* DESCRIPTION
*   Generate Video Editor Image Resource
* PARAMETERS
*   void
* RETURNS
*   void
* GLOBALS AFFECTED
*   NIL
*****************************************************************************/
void PopulateVdoEdtImgRes(void)
{
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_MAIN_ICON,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\SB_VE.bmp", "APP ICON");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_EDIT_BG,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_BG.bmp", "IMG_ID_VDOEDT_EDIT_BG");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_PROGRESS_BAR,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Progress.bmp", "IMG_ID_VDOEDT_PROGRESS_BAR");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_PROGRESS_BAR_BG,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Progress bg.bmp", "IMG_ID_VDOEDT_PROGRESS_BAR_BG");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D0,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_0.BMP", "IMG_ID_VDOEDT_D0");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D1,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_1.BMP", "IMG_ID_VDOEDT_D1");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D2,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_2.BMP", "IMG_ID_VDOEDT_D2");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D3,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_3.BMP", "IMG_ID_VDOEDT_D3");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D4,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_4.BMP", "IMG_ID_VDOEDT_D4");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D5,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_5.BMP", "IMG_ID_VDOEDT_D5");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D6,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_6.BMP", "IMG_ID_VDOEDT_D6");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D7,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_7.BMP", "IMG_ID_VDOEDT_D7");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D8,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_8.BMP", "IMG_ID_VDOEDT_D8");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D9,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_9.BMP", "IMG_ID_VDOEDT_D9");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_D_COL,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_num_col.BMP", "IMG_ID_VDOEDT_D_COL");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_EDITBAR_BG,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Editor.bmp", "IMG_ID_VDOEDT_EDIT_BG");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_EDITBAR_HILIGHT,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Editor_h.bmp", "IMG_ID_VDOEDT_EDITBAR_HILIGHT");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FADE_IN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\FadeIn.bmp", "IMG_ID_VDOEDT_FADE_IN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FADE_OUT,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\FadeOut.bmp", "IMG_ID_VDOEDT_FADE_OUT");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRAME,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\frame.bmp", "IMG_ID_VDOEDT_FRAME");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_AUDIO,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\music.bmp", "IMG_ID_VDOEDT_AUDIO");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_STAT_EMPTY,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\empty.bmp", "empty status");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_RW,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VR_Aleft.bmp", "IMG_ID_VDOEDT_RW");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_RW_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_ALeft_down.bmp", "IMG_ID_VDOEDT_RW_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FF,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VR_ARight.bmp", "IMG_ID_VDOEDT_FF");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FF_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_ARight_Down.bmp", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_PLAY,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Play up.bmp", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_PLAY_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Play_down.bmp", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRAME1,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\frame_01.gif", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRAME2,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\frame_02.gif", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRAME3,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\frame_03.gif", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRAME4,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\frame_04.gif", "IMG_ID_VDOEDT_FF_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRAME5,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\frame_05.gif", "IMG_ID_VDOEDT_FF_DOWN");
    /* cut screen */
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_BG,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_CUT_BG.bmp", "IMG_ID_VDOEDT_CUT_BG"); 
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_BAR_BG,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_frame_bg.bmp", "IMG_ID_VDOEDT_CUT_BAR_BG"); 
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_BAR,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_frame.bmp", "IMG_ID_VDOEDT_CUT_BAR"); 
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_OUT,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Cut_uparrow.bmp", "IMG_ID_VDOEDT_CUT_OUT"); 
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_OUT_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Cut_uparrow_H.bmp", "IMG_ID_VDOEDT_CUT_OUT_DOWN");   
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_IN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Cut_downarrow.bmp", "IMG_ID_VDOEDT_CUT_IN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_IN_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Cut_downarrow_H.bmp", "IMG_ID_VDOEDT_CUT_IN_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_ARROW_L,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_arrow_up_left.bmp", "IMG_ID_VDOEDT_ARROW_L");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_ARROW_L_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_arrow_down_left.bmp", "IMG_ID_VDOEDT_ARROW_L_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_ARROW_L_DISABLE,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_arrow_left.bmp", "IMG_ID_VDOEDT_ARROW_L_DISABLE");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_ARROW_R,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_arrow_up_right.bmp", "IMG_ID_VDOEDT_ARROW_R");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_ARROW_R_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_arrow_down_right.bmp", "IMG_ID_VDOEDT_ARROW_R_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_ARROW_R_DISABLE,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_arrow_right.bmp", "IMG_ID_VDOEDT_ARROW_R_DISABLE");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_IN_ICON,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Cut_down.bmp", "IMG_ID_VDOEDT_ARROW_R_DISABLE");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CUT_OUT_ICON,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Cut_up.bmp", "cut out icon");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_VIEWER,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Viewer.bmp", "frame selection background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRM_BAR,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_frame2_L.bmp", "bar using while editing frame");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRM_BAR_H,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_frame2.bmp", "hilighted frame bar");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_CBAR_H,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_frame_h.bmp", "hilighted cutbar");
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRMSEL_LAK,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Larrow.bmp", "Frame selection arrow");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRMSEL_LAK_D,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Larrow_down.bmp", "Frame selection arrow");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRMSEL_RAK,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Rarrow.bmp", "Frame selection arrow");    
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_FRMSEL_RAK_D,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Rarrow_down.bmp", "Frame selection arrow");
#endif
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_STOP,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Stop_up.bmp", "stop button");
    ADD_APPLICATION_IMAGE2(IMG_ID_VDOEDT_STOP_DOWN,
        CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoEditor\\\\VE_Stop_down.bmp", "stop button (pressed)");

}

/*****************************************************************************
* FUNCTION
*	PopulateVdoEdtMenuItemRes
* DESCRIPTION
*	Generate Video Player Menu Item Resource
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateVdoEdtMenuItemRes(void)
{

#if defined(__MMI_VERSION_2__)
    /* 12 matrix */

    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_APP,MAIN_MENU_MULTIMEDIA_MENUID,0,
        SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,STR_ID_VDOEDT_APP, IMG_ID_VDOEDT_MAIN_ICON));

#else /* __MMI_VERSION_2__ */

    /* 9 matrix */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_APP,MAIN_MENU_MULTIMEDIA_MENUID,0,
        SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,STR_ID_VDOEDT_APP, IMG_ID_VDOEDT_MAIN_ICON));

    #ifdef __MMI_OP01_MENU_NOSIM_LIST__
        ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_APP,MAIN_MENU_MULTIMEDIA_NO_SIM_MENUID,0,
                SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,1,STR_ID_VDOEDT_APP, IMG_ID_VDOEDT_MAIN_ICON));
    #endif /* __MMI_OP01_MENU_NOSIM_LIST__ */
    
#endif /* __MMI_VERSION_2__ */

    /* 3.1 main option */
#if defined (__MMI_VDOEDT_CUSTOM_AUD__)
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_MAIN_P5W_OPTION,
                                0,                         
                                3,
                                MENU_ID_VDOEDT_AUD_SEL,
                                MENU_ID_VDOEDT_SAVE,
                                MENU_ID_VDOEDT_NEW_W7E,
                                0,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                                IMG_GLOBAL_OPTIONS));
#else
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_MAIN_P5W_OPTION,
                                0,
                                2,
                                MENU_ID_VDOEDT_SAVE,
                                MENU_ID_VDOEDT_NEW_W7E,
                                0,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                                IMG_GLOBAL_OPTIONS));
#endif /* __MMI_VDOEDT_CUSTOM_AUD__ */

//  ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_PREVIEW, MENU_ID_VDOEDT_MAIN_P5W_OPTION,0,
//                              SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_PREVIEW,0));
//  ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_SAVE,MENU_ID_VDOEDT_MAIN_P5W_OPTION,0,
//                              SHOW,NONMOVEABLE,1,STR_GLOBAL_SAVE,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_NEW_W7E,MENU_ID_VDOEDT_MAIN_P5W_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_NEW_W7E,0));

    /*3.25 empty option */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_MAIN_EMPTY_OPTION,
                                0,
                                2,
                                MENU_ID_VDOEDT_INS_VDO,
                                MENU_ID_VDOEDT_INS_IMG,
                                0,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                                IMG_GLOBAL_OPTIONS));
#if defined (__MMI_VDOEDT_CUSTOM_AUD__)    
    /*3.8 audio select */
    #ifdef __MMI_VDOEDT_D5T_AUD__

    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_SEL,
                                0,
                                2,
                                MENU_ID_VDOEDT_AUD_SEL_FROM_FILE,
                                MENU_ID_VDOEDT_AUD_DEFAULT,
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_AUDIO,
                                0));
    #else /* __MMI_VDOEDT_D5T_AUD__ */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_SEL,
                                0,
                                1,
                                MENU_ID_VDOEDT_AUD_SEL_FROM_FILE,
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_AUDIO,
                                0));    
    #endif /* __MMI_VDOEDT_D5T_AUD__ */

    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_SEL_FROM_FILE, MENU_ID_VDOEDT_AUD_SEL,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_SEL_FROM_FILE,0));
    /* 3.7 audio option */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_OPTION,
                                0,
                                3,
                                MENU_ID_VDOEDT_AUD_PLAY,
                                MENU_ID_VDOEDT_AUD_CHANGE,
                                MENU_ID_VDOEDT_AUD_REMOVE,
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_AUDIO,
                                0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_PLAY, MENU_ID_VDOEDT_AUD_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_PLAY,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_CHANGE, MENU_ID_VDOEDT_AUD_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_CHANGE,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_REMOVE, MENU_ID_VDOEDT_AUD_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_REMOV_AUD,0));
    #ifdef __MMI_VDOEDT_D5T_AUD__    
    /* default audios */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_DEFAULT,
                                0,
                                2,
                                MENU_ID_VDOEDT_AUD_AUD1,
                                MENU_ID_VDOEDT_AUD_AUD2,
                            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
                            #endif                                
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_AUD_DEFAULT,
                                0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_AUD1, MENU_ID_VDOEDT_AUD_DEFAULT,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_AUD1,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_AUD_AUD2, MENU_ID_VDOEDT_AUD_DEFAULT,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_AUD2,0));
    #if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif/* 0 */
    #endif /* __MMI_VDOEDT_D5T_AUD__ */
#endif /* defined (__MMI_VDOEDT_CUSTOM_AUD__)*/
    /* 3.6 frame option */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_FILENAME_OPTION,
                                0,
                                3,
                                MENU_ID_VDOEDT_DONE,
                                MENU_ID_VDOEDT_CANCEL,
                                MENU_ID_VDOEDT_INPUT_METHOD,
                                SHOW,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                                0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_DONE, MENU_ID_VDOEDT_FILENAME_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_DONE,0));    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_CANCEL, MENU_ID_VDOEDT_FILENAME_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_CANCEL,0));    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INPUT_METHOD, MENU_ID_VDOEDT_FILENAME_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_INPUT_METHOD,0));    
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_TEXT_E4R_OPTION,
                                0,
                                3,
                                MENU_ID_VDOEDT_TEXT_E4R_DONE,
                                MENU_ID_VDOEDT_TEXT_E4R_CANCEL,
                                MENU_ID_VDOEDT_TEXT_E4R_INPUT_METHOD,
                                SHOW,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                                0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_TEXT_E4R_DONE, MENU_ID_VDOEDT_TEXT_E4R_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_DONE,0));    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_TEXT_E4R_CANCEL, MENU_ID_VDOEDT_TEXT_E4R_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_CANCEL,0));    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_TEXT_E4R_INPUT_METHOD, MENU_ID_VDOEDT_TEXT_E4R_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_INPUT_METHOD,0));        
    /*3.1 video option (edit) *****/
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_MAIN_EDT_OPTION,
                                0,
                                9,
                                MENU_ID_VDOEDT_INS_VDO,
                                MENU_ID_VDOEDT_INS_IMG,
                                MENU_ID_VDOEDT_REMOVE,
                                MENU_ID_VDOEDT_CUT_VDO,
                                MENU_ID_VDOEDT_SET_DUR,                                
                                MENU_ID_VDOEDT_EFFECT,
                                MENU_ID_VDOEDT_FRAME,
                                MENU_ID_VDOEDT_SAVE,
                                MENU_ID_VDOEDT_NEW_W7E,                                
                                0,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                               0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_NEW_W7E,MENU_ID_VDOEDT_MAIN_EDT_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_NEW_W7E,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INS_VDO,0,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_INS_VDO,0));
   
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_REMOVE,MENU_ID_VDOEDT_MAIN_EDT_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_REMOV_SHOT,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_EFFECT,MENU_ID_VDOEDT_MAIN_EDT_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_EFFECT,0));    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_CUT_VDO,MENU_ID_VDOEDT_MAIN_EDT_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_CUT_VDO,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INS_IMG,
                                0,
                                4,
                                MENU_ID_VDOEDT_INS_IMG_FROM_FILE,
                                MENU_ID_VDOEDT_INS_IMG_LAST_FRAME,
                                MENU_ID_VDOEDT_INS_IMG_FIRST_FRAME,
                                MENU_ID_VDOEDT_INS_IMG_COLOR,
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_INS_IMG,
                                0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INS_IMG_FROM_FILE, MENU_ID_VDOEDT_INS_IMG, 0,
                                SHOW,NONMOVEABLE, 1, STR_ID_VDOEDT_SEL_FROM_FILE,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INS_IMG_LAST_FRAME, MENU_ID_VDOEDT_INS_IMG, 0,
                                SHOW,NONMOVEABLE, 1, STR_ID_VDOEDT_LAST_FRAME,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INS_IMG_FIRST_FRAME, MENU_ID_VDOEDT_INS_IMG, 0,
                                SHOW,NONMOVEABLE, 1, STR_ID_VDOEDT_FIRST_FRAME,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_INS_IMG_COLOR, MENU_ID_VDOEDT_INS_IMG, 0,       
                                SHOW,NONMOVEABLE, 1, STR_ID_VDOEDT_COLOR,0));    

    
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_SET_DUR,
                                0,
                                5,
                                MENU_ID_VDOEDT_IMG_DUR_1,
                                MENU_ID_VDOEDT_IMG_DUR_2,
                                MENU_ID_VDOEDT_IMG_DUR_3,
                                MENU_ID_VDOEDT_IMG_DUR_4,
                                MENU_ID_VDOEDT_IMG_DUR_5,
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_DUR,
                                0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_IMG_DUR_1,MENU_ID_VDOEDT_SET_DUR,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_IMG_DUR_1,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_IMG_DUR_2,MENU_ID_VDOEDT_SET_DUR,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_IMG_DUR_2,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_IMG_DUR_3,MENU_ID_VDOEDT_SET_DUR,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_IMG_DUR_3,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_IMG_DUR_4,MENU_ID_VDOEDT_SET_DUR,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_IMG_DUR_4,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_IMG_DUR_5,MENU_ID_VDOEDT_SET_DUR,0,
                                SHOW,NONMOVEABLE,1,STR_ID_VDOEDT_IMG_DUR_5,0));

    /* 3.19 Frame Edit Option */
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_FRAME,
                                0,
                                4,
                                MENU_ID_VDOEDT_FRAME_SEL,
                                MENU_ID_VDOEDT_FRAME_TXT,
                                MENU_ID_VDOEDT_FRAME_EDT,
                                MENU_ID_VDOEDT_FRAME_CLEAR,
                                SHOW,
                                0,
                                1,
                                STR_ID_VDOEDT_FRAME,
                                0));

    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_FRAME_CLEAR, MENU_ID_VDOEDT_FRAME, 0,
                                SHOW, NONMOVEABLE, 1, STR_ID_VDOEDT_REMOV_FRMTXT, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_FRAME_SEL, MENU_ID_VDOEDT_FRAME, 0,
                                SHOW, NONMOVEABLE, 1, STR_ID_VDOEDT_TXT_CHOOSE_FRM, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_FRAME_TXT, MENU_ID_VDOEDT_FRAME, 0,
                                SHOW, NONMOVEABLE, 1, STR_ID_VDOEDT_TXT, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_VDOEDT_FRAME_EDT, MENU_ID_VDOEDT_FRAME, 0,
                                SHOW, NONMOVEABLE, 1, STR_ID_VDOEDT_FRAME_EDT, 0));

    ADD_APPLICATION_MENUITEM((
        MENU_ID_VDOEDT_SAVE,
        0,
        2,
        MENU_ID_VDOEDT_2_PHONE,
        MENU_ID_VDOEDT_2_CARD,
        SHOW,
        0,
        1,
        STR_GLOBAL_SAVE,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VDOEDT_2_PHONE,
        MENU_ID_VDOEDT_SAVE,
        0,
        SHOW,
        NONMOVEABLE,
        1,
        STR_ID_VDOEDT_2_PHONE,
        0));
    ADD_APPLICATION_MENUITEM((
        MENU_ID_VDOEDT_2_CARD,
        MENU_ID_VDOEDT_SAVE,
        0,
        SHOW,
        NONMOVEABLE,
        1,
        STR_ID_VDOEDT_2_CARD,
        0));
//#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */
} 


/*****************************************************************************
* FUNCTION
*	PopulateVdoEdtAudRes
* DESCRIPTION
*	Generate Video Editor audio Resource
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateVdoEdtAudRes(void)
{
#ifdef __MMI_VDOEDT_D5T_AUD__    
 	ADD_APPLICATION_AUDIO2(AUD_ID_VDOEDT_AUD1, CUST_ADO_PATH"\\\\VideoEditor\\\\vdoedt01.m4a", "Horror");
	ADD_APPLICATION_AUDIO2(AUD_ID_VDOEDT_AUD2, CUST_ADO_PATH"\\\\VideoEditor\\\\vdoedt02.m4a", "Sci-fi");
#endif /* __MMI_VDOEDT_CUSTOM_AUD__ */

    /* silence */
    ADD_APPLICATION_AUDIO2(AUD_ID_VDOEDT_SILENT, CUST_ADO_PATH"\\\\VideoEditor\\\\silence.m4a", "silent");
}



/*****************************************************************************
* FUNCTION
*	PopulateVdoEdtRes
* DESCRIPTION
*	Generate Video Editor Menu Resource
* PARAMETERS
*	void
* RETURNS
*	void
* GLOBALS AFFECTED
*	NIL
*****************************************************************************/
void PopulateVdoEdtRes(void)
{
    PopulateVdoEdtStrRes();
    PopulateVdoEdtImgRes();
    PopulateVdoEdtAudRes();
    PopulateVdoEdtMenuItemRes();    
}



#endif /* __MMI_VIDEO_EDITOR__ */

#endif /* __MMI_VIDEO_EDITOR__ */


