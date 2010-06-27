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
 *  UCMUtil.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template source file
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_UCM__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "gpioInc.h"
#include "mdi_audio.h"
#include "PhoneBookGprot.h"
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#include "SettingGprots.h"
#include "SimDetectionGprot.h"
#include "app_datetime.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif /* __DRM_SUPPORT__ */

#include "UCMResDef.h"
#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"

extern void SSCHandleIMEI(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_outgoing_group
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  call_type       [IN]            Call type 
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  Number of outgoing group that is in the given call type.
 *****************************************************************************/
S32 mmi_ucm_get_outgoing_group(mmi_ucm_call_type_enum call_type, mmi_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_OUTGOING_STATE))
        {
            index_list[numTotal].group_index = i;
            numTotal++;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_incoming_group
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  call_type       [IN]            Call type 
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  Number of incoming group that is in the given call type.
 *****************************************************************************/
S32 mmi_ucm_get_incoming_group(mmi_ucm_call_type_enum call_type, mmi_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_INCOMING_STATE))
        {
            index_list[numTotal].group_index = i;
            numTotal++;
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_active_group
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  call_type       [IN]            Call type 
 *  single_only     [IN]            Single call or don't care
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  Number of active group that is in the given call type.
 *****************************************************************************/
S32 mmi_ucm_get_active_group(mmi_ucm_call_type_enum call_type, MMI_BOOL single_only, mmi_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_ACTIVE_STATE))
        {
            if (single_only == TRUE)
            {
                if (g_ucm_p->call_list.group_info[i].num_call == 1)
                {
                    index_list[numTotal].group_index = i;
                    numTotal++;
                }
            }
            else
            {
                index_list[numTotal].group_index = i;
                numTotal++;
            }
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_held_group
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  call_type       [IN]            Call type 
 *  single_only     [IN]            Single call or don't care
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  Number of held group that is in the given call type.
 *****************************************************************************/
S32 mmi_ucm_get_held_group(mmi_ucm_call_type_enum call_type, MMI_BOOL single_only, mmi_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((g_ucm_p->call_list.group_info[i].call_type & call_type) && 
            (g_ucm_p->call_list.group_info[i].call_state == MMI_UCM_HOLD_STATE))
        {
            if (single_only == TRUE)
            {
                if (g_ucm_p->call_list.group_info[i].num_call == 1)
                {
                    index_list[numTotal].group_index = i;
                    numTotal++;
                }
            }
            else
            {
                index_list[numTotal].group_index = i;
                numTotal++;
            }
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_group_index_by_call_state
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  None.
 * RETURNS
 *  Group index or -1 if call with the specified state does not exist.
 *****************************************************************************/
S32 mmi_ucm_get_group_index_by_call_state(mmi_ucm_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_state == call_state)
        {
            PRINT_INFORMATION("\n[mmi_ucm_get_group_index_by_call_state] state = %d index = %d\n", call_state, i);
            return i;
        }
    }
    
    PRINT_INFORMATION("\n[mmi_ucm_get_group_index_by_call_state] state = %d NO call found \n",call_state);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_group_index_by_call_state_and_type
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  None.
 * RETURNS
 *  Group index or -1 if call with the specified state does not exist.
 *****************************************************************************/
S32 mmi_ucm_get_group_index_by_call_state_and_type(mmi_ucm_call_state_enum call_state, mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].call_state == call_state && 
            (g_ucm_p->call_list.group_info[i].call_type & call_type))
        {
            PRINT_INFORMATION("\n[mmi_ucm_get_group_index_by_call_state_and_type] state = %d type = %d index = %d\n", call_state, call_type, i);
            return i;
        }
    }
    
    PRINT_INFORMATION("\n[mmi_ucm_get_group_index_by_call_state_and_type] state = %d type = %d NO call found \n",call_state, call_type);
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_index_by_id
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  None.
 * RETURNS
 *  TRUE means the call is fould. Otherwise return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_ucm_get_index_by_id(mmi_ucm_id_info_struct* uid_info, mmi_ucm_index_info_struct* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(index, 0, sizeof(mmi_ucm_index_info_struct));
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if (g_ucm_p->call_list.group_info[i].group_id == uid_info->group_id)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call ; j++)
            {
                if (g_ucm_p->call_list.group_info[i].call_info[j].call_id == uid_info->call_id)
                {
                    index->group_index = i;
                    index->call_index = j;
                    
                    PRINT_INFORMATION("\n[mmi_ucm_get_index_by_id] group_index = %d call_index = %d\n", i, j);
                    return MMI_TRUE;                    
                }
            }
        }
    }
    
    PRINT_INFORMATION("\n[mmi_ucm_get_index_by_id] NO call found \n");
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_busy
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means UCM is busy; FALSE means UCM is not busy.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
        (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
        (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) != 0) || 
        (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0) || 
        (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0) || 
        (mmi_ucm_emergency_call_present() == TRUE))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_crss
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the given number is call related supplementary service; 
 *  FALSE means the given number is not call related supplementary service.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_crss(mmi_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 num_buf = num_uri;
    S32 buf_len;
    pBOOL valid_crss = FALSE;
    pBOOL success = FALSE;
    S32 group_index = 0;
    S32 call_index = 0;
    S32 call_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("****Checking For UCM CRSS****");

    if(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) == 0)
    {
        return MMI_FALSE;
    }

    /* second digit must be NULL, *, or 0~9 */
    if ((*(num_buf + 1) == 0) || (*(num_buf + 1) == '*') || ((*(num_buf + 1) >= '0') && (*(num_buf + 1) <= '9')))
    {
        valid_crss = TRUE;
    }

    if (valid_crss== TRUE)
    {
        switch (*num_buf)
        {
            case '0':
                if ('\0' == *(num_buf + 1))
                {
                    /* 0 send */
                    if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)!= 0)
                    {
                        /* incoming call present => reject waiting call */
                        if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) > 1)
                        {
                            for(group_index = 0; group_index < g_ucm_p->call_list.num_group; group_index++)
                            {
                                for(call_index = 0; call_index < g_ucm_p->call_list.group_info[group_index].num_call ; call_index++)
                                {
                                    if(g_ucm_p->call_list.group_info[group_index].call_state == MMI_UCM_INCOMING_STATE)
                                    {
                                        PRINT_INFORMATION("\n *** operation:0,Reject Waiting Call\n");
                                        mmi_ucm_end_single_action_with_index(group_index, call_index);
                                        return TRUE;     
                                    }
                                }
                            }
                        }
                        else
                        {
                            valid_crss = TRUE;
                            break;
                        }
                    }
                    else
                    {
                        /* no incoming call, drop held call */
                        for(group_index = 0; group_index < g_ucm_p->call_list.num_group; group_index++)
                        {
                            /*end held conf.*/
                            if((g_ucm_p->call_list.group_info[group_index].call_state == MMI_UCM_HOLD_STATE) &&
                               (mmi_ucm_end_conference_check(group_index) == MMI_TRUE))
                            {
                                PRINT_INFORMATION("\n *** operation:0,Hanging Up All Held\n");
                                mmi_ucm_end_conference_action_with_index(group_index);
                                success = TRUE;
                            }
                            /*end single held call*/
                            else if((g_ucm_p->call_list.group_info[group_index].call_state == MMI_UCM_HOLD_STATE))
                            {
                                PRINT_INFORMATION("\n *** operation:0,Hanging Up Single Held\n");
                                mmi_ucm_end_single_action_with_index(group_index, 0);
                                success = TRUE;
                            }
                        }     
                        if(success == TRUE)
                        {
                            return TRUE;
                        }
                        else
                        {
                            valid_crss = TRUE;
                            break;
                        }
                    }
                }
                valid_crss = FALSE;
                break;
                
            case '1':
                if ('\0' == *(num_buf + 1))
                {
                    /* 1 send */
                    if(mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) != 0 &&
                       mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0 &&
                       mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0 &&
                       mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 0)
                    {
                        if(g_ucm_p->call_list.group_info[0].num_call == 1)
                        {
                            PRINT_INFORMATION("\n *** operation:1,End Single Active call\n");
                            mmi_ucm_end_single_action_with_index(0, 0);
                            return TRUE;
                        }
                        else
                        {
                            PRINT_INFORMATION("\n *** operation:1,End Active conference call\n");
                            mmi_ucm_end_conference_action_with_index(0);
                            return TRUE;
                        }
                    }
                    
                    if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)!= 0)
                    {
                        if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL) == 1)
                        {
                            valid_crss = TRUE;
                            break;
                        }
                        else
                        {
                            if (mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) != 0)
                            {
                            	PRINT_INFORMATION("\n *** operation:1,End Active and accept incoming call\n");
                                mmi_ucm_end_active_and_accept_action();
                                return TRUE;
                            }
                            else
                            {
                                valid_crss = TRUE;
                                break;
                            }
                        }
                    }
                    else if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) > 0)
                    {
                        valid_crss = TRUE;
                        break;
                    }
                    else
                    {
                        if (mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) > 0 && mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) > 0)
                        {
                            /*The hilighted tab must be held state*/
                            if(g_ucm_p->call_list.group_info[g_ucm_p->call_misc.hilite_tab].call_state == MMI_UCM_HOLD_STATE)
                            {
                            	PRINT_INFORMATION("\n *** operation:1,End Active and retrieve highlighted held\n");
                                mmi_ucm_end_active_and_retrieve_action();
                                return TRUE;
                            }
                            else if(mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) == 1)
                            {
                                PRINT_INFORMATION("\n *** operation:1,End Active and retrieve held\n");
                                mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
                                mmi_ucm_end_active_and_retrieve_action_with_index(g_ucm_p->call_misc.index_list[0].group_index);
                                return TRUE;
                            }
                            else
                            {
                                valid_crss = TRUE;
                                break;
                            }
                        }
                        else if(mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) > 0)
                        {
                            /*The hilighted tab must be held state*/
                            if(g_ucm_p->call_list.group_info[g_ucm_p->call_misc.hilite_tab].call_state == MMI_UCM_HOLD_STATE)
                            {
                            	PRINT_INFORMATION("\n *** operation:1,Retrieve highlighted held\n");
                                mmi_ucm_retrieve_action();
                                return TRUE;
                            }
                            else if(mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) == 1)
                            {
                                PRINT_INFORMATION("\n *** operation:1,Retrieve held\n");
                                mmi_ucm_get_held_group(MMI_UCM_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list);
                                mmi_ucm_retrieve_action_with_index(g_ucm_p->call_misc.index_list[0].group_index);
                                return TRUE;
                            }
                            else
                            {
                                valid_crss = TRUE;
                                break;
                            }
                        }
                        else
                        {
                            valid_crss = TRUE;
                            break;
                        }
                    }
                }
                else if ('\0' == *(num_buf + 2))
                {
                    /* 1X send */

                    call_id = (S32) atoi((void*)(num_buf + 1));

                    if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) > 0)
                    {
                        valid_crss = TRUE;
                        break;
                    }

                    for(group_index = 0; group_index < g_ucm_p->call_list.num_group; group_index++)
                    {
                        for(call_index = 0; call_index < g_ucm_p->call_list.group_info[group_index].num_call ; call_index++)
                        {
                            if((g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_id == call_id) &&
                               (g_ucm_p->call_list.group_info[group_index].call_state == MMI_UCM_ACTIVE_STATE))
                            {
                                PRINT_INFORMATION("\n *** operation:1X,Hanging Up Active call: group_index:%d, call_index:%d, call_id:%d \n",group_index, call_index, call_id);
                                mmi_ucm_end_single_action_with_index(group_index, call_index);
                                success = TRUE;
                            }
                        }
                    }
                    if(success == TRUE)
                    {
                        return TRUE;
                    }
                    else
                    {
                        valid_crss = TRUE;
                        break;
                    }
                }
                valid_crss = FALSE;
                break;
    
            case '2':
                if ('\0' == *(num_buf + 1))
                {
                    /* 2 send */
                    if (mmi_ucm_app_total_call(MMI_UCM_DATA_CALL_TYPE_ALL)!= 0)
                    {
                        valid_crss = TRUE;
                        break;
                    }
                    if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)!= 0)
                    {
                        if(mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) != 0 &&
                           mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) != 0)
                        {
                            valid_crss = TRUE;
                            break;
                        }
                        else if(mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) != 0 &&
                                mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) == 0)
                        {

                        #ifdef __CTM_SUPPORT__   
                            if(mmi_gsm_ctm_is_connected() == TRUE)
                            {
                                PRINT_INFORMATION("\n *** operation:2, End CTM Active Call and Accept Incoming Call \n");
                                /* drop ctm call before answering the waiting call*/
                                mmi_ucm_end_active_and_accept_action();
                            }
                            else
                       #endif /* __CTM_SUPPORT__ */
                            {
                                PRINT_INFORMATION("\n *** operation:2, Hold Active Call and Accept Incoming Call \n");
                                mmi_ucm_hold_and_accept_action();
                            }
                            return TRUE;
                        }
                        else
                        {
                            PRINT_INFORMATION("\n *** operation:2, Accept Incoming Call \n");
                            mmi_ucm_accept_action();
                            return TRUE;
                        }
                    }
                    else if (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 0)
                    {
                        valid_crss = TRUE;
                        break;
                    }
                    
                    /*only allow to swap in active call screen*/
                    if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0 &&
                        mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)== 0 &&
                        mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) != 0 &&
                        mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) != 0)
                    {
                        PRINT_INFORMATION("\n *** operation:2, Swap Calls \n");
                        mmi_ucm_swap_action();
                        return TRUE;
                    }
                    else if(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0 &&
                            mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)== 0 &&
                            mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) != 0 &&
                            mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) == 0)
                    {
                        PRINT_INFORMATION("\n *** operation:2, Hold Active Calls \n");
                        mmi_ucm_hold_action();
                        return TRUE;
                    }
                    else if(mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 0 &&
                            mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)== 0 &&
                            mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) == 0 &&
                            mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) != 0)
                    {
                        PRINT_INFORMATION("\n *** operation:2, Retrieve Held Calls \n");
                        mmi_ucm_retrieve_action();
                        return TRUE;
                    }
                    else
                    {
                        valid_crss = TRUE;
                        break;
                    }
                    return TRUE;
                }
                else if ('\0' == *(num_buf + 2))
                {
                    /* 2X send */
                    call_id = (S8) atoi((void*)(num_buf + 1));

                    if ((call_id == 0) ||
                        (mmi_ucm_get_outgoing_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) > 0) ||
                        (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) > 0))
                    {
                        valid_crss = TRUE;
                        break;
                    }

                    for(group_index = 0; group_index < g_ucm_p->call_list.num_group; group_index++)
                    {
                        for(call_index = 0; call_index < g_ucm_p->call_list.group_info[group_index].num_call ; call_index++)
                        {
                            /* check if it is active call, only active call can be splited*/
                            if((g_ucm_p->call_list.group_info[group_index].call_info[call_index].call_id == call_id) &&
                               (g_ucm_p->call_list.group_info[group_index].num_call > 1) &&
                               (g_ucm_p->call_list.group_info[group_index].call_state == MMI_UCM_ACTIVE_STATE))
                            {
                                PRINT_INFORMATION("\n *** operation:2X, Split Calls: group_index:%d, call_index:%d, call_id:%d \n",group_index, call_index, call_id);
                                mmi_ucm_split_action_with_index(group_index, call_index);
                                success = TRUE;   
                            }
                        }
                    }
                    if(success == TRUE)
                    {
                        return TRUE;
                    }
                    else
                    {
                        valid_crss = TRUE;
                        break;
                    }
                }
                valid_crss = FALSE;
                break;
                
            case '3':
                if ('\0' == *(num_buf + 1))
                {
                    /* 3 send */
                    if ((mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_ALL) > 0) &&
                        (mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_ALL) > 0))
                    {
                        PRINT_INFORMATION("\n *** operation:3,Conferencing Call \n");
                        mmi_ucm_conference_action();
                        return TRUE;
                    }
                    else
                    {
                        valid_crss = TRUE;
                        break;
                    }
                }
                valid_crss = FALSE;
                break;
                
            case '4':
                if ('*' == *(num_buf + 1))
                {
                    /* 4* send */
                    if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)!= 0)
                    {
                        buf_len = strlen((PS8) num_buf);
                        if (num_buf[buf_len - 1] >= '0' && num_buf[buf_len - 1] <= '9')
                        {
                            PRINT_INFORMATION("\n *** operation:4*number,Call Deflection\n");
                            mmi_ucm_deflect_action_with_number((PU8)(num_buf + 2));
                            return TRUE;
                        }
                    }
                    else
                    {
                        valid_crss = FALSE;
                        break;
                    }
                }
                else if ('\0' == *(num_buf + 1))
                {
                    /* 4 send */
                    if(mmi_ucm_transfer_option())                       
                    {
                        PRINT_INFORMATION("\n *** operation:4,Explicit Call Transfer\n");
                        mmi_ucm_explict_call_transfer_action();
                        return TRUE;
                    }
                    else
                    {
                        valid_crss = TRUE;
                        break;
                    }
                }
                valid_crss = FALSE;
                break;
                
            case '5':
                if ('\0' == *(num_buf + 1))
                {
                    /* 5 send */
                    PRINT_INFORMATION("\n *** operation:5,Activate CCBS\n");
                }
                valid_crss = FALSE;
                break;

            default:
                valid_crss = FALSE;
                break;
        }
    }

    if ((mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL)== 1) &&
        (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list)!= 0))
    {
        PRINT_INFORMATION("\n *** Accept Incoming Call \n");
        mmi_ucm_accept_action();
        return TRUE;

    }
    else if (valid_crss == TRUE)
    {
        PRINT_INFORMATION("\n Not a valid action\n");
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return TRUE;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_sos_number
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means the given number is a sos number; 
 *  FALSE means the given number is not a sos number.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_sos_number(mmi_ucm_call_type_enum call_type, U8 *num_uri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeNum = OslMalloc(MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(unicodeNum, 0, MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((S8*)unicodeNum, (S8*)num_uri, MMI_UCM_MAX_NUM_URI_LEN);

    if (call_type & (MMI_UCM_SIM1_CALL_TYPE_ALL | MMI_UCM_VIDEO_CALL_TYPE))
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (CheckValidEmergencyNo1((S8*)unicodeNum, SIM1) == TRUE)
    #else /* __MMI_DUAL_SIM_MASTER__ */
        if (CheckValidEmergencyNo1((S8*)unicodeNum) == TRUE)
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            OslMfree(unicodeNum);
            return TRUE;
        }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
    {
        if (CheckValidEmergencyNo1((S8*)unicodeNum, SIM2) == TRUE)
        {
            OslMfree(unicodeNum);
            return TRUE;
        }
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VOIP__
    if (call_type & MMI_UCM_VOIP_CALL_TYPE)
    {
        if (mmi_voip_is_sos_number(unicodeNum) == TRUE)
        {
            OslMfree(unicodeNum);
            return TRUE;
        }
    }
#endif /* __MMI_VOIP__ */
    OslMfree(unicodeNum);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_sos_in_call_list
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means sos number is in the call list; 
 *  FALSE means sos number is not in the call list.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_sos_in_call_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    MMI_BOOL result = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
        {
            result = mmi_ucm_is_sos_number(g_ucm_p->call_list.group_info[i].call_type, g_ucm_p->call_list.group_info[i].call_info[j].remote_info.num_uri);
            if (result == TRUE)
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_sos_wait_dial
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means sos number is going to be dialed; 
 *  FALSE means sos number is .
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_sos_wait_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_ucm_p->mo_info.is_wait_dial == TRUE) && (mmi_ucm_is_sos_number(g_ucm_p->mo_info.dial_type, g_ucm_p->mo_info.dial_num.num_uri) == TRUE))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_emergency_call_present
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means emergency number exists; FALSE means emergency number not exists.
 *****************************************************************************/
MMI_BOOL mmi_ucm_emergency_call_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_is_sos_in_call_list() == TRUE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_emergency_call_present] Emergency Number is in Call List\n");
        return TRUE;
    }
    else if (mmi_ucm_is_sos_wait_dial() == TRUE)
    {
        PRINT_INFORMATION("\n[mmi_ucm_emergency_call_present] Emergency Number is Waiting to Dial\n");
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_process_state
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  proc_state      [IN]            Process state
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  Number of calls that is in the given process state.
 *****************************************************************************/
S32 mmi_ucm_get_process_state(mmi_ucm_process_state_enum proc_state, mmi_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
        {
            if (g_ucm_p->call_list.group_info[i].call_info[j].proc_state == proc_state)
            {
                index_list[numTotal].group_index = i;
                index_list[numTotal].call_index = j;
                numTotal++;
            }
        }
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_process_state
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  group_index     [IN]            Group index
 *  call_index      [IN]            Call index
 *  old_state       [IN]            Old process state
 *  new_state       [IN]            New process state
 * RETURNS
 *  Number of calls that is changed its process state.
 *****************************************************************************/
S32 mmi_ucm_set_process_state(S32 group_index, S32 call_index, mmi_ucm_process_state_enum old_state, mmi_ucm_process_state_enum new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, numTotal = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((group_index == -1) && (call_index == -1))
    {
        for (i = 0; i < g_ucm_p->call_list.num_group; i++)
        {
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                if (g_ucm_p->call_list.group_info[i].call_info[j].proc_state == old_state)
                {
                    g_ucm_p->call_list.group_info[i].call_info[j].proc_state = new_state;
                    numTotal++;
                }
            }
        }
    }
    else if ((group_index != -1) && (call_index == -1))
    {
        for (i = 0; i < g_ucm_p->call_list.group_info[group_index].num_call; i++)
        {
            if (g_ucm_p->call_list.group_info[group_index].call_info[i].proc_state == old_state)
            {
                g_ucm_p->call_list.group_info[group_index].call_info[i].proc_state = new_state;
                numTotal++;
            }
        }
    }
    else if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].proc_state == old_state)
    {
        g_ucm_p->call_list.group_info[group_index].call_info[call_index].proc_state = new_state;
        numTotal = 1;
    }
    else
    {
        MMI_ASSERT(0); /* old state mismatch */
    }
    return numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_act_rsp_string_id
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  action          [IN]            UCM current action
 * RETURNS
 *  Corresponding string id.
 *****************************************************************************/
U16 mmi_ucm_get_act_rsp_string_id(mmi_ucm_act_opcode_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case MMI_UCM_HOLD:
            return STR_ID_UCM_CALL_HOLD;
        case MMI_UCM_RETRIEVE:
        case MMI_UCM_END_ACTIVE_AND_RETRIEVE:
            return STR_ID_UCM_CALL_RETRIEVE;
        case MMI_UCM_SWAP:
            return STR_ID_UCM_CALL_SWAP;
        case MMI_UCM_CONFERENCE:
            return STR_ID_UCM_CALL_CONFERENCE;
        case MMI_UCM_SPLIT:
            return STR_ID_UCM_CALL_SPLIT;
        case MMI_UCM_DEFLECT:
            return STR_ID_UCM_DEFLECT;
        case MMI_UCM_TRANSFER:
        case MMI_UCM_EXPLICT_CALL_TRANSFER:
            return STR_ID_UCM_TRANSFER;
        default:
            return STR_ID_UCM_CALL_END;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_search_call_list
 * DESCRIPTION
 *  Your description
 * PARAMETERS 
 *  call_list       [IN]            Application call list
 *  index_list      [IN/OUT]        Index list that matches the condition
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_search_call_list(mmi_ucm_call_info_struct call_list, mmi_ucm_index_info_struct *index_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_ucm_p->call_list.num_group; i++)
    {
        if ((call_list.uid_info.call_type == g_ucm_p->call_list.group_info[i].call_type) && 
            (call_list.uid_info.group_id == g_ucm_p->call_list.group_info[i].group_id))
        {
            index_list->group_index = i;
            for (j = 0; j < g_ucm_p->call_list.group_info[i].num_call; j++)
            {
                if (call_list.uid_info.call_id == g_ucm_p->call_list.group_info[i].call_info[j].call_id)
                {
                    index_list->call_index = j;
                    return; /* group index, call index are found */
                }
            }
            return; /* group index is found */
        }
    }
    return; /* not found */
}


#ifdef __BT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sync_call_state_to_headset
 * DESCRIPTION
 *  Sync call state to bluetooth handfree profile with the order 
 *  1. call 
 *  2. call setup
 *  3. call held 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_sync_call_state_to_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_call_type_enum syncCalltype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_DUAL_SIM_MASTER__
	syncCalltype = MMI_UCM_VOICE_CALL_TYPE | MMI_UCM_VOICE_CALL_TYPE_SIM2;
#else /* __MMI_DUAL_SIM_MASTER__ */
    syncCalltype = MMI_UCM_VOICE_CALL_TYPE;
#endif /* __MMI_DUAL_SIM_MASTER__ */

	PRINT_INFORMATION("\nmmi_ucm_sync_call_state_to_headset syncCalltype=%d\n",syncCalltype);
    if (mmi_ucm_get_active_group(syncCalltype, FALSE, g_ucm_p->call_misc.index_list))
    {
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALL, RMMI_CIND_CC_ACTIVE);
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALL, RMMI_CIND_CC_ACTIVE);
    #endif

        if (mmi_ucm_get_outgoing_group(syncCalltype, g_ucm_p->call_misc.index_list))
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
        #endif
        }
        else if (mmi_ucm_get_incoming_group(syncCalltype, g_ucm_p->call_misc.index_list))
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
        #endif
        }
        else
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
        #endif
        }
        
        if (mmi_ucm_get_held_group(syncCalltype, FALSE, g_ucm_p->call_misc.index_list))
        {
            /* active call + held call */
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_ACTIVE_HOLD);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_ACTIVE_HOLD);
        #endif
        }
        else
        {
            /* only active call */
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_NONE);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_NONE);
        #endif
        }
    }
    else if (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list))
    {
        /* for the sake of supporting BT headset before version 1.5 */
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALL, RMMI_CIND_CC_ACTIVE);
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALL, RMMI_CIND_CC_ACTIVE);
    #endif

        if (mmi_ucm_get_outgoing_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
        #endif
        }
        else if (mmi_ucm_get_incoming_group(MMI_UCM_VOICE_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list))
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
        #endif
        }
        else
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
        #endif
        }
        
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_HOLD);
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_HOLD);
    #endif
    }
    else
    {
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALL, RMMI_CIND_CC_NONE);
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
        mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALL, RMMI_CIND_CC_NONE);
    #endif

        if (mmi_ucm_get_outgoing_group(syncCalltype, g_ucm_p->call_misc.index_list))
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_OUTGOING);
        #endif
        }
        else if (mmi_ucm_get_incoming_group(syncCalltype, g_ucm_p->call_misc.index_list))
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_INCOMING);
        #endif
        }
        else
        {
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_NONE);
        #endif
        }
        
        if (mmi_ucm_get_held_group(syncCalltype, FALSE, g_ucm_p->call_misc.index_list))
        {
            /* only held call */
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_HOLD);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_HOLD);
        #endif
        }
        else
        {
            /* no active call + no held call */
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_NONE);
        #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
            mmi_ucm_bt_handfree_ciev_req(MMI_UCM_FROM_L4C_SIM2, RMMI_CIND_CALLHELD, RMMI_CIND_HELD_NONE);
        #endif
        }
    }
}
#endif /* __BT_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_inband_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_inband_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioPlayToneWithCallBack(TONE_RINGING_CALL_GSM, GetRingTypeEnum(), INCOMING_CALL_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_inband_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_inband_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AudioStopReq(TONE_RINGING_CALL_GSM);
}

#if 1
//Huyanwei Add It 
int PlayIncomingtone = 0 ;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_incoming_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 groupIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_play_incoming_tone] Play Tone State: %d, Total Group: %d\n", g_ucm_p->call_misc.play_tone, g_ucm_p->call_list.num_group);

    #if 1
	//Huyanwei Add It For init It
      PlayIncomingtone = 0  ;
    #endif

    if (g_ucm_p->call_misc.play_tone == MMI_UCM_NONE)
    {
    
    #ifdef __MMI_SIDEKEY_SUPPRESS_RING__
        if (g_ucm_p->call_misc.is_ringtone_suppress == MMI_TRUE)
        {
            return;
        }
    #endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */    

        if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == g_ucm_p->call_list.num_group)
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_RING_TONE;
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            
            if (g_ucm_p->call_list.group_info[groupIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL) 
            {
                mmi_ucm_at_general_req(MMI_UCM_FROM_L4C, RMMI_UCM_RCODE_RING, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                mmi_ucm_at_general_req(MMI_UCM_FROM_L4C_SIM2, RMMI_UCM_RCODE_RING, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
            #endif
            }
            mmi_ucm_play_ringtone();
        }
        else
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_WAITING_TONE;
            mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            
            if (g_ucm_p->call_list.group_info[groupIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL)
            {
                if ((mmi_ucm_get_active_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 0) && 
                    (mmi_ucm_get_held_group(MMI_UCM_VOICE_CALL_TYPE_ALL, FALSE, g_ucm_p->call_misc.index_list) == 0))
                {
                    mmi_ucm_at_general_req(MMI_UCM_FROM_L4C, RMMI_UCM_RCODE_RING, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
                #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                    mmi_ucm_at_general_req(MMI_UCM_FROM_L4C_SIM2, RMMI_UCM_RCODE_RING, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
                #endif
                }
                else
                {
                    mmi_ucm_at_general_req(MMI_UCM_FROM_L4C, RMMI_UCM_RCODE_CCWA, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
                #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                    mmi_ucm_at_general_req(MMI_UCM_FROM_L4C_SIM2, RMMI_UCM_RCODE_CCWA, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
                #endif
                }
            }
            mmi_ucm_play_waitingtone();
        }
    }
    else if (g_ucm_p->call_misc.play_tone == MMI_UCM_WAITING_TONE)
    {
        if (mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == g_ucm_p->call_list.num_group)
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_RING_TONE;
            groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
            
            if (g_ucm_p->call_list.group_info[groupIndex].call_type & MMI_UCM_VOICE_CALL_TYPE_ALL)
            {
                mmi_ucm_at_general_req(MMI_UCM_FROM_L4C, RMMI_UCM_RCODE_RING, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
            #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
                mmi_ucm_at_general_req(MMI_UCM_FROM_L4C_SIM2, RMMI_UCM_RCODE_RING, g_ucm_p->call_list.group_info[groupIndex].call_info[0].call_id, &g_ucm_p->call_misc.l4c_info);
            #endif
            }
            mmi_ucm_play_ringtone();
        }
        else
        {
            /* do not replay waitingtone */
        }
    }
    else /* g_ucm_p->call_misc.play_tone == MMI_UCM_RING_TONE */
    {
        /* do not replay ringtone */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_incoming_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_caller_image_info_struct *imagePtr = OslMalloc(sizeof(mmi_phb_caller_image_info_struct));

    #if 1
	//Huyanwei Add It 
	PlayIncomingtone = 0 ;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_stop_incoming_tone] Reset Play Tone State\n");
    
    memset(imagePtr, 0, sizeof(mmi_phb_caller_image_info_struct));
    mmi_phb_get_caller_image_info(&g_ucm_p->mo_mt_display.image_info, imagePtr);
    g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
    mmi_ucm_stop_ringtone();
    mmi_ucm_stop_waitingtone();
    if ((mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == g_ucm_p->call_list.num_group) && 
        (imagePtr->image_type != WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID) && (imagePtr->image_type != WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE))
    {
        StopCategory17Video();
    }
    OslMfree(imagePtr);
    
#ifdef __MMI_SIDEKEY_SUPPRESS_RING__
    g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */
}


#ifdef __MMI_SIDEKEY_SUPPRESS_RING__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_suppress_incoming_tone
 * DESCRIPTION
 *  Suppress incoming tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_suppress_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_caller_image_info_struct *imagePtr = OslMalloc(sizeof(mmi_phb_caller_image_info_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_suppress_incoming_tone] \n");

    memset(imagePtr, 0, sizeof(mmi_phb_caller_image_info_struct));
    mmi_phb_get_caller_image_info(&g_ucm_p->mo_mt_display.image_info, imagePtr);
    g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
    g_ucm_p->call_misc.is_ringtone_suppress = MMI_TRUE;

    switch (g_ucm_p->mo_mt_display.alert_type)
    {            
        case MMI_RING:
        case MMI_VIBRATION_AND_RING:
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;

        case MMI_VIBRATION_THEN_RING:
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
            
        case MMI_SILENT:
        case MMI_ALERT_NONE:
        case MMI_VIBRATION_ONLY:
            break;
            
        default: /* set default as MMI_RING */
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
    }
    
    if ((mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == g_ucm_p->call_list.num_group) && 
        (imagePtr->image_type != WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID) && (imagePtr->image_type != WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE))
    {
        StopCategory17Video();
    }
    OslMfree(imagePtr);
}
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 

#ifdef __MMI_CONNECT_NOTICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_connect_notice
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_connect_notice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (GetConnectNoticeType())
    {
        case MMI_NOTICE_NONE:
            break;
        case MMI_NOTICE_TONE_ONLY:
            playRequestedTone(CONNECT_TONE);
            break;
        case MMI_NOTICE_VIB_ONLY:
            PlayVibratorOnce();
            break;
        case MMI_NOTICE_TONE_AND_VIB:
            playRequestedTone(CONNECT_TONE);
            PlayVibratorOnce();
            break;
    }
}
#endif /* __MMI_CONNECT_NOTICE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_ring_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_video_sound = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_video_sound = mmi_ucm_is_caller_video_sound(&g_ucm_p->mo_mt_display.image_info);
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n Huyanwe debug is_video_sound= %d\r\n",is_video_sound);
#endif
    switch (g_ucm_p->mo_mt_display.alert_type)
    {
        case MMI_RING:
		#if 1
		 //Huyanwei Add It 
		PlayIncomingtone = 0 ;			
		#endif			
            if (is_video_sound == MMI_FALSE)
            {
                mmi_ucm_play_tone_with_text();
		  #if 1
		  //Huyanwei Add It 
		     PlayIncomingtone = 1 ;			
		  #endif				
            }
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\n Huyanwei debug : MMI_RING File : %s , Line:%d\r\n",__FILE__,__LINE__);
#endif
            break;
        case MMI_VIBRATION_ONLY:
		#if 1
		//Huyanwei Add It 
	       PlayIncomingtone = 0 ;			
		#endif
            VibratorOn();
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\n Huyanwei debug : MMI_VIBRATION_ONLY File : %s , Line:%d\r\n",__FILE__,__LINE__);		
#endif
            break;
        case MMI_VIBRATION_AND_RING:
		#if 1
		//Huyanwei Add It 
	       PlayIncomingtone = 0 ;			
		#endif			
            VibratorOn();
            if (is_video_sound == MMI_FALSE)
            {
                mmi_ucm_play_tone_with_text();
		  #if 1
		  //Huyanwei Add It 
		  PlayIncomingtone = 1 ;			
		  #endif
            }
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\n Huyanwei debug : MMI_VIBRATION_AND_RING File : %s , Line:%d\r\n",__FILE__,__LINE__);				
#endif
            break;
        case MMI_VIBRATION_THEN_RING:
		#if 1
		 //Huyanwei Add It 
	        PlayIncomingtone = 0 ;			
		#endif
            VibratorOn();
            StartTimer(CM_ALERT_NOTIFYDURATION_TIMER, VIB_THEN_RING_DURATION, mmi_ucm_play_tone_after_vibration);
#if defined(NOKE_DEBUG)
	     noke_dbg_printf("\r\n Huyanwei debug : MMI_VIBRATION_THEN_RING File : %s , Line:%d\r\n",__FILE__,__LINE__);				
#endif
            break;
        case MMI_SILENT:
        case MMI_ALERT_NONE:
		#if 1
		//Huyanwei Add It 
	       PlayIncomingtone = 0 ;			
		#endif									
#if defined(NOKE_DEBUG)
	       noke_dbg_printf("\r\n Huyanwei debug : MMI_SILENT File : %s , Line:%d\r\n",__FILE__,__LINE__);				
#endif
            break;
        default: /* set default as MMI_RING */
		#if 1
		//Huyanwei Add It 
		       PlayIncomingtone = 0 ;			
		#endif						
	               mmi_ucm_play_tone_with_text();
	       #if 1
		//Huyanwei Add It 
	       	PlayIncomingtone = 1 ;			
	       #endif
#if defined(NOKE_DEBUG)
	       noke_dbg_printf("\r\n Huyanwei debug : default  File : %s , Line:%d\r\n",__FILE__,__LINE__);			   
#endif
            break;
    }
    PlayPatternCallerGroup(g_ucm_p->mo_mt_display.light_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_ring_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     #if 1
     //Huyanwei Add It 
     PlayIncomingtone = 0 ;			
     #endif
    switch (g_ucm_p->mo_mt_display.alert_type)
    {
        case MMI_RING:
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
        case MMI_VIBRATION_ONLY:
            VibratorOff();
            break;
        case MMI_VIBRATION_AND_RING:
            VibratorOff();
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
        case MMI_VIBRATION_THEN_RING:
            /* NSC Does not make the mobile go back into Silent Mode */
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            VibratorOff();
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
        case MMI_SILENT:
        case MMI_ALERT_NONE:
            break;
        default: /* set default as MMI_RING */
            if (g_ucm_p->mo_mt_display.tone_id < MAX_TONE_ID)
            {
                AudioStopReq(g_ucm_p->mo_mt_display.tone_id);
            }
            else
            {
                mdi_audio_stop_all();
            }
            break;
    }
    StopPatternCallerGroup(g_ucm_p->mo_mt_display.light_id);
}


#if defined(G_SENSOR_SUPPORT)
// Huyanwei Add it 
int GSensor_GetRingToneCase(void)
{
	if(   /*  ( ( g_ucm_p->mo_mt_display.alert_type == MMI_VIBRATION_THEN_RING) || ( g_ucm_p->mo_mt_display.alert_type == MMI_VIBRATION_AND_RING) ) && */(GetRingTypeEnum() == 2))
		return 1;
	else
		return 0;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_with_text
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_tone_with_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
    U8 *speechText = NULL;
    S32 groupIndex = 0;
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
    if (GetIntelligentCallAert() == MMI_INTELLIGENT_CALL_ALERT_ON)
    {
        speechText = OslMalloc(MAX_PB_NAME_LENGTH + MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
        mmi_ucm_get_incoming_group(MMI_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
        groupIndex = g_ucm_p->call_misc.index_list[0].group_index;
        memset(speechText, 0, (MAX_PB_NAME_LENGTH + MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH));
    #if defined (SIMPLE_TTS) || defined (DIGIT_TONE_SUPPORT)
        mmi_asc_n_to_ucs2(
            (S8*)speechText, 
            (S8*)g_ucm_p->call_list.group_info[groupIndex].call_info[0].remote_info.num_uri, 
            strlen((S8*)g_ucm_p->call_list.group_info[groupIndex].call_info[0].remote_info.num_uri));
        mmi_ucs2ncat(
            (S8*)speechText, 
            (S8*)g_ucm_p->call_list.group_info[groupIndex].call_info[0].remote_info.disp_name, 
            mmi_ucs2strlen((S8*)g_ucm_p->call_list.group_info[groupIndex].call_info[0].remote_info.log_name));
    #endif /* defined (SIMPLE_TTS) || defined (DIGIT_TONE_SUPPORT) */
        if (mmi_ucs2strlen((S8*)speechText) > 0)
        {
            mdi_audio_play_text_with_vol_path(
                speechText, 
                mmi_ucs2strlen((S8*)speechText), 
                100, 
                NULL, 
                mmi_ucm_play_tone_with_text_callback, 
                GetRingVolumeLevel(),
                MDI_DEVICE_SPEAKER_BOTH);
        }
        else
        {
            AudioPlayToneWithCallBack(g_ucm_p->mo_mt_display.tone_id, GetRingTypeEnum(), INCOMING_CALL_TONE);
        }
        OslMfree(speechText);
    }
    else       
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */
    {
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\r\n Huyanwei Debug mmi_ucm_play_tone_with_text() =>AudioPlayToneWithCallBack()  \r\n");
#endif
        AudioPlayToneWithCallBack(g_ucm_p->mo_mt_display.tone_id, GetRingTypeEnum(), INCOMING_CALL_TONE);
    }
}


#ifdef __MMI_INTELLIGENT_CALL_ALERT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_with_text_callback
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  result          [IN]            Play text result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_tone_with_text_callback(mdi_result result)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MDI_AUDIO_END_OF_FILE)
    {
        AudioPlayToneWithCallBack(g_ucm_p->mo_mt_display.tone_id, GetRingTypeEnum(), INCOMING_CALL_TONE);
    }
}
#endif /* __MMI_INTELLIGENT_CALL_ALERT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_after_vibration
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_tone_after_vibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_video_sound = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_video_sound = mmi_ucm_is_caller_video_sound(&g_ucm_p->mo_mt_display.image_info);
    
    StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
    VibratorOff();

    if (is_video_sound)
    {
        /* turn on audio path */
        EnableCategory17Audio();
        g_ucm_p->call_misc.is_ring_after_vibra = TRUE;
    }
    else
    {
        mmi_ucm_play_tone_with_text();
    }
	
   #if 1
   //Huyanwei Add It For Play Tone
   PlayIncomingtone = 1 ;			
   #endif
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_waiting_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_waitingtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     #if 1
     //Huyanwei Add It 
     PlayIncomingtone = 0 ;			
     #endif		 
    AudioPlayToneWithCallBack(TONE_CALL_WAITING, GetRingTypeEnum(), INCOMING_CALL_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_waiting_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_waitingtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 1
    //Huyanwei Add It 
    PlayIncomingtone = 0 ;			
   #endif
    AudioStopReq(TONE_CALL_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_ssc_parse
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_ssc_parse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 stringIMEI[20];
    S8 newstringIMEI[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy((S8*) stringIMEI, "*#06#");
    mmi_asc_to_ucs2((PS8) newstringIMEI, (PS8) stringIMEI);

    if (mmi_ucs2cmp((S8*) newstringIMEI, (S8*) g_ucm_p->call_misc.disp_dtmf) == 0)
    {
        SSCHandleIMEI();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voip_call_from_incall_dialer
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voip_call_from_incall_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_app_make_call(MMI_UCM_VOIP_CALL_TYPE, g_ucm_p->mo_info.dial_pad_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_ucm_make_voice_call_from_incall_dialer]\n");

#ifdef __MMI_DUAL_SIM_MASTER__
    switch (MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL))
    {
	case MTPNP_AD_CHANNEL_SLAVE:
	case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
		mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE_SIM2, (U8*) g_ucm_p->mo_info.dial_pad_buffer);
		break ;
	case MTPNP_AD_CHANNEL_MASTER:
	case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*) g_ucm_p->mo_info.dial_pad_buffer);
		break;
     }
	return;
#else  /* __MMI_DUAL_SIM_MASTER__ */
    mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, g_ucm_p->mo_info.dial_pad_buffer);
#endif  /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION("\n[mmi_ucm_make_voice_call_from_dtmf_editor]\n");
#ifdef __MMI_DUAL_SIM_MASTER__
    switch (MTPNP_AD_Get_Channel(MTPNP_AD_CALL_CHANNEL))
    {
	case MTPNP_AD_CHANNEL_SLAVE:
	case MTPNP_AD_CHANNEL_DEFAULT_SLAVE:
		mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE_SIM2, (U8*) g_ucm_p->call_misc.disp_dtmf);
		break ;
	case MTPNP_AD_CHANNEL_MASTER:
	case MTPNP_AD_CHANNEL_DEFAULT_MASTER:
		mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*) g_ucm_p->call_misc.disp_dtmf);
		break;
     }
	return;
#else  /* __MMI_DUAL_SIM_MASTER__ */
    mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*) g_ucm_p->call_misc.disp_dtmf);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#if ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) )
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadCallHandler(NULL);
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif /* ( (defined  __MMI_WGUI_CSK_ENABLE__) && defined (__MMI_TOUCH_SCREEN__) ) */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_time_reminder
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_time_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION("\n[mmi_ucm_call_time_reminder]\n");

    status = GetCtrStatus();
    
    if(status == CTR_OFF)
    {
        return;
    }

    if (mmi_ucm_app_active_call(MMI_UCM_CALL_TYPE_NO_CSD) > 0 ||
        mmi_ucm_app_held_call(MMI_UCM_CALL_TYPE_NO_CSD) > 0)
    {
        playRequestedTone(CALL_REMINDER_TONE);

        if (status == CTR_PERIODIC)
        {
            StartTimer(CM_CTR_TIMER, (1000 * GetCtrTime()), mmi_ucm_call_time_reminder);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_check_gsm_number
 * DESCRIPTION
 *  Validation check before dial GSM call
 * PARAMETERS
 *  strNumber       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL mmi_ucm_check_gsm_number(S8 *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (strNumber[pos] != '\0')
    {
        if((strNumber[pos] == '+') ||
           (strNumber[pos] == '*') ||
           (strNumber[pos] == '#') ||
           (strNumber[pos] == 'p') ||
           (strNumber[pos] == 'w') ||
           ((strNumber[pos] >= '0') && (strNumber[pos] <= '9')))
        {
            pos += 2;
        }
        else
        {
            return MMI_FALSE;
        }        
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_check_if_scr_older
 * DESCRIPTION
 *  Check if the screen is older than the base screen in history
 * PARAMETERS
 *  U16 check_scr screen to be checked
 *  U16 base_scr base screen
 * RETURNS
 *  True means the check_scr is older than the base screen in history.
 *  False means the check_scr is newer, it is not in history, or base_scr is not in history
 *****************************************************************************/
MMI_BOOL mmi_ucm_check_if_scr_older(U16 check_scr, U16 base_scr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr = base_scr;
    U16 pre_scr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsScreenPresent(check_scr))
    {
        return MMI_FALSE;
    }

    if (!IsScreenPresent(base_scr))
    {
        return MMI_FALSE;
    }

    while (GetPreviousScrnIdOf(cur_scr, &pre_scr))
    {
        if (pre_scr == check_scr)
        {
            return MMI_TRUE;
        }

        cur_scr = pre_scr;
        pre_scr = 0;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_phb_call_type
 * DESCRIPTION
 *  get phonebook call type enum
 * PARAMETERS
 *  mmi_ucm_call_type_enum ucm_call_type
 * RETURNS
 *  mmi_phb_call_type_enum
 *****************************************************************************/
U32 mmi_ucm_get_phb_call_type(mmi_ucm_call_type_enum ucm_call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 phb_call_type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (ucm_call_type)
    {
        case MMI_UCM_DATA_CALL_TYPE:
        case MMI_UCM_CSD_CALL_TYPE:
        case MMI_UCM_DATA_CALL_TYPE_SIM2:
        case MMI_UCM_CSD_CALL_TYPE_SIM2:
        {
            phb_call_type = (U32)MMI_PHB_DATA_CALL_TYPE;
        }
        break;

        case MMI_UCM_VOIP_CALL_TYPE:
        {
            phb_call_type = (U32)MMI_PHB_VOIP_CALL_TYPE;
        }
        break;

        case MMI_UCM_VIDEO_CALL_TYPE:
        {
            phb_call_type = (U32)MMI_PHB_VIDEO_CALL_TYPE;
        }
        break;   

        case MMI_UCM_VOICE_CALL_TYPE:
        case MMI_UCM_VOICE_CALL_TYPE_SIM2:
        default:
        {
            phb_call_type = (U32)MMI_PHB_VOICE_CALL_TYPE;
        }
        break;
    }

    return phb_call_type;
}

#ifdef __MMI_SIDEKEY_SUPPRESS_RING__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_side_key_after_suppress_ring
 * DESCRIPTION
 *  Set key handler for side key in its first press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_side_key_after_suppress_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    
#ifdef __MMI_CLAMSHELL__
    SetKeyHandler(mmi_ucm_incoming_call_sendkey, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_ucm_incoming_call_endkey, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#else /* __MMI_CLAMSHELL__ */
    SetKeyHandler(MMI_dummy_function, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(MMI_dummy_function, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __MMI_CLAMSHELL__ */
}
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_channel
 * DESCRIPTION
 *  set call channel for dual SIM mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_call_channel(mmi_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (call_type & MMI_UCM_SIM2_CALL_TYPE_ALL)
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_SLAVE);
    }
    else
    {
        MTPNP_AD_Set_Channel(MTPNP_AD_CALL_CHANNEL, MTPNP_AD_CHANNEL_DEFAULT_MASTER);
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_sendkey_hdlr
 * DESCRIPTION
 *  set sendkey handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_sendkey_hdlr(FuncPtr sendkey_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.sendkey_hdlr = sendkey_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_sendkey_hdlr
 * DESCRIPTION
 *  get sendkey handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr mmi_ucm_get_sendkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->call_misc.sendkey_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_sendkey_hdlr
 * DESCRIPTION
 *  get sendkey handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_sendkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.sendkey_hdlr != NULL)
    {
        g_ucm_p->call_misc.sendkey_hdlr();
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_centerkey_hdlr
 * DESCRIPTION
 *  set center key handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_centerkey_hdlr(FuncPtr centerkey_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.centerkey_hdlr = centerkey_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_centerkey_hdlr
 * DESCRIPTION
 *  get center key handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr mmi_ucm_get_centerkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->call_misc.centerkey_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_centerkey_hdlr
 * DESCRIPTION
 *  get center handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_centerkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.centerkey_hdlr != NULL)
    {
        g_ucm_p->call_misc.centerkey_hdlr();
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_error_tone
 * DESCRIPTION
 *  Get error tone id 
 * PARAMETERS
 *  void
 * RETURNS
 *  error tone id 
 *****************************************************************************/
U8 mmi_ucm_get_error_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) > 0)
    {
        tone_id = ERROR_TONE_IN_CALL;
    }
    else
    {
        tone_id = ERROR_TONE;
    }

    return tone_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_file_valid
 * DESCRIPTION
 *  Check if file is valid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_file_valid(U16* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)file_path))
    {
        fh = FS_Open((U16*) file_path, FS_READ_ONLY);
        
        if (fh > FS_NO_ERROR)
        {
            FS_Close(fh);
            
        #ifdef __DRM_SUPPORT__
            if(DRM_validate_permission(NULL, (PU16)file_path, DRM_PERMISSION_PLAY) == TRUE)
        #endif /* __DRM_SUPPORT__ */
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_caller_video_sound
 * DESCRIPTION
 *  Check if caller video sould should be played
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_caller_video_sound(void* image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_caller_image_info_struct *imagePtr = OslMalloc(sizeof(mmi_phb_caller_image_info_struct));
    mmi_phb_caller_image_input_struct *image_info = (mmi_phb_caller_image_input_struct*)image;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(imagePtr, 0, sizeof(mmi_phb_caller_image_info_struct));
    mmi_phb_get_caller_image_info(image_info, imagePtr);

    switch (imagePtr->image_type)
    {
        case WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID:
        case WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE:
        {

        }
        break;

        case WGUI_CATE_MOMT_RES_TYPE_VIDEO_ID:
        case WGUI_CATE_MOMT_RES_TYPE_SWFLASH_ID:
        case WGUI_CATE_MOMT_RES_TYPE_AVATAR_FILE:
        {
            if (imagePtr->is_video_sound == MMI_TRUE)
            {
                result = MMI_TRUE;
            } 
        }
        break;


        case WGUI_CATE_MOMT_RES_TYPE_VIDEO_FILE:
        case WGUI_CATE_MOMT_RES_TYPE_SWFLASH_FILE:
        {
            if (imagePtr->is_video_sound == MMI_TRUE)
            {
                if (mmi_ucm_is_file_valid((U16*)imagePtr->image_path) == MMI_TRUE)
                {
                    result = MMI_TRUE;
                }
            } 
        }
        break;

        default:
            MMI_ASSERT(0);
    
    }

    OslMfree(imagePtr);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_pending_action
 * DESCRIPTION
 *  Check if pending action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_pending_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((mmi_ucm_get_process_state(MMI_UCM_WAIT_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_process_state(MMI_UCM_DO_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0) && 
        (mmi_ucm_get_process_state(MMI_UCM_COMP_PROCESS_STATE, g_ucm_p->call_misc.index_list) == 0))
    {
        result = MMI_FALSE;
    }
    else
    {
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_validate_start_time
 * DESCRIPTION
 *  Validate start time of calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_validate_start_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 group_index = 0;
    U32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_index = 0; group_index < g_ucm_p->call_list.num_group; group_index++)
    {
        for (call_index = 0; call_index < g_ucm_p->call_list.group_info[group_index].num_call; call_index++)
        {
            if (!mmi_dt_is_valid(&g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time))
            {
                DTGetRTCTime(&g_ucm_p->call_list.group_info[group_index].call_info[call_index].start_time);   

                /* do not log call history for SAT call */
                if (g_ucm_p->call_list.group_info[group_index].call_info[call_index].module_id != MMI_UCM_FROM_SAT)
                {
                    mmi_ucm_log_call_history(group_index, call_index, TRUE);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_call_index_by_call_id
 * DESCRIPTION
 *  Get call index of the call list by call id
 * PARAMETERS
 *  void
 * RETURNS
 *  call index of the call list.
 *  -1 means the call is not found.
 *****************************************************************************/
S32 mmi_ucm_get_call_index_by_call_id(mmi_ucm_call_entry_struct *call_list, U8 call_list_size, U8 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_index = -1;
    U8 call_list_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (call_list_index = 0; call_list_index <= call_list_size; call_list_index++)
    {
        if (call_list[call_list_index].call_id == call_id)
        {
            call_index = call_list_index;
            break;
        }
    }

    return call_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_nw_service_status
 * DESCRIPTION
 *  get network service status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ucm_nw_status_enum mmi_ucm_get_nw_service_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    PRINT_INFORMATION("\n[mmi_ucm_get_nw_service_status] nw_service_status: %d \n", g_ucm_p->call_misc.nw_service_status);

    return g_ucm_p->call_misc.nw_service_status;
}


#endif /* __MMI_UCM__ */

