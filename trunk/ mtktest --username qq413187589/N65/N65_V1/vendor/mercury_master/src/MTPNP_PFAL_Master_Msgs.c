/***********************************************
File name : MTPNP_PFAL_custom_sms.c
Contents : MTPNP pfal sms custom interface
History : Create by : Zhang Nan, Apr 22, 2007
************************************************/
#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

/* MTK header file */
#include "stdC.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"
#include "FrameworkStruct.h"
#include "ProtocolEvents.h"
#include "EventsGprot.h"
#include "wgui_status_icons.h"
#include "GlobalDefs.h"
//...Add MSG header
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
#include "wgui_categories_popup.h"
#include "CommonScreens.h"

// 
#include "SMSApi.h"
#include "SMSStruct.h"
#include "customer_ps_inc.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "ems.h"
#include "SMSFunc.h"
#include "PhoneBookGprot.h"

#include "IdleAppDef.h"
#include "GlobalMenuItems.h"
#include "MessagesresourceData.H"
#include "vCalendar.h"
/* MTK header file */

#include "MTPNP_PFAL_custom_hw.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_Master_Msgs.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Message_Data_Convert.h"
#include "MTPNP_PFAL_CellBroadcast.h"
#include "MTPNP_PFAL_MessageSetup.h"
#include "MTPNP_AD_master_header.h"  //huyi-20080505
extern void mmi_frm_sms_send_sms_rsp(void *inMsg);
extern void mmi_frm_sms_abort_sms_rsp(void *inMsg);
extern void mmi_frm_sms_save_sms_rsp(void *inMsg);
extern void mmi_frm_sms_new_sms_ind(void *inMsg);
extern void mmi_frm_sms_add_new_data(mmi_frm_sms_deliver_data_struct *entry, U16 length, U8 *data);
extern void mmi_frm_sms_new_data(void);
extern void mmi_frm_sms_common_status_report_ind(void *inMsg);

extern void mmi_msg_count_unread_sms(void);   /*add by lijianxin 080508*/
extern unsigned short mmi_frm_sms_show_list_index[MMI_SMS_MAX_MSG_NUM];  /* list index to show */
extern const MTPNP_UINT16 gIndexIconsImageList[];
extern PendingSaveSendDataStruct PendingSaveSendData;
extern mmi_frm_sms_context_struct g_frm_sms_cntx;
extern MTPNP_BOOL g_mmi_frm_sms_change_status;
extern unsigned short mmi_frm_sms_outbox_list[MMI_SMS_MAX_MSG_NUM];
extern mmi_frm_sms_msgbox_struct mmi_frm_sms_msg_box[MMI_SMS_MAX_MSG_NUM];
extern msg_context_struct g_msg_cntx;
extern MMI_BOOL g_mmi_frm_sms_list_finish;
extern U16 sms_unread;    /*add by lijianxin 080508*/

static MTPNP_BOOL g_avtive_sms_is_slave = MTPNP_FALSE;
static MTPNP_UINT8 g_msgs_delall_state = DM_MASTER_BOX | DM_SLAVE_BOX;
static U16 sms_copy_index;
static MTPNP_UINT32 g_sms_wait_icon = 0;

void MTPNP_PFAL_Master_SMS_Init(void)
{
    g_avtive_sms_is_slave = MTPNP_FALSE;

    /* regester menu hightlight and hint */
    SetHiliteHandler(MENU_MTPNP_EMS_ED_OPT_DONE, HightlightSlaveMsgDone);
    SetHiliteHandler(MENU_MTPNP_OUTBOX_OPT_SEND_SMS, mmi_msg_highlight_SIM2_send_outbox);
    SetHiliteHandler(SMS_OUTBOX_OPT_FORWARD_MENUID, HightlightDualModeMsgBoxForward);
    SetHiliteHandler(SMS_INBOX_OPT_FORWARD_MENUID, HightlightDualModeMsgBoxForward);
    SetHiliteHandler(MENU_MTPNP_MSGBOX_OPT_MASTER_FORWARD, HightlightMsgBoxMasterForward);
    SetHiliteHandler(MENU_MTPNP_MSGBOX_OPT_SLAVE_FORWARD, HightlightMsgBoxSlaveForward);

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_STARTUP_READ_BEGIN_IND, MTPNP_PFAL_EVT_SMS_Load_Begin_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_READY_IND, MTPNP_PFAL_Message_Ready_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_NEW_SMS_IND, MTPNP_PFAL_Deliver_New_Msg_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_APP_DATA_IND, MTPNP_PFAL_Deliver_New_App_Data_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_MEM_FULL_IND, MTPNP_PFAL_Message_Memory_Full_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_MEM_AVAILABLE_IND, MTPNP_PFAL_Message_Memory_Avail_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_MEM_EXCEED_IND, MTPNP_PFAL_Message_Memory_Exceed_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_STATUS_REPORT_IND, MTPNP_PFAL_Message_Status_Report_Ind);
}

#if (defined(__MMI_VCALENDAR__) && !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__))
void HighlightVclndrSendBySms(void)
{
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);

    SetLeftSoftkeyFunction(mmi_vclndr_sms_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_vclndr_sms_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_VCALENDAR__) && !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */

void HightlightSlaveMsgDone(void)
{
    /* update channel status */
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    /* update channel status */

    mmi_msg_highlight_generic(STR_GLOBAL_OK,
                              IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_send_option, GoBackHistory);
    if ((g_msg_cntx.sendMessageCase == SEND_CASE_REPLY) || (g_msg_cntx.sendMessageCase == SEND_CASE_SEND_FROM_PHB))
    {
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}

void mmi_msg_highlight_SIM2_send_outbox(void)
{
#if defined(__MMI_DUAL_SIM_MASTER__)
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_UNIFIED_MESSAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        U8 msg_box_type = mmi_um_get_current_msg_box_type();

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        if ( (msg_box_type == UM_MSG_BOX_TYPE_SENT) 
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__            
            || (msg_box_type == UM_MSG_BOX_TYPE_ARCHIVE)
            #endif            
        )  
        {

            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                mmi_msg_entry_SIM2_send_option_outbox,
                GoBackHistory);
        }
        else if (msg_box_type == UM_MSG_BOX_TYPE_UNSENT || msg_box_type == UM_MSG_BOX_TYPE_DRAFT)
        {
            mmi_msg_highlight_generic(
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                mmi_msg_pre_resend_msg_to_only_entry,
                GoBackHistory);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
#else /* __MMI_UNIFIED_MESSAGE__ */ 
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_entry_SIM2_send_option_outbox,
        GoBackHistory);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
}

void HightlightDualModeMsgBoxForward(void)
{
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryDualModeMsgBoxForward, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryDualModeMsgBoxForward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

void HightlightMsgBoxMasterForward(void)
{
    /* update channel status */
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
    /* update channel status */

    mmi_msg_highlight_generic(STR_GLOBAL_OK,
                              IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_forward_option_inbox, GoBackHistory);
}

void HightlightMsgBoxSlaveForward(void)
{
    /* update channel status */
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
    /* update channel status */

    mmi_msg_highlight_generic(STR_GLOBAL_OK,
                              IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK, IMG_GLOBAL_BACK, mmi_msg_entry_forward_option_inbox, GoBackHistory);
}

void mmi_msg_entry_SIM2_send_option_outbox(void)
{
#ifdef __MMI_UNIFIED_COMPOSER__
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
    EMSData *pEMS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    GetEMSDataForEdit(&pEMS, 0);
    
    if (pEMS->listHead)
    {
        mmi_msg_set_confirm_screen(STR_SMS_REMOVE_EMS_OBJECT_QUERY_ID, mmi_msg_forward_msg_by_uc, GoBackHistory);
        mmi_msg_entry_confirm_generic();
    }
    else
    {
        mmi_msg_forward_msg_by_uc();
    }
    
#else /* __MMI_UNIFIED_COMPOSER__ */


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    if (mmi_nsm_get_msg_type() == PICTURE_MESSAGE)
    {
        if (gPictureMessageError == MMI_NSM_PIC_FORMAT_ERROR)
        {
            DisplayPopup(
                (U8*) GetString(STR_ID_NSM_RINGTOEN_FORMAT_NOT_SUPPORTED_MSG),
                IMG_GLOBAL_ERROR,
                FALSE,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

    EntryNewScreen(SCR_MTPNP_MSG_OUTBOX_SEND_OPTION, mmi_msg_exit_generic, mmi_msg_entry_SIM2_send_option_outbox, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[SmsMoMtGuiInterface.c] mmi_msg_entry_send_option_outbox*\n");

    result = CopyEMSViewToEditBuffer();
    /* copy view content to edit buffer maybe fail due to EMS LIB virtual pack fail */
    if (result != EMS_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_FAILURE_MSG_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_MTPNP_MSG_OUTBOX_SEND_OPTION);
        return;
    }
    g_msg_cntx.sendMessageCase = SEND_CASE_SEND_ONLY;   /* reset */
    guiBuffer = GetCurrGuiBuffer(SCR_MTPNP_MSG_OUTBOX_SEND_OPTION);

    numItems = GetNumOfChild(MENU_MTPNP_OUTBOX_OPT_SEND_SMS);
    GetSequenceStringIds(MENU_MTPNP_OUTBOX_OPT_SEND_SMS, nStrItemList);
    SetParentHandler(MENU_MTPNP_OUTBOX_OPT_SEND_SMS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_MTPNP_MSG_OUTBOX_SEND_OPTION);

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)

    /* Copy picbuffer and text buffer to send pic msg */
    if (IsScreenPresent(SCR_ID_PICMSG_OPTION))
    {
        S32 tmp_ucs2_count = g_nsm_msg_context.UCS2_count;

        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        g_nsm_msg_context.is_picmsg = TRUE;
        mmi_ucs2cpy((S8*) g_nsm_msg_context.textbuffer, (S8*) TextBuffer);
        memcpy(g_nsm_msg_context.picbuffer, gNSMBuffer, sizeof(g_nsm_msg_context.picbuffer));
        g_nsm_msg_context.UCS2_count = tmp_ucs2_count;
    }
    else
    {
        S32 tmp_ucs2_count = g_nsm_msg_context.UCS2_count;

        /* Jp for tracker issue 429 20050625 for normal sms */
        mmi_nsm2_init_nsm_msg_struct(&g_nsm_msg_context);
        g_nsm_msg_context.UCS2_count = tmp_ucs2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 

#if defined(__MMI_SMART_MESSAGE_MT__)

    if (IsScreenPresent(SCR_ID_PICMSG_OPTION))
    {
        S32 tmp_ucs2_count = picmsg_text_struct.ucs2_count;

        memset(&picmsg_text_struct, 0x00, sizeof(picmsg_text_struct));
        mmi_ucs2cpy(picmsg_text_struct.pic_textbuff, (S8*) TextBuffer);
        picmsg_text_struct.ucs2_count = tmp_ucs2_count;
    }
#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 

    ShowCategory52Screen(
        STR_SEND_OPTIONS_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

#endif /* __MMI_UNIFIED_COMPOSER__ */

}

void EntryDualModeMsgBoxForward(void)
{
    MTPNP_UINT16 nStrItemList[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    MTPNP_UINT16 nNumofItem;    /* Stores no of children in the submenu */
    MTPNP_UINT16 nDispAttribute;        /* Stores display attribue */
    MTPNP_UINT8 *guiBuffer;     /* Buffer holding history data */
    MTPNP_UINT8 *ItemType[MAX_SUB_MENUS];

    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_DUALMODE_MSGBOX_FORWARD, NULL, EntryDualModeMsgBoxForward, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_DUALMODE_MSGBOX_FORWARD);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(SMS_INBOX_OPT_FORWARD_MENUID);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(SMS_INBOX_OPT_FORWARD_MENUID);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(SMS_INBOX_OPT_FORWARD_MENUID, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(SMS_INBOX_OPT_FORWARD_MENUID);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(SMS_INBOX_OPT_FORWARD_MENUID, ItemType);

    ShowCategory52Screen(STR_FORWARD_MENUENTRY, IMG_SMS_ENTRY_SCRN_CAPTION,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (MTPNP_UINT16 *) gIndexIconsImageList, ItemType, 0, 0, guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void MTPNP_PFAL_SMS_Init_Msgbox(void)
{
    extern void mmi_frm_sms_init_msgbox(void);

    mmi_frm_sms_init_msgbox();
}

void MTPNP_PFAL_Card1_Read_SMS_Rsp(void *in_msg)
{
    extern void mmi_frm_sms_read_sms_rsp(void *inMsg);

    mmi_frm_sms_read_sms_rsp(in_msg);
}

void MTPNP_PFAL_Unpack_SMS(MTPNP_UINT8 dcs, MTPNP_UINT8 fo, MTPNP_UINT8 ori_dcs)
{
    extern void mmi_frm_sms_unpack_sms(MTPNP_UINT8 dcs, MTPNP_UINT8 fo, MTPNP_UINT8 ori_dcs);

    mmi_frm_sms_unpack_sms(dcs, fo, ori_dcs);
}

void MTPNP_PFAL_Add_SMS_To_List(void *data, MTPNP_UINT16 index)
{
    extern void mmi_frm_sms_add_sms_to_list(mmi_frm_sms_msgbox_struct * data, U16 index);

    mmi_frm_sms_add_sms_to_list((mmi_frm_sms_msgbox_struct *) data, index);
}

MTPNP_BOOL MTPNP_PFAL_Card1_SMS_Is_Avail(void)
{
    extern MTPNP_UINT8 mmi_msg_need_mem_full_ind(void);

    if (mmi_msg_need_mem_full_ind() == 0)
        return MTPNP_TRUE;

    return MTPNP_FALSE;
}

void MTPNP_PFAL_Active_Slave_SMS(MTPNP_BOOL flag)
{
    g_avtive_sms_is_slave = flag;
}

MTPNP_BOOL MTPNP_PFAL_Active_SMS_Is_Slave(void)
{
    return g_avtive_sms_is_slave;
}

S32 MTPNP_PFAL_Msg_Inbox_List_Get_Hint(S32 item_index, UI_string_type * hint_array)
{
    S32 list_index = item_index;

    if (MTPNP_AD_SMS_Get_Filter_Rule() != MTPNP_AD_FILTER_ALL)
    {
        list_index = mmi_frm_sms_show_list_index[item_index];
    }
    return mmi_msg_inbox_list_get_hint(list_index, hint_array);
}

MTPNP_UINT16 MTPNP_PFAL_Msg_Get_valid_L4index(MTPNP_UINT16 *l4_index)
{
	MTPNP_UINT16 i;
		
    for (i = 0; i < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size; i++)
    {
    	if (l4_index[i] != MMI_FRM_SMS_INVALID_INDEX)
    	{
        	return l4_index[i];			
    	}
    }

	return MMI_FRM_SMS_INVALID_INDEX;

}

MTPNP_BOOL MTPNP_PFAL_Msg_Inbox_List_Get_Item(MTPNP_INT32 item_index,
                                              UI_string_type str_buff,
                                              MTPNP_UINT8 ** img_buff_p, MTPNP_UINT8 str_img_mask)
{
    MTPNP_CHAR temp[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    MTPNP_CHAR *name;
    MTPNP_UINT16 *l4_index = MTPNP_OSAL_malloc(sizeof(MTPNP_UINT16) * (g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1));
    S32 list_index = item_index;

    if (MTPNP_AD_SMS_Get_Filter_Rule() != MTPNP_AD_FILTER_ALL)
    {
        list_index = mmi_frm_sms_show_list_index[item_index];
    }

    if (((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, (U16) list_index) & 0xf0) >> 4) == SMSAL_MTI_STATUS_REPORT)
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, (S8 *) GetString(STR_INBOX_REPORT_ID));
    }
    else
    {
        MTPNP_OSAL_memset(temp, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);

        mmi_asc_n_to_ucs2(
        	temp,
            (MTPNP_CHAR *)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_INBOX, (MTPNP_UINT16)list_index),
            MAX_DIGITS_SMS);

        name = lookUpNumber(temp);
        if (MTPNP_PFAL_Unicode_String_Length(name))
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, name);
        }
        else
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, temp);
        }
    }

    mmi_frm_sms_get_sms_index(MMI_FRM_SMS_APP_INBOX, (MTPNP_UINT16) list_index, l4_index);
    *l4_index = MTPNP_PFAL_Msg_Get_valid_L4index(l4_index);
    if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, (MTPNP_UINT16) list_index) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
    {
        #if 1
       if(( mmi_frm_sms_get_storage(MMI_FRM_SMS_INBOX, (MTPNP_UINT16) list_index))==SMSAL_ME)
       {
              if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
              {
                     *img_buff_p = get_image(IMG_MASTER_MESSAGE_PHONE_UNREAD);
              }
             else
             {
                     *img_buff_p = get_image(IMG_SLAVE_MESSAGE_PHONE_UNREAD);
              }
       }
	else
	 {
	       if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
              {
                     *img_buff_p = get_image(IMG_MASTER_MESSAGE_SIM_UNREAD);
              }
             else
             {
                     *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SIM_UNREAD);
              }
	 }
       #else
        if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
        {
            *img_buff_p = get_image(IMG_MASTER_MESSAGE_UNREAD);
        }
        else
        {
            *img_buff_p = get_image(IMG_SLAVE_MESSAGE_UNREAD);
        }
       #endif //modify by hechao
    }
    else
    {
        if (mmi_frm_sms_check_complete(MMI_FRM_SMS_APP_INBOX, (MTPNP_UINT16) list_index) == MTPNP_TRUE)
        {
        #if 1
		 if(( mmi_frm_sms_get_storage(MMI_FRM_SMS_INBOX, (MTPNP_UINT16) list_index))==SMSAL_ME)
       {
              if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
              {
                     *img_buff_p = get_image(IMG_MASTER_MESSAGE_PHONE_READ);
              }
             else
             {
                     *img_buff_p = get_image(IMG_SLAVE_MESSAGE_PHONE_READ);
              }
       }
	else
	 {
	       if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
              {
                     *img_buff_p = get_image(IMG_MASTER_MESSAGE_SIM_READ);
              }
             else
             {
                     *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SIM_READ);
              }
	 }
		
		#else
            if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                *img_buff_p = get_image(IMG_MASTER_MESSAGE_READ);
            }
            else
            {
                *img_buff_p = get_image(IMG_SLAVE_MESSAGE_READ);
            }
			#endif
        }
        else
        {
            if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                *img_buff_p = get_image(IMG_MASTER_MESSAGE_SS_NCOMP);
            }
            else
            {
                *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SS_NCOMP);
            }
        }
    }

    MTPNP_OSAL_memfree(l4_index);
    l4_index = MTPNP_NULL;

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Msg_Outbox_List_Get_Item(MTPNP_INT32 item_index,
                                               UI_string_type str_buff,
                                               MTPNP_UINT8 ** img_buff_p, MTPNP_UINT8 str_img_mask)
{
    MTPNP_CHAR temp[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];
    MTPNP_CHAR *name;
    MTPNP_UINT16 *l4_index = MTPNP_OSAL_malloc(sizeof(MTPNP_UINT16) * (g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1));
    S32 list_index = item_index;

    if (MTPNP_AD_SMS_Get_Filter_Rule() != MTPNP_AD_FILTER_ALL)
    {
        list_index = mmi_frm_sms_show_list_index[item_index];
    }

    if (strlen((MTPNP_CHAR *) mmi_frm_sms_get_address(MMI_FRM_SMS_APP_OUTBOX, (MTPNP_UINT16) list_index)))
    {
        MTPNP_OSAL_memset(temp, 0, (MAX_DIGITS_SMS + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(
        	temp,
        	(MTPNP_CHAR *)mmi_frm_sms_get_address(MMI_FRM_SMS_APP_OUTBOX, (MTPNP_UINT16)list_index),
        	MAX_DIGITS_SMS);

        name = lookUpNumber(temp);
        if (MTPNP_PFAL_Unicode_String_Length(name))
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, name);
        }
        else
        {
            MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, temp);
        }
    }
    else
    {
        MTPNP_PFAL_Unicode_String_Copy((MTPNP_CHAR *) str_buff, (MTPNP_CHAR *) GetString(STR_OUTBOX_LIST_MESSAGE));
    }

    mmi_frm_sms_get_sms_index(MMI_FRM_SMS_APP_OUTBOX, (MTPNP_UINT16) list_index, l4_index);
    if (mmi_frm_sms_check_complete(MMI_FRM_SMS_APP_OUTBOX, (MTPNP_UINT16) list_index) == MTPNP_FALSE)
    {
        if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
        {
            *img_buff_p = get_image(IMG_MASTER_MESSAGE_SS_NCOMP);
        }
        else
        {
            *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SS_NCOMP);
        }
    }
    else
    {
        if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_OUTBOX, (MTPNP_UINT16) list_index) & 0x0f) ==
            MMI_FRM_SMS_APP_OUTBOX)
        {
             #if 1
	    if(( mmi_frm_sms_get_storage(MMI_FRM_SMS_OUTBOX, (MTPNP_UINT16) list_index))==SMSAL_ME)
	    {
	         if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
               {
                     *img_buff_p = get_image(IMG_MASTER_MESSAGE_PHONE_SENT);
               }
               else
               {
                     *img_buff_p = get_image(IMG_SLAVE_MESSAGE_PHONE_SENT);
               }
	    }
	    else
	    {
	         if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                *img_buff_p = get_image(IMG_MASTER_MESSAGE_SIM_SENT);
            }
            else
            {
                *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SIM_SENT);
            }
	    }

		#else
            if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                *img_buff_p = get_image(IMG_MASTER_MESSAGE_SENT);
            }
            else
            {
                *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SENT);
            }
		#endif
        }
        else
        {
            #if 1
			if(( mmi_frm_sms_get_storage(MMI_FRM_SMS_OUTBOX, (MTPNP_UINT16) list_index))==SMSAL_ME)
	    {
	         if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
               {
                     *img_buff_p = get_image(IMG_MASTER_MESSAGE_PHONE_UNSENT);
               }
               else
               {
                     *img_buff_p = get_image(IMG_SLAVE_MESSAGE_PHONE_UNSENT);
               }
        }
        else
        {
            if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                *img_buff_p = get_image(IMG_MASTER_MESSAGE_SIM_UNSENT);
            }
            else
            {
                *img_buff_p = get_image(IMG_SLAVE_MESSAGE_SIM_UNSENT);
            }
	    }
	      #else
            if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                *img_buff_p = get_image(IMG_MASTER_MESSAGE_UNSENT);
            }
            else
            {
                *img_buff_p = get_image(IMG_SLAVE_MESSAGE_UNSENT);
            }
	     #endif
        }
    }

    MTPNP_OSAL_memfree(l4_index);
    l4_index = MTPNP_NULL;

    return MTPNP_TRUE;
}


void MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_BOOL blink, MTPNP_BOOL unblink)
{
    MTPNP_UINT16 i = 0;
    MTPNP_UINT16 totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    MTPNP_UINT16 totalsimbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_SIM);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    MTPNP_UINT16 *l4_index = MTPNP_OSAL_malloc(sizeof(MTPNP_UINT16) * (g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1));

	kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display"); //huyi-20080506
	if ((mmi_frm_sms_is_sms_valid() == FALSE)||(MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_ABSENT) || (MTPNP_AD_Get_Card1Status() == MTPNP_AD_SIMCARD_CHVBLOCKED))         
	{
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_INCOMING_SMS);
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SUBLCD_SMS);
		kal_prompt_trace(MOD_MMI, "all sim invalid");
		
		return;
	}
    if (blink == MTPNP_TRUE)
    {
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_INCOMING_SMS);
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SUBLCD_SMS);
        MTPNP_PFAL_Blink_StatusICON(STATUS_ICON_INCOMING_SMS);
        MTPNP_PFAL_Blink_StatusICON(STATUS_ICON_SUBLCD_SMS);
        MTPNP_PFAL_Refresh_StatusBar();

        kal_prompt_trace(MOD_MMI, "card1 sms display, blink");

        MTPNP_OSAL_memfree(l4_index);
        l4_index = MTPNP_NULL;
        return;
    }
    if (unblink == MTPNP_TRUE)
    {
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_INCOMING_SMS);
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SUBLCD_SMS);
    }

    kal_prompt_trace(MOD_MMI, "card1 sms display");

    if (MTPNP_PFAL_Card1_SMS_Is_Avail() && g_msg_cntx.msg_full_ind == FALSE)
    {
        if (totalinbox != MMI_FRM_SMS_INVALID_INDEX)
        {
            while (i < totalinbox)
            {
                mmi_frm_sms_get_sms_index(MMI_FRM_SMS_APP_INBOX, i, l4_index);
                *l4_index = MTPNP_PFAL_Msg_Get_valid_L4index(l4_index);
                if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, i) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
                {
                    kal_prompt_trace(MOD_MMI, "card1 sms display, index: %d", *l4_index);

                    if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                    {
                        kal_prompt_trace(MOD_MMI, "card1 sms display, show icon");

                        MTPNP_PFAL_Show_StatusICON(STATUS_ICON_INCOMING_SMS);
                        MTPNP_PFAL_Show_StatusICON(STATUS_ICON_SUBLCD_SMS);
                        MTPNP_PFAL_Refresh_StatusBar();
			   /*begin add by lijianxin 080508*/
			   mmi_msg_count_unread_sms();   
			   if (sms_unread != 0)
			   {
		//	   	mmi_show_nomal_index(2);   
			   }
			   /*end add by lijianxin 080508*/
                        MTPNP_OSAL_memfree(l4_index);
                        l4_index = MTPNP_NULL;
                        return;
                    }
                }
                i++;
            }
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            i = 0;
            while (i < totalsimbox)
            {
                mmi_frm_sms_get_sms_index(MMI_FRM_SMS_APP_INBOX, i, l4_index);
                if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_SIM, i) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
                {
                    if (*l4_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
                    {
                        MTPNP_PFAL_Show_StatusICON(STATUS_ICON_INCOMING_SMS);
                        MTPNP_PFAL_Show_StatusICON(STATUS_ICON_SUBLCD_SMS);
                        MTPNP_PFAL_Refresh_StatusBar();

                        MTPNP_OSAL_memfree(l4_index);
                        l4_index = MTPNP_NULL;

                        return;
                    }
                }
                i++;
            }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        }

        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_INCOMING_SMS);
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SUBLCD_SMS);
    }
    MTPNP_PFAL_Refresh_StatusBar();

    MTPNP_OSAL_memfree(l4_index);
    l4_index = MTPNP_NULL;
}

void MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_BOOL blink, MTPNP_BOOL unblink)
{
    MTPNP_UINT16 i = 0;
    MTPNP_UINT16 totalinbox = mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_APP_INBOX);
    MTPNP_UINT16 *l4_index = MTPNP_OSAL_malloc(sizeof(MTPNP_UINT16) * (g_frm_sms_cntx.mmi_frm_sms_msg_seg_size + 1));

	kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display");  //huyi-20080506
	if ((mmi_frm_sms_is_sms_valid() == FALSE)||(MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_ABSENT) || (MTPNP_AD_Get_Card2Status() == MTPNP_AD_SIMCARD_CHVBLOCKED) )       
	{
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);        
		kal_prompt_trace(MOD_MMI, "all sim invalid");
		
		return;
	}
	
    if (blink == MTPNP_TRUE)
    {
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);
        MTPNP_PFAL_Blink_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);
        MTPNP_PFAL_Refresh_StatusBar();

        kal_prompt_trace(MOD_MMI, "card2 sms display, blink");

        MTPNP_OSAL_memfree(l4_index);
        l4_index = MTPNP_NULL;
        return;
    }
    if (unblink == MTPNP_TRUE)
    {
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);
    }

    kal_prompt_trace(MOD_MMI, "card2 sms display");

    if (MTPNP_AD_Card2_SMS_Is_Avail())
    {
        if (totalinbox != MMI_FRM_SMS_INVALID_INDEX)
        {
            while (i < totalinbox)
            {
                mmi_frm_sms_get_sms_index(MMI_FRM_SMS_APP_INBOX, i, l4_index);
                *l4_index = MTPNP_PFAL_Msg_Get_valid_L4index(l4_index);
                if ((mmi_frm_sms_get_status(MMI_FRM_SMS_APP_INBOX, i) & 0x0f) == MMI_FRM_SMS_APP_UNREAD)
                {
                    kal_prompt_trace(MOD_MMI, "card2 sms display, index: %d", *l4_index);

                    if (*l4_index >= MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())   /* caution */
                    {
                        kal_prompt_trace(MOD_MMI, "card2 sms display, show icon");

                        MTPNP_PFAL_Show_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);
                        MTPNP_PFAL_Refresh_StatusBar();
			   /*begin add by lijianxin 080508*/
			   mmi_msg_count_unread_sms();   
			   if (sms_unread != 0)
			   {
//			   	mmi_show_nomal_index(2);   
			   }
			   /*end add by lijianxin 080508*/
                        MTPNP_OSAL_memfree(l4_index);
                        l4_index = MTPNP_NULL;
                        return;
                    }
                }
                i++;
            }
        }

        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);
    }
    MTPNP_PFAL_Refresh_StatusBar();

    MTPNP_OSAL_memfree(l4_index);
    l4_index = MTPNP_NULL;
}

void MTPNP_PFAL_EVT_SMS_Load_Begin_Ind(void *inMsg)
{
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_STARTUP_READ_GOING_IND, MTPNP_PFAL_EVT_SMS_Loading_Ind);
    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_STARTUP_READ_FINISH_IND, MTPNP_PFAL_EVT_SMS_Load_Finished_Ind);

    if (!MTPNP_AD_Msgbox_Is_Init())
    {
        MTPNP_PFAL_SMS_Init_Msgbox();
        MTPNP_AD_Msgbox_HasInit();
    }
	/* SIM refresh, unload slave SMS */
	else
	{
		MTPNP_PFAL_Slave_SMS_Unload();
	}
}

void MTPNP_PFAL_EVT_SMS_Loading_Ind(void *inMsg)
{        
	if (mmi_bootup_is_sim2_valid())
	{
	    ST_MTPNP_AD_SMS_LOAD_ONGOING *msg_ind = (ST_MTPNP_AD_SMS_LOAD_ONGOING *) inMsg;
	    MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *msg_start_read;
	    mmi_frm_sms_msgbox_struct *entry = MTPNP_OSAL_malloc(sizeof(mmi_frm_sms_msgbox_struct));
	    MTPNP_UINT8 seg = (msg_ind->concat_info & 0xff000000) >> 24;
	    MTPNP_UINT8 thisseg = ((seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size) == 0) ?
	        g_frm_sms_cntx.mmi_frm_sms_msg_seg_size : (seg % g_frm_sms_cntx.mmi_frm_sms_msg_seg_size);
	    MTPNP_UINT16 length;

	    MTPNP_OSAL_memset((MTPNP_CHAR *) entry, 0, sizeof(mmi_frm_sms_msgbox_struct));

	    length = sizeof(MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT) - 1 + msg_ind->no_msg_data;
	    msg_start_read = MTPNP_OSAL_malloc(length);
	    MTPNP_OSAL_memset(msg_start_read, 0x0, length);

	    MTPNP_PFAL_Convert_SMS_Loading_Data(msg_ind, msg_start_read);
	    mmi_frm_sms_convert_startup_read_to_entry(msg_start_read, entry);
		mmi_frm_sms_add_sms_to_msgbox(entry, msg_ind->index, thisseg);
	    MTPNP_OSAL_memfree(entry);
	    entry = MTPNP_NULL;
	    MTPNP_OSAL_memfree(msg_start_read);
	    msg_start_read = MTPNP_NULL;
	}    
}

void MTPNP_PFAL_EVT_SMS_Load_Finished_Ind(void *inMsg)
{
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_STARTUP_READ_GOING_IND);
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_STARTUP_READ_FINISH_IND);
	if (g_mmi_frm_sms_list_finish == TRUE)
	{
		mmi_frm_sms_create_sms_list();
	}
    /* refresh the statusbar sms display */
    MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
}

void MTPNP_PFAL_Message_Ready_Ind(void *inMsg)
{
    switch (MTPNP_AD_Get_Slave_Type())
    {
    case MTPNP_CM_PHS_MODULE:
        /* MDV PHS module */
        break;
    case MTPNP_CM_GSM_MODULE:
    case MTPNP_PC_SIMULATOR:
        /* MTK GSM module or MTK Modis simulator */
        mmi_frm_sms_get_card2_profile_list(NULL, MOD_MMI);
    #ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        mmi_frm_sms_get_card2_common_settings(NULL, MOD_MMI);
    #endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
        mmi_msg_pre_entry_card2_cb_channel_bootup();
        break;
    case MTPNP_CALIBRATION_TOOLS:
    case MTPNP_UNKNOWN_MODULE:
    default:
        break;
    }
	mmi_frm_sms_interrupt_callback(MOD_MMI, PRT_MSG_ID_MMI_SMS_READY_IND, NULL, MMI_FRM_SMS_OK);
}

void MTPNP_PFAL_Deliver_New_Msg_Ind(void *inMsg)
{
    ST_MTPNP_AD_DELIVER_SMS *msg_ind = (ST_MTPNP_AD_DELIVER_SMS *) inMsg;
    mmi_frm_sms_deliver_msg_struct *new_sms;
    MTPNP_UINT16 length = 0;

    length = sizeof(mmi_frm_sms_deliver_msg_struct);
    new_sms = MTPNP_OSAL_malloc(length);
    MTPNP_OSAL_memset(new_sms, 0x0, length);

    MTPNP_PFAL_Convert_Deliver_Msg(msg_ind, new_sms);

    /* put to awaited list last entry, from now on only process new data as awaited list last entry */
    mmi_frm_sms_add_new_sms(new_sms, msg_ind->no_msg_data, msg_ind->msg_data);

    /* process new sms data */
    mmi_frm_sms_new_sms();

    MTPNP_OSAL_memfree(new_sms);
    new_sms = MTPNP_NULL;
}

void MTPNP_PFAL_Deliver_New_App_Data_Ind(void *inMsg)
{
    ST_MTPNP_AD_APP_DATA *msg_ind = (ST_MTPNP_AD_APP_DATA *) inMsg;
    mmi_frm_sms_deliver_data_struct *new_data;
    MTPNP_UINT16 length = 0;

    length = sizeof(mmi_frm_sms_deliver_data_struct);
    new_data = MTPNP_OSAL_malloc(length);
    MTPNP_OSAL_memset(new_data, 0x0, length);

    MTPNP_PFAL_Convert_Deliver_App_Data(msg_ind, new_data);
    
    /* put to awaited list last entry, from now on only process new data as awaited list last entry */
    mmi_frm_sms_add_new_data(new_data, new_data->message_len, (U8 *)msg_ind->msg_data);

    /* process new sms data */
    mmi_frm_sms_new_data();

    MTPNP_OSAL_memfree(new_data);
    new_data = MTPNP_NULL;
}

void MTPNP_PFAL_Message_Memory_Full_Ind(void *inMsg)
{
    if ((MTPNP_AD_Get_Status() & MTPNP_AD_CARD2) == MTPNP_AD_CARD2)
    {
        MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
    }
}

void MTPNP_PFAL_Message_Memory_Avail_Ind(void *inMsg)
{
    MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_TRUE);
}

void MTPNP_PFAL_Message_Memory_Exceed_Ind(void *inMsg)
{
    MTPNP_UINT8 *type = (MTPNP_UINT8 *) inMsg;

    MTPNP_PFAL_Turnon_Backlight(MTPNP_GPIO_BACKLIGHT_SHORT_TIME);
    g_msg_cntx.msg_exceed_type = *type;
	g_msg_cntx.msg_exceed_ind = TRUE;
	g_msg_cntx.msg_exceed_from_slave = TRUE;
    if (IsMMIInIdleState())
    {
        ClearKeyEvents();
        if (IsKeyPadLockState())
        {
            EntryIdleScreen();
        }
        else
        {
            MTPNP_PFAL_Entry_Slave_Mem_Exceed_Ind(*type);
        }
    }
}

void MTPNP_PFAL_Message_Status_Report_Ind(void *inMsg)
{
    ST_MTPNP_AD_SMS_STATUS_REPORT *msg_ind = (ST_MTPNP_AD_SMS_STATUS_REPORT *) inMsg;
    mmi_frm_sms_status_report_ind_struct *l4Msg;

    kal_prompt_trace(MOD_MMI, "[LJH]slave mr=%d", msg_ind->mr);

    l4Msg = MTPNP_OSAL_malloc(sizeof(mmi_frm_sms_status_report_ind_struct));
    MTPNP_PFAL_Convert_SMS_Status_Report_Ind(msg_ind, l4Msg);

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    {
        MTPNP_UINT8 msg_ref = msg_ind->mr;
        MTPNP_UINT16 delivery_report_awaited_index;

        delivery_report_awaited_index = mmi_frm_sms_get_delivery_report_index_by_mr(msg_ref);

        kal_prompt_trace(MOD_MMI, "[LJH]delivery_report_awaited_index=%d", delivery_report_awaited_index);

        /* mr is in delivery report awaited list */
        if (delivery_report_awaited_index != mmi_frm_get_sms_action_size())
        {
            mmi_frm_sms_set_delivery_report_awaited_check(delivery_report_awaited_index, msg_ref, msg_ind->st);

            if (mmi_frm_sms_check_delivery_report_awaited_complete(delivery_report_awaited_index))
            {
                MTPNP_AD_SMS_Report_Status_From_Card2();

                msg_ind->st = mmi_frm_sms_get_delivery_report_awaited_result(delivery_report_awaited_index);
                mmi_frm_sms_remove_delivery_report_awaited(delivery_report_awaited_index);

                mmi_frm_sms_convert_time_stamp(l4Msg->dt, l4Msg->dt);
                mmi_frm_sms_common_status_report_ind(l4Msg);
            }
        }
        /* Also indicate user if the mr is not in delivery report awaited list */
        /* For the case that the sending maybe aborted but actually the SMS is sent */
        else
        {
            MTPNP_AD_SMS_Report_Status_From_Card2();
            mmi_frm_sms_convert_time_stamp(l4Msg->dt, l4Msg->dt);
            mmi_frm_sms_common_status_report_ind(l4Msg);
        }
    }
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    MTPNP_AD_SMS_Report_Status_From_Card2();
    mmi_frm_sms_convert_time_stamp(l4Msg->dt, l4Msg->dt);
    mmi_frm_sms_common_status_report_ind(l4Msg);
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

    MTPNP_OSAL_memfree(l4Msg);
    l4Msg = MTPNP_NULL;
}

void MTPNP_PFAL_Entry_Slave_Mem_Exceed_Ind(MTPNP_UINT8 type)
{
    MTPNP_UINT16 str_id = 0;

    if (type == MTPNP_AD_MEM_EXCEED_NORMAL)
    {
        str_id = STRING_MTPNP_SLAVE_SMS_MEMORY_EXCEEDED;
    }
    else if (type == SMSAL_SM_EXCEED_WITH_CLASS2)
    {
        str_id = STRING_MTPNP_SLAVE_SMS_SIM_MEMORY_EXCEEDED;
    }

    EntryNewScreen(SCR_ID_MSG_EXCEED_IND, NULL, NULL, NULL);

    if (IsKeyPadLockState() == 0)
    {
        GetCurrEndKeyDownHandler();
        ShowCategory2Screen(STR_SCR6042_CAPTION,
                            IMG_SMS_ENTRY_SCRN_CAPTION, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, str_id, MTPNP_NULL);
        SetRightSoftkeyFunction(mmi_msg_go_back_from_mem_exceed_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_go_back_from_mem_exceed_ind, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_end_key_from_mem_exceed_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        ShowCategory2Screen(STR_SCR6042_CAPTION,
                            IMG_SMS_ENTRY_SCRN_CAPTION,
                            g_keylock_context.KeyLockLSKStringID,
                            g_keylock_context.KeyLockLSKIconID,
                            g_keylock_context.KeyLockRSKStringID,
                            g_keylock_context.KeyLockRSKIconID, str_id, MTPNP_NULL);
    }
}

MTPNP_BOOL MTPNP_PFAL_Read_SMS_Segment(void)
{
    while (PendingSaveSendData.nextSegment < g_frm_sms_cntx.mmi_frm_sms_msg_seg_size)
    {
        if (PendingSaveSendData.l4index[PendingSaveSendData.nextSegment] != MMI_FRM_SMS_INVALID_INDEX)
        {
            MMI_FRM_SMS_GET_MSG_REQ_STRUCT *msgReq;

            msgReq = (MMI_FRM_SMS_GET_MSG_REQ_STRUCT *) OslConstructDataPtr(sizeof(*msgReq));

            msgReq->ref_count = 1;
            msgReq->msg_len = sizeof(MMI_FRM_SMS_GET_MSG_REQ_STRUCT);

            msgReq->index = PendingSaveSendData.l4index[PendingSaveSendData.nextSegment];
            msgReq->change_status = g_mmi_frm_sms_change_status;
            if (msgReq->index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
            {
                /* the idx is master, read message from master */
                MTPNP_PFAL_Active_Slave_SMS(MTPNP_FALSE);

                SetProtocolEventHandler(MTPNP_PFAL_Card1_Read_SMS_Rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_RSP);
                mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_REQ, (oslParaType *) msgReq,
                                         NULL);
            }
            else
            {
                /* the idx is slave, read message from slave */
                MTPNP_PFAL_Active_Slave_SMS(MTPNP_TRUE);

                msgReq->index = MTPNP_AD_Get_SIM2_Index(msgReq->index);
                MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MSG_RSP, MTPNP_PFAL_MMI_SMS_Read_Msg_Rsp);
                MTPNP_AD_Get_SMS(msgReq->index, msgReq->change_status);
                /* need free buffer */
                MTPNP_PFAL_Free_Local_Buffer((void *) msgReq);
                msgReq = MTPNP_NULL;
            }
            PendingSaveSendData.presentSegments = PendingSaveSendData.nextSegment;
            PendingSaveSendData.nextSegment++;
            return MTPNP_TRUE;
        }
        PendingSaveSendData.nextSegment++;
    }
    return MTPNP_FALSE;
}

MTPNP_BOOL MTPNP_PFAL_Send_Message_Segment(void *seg)
{
    ST_MTPNP_AD_SMS_SEND_MSG sms;
    if (seg == MTPNP_NULL)
        return MTPNP_FALSE;

    if (!MTPNP_PFAL_Convert_Send_Data(MTPNP_FALSE, seg, &sms))
    {
        /* need free buffer */
        MTPNP_PFAL_Free_Local_Buffer((void *) seg);
        seg = MTPNP_NULL;

        return MTPNP_FALSE;
    }

    /* need free buffer */
    MTPNP_PFAL_Free_Local_Buffer((void *) seg);
    seg = MTPNP_NULL;

    return MTPNP_AD_Send_SMS(&sms);
}

void MTPNP_PFAL_Send_Message_Succeed(void *inMsg)
{
    ST_MTPNP_AD_SMS_SEND_RSP *msg_rsp = (ST_MTPNP_AD_SMS_SEND_RSP *) inMsg;
    MMI_FRM_SMS_SEND_MSG_RSP_STRUCT msg_send_rsp;

    MTPNP_OSAL_memset(&msg_send_rsp, 0, sizeof(MMI_FRM_SMS_SEND_MSG_RSP_STRUCT));
    if (msg_rsp == MTPNP_NULL)
    {
        msg_send_rsp.result = MTPNP_TRUE;
    }
    else
    {
        MTPNP_PFAL_Convert_SendRsp_Msg((void *) msg_rsp, (void *) &msg_send_rsp);
    }

    mmi_frm_sms_send_sms_rsp(&msg_send_rsp);
}

void MTPNP_PFAL_Send_Message_Failed(void *inMsg)
{
    ST_MTPNP_AD_SMS_SEND_RSP *msg_rsp = (ST_MTPNP_AD_SMS_SEND_RSP *) inMsg;
    MMI_FRM_SMS_SEND_MSG_RSP_STRUCT msg_send_rsp;

    MTPNP_OSAL_memset(&msg_send_rsp, 0, sizeof(MMI_FRM_SMS_SEND_MSG_RSP_STRUCT));
    if (msg_rsp == MTPNP_NULL)
    {
        msg_send_rsp.result = MTPNP_FALSE;
    }
    else
    {
        MTPNP_PFAL_Convert_SendRsp_Msg((void *) msg_rsp, (void *) &msg_send_rsp);
    }

    mmi_frm_sms_send_sms_rsp((void *) &msg_send_rsp);
}

void MTPNP_PFAL_Abort_SMS_Req(void)
{
    mmi_frm_sms_abort_sms_req(MTPNP_NULL);
}

void MTPNP_PFAL_Abort_SMS_Rsp(void *inMsg)
{
    MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT abort_rsp;
    MTPNP_UINT8 *result = (MTPNP_UINT8 *) inMsg;

    abort_rsp.result = *result;

    mmi_frm_sms_abort_sms_rsp((void *) &abort_rsp);
}

MTPNP_BOOL MTPNP_PFAL_Save_Message(void *seg)
{
    ST_MTPNP_AD_SMS_SAVE_MSG sms;

    if (!MTPNP_PFAL_Convert_Save_SMS(seg, &sms))
    {
        /* need free control buffer */
        MTPNP_PFAL_Free_Local_Buffer((void *) seg);
        seg = MTPNP_NULL;
        return MTPNP_FALSE;
    }

    /* need free control buffer */
    MTPNP_PFAL_Free_Local_Buffer((void *) seg);
    seg = MTPNP_NULL;

    return MTPNP_AD_Save_SMS(&sms);
}

void MTPNP_PFAL_Save_Message_Rsp(void *inMsg)
{
    ST_MTPNP_AD_SMS_SAVE_RSP *msg_rsp = (ST_MTPNP_AD_SMS_SAVE_RSP *) inMsg;
    MMI_FRM_SMS_SET_MSG_RSP_STRUCT msg_save_rsp;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_SET_MSG_RSP);

    MTPNP_PFAL_Convert_SaveSMSRsp_Msg((void *) msg_rsp, (void *) &msg_save_rsp);

    mmi_frm_sms_save_sms_rsp((void *) &msg_save_rsp);
}

void MTPNP_PFAL_MMI_SMS_Read_Msg_Rsp(void *inMsg)
{
    MMI_FRM_SMS_GET_MSG_RSP_STRUCT *sms_record;
    ST_MTPNP_AD_SMS_GET_RSP *msg_rsp = (ST_MTPNP_AD_SMS_GET_RSP *) inMsg;
    MTPNP_UINT16 length;

	if (msg_rsp->result == MTPNP_FALSE)
	{
		msg_rsp->no_msg_data = 0;
	}
    length = sizeof(MMI_FRM_SMS_GET_MSG_RSP_STRUCT) - 1 + msg_rsp->no_msg_data;
    sms_record = MTPNP_OSAL_malloc(length);
    MTPNP_OSAL_memset(sms_record, 0x0, length);

    MTPNP_PFAL_Convert_Get_SMS_Data(msg_rsp, sms_record);

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MSG_RSP);

    MTPNP_PFAL_Card1_Read_SMS_Rsp((void *) sms_record);

    MTPNP_OSAL_memfree(sms_record);
    sms_record = MTPNP_NULL;
}

void MTPNP_PFAL_Delete_Slave_SMS_Req(void *bitmap)
{
    ST_MTPNP_AD_SMS_DEL_REQ *msg_req;
    MTPNP_UINT8 *index = (MTPNP_UINT8 *) bitmap;
    MTPNP_UINT16 length = 0;

    length = sizeof(ST_MTPNP_AD_SMS_DEL_REQ) - 1 + 480;
    msg_req = MTPNP_OSAL_malloc(length);
    msg_req->del_flag = SMSAL_DEL_BITMAP;
    msg_req->bitmap_len = 480;
    MTPNP_OSAL_memcpy((MTPNP_CHAR *) msg_req->del_bitmap, (MTPNP_CHAR *) index, 480);

    MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_DEL_MSG_RSP, MTPNP_PFAL_Delete_Slave_SMS_Rsp);
    MTPNP_AD_Delete_SMS(msg_req);

    MTPNP_OSAL_memfree(msg_req);
    msg_req = MTPNP_NULL;
    MTPNP_OSAL_memfree(index);
    index = MTPNP_NULL;
}

void MTPNP_PFAL_Delete_Slave_SMS_Rsp(void *inMsg)
{
    ST_MTPNP_AD_SMS_DEL_RSP *msg_rsp = (ST_MTPNP_AD_SMS_DEL_RSP *) inMsg;
    MTPNP_UINT16 result = MMI_FRM_SMS_ERROR;
    MTPNP_UINT8 *bitmap;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_DEL_MSG_RSP);

    bitmap = MTPNP_OSAL_malloc(480);

    MTPNP_OSAL_memcpy(bitmap, msg_rsp->del_bitmap, 480);

    if (msg_rsp->result)
    {
        result = MMI_FRM_SMS_OK;
        mmi_frm_sms_remove_slave_sms_from_msgbox(bitmap);
    }

    MTPNP_OSAL_memfree(bitmap);
    bitmap = MTPNP_NULL;

    MTPNP_PFAL_Set_Msgs_DelAll_State(DM_SLAVE_BOX);

    mmi_frm_sms_callback_action(MTPNP_NULL, result);

    MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
}

#ifdef __MMI_MESSAGES_COPY__
void MTPNP_PFAL_SMS_Init_Copy_Index(void)
{
    if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_ALL)
    {
        g_frm_sms_copy_info.present_msg_index = 0;
    }
    else
    {
        sms_copy_index = 0;
        g_frm_sms_copy_info.present_msg_index = mmi_frm_sms_show_list_index[sms_copy_index];
    }
}

void MTPNP_PFAL_SMS_Increment_Copy_Index(void)
{
    if (MTPNP_AD_SMS_Get_Filter_Rule() == MTPNP_AD_FILTER_ALL)
    {
        g_frm_sms_copy_info.present_msg_index++;
    }
    else
    {
        sms_copy_index++;
        g_frm_sms_copy_info.present_msg_index = mmi_frm_sms_show_list_index[sms_copy_index];
    }
}

void MTPNP_PFAL_SMS_adjust_Copy_Index(U16 index)
{
    if (MTPNP_AD_SMS_Get_Filter_Rule() != MTPNP_AD_FILTER_ALL)
    {
    	sms_copy_index += index;
    }   
}


void MTPNP_PFAL_Pre_Copy_SMS_Req(void)
{
    if (mmi_frm_sms_record_is_slave_sms(g_frm_sms_copy_info.msg_list_type, g_frm_sms_copy_info.present_msg_index))
    {
        MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MSG_NUM_RSP, MTPNP_PFAL_Pre_Copy_SMS_Rsp);
        MTPNP_AD_SMS_Get_MSG_Num_Req();
    }
    else
    {
        SetProtocolEventHandler(mmi_frm_sms_pre_copy_sms_rsp, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_RSP);
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_GET_MSG_NUM_REQ, NULL, NULL);
    }
}

void MTPNP_PFAL_Pre_Copy_SMS_Rsp(void *inMsg)
{
    ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP *msgRsp = (ST_MTPNP_AD_SMS_GET_MSG_NUM_RSP *) inMsg;
    mmi_sms_get_msg_num_rsp_struct get_rsp;

    get_rsp.result = msgRsp->result;
    get_rsp.is_sim_card_change = msgRsp->is_sim_card_change;
    get_rsp.in_sim_no = msgRsp->in_sim_no;
    get_rsp.in_me_no = msgRsp->in_me_no;
    get_rsp.out_sim_no = msgRsp->out_sim_no;
    get_rsp.out_me_no = msgRsp->out_me_no;
    get_rsp.unread_msg_num = msgRsp->unread_msg_num;
    get_rsp.total_sim_num = msgRsp->total_sim_num;
    get_rsp.total_me_num = msgRsp->total_me_num;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_GET_MSG_NUM_RSP);
    mmi_frm_sms_pre_copy_sms_rsp((void *) &get_rsp);
}

void MTPNP_PFAL_Copy_SMS_Req(mmi_sms_copy_msg_req_struct * msgReq)
{
    if (msgReq->src_index < MTPNP_AD_Get_Card2_StartIdx_In_Msgbox())
    {
        SetProtocolEventHandler(mmi_frm_sms_copy_sms_seg_rsp, PRT_MSG_ID_MMI_SMS_COPY_MSG_RSP);
        mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_COPY_MSG_REQ, (oslParaType *) msgReq, NULL);
    }
    else
    {
        ST_MTPNP_AD_SMS_COPY_REQ copy_req;

        copy_req.action = msgReq->action;
        copy_req.dst_storage = msgReq->dst_storage;

        copy_req.src_index = MTPNP_AD_Get_SIM2_Index(msgReq->src_index);

        MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_COPY_MSG_RSP, MTPNP_PFAL_EVT_Copy_SMS_Rsp);
        MTPNP_AD_Copy_SMS(&copy_req);
        MTPNP_PFAL_Free_Local_Buffer((void *) msgReq);
        msgReq = MTPNP_NULL;
    }
}

void MTPNP_PFAL_EVT_Copy_SMS_Rsp(void *inMsg)
{
    ST_MTPNP_AD_SMS_COPY_RSP *msgRsp = (ST_MTPNP_AD_SMS_COPY_RSP *) inMsg;
    mmi_sms_copy_msg_rsp_struct copy_rsp;

    copy_rsp.result = msgRsp->result;
    copy_rsp.cause = msgRsp->cause;
    copy_rsp.action = msgRsp->action;
    copy_rsp.dst_storage = msgRsp->dst_storage;

    copy_rsp.src_index = MTPNP_AD_Set_SIM2_Index(msgRsp->src_index);
    copy_rsp.dst_index = MTPNP_AD_Set_SIM2_Index(msgRsp->dst_index);
    
    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_COPY_MSG_RSP);
    mmi_frm_sms_copy_sms_seg_rsp((void *) &copy_rsp);
}

void MTPNP_PFAL_Copy_SMS_Move_Req(void)
{
    U8 *data = OslMalloc(sizeof(U8) * 480);
    U16 deleteMsgIndex = 0;

    deleteMsgIndex = g_frm_sms_copy_info.present_msg_index;
    memset((S8 *) data, 0, sizeof(U8) * 480);

    if (mmi_frm_sms_record_is_slave_sms(g_frm_sms_copy_info.msg_list_type, g_frm_sms_copy_info.present_msg_index))
    {
        if (mmi_frm_sms_get_slave_sms_bitmap(g_frm_sms_copy_info.msg_list_type, deleteMsgIndex, data) == FALSE)
        {
            OslMfree(data);
            mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ERROR, MMI_FRM_SMS_ERROR);
        }
        else
        {
            ST_MTPNP_AD_SMS_DEL_REQ *del_req;

            del_req = (ST_MTPNP_AD_SMS_DEL_REQ *) MTPNP_OSAL_malloc(sizeof(ST_MTPNP_AD_SMS_DEL_REQ) - 1 + 480);
            del_req->del_flag = SMSAL_DEL_BITMAP;
            del_req->bitmap_len = 480;
            MTPNP_OSAL_memcpy((MTPNP_CHAR *) del_req->del_bitmap, (MTPNP_CHAR *) data, 480);
            OslMfree(data);

            MTPNP_PFAL_Register_Event_Handler(MTPNP_PFAL_MSG_SMS_DEL_MSG_RSP, MTPNP_PFAL_Copy_SMS_Move_Rsp);
            MTPNP_AD_Delete_SMS(del_req);

            MTPNP_OSAL_memfree(del_req);
            del_req = MTPNP_NULL;
        }
    }
    else
    {
        if (mmi_frm_sms_get_sms_bitmap(g_frm_sms_copy_info.msg_list_type, deleteMsgIndex, data) == FALSE)
        {
            OslMfree(data);
            mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_ERROR, MMI_FRM_SMS_ERROR);
        }
        else
        {
            MMI_FRM_SMS_DEL_MSG_REQ_STRUCT *msgReq;

            msgReq = (MMI_FRM_SMS_DEL_MSG_REQ_STRUCT *) OslConstructDataPtr(sizeof(*msgReq));
            msgReq->del_flag = SMSAL_DEL_BITMAP;
            memcpy((S8 *) msgReq->del_bitmap, (S8 *) data, 480);
            OslMfree(data);

            SetProtocolEventHandler(mmi_frm_sms_copy_sms_move_rsp, PRT_MSG_ID_MMI_SMS_DEL_MSG_RSP);
            mmi_frm_sms_send_message(MOD_MMI, MOD_L4C, 0, PRT_MSG_ID_MMI_SMS_DEL_MSG_REQ, (oslParaType *) msgReq, NULL);
        }
    }
}

void MTPNP_PFAL_Copy_SMS_Move_Rsp(void *inMsg)
{
    ST_MTPNP_AD_SMS_DEL_RSP *msgRsp = (ST_MTPNP_AD_SMS_DEL_RSP *) inMsg;
    U8 result = MMI_FRM_SMS_ERROR;

    MTPNP_PFAL_Remove_Event_Handler(MTPNP_PFAL_MSG_SMS_DEL_MSG_RSP);
    if (msgRsp->result == TRUE)
    {
        result = MMI_FRM_SMS_OK;
        mmi_frm_sms_remove_slave_sms_from_msgbox(msgRsp->del_bitmap);

        g_frm_sms_copy_info.copy_msg_number++;
        g_frm_sms_copy_info.present_L4_index = MMI_FRM_SMS_INVALID_INDEX;
        g_frm_sms_copy_info.dst_msg_index = MMI_FRM_SMS_INVALID_INDEX;
        g_frm_sms_copy_info.handled_msg_number++;
        /* all msgs are handled */
        if (g_frm_sms_copy_info.handled_msg_number >= g_frm_sms_copy_info.total_msg_number)
        {
            if (g_frm_sms_copy_info.is_memory_full)
            {
                mmi_frm_sms_copy_sms_callback(MMI_FRM_SMS_MEMFULL, MMI_FRM_SMS_MEMFULL);
            }
            else
            {
                mmi_frm_sms_copy_sms_callback((U16) result, result);
            }
            return;
        }
        /* handle the next msg */
        else
        {
            mmi_frm_sms_pre_copy_sms_req(NULL);
            return;
        }
    }
    else
    {
        mmi_frm_sms_copy_sms_callback((U16) result, result);
    }

}
#endif /* __MMI_MESSAGES_COPY__ */

void MTPNP_PFAL_Init_Msgs_DelAll_State(MTPNP_UINT8 side)
{
    g_msgs_delall_state = side;
}

void MTPNP_PFAL_Set_Msgs_DelAll_State(MTPNP_UINT8 side)
{
    g_msgs_delall_state &= ~side;
}

MTPNP_UINT8 MTPNP_PFAL_Get_Msgs_DelAll_State(void)
{
    return g_msgs_delall_state;
}

void MTPNP_PFAL_Slave_SMS_Unload(void)
{
    MTPNP_UINT16 i;
    MTPNP_UINT16 sim2_idx_start;

    sim2_idx_start = MTPNP_AD_Get_Card2_StartIdx_In_Msgbox();

    for (i=sim2_idx_start; i<MMI_SMS_MAX_MSG_NUM; i++)
    {
        mmi_frm_sms_handle_sms_refresh(i);
    }
}

void MTPNP_PFAL_Master_SMS_Unload(void)
{
    MTPNP_UINT16 i;
    MTPNP_UINT16 sim2_idx_start;

    sim2_idx_start = MTPNP_AD_Get_Card2_StartIdx_In_Msgbox();

    for (i = 0; i < sim2_idx_start; i++)
    {
        mmi_frm_sms_handle_sms_refresh(i);
    }
	MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
}


void MTPNP_PFAL_Set_SMS_Waiting_Icon(MTPNP_UINT16 index)
{
	MTPNP_UINT8 i;

	if (index < STATUS_ICON_UNREAD_VOICE_L1_MASTER || index > STATUS_ICON_UNREAD_NET_L1L2_SLAVE)
	{
		return;
	}
	i = (MTPNP_UINT8)(index - STATUS_ICON_UNREAD_VOICE_L1_MASTER);
	g_sms_wait_icon |= 1<<i;
}

void  MTPNP_PFAL_Reset_SMS_Waiting_Icon(MTPNP_UINT16 index)
{
	MTPNP_UINT8 i;
	if (index < STATUS_ICON_UNREAD_VOICE_L1_MASTER || index > STATUS_ICON_UNREAD_NET_L1L2_SLAVE)
	{
		return;
	}
	i = (MTPNP_UINT8)(index - STATUS_ICON_UNREAD_VOICE_L1_MASTER);
	g_sms_wait_icon &= ~(1<<i);
}

void MTPNP_PFAL_check_SMS_Waiting_Icon(void)
{	
	MTPNP_UINT16 i = 0;	
	kal_prompt_trace(MOD_MMI, "MTPNP_PFAL_check_SMS_Waiting_Icon i=%d", i);
	kal_prompt_trace(MOD_MMI, " g_sms_wait_icon= %d", g_sms_wait_icon);
	kal_prompt_trace(MOD_MMI, " mmi_frm_sms_is_sms_valid= %d", mmi_frm_sms_is_sms_valid());
	kal_prompt_trace(MOD_MMI, " mmi_bootup_is_sim2_valid= %d", mmi_bootup_is_sim2_valid());
	for (i = 0; i < 24; i++)
	{
        kal_prompt_trace(MOD_MMI, " i= %d", i);
		HideStatusIcon((S16)(STATUS_ICON_UNREAD_VOICE_L1_MASTER + i));
		if (mmi_frm_sms_is_sms_valid())
		{
			if (i < 12)
			{
				if (((g_sms_wait_icon>>i)&0x01) && mmi_bootup_is_sim_valid())
				{
                    kal_prompt_trace(MOD_MMI, " master i= %d", i);
					ShowStatusIcon((S16)(STATUS_ICON_UNREAD_VOICE_L1_MASTER + i));									
				}		
			}
			else
			{
				if (((g_sms_wait_icon>>i)&0x01) && mmi_bootup_is_sim2_valid())
				{
                    kal_prompt_trace(MOD_MMI, " slave i= %d", i);
					ShowStatusIcon((S16)(STATUS_ICON_UNREAD_VOICE_L1_MASTER + i));			
				}	
			}
		}
	}
    UpdateStatusIcons();
}
#endif /* __MMI_DUAL_SIM_MASTER__ */
