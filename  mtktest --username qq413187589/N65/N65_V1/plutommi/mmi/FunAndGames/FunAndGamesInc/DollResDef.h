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
 * DollDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Catch Doll Game ID Declare
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef GAME_DOLL_DEFS_H
#define GAME_DOLL_DEFS_H

typedef enum
{
    STR_GX_DOLL_GAME_NAME = GAME_DOLL_BASE + 1,
    STR_GX_DOLL_NEW,
    STR_GX_DOLL_RESUME,
    STR_GX_DOLL_GRADE,
    STR_GX_DOLL_HELP,
    STR_GX_DOLL_HELP_DESCRIPTION,
    STR_GX_DOLL_COUNT
} DOLL_STR_ID;

/* Image ID */
typedef enum
{
    /* Image */
    IMG_GX_DOLL_GAME_ICON = GAME_DOLL_BASE + 1,
    IMG_GX_DOLL_SEAL_0,
    IMG_GX_DOLL_SEAL_1,
    IMG_GX_DOLL_SEAL_2,
    IMG_GX_DOLL_SEAL_3,
    IMG_GX_DOLL_ARM,
    IMG_GX_DOLL_ARM_BASE,
    IMG_GX_DOLL_CLAW_0,
    IMG_GX_DOLL_CLAW_1,
    IMG_GX_DOLL_CLAW_2,
    IMG_GX_DOLL_CLAW_3,
    IMG_GX_DOLL_CHAT_BOX,
    IMG_GX_DOLL_CATCHED,
    IMG_GX_DOLL_CAN_0,
    IMG_GX_DOLL_CAN_1,
    IMG_GX_DOLL_CAN_2,
    IMG_GX_DOLL_CAN_BOX,
    IMG_GX_DOLL_COIN,
    IMG_GX_DOLL_SMALLDOLL,
    
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__    //this is used for multi-language support
    IMG_GX_DOLL_GOTEXT,
#endif    

    IMG_GX_DOLL_GRADESMAP,
    IMG_GX_DOLL_NUM_0,
    IMG_GX_DOLL_NUM_1,
    IMG_GX_DOLL_NUM_2,
    IMG_GX_DOLL_NUM_3,
    IMG_GX_DOLL_NUM_4,
    IMG_GX_DOLL_NUM_5,
    IMG_GX_DOLL_NUM_6,
    IMG_GX_DOLL_NUM_7,
    IMG_GX_DOLL_NUM_8,
    IMG_GX_DOLL_NUM_9,
    IMG_GX_DOLL_NUM_10,
    
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   //this is used for multi-language support
    IMG_GX_DOLL_GOTEXT_LANGUAGE0,
    IMG_GX_DOLL_GOTEXT_LANGUAGE1,
    IMG_GX_DOLL_GOTEXT_LANGUAGE2,
    IMG_GX_DOLL_GOTEXT_LANGUAGE3,
    IMG_GX_DOLL_GOTEXT_LANGUAGE4,
    IMG_GX_DOLL_GOTEXT_LANGUAGE5,
    IMG_GX_DOLL_GOTEXT_LANGUAGE6,
    IMG_GX_DOLL_GOTEXT_LANGUAGE7,
    IMG_GX_DOLL_GOTEXT_LANGUAGE8,
    IMG_GX_DOLL_GOTEXT_LANGUAGE9,
#endif

    IMG_GX_DOLL_COUNT
} DOLL_IMG_ID;

#endif /* GAME_DOLL_DEFS_H */ 

