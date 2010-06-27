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
 *   TouchScreenGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Low-level Touch Screen API
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _TOUCH_SCREEN_GPROT_H
#define _TOUCH_SCREEN_GPROT_H

#ifndef _KAL_NON_SPECIFIC_GENERAL_TYPES_H
#error "kal_non_specific_general_types.h should be included "
#endif 

#ifndef _MMI_DATA_TYPE_H
#include "MMIDataType.h"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/

/*
 * Whether to support Stroke LongTap Event. 
 * We can use Stroke LongTap event in handwriting to control the editor
 */
#undef MMI_PEN_SUPPORT_STROKE_LONGTAP

/* Number of doubles in one set of  calibation data */
#define PEN_CALIBRATION_DATA_SIZE   4

/* Utility macro functions */
#define PEN_CHECK_BOUND(x, y, x1, y1, width, height) ((x) >= (x1) && (y) >= (y1) && (x) < ((x1) + (width)) && (y) < ((y1) + (height)))

#define PEN_ABS(a, b) (((a) > (b)) ? (a-b) : (b-a))

#define PEN_MIN(a, b) (((a) > (b)) ? (b) : (a))

#define PEN_MAX(a, b) (((a) > (b)) ? (a) : (b))

/* Delay time for Pen LongTap */
#define MMI_PEN_LONGTAP_TIME           (60)     /* multiple of 10ms */

/* Delay time for Pen Repeat */
#define MMI_PEN_REPEAT_TIME            (30)     /* multiple of 10ms */

/* Delay time for Stroke LongTap (MMI_PEN_SUPPORT_STROKE_LONGTAP) */
#define MMI_PEN_STROKE_LONGTAP_TIME    (80)     /* multiple of 10ms */

/* Sampling period of Event-Based pen events (~ 12 samples/sec) */
#define MMI_PEN_SAMPLING_PERIOD_1      (8)      /* multiple of 10ms */

/* Sampling period of Stroke-Based pen events (50 samples/sec) */
#define MMI_PEN_SAMPLING_PERIOD_2      (2)      /* multiple of 10ms */

/* If pen does not move over this distance, donot generate Pen Move event at all. */
#define MMI_PEN_SKIP_MOVE_OFFSET                5

/* If pen does not move over this distance, donot generate Stroke Move event at all. */
#define MMI_PEN_SKIP_STROKE_MOVE_OFFSET         1

/* Maximum move offset for generating LongTap event */
#define MMI_PEN_SKIP_LONGTAP_OFFSET             10

/* Maximum move offset for generating Stroke-LongTap event (MMI_PEN_SUPPORT_STROKE_LONGTAP) */
#define MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET      14

/* Minimum offset to Pen Down position in order to switch from event-based mode to stroke-based mode */
#if defined(MMI_PEN_SUPPORT_STROKE_LONGTAP) || defined(__MMI_HANDWRITING_PAD__)
#define MMI_PEN_STROKE_MIN_OFFSET               0
#else 
#define MMI_PEN_STROKE_MIN_OFFSET               9
#endif 

#ifdef __MMI_HANDWRITING_PAD__
#define IS_ENABLE_FLAG(data, f)        ( (data & (f)) == (f) )

/* Touch Pad flag */
#define TP_MAPPING_KEY_MASK   (0x000000FF)
#define TP_MAPPING_KEY        (0x00000100)
#define TP_CUSTOM_HANDLE      (0x00000200)
#define TP_CONTROL_AREA       (0x80000000)
#define TP_HANDWRITING_AREA   (0x40000000)
#define TP_HANDWRITING_SUPPORTS_FULL_AREA   (0x20000000)

#endif /* __MMI_HANDWRITING_PAD__ */ 

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef enum
{
    MMI_PEN_EVENT_DOWN,
    MMI_PEN_EVENT_UP,
    MMI_PEN_EVENT_LONG_TAP,
    MMI_PEN_EVENT_REPEAT,
    MMI_PEN_EVENT_MOVE,
    MMI_PEN_EVENT_ABORT,
    MMI_PEN_EVENT_TYPE_MAX
} mmi_pen_event_type_enum;

typedef enum
{
    MMI_PEN_STROKE_DOWN,
    MMI_PEN_STROKE_UP,
    MMI_PEN_STROKE_MOVE,
    MMI_PEN_STROKE_LONGTAP,
    MMI_PEN_STROKE_TYPE_MAX
} mmi_pen_stroke_type_enum;

typedef struct
{
    S16 x;
    S16 y;
} mmi_pen_point_struct;

typedef struct
{
    S16 x1, y1, x2, y2;
} mmi_pen_handwriting_area_struct;

typedef struct
{
    mmi_pen_point_struct *points;
    S16 num;
} mmi_pen_polygon_area_struct;

typedef struct
{
    double data[PEN_CALIBRATION_DATA_SIZE];
} mmi_pen_calibration_struct;

typedef void (*mmi_pen_hdlr) (mmi_pen_point_struct pos);

#ifdef __MMI_HANDWRITING_PAD__
typedef struct tp_area_struct_tag
{
    kal_uint32 id;
    kal_uint32 flag;
    const mmi_pen_point_struct *pos;
    mmi_pen_hdlr *hdlr_table;

} tp_area_struct;

/* for handwriting pad (end) */
#endif /* __MMI_HANDWRITING_PAD__ */ 

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
#ifdef __MMI_HANDWRITING_PAD__
extern const mmi_pen_point_struct tp_calibration_point[];
extern const tp_area_struct tp_area_table[];
#endif /* __MMI_HANDWRITING_PAD__ */ 

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_pen_dummy_hdlr(mmi_pen_point_struct);

extern void mmi_pen_config_sampling_period(kal_uint32 low, kal_uint32 high);
extern void mmi_pen_config_timeout_period(kal_uint32 longtap, kal_uint32 repeat, kal_uint32 stroke_longtap);
extern void mmi_pen_config_move_offset(
                kal_uint32 event_based,
                kal_uint32 stroke_based,
                kal_uint32 long_tap,
                kal_uint32 stroke_long_tap);

extern void mmi_pen_init(void);

extern void mmi_pen_block(void);
extern void mmi_pen_unblock(void);

extern void mmi_pen_enable(void);
extern void mmi_pen_disable(void);
extern void mmi_pen_reset(void);

extern void mmi_pen_get_state(kal_bool *is_enabled, kal_bool *is_pen_down);

/* Calibration */
extern void mmi_pen_start_calibration(kal_uint16 num, const mmi_pen_point_struct *points);
extern void mmi_pen_set_calibration_data(const mmi_pen_calibration_struct *data);
extern void mmi_pen_read_calibration_data(mmi_pen_calibration_struct *data);

/* Event-based API */
extern void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp);

/* Stroke-based API */
extern void mmi_pen_start_capture_strokes(
                kal_uint32 max_points,
                mmi_pen_point_struct *point_array,
                kal_uint32 num_regions,
                const mmi_pen_handwriting_area_struct *region_array,
                const mmi_pen_handwriting_area_struct *ext_region);
extern void mmi_pen_stop_capture_strokes(void);

extern void mmi_pen_change_handwriting_area(
                kal_uint32 num_regions,
                const mmi_pen_handwriting_area_struct *region_array,
                const mmi_pen_handwriting_area_struct *ext_region);

extern void mmi_pen_begin_strokes_of_character(void);
extern void mmi_pen_end_strokes_of_character(void);

extern void mmi_pen_register_stroke_down_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_stroke_move_handler(void (*begin_fp) (void), void (*end_fp) (void), mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_stroke_up_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_stroke_longtap_handler(mmi_pen_hdlr pen_fp);

extern void mmi_pen_peek_stroke_state(MMI_BOOL *has_unfinished_stroke);

/* Handwriting Pad */

#ifdef __MMI_HANDWRITING_PAD__
extern void mmi_frm_setup_default_pen_handler(void);
extern S32 mmi_pen_check_inside_control_area();
#endif /* __MMI_HANDWRITING_PAD__ */ 

/* Utility API */
typedef void (*func_ptr_short) (U16);

extern void mmi_pen_set_event_handler_callback(func_ptr_short pre_fp, func_ptr_short post_fp);
extern void mmi_pen_reset_event_handler_callback(func_ptr_short pre_fp, func_ptr_short post_fp);
extern MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos);

#endif /* _TOUCH_SCREEN_GPROT_H */ 

