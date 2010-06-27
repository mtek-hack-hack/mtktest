#ifndef __MTPNP_PFAL_SLAVE_NETWORK_H__
#define __MTPNP_PFAL_SLAVE_NETWORK_H__

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__

#include "MTPNP_AD_slave_header.h"

void MTPNP_PFAL_Set_SIM2_EDGE_status(MTPNP_UINT8 edge_state);
void MTPNP_PFAL_Update_SIM2_GPRS_Status(MTPNP_UINT8 gprs_state);
void MTPNP_PFAL_Change_Roaming_State(void);
void MTPNP_PFAL_NetworkErrorHandle(void);
void MTPNP_PFAL_Report_Service_Indication(void *inMsg);
void MTPNP_PFAL_Get_SIM2_PLMN_Rsp(void *inMsg);
void MTPNP_PFAL_Get_SIM2_PLMN_Req(void);
void MTPNP_PFAL_Check_Roaming_Rsp(void *inMsg);
void MTPNP_PFAL_NumberOfPLMNSuported(void *inMsg);
void MTPNP_PFAL_NW_Cipher_Indication(void *inMsg);

#ifdef __MANUAL_MODE_NW_SEL__
void MTPNP_PFAL_PLMN_Selection_Mode_Indication(void *inMsg);
#endif
#ifdef __MMI_GPRS_FEATURES__
void MTPNP_PFAL_GPRS_Status_Update_Indication(void *inMsg);
#endif

void MTPNP_PFAL_QOS_Indication(void *inMsg);
void MTPNP_PFAL_NW_Attach_Indication(void *inMag);
void MTPNP_PFAL_NW_Idle_Info_Indication(void *inMsg);
void MTPNP_PFAL_SIM2_ECCInfoSave(void *inMsg);
void MTPNP_PFAL_Line_Switch_Rsp(void *inMsg);
void MTPNP_PFAL_Network_Report_Line_Info_Indication(void *inMsg);
void MTPNP_PFAL_Update_CallID_Status_Rsp(void *inMsg);
void MTPNP_PFAL_SetRF_Rsp(void *inMsg);

void MTPNP_PFAL_NITZHandler(void *msg);

#endif /* __MMI_DUAL_SIM_SINGLE_CALL__*/

#endif /* __MTPNP_PFAL_NETWORK_H__ */
