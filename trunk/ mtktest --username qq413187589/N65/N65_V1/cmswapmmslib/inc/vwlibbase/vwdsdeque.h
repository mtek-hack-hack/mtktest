#ifndef __L_VWLIB_DS_DEQUE_H__
#define __L_VWLIB_DS_DEQUE_H__

#include "vwdsbase.h"

#define VW_DS_DEQUE_DEF_DTPER_SLOT		(64)
#define	VW_DT_DEQUE_DEF_INIT_SLOT_CNT	(8)
#define VW_DT_DEQUE_MAX_INCR_SLOT		(64)

typedef vwuint8p	vw_dqu_blk_ptr;		/* size_is( dtperslot * szblock ) */

typedef struct vw_deque_t
{
	VW_Alloc*			alloc;
	VWDS_METHODCP		meth;
	size_t				szblock;
	size_t				maxslot , szdata , fstpos , dtperslot;
	vw_dqu_blk_ptr*		blkptr;			/* size_is( maxslot ) */
}	vw_deque;

VW_EXTERN_C	VWRESULT	VW_Deque_Create	( VW_Alloc* alloc , VWDS_METHODCP meth , vw_deque* pInit , size_t szblock , 
											size_t dtperslot ,		/* 0 for default. */
											size_t initslotcnt );	/* 0 for default. */

VW_EXTERN_C	VWRESULT	VW_Deque_Create2( VW_Alloc* alloc , VWDS_METHODCP meth , vw_deque* pInit , size_t szblock , 
											size_t	dtperslot ,		/* 0 for default. */
											size_t	initslotcnt ,	/* 0 for default. */
											vwvoidcp beg , vwvoidcp end );

VW_EXTERN_C void		VW_Deque_Clear	( vw_deque* pThis );
VW_EXTERN_C size_t		VW_Deque_Size	( const vw_deque* pThis );
VW_EXTERN_C	vwvoidp		VW_Deque_GetAt	( const vw_deque* pThis , size_t index );
VW_EXTERN_C	VWRESULT	VW_Deque_Resize	( vw_deque* pThis , size_t newsz );

VW_EXTERN_C	VWRESULT	VW_Deque_PushBack	( vw_deque* pThis , vwvoidcp src );
VW_EXTERN_C VWRESULT	VW_Deque_PushBack_N	( vw_deque* pThis , vwvoidcp src , size_t n );
VW_EXTERN_C VWRESULT	VW_Deque_PushBack_R	( vw_deque* pThis , vwvoidcp beg , vwvoidcp end );

VW_EXTERN_C VWRESULT	VW_Deque_PushFront	( vw_deque* pThis , vwvoidcp src );
VW_EXTERN_C VWRESULT	VW_Deque_PushFront_N( vw_deque* pThis , vwvoidcp src , size_t n );
VW_EXTERN_C VWRESULT	VW_Deque_PushFront_R( vw_deque* pThis , vwvoidcp beg , vwvoidcp end );

VW_EXTERN_C VWRESULT	VW_Deque_PopBack	( vw_deque* pThis );
VW_EXTERN_C VWRESULT	VW_Deque_PopFront	( vw_deque* pThis );

VW_EXTERN_C void		VW_Deque_EraseEnd	( vw_deque* pThis , size_t nBeg  );		/* erase[ nBeg , end ) */
VW_EXTERN_C void		VW_Deque_EraseFront	( vw_deque* pThis , size_t nLast );		/* erase[ 0 , nLast  ) */

VW_EXTERN_C VWRESULT	VW_Deque_For_Each	( vw_deque* pThis , vwds_enum_callback func );
VW_EXTERN_C VWRESULT	VW_Deque_For_Each_A	( vw_deque* pThis , vwds_enum_callback_arg func , vwvoidp arg );

#endif