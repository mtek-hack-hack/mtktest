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
 * tonedect.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 * header of tone detection function
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define SAMPLING_RATE      8000     /* 8000Hz   */

typedef struct {
   int32 coeff;
   int32 Q1;
   int32 Q2;
} TD_Handle;

typedef struct dtmfHandle DTMF_Handle;
struct dtmfHandle {
   int32       block_size;
   int32       acum_buf_size;
   int32       block_no;
   TD_Handle   hdl[8];
   int32       block_count;
   int32       mag[8];
   TD_Handle   hdl2[8];
   int32       block_count2;
   int32       mag2[8];
   int32       key_threshold;
   int16       key;
   int16       key_temp;
   int16       key_pre;             /*decoded key of previous frame*/
   int16       key_pre_second;      /*decoded key of second previous frame*/
   int16       pauseCount;          /*continuous low mag or non-key count*/
   int32       (*PutData)( DTMF_Handle *hdl, int16 *buf ,int32 len);//return value: consume length of input buffer
   void        (*Close)( DTMF_Handle *hdl );
   int16       (*GetKey)( DTMF_Handle *hdl );
};

void TD_Init( TD_Handle *hdl, int32 target_freq, int32 block_size );
void TD_Reset( TD_Handle *hdl );
void TD_ProcessSample( TD_Handle *hdl, int16 sample );
void TD_ProcessBlock( TD_Handle *hdl, int16 *buf, int32 len );
int32 TD_GetMagnitudeDB( TD_Handle *hdl );
DTMF_Handle *DTMF_Open( int32 block_size, int32 block_no );
