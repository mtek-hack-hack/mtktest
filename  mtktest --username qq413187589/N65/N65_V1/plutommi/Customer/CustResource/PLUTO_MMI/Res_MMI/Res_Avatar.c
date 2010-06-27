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
 *  Res_Avatar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  3D Avatar Applications v0.1
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "MMI_features.h"
#include "MMIDataType.h"
#if defined(__MMI_AVATAR__)

#include "lcd_sw_inc.h"
#include "AvatarResDef.h"       /* include this for avatar related resource IDs */

#include "PopulateRes.h"
#include "CustResDef.h"



/***************************************************************************** 
* Typedef 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  PopulateAvatarStrRes
 * DESCRIPTION
 *  Generate Avatar application related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateAvatarStrRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*********** BarcodeReader App *************/
    ADD_APPLICATION_STRING2(STR_ID_AVATAR_APP_NAME, "Avatar", "[Avatar App Name]");

    ADD_APPLICATION_STRING2(STR_ID_AVATAR_OPTION_MENU_NEW, "New", "[new]");
    ADD_APPLICATION_STRING2(STR_ID_AVATAR_OPTION_MENU_PLAY, "Play", "[play]");
    ADD_APPLICATION_STRING2(STR_ID_AVATAR_OPTION_MENU_RENAME, "Rename", "[rename]");    
    ADD_APPLICATION_STRING2(STR_ID_AVATAR_OPTION_MENU_EXIT, "Exit", "[exit]");    

    ADD_APPLICATION_STRING2(STR_ID_AVATAR_EMPTY_AVATAR_NAME, "Empty String!","[empty]");
    ADD_APPLICATION_STRING2(STR_ID_AVATAR_EXIT_EDITOR_WITHOUT_SVAE, "Exit without save?", "[exit wo save]");    

    ADD_APPLICATION_STRING2(STR_ID_AVATAR_OPTION_TOGGLE, "Switch", "[Switch]");    
    ADD_APPLICATION_STRING2(STR_ID_AVATAR_DELETING, "Deleting", "[Deleting]");
}


/*****************************************************************************
 * FUNCTION
 *  PopulateAvatarImgRes
 * DESCRIPTION
 *  Generate Avatar related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateAvatarImgRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* define avatar image resource path */
    #define AVATAR_ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\AVATAR\\\\"
    #define AVATAR_OSD_PATH AVATAR_ROOT_PATH"\\\\OSD\\\\"
    #define AVATAR_LIP_PATH AVATAR_ROOT_PATH"\\\\MOUTH\\\\"
    #define AVATAR_EYE_PATH AVATAR_ROOT_PATH"\\\\EYES\\\\"
    #define AVATAR_DECORATION_PATH AVATAR_ROOT_PATH"\\\\DECORATION\\\\"
    #define AVATAR_FACE_PATH AVATAR_ROOT_PATH"\\\\FACE\\\\"
    #define AVATAR_BROW_PATH AVATAR_ROOT_PATH"\\\\BROWS\\\\"
    #define AVATAR_DRESS_PATH AVATAR_ROOT_PATH"\\\\DRESS\\\\"
    #define AVATAR_M3D_PATH AVATAR_ROOT_PATH"\\\\M3D\\\\"

    /**********************************************
    * M3D file
    **********************************************/
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_EDITOR_ANIMATION, AVATAR_M3D_PATH"EDITOR.M3D", "IMG_ID_AVATAR_M3D_EDITOR_ANIMATION");
    
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_HEAD, AVATAR_M3D_PATH"HEAD.M3D", "IMG_ID_AVATAR_M3D_HEAD");
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_HAIR, AVATAR_M3D_PATH"HAIR.M3D", "IMG_ID_AVATAR_M3D_HAIR");
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_BODY, AVATAR_M3D_PATH"BODY.M3D", "IMG_ID_AVATAR_M3D_BODY");   
   
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_ANIMATION_1, AVATAR_M3D_PATH"1.M3D", "IMG_ID_AVATAR_M3D_ANIMATION_1");
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_ANIMATION_2, AVATAR_M3D_PATH"2.M3D", "IMG_ID_AVATAR_M3D_ANIMATION_2");
    ADD_APPLICATION_IMAGE3(IMG_ID_AVATAR_M3D_ANIMATION_3, AVATAR_M3D_PATH"3.M3D", "IMG_ID_AVATAR_M3D_ANIMATION_3");
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    /******************************************
    * App
    *******************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_APP_ICON,
        AVATAR_ROOT_PATH"3d_AVATAR.pbm",
        "IMG_ID_AVATAR_APP_ICON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_AVATAR_ICON,
        AVATAR_ROOT_PATH"AVATAR_ICON.gif",
        "IMG_ID_AVATAR_AVATAR_ICON");

   /******************************************
   * OSD related
   *******************************************/
#ifdef __MMI_TOUCH_SCREEN__
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BG,
        AVATAR_OSD_PATH"M3D_BG.gif",
        "IMG_ID_AVATAR_BG");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_SELECTED,
        AVATAR_OSD_PATH"M3D_HEAD.gif",
        "IMG_ID_AVATAR_HEAD_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_SELECTED,
        AVATAR_OSD_PATH"M3D_HAIR.gif",
        "IMG_ID_AVATAR_HAIR_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_SELECTED,
        AVATAR_OSD_PATH"M3D_EYE.gif",
        "IMG_ID_AVATAR_EYE_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_SELECTED,
        AVATAR_OSD_PATH"M3D_BROWs.gif",
        "IMG_ID_AVATAR_BROW_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_SELECTED,
        AVATAR_OSD_PATH"M3D_mouth.gif",
        "IMG_ID_AVATAR_LIP_SELECTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_SELECTED,
        AVATAR_OSD_PATH"M3D_DECORATION.gif",
        "IMG_ID_AVATAR_DECORATION_SELECTED");
        
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BODY_SELECTED,
        AVATAR_OSD_PATH"M3D_CLOTHE.gif",
        "IMG_ID_AVATAR_BODY_SELECTED");


#else
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BG,
        AVATAR_OSD_PATH"M3D_BG_NT.gif",
        "IMG_ID_AVATAR_BG");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_SELECTED,
        AVATAR_OSD_PATH"M3D_HEAD_NT.gif",
        "IMG_ID_AVATAR_HEAD_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_SELECTED,
        AVATAR_OSD_PATH"M3D_HAIR_NT.gif",
        "IMG_ID_AVATAR_HAIR_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_SELECTED,
        AVATAR_OSD_PATH"M3D_EYE_NT.gif",
        "IMG_ID_AVATAR_EYE_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_SELECTED,
        AVATAR_OSD_PATH"M3D_BROWs_NT.gif",
        "IMG_ID_AVATAR_BROW_SELECTED");
    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_SELECTED,
        AVATAR_OSD_PATH"M3D_mouth_NT.gif",
        "IMG_ID_AVATAR_LIP_SELECTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_SELECTED,
        AVATAR_OSD_PATH"M3D_DECORATION_NT.gif",
        "IMG_ID_AVATAR_DECORATION_SELECTED");
        
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BODY_SELECTED,
        AVATAR_OSD_PATH"M3D_CLOTHE_NT.gif",
        "IMG_ID_AVATAR_BODY_SELECTED");

#endif





    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_STRETCH_ON,
        AVATAR_OSD_PATH"M3D_aright_UP.gif",
        "IMG_ID_AVATAR_STRETCH_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_STRETCH_SELECTED,
        AVATAR_OSD_PATH"M3D_aright_sel.gif",
        "IMG_ID_AVATAR_STRETCH_SELECTED");
   
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_SHRINK_ON,
        AVATAR_OSD_PATH"M3D_aleft_up.gif",
        "IMG_ID_AVATAR_SHRINK_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_SHRINK_SELECTED,
        AVATAR_OSD_PATH"M3D_aleft_sel.gif",
        "IMG_ID_AVATAR_SHRINK_SEELCTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MOVEUP_ON,
        AVATAR_OSD_PATH"M3D_aup_up.gif",
        "IMG_ID_AVATAR_MOVEUP_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MOVEUP_SELECTED,
        AVATAR_OSD_PATH"M3D_aup_sel.gif",
        "IMG_ID_AVATAR_MOVEUP_SELECTED");

    
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MOVEDOWN_ON,
        AVATAR_OSD_PATH"M3D_adown_up.gif",
        "IMG_ID_AVATAR_MOVEDOWN_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MOVEDOWN_SELECTED,
        AVATAR_OSD_PATH"M3D_adown_sel.gif",
        "IMG_ID_AVATAR_MOVEDOWN_SELECTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MAGNIFY_ON,
        AVATAR_OSD_PATH"M3D_slideup_up.gif",
        "IMG_ID_AVATAR_MAGNIFY_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MAGNIFY_SELECTED,
        AVATAR_OSD_PATH"M3D_slideup_sel.gif",
        "IMG_ID_AVATAR_MAGNIFY_SELECTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MINIFY_ON,
        AVATAR_OSD_PATH"M3D_slidedown_up.gif",
        "IMG_ID_AVATAR_MINIFY_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_MINIFY_SELECTED,
        AVATAR_OSD_PATH"M3D_slidedown_sel.gif",
        "IMG_ID_AVATAR_MINIFY_SELECTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_COLOR_ON,
        AVATAR_OSD_PATH"M3D_color.gif",
        "IMG_ID_AVATAR_COLOR_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_COLOR_SELECTED,
        AVATAR_OSD_PATH"M3D_color.gif",
        "IMG_ID_AVATAR_COLOR_SELECTED");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_RARROW_SELECTED,
        AVATAR_OSD_PATH"M3D_RSeldown.gif",
        "IMG_ID_AVATAR_RARROW_SELECTED");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_RARROW_ON,
        AVATAR_OSD_PATH"M3D_RSelup.gif",
        "IMG_ID_AVATAR_RARROW_ON");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LARROW_SELECTED,
        AVATAR_OSD_PATH"M3D_LSeldown.gif",
        "IMG_ID_AVATAR_LARROW_SELECTED");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LARROW_ON,
        AVATAR_OSD_PATH"M3D_LSelup.gif",
        "IMG_ID_AVATAR_LARROW_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOP_RARROW_SELECTED,
        AVATAR_OSD_PATH"M3D_TOP_RIGHT_DOWN.PBM",
        "IMG_ID_AVATAR_RARROW_SELECTED");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOP_RARROW_ON,
        AVATAR_OSD_PATH"M3D_TOP_RIGHT_UP.PBM",
        "IMG_ID_AVATAR_RARROW_ON");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOP_LARROW_SELECTED,
        AVATAR_OSD_PATH"M3D_TOP_LEFT_DOWN.PBM",
        "IMG_ID_AVATAR_LARROW_SELECTED");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOP_LARROW_ON,
        AVATAR_OSD_PATH"M3D_TOP_LEFT_UP.PBM",
        "IMG_ID_AVATAR_LARROW_ON");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOGGLE1_SELECTED,
        AVATAR_OSD_PATH"M3D_TOGGLE1_SELECTED.PBM",
        "IMG_ID_AVATAR_TOGGLE1_SELECTED");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOGGLE1_ON,
        AVATAR_OSD_PATH"M3D_TOGGLE1_ON.PBM",
        "IMG_ID_AVATAR_TOGGLE1_ON");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOGGLE2_SELECTED,
        AVATAR_OSD_PATH"M3D_TOGGLE2_SELECTED.PBM",
        "IMG_ID_AVATAR_TOGGLE2_SELECTED");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_TOGGLE2_ON,
        AVATAR_OSD_PATH"M3D_TOGGLE2_ON.PBM",
        "IMG_ID_AVATAR_TOGGLE2_ON");


   /******************************************
   * Conponent icon on OSD
   *******************************************/

    /* head */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_1,
        AVATAR_OSD_PATH"M3D_head01.gif",
        "IMG_ID_AVATAR_HEAD_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_2,
        AVATAR_OSD_PATH"M3D_head02.gif",
        "IMG_ID_AVATAR_HEAD_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_3,
        AVATAR_OSD_PATH"M3D_head03.gif",
        "IMG_ID_AVATAR_HEAD_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_4,
        AVATAR_OSD_PATH"M3D_head04.gif",
        "IMG_ID_AVATAR_HEAD_4");

    /* hair */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_1,
        AVATAR_OSD_PATH"M3D_hair01.gif",
        "IMG_ID_AVATAR_HAIR_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_2,
        AVATAR_OSD_PATH"M3D_hair02.gif",
        "IMG_ID_AVATAR_HAIR_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_3,
        AVATAR_OSD_PATH"M3D_hair03.gif",
        "IMG_ID_AVATAR_HAIR_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_4,
        AVATAR_OSD_PATH"M3D_hair04.gif",
        "IMG_ID_AVATAR_HAIR_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_5,
        AVATAR_OSD_PATH"M3D_hair05.gif",
        "IMG_ID_AVATAR_HAIR_5");
    
    /* face */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_FACE_1,
        AVATAR_OSD_PATH"M3D_face01.gif",
        "IMG_ID_AVATAR_FACE_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_FACE_2,
        AVATAR_OSD_PATH"M3D_face02.gif",
        "IMG_ID_AVATAR_FACE_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_FACE_3,
        AVATAR_OSD_PATH"M3D_face03.gif",
        "IMG_ID_AVATAR_FACE_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_FACE_4,
        AVATAR_OSD_PATH"M3D_face04.gif",
        "IMG_ID_AVATAR_FACE_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_FACE_5,
        AVATAR_OSD_PATH"M3D_face05.gif",
        "IMG_ID_AVATAR_FACE_5");


    /* dress */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DRESS_1,
        AVATAR_OSD_PATH"M3D_CLOTHE01.gif",
        "IMG_ID_AVATAR_DRESS_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DRESS_2,
        AVATAR_OSD_PATH"M3D_clothe02.gif",
        "IMG_ID_AVATAR_DRESS_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DRESS_3,
        AVATAR_OSD_PATH"M3D_clothe03.gif",
        "IMG_ID_AVATAR_DRESS_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DRESS_4,
        AVATAR_OSD_PATH"M3D_clothe04.gif",
        "IMG_ID_AVATAR_DRESS_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DRESS_5,
        AVATAR_OSD_PATH"M3D_clothe05.gif",
        "IMG_ID_AVATAR_DRESS_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DRESS_6,
        AVATAR_OSD_PATH"M3D_clothe06.gif",
        "IMG_ID_AVATAR_DRESS_6");

    /* eye */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_1,
        AVATAR_OSD_PATH"M3D_eye01.gif",
        "IMG_ID_AVATAR_EYE_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_2,
        AVATAR_OSD_PATH"M3D_eye02.gif",
        "IMG_ID_AVATAR_EYE_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_3,
        AVATAR_OSD_PATH"M3D_eye03.gif",
        "IMG_ID_AVATAR_EYE_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_4,
        AVATAR_OSD_PATH"M3D_eye04.gif",
        "IMG_ID_AVATAR_EYE_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_5,
        AVATAR_OSD_PATH"M3D_eye05.gif",
        "IMG_ID_AVATAR_EYE_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_6,
        AVATAR_OSD_PATH"M3D_eye06.gif",
        "IMG_ID_AVATAR_EYE_6");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_7,
        AVATAR_OSD_PATH"M3D_eye07.gif",
        "IMG_ID_AVATAR_EYE_7");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_8,
        AVATAR_OSD_PATH"M3D_eye08.gif",
        "IMG_ID_AVATAR_EYE_8");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_9,
        AVATAR_OSD_PATH"M3D_eye09.gif",
        "IMG_ID_AVATAR_EYE_9");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_10,
        AVATAR_OSD_PATH"M3D_eye10.gif",
        "IMG_ID_AVATAR_EYE_10");

    /* LIP */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_1,
        AVATAR_OSD_PATH"M3D_mouth01.gif",
        "IMG_ID_AVATAR_LIP_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_2,
        AVATAR_OSD_PATH"M3D_mouth02.gif",
        "IMG_ID_AVATAR_LIP_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_3,
        AVATAR_OSD_PATH"M3D_mouth03.gif",
        "IMG_ID_AVATAR_LIP_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_4,
        AVATAR_OSD_PATH"M3D_mouth04.gif",
        "IMG_ID_AVATAR_LIP_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_5,
        AVATAR_OSD_PATH"M3D_mouth05.gif",
        "IMG_ID_AVATAR_LIP_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_6,
        AVATAR_OSD_PATH"M3D_mouth06.gif",
        "IMG_ID_AVATAR_LIP_6");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_7,
        AVATAR_OSD_PATH"M3D_mouth07.gif",
        "IMG_ID_AVATAR_LIP_7");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_8,
        AVATAR_OSD_PATH"M3D_mouth08.gif",
        "IMG_ID_AVATAR_LIP_8");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_9,
        AVATAR_OSD_PATH"M3D_mouth09.gif",
        "IMG_ID_AVATAR_LIP_9");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_10,
        AVATAR_OSD_PATH"M3D_mouth10.gif",
        "IMG_ID_AVATAR_LIP_10");

    /* brow */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_1,
        AVATAR_OSD_PATH"M3D_brows01.gif",
        "IMG_ID_AVATAR_BROW_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_2,
        AVATAR_OSD_PATH"M3D_brows02.gif",
        "IMG_ID_AVATAR_BROW_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_3,
        AVATAR_OSD_PATH"M3D_brows03.gif",
        "IMG_ID_AVATAR_BROW_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_4,
        AVATAR_OSD_PATH"M3D_brows04.gif",
        "IMG_ID_AVATAR_BROW_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_5,
        AVATAR_OSD_PATH"M3D_brows05.gif",
        "IMG_ID_AVATAR_BROW_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_6,
        AVATAR_OSD_PATH"M3D_brows06.gif",
        "IMG_ID_AVATAR_BROW_6");

    /* clothes */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BODY_1,
        AVATAR_OSD_PATH"M3D_body01.gif",
        "IMG_ID_AVATAR_BODY_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BODY_2,
        AVATAR_OSD_PATH"M3D_body02.gif",
        "IMG_ID_AVATAR_BODY_2");
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
#endif
    /* decoration */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_1,
        AVATAR_OSD_PATH"M3D_decoration01.gif",
        "IMG_ID_AVATAR_DECORATION_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_2,
        AVATAR_OSD_PATH"M3D_decoration02.gif",
        "IMG_ID_AVATAR_DECORATION_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_3,
        AVATAR_OSD_PATH"M3D_decoration03.gif",
        "IMG_ID_AVATAR_DECORATION_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_4,
        AVATAR_OSD_PATH"M3D_decoration04.gif",
        "IMG_ID_AVATAR_DECORATION_4");

   /******************************************
   * Conponent icon (SELECTED)on OSD
   *******************************************/

    /* head */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhead01.gif",
        "IMG_ID_AVATAR_HEAD_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhead02.gif",
        "IMG_ID_AVATAR_HEAD_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_3_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhead03.gif",
        "IMG_ID_AVATAR_HEAD_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HEAD_4_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhead04.gif",
        "IMG_ID_AVATAR_HEAD_4");

    /* hair */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhair01.gif",
        "IMG_ID_AVATAR_HAIR_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhair02.gif",
        "IMG_ID_AVATAR_HAIR_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_3_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhair03.gif",
        "IMG_ID_AVATAR_HAIR_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_4_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhair04.gif",
        "IMG_ID_AVATAR_HAIR_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_HAIR_5_SELECTED,
        AVATAR_OSD_PATH"M3D_Lhair05.gif",
        "IMG_ID_AVATAR_HAIR_5");
    

    /* eye */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye01.gif",
        "IMG_ID_AVATAR_EYE_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye02.gif",
        "IMG_ID_AVATAR_EYE_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_3_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye03.gif",
        "IMG_ID_AVATAR_EYE_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_4_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye04.gif",
        "IMG_ID_AVATAR_EYE_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_5_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye05.gif",
        "IMG_ID_AVATAR_EYE_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_6_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye06.gif",
        "IMG_ID_AVATAR_EYE_6");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_7_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye07.gif",
        "IMG_ID_AVATAR_EYE_7");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_8_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye08.gif",
        "IMG_ID_AVATAR_EYE_8");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_9_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye09.gif",
        "IMG_ID_AVATAR_EYE_9");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_EYE_10_SELECTED,
        AVATAR_OSD_PATH"M3D_Leye10.gif",
        "IMG_ID_AVATAR_EYE_10");

    /* LIP */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth01.gif",
        "IMG_ID_AVATAR_LIP_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth02.gif",
        "IMG_ID_AVATAR_LIP_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_3_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth03.gif",
        "IMG_ID_AVATAR_LIP_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_4_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth04.gif",
        "IMG_ID_AVATAR_LIP_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_5_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth05.gif",
        "IMG_ID_AVATAR_LIP_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_6_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth06.gif",
        "IMG_ID_AVATAR_LIP_6");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_7_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth07.gif",
        "IMG_ID_AVATAR_LIP_7");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_8_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth08.gif",
        "IMG_ID_AVATAR_LIP_8");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_9_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth09.gif",
        "IMG_ID_AVATAR_LIP_9");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_LIP_10_SELECTED,
        AVATAR_OSD_PATH"M3D_Lmouth10.gif",
        "IMG_ID_AVATAR_LIP_10");

    /* brow */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbrows01.gif",
        "IMG_ID_AVATAR_BROW_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbrows02.gif",
        "IMG_ID_AVATAR_BROW_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_3_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbrows03.gif",
        "IMG_ID_AVATAR_BROW_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_4_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbrows04.gif",
        "IMG_ID_AVATAR_BROW_4");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_5_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbrows05.gif",
        "IMG_ID_AVATAR_BROW_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BROW_6_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbrows06.gif",
        "IMG_ID_AVATAR_BROW_6");

    /* body */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BODY_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbody01.gif",
        "IMG_ID_AVATAR_BODY_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_BODY_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Lbody02.gif",
        "IMG_ID_AVATAR_BODY_2");

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
#endif 
    /* decoration */
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_1_SELECTED,
        AVATAR_OSD_PATH"M3D_Ldecoration01.gif",
        "IMG_ID_AVATAR_DECORATION_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_2_SELECTED,
        AVATAR_OSD_PATH"M3D_Ldecoration02.gif",
        "IMG_ID_AVATAR_DECORATION_2");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_3_SELECTED,
        AVATAR_OSD_PATH"M3D_Ldecoration03.gif",
        "IMG_ID_AVATAR_DECORATION_3");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_DECORATION_4_SELECTED,
        AVATAR_OSD_PATH"M3D_Ldecoration04.gif",
        "IMG_ID_AVATAR_DECORATION_4");

    /*************************************************
    * Materials - 1. Mouth
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_1,
        AVATAR_LIP_PATH"mouth0101.png",
        "IMG_ID_AVATAR_M_LIP_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_1_2,
        AVATAR_LIP_PATH"mouth0102.png",
        "IMG_ID_AVATAR_M_LIP_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_1_3,
        AVATAR_LIP_PATH"mouth0103.png",
        "IMG_ID_AVATAR_M_LIP_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_1_4,
        AVATAR_LIP_PATH"mouth0104.png",
        "IMG_ID_AVATAR_M_LIP_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_1_5,
        AVATAR_LIP_PATH"mouth0105.png",
        "IMG_ID_AVATAR_M_LIP_1");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_2,
        AVATAR_LIP_PATH"mouth0201.png",
        "IMG_ID_AVATAR_M_LIP_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_2_2,
        AVATAR_LIP_PATH"mouth0202.png",
        "IMG_ID_AVATAR_M_LIP_2_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_2_3,
        AVATAR_LIP_PATH"mouth0203.png",
        "IMG_ID_AVATAR_M_LIP_2_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_2_4,
        AVATAR_LIP_PATH"mouth0204.png",
        "IMG_ID_AVATAR_M_LIP_2_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_2_5,
        AVATAR_LIP_PATH"mouth0205.png",
        "IMG_ID_AVATAR_M_LIP_2_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_3,
        AVATAR_LIP_PATH"mouth0301.png",
        "IMG_ID_AVATAR_M_LIP_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_3_2,
        AVATAR_LIP_PATH"mouth0302.png",
        "IMG_ID_AVATAR_M_LIP_3_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_3_3,
        AVATAR_LIP_PATH"mouth0303.png",
        "IMG_ID_AVATAR_M_LIP_3_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_3_4,
        AVATAR_LIP_PATH"mouth0304.png",
        "IMG_ID_AVATAR_M_LIP_3_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_3_5,
        AVATAR_LIP_PATH"mouth0305.png",
        "IMG_ID_AVATAR_M_LIP_3_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_4,
        AVATAR_LIP_PATH"mouth0401.png",
        "IMG_ID_AVATAR_M_LIP_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_4_2,
        AVATAR_LIP_PATH"mouth0402.png",
        "IMG_ID_AVATAR_M_LIP_4_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_4_3,
        AVATAR_LIP_PATH"mouth0403.png",
        "IMG_ID_AVATAR_M_LIP_4_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_4_4,
        AVATAR_LIP_PATH"mouth0404.png",
        "IMG_ID_AVATAR_M_LIP_4_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_4_5,
        AVATAR_LIP_PATH"mouth0405.png",
        "IMG_ID_AVATAR_M_LIP_4_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_5,
        AVATAR_LIP_PATH"mouth0501.png",
        "IMG_ID_AVATAR_M_LIP_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_5_2,
        AVATAR_LIP_PATH"mouth0502.png",
        "IMG_ID_AVATAR_M_LIP_5_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_5_3,
        AVATAR_LIP_PATH"mouth0503.png",
        "IMG_ID_AVATAR_M_LIP_5_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_5_4,
        AVATAR_LIP_PATH"mouth0504.png",
        "IMG_ID_AVATAR_M_LIP_5_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_5_5,
        AVATAR_LIP_PATH"mouth0505.png",
        "IMG_ID_AVATAR_M_LIP_5_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_6,
        AVATAR_LIP_PATH"mouth0601.png",
        "IMG_ID_AVATAR_M_LIP_6");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_6_2,
        AVATAR_LIP_PATH"mouth0602.png",
        "IMG_ID_AVATAR_M_LIP_6_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_6_3,
        AVATAR_LIP_PATH"mouth0603.png",
        "IMG_ID_AVATAR_M_LIP_6_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_6_4,
        AVATAR_LIP_PATH"mouth0604.png",
        "IMG_ID_AVATAR_M_LIP_6_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_6_5,
        AVATAR_LIP_PATH"mouth0605.png",
        "IMG_ID_AVATAR_M_LIP_6_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_7,
        AVATAR_LIP_PATH"mouth0701.png",
        "IMG_ID_AVATAR_M_LIP_7");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_7_2,
        AVATAR_LIP_PATH"mouth0702.png",
        "IMG_ID_AVATAR_M_LIP_7_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_7_3,
        AVATAR_LIP_PATH"mouth0703.png",
        "IMG_ID_AVATAR_M_LIP_7_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_7_4,
        AVATAR_LIP_PATH"mouth0704.png",
        "IMG_ID_AVATAR_M_LIP_7_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_7_5,
        AVATAR_LIP_PATH"mouth0705.png",
        "IMG_ID_AVATAR_M_LIP_7_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_8,
        AVATAR_LIP_PATH"mouth0801.png",
        "IMG_ID_AVATAR_M_LIP_8");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_8_2,
        AVATAR_LIP_PATH"mouth0802.png",
        "IMG_ID_AVATAR_M_LIP_8_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_8_3,
        AVATAR_LIP_PATH"mouth0803.png",
        "IMG_ID_AVATAR_M_LIP_8_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_8_4,
        AVATAR_LIP_PATH"mouth0804.png",
        "IMG_ID_AVATAR_M_LIP_8_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_8_5,
        AVATAR_LIP_PATH"mouth0805.png",
        "IMG_ID_AVATAR_M_LIP_8_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_9,
        AVATAR_LIP_PATH"mouth0901.png",
        "IMG_ID_AVATAR_M_LIP_9");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_9_2,
        AVATAR_LIP_PATH"mouth0902.png",
        "IMG_ID_AVATAR_M_LIP_9_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_9_3,
        AVATAR_LIP_PATH"mouth0903.png",
        "IMG_ID_AVATAR_M_LIP_9_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_9_4,
        AVATAR_LIP_PATH"mouth0904.png",
        "IMG_ID_AVATAR_M_LIP_9_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_9_5,
        AVATAR_LIP_PATH"mouth0905.png",
        "IMG_ID_AVATAR_M_LIP_9_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_10,
        AVATAR_LIP_PATH"mouth1001.png",
        "IMG_ID_AVATAR_M_LIP_10");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_10_2,
        AVATAR_LIP_PATH"mouth1002.png",
        "IMG_ID_AVATAR_M_LIP_10_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_10_3,
        AVATAR_LIP_PATH"mouth1003.png",
        "IMG_ID_AVATAR_M_LIP_10_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_10_4,
        AVATAR_LIP_PATH"mouth1004.png",
        "IMG_ID_AVATAR_M_LIP_10_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_LIP_10_5,
        AVATAR_LIP_PATH"mouth1005.png",
        "IMG_ID_AVATAR_M_LIP_10_5");

    /*************************************************
    * Materials - 2 Face
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_FACE_1,
        AVATAR_FACE_PATH"face01.png",
        "IMG_ID_AVATAR_M_FACE_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_FACE_2,
        AVATAR_FACE_PATH"face02.png",
        "IMG_ID_AVATAR_M_FACE_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_FACE_3,
        AVATAR_FACE_PATH"face03.png",
        "IMG_ID_AVATAR_M_FACE_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_FACE_4,
        AVATAR_FACE_PATH"face04.png",
        "IMG_ID_AVATAR_M_FACE_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_FACE_5,
        AVATAR_FACE_PATH"face05.png",
        "IMG_ID_AVATAR_M_FACE_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_FACE_6,
        AVATAR_FACE_PATH"face06.png",
        "IMG_ID_AVATAR_M_FACE_6");
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
#endif
    /*************************************************
    * Materials - 3 Clothes
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DRESS_1,
        AVATAR_DRESS_PATH"clothe01.gif",
        "IMG_ID_AVATAR_M_DRESS_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DRESS_2,
        AVATAR_DRESS_PATH"clothe02.gif",
        "IMG_ID_AVATAR_M_DRESS_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DRESS_3,
        AVATAR_DRESS_PATH"clothe03.gif",
        "IMG_ID_AVATAR_M_DRESS_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DRESS_4,
        AVATAR_DRESS_PATH"clothe04.gif",
        "IMG_ID_AVATAR_M_DRESS_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DRESS_5,
        AVATAR_DRESS_PATH"clothe05.gif",
        "IMG_ID_AVATAR_M_DRESS_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DRESS_6,
        AVATAR_DRESS_PATH"clothe06.gif",
        "IMG_ID_AVATAR_M_DRESS_6");
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
#endif
    /*************************************************
    * Materials - 4.1 left Brows
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_1,
        AVATAR_BROW_PATH"brows01_L01.png",
        "IMG_ID_AVATAR_M_L_BROWS_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_1_2,
        AVATAR_BROW_PATH"brows01_L02.png",
        "IMG_ID_AVATAR_M_L_BROWS_1_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_1_3,
        AVATAR_BROW_PATH"brows01_L03.png",
        "IMG_ID_AVATAR_M_L_BROWS_1_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_1_4,
        AVATAR_BROW_PATH"brows01_L04.png",
        "IMG_ID_AVATAR_M_L_BROWS_1_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_1_5,
        AVATAR_BROW_PATH"brows01_L05.png",
        "IMG_ID_AVATAR_M_L_BROWS_1_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_2,
        AVATAR_BROW_PATH"brows02_L01.png",
        "IMG_ID_AVATAR_M_L_BROWS_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_2_2,
        AVATAR_BROW_PATH"brows02_L02.png",
        "IMG_ID_AVATAR_M_L_BROWS_2_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_2_3,
        AVATAR_BROW_PATH"brows02_L03.png",
        "IMG_ID_AVATAR_M_L_BROWS_2_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_2_4,
        AVATAR_BROW_PATH"brows02_L04.png",
        "IMG_ID_AVATAR_M_L_BROWS_2_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_2_5,
        AVATAR_BROW_PATH"brows02_L05.png",
        "IMG_ID_AVATAR_M_L_BROWS_2_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_3,
        AVATAR_BROW_PATH"brows03_L01.png",
        "IMG_ID_AVATAR_M_L_BROWS_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_3_2,
        AVATAR_BROW_PATH"brows03_L02.png",
        "IMG_ID_AVATAR_M_L_BROWS_3_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_3_3,
        AVATAR_BROW_PATH"brows03_L03.png",
        "IMG_ID_AVATAR_M_L_BROWS_3_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_3_4,
        AVATAR_BROW_PATH"brows03_L04.png",
        "IMG_ID_AVATAR_M_L_BROWS_3_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_3_5,
        AVATAR_BROW_PATH"brows03_L05.png",
        "IMG_ID_AVATAR_M_L_BROWS_3_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_4,
        AVATAR_BROW_PATH"brows04_L01.png",
        "IMG_ID_AVATAR_M_L_BROWS_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_4_2,
        AVATAR_BROW_PATH"brows04_L02.png",
        "IMG_ID_AVATAR_M_L_BROWS_4_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_4_3,
        AVATAR_BROW_PATH"brows04_L03.png",
        "IMG_ID_AVATAR_M_L_BROWS_4_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_4_4,
        AVATAR_BROW_PATH"brows04_L04.png",
        "IMG_ID_AVATAR_M_L_BROWS_4_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_4_5,
        AVATAR_BROW_PATH"brows04_L05.png",
        "IMG_ID_AVATAR_M_L_BROWS_4_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_5,
        AVATAR_BROW_PATH"brows05_L01.png",
        "IMG_ID_AVATAR_M_L_BROWS_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_5_2,
        AVATAR_BROW_PATH"brows05_L02.png",
        "IMG_ID_AVATAR_M_L_BROWS_5_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_5_3,
        AVATAR_BROW_PATH"brows05_L03.png",
        "IMG_ID_AVATAR_M_L_BROWS_5_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_5_4,
        AVATAR_BROW_PATH"brows05_L04.png",
        "IMG_ID_AVATAR_M_L_BROWS_5_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_5_5,
        AVATAR_BROW_PATH"brows05_L05.png",
        "IMG_ID_AVATAR_M_L_BROWS_5_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_6,
        AVATAR_BROW_PATH"brows06_L01.png",
        "IMG_ID_AVATAR_M_L_BROWS_6");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_6_2,
        AVATAR_BROW_PATH"brows06_L02.png",
        "IMG_ID_AVATAR_M_L_BROWS_6_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_6_3,
        AVATAR_BROW_PATH"brows06_L03.png",
        "IMG_ID_AVATAR_M_L_BROWS_6_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_6_4,
        AVATAR_BROW_PATH"brows06_L04.png",
        "IMG_ID_AVATAR_M_L_BROWS_6_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_BROWS_6_5,
        AVATAR_BROW_PATH"brows06_L05.png",
        "IMG_ID_AVATAR_M_L_BROWS_6_5");

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
#endif
    /*************************************************
    * Materials - 4.2 RIGHT Brows
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_1,
        AVATAR_BROW_PATH"brows01_R01.png",
        "IMG_ID_AVATAR_M_R_BROWS_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_1_2,
        AVATAR_BROW_PATH"brows01_R02.png",
        "IMG_ID_AVATAR_M_R_BROWS_1_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_1_3,
        AVATAR_BROW_PATH"brows01_R03.png",
        "IMG_ID_AVATAR_M_R_BROWS_1_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_1_4,
        AVATAR_BROW_PATH"brows01_R04.png",
        "IMG_ID_AVATAR_M_R_BROWS_1_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_1_5,
        AVATAR_BROW_PATH"brows01_R05.png",
        "IMG_ID_AVATAR_M_R_BROWS_1_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_2,
        AVATAR_BROW_PATH"brows02_R01.png",
        "IMG_ID_AVATAR_M_R_BROWS_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_2_2,
        AVATAR_BROW_PATH"brows02_R02.png",
        "IMG_ID_AVATAR_M_R_BROWS_2_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_2_3,
        AVATAR_BROW_PATH"brows02_R03.png",
        "IMG_ID_AVATAR_M_R_BROWS_2_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_2_4,
        AVATAR_BROW_PATH"brows02_R04.png",
        "IMG_ID_AVATAR_M_R_BROWS_2_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_2_5,
        AVATAR_BROW_PATH"brows02_R05.png",
        "IMG_ID_AVATAR_M_R_BROWS_2_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_3,
        AVATAR_BROW_PATH"brows03_R01.png",
        "IMG_ID_AVATAR_M_R_BROWS_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_3_2,
        AVATAR_BROW_PATH"brows03_R02.png",
        "IMG_ID_AVATAR_M_R_BROWS_3_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_3_3,
        AVATAR_BROW_PATH"brows03_R03.png",
        "IMG_ID_AVATAR_M_R_BROWS_3_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_3_4,
        AVATAR_BROW_PATH"brows03_R04.png",
        "IMG_ID_AVATAR_M_R_BROWS_3_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_3_5,
        AVATAR_BROW_PATH"brows03_R05.png",
        "IMG_ID_AVATAR_M_R_BROWS_3_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_4,
        AVATAR_BROW_PATH"brows04_R01.png",
        "IMG_ID_AVATAR_M_R_BROWS_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_4_2,
        AVATAR_BROW_PATH"brows04_R02.png",
        "IMG_ID_AVATAR_M_R_BROWS_4_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_4_3,
        AVATAR_BROW_PATH"brows04_R03.png",
        "IMG_ID_AVATAR_M_R_BROWS_4_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_4_4,
        AVATAR_BROW_PATH"brows04_R04.png",
        "IMG_ID_AVATAR_M_R_BROWS_4_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_4_5,
        AVATAR_BROW_PATH"brows04_R05.png",
        "IMG_ID_AVATAR_M_R_BROWS_4_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_5,
        AVATAR_BROW_PATH"brows05_R01.png",
        "IMG_ID_AVATAR_M_R_BROWS_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_5_2,
        AVATAR_BROW_PATH"brows05_R02.png",
        "IMG_ID_AVATAR_M_R_BROWS_5_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_5_3,
        AVATAR_BROW_PATH"brows05_R03.png",
        "IMG_ID_AVATAR_M_R_BROWS_5_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_5_4,
        AVATAR_BROW_PATH"brows05_R04.png",
        "IMG_ID_AVATAR_M_R_BROWS_5_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_5_5,
        AVATAR_BROW_PATH"brows05_R05.png",
        "IMG_ID_AVATAR_M_R_BROWS_5_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_6,
        AVATAR_BROW_PATH"brows06_R01.png",
        "IMG_ID_AVATAR_M_R_BROWS_6");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_6_2,
        AVATAR_BROW_PATH"brows06_R02.png",
        "IMG_ID_AVATAR_M_R_BROWS_6_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_6_3,
        AVATAR_BROW_PATH"brows06_R03.png",
        "IMG_ID_AVATAR_M_R_BROWS_6_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_6_4,
        AVATAR_BROW_PATH"brows06_R04.png",
        "IMG_ID_AVATAR_M_R_BROWS_6_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_BROWS_6_5,
        AVATAR_BROW_PATH"brows06_R05.png",
        "IMG_ID_AVATAR_M_R_BROWS_6_5");

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
#endif
    /*************************************************
    * Materials - 5.1 LEFT Eye
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_1,
        AVATAR_EYE_PATH"eye01_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_1_2,
        AVATAR_EYE_PATH"eye01_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_1_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_1_3,
        AVATAR_EYE_PATH"eye01_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_1_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_1_4,
        AVATAR_EYE_PATH"eye01_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_1_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_1_5,
        AVATAR_EYE_PATH"eye01_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_1_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_2,
        AVATAR_EYE_PATH"eye02_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_2_2,
        AVATAR_EYE_PATH"eye02_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_2_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_2_3,
        AVATAR_EYE_PATH"eye02_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_2_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_2_4,
        AVATAR_EYE_PATH"eye02_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_2_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_2_5,
        AVATAR_EYE_PATH"eye02_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_2_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_3,
        AVATAR_EYE_PATH"eye03_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_3_2,
        AVATAR_EYE_PATH"eye03_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_3_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_3_3,
        AVATAR_EYE_PATH"eye03_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_3_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_3_4,
        AVATAR_EYE_PATH"eye03_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_3_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_3_5,
        AVATAR_EYE_PATH"eye03_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_3_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_4,
        AVATAR_EYE_PATH"eye04_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_4_2,
        AVATAR_EYE_PATH"eye04_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_4_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_4_3,
        AVATAR_EYE_PATH"eye04_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_4_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_4_4,
        AVATAR_EYE_PATH"eye04_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_4_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_4_5,
        AVATAR_EYE_PATH"eye04_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_4_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_5,
        AVATAR_EYE_PATH"eye05_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_5_2,
        AVATAR_EYE_PATH"eye05_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_5_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_5_3,
        AVATAR_EYE_PATH"eye05_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_5_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_5_4,
        AVATAR_EYE_PATH"eye05_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_5_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_5_5,
        AVATAR_EYE_PATH"eye05_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_5_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_6,
        AVATAR_EYE_PATH"eye06_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_6");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_6_2,
        AVATAR_EYE_PATH"eye06_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_6_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_6_3,
        AVATAR_EYE_PATH"eye06_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_6_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_6_4,
        AVATAR_EYE_PATH"eye06_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_6_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_6_5,
        AVATAR_EYE_PATH"eye06_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_6_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_7,
        AVATAR_EYE_PATH"eye07_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_7");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_7_2,
        AVATAR_EYE_PATH"eye07_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_7_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_7_3,
        AVATAR_EYE_PATH"eye07_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_7_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_7_4,
        AVATAR_EYE_PATH"eye07_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_7_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_7_5,
        AVATAR_EYE_PATH"eye07_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_7_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_8,
        AVATAR_EYE_PATH"eye08_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_8");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_8_2,
        AVATAR_EYE_PATH"eye08_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_8_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_8_3,
        AVATAR_EYE_PATH"eye08_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_8_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_8_4,
        AVATAR_EYE_PATH"eye08_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_8_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_8_5,
        AVATAR_EYE_PATH"eye08_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_8_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_9,
        AVATAR_EYE_PATH"eye09_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_9");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_9_2,
        AVATAR_EYE_PATH"eye09_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_9_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_9_3,
        AVATAR_EYE_PATH"eye09_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_9_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_9_4,
        AVATAR_EYE_PATH"eye09_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_9_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_9_5,
        AVATAR_EYE_PATH"eye09_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_9_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_10,
        AVATAR_EYE_PATH"eye10_L01.png",
        "IMG_ID_AVATAR_M_L_EYE_10");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_10_2,
        AVATAR_EYE_PATH"eye10_L02.png",
        "IMG_ID_AVATAR_M_L_EYE_10_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_10_3,
        AVATAR_EYE_PATH"eye10_L03.png",
        "IMG_ID_AVATAR_M_L_EYE_10_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_10_4,
        AVATAR_EYE_PATH"eye10_L04.png",
        "IMG_ID_AVATAR_M_L_EYE_10_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_L_EYE_10_5,
        AVATAR_EYE_PATH"eye10_L05.png",
        "IMG_ID_AVATAR_M_L_EYE_10_5");
    /*************************************************
    * Materials - 5.2 RIGHT Eye
    **************************************************/
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_1,
        AVATAR_EYE_PATH"eye01_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_1_2,
        AVATAR_EYE_PATH"eye01_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_1_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_1_3,
        AVATAR_EYE_PATH"eye01_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_1_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_1_4,
        AVATAR_EYE_PATH"eye01_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_1_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_1_5,
        AVATAR_EYE_PATH"eye01_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_1_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_2,
        AVATAR_EYE_PATH"eye02_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_2_2,
        AVATAR_EYE_PATH"eye02_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_2_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_2_3,
        AVATAR_EYE_PATH"eye02_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_2_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_2_4,
        AVATAR_EYE_PATH"eye02_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_2_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_2_5,
        AVATAR_EYE_PATH"eye02_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_2_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_3,
        AVATAR_EYE_PATH"eye03_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_3_2,
        AVATAR_EYE_PATH"eye03_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_3_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_3_3,
        AVATAR_EYE_PATH"eye03_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_3_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_3_4,
        AVATAR_EYE_PATH"eye03_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_3_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_3_5,
        AVATAR_EYE_PATH"eye03_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_3_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_4,
        AVATAR_EYE_PATH"eye04_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_4_2,
        AVATAR_EYE_PATH"eye04_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_4_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_4_3,
        AVATAR_EYE_PATH"eye04_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_4_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_4_4,
        AVATAR_EYE_PATH"eye04_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_4_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_4_5,
        AVATAR_EYE_PATH"eye04_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_4_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_5,
        AVATAR_EYE_PATH"eye05_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_5");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_5_2,
        AVATAR_EYE_PATH"eye05_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_5_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_5_3,
        AVATAR_EYE_PATH"eye05_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_5_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_5_4,
        AVATAR_EYE_PATH"eye05_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_5_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_5_5,
        AVATAR_EYE_PATH"eye05_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_5_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_6,
        AVATAR_EYE_PATH"eye06_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_6");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_6_2,
        AVATAR_EYE_PATH"eye06_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_6_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_6_3,
        AVATAR_EYE_PATH"eye06_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_6_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_6_4,
        AVATAR_EYE_PATH"eye06_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_6_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_6_5,
        AVATAR_EYE_PATH"eye06_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_6_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_7,
        AVATAR_EYE_PATH"eye07_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_7");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_7_2,
        AVATAR_EYE_PATH"eye07_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_7_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_7_3,
        AVATAR_EYE_PATH"eye07_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_7_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_7_4,
        AVATAR_EYE_PATH"eye07_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_7_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_7_5,
        AVATAR_EYE_PATH"eye07_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_7_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_8,
        AVATAR_EYE_PATH"eye08_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_8");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_8_2,
        AVATAR_EYE_PATH"eye08_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_8_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_8_3,
        AVATAR_EYE_PATH"eye08_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_8_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_8_4,
        AVATAR_EYE_PATH"eye08_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_8_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_8_5,
        AVATAR_EYE_PATH"eye08_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_8_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_9,
        AVATAR_EYE_PATH"eye09_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_9");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_9_2,
        AVATAR_EYE_PATH"eye09_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_9_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_9_3,
        AVATAR_EYE_PATH"eye09_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_9_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_9_4,
        AVATAR_EYE_PATH"eye09_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_9_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_9_5,
        AVATAR_EYE_PATH"eye09_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_9_5");

    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_10,
        AVATAR_EYE_PATH"eye10_R01.png",
        "IMG_ID_AVATAR_M_R_EYE_10");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_10_2,
        AVATAR_EYE_PATH"eye10_R02.png",
        "IMG_ID_AVATAR_M_R_EYE_10_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_10_3,
        AVATAR_EYE_PATH"eye10_R03.png",
        "IMG_ID_AVATAR_M_R_EYE_10_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_10_4,
        AVATAR_EYE_PATH"eye10_R04.png",
        "IMG_ID_AVATAR_M_R_EYE_10_4");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_R_EYE_10_5,
        AVATAR_EYE_PATH"eye10_R05.png",
        "IMG_ID_AVATAR_M_R_EYE_10_5");
    /*************************************************
    * Materials - 6 Decoration
    **************************************************/
//    ADD_APPLICATION_IMAGE2(
//        IMG_ID_AVATAR_M_DECORATION_1,
//        AVATAR_DECORATION_PATH"decoration01.gif",
//        "IMG_ID_AVATAR_M_DECORATION_1");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DECORATION_2,
        AVATAR_DECORATION_PATH"decoration02.gif",
        "IMG_ID_AVATAR_M_DECORATION_2");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DECORATION_3,
        AVATAR_DECORATION_PATH"decoration03.gif",
        "IMG_ID_AVATAR_M_DECORATION_3");
    ADD_APPLICATION_IMAGE2(
        IMG_ID_AVATAR_M_DECORATION_4,
        AVATAR_DECORATION_PATH"decoration04.gif",
        "IMG_ID_AVATAR_M_DECORATION_4");

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
#endif

}


/*****************************************************************************
 * FUNCTION
 *  PopulateAvatarMenuRes
 * DESCRIPTION
 *  Generate Avatar related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateAvatarMenuRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*********** Avatar App *************/
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
#else
    ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR, MAIN_MENU_FUNANDGAMES_MENUID, 0,
#endif
                              SHOW, MOVEABLEACROSSPARENT | SHORTCUTABLE, 1, STR_ID_AVATAR_APP_NAME,
                              IMG_ID_AVATAR_APP_ICON));

	/*********** Option Menu *************/
	ADD_APPLICATION_MENUITEM((	MENU_ID_AVATAR_OPTION, 
										0,
										6,
										MENU_ID_AVATAR_OPTION_NEW,
										MENU_ID_AVATAR_OPTION_EDIT,
										MENU_ID_AVATAR_OPTION_PLAY,
										MENU_ID_AVATAR_OPTION_DELETE,
										MENU_ID_AVATAR_OPTION_DELETE_ALL,
										MENU_ID_AVATAR_OPTION_RENAME,
										0, 
										0, 
										1,
										STR_GLOBAL_OPTIONS,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_OPTION_NEW, MENU_ID_AVATAR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_AVATAR_OPTION_MENU_NEW,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_OPTION_EDIT, MENU_ID_AVATAR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_EDIT,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_OPTION_PLAY, MENU_ID_AVATAR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_AVATAR_OPTION_MENU_PLAY,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_OPTION_DELETE, MENU_ID_AVATAR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_DELETE,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_OPTION_DELETE_ALL, MENU_ID_AVATAR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_DELETE_ALL,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_OPTION_RENAME, MENU_ID_AVATAR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_AVATAR_OPTION_MENU_RENAME,0));

    /********** Editor Option Menu ************/
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR_OPTION, 
										0,
										2,
										MENU_ID_AVATAR_EDITOR_OPTION_SAVE,
										MENU_ID_AVATAR_EDITOR_OPTION_EXIT,
										0, 
										0, 
										1,
										STR_GLOBAL_OPTIONS,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR_OPTION_SAVE, MENU_ID_AVATAR_EDITOR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_SAVE,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR_OPTION_EXIT, MENU_ID_AVATAR_EDITOR_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_AVATAR_OPTION_MENU_EXIT,0));
    

    ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR_RENAME_OPTION,
                                0,
                                2,
                                MENU_ID_AVATAR_EDITOR_RENAME_DONE,
                                MENU_ID_AVATAR_EDITOR_RENAME_INPUT_METHOD,
                                SHOW,
                                0,
                                1,
                                STR_GLOBAL_OPTIONS,
                                0));

    ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR_RENAME_DONE, MENU_ID_AVATAR_EDITOR_RENAME_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_DONE,0));    
    ADD_APPLICATION_MENUITEM((MENU_ID_AVATAR_EDITOR_RENAME_INPUT_METHOD, MENU_ID_AVATAR_EDITOR_RENAME_OPTION,0,
                                SHOW,NONMOVEABLE,1,STR_GLOBAL_INPUT_METHOD,0));        

    
}


/*****************************************************************************
 * FUNCTION
 *  PopulateAvatarRes
 * DESCRIPTION
 *  Generate Avatar related resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateAvatarRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PopulateAvatarStrRes();
    PopulateAvatarImgRes();
    PopulateAvatarMenuRes();
}
#endif /* defined(__MMI_AVATAR__) */ 

