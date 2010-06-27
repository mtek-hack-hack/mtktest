/************************************************************************* 
 * Copyright (c) 2000-2003 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2004-4-23   	
 * 作  者：  滕永; yongt@mobilesoft.com.cn   
 * 文  件：  arrary_memory.h 	    	
 * 描  述：	利用数组实现静态内存的使用。		
 * 修改记录： 
      人  员：   原     因：                   状   态：      日   期：
      滕永      创建                          完成           2004-4-23
 ************************************************************************/
#ifndef ARRARY_MEMORY_H_
#define ARRARY_MEMORY_H_


/* 目标头文件 */
#include "cms_sysfun.h"
#include "cms_debug.h"

#define CACHE_OPEN_TRACE	/* trace 开关 */



#ifdef WIN32	/* win32平台 */

	#ifdef CACHE_OPEN_TRACE	/* 打开trace */

		#define cache_trace		cms_trace
		#define cache_trace_all_memory() _cache_trace_all_memory()		

	#else	/* 关闭trace */

		#define cache_trace			
		#define cache_trace_all_memory()
		
	#endif

	#define cache_assert(x)		/* 诊断宏 */
	
#else	/* 目标平台 */

	#ifdef CACHE_OPEN_TRACE	/* 打开trace */

		#define cache_trace		cms_trace
		#define cache_trace_all_memory() _cache_trace_all_memory()

	#else /* 关闭trace */

		#define cache_trace		
		#define cache_trace_all_memory() 

	#endif

	#define cache_assert(x)		/* 诊断宏 */


#endif



#define UNIT_USED	1	/* 使用标记 */
#define UNIT_FREE	0	/* 未使用标记 */

#define IS_ZERO(  X  )		( 0 == X )					/* 是否为零 */
#define IS_USED_LEFTBIT(  X  )	( X & 0x80000000 )		/* 测试最左位是否使用？ */
#define MOVE_LEFTBIT(  X  )	( ( X << 1 ) & 0xfffffffe )	/* 左移一位 */
#define IS_USED_RIGHTBIT(  X  )	( X & 0x00000001 )		/* 测试最右位是否使用？ */
#define MOVE_RIGHTBIT(  X  )	( ( X >> 1 ) & 0x7fffffff )	/* 左移一位 */
#define LEFT_FIND	1	/* 从左向右查找 */
#define RIGHT_FIND	0	/* 从右向左查找 */


/* 枚举cache类型 */
typedef enum
{
	cache_pb_t = -2,		/* 扩展的pb类型 */
	cache_not_find = -1,	/* 没有存储空间 */
	cache_8_t  = 0,			/* 8个字节的cache */
	cache_16_t ,			/* 16个字节的cache */
	cache_20_t ,			/* 20个字节的cache */
	cache_24_t ,			/* 24个字节的cache */
	cache_100_t ,			/* 100个字节的cache */
#if 0
	cache_100_t ,			/* 100个字节的cache */
	cache_300_t ,			/* 300个字节的cache */
	cache_600_t ,			/* 600个字节的cache */
	cache_1640_t ,			/* 1640(1.6k)个字节的cache */
	cache_2560_t,			/* 2560(2.5k)个字节的cache */
	cache_6k_t,				/* 6144(6k)个字节的cache */
	cache_10k_t,			/* 10240(10k)个字节的cache */
	cache_20k_t,			/* 20480(20k)个字节的cache */
#endif
	cache_dynamic_t,		/* 动态内存分配的类型 */

	cache_totle_num		/* cache totle num */  //  Modified by TIPrj[2005/6/30]
}e_cache;


#define MAX_BITMAP_NUM	23	/* 定义bitmap最大个数,最大共计320个存储单元 */
#define CACHE_BITMAP	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0	/* 记录内存使用的情况 */

/*定义cache数据结构 */
typedef struct _cache_t
{
	e_cache	 cache_type;		/*cache 类型 */
	
	
	unsigned short	unit_len;	/* 单元长度 */
	short		    free_num;	/* 空闲单元数目 */

	int			    bitmap_num;	/* bitmap数目 */
	unsigned int	bitmap[MAX_BITMAP_NUM];	/* 内存bitmap */
	unsigned int base_pointer;	/* 基指针地址 */
	unsigned int end_pointer;	/* 尾指针地址 */

}cache_t;


/* 16 byte cache 参数定义 */

#define CACHE_8_UNIT_LEN	8	/* 定义初始化cache_8_t单元长度 */
#define CACHE_8_BITMAP_NUM	16	/* 定义cache_8 bitmap个数,要小于MAX_BITMAP_NUM 共320单元*/
#define CACHE_8_FREE_NUM	(CACHE_8_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_8_SIZE	( CACHE_8_UNIT_LEN*CACHE_8_FREE_NUM )	/* cache size */

#define CACHE_8_BASE_POINTER	((unsigned int)cache_base_8)
#define CACHE_8_END_POINTER	(CACHE_8_BASE_POINTER + CACHE_8_SIZE )


/* 16 byte cache 参数定义 */
#define CACHE_16_UNIT_LEN	16	/* 定义初始化cache_16_t单元长度 */
#define CACHE_16_BITMAP_NUM	1	/* 定义cache_16 bitmap个数,要小于MAX_BITMAP_NUM 共320单元*/
#define CACHE_16_FREE_NUM	(CACHE_16_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_16_SIZE	( CACHE_16_UNIT_LEN*CACHE_16_FREE_NUM )	/* cache size */

#define CACHE_16_BASE_POINTER	((unsigned int)cache_base_16)
#define CACHE_16_END_POINTER	(CACHE_16_BASE_POINTER + CACHE_16_SIZE )


/* 20 byte cache 参数定义 */
#define CACHE_20_UNIT_LEN	20	/* 定义初始化cache_20_t单元长度 */
#define CACHE_20_BITMAP_NUM	16	/* 定义cache_20 bitmap个数,要小于MAX_BITMAP_NUM 共320单元*/
#define CACHE_20_FREE_NUM	(CACHE_20_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_20_SIZE	( CACHE_20_UNIT_LEN*CACHE_20_FREE_NUM )	/* cache size */

#define CACHE_20_BASE_POINTER	((unsigned int)cache_base_20)
#define CACHE_20_END_POINTER	(CACHE_20_BASE_POINTER + CACHE_20_SIZE )


/* 32 byte cache 参数定义 */
#define CACHE_24_UNIT_LEN	24	/* 定义初始化cache_24_t单元长度 */
#define CACHE_24_BITMAP_NUM	10	/* 定义cache_24 bitmap个数,要小于MAX_BITMAP_NUM 共160单元 */
#define CACHE_24_FREE_NUM	(CACHE_24_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_24_SIZE	( CACHE_24_UNIT_LEN*CACHE_24_FREE_NUM )	/* cache size */

#define CACHE_24_BASE_POINTER	((unsigned int)cache_base_24)
#define CACHE_24_END_POINTER	(CACHE_24_BASE_POINTER + CACHE_24_SIZE )


/* 100 byte cache 参数定义 */
#define CACHE_100_UNIT_LEN	100	/* 定义初始化cache_100_t单元长度 */
#define CACHE_100_BITMAP_NUM	1	/* 定义cache_100 bitmap个数,要小于MAX_BITMAP_NUM 共128单元 */
#define CACHE_100_FREE_NUM	(CACHE_100_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_100_SIZE	( CACHE_100_UNIT_LEN*CACHE_100_FREE_NUM )	/* cache size */

#define CACHE_100_BASE_POINTER	((unsigned int)cache_base_100)
#define CACHE_100_END_POINTER	(CACHE_100_BASE_POINTER + CACHE_100_SIZE )

#if 0
/* 100 byte cache 参数定义 */
#define CACHE_100_UNIT_LEN	100	/* 定义初始化cache_100_t单元长度 */
#define CACHE_100_BITMAP_NUM	2	/* 定义cache_100 bitmap个数,要小于MAX_BITMAP_NUM 共64单元 */
#define CACHE_100_FREE_NUM	(CACHE_100_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_100_SIZE	( CACHE_100_UNIT_LEN*CACHE_100_FREE_NUM )	/* cache size */

#define CACHE_100_BASE_POINTER	((unsigned int)cache_base_100)
#define CACHE_100_END_POINTER	(CACHE_100_BASE_POINTER + CACHE_100_SIZE )



/* 300 byte cache 参数定义 */
#define CACHE_300_UNIT_LEN	300	/* 定义初始化cache_300_t单元长度 */
#define CACHE_300_BITMAP_NUM	1	/* 定义cache_300 bitmap个数,要小于MAX_BITMAP_NUM 共15单元 */
#define CACHE_300_FREE_NUM	(15)	/* 主动设为15个存储单元 */
#define CACHE_300_SIZE	( CACHE_300_UNIT_LEN*CACHE_300_FREE_NUM )	/* cache size */

#define CACHE_300_BASE_POINTER	((unsigned int)cache_base_300)
#define CACHE_300_END_POINTER	(CACHE_300_BASE_POINTER + CACHE_300_SIZE )


/* 600 byte cache 参数定义 */
#define CACHE_600_UNIT_LEN	600	/* 定义初始化cache_600_t单元长度 */
#define CACHE_600_BITMAP_NUM	1	/* 定义cache_600 bitmap个数,要小于MAX_BITMAP_NUM 共7单元 */
#define CACHE_600_FREE_NUM	(10)	/* 主动设为7个存储单元 */
#define CACHE_600_SIZE	( CACHE_600_UNIT_LEN*CACHE_600_FREE_NUM )	/* cache size */

#define CACHE_600_BASE_POINTER	((unsigned int)cache_base_600)
#define CACHE_600_END_POINTER	(CACHE_600_BASE_POINTER + CACHE_600_SIZE )


/* 1640 byte cache 参数定义 */
#define CACHE_1640_UNIT_LEN	1500	/* 定义初始化cache_1640_t单元长度 */
#define CACHE_1640_BITMAP_NUM	1	/* 定义cache_1640 bitmap个数,要小于MAX_BITMAP_NUM 共4单元 */
#define CACHE_1640_FREE_NUM	(16)	/* 主动设为16个存储单元 */
#define CACHE_1640_SIZE	( CACHE_1640_UNIT_LEN*CACHE_1640_FREE_NUM )	/* cache size */

#define CACHE_1640_BASE_POINTER	((unsigned int)cache_base_1640)
#define CACHE_1640_END_POINTER	(CACHE_1640_BASE_POINTER + CACHE_1640_SIZE )


/* 1640 byte cache 参数定义 */
#define CACHE_2560_UNIT_LEN	2560	/* 定义初始化cache_2560_t单元长度 */
#define CACHE_2560_BITMAP_NUM	1	/* 定义cache_2560 bitmap个数,要小于MAX_BITMAP_NUM 共4单元 */
#define CACHE_2560_FREE_NUM	(8)	/* 主动设为8个存储单元 */
#define CACHE_2560_SIZE	( CACHE_2560_UNIT_LEN*CACHE_2560_FREE_NUM )	/* cache size */

#define CACHE_2560_BASE_POINTER	((unsigned int)cache_base_2560)
#define CACHE_2560_END_POINTER	(CACHE_2560_BASE_POINTER + CACHE_2560_SIZE )


/* 6k byte cache 参数定义 */
#define CACHE_6k_UNIT_LEN	6144	/* 定义初始化cache_6k_t单元长度 */
#define CACHE_6k_BITMAP_NUM	1	/* 定义cache_6k bitmap个数,要小于MAX_BITMAP_NUM 共5单元 */
#define CACHE_6k_FREE_NUM	(5)	/* 主动设为5个存储单元 */
#define CACHE_6k_SIZE	( CACHE_6k_UNIT_LEN*CACHE_6k_FREE_NUM )	/* cache size */

#define CACHE_6k_BASE_POINTER	((unsigned int)cache_base_6k)
#define CACHE_6k_END_POINTER	(CACHE_6k_BASE_POINTER + CACHE_6k_SIZE )


/* 10k byte cache 参数定义 */
#define CACHE_10k_UNIT_LEN	10240	/* 定义初始化cache_10k_t单元长度 */
#define CACHE_10k_BITMAP_NUM	1	/* 定义cache_10k bitmap个数,要小于MAX_BITMAP_NUM 共4单元 */
#define CACHE_10k_FREE_NUM	(2)	/* 主动设为2个存储单元 */
#define CACHE_10k_SIZE	( CACHE_10k_UNIT_LEN*CACHE_10k_FREE_NUM )	/* cache size */

#define CACHE_10k_BASE_POINTER	((unsigned int)cache_base_10k)
#define CACHE_10k_END_POINTER	(CACHE_10k_BASE_POINTER + CACHE_10k_SIZE )


/* 20k byte cache 参数定义 */
#define CACHE_20k_UNIT_LEN	20480	/* 定义初始化cache_20k_t单元长度 */
#define CACHE_20k_BITMAP_NUM	1	/* 定义cache_20k bitmap个数,要小于MAX_BITMAP_NUM 共4单元 */
#define CACHE_20k_FREE_NUM	(1)	/* 主动设为1个存储单元 */
#define CACHE_20k_SIZE	( CACHE_20k_UNIT_LEN*CACHE_20k_FREE_NUM )	/* cache size */

#define CACHE_20k_BASE_POINTER	((unsigned int)cache_base_20k)
#define CACHE_20k_END_POINTER	(CACHE_20k_BASE_POINTER + CACHE_20k_SIZE )


#endif

/* dynamic cache 参数定义 */
#define CACHE_dynamic_UNIT_LEN	1//1500	/* 定义初始化cache_dynamic_t单元长度 */
#define CACHE_dynamic_BITMAP_NUM 1//	3	/* 定义cache_dynamic bitmap个数,要小于MAX_BITMAP_NUM 共96单元 */
#define CACHE_dynamic_FREE_NUM	(1)//CACHE_dynamic_BITMAP_NUM*sizeof(unsigned int)*8)	/* 主动设为1个存储单元 */
#define CACHE_dynamic_SIZE	( CACHE_dynamic_UNIT_LEN*CACHE_dynamic_FREE_NUM )	/* cache size */

#define CACHE_dynamic_BASE_POINTER	((unsigned int)cache_base_dynamic)
#define CACHE_dynamic_END_POINTER	(CACHE_dynamic_BASE_POINTER + CACHE_dynamic_SIZE )

#define AR_DYNAMIC_NO_FREE_POS	( -1 )	/* 动态内存没有空闲位置 */	
#define AR_DYNAMIC_MAX_SIZE	( CACHE_dynamic_SIZE-CACHE_dynamic_UNIT_LEN)	/* 最大动态分内存 */
#define AR_DYNAMIC_MIN_SIZE	800	/* 最小动态分内存 */
#define AR_DYNAMIC_MID_SIZE ( 50176 ) /* 49*1024 动态内存中间数值 */
#define DYNAMIC_CAL_UNIT_NUM( size ) (size/CACHE_dynamic_UNIT_LEN+1) /*计算所需动态内存单元个数 */

/* phone book (pb) cache 参数定义 */
#define CACHE_PB_UNIT_LEN	44	/* 定义初始化 phone book 单元长度 */
#define CACHE_PB_BITMAP_NUM	0	/* 定义cache_PB bitmap个数,512单元*/
#define CACHE_PB_FREE_NUM	(1)//CACHE_PB_BITMAP_NUM*sizeof(unsigned int)*8)
#define CACHE_PB_SIZE	( CACHE_PB_UNIT_LEN*CACHE_PB_FREE_NUM )	/* cache size */

#define CACHE_PB_BASE_POINTER	((unsigned int)cache_base_PB)
#define CACHE_PB_END_POINTER	(CACHE_PB_BASE_POINTER + CACHE_PB_SIZE )


/* 计算空闲位置的偏移量 */
#define CACHE_OFFSET(cache_type,free_pos) ( g_ar_cache[cache_type].unit_len*free_pos)
/* 计算偏移量的存储位置 */
#define CACHE_POS( cache_type, cache_pointer ) ( (cache_pointer-g_ar_cache[cache_type].base_pointer)/g_ar_cache[cache_type].unit_len)
/* 计算是否还有存储空间 */ 
#define CACHE_IS_HAVE_FREE_ROOM( cache_type ) ( g_ar_cache[cache_type].free_num > 0 )


void *array_alloc_by_type( e_cache cache_type );

#endif