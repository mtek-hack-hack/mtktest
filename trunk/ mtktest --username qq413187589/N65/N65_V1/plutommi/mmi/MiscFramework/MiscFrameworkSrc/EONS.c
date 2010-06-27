/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * EONS.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is created for EONS support (3GPP 51.11 EF OPL/PNN)
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
#include "ProtocolEvents.h"
#include "SimDetectionDef.h"
#include "GSM7BitDefaultAlphabet.h"
#include "sim_common_enums.h"
#include "IdleAppDef.h" /* for g_idle_context */
#include "SimDetectionGexdcl.h" /* for g_pwr_context */
#include "SimDetectionGprot.h"
#include "EONSGProt.h"
#include "IdleAppProt.h"


static U8 opl_record_number = 0;    /* total records read from EF OPL */
static MMI_BOOL is_pnn_no_opl = MMI_FALSE;


/**************************************************************************
   Pre-definition
**************************************************************************/
#ifdef __MMI_EONS_SUPPORT__

/**************************************************************************
   Definitions
**************************************************************************/
#define MAX_MCC_MNC_LENGTH 3    /* Do not modify this definition */
#define MAX_OPL_PNN_RECORD 50   /* Modify this definition to support more records in EF OPL/PNN */
                                /* If this value is larger than 50, NVRAM size should also be modified */

/**************************************************************************
   Structure
**************************************************************************/
typedef struct _eons_plmn_info
{
    S8 pnn_plmn_num[MAX_MCC_MNC_LENGTH + 1];
    U8 pnn_identifier;
    U8 LAC1[2];
    U8 LAC2[2];
} EONSPLMNINFO;

/**************************************************************************
   Global variables
**************************************************************************/
static U8 pnn_record_number;        /* EF PNN record index to query */
static U8 opl_record_count = 1;     /* count for how many records which have been read */
static MMI_BOOL opl_read_finish = MMI_FALSE;
static EONSPLMNINFO g_eons_plmn_info[MAX_OPL_PNN_RECORD];

/* diamond, 2006/06/01 Prevent from sending this message twice before get the response */
static U8 eons_got_read_pnn_rsp = 1;

extern U8 gNWProviderName[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];   /* in SimDetection.c */
extern U8 gPLMN[MAX_PLMN_LEN_MMI];
extern S8 gHomePLMNNum[MAX_PLMN_LEN_MMI + 1];
extern S8 gOperatorName[MAX_LENGTH_OPERATOR_NAME * ENCODING_LENGTH];
extern U8 gOpNameValid;
extern U8 gShortOpnameValid;
extern U8 gLAC[2];


/**************************************************************************
   Function Prototypes
**************************************************************************/
extern void smsal_gsm7_unpack(
                kal_uint8 *old_data_ptr,
                kal_uint8 *new_data_ptr,
                kal_uint16 data_len,
                kal_uint16 offset);
extern kal_uint16 smsal_msg_len_in_character(kal_uint8 dcs, kal_uint16 len, kal_uint8 last_byte);
#ifdef __GEMINI__
extern kal_bool is_sim_replaced(kal_uint8 simInterface);
#else
extern kal_bool is_sim_replaced(void);
#endif
extern void RefreshNwProviderName(U8 *);


/**************************************************************************
   Get records of PNN:
      void mmi_eons_retrieve_name_from_table(U8 *data)
      void mmi_eons_retrieve_name_from_pnn(U16 length, U8 *data)
      void mmi_eons_get_pnn_record_rsp(void *msgPtr)
      void mmi_eons_get_pnn_record_req(U8 recordNo)
      void mmi_eons_replace_opn_by_pnn_for_hplmn_rsp(void *msgPtr)
      void mmi_eons_replace_opn_by_pnn_for_hplmn_req(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_retrieve_name_from_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_retrieve_name_from_table(U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * U16 count;
     * for(count = 0; count < MAX_PLMN_NO_LIST_LENGTH; ++count)
     * {
     * if(memcmp(sPlmnsToDisplayName[count],gPLMN,strlen((PS8) sPlmnsToDisplayName[count])) == 0)
     * break;
     * }
     * if(count < MAX_PLMN_NO_LIST_LENGTH)
     * memcpy((S8*)gNWProviderName,GetCurrentPLMNName((S8*)sPlmnsToDisplayName[count]),MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH);
     * else
     * mmi_asc_to_ucs2((S8*)gNWProviderName,(S8*)gPLMN);
     */
    *buffer = 0;    /* null string */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_retrieve_name_from_pnn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length      [IN]        
 *  data        [?]         
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_retrieve_name_from_pnn(U16 length, U8 *data, U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* data[0]: Network IEI */
    /* data[1]: Length   */
    /* data[2]-[n]: Name */
    U8 coding_scheme;
    U8 pnnDecode[MAX_LENGTH_DISPLAY_NAME];
    U8 pnnBuffer[MAX_LENGTH_DISPLAY_NAME];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //U8* pnnDecode = OslMalloc(data[1]*8/7 +1);
    //U8* pnnBuffer = OslMalloc(data[1]);

    memset(pnnDecode, 0, MAX_LENGTH_DISPLAY_NAME);
    memcpy(pnnBuffer, data + 3, data[1] - 1);
    *(pnnBuffer + data[1] - 1) = 0; /* set null-terminated char */

    coding_scheme = (data[2] & 0x70) >> 4;
    if (coding_scheme == 0)
    {
        /* Octets (packed GSM 7-bit default alphabet) in EF PNN  */
        smsal_gsm7_unpack(pnnBuffer, pnnDecode, smsal_msg_len_in_character(0, data[1] - 1, pnnBuffer[data[1] - 2]), 0);
        /* Unicode in display buffer */
        mmi_asc_to_ucs2((PS8) buffer, (PS8) pnnDecode);
    }
    else if (coding_scheme == 1)
    {
        /* Octets (UCS2) in EF PNN */
        U8 *convertedData = NULL;
        U8 dcs;

        switch (*pnnBuffer)
        {
            case 0x80:
                dcs = MMI_UCS2_DCS;
                break;
            case 0x81:
                dcs = MMI_UCS2_81;
                break;
            case 0x82:
                dcs = MMI_UCS2_82;
                break;
            default:
                dcs = 0;
                break;
        }
        if (dcs == 0)
        {
            mmi_eons_retrieve_name_from_table(buffer);
        }
        else
        {
            convertedData = CovertStringForPlatform(pnnBuffer + 1, data[1] - 2, dcs, NULL);
            mmi_ucs2cpy((PS8) buffer, (PS8) convertedData);
            OslMfree(convertedData);
        }
    }
    else
    {
        /* unknown format */
        mmi_eons_retrieve_name_from_table(buffer);
    }

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[EONS] PNN: %s", pnnDecode);

    //OslMfree(pnnDecode);
    //OslMfree(pnnBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_pnn_data_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_pnn_data_rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *pnnReadSimRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pnnReadSimRes = (mmi_smu_read_sim_rsp_struct*) msgPtr;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);
    eons_got_read_pnn_rsp = 1;

    /* EONS: Get the PLMN name string successfully, and save it to display buffer */
    if (pnnReadSimRes->result.flag == 0 && pnnReadSimRes->data[0] != 0xFF)
    {
        memset(gNWProviderName, 0, MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH);
        mmi_eons_retrieve_name_from_pnn(pnnReadSimRes->length, pnnReadSimRes->data, (PU8) gNWProviderName);
    }
    else
    {
        mmi_netset_retrieve_opname_from_plmn(gPLMN, gNWProviderName);
    }

    ChangeRoamingState();
    if (g_idle_context.IsOnIdleScreen && g_pwr_context.testRoaming == 3)
    {
        if (mmi_bootup_is_idle_screen_reached())
        {
            IdleRefreshServiceIndicationArea();
            idle_screen_show_network_details();
        } 
        else
        {
            EntryIdleScreen();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_pnn_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pnn_data_size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_pnn_data_req(U16 pnn_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: Get the record of EF PNN for camp on PLMN */
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_eons_get_pnn_data_rsp, PRT_MMI_SMU_READ_SIM_RSP);
    eons_got_read_pnn_rsp = 0;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_PNN_IDX;  /* PNN...FILE_PNN_IDX */
    dataPtr->para = (U8) pnn_record_number;
    dataPtr->length = pnn_data_size;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_pnn_record_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_pnn_record_rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *pnn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pnn_info = (mmi_smu_read_file_info_rsp_struct*) (msgPtr);

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_FILE_INFO_RSP);

    if (pnn_info->result.flag == 0)
    {
        mmi_eons_get_pnn_data_req((U16) (pnn_info->file_size / pnn_info->num_of_rec));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_pnn_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  recordNo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_pnn_record_req(U8 recordNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_smu_read_file_info_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (eons_got_read_pnn_rsp == 0)
    {
        /* diamond, 2006/06/01 Prevent from sending this message twice before get the response */
        return;
    }

    pnn_record_number = recordNo;

    SetProtocolEventHandler(mmi_eons_get_pnn_record_rsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    dataPtr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    dataPtr->file_idx = (U8) FILE_PNN_IDX;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/**************************************************************************
   Get records of OPL:
      void mmi_eons_retrieve_plmn_from_opl(U16 length, U8 *data)
      void mmi_eons_get_opl_record_rsp(void *msgPtr)
      void mmi_eons_get_opl_record_req(U8 recordNo)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_retrieve_plmn_from_opl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  length      [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_retrieve_plmn_from_opl(U16 length, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 PnnPlmn[MAX_MCC_MNC_LENGTH * 2 + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    /* data[0]-[6]: Location Area Identity (3-byte PLMN + 2-byte LAC * 2) */
    /* data[7]: PLMN Network Name Record Identifier (use this id to search the name in EF PNN */
    g_eons_plmn_info[opl_record_count - 1].pnn_plmn_num[0] = data[0];
    g_eons_plmn_info[opl_record_count - 1].pnn_plmn_num[1] = data[1];
    g_eons_plmn_info[opl_record_count - 1].pnn_plmn_num[2] = data[2];
    memcpy(&g_eons_plmn_info[opl_record_count - 1].LAC1[0], &data[3], 2);
    memcpy(&g_eons_plmn_info[opl_record_count - 1].LAC2[0], &data[5], 2);
    g_eons_plmn_info[opl_record_count - 1].pnn_identifier = data[7];

    mmi_eons_convert_plmn_bcd_format_to_string((U8*) g_eons_plmn_info[opl_record_count - 1].pnn_plmn_num, PnnPlmn);
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[EONS] OPL %02d: %s", opl_record_count, PnnPlmn);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_opl_record_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_opl_record_rsp(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *oplReadSimRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    oplReadSimRes = (mmi_smu_read_sim_rsp_struct*) msgPtr;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);

    if (oplReadSimRes->data[0] != 0xFF && opl_record_count < opl_record_number)
    {
        /* EONS: Get the BCD-formated PLMN successfully, and save it to memory */
        if (oplReadSimRes->result.flag == 0)
        {
            mmi_eons_retrieve_plmn_from_opl(oplReadSimRes->length, oplReadSimRes->data);
        }

        /* EONS: Get next one */
        mmi_eons_get_opl_record_req(++opl_record_count);
    }
    else
    {
        /* EONS: following records are invalid */
        opl_read_finish = MMI_TRUE;

        if (oplReadSimRes->data[0] == 0xFF)
        {
            opl_record_count--; /* invalid one */
        }

        if (opl_record_count == opl_record_number && oplReadSimRes->result.flag == 0)
        {
            mmi_eons_retrieve_plmn_from_opl(oplReadSimRes->length, oplReadSimRes->data);    /* the max supported record */
        }

        if (opl_record_count != 0)
        {
            gOpNameValid = 0; /* discard CPHS operator name if EONS is activated */
            gShortOpnameValid = 0;
        }
        else
        {
            opl_record_number = 0;
        }

        mmi_eons_write_opl_to_nvram();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_opl_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  recordNo        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_opl_record_req(U8 recordNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: Get the record of EF OPL */
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_eons_get_opl_record_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_OPL_IDX;  /* OPL...FILE_OPL_IDX */
    dataPtr->para = (U8) recordNo;
    dataPtr->length = 8;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

/**************************************************************************
   Get File Info of PNN and OPL:
      void mmi_eons_get_pnn_file_info_rsp(void *info)
      void mmi_eons_get_pnn_file_info_req(void)
      void mmi_eons_get_opl_file_info_rsp(void *info)
      void mmi_eons_get_opl_file_info_req(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_confirm_pnn_1st_validation_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_confirm_pnn_1st_validation_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *pnnReadSimRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pnnReadSimRes = (mmi_smu_read_sim_rsp_struct*) info;

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_SIM_RSP);

    if (pnnReadSimRes->result.flag == 0 && pnnReadSimRes->data[0] != 0xFF)
    {
        is_pnn_no_opl = MMI_TRUE;
        gOpNameValid = 0; /* discard CPHS operator name if EONS is activated */
        gShortOpnameValid = 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_eons_confirm_pnn_1st_validation_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pnn_data_size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_confirm_pnn_1st_validation_req(U16 pnn_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: Get the record of EF PNN for camp on PLMN */
    MYQUEUE Message;
    mmi_smu_read_sim_req_struct *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_eons_confirm_pnn_1st_validation_rsp, PRT_MMI_SMU_READ_SIM_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_SMU_READ_SIM_REQ;
    dataPtr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    dataPtr->file_idx = (U8) FILE_PNN_IDX;  /* PNN...FILE_PNN_IDX */
    dataPtr->para = 1;
    dataPtr->length = pnn_data_size;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_pnn_file_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_pnn_file_info_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: If PNN is also present, then try to get OPN first record */
    mmi_smu_read_file_info_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_read_file_info_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_FILE_INFO_RSP);

#ifdef __GEMINI__
    if (resp->result.flag == 0 && sim_service_table_query(SERVICE_PLMN_NAME, SIM1) == SERVICE_SUPPORT)
#else
    if (resp->result.flag == 0 && sim_service_table_query(SERVICE_PLMN_NAME) == SERVICE_SUPPORT)
#endif
    {
        if (opl_record_number != 0)
        {
            mmi_eons_get_opl_record_req(opl_record_count);
        }
        else
        {
           mmi_eons_confirm_pnn_1st_validation_req((U16) (resp->file_size / resp->num_of_rec));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_pnn_file_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_pnn_file_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: Get the file info of EF PNN */
    MYQUEUE msgStruct;
    mmi_smu_read_file_info_req_struct *pnnstatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_eons_get_pnn_file_info_rsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    pnnstatus = OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    pnnstatus->file_idx = (U8) FILE_PNN_IDX;    /* PNN...FILE_PNN_IDX */
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) pnnstatus;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_opl_file_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_opl_file_info_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: If OPL is present, then try to get PNN */
    mmi_smu_read_file_info_rsp_struct *resp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resp = (mmi_smu_read_file_info_rsp_struct*) (info);

    ClearProtocolEventHandler(PRT_MMI_SMU_READ_FILE_INFO_RSP);

#ifdef __GEMINI__
    if (resp->result.flag == 0 && sim_service_table_query(SERVICE_OPLMN_LIST, SIM1) == SERVICE_SUPPORT)
#else
    if (resp->result.flag == 0 && sim_service_table_query(SERVICE_OPLMN_LIST) == SERVICE_SUPPORT)
#endif
    {
        opl_record_number = (resp->num_of_rec < MAX_OPL_PNN_RECORD) ? resp->num_of_rec : MAX_OPL_PNN_RECORD;
    }
    else
    {
    #ifdef __GEMINI__
        if (is_sim_replaced(SIM1))
    #else
        if (is_sim_replaced())
    #endif
        {
            mmi_eons_reset_nvram();
        }
    }

    mmi_eons_get_pnn_file_info_req(); /* try to find EF_PNN no matter EF_OPL is present or not */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_get_opl_file_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_get_opl_file_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EONS: Get the file info of EF OPL */
    MYQUEUE msgStruct;
    mmi_smu_read_file_info_req_struct *oplstatus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_eons_get_opl_file_info_rsp, PRT_MMI_SMU_READ_FILE_INFO_RSP);

    oplstatus = OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    oplstatus->file_idx = (U8) FILE_OPL_IDX;    /* OPL...FILE_OPL_IDX */
    msgStruct.oslSrcId = MOD_MMI;
    msgStruct.oslDestId = MOD_L4C;
    msgStruct.oslMsgId = PRT_MMI_SMU_READ_FILE_INFO_REQ;
    msgStruct.oslSapId = INVALID_SAP;
    msgStruct.oslDataPtr = (oslParaType*) oplstatus;
    msgStruct.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&msgStruct);
}

/**************************************************************************
   Check if camp on PLMN is the same as anyone in OPL:
      U8 mmi_eons_check_if_plmn_present(U8 *UpdatePlmn)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_check_if_plmn_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UpdatePlmn      [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_eons_check_if_plmn_present(U8 *UpdatePlmn, U8 *UpdateLac)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, rtn = 0;
    U8 PnnPlmn[MAX_MCC_MNC_LENGTH * 2 + 1];

    U16 LAC_code_opl_1, LAC_code_opl_2, LAC_code_current;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen((PS8) UpdatePlmn) == 0)
    {
        return rtn;
    }

    LAC_code_current = UpdateLac[0] * 256 + UpdateLac[1];

    if (LAC_code_current == 0xFFFF)
    {
        return rtn;
    }

    for (i = 0; i < MAX_OPL_PNN_RECORD; i++)
    {
        mmi_eons_convert_plmn_bcd_format_to_string((U8*) g_eons_plmn_info[i].pnn_plmn_num, PnnPlmn);

        LAC_code_opl_1 = g_eons_plmn_info[i].LAC1[0] * 256 + g_eons_plmn_info[i].LAC1[1];
        LAC_code_opl_2 = g_eons_plmn_info[i].LAC2[0] * 256 + g_eons_plmn_info[i].LAC2[1];

        /* Compare camp on PLMN with PLMN in OPL, need to notice that the first parameter is camp on PLMN */
        if (mmi_netset_plmn_matching_criteria(PnnPlmn, UpdatePlmn) && (LAC_code_current >= LAC_code_opl_1 && LAC_code_current <= LAC_code_opl_2))
        {
            /* return which record in opl */
            rtn = g_eons_plmn_info[i].pnn_identifier;
            break;
        }
    }

    return rtn;
}

/**************************************************************************
   Update OPL to NVRAM:
      void mmi_eons_write_opl_to_nvram(void)
      void mmi_eons_read_opl_to_nvram(void)
      void mmi_eons_reset_nvram(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_write_opl_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_write_opl_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_buf[NVRAM_EF_EONS_INFO_SIZE];
    U8 i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvram_buf, 0xFF, NVRAM_EF_EONS_INFO_SIZE);

    for (i = 0; i < opl_record_count; i++)
    {
        nvram_buf[i * 8] = g_eons_plmn_info[i].pnn_plmn_num[0];
        nvram_buf[i * 8 + 1] = g_eons_plmn_info[i].pnn_plmn_num[1];
        nvram_buf[i * 8 + 2] = g_eons_plmn_info[i].pnn_plmn_num[2];
        nvram_buf[i * 8 + 3] = g_eons_plmn_info[i].pnn_identifier;
        memcpy(&nvram_buf[i * 8 + 4], &g_eons_plmn_info[i].LAC1[0], 2);
        memcpy(&nvram_buf[i * 8 + 6], &g_eons_plmn_info[i].LAC2[0], 2);
    }

    WriteRecord(NVRAM_EF_EONS_INFO_LID, 1, (void*)nvram_buf, NVRAM_EF_EONS_INFO_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_read_opl_from_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_read_opl_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_buf[NVRAM_EF_EONS_INFO_SIZE];
    U8 PnnPlmn[MAX_MCC_MNC_LENGTH * 2 + 1];
    U8 i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_EONS_INFO_LID, 1, (void*)nvram_buf, NVRAM_EF_EONS_INFO_SIZE, &error);

    for (i = 0; i < MAX_OPL_PNN_RECORD; i++)
    {
        g_eons_plmn_info[i].pnn_plmn_num[0] = nvram_buf[i * 8];
        g_eons_plmn_info[i].pnn_plmn_num[1] = nvram_buf[i * 8 + 1];
        g_eons_plmn_info[i].pnn_plmn_num[2] = nvram_buf[i * 8 + 2];
        g_eons_plmn_info[i].pnn_identifier = nvram_buf[i * 8 + 3];
        memcpy(&g_eons_plmn_info[i].LAC1[0], &nvram_buf[i * 8 + 4], 2);
        memcpy(&g_eons_plmn_info[i].LAC2[0], &nvram_buf[i * 8 + 6], 2);

        if (g_eons_plmn_info[i].pnn_identifier != 0xFF)
        {
            opl_record_number++;
        }

        mmi_eons_convert_plmn_bcd_format_to_string((U8*) g_eons_plmn_info[i].pnn_plmn_num, PnnPlmn);
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "[EONS] OPL %02d: %s", i + 1, PnnPlmn);
    }

    if (opl_record_number == 0)
    {
        mmi_eons_get_pnn_file_info_req(); /* try to find EF_PNN if no EF_OPL */
    }
    else
    {
        gOpNameValid = 0; /* discard CPHS operator name if EONS is activated */
        gShortOpnameValid = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_reset_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_reset_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_buf[NVRAM_EF_EONS_INFO_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvram_buf, 0xFF, NVRAM_EF_EONS_INFO_SIZE);
    WriteRecord(NVRAM_EF_EONS_INFO_LID, 1, (void*)nvram_buf, NVRAM_EF_EONS_INFO_SIZE, &error);
}

/**************************************************************************
   Utility:
      MMI_BOOL mmi_eons_check_roaming(void)
      MMI_BOOL mmi_eons_check_opl_read(void)
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_check_roaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_eons_check_roaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 plmn_str_1[MAX_PLMN_LEN_MMI], plmn_str_2[MAX_PLMN_LEN_MMI + 1];
    U8 rtn1, rtn2, rtn_tmp2_1, rtn_tmp2_2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(plmn_str_1, gHomePLMNNum, 5);    /* assumed that Home PLMN is 5-digit */
    plmn_str_1[5] = 0;
    memcpy(plmn_str_2, gHomePLMNNum, 6);    /* assumed that Home PLMN is 6-digit */
    plmn_str_2[6] = 0;

    rtn1 = mmi_eons_check_if_plmn_present(gPLMN, gLAC);
    rtn_tmp2_1 = mmi_eons_check_if_plmn_present(plmn_str_1, gLAC);
    rtn_tmp2_2 = mmi_eons_check_if_plmn_present(plmn_str_2, gLAC);

    if (rtn_tmp2_1 != 0)
    {
        rtn2 = rtn_tmp2_1;
    }
    else if (rtn_tmp2_2 != 0)
    {
        rtn2 = rtn_tmp2_2;
    }
    else
    {
        rtn2 = 0;
    }

    if (rtn1 == 0 && rtn2 == 0)
    {
        return MMI_FALSE;
    }
    else if (rtn1 != rtn2)
    {
        return MMI_FALSE;
    }
    else    /* rtn1=rtn2: the same name string for camp on PLMN and home PLMN */
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_check_opl_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_eons_check_opl_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return opl_read_finish;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_is_pnn_present_without_opl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_eons_is_pnn_present_without_opl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return is_pnn_no_opl;
}


/**************************************************************************
   Post-definition
**************************************************************************/
#endif /* __MMI_EONS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_is_service_available
 * DESCRIPTION
 *  Check if EF_PNN and EF_OPL are allocated and activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_eons_is_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    if (opl_record_number != 0)
    {
        return MMI_TRUE;
    }
    else if (is_pnn_no_opl)
    {
        return MMI_TRUE;
    }
    else
#endif /* __MMI_EONS_SUPPORT__ */
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_init
 * DESCRIPTION
 *  Read EONS files from SIM or NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EONS_SUPPORT__
    /* diamond, 2005/09/26 support PNN and OPL */
#ifdef __GEMINI__
    if (is_sim_replaced(SIM1))
#else
    if (is_sim_replaced())
#endif
    {
        mmi_eons_get_opl_file_info_req();
    }
    else
    {
        mmi_eons_read_opl_from_nvram();
    }
#endif /* __MMI_EONS_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_eons_convert_plmn_bcd_format_to_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  PlmnBcd         [?]     
 *  PlmnString      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_eons_convert_plmn_bcd_format_to_string(U8 *PlmnBcd, U8 *PlmnString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PlmnString[0] = 0x30 + (PlmnBcd[0] & 0x0F);
    PlmnString[1] = 0x30 + ((PlmnBcd[0] & 0xF0) >> 4);
    PlmnString[2] = 0x30 + (PlmnBcd[1] & 0x0F);
    PlmnString[3] = 0x30 + (PlmnBcd[2] & 0x0F);
    PlmnString[4] = 0x30 + ((PlmnBcd[2] & 0xF0) >> 4);
    if ((PlmnBcd[1] & 0xF0) == 0xF0)    /* 5-digit MCC/MNC */
    {
        PlmnString[5] = 0;
    }
    else    /* 6-digit MCC/MNC */
    {
        PlmnString[5] = 0x30 + ((PlmnBcd[1] & 0xF0) >> 4);
        PlmnString[6] = 0;
    }
}

