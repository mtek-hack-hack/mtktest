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
#include "MMI_features.h"
#include "PixtelDataTypes.h"
#include "Gui_data_types.h"

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__

U16 g_audio_equalizer_bar_start_x, g_audio_equalizer_bar_start_y;
U16 g_audio_equalizer_bar_width, g_audio_equalizer_bar_height, g_audio_equalizer_dist_btw_bars;
U16 g_audio_equalizer_scrollable_ht, g_audio_equalizer_unit_scroll;


void mmi_aud_eq_init_image_specific_vals(void)
{
#if defined __MMI_MAINLCD_128X128__ //dummy values

	g_audio_equalizer_bar_start_x = 22;
	g_audio_equalizer_bar_start_y = 13;
	g_audio_equalizer_bar_width = 7;
	g_audio_equalizer_bar_height = 70;
	g_audio_equalizer_dist_btw_bars = 6;
	g_audio_equalizer_scrollable_ht = 64;
	g_audio_equalizer_unit_scroll = 8;

#elif defined __MMI_MAINLCD_128X160__

	g_audio_equalizer_bar_start_x = 25;
	g_audio_equalizer_bar_start_y = 30;
	g_audio_equalizer_bar_width = 7;
	g_audio_equalizer_bar_height = 70;
	g_audio_equalizer_dist_btw_bars = 6;
	g_audio_equalizer_scrollable_ht = 64;
	g_audio_equalizer_unit_scroll = 8;

#elif defined __MMI_MAINLCD_176X220__

	g_audio_equalizer_bar_start_x = 29;
	g_audio_equalizer_bar_start_y = 39;
	g_audio_equalizer_bar_width = 11;
	g_audio_equalizer_bar_height = 92;
	g_audio_equalizer_dist_btw_bars = 7;
	g_audio_equalizer_scrollable_ht = 80;
	g_audio_equalizer_unit_scroll = 10;

#elif defined __MMI_MAINLCD_240X320__

	g_audio_equalizer_bar_start_x = 41;
	g_audio_equalizer_bar_start_y = 71;
	g_audio_equalizer_bar_width = 12;
	g_audio_equalizer_bar_height = 127;
	g_audio_equalizer_dist_btw_bars = 13;
	g_audio_equalizer_scrollable_ht = 112;
	g_audio_equalizer_unit_scroll = 14;

#elif defined __MMI_MAINLCD_320X240__

	g_audio_equalizer_bar_start_x = 75;
	g_audio_equalizer_bar_start_y = 20;
	g_audio_equalizer_bar_width = 12;
	g_audio_equalizer_bar_height = 127;
	g_audio_equalizer_dist_btw_bars = 14;
	g_audio_equalizer_scrollable_ht = 112;
	g_audio_equalizer_unit_scroll = 14;

#endif
}

#endif
