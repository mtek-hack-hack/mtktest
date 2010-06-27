#ifndef __MTPNP_PFAL_NETWORK_H__
#define __MTPNP_PFAL_NETWORK_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

void MTPNP_PFAL_Network_Init(void);
void MTPNP_PFAL_Slave_Network_Attach(void *inMsg);
void MTPNP_PFAL_Slave_OPN_Loaded(void *inMsg);
void MTPNP_PFAL_Slave_SPN_Loaded(void *inMsg);

/* plmn begin */
extern void MTPNP_PFAL_Network_Setup_Init(void);
/* plmn end */

/* master RF ctrl */
void MTPNP_PFAL_PwrOn_MasterRF(void *inMsg);
void MTPNP_PFAL_PwrOff_MasterRF(void *inMsg);
void MTPNP_PFAL_PwrOn_MasterRF_Rsp(void *info);
void MTPNP_PFAL_PwrOff_MasterRF_Rsp(void *info);
/* master RF ctrl */

void MTPNP_PFAL_Refresh_Card2PLMN(void);

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_NETWORK_H__ */
