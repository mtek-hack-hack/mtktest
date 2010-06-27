#ifndef _L1SP_TRC_H
#define _L1SP_TRC_H

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before l1sp_trc.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before nvram_trc.h"
#endif

#define TRACE_GROUP_SBC TRACE_GROUP_1
#define TRACE_GROUP_DAFRTP TRACE_GROUP_1
#define TRACE_GROUP_SND TRACE_GROUP_2
#define TRACE_GROUP_AUD_PROCESS TRACE_GROUP_3
#define TRACE_GROUP_VORTP TRACE_GROUP_4
#define TRACE_GROUP_CACHE TRACE_GROUP_5
#define TRACE_GROUP_AUDRTP TRACE_GROUP_6
#define TRACE_GROUP_APM TRACE_GROUP_7

BEGIN_TRACE_MAP(MOD_L1SP)

   // AFE
   TRC_MSG(AFE_SWITCH_FIR, "AFE Switch FIR %c for aud_func %X")
   TRC_MSG(AFE_SWITCH_LOOPBACK, "AFE Switch Loopback %c")
   TRC_MSG(AFE_SWITCH_MIC, "AFE Switch MIC %c for aud_func %X")
   TRC_MSG(AFE_SET_INPUT_SRC, "AFE SetInputSource: %X")
   TRC_MSG(AFE_GAIN, "AFE_VAG_CON:%X, AFE_AAG_CON:%X, DP_SIDETONE:%X")
   TRC_MSG(AFE_DIGI_GAIN, "DP_VOL_OUT_PCM:%X, DP_DigiGain_Setting:%X")
   TRC_MSG(AFE_SET_MIC_VOLUME, "AFE SetMicrophoneVolume: %X")
   TRC_MSG(AFE_SET_SIDETONE_VOLUME, "AFE SetSideToneVolume: %X")
   TRC_MSG(AFE_SET_OUTPUT_DEVICE, "AFE Set aud_func %X OutputDevice %X")
   TRC_MSG(AFE_SET_OUTPUT_VOLUME, "AFE Set aud_func %X OutputVolume %d %d")



   // L1CTM
   TRC_MSG(L1CTM_OPEN, "Call L1Ctm_Open")
   TRC_MSG(L1CTM_CLOSE, "Call L1Ctm_Close")
   TRC_MSG(L1CTM_SET_INTERFACE, "Call L1Ctm_SetInterface")
   TRC_MSG(L1CTM_START_NEGOTIATION, "Call L1Ctm_StartNegotiation")
   TRC_MSG(L1CTM_TX_PUT_TEXT, "Call L1Ctm_TxPutText")
   TRC_MSG(L1CTM_RX_GET_TEXT, "Call L1Ctm_RxGetText")

   TRC_MSG(L1CTM_FAR_END_CTM_DETECTED, "L1Ctm far-end CTM detected")
   TRC_MSG(L1CTM_NEGOTIATION_SUCCESS, "L1Ctm negotiation success")
   TRC_MSG(L1CTM_NEGOTIATION_FAIL, "L1Ctm negotiation fail")
   TRC_MSG(L1CTM_DEMAND_CTM_ACK, "L1Ctm is demanded to send CTM ACK")
   TRC_MSG(L1CTM_UL_SEND_IDLE_AS_ACK, "L1CtmTx ul-path send IDLE as ACK")
   TRC_MSG(L1CTM_DL_DETECT_CTM_SYNC, "L1Ctm dl-path detect CTM Sync")
   TRC_MSG(L1CTM_DL_CTM_BURST_END, "L1Ctm dl-path detect CTM burst-end")

   TRC_MSG(L1CTM_UL_SEND_ENQUIRY_CHAR, "L1Ctm ul-path send %d-time ENQUIRY char")
   TRC_MSG(L1CTM_UL_GET_DECODED_TTY_CHAR, "L1Ctm ul-path get decoded TTY-char 0x%02X")
   TRC_MSG(L1CTM_UL_SEND_CTM_CHAR, "L1Ctm ul-path send CTM-char 0x%02X")
   TRC_MSG(L1CTM_DL_GET_RECEIVED_CTM_CHAR, "L1Ctm dl-path get received CTM-char 0x%02X")
   TRC_MSG(L1CTM_DL_SEND_TTY_CHAR, "L1Ctm dl-path send TTY-char 0x%02X")
   TRC_MSG(L1CTM_REC_DIR_NO, "L1Ctm record to dir REC_%02u")

   // SBC
   TRC_MSG(L1SBC_ENTER_SBC_INITIATEBITPOOL, "Enter SBC_InitiateBitPool")
   TRC_MSG(L1SBC_ENTER_SBC_ADJUSTBITPOOL, "Enter SBC_AdjustBitPool")
   TRC_MSG(L1SBC_ENTER_SBC_ADJUSTBITRATEFROMQOS, "Enter sbc_AdjustBitRateFromQoS")
   TRC_MSG(L1SBC_ENTER_SBC_QUERYPAYLOADSIZE, "Enter sbc_QueryPayloadSize")
   TRC_MSG(L1SBC_ENTER_SBC_GETPAYLOAD, "Enter sbc_GetPayload")
   TRC_MSG(L1SBC_ENTER_SBC_OPEN, "Enter SBC_Open")
   TRC_MSG(L1SBC_ENTER_SBC_CLOSE, "Enter SBC_Close")
   TRC_MSG(L1SBC_ENTER_SBC_GETMEMREQ, "Enter SBC_GetMemReq")
   TRC_MSG(L1SBC_ENTER_SBC_ENCODING, "Enter sbc_event_handler")
   TRC_MSG(L1SBC_QOS_REPORT, "SBC QoS=%d, change bitrate from %d to %d")
   TRC_MSG(L1SBC_OPEN_REPORT, "SBC opened with id=%d, initial bitrate=%d, full sbc=%d, fmt=%d")
   TRC_MSG(L1SBC_CLOSE_REPORT, "SBC closed with %d frame dropped")
   TRC_MSG(L1SBC_CONFIG_REPORT, "SBC encoder config: fs=%d, cm=%d, bp=%d-%d-%d")
   TRC_MSG(L1SBC_ENCODER_REPORT, "SBC encoder status: process %d samples, left %d bytes, produce %d frames")
   TRC_MSG(L1SBC_PAYLOAD_REPORT, "SBC payload request %dB, get %dB, %d frames, left %dB")
   TRC_MSG(L1SBC_FRAME_BUFFER_UNDERRUN, "SBC frame buffer underrun")
   TRC_MSG(L1SBC_ENCODER_CONFIG, "SBC encoder config: ana: %d, up: %d, sample freq: %d/%d")

   // SND
   TRC_MSG(L1SND_ENTER_SND_OPEN, "Enter SND_Open")
   TRC_MSG(L1SND_ENTER_SND_CLOSE, "Enter SND_Close")
   TRC_MSG(L1SND_ENTER_SND_PLAY, "Enter SND_Play")
   TRC_MSG(L1SND_ENTER_SND_STOP, "Enter SND_Stop")
   TRC_MSG(L1SND_CONFIG_ULMIXER, "SND ConfigULMixer, flag:%d, gain:%d")
   TRC_MSG(L1SND_CONFIG_DLMIXER, "SND ConfigDLMixer, flag:%d, gain:%d")
   TRC_MSG(L1SND_REPEATED, "SND Repeat-play, elapsed:%d times")
   TRC_MSG(L1SND_FILLBUFFER, "SND Filled %d bytes")
   TRC_MSG(L1SND_DATACHUNK_SIZE, "SND Data chunk size: %d bytes")

   // L1AUDIO
   TRC_MSG(L1AUDIO_OPEN_FILE, "Enter AUD_Open file, type = %d")
   TRC_MSG(L1AUDIO_OPEN_STREAM, "Enter AUD_Open stream, type = %d")
   TRC_MSG(L1AUDIO_PLAY_FILE, "Enter AUD_Play file, type = %d")
   TRC_MSG(L1AUDIO_PLAY_STREAM, "Enter AUD_Play stream, type = %d")
   TRC_MSG(L1AUDIO_RECORD, "Enter AUD_Record stream, type = %d")
   TRC_MSG(L1AUDIO_PROCESS, "Enter AUD_Process, type = %d")
   TRC_MSG(L1AUDIO_PAUSE, "Enter AUD_Pause, type = %d")
   TRC_MSG(L1AUDIO_RESUME, "Enter AUD_Resume, type = %d")
   TRC_MSG(L1AUDIO_STOP, "Enter AUD_Stop, type = %d")
   TRC_MSG(L1AUDIO_CLOSE, "Enter AUD_Close, type = %d")
   TRC_MSG(L1AUDIO_SEEK, "Enter AUD_Seek, type = %d")
   TRC_MSG(L1AUDIO_SET_START_TIME, "Set audio start time, start time = %d ms, type = %d")
   TRC_MSG(L1AUDIO_SET_STOP_TIME, "Set audio stop time, stop time = %d ms, type = %d")
   TRC_MSG(L1AUDIO_CONTENT, "Enter AUD_GetContentDescInfo, type = %d")

   TRC_MSG(L1AUDIO_INIT_STATE, "Audio function in initial state")
   TRC_MSG(L1AUDIO_RUNNING_STATE, "Audio function in running state")
   TRC_MSG(L1AUDIO_STOP_STATE, "Audio function in stop state")
   TRC_MSG(L1AUDIO_END_STATE, "Audio function in end state")
   TRC_MSG(L1AUDIO_IDLE_STATE, "Audio function in idle state")

   TRC_MSG(L1AUDIO_READ_BYTE, "Read %d bytes from media buffer")

   TRC_MSG(L1AUDIO_DSP_ERROR, "ERROR! DSP decodes bitstream")
   TRC_MSG(L1AUDIO_MCU_ERROR, "ERROR! MCU parses packet")

   // AUD RTP
   TRC_MSG(RTP_AUD_CONFIG, "RTP_AAC_Config, SR = %d, FrameDur = %d, channel# = %d")
   TRC_MSG(RTP_AUD_MB_UF, "RTP_MB_UF, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_MB_OF, "RTP_MB_OF, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_PKT_LOSS, "RTP_PKT_LOSS, loss = %d, type = %d")
   TRC_MSG(RTP_AUD_DISCAR, "RTP_PKT_DISCAR, p # = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPktToJitter, "PutPktToJitterBuffer, seq number = %d, jitter count = %d, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPktFromJitter, "PutPktFromJitBufWithSilence, seq number = %d, jitter count = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPkt, "PutPktFromJitBufInOrder, seq number = %d, jitter count = %d, type = %d")
   TRC_MSG(RTP_AUD_GetFromJitter, "Jitter Info, seq number = %d, jitter count = %d, pos = %d")
   TRC_MSG(RTP_AUD_PUTPKT_FST, "RTP_PUTPKT_FST, p # = %d")
   TRC_MSG(RTP_AUD_PUTPKT_FUNC, "RTP_PUTPKT_FUNC, packet# = %d, timestamp = %d, size = %d, type = %d")
   TRC_MSG(RTP_AUD_PUT_SIL, "RTP_Put_Silence, packet# = %d, frames = %d, type = %d")
   TRC_MSG(RTP_AUD_Info, "AAC-LATM_bufSize_Error, seq number = %d, Residual Buffer Size = %d, type = %d")
   TRC_MSG(RTP_AUD_PUT_PKT, "RTP_Put_Packet_To_Buf, packet# = %d, timestamp = %d, type = %d")
   TRC_MSG(RTP_AUD_FRM_IN_BUF, "RTP_Frame_In_Buf, frame count = %d, type = %d")
   TRC_MSG(RTP_AUD_FRM_IN_PKT, "RTP_Frame_In_packet, frame count = %d, type = %d")
   TRC_MSG(RTP_AUD_BUF_STATUS, "RTP_Buffer_Status, CurBufDur = %d, BufTotalSize = %d, BufFreeSize = %d, MinBufTotalDur = %d")

   // APM (Audio Post-Processing Manager)
   TRC_MSG(APM_ACTIVATE_INFO, "APM:Activate Task %d, Sampling Frequency %d, Channels %d")
   TRC_MSG(APM_ACTIVATING, "APM:Activating ID %d")
   TRC_MSG(APM_DEACTIVATE_INFO, "APM:Deactivate Task %d")
   TRC_MSG(APM_DEACTIVATING, "APM:Deactivating ID %d")
   TRC_MSG(APM_REGISTER, "APM:Register ID %d, Original tasks %d")
   TRC_MSG(APM_UNREGISTER, "APM:Unregister ID %d, Original tasks %d")
   TRC_MSG(APM_CLEARBUFFER, "APM:Clear Buffer")
   TRC_MSG(APM_EOF, "APM:EOF task %d")
   TRC_MSG(APM_TRUNCATE, "APM:Truncate outTempBuf")
   
   // Audio Post Process
   TRC_MSG(L1AUDIO_PP_SET_3D, "Enter AudioPP_Set3D, set 3D effect cofeeicients")
   TRC_MSG(L1AUDIO_PP_SET_TS, "Enter AudioPP_SetTS, set speed mode %d")
   TRC_MSG(L1AUDIO_PP_3D_STATE, "3D effect is in state %d")
   TRC_MSG(L1AUDIO_PP_3D_WAIT_ADDRESS, "3D effect waits DSP for getting address")
   TRC_MSG(L1AUDIO_PP_3D_GET_ADDRESS, "3D effect gets coefficient address")
   TRC_MSG(L1AUDIO_PP_TS_STATE, "TS is in state %d")

   // L1SP
   TRC_MSG(L1SP_SET_MODE, "L1SP set mode=%d, spk_lev=%d, mic_lev=%d")
   TRC_MSG(L1SP_APPLY_MODE, "L1SP on=%d, mode=%d, spk_lev=%d, mic_lev=%d")
   TRC_MSG(L1SP_SPEECH_ENHANCEMENT, "L1SP turn on speech enhancement, m0=%d, m1=%d, c0=%d, c1=%d")

   // VoRTP
   TRC_MSG(VORTP_ENTER_STARTTONE, "[VoRTP] Enter StartInbandTone; f1=%d, f2=%d, dB=%d, dura=%d")
   TRC_MSG(VORTP_ENTER_STOPTONE, "[VoRTP] Enter StopInbandTone")
   TRC_MSG(VORTP_UL_ENTER_OPEN, "[VoRTP] Enter OpenULChannel")
   TRC_MSG(VORTP_UL_ENTER_CONFIG, "[VoRTP] Enter UL::Config; type=%d, sid=%d")
   TRC_MSG(VORTP_UL_ENTER_SETBUFFER, "[VoRTP] Enter UL::SetBuffer; size=%d")
   TRC_MSG(VORTP_UL_ENTER_START, "[VoRTP] Enter UL::Start; sid=%d, ts=%d")
   TRC_MSG(VORTP_UL_ENTER_STOP, "[VoRTP] Enter UL::Stop; sid=%d")
   TRC_MSG(VORTP_UL_ENTER_CLOSE, "[VoRTP] Enter UL::Close")
   TRC_MSG(VORTP_UL_ENTER_SETMIX, "[VoRTP] Enter UL::SetMix; val=%d")
   TRC_MSG(VORTP_DL_ENTER_OPEN, "[VoRTP] Enter OpenDLChannel")
   TRC_MSG(VORTP_DL_ENTER_CONFIG, "[VoRTP] Enter DL::Config; type=%d, sid=%d")
   TRC_MSG(VORTP_DL_ENTER_SETBUFFER, "[VoRTP] Enter DL::SetBuffer; size=%d")
   TRC_MSG(VORTP_DL_ENTER_START, "[VoRTP] Enter DL::Start; sid=%d")
   TRC_MSG(VORTP_DL_ENTER_STOP, "[VoRTP] Enter DL::Stop; sid=%d")
   TRC_MSG(VORTP_DL_ENTER_CLOSE, "[VoRTP] Enter DL::Close")
   TRC_MSG(VORTP_JITTER_INFO, "[VoRTP] DL-Jitter; sid=%d, depth=%d, curJit=%d, old_ts=%d, new_ts=%d")
   TRC_MSG(VORTP_JITTER_OVERRUN, "[VoRTP] DL-Jitter; sid=%d, overrun=%d")
   TRC_MSG(VORTP_JITTER_PREBUF, "[VoRTP] DL-Jitter; sid=%d, prebuf=%d, fn=%d")
   TRC_MSG(VORTP_DL_ARRIVAL, "[VoRTP] DL-Arrival; sid=%d, seq=%d, ts=%d, type=%d, payload_sz=%d, pt=%d, m=%d")
   TRC_MSG(VORTP_DL_PLAY, "[VoRTP] DL-Play; sid=%d, seq=%d, ts=%d, type=%d, payload_sz=%d, pt=%d, m=%d")
   TRC_MSG(VORTP_UL_BORN, "[VoRTP] UL-Born; sid=%d, ts=%d, type=%d, payload_sz=%d, m=%d")
   TRC_MSG(VORTP_UL_SENT, "[VoRTP] UL-Sent; sid=%d, ts=%d, type=%d, payload_sz=%d, m=%d")
   TRC_MSG(VORTP_DL_INFO1, "[VoRTP] DL-Info; sid%d, arriv=%d, play=%d, miss=%d")
   TRC_MSG(VORTP_JITTER_BURST, "[VoRTP] DL-Burst; sid%d, curJit=%d, prevMaxJit=%d, latestBurstJit=%d")
   TRC_MSG(VORTP_JITTER_BURST_STATE, "[VoRTP] DL-Burst; sid=%d, isBurstState=%d")

   // DAF stream sender over RTP
   TRC_MSG(ENTER_A2DP_DAF_OPEN, "Enter A2DP_DAF_Open")
   TRC_MSG(ENTER_A2DP_DAF_CLOSE, "Enter A2DP_DAF_Close")
   TRC_MSG(DAFRTP_PUTDATA, "DAFRTP PutData, putlen=%d, elapsed: %d, wait: %d")
   TRC_MSG(DAFRTP_GETDATA, "DAFRTP GetData, buflen=%d, getlen: %d, elapsed: %d, sample: %d, header: %d")
   TRC_MSG(DAFRTP_FRAMESYNC, "DAFRTP FrameSync, skip=%d, framelen: %d, bitrate: %d")

// Audio Cache
   TRC_MSG(L1AUDIO_SET_CACHE_TBL, "Set Cache Table, type = %d")
   TRC_MSG(L1AUDIO_BUILD_CACHE, "Build Cache, type = %d, Ret = %d, Prog = %d")
   TRC_MSG(L1AUDIO_CACHE_STROFFSET, "Cache_Start_Offset, type = %d, idx = %d, offset = %d")
   TRC_MSG(L1AUDIO_CACHE_ACCFRAME, "Cache_Accumulated_Frame, type = %d, idx = %d, frame = %d")
   TRC_MSG(L1AUDIO_CACHE_FINISH_RETURN, "Cache Finished Return, type = %d")
   TRC_MSG(L1AUDIO_CACHE_END, "Cache End, type = %d, total frame = %d")
   TRC_MSG(L1AUDIO_CACHE_FAILED, "Cache Fail, type = %d, total frame = %d")
   TRC_MSG(L1AUDIO_SEEK_RESULT, " Seek Result, type=%d, Start Frame=%d, Offset=%d, ST(ms)=%d")
   TRC_MSG(L1AUDIO_SEEK_FAIL, " Seek Fail, type=%d, Start Frame=%d, Offset=%d, ST(ms)=%d")
   TRC_MSG(L1AUDIO_CACHE_GET_DUR, "Cache_Get_Duration, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_GET_DUR_F, "Cache_Get_Duration_F, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_GET_TOTAL_DUR, "Cache_Get_Total_Duration, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_FILE_SIZE, "File Size, type = %d, file size = %d")

END_TRACE_MAP(MOD_L1SP)

#endif // _L1SP_TRC_H
