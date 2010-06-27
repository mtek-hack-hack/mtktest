#ifndef L1TRC_L1TAMR_DEF_H
#define L1TRC_L1TAMR_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1T_Trc_AMR_QI_INFO(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_QI_INFO(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_QI_INFO(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_EQ_CI(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_EQ_CI(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_EQ_CI(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_EQ_CI(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_EQ_CI(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_EQ_CI(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_EQ_RNV(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_EQ_RNV(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_EQ_RNV(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_EQ_RNV(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_EQ_RNV(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_EQ_RNV(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_ANT_DIV(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_ANT_DIV(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_ANT_DIV(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_ANT_DIV(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_ANT_DIV(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_ANT_DIV(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AFS_ANT_26_DIV(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AFS_ANT_26_DIV(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AFS_ANT_26_DIV(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AHS_ANT_26_DIV(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AHS_ANT_26_DIV(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AHS_ANT_26_DIV(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_CI_FILTER(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_CI_FILTER(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_CI_FILTER(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_CI_FIT(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_CI_FIT(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_CI_FIT(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_RNV_FILTER(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_RNV_FILTER(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_RNV_FILTER(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_ANT_DIV_FILTER(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_ANT_DIV_FILTER(v1, v2);\
} while(0)
#else
	#define L1T_Trc_AMR_ANT_DIV_FILTER(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_CI_COMPEN(v1, v2, v3) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_CI_COMPEN(v1, v2, v3);\
} while(0)
#else
	#define L1T_Trc_AMR_CI_COMPEN(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_SAIC_FLAG(v1) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_SAIC_FLAG(v1);\
} while(0)
#else
	#define L1T_Trc_AMR_SAIC_FLAG(v1)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_DSP_EQSOSUM(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_DSP_EQSOSUM(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_DSP_EQSOSUM(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_DSP_EQSOFT(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_DSP_EQSOFT(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_DSP_EQSOFT(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_EQSOFT_FILTER(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_EQSOFT_FILTER(v1, v2, v3, v4);\
} while(0)
#else
	#define L1T_Trc_AMR_EQSOFT_FILTER(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1T_Trc_AMR_ANTDIV_FILTER(v1, v2, v3) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trc_AMR_ANTDIV_FILTER(v1, v2, v3);\
} while(0)
#else
	#define L1T_Trc_AMR_ANTDIV_FILTER(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1TAMR_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1T_Trc_AMR_QI_INFO(char v1, char v2, char v3, char v4);
void L1TRC_Send_L1T_Trc_AFS_EQ_CI(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_EQ_CI(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_EQ_RNV(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_EQ_RNV(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_ANT_DIV(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_ANT_DIV(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_ANT_26_DIV(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_ANT_26_DIV(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_FILTER(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_FIT(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_RNV_FILTER(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_ANT_DIV_FILTER(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_COMPEN(short v1, short v2, short v3);
void L1TRC_Send_L1T_Trc_AMR_SAIC_FLAG(unsigned short v1);
void L1TRC_Send_L1T_Trc_AMR_DSP_EQSOSUM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1T_Trc_AMR_DSP_EQSOFT(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AMR_EQSOFT_FILTER(short v1, short v2, short v3, char v4);
void L1TRC_Send_L1T_Trc_AMR_ANTDIV_FILTER(short v1, short v2, char v3);

void Set_L1TAMR_Filter(unsigned char *setting);

#endif


#endif
