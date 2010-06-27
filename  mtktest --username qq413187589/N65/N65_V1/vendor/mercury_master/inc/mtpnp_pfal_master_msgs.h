#ifndef __MTPNP_PFAL_CUSTOM_SMS_H__
#define __MTPNP_PFAL_CUSTOM_SMS_H__

#ifdef __MMI_DUAL_SIM_MASTER__

/*MTK header file*/
#include "l4dr.h"

#include  "PixtelDataTypes.h"
#include "MessagesL4Def.h"
#include "MessagesMiscell.h"
#include "Gui_data_types.h"
#include "ems.h"
/*MTK header file*/

#include "MTPNP_AD_master_header.h"

typedef enum
{
    DM_MASTER_BOX = 0x01,
    DM_SLAVE_BOX = 0x02,
    DM_MIX_BOX = 0x03,
    
    DM_INVALID_BOX = 0xffff
} E_DUALMODE_MSGS_BOX;

void MTPNP_PFAL_Master_SMS_Init(void);
void HightlightSlaveMsgDone(void);
void mmi_msg_highlight_SIM2_send_outbox(void);
void HightlightDualModeMsgBoxForward(void);
void HightlightMsgBoxMasterForward(void);
void HightlightMsgBoxSlaveForward(void);
#if (defined(__MMI_VCALENDAR__) && !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__))
void HighlightVclndrSendBySms(void);
#endif /* defined(__MMI_VCALENDAR__) && !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */

void mmi_msg_entry_SIM2_send_option_outbox(void);
void EntryDualModeMsgBoxForward(void);

void MTPNP_PFAL_Active_Slave_SMS(MTPNP_BOOL flag);
MTPNP_BOOL MTPNP_PFAL_Active_SMS_Is_Slave(void);

extern S32 MTPNP_PFAL_Msg_Inbox_List_Get_Hint(S32 item_index, UI_string_type * hint_array);
MTPNP_UINT16 MTPNP_PFAL_Msg_Get_valid_L4index(MTPNP_UINT16 *l4_index);
MTPNP_BOOL MTPNP_PFAL_Msg_Inbox_List_Get_Item(MTPNP_INT32 item_index,
                                              UI_string_type str_buff,
                                              MTPNP_UINT8 ** img_buff_p, MTPNP_UINT8 str_img_mask);
MTPNP_BOOL MTPNP_PFAL_Msg_Outbox_List_Get_Item(MTPNP_INT32 item_index,
                                               UI_string_type str_buff,
                                               MTPNP_UINT8 ** img_buff_p, MTPNP_UINT8 str_img_mask);

void MTPNP_PFAL_EVT_SMS_Load_Begin_Ind(void *inMsg);
void MTPNP_PFAL_EVT_SMS_Loading_Ind(void *inMsg);
void MTPNP_PFAL_EVT_SMS_Load_Finished_Ind(void *inMsg);
void MTPNP_PFAL_Message_Ready_Ind(void *inMsg);
void MTPNP_PFAL_Deliver_New_Msg_Ind(void *inMsg);
void MTPNP_PFAL_Deliver_New_App_Data_Ind(void *inMsg);
void MTPNP_PFAL_Message_Memory_Full_Ind(void *inMsg);
void MTPNP_PFAL_Message_Memory_Avail_Ind(void *inMsg);
void MTPNP_PFAL_Message_Memory_Exceed_Ind(void *inMsg);
void MTPNP_PFAL_Message_Status_Report_Ind(void *inMsg);

MTPNP_BOOL MTPNP_PFAL_Send_Message_Segment(void *seg);
void MTPNP_PFAL_Send_Message_Succeed(void *inMsg);
void MTPNP_PFAL_Send_Message_Failed(void *inMsg);
void MTPNP_PFAL_Abort_SMS_Req(void);
void MTPNP_PFAL_Abort_SMS_Rsp(void *inMsg);
MTPNP_BOOL MTPNP_PFAL_Save_Message(void *seg);
void MTPNP_PFAL_Save_Message_Rsp(void *inMsg);
void MTPNP_PFAL_MMI_SMS_Read_Msg_Rsp(void *inMsg);
void MTPNP_PFAL_Entry_Slave_Mem_Exceed_Ind(MTPNP_UINT8 type);
void MTPNP_PFAL_Delete_Slave_SMS_Req(void *bitmap);
void MTPNP_PFAL_Delete_Slave_SMS_Rsp(void *inMsg);

#ifdef __MMI_MESSAGES_COPY__
void MTPNP_PFAL_SMS_Init_Copy_Index(void);
void MTPNP_PFAL_SMS_Increment_Copy_Index(void);
void MTPNP_PFAL_SMS_adjust_Copy_Index(U16 index);
void MTPNP_PFAL_Pre_Copy_SMS_Req(void);
void MTPNP_PFAL_Pre_Copy_SMS_Rsp(void *inMsg);
void MTPNP_PFAL_Copy_SMS_Req(mmi_sms_copy_msg_req_struct * msgReq);
void MTPNP_PFAL_EVT_Copy_SMS_Rsp(void *inMsg);
void MTPNP_PFAL_Copy_SMS_Move_Req(void);
void MTPNP_PFAL_Copy_SMS_Move_Rsp(void *inMsg);
#endif /* __MMI_MESSAGES_COPY__ */

void MTPNP_PFAL_Init_Msgs_DelAll_State(MTPNP_UINT8 side);
void MTPNP_PFAL_Set_Msgs_DelAll_State(MTPNP_UINT8 side);
MTPNP_UINT8 MTPNP_PFAL_Get_Msgs_DelAll_State(void);

void MTPNP_PFAL_Slave_SMS_Unload(void);
void MTPNP_PFAL_Master_SMS_Unload(void);
void MTPNP_PFAL_check_SMS_Waiting_Icon(void);
void MTPNP_PFAL_Set_SMS_Waiting_Icon(MTPNP_UINT16 index);
void  MTPNP_PFAL_Reset_SMS_Waiting_Icon(MTPNP_UINT16 index);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_CUSTOM_SMS_H__ */
