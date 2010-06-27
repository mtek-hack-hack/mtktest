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
 *   resource_video_skins.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video customization file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VIDEO_EDITOR__)

#include "PixtelDataTypes.h"
#include "gdi_lcd_config.h"
#include "MMI_features_video.h"
#include "resource_vdoedt_skins.h"


/***************************************************************************** 
*
* Customizable OSD Skin     
* [176x220]
* [240x320]
*
*****************************************************************************/

#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***************************************************************************** 
*
* [176x220]
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 176X220 Video Editor Main Screen skin                                    */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {0, 0,176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,205},             /* icon_lsk_pos */
        {145,205},               /* icon_rsk_pos */                   
        {88,203},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{13,164,0,0},              /*empty     */
        {13,164,0,0},               /*full      */
        {TRUE, 163,162},              /*forward   */
        {TRUE, 0,162}},           /*rewind    */
        /*status*/
        {{TRUE,13,148},             /* audio        */
        {TRUE,29,148},             /* frame        */
        {TRUE,45,148},             /* in effect    */
        {TRUE,61,148}},            /* out effect   */
        /*edit bar*/
        {{13,174,0, 0},              /* editbar empty*/
        {13,173, 0, 0},
        {{2,2,26,21},         /* shot 1       */
        {32,2,26,21},         /* shot 2       */
        {62,2,26,21},         /* shot 3       */
        {92,2,26,21},         /* shot 4       */
        {122,2,26,21}}},      /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,117,148},         /* h */
         {TRUE,124,148},         /* h */
        {TRUE,131,148},         /* : */
        {TRUE,133,148},         /* m */
        {TRUE,140,148},         /* m */
        {TRUE,147,148},         /* : */
        {TRUE,149,148},         /* S */
        {TRUE,156,148}}         /* S */
    };
    /****************************************************************************/
    /* 176x220 Video Editor Cut/FrameEdit Screen skin                           */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {0, 0, 176,144},
        /* cut bar      */
        {{5, 156, 0, 0},
         {5, 156, 0, 0},
         {5, 156, 0, 0},
//        {TRUE, 165, 145},            /* cut out cursor */
        {TRUE, 164, 145, 0, 0}, 
        {TRUE, 122, 182},            /* cut out label */
        {TRUE,  98, 182},            /* cut out arrow*/
        {TRUE, 143, 182},
//        {TRUE,   0, 165},            /* cut in cursor*/
        {TRUE, 0, 165, 0, 0},
        {TRUE,  42, 182},            /* cut in label */
        {TRUE,  16, 182},            /* cut in arrow*/
        {TRUE,  61, 182}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,205},             /* icon_lsk_pos */
        {140,205},               /* icon_rsk_pos */                   
        {88,203},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */            
    };
    /****************************************************************************/
    /* 176x220 Video Editor Frame selection Screen skin                         */
    /****************************************************************************/  

    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {0, 37, 176, 144},
        /* 2 arrow key */
        {TRUE, 70, 182},
        {TRUE, 90, 182},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */
        {64,205},             /* icon_lsk_pos */
        {180,205},               /* icon_rsk_pos */
        {88,203},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */
    };
 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***************************************************************************** 
*
* [240x320]
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 240x320 Video Editor Main Screen skin                                    */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {32,33,176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,300},             /* icon_lsk_pos */
        {200,300},               /* icon_rsk_pos */                   
        {120,300},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{24,215},              /*empty     */
        {24,215},               /*full      */
        {TRUE, 219,215},          /*forward   */
        {TRUE, 5,215}},        /*rewind    */
        /*status*/
        {{TRUE,215,55},            /* audio        */
        {TRUE,215,80},             /* frame        */
        {TRUE, 7, 30},             /* in effect    */
        {TRUE,215,30}},            /* out effect   */
        /*edit bar*/
        {{24, 238, 0, 0},              /* editbar empty*/
        {24,  238, 0, 0},
        {{2,5,35,33},         /* shot 1       */
        {41,5,35,33},         /* shot 2       */
        {79,5,35,33},         /* shot 3       */
        {117,5,35,33},        /* shot 4       */
        {156,5,35,33}}},      /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,83,187},         /* h */
         {TRUE,95,187},         /* h */
        {TRUE,107,187},         /* : */
        {TRUE,112,187},         /* m */
        {TRUE,124,187},         /* m */
        {TRUE,136,187},         /* : */                
        {TRUE,141,187},         /* S */
        {TRUE,153,187}}         /* S */    
    };
    /****************************************************************************/
    /* 240x320 Video Editor Cut/FrameEdit Screen skin                           */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {29, 30, 176,144},
        /* cut bar      */
        {{15, 212, 0, 0},
         {15, 212, 0, 0},
         {15, 212, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 215, 190, 0, 0},
        {TRUE, 170, 263},
        {TRUE, 141, 268},
        {TRUE, 208, 268},
        //{TRUE,   9, 243},
        {TRUE, 6, 243, 0, 0},
        {TRUE,  46, 263},
        {TRUE,  15, 268},
        {TRUE,  82, 268}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,300},             /* icon_lsk_pos */
        {198,300},               /* icon_rsk_pos */                   
        {120,300},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */            
    };
    /****************************************************************************/
    /* 240x320 Video Editor Frame selection Screen skin                         */
    /****************************************************************************/  

    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {32, 69, 176, 144},
        /* 2 arrow key */
        {TRUE, 40, 232},
        {TRUE, 160, 232},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */
        {2,300},             /* icon_lsk_pos */
        {198,300},               /* icon_rsk_pos */
        {120,300},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */
    };
#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
/***************************************************************************** 
*
* [320x240]  Landscape
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 320x240 landscape Video Editor Main Screen skin                          */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {73 , 4, 176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,216},             /* icon_lsk_pos */
        {280,216},               /* icon_rsk_pos */                   
        {160,216},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{50,157},              /*empty     */
        {50,157},               /*full      */
        {TRUE, 273,154},          /*forward   */
        {TRUE, 23,154}},        /*rewind    */
        /*status*/
        {{TRUE,45,51},            /* audio        */
        {TRUE, 45,122},             /* frame        */
        {TRUE, 45, 75},             /* in effect    */
        {TRUE, 45, 99}},            /* out effect   */
        /*edit bar*/
        {{53, 172, 0, 0},              /* editbar empty*/
         {53, 172, 0, 0},
        {{3, 2,40,32},         /* shot 1       */
        {45, 2,40,32},         /* shot 2       */
        {87, 2,40,32},         /* shot 3       */
        {129,2,40,32},        /* shot 4       */
        {171,2,40,32}}},      /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,253,126},         /* h */
         {TRUE,262,126},         /* h */
        {TRUE,271,126},         /* : */
        {TRUE,274,126},         /* m */
        {TRUE,283,126},         /* m */
        {TRUE,292,126},         /* : */                
        {TRUE,295,126},         /* S */
        {TRUE,304,126}}         /* S */    
    };

    /****************************************************************************/
    /* 320x240 landscape Video Editor Cut/FrameEdit Screen skin                 */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {73, 4, 176,144},
        /* cut bar      */
        {{20, 171, 0, 0},
         {20, 171, 0, 0},
         {20, 171, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 289, 152, 0, 0}, /* out cursor*/
        {TRUE, 272, 89},       /* out icon*/
        {TRUE, 265, 114},       /* left arrow */
        {TRUE, 286, 114},       /* right arrow */
        //{TRUE,   9, 243},
        {TRUE,  11, 191, 0, 0},
        {TRUE, 272, 26},
        {TRUE, 265, 53},
        {TRUE, 286, 53}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,216},             /* icon_lsk_pos */
        {280,216},               /* icon_rsk_pos */                   
        {160,216},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */        
    };
    
    /****************************************************************************/
    /* 320x240 landscape Video Editor Frame selection Screen skin               */
    /****************************************************************************/  
    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {73 , 4, 176, 144},
        /* 2 arrow key */
        {TRUE, 111, 169},
        {TRUE, 190, 169},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,216},             /* icon_lsk_pos */
        {280,216},               /* icon_rsk_pos */                   
        {160,216},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */

    };


#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
    
#endif /* __MMI_VIDEO_EDITOR__ */

