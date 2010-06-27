#ifndef L1TRC_L1I_EGPRS_DEF_H
#define L1TRC_L1I_EGPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_EGPRS_Str_Bool(v1)	(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1I_Trace_U2_header(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_U2_header(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1I_Trace_U2_header(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_UL_Header1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_UL_Header1(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1I_Trace_UL_Header1(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_UL_Header2(v1, v2, v3, v4, v5) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_UL_Header2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1I_Trace_UL_Header2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_UL_Header3(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_UL_Header3(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1I_Trace_UL_Header3(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_IRParams(v1, v2, v3, v4) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_IRParams(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_IRParams(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_EGPRS_PDAN(v1, v2, v3, v4) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_EGPRS_PDAN(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trace_EGPRS_PDAN(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_Set_SRB_Mode(v1, v2, v3) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Trace_Set_SRB_Mode(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_Set_SRB_Mode(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_Egprs_ExtractPR(v1, v2, v3) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Trace_Egprs_ExtractPR(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_Egprs_ExtractPR(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_New_TBF_Tid(v1) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_New_TBF_Tid(v1);\
} while(0)
#else
	#define L1I_Trace_New_TBF_Tid(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_U2_data(v1) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_U2_data(v1);\
} while(0)
#else
	#define L1I_Trace_U2_data(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_TAC_no_accumulate(v1) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_TAC_no_accumulate(v1);\
} while(0)
#else
	#define L1I_Trace_TAC_no_accumulate(v1)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1I_EGPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Trace_U2_header(short v1, short v2, short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_L1I_Trace_UL_Header1(char v1, short v2, short v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_L1I_Trace_UL_Header2(char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Trace_UL_Header3(char v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Trace_IRParams(char v1, char v2, short v3, char v4);
void L1TRC_Send_L1I_Trace_EGPRS_PDAN(char v1, char v2, short v3, short v4);
void L1TRC_Send_L1I_Trace_Set_SRB_Mode(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_Egprs_ExtractPR(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_New_TBF_Tid(short v1);
void L1TRC_Send_L1I_Trace_U2_data(unsigned short v1);
void L1TRC_Send_L1I_Trace_TAC_no_accumulate(long v1);

void Set_L1I_EGPRS_Filter(unsigned char *setting);

#endif


#endif
