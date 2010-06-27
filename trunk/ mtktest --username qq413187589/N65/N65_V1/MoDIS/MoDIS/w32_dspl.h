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
 *   w32_dslp.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of display functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 #ifndef __PC_DISPLAY_H
#define __PC_DISPLAY_H

#define LCD_LOCATION_X		60//69//21		// LCD display start point x  //26 (origin)
#define LCD_LOCATION_Y		64//69//78		// LCD display start point y  //64 (160 length)

#define KEYPAD_BMP_W		154
#define KEYPAD_BMP_H		261

#define PC_SIMULATOR_W     250         // PC simulator width
#define PC_SIMULATOR_H     550         // PC simulator height

#define PC_KEY_NUMBERS		32  /* gilbert */

#define REFRESH_AREA_LOC_X 51		// refresh area start point x (after key release)
#define REFRESH_AREA_LOC_Y 228//240		// refresh area start point y (after key release)

#define _OX_				63
#define _OY_				237
#define KEY_WIDTH			40 
#define KEY_HEIGHT			20 

#define KEY_1_LEFT   		70-_OX_
#define KEY_1_TOP    		340-_OY_
#define KEY_1_RIGHT  		(108) -_OX_
#define KEY_1_BOTTOM 		(364)-_OY_

#define KEY_2_LEFT   		115 -_OX_
#define KEY_2_TOP    		342 -_OY_
#define KEY_2_RIGHT  		(156)-_OX_
#define KEY_2_BOTTOM 		(364)-_OY_

#define KEY_3_LEFT   165 -_OX_
#define KEY_3_TOP    340 -_OY_
#define KEY_3_RIGHT  (204)-_OX_
#define KEY_3_BOTTOM (364) -_OY_

#define KEY_4_LEFT   68 -_OX_
#define KEY_4_TOP    368 -_OY_
#define KEY_4_RIGHT  (108)-_OX_
#define KEY_4_BOTTOM (394) -_OY_

#define KEY_5_LEFT   115 -_OX_
#define KEY_5_TOP    370 -_OY_
#define KEY_5_RIGHT  (156) -_OX_
#define KEY_5_BOTTOM (394) -_OY_

#define KEY_6_LEFT   165 -_OX_
#define KEY_6_TOP    369 -_OY_
#define KEY_6_RIGHT  (204) -_OX_
#define KEY_6_BOTTOM (394) -_OY_

#define KEY_7_LEFT   68 -_OX_
#define KEY_7_TOP    396 -_OY_
#define KEY_7_RIGHT  (108) -_OX_
#define KEY_7_BOTTOM (424) -_OY_

#define KEY_8_LEFT   114 -_OX_
#define KEY_8_TOP    401 -_OY_
#define KEY_8_RIGHT  (156) -_OX_
#define KEY_8_BOTTOM (424) -_OY_

#define KEY_9_LEFT   165 -_OX_
#define KEY_9_TOP    399 -_OY_
#define KEY_9_RIGHT  (204) -_OX_
#define KEY_9_BOTTOM (424) -_OY_

#define KEY_0_LEFT   115 -_OX_
#define KEY_0_TOP    430 -_OY_
#define KEY_0_RIGHT  (156)-_OX_
#define KEY_0_BOTTOM (454) -_OY_

#define KEY_STAR_LEFT   67-_OX_
#define KEY_STAR_TOP    427-_OY_
#define KEY_STAR_RIGHT  (108)-_OX_
#define KEY_STAR_BOTTOM (454) -_OY_

#define KEY_HASH_LEFT   163-_OX_
#define KEY_HASH_TOP    428-_OY_
#define KEY_HASH_RIGHT  (204) -_OX_
#define KEY_HASH_BOTTOM (454) -_OY_

#define SOFTKEY_WIDTH   33
#define SOFTKEY_HEIGHT  15

#define KEY_SOFT1_LEFT   79-_OX_
#define KEY_SOFT1_TOP    279-_OY_
#define KEY_SOFT1_RIGHT  (105)-_OX_ 
#define KEY_SOFT1_BOTTOM (302) -_OY_

#define KEY_SOFT2_LEFT   169-_OX_
#define KEY_SOFT2_TOP    279 -_OY_
#define KEY_SOFT2_RIGHT  (195) -_OX_
#define KEY_SOFT2_BOTTOM (302) -_OY_

#define KEY_OK_LEFT   78-_OX_
#define KEY_OK_TOP    310-_OY_
#define KEY_OK_RIGHT  (104)-_OX_
#define KEY_OK_BOTTOM (336) -_OY_

#define KEY_CANCEL_LEFT   170-_OX_
#define KEY_CANCEL_TOP    311-_OY_
#define KEY_CANCEL_RIGHT  (323) -_OX_
#define KEY_CANCEL_BOTTOM (336) -_OY_

#define BUTTON_WIDTH	   10 
#define BUTTON_HEIGHT	14 

#define KEY_UP_LEFT     116 -_OX_
#define KEY_UP_TOP      276 -_OY_
#define KEY_UP_RIGHT    (156) -_OX_
#define KEY_UP_BOTTOM   (290)-_OY_

#define KEY_DOWN_LEFT   116 -_OX_
#define KEY_DOWN_TOP    324 -_OY_
#define KEY_DOWN_RIGHT  (160) -_OX_
#define KEY_DOWN_BOTTOM (338) -_OY_

#define KEY_LEFT_LEFT   108 -_OX_
#define KEY_LEFT_TOP    283 -_OY_
#define KEY_LEFT_RIGHT  (125)-_OX_
#define KEY_LEFT_BOTTOM (327)-_OY_

#define KEY_RIGHT_LEFT   153 -_OX_
#define KEY_RIGHT_TOP    284 -_OY_
#define KEY_RIGHT_RIGHT  (169)-_OX_
#define KEY_RIGHT_BOTTOM (327)-_OY_

#define KEY_MENU_LEFT   112 -_OX_
#define KEY_MENU_TOP    253 -_OY_
#define KEY_MENU_RIGHT  (KEY_MENU_LEFT+33)-_OX_
#define KEY_MENU_BOTTOM (KEY_MENU_TOP+31) -_OY_

#define KEY_FUNC_LEFT   72 -_OX_
#define KEY_FUNC_TOP    248 -_OY_
#define KEY_FUNC_RIGHT  (KEY_FUNC_LEFT+25)-_OX_
#define KEY_FUNC_BOTTOM (KEY_FUNC_TOP+26) -_OY_

#define KEY_VOLUP_LEFT   16 -_OX_
#define KEY_VOLUP_TOP    270 -_OY_
#define KEY_VOLUP_RIGHT  (48)-_OX_
#define KEY_VOLUP_BOTTOM (303) -_OY_

#define KEY_VOLWN_LEFT   16 -_OX_
#define KEY_VOLWN_TOP    318-_OY_
#define KEY_VOLWN_RIGHT  (47)-_OX_
#define KEY_VOLWN_BOTTOM (349) -_OY_

#define KEY_POWER_LEFT   154-_OX_
#define KEY_POWER_TOP    20-_OY_
#define KEY_POWER_RIGHT  (KEY_POWER_LEFT+40)-_OX_
#define KEY_POWER_BOTTOM (KEY_POWER_TOP+40) -_OY_

#define KEY_CLEAR_LEFT   164 -_OX_
#define KEY_CLEAR_TOP    249 -_OY_
#define KEY_CLEAR_RIGHT  (KEY_CLEAR_LEFT+24)-_OX_
#define KEY_CLEAR_BOTTOM (KEY_CLEAR_TOP+25) -_OY_

/*
#define KEY_EARPHONE_LEFT 12
#define KEY_EARPHONE_TOP 241
#define KEY_EARPHONE_RIGHT (12+15)
#define KEY_EARPHONE_BOTTOM (241+15)
*/
typedef struct {
	HWND				hwnd;
	RECT				lcd_location;
   RECT				key_location[PC_KEY_NUMBERS];
	HDC				main_bitmap;
	unsigned int	main_bitmap_width;
	unsigned int	main_bitmap_height;
	HDC				key_bitmap[PC_KEY_NUMBERS];
	HDC				key_up_bitmap[PC_KEY_NUMBERS];

	/* the data below are read from the INI file */
	unsigned int	main_lcd_height;
	unsigned int	main_lcd_width;
	unsigned int	skin_main_lcd_x;
	unsigned int	skin_main_lcd_y;
	unsigned int	sub_lcd_height;
	unsigned int	sub_lcd_width;
	unsigned int	skin_sub_lcd_x;
	unsigned int	skin_sub_lcd_y;
	unsigned int	window_height;
	unsigned int	window_width;
	/* the data above are read from the INI file */

	//HBITMAP main_hbitmap;
   //HBITMAP key_hbitmap[PC_KEY_NUMBERS];
} T_W32_SCREEN_DEVICE;

extern void w32_key_detect_ind(unsigned char key_status, unsigned char key_code);
extern void w32_update_screen
(
 void
);
extern void w32_lcd_update_sub
(
 void
);



#endif
