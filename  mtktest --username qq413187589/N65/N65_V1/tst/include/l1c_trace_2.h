#ifndef L1TRC_L1C_GSM_2_DEF_H
#define L1TRC_L1C_GSM_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)	(v1+0)
#define L1C_Str_Function(v1)	(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1C_Msg_ReportFCCh_2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_ReportFCCh_2(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1C_Msg_ReportFCCh_2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportSCh_2(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSCh_2(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1C_Msg_ReportSCh_2(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportBCCh_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_ReportBCCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_ReportBCCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportNBCCh_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_ReportNBCCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_ReportNBCCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportPCh_2(v1, v2) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPCh_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_ReportPCh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportPeek_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPeek_2(v1);\
} while(0)
#else
	#define L1C_Msg_ReportPeek_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportCBCh_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_ReportCBCh_2(v1);\
} while(0)
#else
	#define L1C_Msg_ReportCBCh_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportAGCh_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportAGCh_2(v1);\
} while(0)
#else
	#define L1C_Msg_ReportAGCh_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportSDCCh_2(v1, v2) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSDCCh_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_ReportSDCCh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_ReportSACCh_2(v1, v2) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSACCh_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_ReportSACCh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_DL_FACCH_2() do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_DL_FACCH_2();\
} while(0)
#else
	#define L1C_Msg_DL_FACCH_2() 
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_HoppingSeq_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_HoppingSeq_2(v1);\
} while(0)
#else
	#define L1C_Msg_HoppingSeq_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_SDCCH_DL_DATA_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_SDCCH_DL_DATA_2(v1);\
} while(0)
#else
	#define L1T_Trc_SDCCH_DL_DATA_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_SACCH_DL_DATA_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1T_Trc_SACCH_DL_DATA_2(v1);\
} while(0)
#else
	#define L1T_Trc_SACCH_DL_DATA_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_FACCH_DL_DATA_2(v1) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1T_Trc_FACCH_DL_DATA_2(v1);\
} while(0)
#else
	#define L1T_Trc_FACCH_DL_DATA_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartBCCh_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_StartBCCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_StartBCCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupPCh_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupPCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartAGCh_2(v1, v2) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_StartAGCh_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartAGCh_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupCBCh_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_SetupCBCh_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_SetupCBCh_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_SetupCiphering_2(v1, v2) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_SetupCiphering_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_SetupCiphering_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartFCChT_2(v1, v2) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_StartFCChT_2(v1, v2);\
} while(0)
#else
	#define L1C_Msg_StartFCChT_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_StartSChT_2(v1, v2, v3, v4) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_StartSChT_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Msg_StartSChT_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Msg_FunctionCalled_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_FunctionCalled_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Msg_FunctionCalled_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_R99_Bep_2(v1, v2, v3, v4) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Bep_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_R99_Bep_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_R99_Bep_bNormalize_2(v1, v2, v3, v4) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Bep_bNormalize_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1C_Trace_R99_Bep_bNormalize_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_R99_Power_bNormalize_2(v1, v2, v3) do {\
		if(L1C_GSM_2_Trace_Filter[0]==1 && (L1C_GSM_2_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Power_bNormalize_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_R99_Power_bNormalize_2(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1C_GSM_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Msg_ReportFCCh_2(unsigned char v1, unsigned char v2, char v3, unsigned long v4, short v5, unsigned long v6, unsigned long v7, short v8);
void L1TRC_Send_L1C_Msg_ReportSCh_2(unsigned char v1, char v2, unsigned long v3, short v4, unsigned long v5, short v6);
void L1TRC_Send_L1C_Msg_ReportBCCh_2(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_ReportNBCCh_2(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_ReportPCh_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_ReportPeek_2(unsigned char v1);
void L1TRC_Send_L1C_Msg_ReportCBCh_2(unsigned char v1);
void L1TRC_Send_L1C_Msg_ReportAGCh_2(unsigned char v1);
void L1TRC_Send_L1C_Msg_ReportSDCCh_2(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_ReportSACCh_2(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_DL_FACCH_2(void);
void L1TRC_Send_L1C_Msg_HoppingSeq_2(char v1);
void L1TRC_Send_L1T_Trc_SDCCH_DL_DATA_2(unsigned long v1);
void L1TRC_Send_L1T_Trc_SACCH_DL_DATA_2(unsigned long v1);
void L1TRC_Send_L1T_Trc_FACCH_DL_DATA_2(unsigned long v1);
void L1TRC_Send_L1C_Msg_StartBCCh_2(unsigned char v1, char v2, unsigned long v3);
void L1TRC_Send_L1C_Msg_SetupPCh_2(unsigned char v1, char v2, long v3);
void L1TRC_Send_L1C_Msg_StartAGCh_2(unsigned char v1, char v2);
void L1TRC_Send_L1C_Msg_SetupCBCh_2(char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_SetupCiphering_2(unsigned char v1, char v2);
void L1TRC_Send_L1C_Msg_StartFCChT_2(char v1, char v2);
void L1TRC_Send_L1C_Msg_StartSChT_2(unsigned long v1, short v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_FunctionCalled_2(unsigned char v1, long v2, long v3);
void L1TRC_Send_L1C_Trace_R99_Bep_2(char v1, char v2, long v3, short v4);
void L1TRC_Send_L1C_Trace_R99_Bep_bNormalize_2(long v1, short v2, long v3, short v4);
void L1TRC_Send_L1C_Trace_R99_Power_bNormalize_2(long v1, long v2, char v3);

void Set_L1C_GSM_2_Filter(unsigned char *setting);

#endif


#endif
