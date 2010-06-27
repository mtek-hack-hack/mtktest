#ifndef __MTPNP_PFAL_MESSAGESETUP_H__
#define __MTPNP_PFAL_MESSAGESETUP_H__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

extern void MTPNP_PFAL_InitMessageSetup(void);
extern void MTPNP_PFAL_SMS_Init_Show_Style(void);
extern void mmi_frm_sms_get_card2_sc_addr_req(void *inMsg);
extern void mmi_frm_sms_get_card2_profile_list(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_get_card2_common_settings(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_entry_card2_sc(void);

extern void mmi_msg_pre_entry_master_inbox_list(void);
extern void mmi_msg_pre_entry_slave_inbox_list(void);
extern void mmi_msg_pre_entry_master_outbox_list(void);
extern void mmi_msg_pre_entry_slave_outbox_list(void);
extern U16 MTPNP_PFAL_SMS_Get_SMS_List_Size(U8 type);
extern void MTPNP_PFAL_SMS_Set_Current_Index(S32 nIndex);
extern S32 MTPNP_PFAL_SMS_Get_Current_Index(void);
extern void RefreshSMSDividedMenuList(void);

#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MTPNP_PFAL_MESSAGESETUP_H__ */
