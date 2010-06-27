/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * mmi_phnset_dispchar.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Display Characteristic
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
#ifndef MMI_PHNSET_DISPCHAR_H
#define MMI_PHNSET_DISPCHAR_H

/***************************************************************************** 
* Define
*****************************************************************************/
/* customize display char */
/* [Display Char. String list] >16:Auto gen, <16: originial, because the build-in string id <16 */
#define __MMI_MAX_WALLPAPER_IMG__   16
#define __MMI_MAX_SCREENSAVER_IMG__ 16
#define __MMI_MAX_SCREENSAVER_ANM__ 16
#define __MMI_MAX_SCREENSAVER_VDO__ 16
#define __MMI_MAX_POWER_ONOFF_IMG__ 16
#define __MMI_MAX_POWER_ONOFF_ANM__ 16
#define __MMI_MAX_POWER_ONOFF_VDO__ 16
    
#if __MMI_MAX_WALLPAPER_IMG__ > __MMI_MAX_SCREENSAVER_IMG__
#if __MMI_MAX_WALLPAPER_IMG__ > __MMI_MAX_POWER_ONOFF_IMG__
#define MMI_MAX_DISPCHAR_IMG __MMI_MAX_WALLPAPER_IMG__
#else 
#define MMI_MAX_DISPCHAR_IMG __MMI_MAX_POWER_ONOFF_IMG__
#endif 
#else /* __MMI_MAX_WALLPAPER_IMG__ > __MMI_MAX_SCREENSAVER_IMG__ */ 
#if __MMI_MAX_SCREENSAVER_IMG__ > __MMI_MAX_POWER_ONOFF_IMG__
#define MMI_MAX_DISPCHAR_IMG __MMI_MAX_SCREENSAVER_IMG__
#else 
#define MMI_MAX_DISPCHAR_IMG __MMI_MAX_POWER_ONOFF_IMG__
#endif 
#endif /* __MMI_MAX_WALLPAPER_IMG__ > __MMI_MAX_SCREENSAVER_IMG__ */ 
#if MMI_MAX_DISPCHAR_IMG > 16
#undef MMI_MAX_DISPCHAR_IMG
#define MMI_MAX_DISPCHAR_IMG 16
#endif /* MMI_MAX_DISPCHAR_IMG > 16 */ 
    
#if __MMI_MAX_SCREENSAVER_ANM__ > __MMI_MAX_POWER_ONOFF_ANM__
#define MMI_MAX_DISPCHAR_ANM __MMI_MAX_SCREENSAVER_ANM__
#else 
#define MMI_MAX_DISPCHAR_ANM __MMI_MAX_POWER_ONOFF_ANM__
#endif 
#if MMI_MAX_DISPCHAR_ANM > 16
#undef MMI_MAX_DISPCHAR_ANM
#define MMI_MAX_DISPCHAR_ANM 16
#endif /* MMI_MAX_DISPCHAR_ANM > 16 */ 
    
#if __MMI_MAX_SCREENSAVER_VDO__ > __MMI_MAX_POWER_ONOFF_VDO__
#define MMI_MAX_DISPCHAR_VDO __MMI_MAX_SCREENSAVER_VDO__
#else 
#define MMI_MAX_DISPCHAR_VDO __MMI_MAX_POWER_ONOFF_VDO__
#endif 
#if MMI_MAX_DISPCHAR_VDO > 16
#undef MMI_MAX_DISPCHAR_VDO
#define MMI_MAX_DISPCHAR_VDO 16
#endif /* MMI_MAX_DISPCHAR_VDO > 16 */ 


#define PHNSET_MAX_WALLPAPER_FRAME  30  /* relate to GDI cache size */
#define PHNSET_MAX_SUB_WALLPAPER_FRAME 20

/*************************************************************
 *  Header File Dependance Check
 *************************************************************/
#include "WallpaperDefs.h"
#include "ScreenSaverDefs.h"
#include "PowerOnOffDisplayDefs.h"
#include "DownloadDefs.h"
#include "PhoneSetupResList.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    PHNSET_TYPE_DISP_VIDEO,
    PHNSET_TYPE_DISP_IMAGE,
    PHNSET_TYPE_DISP_SWFLASH,
    PHNSET_TYPE_DISP_AVATAR,
    PHNSET_TYPE_DISP_USER,
    PHNSET_TYPE_DISP_INVALID
} PHNSET_TYPE_DISP;

typedef enum
{
    MMI_PHNSET_TYPE_WP,
#ifdef __MMI_SUB_WALLPAPER__
    MMI_PHNSET_TYPE_SUB_WP,
#endif 
    MMI_PHNSET_TYPE_SS,
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    MMI_PHNSET_TYPE_PWRON,
    MMI_PHNSET_TYPE_PWROFF,
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
    MMI_PHNSET_TYPE_MAX
} phnset_wpss_type_enum;

/*
 * Global Function                                                                    
 */
extern void mmi_dispchar_get_img_id(U8 nDataItemId, U16 *data);
extern void mmi_dispchar_set_img_id(U8 nDataItemId, U16 *data);
extern PHNSET_TYPE_DISP PhnsetGetDisplayType(U16 id);
#ifdef __MMI_SWFLASH__
extern MMI_BOOL dispchar_iswp_swflash(void);
#endif

/*
 * Global Variable
 */
#endif /* MMI_PHNSET_DISPCHAR_H */ 

