/***********************************************
File name : MTPNP_PFAL_Debug.c
Contents : MTPNP debug interface
History : Create by : Zhang Nan, Apr 5, 2007
************************************************/
#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif
#include <stdarg.h>
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_Debug.h"

#ifdef kal_prompt_trace
#undef kal_prompt_trace
#endif
#if defined(NOKE_DEBUG)
extern void noke_dbg_printf( const char * format,  ... );
#endif
void MTPNP_PFAL_Assert(MTPNP_INT expression, MTPNP_CHAR * filename, MTPNP_UINT32 line_no)
{
#if !(defined(MMI_ON_WIN32) || defined(WIN32))
    extern void kal_assert_fail(MTPNP_CHAR * expr,
                                MTPNP_CHAR * file,
                                MTPNP_UINT32 line,
                                MTPNP_BOOL isext, MTPNP_UINT32 ex1, MTPNP_UINT32 ex2, MTPNP_UINT32 ex3);

    if (!expression)
    {
#if defined(NOKE_DEBUG)
    	noke_dbg_printf("FILE: %s, LINE:%d\n",  __FILE__, __LINE__);
#endif
       kal_assert_fail("[MTPNP] assert", filename, line_no, MTPNP_TRUE, 0, 0, 0);

    }
#endif
}

void MTPNP_PFAL_Print_Slave_Debug_String(void *info)
{
    ST_MTPNP_DATA_DBG_INFO *dbgInfo = (ST_MTPNP_DATA_DBG_INFO *) info;
    kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "Sender:%d,Content:%s", dbgInfo->sender, dbgInfo->content);
}

void MTPNP_PFAL_Output_Local_Debug_String(const MTPNP_UINT8 * dbg_info)
{
    kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "%s", dbg_info);
}

#ifdef __MERCURY_TRACE__
ST_MERCURY_TRACE mercury_buf[MERCURY_BUF_CNT] = { 0 };
unsigned int mercury_cnt = 0;
unsigned int mercury_group = 0;
void mercury_trace(int sth, char *fmt, ...)
{
    char buf[MERCURY_TRACE_SIZE];
    va_list ap;
    unsigned int tick, i;
    int n;

    kal_get_time(&tick);
    mercury_buf[mercury_cnt].second = tick * 0.004615;

    i = mercury_cnt;

    va_start(ap, fmt);
    _vsnprintf(mercury_buf[mercury_cnt++].buf, MERCURY_BUF_SIZE, fmt, ap);
    va_end(ap);

    if (mercury_cnt >= MERCURY_BUF_CNT)
    {
        mercury_cnt = 0;
        mercury_group++;
    }

    n = _snprintf(buf, MERCURY_TRACE_SIZE, "<%s:%d:%d>%s\r\n", mercury_buf[i].func, mercury_buf[i].line,
                  mercury_buf[i].count, mercury_buf[i].buf);

#ifdef WIN32
    OutputDebugString(buf);
#else
//      U_PutUARTBytes(0, (unsigned char *)buf, n);
#endif
//      kal_debug_print(buf);

#if defined(NOKE_DEBUG)
noke_dbg_printf( "%s", buf);
#endif
   // kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "%s", buf);
}

void print_mercury_trace(void)
{
    char buf[MERCURY_TRACE_SIZE];
    int i, n;

    kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "mercury_group=%d", mercury_group);
    for (i = 0; i < MERCURY_BUF_CNT; i++)
    {
        if (mercury_buf[i].buf[0] == 0x00)
        {
            break;
        }
        n = _snprintf(buf, MERCURY_TRACE_SIZE, "[%u]<%s:%d:%d>%s\r\n", mercury_buf[i].second, mercury_buf[i].func,
                      mercury_buf[i].line, mercury_buf[i].count, mercury_buf[i].buf);
      //  kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "%s", buf);
#if defined(NOKE_DEBUG)
      noke_dbg_printf( "%s", buf);
#endif
    }
}

#endif

#endif /* __MMI_DUAL_SIM_MASTER__ */
