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
 *	 bytestream_hw.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Abstract file and memory data source.
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
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h" 
#include "fat_fs.h"				/* for access file system */
#include "drm_gprot.h"
#include "bytestream_hw.h"
/* Function pointer table */

hw_bytestream_dcb_struct hw_bytestream_dcb[HW_BYTESTREAM_OWNER_NUM];

/**************************************************************

	FUNCTION NAME		: hw_bytestream_free

  	PURPOSE				: free a bytestream

	INPUT PARAMETERS	: void
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: hw_RESULT

	REMARKS				: nil

***************************************************************/
void hw_bytestream_free(kal_uint32 owner)
{
	/*
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];
	
	if(p->hw_bytestream_source_type == HW_BYTESTREAM_TYPE_FILE)
	{
		(void)DRM_close_file(p->file.p->type.file.file_handle);
	}
	else
	{
		ASSERT(p->hw_bytestream_source_type == HW_BYTESTREAM_TYPE_MEM);
	}
	*/

}



/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_byte_mem

  	PURPOSE				: get a byte from memory

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint8

	REMARKS				: nil

***************************************************************/
kal_uint8	hw_bytestream_get_byte_mem(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	kal_uint8 v = (kal_uint8)p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	
	if(p->type.mem.buffer_offset <= p->type.mem.buffer_size)
	{
		return v;
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
	}
	return 0;
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_byte_mem

  	PURPOSE				: peek a byte from memory

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint8

	REMARKS				: nil

***************************************************************/
kal_uint8	hw_bytestream_peek_byte_mem(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];
	
	if(p->type.mem.buffer_offset+1 <= p->type.mem.buffer_size)
	{
		return (kal_uint8)p->type.mem.buffer_ptr[p->type.mem.buffer_offset];
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
	}
	return 0;
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_peek_byte_n_mem

  	PURPOSE				: peek one byte after n bytes

	INPUT PARAMETERS	: int index
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint8

	REMARKS				: nil

***************************************************************/
kal_uint8	hw_bytestream_peek_byte_n_mem(kal_uint32 owner, kal_uint32 index) 
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	kal_uint32 offset = p->type.mem.buffer_offset+index;
	
	if(offset+1 <= p->type.mem.buffer_size)
	{
		return (kal_uint8)p->type.mem.buffer_ptr[offset];
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
		return 0; /* Unreached */
	}
}



/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_word_mem

  	PURPOSE				: peek a word from memory

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint16

	REMARKS				: nil

***************************************************************/
kal_uint16 hw_bytestream_get_word_mem(kal_uint32 owner,hw_bytestream_endian_enum endian)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	kal_uint32 byte0;
	kal_uint32 byte1;
	
	byte0 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	byte1 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];

	if(p->type.mem.buffer_offset <= p->type.mem.buffer_size)
	{
		if(endian == LITTLE_ENDIAN)
			return ((kal_uint16)((byte1<<8)|byte0));
		else
			return ((kal_uint16)((byte0<<8)|byte1));
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
		return 0; // Unreached
	}
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_word_mem

  	PURPOSE				: peek a word from memory

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint16

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_get_3bytes_mem(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];		
	kal_uint32 byte0;
	kal_uint32 byte1;
	kal_uint32 byte2;

	byte0 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	byte1 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	byte2 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];

	if(p->type.mem.buffer_offset <= p->type.mem.buffer_size)
	{
		return ((kal_uint32)((byte2<<16)|(byte1<<8)|byte0));
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
		return 0; // Unreached
	}
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_dword_mem

  	PURPOSE				: peek a dword from memory

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint32

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_get_dword_mem(kal_uint32 owner,hw_bytestream_endian_enum endian)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];		
	kal_uint32 byte0;
	kal_uint32 byte1;
	kal_uint32 byte2;
	kal_uint32 byte3;
	
	byte0 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	byte1 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	byte2 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];
	byte3 = p->type.mem.buffer_ptr[p->type.mem.buffer_offset++];	
	if(p->type.mem.buffer_offset <= p->type.mem.buffer_size)
	{
		if(endian == LITTLE_ENDIAN)
			return  ((kal_uint32)(byte3<<24))|((kal_uint32)(byte2<<16))|((kal_uint32)(byte1<<8))|(kal_uint32)(byte0);
		else
			return  ((kal_uint32)(byte0<<24))|((kal_uint32)(byte1<<16))|((kal_uint32)(byte2<<8))|(kal_uint32)(byte3);			
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
		return 0; // Unreached code
	}
}
void hw_bytestream_get_array_mem(kal_uint32 owner, kal_uint8 * array,kal_uint32 size)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	if( p->type.mem.buffer_offset + size <= p->type.mem.buffer_size)
	{
		memcpy(array,p->type.mem.buffer_ptr+p->type.mem.buffer_offset,size);
		p->type.mem.buffer_offset += size;
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
		return; // Unreached code
	}
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_is_eof_mem

  	PURPOSE				: chcek if is eof

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_bool

	REMARKS				: nil

***************************************************************/
kal_bool hw_bytestream_is_eof_mem(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	return  (kal_bool)(p->type.mem.buffer_offset >= p->type.mem.buffer_size);
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_flush_mem 

  	PURPOSE				: flush memory

	INPUT PARAMETERS	: kal_uint32 count
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void hw_bytestream_flush_mem(kal_uint32 owner, kal_uint32 count)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	// It allows to stop at the end of stream plus one byte
	if( (p->type.mem.buffer_offset += count) > p->type.mem.buffer_size)
		BYTESTREAM_RAISE(owner,1);
	}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_seek_mem 

  	PURPOSE				: seek memory

	INPUT PARAMETERS	: kal_int32 offset
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void hw_bytestream_seek_mem(kal_uint32 owner, kal_int32 offset)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	// It allows to stop at the end of stream plus one byte
	if (offset <= (kal_int32)p->type.mem.buffer_size)
	{
		p->type.mem.buffer_offset = offset;
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
	}
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_tell_mem 

  	PURPOSE				: tell memory

	INPUT PARAMETERS	: kal_int32 offset
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_int32

	REMARKS				: nil

***************************************************************/
kal_int32 hw_bytestream_tell_mem(kal_uint32 owner, hw_bytestream_dcb_struct **info)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	

	if(info != NULL)
		*info = p;
	return p->type.mem.buffer_offset;
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_size_mem 

  	PURPOSE				: get size of memory

	INPUT PARAMETERS	: kal_int32 offset
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint32

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_get_size_mem(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	return p->type.mem.buffer_size;
}
/**************************************************************

	FUNCTION NAME		: hw_bytestream_refill_file 

  	PURPOSE				: refill the buffer with valid data
	INPUT PARAMETERS	: void
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: nil

	REMARKS				: nil

***************************************************************/
void hw_bytestream_refill_mem(kal_uint32 owner)
{
}


//--------------------------------------------------------------//
// bytestream of file type start here
//--------------------------------------------------------------//
void hw_bytestream_buffer_load_file(kal_uint32 owner, int at_least)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	int offset;
	
	offset = p->type.file.buffer_content_size; 
	if(offset)
		memcpy(p->type.file.buffer_ptr,p->type.file.buffer_reader,offset);
	
	if((DRM_read_file(p->type.file.file_handle,
				p->type.file.buffer_ptr+offset,p->type.file.buffer_size-offset,
				(UINT*)&p->type.file.buffer_content_size) == FS_NO_ERROR)
	&& p->type.file.buffer_content_size>0)
	{
		p->type.file.buffer_reader = p->type.file.buffer_ptr;
		p->type.file.buffer_content_size += offset;

		if(p->type.file.buffer_content_size >= at_least)
			return;
	}
	else
	{
		BYTESTREAM_RAISE(owner,1);
	}
}

kal_bool hw_bytestream_buffer_load_file_widthout_exception(kal_uint32 owner, int at_least)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	int offset;
	offset = p->type.file.buffer_content_size;
	if(offset)
		memcpy(p->type.file.buffer_ptr,p->type.file.buffer_reader,p->type.file.buffer_content_size);
	
	if((DRM_read_file(p->type.file.file_handle,
				p->type.file.buffer_ptr+offset,p->type.file.buffer_size-offset,
				(UINT*)&p->type.file.buffer_content_size) == FS_NO_ERROR)
	&& p->type.file.buffer_content_size>0)
	{
		p->type.file.buffer_reader = p->type.file.buffer_ptr;
		p->type.file.buffer_content_size += offset;

		if(p->type.file.buffer_content_size >= at_least)
			return KAL_TRUE;
	}
	return KAL_FALSE;
}
/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_byte_file 

  	PURPOSE				: get a byte from file 

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint8

	REMARKS				: nil

***************************************************************/
kal_uint8	hw_bytestream_get_byte_file(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	if(!(p->type.file.buffer_content_size))
		hw_bytestream_buffer_load_file(owner, 1);

	p->type.file.buffer_content_size--;

	p->type.file.file_offset++;

	return *p->type.file.buffer_reader++;
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_byte_file 

  	PURPOSE				: peek a byte from file 

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint8

	REMARKS				: nil

***************************************************************/
kal_uint8	hw_bytestream_peek_byte_file(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	if(!p->type.file.buffer_content_size)
		hw_bytestream_buffer_load_file(owner, 1);

	return *p->type.file.buffer_reader;
}
/**************************************************************

	FUNCTION NAME		: hw_bytestream_peek_byte_n_file 

  	PURPOSE				: peek n byte from file 

	INPUT PARAMETERS	: int index
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint8

	REMARKS				: nil

***************************************************************/
kal_uint8	hw_bytestream_peek_byte_n_file(kal_uint32 owner, kal_uint32 index)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	if(p->type.file.buffer_content_size<index)
		hw_bytestream_buffer_load_file(owner, index);
	
	return p->type.file.buffer_reader[index];
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_word_file 

  	PURPOSE				: peek a word from file (16 bit)

	INPUT PARAMETERS	: void 
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint16

	REMARKS				: nil

***************************************************************/
kal_uint16 hw_bytestream_get_word_file(kal_uint32 owner,hw_bytestream_endian_enum endian)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	kal_uint16 result;
	
	if(p->type.file.buffer_content_size<2)
		hw_bytestream_buffer_load_file(owner, 2);
	
	p->type.file.buffer_content_size-=2;
	p->type.file.file_offset+=2;

	if(endian == LITTLE_ENDIAN)
	{
		result = *p->type.file.buffer_reader++;
		result |= (*p->type.file.buffer_reader++) << 8;
	}
	else
	{
		result = *p->type.file.buffer_reader++ << 8;
		result |= (*p->type.file.buffer_reader++);
	}
	return result;
}




/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_word_file 

  	PURPOSE				: peek a word from file (16 bit)

	INPUT PARAMETERS	: void 
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint16

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_get_3bytes_file(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	kal_uint32 result;
	
	if(p->type.file.buffer_content_size<3)
		hw_bytestream_buffer_load_file(owner, 3);
	
	p->type.file.buffer_content_size-=3;
	p->type.file.file_offset+=3;

	result = *p->type.file.buffer_reader++;
	result |= (*p->type.file.buffer_reader++) << 8;
	result |= (*p->type.file.buffer_reader++) << 16;
	return result;
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_dword_file 

  	PURPOSE				: get a dword from file (32 bit)

	INPUT PARAMETERS	: int index
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint32

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_get_dword_file(kal_uint32 owner, hw_bytestream_endian_enum endian)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	kal_uint32 result;
	
	if(p->type.file.buffer_content_size<4)
		hw_bytestream_buffer_load_file(owner, 4);

	p->type.file.buffer_content_size-=4;
	p->type.file.file_offset+=4;	

	if(endian == LITTLE_ENDIAN)
	{
		result = *p->type.file.buffer_reader++;
		result |= (*p->type.file.buffer_reader++) << 8;
		result |= (*p->type.file.buffer_reader++) << 16;
		result |= (*p->type.file.buffer_reader++) << 24;
	}
	else
	{
		result  = (*p->type.file.buffer_reader++) << 24;
		result |= (*p->type.file.buffer_reader++) << 16;
		result |= (*p->type.file.buffer_reader++) << 8;
		result |= (*p->type.file.buffer_reader++);
		
	}
	return result;
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_array_file 

  	PURPOSE				: get a dword from file (32 bit)

	INPUT PARAMETERS	: int index
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint32

	REMARKS				: nil

***************************************************************/
void hw_bytestream_get_array_file(kal_uint32 owner, kal_uint8 * array,kal_uint32 size)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	while(size>0)
	{
		int n;
		if(p->type.file.buffer_content_size == 0)
			hw_bytestream_buffer_load_file(owner, 1);
		
		n= MIN(size,p->type.file.buffer_content_size);
		memcpy(array,p->type.file.buffer_reader,n);
		array+=n;
		p->type.file.buffer_content_size -=n;
		size -= n;
		p->type.file.file_offset+=n;
		p->type.file.buffer_reader+=n;
	}
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_is_eof_file 

  	PURPOSE				: check is eof 

	INPUT PARAMETERS	: nil
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_bool

	REMARKS				: nil

***************************************************************/
kal_bool hw_bytestream_is_eof_file(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	if(p->type.file.buffer_content_size)
		return KAL_FALSE;

	if(hw_bytestream_buffer_load_file_widthout_exception(owner, 1))
		return KAL_FALSE;
	
	return KAL_TRUE;
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_seek_file 

  	PURPOSE				: seek file bytestream 

	INPUT PARAMETERS	: kal_int32 offset
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
void hw_bytestream_seek_file(kal_uint32 owner, kal_int32 offset)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	int ret;
	
	ret = DRM_seek_file(p->type.file.file_handle,offset,FS_FILE_BEGIN);
	p->type.file.buffer_content_size = 0;
	p->type.file.file_offset = offset;

	if ((ret<0) || (ret!=(int)offset))
	{
		BYTESTREAM_RAISE(owner,1);
	}
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_flush_file 

  	PURPOSE				: flush file bytestream 

	INPUT PARAMETERS	: kal_uint32 count
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

***************************************************************/
/* Note: FSAL does not check the availability of data until issuing read/write operations */
void hw_bytestream_flush_file(kal_uint32 owner, kal_uint32 count)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	p->type.file.file_offset+=count;
	if(count >= p->type.file.buffer_size)
	{
		hw_bytestream_seek_file(owner, p->type.file.file_offset);
		return;
	}
	while(count)
	{
		if(p->type.file.buffer_content_size < (int)count)
		{
			count -= p->type.file.buffer_content_size;
			p->type.file.buffer_content_size=0;
			hw_bytestream_buffer_load_file(owner, 1);
		}
		else
		{
			p->type.file.buffer_content_size-=count;
			p->type.file.buffer_reader +=count;
			count=0;
		}
	}
}





/**************************************************************

	FUNCTION NAME		: hw_bytestream_tell_file 

  	PURPOSE				: tell file bytestream 

	INPUT PARAMETERS	: void
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_int32

	REMARKS				: nil

***************************************************************/
kal_int32 hw_bytestream_tell_file(kal_uint32 owner, hw_bytestream_dcb_struct **info )
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	
	if(info != NULL)
		*info = p;
	return p->type.file.file_offset;
}


/**************************************************************

	FUNCTION NAME		: hw_bytestream_get_size_file 

  	PURPOSE				: get size of file bytestream 

	INPUT PARAMETERS	: void
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: kal_uint32

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_get_size_file(kal_uint32 owner)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	
	return p->type.file.file_size;
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_refill_file 

  	PURPOSE				: refill the buffer with valid data
	INPUT PARAMETERS	: void
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: nil

	REMARKS				: nil

***************************************************************/
void hw_bytestream_refill_file(kal_uint32 owner)
{
	hw_bytestream_buffer_load_file(owner,1);
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_create

  	PURPOSE				: create a memory bytestream

	INPUT PARAMETERS	: kal_uint8 *buf_ptr
							  kal_uint32 buf_size
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: hw_RESULT

	REMARKS				: nil

***************************************************************/
void hw_bytestream_create(kal_uint32 owner, kal_uint8 *buf_ptr, kal_uint32 buf_size)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	

	p->t = HW_BYTESTREAM_TYPE_MEM;
	p->type.mem.buffer_size		= buf_size;
	p->type.mem.buffer_offset		= 0;
	p->type.mem.buffer_ptr	= buf_ptr;
}

/**************************************************************

	FUNCTION NAME		: hw_bytestream_create_file

  	PURPOSE				: create a file bytestream

	INPUT PARAMETERS	: const S8 *file_name
						  
	OUTPUT PARAMETERS	: nil

	RETURNS				: hw_RESULT

	REMARKS				: nil

***************************************************************/
kal_uint32 hw_bytestream_create_file(kal_uint32 owner, FS_HANDLE handle, kal_uint8* buf, kal_uint32 buf_size)
{
	hw_bytestream_dcb_struct *p = &hw_bytestream_dcb[owner];	

	p->t = HW_BYTESTREAM_TYPE_FILE;
	p->type.file.file_handle = handle;
	p->type.file.buffer_ptr = buf;
	p->type.file.buffer_size = buf_size;
	p->type.file.buffer_reader = p->type.file.buffer_ptr;
	p->type.file.buffer_content_size = 0;
	p->type.file.file_offset = 0;
	DRM_seek_file((FS_HANDLE) p->type.file.file_handle, 0, FS_FILE_BEGIN);
	if(DRM_file_size(p->type.file.file_handle, (kal_uint32*)&p->type.file.file_size)<0)
		p->type.file.file_size = 0;	

	return p->type.file.file_size;
}

hw_bytestream_func_struct hw_bytestream_func[HW_BYTESTREAM_TYPE_NUM]=
{
	{
		hw_bytestream_get_byte_mem ,
		//hw_bytestream_peek_byte_mem,
		hw_bytestream_peek_byte_n_mem,
		hw_bytestream_get_word_mem,
		//hw_bytestream_get_3bytes_mem,
		hw_bytestream_get_dword_mem, 
		hw_bytestream_get_array_mem,
		hw_bytestream_flush_mem,
		hw_bytestream_seek_mem,
		hw_bytestream_tell_mem,
		//hw_bytestream_get_size_mem,		
		hw_bytestream_is_eof_mem,		
		hw_bytestream_refill_mem
	},
	{
		hw_bytestream_get_byte_file ,
		//hw_bytestream_peek_byte_file,
		hw_bytestream_peek_byte_n_file,
		hw_bytestream_get_word_file,
		//hw_bytestream_get_3bytes_file,
		hw_bytestream_get_dword_file, 
		hw_bytestream_get_array_file,
		hw_bytestream_flush_file,
		hw_bytestream_seek_file,
		hw_bytestream_tell_file,
		//hw_bytestream_get_size_file,
		hw_bytestream_is_eof_file,		
		hw_bytestream_refill_file,	
	}
};

