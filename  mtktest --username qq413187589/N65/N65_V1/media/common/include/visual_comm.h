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
 *   visual_comm.h
 *
 * Project:
 * --------
 *		MT6218B and MT6219
 *
 * Description:
 * ------------
 *   common memory management code for MT6218B and MT6219
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _VISUAL_COMM_H
#define _VISUAL_COMM_H

#include "scn_comm.h"

#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
/*(MT6217)||(MT6218B)||(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/
typedef struct {
   kal_uint32  *ext_ram_start_ptr;
   kal_uint32  ext_ram_total_length;
   kal_uint32  ext_ram_index;
   kal_uint32  *int_ram_start_ptr;
   kal_uint32  int_ram_total_length;
   kal_uint32  int_ram_index;
   kal_bool    ext_ram_init;
   kal_bool    int_ram_init;
}VISUAL_MEM_STRUCT;

#define ENTER_CRITICAL()		{\
													kal_uint32 _savedMask;\
													_savedMask = SaveAndSetIRQMask();

#define EXIT_CRITICAL()			RestoreIRQMask(_savedMask);}
extern void Visual_Init(void);
extern void visual_hisr_init(void);
extern void *intmem_get_buffer(kal_uint32 size);
extern void *extmem_get_buffer(kal_uint32 size);
extern void intmem_init(void *start_ptr,kal_uint32 length);
extern void extmem_init(void *start_ptr,kal_uint32 length);
extern void intmem_deinit(void);
extern void extmem_deinit(void);
extern void visual_disable_sleep(void);
extern void visual_enable_sleep(void);

extern kal_bool extmem_is_buffer_available(kal_uint32 size);
#endif /*(MT6217)||(MT6218B)||(MT6219)||(MT6226)||(MT6227)||(MT6226M)||(MT6228)||(MT6229)*/
#endif   /*_VISUAL_COMM_H*/

