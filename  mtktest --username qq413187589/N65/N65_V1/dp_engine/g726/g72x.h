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
 *   G72x.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   G.726 codec implementation
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This source code is a product of Sun Microsystems, Inc. and is provided
 * for unrestricted use.  Users may copy or modify this source code without
 * charge.
 *
 * SUN SOURCE CODE IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING
 * THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.
 *
 * Sun source code is provided with no support and without any obligation on
 * the part of Sun Microsystems, Inc. to assist in its use, correction,
 * modification or enhancement.
 *
 * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE
 * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS SOFTWARE
 * OR ANY PART THEREOF.
 *
 * In no event will Sun Microsystems, Inc. be liable for any lost revenue
 * or profits or other special, indirect and consequential damages, even if
 * Sun has been advised of the possibility of such damages.
 *
 * Sun Microsystems, Inc.
 * 2550 Garcia Avenue
 * Mountain View, California  94043
 */

/*
 * g72x.h
 *
 * Header file for CCITT conversion routines.
 *
 */
#ifndef _G72X_H
#define	_G72X_H

/////////////////////////////////////////////////////////// Add by YS
#define AUDIO_ENCODING_LINEAR_ONLY
/////////////////////////////////////////////////////////// Add by YS

#define	AUDIO_ENCODING_ULAW	(1)	/* ISDN u-law */
#define	AUDIO_ENCODING_ALAW	(2)	/* ISDN A-law */
#define	AUDIO_ENCODING_LINEAR	(3)	/* PCM 2's-complement (0-center) */

/*
 * The following is the definition of the state structure
 * used by the G.721/G.723 encoder and decoder to preserve their internal
 * state between successive calls.  The meanings of the majority
 * of the state structure fields are explained in detail in the
 * CCITT Recommendation G.721.  The field names are essentially indentical
 * to variable names in the bit level description of the coding algorithm
 * included in this Recommendation.
 */
typedef struct g726_state_s {
	long yl;	/* Locked or steady state step size multiplier. */
	int yu;		/* Unlocked or non-steady state step size multiplier. */
	int dms;	/* Short term energy estimate. */
	int dml;	/* Long term energy estimate. */
	int ap;		/* Linear weighting coefficient of 'yl' and 'yu'. */

	int a[2];	/* Coefficients of pole portion of prediction filter. */
	int b[6];	/* Coefficients of zero portion of prediction filter. */
	int pk[2];	/* Signs of previous two samples of a partially
				 * reconstructed signal. */
	short dq[6];/* int here fails in newupdate on encode!
				 * Previous 6 samples of the quantized difference
				 * signal represented in an internal floating point
				 * format.
				 */
	int sr[2];	/* Previous 2 samples of the quantized difference
				 * signal represented in an internal floating point
				 * format. */
	int td;		/* delayed tone detect, new in 1988 version */
} g726_state;

/* External function definitions. */

void g726_init_state( g726_state *);

int g726_32_encoder(
		int sample,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
		int in_coding,
#endif
		 g726_state *state_ptr);
int g726_32_decoder(
		int code,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
		int out_coding,
#endif
		 g726_state *state_ptr);
int g726_16_encoder(
        int sample,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
        int in_coding,
#endif
         g726_state *state_ptr);
int g726_16_decoder(
        int code,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
        int out_coding,
#endif
         g726_state *state_ptr);
int g726_24_encoder(
		int sample,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
		int in_coding,
#endif
		g726_state *state_ptr);
int g726_24_decoder(
		int code,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
		int out_coding,
#endif
		 g726_state *state_ptr);
int g726_40_encoder(
		int sample,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
		int in_coding,
#endif
		 g726_state *state_ptr);
int g726_40_decoder(
		int code,
#if !defined(AUDIO_ENCODING_LINEAR_ONLY)
		int out_coding,
#endif
		 g726_state *state_ptr);


#endif /* !_G72X_H */

