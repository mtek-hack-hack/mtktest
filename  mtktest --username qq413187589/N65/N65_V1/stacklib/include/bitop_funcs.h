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
 *   bitop_funcs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Functions for putting and getting bit fields into
 *   byte arrays.
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

#ifndef _BITOP_FUNCS_H
#define _BITOP_FUNCS_H

/***************************************************************************
 * Exported Function Prototypes
 ***************************************************************************/
extern unsigned int mask(unsigned int width);

extern unsigned int get_bits_1_8(
                          kal_uint8    *addr,
                          unsigned int offset,
                          unsigned int width
                          );

extern unsigned int get_bits_9_16(
                           kal_uint8    *addr,
                           unsigned int offset,
                           unsigned int width
                           );

extern unsigned int get_bits_17_24(
                            kal_uint8    *addr,
                            unsigned int offset,
                            unsigned int width
                            );

extern unsigned int get_bits_25_32(
                            kal_uint8    *addr,
                            unsigned int offset,
                            unsigned int width
                            );


extern unsigned int get_bits(
                      kal_uint8    *addr,
                      unsigned int offset,
                      unsigned int width
                      );


extern void put_bits_1_8(
                  kal_uint8 *addr,
                  unsigned int offset,
                  unsigned int width,
                  unsigned int put_val
                  );


extern void put_bits_9_16(
                   kal_uint8    *addr,
                   unsigned int offset,
                   unsigned int width,
                   unsigned int put_val
                   );


extern void put_bits_17_24(
                   kal_uint8    *addr,
                   unsigned int offset,
                   unsigned int width,
                   unsigned int put_val
                   );

extern void put_bits_25_32(
                   kal_uint8    *addr,
                   unsigned int offset,
                   unsigned int width,
                   unsigned int put_val
                   );


extern void put_bits(
              kal_uint8    *addr,
              unsigned int offset,
              unsigned int width,
              unsigned int put_val
              );

/* constants for shift directions */
#define SHIFT_LEFT  1
#define SHIFT_RIGHT 2

/* Length of a static buffer */
#define SHIFT_BUFFER_LEN 255

void copy_bits16(const kal_uint8 *pzSrc,
                 kal_uint16      u16SrcIndex,
                 kal_uint8       *pzDst,
                 kal_uint16      *pu16DstIndex,
                 kal_uint16      u16NumBits);

kal_uint16 shift_bits16(kal_uint8   *pzSrc,
                      kal_uint8     *pzDest,
                      kal_uint16    u16SizeInBytes,
                      kal_uint16    u16ShiftBits,
                      kal_uint16    u16Direction);

/***************************************************************************
 * Declarations Of Exported Globals
 ***************************************************************************/

#endif /* _BITOP_FUNCS_H */

