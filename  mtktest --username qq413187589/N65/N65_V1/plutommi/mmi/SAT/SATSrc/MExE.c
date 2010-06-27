/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *   MExE.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended for MExE appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MExE_SUPPORT__


#include "mexe_struct.h"
#include "MExEGProt.h"

#include "SATDefs.h"
#include "SATStruct.h"
#include "SATGProts.h"
#include "SATProts.h"
#include "ProtocolEvents.h"
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "GSM7BitDefaultAlphabet.h"
#include "CommonScreens.h"
#include "SSCStringHandle.h"
#include "lcd_sw_rnd.h"
#include "BootUp.h"
#include "PowerOnChargerProt.h"
#include "SimDetectionDef.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "sat_def.h"


/*
 * Local Variable
 */
static mexe_context_struct g_MExE_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_init
 * DESCRIPTION
 *  MExE initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_mexe_get_sim_certificate_req, MSG_ID_MMI_GET_SIM_CERTIFICATE_REQ);

    memset(&g_MExE_context, 0, sizeof(mexe_context_struct));

#ifdef __GEMINI__
    if (sim_service_table_query(SERVICE_MEXE, SIM1) == SERVICE_SUPPORT)
#else
    if (sim_service_table_query(SERVICE_MEXE) == SERVICE_SUPPORT)
#endif
    {
        /* search for MExE service table */
        mmi_mexe_read_service_table_req();
    }
}


void mmi_mexe_get_sim_certificate_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_get_sim_certificate_req_struct *sim_certificate_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_certificate_req = (mmi_get_sim_certificate_req_struct*) info;

    g_MExE_context.idx_certificate = 0;
    g_MExE_context.sender_module = sim_certificate_req->mod_id;

    if (!g_MExE_context.MExE_valid)
    {
        mmi_mexe_get_sim_certificate_rsp();
        return;
    }

    g_MExE_context.required_type = sim_certificate_req->type;
    g_MExE_context.ORPK_finish = 0;
    g_MExE_context.ARPK_finish = 0;
    g_MExE_context.TPRPK_finish = 0;
    g_MExE_context.key_identifier = OslMalloc(MAX_MExE_IDENTIFIER_LEN);
    g_MExE_context.certificate_identifier = OslMalloc(MAX_MExE_IDENTIFIER_LEN);
    g_MExE_context.certificate_data = OslMalloc(MAX_MExE_DATA_LEN);

    SetProtocolEventHandler(mmi_mexe_send_sim_certificate_record_res, MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_RES);

    mmi_mexe_retrieve_certificate_handler();
}


void mmi_mexe_get_sim_certificate_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_get_sim_certificate_rsp_struct *sim_certificate_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_RES);

    if (g_MExE_context.key_identifier != NULL)
    {
        OslMfree(g_MExE_context.key_identifier);
        g_MExE_context.key_identifier = NULL;
    }
    if (g_MExE_context.certificate_identifier != NULL)
    {
        OslMfree(g_MExE_context.certificate_identifier);
        g_MExE_context.certificate_identifier = NULL;
    }
    if (g_MExE_context.certificate_data != NULL)
    {
        OslMfree(g_MExE_context.certificate_data);
        g_MExE_context.certificate_data = NULL;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = g_MExE_context.sender_module;
    Message.oslMsgId = MSG_ID_MMI_GET_SIM_CERTIFICATE_RSP;
    sim_certificate_rsp = (mmi_get_sim_certificate_rsp_struct*) OslConstructDataPtr(sizeof(mmi_get_sim_certificate_rsp_struct));
    sim_certificate_rsp->total = g_MExE_context.idx_certificate;
    Message.oslDataPtr = (oslParaType*) sim_certificate_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_mexe_send_sim_certificate_record_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_send_sim_certificate_record_ind_struct *sim_certificate_record_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = g_MExE_context.sender_module;
    Message.oslMsgId = MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_IND;
    sim_certificate_record_ind = (mmi_send_sim_certificate_record_ind_struct*) OslConstructDataPtr(sizeof(mmi_send_sim_certificate_record_ind_struct));

    sim_certificate_record_ind->idx = g_MExE_context.file_index; //g_MExE_context.idx_certificate++;
    sim_certificate_record_ind->authority_certificate = g_MExE_context.authority_certificate;
    sim_certificate_record_ind->certificate_type = g_MExE_context.certificate_type;
    sim_certificate_record_ind->key_identifier_length = g_MExE_context.key_identifier_length;
    memcpy(sim_certificate_record_ind->key_identifier, g_MExE_context.key_identifier, sim_certificate_record_ind->key_identifier_length);
    sim_certificate_record_ind->certificate_identifier_length = g_MExE_context.certificate_identifier_length;
    if (g_MExE_context.certificate_identifier_length != 0)
    {
        memcpy(sim_certificate_record_ind->certificate_identifier, g_MExE_context.certificate_identifier, sim_certificate_record_ind->certificate_identifier_length);
    }
    sim_certificate_record_ind->data_length = g_MExE_context.certificate_file_length;
    memcpy(sim_certificate_record_ind->data, g_MExE_context.certificate_data, g_MExE_context.certificate_file_length);

    Message.oslDataPtr = (oslParaType*) sim_certificate_record_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_mexe_send_sim_certificate_record_res(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_send_sim_certificate_record_res_struct *sim_certificate_record_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_certificate_record_res = (mmi_send_sim_certificate_record_res_struct*) info;

    if (sim_certificate_record_res->next != 0)
    {
        mmi_mexe_retrieve_certificate_handler();
    }
    else
    {
        mmi_mexe_get_sim_certificate_rsp();
    }
}


void mmi_mexe_read_service_table_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_mexe_read_service_table_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C; /* message back to the sender */
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_MEXE_ST_IDX;
    dataPtr->para = 0;
    dataPtr->length = 1;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_mexe_read_service_table_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *MExE_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MExE_data = (mmi_smu_read_sim_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);

    if (MExE_data->result.flag == 0)
    {
        if (MExE_data->data[0] & 0x03) /* 0000 0011 */
        {
            g_MExE_context.ORPK_support = MMI_TRUE;
        }

        if (MExE_data->data[0] & 0x0C) /* 0000 1100 */
        {
            g_MExE_context.ARPK_support = MMI_TRUE;
        }

        if (MExE_data->data[0] & 0x30) /* 0011 0000 */
        {
            g_MExE_context.TPRPK_support = MMI_TRUE;
        }

        if (g_MExE_context.ORPK_support || g_MExE_context.ARPK_support || g_MExE_context.TPRPK_support)
        {
            g_MExE_context.MExE_valid = MMI_TRUE;
        }
    }
}


void mmi_mexe_read_rpk_file_info_req(U8 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_file_info_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_mexe_read_rpk_file_info_rsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    dataPtr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    dataPtr->file_idx = file_id;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_mexe_read_rpk_file_info_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *rpk_file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rpk_file_info = (mmi_smu_read_file_info_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_FILE_INFO_RSP);

    if (rpk_file_info->result.flag == 0)
    {
        g_MExE_context.rpk_record_length = (U8) (rpk_file_info->file_size / rpk_file_info->num_of_rec);
        g_MExE_context.rpk_record_total = rpk_file_info->num_of_rec;
        g_MExE_context.rpk_record_read = 0;
    }
    else
    {
        /* error handler for allocated and activated file not found */
        mmi_mexe_finish_rpk_file(MMI_FALSE);
    }

    mmi_mexe_retrieve_certificate_handler();
}


void mmi_mexe_read_rpk_file_req(U8 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_mexe_read_rpk_file_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = file_id;
    dataPtr->para = g_MExE_context.rpk_record_read;
    dataPtr->length = g_MExE_context.rpk_record_length;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_mexe_read_rpk_file_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *rpk_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rpk_file = (mmi_smu_read_sim_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);

    if (rpk_file->result.flag == 0)
    {
        if ((++g_MExE_context.rpk_record_read) == g_MExE_context.rpk_record_total)
        {
            mmi_mexe_finish_rpk_file(MMI_TRUE);
        }

        if (rpk_file->data[0] == 0xFF)
        {
            /* certificate descriptor is invalid */
            mmi_mexe_retrieve_certificate_handler();
            return;
        }

        if (g_MExE_context.required_type != MExE_CERTIFICATE_ALL && g_MExE_context.required_type != rpk_file->data[2])
        {
            /* certificate type is not desired */
            mmi_mexe_retrieve_certificate_handler();
            return;
        }

        /* prepare parameters to read instance */
        memcpy(&g_MExE_context.certificate_file_id[0], &rpk_file->data[3], 2);
        g_MExE_context.certificate_file_length = rpk_file->data[7] * 256 + rpk_file->data[8];
        g_MExE_context.certificate_file_read_cycle = 0;
        if ((g_MExE_context.certificate_file_length % 256) == 0 && (g_MExE_context.certificate_file_length / 256) > 0)
        {
            g_MExE_context.certificate_file_total_cycle = g_MExE_context.certificate_file_length / 256 - 1;
        }
        else
        {
            g_MExE_context.certificate_file_total_cycle = g_MExE_context.certificate_file_length / 256;
        }

        memset(g_MExE_context.key_identifier, 0, MAX_MExE_IDENTIFIER_LEN);
        memset(g_MExE_context.certificate_identifier, 0, MAX_MExE_IDENTIFIER_LEN);

        /* keep the root public key description file */
        g_MExE_context.authority_certificate = rpk_file->data[1];
        g_MExE_context.certificate_type = rpk_file->data[2];
        g_MExE_context.key_identifier_length = rpk_file->data[9];
        memcpy(g_MExE_context.key_identifier, rpk_file->data + 10, g_MExE_context.key_identifier_length);

        if (rpk_file->data[10 + g_MExE_context.key_identifier_length] != 0 && rpk_file->data[10 + g_MExE_context.key_identifier_length] != 0xFF)
        {
            g_MExE_context.certificate_identifier_length = rpk_file->data[10 + g_MExE_context.key_identifier_length];
            memcpy(g_MExE_context.certificate_identifier, rpk_file->data + 11 + g_MExE_context.key_identifier_length, g_MExE_context.certificate_identifier_length);
        }
        else
        {
            g_MExE_context.certificate_identifier_length = 0;
        }

        mmi_mexe_read_rpk_instance_req();
    }
    else
    {
        /* error handler for allocated and activated file not found */
        mmi_mexe_finish_rpk_file(MMI_FALSE);
    }
}


void mmi_mexe_finish_rpk_file(pBOOL done_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_MExE_context.ORPK_support && !g_MExE_context.ORPK_finish)
    {
        if (done_flag)
        {
            g_MExE_context.ORPK_finish = 1;
            g_MExE_context.rpk_record_length = 0;
        }
        else
        {
            g_MExE_context.ORPK_support = 0;
        }
        return;
    }

    if (g_MExE_context.ARPK_support && !g_MExE_context.ARPK_finish)
    {
        if (done_flag)
        {
            g_MExE_context.ARPK_finish = 1;
            g_MExE_context.rpk_record_length = 0;
        }
        else
        {
            g_MExE_context.ARPK_support = 0;
        }
        return;
    }

    if (g_MExE_context.TPRPK_support && !g_MExE_context.TPRPK_finish)
    {
        if (done_flag)
        {
            g_MExE_context.TPRPK_finish = 1;
            g_MExE_context.rpk_record_length = 0;
        }
        else
        {
            g_MExE_context.TPRPK_support = 0;
        }
        return;
    }
}


void mmi_mexe_read_rpk_instance_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    U8 path[6] = {0x7F, 0x20, 0x5F, 0x3C, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path[4] = g_MExE_context.certificate_file_id[0];
    path[5] = g_MExE_context.certificate_file_id[1];

    SetProtocolEventHandler(mmi_mexe_read_rpk_instance_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = FILE_NONE;
    dataPtr->para = g_MExE_context.certificate_file_read_cycle * 256; /* data offset might be larger than 256 */
    dataPtr->length = (g_MExE_context.certificate_file_total_cycle == g_MExE_context.certificate_file_read_cycle) ? g_MExE_context.certificate_file_length - dataPtr->para : 256;
    memcpy(dataPtr->path, path, 6); /* read from EF path, total 6 bytes for path */
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_mexe_read_rpk_instance_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *rpk_instance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rpk_instance = (mmi_smu_read_sim_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);

    memcpy(g_MExE_context.certificate_data + (g_MExE_context.certificate_file_read_cycle * 256), rpk_instance->data, rpk_instance->length);

    // need to read many cycles
    if (g_MExE_context.certificate_file_total_cycle == g_MExE_context.certificate_file_read_cycle)
    {
        mmi_mexe_send_sim_certificate_record_ind();
    }
    else
    {
        g_MExE_context.certificate_file_read_cycle++;
        mmi_mexe_read_rpk_instance_req();
    }
}


void mmi_mexe_retrieve_certificate_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* read EF ORPK */
    if (g_MExE_context.ORPK_support && !g_MExE_context.ORPK_finish)
    {
        g_MExE_context.file_index = ROOT_PUBLIC_KEY_OPERATOR;
        if (g_MExE_context.rpk_record_length == 0)
        {
            mmi_mexe_read_rpk_file_info_req(FILE_ORPK_IDX);
        }
        else
        {
            mmi_mexe_read_rpk_file_req(FILE_ORPK_IDX);
        }
        return;
    }

    /* read EF ARPK */
    if (g_MExE_context.ARPK_support && !g_MExE_context.ARPK_finish)
    {
        g_MExE_context.file_index = ROOT_PUBLIC_KEY_ADMINISTRATOR;
        if (g_MExE_context.rpk_record_length == 0)
        {
            mmi_mexe_read_rpk_file_info_req(FILE_ARPK_IDX);
        }
        else
        {
            mmi_mexe_read_rpk_file_req(FILE_ARPK_IDX);
        }
        return;
    }

    /* read EF TPRPK */
    if (g_MExE_context.TPRPK_support && !g_MExE_context.TPRPK_finish)
    {
        g_MExE_context.file_index = ROOT_PUBLIC_KEY_PARTY;
        if (g_MExE_context.rpk_record_length == 0)
        {
            mmi_mexe_read_rpk_file_info_req(FILE_TPRPK_IDX);
        }
        else
        {
            mmi_mexe_read_rpk_file_req(FILE_TPRPK_IDX);
        }
        return;
    }

    g_MExE_context.file_index = ROOT_PUBLIC_KEY_NONE;
    mmi_mexe_get_sim_certificate_rsp();
}

#endif /* __MMI_MExE_SUPPORT__ */

