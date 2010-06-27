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
 *  DebugInit.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : DebugInit.c

   PURPOSE     : To put all trace related functionality in common place

   REMARKS     : nil

   AUTHOR      : Vijay Vaidya

   DATE     : Sep' 4, 2002

**************************************************************/

#include "MMI_include.h"

#include "gv.h"
#include "tst_def.h"



#ifdef DEBUG_ASSERT
BOOL g_mmi_frm_enable_debug_assert = MMI_FALSE;
#endif 

#ifdef DEBUG_FILE
extern FILE *fpDebugTrace;
#endif 

extern void custom_print(kal_char *string);


/*****************************************************************************
 * FUNCTION
 *  get_current_module_id
 * DESCRIPTION
 *  Initialize trace mechanism
 *  
 *  This sets up the desired trace for debugging at predefined levels
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_mutexid mmi_mutex_trace;

#define TRACE_MUTEX_BEGIN        kal_take_mutex(mmi_mutex_trace);
#define TRACE_MUTEX_END       kal_give_mutex(mmi_mutex_trace);
#define GET_CURRENT_MODULE_ID    get_current_module_id()

static module_type get_current_module_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (stack_get_active_module_id())
    {
    #ifdef __J2ME__
        case MOD_J2ME:
            return MOD_J2ME;
        case MOD_JASYN:
            return MOD_JASYN;
    #endif /* __J2ME__ */ 
        default:
            return MOD_MMI;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DebugInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DebugInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  kal_disable_trace
 * DESCRIPTION
 *  To display/print to the debug trace window/file
 * PARAMETERS
 *  mod_id          [IN]        
 *  trc_class       [IN]        
 *  Variable(?)     [IN]        Arguments with format being the first one
 * RETURNS
 *  void
 *****************************************************************************/
/* MTK Elvis  it may cause MMI-task stack to overflow */
S8 nPrintableStr[1000]; /* Assumed..this can chane if need to dump more bytes */

/* MTK end */
extern kal_bool tst_ft_mode;
extern kal_uint8 tst_module_filter_g[];
extern kal_uint8 tst_trace_filter_g[];

MMI_BOOL kal_disable_trace(module_type mod_id, trace_class_enum trc_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tmp_filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tst_ft_mode == KAL_TRUE)
    {
        return MMI_TRUE;
    }

    if ((tst_module_filter_g[mod_id / 8] & (0x01 << (mod_id % 8))) == 0)
    {
        return MMI_TRUE;
    }

    tmp_filter = (tst_trace_filter_g[mod_id * 2]) + (tst_trace_filter_g[mod_id * 2 + 1] << 8);

    if ((tmp_filter & (0x01 << trc_class)) == 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  Trace2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt             [IN]        
 *  arg_type        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void Trace2(U32 fmt, S8 *arg_type, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;
    int ival;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ival = fmt;

    if (kal_disable_trace(GET_CURRENT_MODULE_ID, TRACE_FUNC + ival))
    {
        return;
    }

    TRACE_MUTEX_BEGIN va_start(MyList, arg_type);
    vsprintf(nPrintableStr, arg_type, MyList);
    va_end(MyList);


    if (ival <= MAX_MMI_TRACE_LOG_TYPE)
    {
        kal_wap_trace(GET_CURRENT_MODULE_ID, TRACE_FUNC + ival, nPrintableStr);
    }

TRACE_MUTEX_END}


/*****************************************************************************
 * FUNCTION
 *  Trace3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt             [IN]        
 *  arg_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Trace3(U32 fmt, U32 arg_type, ...)
{
}


/*****************************************************************************
 * FUNCTION
 *  Trace
 * DESCRIPTION
 *  To display/print to the debug trace window/file
 * PARAMETERS
 *  fmt             [?]         
 *  Variable(?)     [IN]        Arguments with format being the first one
 * RETURNS
 *  void
 *****************************************************************************/
void Trace(S8 *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (kal_disable_trace(GET_CURRENT_MODULE_ID, TRACE_INFO))
    {
        return;
    }

    TRACE_MUTEX_BEGIN va_start(MyList, fmt);
    vsprintf(nPrintableStr, fmt, MyList);
    va_end(MyList);

    kal_wap_trace(GET_CURRENT_MODULE_ID, TRACE_INFO, nPrintableStr);

TRACE_MUTEX_END}

/*
 * void DebugClose()
 * {
 * fclose(fpDebugTrace);
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  Trace_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt             [IN]        
 *  arg_type        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_print_trace(module_type mod_id, U32 trc_group, S8 *arg_type, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;
    int ival;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ival = trc_group;

    if (kal_disable_trace(mod_id, TRACE_FUNC + ival))
    {
        return;
    }

    TRACE_MUTEX_BEGIN 
    va_start(MyList, arg_type);
    vsprintf(nPrintableStr, arg_type, MyList);
    va_end(MyList);


    if (ival <= MAX_MMI_TRACE_LOG_TYPE)
    {
        kal_wap_trace(mod_id, TRACE_FUNC + ival, nPrintableStr);
    }

    TRACE_MUTEX_END
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wprintf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id          [IN]        
 *  fmt             [IN]        
 *  wstr            [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wprintf(module_type mod_id, U32 fmt, WCHAR *wstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * MMI_FW_BUFFER_TRACE, MMI_COMMON_APP_BUFFER_TRACE, MMI_MEDIA_APP_BUFFER_TRACE, ...
     * will expand to xxxxx__enum, xxxxx_size when compile the C files
     */
    switch (mod_id)
    {
    case MOD_MMI_FW:
        kal_buffer_trace(fmt, MMI_FW_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_COMMON_APP:
        kal_buffer_trace(fmt, MMI_COMMON_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_MEDIA_APP:
        kal_buffer_trace(fmt, MMI_MEDIA_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_CONN_APP:
        kal_buffer_trace(fmt, MMI_CONN_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_INET_APP:
        kal_buffer_trace(fmt, MMI_INET_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    default:
        kal_buffer_trace(fmt, MMI_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
    }
}




