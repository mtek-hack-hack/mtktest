/***********************************************
File name : MTPNP_AD_Slave_common_if.h
Contents : MTPNP AD interface definition for 6223 slave
History : Create by : Zhang Nan, Jun 4, 2007
************************************************/
#ifndef __MTPNP_AD_SLAVE_COMMON_IF_H__
#define __MTPNP_AD_SLAVE_COMMON_IF_H__

#include "MTPNP_AD_slave_if.h"
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_PFAL_Gemini_if.h"
#else
#include "MTPNP_PFAL_slave_if.h"
#endif
#include "MTPNP_AD_Feature_common.h"

#define MTPNP_AD_OWNER_NUMBER_COUNT	4

#define SUPPORTED_FEATURE	(MTPNP_AD_FEATURE_DUALMODE_CTRL | \
							MTPNP_AD_FEATURE_CHV_MANAGEMENT | \
							MTPNP_AD_FEATURE_NETWORK_MANAGEMENT | \
							MTPNP_AD_FEATURE_CALL_CTRL | \
							MTPNP_AD_FEATURE_MESSAGE_MANAGEMENT | \
							MTPNP_AD_FEATURE_MESSAGE_SETUP | \
							MTPNP_AD_FEATURE_PHONEBOOK_MANAGEMENT | \
							MTPNP_AD_FEATURE_CALLHISTORY_MANAGEMENT | \
							MTPNP_AD_FEATURE_CELLBROADCAST_MANAGEMENT)

#ifdef __MTPNP_DDT_SUPPORT__
#define SUPPORTED_DDT_FEATURE (MTPNP_DDT_FEATURE_MESSAGE | \
								  MTPNP_DDT_FEATURE_MESSAGE_SETUP | \
								  MTPNP_DDT_FEATURE_CELLBROADCAST | \
								  MTPNP_DDT_FEATURE_VMAIL | \
								  MTPNP_DDT_FEATURE_CALLHISTORY | \
								  MTPNP_DDT_FEATURE_SEL_PLMN | \
								  MTPNP_DDT_FEATURE_HIGHPRIORITY | \
								  MTPNP_DDT_FEATURE_CALLCONTROL | \
								  MTPNP_DDT_FEATURE_ENGINEERMODE)
#endif	// __MTPNP_DDT_SUPPORT__

#endif	// __MTPNP_AD_SLAVE_COMMON_IF_H__
