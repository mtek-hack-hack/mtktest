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
 *
 * Filename:
 * ---------
 * SPDI.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is created for service provider display information support (3GPP 51.11 EF SPDI)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "SimDetectionDef.h"
#include "GSM7BitDefaultAlphabet.h"
#include "sim_common_enums.h"
#include "IdleAppDef.h" /* for g_idle_context */
#include "SimDetectionGexdcl.h" /* for g_pwr_context */
#include "SimDetectionGprot.h"
#include "EONSGProt.h"


/**************************************************************************
   Definitions
**************************************************************************/
#define MAX_SPDI_RECORD 50


/**************************************************************************
   Global variables
**************************************************************************/
static U8 g_spdi_info[MAX_SPDI_RECORD][3];
static U8 g_spdi_number;

extern U8 gPLMN[MAX_PLMN_LEN_MMI];


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_spdi_data_rsp
 * DESCRIPTION
 *  Response of read EF_SPDI data
 * PARAMETERS
 *  info            [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_spdi_data_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *spdi_data;
    U8 spdi_offset = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spdi_data = (mmi_smu_read_sim_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);

    if (spdi_data->result.flag == 0)
    {
        memcpy(&g_spdi_info[0][0], &spdi_data->data[spdi_offset], spdi_data->data[spdi_offset - 1]);
    }

    mmi_eons_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_spdi_data_req
 * DESCRIPTION
 *  Request of read EF_SPDI data
 * PARAMETERS
 *  spdi_data_size  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_spdi_data_req(U16 spdi_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_idle_get_spdi_data_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_SPDI_IDX;  /* SPDI...FILE_SPDI_IDX */
    dataPtr->para = 0;
    dataPtr->length = spdi_data_size;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_spdi_info_rsp
 * DESCRIPTION
 *  Response of read EF_SPDI info
 * PARAMETERS
 *  info            [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_spdi_info_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *spdi_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spdi_info = (mmi_smu_read_file_info_rsp_struct*) (info);
    memset(&g_spdi_info[0][0], 0, sizeof (g_spdi_info));

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_FILE_INFO_RSP);

#ifdef __GEMINI__
    if (spdi_info->result.flag == 0 && sim_service_table_query(SERVICE_SP_DSPL_INFO, SIM1) == SERVICE_SUPPORT)
#else
    if (spdi_info->result.flag == 0 && sim_service_table_query(SERVICE_SP_DSPL_INFO) == SERVICE_SUPPORT)
#endif
    {
        mmi_idle_get_spdi_data_req(spdi_info->file_size);
    }
    else
    {
        g_spdi_number = 0;
        mmi_eons_init();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_spdi_info_req
 * DESCRIPTION
 *  Request of read EF_SPDI info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_spdi_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_file_info_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_idle_get_spdi_info_rsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    dataPtr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    dataPtr->file_idx = (U8) FILE_SPDI_IDX;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_rplmn_in_spdi_list
 * DESCRIPTION
 *  Find out if VPLMN is in SPDI list or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_idle_is_rplmn_in_spdi_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 spni_plmn[MAX_PLMN_LEN_MMI];
	U8 empty_plmn_bcd[3] = {0xFF, 0xFF, 0xFF};
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_SPDI_RECORD; i++)
    {
		if (memcmp(g_spdi_info[i], empty_plmn_bcd, 3) == 0)
		{
            return MMI_FALSE;
		}

        mmi_eons_convert_plmn_bcd_format_to_string(g_spdi_info[i], spni_plmn);

        if (memcmp(spni_plmn, gPLMN, strlen((S8*) gPLMN)) == 0)
		{
            return MMI_TRUE;
		}
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_spn_b1_set
 * DESCRIPTION
 *  Is b1 set in EF_SPN ?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_idle_is_spn_b1_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL) (g_pwr_context.RequireRPLMN & 0x01);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_is_spn_b2_set
 * DESCRIPTION
 *  Is b2 set in EF_SPN ?
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_idle_is_spn_b2_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL) (g_pwr_context.RequireRPLMN & 0x02);
}

