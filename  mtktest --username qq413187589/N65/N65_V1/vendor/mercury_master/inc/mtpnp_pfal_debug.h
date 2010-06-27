/***********************************************
File name : MTPNP_PFAL_Debug.h
Contents : MTPNP debug interface
History : Create by : Zhang Nan, Apr 5, 2007
************************************************/
#ifndef __MTPNP_PFAL_DEBUG_H__
#define __MTPNP_PFAL_DEBUG_H__
#include <stdio.h>

extern void MTPNP_PFAL_Assert(MTPNP_INT expression, MTPNP_CHAR * filename, MTPNP_UINT32 line_no);

extern MTPNP_BOOL MTPNP_DBG_open_LogFile(void);
extern MTPNP_BOOL MTPNP_DBG_write_Log(const MTPNP_CHAR * format, ...);
extern MTPNP_BOOL MTPNP_DBG_close_LogFile(void);

#ifdef WIN32
#define MTPNP_PFAL_ASSERT(expr) (void)( (expr) || (_assert(#expr, __FILE__, __LINE__), 0) )
#else
#define MTPNP_PFAL_ASSERT(expr) MTPNP_PFAL_Assert(expr, __FILE__, __LINE__)
#endif

//#define __MERCURY_TRACE__

#ifdef __MERCURY_TRACE__
#define MERCURY_TRACE_SIZE 255
#define MERCURY_FUNC_SIZE 31
#define MERCURY_BUF_SIZE 127
#define MERCURY_BUF_CNT 50

#ifdef WIN32
#define __func__ (strrchr(__FILE__, '\\')+1)
#endif

typedef struct
{
    unsigned int second;
    unsigned short count;
    unsigned short line;
    char func[MERCURY_FUNC_SIZE + 1];
    char buf[MERCURY_BUF_SIZE + 1];
} ST_MERCURY_TRACE;

extern ST_MERCURY_TRACE mercury_buf[MERCURY_BUF_CNT];
extern unsigned int mercury_cnt;
extern unsigned int mercury_group;
extern void mercury_trace(int sth, char *fmt, ...);

#define kal_prompt_trace \
{ \
	static unsigned short cnt = 0; \
	mercury_buf[mercury_cnt].count = ++cnt; \
	mercury_buf[mercury_cnt].line = __LINE__; \
	_snprintf(mercury_buf[mercury_cnt].func, MERCURY_FUNC_SIZE, "%s", __func__); \
} mercury_trace

#endif

#endif // __MTPNP_PFAL_DEBUG_H__
