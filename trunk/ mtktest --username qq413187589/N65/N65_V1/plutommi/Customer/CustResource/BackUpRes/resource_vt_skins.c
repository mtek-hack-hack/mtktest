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
 *  resource_vt_skins.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video Telephony customization file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "MMIDatatype.h"
#include "gdi_lcd_config.h"
#include "resource_vt_skins.h"


/***************************************************************************** 
 *
 * Customizable VT Skin     
 * [176x220]
 * [240x320]
 *
 *****************************************************************************/



#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
#error "Currently, VT only support with LCD 176x220 or larger, add this part if needed"
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
#error "Currently, VT only support with LCD 176x220 or larger, add this part if needed"

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***************************************************************************** 
 *
 * [176x220]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* regions */
        {0, 0, 176, 18},     /* status_rect */                
        {0, 18, 176, 20},    /* title_rect */
        {0, 38, 176, 122},   /* body_rect */    
        {12, 38, 152, 122},  /* main_wnd_rect */
        {4, 148, 64, 52},    /* sub_wnd_rect */            
        {0, 160, 172, 21},   /* time_panel_rect */          
        {0, 181, 176, 19},   /* ctrl_panel_rect */  
        {0, 200, 176, 20},   /* softkey_rect */  
            
        /* time panel */            
        {111, 162},         /* money_icon_pos */
        {111, 172},         /* time_icon_pos */
            
        /* status panel */      
        {70, 183},          /* icon_1_pos */
        {87, 183},          /* icon_2_pos */
        {104, 183},         /* icon_3_pos */                    
        {121, 183},         /* icon_4_pos */
        {138, 183},         /* icon_5_pos */
        {155, 183},         /* icon_6_pos */  
           
        /* control panel */   
        {70, 183},          /* ctrl_icon_pos */ 
        {155, 183},         /* inc_icon_pos */
        {87, 183},          /* dec_icon_pos */
        {104, 188},         /* scroll_bar_pos */      
            
        /* text sytle */
        {255, 255, 255, 0, 0, 0, MMI_VTCS_TEXT_STYLE_BORDER},    /* title_text_style */
        {255, 255, 255, 0, 0, 0, MMI_VTCS_TEXT_STYLE_BORDER}     /* sk_text_style */
    };


#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***************************************************************************** 
 *
 * [240x320]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* regions */
        {0, 0, 176, 18},     /* status_rect */        
        {0, 18, 176, 20},    /* title_rect */
        {0, 38, 176, 122},   /* body_rect */                
        {12, 38, 152, 122},  /* main_wnd_rect */
        {3, 146, 64, 52},    /* sub_wnd_rect */            
        {0, 160, 172, 21},   /* time_panel_rect */          
        {0, 181, 176, 19},   /* ctrl_panel_rect */  
        {0, 200, 176, 20},   /* softkey_rect */  
            
        /* time panel */            
        {111, 162},         /* money_icon_pos */
        {111, 172},         /* time_icon_pos */
            
        /* status panel */      
        {70, 183},          /* icon_1_pos */
        {87, 183},          /* icon_2_pos */
        {104, 183},         /* icon_3_pos */                    
        {121, 183},         /* icon_4_pos */
        {138, 183},         /* icon_5_pos */
        {155, 183},         /* icon_6_pos */  
           
        /* control panel */
        {155, 183},         /* ctrl_icon_pos */        
        {155, 183},         /* inc_icon_pos */
        {70, 183},          /* dec_icon_pos */
        {87, 188},          /* scroll_bar_pos */      
            
        /* text sytle */
        {255, 255, 255, 0, 0, 0, MMI_VTCS_TEXT_STYLE_BORDER},    /* title_text_style */
        {255, 255, 255, 0, 0, 0, MMI_VTCS_TEXT_STYLE_BORDER}     /* sk_text_style */
    };

#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
#endif /* __MMI_VIDEO_TELEPHONY__ */

