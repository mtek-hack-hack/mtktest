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
 *    PictBridgeDef.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
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

#ifndef __PICT_BRIDGE_DEF_H__
#define __PICT_BRIDGE_DEF_H__

#ifdef __MMI_PICT_BRIDGE_SUPPORT__

#include "PictBridgeResDef.h"

#define PICT_VALUE_LEN 8
#define PICT_PROGRESS_LEN 7

#define PICT_MAX_DPS_VERSION_LEN 3
#define PICT_MAX_PRODUCT_NAME_LEN 31
#define PICT_MAX_DATE_LEN 10 /* 2007/12/15 */
#define PICT_MAX_IMAGE_LEN 4

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
#define PICT_MAX_MULTI_FILES 20
#endif

#define PICT_XML_PATH L"Z:\\@USER\\pict.xml"

/* only alphanumeric filename is allowed to print so the default name is used for not alphanumeric filename */
#define PICT_DEFAULT_FILENAME L" "

enum PICT_PAPER_SIZE
{
    PICT_PAPER_DEFAULT = 0x01,
    PICT_PAPER_POSTCARD = 0x02,
    PICT_PAPER_4x6 = 0x04,
    PICT_PAPER_LETTER = 0x08,
    PICT_PAPER_A4 = 0x10,
    PICT_PAPER_MAX = 0x20
};

enum PICT_CAPABILITY_ONOFF
{
    PICT_CAPABILITY_DEFAULT = 0x01,
    PICT_CAPABILITY_OFF = 0x02,
    PICT_CAPABILITY_ON = 0x04
};

enum PICT_QUALITY_VALUE
{
    PICT_QUALITY_DEFAULT = 0x01,
    PICT_QUALITY_NORMAL = 0x02,
    PICT_QUALITY_DRAFT = 0x04,
    PICT_QUALITY_FINE = 0x08
};

enum PICT_LAYOUT_VALUE
{
    PICT_LAYOUT_DEFAULT = 0x01,
    PICT_LAYOUT_1UP = 0x02,
    PICT_LAYOUT_2UP = 0x04,
    PICT_LAYOUT_4UP = 0x08,
    PICT_LAYOUT_INDEX = 0x10,
    PICT_LAYOUT_FULL = 0x20
};

enum PICT_ABORT_STYLE
{
    PICT_ABORT_IMMEDIATELY,
    PICT_ABORT_PAGE_END
};

enum PICT_DPS_STATUS
{
    PICT_DPS_IDLE,
    PICT_DPS_BUSY
};

enum PICT_PRINTING_STATE
{
    PICT_PRINTING_NONE,
    PICT_PRINTING_NOW,
    PICT_PRINTING_ERROR
};

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

#endif /* __PICT_BRIDGE_DEF_H__ */

