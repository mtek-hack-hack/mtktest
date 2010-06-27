#ifndef L1TRC_L1Audio_DEF_H
#define L1TRC_L1Audio_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1AUDIO_Str_Bool(v1)	(v1+0)
#define L1AUDIO_Str_onoff(v1)	(v1+2)
#define L1AUDIO_Func_Name(v1)	(v1+4)
#define AFE_Switch_Name(v1)	(v1+12)
#define AM_Switch_Name(v1)	(v1+17)
#define AM_IO_Name(v1)	(v1+28)
#define AM_Speech_Feature_Name(v1)	(v1+32)
#define L1Audio_Speech_State(v1)	(v1+36)
#define L1SP_Speech_Codec_Mode(v1)	(v1+42)
#define L1SP_Speech_TX_Type(v1)	(v1+53)
#define L1SP_Speech_RX_Type(v1)	(v1+57)


/****************************/
/* Message macro definition */
/****************************/
#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_Switch(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_Switch(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AFE_Switch(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_TurnSpk(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_TurnSpk(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AFE_TurnSpk(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_TurnMIC(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_TurnMIC(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AFE_TurnMIC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_TurnFIR(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_TurnFIR(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AFE_TurnFIR(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_SetInput(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_SetInput(v1);\
} while(0)
#else
	#define L1Audio_Msg_AFE_SetInput(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_MicVolume(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_MicVolume(v1);\
} while(0)
#else
	#define L1Audio_Msg_AFE_MicVolume(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_StVolume(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_StVolume(v1);\
} while(0)
#else
	#define L1Audio_Msg_AFE_StVolume(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_EcParam(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_EcParam(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AFE_EcParam(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_SetDevice(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_SetDevice(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AFE_SetDevice(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_SetVolume(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_SetVolume(v1, v2, v3);\
} while(0)
#else
	#define L1Audio_Msg_AFE_SetVolume(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_SpkSelect(v1, v2, v3, v4, v5) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_SpkSelect(v1, v2, v3, v4, v5);\
} while(0)
#else
	#define L1Audio_Msg_AFE_SpkSelect(v1, v2, v3, v4, v5)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AFE_Gain(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_Gain(v1, v2, v3);\
} while(0)
#else
	#define L1Audio_Msg_AFE_Gain(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AM_Switch(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_Switch(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AM_Switch(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AM_Handover(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_Handover(v1);\
} while(0)
#else
	#define L1Audio_Msg_AM_Handover(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AM_IO_Switch(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_IO_Switch(v1);\
} while(0)
#else
	#define L1Audio_Msg_AM_IO_Switch(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AM_SetSpeech(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_SetSpeech(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_AM_SetSpeech(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_Speech_State(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_Speech_State(v1);\
} while(0)
#else
	#define L1Audio_Msg_Speech_State(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_DSP_INT(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_DSP_INT(v1);\
} while(0)
#else
	#define L1Audio_Msg_DSP_INT(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_AM_DELAY_TABLE(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_DELAY_TABLE(v1);\
} while(0)
#else
	#define L1Audio_Msg_AM_DELAY_TABLE(v1)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_SPEECH_FRAME(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_SPEECH_FRAME(v1, v2, v3);\
} while(0)
#else
	#define L1Audio_Msg_SPEECH_FRAME(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_SPEECH_CODEC(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_SPEECH_CODEC(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_SPEECH_CODEC(v1, v2)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_VM_DEBUG(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_VM_DEBUG(v1, v2, v3);\
} while(0)
#else
	#define L1Audio_Msg_VM_DEBUG(v1, v2, v3)
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_VBI_RESET() do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_VBI_RESET();\
} while(0)
#else
	#define L1Audio_Msg_VBI_RESET() 
#endif

#ifdef L1_CATCHER
	#define L1Audio_Msg_SPE_DEBUG(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_SPE_DEBUG(v1, v2);\
} while(0)
#else
	#define L1Audio_Msg_SPE_DEBUG(v1, v2)
#endif



/*******************************/
/* declaration of filter array*/
/*******************************/
extern unsigned char L1Audio_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1Audio_Msg_AFE_Switch(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_TurnSpk(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_TurnMIC(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_TurnFIR(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_SetInput(char v1);
void L1TRC_Send_L1Audio_Msg_AFE_MicVolume(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_AFE_StVolume(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_AFE_EcParam(short v1, short v2);
void L1TRC_Send_L1Audio_Msg_AFE_SetDevice(unsigned char v1, char v2);
void L1TRC_Send_L1Audio_Msg_AFE_SetVolume(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1Audio_Msg_AFE_SpkSelect(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1Audio_Msg_AFE_Gain(unsigned short v1, unsigned short v2, short v3);
void L1TRC_Send_L1Audio_Msg_AM_Switch(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AM_Handover(char v1);
void L1TRC_Send_L1Audio_Msg_AM_IO_Switch(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_AM_SetSpeech(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_Speech_State(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_DSP_INT(unsigned short v1);
void L1TRC_Send_L1Audio_Msg_AM_DELAY_TABLE(short v1);
void L1TRC_Send_L1Audio_Msg_SPEECH_FRAME(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1Audio_Msg_SPEECH_CODEC(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_VM_DEBUG(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1Audio_Msg_VBI_RESET(void);
void L1TRC_Send_L1Audio_Msg_SPE_DEBUG(unsigned short v1, unsigned short v2);

void Set_L1Audio_Filter(unsigned char *setting);

#endif


#endif
