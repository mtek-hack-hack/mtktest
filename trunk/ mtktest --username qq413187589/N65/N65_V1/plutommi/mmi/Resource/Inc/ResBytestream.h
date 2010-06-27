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
 *  ResBytestream.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   External tool required for the MMI

   Filename:      bytestream.h
   Author:        manju
   Date Created:  June-10-2002
   Contains:      bytestream data type header file
               These are used to process ROM images of binary files
**********************************************************************************/

#ifndef __BYTESTREAM_H__
#define __BYTESTREAM_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include <stdio.h>
#include <stdlib.h>
#include "ResDevice.h"

    typedef struct _bytestream
    {
        long int size;
        long int current_offset;
        U8 *data;
    } bytestream;

    extern void bytestream_initialize(bytestream *file, U8 *data, long int size);
    extern void bytestream_fclose(bytestream *file);
    extern U8 bytestream_fseek(bytestream *file, long int offset, int mode);
    extern U8 bytestream_feof(bytestream *file);
    extern U8 bytestream_fgetbyte(bytestream *file);
    extern U8 bytestream_fputbyte(bytestream *file, U8 c);
    extern size_t bytestream_fread(U8 *buffer, size_t size, size_t number, bytestream *file);
    extern U16 bytestream_fgetword(bytestream *file);
    extern U32 bytestream_fgetdword(bytestream *file);
    extern U8 bytestream_fputword(bytestream *file, U16 w);
    extern U8 bytestream_fputword_bigendian(bytestream *file, U16 w);
    extern U8 bytestream_fputdword(bytestream *file, U32 d);
    extern U8 bytestream_fputdword_bigendian(bytestream *file, U32 d);
    extern U16 bytestream_fgetword_bigendian(bytestream *file);
    extern U32 bytestream_fgetdword_bigendian(bytestream *file);
    /* Used to read variable length data: Useful only for MIDI files  */
    extern U32 bytestream_fgetvdata(bytestream *file);

#ifdef __cplusplus
}
#endif 

#endif /* __BYTESTREAM_H__ */ 

