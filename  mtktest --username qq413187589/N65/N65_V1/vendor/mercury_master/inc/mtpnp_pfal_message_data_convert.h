#ifndef __MTPNP_PFAL_MESSAGE_DATA_CONVERT_H__
#define __MTPNP_PFAL_MESSAGE_DATA_CONVERT_H__

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_AD_master_header.h"

MTPNP_BOOL MTPNP_PFAL_Convert_SMS_Loading_Data(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_Send_Data(MTPNP_BOOL need_saved, void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_SendRsp_Msg(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_Save_SMS(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_SaveSMSRsp_Msg(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_Get_SMS_Data(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_Deliver_Msg(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_Deliver_App_Data(void *src_data, void *dst_data);
MTPNP_BOOL MTPNP_PFAL_Convert_SMS_Status_Report_Ind(void *src_data, void *dst_data);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __MTPNP_PFAL_MESSAGE_DATA_CONVERT_H__ */
