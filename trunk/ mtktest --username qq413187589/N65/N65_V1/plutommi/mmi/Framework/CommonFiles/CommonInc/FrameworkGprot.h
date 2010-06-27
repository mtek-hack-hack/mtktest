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
 *  FrameworkGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework export function declaration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef FRAMEWORK_GPROT_H
#define FRAMEWORK_GPROT_H

#if	defined(UNICODE) && defined(_WINDOWS_)
#error "Please don't include windows.h and FrameworkGprot.h together when defined UNICODE, because they have redefinition problem(L4Dr.h)!"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Include header file
*****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "L4Dr.h"
#include "FrameworkStruct.h"    	    
#include "FrameworkBackwardCompatible.h"

/* NVRAMManager folder */
#include "NVRAMProt.h"
#include "NVRAMEnum.h"
#include "NVRAMType.h"
#include "NVRAMHwMapFile.h"
#include "NVRAMExdcl.h"
#include "NVRAMGdcl.h"

/* MemManager folder */
#include "OslMemory.h"
#include "AppMemMgrGprot.h"
#include "ScrMemMgrGprot.h"
#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)      
#include "ResMemMgrGprot.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

/* TasksInc folder */
#include "MMItaskGprot.h"
#include "QueueGprot.h" 

/* History folder */
#include "HistoryGprot.h"
#include "SubLCDHistoryGprot.h"

/* EventHandling folder */
#include "EventsGprot.h"
#include "EventsDef.h"
#include "EventsDcl.h"                          /* Maybe can be removed, it's included in frameworkProt.h */
#include "MMITimer.h"
#include "KeyBrd.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "TouchScreenGprot.h"
#endif 
#ifdef __MMI_SUBLCD_MASTER_MODE__
#include "Sublcd_master.h"
#endif /* __MMI_SUBLCD_MASTER_MODE__ */

/* ThemeManager folder */
#if defined(__MMI_THEMES_V2_SUPPORT__) || defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
#include "ThemeManager.h"
#include "ThemeArchiverMsgStruct.h"
#include "ThemeArchiverProt.h"
#endif 

/* File system */
#include "fs_type.h"
#include "fs_func.h" 
#include "fs_errcode.h"

#endif /* FRAMEWORK_GPROT_H*/ 

