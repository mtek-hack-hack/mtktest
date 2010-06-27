#ifndef __MTPNP_PFAL_DUAL_PROFILES_H__
#define __MTPNP_PFAL_DUAL_PROFILES_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

#include "audioInc.h"
#include "resource_audio.h"

#include "SettingProfile.h"
#include "UserProfilesResDef.h"

#ifdef __MMI_DUAL_PROFILE_SUPPORT__

MTPNP_BOOL MTPNP_PFAL_Play_MasterMsgsTone(MTPNP_UINT8 type);

#endif /* __MMI_DUAL_PROFILE_SUPPORT__ */

#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_DUAL_PROFILES_H__ */
