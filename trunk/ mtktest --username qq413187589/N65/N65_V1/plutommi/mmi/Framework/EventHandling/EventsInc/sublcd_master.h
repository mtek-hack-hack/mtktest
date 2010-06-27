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
 * sublcd_master.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sublcd master interface.
 *
 * Author: 
 * -------
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

#ifndef _SUBLCD_MASTER_H
#define _SUBLCD_MASTER_H
#include "drv_comm.h"
#include "lcd_sw.h"
#include "gui_setting.h"

#ifdef __MMI_SUBLCD_MASTER_MODE__
typedef enum
{
    SUBLCD_MODE_SLAVE,
    SUBLCD_MODE_MASTER,
    SUBLCD_MODE_S2M,
    SUBLCD_MODE_M2S
} SubLCD_mode_enum;

typedef struct
{
    SubLCD_mode_enum    state;
    MMI_BOOL            is_sublcd_force_add_history;
} SubLCD_master_cntx_Struct;
extern SubLCD_master_cntx_Struct    g_sublcd_master_cntx;
#endif

MMI_BOOL EntrySubLCDMasterFromIdle(void);
void SetSubLCDMasterKeyHandler(void);
MMI_BOOL SetSubLCDInMasterMode(void);
MMI_BOOL SetSubLCDInSlaveMode(void);
MMI_BOOL IsSubLCDInMasterMode(void);
U8 EntrySubLCDMainMenu(void);
void SubLCDMasterModeClamOpen(void);
void SubLCDMasterModeClamclosed(void);

U8 EntryNewScreenSubLCDMaster(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *peerBuf);
void SetSubLCDMasterLongPressHandler(FuncPtr funcPtr, U16 keyCode);
void SetSubLCDMasterClamOpenClose(void);
void InitSubLCDMasterMode(void);
void ForceEntrySubLCDMaster(void);
void ForceEntrySubLCDSlave(void);

U8 ChangeInterruptToneInMasterMode(U8 in_tone);

void UnFreezeSubLCD(void);

#endif /* _SUBLCD_MASTER_H */ 

