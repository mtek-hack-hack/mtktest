#ifndef L1TRC_L1D_EDGE_2_DEF_H
#define L1TRC_L1D_EDGE_2_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1D_Trc_DelayCD_2(v1) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DelayCD_2(v1);\
} while(0)
#else
	#define L1D_Trc_DelayCD_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_PTCCH_CD_TOGETHER_2() do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_PTCCH_CD_TOGETHER_2();\
} while(0)
#else
	#define L1D_Trc_PTCCH_CD_TOGETHER_2() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_USF_Status_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_USF_Status_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_USF_Status_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_USF_Modtype_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_USF_Modtype_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_USF_Modtype_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_Mod_type_2(v1, v2) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_DSP_Mod_type_2(v1, v2);\
} while(0)
#else
	#define L1D_DSP_Mod_type_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_REPORT_D_VALUE_2(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_DSP_REPORT_D_VALUE_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1D_DSP_REPORT_D_VALUE_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1D_DSP_SRB_MACHINE_2(v1, v2, v3, v4, v5) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_DSP_SRB_MACHINE_2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1D_DSP_SRB_MACHINE_2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1D_USF_Dummy_Detect_2(v1) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_USF_Dummy_Detect_2(v1);\
} while(0)
#else
	#define L1D_USF_Dummy_Detect_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_TX_AFC_Dac_2(v1, v2) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_TX_AFC_Dac_2(v1, v2);\
} while(0)
#else
	#define L1D_TX_AFC_Dac_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_IGain_Update_2(v1, v2) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_IGain_Update_2(v1, v2);\
} while(0)
#else
	#define L1D_IGain_Update_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_IGain_NewGain_2(v1) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_IGain_NewGain_2(v1);\
} while(0)
#else
	#define L1D_IGain_NewGain_2(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_SPLIT_CTIRQ2_PRE_EQ_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_SPLIT_CTIRQ2_PRE_EQ_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_SPLIT_CTIRQ2_PRE_EQ_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_CONTINUE_CTIRQ2_PRE_EQ_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_CONTINUE_CTIRQ2_PRE_EQ_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_CONTINUE_CTIRQ2_PRE_EQ_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_CONTINUE_CTIRQ1_PRE_EQ_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_CONTINUE_CTIRQ1_PRE_EQ_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_CONTINUE_CTIRQ1_PRE_EQ_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_6229_FB_power_2(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1D_6229_FB_power_2(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1D_6229_FB_power_2(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1D_TX_info_2(v1, v2) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1D_TX_info_2(v1, v2);\
} while(0)
#else
	#define L1D_TX_info_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_RX_DC_Offset_2(v1, v2, v3) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_RX_DC_Offset_2(v1, v2, v3);\
} while(0)
#else
	#define L1D_Trc_RX_DC_Offset_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_EDGE_USF_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_EDGE_USF_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_EDGE_USF_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SAIC_SNR_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_SNR_2(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1D_Trc_SAIC_SNR_2(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SAIC_FOE_2(v1, v2, v3, v4) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_FOE_2(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_SAIC_FOE_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SAIC_FWBW_SNR_2(v1, v2) do {\
		if(L1D_EDGE_2_Trace_Filter[0]==1 && (L1D_EDGE_2_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_SAIC_FWBW_SNR_2(v1, v2);\
} while(0)
#else
	#define L1D_Trc_SAIC_FWBW_SNR_2(v1, v2)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1D_EDGE_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1D_Trc_DelayCD_2(short v1);
void L1TRC_Send_L1D_Trc_PTCCH_CD_TOGETHER_2(void);
void L1TRC_Send_L1D_Trc_USF_Status_2(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_USF_Modtype_2(char v1, short v2, short v3, char v4);
void L1TRC_Send_L1D_DSP_Mod_type_2(unsigned short v1, short v2);
void L1TRC_Send_L1D_DSP_REPORT_D_VALUE_2(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_DSP_SRB_MACHINE_2(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_USF_Dummy_Detect_2(short v1);
void L1TRC_Send_L1D_TX_AFC_Dac_2(short v1, short v2);
void L1TRC_Send_L1D_IGain_Update_2(long v1, long v2);
void L1TRC_Send_L1D_IGain_NewGain_2(short v1);
void L1TRC_Send_L1D_SPLIT_CTIRQ2_PRE_EQ_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_CONTINUE_CTIRQ2_PRE_EQ_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_CONTINUE_CTIRQ1_PRE_EQ_2(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_6229_FB_power_2(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_TX_info_2(short v1, short v2);
void L1TRC_Send_L1D_Trc_RX_DC_Offset_2(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_EDGE_USF_2(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_L1D_Trc_SAIC_SNR_2(char v1, char v2, char v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_L1D_Trc_SAIC_FOE_2(char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_Trc_SAIC_FWBW_SNR_2(short v1, short v2);

void Set_L1D_EDGE_2_Filter(unsigned char *setting);

#endif


#endif
