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
 *   RTPCodec.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Definition of external codec interface
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

#ifndef RTPCODEC_DOT_H
#define RTPCODEC_DOT_H

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define G711_ALAW                       1
#define G711_ULAW                       2

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/

/*****************************************************************************
*                  D A T A   D E C L A R A T I O N S
******************************************************************************
*/

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
#define G729ab
extern unsigned int G729AB_GetInternalBufferSize(int is_encoder);
extern unsigned int G729AB_GetSharedBufferSize(int is_encoder);
extern void *G729AB_Open(int is_encoder, unsigned char *internal_buffer, unsigned int internal_buffer_size, unsigned char *shared_buffer);
extern void G729AB_Close(void *data, int is_encoder);
extern int G729AB_Encode(void *data, short *speech_in, unsigned char *bits_out, int VAD_enable, int CNG_enable);
extern int G729AB_Decode(void *data, unsigned char *bits_in, short * speech_out, int num_octets, short frame_erasure);

#define G7231
extern unsigned int G7231_GetInternalBufferSize(int is_encoder);
extern unsigned int G7231_GetSharedBufferSize(int is_encoder);
extern void *G7231_Open(int wrkRate, int is_encoder, unsigned char *internal_buffer, unsigned int internal_buffer_size, unsigned char *shared_buffer);
extern void G7231_Close(void *data, int is_encoder);
extern int G723_1_Encode(void *data, short *speech_samples, unsigned char *bits_out, int VAD_enable, int CNG_enable);
extern int G723_1_Decode(void *data, unsigned char *bits_in, short * speech_samples, int num_octets, short frame_erasure);
extern int G7231_GetDecodeFrameSize(unsigned char c);

#define G711
extern unsigned int G711_GetInternalBufferSize(int is_encoder);
extern unsigned int G711_GetSharedBufferSize(int is_encoder);
extern void *G711_Open(int law, int is_encoder, unsigned char *internal_buffer, unsigned int internal_buffer_size, unsigned char *shared_buffer);
extern void G711_Close(void *data, int is_encoder);
extern int G711_Encode(void *data, short *speech_in, unsigned char *bits_out, int VAD_enable, int CNG_enable);
extern int G711_Decode(void *data, unsigned char *bits_in, short * speech_out, int num_octets, short frame_erasure, int isCNPayload, int disable_enhancement);

#define G726
extern unsigned int G726_GetInternalBufferSize(int is_encoder);
extern unsigned int G726_GetSharedBufferSize(int is_encoder);
extern void *G726_Open(int rate, int is_encoder, unsigned char *internal_buffer, unsigned int internal_buffer_size, unsigned char *shared_buffer);
extern void G726_Close(void *data, int is_encoder);
extern int G726_Encode(void *data, short *speech_in, unsigned char *bits_out, int VAD_enable, int CNG_enable, int rate);
extern int G726_Decode(void *data, unsigned char *bits_in, short * speech_out, int num_octets, short frame_erasure, int isCNPayload, int disable_enhancement);

/*****************************************************************************
*       I N L I N E   F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/


#endif
