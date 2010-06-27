#ifndef __MTPNP_PFAL_VOICEMAIL_H__
#define __MTPNP_PFAL_VOICEMAIL_H__
#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

extern void MTPNP_PFAL_InitVoiceMail(void);
extern void mmi_frm_sms_get_card2_mailbox_info(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_msg_dial_card2_mailbox_req(void);

#endif /* __MMI_DUAL_SIM_MASTER__ */
#endif /* __MTPNP_PFAL_VOICEMAIL_H__ */
