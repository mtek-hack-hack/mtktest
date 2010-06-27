#ifndef __MTPNP_AD_SLAVE_HEADER_H__
#define __MTPNP_AD_SLAVE_HEADER_H__
/*#if defined(WIN32)
#pragma pack(push)
#pragma pack(4)
#endif*/ /* WIN32 */
#include "MTPNP_AD_slave_if.h"
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_PFAL_Gemini_if.h"
#include "MTPNP_PFAL_Gemini_def.h"
#else
#include "MTPNP_PFAL_slave_if.h"
#include "MTPNP_PFAL_slave_def.h"
#endif
/*#if defined(WIN32)
#pragma pack(pop)
#endif*/ /* WIN32 */

#include "MTPNP_PFAL_Debug.h"
#endif /*__MTPNP_AD_SLAVE_HEADER_H__*/
