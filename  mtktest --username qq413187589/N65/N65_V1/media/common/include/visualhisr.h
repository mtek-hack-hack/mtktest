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
 * Filename:
 * ---------
 *	visualhisr.h
 *
 * Project:
 * --------
 *   MT6219, MT6227, MT6226, MT6226M, MT6228, MT6229
 *
 * Description:
 * ------------
 *   This file is intends for visual driver.
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VISUALHISR_H
#define _VISUALHISR_H

#include    "drv_comm.h"

#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
/*(MT6217)||(MT6218B)||(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/
#define MAX_VISUAL_HISR_DBG_INFO_SIZE 64	/*must be 2^n*/

typedef struct{
   kal_uint16      tag;
   kal_uint32      time;
}VISUAL_HISR_DBG_DATA;

typedef struct{
   VISUAL_HISR_DBG_DATA   	dbg_data[MAX_VISUAL_HISR_DBG_INFO_SIZE];
   kal_uint16     		dbg_data_idx;
}VISUAL_HISR_DBG_STRUCT;

typedef enum {
   VISUAL_UNKNOWN_ID=0,
   VISUAL_CAMERA_HISR_ID,
   VISUAL_MPEG4_ENC_HISR_ID,
   VISUAL_MPEG4_DEC_HISR_ID,
   VISUAL_IMGDMA_HISR_ID,
   VISUAL_MP4_SEEK_HISR_ID,
   VISUAL_G2D_HISR_ID,
   VISUAL_JPEG_DEC_HISR_ID,
   VISUAL_JPEG_ENC_HISR_ID,
   VISUAL_JPEG_DEC_CB_HISR_ID,
   VISUAL_MP4_ENC_RECOVERY1_HISR_ID,
   VISUAL_MP4_ENC_RECOVERY2_HISR_ID,
   VISUAL_RESIZER_HISR_ID,
   VISUAL_IMGPROC_HISR_ID,
   VISUAL_GIF_HISR_ID,
   VISUAL_PNG_HISR_ID,
   VISUAL_MP4_EDITOR_LISR_HISR_ID,
#ifdef MP4_MOVE_LISR_TO_HISR   
   VISUAL_MPEG4_ENC_FIRST_HISR_ID,
   VISUAL_MPEG4_ENC_FIRST_DMA_HISR_ID,
   VISUAL_MPEG4_DEC_FIRST_HISR_ID,
   VISUAL_MPEG4_SEEK_FIRST_HISR_ID,
#endif      
   MAX_VISUAL_DEVICE,
   VISUAL_UNKNOWN_HISR_ID = 0xfe
} VISUAL_HISR_ID;

typedef struct {
   VOID_FUNC   hisr_func;
   kal_uint16  hisr_count;
} VISUAL_HISR_STRUCT;

#ifdef __NO_MULTIMEDIA_FEATURE__

#define visual_active_hisr(_id)  \
{\
   ASSERT(0);\
}

#else /*!__NO_MULTIMEDIA_FEATURE__*/

#define visual_active_hisr(_id)  \
{\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   visual_hisr_status |= (1<<_id);\
   VISUAL_HISR_TABLE[_id].hisr_count++;\
   RestoreIRQMask(_savedMask);\
   kal_activate_hisr(visual_hisr);\
}

#endif /*__NO_MULTIMEDIA_FEATURE__*/

typedef void (* VOID_FUNCTION)(void);
extern kal_hisrid visual_hisr;
extern kal_uint32 visual_hisr_status;
extern VISUAL_HISR_STRUCT VISUAL_HISR_TABLE[MAX_VISUAL_DEVICE];

extern void VISUAL_Register_HISR(kal_uint8 visula_hisr_id, VOID_FUNCTION hisr_func);
extern void VISUAL_HISR(void);
extern void visual_hisr_init(void);
#endif /*(MT6217)||(MT6218B)||(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/
#endif   /*_VISUALHISR_H*/

