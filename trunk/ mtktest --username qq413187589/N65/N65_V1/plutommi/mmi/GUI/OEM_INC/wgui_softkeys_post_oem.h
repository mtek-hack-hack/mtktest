/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  wgui_softkey_post_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for title.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
#ifndef __WGUI_SOFTKEY_POST_OEM_H__
#define __WGUI_SOFTKEY_POST_OEM_H__

#include "MMI_features.h"
#include "gui_config.h"
#include "wgui.h"

typedef enum
{
    MMI_LEFT_SOFTKEY,
        MMI_RIGHT_SOFTKEY,
#ifdef __MMI_WGUI_CSK_ENABLE__
        MMI_CENTER_SOFTKEY,
#endif 
        WGUI_MAX_SOFTKEYS
} WGUI_SOFTKEY_ENUM;

void wgui_softkey_oem_show(WGUI_SOFTKEY_ENUM key);
void wgui_softkey_oem_hide(WGUI_SOFTKEY_ENUM key);

#endif /*__WGUI_SOFTKEY_POST_OEM_H__*/
