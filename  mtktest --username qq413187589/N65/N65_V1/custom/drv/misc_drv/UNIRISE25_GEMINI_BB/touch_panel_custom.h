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
 *    keypad_def.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for keypad table
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef TOUCH_PANEL_CUSTOM_H
#define TOUCH_PANEL_CUSTOM_H
 
/*ADC*/ 
#define TOUCH_PANEL_ADC_X_START   270 
#define TOUCH_PANEL_ADC_X_END      3774
#define TOUCH_PANEL_ADC_Y_START    135 
#define TOUCH_PANEL_ADC_Y_END      3699

#define TOUCH_PANEL_COORD_X_START 0
#define TOUCH_PANEL_COORD_X_END   239
#define TOUCH_PANEL_COORD_Y_START 0
#define TOUCH_PANEL_COORD_Y_END  319

#define TOUCH_PANEL_EINT_DOWN_LEVEL  LEVEL_LOW


/*touch panel control*/
#define TOUCH_PANEL_START_BIT    0x80

#define TOUCH_PANEL_TEMP0        0x00
#define TOUCH_PANEL_X_PLUS       0x10
#define TOUCH_PANEL_VBAT         0x20
#define TOUCH_PANEL_Z1_POS       0x30
#define TOUCH_PANEL_Z2_POS       0x40
#define TOUCH_PANEL_Y_PLUS       0x50
#define TOUCH_PANEL_TEMP1        0x70

#define TOUCH_PANEL_ADC3         0x20
#define TOUCH_PANEL_ADC4         0x60
#define TOUCH_PANEL_12BIT_SAMPLE 0x0
#define TOUCH_PANEL_8BIT_SAMPLE  0x8
#define TOUCH_PANEL_DIFF_MODE    0x0
#define TOUCH_PANEL_SINGLE_MODE  0x4

#define TOUCH_PANEL_PWD_ENBLE    0x0
#define TOUCH_PANEL_IRQ_DISABLE  0x1
#define TOUCH_PANEL_PWD_DISABLE  0x3
#define TOUCH_PANEL_PWD_RESET    0x2

/*retry and filter*/
   #define TOUCH_PANEL_RETRY 4
   #define TOUCH_PANEL_FILTER_THRESOLD 50

/*************************************************************************
 * [Define the cailbration point only for HAND_WRITING feature ]
 *************************************************************************/
/* top-left point */
#define TOUCH_PANEL_CALIBRATION_X_1   (20)
#define TOUCH_PANEL_CALIBRATION_Y_1   (170)
/* bottom-right point */
#define TOUCH_PANEL_CALIBRATION_X_2   (220)
#define TOUCH_PANEL_CALIBRATION_Y_2   (270)
/* 3rd point should be different from the ceter point 
 * such that driver can check it's ADC value
 */
#define TOUCH_PANEL_CALIBRATION_X_3   (150)
#define TOUCH_PANEL_CALIBRATION_Y_3   (250)


/*************************************************************************
 * [handwriting pad information setting]
 * 1. Define the enum of the control areas
 * 
 * The flag for control areas or handwriting areas...
 *
 * #define TP_MAPPING_KEY        (0x00000100)
 * #define TP_CUSTOM_HANDLE      (0x00000200)
 * #define TP_CONTROL_AREA       (0x80000000)
 * #define TP_HANDWRITING_AREA   (0x40000000)
 * #define TP_HANDWRITING_SUPPORTS_FULL_AREA   (0x20000000)
 *
 * 2.
 *************************************************************************/
typedef enum
{
   TP_AREA_HANDWRITING,
   TP_CONTROL_AREA_LSK,
   TP_CONTROL_AREA_UP_ARROW,
   TP_CONTROL_AREA_RSK,
   TP_CONTROL_AREA_DOWN_ARROW,
   TP_CONTROL_AREA_LEFT_ARROW,
   TP_CONTROL_AREA_RIGHT_ARROW,

   TP_CONTROL_AREA_SEND,
   TP_CONTROL_AREA_CLEAN,
   TP_CONTROL_AREA_END,

   TP_CONTROL_AREA_1,
   TP_CONTROL_AREA_2,
   TP_CONTROL_AREA_3,

   TP_CONTROL_AREA_4,
   TP_CONTROL_AREA_5,
   TP_CONTROL_AREA_6,

   TP_CONTROL_AREA_7,
   TP_CONTROL_AREA_8,
   TP_CONTROL_AREA_9,

   TP_CONTROL_AREA_STAR,
   TP_CONTROL_AREA_0,
   TP_CONTROL_AREA_HASH,   
   
   TP_CONTROL_AREA_EXTRA_FUNC,
   
   /* don't add the enum after this line */
   TP_AREA_MAX_NUM
}tp_area_id_enum;



#endif
