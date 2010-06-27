#ifndef __MTPNP_PFAL_CUSTOM_VEINT_H__
#define __MTPNP_PFAL_CUSTOM_VEINT_H__

#if defined(__MMI_DUAL_SIM_MASTER__)

#include "MTPNP_AD_master_header.h"

void MTPNP_VENT_Init(void);

void MTPNP_VEINT0_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT1_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT2_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT3_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT4_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT5_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT6_HISR(MTPNP_UINT8 state);
void MTPNP_VEINT7_HISR(MTPNP_UINT8 state);

void MTPNP_Send_VEINT(void);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_CUSTOM_VEINT_H__ */
