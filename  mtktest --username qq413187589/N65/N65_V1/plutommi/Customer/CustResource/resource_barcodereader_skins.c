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
 *  resourece_barcodereader_skins.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
#ifdef __MMI_BARCODEREADER__

#include "PixtelDataTypes.h"
#include "gdi_lcd_config.h"
#include "MMI_features_barcodereader.h"
#include "resource_barcodereader_skins.h"

#if ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***************************************************************************** 
* 
* [240x320]
* 
*****************************************************************************/

	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
	#ifdef __MMI_HORIZONTAL_BARCODEREADER__
		{0,0,320,240},
	#else
		{0,0,240,320},
	#endif
		/****** status icons ******/
		{TRUE,96,237},		/* flash */
		{TRUE,60,9},		/* ev */
		{TRUE,207,9},		/* ev_inc */
		{TRUE,38,9},		/* ev_dec */			
		{TRUE,5,72},		/* zoom */
		{TRUE,5,40},		/* zoom_inc */			
		{TRUE,5,153},		/* zoom_dec */
		{TRUE,163,237},	    /* storage */
		{TRUE,29,237},		/* focus_mode */
		{TRUE,5,188},		/* zoom_mf_toggle */
		{TRUE,112,295},	/* capture */
		/****** hint box ******/
		{TRUE,0,110,240,70,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,136,7,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx_270 =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
		{0,0,320,240},
		/****** status icons ******/
		{TRUE,5,63},		/* flash */
		{TRUE,175,2},		/* ev */
		{TRUE,239,2},		/* ev_inc */
		{TRUE,150,1},		/* ev_dec */			
		{TRUE,290,70},		/* zoom */
		{TRUE,290,33},		/* zoom_inc */			
		{TRUE,290,150},	/* zoom_dec */
		{TRUE,205,79},	/* storage */
		{TRUE,5,93},		/* focus_mode */
		{TRUE,290,183},	/* zoom_mf_toggle */
		{TRUE,60,3},		/* capture */
		/****** hint box ******/
		{TRUE,80,50,160,140,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,123,5,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */
// Dihrin landscape begin
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
/***************************************************************************** 
* 
* [320x240]
* 
*****************************************************************************/

	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
	#ifdef __MMI_HORIZONTAL_BARCODEREADER__
		{0,0,320,240},
	#else
		{0,0,240,320},
	#endif
		/****** status icons ******/
		{TRUE,272,101},		/* flash */
		{TRUE,69,8},		/* ev */
		{TRUE,222,11},		/* ev_inc */
		{TRUE,55,11},		/* ev_dec */			
		{TRUE,5,72},		/* zoom ??*/
		{TRUE,5,40},		/* zoom_inc ??*/			
		{TRUE,5,153},		/* zoom_dec ??*/
		{TRUE,272,66},	    /* storage */
		{TRUE,272,137},		/* focus_mode */
		{TRUE,5,188},		/* zoom_mf_toggle ?? */
		{TRUE,145,214},	/* capture */
		/****** hint box ******/
		{TRUE,60,70,160,90,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,136,7,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};
#ifdef __MMI_HORIZONTAL_BARCODEREADER__

	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx_270 =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
		{0,0,320,240},
		/****** status icons ******/
		{TRUE,272,101},		/* flash */
		{TRUE,69,8},		/* ev */
		{TRUE,222,11},		/* ev_inc */
		{TRUE,55,11},		/* ev_dec */			
		{TRUE,5,72},		/* zoom ??*/
		{TRUE,5,40},		/* zoom_inc ??*/			
		{TRUE,5,153},		/* zoom_dec ??*/
		{TRUE,272,66},	    /* storage */
		{TRUE,272,137},		/* focus_mode */
		{TRUE,5,188},		/* zoom_mf_toggle ?? */
		{TRUE,145,214},	/* capture */
		/****** hint box ******/
		{TRUE,60,70,160,90,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,136,7,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */
// Dihrin landscape end

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***************************************************************************** 
* 
* [176x220]
* 
*****************************************************************************/

	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
	#ifdef __MMI_HORIZONTAL_BARCODEREADER__
		{0,0,220,176},
	#else
		{0,0,176,220},
	#endif
		/****** status icons ******/
		{TRUE,65,160},		/* flash */
		{TRUE,49,2},		/* ev */
		{TRUE,150,2},		/* ev_inc */
		{TRUE,29,2},		/* ev_dec */			
		{TRUE,3,46},		/* zoom */
		{TRUE,3,35},		/* zoom_inc */			
		{TRUE,3,116},		/* zoom_dec */
		{TRUE,118,160},	    	/* storage */
		{TRUE,11,160},		    /* af_mode */
		{TRUE,0,0},	    	/* zoom_mf_toggle */
		{TRUE,79,203},		/* capture */
		/****** hint box ******/
		{TRUE,0,50,176,50,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,130,7,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};

#ifdef __MMI_HORIZONTAL_BARCODEREADER__
	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx_270 =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
		{0,0,220,176},
		/****** status icons ******/
		{TRUE,65,160},		/* flash */
		{TRUE,49,2},		/* ev */
		{TRUE,150,2},		/* ev_inc */
		{TRUE,29,2},		/* ev_dec */			
		{TRUE,3,46},		/* zoom */
		{TRUE,3,35},		/* zoom_inc */			
		{TRUE,3,116},		/* zoom_dec */
		{TRUE,118,160},	    	/* storage */
		{TRUE,11,160},		    /* af_mode */
		{TRUE,0,0},	    	/* zoom_mf_toggle */
		{TRUE,79,203},		/* capture */
		/****** hint box ******/
		{TRUE,0,30,220,88,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,26,163,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};
#endif /* __MMI_HORIZONTAL_BARCODEREADER__*/

#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
/***************************************************************************** 
* 
* [128x160]
* 
*****************************************************************************/

	barcodereader_osd_layeout_struct g_barcodereader_osd_cntx =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
		{0,0,128,160},
		/****** status icons ******/
		{FALSE,0,0},		/* flash */
		{TRUE,2,2},			/* ev */
		{FALSE,0,0},		/* ev_inc */
		{FALSE,0,0},		/* ev_dec */			
		{TRUE,113,40},		/* zoom */
		{FALSE,0,0},		/* zoom_inc */			
		{FALSE,0,0},		/* zoom_dec */
		{FALSE,0,0},		/* storage */
		{FALSE,0,0},		/* focus_mode */
		{FALSE,0,0},		/* zoom_mf_toggle */
		{FALSE,0,0},		/* capture */
		/****** hint box ******/
		{TRUE,0,55,128,50,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,125,23,
		 {67,87,153,255,255,255,MMI_BARCODEREADER_TEXT_STYLE_BORDER}}
	};


#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
/***************************************************************************** 
* 
* [128x128]
* 
*****************************************************************************/

	camera_osd_layeout_struct g_camera_osd_cntx =
	{
		/****** background ******/
		{FALSE,TRUE,0,0,0},
		/****** title ******/
		{FALSE,FALSE},
		/****** softkey layer ******/
		{FALSE,
		 {67,87,153,255,255,255,CAMERA_TEXT_STYLE_BORDER}, 	/* lsk */
		 {67,87,153,255,255,255,CAMERA_TEXT_STYLE_BORDER}},	/* rsk */
		/****** preview wnd ******/
		{0,0,128,128},
		/****** status icons ******/
		{FALSE,0,0},		/* flash */
		{TRUE,2,2},			/* ev */
		{FALSE,0,0},		/* ev_inc */
		{FALSE,0,0},		/* ev_dec */			
		{TRUE,113,40},		/* zoom */
		{FALSE,0,0},		/* zoom_inc */			
		{FALSE,0,0},		/* zoom_dec */			
		{FALSE,0,0},		/* storage */
		{FALSE,0,0},		/* focus_mode */
		{FALSE,0,0},		/* zoom_mf_toggle */
		{FALSE,0,0},		/* capture */
		/****** hint box ******/
		{TRUE,0,33,128,50,
		 {67,87,153,255,255,255,CAMERA_TEXT_STYLE_BORDER}},		
		/****** remain storage ******/
		{TRUE,TRUE,125,23,
		 {67,87,153,255,255,255,CAMERA_TEXT_STYLE_BORDER}}
	};



#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */



 


#endif /* __MMI_BARCODEREADER__*/

