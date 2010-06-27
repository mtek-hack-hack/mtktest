#ifndef __MTPNP_PFAL_CHV_VERIFY_H__
#define __MTPNP_PFAL_CHV_VERIFY_H__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

extern void MTPNP_PFAL_Cancel_SIM1_VerifyAndUnblock(void);
extern void MTPNP_PFAL_Cancel_SIM1_Verify(void);
extern void MTPNP_PFAL_Cancel_SIM2_VerifyAndUnblock(void);
extern void MTPNP_PFAL_Cancel_SIM2_Verify(void);
extern void MTPNP_PFAL_Entry_SIM1_Verified_Screen(void);
extern void MTPNP_PFAL_GoTo_SOS_DialScr(void);
extern void MTPNP_PFAL_ATCmd_Update_Chv(void *info);

#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MTPNP_PFAL_CHV_VERIFY_H__ */

