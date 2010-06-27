#ifndef __MTPNP_PFAL_CARD2_MSISDN_H__
#define __MTPNP_PFAL_CARD2_MSISDN_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

void MTPNP_PFAL_MSISDN_Init(void);
void HighlightCard2PhbExtra(void);
void EntryCard2PhbExtra(void);
void ExitCard2PhbExtra(void);
void HighlightCard2OwnerNumber(void);
/* SDN begin*/
void HighlightCard2SDLNumber(void);
void mmi_phb_sim2_sdn_list_pre_entry(void);
void mmi_phb_sim2_sdn_get_entry_req(void);
void mmi_phb_sim2_sdn_get_entry_rsp(void *info);
void mmi_phb_sim2_entry_sdn_list(void);
void mmi_phb_sim2_exit_sdn_list(void);
void mmi_phb_sim2_sdn_list_make_call(void);
/* SDN end */
/* SOS begin */
void HighlightCard2SOSNumber(void);
void mmi_phb_sim2_sos_list_pre_entry(void);
void mmi_phb_sim2_sos_list_get_entry_req(void);
void mmi_phb_sim2_sos_list_get_entry_rsp(void *info);
void mmi_phb_sim2_entry_sos_list(void);
void mmi_phb_sim2_exit_sos_list(void);
void mmi_phb_sim2_sos_list_get_index(S32 index);
void mmi_phb_sim2_sos_list_pre_confirm_call(void);
void mmi_phb_sim2_entry_sos_list_confirm_call(void);
void mmi_phb_sim2_sos_list_make_call(void);
/* SOS end */
void HighlightCard2ShowOwnerNumber(void);
void MTPNP_PFAL_Update_Card2_Owner_Number_Record(void);
void MTPNP_PFAL_Toggle_Card2ShowOwnNo(void);
void MTPNP_PFAL_Owner_Number_Pre_Entry(void);
void MTPNP_PFAL_Owner_Number_Prepare(void);
void MTPNP_PFAL_Entry_Owner_Number(void);
void MTPNP_PFAL_Refresh_Card2_Owner_Number(void);
void MTPNP_PFAL_MSISDN_Load_Finished(void *inMsg);
void MTPNP_PFAL_MSISDN_Load_Failed(void *inMsg);

void EntryCard2OwnerNumber(void);
void MTPNP_PFAL_Entry_Card2_Owner_Number_Option(void);
void MTPNP_PFAL_Exit_Card2_Owner_Number_Option(void);
void HighlightCard2OwnerNumberErase(void);
void HighlightCard2OwnerNumberEdit(void);
void MTPNP_PFAL_Card2_Owner_Number_Erase_Prepare(void);
void MTPNP_PFAL_Card2_Owner_Number_Erase_Confirm(void);
void MTPNP_PFAL_Card2_Erase_MSISDN_Record(void);
void MTPNP_PFAL_Erase_Card2_MSISDN_Record_Succeed(void *inMsg);
void MTPNP_PFAL_Erase_Card2_MSISDN_Record_Failed(void *inMsg);
void MTPNP_PFAL_Card2_Owner_Number_Edit_Prepare(void);
void EntryCard2OwnerNumberEdit(void);
void ExitCard2OwnerNumberEdit(void);
void MTPNP_PFAL_Card2_Owner_Number_Update_Confirm(void);
void MTPNP_PFAL_Card2_Update_MSISDN_Record_Prepare(void);
void MTPNP_PFAL_Card2_Update_MSISDN_Record(void);
void MTPNP_PFAL_Update_Card2_MSISDN_Record_Succeed(void *inMsg);
void MTPNP_PFAL_Update_Card2_MSISDN_Record_Failed(void *inMsg);
void MTPNP_PFAL_MSISDN_HandleUpdateFail(MTPNP_UINT16 fail_cause);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_CARD2_MSISDN_H__ */
