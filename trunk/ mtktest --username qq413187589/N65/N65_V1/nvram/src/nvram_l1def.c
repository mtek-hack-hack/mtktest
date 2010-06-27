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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * nvram_l1def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file provides a fuction for NVRAM Task to get L1 default value
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"        /* Basic data type */
#include "nvram_data_items.h"
#include "nvram_l1def.h"

#ifdef __MTK_TARGET__

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "nvram_struct.h"
#include "custom_nvram_sec.h"
#include "nvram_sec.h"
#include "nvram_drv_int.h"
#include "nvram_context.h"
#include "nvram_handler_read.h"
#include "nvram_io.h"

/* L1 calibration data defination */
#include "m12190.h"
#include "m12193.h"
#include "l1cal.h"

#if defined(__WIFI_SUPPORT__)
#include "wndrv_cal.h"
#endif 

#include "l1d_custom_rf.h"
#include "l1d_rf.h"
/* For access audio data items */
#include "nvram_user_defs.h"

extern const signed short Speech_Input_FIR_Coeff[6][45];
extern const signed short Speech_Output_FIR_Coeff[6][45];
extern const unsigned short Speech_Common_Para[12];
extern const unsigned short Speech_Normal_Mode_Para[8];
extern const unsigned short Speech_Earphone_Mode_Para[8];
extern const unsigned short Speech_LoudSpk_Mode_Para[8];
extern const unsigned short Speech_BT_Earphone_Mode_Para[8];
extern const unsigned short Speech_BT_Cordless_Mode_Para[8];
extern const unsigned short Speech_AUX1_Mode_Para[8];
extern const unsigned short Speech_AUX2_Mode_Para[8];
extern const unsigned short Speech_AUX3_Mode_Para[8];
extern const unsigned short Media_Playback_Maximum_Swing;
extern const signed short Melody_FIR[];
extern const signed short Audio_Compensation_Filter[2][45];

#if defined(__WIFI_SUPPORT__)
extern const wndrv_cal_mac_addr_struct wndrv_default_mac_addr;
extern const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M;
extern const wndrv_cal_txpwr_5000M_struct wndrv_default_txpwr_5000M;
extern const wndrv_cal_dac_dc_offset_struct wndrv_default_dac_dc_offset;
#endif /* defined(__WIFI_SUPPORT__) */ 

/*
 * extern const unsigned char bbtx_trim_i;             
 * extern const unsigned char bbtx_trim_q;             
 * extern const unsigned char bbtx_offset_i;           
 * extern const unsigned char bbtx_offset_q;           
 */




/*****************************************************************************
 * FUNCTION
 *  nvram_send_L1_cal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_send_L1_cal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /**
    *    file_idx should be the first L1 element in the logical data item ID enum
    *    Currently, L1 calibration data element is as following:
    *    NVRAM_EF_L1_AGCPATHLOSS_LID, NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
    *    NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 
    *    NVRAM_EF_L1_AFCDATA_LID, VRAM_EF_L1_L1SPFC_LID, 
    */

    nvram_lid_enum file_idx;
    ltable_entry_struct *ldi;
    peer_buff_struct *peer_buf_ptr;
    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length;
    nvram_read_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

    for (file_idx = NVRAM_EF_L1_START; file_idx <= NVRAM_EF_L1_END; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }
        
        switch(file_idx)
        {
            case NVRAM_EF_L1_AGCPATHLOSS_LID:
            case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
            case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
            case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
            case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
        #if defined(__EPSK_TX__)
            case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
            case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
            case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
            case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
            case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
            case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
            case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
            case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
        #endif /* __EPSK_TX__ */ 
            case NVRAM_EF_L1_AFCDATA_LID:
            case NVRAM_EF_L1_TXIQ_LID:
            case NVRAM_EF_L1_RFSPECIALCOEF_LID:
            case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
            case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
            case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
            case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
            case NVRAM_EF_L1_CRYSTAL_AFCDATA_LID:
            case NVRAM_EF_L1_CRYSTAL_CAPDATA_LID:
            {
                nvram_get_data_item(ldi, file_idx);
        
                local_data->access_id = 0;
                local_data->file_idx = file_idx;
                local_data->para = 1;
        
                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                ASSERT(peer_buf_ptr != NULL);
        
                pdu_ptr = get_pdu_ptr(peer_buf_ptr, &pdu_length);
                ASSERT(pdu_ptr != NULL);
        
                nvram_read_confirm
                    (MOD_L1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                
                break;
            }
        }
    }

    free_local_para((local_para_struct*) local_data);

}   /* end of nvram_send_L1_cal function */

#endif /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_get_L1_default_value_to_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lid         [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint16 i, j;
    l1cal_agcPathLoss_T *agc;
    l1cal_rampTable_T *ramp;
    l1cal_afcData_T afc;

    /* l1cal_txiq_T  txiq; */
    FrequencyBand band = NULL;

    l1cal_interRampData_T *interRamp;

#if defined(__EPSK_TX__)
    l1cal_EPSK_interRampData_T *EPSK_interRamp;
#endif 
    l1cal_crystalAfcData_T *crystalAfc;
    l1cal_crystalCapData_T *crystalCap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lid)
    {
        case NVRAM_EF_L1_AGCPATHLOSS_LID:
            /* L1 Data - AGC */
            agc = (l1cal_agcPathLoss_T*) buffer;
            for (i = 0; i < FrequencyBandCount; i++)
            {
                if (AGC_PATHLOSS_TABLE[i] != 0)
                {
                    kal_mem_cpy(
                        &agc->agcPathLoss[i][0],
                        AGC_PATHLOSS_TABLE[i],
                        (sizeof(sAGCGAINOFFSET) * PLTABLE_SIZE));
                }
            }
            break;
        case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
        case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
        case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
        case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
            /* L1 Data - Ramp */
            ramp = (l1cal_rampTable_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_RAMPTABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_RAMPTABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (RampData[band] != 0)
            {
                kal_mem_cpy(&ramp->rampData, RampData[band], sizeof(sRAMPDATA));
            }
            break;
        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
        case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
            /* L1 Data - Ramp */
            ramp = (l1cal_rampTable_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            if (RampData_EPSK[band] != 0)
            {
                kal_mem_cpy(&ramp->rampData, RampData_EPSK[band], sizeof(sRAMPDATA));
            }
            break;
        #endif /* defined(__EPSK_TX__) */ 
        case NVRAM_EF_L1_AFCDATA_LID:
            /* L1 Data - Afc */
            afc.dacValue = PSI_EE;
            afc.slopeInv = C_PSI_STA;
            kal_mem_cpy(buffer, &afc, sizeof(l1cal_afcData_T));
            break;
        case NVRAM_EF_L1_TXIQ_LID:
            /* L1 Data - TX IQ */
            //txiq.TxTrimI   = bbtx_trim_i;
            //txiq.TxTrimQ   = bbtx_trim_q;
            //txiq.TxOffsetI = bbtx_offset_i;
            //txiq.TxOffsetQ = bbtx_offset_q;
            //kal_mem_cpy(buffer, &txiq, sizeof(l1cal_txiq_T));
            kal_mem_cpy(buffer, &BBTXParameters, sizeof(l1cal_txiq_T));
            break;
        case NVRAM_EF_L1_RFSPECIALCOEF_LID:
            /* L1 Data - RF Special coef */
        {
            extern void L1D_RF_Init_SpecialCoef(void);

            L1D_RF_Init_SpecialCoef();
        }
            kal_mem_cpy(buffer, &RFSpecialCoef, sizeof(l1cal_rfspecialcoef_T));
            break;
        case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
        case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
            interRamp = (l1cal_interRampData_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            /* Shine modified start */
            if (InterRampData[band] != 0)
            {
                kal_mem_cpy(&(interRamp->interRampData[0]), InterRampData[band], sizeof(sMIDRAMPDATA));
            }
            /* Shine modified end */
            break;

        #if defined(__EPSK_TX__)
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
        case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
            EPSK_interRamp = (l1cal_EPSK_interRampData_T*) buffer;
            switch (lid)
            {
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID:
                    band = FrequencyBand850;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID:
                    band = FrequencyBand900;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID:
                    band = FrequencyBand1800;
                    break;
                case NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID:
                    band = FrequencyBand1900;
                    break;
            }
            for (i = 0; i < 4; i++)
            {
                if ((*(EPSK_InterRampData[band])[i]) != 0)
                {
                    kal_mem_cpy(
                        &(EPSK_interRamp->EPSK_interRampData[i]),
                        (*(EPSK_InterRampData[band])[i]),
                        sizeof(sMIDRAMPDATA));
                }
            }
            break;
        #endif /* defined(__EPSK_TX__) */ 

        case NVRAM_EF_L1_CRYSTAL_AFCDATA_LID:
            /* Shine modified start */
            crystalAfc = (l1cal_crystalAfcData_T*) buffer;
            kal_mem_cpy(&(crystalAfc->XO_SlopeAreaData[0]), XO_SlopeAreaData, sizeof(l1cal_crystalAfcData_T));
            /* Shine modified end */
            break;
        case NVRAM_EF_L1_CRYSTAL_CAPDATA_LID:
            /* Shine modified start */
            crystalCap = (l1cal_crystalCapData_T*) buffer;
            kal_mem_cpy(&(crystalCap->cap_id), &XO_CapID, sizeof(l1cal_crystalCapData_T));
            /* Shine modified end */
            break;

        case NVRAM_EF_AUDIO_PARAM_LID:
            /* Audio parameters  */
            /*********************************************************/
            /* !!! NOTICE !!! */
            /* ****************************************************** */
            /*  The current configuration of NVRAM_EF_AUDIO_PARAM_SIZE is 1466
             *  If wanna add parameters, plz double check the data size
             *  Or even I cound not know what'll happen
             ********************************************************/
            i = 0;
            for(j = 0; j < 6; j++)
            {
                kal_mem_cpy((buffer + i), (void*)&Speech_Input_FIR_Coeff[j][0], (sizeof(kal_uint16) * 45));
                i += sizeof(kal_uint16) * 45;
            }
            for(j = 0; j < 6; j++)
            {
                kal_mem_cpy((buffer + i), (void*)&Speech_Output_FIR_Coeff[j][0], (sizeof(kal_uint16) * 45));
                i += sizeof(kal_uint16) * 45;
            }
            *(kal_uint16*) (buffer + i) = 0;
            i += sizeof(kal_uint16);
            kal_mem_cpy((buffer + i), &Speech_Common_Para[0], sizeof(kal_uint16) * 12);
            i += sizeof(kal_uint16) * 12;
            kal_mem_cpy((buffer + i), &Speech_Normal_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_Earphone_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_LoudSpk_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_BT_Earphone_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_BT_Cordless_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_AUX1_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_AUX2_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Speech_AUX3_Mode_Para[0], sizeof(kal_uint16) * 8);
            i += sizeof(kal_uint16) * 8;
            kal_mem_cpy((buffer + i), &Media_Playback_Maximum_Swing, sizeof(kal_int16));
            i += sizeof(kal_int16);
            kal_mem_cpy((buffer + i), (void*)&Melody_FIR[0], (sizeof(kal_uint16) * 25));
            i += sizeof(kal_uint16) * 25;

    #ifdef AUDIO_COMPENSATION_ENABLE
            for(j = 0; j < 2; j++)
            {
                kal_mem_cpy((buffer + i), (void*)&Audio_Compensation_Filter[j][0], (sizeof(kal_int16) * 45));
                i += sizeof(kal_int16) * 45;
            }
    #endif /* AUDIO_COMPENSATION_ENABLE */

            break;
        #if defined(__WIFI_SUPPORT__)
        case NVRAM_EF_WNDRV_MAC_ADDRESS_LID:
        {
            void wndrv_get_nvram_default_mac_addr(wndrv_cal_mac_addr_struct * m);
            wndrv_cal_mac_addr_struct mac;

            wndrv_get_nvram_default_mac_addr(&mac);
            kal_mem_cpy((wndrv_cal_mac_addr_struct*) buffer, &mac, sizeof(wndrv_cal_mac_addr_struct));
        }
            break;

        case NVRAM_EF_WNDRV_TX_POWER_2400M_LID:
        {
            void wndrv_get_nvram_default_txpwr_2400M(wndrv_cal_txpwr_2400M_struct * t);
            wndrv_cal_txpwr_2400M_struct txpwr;

            wndrv_get_nvram_default_txpwr_2400M(&txpwr);
            kal_mem_cpy((wndrv_cal_txpwr_2400M_struct*) buffer, &txpwr, sizeof(wndrv_cal_txpwr_2400M_struct));
        }
            break;

        case NVRAM_EF_WNDRV_TX_POWER_5000M_LID:
        {
            void wndrv_get_nvram_default_txpwr_5000M(wndrv_cal_txpwr_5000M_struct * t);
            wndrv_cal_txpwr_5000M_struct txpwr;

            wndrv_get_nvram_default_txpwr_5000M(&txpwr);
            kal_mem_cpy((wndrv_cal_txpwr_5000M_struct*) buffer, &txpwr, sizeof(wndrv_cal_txpwr_5000M_struct));
        }
            break;

        case NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID:
        {
            void wndrv_get_nvram_default_dac_dc_offset(wndrv_cal_dac_dc_offset_struct * d);
            wndrv_cal_dac_dc_offset_struct offset;

            wndrv_get_nvram_default_dac_dc_offset(&offset);

            kal_mem_cpy((wndrv_cal_dac_dc_offset_struct*) buffer, &offset, sizeof(wndrv_cal_dac_dc_offset_struct));
        }
            break;
        case NVRAM_EF_WNDRV_TX_ALC_POWER_LID:
        {
            void wndrv_get_nvram_default_tx_ALC_pwr_2400M(wndrv_cal_tx_ALC_2400M_struct * t);
            wndrv_cal_tx_ALC_2400M_struct txALC;

            wndrv_get_nvram_default_tx_ALC_pwr_2400M(&txALC);
            kal_mem_cpy((wndrv_cal_tx_ALC_2400M_struct*) buffer, &txALC, sizeof(wndrv_cal_tx_ALC_2400M_struct));
        }
            break;
        case NVRAM_EF_WNDRV_ALC_SLOPE_LID:
        {
            extern void wndrv_get_nvram_default_ALC_Slope_2400M (wndrv_cal_ALC_Slope_2400M_struct *t);
            wndrv_cal_ALC_Slope_2400M_struct alcSlope;

            wndrv_get_nvram_default_ALC_Slope_2400M(&alcSlope);
            kal_mem_cpy((wndrv_cal_ALC_Slope_2400M_struct*) buffer, &alcSlope, sizeof(wndrv_cal_ALC_Slope_2400M_struct));
        }
            break;
        #endif /* defined(__WIFI_SUPPORT__) */ 
        default:
    #if defined(__WCDMA_RAT__) &&  defined(__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __WCDMA_RAT__ && __MTK_UL1_FDD__ */
            ASSERT(KAL_FALSE);
            break;
    }

#endif /* __MTK_TARGET__ */ 

}

