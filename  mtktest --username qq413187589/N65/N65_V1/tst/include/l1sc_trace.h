#ifndef L1TRC_L1SC_DEF_H
#define L1TRC_L1SC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1SC_Str_Bool(v1)	(v1+0)
#define L1SC_Str_SCMODE(v1)	(v1+2)
#define L1C_Str_Identity(v1)	(v1+11)
#define L1C_Str_TFI(v1)	(v1+15)
#define L1C_Str_AMR_Status(v1)	(v1+17)
#define L1C_Str_Loopback_Mode(v1)	(v1+25)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1SC_Msg_FB(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SC_Msg_FB(v1, v2, v3);\
} while(0)
#else
	#define L1SC_Msg_FB(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_FB_done(v1, v2, v3, v4, v5, v6) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SC_Msg_FB_done(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1SC_Msg_FB_done(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_FB_abort(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SC_Msg_FB_abort(v1, v2);\
} while(0)
#else
	#define L1SC_Msg_FB_abort(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SB(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1SC_Msg_SB(v1, v2);\
} while(0)
#else
	#define L1SC_Msg_SB(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SB_done(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1SC_Msg_SB_done(v1, v2, v3, v4);\
} while(0)
#else
	#define L1SC_Msg_SB_done(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SB_abort(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1SC_Msg_SB_abort(v1);\
} while(0)
#else
	#define L1SC_Msg_SB_abort(v1)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SI(v1, v2, v3, v4) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SC_Msg_SI(v1, v2, v3, v4);\
} while(0)
#else
	#define L1SC_Msg_SI(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SI_done(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SC_Msg_SI_done(v1, v2, v3);\
} while(0)
#else
	#define L1SC_Msg_SI_done(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SI_abort(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SC_Msg_SI_abort(v1, v2);\
} while(0)
#else
	#define L1SC_Msg_SI_abort(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SCMODE(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1SC_Msg_SCMODE(v1, v2);\
} while(0)
#else
	#define L1SC_Msg_SCMODE(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_SCARFCN(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1SC_Msg_SCARFCN(v1, v2);\
} while(0)
#else
	#define L1SC_Msg_SCARFCN(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1C_ReportGPRS_DL_CB(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_ReportGPRS_DL_CB(v1);\
} while(0)
#else
	#define L1C_ReportGPRS_DL_CB(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PUAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_PUAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);\
} while(0)
#else
	#define L1C_Trace_PUAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDAS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_PDAS(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1C_Trace_PDAS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PUAS(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_PUAS(v1, v2, v3, v4, v5, v6, v7, v8, v9);\
} while(0)
#else
	#define L1C_Trace_PUAS(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PPR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_PPR(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1C_Trace_PPR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PTR(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_PTR(v1, v2, v3, v4, v5, v6, v7);\
} while(0)
#else
	#define L1C_Trace_PTR(v1, v2, v3, v4, v5, v6, v7)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_PDCH_Release(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Trace_PDCH_Release(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_PDCH_Release(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_Debug_UL_DL_CB(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_Debug_UL_DL_CB(v1);\
} while(0)
#else
	#define L1C_Trace_Debug_UL_DL_CB(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_FixAlloc_Transition(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_FixAlloc_Transition(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_FixAlloc_Transition(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_RepeatAlloc(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_RepeatAlloc(v1, v2, v3);\
} while(0)
#else
	#define L1I_Trace_RepeatAlloc(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_ReportRepeatAlloc(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_ReportRepeatAlloc(v1);\
} while(0)
#else
	#define L1I_Trace_ReportRepeatAlloc(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_AllocBitMap(v1, v2) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_AllocBitMap(v1, v2);\
} while(0)
#else
	#define L1I_Trace_AllocBitMap(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_BitMapNo(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_BitMapNo(v1);\
} while(0)
#else
	#define L1I_Trace_BitMapNo(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_Loopback_Mode(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Trace_Loopback_Mode(v1);\
} while(0)
#else
	#define L1C_Trace_Loopback_Mode(v1)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_AMR_Status(v1, v2, v3) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_AMR_Status(v1, v2, v3);\
} while(0)
#else
	#define L1C_Trace_AMR_Status(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1C_Trace_RATSCCH_DATA(v1) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_RATSCCH_DATA(v1);\
} while(0)
#else
	#define L1C_Trace_RATSCCH_DATA(v1)
#endif

#ifdef L1_CATCHER
	#define L1I_Trace_NC_Measurement(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_NC_Measurement(v1, v2, v3, v4, v5, v6, v7, v8);\
} while(0)
#else
	#define L1I_Trace_NC_Measurement(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_BSIC_Debug(v1, v2, v3, v4, v5) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1SC_Msg_BSIC_Debug(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1SC_Msg_BSIC_Debug(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1SC_Msg_BCCH_Debug(v1, v2, v3, v4, v5, v6) do {\
		if(L1SC_Trace_Filter[0]==1 && (L1SC_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1SC_Msg_BCCH_Debug(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1SC_Msg_BCCH_Debug(v1, v2, v3, v4, v5, v6)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1SC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1SC_Msg_FB(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1SC_Msg_FB_done(short v1, unsigned char v2, unsigned char v3, short v4, char v5, unsigned char v6);
void L1TRC_Send_L1SC_Msg_FB_abort(short v1, unsigned char v2);
void L1TRC_Send_L1SC_Msg_SB(short v1, unsigned char v2);
void L1TRC_Send_L1SC_Msg_SB_done(short v1, unsigned char v2, short v3, char v4);
void L1TRC_Send_L1SC_Msg_SB_abort(short v1);
void L1TRC_Send_L1SC_Msg_SI(short v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1SC_Msg_SI_done(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1SC_Msg_SI_abort(short v1, unsigned char v2);
void L1TRC_Send_L1SC_Msg_SCMODE(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1SC_Msg_SCARFCN(short v1, short v2);
void L1TRC_Send_L1C_ReportGPRS_DL_CB(unsigned long v1);
void L1TRC_Send_L1C_Trace_PUAN(char v1, char v2, char v3, char v4, char v5, char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12, unsigned char v13, unsigned char v14);
void L1TRC_Send_L1C_Trace_PDAS(char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_L1C_Trace_PUAS(char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, char v9);
void L1TRC_Send_L1C_Trace_PPR(char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_L1C_Trace_PTR(char v1, char v2, char v3, unsigned char v4, char v5, char v6, char v7);
void L1TRC_Send_L1C_Trace_PDCH_Release(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_Debug_UL_DL_CB(char v1);
void L1TRC_Send_L1I_Trace_FixAlloc_Transition(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_RepeatAlloc(char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_L1I_Trace_ReportRepeatAlloc(unsigned char v1);
void L1TRC_Send_L1I_Trace_AllocBitMap(char v1, char v2);
void L1TRC_Send_L1I_Trace_BitMapNo(char v1);
void L1TRC_Send_L1C_Trace_Loopback_Mode(unsigned char v1);
void L1TRC_Send_L1C_Trace_AMR_Status(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Trace_RATSCCH_DATA(unsigned char v1);
void L1TRC_Send_L1I_Trace_NC_Measurement(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_L1SC_Msg_BSIC_Debug(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1SC_Msg_BCCH_Debug(short v1, short v2, short v3, short v4, short v5, short v6);

void Set_L1SC_Filter(unsigned char *setting);

#endif


#endif
