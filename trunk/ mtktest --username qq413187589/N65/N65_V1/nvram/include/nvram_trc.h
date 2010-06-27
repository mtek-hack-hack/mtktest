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
 *	nvram_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is trace map definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _NVRAM_TRC_H
#define _NVRAM_TRC_H


#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

BEGIN_TRACE_MAP(MOD_NVRAM)

   /* TRACE_FUNC trace class */   
   TRC_MSG(FUNC_NVRAM_STARTUP, "NVRAM: startup handler")
   TRC_MSG(FUNC_NVRAM_STARTUP_CNF, "NVRAM: confirm result: %02X")
   TRC_MSG(FUNC_NVRAM_READ, "NVRAM: read handler")
   TRC_MSG(FUNC_NVRAM_READ_CNF, "NVRAM: read result: %02X. Sniff: file_idx:%2X, para:%2X, %02X:%02X")
   TRC_MSG(FUNC_NVRAM_WRITE, "NVRAM: write handler")
   TRC_MSG(FUNC_NVRAM_WRITE_CNF, "NVRAM: write result: %02X")
   TRC_MSG(FUNC_NVRAM_RESET, "NVRAM: reset handler")
   TRC_MSG(FUNC_NVRAM_RESET_CNF, "NVRAM: reset result: %02X")
   TRC_MSG(FUNC_NVRAM_TST, "NVRAM: tst handler")

   /* TRACE_STATE trace class */   
   TRC_MSG(STATE_NVRAM_NULL, "NVRAM: State: NULL. Cannot initialized. Device fail?")
   TRC_MSG(STATE_NVRAM_NOT_READY, "NVRAM: State: Not ready. Initialized but not receive STARTUP yet")
   TRC_MSG(STATE_NVRAM_READY, "NVRAM: State: Ready. Receive STARTUP and ready")

   /* TRACE_INFO trace class */   
   TRC_MSG(INFO_NVRAM_DRV_INIT, "NVRAM: DRV report: initialized")
   TRC_MSG(INFO_NVRAM_DRV_UNFORMATTED, "NVRAM: DRV report: DRV_UNFORMATTED")
   TRC_MSG(INFO_NVRAM_LOCK_STATUS, "NVRAM: lock: %d")

   /* TRACE_WARNING trace class */   
   TRC_MSG(WARNING_NVRAM_SYS_RECORD, "NVRAM: %d is corrupted")
   TRC_MSG(WARNING_NVRAM_ALL_LDI_INIT, "NVRAM: Warning: all logical data items of category '%d' are to be reset; unformatted device or incompatible version?")

   /* TRACE_ERROR trace class */   
   TRC_MSG(ERROR_NVRAM_CANNOT_STARTUP, "NVRAM: Receive STARTUP but cannot startup. Device fail?")
   TRC_MSG(ERROR_NVRAM_STATE, "NVRAM: State error")
   TRC_MSG(ERROR_NVRAM_TST_INVALID_COMM, "NVRAM: Invalid Command")


END_TRACE_MAP(MOD_NVRAM)
#endif


