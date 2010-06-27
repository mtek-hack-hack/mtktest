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
 *    bmd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for ring-buffer API.
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
#ifndef BMD_H
#define BMD_H

typedef struct __BUFFER_INFO
{
	kal_uint16	Read;		/* @field Current Read index. */
	kal_uint16	Write;		/* @field Current Write index. */
	kal_uint16	Length;		/* @field Length of buffer */
	kal_uint8	*CharBuffer;		/* @field Start of buffer */
}BUFFER_INFO;

#define ResetFifo(Buffer)   		Buffer.Write = Buffer.Read = 0
#define BWrite(Buffer)	   		(Buffer->Write)
#define BRead(Buffer)		   	(Buffer->Read)
#define BLength(Buffer)	   		(Buffer->Length)
#define BStartAddr(Buffer)     (Buffer->CharBuffer)
#define BuffWrite(Buffer)   		(Buffer->CharBuffer+Buffer->Write)
#define BuffRead(Buffer)	   	(Buffer->CharBuffer+Buffer->Read)

#define BWrite_addr(Buffer)	   (Buffer.Write)
#define BRead_addr(Buffer)		   (Buffer.Read)
#define BLength_addr(Buffer)	   (Buffer.Length)
#define BuffWrite_addr(Buffer)   (Buffer.CharBuffer+Buffer.Write)
#define BuffRead_addr(Buffer)	   (Buffer.CharBuffer+Buffer.Read)
#define Buff_EndAddr(Buffer)     (Buffer.CharBuffer+Buffer.Length-1)
#define Buff_StartAddr(Buffer)     (Buffer.CharBuffer)

#define Buff_isEmpty	1
#define Buff_notEmpty	0
#define Buff_isFull	1
#define Buff_notFull	0
#define Buff_PushOK	0
#define Buff_PushErr	1
#define Buff_PopOK	0
#define Buff_PopErr	1

#define Buf_init(_Buffer,_Buffaddr,_uTotalSize) \
{\
   BUFFER_INFO *_Buf=_Buffer;\
   _Buf->Read = 0;\
	_Buf->Write = 0;\
	_Buf->Length = _uTotalSize;\
	_Buf->CharBuffer = _Buffaddr;\
}\

#define Buf_IsFull(_Buffer,_result)   \
{\
   BUFFER_INFO *_Buf=_Buffer;\
	kal_uint16 _tmp = BRead(_Buf);\
	if (_tmp == 0)\
		_tmp = BLength(_Buf);\
	if ( (_tmp-BWrite(_Buf)) == 1)\
	{\
		_result = Buff_isFull;\
	}\
	else\
	{\
		_result = Buff_notFull;\
	}\
}\

#define Buf_GetRoomLeft(_Buffer,_RoomLeft)   \
{\
   BUFFER_INFO *_Buf=_Buffer;\
   if ( BRead(_Buf) <= BWrite(_Buf) ) \
	{\
      _RoomLeft = BLength(_Buf) - BWrite(_Buf) + BRead(_Buf) - 1;\
	}\
	else\
	{\
		_RoomLeft = BRead(_Buf) - BWrite(_Buf) - 1;\
	}\
}\

#define Buf_Push(_Buffer,_pushData) \
{\
   BUFFER_INFO *_Buf=_Buffer;\
   *BuffWrite(_Buf) = _pushData;\
   if(BWrite(_Buf) >= (BLength(_Buf) - 1))\
   {\
   	BWrite(_Buf) = 0;\
   }\
   else\
   {\
	BWrite(_Buf)++;\
   }\
}\

#define Buf_GetBytesAvail(_Buffer,_BytesAvail) \
{\
   BUFFER_INFO *_Buf = _Buffer;\
	_BytesAvail = 0;\
	if (BWrite(_Buf) >= BRead(_Buf))\
		_BytesAvail = BWrite(_Buf) - BRead(_Buf);\
	else\
		_BytesAvail = BLength(_Buf) - BRead(_Buf) + BWrite(_Buf);	\
}\

#define Buf_Pop(_Buffer,_popData)   \
{\
   BUFFER_INFO *_Buf = _Buffer;\
	_popData= *BuffRead(_Buf);\
	BRead(_Buf)++;\
	if (BRead(_Buf) >= BLength(_Buf))\
	{\
		BRead(_Buf) -= BLength(_Buf);\
	}\
}\

/* should be deleted */
#define Buf_IsEmpty(_Buffer,_result)   \
{\
   BUFFER_INFO *_Buf = _Buffer;\
	if ( BRead(_Buf) == BWrite(_Buf) ) \
	{\
		_result = Buff_isEmpty;\
	}\
	else\
	{\
		_result = Buff_notEmpty;\
	}\
}\

/* void Get32FromBuff(BUFFER_INFO *Buf,kal_uint32 DATA) */
#define Get32FromBuf(_Buffer,_DATA)    \
{\
   BUFFER_INFO *_Buf = _Buffer;\
	kal_uint8	_tmp,_index;\
	kal_uint32 	_tmp32;\
	_DATA =0;\
	for (_index =0;_index < 4;_index++)\
	{\
		Buff_Pop(_Buf,&_tmp);\
		_tmp32 = (kal_uint32)_tmp;\
		(_DATA) |= (_tmp32 << (8*_index));\
	}\
}\

/*void Put32toBuff(BUFFER_INFO *Buf,kal_uint32 *DATA)*/
#define Put32toBuf(_Buffer,_DATA)    \
{\
   BUFFER_INFO *_Buf = _Buffer;\
	kal_uint8	_tmp,_index;\
	kal_uint32 	_tmp32;\
	for (_index =0;_index < 4;_index++)\
	{\
		_tmp32 = ((*_DATA) >> (8*_index));\
		_tmp = (kal_uint8)_tmp32;\
		Buff_Push(_Buf,&_tmp);\
	}\
}\

#define Buf_Flush(_Buffer) \
{\
   BUFFER_INFO *_Buf = _Buffer;\
	_Buf->Write = _Buf->Read = 0;\
}

#define Buf_look(_Buffer,_popData,_num)   \
{\
   BUFFER_INFO *_Buf = _Buffer;\
   kal_uint8 _index;\
   kal_uint16 _tmp;\
   _tmp = BRead(Buf);\
   for(_index=0;_index<_num;_index++)\
   {\
	   *_popData= *(Buf->CharBuffer+_tmp);\
	   _tmp++;\
	   if (_tmp >= BLength(Buf))\
	   {\
		   _tmp -= BLength(Buf);\
	   }\
	}\
}

#if 1
extern void Buff_init(BUFFER_INFO *Buf,kal_uint8 *Buffaddr, kal_uint16 uTotalSize);
extern void Buff_Push(BUFFER_INFO *Buf,kal_uint8 *pushData);
extern void Buff_Pop(BUFFER_INFO *Buf,kal_uint8 *popData);
extern kal_uint8 Buff_IsEmpty(BUFFER_INFO *Buf);
extern kal_uint8 Buff_IsFull (BUFFER_INFO *Buf);
extern kal_uint16 Buff_GetRoomLeft (BUFFER_INFO *Buf);
extern kal_uint16 Buff_GetBytesAvail (BUFFER_INFO *Buf);
extern kal_uint16 Buff_GetLength(BUFFER_INFO *Buf);
extern void Buff_Flush (BUFFER_INFO *Buf);
extern void Buff_look(BUFFER_INFO *Buf,kal_uint8 *popData,kal_uint8 num);
extern void Get32FromBuff(BUFFER_INFO *Buf,kal_uint32 *DATA);
extern void Put32toBuff(BUFFER_INFO *Buf,kal_uint32 *DATA);
extern void MemCPY(kal_uint8 *dst,kal_uint8 *src,kal_uint32 len);
extern void MemSET(kal_uint8 *dst,kal_uint8 data,kal_uint32 len);
#endif

#endif

