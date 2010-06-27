#ifndef L1TRC_CSD_2_DEF_H
#define L1TRC_CSD_2_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_2(v1, v2, v3, v4, v5, v6) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_2(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_2(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_AFS_2(v1, v2, v3) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_AFS_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_AFS_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_AHS_2(v1, v2, v3) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_AHS_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_AHS_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RXQUAL_Input_2(v1, v2, v3) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_Input_2(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_RXQUAL_Input_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_ActivateReq_2(v1, v2, v3) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_ActivateReq_2(v1, v2, v3);\
} while(0)
#else
	#define CSD_Msg_ActivateReq_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DeActivateReq_2() do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_DeActivateReq_2();\
} while(0)
#else
	#define CSD_Msg_DeActivateReq_2() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_CMMReq_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_CMMReq_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_CMMReq_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_SHIFT_HALF_RLP_2() do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_SHIFT_HALF_RLP_2();\
} while(0)
#else
	#define CSD_Msg_SHIFT_HALF_RLP_2() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DL_FCS_ERROR_2() do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_DL_FCS_ERROR_2();\
} while(0)
#else
	#define CSD_Msg_DL_FCS_ERROR_2() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_UL_DTX_Allow_2(v1) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_UL_DTX_Allow_2(v1);\
} while(0)
#else
	#define CSD_Msg_UL_DTX_Allow_2(v1)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_LoopMode_2(v1) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_LoopMode_2(v1);\
} while(0)
#else
	#define CSD_Msg_LoopMode_2(v1)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_Dummy_Pattern_OverLoading_2() do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_Dummy_Pattern_OverLoading_2();\
} while(0)
#else
	#define CSD_Msg_Dummy_Pattern_OverLoading_2() 
#endif

#ifdef L1_CATCHER
	#define CSD_MSG_DSP_L2FillFrame_2() do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_MSG_DSP_L2FillFrame_2();\
} while(0)
#else
	#define CSD_MSG_DSP_L2FillFrame_2() 
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DnlinkData1_2(v1, v2, v3, v4) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_CSD_Msg_DnlinkData1_2(v1, v2, v3, v4);\
} while(0)
#else
	#define CSD_Msg_DnlinkData1_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_DnlinkData2_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_CSD_Msg_DnlinkData2_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_DnlinkData2_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_UplinkData1_2(v1, v2, v3) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_CSD_Msg_UplinkData1_2(v1, v2, v3);\
} while(0)
#else
	#define CSD_Msg_UplinkData1_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_UplinkData2_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_CSD_Msg_UplinkData2_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_UplinkData2_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1PutDnlinkData1_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_CSD_Msg_L1PutDnlinkData1_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1PutDnlinkData1_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1PutDnlinkData2_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_CSD_Msg_L1PutDnlinkData2_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1PutDnlinkData2_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1GetUplinkData1_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_CSD_Msg_L1GetUplinkData1_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1GetUplinkData1_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define CSD_Msg_L1GetUplinkData2_2(v1, v2) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_L1GetUplinkData2_2(v1, v2);\
} while(0)
#else
	#define CSD_Msg_L1GetUplinkData2_2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_DnlinkData1_2(v1, v2, v3, v4) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_FAX_Msg_DnlinkData1_2(v1, v2, v3, v4);\
} while(0)
#else
	#define FAX_Msg_DnlinkData1_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_DnlinkData2_2(v1, v2, v3, v4) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_FAX_Msg_DnlinkData2_2(v1, v2, v3, v4);\
} while(0)
#else
	#define FAX_Msg_DnlinkData2_2(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_UplinkData1_2(v1, v2, v3) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_FAX_Msg_UplinkData1_2(v1, v2, v3);\
} while(0)
#else
	#define FAX_Msg_UplinkData1_2(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define FAX_Msg_UplinkData2_2(v1, v2, v3, v4) do {\
		if(CSD_2_Trace_Filter[0]==1 && (CSD_2_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_FAX_Msg_UplinkData2_2(v1, v2, v3, v4);\
} while(0)
#else
	#define FAX_Msg_UplinkData2_2(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char CSD_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_RXQUAL_2(short v1, short v2, char v3, short v4, short v5, char v6);
void L1TRC_Send_L1C_Trace_RXQUAL_AFS_2(char v1, short v2, short v3);
void L1TRC_Send_L1C_Trace_RXQUAL_AHS_2(char v1, short v2, short v3);
void L1TRC_Send_L1C_Trace_RXQUAL_Input_2(short v1, short v2, short v3);
void L1TRC_Send_CSD_Msg_ActivateReq_2(char v1, char v2, char v3);
void L1TRC_Send_CSD_Msg_DeActivateReq_2(void);
void L1TRC_Send_CSD_Msg_CMMReq_2(char v1, char v2);
void L1TRC_Send_CSD_Msg_SHIFT_HALF_RLP_2(void);
void L1TRC_Send_CSD_Msg_DL_FCS_ERROR_2(void);
void L1TRC_Send_CSD_Msg_UL_DTX_Allow_2(char v1);
void L1TRC_Send_CSD_Msg_LoopMode_2(char v1);
void L1TRC_Send_CSD_Msg_Dummy_Pattern_OverLoading_2(void);
void L1TRC_Send_CSD_MSG_DSP_L2FillFrame_2(void);
void L1TRC_Send_CSD_Msg_DnlinkData1_2(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_CSD_Msg_DnlinkData2_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_UplinkData1_2(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_CSD_Msg_UplinkData2_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1PutDnlinkData1_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1PutDnlinkData2_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1GetUplinkData1_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_CSD_Msg_L1GetUplinkData2_2(unsigned char v1, unsigned char v2);
void L1TRC_Send_FAX_Msg_DnlinkData1_2(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_FAX_Msg_DnlinkData2_2(char v1, unsigned char v2, char v3, unsigned char v4);
void L1TRC_Send_FAX_Msg_UplinkData1_2(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_FAX_Msg_UplinkData2_2(char v1, unsigned char v2, char v3, unsigned char v4);

void Set_CSD_2_Filter(unsigned char *setting);

#endif


#endif
