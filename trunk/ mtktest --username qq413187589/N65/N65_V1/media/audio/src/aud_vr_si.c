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
 *   aud_vr_si.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SI VR  module functions 
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

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_VRSI_MOD__

extern aud_vrsi_context_struct vrsi_ctx;

#define MED_AUD_VRSI_STATE_IDLE  0x1
#define MED_AUD_VRSI_STATE_READY  0x2
#define MED_AUD_VRSI_STATE_PROCESS  0x4

// aud_vr_si.c 
// sub-flow or step-flow  


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_callback(VRSI_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_process_ind(MOD_MED, vrsi_ctx.session_id, (kal_uint8) event);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_prompt_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_prompt_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRSI_MMI_Confirmed();
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VRSI_ErrMsg errMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    errMsg = VRSI_GetErrMsg();

    switch (errMsg)
    {
            /* for return value : fail */
        case VRSI_ERR_NO:
            return MED_RES_VRSI_OK;
        case VRSI_ERR_UNINITIALIZED:
            return MED_RES_VRSI_ERR_UNINITIALIZED;
        case VRSI_ERR_BUSY:
            return MED_RES_VRSI_ERR_BUSY;
        case VRSI_ERR_INSUFFICIENT_MEM:
            return MED_RES_VRSI_ERR_MEM_INSUFFICIENT;
        case VRSI_ERR_DB_FULL:
        case VRSI_ERR_DB_ERROR:
            return MED_RES_VRSI_ERR_DATA_ERROR;
        case VRSI_ERR_LIBRARY_CORRUPT:
            return MED_RES_VRSI_ERR_LIBRARY_CORRUPT;
        case VRSI_ERR_BAD_GRAMMAR:
            return MED_RES_VRSI_ERR_BAD_GRAMMAR;
        case VRSI_ERR_LANG_NOT_SUPPORT:
            return MED_RES_VRSI_ERR_LANG_NOT_SUPPORT;
        case VRSI_ERR_NO_MATCH_TAG:
            return MED_RES_VRSI_ERR_NO_MATCH_TAG;
        case VRSI_ERR_TTS_TOO_LONG:
            return MED_RES_VRSI_ERR_TTS_TOO_LONG;
            /* for error event */
        case VRSI_ERR_NO_SOUND:
            return MED_RES_VRSI_ERR_NO_SOUND;
        case VRSI_ERR_TRAIN_TAG_FAIL:
            return MED_RES_VRSI_ERR_CMD_TRN_FAIL;
        case VRSI_ERR_RECOG_FAIL:
            return MED_RES_VRSI_ERR_CMD_RCG_FAIL;
        case VRSI_ERR_DIGIT_RECOG_FAIL:
            return MED_RES_VRSI_ERR_DGT_RCG_FAIL;
        case VRSI_ERR_DIGIT_ADAPT_FAIL:
            return MED_RES_VRSI_ERR_DGT_ADP_FAIL;
        default:
            return MED_RES_VRSI_ERR_UNKNOWN;
    }
}

#define MAX_VRSI_FIXED_TAGS 100
#define MAX_VRSI_DYNAMIC_TAGS 500
#define MAX_VRSI_SD_TAGS 20

/* initialization */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 bufLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_IDLE)
    {
        ASSERT(KAL_FALSE);
    }

    VRSI_Init(aud_vrsi_callback);

    bufLen = VRSI_GetMemRequest(MAX_VRSI_FIXED_TAGS, MAX_VRSI_DYNAMIC_TAGS, MAX_VRSI_SD_TAGS);
    if ((vrsi_ctx.buffer = (kal_uint8*) med_alloc_ext_mem(bufLen)) == NULL)
    {
        VRSI_Close();
        return MED_RES_VRSI_ERR_MEM_INSUFFICIENT;
    }

    if(VRSI_SetMem(vrsi_ctx.buffer,
                   bufLen,
                   MAX_VRSI_FIXED_TAGS,
                   MAX_VRSI_DYNAMIC_TAGS,
                   MAX_VRSI_SD_TAGS,
                   vrsi_ctx.db_path )== VRSI_FAIL)
    {
        VRSI_Close();
        med_free_ext_mem((void **)&vrsi_ctx.buffer);
        return MED_RES_VRSI_ERR_DATA_ERROR;
    }

    vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;

    return MED_RES_OK;
}

/* VRSI functinos */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_add_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_add_tags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Add_Tags(vrsi_ctx.grammar, &vrsi_ctx.addtags_param) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }

    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_compare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p1      [?]     
 *  p2      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool aud_vrsi_compare(kal_uint16 *p1, kal_uint16 *p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*p1 != '\0')
    {
        if (*p1++ != *p2++)
        {
            return KAL_FALSE;
        }
    }

    /* *p1 == '\0' */
    if (*p1 == *p2)
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
 *  aud_vrsi_save_addtags_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_save_addtags_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i, j, k;
    VRSI_AddTags_Result *addtags_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRSI_ReadResult((void **)&addtags_result);

    k = 0;
    for (i = 0; i < addtags_result->numTag; i++)
    {
        for (j = k; j < vrsi_ctx.addtags_param.numTag; j++)
        {
            k++;
            if (aud_vrsi_compare(addtags_result->ppTagName[i], vrsi_ctx.addtags_param.ppTagName[j]))
            {
                vrsi_ctx.id_list[j] = addtags_result->pTagID[i];
                break;
            }
            else
            {
                vrsi_ctx.id_list[j] = 65535;
            }
        }
    }
    for (j = k; j < vrsi_ctx.addtags_param.numTag; j++)
    {
        vrsi_ctx.id_list[j] = 65535;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_start_cmd_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_start_cmd_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Recog(vrsi_ctx.grammar) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }
    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_start_cmd_trn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_start_cmd_trn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Train_Tag(vrsi_ctx.grammar, &vrsi_ctx.tag_param) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }
    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_start_digit_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [IN]        
 *  limit       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_start_digit_rcg(kal_uint8 lang, kal_uint16 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Digit_Recog(lang, limit) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }
    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_start_digit_adapt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_start_digit_adapt(kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Digit_Adapt(lang) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }
    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}

/* play */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_play_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tag_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_play_tag(kal_uint16 tag_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Play_Tag(vrsi_ctx.grammar, tag_id, MEDIA_VMP_AS_RINGTONE) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }
    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_play_tts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_play_tts(kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_TTS_Play(lang, (kal_uint16*) vrsi_ctx.pmp_text) == VRSI_FAIL)
    {
        vrsi_ctx.session_on = KAL_FALSE;
        return aud_vrsi_error();
    }
    vrsi_ctx.state = MED_AUD_VRSI_STATE_PROCESS;
    return MED_RES_OK;
}

/* database management */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_get_tagnum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tagNum      [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_get_tagnum(kal_int32 *tagNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Gram_GetTagNum(vrsi_ctx.grammar, tagNum) == VRSI_FAIL)
    {
        *tagNum = 0;
        return aud_vrsi_error();
    }
    return MED_RES_VRSI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_get_tag_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tagNum          [IN]        
 *  pTagID          [IN]        
 *  ppTagName       [IN]        
 *  pTagLong        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_get_tag_info(
            kal_int32 tagNum,
            const kal_uint16 *pTagID,
            kal_uint16 **ppTagName,
            kal_int32 *pTagLong)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_ReadTags(vrsi_ctx.grammar, tagNum, pTagID, ppTagName, pTagLong) == VRSI_FAIL)
    {
        return aud_vrsi_error();
    }

    return MED_RES_VRSI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_del_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tagNum      [IN]        
 *  pTagID      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_del_tags(kal_int32 tagNum, const kal_uint16 *pTagID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 delTagNum;
    kal_uint16 *pDelTagID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    pDelTagID = (kal_uint16*) get_ctrl_buffer(tagNum * 2);

    if (VRSI_DeleteTags(vrsi_ctx.grammar, tagNum, pTagID, &delTagNum, pDelTagID) == VRSI_FAIL)
    {
        free_ctrl_buffer(pDelTagID);
        return aud_vrsi_error();
    }
    free_ctrl_buffer(pDelTagID);    /* check if MMI need successfully-deleted-tag information */
    return MED_RES_VRSI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_reset_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_reset_tags(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Gram_DeleteAllTags(vrsi_ctx.grammar) == VRSI_FAIL)
    {
        return aud_vrsi_error();
    }

    return MED_RES_VRSI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_sync_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tag_num         [IN]        
 *  id_list         [?]         
 *  name_list       [IN]        
 *  sync_flag       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_sync_db(kal_uint32 tag_num, kal_uint16 *id_list, kal_uint16 **name_list, kal_uint8 *sync_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 db_tag_num, tmp, i, j, k, del_num;
    kal_uint16 *p_db_tag_id, *p_del_tag, *p_name;
    kal_uint16 sync_id, db_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Gram_GetTagNum(vrsi_ctx.grammar, &db_tag_num) == VRSI_FAIL)
      return aud_vrsi_error();              
      
    if(db_tag_num == 0)
    {
        for(i = 0 ; i < tag_num ; i ++)
            sync_flag[i] = 0; 
        return MED_RES_VRSI_OK;      
    }
   
    p_db_tag_id = (kal_uint16*) get_ctrl_buffer(db_tag_num << 1);
    p_del_tag = (kal_uint16*) get_ctrl_buffer(db_tag_num << 1);
    p_name = (kal_uint16*) get_ctrl_buffer(32); /* need to make sure this value OK */

    VRSI_Gram_ReadTagIDs(vrsi_ctx.grammar, p_db_tag_id, db_tag_num << 1, &tmp);

    if (db_tag_num != tmp)
    {
        free_ctrl_buffer(p_db_tag_id);
        free_ctrl_buffer(p_del_tag);
        free_ctrl_buffer(p_name);
        return MED_RES_VRSI_ERR_DATA_ERROR;
    }

    /* ask MMI to pass data by incremental tag_id */
    k = 0;
    del_num = 0;

    for (i = 0; i < tag_num; i++)
    {
        sync_id = id_list[i];

        for (j = k; j < db_tag_num; j++)
        {
            db_id = p_db_tag_id[j];

            if (sync_id == db_id)
            {
                k++;
                VRSI_ReadTags(vrsi_ctx.grammar, 1, &db_id, &p_name, &tmp);
                if (aud_vrsi_compare(name_list[i], p_name))
                {
                    sync_flag[i] = 1;
                    break;
                }
                else
                {
                    sync_flag[i] = 0;
                    p_del_tag[del_num++] = db_id;
                    break;
                }
            }
            else if (sync_id > db_id)
            {
                k++;
                p_del_tag[del_num++] = db_id;
            }
            else
            {
                sync_flag[i] = 0;
                break;
            }
        }

        if (k == db_tag_num && sync_id != db_id)
        {
            sync_flag[i] = 0;
        }
    }

    for (j = k; j < db_tag_num; j++)
    {
        db_id = p_db_tag_id[j];
        p_del_tag[del_num++] = db_id;
    }

    if (del_num != 0)
    {
        aud_vrsi_del_tags(del_num, p_del_tag);
    }

    free_ctrl_buffer(p_db_tag_id);
    free_ctrl_buffer(p_del_tag);
    free_ctrl_buffer(p_name);
    return MED_RES_VRSI_OK;

}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_sync_db_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tag_num         [IN]        
 *  id_list         [?]         
 *  sync_flag       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_vrsi_sync_db_by_id(kal_uint32 tag_num, kal_uint16 *id_list, kal_uint8 *sync_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 db_tag_num, tmp, i, j, del_num;
    kal_uint16 *p_db_tag_id, *p_del_tag;
    kal_uint16 sync_count, db_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    if (VRSI_Gram_GetTagNum(vrsi_ctx.grammar, &db_tag_num) == VRSI_FAIL)
      return aud_vrsi_error();              

    if(db_tag_num == 0)
    {
        for(i = 0 ; i < tag_num ; i ++)
            sync_flag[i] = 0; 
        return MED_RES_VRSI_OK;      
    }

    p_db_tag_id = (kal_uint16*) get_ctrl_buffer(db_tag_num << 1);
    p_del_tag = (kal_uint16*) get_ctrl_buffer(db_tag_num << 1);

    VRSI_Gram_ReadTagIDs(vrsi_ctx.grammar, p_db_tag_id, db_tag_num << 1, &tmp);

    if (db_tag_num != tmp)
    {
        free_ctrl_buffer(p_db_tag_id);
        free_ctrl_buffer(p_del_tag);
        return MED_RES_VRSI_ERR_DATA_ERROR;
    }

    del_num = 0;
    sync_count = 0;

    for (i = 0; i < tag_num; i++)
    {
        sync_flag[i] = 0;
    }

    for (i = 0; i < db_tag_num; i++)
    {
        db_id = p_db_tag_id[i];

        if (sync_count != tag_num)
        {
            for (j = 0; j < tag_num; j++)
            {
                if (db_id == id_list[j])
                {
                    break;
                }
            }

            if (j == tag_num)   /* not found */
            {
                p_del_tag[del_num++] = db_id;
            }
            else
            {
                sync_flag[j] = 1;
                sync_count++;
            }
        }
        else
        {
            p_del_tag[del_num++] = db_id;
        }
    }

    if (del_num != 0)
    {
        aud_vrsi_del_tags(del_num, p_del_tag);
    }

    free_ctrl_buffer(p_db_tag_id);
    free_ctrl_buffer(p_del_tag);
    return MED_RES_VRSI_OK;
}

/* termination */


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state == MED_AUD_VRSI_STATE_IDLE)
    {
        ASSERT(KAL_FALSE);
    }

    VRSI_Stop();

    vrsi_ctx.state = MED_AUD_VRSI_STATE_READY;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vrsi_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vrsi_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vrsi_ctx.state != MED_AUD_VRSI_STATE_READY)
    {
        ASSERT(KAL_FALSE);
    }

    VRSI_Close();
    /* return allocated memory */
    med_free_ext_mem((void **)&vrsi_ctx.buffer);

    vrsi_ctx.state = MED_AUD_VRSI_STATE_IDLE;
}

#endif /* __MED_VRSI_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

