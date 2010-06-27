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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#include "bra_act.h"
#include "bra_cfg.h"
#include "bra_win.h"
#include "bra_cmn.h"

#include "brs_if.h"

#include "msf_url.h"
#include "msf_lib.h"
#include "msf_cfg.h"
#include "msf_cmmn.h"


/************************************************************
 * Local Types
 ************************************************************/

typedef struct {
  int enabled;
  char *url;
  char *mime_type;
  char *file_name;
  char *file_path;
  MSF_INT32 drm;
}bra_act_object_action_t;

typedef struct bra_act_list_t{
  int idx;
  MSF_INT32 action_id;
  struct bra_act_list_t *next;
}bra_act_list_t;

/************************************************************
 * Global Variables
 ************************************************************/

static bra_act_object_action_t bra_act_object_action;
static msf_pck_handle_t *bra_act_handle;
static bra_act_list_t  *bra_act_list;

/**********************************************************************
 * Local functions
 **********************************************************************/
/*
 * Extract file name from url
 *
 */
static char*
bra_act_extract_file_name(char* url)
{
  char *s;
  char *p;
  char *file_name;

  s = msf_url_get_path (MSF_MODID_BRA, url);
  if ((s == NULL) || (*s == '\0'))
  {
    return NULL;
  }
  else
  {
    p = s + strlen (s);
    while ((*p != '/') && (*p != '\\') && (p != s))
      p--;
     p++;
    file_name = msf_cmmn_strdup (MSF_MODID_BRA, p);
    BRA_FREE (s);
    return file_name;
  }
}

static void
bra_act_add_action_to_list (int idx, MSF_INT32 action_id)
{
  bra_act_list_t *element;

  element = BRA_ALLOCTYPE (bra_act_list_t);
  element->idx = idx;
  element->action_id = action_id;
  element->next = bra_act_list;

  bra_act_list = element;  
}

static MSF_INT32
bra_act_find_action_id (int idx)
{
  bra_act_list_t *p;

  p = bra_act_list;

  while (p != NULL)
  {
    if (p->idx == idx)
      return p->action_id;
    p = p->next;
  }
  
  return -1;
}

static void
bra_act_delete_action_list (void)
{
  bra_act_list_t *p;

  while (bra_act_list != NULL)
  {
    p = bra_act_list;
    bra_act_list = bra_act_list->next;
    BRA_FREE (p);
  }
  bra_act_list = NULL;
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/

void
bra_act_init (void)
{
  bra_act_list = NULL;
  bra_act_handle = msf_act_init (MSF_MODID_BRA);

  bra_act_object_action.enabled = 0;
  bra_act_object_action.file_name = NULL;
  bra_act_object_action.url       = NULL;
  bra_act_object_action.mime_type = NULL;
  bra_act_object_action.file_path = NULL;
  bra_act_object_action.drm       = MSF_PERMISSION_FORWARD_BLOCKED;
}

void
bra_act_terminate (void)
{
  bra_act_delete_action_list ();
  if (bra_act_handle)
  {
    msf_act_terminate (bra_act_handle);
    bra_act_handle = NULL;
  }
}

/*
 * This function enables action on object options and should be called
 * when an object is selected
 *
 * PARAMETERS
 *
 * url       : Url to the object
 * mime_type : The mime type of the object
 * file_path : The file path of the object
 *
 * RETURN    : void
 */
void
bra_act_enable_object_action (char *url, char *mime_type, char *file_path, MSF_INT16 drm_restriction)
{
  char *substr = NULL;
  bra_act_object_action.file_name = bra_act_extract_file_name(url);
  bra_act_object_action.url       = msf_cmmn_strdup(MSF_MODID_BRA, url);
  if(mime_type != NULL)
    substr = strchr(mime_type, ';');
  if(substr != NULL)
    bra_act_object_action.mime_type = msf_cmmn_strndup(MSF_MODID_BRA, mime_type, substr - mime_type);
  else
    bra_act_object_action.mime_type = msf_cmmn_strdup(MSF_MODID_BRA, mime_type);
  bra_act_object_action.file_path = msf_cmmn_strdup(MSF_MODID_BRA, file_path);
  if (drm_restriction == BRS_FOCUSED_ELEM_DRM_RESTRICTION_FWD_LOCK)
    bra_act_object_action.drm = MSF_PERMISSION_FORWARD_BLOCKED;
  else
    bra_act_object_action.drm = MSF_PERMISSION_NONE_BLOCKED;

  bra_act_object_action.enabled = 1;
}

/*
 * This function disables action on object option and must be called  
 * when no object is selected
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_act_disable_object_action (void)
{
  if( bra_act_object_action.enabled == 1)
  {
    BRA_FREE (bra_act_object_action.url);
    bra_act_object_action.url = NULL;
    BRA_FREE (bra_act_object_action.mime_type);
    bra_act_object_action.mime_type = NULL;
    BRA_FREE (bra_act_object_action.file_name);
    bra_act_object_action.file_name = NULL;
    BRA_FREE (bra_act_object_action.file_path);
    bra_act_object_action.file_path = NULL;

    bra_act_object_action.enabled = 0;
    bra_act_object_action.drm     = MSF_PERMISSION_FORWARD_BLOCKED;

    bra_act_delete_action_list();
  }
  
}

/*
 * Call this function when act package is finished
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_act_finished (MSF_INT32 act_id)
{
  msf_pck_result_t    act_result;

  msf_act_get_result (bra_act_handle, act_id, &act_result);
  msf_act_result_free (bra_act_handle, &act_result);
}


/* Add Object Actions: */
int
bra_act_add_actions (MSF_UINT32 window, int i)
{
  MSF_INT32           act_id;
  msf_pck_result_t    act_result;
  int                 action_nbr;
  msf_act_result_get_actions_t *actions;

  if( bra_act_object_action.enabled == 1)
  {
    bra_act_delete_action_list ();

    act_id = msf_act_get_actions (bra_act_handle, bra_act_object_action.mime_type, 0);
    msf_act_get_result (bra_act_handle, act_id, &act_result);

    actions = (msf_act_result_get_actions_t *)act_result._u.data;
    for (action_nbr = 0; action_nbr < (actions->num_actions) ; action_nbr++)
    {
      MSF_WIDGET_CHOICE_SET_ELEMENT ( window,
                                      i,
                                      MSF_WIDGET_STRING_GET_PREDEFINED(actions->action_list[action_nbr].string_id),
                                      0, bra_cmn_get_list_num_image(i), 0, TRUE);
      i++;                                      
      bra_act_add_action_to_list (action_nbr, actions->action_list[action_nbr].action_id);
    }
    msf_act_result_free (bra_act_handle, &act_result);
    return action_nbr;
  }
  return 0;
}

int
bra_act_get_num_actions (void)
{
  MSF_INT32           act_id;
  msf_pck_result_t    act_result;
  msf_act_result_get_actions_t *actions;
  int num;

  if( bra_act_object_action.enabled == 1)
  {
    act_id = msf_act_get_actions (bra_act_handle, bra_act_object_action.mime_type, 0);
    msf_act_get_result (bra_act_handle, act_id, &act_result);
    actions = (msf_act_result_get_actions_t *)act_result._u.data;
	num = actions->num_actions;
	msf_act_result_free(bra_act_handle, &act_result);
	
    return num;
  }

  return 0;
}

void
bra_act_execute_object_action (int idx)
{
  MSF_INT32             act_id;
  msf_pck_result_t      result;
  long                  data_len = 0;
  
  if( bra_act_object_action.enabled == 1)
  {
    data_len = HDIa_fileGetSize(bra_act_object_action.file_path);
    
    if (bra_act_object_action.drm == MSF_PERMISSION_FORWARD_BLOCKED)
      act_id = msf_act_object_action_drm (bra_act_handle,
                           bra_act_find_action_id (idx),
                           bra_act_object_action.mime_type,
                           MsfResourceFile,
                           NULL,
                           data_len,
                           bra_act_object_action.file_path,
                           NULL,
                           bra_act_object_action.file_name,
                           bra_act_object_action.drm,
                           bra_win_get_screen (),
                           "application/vnd.oma.drm.content",
                           NULL,
                           0);
    else
            act_id = msf_act_object_action_drm (bra_act_handle,
                           bra_act_find_action_id (idx),
                           bra_act_object_action.mime_type,
                           MsfResourceFile,
                           NULL,
                           data_len,
                           bra_act_object_action.file_path,
                           NULL,
                           bra_act_object_action.file_name,
                           bra_act_object_action.drm,
                           bra_win_get_screen (),
                           NULL,
                           NULL,
                           0);

    msf_act_get_result (bra_act_handle, act_id, &result);
    msf_act_result_free (bra_act_handle, &result);
  }
}

msf_pck_handle_t*
bra_act_get_handle (void)
{
  return bra_act_handle;
}


int
bra_act_add_actions_mime (MSF_UINT32 window, int i, char *mime, int exclude_save)
{
  MSF_INT32           act_id;
  msf_pck_result_t    act_result;
  int                 action_nbr;
  msf_act_result_get_actions_t *actions;
  int                 idx = 0;


  act_id = msf_act_get_actions (bra_act_handle, mime, 0);
  msf_act_get_result (bra_act_handle, act_id, &act_result);

  actions = (msf_act_result_get_actions_t *)act_result._u.data;
  for (action_nbr = 0; action_nbr < (actions->num_actions) ; action_nbr++)
  {
   
    char *text;
    text = BRA_ALLOC (MSF_WIDGET_STRING_GET_LENGTH(MSF_WIDGET_STRING_GET_PREDEFINED(actions->action_list[action_nbr].string_id), 1, MsfUtf8) + 1);
    MSF_WIDGET_STRING_GET_DATA (MSF_WIDGET_STRING_GET_PREDEFINED(actions->action_list[action_nbr].string_id), text, MsfUtf8);

    if (!exclude_save || strcmp(text, "Save As"))
    {
      MSF_WIDGET_CHOICE_SET_ELEMENT ( window,
                                      (i++),
                                      MSF_WIDGET_STRING_GET_PREDEFINED(actions->action_list[action_nbr].string_id),
                                      0, 0, 0, TRUE);
      bra_act_add_action_to_list (idx++, actions->action_list[action_nbr].action_id);
    }

    BRA_FREE (text);
  }
  msf_act_result_free (bra_act_handle, &act_result);
  return i + action_nbr;
}

int
bra_act_get_num_actions_mime (char *mime)
{
  MSF_INT32           act_id;
  msf_pck_result_t    act_result;
  msf_act_result_get_actions_t *actions;
  int nbr_of_actions = 0;


  act_id = msf_act_get_actions (bra_act_handle, mime, 0);
  msf_act_get_result (bra_act_handle, act_id, &act_result);

  actions = (msf_act_result_get_actions_t *)act_result._u.data;
  nbr_of_actions = actions->num_actions;
  msf_act_result_free (bra_act_handle, &act_result);

  return nbr_of_actions;
}

void
bra_act_execute_object_action_mime (int idx, char *mime, char *file_path, char *file_name)
{
  MSF_INT32             act_id;
  msf_pck_result_t      result;
  char                 *src_path;

  src_path = BRA_ALLOC (strlen(file_path) + strlen(file_name) + 1);
  strcpy (src_path, file_path);
  strcat (src_path, file_name);

  act_id = msf_act_object_action (bra_act_handle,
                         bra_act_find_action_id (idx),
                         mime,
                         MsfResourceFile,
                         NULL,
                         0,
                         src_path,
                         NULL,
                         file_name,
                         MSF_PERMISSION_NONE_BLOCKED,
                         bra_win_get_screen ());

  BRA_FREE (src_path);

  msf_act_get_result (bra_act_handle, act_id, &result);
  msf_act_result_free (bra_act_handle, &result);
}


