#ifndef L1TRC_CSD_DEF_H
#define L1TRC_CSD_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL(v1, v2, v3, v4, v5, v6) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1C_Trace_RXQUAL(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_AFS(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_AFS(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_AFS(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_AHS(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_AHS(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_AHS(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_Input(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_Input(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_Input(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_ActivateReq(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_ActivateReq(v1, v2, v3);\
} while(0)
#else
	#define CSD_Msg_ActivateReq(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DeActivateReq() do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_DeActivateReq();\
} while(0)
#else
	#define CSD_Msg_DeActivateReq() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_CMMReq(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_CMMReq(v1, v2);\
} while(0)
#else
	#define CSD_Msg_CMMReq(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_SHIFT_HALF_RLP() do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_SHIFT_HALF_RLP();\
} while(0)
#else
	#define CSD_Msg_SHIFT_HALF_RLP() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DL_FCS_ERROR() do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_DL_FCS_ERROR();\
} while(0)
#else
	#define CSD_Msg_DL_FCS_ERROR() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_UL_DTX_Allow(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_UL_DTX_Allow(v1);\
} while(0)
#else
	#define CSD_Msg_UL_DTX_Allow(v1)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_LoopMode(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_LoopMode(v1);\
} while(0)
#else
	#define CSD_Msg_LoopMode(v1)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_Dummy_Pattern_OverLoading() do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_Dummy_Pattern_OverLoading();\
} while(0)
#else
	#define CSD_Msg_Dummy_Pattern_OverLoading() 
#endif

#ifdef L1_CATCHER
	#define CSD_MSG_DSP_L2FillFrame() do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_MSG_DSP_L2FillFrame();\
} while(0)
#else
	#define CSD_MSG_DSP_L2FillFrame() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DnlinkData1(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_CSD_Msg_DnlinkData1(v1, v2, v3, v4);\
} while(0)
#else
	#define CSD_Msg_DnlinkData1(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DnlinkData2(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_CSD_Msg_DnlinkData2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_DnlinkData2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_UplinkData1(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_CSD_Msg_UplinkData1(v1, v2, v3);\
} while(0)
#else
	#define CSD_Msg_UplinkData1(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_UplinkData2(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_CSD_Msg_UplinkData2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_UplinkData2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1PutDnlinkData1(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_CSD_Msg_L1PutDnlinkData1(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1PutDnlinkData1(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1PutDnlinkData2(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_CSD_Msg_L1PutDnlinkData2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1PutDnlinkData2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1GetUplinkData1(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_CSD_Msg_L1GetUplinkData1(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1GetUplinkData1(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1GetUplinkData2(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_L1GetUplinkData2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1GetUplinkData2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_DnlinkData1(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_FAX_Msg_DnlinkData1(v1, v2, v3, v4);\
} while(0)
#else
	#define FAX_Msg_DnlinkData1(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_DnlinkData2(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_FAX_Msg_DnlinkData2(v1, v2, v3, v4);\
} while(0)
#else
	#define FAX_Msg_DnlinkData2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_UplinkData1(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_FAX_Msg_UplinkData1(v1, v2, v3);\
} while(0)
#else
	#define FAX_Msg_UplinkData1(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_UplinkData2(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_FAX_Msg_UplinkData2(v1, v2, v3, v4);\
} while(0)
#else
	#define FAX_Msg_UplinkData2(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char CSD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_RXQUAL(short v1, short v2, char v3, short v4, short v5, char v6);
void L1TRC_Send_L1C_Trace_RXQUAL_AFS(char v1, short v2, short v3);
void L1TRC_Send_L1C_Trace_RXQUAL_AHS(char v1, short v2, short v3);
void L1TRC_Send_L1C_Trace_RXQUAL_Input(short v1, short v2, short v3);
void L1TRC_Send_CSD_Msg_ActivateReq(char v1, char v2, char v3);
void L1TRC_Send_CSD_Msg_DeActivateReq(void);
void L1TRC_Send_CSD_Msg_CMMReq(char v1, char v2);
void L1TRC_Send_CSD_Msg_SHIFT_HALF_RLP(void);
void L1TRC_Send_CSD_Msg_DL_FCS_ERROR(void);
void L1TRC_Send_CSD_Msg_UL_DTX_Allow(char v1);
void L1TRC_Send_CSD_Msg_LoopMode(char v1);
void L1TRC_Send_CSD_Msg_Dummy_Pattern_OverLoading(void);
void L1TRC_Send_CSD_MSG_DSP_L2FillFrame(void);
void L1TRC_Send_CSD_Msg_DnlinkData1(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_CSD_Msg_DnlinkData2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_UplinkData1(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_CSD_Msg_UplinkData2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1PutDnlinkData1(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1PutDnlinkData2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1GetUplinkData1(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1GetUplinkData2(unsigned char v1, unsigned char v2);
void L1TRC_Send_FAX_Msg_DnlinkData1(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_FAX_Msg_DnlinkData2(char v1, unsigned char v2, char v3, unsigned char v4);
void L1TRC_Send_FAX_Msg_UplinkData1(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_FAX_Msg_UplinkData2(char v1, unsigned char v2, char v3, unsigned char v4);

void Set_CSD_Filter(unsigned char *setting);

#endif


#endif
