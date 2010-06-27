#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

/* MTK Header */
#include "stdC.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"
#include "FrameworkStruct.h"
#include "ProtocolEvents.h"
#include "EventsGprot.h"
#include "wgui_status_icons.h"
#include "GlobalDefs.h"
//...Add MSG header
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
// 
#include "SMSApi.h"
#include "SMSStruct.h"
#include "customer_ps_inc.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "ems.h"
#include "SMSFunc.h"
#include "PhoneBookGprot.h"
/* MTK Header */

#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_Message_Data_Convert.h"

#ifndef MMI_FRM_SMS_MSG_CONTENT_NUM
#define MMI_FRM_SMS_MSG_CONTENT_NUM 20
#endif

MTPNP_BOOL MTPNP_PFAL_Convert_SMS_Loading_Data(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_SMS_LOAD_ONGOING *src_sms = (ST_MTPNP_AD_SMS_LOAD_ONGOING *) src_data;
    MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *dst_sms = (MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT *) dst_data;

    if (src_sms == MTPNP_NULL || dst_sms == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_sms->startup_seq_num = src_sms->startup_seq_num;
    dst_sms->mti = src_sms->mti;
    dst_sms->status = src_sms->status;
    dst_sms->storage_type = src_sms->storage_type;
    dst_sms->fo = src_sms->fo;
    dst_sms->index = src_sms->index;
    MTPNP_OSAL_memcpy(dst_sms->scts, src_sms->scts, 7);
    dst_sms->addr_number.length = src_sms->addr_number.length;
    dst_sms->addr_number.type = src_sms->addr_number.type;
    MTPNP_OSAL_memcpy(dst_sms->addr_number.number, src_sms->addr_number.number, MAX_CC_ADDR_LEN);
    dst_sms->pid = src_sms->pid;

    switch (src_sms->dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_sms->dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_sms->dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_sms->dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_sms->dcs = src_sms->dcs;
        break;
    }
    
    switch (src_sms->ori_dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_sms->ori_dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_sms->ori_dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_sms->ori_dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_sms->ori_dcs = src_sms->ori_dcs;
        break;
    }
    
    dst_sms->vp = src_sms->vp;
    dst_sms->mr = src_sms->mr;
    MTPNP_OSAL_memcpy(dst_sms->dt, src_sms->dt, 7);
    dst_sms->st = src_sms->st;
    dst_sms->dest_port = src_sms->dest_port;
    dst_sms->src_port = src_sms->src_port;
    dst_sms->concat_info = src_sms->concat_info;
    dst_sms->no_msg_data = src_sms->no_msg_data;
    MTPNP_OSAL_memcpy(dst_sms->msg_data, src_sms->msg_data, dst_sms->no_msg_data);

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_Send_Data(MTPNP_BOOL need_saved, void *src_data, void *dst_data)
{
    MMI_FRM_SMS_SEND_MSG_REQ_STRUCT *src_sms = (MMI_FRM_SMS_SEND_MSG_REQ_STRUCT *) src_data;
    ST_MTPNP_AD_SMS_SEND_MSG *dst_sms = (ST_MTPNP_AD_SMS_SEND_MSG *) dst_data;

    if (src_sms == MTPNP_NULL || dst_sms == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_sms->need_saved = need_saved;

    dst_sms->profile = src_sms->profile;
    dst_sms->reply_index = src_sms->reply_index;

    dst_sms->dest.type = src_sms->dest.type;
    dst_sms->dest.length = src_sms->dest.length;
    MTPNP_OSAL_memcpy(dst_sms->dest.number, src_sms->dest.number, MAX_CC_ADDR_LEN);

    dst_sms->para = src_sms->para;

    dst_sms->sc_addr.type = src_sms->sc_addr.type;
    dst_sms->sc_addr.length = src_sms->sc_addr.length;
    MTPNP_OSAL_memcpy(dst_sms->sc_addr.number, src_sms->sc_addr.number, MAX_CC_ADDR_LEN);

    dst_sms->vp = src_sms->vp;
    dst_sms->pid = src_sms->pid;
    dst_sms->udhi = src_sms->udhi;
    switch (src_sms->dcs)
    {
    case SMSAL_DEFAULT_DCS:
        dst_sms->dcs = MTPNP_CODING_SCHEME_DEFAULT;
        break;
    case SMSAL_8BIT_DCS:
        dst_sms->dcs = MTPNP_CODING_SCHEME_ASCII;
        break;
    case SMSAL_UCS2_DCS:
        dst_sms->dcs = MTPNP_CODING_SCHEME_UCS2;
        break;
    default:
        break;
    }
    dst_sms->length = src_sms->length;
    MTPNP_OSAL_memcpy(dst_sms->msg, src_sms->msg, MTPNP_AD_MAX_MSG_LEN);
    dst_sms->seq_num = src_sms->seq_num;
    dst_sms->mms_mode = src_sms->mms_mode;

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_SendRsp_Msg(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_SMS_SEND_RSP *src_msg = (ST_MTPNP_AD_SMS_SEND_RSP *) src_data;
    MMI_FRM_SMS_SEND_MSG_RSP_STRUCT *dst_msg = (MMI_FRM_SMS_SEND_MSG_RSP_STRUCT *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->result = src_msg->result;
    dst_msg->cause = src_msg->cause;
    dst_msg->mr = src_msg->mr;
    MTPNP_OSAL_memcpy(dst_msg->scts, src_msg->scts, 7);
    dst_msg->seq_num = src_msg->seq_num;
    dst_msg->concat_info.ref = src_msg->concat_info.ref;
    dst_msg->concat_info.total_seg = src_msg->concat_info.total_seg;
    dst_msg->concat_info.seg = src_msg->concat_info.seg;

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_Save_SMS(void *src_data, void *dst_data)
{
    MMI_FRM_SMS_SET_MSG_REQ_STRUCT *src_msg = (MMI_FRM_SMS_SET_MSG_REQ_STRUCT *) src_data;
    ST_MTPNP_AD_SMS_SAVE_MSG *dst_msg = (ST_MTPNP_AD_SMS_SAVE_MSG *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->profile = src_msg->profile;
    dst_msg->status = src_msg->status;

    dst_msg->dest.type = src_msg->dest.type;
    dst_msg->dest.length = src_msg->dest.length;
    MTPNP_OSAL_memcpy(dst_msg->dest.number, src_msg->dest.number, MAX_CC_ADDR_LEN);
    dst_msg->para = src_msg->para;
    dst_msg->sc_addr.type = src_msg->sc_addr.type;
    dst_msg->sc_addr.length = src_msg->sc_addr.length;
    MTPNP_OSAL_memcpy(dst_msg->sc_addr.number, src_msg->sc_addr.number, MAX_CC_ADDR_LEN);

    dst_msg->para = src_msg->para;

    MTPNP_OSAL_memcpy(dst_msg->scts, src_msg->scts, 7);
    dst_msg->vp = src_msg->vp;
    dst_msg->pid = src_msg->pid;
    dst_msg->udhi = src_msg->udhi;

    switch (src_msg->dcs)
    {
    case SMSAL_DEFAULT_DCS:
        dst_msg->dcs = MTPNP_CODING_SCHEME_DEFAULT;
        break;
    case SMSAL_8BIT_DCS:
        dst_msg->dcs = MTPNP_CODING_SCHEME_ASCII;
        break;
    case SMSAL_UCS2_DCS:
        dst_msg->dcs = MTPNP_CODING_SCHEME_UCS2;
        break;
    default:
        break;
    }

    dst_msg->index = src_msg->index;
    dst_msg->length = src_msg->length;
    MTPNP_OSAL_memcpy(dst_msg->msg, src_msg->msg, MTPNP_AD_MAX_MSG_LEN);

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_SaveSMSRsp_Msg(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_SMS_SAVE_RSP *src_msg = (ST_MTPNP_AD_SMS_SAVE_RSP *) src_data;
    MMI_FRM_SMS_SET_MSG_RSP_STRUCT *dst_msg = (MMI_FRM_SMS_SET_MSG_RSP_STRUCT *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->result = src_msg->result;
    dst_msg->cause = src_msg->cause;
    dst_msg->index = src_msg->index;
    dst_msg->status = src_msg->status;
    dst_msg->storage_type = src_msg->storage_type;

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_Get_SMS_Data(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_SMS_GET_RSP *src_msg = (ST_MTPNP_AD_SMS_GET_RSP *) src_data;
    MMI_FRM_SMS_GET_MSG_RSP_STRUCT *dst_msg = (MMI_FRM_SMS_GET_MSG_RSP_STRUCT *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->result = src_msg->result;
    dst_msg->cause = src_msg->cause;

    dst_msg->concat_info.ref = src_msg->concat_info.ref;
    dst_msg->concat_info.seg = src_msg->concat_info.seg;
    dst_msg->concat_info.total_seg = src_msg->concat_info.total_seg;

    dst_msg->mti = src_msg->mti;
    dst_msg->status = src_msg->status;
    dst_msg->storage_type = src_msg->storage_type;
    dst_msg->fo = src_msg->fo;
    MTPNP_OSAL_memcpy(dst_msg->scts, src_msg->scts, 7);

    dst_msg->sca_number.type = src_msg->sca_number.type;
    dst_msg->sca_number.length = src_msg->sca_number.length;
    MTPNP_OSAL_memcpy(dst_msg->sca_number.number, src_msg->sca_number.number, MAX_CC_ADDR_LEN);

    dst_msg->addr_number.type = src_msg->addr_number.type;
    dst_msg->addr_number.length = src_msg->addr_number.length;
    MTPNP_OSAL_memcpy(dst_msg->addr_number.number, src_msg->addr_number.number, MAX_CC_ADDR_LEN);

    dst_msg->pid = src_msg->pid;

    switch (src_msg->dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_msg->dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_msg->dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_msg->dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_msg->dcs = src_msg->dcs;
        break;
    }
    
    switch (src_msg->ori_dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_msg->ori_dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_msg->ori_dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_msg->ori_dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_msg->ori_dcs = src_msg->ori_dcs;
        break;
    }
    
    dst_msg->vp = src_msg->vp;
    dst_msg->mr = src_msg->mr;
    MTPNP_OSAL_memcpy(dst_msg->dt, src_msg->dt, 7);
    dst_msg->st = src_msg->st;
    dst_msg->dest_port = src_msg->dest_port;
    dst_msg->src_port = src_msg->src_port;
    dst_msg->no_msg_data = src_msg->no_msg_data;
    MTPNP_OSAL_memcpy(dst_msg->msg_data, src_msg->msg_data, dst_msg->no_msg_data);

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_Deliver_Msg(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_DELIVER_SMS *src_msg = (ST_MTPNP_AD_DELIVER_SMS *) src_data;
    mmi_frm_sms_deliver_msg_struct *dst_msg = (mmi_frm_sms_deliver_msg_struct *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->fo = src_msg->fo;
    MTPNP_OSAL_memcpy(dst_msg->scts, src_msg->scts, 7);

    dst_msg->sca_number.type = src_msg->sca_number.type;
    dst_msg->sca_number.length = src_msg->sca_number.length;
    MTPNP_OSAL_memcpy(dst_msg->sca_number.number, src_msg->sca_number.number, MAX_CC_ADDR_LEN);

    dst_msg->addr_number.type = src_msg->oa_number.type;
    dst_msg->addr_number.length = src_msg->oa_number.length;
    MTPNP_OSAL_memcpy(dst_msg->addr_number.number, src_msg->oa_number.number, MAX_CC_ADDR_LEN);

    dst_msg->pid = src_msg->pid;

    switch (src_msg->dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_msg->dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_msg->dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_msg->dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_msg->dcs = src_msg->dcs;
        break;
    }
    
    switch (src_msg->ori_dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_msg->ori_dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_msg->ori_dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_msg->ori_dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_msg->ori_dcs = src_msg->ori_dcs;
        break;
    }
    
    dst_msg->index = src_msg->index;
    dst_msg->dest_port = src_msg->dest_port;
    dst_msg->src_port = src_msg->src_port;
    dst_msg->mti = src_msg->mti;
    dst_msg->display_type = src_msg->display_type;
	/* MMI_FRM_SMS_TYPE_CLASS0_SLAVE */
	if (dst_msg->display_type == SMSAL_MSG_TYPE_CLASS0)
	{
		dst_msg->display_type = MMI_FRM_SMS_TYPE_CLASS0_SLAVE;
	}
#ifdef __MMI_MESSAGES_COPY__
    dst_msg->storageType = src_msg->storage_type;
#endif
    dst_msg->concat_info = src_msg->concat_info;
    dst_msg->no_msg_data = src_msg->no_msg_data;
    dst_msg->msg_data[0] = MMI_FRM_SMS_MSG_CONTENT_NUM;

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_Deliver_App_Data(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_APP_DATA *src_msg = (ST_MTPNP_AD_APP_DATA *) src_data;
    mmi_frm_sms_deliver_data_struct *dst_msg = (mmi_frm_sms_deliver_data_struct *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->dest_mod_id = src_msg->dest_mod_id;
    dst_msg->dest_port = src_msg->dest_port;
    dst_msg->src_port = src_msg->src_port;
	dst_msg->isSlave = MTPNP_TRUE;

    switch (src_msg->dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_msg->dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_msg->dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_msg->dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_msg->dcs = src_msg->dcs;
        break;
    }

    dst_msg->mti = src_msg->mti;
    dst_msg->message_len = src_msg->message_len;
	dst_msg->concat_info = src_msg->concat_info[0];    

    dst_msg->oa.type = src_msg->oa.type;
    dst_msg->oa.length = src_msg->oa.length;
    MTPNP_OSAL_memcpy(dst_msg->oa.number, src_msg->oa.number, MAX_CC_ADDR_LEN);

    MTPNP_OSAL_memcpy(dst_msg->scts, src_msg->scts, 7);

    return MTPNP_TRUE;
}

MTPNP_BOOL MTPNP_PFAL_Convert_SMS_Status_Report_Ind(void *src_data, void *dst_data)
{
    ST_MTPNP_AD_SMS_STATUS_REPORT *src_msg = (ST_MTPNP_AD_SMS_STATUS_REPORT *) src_data;
    mmi_frm_sms_status_report_ind_struct *dst_msg = (mmi_frm_sms_status_report_ind_struct *) dst_data;

    if (src_msg == MTPNP_NULL || dst_msg == MTPNP_NULL)
        return MTPNP_FALSE;

    dst_msg->fo = src_msg->fo;
    MTPNP_OSAL_memcpy(dst_msg->scts, src_msg->scts, 7);
    MTPNP_OSAL_memcpy(dst_msg->dt, src_msg->dt, 7);

    dst_msg->ra_number.length = src_msg->ra_number.length;
    dst_msg->ra_number.type = src_msg->ra_number.type;
    MTPNP_OSAL_memcpy(dst_msg->ra_number.number, src_msg->ra_number.number, MAX_CC_ADDR_LEN);

    dst_msg->st = src_msg->st;
    dst_msg->pid = src_msg->pid;

    switch (src_msg->dcs)
    {
    case MTPNP_CODING_SCHEME_DEFAULT:
        dst_msg->dcs = SMSAL_DEFAULT_DCS;
        break;
    case MTPNP_CODING_SCHEME_ASCII:
        dst_msg->dcs = SMSAL_8BIT_DCS;
        break;
    case MTPNP_CODING_SCHEME_UCS2:
        dst_msg->dcs = SMSAL_UCS2_DCS;
        break;
    case MTPNP_CODING_SCHEME_GB2312:
        break;
    case MTPNP_CODING_SCHEME_BIG5:
        break;
    case MTPNP_CODING_SCHEME_STREAM:
    case MTPNP_CODING_SCHEME_UNKNOWN:
    default:
        dst_msg->dcs = src_msg->dcs;
        break;
    }
    
    dst_msg->mr = src_msg->mr;
    dst_msg->no_msg_data = src_msg->no_msg_data;
	dst_msg->isFromMaster = MTPNP_FALSE;
    MTPNP_OSAL_memcpy(dst_msg->msg_data, src_msg->msg_data, 1);

    return MTPNP_TRUE;
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
