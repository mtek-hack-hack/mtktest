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
 *   em_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineer mode related structures.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

 
#ifndef _EM_STRUCT_H
#define _EM_STRUCT_H

typedef kal_uint32 request_info_type;

typedef enum
{
   /* RR */ 
   RR_EM_CELL_SELECT_PARA_INFO   = 0x00000001 ,
   RR_EM_CHANNEL_DESCR_INFO      = 0x00000002 ,
   RR_EM_CTRL_CHANNEL_DESCR_INFO = 0x00000004 ,
   RR_EM_RACH_CTRL_PARA_INFO     = 0x00000008 ,
   RR_EM_LAI_INFO                = 0x00000010 ,
   RR_EM_RADIO_LINK_COUNTER_INFO = 0x00000020 ,
   RR_EM_MEASUREMENT_REPORT_INFO = 0x00000040 ,
   
   /* CC */ 
   CC_EM_CHANNEL_INFO            = 0x00000080 ,
   CC_EM_CALL_INFO               = 0x00000100 ,
   
   /* CB */
   CB_EM_INFO                    = 0x00000200 ,
   
   /* SS */
   SS_EM_INFO                    = 0x00000400 ,
   
   /* MM */
   MM_EM_INFO                    = 0x00000800 ,
                                        
   /* UEM */                            
   UEM_EM_BATTERY_INFO           = 0x00001000 ,
   
   /* RR new structure */
   RR_EM_CONTROL_MSG_INFO        = 0x00002000 ,
   /* gprs em begins */
   RR_EM_TBF_INFO                = 0x00004000 ,
   RR_EM_GPRS_GENERAL_INFO       = 0x00008000 ,
   GMM_EM_INFO                   = 0x00010000 ,
   TCM_EM_EXT_PDP_INFO           = 0x00020000 ,
   TCM_EM_INT_PDP_INFO           = 0x00040000 ,
   SNDCP_EM_INFO                 = 0x00080000 ,
   LLC_EM_INFO                   = 0x00100000 ,
   PPP_EM_INFO                   = 0x00200000 ,
   SM_EM_INFO                    = 0x00400000 ,
   
   /*EM ehancement for RR new structure*/
   MMRR_EM_PLMN_INFO_STRUCT_INFO = 0x00800000 ,
   RR_EM_SI2Q_INFO_STRUCT_INFO   = 0x01000000 , 
   RR_EM_MI_INFO_STRUCT_INFO     = 0x02000000,
   RR_EM_BLK_INFO                = 0x04000000 

#ifdef __MTK_3G_MRAT_ARCH__
   ,
   /**
    * Gibran 20061228
    * UAS MEME/CSCE measuremnt and cell status structure
    */
   MEME_EM_RL_STATUS_IND_STRUCT_INFO           = 0x08000000 ,
   CSCE_EM_SERV_CELL_S_STATUS_IND_STRUCT_INFO  = 0x10000000 ,
   CSCE_EM_NEIGH_CELL_S_STATUS_IND_STRUCT_INFO = 0x20000000 ,
   CSCE_EM_CELL_R_STATUS_IND_STRUCT_INFO       = 0x40000000 , 
   CSCE_EM_MEAS_RULE_STATUS_IND_STRUCT_INFO    = 0x80000000
#endif /* __MTK_3G_MRAT_ARCH__ */
} em_info_enum;

typedef enum                     
{
	EM_NOT_ACTIVE,
	EM_FROM_MMI,
	EM_FROM_CATCHER,
	EM_FROM_RMMI	/* tommy add for RMMI EM support */
} em_source_enum;

typedef enum
{
	EM_CAUSE_OK,
	EM_CAUSE_INVALID_INFO_TYPE
} em_err_cause_enum;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef enum
{
    /*For quest to disable MT or not*/
    EM_MT_NOT_ALLOWED
} em_feature_enum;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef enum
{
    /*For turn on the feature or not*/
    EM_FEATURE_ON,
    EM_FEATURE_OFF
} em_feature_state_enum;

/* local parameter structures */
/* For L4CPS_EM_START_REQ, L4CPS_EM_STOP_REQ */
typedef struct
{
  kal_uint8 ref_count;
  kal_uint16 msg_len;
   request_info_type	info_request;
} l4cps_em_start_req_struct;

typedef l4cps_em_start_req_struct l4cps_em_stop_req_struct;

/*Byron: 2006/02/15: User can trigger RR to suspend cell reselection procedure in all state or transfer state*/
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 suspend_status; /* 0: in all RR states, 1: in RR GPRS transfer */
} l4cps_em_cell_resel_suspend_req_struct; 

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result; /* 0: in all RR states, 1: in RR GPRS transfer */
   kal_uint8 cause;
}l4cps_em_cell_resel_suspend_cnf_struct;

typedef l4cps_em_cell_resel_suspend_cnf_struct l4cps_em_cell_resel_resume_cnf_struct;

/*Byron: 2006/08/06: Add for cell lock*/
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool turn_on_or_off; /*0: Turn off, 1: Turn on*/
    kal_bool band_indicator; /* 0: not 1900 band cell, 1: 1900 band cell*/
    kal_uint16 lock_arfcn; /* The cell's arfcn to be locked*/
}l4cps_em_set_cell_lock_req_struct;

/*Byron: 2006/08/06: Add for cell lock*/
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result; /*0: Turn off, 1: Turn on*/
}l4cps_em_set_cell_lock_cnf_struct;

/*Byron: 2006/08/06: Add for cell lock*/
typedef struct{
    kal_bool result;
    kal_bool turn_on_or_off; /*0: Turn off, 1: Turn on*/
    kal_bool band_indicator; /*0: not 1900 band cell, 1: 1900 band cell*/
    kal_uint16 lock_arfcn; /* The cell's arfcn to be locked*/
}l4cps_em_get_cell_lock_cnf_struct;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    em_feature_enum em_feature;
    em_feature_state_enum em_feature_state;
} l4cps_em_feature_command_req_struct;

/*Byron: 2007/03/14: Add for request to RR from Engineering mode*/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    em_feature_enum em_feature;
    kal_bool result; /*0: Fail, 1: Success*/
} l4cps_em_feature_command_cnf_struct;

/* For L4CPS_EM_START_CNF, L4CPS_EM_STOP_CNF */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool	result;
   kal_uint8	cause;
   request_info_type	info_request;
} l4cps_em_start_cnf_struct;

typedef l4cps_em_start_cnf_struct l4cps_em_stop_cnf_struct;

/* For L4CPS_EM_STATUS_IND */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   em_info_enum	em_info;
} l4cps_em_info_req_struct;

typedef l4cps_em_info_req_struct l4cps_em_status_ind_struct;

/* For TSTL4C_EM_START_REQ, TSTL4C_EM_STOP_REQ */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   module_type mod_id;
   request_info_type	info_request;
} tstl4c_em_start_req_struct;

typedef tstl4c_em_start_req_struct tstl4c_em_stop_req_struct;


/* peer buffer structures */
/* RR structure */		
typedef struct
{
	kal_uint8	crh;   //CELL-RESELECT-HYSTERESIS
	kal_uint8	ms_txpwr;   // 	maximum TX power level an MS may use when accessing on a CCH
	kal_uint8	rxlev_access_min;   //	minimum received signal level at the MS for which it is permitted to access the system
} rr_em_cell_select_para_info_struct;
			
typedef struct
{
	kal_uint8	channel_type;   //	channel type
	kal_uint8	tn;   //	timeslot number
	kal_uint8	tsc;   //	training sequence code
	kal_uint8	hopping_flag;   //	hopping or not
	kal_uint8	maio;   //	MAIO value
	kal_uint8	hsn;   //	HSN value
	kal_uint8	num_of_carriers;   //	number of carriers in the BA list(in the non-hopping case, this shall be set to 1)
	kal_uint16	arfcn[64];   //	ARFCN value in the MA
	kal_bool     is_BCCH_arfcn_valid; /*the BCCH_arfcn is only valid 
	                              when receives H.O cmd in DEDI-state*/
	kal_uint16 BCCH_arfcn;   //	Target_BCCH carrier
	
	/*ZY:2006-08-15 add cipher algo for EM */
	kal_uint8	cipher_algo;  // ciphering value, OFF/A51/A52
	
	/* brwang, 051024, [AMR engineering mode info.] */
       #ifdef __AMR_SUPPORT__
//	rr_mpal_amr_req_struct amr_decode_buf;
       kal_bool amr_valid; /* the AMR(TRUE) or not(FALSE) */
       kal_uint32 frame_number;/* the frame number to get RATSCCH messages */
       kal_uint8 cmip;  /* CMI phase */
       kal_uint8 mr_ver;   /* MultiRate speech VERsion : 001-amr verion 1*/
       kal_bool nscb;      /* Noise Supression Control Bit : 0-noise supression is used */
       kal_bool icmi;       /* Initial Codec Mode Indicator : 0-is defined bythe implicit rule */
       kal_uint8 start_codec_mode; /* Start Codec Mode */
       kal_uint8 acs;       /* AMR Codec Activate Set */
       kal_uint8 threshold[3]; /* Threshold1/Threshold2/Threshold3 */
       kal_uint8 hysteresis[3]; /* Hysteresis1/Hysteresis2/Hysteresis3 */
       #endif
} rr_em_channel_descr_info_struct;	//This shall be used in IDLE and DEDI state
			
typedef struct
{	
	kal_uint8	mscr;   //	MSC release
	kal_uint8	att;   //	att flag
	kal_uint8	bs_ag_blks_res;   //	BS-AG-BLKS-RES
	kal_uint8	ccch_conf;   //	CCCH-CONF
	kal_uint8	cbq2;   //	Cell Bar Qualify 2
	kal_uint8	bs_pa_mfrms;   //	BS-PA-MFRMS
	kal_uint8	t3212;   //	T3212 timeout value
} rr_em_ctrl_channel_descr_info_struct;
			
typedef struct
{		
	kal_uint8	max_retrans;   //	MAX Retrans value
	kal_uint8	tx_integer;   //	TX integer
	kal_uint8	cba;   //	cell bar for access
	kal_uint8	re;   //	call reestablishment allowed
	kal_uint8	acc_class[2];   //	acces control class
	kal_bool	CB_supported;	// cell broadcast is supported
} rr_em_rach_ctrl_para_info_struct;
			
typedef struct
{			
	kal_uint8	mcc[3];	//MCC
	kal_uint8	mnc[3];	//MNC
	kal_uint8	lac[2];	//LAC
	kal_uint16	cell_id;	 //cell ID
	kal_uint8	nc_info_index; // index in rlc array to acquire the corresponding arfcn, bsic, rxlevel...
} rr_em_lai_info_struct;
					
typedef struct
{			
	kal_uint16	max_value;   //	timeout value for the DSF or RLF
	kal_int16	current_value;   //	current value in the DSF or RLF calculation
	kal_uint8	dtx_ind;	//DTX indicator
	kal_uint8	dtx_used;	//DTX used or not
	kal_bool	is_dsf;		//timeout value for the DSF or RLF	
} rr_em_radio_link_counter_info_struct;  //This shall be used in IDLE and DEDI state
			
typedef struct
{
	
	kal_uint8	rr_state;	//current RR state	1: IDLE, 2: ACCESS, 3: PKT_TRANSFER 4: DEDICATED
	kal_uint16	serving_arfcn;	//serving cell ARFCN
	kal_uint8	serving_bsic;	//serving cell BSIC
	kal_uint8	serv_gprs_supported;	//serving cell support GPRS or not		
	kal_int16	serv_rla_in_quarter_dbm;	/*rssi level for serving cell (BCCH
                   	                  in IDLE-state) & (TCH in DEDI-state) & (PDTCH in TRANSFER-state) */
    	kal_bool     is_serv_BCCH_rla_valid;  /*To indicate if the serv_BCCH rssi is valid*/                   	                     
	kal_int16	serv_BCCH_rla_in_dedi_state;	/*rssi level for serving cell (BCCH) in DEDI-State*/
	kal_uint8	quality;	//serving cell -TCH measured quality	

   	/* 2003-0919, add new C31/C32 cvalue information for GPRS service */
   	kal_bool     gprs_pbcch_present; // To indicate if the current cell supports GPRS & PBCCH is present

	/* 2003-0919, add new C31/C32 cvalue information for GPRS service */
   	kal_bool     gprs_c31_c32_enable; // To indicate if the current mode is GPRS_PMO_MODE or GPRS_PCCCH_MODE
	kal_int16	c31[32];	//C31 value for the neighbor cell	   

	kal_int16	c1_serv_cell;	//C1 value for the serving cell
	kal_int16	c2_serv_cell;	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for serv_cell
	                              if gprs_c31_c32_enable is true, this field is shown as c32_value for serv_cell */
	kal_int16	c31_serv_cell;	/* if gprs_c31_c32_enable is false, this field is ignore
	                              if gprs_c31_c32_enable is true, this field shall be shown in based on report c31_value*/
	                                 

	kal_uint8	num_of_carriers;	//number of carriers in the BA list
	kal_uint16	nc_arfcn[32];	//ARFCN value in the BA list(The list will be sorted by the RSSI level)
	kal_int16	rla_in_quarter_dbm[32];	//rssi level for each carrier
	kal_uint8	nc_info_status[32];	/*Bit0 = 0: "nc_bsic","frame_offset","ebit_offset" is invalid
									Bit0 = 1: "nc_bsic","frame_offset","ebit_offset" is valid
             									Bit1 = 0: "c1","c2" is invalid
             									Bit1 = 1: "c1","c2" is valid 
             									Bit2 = 0: "gprs_status" is invalid
             									Bit2 = 1: "gprs_status" is valid */
	kal_uint8	nc_bsic[32];	//neighbor cell BSIC
	kal_int32	frame_offset[32];	//frame offset for each carrier
	kal_int32	ebit_offset[32];	//ebit offset for each carrier
	kal_int16	c1[32];	//C1 value for the neighbor cell
	kal_int16	c2[32];	/* if gprs_c31_c32_enable is false, this field is shown as c2_value for nbr_cell
                           if gprs_c31_c32_enable is true, this field is shown as c32_value for nbr_cell */

	
	//kal_uint8	nbr_gprs_supported[32];	//0: not supported, 1: supported
	kal_uint8	multiband_report;	//MULTIBAND_REPORT value
	kal_uint8	timing_advance;		//Timing advance, range is 0 - 63
	kal_uint8	rxqual_sub;		//rx quality (sub), range is 0 - 7
	kal_uint8	rxqual_full;		//RX quality (full), range is 0 - 7
#ifdef __AMR_SUPPORT__
    kal_bool amr_info_valid;
    kal_uint8 cmr_cmc_cmiu_cmid;
    kal_uint8 c_i;
    kal_uint16 icm;
    kal_uint16 acs;
#endif /* __AMR_SUPPORT__ */
/* brwang, 05/12/27, cell lock support */    
#ifdef __FWP_NC_LAI_INFO__
	kal_uint8	num_of_nc_lai;			/* how many valid LAI info in nc_lai[] array */
	rr_em_lai_info_struct	nc_lai[6]; 	/* store LAI and CID for at most 6 strongest neighbor cells */
#endif /* __FWP_NC_LAI_INFO__ */
/* brwang, 05/12/27, cell lock support */   
} rr_em_measurement_report_info_struct;	//This shall be used in IDLE and DEDI state;
			
typedef struct
{	
	kal_uint8	msg_type;	/*receives msg type from network in Dedi-State
	                          0: Assignment Command
	                          1: Channel Release
	                          2: Additional Assignment 
	                          3: Classmark Enquiry
	                          4: Ciphering Mode Command
	                          5: Configure Change Command
	                          6: Handover Command
	                          7: Frequency Redefinition
	                          8: Channel Mode Modify
	                          9: Cell Selection Indicator*/
	                           	                           
} rr_em_control_msg_info_struct;

/* CC structure */
typedef struct
{
   kal_uint8   cause;	//channel sync cause
   kal_uint8   channel_type;	//channel type
   kal_uint8   channel_mode;	//channel mode
} cc_em_channel_info_struct;

typedef struct
{
	kal_uint8	call_id;	//call id
	kal_uint8	ti;	//transaction identifier
	kal_uint8	state;	//call state
	kal_uint8	aux_state;	//auxiliary state
   	kal_uint8	pi; //progress indicator
	kal_uint16	cause;	//call disconnect cause
	kal_uint8	cause_location;	//cause originating locatioin   
} cc_em_call_info_struct;

/* CB structure */
typedef struct
{
	kal_uint16	sn;	//serial number
	kal_uint16	mi;	//message identifier
	kal_uint8	dcs;	//data code scheme
	kal_uint8	page;	//current number of this page
	kal_uint8	pages;	//total number of pages
} cb_em_info_struct;
     
/* SS structure */
typedef struct
{			
	kal_uint8	ss_state;	//ciss state
	kal_uint8	ti;	//transaction identifier
	kal_uint8	call_id;	//call id
	kal_uint8	invoke_id;	//invoke id
	kal_uint8	num_invoke;	//number of active invokes
	kal_uint8	op_code;	//operation code
	kal_uint8	ss_code;	//supplementary service code
	kal_uint8	bs_code;	//basic service code
} ss_em_info_struct;

/* MM structure */ 
typedef struct
{
	kal_uint8	t3212_val;	//T3212 timer value
	kal_uint8	att_flag;	//ATT flag
	kal_uint8	mm_cause;	//MM Reject cause, if any
	kal_uint8	mm_state;	//MM State
   	kal_uint8	mcc[3];	//MCC
   	kal_uint8	mnc[3];	//MNC
	kal_uint8   loc[2];	 //registered LAC
   	kal_uint8   rac;     //registered RAC
	kal_uint8	tmsi[4];	//TMSI, if valid
} mm_em_info_struct;

/* UEM structure */
typedef struct
{
	kal_int32	adc_value;	//battery ADC value
	kal_uint8	battery_level;	//battery level
	kal_uint8	battery_status;	//battery status: battery_status_enum
} uem_em_battery_info;




typedef struct
{
   kal_uint8   flc_buffer_type;     // reference to gprs_flc_buffer_enum
   kal_uint8   pool_active;         // true or false
   kal_uint8	percentage_upp_thre; //percentage of upper threshold
   kal_uint8	percentage_low_thre; //	percentage of lower threshold
   kal_uint32	total_size;          //	total size of pol
   kal_uint32	curr_occ;            //	current occupied
   kal_uint16	hit_upp_thre_counts; //	upper threshold hit counter
   kal_uint16	hit_low_thre_counts; //	lower threshold hit counter
} flc_em_pool_status_struct;

extern kal_bool flc_em_get_pool_staus(kal_uint8 poolid,
                     flc_em_pool_status_struct *status);


/* The rr_em_tbf_status_struct is updated whenever TBF is established/reallocated or released. */
typedef struct
{
	kal_uint8	tbf_mode;                // GPRS or EGPRS TBF mode

	/* UL TBF info */
	kal_uint8	ul_tbf_status;      //	access/active/inactive
	kal_uint8	ul_rel_cause;       //	if applicable
	kal_uint8	ul_ts_allocation;   // timeslot allocation  
	kal_uint8 ul_rlc_mode;            // RLC ACK / UNACK mode
	kal_uint8 ul_mac_mode;         // Dynamic allocation / Extended dynamic allocation / Fixed allocation
       /* new created fields */
       kal_uint16 number_rlc_octect;  // RLC requested octect/byte number
	kal_uint8 ul_tfi;
	kal_uint8 ul_granularity;
	kal_uint8 ul_usf;
       kal_uint8 ul_tai;
       kal_uint16 ul_tqi;       
	kal_uint16  ul_window_size;    // GPRS: 64, EGPRS 64 ~1024   
			
       /* DL TBF info */
	kal_uint8	dl_tbf_status;     //	active/inactive/release pending
	kal_uint8	dl_rel_cause;      //	if applicable
	kal_uint8	dl_ts_allocation;      // Ttimeslot allocation
	kal_uint8 dl_rlc_mode;            // RLC ACK / UNACK mode
	kal_uint8 dl_mac_mode;          // Dynamic allocation / Extended dynamic allocation / Fixed allocation
       /* new created fields */
	kal_uint8 dl_tfi;
       kal_uint8 dl_tai;
	kal_uint16 dl_window_size;	// GPRS: 64, EGPRS 64 ~1024   
#ifdef __EGPRS_MODE__	
	kal_uint8 dl_out_of_memory;   // EGPRS IR out of memory indication
#endif /* __EGPRS_MODE__ */
}rr_em_tbf_status_struct;

/* The new rr_em_blk_info_struct is updated every N (configurable?) block period during TBF. 
    N should be adjusted to suitable/smooth display rate. */
typedef struct
{
	/* UL TBF info */       
	kal_uint8	ul_coding_scheme;   
	kal_uint8 ul_cv;
	kal_uint8 ul_tlli;
	kal_uint16 ul_bsn1;
#ifdef __EGPRS_MODE__	
	kal_uint16 ul_bsn2;
       kal_uint8 ul_cps;
	kal_uint8 ul_rsb;
	kal_uint8 ul_spb;
#endif /* __EGPRS_MODE__ */

	/* DL TBF info */
	kal_uint8 dl_c_value_in_rx_level;  /* for both GPRS/EGPRS C value (channel quality) */
       kal_uint8 dl_rxqual;                         /* for GPRS RX QUAL (channel quality) */
       kal_uint8 dl_sign_var;                     /* for GPRS signal variance (channel quality) */
                     
	kal_uint8 dl_coding_scheme;
	kal_uint8 dl_fbi;
	kal_uint16 dl_bsn1;	
#ifdef __EGPRS_MODE__	
	kal_uint16 dl_bsn2;
	kal_uint8 dl_cps;
	kal_uint8 dl_gmsk_mean_bep_lev;	  /* for EGPRS GMSK mean BEP level (channel quality). valid: 0 ~ 31. invalid: 255 */
	kal_uint8 dl_8psk_mean_bep_lev;	  /* for EGPRS 8PSK mean BEP level (channel quality) . valid: 0 ~ 31. invalid: 255 */
       kal_uint8 dl_tn_mean_bep_lev[8];	  /* for EGPRS Timeslot Number mean BEP level (channel quality). valid: 0 ~ 31. invalid: 255 */		
#endif /* __EGPRS_MODE__ */       
       kal_uint8 dl_tn_interference_lev[8]; /* for GPRS/EGPRS Timeslot Number interference (channel quality). valid: 0 ~ 15. invalid: 255 */		       
}rr_em_blk_info_struct;

typedef struct 
{
	kal_uint32	t3192;  // in msec
	kal_uint32	t3168;  // in msec
	kal_uint8   	rp;     // radio priority
	kal_uint8  	gprs_support;	//GPRS channel request support(0 support,1 not support)
	kal_uint8 	egprs_support; 
	kal_uint8  	sgsn_r;		//PS domain is R99 or R98(0 R98,1 R99)
	kal_uint8  	pfc_support;	//packet flow context support(0 support,1 not support)
	kal_uint8  	epcr_support;	//EGPRS channel request support(0 support,1 not support)
	kal_uint8  	bep_period;	//BEP period
}rr_em_gprs_general_info_struct;

typedef struct
{
	kal_uint32	num_pkt_txed;    // number of packets transferred
	kal_uint32	num_pkt_rxed;    // number of packets received.
	kal_uint32	num_octets_txed;  // number of octets transferred
	kal_uint32	num_octets_rxed;	// number of octets received.
}tcm_em_pdp_info_struct;

typedef struct
{
   kal_uint8   nsapi; // NSAPI 
	kal_uint8	pdp_context_status; //	active/inactive
	kal_uint8	rej_cause;          //	if applicable
	kal_uint8	reliability_class;  //	reliabillity class of QoS
	kal_uint8	rp;  //radio priority
} sm_em_pdp_info_struct;

typedef struct{
   sm_em_pdp_info_struct pdp[2];
} sm_em_info_struct;

typedef struct
{
	kal_uint16	ready_timer; //	Ready timer value in SECONDS.
	kal_uint16	rau_timer;   //	Periodical Routing Area Updating timer value in deci-hours
	kal_uint8	ms_state;    //	    MS_NULL_STATE = 0,
                            //    MS_READY_STATE,
                            //    MS_STANDBY_STATE,
                            //    MS_FORCED_TO_STANDBY_STATE
}gmm_em_info_struct;



typedef struct
{
	kal_uint32	num_checksum_error;
	kal_uint32  requested_ip;
	kal_uint32  negotiated_ip;
	kal_uint32  requested_dns;
	kal_uint32  negotiated_dns;
} ppp_em_info_struct;


typedef struct
{
	kal_uint32	num_reasm_failure;
} sndcp_em_info_struct;

typedef struct
{
	kal_uint32	num_fcs_error;
} llc_em_info_struct;

/* brwang, 20070727, [EM Cell ID Lock function] { */    

#define L4C_MAX_EM_CELL_LOCK_NUM 16
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8		 num_of_nc_lai;
   rr_em_lai_info_struct nc_lai[L4C_MAX_EM_CELL_LOCK_NUM];
} l4cps_em_set_cell_id_lock_req_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool result; 
} l4cps_em_set_cell_id_lock_cnf_struct;

/* brwang, 20070727, [EM Cell ID Lock function]  } */    


typedef struct
{
    kal_uint8 is_higher_pri_plmn_srch; /* indicate that if the higher priority PLMN search is performing */
    kal_uint8 hp_timeout_timer; /* higher priority PLMN search timer (6 mins per unit) */
    kal_uint8 hp_count_down_timer; /* higher priority PLMN search count down timer (6 mins per unit) */
    kal_uint8 rplmn[6]; /* RPLMN */
    kal_uint8 eq_plmn[5][6]; /* 1~5 equivalent PLMNs (6 digits for each PLMN ID) */
    kal_uint8 forbid_plmn[4][6]; /* 1~4 forbidden PLMNs (6 digits for each PLMN ID) */
} mmrr_plmn_info_struct;

/*Byron: 2006/08/06: Add for SI2q information*/
typedef struct
{
	kal_bool 	present;	
	kal_uint8 no_of_instance;
	kal_bool 	emr_report;
       kal_bool 	pemr_report;
	kal_bool 	umts_parameter_exist;
} rr_em_si2q_info_struct;

/*Byron: 2006/08/06: Add for measurement information*/
typedef struct
{
	kal_bool 	present;
	kal_uint8 no_of_instance;
	kal_bool 	emr_report;
	kal_bool 	umts_parameter_exist;
} rr_em_mi_info_struct;

/*mtk00924: 061106 add for network event notify*/
typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_bool 	is_on;
} l4cps_em_nw_event_notify_req_struct;

typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_bool 	result;
} l4cps_em_nw_event_notify_cnf_struct;

typedef struct
{
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint8 group_id;
	kal_uint32 event_id;
} l4cps_em_nw_event_notify_ind_struct;

#ifdef __MTK_3G_MRAT_ARCH__

typedef struct
{
    kal_uint8	        cellidx;
    kal_uint16        psc;
    kal_uint8         ec_no;                     /* Ec/No. 0 ~ 49 to represent for (-25~0) dB in 0.5 dB step */
    kal_uint8         rscp;                      /* RSCP. 0 ~ 91 to represent for (-116 ~ 25 )dBm in 1 dB step*/
    kal_int16         off;                       /* FN offset. -1 ~ 4095 : -1 means unknown timing */
    kal_int32         tm;                        /* Cell boundary. -1 ~ 38400*8-1 : -1 means unknown timing*/    
}meme_em_active_set;


typedef struct
{
	kal_uint8         active_set_count;
	meme_em_active_set   active_set[8];
} meme_em_active_set_list_struct;

typedef struct
{
	kal_uint8        ref_count;
	kal_uint16	     msg_len;
	kal_uint16       uarfcn_DL;
  kal_int16    tx_power;                           /* Averaged TX power meas result */
	meme_em_active_set_list_struct active_set_list;
} meme_em_rl_status_ind_struct;

/**
 * Gibran 20061228
 * Added Cell Status for EM in Catcher 
 */
typedef struct
{
   kal_uint8         cellidx;
   kal_uint16        uarfcn_DL;
   kal_uint16        psc;
   kal_bool	         is_s_criteria_satisfied;
   /* is_s_criteria_satisfied, 0: FALSE, 1: TRUE */
   kal_int8          qQualmin;
   kal_int8          qRxlevmin;
   /* the following value should be divided by 1024, the result may be float */
   kal_int32         srxlev;                     
   kal_int32         squal;                      
   kal_int32         rscp;                       
   kal_int32         ec_no;                      
} csce_em_serv_cell_s_status;

typedef struct
{
   kal_uint8         cellidx;
   kal_uint16        uarfcn_DL;
   kal_uint16        psc;
   kal_int8          qQualmin;
   kal_int8          qRxlevmin;
   /* the following value should be divided by 1024, the result may be float */
   kal_int32         srxlev;        
   kal_int32         squal;         
   kal_int32         rscp;          
   kal_int32         ec_no;         
} csce_em_neigh_cell_s_status;

typedef struct
{
   kal_uint8         cellidx;
   kal_uint16        arfcn;
   kal_uint8         bsic;
   kal_bool          is_bsic_verified;
   kal_uint8         freq_band;
   /* 0: 1800Band, 1: 1900Band */
   kal_int8          qRxlevmin;
   /* the following value should be divided by 1024, the result may be float */
   kal_int32         srxlev;        
   kal_int32         rssi;          
} csce_em_2G_neigh_cell_s_status;
 
typedef struct
{
   kal_uint8                       ref_count;
   kal_uint16                      msg_len;
   csce_em_serv_cell_s_status      serv_cell;
} csce_em_serv_cell_s_status_ind_struct;

typedef enum
{
	EM_UMTS_CELL,
	EM_GSM_CELL
} em_RAT_type_enum;

typedef struct
{
   kal_uint8               ref_count;
   kal_uint16              msg_len;	
   kal_uint8               neigh_cell_count;
   em_RAT_type_enum        RAT_type;
   union
   {
      csce_em_neigh_cell_s_status      neigh_cells[8];
      csce_em_2G_neigh_cell_s_status   GSM_neigh_cells[8];
   }
   choice;
   /* for the element over neigh_cell_count, shows N/A */ 
} csce_em_s_satisfied_neigh_cell_s_status_ind_struct;

typedef struct
{
   kal_uint8      cellidx;
   kal_uint8      celltype;  /* 1: ServCell, 2: IntraFreq NeighCell, 3: InterFreq NeighCell, 4: InterRAT NeighCell */
   kal_int32      r_value;   /* the value should be divided by 1024, the result may be float */
   kal_uint8      chan_fail_type;   /* 0: Normal, 1: BCH failure, 2: Attempt failure, 4: MainCH failure */
} csce_em_cell_r_status;

typedef struct
{
   kal_uint8               ref_count;
   kal_uint16              msg_len;	
   kal_uint8               cell_count;
   csce_em_cell_r_status   cell_r_status[9];      /* for the element over neigh_cell_count, shows N/A */ 
} csce_em_cell_r_status_ind_struct;

typedef struct
{
   kal_uint8        ref_count;
   kal_uint16       msg_len;	
   /* the "sx","s_intra_search_value","s_intra_search_value" should be divided by 1024, the result may be float */
   kal_int32        sx;
   kal_bool         is_s_intra_search_valid;
   kal_int32        s_intra_search_value;
   kal_bool         is_s_inter_search_valid;
   kal_int32        s_inter_search_value;
   /* For meas_tgt_cells, 0: Serv Cell only, 1: Serv with IntraFreq Cell, 3: Serv with Intra/InterFreq Cell */	
   kal_uint32       meas_tgt_cells; 
} csce_em_meas_rule_status_ind_struct;

#endif /* __MTK_3G_MRAT_ARCH__ */

#endif /* ~_EM_STRUCT_H */

