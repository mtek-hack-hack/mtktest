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
 *
 * Filename:
 * ---------
 * msf_misc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for miscellaneous adapter functions of Mobile Suite Framework
 *   , including memory management, logging, time information, WTAI function etc.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _MSF_MISC_C_

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "app_buff_alloc.h"
#include "stack_buff_alloc.h"

#include "kal_trace.h"
#include "gv.h"
#include "tst_def.h"

#include "rtc_sw.h"
#include "app_datetime.h"

#include <stdarg.h>
#include <time.h>

#include "msf_int.h"
#include "msf_lib.h"
#include "msf_cfg.h"
#include "msf_act.h"
#include "msf_env.h"
#include "msm_int.h"
#include "msm_env.h"
#include "bra_if.h"
#include "bra_str.h"
#include "stk_if.h"
#include "PhoneBookTypes.h"

#ifdef __MTK_TARGET__
#define  HDI_MSG_LOG
#endif 

typedef float FLOAT;
typedef unsigned char U8;
extern FLOAT GetTimeZone(U8 cityIndex);
extern U8 PhnsetGetHomeCity(void);

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
#define PRINTVALUE_HEAD (0xbbbbbbbb)
#define PRINTVALUE_TAIL (0xcccccccc)
#define PRINTVALUE_HEAD_FREED (0xdddddddd)
#define PRINTVALUE_TAIL_FREED (0xeeeeeeee)
#endif /* !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK) */ 

#ifndef __MTK_TARGET__
static kal_uint16 log_mod_mask = 0xffff;
#else 
static kal_uint16 log_mod_mask = 0x0000;
#endif 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

static trace_class_enum log_mod[15] = 
{
    TRACE_FUNC,
    TRACE_STATE,
    TRACE_INFO,
    TRACE_WARNING,
    TRACE_ERROR,
    TRACE_GROUP_1,
    TRACE_GROUP_2,
    TRACE_GROUP_3,
    TRACE_GROUP_4,
    TRACE_GROUP_5,
    TRACE_GROUP_6,
    TRACE_GROUP_7,
    TRACE_GROUP_8,
    TRACE_GROUP_9,
    TRACE_GROUP_10
};

/**********************************************************************
 * HDI Misc
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_telMakeCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  telId       [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_telMakeCall(MSF_UINT8 modId, MSF_UINT16 telId, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BRAif_telMakeCall(modId, telId, number);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_telSendDtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  telId       [IN]        
 *  dtmf        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_telSendDtmf(MSF_UINT8 modId, MSF_UINT16 telId, const char *dtmf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BRAif_telSendDtmf(modId, telId, dtmf);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_pbAddEntry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  pbId        [IN]        
 *  name        [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_pbAddEntry(MSF_UINT8 modId, MSF_UINT16 pbId, const char *name, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_phb_cntx.phone_used >= g_phb_cntx.phone_total)
    {
        HDIc_pbAddEntryResponse(modId, pbId, HDI_PB_ERROR_PHONE_BOOK_IS_FULL);
        BRAif_showDialog(MsfError, BRA_STR_ERR_PHONEBOOK_FULL);
        return;
    }
    BRAif_pbAddEntry(modId, pbId, name, number);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_timeGetCurrent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 HDIa_timeGetCurrent(void)
{
#ifndef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    time_t ltime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDIa_timeUTCToLocal((MSF_UINT32) time(&ltime));
#else /* __MTK_TARGET__ */ 
    t_rtc rtc;
    struct tm when;

    RTC_GetTime(&rtc);
    when.tm_sec = rtc.rtc_sec;
    when.tm_min = rtc.rtc_min;
    when.tm_hour = rtc.rtc_hour;
    when.tm_mday = rtc.rtc_day;
    when.tm_mon = rtc.rtc_mon - 1;
    when.tm_year = rtc.rtc_year + 100;
    when.tm_isdst = 0;

    return (MSF_UINT32) mktime(&when);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_timeGetTimeZone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT16 HDIa_timeGetTimeZone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_INT16) (GetTimeZone(PhnsetGetHomeCity()) * 60);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_timeUTCToLocal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  utc_time        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 HDIa_timeUTCToLocal(MSF_UINT32 utc_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_dt_sec_utc_to_local(utc_time);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_timeLocalToUTC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_time      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 HDIa_timeLocalToUTC(MSF_UINT32 local_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_dt_sec_local_to_utc(local_time);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memAlloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *HDIa_memAlloc(MSF_UINT8 modId, MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *memory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void *wapadp_mem_alloc(MSF_UINT8 modId, MSF_UINT8 user, MSF_UINT32 size);

#if defined(MMS_SUPPORT) && !defined(WAP_USE_ASM)
    extern int wap_mem_balance(MSF_UINT8 poolId);
#endif 
    extern kal_uint8 wap_status;

#if defined(MMS_SUPPORT) && !defined(WAP_USE_ASM)
    if (modId == MSF_MODID_BRS && wap_mem_balance(WAP_MEM_POOL) < (15 * 1024))
    {
        extern jmp_buf brs_jmp_buf;

        /* Remove STK channel for BRS, currently, the channel id is 1 */
        STKif_removeChannel(MSF_MODID_BRS, 1);
        longjmp(brs_jmp_buf, 1);
    }
#endif /* defined(MMS_SUPPORT) && !defined(WAP_USE_ASM) */ 

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
    size += 8;  /* 4 byte headprint + 4 byte footprint */
#endif 

#ifdef WAP_USE_ASM
    if (modId == MSF_MODID_BRS || modId == MSF_MODID_MEA || modId == MSF_MODID_SMA || modId == MSF_MODID_SLS)
    {
        extern jmp_buf brs_jmp_buf;
        extern jmp_buf wap_jmpbuf;

        memory = wapadp_mem_alloc(WAP_APP_MEM_POOL, modId, size);
        if (memory == NULL)
        {
            /* Remove STK channel for BRS, currently, the channel id is 1 */
            if (modId == MSF_MODID_BRS)
            {
                STKif_removeChannel(MSF_MODID_BRS, 1);
                longjmp(brs_jmp_buf, 1);
            }
            else
            {
                ASSERT(wap_status != WAP_RESET_ONGOING) longjmp(wap_jmpbuf, 1);
            }
        }
    }
    else
    {
#endif /* WAP_USE_ASM */ 

        memory = wapadp_mem_alloc(WAP_MEM_POOL, modId, size);
        if (memory == NULL)
        {
            extern jmp_buf wap_jmpbuf;

        #ifdef WPS_TASK_SUPPORT
            if (modId == MSF_MODID_STK)
            {
                return NULL;
            }
        #endif /* WPS_TASK_SUPPORT */ 
            ASSERT(wap_status != WAP_RESET_ONGOING);
            longjmp(wap_jmpbuf, 1);
        }

    #ifdef WAP_USE_ASM
    }
    #endif 

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
    {
        MSF_UINT32 chunk_size;
        unsigned char *headprint;
        unsigned char *footprint;
        MSF_UINT32 printvalue = PRINTVALUE_HEAD;

        /* record headprint */
        headprint = (unsigned char*)memory;
        /* memset(headprint, 0xff, 4); */
        memcpy(headprint, &printvalue, 4);
        /* record footprint */
        chunk_size = *((MSF_UINT32*) (((unsigned char*)memory) - 4));
        chunk_size = ((chunk_size & ~0x01) >> 1);
        footprint = ((unsigned char*)memory) + (chunk_size - 8) - 4;
        /* memset(footprint, 0xff, 4); */
        printvalue = PRINTVALUE_TAIL;
        memcpy(footprint, &printvalue, 4);
        /* user memory address */
        memory = ((unsigned char*)memory) + 4;
    }
#endif /* !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK) */ 

    return memory;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_memFree(MSF_UINT8 modId, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void wapadp_mem_free(MSF_UINT8 modId, MSF_UINT8 user, void *p);

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
    {
        MSF_UINT32 printvalue = PRINTVALUE_HEAD;
        unsigned char *headprint;
        unsigned char *footprint;
        MSF_UINT32 chunk_size;

        /* address contain headprint */
        p = ((unsigned char*)p) - 4;
        /* check headprint */
        headprint = ((unsigned char*)p);
        ASSERT(!memcmp(headprint, &printvalue, 4))
            /* check footprint */
            chunk_size = *((MSF_UINT32*) (((unsigned char*)p) - 4));
        chunk_size = ((chunk_size & ~0x01) >> 1);
        footprint = (unsigned char*)p + (chunk_size - 8) - 4;
        printvalue = PRINTVALUE_TAIL;
        ASSERT(!memcmp(footprint, &printvalue, 4)) printvalue = PRINTVALUE_HEAD_FREED;
        memcpy(headprint, &printvalue, 4);
        printvalue = PRINTVALUE_TAIL_FREED;
        memcpy(footprint, &printvalue, 4);
    }
#endif /* !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK) */ 

#ifdef WAP_USE_ASM
    if (modId == MSF_MODID_BRS || modId == MSF_MODID_MEA || modId == MSF_MODID_SMA || modId == MSF_MODID_SLS)
    {
        wapadp_mem_free(WAP_APP_MEM_POOL, modId, p);
    }
    else
    {
        wapadp_mem_free(WAP_MEM_POOL, modId, p);
    }
#else /* WAP_USE_ASM */ 
    wapadp_mem_free(WAP_MEM_POOL, modId, p);
#endif /* WAP_USE_ASM */ 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memExternalAlloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *HDIa_memExternalAlloc(MSF_UINT8 modId, MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return HDIa_memAlloc(modId, size);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memExternalFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_memExternalFree(MSF_UINT8 modId, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_memFree(modId, p);
}

#ifdef MSF_CONFIG_INTERNAL_MALLOC


/*****************************************************************************
 * FUNCTION
 *  HDIa_memInternalInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *HDIa_memInternalInit(MSF_UINT8 modId, MSF_UINT32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}
#endif /* MSF_CONFIG_INTERNAL_MALLOC */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  errorNo     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_error(MSF_UINT8 modId, int errorNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId == MSF_MODID_BRS && errorNo == HDI_ERR_MODULE_OUT_OF_MEMORY)
    {
        BRAif_destroyUI();
        BRAif_createUI(BRA_UI_MEM_FULL, NULL);
        return;
    }
    else if (modId == MSF_MODID_STK && errorNo == HDI_ERR_MODULE_OUT_OF_MEMORY)
    {
        ilm_struct *ilm_ptr = NULL;
        ilm_ptr = allocate_ilm(MOD_WPS);
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        ilm_ptr->msg_id = MSG_ID_WAP_INTERNAL_ERROR_IND;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

        SEND_ILM(MOD_WPS, MOD_WAP, WPS_APP_SAP, ilm_ptr);
        return;
    }
	
    EXT_ASSERT((errorNo != HDI_ERR_SYSTEM_FATAL && errorNo != HDI_ERR_MODULE_OUT_OF_MEMORY &&
        errorNo != HDI_ERR_SYSTEM_REG_ABORTED), (kal_uint32) modId, (kal_uint32) errorNo, -1);
}


/*****************************************************************************
 * FUNCTION
 *  set_log_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inject_str      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void set_log_filter(tst_inject_string_struct *inject_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr((const char*)inject_str->string, "MSM"))
    {
        mask |= (0x0001 << MSF_MODID_MSM);
    }
    if (strstr((const char*)inject_str->string, "STK"))
    {
        mask |= (0x0001 << MSF_MODID_STK);
    }
    if (strstr((const char*)inject_str->string, "BRS"))
    {
        mask |= (0x0001 << MSF_MODID_BRS);
    }
    if (strstr((const char*)inject_str->string, "BRA"))
    {
        mask |= (0x0001 << MSF_MODID_BRA);
    }
    if (strstr((const char*)inject_str->string, "PHS"))
    {
        mask |= (0x0001 << MSF_MODID_PHS);
    }
    if (strstr((const char*)inject_str->string, "UIS"))
    {
        mask |= (0x0001 << MSF_MODID_UIS);
    }
    if (strstr((const char*)inject_str->string, "PRS"))
    {
        mask |= (0x0001 << MSF_MODID_PRS);
    }
#ifdef WAP_SEC_SUPPORT
    if (strstr((const char*)inject_str->string, "SEC"))
    {
        mask |= (0x0001 << MSF_MODID_SEC);
    }
#endif /* WAP_SEC_SUPPORT */ 
#ifdef MMS_SUPPORT
    if (strstr((const char*)inject_str->string, "MMS"))
    {
        mask |= (0x0001 << MSF_MODID_MMS);
    }
    if (strstr((const char*)inject_str->string, "MEA"))
    {
        mask |= (0x0001 << MSF_MODID_MEA);
    }
    if (strstr((const char*)inject_str->string, "SLS"))
    {
        mask |= (0x0001 << MSF_MODID_SLS);
    }
    if (strstr((const char*)inject_str->string, "SMA"))
    {
        mask |= (0x0001 << MSF_MODID_SMA);
    }
#endif /* MMS_SUPPORT */ 
    if (strstr((const char*)inject_str->string, "MIB"))
    {
        mask |= (0x0001 << MSF_MODID_MSM)
            | (0x0001 << MSF_MODID_STK)
            | (0x0001 << MSF_MODID_BRS)
            | (0x0001 << MSF_MODID_BRA)
            | (0x0001 << MSF_MODID_PHS) | (0x0001 << MSF_MODID_UIS) | (0x0001 << MSF_MODID_PRS)
    #ifdef WAP_SEC_SUPPORT
            | (0x0001 << MSF_MODID_SEC)
    #endif 
            ;
    }
#ifdef MMS_SUPPORT
    if (strstr((const char*)inject_str->string, "MM"))
    {
        mask |= (0x0001 << MSF_MODID_MSM)
            | (0x0001 << MSF_MODID_STK)
            | (0x0001 << MSF_MODID_PHS) | (0x0001 << MSF_MODID_UIS) | (0x0001 << MSF_MODID_PRS)
    #ifdef WAP_SEC_SUPPORT
            | (0x0001 << MSF_MODID_SEC)
    #endif 
            | (0x0001 << MSF_MODID_MMS)
            | (0x0001 << MSF_MODID_MEA) | (0x0001 << MSF_MODID_SLS) | (0x0001 << MSF_MODID_SMA);
    }
#endif /* MMS_SUPPORT */ 
    if (strstr((const char*)inject_str->string, "ALL"))
    {
        mask = 0xffff;
    }

    /* reset */
    if (inject_str->index == 0)
    {
        mask = ~mask;
        log_mod_mask &= mask;
    }
    else
    {
        log_mod_mask |= mask;
    }
}


#ifdef __MTK_TARGET__

void HDIa_logTrace (int type, MSF_UINT8 modId, int msgId, char *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == HDI_LOG_TYPE_DETAILED_HIGH)
    {
        return;
    }
    
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        return;
    }

    va_start(arg_list, format);
    kal_trace_for_3rd_party(log_mod[modId], msgId, format, arg_list);
    va_end(arg_list);

}

#else

void HDIa_logTrace (int type, MSF_UINT8 modId, int msgId, char *dummy, char *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char log[129] = "";
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == HDI_LOG_TYPE_DETAILED_HIGH)
    {
        return;
    }
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        return;
    }

    va_start(arg_list, format);
    _vsnprintf(log, 128, format, arg_list);
    va_end(arg_list);

    kal_wap_trace(MOD_WAP, log_mod[modId], "%s", log);
	/* kal_printf("%s", log); */
}

#endif


/*****************************************************************************
 * FUNCTION
 *  HDIa_logMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  modId       [IN]        
 *  format      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_logMsg(int type, MSF_UINT8 modId, const char *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_MEM_DEBUG
    extern void wap_mem_debug(MSF_UINT8 modId, const char *mem_log);
#endif 

    extern int MSF_wapIsReady(void);
    extern kal_uint8 wap_status;
    char log[128];
    va_list arg_list;

#ifndef WAP_MEM_DEBUG
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        return;
    }
#endif /* WAP_MEM_DEBUG */ 

#ifdef HDI_MSG_LOG
    if (wap_status != WAP_RUNNING || MSF_wapIsReady() <= 0 || type == HDI_LOG_TYPE_DETAILED_HIGH)
#endif 
    {
        /* filter */
        return;
    }

    va_start(arg_list, format);
    vsnprintf(log, 128, format, arg_list);
    va_end(arg_list);

#ifdef WAP_MEM_DEBUG
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        wap_mem_debug(modId, log);
    }
    else
#endif /* WAP_MEM_DEBUG */ 
    {
        kal_wap_trace(MOD_WAP, log_mod[modId], "%s", log);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_logData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  modId       [IN]        
 *  data        [IN]        
 *  dataLen     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_logData(int type, MSF_UINT8 modId, const unsigned char *data, int dataLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 log[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsReady(void);
    extern kal_uint8 wap_status;

#if 1
    if (wap_status != WAP_RUNNING || MSF_wapIsReady() <= 0 || type == HDI_LOG_TYPE_DETAILED_HIGH)
#else 
/* under construction !*/
#endif 
    {
        /* filter */
        return;
    }

    kal_mem_cpy(log, data, (dataLen > 128 ? 128 : dataLen));
#if 1
    kal_wap_trace(MOD_WAP, log_mod[modId], "%s", log);
#else 
/* under construction !*/
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_logSignal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcModId        [IN]        
 *  dstModId        [IN]        
 *  data            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_logSignal(MSF_UINT8 srcModId, MSF_UINT8 dstModId, const char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 log[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsReady(void);
    extern kal_uint8 wap_status;

#if 1
    if (wap_status != WAP_RUNNING || MSF_wapIsReady() <= 0)
#else 
/* under construction !*/
#endif 
    {
        /* filter */
        return;
    }

    kal_mem_cpy(log, data, (strlen(data) > 128 ? 128 : strlen(data)));
#if 1
    kal_wap_trace(MOD_WAP, log_mod[dstModId], "%s", log);
#else 
/* under construction !*/
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_getModuleID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT8 HDIa_getModuleID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 msf_active_modId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return msf_active_modId;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_killTask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_killTask(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern int msf_mod_status[MSF_NUMBER_OF_MODULES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msf_mod_status[modId] = MSM_MODULE_STATUS_TERMINATED;
}

/**********************************************************************
 * Object Actions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_objectAction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action_cmd          [IN]        
 *  mime_type           [IN]        
 *  data_type           [IN]        
 *  data                [IN]        
 *  data_len            [IN]        
 *  src_path            [IN]        
 *  default_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_objectAction(
        const char *action_cmd,
        const char *mime_type,
        MsfResourceType data_type,
        const unsigned char *data,
        MSF_INT32 data_len,
        const char *src_path,
        const char *default_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/**********************************************************************
 * Mime Action table customizable section
 **********************************************************************/

const int extern_nbr_of_mime_actions = 1;

const msf_act_mime_action_t msf_act_mime_action_table[] = 
{
  { "*/*",
    MSF_PACKET_OPERATION_ID_SAS,
    0,
    MSF_STR_ID_MIME_ACTION_SAVE,
    MSF_MIME_ACTION_TYPE_PACKET,
    -1,
    MSF_PERMISSION_NONE_BLOCKED
  }
};

