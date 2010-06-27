#ifndef L1TRC_L1D_EDGE_DEF_H
#define L1TRC_L1D_EDGE_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1D_Trc_DelayCD(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DelayCD(v1);\
} while(0)
#else
	#define L1D_Trc_DelayCD(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_PTCCH_CD_TOGETHER() do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_PTCCH_CD_TOGETHER();\
} while(0)
#else
	#define L1D_Trc_PTCCH_CD_TOGETHER() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_USF_Status(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_USF_Status(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_USF_Status(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_USF_Modtype(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_USF_Modtype(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_USF_Modtype(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_Mod_type(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_DSP_Mod_type(v1, v2);\
} while(0)
#else
	#define L1D_DSP_Mod_type(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_REPORT_D_VALUE(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_DSP_REPORT_D_VALUE(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1D_DSP_REPORT_D_VALUE(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_SRB_MACHINE(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_DSP_SRB_MACHINE(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1D_DSP_SRB_MACHINE(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1D_USF_Dummy_Detect(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_USF_Dummy_Detect(v1);\
} while(0)
#else
	#define L1D_USF_Dummy_Detect(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TX_AFC_Dac(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_TX_AFC_Dac(v1, v2);\
} while(0)
#else
	#define L1D_TX_AFC_Dac(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_IGain_Update(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_IGain_Update(v1, v2);\
} while(0)
#else
	#define L1D_IGain_Update(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_IGain_NewGain(v1) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_IGain_NewGain(v1);\
} while(0)
#else
	#define L1D_IGain_NewGain(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_SPLIT_CTIRQ2_PRE_EQ(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_SPLIT_CTIRQ2_PRE_EQ(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_SPLIT_CTIRQ2_PRE_EQ(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_CONTINUE_CTIRQ2_PRE_EQ(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_CONTINUE_CTIRQ2_PRE_EQ(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_CONTINUE_CTIRQ2_PRE_EQ(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_CONTINUE_CTIRQ1_PRE_EQ(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_CONTINUE_CTIRQ1_PRE_EQ(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_CONTINUE_CTIRQ1_PRE_EQ(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_6229_FB_power(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1D_6229_FB_power(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1D_6229_FB_power(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1D_TX_info(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1D_TX_info(v1, v2);\
} while(0)
#else
	#define L1D_TX_info(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_RX_DC_Offset(v1, v2, v3) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_RX_DC_Offset(v1, v2, v3);\
} while(0)
#else
	#define L1D_Trc_RX_DC_Offset(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_EDGE_USF(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_EDGE_USF(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_EDGE_USF(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SAIC_SNR(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_SNR(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1D_Trc_SAIC_SNR(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SAIC_FOE(v1, v2, v3, v4) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_FOE(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_SAIC_FOE(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SAIC_FWBW_SNR(v1, v2) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_FWBW_SNR(v1, v2);\
} while(0)
#else
	#define L1D_Trc_SAIC_FWBW_SNR(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_GEMINI_FB_debug(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_Trace_Filter[0]==1 && (L1D_EDGE_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_GEMINI_FB_debug(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1D_Trc_GEMINI_FB_debug(v1, v2, v3, v4, v5)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1D_EDGE_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1D_Trc_DelayCD(short v1);
void L1TRC_Send_L1D_Trc_PTCCH_CD_TOGETHER(void);
void L1TRC_Send_L1D_Trc_USF_Status(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_USF_Modtype(char v1, short v2, short v3, char v4);
void L1TRC_Send_L1D_DSP_Mod_type(unsigned short v1, short v2);
void L1TRC_Send_L1D_DSP_REPORT_D_VALUE(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_DSP_SRB_MACHINE(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_USF_Dummy_Detect(short v1);
void L1TRC_Send_L1D_TX_AFC_Dac(short v1, short v2);
void L1TRC_Send_L1D_IGain_Update(long v1, long v2);
void L1TRC_Send_L1D_IGain_NewGain(short v1);
void L1TRC_Send_L1D_SPLIT_CTIRQ2_PRE_EQ(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_CONTINUE_CTIRQ2_PRE_EQ(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_CONTINUE_CTIRQ1_PRE_EQ(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_6229_FB_power(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_TX_info(short v1, short v2);
void L1TRC_Send_L1D_Trc_RX_DC_Offset(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_EDGE_USF(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_L1D_Trc_SAIC_SNR(char v1, char v2, char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_L1D_Trc_SAIC_FOE(char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_Trc_SAIC_FWBW_SNR(short v1, short v2);
void L1TRC_Send_L1D_Trc_GEMINI_FB_debug(short v1, unsigned long v2, short v3, unsigned long v4, unsigned long v5);

void Set_L1D_EDGE_Filter(unsigned char *setting);

#endif


#endif
