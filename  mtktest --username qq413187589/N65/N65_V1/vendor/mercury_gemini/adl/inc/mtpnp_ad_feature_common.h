#ifndef __MTPNP_AD_FEATURE_COMMON_H__
#define __MTPNP_AD_FEATURE_COMMON_H__

#include "MTPNP_AD_Feature.h"

typedef enum
{
    MTPNP_AD_FEATURE_DUALMODE_CTRL = 0x01,      /* xxxx xxxx xxxx xxx1 support dual mode control */
    MTPNP_AD_FEATURE_CHV_MANAGEMENT = 0x02,     /* xxxx xxxx xxxx xx1x support slave chv management */
    MTPNP_AD_FEATURE_NETWORK_MANAGEMENT = 0x04, /* xxxx xxxx xxxx x1xx support slave network management */
    MTPNP_AD_FEATURE_CALL_CTRL = 0x08,  /* xxxx xxxx xxxx 1xxx support slave call control */
    MTPNP_AD_FEATURE_MESSAGE_MANAGEMENT = 0x10, /* xxxx xxxx xxx1 xxxx support slave message management */
    /* reserve */
    MTPNP_AD_FEATURE_MESSAGE_SETUP = 0x20,      /* xxxx xxxx xx1x xxxx support slave message setup management */

    MTPNP_AD_FEATURE_PHONEBOOK_MANAGEMENT = 0x40,       /* xxxx xxxx x1xx xxxx support slave phb management */
    MTPNP_AD_FEATURE_CALLHISTORY_MANAGEMENT = 0x80,     /* xxxx xxxx 1xxx xxxx support slave call history management */
    /* reserve */
    MTPNP_AD_FEATURE_CELLBROADCAST_MANAGEMENT = 0x100,  /* xxxx xxx1 xxxx xxxx support slave cell broadcast management */

    MTPNP_AD_FEATURE_DIRECT_DATA_TRANSFER = 0x1000      /* xxx1 xxxx xxxx xxxx support direct data transfer */
} E_MTPNP_AD_FEATURE;

#ifdef __MTPNP_DDT_SUPPORT__
typedef enum
{
    MTPNP_DDT_FEATURE_MESSAGE = 0x01,   /* xxxx xxxx xxxx xxx1 use ddt support short message */
    MTPNP_DDT_FEATURE_MESSAGE_SETUP = 0x02,     /* xxxx xxxx xxxx xx1x use ddt support message setup */
    MTPNP_DDT_FEATURE_CELLBROADCAST = 0x04,     /* xxxx xxxx xxxx x1xx use ddt support cell broadcast */
    MTPNP_DDT_FEATURE_VMAIL = 0x08,     /* xxxx xxxx xxxx 1xxx use ddt support voice mail */
    MTPNP_DDT_FEATURE_CALLHISTORY = 0x10,       /* xxxx xxxx xxx1 xxxx use ddt support call history */
    MTPNP_DDT_FEATURE_SEL_PLMN = 0x20,  /* xxxx xxxx xx1x xxxx use ddt support select plmn */
    MTPNP_DDT_FEATURE_CALLCONTROL = 0x40,       /* xxxx xxxx x1xx xxxx use ddt support select plmn */
    MTPNP_DDT_FEATURE_ENGINEERMODE = 0x80,      /* xxxx xxxx 1xxx xxxx use ddt support select plmn */

    MTPNP_DDT_FEATURE_HIGHPRIORITY = 0x1000     /* xxx1 xxxx xxxx xxxx use ddt support HIGHPRIORITY */
} E_MTPNP_DDT_FEATURE;
#endif // __MTPNP_DDT_SUPPORT__

#ifdef __MTPNP_AD_DUAL_SYNC_SUPPORT__
#define MTPNP_AD_DUAL_SYNC			0x02
#endif

#endif // __MTPNP_AD_FEATURE_COMMON_H__
