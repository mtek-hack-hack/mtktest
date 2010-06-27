#ifndef L1TRC_L1C_GPRS_2_DEF_H
#define L1TRC_L1C_GPRS_2_DEF_H

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
	#define L1C_Trace_ReportPBCCh_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPBCCh_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPBCCh_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportNPBCCh_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_ReportNPBCCh_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportNPBCCh_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPPCh_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPPCh_2(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportPPCh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPTCChDown_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPTCChDown_2(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportPTCChDown_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_woRRBP_woFBI_2(v1, v2, v3, v4) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_woFBI_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_woRRBP_wFBI_2(v1, v2, v3, v4) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_wFBI_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_wRRBP_woFBI_2(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_woFBI_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_wRRBP_wFBI_2(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_wFBI_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_Ctrl_2(v1, v2, v3) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_Ctrl_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_Ctrl_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDTChGood_Dummy_Ctrl_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl_2(v1, v2);\
} while(0)
#else
	#define L1C_Trace_PDTChGood_Dummy_Ctrl_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPDTChBad_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPDTChBad_2(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportPDTChBad_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_TBFStart_2(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart_2(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1C_Trace_TBFStart_2(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportIM_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportIM_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportIM_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportIMPower_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_ReportIMPower_2(v1, v2);\
} while(0)
#else
	#define L1C_Trace_ReportIMPower_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPAGCh_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPAGCh_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPAGCh_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportSingleDL_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_ReportSingleDL_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportSingleDL_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPACCh_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPACCh_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPACCh_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPACCh_Ctrl_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl_2(v1);\
} while(0)
#else
	#define L1C_Trace_ReportPACCh_Ctrl_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPBCCh_2(v1, v2, v3) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPBCCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPBCCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPPCh_2(v1, v2, v3) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPPCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPPCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartPAGCh_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_StartPAGCh_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartPAGCh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPRACh_2(v1, v2, v3) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPRACh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPRACh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartPollRespAB_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_StartPollRespAB_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartPollRespAB_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartPollRespNB_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_StartPollRespNB_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartPollRespNB_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartSingleULwoTBF_2(v1, v2) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_StartSingleULwoTBF_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartSingleULwoTBF_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartSingleDL_2(v1, v2, v3) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_StartSingleDL_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_StartSingleDL_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartULTwoPhase_2(v1, v2, v3) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_StartULTwoPhase_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_StartULTwoPhase_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartIM_2(v1) do {\
		if(L1C_GPRS_2_Trace_Filter[0]==1 && (L1C_GPRS_2_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_StartIM_2(v1);\
} while(0)
#else
	#define L1C_Msg_StartIM_2(v1)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1C_GPRS_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_ReportPBCCh_2(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportNPBCCh_2(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportPPCh_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPTCChDown_2(unsigned char v1, char v2);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI_2(char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI_2(char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI_2(char v1, char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI_2(char v1, char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_Ctrl_2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportPDTChBad_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_TBFStart_2(unsigned long v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1C_Trace_ReportIM_2(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportIMPower_2(char v1, short v2);
void L1TRC_Send_L1C_Trace_ReportPAGCh_2(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportSingleDL_2(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportPACCh_2(unsigned char v1);
void L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl_2(unsigned char v1);
void L1TRC_Send_L1C_Msg_SetupPBCCh_2(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_SetupPPCh_2(char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartPAGCh_2(char v1, char v2);
void L1TRC_Send_L1C_Msg_SetupPRACh_2(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartPollRespAB_2(long v1, char v2);
void L1TRC_Send_L1C_Msg_StartPollRespNB_2(long v1, char v2);
void L1TRC_Send_L1C_Msg_StartSingleULwoTBF_2(long v1, char v2);
void L1TRC_Send_L1C_Msg_StartSingleDL_2(long v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartULTwoPhase_2(long v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartIM_2(char v1);

void Set_L1C_GPRS_2_Filter(unsigned char *setting);

#endif


#endif
