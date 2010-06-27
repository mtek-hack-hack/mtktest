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
 * MSF_NW_ACC.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the adaptive function of HDI Network Account.
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
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "nvram_editor_data_item.h"
#include "custom_nvram_editor_data_item.h"
#include "l4c2abm_struct.h"
#include "abm_util.h"
#include "abm_soc_enums.h"

#include "msf_int.h"
#include "nvram_user_defs.h"
#include "custom_nvram_editor_data_item.h"

#ifdef __PS_SERVICE__
#include "mmi_l3_enums.h"
#include "l3_inc_enums.h"
#ifdef __MCD__
#include "mcd_l3_inc_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#else /* __MCD__ */ 
#include "l3_inc_struct.h"
#endif /* __MCD__ */ 
#include "ppp_l4_enums.h"
#include "mmi_sm_enums.h"
#include "tcm_common_enums.h"
#include "tcm_common.h"
#include "l4c2tcm_struct.h"
#include "l4c2tcm_func.h"
#endif /* __PS_SERVICE__ */ 

#include "msf_chrs.h"
#include "bra_str.h"
#include "mcd_l4_common.h"
#include "l4c2phb_enums.h"
#include <stdio.h>

#include "widget_extension.h"

extern kal_bool l4ccsm_cc_get_csd_prof(kal_uint8 csd_prof_id, nvram_ef_csd_profile_struct *csd_prof_ptr);

kal_uint8 abm2hdi_enum_table[] = {HDI_SOCKET_BEARER_IP_ANY, HDI_SOCKET_BEARER_GSM_CSD, HDI_SOCKET_BEARER_GSM_GPRS, HDI_SOCKET_BEARER_WIFI};


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetBearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_networkAccountGetBearer(MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer = 0, bearer_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (KAL_FALSE == abm_nw2bearer_id((kal_uint32) networkAccountID, &bearer, &bearer_id))
    {
        return -1;
    }
    else
    {
        return abm2hdi_enum_table[bearer];
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetName
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 *  buf                     [?]         
 *  buflen                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_networkAccountGetName(MSF_INT32 networkAccountID, char *buf, int buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer = 0, bearer_id = 0;
    nvram_ef_csd_profile_struct csd_prof;
    char buffer[64];
    char dummy[64];
    MSF_UINT8 len;
    int srcLen, dstLen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(abm_nw2bearer_id((kal_uint32)networkAccountID, &bearer, &bearer_id) == KAL_FALSE)
    {
        return -1;
    }

    switch(bearer)
    {
    case ABM_E_SOCKET_BEARER_GSM_CSD:
        if(l4ccsm_cc_get_csd_prof(bearer_id, &csd_prof) == KAL_TRUE && csd_prof.name.name_length > 0)
        {
            if(csd_prof.name.name_dcs == PHB_ASCII)
            {
                strncpy(buf, (const char *)csd_prof.name.name, 
                    (csd_prof.name.name_length < buflen) ? csd_prof.name.name_length : buflen);
                return 0;
            }
            else if(csd_prof.name.name_dcs == PHB_UCS2)
            {
                srcLen = csd_prof.name.name_length;
                dstLen = buflen;
                msf_charset_ucs2be_to_utf8((const char*)csd_prof.name.name, (long *)&srcLen, buf, (long *)&dstLen);
                return 0;
            }
        }
        break;
#ifdef __PS_SERVICE__
    case ABM_E_SOCKET_BEARER_GSM_GPRS:
        {
            l4c_gprs_account_info_struct gprs_prof;
            
            gprs_prof.context_id = bearer_id;
            
            if(l4cabm_get_gprs_account_info(&gprs_prof) == KAL_TRUE && gprs_prof.name_length > 0)
            {
                if(gprs_prof.name_dcs == PHB_ASCII)
                {
                    strncpy(buf, (const char *)gprs_prof.name, 
                        (gprs_prof.name_length < buflen) ? gprs_prof.name_length : buflen);
                    return 0;
                }
                else if(gprs_prof.name_dcs == PHB_UCS2)
                {
                    srcLen = gprs_prof.name_length;
                    dstLen = buflen;
                    msf_charset_ucs2be_to_utf8((const char*)gprs_prof.name, (long *)&srcLen, buf, (long *)&dstLen);
                    return 0;
                }
            }            
        }
        break;
#endif
#ifdef __WIFI_SUPPORT__
    case ABM_E_SOCKET_BEARER_WIFI:
        {
            len = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_BEARER_WIFI, 1, MsfUtf8);
            MSF_WIDGET_STRING_GET_DATA (BRA_STR_BEARER_WIFI, buffer, MsfUtf8);
            strncpy(buf, buffer, len > buflen ? buflen : len);
            return 0;
        }
        break;
#endif
    default:
        break;        
    }

    /* Generate default name if it is not defined */
    len = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_SET_DEF_NET_ID, 1, MsfUtf8);

    MSF_WIDGET_STRING_GET_DATA(BRA_STR_SET_DEF_NET_ID, dummy, MsfUtf8);

    sprintf(buffer, "%s %d", dummy, bearer_id);

    strncpy(buf, buffer, strlen(buffer) > buflen ? buflen : strlen(buffer));    
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bearer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_networkAccountGetId(int bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 nw_acc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (HDI_SOCKET_BEARER_GSM_CSD == bearer)
    {
        if (KAL_FALSE == abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_CSD, 0, &nw_acc_id))
        {
            return -1;
        }
    }
    else if (HDI_SOCKET_BEARER_GSM_GPRS == bearer)
    {
        if (KAL_FALSE == abm_bearer2nw_id(ABM_E_SOCKET_BEARER_GSM_GPRS, 1, &nw_acc_id))
        {
            return -1;
        }
    }
    else if(HDI_SOCKET_BEARER_WIFI == bearer)
    {
        if(KAL_FALSE == abm_bearer2nw_id(ABM_E_SOCKET_BEARER_WIFI, 0, &nw_acc_id))
        {
             return -1;
        }
    }
    else
    {
        return -1;
    }

    return (MSF_INT32)nw_acc_id;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetFirst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_networkAccountGetFirst()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ABM_MIN_NWACC_ID;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_networkAccountGetNext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  networkAccountID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_INT32 HDIa_networkAccountGetNext(MSF_INT32 networkAccountID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* abm_get_total_bearer()-1 is for one invisible GPRS profile ID (SAT use only) */
#ifdef __PS_SERVICE__
    if (ABM_MIN_NWACC_ID <= networkAccountID && abm_get_total_bearer() - 1 > networkAccountID + 1)
#else 
    if (ABM_MIN_NWACC_ID <= networkAccountID && abm_get_total_bearer() > networkAccountID + 1)
#endif 
    {
        return networkAccountID + 1;
    }
    else
    {
        return -1;
    }
}

