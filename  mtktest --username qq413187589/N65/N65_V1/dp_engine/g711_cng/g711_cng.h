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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   G711_CNG.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   G.711 Appendix II Comfort Noise Generator implementation
 *
 * Author:
 * -------
 * -------
 *============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef G711_CNG_DOT_H
#define G711_CNG_DOT_H

// Debug Information, 0:off, 1:on
#define DEBUG_INFO     0
// Combine Durbin and Backward recursion
#define OPT_VERSION    1
// 0: Gaussian, 1: uniform
#define RANDOM_VERSION 1

#define MODEL_ORDER            10
#define MODEL_ORDER_P2      (MODEL_ORDER+2)
#define FRAME_SAMPLE           80
#define WINDOW_SIZE           200
#define EXC_LEN                 5
#define HP_IIR             0x7F00                 // 127/128 for S.15
#define CORR_THRESHOLD     (1966 * MODEL_ORDER)   // 0.06 * MODEL_ORDER
#define GAUSSIAN_CON       0x80000031


typedef struct {
   short PreVAD;
   short order;
   int   FrameSize;
   int   IncTh;
   int   Th;
   int   PreEnergy;
   int   PreMag;
   short DataBuf[WINDOW_SIZE];
   short PreCorr[MODEL_ORDER_P2];
   
   unsigned int xn_1_2;
   unsigned int yn_1_2;
} G711_CNG_Cod_state;

typedef struct {
   int   CurEnergy;
   int   CurMag;
   short WindowSignal[WINDOW_SIZE];
   short CurCorr[MODEL_ORDER_P2];
   short LPC[MODEL_ORDER];
   short Reflect[MODEL_ORDER];
} G711_CNG_Cod_scratch;

typedef struct {
   int   Order;
   int   PreVAD;
   int   FrameSize;
   int   SidMag;
   int   CurMag;
   int   Seed;
   int   ExcFactor;
   short Reflect[MODEL_ORDER];
   short LPC[MODEL_ORDER];
   short IIRDl[MODEL_ORDER];
   
   unsigned int xn_1_2;
   unsigned int yn_1_2;
} G711_CNG_Dec_state;

typedef struct {
   short TempBuf[MODEL_ORDER];
} G711_CNG_Dec_scratch;

int G711_CNG_Enc_getScratchSize(void);
void G711_CNG_Init_Enc(G711_CNG_Cod_state *cng_cod, int frame_size, int order);
void G711_CNG_PreProcess(G711_CNG_Cod_state *cng_cod, void *scratch, short *speech_in);
int G711_CNG_Encoder( G711_CNG_Cod_state *cng_cod, void *scratch, short *bits_out );
void G711_CNG_Update_Enc( G711_CNG_Cod_state *cng_cod, int ftyp);

int G711_CNG_Dec_getScratchSize(void);
void G711_CNG_Init_Dec(G711_CNG_Dec_state *cng_dec, int frame_size);
int G711_CNG_Decoder( G711_CNG_Dec_state *cng_dec, void *scratch, unsigned char *bits_in, short *speech_out, int num_octets);
void G711_CNG_Update_Dec( G711_CNG_Dec_state *cng_dec, int ftyp);
int G711_CNG_IsDTX(G711_CNG_Dec_state *cng_dec);
void cngLPCSynthesize(G711_CNG_Dec_state *cng_dec, short *speech_out, int len);


#endif
