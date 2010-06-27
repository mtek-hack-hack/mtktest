#ifndef __L_VWLIB_STREAM_H__
#define __L_VWLIB_STREAM_H__

#include "vwstring.h"

#define	VW_EOF					(EOF)
#define VW_SEEK_CUR				(SEEK_CUR)
#define VW_SEEK_END				(SEEK_END)
#define VW_SEEK_SET				(SEEK_SET)

typedef struct VW_Stream	VW_Stream;
typedef	struct VW_StreamVtbl
{
	void		( *vwdestroy)( VW_Stream* pThis );
	size_t		( *vwread	)( VW_Stream* pThis , vwvoidp	buf , size_t sz );
	size_t		( *vwwrite	)( VW_Stream* pThis , vwvoidcp	buf , size_t sz );	
	int			( *vwgetc	)( VW_Stream* pThis );
	VWRESULT	( *vwputc	)( VW_Stream* pThis , int ch );
	VWRESULT	( *vwputs	)( VW_Stream* pThis , vwcharcp	str );
	VWRESULT	( *vwgetline)( VW_Stream* pThis , VW_String_Buffer buf , int ch );
	VWRESULT	( *vwseek	)( VW_Stream* pThis , long off , int orgi );
	long		( *vwtell	)( VW_Stream* pThis );
	vw_bool		( *vweof	)( VW_Stream* pThis );
	vw_bool		( *vwerror	)( VW_Stream* pThis );	
}	VW_StreamVtbl;

typedef		void		( *_VW_Stream_DestroyFunc)( VW_Stream* pThis );
typedef		size_t		( *_VW_Stream_ReadFunc	 )( VW_Stream* pThis , vwvoidp	buf , size_t sz );
typedef		size_t		( *_VW_Stream_WriteFunc  )( VW_Stream* pThis , vwvoidcp	buf , size_t sz );	
typedef		int			( *_VW_Stream_GetcFunc	 )( VW_Stream* pThis );
typedef		VWRESULT	( *_VW_Stream_PutcFunc	 )( VW_Stream* pThis , int ch );
typedef		VWRESULT	( *_VW_Stream_PutsFunc	 )( VW_Stream* pThis , vwcharcp	str );
typedef		VWRESULT	( *_VW_Stream_GetLineFunc)( VW_Stream* pThis , VW_String_Buffer buf , int ch );
typedef		VWRESULT	( *_VW_Stream_SeekFunc	 )( VW_Stream* pThis , long off , int orgi );
typedef		long		( *_VW_Stream_TellFunc	 )( VW_Stream* pThis );
typedef		vw_bool		( *_VW_Stream_EofFunc	 )( VW_Stream* pThis );
typedef		vw_bool		( *_VW_Stream_ErrorFunc	 )( VW_Stream* pThis );	

struct VW_Stream
{
	const VW_StreamVtbl*	vtbl;
};

#define VW_Stream_Destroy( obj )				( (obj)->vtbl->vwdestroy( (obj) ) )
#define VW_Stream_Read( obj , buf , sz )		( (obj)->vtbl->vwread	( (obj) , (buf) , (sz) ) )
#define VW_Stream_Write( obj , buf , sz )		( (obj)->vtbl->vwwrite	( (obj) , (buf) , (sz) ) )
#define	VW_Stream_Getc( obj )					( (obj)->vtbl->vwgetc	( (obj) ) )
#define VW_Stream_Putc( obj , ch )				( (obj)->vtbl->vwputc	( (obj) , (ch) ) )
#define VW_Stream_Puts( obj , str )				( (obj)->vtbl->vwputs	( (obj) , (str) ) )
#define VW_Stream_Getline( obj , buf , ch )		( (obj)->vtbl->vwgetline( (obj) , (buf) , (ch) ) )
#define VW_Stream_Seek( obj , off , orgi )		( (obj)->vtbl->vwseek	( (obj) , (off) , (orgi) ) )
#define VW_Stream_Tell( obj )					( (obj)->vtbl->vwtell	( (obj) ) )
#define VW_Stream_Eof( obj )					( (obj)->vtbl->vweof	( (obj) ) )
#define VW_Stream_Error( obj )					( (obj)->vtbl->vwerror	( (obj) ) )

VW_EXTERN_C	int			_VW_Stream_DefGetc		( VW_Stream* pThis );
VW_EXTERN_C	VWRESULT	_VW_Stream_DefPutc		( VW_Stream* pThis , int ch );
VW_EXTERN_C	VWRESULT	_VW_Stream_DefPuts		( VW_Stream* pThis , VW_RawString str );
VW_EXTERN_C	VWRESULT	_VW_Stream_DummyPutc	( VW_Stream* pThis , int ch );
VW_EXTERN_C	VWRESULT	_VW_Stream_DummyPuts	( VW_Stream* pThis , vwsint8cp str );
VW_EXTERN_C size_t		_VW_Stream_DummyWrite	( VW_Stream* pThis , vwvoidcp buf , size_t sz );

VW_EXTERN_C	VW_Stream*	VW_IStringStream_Create	( VW_Alloc* alloc , vwvoidcp str , size_t sz );

VW_EXTERN_C	VW_Stream*	VW_IOStringStream_Create( VW_Alloc* alloc , size_t slotsize , size_t maxslot );



#endif
