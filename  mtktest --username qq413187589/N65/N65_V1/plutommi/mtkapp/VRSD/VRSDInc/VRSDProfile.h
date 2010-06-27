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
 * VRSDProfile.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VRSDPROFILE_H
#define _MMI_VRSDPROFILE_H

/* if some header should be include before this one */
//#ifndef _NVRAM_USER_DEFS_H
//#error "nvram_user_defs.h should be included before header.h"
//#endif

/* 
 * Define
 */
#define MMI_VRSD_PROFILE_MAX_NUM    6

#define MMI_VRSD_PROFILE_1 0x01
#define MMI_VRSD_PROFILE_2 0x02
#define MMI_VRSD_PROFILE_3 0x04
#define MMI_VRSD_PROFILE_4 0x08
#define MMI_VRSD_PROFILE_5 0x10
#define MMI_VRSD_PROFILE_6 0x20

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#if defined(__MMI_VRSD_PROFILE__)
extern void mmi_vrsdprf_init_highlight_handler(void);
extern void mmi_vrsdprf_highlight_app(void);
extern void mmi_vrsdprf_entry_main_menu(void);
extern void mmi_vrsdprf_exit_main_menu(void);
extern void mmi_vrsdprf_highlight_profile(S32 nIndex);
extern void mmi_vrsdprf_hint_profile(U16 index);
extern void mmi_vrsdprf_list_playback_tag(void);
extern void mmi_vrsdprf_trn_tag(void);
extern void mmi_vrsdprf_trn_result_callback(U8 result);
extern void mmi_vrsdprf_del_tag_confirm(void);
extern void mmi_vrsdprf_del_tag(void);
extern void mmi_vrsdprf_del_tag_reset_flag(void);
extern void mmi_vrsdprf_rcg_callback(U16 appref_id);
#endif /* defined(__MMI_VRSD_PROFILE__) */ 

#endif /* _MMI_VRSDPROFILE_H */ /* #ifndef _MMI_VRSDPROFILE_H */

