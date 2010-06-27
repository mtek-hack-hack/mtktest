#ifndef L1TRC_L1I_GSM_DEF_H
#define L1TRC_L1I_GSM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_Str_Timer(v1)	(v1+0)
#define L1I_Str_Burst(v1)	(v1+52)
#define L1I_Str_Bool(v1)	(v1+54)
#define L1I_Str_RATSCCH_STATE(v1)	(v1+56)
#define L1I_Str_NoExecute(v1)	(v1+73)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1I_Msg_AGC(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AGC(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_AGC(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_S_AGCNB(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_S_AGCNB(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_S_AGCNB(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_N_AGCNB(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_N_AGCNB(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_N_AGCNB(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_IM_TS123_AGC(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_IM_TS123_AGC(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_IM_TS123_AGC(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AGC_PM(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AGC_PM(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Msg_AGC_PM(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFC(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_AFC(v1, v2);\
} while(0)
#else
	#define L1I_Msg_AFC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_AFCInit(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_AFCInit(v1);\
} while(0)
#else
	#define L1I_Msg_AFCInit(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_S_AFCNB(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_S_AFCNB(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_S_AFCNB(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_N_AFCNB(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_N_AFCNB(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_N_AFCNB(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TAC(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_TAC(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TAC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TAC_Accumulate(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_Accumulate(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TAC_Accumulate(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TAC_Adjust(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_Adjust(v1);\
} while(0)
#else
	#define L1I_Msg_TAC_Adjust(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_Timer(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_Timer(v1, v2);\
} while(0)
#else
	#define L1I_Msg_Timer(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ReportRACh(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Msg_ReportRACh(v1, v2);\
} while(0)
#else
	#define L1I_Msg_ReportRACh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_UL_FACCH() do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_UL_FACCH();\
} while(0)
#else
	#define L1I_Msg_UL_FACCH() 
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ReportTCh(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ReportTCh(v1, v2, v3);\
} while(0)
#else
	#define L1I_Msg_ReportTCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_SetSync(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_SetSync(v1, v2);\
} while(0)
#else
	#define L1I_Msg_SetSync(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TaskSetSync(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_TaskSetSync(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TaskSetSync(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TxPower(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Msg_TxPower(v1, v2);\
} while(0)
#else
	#define L1I_Msg_TxPower(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ULDTX(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ULDTX(v1);\
} while(0)
#else
	#define L1I_Msg_ULDTX(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_RATSCChState(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_RATSCChState(v1);\
} while(0)
#else
	#define L1I_Msg_RATSCChState(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_SetupTA(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_SetupTA(v1);\
} while(0)
#else
	#define L1I_Msg_SetupTA(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_FCBT_CNT(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1I_Msg_FCBT_CNT(v1);\
} while(0)
#else
	#define L1I_Msg_FCBT_CNT(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh2(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh2(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MonitorReportEnh4(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh4(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh4(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_SIM_STATUS(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_SIM_STATUS(v1);\
} while(0)
#else
	#define L1I_Msg_SIM_STATUS(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_TimerAbortNoExecute() do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_TimerAbortNoExecute();\
} while(0)
#else
	#define L1I_Msg_TimerAbortNoExecute() 
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1I_GSM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AGC(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_S_AGCNB(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_N_AGCNB(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC(short v1, char v2, char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC(char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1I_Msg_IM_TS0_AGC(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_IM_TS123_AGC(char v1, char v2, char v3);
void L1TRC_Send_L1I_Msg_AGC_PM(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_AFC(short v1, short v2);
void L1TRC_Send_L1I_Msg_AFCInit(char v1);
void L1TRC_Send_L1I_Msg_S_AFCNB(short v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_N_AFCNB(short v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_TAC(short v1, char v2);
void L1TRC_Send_L1I_Msg_TAC_Accumulate(short v1, short v2);
void L1TRC_Send_L1I_Msg_TAC_Adjust(short v1);
void L1TRC_Send_L1I_Msg_Timer(char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_ReportRACh(unsigned long v1, char v2);
void L1TRC_Send_L1I_Msg_UL_FACCH(void);
void L1TRC_Send_L1I_Msg_ReportTCh(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_SetSync(unsigned long v1, short v2);
void L1TRC_Send_L1I_Msg_TaskSetSync(unsigned long v1, short v2);
void L1TRC_Send_L1I_Msg_TxPower(char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_ULDTX(unsigned char v1);
void L1TRC_Send_L1I_Msg_RATSCChState(unsigned char v1);
void L1TRC_Send_L1I_Msg_SetupTA(unsigned char v1);
void L1TRC_Send_L1I_Msg_FCBT_CNT(unsigned char v1);
void L1TRC_Send_L1I_Trace_MonitorReportEnh1(unsigned long v1, char v2, char v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_L1I_Trace_MonitorReportEnh2(long v1, long v2);
void L1TRC_Send_L1I_Trace_MonitorReportEnh3(long v1, short v2, long v3, short v4);
void L1TRC_Send_L1I_Trace_MonitorReportEnh4(long v1, char v2);
void L1TRC_Send_L1I_Msg_SIM_STATUS(unsigned char v1);
void L1TRC_Send_L1I_Msg_TimerNoExecute(unsigned char v1, char v2, unsigned char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Msg_TimerAbortNoExecute(void);

void Set_L1I_GSM_Filter(unsigned char *setting);

#endif


#endif
