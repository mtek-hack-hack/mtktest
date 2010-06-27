#ifndef L1TRC_L1C_GPRS_DEF_H
#define L1TRC_L1C_GPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)	(v1+0)
#define L1C_Str_GPRS_DL_CtrlMsg(v1)	(v1+2)
#define L1C_Str_UplinkAccessMode(v1)	(v1+58)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1C_Trace_ReportPBCCh(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPBCCh(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPBCCh(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportNPBCCh(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_ReportNPBCCh(v1);\
} while(0)
#else
	#define L1C_Trace_ReportNPBCCh(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPPCh(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPPCh(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportPPCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPTCChDown(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPTCChDown(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportPTCChDown(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_Ctrl(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_Ctrl(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_Ctrl(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPDTChBad(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPDTChBad(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportPDTChBad(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportIM(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportIM(v1);\
} while(0)
#else
	#define L1C_Trace_ReportIM(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportIMPower(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportIMPower(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportIMPower(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPAGCh(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPAGCh(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPAGCh(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportSingleDL(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_ReportSingleDL(v1);\
} while(0)
#else
	#define L1C_Trace_ReportSingleDL(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPACCh(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPACCh(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPACCh(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPACCh_Ctrl(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPACCh_Ctrl(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPBCCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPBCCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPBCCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPPCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPPCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPPCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartPAGCh(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_StartPAGCh(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartPAGCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPRACh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPRACh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPRACh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartPollRespAB(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_StartPollRespAB(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartPollRespAB(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartPollRespNB(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_StartPollRespNB(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartPollRespNB(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartSingleULwoTBF(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_StartSingleULwoTBF(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartSingleULwoTBF(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartSingleDL(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_StartSingleDL(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_StartSingleDL(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartULTwoPhase(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_StartULTwoPhase(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_StartULTwoPhase(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartIM(v1) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_StartIM(v1);\
} while(0)
#else
	#define L1C_Msg_StartIM(v1)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1C_GPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_ReportPBCCh(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportNPBCCh(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportPPCh(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPTCChDown(unsigned char v1, char v2);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI(char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI(char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI(char v1, char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI(char v1, char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_Ctrl(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPDTChBad(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_TBFStart(unsigned long v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1C_Trace_ReportIM(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportIMPower(char v1, short v2);
void L1TRC_Send_L1C_Trace_ReportPAGCh(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportSingleDL(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportPACCh(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl(unsigned char v1);
void L1TRC_Send_L1C_Msg_SetupPBCCh(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_SetupPPCh(char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartPAGCh(char v1, char v2);
void L1TRC_Send_L1C_Msg_SetupPRACh(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartPollRespAB(long v1, char v2);
void L1TRC_Send_L1C_Msg_StartPollRespNB(long v1, char v2);
void L1TRC_Send_L1C_Msg_StartSingleULwoTBF(long v1, char v2);
void L1TRC_Send_L1C_Msg_StartSingleDL(long v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartULTwoPhase(long v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartIM(char v1);

void Set_L1C_GPRS_Filter(unsigned char *setting);

#endif


#endif
