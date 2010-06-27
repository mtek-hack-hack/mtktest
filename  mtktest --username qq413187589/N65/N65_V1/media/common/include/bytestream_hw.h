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
 *	 bytestream_hw.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  hw Bytesteam header.
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
 *==============================================================================
 *******************************************************************************/
#ifndef _BYTESTREAM_HW_H_
#define _BYTESTREAM_HW_H_
#include "setjmp.h"

// #define BYTESTREAM_DEBUG

typedef enum
{
	HW_BYTESTREAM_TYPE_MEM,
	HW_BYTESTREAM_TYPE_FILE,
	HW_BYTESTREAM_TYPE_NUM
} hw_bytestream_type_enum;

typedef enum
{
	HW_BYTESTREAM_GIF,
	HW_BYTESTREAM_PNG,
	HW_BYTESTREAM_OWNER_NUM
}hw_bytestream_owner_enum;

typedef enum
{
	LITTLE_ENDIAN,
	BIG_ENDIAN
}hw_bytestream_endian_enum;

#ifdef __RVCT__
   typedef long long mtk_jmpbuf[11];
#else
   typedef int mtk_jmpbuf[11];
#endif

typedef struct _bytestream_dcb
{
	hw_bytestream_type_enum t;
	mtk_jmpbuf jmp_buf;
	union{
		struct{	
		// for source in the memory
	 	kal_uint8*			buffer_ptr;
	 	kal_uint32			buffer_size;
	 	// kal_uint32			buffer_reader;
	 	kal_uint32			buffer_offset;
		}mem;
		struct{
		// for source in the file
		FS_HANDLE			file_handle;		
		kal_uint32 			file_size;
		kal_uint32			buffer_content_size;	// valid data in the buffer
		kal_uint32			file_offset;
		kal_uint8* 			buffer_reader;			// read pointer of the buffer
		kal_uint8*			buffer_ptr;
		kal_uint32			buffer_size;
		}file;
	}type;

#if defined(BYTESTREAM_DEBUG)
	kal_char file_name[256];
	kal_int32 line;
#endif
}hw_bytestream_dcb_struct;

typedef struct 
{
	kal_uint8		(*hw_bytestream_get_byte)(kal_uint32 owner);
	//kal_uint8		(*hw_bytestream_peek_byte)(kal_uint32 owner);
	kal_uint8		(*hw_bytestream_peek_byte_n)(kal_uint32 owner, kal_uint32 index);	
	kal_uint16		(*hw_bytestream_get_word)(kal_uint32 owner,hw_bytestream_endian_enum endian);
	//kal_uint32		(*hw_bytestream_get_3bytes)(kal_uint32 owner);	
	kal_uint32		(*hw_bytestream_get_dword)(kal_uint32 owner,hw_bytestream_endian_enum endian);
	void				(*hw_bytestream_get_array)(kal_uint32 owner, kal_uint8 * array,kal_uint32 size);	
	void				(*hw_bytestream_flush)(kal_uint32 owner, kal_uint32 count);
	void				(*hw_bytestream_seek)(kal_uint32 owner, kal_int32 offset);
	kal_int32		(*hw_bytestream_tell)(kal_uint32 owner, hw_bytestream_dcb_struct **info);
	// kal_uint32		(*hw_bytestream_get_size)(kal_uint32 owner);
	kal_bool			(*hw_bytestream_is_eof)(kal_uint32 owner); /* Deprecated. We use longjmp() to handle truncated data source. */
	void				(*hw_bytestream_refill)(kal_uint32 owner);
	
}hw_bytestream_func_struct;


extern hw_bytestream_func_struct hw_bytestream_func[2];
extern hw_bytestream_dcb_struct hw_bytestream_dcb[HW_BYTESTREAM_OWNER_NUM];


#define MIN(a,b) 			(a>b)?(b):(a)
// HW_BYTESTREAM_GIF = 0
#define GIF_GET_U8()	 	hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_get_byte(0)
#define GIF_GET_U16() 	hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_get_word(0,0)
#define GIF_GET_U32() 	hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_get_dword(0,0)
#define GIF_FLUSH(x)		hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_flush(0,x)
#define GIF_SEEK(x)		hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_seek(0,x)
#define GIF_TELL(x)		hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_tell(0,x)
#define GIF_IS_EOF()		hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_is_eof(0)
#define GIF_REFILL()		hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_refill(0)
#define GIF_PEEK(x)		hw_bytestream_func[hw_bytestream_dcb[0].t].hw_bytestream_peek_byte_n(0,x)

#define GIF_TRY			\
	{\
		kal_int32 jmpret;\
		jmpret = setjmp (hw_bytestream_dcb[0].jmp_buf);\
		if(jmpret == 0 )\
		{

#define GIF_CATCH_BEGIN \
		}\
		else\
		{\
			
#define GIF_CATCH_END  \
		}\
	}
#if defined(BYTESTREAM_DEBUG)

#define BYTESTREAM_RAISE_EX(x,y,a,b)		{\
											strcpy(hw_bytestream_dcb[x].file_name, a);\
											hw_bytestream_dcb[x].line = b;\
											dbg_print("\r\n Raise at file %s line %d",a,b);\
											longjmp (hw_bytestream_dcb[x].jmp_buf, y);\
											}
#define BYTESTREAM_RAISE(x,y)		BYTESTREAM_RAISE_EX(x,y,__FILE__,__LINE__)

#define PNG_RAISE(y)					BYTESTREAM_RAISE(HW_BYTESTREAM_PNG,y)

#else
#define BYTESTREAM_RAISE(x,y)		longjmp (hw_bytestream_dcb[x].jmp_buf, y);
#define PNG_RAISE(y)					BYTESTREAM_RAISE(HW_BYTESTREAM_PNG,y)
#endif

// HW_BYTESTREAM_PNG = 1
#define PNG_GET_U8()		hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_get_byte(1)
#define PNG_GET_U16() 	hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_get_word(1,1)
#define PNG_GET_U32() 	hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_get_dword(1,1)
#define PNG_FLUSH(x)		hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_flush(1,x)
#define PNG_SEEK(x)		hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_seek(1,x)
#define PNG_TELL(x)		hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_tell(1,x)
#define PNG_IS_EOF()		hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_is_eof(1)
#define PNG_REFILL()		hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_refill(1)
#define PNG_GET_ARRAY(a,b) 	hw_bytestream_func[hw_bytestream_dcb[1].t].hw_bytestream_get_array(1,a,b)

#define PNG_TRY			\
	{\
		kal_int32 jmpret;\
		jmpret = setjmp (hw_bytestream_dcb[1].jmp_buf);\
		if(jmpret == 0 )\
		{

#define PNG_CATCH_BEGIN \
		}\
		else\
		{\
			
#define PNG_CATCH_END  \
		}\
	}
extern kal_uint32 hw_bytestream_create_file(kal_uint32 owner, FS_HANDLE handle, kal_uint8* buf, kal_uint32 buf_size);
extern void hw_bytestream_create(kal_uint32 owner, kal_uint8 *buf_ptr, kal_uint32 buf_size);



#endif  /* _BYTESTREAM_HW_H_ */
