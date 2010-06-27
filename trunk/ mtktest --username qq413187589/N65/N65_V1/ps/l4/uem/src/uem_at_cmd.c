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
 * UEM_AT_CMD.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for AT command test function.
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Includes
*****************************************************************************/
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stdio.h"
#include "kal_trace.h"
#include "stacklib.h"
#include "stack_timer.h"
#include "event_shed.h"

#include "device.h"

#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"

#include "l4c2uem_struct.h"

#include "uem_context.h"
#include "uem_at_cmd.h"
#include "uem_trc.h"
#include "uem_utility.h"

/***************************************************************************** 
* Local Variables Declaration
*****************************************************************************/
static kal_int8 at_test_string[30];

/***************************************************************************** 
****************************************************************************** 
* External Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      l4cuem_test_alarm_setting
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_alarm_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_alarm_setting(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CALA: (0..2),(4)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_alarm_delete
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_alarm_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_alarm_delete(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CALD: 0-2";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_clock_setting
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_clock_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_clock_setting(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) " ";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_date_format
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_date_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_date_format(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CSDF: (1..7)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_time_format
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_time_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_time_format(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CSTF: (1..2)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_battery_level
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_battery_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_battery_level(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CBC: (0,2),(0..3)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_language
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_language(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CLAN: (\"en\", \"tw\", \"zh\") ";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_volume_level
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_volume_level(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        kal_sprintf((kal_char*) at_test_string, "+CLVL: (0-%d)", MAX_VOL_LEVEL - 1);
        *buffer = (kal_uint8*) at_test_string;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_ring_volume_level
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_ring_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_ring_volume_level(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        kal_sprintf((kal_char*) at_test_string, "+CRSL: (1-%d)", MAX_VOL_LEVEL);
        *buffer = (kal_uint8*) at_test_string;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef __test_mode__
/*****************************************************************************
*   Function 
*      l4cuem_test_mute_mode
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_mute_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_mute_mode(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CMUT: (0,1)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif /* __test_mode__ */ 

/*****************************************************************************
*   Function 
*      l4cuem_test_silent_mode
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_silent_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_silent_mode(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CSIL: (0,1)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_vibrator_mode
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_vibrator_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_vibrator_mode(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CVIB: (0,1)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_greeting_text
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_greeting_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_greeting_text(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        kal_sprintf((kal_char*) at_test_string, "+CSGT: (0,1),%d", 30);
        *buffer = (kal_uint8*) at_test_string;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  l4cuem_at_query_is_charging
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_at_query_is_charging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER) ||
        FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CHARGER))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  l4cuem_at_query_is_clam_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_at_query_is_clam_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

