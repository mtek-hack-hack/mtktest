#ifndef L1TRC_L1D_SEC_DEF_H
#define L1TRC_L1D_SEC_DEF_H

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
	#define L1I_Msg_AFC_Assert_Reason(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Assert_Reason(v1);\
} while(0)
#else
	#define L1I_Msg_AFC_Assert_Reason(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFC_TQ_TIME(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_TQ_TIME(v1, v2);\
} while(0)
#else
	#define L1I_Msg_AFC_TQ_TIME(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFC_Assert34(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_Assert34(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_AFC_Assert34(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4);\
} while(0)
#else
	#define XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_FreqCrtUpdate(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_XO_TRACE_FreqCrtUpdate(v1, v2);\
} while(0)
#else
	#define XO_TRACE_FreqCrtUpdate(v1, v2)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_ReadTempADC(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_XO_TRACE_ReadTempADC(v1, v2);\
} while(0)
#else
	#define XO_TRACE_ReadTempADC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_CmpTempPhi(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_XO_TRACE_CmpTempPhi(v1);\
} while(0)
#else
	#define XO_TRACE_CmpTempPhi(v1)
#endif

#ifdef L1_CATCHER
	#define XO_TRACE_Phi2Dac(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_XO_TRACE_Phi2Dac(v1, v2);\
} while(0)
#else
	#define XO_TRACE_Phi2Dac(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_HIGHSNR_BADBLOCK() do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK();\
} while(0)
#else
	#define L1D_Trc_HIGHSNR_BADBLOCK() 
#endif

#ifdef L1_CATCHER
	#define L1D_SP_flag(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_SP_flag(v1);\
} while(0)
#else
	#define L1D_SP_flag(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_SP_flag_Fsig_no_data_tx(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx(v1);\
} while(0)
#else
	#define L1D_SP_flag_Fsig_no_data_tx(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_DCM_status(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_DCM_status(v1);\
} while(0)
#else
	#define L1I_DCM_status(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_OK_AT_STATE(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_OK_AT_STATE(v1);\
} while(0)
#else
	#define L1D_PCH_OK_AT_STATE(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_CCCH_OK_AT_STATE(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_CCCH_OK_AT_STATE(v1);\
} while(0)
#else
	#define L1D_CCCH_OK_AT_STATE(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_One_Burst_Enable(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_One_Burst_Enable(v1);\
} while(0)
#else
	#define L1D_PCH_One_Burst_Enable(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_Null_Detect() do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_Null_Detect();\
} while(0)
#else
	#define L1D_PCH_Null_Detect() 
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_Empty_Detect() do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_Empty_Detect();\
} while(0)
#else
	#define L1D_PCH_Empty_Detect() 
#endif

#ifdef L1_CATCHER
	#define L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_PM_LEN(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_TRC_PM_LEN(v1);\
} while(0)
#else
	#define L1D_TRC_PM_LEN(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_8PM_ENABLE(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_TRC_8PM_ENABLE(v1);\
} while(0)
#else
	#define L1D_TRC_8PM_ENABLE(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DP6TapEQStatus(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DP6TapEQStatus(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DP6TapEQStatus(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_WATCH_DOG(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_DSP_WATCH_DOG(v1);\
} while(0)
#else
	#define L1D_DSP_WATCH_DOG(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_RX_FILTER(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1D_DSP_RX_FILTER(v1);\
} while(0)
#else
	#define L1D_DSP_RX_FILTER(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_CD2nd_CRC_Pass(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass(v1, v2);\
} while(0)
#else
	#define L1D_Trc_CD2nd_CRC_Pass(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_TCH_HandoverState(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_TCH_HandoverState(v1);\
} while(0)
#else
	#define L1D_TRC_TCH_HandoverState(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_GetReportInAdvance() do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_GetReportInAdvance();\
} while(0)
#else
	#define L1D_TRC_GetReportInAdvance() 
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_RACH2FACCH(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_RACH2FACCH(v1);\
} while(0)
#else
	#define L1D_TRC_RACH2FACCH(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TRC_SABM_FACCH_Counter(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_TRC_SABM_FACCH_Counter(v1);\
} while(0)
#else
	#define L1D_TRC_SABM_FACCH_Counter(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_Tx_ARFCN_TA(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_Tx_ARFCN_TA(v1, v2);\
} while(0)
#else
	#define L1D_Trc_Tx_ARFCN_TA(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1D_SEC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AFC_Assert_Reason(unsigned char v1);
void L1TRC_Send_L1I_Msg_AFC_TQ_TIME(short v1, short v2);
void L1TRC_Send_L1I_Msg_AFC_Assert34(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_XO_TRACE_VTuneCrt7AREA(char v1, long v2, short v3, long v4);
void L1TRC_Send_XO_TRACE_FreqCrtUpdate(char v1, short v2);
void L1TRC_Send_XO_TRACE_ReadTempADC(short v1, long v2);
void L1TRC_Send_XO_TRACE_CmpTempPhi(long v1);
void L1TRC_Send_XO_TRACE_Phi2Dac(long v1, short v2);
void L1TRC_Send_L1D_SB_Status_Extend(short v1, unsigned char v2, short v3, short v4, char v5, short v6, short v7);
void L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK(void);
void L1TRC_Send_L1D_SP_flag(short v1);
void L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx(short v1);
void L1TRC_Send_L1I_DCM_status(unsigned char v1);
void L1TRC_Send_L1D_PCH_OK_AT_STATE(short v1);
void L1TRC_Send_L1D_CCCH_OK_AT_STATE(short v1);
void L1TRC_Send_L1D_PCH_One_Burst_Enable(short v1);
void L1TRC_Send_L1D_PCH_Null_Detect(void);
void L1TRC_Send_L1D_PCH_Empty_Detect(void);
void L1TRC_Send_L1D_PCH_Pattern(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1D_TRC_PM_LEN(short v1);
void L1TRC_Send_L1D_TRC_8PM_ENABLE(char v1);
void L1TRC_Send_L1D_Trc_DP6TapEQStatus(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_DSP_WATCH_DOG(char v1);
void L1TRC_Send_L1D_DSP_RX_FILTER(short v1);
void L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass(char v1, unsigned short v2);
void L1TRC_Send_L1D_TRC_TCH_HandoverState(char v1);
void L1TRC_Send_L1D_TRC_GetReportInAdvance(void);
void L1TRC_Send_L1D_TRC_RACH2FACCH(unsigned char v1);
void L1TRC_Send_L1D_TRC_SABM_FACCH_Counter(char v1);
void L1TRC_Send_L1D_Trc_Tx_ARFCN_TA(short v1, short v2);
void L1TRC_Send_L1D_Trc_AFC_DAC_Data(char v1, short v2, short v3, short v4);

void Set_L1D_SEC_Filter(unsigned char *setting);

#endif


#endif
