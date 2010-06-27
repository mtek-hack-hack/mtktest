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
 * mmi_imps_ps_pa.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements all protocol presence related function/interface for IMPS application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_IMPS__
/*  Include: MMI header file */

#include "CommonScreens.h"


#include "IMPSResDef.h"
#include "mmi_imps_prot.h"
#include "Mmi_imps_gprot.h"

#include "wap_ps_struct.h"
#include "FileManagerGProt.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif
/* ... Add More MMI header */

/*  Include: PS header file */
/* ... Add More PS header */

typedef struct
{
    U8 ref_count;
    U16 msg_len;
} imps_local_para_hdr;

/***************************************************************************** 
* Define
*****************************************************************************/
#define IMPS_MEMSET(addr, value, structure) memset(((U8*)addr)+sizeof(imps_local_para_hdr), value, (S32)(sizeof(structure) - sizeof(imps_local_para_hdr)))
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_init_ps_pa_hdlr
 * DESCRIPTION
 *  Initialize all protocol presence event handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_init_ps_pa_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetProtocolEventHandler(mmi_imps_ps_get_contact_list_rsp, MSG_ID_MMI_IMPS_GET_CONTACT_LIST_RSP);
    SetProtocolEventHandler(mmi_imps_ps_view_contact_list_rsp, MSG_ID_MMI_IMPS_VIEW_CONTACT_LIST_RSP);
    SetProtocolEventHandler(mmi_imps_abort_get_pa_rsp, MSG_ID_MMI_IMPS_ABORT_GET_PA_RSP);
    SetProtocolEventHandler(mmi_imps_ps_pa_notify_ind, MSG_ID_MMI_IMPS_PA_NOTIFY_IND);
    
    SetProtocolEventHandler(mmi_imps_ps_update_pa_rsp, MSG_ID_MMI_IMPS_UPDATE_PA_RSP);
    SetProtocolEventHandler(mmi_imps_ps_get_watch_list_rsp, MSG_ID_MMI_IMPS_GET_WATCHER_LIST_RSP);
    SetProtocolEventHandler(mmi_imps_ps_abort_get_watch_list_rsp, MSG_ID_MMI_IMPS_ABORT_GET_WATCHER_LIST_RSP);    
    SetProtocolEventHandler(mmi_imps_ps_del_contact_list_rsp, MSG_ID_MMI_IMPS_DEL_CONTACT_LIST_RSP);
    SetProtocolEventHandler(mmi_imps_ps_get_block_list_rsp, MSG_ID_MMI_IMPS_GET_BLOCK_LIST_RSP);
    SetProtocolEventHandler(mmi_imps_ps_add_contact_list_rsp, MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_RSP);
        
    SetProtocolEventHandler(mmi_imps_ps_pa_auth_ind, MSG_ID_MMI_IMPS_PA_AUTH_IND);    
}


#define CONT_PS_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_contact_list_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_CONTACT_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_contact_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_CONTACT_LIST_REQ, NULL, NULL);

    /* restore current action -- won't store state for background update */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_contact_list_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_GET_CONTACT_LIST_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_contact_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_contact_list_rsp_struct *rsp = (mmi_imps_get_contact_list_rsp_struct*) msg;
    imps_entity_struct *entity = NULL;
    S16 *ucs2_folder = NULL;
    FS_HANDLE fileHandle = 0;
    U32 len;
    S32 result;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        if (rsp->contact_list_id_list.entity_num > 0 || rsp->default_contact_list_id_p)
		{
			S32 i = 0, l = 0, j = 0, k = 0;
			S32 ps_count, local_count;
			S32 new_ids[IMPS_MAX_NO_GROUP];

			memset(&new_ids, 0, sizeof(new_ids));

			/* default contact list */
			ps_count = (S32) rsp->contact_list_id_list.entity_num;

			if (ps_count > IMPS_MAX_NO_GROUP)
			{
				ps_count = IMPS_MAX_NO_GROUP;
			}

			local_count = (S32) imps_p->group_info.no_group;

			if (rsp->default_contact_list_id_p)
			{
				/* check if the default contact list is on server */
				for (i = 0; i < local_count; i++)
				{
					if (mmi_imps_util_is_id_same
						((S8*) rsp->default_contact_list_id, (S8*) imps_p->group_info.group_list[i].group_id))
					{
						imps_p->group_info.group_list[i].is_sync = TRUE;
						break;
					}
				}

				/* default contact list presently is not in global context */
				if (i == local_count && l < IMPS_MAX_NO_GROUP)
				{
					/* store it in the new_id list, make it equal to ps_count to distinguish with others */
					new_ids[l++] = ps_count;
				}
			}


			entity = OslMalloc(sizeof(imps_entity_struct));
			ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);  
			mmi_imps_util_get_filename_from_fileindex(rsp->contact_list_id_list.entity_list_file_index, IMPS_LIST_FILE_CONTACT_LIST_ID, (S8*) ucs2_folder);
			fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);        
			/* sync group id with contact list Update contact list info if it's not sync */
			/* from PS to local part, find out new group ids */
			if (fileHandle > 0)
			{
				for (j = 0; j < ps_count; j++)
				{
					result = FS_Read(fileHandle, (void*)entity, sizeof(imps_entity_struct), &len);
					if (result == FS_NO_ERROR)
					{
						for (k = 0; k < local_count; k++)
						{
							/* mark is_retrieve to TRUE to mean the group is retrieved and is still stored on server */
							if (imps_p->group_info.group_list[k].is_sync == FALSE)
							{
								if (mmi_imps_util_is_id_same
									((S8*) imps_p->group_info.group_list[k].group_id,
									 (S8*) entity->id))
								{
									imps_p->group_info.group_list[k].is_sync = TRUE;
									break;
								}
							}
						}
					}

					/* only allow IMPS_MAX_NO_GROUP of groups */
					if (l < IMPS_MAX_NO_GROUP && k == local_count)
					{
						new_ids[l++] = j;
					}
				}
			}

			/* removed dangling ids */
			for (k = (local_count - 1); k >= 0; k--)
			{
				if (imps_p->group_info.group_list[k].is_sync == FALSE)
				{
					if (k < (local_count - 1))
					{
						memcpy(
							&imps_p->group_info.group_list[k],
							&imps_p->group_info.group_list[k + 1],
							(local_count - k - 1) * sizeof(mmi_imps_group_struct));
					}
					local_count--;
					memset(&imps_p->group_info.group_list[local_count], 0, sizeof(mmi_imps_group_struct));
				}
			}

			/* fill the new id list into group list if there are still some empty slots */
			for (k = 0; (k < l && local_count < IMPS_MAX_NO_GROUP); k++, local_count++)
			{
				if (new_ids[k] == ps_count) /* it's the default contact list */
				{
					strcpy((S8*) imps_p->group_info.group_list[local_count].group_id, (S8*) rsp->default_contact_list_id);
				}
				else
				{
					if (fileHandle > 0)
					{
						FS_Seek(fileHandle, new_ids[k] * sizeof(imps_entity_struct), FS_FILE_BEGIN);
						result = FS_Read(fileHandle, (void*)entity, sizeof(imps_entity_struct), &len);
						strcpy(
							(S8*) imps_p->group_info.group_list[local_count].group_id,
							(S8*) entity->id);
					}
				}

				imps_p->group_info.group_list[local_count].is_sync = TRUE;
			}

			FS_Close(fileHandle);
			FS_Delete((U16*) ucs2_folder);
			OslMfree(ucs2_folder);
			OslMfree(entity);

			imps_p->group_info.no_group = (U8) local_count;

			/* send request to get detail information of each contact list */
			if (local_count)
			{
				imps_p->gen_info.curr_group = 0;
				mmi_imps_ps_view_contact_list_req(0);
			}
			else
			{
				mmi_imps_sync_cont_list();
				imps_p->gen_info.auto_update_done = TRUE;
			}
		}
		else
		{
			if (imps_p->group_info.no_group)
			{
				mmi_imps_util_reset_cont_list();
			}
			
	        mmi_imps_ps_get_about_me_pa_req();
		}
	}
    else
    {
        /* get contact list data using local-saved data if group is not empty */
        if (imps_p->group_info.no_group)
        {
            mmi_imps_ps_view_contact_list_req(0);
        }
        else
        {
            /* mmi_imps_ps_get_block_list_req(); */
            mmi_imps_ps_get_about_me_pa_req();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_view_next_contact_list
 * DESCRIPTION
 *  Send request to view the detail information of next contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_view_next_contact_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_group++;

    if (imps_p->gen_info.curr_group != imps_p->group_info.no_group)
    {
        /* still some group not retrieved */
        mmi_imps_ps_view_contact_list_req(imps_p->gen_info.curr_group);
    }
    else
    {
        mmi_imps_ps_get_about_me_pa_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_view_contact_list_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_VIEW_CONTACT_REQ to PS.
 * PARAMETERS
 *  index       [IN]        Index of group to be retrieved.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_view_contact_list_req(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_view_contact_list_req_struct *req =
        (mmi_imps_view_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_view_contact_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_view_contact_list_req_struct);

    strcpy((S8*) req->contact_list_id, (S8*) imps_p->group_info.group_list[index].group_id);

    /* send view contact list request to PS */
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_VIEW_CONTACT_LIST_REQ, (void*)req, NULL);

    /* restore current action -- won't store state for background update */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_view_contact_list_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_VIEW_CONTACT_LIST_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_view_contact_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_view_contact_list_rsp_struct *rsp = (mmi_imps_view_contact_list_rsp_struct*) msg;
	S16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        S32 i, j, count;
        S32 curr_no_cont = (S32) imps_p->cont_info.no_cont;
        mmi_imps_cont_struct *cont;
		imps_entity_struct *entity;
		FS_HANDLE fileHandle;
		U32 len;

        count = (S32) rsp->user_nick_list.entity_num;

        /* update info of this contact list */
        if (rsp->display_name_p)
        {
            mmi_ucs2cpy(
                (S8*) imps_p->group_info.group_list[imps_p->gen_info.curr_group].group_name,
                (S8*) rsp->display_name);
        }
        if (rsp->authorize_pa_p == TRUE)
        {
            if (rsp->authorize_pa & IMPS_PA_USER_AVAILABILITY || rsp->authorize_pa & IMPS_PA_ONLINE_STATUS)
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_status = IMPS_STATUS_OPEN;
            }
            else
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_status = IMPS_STATUS_HIDE;
            }
            
            if (rsp->authorize_pa & IMPS_PA_STATUS_TEXT)
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_text = IMPS_STATUS_OPEN;
            }
            else
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_text = IMPS_STATUS_HIDE;
            }

            if (rsp->authorize_pa & IMPS_PA_STATUS_CONTENT)
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_pic = IMPS_STATUS_OPEN;
            }
            else
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_pic = IMPS_STATUS_HIDE;
            }   

            if (rsp->authorize_pa & IMPS_PA_STATUS_MOOD)
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_mood = IMPS_STATUS_OPEN;
            }
            else
            {
                imps_p->group_info.group_list[imps_p->gen_info.curr_group].open_mood = IMPS_STATUS_HIDE;
            }           
            
        }
        
        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        entity = (imps_entity_struct*) OslMalloc(sizeof(imps_entity_struct));
        mmi_imps_util_get_filename_from_fileindex(rsp->user_nick_list.entity_list_file_index, IMPS_LIST_FILE_USER, (S8*) ucs2_folder);
        fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);

        if (fileHandle > 0)  
        {
            /* update contacts in file buffer */
            for (i = 0; i < count; i++)
            {
                FS_Read(fileHandle, (void*)entity, sizeof(imps_entity_struct), &len);    
                
                /* still compare "Myself" to prevent abnormal case */
                for (j = 0; j < curr_no_cont; j++)
                {
                    cont = &imps_p->cont_info.cont_list[j];
                    if (mmi_imps_util_is_id_same((S8*) entity->id, (S8*) cont->id))
                    {
                        /* if j == 0, duplicated */
                        if (j == 0)
                        {
                            break;
                        }

                        /* check if the user already updated */
                        if ((cont->comm_state & IMPS_CONT_PA_READY) == 0)
                        {
                            cont->comm_state |= IMPS_CONT_PA_READY;
                            strcpy(
                                (S8*) cont->group_id,
                                (S8*) imps_p->group_info.group_list[imps_p->gen_info.curr_group].group_id);

                            /* use server-provided name if the user did not modify the nick for the contact */
                            if (mmi_ucs2strlen((S8*) cont->nick_name) == 0 && mmi_ucs2strlen((S8*) entity->sname) > 0)
                            {
                                mmi_ucs2cpy((S8*) cont->nick_name, (S8*) entity->sname);
                            }

                            cont->availability = IMPS_PA_USER_UNKNOWN;
                            break;
                        }
                        else
                        {
                            /* to prevent single contact belongs to multiple contact lists cases */
                            break;
                        }
                    }
                }

                /* not in contact list -- new id */
                if ((j == curr_no_cont) && (curr_no_cont < IMPS_MAX_NO_CONT))
                {
                    /* to prevent abnormal case -- empty id */
                    if (strlen((S8*) entity->id))
                    {
                        cont = &imps_p->cont_info.cont_list[j];
                        strcpy((S8*) cont->id, (S8*) entity->id);
                        mmi_ucs2cpy((S8*) cont->nick_name, (S8*) entity->sname);
                        cont->comm_state |= IMPS_CONT_PA_READY;
                        strcpy(
                            (S8*) cont->group_id,
                            (S8*) imps_p->group_info.group_list[imps_p->gen_info.curr_group].group_id);
                        cont->availability = IMPS_PA_USER_UNKNOWN;
                        curr_no_cont++;
                        imps_p->cont_info.no_cont++;
                    }
                }
            }            
            FS_Close(fileHandle);
        }
        OslMfree(entity);

        /* send request to retrieve PA of each friend */
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
        {
            mmi_imps_cont_redraw_list();
            mmi_imps_ps_view_next_contact_list();
        }
        FS_Delete((U16*) ucs2_folder);
        OslMfree(ucs2_folder);        
    }
    else
    {
        mmi_imps_ps_view_next_contact_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_edit_contact_list_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_edit_contact_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_req_struct *req =
        (mmi_imps_edit_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_edit_contact_list_req_struct));

    mmi_imps_group_inline_struct *grp_edit = imps_p->group_info.inline_edit_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_edit_contact_list_req_struct);

    strcpy((S8*) req->contact_list_id, (S8*) imps_p->group_info.group_list[imps_p->group_info.curr_item].group_id);

    req->display_name_p = TRUE;
    mmi_ucs2cpy((S8*) req->display_name, (S8*) grp_edit->group_name);
    if (grp_edit->open_status == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= (IMPS_PA_USER_AVAILABILITY | IMPS_PA_ONLINE_STATUS);
    }

    if (grp_edit->open_text == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_TEXT;
    }

    if (grp_edit->open_pic == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_CONTENT;
    }

    if (grp_edit->open_mood == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_MOOD;
    }

    if (req->authorize_pa)
    {
        req->authorize_pa_p = TRUE;
    }

    req->subscribe_pa = IMPS_PA_ATTR_VALUE_NO_PIC;

    req->subscribe_user_pa = IMPS_PA_ATTR_VALUE_NO_PIC;

    req->subscribe_pa_user_p = TRUE;

    req->subscribe_pa_p = TRUE;

    req->return_content = TRUE;

    SetProtocolEventHandler(mmi_imps_ps_edit_contact_list_rsp, MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_edit_contact_list_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_edit_contact_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_rsp_struct *rsp = (mmi_imps_edit_contact_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_group_edit_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_add_contact_list_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_add_contact_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_add_contact_list_req_struct *req =
        (mmi_imps_add_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_add_contact_list_req_struct));
    mmi_imps_group_inline_struct *grp_edit = imps_p->group_info.inline_edit_group;
    S8 *buff = OslMalloc(IMPS_MAX_ID_LEN);
    S8 *buff2 = OslMalloc(IMPS_MAX_ID_LEN);
    U32 len, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_add_contact_list_req_struct);

    /* generate group id */
    mmi_ucs2_to_asc((S8*) buff2, (S8*) grp_edit->group_name);
    len = strlen((S8*) imps_p->act_prof.username);
    while (imps_p->act_prof.username[i] != '@' && i < len) i++;
    strncpy((S8*) buff, (S8*) imps_p->act_prof.username, i);
    sprintf((S8*) &buff[i], "/%s%s", buff2, &imps_p->act_prof.username[i]);
    strcpy((S8*) req->contact_list_id, (S8*) buff);
    OslMfree(buff);
    OslMfree(buff2);

    req->display_name_p = TRUE;
    mmi_ucs2cpy((S8*) req->display_name, (S8*) grp_edit->group_name);
    if (grp_edit->open_status == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= (IMPS_PA_USER_AVAILABILITY | IMPS_PA_ONLINE_STATUS);
    }

    if (grp_edit->open_text == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_TEXT;
    }

    if (grp_edit->open_pic == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_CONTENT;
    }

    if (grp_edit->open_mood == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_MOOD;
    }    

    if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
    {
        req->is_do_not_notify_p = FALSE;
    }
    else
    {
        req->is_do_not_notify_p = TRUE;
        req->do_not_notify = FALSE;
        if (grp_edit->do_not_notify == 1)
        {
            req->do_not_notify = TRUE;
        }
    }

    if (grp_edit->open_mood == IMPS_STATUS_OPEN)
    {
        req->authorize_pa |= IMPS_PA_STATUS_MOOD;
    }

    req->subscribe_pa = IMPS_PA_ATTR_VALUE_NO_PIC;

    if (req->authorize_pa)
    {
        /* authorize_pa_p = TRUE only when authorize_pa is not none */
        req->authorize_pa_p = TRUE;
    }

    req->subscribe_pa_p = TRUE;

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_add_contact_list_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_ADD_CONTACT_LIST_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_add_contact_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_add_contact_list_rsp_struct *rsp = (mmi_imps_add_contact_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_group_edit_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_del_cont_req
 * DESCRIPTION
 *  Send request to remove one contact from contact list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_del_cont_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_req_struct *req =
        (mmi_imps_edit_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_edit_contact_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_edit_contact_list_req_struct);

    strcpy((S8*) req->contact_list_id, (S8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].group_id);

    req->user_nick_list.entity_count = 1;

    strcpy((S8*) req->user_nick_list.entity[0].id, (S8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id);

    req->user_nick_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;

    SetProtocolEventHandler(mmi_imps_ps_del_cont_rsp, MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_del_cont_rsp
 * DESCRIPTION
 *  Response handler for deleting one contact
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_del_cont_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_rsp_struct *rsp = (mmi_imps_edit_contact_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_del_cont_finished((S32) rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_del_contact_list_req
 * DESCRIPTION
 *  Send request to delete a contact list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_del_contact_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_del_contact_list_req_struct *req =
        (mmi_imps_del_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_del_contact_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_del_contact_list_req_struct);

    strcpy((S8*) req->contact_list_id, (S8*) imps_p->group_info.group_list[imps_p->group_info.curr_item].group_id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_DEL_CONTACT_LIST_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_del_contact_list_rsp
 * DESCRIPTION
 *  Response handler for deleting contact list
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_del_contact_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_del_contact_list_rsp_struct *rsp = (mmi_imps_del_contact_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_group_del_done((S32) rsp->result);

    /* restore current action */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_cont_req
 * DESCRIPTION
 *  Send request to adding new contacts to a group
 * PARAMETERS
 *  group_id        [IN]        Groud id
 *  cont_id         [IN]        Contact id to be added
 *  nick_name       [IN]        Nick name of the contact
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_cont_req(U8 *group_id, U8 *cont_id, S8 *nick_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_req_struct *req =
        (mmi_imps_edit_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_edit_contact_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_edit_contact_list_req_struct);

    strcpy((S8*) req->contact_list_id, (S8*) group_id);

    req->add_user = TRUE;

    req->user_nick_list.entity_count = 1;

    req->subscribe_pa_p = TRUE;

    req->subscribe_pa |= IMPS_PA_ATTR_VALUE_NO_PIC;

    req->subscribe_pa_user_p = TRUE;

    req->subscribe_user_pa |= IMPS_PA_ATTR_VALUE_NO_PIC;

    strcpy((S8*) req->user_nick_list.entity[0].id, (S8*) cont_id);

    req->user_nick_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;

    if (mmi_ucs2strlen(nick_name))
    {
        mmi_ucs2cpy((S8*) req->user_nick_list.entity[0].sname, (S8*) nick_name);
    }

    SetProtocolEventHandler(mmi_imps_add_cont_rsp, MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_add_cont_rsp
 * DESCRIPTION
 *  Response handler of adding new contact
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_add_cont_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_rsp_struct *rsp = (mmi_imps_edit_contact_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_add_cont_finished(rsp->result);

    /* to sync with block list */
    mmi_imps_ps_get_block_list_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_edit_cont_req
 * DESCRIPTION
 *  Send request to edit nick name of a contact
 * PARAMETERS
 *  group_id        [?]     [?]     [?]     [?]
 *  cont_id         [?]     [?]     [?]     [?]
 *  nick_name       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_edit_cont_req(U8 *group_id, U8 *cont_id, S8 *nick_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_req_struct *req =
        (mmi_imps_edit_contact_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_edit_contact_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_edit_contact_list_req_struct);

    strcpy((S8*) req->contact_list_id, (S8*) group_id);

    req->add_user = TRUE;

    req->user_nick_list.entity_count = 1;

    strcpy((S8*) req->user_nick_list.entity[0].id, (S8*) cont_id);

    req->user_nick_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;

    if (mmi_ucs2strlen(nick_name))
    {
        mmi_ucs2cpy((S8*) req->user_nick_list.entity[0].sname, (S8*) nick_name);
    }

    SetProtocolEventHandler(mmi_imps_edit_cont_rsp, MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_EDIT_CONTACT_LIST_REQ, (void*)req, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_edit_cont_rsp
 * DESCRIPTION
 *  Response handler of editing nick name of a contact
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_edit_cont_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_edit_contact_list_rsp_struct *rsp = (mmi_imps_edit_contact_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_about_friend_edit_finish(rsp->result);

    imps_p->gen_info.curr_action = 0;
}

#define PA_PS_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_sync_cont_list
 * DESCRIPTION
 *  Remove dangling contacts and flush data to file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_sync_cont_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 count = (S32) imps_p->cont_info.no_cont;
    S32 no_group = (S32) imps_p->group_info.no_group;
    mmi_imps_cont_info_struct *cont_info = &imps_p->cont_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset number of members */
    for (j = 0; j < no_group; j++)
    {
        imps_p->group_info.group_list[j].no_users = 0;
    }

    /* sync contacts -- remove dangling contacts */
    i = 1;
	
	while (i < count)
	{
        if ((cont_info->cont_list[i].comm_state & IMPS_CONT_PA_READY) == 0)
        {
			if (i < (count - 1))
			{
				memcpy(
                    &cont_info->cont_list[i],
                    &cont_info->cont_list[i + 1],
                    (count - i - 1) * sizeof(mmi_imps_cont_struct));
			}
			count--;
            memset(&cont_info->cont_list[count], 0, sizeof(mmi_imps_cont_struct));
        }
		else
		{
            for (j = 0; j < no_group; j++)
			{
                if (mmi_imps_util_is_id_same(
					(S8*) cont_info->cont_list[i].group_id, 
					(S8*) imps_p->group_info.group_list[j].group_id))
                {
                    imps_p->group_info.group_list[j].no_users++;
                }
			}
			
			i++;
		}
	}

    imps_p->cont_info.no_cont = (U8) count;

    /* flush data to file system */
    mmi_imps_util_write_cont();
    mmi_imps_util_write_group();

    /* redraw contact list */
    mmi_imps_cont_redraw_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_PA_REQ to PS.
 * PARAMETERS
 *  data        [IN]        Pointer to contact list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_pa_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imps_view_contact_list_rsp_struct *ids = (mmi_imps_view_contact_list_rsp_struct*) data;
    S32 count = (S32) ids->user_nick_list.entity_num;

    mmi_imps_get_pa_req_struct *req =
        (mmi_imps_get_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_pa_req_struct));

	FS_HANDLE fileHandle;
	U32 len;
	S16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_pa_req_struct);

    req->user_id_list.entity_count= (U8) ids->user_nick_list.entity_num;

    req->subscribe_pa = IMPS_PA_ATTR_VALUE_NO_PIC;

    ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_imps_util_get_filename_from_fileindex(ids->user_nick_list.entity_list_file_index, IMPS_LIST_FILE_USER, (S8*) ucs2_folder);
    
    fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_ONLY);
    OslMfree(ucs2_folder);
    
    if (fileHandle > 0)
    {
        for (i = 0; i < count; i++)
        {
            FS_Read(fileHandle, (void*)&req->user_id_list.entity[i], sizeof(imps_entity_struct), &len);  
			req->user_id_list.entity[i].entity_type = IMPS_ENTITY_TYPE_USER;
            /* strcpy((S8*) req->user_id_list.entity[i].id, (S8*) entity.id); */
        }
    }
    FS_Close(fileHandle);
    
    SetProtocolEventHandler(mmi_imps_ps_get_pa_rsp, MSG_ID_MMI_IMPS_GET_PA_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_PA_REQ, (void*)req, NULL);

    /* restore current action -- do not have to store action for background update cases */
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_pa_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_GET_PA_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pa_rsp_struct *rsp = (mmi_imps_get_pa_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        S32 i, j;
        S32 ps_count = (S32) rsp->pa_val_list_info.entity_num;
        S32 local_count = (S32) imps_p->cont_info.no_cont;
        imps_pa_value_struct *pa_value;
        mmi_imps_cont_struct *cont;
        imps_pa_value_publisher_struct *pa_value_publisher = OslMalloc(sizeof(imps_pa_value_publisher_struct));
        S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        FS_HANDLE fileHandle = 0;
        U32 len;
        S32 result;

        mmi_imps_util_get_filename_from_fileindex(rsp->pa_val_list_info.entity_list_file_index, IMPS_LIST_FILE_PRESENCE_ATTRIBUTE, (S8*) ucs2_folder);        
        fileHandle = FS_Open((const WCHAR *) ucs2_folder, FS_READ_ONLY);

        /* update information of users */
        for (i = 0; i < ps_count; i++)
        {
            /*  read pa value from file */
            if (fileHandle > 0)
            {
                result = FS_Read(fileHandle, (void *) pa_value_publisher, sizeof(imps_pa_value_publisher_struct), &len);
            }
            else
            {
                break;
            }
            
            for (j = 0; j < local_count; j++)
            {
                if (result < FS_NO_ERROR)
                {
                    break;
                }
                
                if (imps_p->cont_info.cont_list[j].comm_state & IMPS_CONT_PA_READY)
                {
                    if (mmi_imps_util_is_id_same
                        ((S8*) imps_p->cont_info.cont_list[j].id,
                         (S8*) pa_value_publisher->publisher_user_id))
                    {
                        cont = &imps_p->cont_info.cont_list[j];
                        pa_value = &pa_value_publisher->pa_value;

                        /* default availability */
                        cont->availability = IMPS_PA_USER_NOT_AVAILABLE;
                        if (pa_value->online_status_qualifier)  /* if user is online, the availability depends on his setting */
                        {
                            if (pa_value->online_status == TRUE)
                            {
                                if (pa_value->user_availability_qualifier)
                                {
                                    cont->availability = pa_value->user_availability;
                                }
                                else
                                {
                                    cont->availability = IMPS_PA_USER_AVAILABLE;
                                }
                            }
                        }
                        else
                        {
                            if (pa_value->user_availability_qualifier)
                            {
                                cont->availability = pa_value->user_availability;
                            }
                        }

                        if (pa_value->status_mood_qualifier)
                        {
                            cont->mood = pa_value->status_mood;
                        }

                        /* alias */
                        if (pa_value->alias_qualifier)
                        {
                            mmi_ucs2cpy((S8*) cont->alias, (S8*) pa_value->alias);
                        }

                        if (pa_value->status_text_qualifier)
                        {
                            mmi_ucs2cpy((S8*) cont->prof_text, (S8*) pa_value->status_text);
                        }

                        /*
                         * currently no usage 
                         * if(pa_value->status_content_qualifier)
                         */

                    }
                }
            }
        }

        FS_Close(fileHandle);
        FS_Delete((const WCHAR *) ucs2_folder);
        OslMfree(ucs2_folder);
        OslMfree(pa_value_publisher);

        mmi_imps_cont_redraw_list();
    }
    else
    {
        /* do nothing */
    }

    mmi_imps_ps_view_next_contact_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_about_me_pa_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_IMPS_GET_PA_REQ for about me
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_about_me_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pa_rsp_struct *rsp = (mmi_imps_get_pa_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }

    if (rsp->result == IMPS_OK)
    {
        mmi_imps_nvram_struct *nvram_buff = (mmi_imps_nvram_struct*) OslMalloc(NVRAM_EF_IMPS_SIZE);
        imps_pa_value_struct *pa_value;
        mmi_imps_cont_struct *cont;
        imps_pa_value_publisher_struct *pa_value_publisher = OslMalloc(sizeof(imps_pa_value_publisher_struct));
        FS_HANDLE fileHandle = 0;
        U32 len;
        S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_imps_util_get_filename_from_fileindex(rsp->pa_val_list_info.entity_list_file_index, IMPS_LIST_FILE_PRESENCE_ATTRIBUTE, (S8*) ucs2_folder);
        fileHandle = FS_Open((const WCHAR *) ucs2_folder, FS_READ_ONLY);

        if (fileHandle > 0)
        {
            FS_Read(fileHandle, (void *) pa_value_publisher, sizeof(imps_pa_value_publisher_struct), &len);
        }

        /* read data from NVRAM */
        mmi_imps_util_read_nvram((void*)nvram_buff);

        cont = &imps_p->cont_info.cont_list[0];
        pa_value = &pa_value_publisher->pa_value;

        /* default regarded as online */
        cont->availability = IMPS_PA_USER_AVAILABLE;

        if (pa_value->online_status_qualifier)
        {
            if (pa_value->online_status == TRUE)
            {
                if (pa_value->user_availability_qualifier)
                {
                    cont->availability = pa_value->user_availability;
                }
            }
            else
            {
                cont->availability = IMPS_PA_USER_NOT_AVAILABLE;
            }
        }

        if (pa_value->status_mood_qualifier)
        {
            cont->mood = pa_value->status_mood;
        }
        else
        {
            cont->mood = nvram_buff->about_me.mood;
        }

        if (pa_value->status_text_qualifier)
        {
            mmi_ucs2cpy((S8*) cont->prof_text, (S8*) pa_value->status_text);
            mmi_ucs2cpy((S8*) nvram_buff->about_me.my_prof, (S8*) cont->prof_text);
        }
        else
        {
            mmi_ucs2cpy((S8*) cont->prof_text, (S8*) nvram_buff->about_me.my_prof);
        }

        /* keneng : alias */
        if (pa_value->alias_qualifier)
        {
            mmi_ucs2cpy((S8*) cont->alias, (S8*) pa_value->alias);
            mmi_ucs2cpy((S8*) nvram_buff->about_me.alias, (S8*) cont->alias);
        }
        else
        {
            mmi_ucs2cpy((S8*) cont->alias, (S8*) nvram_buff->about_me.alias);
        }
        
        FS_Close(fileHandle);
        FS_Delete((const WCHAR *) ucs2_folder);
        OslMfree(ucs2_folder);
        OslMfree(pa_value_publisher);

        /* status */
        nvram_buff->about_me.status = (U8) cont->availability;
        nvram_buff->about_me.mood = (U8) cont->mood;

        mmi_imps_util_write_nvram((void*)nvram_buff);

        OslMfree(nvram_buff);
        mmi_imps_cont_redraw_list();
    }

    /* check if is before imps 1.3 */
    if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
    {
        mmi_imps_ps_get_block_list_req();
    }
    else
    {
        mmi_imps_ps_get_about_me_pp_req();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_about_me_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_PA_REQ to get detailed information of myself.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_about_me_pa_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pa_req_struct *req =
        (mmi_imps_get_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_pa_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_pa_req_struct);
    
    req->user_id_list.entity_count = 1;

    req->subscribe_pa = IMPS_PA_ATTR_VALUE_NO_PIC;

    strcpy((S8*) req->user_id_list.entity[0].id, (S8*) imps_p->cont_info.cont_list[0].id);

    req->user_id_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;

    SetProtocolEventHandler(mmi_imps_ps_get_about_me_pa_rsp, MSG_ID_MMI_IMPS_GET_PA_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_PA_REQ, (void*)req, NULL);

    /* restore current action -- do not have to store action for background update cases */
    imps_p->gen_info.curr_action = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_single_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_PA_REQ to get detailed information of a user.
 * PARAMETERS
 *  id      [IN]        Id of contact to get
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_single_pa_req(U8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pa_req_struct *req =
        (mmi_imps_get_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_pa_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_pa_req_struct);

    req->user_id_list.entity_count = 1;

    req->user_id_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;

    req->subscribe_pa = IMPS_PA_ATTR_VALUE;

    strcpy((S8*) req->user_id_list.entity[0].id, (S8*) id);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_PA_REQ, (void*)req, NULL);
    SetProtocolEventHandler(mmi_imps_ps_get_single_pa_rsp, MSG_ID_MMI_IMPS_GET_PA_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_single_pa_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_GET_PA_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_single_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pa_rsp_struct *rsp = (mmi_imps_get_pa_rsp_struct*) msg;
  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        imps_pa_value_publisher_struct *pa_value_publisher = OslMalloc(sizeof(imps_pa_value_publisher_struct));
        FS_HANDLE fileHandle = 0;
        U32 len;
        S32 result = FS_ERROR_RESERVED;
        S16 *ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_imps_util_get_filename_from_fileindex(rsp->pa_val_list_info.entity_list_file_index, IMPS_LIST_FILE_PRESENCE_ATTRIBUTE, (S8*) ucs2_folder);
        

        fileHandle = FS_Open((const WCHAR *) ucs2_folder, FS_READ_ONLY);
        if (fileHandle > 0)
        {
            result = FS_Read(fileHandle, (void *) pa_value_publisher, sizeof(imps_pa_value_publisher_struct), &len);
        }
        
        if (result == FS_NO_ERROR)
        {
            imps_pa_value_struct *pa_value = &pa_value_publisher->pa_value;
            mmi_imps_cont_struct *cont = &imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont];

            if (pa_value->online_status_qualifier)  /* if user is online, the availability depends on his setting */
            {
                if (pa_value->online_status == TRUE)
                {
                    if (pa_value->user_availability_qualifier)
                    {
                        cont->availability = pa_value->user_availability;
                    }
                    else
                    {
                        cont->availability = IMPS_PA_USER_AVAILABLE;
                    }
                }
                else
                {
                    cont->availability = IMPS_PA_USER_NOT_AVAILABLE;
                }
            }
            else
            {
                if (pa_value->user_availability_qualifier)
                {
                    cont->availability = pa_value->user_availability;
                }
            }

            if (pa_value->status_mood_qualifier)
            {
                cont->mood = pa_value->status_mood;
            }
            else
            {
                cont->mood = IMPS_PA_STATUS_MOOD_HAPPY;
            }

            if (pa_value->status_text_qualifier)
            {
                mmi_ucs2cpy((S8*) cont->prof_text, (S8*) pa_value->status_text);
            }
            else
            {
                cont->prof_text[0] = 0;
            }

            /* image context, temporary saved in common file buffer */
            if (pa_value->status_content_qualifier)
            {
                mmi_ucs2cpy((S8*) imps_p->friend_info.file_name, (S8*) pa_value->status_content_file_name);
            }
            else
            {
                imps_p->friend_info.file_name[0] = 0;
            }
        }

        FS_Close(fileHandle);
        FS_Delete((const WCHAR *) ucs2_folder);
        OslMfree(ucs2_folder);
        OslMfree(pa_value_publisher);

        if (imps_p->gen_info.imps_version < IMPS_CSP_VERSION_13)
        {
            /* before imps 1.3 */
            /* update data */
            mmi_imps_about_friend_refresh_finish();
        }
        else
        {
            /* imps 1.3 or later, need get public profile during login period */
            mmi_imps_ps_get_pp_req();
        }
    }
    else
    {
        mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_ABOUT_FRIEND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_abort_get_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_UPDATE_PA_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_abort_get_pa_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_GET_PA_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_abort_get_pa_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_ABORT_GET_PA_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_abort_get_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (imps_p->gen_info.is_reentry)
    {
        mmi_imps_re_entry_app();
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
        {
            GoBackToHistory(SCR_ID_IMPS_ABOUT_FRIEND);
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_update_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_UPDATE_PA_REQ to PS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_update_pa_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_update_pa_req_struct *req =
        (mmi_imps_update_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_update_pa_req_struct));
    imps_pa_value_struct *pa_value = &req->pa_update_list.pa_value;
    mmi_imps_presence_struct *about_info = imps_p->about_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_update_pa_req_struct);

    strcpy((S8*) req->pa_update_list.publisher_user_id, (S8*) imps_p->act_prof.username);

    pa_value->registration_qualifier = FALSE;
    pa_value->client_info_qualifier = FALSE;

    pa_value->user_availability_qualifier = TRUE;
    pa_value->user_availability = (U8) about_info->status;

    pa_value->status_mood_qualifier = TRUE;
    pa_value->status_mood = (U8) about_info->mood;

    pa_value->status_text_qualifier = TRUE;
    mmi_ucs2cpy((S8*) pa_value->status_text, (S8*) about_info->my_prof);

    /* alias */
    pa_value->alias_qualifier = TRUE;
    mmi_ucs2cpy((S8*) pa_value->alias, (S8*) about_info->alias);

    pa_value->status_content_qualifier = FALSE;
    if (imps_p->about_info->is_pic_changed && mmi_ucs2strlen((S8*) about_info->my_pic))
    {
        S8 *file_ext = NULL, *mine_type = NULL;

        /* shall fill contect type afterwards */
        pa_value->status_content_qualifier = TRUE;

        mmi_ucs2cpy((S8*) pa_value->status_content_file_name, (S8*) IMPS_ABOUT_PIC_PREFIX);

        file_ext = (S8*) mmi_fmgr_extract_ext_file_name((S8*) about_info->file_buff);
        mmi_ucs2cat((S8*) pa_value->status_content_file_name, (S8*) file_ext);

        mmi_ucs2_to_asc((S8*) pa_value->status_content_type, (S8*) file_ext);
        mine_type = mmi_imps_get_mine_type((S8*) pa_value->status_content_type);

        if (mine_type)
        {
            strcpy((S8*) pa_value->status_content_type, mine_type);
        }
    }

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_UPDATE_PA_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_update_pa_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_UPDATE_PA_RSP.
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_update_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_update_pa_rsp_struct *rsp = (mmi_imps_update_pa_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    mmi_imps_presence_save_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_pa_notify_ind
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_PA_NOTIFY_IND.
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_pa_notify_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_pa_notify_ind_struct *ind = (mmi_imps_pa_notify_ind_struct*) msg;
    mmi_imps_cont_struct *cont;
    S32 i, pa_count, entity_count, j;
    imps_pa_value_struct *pa_value;
    imps_pa_value_publisher_struct *pa_value_publisher = OslMalloc(sizeof(imps_pa_value_publisher_struct));
    FS_HANDLE fileHandle = 0;
    U32 len;
    S32 result;
	S16 *ucs2_folder = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pa_count = (S32) ind->pa_val_list_info.entity_num;
    entity_count = (S32) imps_p->cont_info.no_cont;

    ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_imps_util_get_filename_from_fileindex(ind->pa_val_list_info.entity_list_file_index, IMPS_LIST_FILE_PRESENCE_ATTRIBUTE, (S8*) ucs2_folder);

    fileHandle = FS_Open((const WCHAR *) ucs2_folder, FS_READ_ONLY);

    for (i = 0; i < pa_count; i++)
    {
        /* keneng : read pa value from file */
        if (fileHandle > 0)
        {
            result = FS_Read(fileHandle, (void *) pa_value_publisher, sizeof(imps_pa_value_publisher_struct), &len);
        }
        else
        {
            continue;
        }
            
        for (j = 0; j < entity_count; j++)
        {
            if (result < FS_NO_ERROR)
            {
                break;
            }
            cont = &imps_p->cont_info.cont_list[j];

            /* find the user in contact list, update it's data */
            if (mmi_imps_util_is_id_same((S8*) cont->id, (S8*) pa_value_publisher->publisher_user_id))
            {
                pa_value = &pa_value_publisher->pa_value;

                if (pa_value->online_status_qualifier)  /* if user is online, the availability depends on his setting */
                {
                    if (pa_value->online_status == TRUE)
                    {
                        if (pa_value->user_availability_qualifier)
                        {
                            cont->availability = pa_value->user_availability;
                        }
                        else
                        {
                            cont->availability = IMPS_PA_USER_AVAILABLE;
                        }
                    }
                    else
                    {
                        cont->availability = IMPS_PA_USER_NOT_AVAILABLE;
                    }
                }
                else
                {
                    if (pa_value->user_availability_qualifier)
                    {
                        cont->availability = pa_value->user_availability;
                    }
                }

                if (pa_value->status_mood_qualifier)
                {
                    cont->mood = pa_value->status_mood;
                }

                /* keneng : change of alias */
                if (pa_value->alias_qualifier)
                {
                    mmi_ucs2cpy((S8*) cont->alias, (S8*) pa_value->alias);
                }

                if (pa_value->status_text_qualifier)
                {
                    mmi_ucs2cpy((S8*) cont->prof_text, (S8*) pa_value->status_text);
                }
            }
        }
    }

    FS_Close(fileHandle);
    FS_Delete((const WCHAR *) ucs2_folder);
    OslMfree(ucs2_folder);
    OslMfree(pa_value_publisher);

    /* update information of the contact */

    /* force to redraw contact list */
    mmi_imps_cont_redraw_list();

}


#define WATCH_PS_IMPS


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_watch_list_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_WATCHER_LIST_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_watch_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_watcher_list_req_struct *req =
        (mmi_imps_get_watcher_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_watcher_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_watcher_list_req_struct);

    req->max_watcher_list = IMPS_MAX_SEARCH_RESULT;
    req->max_watcher_list_p = TRUE;

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_WATCHER_LIST_REQ, (void*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_watch_list_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_GET_WATCHER_LIST_RSP
 * PARAMETERS
 *  msg     [IN]        Indication data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_watch_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_watcher_list_rsp_struct *rsp = (mmi_imps_get_watcher_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore current action */
    imps_p->gen_info.curr_action = 0;

    if (rsp->result == IMPS_OK)
    {
        S32 result;
		S16 *ucs2_folder;

    if (rsp->watcher_list_p == FALSE || rsp->watcher_list.entity_num == 0)
    {
        mmi_imps_util_disp_empty_popup();
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT);
    }
        else
    {
        /* copy response to local structure */
        imps_p->search_result.count = rsp->watcher_list.entity_num;

        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        mmi_imps_util_get_filename_from_fileindex(rsp->watcher_list.entity_list_file_index, IMPS_LIST_FILE_WATCHER, (S8*) ucs2_folder);

        /* display result screen */
        result = mmi_imps_pre_entry_watch_list((S16*) ucs2_folder);
        FS_Delete((U16*) ucs2_folder);
        OslMfree(ucs2_folder);

        if (result > 0)
        {
            if (GetActiveScreenId() == SCR_ID_IMPS_PROGRESS)
            {
                mmi_imps_entry_search_result();
                mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT);
            }
            else
            {
                HistoryReplace(SCR_ID_IMPS_PROGRESS, SCR_ID_IMPS_WATCHER_LIST, mmi_imps_entry_watch_list);
            }
        }
        else
        {
            mmi_imps_util_disp_err_popup(STR_ID_IMPS_ERR_FILE_ACCESS_ERROR);
            mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT);
        }
    }
    }
	else
	{
		mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(rsp->result));
        mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_get_watch_list_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_WATCHER_LIST_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_get_watch_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_ABORT_GET_WATCHER_LIST_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_abort_get_watch_list_rsp
 * DESCRIPTION
 *  Abort Get Watcher list process
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_abort_get_watch_list_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_abort_search_finish();

    /* restore current action */
    imps_p->gen_info.curr_action = 0;
}


#define PP_PS_IMPS



/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_about_me_pp_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_GET_PP_REQ to get public profile of myself.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_about_me_pp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pp_req_struct *req =
        (mmi_imps_get_pp_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_pp_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_pp_req_struct);

    strcpy((S8*) req->userid, (S8*) imps_p->cont_info.cont_list[0].id);

    SetProtocolEventHandler(mmi_imps_ps_get_about_me_pp_rsp, MSG_ID_MMI_IMPS_GET_PP_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_PP_REQ, (void*)req, NULL);

    /* restore current action -- do not have to store action for background update cases */
    imps_p->gen_info.curr_action = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_about_me_pp_rsp
 * DESCRIPTION
 *  Response handler of MSG_ID_MMI_IMPS_GET_PP_REQ for about me
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_about_me_pp_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pp_rsp_struct *rsp = (mmi_imps_get_pp_rsp_struct*) msg;
    S16 *ucs2_folder = NULL;
    FS_HANDLE fileHandle;
    mmi_imps_public_profile_struct *public_profile = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_action == MSG_ID_MMI_IMPS_LOGOUT_REQ || imps_p->gen_info.is_login == FALSE)
    {
        return;
    }
    public_profile = (mmi_imps_public_profile_struct*) OslMalloc(sizeof(mmi_imps_public_profile_struct));
    memset(public_profile, 0, sizeof(mmi_imps_public_profile_struct));
    if (rsp->result == IMPS_OK)
    {
        /* Save public profile to file */
        mmi_ucs2cpy((S8*) public_profile->city, (S8*) rsp->user_pp.city);
        mmi_ucs2cpy((S8*) public_profile->fname, (S8*) rsp->user_pp.fname);
        mmi_ucs2cpy((S8*) public_profile->free_text, (S8*) rsp->user_pp.freetext);
        public_profile->gender = (S32) rsp->user_pp.gender;
        mmi_ucs2cpy((S8*) public_profile->hobbies, (S8*) rsp->user_pp.hobbies);
        mmi_ucs2cpy((S8*) public_profile->intention, (S8*) rsp->user_pp.intention);
        public_profile->marital_status = (S32) rsp->user_pp.marital_status;
        if (strlen((S8*) rsp->user_pp.age) >= 6)
        {
            mmi_asc_n_to_ucs2((S8*) public_profile->year_buff, (S8*) &rsp->user_pp.age[0], 4);
            mmi_asc_n_to_ucs2((S8*) public_profile->month_buff, (S8*) &rsp->user_pp.age[4], 2); 
            mmi_ucs2cpy((S8*) public_profile->day_buff, (S8*) L"01");
        }
        else
        {
            mmi_ucs2cpy((S8*) public_profile->year_buff, (S8*) L"1990");
            mmi_ucs2cpy((S8*) public_profile->month_buff, (S8*) L"01"); 
            mmi_ucs2cpy((S8*) public_profile->day_buff, (S8*) L"01"); 
        }

    }
    else
    {
        mmi_ucs2cpy((S8*) public_profile->year_buff, (S8*) L"1990");
        mmi_ucs2cpy((S8*) public_profile->month_buff, (S8*) L"01");
        mmi_ucs2cpy((S8*) public_profile->day_buff, (S8*) L"01");
    }
    
    ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    mmi_imps_util_get_work_path((S8*) ucs2_folder);
    mmi_ucs2cat((S8*) ucs2_folder, (S8*) IMPS_PUBLIC_PROFILE);

    fileHandle = FS_Open((U16*) ucs2_folder, FS_CREATE_ALWAYS);
    OslMfree(ucs2_folder);

    if (fileHandle > 0)
    {
        U32 len;

        FS_Write(
            fileHandle,
            (void*) public_profile,
            sizeof(mmi_imps_public_profile_struct),
            (U32*) &len);
        FS_Close(fileHandle);        
    }
    OslMfree(public_profile);
    
    mmi_imps_ps_get_block_list_req();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_pp_req
 * DESCRIPTION
 *  Send get public profile request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_pp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pp_req_struct *req =
        (mmi_imps_get_pp_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_get_pp_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_get_pp_req_struct);

    strcpy((S8*) req->userid, (S8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].id);

    SetProtocolEventHandler(mmi_imps_ps_get_pp_rsp, MSG_ID_MMI_IMPS_GET_PP_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_GET_PP_REQ, (void*)req, NULL);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_get_pp_rsp
 * DESCRIPTION
 *  Handler for get public profile response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_get_pp_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_get_pp_rsp_struct *rsp = (mmi_imps_get_pp_rsp_struct*) msg;
    wgui_color_buffer_writer_struct writer;
    BOOL result;
    U16 *temp_buff = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result == IMPS_OK)
    {
        temp_buff = OslMalloc(IMPS_MAX_ID_LEN);
            
        /* save data to struct */
        imps_p->friend_info.profile_text[0] = 0;
        wgui_color_buffer_create_writer(&writer, (U8*) imps_p->friend_info.profile_text, IMPS_PUBLIC_PROFILE_DISP_BUFF * ENCODING_LENGTH);

        /* prof text */
        wgui_color_buffer_write_string(&writer, (U8*) imps_p->cont_info.cont_list[imps_p->cont_info.curr_cont].prof_text, MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, '\n');

        /* friendly name */
        if (mmi_ucs2strlen((S8*) rsp->user_pp.fname) > 0)
        {
            wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_FRIENDLY_NAME), MMI_FALSE, &result);
            wgui_color_buffer_write_char(&writer, ':');
            wgui_color_buffer_write_string(&writer, (U8*) rsp->user_pp.fname, MMI_FALSE, &result);   
            wgui_color_buffer_write_char(&writer, '\n');           
        }

        /* age : birthday */        
        wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_AGE), MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, ':');
        mmi_asc_to_ucs2((S8*) temp_buff, (S8*) rsp->user_pp.age);
        wgui_color_buffer_write_string(&writer, (U8*) temp_buff, MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, '\n');        
        
        /* gender */
        temp_buff[0] = 0;
        if (rsp->user_pp.gender == IMPS_GENDER_NO_DISCLOSE)
        {
            mmi_ucs2cpy((S8*) temp_buff, (S8*) GetString(STR_ID_IMPS_NO_DISCLOSE));
        }
        else if (rsp->user_pp.gender == IMPS_GENDER_FEMALE)
        {
            mmi_ucs2cpy((S8*) temp_buff, (S8*) GetString(STR_ID_IMPS_FEMALE));
        }
        else if (rsp->user_pp.gender == IMPS_GENDER_MALE)
        {
            mmi_ucs2cpy((S8*) temp_buff, (S8*) GetString(STR_ID_IMPS_MALE));
        }        
        else
        {
            mmi_ucs2cpy((S8*) temp_buff, (S8*) GetString(STR_ID_IMPS_UNSPECIFIED));
        }

        wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_GENDER), MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, ':');
        wgui_color_buffer_write_string(&writer, (U8*) temp_buff, MMI_FALSE, &result);   
        wgui_color_buffer_write_char(&writer, '\n');        

        /* marital status */
        wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_MARITAL_STATUS), MMI_FALSE, &result);
        wgui_color_buffer_write_char(&writer, ':');
        wgui_color_buffer_write_string(&writer, (U8*) GetString((U16)(STR_ID_IMPS_NO_DISCLOSE + rsp->user_pp.marital_status)), MMI_FALSE, &result);   
        wgui_color_buffer_write_char(&writer, '\n');        

        /* city */
        if (mmi_ucs2strlen((S8*) rsp->user_pp.city) > 0)
        {        
            wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_CITY), MMI_FALSE, &result);
            wgui_color_buffer_write_char(&writer, ':');
            wgui_color_buffer_write_string(&writer, (U8*) rsp->user_pp.city, MMI_FALSE, &result);   
            wgui_color_buffer_write_char(&writer, '\n'); 
        }

        /* intention */
        if (mmi_ucs2strlen((S8*) rsp->user_pp.intention) > 0)
        {          
            wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_INTENTION), MMI_FALSE, &result);
            wgui_color_buffer_write_char(&writer, ':');
            wgui_color_buffer_write_string(&writer, (U8*) rsp->user_pp.intention, MMI_FALSE, &result);   
            wgui_color_buffer_write_char(&writer, '\n'); 
        }

        /* hobbies */
        if (mmi_ucs2strlen((S8*) rsp->user_pp.hobbies) > 0)
        {           
            wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_HOBBIES), MMI_FALSE, &result);
            wgui_color_buffer_write_char(&writer, ':');
            wgui_color_buffer_write_string(&writer, (U8*) rsp->user_pp.hobbies, MMI_FALSE, &result);   
            wgui_color_buffer_write_char(&writer, '\n');   
        }

        /* free text */
        if (mmi_ucs2strlen((S8*) rsp->user_pp.freetext) > 0)
        {           
            wgui_color_buffer_write_string(&writer, (U8*) GetString(STR_ID_IMPS_FREE_TEXT), MMI_FALSE, &result);
            wgui_color_buffer_write_char(&writer, ':');
            wgui_color_buffer_write_string(&writer, (U8*) rsp->user_pp.freetext, MMI_FALSE, &result);   
            wgui_color_buffer_write_char(&writer, '\n');      
        }

        OslMfree(temp_buff);
    }
    else
    {
        
    }
    
    /* Update data */
    mmi_imps_about_friend_refresh_finish();
        
    imps_p->gen_info.curr_action = 0; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_update_pp_req
 * DESCRIPTION
 *  Send update public profile request to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_update_pp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_update_pp_req_struct *req = 
        (mmi_imps_update_pp_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_update_pp_req_struct));
    imps_public_profile_struct *user_pp = NULL;
    mmi_imps_public_profile_struct * inline_pp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_update_pp_req_struct);

    req->clear_pp = FALSE;
    req->user_pp_p = TRUE;

    user_pp = &req->user_pp;
    inline_pp = &imps_p->pp_info->public_profile;

    /* age */
    if (strlen((S8*) inline_pp->year_buff) > 0 && strlen((S8*) inline_pp->month_buff) > 0)
    {
        mmi_ucs2_n_to_asc((S8*) &user_pp->age[0], (S8*) inline_pp->year_buff, 8);
        mmi_ucs2_n_to_asc((S8*) &user_pp->age[4], (S8*) inline_pp->month_buff, 4);
    }

    /* city */
    if (mmi_ucs2strlen((S8*) inline_pp->city) > 0)
    {
        mmi_ucs2cpy((S8*) user_pp->city, (S8*) inline_pp->city);
    }

    /* country code */
    strcpy((S8*) user_pp->country_code, (S8*) "CN");

    /* friendly name */
    if (mmi_ucs2strlen((S8*) inline_pp->fname) > 0)
    {
        mmi_ucs2cpy((S8*) user_pp->fname, (S8*) inline_pp->fname);
    }    

    /* free text */
    if (mmi_ucs2strlen((S8*) inline_pp->free_text) > 0)
    {
        mmi_ucs2cpy((S8*) user_pp->freetext, (S8*) inline_pp->free_text);
    }    

    /* gender */
    user_pp->gender = (U8) inline_pp->gender;

    /* hobbies */
    if (mmi_ucs2strlen((S8*) inline_pp->hobbies) > 0)
    {
        mmi_ucs2cpy((S8*) user_pp->hobbies, (S8*) inline_pp->hobbies);
    }        

    /* intention */
    if (mmi_ucs2strlen((S8*) inline_pp->intention) > 0)
    {
        mmi_ucs2cpy((S8*) user_pp->intention, (S8*) inline_pp->intention);
    }        

    /* marital status */
    user_pp->marital_status = (U8) inline_pp->marital_status;

    SetProtocolEventHandler(mmi_imps_ps_update_pp_rsp, MSG_ID_MMI_IMPS_UPDATE_PP_RSP);

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_UPDATE_PP_REQ, (void*)req, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_update_pp_rsp
 * DESCRIPTION
 *  Handler for update public profile response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_update_pp_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_update_pp_rsp_struct *rsp = (mmi_imps_update_pp_rsp_struct*) msg;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* restore current action */
    imps_p->gen_info.curr_action = 0;
    
    mmi_imps_public_profile_save_done(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_pa_auth_ind
 * DESCRIPTION
 *  Indication handler of Presence attribute authentication indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_ps_pa_auth_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_presence_auth_ind_struct *ind = (mmi_imps_presence_auth_ind_struct*) msg;

    FS_HANDLE fileHandle = 0;
    U32 len;
    S16 *ucs2_folder = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->pa_auth == NULL)
    {
        imps_p->pa_auth = (mmi_imps_presence_auth_struct*) OslMalloc(sizeof(mmi_imps_presence_auth_struct));
        memset(imps_p->pa_auth, 0, sizeof(mmi_imps_presence_auth_struct));
    }

        /* save pa auth info to current process struct */
        ucs2_folder = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

        mmi_imps_util_file_path((S8*) ucs2_folder, (S8*) IMPS_PA_AUTH, 0);

        fileHandle = FS_Open((U16*) ucs2_folder, FS_READ_WRITE | FS_CREATE);
        OslMfree(ucs2_folder);  
        if (fileHandle > 0)
        {
            FS_Seek(fileHandle, 0, FS_FILE_END);
            FS_Write(fileHandle, (void*) ind, sizeof(mmi_imps_presence_auth_ind_struct), &len);
            imps_p->pa_auth->total++;
        }
        FS_Close(fileHandle);    

    mmi_imps_check_pa_auth();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_presence_auth_user_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_PA_AUTH_USER_REQ to PS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
void mmi_imps_presence_auth_user_req(BOOL is_accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_presence_auth_user_struct *req =
            (mmi_imps_presence_auth_user_struct*) OslConstructDataPtr(sizeof(mmi_imps_presence_auth_user_struct));  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    IMPS_MEMSET(req, 0, mmi_imps_presence_auth_user_struct);

    req->attr_list = imps_p->pa_auth->attr_list;

    req->is_accept = is_accept;

    memcpy(&req->auth_user, &imps_p->pa_auth->auth_user, sizeof(imps_entity_struct));

    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_PA_AUTH_USER_REQ, req, NULL);

    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_create_attributelist_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_CREATE_ATTRIBUTE_LIST_REQ to PS
 * PARAMETERS
 *  id      [IN]        Id of contact or contact list to create
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_create_attributelist_req(void *id_list, U32 attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_create_attribute_list_req_struct *req =
        (mmi_imps_create_attribute_list_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_create_attribute_list_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_create_attribute_list_req_struct);

    req->attr_list = attr_list;

    memcpy(&req->user_id_list, id_list, sizeof(imps_entity_list_struct));

    SetProtocolEventHandler(mmi_imps_ps_create_attributelist_rsp, MSG_ID_MMI_IMPS_CREATE_ATTRIBUTE_LIST_RSP);
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_CREATE_ATTRIBUTE_LIST_REQ, req, NULL);
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_create_attributelist_rsp
 * DESCRIPTION
 *  Response handler of create attribute list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_create_attributelist_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_create_attribute_list_rsp_struct *rsp = (mmi_imps_create_attribute_list_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_action = 0;
    mmi_imps_create_attributelist_finished(rsp->result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_subs_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_SUBS_PA_REQ to PS
 * PARAMETERS
 *  id      [IN]        Id of contact to subscribe
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_subs_pa_req(void *id_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_subs_pa_req_struct *req =
        (mmi_imps_subs_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_subs_pa_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IMPS_MEMSET(req, 0, mmi_imps_subs_pa_req_struct);

    req->subscribe_pa = IMPS_PA_ATTR_VALUE_NO_PIC; /* IMPS_PA_ATTR_VALUE;  IMPS_PA_ATTR_VALUE_NO_PIC */

    memcpy(&req->id_list, id_list, sizeof(imps_entity_list_struct));

    SetProtocolEventHandler(mmi_imps_ps_subs_pa_rsp, MSG_ID_MMI_IMPS_SUBS_PA_RSP);
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SUBS_PA_REQ, req, NULL);
    imps_p->gen_info.curr_action = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_subs_pa_rsp
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_IMPS_SUBS_PA_RSP
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_subs_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_subs_pa_rsp_struct *rsp = (mmi_imps_subs_pa_rsp_struct*) msg;
    imps_entity_list_struct *id_list = NULL;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imps_p->gen_info.curr_subs < imps_p->group_info.no_group)
    {
        id_list = OslMalloc(sizeof(imps_entity_list_struct));
        memset(id_list, 0, sizeof(imps_entity_list_struct));
        id_list->entity_count = 0;
        for(i = 0; i < IMPS_MAX_ENTITY_NUMBER && i < imps_p->group_info.no_group; i++)
        {           
            id_list->entity[id_list->entity_count].entity_type = IMPS_ENTITY_TYPE_CONTACT_LIST;
            strcpy((S8*) id_list->entity[id_list->entity_count++].id, (S8*) imps_p->group_info.group_list[i + imps_p->gen_info.curr_subs].group_id);
    		if ((imps_p->group_info.no_group - i == 1) || (IMPS_MAX_ENTITY_NUMBER - i == 1)) 
            {
                imps_p->gen_info.curr_subs += (i + 1);
                /* send request to PS to subscribe contacts' pa */
                mmi_imps_ps_subs_pa_req((void*) id_list);                 
            }
        }

        OslMfree(id_list);
    }
    else
    {
        mmi_imps_sync_cont_list();        
        imps_p->gen_info.auto_update_done = TRUE;
        mmi_imps_subscribe_pa_finished(rsp->result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_subscribe_pa_finished
 * DESCRIPTION
 *  Handler when subscribe pa finished
 * PARAMETERS
 *  result      [IN]        Error code of sbuscribing
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_subscribe_pa_finished(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_action = 0;
    if (result == IMPS_OK)
    {
        if (IsScreenPresent(SCR_ID_IMPS_PROGRESS))
        {
            mmi_imps_util_disp_popup_done();
        }
        else
        {
            /* do nothing when subscribe during login */
        }
    }
    else
    {
        if (IsScreenPresent(SCR_ID_IMPS_PROGRESS))
        {
            mmi_imps_util_disp_err_popup(mmi_imps_util_get_err_str(mmi_imps_util_get_err_str(result)));        }
        else
        {
            /* do nothing when subscribe during login */
        }
    }

    mmi_imps_util_del_scr_after_progress(SCR_ID_IMPS_CONT_OPT);
}


#ifdef IMPS_FOR_OMA_ONLY

/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_unsubs_pa_req
 * DESCRIPTION
 *  Send MSG_ID_MMI_IMPS_UNSUBS_PA_REQ to PS
 * PARAMETERS
 *  id      [IN]        Id of contact to unsubscribe
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_unsubs_pa_req(S8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_unsubs_pa_req_struct *req =
        (mmi_imps_unsubs_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_unsubs_pa_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_action = 0;

    IMPS_MEMSET(req, 0, mmi_imps_unsubs_pa_req_struct);

    req->user_id_list.entity_count = 1;
    req->user_id_list.entity[0].entity_type = IMPS_ENTITY_TYPE_USER;
    strcpy((S8*) req->user_id_list.entity[0].id, (S8*) id);

    SetProtocolEventHandler(mmi_imps_ps_subs_pa_rsp, MSG_ID_MMI_IMPS_UNSUBS_PA_RSP);
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_UNSUBS_PA_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_subs_group_pa_rsp
 * DESCRIPTION
 *  Handler for mmi_imps_ps_subs_group_pa_rsp
 * PARAMETERS
 *  msg     [IN]        Result of response
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_subs_group_pa_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_subs_pa_rsp_struct *rsp = (mmi_imps_subs_pa_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imps_util_disp_popup_done();
    DeleteScreenIfPresent(SCR_ID_IMPS_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imps_ps_subs_group_pa_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imps_ps_subs_group_pa_req(U8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imps_subs_pa_req_struct *req =
        (mmi_imps_subs_pa_req_struct*) OslConstructDataPtr(sizeof(mmi_imps_subs_pa_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imps_p->gen_info.curr_action = 0;

    IMPS_MEMSET(req, 0, mmi_imps_subs_pa_req_struct);

    req->subscribe_pa = IMPS_PA_ATTR_VALUE_NO_PIC;

    req->id_list.entity_count = 1;
    req->id_list.entity[0].entity_type = IMPS_ENTITY_TYPE_CONTACT_LIST;
    strcpy((S8*) req->id_list.entity[0].id, (S8*) id);

    SetProtocolEventHandler(mmi_imps_ps_subs_group_pa_rsp, MSG_ID_MMI_IMPS_SUBS_PA_RSP);
    mmi_imps_ps_send_msg(MSG_ID_MMI_IMPS_SUBS_PA_REQ, req, NULL);

}

#endif
#endif
