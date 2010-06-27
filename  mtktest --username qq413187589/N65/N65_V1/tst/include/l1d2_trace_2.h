#ifndef L1TRC_L1D_SEC_2_DEF_H
#define L1TRC_L1D_SEC_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_AFC_REASON_STR(v1)	(v1+0)
#define L1D_Str_Bool(v1)	(v1+14)
#define L1I_DCM_status_STR(v1)	(v1+16)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1I_Msg_AFC_Assert_Reason_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Assert_Reason_2(v1);\
} while(0)
#else
	#define L1I_Msg_AFC_Assert_Reason_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFC_TQ_TIME_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_TQ_TIME_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_AFC_TQ_TIME_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFC_Assert34_2(v1, v2, v3) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Assert34_2(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_AFC_Assert34_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_VTuneCrt7AREA_2(v1, v2, v3, v4) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_XO_TRACE_VTuneCrt7AREA_2(v1, v2, v3, v4);\
} while(0)
#else
	#define XO_TRACE_VTuneCrt7AREA_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_FreqCrtUpdate_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_XO_TRACE_FreqCrtUpdate_2(v1, v2);\
} while(0)
#else
	#define XO_TRACE_FreqCrtUpdate_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_ReadTempADC_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_XO_TRACE_ReadTempADC_2(v1, v2);\
} while(0)
#else
	#define XO_TRACE_ReadTempADC_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_CmpTempPhi_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_XO_TRACE_CmpTempPhi_2(v1);\
} while(0)
#else
	#define XO_TRACE_CmpTempPhi_2(v1)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_Phi2Dac_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_XO_TRACE_Phi2Dac_2(v1, v2);\
} while(0)
#else
	#define XO_TRACE_Phi2Dac_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_SB_Status_Extend_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_SB_Status_Extend_2(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1D_SB_Status_Extend_2(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_HIGHSNR_BADBLOCK_2() do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK_2();\
} while(0)
#else
	#define L1D_Trc_HIGHSNR_BADBLOCK_2() 
#endif

#ifdef L1_CATCHER
	#define L1D_SP_flag_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_SP_flag_2(v1);\
} while(0)
#else
	#define L1D_SP_flag_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_SP_flag_Fsig_no_data_tx_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx_2(v1);\
} while(0)
#else
	#define L1D_SP_flag_Fsig_no_data_tx_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_DCM_status_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_DCM_status_2(v1);\
} while(0)
#else
	#define L1I_DCM_status_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_OK_AT_STATE_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_OK_AT_STATE_2(v1);\
} while(0)
#else
	#define L1D_PCH_OK_AT_STATE_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_CCCH_OK_AT_STATE_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_CCCH_OK_AT_STATE_2(v1);\
} while(0)
#else
	#define L1D_CCCH_OK_AT_STATE_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_One_Burst_Enable_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_One_Burst_Enable_2(v1);\
} while(0)
#else
	#define L1D_PCH_One_Burst_Enable_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_Null_Detect_2() do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_Null_Detect_2();\
} while(0)
#else
	#define L1D_PCH_Null_Detect_2() 
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_Empty_Detect_2() do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_Empty_Detect_2();\
} while(0)
#else
	#define L1D_PCH_Empty_Detect_2() 
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_Pattern_2(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_Pattern_2(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1D_PCH_Pattern_2(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_PM_LEN_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_TRC_PM_LEN_2(v1);\
} while(0)
#else
	#define L1D_TRC_PM_LEN_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_8PM_ENABLE_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_TRC_8PM_ENABLE_2(v1);\
} while(0)
#else
	#define L1D_TRC_8PM_ENABLE_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DP6TapEQStatus_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DP6TapEQStatus_2(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DP6TapEQStatus_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_WATCH_DOG_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_DSP_WATCH_DOG_2(v1);\
} while(0)
#else
	#define L1D_DSP_WATCH_DOG_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_RX_FILTER_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1D_DSP_RX_FILTER_2(v1);\
} while(0)
#else
	#define L1D_DSP_RX_FILTER_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_CD2nd_CRC_Pass_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass_2(v1, v2);\
} while(0)
#else
	#define L1D_Trc_CD2nd_CRC_Pass_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_TCH_HandoverState_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_TCH_HandoverState_2(v1);\
} while(0)
#else
	#define L1D_TRC_TCH_HandoverState_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_GetReportInAdvance_2() do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_GetReportInAdvance_2();\
} while(0)
#else
	#define L1D_TRC_GetReportInAdvance_2() 
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_RACH2FACCH_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_RACH2FACCH_2(v1);\
} while(0)
#else
	#define L1D_TRC_RACH2FACCH_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_SABM_FACCH_Counter_2(v1) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_SABM_FACCH_Counter_2(v1);\
} while(0)
#else
	#define L1D_TRC_SABM_FACCH_Counter_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_Tx_ARFCN_TA_2(v1, v2) do {\
		if(L1D_SEC_2_Trace_Filter[0]==1 && (L1D_SEC_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_Tx_ARFCN_TA_2(v1, v2);\
} while(0)
#else
	#define L1D_Trc_Tx_ARFCN_TA_2(v1, v2)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1D_SEC_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AFC_Assert_Reason_2(unsigned char v1);
void L1TRC_Send_L1I_Msg_AFC_TQ_TIME_2(short v1, short v2);
void L1TRC_Send_L1I_Msg_AFC_Assert34_2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_XO_TRACE_VTuneCrt7AREA_2(char v1, long v2, short v3, long v4);
void L1TRC_Send_XO_TRACE_FreqCrtUpdate_2(char v1, short v2);
void L1TRC_Send_XO_TRACE_ReadTempADC_2(short v1, long v2);
void L1TRC_Send_XO_TRACE_CmpTempPhi_2(long v1);
void L1TRC_Send_XO_TRACE_Phi2Dac_2(long v1, short v2);
void L1TRC_Send_L1D_SB_Status_Extend_2(short v1, unsigned char v2, short v3, short v4, char v5, short v6, short v7);
void L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK_2(void);
void L1TRC_Send_L1D_SP_flag_2(short v1);
void L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx_2(short v1);
void L1TRC_Send_L1I_DCM_status_2(unsigned char v1);
void L1TRC_Send_L1D_PCH_OK_AT_STATE_2(short v1);
void L1TRC_Send_L1D_CCCH_OK_AT_STATE_2(short v1);
void L1TRC_Send_L1D_PCH_One_Burst_Enable_2(short v1);
void L1TRC_Send_L1D_PCH_Null_Detect_2(void);
void L1TRC_Send_L1D_PCH_Empty_Detect_2(void);
void L1TRC_Send_L1D_PCH_Pattern_2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1D_TRC_PM_LEN_2(short v1);
void L1TRC_Send_L1D_TRC_8PM_ENABLE_2(char v1);
void L1TRC_Send_L1D_Trc_DP6TapEQStatus_2(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_DSP_WATCH_DOG_2(char v1);
void L1TRC_Send_L1D_DSP_RX_FILTER_2(short v1);
void L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass_2(char v1, unsigned short v2);
void L1TRC_Send_L1D_TRC_TCH_HandoverState_2(char v1);
void L1TRC_Send_L1D_TRC_GetReportInAdvance_2(void);
void L1TRC_Send_L1D_TRC_RACH2FACCH_2(unsigned char v1);
void L1TRC_Send_L1D_TRC_SABM_FACCH_Counter_2(char v1);
void L1TRC_Send_L1D_Trc_Tx_ARFCN_TA_2(short v1, short v2);

void Set_L1D_SEC_2_Filter(unsigned char *setting);

#endif


#endif
