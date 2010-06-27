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
 *   gui_data_types.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Basic data types
 *
 * Author:
 * -------
 *
 *
 *==============================================================================
 * 				HISTORY
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
 
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
 
/**********************************************************************************
	Filename:		gui_data_types.h
	Author:			manju
	Date Created:	December-24-2002
	Contains:		PixTel UI data types
					Includes standard and external data types
**********************************************************************************/

#ifndef __GUI_DATA_TYPES_H__
#define __GUI_DATA_TYPES_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*	External includes					*/

#include "MMIDataType.h"
#include "PixcomFontengine.h"
#include "FontRes.h"
#include "gui_config.h"

/*	Basic datatypes used by the UI		*/

typedef U8				byte;			/*	unsigned 8-bit data		*/
typedef U16				word;			/*	unsigned 16-bit data	*/
typedef U32				dword;			/*	unsigned 32-bit data	*/

	typedef S8				s8;				/*	signed 8-bit data		*/
	typedef S16				s16;			/*	signed 16-bit data		*/
#ifndef __LxS_Types_h__ //iTap define its own s32 type, and disagree with ours.
	typedef S32				s32;			/*	signed 32-bit data		*/
#endif
/*	External datatypes used by the UI	*/

#define MAX_ANIMATED_IMAGES			32
#define MAX_ANIMATION_FRAMES		32
#define ANIMATED_IMAGE_FRAME_RATE	200			/*	milli-seconds	*/

#define ANIMATED_IMAGE_TRANSPARENT				0x00000001
#define ANIMATED_IMAGE_CYCLE_SELECTED_FRAMES	0x00000002

typedef struct _bitmap
{	s32		xsize;
	s32		ysize;
    s8		color_depth;
    s32		row_bytes;
    byte	*palette;
    byte	*data;
} bitmap;

typedef byte*				UI_image_type;
typedef byte*				UI_audio_type;//101205 audio resource Calvin add
typedef byte				UI_transparent_color_type;
typedef stFontAttribute*	UI_font_type;

#ifdef __UCS2_ENCODING
typedef	U16					UI_character_type;
#else
typedef U8					UI_character_type;
#endif

typedef UI_character_type*	UI_string_type;
typedef U8*					UI_buffer_type;

/* Deprecated data type. Replaced by GDI */
typedef struct _animated_image
{	s16				n_frames;
    s16				frame_rate;
    s16				frame_counter;
	s32				x;
	s32				y;
	UI_image_type	images[MAX_ANIMATION_FRAMES];
    void			(*hide_function)(s32 x1,s32 y1,s32 x2,s32 y2);
    dword			flags;
	s32				clip_x1;
	s32				clip_y1;
	s32				clip_x2;
	s32				clip_y2;
	s16				start_frame;
	s16				end_frame;
	bitmap*			graphics_context;
	void			(*last_frame_function)(void);
} animated_image;

/* Deprecated data type. Replaced by GDI */
typedef animated_image*					UI_animated_image_handle;

extern	UI_font_type					UI_font;

#define UI_NULL_IMAGE					NULL
#define UI_DEFAULT_TRANSPARENT_COLOR	0
#define UI_NULL_TRANSPARENT_COLOR		255

/*	Retained for compatibility sake. Will be removed later	*/
#define UI_IMAGE_ID_NULL				NULL

#define UI_UNUSED_PARAMETER(x)			((void)(x))

#if(UI_INDEXED_COLOR_SYSTEM)

#if(UI_COLOR_DEPTH<=8)

typedef byte	color;

#else

typedef word	color;

#endif

#else

typedef struct _color
{	byte r;
	byte g;
	byte b;
	byte alpha;
} color;

#endif

typedef struct _polygon_vertex
{	s32		x;
	s32		y;
} polygon_vertex;

#ifdef __cplusplus
}
#endif

#endif

