#ifndef __MTPNP_PFAL_CELLBROADCAST_H__
#define __MTPNP_PFAL_CELLBROADCAST_H__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

extern void MTPNP_PFAL_InitCellBroadcastApp(void);
extern void mmi_msg_pre_entry_card2_cb_channel_bootup(void);

extern void mmi_msg_entry_card2_new_cb_ind(void);
extern U8 mmi_card2_msg_need_new_cb_ind(void);

#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif
