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
#include "MMI_features.h"
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)

#include "PixtelDataTypes.h"
#include "gdi_lcd_config.h"
#include "MMI_features_video.h"
#include "resource_video_skins.h"


/***************************************************************************** 
*
* Customizable OSD Skin     
* [128x128]
* [128x160]
* [176x220]
*
*****************************************************************************/



#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
/***************************************************************************** 
*
* [128x128]
*
*****************************************************************************/

    /* 
        1. Video Recorder 
        2. Video Player
    */
    
    /***************************************************************************** 
    * 128x128 Video Recoder Skin
    *****************************************************************************/
    vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
    {
        /****** bg ******/
        {{0,0,0,0},         /* region 0 - not used */
         {0,0,0,0}},        /* region 1 - not used */            
        /****** title ******/
        {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
         {0,0,0,0},
         {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
        /****** preview_wnd ******/
        {{12,3,104,85}},
        /****** panel ******/
        {{59,98},           /* ev */
         {87,99},           /* ev_inc */
         {82,99},           /* ev_dec */                
         {96,98},           /* zoom */
         {119,98},          /* zoom_inc */
         {119,103},         /* zoom_dec */               
         {14,100},          /* timer */
         {11,98},           /* timer_bg */            
         {92,89}},          /* state */
        /****** status ******/
        {TRUE,{11,3,100,18},
         {TRUE,16,2},       /* nigth icon */
         {TRUE,2,2},        /* led highlight icon */
         {TRUE,37,2},       /* record aud icon */   
         {FALSE,0,0},       /* size limit icon */
         {FALSE,0,0}},      /* time limit icon */
        /****** softkey ******/
        {FALSE,             /* is_lsk_icon */
         FALSE,             /* is_rsk_icon */
         TRUE,              /* is_ck_icon */                 
         {0,0},                 /* icon_lsk_pos */
         {0,0},                 /* icon_rsk_pos */                  
         {54,111},          /* icon_ck_pos */                           
         {0,110,128,18},
         {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
         {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
        /****** hint ******/
        {FALSE,{0,0,0,0},
         {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
    };
    /* End of 128x128 Video Recorder Skin */


    /***************************************************************************** 
    * 128x128 Video Player Skin
    *****************************************************************************/
    vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
    {
        /****** bg ******/
        {{0,0,0,0},             /* region 0 - not used */
         {0,0,0,0}},            /* region 1 - not used */          
        /****** title ******/
        {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
         {0,0,0,0},
         {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
        /****** play wnd ******/
        {{12,3,104,85}},
        /****** panel ******/
        {{67,98},               /* speed */
         {92,98},               /* speed_inc */
         {92,104},              /* speed_dec */             
         {101,97},              /* volume */        
         {118,98},              /* volume_inc */
         {118,104},             /* volume_dec */
         {22,100},              /* timer */
         {19,98},               /* timer_bg */               
         {12,91},               /* progress_fill */
         {12,91},               /* progress empty */
         {118,91},              /* progress_inc */
         {7,91},                /* progress_dec */
         {4,97},                /* snap */
         {0,0}},                /* fullscreen */                 
        /****** softkey ******/
        {FALSE,                 /* is_lsk_icon */
         FALSE,                 /* is_rsk_icon */
         TRUE,                  /* is_ck_icon */                 
         {0,0},                 /* icon_lsk_pos */
         {0,0},                 /* icon_rsk_pos */                  
         {54,110},              /* icon_ck_pos */                       
         {0,110,128,18},        /* rect */
         {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
         {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */               
        /****** loading ******/
        {{14,22,100,53},       /* rect */
         {14,22},              /* bg */
         TRUE,                 /* is_draw_progress */
         {21,41}}              /* progress */                      
    };
    /* End of 128x128 Video Player Skin */
    
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
/***************************************************************************** 
*
* [128x160]
*
*****************************************************************************/

    /* 
        1. Video Recorder Horizontal
        2. Video Recorder 
        3. Video Player Horizontal
        4. Video Player
        5. Video Play Fullscreen
    */
    
    #ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    
        /***************************************************************************** 
        * 128x160 [Horizontal] Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},         /* region 0 - not used */
             {0,0,0,0}},        /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** preview_wnd ******/
            {{5,6,176,144}},
            /****** panel ******/
            {{182,70},          /* ev */
             {197,84},          /* ev_inc */
             {182,84},          /* ev_dec */
             {182,32},          /* zoom */
             {197,46},          /* zoom_inc */
             {182,46},          /* zoom_dec */   
             {21,156},          /* timer */
             {0,0},             /* timer_bg */                
             {76,157}},         /* state */
            /****** status ******/
            {TRUE,{7,8,20,100},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {TRUE,              /* is_lsk_icon */
             TRUE,              /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {183,151},         /* icon_lsk_pos */
             {183,5},           /* icon_rsk_pos */              
             {183,130},         /* icon_ck_pos */   
             {0,0,0,0},         /* rect */ /* not used */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{41,58,110,40},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        };
        /* End of 128x160 Video Recorder Skin */

    #else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    
        /***************************************************************************** 
        * 128x160 Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},         /* region 0 - not used */
             {0,0,0,0}},        /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
            /****** preview_wnd ******/
            {{0,6,128,104}},
            /****** panel ******/
            {{55,125},          /* ev */
             {78,124},          /* ev_inc */
             {78,132},          /* ev_dec */                
             {90,125},          /* zoom */
             {115,124},         /* zoom_inc */
             {115,132},         /* zoom_dec */               
             {11,128},          /* timer */
             {8,125},           /* timer_bg */                
             {89,112}},         /* state */
            /****** status ******/
            {TRUE,{2,8,166,18},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */                  
             {55,142},          /* icon_ck_pos */                           
             {0,140,128,20},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{11,29,104,58},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        };
        /* End of 128x160 Video Recorder Skin */
        
    #endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */


    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        /***************************************************************************** 
        * 128x160 [Horizontal] Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},             /* region 0 - not used */
             {0,0,0,0}},            /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** play wnd ******/
            {{5,6,176,144}},
            /****** panel ******/
            {{182,69},              /* speed */
             {198,84},              /* speed_inc */
             {182,84},              /* speed_dec */             
             {182,31},              /* volume */
             {198,46},              /* volume_inc */
             {182,46},              /* volume_dec */             
             {23,156},              /* timer */
             {0,0},                 /* timer_bg */                
             {73,151},              /* progress fill */
             {73,151},              /* progress empty */
             {134,158},             /* progress_inc */
             {73,158},              /* progress_dec */  
             {183,109},             /* snap */
             {5,154}},              /* fullscreen */
            /****** softkey ******/
            {TRUE,                  /* is_lsk_icon */
             TRUE,                  /* is_rsk_icon */
             FALSE,                 /* is_ck_icon */                 
             {183,151},             /* icon_lsk_pos */
             {183,5},               /* icon_rsk_pos */                  
             {0,0},                 /* icon_ck_pos */
             {0,0,0,0},             /* rect */  /* not used */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */    
            /****** loading ******/
            {{14,33,100,53},       /* rect */
             {14,33},              /* bg */
             TRUE,                 /* is_draw_progress */
             {21,52}}              /* progress */                 
        };
        /* End of 128x160 Video Player Skin */
    
    #else  /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */
    
        /***************************************************************************** 
        * 128x160 Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},             /* region 0 - not used */
             {0,0,0,0}},            /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
            /****** play wnd ******/
            {{0,6,128,104}},
            /****** panel ******/
            {{62,125},              /* speed */
             {88,124},              /* speed_inc */
             {88,131},              /* speed_dec */             
             {98,125},              /* volume */        
             {116,124},             /* volume_inc */
             {116,131},             /* volume_dec */
             {30,128},              /* timer */
             {27,125},              /* timer_bg */                   
             {16,113},              /* progress_fill */
             {16,113},              /* progress empty */
             {115,112},             /* progress_inc */
             {2,112},               /* progress_dec */
             {14,125},              /* snap */
             {1,125}},              /* fullscreen */                 
            /****** softkey ******/
            {FALSE,                 /* is_lsk_icon */
             FALSE,                 /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {0,0},                 /* icon_lsk_pos */
             {0,0},                 /* icon_rsk_pos */                  
             {55,142},              /* icon_ck_pos */                       
             {0,140,128,20},        /* rect */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},    /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */     
            /****** loading ******/
            {{14,33,100,53},       /* rect */
             {14,33},              /* bg */
             TRUE,                 /* is_draw_progress */
             {21,56}}              /* progress */                 
        };
        /* End of 128x160 Video Player Skin */

    #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */


    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /***************************************************************************** 
        * 128x160 [FullScreen] Video Player Skin
        *****************************************************************************/
        vdoply_osd_fullscr_layout_struct g_vdoply_fullscr_osd_cntx =
        {
            /****** fullscreen panel ******/    
            {{2,98},            /* bg */
             {63,101},          /* speed */
             {78,100},          /* speed_inc */
             {78,112},          /* speed_dec */              
             {88,101},          /* volume */
             {97,100},          /* volume_inc */
             {97,112},          /* volume_dec */
             {10,113},          /* timer */
             {5,13},            /* timer_bg */                   
             {10,102},          /* progress fill */
             {10,102},          /* progress empty */
             {56,102},          /* progress_inc */
             {5,102}},          /* progress_dec */
            /****** fullscreen softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */                  
             {41,111},          /* icon_ck_pos */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */                
        };
        /* End of 128x160 fullscreen Video Player Skin */
    
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */


#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***************************************************************************** 
*
* [176x220]
*
*****************************************************************************/
    /* 
        1. Video Recorder Horizontal
        2. Video Recorder 
        3. Video Player Horizontal
        4. Video Player
        5. Video Play Fullscreen
    */
    
    #ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    
        /***************************************************************************** 
        * 176x220 [Horizontal] Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},         /* region 0 - not used */
             {0,0,0,0}},        /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** preview_wnd ******/
            {{5,6,176,144}},
            /****** panel ******/
            {{182,70},          /* ev */
             {197,84},          /* ev_inc */
             {182,84},          /* ev_dec */
             {182,32},          /* zoom */
             {197,46},          /* zoom_inc */
             {182,46},          /* zoom_dec */   
             {21,156},          /* timer */
             {19,153},          /* timer_bg */                
             {76,157}},         /* state */
            /****** status ******/
            {TRUE,{7,8,20,100},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {TRUE,              /* is_lsk_icon */
             TRUE,              /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {183,151},         /* icon_lsk_pos */
             {183,5},           /* icon_rsk_pos */              
             {183,130},         /* icon_ck_pos */   
             {0,0,0,0},         /* rect */ /* not used */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{41,58,110,40},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        };
        /* End of 176x220 Video Recorder Skin */

    #else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    
        /***************************************************************************** 
        * 176x220 Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},         /* region 0 - not used */
             {0,0,0,0}},        /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,TRUE,FALSE,
			 {4,0,172,19},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
            /****** preview_wnd ******/
            {{0,19,176,144}},
            /****** panel ******/
            {{92,182},          /* ev */
             {109,182},         /* ev_inc */
             {76,182},          /* ev_dec */                
             {142,182},         /* zoom */
             {159,182},         /* zoom_inc */
             {126,182},         /* zoom_dec */               
             {6,181},           /* timer */
             {4,179},           /* timer_bg */                
             {148,168}},        /* state */
            /****** status ******/
            {TRUE,{5,21,166,18},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */                  
             {80,201},          /* icon_ck_pos */                           
             {0,200,176,20},    /* rect */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{33,74,110,40},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        };
        /* End of 176x220 Video Recorder Skin */
        
    #endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */


    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        /***************************************************************************** 
        * 176x220 [Horizontal] Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},             /* region 0 - not used */
             {0,0,0,0}},            /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** play wnd ******/
            {{5,6,176,144}},
            /****** panel ******/
            {{182,69},              /* speed */
             {198,84},              /* speed_inc */
             {182,84},              /* speed_dec */             
             {182,31},              /* volume */
             {198,46},              /* volume_inc */
             {182,46},              /* volume_dec */             
             {23,156},              /* timer */
             {21,153},              /* timer_bg */                
             {73,151},              /* progress fill */
             {73,151},              /* progress empty */
             {134,158},             /* progress_inc */
             {73,158},              /* progress_dec */  
             {183,109},             /* snap */
             {5,154}},              /* fullscreen */
            /****** softkey ******/
            {TRUE,                  /* is_lsk_icon */
             TRUE,                  /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {183,151},             /* icon_lsk_pos */
             {183,5},               /* icon_rsk_pos */                  
             {183,130},             /* icon_ck_pos */   
             {0,0,0,0},          /* rect */ /* not used */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */               
            /****** loading ******/
            {{44,54,100,43},       /* rect */
             {44,54},              /* bg */
             TRUE,                 /* is_draw_progress */
             {51,73}}              /* progress */                 
        };
        /* End of 176x220 Video Player Skin */

    #else  /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    
        /***************************************************************************** 
        * 176x220 Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},             /* region 0 - not used */
             {0,0,0,0}},            /* region 1 - not used */              
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,TRUE,
             {4,0,172,19},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
            /****** play wnd ******/
            {{0,19,176,144}},
            /****** panel ******/
            {{102,181},             /* speed */
             {119,182},             /* speed_inc */
             {90,182},              /* speed_dec */             
             {145,181},             /* volume */        
             {162,182},             /* volume_inc */
             {133,182},             /* volume_dec */
             {39,183},              /* timer */
             {37,180},              /* timer_bg */                
             {20,169},              /* progress_fill */
             {20,169},              /* progress empty */
             {157,167},             /* progress_inc */
             {3,167},               /* progress_dec */
             {3,182},               /* snap */
             {20,182}},             /* fullscreen */                 
            /****** softkey ******/
            {FALSE,                 /* is_lsk_icon */
             FALSE,                 /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {0,0},                 /* icon_lsk_pos */
             {0,0},                 /* icon_rsk_pos */                  
             {80,201},              /* icon_ck_pos */                       
             {0,200,176,20},        /* rect */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */               
            /****** loading ******/
            {{38,66,100,43},       /* rect */
             {38,66},              /* bg */
             TRUE,                 /* is_draw_progress */
             {45,85}}              /* progress */                 
        };
        /* End of 176x220 Video Player Skin */

    #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */


    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /***************************************************************************** 
        * 176x220 [FullScreen] Video Player Skin
        *****************************************************************************/
        vdoply_osd_fullscr_layout_struct g_vdoply_fullscr_osd_cntx =
        {
            /****** fullscreen panel ******/    
            {{1,141},           /* bg */
             {99,145},          /* speed */
             {116,146},         /* speed_inc */
             {116,159},         /* speed_dec */              
             {129,145},         /* volume */
             {146,146},         /* volume_inc */
             {146,159},         /* volume_dec */
             {6,159},           /* timer */
             {4,157},           /* timer_bg */                
             {20,146},          /* progress fill */
             {20,146},          /* progress empty */
             {81,144},          /* progress_inc */
             {5,144}},          /* progress_dec */
            /****** fullscreen softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */                  
             {54,157},          /* icon_ck_pos */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */  
            /****** loading ******/
            {{61,68,100,43},        /* rect */
             {61,68},               /* bg */
             TRUE,                  /* is_draw_progress */
             {68,87}}               /* progress */                     
        };
        /* End of 176x220 fullscreen Video Player Skin */
    
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***************************************************************************** 
*
* [240x320]
*
*****************************************************************************/
    /* 
        1. Video Recorder Horizontal
        2. Video Recorder 
        3. Video Player Horizontal
        4. Video Player
        5. Video Play Fullscreen
    */
    
    #ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    
        /***************************************************************************** 
        * 240x320 [Horizontal] Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{248,0,72,240},    /* region 0 */
             {0,203,248,37}},   /* region 1 */               
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** preview_wnd ******/
            {{0,0,248,203}},
            /****** panel ******/
            {{259,91},          /* ev */
             {285,114},         /* ev_inc */
             {259,114},         /* ev_dec */
             {259,41},          /* zoom */
             {285,64},          /* zoom_inc */
             {259,64},          /* zoom_dec */   
             {44,213},          /* timer */
             {37,209},          /* timer_bg */                
             {127,215}},        /* state */
            /****** status ******/
            {TRUE,{16,11,20,100},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {TRUE,              /* is_lsk_icon */
             TRUE,              /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {259,208},         /* icon_lsk_pos */
             {259,8},           /* icon_rsk_pos */              
             {259,180},         /* icon_ck_pos */   
             {0,0,0,0},         /* rect */ /* not used */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{34,37,199,146},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        };
        /* End of 240x320 Video Recorder Skin */

    #else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    
        /***************************************************************************** 
        * 240x320 Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{0,0,240,27},      /* region 0 */
             {0,223,240,97}},   /* region 1 */        
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,TRUE,FALSE,
             {10,0,230,27},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
            /****** preview_wnd ******/
            {{0,27,240,196}},
            /****** panel ******/
            {{51,262},         /* ev */
             {102,258},         /* ev_inc */
             {37,258},          /* ev_dec */                
             {146,262},         /* zoom */
             {197,260},         /* zoom_inc */
             {132,260},         /* zoom_dec */               
             {102,235},          /* timer */
             {93,227},           /* timer_bg */                
             {167,232}},        /* state */
            /****** status ******/
            {TRUE,{5,33,166,18},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */                  
             {100,290},         /* icon_ck_pos */                           
             {0,296,240,25},    /* rect */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{26,57,189,139},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        }; //sk 8010
        /* End of 240x320 Video Recorder Skin */
        
    #endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */


    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        /***************************************************************************** 
        * 240x320 [Horizontal] Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{248,0,72,240},        /* region 0 */
             {0,203,248,37}},       /* region 1 */        
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** play wnd ******/
            {{0,0,248,203}},
            /****** panel ******/
            {{259,90},              /* speed */
             {285,113},             /* speed_inc */
             {259,113},             /* speed_dec */             
             {259,40},              /* volume */
             {285,63},              /* volume_inc */
             {259,63},              /* volume_dec */             
             {44,213},              /* timer */
             {37,209},              /* timer_bg */                
             {111,209},             /* progress fill */
             {111,209},             /* progress empty */
             {187,219},             /* progress_inc */
             {111,219},             /* progress_dec */  
             {259,141},             /* snap */
             {13,209}},             /* fullscreen */
            /****** softkey ******/
            {TRUE,                  /* is_lsk_icon */
             TRUE,                  /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {259,208},             /* icon_lsk_pos */
             {259,8},               /* icon_rsk_pos */                   
             {259,180},             /* icon_ck_pos */   
             {0,0,0,0},             /* rect */  /* not used */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** loading ******/
            {{63,79,143,45},       /* rect */
             {63,79},              /* bg */
             TRUE,                 /* is_draw_progress */
             {76,100}}             /* progress */             
        };
        /* End of 240x320 Video Player Skin */

    #else  /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    
        /***************************************************************************** 
        * 240x320 Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{0,0,240,27},          /* region 0 */
             {0,223,240,97}},       /* region 1 */
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,TRUE,
             {10,0,215,27},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
            /****** play wnd ******/
            {{0,27,240,196}},
            /****** panel ******/
            {{138,330},             /* speed */
             {164,330},             /* speed_inc */
             {123,330},             /* speed_dec */             
             {60,261},             /* volume */        
             {189,258},             /* volume_inc */
             {37,258},             /* volume_dec */
             {8,282},              /* timer */
             {48,330},              /* timer_bg */
             {60,282},              /* progress_fill */
             {60,282},              /* progress empty */
             {166,235},             /* progress_inc */
             {60,235},               /* progress_dec */
             {25,260},              /* snap */
             {207,3}},              /* fullscreen */                 
            /****** softkey ******/
            {FALSE,                 /* is_lsk_icon */
             FALSE,                 /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {0,0},                 /* icon_lsk_pos */
             {0,0},                 /* icon_rsk_pos */                  
             {113,235},             /* icon_ck_pos */                       
             {0,296,240,25},        /* rect */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */  
            /****** loading ******/
            {{49,102,143,45},       /* rect */
             {49,102},              /* bg */
             TRUE,                  /* is_draw_progress */
             {62,123}}              /* progress */
        };//sk 0810
        /* End of 240x320 Video Player Skin */

    #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */


    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /***************************************************************************** 
        * 240x320 [FullScreen] Video Player Skin
        *****************************************************************************/
        vdoply_osd_fullscr_layout_struct g_vdoply_fullscr_osd_cntx =
        {
            /****** fullscreen panel ******/    
            {{1,190},           /* bg */
             {137,194},         /* speed */
             {164,194},         /* speed_inc */
             {164,214},         /* speed_dec */              
             {184,194},         /* volume */
             {207,194},         /* volume_inc */
             {207,214},         /* volume_dec */
             {14,216},          /* timer */
             {6,212},           /* timer_bg */                
             {25,197},          /* progress fill */
             {25,197},          /* progress empty */
             {113,194},         /* progress_inc */
             {5,194}},          /* progress_dec */
            /****** fullscreen softkey ******/
            {FALSE,                 /* is_lsk_icon */
             FALSE,                 /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {0,0},                 /* icon_lsk_pos */
             {0,0},                 /* icon_rsk_pos */                  
             {80,212},              /* icon_ck_pos */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */                
            /****** loading ******/
            {{89,88,143,45},       /* rect */
             {89,88},              /* bg */
             TRUE,                 /* is_draw_progress */
             {102,109}}             /* progress */             
        };
        /* End of 240x320 fullscreen Video Player Skin */
    
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */

/* hongzhe.liu add start */
	#ifdef ANALOG_TV_SUPPORT
	/***************************************************************************** 
	* 240x320 analog tv Skin
	*****************************************************************************/
	//p_6226_m24_bw_z0155  调整电视界面坐标
	vdoply_osd_vdoply_layout_struct g_analog_tv_osd_cntx =
	{
		/****** bg ******/
            {{0,0,240,27},          /* region 0 */
             {0,223,240,97}},       /* region 1 */
		/****** title ******/
		{VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,TRUE,
		 {10,0,215,27},
		 {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
		/****** play wnd ******/
		{{0,26,240,198}},
		/****** panel ******/
		{
		{117,233},				/* channel */
		 {166,235},				/* channel_inc */
		 {60,235},				/* cnannel_dec */				
		 {60,261},				/* volume */
		 {190,258},				/* volume_inc */
		 {37,257},				/* volume_dec */	   		 
		 {92,265},  //ghw65				/* timer */
		 {0,0},					/* timer  bg*/		 
		 {59,251},				/* progress fill */
		 {59,251},				/* progress empty */
		 {168,262},				/* progress_inc */
		 {60,262},				/* progress_dec */	
		 {83,233},				/* snap */
		 {207,3}},				/* fullscreen */				 
		/****** softkey ******/
		{FALSE,					/* is_lsk_icon */
		  FALSE,					/* is_rsk_icon */
		 TRUE,					/* is_ck_icon */	 			 
		 {0,0}, 					/* icon_lsk_pos */
		 {0,0}, 					/* icon_rsk_pos */				 	
		 {110,229},				/* icon_ck_pos */						
		 {0,296,240,25}, 		/* rect */
			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},	/* lsk */
		 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},	/* rsk */ 	
		 /****** loading ******/
            {{70,103,100,43},       /* rect */
             {70,103},              /* bg */
             TRUE,                  /* is_draw_progress */
             {78,128}}              /* progress */		 	
	}; //sk 0810

//p_6226_m24_bw_z0163  使电视用的变量独立	
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
	
		/***************************************************************************** 
		* 240x320 [Horizontal] Video Recoder Skin
		*****************************************************************************/
		vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx02 =
		{
			/************************************/
			/* 			  BASIC SKIN 				*/
			/************************************/	
			 /****** bg ******/
            {{0,0,240,27},      /* region 0 */
             {0,223,240,97}},   /* region 1 */       
			/****** title ******/
			{VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
			 {0,0,0,0},
			 {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
			/****** preview_wnd ******/
			{{13,9,240,196}},
			/****** panel ******/
			{{258,90},			/* ev */
			 {284,113},			/* ev_inc */
		    {258,113},			/* ev_dec */
			 {258,40},			/* zoom */
			 {284,63},			/* zoom_inc */
			 {258,63},			/* zoom_dec */	 
	       {43,212},			/* timer */
  			 {126,215}},		/* state */
			/****** status ******/
			{TRUE,{16,11,20,100},
			 {TRUE,16,2},		/* nigth icon */
			 {TRUE,2,2},		/* led highlight icon */
			 {TRUE,37,2},		/* record aud icon */	
			 {FALSE,0,0},		/* size limit icon */
			 {FALSE,0,0}},		/* time limit icon */
			/****** softkey ******/
			{TRUE,				/* is_lsk_icon */
 			 TRUE,				/* is_rsk_icon */
			 TRUE,				/* is_ck_icon */	 			 
			 {258,207}, 		/* icon_lsk_pos */
			 {258,7}, 			/* icon_rsk_pos */			 	
			 {258,179}, 		/* icon_ck_pos */	
			 {0,0,0,0},			/* rect */ /* not used */
 			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},	/* lsk */
			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},	/* rsk */ 	
			/****** hint ******/
			{TRUE,{34,37,199,146},
 			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}	/* text_style */
		};
		/* End of 240x320 Video Recorder Skin */

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
	
		/***************************************************************************** 
		* 240x320 Video Recoder Skin
		*****************************************************************************/
		vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx02 =
		{
			/************************************/
			/* 			  BASIC SKIN 				*/
			/************************************/	
			 /****** bg ******/
            {{0,0,240,27},      /* region 0 */
             {0,223,240,97}},   /* region 1 */       	
			/****** title ******/
			{VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,TRUE,FALSE,
			 {10,0,240,27},
			 {255,255,255,0,0,0,VIDEO_TEXT_STYLE_BORDER}},
			/****** preview_wnd ******/
			{{0,27,240,196}},
			/****** panel ******/
			{{115,257},			/* ev */
			 {141,260},			/* ev_inc */
			 {94,260},			/* ev_dec */				
			 {187,257},			/* zoom */
			 {214,260},			/* zoom_inc */
			 {166,260},			/* zoom_dec */	  			 
	       {17,266},			/* timer */
  			 {187,230}},		/* state */
			/****** status ******/
			{TRUE,{5,33,166,18},
			 {TRUE,16,2},		/* nigth icon */
			 {TRUE,2,2},		/* led highlight icon */
			 {TRUE,37,2},		/* record aud icon */	
			 {FALSE,0,0},		/* size limit icon */
			 {FALSE,0,0}},		/* time limit icon */
			/****** softkey ******/
			{FALSE,				/* is_lsk_icon */
 			 FALSE,				/* is_rsk_icon */
			 TRUE,				/* is_ck_icon */	 			 
			 {0,0}, 				/* icon_lsk_pos */
			 {0,0}, 				/* icon_rsk_pos */				 	
			 {100,297}, 		/* icon_ck_pos */							
			 {0,296,240,25},	/* rect */
 			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},	/* lsk */
			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},	/* rsk */ 	
			/****** hint ******/
			{TRUE,{26,57,189,139},
 			 {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}	/* text_style */
		};
		/* End of 240x320 Video Recorder Skin */
		
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */

	#endif

/* hongzhe.liu add end */

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
/***************************************************************************** 
*
* [320x240]
*
*****************************************************************************/
    /* 
        1. Video Recorder 
        2. Video Player
    */
    
        /***************************************************************************** 
        * 320x240 Video Recoder Skin
        *****************************************************************************/
        vdorec_osd_vdorec_layout_struct g_vdorec_osd_cntx =
        {
            /****** bg ******/
            {{248,0,72,240},    /* region 0 */
             {0,203,248,37}},   /* region 1 */               
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** preview_wnd ******/
            {{52,6,219,181}},
            /****** panel ******/
            {{285,35},          /* ev */
             {298,64},          /* ev_inc */
             {284,64},          /* ev_dec */
             {285,123},         /* zoom */
             {285,152},         /* zoom_inc */
             {285,166},         /* zoom_dec */   
             {209,193},         /* timer */
             {203,190},         /* timer_bg */                
             {62,192}},         /* state */
            /****** status ******/
            {TRUE,{54,8,20,100},
             {TRUE,16,2},       /* nigth icon */
             {TRUE,2,2},        /* led highlight icon */
             {TRUE,37,2},       /* record aud icon */   
             {FALSE,0,0},       /* size limit icon */
             {FALSE,0,0}},      /* time limit icon */
            /****** softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             TRUE,              /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */              
             {138,213},         /* icon_ck_pos */   
             {0,212,320,28},    /* rect */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** hint ******/
            {TRUE,{62,23,199,146},
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* text_style */
        };
        /* End of 320x240 Video Recorder Skin */


        /***************************************************************************** 
        * 320x240 Video Player Skin
        *****************************************************************************/
        vdoply_osd_vdoply_layout_struct g_vdoply_osd_cntx =
        {
            /****** bg ******/
            {{0,0,0,0},        /* region 0 */ /* not using multi-region bg */
             {0,0,0,0}},       /* region 1 */ /* not using multi-region bg */       
            /****** title ******/
            {VIDEO_ALIGN_LEFT,VIDEO_ALIGN_CENTER,FALSE,FALSE,
             {0,0,0,0},
             {255,255,255,0,0,0,VIDEO_TEXT_STYLE_NORMAL}},
            /****** play wnd ******/
            {{52,6,219,181}},
            /****** panel ******/
            {{285,123},             /* speed */
             {286,152},             /* speed_inc */
             {286,166},             /* speed_dec */             
             {285,33},              /* volume */
             {286,64},              /* volume_inc */
             {286,78},              /* volume_dec */             
             {238,193},             /* timer */
             {232,190},             /* timer_bg */                
             {40,195},              /* progress fill */
             {40,195},              /* progress empty */
             {207,193},             /* progress_inc */
             {18,193},              /* progress_dec */  
             {12,76},               /* snap */
             {12,41}},              /* fullscreen */
            /****** softkey ******/
            {FALSE,                 /* is_lsk_icon */
             FALSE,                 /* is_rsk_icon */
             TRUE,                  /* is_ck_icon */                 
             {0,0},                 /* icon_lsk_pos */
             {0,0},                 /* icon_rsk_pos */                   
             {138,214},             /* icon_ck_pos */   
             {0,212,320,28},        /* rect */ 
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */   
            /****** loading ******/
            {{110,78,100,43},       /* rect */
             {110,78},              /* bg */
             TRUE,                  /* is_draw_progress */
             {117,97}}              /* progress */           
        };
        /* End of 320x240 Video Player Skin */


    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /***************************************************************************** 
        * 320x240 [FullScreen] Video Player Skin
        *****************************************************************************/
        vdoply_osd_fullscr_layout_struct g_vdoply_fullscr_osd_cntx =
        {
            /****** fullscreen panel ******/    
            {{0,0},             /* bg */
             {0,0},             /* speed */
             {0,0},             /* speed_inc */
             {0,0},             /* speed_dec */              
             {0,0},             /* volume */
             {0,0},             /* volume_inc */
             {0,0},             /* volume_dec */
             {0,0},             /* timer */
             {0,0},             /* timer_bg */                
             {0,0},             /* progress fill */
             {0,0},             /* progress empty */
             {0,0},             /* progress_inc */
             {0,0}},            /* progress_dec */
            /****** fullscreen softkey ******/
            {FALSE,             /* is_lsk_icon */
             FALSE,             /* is_rsk_icon */
             FALSE,             /* is_ck_icon */                 
             {0,0},             /* icon_lsk_pos */
             {0,0},             /* icon_rsk_pos */                  
             {0,0},             /* icon_ck_pos */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
             {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},  /* rsk */                
            /****** loading ******/
            {{110,98,100,43},       /* rect */
             {110,98},              /* bg */
             TRUE,                  /* is_draw_progress */
             {117,117}}             /* progress */             
        };
        /* End of 240x320 fullscreen Video Player Skin */
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
    
#endif /* __MMI_VIDEO_PLAYER__ || __MMI_VIDEO_RECORDER__ */

