#ifndef L1TRC_L1TAMR_2_DEF_H
#define L1TRC_L1TAMR_2_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1T_Trc_AMR_QI_INFO_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_QI_INFO_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_QI_INFO_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_EQ_CI_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_EQ_CI_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_EQ_CI_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_EQ_CI_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_EQ_CI_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_EQ_CI_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_EQ_RNV_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_EQ_RNV_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_EQ_RNV_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_EQ_RNV_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_EQ_RNV_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_EQ_RNV_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_ANT_DIV_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_ANT_DIV_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_ANT_DIV_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_ANT_DIV_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_ANT_DIV_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_ANT_DIV_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_ANT_26_DIV_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_ANT_26_DIV_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_ANT_26_DIV_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_ANT_26_DIV_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_ANT_26_DIV_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_ANT_26_DIV_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_CI_FILTER_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_CI_FILTER_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_CI_FILTER_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_CI_FIT_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_CI_FIT_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_CI_FIT_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_RNV_FILTER_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_RNV_FILTER_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_RNV_FILTER_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_ANT_DIV_FILTER_2(v1, v2) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_ANT_DIV_FILTER_2(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_ANT_DIV_FILTER_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_CI_COMPEN_2(v1, v2, v3) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_CI_COMPEN_2(v1, v2, v3);\
} while(0)
#else
	#define L1T_Trc_AMR_CI_COMPEN_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_SAIC_FLAG_2(v1) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_SAIC_FLAG_2(v1);\
} while(0)
#else
	#define L1T_Trc_AMR_SAIC_FLAG_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_DSP_EQSOSUM_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_DSP_EQSOSUM_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_DSP_EQSOSUM_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_DSP_EQSOFT_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_DSP_EQSOFT_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_DSP_EQSOFT_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_EQSOFT_FILTER_2(v1, v2, v3, v4) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_EQSOFT_FILTER_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_EQSOFT_FILTER_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_ANTDIV_FILTER_2(v1, v2, v3) do {\
		if(L1TAMR_2_Trace_Filter[0]==1 && (L1TAMR_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_ANTDIV_FILTER_2(v1, v2, v3);\
} while(0)
#else
	#define L1T_Trc_AMR_ANTDIV_FILTER_2(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1TAMR_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1T_Trc_AMR_QI_INFO_2(char v1, char v2, char v3, char v4);
void L1TRC_Send_L1T_Trc_AFS_EQ_CI_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_EQ_CI_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_EQ_RNV_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_EQ_RNV_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_ANT_DIV_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_ANT_DIV_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_ANT_26_DIV_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_ANT_26_DIV_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_FILTER_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_FIT_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_RNV_FILTER_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_ANT_DIV_FILTER_2(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_COMPEN_2(short v1, short v2, short v3);
void L1TRC_Send_L1T_Trc_AMR_SAIC_FLAG_2(unsigned short v1);
void L1TRC_Send_L1T_Trc_AMR_DSP_EQSOSUM_2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1T_Trc_AMR_DSP_EQSOFT_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AMR_EQSOFT_FILTER_2(short v1, short v2, short v3, char v4);
void L1TRC_Send_L1T_Trc_AMR_ANTDIV_FILTER_2(short v1, short v2, char v3);

void Set_L1TAMR_2_Filter(unsigned char *setting);

#endif


#endif
