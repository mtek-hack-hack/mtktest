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
 *   LowcFE.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   G.711 Appendix I Low Complexity Algorithm for Packet Loss Concealment
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef LOWCFE_DOT_H
#define LOWCFE_DOT_H

// 0: floating point, 1: fixed point
#define FE_OPTION 1

#define PITCH_MIN     40                              // minimum allowed pitch, 200 Hz
#define PITCH_MAX     120                             // maximum allowed pitch, 66 Hz
#define PITCHDIFF     (PITCH_MAX - PITCH_MIN)
#define POVERLAPMAX   (PITCH_MAX >> 2)                // maximum pitch OLA window
#define HISTORYLEN    (PITCH_MAX * 3 + POVERLAPMAX)   // history buffer length
#define NDEC          2                               // 2:1 decimation
#define CORRLEN       160                             // 20 ms correlation length
#define CORRBUFLEN    (CORRLEN + PITCH_MAX)           // correlation buffer length
#define CORRMINPOWER 	250                             // minimum power
#define EOVERLAPINCR 	32                              // end OLA increment per frame, 4 ms
#define FRAMESZ       80                              // 10 ms at 8 KHz

#define ATTENFAC 	    429496729                       // attenuation factor per 10 ms frame (S.31 about 0.2)
#define ATTENINCR     5368709                         // attenuation per sample (ATTENFAC/FRAMESZ)


typedef signed long   Word32;
typedef unsigned long UWord32;
typedef signed short  Word16;

/* Persistent memory */
typedef struct {
   int erasecnt;                  // consecutive erased frames
   int poverlap;                  // overlap based on pitch
   int poffset;                   // offset into pitch period
   int pitch;                     // pitch estimate
   int pitchblen;                 // current pitch buffer length
   Word16 *pitchbufend;           // end of pitch buffer
   Word16 *pitchbufstart;         // start of pitch buffer
   Word16 pitchbuf[HISTORYLEN];   // buffer for cycles of speech
   Word16 lastq[POVERLAPMAX];     // saved last quarter wavelength
   Word16 history[HISTORYLEN];    // history buffer
} LowcFE_state;

/* Scratch memory */
typedef struct {
   Word16 tmpBuf[HISTORYLEN];     // A temp buffer to keep the overlap or pitch
} LowcFE_scratch;

// get the size of scratch memory
int LowcFE_getScratchSize(void);
// Initialize the instance
void LowcFE_init(LowcFE_state *state_ptr);
// Synthesize speech for erasure
void LowcFE_dofe(LowcFE_state *state_ptr, void *scratch, Word16 *s);
// Add a good frame to history buffer
void LowcFE_addtohistory(LowcFE_state *state_ptr, void *scratch, Word16 *s);

#endif
