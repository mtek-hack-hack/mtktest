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
 *   stack_ltlcom.h
 *
 * Project:
 * --------
 *   Maui_Software
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/

#ifndef _APP_LTLCOM_H
#define _APP_LTLCOM_H

/*******************************************************************************
 * Macros Without Parameters
 *******************************************************************************/
#define LOCAL_PARA_HDR \
   kal_uint8	ref_count; \
   kal_uint16	msg_len;

#define PEER_BUFF_HDR \
   kal_uint16	pdu_len; \
   kal_uint8	ref_count; \
   kal_uint8   	pb_resvered; \
   kal_uint16	free_header_space; \
   kal_uint16	free_tail_space;

/*******************************************************************************
 * Type Definitions
 *******************************************************************************/
typedef enum {
   TD_UL = 0x01 << 0,   /* Uplink Direction */
   TD_DL = 0x01 << 1,   /* Downlink Direction */
   TD_CTRL = 0x01 << 2, /* Control Plane. Both directions */
   TD_RESET = 0x01 << 3 /* Reset buffer content to 0 */
} transfer_direction;

/*
 *  Peer message header passed between Layers for peer messages
 *  pdu_len: PDU data size (PDU data comes after PDU header)
 *
 *  free_header_spcae: Space left before the PDU data to place the
 *                      PDU header
 *
 *  free_tail_space: Space left after the PDU data to place the PDU
 *                   trailer
 *  pdu_len + free_header_space + free_tail_space is equl to the size
 *  of buffer allocated for the PDU
 */

typedef struct peer_buff_struct {
   PEER_BUFF_HDR /* XXX!!!. Rex Luo - I don't like the usage */
} peer_buff_struct;

/*
 *  Local parameter header
 *  msg_len : Numbfer of bytes after the ref_count field.
 *             Length is in bytes.
 *  ref_count : This is useful if a module wants to retain
 *               a buffer. Protocol stack module should access
 *               this field by calling hold_local_para()
 */

typedef struct local_para_struct {
   LOCAL_PARA_HDR   /*XXX!!!. Rex Luo - I don't like the usage */
} local_para_struct;

/*
 *  The Interlayer Message structure, which is exchaged between modules
 *
 *  src_mod_id : Source module ID of the message.
 *                This is defined only in the RPS_DEBUG version of
 *                the code, since only SME has to use it.
 *  dest_mod_id : Destination module ID of the message.
 *  sap_id      : Service Access Pointer Identifier.
 *                This is required only in the RPS_DEBUG version of
 *                the code, since only SME has to use it.
 *
 *  msg_id      : The inter layer message type exchanged between
 *                the modules.
 *
 * local_para_ptr: Pointer to the memory location that
 *                contains the local parameters of the ILM.
 *
 * peer_buff_ptr : Pointer to the buffer that contains the peer
 *                 message.
 */

typedef struct ilm_struct {
   module_type       src_mod_id;
   module_type       dest_mod_id;
   sap_type          sap_id;
   msg_type          msg_id;
   local_para_struct *local_para_ptr;
   peer_buff_struct  *peer_buff_ptr;
} ilm_struct;

/*******************************************************************************
 * Exported Function Prototypes
 *******************************************************************************/
extern void* construct_int_peer_buff(kal_uint16 pdu_len, kal_uint16 header_len, \
                                     kal_uint16 tail_len, kal_char* file_name_ptr, \
                                     kal_uint32 line);

/*
 * NoteXXX: construct_int_local_para is original in MCUROM. It is moved to Maui now.
 *          But To eliminate compile error when building MCUROM code, we need to keep
 *          the original function prototype.
 */
#if !defined(__BUILD_MCU_ROM__)
extern void* construct_int_local_para(kal_uint16 local_para_size, kal_uint32 auto_reset,
                                      kal_char* file_ptr, kal_uint32 line);
#else   /* !__BUILD_MCU_ROM__ */
extern void* construct_int_local_para(kal_uint16 local_para_size, kal_char* file_ptr, kal_uint32 line);
#endif  /* !__BUILD_MCU_ROM__ */

extern void free_int_peer_buff(peer_buff_struct *pdu_ptr, kal_char* file,
                               kal_uint32 line);

extern void free_int_local_para(local_para_struct *local_para_ptr,
                                kal_char* file, kal_uint32 line);

extern void free_int_peer_buff_r(peer_buff_struct *pdu_ptr, kal_char* file, kal_uint32 line);

extern void free_int_local_para_r(local_para_struct *local_para_ptr, kal_char* file, kal_uint32 line);

extern void* get_pdu_ptr(peer_buff_struct *peer_buff_ptr, kal_uint16 *length_ptr);

#if defined(DEBUG_KAL)

/* Function     : construct_local_para()
 * Input        :
 *   local_para_size:
 *      Lengh of local para contents.
 *   direction:
 *      transfer direction.( TD_CTRL, TD_UL or TD_DL ).
 * Return       : Returns a valid pointer on success.
 *
 * Description  : API allocates a local parameter structure
 *                of length local_para_size. The memory allocation is
 *                done from the control buffer pool of the stack.
 *                API always returns a valid pointer on success.
 *                If the control buffer pool is exhausted, a soft-reset
 *                will result. This API should be used for all cases
 *                except the data request and data indication primitives
 *                between application and protocol stack.( RLC<->App,
 *                RABM<->App ).
 */
#define construct_local_para(local_para_size, direction) \
        construct_int_local_para(local_para_size, ((direction & TD_RESET) != 0)? 1: 0, __FILE__, __LINE__)

/* Function     : construct_peer_buff()
 * Input        :
 *  pdu_len:
 *    The length of the PDU.
 *  hdr_len:
 *     Length of the PDU header reserved for upper/lower layer.
 *  tail_len:
 *     Length of the PDU tail reserved for upper/lower layer.
 * Return       : Returns a valid pointer on success.
 * Description  : Function allocates a peer buffer structure.
 *                Memory allocation is done from the control buffer
 *                pool of the stack. If the control buffer pools are
 *                exhausted, a soft-reset will result. So, the caller
 *                need not validate the return pointer.
 *                This API should be used for all cases except the
 *                data request and data indication primitives
 *                between application and protocol stack.( RLC<->App,
 *                RABM<->App ).
 */
#define construct_peer_buff(pdu_len, header_len, tail_len, direction) \
        construct_int_peer_buff(pdu_len, header_len, tail_len, __FILE__, __LINE__)

/* Function     : construct_uplane_local_para()
 * Input        :
 *  local_pra_size:
 *                Length of local para contents.
 *  direction:
 *                direction of transfer. TD_UL,TD_DL or TD_CTRL.
 *  alloc_fptr:
 *                Pointer to the memory allocation function.
 *  status_ptr:
 *                address of memory location where the status
 *                of the buffer pool from where memory allocation is
 *                done is returned.
 * Return       : Returns a valid pointer on success. NULL on
 *                failure. If *status_ptr contains FLC_SDU_STATUS_UTHR_HIT
 *                or FLC_SDU_STATUS_LTHR_HIT, the caller should
 *                initiate flow control operations.
 *
 * Description  : Function allocates a local parameter structure
 *                of length local_para_size. The memory allocation is
 *                done using the function pointed by 'alloc_fptr'.
 *                This API should be used for only the
 *                data request and data indication primitives
 *                between application and protocol stack.( RLC<->App,
 *                RABM<->App ).
 */
#define construct_uplane_local_para(local_para_size, direction, alloc_fptr, status_ptr) \
        construct_int_uplane_local_para(local_para_size, (direction & TD_RESET) != 0), alloc_fptr, status_ptr , __FILE__, __LINE__)

/* Function     : free_local_para().
 * Input        :
 *   local_para:
 *      Pointer to the local parameter structure.
 * Return       : None.
 *
 * Description  : Function frees the local parameter structure created
 *                using 'construct_local_para()'. This API
 *                should be used for all cases except the data
 *                request and data indication primitives between
 *                application and protocol stack.( RLC<->App,
 *                RABM<->App ).
 */
#define free_local_para(local_para) free_int_local_para(local_para, __FILE__, __LINE__)

#define free_local_para_r(local_para) free_int_local_para_r(local_para, __FILE__, __LINE__)

/* Function     : free_uplane_local_para().
 * Input        :
 *   local_para:
 *      Pointer to the local parameter structure.
 *   free_fptr:
 *      Pointer to the function to be used for freeing local parameter.
 *   status_ptr:
 *      Address of the memory location at which the buffer status is
 *      returned.
 * Return       : None.
 *
 * Description  : API frees the local parameter structure created
 *                using 'construct_uplane_local_para()'. This API
 *                should be used only for the data transfer and data
 *                receive primitives between application and stack.
 *                (Application<->RLC, Application<->RABM).The free_fptr
 *                should point to the SDU buffer free function
 *                provided by application at call setup time.
 *                The caller should take flow control actions if
 *                *status_ptr contains FLC_SDU_STATUS_LTHR_HIT
 *                or FLC_SDU_STATUS_UTHR_HIT.
 */
#define free_uplane_local_para( local_para,free_fptr, status_ptr) \
        free_int_uplane_local_para(local_para, free_fptr, status_ptr, __FILE__, __LINE__)

/* Function     : free_peer_buff()
 * Input        :
 *   local_para:
 *      Pointer to the peer buffer structure.
 * Return       : None.
 *
 * Description  : Function frees the peer buffer structure created
 *                using 'construct_peer_buff()'. This API
 *                should be used for all cases except the data
 *                request and data indication primitives between
 *                application and protocol stack.( RLC<->App,
 *                RABM<->App ).
 */
#define free_peer_buff(peer_buff) free_int_peer_buff(peer_buff, __FILE__, __LINE__)

#define free_peer_buff_r(peer_buff) free_int_peer_buff_r(peer_buff, __FILE__, __LINE__)

/* Function     : free_uplane_peer_buff()
 * Input        :
 *   local_para:
 *      Pointer to the peer buffer structure.
 *   free_fptr:
 *      Pointer to the function to be used for freeing local parameter.
 *   status_ptr:
 *      Address of the memory location at which the buffer status is
 *      returned.
 * Return       : None.
 *
 * Description  : Function frees the peer buffer structure created
 *                using 'construct_uplane_peer_buff()'. This primitive
 *                should be used for only the data
 *                request and data indication primitives between
 *                application and protocol stack.( RLC<->App,
 *                RABM<->App ). The free_fptr should point to the
 *                SDU buffer free function provided by application
 *                at call setup time. The caller should take
 *                flow control actions if *status_ptr contains
 *                FLC_SDU_STATUS_LTHR_HIT or FLC_SDU_STATUS_UTHR_HIT.
 */
#define free_uplane_peer_buff( pdu_ptr, free_fptr, status_ptr) \
        free_int_uplane_peer_buff(pdu_ptr, free_fptr, status_ptr, __FILE__, __LINE__)

#else   /* DEBUG_KAL */

#define construct_local_para(local_para_size, direction) \
        construct_int_local_para(local_para_size, (direction == TD_RESET)? 1: 0, NULL, 0)

#define construct_peer_buff(pdu_len, header_len, tail_len, direction) \
        construct_int_peer_buff(pdu_len, header_len, tail_len, NULL, 0)

#define free_local_para(local_para) free_int_local_para(local_para, NULL, 0)

#define free_local_para_r(local_para) free_int_local_para_r(local_para, NULL, 0)

#define free_peer_buff(peer_buff) free_int_peer_buff(peer_buff, NULL, 0)

#define free_peer_buff_r(peer_buff) free_int_peer_buff_r(peer_buff, NULL, 0)


#endif /* DEBUG_KAL */

extern void free_int_ilm(ilm_struct *ilm_ptr, kal_char* file_name, kal_uint32 line);

/*******************************************************************************
 * Macros Without Parameters
 *******************************************************************************/
#if defined(__MTK_TARGET__ ) || defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR)
#include "stack_ltlcom.h"
#endif /* __MTK_TARGET__ || MTK_KAL_MNT || KAL_ON_OSCAR */

#endif /* _APP_LTLCOM_H */


