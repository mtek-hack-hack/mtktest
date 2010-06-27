/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * l1ctm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1Ctm interface  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
  
#ifdef __CTM_SUPPORT__

extern int dsp_tch_bfi;
#include "l1audio_def.h"
#include "dcmgr.h"
#include "pcm4way.h"
#include "ctm_params.h"
#include "ctm_modem.h"
//#include "l1ctm.h"
#include "fat_fs.h"  /* file system */
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "ddload.h"
#include "am.h"

// Catcher trace  
#define L1CTM_TRACE_FUNC(X) kal_trace(TRACE_FUNC, X)
#define L1CTM_TRACE_STATE(X) kal_trace(TRACE_STATE, X)
#define L1CTM_TRACE_INFO(X,Y) kal_trace(TRACE_INFO, X, Y)

int ctm_hco_vco_state = 0;		// 0 - disable; 1 - HCO enable; 2 - VCO enable;

const uint16 zero_dl_pcm[160] = 
{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};  

//#define CTM_COSIM
//#define FAKE_CTM_COSIM      // Mcu run in normal mode while DSP run in cosim mode. This is used to record files for DSP verification.

#if defined(FAKE_CTM_COSIM) || defined(CTM_COSIM)

#define COSIM_GUARD_PERIOD_LEN  1
int32 cosim_guard_period;

extern kal_uint16 idma_load_pm(kal_uint16 page, kal_uint16 address, kal_uint16 len, const kal_uint16 *image);
const int16 ctm_cosim_data[] = 	{226, 24060, -3947, -12978, 9434, 3588, -3845, 20270, 17456, -24664, 793, 22208, -16060, 632, 28906, 4, 0, 0, 0, 0, 
				27189, 26720, 4613, -14396, 344, 10840, 29892, -5943, 4626, 22516, -19838, 28815, -31477, 18263, 10422, 11, 0, 0, 1, 0, 
				8768, 27184, -12691, -20401, -29500, 10824, 9752, 19330, 3063, 29994, 13359, 8205, 1393, 5120, 20688, 11, 0, 1, 1, 0, 
				21049, -22432, 16365, -27652, 24932, -11571, 432, 20643, 6612, 26604, 2817, 15077, 22795, 16756, 27528, 1, 5, 0, 1, -1976, 
				27189, 26720, 4613, -14396, 344, 10840, 29892, -5943, 4626, 22516, -19838, 28815, -31477, 18263, 10422, 11, 0, 0, 1, 1176, 
				7657, 27326, -3131, -20360, -10968, 19297, 568, 18928, 1308, 16653, -20898, -23546, 22528, -16635, -20448, 4, 0, 0, 2, 15976, 
				27189, 26720, 4613, -14396, 344, 10840, 29892, -5943, 4626, 22516, -19838, 28815, -31477, 18263, 10422, 11, 0, 0, 0, 374, 
				8768, 27184, -12691, -20401, -29500, 10824, 9752, 19330, 3063, 29994, 13359, 8205, 1393, 5120, 20688, 11, 0, 0, 0, -848};

#define DP_CTM_COSIM_DUMP               (*(volatile uint16*)(DPRAM_CPU_base+ 0x1E0*2))
#define COSIM_DUMP_DATA_LEN     100
int16 cosim_dump_data[COSIM_DUMP_DATA_LEN];
int32 cosim_dump_index = 0;

#endif

#define MORE_ENQUIRY 8  
static uint32 more_enquiry_times; 

#define DIRECT_MODE_PURE_SPEECH 
// restore pure speech in direct mode when DL_CTM_RECEIVING is not true.
// This operation should be available only in direct mode because in TTY mode
// Baudot signal may be still generating by baudot generator when CTM is end

static int16 cprm_debug_flag = 0;

#if defined(L1CTM_DEBUG_MODE)

//#define CTM_CODEC_EXP
#define BAUDOT_MODE_TEST
//#define DUPLEX_BAUDOT
#define DIRECT_MODE_AUTO_SEND_TEXT_FILE 
#define UL_GET_PCM_FROM_FILE 
#define DL_GET_PCM_FROM_FILE  

#define UL_IN_PCM_RECORD
#define UL_OUT_PCM_RECORD
#define DL_IN_PCM_RECORD
#define DL_OUT_PCM_RECORD

//#define RECORD_DSP_RXBUFFER     // Must sync with l1d_def.h

#define DL_IN_BFI_RECORD

#if defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
   #define SAVE_ONLY_TTY_CHAR
#endif

#ifdef SAVE_ONLY_TTY_CHAR
   #define BURST_START_CHAR   '#'
   #define BURST_END_CHAR     '*'
   static const char TTY_CHAR_TAB[] = "\b\r\n 3-87$4',!:(5\")2=6019\?+./;";
#endif

#if defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
void l1ctm_save_decoded_char(uint8 ch, uint8 special_ch);
#endif

#if defined(UL_IN_PCM_RECORD) || defined(UL_OUT_PCM_RECORD) || defined(DL_IN_PCM_RECORD) || defined(DL_OUT_PCM_RECORD) || defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE) || defined(DL_IN_BFI_RECORD) || defined(CTM_COSIM)
static uint32 ctm_rec_dir_no = 0;
#endif

#ifdef RECORD_DSP_RXBUFFER
/*RecordDSP*/ #define DSP_RECORD_DATA_LEN      (2*80*4)     // Must sync with l1d_def.h
/*RecordDSP*/ //  The following variables are defined in m12100.c

/*RecordDSP*/ #if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238) /*2006-06-18 Jinfa*/
/*RecordDSP*/   #define SAMPLES_RX_BUF			156*4	 //Samples per burst; Wideband & Narrowband ; I/Q
/*RecordDSP*/   #define SAMPLES_NB_RESULT0	18		 //Samples per burst
/*RecordDSP*/ #else
/*RecordDSP*/   #define SAMPLES_RX_BUF			156*2	 //Samples per burst; I/Q
/*RecordDSP*/   #define SAMPLES_NB_RESULT0	8			 //Samples per burst
/*RecordDSP*/ #endif

/*RecordDSP*/ extern uint16 dsp_rec_rx_buf0[2][DSP_RECORD_DATA_LEN][SAMPLES_RX_BUF];
/*RecordDSP*/ extern uint16 dsp_rec_nb_result0[2][DSP_RECORD_DATA_LEN][SAMPLES_NB_RESULT0];

/*RecordDSP*/ extern int32  dsp_rec_fn[2][DSP_RECORD_DATA_LEN];
/*RecordDSP*/ //extern uint16 dsp_rec_eq_so0[2][DSP_RECORD_DATA_LEN][116];

/*RecordDSP*/ extern int16  dsp_rec_idx;
/*RecordDSP*/ extern int16  dsp_rec_buf_idx;

/*RecordDSP*/ static uint8  dsp_rec_rx_buf0_write_ok;
/*RecordDSP*/ static uint8  dsp_rec_nb_result0_write_ok;
/*RecordDSP*/ static uint8  dsp_rec_fn_write_ok;
/*RecordDSP*/ //static uint8  dsp_rec_eq_so0_write_ok;

/*RecordDSP*/ static int32  fh_dsp_rec_rx_buf0;
/*RecordDSP*/ static int32  fh_dsp_rec_nb_result0;
/*RecordDSP*/ static int32  fh_dsp_rec_fn;
/*RecordDSP*/ //static int32  fh_dsp_rec_eq_so0;

#endif // RECORD_DSP_RXBUFFER

void med_integrate_debug_hdlr(kal_uint32 msg, void *msg_info);
typedef void (*media_in_proc_call_type)( kal_uint32 arg1, void* arg2 );
void aud_send_in_proc_call_req( module_type src_mod_id, media_in_proc_call_type func,
	kal_uint32 func_arg1, void* func_arg2 );

#ifdef DIRECT_MODE_AUTO_SEND_TEXT_FILE  
void l1ctm_callback1(L1Ctm_Event event, void *data);
#endif

// Msg_Info Data Struct
typedef struct
{
   int32 read_file_hdl;
   uint8 *read_buf;
   uint16 read_len;
}File_Read_Msg_Info;

typedef struct
{
   int32 write_file_hdl;
   uint8 *write_buf;
   uint32 write_len;        // Change from uint16 to uint32 for writing DSP RX buffer data
}File_Write_Msg_Info;

typedef struct 
{
   int32 read_text_file_hdl;
   uint8 *text_buf_ptr;
   uint32 write_text_len;
   uint32 read_text_len;
}Put_Text_File_Msg_Info;


typedef struct 
{   
   uint8 *dummy_buf_ptr;
   uint32 dummy_buf_size;
}Dummy_Buffer_Msg_Info;

// Msg_Info Debug Message 
#define OPEN_CTM_REQUEST 1
#define CLOSE_CTM_REQUEST 2
#define UL_READ_PCM_FILE_REQUEST 3
#define DL_READ_PCM_FILE_REQUEST 4
#define DL_READ_BFI_FILE_REQUEST 5   
#define UL_IN_WRITE_FILE_REQUEST 6
#define DL_IN_WRITE_FILE_REQUEST 7
#define UL_OUT_WRITE_FILE_REQUEST 8
#define DL_OUT_WRITE_FILE_REQUEST 9   
#define GENERAL_WRITE_FILE_REQUEST 10
#define PUT_TEXT_TO_UL_CTM_BUF_REQUEST 11
#define UL_CTM_BUF_DUMMY_READ_REQUEST 12

#define DSP_REC_RX_BUF0_REQUEST 13
#define DSP_REC_NB_RESULT0_REQUEST 14
#define DSP_REC_FN_REQUEST 15
#define DSP_REC_EQ_SO0_REQUEST 16

#define START_NEGOTIATION_REQUEST 17

static int32 sdCardDrv;
static kal_wchar file_name[30];

static int32 ctmReadDelayCountDown;

#ifdef CTM_CODEC_EXP
#define CTM_CODEC_EXP_CHANGE_TIME 20
static uint8 ctm_codec_state;
static uint16 ctm_codec_exp_cnt;
#endif 


#define UTF8_TEXT_BUF_LEN 100 

#if defined(BAUDOT_MODE_TEST)
static int32 f_ul_tty_text_hdl;
static uint8 Ul_TTY_Text_Buf[2][UTF8_TEXT_BUF_LEN];
static uint8 ul_tty_text_buf_idx;
static uint8 ul_tty_text_buf_write_count;
#endif 

#if defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
static int32 f_ul_ctm_text_hdl;   
static uint8 Ul_CTM_Text_Buf[2*UTF8_TEXT_BUF_LEN]; 
static uint32 ul_ctm_text_buf_read_count;
static uint32 ul_ctm_text_buf_write_count;
static uint16 ul_text_sent;
static uint16 ul_text_received;
static uint8 Dummy_Dl_CTM_Text_Buf[UTF8_TEXT_BUF_LEN];
#endif 

#if defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
static int32 f_dl_ctm_text_hdl;   
static uint8 Dl_CTM_Text_Buf[2][UTF8_TEXT_BUF_LEN]; 
static uint8 dl_ctm_text_buf_idx;
static uint8 dl_ctm_text_buf_write_count;
#endif 

#define PCM_DEBUG_BUFFER_SIZE 64000
//#define PCM_DEBUG_BUFFER_SIZE 16000

// for ulInPcmReadFlag , dlInPcmReadFlag
#define HAS_ANOTHER_BUF_DATA_FLAG 0x1
#define READ_EOF_FLAG 0x2
#define READ_NO_DATA_FLAG 0x4 
// for pcmDebugReadFlag
#define UL_IN_READ_PCM_FLAG 0x1
#define DL_IN_READ_PCM_FLAG 0x2
#define UL_IN_READ_PCM_BUF1 0x10
#define DL_IN_READ_PCM_BUF1 0x20

static uint16 pcmDebugReadFlag;
static uint16 sdCardNotFullFlag; 

#if defined(UL_GET_PCM_FROM_FILE)   
static int32 f_ul_in_pcm_hdl; 
static uint16 *ulInPcmReadBuf[2];  
static uint16 *ulInPcmReadPtr;   
static uint16 ulInPcmReadCount;   
static uint8  ulInPcmReadBufIdx;
static uint16 ulInPcmDataCount;
static uint16 ulInPcmReadBufDataCount[2];
static uint16 ulInPcmReadFlag;

static uint8 ULINPCMREADBUF[2][PCM_DEBUG_BUFFER_SIZE];
#endif 
   
#if defined(DL_GET_PCM_FROM_FILE)
static int32 f_dl_in_pcm_hdl;
static uint16 *dlInPcmReadBuf[2];
static uint16 *dlInPcmReadPtr;   
static uint16 dlInPcmReadCount;   
static uint8  dlInPcmReadBufIdx;
static uint16 dlInPcmDataCount;
static uint16 dlInPcmReadBufDataCount[2];
static uint16 dlInPcmReadFlag;

static uint8 DLINPCMREADBUF[2][PCM_DEBUG_BUFFER_SIZE];

#define DL_IN_BFI_READ_BUFFER_SIZE 1024
static int32 f_dl_in_bfi_hdl;
static uint8 dlInBfiReadBuf[2][DL_IN_BFI_READ_BUFFER_SIZE];
static uint16 dlInBfiReadCount;
static uint8 dlInBfiReadBufIdx;
static uint16 dlInBfiDataCount;
static uint16 dlInBfiReadBufDataCount[2];
static uint16 dlInBfiReadFlag;   
#endif 
   
#if defined(UL_IN_PCM_RECORD) 
static int32 f_ul_in_pcm_rec_hdl;
static uint16 *ulInPcmWriteBuf[2];
static uint16 *ulInPcmWritePtr;
static uint16 ulInPcmWriteCount; 
static uint8  ulInPcmWriteBufIdx;       
static uint8  ulInPcmWriteFlag;

static uint8 ULINPCMWRITEBUF[2][PCM_DEBUG_BUFFER_SIZE];

#endif
   
#if defined(UL_OUT_PCM_RECORD)  
static int32 f_ul_out_pcm_rec_hdl;
static uint16 *ulOutPcmWriteBuf[2];
static uint16 *ulOutPcmWritePtr;
static uint16 ulOutPcmWriteCount; 
static uint8  ulOutPcmWriteBufIdx;      
static uint8  ulOutPcmWriteFlag;

static uint8 ULOUTPCMWRITEBUF[2][PCM_DEBUG_BUFFER_SIZE];

#endif 
   
#if defined(DL_IN_PCM_RECORD)    
static int32 f_dl_in_pcm_rec_hdl;
static uint16 *dlInPcmWriteBuf[2];
static uint16 *dlInPcmWritePtr;
static uint16 dlInPcmWriteCount; 
static uint8  dlInPcmWriteBufIdx;       
static uint8  dlInPcmWriteFlag;

static uint8 DLINPCMWRITEBUF[2][PCM_DEBUG_BUFFER_SIZE];
        
#define VM_DATA_BUFFER_SIZE 4000
static int32 f_vm_rec_hdl;
static uint16 vmDataBuf[2][VM_DATA_BUFFER_SIZE]; 
static uint16 vmDataBufIdx;
static uint16 *vmDataPtr, *vmDataStartPtr, *vmDataEndPtr; // this is because vm data count is not fixed 
static uint16 vmRecDataCnt;    
static uint16 *vmRecDataPtr; 
#endif 

#ifdef DL_IN_BFI_RECORD
#define DL_IN_BFI_WRITE_BUFFER_SIZE 1024
static int32 f_dl_in_bfi_rec_hdl; 
static uint8 dlInBfiWriteBuf[2][DL_IN_BFI_WRITE_BUFFER_SIZE];
static uint8 dlInBfiWriteBufIdx;
static uint16 dlInBfiWriteCount;
#endif

#if defined(DL_OUT_PCM_RECORD)     
static int32 f_dl_out_pcm_rec_hdl;
static uint16 *dlOutPcmWriteBuf[2];
static uint16 *dlOutPcmWritePtr;
static uint16 dlOutPcmWriteCount;       
static uint8  dlOutPcmWriteFlag;
static uint8  dlOutPcmWriteBufIdx;     

static uint8 DLOUTPCMWRITEBUF[2][PCM_DEBUG_BUFFER_SIZE];

#endif 

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238) /*2006-06-18 Jinfa*/
#define  Check_Setting_by_Catcher_Trace()	\
	{  kal_prompt_trace(MOD_L1SP, "[CTM Setting 6229] AEC, EES, ES (Address 0x1A0~0x1A2): %d,%d,%d",  *(uint16*)(DPRAM2_CPU_base+0x1A0*2), *(uint16*)(DPRAM2_CPU_base+0x1A1*2), *(uint16*)(DPRAM2_CPU_base+0x1A2*2)  );\
	   kal_prompt_trace(MOD_L1SP, "[CTM Setting 6229] AMR codebook threshold=%d, gain=%d",    *(uint16*)(DPRAM2_CPU_base+0x19D*2),*(uint16*)(DPRAM2_CPU_base+0x19E*2) );\
      kal_prompt_trace(MOD_L1SP, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 0: %d,%d", *(uint16*)(DPRAM2_CPU_base+0x6A*2), *(uint16*)(DPRAM2_CPU_base+0x6E*2)  );\
      kal_prompt_trace(MOD_L1SP, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 1: %d,%d", *(uint16*)(DPRAM2_CPU_base+0x6B*2), *(uint16*)(DPRAM2_CPU_base+0x6F*2)  );\
      kal_prompt_trace(MOD_L1SP, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 2: %d,%d", *(uint16*)(DPRAM2_CPU_base+0x6C*2), *(uint16*)(DPRAM2_CPU_base+0x70*2)  );\
      kal_prompt_trace(MOD_L1SP, "[CTM Setting 6229] DSP_AFS/AHS_SP_BFI_THRESHOLD 3: %d,%d", *(uint16*)(DPRAM2_CPU_base+0x6D*2), *(uint16*)(DPRAM2_CPU_base+0x71*2)  );\
      kal_prompt_trace(MOD_L1SP, "[CTM Setting]: Audio Coefficient for input : %d, %d, %d, %d", *(int16*)DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR), *(int16*)DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR+1), *(int16*)DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR+2), *(int16*)DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR+3) );\
      kal_prompt_trace(MOD_L1SP, "[CTM Setting]: Audio Coefficient for output: %d, %d, %d, %d", *(int16*)DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR), *(int16*)DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR+1), *(int16*)DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR+2), *(int16*)DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR+3));\
	}
#endif

#endif // L1CTM_DEBUG_MODE

int CtmReadFileDelay = 30;
  
#define UL_TTY_BUF_LEN 64 
#define UL_CTM_BUF_LEN 256
#define DL_TTY_BUF_LEN 1024 
#define DL_CTM_BUF_LEN 256 

#define PCM_FIFO_LEN 2   // could be 1 ~ N   

typedef struct{
   void (*callback_handler)(L1Ctm_Event event, void *data);
   // speech-channel PCM  buffer
   uint16 ul_pcm_fifo[PCM_FIFO_LEN][160];         
   uint16 dl_pcm_fifo[PCM_FIFO_LEN][160];             
#if defined( DIRECT_MODE_PURE_SPEECH )
   uint16 dl_pcm_original[160];
#endif
   // text buffer 
   uint8 ul_tty_buf[UL_TTY_BUF_LEN];
   uint8 ul_ctm_buf[UL_CTM_BUF_LEN];
   uint8 dl_tty_buf[DL_TTY_BUF_LEN];
   uint8 dl_ctm_buf[DL_CTM_BUF_LEN];
   // buffer read write pointer      
   uint16 ul_tty_buf_read;  // buf_read == buf_write , means buffer empty 
   uint16 ul_tty_buf_write; // buffer could be filled at most (BUF_LEN - 1) data 
   uint16 ul_ctm_buf_read;
   uint16 ul_ctm_buf_write;
   uint16 dl_tty_buf_read;
   uint16 dl_tty_buf_write;
   uint16 dl_ctm_buf_read;
   uint16 dl_ctm_buf_write;   
   // control relative
   uint16 next_to_process; 
   uint16 pcm_fifo_write;
   uint16 pcm_fifo_read; 
   uint16 aud_id;
   uint16 FLAGS;
   uint16 ul_mute_flags;
   uint16 dl_mute_flags;
   uint8 bfi_info[PCM_FIFO_LEN];
   uint8 l1d_bfi_info[PCM_FIFO_LEN];
   uint8 interface;
   uint8 state;   
   uint8 next_ack_timeout; 
   int8 enquiry_count;
   uint8 enquiry_timeout1;
   uint8 enquiry_timeout2;
   uint8 transition_mute;
}L1Ctm_Module; 

static L1Ctm_Module *l1ctm;
//extern UNSIGNED TMD_System_Clock;

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

//***** UTF8 special character 
#define ENQUIRY_CHAR 0x5
#define IDLE_CHAR 0x16 
#define NON_UTF8_CHAR 0xFF 
#define NO_CHAR 0xFF

//***** LCF : L1CTM Control Flag 
// CTM Negotiation relative 
#define LCF_NEGOTIATION_REQ   0x1
#define LCF_NEGOTIATION       0x2
#define LCF_SEND_ENQUIRY      0x4
#define LCF_SEND_ACK          0x8
#define LCF_FAR_END_DETECTED  0x10
// speech-channel output relative
#define LCF_UL_CTM_TRANSMITTING  0x20
#define LCF_UL_MUTE           0x40  
#define LCF_DL_CTM_RECEIVING  0x80
#define LCF_DL_BAUDOT_TRANSMITTING  0x100 
#define LCF_DL_MUTE  0x200
#define LCF_ACKING   0x400
#define LCF_DL_ACKING 0x800

//***** time-out setting 
#define ENQUIRY_TIMEOUT1 21 // 20 (400 ms) + 1 
#define ENQUIRY_TIMEOUT2 67 // 66 (1320 ms) + 1  
#define NEXT_ACK_TIMEOUT 26 // 25 (500 ms) + 1 
#define DL_TRANSITION_MUTE_TIMEOUT  2 // 40 ms 

//***** L1CTM state 
#define L1CTM_READY_STATE 0xAB 
#define L1CTM_CONNECTED_STATE 0xCD
 
//***** text buffer operation used in l1ctm_in_task

#define  UL_TTY_BUF_CHAR_READY() (l1ctm->ul_tty_buf_read != l1ctm->ul_tty_buf_write)

#define  UL_TTY_BUF_GET_CHAR(tty_code)    {  \
            tty_code = l1ctm->ul_tty_buf[l1ctm->ul_tty_buf_read ++];  \
            l1ctm->ul_tty_buf_read &= (UL_TTY_BUF_LEN-1);                \
         }

#define UL_TTY_BUF_PUT_CHAR(tty_code) \
        { \
          l1ctm->ul_tty_buf[l1ctm->ul_tty_buf_write ++] = tty_code; \
          l1ctm->ul_tty_buf_write &= (UL_TTY_BUF_LEN-1);                  \
          if(l1ctm->ul_tty_buf_write == l1ctm->ul_tty_buf_read)       \
            {                                                           \
               l1ctm->ul_tty_buf_read ++;                               \
               l1ctm->ul_tty_buf_read &= (UL_TTY_BUF_LEN-1);                \
            }                                                           \
        }   
         
                      
#define  DL_TTY_BUF_CHAR_READY() (l1ctm->dl_tty_buf_read != l1ctm->dl_tty_buf_write)

#define  DL_TTY_BUF_GET_CHAR(tty_code)    {  \
            tty_code = l1ctm->dl_tty_buf[l1ctm->dl_tty_buf_read++];  \
            l1ctm->dl_tty_buf_read &= (DL_TTY_BUF_LEN-1);                \
         }

#define DL_TTY_BUF_PUT_CHAR(tty_code) \
        { \
          l1ctm->dl_tty_buf[l1ctm->dl_tty_buf_write ++] = tty_code; \
          l1ctm->dl_tty_buf_write &= (DL_TTY_BUF_LEN-1);                  \
          if(l1ctm->dl_tty_buf_write == l1ctm->dl_tty_buf_read)       \
            {                                                           \
               l1ctm->dl_tty_buf_read ++;                               \
               l1ctm->dl_tty_buf_read &= (DL_TTY_BUF_LEN-1);                \
            }                                                           \
        }   


#define  UL_CTM_BUF_CHAR_READY() (l1ctm->ul_ctm_buf_read != l1ctm->ul_ctm_buf_write)

#define  UL_CTM_BUF_GET_CHAR(ctm_code)    {  \
            ctm_code = l1ctm->ul_ctm_buf[l1ctm->ul_ctm_buf_read++];  \
            l1ctm->ul_ctm_buf_read &= (UL_CTM_BUF_LEN - 1);                \
         }  


#define  DL_CTM_BUF_PUT_CHAR(ctm_code)    {  \
            l1ctm->dl_ctm_buf[l1ctm->dl_ctm_buf_write++] = ctm_code;  \
            l1ctm->dl_ctm_buf_write &= (DL_CTM_BUF_LEN - 1);                \
            ASSERT(l1ctm->dl_ctm_buf_write != l1ctm->dl_ctm_buf_read);\
         } 
 
/*==============================================================================*/
void l1ctm_init(void)
{
   l1ctm = (L1Ctm_Module*) 0;   
}  

#define VM_CTRL_SC_START   2
#define VM_CTRL_SD_START   6
#define VM_CTRL_UL         1
#define VM_CTRL_DL         2
extern int32 L1T_GetFN( void );
static uint8 pcm_ex_vm_counter;

void vmRecordService(uint16 **vmPtr)  
{
   volatile uint16   *addr;
   uint16   vm_control, I, sc_mode, sd_mode, sc_len, sd_len; 
   uint32 J; 
   uint16 *destPtr; 
   
   destPtr = *vmPtr;

   //kal_prompt_trace(MOD_L1SPHISR, "ptr%d cnt%d", destPtr, pcm_ex_vm_counter);
    
   I        = *DP_SC_MODE;
   sc_mode  = (I >> 8) & 0x0F;
   sd_mode  = I & 0x0F;

   if( sc_mode>2 && sc_mode<11 )
   {
   	I = *DP_RX_TCH_S(0,17) >> 8;
	   sd_mode = I & 0x1F;
   	I = *DP_TX_TCH_S(0,17) >> 8;
	   sc_mode = I & 0x1F;
   }
   sc_len = AM_GetSpeechPatternLength(sc_mode);
   sd_len = AM_GetSpeechPatternLength(sd_mode);
   if( sc_mode <= 2 ) 
   {
      vm_control =((*DP_RX_TCH_S(0,0) & 0x3E) << 10) |
                  ((*DP_TX_TCH_S(0,0) & 2)<< 9 ) |
                  (sd_mode << VM_CTRL_SD_START) |
                  (sc_mode << VM_CTRL_SC_START) |
                  0x3; 
    }
   else 
   {
      I = *DP_RX_TCH_S(0,0) >> 1;
      I = ((I & 0x10)>>1) | (I & 0x07);
      vm_control =(I << 12) |
                  ((*DP_TX_TCH_S(0,0) & 3)<< 10 ) |
                  (sd_mode << VM_CTRL_SD_START) |
                  (sc_mode << VM_CTRL_SC_START) |
                  0x3; 
   }

   // record syn_word for VM_LOG_DEBUG 
                
   *destPtr++ = 0xAA55;
   J = L1T_GetFN();
   I = (uint16)(J & 0xFFFF);
   *destPtr++ = I ;
   I = (uint16)((J >> 16) + ((uint32)pcm_ex_vm_counter << 8));
   *destPtr++ = I ;
   pcm_ex_vm_counter++;
   
   // record vm control value 
   *destPtr++ = vm_control;
   
   // record UL data 
   if( vm_control & VM_CTRL_UL ) 
   {
      addr = DP_TX_TCH_S( 0, 1 );
      for( I = 0; I < sc_len; I++ )
         *destPtr++ =  *addr++;
   }
   
   // record DL data 
   if( vm_control & VM_CTRL_DL ) 
   {
      addr = DP_RX_TCH_S( 0, 1 );
      for( I = 0; I < sd_len; I++ )
         *destPtr++ = *addr++;

     	if( sd_mode>2 && sd_mode<11 )
     	{
     		addr = DP_RX_TCH_S( 0, 17);
         *destPtr++ = *addr;	// Rx
     		addr = DP_TX_TCH_S( 0, 17);
         *destPtr++ = *addr;	// Tx         
      #if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
         addr = (volatile uint16 *)DP_SP_VM_CTRL_base(0x24);
      #else
         addr = (volatile uint16 *)DP_SP_VM_CTRL_base(0x1b7);
      #endif
         for( I = 0; I <42; I++ )
            *destPtr++ = *addr++;
     	}
   } 
   
   *vmPtr = destPtr;  
}


#define PCM_BFI_SHIFT 1 
void l1ctm_in_hisr()
{
#ifndef CTM_COSIM

   uint16 buf_idx, bfi_data, bfi_rec, bfi_store_idx;   
   
#ifdef FAKE_CTM_COSIM
   if (CtmReadFileDelay == 20)
   {
      if (cosim_guard_period > 0)
      {
         cosim_guard_period--;
         if (cosim_guard_period == 0)
         {
            kal_prompt_trace(MOD_L1SP, "Turning on COSIM bit in DP_CTM_COSIM_CTRL");
            bfi_data = DP_CTM_COSIM_CTRL;
            DP_CTM_COSIM_CTRL = bfi_data | 0x8000;
         }
      }
   }
#endif
   
   buf_idx = l1ctm->pcm_fifo_read;
   if(buf_idx >= PCM_FIFO_LEN) 
      buf_idx -= PCM_FIFO_LEN;
   
   bfi_store_idx = buf_idx + PCM_BFI_SHIFT;
   if(bfi_store_idx >= PCM_FIFO_LEN)
      bfi_store_idx -= PCM_FIFO_LEN;
      
   // check pcm fifo status   
   ASSERT(l1ctm->pcm_fifo_read != l1ctm->next_to_process);      
   
   // uplink-path                                       
   if(l1ctm->ul_mute_flags & (1 << l1ctm->pcm_fifo_read))
      PCM4WAY_FillSE(0);
   else                
      PCM4WAY_PutToSE((const uint16*)(l1ctm->ul_pcm_fifo[buf_idx]));

   // cha-cha noise debug
//   for (I = 0; I < 160; ++I)
//       ASSERT(l1ctm->ul_pcm_fifo[buf_idx][I] == 0);
   // end cha-cha noise debug
      
#if defined(UL_GET_PCM_FROM_FILE)
   if(f_ul_in_pcm_hdl > 0)
   {
      uint16 *ptr;
      ptr = l1ctm->ul_pcm_fifo[buf_idx];
   
      if(!(ulInPcmReadFlag & READ_NO_DATA_FLAG))
      {   
         if(ulInPcmReadCount >= ulInPcmDataCount)
         {
            if(ulInPcmReadFlag & HAS_ANOTHER_BUF_DATA_FLAG)
            {
               if(!(ulInPcmReadFlag & READ_EOF_FLAG))
               {            
                  pcmDebugReadFlag |= UL_IN_READ_PCM_FLAG;
                  if(ulInPcmReadBufIdx)
                     pcmDebugReadFlag |= UL_IN_READ_PCM_BUF1;
                  else 
                     pcmDebugReadFlag &= ~UL_IN_READ_PCM_BUF1; 
               }      
                  
               ulInPcmReadBufIdx^= 0x1;                
               ulInPcmReadCount = 0;       
               ulInPcmReadPtr = ulInPcmReadBuf[ulInPcmReadBufIdx];        
               ulInPcmDataCount = ulInPcmReadBufDataCount[ulInPcmReadBufIdx]; 
               ulInPcmReadFlag &= ~HAS_ANOTHER_BUF_DATA_FLAG;                       
            }
            else
            {
               if(ulInPcmReadFlag & READ_EOF_FLAG)
                  ulInPcmReadFlag |= READ_NO_DATA_FLAG;
               else 
                  ASSERT(false);                                    
            }
         }                                                                                       
      }  
            
      if(ulInPcmReadFlag & READ_NO_DATA_FLAG )
      {
         uint32 I;
         for(I = 160; I > 0 ; I --)
            *ptr++ = 0;
      }
      else 
      {
         uint32 I;                       
         for(I = 160; I > 0 ; I --)
            *ptr++ = *ulInPcmReadPtr++;
                        
         ulInPcmReadCount += 320;                                           
      } 
   }      
   else       
#endif
   PCM4WAY_GetFromMic((uint16*)(l1ctm->ul_pcm_fifo[buf_idx]));   

   // cha-cha noise debug
//   for (I = 0; I < 160; ++I)
//       ASSERT(l1ctm->ul_pcm_fifo[buf_idx][I] == 0);
   // end cha-cha noise debug
    
   // downlink-path                
   if(l1ctm->dl_mute_flags & (1 << l1ctm->pcm_fifo_read))
      PCM4WAY_FillSpk(0);
   else 
      PCM4WAY_PutToSpk((const uint16*)(l1ctm->dl_pcm_fifo[buf_idx]));

   // cha-cha noise debug
//   for (I = 0; I < 160; ++I)
//       ASSERT((l1ctm->dl_pcm_fifo[buf_idx][I] == I + 1) || (l1ctm->dl_pcm_fifo[buf_idx][I] == 0));
       //ASSERT(l1ctm->dl_pcm_fifo[buf_idx][I] == 0);
   // end cha-cha noise debug

#if defined(DL_GET_PCM_FROM_FILE)
   if(f_dl_in_pcm_hdl > 0)
   {
      uint16 *ptr;
      ptr = l1ctm->dl_pcm_fifo[buf_idx];
   
      if(!(dlInPcmReadFlag & READ_NO_DATA_FLAG))
      {   
         if(dlInPcmReadCount >= dlInPcmDataCount)
         {
            if(dlInPcmReadFlag & HAS_ANOTHER_BUF_DATA_FLAG)
            {
               if(!(dlInPcmReadFlag & READ_EOF_FLAG))
               {            
                  pcmDebugReadFlag |= DL_IN_READ_PCM_FLAG;
                  if(dlInPcmReadBufIdx)
                     pcmDebugReadFlag |= DL_IN_READ_PCM_BUF1;
                  else 
                     pcmDebugReadFlag &= ~DL_IN_READ_PCM_BUF1; 
               }      
                  
               dlInPcmReadBufIdx^= 0x1;                
               dlInPcmReadCount = 0;       
               dlInPcmReadPtr = dlInPcmReadBuf[dlInPcmReadBufIdx];        
               dlInPcmDataCount = dlInPcmReadBufDataCount[dlInPcmReadBufIdx]; 
               dlInPcmReadFlag &= ~HAS_ANOTHER_BUF_DATA_FLAG;                       
            }
            else 
            {
               if(dlInPcmReadFlag & READ_EOF_FLAG)
                  dlInPcmReadFlag |= READ_NO_DATA_FLAG;    
               else 
                  ASSERT(false);                                    
            }
         }                                                                                       
      }  
            
      if(dlInPcmReadFlag & READ_NO_DATA_FLAG )
      {
         uint32 I;
         for(I = 160; I > 0 ; I --)
            *ptr++ = 0;
      }
      else 
      {
         uint32 I;                       
         for(I = 160; I > 0 ; I --)
            *ptr++ = *dlInPcmReadPtr++;
                        
         dlInPcmReadCount += 320;                                           
      } 
   }
   else       
#endif    
   PCM4WAY_GetFromSD((uint16*)(l1ctm->dl_pcm_fifo[buf_idx]));  
   
   // cha-cha noise debug
//   dl_mute_debug_temp = 0;
//   for (I = 0; I < 160; ++I)
//      if (l1ctm->dl_pcm_fifo[buf_idx][I] != 0)
//         dl_mute_debug_temp = 1;
         
//   if (dl_mute_debug_temp != 0)
//      kal_prompt_trace(MOD_L1SP, "PCM4WAY_GetFromSD is not all 0.");
//   else
//      kal_prompt_trace(MOD_L1SP, "PCM4WAY_GetFromSD is all 0.");
      
//       ASSERT(l1ctm->dl_pcm_fifo[buf_idx][I] == 0);
   // end cha-cha noise debug

#if defined(DL_IN_PCM_RECORD)
   if (cprm_debug_flag & CPRM_MASK_REC_DL_PCM_IN)
   {
       if(vmDataPtr > vmDataEndPtr - 200)
       {
          vmRecDataCnt = vmDataPtr - vmDataStartPtr; 
          vmRecDataPtr = vmDataStartPtr;       
          vmDataBufIdx ^= 0x1;
          vmDataStartPtr = vmDataBuf[vmDataBufIdx];
          vmDataEndPtr = vmDataStartPtr + VM_DATA_BUFFER_SIZE;
          vmDataPtr = vmDataStartPtr;         
       }   
       vmRecordService(&vmDataPtr);
   }
#endif    
   
   bfi_data = DP_BFI_FACCH_REPORT;

   bfi_rec = (bfi_data&0x1)|(((bfi_data&0x10)>>4)<<1)|(((bfi_data&0x100)>>8)<<2)|(((bfi_data&0x1000)>>12)<<3)|(((bfi_data&0x4000)>>14)<<4);

   //kal_prompt_trace(MOD_L1SPHISR, "DP_BFI_FACCH_REPORT %x", bfi_rec);
   
   l1ctm->bfi_info[buf_idx] = bfi_rec;
   
   if(dsp_tch_bfi > 0)
      l1ctm->l1d_bfi_info[bfi_store_idx] = 1;
   else
      l1ctm->l1d_bfi_info[bfi_store_idx] = 0;     

   //kal_prompt_trace(MOD_L1SP, "case5, buf_idx=%x, bfi_store_idx=%x, bfi_rec=%x, dsp_tch_bfi=%x", buf_idx, bfi_store_idx, bfi_rec, dsp_tch_bfi);

   l1ctm->pcm_fifo_write++;
   if(l1ctm->pcm_fifo_write == 2 * PCM_FIFO_LEN)
      l1ctm->pcm_fifo_write = 0;
   l1ctm->pcm_fifo_read++; 
   if(l1ctm->pcm_fifo_read == 2 * PCM_FIFO_LEN)
      l1ctm->pcm_fifo_read = 0;
                        
   L1Audio_SetEvent(l1ctm->aud_id, (void*)0); // involve L1Audio task to run CTM modem   
#else // CTM_COSIM
   uint16 buf_idx, bfi_store_idx, bfi_data;
   uint32 i;
   
   if (cosim_guard_period > 0)
   {
      cosim_guard_period--;
      if (cosim_guard_period == 0)
      {
         kal_prompt_trace(MOD_L1SP, "Turning on COSIM bit in DP_CTM_COSIM_CTRL");
         bfi_data = DP_CTM_COSIM_CTRL;
         DP_CTM_COSIM_CTRL = bfi_data | 0x8000;
      }
   }
   if (cosim_dump_index < COSIM_DUMP_DATA_LEN)
   {
      cosim_dump_data[cosim_dump_index] = DP_CTM_COSIM_DUMP;
      cosim_dump_index++;
   }

   buf_idx = l1ctm->pcm_fifo_read;
   if(buf_idx >= PCM_FIFO_LEN) 
      buf_idx -= PCM_FIFO_LEN;
   
   bfi_store_idx = buf_idx + PCM_BFI_SHIFT;
   if(bfi_store_idx >= PCM_FIFO_LEN)
      bfi_store_idx -= PCM_FIFO_LEN;

   if(dsp_tch_bfi > 0)
      l1ctm->l1d_bfi_info[bfi_store_idx] = 1;
   else
      l1ctm->l1d_bfi_info[bfi_store_idx] = 0;     

   PCM4WAY_GetFromMic((uint16*)(l1ctm->ul_pcm_fifo[buf_idx]));   
   PCM4WAY_PutToSE((const uint16*)(l1ctm->ul_pcm_fifo[buf_idx]));

   PCM4WAY_GetFromSD((uint16*)(l1ctm->dl_pcm_fifo[buf_idx]));  
   
   if (l1ctm->l1d_bfi_info[buf_idx] == 1)
      for (i = 0; i < 160; i++)
         l1ctm->dl_pcm_fifo[buf_idx][i] >>= 2;
   
   PCM4WAY_PutToSpk((const uint16*)(l1ctm->dl_pcm_fifo[buf_idx]));
   
   kal_prompt_trace(MOD_L1SP, "l1ctm_in_hisr in cosim mode(buf_idx=%x, bfi_store_idx=%x, dsp_tch_bfi=%x, bfi flag=%x)", buf_idx, bfi_store_idx, dsp_tch_bfi, l1ctm->l1d_bfi_info[buf_idx]);

   l1ctm->pcm_fifo_read++; 
   if(l1ctm->pcm_fifo_read == 2 * PCM_FIFO_LEN)
      l1ctm->pcm_fifo_read = 0;
  
#endif // CTM_COSIM
}

void l1ctm_in_task(void *data)
{  
   uint16 l1ctmFlags, ctmFlags, interface, buf_idx; 
   uint8 utf8_code;        
   kal_bool bfi_flag;   
#if defined(L1CTM_DEBUG_MODE)   
   File_Write_Msg_Info *write_msg_info;
   File_Read_Msg_Info *read_msg_info;
#endif 
   
   if(l1ctm == (L1Ctm_Module*) 0)
      return;
      
   while(l1ctm->next_to_process != l1ctm->pcm_fifo_write)
   {  
      buf_idx = l1ctm->next_to_process;
      if(buf_idx >= PCM_FIFO_LEN)
         buf_idx -= PCM_FIFO_LEN;
         
      #ifdef DL_GET_PCM_FROM_FILE
      bfi_flag = 0;
      if(f_dl_in_bfi_hdl > 0)
      {         
//            kal_prompt_trace(MOD_L1SP, "case7, dlInBfiReadFlag=%x, dlInBfiReadCount=%x, dlInBfiDataCount=%x, dlInBfiReadBufIdx=%x",
//                             dlInBfiReadFlag, dlInBfiReadCount, dlInBfiDataCount, dlInBfiReadBufIdx);

         if(!(dlInBfiReadFlag & READ_NO_DATA_FLAG))
         {   
            if(dlInBfiReadCount == dlInBfiDataCount)
            {
               if(dlInBfiReadFlag & HAS_ANOTHER_BUF_DATA_FLAG)
               {
                  if(!(dlInBfiReadFlag & READ_EOF_FLAG))
                  {                                                                                                            
                     read_msg_info = (File_Read_Msg_Info *) get_ctrl_buffer(sizeof(File_Read_Msg_Info));
         
                     read_msg_info->read_file_hdl = f_dl_in_bfi_hdl;
                     read_msg_info->read_buf = (uint8 *)dlInBfiReadBuf[dlInBfiReadBufIdx];
                     read_msg_info->read_len = DL_IN_BFI_READ_BUFFER_SIZE;  
                     aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DL_READ_BFI_FILE_REQUEST, (void*)read_msg_info);                      
                     
                     //kal_prompt_trace(MOD_L1SP, "case8, send DL_READ_BFI_FILE_REQUEST msg");
                  }
                  dlInBfiReadBufIdx^= 0x1;                
                  dlInBfiReadCount = 0;                                 
                  dlInBfiDataCount = dlInBfiReadBufDataCount[dlInBfiReadBufIdx]; 
                  dlInBfiReadFlag &= ~HAS_ANOTHER_BUF_DATA_FLAG;                       
               }
               else 
               {
                  if(dlInBfiReadFlag & READ_EOF_FLAG)
                     dlInBfiReadFlag |= READ_NO_DATA_FLAG;    
                  else 
                     ASSERT(false);                                    
               }
            }                                                                                       
         }  

         if(!(dlInBfiReadFlag & READ_NO_DATA_FLAG))
         {
            uint8 bfi_data;      
            bfi_data = dlInBfiReadBuf[dlInBfiReadBufIdx][dlInBfiReadCount];
            bfi_flag = (kal_bool)((bfi_data & 0x20) != 0);
            //kal_prompt_trace(MOD_L1SP, "case1, bfi_data=%x, bfi_flag=%x", bfi_data, bfi_flag);
            dlInBfiReadCount++; 
         }                     
      }
      else if(f_dl_in_pcm_hdl < 0)
      {
         bfi_flag = (kal_bool)(l1ctm->l1d_bfi_info[buf_idx]);    
         //kal_prompt_trace(MOD_L1SP, "case2, bfi_flag=%x", bfi_flag);
      }
      #else 
      bfi_flag = (kal_bool)(l1ctm->l1d_bfi_info[buf_idx]);    
      //kal_prompt_trace(MOD_L1SP, "case3, bfi_flag=%x", bfi_flag);
      #endif 
          
      #ifdef CTM_CODEC_EXP
      if(ctm_codec_state == 2)
      {
         if((DP_CTM_CODEC_CTRL & 0xF) == 0x0)           
            ctm_codec_state = 0;               
      }
      else 
      {
         ctm_codec_exp_cnt++;
         if(ctm_codec_exp_cnt >= CTM_CODEC_EXP_CHANGE_TIME)
         {
            ctm_codec_exp_cnt = 0;
            if(ctm_codec_state == 0)
            {
               ctm_codec_state = 1;
               DP_CTM_CODEC_CTRL = (DP_CTM_CODEC_CTRL & 0xFFF0) | 0x1; 
            
            }
            else if(ctm_codec_state == 1)
            {
               ctm_codec_state = 2;
               DP_CTM_CODEC_CTRL = (DP_CTM_CODEC_CTRL & 0xFFF0) | 0x2;            
            }
         
         }  
      }      
      #endif 
      
      #ifdef UL_IN_PCM_RECORD     
      if((cprm_debug_flag & CPRM_MASK_REC_UL_PCM_IN) && sdCardNotFullFlag && f_ul_in_pcm_rec_hdl > 0) 
      {
         uint32 I; 
         uint16 *ptr;  
         ptr = l1ctm->ul_pcm_fifo[buf_idx];
         if(ulInPcmWriteCount == PCM_DEBUG_BUFFER_SIZE)
         {            
            ASSERT(ulInPcmWriteFlag != 1);                  
         
            ulInPcmWriteFlag = 1;
            
            write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
            write_msg_info->write_file_hdl = f_ul_in_pcm_rec_hdl; 
            write_msg_info->write_buf = (uint8 *)ulInPcmWriteBuf[ulInPcmWriteBufIdx];
            write_msg_info->write_len = PCM_DEBUG_BUFFER_SIZE;
            aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, UL_IN_WRITE_FILE_REQUEST, (void*)write_msg_info);                                                                           
            
            ulInPcmWriteBufIdx ^= 0x1;
            ulInPcmWriteCount = 0;       
            ulInPcmWritePtr = ulInPcmWriteBuf[ulInPcmWriteBufIdx];                        
         }   
         for(I = 160; I > 0; I --)
            *ulInPcmWritePtr++ = *ptr++;   
         ulInPcmWriteCount += 320;                
      }                    
      #endif    
      
      #ifdef DL_IN_PCM_RECORD
      if (cprm_debug_flag & CPRM_MASK_REC_DL_PCM_IN)
      {
          uint16 vmRecDataCount;
          uint32 I; 
          uint16 *ptr;  
          if(sdCardNotFullFlag && f_dl_in_pcm_rec_hdl > 0) 
          {
             ptr = l1ctm->dl_pcm_fifo[buf_idx];
             if(dlInPcmWriteCount == PCM_DEBUG_BUFFER_SIZE)
             {             
                ASSERT(dlInPcmWriteFlag != 1);                  
         
                dlInPcmWriteFlag = 1;
            
                write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
                write_msg_info->write_file_hdl = f_dl_in_pcm_rec_hdl;          
                write_msg_info->write_buf = (uint8 *)dlInPcmWriteBuf[dlInPcmWriteBufIdx];         
                write_msg_info->write_len = PCM_DEBUG_BUFFER_SIZE;
                aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DL_IN_WRITE_FILE_REQUEST, (void*)write_msg_info);                        
               
         
                dlInPcmWriteBufIdx ^= 0x1;
                dlInPcmWriteCount = 0;       
                dlInPcmWritePtr = dlInPcmWriteBuf[dlInPcmWriteBufIdx];                        
             }   
             for(I = 160; I > 0; I --)
                *dlInPcmWritePtr++ = *ptr++;   
             dlInPcmWriteCount += 320;                
          }   
      
          vmRecDataCount = 0;
          if(vmRecDataCnt > 0)
          {
             uint32 savedMask;
             vmRecDataCount = vmRecDataCnt; 
             savedMask = SaveAndSetIRQMask(); 
             vmRecDataCnt = 0;
             RestoreIRQMask( savedMask );
          }   
          if(vmRecDataCount > 0)
          {                 
             write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
             write_msg_info->write_file_hdl = f_vm_rec_hdl;
             write_msg_info->write_buf = (uint8 *)vmRecDataPtr;
             write_msg_info->write_len = vmRecDataCount << 1;    
             vmRecDataCount = 0;      
             aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, GENERAL_WRITE_FILE_REQUEST, (void*)write_msg_info);

          }
      }
      #endif
      
      #ifdef DL_IN_BFI_RECORD
      dlInBfiWriteBuf[dlInBfiWriteBufIdx][dlInBfiWriteCount++] = (DP_CTM_CODEC_CTRL << 6) + (l1ctm->l1d_bfi_info[buf_idx]<<5) + l1ctm->bfi_info[buf_idx];
            
      if(dlInBfiWriteCount == DL_IN_BFI_WRITE_BUFFER_SIZE)
      {         
         write_msg_info = (File_Write_Msg_Info *) get_ctrl_buffer(sizeof(File_Write_Msg_Info));
         
         write_msg_info->write_file_hdl = f_dl_in_bfi_rec_hdl;
         write_msg_info->write_buf = (uint8 *)dlInBfiWriteBuf[dlInBfiWriteBufIdx];
         write_msg_info->write_len = DL_IN_BFI_WRITE_BUFFER_SIZE;  
         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, GENERAL_WRITE_FILE_REQUEST, (void*)write_msg_info);
                                                         
         dlInBfiWriteBufIdx ^= 0x1;
         dlInBfiWriteCount = 0;
      }            
      #endif        
               
      l1ctmFlags = l1ctm->FLAGS; 
      interface = l1ctm->interface;
#if !defined(CTM_CODEC_EXP)      
      ctmFlags = ctm_modem_get_flags();
      
      #if defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
      if(ctmReadDelayCountDown > 0) 
      {
         ctmReadDelayCountDown--;

         if(ctmReadDelayCountDown == 200)       // start negotiation 4 seconds before start sending text automatically
            aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, START_NEGOTIATION_REQUEST, NULL);

         if(ctmReadDelayCountDown == 0)
         {
            if(ul_ctm_text_buf_write_count > 0) 
            {
               Put_Text_File_Msg_Info *put_text_msg_info;               
               put_text_msg_info = (Put_Text_File_Msg_Info *)get_ctrl_buffer(sizeof(Put_Text_File_Msg_Info));
               put_text_msg_info->read_text_file_hdl = f_ul_ctm_text_hdl;    
               put_text_msg_info->text_buf_ptr = (uint8 *)Ul_CTM_Text_Buf;
               put_text_msg_info->write_text_len = ul_ctm_text_buf_write_count;
               put_text_msg_info->read_text_len = ul_ctm_text_buf_read_count;
               aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, PUT_TEXT_TO_UL_CTM_BUF_REQUEST, (void*)put_text_msg_info);             
            }
         }                    
      }       
      
      #endif 
      
            
      // up-link path input : Baudot Demodulator 
      if(interface == BAUDOT_MODE)
      {
      #if !defined(DUPLEX_BAUDOT)         
         if(ctmFlags & CMF_BAUDOT_OUT_BITS_READY && l1ctm->enquiry_count != -2)
            l1ctmFlags |= LCF_UL_MUTE;
         else
      #endif    
         { 
            baudot_demod((const uint16*)l1ctm->ul_pcm_fifo[buf_idx],&ctmFlags, &utf8_code); 
         
            if(ctmFlags & CMF_BAUDOT_IN_DETECTED && l1ctm->enquiry_count != -2)
               l1ctmFlags |= LCF_UL_MUTE;                                 
            else if(ctmFlags & CMF_BAUDOT_IN_CHAR)
            {
               UL_TTY_BUF_PUT_CHAR(utf8_code);
               L1CTM_TRACE_INFO( L1CTM_UL_GET_DECODED_TTY_CHAR , utf8_code );
            #if defined(BAUDOT_MODE_TEST)                  
               Ul_TTY_Text_Buf[ul_tty_text_buf_idx][ul_tty_text_buf_write_count++] = utf8_code;
               if(ul_tty_text_buf_write_count == UTF8_TEXT_BUF_LEN)
               {                        
                  write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
                  write_msg_info->write_file_hdl = f_ul_tty_text_hdl;
                  write_msg_info->write_buf = (uint8 *)Ul_TTY_Text_Buf[ul_tty_text_buf_idx];
                  write_msg_info->write_len = UTF8_TEXT_BUF_LEN;                   
                  aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, GENERAL_WRITE_FILE_REQUEST, (void*)write_msg_info);
                                                                                
                  ul_tty_text_buf_idx ^= 0x1;
                  ul_tty_text_buf_write_count = 0;
               }
            #endif
            }   
         }
      }
   
      // down-link path input : CTM receiver 
      if( l1ctm->interface == BAUDOT_MODE ) // Half-duplex CTM for BAUDOT_MODE //mtk01407, 2006-05-22
      {	
         if(    (!(ctmFlags & CMF_CTM_TX_BITS_READY))  ||  (l1ctmFlags & (LCF_NEGOTIATION | LCF_ACKING)) )
         { ctm_receiver((const uint16*)l1ctm->dl_pcm_fifo[buf_idx], bfi_flag, &ctmFlags, &utf8_code);  }
         else
         {	// If CTM is transmitting, dump zero patter to CTM receiver that means disable receiving function of CTM
            // Set bfi = 0 to avoid const zero_dl_pcm[] being modified      //mtk01407, 2006-05-17
            ctm_receiver((const uint16*)zero_dl_pcm,  0, &ctmFlags, &utf8_code);
         }  
        	
      }else	// Full-duplex CTM for DIRECT_MODE
      {
#if defined( DIRECT_MODE_PURE_SPEECH )
         {  // copy original speech data to keep pure speech
            uint32 i;
            uint16 *ptrSrc, *ptrDest;
            ptrSrc  = l1ctm->dl_pcm_fifo[buf_idx];
            ptrDest = l1ctm->dl_pcm_original;
            for( i = 160 ; i > 0 ; i-- )
               *ptrDest++ = *ptrSrc++;
         }
#endif
         ctm_receiver((const uint16*)l1ctm->dl_pcm_fifo[buf_idx], bfi_flag, &ctmFlags, &utf8_code);  	      	
      }
   
      if(ctmFlags & CMF_CTM_RX_DETECTED)
      {
         if(!(l1ctmFlags & LCF_DL_CTM_RECEIVING))
         {             
            l1ctmFlags |= LCF_DL_CTM_RECEIVING; 

            L1CTM_TRACE_STATE( L1CTM_DL_DETECT_CTM_SYNC ); 
//#ifdef SAVE_ONLY_TTY_CHAR            
//            l1ctm_save_decoded_char(0, BURST_START_CHAR);
//#endif         
            // command DSP to change to speech codec revision
            DP_CTM_CODEC_CTRL = (DP_CTM_CODEC_CTRL & 0xFFF0) | 0x1;
             
            if(!(l1ctmFlags & LCF_FAR_END_DETECTED))
            {           
               l1ctmFlags |= LCF_FAR_END_DETECTED;
               L1CTM_TRACE_STATE( L1CTM_FAR_END_CTM_DETECTED );
               l1ctm->state = L1CTM_CONNECTED_STATE;
               // first detect far-end CTM    
               if(l1ctmFlags & LCF_NEGOTIATION)
               {
                  L1CTM_TRACE_STATE( L1CTM_NEGOTIATION_SUCCESS );
                  l1ctmFlags &= ~LCF_NEGOTIATION;
                  l1ctmFlags |= LCF_DL_ACKING;
                  l1ctm->enquiry_timeout1 = 0;
                  l1ctm->enquiry_timeout2 = 0;
                  if(interface == BAUDOT_MODE)
                     l1ctm->enquiry_count = -1; //0;                                    
                  else if(interface == DIRECT_MODE)
                  {
                     l1ctm->callback_handler(CTM_MO_SUCCESS, (void*) 0);                                  
                     l1ctm->enquiry_count = 3;
                  }
               }
               else 
               {
                  L1CTM_TRACE_STATE( L1CTM_DEMAND_CTM_ACK );
                  l1ctmFlags |= LCF_SEND_ACK;
                  l1ctm->next_ack_timeout = NEXT_ACK_TIMEOUT;   
                  if(interface == DIRECT_MODE)
                     l1ctm->callback_handler(CTM_MT_DETECTED, (void*) 0);            
               }                  
            }
         } // end of if(!(l1ctmFlags & LCF_DL_CTM_RECEIVING))     
         
         if(ctmFlags & CMF_CTM_RX_CHAR)   
         { 
            L1CTM_TRACE_INFO( L1CTM_DL_GET_RECEIVED_CTM_CHAR , utf8_code );   
            if(l1ctmFlags & LCF_DL_ACKING)      
            {
            }
            else if(utf8_code == ENQUIRY_CHAR)
            {
               if(l1ctm->next_ack_timeout == 0)
               {
                  l1ctmFlags |= LCF_SEND_ACK;
                  l1ctm->next_ack_timeout = NEXT_ACK_TIMEOUT;              
               }   
            }
            else // receive a normal character  
            {
               #if defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)                    
                  l1ctm_save_decoded_char(utf8_code, 0);
               #endif    
               
               if(interface == BAUDOT_MODE)
               {
                  DL_TTY_BUF_PUT_CHAR(utf8_code);               
               }
               else if(interface == DIRECT_MODE)
               {
                  DL_CTM_BUF_PUT_CHAR(utf8_code);            
                  l1ctm->callback_handler(CTM_CHAR_RECEIVED, (void*)utf8_code);            
               }         
            }                
         } // end of if(ctmFlags & CMF_CTM_RX_CHAR)
      }        
      else 
      {
         if(l1ctmFlags & LCF_DL_CTM_RECEIVING)
         { 
            L1CTM_TRACE_STATE( L1CTM_DL_CTM_BURST_END );            
//#ifdef SAVE_ONLY_TTY_CHAR            
//            l1ctm_save_decoded_char(0, BURST_END_CHAR);
//#endif         
            l1ctmFlags &= ~LCF_DL_CTM_RECEIVING;
            l1ctmFlags &= ~LCF_DL_ACKING;
       
                        
            // command DSP to change to normal speech codec 
            DP_CTM_CODEC_CTRL = (DP_CTM_CODEC_CTRL & 0xFFF0) | 0x2;                         
                   
            l1ctm->transition_mute = DL_TRANSITION_MUTE_TIMEOUT;               
         }   
      }
      
#if defined( DIRECT_MODE_PURE_SPEECH )
      {
         uint32 i;
         uint16 *ptrSrc, *ptrDest;
         if( ( l1ctm->interface == DIRECT_MODE ) && !( l1ctmFlags & LCF_DL_CTM_RECEIVING ) ){
            ptrSrc  = l1ctm->dl_pcm_original;
            ptrDest = l1ctm->dl_pcm_fifo[buf_idx];
            for( i = 160 ; i > 0 ; i-- )
               *ptrDest++ = *ptrSrc++;
         }
      }
#endif
      // judge RX mute case               
      if(ctmFlags & CMF_CTM_RX_EARLY_MUTE || l1ctmFlags & LCF_DL_CTM_RECEIVING)
         l1ctmFlags |= LCF_DL_MUTE;        
   
      if((DP_CTM_CODEC_CTRL & 0xF) == 0x2)
         l1ctmFlags |= LCF_DL_MUTE; 
   
      if((DP_CTM_CODEC_CTRL & 0xF) == 0x0 && l1ctm->transition_mute > 0)
      {
         l1ctm->transition_mute --;
         l1ctmFlags |= LCF_DL_MUTE;   
      }   
                                                                        
  
      // down-link path output    
      if(interface == BAUDOT_MODE)
      {
         if(ctmFlags & CMF_BAUDOT_OUT_BITS_READY)
         {
            utf8_code = NON_UTF8_CHAR;
         
            if(ctmFlags & CMF_BAUDOT_OUT_NEAR_EMPTY)         
               if(DL_TTY_BUF_CHAR_READY())
               {
                  DL_TTY_BUF_GET_CHAR(utf8_code);                             
                  L1CTM_TRACE_INFO( L1CTM_DL_SEND_TTY_CHAR , utf8_code );  
               }   
                                 
            baudot_mod(utf8_code, l1ctm->dl_pcm_fifo[buf_idx], &ctmFlags);                                
         }
         else 
         {
            if(l1ctmFlags & LCF_DL_BAUDOT_TRANSMITTING)
               l1ctmFlags &= ~LCF_DL_BAUDOT_TRANSMITTING;      
            
            if(DL_TTY_BUF_CHAR_READY())
            {
               DL_TTY_BUF_GET_CHAR(utf8_code); 
               L1CTM_TRACE_INFO( L1CTM_DL_SEND_TTY_CHAR , utf8_code );              
               baudot_mod(utf8_code, l1ctm->dl_pcm_fifo[buf_idx], &ctmFlags);
            #if !defined(DUPLEX_BAUDOT)   
               baudot_demod_reset();
               l1ctmFlags |= LCF_UL_MUTE; // mute for baudot_out is modulating 
            #endif    
               l1ctmFlags |= LCF_DL_BAUDOT_TRANSMITTING;
            }                                
         }         
      }
                                                                                          
      // up-link path output       
      if(ctmFlags & CMF_CTM_TX_BITS_READY)
      {
         utf8_code = NON_UTF8_CHAR;
      
         l1ctmFlags &= ~LCF_SEND_ACK;
      
         if(ctmFlags & CMF_CTM_TX_NEAR_EMPTY)
         {
            utf8_code = IDLE_CHAR;
                  
            if(l1ctmFlags & LCF_NEGOTIATION)
            {
               // Yuan comment out to test the ul nego fail problem in LA.
               //if(interface == BAUDOT_MODE && l1ctm->enquiry_timeout1 > 0)   
               //   if(UL_TTY_BUF_CHAR_READY())
               //      UL_TTY_BUF_GET_CHAR(utf8_code);            
               //if(interface == BAUDOT_MODE && l1ctm->enquiry_timeout1 > 0)   
                  //utf8_code = ENQUIRY_CHAR;
            }
            else 
            {
               if(interface == BAUDOT_MODE && UL_TTY_BUF_CHAR_READY())
               {
                  UL_TTY_BUF_GET_CHAR(utf8_code);
               }
               else if(interface == DIRECT_MODE && UL_CTM_BUF_CHAR_READY())
               {
                  UL_CTM_BUF_GET_CHAR(utf8_code);   
                  l1ctm->callback_handler(CTM_CHAR_SENT, (void*)utf8_code);
               }
            } 
            L1CTM_TRACE_INFO( L1CTM_UL_SEND_CTM_CHAR , utf8_code );                                              
         }      
         ctm_transmitter(utf8_code, l1ctm->ul_pcm_fifo[buf_idx], &ctmFlags); 
      }
      else 
      {
         if(l1ctmFlags & LCF_UL_CTM_TRANSMITTING)
         {
            l1ctmFlags &= ~LCF_UL_CTM_TRANSMITTING;
            if(l1ctmFlags & LCF_ACKING)
            	l1ctmFlags &= ~LCF_ACKING; 
         
            if(interface == DIRECT_MODE)
               l1ctm->callback_handler(CTM_TX_BURST_END, (void*) 0);                                                               
         }
      
         if(l1ctm->enquiry_timeout2 == 0 && l1ctm->enquiry_count == 0)
         {
            l1ctmFlags &= ~LCF_NEGOTIATION;
         
            L1CTM_TRACE_STATE( L1CTM_NEGOTIATION_FAIL );  
            if(interface == DIRECT_MODE)
            {
               l1ctm->callback_handler(CTM_MO_FAIL, (void*)0);
               l1ctm->enquiry_count = 3; // reset enquiry_count to allow next negotiation            
            }
            else // BAUDOT_MODE
               l1ctm->enquiry_count = -2;  
                     
         }           
                  
         // judge if has character to send
         if(l1ctmFlags & LCF_FAR_END_DETECTED)
         {
            utf8_code = NO_CHAR;
         
            if(interface == BAUDOT_MODE && UL_TTY_BUF_CHAR_READY())
            {
               UL_TTY_BUF_GET_CHAR(utf8_code);
            }
            else if(interface == DIRECT_MODE && UL_CTM_BUF_CHAR_READY())
            {
               UL_CTM_BUF_GET_CHAR(utf8_code);
               l1ctm->callback_handler(CTM_CHAR_SENT, (void*)utf8_code);
            }
            else if(l1ctmFlags & LCF_SEND_ACK)
            {
               L1CTM_TRACE_STATE( L1CTM_UL_SEND_IDLE_AS_ACK );
               utf8_code = IDLE_CHAR;
            }
                                   
            if(utf8_code != NO_CHAR)
            {
               if(l1ctmFlags & LCF_SEND_ACK)
               {	
                  l1ctmFlags &= ~LCF_SEND_ACK;
                  l1ctmFlags |= LCF_ACKING;
               } 
               L1CTM_TRACE_INFO( L1CTM_UL_SEND_CTM_CHAR , utf8_code );
               ctm_transmitter(utf8_code, l1ctm->ul_pcm_fifo[buf_idx], &ctmFlags);               
               l1ctmFlags |= LCF_UL_CTM_TRANSMITTING;      
            }
         }
         else 
         {
            if(l1ctm->enquiry_count > 0)
            {
               //if(l1ctm->enquiry_count == 3) // Adam : mark for more enquiry 
               if(l1ctm->enquiry_count == more_enquiry_times)
               {
                  if((interface == BAUDOT_MODE && UL_TTY_BUF_CHAR_READY()) ||
                      (interface == DIRECT_MODE && (l1ctmFlags & LCF_NEGOTIATION_REQ)))                
                     l1ctmFlags |= (LCF_SEND_ENQUIRY + LCF_NEGOTIATION);                              
               }            
               else  
               {
                  if(l1ctm->enquiry_timeout2 == 0)
                     l1ctmFlags |= LCF_SEND_ENQUIRY;
               }
            
               if(l1ctmFlags & LCF_SEND_ENQUIRY)
               {
                  l1ctm->enquiry_count --; 
                  l1ctm->enquiry_timeout1 = ENQUIRY_TIMEOUT1;   
                  l1ctm->enquiry_timeout2 = ENQUIRY_TIMEOUT2; 
                  L1CTM_TRACE_INFO( L1CTM_UL_SEND_ENQUIRY_CHAR , 3 - l1ctm->enquiry_count );              
                  ctm_transmitter(ENQUIRY_CHAR, l1ctm->ul_pcm_fifo[buf_idx], &ctmFlags);
                  l1ctmFlags |= LCF_UL_CTM_TRANSMITTING;    
                  l1ctmFlags &= ~(LCF_SEND_ENQUIRY + LCF_NEGOTIATION_REQ);   
               }            
            }            
         }      
      }         
   
      // calculate time out
      if(l1ctm->next_ack_timeout > 0)
         l1ctm->next_ack_timeout --;
      if(l1ctm->enquiry_timeout1 > 0)
         l1ctm->enquiry_timeout1 --;  
      if(l1ctm->enquiry_timeout2 > 0)
         l1ctm->enquiry_timeout2 --;          
                                                             
#endif                
      // process output for MUTE case       
      if(!(l1ctmFlags & LCF_UL_CTM_TRANSMITTING) && (l1ctmFlags & LCF_UL_MUTE))
         l1ctm->ul_mute_flags |= 1 << l1ctm->next_to_process;
      else 
         l1ctm->ul_mute_flags &= ~(1 << l1ctm->next_to_process);         
      
      
      if(!(l1ctmFlags & LCF_DL_BAUDOT_TRANSMITTING) && (l1ctmFlags & LCF_DL_MUTE))
         l1ctm->dl_mute_flags |= 1 << l1ctm->next_to_process;
      else 
         l1ctm->dl_mute_flags &= ~(1 << l1ctm->next_to_process);   
      
      l1ctmFlags &= ~(LCF_UL_MUTE + LCF_DL_MUTE);
      l1ctm->FLAGS = l1ctmFlags;
             
           
      #ifdef UL_OUT_PCM_RECORD
      if((cprm_debug_flag & CPRM_MASK_REC_UL_PCM_OUT) && sdCardNotFullFlag && f_ul_out_pcm_rec_hdl > 0) 
      {
         uint32 I; 
         uint16 *ptr;  
         ptr = l1ctm->ul_pcm_fifo[buf_idx];
         if(ulOutPcmWriteCount == PCM_DEBUG_BUFFER_SIZE)
         {
            ASSERT(ulOutPcmWriteFlag != 1);                  
         
            ulOutPcmWriteFlag = 1;
            
            write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
            write_msg_info->write_file_hdl = f_ul_out_pcm_rec_hdl;             
            write_msg_info->write_buf = (uint8 *)ulOutPcmWriteBuf[ulOutPcmWriteBufIdx];   
            write_msg_info->write_len = PCM_DEBUG_BUFFER_SIZE; 
            aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, UL_OUT_WRITE_FILE_REQUEST, (void*)write_msg_info);                         
               
            
            ulOutPcmWriteBufIdx ^= 0x1;
            ulOutPcmWriteCount = 0;       
            ulOutPcmWritePtr = ulOutPcmWriteBuf[ulOutPcmWriteBufIdx];                        
         }
         if(l1ctm->ul_mute_flags & (1 << l1ctm->next_to_process))            
         {
            for(I = 160; I > 0; I --)
               *ulOutPcmWritePtr++ = 0;                
         }                   
         else 
         {
            for(I = 160; I > 0; I --)
               *ulOutPcmWritePtr++ = *ptr++;   
         }      
         ulOutPcmWriteCount += 320;                
      }                    
      #endif    
      
      #ifdef DL_OUT_PCM_RECORD
      if((cprm_debug_flag & CPRM_MASK_REC_DL_PCM_OUT) && sdCardNotFullFlag && f_dl_out_pcm_rec_hdl > 0) 
      {
         uint32 I; 
         uint16 *ptr;  
         ptr = l1ctm->dl_pcm_fifo[buf_idx];
         if(dlOutPcmWriteCount == PCM_DEBUG_BUFFER_SIZE)
         {
            ASSERT(dlOutPcmWriteFlag != 1);                  
         
            dlOutPcmWriteFlag = 1;
            
            write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
            write_msg_info->write_file_hdl = f_dl_out_pcm_rec_hdl;          
            write_msg_info->write_buf = (uint8 *)dlOutPcmWriteBuf[dlOutPcmWriteBufIdx];         
            write_msg_info->write_len = PCM_DEBUG_BUFFER_SIZE;
            aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DL_OUT_WRITE_FILE_REQUEST, (void*)write_msg_info);                        
               
            dlOutPcmWriteBufIdx ^= 0x1;
            dlOutPcmWriteCount = 0;       
            dlOutPcmWritePtr = dlOutPcmWriteBuf[dlOutPcmWriteBufIdx];                        
         }
         if(l1ctm->dl_mute_flags & (1 << l1ctm->next_to_process))            
         { 
            for(I = 160; I > 0; I --)
               *dlOutPcmWritePtr++ = 0;   
         }           
         else 
         {
            for(I = 160; I > 0; I --)
               *dlOutPcmWritePtr++ = *ptr++;   
         }      
         dlOutPcmWriteCount += 320;                
      }                    
      #endif    

      #ifdef RECORD_DSP_RXBUFFER
      if((cprm_debug_flag & CPRM_MASK_REC_RX_BUF) && sdCardNotFullFlag &&
         dsp_rec_idx >= DSP_RECORD_DATA_LEN - 20 &&
         fh_dsp_rec_rx_buf0 > 0 && fh_dsp_rec_nb_result0 > 0 && fh_dsp_rec_fn > 0/* && fh_dsp_rec_eq_so0 > 0*/)
      {
         uint32 savedMask;         
         int16 dsp_rec_idx2, dsp_rec_buf_idx2;

         ASSERT(dsp_rec_rx_buf0_write_ok == 1 && dsp_rec_nb_result0_write_ok == 1 && dsp_rec_fn_write_ok == 1/* && dsp_rec_eq_so0_write_ok == 1*/);
         dsp_rec_rx_buf0_write_ok = dsp_rec_nb_result0_write_ok = dsp_rec_fn_write_ok/* = dsp_rec_eq_so0_write_ok*/ = 0;
         
         savedMask = SaveAndSetIRQMask();
         dsp_rec_idx2 = dsp_rec_idx;
         dsp_rec_buf_idx2 = dsp_rec_buf_idx;
         dsp_rec_buf_idx ^= 0x1;
         dsp_rec_idx = 0;       
         RestoreIRQMask( savedMask );

         write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
         write_msg_info->write_file_hdl = fh_dsp_rec_rx_buf0;
         write_msg_info->write_buf = (uint8 *)dsp_rec_rx_buf0[dsp_rec_buf_idx2];
         write_msg_info->write_len = dsp_rec_idx2 * SAMPLES_RX_BUF * sizeof(uint16);
         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DSP_REC_RX_BUF0_REQUEST, (void*)write_msg_info);

         write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
         write_msg_info->write_file_hdl = fh_dsp_rec_nb_result0;
         write_msg_info->write_buf = (uint8 *)dsp_rec_nb_result0[dsp_rec_buf_idx2];
         write_msg_info->write_len = dsp_rec_idx2 * SAMPLES_NB_RESULT0 * sizeof(uint16);
         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DSP_REC_NB_RESULT0_REQUEST, (void*)write_msg_info);

         write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
         write_msg_info->write_file_hdl = fh_dsp_rec_fn;
         write_msg_info->write_buf = (uint8 *)dsp_rec_fn[dsp_rec_buf_idx2];
         write_msg_info->write_len = dsp_rec_idx2 * sizeof(int32);
         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DSP_REC_FN_REQUEST, (void*)write_msg_info);

//         write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
//         write_msg_info->write_file_hdl = fh_dsp_rec_eq_so0;
//         write_msg_info->write_buf = (uint8 *)dsp_rec_eq_so0[dsp_rec_buf_idx2];
//         write_msg_info->write_len = dsp_rec_idx2 * 116 * sizeof(uint16);
//         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DSP_REC_EQ_SO0_REQUEST, (void*)write_msg_info);
      }
      #endif // RECORD_DSP_RXBUFFER

#if defined(UL_GET_PCM_FROM_FILE) || defined(DL_GET_PCM_FROM_FILE)
   if(pcmDebugReadFlag & (UL_IN_READ_PCM_FLAG + DL_IN_READ_PCM_FLAG))
   {
      uint32 savedMask;               
      #if defined(UL_GET_PCM_FROM_FILE)
      if(pcmDebugReadFlag & UL_IN_READ_PCM_FLAG)
      {
         read_msg_info = (File_Read_Msg_Info *)get_ctrl_buffer(sizeof(File_Read_Msg_Info));
         read_msg_info->read_file_hdl = f_ul_in_pcm_hdl; 
         if(pcmDebugReadFlag & UL_IN_READ_PCM_BUF1)  
            read_msg_info->read_buf = (uint8 *)ulInPcmReadBuf[1];
         else 
            read_msg_info->read_buf = (uint8 *)ulInPcmReadBuf[0];   
         read_msg_info->read_len = PCM_DEBUG_BUFFER_SIZE;
         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, UL_READ_PCM_FILE_REQUEST, (void*)read_msg_info);
      }          
      #endif   
      #if defined(DL_GET_PCM_FROM_FILE) 
      if(pcmDebugReadFlag & DL_IN_READ_PCM_FLAG)
      {
         read_msg_info = (File_Read_Msg_Info *)get_ctrl_buffer(sizeof(File_Read_Msg_Info));  
         read_msg_info->read_file_hdl = f_dl_in_pcm_hdl;   
         if(pcmDebugReadFlag & DL_IN_READ_PCM_BUF1)  
            read_msg_info->read_buf = (uint8 *)dlInPcmReadBuf[1];
         else 
            read_msg_info->read_buf = (uint8 *)dlInPcmReadBuf[0];   
         read_msg_info->read_len = PCM_DEBUG_BUFFER_SIZE;
         aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, DL_READ_PCM_FILE_REQUEST, (void*)read_msg_info);
      }        
      #endif          
      savedMask = SaveAndSetIRQMask();   
      pcmDebugReadFlag &= ~(UL_IN_READ_PCM_FLAG + DL_IN_READ_PCM_FLAG);
      RestoreIRQMask( savedMask );      
   }
#endif

      l1ctm->next_to_process ++;
      if(l1ctm->next_to_process == 2 * PCM_FIFO_LEN)
         l1ctm->next_to_process = 0;   
         
   } 
}


/*============================== L1Ctm APIs ====================================*/

uint32 L1Ctm_GetMemReq(void)
{
   uint32 mem_size = 0;   

   mem_size = sizeof(L1Ctm_Module) + ctm_modem_mem_req();
   
#if 0
#if defined(UL_GET_PCM_FROM_FILE)
/* under construction !*/
#endif 
#if defined(DL_GET_PCM_FROM_FILE)
/* under construction !*/
#endif 
#if defined(UL_IN_PCM_RECORD)
/* under construction !*/
#endif 
#if defined(UL_OUT_PCM_RECORD)
/* under construction !*/
#endif 
#if defined(DL_IN_PCM_RECORD)
/* under construction !*/
#endif 
#if defined(DL_OUT_PCM_RECORD)
/* under construction !*/
#endif 
#endif
      
   return mem_size;      
}

void AFE_SetInputSource( kal_uint8 src ); // HCO src : L1SP_LNA_1 (1, headset mode)  ; 
                                          // VCO src : L1SP_LNA_0 (0, normal mode) ; 
void AFE_SetOutputDevice( kal_uint8 aud_func, kal_uint8 device );
                                         // aud_func : L1SP_SPEECH   
                                         // HCO device : L1SP_BUFFER_0 (0x01, normal speaker)  
                                         // VCO device : L1SP_BUFFER_ST(0x04, headset speaker)     
void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index );
                        // check if HCO need to set output volume to norml mode 
void AFE_SetMicrophoneVolume( kal_uint8 mic_volume );
                        // check if VCO need to set input volume to normal mode                           
                                 

void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, uint8 *buf, uint32 buf_len, CTM_Param *ctm_param)
{   
   uint8 *buf_ptr;
   #ifdef RECORD_DSP_RXBUFFER
   uint32 savedMask;
   #endif
   
   L1CTM_TRACE_FUNC( L1CTM_OPEN );  
            
   ASSERT(l1ctm == (L1Ctm_Module*) 0);
   ASSERT(buf_len >= L1Ctm_GetMemReq()); 
   
   L1SP_EnableSpeechEnhancement(false);   
   
   if(ctm_hco_vco_state == 1) // HCO 
   {  // set output source to normal mode   
      AFE_SetOutputDevice(L1SP_SPEECH,L1SP_BUFFER_0); 	
   	  AFE_SetOutputVolume(L1SP_SPEECH, 176, 0);
   	  kal_prompt_trace(MOD_L1SP, "Opening ctm in HCO mode.");
   }
   else if(ctm_hco_vco_state == 2) // VCO 
   {  // set input source to normal mode  
      AFE_SetInputSource(L1SP_LNA_0);		
   	  AFE_SetMicrophoneVolume(176); 
   	  kal_prompt_trace(MOD_L1SP, "Opening ctm in VCO mode.");
   }
   else
   {	  kal_prompt_trace(MOD_L1SP, "Opening ctm in normal mode (no HCO/VCO).");
   }
   
   // dynamic code reallocation to TCM   
   DCM_Load(DYNAMIC_CODE_CTM, 0, 0);
   
   // allocate memory to L1CTM and CTM modem , and init CTM modem       
   l1ctm = (L1Ctm_Module*) buf;
   buf_ptr = buf + sizeof(L1Ctm_Module);
   buf_len -= sizeof(L1Ctm_Module);  

#if defined(UL_GET_PCM_FROM_FILE)   
   ulInPcmReadBuf[0] = (uint16*)ULINPCMREADBUF[0];
   ulInPcmReadBuf[1] = (uint16*)ULINPCMREADBUF[1];
#endif 

#if defined(DL_GET_PCM_FROM_FILE)   
   dlInPcmReadBuf[0] = (uint16*)DLINPCMREADBUF[0];
   dlInPcmReadBuf[1] = (uint16*)DLINPCMREADBUF[1];
#endif 

#if defined(UL_IN_PCM_RECORD)
   ulInPcmWriteBuf[0] = (uint16*)ULINPCMWRITEBUF[0];
   ulInPcmWriteBuf[1] = (uint16*)ULINPCMWRITEBUF[1];
#endif 

#if defined(UL_OUT_PCM_RECORD)
   ulOutPcmWriteBuf[0] = (uint16*)ULOUTPCMWRITEBUF[0];
   ulOutPcmWriteBuf[1] = (uint16*)ULOUTPCMWRITEBUF[1];
#endif 

#if defined(DL_IN_PCM_RECORD)
   dlInPcmWriteBuf[0] = (uint16*)DLINPCMWRITEBUF[0];
   dlInPcmWriteBuf[1] = (uint16*)DLINPCMWRITEBUF[1];
#endif 

#if defined(DL_OUT_PCM_RECORD)
   dlOutPcmWriteBuf[0] = (uint16*)DLOUTPCMWRITEBUF[0];
   dlOutPcmWriteBuf[1] = (uint16*)DLOUTPCMWRITEBUF[1];
#endif 

#if 0
#if defined(UL_GET_PCM_FROM_FILE)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if defined(DL_GET_PCM_FROM_FILE)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if defined(UL_IN_PCM_RECORD)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if defined(UL_OUT_PCM_RECORD)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if defined(DL_IN_PCM_RECORD)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if defined(DL_OUT_PCM_RECORD)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif

   ctm_modem_init(buf_ptr, buf_len, ctm_param);   

   if(ctm_param != NULL)
   {
      cprm_debug_flag = ctm_param->cprm_tone_demod_down_samp;
      //cprm_debug_flag = CPRM_MASK_REC_DL_PCM_OUT;    // temp override
      kal_prompt_trace(MOD_L1SP, "ctm param is not null, cprm_debug_flag=%x", cprm_debug_flag);
   }
   else
   {   cprm_debug_flag = CPRM_MASK_DOWN_SAMP | CPRM_MASK_REC_DL_PCM_IN | CPRM_MASK_REC_DL_PCM_OUT | CPRM_MASK_REC_UL_PCM_IN | CPRM_MASK_REC_UL_PCM_OUT;
      //cprm_debug_flag = CPRM_MASK_REC_RX_BUF | CPRM_MASK_REC_DL_PCM_IN | CPRM_MASK_REC_DL_PCM_OUT | CPRM_MASK_REC_UL_PCM_IN | CPRM_MASK_REC_UL_PCM_OUT;
   }
   
   // set interface 
   ASSERT(a == BAUDOT_MODE || a == DIRECT_MODE);
   l1ctm->interface = a;       
   
   // init l1ctm pcm_fifo output to 0 by setting ul_mute_flags & dl_mute_flags
   l1ctm->ul_mute_flags = 2^PCM_FIFO_LEN - 1;
   l1ctm->dl_mute_flags = 2^PCM_FIFO_LEN - 1;
       
   // init l1ctm variables
   l1ctm->aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler(l1ctm->aud_id , l1ctm_in_task);
   L1Audio_SetFlag(l1ctm->aud_id);
   l1ctm->callback_handler = handler; 
   l1ctm->next_to_process = PCM_FIFO_LEN;
   l1ctm->pcm_fifo_write = PCM_FIFO_LEN;
   l1ctm->pcm_fifo_read = 0;                 
   l1ctm->ul_tty_buf_read = 0;  
   l1ctm->ul_tty_buf_write = 0;
   l1ctm->ul_ctm_buf_read = 0;
   l1ctm->ul_ctm_buf_write = 0;
   l1ctm->dl_tty_buf_read = 0;
   l1ctm->dl_tty_buf_write = 0;
   l1ctm->dl_ctm_buf_read = 0;
   l1ctm->dl_ctm_buf_write = 0;  
   l1ctm->FLAGS = 0;
   //l1ctm->interface = DIRECT_MODE; // default set
   l1ctm->state = L1CTM_READY_STATE;    
   l1ctm->next_ack_timeout = 0;
   l1ctm->enquiry_count = 3;
   
   if(cprm_debug_flag & CPRM_MASK_MORE_ENQUIRY) // Adam : for more enquiry 
   {
      l1ctm->enquiry_count = MORE_ENQUIRY; 					
      more_enquiry_times = MORE_ENQUIRY; 	
   }
   else 
      more_enquiry_times = 3; // the same setting as Spec 
   
   if(cprm_debug_flag & CPRM_MASK_ALWAYS_NEGO_SUC) // Adam : for non-Negotiation test 
   {
      l1ctm->FLAGS = LCF_FAR_END_DETECTED; 
      if(l1ctm->interface == BAUDOT_MODE)
         l1ctm->enquiry_count = -1; 	
   }  
   	      
   l1ctm->enquiry_timeout1 = 0;
   l1ctm->enquiry_timeout2 = 0;
   l1ctm->transition_mute = 0;
   
   l1ctm->l1d_bfi_info[0] = 0;
   

   #if defined(UL_GET_PCM_FROM_FILE) || defined(DL_GET_PCM_FROM_FILE) || defined(UL_IN_PCM_RECORD) || defined(UL_OUT_PCM_RECORD) || defined(DL_IN_PCM_RECORD) || defined(DL_OUT_PCM_RECORD) || defined(RECORD_DSP_RXBUFFER) || defined(DL_IN_BFI_RECORD) || defined(CTM_COSIM)
   sdCardDrv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
   if(sdCardDrv <= 0)   
      //ASSERT(false);
      sdCardDrv = 'D';
   pcmDebugReadFlag = 0;        
     
   #endif    

   #if defined(L1CTM_DEBUG_MODE) 
   sdCardNotFullFlag = 1;
   #endif 
   
   #ifdef UL_GET_PCM_FROM_FILE
   kal_wsprintf(file_name, "%c:\\ul_pcm_in.pcm",sdCardDrv);  
   f_ul_in_pcm_hdl = FS_Open(file_name,  FS_READ_ONLY);
      
   if(f_ul_in_pcm_hdl > 0)         
   {
      uint32 read_len;       
      FS_Read(f_ul_in_pcm_hdl, ulInPcmReadBuf[0], PCM_DEBUG_BUFFER_SIZE, &read_len);
      ulInPcmDataCount = read_len;
      ulInPcmReadCount = 0;
      ulInPcmReadBufIdx = 0; 
      ulInPcmReadPtr = ulInPcmReadBuf[0];    
      if(read_len != PCM_DEBUG_BUFFER_SIZE)      
         ulInPcmReadFlag = READ_EOF_FLAG;                                 
      else 
      {
         pcmDebugReadFlag |= (UL_IN_READ_PCM_FLAG + UL_IN_READ_PCM_BUF1);
         ulInPcmReadFlag = 0;
      }             
   }        
   #endif    
   
   #ifdef DL_GET_PCM_FROM_FILE
   kal_wsprintf(file_name, "%c:\\dl_pcm_in.pcm",sdCardDrv);  
   f_dl_in_pcm_hdl = FS_Open(file_name,  FS_READ_ONLY);

   if(f_dl_in_pcm_hdl > 0)
   {
      uint32 read_len;
      FS_Read(f_dl_in_pcm_hdl, dlInPcmReadBuf[0], PCM_DEBUG_BUFFER_SIZE, &read_len);
      dlInPcmDataCount = read_len;
      dlInPcmReadCount = 0;
      dlInPcmReadBufIdx = 0; 
      dlInPcmReadPtr = dlInPcmReadBuf[0];    
      if(read_len != PCM_DEBUG_BUFFER_SIZE)      
         dlInPcmReadFlag = READ_EOF_FLAG;                                 
      else 
      {
         pcmDebugReadFlag |= (DL_IN_READ_PCM_FLAG + DL_IN_READ_PCM_BUF1);
         dlInPcmReadFlag = 0;
      }   
      
      // open BFI file 
      kal_wsprintf(file_name, "%c:\\dl_bfi_in.pcm",sdCardDrv);  
      f_dl_in_bfi_hdl = FS_Open(file_name,  FS_READ_ONLY);

      if(f_dl_in_bfi_hdl > 0)
      {
         uint32 read_len;      
      
         FS_Read(f_dl_in_bfi_hdl, dlInBfiReadBuf[0], DL_IN_BFI_READ_BUFFER_SIZE, &read_len);
         dlInBfiReadBufDataCount[0] = read_len; 
         
         dlInBfiDataCount = read_len;
         dlInPcmReadCount = 0;
         dlInPcmReadBufIdx = 0; 
      
         if(read_len != DL_IN_BFI_READ_BUFFER_SIZE)      
            dlInBfiReadFlag = READ_EOF_FLAG;                  
         else 
         {
            FS_Read(f_dl_in_bfi_hdl, dlInBfiReadBuf[1], DL_IN_BFI_READ_BUFFER_SIZE, &read_len);
            dlInBfiReadBufDataCount[1] = read_len; 

            if(read_len != DL_IN_BFI_READ_BUFFER_SIZE)
               dlInBfiReadFlag = READ_EOF_FLAG + HAS_ANOTHER_BUF_DATA_FLAG;
            else 
               dlInBfiReadFlag = HAS_ANOTHER_BUF_DATA_FLAG;   
         }      
      }                         
   }
   else 
   {
      f_dl_in_bfi_hdl = -1;         
   }   
   #endif    
   
   #if defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
   kal_wsprintf(file_name, "%c:\\ul_text_in.txt",sdCardDrv);  
   f_ul_ctm_text_hdl = FS_Open(file_name, FS_READ_ONLY);
   
   if(f_ul_ctm_text_hdl > 0)
   {
      uint32 read_len;
      FS_Read(f_ul_ctm_text_hdl, Ul_CTM_Text_Buf, 2*UTF8_TEXT_BUF_LEN, &read_len); 
      ul_ctm_text_buf_write_count = read_len; 
      if(read_len == 2*UTF8_TEXT_BUF_LEN)       
         ul_ctm_text_buf_read_count = UTF8_TEXT_BUF_LEN;
      else     
         ul_ctm_text_buf_read_count = 0;  
         
      ctmReadDelayCountDown = CtmReadFileDelay * 50;
      l1ctm->callback_handler = l1ctm_callback1; 
      l1ctm->interface = DIRECT_MODE;
   }
   else 
      ul_ctm_text_buf_write_count = 0;
   
   ul_text_sent = 0;
   ul_text_received = 0;
   
   #endif 

#if defined(UL_IN_PCM_RECORD) || defined(UL_OUT_PCM_RECORD) || defined(DL_IN_PCM_RECORD) || defined(DL_OUT_PCM_RECORD) || defined(BAUDOT_MODE_TEST) || defined(RECORD_DSP_RXBUFFER) || defined(DL_IN_BFI_RECORD) || defined(CTM_COSIM)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   while (ctm_rec_dir_no < 200)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u",sdCardDrv,ctm_rec_dir_no);  
       if (FS_NO_ERROR == FS_CreateDir(file_name))
       {
          L1CTM_TRACE_INFO(L1CTM_REC_DIR_NO, ctm_rec_dir_no);
          break;
       }
       ctm_rec_dir_no++;
   }
#endif
#endif

   #ifdef UL_IN_PCM_RECORD
   if (cprm_debug_flag & CPRM_MASK_REC_UL_PCM_IN)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u\\ul_pcm_in_rec.pcm",sdCardDrv,ctm_rec_dir_no);  
       f_ul_in_pcm_rec_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS); 
   }
   else
       f_ul_in_pcm_rec_hdl = 0;

   ulInPcmWriteFlag = 0;
   ulInPcmWriteCount = 0;
   ulInPcmWriteBufIdx = 0;
   ulInPcmWritePtr = ulInPcmWriteBuf[0];
   #endif    
   
   #ifdef UL_OUT_PCM_RECORD
   if (cprm_debug_flag & CPRM_MASK_REC_UL_PCM_OUT)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u\\ul_pcm_out_rec.pcm",sdCardDrv,ctm_rec_dir_no); 
       f_ul_out_pcm_rec_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);
   }
   else
       f_ul_out_pcm_rec_hdl = 0;

   ulOutPcmWriteFlag = 0;
   ulOutPcmWriteCount = 0;
   ulOutPcmWriteBufIdx = 0;
   ulOutPcmWritePtr = ulOutPcmWriteBuf[0];  
   #endif 
      
   #ifdef DL_IN_PCM_RECORD
   // record PCM 
   if (cprm_debug_flag & CPRM_MASK_REC_DL_PCM_IN)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u\\dl_pcm_in_rec.pcm",sdCardDrv,ctm_rec_dir_no);   
       f_dl_in_pcm_rec_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);
   }
   else
       f_dl_in_pcm_rec_hdl = 0;
   dlInPcmWriteFlag = 0;
   dlInPcmWriteCount = 0;
   dlInPcmWriteBufIdx = 0;
   dlInPcmWritePtr = dlInPcmWriteBuf[0];
   
   // record VM 
   if (cprm_debug_flag & CPRM_MASK_REC_DL_PCM_IN)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u\\ul_dl_rec.vm",sdCardDrv,ctm_rec_dir_no);   
       f_vm_rec_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);   
   }
   else
       f_vm_rec_hdl = 0;
   vmDataBufIdx = 0;
   vmDataStartPtr = vmDataBuf[vmDataBufIdx];
   vmDataEndPtr = vmDataStartPtr + VM_DATA_BUFFER_SIZE;
   vmDataPtr = vmDataStartPtr;   
   vmRecDataCnt = 0;   
   #endif 
      
   #ifdef DL_IN_BFI_RECORD
   // record dlInBfiReadBuf
   kal_wsprintf(file_name, "%c:\\REC_%02u\\dl_bfi.rec",sdCardDrv,ctm_rec_dir_no);   
   f_dl_in_bfi_rec_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);   
   dlInBfiWriteCount = 0;
   dlInBfiWriteBufIdx = 0;  
   #endif 
   
   #ifdef DL_OUT_PCM_RECORD
   if (cprm_debug_flag & CPRM_MASK_REC_DL_PCM_OUT)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u\\dl_pcm_out_rec.pcm",sdCardDrv,ctm_rec_dir_no);   
       f_dl_out_pcm_rec_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);
   }
   else
       f_dl_out_pcm_rec_hdl = 0;

   dlOutPcmWriteFlag = 0;
   dlOutPcmWriteCount = 0;
   dlOutPcmWriteBufIdx = 0;
   dlOutPcmWritePtr = dlOutPcmWriteBuf[0];
   #endif
         
   #ifdef RECORD_DSP_RXBUFFER
   if (cprm_debug_flag & CPRM_MASK_REC_RX_BUF)
   {
       kal_wsprintf(file_name, "%c:\\REC_%02u\\dsp_rec_rx_buf0.bin",sdCardDrv,ctm_rec_dir_no);   
       fh_dsp_rec_rx_buf0 = FS_Open(file_name,  FS_CREATE_ALWAYS);
       kal_wsprintf(file_name, "%c:\\REC_%02u\\dsp_rec_nb_result0.bin",sdCardDrv,ctm_rec_dir_no);   
       fh_dsp_rec_nb_result0 = FS_Open(file_name,  FS_CREATE_ALWAYS);
       kal_wsprintf(file_name, "%c:\\REC_%02u\\dsp_rec_fn.bin",sdCardDrv,ctm_rec_dir_no);   
       fh_dsp_rec_fn = FS_Open(file_name,  FS_CREATE_ALWAYS);
//       kal_wsprintf(file_name, "%c:\\REC_%02u\\dsp_rec_eq_so0.bin",sdCardDrv,ctm_rec_dir_no);   
//       fh_dsp_rec_eq_so0 = FS_Open(file_name,  FS_CREATE_ALWAYS);
       
       ASSERT(fh_dsp_rec_rx_buf0 > 0);  // To avoid SD card not detected problem.

       savedMask = SaveAndSetIRQMask(); 
       dsp_rec_idx = 0;
       dsp_rec_buf_idx = 0;
       RestoreIRQMask( savedMask );
       dsp_rec_rx_buf0_write_ok = 1;
       dsp_rec_nb_result0_write_ok = 1;
       dsp_rec_fn_write_ok = 1;
       //dsp_rec_eq_so0_write_ok = 1;
   }
   #endif
         

#if defined(BAUDOT_MODE_TEST)
   kal_wsprintf(file_name, "%c:\\REC_%02u\\med_ul_tty.txt",sdCardDrv,ctm_rec_dir_no);   
   f_ul_tty_text_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);
   ul_tty_text_buf_idx = 0;
   ul_tty_text_buf_write_count = 0;
   kal_wsprintf(file_name, "%c:\\REC_%02u\\med_dl_ctm.txt",sdCardDrv,ctm_rec_dir_no);   
   f_dl_ctm_text_hdl = FS_Open(file_name,  FS_CREATE_ALWAYS);
   dl_ctm_text_buf_idx = 0;
   dl_ctm_text_buf_write_count = 0;
#endif 

#if defined(UL_IN_PCM_RECORD) || defined(UL_OUT_PCM_RECORD) || defined(DL_IN_PCM_RECORD) || defined(DL_OUT_PCM_RECORD) || defined(BAUDOT_MODE_TEST) || defined(DL_IN_BFI_RECORD) || defined(CTM_COSIM)
   ctm_rec_dir_no++;
#endif

#ifdef CTM_CODEC_EXP
   ctm_codec_state = 0;
   ctm_codec_exp_cnt = 0;

#endif 
   //DSP_DynamicDownload( DDID_AMR_CC_SCHEDULE );
   DP_CTM_CODEC_CTRL = (DP_CTM_CODEC_CTRL & 0xFFF0) | 0x0;

   //if(ctm_param != NULL)
   //{
      DP_CTM_AMR_CODEBOOK_GAIN_LIMIT = CPRM_CODEBOOK_GAIN_THRESHOLD;
      DP_CTM_AMR_CODEBOOK_GAIN_UPDATE = CPRM_CODEBOOK_GAIN_VALUE;
   //}
   //else
   //{
   //#if defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6228) || defined(MT6225)
      //DP_CTM_AMR_CODEBOOK_GAIN_LIMIT = 3000;
      //DP_CTM_AMR_CODEBOOK_GAIN_UPDATE = 2800;
   //#else
      //DP_CTM_AMR_CODEBOOK_GAIN_LIMIT = 4000;
      //DP_CTM_AMR_CODEBOOK_GAIN_UPDATE = 2000;
   //#endif
   //}
   
#if defined(FAKE_CTM_COSIM)
   if (CtmReadFileDelay == 20)
   {
#endif    
#if defined(FAKE_CTM_COSIM) || defined(CTM_COSIM)
      kal_prompt_trace(MOD_L1SP, "Opening CTM in cosim mode");
       
      cosim_guard_period = COSIM_GUARD_PERIOD_LEN;
      cosim_dump_index = 0;
       
      //DP_BFI_FACCH_REPORT = 0x8000;
   DP_CTM_CODEC_CTRL = 0;
   DP_CTM_COSIM_CTRL = 0;
      idma_load_pm(0, 0x3ebc, sizeof(ctm_cosim_data) / sizeof(ctm_cosim_data[0]), (const kal_uint16 *)ctm_cosim_data);
#endif
#if defined(FAKE_CTM_COSIM)
   }
#endif
   if (CtmReadFileDelay == 50 || CtmReadFileDelay == 60)
      *AFE_VLB_CON |= 0x02;
      //*AFE_VAC_CON1 |= 0x01;    // Loopback
   
   // start DSP PCM4WAY service 
   PCM4WAY_Start(l1ctm_in_hisr,0); 

} // End of L1Ctm_open(~)

void L1Ctm_Close(void)
{
#ifdef L1CTM_DEBUG_MODE /*2006-06-14 Jinfa*/
	 Check_Setting_by_Catcher_Trace(); // Show setting of CTM by catcher
#endif

   L1CTM_TRACE_FUNC( L1CTM_CLOSE );
   
   if (CtmReadFileDelay == 50 || CtmReadFileDelay == 60)
      *AFE_VLB_CON &= ~0x02;
      //*AFE_VAC_CON1 &= ~0x01;    // Loopback
   
   ASSERT(l1ctm != (L1Ctm_Module*) 0);   
   PCM4WAY_Stop(0); 
   DCM_Unload(DYNAMIC_CODE_CTM);
   
#ifdef CTM_COSIM
   if(sdCardNotFullFlag)
   {
      int32 fh_cosim_dump;
      uint32 write_count;
      
      kal_wsprintf(file_name, "%c:\\REC_%02u\\cosim_dump.rec", sdCardDrv, ctm_rec_dir_no - 1);  
      fh_cosim_dump = FS_Open(file_name, FS_CREATE_ALWAYS); 
      if (fh_cosim_dump > 0)
      {
          FS_Write(fh_cosim_dump, cosim_dump_data, COSIM_DUMP_DATA_LEN, &write_count);                    
          if(write_count != COSIM_DUMP_DATA_LEN)
             sdCardNotFullFlag = 0;
          FS_Close(fh_cosim_dump);
      }
   }
#endif   
      
#if defined(UL_GET_PCM_FROM_FILE)
   if(f_ul_in_pcm_hdl > 0)
      FS_Close(f_ul_in_pcm_hdl);   
#endif 
#if defined(DL_GET_PCM_FROM_FILE)
   if(f_dl_in_pcm_hdl > 0)
      FS_Close(f_dl_in_pcm_hdl);
   if(f_dl_in_bfi_hdl > 0)
      FS_Close(f_dl_in_bfi_hdl);
#endif 

#if defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
   if(f_ul_ctm_text_hdl > 0)
      FS_Close(f_ul_ctm_text_hdl);
#endif 

#if defined(UL_IN_PCM_RECORD)
   if(f_ul_in_pcm_rec_hdl > 0)
   {
      if(ulInPcmWriteCount > 0 && sdCardNotFullFlag)   
         FS_Write(f_ul_in_pcm_rec_hdl, ulInPcmWriteBuf[ulInPcmWriteBufIdx], ulInPcmWriteCount, NULL);                
      FS_Close(f_ul_in_pcm_rec_hdl);  
   }   
#endif 
#if defined(UL_OUT_PCM_RECORD)
   if(f_ul_out_pcm_rec_hdl > 0)
   {
      if(ulOutPcmWriteCount > 0 && sdCardNotFullFlag)   
         FS_Write(f_ul_out_pcm_rec_hdl, ulOutPcmWriteBuf[ulOutPcmWriteBufIdx], ulOutPcmWriteCount, NULL);
      FS_Close(f_ul_out_pcm_rec_hdl);      
   }   
#endif 
#if defined(DL_IN_PCM_RECORD)
   if(f_dl_in_pcm_rec_hdl > 0)
   {
      if(dlInPcmWriteCount > 0 && sdCardNotFullFlag)   
         FS_Write(f_dl_in_pcm_rec_hdl, dlInPcmWriteBuf[dlInPcmWriteBufIdx], dlInPcmWriteCount, NULL);
      FS_Close(f_dl_in_pcm_rec_hdl);      
   } 
   
   if(f_vm_rec_hdl > 0)
   {          
      if(vmDataPtr > vmDataStartPtr)
      {
         uint16 vmRecCount;
         vmRecCount = (uint16)(vmDataPtr - vmDataStartPtr);          
         FS_Write(f_vm_rec_hdl, vmDataStartPtr, vmRecCount << 1, NULL);
      }   
      FS_Close(f_vm_rec_hdl);               
   }
#endif 
#if defined(DL_IN_BFI_RECORD)
   if(f_dl_in_bfi_rec_hdl > 0)
   {
      if(dlInBfiWriteCount > 0 && sdCardNotFullFlag) 
         FS_Write(f_dl_in_bfi_rec_hdl, dlInBfiWriteBuf[dlInBfiWriteBufIdx], dlInBfiWriteCount, NULL);
      FS_Close(f_dl_in_bfi_rec_hdl);           
   } 
#endif 

#if defined(DL_OUT_PCM_RECORD)
   if(f_dl_out_pcm_rec_hdl > 0)
   {
      if(dlOutPcmWriteCount > 0 && sdCardNotFullFlag)   
         FS_Write(f_dl_out_pcm_rec_hdl, dlOutPcmWriteBuf[dlOutPcmWriteBufIdx], dlOutPcmWriteCount, NULL);
      FS_Close(f_dl_out_pcm_rec_hdl);      
   }   
#endif 

#if defined(RECORD_DSP_RXBUFFER)
   if (cprm_debug_flag & CPRM_MASK_REC_RX_BUF)
   {
       if(fh_dsp_rec_rx_buf0 > 0)       FS_Close(fh_dsp_rec_rx_buf0);      
       if(fh_dsp_rec_nb_result0 > 0)    FS_Close(fh_dsp_rec_nb_result0);      
       if(fh_dsp_rec_fn > 0)            FS_Close(fh_dsp_rec_fn);      
       //if(fh_dsp_rec_eq_so0 > 0)        FS_Close(fh_dsp_rec_eq_so0);      
   }
#endif 

#if defined(BAUDOT_MODE_TEST)
   if(f_ul_tty_text_hdl > 0)
   {
      if(ul_tty_text_buf_write_count > 0) 
         FS_Write(f_ul_tty_text_hdl, Ul_TTY_Text_Buf[ul_tty_text_buf_idx], ul_tty_text_buf_write_count, NULL);
      FS_Close(f_ul_tty_text_hdl);
   }
   
   if(f_dl_ctm_text_hdl > 0)
   {
      if(dl_ctm_text_buf_write_count > 0) 
         FS_Write(f_dl_ctm_text_hdl, Dl_CTM_Text_Buf[dl_ctm_text_buf_idx], dl_ctm_text_buf_write_count, NULL);
      FS_Close(f_dl_ctm_text_hdl);
   }
#endif 
   
   L1Audio_ClearFlag(l1ctm->aud_id); 
   L1Audio_FreeAudioID(l1ctm->aud_id); 
   l1ctm = (L1Ctm_Module*) 0;  
   L1SP_EnableSpeechEnhancement(true);    
}  // end of L1Ctm_Close(~)

void L1Ctm_StartNegotiation(void)
{   
   uint32 savedMask;
   
   L1CTM_TRACE_FUNC( L1CTM_START_NEGOTIATION );   
   
   ASSERT(l1ctm != (L1Ctm_Module*) 0); 
   ASSERT(l1ctm->interface == DIRECT_MODE); 
   savedMask = SaveAndSetIRQMask();
   if(!(l1ctm->FLAGS & LCF_NEGOTIATION))
      l1ctm->FLAGS |= LCF_NEGOTIATION_REQ;      
   RestoreIRQMask( savedMask );          
}

uint32 L1Ctm_TxPutText(const uint8 *text, uint32 len, uint32 *left_space)
{
   uint8 *ptr_text;
   uint32 write_count, count1, count2, I;
   int32 total_space;
   
   L1CTM_TRACE_FUNC( L1CTM_TX_PUT_TEXT );

   ASSERT(l1ctm != (L1Ctm_Module*) 0); 
   ASSERT(l1ctm->state == L1CTM_CONNECTED_STATE);
   
   ptr_text = (uint8*)text;
   
   total_space = l1ctm->ul_ctm_buf_read - 1 - l1ctm->ul_ctm_buf_write; 
   if(total_space < 0)
      total_space += UL_CTM_BUF_LEN; 
      
   if(total_space > len)
   {
      if(left_space)
         *left_space = total_space - len; 
      write_count = len;
   }
   else
   { 
      if(left_space)
         *left_space = 0;      
      write_count = total_space;
   }
   
   if(write_count > 0)
   {
      if(l1ctm->ul_ctm_buf_read == 0)  
         count1 = UL_CTM_BUF_LEN - 1 - l1ctm->ul_ctm_buf_write;    
      else if(l1ctm->ul_ctm_buf_read > l1ctm->ul_ctm_buf_write)   
         count1 = l1ctm->ul_ctm_buf_read-1 - l1ctm->ul_ctm_buf_write;                  
      else
      {// this case include l1ctm->ul_ctm_buf_read == l1ctm->ul_ctm_buf_write
         count1 = UL_CTM_BUF_LEN - l1ctm->ul_ctm_buf_write;   
         count2 = l1ctm->ul_ctm_buf_read-1; 
      }   
   
      if(write_count > count1)
      {
         for(I = count1; I > 0; I --)
            l1ctm->ul_ctm_buf[l1ctm->ul_ctm_buf_write++] = *ptr_text++;
      
         l1ctm->ul_ctm_buf_write = 0;
         for(I = write_count - count1; I > 0; I --)
            l1ctm->ul_ctm_buf[l1ctm->ul_ctm_buf_write++] = *ptr_text++;
      }
      else 
      {
         for(I = write_count; I > 0; I --) 
            l1ctm->ul_ctm_buf[l1ctm->ul_ctm_buf_write++] = *ptr_text++;
      
         l1ctm->ul_ctm_buf_write &= (UL_CTM_BUF_LEN - 1);     
      }
   } 
      
   return write_count; 
}

uint32 L1Ctm_RxGetText(uint8 *text, uint32 len, uint32 *left_count)
{
   uint8 *ptr_text;
   uint32 read_count, count1, count2, I;
   int32 total_char;
   
   L1CTM_TRACE_FUNC( L1CTM_RX_GET_TEXT );
   
   ASSERT(l1ctm != (L1Ctm_Module*) 0); 
   ASSERT(l1ctm->state == L1CTM_CONNECTED_STATE);
   
   ptr_text = text;
   
   total_char = l1ctm->dl_ctm_buf_write - l1ctm->dl_ctm_buf_read; 
   
   if(total_char < 0)
      total_char += DL_CTM_BUF_LEN; 

   if(total_char > len)
   {
      if(left_count)
         *left_count = total_char - len;
      read_count = len;
   }
   else 
   {
      if(left_count)
         *left_count = 0;
      read_count = total_char;
   }    
   
   if(read_count > 0)
   {

      if(l1ctm->dl_ctm_buf_write > l1ctm->dl_ctm_buf_read)   
         count1 = l1ctm->dl_ctm_buf_write - l1ctm->dl_ctm_buf_read;                  
      else
      {// this case include l1ctm->dl_ctm_buf_write == 0
         count1 = DL_CTM_BUF_LEN - l1ctm->dl_ctm_buf_read;   
         count2 = l1ctm->dl_ctm_buf_write; 
      }   
      
      if(read_count > count1)
      {
         for(I = count1; I > 0; I --)
            *ptr_text++ = l1ctm->dl_ctm_buf[l1ctm->dl_ctm_buf_read++];
      
         l1ctm->dl_ctm_buf_read = 0;
         for(I = read_count - count1; I > 0; I --)
            *ptr_text++ = l1ctm->dl_ctm_buf[l1ctm->dl_ctm_buf_read++];             
      }
      else 
      {
         for(I = read_count; I > 0; I --) 
            *ptr_text++ = l1ctm->dl_ctm_buf[l1ctm->dl_ctm_buf_read++]; 
               
         l1ctm->dl_ctm_buf_read &= (DL_CTM_BUF_LEN - 1); 
      }
   }   
      
   return read_count;        
}

/*===========================MED_L1Audio_Integrate_Handler===========================================*/

#ifdef DIRECT_MODE_AUTO_SEND_TEXT_FILE  
void l1ctm_callback1(L1Ctm_Event event, void *data)
{
   kal_prompt_trace(MOD_L1SP, "L1Ctm Event %d" , event);   
   switch(event)
   {            
      case CTM_CHAR_SENT:
         ul_text_sent ++;
         if(ul_text_sent == UTF8_TEXT_BUF_LEN)
         {
            Put_Text_File_Msg_Info *put_text_msg_info;   
            ul_text_sent = 0;                            
            put_text_msg_info = (Put_Text_File_Msg_Info *)get_ctrl_buffer(sizeof(Put_Text_File_Msg_Info));
            put_text_msg_info->read_text_file_hdl = f_ul_ctm_text_hdl;    
            put_text_msg_info->text_buf_ptr = (uint8 *)Ul_CTM_Text_Buf;
            put_text_msg_info->write_text_len = ul_ctm_text_buf_write_count;
            put_text_msg_info->read_text_len = ul_ctm_text_buf_read_count;
            aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, PUT_TEXT_TO_UL_CTM_BUF_REQUEST, (void*)put_text_msg_info);       
         }   
         break;
      case CTM_CHAR_RECEIVED: 
         ul_text_received ++;
         if(ul_text_received == UTF8_TEXT_BUF_LEN)
         {
            Dummy_Buffer_Msg_Info *dummy_buf_msg_info; 
            ul_text_received = 0; 
            dummy_buf_msg_info = (Dummy_Buffer_Msg_Info *)get_ctrl_buffer(sizeof(Dummy_Buffer_Msg_Info));                      
            dummy_buf_msg_info->dummy_buf_ptr = (uint8 *)Dummy_Dl_CTM_Text_Buf; 
            dummy_buf_msg_info->dummy_buf_size = UTF8_TEXT_BUF_LEN;
            aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, UL_CTM_BUF_DUMMY_READ_REQUEST, (void*)dummy_buf_msg_info); 
         }  
         break;
   }   
}
#endif  

void l1ctm_callback2(L1Ctm_Event event, void *data)
{
   kal_prompt_trace(MOD_L1SP, "L1Ctm Event %d" , event);      
}

#if defined(L1CTM_DEBUG_MODE)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void med_integrate_debug_hdlr(kal_uint32 msg, void *msg_info)
{
   uint32 savedMask,read_count, write_count;             
   File_Read_Msg_Info *file_read_info;
   File_Write_Msg_Info *file_write_info;
   Put_Text_File_Msg_Info *put_text_msg_info;
   Dummy_Buffer_Msg_Info *dummy_buf_msg_info; 
      
    switch(msg)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      case START_NEGOTIATION_REQUEST:
          L1Ctm_StartNegotiation();
          break;
      #if defined(UL_GET_PCM_FROM_FILE)   
      case UL_READ_PCM_FILE_REQUEST:          
         file_read_info = (File_Read_Msg_Info *)msg_info;                         
         FS_Read(file_read_info->read_file_hdl, file_read_info->read_buf, file_read_info->read_len, &read_count);                    
         ulInPcmReadBufDataCount[ulInPcmReadBufIdx^0x1] = read_count; 
         savedMask = SaveAndSetIRQMask();                 
         if(read_count != file_read_info->read_len)         
            ulInPcmReadFlag |= (READ_EOF_FLAG + HAS_ANOTHER_BUF_DATA_FLAG);
         else 
            ulInPcmReadFlag |= HAS_ANOTHER_BUF_DATA_FLAG;                         
         RestoreIRQMask( savedMask );         
         break;
      #endif 
      
      #if defined(DL_GET_PCM_FROM_FILE)   
      case DL_READ_PCM_FILE_REQUEST:          
         file_read_info = (File_Read_Msg_Info *)msg_info;                                            
         FS_Read(file_read_info->read_file_hdl, file_read_info->read_buf, file_read_info->read_len, &read_count);                    
         dlInPcmReadBufDataCount[dlInPcmReadBufIdx^0x1] = read_count; 
         savedMask = SaveAndSetIRQMask();                 
         if(read_count != file_read_info->read_len)         
            dlInPcmReadFlag |= (READ_EOF_FLAG + HAS_ANOTHER_BUF_DATA_FLAG);
         else 
            dlInPcmReadFlag |= HAS_ANOTHER_BUF_DATA_FLAG;                         
         RestoreIRQMask( savedMask );                              
         break;
      case DL_READ_BFI_FILE_REQUEST: 
         file_read_info = (File_Read_Msg_Info *)msg_info;
         
         FS_Read(file_read_info->read_file_hdl, file_read_info->read_buf, file_read_info->read_len, &read_count);
         dlInBfiReadBufDataCount[dlInBfiReadBufIdx^0x1] = read_count; 
         savedMask = SaveAndSetIRQMask();
         if(read_count != file_read_info->read_len)         
            dlInBfiReadFlag |= (READ_EOF_FLAG + HAS_ANOTHER_BUF_DATA_FLAG);
         else 
            dlInBfiReadFlag |= HAS_ANOTHER_BUF_DATA_FLAG;                
         RestoreIRQMask( savedMask );                
         //kal_prompt_trace(MOD_L1SP, "case6, dlInBfiReadBufIdx=%x, read_count=%x, dlInBfiReadFlag=%x", dlInBfiReadBufIdx, read_count, dlInBfiReadFlag);
         break;
      #endif 
      
      
      #if defined(UL_IN_PCM_RECORD)         
      case UL_IN_WRITE_FILE_REQUEST:                               
         file_write_info = (File_Write_Msg_Info *)msg_info;               
      
         FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count);                    
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;
         
         savedMask = SaveAndSetIRQMask();                              
         ulInPcmWriteFlag = 0;
         RestoreIRQMask( savedMask );
       
         break;
      #endif 
      
      #if defined(DL_IN_PCM_RECORD)
      case DL_IN_WRITE_FILE_REQUEST:         

         file_write_info = (File_Write_Msg_Info *)msg_info;        
      
         FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count);                    
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;    
         
         savedMask = SaveAndSetIRQMask();                          
         dlInPcmWriteFlag = 0;
         RestoreIRQMask( savedMask );
         
         break;
      #endif 
      
      #if defined(UL_OUT_PCM_RECORD) 
      case UL_OUT_WRITE_FILE_REQUEST:         
         file_write_info = (File_Write_Msg_Info *)msg_info;  
         
         FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count);                    
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;    
         
         savedMask = SaveAndSetIRQMask();                          
         ulOutPcmWriteFlag = 0;
         RestoreIRQMask( savedMask );
         
         break;
      #endif 
      
      #if defined(DL_OUT_PCM_RECORD)       
      case DL_OUT_WRITE_FILE_REQUEST:         
         file_write_info = (File_Write_Msg_Info *)msg_info;  
         
         FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count);                    
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;
         
         savedMask = SaveAndSetIRQMask();                               
         dlOutPcmWriteFlag = 0;
         RestoreIRQMask( savedMask );
                                        
         break; 
      #endif     
         
      #if defined(RECORD_DSP_RXBUFFER)       
      case DSP_REC_RX_BUF0_REQUEST:         
         file_write_info = (File_Write_Msg_Info *)msg_info;  
         //kal_prompt_trace(MOD_L1SP, "SYSCLOCK %d", TMD_System_Clock);
         ASSERT(FS_NO_ERROR == FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count));
         //kal_prompt_trace(MOD_L1SP, "SYSCLOCK %d", TMD_System_Clock);
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;
         savedMask = SaveAndSetIRQMask();                               
         dsp_rec_rx_buf0_write_ok = 1;
         RestoreIRQMask( savedMask );
         break; 
      case DSP_REC_NB_RESULT0_REQUEST:         
         file_write_info = (File_Write_Msg_Info *)msg_info;  
         ASSERT(FS_NO_ERROR == FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count));
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;
         savedMask = SaveAndSetIRQMask();                               
         dsp_rec_nb_result0_write_ok = 1;
         RestoreIRQMask( savedMask );
         break; 
      case DSP_REC_FN_REQUEST:         
         file_write_info = (File_Write_Msg_Info *)msg_info;  
         ASSERT(FS_NO_ERROR == FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count));
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;
         savedMask = SaveAndSetIRQMask();                               
         dsp_rec_fn_write_ok = 1;
         RestoreIRQMask( savedMask );
         break; 
//      case DSP_REC_EQ_SO0_REQUEST:         
//         file_write_info = (File_Write_Msg_Info *)msg_info;  
//         ASSERT(FS_NO_ERROR == FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count));
//         if(write_count != file_write_info->write_len)
//            sdCardNotFullFlag = 0;
//         savedMask = SaveAndSetIRQMask();                               
//         dsp_rec_eq_so0_write_ok = 1;
//         RestoreIRQMask( savedMask );
//         break; 
      #endif // RECORD_DSP_RXBUFFER  
         
      case GENERAL_WRITE_FILE_REQUEST:
         file_write_info = (File_Write_Msg_Info *)msg_info;         
         FS_Write(file_write_info->write_file_hdl, file_write_info->write_buf, file_write_info->write_len, &write_count);                       
         if(write_count != file_write_info->write_len)
            sdCardNotFullFlag = 0;
         break;  
         
      #if defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
      case PUT_TEXT_TO_UL_CTM_BUF_REQUEST:
         put_text_msg_info = (Put_Text_File_Msg_Info *)msg_info;
         write_count = L1Ctm_TxPutText((const uint8 *)put_text_msg_info->text_buf_ptr, put_text_msg_info->write_text_len, NULL);
         ul_ctm_text_buf_write_count = 0;
         if(write_count != put_text_msg_info->write_text_len)
            ASSERT(false);
         if(ul_ctm_text_buf_read_count > 0)
         {
            FS_Read(put_text_msg_info->read_text_file_hdl, put_text_msg_info->text_buf_ptr, put_text_msg_info->read_text_len, &read_count);
            ul_ctm_text_buf_write_count = read_count; 
            if(read_count != put_text_msg_info->read_text_len)
               ul_ctm_text_buf_read_count = 0;                        
         }      
         break;
      
      case UL_CTM_BUF_DUMMY_READ_REQUEST:    
         dummy_buf_msg_info = (Dummy_Buffer_Msg_Info *)msg_info;                     
         read_count = L1Ctm_RxGetText(dummy_buf_msg_info->dummy_buf_ptr, dummy_buf_msg_info->dummy_buf_size, NULL);
         if(read_count != dummy_buf_msg_info->dummy_buf_size)
            ASSERT(false);          
      #endif 
      
                               
    }
    if(msg_info != NULL)
      free_ctrl_buffer(msg_info); 
}
#endif

#if defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
void l1ctm_save_decoded_char(uint8 ch, uint8 special_ch)
{
#if defined(L1CTM_DEBUG_MODE)   
   File_Write_Msg_Info *write_msg_info;
#endif 
#ifdef SAVE_ONLY_TTY_CHAR
   if(special_ch == BURST_START_CHAR || special_ch == BURST_END_CHAR)
      ch = special_ch;
   else
   {
      if(ch >= 'a' && ch <= 'z')
         ch -= 'a' - 'A';
      else if(!(ch >= 'A' && ch <= 'Z') && strchr(TTY_CHAR_TAB, ch) == NULL)
         return;
      else if(ch == 0)
          return;
   }
#endif // SAVE_ONLY_TTY_CHAR
   Dl_CTM_Text_Buf[dl_ctm_text_buf_idx][dl_ctm_text_buf_write_count++] = ch;
   if(dl_ctm_text_buf_write_count == UTF8_TEXT_BUF_LEN)
   {                           
      write_msg_info = (File_Write_Msg_Info *)get_ctrl_buffer(sizeof(File_Write_Msg_Info));
      write_msg_info->write_file_hdl = f_dl_ctm_text_hdl;
      write_msg_info->write_buf = (uint8 *)Dl_CTM_Text_Buf[dl_ctm_text_buf_idx];
      write_msg_info->write_len = UTF8_TEXT_BUF_LEN;
            
      aud_send_in_proc_call_req( MOD_L1SP, med_integrate_debug_hdlr, GENERAL_WRITE_FILE_REQUEST, (void*)write_msg_info);
     
      dl_ctm_text_buf_idx ^= 0x1;
      dl_ctm_text_buf_write_count = 0;
   }                                    
}
#endif // defined(BAUDOT_MODE_TEST) || defined(DIRECT_MODE_AUTO_SEND_TEXT_FILE)
#else                                                                        
char dummy_l1ctm_c;    /* define a dummy variable to avoid warning message */
#endif // __CTM_SUPPORT__
