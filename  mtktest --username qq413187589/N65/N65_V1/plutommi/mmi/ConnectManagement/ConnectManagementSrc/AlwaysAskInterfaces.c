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
 * AlwaysAskInterfaces.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

//#ifdef __CBM_ALWAYS_ASK_FEATURE__

#include "MMI_features.h"

#include "ProtocolEvents.h"
#include "DebugInitDef.h"

#include "ConnectManageGProt.h"
#include "ConnectManageStruct.h"
/*
#define ALWAYS_ASK_MAX_APP_ID_SIZE      255
#define ALWAYS_ASK_MAX_APP_NAME_LEN     32

#define ENCODE_MASK_ALWAYS_ASK          0x02
#define ENCODE_MASK_SIM                 0x01

#define ALWAYS_ASK_MAX_APP_NUM         20


typedef union
{
    kal_uint32 acct_id;
    struct  
    {
        kal_uint8 ori_acct_id;
        kal_uint8 app_id;
        kal_uint8 mask;
        kal_uint8 reverse;
    }acct_mask;
}acct_union_struct; 

typedef struct always_ask_register
{
    kal_uint8 app_id;
    kal_semid always_ask_sem_id;
}always_ask_register_struct;

typedef struct  
{
    FuncPtrAccountSelectExt always_ask_callback;
    kal_uint32 mod_id;
    kal_uint32 app_id;
    kal_uint8  valid;
    kal_uint16 app_str_id;
}cbm_always_ask_struct;
*/

static cbm_always_ask_struct    g_cbm_always_ask[ALWAYS_ASK_MAX_APP_NUM];
static always_ask_register_struct g_register_always_ask;
#define ALWAYS_ASK_SEM_STRING  "ALWAYS_ASK"

/* start always ask feature */
/*****************************************************************************
 * FUNCTION
 *  always_ask_register_app_chain_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
BOOL always_ask_create_sem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(g_cbm_always_ask, 0, sizeof(cbm_always_ask_struct)*ALWAYS_ASK_MAX_APP_NUM);
    g_register_always_ask.always_ask_sem_id = kal_create_sem( ALWAYS_ASK_SEM_STRING, 1 );
    g_register_always_ask.app_id = 0;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  always_ask_register_app_chain_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool always_ask_register_app_chain_add(kal_uint8 app_id, kal_uint16 app_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /**/
    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if(!g_cbm_always_ask[i].valid)
        {
            g_cbm_always_ask[i].app_str_id = app_str_id;
            g_cbm_always_ask[i].app_id = app_id;
            g_cbm_always_ask[i].always_ask_callback = NULL;
            g_cbm_always_ask[i].mod_id = 0;
            g_cbm_always_ask[i].valid = KAL_TRUE;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  always_ask_register_app_chain_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool always_ask_register_app_chain_del(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if((g_cbm_always_ask[i].app_id == app_id) &&
            (g_cbm_always_ask[i].valid))
        {
            g_cbm_always_ask[i].app_str_id = 0;
            g_cbm_always_ask[i].always_ask_callback = NULL;
            g_cbm_always_ask[i].mod_id = 0;
            g_cbm_always_ask[i].app_id = 0;
            g_cbm_always_ask[i].valid = KAL_FALSE;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}




/* Thread-safe apis */
/*****************************************************************************
 * FUNCTION
 *  always_ask_register_get_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_register_get_app_name(kal_uint8 app_id, kal_uint16* app_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_bool check_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(app_str_id == NULL)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    /* take sem */
    kal_take_sem( g_register_always_ask.always_ask_sem_id, KAL_INFINITE_WAIT );

    /* check app id */
    check_result = always_ask_register_app_check_id(app_id);
    if(!check_result)
    {
        /* release sem */
        kal_give_sem( g_register_always_ask.always_ask_sem_id );
        return KAL_FALSE;
    }

    /* get app name */
    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if((g_cbm_always_ask[i].valid) && (g_cbm_always_ask[i].app_id == app_id))
        {
           *app_str_id = g_cbm_always_ask[i].app_str_id;
            
            /* release sem */
            kal_give_sem( g_register_always_ask.always_ask_sem_id );
            return KAL_TRUE;
        }
    }

    /* release sem */
    kal_give_sem( g_register_always_ask.always_ask_sem_id );
    return KAL_FALSE;
}




/*****************************************************************************
 * FUNCTION
 *  abm_register_chain_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_register_app_check_id(kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(app_id == 0)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if((g_cbm_always_ask[i].valid) && (g_cbm_always_ask[i].app_id == app_id))
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  abm_encode_data_account_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 always_ask_encode_data_account_id(kal_uint32 acct_id, always_ask_sim_info_enum sim_src, kal_uint8 app_id, kal_bool always_ask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm encode acct_id = %d, sim = %d, app_id = %d, alwasy_ask = %d", 
                     acct_id, sim_src, app_id, always_ask);

    if(sim_src >= ALWAYS_ASK_SIM_INFO_TOTAL)
    {
        ASSERT(0);
        return acct_id;
    }

    /* reset sim info , alwasy ask and app id. */
    acct_union_id.acct_id = (acct_id & 0x000000ff);

    /* set app id info to acct_id */
    acct_union_id.acct_mask.app_id = app_id;

    /* set sim info to acct_id */
    if(sim_src == ALWAYS_ASK_SIM_INFO_SIM2)
    {
        acct_union_id.acct_mask.mask |= ENCODE_MASK_SIM;
    }

    /* set always ask info to acct_id */
    if(always_ask)
    {
        acct_union_id.acct_mask.mask |= ENCODE_MASK_ALWAYS_ASK;
    }

    return acct_union_id.acct_id;
}


/*****************************************************************************
 * FUNCTION
 *  abm_encode_app_id_data_account_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 always_ask_encode_app_id_data_account_id(kal_uint32 acct_id, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm encode app id acct_id = %d, app_id = %d", acct_id, app_id);

    acct_union_id.acct_id = acct_id;

    /* set app id info to acct_id */
    acct_union_id.acct_mask.app_id = app_id;

    return acct_union_id.acct_id;
}


/*****************************************************************************
 * FUNCTION
 *  abm_decode_data_account_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_decode_data_account_id(kal_uint32 acct_id, always_ask_sim_info_enum *sim_src, kal_uint8 *app_id, kal_bool *always_ask, kal_uint32* ori_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 old_acct_id;
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm decode acct_id = %d", acct_id);

    if((sim_src == NULL) && (app_id == NULL) && (always_ask == NULL) && (ori_acct_id == NULL))
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    /* set the union acct_id. */
    acct_union_id.acct_id = acct_id;
    
    if(app_id)
    {
        /* get app id info from union acct_id */
        *app_id = acct_union_id.acct_mask.app_id;
    }
    
    if(ori_acct_id)
    {
        /* get ori acct id from union acct id */
        *ori_acct_id = acct_union_id.acct_mask.ori_acct_id;
    }
    
    if(sim_src)
    {
        /* get sim info from union acct_id */
        if(acct_union_id.acct_mask.mask & ENCODE_MASK_SIM)
        {
            *sim_src = ALWAYS_ASK_SIM_INFO_SIM2;
        }
        else
        {
            *sim_src = ALWAYS_ASK_SIM_INFO_SIM1;
        }
    }
    
    if(always_ask)
    {
        /* get always ask info from union acct_id */
        if(acct_union_id.acct_mask.mask & ENCODE_MASK_ALWAYS_ASK)
        {
            *always_ask = KAL_TRUE;
        }
        else
        {
            *always_ask = KAL_FALSE;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  abm_is_always_ask_data_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_is_always_ask_data_account(kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool always_ask_result;
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm is always ask acct_id = %d", acct_id);

    /* set the union acct_id. */
    acct_union_id.acct_id = acct_id;
    
    /* get always ask info from union acct_id */
    if(acct_union_id.acct_mask.mask & ENCODE_MASK_ALWAYS_ASK)
    {
        always_ask_result = KAL_TRUE;
    }
    else
    {
        always_ask_result = KAL_FALSE;
    }

    return always_ask_result;
}


/*****************************************************************************
 * FUNCTION
 *  abm_get_sim_info_data_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
always_ask_sim_info_enum always_ask_get_sim_info_data_account(kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    always_ask_sim_info_enum sim_info;
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm sim info acct_id = %d", acct_id);
    
    /* set the union acct_id. */
    acct_union_id.acct_id = acct_id;
    
    /* get sim info from union acct_id */
    if(acct_union_id.acct_mask.mask & ENCODE_MASK_SIM)
    {
        sim_info = ALWAYS_ASK_SIM_INFO_SIM2;
    }
    else
    {
        sim_info = ALWAYS_ASK_SIM_INFO_SIM1;
    }
   
    return sim_info;
}


/*****************************************************************************
 * FUNCTION
 *  abm_get_app_id_data_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 always_ask_get_app_id_data_account(kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 app_id;
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm app id acct_id = %d", acct_id);
    
    /* set the union acct_id. */
    acct_union_id.acct_id = acct_id;
    
    /* get app id info from union acct_id */
    app_id = acct_union_id.acct_mask.app_id;

    return app_id;
}


/*****************************************************************************
 * FUNCTION
 *  abm_get_original_id_data_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 always_ask_get_original_id_data_account (kal_uint32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 ori_acct_id;
    acct_union_struct acct_union_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_ABM, "[ABM_ALWAYS_ASK] abm ori_acct_id acct_id = %d", acct_id);
    
    /* set the union acct_id. */
    acct_union_id.acct_id = acct_id;
    
    /* get ori acct id from union acct id */
    ori_acct_id = acct_union_id.acct_mask.ori_acct_id;

    return ori_acct_id;
}

/* Thread-safe api */
/*****************************************************************************
 * FUNCTION
 *  mmi_cbm_get_app_register_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_cbm_get_app_register_info(U8 app_id, module_type mod_id, mmi_cbm_app_register_info_struct *app_register_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(app_id == 0)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    /* take sem */
    kal_take_sem( g_register_always_ask.always_ask_sem_id, KAL_INFINITE_WAIT );

    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if((g_cbm_always_ask[i].valid) && (g_cbm_always_ask[i].app_id == app_id))
        {
            if((g_cbm_always_ask[i].always_ask_callback) &&
                (g_cbm_always_ask[i].mod_id == 0))
            {
                app_register_info->register_type = REGISTER_TYPE_CALLBACK;
                app_register_info->callback = g_cbm_always_ask[i].always_ask_callback;
                app_register_info->mod_id = 0;
                app_register_info->app_id = app_id;
            }
            else if((g_cbm_always_ask[i].always_ask_callback == NULL) &&
                    (g_cbm_always_ask[i].mod_id != 0))
            {
                app_register_info->register_type = REGISTER_TYPE_PRIMITIVE;
                app_register_info->callback = NULL;
                app_register_info->mod_id = mod_id;
                app_register_info->app_id = app_id;
            }
            else
            {
                app_register_info->app_id = app_id;
                app_register_info->register_type = REGISTER_TYPE_TOTAL;
                /* release sem */
                kal_give_sem( g_register_always_ask.always_ask_sem_id );
                return FALSE;
            }

            /* release sem */
            kal_give_sem( g_register_always_ask.always_ask_sem_id );
            return TRUE;
        }
    }

    /* release sem */
    kal_give_sem( g_register_always_ask.always_ask_sem_id );
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  always_ask_register_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 always_ask_register_app_id (U16 app_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* take sem */
    kal_take_sem( g_register_always_ask.always_ask_sem_id, KAL_INFINITE_WAIT );

    ++g_register_always_ask.app_id;
    result = always_ask_register_app_chain_add(g_register_always_ask.app_id, app_str_id);

    /* release sem */
    kal_give_sem( g_register_always_ask.always_ask_sem_id );

    if(!result)
    {
        return 0;
    }

    if(g_register_always_ask.app_id >= ALWAYS_ASK_MAX_APP_ID_SIZE)
    {
        /*check app id*/
        g_register_always_ask.app_id = 1;
        while(1)
        {
            if(always_ask_register_app_check_id(g_register_always_ask.app_id))
            {
                g_register_always_ask.app_id++;
            }
            else
            {
                break;
            }
        }
        
        return g_register_always_ask.app_id;
    }
    else
    {
        return g_register_always_ask.app_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  always_ask_deregister_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_deregister_app_id (kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(app_id == 0)
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    /* take sem */
    kal_take_sem( g_register_always_ask.always_ask_sem_id, KAL_INFINITE_WAIT );

    if(!always_ask_register_app_check_id(app_id))
    {
        /* release sem */
        kal_give_sem( g_register_always_ask.always_ask_sem_id );
        return KAL_FALSE;
    }

    /* delete app registe primitive in cbm */
    result = always_ask_register_app_chain_del(app_id);

    /* release sem */
    kal_give_sem( g_register_always_ask.always_ask_sem_id );

    if(result)
    {
        return KAL_TRUE;
    }
    
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  always_ask_register_acct_select_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_register_acct_select_notify(kal_uint8 app_id, always_ask_register_type_enum register_type, kal_uint32 mod_id, FuncPtrAccountSelectExt callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ always ask register app_id = %d, register_type = %d, callback = %d $$$$$", 
                       app_id, register_type, callback);
    
    if((app_id == 0))
    {
        ASSERT(0);
        return KAL_FALSE;
    }
    
    /* take sem */
    kal_take_sem( g_register_always_ask.always_ask_sem_id, KAL_INFINITE_WAIT );

    if(!always_ask_register_app_check_id(app_id))
    {
        /* release sem */
        kal_give_sem( g_register_always_ask.always_ask_sem_id );
        return KAL_FALSE;
    }

    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if((g_cbm_always_ask[i].valid) && (g_cbm_always_ask[i].app_id == app_id))
        {
            if(register_type == REGISTER_TYPE_CALLBACK)
            {
                g_cbm_always_ask[i].always_ask_callback = callback;
                g_cbm_always_ask[i].mod_id = 0;
            }
            else if(register_type == REGISTER_TYPE_PRIMITIVE)
            {
                g_cbm_always_ask[i].always_ask_callback = NULL;
                g_cbm_always_ask[i].mod_id = mod_id;
            }
            else
            {
                /* release sem */
                kal_give_sem( g_register_always_ask.always_ask_sem_id );
                return KAL_FALSE;
            }

            /* release sem */
            kal_give_sem( g_register_always_ask.always_ask_sem_id );
            return KAL_TRUE;
        }
    }

    /* release sem */
    kal_give_sem( g_register_always_ask.always_ask_sem_id );

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  always_ask_deregister_acct_select_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool always_ask_deregister_acct_select_notify(kal_uint8 app_id, always_ask_register_type_enum register_type, kal_uint32 mod_id, FuncPtrAccountSelectExt callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("$$$$$ CBM always ask deregister app_id = %d$$$$$", app_id);
    
    if(app_id == 0)
    {
        ASSERT(0);
        return KAL_FALSE;
    }
    
    /* take sem */
    kal_take_sem( g_register_always_ask.always_ask_sem_id, KAL_INFINITE_WAIT );

    if(!always_ask_register_app_check_id(app_id))
    {
        /* release sem */
        kal_give_sem( g_register_always_ask.always_ask_sem_id );
        return KAL_FALSE;
    }

    for(i = 0; i < ALWAYS_ASK_MAX_APP_NUM; i++)
    {
        if((g_cbm_always_ask[i].valid) && (g_cbm_always_ask[i].app_id == app_id))
        {
            if(register_type == REGISTER_TYPE_CALLBACK)
            {
                g_cbm_always_ask[i].always_ask_callback = NULL;
            }
            else if(register_type == REGISTER_TYPE_PRIMITIVE)
            {
                g_cbm_always_ask[i].mod_id = 0;
            }
            else
            {
                /* release sem */
                kal_give_sem( g_register_always_ask.always_ask_sem_id );
                return KAL_FALSE;
            }
            
            /* release sem */
            kal_give_sem( g_register_always_ask.always_ask_sem_id );
            return KAL_TRUE;
        }
    }

    /* release sem */
    kal_give_sem( g_register_always_ask.always_ask_sem_id );

    return KAL_FALSE;
}

//#endif /* __CBM_ALWAYS_ASK_FEATURE__ */