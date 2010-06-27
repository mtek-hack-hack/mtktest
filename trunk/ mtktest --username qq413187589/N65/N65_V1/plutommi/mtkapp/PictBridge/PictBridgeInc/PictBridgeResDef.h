/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   PictBridgeResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for PictBridge resource definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PICT_BRIDGE_RES_DEF_H__
#define __PICT_BRIDGE_RES_DEF_H__

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_PICT_FILES = PICT_BRIDGE_BASE,
    SCR_ID_PICT_CONFIGURATION,
    SCR_ID_PICT_SETTINGS,
    SCR_ID_PICT_PREVIEW,
    SCR_ID_PICT_PRINTING,
    SCR_ID_PICT_QUERY,

    SCR_ID_PICT_CROPPING,
    SCR_ID_PICT_CROPPING_PHASE1,
    SCR_ID_PICT_CROPPING_PHASE2,
    SCR_ID_PICT_ERROR,
    SCR_ID_PICT_DUMMY,

    SCR_ID_PICT_END
} PICT_SCR_ID_ENUM;

/* String IDs */
typedef enum
{
    STR_ID_PICT_TITLE = PICT_BRIDGE_BASE + 1,
    STR_ID_PICT_CONFIGURATION,
    STR_ID_PICT_SETTINGS,
    STR_ID_PICT_PREVIEW,
    STR_ID_PICT_PRINTING,
    STR_ID_PICT_QUERY,

    STR_ID_PICT_BRIDGE,

    STR_ID_PICT_PAPER_SIZE,
    STR_ID_PICT_COPIES,
    STR_ID_PICT_PAGE_FORMAT,
    STR_ID_PICT_LAYOUT,   /* pages per sheet */
    STR_ID_PICT_BORDER,
    STR_ID_PICT_DATE_PRINT,
    STR_ID_PICT_FILENAME_PRINT,
    STR_ID_PICT_CROPPING,
    STR_ID_PICT_FIXED_SIZE,

    STR_ID_PICT_DEFAULT,
    STR_ID_PICT_ENABLE,
    STR_ID_PICT_DISABLE,
    STR_ID_PICT_STANDARD, /* page format */
    STR_ID_PICT_MULTIPLE, /* page format */
    STR_ID_PICT_INDEX,    /* page format */

    STR_ID_PICT_PAPER_POSTCARD,
    STR_ID_PICT_PAPER_4x6,
    STR_ID_PICT_PAPER_LETTER,
    STR_ID_PICT_PAPER_A4,

    STR_ID_PICT_CONTINUE,
    STR_ID_PICT_ERROR,
    STR_ID_PICT_ERROR_PAPER,
    STR_ID_PICT_ERROR_INK,
    STR_ID_PICT_ERROR_HARDWARE,
    STR_ID_PICT_ERROR_FILE,
    STR_ID_PICT_NO_PAPER,
    STR_ID_PICT_NO_INK,

    STR_ID_PICT_PRINTER_BUSY,
    STR_ID_PICT_PRINTER_REMOVED,
#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
    STR_ID_PICT_PRINTER_CONNECTED,
#endif

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    STR_ID_PICT_MAX_FILES,
#endif

    STR_ID_PICT_X_COORDINATE,
    STR_ID_PICT_Y_COORDINATE,
    STR_ID_PICT_X_ARIX,
    STR_ID_PICT_Y_ARIX,

    STR_ID_PICT_CONNECT_TO_PC,
    STR_ID_PICT_INCOMPATIBLE_FILE,
    STR_ID_PICT_FILE_DELETED,
    STR_ID_PICT_INDEX_ALL,
    STR_ID_PICT_CMD_NOT_EXECUTED,
    STR_ID_PICT_USB_RESET,
    STR_ID_INVALID_JPG_FILE,

    STR_ID_PICT_END
} PICT_STR_ID_ENUM;

/* Image IDs */
typedef enum
{
    IMG_ID_PICT_TITLE = PICT_BRIDGE_BASE + 1,
    IMG_ID_PICT_PRINTING,
    IMG_ID_PICT_LAYOUT1,
    IMG_ID_PICT_LAYOUT2,
    IMG_ID_PICT_LAYOUT4,

    IMG_ID_PICT_END
} PICT_IMG_ID_ENUM;

#endif /*__PICT_BRIDGE_RES_DEF_H__ */

