#ifndef L1TRC_L1D_PRI_DEF_H
#define L1TRC_L1D_PRI_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)	(v1+0)
#define L1C_Str_SM_Handler(v1)	(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1D_Trc_DPTCHS0FLAGS(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DPTCHS0FLAGS(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DPTCHS0FLAGS(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DPCCFLAG(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DPCCFLAG(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DPCCFLAG(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DPNB(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_DPNB(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DPNB(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DPGSMMODE(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DPGSMMODE(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DPGSMMODE(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DPTXWIN0PROC(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DPTXWIN0PROC(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DPTXWIN0PROC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_DPRXWIN0PROC(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_DPRXWIN0PROC(v1, v2);\
} while(0)
#else
	#define L1D_Trc_DPRXWIN0PROC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_D2CStopUL() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_D2CStopUL();\
} while(0)
#else
	#define L1D_Trc_D2CStopUL() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_D2CFBFound() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_D2CFBFound();\
} while(0)
#else
	#define L1D_Trc_D2CFBFound() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SHARED2MCTL(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_SHARED2MCTL(v1, v2);\
} while(0)
#else
	#define L1D_Trc_SHARED2MCTL(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SetChannelCmd(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_SetChannelCmd(v1, v2);\
} while(0)
#else
	#define L1D_Trc_SetChannelCmd(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_ReportPeriod(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_ReportPeriod(v1, v2);\
} while(0)
#else
	#define L1D_Trc_ReportPeriod(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_FCChStage(v1) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_FCChStage(v1);\
} while(0)
#else
	#define L1D_Trc_FCChStage(v1)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_CipherCmd(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_CipherCmd(v1, v2);\
} while(0)
#else
	#define L1D_Trc_CipherCmd(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_CipherKey(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_CipherKey(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1D_Trc_CipherKey(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_PDNCON2(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_PDNCON2(v1, v2);\
} while(0)
#else
	#define L1D_Trc_PDNCON2(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_BCCR(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_BCCR(v1, v2);\
} while(0)
#else
	#define L1D_Trc_BCCR(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_EVENA1(v1, v2, v3) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_EVENA1(v1, v2, v3);\
} while(0)
#else
	#define L1D_Trc_EVENA1(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_USF(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_USF(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_USF(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_APC_VOLTTEMP(v1, v2, v3) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_APC_VOLTTEMP(v1, v2, v3);\
} while(0)
#else
	#define L1D_Trc_APC_VOLTTEMP(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SDCCH_UL() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_SDCCH_UL();\
} while(0)
#else
	#define L1D_Trc_SDCCH_UL() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SACCH_UL() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_SACCH_UL();\
} while(0)
#else
	#define L1D_Trc_SACCH_UL() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_FACCH_UL() do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_FACCH_UL();\
} while(0)
#else
	#define L1D_Trc_FACCH_UL() 
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SDCCH_UL_DATA(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_SDCCH_UL_DATA(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_SDCCH_UL_DATA(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_SACCH_UL_DATA(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_SACCH_UL_DATA(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_SACCH_UL_DATA(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_FACCH_UL_DATA(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_FACCH_UL_DATA(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trc_FACCH_UL_DATA(v1, v2, v3, v4)
#endif

#ifdef L1_CATCHER
	#define L1D_Trc_MaxTime(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_MaxTime(v1, v2);\
} while(0)
#else
	#define L1D_Trc_MaxTime(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1_Trace_sm1(v1, v2) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1_Trace_sm1(v1, v2);\
} while(0)
#else
	#define L1_Trace_sm1(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1_Trace_sm2(v1, v2, v3, v4, v5) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1_Trace_sm2(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1_Trace_sm2(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1_Trace_sm3(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1_Trace_sm3(v1, v2, v3, v4, v5, v6);\
} while(0)
#else
	#define L1_Trace_sm3(v1, v2, v3, v4, v5, v6)
#endif

#ifdef L1_CATCHER
	#define L1_Trace_sm4(v1) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1_Trace_sm4(v1);\
} while(0)
#else
	#define L1_Trace_sm4(v1)
#endif

#ifdef L1_CATCHER
	#define L1_Trace_sm5(v1, v2, v3, v4, v5) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1_Trace_sm5(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1_Trace_sm5(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1D_Trace_FMResult(v1, v2, v3, v4) do {\
		if(L1D_PRI_Trace_Filter[0]==1 && (L1D_PRI_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_Trace_FMResult(v1, v2, v3, v4);\
} while(0)
#else
	#define L1D_Trace_FMResult(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1D_PRI_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1D_Trc_DPTCHS0FLAGS(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_DPCCFLAG(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_DPNB(char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_DPGSMMODE(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_DPTXWIN0PROC(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_DPRXWIN0PROC(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_D2CStopUL(void);
void L1TRC_Send_L1D_Trc_D2CFBFound(void);
void L1TRC_Send_L1D_Trc_SHARED2MCTL(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_SetChannelCmd(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_ReportPeriod(char v1, char v2);
void L1TRC_Send_L1D_Trc_FCChStage(char v1);
void L1TRC_Send_L1D_Trc_CipherCmd(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_CipherKey(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1D_Trc_PDNCON2(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_BCCR(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_Trc_EVENA1(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1D_Trc_USF(unsigned char v1, short v2, char v3, short v4);
void L1TRC_Send_L1D_Trc_APC_VOLTTEMP(char v1, long v2, long v3);
void L1TRC_Send_L1D_Trc_SDCCH_UL(void);
void L1TRC_Send_L1D_Trc_SACCH_UL(void);
void L1TRC_Send_L1D_Trc_FACCH_UL(void);
void L1TRC_Send_L1D_Trc_SDCCH_UL_DATA(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_L1D_Trc_SACCH_UL_DATA(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_L1D_Trc_FACCH_UL_DATA(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_L1D_Trc_MaxTime(char v1, short v2);
void L1TRC_Send_L1_Trace_sm1(unsigned long v1, unsigned short v2);
void L1TRC_Send_L1_Trace_sm2(char v1, char v2, unsigned short v3, unsigned short v4, char v5);
void L1TRC_Send_L1_Trace_sm3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, short v5, short v6);
void L1TRC_Send_L1_Trace_sm4(unsigned long v1);
void L1TRC_Send_L1_Trace_sm5(unsigned char v1, unsigned long v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_L1D_Trace_FMResult(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);

void Set_L1D_PRI_Filter(unsigned char *setting);

#endif


#endif
