#ifndef _BRWREFRESHTEST_H
#define _BRWREFRESHTEST_H
#include "cms_debug.h"
#include "cms_time.h"


//#define	_T_BRWREFRESHTEST


#ifdef _T_BRWREFRESHTEST
extern size_t  count_rate[3];
extern clock_t __clk_beg_t__;

#define TIME_TEST_BEGIN( )		\
	{							\
		__clk_beg_t__ = cms_clock();	\
	}

#define TIME_TEST_END( id )								{\
		count_rate[id] += cms_clock() - __clk_beg_t__;	\
	} 

#define TIME_TEST_MARK_START(x) 	cms_trace("$$$ TIME_TEST_MARK_START: %s\n",x);
#define TIME_TEST_MARK_END() 	cms_trace("$$$ TIME_TEST_MARK_END\n");

#define TIME_TEST_MARK_CLOCK() 	cms_trace("$$$ clock: %d\n",cms_clock());

void time_trace(void);

#else 

#define TIME_TEST_MARK_START(x)	(void)0;
#define TIME_TEST_MARK_END()	(void)0;
#define TIME_TEST_MARK_CLOCK()	(void)0;

#define TIME_TEST_BEGIN()		(void)0;
#define TIME_TEST_END(id)		(void)0;
#define time_trace()			(void)0;

#endif

#endif