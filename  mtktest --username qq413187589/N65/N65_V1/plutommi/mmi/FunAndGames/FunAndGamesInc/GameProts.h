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
 * GameProts.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game function declare
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef GAMEPROTS_H
#define GAMEPROTS_H

#include "MMIDataType.h"
#include "MMI_features.h"

extern void mmi_game_highlight_app(void);

/* motion app */
#if defined(__MMI_MOTION_APP__)
extern void mmi_motion_highlight_app(void);
extern void mmi_motion_init(void);
#endif /* defined(__MMI_MOTION_APP__) */ 



#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  /*this is used for multi-language*/
typedef enum
{
    MMI_GAME_LANGUAGE0 = 0,
    MMI_GAME_LANGUAGE1,
    MMI_GAME_LANGUAGE2,
    MMI_GAME_LANGUAGE3,
    MMI_GAME_LANGUAGE4,
    MMI_GAME_LANGUAGE5,
    MMI_GAME_LANGUAGE6,
    MMI_GAME_LANGUAGE7,
    MMI_GAME_LANGUAGE8,
    MMI_GAME_LANGUAGE9,
    MMI_GAME_LANGUAGE_TATAL
}MMI_GAME_MULTI_LANGUAGE_ENUM;

typedef struct 
{
    U8       language_index;
    PS8     language_description;
    U8     aLangSSC[10];
}mmi_game_language_mapping_table_struct;

typedef struct 
{
    U16 x;
    U16 y;
}mmi_game_point_struct;

extern mmi_game_language_mapping_table_struct g_mmi_game_language_mapping_table[];
extern U16 g_mmi_game_current_language_index;

extern const U8 ________CUSTOMER__IMAGES__DEFAULT_BMP[], ________CUSTOMER__IMAGES__EMPTYIMAGE_BMP[];
#define MMI_GAME_DEFAULT_IMAGE_BMP       ________CUSTOMER__IMAGES__DEFAULT_BMP
#define MMI_GAME_EMPTYIMAGE_BMP             ________CUSTOMER__IMAGES__EMPTYIMAGE_BMP

extern U16 mmi_gfx_get_multilanguage_image_ID(
           MMI_GAME_MULTI_LANGUAGE_ENUM language, 
           U16 image_ID_base, 
           U16 total_string_count, 
           U16 string_number);
extern BOOL mmi_gfx_check_image_get_valid_language(
            U16 *game_language_index, 
            U16 image_ID_base, 
            U16 total_string_count);
#endif /*__GAME_MULTI_LANGUAGE_SUPPORT__*/

#endif /* GAMEPROTS_H */ 

