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
 * Calendar.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Calendar application.
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
 *============================================================================
 ****************************************************************************/
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Calendar.c
   Author:        GAUTAM
   Date Created:  July-12-2003
**********************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_CALENDAR_C
#define _MMI_CALENDAR_C


#ifdef __MMI_CALENDAR__

#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include "AlarmGProt.h"
#include "ProtocolEvents.h"
#include "OrganizerDef.h"

#include "AudioInc.h"
#include "CalendarDef.h"
#include "CalendarProt.h"
#include "CommonScreens.h"
#include "ToDoListEnum.h"
#include "wgui_calendar.h"

#ifdef __MMI_TODOLIST__
#include "ToDoListDef.h"
#endif 

#ifdef __MMI_CALENDAR_V2__
#endif 

#ifdef __MMI_BIRTHDAY_REMINDER__
#include "PhoneBookTypes.h"
#include "PhoneBookGprot.h"

#endif /* __MMI_BIRTHDAY_REMINDER__ */ 
/*  Include: PS header file */
/* ... Add More PS header */

#ifdef __MMI_BPP_SUPPORT__
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#include "Conversions.h"
#include "FileManagerGProt.h"
#include "SimDetectionGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif /*__USB_IN_NORMAL_MODE__*/
#endif /* __MMI_BPP_SUPPORT__ */ 
/* 
 * Define
 */
#ifdef __MMI_BPP_SUPPORT__
#define CLNDR_BPP_MAX_FILE_PATH    30
#define CLNDR_SNAPSHOT_FILE_NAME	"clndrBPP.jpg"

#endif /* __MMI_BPP_SUPPORT__ */ 
/*
 * Typedef 
 */

/* 
 * Local Variable
 */

/* the solar term days for lunarinfo by feifan 8/1/2005 */
const U8 solar_term_table[62][24] = 
{
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},       /* 1970 */
    {6, 21, 4, 19, 6, 21, 5, 21, 6, 22, 6, 22, 8, 23, 8, 24, 8, 24, 9, 24, 8, 23, 8, 22},
    {6, 21, 5, 19, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 6, 21, 5, 21, 6, 22, 6, 22, 8, 23, 8, 24, 8, 23, 9, 24, 8, 23, 8, 22},       /* 1975 */
    {6, 21, 5, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 23},
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 6, 21, 5, 21, 6, 21, 6, 22, 8, 23, 8, 24, 8, 23, 9, 24, 8, 23, 8, 22},
    {6, 21, 5, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},       /* 1980 */
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 8, 23, 8, 24, 8, 23, 9, 24, 8, 23, 8, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 5, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},       /* 1985 */
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 24, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 19, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},       /* 1990 */
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},       /* 1995 */
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},       /* 2000 */
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},       /* 2005 */
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 9, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 22, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},       /* 2010 */
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 23, 7, 22},
    {6, 21, 4, 19, 5, 20, 4, 20, 5, 20, 5, 21, 7, 22, 7, 23, 7, 22, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 22, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},       /* 2015 */
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 7, 22, 7, 23, 7, 22, 8, 23, 7, 22, 7, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 5, 21, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 6, 22, 7, 22, 7, 22, 8, 23, 7, 22, 7, 21},       /* 2020 */
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 19, 5, 20, 5, 20, 5, 21, 6, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 24, 8, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 6, 22, 7, 22, 7, 22, 8, 23, 7, 22, 6, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},       /* 2025 */
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},
    {5, 20, 4, 19, 6, 21, 5, 20, 6, 21, 6, 21, 7, 23, 8, 23, 8, 23, 8, 23, 7, 22, 7, 22},
    {6, 20, 4, 19, 5, 20, 4, 19, 5, 20, 5, 21, 6, 22, 7, 22, 7, 22, 8, 23, 7, 22, 6, 21},
    {5, 20, 3, 18, 5, 20, 4, 20, 5, 21, 5, 21, 7, 22, 7, 23, 7, 23, 8, 23, 7, 22, 7, 21},
    {5, 20, 4, 18, 5, 20, 5, 20, 5, 21, 5, 21, 7, 23, 7, 23, 7, 23, 8, 23, 7, 22, 7, 22},       /* 2030 */
};

/* number of accumulated days per solar month, non-leap year and leap year. */
const S16 gClndrAccuDays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, 396};

/* array of lunar calendar */

const clndr_lunar_table_struct gClndrLunarInfo[] = 
{
    {47, 2, 11, 0, 5482},
    {36, 3, 16, 0, 2921},   /* 1970 */
    {26, 4, 21, 5, 5970},
    {45, 5, 26, 0, 6994},
    {33, 0, 32, 0, 6949},
    {22, 1, 37, 4, 5707},
    {41, 2, 42, 0, 6731},   /* 1975 */
    {30, 3, 47, 8, 5291},
    {48, 5, 53, 0, 4781},
    {37, 6, 58, 0, 5485},
    {27, 0, 3, 6, 2921},
    {46, 1, 8, 0, 3497},    /* 1980 */
    {35, 3, 14, 0, 7570},
    {24, 4, 19, 4, 7461},
    {43, 5, 24, 0, 7461},
    {32, 6, 29, 10, 6733},
    {50, 1, 35, 0, 2646},   /* 1985 */
    {39, 2, 40, 0, 4790},
    {28, 3, 45, 6, 1461},
    {47, 4, 50, 0, 5845},
    {36, 6, 56, 0, 3785},
    {26, 0, 1, 5, 7826},    /* 1990 */
    {45, 1, 6, 0, 3730},
    {34, 2, 11, 0, 3366},
    {22, 4, 17, 3, 2646},
    {40, 5, 22, 0, 2647},
    {30, 6, 27, 8, 5334},   /* 1995 */
    {49, 0, 32, 0, 4954},
    {37, 2, 38, 0, 5845},
    {27, 3, 43, 5, 5833},
    {46, 4, 48, 0, 5961},
    {35, 5, 53, 0, 5779},   /* 2000 */
    {23, 0, 59, 4, 5419},
    {42, 1, 4, 0, 5419},
    {31, 2, 9, 0, 2651},
    {21, 3, 14, 2, 5466},
    {39, 5, 20, 0, 5482},   /* 2005 */
    {28, 6, 25, 7, 6997},
    {48, 0, 30, 0, 7076},
    {37, 1, 35, 0, 6985},
    {25, 3, 41, 5, 6803},
    {44, 4, 46, 0, 6805},   /* 2010 */
    {33, 5, 51, 0, 5421},
    {22, 6, 56, 4, 2733},
    {40, 1, 2, 0, 2741},
    {30, 2, 7, 9, 5546},
    {49, 3, 12, 0, 5586},   /* 2015 */
    {38, 4, 17, 0, 3493},
    {27, 6, 23, 6, 7498},
    {46, 0, 28, 0, 3402},
    {35, 1, 33, 0, 3222},
    {24, 2, 38, 4, 5422},   /* 2020 */
    {42, 4, 44, 0, 5462},
    {31, 5, 49, 0, 2741},
    {21, 6, 54, 2, 5554},
    {40, 0, 59, 0, 5842},
    {28, 2, 5, 6, 3749},    /* 2025 */
    {47, 3, 10, 0, 5925},
    {36, 4, 15, 0, 5707},
    {25, 5, 20, 5, 3223},
    {43, 0, 26, 0, 3243},
    {33, 1, 31, 0, 1370},   /* 2030 */
    {22, 2, 36, 3, 2774},
};

const S8 clndr_weekday[] = {'S','M','T','W','T','F','S'};
/* 
 * Local Function
 */

/* 
 * Global Variable
 */
/* the number of days for each solar month. */
U8 gClndrAddToHistory;
clndr_context_struct *g_clndr_cntx = NULL;
extern wgui_inline_item wgui_inline_items[];
extern const U8 gDaysInMonth[];

/* 
 * Global Function
 */
extern void SetCategory82Title1(U8 *);
extern void SetCategory82Title2(U8 *);
extern void SetCategory82Title3(U8 *);
extern pBOOL IsChineseSet(void);
extern MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id);
#ifdef __MMI_BPP_SUPPORT__
extern void wgui_cat8x_set_status_string(U8* message);
#endif
#define CLNDR_INITIALIZE
#ifdef __MMI_BPP_SUPPORT__
extern void mmi_bt_bpp_document_compose_done(mmi_bpp_doc_compose_enum doc_flag);
#endif

#ifdef __MMI_CALENDAR_V2__


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_week_numbers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 *  month       [IN]        
 *  weekStr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_week_numbers(U16 year, U8 month, U8 **weekStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME dt;
    U8 week, i;
    S8 asciiStr[CLNDR_HORIZON_LIST_CELL_LEN], unicodeStr[CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&dt, 0, sizeof(MYTIME));
    memset(&asciiStr, 0, CLNDR_HORIZON_LIST_CELL_LEN);
    memset(&unicodeStr, 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH);

    dt.nYear = year;
    dt.nMonth = month;
    dt.nDay = 1;

    /* get the week number of first day of the month */
    week = applib_dt_get_week_number((applib_time_struct*) & dt);

    for (i = 0; i < CLNDR_ROW; i++, week++)
    {
        sprintf(asciiStr, "%d", week);

        /* assert if the string of week number is longer than  */
        ASSERT(strlen(asciiStr) < CLNDR_HORIZON_LIST_CELL_LEN - CLNDR_WEEK_SYMBOL_LEN);

        mmi_asc_to_ucs2(unicodeStr, asciiStr);
    #ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
        mmi_ucs2ncpy((S8*) weekStr[i], GetString((U16) STR_CLNDR_WEEK_SYMBOL), CLNDR_WEEK_SYMBOL_LEN);
        mmi_ucs2ncat((S8*) weekStr[i], unicodeStr, strlen(asciiStr));
    #else
        mmi_ucs2ncpy((S8*) weekStr[i], unicodeStr, strlen(asciiStr));
    #endif        

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_date_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  date        [?]     [?]
 *  dateStr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_date_str(MYTIME *date, U8 *dateStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 asciiStr[CLNDR_TITLE_LEN], unicodeStr[CLNDR_TITLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&asciiStr, 0, CLNDR_TITLE_LEN);
    memset(&unicodeStr, 0, CLNDR_TITLE_LEN);

    /* year */
    sprintf(asciiStr, "%d", date->nYear);
    mmi_asc_to_ucs2(unicodeStr, asciiStr);
    mmi_ucs2cpy((S8*) dateStr, unicodeStr);
    mmi_ucs2cat((S8*) dateStr, (PS8) "/");

    /* month */
    if (date->nMonth < 10)
    {
        mmi_ucs2cat((S8*) dateStr, (PS8) "0");
    }
    sprintf(asciiStr, "%d", date->nMonth);
    mmi_asc_to_ucs2(unicodeStr, asciiStr);
    mmi_ucs2cat((S8*) dateStr, unicodeStr);
    mmi_ucs2cat((S8*) dateStr, (PS8) "/");

    /* month */
    if (date->nDay < 10)
    {
        mmi_ucs2cat((S8*) dateStr, (PS8) "0");
    }
    sprintf(asciiStr, "%d", date->nDay);
    mmi_asc_to_ucs2(unicodeStr, asciiStr);
    mmi_ucs2cat((S8*) dateStr, unicodeStr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_weekday
 * DESCRIPTION
 *  
 * PARAMETERS
 *  weekdayStr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_weekday(U8 **weekdayStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = CLNDR_START_WEEKDAY; i < CLNDR_TOTAL_WEEKDAY; i++)
    {
        mmi_asc_n_to_ucs2((S8*)weekdayStr[i], (S8*)&clndr_weekday[i], 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_construct_monthly_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_construct_monthly_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, taskPos, nextMonthBoundary;
    gui_calendar_cell_struct *cell;
    MYTIME preMonth, incTime, currTime;
    U8 lastDayofPreMonth;
#ifdef __MMI_BIRTHDAY_REMINDER__
    U8 pbNumber[MAX_PB_NUMBER_LENGTH + 1], pbName[(MAX_PB_NAME_LENGTH +1 )* ENCODING_LENGTH];
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&preMonth, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&currTime, 0, sizeof(MYTIME));

#ifdef __MMI_BIRTHDAY_REMINDER__
    mmi_clndr_set_birthday_table(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth);
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

    incTime.nMonth = 1;
    applib_dt_decrease_time(
        (applib_time_struct*) & (g_clndr_cntx->CalTime),
        (applib_time_struct*) & incTime,
        (applib_time_struct*) & preMonth);
    lastDayofPreMonth = applib_dt_last_day_of_mon(preMonth.nMonth, preMonth.nYear);

    cell = g_clndr_cntx->CalendarCell + (g_clndr_cntx->DayOnFirst);

    /* last month */
    for (i = g_clndr_cntx->DayOnFirst - 1; i >= 0; i--)
    {
        cell--;
        mmi_clndr_util_num_to_unicode(lastDayofPreMonth, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->valid = MMI_FALSE;
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        lastDayofPreMonth--;
    }

    /* this month */
    taskPos = 1;
#ifdef __MMI_ADVANCED_TODO__    
    mmi_tdl_get_monthly_task_with_icon(&(g_clndr_cntx->CalTime), g_clndr_cntx->TaskDayList);
#endif

    cell = g_clndr_cntx->CalendarCell + g_clndr_cntx->DayOnFirst;

    for (i = 1; i <= g_clndr_cntx->NumDaysInMonth; i++)
    {
        mmi_clndr_util_num_to_unicode(i, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->bg_index = cell->bg_index = GUI_CALENDAR_COLOR_NONE;

        if (g_clndr_cntx->TaskDayList[i].date > 0)
        {
        #ifdef __MMI_CLNDR_ICON_SUPPORT__
            cell->icon_id = g_clndr_cntx->TaskDayList[i].icon;        
        #else
            cell->bg_index = GUI_CALENDAR_COLOR_ONE_TASK;
        #endif
        }
    #ifdef __MMI_BIRTHDAY_REMINDER__
        else if (g_clndr_cntx->BirthdayInfo[i].count > 0 && mmi_phb_get_name_number(0, pbName, pbNumber) == MMI_TRUE) /* Phonebook is not ready */
        {
        #ifdef __MMI_CLNDR_ICON_SUPPORT__
            cell->icon_id = IMG_CLNDR_BIRTHDAY_REMINDER;
        #else
            cell->bg_index = GUI_CALENDAR_COLOR_ONE_TASK;
        #endif
        }
    #endif /* __MMI_BIRTHDAY_REMINDER__ */ 
    
        cell->valid = MMI_TRUE;
        cell++;
    }

    /* next month */
    nextMonthBoundary = CLNDR_ROW * CLNDR_COLUMN - (g_clndr_cntx->DayOnFirst + g_clndr_cntx->NumDaysInMonth);
    for (i = 1; i <= nextMonthBoundary; i++)
    {
        mmi_clndr_util_num_to_unicode(i, (U8*) cell->text, GUI_CALENDAR_MAX_CELL_TEXT);
        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        cell->valid = MMI_FALSE;
        cell++;
    }

}

/* wgui_cat83_cell_struct* mmi_clndr_construct_weekly_cell_info(); */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_util_num_to_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num     [IN]        
 *  str     [?]         [?]
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_util_num_to_unicode(S32 num, U8 *str, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii[CLNDR_TITLE_LEN];
    U16 value = (U16) num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ascii, 0, CLNDR_TITLE_LEN);
    sprintf(ascii, "%d", value);

    /* ASSERT(strlen(ascii) < len); */

    mmi_asc_to_ucs2((S8*) str, ascii);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_highlight_monthly_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_highlight_monthly_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetKeyHandler(mmi_pre_entry_monthly_view_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_pre_entry_monthly_view_screen, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pre_entry_monthly_view_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pre_entry_monthly_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_clndr_cntx->DisplayType = CLNDR_MONTHLY_VIEW;
    WriteValue(NVRAM_CLNDR_VIEW_TYPE, &(g_clndr_cntx->DisplayType), DS_BYTE, &error);
    g_clndr_cntx->RowNumber = CLNDR_ROW;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_monthly_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_monthly_highlight(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 totaldays;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totaldays = (row * CLNDR_COLUMN) + column + 1;
    g_clndr_cntx->CalTime.nDay = totaldays - g_clndr_cntx->DayOnFirst;
    g_clndr_cntx->CalTime.DayIndex = DOW(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nDay);
    if (g_clndr_cntx->LunarState == TRUE && IsChineseSet())
    {        
        g_clndr_cntx->LunarInfo.SolarMonth = g_clndr_cntx->CalTime.nMonth;
        g_clndr_cntx->LunarInfo.SolarYear = g_clndr_cntx->CalTime.nYear;
        g_clndr_cntx->LunarInfo.SolarDay = g_clndr_cntx->CalTime.nDay;
        ClndrComputeLunarInfo(&g_clndr_cntx->LunarInfo);
        
        wgui_calendar_set_normal_title((U8*) g_clndr_cntx->LunarInfo.TitleInfo1);        
        wgui_calendar_set_popup(
                    (U8*) g_clndr_cntx->LunarInfo.MessageLine1,
                    (U8*) g_clndr_cntx->LunarInfo.MessageLine2,
                    (U8*) g_clndr_cntx->LunarInfo.MessageLine3);
    }
    else
    {
    mmi_clndr_get_date_str(&(g_clndr_cntx->CalTime), g_clndr_cntx->Title);
    wgui_calendar_set_normal_title(g_clndr_cntx->Title);
    }

#ifdef __MMI_CLNDR_ICON_SUPPORT__    
    mmi_momthly_clndr_set_info_box();
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_monthly_compute_next_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arrow       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_monthly_compute_next_time(U32 arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME resultDate, incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&resultDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));

    switch (arrow)
    {
        case CLNDR_KEY_UP:
            incTime.nDay = CLNDR_TOTAL_WEEKDAY;
            applib_dt_decrease_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
            break;
        case CLNDR_KEY_DOWN:
            incTime.nDay = CLNDR_TOTAL_WEEKDAY;
            applib_dt_increase_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
            break;
        case CLNDR_KEY_LEFT:
            incTime.nDay = 1;
            applib_dt_decrease_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
            break;
        case CLNDR_KEY_RIGHT:
            incTime.nDay = 1;
            applib_dt_increase_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
            break;
        default:
            break;
    }

    return mmi_clndr_monthly_out_of_boundary(&resultDate);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_monthly_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resultDate      [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_monthly_out_of_boundary(MYTIME *resultDate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;
    U32 highlightDays, highlightX, highlightY;
    S32 currCell = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (resultDate->nYear > CLNDR_END_YEAR || resultDate->nYear < CLNDR_START_YEAR)
    {
        DisplayPopup(
        (U8*) GetString(STR_CLNDR_OUT_OF_CALENDAR),
        IMG_GLOBAL_WARNING,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
        
        return MMI_FALSE;
    }

    g_clndr_cntx->DayOnFirst = DOW(resultDate->nYear, resultDate->nMonth, 1);

    /* set highlight and current date */
    /* subtract 1 to compute the correct highlight position */
    highlightDays = g_clndr_cntx->DayOnFirst + resultDate->nDay - 1;
    highlightX = highlightDays % CLNDR_TOTAL_WEEKDAY;
    highlightY = highlightDays / CLNDR_TOTAL_WEEKDAY;
    wgui_calendar_set_highlight(highlightY, highlightX);

    /* move to next/previous month */
    if (g_clndr_cntx->CalTime.nMonth != resultDate->nMonth || g_clndr_cntx->CalTime.nYear != resultDate->nYear)
    {
        memcpy(&g_clndr_cntx->CalTime, resultDate, sizeof(MYTIME));

        /* get calendar information */
        memset(g_clndr_cntx->TaskDayList, 0, CLNDR_COLUMN * CLNDR_ROW * sizeof(clndr_task_icon_struct));
        g_clndr_cntx->NumDaysInMonth = LastDayOfMonth(g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nYear);

        mmi_clndr_get_date_str(&(g_clndr_cntx->CalTime), g_clndr_cntx->Title);
        mmi_clndr_get_weekday(g_clndr_cntx->HorizonList);
        mmi_clndr_get_week_numbers(
            g_clndr_cntx->CalTime.nYear,
            g_clndr_cntx->CalTime.nMonth,
            g_clndr_cntx->VerticalList);

        /* Set current date */
        GetDateTime(&currTime);
        if (currTime.nMonth == g_clndr_cntx->CalTime.nMonth && currTime.nYear == g_clndr_cntx->CalTime.nYear)
        {
            currCell = g_clndr_cntx->DayOnFirst + currTime.nDay - 1;
        }
        wgui_calendar_set_current(currCell / CLNDR_COLUMN, currCell % CLNDR_COLUMN);

        /* construct cell info */
        memset(g_clndr_cntx->CalendarCell, 0, g_clndr_cntx->RowNumber * CLNDR_COLUMN * CLNDR_CELL_SIZE);
        mmi_clndr_construct_monthly_cell_info();

        mmi_clndr_monthly_set_content();
        /* ClndrGetScreenInfo(); */
        return MMI_TRUE;
    }
    else
    {
        /* return MMI_FALSE; */
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_left_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_left_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        return mmi_clndr_monthly_compute_next_time(CLNDR_KEY_LEFT);
        /* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_LEFT, row, column); */
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    else
    {
        /* return mmi_clndr_weekly_out_of_boundary(CLNDR_KEY_LEFT, row, column); */
        return mmi_clndr_weekly_compute_next_time(CLNDR_KEY_LEFT);
    }
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_right_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_right_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        return mmi_clndr_monthly_compute_next_time(CLNDR_KEY_RIGHT);
        /* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_RIGHT, row, column); */
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    else
    {
        /* return mmi_clndr_weekly_out_of_boundary(CLNDR_KEY_RIGHT, row, column); */
        return mmi_clndr_weekly_compute_next_time(CLNDR_KEY_RIGHT);
    }
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_up_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_up_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        return mmi_clndr_monthly_compute_next_time(CLNDR_KEY_UP);
        /* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_UP, row, column); */
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    else
    {
        /* return mmi_clndr_weekly_out_of_boundary(CLNDR_KEY_UP, row, column); */
        return mmi_clndr_weekly_compute_next_time(CLNDR_KEY_UP);
    }
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_down_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_down_out_of_boundary(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        return mmi_clndr_monthly_compute_next_time(CLNDR_KEY_DOWN);
        /* return mmi_clndr_monthly_out_of_boundary(CLNDR_KEY_DOWN, row, column); */
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    else
    {
        /* return mmi_clndr_weekly_out_of_boundary(CLNDR_KEY_DOWN, row, column); */
        return mmi_clndr_weekly_compute_next_time(CLNDR_KEY_DOWN);
    }
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_up_side_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_up_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_monthly_movement(CLNDR_PRIVOUS_MONTH);
    /* return MMI_TRUE; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_down_side_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_down_side_key(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_monthly_movement(CLNDR_NEXT_MONTH);
    /* return MMI_TRUE; */
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_year_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_year_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_monthly_movement(CLNDR_NEXT_YEAR);
    /* return MMI_TRUE; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_year_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_year_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_monthly_movement(CLNDR_PRIVOUS_YEAR);
    /* return MMI_TRUE; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_month_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_month_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_monthly_movement(CLNDR_NEXT_MONTH);
    /* return MMI_TRUE; */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_month_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_month_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_monthly_movement(CLNDR_PRIVOUS_MONTH);
    /* return MMI_TRUE; */
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

/* void mmi_clndr_monthly_movement(CLNDR_CLNDAR_MOVEMENT_ENUM type) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_monthly_movement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_monthly_movement(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime, resultTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&resultTime, 0, sizeof(MYTIME));

    switch (type)
    {
        case CLNDR_PRIVOUS_MONTH:
            incTime.nMonth = 1;
            applib_dt_decrease_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultTime);
            break;

        case CLNDR_NEXT_MONTH:
            incTime.nMonth = 1;
            applib_dt_increase_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultTime);
            break;
    #ifdef __MMI_TOUCH_SCREEN__
        case CLNDR_PRIVOUS_YEAR:
            incTime.nYear = 1;
            applib_dt_decrease_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultTime);
            break;

        case CLNDR_NEXT_YEAR:
            incTime.nYear = 1;
            applib_dt_increase_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultTime);
            break;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        default:
            ASSERT(0);
    }
    resultTime.nDay = 1;

    return mmi_clndr_monthly_out_of_boundary(&resultTime);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_monthly_set_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_monthly_set_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_clndr_cntx->horizon_select1, 0, CLNDR_VERTICAL_SELECT_LEN);
    memset(g_clndr_cntx->horizon_select2, 0, CLNDR_VERTICAL_SELECT_LEN);

    mmi_clndr_util_num_to_unicode(
        g_clndr_cntx->CalTime.nYear,
        g_clndr_cntx->horizon_select1,
        CLNDR_VERTICAL_SELECT_LEN);
    mmi_clndr_util_num_to_unicode(
        g_clndr_cntx->CalTime.nMonth,
        g_clndr_cntx->horizon_select2,
        CLNDR_VERTICAL_SELECT_LEN);
    wgui_calendar_set_select_horizontal1(
        CAL_LEFT_ARROW_UP_IMAGE,
        CAL_LEFT_ARROW_DOWN_IMAGE,
        CAL_RIGHT_ARROW_UP_IMAGE,
        CAL_RIGHT_ARROW_DOWN_IMAGE,
        g_clndr_cntx->horizon_select1,
        GUI_CALENDAR_SELECT_ALIGN_CENTER);
    wgui_calendar_set_select_horizontal2(
        CAL_LEFT_ARROW_UP_IMAGE,
        CAL_LEFT_ARROW_DOWN_IMAGE,
        CAL_RIGHT_ARROW_UP_IMAGE,
        CAL_RIGHT_ARROW_DOWN_IMAGE,
        g_clndr_cntx->horizon_select2,
        GUI_CALENDAR_SELECT_ALIGN_CENTER);
    wgui_calendar_set_select_vertical(
        0,  /* monthly view has no vertical shift button */
        0,
        0,
        0,
        g_clndr_cntx->VerticalList,
        GUI_CALENDAR_SELECT_ALIGN_CELL);

#ifdef __MMI_BPP_SUPPORT__    
#ifdef __MMI_INDICAL__
    g_clndr_cntx->LunarState = mmi_clndr_get_onscreen_disp_type();
    if(g_clndr_cntx->LunarState == CHINESE_LUNAR && IsChineseSet() && g_clndr_cntx->IsBPPPreview == MMI_TRUE)
#else /*__MMI_INDICAL__*/
    if (g_clndr_cntx->LunarState == TRUE && IsChineseSet() && g_clndr_cntx->IsBPPPreview == MMI_TRUE)
#endif /*__MMI_INDICAL__*/
    {        
        g_clndr_cntx->LunarInfo.SolarMonth = g_clndr_cntx->CalTime.nMonth;
        g_clndr_cntx->LunarInfo.SolarYear = g_clndr_cntx->CalTime.nYear;
        g_clndr_cntx->LunarInfo.SolarDay = g_clndr_cntx->CalTime.nDay;
        ClndrComputeLunarInfo(&g_clndr_cntx->LunarInfo);
                
        wgui_calendar_set_normal_title((U8*) g_clndr_cntx->LunarInfo.TitleInfo1);     
    }
    else
    {
        wgui_calendar_set_normal_title(g_clndr_cntx->Title);
    }    
#else /*__MMI_BPP_SUPPORT__*/    
    wgui_calendar_set_normal_title(g_clndr_cntx->Title);
#endif /*__MMI_BPP_SUPPORT__*/     
    wgui_calendar_set_cell_array(
        g_clndr_cntx->CalendarCell,
        GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL,
        GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
        GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHT_TOP);
}

#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_pre_entry_weekly_view_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pre_entry_weekly_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currentTime;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&currentTime);

    g_clndr_cntx->DisplayType = CLNDR_WEEKLY_VIEW;
    WriteValue(NVRAM_CLNDR_VIEW_TYPE, &(g_clndr_cntx->DisplayType), DS_BYTE, &error);

    ReadValue(NVRAM_CLNDR_PERIOD_INTERVAL, &(g_clndr_cntx->PeriodInterval), DS_BYTE, &error);
    if (g_clndr_cntx->PeriodInterval == 0 || g_clndr_cntx->PeriodInterval == 0xFF)
    {
        g_clndr_cntx->PeriodInterval = CLNDR_WEEKLY_PERIOD_INTERVAL;
        WriteValue(NVRAM_CLNDR_PERIOD_INTERVAL, &(g_clndr_cntx->PeriodInterval), DS_BYTE, &error);
    }
    g_clndr_cntx->RowNumber = DLNDR_MAX_DAY_HOURS / g_clndr_cntx->PeriodInterval;
    
    g_clndr_cntx->CurrPeriodIndex = (currentTime.nHour / g_clndr_cntx->PeriodInterval);
    /* g_clndr_cntx->PeriodStartIndex = (currentTime.nHour / g_clndr_cntx->PeriodInterval); */

    /* start index is larger than limitation */
    if (g_clndr_cntx->CurrPeriodIndex > g_clndr_cntx->RowNumber - CLNDR_ROW)
    {
        g_clndr_cntx->PeriodStartIndex = g_clndr_cntx->RowNumber - CLNDR_ROW;
    }
    else
    {
        g_clndr_cntx->PeriodStartIndex = g_clndr_cntx->CurrPeriodIndex;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_highlight_weekly_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_highlight_weekly_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetKeyHandler(mmi_pre_entry_weekly_view_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_pre_entry_weekly_view_screen, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_first_date_of_week
 * DESCRIPTION
 *  
 * PARAMETERS
 *  currDate            [?]     [?]
 *  firstDateOfWeek     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_first_date_of_week(MYTIME *currDate, MYTIME *firstDateOfWeek)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 day;
    MYTIME incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));

    day = (U8) applib_dt_dow(currDate->nYear, currDate->nMonth, currDate->nDay);

    incTime.nDay = day;

    applib_dt_decrease_time(
        (applib_time_struct*) currDate,
        (applib_time_struct*) & incTime,
        (applib_time_struct*) firstDateOfWeek);
    firstDateOfWeek->nHour = firstDateOfWeek->nMin = firstDateOfWeek->nSec = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_weekly_dates
 * DESCRIPTION
 *  
 * PARAMETERS
 *  currDate        [?]         [?]
 *  dateStr         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_weekly_dates(MYTIME *currDate, U8 **dateStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, lastday, date, diffDay;
    MYTIME firstDateOfWeek;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&firstDateOfWeek, 0, sizeof(MYTIME));
    mmi_clndr_get_first_date_of_week(currDate, &firstDateOfWeek);

    diffDay = (S32) (currDate->nDay - firstDateOfWeek.nDay);
    date = firstDateOfWeek.nDay;

    /* first day of week is date of previous month */
    if (diffDay < 0)
    {
        lastday = (S32) applib_dt_last_day_of_mon(firstDateOfWeek.nMonth, firstDateOfWeek.nYear);
    }
    else
    {
        lastday = (S32) applib_dt_last_day_of_mon(currDate->nMonth, currDate->nYear);
    }

    for (i = 0; i < CLNDR_TOTAL_WEEKDAY; i++, date++)
    {
        if (date > lastday)
        {
            date = 1;
        }
        mmi_clndr_util_num_to_unicode(date, dateStr[i], CLNDR_HORIZON_LIST_CELL_LEN);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_period_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  PeriodIndex     [IN]        
 *  periodStr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_period_range(U8 PeriodIndex, U8 **periodStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, time, checkPeriod;
    U8 *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* guaranteethat the period will within the range */
    checkPeriod = (DLNDR_MAX_DAY_HOURS - CLNDR_ROW * g_clndr_cntx->PeriodInterval) / g_clndr_cntx->PeriodInterval;
    if (PeriodIndex > checkPeriod)
    {
        PeriodIndex = checkPeriod;
    }

    time = PeriodIndex * g_clndr_cntx->PeriodInterval;

    for (i = 0; i < CLNDR_ROW; i++)
    {
        ptr = periodStr[i];

        ASSERT(time < DLNDR_MAX_DAY_HOURS);

        if (time < 10)
        {
            mmi_ucs2cpy((S8*) ptr, (PS8) L"0");
            ptr += ENCODING_LENGTH;
            mmi_clndr_util_num_to_unicode(time, ptr, 1);
        }
        else
        {
            mmi_clndr_util_num_to_unicode(time, ptr, 2);
        }
    #ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
        /* ptr += (mmi_ucs2strlen(ptr) * ENCODING_LENGTH); */
        mmi_ucs2cat((S8*) ptr, (PS8) L":00");
    #endif
        time += g_clndr_cntx->PeriodInterval;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_construct_weekly_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_construct_weekly_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, dow, maxDay;
    gui_calendar_cell_struct *cell;
    MYTIME firstDay;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ADVANCED_TODO__    
    mmi_tdl_get_weekly_tasks(
        &g_clndr_cntx->CalTime,
        g_clndr_cntx->TaskDayList,
        g_clndr_cntx->PeriodInterval,
        g_clndr_cntx->RowNumber);
#endif        

    /* set the task icon and color of calendar cell */
    g_clndr_cntx->CalendarCell->bg_index = GUI_CALENDAR_COLOR_NONE;
    /* for (i = 1; i <= CLNDR_COLUMN * g_clndr_cntx->RowNumber; i++) */
    for (i = 0; i < CLNDR_COLUMN * g_clndr_cntx->RowNumber; i++)
    {
        cell = g_clndr_cntx->CalendarCell + i;
        if (g_clndr_cntx->TaskDayList[i].date > 0)
        {
            if (g_clndr_cntx->TaskDayList[i].date == 1)
            {
                cell->bg_index = GUI_CALENDAR_COLOR_ONE_TASK;
            }
            else
            {
                cell->bg_index = GUI_CALENDAR_COLOR_MORE_TASK;
            }
        #ifdef __MMI_CLNDR_ICON_SUPPORT__
            cell->icon_id = g_clndr_cntx->TaskDayList[i].icon;
        #endif /*__MMI_CLNDR_ICON_SUPPORT__*/
        }
        else
        {
            cell->bg_index = GUI_CALENDAR_COLOR_NONE;
        }
    }

    /* some date of weekly view is out of boundary */
    memset(&firstDay, 0, sizeof(MYTIME));
    mmi_clndr_get_first_date_of_week(&g_clndr_cntx->CalTime, &firstDay);
    maxDay = 31 - CLNDR_TOTAL_WEEKDAY;

    if (firstDay.nYear < CLNDR_START_YEAR)
    {
        dow = applib_dt_dow(CLNDR_START_YEAR, 1, 1);
        mmi_clndr_weekly_set_cell_validation(dow, CLNDR_LARGER_THAN_MIN_YEAR);
    }
    /* if the first day of week is larger than 2030/12/26 */
    else if (firstDay.nYear == CLNDR_END_YEAR && firstDay.nMonth == NUM_MONTHS && firstDay.nDay >= maxDay)
    {
        dow = applib_dt_dow(CLNDR_END_YEAR, 12, 31);
        mmi_clndr_weekly_set_cell_validation(dow, CLNDR_LARGER_THAN_MAX_YEAR);
    }
    else
    {
        cell = g_clndr_cntx->CalendarCell;
        for (i = 0; i < g_clndr_cntx->RowNumber * CLNDR_COLUMN; i++)
        {
            cell->valid = MMI_TRUE;
            cell++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_set_cell_validation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dow         [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_weekly_set_cell_validation(U32 dow, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    gui_calendar_cell_struct* cell = g_clndr_cntx->CalendarCell;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            for (i = 0; i < g_clndr_cntx->RowNumber; i++)
            {
                for (j = 0; j< CLNDR_COLUMN; j++)
                {                    
                    if ((type == CLNDR_LARGER_THAN_MAX_YEAR && j > dow) ||
                        (type == CLNDR_LARGER_THAN_MIN_YEAR && j < dow)) /* the date is larger than boundary */
                    {
                        memset(cell, 0, sizeof(gui_calendar_cell_struct));
                        cell->bg_index = GUI_CALENDAR_COLOR_NONE;
                    }
                    else
                    {
                        cell->valid = MMI_TRUE;
                    }
                    cell++;
                }
            }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_highlight(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME firstDayofWeek, incTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&firstDayofWeek, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));
    mmi_clndr_get_first_date_of_week(&(g_clndr_cntx->CalTime), &firstDayofWeek);

    incTime.nDay = column;
    IncrementTime(firstDayofWeek, incTime, &g_clndr_cntx->CalTime);

    g_clndr_cntx->CalTime.DayIndex = DOW(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nDay);
    g_clndr_cntx->CurrPeriodIndex = g_clndr_cntx->PeriodStartIndex + row;
    g_clndr_cntx->CalTime.nHour = g_clndr_cntx->CurrPeriodIndex * g_clndr_cntx->PeriodInterval;

    mmi_clndr_get_date_str(&(g_clndr_cntx->CalTime), g_clndr_cntx->Title);
    wgui_calendar_set_normal_title(g_clndr_cntx->Title);

    if (g_clndr_cntx->CalTime.nMonth == 1 || g_clndr_cntx->CalTime.nMonth == 12)
    {
        g_clndr_cntx->WeekNum = applib_dt_get_week_number((applib_time_struct*) & g_clndr_cntx->CalTime);
        mmi_clndr_weekly_set_content();
    }

#ifdef __MMI_CLNDR_ICON_SUPPORT__
    mmi_weekly_clndr_set_info_box();
#endif

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_compute_next_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arrow       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_compute_next_time(U32 arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME resultDate, incTime;
    U32 highlightY=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&resultDate, 0, sizeof(MYTIME));
    memset(&incTime, 0, sizeof(MYTIME));

    switch (arrow)
    {
        case CLNDR_KEY_UP:
            if (g_clndr_cntx->CurrPeriodIndex > 0)
            {
                g_clndr_cntx->CurrPeriodIndex--;
                g_clndr_cntx->PeriodStartIndex--;
                memcpy(&resultDate, &(g_clndr_cntx->CalTime), sizeof(MYTIME));
            }
            else
            {
                return MMI_FALSE;
            }
            break;
        case CLNDR_KEY_DOWN:
            if (g_clndr_cntx->CurrPeriodIndex < g_clndr_cntx->RowNumber - 1)
            {
                g_clndr_cntx->CurrPeriodIndex++;
                g_clndr_cntx->PeriodStartIndex++;
                memcpy(&resultDate, &(g_clndr_cntx->CalTime), sizeof(MYTIME));
            }
            else
            {
                return MMI_FALSE;
            }
            break;
        case CLNDR_KEY_LEFT:
            incTime.nDay = 1;
            applib_dt_decrease_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
            /* highlight date become the last day of previous week */
            highlightY = g_clndr_cntx->CurrPeriodIndex - g_clndr_cntx->PeriodStartIndex;
            break;
        case CLNDR_KEY_RIGHT:
            incTime.nDay = 1;
            applib_dt_increase_time(
                (applib_time_struct*) & (g_clndr_cntx->CalTime),
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & resultDate);
            /* highlight date become the first day of next week */
            highlightY = g_clndr_cntx->CurrPeriodIndex - g_clndr_cntx->PeriodStartIndex;
            break;
        default:
            break;
    }

    return mmi_clndr_weekly_out_of_boundary(&resultDate, highlightY);
}

/* MMI_BOOL mmi_clndr_weekly_out_of_boundary(U32 arrow, U32 row, U32 column) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_out_of_boundary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resultDate          [?]         
 *  highlightRow        [IN]        
 *  highlightCol        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_out_of_boundary(MYTIME *resultDate, U32 highlightRow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U32 highlightY; */

    if (resultDate->nYear > CLNDR_END_YEAR || resultDate->nYear < CLNDR_START_YEAR)
    {
         DisplayPopup(
        (U8*) GetString(STR_CLNDR_OUT_OF_CALENDAR),
        IMG_GLOBAL_WARNING,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
         
        return MMI_FALSE;
    }

    /* If the date changed, update the highlight period */
    /* if (arrow == CLNDR_KEY_LEFT || arrow == CLNDR_KEY_RIGHT) */
    if (g_clndr_cntx->CalTime.nYear != resultDate->nYear ||
        g_clndr_cntx->CalTime.nMonth != resultDate->nMonth || g_clndr_cntx->CalTime.nDay != resultDate->nDay)
    {
        /* highlightY = g_clndr_cntx->CurrPeriodIndex - g_clndr_cntx->PeriodStartIndex; */
        memcpy(&g_clndr_cntx->CalTime, resultDate, sizeof(MYTIME));
        wgui_calendar_set_current(0xFFFFFFFF, 0xFFFFFFFF);
        wgui_calendar_set_highlight(highlightRow, g_clndr_cntx->CalTime.DayIndex);

        memset(g_clndr_cntx->TaskDayList, 0, CLNDR_COLUMN * CLNDR_ROW * sizeof(clndr_task_icon_struct));
        memset(g_clndr_cntx->CalendarCell, 0, g_clndr_cntx->RowNumber * CLNDR_COLUMN * CLNDR_CELL_SIZE);
        //mmi_clndr_get_weekly_dates(&g_clndr_cntx->CalTime, g_clndr_cntx->HorizonList);
        //mmi_clndr_get_date_str(&(g_clndr_cntx->CalTime), g_clndr_cntx->Title);        
        /* todo : compute the start period index */
        /* mmi_clndr_construct_weekly_cell_info(); */
        ClndrGetScreenInfo();
    }
    else
    {
        mmi_clndr_get_period_range(g_clndr_cntx->PeriodStartIndex, g_clndr_cntx->VerticalList);
        wgui_calendar_set_select_vertical(
            IMG_TOP_UP,
            IMG_TOP_DOWN,
            IMG_BOTTOM_UP,
            IMG_BOTTOM_DOWN,
            g_clndr_cntx->VerticalList,
            GUI_CALENDAR_SELECT_ALIGN_LINE);
    }
    mmi_clndr_weekly_set_content();

    return MMI_TRUE;
}

/* void mmi_clndr_weekly_movement(CLNDR_CLNDAR_MOVEMENT_ENUM type) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_movement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_movement(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime, firstDay;
    U32 highlightY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&incTime, 0, sizeof(MYTIME));
    memset(&firstDay, 0, sizeof(MYTIME));


    switch (type)
    {
        case CLNDR_PRIVOUS_WEEK:
            incTime.nDay = 7;
            applib_dt_decrease_time(
                (applib_time_struct*) & g_clndr_cntx->CalTime,
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & firstDay);
            break;

        case CLNDR_NEXT_WEEK:
            incTime.nDay = 7;
            applib_dt_increase_time(
                (applib_time_struct*) & g_clndr_cntx->CalTime,
                (applib_time_struct*) & incTime,
                (applib_time_struct*) & firstDay);
            break;

    #ifdef __MMI_TOUCH_SCREEN__

        case CLNDR_NEXT_PERIOD:
            /* the boundary of period */
            if (g_clndr_cntx->PeriodStartIndex == g_clndr_cntx->RowNumber - CLNDR_ROW)
            {
                return MMI_FALSE;
            }
            g_clndr_cntx->CalTime.nHour += g_clndr_cntx->PeriodInterval;
            g_clndr_cntx->PeriodStartIndex++;
            /* return; */

        case CLNDR_PRIVOUS_PERIOD:
            /* the boundary of period */
            if (g_clndr_cntx->PeriodStartIndex == 0)
            {
                return MMI_FALSE;
            }
            g_clndr_cntx->CalTime.nHour -= g_clndr_cntx->PeriodInterval;
            g_clndr_cntx->PeriodStartIndex++;
            /* return; */

        case CLNDR_NEXT_MULTI_PERIOD:
            break;
        case CLNDR_PRIVOUS_MULTI_PERIOD:
            break;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        default:
            ASSERT(0);
    }
    highlightY = g_clndr_cntx->CurrPeriodIndex - g_clndr_cntx->PeriodStartIndex;

    return mmi_clndr_weekly_out_of_boundary(&firstDay, highlightY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_period_interval
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_clndr_get_period_interval(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 interval;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CLNDR_PERIOD_INTERVAL, &interval, DS_BYTE, &error);
    return interval;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_weekly_set_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_weekly_set_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__     
    U32 j;
#endif
    U8* str;
    gui_calendar_cell_struct *cell;
    MYTIME currTime, compareTime, resultTime;
    U8 currWeekNumber, lastWeekNumber;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_clndr_cntx->horizon_select1, 0, CLNDR_VERTICAL_SELECT_LEN);
    memset(g_clndr_cntx->horizon_select2, 0, CLNDR_VERTICAL_SELECT_LEN);
    GetDateTime(&currTime);

#ifdef __MMI_TOUCH_SCREEN__ 
    str = g_clndr_cntx->horizon_select1;
    mmi_ucs2cpy((S8*)str, (S8*)L"W");
    str += ENCODING_LENGTH;
    mmi_clndr_util_num_to_unicode(g_clndr_cntx->WeekNum, str, CLNDR_VERTICAL_SELECT_LEN);
    wgui_calendar_set_select_horizontal1(CAL_LEFT_ARROW_UP_IMAGE, CAL_LEFT_ARROW_DOWN_IMAGE, CAL_RIGHT_ARROW_UP_IMAGE, CAL_RIGHT_ARROW_DOWN_IMAGE, g_clndr_cntx->horizon_select1, GUI_CALENDAR_SELECT_ALIGN_CENTER);
    
    j = g_clndr_cntx->PeriodInterval * CLNDR_ROW;
    if (j < CLNDR_MAX_ROW)
    {
        mmi_clndr_util_num_to_unicode(j, g_clndr_cntx->horizon_select2, CLNDR_VERTICAL_SELECT_LEN);
        wgui_calendar_set_select_horizontal2(IMG_HOUR_SUBTRACT_UP, IMG_HOUR_SUBTRACT_DOWN, IMG_HOUR_PLUS_UP, IMG_HOUR_PLUS_DOWN, g_clndr_cntx->horizon_select2, GUI_CALENDAR_SELECT_ALIGN_CENTER);
        mmi_ucs2cat((S8*)g_clndr_cntx->horizon_select2,(S8*) L" H");
    }
#else
    str = g_clndr_cntx->horizon_select1;
    mmi_ucs2ncpy((S8*)str, (S8*)GetString(STR_CLNDR_WEEK_STRING), (CLNDR_VERTICAL_SELECT_LEN / ENCODING_LENGTH) - 1);
    wgui_calendar_set_select_horizontal1(CAL_LEFT_ARROW_UP_IMAGE, CAL_LEFT_ARROW_DOWN_IMAGE, CAL_RIGHT_ARROW_UP_IMAGE, CAL_RIGHT_ARROW_DOWN_IMAGE, g_clndr_cntx->horizon_select1, GUI_CALENDAR_SELECT_ALIGN_CENTER);

    str = g_clndr_cntx->horizon_select2;
    mmi_clndr_util_num_to_unicode(g_clndr_cntx->WeekNum, str, CLNDR_VERTICAL_SELECT_LEN);
    wgui_calendar_set_select_horizontal2(IMG_HOUR_SUBTRACT_UP, IMG_HOUR_SUBTRACT_DOWN, IMG_HOUR_PLUS_UP, IMG_HOUR_PLUS_DOWN, g_clndr_cntx->horizon_select2, GUI_CALENDAR_SELECT_ALIGN_CENTER);
    
#endif    
    wgui_calendar_set_normal_title(g_clndr_cntx->Title);

    currWeekNumber = applib_dt_get_week_number((applib_time_struct*)&currTime);

    memset(&compareTime, 0, sizeof(MYTIME));
    compareTime.nYear = currTime.nYear - 1;
    compareTime.nMonth= 12;
    compareTime.nDay = 31;   
    lastWeekNumber = applib_dt_get_week_number((applib_time_struct*)&compareTime);    
    
    if (currWeekNumber == g_clndr_cntx->WeekNum && currTime.nYear == g_clndr_cntx->CalTime.nYear)
    {
        wgui_calendar_set_horizontal_string(g_clndr_cntx->HorizonList, currTime.DayIndex);
    }
    else if (currWeekNumber == 1 && g_clndr_cntx->WeekNum == lastWeekNumber && currTime.nYear == g_clndr_cntx->CalTime.nYear + 1)
    {             
        applib_get_time_difference((applib_time_struct *)&currTime, (applib_time_struct *)&(g_clndr_cntx->CalTime), (applib_time_struct *)&resultTime);
        if (resultTime.nDay < 7)
        {
            wgui_calendar_set_horizontal_string(g_clndr_cntx->HorizonList, currTime.DayIndex);
        }
    }
    else if (currWeekNumber == lastWeekNumber && g_clndr_cntx->WeekNum == 1 && currTime.nYear == g_clndr_cntx->CalTime.nYear - 1)
    {
        memset(&compareTime, 0, sizeof(MYTIME));
        compareTime.nYear = currTime.nYear + 1;
        compareTime.nMonth= 1;
        compareTime.nDay = 1;        
        applib_get_time_difference((applib_time_struct *)&(g_clndr_cntx->CalTime), (applib_time_struct *)&currTime, (applib_time_struct *)&resultTime);
        if (resultTime.nDay < 7)
        {
            wgui_calendar_set_horizontal_string(g_clndr_cntx->HorizonList, currTime.DayIndex);
        }
    }
    else
    {
        wgui_calendar_set_horizontal_string(g_clndr_cntx->HorizonList, 0xFF);
    }

    /* mmi_clndr_get_period_range(g_clndr_cntx->PeriodStartIndex, g_clndr_cntx->VerticalList); */
    wgui_calendar_set_select_vertical(
        IMG_TOP_UP,
        IMG_TOP_DOWN,
        IMG_BOTTOM_UP,
        IMG_BOTTOM_DOWN,
        g_clndr_cntx->VerticalList,
        GUI_CALENDAR_SELECT_ALIGN_LINE);

    cell = g_clndr_cntx->CalendarCell + g_clndr_cntx->PeriodStartIndex * CLNDR_COLUMN;
    wgui_calendar_set_cell_array(
        /* g_clndr_cntx->CalendarCell, */ cell,
        GUI_CALENDAR_CELL_BG_FILL_VERTICAL,
        GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
        GUI_CALENDAR_CELL_ICON_DISPLAY_CENTER);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_weekly_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_weekly_movement(CLNDR_NEXT_WEEK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_weekly_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_weekly_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_weekly_movement(CLNDR_PRIVOUS_WEEK);
}

#ifdef __MMI_TOUCH_SCREEN__   

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_multi_periodly_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_multi_periodly_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_periodly_movement((U32) CLNDR_NEXT_MULTI_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_multi_periodly_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_multi_periodly_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_periodly_movement((U32) CLNDR_PRIVOUS_MULTI_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_single_periodly_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_single_periodly_increase(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_periodly_movement((U32) CLNDR_NEXT_PERIOD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_touch_single_periodly_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  row         [IN]        
 *  column      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_touch_single_periodly_decrease(U32 row, U32 column)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clndr_periodly_movement((U32) CLNDR_PRIVOUS_PERIOD);
}

/* void mmi_clndr_periodly_movement(CLNDR_CLNDAR_MOVEMENT type) */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_periodly_movement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clndr_periodly_movement(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 highlightY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlightY = g_clndr_cntx->CurrPeriodIndex - g_clndr_cntx->PeriodStartIndex;

    switch (type)
    {
        case CLNDR_NEXT_PERIOD:
            /* the boundary of period */
            if (g_clndr_cntx->PeriodStartIndex == g_clndr_cntx->RowNumber - CLNDR_ROW)
            {
                return MMI_FALSE;
            }
            /* clndr_cntx->CalTime.nHour += g_clndr_cntx->PeriodInterval; */
            g_clndr_cntx->PeriodStartIndex++;
            if (highlightY > 0)
            {
                highlightY--;
            }
            break;
            /* return; */

        case CLNDR_PRIVOUS_PERIOD:
            /* the boundary of period */
            if (g_clndr_cntx->PeriodStartIndex == 0)
            {
                return MMI_FALSE;
            }
            /* clndr_cntx->CalTime.nHour -= g_clndr_cntx->PeriodInterval; */
            g_clndr_cntx->PeriodStartIndex--;
            if (highlightY < CLNDR_ROW - 1)
            {
                highlightY++;
            }
            break;
            /* return; */

        case CLNDR_NEXT_MULTI_PERIOD:
            g_clndr_cntx->PeriodStartIndex += CLNDR_ROW;

            if (g_clndr_cntx->PeriodStartIndex >= g_clndr_cntx->RowNumber - CLNDR_ROW)
            {
                g_clndr_cntx->PeriodStartIndex = g_clndr_cntx->RowNumber - CLNDR_ROW;
            }
            break;

        case CLNDR_PRIVOUS_MULTI_PERIOD:
            if (g_clndr_cntx->PeriodStartIndex <= CLNDR_ROW)
            {
                g_clndr_cntx->PeriodStartIndex = 0;
            }
            else
            {
                g_clndr_cntx->PeriodStartIndex -= CLNDR_ROW;
            }
            break;

        default:
            ASSERT(0);
    }

    mmi_clndr_get_period_range(g_clndr_cntx->PeriodStartIndex, g_clndr_cntx->VerticalList);
    wgui_calendar_set_select_vertical(
        IMG_TOP_UP,
        IMG_TOP_DOWN,
        IMG_BOTTOM_UP,
        IMG_BOTTOM_DOWN,
        g_clndr_cntx->VerticalList,
        GUI_CALENDAR_SELECT_ALIGN_LINE);
    mmi_clndr_weekly_set_content();
    wgui_calendar_set_highlight(highlightY, g_clndr_cntx->CalTime.DayIndex);

    return MMI_TRUE;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

#ifdef __MMI_TODOLIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_prepare_for_add_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_prepare_for_add_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tdl_set_clndr(&g_clndr_cntx->CalTime, g_clndr_cntx->DisplayType);
    /* TDLAddDefaultRecord(); */
#ifdef __MMI_ADVANCED_TODO__
    mmi_tdl_entry_select_task_type();
#else
    TdlExecEdit();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_highlight_add_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_highlight_add_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tdl_cntx.CurrHiliteOption = TODO_LIST_TASK_OPTION_ADD;    /* set tdl option as "ADD" */

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetKeyHandler(mmi_prepare_for_add_task, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_prepare_for_add_task, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* __MMI_TODOLIST__ */ 

#ifdef __MMI_CLNDR_ICON_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_momthly_clndr_set_info_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_momthly_clndr_set_info_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    clndr_task_icon_struct task;

    /* ToDoListNode todoItem; */
    U8 taskNum[6];  /* two digits number */
    S8 timeString[CLNDR_TIME_STRING_LENGTH * 2 + 1 + 1];    /* HH:MM-HH:MM\0 */
#ifdef __MMI_BIRTHDAY_REMINDER__    
    U8 pbNumber[MAX_PB_NUMBER_LENGTH + 1], pbName[(MAX_PB_NAME_LENGTH +1 )* ENCODING_LENGTH];
    U8 maxStrLen;
    MMI_BOOL phb_result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_clndr_cntx->info_box_text[0], 0, CLNDR_MAX_INFO_BOX_LEN + ENCODING_LENGTH);
    memset(g_clndr_cntx->info_box_text[1], 0, CLNDR_MAX_INFO_BOX_LEN + ENCODING_LENGTH);
    g_clndr_cntx->info_box_icon[0] = 0;
    g_clndr_cntx->info_box_icon[1] = 0;

    memcpy(&task, &(g_clndr_cntx->TaskDayList[g_clndr_cntx->CalTime.nDay]), sizeof(clndr_task_icon_struct));

#ifdef __MMI_BIRTHDAY_REMINDER__
    if (g_clndr_cntx->BirthdayInfo[g_clndr_cntx->CalTime.nDay].count > 0)       /* someone's birthday */
    {
        /* birthday reminder */
        memset(pbNumber, 0, MAX_PB_NUMBER_LENGTH + 1);
        memset(pbName, 0, (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
        phb_result = mmi_phb_get_name_number(
            g_clndr_cntx->BirthdayInfo[g_clndr_cntx->CalTime.nDay].firstMatchedIndex,
            pbName,
            pbNumber);

        if (phb_result == MMI_TRUE)
        {
			g_clndr_cntx->info_box_icon[0] = IMG_CLNDR_BIRTHDAY_REMINDER;
            mmi_ucs2cpy((S8*) g_clndr_cntx->info_box_text[0], (PS8) L"(");
            mmi_clndr_util_num_to_unicode(g_clndr_cntx->BirthdayInfo[g_clndr_cntx->CalTime.nDay].count, taskNum, 3);
            mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (S8*) taskNum);
            mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (PS8) L") ");
    
            maxStrLen = (CLNDR_MAX_INFO_BOX_LEN / ENCODING_LENGTH) - mmi_ucs2strlen((S8*)L"() ") - mmi_ucs2strlen((S8*)taskNum);
            if(mmi_ucs2strlen((S8*)pbName) > maxStrLen)
            {
                mmi_ucs2ncat((S8*)g_clndr_cntx->info_box_text[0], (S8*)pbName, (U32)maxStrLen);
            }
            else
            {
                mmi_ucs2cat((S8*)g_clndr_cntx->info_box_text[0], (S8*)pbName);
            }
        }
        
        /* todo reminder */
        if (task.date > 0)
        {
            g_clndr_cntx->info_box_icon[1] = task.icon;
                       
            mmi_ucs2cpy((S8*) g_clndr_cntx->info_box_text[1], (PS8) L"(");
            mmi_clndr_util_num_to_unicode(task.date, taskNum, 3);
            mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[1], (S8*) taskNum);
            mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[1], (PS8) L") ");

            if(mmi_ucs2strlen((S8*)task.maxPriorityTask->Note) > maxStrLen)
            {
                mmi_ucs2ncat((S8*)g_clndr_cntx->info_box_text[1], (S8*)task.maxPriorityTask->Note, (U32)maxStrLen);
            }
            else
            {
                mmi_ucs2cat((S8*)g_clndr_cntx->info_box_text[1], (S8*)task.maxPriorityTask->Note);
            }
        }
    }
    else
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 
    if (task.date > 0)
    {
        g_clndr_cntx->info_box_icon[0] = IMG_CLNDR_TASK_CLOCK;
        memset(timeString, 0, CLNDR_TIME_STRING_LENGTH * 2 + 1 + 1);

        mmi_tdl_get_time_string(
            task.maxPriorityTask,
            &(g_clndr_cntx->CalTime),
            timeString);
        mmi_asc_to_ucs2((S8*) g_clndr_cntx->info_box_text[0], (S8*) timeString);

        mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (PS8) L"(");
        mmi_clndr_util_num_to_unicode(task.date, taskNum, 2);
        mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (S8*) taskNum);
        mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (PS8) L"-1)");

        g_clndr_cntx->info_box_icon[1] = task.icon;
        memcpy(g_clndr_cntx->info_box_text[1], task.maxPriorityTask->Note, CLNDR_MAX_INFO_BOX_LEN);

    }
    else
    {
        g_clndr_cntx->info_box_icon[0] = 0;
        g_clndr_cntx->info_box_icon[1] = 0;
    }
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    wgui_calendar_set_infobox(g_clndr_cntx->info_box_icon, g_clndr_cntx->info_box_text, CLNDR_INFO_BOX_ROW);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_weekly_clndr_set_info_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_weekly_clndr_set_info_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    clndr_task_icon_struct task;
    ToDoListNode todoItem;
    U8 taskNum[6];                                          /* two digits number */
    S8 timeString[CLNDR_TIME_STRING_LENGTH * 2 + 1 + 1];    /* hh:mm-hh:mm\0 */
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_clndr_cntx->info_box_text[0], 0, CLNDR_MAX_INFO_BOX_LEN + ENCODING_LENGTH);
    memset(g_clndr_cntx->info_box_text[1], 0, CLNDR_MAX_INFO_BOX_LEN + ENCODING_LENGTH);

    index = g_clndr_cntx->CurrPeriodIndex * CLNDR_COLUMN + g_clndr_cntx->CalTime.DayIndex;
    memcpy(&task, &(g_clndr_cntx->TaskDayList[index]), sizeof(clndr_task_icon_struct));
    if (task.date > 0)
    {
        memcpy(&todoItem, task.maxPriorityTask, sizeof(ToDoListNode));

        g_clndr_cntx->info_box_icon[0] = IMG_CLNDR_TASK_CLOCK;

        memset(timeString, 0, CLNDR_TIME_STRING_LENGTH * 2 + 1 + 1);
        
        /* start time */
        mmi_tdl_get_time_string(
            task.maxPriorityTask,
            &(g_clndr_cntx->CalTime),
            timeString);
        mmi_asc_to_ucs2((S8*) g_clndr_cntx->info_box_text[0], timeString);
        
        mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (PS8) L"(");
        mmi_clndr_util_num_to_unicode(task.date, taskNum, 2);
        mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (S8*) taskNum);
        mmi_ucs2cat((S8*) g_clndr_cntx->info_box_text[0], (PS8) L"-1)");

	 g_clndr_cntx->info_box_icon[1] = todoItem.Type + IMG_CLNDR_ICON_REMINDER;

        memcpy(g_clndr_cntx->info_box_text[1], task.maxPriorityTask->Note, CLNDR_MAX_INFO_BOX_LEN);

        //g_clndr_cntx->info_box_icon[1] = task.maxPriorityTask->Type + IMG_CLNDR_ICON_MEETING;
        //memcpy(g_clndr_cntx->info_box_text[1],task.maxPriorityTask->Note, CLNDR_MAX_INFO_BOX_LEN);
    }
    else
    {
        g_clndr_cntx->info_box_icon[0] = 0;
        g_clndr_cntx->info_box_icon[1] = 0;
        /* g_clndr_cntx->info_box_icon[1] = NULL; */
    }

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    wgui_calendar_set_infobox(g_clndr_cntx->info_box_icon, g_clndr_cntx->info_box_text, CLNDR_INFO_BOX_ROW);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
}

#endif /* __MMI_CLNDR_ICON_SUPPORT__ */ 

#else /* __MMI_CALENDAR_V2__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightClndrDate
 * DESCRIPTION
 *  Highlight handler of a date on calendar
 * PARAMETERS
 *  date        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightClndrDate(S32 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_clndr_cntx->CalTime.nDay = (U8) date;
}

#endif /* __MMI_CALENDAR_V2__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_set_date
 * DESCRIPTION
 *  
 * PARAMETERS
 *  date        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_set_date(MYTIME *date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx != NULL)
    {
        memcpy(&(g_clndr_cntx->CalTime), date, sizeof(MYTIME));
    }
}


/*****************************************************************************
 * FUNCTION
 *  ClndrInit
 * DESCRIPTION
 *  Register highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(ORGANIZER_CALENDER_MENU, HighlightClndrMenu);
    SetHintHandler(MENU_CAL_TYPE, ClndrLunarHintHandler);
    SetHiliteHandler(MENU_GOTO_TASK_CAL, HighlightClndrViewTask);
    SetHiliteHandler(MENU_CAL_TYPE, HighlightClndrLunar);
    SetHiliteHandler(MENU_ID_CLNDR_JUMP_TO_DATE, HighlightJumpToDate);
#ifdef __MMI_CALENDAR_V2__
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    SetHiliteHandler(MENU_ID_CLNDR_MONTHLY_VIEW, mmi_clndr_highlight_monthly_view);
    SetHiliteHandler(MENU_ID_CLNDR_WEEKLY_VIEW, mmi_clndr_highlight_weekly_view);
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
#ifdef __MMI_TODOLIST__
    SetHiliteHandler(MENU_ID_CLNDR_ADD_TASK, mmi_clndr_highlight_add_task);
#endif
#endif /* __MMI_CALENDAR_V2__ */ 
#ifdef __MMI_BPP_SUPPORT__
    SetHiliteHandler(MENU_ID_CLNDR_BPP_PRINT, mmi_clndr_highlight_bpp_print);
#endif /*__MMI_BPP_SUPPORT__*/

}


/*****************************************************************************
 * FUNCTION
 *  ClndrDeInit
 * DESCRIPTION
 *  Free allocated memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 ClndrDeInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_clndr_cntx->Title != NULL)
    {
        mmi_frm_scrmem_free((void*)g_clndr_cntx->Title);
        g_clndr_cntx->Title = NULL;
    }

    if (g_clndr_cntx->HorizonList[0] != NULL)
    {
        mmi_frm_scrmem_free((void*)g_clndr_cntx->HorizonList[0]);
        g_clndr_cntx->HorizonList[0] = NULL;
    }

    if (g_clndr_cntx->VerticalList[0] != NULL)
    {
        mmi_frm_scrmem_free((void*)g_clndr_cntx->VerticalList[0]);
        g_clndr_cntx->VerticalList[0] = NULL;
    }

    if (g_clndr_cntx->CalendarCell != NULL)
    {
        mmi_frm_scrmem_free((void*)g_clndr_cntx->CalendarCell);
        g_clndr_cntx->CalendarCell = NULL;
    }

#ifdef __MMI_CLNDR_ICON_SUPPORT__    
    if (g_clndr_cntx->info_box_text[0] != NULL)
    {
        OslMfree(g_clndr_cntx->info_box_text[0]);
        OslMfree(g_clndr_cntx->info_box_text[1]);

        g_clndr_cntx->info_box_text[0] = NULL;
        g_clndr_cntx->info_box_text[1] = NULL;
    }
#endif /*__MMI_CLNDR_ICON_SUPPORT__    */
    
    if (g_clndr_cntx)
    {
        OslMfree(g_clndr_cntx);
        g_clndr_cntx = NULL;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightClndrMenu
 * DESCRIPTION
 *  Highlight handler of Calendar menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightClndrMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(ClndrPreEntryApp, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(ClndrPreEntryApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define CLNDR_APP_SCREEN


/*****************************************************************************
 * FUNCTION
 *  ClndrPreEntryApp
 * DESCRIPTION
 *  Initialize variables and go to calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrPreEntryApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currentTime;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx == NULL)
    {
        g_clndr_cntx = OslMalloc(sizeof(clndr_context_struct));
    }

    GetDateTime(&currentTime);

    memset(&g_clndr_cntx->CalTime, 0, sizeof(MYTIME));

    g_clndr_cntx->CalTime.nDay = currentTime.nDay;
    g_clndr_cntx->CalTime.nMonth = currentTime.nMonth;
    g_clndr_cntx->CalTime.nYear = currentTime.nYear;
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    g_clndr_cntx->CalTime.nHour = currentTime.nHour;

    ReadValue(NVRAM_CLNDR_PERIOD_INTERVAL, &(g_clndr_cntx->PeriodInterval), DS_BYTE, &error);
    if (g_clndr_cntx->PeriodInterval == 0 || g_clndr_cntx->PeriodInterval == 0xFF)
    {
        g_clndr_cntx->PeriodInterval = CLNDR_WEEKLY_PERIOD_INTERVAL;
        WriteValue(NVRAM_CLNDR_PERIOD_INTERVAL, &(g_clndr_cntx->PeriodInterval), DS_BYTE, &error);
    }
    
    g_clndr_cntx->PeriodStartIndex = (currentTime.nHour / g_clndr_cntx->PeriodInterval);
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

    /* lunar state */
    ReadValue(LUNAR_CALENDAR, (void*)&g_clndr_cntx->LunarState, DS_BYTE, &error);

    if (g_clndr_cntx->LunarState != TRUE)
    {
        g_clndr_cntx->LunarState = FALSE;
    }
#ifdef __MMI_CALENDAR_V2__

    ReadValue(NVRAM_CLNDR_VIEW_TYPE, &(g_clndr_cntx->DisplayType), DS_BYTE, &error);
    if (g_clndr_cntx->DisplayType != CLNDR_MONTHLY_VIEW && g_clndr_cntx->DisplayType != CLNDR_WEEKLY_VIEW)
    {
        g_clndr_cntx->DisplayType = CLNDR_MONTHLY_VIEW;
        WriteValue(NVRAM_CLNDR_VIEW_TYPE, &(g_clndr_cntx->DisplayType), DS_BYTE, &error);
    }

    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        g_clndr_cntx->RowNumber = CLNDR_ROW;
    }
    else
    {
        ReadValue(NVRAM_CLNDR_PERIOD_INTERVAL, &(g_clndr_cntx->PeriodInterval), DS_BYTE, &error);
        if (g_clndr_cntx->PeriodInterval == 0 || g_clndr_cntx->PeriodInterval == 0xFF)
        {
            g_clndr_cntx->PeriodInterval = CLNDR_WEEKLY_PERIOD_INTERVAL;
            WriteValue(NVRAM_CLNDR_PERIOD_INTERVAL, &(g_clndr_cntx->PeriodInterval), DS_BYTE, &error);
        }
        g_clndr_cntx->RowNumber = DLNDR_MAX_DAY_HOURS / g_clndr_cntx->PeriodInterval;
        
        g_clndr_cntx->CurrPeriodIndex = (currentTime.nHour / g_clndr_cntx->PeriodInterval);
        /* g_clndr_cntx->PeriodStartIndex = (currentTime.nHour / g_clndr_cntx->PeriodInterval); */

        /* start index is larger than limitation */
        if (g_clndr_cntx->CurrPeriodIndex > g_clndr_cntx->RowNumber - CLNDR_ROW)
        {
            g_clndr_cntx->PeriodStartIndex = g_clndr_cntx->RowNumber - CLNDR_ROW;
        }
        else
        {
            g_clndr_cntx->PeriodStartIndex = g_clndr_cntx->CurrPeriodIndex;
        }
    }
#endif /* __MMI_CALENDAR_V2__ */ 

#ifdef __MMI_BPP_SUPPORT__
    g_clndr_cntx->IsBPPPreview = MMI_FALSE;
#endif /*__MMI_BPP_SUPPORT__*/
    EntryClndrScreen();
}



#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
U16 g_image_list[3];
U8 *g_description_list[3];


/*****************************************************************************
 * FUNCTION
 *  ClndrUpdateInfoBox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_info                [?]         [?]         [?]
 *  icon_list               [IN]        
 *  description_list        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrUpdateInfoBox(S32 *num_info, U16 **icon_list, U8 ***description_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *num_info = 3;

    g_description_list[0] = (U8*) g_clndr_cntx->LunarInfo.MessageLine1;
    g_description_list[1] = (U8*) g_clndr_cntx->LunarInfo.MessageLine2;
    g_description_list[2] = (U8*) g_clndr_cntx->LunarInfo.MessageLine3;
    *description_list = g_description_list;

    g_image_list[0] = g_image_list[1] = g_image_list[2] = 0;

    *icon_list = g_image_list;
}
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryClndrScreen
 * DESCRIPTION
 *  Display calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClndrScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME myTime;
#ifdef __MMI_BPP_SUPPORT__
	S8 snapshot_file_path[CLNDR_BPP_MAX_FILE_PATH * ENCODING_LENGTH];
#endif /*__MMI_BPP_SUPPORT__*/
#ifdef __MMI_CALENDAR_V2__
    S32 j, highlightCell, currCell = -1;
    gui_calendar_cell_struct *startCell;
    MMI_BOOL status_bar_display = MMI_TRUE;
    U8 *lsk, *rsk;
#else
    U8 lunarOptionInternal;    
#ifdef __MMI_TODOLIST__
    S32 i;
#endif     
#endif /* __MMI_CALENDAR_V2__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_V2__

#ifdef __MMI_BPP_SUPPORT__
    /* BPP preview need not to be added into history */
    if (g_clndr_cntx->IsBPPPreview == MMI_TRUE)
    {
        EntryNewScreen(SCR_ID_CLNDR_SCREEN, ExitClndrScreen, NULL, NULL);
        SetDelScrnIDCallbackHandler(SCR_ID_CLNDR_SCREEN, (HistoryDelCBPtr)mmi_clndr_bpp_delete_callback);
        status_bar_display = MMI_FALSE;
        lsk = (U8*)GetString(STR_CLNDR_BPP_PRINT);
    }
    else
    {
        EntryNewScreen(SCR_ID_CLNDR_SCREEN, ExitClndrScreen, EntryClndrScreen, NULL);
        lsk = (U8*)GetString(STR_GLOBAL_OPTIONS);
    }
#else
    EntryNewScreen(SCR_ID_CLNDR_SCREEN, ExitClndrScreen, EntryClndrScreen, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_CLNDR_SCREEN, (HistoryDelCBPtr)ClndrDeInit);
    lsk = (U8*)GetString(STR_GLOBAL_OPTIONS);
#endif
    rsk = (U8*)GetString(STR_GLOBAL_BACK);
    g_clndr_cntx->Title = mmi_frm_scrmem_alloc(CLNDR_TITLE_LEN * CLNDR_COLUMN);
    g_clndr_cntx->HorizonList[0] =
        (U8*) mmi_frm_scrmem_alloc(CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
    g_clndr_cntx->VerticalList[0] =
        (U8*) mmi_frm_scrmem_alloc(CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
    g_clndr_cntx->CalendarCell = mmi_frm_scrmem_alloc((g_clndr_cntx->RowNumber * CLNDR_COLUMN) * CLNDR_CELL_SIZE);
#ifdef __MMI_CLNDR_ICON_SUPPORT__    
    /* allocate memory for reminder */
    g_clndr_cntx->info_box_text[0] = OslMalloc(CLNDR_MAX_INFO_BOX_LEN + ENCODING_LENGTH);
    g_clndr_cntx->info_box_text[1] = OslMalloc(CLNDR_MAX_INFO_BOX_LEN + ENCODING_LENGTH);
#endif /*__MMI_CLNDR_ICON_SUPPORT__    */
    for (j = 1; j < CLNDR_COLUMN; j++)
    {
        g_clndr_cntx->HorizonList[j] = g_clndr_cntx->HorizonList[j - 1] + CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH;
    }
    for (j = 1; j < CLNDR_ROW; j++)
    {
        g_clndr_cntx->VerticalList[j] =
            g_clndr_cntx->VerticalList[j - 1] + CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH;
    }

    /* reset memory */
    memset(g_clndr_cntx->Title, 0, CLNDR_TITLE_LEN * CLNDR_COLUMN);
    memset(g_clndr_cntx->HorizonList[0], 0, CLNDR_HORIZON_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_COLUMN);
    memset(g_clndr_cntx->VerticalList[0], 0, CLNDR_VERTICAL_LIST_CELL_LEN * ENCODING_LENGTH * CLNDR_ROW);
    memset(g_clndr_cntx->CalendarCell, 0, g_clndr_cntx->RowNumber * CLNDR_COLUMN * CLNDR_CELL_SIZE);

    ClndrGetScreenInfo();

    wgui_calendar_set_horizontal_string(g_clndr_cntx->HorizonList, 0xFF);

    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        highlightCell = g_clndr_cntx->DayOnFirst + g_clndr_cntx->CalTime.nDay - 1;
        /* set current date */
        GetDateTime(&myTime);
        if (myTime.nMonth == g_clndr_cntx->CalTime.nMonth && myTime.nYear == g_clndr_cntx->CalTime.nYear)
        {
            currCell = g_clndr_cntx->DayOnFirst + myTime.nDay - 1;
        }
    #ifdef __MMI_BPP_SUPPORT__
        if (g_clndr_cntx->IsBPPPreview == MMI_FALSE)
        /* Register keypad and touch handler */
        {
            wgui_calendar_register_cell_highlight_handler(mmi_clndr_monthly_highlight);
            wgui_calendar_register_left_arrow_key_handler(mmi_clndr_left_out_of_boundary);
            wgui_calendar_register_right_arrow_key_handler(mmi_clndr_right_out_of_boundary);
            wgui_calendar_register_up_arrow_key_handler(mmi_clndr_up_out_of_boundary);
            wgui_calendar_register_down_arrow_key_handler(mmi_clndr_down_out_of_boundary);
            wgui_calendar_register_up_side_key_handler(mmi_clndr_up_side_key);
            wgui_calendar_register_down_side_key_handler(mmi_clndr_down_side_key);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_calendar_set_select_horizontal1_handler(mmi_clndr_touch_year_decrease, mmi_clndr_touch_year_increase);
            wgui_calendar_set_select_horizontal2_handler(mmi_clndr_touch_month_decrease, mmi_clndr_touch_month_increase);
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
        else
        {
            wgui_calendar_register_cell_highlight_handler(NULL);
        	wgui_cat8x_set_status_string((U8*)GetString(STR_CLNDR_BPP_PREVIEW));
        }
    #else        
    	/* Register keypad and touch handler */        
        wgui_calendar_register_cell_highlight_handler(mmi_clndr_monthly_highlight);
        wgui_calendar_register_left_arrow_key_handler(mmi_clndr_left_out_of_boundary);
        wgui_calendar_register_right_arrow_key_handler(mmi_clndr_right_out_of_boundary);
        wgui_calendar_register_up_arrow_key_handler(mmi_clndr_up_out_of_boundary);
        wgui_calendar_register_down_arrow_key_handler(mmi_clndr_down_out_of_boundary);
        wgui_calendar_register_up_side_key_handler(mmi_clndr_up_side_key);
        wgui_calendar_register_down_side_key_handler(mmi_clndr_down_side_key);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_calendar_set_select_horizontal1_handler(mmi_clndr_touch_year_decrease, mmi_clndr_touch_year_increase);
        wgui_calendar_set_select_horizontal2_handler(mmi_clndr_touch_month_decrease, mmi_clndr_touch_month_increase);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    #endif
                
#ifdef __MMI_CLNDR_ICON_SUPPORT__
        mmi_momthly_clndr_set_info_box();
#endif /*__MMI_CLNDR_ICON_SUPPORT__*/

        mmi_clndr_monthly_set_content();

        ShowCategory83Screen(
            IMG_CALENDAR_JAN,
            (U8 **) g_clndr_cntx->HorizonList,
            (gui_calendar_cell_struct*) g_clndr_cntx->CalendarCell,
            CLNDR_ROW,
            CLNDR_COLUMN,
            currCell / CLNDR_COLUMN,
            currCell % CLNDR_COLUMN,
            highlightCell / CLNDR_COLUMN,
            highlightCell % CLNDR_COLUMN,
            GUI_CALENDAR_CELL_BG_FILL_HORIZONTAL,
            GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
            GUI_CALENDAR_CELL_ICON_DISPLAY_RIGHT_TOP,
            status_bar_display,
            lsk,
            rsk);    
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    else if (g_clndr_cntx->DisplayType == CLNDR_WEEKLY_VIEW)
    {
    #ifdef __MMI_BPP_SUPPORT__
        if (g_clndr_cntx->IsBPPPreview == MMI_FALSE)
        {        
            wgui_calendar_register_cell_highlight_handler(mmi_clndr_weekly_highlight);
            wgui_calendar_register_left_arrow_key_handler(mmi_clndr_left_out_of_boundary);
            wgui_calendar_register_right_arrow_key_handler(mmi_clndr_right_out_of_boundary);
            wgui_calendar_register_up_arrow_key_handler(mmi_clndr_up_out_of_boundary);
            wgui_calendar_register_down_arrow_key_handler(mmi_clndr_down_out_of_boundary);
            wgui_calendar_register_up_side_key_handler(mmi_clndr_weekly_decrease);
            wgui_calendar_register_down_side_key_handler(mmi_clndr_weekly_increase);
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_calendar_set_select_horizontal1_handler(mmi_clndr_weekly_decrease, mmi_clndr_weekly_increase);
            wgui_calendar_set_select_horizontal2_handler(
                mmi_clndr_touch_multi_periodly_decrease,
                mmi_clndr_touch_multi_periodly_increase);
            wgui_calendar_set_select_vertical_handler(
                mmi_clndr_touch_single_periodly_decrease,
                mmi_clndr_touch_single_periodly_increase);
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
        else
        {
            wgui_calendar_register_cell_highlight_handler(NULL);
        	wgui_cat8x_set_status_string((U8*)GetString(STR_CLNDR_BPP_PREVIEW));
        }
    #else /* __MMI_BPP_SUPPORT__ */
        /* Register keypad and touch handler */      
        wgui_calendar_register_cell_highlight_handler(mmi_clndr_weekly_highlight);
        wgui_calendar_register_left_arrow_key_handler(mmi_clndr_left_out_of_boundary);
        wgui_calendar_register_right_arrow_key_handler(mmi_clndr_right_out_of_boundary);
        wgui_calendar_register_up_arrow_key_handler(mmi_clndr_up_out_of_boundary);
        wgui_calendar_register_down_arrow_key_handler(mmi_clndr_down_out_of_boundary);
        wgui_calendar_register_up_side_key_handler(mmi_clndr_weekly_decrease);
        wgui_calendar_register_down_side_key_handler(mmi_clndr_weekly_increase);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_calendar_set_select_horizontal1_handler(mmi_clndr_weekly_decrease, mmi_clndr_weekly_increase);
        wgui_calendar_set_select_horizontal2_handler(
                mmi_clndr_touch_multi_periodly_decrease,
                mmi_clndr_touch_multi_periodly_increase);
        wgui_calendar_set_select_vertical_handler(
                mmi_clndr_touch_single_periodly_decrease,
                mmi_clndr_touch_single_periodly_increase);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    #endif /* __MMI_BPP_SUPPORT__ */
        ClndrGetScreenInfo();

#ifdef __MMI_CLNDR_ICON_SUPPORT__
        mmi_weekly_clndr_set_info_box();
#endif /*__MMI_CLNDR_ICON_SUPPORT__*/
        mmi_clndr_weekly_set_content();

        startCell = g_clndr_cntx->CalendarCell + (g_clndr_cntx->PeriodStartIndex * CLNDR_COLUMN);

        ShowCategory83Screen(
            IMG_CALENDAR_JAN,
            (U8 **) g_clndr_cntx->HorizonList,
            startCell,
            CLNDR_ROW,
            CLNDR_COLUMN,
            0xFFFFFFFF, /* do not mark current period */
            0xFFFFFFFF,
            g_clndr_cntx->CurrPeriodIndex - g_clndr_cntx->PeriodStartIndex,
            DOW(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nDay),
            GUI_CALENDAR_CELL_BG_FILL_VERTICAL,
            GUI_CALENDAR_CELL_TEXT_DISPLAY_LEFT_BOTTOM,
            GUI_CALENDAR_CELL_ICON_DISPLAY_CENTER,
            status_bar_display,
            lsk,
            rsk);
    }
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 

#ifdef __MMI_BPP_SUPPORT__
    if (g_clndr_cntx->IsBPPPreview == MMI_TRUE)
    {
    	mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
		mmi_clndr_bpp_create_snapshot(snapshot_file_path);  
        SetLeftSoftkeyFunction(mmi_clndr_bpp_print, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        return;
    }
#endif /* __MMI_BPP_SUPPORT__ */ 

#else /* __MMI_CALENDAR_V2__ */ 
    gClndrAddToHistory = FALSE;
    EntryNewScreen(SCR_ID_CLNDR_SCREEN, ExitClndrScreen, NULL, NULL);
    gClndrAddToHistory = TRUE;

    ClndrGetScreenInfo();

    if (g_clndr_cntx->LunarState == TRUE && IsChineseSet())
    {
        lunarOptionInternal = TRUE;
        InitializeCategory82Screen(
            g_clndr_cntx->DayOnFirst,
            g_clndr_cntx->NumDaysInMonth,
            g_clndr_cntx->CalTime.nDay,
            g_clndr_cntx->CalTime.nMonth,
            g_clndr_cntx->CalTime.nYear);
    }
    else
    {
        lunarOptionInternal = FALSE;
        InitializeCategory80Screen(
            g_clndr_cntx->DayOnFirst,
            g_clndr_cntx->NumDaysInMonth,
            g_clndr_cntx->CalTime.nDay,
            g_clndr_cntx->CalTime.nMonth,
            g_clndr_cntx->CalTime.nYear);
    }

#ifdef __MMI_TODOLIST__
    if (g_clndr_cntx->TaskDayList[0] != CLNDR_MAX_DAYS)
    {
        for (i = 1; i <= g_clndr_cntx->TaskDayList[0]; i++)
        {
            SetCalendarDay(g_clndr_cntx->TaskDayList[i], CALENDAR_TASK_DAY);
        }
    }
    else
    {
        for (i = 1; i <= CLNDR_MAX_DAYS; i++)
        {
            SetCalendarDay(i, CALENDAR_TASK_DAY);
        }
    }
#endif /* __MMI_TODOLIST__ */ 

    /* browsing to current month */
    GetDateTime(&myTime);
    if (myTime.nMonth == g_clndr_cntx->CalTime.nMonth && myTime.nYear == g_clndr_cntx->CalTime.nYear)
    {
        SetCalendarDay(myTime.nDay, CALENDAR_CURRENT_DAY);
    }

#ifdef __MMI_BPP_SUPPORT__
    if (g_clndr_cntx->IsBPPPreview == MMI_FALSE)
    {
        RegisterCalendarHighlightHandler(HighlightClndrDate);

        RegisterCalendarUpdateHandler(UpdateClndrContext);
    }   
#else
	RegisterCalendarHighlightHandler(HighlightClndrDate);
    RegisterCalendarUpdateHandler(UpdateClndrContext);
#endif

#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    if (lunarOptionInternal == TRUE)
    {
        RegisterCalendarUpdateInfoBoxHandler(ClndrUpdateInfoBox);
    }
#endif /* __MMI_UI_CALENDAR_WITH_INFO_BOX__ */ 

    if (IsChineseSet())
    {
        SetCalendarTitleImage(CAL_CHINESE_DAYS_IMAGE);
    }
    else
    {
        SetCalendarTitleImage(CAL_ENGLISH_DAYS_IMAGE);
    }
    
	if (lunarOptionInternal == TRUE)
    {
        g_clndr_cntx->LunarInfo.SolarMonth = g_clndr_cntx->CalTime.nMonth;
        g_clndr_cntx->LunarInfo.SolarYear = g_clndr_cntx->CalTime.nYear;
        g_clndr_cntx->LunarInfo.SolarDay = g_clndr_cntx->CalTime.nDay;
        ClndrComputeLunarInfo(&g_clndr_cntx->LunarInfo);
        SetCalendarPopupDay(
            g_clndr_cntx->LunarInfo.SolarDay,
            (U8*) g_clndr_cntx->LunarInfo.MessageLine1,
            (U8*) g_clndr_cntx->LunarInfo.MessageLine2,
            (U8*) g_clndr_cntx->LunarInfo.MessageLine3);

        SetCategory82Title1((U8*) g_clndr_cntx->LunarInfo.TitleInfo1); /* OR calInfo.totlestring */
        /* SetCategory82Title2((U8*)g_clndr_cntx->TitleString); */
        SetCategory82Title3((U8*) g_clndr_cntx->LunarInfo.TitleInfo2);
        SetCalendarPopupTitleLunarFunc(ClndrGeneratePopupInfo);        
    }

#ifdef __MMI_BPP_SUPPORT__
    if (g_clndr_cntx->IsBPPPreview == MMI_TRUE)
    {
        wgui_cat8x_set_status_string((U8*)GetString(STR_CLNDR_BPP_PREVIEW));
        
		if (lunarOptionInternal == FALSE)
		{
			ShowCategory80Screen(STR_CLNDR_BPP_PRINT, 0, 0, 0, 0);
		}
		else
		{
			ShowCategory82Screen(STR_CLNDR_BPP_PRINT, 0, 0, 0, 0);
		}
		
		mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
		mmi_clndr_bpp_create_snapshot(snapshot_file_path);    		

        SetLeftSoftkeyFunction(mmi_clndr_bpp_print, KEY_EVENT_UP);
        SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
        return;
    }
	else
	{
		if (lunarOptionInternal == FALSE)
		{
			ShowCategory80Screen(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_OK, 0);
		}
		else
		{
			ShowCategory82Screen(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_OK, 0);
		}
	}
#else
	if (lunarOptionInternal == FALSE)
	{
		ShowCategory80Screen(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_OK, 0);
	}
	else
	{
		ShowCategory82Screen(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_OK, 0);
	}
#endif	

    SetKeyHandler(wgui_calendar_previous_month, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_calendar_previous_month, KEY_VOL_UP, KEY_LONG_PRESS);
    SetKeyHandler(wgui_calendar_next_month, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_calendar_next_month, KEY_VOL_DOWN, KEY_LONG_PRESS);

    SetCalendarMonthFunctions(
        wgui_calendar_previous_month_day,
        wgui_calendar_next_month_day,
        wgui_calendar_previous_month_week,
        wgui_calendar_next_month_week);

#ifdef __MMI_TOUCH_SCREEN__
    SetCalendarMonthChangeFunctions(wgui_calendar_previous_month, wgui_calendar_next_month);
    /* 053005 Calvin Start */
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    SetCalendarYearChangeFunctions(wgui_calendar_previous_year, wgui_calendar_next_year);
#endif 
    /* 053005 Calvin End */
#endif /* __MMI_TOUCH_SCREEN__ */ 
#endif /* __MMI_CALENDAR_V2__ */ 
    SetLeftSoftkeyFunction(EntryClndrOptions, KEY_EVENT_UP);
    SetRightSoftkeyFunction(ClndrGoBackFromCalendar, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitClndrScreen
 * DESCRIPTION
 *  Exit function of calendar screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitClndrScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_V2__
#ifdef __MMI_BPP_SUPPORT__        
    /* Goback from BPP preview screen*/
    if (g_clndr_cntx->IsBPPPreview == MMI_TRUE)
    {
        g_clndr_cntx->IsBPPPreview = MMI_FALSE;
    }
#endif /* __MMI_BPP_SUPPORT__ */
    if (g_clndr_cntx)
    {
        if (g_clndr_cntx->Title != NULL)
        {
            mmi_frm_scrmem_free((void*)g_clndr_cntx->Title);
            g_clndr_cntx->Title = NULL;
        }

        if (g_clndr_cntx->HorizonList[0] != NULL)
        {
            mmi_frm_scrmem_free((void*)g_clndr_cntx->HorizonList[0]);
            g_clndr_cntx->HorizonList[0] = NULL;
        }

        if (g_clndr_cntx->VerticalList[0] != NULL)
        {
            mmi_frm_scrmem_free((void*)g_clndr_cntx->VerticalList[0]);
            g_clndr_cntx->VerticalList[0] = NULL;
        }

        if (g_clndr_cntx->CalendarCell != NULL)
        {
            mmi_frm_scrmem_free((void*)g_clndr_cntx->CalendarCell);
            g_clndr_cntx->CalendarCell = NULL;
        }

    #ifdef __MMI_CLNDR_ICON_SUPPORT__    
        if (g_clndr_cntx->info_box_text[0] != NULL)
        {
            OslMfree(g_clndr_cntx->info_box_text[0]);
            OslMfree(g_clndr_cntx->info_box_text[1]);

            g_clndr_cntx->info_box_text[0] = NULL;
            g_clndr_cntx->info_box_text[1] = NULL;
        }
    #endif /*__MMI_CLNDR_ICON_SUPPORT__    */    
    }

#else /* __MMI_CALENDAR_V2__ */ 
    if (gClndrAddToHistory        
#ifdef __MMI_BPP_SUPPORT__        
        && g_clndr_cntx->IsBPPPreview == MMI_FALSE /* BPP preview need not to be added into history */
#endif        
        )
    {
        history Scr;
        S16 nHistory = 0;

        Scr.scrnID = SCR_ID_CLNDR_SCREEN;
        Scr.entryFuncPtr = EntryClndrScreen;
        GetCategoryHistory(Scr.guiBuffer);
        mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
        AddHistory(Scr);
    }
#endif /* __MMI_CALENDAR_V2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ClndrGetScreenInfo
 * DESCRIPTION
 *  Get screen display information of.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrGetScreenInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TODOLIST__
    MYTIME myTime;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the DOW 1st of todays month */
    g_clndr_cntx->DayOnFirst = DOW(g_clndr_cntx->CalTime.nYear, g_clndr_cntx->CalTime.nMonth, 1);

    /* get the num of days in todays month */
    g_clndr_cntx->NumDaysInMonth = LastDayOfMonth(g_clndr_cntx->CalTime.nMonth, g_clndr_cntx->CalTime.nYear);

     /* reset task list */
    memset(g_clndr_cntx->TaskDayList, 0, CLNDR_COLUMN * CLNDR_ROW * sizeof(clndr_task_icon_struct));

#ifdef __MMI_CALENDAR_V2__
    mmi_clndr_get_date_str(&(g_clndr_cntx->CalTime), g_clndr_cntx->Title);
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        mmi_clndr_get_weekday(g_clndr_cntx->HorizonList);
        mmi_clndr_get_week_numbers(
            g_clndr_cntx->CalTime.nYear,
            g_clndr_cntx->CalTime.nMonth,
            g_clndr_cntx->VerticalList);
        mmi_clndr_construct_monthly_cell_info();
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__
    else
    {
        mmi_clndr_get_weekly_dates(&g_clndr_cntx->CalTime, g_clndr_cntx->HorizonList);
        /* todo : compute the start period index */
        mmi_clndr_get_period_range(g_clndr_cntx->PeriodStartIndex, g_clndr_cntx->VerticalList);
        mmi_clndr_construct_weekly_cell_info();
        g_clndr_cntx->WeekNum = applib_dt_get_week_number((applib_time_struct*) & g_clndr_cntx->CalTime);
    }
#endif /* __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__ */ 
#endif /* __MMI_CALENDAR_V2__ */

}


/*****************************************************************************
 * FUNCTION
 *  ClndrGoBackFromCalendar
 * DESCRIPTION
 *  Free memory and go back to previous screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrGoBackFromCalendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}



#define CLNDR_OPTION


/*****************************************************************************
 * FUNCTION
 *  EntryClndrOptions
 * DESCRIPTION
 *  Side down key handler, go to 1st day of next month.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClndrOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *pop_up_desc[CLNDR_OPTIONS_TOTAL];
    U16 nStrItemList[CLNDR_OPTIONS_TOTAL];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 menuId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gClndrAddToHistory = TRUE;
    EntryNewScreen(SCR_ID_CLNDR_OPTION, ExitClndrOptions, EntryClndrOptions, NULL);
    gClndrAddToHistory = FALSE;

#ifdef __MMI_CALENDAR_V2__
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        menuId = ORGANIZER_CALENDER_MONTHLY_OPTIONS_MENU;
    }
    else
    {
        menuId = ORGANIZER_CALENDER_WEEKLY_OPTIONS_MENU;
    }
#else /* __MMI_CALENDAR_V2__ */ 
    menuId = ORGANIZER_CALENDER_MENU;
#endif /* __MMI_CALENDAR_V2__ */ 

#if defined(__MMI_CALENDAR_V2__) && defined(__MMI_TODOLIST__)    
    /* Hide options of adding task if the amount of todolist equals to max value */
    if (TDLGetTotalItem() >= NUM_OF_TDL)
    {
        mmi_frm_hide_menu_item(MENU_ID_CLNDR_ADD_TASK);
    }
    else if (mmi_frm_test_menu_item_hide(MENU_ID_CLNDR_ADD_TASK))
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLNDR_ADD_TASK);
    }
#endif  

#if defined(__MMI_BPP_SUPPORT__) && defined(__FLIGHT_MODE_SUPPORT__)
    if (mmi_bootup_get_active_flight_mode() == 1) /* in flight mode */
    {
        mmi_frm_hide_menu_item(MENU_ID_CLNDR_BPP_PRINT);        
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_CLNDR_BPP_PRINT);        
    }

#endif /*__MMI_BPP_SUPPORT__ && __FLIGHT_MODE_SUPPORT__*/
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CLNDR_OPTION);

    /*  Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(menuId);

    /*  Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(menuId, nStrItemList);

    ConstructHintsList(menuId, pop_up_desc);

    /*  Set current parent id */
    SetParentHandler(menuId);

    /*  Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    if (IsChineseSet())
    {
        ShowCategory52Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_OK,
            nNumofItem,
            nStrItemList,
            (PU16) gIndexIconsImageList,
            pop_up_desc,
            0,
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory52Screen(
            STR_GLOBAL_OPTIONS,
            ORGANIZER_TITLE_IMAGEID,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_OK,
            (nNumofItem - 1),
            nStrItemList,
            (PU16) gIndexIconsImageList,
            pop_up_desc,
            0,
            0,
            guiBuffer);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ExitClndrOptions
 * DESCRIPTION
 *  Exit function of calendar option screen. write lunar state to nvram.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitClndrOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(LUNAR_CALENDAR, &g_clndr_cntx->LunarState, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  ClndrSetLunarState
 * DESCRIPTION
 *  Toggle state of lunar calendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrSetLunarState(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 indexPopup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    indexPopup = GetCurrHiliteID();

    if (g_clndr_cntx->LunarState == TRUE)
    {
        g_clndr_cntx->LunarState = FALSE;
        mmi_ucs2cpy((S8*) hintData[indexPopup], (S8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_CAL_ON);
    }
    else
    {
        g_clndr_cntx->LunarState = TRUE;
        mmi_ucs2cpy((S8*) hintData[indexPopup], (S8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_CAL_OFF);
    }

    Category52ChangeItemDescription(indexPopup, hintData[indexPopup]);
    SetLeftSoftkeyFunction(ClndrSetLunarState, KEY_EVENT_UP);
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  ClndrDisplayTask
 * DESCRIPTION
 *  Display to do list task of selected date.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrDisplayTask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TODOLIST__
#ifdef __MMI_CALENDAR_V2__
    mmi_tdl_set_clndr(&g_clndr_cntx->CalTime, g_clndr_cntx->DisplayType);
#else 
    mmi_tdl_set_clndr(&g_clndr_cntx->CalTime, MMI_TRUE);
#endif 
    TDLShowSpecificDateList();
#endif /* __MMI_TODOLIST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ClndrLunarHintHandler
 * DESCRIPTION
 *  Hint handler of lunar calendar option.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrLunarHintHandler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx->LunarState == FALSE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightClndrViewTask
 * DESCRIPTION
 *  Highlight handler of View Task option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightClndrViewTask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(ClndrDisplayTask, KEY_EVENT_UP);
    SetKeyHandler(ClndrDisplayTask, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightClndrLunar
 * DESCRIPTION
 *  Highlight handler on lunar calendar option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightClndrLunar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 indexPopup = GetCurrHiliteID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx->LunarState == FALSE)
    {
        mmi_ucs2cpy((S8*) hintData[indexPopup], (S8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_CAL_ON);
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[indexPopup], (S8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_CAL_OFF);
    }

    SetLeftSoftkeyFunction(ClndrSetLunarState, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define CLNDR_JUMP_TO_DATE


/*****************************************************************************
 * FUNCTION
 *  ClndrValidateInput
 * DESCRIPTION
 *  Validate correctness of date and jump to the date in calendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrValidateInput(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmpMon[CLNDR_DAY_LEN];
    S8 tmpDay[CLNDR_MON_LEN];
    S8 tmpYear[CLNDR_YEAR_LEN];
    U8 DayOfMon;

    U8 nDay, nMonth;
    U16 nYear;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* validate day */
    mmi_ucs2_to_asc(tmpDay, g_clndr_cntx->DayBuf);
    mmi_ucs2_to_asc(tmpMon, g_clndr_cntx->MonBuf);
    mmi_ucs2_to_asc(tmpYear, g_clndr_cntx->YearBuf);

    nDay = atoi(tmpDay);
    nMonth = atoi(tmpMon);
    nYear = atoi(tmpYear);

    /* daty out of boundary */
    DayOfMon = LastDayOfMonth(nMonth, nYear);
    if (nDay > DayOfMon)
    {
        DisplayPopup(
            (U8*) GetString(STR_CLNDR_WRONG_DATE),
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    else
    {
        g_clndr_cntx->CalTime.nDay = nDay;
        g_clndr_cntx->CalTime.nMonth = nMonth;
        g_clndr_cntx->CalTime.nYear = nYear;
        GoBackToHistory(SCR_ID_CLNDR_SCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ClndrFillInilineStruct
 * DESCRIPTION
 *  Fill inline structure of date input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrFillInilineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmpMon[CLNDR_DAY_LEN];
    S8 tmpDay[CLNDR_MON_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa((S32) g_clndr_cntx->CalTime.nYear, (U16*) g_clndr_cntx->YearBuf, 10);

    sprintf(tmpMon, "%02d", g_clndr_cntx->CalTime.nMonth);
    mmi_asc_to_ucs2(g_clndr_cntx->MonBuf, tmpMon);

    sprintf(tmpDay, "%02d", g_clndr_cntx->CalTime.nDay);
    mmi_asc_to_ucs2(g_clndr_cntx->DayBuf, tmpDay);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_CLNDR_DATE));

    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDate(
        &wgui_inline_items[1],
        (U8*) g_clndr_cntx->DayBuf,
        (U8*) g_clndr_cntx->MonBuf,
        (U8*) g_clndr_cntx->YearBuf,
        ClndrDateEditorCallBack);
    RightJustifyInlineItem(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    set_inline_date_boundary(2030, 1970, 12, 1);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightClndrInputItem
 * DESCRIPTION
 *  Highlight handler of inline editor items.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightClndrInputItem(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(ClndrValidateInput, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitClndrJumpToDate
 * DESCRIPTION
 *  Exit function of Jump To screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitClndrJumpToDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    U16 inputBufferSize;    /* added for inline edit history */

    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_CLNDR_JUMP;
    CloseCategory57Screen();
    Scr.entryFuncPtr = EntryClndrJumpToDate;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    AddNHistory(Scr, inputBufferSize);                  /* added for inline edit history */

}


/*****************************************************************************
 * FUNCTION
 *  EntryClndrJumpToDate
 * DESCRIPTION
 *  Entry function of Jump To screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClndrJumpToDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    U8 *inputBuffer;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CLNDR_JUMP, ExitClndrJumpToDate, NULL, NULL);
    InitializeCategory57Screen();

    ClndrFillInilineStruct();

    RegisterHighlightHandler(HighlightClndrInputItem);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CLNDR_JUMP);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_CLNDR_JUMP, &inputBufferSize);

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, 2, inputBuffer);   /* sets the data */
    }

    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_CLNDR_JUMP_TO,
        GetRootTitleIcon(ORGANIZER_CALENDER_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    SetKeyHandler(ClndrValidateInput, KEY_LSK, KEY_EVENT_UP);

    SetCategory57RightSoftkeyFunctions(ClndrValidateInput, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightJumpToDate
 * DESCRIPTION
 *  Highlight handler on lunar calendar option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightJumpToDate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetKeyHandler(EntryClndrJumpToDate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryClndrJumpToDate, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define CLNDR_LUNAR_CALENDAR


/*****************************************************************************
 * FUNCTION
 *  ClndrComputeSolarTerm
 * DESCRIPTION
 *  This function is to calculate the date of solar item in given year.
 * PARAMETERS
 *  year            [IN]        Year in solar calendar, e.g. 2003
 *  month           [IN]        
 *  solar_index     [IN]        Index of solar term, 0 = SC (Slight Cold), 1 = GC,...
 * RETURNS
 *  the solar day of given solar item
 *****************************************************************************/
S16 ClndrComputeSolarTerm(S16 year, S16 month, S16 solar_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* adjust the solar term days for lunarinfo by feifan 8/1/2005 */

    return solar_term_table[year - CLNDR_FIRST_NAVI_YEAR][solar_index];

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  ClndrComputeLunarInfo
 * DESCRIPTION
 *  This function is to convert solar date infomation to lunar date.
 * CALLS
 * PARAMETERS
 *  DI      [IN/OUT]        A struct contains solar date information and lunar information will also be stored here
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrComputeLunarInfo(clndr_lnuar_date_info_struct *DI)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 LeapDay;
    S16 StartMonth;
    S16 YearIndex;
    S16 AccumulateDay;
    S16 KanChiDay;
    S16 DateDiff;
    S16 IntercalaryMonth;
    S16 LunarDays;
    S16 SolarDate1, SolarDate2, SolarDate3;
    S16 MonthIndex;
    S8 dummyString[CLNDR_TITLE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to check if the month out of boundary */
    StartMonth = DI->SolarMonth - 1;

    /* to calculate the number of days in Feb. this year */
    if (StartMonth > 1)
    {
        LeapDay = (U8) IsLeapYear(DI->SolarYear);
    }
    else
    {
        LeapDay = 0;
    }

    YearIndex = DI->SolarYear - CLNDR_TABLE_START_YEAR;

    /* to calculate weekday */
    AccumulateDay = (gClndrAccuDays[StartMonth] + LeapDay + DI->SolarDay);

    /* to calculate the Kan and Chin of today */
    KanChiDay = AccumulateDay + gClndrLunarInfo[YearIndex].BaseKanChi;

    /* to check if today is earlier than the Chinese New Year day of this year */
	LeapDay = (U8) IsLeapYear(DI->LunarYear);
    if (g_clndr_cntx->CalTime.nMonth == 1 || (g_clndr_cntx->CalTime.nMonth == 2 && g_clndr_cntx->CalTime.nDay < 29))
    {
        LeapDay = 0;
    }
    if (AccumulateDay <= gClndrLunarInfo[YearIndex].BaseDays)
    {
        YearIndex--;
        DI->LunarYear = DI->SolarYear - 1;
        
        StartMonth += 12;
        AccumulateDay = (gClndrAccuDays[StartMonth] + LeapDay + DI->SolarDay);
    }
    else
    {
        DI->LunarYear = DI->SolarYear;
    }

    /* to calculate the lunar month and day */
    IntercalaryMonth = gClndrLunarInfo[YearIndex].Intercalary;
    DateDiff = gClndrLunarInfo[YearIndex].BaseDays;
    for (MonthIndex = 0; MonthIndex < 13; MonthIndex++)
    {
        LunarDays = DateDiff + 29;
        if (gClndrLunarInfo[YearIndex].MonthDays & (0x01 << MonthIndex))
        {
            LunarDays++;
        }

        if (AccumulateDay <= LunarDays)
        {
            break;
        }

        DateDiff = LunarDays;
    }

    DI->LunarMonth = (MonthIndex + 1);
    DI->LunarDay = AccumulateDay - DateDiff;

    /* to adjust Lunar month if there is a intercalary month in this year */
    if (IntercalaryMonth != 0 && DI->LunarMonth > IntercalaryMonth)
    {
        DI->LunarMonth--;
    }

    if (DI->LunarMonth > 12)
    {
        DI->LunarMonth -= 12;
    }

    /* the unfortunate direction, age, and animal today */
    DI->Direction = KanChiDay % 4;
    DI->Age = (82 - (KanChiDay % 60) + (DI->LunarYear - CLNDR_BASE)) % 60;

    if (DI->Age <= 10)
    {
        DI->Age += 60;
    }

    DI->Animal = (KanChiDay + 6) % 12;

    /* to calculate the Kan and Chin of this year */
    if (DI->LunarYear == DI->SolarYear)
    {
        DI->KanYear = (DI->SolarYear - 1900 + 36) % 10;
        DI->ChiYear = (DI->SolarYear - 1900 + 36) % 12;

        /* to calculate the animal of this year */
        DI->YearAnimal = (DI->SolarYear + 8) % 12;
    }
    else
    {
        DI->KanYear = (DI->SolarYear - 1900 + 36 - 1) % 10;
        DI->ChiYear = (DI->SolarYear - 1900 + 36 - 1) % 12;

        /* to calculate the animal of this year */
        DI->YearAnimal = (DI->SolarYear + 8 - 1) % 12;
    }

    /* to calculate the lunar day of solar term in this month */
    SolarDate1 = ClndrComputeSolarTerm(DI->SolarYear, DI->SolarMonth, (S16) ((DI->SolarMonth - 1) * 2));

    SolarDate2 = ClndrComputeSolarTerm(DI->SolarYear, DI->SolarMonth, (S16) ((DI->SolarMonth - 1) * 2 + 1));

    if (DI->SolarMonth < 12)
    {
        SolarDate3 = ClndrComputeSolarTerm(DI->SolarYear, (S16) (DI->SolarMonth + 1), (S16) ((DI->SolarMonth - 1) * 2 + 2));
    }
    else
    {
        SolarDate3 = ClndrComputeSolarTerm((S16) (DI->SolarYear + 1), (S16) 1, (S16) (0));
    }

    if (DI->SolarDay < SolarDate1)
    {
        DI->SolarTerm = 0;
        DI->SolarDate = SolarDate1 - DI->SolarDay + DI->LunarDay;
    }
    else if (DI->SolarDay == SolarDate1)
    {
        DI->SolarTerm = 0;
        DI->SolarDate = 0;
    }
    else if (DI->SolarDay < SolarDate2)
    {
        DI->SolarTerm = 1;
        DI->SolarDate = SolarDate2 - DI->SolarDay + DI->LunarDay;
    }
    else if (DI->SolarDay == SolarDate2)
    {
        DI->SolarTerm = 1;
        DI->SolarDate = 0;
    }
    else
    {
        DI->SolarTerm = 2;
        if (DI->SolarMonth == 2)
        {
            DI->SolarDate = gDaysInMonth[DI->SolarMonth - 1] - DI->SolarDay + SolarDate3 + DI->LunarDay + LeapDay;
        }
        else
        {
            DI->SolarDate = gDaysInMonth[DI->SolarMonth - 1] - DI->SolarDay + SolarDate3 + DI->LunarDay;
        }
    }

    if (gClndrLunarInfo[YearIndex].MonthDays & (0x01 << MonthIndex))
    {
        LunarDays = 30;
    }
    else
    {
        LunarDays = 29;
    }

    if (DI->SolarDate > LunarDays)
    {
        DI->SolarDate -= LunarDays;
    }

    /* to recode the information to present */

    /* Chinese year/month/day information */
    mmi_ucs2cpy(DI->TitleInfo1, GetString((U16) (STR_CAL_KAN1 + DI->KanYear)));
    mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHI1 + DI->ChiYear)));
    mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_YEAR));

    if (DI->LunarMonth < 10)
    {
        mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHINESE_NO1 + DI->LunarMonth - 1)));
    }
    else
    {
        mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_CHINESE_NO10));
        if (DI->LunarMonth > 10)
        {
            mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHINESE_NO1 + (DI->LunarMonth % 10 - 1))));
        }
    }

    mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_MONTH));

    if (DI->LunarDay < 10)
    {
        mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHINESE_NO1 + DI->LunarDay - 1)));
    }
    else if (DI->LunarDay < 20)
    {
        mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_CHINESE_NO10));
        if (DI->LunarDay > 10)
        {
            mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHINESE_NO1 + DI->LunarDay % 10 - 1)));
        }
    }
    else if (DI->LunarDay < 30)
    {
        mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_CHINESE_NO20));
        if (DI->LunarDay > 20)
        {
            mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHINESE_NO1 + DI->LunarDay % 10 - 1)));
        }
    }
    else
    {
        mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_CHINESE_NO30));
        if (DI->LunarDay > 30)
        {
            mmi_ucs2cat(DI->TitleInfo1, GetString((U16) (STR_CAL_CHINESE_NO1 + DI->LunarDay % 10 - 1)));
        }
    }

    mmi_ucs2cat(DI->TitleInfo1, GetString(STR_CAL_DAY));

    /* Animal index */
    mmi_ucs2cpy(DI->TitleInfo2, GetString((U16) (STR_CAL_ANIMAL1 + DI->YearAnimal)));

    /* Solar Term */
    if (DI->SolarDate == 0)
    {
        mmi_ucs2cpy(
            DI->MessageLine1,
            GetString((U16) (STR_CAL_SOLARTERM1 + (DI->SolarMonth - 1) * 2 + DI->SolarTerm)));
    }
    else
    {
        sprintf(dummyString, "%d", DI->SolarDate);
        mmi_asc_to_ucs2(DI->MessageLine1, dummyString);

        if (DI->SolarTerm == 2 && DI->SolarMonth == 12)
        {
            mmi_ucs2cat(DI->MessageLine1, GetString(STR_CAL_SOLARTERM1));
        }
        else
        {
            mmi_ucs2cat(
                DI->MessageLine1,
                GetString((U16) (STR_CAL_SOLARTERM1 + (DI->SolarMonth - 1) * 2 + DI->SolarTerm)));
        }
    }

    /* Unfortunate */
    mmi_ucs2cpy(DI->MessageLine2, GetString(STR_CAL_UNLUCKY));
    mmi_ucs2cat(DI->MessageLine2, GetString((U16) (STR_CAL_DIRECTION1 + DI->Direction)));

    /* Unlucky */
    sprintf(DI->MessageLine3, "%d", DI->Age);
    mmi_asc_to_ucs2(dummyString, DI->MessageLine3);
    mmi_ucs2cpy(DI->MessageLine3, GetString(STR_CAL_UNFORTUNATE));
    mmi_ucs2cat(DI->MessageLine3, GetString((U16) (STR_CAL_ANIMAL1 + DI->Animal)));
    mmi_ucs2cat(DI->MessageLine3, dummyString);

}

#ifdef __MMI_BIRTHDAY_REMINDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_monthly_birthday_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  month               [IN]        
 *  BirthdayInfo        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_monthly_birthday_info(U16 year, U8 month, birthday_info_struct *BirthdayInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, date;
    MMI_PHB_BDAY_STRUCT *bday;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bday = (MMI_PHB_BDAY_STRUCT*) mmi_frm_scrmem_alloc(NVRAM_EF_PHB_BIRTHDAY_SIZE * NVRAM_EF_PHB_BIRTHDAY_TOTAL);
    mmi_clndr_read_birthday_info(bday);
    for (i = 0; i < MAX_PB_PHONE_ENTRIES; i++)
    {
        date = bday[i].bDay;
        if (bday[i].bMonth == month && year >= bday[i].bYear)
        {
            if (BirthdayInfo[date].count == 0)
            {
                BirthdayInfo[date].firstMatchedIndex = i;
                BirthdayInfo[date].count++;
            }
            else
            {
                BirthdayInfo[date].count++;
            }
        }
    }
    mmi_frm_scrmem_free((void*)bday);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_daily_birthday_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  month           [IN]        
 *  day             [IN]        
 *  amount          [IN]        
 *  PBIndexList     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_daily_birthday_info(U16 year, U8 month, U8 day, U16 amount, U16 *PBIndexList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count = 0;
    MMI_PHB_BDAY_STRUCT *bday;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bday = (MMI_PHB_BDAY_STRUCT*) mmi_frm_scrmem_alloc(NVRAM_EF_PHB_BIRTHDAY_SIZE * NVRAM_EF_PHB_BIRTHDAY_TOTAL);
    mmi_clndr_read_birthday_info(bday);
    for (i = 0; i < MAX_PB_PHONE_ENTRIES; i++)
    {
        if (bday[i].bMonth == month && bday[i].bDay == day && year >= bday[i].bYear)
        {
            PBIndexList[count] = i;
            count++;
        }

        if (count >= amount)
        {
            break;
        }
    }
    mmi_frm_scrmem_free((void*)bday);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_read_birthday_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bday_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_read_birthday_info(MMI_PHB_BDAY_STRUCT *bday_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32 bday_record;
    MMI_PHB_BDAY_STRUCT *data_pos = bday_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (bday_record = 1; bday_record <= NVRAM_EF_PHB_BIRTHDAY_TOTAL; bday_record++)
    {
        data_pos = bday_data + ((bday_record - 1) * NVRAM_EF_PHB_BIRTHDAY_COUNT);
        ReadRecord(NVRAM_EF_PHB_BIRTHDAY_LID, bday_record, (void*)data_pos, NVRAM_EF_PHB_BIRTHDAY_SIZE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_daily_birthday_amount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  date        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_clndr_get_daily_birthday_amount(U8 date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_clndr_cntx != NULL)
    {
        return g_clndr_cntx->BirthdayInfo[date].count;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_set_birthday_table
 * DESCRIPTION
 *  Set birthday information when month is changed.
 * PARAMETERS
 *  date        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_clndr_set_birthday_table(U16 year, U8 month)
{
#ifdef __MMI_BIRTHDAY_REMINDER__
        memset(g_clndr_cntx->BirthdayInfo, 0, sizeof(birthday_info_struct) * (CLNDR_MONTH_DAYS + 1));
        /* get birthday information */
        mmi_clndr_get_monthly_birthday_info(year, month, g_clndr_cntx->BirthdayInfo);
#endif /* __MMI_BIRTHDAY_REMINDER__ */ 
}

#endif /* __MMI_BIRTHDAY_REMINDER__ */ 

#ifdef __MMI_BPP_SUPPORT__

/* calendar_xhtml_table_constructer */

void mmi_clndr_highlight_bpp_print(void)
{
    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetKeyHandler(mmi_clndr_bpp_print, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_clndr_bpp_print, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void mmi_clndr_bpp_print(void)
{
    S8 snapshot_file_path[CLNDR_BPP_MAX_FILE_PATH * ENCODING_LENGTH];
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((S8*)snapshot_file_path))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    if (mmi_bt_bpp_app_is_printing() == MMI_BPP_PRINT_STATUS_BUSY)
    {
        mmi_bt_bpp_busy_popup();   
    }
    else
    {
        if (g_clndr_cntx->IsBPPPreview == MMI_TRUE)
        {
            mmi_bt_bpp_app_print(MMI_BPP_APP_CALENDAR, mmi_clndr_xhtml_table_constructer);    
            g_clndr_cntx->IsBPPPreview = MMI_FALSE;
        }
        /* Entry bpp print preview screen to create calendar snapshot */
        else
        {
        /* Add Calendar screen into history*/
        #ifndef __MMI_CALENDAR_V2__
            gClndrAddToHistory = TRUE;
        #endif
            
            /*Entry bpp preview screen*/
            g_clndr_cntx->IsBPPPreview = MMI_TRUE;
            EntryClndrScreen();
        }
        
    }
    return;
}

void mmi_clndr_bpp_get_snapshot_file_path(S8* file_path)
{
	S8 file_path_ascii[CLNDR_BPP_MAX_FILE_PATH];
	
	memset(file_path_ascii, 0, CLNDR_BPP_MAX_FILE_PATH);
	BPP_MAKE_TEMP_FOLDER(file_path_ascii);
	strcat(file_path_ascii, (S8*)CLNDR_SNAPSHOT_FILE_NAME);
   	mmi_asc_to_ucs2(file_path, file_path_ascii);
}

void mmi_clndr_bpp_create_snapshot(S8* file_path)
{
	U8 *tbuffer; /*buffer to get calendar snapshot */

	tbuffer = (U8*)mmi_frm_scrmem_alloc(T_SIZE);    
#ifdef __MMI_CALENDAR_V2__
	wgui_cat83_save_snapshot(tbuffer, T_SIZE, (U8*)file_path);
#else
	wgui_cat80_save_snapshot(tbuffer, T_SIZE, (U8*)file_path);
#endif	
	mmi_frm_scrmem_free(tbuffer);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_xhtml_table_constructer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_xhtml_table_constructer(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;
    mmi_bpp_xhtml_table_css_struct *tab_css;
    mmi_bpp_xhtml_style_class_struct *cell_css;
    mmi_bpp_xhtml_data_element_struct *data;
    FS_HANDLE fh = 0;   /* file handle */    
    S8 snapshot_file_path[CLNDR_BPP_MAX_FILE_PATH * ENCODING_LENGTH];
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check BPP response */
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
	{
    	mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
    	FS_Delete((U16*)snapshot_file_path);
		return;
	}
    
    /* config table css */
    tab_css = (mmi_bpp_xhtml_table_css_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_table_css_struct));

    /* the attributes should be set as 0 if not used */
    memset(tab_css, 0, sizeof(mmi_bpp_xhtml_table_css_struct));
    /* set css */
    tab_css->caption_side = MMI_BPP_XHTML_ALIGN_NONE;

    rsp = app_config_table_css(tab_css);
    free_ctrl_buffer(tab_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* config task_css css */
    cell_css = (mmi_bpp_xhtml_style_class_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_style_class_struct));
    /* the attributes should be set as 0 if not used */
    memset(cell_css, 0, sizeof(mmi_bpp_xhtml_style_class_struct));

    /* prepare style class name calendar_css_name[] */
    sprintf((S8*)cell_css->class_name, "calendar-img-css");

    /* set calendar_css (image data cell) */    

    rsp = app_config_style_class(cell_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        free_ctrl_buffer(cell_css);
        return;
    }

    /* prepare style class name task_css_name[] */
    sprintf((S8*)cell_css->class_name, "calendar-data-css");

    /* set task_css (common data cell) */
    cell_css->txt_v_align = MMI_BPP_XHTML_ALIGN_MIDDLE;
    cell_css->txt_h_align = MMI_BPP_XHTML_ALIGN_LEFT;
    cell_css->text_color = MMI_BPP_XHTML_COLOR_BLACK;    
    //cell_css->left_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    //cell_css->left_border.border_width = 1;     /* px */
    //cell_css->right_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    //cell_css->right_border.border_width = 1;    /* px */
    //cell_css->top_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    //cell_css->top_border.border_width = 1;      /* px */
    cell_css->bottom_border.border_color = MMI_BPP_XHTML_COLOR_GRAY;
    cell_css->bottom_border.border_width = 1;   /* px */
    cell_css->bottom_border.border_style = MMI_BPP_XHTML_BORDER_DASHED;
        
    cell_css->width = 30;

    rsp = app_config_style_class(cell_css);
    free_ctrl_buffer(cell_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* inline image data from file */
    rsp = app_compose_xhtml_file_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* prepare caption[] */
    rsp = app_compose_xhtml_table_element_start(NULL, 0);   /* utf-8(ascii) encoded */
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* for first row of the image data */
    rsp = app_compose_xhtml_row_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    rsp = app_compose_xhtml_data_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* compose function */
    /* compose data element structure */
    data = (mmi_bpp_xhtml_data_element_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
    /* the attributes should be set as 0 if not used */
    memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));

    /* set calendar_css_name attributes */
    sprintf((S8*)data->class_name, "calendar-img-css");
    data->name_len = strlen((S8*)data->class_name);

    /* prepare image file handler */
    mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
    fh = FS_Open((U16*) snapshot_file_path, FS_READ_ONLY);
    FS_GetFileSize(fh, &(data->obj_len));

    if (fh < 0)
    {
    	mmi_bt_bpp_document_compose_done(MMI_BPP_DOC_COMPOSE_FAILED);  
        return;
    }

    /* prepare the image FS_HANDLE open by DRM API */
    data->file_element = fh;

    /* data->obj_len = calendar_img_size; */
    data->app_callback = mmi_clndr_bpp_img_file_callback;
    data->type = MMI_BPP_XHTML_TYPE_JPG;
    data->img_box = 30;
    /* switch(image_type)
       {
       case JPEG:
       data->type = MMI_BPP_XHTML_TYPE_JPG;
       break;
       case GIF:
       data->type = MMI_BPP_XHTML_TYPE_GIF;
       break;
       case BMP:
       data->type = MMI_BPP_XHTML_TYPE_BMP;
       break;            
       }  */
    rsp = app_compose_xhtml_data_element_from_file(data);
    free_ctrl_buffer(data);
    switch (rsp)
    {
        case MMI_BPP_XHTML_RSP_WRITING:
            return;
        case MMI_BPP_XHTML_RSP_DONE:
            mmi_clndr_bpp_img_file_callback(rsp);
            return;
        default:
            return;
    }
}

/* mmi_clndr_bpp_img_file_callback */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_bpp_img_file_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_bpp_img_file_callback(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;
	S8 snapshot_file_path[CLNDR_BPP_MAX_FILE_PATH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
	{
		return;
	}
	mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
	FS_Delete((U16*)snapshot_file_path);
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    rsp = app_compose_xhtml_data_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    g_clndr_cntx->calendar_task_index = 0;
    rsp = app_compose_xhtml_row_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    rsp = mmi_clndr_bpp_compose_tasks();
    switch (rsp)
    {
        case MMI_BPP_XHTML_RSP_DONE:
            break;
        case MMI_BPP_XHTML_RSP_WRITING:
            return;
        default:
            return;
    }

    /* tasks done -> table and file end */
    mmi_clndr_bpp_compose_file_end();
    return;
}

/* mmi_clndr_bpp_compose_tasks */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_bpp_compose_tasks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_bpp_xhtml_rsp_enum mmi_clndr_bpp_compose_tasks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;
    S8 task_str[(((CLNDR_TIME_STRING_LENGTH + 1) * ENCODING_LENGTH) * 2) + MAX_TODO_LIST_NOTE + ENCODING_LENGTH];       /* UCS2 [hh:mm-hh:mm note\0] */
    S8 task_str_utf8[sizeof(task_str) * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get all tasks of highlight cell */
#ifdef __MMI_CALENDAR_V2__
	mmi_tdl_set_clndr(&g_clndr_cntx->CalTime, g_clndr_cntx->DisplayType);
    if (g_clndr_cntx->DisplayType == CLNDR_MONTHLY_VIEW)
    {
        TDLMakeListOfSelectedDate(CLNDR_MONTHLY_VIEW);
    }
#ifdef __MMI_CLNDR_WEEKLY_VIEW_SUPPORT__    
    else
    {
        mmi_tdl_get_period_task();
    }
#endif /*__MMI_CLNDR_WEEKLY_VIEW_SUPPORT__*/    
#else /* __MMI_CALENDAR_V2__ */ 
	mmi_tdl_set_clndr(&g_clndr_cntx->CalTime, MMI_TRUE);
    TDLMakeListOfSelectedDate(MMI_TRUE);
#endif /* __MMI_CALENDAR_V2__ */ 

    while (g_clndr_cntx->calendar_task_index < g_tdl_cntx.TotalListedTask)
    {
        mmi_bpp_xhtml_data_element_struct *data;

        rsp = app_compose_xhtml_row_element_start();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return rsp;
        }

        rsp = app_compose_xhtml_data_element_start();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return rsp;
        }

        /* compose data element structure */
        data = (mmi_bpp_xhtml_data_element_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
        /* the attributes should be set as 0 if not used */
        memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));

        /* set task_css attributes */
        sprintf((S8*)data->class_name, "calendar-data-css");
        data->name_len = strlen((S8*)data->class_name);

        /* prepare the data buffer */
        memset(
            task_str,
            0,
            (((CLNDR_TIME_STRING_LENGTH + 1) * ENCODING_LENGTH) * 2) + MAX_TODO_LIST_NOTE + ENCODING_LENGTH);
        mmi_clndr_get_task_string(&(g_tdl_cntx.TaskList[g_tdl_cntx.SortedList[g_clndr_cntx->calendar_task_index]]), task_str);

        mmi_chset_convert(
            (mmi_chset_enum) MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (S8*) task_str,
            (S8*) task_str_utf8,
            sizeof(task_str) * 2);

        data->data_element = task_str_utf8;
        data->obj_len = strlen(task_str_utf8);
        data->app_callback = mmi_clndr_bpp_compose_task_callback;
        data->type = MMI_BPP_XHTML_TYPE_TXT;
        rsp = app_compose_xhtml_data_element_from_buff(data);
        free_ctrl_buffer(data);
        switch (rsp)
        {
            case MMI_BPP_XHTML_RSP_DONE:
                g_clndr_cntx->calendar_task_index++;
                break;
            case MMI_BPP_XHTML_RSP_WRITING:
                return rsp;
            default:
                return rsp;
        }

        rsp = app_compose_xhtml_data_element_end();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return rsp;
        }

        rsp = app_compose_xhtml_row_element_end();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return rsp;
        }
    }
    return MMI_BPP_XHTML_RSP_DONE;
}

/* calendar_compose_task_callback */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_bpp_compose_task_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_bpp_compose_task_callback(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;
    S8 task_str[(((CLNDR_TIME_STRING_LENGTH + 1) * ENCODING_LENGTH) * 2) + MAX_TODO_LIST_NOTE + ENCODING_LENGTH];       /* UCS2 [hh:mm-hh:mm note\0] */
    S8 task_str_utf8[sizeof(task_str) * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
    	return;
    }
    g_clndr_cntx->calendar_task_index++;
    while (g_clndr_cntx->calendar_task_index < g_tdl_cntx.TotalListedTask)
    {
        mmi_bpp_xhtml_data_element_struct *data;

        rsp = app_compose_xhtml_row_element_start();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return;
        }

        rsp = app_compose_xhtml_data_element_start();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return;
        }

        /* compose data element structure */
        data = (mmi_bpp_xhtml_data_element_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
        /* the attributes should be set as 0 if not used */
        memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));

        /* set task_css attributes */
        sprintf((s8*)data->class_name, "calendar-data-css");
        data->name_len = strlen((s8*)data->class_name);

        /* prepare the data buffer */
        memset(
            task_str,
            0,
            (((CLNDR_TIME_STRING_LENGTH + 1) * ENCODING_LENGTH) * 2) + MAX_TODO_LIST_NOTE + ENCODING_LENGTH);
        mmi_clndr_get_task_string(&(g_tdl_cntx.TaskList[g_tdl_cntx.SortedList[g_clndr_cntx->calendar_task_index]]), task_str);

        mmi_chset_convert(
            (mmi_chset_enum) MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (S8*) task_str,
            (S8*) task_str_utf8,
            sizeof(task_str) * 2);

        data->data_element = task_str_utf8;
        data->obj_len = strlen(task_str_utf8);
        data->app_callback = mmi_clndr_bpp_compose_task_callback;
        data->type = MMI_BPP_XHTML_TYPE_TXT;
        rsp = app_compose_xhtml_data_element_from_buff(data);
        free_ctrl_buffer(data);
        switch (rsp)
        {
            case MMI_BPP_XHTML_RSP_DONE:
                g_clndr_cntx->calendar_task_index++;
                break;
            case MMI_BPP_XHTML_RSP_WRITING:
                return;
            default:
                return;
        }

        rsp = app_compose_xhtml_data_element_end();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return;
        }

        rsp = app_compose_xhtml_row_element_end();
        if (rsp != MMI_BPP_XHTML_RSP_DONE)
        {
            return;
        }
    }

    /* tasks done -> table and file end */
    mmi_clndr_bpp_compose_file_end();    
    return;
}

/* calendar file end composer */


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_bpp_compose_file_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_bpp_compose_file_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = app_compose_xhtml_table_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_file_end();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_get_task_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task            [?]     
 *  task_str        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clndr_get_task_string(ToDoListNode *task, S8 *task_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 timeString[CLNDR_TIME_STRING_LENGTH * 2 + 1 + 1];    /* hh:mm-hh:mm\0 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ADVANCED_TODO__
    mmi_tdl_get_time_string(task, &(g_clndr_cntx->CalTime), timeString);
#else /* __MMI_ADVANCED_TODO__ */ 
    memset(timeString, 0, CLNDR_TIME_STRING_LENGTH * 2 + 1 + 1);
    sprintf(
        (S8*) timeString,
        "%02d:%02d-%02d:%02d",
        task->StartTime.nHour,
        task->StartTime.nMin,
        task->EndHour,
        task->EndMin);
#endif /* __MMI_ADVANCED_TODO__ */ 

    mmi_asc_to_ucs2((S8*) task_str, timeString);
    mmi_ucs2cat(task_str, (S8*)L" ");
    mmi_ucs2cat(task_str, (S8*)task->Note);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_clndr_bpp_delete_callback
 * DESCRIPTION
 *  Delete callback function of bpp preview screen
 * PARAMETERS
 *  task            [?]     
 *  task_str        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_clndr_bpp_delete_callback(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 snapshot_file_path[CLNDR_BPP_MAX_FILE_PATH * ENCODING_LENGTH];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clndr_bpp_get_snapshot_file_path(snapshot_file_path);
    FS_Delete((U16*)snapshot_file_path);
    return MMI_FALSE;
}

#endif /* __MMI_BPP_SUPPORT__ */ 
#endif /* __MMI_CALENDAR__ */ 


/*****************************************************************************
 * FUNCTION
 *  ClndrDateEditorCallBack
 * DESCRIPTION
 *  Call back funtion for inline date input.
 * PARAMETERS
 *  DateStr     [?]     
 *  day         [?]     
 *  month       [?]     
 *  year        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ClndrDateEditorCallBack(U8 *DateStr, U8 *day, U8 *month, U8 *year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) DateStr, (S8*) year);
    mmi_ucs2cat((S8*) DateStr, (S8*) "/");
    mmi_ucs2cat((S8*) DateStr, (S8*) month);
    mmi_ucs2cat((S8*) DateStr, (S8*) "/");
    mmi_ucs2cat((S8*) DateStr, (S8*) day);
}


#endif /* _MMI_CALENDAR_C */ // #ifndef _MMI_CALENDAR_C

