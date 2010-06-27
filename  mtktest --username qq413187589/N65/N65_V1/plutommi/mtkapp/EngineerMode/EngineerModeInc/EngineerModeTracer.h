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
 * Filename:
 * ---------
 * EngineerModeTracer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the tracer for PS log
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
#if defined(__MMI_ENGINEER_MODE__) && defined(__EM_MODE__)

/*****************************************************************/
/********************  Structures / Definitions ******************/
/*****************************************************************/


typedef struct
{
    kal_uint8 crh;              /* CELL-RESELECT-HYSTERESIS */
    kal_uint8 ms_txpwr;         /* maximum TX power level an MS may use when accessing on a CCH */
    kal_uint8 rxlev_access_min; /* minimum received signal level at the MS for which it is permitted to access the system */
    kal_uint8 is_present;
} mmi_rr_em_cell_select_para_info_t;

typedef struct
{
    kal_uint8 channel_type;     /* channel type */
    kal_uint8 hopping_flag;     /* hopping or not */
    kal_uint8 hsn;              /* HSN value */
    kal_uint8 tn;               /* timeslot number */
    kal_uint8 maio;             /* MAIO value */
    kal_uint8 num_of_carriers;  /* number of carriers in the BA list(in the non-hopping case, this shall be set to 1) */
    kal_uint8 tsc;              /* training sequence code */
    kal_uint8 is_present;

#ifdef __AMR_SUPPORT__
    kal_bool amr_valid;         /* the AMR(TRUE) or not(FALSE) */
    kal_uint32 frame_number;    /* the frame number to get RATSCCH messages */
    kal_uint8 cmip;             /* CMI phase */
    kal_uint8 mr_ver;           /* MultiRate speech VERsion : 001-amr verion 1 */
    kal_bool nscb;              /* Noise Supression Control Bit : 0-noise supression is used */
    kal_bool icmi;              /* Initial Codec Mode Indicator : 0-is defined bythe implicit rule */
    kal_uint8 start_codec_mode; /* Start Codec Mode */
    kal_uint8 acs;              /* AMR Codec Activate Set */
    kal_uint8 threshold[3];     /* Threshold1/Threshold2/Threshold3 */
    kal_uint8 hysteresis[3];    /* Hysteresis1/Hysteresis2/Hysteresis3 */
#endif /* __AMR_SUPPORT__ */ 

    kal_uint8 cipher_algo;
} mmi_rr_em_channel_descr_info_t;

typedef struct
{
    kal_uint8 mscr;             /* MSC release */
    kal_uint8 att;              /* att flag */
    kal_uint8 bs_ag_blks_res;   /* BS-AG-BLKS-RES */
    kal_uint8 ccch_conf;        /* CCCH-CONF */
    kal_uint8 cbq2;             /* Cell Bar Qualify 2 */
    kal_uint8 bs_pa_mfrms;      /* BS-PA-MFRMS */
    kal_uint8 t3212;            /* T3212 timeout value */
    kal_uint8 is_present;
} mmi_rr_em_ctrl_channel_descr_info_t;

typedef struct
{
    kal_uint8 max_retrans;  /* MAX Retrans value */
    kal_uint8 tx_integer;   /* TX integer */
    kal_uint8 cba;          /* cell bar for access */
    kal_uint8 re;           /* call reestablishment allowed */
    kal_uint8 acc_class[2]; /* acces control class */
    kal_uint8 is_present;
    kal_bool    CB_supported;
} mmi_rr_em_rach_ctrl_para_info_t;

typedef struct
{
    kal_uint8 mcc[3];   /* MCC */
    kal_uint8 mnc[3];   /* MNC */
    kal_uint8 lac[2];   /* LAC */
    kal_uint16 cell_id; /* cell ID */
    kal_uint8 is_present;
} mmi_rr_em_lai_info_t;

typedef struct
{
    kal_uint16 max_value;       /* timeout value for the DSF or RLF */
    kal_int16 current_value;    /* current value in the DSF or RLF calculation */
    kal_uint8 dtx_ind;          /* DTX indicator */
    kal_uint8 dtx_used;         /* DTX used or not */
    kal_uint8 is_present;
    kal_bool    is_dsf;
} mmi_rr_em_radio_link_counter_info_t;

typedef struct
{
    kal_uint16 nc_arfcn[12];    /* Top 12 */
    kal_int16 rla_in_quarter_dbm[12];
    kal_int16 c1[12];
    kal_int16 c2[12];
    kal_uint8 nc_info_status[12];
    kal_uint16 serving_arfcn;
    kal_int16 serv_rla_in_quarter_dbm;
    kal_int16 c1_serv_cell;
    kal_int16 c2_serv_cell;
    kal_uint8 serving_bsic;
    kal_uint8 serv_gprs_supported;
    kal_bool gprs_pbcch_present;
    kal_uint8 num_of_carriers;
    kal_uint8 rr_state;
    kal_uint8 multiband_report;
    kal_uint8 is_present;
    kal_uint8   timing_advance;
    kal_uint8   rxqual_sub;
    kal_uint8   rxqual_full;

#ifdef __AMR_SUPPORT__
    kal_bool amr_info_valid;
    kal_uint8 cmr_cmc_cmiu_cmid;
    kal_uint8 c_i;
    kal_uint16 icm;
    kal_uint16 acs;
#endif /* __AMR_SUPPORT__ */
   
} mmi_rr_em_measurement_report_info_t;


/*****************************************************************/
/***************************  Functions **************************/
/*****************************************************************/
extern void HighlightEmNetworkSetting(void);
extern void EntryEmNetworkSettingMenu(void);
extern void HighlightEmNetworkInfo(void);
extern void EntryEmNetworkInfoMenu(void);

#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__)
/* under construction !*/
#endif /* #if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */

extern void HighlightEmNWCellLock(void);

extern void SetEmModeIndex(S32 nIndex);
extern void EnableDisableEmMode(void);
extern void CheckEmMode(void);
extern void GoBackFromNetworkSetting(void);
extern void SendEmStartMsg(void);
extern void EngineerModeStartReq(U32 mod_id, U32 info_req);
extern void EngineerModeStatusUpdate(U32 mod_id, U32 info_req);
extern void EngineerModeStatusIndHdlr(void *inMsg);

#if defined(__EM_MODE__)

extern void HighlightEmNWNetworkEvents(void);
extern void EntryEmNetworkEventMenu(void);
extern void EmNWEventPrepareContext(void);

extern void HighlightEmNWStart(void);
extern void EmNetworkEventStartReq(void);

extern void HighlightEmNWFilter(void);
extern void EntryEmNWEventFilterMenu(void);
extern void EmNWEventGroupFilterHighlightIndex(S32 index);
extern void HighlightHandlerEmNwEventGroupFilterInline(S32 index);
extern void EntryEmNwEventFilterEdit(void);
extern void EmNwEventFilterEditHighlightIndex(S32 nIndex);
extern void EmNWEventSetFilter(void);

extern void HighlightEmNWSetting(void);
extern void EntryEmNWEventSettingMenu(void);
extern void EntryEmNetworkEventGroup(void);
extern void EntryNWEventUpdateSrc(void);
extern void EmNWEventUpdate(void);
extern void EmNwEventInlineEditHighlightHdlr(S32 index);
extern void EntryNwEventSelectRingTone(void);
extern void em_nw_event_select_ring(void);
extern void em_nw_event_ring_get_id_callback(U8 ExtMelodyFlag, U16 ringToneId);
extern void em_nw_event_select_ring_done(U16 ringToneId);
extern void EmNWEventStartStopReq(void);
extern void EmNWEventStartStopRsp(void *inMsg);
extern void EngineerModeNWEventNotifyInd(void *inMsg);
extern void EmNWPlayEventToneHdlr(void);
#endif /* defined(__EM_MODE__) */

extern void mmi_em_send_start_req(module_type mod_id, request_info_type info_id);
extern void mmi_em_display_init(void);
extern void mmi_em_trace_on_ind(void);
extern void mmi_em_parsing_data(void *info);
extern void mmi_em_show_screen(void);
extern void mmi_em_exit_screen(void);
extern void mmi_em_tracer_key(void);
extern void mmi_em_tracer_key_up(void);
extern void mmi_em_tracer_key_down(void);
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_em_tracer_pen_down(mmi_pen_point_struct pos);
#endif 
extern void mmi_em_rr_process_logs(kal_uint32 em_info, peer_buff_struct *pdu_buff_ptr);
extern void mmi_em_rr_cell_select_logs_value(rr_em_cell_select_para_info_struct *rr_em_cell_select_para_info);
extern void mmi_em_rr_channel_descr_logs_value(rr_em_channel_descr_info_struct *rr_em_channel_descr_info);
extern void mmi_em_rr_ctrl_channel_descr_logs_value(rr_em_ctrl_channel_descr_info_struct *rr_em_ctrl_channel_descr_info);
extern void mmi_em_rr_rach_ctrl_para_info_logs_value(rr_em_rach_ctrl_para_info_struct *rr_em_rach_ctrl_para_info);
extern void mmi_em_rr_lai_info_logs_value(rr_em_lai_info_struct *rr_em_lai_info);
extern void mmi_em_rr_radio_link_counter_info_logs_value(rr_em_radio_link_counter_info_struct *rr_em_radio_link_counter_info);
extern void mmi_em_rr_measurement_report_info_logs_value(rr_em_measurement_report_info_struct *rr_em_measurement_report_info);
extern void mmi_em_display_screen_n(kal_uint8 screen_num);
extern void mmi_em_tracer_screen_color_init(kal_uint8 color_r, kal_uint8 color_g, kal_uint8 color_b);
extern kal_uint8 mmi_show_screen_text_log(int screen_number);
extern void mmi_em_display_line_n(kal_int32 *text_pos, kal_uint8 *str);
extern kal_uint8 mmi_em_rr_measurement_report_info_logs(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info);
extern kal_uint8 mmi_em_rr_measurement_report_info_logs_2(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info);
extern kal_uint8 mmi_em_rr_cell_select_logs(
            kal_uint8 screen_num,
            mmi_rr_em_cell_select_para_info_t *rr_em_cell_select_para_info);
extern kal_uint8 mmi_em_rr_channel_descr_logs(kal_uint8 screen_num, mmi_rr_em_channel_descr_info_t *rr_em_channel_descr_info);
extern kal_uint8 mmi_em_rr_ctrl_channel_descr_logs(
            kal_uint8 screen_num,
            mmi_rr_em_ctrl_channel_descr_info_t *rr_em_ctrl_channel_descr_info);
extern kal_uint8 mmi_em_rr_rach_ctrl_para_info_logs(
            kal_uint8 screen_num,
            mmi_rr_em_rach_ctrl_para_info_t *rr_em_rach_ctrl_para_info);
extern kal_uint8 mmi_em_rr_lai_info_logs(kal_uint8 screen_num, mmi_rr_em_lai_info_t *rr_em_lai_info);
extern kal_uint8 mmi_em_rr_radio_link_counter_info_logs(
            kal_uint8 screen_num,
            mmi_rr_em_radio_link_counter_info_t *rr_em_radio_link_counter_info);
extern kal_uint8 mmi_em_rr_c1_c2_logs(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info);
extern kal_uint8 mmi_em_rr_c1_c2_logs_2(
            kal_uint8 screen_num,
            mmi_rr_em_measurement_report_info_t *rr_em_measurement_report_info);

extern void mmi_em_rr_plmn_info_logs_value(mmrr_plmn_info_struct *rr_plmn_info);
extern void mmi_em_rr_gprs_general_info_logs_value(rr_em_gprs_general_info_struct *rr_em_gprs_general_info);
extern void mmi_em_rr_si2q_info_logs_value(rr_em_si2q_info_struct *rr_em_si2q_info);
extern void mmi_em_rr_mi_info_logs_value(rr_em_mi_info_struct *rr_em_mi_info);
extern void mmi_em_rr_tbf_info_logs_value(rr_em_tbf_status_struct *rr_em_tbf_info);
extern void mmi_em_rr_blk_info_logs_value(rr_em_blk_info_struct *rr_em_blk_info);

extern kal_uint8 mmi_em_rr_plmn_info_logs(kal_uint8 screen_num);
extern kal_uint8 mmi_em_rr_gprs_general_info_logs(kal_uint8 screen_num);
extern kal_uint8 mmi_em_rr_si2q_mi_info_logs(kal_uint8 screen_num);

extern kal_uint8 mmi_em_rr_tbf_info_logs(kal_uint8 screen_num);
extern kal_uint8 mmi_em_rr_blk_info_logs(kal_uint8 screen_num);

extern void EntryEmNWPreferRatMenu(U8 index);
extern void EntryEmNWCellLockMenu(MMI_BOOL on_off, MMI_BOOL band_onoff, U16 arfcn);
extern void HighlightHdlrEmCellLockInline(S32 index);
extern void EmSetNWCellLock(void); 
extern void ExitEmNWCellLockInlineScr(void);
extern void HighlightHandlerNWCellLockEnableInline(S32 index) ;


#endif /* defined(__MMI_ENGINEER_MODE__) && defined(__EM_MODE__) */

