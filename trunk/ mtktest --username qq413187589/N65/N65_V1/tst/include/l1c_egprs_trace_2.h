#ifndef L1TRC_L1C_EGPRS_2_DEF_H
#define L1TRC_L1C_EGPRS_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)	(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_TBFStart_2(v1, v2) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_TBFStart_2(v1, v2);\
} while(0)
#else
	#define L1T_Trace_EGPRS_TBFStart_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_DL_header_2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trace_DL_header_2(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1T_Trace_DL_header_2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_PDTCh_2(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_PDTCh_Header_2(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh_Header_2(v1, v2, v3, v4, v5, v6, v7, v8, v9);\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh_Header_2(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_PDTCh2_2(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh2_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_PDTCh2_Header_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_Header_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh2_Header_2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_DSP_DPS_IR_2(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_DSP_DPS_IR_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_DPS_IR_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_DSP_IR_2(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_DSP_IR_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_IR_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EGPRS_PDTCH_Conflict_2(v1, v2, v3) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCH_Conflict_2(v1, v2, v3);\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCH_Conflict_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_Set_SRB_Mode_2(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1T_Trace_Set_SRB_Mode_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1T_Trace_Set_SRB_Mode_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_SRB_Assigned_Ts_2(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1T_Trace_SRB_Assigned_Ts_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1T_Trace_SRB_Assigned_Ts_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_SBT_2(v1, v2) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1T_Trace_SBT_2(v1, v2);\
} while(0)
#else
	#define L1T_Trace_SBT_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_ReportPDTChBad_wBEP_2(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPDTChBad_wBEP_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1C_Trace_ReportPDTChBad_wBEP_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_GPRS_PDTCh_wBEP_2(v1, v2) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_GPRS_PDTCh_wBEP_2(v1, v2);\
} while(0)
#else
	#define L1T_Trace_GPRS_PDTCh_wBEP_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trace_EgprsResetIR_2(v1, v2, v3) do {\
		if(L1C_EGPRS_2_Trace_Filter[0]==1 && (L1C_EGPRS_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trace_EgprsResetIR_2(v1, v2, v3);\
} while(0)
#else
	#define L1T_Trace_EgprsResetIR_2(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1C_EGPRS_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1T_Trace_EGPRS_TBFStart_2(char v1, char v2);
void L1TRC_Send_L1T_Trace_DL_header_2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh_2(char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh_Header_2(char v1, char v2, char v3, short v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_2(char v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_Header_2(char v1, char v2, char v3, short v4, short v5, char v6, char v7, char v8, char v9, char v10, char v11);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_DPS_IR_2(short v1, short v2, short v3, char v4);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_IR_2(short v1, short v2, char v3, char v4, short v5);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCH_Conflict_2(short v1, short v2, short v3);
void L1TRC_Send_L1T_Trace_Set_SRB_Mode_2(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_L1T_Trace_SRB_Assigned_Ts_2(char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1T_Trace_SBT_2(short v1, short v2);
void L1TRC_Send_L1C_Trace_ReportPDTChBad_wBEP_2(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1T_Trace_GPRS_PDTCh_wBEP_2(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1T_Trace_EgprsResetIR_2(char v1, char v2, char v3);

void Set_L1C_EGPRS_2_Filter(unsigned char *setting);

#endif


#endif
