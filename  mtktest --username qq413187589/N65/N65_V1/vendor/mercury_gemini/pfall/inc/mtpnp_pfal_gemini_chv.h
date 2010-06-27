#ifndef __MTPNP_PFAL_SLAVE_CHV_H__
#define __MTPNP_PFAL_SLAVE_CHV_H__

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__

#include "MTPNP_AD_slave_header.h"

extern void Convert_To_AD_CHV_Info(ST_SIM_CHV_INFO * chv_ad, sim_chv_info_struct chv_info);
void MTPNP_PFAL_SIM2_PasswdReqResponse(void *inMsg);
void MTPNP_PFAL_SIM2_QueryFailureRsp(void *inMsg);

#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

#endif /* __MTPNP_PFAL_SLAVE_CHV_H__ */
