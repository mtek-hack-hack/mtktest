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
 * EngineerModeTracer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the tracer for PS log
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
 *==============================================================================
 *******************************************************************************/

/*****************************************************************/
/*************************  Header Files *************************/
/*****************************************************************/

#include "MMI_features.h"

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

#if defined(__MMI_ENGINEER_MODE__) && defined(__EM_MODE__)

#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "PixcomFontEngine.h"   
#include "MainMenuDef.h"
#include "CustomCfg.h"
#include "audioInc.h"
#include "IdleAppDef.h"
#include "FactoryModeDef.h"
#include "FactoryModeProt.h"
#include "AlarmDef.h"
#include "gpioInc.h"
#include "DateTimeGprot.h"
#include "CallManagementIdDef.h"
#include "CallManagementGprot.h"
#include "Simdetectiondef.h"
#include "ENgineerModeTracer.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "idleappdef.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "EngineerModeProt.h"

#include "EngineerModeProt.h"
#include "CommonScreens.h"

#ifdef __EM_MODE__
#include "FileMgr.h"
#include "UserProfilesResDef.h"
#include "ProfilesDefs.h"
#include "Profiles_Prot.h"
#include "ProfileGprots.h"
#include "ProfilesGexdcl.h"
#include "ProfileMgrGProt.h"
#include "custom_mmi_default_value.h"
#include "common_nvram_editor_data_item.h"
#endif /* #ifdef __EM_MODE__ */


/*****************************************************************/
/****************  Structure / Variables Declaration *************/
/*****************************************************************/
#define MAX_TRACER_SCREEN_NUM 15
#define MAX_TRACER_LINE_NUM 14
#define EM_LOG_SCREEN_ID 907

#define TEXT_FORMAT_1   "%s:%2d%2d%2d"
#define TEXT_FORMAT_2   "%s:%d"
#define TEXT_FORMAT_3   "%4d %4d %4d %4d %4d %4d"
#define TEXT_FORMAT_4   "%s:%2d %2d"
#define TEXT_FORMAT_5   "%s:%2d%2d%2s"
#define TEXT_FORMAT_6   "%4s %4s %4s %4s %4s %4s"
#define TEXT_FORMAT_7   "%4s %4s %3s %3s %1s"
#define TEXT_FORMAT_8   "%4d %4d %3d %3d %1d"
#define TEXT_FORMAT_9   "%s:%d/%d"
#define TEXT_FORMAT_10  "%s:%2s"
#define TEXT_FORMAT_11  "%4d %4d %3s %3s %1d"
#define TEXT_FORMAT_12  "%s:%s"
#define TEXT_FORMAT_13  "%4s %4s %3s %3s %1s"
#define TEXT_FORMAT_14  "%s:%d  %s:%d"
#define TEXT_FORMAT_15  "%s:%s  %s:%s"
#define TEXT_FORMAT_16  "%s:%d %s:%d %s:%d"
#define TEXT_FORMAT_17  "%s:%s %s:%s %s:%s"
#define TEXT_FORMAT_18  "%d %d %d %d %d %d %d %d"
#define TEXT_FORMAT_19  "%s"
#define TEXT_FORMAT_20  "%s: %d/%d"
#define TEXT_FORMAT_21  "%s: %x%x%x%x%x%x %x%x%x%x%x%x"
#define TEXT_FORMAT_22  "%s: %s %x%x%x%x%x%x"
#define TEXT_FORMAT_23  "%s: %x%x%x%x%x%x %s"
#define TEXT_FORMAT_24  "%s: %s %s"
#define TEXT_FORMAT_25  "%s: %x%x%x%x%x%x"
#define TEXT_FORMAT_26  "%s: 0x%x"
#define TEXT_FORMAT_27  "%s: %d %d %d %d"
#define TEXT_FORMAT_28  "%s:%2s %s:%d"
#define TEXT_FORMAT_29  "%s:%d %s:%2s"
#define TEXT_FORMAT_30  "%s:%d %s:0x%x %s:%d"
#define TEXT_FORMAT_31  "%s:%d %s:0x%x"

#define NA_SYMBOL "X"
#define EM_IS_SET(b, a)       ((b & (0x1 << a)) >> a)

#define MAX_CHANNEL_TYPE_COUNT (sizeof(rr_channel_type_name)/sizeof(rr_channel_type_name[0]) )

#ifdef __EM_MODE__

#define MAX_NWEVENT_OF_A_GROUP    20

typedef struct
{
    U8 is_on;                  /* request start or stop */

    U16 total_item_num;                             /* total num of events */
    U8  event_num_of_group[EM_NW_MAX_NO_OF_GROUP];  /* event num of a group */
    U16 cur_start_idx_in_tbl;                       /* current start index in the table [shared] */

    /* filter */
    U8  *pEmNwEventGroupOnOff[2];
    S32 group_cur_state[EM_NW_MAX_NO_OF_GROUP];
    
    U32 group_filter_mask;                          /* gropu filter mask */
    U32 event_filter_mask[EM_NW_MAX_NO_OF_GROUP];   /* event filter mask in a group */

    /* setting */
    U32 current_event;                              /* current event in this group */
    U32 current_group;                              /* current group */

    /* notififcation */
    U8 is_playing;                                  /* is playing or not */
    U16 event_rone_queue[EM_NW_NUM_OF_QUEUE_EVENT]; /* event queue */
    U8 cur_playing_index;                           /* cur playing idx in event queue */
    U8 cur_queue_index;                             /* cur idx in event queue to add new entry */
} em_nw_event_struct;

em_nw_event_struct g_nw_event_cntx = {0};

extern void mmi_profiles_Ext_melody_set_tone_type(PRFSET_MELODY_CONF_TYPE type);

#endif /* #ifdef __EM_MODE__ */


/* below string table is to follow the em_struct.h to display */
const char *const rr_channel_type_name[] = 
{
    "PBCCH",
    "PRACH",
    "PCCCH",
    "PDTCH",
    "PACCH",
    "BCCH",
    "N_BCCH",
    "E_BCCH",
    "CCCH",
    "PAG_CH",
    "RACH",
    "SDCCH4",
    "SDCCH4",
    "SDCCH4",
    "SDCCH4",
    "SDCCH8",
    "SDCCH8",
    "SDCCH8",
    "SDCCH8",
    "SDCCH8",
    "SDCCH8",
    "SDCCH8",
    "SDCCH8",
    "SDCCH",
    "SACCH",
    "FACCH",
    "TCH_EF",
    "TCH_F",
    "TCH_H",
    "TCH_H",
    "TCH_H",
    "CBCH",
    "PPCH"
};

const char *const rr_cipher_algo_name[] = 
{
    "OFF",
    "A51",
    "A52"
};

const char *const rr_downlink_signal_fail_name[] = 
{
    "DSF",
    "RLF"
};

const char *const amr_info_bitwise_name[] = 
{
    "AFS1220",  /* bit 0 */
    "AFS1020",  /* bit 1 */
    "AFS795",   /* bit 2 */
    "AFS740",   /* bit 3 */
    "AFS670",   /* bit 4 */
    "AFS590",   /* bit 5 */
    "AFS515",   /* bit 6 */
    "AFS475",   /* bit 7 */
    "AHS795",   /* bit 8 */
    "AHS740",   /* bit 9 */
    "AHS670",   /* bit 10 */
    "AHS590",   /* bit 11 */
    "AHS515",   /* bit 12 */
    "AHS475",   /* bit 13 */
    "X",        /* bit 14 */
    "X"         /* bit 15 */
};

/* Network Info CheckBox Enum Type */
typedef enum
{
   /* RR */ 
   MMI_EM_CELL_SELECT_PARA_INFO   = 0x00000001 ,
   MMI_EM_CHANNEL_DESCR_INFO      = 0x00000002 ,
   MMI_EM_CTRL_CHANNEL_DESCR_INFO = 0x00000004 ,
   MMI_EM_RACH_CTRL_PARA_INFO     = 0x00000008 ,
   MMI_EM_LAI_INFO                = 0x00000010 ,
   MMI_EM_RADIO_LINK_COUNTER_INFO = 0x00000020 ,
   MMI_EM_MEASUREMENT_REPORT_INFO = 0x00000040 ,
      
   /* CC */ 
   MMI_EM_CHANNEL_INFO            = 0x00000080 ,
   MMI_EM_CALL_INFO               = 0x00000100 ,
   
   /* CB */
   MMI_EM_INFO                    = 0x00000200 ,
   
   /* GPRS General Info */
   MMI_EM_PLMN_INFO_STRUCT_INFO   = 0x00000400 ,

   /*EM ehancement for RR new structure*/
   MMI_EM_GPRS_GENERAL_INFO       = 0x00000800 ,
   MMI_EM_SI2Q_MI_INFO_STRUCT_INFO  = 0x00001000,
   MMI_EM_TBF_INFO                  = 0x00002000,   
   MMI_EM_BLK_INFO                  = 0x00004000
   
} em_network_info_type_enum;


/************************************/
/********  Local Variables **********/
/************************************/
static kal_uint8 index_screen = 0;
static kal_uint8 mmi_screen_text[MAX_TRACER_LINE_NUM][40];
static kal_uint8 num_of_carriers = 0;
static request_info_type receive_last_info = 0x00;
static mmi_rr_em_cell_select_para_info_t mmi_rr_em_cell_select_para_info;
static mmi_rr_em_channel_descr_info_t mmi_rr_em_channel_descr_info;
static mmi_rr_em_ctrl_channel_descr_info_t mmi_rr_em_ctrl_channel_descr_info;
static mmi_rr_em_rach_ctrl_para_info_t mmi_rr_em_rach_ctrl_para_info;
static mmi_rr_em_lai_info_t mmi_rr_em_lai_info;
static mmi_rr_em_radio_link_counter_info_t mmi_rr_em_radio_link_counter_info;
static mmi_rr_em_measurement_report_info_t mmi_rr_em_measurement_report_info;
static rr_em_channel_descr_info_struct channel_descr_info;
static rr_em_measurement_report_info_struct meas_report_info;
static rr_em_control_msg_info_struct control_msg_info;
static rr_em_radio_link_counter_info_struct radio_link_counter_info;
static mmrr_plmn_info_struct mmi_rr_em_plmn_info;
static rr_em_gprs_general_info_struct mmi_rr_em_gprs_general_info;
static rr_em_si2q_info_struct mmi_rr_em_si2q_info;
static rr_em_mi_info_struct mmi_rr_em_mi_info;
static rr_em_tbf_status_struct mmi_rr_em_tbf_info;
static rr_em_blk_info_struct mmi_rr_em_blk_info;

/************************************/
/********  Global Variables *********/
/************************************/
kal_uint8 gIsOnEMTracer = 0;
U8 gEmInfoOn = 0;
U32 currentEmMode = 0;
U32 newEmMode = 0;
EmCommandTypeEnum currentEmCommand = EM_NONE;
U8 activeEmModeIndex;

U8 EmModeEnabled[MAX_EM_MODE] = 
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0
};

S8 *channel_type[] = 
{
    "PBCCH",
    "PRACH",
    "PCCCH",
    "PDTCH",
    "PACCH",
    "BCCH",
    "N_BCCH",
    "E_BCCH",
    "CCCH",
    "PAG_CH",
    "RACH",
    "SDCCH4_0",
    "SDCCH4_1",
    "SDCCH4_2",
    "SDCCH4_3",
    "SDCCH8_0",
    "SDCCH8_1",
    "SDCCH8_2",
    "SDCCH8_3",
    "SDCCH8_4",
    "SDCCH8_5",
    "SDCCH8_6",
    "SDCCH8_7",
    "SDCCH",
    "SACCH",
    "FACCH",
    "TCH_EF",
    "TCH_F",
    "TCH_H_0",
    "TCH_H_1",
    "TCH_H",
    "CBCH",
    "PPCH"
};

typedef struct {

    S32     currCellLock;
    S32     curr1900Band;    
    U8      *pEMEmNWCellLock[2];
    U8      *pEMEmNW1900Band[2];    
    U8      arfcn[10];
        
} em_nw_cell_lock_struct;

em_nw_cell_lock_struct g_em_nw_cell_lock_cntx={0};


/*****************************************************************/
/******************  External functions / variables **************/
/*****************************************************************/
extern void UI_set_clip(S32 x1, S32 y1, S32 x2, S32 y2);
extern void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void UI_set_font(UI_font_type f);
extern void UI_set_text_color(color c);

extern kal_uint32 MAIN_LCD_device_height;
extern kal_uint32 MAIN_LCD_device_width;
extern U8 currentHighlightIndex;


/*****************************************************************/
/********************  Code Body (NetworkInfo) *******************/
/*****************************************************************/

/*****************************************************************************
 * FUNCTION
 *  HighlightEmNetworkSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNetworkSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmNetworkSettingMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
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
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNWCellLock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNWCellLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EmGetNWCellLockReq, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNetworkInfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNetworkInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmNetworkInfoMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNWNetworkEvents
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNWNetworkEvents(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmNetworkEventMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNWStart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNWStart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nw_event_cntx.is_on == MMI_TRUE)
    {
        Category52ChangeItemDescription(0, (U8*) get_string(STR_GLOBAL_ON));
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        Category52ChangeItemDescription(0, (U8*) get_string(STR_GLOBAL_OFF));
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EmNetworkEventStartReq, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNWFilter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNWFilter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmNWEventFilterMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmNWSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmNWSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryEmNWEventSettingMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  em_nw_event_select_ring_done
 * DESCRIPTION
 *  select ring tone done
 * PARAMETERS
 *  ExtMelodyFlag       [IN]        Is it a external resource
 *  ringToneId          [IN]        Selected ring tone id.
 * RETURNS
 *  void
 *****************************************************************************/
void em_nw_event_select_ring_done(U16 ringToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    em_network_event_tbl[g_nw_event_cntx.cur_start_idx_in_tbl+g_nw_event_cntx.current_event].ring_tone_id = ringToneId;

    DeleteScreenIfPresent(SCR_PROFILES_RING_TONE_SETUP);
    DeleteScreenIfPresent(MENU_TONE_SETUP_RING_TONE_EXT_MELODY);
    
    mmi_profiles_preview_stop_tone();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmNetworkSettingMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmNetworkSettingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[10];
    U16 ItemIcons[10];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[10];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_NETWORK_SETTING_MENU_SCR, NULL, EntryEmNetworkSettingMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_SETTING_MENU_SCR);

    nItems = GetNumOfChild(EM_NETWORK_SETTING_MENUID);
    GetSequenceStringIds(EM_NETWORK_SETTING_MENUID, ItemList);
    SetParentHandler(EM_NETWORK_SETTING_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i); 
    }

    ShowCategory52Screen(
        EM_NETWORK_SETTING_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmNetworkInfoMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmNetworkInfoMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[] = 
    {
        EM_NET_RR_CELL_SEL_TEXT,     /* 1 */
        EM_NET_RR_CH_DSCR_TEXT,      /* 2 */
        EM_NET_RR_CTRL_CH_TEXT,      /* 3 */
        EM_NET_RR_RACH_CTRL_TEXT,    /* 4 */
        EM_NET_RR_LAI_INFO_TEXT,     /* 5 */
        EM_NET_RR_RADIO_LINK_TEXT,   /* 6 */
        EM_NET_RR_MEAS_REP_TEXT,     /* 7 */
        EM_NET_CC_CHAN_INFO_TEXT,    /* 8 */
        EM_NET_CC_CALL_INFO_TEXT,    /* 9 */
        EM_NET_CB_INFO_TEXT,         /* 10 */
        EM_NET_PLMN_INFO_TEXT,       /* 11 */
        EM_NET_GPRS_INFO_TEXT,       /* 12 */
        EM_NET_Si2Q_MI_INFO_TEXT,    /* 13 */
        EM_NET_TBF_STATUS_TEXT,      /* 14 */
        EM_NET_BLK_INFO_TEXT        /* 15 */        
    };
    U16 nNumofItem = 15;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_NETWORK_INFO_MENU_SCR, NULL, EntryEmNetworkInfoMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_INFO_MENU_SCR); 

    RegisterHighlightHandler(SetEmModeIndex);
    
    ShowCategory13Screen(
        EM_NETWORK_INFO_TEXT,
        EM_NETWORK_ICON,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        EmModeEnabled,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(EnableDisableEmMode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(CheckEmMode, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  SetEmModeIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetEmModeIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activeEmModeIndex = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EnableDisableEmMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnableDisableEmMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newEmMode = 0x00000001 << activeEmModeIndex;
    
    if (EmModeEnabled[activeEmModeIndex])
    {
        EmModeEnabled[activeEmModeIndex] = 0;

        if (activeEmModeIndex < 10)    /* emnu is mapping as em_struct.h */
        {
            currentEmMode &= ~newEmMode;
            receive_last_info &= ~newEmMode;
        }
        else   /* emnu is NOT mapping as em_struct.h */
        {
            if (newEmMode & MMI_EM_PLMN_INFO_STRUCT_INFO)
            {
                currentEmMode &= ~MMRR_EM_PLMN_INFO_STRUCT_INFO;
                
                receive_last_info &= ~MMI_EM_PLMN_INFO_STRUCT_INFO;
            }
            else if (newEmMode & MMI_EM_GPRS_GENERAL_INFO)
            {
                currentEmMode &= ~RR_EM_GPRS_GENERAL_INFO;      
                
                receive_last_info &= ~MMI_EM_GPRS_GENERAL_INFO;
            }
            else if (newEmMode & MMI_EM_SI2Q_MI_INFO_STRUCT_INFO)
            {
                currentEmMode &= ~RR_EM_SI2Q_INFO_STRUCT_INFO;                        
                currentEmMode &= ~RR_EM_MI_INFO_STRUCT_INFO;     
                
                receive_last_info &= ~MMI_EM_SI2Q_MI_INFO_STRUCT_INFO;
            }
            else if (newEmMode & MMI_EM_TBF_INFO)
            {
                currentEmMode &= ~RR_EM_TBF_INFO;                        
                
                receive_last_info &= ~MMI_EM_TBF_INFO;
            }
            else if (newEmMode & MMI_EM_BLK_INFO)
            {
                currentEmMode &= ~RR_EM_BLK_INFO;                        

                receive_last_info &= ~MMI_EM_BLK_INFO;
            }
            else
                ASSERT(0);
        }
    }
    else
    {
        EmModeEnabled[activeEmModeIndex] = 1;

        if (activeEmModeIndex < 10)    /* emnu is mapping as em_struct.h */
        {
            currentEmMode |= newEmMode; 
            
            receive_last_info |= newEmMode; 
        }
        else   /* emnu is NOT mapping as em_struct.h */
        {
            if (newEmMode & MMI_EM_PLMN_INFO_STRUCT_INFO)
            {
                currentEmMode |= MMRR_EM_PLMN_INFO_STRUCT_INFO;    
                
                receive_last_info |= MMI_EM_PLMN_INFO_STRUCT_INFO;
            }
            else if (newEmMode & MMI_EM_GPRS_GENERAL_INFO)
            {
                currentEmMode |= RR_EM_GPRS_GENERAL_INFO; 
                
                receive_last_info |= MMI_EM_GPRS_GENERAL_INFO;
            }
            else if (newEmMode & MMI_EM_SI2Q_MI_INFO_STRUCT_INFO)
            {
                currentEmMode |= RR_EM_SI2Q_INFO_STRUCT_INFO;  
                currentEmMode |= RR_EM_MI_INFO_STRUCT_INFO; 
                
                receive_last_info |= MMI_EM_SI2Q_MI_INFO_STRUCT_INFO;
            }
            else if (newEmMode & MMI_EM_TBF_INFO)
            {
                currentEmMode |= RR_EM_TBF_INFO;  
                
                receive_last_info |= MMI_EM_TBF_INFO;
            }
            else if (newEmMode & MMI_EM_BLK_INFO)
            {
                currentEmMode |= RR_EM_BLK_INFO;  
                
                receive_last_info |= MMI_EM_BLK_INFO;
            }
            else
                ASSERT(0);
        }
    }

    standard_check_list_handle_item_select(activeEmModeIndex);    
}


/*****************************************************************************
 * FUNCTION
 *  CheckEmMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CheckEmMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U32 mask = 0x00000001;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, CheckEmMode, NULL);

    newEmMode = 0;

    for (i = 0; i < MAX_EM_MODE; i++)
    {
        if (EmModeEnabled[i])
        {
            newEmMode |= mask;
        }
        mask = mask << 1;
    }

    ShowCategory2Screen(EM_UPDATE_TITLE_TEXT, 0, STR_GLOBAL_YES, 0, STR_GLOBAL_NO, 0, EM_UPDATE_QUERY_TEXT, NULL);
    SetLeftSoftkeyFunction(SendEmStartMsg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackFromNetworkSetting, KEY_EVENT_UP);
    ReplaceNewScreenHandler(EM_NETWORK_INFO_MENU_SCR, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  GoBackFromNetworkSetting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackFromNetworkSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  SendEmStartMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendEmStartMsg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentEmCommand = EM_START;
    EngineerModeStartReq(MOD_AS, currentEmMode /* newEmMode */ );

#ifndef __MTK_TARGET__
    EngineerModeStatusUpdate(0, currentEmMode /* newEmMode */ );
    EngineerModeSuccessNotice(EM_UPDATE_SUCCESS_TEXT);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStartReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id          [IN]        
 *  info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStartReq(U32 mod_id, U32 info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_init();
    mmi_em_trace_on_ind();
    mmi_em_send_start_req(mod_id, info_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_send_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id      [IN]        
 *  info_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_send_start_req(module_type mod_id, request_info_type info_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_em_start_req_struct *em_start_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_em_send_start_req %d", info_id);
    mmi_em_show_screen();

    Message.oslMsgId = MSG_ID_MMI_EM_START_REQ;
    em_start_req = OslConstructDataPtr(sizeof(mmi_em_start_req_struct));
    em_start_req->mod_id = mod_id;
    em_start_req->info_request = info_id;

    Message.oslDataPtr = (oslParaType*) em_start_req;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    OslMsgSendExtQueue(&Message);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_display_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_display_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 page_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_screen_text, 0, sizeof(mmi_screen_text));

    mmi_rr_em_cell_select_para_info.is_present = 0;
    mmi_rr_em_channel_descr_info.is_present = 0;
    mmi_rr_em_ctrl_channel_descr_info.is_present = 0;
    mmi_rr_em_rach_ctrl_para_info.is_present = 0;
    mmi_rr_em_lai_info.is_present = 0;
    mmi_rr_em_radio_link_counter_info.is_present = 0;
    mmi_rr_em_measurement_report_info.is_present = 0;

    MMI_ASSERT(page_count <= MAX_TRACER_SCREEN_NUM);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_trace_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_trace_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_em_parsing_data, MSG_ID_MMI_EM_STATUS_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_parsing_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_parsing_data(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_status_ind_struct *msg = (mmi_em_status_ind_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_em_parsing_data=%d, %d", msg->mod_id, msg->em_info);

//    if (msg->mod_id == MOD_AS)
    {
        mmi_em_rr_process_logs(msg->em_info, msg->info);

        /* display the trace information on screen */
        mmi_em_show_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_show_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_show_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 current_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gIsOnEMTracer == 0)
    {
        EntryNewScreen_Ext(EM_LOG_SCREEN_ID, mmi_em_exit_screen, NULL, NULL);
    }

    current_screen = GetCurrScrnId();
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_em_show_screen %d", current_screen);

    if ((current_screen == IDLE_SCREEN_ID) || (current_screen == SCR_SIM_INSERTION) ||
        (current_screen == SCR_CM_ACTIVECALLSCREEN))
    {
        if (gIsOnEMTracer == 0) 
        {
            ShowCategory7Screen(0, 0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, NULL);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }

        if (IsScreenPresent(EM_LOG_SCREEN_ID))
        {
            DeleteScreenIfPresent(EM_LOG_SCREEN_ID); 
        }

        gIsOnEMTracer = 1;

        /* register key handler */
        mmi_em_tracer_key();
        if (current_screen == SCR_CM_ACTIVECALLSCREEN)
        {
            U16 IdleScreenDigits[MAX_CM_SCREEN_DIGITS] = 
            {
                KEY_0, KEY_1, KEY_2, KEY_3,
                KEY_4, KEY_5, KEY_6, KEY_7,
                KEY_8, KEY_9, KEY_STAR,
                KEY_POUND
            };
            SetGroupKeyHandler(EnterScreenAndHandleDigit, IdleScreenDigits, MAX_CM_SCREEN_DIGITS - 1, KEY_EVENT_DOWN);
        }

        mmi_em_display_screen_n(index_screen);

    }
    else if (gIsOnEMTracer == 0)
    {
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsOnEMTracer = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_em_tracer_key_up, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_em_tracer_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_em_tracer_key_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_em_tracer_key_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_em_tracer_pen_down);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_key_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index_screen == 0)
    {
        index_screen = MAX_TRACER_SCREEN_NUM - 1;
    }
    else
    {
        index_screen--;
    }

    mmi_em_display_screen_n(index_screen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_key_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index_screen++;
    if (index_screen >= MAX_TRACER_SCREEN_NUM)
    {
        index_screen = 0;
    }

    mmi_em_display_screen_n(index_screen);

}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_pen_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_pen_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if y position is in button bar or not */
    if (pos.y >= MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT - 1)
    {
        /* If in button bar,  the event handler will be passed to gerneral handler. (softkey handler)  */
        wgui_general_pen_down_hdlr(pos);
    }
    else
    {
        /* If not in button bar,  execute dedicate handler.  */
        index_screen++;
        if (index_screen >= MAX_TRACER_SCREEN_NUM)
        {
            index_screen = 0;
        }

        mmi_em_display_screen_n(index_screen);
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_process_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  em_info             [IN]        
 *  pdu_buff_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_process_logs(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_em_rr_process_logs=%d", em_info);
    switch (em_info)
    {
        case RR_EM_CELL_SELECT_PARA_INFO:
        {
            rr_em_cell_select_para_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_cell_select_para_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            /* data_ptr = (rr_em_cell_select_para_info_struct *) pdu_buff_ptr; */
            mmi_em_rr_cell_select_logs_value((rr_em_cell_select_para_info_struct*) data_ptr);
        }
            break;
        case RR_EM_CHANNEL_DESCR_INFO:
        {
            rr_em_channel_descr_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_channel_descr_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_channel_descr_logs_value((rr_em_channel_descr_info_struct*) data_ptr);
        }
            break;
        case RR_EM_CTRL_CHANNEL_DESCR_INFO:
        {
            rr_em_ctrl_channel_descr_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_ctrl_channel_descr_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            /* data_ptr = (rr_em_ctrl_channel_descr_info_struct *) pdu_buff_ptr; */
            mmi_em_rr_ctrl_channel_descr_logs_value((rr_em_ctrl_channel_descr_info_struct*) data_ptr);
        }
            break;
        case RR_EM_RACH_CTRL_PARA_INFO:
        {
            rr_em_rach_ctrl_para_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_rach_ctrl_para_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            /* data_ptr = (rr_em_rach_ctrl_para_info_struct *) pdu_buff_ptr; */
            mmi_em_rr_rach_ctrl_para_info_logs_value((rr_em_rach_ctrl_para_info_struct*) data_ptr);
        }
            break;
        case RR_EM_LAI_INFO:
        {
            rr_em_lai_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_lai_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_lai_info_logs_value((rr_em_lai_info_struct*) data_ptr);
        }
            break;
        case RR_EM_RADIO_LINK_COUNTER_INFO:
        {
            rr_em_radio_link_counter_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_radio_link_counter_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_radio_link_counter_info_logs_value((rr_em_radio_link_counter_info_struct*) data_ptr);
        }
            break;
        case RR_EM_MEASUREMENT_REPORT_INFO:
        {
            rr_em_measurement_report_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_measurement_report_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_measurement_report_info_logs_value((rr_em_measurement_report_info_struct*) data_ptr);
        }
            break;
        case MMRR_EM_PLMN_INFO_STRUCT_INFO:
        {
            mmrr_plmn_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (mmrr_plmn_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_plmn_info_logs_value((mmrr_plmn_info_struct*) data_ptr);
            break;
        }
        case RR_EM_GPRS_GENERAL_INFO:
        {
            rr_em_gprs_general_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_gprs_general_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_gprs_general_info_logs_value((rr_em_gprs_general_info_struct*) data_ptr);
            break;
        }
        case RR_EM_SI2Q_INFO_STRUCT_INFO:
        {
            rr_em_si2q_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_si2q_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_si2q_info_logs_value((rr_em_si2q_info_struct*) data_ptr);
            break;
        }
        case RR_EM_MI_INFO_STRUCT_INFO:
        {
            rr_em_mi_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_mi_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_mi_info_logs_value((rr_em_mi_info_struct*) data_ptr);
            break;
        }
        case RR_EM_TBF_INFO:
        {
            rr_em_tbf_status_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_tbf_status_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_tbf_info_logs_value((rr_em_tbf_status_struct*) data_ptr);
            break;
        }
        case RR_EM_BLK_INFO:
        {
            rr_em_blk_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;

            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (rr_em_blk_info_struct*) get_pdu_ptr(pdu_buff_ptr, &mm_pdu_len);
            mmi_em_rr_blk_info_logs_value((rr_em_blk_info_struct*) data_ptr);
            break;
        }
        default:
            break;
    }
    free_peer_buff(pdu_buff_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_cell_select_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_cell_select_para_info     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_cell_select_logs_value(rr_em_cell_select_para_info_struct *rr_em_cell_select_para_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_cell_select_para_info.is_present = 1;
    mmi_rr_em_cell_select_para_info.crh = rr_em_cell_select_para_info->crh;
    mmi_rr_em_cell_select_para_info.ms_txpwr = rr_em_cell_select_para_info->ms_txpwr;
    mmi_rr_em_cell_select_para_info.rxlev_access_min = rr_em_cell_select_para_info->rxlev_access_min;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_channel_descr_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_channel_descr_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_channel_descr_logs_value(rr_em_channel_descr_info_struct *rr_em_channel_descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_channel_descr_info.is_present = 1;
    mmi_rr_em_channel_descr_info.channel_type = rr_em_channel_descr_info->channel_type;
    mmi_rr_em_channel_descr_info.hopping_flag = rr_em_channel_descr_info->hopping_flag;
    mmi_rr_em_channel_descr_info.hsn = rr_em_channel_descr_info->hsn;
    mmi_rr_em_channel_descr_info.tn = rr_em_channel_descr_info->tn;
    mmi_rr_em_channel_descr_info.maio = rr_em_channel_descr_info->maio;
    mmi_rr_em_channel_descr_info.num_of_carriers = rr_em_channel_descr_info->num_of_carriers;
    mmi_rr_em_channel_descr_info.tsc = rr_em_channel_descr_info->tsc;

#ifdef __AMR_SUPPORT__
    mmi_rr_em_channel_descr_info.amr_valid = rr_em_channel_descr_info->amr_valid;
    mmi_rr_em_channel_descr_info.frame_number = rr_em_channel_descr_info->frame_number;
    mmi_rr_em_channel_descr_info.cmip = rr_em_channel_descr_info->cmip;
    mmi_rr_em_channel_descr_info.mr_ver = rr_em_channel_descr_info->mr_ver;
    mmi_rr_em_channel_descr_info.nscb = rr_em_channel_descr_info->nscb;
    mmi_rr_em_channel_descr_info.icmi = rr_em_channel_descr_info->icmi;
    mmi_rr_em_channel_descr_info.start_codec_mode = rr_em_channel_descr_info->start_codec_mode;
    mmi_rr_em_channel_descr_info.threshold[0] = rr_em_channel_descr_info->threshold[0];
    mmi_rr_em_channel_descr_info.threshold[1] = rr_em_channel_descr_info->threshold[1];
    mmi_rr_em_channel_descr_info.threshold[2] = rr_em_channel_descr_info->threshold[2];
    mmi_rr_em_channel_descr_info.hysteresis[0] = rr_em_channel_descr_info->hysteresis[0];
    mmi_rr_em_channel_descr_info.hysteresis[1] = rr_em_channel_descr_info->hysteresis[1];
    mmi_rr_em_channel_descr_info.hysteresis[2] = rr_em_channel_descr_info->hysteresis[2];
#endif /* __AMR_SUPPORT__ */ 

    mmi_rr_em_channel_descr_info.cipher_algo = rr_em_channel_descr_info->cipher_algo;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_ctrl_channel_descr_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_ctrl_channel_descr_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_ctrl_channel_descr_logs_value(rr_em_ctrl_channel_descr_info_struct *rr_em_ctrl_channel_descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_ctrl_channel_descr_info.is_present = 1;
    mmi_rr_em_ctrl_channel_descr_info.mscr = rr_em_ctrl_channel_descr_info->mscr;
    mmi_rr_em_ctrl_channel_descr_info.att = rr_em_ctrl_channel_descr_info->att;
    mmi_rr_em_ctrl_channel_descr_info.ccch_conf = rr_em_ctrl_channel_descr_info->ccch_conf;
    mmi_rr_em_ctrl_channel_descr_info.bs_pa_mfrms = rr_em_ctrl_channel_descr_info->bs_pa_mfrms;
    mmi_rr_em_ctrl_channel_descr_info.bs_ag_blks_res = rr_em_ctrl_channel_descr_info->bs_ag_blks_res;
    mmi_rr_em_ctrl_channel_descr_info.cbq2 = rr_em_ctrl_channel_descr_info->cbq2;
    mmi_rr_em_ctrl_channel_descr_info.t3212 = rr_em_ctrl_channel_descr_info->t3212;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_rach_ctrl_para_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_rach_ctrl_para_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_rach_ctrl_para_info_logs_value(rr_em_rach_ctrl_para_info_struct *rr_em_rach_ctrl_para_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_rach_ctrl_para_info.is_present = 1;
    mmi_rr_em_rach_ctrl_para_info.max_retrans = rr_em_rach_ctrl_para_info->max_retrans;
    mmi_rr_em_rach_ctrl_para_info.cba = rr_em_rach_ctrl_para_info->cba;
    mmi_rr_em_rach_ctrl_para_info.acc_class[0] = rr_em_rach_ctrl_para_info->acc_class[0];
    mmi_rr_em_rach_ctrl_para_info.acc_class[1] = rr_em_rach_ctrl_para_info->acc_class[1];
    mmi_rr_em_rach_ctrl_para_info.tx_integer = rr_em_rach_ctrl_para_info->tx_integer;
    mmi_rr_em_rach_ctrl_para_info.re = rr_em_rach_ctrl_para_info->re;
    mmi_rr_em_rach_ctrl_para_info.CB_supported = rr_em_rach_ctrl_para_info->CB_supported;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_lai_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_lai_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_lai_info_logs_value(rr_em_lai_info_struct *rr_em_lai_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_lai_info.is_present = 1;
    mmi_rr_em_lai_info.mcc[0] = rr_em_lai_info->mcc[0];
    mmi_rr_em_lai_info.mcc[1] = rr_em_lai_info->mcc[1];
    mmi_rr_em_lai_info.mcc[2] = rr_em_lai_info->mcc[2];
    mmi_rr_em_lai_info.mnc[0] = rr_em_lai_info->mnc[0];
    mmi_rr_em_lai_info.mnc[1] = rr_em_lai_info->mnc[1];
    mmi_rr_em_lai_info.mnc[2] = rr_em_lai_info->mnc[2];
    mmi_rr_em_lai_info.lac[0] = rr_em_lai_info->lac[0];
    mmi_rr_em_lai_info.lac[1] = rr_em_lai_info->lac[1];
    mmi_rr_em_lai_info.cell_id = rr_em_lai_info->cell_id;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_radio_link_counter_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_radio_link_counter_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_radio_link_counter_info_logs_value(rr_em_radio_link_counter_info_struct *rr_em_radio_link_counter_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_radio_link_counter_info.is_present = 1;
    mmi_rr_em_radio_link_counter_info.max_value = rr_em_radio_link_counter_info->max_value;
    mmi_rr_em_radio_link_counter_info.current_value = rr_em_radio_link_counter_info->current_value;
    mmi_rr_em_radio_link_counter_info.dtx_ind = rr_em_radio_link_counter_info->dtx_ind;
    mmi_rr_em_radio_link_counter_info.dtx_used = rr_em_radio_link_counter_info->dtx_used;
    mmi_rr_em_radio_link_counter_info.is_dsf = rr_em_radio_link_counter_info->is_dsf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_measurement_report_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_measurement_report_info       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_measurement_report_info_logs_value(rr_em_measurement_report_info_struct *rr_em_measurement_report_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_measurement_report_info.is_present = 1;
    mmi_rr_em_measurement_report_info.serving_arfcn = rr_em_measurement_report_info->serving_arfcn;
    mmi_rr_em_measurement_report_info.serv_rla_in_quarter_dbm = rr_em_measurement_report_info->serv_rla_in_quarter_dbm;
    mmi_rr_em_measurement_report_info.serving_bsic = rr_em_measurement_report_info->serving_bsic;
    mmi_rr_em_measurement_report_info.c1_serv_cell = rr_em_measurement_report_info->c1_serv_cell;
    mmi_rr_em_measurement_report_info.c2_serv_cell = rr_em_measurement_report_info->c2_serv_cell;

    mmi_rr_em_measurement_report_info.serv_gprs_supported = rr_em_measurement_report_info->serv_gprs_supported;
    mmi_rr_em_measurement_report_info.gprs_pbcch_present = rr_em_measurement_report_info->gprs_pbcch_present;
    mmi_rr_em_measurement_report_info.num_of_carriers = rr_em_measurement_report_info->num_of_carriers;
    num_of_carriers = rr_em_measurement_report_info->num_of_carriers;
    mmi_rr_em_measurement_report_info.rr_state = rr_em_measurement_report_info->rr_state;
    mmi_rr_em_measurement_report_info.multiband_report = rr_em_measurement_report_info->multiband_report;

    for (j = 0; j < 12; j++)
    {
        mmi_rr_em_measurement_report_info.nc_arfcn[j] = rr_em_measurement_report_info->nc_arfcn[j];
        mmi_rr_em_measurement_report_info.rla_in_quarter_dbm[j] = rr_em_measurement_report_info->rla_in_quarter_dbm[j];
        mmi_rr_em_measurement_report_info.c1[j] = rr_em_measurement_report_info->c1[j];
        mmi_rr_em_measurement_report_info.c2[j] = rr_em_measurement_report_info->c2[j];
        mmi_rr_em_measurement_report_info.nc_info_status[j] = rr_em_measurement_report_info->nc_info_status[j];
    }

    mmi_rr_em_measurement_report_info.timing_advance = rr_em_measurement_report_info->timing_advance;
    mmi_rr_em_measurement_report_info.rxqual_sub = rr_em_measurement_report_info->rxqual_sub;
    mmi_rr_em_measurement_report_info.rxqual_full = rr_em_measurement_report_info->rxqual_full;

#ifdef __AMR_SUPPORT__
    mmi_rr_em_measurement_report_info.amr_info_valid = rr_em_measurement_report_info->amr_info_valid;
    mmi_rr_em_measurement_report_info.cmr_cmc_cmiu_cmid = rr_em_measurement_report_info->cmr_cmc_cmiu_cmid;
    mmi_rr_em_measurement_report_info.c_i = rr_em_measurement_report_info->c_i;
    mmi_rr_em_measurement_report_info.icm = rr_em_measurement_report_info->icm;
    mmi_rr_em_measurement_report_info.acs = rr_em_measurement_report_info->acs;
#endif /* __AMR_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_plmn_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_plmn_info_struct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_plmn_info_logs_value(mmrr_plmn_info_struct *rr_plmn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i,j,k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_plmn_info.is_higher_pri_plmn_srch = rr_plmn_info->is_higher_pri_plmn_srch;
    mmi_rr_em_plmn_info.hp_timeout_timer = rr_plmn_info->hp_timeout_timer;
    mmi_rr_em_plmn_info.hp_count_down_timer = rr_plmn_info->hp_count_down_timer;

    for (i=0;i<6;i++)
    {
        mmi_rr_em_plmn_info.rplmn[i] = rr_plmn_info->rplmn[i];
        
        for (j=0;j<5;j++)
        {
            mmi_rr_em_plmn_info.eq_plmn[j][i] = rr_plmn_info->eq_plmn[j][i];
        }

        for (k=0;k<4;k++)
        {
            mmi_rr_em_plmn_info.forbid_plmn[k][i] = rr_plmn_info->forbid_plmn[k][i];        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_gprs_general_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_gprs_general_info_struct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_gprs_general_info_logs_value(rr_em_gprs_general_info_struct *rr_em_gprs_general_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_gprs_general_info.t3192 = rr_em_gprs_general_info->t3192;
    mmi_rr_em_gprs_general_info.t3168 = rr_em_gprs_general_info->t3168;
    mmi_rr_em_gprs_general_info.rp = rr_em_gprs_general_info->rp;
    mmi_rr_em_gprs_general_info.gprs_support = rr_em_gprs_general_info->gprs_support;
    mmi_rr_em_gprs_general_info.sgsn_r = rr_em_gprs_general_info->sgsn_r;
    mmi_rr_em_gprs_general_info.pfc_support = rr_em_gprs_general_info->pfc_support;
    mmi_rr_em_gprs_general_info.epcr_support = rr_em_gprs_general_info->epcr_support;
    mmi_rr_em_gprs_general_info.bep_period = rr_em_gprs_general_info->bep_period;
    mmi_rr_em_gprs_general_info.egprs_support = rr_em_gprs_general_info->egprs_support;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_si2q_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_si2q_info_struct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_si2q_info_logs_value(rr_em_si2q_info_struct *rr_em_si2q_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_si2q_info.present = rr_em_si2q_info->present;
    mmi_rr_em_si2q_info.no_of_instance = rr_em_si2q_info->no_of_instance;
    mmi_rr_em_si2q_info.emr_report = rr_em_si2q_info->emr_report;
    mmi_rr_em_si2q_info.umts_parameter_exist = rr_em_si2q_info->umts_parameter_exist;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_mi_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_mi_info_struct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_mi_info_logs_value(rr_em_mi_info_struct *rr_em_mi_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_mi_info.present = rr_em_mi_info->present;
    mmi_rr_em_mi_info.no_of_instance = rr_em_mi_info->no_of_instance;
    mmi_rr_em_mi_info.emr_report = rr_em_mi_info->emr_report;
    mmi_rr_em_mi_info.umts_parameter_exist = rr_em_mi_info->umts_parameter_exist;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_tbf_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_tbf_info_struct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_tbf_info_logs_value(rr_em_tbf_status_struct *rr_em_tbf_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_tbf_info.tbf_mode = rr_em_tbf_info->tbf_mode;
    mmi_rr_em_tbf_info.ul_tbf_status = rr_em_tbf_info->ul_tbf_status;
    mmi_rr_em_tbf_info.ul_rel_cause = rr_em_tbf_info->ul_rel_cause;
    mmi_rr_em_tbf_info.ul_ts_allocation = rr_em_tbf_info->ul_ts_allocation;
    mmi_rr_em_tbf_info.ul_rlc_mode = rr_em_tbf_info->ul_rlc_mode;
    mmi_rr_em_tbf_info.ul_mac_mode = rr_em_tbf_info->ul_mac_mode;
    mmi_rr_em_tbf_info.number_rlc_octect = rr_em_tbf_info->number_rlc_octect;
    mmi_rr_em_tbf_info.ul_tfi = rr_em_tbf_info->ul_tfi;
    mmi_rr_em_tbf_info.ul_granularity = rr_em_tbf_info->ul_granularity;
    mmi_rr_em_tbf_info.ul_usf = rr_em_tbf_info->ul_usf;
    mmi_rr_em_tbf_info.ul_tai = rr_em_tbf_info->ul_tai;
    mmi_rr_em_tbf_info.ul_tqi = rr_em_tbf_info->ul_tqi;
    mmi_rr_em_tbf_info.ul_window_size = rr_em_tbf_info->ul_window_size;
    mmi_rr_em_tbf_info.dl_tbf_status = rr_em_tbf_info->dl_tbf_status;
    mmi_rr_em_tbf_info.dl_rel_cause = rr_em_tbf_info->dl_rel_cause;
    mmi_rr_em_tbf_info.dl_ts_allocation = rr_em_tbf_info->dl_ts_allocation;
    mmi_rr_em_tbf_info.dl_rlc_mode = rr_em_tbf_info->dl_rlc_mode;
    mmi_rr_em_tbf_info.dl_mac_mode = rr_em_tbf_info->dl_mac_mode;    
    mmi_rr_em_tbf_info.dl_tfi = rr_em_tbf_info->dl_tfi;    
    mmi_rr_em_tbf_info.dl_tai = rr_em_tbf_info->dl_tai;        
    mmi_rr_em_tbf_info.dl_window_size = rr_em_tbf_info->dl_window_size;        
#ifdef __EGPRS_MODE__	
    mmi_rr_em_tbf_info.dl_out_of_memory = rr_em_tbf_info->dl_out_of_memory;        
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_blk_info_logs_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rr_em_blk_info_struct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_rr_blk_info_logs_value(rr_em_blk_info_struct *rr_em_blk_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rr_em_blk_info.ul_coding_scheme = rr_em_blk_info->ul_coding_scheme;
    mmi_rr_em_blk_info.ul_cv = rr_em_blk_info->ul_cv;
    mmi_rr_em_blk_info.ul_tlli = rr_em_blk_info->ul_tlli;
    mmi_rr_em_blk_info.ul_bsn1 = rr_em_blk_info->ul_bsn1;
#ifdef __EGPRS_MODE__	    
    mmi_rr_em_blk_info.ul_bsn2 = rr_em_blk_info->ul_bsn2;
    mmi_rr_em_blk_info.ul_cps = rr_em_blk_info->ul_cps;
    mmi_rr_em_blk_info.ul_rsb = rr_em_blk_info->ul_rsb;
    mmi_rr_em_blk_info.ul_spb = rr_em_blk_info->ul_spb;
#endif    
    mmi_rr_em_blk_info.dl_c_value_in_rx_level = rr_em_blk_info->dl_c_value_in_rx_level;
    mmi_rr_em_blk_info.dl_rxqual = rr_em_blk_info->dl_rxqual;
    mmi_rr_em_blk_info.dl_sign_var = rr_em_blk_info->dl_sign_var;
    mmi_rr_em_blk_info.dl_coding_scheme = rr_em_blk_info->dl_coding_scheme;

    mmi_rr_em_blk_info.dl_fbi = rr_em_blk_info->dl_fbi;
    mmi_rr_em_blk_info.dl_bsn1 = rr_em_blk_info->dl_bsn1;
#ifdef __EGPRS_MODE__	    
    mmi_rr_em_blk_info.dl_bsn2 = rr_em_blk_info->dl_bsn2;
    mmi_rr_em_blk_info.dl_cps = rr_em_blk_info->dl_cps;    
    mmi_rr_em_blk_info.dl_gmsk_mean_bep_lev = rr_em_blk_info->dl_gmsk_mean_bep_lev;    
    mmi_rr_em_blk_info.dl_8psk_mean_bep_lev = rr_em_blk_info->dl_8psk_mean_bep_lev;    
    for (i=0; i<8; i++)
        mmi_rr_em_blk_info.dl_tn_mean_bep_lev[i] = rr_em_blk_info->dl_tn_mean_bep_lev[i];    
#endif
    for (i=0; i<8; i++)
        mmi_rr_em_blk_info.dl_tn_interference_lev[i] = rr_em_blk_info->dl_tn_interference_lev[i];        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_display_screen_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_display_screen_n(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 text_pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_em_display_screen_n=%d", screen_num);

    MMI_ASSERT(screen_num < MAX_TRACER_SCREEN_NUM);

    gui_lock_double_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    mmi_em_tracer_screen_color_init(255, 255, 255);

    mmi_show_screen_text_log(screen_num);

    for (i = 0; i < MAX_TRACER_LINE_NUM; i++)
    {
        if (mmi_screen_text[i][0] == '\0')
        {
            break;
        }
        mmi_em_display_line_n(&text_pos, mmi_screen_text[i]);
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1);

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_tracer_screen_color_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_r     [IN]        
 *  color_g     [IN]        
 *  color_b     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_tracer_screen_color_init(kal_uint8 color_r, kal_uint8 color_g, kal_uint8 color_b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute debug_print_font = {0, 0, 0, SMALL_FONT, 0, 0};
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = gui_color(color_r, color_g, color_b);

    UI_fill_rectangle(
        0,
        0,
        //MMI_STATUS_BAR_HEIGHT,
        MAIN_LCD_device_width-1,
        MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT,
        c);

    UI_set_font(&debug_print_font);
    c = gui_color(0, 0, 0);
    UI_set_text_color(c);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_show_screen_text_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_number       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_show_screen_text_log(int screen_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 screen_num_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (screen_number)
    {
        case 0:
            screen_num_id = mmi_em_rr_measurement_report_info_logs((kal_uint8) screen_number, &mmi_rr_em_measurement_report_info);
            break;
        case 1:
            screen_num_id = mmi_em_rr_measurement_report_info_logs_2((kal_uint8) screen_number, &mmi_rr_em_measurement_report_info);
            break;
        case 2:
            screen_num_id = mmi_em_rr_cell_select_logs((kal_uint8) screen_number, &mmi_rr_em_cell_select_para_info);
            break;
        case 3:
            screen_num_id = mmi_em_rr_channel_descr_logs((kal_uint8) screen_number, &mmi_rr_em_channel_descr_info);
            break;
        case 4:
            screen_num_id = mmi_em_rr_ctrl_channel_descr_logs((kal_uint8) screen_number, &mmi_rr_em_ctrl_channel_descr_info);
            break;
        case 5:
            screen_num_id = mmi_em_rr_rach_ctrl_para_info_logs((kal_uint8) screen_number, &mmi_rr_em_rach_ctrl_para_info);
            break;
        case 6:
            screen_num_id = mmi_em_rr_lai_info_logs((kal_uint8) screen_number, &mmi_rr_em_lai_info);
            break;
        case 7:
            screen_num_id = mmi_em_rr_radio_link_counter_info_logs((kal_uint8) screen_number, &mmi_rr_em_radio_link_counter_info);
            break;
        case 8:
            screen_num_id = mmi_em_rr_c1_c2_logs((kal_uint8) screen_number, &mmi_rr_em_measurement_report_info);
            break;
        case 9:
            screen_num_id = mmi_em_rr_c1_c2_logs_2((kal_uint8) screen_number, &mmi_rr_em_measurement_report_info);
            break;
        case 10:
            screen_num_id = mmi_em_rr_plmn_info_logs((kal_uint8) screen_number);
            break;
        case 11:
            screen_num_id = mmi_em_rr_gprs_general_info_logs((kal_uint8) screen_number);
            break;
        case 12:
            screen_num_id = mmi_em_rr_si2q_mi_info_logs((kal_uint8) screen_number);
            break;
        case 13:
            screen_num_id = mmi_em_rr_tbf_info_logs((kal_uint8) screen_number);
            break;
        case 14:
            screen_num_id = mmi_em_rr_blk_info_logs((kal_uint8) screen_number);
            break;
        default:
            break;
    }
    return screen_num_id;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_display_line_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_pos        [?]     
 *  str             [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_display_line_n(kal_int32 *text_pos, kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 temp_str[200];
    kal_uint16 alignment_width = 0, alignment_height = 0;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2((S8*) temp_str, (S8*) str, sizeof(temp_str) / 2 - 1);
    Get_StringWidthHeight((U8*) temp_str, (S32*) & alignment_width, (S32*) & alignment_height);

    gui_set_font(&MMI_small_font);

    gui_measure_string((UI_string_type) temp_str, &width, &height);

    if ((*text_pos+height) < (MAIN_LCD_device_height - MMI_BUTTON_BAR_HEIGHT-1) )
    {
        gui_move_text_cursor(0, *text_pos);
        *text_pos += height;
        gui_print_text((UI_string_type) temp_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_measurement_report_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 *  rr_em_measurement_report_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_measurement_report_info_logs(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page one */
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Measure Rep", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_MEASUREMENT_REPORT_INFO) && (rr_em_measurement_report_info->is_present != 0))
    {
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<SERV_ARFCN>",
            rr_em_measurement_report_info->serving_arfcn);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<RSSI>",
            rr_em_measurement_report_info->serv_rla_in_quarter_dbm);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<BSIC>", rr_em_measurement_report_info->serving_bsic);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<C1_SERV_CELL>",
            rr_em_measurement_report_info->c1_serv_cell);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<C2_SERV_CELL>",
            rr_em_measurement_report_info->c2_serv_cell);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_10,
            "<C31>",
            "X" /* reserved rr_em_measurement_report_info->c31 */ );
#ifdef __AMR_SUPPORT__
        if (rr_em_measurement_report_info->amr_info_valid != FALSE)
        {
            U8 k=0, j=0, value=0;
            S8 buf[40]= {'\0'};
            S8 buf_temp[10] = {'\0'};
            U8 acs_index[4];

            for (k=0; k< 4; k++)
                acs_index[k] = 15;   /* init string : X */
                            
            /* acs info */
            for (k=16; k>0; k--)
            {
                if (EM_IS_SET(rr_em_measurement_report_info->acs, k-1))
                {
                    if (j<4)
                    {
                        acs_index[j] = k-1;
                        j++;
                    }
                }
            }

            sprintf((char*)buf, "%s,%s,%s,%s", amr_info_bitwise_name[acs_index[0]], amr_info_bitwise_name[acs_index[1]],
                                                  amr_info_bitwise_name[acs_index[2]], amr_info_bitwise_name[acs_index[3]]);
            
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_12, "<acs>", buf);
            buf[0]= 0 ;
        
            /* icm info */
            for (k=16; k>0; k--)
            {
                if (EM_IS_SET(rr_em_measurement_report_info->icm, k-1))
                {
                    sprintf((char*)buf,"%s, ", amr_info_bitwise_name[k-1]);
                }
            }
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_12, "<icm>", buf);

            /* cmr info */
            value  = (U8)(rr_em_measurement_report_info->cmr_cmc_cmiu_cmid>>6);
            if (value<4)
                sprintf((char*)buf_temp, TEXT_FORMAT_12, "<cmr>", amr_info_bitwise_name[acs_index[value]]);
            sprintf((char*)buf, "%s", buf_temp);
            buf_temp[0]= 0 ;
                
            /* cmc info */
            value  = (U8)((rr_em_measurement_report_info->cmr_cmc_cmiu_cmid&0x30)>>4);
            if (value<4)
                sprintf((char*)buf_temp, TEXT_FORMAT_12, "<cmc>", amr_info_bitwise_name[acs_index[value]]);
            sprintf((char*)buf, "%s %s", buf, buf_temp);
            buf_temp[0]= 0 ;
                
            sprintf((char*)mmi_screen_text[i++], "%s", buf);
            buf[0]= 0 ;
                
            /* cmiu info */
            value  = (U8)((rr_em_measurement_report_info->cmr_cmc_cmiu_cmid&0x0C)>>2);
            if (value<4)
                sprintf((char*)buf_temp, TEXT_FORMAT_12, "<cmiu>", amr_info_bitwise_name[acs_index[value]]);
            sprintf((char*)buf, "%s", buf_temp);
            buf_temp[0]= 0 ;
                
            /* cmid info */
            value  = (U8)(rr_em_measurement_report_info->cmr_cmc_cmiu_cmid&0x03);
            if (value<4)
                sprintf((char*)buf_temp, TEXT_FORMAT_12, "<cmid>", amr_info_bitwise_name[acs_index[value]]);
            sprintf((char*)buf, "%s %s", buf, buf_temp);
            buf_temp[0]= 0 ;
                
            sprintf((char*)mmi_screen_text[i++], "%s", buf);
            buf[0]= 0 ;
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<c_i>",rr_em_measurement_report_info->c_i );
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<acs>", NA_SYMBOL );
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<icm>", NA_SYMBOL );
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<cmr_c_iu_id>", NA_SYMBOL );
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<c_i>", NA_SYMBOL );
        }
#endif /* #ifdef __AMR_SUPPORT__ */        
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<G_SUP>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<PBCCH>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<NUM_CARRIERS>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<RR_STATE>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MULTIBAND>", NA_SYMBOL);
#ifdef __AMR_SUPPORT__        
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<acs>", NA_SYMBOL );
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<icm>", NA_SYMBOL );        
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<cmr_c_iu_id>", NA_SYMBOL );
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<c_i>", NA_SYMBOL );
#endif        
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_measurement_report_info_logs_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 *  rr_em_measurement_report_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_measurement_report_info_logs_2(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page two */
    MMI_ASSERT(screen_num < MAX_TRACER_SCREEN_NUM);
    i = 0;
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Measure Rep", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_MEASUREMENT_REPORT_INFO) && (rr_em_measurement_report_info->is_present != 0))
    {
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<G_SUP>",
            rr_em_measurement_report_info->serv_gprs_supported);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<PBCCH>",
            rr_em_measurement_report_info->gprs_pbcch_present);
        num_of_carriers = rr_em_measurement_report_info->num_of_carriers;
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<NUM_CARRIERS>",
            rr_em_measurement_report_info->num_of_carriers);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<RR_STATE>", rr_em_measurement_report_info->rr_state);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<MULTIBAND>",
            rr_em_measurement_report_info->multiband_report);

        if (rr_em_measurement_report_info->timing_advance != 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<Timing_adv>",rr_em_measurement_report_info->timing_advance);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<Timing_adv>", NA_SYMBOL);
        }
        
        if (rr_em_measurement_report_info->timing_advance != 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<Rxqual_sub>",rr_em_measurement_report_info->rxqual_sub);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<Rxqual_sub>", NA_SYMBOL);
        }

        if (rr_em_measurement_report_info->timing_advance != 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<Rxqual_full>",rr_em_measurement_report_info->rxqual_full);        
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<Rxqual_full>", NA_SYMBOL);
        }
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<G_SUP>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<PBCCH>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<NUM_CARRIERS>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<RR_STATE>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MULTIBAND>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<Timing_adv>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<Rxqual_sub>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<Rxqual_full>", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_cell_select_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                      [IN]        
 *  rr_em_cell_select_para_info     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_cell_select_logs(
            kal_uint8 screen_num,
            mmi_rr_em_cell_select_para_info_t *rr_em_cell_select_para_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Cell Selection", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_CELL_SELECT_PARA_INFO) && (rr_em_cell_select_para_info->is_present != 0))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<CRH>", rr_em_cell_select_para_info->crh);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<MS_TXPWR>", rr_em_cell_select_para_info->ms_txpwr);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<RX_ACC_MIN>",
            rr_em_cell_select_para_info->rxlev_access_min);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CRH>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MS_TXPWR>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<RX_ACC_MIN>", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_channel_descr_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                      [IN]        
 *  rr_em_channel_descr_info        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_channel_descr_logs(kal_uint8 screen_num, mmi_rr_em_channel_descr_info_t *rr_em_channel_descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Channel Descr", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    if ((receive_last_info & MMI_EM_CHANNEL_DESCR_INFO) && (rr_em_channel_descr_info->is_present != 0))
    {
        if (rr_em_channel_descr_info->channel_type < MAX_CHANNEL_TYPE_COUNT)
        {
            sprintf(
                (char*)mmi_screen_text[i++],
                TEXT_FORMAT_12,
                "CH_TYPE",
                rr_channel_type_name[rr_em_channel_descr_info->channel_type]);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "CH_TYPE", rr_em_channel_descr_info->channel_type);
        }

        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_14,
            "HOPPING",
            rr_em_channel_descr_info->hopping_flag,
            "MAIO",
            rr_em_channel_descr_info->maio);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_16,
            "HSN",
            rr_em_channel_descr_info->hsn,
            "TN",
            rr_em_channel_descr_info->tn,
            "TSC",
            rr_em_channel_descr_info->tsc);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "MA_NUMBER", rr_em_channel_descr_info->num_of_carriers);

    #ifdef __AMR_SUPPORT__
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "AMR_VALID", rr_em_channel_descr_info->amr_valid);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "FRAME_NUMBER", rr_em_channel_descr_info->frame_number);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_14,
            "CMI_PHASE",
            rr_em_channel_descr_info->cmip,
            "NSCB",
            rr_em_channel_descr_info->nscb);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_14,
            "MR_VER",
            rr_em_channel_descr_info->mr_ver,
            "ICMI",
            rr_em_channel_descr_info->icmi);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "START_CODEC", rr_em_channel_descr_info->start_codec_mode);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_1,
            "THRESHOLD",
            rr_em_channel_descr_info->threshold[0],
            rr_em_channel_descr_info->threshold[1],
            rr_em_channel_descr_info->threshold[2]);

        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_1,
            "HYSTERESIS",
            rr_em_channel_descr_info->hysteresis[0],
            rr_em_channel_descr_info->hysteresis[1],
            rr_em_channel_descr_info->hysteresis[2]);
    #endif /* __AMR_SUPPORT__ */ 

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_12, "Cipher_algo", rr_cipher_algo_name[rr_em_channel_descr_info->cipher_algo]);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "CH_TYPE", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "HOPPING", NA_SYMBOL, "MAIO", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "HSN", NA_SYMBOL, "TN", NA_SYMBOL, "TSC", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "MA_NUMBER", NA_SYMBOL);

    #ifdef __AMR_SUPPORT__
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "AMR_VALID", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "FRAME_NUMBER", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "CMI_PHASE", NA_SYMBOL, "NSCB", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "START_CODEC", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "THRESHOLD", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "HYSTERESIS", NA_SYMBOL);
    #endif /* __AMR_SUPPORT__ */ 

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "Cipher_algo", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_ctrl_channel_descr_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 *  rr_em_ctrl_channel_descr_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_ctrl_channel_descr_logs(
            kal_uint8 screen_num,
            mmi_rr_em_ctrl_channel_descr_info_t *rr_em_ctrl_channel_descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(screen_num < MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Ctrl Channel", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_CTRL_CHANNEL_DESCR_INFO) && (rr_em_ctrl_channel_descr_info->is_present != 0))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<MSCR>", rr_em_ctrl_channel_descr_info->mscr);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<ATT>", rr_em_ctrl_channel_descr_info->att);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<CCCH_CONF>", rr_em_ctrl_channel_descr_info->ccch_conf);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<MFRMS>", rr_em_ctrl_channel_descr_info->bs_pa_mfrms);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<BS_AG_BLKS>",
            rr_em_ctrl_channel_descr_info->bs_ag_blks_res);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<CBQ2>", rr_em_ctrl_channel_descr_info->cbq2);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<T3212>", rr_em_ctrl_channel_descr_info->t3212);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MSCR>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<ATT>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CCCH_CONF>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MFRMS>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<BS_AG_BLKS>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CBQ2>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<T3212>", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_rach_ctrl_para_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                      [IN]        
 *  rr_em_rach_ctrl_para_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_rach_ctrl_para_info_logs(
            kal_uint8 screen_num,
            mmi_rr_em_rach_ctrl_para_info_t *rr_em_rach_ctrl_para_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0 , j = 0;
    kal_uint8 str_buf[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "RACH Ctrl", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_RACH_CTRL_PARA_INFO) && (rr_em_rach_ctrl_para_info->is_present != 0))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<MAX RETRANS>", rr_em_rach_ctrl_para_info->max_retrans);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<CBA>", rr_em_rach_ctrl_para_info->cba);
        sprintf((char*)mmi_screen_text[i++], "<ACC_Class>:");

        /* Bit 15 - Bit 8 */
        j = rr_em_rach_ctrl_para_info->acc_class[1];
        sprintf((char*)str_buf, TEXT_FORMAT_18, EM_IS_SET(j,7), EM_IS_SET(j,6), EM_IS_SET(j,5), EM_IS_SET(j,4), EM_IS_SET(j,3), EM_IS_SET(j,2), EM_IS_SET(j,1), EM_IS_SET(j,0));
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, str_buf);

        /* Bit 7 - Bit 0 */
        j = rr_em_rach_ctrl_para_info->acc_class[0];
        str_buf[0]=0;
        sprintf((char*)str_buf, TEXT_FORMAT_18, EM_IS_SET(j,7), EM_IS_SET(j,6), EM_IS_SET(j,5), EM_IS_SET(j,4), EM_IS_SET(j,3), EM_IS_SET(j,2), EM_IS_SET(j,1), EM_IS_SET(j,0));
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, str_buf);

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<CB_support>", rr_em_rach_ctrl_para_info->CB_supported);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<TX_INTEGER>", rr_em_rach_ctrl_para_info->tx_integer);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<RE_EST>", rr_em_rach_ctrl_para_info->re);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MAX RETRANS>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CBA>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<ACC_Class>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<TX_INTEGER>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<RE_EST>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CB_support>", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_lai_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num          [IN]        
 *  rr_em_lai_info      [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_lai_info_logs(kal_uint8 screen_num, mmi_rr_em_lai_info_t *rr_em_lai_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "LAI", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_LAI_INFO) && (rr_em_lai_info->is_present != 0))
    {
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_1,
            "<MCC>",
            rr_em_lai_info->mcc[0],
            rr_em_lai_info->mcc[1],
            rr_em_lai_info->mcc[2]);
        if (rr_em_lai_info->mnc[2] != 0x0f)
        {
            sprintf(
                (char*)mmi_screen_text[i++],
                TEXT_FORMAT_1,
                "<MNC>",
                rr_em_lai_info->mnc[0],
                rr_em_lai_info->mnc[1],
                rr_em_lai_info->mnc[2]);
        }
        else
        {
            sprintf(
                (char*)mmi_screen_text[i++],
                TEXT_FORMAT_5,
                "<MNC>",
                rr_em_lai_info->mnc[0],
                rr_em_lai_info->mnc[1],
                "F");
        }
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_4, "<LAC>", rr_em_lai_info->lac[0], rr_em_lai_info->lac[1]);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<CELL_ID>", rr_em_lai_info->cell_id);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MCC>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MNC>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<LAC>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CELL_ID>", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_radio_link_counter_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 *  rr_em_radio_link_counter_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_radio_link_counter_info_logs(
            kal_uint8 screen_num,
            mmi_rr_em_radio_link_counter_info_t *rr_em_radio_link_counter_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "DSC/RLC Cnt", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");

    if (rr_em_radio_link_counter_info->is_dsf)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, rr_downlink_signal_fail_name[0]);    
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_19, rr_downlink_signal_fail_name[1]);    
    }

    if ((receive_last_info & MMI_EM_RADIO_LINK_COUNTER_INFO) && (rr_em_radio_link_counter_info->is_present != 0))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<MAX_VALUE>", rr_em_radio_link_counter_info->max_value);
        sprintf(
            (char*)mmi_screen_text[i++],
            TEXT_FORMAT_2,
            "<CUR_VALUE>",
            rr_em_radio_link_counter_info->current_value);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<DTX_IND>", rr_em_radio_link_counter_info->dtx_ind);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<DTX_USED>", rr_em_radio_link_counter_info->dtx_used);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<MAX_VALUE>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<CUR_VALUE>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<DTX_IND>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<DTX_USED>", NA_SYMBOL);
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_c1_c2_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 *  rr_em_measurement_report_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_c1_c2_logs(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Nebr/Srv Cell", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_MEASUREMENT_REPORT_INFO) && (rr_em_measurement_report_info->is_present != 0))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_7, "arfcn", "rssi", "c1", "c2", "G");
        for (j = 0; j < 6; j++)
        {
            if (((rr_em_measurement_report_info->nc_info_status[j] & 0x03) == 0x03) &&
                (rr_em_measurement_report_info->c1[j] != -1) && (rr_em_measurement_report_info->c2[j] != -1))
            {
                sprintf(
                    (char*)mmi_screen_text[i++],
                    TEXT_FORMAT_8,
                    rr_em_measurement_report_info->nc_arfcn[j],
                    rr_em_measurement_report_info->rla_in_quarter_dbm[j],
                    rr_em_measurement_report_info->c1[j],
                    rr_em_measurement_report_info->c2[j],
                    (rr_em_measurement_report_info->nc_info_status[j] & 0x04 ? 1 : 0));
            }
            else
            {
                sprintf(
                    (char*)mmi_screen_text[i++],
                    TEXT_FORMAT_11,
                    rr_em_measurement_report_info->nc_arfcn[j],
                    rr_em_measurement_report_info->rla_in_quarter_dbm[j],
                    " X ",
                    " X ",
                    0);
            }
        }
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_7, "arfcn", "rssi", "c1", "c2", "G");
        for (j = 0; j < 6; j++)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_13, " X ", " X ", " X ", " X ", " X ");
        }
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_c1_c2_logs_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 *  rr_em_measurement_report_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_c1_c2_logs_2(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* page two */

    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Nebr/Srv Cell", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if ((receive_last_info & MMI_EM_MEASUREMENT_REPORT_INFO) && (rr_em_measurement_report_info->is_present != 0))
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_7, "arfcn", "rssi", "c1", "c2", "G");
        for (j = 6; j < 12; j++)
        {
            if (((rr_em_measurement_report_info->nc_info_status[j] & 0x03) == 0x03) &&
                (rr_em_measurement_report_info->c1[j] != -1) && (rr_em_measurement_report_info->c2[j] != -1))
            {
                sprintf(
                    (char*)mmi_screen_text[i++],
                    TEXT_FORMAT_8,
                    rr_em_measurement_report_info->nc_arfcn[j],
                    rr_em_measurement_report_info->rla_in_quarter_dbm[j],
                    rr_em_measurement_report_info->c1[j],
                    rr_em_measurement_report_info->c2[j],
                    (rr_em_measurement_report_info->nc_info_status[j] & 0x04 ? 1 : 0));
            }
            else
            {
                sprintf(
                    (char*)mmi_screen_text[i++],
                    TEXT_FORMAT_11,
                    rr_em_measurement_report_info->nc_arfcn[j],
                    rr_em_measurement_report_info->rla_in_quarter_dbm[j],
                    " X ",
                    " X ",
                    0);
            }
        }
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_7, "arfcn", "rssi", "c1", "c2", "G");
        for (j = 0; j < 6; j++)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_13, " X ", " X ", " X ", " X ", " X ");
        }
    }
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_plmn_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_plmn_info_logs(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0 , j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "PLMN Info", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if (receive_last_info & MMI_EM_PLMN_INFO_STRUCT_INFO)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<HP_PLMN_SRCH>", mmi_rr_em_plmn_info.is_higher_pri_plmn_srch);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_20, "<HP_PS_TIMER>", mmi_rr_em_plmn_info.hp_count_down_timer , mmi_rr_em_plmn_info.hp_timeout_timer);

        /* RPLMN */
        if (mmi_rr_em_plmn_info.rplmn[0] == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<RPLMN>", NA_SYMBOL);    
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_25, "<RPLMN>",
                    mmi_rr_em_plmn_info.rplmn[0], mmi_rr_em_plmn_info.rplmn[1], 
                    mmi_rr_em_plmn_info.rplmn[2], mmi_rr_em_plmn_info.rplmn[3], 
                    mmi_rr_em_plmn_info.rplmn[4], mmi_rr_em_plmn_info.rplmn[5]); 
        }
                
        /* EQ_PLMN1 - EQ_PLMN4 */
        for (j=0;j<4;j+=2)
        {
            if (mmi_rr_em_plmn_info.eq_plmn[j][0] == 0xff && mmi_rr_em_plmn_info.eq_plmn[j+1][0] == 0xff)
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<EPLMN>", NA_SYMBOL, NA_SYMBOL);
            }
            else if (mmi_rr_em_plmn_info.eq_plmn[j][0] == 0xff)
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_22, "<EPLMN>", NA_SYMBOL, 
                        mmi_rr_em_plmn_info.eq_plmn[j+1][0], mmi_rr_em_plmn_info.eq_plmn[j+1][1], 
                        mmi_rr_em_plmn_info.eq_plmn[j+1][2], mmi_rr_em_plmn_info.eq_plmn[j+1][3], 
                        mmi_rr_em_plmn_info.eq_plmn[j+1][4], mmi_rr_em_plmn_info.eq_plmn[j+1][5]); 
            }
            else if (mmi_rr_em_plmn_info.eq_plmn[j+1][0] == 0xff)
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_23, "<EPLMN>",
                        mmi_rr_em_plmn_info.eq_plmn[j][0], mmi_rr_em_plmn_info.eq_plmn[j][1], 
                        mmi_rr_em_plmn_info.eq_plmn[j][2], mmi_rr_em_plmn_info.eq_plmn[j][3], 
                        mmi_rr_em_plmn_info.eq_plmn[j][4], mmi_rr_em_plmn_info.eq_plmn[j][5], NA_SYMBOL); 
            }
            else
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_21, "<EPLMN>", 
                        mmi_rr_em_plmn_info.eq_plmn[j][0], mmi_rr_em_plmn_info.eq_plmn[j][1], 
                        mmi_rr_em_plmn_info.eq_plmn[j][2], mmi_rr_em_plmn_info.eq_plmn[j][3], 
                        mmi_rr_em_plmn_info.eq_plmn[j][4], mmi_rr_em_plmn_info.eq_plmn[j][5],
                        mmi_rr_em_plmn_info.eq_plmn[j+1][0], mmi_rr_em_plmn_info.eq_plmn[j+1][1], 
                        mmi_rr_em_plmn_info.eq_plmn[j+1][2], mmi_rr_em_plmn_info.eq_plmn[j+1][3], 
                        mmi_rr_em_plmn_info.eq_plmn[j+1][4], mmi_rr_em_plmn_info.eq_plmn[j+1][5]); 
            }
        }            

        /* EQ_PLMN5 */
        if (mmi_rr_em_plmn_info.eq_plmn[4][0] == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<EPLMN>", NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_23, "<EPLMN>", 
                    mmi_rr_em_plmn_info.eq_plmn[4][0], mmi_rr_em_plmn_info.eq_plmn[4][1], 
                    mmi_rr_em_plmn_info.eq_plmn[4][2], mmi_rr_em_plmn_info.eq_plmn[4][3], 
                    mmi_rr_em_plmn_info.eq_plmn[4][4], mmi_rr_em_plmn_info.eq_plmn[4][5], NA_SYMBOL);
        }
        /* FPLMN1 - FPLMN4 */
        for (j=0;j<4;j+=2)
        {
            if (mmi_rr_em_plmn_info.forbid_plmn[j][0] == 0xff && mmi_rr_em_plmn_info.forbid_plmn[j+1][0] == 0xff)
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<FPLMN>", NA_SYMBOL, NA_SYMBOL);
            }
            else if (mmi_rr_em_plmn_info.forbid_plmn[j][0] == 0xff)
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_22, "<FPLMN>", NA_SYMBOL, 
                        mmi_rr_em_plmn_info.forbid_plmn[j+1][0], mmi_rr_em_plmn_info.forbid_plmn[j+1][1], 
                        mmi_rr_em_plmn_info.forbid_plmn[j+1][2], mmi_rr_em_plmn_info.forbid_plmn[j+1][3], 
                        mmi_rr_em_plmn_info.forbid_plmn[j+1][4], mmi_rr_em_plmn_info.forbid_plmn[j+1][5]); 
            }
            else if (mmi_rr_em_plmn_info.forbid_plmn[j+1][0] == 0xff)
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_23, "<FPLMN>",
                        mmi_rr_em_plmn_info.forbid_plmn[j][0], mmi_rr_em_plmn_info.forbid_plmn[j][1], 
                        mmi_rr_em_plmn_info.forbid_plmn[j][2], mmi_rr_em_plmn_info.forbid_plmn[j][3], 
                        mmi_rr_em_plmn_info.forbid_plmn[j][4], mmi_rr_em_plmn_info.forbid_plmn[j][5], NA_SYMBOL); 
            }
            else
            {
                sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_21, "<FPLMN>", 
                        mmi_rr_em_plmn_info.forbid_plmn[j][0], mmi_rr_em_plmn_info.forbid_plmn[j][1], 
                        mmi_rr_em_plmn_info.forbid_plmn[j][2], mmi_rr_em_plmn_info.forbid_plmn[j][3], 
                        mmi_rr_em_plmn_info.forbid_plmn[j][4], mmi_rr_em_plmn_info.forbid_plmn[j][5],
                        mmi_rr_em_plmn_info.forbid_plmn[j+1][0], mmi_rr_em_plmn_info.forbid_plmn[j+1][1], 
                        mmi_rr_em_plmn_info.forbid_plmn[j+1][2], mmi_rr_em_plmn_info.forbid_plmn[j+1][3], 
                        mmi_rr_em_plmn_info.forbid_plmn[j+1][4], mmi_rr_em_plmn_info.forbid_plmn[j+1][5]); 
            }
        }            
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<HP_PLMN_SRCH>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<HP_PS_TIMER>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<RPLMN>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<EPLMN>", NA_SYMBOL, NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<EPLMN>", NA_SYMBOL, NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<EPLMN>", NA_SYMBOL, NA_SYMBOL);        
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<FPLMN>", NA_SYMBOL, NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_24, "<FPLMN>", NA_SYMBOL, NA_SYMBOL);        
    }
    
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_gprs_general_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_gprs_general_info_logs(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "GPRS Info", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    sprintf((char*)mmi_screen_text[i++], "-------------------------");
    if (receive_last_info & MMI_EM_GPRS_GENERAL_INFO)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<GPRS_Support>", mmi_rr_em_gprs_general_info.gprs_support);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<sgsn_r>", mmi_rr_em_gprs_general_info.sgsn_r);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<pfc_support>", mmi_rr_em_gprs_general_info.pfc_support);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<epcr_support>", mmi_rr_em_gprs_general_info.epcr_support);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<bep_period>", mmi_rr_em_gprs_general_info.bep_period);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<egprs_support>", mmi_rr_em_gprs_general_info.egprs_support);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<GPRS_Support>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<sgsn_r>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<pfc_support>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<epcr_support>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<bep_period>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<egprs_support>", NA_SYMBOL);
    }
    
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_si2q_mi_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_si2q_mi_info_logs(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "Si2q/mi Info", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    if (receive_last_info & MMI_EM_SI2Q_MI_INFO_STRUCT_INFO)
    {
        sprintf((char*)mmi_screen_text[i++], "------------Si2q---------");
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<present>", mmi_rr_em_si2q_info.present);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<no_of_instance>", mmi_rr_em_si2q_info.no_of_instance);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<emr_report>", mmi_rr_em_si2q_info.emr_report);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<umts_exist>", mmi_rr_em_si2q_info.umts_parameter_exist);

        sprintf((char*)mmi_screen_text[i++], "-------------mi----------");
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<present>", mmi_rr_em_mi_info.present);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<no_of_instance>", mmi_rr_em_mi_info.no_of_instance);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<emr_report>", mmi_rr_em_mi_info.emr_report);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "<umts_exist>", mmi_rr_em_mi_info.umts_parameter_exist);
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], "------------Si2q---------");    
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<present>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<no_of_instance>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<emr_report>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<umts_exist>", NA_SYMBOL);

        sprintf((char*)mmi_screen_text[i++], "-------------mi----------");
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<present>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<no_of_instance>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<emr_report>", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "<umts_exist>", NA_SYMBOL);
    }
    
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_tbf_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_tbf_info_logs(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "TBF Info", screen_num + 1, MAX_TRACER_SCREEN_NUM);
    if (receive_last_info & MMI_EM_TBF_INFO)
    {
        if ((mmi_rr_em_tbf_info.ul_tbf_status == 0xff) && (mmi_rr_em_tbf_info.dl_tbf_status == 0xff))
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "tbf_mode", NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "tbf_mode", mmi_rr_em_tbf_info.tbf_mode);
        }
            
        if (mmi_rr_em_tbf_info.ul_tbf_status == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], "-------------------------");    
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, "u_stat", NA_SYMBOL, "rel", mmi_rr_em_tbf_info.ul_rel_cause);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "ws", NA_SYMBOL, "ts", NA_SYMBOL, "usf", NA_SYMBOL);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "rlcm", NA_SYMBOL, "macm", NA_SYMBOL);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "tfi", NA_SYMBOL, "tai", NA_SYMBOL);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "oct", NA_SYMBOL,"gra", NA_SYMBOL, "tqi", NA_SYMBOL );
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], "-------------------------");    
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "u_stat" , mmi_rr_em_tbf_info.ul_tbf_status, "rel", mmi_rr_em_tbf_info.ul_rel_cause);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_30, "ws", mmi_rr_em_tbf_info.ul_window_size , "ts" , mmi_rr_em_tbf_info.ul_ts_allocation,  "usf", mmi_rr_em_tbf_info.ul_usf);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "rlcm", mmi_rr_em_tbf_info.ul_rlc_mode, "macm", mmi_rr_em_tbf_info.ul_mac_mode);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "tfi", mmi_rr_em_tbf_info.ul_tfi, "tai", mmi_rr_em_tbf_info.ul_tai);
            //sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_16,  "oct", mmi_rr_em_tbf_info.number_rlc_octect, "gra", mmi_rr_em_tbf_info.ul_granularity, "tqi", mmi_rr_em_tbf_info.ul_tqi);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14,  "oct", mmi_rr_em_tbf_info.number_rlc_octect, "gra", mmi_rr_em_tbf_info.ul_granularity); 
        }
        
        sprintf((char*)mmi_screen_text[i++], "-------------------------");    
        
        if (mmi_rr_em_tbf_info.dl_tbf_status == 0xff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, "d_stat", NA_SYMBOL, "rel", mmi_rr_em_tbf_info.dl_rel_cause);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "ws", NA_SYMBOL, "ts", NA_SYMBOL);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "rlcm", NA_SYMBOL, "macm", NA_SYMBOL);
        #ifdef __EGPRS_MODE__	        
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "tfi", NA_SYMBOL, "tai", NA_SYMBOL, "om", NA_SYMBOL);
        #else
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "tfi", NA_SYMBOL, "tai", NA_SYMBOL);
        #endif
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "d_stat", mmi_rr_em_tbf_info.dl_tbf_status, "rel", mmi_rr_em_tbf_info.dl_rel_cause);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_31, "ws", mmi_rr_em_tbf_info.dl_window_size, "ts", mmi_rr_em_tbf_info.dl_ts_allocation);
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "rlcm", mmi_rr_em_tbf_info.dl_rlc_mode, "macm", mmi_rr_em_tbf_info.dl_mac_mode);        
        #ifdef __EGPRS_MODE__	        
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_16, "tfi", mmi_rr_em_tbf_info.dl_tfi, "tai", mmi_rr_em_tbf_info.dl_tai, "om", mmi_rr_em_tbf_info.dl_out_of_memory);
        #else
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "tfi", mmi_rr_em_tbf_info.dl_tfi, "tai", mmi_rr_em_tbf_info.dl_tai);        
    #endif
    }
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "tbf_mode", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "u_stat", NA_SYMBOL, "rel", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "ws", NA_SYMBOL, "ts", NA_SYMBOL, "usf", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "rlcm", NA_SYMBOL, "macm", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "tfi", NA_SYMBOL, "tai", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "oct", NA_SYMBOL, "gra", NA_SYMBOL, "tqi", NA_SYMBOL);

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "d_stat", NA_SYMBOL , "rel", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "ws", NA_SYMBOL, "ts", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "rlcm", NA_SYMBOL, "macm", NA_SYMBOL);
    #ifdef __EGPRS_MODE__	        
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "tfi", NA_SYMBOL, "tai", NA_SYMBOL, "om", NA_SYMBOL);
    #else
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "tfi", NA_SYMBOL, "tai", NA_SYMBOL);
    #endif
    }
    
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_rr_blk_info_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_num                          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mmi_em_rr_blk_info_logs(kal_uint8 screen_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_9, "BLK Info", screen_num + 1, MAX_TRACER_SCREEN_NUM);
//    sprintf((char*)mmi_screen_text[i++], "-------------------------");    
    if (receive_last_info & MMI_EM_BLK_INFO)
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_16, "UL_cs", mmi_rr_em_blk_info.ul_coding_scheme,"cv", mmi_rr_em_blk_info.ul_cv, "tlli", mmi_rr_em_blk_info.ul_tlli);

#ifdef __EGPRS_MODE__	        
        if (mmi_rr_em_blk_info.ul_bsn1 == 0xffff && mmi_rr_em_blk_info.ul_bsn2 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "bsn1", NA_SYMBOL, "bsn2", NA_SYMBOL);
        }
        else if (mmi_rr_em_blk_info.ul_bsn1 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, "bsn1", NA_SYMBOL, "bsn2",  mmi_rr_em_blk_info.ul_bsn2);
        }
        else if (mmi_rr_em_blk_info.ul_bsn2 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_29, "bsn1", mmi_rr_em_blk_info.ul_bsn1, "bsn2",  NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "bsn1", mmi_rr_em_blk_info.ul_bsn1, "bsn2",  mmi_rr_em_blk_info.ul_bsn2);
        }
#else
        if (mmi_rr_em_blk_info.ul_bsn1 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "bsn1", NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "bsn1", mmi_rr_em_blk_info.ul_bsn1);
        }
#endif /* #ifdef __EGPRS_MODE__	*/       
        
        sprintf((char*)mmi_screen_text[i++], "-------------------------");            

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14,  "DL_cs", mmi_rr_em_blk_info.dl_coding_scheme, "rxq", mmi_rr_em_blk_info.dl_rxqual);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "sigvar", mmi_rr_em_blk_info.dl_sign_var,"cval", mmi_rr_em_blk_info.dl_c_value_in_rx_level );

#ifdef __EGPRS_MODE__	
        if (mmi_rr_em_blk_info.dl_bsn1 == 0xffff && mmi_rr_em_blk_info.dl_bsn2 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "bsn1", NA_SYMBOL, "bsn2", NA_SYMBOL);
        }
        else if (mmi_rr_em_blk_info.dl_bsn1 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_28, "bsn1", NA_SYMBOL, "bsn2",  mmi_rr_em_blk_info.dl_bsn2);
        }
        else if (mmi_rr_em_blk_info.dl_bsn2 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_29, "bsn1", mmi_rr_em_blk_info.dl_bsn1, "bsn2",  NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "bsn1", mmi_rr_em_blk_info.dl_bsn1, "bsn2",  mmi_rr_em_blk_info.dl_bsn2);
        }
#else
        if (mmi_rr_em_blk_info.dl_bsn1 == 0xffff)
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "bsn1", NA_SYMBOL);
        }
        else
        {
            sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_2, "bsn1", mmi_rr_em_blk_info.dl_bsn1);
        }
#endif /* #ifdef __EGPRS_MODE__	*/      

#ifdef __EGPRS_MODE__
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_14, "g_mb", mmi_rr_em_blk_info.dl_gmsk_mean_bep_lev, "8_mb", mmi_rr_em_blk_info.dl_8psk_mean_bep_lev);                
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_mb_1", mmi_rr_em_blk_info.dl_tn_mean_bep_lev[0],mmi_rr_em_blk_info.dl_tn_mean_bep_lev[1], 
                       mmi_rr_em_blk_info.dl_tn_mean_bep_lev[2], mmi_rr_em_blk_info.dl_tn_mean_bep_lev[3]);                        

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_mb_2", mmi_rr_em_blk_info.dl_tn_mean_bep_lev[4],mmi_rr_em_blk_info.dl_tn_mean_bep_lev[5], 
                       mmi_rr_em_blk_info.dl_tn_mean_bep_lev[6], mmi_rr_em_blk_info.dl_tn_mean_bep_lev[7]); 
#endif
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_IL_1", mmi_rr_em_blk_info.dl_tn_interference_lev[0], mmi_rr_em_blk_info.dl_tn_interference_lev[1],
                       mmi_rr_em_blk_info.dl_tn_interference_lev[2], mmi_rr_em_blk_info.dl_tn_interference_lev[3]);

        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_27, "tn_IL_2", mmi_rr_em_blk_info.dl_tn_interference_lev[4], mmi_rr_em_blk_info.dl_tn_interference_lev[5],
                       mmi_rr_em_blk_info.dl_tn_interference_lev[6], mmi_rr_em_blk_info.dl_tn_interference_lev[7]);        
    }
    else
    {
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "u_cs", NA_SYMBOL,"cv", NA_SYMBOL, "tlli", NA_SYMBOL);        
    #ifdef __EGPRS_MODE__
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "bsn1", NA_SYMBOL, "bsn2", NA_SYMBOL);
    #else
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "bsn1", NA_SYMBOL);
    #endif

    #ifdef __EGPRS_MODE__	
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_17, "rsb", NA_SYMBOL, "spb",  NA_SYMBOL, "cps", NA_SYMBOL);
    #endif        
    
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "d_cval", NA_SYMBOL, "rxq", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "sigvar", NA_SYMBOL, "cs", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "bsn1", NA_SYMBOL, "fbi", NA_SYMBOL);

    #ifdef __EGPRS_MODE__	  
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "bsn2", NA_SYMBOL, "cps", NA_SYMBOL);      
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_15, "g_mb", NA_SYMBOL, "8_mb", NA_SYMBOL); 
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "tn_mb_1", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "tn_mb_2", NA_SYMBOL);        
    #endif
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "tn_IL_1", NA_SYMBOL);
        sprintf((char*)mmi_screen_text[i++], TEXT_FORMAT_10, "tn_IL_2", NA_SYMBOL);
    }
    
    mmi_screen_text[i++][0] = '\0';
    MMI_ASSERT(i <= MAX_TRACER_LINE_NUM);

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStatusUpdate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id          [IN]        
 *  info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStatusUpdate(U32 mod_id, U32 info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currentEmCommand == EM_START)
    {
        currentEmMode |= info_req;
    }
    else
    {
        currentEmMode &= ~info_req;
    }

    if (currentEmMode)
    {
        gEmInfoOn = 1;
    }
    else
    {
        gEmInfoOn = 0;
    }

    channel_descr_info.channel_type = DEFAULT_CHANNEL;

    currentEmCommand = EM_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeStatusIndHdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeStatusIndHdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_status_ind_struct *status_ind = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status_ind->em_info)
    {
        case RR_EM_MEASUREMENT_REPORT_INFO:
            kal_mem_cpy(&meas_report_info, status_ind->info, sizeof(rr_em_measurement_report_info_struct));
            break;
        case RR_EM_RADIO_LINK_COUNTER_INFO:
            kal_mem_cpy(&radio_link_counter_info, status_ind->info, sizeof(rr_em_radio_link_counter_info_struct));
            break;
        case RR_EM_CHANNEL_DESCR_INFO:
            kal_mem_cpy(&channel_descr_info, status_ind->info, sizeof(rr_em_channel_descr_info_struct));
            break;
        case RR_EM_CONTROL_MSG_INFO:
            kal_mem_cpy(&control_msg_info, status_ind->info, sizeof(rr_em_control_msg_info_struct));
            break;
        case MMRR_EM_PLMN_INFO_STRUCT_INFO:
        {
            mmrr_plmn_info_struct *data_ptr;
            kal_uint16 mm_pdu_len;
            /* Get the pdu_ptr where MM peer msg will be stored for transmission */
            data_ptr = (mmrr_plmn_info_struct*) get_pdu_ptr(status_ind->info, &mm_pdu_len);
            mmi_em_rr_plmn_info_logs_value((mmrr_plmn_info_struct*) data_ptr);
            break;
        }
    }
}


#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)    
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */


/*****************************************************************************
 * FUNCTION
 *  EntryEmNWCellLockMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmNWCellLockMenu_Ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8* guiBuffer;
    U16 ImageList[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_NETWORK_CELL_LOCK_MENU_SCR, ExitEmNWCellLockInlineScr, EntryEmNWCellLockMenu_Ext, NULL);
    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_CELL_LOCK_MENU_SCR);
    RegisterHighlightHandler(HighlightHdlrEmCellLockInline);

    /* Cell Lock */
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*)GetString(EM_NETWORK_CELL_LOCK_TEXT));
    ImageList[0] = IMG_STATUS;

    g_em_nw_cell_lock_cntx.pEMEmNWCellLock[0] = (U8*)GetString(STR_GLOBAL_OFF);
    g_em_nw_cell_lock_cntx.pEMEmNWCellLock[1] = (U8*)GetString(STR_GLOBAL_ON);
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[1], 2, (U8**)g_em_nw_cell_lock_cntx.pEMEmNWCellLock, &g_em_nw_cell_lock_cntx.currCellLock);    
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[1],HighlightHandlerNWCellLockEnableInline);
    ImageList[1] = 0;

    /* 1900 Band */
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*)GetString(EM_NETWORK_1900_BAND_TEXT));
    ImageList[2] = IMG_STATUS;

    g_em_nw_cell_lock_cntx.pEMEmNW1900Band[0] = (U8*)GetString(STR_GLOBAL_DEACTIVATE);
    g_em_nw_cell_lock_cntx.pEMEmNW1900Band[1] = (U8*)GetString(STR_GLOBAL_ACTIVATE);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[3], 2, (U8**)g_em_nw_cell_lock_cntx.pEMEmNW1900Band, &g_em_nw_cell_lock_cntx.curr1900Band);    
    ImageList[3] = 0;
       

    /* Arfcn */
    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (U8*)GetString(EM_NETWORK_ARFCN_TEXT));
    ImageList[4] = IMG_STATUS;
       
    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(&wgui_inline_items[5], (PU8)g_em_nw_cell_lock_cntx.arfcn, 5, INPUT_TYPE_NUMERIC);
    ImageList[5] = 0;
    
    DisableCategory57ScreenDone();
     	
    ShowCategory57Screen(EM_NETWORK_CELL_LOCK_TEXT, 0, 
                         STR_GLOBAL_OK, 
                         IMG_GLOBAL_OK, 
                         STR_GLOBAL_BACK, 
                         IMG_GLOBAL_BACK,
 	                     6, ImageList, wgui_inline_items, 0, guiBuffer);	
      
    SetCategory57RightSoftkeyFunctions( GoBackHistory, GoBackHistory );

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmNWCellLockMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmNWCellLockMenu(MMI_BOOL on_off, MMI_BOOL band_onoff, U16 arfcn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[20];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_em_nw_cell_lock_cntx.currCellLock = on_off;
    g_em_nw_cell_lock_cntx.curr1900Band = band_onoff;

    sprintf(buffer,"%d", arfcn);
    mmi_asc_to_ucs2((PS8)g_em_nw_cell_lock_cntx.arfcn, buffer);

    EntryEmNWCellLockMenu_Ext();
}


/**************************************************************

	FUNCTION NAME		: HighlightHdlrEmCellLockInline()

  	PURPOSE				: Cell Lock inline highlight handler

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void HighlightHdlrEmCellLockInline(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EmSetNWCellLock, KEY_EVENT_UP);
}

/**************************************************************
**	FUNCTION NAME		: EmSetNWCellLock
**
** 	PURPOSE				: Set EM Network Cell Lock  
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmSetNWCellLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 textbuf[20];
    U16 value;
    MMI_BOOL result = MMI_TRUE;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    /* To check if ARFCN is valid */
    mmi_ucs2_to_asc((PS8)textbuf,  (PS8)g_em_nw_cell_lock_cntx.arfcn);
    value = atoi((const char *) textbuf);
         
    if ( value > 1024 )
        result = MMI_FALSE;         
     
    /* To check input data is not NULL */
    if (!mmi_ucs2strlen((const S8*)g_em_nw_cell_lock_cntx.arfcn))
        result = MMI_FALSE;

    /* If one of the parameters is invalid, then pop-up error and return */
    if (result == MMI_FALSE)
    {
        DisplayPopup((PU8)GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, 1000, 0);
        return;
    }

    EmSetNWCellLockReq((MMI_BOOL)g_em_nw_cell_lock_cntx.currCellLock, (MMI_BOOL)g_em_nw_cell_lock_cntx.curr1900Band, value);
    
}

     
/**************************************************************

	FUNCTION NAME		: ExitEmNWCellLockInlineScr()

  	PURPOSE				: Exit Em Cell Lock Inline edit screen

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void ExitEmNWCellLockInlineScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
}


/**************************************************************
**	FUNCTION NAME		: HighlightHandlerNWCellLockEnableInline
**
**  PURPOSE				: Highlight handler of EM NWCellLock Inline highlight handler.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightHandlerNWCellLockEnableInline(S32 index) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_em_nw_cell_lock_cntx.currCellLock == 0)  // False
    {
        DisableInlineItem(&wgui_inline_items[3], 3);    
        DisableInlineItem(&wgui_inline_items[5], 5);            
    }
    else  // true
    {
        EnableInlineItem(&wgui_inline_items[3], 3);    
        EnableInlineItem(&wgui_inline_items[5], 5);            
    }
    RedrawCategory57Screen();
}


#ifdef __EM_MODE__
/**************************************************************
**	FUNCTION NAME		: EntryEmNetworkEventMenu
**
** 	PURPOSE				: Entry EM Network Events function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmNetworkEventMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32];
    U16 ItemIcons[32];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EmNWEventPrepareContext();
 
    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_MENU_SCR, NULL, EntryEmNetworkEventMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_NETWORK_EVENT_MENU_SCR);

    nItems = GetNumOfChild(EM_NETWORK_NETWORK_EVENT_MENUID);
    GetSequenceStringIds(EM_NETWORK_NETWORK_EVENT_MENUID, ItemList);
    SetParentHandler(EM_NETWORK_NETWORK_EVENT_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   
    }

    ShowCategory52Screen(
        EM_NET_NETWORK_EVENT_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  EmNWEventPrepareContext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWEventPrepareContext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_em_nw_event_setting_struct nvram_buf;    
    nvram_ef_em_nw_event_setting_struct *temp_setting = &nvram_buf;    
    S16 error;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nw_event_cntx.total_item_num = em_nw_get_total_event();

    ASSERT(g_nw_event_cntx.total_item_num < EM_NW_EVENT_MAX_NUM_OF_EVENTS);
    
    memset(g_nw_event_cntx.event_num_of_group, 0, sizeof(g_nw_event_cntx.event_num_of_group));    
    ReadRecord(NVRAM_EF_EM_NW_EVENT_RINGS_LID, 1, (void*)&nvram_buf, NVRAM_EF_EM_NW_EVENT_RINGS_SIZE, &error);

    g_nw_event_cntx.group_filter_mask = temp_setting->group_filter;

    for (i=0; i<EM_NW_MAX_NO_OF_GROUP ; i++)
    {
        g_nw_event_cntx.event_filter_mask[i] = temp_setting->event_filter[i];

        if (EM_IS_SET(g_nw_event_cntx.group_filter_mask, i))
        {
            g_nw_event_cntx.group_cur_state[i]= MMI_TRUE;
        }
        else
        {
            g_nw_event_cntx.group_cur_state[i] = MMI_FALSE;
        }        
    }

    for (i = 0; i < g_nw_event_cntx.total_item_num; i++)
    {
        em_network_event_tbl[i].ring_tone_id = temp_setting->event_ring[i];    
        g_nw_event_cntx.event_num_of_group[(em_network_event_tbl[i].group_id)]++;

    }

}


/**************************************************************
**	FUNCTION NAME		: EmNetworkEventStartReq
**
** 	PURPOSE				: EM Network Events Start Req function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmNetworkEventStartReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nw_event_cntx.is_on == MMI_TRUE)
    {
        g_nw_event_cntx.is_on = MMI_FALSE;
        Category52ChangeItemDescription(0, (U8*) get_string(STR_GLOBAL_OFF));
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        g_nw_event_cntx.is_on = MMI_TRUE;    
        Category52ChangeItemDescription(0, (U8*) get_string(STR_GLOBAL_ON));
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    RedrawCategoryFunction();
    
    /* Send msg to PS */
    EmNWEventStartStopReq();
    
}


/**************************************************************
**	FUNCTION NAME		: EntryEmNWEventFilterMenu
**
** 	PURPOSE				: Entry EM Network Events Filter function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmNWEventFilterMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[EM_NW_MAX_NO_OF_GROUP*2];
    U8 *guiBuffer;
    S8 buffer[32];    
    U8 i=0;
    U16 temp_idx=0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuData, 0, sizeof(subMenuData));

    /* exit function --> function reuse */
    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_FILTER_SCR, ExitEmNWCellLockInlineScr, EntryEmNWEventFilterMenu, NULL);

    InitializeCategory57Screen();
    
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_NETWORK_EVENT_FILTER_SCR);
    RegisterHighlightHandler(EmNWEventGroupFilterHighlightIndex);

    for (i = 0; i < EM_NW_MAX_NO_OF_GROUP; i++)
    {
        temp_idx += g_nw_event_cntx.event_num_of_group[i];
        
        sprintf(buffer, "%s", em_network_event_tbl[temp_idx-1].group_name);
        mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);

        SetInlineItemActivation(&wgui_inline_items[i*2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemCaption(&wgui_inline_items[i*2], (U8*)subMenuData[i]);
        ItemIcons[i*2] = IMG_STATUS;
    
        g_nw_event_cntx.pEmNwEventGroupOnOff[0] = (U8*)GetString(STR_GLOBAL_OFF);
        g_nw_event_cntx.pEmNwEventGroupOnOff[1] = (U8*)GetString(STR_GLOBAL_ON);
        SetInlineItemActivation(&wgui_inline_items[i*2+1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(&wgui_inline_items[i*2+1], 2, (U8**)g_nw_event_cntx.pEmNwEventGroupOnOff, &g_nw_event_cntx.group_cur_state[i]);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[i*2+1],HighlightHandlerEmNwEventGroupFilterInline);
        ItemIcons[i*2+1] = 0;
    }

    ShowCategory57Screen(EM_NET_NETWORK_EVENT_FILTER_TEXT, 0, 
                         0, 
                         0, 
                         STR_GLOBAL_BACK, 
                         0,
 	                     EM_NW_MAX_NO_OF_GROUP*2, 
 	                     ItemIcons, 
 	                     wgui_inline_items, 
 	                     0, 
 	                     guiBuffer);	
      
    SetCategory57RightSoftkeyFunctions( EntryNWEventUpdateSrc, EntryNWEventUpdateSrc );

}


/**************************************************************
**	FUNCTION NAME		: EmNWEventGroupFilterHighlightIndex
**
**  PURPOSE				: Highlight handler of Em NW Group Filter highlight Index handler.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmNWEventGroupFilterHighlightIndex(S32 index) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nw_event_cntx.current_group = index/2;
}

/**************************************************************
**	FUNCTION NAME		: HighlightHandlerEmNwEventGroupFilterInline
**
**  PURPOSE				: Highlight handler of Em NW Event Filter Inline highlight handler.
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void HighlightHandlerEmNwEventGroupFilterInline(S32 index) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nw_event_cntx.group_cur_state[g_nw_event_cntx.current_group] == MMI_TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
   	    SetCategory57LeftSoftkeyFunction(EntryEmNwEventFilterEdit); 

        EM_STATE_SET(g_nw_event_cntx.group_filter_mask, g_nw_event_cntx.current_group);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
   	    SetCategory57LeftSoftkeyFunction(NULL);        
   	    
        EM_STATE_UNSET(g_nw_event_cntx.group_filter_mask, g_nw_event_cntx.current_group);   	    
    }
    RedrawCategoryFunction();
}


/**************************************************************
**	FUNCTION NAME		: EntryEmNwEventFilterEdit
**
** 	PURPOSE				: Entry EM Network Event Filter Edit function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmNwEventFilterEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[40];
    U8 *guiBuffer;
    S8 buffer[32];    
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_FILTER_SETTING_SCR, NULL, EntryEmNwEventFilterEdit, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_NETWORK_EVENT_FILTER_SETTING_SCR);

    RegisterHighlightHandler(EmNwEventFilterEditHighlightIndex);

    g_nw_event_cntx.cur_start_idx_in_tbl = 0;
    for (i = 0; i<g_nw_event_cntx.current_group; i++)
    {
        g_nw_event_cntx.cur_start_idx_in_tbl += g_nw_event_cntx.event_num_of_group[i];
    }
    
    for (i = 0; i < g_nw_event_cntx.event_num_of_group[g_nw_event_cntx.current_group]; i++)
    {
        sprintf(buffer, "%s", em_network_event_tbl[g_nw_event_cntx.cur_start_idx_in_tbl+i].event_name);
        mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
        subMenuDataPtrs[i] = subMenuData[i];

        hintDataPtrs[i] = NULL;        
    }

    ShowCategory53Screen(
        EM_NET_NETWORK_EVENT_FILTER_TEXT,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        g_nw_event_cntx.event_num_of_group[g_nw_event_cntx.current_group],
        (PU8*) subMenuDataPtrs,
        (U16*) ItemIcons,
        (U8 **) hintDataPtrs,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
//    SetLeftSoftkeyFunction(em_nw_event_select_ring, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmNwEventFilterEditHighlightIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmNwEventFilterEditHighlightIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nw_event_cntx.current_event = nIndex;

    if (EM_IS_SET(g_nw_event_cntx.event_filter_mask[g_nw_event_cntx.current_group], nIndex))
    {
        Category52ChangeItemDescription(nIndex, (U8*) get_string(STR_GLOBAL_ON));
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        Category52ChangeItemDescription(nIndex, (U8*) get_string(STR_GLOBAL_OFF));
        change_left_softkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();

    SetLeftSoftkeyFunction(EmNWEventSetFilter, KEY_EVENT_UP);
        
}


/*****************************************************************************
 * FUNCTION
 *  EmNWEventSetFilter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWEventSetFilter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EM_STATE_TOGGLE(g_nw_event_cntx.event_filter_mask[g_nw_event_cntx.current_group], g_nw_event_cntx.current_event);

    if (EM_IS_SET(g_nw_event_cntx.event_filter_mask[g_nw_event_cntx.current_group], g_nw_event_cntx.current_event))
    {
        Category52ChangeItemDescription(g_nw_event_cntx.current_event, (U8*) get_string(STR_GLOBAL_ON));
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        Category52ChangeItemDescription(g_nw_event_cntx.current_event, (U8*) get_string(STR_GLOBAL_OFF));
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    RedrawCategoryFunction();
}


/**************************************************************
**	FUNCTION NAME		: EntryEmNWEventSettingMenu
**
** 	PURPOSE				: Entry EM Network Events Setting function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmNWEventSettingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[40];
    U8 *guiBuffer;
    S8 buffer[32];    
    U8 i=0;
    U16 temp_idx=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));
    memset(subMenuData, 0, sizeof(subMenuData));
    
    EmNWEventPrepareContext();

    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_SETTING_SCR, NULL, EntryEmNWEventSettingMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_NETWORK_EVENT_SETTING_SCR);
    RegisterHighlightHandler(SetHighlightIndex);

    for (i = 0; i < EM_NW_MAX_NO_OF_GROUP; i++)
    {
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);   

        temp_idx += g_nw_event_cntx.event_num_of_group[i];

//        sprintf(buffer, "Group %d", i+1);
        sprintf(buffer, "%s", em_network_event_tbl[temp_idx-1].group_name);
        mmi_asc_to_ucs2((PS8) subMenuData[i], buffer);
        subMenuDataPtrs[i] = subMenuData[i];       
    }

    ShowCategory53Screen(
        EM_NET_NETWORK_EVENT_SETTING_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        EM_NW_MAX_NO_OF_GROUP,
        (PU8*) subMenuDataPtrs,
        (U16*) ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryEmNetworkEventGroup, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    

}


/**************************************************************
**	FUNCTION NAME		: EntryEmNetworkEventGroup
**
** 	PURPOSE				: Entry EM Network Event Groups function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryEmNetworkEventGroup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemIcons[40];
    U8 *guiBuffer;
    S8 buffer[32];
    U16 i=0;
    U16 ring_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));
    memset(subMenuData, 0, sizeof(subMenuData));

    ASSERT(g_nw_event_cntx.event_num_of_group[currentHighlightIndex] <= MAX_NWEVENT_OF_A_GROUP);

    g_nw_event_cntx.cur_start_idx_in_tbl = 0;
    for (i = 0; i<currentHighlightIndex; i++)
    {
        g_nw_event_cntx.cur_start_idx_in_tbl += g_nw_event_cntx.event_num_of_group[i];
    }
    
    for (i = 0; i < g_nw_event_cntx.event_num_of_group[currentHighlightIndex]; i++)
    {
        sprintf(buffer, "%s", em_network_event_tbl[g_nw_event_cntx.cur_start_idx_in_tbl+i].event_name);
        mmi_asc_to_ucs2((PS8) subMenuData[i*2], buffer);
        subMenuDataPtrs[i*2] = subMenuData[i*2];
        ItemIcons[i*2] = IMG_STATUS; 

        ring_id = em_network_event_tbl[g_nw_event_cntx.cur_start_idx_in_tbl+i].ring_tone_id;

        /* Ring Tone as Alarm */
        if ((ring_id >= gstartRingId) && (ring_id <= (gstartRingId + gtotalRingId - 1)))
        {
            mmi_ucs2cpy((S8*) subMenuData[(i*2)+1], (S8*) GetString(STR_PROFILES_RING_1+(ring_id-gstartRingId)));
        }
        /* Midi Tone as Alarm */
        else if ((ring_id >= gstartMidiId) && (ring_id <= (gstartMidiId + gtotalMidiId - 1)))
        {
            mmi_ucs2cpy((S8*) subMenuData[(i*2)+1], (S8*) GetString(STR_PROFILES_RING_1+(ring_id - gstartMidiId + gtotalRingId)));
        }
    #if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)        
        else if (ring_id >= PMG_EXT_MELODY_BEGIN && ring_id <= PMG_EXT_MELODY_END)
        {
            DYNEXTMELODYINFO *ExtMelodyInfo;

            PmgGetExtMelodyInfo(&ExtMelodyInfo);
            mmi_ucs2cpy((S8*) subMenuData[(i*2)+1], (S8*)(ExtMelodyInfo->info[ring_id - PMG_EXT_MELODY_BEGIN]).filename);
        }
    #endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */
        else
        {
            mmi_ucs2cpy((S8*) subMenuData[(i*2)+1], (S8*) GetString(STR_PROFILES_RING_1));
        }

        subMenuDataPtrs[(i*2)+1] = subMenuData[(i*2)+1];
        ItemIcons[(i*2)+1] = 0; 
        
    }

    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_GROUP_SCR, NULL, EntryEmNetworkEventGroup, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_NETWORK_EVENT_GROUP_SCR);
    RegisterHighlightHandler(EmNwEventInlineEditHighlightHdlr);

    ShowCategory53Screen(
        EM_NET_NETWORK_EVENT_GROUP_TEXT,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        g_nw_event_cntx.event_num_of_group[currentHighlightIndex]*2,
        (PU8*) subMenuDataPtrs,
        (U16*) ItemIcons,
        0,
        0,
        0,
        guiBuffer);

  SetRightSoftkeyFunction(EntryNWEventUpdateSrc, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryNWEventUpdateSrc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryNWEventUpdateSrc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_UPDATE_SCR, NULL, EntryNWEventUpdateSrc, NULL);
    
    ShowCategory2Screen(
        EM_UPDATE_TITLE_TEXT, 
        0, 
        STR_GLOBAL_YES, 
        0, 
        STR_GLOBAL_NO, 
        0, 
        EM_UPDATE_QUERY_TEXT, 
        NULL);

    SetLeftSoftkeyFunction(EmNWEventUpdate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    DeleteScreenIfPresent(EM_NETWORK_NETWORK_EVENT_GROUP_SCR);    
    DeleteScreenIfPresent(EM_NETWORK_NETWORK_EVENT_FILTER_SCR);    
    
    
}


/*****************************************************************************
 * FUNCTION
 *  EmNWEventUpdate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWEventUpdate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_em_nw_event_setting_struct nvram_buf;    
    nvram_ef_em_nw_event_setting_struct *temp_setting = &nvram_buf;    
    S16 error;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_setting->group_filter = g_nw_event_cntx.group_filter_mask;

    for(i = 0; i<EM_NW_MAX_NO_OF_GROUP; i++)
    {
        temp_setting->event_filter[i] = g_nw_event_cntx.event_filter_mask[i];
    }
    
    for (i = 0; i < g_nw_event_cntx.total_item_num; i++)
    {
        temp_setting->event_ring[i] = em_network_event_tbl[i].ring_tone_id;
    }
    
    WriteRecord(NVRAM_EF_EM_NW_EVENT_RINGS_LID, 1, (void*)&nvram_buf, NVRAM_EF_EM_NW_EVENT_RINGS_SIZE, &error);

    EngineerModeSuccessNotice(EM_AUD_SET_SUCCESS_TEXT);    
    DeleteScreenIfPresent(EM_NETWORK_NETWORK_EVENT_UPDATE_SCR);
}


/*****************************************************************************
 * FUNCTION
 *  EmNwEventInlineEditHighlightHdlr
 * DESCRIPTION
 *  EM NW Events editor highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmNwEventInlineEditHighlightHdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index%2)
    {
        g_nw_event_cntx.current_event = index/2;
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(EntryNwEventSelectRingTone, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
}


/**************************************************************
**	FUNCTION NAME		: EntryNwEventSelectRingTone
**
** 	PURPOSE				: Entry EM Network Event Select Ring function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EntryNwEventSelectRingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 selecteditem = 0;
    U8 totalItems = 0;
    U16 ring_id;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    mmi_profiles_Ext_melody_set_tone_type(PRFSET_MELODY_TYPE_ENGINEERMODE);
#endif

    EntryNewScreen(EM_NETWORK_NETWORK_EVENT_SELECT_RING_SCR, mmi_profiles_exit_ring_tone_list, EntryNwEventSelectRingTone, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_NETWORK_NETWORK_EVENT_SELECT_RING_SCR);

    ring_id = em_network_event_tbl[g_nw_event_cntx.cur_start_idx_in_tbl+g_nw_event_cntx.current_event].ring_tone_id;
        
    if (ring_id == 0)
    {
        totalItems = mmi_profiles_get_melody_list((U16)(gstartRingId), &selecteditem);
    }
    else
    {
        totalItems = mmi_profiles_get_melody_list((U16)ring_id, &selecteditem);  
    }
    
    RegisterHighlightHandler(mmi_profiles_melody_list_highlight_hdlr);

    ShowCategory89Screen(
        EM_NET_NETWORK_EVENT_SELECT_RING_TEXT,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        totalItems,
        subMenuDataPtrs,
        hintDataPtrs,
        0,
        selecteditem,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_profiles_stop_tone_and_go_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(em_nw_event_select_ring, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  em_nw_event_select_ring
 * DESCRIPTION
 *  select a ring tone id from profile done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_nw_event_select_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_profiles_set_ring_tone_id_count_id(em_nw_event_ring_get_id_callback);
}


/*****************************************************************************
 * FUNCTION
 *  em_nw_event_ring_get_id_callback
 * DESCRIPTION
 *  Get the ring tone id from profile
 * PARAMETERS
 *  ExtMelodyFlag       [IN]        Is it a external resource
 *  ringToneId          [IN]        Selected ring tone id.
 * RETURNS
 *  void
 *****************************************************************************/
void em_nw_event_ring_get_id_callback(U8 ExtMelodyFlag, U16 ringToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PROFILE_EXTMELODY_SUPPORT__)
    if (ExtMelodyFlag == MMI_TRUE)
    {
        mmi_profiles_Ext_melody_set_tone_type(PRFSET_MELODY_TYPE_ENGINEERMODE);
        mmi_profiles_Ext_melody_entry_menu();
        return;
    }
#endif /* defined(__MMI_PROFILE_EXTMELODY_SUPPORT__) */ 

    em_nw_event_select_ring_done(ringToneId);
}


/**************************************************************
**	FUNCTION NAME		: EmNWEventStartStopReq
**
** 	PURPOSE				: EM NW Event Start/Stop request function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmNWEventStartStopReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_nw_event_notify_req_struct *msg_p;
    U8 i, mod_num=0;
    U16 index=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nw_event_cntx.cur_playing_index = 0;
    g_nw_event_cntx.cur_queue_index = 0;
    g_nw_event_cntx.is_playing = 0;
    
    msg_p = OslConstructDataPtr(sizeof(mmi_em_nw_event_notify_req_struct));
    msg_p->is_on = g_nw_event_cntx.is_on; 

    for (i = 0; i < EM_NW_MAX_NO_OF_GROUP; i++)
    {
        index = index + g_nw_event_cntx.event_num_of_group[i];
        
        if (EM_IS_SET(g_nw_event_cntx.group_filter_mask, i))
        {
            msg_p->mod_list[mod_num] = em_network_event_tbl[index-1].mod_id; 
            mod_num++;
        }
    }
    msg_p->num_of_mod = mod_num; 

    EngineerModeSendMsg(MSG_ID_MMI_EM_NW_EVENT_NOTIFY_REQ, msg_p, NULL);

}


/**************************************************************
**	FUNCTION NAME		: EngineerModeNWEventRsp
**
** 	PURPOSE				: Start EM NW Event response function. 
**
**	INPUT PARAMETERS	: nil
**
**	OUTPUT PARAMETERS	: void
**
**	RETURNS				: void
**
**	REMARKS			: 
**************************************************************/
void EmNWEventStartStopRsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_nw_event_notify_rsp_struct *rsp_p = inMsg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result)
    {
        EngineerModeSuccessNotice(EM_UPDATE_SUCCESS_TEXT);
    }
    else
    {
        EngineerModeErrorNotice(EM_UPDATE_ERROR_TEXT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeNWEventNotifyInd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeNWEventNotifyInd(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_nw_event_notify_ind_struct *status_ind = inMsg;
    U16 index=0;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nw_event_cntx.is_on == 0 )
    {
        return;
    }
    
    if (!EM_IS_SET(g_nw_event_cntx.group_filter_mask, status_ind->group_id))
    {
        return;
    }

    for (i=0 ;i < (status_ind->group_id); i++)
    {
        index = index + g_nw_event_cntx.event_num_of_group[i];
    }
        
    for (i=0; i < g_nw_event_cntx.event_num_of_group[status_ind->group_id]; i++)
    {
        if (status_ind->event_id == em_network_event_tbl[index].event_id)
        {
            if(EM_IS_SET(g_nw_event_cntx.event_filter_mask[status_ind->group_id], i))
            {
                if (g_nw_event_cntx.cur_queue_index < (EM_NW_NUM_OF_QUEUE_EVENT-1))
                {
                    if (g_nw_event_cntx.is_playing == MMI_TRUE &&
                        ((g_nw_event_cntx.cur_queue_index+1) != g_nw_event_cntx.cur_playing_index))
                    {
                        g_nw_event_cntx.event_rone_queue[g_nw_event_cntx.cur_queue_index]=em_network_event_tbl[index].ring_tone_id;
                        g_nw_event_cntx.cur_queue_index++;
                    }
                    else
                    {
                        g_nw_event_cntx.event_rone_queue[g_nw_event_cntx.cur_queue_index]=em_network_event_tbl[index].ring_tone_id;
                        g_nw_event_cntx.cur_queue_index++;
                    }
                }
                else    /* g_nw_event_cntx.cur_queue_index == (EM_NW_NUM_OF_QUEUE_EVENT-1) */
                {
                    if (g_nw_event_cntx.cur_playing_index != 0 )
                    {
                        g_nw_event_cntx.event_rone_queue[g_nw_event_cntx.cur_queue_index]=em_network_event_tbl[index].ring_tone_id;
                        g_nw_event_cntx.cur_queue_index = 0;
                    }
                }

                if (g_nw_event_cntx.is_playing == MMI_FALSE)
                {
                    EmNWPlayEventToneHdlr();
                }
            }
            break;
        }
        index++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmNWPlayEventToneHdlr
 * DESCRIPTION
 *  EmNWPlayEventToneHdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmNWPlayEventToneHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_NW_EVENT_PLAY_TONE_TIMER);
    
    if (g_nw_event_cntx.cur_playing_index == 0 )
    {
        AudioStopReq(g_nw_event_cntx.event_rone_queue[0]);                
    }
    else
    {
        AudioStopReq(g_nw_event_cntx.event_rone_queue[g_nw_event_cntx.cur_playing_index-1]);  
    }

    if (g_nw_event_cntx.cur_playing_index == g_nw_event_cntx.cur_queue_index)
    {
        g_nw_event_cntx.is_playing = MMI_FALSE;         
        return;
    }
     
    g_nw_event_cntx.is_playing   = MMI_TRUE;
   
    if (!IsSilentModeActivated() && !isInCall()) 
    {
    #ifdef __MMI_SILENT_MEETING_PROFILE__
        if (!IsMeetingModeActivated())
    #endif 
        {
            StartTimer(EM_NW_EVENT_PLAY_TONE_TIMER, 3000, EmNWPlayEventToneHdlr);             
            
            if (g_nw_event_cntx.cur_playing_index < EM_NW_NUM_OF_QUEUE_EVENT)
            {
                AudioPlayReq(g_nw_event_cntx.event_rone_queue[g_nw_event_cntx.cur_playing_index], (U8) DEVICE_AUDIO_PLAY_ONCE);                
            }
            else  /* g_nw_event_cntx.cur_playing_index = EM_NW_NUM_OF_QUEUE_EVENT */
            {
                g_nw_event_cntx.cur_playing_index = 0;
                AudioPlayReq(g_nw_event_cntx.event_rone_queue[g_nw_event_cntx.cur_playing_index], (U8) DEVICE_AUDIO_PLAY_ONCE);                
            }
        }
    }
    else
    {
        StartTimer(EM_NW_EVENT_PLAY_TONE_TIMER, 3000, EmNWPlayEventToneHdlr);     

//        PlayVibratorOnce();
        
        if (g_nw_event_cntx.cur_playing_index >= EM_NW_NUM_OF_QUEUE_EVENT)
        {
            g_nw_event_cntx.cur_playing_index = 0;
        }
    }

    g_nw_event_cntx.cur_playing_index++;

}
#endif /* #ifdef __EM_MODE__ */


#endif /* defined(__MMI_ENGINEER_MODE__) && defined(__EM_MODE__) */ 

