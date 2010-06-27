#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "QueueGprot.h"
#include "MTPNP_AD_master_header.h"

void *MTPNP_PFAL_Malloc_Local_Buffer(MTPNP_UINT32 size)
{
    return OslConstructDataPtr(size);
}

void MTPNP_PFAL_Free_Local_Buffer(void *data)
{
    OslIntFreeDataPtr(data);
}

void MTPNP_PFAL_Send_Msg_To_Queue(void *message)
{
    MYQUEUE Msg;
    ST_ILM *ilm_message;

    ilm_message = (ST_ILM *) message;

    Msg.oslMsgId = ilm_message->msg_id;
    Msg.oslDataPtr = (oslParaType *) ilm_message->local_para_ptr;
    Msg.oslPeerBuffPtr = MTPNP_NULL;
    Msg.oslSrcId = ilm_message->src_mod_id;
    Msg.oslDestId = ilm_message->dest_mod_id;

    OslMsgSendExtQueue(&Msg);
}
void MTPNP_PFAL_send_message(module_type MOD_SRC,
                             module_type MOD_DEST,
                             MTPNP_UINT8 MSG_SAP, const MTPNP_UINT16 MSG_ID, void *LOCAL, void *PEER)
{
    MYQUEUE Message;

    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslMsgId = MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}


#endif /* __MMI_DUAL_SIM_MASTER__ */
