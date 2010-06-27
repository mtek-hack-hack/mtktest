#ifndef __MTPNP_PFAL_GEMINI_CALLHISTORY_H__
#define __MTPNP_PFAL_GEMINI_CALLHISTORY_H__
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__

#include "MTPNP_AD_slave_common_def.h"
#include "MTPNP_AD_Slave_common_if.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MTPNP_PFAL_CallHistory_Del(MTPNP_AD_REQ_DEL_CALL_SCT * type);
void MTPNP_PFAL_CallHistory_Load(MTPNP_AD_REQ_LOAD_CALL_SCT * type);
void MTPNP_PFAL_CallHistory_Set(MTPNP_AD_REQ_CALL_RECORD_SCT * type);
void MTPNP_PFAL_CallHistory_Del(MTPNP_AD_REQ_DEL_CALL_SCT * type);
void MTPNP_PFAL_RspDelCallHistory(void *info);
void MTPNP_PFAL_RspSetCallHistory(void *info);
void MTPNP_PFAL_RspReadCallHistory(void *info);
void MTPNP_PFAL_CallHistory_Set(MTPNP_AD_REQ_CALL_RECORD_SCT * type);
void MTPNP_PFAL_CallHistory_ReadyIndication(void *info);

#ifdef __cplusplus
}
#endif
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
#endif
