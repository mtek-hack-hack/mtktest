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
 *   VMI.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Voice mixer interface definition
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

#ifndef _VMI_DOT_H_
#define _VMI_DOT_H_

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/
#if defined(SIM_ON_VC)
#define VMI_SUPPORT                     1
#else
#define VMI_SUPPORT                     ( defined(MT6225) || defined(MT6228) || \
                                          defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) || defined(MT6238))
#endif
#define VMI_IN_TASK                     1

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/
#include "l1audio_def.h"
#if defined(__MTK_TARGET__)
#include "pcm4way.h" // Data transfer through PCM2WAY interface
#endif

#include "tonesyn.h"
#include "PCMRB.h"

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define PCM2WAY_FRAME_TIME              20
#define PCM2WAY_SAMPLE_PER_MSEC         8
#define PCM2WAY_FRAME_SIZE              (PCM2WAY_FRAME_TIME*PCM2WAY_SAMPLE_PER_MSEC)

#define VMI_FRAME_TIME                  PCM2WAY_FRAME_TIME
#define VMI_SAMPLE_PER_MSEC             PCM2WAY_SAMPLE_PER_MSEC
#define VMI_FRAME_SIZE                  PCM2WAY_FRAME_SIZE

#define G711_PCMRB_SIZE                 (2*PCM2WAY_FRAME_SIZE*sizeof(int16)) // 40ms
#define G726_PCMRB_SIZE                 (2*PCM2WAY_FRAME_SIZE*sizeof(int16)) // 40ms
#define G729_PCMRB_SIZE                 (2*PCM2WAY_FRAME_SIZE*sizeof(int16)) // 40ms
#define G7231_PCMRB_SIZE                (3*PCM2WAY_FRAME_SIZE*sizeof(int16)) // 60ms

#define VMI_STATUS_SUCCESS              0
#define VMI_STATUS_FAIL                 1

#define VMI_EVENT_NONE                  0
#define VMI_EVENT_TONE_OFF              1
#define VMI_EVENT_DATA_REQUEST          2
#define VMI_EVENT_DATA_NOTIFY           4

#define VMI_DIR_UL                      0
#define VMI_DIR_DL                      1

#define VMI_PCMREC_SID                  0xffff0000
#define VMI_AUTOSPEAK_SID               0xffff0001

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
typedef uint32                          VMI_STATUS;
typedef uint32                          VMI_EVENT;
typedef void (*VMI_CALLBACK)( void *host_data, VMI_EVENT event );

typedef struct VoiceHandleStruct VMI_HANDLE;
struct VoiceHandleStruct {
   uint32           dir:1, on:1, mute:1, mix:1, mute_mic:1, mic:1;
   uint32           unused:26;
   uint32           session_id;
   PCMRB            rb;
   int32            processed_frames;
   int32            skip_frames;
   VMI_CALLBACK     callback;
   void             *host_data;
   VMI_HANDLE       *next;
};

typedef struct VMIToneParaStruct VMI_TONE_PARA;
struct VMIToneParaStruct {
   uint32           uplink_en:1, downlink_en:1, uplink_mix:1, downlink_mix:1;
   uint32           unused:28;
   uint16           freq1;
   uint16           freq2;
   int16            gain;
   uint32           duration;
   VMI_CALLBACK     callback;
   void             *host_data;
};

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
#if !defined(__MTK_TARGET__)
extern void PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type);
extern void PCM2WAY_Stop(uint32 type);
extern void PCM2WAY_GetFromMic(uint16 *ul_buf);
extern void PCM2WAY_PutToSpk(const uint16 *dl_data);
extern void PCM2WAY_FillSpk(uint16 value);
#endif

void VMI_Init( void );
VMI_HANDLE *VMI_GetHandle( uint32 dir, uint8 *buffer, int32 buffer_size );
   /* return NULL if malloc failed or buffer_size is not enough */
VMI_STATUS VMI_FreeHandle( VMI_HANDLE *handle );
   /* asserts when handle is corrupted */
VMI_STATUS VMI_Start( VMI_HANDLE *handle );
   /* asserts when handle is corrupted */
   /* return VMI_STATUS_FAIL if the handle is started before */
VMI_STATUS VMI_Mute( VMI_HANDLE *handle, bool mute );

VMI_STATUS VMI_ToneOn( VMI_TONE_PARA *para );
   /* asserts when neither uplink_en nor downlink_en is on */
   /* return VMI_STATUS_FAIL if one tone is playing or the request tone duration is not accepted */
VMI_STATUS VMI_ToneOff( void );
   /* return VMI_STATUS_FAIL if no tone is playing */
VMI_STATUS VMI_PutAllToSE(bool enable);   

#if VMI_IN_TASK
void vmi_process( void );
#endif

/*****************************************************************************
*       I N L I N E   F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/

#endif

