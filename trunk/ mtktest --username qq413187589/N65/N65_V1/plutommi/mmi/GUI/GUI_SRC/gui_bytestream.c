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
 *   gui_bytestream.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Bytestream Interface for Image Decoder
 *
 *   (Deprecated by gdi_bytestream.c)
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      gui_bytestream.c
   Author:        manju
   Date Created:  June-10-2002
   Contains:      bytestream data type
               These are used to process ROM images of binary files
**********************************************************************************/

#include "gui_bytestream.h"

#define GUI_BYTESTREAM_IRAM_PLACEMENT     0

#if(GUI_BYTESTREAM_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code = "INTERNCODE"
#endif 
#endif /* (GUI_BYTESTREAM_IRAM_PLACEMENT) */ 


/*****************************************************************************
 * FUNCTION
 *  bytestream_initialize
 * DESCRIPTION
 *  initialize a bytestraem
 * PARAMETERS
 *  file        [IN]        
 *  data        [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bytestream_initialize(bytestream *file, U8 *data, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file->data = data;
    file->size = size;
    file->current_offset = 0;
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fclose
 * DESCRIPTION
 *  close teh file
 * PARAMETERS
 *  file        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bytestream_fclose(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file->data = NULL;
    file->size = 0;
    file->current_offset = 0;
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fseek
 * DESCRIPTION
 *  seek a file pointer to particular position
 * PARAMETERS
 *  file        [IN]        
 *  offset      [IN]        
 *  mode        [IN]        
 * RETURNS
 *  byte- //true or false
 *****************************************************************************/
U8 bytestream_fseek(bytestream *file, S32 offset, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_offset, final_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode)
    {
        case SEEK_END:
            start_offset = file->size - 1;
            break;
        case SEEK_SET:
            start_offset = 0;
            break;
        case SEEK_CUR:
        default:
            start_offset = file->current_offset;
            break;
    }
    final_offset = start_offset + offset;
    if (final_offset < 0 || final_offset >= file->size)
    {
        return (1);
    }
    else
    {
        file->current_offset = final_offset;
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_feof
 * DESCRIPTION
 *  check if end of file
 * PARAMETERS
 *  file        [IN]        
 * RETURNS
 *  byte- //true or false
 *****************************************************************************/
U8 bytestream_feof(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file->current_offset >= file->size)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fgetbyte
 * DESCRIPTION
 *  read a byte from fiel
 * PARAMETERS
 *  file        [IN]        
 * RETURNS
 *  byte-
 *****************************************************************************/
U8 bytestream_fgetbyte(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bytestream_feof(file))
    {
        return (0);
    }
    c = file->data[file->current_offset];
    file->current_offset++;
    return (c);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fputbyte
 * DESCRIPTION
 *  insert a byte in file
 * PARAMETERS
 *  file        [IN]        
 *  c           [IN]        
 * RETURNS
 *  byte- true or flase
 *****************************************************************************/
U8 bytestream_fputbyte(bytestream *file, U8 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bytestream_feof(file))
    {
        return (0);
    }
    file->data[file->current_offset] = c;
    file->current_offset++;
    return (1);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fread
 * DESCRIPTION
 *  get  word
 * PARAMETERS
 *  buffer      [OUT]       Data read from file
 *  size        [IN]        // size of data
 *  number      [IN]        // number of bytes to read
 *  file        [IN]        File pointer
 * RETURNS
 *  size_t return number of bytes read from file
 *****************************************************************************/
size_t bytestream_fread(U8 *buffer, size_t size, size_t number, bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = (U32) size * number; i; i--)
    {
        if (bytestream_feof(file))
        {
            break;
        }
        buffer[count++] = bytestream_fgetbyte(file);
    }
    return (count);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fgetword
 * DESCRIPTION
 *  get  word
 * PARAMETERS
 *  file            [?]         
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  word
 *****************************************************************************/
U16 bytestream_fgetword(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 MSB, LSB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LSB = bytestream_fgetbyte(file);
    MSB = bytestream_fgetbyte(file);
    return ((U16) ((MSB << 8) | LSB));
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fgetdword
 * DESCRIPTION
 *  get  U32
 * PARAMETERS
 *  file            [?]         
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  U32
 *****************************************************************************/
U32 bytestream_fgetdword(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 MSB, LSB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LSB = bytestream_fgetword(file);
    MSB = bytestream_fgetword(file);
    return ((MSB << 16) | LSB);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fputword
 * DESCRIPTION
 *  insert  word in  big endian format in file
 * PARAMETERS
 *  file            [?]         
 *  w               [IN]        
 *  word(?)         [IN]        D
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  byte
 *****************************************************************************/
U8 bytestream_fputword(bytestream *file, U16 w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 MSB, LSB, rvalue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LSB = (U8) (w & 0xff);
    MSB = (U8) (w >> 8);
    rvalue = bytestream_fputbyte(file, LSB);
    rvalue = bytestream_fputbyte(file, MSB);
    return (rvalue);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fputword_bigendian
 * DESCRIPTION
 *  insert  word in  big endian format in file
 * PARAMETERS
 *  file            [?]         
 *  w               [IN]        
 *  word(?)         [IN]        D
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  byte
 *****************************************************************************/
U8 bytestream_fputword_bigendian(bytestream *file, U16 w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 MSB, LSB, rvalue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LSB = (U8) (w & 0xff);
    MSB = (U8) (w >> 8);
    rvalue = bytestream_fputbyte(file, MSB);
    rvalue = bytestream_fputbyte(file, LSB);
    return (rvalue);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fputdword
 * DESCRIPTION
 *  insert  U32 in  big endian format in file
 * PARAMETERS
 *  file            [?]         
 *  d               [IN]        
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  byte
 *****************************************************************************/
U8 bytestream_fputdword(bytestream *file, U32 d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 MSB, LSB;
    U8 rvalue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LSB = (U16) (d & 0xffff);
    MSB = (U16) (d >> 16);
    rvalue = bytestream_fputword(file, LSB);
    rvalue = bytestream_fputword(file, MSB);
    return (rvalue);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fputdword_bigendian
 * DESCRIPTION
 *  insert  U32 in  big endian format in file
 * PARAMETERS
 *  file            [?]         
 *  d               [IN]        
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  byte
 *****************************************************************************/
U8 bytestream_fputdword_bigendian(bytestream *file, U32 d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 MSB, LSB;
    U8 rvalue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LSB = (U16) (d & 0xffff);
    MSB = (U16) (d >> 16);
    rvalue = bytestream_fputword_bigendian(file, MSB);
    rvalue = bytestream_fputword_bigendian(file, LSB);
    return (rvalue);
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fgetword_bigendian
 * DESCRIPTION
 *  get word in  big endian format fron file
 * PARAMETERS
 *  file            [?]         
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  word
 *****************************************************************************/
U16 bytestream_fgetword_bigendian(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 MSB, LSB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSB = bytestream_fgetbyte(file);
    LSB = bytestream_fgetbyte(file);
    return ((U16) ((MSB << 8) | LSB));
}


/*****************************************************************************
 * FUNCTION
 *  bytestream_fgetdword_bigendian
 * DESCRIPTION
 *  get dwordin big endian format fron file
 * PARAMETERS
 *  file            [?]         
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  U32
 *****************************************************************************/
U32 bytestream_fgetdword_bigendian(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 MSB, LSB;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSB = bytestream_fgetword_bigendian(file);
    LSB = bytestream_fgetword_bigendian(file);
    return ((MSB << 16) | LSB);
}

#if(GUI_BYTESTREAM_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (GUI_BYTESTREAM_IRAM_PLACEMENT) */ 


/*****************************************************************************
 * FUNCTION
 *  bytestream_fgetvdata
 * DESCRIPTION
 *  Used to read variable length data: Useful only for MIDI files
 * PARAMETERS
 *  file            [?]         
 *  pointer(?)      [IN]        Of file
 * RETURNS
 *  void
 *****************************************************************************/
/* Used to read variable length data: Useful only for MIDI files  */
U32 bytestream_fgetvdata(bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rvalue;
    U8 b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((rvalue = bytestream_fgetbyte(file)) & 0x80)
    {
        rvalue &= 0x7f;
        do
        {
            rvalue = (rvalue << 7) + ((b = bytestream_fgetbyte(file)) & 0x7f);
        } while (b & 0x80);
    }
    return (rvalue);
}

