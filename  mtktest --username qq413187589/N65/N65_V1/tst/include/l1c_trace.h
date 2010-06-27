#ifndef L1TRC_L1C_GSM_DEF_H
#define L1TRC_L1C_GSM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)	(v1+0)
#define L1C_Str_Function(v1)	(v1+2)
#define L1C_Str_ConflictReport(v1)	(v1+5)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportBCCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_ReportBCCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_ReportBCCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportNBCCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_ReportNBCCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_ReportNBCCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportPCh(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPCh(v1, v2);\
} while(0)
#else
	#define L1C_Msg_ReportPCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportPeek(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPeek(v1);\
} while(0)
#else
	#define L1C_Msg_ReportPeek(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportCBCh(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_ReportCBCh(v1);\
} while(0)
#else
	#define L1C_Msg_ReportCBCh(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportAGCh(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportAGCh(v1);\
} while(0)
#else
	#define L1C_Msg_ReportAGCh(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportSDCCh(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSDCCh(v1, v2);\
} while(0)
#else
	#define L1C_Msg_ReportSDCCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportSACCh(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSACCh(v1, v2);\
} while(0)
#else
	#define L1C_Msg_ReportSACCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_DL_FACCH() do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_DL_FACCH();\
} while(0)
#else
	#define L1C_Msg_DL_FACCH() 
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_HoppingSeq(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_HoppingSeq(v1);\
} while(0)
#else
	#define L1C_Msg_HoppingSeq(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_SDCCH_DL_DATA(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_SDCCH_DL_DATA(v1);\
} while(0)
#else
	#define L1T_Trc_SDCCH_DL_DATA(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_SACCH_DL_DATA(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1T_Trc_SACCH_DL_DATA(v1);\
} while(0)
#else
	#define L1T_Trc_SACCH_DL_DATA(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_FACCH_DL_DATA(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1T_Trc_FACCH_DL_DATA(v1);\
} while(0)
#else
	#define L1T_Trc_FACCH_DL_DATA(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartBCCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_StartBCCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_StartBCCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartAGCh(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_StartAGCh(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartAGCh(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupCBCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_SetupCBCh(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupCBCh(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupCiphering(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_SetupCiphering(v1, v2);\
} while(0)
#else
	#define L1C_Msg_SetupCiphering(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartFCChT(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_StartFCChT(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartFCChT(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartSChT(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_StartSChT(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Msg_StartSChT(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_FunctionCalled(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_FunctionCalled(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_FunctionCalled(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_R99_Bep(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Bep(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_R99_Bep(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_R99_Power_bNormalize(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Power_bNormalize(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_R99_Power_bNormalize(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Msg_ConflictReportType(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_ConflictReportType(v1);\
} while(0)
#else
	#define L1I_Msg_ConflictReportType(v1)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1C_GSM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Msg_ReportFCCh(unsigned char v1, unsigned char v2, char v3, unsigned long v4, short v5, unsigned long v6, unsigned long v7, short v8);
void L1TRC_Send_L1C_Msg_ReportSCh(unsigned char v1, char v2, unsigned long v3, short v4, unsigned long v5, short v6);
void L1TRC_Send_L1C_Msg_ReportBCCh(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_ReportNBCCh(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_ReportPCh(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_ReportPeek(unsigned char v1);
void L1TRC_Send_L1C_Msg_ReportCBCh(unsigned char v1);
void L1TRC_Send_L1C_Msg_ReportAGCh(unsigned char v1);
void L1TRC_Send_L1C_Msg_ReportSDCCh(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_ReportSACCh(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_DL_FACCH(void);
void L1TRC_Send_L1C_Msg_HoppingSeq(char v1);
void L1TRC_Send_L1T_Trc_SDCCH_DL_DATA(unsigned long v1);
void L1TRC_Send_L1T_Trc_SACCH_DL_DATA(unsigned long v1);
void L1TRC_Send_L1T_Trc_FACCH_DL_DATA(unsigned long v1);
void L1TRC_Send_L1C_Msg_StartBCCh(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_L1C_Msg_SetupPCh(unsigned char v1, char v2, long v3);
void L1TRC_Send_L1C_Msg_StartAGCh(unsigned char v1, char v2);
void L1TRC_Send_L1C_Msg_SetupCBCh(char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_SetupCiphering(unsigned char v1, char v2);
void L1TRC_Send_L1C_Msg_StartFCChT(char v1, char v2);
void L1TRC_Send_L1C_Msg_StartSChT(unsigned long v1, short v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_FunctionCalled(unsigned char v1, long v2, long v3);
void L1TRC_Send_L1C_Trace_R99_Bep(char v1, char v2, long v3, short v4);
void L1TRC_Send_L1C_Trace_R99_Bep_bNormalize(long v1, short v2, long v3, short v4);
void L1TRC_Send_L1C_Trace_R99_Power_bNormalize(long v1, long v2, char v3);
void L1TRC_Send_L1I_Msg_ConflictReportType(unsigned char v1);

void Set_L1C_GSM_Filter(unsigned char *setting);

#endif


#endif
