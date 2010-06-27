/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtv_comm.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_COMM_H
#define _MTV_COMM_H

#ifndef _MED_GLOBAL_H
#include "med_global.h"
#endif

#ifndef _MTV_ERROR_H
#include "mtv_error.h"
#endif

#ifndef _MTV_CUSTOM_H
#include "mtv_custom.h"
#endif

/* common constants */

#define MTV_CONTROL_MOD         MOD_MED
#define MTV_TRANSPORT_MOD       MOD_MED
#define MTV_BACKGROUND_MOD      MOD_MTV
#define MTV_ASYNC_IO_MOD        MOD_MED_V

/* helper macros */

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

#ifndef UNUSED
#define UNUSED(p) ((void)(p))
#endif

#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define PTHIS(p, parent, member) (parent*)(((int)p) - OFFSET_OF(parent,member))

#define TS_PACKET_BYTES 188
#define LEN_ADTS_HEADER 7

#define ENDIAN_FLIP(v) ( ((v) << 24) + (((v) & 0x0000ff00) << 8) + (((v) & 0x00ff0000) >> 8) + (((v) & 0xff000000) >> 24) )

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

/* debugging support */

#define NOT_REACHED(msg) ASSERT(msg && 0)
#define NOT_IMPLEMENTED(msg) ASSERT(msg && 0)
#define SHOULD_NOT_HAPPEN(msg) ASSERT(msg && 0)

#define _MTV_SLA_LOGGING
#if defined(_MTV_SLA_LOGGING) && defined(__MTK_TARGET__)
    #define SLA_BEGIN(job) SLA_CustomLogging(job, SA_start)
    #define SLA_END(job) SLA_CustomLogging(job, SA_stop)
    #define SLA_LABEL(job) SLA_CustomLogging(job, SA_label)
#else
    #define SLA_BEGIN(job) do {} while (0)
    #define SLA_END(job) do {} while (0)
    #define SLA_LABEL(job) do {} while (0)
#endif

#define _MTV_DEBUG
#if defined(_MTV_DEBUG)
#define mtv_prompt_trace kal_prompt_trace
#else
#define mtv_prompt_trace if (0) kal_prompt_trace
#endif

#define mtv_error_from_fs(fs_error) (fs_error < 0 ? (MTV_IO_E_BASE + (fs_error)) : MTV_S_OK)

/* common structures */

typedef enum
{
    MTV_PACKET_FROM_CL_TDMB_DEMUX        = 0x0001,   /**< this packet is from CyberLink's demux */
    MTV_PACKET_WITH_ADTS_HEADER          = 0X0002,   /**< this packet contains ADTS header */
    MTV_PACKET_WITH_H264_START_CODE      = 0X0004,   /**< this packet contains H.264 start code */
    MTV_PACKET_WITH_RANDOM_ACCESS_POINT  = 0x0008    /**< this packet contains random access point of elementary stream */

} mtv_packet_flag_t;

/**
  * Generic data packet that is used to pass any data with timestamp.
  */
typedef struct
{
    kal_uint8* data;        /**< data pointer */
    kal_uint32 size;        /**< data size in bytes */
    kal_uint32 timestamp;   /**< the timestamp */
    kal_uint32 flags;       /**< flags to indicate some special packets. @see mtv_packet_flag_t */

} mtv_packet_t;

/**
  * Frequency band.
  */
typedef enum
{
    MTV_FREQ_INVALID_BAND,
    MTV_FREQ_KOREA_BAND,
    MTV_FREQ_BAND_III,
    MTV_FREQ_L_BAND,
    MTV_FREQ_CANADA_BAND,
    MTV_FREQ_CHINESE_BAND,
    MTV_FREQ_BAND_II,
    MTV_FREQ_BAND_IF

} mtv_freq_band_t;

/* utility functions */

extern kal_wchar* mtv_filename_dup(const kal_wchar* from);
extern kal_wchar* mtv_generate_new_filename(const kal_wchar* dir, const kal_wchar* basename, const kal_wchar* extname);
extern kal_wchar* mtv_str_dup(const kal_wchar* from, kal_uint32 max_len);

typedef kal_bool (*mtv_process_file_callback)(void* param, kal_wchar* filename);
extern kal_uint32 mtv_process_files(const kal_wchar* dir, const kal_wchar* pattern, mtv_process_file_callback process_file, void* callback_param);

/* global variables */

extern kal_mutexid g_mtv_transport_lock;

extern void mtv_take_transport_lock(void);
extern void mtv_give_transport_lock(void);

/* MSVC-specific */

#if defined(_MSC_VER)
#pragma warning(disable:4514 4127)
#endif

/* enable this macro to use simulated DAB demodulator with MPEG-2 TS */
/*#define _MTV_USE_TDMB_TS_DEMOD*/

#endif /* _MTV_COMM_H */
