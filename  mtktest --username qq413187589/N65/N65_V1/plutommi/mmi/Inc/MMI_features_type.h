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
 *  MMI_features_type.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Type define fo MMI feature switch file
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
#ifndef __MMI_FEATURES_TYPE_H__
#define __MMI_FEATURES_TYPE_H__

/* general on/off/auto type */
#define __ON__          (-1)
#define __OFF__         (-2)
#define __AUTO__        (-3)

/* gui menu type */
#define __MATRIX__          (0)
#define __PAGE__            (1)
#define __LIST__            (2)
#define __CIRCULAR_3D__     (3)
#define __ROTATE__          (4)
#define __TAB__             (5)
#define __FIXED_GRID__      (6)
#define __ANI_BG_LIST__     (7)

/* resource type */
#define __RES_TYPE_GIF__        (0)
#define __RES_TYPE_BMP__        (1)
#define __RES_TYPE_JPG__        (2)
#define __RES_TYPE_SEQUENCE__   (3)
#define __RES_TYPE_PNG__        (4)

/* highlight effect */
#define  HIGHLIGHT_EFFECT_NONE          (0)     /* No Effect */
#define  HIGHLIGHT_EFFECT_TRANSPARENCY  (1)     /* Transparent with increasing opacity */
#define  HIGHLIGHT_EFFECT_FLASH_FEELING (2)     /* Flash effect with increase in Filler area */
#define  HIGHLIGHT_EFFECT_ANIMATION     (3)     /* Animatian with gif */
#define  HIGHLIGHT_EFFECT_SLIDE         (4)     /* slide effect */

/* softkey style */
#define  SOFTKEY_STYLE_NONE             (0)     /* No Special Effect */
#define  SOFTKEY_STYLE_DALMATIAN        (1)     /* Dalmatian Style */
#define  SOFTKEY_STYLE_TECHNO           (2)     /* Techno Stle */

/* status bar style */
#define  STATUSBAR_STYLE_NONE           (0)     /* No Special Effect */
#define  STATUSBAR_STYLE_DALMATIAN      (1)     /* Dalmatian Style */
#define  STATUSBAR_STYLE_TECHNO         (2)     /* Techno Stle */

/* ui animated title effect type */
#define __ONCE__        (0)
#define __CONTINUOUS__  (1)

/* ui fade effect style */
#define MMI_UI_FADE_EFFECT_STYLE_GRAY       (0)
#define MMI_UI_FADE_EFFECT_STYLE_DARKEN     (1)

#endif /* __MMI_FEATURES_TYPE_H__ */
