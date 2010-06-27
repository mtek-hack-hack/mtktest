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
 * VRSIType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the main header file for vrsi
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_VRSITYPE_H
#define _MMI_VRSITYPE_H

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Define
 */
#define MMI_VRSI_MAX_RCG_RESULT  6
#define MMI_VRSI_MAX_DIAL_DIGIT  20
#define MMI_VRSI_MAX_RETRY    2
#define MMI_VRSI_MAX_SD_TAG      20     /* Should be the same as engine and NVRAM setting */
#define MMI_VRSI_MAX_PROMPT_STR  128    /* characters */
#define MMI_VRSI_MAX_ADD_ENTRY   60
#define MMI_VRSI_MAX_TAG_ID 2048

#define MMI_VRSI_CMD_PROFILE_BASE      2000
#define MMI_VRSI_CMD_SCUT_BASE         2500
#define MMI_VRSI_CMD_CITY_BASE         3000

/* 
 * Typedef 
 */
typedef enum
{
    MMI_VRSI_GRAMMAR_1,
    MMI_VRSI_GRAMMAR_2,
    MMI_VRSI_GRAMMAR_3,
    MMI_VRSI_GRAMMAR_4,
    MMI_VRSI_GRAMMAR_5,
    MMI_VRSI_GRAMMAR_TOTAL,
    MMI_VRSI_GRAMMAR_DIGIT  /* Build-in */
} vrsi_grammer_enum;

typedef enum
{
    VRSI_CMD1_NONE,
    /* Single Command */
    VRSI_CMD1_EXIT,
    VRSI_CMD1_DIGIT_DIAL,
    VRSI_CMD1_HELP,
    VRSI_CMD1_REDIAL_MISSED,
    VRSI_CMD1_REDIAL_RECEIVED,
    VRSI_CMD1_REDIAL_DIALED,
    VRSI_CMD1_PROFILE1,
    VRSI_CMD1_PROFILE2,
    VRSI_CMD1_PROFILE3,
    VRSI_CMD1_PROFILE4,
    VRSI_CMD1_PROFILE5,
    VRSI_CMD1_PROFILE6,
    /* Pre Command */
    VRSI_CMD1_NAME_DIAL,
    VRSI_CMD1_NAME_QUERY,
    VRSI_CMD1_OPEN,
    VRSI_CMD1_SWITCH,
    /* Post Command */
    VRSI_CMD1_MOBILE,
    VRSI_CMD1_HOME,
    VRSI_CMD1_BUSINESS,
    VRSI_CMD1_FAX,
    VRSI_CMD1_TIME,
    /* Central Command */
    VRSI_CMD1_SWITCH_PROFILE1 = MMI_VRSI_CMD_PROFILE_BASE,
    VRSI_CMD1_SWITCH_PROFILE2,
    VRSI_CMD1_SWITCH_PROFILE3,
    VRSI_CMD1_SWITCH_PROFILE4,
    VRSI_CMD1_SWITCH_PROFILE5,
    VRSI_CMD1_SWITCH_PROFILE6,
    VRSI_CMD1_SWITCH_PROFILE7,
    VRSI_CMD1_MAX
} vrsi_grammar_cmd_1;

typedef enum
{
    VRSI_CMD2_NONE,
    /* All Are Single Command */
    VRSI_CMD2_EXIT,
    VRSI_CMD2_MOBILE,
    VRSI_CMD2_HOME,
    VRSI_CMD2_BUSINESS,
    VRSI_CMD2_FAX,
    VRSI_CMD2_MAX
} vrsi_grammar_cmd_2;

typedef enum
{
    VRSI_CMD3_NONE,
    /* All Are Single Command */
    VRSI_CMD3_EXIT,
    VRSI_CMD3_1ST,
    VRSI_CMD3_2ND,
    VRSI_CMD3_3RD,
    VRSI_CMD3_4TH,
    VRSI_CMD3_5TH,
    VRSI_CMD3_6TH,
    VRSI_CMD3_MAX
} vrsi_grammar_cmd_3;

typedef enum
{
    VRSI_CMD4_NONE,
    /* All Are Single Command */
    VRSI_CMD4_EXIT,
    VRSI_CMD4_CONFIRM,
    VRSI_CMD4_REENTRY,
    VRSI_CMD4_MAX
} vrsi_grammar_cmd_4;

typedef enum
{
    VRSI_CMD5_NONE,
    /* All Are Single Command */
    VRSI_CMD5_EXIT,
    VRSI_CMD5_SELECT,
    VRSI_CMD5_REENTRY,
    VRSI_CMD5_PREVIOUS,
    VRSI_CMD5_NEXT,
    VRSI_CMD5_DIAL,
    VRSI_CMD5_MAX
} vrsi_grammar_cmd_5;

typedef enum
{
    MMI_VRSI_STATE_CMD_NOT_READY,
    MMI_VRSI_STATE_ADDING_CMD,
    MMI_VRSI_STATE_ADDING_PAUSE,
    MMI_VRSI_STATE_IDLE,
    MMI_VRSI_STATE_RUNNING
} vrsi_mmi_state_enum;

typedef enum
{
    MMI_VRSI_APP_ALL,
    MMI_VRSI_APP_DIAL,
    MMI_VRSI_APP_SHORTCUT,
    MMI_VRSI_APP_CITY,
    MMI_VRSI_APP_TOTAL,
    MMI_VRSI_APP_NONE = 0xff
} vrsi_app_id_enum;

typedef struct
{
    U16 tag_long;
    U16 tag_id;
    U8 app_id;
    U8 dummy;
} vrsi_sd_tag_struct;

typedef struct
{
    U32 session_id;
    void (*tts_callback) (void);
    void (*init_callback) (void);
    U16 *long_name_ptr;
    U16 active_index;
    U16 central_count;
    U16 central_fail;
    U16 long_list[MMI_VRSI_MAX_RCG_RESULT];
    U8 loc_num[4];
    U8 digit_list[MMI_VRSI_MAX_DIAL_DIGIT + 1];
    U8 long_list_num;
    U8 vrsi_state;
    U8 sdtag_sync;
    U8 curr_grammar;
    U8 post_cmd;
    U8 rcg_enable;
    U8 curr_scenario;
    U8 retry;
    U8 curr_app;
    U8 curr_tag;
    U8 lang;
    BOOL is_abort;
} vrsi_context_struct;

/* 
 * Extern Global Variable
 */
extern vrsi_context_struct g_vrsi_cntx; /* Global Context */
extern const U8 *g_vrsi_grammar[];
extern const U8 g_vrsi_prompt_tone[];

/* 
 * Extern Global Function
 */

#endif /* _MMI_VRSITYPE_H */ /* #ifndef _MMI_VRSITYPE_H */

