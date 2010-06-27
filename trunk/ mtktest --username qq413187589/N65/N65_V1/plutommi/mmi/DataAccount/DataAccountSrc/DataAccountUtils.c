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
 * DataAccountUtils.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Utility functions for Data Account.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "DataAccountCommon.h"

#ifdef __MMI_WLAN_FEATURES__


/*****************************************************************************
 * FUNCTION
 *  hex_to_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [?]         
 *  src         [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL hex_to_string(U8 *dest, U8 *src, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len % 2 != 0)
    {
        return FALSE;
    }

    memset(dest, 0, len / 2 + 1);

    for (i = 0, j = 0; i < len; i++)
    {
        j = (i - i % 2) / 2;
        if (src[i] >= '0' && src[i] <= '9')
        {
            dest[j] += (src[i] - '0') << 4 * ((i + 1) % 2);
        }
        else if (src[i] >= 'A' && src[i] <= 'F')
        {
            dest[j] += (src[i] - 'A' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else if (src[i] >= 'a' && src[i] <= 'f')
        {
            dest[j] += (src[i] - 'a' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  is_valid_hexstring
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL is_valid_hexstring(U8 *src, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (src[i] >= '0' && src[i] <= '9')
        {
            continue;
        }
        else if (src[i] >= 'A' && src[i] <= 'F')
        {
            continue;
        }
        else if (src[i] >= 'a' && src[i] <= 'f')
        {
            continue;
        }
        else
        {
            return FALSE;
        }
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  state2str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const char* state2str(wlan_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(state)
    {
    case WLAN_STATE_NULL:
        return "NULL";
    case WLAN_STATE_DEINIT_WAIT:
        return "DEINIT_WAIT";
    case WLAN_STATE_INIT_WAIT:
        return "INIT_WAIT";
    case WLAN_STATE_INIT:
        return "INIT";
    case WLAN_STATE_DISCONNECT_WAIT:
        return "DISCONNECT_WAIT";
    case WLAN_STATE_CONNECT_WAIT:
        return "CONNECT_WAIT";
    case WLAN_STATE_CONNECTED:
        return "CONNECTED";
    }
    
    ASSERT(0);
    return NULL;
}
#endif /* __MMI_WLAN_FEATURES__ */ 

