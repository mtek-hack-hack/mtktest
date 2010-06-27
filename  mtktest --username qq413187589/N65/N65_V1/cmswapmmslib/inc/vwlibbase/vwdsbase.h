#ifndef __L_VWLIB_DSBASE_H__
#define __L_VWLIB_DSBASE_H__

#include "vwmemory.h"

/*
 *	dtor. 
 */
typedef void		(*vwds_data_clear	)( VW_Alloc* alloc , vwvoidp obj , size_t sz );

/*
 *	default ctor.
 */
typedef VWRESULT	(*vwds_data_ctor	)( VW_Alloc* alloc , vwvoidp  dst , size_t sz );

/*
 *	copy ctor.
 */
typedef VWRESULT	(*vwds_data_clone	)( VW_Alloc* alloc , vwvoidp  dst , vwvoidcp src , size_t sz );

/*
 *	swap two obj. 
 */
typedef void		(*vwds_data_swap	)( VW_Alloc* alloc , vwvoidp lhs , vwvoidp rhs , size_t sz );

/*
 *	dst = src.detach. 
 */
typedef void		(*vwds_data_detach	)( VW_Alloc* alloc , vwvoidp  dst , vwvoidp  src , size_t sz );

/*
 *	0 : lhs == rhs , .lt. 0 : lhs < rhs , .gt. 0 : lhs > rhs.
 */
typedef int			(*vwds_data_cmp		)( VW_Alloc* alloc , vwvoidcp lhs , vwvoidcp rhs , size_t sz );

/*
 *	hash function.
 */
typedef vwuint32	(*vwds_data_hash	)( VW_Alloc* alloc , vwvoidcp obj , size_t sz );

/*
 *	enum data.
 */
typedef VWRESULT	(*vwds_enum_callback)( VW_Alloc* alloc , vwvoidp  obj , size_t sz  );

/*
 *	enum data with arglist.
 */
typedef VWRESULT	(*vwds_enum_callback_arg )( VW_Alloc* alloc , vwvoidp  obj , size_t sz , vwvoidp arg );


/*
 *	VWDS_METHOD , 
 */
typedef struct VWDS_METHOD
{
	void		(*fnclear	)( VW_Alloc* alloc , vwvoidp  obj , size_t   sz );
	VWRESULT	(*fnctor	)( VW_Alloc* alloc , vwvoidp  dst , size_t sz );
	VWRESULT	(*fnclone	)( VW_Alloc* alloc , vwvoidp  dst , vwvoidcp src , size_t sz );
	void		(*fnswap	)( VW_Alloc* alloc , vwvoidp  lhs , vwvoidp  rhs , size_t sz );
	void 		(*fndetach	)( VW_Alloc* alloc , vwvoidp  dst , vwvoidp  src , size_t sz );
	int			(*fncmp		)( VW_Alloc* alloc , vwvoidcp lhs , vwvoidcp rhs , size_t sz );
	vwuint32	(*fnhash	)( VW_Alloc* alloc , vwvoidcp obj , size_t   sz );
}	VWDS_METHOD;

typedef const VWDS_METHOD* VWDS_METHODCP;

VW_EXTERN_C	void		VWDS_Def_Data_Clear ( VW_Alloc* alloc , vwvoidp  obj , size_t   sz );
VW_EXTERN_C	VWRESULT	VWDS_Def_Data_Ctor	( VW_Alloc* alloc , vwvoidp  dst , size_t   sz );
VW_EXTERN_C VWRESULT	VWDS_Def_Data_Clone ( VW_Alloc* alloc , vwvoidp  dst , vwvoidcp src , size_t sz );
VW_EXTERN_C void		VWDS_Def_Data_Swap	( VW_Alloc* alloc , vwvoidp  lhs , vwvoidp  rhs , size_t sz );
VW_EXTERN_C void		VWDS_Def_Data_Detach( VW_Alloc* alloc , vwvoidp  dst , vwvoidp  src , size_t sz );
VW_EXTERN_C int			VWDS_Def_Data_Cmp   ( VW_Alloc* alloc , vwvoidcp lhs , vwvoidcp rhs , size_t sz );
VW_EXTERN_C vwuint32	VWDS_Def_Data_Hash	( VW_Alloc* alloc , vwvoidcp obj , size_t	sz );

VW_EXTERN_C VW_EXTERN const VWDS_METHOD* VWDS_Def_Method;

VW_EXTERN_C	VWRESULT	VWDS_Data_Ctor		( VW_Alloc* alloc , VWDS_METHODCP meth , vwvoidp beg , vwvoidp end , size_t sz );
VW_EXTERN_C	VWRESULT	VWDS_Data_Init		( VW_Alloc* alloc , VWDS_METHODCP meth , vwvoidp beg , vwvoidp end , size_t sz , vwvoidcp src );
VW_EXTERN_C VWRESULT	VWDS_Data_InitR		( VW_Alloc* alloc , VWDS_METHODCP meth , vwvoidp beg , size_t sz , vwvoidcp srcbeg , vwvoidcp srcend );
VW_EXTERN_C void		VWDS_Data_DetachTo	( VW_Alloc* alloc , VWDS_METHODCP meth , vwvoidp beg , size_t sz , vwvoidp  srcbeg , vwvoidp  srcend , vw_bool bdtor );
VW_EXTERN_C	void		VWDS_Data_Dtor		( VW_Alloc* alloc , VWDS_METHODCP meth , vwvoidp beg , vwvoidp end , size_t sz );

#endif