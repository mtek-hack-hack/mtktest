#ifndef L1TRC_L1IAMR_DEF_H
#define L1TRC_L1IAMR_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_AMR_CONFIG_MASK_STR(v1)	(v1+0)
#define L1D_Trc_Str_AMR_Channel_Codec(v1)	(v1+16)
#define L1D_Trc_Str_AMR_Speech_Codec(v1)	(v1+30)
#define L1D_Trc_Str_AMR_RX_Type(v1)	(v1+38)
#define L1D_Trc_Str_AMR_TX_Type(v1)	(v1+46)
#define L1D_Trc_Str_AFS_IM_Detect(v1)	(v1+50)
#define L1D_Trc_Str_AHS_IM_Detect(v1)	(v1+57)
#define L1D_Trc_Str_AFS_SID_Stolen(v1)	(v1+64)
#define L1D_Trc_Str_AHS_SID_Stolen(v1)	(v1+70)
#define L1D_Trc_Str_AMR_CC2(v1)	(v1+76)
#define L1D_Trc_Str_AMR_CC_TX(v1)	(v1+81)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Channel_Decoder(v1, v2, v3, v4) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Channel_Decoder(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trc_AMR_Channel_Decoder(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Channel_Encoder(v1, v2, v3) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Channel_Encoder(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trc_AMR_Channel_Encoder(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Speech_Decoder(v1) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Speech_Decoder(v1);\
} while(0)
#else
	#define L1I_Trc_AMR_Speech_Decoder(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Speech_Encoder(v1) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Speech_Encoder(v1);\
} while(0)
#else
	#define L1I_Trc_AMR_Speech_Encoder(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Codec_Err(v1) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Codec_Err(v1);\
} while(0)
#else
	#define L1I_Trc_AMR_Codec_Err(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_CC_TX(v1) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_CC_TX(v1);\
} while(0)
#else
	#define L1I_Trc_AMR_CC_TX(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Config_Flag(v1, v2, v3, v4, v5) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Config_Flag(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1I_Trc_AMR_Config_Flag(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_INB(v1, v2, v3, v4) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_INB(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trc_AMR_INB(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_INB_Corr(v1, v2, v3, v4) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_INB_Corr(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trc_AMR_INB_Corr(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_INB_Debug(v1, v2, v3, v4) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_INB_Debug(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trc_AMR_INB_Debug(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_FACCH_RATSCCH(v1, v2) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_FACCH_RATSCCH(v1, v2);\
} while(0)
#else
	#define L1I_Trc_AMR_FACCH_RATSCCH(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_IM_SID(v1, v2) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_IM_SID(v1, v2);\
} while(0)
#else
	#define L1I_Trc_AMR_IM_SID(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Config(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Config(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11);\
} while(0)
#else
	#define L1I_Trc_AMR_Config(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_DSP_Threshold(v1, v2, v3) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_DSP_Threshold(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trc_AMR_DSP_Threshold(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_DSP_ICM(v1, v2, v3, v4) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_DSP_ICM(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trc_AMR_DSP_ICM(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_DSP_ACS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_DSP_ACS(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1I_Trc_AMR_DSP_ACS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_DSP_CMR_Enable(v1, v2) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_DSP_CMR_Enable(v1, v2);\
} while(0)
#else
	#define L1I_Trc_AMR_DSP_CMR_Enable(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_DSP_CI_Compen(v1) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_DSP_CI_Compen(v1);\
} while(0)
#else
	#define L1I_Trc_AMR_DSP_CI_Compen(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Speech_Info(v1, v2, v3, v4) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Speech_Info(v1, v2, v3, v4);\
} while(0)
#else
	#define L1I_Trc_AMR_Speech_Info(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Debug_Info1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Debug_Info1(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1I_Trc_AMR_Debug_Info1(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1I_Trc_AMR_Debug_Info2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1IAMR_Trace_Filter[0]==1 && (L1IAMR_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trc_AMR_Debug_Info2(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1I_Trc_AMR_Debug_Info2(v1, v2, v3, v4, v5, v6, v7)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1IAMR_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Trc_AMR_Channel_Decoder(unsigned char v1, unsigned char v2, char v3, short v4);
void L1TRC_Send_L1I_Trc_AMR_Channel_Encoder(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trc_AMR_Speech_Decoder(unsigned char v1);
void L1TRC_Send_L1I_Trc_AMR_Speech_Encoder(unsigned char v1);
void L1TRC_Send_L1I_Trc_AMR_Codec_Err(unsigned char v1);
void L1TRC_Send_L1I_Trc_AMR_CC_TX(unsigned char v1);
void L1TRC_Send_L1I_Trc_AMR_Config_Flag(unsigned short v1, unsigned short v2, unsigned short v3, char v4, char v5);
void L1TRC_Send_L1I_Trc_AMR_INB(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1I_Trc_AMR_INB_Corr(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1I_Trc_AMR_INB_Debug(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1I_Trc_AMR_FACCH_RATSCCH(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trc_AMR_IM_SID(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trc_AMR_Config(char v1, unsigned char v2, char v3, unsigned char v4, char v5, char v6, char v7, char v8, char v9, char v10, char v11);
void L1TRC_Send_L1I_Trc_AMR_DSP_Threshold(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1I_Trc_AMR_DSP_ICM(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_L1I_Trc_AMR_DSP_ACS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_L1I_Trc_AMR_DSP_CMR_Enable(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trc_AMR_DSP_CI_Compen(short v1);
void L1TRC_Send_L1I_Trc_AMR_Speech_Info(unsigned short v1, unsigned short v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_L1I_Trc_AMR_Debug_Info1(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_L1I_Trc_AMR_Debug_Info2(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);

void Set_L1IAMR_Filter(unsigned char *setting);

#endif


#endif
