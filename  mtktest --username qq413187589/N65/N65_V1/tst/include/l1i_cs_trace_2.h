#ifndef L1TRC_L1I_GSM_2_DEF_H
#define L1TRC_L1I_GSM_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_Str_Timer(v1)	(v1+0)
#define L1I_Str_Burst(v1)	(v1+52)
#define L1I_Str_Bool(v1)	(v1+54)
#define L1I_Str_RATSCCH_STATE(v1)	(v1+56)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1I_Msg_AGC_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AGC_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_AGC_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_S_AGCNB_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_S_AGCNB_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_S_AGCNB_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_N_AGCNB_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_N_AGCNB_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_N_AGCNB_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_PDTCH_TS0_AGC_2(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1I_Msg_PDTCH_TS0_AGC_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_PDTCH_TS123_AGC_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_PDTCH_TS123_AGC_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_IM_TS0_AGC_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_IM_TS0_AGC_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_IM_TS0_AGC_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_IM_TS123_AGC_2(v1, v2, v3) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_IM_TS123_AGC_2(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_IM_TS123_AGC_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AGC_PM_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AGC_PM_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_AGC_PM_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFC_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_AFC_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_AFC_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_S_AFCNB_2(v1, v2, v3) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_S_AFCNB_2(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_S_AFCNB_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_N_AFCNB_2(v1, v2, v3) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_N_AFCNB_2(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_N_AFCNB_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TAC_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TAC_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TAC_Accumulate_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_Accumulate_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TAC_Accumulate_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TAC_Adjust_2(v1) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_Adjust_2(v1);\
} while(0)
#else
	#define L1I_Msg_TAC_Adjust_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_Timer_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_Timer_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_Timer_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ReportRACh_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Msg_ReportRACh_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_ReportRACh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_UL_FACCH_2() do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_UL_FACCH_2();\
} while(0)
#else
	#define L1I_Msg_UL_FACCH_2() 
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ReportTCh_2(v1, v2, v3) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ReportTCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_ReportTCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_SetSync_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_SetSync_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_SetSync_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TaskSetSync_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_TaskSetSync_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TaskSetSync_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TxPower_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Msg_TxPower_2(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TxPower_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ULDTX_2(v1) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ULDTX_2(v1);\
} while(0)
#else
	#define L1I_Msg_ULDTX_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_RATSCChState_2(v1) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_RATSCChState_2(v1);\
} while(0)
#else
	#define L1I_Msg_RATSCChState_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_SetupTA_2(v1) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_SetupTA_2(v1);\
} while(0)
#else
	#define L1I_Msg_SetupTA_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_FCBT_CNT_2(v1) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1I_Msg_FCBT_CNT_2(v1);\
} while(0)
#else
	#define L1I_Msg_FCBT_CNT_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh1_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh1_2(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh1_2(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh2_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh2_2(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh2_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh3_2(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh3_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh3_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh4_2(v1, v2) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh4_2(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh4_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_SIM_STATUS_2(v1) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_SIM_STATUS_2(v1);\
} while(0)
#else
	#define L1I_Msg_SIM_STATUS_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SIM2Timing(v1, v2, v3, v4) do {\
		if(L1I_GSM_2_Trace_Filter[0]==1 && (L1I_GSM_2_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_SIM2Timing(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Msg_SIM2Timing(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1I_GSM_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AGC_2(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_S_AGCNB_2(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_N_AGCNB_2(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC_2(short v1, char v2, char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC_2(char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1I_Msg_IM_TS0_AGC_2(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_IM_TS123_AGC_2(char v1, char v2, char v3);
void L1TRC_Send_L1I_Msg_AGC_PM_2(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_AFC_2(short v1, short v2);
void L1TRC_Send_L1I_Msg_S_AFCNB_2(short v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_N_AFCNB_2(short v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_TAC_2(short v1, char v2);
void L1TRC_Send_L1I_Msg_TAC_Accumulate_2(short v1, short v2);
void L1TRC_Send_L1I_Msg_TAC_Adjust_2(short v1);
void L1TRC_Send_L1I_Msg_Timer_2(char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_ReportRACh_2(unsigned long v1, char v2);
void L1TRC_Send_L1I_Msg_UL_FACCH_2(void);
void L1TRC_Send_L1I_Msg_ReportTCh_2(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_SetSync_2(unsigned long v1, short v2);
void L1TRC_Send_L1I_Msg_TaskSetSync_2(unsigned long v1, short v2);
void L1TRC_Send_L1I_Msg_TxPower_2(char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_ULDTX_2(unsigned char v1);
void L1TRC_Send_L1I_Msg_RATSCChState_2(unsigned char v1);
void L1TRC_Send_L1I_Msg_SetupTA_2(unsigned char v1);
void L1TRC_Send_L1I_Msg_FCBT_CNT_2(unsigned char v1);
void L1TRC_Send_L1I_Trace_MonitorReportEnh1_2(unsigned long v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_L1I_Trace_MonitorReportEnh2_2(long v1, long v2);
void L1TRC_Send_L1I_Trace_MonitorReportEnh3_2(long v1, short v2, long v3, short v4);
void L1TRC_Send_L1I_Trace_MonitorReportEnh4_2(long v1, char v2);
void L1TRC_Send_L1I_Msg_SIM_STATUS_2(unsigned char v1);
void L1TRC_Send_L1C_Msg_SIM2Timing(unsigned char v1, unsigned long v2, short v3, short v4);

void Set_L1I_GSM_2_Filter(unsigned char *setting);

#endif


#endif
