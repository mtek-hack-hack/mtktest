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
 * customer_data_account.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the Data Account context / functions.
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"

#include "custom_nvram_editor_data_item.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"

#include "custom_data_account.h"

#ifndef __L1_STANDALONE__

#ifdef __PS_SERVICE__   
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    nvram_ef_abm_gprs_profile_struct abm_gprs_profile[MAX_GPRS_PROFILE_NUM+1];
    kal_uint8 abm_gprs_state[MAX_GPRS_PROFILE_NUM+1];
    kal_uint8 abm_gprs_bearer_id[MAX_GPRS_PROFILE_NUM+1];   
#endif /* __MMI_OP01_GPRS_DATACFG__ */
#else /* __PS_SERVICE__ */
    nvram_ef_abm_gprs_profile_struct abm_gprs_profile[6]; /* dummy array */
    kal_uint8 abm_gprs_state[6];
    kal_uint8 abm_gprs_bearer_id[6];   
#endif /* __PS_SERVICE__ */

#ifdef __TCPIP__
   nvram_ef_csd_profile_struct      csd_prof[CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM];
#endif /*__TCPIP__*/

#endif /* __L1_STANDALONE__ */   

/*****************************************************************************
* FUNCTION
*  custom_get_gprs_profile_num 
* DESCRIPTION
*   This function is used to get the GPRS profile number.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 custom_get_gprs_profile_num()
{
   return MAX_GPRS_PROFILE_NUM;
}

/*****************************************************************************
* FUNCTION
*  custom_get_csd_profile_num 
* DESCRIPTION
*   This function is used to get the CSD profile number.
* 
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 custom_get_csd_profile_num()
{
   return CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM;
}   

/*****************************************************************************
* FUNCTION
*  custom_get_gprs_profile_size 
* DESCRIPTION
*   This function is used to get the total GPRS profile size.
* 
* PARAMETERS
*
* RETURNS
*  kal_int32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_int32 custom_get_gprs_profile_size()
{
#ifdef __L1_STANDALONE__
   return 0;
#else   
   return sizeof(nvram_meta_abm_gprs_profile_struct);
#endif /* __L1_STANDALONE__ */
}


