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
 * am.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio Manager(AM) for Audio Mode Changes
 *
 * Author:
 * -------
 * -------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *******************************************************************************/
#include "media.h"
#include "afe.h"
#if defined(MT6223) || defined(MT6223P)
#include "dcmgr.h"
#endif

#if  !defined(MT6205B)
#include "ddload.h"
#endif

#include "wma_drv.h"

/* ========================================================================= */
uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );
int8     L1D_GetT2( void );
void     L1D_CCCDReset( void );
void     L1D_ENABLE_DTIRQ( void );
uint16   L1D_Get_Win_TQ_WRAP( void );
/* ========================================================================= */
#define  AM_STATE_KEYTONE  (1<<L1SP_KEYTONE  )
#define  AM_STATE_TONE     (1<<L1SP_TONE     )
#define  AM_STATE_SPEECH   (1<<L1SP_SPEECH   )
#define  AM_STATE_VOIP   (1<<(L1SP_MAX_AUDIO+0)   )
#define  AM_STATE_VOICE    (1<<L1SP_VOICE    )
#define  AM_STATE_DAI      (1<<L1SP_DAI      )
#define  AM_STATE_AUDIO    (1<<L1SP_AUDIO  )
#if defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define  AM_STATE_SND_EFFECT  (1<<L1SP_SND_EFFECT)
#endif
#define  AM_STATE_AvBT     (1 << (L1SP_MAX_AUDIO + 1))

#define AM_CONFLICT_STATE (AM_STATE_SPEECH + AM_STATE_VOIP + AM_STATE_VOICE + AM_STATE_AUDIO) 

/*========  Speech State : record features in dedicated-mode speech  ========= */    
#define SP_STATE_VMR          (1 << 0)
#define SP_STATE_PCM8K_REC    (1 << 1)
#define SP_STATE_PCM4WAY      (1 << 2)
#define SP_STATE_CLOSING      (1 << 3)

/*========  VoIP State ======================================= */    
#define VOIP_STATE_VMR          (1 << 0)





/*=============  DSP&AFE IO types  ============================ */
#define NORMAL_MODE        0
#define DAI_MODE           1
#define BT_CORDLESS_MODE   2
#define BT_EARPHONE_MODE   3

/*============= low byte flags of *DP_AUDIO_PAR ============================ */
#define VOICE_INPUT_FILTER_FLAG     0x1 
#define VOICE_OUTPUT_FILTER_FLAG    0x2
#define VOICE_WB_AMR_FLAG           0x8 
#define VOICE_16K_SWITCH_FLAG       0x10                
#define VOICE_MIC_MUTE_FLAG         0x20
#define VOICE_SIDETONE_FILTER_FLAG  0x40 

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#if defined(__MA_L1__) || defined(MT6268T)
#define  VBI_Reset()          { *SHARE2_M2DI1 = 0x0838; \
                                L1Audio_Msg_VBI_RESET();\
                              }
#else
#define  VBI_Reset()          { *SHARE2_M2DI1 = 0x0838; }
#endif
#define  VBI_End()            { *SHARE2_M2DI1 = 0x0839; }
#define  DSP_IO4_On()         { *SHARE2_D2MCON |= 0x10;  }
#define  DSP_IO5_On()         { *SHARE2_D2MCON |= 0x20;  }
#else
#define  VBI_Reset()          { *SHARE_M2DI1 = 0x0838; }
#define  VBI_End()            { *SHARE_M2DI1 = 0x0839; }
#define  DSP_IO4_On()         { *SHARE_D2MCTL |= 0x10;  }
#define  DSP_IO5_On()         { *SHARE_D2MCTL |= 0x20;  }
#endif
/* =========== Platform that DSP support upsample ========================== */
#define DSP_SUPPORT_UPSAMPLE  ( defined(MT6217) || defined(MT6226_S01) || defined(MT6226_S02) || defined(MT6226M_S01) || defined(MT6226M_S02) || defined(MT6227_S01) || defined(MT6227_S02) || defined(MT6227D) || defined(MT6226D) || \
                                defined(MT6225) || defined(MT6228_S01) || defined(MT6228_S02) || defined(MT6229_S01) || defined(MT6229_S02) || defined(MT6230_S01) || defined(MT6230_S02) || \
                                defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6227S) || defined(MT6235) || defined(MT6238) )

/* ========================================================================= */

typedef struct {
   void     (*code)(uint32);
   uint32   data;
} AM_QFunction;

static struct {
   uint16   state;
   uint16   speech_mode;
   int16    speech_off_delay;
   int8     sub_channel;
#if defined(__BT_SUPPORT__)
   uint16  bt_digital_gain;
   uint16  bt_mic_gain;
#endif
   RINGBUFFER_T(AM_QFunction,8) qfunc;
   uint8    speech_state;
   uint8	   voip_state;   
   uint8    io_type;
   bool     fLoopBack;
#if defined(MT6219) || defined(MT6217)
   bool     need_update_coeff;
   int16    in_coeff_tmp[45];
   int16    out_coeff_tmp[45];
#endif
#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))
   bool     toneLoopbackRec;
#endif
   bool     sp3g_flag;  
} am;

/* --------------------------------------------------------------------------*/
static void AM_Enqueue( void (*code)(uint32), uint32 data )
{
   uint32 savedMask;
   AM_QFunction qf;

   savedMask = SaveAndSetIRQMask();
   L1D_ENABLE_DTIRQ();

   qf.code = code;
   qf.data = data;
   RB_PUT( am.qfunc, qf );

   RestoreIRQMask(savedMask);
}

/* --------------------------------------------------------------------------*/
#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define AM_WriteAspParam(asp_type,asp_fs,del_w,del_m)             \
{                                                                 \
   *DP_ASP_TYPE    = asp_type;                                    \
   *DP_ASP_FS      = asp_fs;                                      \
   *DP_ASP_DEL_W   = del_w;                                       \
   *DP_ASP_DEL_M   = del_m;                                       \
   DSP_TONE_FORCE_KT_8K = 0x8000;                                 \
}
#else
#define AM_WriteAspParam(asp_type,asp_fs,del_w,del_m)             \
{                                                                 \
   *DP_ASP_TYPE    = asp_type;                                    \
   *DP_ASP_FS      = asp_fs;                                      \
   *DP_ASP_DEL_W   = del_w;                                       \
   *DP_ASP_DEL_M   = del_m | 0x8000;                              \
}
#endif

/* --------------------------------------------------------------------------*/

#define AM_WriteSpeechParameters( sc_flags, sc_mode, sd_mode )    \
{                                                                 \
   *DP_SC_MODE          = sd_mode | (sc_mode << 8);               \
   *DP_SC_VAD           = (sc_mode>2)? 1:0;                       \
   *DP_SC_FLAGS         = sc_flags;                               \
}

/* ========================================================================= */
const  uint16  DSP_PCM_DELAY_TABLE_SUBCH0[13][2] =
{  /*  SE      SD  */                    /*   SE  SD   */
   { (0x00B5), 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090), 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B), 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046), 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1), 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C), 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077), 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052), 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D), 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8), 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083), 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E), 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039), 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

const  uint16  DSP_PCM_DELAY_TABLE_SUBCH1[13][2] =
{  /*  SE      SD  */                    /*   SE  SD   */
   { (0x00B5)+0x25, 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090)+0x25, 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B)+0x25, 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046)+0x25, 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1)+0x25, 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C)+0x25, 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077)+0x25, 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052)+0x25, 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D)+0x25, 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8)+0x25, 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083)+0x25, 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E)+0x25, 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039)+0x25, 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};
/*....................................*/

#ifdef  L1D_TEST
const  uint16  DSP_PCM_DELAY_TABLE2[13][3] =
{  /*  SE             SD   */                   /*   SE   SD   */
   /*(78Mhz)-0x19=52Mhz    */
   { (0x0047)-0x19, 0x0274 },  /* T2 = 0 /13 */ /*  1.9  18.8  */
   { (0x00C2)-0x19, 0x024F },  /* T2 = 1 /14 */ /*  5.8  17.7  */
   { (0x009D)-0x19, 0x022A },  /* T2 = 2 /15 */ /*  4.7  16.6  */
   { (0x0079)-0x19, 0x02A5 },  /* T2 = 3 /16 */ /*  3.6  20.3  */
   { (0x0054)-0x19, 0x0280 },  /* T2 = 4 /17 */ /*  2.5  19.2  */
   { (0x002F)-0x19, 0x025C },  /* T2 = 5 /18 */ /*  1.4  18.1  */
   { (0x00AA)-0x19, 0x0237 },  /* T2 = 6 /19 */ /*  5.1  17.0  */
   { (0x0085)-0x19, 0x0212 },  /* T2 = 7 /20 */ /*  3.9  15.9  */
   { (0x0060)-0x19, 0x028D },  /* T2 = 8 /21 */ /*  2.8  19.5  */
   { (0x003B)-0x19, 0x0268 },  /* T2 = 9 /22 */ /*  1.7  18.4  */
   { (0x0091)-0x19, 0x0243 },  /* T2 = 10/23 */ /*  4.3  17.3  */
   { (0x006C)-0x19, 0x021E },  /* T2 = 11/24 */ /*  3.2  16.2  */
   { (0x0047)-0x19, 0x0274 }   /* T2 = 12/25 */ /*  1.9  18.8  */
};

const  uint16  DSP_WB_AMR_PCM_DELAY_TABLE2[13][3] =
{  /*  SE             SD   */                   /*   SE   SD   */
   /*(78Mhz)-0x41=52Mhz    */
   { (0x0047)-0x41, (0x0274)-0x14E },  /* T2 = 0 /13 */ /*  1.9  18.8  */
   { (0x00C2)-0x41, (0x024F)-0x14E },  /* T2 = 1 /14 */ /*  5.8  17.7  */
   { (0x009D)-0x41, (0x022A)-0x14E },  /* T2 = 2 /15 */ /*  4.7  16.6  */
   { (0x0079)-0x41, (0x02A5)-0x14E },  /* T2 = 3 /16 */ /*  3.6  20.3  */
   { (0x0054)-0x41, (0x0280)-0x14E },  /* T2 = 4 /17 */ /*  2.5  19.2  */
   { (0x002F)-0x41, (0x025C)-0x14E },  /* T2 = 5 /18 */ /*  1.4  18.1  */
   { (0x00AA)-0x41, (0x0237)-0x14E },  /* T2 = 6 /19 */ /*  5.1  17.0  */
   { (0x0085)-0x41, (0x0212)-0x14E },  /* T2 = 7 /20 */ /*  3.9  15.9  */
   { (0x0060)-0x41, (0x028D)-0x14E },  /* T2 = 8 /21 */ /*  2.8  19.5  */
   { (0x003B)-0x41, (0x0268)-0x14E },  /* T2 = 9 /22 */ /*  1.7  18.4  */
   { (0x0091)-0x41, (0x0243)-0x14E },  /* T2 = 10/23 */ /*  4.3  17.3  */
   { (0x006C)-0x41, (0x021E)-0x14E },  /* T2 = 11/24 */ /*  3.2  16.2  */
   { (0x0047)-0x41, (0x0274)-0x14E }   /* T2 = 12/25 */ /*  1.9  18.8  */
};
#endif

/*....................................*/
const  uint16  DSP_PCM_MARGIN_TABLE[] = {
   0x38+(16<<10)+(2<<8),     /* 1.2 : FR        */
   0x38+(12<<10)+(2<<8),     /* 1.2 : HR        */
   0x38+(16<<10)+(2<<8),     /* 1.2 : EFR       */   
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 12.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 10.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.95  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.4   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 6.7   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.9   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.15  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 4.75  */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   0x96+(16<<10)+(2<<8),     /* AMR-WB 6.60     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 8.85     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 12.65    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 14.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 15.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 18.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 19.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.05    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.85    */
#endif
};

/*....................................*/

#ifdef  L1D_TEST
const  uint16  DSP_PCM_MARGIN_TABLE2[] = {
   0x45+(16<<10)+(2<<8),     /* 1.87 : FR       */
   0x46+(12<<10)+(2<<8),     /* 1.89 : HR       */
   0x45+(16<<10)+(2<<8),     /* 1.87 : EFR      */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 12.2 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 10.2 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 7.95 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 7.4  */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 6.7  */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 5.9  */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 5.15 */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR 4.75 */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 6.60     */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 8.85     */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 12.65    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 14.25    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 15.85    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 18.25    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 19.85    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 23.05    */
   0x45+(16<<10)+(2<<8),     /* 1.87 : AMR-WB 23.85    */
#endif
};
#endif

#if DSP_SUPPORT_UPSAMPLE

/* FIR Coefficients for Upsampling */
const signed short UPSAMPLE_FIR[16] = 
{ 
    136,  -749, -5687,  9748, 20285, -1568, -3619,   252, 
    252, -3619, -1568, 20285,  9748, -5687,  -749,   136  
};

static void AM_Write_Upsampling_Coeff(void)
{
   int I;
   const int16 *ptr;
   volatile uint16* dsp_ptr;

#if defined(MT6217)
   dsp_ptr = DSP_PM_ADDR(0, 0x3F70);
#elif defined(MT6226_S01) || defined(MT6226_S02) || defined(MT6226M_S01) || defined(MT6226M_S02) || defined(MT6227_S01) || defined(MT6227_S02) || defined(MT6227D) || defined(MT6226D)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FE0);
#elif defined(MT6228_S01) || defined(MT6228_S02)
   dsp_ptr = DSP_PM_ADDR(0, 0x3F95);
#elif defined(MT6229_S01) || defined(MT6229_S02) || defined(MT6230_S01) || defined(MT6230_S02) || defined(MT6235) || defined(MT6238)
   dsp_ptr = DSP_PM_ADDR(0, 0x3F3A);
#elif defined(MT6223) || defined(MT6223P)
   dsp_ptr = DSP_PM_ADDR(0, 0x39DA);
#elif defined(MT6225)
   dsp_ptr = DSP_PM_ADDR(0, 0x3F95);
#elif defined(MT6268T)
   dsp_ptr = DSP_PM_ADDR(0, 0x3F3A);
#elif defined(MT6227S)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FE0);
#else
   #error Need DSP guys give the Upsample FIR address
#endif

   ptr = UPSAMPLE_FIR;
   for (I=15; I>=0; I--)
      *dsp_ptr++ = *ptr++;

}
#endif

static void AM_Write_Speech_Delay( uint16 speech_mode, int8 sub_channel, uint16 delay )
{
   uint16 n = (uint16)L1D_GetT2();

   if( n >= 13 )
      n -= 13;
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   if (speech_mode>=0x20)
      speech_mode-=(0x20-0x0B);
#endif
   ASSERT(speech_mode<(sizeof(DSP_PCM_MARGIN_TABLE)/sizeof(DSP_PCM_MARGIN_TABLE[0])));
#ifdef L1D_TEST
   if((PollLoopbackMode()==1)||(PollLoopbackMode()==2))
   {
      if ( speech_mode < 0x0B )
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE2[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE2[n][1];
         
      }
      else
      {
         *DP_DEL_PCM_R     = DSP_WB_AMR_PCM_DELAY_TABLE2[n][0];
         *DP_DEL_PCM_W     = DSP_WB_AMR_PCM_DELAY_TABLE2[n][1];
      }
      *DP_MARGIN_PCM_W  = DSP_PCM_MARGIN_TABLE2[speech_mode];
   }
   else
#endif
   {
      if (sub_channel == 0)
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH0[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH0[n][1];
      }
      else
      {
         *DP_DEL_PCM_R     = DSP_PCM_DELAY_TABLE_SUBCH1[n][0];
         *DP_DEL_PCM_W     = DSP_PCM_DELAY_TABLE_SUBCH1[n][1];
         n += 13;
      }
      L1Audio_Msg_AM_DELAY_TABLE( n );
      *DP_MARGIN_PCM_W  = DSP_PCM_MARGIN_TABLE[speech_mode];
   }
   *DP_SC_EVLUATE_DELAY = delay;
}

const  uint16  DSP_PCM_IDLE_DELAY_TABLE[7][3] =
{ 
   { 0x20, 0x20 , 0x4B+(16<<10)+(2<<8)}, // for AMR codec 
   { 0x20, 0x20 , 0x96+(16<<10)+(2<<8)}, // for speech codec except AMR 
   { 0x0A, 0x0A , 0x4F+(16<<10)+(2<<8)}, // for PCM8K_Playback.....
   { 0x0A, 0x0A , 0x28+(16<<10)+(2<<8)}, // for PCM16K  
   { 0x0A, 0x0A , 0x9F+(16<<10)+(2<<8)},  // for Keytone/Tone/ 
   { 0x0A, 0x0A , 0x4F+(16<<10)+(2<<8)}, // for PCM8K_Playback.....
   { 0x10, 0x130, 0x96+(16<<10)+(2<<8)}  // for 3G Speech    
};

static void AM_Write_Idle_Delay( uint8 type )
{
   *DP_DEL_PCM_R        = DSP_PCM_IDLE_DELAY_TABLE[type][0];
   *DP_DEL_PCM_W        = DSP_PCM_IDLE_DELAY_TABLE[type][1];
   *DP_MARGIN_PCM_W     = DSP_PCM_IDLE_DELAY_TABLE[type][2];
   *DP_SC_EVLUATE_DELAY = 0;
}


/* Note: The speech pattern length for amr-wb can be calculated from
lenSpeechBitsAMR_WB in amr_table.h; therefore, remove them out.
Those for amr might be removed if vm.c does not handle amr any more. */
static const uint8 SpeechPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16 + 1),       /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
#endif
};

uint16 AM_GetSpeechPatternLength( uint8 speech_mode )
{
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;
   ASSERT(speech_mode<(sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])));
   return (uint16)SpeechPatternLength[speech_mode];
}

static const uint16 SpeechSilencePattern[][17] = {
   {  0x4820,0xD617,0x0284,0x2480,0x9249,0x8924,0x8002,0x4924,       /* FR       */
      0x2492,0x0289,0x2480,0x9249,0x8924,0x8002,0x4924,0x2492,
      0x0009                                                   },
   {  0x4E20,0x875E,0x5473,0x8482,0x00E9,0x0000,0x0000         },    /* HR       */
   {  0x7A10,0x092D,0xB55F,0x7C06,0x185C,0xDE06,0x4230,0x0103,       /* EFR      */
      0xA012,0x001A,0x0000,0x0000,0x0D6C,0x0000,0x0000,0x0000  },
   {  0x00e2,0x5dfc,0xf095,0xcd4e,0x24da,0x0e04,0xf0fb,0x4f2e,       /* AMR12.2  */
      0x4430,0x9fa8,0x0319,0x56c0,0xc144,0x0278,0x70ea,0x0004  },
   {  0xe00a,0xf2e7,0x516b,0x19a1,0xc10d,0x145a,0x4c96,0x25e0,       /* AMR10.2  */
      0x5ce6,0x17b9,0x0982,0x225d,0x00c4                       },
   {  0x033c,0xe5cd,0xd9fb,0x387f,0x420c,0x8c99,0x58d7,0x1156,       /* AMR7.95  */
      0x397f,0x1074                                            },
   {  0xe00a,0xf2e7,0x9ac5,0x4433,0x185b,0x3e05,0xdc64,0xc886,       /* AMR7.4   */
      0xcd2e,0x0000                                            },
   {  0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,       /* AMR6.7   */
      0x0002                                                   },
   {  0xe00a,0xf2e7,0xb196,0xa8ae,0xbcb7,0x6fb9,0x0193,0x002e  },    /* AMR5.9   */
   {  0x3c0a,0x7e51,0x652c,0x5e91,0xd023,0xea5a,0x005b         },    /* AMR5.15  */
   {  0x3c0a,0x3e51,0x6529,0x3a49,0x977f,0x3565                },    /* AMR4.75  */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   {0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,0x0002},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}     /* AMR-WB 6.60  */
#endif
};

void AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode )
{
#ifndef  L1D_TEST
   const uint16 *pat_info;
   uint32 I, len;
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;

   pat_info = SpeechSilencePattern[speech_mode];
   len = (uint16)SpeechPatternLength[speech_mode];

   *addr++ = info;
   for( I = 0; I < len; I++ )
      *addr++ = *pat_info++;
#endif
}

/* -------------------------------------------------------------------------- */
bool AM_AudioManager( bool handover, uint16 speech_mode, int8 sub_channel )
{
   AM_QFunction func;

   L1Audio_Msg_SPE_DEBUG( DP_SPE_debug1, DP_SPE_debug2 );
   if( speech_mode != am.speech_mode )
      am.speech_mode = speech_mode;

   if( sub_channel != am.sub_channel )
      am.sub_channel = sub_channel;

   if( am.speech_off_delay > 0 ) {
      if( --am.speech_off_delay == 0 )
         AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode );
   }

   if( handover && (am.state & AM_STATE_DAI) == 0 && (!am.sp3g_flag) ) {
      if( am.state & AM_STATE_SPEECH ) {
         if(am.fLoopBack){   
            AM_WriteSpeechParameters(0x063a, am.speech_mode, am.speech_mode );      
         }else{
            AM_WriteSpeechParameters( (*DP_SC_FLAGS&0xF800) | 0x063B, am.speech_mode, am.speech_mode );                          
         }    
         AM_Write_Speech_Delay( am.speech_mode, am.sub_channel, L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT );
         AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode );

         if( am.speech_mode > 2 &&  am.speech_mode <=10)
            *DP_TX_TCH_S(0,17) = am.speech_mode << 8;
         L1Audio_Msg_AM_Handover( am.speech_mode );
#if defined(__MA_L1__) || defined(MT6268T)
         L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(am.speech_mode), L1SP_Speech_Codec_Mode(am.speech_mode) );
#endif
         VBI_Reset();
      }
      else {      /* Not in speech mode */
         AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode );
      }
   }
   else if( !RB_EMPTY( am.qfunc ) ) {
      RB_GET( am.qfunc, func );
      func.code( func.data );
   }
   else {
      AFE_Manager();
   }
   return (bool)(am.state != 0);
}

void AM_FlushQFunction( void )
{
#ifndef  L1D_TEST
   while( !RB_EMPTY(am.qfunc) )
      kal_sleep_task( 1 );
#endif
}
/* ========================================================================= */
/*   Interface Functions                                                     */
/* ========================================================================= */
static uint8 audio_coeff_flag = 0;
#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#define COMPEN_FILTER_SIZE 45
#else
#define COMPEN_FILTER_SIZE 30
#endif
void AM_WriteFirCoeffs( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   int i;
   volatile uint16* dsp_ptr;

#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))
   if(am.toneLoopbackRec)
      return;
#endif

#if defined(MT6219) || defined(MT6217)
   /* Avoid to access DSP memory during WT accelrator is on */
   if(am.state & AM_STATE_AUDIO)
   {
      memcpy(am.in_coeff_tmp, in_coeff, 45*sizeof(int16));
      memcpy(am.out_coeff_tmp, out_coeff, 45*sizeof(int16));
      am.need_update_coeff = true;
      return;
   }
   am.need_update_coeff = false;
#endif

   audio_coeff_flag = 1;

   /* Write audio FIR filter coeficients */
   *DP_AFI_COEF_LEN = COMPEN_FILTER_SIZE;   
   dsp_ptr = DSP_PM_ADDR(0,DSP_IN_FIR_COEFF_IN_ADDR);   
   for( i=0; i<COMPEN_FILTER_SIZE; i++ )
      *dsp_ptr ++ = *in_coeff++;    

   *DP_AFO_COEF_LEN = COMPEN_FILTER_SIZE;   
   dsp_ptr = DSP_PM_ADDR(0,DSP_OUT_FIR_COEFF_OUT_ADDR);      
   for( i=0; i<COMPEN_FILTER_SIZE; i++ )
      *dsp_ptr ++ = *out_coeff++;

   /* enable input/output filtering */

#if defined(MT6219) || defined(MT6217) || defined(MT6235) || defined(MT6238)
   *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG);                  
                                        /* if 8->16K IIR is done by H/W */
   *VLBCR &= ~(0x01<<3);                     /* if 8->16K IIR is done by H/W */
#else /* all others use DSP IIR */
   *DP_AUDIO_PAR |= (VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG);                  
                                        /* if 8->16K IIR is done by DSP */
   *VLBCR |= (0x01<<3);                      /* if 8->16K IIR is done by DSP */
#endif
}

#if defined(MT6219) || defined(MT6217)
static void AM_UpdateFirCoeffs()
{
   if(am.need_update_coeff == true)
   {
      AM_WriteFirCoeffs(am.in_coeff_tmp, am.out_coeff_tmp);
      am.need_update_coeff = false;
   }
}
#endif

#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)

const signed short Audio_Flt_Coeff[114] = 
{ 
   -26,   -52,    19,   104,    28,  -151,  -134,   150,   283,   -59,
  -441,  -164,   531,   521,  -461,  -999,    97,  1520,   734, -1997,
 -2562,  2330, 10084, 13890, 10084,  2330, -2562, -1997,   734,  1520,
    97,  -999,  -461,   521,   531,  -164,  -441,   -59,   283,   150,
  -134,  -151,    28,   104,    19,   -52,   -26,    59,    97,   -67,
  -160,    60,   241,   -28,  -339,   -39,   448,   153,  -564,  -333, 
   681,   605,  -790, -1023,   885,  1730,  -958, -3247,  1004, 10318, 
 15303, 10318,  1004, -3247,  -958,  1730,   885, -1023,  -790,   605, 
   681,  -333,	-564,   153,   448,   -39,  -339,   -28,   241,    60, 
  -160,   -67,    97,    59, -7153, 15272,  7650,-15301,  7650, -7153,
 15272,  7650,-15301,  7650, -7322, 15221,  7162,-14324,  7162, -5371,
 13169,  7162,-14324,  7162 
};

const signed short Audio_16k_Compen_filter[45] = 
{ 
   -50,    58,  -115,   146,  -226,   460,  -620,  1086, -1756,  3535, 
 -8484, 31128, -8484,  3535, -1756,  1086,  -620,   460,  -226,   146, 
  -115,    58,   -50,     0,     0,     0,     0,     0,     0,     0, 
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
     0,     0,     0,     0,     0 
};

static void AM_WriteFirCoeffs2()
{
   volatile uint16* dsp_ptr;
   {
      int I;
      const int16 *ptr;

      /* Write Audio filter coefficients */
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      *DP_Audio_Flt_Coeff_Len = 47;
#endif
      ptr = Audio_Flt_Coeff;

#if defined(MT6226_S00) || defined(MT6226M_S00) || defined(MT6227_S00)   
   dsp_ptr = DSP_PM_ADDR(0, 0x385A);
#elif defined(MT6226_S01) || defined(MT6226M_S01) || defined(MT6227_S01) || defined(MT6226_S02) || defined(MT6226M_S02) || defined(MT6227_S02) || defined(MT6227D) || defined(MT6226D)
   dsp_ptr = DSP_PM_ADDR(0, 0x3800);
#elif defined(MT6228) || defined(MT6225)
   dsp_ptr = DSP_PM_ADDR(0, 0x3800); 
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   dsp_ptr = DSP_DM_ADDR(2, 0x3540);
#elif defined(MT6223) || defined(MT6223P)
   dsp_ptr = DSP_DM_ADDR(1, 0x3540);
#else
   #error Need DSP guys give the Firmware Anti-Aliasing address
#endif

#if defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   *DSP_UP_DOWN_SAMP_CTRL  = 1;
#endif
      
      for( I = 114; --I >= 0 ; )
         *dsp_ptr++ = *ptr++;

      /* Write 16k compensation filter coefficients */
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
      *DP_16k_Compen_Flt_Len = 45;
#endif
      ptr = Audio_16k_Compen_filter;

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) 
   dsp_ptr = DSP_PM_ADDR(0, 0x38CC);
#elif defined(MT6228) || defined(MT6225)
   dsp_ptr = DSP_PM_ADDR(0, 0x390C);
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FA4);
#else
   #error Need DSP guys give the 16k compensation filter address
#endif
      
      for( I = 45 ; --I >= 0 ; )
         *dsp_ptr++ = *ptr++;    
   }
}
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOff( uint32 data );

static void AM_DSP_SpeechOn( uint32 rat_mode )
{
   ASSERT( !(am.state & AM_CONFLICT_STATE) ); 
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(1) );
#if defined(MT6219) || defined(MT6217)
   AM_UpdateFirCoeffs();
#endif
   am.speech_off_delay = 0;
   
#ifdef MT6205
   if( am.speech_mode == 0 ) {      /* Fix a FR bug, clear FR internal buffer */
      int16 I;
      DSP_WRITE( DSP_DM_ADDR(0, 0x1288), 0 );
      for( I = 1; I < 76; I++ )
         DSP_WRITE( IDMA_SHORT_ADDR, 0 );
   }
#endif

#if defined( __WCDMA_RAT__ )
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef AUTO_DAI
   AFE_TurnOff8K();              /* Turn Off 8K int. before turn on DAI   */
   AFE_TurnOnDAI();
   AFE_TurnOn8K();               /* Turn On 8K int   */
#if defined(MT6227D) || defined(MT6226D)
   SPE_LoadLimiterPara(0);       /*Disable DSP limiter when DAI mode by DSP   */
                                 /*team request to walk around by MCU only on */
                                 /*MT6227D. If DSP patch reset, this code can */
                                 /*be removed*/
#endif
   *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x0800;   
   am.io_type = DAI_MODE;
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
   AM_WriteSpeechParameters( 0x0600, am.speech_mode, am.speech_mode );
   am.state |= AM_STATE_DAI;
#else
   AFE_TurnOn8K();

   if(am.fLoopBack){
      AM_WriteSpeechParameters( 0x0632, am.speech_mode, am.speech_mode );
   }else{
      if(rat_mode == RAT_2G_MODE)
      {
         AM_WriteSpeechParameters( 0x0633, am.speech_mode, am.speech_mode );
      }   
#if defined( __WCDMA_RAT__ )
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   }   
#endif
   if(rat_mode == RAT_2G_MODE)
   {
      AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode );
      AM_Write_Speech_Delay( am.speech_mode,  am.sub_channel, 0 );
      am.sp3g_flag = false;
   }         
#if defined( __WCDMA_RAT__ )
/* under construction !*/
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
#ifndef L1D_TEST
   *E_CTRL_HO |= 0x0004;   // Enable ramp up in TCH
#endif    
#endif

   VBI_Reset();

   am.state |= AM_STATE_SPEECH;
}

void AM_SpeechOn(uint32 rat_mode)
{   
   AM_Enqueue( AM_DSP_SpeechOn, rat_mode);

   AFE_TurnOnSpeaker( L1SP_SPEECH );
   AFE_TurnOnMicrophone( L1SP_SPEECH );
   
#ifndef  L1D_TEST
   AM_FlushQFunction();
#endif
}

static void AM_DSP_SpeechOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(0) );
   am.speech_off_delay = 10;
   if( am.speech_state & SP_STATE_VMR )            /* call drop while conversation recording */
      AM_DSP_VMRecordOff( 0 );

#ifdef AUTO_DAI
   if( am.state & AM_STATE_DAI ) {
      AFE_TurnOffDAI();
      *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x8000; 
      am.io_type = NORMAL_MODE;
      L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) ); 
      am.state &= ~AM_STATE_DAI;
   }
#endif

   am.state &= ~AM_STATE_SPEECH;
   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   *DP_SC_FLAGS &= 0xF800;
#if defined( __WCDMA_RAT__ )
/* under construction !*/
/* under construction !*/
#endif
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   *E_CTRL_HO &= ~0x0004;   // Disable ramp up in TCH
#endif
}

void AM_SpeechOff( void )
{
#ifndef  L1D_TEST
   AFE_TurnOffMicrophone( L1SP_SPEECH );
   AFE_TurnOffSpeaker( L1SP_SPEECH );
   AFE_MuteMicrophone( false );
#endif
   AM_Enqueue( AM_DSP_SpeechOff, false );
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

void AM_EnterSpeechOff()
{
   /* do not allow handover when speech off procedure to avoid that speech   */
   /* enhancement can not switch state machine due to VBI Reset              */
   am.speech_state |= SP_STATE_CLOSING;
   L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(3) , L1AUDIO_Str_onoff(1) );
}

void AM_LeaveSpeechOff()
{
   am.speech_state &= ~SP_STATE_CLOSING;
   L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(3) , L1AUDIO_Str_onoff(0) );
}

bool AM_IsSpeechOn( void )
{
   return( (bool)((am.state & AM_STATE_SPEECH) != 0 && (am.speech_state & SP_STATE_CLOSING) == 0 ) );
}

bool AM_IsSpeechState( void )
{
   return( (bool)((am.state & AM_STATE_SPEECH) != 0 ));
}

void AM_SetSpeechMode( uint16 speech_mode, int8 sub_channel )
{
   am.speech_mode = speech_mode;
   am.sub_channel = sub_channel;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static const uint16 DAITEST_CMD_TABLE[] =
{  0x8000,    /* 0: DAI TEST MODE 0  */
   0x0200,    /* 1: DAI TEST MODE 1  */
   0x0400,    /* 2: DAI TEST MODE 2  */
   0x0800,    /* 3: DAI TEST MODE 3  */
   0x1000,    /* 4: BT Cordless Mode */
   0x2000,    /* 5: BT Earphone Mode */
   0x8000,    /* 6: Speech Mode      */
   0x0000     /* 7: NOne             */
};

static void AM_DSP_SetDAIMode( uint32 mode )
{  
   if( am.state & AM_STATE_VOICE )
      return;
   if( (am.state & AM_STATE_SPEECH) == 0 )
      return;

   if( mode == 4 )
      mode = 3;
   if( mode > 3 )
      mode = 0;

   VBI_End();
   AFE_TurnOff8K();  

   if( mode == 0 ) {
      AFE_TurnOffDAI();
      AFE_TurnOn8K();               /* Turn On 8K int   */
      *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x8000;
      VBI_Reset();
      am.state &= ~AM_STATE_DAI;
      am.io_type = NORMAL_MODE;      
   }
   else {
      AFE_TurnOnDAI();
      AFE_TurnOn8K();               /* Turn On 8K int   */
      *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | DAITEST_CMD_TABLE[mode];
      VBI_Reset();
      am.state |= AM_STATE_DAI;
      am.io_type = DAI_MODE;
   }
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}

void AM_SetDAIMode ( uint8 mode )
{
   uint32 savedMask;
   AM_QFunction qf;

   savedMask = SaveAndSetIRQMask();
   L1D_CCCDReset();

   qf.code = AM_DSP_SetDAIMode;
   qf.data = (uint32)mode;
   RB_PUT( am.qfunc, qf );

   RestoreIRQMask(savedMask);
}

bool AM_IsDAIMode( void )
{
   return (*DP_AUDIO_PAR & 0x0E00)? true: false;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOn( uint32 speech_mode )
{
      
   if( am.state & AM_STATE_SPEECH ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_VMR));
      *DP_SC_FLAGS |= 0x0800;
#if  !defined(MT6205B)
      *E_CTRL_HO   |= 0x08;         /* Enable DSP debugging information of VM */
#endif
      am.speech_state |= SP_STATE_VMR;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(1) );
   }
   else if	( am.state & AM_STATE_VOIP ) {    /* VoIP Recording */
      ASSERT(!(am.voip_state & VOIP_STATE_VMR));   
      
      if (speech_mode>=0x03 && speech_mode<=0x0A) { /* AMR */           
         *DP_SC_MUTE |= 0x0002;         
         AM_WriteSpeechParameters( 0x0D33, speech_mode, speech_mode ); /* Turn on speech decoder */                      
      }      
      
      am.voip_state |= VOIP_STATE_VMR;
      
      L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(1) );

   }   
   else {                                    /* VM in idle mode */
      ASSERT( !(am.state & AM_CONFLICT_STATE) );                                 
#if defined(MT6219) || defined(MT6217)
      AM_UpdateFirCoeffs();
#endif
      AFE_TurnOn8K();
      
#if defined(AMRWB_ENCODE)
#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T)
      if(speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);            
                                           /* Turn off DSP IIR, Set AMR-WB bit */
         *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );    /* Turn off sidetone */
         *DP_16k_Compen_Flt_flag = 1;
      }
#elif defined(MT6235) || defined(MT6238)
      if(speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
                                           /* Set AMR-WB bit */
         *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );    /* Turn off sidetone */
         *DP_16k_Compen_Flt_flag = 1;
         *VLBCR |= (0x01<<3);                /* Bypass hardware IIR filter */
      }
#elif defined(MT6219)
      if(speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);            
                                          /* Turn off DSP IIR, Set AMR-WB bit */
         *DP_AUDIO_PAR &= ~(VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG);            
                             /* Turn off DSP FIR Should turn on in the future */
         // Do not turn on AWB DTX mode yet, when turning on, it contains a lot of no data frames.
         //*DP_AUDIO_CTRL2 |= 0x0100;          /* Turn on AWB DTX mode */
         *VLBCR |= (0x01<<3);                /* Bypass hardware IIR filter, not in 6208 */
      }
#endif      
      if (speech_mode>=0x20 && speech_mode<=0x28) { /* AMR-WB */
         AM_WriteSpeechParameters( 0x0D31, speech_mode, speech_mode ); /* Turn off speech decoder */
         AM_Write_Idle_Delay(0);
      } else 
#endif//#if defined(AMRWB_ENCODE)
      if (speech_mode>=0x03 && speech_mode<=0x0A) { /* AMR */
         *DP_SC_MUTE |= 0x0002;
//         AM_FillSilencePattern( DP_RX_TCH_S0_0, 0, speech_mode );
         AM_WriteSpeechParameters( 0x0D33, speech_mode, speech_mode ); /* Turn on speech decoder */
         AM_Write_Idle_Delay(0);
      } else { /* Voice Memo */
         *DP_SC_MUTE |= 0x0002;
//         AM_FillSilencePattern( DP_RX_TCH_S0_0, 0, speech_mode );
         AM_WriteSpeechParameters( 0x0D33, speech_mode, speech_mode );
         AM_Write_Speech_Delay( speech_mode, 0, 0 );
      }
      VBI_Reset();
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
   }
   
}

void AM_VMRecordOn( uint16 speech_mode )
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if(!(am.state & AM_STATE_SPEECH) && (speech_mode <= 0xA) && !(am.state & AM_STATE_VOIP) )
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );
#endif
   AM_Enqueue( AM_DSP_VMRecordOn, speech_mode );
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_FM_RADIO );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      {         
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }   
   }

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   AM_FlushQFunction(); 
   if(!(am.state & AM_STATE_SPEECH) && (speech_mode <= 0xA) && !(am.state & AM_STATE_VOIP) )
      SPE_SetULNR(true);
#endif    
   
}


static void AM_DSP_VMRecordOff( uint32 data )
{
   (void)data;
   
#if !defined(MT6205B)
   *E_CTRL_HO   &= 0xFFF7;   /* Disable DSP debugging information of VM */
#endif

   if(am.speech_state & SP_STATE_VMR) /* Conversation Recording */
   {
      am.speech_state &= ~SP_STATE_VMR;
      *DP_SC_FLAGS &= ~0x0800;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(0) );
   }
   else if	( am.voip_state & VOIP_STATE_VMR ) {    /* VoIP Recording */
      
      am.voip_state &= ~VOIP_STATE_VMR;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(0) );       
      if( am.state == 0 ) {
         VBI_End();
         AFE_TurnOff8K();
      }  
      *DP_SC_MUTE &= ~0x0002;
      *DP_SC_FLAGS = 0x0000;      
            
   }   
   else  /* VM in idle mode */ 
   {         
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );                               
      if( am.state == 0 ) {
         VBI_End();
         AFE_TurnOff8K();
      }  
      *DP_SC_MUTE &= ~0x0002;
      *DP_SC_FLAGS = 0x0000;
#if defined(AMRWB_ENCODE)
#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)
      *DP_AUDIO_PAR &= ~(VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);           
                                            /* AMR-WB: Turn off AMR-WB */
      *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Turn on DSP IIR and enable sidetone filter */
      *DP_16k_Compen_Flt_flag = 0;          /* Switch 16k compensation filter off */
#elif defined(MT6235) || defined(MT6238)
      *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);
                                            /* AMR-WB: Turn off AMR-WB */
      *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Turn on DSP IIR and enable sidetone filter */
      *DP_16k_Compen_Flt_flag = 0;          /* Switch 16k compensation filter off */
      *VLBCR &= ~(0x01<<3);                /* don't Bypass hardware IIR filter */

#elif defined(MT6219)
      *DP_AUDIO_PAR &= ~VOICE_WB_AMR_FLAG;  /* AMR-WB: Turn off AMR-WB */
      *VLBCR &= ~(0x01<<3);                 /* AMR-WB: if 8->16K IIR is done by H/W */
#endif
#endif
   }
}

void AM_VMRecordOff( void )
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      SPE_SetULNR(false);
#endif       
   
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_FM_RADIO );
   }
   else {      
      if( !(am.state & AM_STATE_VOIP) )        
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   AM_Enqueue( AM_DSP_VMRecordOff, 0 );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_VMWriteParameter(uint16 sc_mode, uint16 sd_mode, bool isReset)
{
   if(sc_mode > 2) {
      /* For AMR speech playback, One SD only */
      AM_WriteSpeechParameters( 0x1622, sc_mode, sd_mode );
      AM_Write_Idle_Delay(0);
   } else {
      AM_WriteSpeechParameters( 0x2622, sc_mode, sd_mode );
      AM_Write_Speech_Delay( sc_mode, 0, 0 );
   }
   
#if defined(AMRWB_DECODE)
#if  defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T)
   if(sc_mode>=0x20 && sc_mode<=0x28) {   /* AMR-WB Mode */
      *DP_AUDIO_PAR &= ~VOICE_SIDETONE_FILTER_FLAG;   /* disable sidetone filter */
      *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);            
                                     /* AMR-WB: Turn off DSP IIR, Set AMR-WB bit */
      *DP_16k_Compen_Flt_flag = 1;
   }
#elif defined(MT6235) || defined(MT6238)
   if(sc_mode>=0x20 && sc_mode<=0x28) {   /* AMR-WB Mode */
      *DP_AUDIO_PAR &= ~VOICE_SIDETONE_FILTER_FLAG;   /* disable sidetone filter */
      *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);            
                                     /* AMR-WB: Set AMR-WB bit */
      *DP_16k_Compen_Flt_flag = 1;
      *VLBCR |= (0x01<<3);                /* AMR-WB: Bypass hardware IIR filter  */
   }
#elif defined(MT6219)
   if(sc_mode>=0x20 && sc_mode<=0x28) {   /* AMR-WB Mode */
      *DP_AUDIO_PAR &= ~(VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG);         
                                          /* AMR-WB: Should turn on in the future */
      *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);            
                                          /* AMR-WB: Turn off DSP IIR, Set AMR-WB bit */
      *VLBCR |= (0x01<<3);                /* AMR-WB: Bypass hardware IIR filter, not in 6208 */
   }
#endif
#endif

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   // Disable the bit 10 of E_CTRL_HO before VM playback
   //   to avoid the abonrmal AMR playback just after power on
   *E_CTRL_HO &= ~0x0400;
#endif

   if (isReset)
      VBI_Reset();
}

static void AM_DSP_VMPlaybackOn( uint32 vm_control )
{
   uint16 sc_mode, sd_mode;
   uint32 style;

   ASSERT( !(am.state & AM_CONFLICT_STATE) );
   /**
    * style:
    * bit0 : MEDIA_VMP_AS_SPEECH(0) or MEDIA_VMP_AS_RINGTONE(1)
    * bit1 : MEDIA_VMP_AMR(0) or MEDIA_VMP_AMR_WB(2)
    */
   style = vm_control >> 16;
   
   L1Audio_Msg_AM_Switch( AM_Switch_Name(7), L1AUDIO_Str_onoff(1) );
#if defined(MT6219) || defined(MT6217)
   AM_UpdateFirCoeffs();
#endif
   AFE_TurnOn8K();   

#if defined(AMRWB_DECODE)
   if ( (uint32)MEDIA_VMP_AMR_WB == (style&0x02)) {
      sc_mode = (vm_control>>2) & 0xFF;
      sd_mode = 0;
   } else
#endif
   {
      /* control --> | 4bit:sd_mode | 4bit:sc_mode | 1bit:DL | 1bit:UL | */
      sc_mode = (vm_control>>2) & 0xF;
      sd_mode = (vm_control>>6) & 0xF;
   }

   if( sc_mode == 0 )
      sc_mode = sd_mode;
   if( sd_mode == 0 )
      sd_mode = sc_mode;

   AM_VMWriteParameter(sc_mode, sd_mode, true);
   
   am.state |= AM_STATE_VOICE;
}

void AM_VMPlaybackOn( uint16 control, uint32 style )
{
#if defined(MT6223) || defined(MT6223P)
   if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif
#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if( !AM_IsSpeechOn() )
   {  // Download DSP SBC code
      uint16 amr_sd_mode = (control&0x3C) >> 2;
      uint16 awb_sd_mode = (control&0xFC) >> 2;
      if( (0x03<=amr_sd_mode && 0x0A>=amr_sd_mode) // AMR
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
          || (0x20<=awb_sd_mode && 0x28>=awb_sd_mode)  // AWB
        )
           DSP_DynamicDownload( DDID_AMRSBC );
#else
        )
        {
           // DSP dynamic download should be done before setting Audio Flexile flag.
           //   Otherwise, 8k interrupt is avtive in keytone, then DSP jumps from ROM to RAM.
           //   At this time, the RAM may be wrong address
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
           DSP_DynamicDownload( DDID_AMRSBC );
           *DP_AUDIO_FLEXI_CTRL |= 0x0005;
#elif defined(MT6225)
           DSP_DynamicDownload( DDID_DAF );
           *DP_AUDIO_FLEXI_CTRL |= 0x0004;
#endif
        }
        (void)awb_sd_mode;
#endif

#if defined(AUD_TIME_STRETCH)
      *DP2_AUDIO_PP_CTRL |= 0x0001;
      AudioPP_TS_Activate(true);
#endif

#if defined( __BT_AUDIO_VIA_SCO__ ) //AMR/AWB can output via VBI and BT SCO link at the same time
      if (AM_IsBluetoothOn()){
   		*DP_VSBT_CTRL |= 0x1;
   	}
#endif

#if APM_SUPPORT
      if (0x20<=awb_sd_mode && 0x28>=awb_sd_mode)
         APM_Activate(ASP_TYPE_VOICE, ASP_FS_16K);
      else
         APM_Activate(ASP_TYPE_VOICE, ASP_FS_8K);
#endif
   }
#endif

   AM_Enqueue( AM_DSP_VMPlaybackOn, (style<<16) | control );

   if( (uint32)MEDIA_VMP_AS_SPEECH == (style&0x01)) {
      AFE_TurnOnSpeaker( L1SP_SPEECH );
   }
   else { /* MEDIA_VMP_AS_RINGTONE */
      AFE_TurnOnSpeaker( L1SP_VOICE );
   }
}

static void AM_DSP_VMPlaybackOff( uint32 style )
{
   (void)style;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(7), L1AUDIO_Str_onoff(0) );   

   am.state &= ~AM_STATE_VOICE;
   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   *DP_SC_FLAGS   = 0x0000;

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   // Enable the bit 10 of E_CTRL_HO before VM playback
   //   to avoid the abonrmal AMR playback just after power on
   *E_CTRL_HO |= 0x0400;
#endif

#if defined(AMRWB_DECODE)
#if  defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)
   *DP_AUDIO_PAR &= ~(VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);	
                                     /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Enable sidetone filter */
   *DP_16k_Compen_Flt_flag = 0;
#elif defined(MT6235) || defined(MT6238)
   *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);	
                                     /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG; /* Enable sidetone filter */
   *DP_16k_Compen_Flt_flag = 0;
   *VLBCR &= ~(0x01<<3);      /* AMR-WB: if 8->16K IIR is done by H/W */
#elif defined(MT6219)
   *DP_AUDIO_PAR &= ~VOICE_WB_AMR_FLAG;  /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= (VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG);	    
                                         /* Enable compensation filter */
   *VLBCR &= ~(0x01<<3);      /* AMR-WB: if 8->16K IIR is done by H/W */
#endif
#endif
}


void AM_VMPlaybackOff( uint32 style )
{
#if APM_SUPPORT
   APM_Deactivate();
#endif

   if( (uint32)MEDIA_VMP_AS_SPEECH == (style & 0x01)) {
      AFE_TurnOffSpeaker( L1SP_SPEECH );
   }
   else {    /* MEDIA_VMP_AS_RINGTONE */
      AFE_TurnOffSpeaker( L1SP_VOICE );
   }
#if defined(__BT_A2DP_PROFILE__) && !defined(SBC_UNIT_TEST)
   SBC_Close();
#endif


#if defined(AUD_TIME_STRETCH)
   AudioPP_Close();
#endif

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238)
   *DP_AUDIO_FLEXI_CTRL &= ~0x0005;
#elif defined(MT6225)
   *DP_AUDIO_FLEXI_CTRL &= ~0x0004;
#endif
#if defined( __BT_AUDIO_VIA_SCO__ ) //AMR/AWB can output via VBI and BT SCO link at the same time
   if (AM_IsBluetoothOn()){
		*DP_VSBT_CTRL &= ~0x1;
	}
#endif
   AM_Enqueue( AM_DSP_VMPlaybackOff, style );
   /* Resume Digital Gain for Speech Mode */
#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   AFE_SetDigitalGain( L1SP_VOICE, 100 );
#endif
#if defined(MT6223) || defined(MT6223P)
   if( DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Unload( DYNAMIC_CODE_SBC );
#endif
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_Melody( uint32 data )
{
   if( (bool)data ) {            /* Turn on */
      ASSERT( !(am.state & AM_CONFLICT_STATE) );
      AFE_TurnOn8K();
      if( am.state == 0 ) {         
         AM_Write_Idle_Delay(2);         
         VBI_Reset();
      }
      am.state |= AM_STATE_VOICE;
   }
   else {                        /* Turn on */
      am.state &= ~AM_STATE_VOICE;
      if( am.state == 0 ) 
         VBI_End();         
      
      if( (am.state & ~AM_STATE_AUDIO) == 0 )
         AFE_TurnOff8K();
   }
}

void AM_MelodyOn( void )
{
   AM_Enqueue( AM_DSP_Melody, true );
   AFE_TurnOnSpeaker( L1SP_VOICE );
}

void AM_MelodyOff( void )
{
   AFE_TurnOffSpeaker( L1SP_VOICE );
   AM_Enqueue( AM_DSP_Melody, false );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_KeyToneOn( uint32 data )
{
   (void)data;
   ASSERT(!(am.state & AM_STATE_KEYTONE));
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(1) );
#if defined(MT6219) || defined(MT6217)
   AM_UpdateFirCoeffs();
#endif
   AFE_TurnOn8K();
   if( am.state == 0 ) { 
   #if defined(MT6205B)   
      AM_Write_Idle_Delay(2);
   #else 
      AM_Write_Idle_Delay(4);
   #endif   	                
      VBI_Reset();
   }
   am.state |= AM_STATE_KEYTONE;
}

void AM_KeyToneOn( void )
{
   AM_Enqueue( AM_DSP_KeyToneOn, 0 );
   AFE_TurnOnSpeaker( L1SP_KEYTONE );
}

static void AM_DSP_KeyToneOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_KEYTONE;
   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_KeyToneOff( void )
{
   AFE_TurnOffSpeaker( L1SP_KEYTONE );
   AM_Enqueue( AM_DSP_KeyToneOff, 0 );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_ToneOn( uint32 data )
{
   (void)data;
   ASSERT(!(am.state & AM_STATE_TONE));
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(1) );
#if defined(MT6219) || defined(MT6217)
   AM_UpdateFirCoeffs();
#endif
   AFE_TurnOn8K();
   if( am.state == 0) {          
   #if defined(MT6205B)
      AM_Write_Idle_Delay(2);
   #else 
      AM_Write_Idle_Delay(4);
   #endif   	    
      VBI_Reset();
   }
   am.state |= AM_STATE_TONE;
}

void AM_ToneOn( void )
{
   AM_Enqueue( AM_DSP_ToneOn, 0 );
}

static void AM_DSP_ToneOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_TONE;
   if( am.state == 0 ) 
      VBI_End();     
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_ToneOff( void )
{
   AM_Enqueue( AM_DSP_ToneOff, 0 );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM8K_PlaybackOn( uint32 data )
{
   (void)data;
   
#if defined(MT6219) || defined(MT6217)
   AM_UpdateFirCoeffs();
#endif
   AFE_TurnOn8K();
   if( am.state == 0 ) {            
      AM_Write_Idle_Delay(2);
      VBI_Reset();
   }
#if defined(BGSND_ENABLE)
   if ( data == 1 )
   {
      ASSERT(!(am.state & AM_STATE_SND_EFFECT));
      am.state |= AM_STATE_SND_EFFECT;                                    
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(1) );         
   }
   else
#endif /* ...BGSND_ENABLE */
   {
      ASSERT( !(am.state & AM_CONFLICT_STATE) );       
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(1) );
   }
}

void AM_PCM8K_PlaybackOn( void )
{
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOn, 0 );
   if(!(am.state & AM_STATE_SPEECH))
      AFE_TurnOnSpeaker( L1SP_VOICE );
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

static void AM_DSP_PCM8K_PlaybackOff( uint32 data )
{
   (void)data;
   
#if defined(BGSND_ENABLE) 
   if( data == 1 )
   {
      am.state &= ~AM_STATE_SND_EFFECT;                  
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(0) );         
   }
   else
#endif /* ...BGSND_ENABLE */
   {      
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(0) );
   }
   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_PCM8K_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_VOICE );
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOff, 0 );
   
#ifndef  L1D_TEST
   if( wait ) 
      AM_FlushQFunction(); 
#endif   
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM16K_PlaybackOn( uint32 data )
{
   (void)data;
   ASSERT( !(am.state & AM_CONFLICT_STATE) ); 
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(1) );
   AFE_TurnOn8K();   
   *DP_AUDIO_PAR |= VOICE_WB_AMR_FLAG;               
   AM_Write_Idle_Delay(3);   
   VBI_Reset();
   
   am.state |= AM_STATE_VOICE;
}

void AM_PCM16K_PlaybackOn( void )
{
   AM_Enqueue( AM_DSP_PCM16K_PlaybackOn, 0 );
   AFE_TurnOnSpeaker( L1SP_VOICE );
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

static void AM_DSP_PCM16K_PlaybackOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(0) );
   
   am.state &= ~AM_STATE_VOICE;
   *DP_AUDIO_PAR &= ~VOICE_WB_AMR_FLAG;
   if( am.state == 0 ) 
      VBI_End();     
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_PCM16K_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_VOICE );
   AM_Enqueue( AM_DSP_PCM16K_PlaybackOff, 0 );
   
#ifndef  L1D_TEST
   if( wait )
      AM_FlushQFunction(); 
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

static void AM_DSP_PCM16K_RecordOn( uint32 data )
{
   (void)data;

   ASSERT( !(am.state & AM_CONFLICT_STATE) );
   AFE_TurnOn8K();
#if  defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)
   *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);
   *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_16k_Compen_Flt_flag = 1;
#elif defined(MT6235) || defined(MT6238)
   *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG);
   *DP_AUDIO_PAR &= ~( VOICE_SIDETONE_FILTER_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG );
   *DP_16k_Compen_Flt_flag = 1;
   *VLBCR |= (0x01<<3);                /* Bypass hardware IIR filter*/
#elif defined(MT6219)
   *DP_AUDIO_PAR |= (VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);            
   /* Turn off DSP IIR, Set AMR-WB bit */
   *DP_AUDIO_PAR &= ~(VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG);
   /* Turn off DSP FIR Should turn on in the future */
   *VLBCR |= (0x01<<3);                /* Bypass hardware IIR filter, not in 6208 */
#endif      
   *DP_SC_MUTE |= 0x0002;
   *DP_SC_FLAGS = 0x0D00; //disable speech coder
   
   AM_Write_Idle_Delay(3);//16K PCM
   VBI_Reset();
   am.state |= AM_STATE_VOICE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
}

void AM_PCM16K_RecordOn( void )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) );
   AM_Enqueue( AM_DSP_PCM16K_RecordOn, 0 );
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_FM_RADIO );
   }
   else {      
      AFE_TurnOnMicrophone( L1SP_VOICE );
   }
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

static void AM_DSP_PCM16K_RecordOff( uint32 data )
{
   (void)data;

   am.state &= ~AM_STATE_VOICE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );                               
   if( am.state == 0 ) {
      VBI_End();
      AFE_TurnOff8K();
   }  
   *DP_SC_MUTE &= ~0x0002;
   *DP_SC_FLAGS = 0x0000;
#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)
   *DP_AUDIO_PAR &= ~(VOICE_16K_SWITCH_FLAG + VOICE_WB_AMR_FLAG);           
                                            /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG;
   *DP_16k_Compen_Flt_flag = 0;          /* Switch 16k compensation filter off */
#elif defined(MT6235) || defined(MT6238)
   *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);
                                            /* AMR-WB: Turn off AMR-WB */
   *DP_AUDIO_PAR |= VOICE_SIDETONE_FILTER_FLAG + VOICE_INPUT_FILTER_FLAG + VOICE_OUTPUT_FILTER_FLAG;
   *DP_16k_Compen_Flt_flag = 0;          /* Switch 16k compensation filter off */
   *VLBCR &= ~(0x01<<3);                 /* AMR-WB: if 8->16K IIR is done by H/W */
#elif defined(MT6219)
   *DP_AUDIO_PAR &= ~VOICE_WB_AMR_FLAG;  /* AMR-WB: Turn off AMR-WB */
   *VLBCR &= ~(0x01<<3);                 /* AMR-WB: if 8->16K IIR is done by H/W */
#endif

}

void AM_PCM16K_RecordOff( bool wait )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) );
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_FM_RADIO );
   }
   else {      
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   AM_Enqueue( AM_DSP_PCM16K_RecordOff, 0 );
    
#ifndef  L1D_TEST
   if( wait )
      AM_FlushQFunction(); 
#endif
  
}

#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_PCM8K_RecordOn( uint32 data )
{
   (void)data;

   if( am.state & AM_STATE_SPEECH ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_PCM8K_REC));
      *DP_TCH_PCM_REC_ENA |= 0x0001;       
      am.speech_state |= SP_STATE_PCM8K_REC;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(1) );
      return;
   }else{
       ASSERT( !(am.state & AM_CONFLICT_STATE) );
#if defined(MT6219) || defined(MT6217)
       AM_UpdateFirCoeffs();
#endif
       AFE_TurnOn8K();       
       *DP_SC_MUTE |= 0x0002;
       *DP_SC_MODE =  0x0000; // Dummy set to DSP FR Speech Decoder
       *DP_SC_FLAGS|= 0x0022; // Dummy Enable DSP SD Task Since DP_SC_MUTE is set to 2       
       AM_Write_Idle_Delay(2);
       VBI_Reset();
       am.state |= AM_STATE_VOICE;
       L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(1) );
    }
   
}

void AM_PCM8K_RecordOn( void )
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );
#endif

   AM_Enqueue( AM_DSP_PCM8K_RecordOn, 0 );
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_FM_RADIO );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH))
      {        
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }   
   }

#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
   if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
      SPE_SetULNR(true);
#endif       
}

static void AM_DSP_PCM8K_RecordOff( uint32 data )
{
   (void)data;
   
      
   if(am.speech_state & SP_STATE_PCM8K_REC) 
   { 
      am.speech_state &= ~SP_STATE_PCM8K_REC;   
      *DP_TCH_PCM_REC_ENA &= ~0x0001;   /* Disable DSP control bit for WAV record in TCH mode */
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(0) );
   }
   else 
   {   
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(0) );
   }   
   if( am.state == 0 ) {
      VBI_End();      
      *DP_SC_FLAGS &= ~0x0022;
      *DP_SC_MUTE &= ~0x0002;
   }
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
}

void AM_PCM8K_RecordOff( bool wait )
{
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6227) || defined(MT6227D) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   if(!(am.state & AM_STATE_SPEECH))
#if defined(__BT_SUPPORT__)
      if(!AM_IsBTCordlessMode())
#endif
      SPE_SetULNR(false);
#endif    
   
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_FM_RADIO );
   }
   else {      
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   AM_Enqueue( AM_DSP_PCM8K_RecordOff, 0 );
    
#ifndef  L1D_TEST
   if( wait )
      AM_FlushQFunction(); 
#endif
  
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if  !defined(MT6205B)
static void AM_DSP_AudioPlaybackOn( uint32 data )
{
   uint16 asp_type, asp_fs, del_m = 0;

   ASSERT( !(am.state & AM_CONFLICT_STATE) ); 
   asp_type = (uint16)(data>>16);
   asp_fs = (uint16)data;
   AFE_TurnOnAudioClock( (uint8)data&0x0F );
   switch( asp_type ){
      case 0:
         del_m = 864;         break;
      case ASP_TYPE_MELODY_16K:
         AFE_TurnOnWTDMA();
         del_m = 864;         break;
      case ASP_TYPE_PCM_HI:
         if(((int8)(data&0xFF))<=0x12)
            del_m = 132;
         else if(((int8)(data&0xFF))<=0x22)
            del_m = 276;
         else
            del_m = 564;
         break;
      case ASP_TYPE_DAF:
         del_m = 1152;        break;
      case ASP_TYPE_AAC:
         del_m = 2040;        break;
      case ASP_TYPE_WMA:
      case ASP_TYPE_AACPLUS:
         del_m = 4080;        break;
      case ASP_TYPE_AWB_PLUS:
         del_m = 2500;        break;
   }
   AM_WriteAspParam( asp_type, asp_fs, 0x20, del_m );   
   AM_Write_Idle_Delay(2);

#if defined(__BT_AUDIO_VIA_SCO__)   
   if ( AM_IsBluetoothOn() )
      AFE_TurnOn8K();
#endif

   VBI_Reset();
   
#if defined(__BT_AUDIO_VIA_SCO__)
   if ( AM_IsBluetoothOn() ){
      *DP_SC_FLAGS = 0x0600;
      *DP_AUDIO_PAR &= ~0x0002;
      *DP_AUDIO_VIA_8KBT_CTRL |= 0x0001;
      am.state |= AM_STATE_AvBT;
   }
#endif

   am.state |= AM_STATE_AUDIO;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(1) );
}

void AM_AudioPlaybackOn( uint16 asp_type, uint16 asp_fs )
{
#if defined(MT6223) || defined(MT6223P)
   if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif

#if defined(__BT_A2DP_PROFILE__) && (defined(MT6223) || defined(MT6223P))
   DSP_DynamicDownload_MT6223(DDID_SBC);
#endif

#ifndef  L1D_TEST

#if defined(AUDIO_EQUALIZER_ENABLE)
#if defined(MT6219) || defined(MT6217)
   if ( asp_type == ASP_TYPE_DAF ) {
      AEQ_Activate( asp_fs, false );
   }
#elif defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6223) || defined(MT6223P) || defined(MT6225)
   AEQ_Activate( asp_fs, false );
#endif
#endif

#if defined(AUDIO_COMPENSATION_ENABLE)
#if defined(MT6217) || defined(MT6219)
   if ( asp_type == ASP_TYPE_DAF )
      Audio_Compensation_Activate( false );
#else
   Audio_Compensation_Activate( false );
#endif
#endif

#if !defined(AUDIO_EQUALIZER_ENABLE) && !defined(AUDIO_COMPENSATION_ENABLE) && ( defined(MT6223) || defined(MT6223P) || defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238) || defined(MT6268T) )
   Audio_HW_FIR_Reset();
#endif

#if DSP_SUPPORT_UPSAMPLE
   AM_Write_Upsampling_Coeff();
#endif

   // For SBC or DSP FIR
#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
   *DP_AUDIO_FLEXI_CTRL |= 0x0005;
#elif defined(MT6225)
   *DP_AUDIO_FLEXI_CTRL |= 0x0004;
#endif

#if defined ( __BT_AUDIO_VIA_SCO__ )
   if( AM_IsBluetoothOn() )
      HOST_APM_Register(APM_TASKID_AVB);
   else
      HOST_APM_UnRegister(APM_TASKID_AVB);
#endif
#if APM_SUPPORT
   APM_Activate(asp_type, asp_fs);
#endif

   AFE_SetSamplingRate( (uint32)asp_fs );

#if defined(AUD_TIME_STRETCH)
   *DP2_AUDIO_PP_CTRL |= 0x0001;
   AudioPP_TS_Activate(false);
#endif  // AUD_TIME_STRETCH

#endif  // L1D_TEST
   AM_Enqueue( AM_DSP_AudioPlaybackOn, ((uint32)asp_type << 16) + (uint32)asp_fs );
   AFE_TurnOnSpeaker( L1SP_AUDIO );
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif  // L1D_TEST
}

static void AM_DSP_AudioPlaybackOff( uint32 data )
{
   (void)data;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(0) );
   
   am.state &= ~AM_STATE_AUDIO;
   AFE_TurnOffAudioClock();
   AFE_TurnOffWTDMA();
   AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95 );
#if defined(__BT_AUDIO_VIA_SCO__)
   if (AM_IsBluetoothOn()){
      *DP_AUDIO_VIA_8KBT_CTRL &= ~0x0001;
      am.state &= ~AM_STATE_AvBT;
   }
#endif
   
   if( am.state == 0 ) {
      VBI_End();
      AFE_TurnOff8K(); /*Turn off 8k clock which was turned on before keypad pressing.*/      
   }
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   *DP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
#endif
}

void AM_AudioPlaybackOff( bool wait )
{

#if APM_SUPPORT
   if (wait)
      AFE_SetHardwareMute(true);
   APM_Deactivate();
#endif

#if defined(__BT_A2DP_PROFILE__) && !defined(SBC_UNIT_TEST)
#if !(APM_SUPPORT)
   if( wait )
#endif
      SBC_Close();
#endif

   AFE_TurnOffSpeaker( L1SP_AUDIO );
   AM_Enqueue( AM_DSP_AudioPlaybackOff, 0 );
#ifndef  L1D_TEST
   if( wait ) 
      AM_FlushQFunction(); 
#if defined ( __BT_AUDIO_VIA_SCO__ )
   HOST_APM_UnRegister(APM_TASKID_AVB);
#endif   
#if defined(AUD_TIME_STRETCH)
   AudioPP_Close();      /* Turn off audio post process*/
#endif  // AUD_TIME_STRETCH

#if defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
   *DP_AUDIO_FLEXI_CTRL &= ~0x0005;
#elif defined(MT6225)
   *DP_AUDIO_FLEXI_CTRL &= ~0x0004;
#endif

#if defined(MT6219) || defined(MT6217) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) 
   *DP_AEQ_CTRL = 0;     /* Turn off audio equalizer */
#endif

#endif  // L1D_TEST
#if defined(MT6223) || defined(MT6223P)
   if( DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Unload( DYNAMIC_CODE_SBC );
#endif 

#if APM_SUPPORT
   if (wait)
      AFE_SetHardwareMute(false);
#endif
}

int16 AM_IsAudioPlaybackOn( void )
{
   if( am.state & AM_STATE_AUDIO )
      return( *DP_ASP_FS );
   return -1;
}

bool AM_IsVMPlaybackOn( void )
{
   if( am.state & AM_STATE_VOICE)
      return true;
   return false;
}
#endif

/* ==========================================================================*/
void AM_MuteULSpeech( bool mute )
{
   if( mute ) 
      *DP_SC_MUTE |= 0x0001;   
   else 
      *DP_SC_MUTE &= ~0x0001;   
}

bool AM_IsULSpeechMuted( void )
{
   if(*DP_SC_MUTE & 0x1)
      return true; 
   else 
      return false;    
}

#if defined(VR_ITRI)
static void AM_DSP_VRRecordOn( uint32 trainPhase )
{
   ASSERT( !(am.state & AM_CONFLICT_STATE) );
#if defined(MT6219) || defined(MT6217)
   AM_UpdateFirCoeffs();
#endif
   AFE_TurnOn8K();
   
   *DP_SC_MUTE |= 0x0002;
   AM_FillSilencePattern( DP_RX_TCH_S0_0, 0, 0 );
   if(trainPhase){
      AM_WriteSpeechParameters( 0x0D33, 0, 0 );
   }else{
      AM_WriteSpeechParameters( 0x0033, 0, 0 );
   }
   AM_Write_Speech_Delay( 0, 0, 0 );
   VBI_Reset();
         
   am.state |= AM_STATE_VOICE;
}

static void AM_DSP_VRRecordOff( uint32 trainPhase )
{
   am.state &= ~AM_STATE_VOICE;

   if( am.state == 0 ) 
      VBI_End();      
   
   if( (am.state & ~AM_STATE_AUDIO) == 0 )
      AFE_TurnOff8K();
   *DP_SC_FLAGS = 0x0000;
   *DP_SC_MUTE &= ~0x0002;

}

void  AM_VRRecordOn( uint32 trainPhase )
{
   AM_Enqueue( AM_DSP_VRRecordOn, trainPhase );   
   AFE_TurnOnMicrophone( L1SP_VOICE );
}

void  AM_VRRecordOff( uint32 trainPhase )
{   
   AFE_TurnOffMicrophone( L1SP_VOICE );
   AM_Enqueue( AM_DSP_VRRecordOff, trainPhase );
}
#endif // "#if defined(VR_ITRI)"

const signed short Sidetone_FIR[31] = 
{ 
   287,   -37,  -407,  -201,   432,   541,  -305,  -936,   -48,  1292, 
   818, -1545, -2548,  1657,  9937, 14977,  9937,  1657, -2548, -1545, 
   818,  1292,   -48,  -936,  -305,   541,   432,  -201,  -407,   -37, 
   287 
};

#if defined(MT6227D) || defined(MT6226D)
// DSP version encryption, asked by Jerry Chen
const static int16 S7[128] = {
   54, 50, 62, 56, 22, 34, 94, 96, 38, 6, 63, 93, 2, 18,123, 33,
   55,113, 39,114, 21, 67, 65, 12, 47, 73, 46, 27, 25,111,124, 81,
   53, 9,121, 79, 52, 60, 58, 48,101,127, 40,120,104, 70, 71, 43,
   20,122, 72, 61, 23,109, 13,100, 77, 1, 16, 7, 82, 10,105, 98,
   117,116, 76, 11, 89,106, 0,125,118, 99, 86, 69, 30, 57,126, 87,
   112, 51, 17, 5, 95, 14, 90, 84, 91, 8, 35,103, 32, 97, 28, 66,
   102, 31, 26, 45, 75, 4, 85, 92, 37, 74, 80, 49, 68, 29,115, 44,
   64,107,108, 24,110, 83, 36, 78, 42, 19, 15, 41, 88,119, 59, 3
};
	
const static int16 S9[512] = {
   167,239,161,379,391,334, 9,338, 38,226, 48,358,452,385, 90,397,
   183,253,147,331,415,340, 51,362,306,500,262, 82,216,159,356,177,
   175,241,489, 37,206, 17, 0,333, 44,254,378, 58,143,220, 81,400,
   95, 3,315,245, 54,235,218,405,472,264,172,494,371,290,399, 76,
   165,197,395,121,257,480,423,212,240, 28,462,176,406,507,288,223,
   501,407,249,265, 89,186,221,428,164, 74,440,196,458,421,350,163,
   232,158,134,354, 13,250,491,142,191, 69,193,425,152,227,366,135,
   344,300,276,242,437,320,113,278, 11,243, 87,317, 36, 93,496, 27,
   487,446,482, 41, 68,156,457,131,326,403,339, 20, 39,115,442,124,
   475,384,508, 53,112,170,479,151,126,169, 73,268,279,321,168,364,
   363,292, 46,499,393,327,324, 24,456,267,157,460,488,426,309,229,
   439,506,208,271,349,401,434,236, 16,209,359, 52, 56,120,199,277,
   465,416,252,287,246, 6, 83,305,420,345,153,502, 65, 61,244,282,
   173,222,418, 67,386,368,261,101,476,291,195,430, 49, 79,166,330,
   280,383,373,128,382,408,155,495,367,388,274,107,459,417, 62,454,
   132,225,203,316,234, 14,301, 91,503,286,424,211,347,307,140,374,
   35,103,125,427, 19,214,453,146,498,314,444,230,256,329,198,285,
   50,116, 78,410, 10,205,510,171,231, 45,139,467, 29, 86,505, 32,
   72, 26,342,150,313,490,431,238,411,325,149,473, 40,119,174,355,
   185,233,389, 71,448,273,372, 55,110,178,322, 12,469,392,369,190,
   1,109,375,137,181, 88, 75,308,260,484, 98,272,370,275,412,111,
   336,318, 4,504,492,259,304, 77,337,435, 21,357,303,332,483, 18,
   47, 85, 25,497,474,289,100,269,296,478,270,106, 31,104,433, 84,
   414,486,394, 96, 99,154,511,148,413,361,409,255,162,215,302,201,
   266,351,343,144,441,365,108,298,251, 34,182,509,138,210,335,133,
   311,352,328,141,396,346,123,319,450,281,429,228,443,481, 92,404,
   485,422,248,297, 23,213,130,466, 22,217,283, 70,294,360,419,127,
   312,377, 7,468,194, 2,117,295,463,258,224,447,247,187, 80,398,
   284,353,105,390,299,471,470,184, 57,200,348, 63,204,188, 33,451,
   97, 30,310,219, 94,160,129,493, 64,179,263,102,189,207,114,402,
   438,477,387,122,192, 42,381, 5,145,118,180,449,293,323,136,380,
   43, 66, 60,455,341,445,202,432, 8,237, 15,376,436,464, 59,461
};
#endif

void AM_Init( void )
{
   int I;
   const int16 *ptr;
   volatile uint16* dsp_ptr;

   RB_INIT( am.qfunc );
   am.state = 0;
   am.speech_mode = 0;
   am.sub_channel = 0;
   am.speech_off_delay = 0;
   AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode );

   *DP_ASP_DEL_W        = 95;
   *DP_ASP_DEL_M        = 95;
#if !(defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238))
   *DP_Melody_Control   = 0;     /* suppress the old QTMF synthesizer */
#endif

#if defined(MT6227D) || defined(MT6226D)
   // DSP version encryption, asked by Jerry Chen
   ptr = S7;
   dsp_ptr = DSP_DM_ADDR(2, 0x1d00);
   for( I = 127; I>=0; I--)
      *dsp_ptr++ = *ptr++;

   ptr = S9;
   dsp_ptr = DSP_DM_ADDR(2, 0x1d80);
   for( I = 511; I>=0; I--)
      *dsp_ptr++ = *ptr++;
#endif

   /* Write audio FIR filter coeficients */
   ptr = Sidetone_FIR;

#if defined(MT6205B)
   dsp_ptr = DSP_DM_ADDR(0, 0x2F7F);
#elif defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) 
   dsp_ptr = DSP_PM_ADDR(0, 0x3F95);
#elif defined(MT6228) || defined(MT6225)
   dsp_ptr = DSP_PM_ADDR(0, 0x3939);
#elif defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
   dsp_ptr = DSP_PM_ADDR(0, 0x3FD1);
#else
   #error Need DSP guys give the sidetone FIR address
#endif

   for( I = 31; --I >= 0; )
      *dsp_ptr++ = *ptr++;

#if !defined(MT6205B)
/*for 6219_ECO co-sim*/
#ifndef L1D_TEST
   *E_CTRL_HRFR         = 0x00;
   *E_CTRL_AMREFR       = 0x02;
   *E_CTRL_HO           = 0x0401;  // AMR _Type update bit 9, HO_SID_Update bit 8
#endif
   // Initialization for EC/AEC/EES
   *DP_EC_SUPP        = 0;
   *DP_AEC_CTRL       = 0;
   *DP_EES_CTRL       = 0;
#endif

#if defined(MT6227D) || defined(MT6226D) || defined(MT6223) || defined(MT6223P) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238)
   *E_CTRL_HO         |=0x0010;
   //enable this bit to get better speech quality when HO
#endif

#if defined(MT6223) || defined(MT6223P)
   *DP_DEBUG_ASSERT_CTRL |= 0x4;
   //To disable the constraint of audio and SWDBG can not run at the same time
#endif

#if defined(MT6219) || defined(MT6217)
   am.need_update_coeff = false;
#endif
   if( audio_coeff_flag == 0 ) {
      AM_WriteFirCoeffs( Speech_Input_FIR_Coeff[0], Speech_Output_FIR_Coeff[0] );
   }
#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)  || defined(MT6235) || defined(MT6238)
   AM_WriteFirCoeffs2();
#endif

#if defined(AEC_ENABLE) || defined(EES_ENABLE)   
   *DP_AEC_8K_CTRL = 0;
#endif    
   *DP_EC_SUPP = 0;
   *DP_NSYNC_NOT_ETSI_C &= ~0x20;
   *DP_AUDIO_PAR = 0x8000; 
   AM_WriteAspParam( ASP_TYPE_VOICE, ASP_FS_8K, 95, 95 );
   DSP_IO4_On();
   DSP_IO5_On(); 
   am.io_type = NORMAL_MODE;  
   am.speech_state = 0;
   am.voip_state = 0;   
   am.fLoopBack = false; 
   am.sp3g_flag = false;
#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))
   am.toneLoopbackRec = false;
#endif
}

/* ========================================================================= */
/*   Bluetooth control Functions                                             */
/* ========================================================================= */
#if defined(__BT_SUPPORT__)
static void AM_DSP_BluetoothOn( uint32 data )
{
   // If BT is turned on already, return directly.
   if( AM_IsBluetoothOn() )
      return;
                           
   // Adjust the uplink and downlink gain
   am.bt_digital_gain = *DP_VOL_OUT_PCM;   
   am.bt_mic_gain = *DP_VOL_IN_PCM;
   
   if(data == 0x1000)
   {
      ASSERT(am.state == 0);

      // Set linear mode (zero pending)
#if defined(MT6227D) || defined(MT6226D)
      *DP_BT_PATCH_CTRL |= 0x0102;   // Asked by Wego to avoid noise on MT6227D
#else
      *DP_BT_PATCH_CTRL |= 0x0001;
#endif

      *DP_BT_MODE_CTRL = 0x0000;
      *DP_VOL_OUT_PCM = 0x1000;
      *DP_VOL_IN_PCM  = 0x1000;

      *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x1000;      
      AFE_TurnOnBluetooth(0);
      AFE_TurnOn8K(); 
      am.io_type = BT_CORDLESS_MODE;            
   }   
   else 
   {
      AFE_TurnOff8K_Direct();
      //AFE_Mute(true);

      // Set linear mode without modifying gain by DSP
#if defined(MT6227D) || defined(MT6226D)
      *DP_BT_PATCH_CTRL |= 0x0102;   // Asked by Wego to avoid noise on MT6227D
#else
      *DP_BT_PATCH_CTRL |= 0x0001;
#endif

      *DP_BT_MODE_CTRL = 0x0000;
      *DP_VOL_OUT_PCM = 0x1000;
      *DP_VOL_IN_PCM  = 0x1000;

      if(am.state == 0)    
      {
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x2000;
         AFE_TurnOnBluetooth(0);
      }   
      else 
      {                
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x2000;
         AFE_TurnOnBluetooth(0);                    
         if(am.state & AM_STATE_SPEECH)         
            AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode ); 
         AFE_TurnOn8K();
#if defined(__BT_AUDIO_VIA_SCO__)
         if ( AM_IsAudioPlaybackOn() != -1 ){
            *DP_SC_FLAGS = 0x0600;
            *DP_AUDIO_PAR &= ~0x0002;
            am.state |= AM_STATE_AvBT;
         }else if ( AM_IsVMPlaybackOn() )
            *DP_VSBT_CTRL |= 0x1;
#endif
         if(am.state & ( AM_STATE_SPEECH | AM_STATE_VOICE ) )
            VBI_Reset();
#if defined(__BT_AUDIO_VIA_SCO__)
         if(am.state & AM_STATE_AvBT )
            *DP_AUDIO_VIA_8KBT_CTRL |= 0x0001;
#endif
      }
      am.io_type = BT_EARPHONE_MODE;                                   
   }
   
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );        
}

static void AM_DSP_BluetoothOff( uint32 data )
{
   // If BT is turned off already, return directly.
   if( !AM_IsBluetoothOn() )
      return;
      
   AFE_TurnOff8K_Direct();
   //AFE_Mute(false);
   *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x8000;
   AFE_TurnOffBluetooth();    

#if defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T)  || defined(MT6235) || defined(MT6238)
   // Set linear mode (zero pending)
   *DP_BT_MODE_CTRL = 0x0000;
#endif
   *DP_VOL_OUT_PCM = am.bt_digital_gain;
   *DP_VOL_IN_PCM = am.bt_mic_gain;

   if( am.state != 0 )     
   {  
#if defined(__BT_AUDIO_VIA_SCO__)
      if (AM_IsAudioPlaybackOn() != -1){
         *DP_AUDIO_VIA_8KBT_CTRL &= ~0x0001;
         am.state &= ~AM_STATE_AvBT;
      }else if (AM_IsVMPlaybackOn())
         *DP_VSBT_CTRL &= ~0x1;
#endif
      if(am.state & AM_STATE_SPEECH) 
         AM_FillSilencePattern( DP_TX_TCH_S0_0, 2, am.speech_mode );
      AFE_TurnOn8K();
      if(am.state & AM_STATE_SPEECH)    
         VBI_Reset();
   }
   
   am.io_type = NORMAL_MODE; 
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );                                     
}

//*******************************************************************//
//*   bt_mode:        1 for cordless mode, 2 for earphone mode      *//
//*   bt_sync_type:   0 for short sync, 1 for long sync             *//
//*   bt_sync_length: range from 1 to 8                             *//
//*******************************************************************//
extern const unsigned char Bluetooth_Sync_Type;
extern const unsigned char Bluetooth_Sync_Length;
void AM_BluetoothOn( uint8 bt_mode )
{
   uint32 param = bt_mode;          // bt_mode will be either 1 for cordless mode, or 2 for earphone mode
   param <<= 12;
   param |= (Bluetooth_Sync_Type << 3);    // bt_sync_type will be either 0 for short sync, or 1 for long sync
   param |= (Bluetooth_Sync_Length - 1);   // 1 <= bt_sync_length <= 8
   AM_Enqueue( AM_DSP_BluetoothOn, param );
   
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
#if defined ( __BT_AUDIO_VIA_SCO__ )
   if( AM_IsAudioPlaybackOn() != -1 )
      HOST_APM_Register(APM_TASKID_AVB);
   else
      HOST_APM_UnRegister(APM_TASKID_AVB);
#endif
}

void AM_BluetoothOff( void )
{
   AM_Enqueue( AM_DSP_BluetoothOff, 0 );

#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
#if defined ( __BT_AUDIO_VIA_SCO__ )
   HOST_APM_UnRegister(APM_TASKID_AVB);
#endif
}

bool AM_IsBluetoothOn( void )
{
   return( (*DP_AUDIO_PAR&0x3000)!=0 );
}

bool AM_IsBTCordlessMode( void )
{
   return( (*DP_AUDIO_PAR&0x1000)!=0 );
}

#endif   // __BT_SUPPORT__
/* ========================================================================= */


#if defined(BGSND_ENABLE) 
void AM_SND_PlaybackOn( void )
{
#if defined(MT6223) || defined(MT6223P)
   if( !DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Load( DYNAMIC_CODE_SBC, 0, 0 );
#endif
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOn, 1 );
   if( !AM_IsSpeechOn() ) AFE_TurnOnSpeaker( L1SP_SND_EFFECT );
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

void AM_SND_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_SND_EFFECT );
   AM_Enqueue( AM_DSP_PCM8K_PlaybackOff, 1 );
   
#ifndef  L1D_TEST
   if( wait )
      AM_FlushQFunction(); 
#endif
#if defined(MT6223) || defined(MT6223P)
   if( DCM_Isloaded( DYNAMIC_CODE_SBC ) )
      DCM_Unload( DYNAMIC_CODE_SBC );
#endif 
}
#endif /* ...BGSND_ENABLE */

/* ========================================================================= */
/*   PCM_EX control Functions                                            */
/* ========================================================================= */

#if defined(MT6225) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
void AM_DSP_PCM_EX_On(uint32 type)
{
   

   switch(type)
   {
      case 0:  //PCM4WAY CTM
         ASSERT(!(am.speech_state & SP_STATE_PCM4WAY)); 
#ifndef L1D_TEST
         // add codes to enable VM log
         *DP_SC_FLAGS |= 0x0800;  // conversion recording in speech call
         *E_CTRL_HO   |= 0x08;         /* Enable DSP debugging information of VM */
         am.speech_state |= SP_STATE_PCM4WAY;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(1) );
#endif                   
         break;
         
      case 1:  //PCM2WAY Voice
         ASSERT( !(am.state & AM_CONFLICT_STATE) ); 
         AFE_TurnOn8K();
         if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }         
         am.state |= AM_STATE_VOICE;         
         break;
         
      case 2:  //PCM2WAY VoIP
         ASSERT( !(am.state & AM_CONFLICT_STATE) ); 
         AFE_TurnOn8K();
         if(am.state == 0)
         {                 
            AM_Write_Idle_Delay(5);
            VBI_Reset();
         }        
         am.state |= AM_STATE_VOIP;                           
         break;
         
      default:
         ASSERT(0);
         break;                 
   }   
}


void AM_DSP_PCM_EX_Off(uint32 type)
{   

   switch(type)
   {
      case 0:  //PCM4WAY CTM
         // add codes to stop VM log
         *E_CTRL_HO   &= 0xFFF7;   /* Disable DSP debugging information of VM */
         *DP_SC_FLAGS &= ~0x0800;
         am.speech_state &= ~SP_STATE_PCM4WAY;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(0) );                   
         break;
         
      case 1:  //PCM2WAY Voice
         am.state &= ~AM_STATE_VOICE;
         if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K(); 
         }      
         break;
         
      case 2:  //PCM2WAY VoIP
         am.state &= ~AM_STATE_VOIP;         
         if( am.state == 0 ) {
            VBI_End();        
            AFE_TurnOff8K();
         }                                        
         break;
         
      default:
         ASSERT(0);
         break;                  
   }    
}


void  AM_PCM_EX_On( uint32 type )
{
   kal_uint8 aud_func = L1SP_MAX_AUDIO;

   if( type == 2 )
   {
#if defined(MT6217) || defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      AFE_SetDigitalGain( L1SP_SPEECH, 100 );
#endif    
#if defined(AEC_ENABLE) || defined(EES_ENABLE) || defined(MT6217) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
      DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif
      aud_func = L1SP_SPEECH;
   }
   else if(!(am.state & AM_STATE_SPEECH))
      aud_func = L1SP_VOICE;

   AM_Enqueue( AM_DSP_PCM_EX_On, type );
   if(aud_func < L1SP_MAX_AUDIO)
   {
      AFE_TurnOnSpeaker( aud_func );
      AFE_TurnOnMicrophone( aud_func );
   }
}


void  AM_PCM_EX_Off( uint32 type )
{
   kal_uint8 aud_func = L1SP_MAX_AUDIO;

   if( type == 2 )
      aud_func = L1SP_SPEECH;
   else if(!(am.state & AM_STATE_SPEECH))
      aud_func = L1SP_VOICE;

   if(aud_func < L1SP_MAX_AUDIO)
   {
      AFE_TurnOffSpeaker( aud_func );
      AFE_TurnOffMicrophone( aud_func );
   }

   AM_Enqueue( AM_DSP_PCM_EX_Off, type);
   AM_FlushQFunction();
}
#endif

bool AM_IsVoIPOn( void )
{
   return( (bool)((am.state & AM_STATE_VOIP) != 0) );
}

/* ========================================================================= */
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)
void AM_SetPostProcessCtrl( uint16 ppMask, uint16 ppCtrl )
{
   uint32 savedMask;
   uint16 pp_ctrl_cache;

   savedMask = SaveAndSetIRQMask();
   pp_ctrl_cache = *DP2_AUDIO_PP_CTRL & ~ppMask;
   pp_ctrl_cache |= ((ppCtrl & ppMask) | 0x0001);
   *DP2_AUDIO_PP_CTRL |= pp_ctrl_cache;
   RestoreIRQMask(savedMask);
}

void AM_ClearPostProcessCtrl( uint16 ppMask )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   *DP2_AUDIO_PP_CTRL &= ~ppMask;
   RestoreIRQMask(savedMask);
}
#endif
uint16 AM_Status( void ) 
{
   return am.state;   
}

#if (!defined(MT6219)&&!defined(MT6205)&&!defined(MT6205B)&&!defined(MT6219B)&&!defined(MT6217))
void AM_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      am.toneLoopbackRec = KAL_TRUE;
   else
      am.toneLoopbackRec = KAL_FALSE;
}
#endif

/* ========================================================================= */
/*   Functions for Modem LoopBack Test                                       */
/* ========================================================================= */

bool AM_IsLoopBackTest( void )
{   
   return am.fLoopBack; 
}

void AM_SetLoopBackTest(bool enable)
{
   if(AM_IsSpeechOn()) 
   {  
      if(enable)   
         *DP_SC_FLAGS = 0x632;            
      else if(am.fLoopBack)    
         *DP_SC_FLAGS = 0x633;       
   }         
   am.fLoopBack = enable;          
} 

/* ========================================================================= */
/*   Functions for Buletooth Cordless Mode                                   */
/* ========================================================================= */
static void AM_DSP_BTCordlessOn( uint32 data )
{
   (void)data;
   AFE_TurnOnSpeaker( L1SP_VOICE );
   AFE_TurnOnMicrophone( L1SP_VOICE );
   AFE_TurnOn8K();
   if ( am.state == 0 ) {
      VBI_Reset();
   }
   am.state |= AM_STATE_VOICE;
}

void AM_BTCordlessOn( void )
{
   AM_Enqueue( AM_DSP_BTCordlessOn, 0 );
   
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

static void AM_DSP_BTCordlessOff( uint32 data )
{
   (void)data;
   am.state &= ~AM_STATE_VOICE;
   if ( am.state == 0 ) {
      VBI_End();      
      AFE_TurnOff8K();
   }

   AFE_TurnOffMicrophone( L1SP_VOICE );
   AFE_TurnOffSpeaker( L1SP_VOICE );
}

void AM_BTCordlessOff( void )
{
   AM_Enqueue( AM_DSP_BTCordlessOff, 0 );
   
#ifndef  L1D_TEST
   AM_FlushQFunction(); 
#endif
}

bool AM_IsConflictState( void )
{
   if( am.state & AM_CONFLICT_STATE )
      return true;
   else
      return false;
}
