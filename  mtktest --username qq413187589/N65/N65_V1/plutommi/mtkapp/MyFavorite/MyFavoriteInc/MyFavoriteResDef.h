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
 *  MyFavoriteResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource definitions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_MYFAVORITEDEF_H
#define  MMI_MYFAVORITEDEF_H

#include "MMI_features.h"       /* add if you use any compile options defined in MMI_features.h */

#ifdef __MMI_MY_FAVORITE__

#include "MMIDataType.h"        /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_MY_FAVORITE = MY_FAVORITE_BASE,
    /* add new screen ID below this line */
    SCR_MY_FAVORITE_MARKER,
    SCR_MY_FAVORITE_MAIN,
    SCR_MY_FAVORITE_MEMORY_CARD_OPTION,
    SCR_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTION,
    SCR_MY_FAVORITE_JAVABOX_OPTION,
    SCR_MY_FAVORITE_EDITOR,
    SCR_MY_FAVORITE_EDITOR_OPTION,
    /* add new screen ID above this line */
    SCR_ID_MY_FAVORITE_END
} SCR_ID_MY_FAVORITE_ENUM;

/* String IDs */
typedef enum
{
    STR_ID_MY_FAVORITE = MY_FAVORITE_BASE,
    /* add new string ID below this line */
    STR_ID_MY_FAVORITE_MAIN,
    STR_ID_MY_FAVORITE_FOLDER_IMAGES,
    STR_ID_MY_FAVORITE_FOLDER_AUDIO,
    STR_ID_MY_FAVORITE_FOLDER_VIDEO,
    STR_ID_MY_FAVORITE_FOLDER_JAVABOX,
    STR_ID_MY_FAVORITE_FOLDER_SWFLASH,
    STR_ID_MY_FAVORITE_FOLDER_OTHERS,
    STR_ID_MY_FAVORITE_FOLDER_MEMORY_CARD,
    STR_ID_MY_FAVORITE_WAP_JAVA,
    STR_ID_MY_FAVORITE_WAP_SWFLASH,
    /* add new string ID above this line */
    STR_ID_MY_FAVORITE_END
} STR_ID_MY_FAVORITE_ENUM;

/* Image IDs */
typedef enum
{
    IMG_ID_MY_FAVORITE = MY_FAVORITE_BASE,
    /* add new image ID below this line */
    IMG_ID_MY_FAVORITE_MAIN,
    IMG_ID_MY_FAVORITE_TITLE_IMAGES,
    IMG_ID_MY_FAVORITE_TITLE_AUDIO,
    IMG_ID_MY_FAVORITE_TITLE_VIDEO,
    IMG_ID_MY_FAVORITE_TITLE_JAVABOX,
    IMG_ID_MY_FAVORITE_TITLE_SWFLASH,
    IMG_ID_MY_FAVORITE_TITLE_OTHERS,
    IMG_ID_MY_FAVORITE_TITLE_MEMORY_CARD,
    IMG_ID_MY_FAVORITE_FOLDER_IMAGES,
    IMG_ID_MY_FAVORITE_FOLDER_AUDIO,
    IMG_ID_MY_FAVORITE_FOLDER_VIDEO,
    IMG_ID_MY_FAVORITE_FOLDER_JAVABOX,
    IMG_ID_MY_FAVORITE_FOLDER_SWFLASH,
    IMG_ID_MY_FAVORITE_FOLDER_OTHERS,
    IMG_ID_MY_FAVORITE_FOLDER_MEMORY_CARD,
    IMG_ID_MY_FAVORITE_WAP_JAVABOX,
    IMG_ID_MY_FAVORITE_WAP_SWFLASH,
    /* add new image ID above this line */
    IMG_ID_MY_FAVORITE_END
} IMG_ID_MY_FAVORITE_ENUM;

#endif /* __MMI_MY_FAVORITE__ */ 

#endif /* MMI_MYFAVORITEDEF_H */ 

