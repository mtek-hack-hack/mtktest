#ifndef L1TRC_L1I_GPRS_DEF_H
#define L1TRC_L1I_GPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_GPRS_Str_Bool(v1)	(v1+0)
#define L1I_PRACH_Str_States(v1)	(v1+2)
#define L1I_TBF_Str_States(v1)	(v1+8)
#define L1I_Str_GPRS_UL_CtrlMsg(v1)	(v1+14)
#define L1I_Str_Check_RRBP(v1)	(v1+23)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1I_Trace_PowerControlSetC(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_PowerControlSetC(v1);\
} while(0)
#else
	#define L1I_Trace_PowerControlSetC(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportTBFStarted(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ReportTBFStarted(v1, v2);\
} while(0)
#else
	#define L1I_Trace_ReportTBFStarted(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_TBF_Transition(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_TBF_Transition(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_TBF_Transition(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportTBFStopped(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ReportTBFStopped(v1);\
} while(0)
#else
	#define L1I_Trace_ReportTBFStopped(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportPDTChConflict(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_ReportPDTChConflict(v1);\
} while(0)
#else
	#define L1I_Trace_ReportPDTChConflict(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportPRACh(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_ReportPRACh(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_ReportPRACh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportSingleDL(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Trace_ReportSingleDL(v1);\
} while(0)
#else
	#define L1I_Trace_ReportSingleDL(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MACAssigned(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1I_Trace_MACAssigned(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_MACAssigned(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MACOurUSFMask(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_MACOurUSFMask(v1);\
} while(0)
#else
	#define L1I_Trace_MACOurUSFMask(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MACTxSpec(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_MACTxSpec(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MACTxSpec(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MACSetReceivedUSF(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_MACSetReceivedUSF(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MACSetReceivedUSF(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MACPreGetUplinkPDTCh(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MACPreGetUplinkPDTCh(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MACPreGetUplinkPDTCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_MACULStatusReport(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_MACULStatusReport(v1, v2);\
} while(0)
#else
	#define L1I_Trace_MACULStatusReport(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ExtractPR1() do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_ExtractPR1();\
} while(0)
#else
	#define L1I_Trace_ExtractPR1() 
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ExtractPR2() do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_ExtractPR2();\
} while(0)
#else
	#define L1I_Trace_ExtractPR2() 
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ExtractPR3(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ExtractPR3(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_ExtractPR3(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_GPRS_AGC0(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC0(v1);\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC0(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_GPRS_AGC1(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC1(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC1(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_GPRS_AGC2(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC2(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_GPRS_AGC3(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC3(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC3(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_GPRS_AGC4(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC4(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC4(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_GPRS_AGC5(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC5(v1, v2);\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC5(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_UL_DATA(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_UL_DATA(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_UL_DATA(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_UL_Ctrl(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_UL_Ctrl(v1, v2);\
} while(0)
#else
	#define L1I_Trace_UL_Ctrl(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);\
} while(0)
#else
	#define L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_PCA_AB(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_PCA_AB(v1);\
} while(0)
#else
	#define L1I_Trace_PCA_AB(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_PDTChCheckNoRRBP(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_PDTChCheckNoRRBP(v1);\
} while(0)
#else
	#define L1I_Trace_PDTChCheckNoRRBP(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_UpdateTimingAdvance(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1I_Trace_UpdateTimingAdvance(v1, v2);\
} while(0)
#else
	#define L1I_Trace_UpdateTimingAdvance(v1, v2)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1I_GPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Trace_PowerControlSetC(char v1);
void L1TRC_Send_L1I_Trace_ReportTBFStarted(char v1, char v2);
void L1TRC_Send_L1I_Trace_TBF_Transition(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_ReportTBFStopped(unsigned long v1);
void L1TRC_Send_L1I_Trace_ReportPDTChConflict(unsigned long v1);
void L1TRC_Send_L1I_Trace_ReportPRACh(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_L1I_Trace_ReportPollResp(unsigned char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Trace_ReportSingleDL(unsigned char v1);
void L1TRC_Send_L1I_Trace_ReportULTwoPhase(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Trace_ReportULWithoutTBF(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Trace_MACAssigned(char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_MACOurUSFMask(unsigned char v1);
void L1TRC_Send_L1I_Trace_MACTxSpec(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_MACSetReceivedUSF(char v1, char v2);
void L1TRC_Send_L1I_Trace_MACPreGetUplinkPDTCh(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_MACULStatusReport(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_ExtractPR1(void);
void L1TRC_Send_L1I_Trace_ExtractPR2(void);
void L1TRC_Send_L1I_Trace_ExtractPR3(unsigned char v1, char v2, unsigned char v3, char v4);
void L1TRC_Send_L1I_Trace_GPRS_AGC0(char v1);
void L1TRC_Send_L1I_Trace_GPRS_AGC1(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC2(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC3(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC4(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC5(char v1, char v2);
void L1TRC_Send_L1I_Trace_UL_DATA(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_UL_Ctrl(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_PDAN(char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, char v12);
void L1TRC_Send_L1I_Trace_PCA_AB(char v1);
void L1TRC_Send_L1I_Trace_PDTChCheckNoRRBP(unsigned char v1);
void L1TRC_Send_L1I_Trace_UpdateTimingAdvance(char v1, char v2);

void Set_L1I_GPRS_Filter(unsigned char *setting);

#endif


#endif
