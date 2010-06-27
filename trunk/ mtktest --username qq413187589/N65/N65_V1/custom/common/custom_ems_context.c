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
 * custom_ems_context.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the EMS maximum segment number.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "kal_non_specific_general_types.h"
#include "string.h"

#include "customer_ps_inc.h"

#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
#include "ems.h"
#include "ems_defs.h"
#endif /* ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 

#include "custom_ems_context.h"

const kal_uint8 ems_miss_seg_str[] = EMS_MISS_SEG_DELIMIT_STR;

#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
/* EMS buffer pool                                            */
/* !! VERY IMPORTANT:  user pointer shall 4-byte alignment !! */
#ifndef __SLIM_EMS__
kal_uint32 ems_mem_pool_buff[EMS_MAX_EMS_DATA][(MMI_SMS_MAX_MSG_SEG * EMS_OBJ_BUFF_SIZE_PER_SEG) / 4];

#ifdef __EMS_REL5__
#define EMS_PDU_POOL_SIZE  (MMI_SMS_MAX_MSG_SEG * 140 * EMS_RATIO_OF_OBJ_PDU_BUFF)
kal_uint32 ems_mem_pdu_pool_buff[EMS_MAX_EMS_DATA][EMS_PDU_POOL_SIZE / 4];
#endif /* __EMS_REL5__ */ 
#endif /* __SLIM_EMS__ */ 
kal_uint8 ems_textBuffer[EMS_MAX_EMS_DATA][MMI_SMS_MAX_MSG_SEG * 153 * 2 + 4];  /* text buffer */
kal_uint8 ems_TPUDLen[EMS_MAX_EMS_DATA][MMI_SMS_MAX_MSG_SEG];
kal_uint8 ems_UDHL[EMS_MAX_EMS_DATA][MMI_SMS_MAX_MSG_SEG];
kal_uint8 ems_oridcsBuffer[EMS_MAX_EMS_DATA][MMI_SMS_MAX_MSG_SEG];

#endif /* ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 


/*****************************************************************************
 * FUNCTION
 *  ems_max_seg_num
 * DESCRIPTION
 *  This function is used to define the
 *  EMS maximum segment number.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 ems_max_seg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_SMS_MAX_MSG_SEG);
}


/*****************************************************************************
 * FUNCTION
 *  ems_obj_buff_size_per_seg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 ems_obj_buff_size_per_seg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (EMS_OBJ_BUFF_SIZE_PER_SEG);
}


/*****************************************************************************
 * FUNCTION
 *  ems_get_miss_seg_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_len     [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *ems_get_miss_seg_str(kal_uint16 *str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str_len != NULL)
    {
        *str_len = strlen((char*)ems_miss_seg_str);
    }

    return ((kal_uint8*) ems_miss_seg_str);
}

#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
#ifndef __SLIM_EMS__

#ifdef __EMS_REL5__


/*****************************************************************************
 * FUNCTION
 *  ems_get_pdu_mem_pool_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ems_id      [IN]        
 *  size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *ems_get_pdu_mem_pool_info(kal_uint8 ems_id, kal_uint16 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ems_id < EMS_MAX_EMS_DATA)
    {
        if (size != NULL)
        {
            *size = ((EMS_PDU_POOL_SIZE >> 2) << 2);
        }

        return (void*)ems_mem_pdu_pool_buff[ems_id];
    }
    else
    {
        return NULL;
    }
}
#endif /* __EMS_REL5__ */ 


/*****************************************************************************
 * FUNCTION
 *  ems_get_mem_pool_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ems_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *ems_get_mem_pool_ptr(kal_uint8 ems_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ems_id < EMS_MAX_EMS_DATA)
    {
        return (void*)ems_mem_pool_buff[ems_id];
    }
    else
    {
        return NULL;
    }

}
#endif /* __SLIM_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  ems_get_text_buff_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ems_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *ems_get_text_buff_ptr(kal_uint8 ems_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ems_id < EMS_MAX_EMS_DATA)
    {
        return (void*)ems_textBuffer[ems_id];
    }
    else
    {
        return NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ems_get_oridcs_buff_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ems_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *ems_get_oridcs_buff_ptr(kal_uint8 ems_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ems_id < EMS_MAX_EMS_DATA)
    {
        return (void*)ems_oridcsBuffer[ems_id];
    }
    else
    {
        return NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ems_get_TPUDLen_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ems_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *ems_get_TPUDLen_ptr(kal_uint8 ems_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ems_id < EMS_MAX_EMS_DATA)
    {
        return (void*)ems_TPUDLen[ems_id];
    }
    else
    {
        return NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ems_get_UDHL_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ems_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *ems_get_UDHL_ptr(kal_uint8 ems_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ems_id < EMS_MAX_EMS_DATA)
    {
        return (void*)ems_UDHL[ems_id];
    }
    else
    {
        return NULL;
    }

}
#endif /* ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 

