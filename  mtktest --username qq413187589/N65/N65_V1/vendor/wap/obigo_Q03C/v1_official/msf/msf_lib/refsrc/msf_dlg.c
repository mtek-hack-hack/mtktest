/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_dlg.c
 *
 * Dialog package:
 * 
 *
 * Created by Simon Magnusson, May 16 2003.
 *
 * Revision  history:
 */


#include "msf_core.h"
#include "msf_log.h"
#include "msf_wid.h"
#include "msf_lib.h"
#include "msf_dlg.h"
#include "msf_afi.h"
#include "msf_mem.h"
#include "msf_pck.h"
#include "msf_pipe.h"

#ifdef WAP_SUPPORT
/* We made some modification to handle save as with file exists 
 * Some modifications are deprecated after we use HDIa_widgetExtFmgrGetSaveFileName
 * instead of msf_dlg package to select file path.
 */
#include "widget_extension.h"
#include "msf_file.h"
#include "msf_env.h"
#endif /* WAP_SUPPORT */

#ifdef MSF_CONFIG_DRE
#include "msf_dre.h"
#endif

/*************************************************
 * Defines
 *************************************************/
#define MSF_DLG_STATE_OPEN_NAVIGATE                   1
#define MSF_DLG_STATE_OPEN_NAVIGATE_DELAYED           2
#define MSF_DLG_STATE_OPEN_FINISHED                   3
#define MSF_DLG_STATE_SAVE_AS_NAVIGATE                4
#define MSF_DLG_STATE_SAVE_AS_NAVIGATE_DELAYED        5
#define MSF_DLG_STATE_SAVE_AS_EDIT_NAME               6
#define MSF_DLG_STATE_SAVE_AS_FINISHED                7
#define MSF_DLG_STATE_SAVE_AS_FILE_EXISTS_DELAYED     8
#define MSF_DLG_STATE_SAVE_AS_EXISTS_DIALOG           9
#define MSF_DLG_STATE_SAVE_AS_EXISTS_DELETE_DELAYED  10
#define MSF_DLG_STATE_SAVE_AS_MSG_DLG                11
#define MSF_DLG_STATE_SAVE_AS_ICONS_DELAY            12
#define MSF_DLG_STATE_OPEN_ICONS_DELAY               13
#define MSF_DLG_STATE_NEW_DIR_NAME_EDIT              14
#define MSF_DLG_STATE_NEW_DIR_AFI_DELAYED            15
#define MSF_DLG_STATE_ERROR_POPUP                    16
#define MSF_DLG_STATE_SAVE_AS_CANNOT_SAVE            17
#define MSF_DLG_STATE_SAVE_FILED_LOCKED              18
#ifdef WAP_SUPPORT
#define MSF_DLG_STATE_SAVE_AS_FMGR					 20
#define MSF_DLG_STATE_SAVE_AS_FMGR_FINISHED			 21
#endif

#define MSF_DLG_PREVIEW_STATE_IDLE                    1
#define MSF_DLG_PREVIEW_STATE_SLEEP                   2
#define MSF_DLG_PREVIEW_STATE_BUSY                    3

#define MSF_DLG_PREVIEW_TIMER                         20   /* preview delay in tenth of seconds */

#define MSF_DLG_CONTENT_TYPE_IMAGE                    "image/jpeg,image/gif,image/png,image/vnd.wap.wbmp,image/bmp"
#define MSF_DLG_CONTENT_MAX_SIZE                      300000 /* max size in bytes of content to preview */

#define MSF_DLG_PIPE_STATE_IDLE                 0
#define MSF_DLG_PIPE_STATE_AFI_OPEN_BUSY        1
#define MSF_DLG_PIPE_STATE_AFI_READ_BUSY        2
#define MSF_DLG_PIPE_STATE_PIPE_FULL            3
#define MSF_DLG_PIPE_STATE_AFI_CLOSE_BUSY       4

#define MSF_DLG_PIPE_BFR_SIZE                   500

#define MSF_DLG_ICONS_NOT_LOADED                -1

typedef struct msf_dlg_action_st {
  struct msf_dlg_action_st   *next;
  MsfActionHandle             handle;
  MsfActionType               type;
} msf_dlg_action_t;


typedef struct msf_dlg_gadget_st {
  struct msf_dlg_gadget_st   *next;
  MsfGadgetHandle             handle;
} msf_dlg_gadget_t;


typedef struct msf_dlg_window_st {
  struct msf_dlg_window_st     *next;
  MsfWindowHandle               handle;
  msf_dlg_action_t             *action;
  msf_dlg_gadget_t             *gadget;
} msf_dlg_window_t;


/* Pipe from file */
typedef struct msf_dlg_pipe_from_file_st {
  int                     state;
  int                     pipe_handle;
  char                    *file_name;
  int                     file_handle;
  MSF_INT32               afi_id;
  unsigned char*          bfr;
  long                    bytes_read;
  long                    bytes_written;
  long                    current_bytes_read;
  MSF_INT32               op_result;
} msf_dlg_pipe_from_file_t;


typedef struct msf_dlg_op_st {
  struct msf_dlg_op_st    *next;
  MSF_UINT32              id;          /* operation identifier */
  MSF_INT8                type;
  int                     state;
  int                     prev_state;
  void                    *priv_data;
  long                    status;    /* status of operation */
  int                     permission;
  char*                   mime_types;
  char*                   file_name;
  char*                   default_name;
  char*                   entered_name;
  int                     current_focus;
  msf_dlg_window_t        *window;
  MsfScreenHandle         screen;
  MSF_INT32               afi_id;
  MSF_INT32               bit_flag;
  msf_afi_result_dir_entries_t *dir_entries;
  int                     preview_state;
  MsfPattern              default_pattern;
  msf_dlg_pipe_from_file_t *pipe_from_file;
  int                     current_timer_id;
  MsfImageHandle          preview_image_handle;
#ifdef WAP_SUPPORT
  MSF_UINT8                  modid;
#endif
} msf_dlg_op_t;


typedef struct msf_dlg_handle_st {
  struct msf_dlg_handle_st  *next, *prev;
  MSF_UINT8                  modid;
  msf_dlg_op_t              *op;
  msf_pck_handle_t          *afi_handle;
  MsfImageHandle             folder_image;
  MsfImageHandle             file_image;
  msf_icon_list_t           *icons;
  MSF_INT16                 n_items;
} msf_dlg_handle_t;

typedef struct msf_dlg_index_list_st{
  struct  msf_dlg_index_list_st  *next;
  int     index;
} msf_dlg_index_list_t;


/*************************************************
 * Configuration
 *************************************************/

#define MSF_DLG_MENU_SIZE_WIDTH         0.9
#define MSF_DLG_MENU_SIZE_HEIGHT        0.9
#define MSF_DLG_TEXT_POSITION           {10,10}
#define MSF_DLG_TEXT_HEIGHT             20


/* Bitmap used as folder icon */
/* BMP 24-bit */
const unsigned char msf_dlg_folder_image[] = {
0x42, 0x4d, 0x2a, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x76, 0x0, 0x0, 0x0, 0x28, 
0x0, 0x0, 0x0, 0x11, 0x0, 0x0, 0x0, 0xf, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4, 0x0, 0x0, 
0x0, 0x0, 0x0, 0xb4, 0x0, 0x0, 0x0, 0xc4, 0xe, 0x0, 0x0, 0xc4, 0xe, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 
0x80, 0x0, 0x0, 0x0, 0x80, 0x80, 0x0, 0x80, 0x0, 0x0, 0x0, 0x80, 0x0, 0x80, 0x0, 0x80, 
0x80, 0x0, 0x0, 0x80, 0x80, 0x80, 0x0, 0xc0, 0xc0, 0xc0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 
0xff, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0x0, 0xff, 
0xff, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 
0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 
0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 0xfb, 0xbb, 0xbb, 0xbb, 
0xbb, 0xbb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 0xfb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0, 0xf0, 
0x0, 0x0, 0x0, 0xf3, 0xfb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0x73, 
0xfb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 0xfb, 0xbb, 0xbb, 0xbb, 
0xbb, 0xbb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 0xfb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0, 0xf0, 
0x0, 0x0, 0x0, 0xf3, 0xfb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xb0, 0xf0, 0x0, 0x0, 0x0, 0xf3, 0x88, 0x88, 0x88, 0x83, 
0x33, 0x33, 0x3f, 0xf0, 0x0, 0x0, 0x0, 0xff, 0x3f, 0xff, 0x88, 0x30, 0xff, 0xff, 0xff, 0xf0, 
0x0, 0x0, 0x0, 0xff, 0xf3, 0x33, 0x33, 0xf, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0xff, 
};
const unsigned short msf_dlg_folder_image_size = 298;

const unsigned char msf_dlg_file_image[] = {
0x42, 0x4d, 0x6, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x76, 0x0, 0x0, 0x0, 0x28, 
0x0, 0x0, 0x0, 0xf, 0x0, 0x0, 0x0, 0x12, 0x0, 0x0, 0x0, 0x1, 0x0, 0x4, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x90, 0x0, 0x0, 0x0, 0xc4, 0xe, 0x0, 0x0, 0xc4, 0xe, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 
0x80, 0x0, 0x0, 0x0, 0x80, 0x80, 0x0, 0x80, 0x0, 0x0, 0x0, 0x80, 0x0, 0x80, 0x0, 0x80, 
0x80, 0x0, 0x0, 0x80, 0x80, 0x80, 0x0, 0xc0, 0xc0, 0xc0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 
0xff, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0xff, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0x0, 0xff, 
0xff, 0x0, 0x0, 0xff, 0xff, 0xff, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xf7, 0x88, 0x88, 0x88, 0x88, 0x88, 0x80, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xf0, 0xf7, 0xf0, 0x0, 0x0, 0x0, 0xf, 0x80, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xf0, 0xf7, 0xf0, 0x0, 0x0, 0x0, 0xf, 0x80, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xf0, 0xf7, 0xf0, 0x0, 0x0, 0x0, 0xf, 0x80, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xf0, 0xf7, 0xf0, 0x0, 0x0, 0x0, 0xf, 0x80, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xf0, 0xf7, 0xf0, 0x0, 0x0, 0xf, 0xff, 0x80, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0xf0, 0xf7, 0xf0, 0x0, 0x0, 0xf, 0x8f, 0x7f, 0xf0, 0xf7, 
0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xf0, 0xf7, 0x77, 0x77, 0x77, 0x77, 0x7f, 0xff, 0xf0, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xff, 
};
const unsigned short msf_dlg_file_image_size = 262;

#ifdef WAP_SUPPORT
msf_dlg_op_t* msf_act_dlg_op_list;

static void msf_dlg_add_act_dlg_op(msf_dlg_handle_t* dlg, msf_dlg_op_t *op)
{
  op->modid = dlg->modid;
  msf_act_dlg_op_list = op;
}

static void msf_dlg_remove_act_dlg_op(msf_dlg_op_t *op)
{
  if(msf_act_dlg_op_list == op)
    msf_act_dlg_op_list = op->next;
}

void msf_dlg_destroy_act_dlg_op(void)
{
  msf_dlg_op_t *op;
  op = msf_act_dlg_op_list;

  while(op)
  {
  	if (op->window && op->window->action)
  	{
    	HDIc_widgetAction(op->modid, op->window->handle, op->window->action->handle);
	}
    op = op->next;
  }
}
#endif

/**********************************************************************
 * Function prototypes
 **********************************************************************/

static void
create_error_msg_dialog ( msf_dlg_handle_t *handle, msf_dlg_op_t *op, 
                          MsfStringHandle title, MsfStringHandle str);


/**********************************************************************
 * Local functions
 **********************************************************************/


static int /* returns TRUE/FALSE*/
file_name_valid(char *name)
{
  int name_len = strlen(name);
  int i;
  if (name_len<1)
    return FALSE;
  for (i = 0 ; i < name_len ; i++){
    if (name[i] == MSF_USER_FOLDER_ID_CHAR)
      return FALSE;
  }
  return TRUE;
}

static msf_dlg_op_t *
find_op_by_id (msf_dlg_handle_t *handle, MSF_UINT32 id)
{
  msf_dlg_op_t *op = handle->op;

  while (op) {
    if (op->id == id)
      return op;
    op = op->next;
  }
  return NULL;
}

static msf_dlg_action_t *
find_action_by_type (msf_dlg_action_t *handle, MsfActionType type)
{

  while (handle) {
    if (handle->type == type)
      return handle;
    handle = handle->next;
  }
  return NULL;
}


static char*
get_mime_from_attr_list(msf_pck_attr_list_t *attrlist)
{ 
  msf_pck_attr_list_t *attribute;
  attribute = attrlist;
  while (attribute) {
    switch (attribute->attribute){
    case MSF_PCK_ATTRIBUTE_MIME:
      if (attribute->type == MSF_PCK_ATTR_TYPE_STRING)
        return attribute->_u.s;
    }
    attribute = attribute->next;
  }
  return NULL;
}

#ifdef MSF_CONFIG_DRE
static msf_pck_attr_list_t*
get_drm_from_attr_list(msf_pck_attr_list_t *attrlist)
{ 
  msf_pck_attr_list_t *attribute;
  attribute = attrlist;
  while (attribute) {
    switch (attribute->attribute){
    case MSF_PCK_ATTRIBUTE_DRM:
      return attribute;
    }
    attribute = attribute->next;
  }
  return NULL;
}
#endif

/* Returns TRUE if Forward Locked, else FALSE */
static int
is_forward_locked(msf_pck_attr_list_t *attrlist)
{
  msf_pck_attr_list_t *attribute;
  attribute = attrlist;
  while (attribute) {
    switch (attribute->attribute){
    case MSF_PCK_ATTRIBUTE_FLAGS:
      if (attribute->_u.i & MSF_PCK_FLAG_DRM_FORWARD_LOCK)
        return TRUE;
    }
    attribute = attribute->next;
  }
  return FALSE;
}

static MsfImageHandle
get_icon_handle (msf_dlg_handle_t *handle, const char* mime_type)
{
  int i = 0;
  MSF_UINT32 hash1, hash2;
  MsfCreateData image_data;

  if (mime_type == NULL)
    return 0;

  hash1 = msf_cmmn_strhash (mime_type, strlen (mime_type));
  for (i = 0; i < handle->n_items; i++){
    if (hash1 != handle->icons[i].mime_hash)
      continue;

    if (strcmp(mime_type, handle->icons[i].s_mime) != 0)
      continue;
    if (handle->icons[i].resource_type == MSF_ICON_RESOURCE_TYPE_PREDEFINED){
      return HDIa_widgetImageGetPredefined (handle->icons[i].resource_int_id, NULL);
    }
    else{
      image_data.resource = handle->icons[i].resource_str_id;
      return HDIa_widgetImageCreateFormat(handle->modid, &image_data,mime_type,MsfResourceFile,0);
    }
  }
  /*No specific type was found. Look for general types*/
  {
    char *end;
    char *s;
    int   found = -1;

    end = strchr(mime_type,'/');

    if (end == NULL)
      return 0;

    hash1 = msf_cmmn_strhash ("*/*", strlen ("*/*"));
    s = MSF_MEM_ALLOC (handle->modid, end - mime_type + 3);
    strncpy(s,mime_type, end - mime_type);
    s[end - mime_type] = '\0';
    strcat (s,"/*");
    hash2 = msf_cmmn_strhash (s, strlen (s));

    for (i = 0; i < handle->n_items; i++){
      if (hash1 == handle->icons[i].mime_hash){
        if (strcmp("*/*", handle->icons[i].s_mime) == 0){
          found = i;
          continue;
        }
      }
      if (hash2 == handle->icons[i].mime_hash){
        if (strcmp(s, handle->icons[i].s_mime) == 0){
          found = i;
          break;
        }
      }
    }

    MSF_MEM_FREE (handle->modid, s);
    /*Check if found*/
    if (found < 0)
      return 0;
      
    if (handle->icons[found].resource_type == MSF_ICON_RESOURCE_TYPE_PREDEFINED){
      return HDIa_widgetImageGetPredefined (handle->icons[found].resource_int_id, NULL);
    }
    else{
      image_data.resource = handle->icons[found].resource_str_id;
      return HDIa_widgetImageCreateFormat(handle->modid, &image_data,mime_type,MsfResourceFile,0);
    }

  }


  return 0;
}
static int
mime_type_in_list (const char *mime_type, const char *mime_list)
{  
  do {
    char *m = (char *) mime_type;
    
    while (mime_list != NULL && *mime_list != '\0') {

      if (*m == '\0')
        return TRUE;
      
      if (*mime_list++ != *m++)
        break;

      if ((*mime_list == '/') && (mime_list[1] == '*'))
        return TRUE;
    }
    
    if ((*m == '\0') && (*mime_list == '\0'))
      return TRUE;

  } while (mime_list != NULL && *mime_list != '\0');
   
  return FALSE;
}


static void
free_dir_entries (MSF_UINT8 modid, msf_afi_result_dir_entries_t *result){
  int i=0;  
  for (i=0 ; i < result->num_entries ; i++){
    if (result->entry_list[i].attr_list)
      msf_pck_attr_free (modid, result->entry_list[i].attr_list);
    if (result->entry_list[i].name)
      MSF_MEM_FREE(modid, result->entry_list[i].name);
  }
  MSF_MEM_FREE(modid, result);
}

static msf_dlg_gadget_t *
get_new_gadget (msf_dlg_handle_t *handle, msf_dlg_window_t *window)
{
  msf_dlg_gadget_t *gadget = MSF_MEM_ALLOCTYPE (handle->modid, msf_dlg_gadget_t);

  gadget->handle = 0;

  /* insert new gadget first in list */
  gadget->next = window->gadget;
  window->gadget = gadget;
  return gadget;
}

static void
free_dlg_gadget(msf_dlg_handle_t *handle, msf_dlg_window_t *window, msf_dlg_gadget_t *gadget)
{
  msf_dlg_gadget_t *temp_gadget = window->gadget;
  msf_dlg_gadget_t *prev_gadget = NULL;

  /*Remove gadget*/
  while (temp_gadget != gadget) {
    prev_gadget = temp_gadget;
    temp_gadget = temp_gadget->next;
  }
  if (prev_gadget)
    prev_gadget->next = gadget->next;
  else
    window->gadget = gadget->next;

  /* Free gadget*/
  MSF_WIDGET_REMOVE (window->handle, gadget->handle); 
  MSF_WIDGET_RELEASE(gadget->handle); 
  MSF_MEM_FREE(handle->modid, gadget);
  
}

static msf_dlg_action_t *
get_new_action (msf_dlg_handle_t *handle, msf_dlg_window_t *window, MsfActionType type)
{
  msf_dlg_action_t *action = MSF_MEM_ALLOCTYPE (handle->modid, msf_dlg_action_t);

  action->handle = 0;
  action->type = type;
  /* insert new action first in list */
  action->next = window->action;
  window->action = action;
  return action;
}

static void
free_dlg_action(msf_dlg_handle_t *handle, msf_dlg_window_t *window, msf_dlg_action_t *action)
{
  msf_dlg_action_t *temp_action = window->action;
  msf_dlg_action_t *prev_action = NULL;

  /*Remove action*/
  while (temp_action != action) {
    prev_action = temp_action;
    temp_action = temp_action->next;
  }
  if (prev_action)
    prev_action->next = action->next;
  else
    window->action = action->next;

  /* Free action*/
  MSF_WIDGET_REMOVE (window->handle, action->handle); 
  MSF_WIDGET_RELEASE(action->handle); 
  MSF_MEM_FREE(handle->modid, action);
  
}

static msf_dlg_window_t *
get_new_window (msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  msf_dlg_window_t *window = MSF_MEM_ALLOCTYPE (handle->modid, msf_dlg_window_t);

  window->handle = 0;
  window->action = NULL;
  window->gadget = NULL;

  /* insert new window first in list */
  window->next = op->window;
  op->window = window;
  return window;
}

static void
free_dlg_window(msf_dlg_handle_t *handle, msf_dlg_op_t *op, msf_dlg_window_t *window)
{
  msf_dlg_window_t *temp_window = op->window;
  msf_dlg_window_t *prev_window = NULL;

  /*Remove window*/

  while (temp_window != window) {
    prev_window = temp_window;
    temp_window = temp_window->next;
  }
  if (prev_window)
    prev_window->next = window->next;
  else
    op->window = window->next;

  /*Free window*/

  while (window->action)
    free_dlg_action(handle, window, window->action);
  while (window->gadget)
    free_dlg_gadget(handle, window, window->gadget);
  
  MSF_WIDGET_REMOVE (op->screen, window->handle); 
  MSF_WIDGET_RELEASE(window->handle);
  MSF_MEM_FREE(handle->modid, window);

}

static msf_dlg_op_t *
get_new_op (msf_dlg_handle_t *handle, MSF_INT8 type)
{
  static int msf_dlg_uniq_id = 1;

  msf_dlg_op_t *op = MSF_MEM_ALLOCTYPE (handle->modid, msf_dlg_op_t);
  
  op->dir_entries = NULL;
  op->id = msf_dlg_uniq_id++;
  op->type = type;
  op->state = 0;
  op->prev_state = 0;
  op->permission = 0;
  op->mime_types = NULL;
  op->file_name = NULL;
  op->default_name = NULL;
  op->entered_name = NULL;
  op->window = NULL;
  op->screen = 0;
  op->priv_data = NULL;
  op->status = MSF_DLG_RETURN_NOT_AVAILABLE;
  op->afi_id = -1;
  op->preview_state = MSF_DLG_PREVIEW_STATE_IDLE;
  op->current_timer_id = 0;
  op->pipe_from_file = NULL;
  op->preview_image_handle = 0;

  /* insert new operation first in list */
  op->next = handle->op;
  handle->op = op;

  return op;
}

static void
free_dlg_op(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  msf_dlg_op_t *temp_op = handle->op;
  msf_dlg_op_t *prev_op = NULL;

  /*Remove op*/

  while (temp_op != op) {
    prev_op = temp_op;
    temp_op = temp_op->next;
  }
  if (prev_op)
    prev_op->next = op->next;
  else
    handle->op = op->next;
  
  /*Free op*/

  while (op->window)
    free_dlg_window(handle, op, op->window);
  
  if (op->mime_types)
    MSF_MEM_FREE(handle->modid, op->mime_types);
  if (op->file_name)
    MSF_MEM_FREE(handle->modid, op->file_name);
  if (op->default_name)
    MSF_MEM_FREE(handle->modid, op->default_name);
  if (op->entered_name)
    MSF_MEM_FREE(handle->modid, op->entered_name);

  if (op->dir_entries)
    free_dir_entries(handle->modid, op->dir_entries);
 
#ifdef WAP_SUPPORT
  msf_dlg_remove_act_dlg_op(op);
#endif 
  MSF_MEM_FREE(handle->modid, op);
  op = NULL;
}

static MsfStringHandle
create_msf_string (MSF_UINT8 modid, const char* string)
{
  return MSF_WIDGET_STRING_CREATE( modid, string, MsfUtf8, strlen(string)+1, 0);
}

static void
msf_dlg_start_preview_timer(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  static int msf_dlg_uniq_timer_id = 5000;

  op->current_timer_id = msf_dlg_uniq_timer_id;
  MSF_TIMER_SET(handle->modid, msf_dlg_uniq_timer_id++, MSF_DLG_PREVIEW_TIMER);
  op->preview_state = MSF_DLG_PREVIEW_STATE_SLEEP;
}


static char *
msf_dlg_get_pipe_name_from_id(MSF_UINT8 modid, int id)
{
  char *id_string;
  id_string = MSF_MEM_ALLOC(modid, 24 );
  sprintf(id_string,"/MSF_DLG/%d",id);
  
  return id_string;
}

static void
msf_dlg_close_pipe_from_file(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  if (op->pipe_from_file){
    MSF_MEM_FREE(handle->modid, op->pipe_from_file->file_name);
    MSF_PIPE_CLOSE (op->pipe_from_file->pipe_handle);
    op->pipe_from_file->state = MSF_DLG_PIPE_STATE_IDLE;
    if (op->pipe_from_file->bfr)
      MSF_MEM_FREE(handle->modid, op->pipe_from_file->bfr);
    MSF_MEM_FREE(handle->modid, op->pipe_from_file);

  }
  op->pipe_from_file = NULL;
}

static char *
msf_dlg_get_pipe_from_file(msf_dlg_handle_t *handle, msf_dlg_op_t *op, const char *path)
{
  static msf_dlg_uniq_pipe_id = 5000;

  char *pipe_name = msf_dlg_get_pipe_name_from_id(handle->modid, msf_dlg_uniq_pipe_id);

  op->pipe_from_file = MSF_MEM_ALLOCTYPE(handle->modid,  msf_dlg_pipe_from_file_t);
  op->pipe_from_file->file_name = msf_cmmn_strdup(handle->modid, path);
  op->pipe_from_file->bfr = NULL;
  op->pipe_from_file->afi_id = -1;
  op->pipe_from_file->pipe_handle = MSF_PIPE_CREATE(handle->modid, pipe_name);
  
  switch (op->pipe_from_file->pipe_handle){
  case MSF_PIPE_ERROR_INVALID_PARAM:
  case MSF_PIPE_ERROR_EXISTS:
  case MSF_PIPE_ERROR_RESOURCE_LIMIT:
    return NULL;
  }
  
  op->pipe_from_file->state = MSF_DLG_PIPE_STATE_IDLE;
  op->pipe_from_file->op_result = MSF_AFI_OK;

  return pipe_name;
}


/* Returns TRUE if finished, otherwise FALSE */
static int
msf_dlg_execute_pipe_from_file(msf_dlg_handle_t *handle, msf_dlg_op_t *op, int pipe_handle)
{
  msf_pck_result_t  pck_result;
  long              return_result;

  if (pipe_handle)
    if (pipe_handle != op->pipe_from_file->pipe_handle)
      return FALSE;

  
  if (op->pipe_from_file->state == MSF_DLG_PIPE_STATE_AFI_OPEN_BUSY)
    goto open_afi_result;
  else if (op->pipe_from_file->state == MSF_DLG_PIPE_STATE_AFI_READ_BUSY){
    goto read_result;
  }
  else if (op->pipe_from_file->state == MSF_DLG_PIPE_STATE_PIPE_FULL){
    goto hdi_write;
  }
  else if (op->pipe_from_file->state == MSF_DLG_PIPE_STATE_AFI_CLOSE_BUSY){
    goto close_result;
  }

  op->pipe_from_file->bfr = NULL;

  op->pipe_from_file->afi_id = msf_afi_open (handle->afi_handle, op->pipe_from_file->file_name, MSF_AFI_RDONLY, NULL);
  if (op->pipe_from_file->afi_id < 0) {
    msf_dlg_close_pipe_from_file(handle, op);
    return TRUE;
  }

open_afi_result:
  if (msf_afi_get_result(handle->afi_handle, op->pipe_from_file->afi_id, &pck_result) == MSF_PACKAGE_BUSY){
    msf_afi_result_free(handle->afi_handle, &pck_result);
    op->pipe_from_file->state = MSF_DLG_PIPE_STATE_AFI_OPEN_BUSY;
    return FALSE;
  }
  else if (((msf_afi_result_open_t*)(pck_result._u.data))->result != MSF_AFI_OK){
    /*error*/
    msf_afi_result_free(handle->afi_handle, &pck_result);
    msf_dlg_close_pipe_from_file(handle, op);
    return TRUE;
  }
  op->pipe_from_file->file_handle = ((msf_afi_result_open_t*)(pck_result._u.data))->file_handle;
  msf_afi_result_free(handle->afi_handle, &pck_result);

  op->pipe_from_file->bfr = MSF_MEM_ALLOC(handle->modid, MSF_DLG_PIPE_BFR_SIZE);
  while (op->pipe_from_file->op_result != MSF_AFI_ERROR_EOF){
    op->pipe_from_file->afi_id = msf_afi_read (handle->afi_handle, op->pipe_from_file->file_handle, 
                                               op->pipe_from_file->bfr, MSF_DLG_PIPE_BFR_SIZE);

read_result:
    if (msf_afi_get_result(handle->afi_handle, op->pipe_from_file->afi_id, &pck_result) == MSF_PACKAGE_BUSY){
      msf_afi_result_free(handle->afi_handle, &pck_result);
      op->pipe_from_file->state =MSF_DLG_PIPE_STATE_AFI_READ_BUSY;
      return FALSE;
    }
    else if ((((msf_afi_result_read_t*)(pck_result._u.data))->result != MSF_AFI_OK) &&
             (((msf_afi_result_read_t*)(pck_result._u.data))->result != MSF_AFI_ERROR_EOF)){
      /*error*/
      op->pipe_from_file->state = MSF_DLG_PIPE_STATE_IDLE;
      op->pipe_from_file->afi_id = msf_afi_close (handle->afi_handle, op->pipe_from_file->file_handle);
      goto close_result;
    }
    op->pipe_from_file->op_result = ((msf_afi_result_read_t *)(pck_result._u.data))->result;
    op->pipe_from_file->current_bytes_read = ((msf_afi_result_read_t *)(pck_result._u.data))->data_len;
    msf_afi_result_free(handle->afi_handle, &pck_result);
    op->pipe_from_file->bytes_read += op->pipe_from_file->current_bytes_read;
    op->pipe_from_file->bytes_written = 0;
    while (op->pipe_from_file->bytes_written < op->pipe_from_file->current_bytes_read){

hdi_write:
          return_result = MSF_PIPE_WRITE(op->pipe_from_file->pipe_handle, op->pipe_from_file->bfr + op->pipe_from_file->bytes_written,
                                         op->pipe_from_file->current_bytes_read - op->pipe_from_file->bytes_written);
          if ( return_result == MSF_PIPE_ERROR_DELAYED){
            MSF_PIPE_POLL (op->pipe_from_file->pipe_handle);
            op->pipe_from_file->state = MSF_DLG_PIPE_STATE_PIPE_FULL;
            return FALSE;
          }
          else if (return_result < 0){
            /*error*/
            op->pipe_from_file->state = MSF_DLG_PIPE_STATE_IDLE;
            op->pipe_from_file->afi_id = msf_afi_close (handle->afi_handle, op->pipe_from_file->file_handle);
            goto close_result;
          }
          op->pipe_from_file->bytes_written += return_result;
    }
  }

  op->pipe_from_file->afi_id = msf_afi_close (handle->afi_handle, op->pipe_from_file->file_handle);

close_result:
  if (msf_afi_get_result(handle->afi_handle, op->pipe_from_file->afi_id, &pck_result) == MSF_PACKAGE_BUSY){
    msf_afi_result_free(handle->afi_handle, &pck_result);
    op->pipe_from_file->state = MSF_DLG_PIPE_STATE_AFI_CLOSE_BUSY;
    return FALSE;
  }
  else if (pck_result._u.i_val != MSF_AFI_OK){
    /*error*/
    msf_afi_result_free(handle->afi_handle, &pck_result);
    msf_dlg_close_pipe_from_file(handle, op);
    return TRUE;
  }

  msf_afi_result_free(handle->afi_handle, &pck_result);
  if (op->pipe_from_file->file_name)
    msf_dlg_close_pipe_from_file(handle, op);
  
  return TRUE;
}




/* Checks if path allows directories to be created. Returns TRUE or FALSE. */
static int
allow_create_new_dir(MSF_UINT8 modid, const char *path)
{
  char *urf;
  char *temp;
  int max_depth;
  int depth = 0;
  if (!path)
    return FALSE;
  if (strlen (path) < 5)
    return FALSE;
  if ((path[0] != '/') || (path[1] != MSF_USER_FOLDER_ID_CHAR))
    return FALSE;

  urf = msf_cmmn_strdup(modid, path);
  urf++;
  urf++;

  temp = strchr(urf, MSF_USER_FOLDER_ID_CHAR);
  *temp = '\0';
  max_depth = msf_pck_get_urf_max_depth (urf);
  temp++;
  while ((temp = strchr(temp,'/')) != NULL){
    depth++;
    temp++;
  }

  urf--;
  urf--;
  MSF_MEM_FREE(modid, urf);
  
  if (depth < max_depth)
    return TRUE;
  else
    return FALSE;
}

/* sorting alphabetic with folders first */
static int
is_after_alphabetic(const char *name1, int isdir1,
         const char *name2, int isdir2)
{
  if ((!isdir1) && isdir2)
    return TRUE;
  if (isdir1 && (!isdir2))
    return FALSE;

  if (msf_cmmn_strcmp_nc(name1, name2) >= 0)
    return TRUE;
  else
    return FALSE;

}

/* Returns a sorted list with indexnumbers.
   sorting : alphabetic
             by size
             by mime

*/
static msf_dlg_index_list_t *
sort_dir_entries(msf_dlg_handle_t *handle, msf_afi_result_dir_entries_t *dir_entries)
{
  int i;
  msf_dlg_index_list_t *insert_entry, *first_entry, *insert_before_entry,  *insert_after_entry;

  if (!dir_entries)
    return NULL;

  if (dir_entries->num_entries == 0)
    return NULL;

  first_entry = MSF_MEM_ALLOCTYPE(handle->modid, msf_dlg_index_list_t);
  first_entry->next = NULL;
  first_entry->index = 0;

  if (dir_entries->num_entries == 1)
    return first_entry;

  for (i = 1; i < dir_entries->num_entries ; i ++){
    insert_entry = MSF_MEM_ALLOCTYPE(handle->modid, msf_dlg_index_list_t);
    insert_entry->index = i;
    insert_before_entry = first_entry;
    insert_after_entry = NULL;
    while ((insert_before_entry != NULL) && 
           is_after_alphabetic(dir_entries->entry_list[i].name,
           dir_entries->entry_list[i].is_dir,
           dir_entries->entry_list[insert_before_entry->index].name,
           dir_entries->entry_list[insert_before_entry->index].is_dir
           ))
    {
      insert_after_entry = insert_before_entry;
      insert_before_entry = insert_before_entry->next;
    }
    /* ----------------------*/
    
    if (insert_after_entry)
      insert_after_entry->next = insert_entry;
    else
      first_entry = insert_entry;
    insert_entry->next = insert_before_entry;
  }
  return first_entry;
}

static void
delete_index_list(msf_dlg_handle_t *handle, msf_dlg_index_list_t *index_list)
{
  msf_dlg_index_list_t *entry;
  while (index_list){
    entry = index_list->next;
    MSF_MEM_FREE(handle->modid, index_list);
    index_list = entry;
  }
}

static int
get_index_from_index_list_number_restrict(msf_dlg_index_list_t *index_list, 
                                           int number, 
                                           msf_afi_result_dir_entries_t *dir_entries, 
                                           char *mime_list,
                                           int permission)
{
  int i=0;
  msf_dlg_index_list_t *entry = index_list;

  if (!entry)
    return -1;

  if (!entry){
skip_beginning_entry:
    entry = entry->next;
  }

  {
    char *mime_type = get_mime_from_attr_list(dir_entries->entry_list[entry->index].attr_list);
    if (mime_type)
      if (!(mime_type_in_list(mime_type, mime_list)))
        goto skip_beginning_entry;

#ifdef MSF_CONFIG_DRE
    {
      msf_pck_attr_list_t *dre_attr;
      if ((dre_attr = get_drm_from_attr_list(dir_entries->entry_list[entry->index].attr_list)) != NULL){
        if (msf_dre_check_permissions_data (NULL, dre_attr->_u.bv.b_value, dre_attr->_u.bv.b_len, permission)
                    == MSF_DRE_RETURN_PERMISSION_DENIED){
          goto skip_beginning_entry;
        }
      }
    }
#endif
    if ((permission == MSF_DLG_PERMISSION_FORWARD) && (is_forward_locked(dir_entries->entry_list[entry->index].attr_list)))
      goto skip_beginning_entry;

  }

  for (i = 0 ; i < number ;i ++){
    if (!entry)
      return -1;

skip_entry:
    entry = entry->next;
    
    {
      char *mime_type = get_mime_from_attr_list(dir_entries->entry_list[entry->index].attr_list);
      if (mime_type)
        if (!(mime_type_in_list(mime_type, mime_list)))
          goto skip_entry;

#ifdef MSF_CONFIG_DRE
      {
        msf_pck_attr_list_t *dre_attr;
        if ((dre_attr = get_drm_from_attr_list(dir_entries->entry_list[entry->index].attr_list)) != NULL){
          if (msf_dre_check_permissions_data (NULL, dre_attr->_u.bv.b_value, dre_attr->_u.bv.b_len, permission)
                      == MSF_DRE_RETURN_PERMISSION_DENIED){
            goto skip_entry;
          }
        }
      }
#endif
      if ((permission == MSF_DLG_PERMISSION_FORWARD) && (is_forward_locked(dir_entries->entry_list[entry->index].attr_list)))
        goto skip_entry;

    }

  }

  return entry->index;
}


static int
get_index_from_index_list_number(msf_dlg_index_list_t *index_list, int number)
{
  int i=0;
  msf_dlg_index_list_t *entry = index_list;

  if (!entry)
    return -1;
  for (i = 0 ; i < number ;i ++){
    if (!entry)
      return -1;
    entry = entry->next;
  }

  return entry->index;
}

static MSF_INT32
get_size_from_attr_list(msf_pck_attr_list_t *attrlist)
{ 
  msf_pck_attr_list_t *attribute;
  attribute = attrlist;
  while (attribute) {
    switch (attribute->attribute){
    case MSF_PCK_ATTRIBUTE_SIZE:
      return attribute->_u.i;
    }
    attribute = attribute->next;
  }
  return 0;
}

static char*
size_to_string (msf_dlg_handle_t *handle, MSF_INT32 size , char *notation, char* bString, char* KbString, char* MbString)
{ 
  long sizeMBytes ,sizekBytes, sizeBytes;
  char sizeBytesString[5] , sizekBytesString[5], sizeMBytesString[5], *return_string;
  if (size >= (1048567)) {
        sizeMBytes = (long) size / 1048567;
        sizekBytes = size % 1048567;
        sizekBytes = (long) ( ( (double)sizekBytes ) / 104856.7);
        sprintf (sizeMBytesString, "%ld", sizeMBytes);
        sprintf (sizekBytesString, "%ld", sizekBytes);
        return_string = MSF_MEM_ALLOC(handle->modid, strlen(sizeMBytesString) + strlen(sizekBytesString) + 
                                      strlen(notation) + strlen(MbString) + 1);
        strcpy(return_string, sizeMBytesString);
        strcat(return_string, notation);
        strcat(return_string, sizekBytesString);
        strcat(return_string, MbString);
        return return_string;
  }
  else if ( size >= 1024){
        sizekBytes = (long) size / 1024;
        sizeBytes = size % 1024;
        sizeBytes = (long) ( ( (double)sizeBytes ) / 102.4);
        sprintf (sizekBytesString, "%ld", sizekBytes);
        sprintf (sizeBytesString, "%ld", sizeBytes);
        return_string = MSF_MEM_ALLOC(handle->modid, strlen(sizekBytesString) + strlen(sizeBytesString) + 
                                      strlen(notation) + strlen(KbString) + 1);
        strcpy(return_string, sizekBytesString);
        strcat(return_string, notation);
        strcat(return_string, sizeBytesString);
        strcat(return_string, KbString);
        return return_string;
  }
  else{
        sizeBytes = size;
        sprintf (sizeBytesString, "%ld", sizeBytes);
        return_string = MSF_MEM_ALLOC(handle->modid, strlen(sizeBytesString) + strlen(bString) + 1);
        strcpy(return_string, sizeBytesString);
        strcat(return_string, bString);
        return return_string;
  }
}

static char *
get_string_from_file_size(msf_dlg_handle_t *handle, MSF_INT32 file_size)
{
  char *text_size2, *text_size3, *text_size4, *text_size5, *text_size;
  
  text_size2 = MSF_MEM_ALLOC(handle->modid, MSF_WIDGET_STRING_GET_LENGTH(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE2), 1, MsfUtf8)+1);
  MSF_WIDGET_STRING_GET_DATA(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE2), text_size2, MsfUtf8);
  text_size3 = MSF_MEM_ALLOC(handle->modid, MSF_WIDGET_STRING_GET_LENGTH(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE3), 1, MsfUtf8)+1);
  MSF_WIDGET_STRING_GET_DATA(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE3), text_size3, MsfUtf8);
  text_size4 = MSF_MEM_ALLOC(handle->modid, MSF_WIDGET_STRING_GET_LENGTH(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE4), 1, MsfUtf8)+1);
  MSF_WIDGET_STRING_GET_DATA(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE4), text_size4, MsfUtf8);
  text_size5 = MSF_MEM_ALLOC(handle->modid, MSF_WIDGET_STRING_GET_LENGTH(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE5), 1, MsfUtf8)+1);
  MSF_WIDGET_STRING_GET_DATA(MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_PROPERTIES_SIZE5), text_size5, MsfUtf8);
  text_size = size_to_string(handle, file_size, text_size2, text_size5, text_size3, text_size4);
  MSF_MEM_FREE(handle->modid, text_size2);
  MSF_MEM_FREE(handle->modid, text_size3);
  MSF_MEM_FREE(handle->modid, text_size4);
  MSF_MEM_FREE(handle->modid, text_size5);
  
  return text_size;
}


static void
add_entries_to_selectgroup(msf_dlg_handle_t *handle, MsfGadgetHandle selectgroup,
                       msf_afi_result_dir_entries_t *dir_entries, const char *current_dir)
{
  msf_dlg_index_list_t *index_list_first_entry = sort_dir_entries(handle, dir_entries);
  msf_dlg_index_list_t *index_list = index_list_first_entry;
  int i;
  int position = 0;
  while (index_list) {
    i = index_list->index;
    if (dir_entries->entry_list[i].is_dir == TRUE){
      char *localized_uf = msf_pck_get_local_uf (handle->modid, current_dir, dir_entries->entry_list[i].name);
      if (localized_uf){
        MsfStringHandle   msfStr = MSF_WIDGET_STRING_CREATE( handle->modid, localized_uf, MsfUtf8, strlen(localized_uf)+1, 0);
        MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++,
               msfStr, 0, handle->folder_image, 0, TRUE);
        MSF_MEM_FREE(handle->modid, localized_uf);
        MSF_WIDGET_RELEASE (msfStr);        
      }
      else {
        MsfStringHandle   msfStr = MSF_WIDGET_STRING_CREATE( handle->modid, dir_entries->entry_list[i].name, MsfUtf8, strlen(dir_entries->entry_list[i].name)+1, 0);
        MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++,
               msfStr, 0, handle->folder_image, 0, TRUE);
        MSF_WIDGET_RELEASE (msfStr);        
      }
    }
    else{
      char *text_size = get_string_from_file_size(handle, get_size_from_attr_list(dir_entries->entry_list[i].attr_list));
      MsfStringHandle   msfStr1 = MSF_WIDGET_STRING_CREATE( handle->modid, dir_entries->entry_list[i].name, MsfUtf8, strlen(dir_entries->entry_list[i].name)+1, 0);
      MsfStringHandle   msfStr2 = MSF_WIDGET_STRING_CREATE( handle->modid, text_size, MsfUtf8, strlen(text_size)+1, 0);
      MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++,
               msfStr1, msfStr2, get_icon_handle (handle, get_mime_from_attr_list(dir_entries->entry_list[i].attr_list)), 0, TRUE);
      MSF_MEM_FREE(handle->modid, text_size);
      MSF_WIDGET_RELEASE (msfStr1);        
      MSF_WIDGET_RELEASE (msfStr2);        
    }
    index_list = index_list->next;
  }
  delete_index_list(handle, index_list_first_entry);
}


static int /* Returns state*/
update_navigate_window_continue(msf_dlg_handle_t *handle, MsfGadgetHandle selectgroup,
                       const char* mime_types, msf_afi_result_dir_entries_t **dir_entries, msf_pck_result_t *pck_res, msf_dlg_op_t *op)
{
  int i;
  msf_afi_result_dir_entries_t  *result = (msf_afi_result_dir_entries_t*)pck_res->_u.data;
  msf_dlg_index_list_t *index_list_first_entry = sort_dir_entries(handle, result);
  msf_dlg_index_list_t *index_list = index_list_first_entry;
  int position = 0;

  op = op;
  if (*dir_entries)
    free_dir_entries(handle->modid, *dir_entries);
  *dir_entries = result;

  while (index_list) {
    char *mime_type;
    i = index_list->index;
    mime_type = get_mime_from_attr_list(result->entry_list[i].attr_list);
    if (mime_type)
      if (!(mime_type_in_list(mime_type, mime_types)))
        goto skip_entry;

#ifdef MSF_CONFIG_DRE
    {
      msf_pck_attr_list_t *dre_attr;
      if ((dre_attr = get_drm_from_attr_list(result->entry_list[i].attr_list)) != NULL){
        if (msf_dre_check_permissions_data (NULL, dre_attr->_u.bv.b_value, dre_attr->_u.bv.b_len, op->permission)
            == MSF_DRE_RETURN_PERMISSION_DENIED){
          goto skip_entry;
        }
      }
    }
#endif
    if ((op->permission == MSF_DLG_PERMISSION_FORWARD) && (is_forward_locked(result->entry_list[i].attr_list)))
        goto skip_entry;

    if (result->entry_list[i].is_dir == FALSE){
      char *text_size = get_string_from_file_size(handle, get_size_from_attr_list(result->entry_list[i].attr_list));
      MsfStringHandle   msfStr1 = MSF_WIDGET_STRING_CREATE( handle->modid, result->entry_list[i].name, MsfUtf8, strlen(result->entry_list[i].name)+1, 0);
      MsfStringHandle   msfStr2 = MSF_WIDGET_STRING_CREATE( handle->modid, text_size, MsfUtf8, strlen(text_size)+1, 0);
      MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++,
               msfStr1, msfStr2, get_icon_handle (handle, get_mime_from_attr_list(result->entry_list[i].attr_list)), 0, TRUE);
      MSF_MEM_FREE(handle->modid, text_size);
      MSF_WIDGET_RELEASE (msfStr1);        
      MSF_WIDGET_RELEASE (msfStr2);
    }
    else{
      char *localized_uf = msf_pck_get_local_uf (handle->modid, op->file_name, result->entry_list[i].name);
      if (localized_uf){
        MsfStringHandle   msfStr = MSF_WIDGET_STRING_CREATE( handle->modid, localized_uf, MsfUtf8, strlen(localized_uf)+1, 0);
        MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++, msfStr, 0, handle->folder_image, 0, TRUE);
        MSF_MEM_FREE(handle->modid, localized_uf);       
        MSF_WIDGET_RELEASE (msfStr);        
      }
      else{
        MsfStringHandle   msfStr = MSF_WIDGET_STRING_CREATE( handle->modid, result->entry_list[i].name, MsfUtf8, strlen(result->entry_list[i].name)+1, 0);
        MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++, msfStr, 0, handle->folder_image, 0, TRUE);
        MSF_WIDGET_RELEASE (msfStr);
      }
    }
skip_entry:
    index_list = index_list->next;
  }
  delete_index_list(handle, index_list_first_entry);
  if (position)
    MSF_WIDGET_CHOICE_SET_ELEM_STATE(selectgroup, 0, MSF_CHOICE_ELEMENT_SELECTED);
  op->current_focus = 0;

  { /* Possibly start preview timer */
    char *mime;
    int selection;

    if (position == 0)
      goto skip_preview;

    index_list = sort_dir_entries(handle, op->dir_entries);
    selection = get_index_from_index_list_number_restrict(index_list, 0, op->dir_entries, op->mime_types, op->permission);
    delete_index_list(handle, index_list);

    mime = get_mime_from_attr_list(op->dir_entries->entry_list[selection].attr_list);
    if (!msf_pck_mime_type_in_list(mime, MSF_DLG_CONTENT_TYPE_IMAGE))
      goto skip_preview;
    if (op->dir_entries->entry_list[selection].is_dir == TRUE)
      goto skip_preview;
    if (get_size_from_attr_list(op->dir_entries->entry_list[selection].attr_list) > MSF_DLG_CONTENT_MAX_SIZE)
      goto skip_preview;

    msf_dlg_start_preview_timer(handle, op);
  }

skip_preview:
  return MSF_DLG_STATE_OPEN_NAVIGATE;
}



static int /* Returns state*/
update_navigate_window(msf_dlg_handle_t *handle, MsfWindowHandle window_handle, MsfGadgetHandle selectgroup,
                       const char* mime_types, const char* path, msf_afi_result_dir_entries_t **dir_entries, msf_dlg_op_t *op)
{
  int                       i;  
  /*Remove all choice elements*/
  i = 0;
  while (MSF_WIDGET_CHOICE_SIZE(selectgroup))
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT(selectgroup,0);

  if (path== NULL)
  {
    msf_pck_root_folders_t    *root_folders;
    MSF_WIDGET_SET_TITLE (window_handle, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TEXT_ROOT_FOLDER));
    MSF_WIDGET_WINDOW_SET_PROPERTIES (window_handle, MSF_WINDOW_PROPERTY_TITLE);  
    msf_pck_get_urf_from_mime (handle->modid, mime_types,  &root_folders);
    for (i = 0; (i < root_folders->n_rf) ; i++) {    
      MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, i,
                      MSF_WIDGET_STRING_GET_PREDEFINED(root_folders->rf[i].str_id)
                      , 0, handle->folder_image, 0, TRUE);
    }
    if (root_folders->n_rf)
      MSF_WIDGET_CHOICE_SET_ELEM_STATE(selectgroup, 0, MSF_CHOICE_ELEMENT_SELECTED);
    op->current_focus = 0;
    MSF_MEM_FREE( handle->modid, root_folders);
    return MSF_DLG_STATE_OPEN_NAVIGATE;
  }
  else
  {
    msf_afi_result_dir_entries_t *result = NULL;
    msf_pck_result_t              pck_res;
    char                          *localized_path;
    MsfStringHandle               MsfStr;

    if (handle->n_items == MSF_DLG_ICONS_NOT_LOADED)
    {
      MSF_GET_ICONS (handle->modid, op->id, 0, NULL);
      return MSF_DLG_STATE_OPEN_NAVIGATE_DELAYED;
    }
    localized_path = msf_pck_get_localized_pathname (handle->modid, path);
    MsfStr = create_msf_string( handle->modid, localized_path);
    MSF_MEM_FREE(handle->modid, localized_path);
    MSF_WIDGET_SET_TITLE (window_handle, MsfStr );
    MSF_WIDGET_RELEASE (MsfStr);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (window_handle, MSF_WINDOW_PROPERTY_TITLE);
    op->afi_id = msf_afi_get_dir_entries (handle->afi_handle, path, 0);
    
    switch (msf_afi_get_result (handle->afi_handle, op->afi_id, &pck_res)){
      case MSF_PACKAGE_COMPLETED:
        result = (msf_afi_result_dir_entries_t*)pck_res._u.data;
        if (result->result == MSF_AFI_ERROR_DELAYED) {
          MSF_MEM_FREE(handle->modid, result);
          return MSF_DLG_STATE_OPEN_NAVIGATE_DELAYED;
        }
        else if (result->result == MSF_AFI_ERROR_PATH) {
          MSF_MEM_FREE(handle->modid, result);
          return MSF_DLG_STATE_OPEN_NAVIGATE;
        }
        else{
          msf_dlg_index_list_t *index_list_first_entry = sort_dir_entries(handle, result);
          msf_dlg_index_list_t *index_list = index_list_first_entry;
          int                   position = 0;
          /*got entries*/
          if (*dir_entries)
           free_dir_entries(handle->modid, *dir_entries);
          *dir_entries = result; /*save them*/
          i = 0;
          while (index_list) {
            char *mime_type;
            i = index_list->index;
            mime_type = get_mime_from_attr_list(result->entry_list[i].attr_list);
            if (mime_type)
              if (!(mime_type_in_list(mime_type, mime_types)))
                goto skip_entry;

#ifdef MSF_CONFIG_DRE
            {
              msf_pck_attr_list_t *dre_attr;
              if ((dre_attr = get_drm_from_attr_list(result->entry_list[i].attr_list)) != NULL){
                if (msf_dre_check_permissions_data (NULL, dre_attr->_u.bv.b_value, dre_attr->_u.bv.b_len, op->permission)
                    == MSF_DRE_RETURN_PERMISSION_DENIED){
                  goto skip_entry;
                }
              }
            }
#endif
            if ((op->permission == MSF_DLG_PERMISSION_FORWARD) && (is_forward_locked(result->entry_list[i].attr_list)))
              goto skip_entry;

            if (result->entry_list[i].is_dir == FALSE){
              char *text_size = get_string_from_file_size(handle, get_size_from_attr_list(result->entry_list[i].attr_list));
              MsfStringHandle   msfStr1 = MSF_WIDGET_STRING_CREATE( handle->modid, result->entry_list[i].name, MsfUtf8, strlen(result->entry_list[i].name)+1, 0);
              MsfStringHandle   msfStr2 = MSF_WIDGET_STRING_CREATE( handle->modid, text_size, MsfUtf8, strlen(text_size)+1, 0);
              MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++,
                       msfStr1, msfStr2, get_icon_handle (handle, get_mime_from_attr_list(result->entry_list[i].attr_list)), 0, TRUE);
              MSF_MEM_FREE(handle->modid, text_size);
              MSF_WIDGET_RELEASE (msfStr1);        
              MSF_WIDGET_RELEASE (msfStr2);
            }
            else{
              char *localized_uf = msf_pck_get_local_uf (handle->modid, op->file_name, result->entry_list[i].name);
              if (localized_uf){
                MsfStringHandle   msfStr = MSF_WIDGET_STRING_CREATE( handle->modid, localized_uf, MsfUtf8, strlen(localized_uf)+1, 0);
                MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++, msfStr, 0, handle->folder_image, 0, TRUE);
                MSF_MEM_FREE(handle->modid, localized_uf);       
                MSF_WIDGET_RELEASE (msfStr);        
              }
              else{
                MsfStringHandle   msfStr = MSF_WIDGET_STRING_CREATE( handle->modid, result->entry_list[i].name, MsfUtf8, strlen(result->entry_list[i].name)+1, 0);
                MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, position++, msfStr, 0, handle->folder_image, 0, TRUE);
                MSF_WIDGET_RELEASE (msfStr);
              }
            }
skip_entry:
            index_list = index_list->next;
          }
          delete_index_list(handle, index_list_first_entry);
          if (position)
            MSF_WIDGET_CHOICE_SET_ELEM_STATE(selectgroup, 0, MSF_CHOICE_ELEMENT_SELECTED);
          op->current_focus = 0;
           
          { /* Possibly start preview timer */
            char *mime;
            int selection;
            
            if (position == 0)
              goto skip_preview;

            index_list = sort_dir_entries(handle, op->dir_entries);
            selection = get_index_from_index_list_number_restrict(index_list, 0, op->dir_entries, op->mime_types, op->permission);
            delete_index_list(handle, index_list);

            mime = get_mime_from_attr_list(op->dir_entries->entry_list[selection].attr_list);
            if (!msf_pck_mime_type_in_list(mime, MSF_DLG_CONTENT_TYPE_IMAGE))
              goto skip_preview;
            if (op->dir_entries->entry_list[selection].is_dir == TRUE)
              goto skip_preview;
            if (get_size_from_attr_list(op->dir_entries->entry_list[selection].attr_list) > MSF_DLG_CONTENT_MAX_SIZE)
              goto skip_preview;

            msf_dlg_start_preview_timer(handle, op);
          }
skip_preview:
          return MSF_DLG_STATE_OPEN_NAVIGATE;
        }
        break;
      case MSF_PACKAGE_BUSY:
        msf_afi_result_free(handle->afi_handle, &pck_res);
        return MSF_DLG_STATE_OPEN_NAVIGATE_DELAYED;
        break;
    }
    
    return MSF_DLG_STATE_OPEN_NAVIGATE;
  }
}


static int /* Returns state*/
update_navigate_save_window_continue(msf_dlg_handle_t *handle, MsfGadgetHandle selectgroup,
                       msf_afi_result_dir_entries_t **dir_entries, msf_pck_result_t *pck_res, const char *current_dir)
{
  msf_afi_result_dir_entries_t  *result = (msf_afi_result_dir_entries_t*)pck_res->_u.data;

  if (*dir_entries)
    free_dir_entries(handle->modid, *dir_entries);
  *dir_entries = result;

  add_entries_to_selectgroup(handle, selectgroup, *dir_entries, current_dir);

  MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, 0, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TEXT_SAVE_HERE), 0, 0, 0, TRUE);
  MSF_WIDGET_CHOICE_SET_ELEM_STATE(selectgroup, 0, MSF_CHOICE_ELEMENT_SELECTED);
  return MSF_DLG_STATE_SAVE_AS_NAVIGATE;
}


static int /* Returns state*/
update_navigate_save_window(msf_dlg_handle_t *handle, MsfWindowHandle window_handle, MsfGadgetHandle selectgroup,
                       const char* mime_types, const char* path, msf_afi_result_dir_entries_t **dir_entries, msf_dlg_op_t *op)
{
  int i = 0;
  
  /*Remove all choice elements*/
  while (MSF_WIDGET_CHOICE_SIZE (selectgroup)) {
    MSF_WIDGET_CHOICE_REMOVE_ELEMENT (selectgroup, 0);
  }

  if (path== NULL) {
    msf_pck_root_folders_t  *root_folders;
    int                      displayed_items = 0;
    msf_dlg_action_t        *menu_action;

    menu_action = find_action_by_type (op->window->action, MsfMenu);
    if(menu_action && menu_action->handle) {
      MSF_WIDGET_REMOVE (handle->op->window->handle, menu_action->handle);
      MSF_WIDGET_RELEASE (menu_action->handle);
      menu_action->handle = 0;
    }

    MSF_WIDGET_SET_TITLE (window_handle, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TEXT_ROOT_FOLDER));
    MSF_WIDGET_WINDOW_SET_PROPERTIES (window_handle, MSF_WINDOW_PROPERTY_TITLE);  
    msf_pck_get_urf_from_mime (handle->modid, mime_types,  &root_folders);

    for (i = 0; (i < root_folders->n_rf); i++) { 
      if (!(((op->bit_flag & MSM_DLG_NO_EXTERNAL_MEMORY) > 0) && (root_folders->rf[i].external == 1))) {
        displayed_items++;
        MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, i,
                      MSF_WIDGET_STRING_GET_PREDEFINED (root_folders->rf[i].str_id),
                      0, handle->folder_image, 0, TRUE);
      }
    }
    MSF_MEM_FREE (handle->modid, root_folders);

    if (displayed_items > 0) {
      MSF_WIDGET_CHOICE_SET_ELEM_STATE (selectgroup, 0, MSF_CHOICE_ELEMENT_SELECTED);
      return MSF_DLG_STATE_SAVE_AS_NAVIGATE;
    }
    else {
      create_error_msg_dialog (handle, op,
           MSF_WIDGET_STRING_GET_PREDEFINED (MSF_STR_ID_DLG_SAVE_ERROR),
           MSF_WIDGET_STRING_GET_PREDEFINED (MSF_STR_ID_DLG_SAVE_NOT_ALLOWED));
      return MSF_DLG_STATE_SAVE_AS_MSG_DLG;
    }
  }
  else
  {
    msf_afi_result_dir_entries_t *result = NULL;
    msf_pck_result_t              pck_res;
    char                         *localized_path;
    MsfStringHandle               MsfStr;
    msf_dlg_action_t             *menu_action;

    if (handle->n_items == MSF_DLG_ICONS_NOT_LOADED) {
      MSF_GET_ICONS (handle->modid, op->id, 0, NULL);
      return MSF_DLG_STATE_SAVE_AS_NAVIGATE_DELAYED;
    }
    localized_path = msf_pck_get_localized_pathname (handle->modid, path);
    MsfStr = create_msf_string (handle->modid, localized_path);
    MSF_MEM_FREE(handle->modid, localized_path);
    MSF_WIDGET_SET_TITLE (window_handle, MsfStr);
    MSF_WIDGET_RELEASE (MsfStr);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (window_handle, MSF_WINDOW_PROPERTY_TITLE);
    op->afi_id = msf_afi_get_dir_entries (handle->afi_handle, path, 0);
    menu_action = find_action_by_type (op->window->action, MsfMenu);

    if (allow_create_new_dir (handle->modid, path)) {
      if (!menu_action) {
        menu_action = get_new_action (handle, op->window, MsfMenu);
      }
      if (menu_action->handle == 0) {
	      menu_action->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                                 MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_CREATE_DIR), MsfMenu, 3, MSF_ACTION_PROPERTY_ENABLED);
    	  MSF_WIDGET_ADD_ACTION (handle->op->window->handle, menu_action->handle);
      }
    }
    else {
      if(menu_action->handle) {
        MSF_WIDGET_REMOVE (handle->op->window->handle, menu_action->handle);
        MSF_WIDGET_RELEASE (menu_action->handle);
        menu_action->handle = 0;
      }
    }
    
    switch (msf_afi_get_result (handle->afi_handle, op->afi_id, &pck_res)) {
    case MSF_PACKAGE_COMPLETED:
      result = (msf_afi_result_dir_entries_t*)pck_res._u.data;
      if (result->result == MSF_AFI_ERROR_DELAYED) {
        MSF_MEM_FREE (handle->modid, result);
        return MSF_DLG_STATE_SAVE_AS_NAVIGATE_DELAYED;
      }
      else if (result->result == MSF_AFI_ERROR_PATH) {
        MSF_MEM_FREE (handle->modid, result);
        return MSF_DLG_STATE_SAVE_AS_NAVIGATE;
      }
      else {
        /*got entries*/
        if (*dir_entries)
          free_dir_entries(handle->modid, *dir_entries);
        *dir_entries = result; /*save them*/
        
        add_entries_to_selectgroup (handle, selectgroup, *dir_entries, op->file_name);
        
        MSF_WIDGET_CHOICE_SET_ELEMENT (selectgroup, 0, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TEXT_SAVE_HERE), 0, 0, 0, TRUE);

        MSF_WIDGET_CHOICE_SET_ELEM_STATE(selectgroup, 0, MSF_CHOICE_ELEMENT_SELECTED);
        return MSF_DLG_STATE_SAVE_AS_NAVIGATE;
      }
      break;
    case MSF_PACKAGE_BUSY:
      msf_afi_result_free (handle->afi_handle, &pck_res);
      return MSF_DLG_STATE_SAVE_AS_NAVIGATE_DELAYED;
      break;
    }
  return MSF_DLG_STATE_SAVE_AS_NAVIGATE;
  }
}

static void
create_error_popup_window(msf_dlg_handle_t *handle, msf_dlg_op_t *op, MSF_INT32 text_id, int prev_state)
{
  MsfPosition       null_pos = {0, 0};
  msf_dlg_window_t  *window = get_new_window(handle, op);
  msf_dlg_action_t  *action_ok = get_new_action(handle, window, MsfOk);


  window->handle = MSF_WIDGET_DIALOG_CREATE (handle->modid, 
                                            MSF_WIDGET_STRING_GET_PREDEFINED(text_id),
                                            MsfError,
                                            0, 0, 0);

  MSF_WIDGET_SET_TITLE (window->handle,  MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_COMMON_ERROR));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (window->handle,MSF_WINDOW_PROPERTY_TITLE);

  action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                         MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (window->handle, action_ok->handle);
	

  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, window->handle,
                                &null_pos, 0, 0);
  MSF_WIDGET_SET_IN_FOCUS (window->handle, 1);

  op->prev_state = prev_state;
  op->state = MSF_DLG_STATE_ERROR_POPUP;
}

#ifdef WAP_SUPPORT /* FULL EDITOR */

static void
create_name_edit_window(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  MsfPosition   menuPosition = {0, 0};
  msf_dlg_window_t             *name_edit_window = get_new_window (handle, op);
  msf_dlg_action_t             *action_ok = get_new_action(handle, name_edit_window, MsfOk);
  msf_dlg_action_t             *action_cancel = get_new_action(handle, name_edit_window, MsfCancel);
  MsfStringHandle              MsfStr;

  /* Create the text input gadget. */
  if (op->default_name){
	/* remove filename extension */
	char *nname = msf_cmmn_strdup(handle->modid, op->default_name);
	char *sep, *sep2;
	sep = strchr(nname, '.');
	if (sep) { // TODO: there is a bug if the directory name contains a dot 
		*sep = 0;
	}
	/* /external/pathname might contains '\' */
	sep = strrchr(nname, '\\');
	sep2 = strrchr(nname, '/');
	if (sep == NULL)
		sep =sep2;
	else if (sep2!= NULL)
		sep = (sep > sep2)?sep:sep2;
	
	if (sep)
		MsfStr = create_msf_string( handle->modid, sep+1);
	else
	    MsfStr = create_msf_string( handle->modid, nname);
    MSF_MEM_FREE(handle->modid, nname);
  }
  else {
    MsfStr = create_msf_string( handle->modid, "");
  } 


  name_edit_window->handle = MSF_WIDGET_EDITOR_CREATE(handle->modid, 0, 
                             MsfStr, MsfSaveAsFilename, MSF_CFG_FILE_NAME_LENGTH, 1, NULL, 0, 0);

  MSF_WIDGET_RELEASE (MsfStr);

  /* Create an OK action. */
	action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_SAVE), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (name_edit_window->handle, action_ok->handle);
	
	/* Create an Exit action. */
	action_cancel->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (name_edit_window->handle, action_cancel->handle);
  
  MSF_WIDGET_SET_TITLE (name_edit_window->handle, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TEXT_EDIT_FILENAME));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (name_edit_window->handle,MSF_WINDOW_PROPERTY_TITLE);
  
  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, name_edit_window->handle,
                                &menuPosition, 0, 0);
  
  MSF_WIDGET_SET_IN_FOCUS (op->screen, 1);
  MSF_WIDGET_SET_IN_FOCUS (name_edit_window->handle, 1);

}

#else

static void
create_name_edit_window(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{

  MsfDeviceProperties prop;
  MsfPosition   menuPosition;
  MsfPosition   stringPos = MSF_DLG_TEXT_POSITION;
  MsfSize       textInputSize;
  msf_dlg_window_t             *name_edit_window = get_new_window (handle, op);
  msf_dlg_gadget_t             *input_gadget = get_new_gadget(handle, name_edit_window);
  msf_dlg_action_t             *action_ok = get_new_action(handle, name_edit_window, MsfOk);
  msf_dlg_action_t             *action_cancel = get_new_action(handle, name_edit_window, MsfCancel);
  MsfStringHandle              MsfStr;


  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  menuPosition.x = (short)((prop.displaySize.width - (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH)) / 2);
  menuPosition.y = (short)((prop.displaySize.height - (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT)) / 2);

  prop.displaySize.height = (short) (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT); /* Set size of menu*/
  prop.displaySize.width = (short) (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH);

  textInputSize.height = (short) (MSF_DLG_TEXT_HEIGHT);
  textInputSize.width = (short) (prop.displaySize.width - (stringPos.x * 2));
  
  name_edit_window->handle = MSF_WIDGET_FORM_CREATE (handle->modid, &prop.displaySize,
                                                MSF_WINDOW_PROPERTY_TITLE, 0);
  MSF_WIDGET_SET_TITLE (name_edit_window->handle, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TEXT_EDIT_FILENAME));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (name_edit_window->handle,MSF_WINDOW_PROPERTY_TITLE);

  /* Create an OK action. */
	action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_SAVE), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (name_edit_window->handle, action_ok->handle);
	
	/* Create an Exit action. */
	action_cancel->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (name_edit_window->handle, action_cancel->handle);

  /* Create the text input gadget. */
  if (op->default_name){
    MsfStr = create_msf_string( handle->modid, op->default_name);
  }
  else {
    MsfStr = create_msf_string( handle->modid, "");
  } 
  
  if(textInputSize.width > prop.displaySize.width)
    textInputSize.width = (short)( prop.displaySize.width - 5);

  input_gadget->handle = MSF_WIDGET_TEXT_INPUT_CREATE (handle->modid,
                               0, MsfStr, MsfText, MSF_CFG_VIRTUAL_FILE_NAME_LENGTH, 1, &textInputSize,
                               MSF_GADGET_PROPERTY_BORDER | MSF_GADGET_PROPERTY_FOCUS, 0);

  MSF_WIDGET_RELEASE (MsfStr);
  MSF_WIDGET_WINDOW_ADD_GADGET (name_edit_window->handle, input_gadget->handle,
                                &stringPos, 0);

  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, name_edit_window->handle,
                                &menuPosition, 0, 0);
  
  MSF_WIDGET_SET_IN_FOCUS (op->screen, 1);
  MSF_WIDGET_SET_IN_FOCUS (name_edit_window->handle, 1);

}
#endif /* WAP_SUPPORT */

static void
create_exists_dialog ( msf_dlg_handle_t *handle, msf_dlg_op_t *op, char *name)
{
  char              *dialogText;
  MsfPosition       null_pos = {0, 0};
  char              *exists_text1 , *exists_text2;
  msf_dlg_window_t  *window = get_new_window(handle, op);
  msf_dlg_action_t  *action_ok = get_new_action(handle, window, MsfOk);
  msf_dlg_action_t  *action_cancel = get_new_action(handle, window, MsfCancel);
  MsfStringHandle   MsfStr;

  if ((op->bit_flag &  MSF_DLG_ALLOW_OVERWRITE) > 0){
#ifndef WAP_SUPPORT
    exists_text1 = MSF_MEM_ALLOC(handle->modid, 
      MSF_WIDGET_STRING_GET_LENGTH( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_EXISTS_TEXT1), 1, MsfUtf8)+1);
    MSF_WIDGET_STRING_GET_DATA( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_EXISTS_TEXT1), exists_text1, MsfUtf8);
#else
	exists_text1 = msf_cmmn_strdup(handle->modid, "");
#endif
    exists_text2 = MSF_MEM_ALLOC(handle->modid, 
      MSF_WIDGET_STRING_GET_LENGTH( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_EXISTS_TEXT2), 1, MsfUtf8)+1);
    MSF_WIDGET_STRING_GET_DATA( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_EXISTS_TEXT2), exists_text2, MsfUtf8);
  }
  else {
#ifndef WAP_SUPPORT
    exists_text1 = MSF_MEM_ALLOC(handle->modid, 
      MSF_WIDGET_STRING_GET_LENGTH( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_NO_REPLACE_TEXT1), 1, MsfUtf8)+1);
    MSF_WIDGET_STRING_GET_DATA( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_NO_REPLACE_TEXT1), exists_text1, MsfUtf8);
#else
	exists_text1 = msf_cmmn_strdup(handle->modid, "");
#endif
    exists_text2 = MSF_MEM_ALLOC(handle->modid, 
      MSF_WIDGET_STRING_GET_LENGTH( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_NO_REPLACE_TEXT2), 1, MsfUtf8)+1);
    MSF_WIDGET_STRING_GET_DATA( MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_NO_REPLACE_TEXT2), exists_text2, MsfUtf8);
  }

  dialogText = MSF_MEM_ALLOC(handle->modid, strlen(exists_text1) +strlen(name) + strlen(exists_text2)+1);
  strcpy(dialogText, exists_text1);
  strcat(dialogText, name);
  strcat(dialogText, exists_text2);

  MsfStr = create_msf_string(handle->modid, dialogText);
  window->handle = MSF_WIDGET_DIALOG_CREATE (handle->modid, 
                                            MsfStr,
                                            MsfConfirmation,
                                            0, 0, 0);
  MSF_WIDGET_RELEASE (MsfStr);
  MSF_MEM_FREE(handle->modid, exists_text1);
  MSF_MEM_FREE(handle->modid, exists_text2);
  MSF_MEM_FREE(handle->modid, dialogText);

  MSF_WIDGET_SET_TITLE (window->handle,  MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_EXISTS_TITLE));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (window->handle,MSF_WINDOW_PROPERTY_TITLE);

  if ((op->bit_flag & MSF_DLG_ALLOW_OVERWRITE) > 0){
    action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	  MSF_WIDGET_ADD_ACTION (window->handle, action_ok->handle);
  }
	
	action_cancel->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (window->handle, action_cancel->handle);

  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, window->handle,
                                &null_pos, 0, 0);
  MSF_WIDGET_SET_IN_FOCUS (window->handle, 1);

}

static void
create_error_msg_dialog ( msf_dlg_handle_t *handle, msf_dlg_op_t *op, MsfStringHandle title, MsfStringHandle str)
{
  MsfPosition       null_pos = {0, 0};
  msf_dlg_window_t  *window = get_new_window(handle, op);
  msf_dlg_action_t  *action_ok = get_new_action(handle, window, MsfOk);

  window->handle = MSF_WIDGET_DIALOG_CREATE (handle->modid, 
                                            str,
                                            MsfError,
                                            0, 0, 0);

  MSF_WIDGET_SET_TITLE (window->handle,  title);
  MSF_WIDGET_WINDOW_SET_PROPERTIES (window->handle,MSF_WINDOW_PROPERTY_TITLE);

  action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (window->handle, action_ok->handle);

  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, window->handle, &null_pos, 0, 0);
  MSF_WIDGET_SET_IN_FOCUS (window->handle, 1);

}
static void
create_new_dir_dialog(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  MsfDeviceProperties prop;
  MsfPosition   windowPosition;
  MsfPosition   stringPos = MSF_DLG_TEXT_POSITION;
  MsfSize       textInputSize;
  msf_dlg_window_t             *create_dir_window = get_new_window (handle, op);
  msf_dlg_gadget_t             *input_gadget = get_new_gadget(handle, create_dir_window);
  msf_dlg_action_t             *action_ok = get_new_action(handle, create_dir_window, MsfOk);
  msf_dlg_action_t             *action_cancel = get_new_action(handle, create_dir_window, MsfCancel);
  MsfStringHandle              MsfStr;

  op->state = MSF_DLG_STATE_NEW_DIR_NAME_EDIT;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

  windowPosition.x = (short)((prop.displaySize.width - (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH)) / 2);
  windowPosition.y = (short)((prop.displaySize.height - (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT)) / 2);

  prop.displaySize.height = (short) (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT); /* Set size of window*/
  prop.displaySize.width = (short) (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH);

  textInputSize.height = (short) (MSF_DLG_TEXT_HEIGHT);
  textInputSize.width = (short) (prop.displaySize.width - (stringPos.x * 2));
  
  create_dir_window->handle = MSF_WIDGET_FORM_CREATE (handle->modid, &prop.displaySize,
                                                MSF_WINDOW_PROPERTY_TITLE, 0);
  MSF_WIDGET_SET_TITLE (create_dir_window->handle, MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_TITLE_CREATE_DIR));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (create_dir_window->handle,MSF_WINDOW_PROPERTY_TITLE);

  /* Create an OK action. */
	action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (create_dir_window->handle, action_ok->handle);
	
	/* Create an Cancel action. */
	action_cancel->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_CANCEL), MsfCancel, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (create_dir_window->handle, action_cancel->handle);

  /* Create the text input gadget. */
  MsfStr = create_msf_string( handle->modid, "");
  input_gadget->handle = MSF_WIDGET_TEXT_INPUT_CREATE (handle->modid,
                               0, MsfStr, MsfText, 255, 0, &textInputSize,
                               MSF_GADGET_PROPERTY_BORDER | MSF_GADGET_PROPERTY_FOCUS, 0);

  MSF_WIDGET_RELEASE (MsfStr);
  MSF_WIDGET_WINDOW_ADD_GADGET (create_dir_window->handle, input_gadget->handle,
                                &stringPos, 0);

  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, create_dir_window->handle,
                                &windowPosition, 0, 0);
  
  MSF_WIDGET_SET_IN_FOCUS (op->screen, 1);
  MSF_WIDGET_SET_IN_FOCUS (create_dir_window->handle, 1);
}

static int
msf_dlg_try_create_dir(msf_dlg_handle_t *handle, msf_dlg_op_t *op, msf_dlg_window_t *window)
{
  MsfStringHandle   msfStr;
  char              *name;
  char              *full_path;
  char              *full_path_with_end;
  msf_pck_result_t  result;

  msfStr = MSF_WIDGET_STRING_CREATE_TEXT(handle->modid, window->gadget->handle, 0);
  name = MSF_MEM_ALLOC(handle->modid, MSF_WIDGET_STRING_GET_LENGTH(msfStr, 1, MsfUtf8)+1);
  MSF_WIDGET_STRING_GET_DATA(msfStr, name, MsfUtf8);
  MSF_WIDGET_RELEASE(msfStr);
  
  if (file_name_valid(name) == FALSE){
    create_error_popup_window(handle, op, MSF_STR_ID_DLG_ERROR_CREATE_DIR, MSF_DLG_STATE_NEW_DIR_NAME_EDIT);
    MSF_MEM_FREE(handle->modid, name);
    return MSF_PACKAGE_SIGNAL_HANDLED;
  }
  
  full_path = msf_cmmn_strcat(handle->modid, op->file_name, name);
  MSF_MEM_FREE(handle->modid, name);
  full_path_with_end = msf_cmmn_strcat(handle->modid, full_path, "/");
  MSF_MEM_FREE(handle->modid, full_path);
  op->afi_id = msf_afi_mkdir (handle->afi_handle, full_path_with_end);
  MSF_MEM_FREE(handle->modid, full_path_with_end);
  switch (msf_afi_get_result(handle->afi_handle, op->afi_id, &result)){
  case MSF_PACKAGE_COMPLETED:
    if (result._u.i_val == MSF_AFI_OK){
      free_dlg_window(handle, op, window);
      op->state = update_navigate_save_window(handle, op->window->handle, op->window->gadget->handle,
                                                     op->mime_types, op->file_name, &(op->dir_entries), op);
    }
    else{
      create_error_popup_window(handle, op, MSF_STR_ID_DLG_ERROR_CREATE_DIR, MSF_DLG_STATE_NEW_DIR_NAME_EDIT);
    }
    break;
  case MSF_PACKAGE_ERROR:
    free_dlg_window(handle, op, window);
    op->state = update_navigate_save_window(handle, op->window->handle, op->window->gadget->handle,
                                                     op->mime_types, op->file_name, &(op->dir_entries), op);
    break;
  case MSF_PACKAGE_BUSY:
    op->state = MSF_DLG_STATE_NEW_DIR_AFI_DELAYED;
    break;
  }
  
  msf_afi_result_free(handle->afi_handle, &result);
  
  return MSF_PACKAGE_SIGNAL_HANDLED;
}

#ifdef WAP_SUPPORT 
/* Modified from msf_afi_resolve_path */
static char *
msf_dlg_resolve_path (MSF_UINT8 modid, const char *afi_path_in)
{
  const char *p;
  const char *s;
  const char *urf_path;
  char *folder;

  /*Get root folder*/
  p = afi_path_in;
  if ((p == NULL) || (*p == '\0') || (*p != '/'))
    return NULL;

  if (*(p + 1) != MSF_USER_FOLDER_ID_CHAR) {
    /* This is a POSIX path */
	WAP_DBG_ASSERT(0);
    return msf_cmmn_strdup(modid, p);
  }
  p += 2;
  s = p;

  while (*p++ != '/') ;

  if (*(p - 2) != MSF_USER_FOLDER_ID_CHAR)
    return NULL;

  folder = msf_cmmn_strndup (modid, s, (p - 2) - s);
  if (folder == NULL)
    return NULL;
  urf_path = msf_pck_get_posix_path (folder);
  MSF_MEM_FREE (modid, folder);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
  if (*p == MSF_USER_FOLDER_ID_CHAR)
    return NULL; /* We don't support this */

  if (*p == '\0')
    return NULL;
  return msf_cmmn_strcat(modid, urf_path, p);
}
#endif /* WAP_SUPPORT */

static void
create_cannot_save_window(msf_dlg_handle_t *handle, msf_dlg_op_t *op)
{
  MsfPosition       null_pos = {0, 0};
  msf_dlg_window_t  *window = get_new_window(handle, op);
  msf_dlg_action_t  *action_ok = get_new_action(handle, window, MsfOk);


  window->handle = MSF_WIDGET_DIALOG_CREATE (handle->modid, 
                                            MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_CANNOT_SAVE),
                                            MsfError,
                                            0, 0, 0);

  MSF_WIDGET_SET_TITLE (window->handle,  MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_COMMON_ERROR));
  MSF_WIDGET_WINDOW_SET_PROPERTIES (window->handle,MSF_WINDOW_PROPERTY_TITLE);

  action_ok->handle = MSF_WIDGET_ACTION_CREATE (handle->modid,
                         MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (window->handle, action_ok->handle);
	

  MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, window->handle,
                                &null_pos, 0, 0);
  MSF_WIDGET_SET_IN_FOCUS (window->handle, 1);

  op->state = MSF_DLG_STATE_SAVE_AS_CANNOT_SAVE;
}

static int
msf_dlg_handle_widget_action (msf_dlg_handle_t *handle, MSF_INT32 *id, MsfWindowHandle window_handle, MsfActionHandle action_handle)
{
  msf_dlg_op_t *op = handle->op;
  msf_dlg_op_t *found_op = NULL;
  msf_dlg_window_t *found_window = NULL;

  while (op && (!found_op)) {
    msf_dlg_window_t *window = op->window;
    while (window && (!found_window)) {
      if (window->handle == window_handle) {
        found_op = op;
        found_window = window;
        *id = op->id;
      }
      window = window->next;
    }
    op = op->next;
  }
  if (found_op) {
    int actionType;
    int priority;
    MSF_WIDGET_ACTION_GET_ATTR(action_handle, &actionType, &priority);

    if (found_op->state == MSF_DLG_STATE_OPEN_NAVIGATE){
          
      HDIa_widgetSetPattern (found_window->gadget->handle, &found_op->default_pattern, 1);  
      if (found_op->preview_state == MSF_DLG_PREVIEW_STATE_SLEEP){
        MSF_TIMER_RESET(handle->modid, found_op->current_timer_id);
        found_op->preview_state = MSF_DLG_PREVIEW_STATE_IDLE;
      }
      
      if (actionType == MsfOk && MSF_WIDGET_CHOICE_SIZE(found_window->gadget->handle)){
        int selection = 0;
        while ((!(MSF_WIDGET_CHOICE_GET_ELEM_STATE(found_window->gadget->handle, selection) & MSF_CHOICE_ELEMENT_FOCUSED)) &&
               (selection < MSF_WIDGET_CHOICE_SIZE(found_window->gadget->handle)))
          selection++;

        if (found_op->file_name == NULL) {
          msf_pck_root_folders_t    *root_folders;
          char                      urf_string[2] = {MSF_USER_FOLDER_ID_CHAR, '\0'};
          msf_pck_get_urf_from_mime (handle->modid, found_op->mime_types,  &root_folders);
          found_op->file_name = MSF_MEM_ALLOC(handle->modid, 2 + strlen(root_folders->rf[selection].fld_id) + 2 + 1);
          strcpy(found_op->file_name, "/");
          strcat(found_op->file_name, urf_string);
          strcat(found_op->file_name, root_folders->rf[selection].fld_id);
          strcat(found_op->file_name, urf_string);
          strcat(found_op->file_name, "/");
          found_op->state = update_navigate_window(handle, found_window->handle, found_window->gadget->handle,
                                                   found_op->mime_types, found_op->file_name, &(found_op->dir_entries), found_op );
          MSF_MEM_FREE( handle->modid, root_folders);
        }
        else{
          char *temp_file_name;
          int j;
          msf_dlg_index_list_t *index_list;
          index_list = sort_dir_entries(handle, found_op->dir_entries);
          j = get_index_from_index_list_number_restrict(index_list, selection, found_op->dir_entries, found_op->mime_types, found_op->permission);
          delete_index_list(handle, index_list);

          if (found_op->dir_entries->entry_list[j].is_dir == TRUE){
            char *temp_file_name;
            temp_file_name = MSF_MEM_ALLOC(handle->modid,
                                strlen(found_op->file_name) + strlen(found_op->dir_entries->entry_list[j].name) + 1 + 1 );
            strcpy(temp_file_name, found_op->file_name);
            strcat(temp_file_name, found_op->dir_entries->entry_list[j].name);
            strcat(temp_file_name, "/");
            MSF_MEM_FREE(handle->modid, found_op->file_name);
            found_op->file_name = temp_file_name;
            found_op->state = update_navigate_window(handle, found_window->handle, found_window->gadget->handle,
                                                   found_op->mime_types, found_op->file_name, &(found_op->dir_entries), found_op );
          }
          else{
            temp_file_name = MSF_MEM_ALLOC(handle->modid,
                                strlen(found_op->file_name) + strlen(found_op->dir_entries->entry_list[j].name) + 1 );
            strcpy(temp_file_name, found_op->file_name);
            strcat(temp_file_name, found_op->dir_entries->entry_list[j].name);
            MSF_MEM_FREE(handle->modid, found_op->file_name);
            found_op->file_name = temp_file_name;
            found_op->status = MSF_DLG_RETURN_OK;
            found_op->state = MSF_DLG_STATE_OPEN_FINISHED;
            return MSF_PACKAGE_OPERATION_COMPLETE;
          }
        }

      }
      else if (actionType == MsfBack){
        if (found_op->file_name == NULL) {
          /*Exit dialog*/
          found_op->status = MSF_DLG_RETURN_CANCELLED;
          found_op->state = MSF_DLG_STATE_OPEN_FINISHED;
          return MSF_PACKAGE_OPERATION_COMPLETE;
        }
        else {
          found_op->file_name[strlen(found_op->file_name)-1] = '\0';
          found_op->file_name[strrchr(found_op->file_name, '/' ) - found_op->file_name + 1] = '\0';
          if (strlen(found_op->file_name) == 1) {
            MSF_MEM_FREE(handle->modid, found_op->file_name);
            found_op->file_name = NULL;
          }
          found_op->state = update_navigate_window(handle, found_window->handle, found_window->gadget->handle,
                                                   found_op->mime_types, found_op->file_name, &(found_op->dir_entries), found_op );
        }
      }
    }
#ifdef WAP_SUPPORT
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_FMGR){
    	/* Illegal states */
		HDIa_widgetExtFmgrSaveFileNameAbort();
        found_op->status = MSF_DLG_RETURN_CANCELLED;
        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
        return MSF_PACKAGE_OPERATION_COMPLETE;
    }
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_FMGR_FINISHED){
    	if (actionType == MsfOk)
    	{
    		/* cf.  msf_dlg_get_result */			
	        found_op->status = MSF_DLG_RETURN_OK;
	        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
	        return MSF_PACKAGE_OPERATION_COMPLETE;
    	}
    	else 
    	{
    		WAP_DBG_ASSERT(actionType == MsfCancel);
    		HDIa_widgetExtFmgrSaveFileNameAbort(); /* Effective if canceled by End key */
	        found_op->status = MSF_DLG_RETURN_CANCELLED;
	        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
	        return MSF_PACKAGE_OPERATION_COMPLETE;
    	}
    }    
#endif
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_NAVIGATE){

      if (actionType == MsfOk && MSF_WIDGET_CHOICE_SIZE(found_window->gadget->handle)){
        int j = 0;
        while ((!(MSF_WIDGET_CHOICE_GET_ELEM_STATE(found_window->gadget->handle, j) & MSF_CHOICE_ELEMENT_FOCUSED)) &&
               (j < MSF_WIDGET_CHOICE_SIZE(found_window->gadget->handle)))
          j++;
        
        if (found_op->file_name == NULL) {
          msf_pck_root_folders_t    *root_folders;
          char                      urf_string[2] = {MSF_USER_FOLDER_ID_CHAR, '\0'};
          msf_pck_get_urf_from_mime (handle->modid, found_op->mime_types,  &root_folders);
          if (found_op->file_name)
            MSF_MEM_FREE(handle->modid, found_op->file_name);
          found_op->file_name = MSF_MEM_ALLOC(handle->modid, 2 + strlen(root_folders->rf[j].fld_id) + 2 + 1);
          strcpy(found_op->file_name, "/");
          strcat(found_op->file_name, urf_string);
          strcat(found_op->file_name, root_folders->rf[j].fld_id);
          strcat(found_op->file_name, urf_string);
          strcat(found_op->file_name, "/");

          found_op->state = update_navigate_save_window(handle, found_window->handle, found_window->gadget->handle,
                                                   found_op->mime_types, found_op->file_name, &(found_op->dir_entries), found_op );
          MSF_MEM_FREE( handle->modid, root_folders);
        }
        else if (j == 0){
          /* Save here pressed*/
          free_dlg_window(handle, found_op, found_window);
          create_name_edit_window(handle, found_op);
          found_op->state = MSF_DLG_STATE_SAVE_AS_EDIT_NAME;
        }
        else{
          msf_dlg_index_list_t *index_list = sort_dir_entries(handle, found_op->dir_entries);
          int selection = get_index_from_index_list_number(index_list, j-1);
          delete_index_list(handle, index_list);

          if (found_op->dir_entries->entry_list[selection].is_dir == TRUE){
            char *temp_file_name; 
            temp_file_name = MSF_MEM_ALLOC(handle->modid,
                                strlen(found_op->file_name) + strlen(found_op->dir_entries->entry_list[selection].name) + 1 + 1 );
            strcpy(temp_file_name, found_op->file_name);
            strcat(temp_file_name, found_op->dir_entries->entry_list[selection].name);
            strcat(temp_file_name, "/");
            MSF_MEM_FREE(handle->modid, found_op->file_name);
            found_op->file_name = temp_file_name;
            found_op->state = update_navigate_save_window(handle, found_window->handle, found_window->gadget->handle,
                                                   found_op->mime_types, found_op->file_name, &(found_op->dir_entries), found_op );
          }
          else{
          /*File pressed, do nothing?*/
          }

        }

      }
      else if (actionType == MsfBack){
        if (found_op->file_name == NULL) {
          /*Exit dialog*/
          found_op->status = MSF_DLG_RETURN_CANCELLED;
          found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
          return MSF_PACKAGE_OPERATION_COMPLETE;
        }
        else {
          found_op->file_name[strlen(found_op->file_name)-1] = '\0';
          found_op->file_name[strrchr(found_op->file_name, '/' ) - found_op->file_name + 1] = '\0';
          if (strlen(found_op->file_name) == 1) {
            MSF_MEM_FREE(handle->modid, found_op->file_name);
            found_op->file_name = NULL;
          }
          found_op->state = update_navigate_save_window(handle, found_window->handle, found_window->gadget->handle,
                                                   found_op->mime_types, found_op->file_name, &(found_op->dir_entries), found_op );
        }
      }
      else if ((actionType == MsfMenu) && (allow_create_new_dir(handle->modid, found_op->file_name))){
        create_new_dir_dialog(handle, found_op);
      }

    }
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_EDIT_NAME){
      if (actionType == MsfOk){
          MsfStringHandle   msfStr;
          char              *name;
          char              *temp_file_name;
          msf_pck_result_t  result;
#ifdef WAP_SUPPORT /* FULL EDITOR */
          msfStr = MSF_WIDGET_STRING_CREATE_TEXT(handle->modid, found_window->handle, 0);
#else
          msfStr = MSF_WIDGET_STRING_CREATE_TEXT(handle->modid, found_window->gadget->handle, 0);
#endif
          name = MSF_MEM_ALLOC(handle->modid, MSF_WIDGET_STRING_GET_LENGTH(msfStr, 1, MsfUtf8)+1);
          MSF_WIDGET_STRING_GET_DATA(msfStr, name, MsfUtf8);
          MSF_WIDGET_RELEASE(msfStr);
          if (file_name_valid(name) == FALSE){
            create_error_popup_window(handle, found_op, MSF_STR_ID_DLG_ERROR_NAME, MSF_DLG_STATE_SAVE_AS_EDIT_NAME);
            MSF_MEM_FREE(handle->modid, name);
            return MSF_PACKAGE_SIGNAL_HANDLED;
          }

          if (found_op->entered_name)
            MSF_MEM_FREE (handle->modid, found_op->entered_name);
          found_op->entered_name = name;
               
          temp_file_name = MSF_MEM_ALLOC(handle->modid, strlen(found_op->file_name) + strlen(name) + 1 );
          strcpy(temp_file_name, found_op->file_name);
          strcat(temp_file_name, name);

#ifdef WAP_SUPPORT
          {
			char *posix_file_name;
			posix_file_name = msf_dlg_resolve_path(handle->modid, temp_file_name);
			if (posix_file_name && HDIa_fileCheckDirExist(posix_file_name))
            {
               MSF_MEM_FREE(handle->modid, posix_file_name);

   	           create_exists_dialog(handle, found_op, name);
   	           found_op->state = MSF_DLG_STATE_SAVE_AS_EXISTS_DIALOG;
   	           // msf_afi_result_free(handle->afi_handle, &result);
   	           MSF_MEM_FREE(handle->modid, temp_file_name);
   	           return MSF_PACKAGE_SIGNAL_HANDLED;
            }
            if (posix_file_name)
            	MSF_MEM_FREE(handle->modid, posix_file_name);
          }
#endif /* WAP_SUPPORT */
          
          found_op->afi_id = msf_afi_exist (handle->afi_handle, temp_file_name);
          if (msf_afi_get_result (handle->afi_handle, found_op->afi_id, &result) == MSF_PACKAGE_BUSY){
            msf_afi_result_free(handle->afi_handle, &result);
            found_op->state = MSF_DLG_STATE_SAVE_AS_FILE_EXISTS_DELAYED;
            MSF_MEM_FREE(handle->modid, temp_file_name);
            return MSF_PACKAGE_SIGNAL_HANDLED;
          }
          if ((MSF_INT32)(result._u.data) != MSF_AFI_ERROR_PATH) {
#ifdef WAP_SUPPORT
			char *posix_file_name;
			posix_file_name = msf_dlg_resolve_path(handle->modid, temp_file_name);
			if (posix_file_name)
			{
				MSF_FILE_REMOVE(posix_file_name);
				MSF_MEM_FREE(handle->modid, posix_file_name);
			}
#else
            if ((MSF_INT32) (result._u.data) == MSF_AFI_ERROR_LOCKED)
            {
                // file locked, display error dialog.
                create_error_msg_dialog(handle,
                                        found_op,
                                        MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_SAVE_ERROR),
                                        MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_EXISTS_LOCKED));

                found_op->state  = MSF_DLG_STATE_SAVE_FILED_LOCKED;
                return MSF_PACKAGE_SIGNAL_HANDLED;
            }
            else {
              create_exists_dialog(handle, found_op, name);
              found_op->state = MSF_DLG_STATE_SAVE_AS_EXISTS_DIALOG;
              msf_afi_result_free(handle->afi_handle, &result);
              MSF_MEM_FREE(handle->modid, temp_file_name);
              return MSF_PACKAGE_SIGNAL_HANDLED;
			}
#endif /* WAP_SUPPORT */
          }
          msf_afi_result_free(handle->afi_handle, &result);
          MSF_MEM_FREE(handle->modid, found_op->file_name);
          found_op->file_name = temp_file_name;

          found_op->status = MSF_DLG_RETURN_OK;
          found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
          return MSF_PACKAGE_OPERATION_COMPLETE;

      }
      else if (actionType == MsfCancel){
        /*Exit dialog*/
        found_op->status = MSF_DLG_RETURN_CANCELLED;
        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
        return MSF_PACKAGE_OPERATION_COMPLETE;
      }
    }
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_EXISTS_DIALOG){
      if (actionType == MsfOk) {
        char* tmp_file_name = NULL;

        tmp_file_name = msf_cmmn_strcat (handle->modid, found_op->file_name,
                                         found_op->entered_name);

        MSF_MEM_FREE (handle->modid, found_op->file_name);        
        found_op->file_name = tmp_file_name;
        
        found_op->status = MSF_DLG_RETURN_OK;
        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;        
        return MSF_PACKAGE_OPERATION_COMPLETE;
      }
      else if (actionType == MsfCancel){
        /*Cancel exists dialog and reedit name*/
        free_dlg_window(handle, found_op, found_window);
        found_op->state = MSF_DLG_STATE_SAVE_AS_EDIT_NAME;
#ifdef WAP_SUPPORT
        /* MTK widget implementation need to MSF_WIDGET_SET_IN_FOCUS previous editor explicitly */
        if (found_op->window)
        {
            MSF_WIDGET_SET_IN_FOCUS (found_op->screen, 1);
	        MSF_WIDGET_SET_IN_FOCUS (found_op->window->handle, 1);
	    }
#endif
        return MSF_PACKAGE_SIGNAL_HANDLED;
      }
    }
    else if (found_op->state == MSF_DLG_STATE_SAVE_FILED_LOCKED)
    {
      free_dlg_window(handle, found_op, found_window);
      found_op->state = MSF_DLG_STATE_SAVE_AS_EDIT_NAME;
      return MSF_PACKAGE_SIGNAL_HANDLED;
    }
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_MSG_DLG){
      if (actionType == MsfOk){        
        found_op->status = MSF_DLG_RETURN_CANCELLED;
        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;        
        return MSF_PACKAGE_OPERATION_COMPLETE;
      }
    }
    else if (found_op->state == MSF_DLG_STATE_NEW_DIR_NAME_EDIT){
      switch (actionType){
      case MsfOk:
        return msf_dlg_try_create_dir(handle, found_op, found_window);
      case MsfCancel:
        free_dlg_window(handle, found_op, found_window);
        found_op->state = MSF_DLG_STATE_SAVE_AS_NAVIGATE;
        break;
      }
    }
    else if (found_op->state == MSF_DLG_STATE_ERROR_POPUP){
      free_dlg_window(handle, found_op, found_window);
      found_op->state = found_op->prev_state;
    }
    else if (found_op->state == MSF_DLG_STATE_SAVE_AS_CANNOT_SAVE){
      if (actionType == MsfOk){        
        found_op->status = MSF_DLG_RETURN_CANCELLED;
        found_op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;        
        return MSF_PACKAGE_OPERATION_COMPLETE;
      }
    }
    return MSF_PACKAGE_SIGNAL_HANDLED;
  }
  return MSF_PACKAGE_SIGNAL_NOT_HANDLED;
}


static void
msf_dlg_navigate_handle_user_evt_up_down(msf_dlg_handle_t *handle, msf_dlg_op_t *op, msf_dlg_window_t *window, MsfEventType eventType)
{
  int focus;
  int selection = 0;
  int choice_size = MSF_WIDGET_CHOICE_SIZE(window->gadget->handle);
  int last_choice = choice_size - 1;

  if (!choice_size)
    return;

  while (!(MSF_WIDGET_CHOICE_GET_ELEM_STATE(window->gadget->handle, selection) & MSF_CHOICE_ELEMENT_FOCUSED))
    selection++;

  focus = selection;

  switch (eventType){
  case MsfKey_Up:
    if (selection != 0)
      focus = selection - 1;
    break;
  case MsfKey_Down:
    if (selection < last_choice)
      focus = selection + 1;
    break;
  }
  
  if (selection != focus){
    msf_dlg_index_list_t *index_list; 
    char             *mime;

    MSF_WIDGET_CHOICE_SET_ELEM_STATE(window->gadget->handle, selection, 0);
    MSF_WIDGET_CHOICE_SET_ELEM_STATE(window->gadget->handle, focus, MSF_CHOICE_ELEMENT_FOCUSED);
    op->current_focus = focus;

    if (op->preview_state == MSF_DLG_PREVIEW_STATE_SLEEP)
      MSF_TIMER_RESET(handle->modid, op->current_timer_id);

    if (op->preview_state == MSF_DLG_PREVIEW_STATE_BUSY)
      msf_dlg_close_pipe_from_file(handle, op);
    
    op->preview_state = MSF_DLG_PREVIEW_STATE_IDLE;
    
    HDIa_widgetSetPattern (window->gadget->handle, &op->default_pattern, 1);  

    if (op->file_name == NULL)
      return;

    index_list = sort_dir_entries(handle, op->dir_entries);
    selection = get_index_from_index_list_number_restrict(index_list, op->current_focus, op->dir_entries, op->mime_types, op->permission);
    delete_index_list(handle, index_list);

    mime = get_mime_from_attr_list(op->dir_entries->entry_list[selection].attr_list);
    if (!msf_pck_mime_type_in_list(mime, MSF_DLG_CONTENT_TYPE_IMAGE))
      return;
    if (op->dir_entries->entry_list[selection].is_dir == TRUE)
      return;
    if (get_size_from_attr_list(op->dir_entries->entry_list[selection].attr_list) > MSF_DLG_CONTENT_MAX_SIZE)
      return;

    msf_dlg_start_preview_timer(handle, op);
  }

}



static int
msf_dlg_handle_user_evt (msf_dlg_handle_t *handle, MSF_INT32 *id, MSF_UINT32 window_handle, MsfEvent evt)
{
  msf_dlg_op_t *op = handle->op;
  msf_dlg_op_t *found_op = NULL;
  msf_dlg_window_t *found_window = NULL;

  while (op && (!found_op)) {
    msf_dlg_window_t *window = op->window;
    while (window && (!found_window)) {
      if (window->handle == window_handle) {
        found_op = op;
        found_window = window;
        *id = op->id;
      }
      window = window->next;
    }
    op = op->next;
  }
  if (found_op) {
    if (evt.eventClass != MsfRelease)
      return MSF_PACKAGE_SIGNAL_HANDLED;

    if (found_op->state == MSF_DLG_STATE_OPEN_NAVIGATE){
      
      switch (evt.eventType){
  
      case MsfKey_Up:
        msf_dlg_navigate_handle_user_evt_up_down(handle, found_op, found_window, MsfKey_Up);
        break;

      case MsfKey_Down:
        msf_dlg_navigate_handle_user_evt_up_down(handle, found_op, found_window, MsfKey_Down);
        break;

      }
    }
  }

  if (found_op)
    return MSF_PACKAGE_SIGNAL_HANDLED;
  else
    return MSF_PACKAGE_SIGNAL_NOT_HANDLED;
}

static int
msf_dlg_handle_timer_expired(msf_dlg_handle_t *handle, MSF_INT32 *id, int timer_id)
{
  MsfPattern        pattern;
  char              *pipe_name;
  char              *path;
  const char        *mime;
  int               selection;
  msf_dlg_index_list_t *index_list; 
  msf_dlg_op_t *op = handle->op;
  msf_dlg_op_t *found_op = NULL;
  MsfCreateData     createData;

  while (op && (!found_op)) {
    if (op->current_timer_id == timer_id)
      found_op = op;
    op = op->next;
  }
  
  if (!found_op)
    return MSF_PACKAGE_SIGNAL_NOT_HANDLED;

  op = found_op;
  *id = op->id;

  index_list = sort_dir_entries(handle, op->dir_entries);
  selection = get_index_from_index_list_number_restrict(index_list, op->current_focus, 
                                    op->dir_entries, op->mime_types, op->permission);
  delete_index_list(handle, index_list);

  mime = get_mime_from_attr_list(op->dir_entries->entry_list[selection].attr_list);
  if (!mime)
    return MSF_PACKAGE_SIGNAL_HANDLED;

  path = msf_cmmn_strcat(handle->modid, op->file_name, op->dir_entries->entry_list[selection].name);

  
  pipe_name = msf_dlg_get_pipe_from_file(handle, op, path);
  if (msf_dlg_execute_pipe_from_file(handle, op, 0))
    op->preview_state = MSF_DLG_PREVIEW_STATE_IDLE;
  else
    op->preview_state = MSF_DLG_PREVIEW_STATE_BUSY;

  MSF_MEM_FREE(handle->modid, path);
	MSF_WIDGET_RELEASE (op->preview_image_handle);
  
  createData.resource = pipe_name;
  op->preview_image_handle = MSF_WIDGET_IMAGE_CREATE_FORMAT (handle->modid, &createData, mime,
                                                                        MsfResourcePipe, 0); 
  MSF_MEM_FREE(handle->modid, pipe_name);

  pattern.image = op->preview_image_handle;
  pattern.alignment.horisontalPos = MsfCenter;
  pattern.alignment.verticalPos = MsfMiddle;
  pattern.padding = MsfNoPadding;
  
  
  HDIa_widgetSetPattern (op->window->gadget->handle, &pattern, 1);  

  return MSF_PACKAGE_SIGNAL_HANDLED;
}

/* Returns TRUE if op found otherwise false */
static int
msf_dlg_pipe_find_op_from_afi_id(msf_dlg_handle_t *handle, MSF_INT32 afi_id, MSF_INT32 *id)
{
  msf_dlg_op_t *op = handle->op;

  while (op) {
    if (op->pipe_from_file)
      if (op->pipe_from_file->afi_id == afi_id){
        *id = op->id;
        return TRUE;
      }
    op = op->next;
  }
  
  return FALSE;
}

/* Returns TRUE if op found otherwise false */
static int
msf_dlg_pipe_handle_afi_complete(msf_dlg_handle_t *handle, MSF_INT32 afi_id, MSF_INT32 *id)
{
  msf_dlg_op_t *op = handle->op;
  msf_dlg_op_t *found_op = NULL;

  while (op && (!found_op)) {
    if (op->pipe_from_file)
      if (op->pipe_from_file->afi_id == afi_id)
        found_op = op;
    op = op->next;
  }

  if (!found_op)
    return FALSE;

  op = found_op;
  *id = found_op->id;

  if (msf_dlg_execute_pipe_from_file(handle, op, 0))
    op->preview_state = MSF_DLG_PREVIEW_STATE_IDLE;

  return TRUE;
}


static int
msf_dlg_handle_pipe_notify(msf_dlg_handle_t *handle, MSF_INT32 *id, void *signal)
{
  msf_pipe_notify_t *pipe_signal = ((msf_pipe_notify_t *)signal);
  msf_dlg_op_t *op = handle->op;
  msf_dlg_op_t *found_op = NULL;

  while (op && (!found_op)) {
    if (op->pipe_from_file)
      if (op->pipe_from_file->pipe_handle == pipe_signal->handle)
        found_op = op;
    op = op->next;
  }

  if (!found_op)
    return MSF_PACKAGE_SIGNAL_NOT_HANDLED;

  op = found_op;
  *id = found_op->id;

  if (msf_dlg_execute_pipe_from_file(handle, op, pipe_signal->handle))
    op->preview_state = MSF_DLG_PREVIEW_STATE_IDLE;

  return MSF_PACKAGE_SIGNAL_NOT_HANDLED;
}


/*******************************************************************
 * Global Functions
 *******************************************************************/

/*
 * Initialize the DLG package.
 * Returns a handle if success, otherwise returns NULL.
 */
msf_pck_handle_t *
msf_dlg_init (MSF_UINT8 modid)
{
  msf_dlg_handle_t *h = MSF_MEM_ALLOCTYPE (modid, msf_dlg_handle_t);

  if (h) {
    h->modid = modid;
    h->next = h->prev = NULL;
    h->afi_handle = msf_afi_init (modid);
    h->op = NULL;
    h->folder_image = MSF_WIDGET_IMAGE_CREATE(modid,
                      (char *)msf_dlg_folder_image, 
                      (int)sizeof(msf_dlg_folder_image), MsfBmp, 0, 0);
    h->file_image   = MSF_WIDGET_IMAGE_CREATE(modid,
                      (char *)msf_dlg_file_image, 
                      msf_dlg_file_image_size, MsfBmp, 0, 0);
    h->icons = NULL;
    h->n_items = MSF_DLG_ICONS_NOT_LOADED;
  }

  return (msf_pck_handle_t *)h;
}

#ifdef WAP_SUPPORT /* Integration with File Manager */

typedef struct
{
	msf_dlg_handle_t	*dlg_handle;
	msf_dlg_op_t	 	*dlg_op;
} msf_dlg_fmgr_param_struct;

void msf_dlg_save_as_get_name_hdlr(const char *path_name, void *arg)
{
	msf_dlg_fmgr_param_struct *param = (msf_dlg_fmgr_param_struct*) arg;
	ASSERT(param);
	ASSERT(param->dlg_op->window);
	ASSERT(param->dlg_op->window->action);
	ASSERT(param->dlg_op->window->action->next);

	param->dlg_op->state = MSF_DLG_STATE_SAVE_AS_FMGR_FINISHED;

	if (!path_name)
	{
        HDIc_widgetAction(param->dlg_handle->modid, param->dlg_op->window->handle, 
        	param->dlg_op->window->action->handle); /* First action is cancel */
    }
    else
    {
		param->dlg_op->file_name = msf_cmmn_strdup(param->dlg_handle->modid, path_name);
    
        HDIc_widgetAction(param->dlg_handle->modid, param->dlg_op->window->handle, 
        	param->dlg_op->window->action->next->handle); /* Second action is Ok */
    }
    
    MSF_MEM_FREE(param->dlg_handle->modid, param);
}


static char *msf_dlg_get_default_name(MSF_UINT8 modid, msf_dlg_op_t *op)
{
  if (op->default_name){
	/* remove filename extension */
	char *nname = msf_cmmn_strdup(modid, op->default_name);
	char *sep, *sep2;
	char *out;
	
	sep = strrchr(nname, '.');
	if (sep) {
		*sep = 0;
	}
	/* /external/pathname might contains '\' */
	sep = strrchr(nname, '\\');	
	sep2 = strrchr(nname, '/');
	if (sep == NULL)
		sep =sep2;
	else if (sep2!= NULL)
		sep = (sep > sep2)?sep:sep2;

	if (sep)
	{
		out = msf_cmmn_strdup(modid, sep+1);
		MSF_MEM_FREE(modid, nname);
	}
	else
	{
		out = nname;
	}
	return out;
  }
  else {
    return NULL;
  } 
}

static void msf_dlg_free_default_name(MSF_UINT8 modid, char *name)
{
	if (!name)
		return;

	MSF_MEM_FREE(modid, name);
}

#endif /* WAP_SUPPORT */


/*
 * Create a save as dialog.
 *
 * Parameters:
 *  screen                The screen that should be used for the dialog.
 *  file_name             Suggested user friendly file name of the file.
 *  mime_type             The mime type of file to save.
 *  bit_flag              MSF_DLG_ALLOW_OVERWRITE   -  if bit is set, the package will prompt
 *                          the user about the replace and possibly replace the existing file.
 *                        MSM_DLG_NO_EXTERNAL_MEMORY - If this bit is set no folders on
 *                          external memory will be possible to select as save destination.
 * 
 * Returns a positive identifier if success, otherwise MSF_PACKAGE_ERROR.
 */
MSF_INT32
msf_dlg_create_save_as (msf_pck_handle_t* handle,
                        MsfScreenHandle screen,
                        const char* file_name,
                        const char* mime_type,
                        MSF_INT32 bit_flag)
{ 
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  msf_dlg_op_t              *op;
  msf_pck_root_folders_t    *root_folders;
  
  if ((!mime_type) || (!dlg_handle))
    return MSF_PACKAGE_ERROR;

  op = get_new_op (dlg_handle, MSF_DLG_TYPE_SAVE_AS);
#ifdef WAP_SUPPORT
  msf_dlg_add_act_dlg_op(dlg_handle, op);
#endif
  if (file_name){
    op->default_name = MSF_MEM_ALLOC(dlg_handle->modid, strlen(file_name) +1 );
    strcpy(op->default_name, file_name);
  }
  op->screen = screen;
  op->bit_flag = bit_flag;
  op->mime_types = MSF_MEM_ALLOC(dlg_handle->modid, strlen(mime_type) +1 );
  strcpy(op->mime_types, mime_type);

  msf_pck_get_urf_from_mime (dlg_handle->modid, mime_type,  &root_folders);

  if (root_folders->n_rf == 0){
    create_cannot_save_window(dlg_handle, op);
    MSF_MEM_FREE(dlg_handle->modid, root_folders);
    return op->id;
  }
  
  if (root_folders->n_rf == 1){
    if (!(((op->bit_flag & MSM_DLG_NO_EXTERNAL_MEMORY) > 0) && (root_folders->rf[0].external == 1))){
      char                      urf_string[2] = {MSF_USER_FOLDER_ID_CHAR, '\0'};
      op->file_name = MSF_MEM_ALLOC(dlg_handle->modid, 2 + strlen(root_folders->rf[0].fld_id) + 2 + 1);
      strcpy(op->file_name, "/");
      strcat(op->file_name, urf_string);
      strcat(op->file_name, root_folders->rf[0].fld_id);
      strcat(op->file_name, urf_string);
      strcat(op->file_name, "/");
    }
  }

  if (root_folders->n_rf == 1 && msf_pck_get_urf_max_depth (root_folders->rf[0].fld_id) == 1){
#ifdef WAP_SUPPORT
	char 						*default_name;
	
	msf_dlg_fmgr_param_struct	*param;
	msf_dlg_window_t            *progressing_window = get_new_window (dlg_handle, op);
	/* Create action_cancel after action_ok (cf. msf_dlg_destroy_act_dlg_op()) */
	msf_dlg_action_t            *action_ok = get_new_action(dlg_handle, progressing_window, MsfOk);
	msf_dlg_action_t            *action_cancel = get_new_action(dlg_handle, progressing_window, MsfCancel);
	MsfPosition   				menuPosition = {0, 0};
	
	progressing_window->handle = HDIa_widgetExtCreateWaitView(dlg_handle->modid, WIDGET_STR_ID_PLEASE_WAIT);
	
	action_ok->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
			MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_OK), MsfOk, 
			3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (progressing_window->handle, action_ok->handle);

	action_cancel->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
			MSF_WIDGET_STRING_GET_PREDEFINED(WIDGET_STR_ID_CANCEL), MsfCancel, 
			3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (progressing_window->handle, action_cancel->handle);

	MSF_WIDGET_SCREEN_ADD_WINDOW (op->screen, progressing_window->handle,
                                &menuPosition, 0, 0);

	/* Because widget will enter FMGR immediately before this function return, 
	 * and widget will invoke msf_dlg_save_as_get_name_hdlr with widget_execute_WAP
	 * when go back to widget screen. As a result, this window should never be focused.
	 */
	MSF_WIDGET_SET_IN_FOCUS(progressing_window->handle, 1);

	// This is dummy window, we do not need to set focus
	// MSF_WIDGET_SET_IN_FOCUS (op->screen, 1);
	// MSF_WIDGET_SET_IN_FOCUS (name_edit_window->handle, 1);

	param = MSF_MEM_ALLOC(dlg_handle->modid, sizeof(msf_dlg_fmgr_param_struct));
	param->dlg_handle = dlg_handle;
	param->dlg_op = op;
	
	default_name = msf_dlg_get_default_name(dlg_handle->modid, op);
	HDIa_widgetExtFmgrGetSaveFileName(default_name, mime_type, msf_dlg_save_as_get_name_hdlr, param);
	msf_dlg_free_default_name(dlg_handle->modid, default_name);

	op->state = MSF_DLG_STATE_SAVE_AS_FMGR;
#else
    create_name_edit_window(dlg_handle, op);
    op->state = MSF_DLG_STATE_SAVE_AS_EDIT_NAME;
#endif
  }
  else{
    MsfDeviceProperties           prop;
    MsfElementPosition            choice_position;
    MsfPosition                   menuPosition;
    MsfPosition                   selectGroupPos = {0,0};
    MsfSize                       editable_size;
    msf_dlg_window_t              *navigate_window = get_new_window (dlg_handle, op);
    msf_dlg_gadget_t              *selectgroup = get_new_gadget(dlg_handle, navigate_window);
    msf_dlg_action_t              *action_ok = get_new_action(dlg_handle, navigate_window, MsfOk);
    msf_dlg_action_t              *action_back = get_new_action(dlg_handle, navigate_window, MsfBack);
/*
    msf_dlg_action_t              *action_menu = get_new_action(dlg_handle, navigate_window, MsfMenu);
*/

    op->state = MSF_DLG_STATE_SAVE_AS_NAVIGATE; 

    choice_position.image1Pos=0;
    choice_position.string1Pos=1;
    choice_position.image2Pos=2;
    choice_position.string2Pos=3;
    choice_position.indexPos=4;
    choice_position.iconPos=5;

    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

    menuPosition.x = (short)((prop.displaySize.width - (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH)) / 2);
    menuPosition.y = (short)((prop.displaySize.height - (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT)) / 2);

    prop.displaySize.height = (short) (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT);
    prop.displaySize.width = (short) (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH);

    navigate_window->handle = MSF_WIDGET_FORM_CREATE (dlg_handle->modid, &prop.displaySize,
                                                  MSF_WINDOW_PROPERTY_TITLE, 0);
    MSF_WIDGET_WINDOW_SPECIFIC_SIZE(navigate_window->handle, &editable_size, 0);
    selectgroup->handle = MSF_WIDGET_SELECTGROUP_CREATE (dlg_handle->modid, 
                                                       MsfExclusiveChoice, 
                                                       &editable_size, 
                                                       0, 
                                                       MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_STRING_2 | MSF_CHOICE_ELEMENT_IMAGE_1, 
                                                       0x8000, 
                                                       0);
    MSF_WIDGET_WINDOW_ADD_GADGET (navigate_window->handle, selectgroup->handle,
                                  &selectGroupPos, 0);
    /* Create an OK action.*/
	  action_ok->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
                              MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	  MSF_WIDGET_ADD_ACTION (navigate_window->handle, action_ok->handle);
	  
	  /* Create a Back action.*/
	  action_back->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_BACK), MsfBack, 3, MSF_ACTION_PROPERTY_ENABLED);
	  MSF_WIDGET_ADD_ACTION (navigate_window->handle, action_back->handle);

	  /* Create a Menu action.*/
/*
	  action_menu->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
                             MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_CREATE_DIR), MsfMenu, 3, MSF_ACTION_PROPERTY_ENABLED);
	  MSF_WIDGET_ADD_ACTION (navigate_window->handle, action_menu->handle);
*/

    op->state = update_navigate_save_window(dlg_handle, navigate_window->handle, selectgroup->handle, mime_type, op->file_name, &(op->dir_entries), op);

    MSF_WIDGET_SCREEN_ADD_WINDOW (screen, navigate_window->handle,
                                  &menuPosition, 0, 0);
    MSF_WIDGET_SET_IN_FOCUS (screen, 1);
    MSF_WIDGET_SET_IN_FOCUS (navigate_window->handle, 1);

  }
  MSF_MEM_FREE(dlg_handle->modid, root_folders);
  return op->id;
}


int
msf_dlg_get_result (msf_pck_handle_t* handle, MSF_INT32 id,
                         msf_pck_result_t* result)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  msf_dlg_op_t *op;
  
  if (!dlg_handle)
    return FALSE;
  op = find_op_by_id (dlg_handle, id);  
  if (op == NULL)
    return FALSE;
  if (op->type == MSF_DLG_TYPE_OPEN)
  {
    result->type = MSF_DLG_TYPE_OPEN;
    result->_u.data = MSF_MEM_ALLOCTYPE(dlg_handle->modid, msf_dlg_result_open_t);
    ((msf_dlg_result_open_t*)result->_u.data)->file_name = NULL;
    ((msf_dlg_result_open_t*)result->_u.data)->result = op->status;
    if (op->status == MSF_DLG_RETURN_OK){
      char *return_file_name;
      return_file_name = MSF_MEM_ALLOC(dlg_handle->modid, strlen(op->file_name) + 1);
      strcpy(return_file_name, op->file_name);
      ((msf_dlg_result_open_t*)result->_u.data)->file_name = return_file_name;
      free_dlg_op(dlg_handle, op);
    }
    else if (op->status == MSF_DLG_RETURN_CANCELLED){
      free_dlg_op(dlg_handle, op);
    }
    return TRUE;
  }
  else if (op->type == MSF_DLG_TYPE_SAVE_AS)
  {
    result->type = MSF_DLG_TYPE_SAVE_AS;
    result->_u.data = MSF_MEM_ALLOCTYPE(dlg_handle->modid, msf_dlg_result_save_as_t);
    ((msf_dlg_result_save_as_t*)result->_u.data)->file_name = NULL;
    ((msf_dlg_result_save_as_t*)result->_u.data)->result = op->status;
    if (op->status == MSF_DLG_RETURN_OK) {
      char *return_file_name;
      return_file_name = MSF_MEM_ALLOC(dlg_handle->modid, strlen(op->file_name) + 1);
      strcpy(return_file_name, op->file_name);
      ((msf_dlg_result_save_as_t*)result->_u.data)->file_name = return_file_name;
      free_dlg_op(dlg_handle, op);
    }
    else if (op->status == MSF_DLG_RETURN_CANCELLED){
      free_dlg_op(dlg_handle, op);
    }
    return TRUE;
  }
  else if (op->state == MSF_DLG_STATE_SAVE_AS_MSG_DLG){
    result->type = MSF_DLG_TYPE_SAVE_AS;
    result->_u.data = MSF_MEM_ALLOCTYPE(dlg_handle->modid, msf_dlg_result_save_as_t);
    ((msf_dlg_result_save_as_t*)result->_u.data)->file_name = NULL;
    ((msf_dlg_result_save_as_t*)result->_u.data)->result = op->status;
    return TRUE;
  }
  else
    return FALSE;
}


int
msf_dlg_result_free(msf_pck_handle_t* handle, msf_pck_result_t* result)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  if (!result)
    return FALSE;
  if (result->_u.data){
    if (result->type == MSF_DLG_TYPE_OPEN){
      if (((msf_dlg_result_open_t*)result->_u.data)->file_name)
        MSF_MEM_FREE( dlg_handle->modid , ((msf_dlg_result_open_t*)result->_u.data)->file_name);
      MSF_MEM_FREE( dlg_handle->modid , ((msf_dlg_result_open_t*)result->_u.data));
    }
    if (result->type == MSF_DLG_TYPE_SAVE_AS){
      if (((msf_dlg_result_save_as_t*)result->_u.data)->file_name)
        MSF_MEM_FREE( dlg_handle->modid , ((msf_dlg_result_save_as_t*)result->_u.data)->file_name);
      MSF_MEM_FREE( dlg_handle->modid , ((msf_dlg_result_save_as_t*)result->_u.data));
    }
  }

  return TRUE;
}

/*
 * Create an open dialog.
 *
 * Open parameters:
 *  screen        The screen that should be used for the dialog.
 *  permission    Do not show files when this permission(s) is not valid.
 *                E.g. if the caller will send forward the selected
 *                content, any DRM protected content must not be showed
 *                to the end user.
 *  mime_types    Which type of files that will be shown to the user.
 *                Wildcards is allowed in this parameter.
 * 
 * Returns a positive identifier if success, otherwise MSF_PACKAGE_ERROR.
 */
MSF_INT32
msf_dlg_create_open (msf_pck_handle_t* handle,
                     MsfScreenHandle screen,
                     int permission,
                     const char* mime_types)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  MsfDeviceProperties           prop;
  MsfElementPosition            choice_position;
  MsfPosition                   menuPosition;
  MsfPosition                   selectGroupPos = {0,0};
  msf_dlg_op_t                  *op = get_new_op (dlg_handle, MSF_DLG_TYPE_OPEN);
  msf_dlg_window_t              *navigate_window = get_new_window (dlg_handle, op);
  msf_dlg_gadget_t              *selectgroup = get_new_gadget(dlg_handle, navigate_window);
  msf_dlg_action_t              *action_ok = get_new_action(dlg_handle, navigate_window, MsfOk);
  msf_dlg_action_t              *action_back = get_new_action(dlg_handle, navigate_window, MsfBack);
  msf_pck_root_folders_t        *root_folders;
  MsfSize                       editable_size;

  op->permission = permission;
  op->state = MSF_DLG_STATE_OPEN_NAVIGATE; 
  op->mime_types = MSF_MEM_ALLOC(dlg_handle->modid, strlen(mime_types) +1 );
  op->screen = screen;
  strcpy(op->mime_types, mime_types);

  msf_pck_get_urf_from_mime (dlg_handle->modid, mime_types,  &root_folders);
  if (root_folders->n_rf == 1){
    char  urf_string[2] = {MSF_USER_FOLDER_ID_CHAR, '\0'};
    op->file_name = MSF_MEM_ALLOC(dlg_handle->modid, 2 + strlen(root_folders->rf[0].fld_id) + 2 + 1);
    strcpy(op->file_name, "/");
    strcat(op->file_name, urf_string);
    strcat(op->file_name, root_folders->rf[0].fld_id);
    strcat(op->file_name, urf_string);
    strcat(op->file_name, "/");
  }
  MSF_MEM_FREE(dlg_handle->modid, root_folders);

  choice_position.image1Pos=0;
  choice_position.string1Pos=1;
  choice_position.image2Pos=2;
  choice_position.string2Pos=3;
  choice_position.indexPos=4;
  choice_position.iconPos=5;

  MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
  menuPosition.x = (short)((prop.displaySize.width - (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH)) / 2);
  menuPosition.y = (short)((prop.displaySize.height - (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT)) / 2);

  prop.displaySize.height = (short) (prop.displaySize.height * MSF_DLG_MENU_SIZE_HEIGHT);
  prop.displaySize.width = (short) (prop.displaySize.width * MSF_DLG_MENU_SIZE_WIDTH);

  navigate_window->handle = MSF_WIDGET_FORM_CREATE (dlg_handle->modid, &prop.displaySize,
                                                MSF_WINDOW_PROPERTY_TITLE, 0);
  MSF_WIDGET_WINDOW_SPECIFIC_SIZE(navigate_window->handle, &editable_size, 0);
  selectgroup->handle = MSF_WIDGET_SELECTGROUP_CREATE (dlg_handle->modid, 
                                                     MsfExclusiveChoice, 
                                                     &editable_size, 
                                                     0, 
                                                     MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_STRING_2 | MSF_CHOICE_ELEMENT_IMAGE_1, 
                                                     0x8000, 
                                                     0);
  MSF_WIDGET_WINDOW_ADD_GADGET (navigate_window->handle, selectgroup->handle,
                                &selectGroupPos, 0);
  /* Create an OK action. */
	action_ok->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_OK), MsfOk, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (navigate_window->handle, action_ok->handle);
	
	/* Create a Back action.*/
	action_back->handle = MSF_WIDGET_ACTION_CREATE (dlg_handle->modid,
                           MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_DLG_ACTION_BACK), MsfBack, 3, MSF_ACTION_PROPERTY_ENABLED);
	MSF_WIDGET_ADD_ACTION (navigate_window->handle, action_back->handle);

  MSF_WIDGET_HANDLE_MSF_EVT (navigate_window->handle, MsfKey_Up,   TRUE, 0);
  MSF_WIDGET_HANDLE_MSF_EVT (navigate_window->handle, MsfKey_Down,   TRUE, 0);
  HDIa_widgetGetPattern(selectgroup->handle, 1, &(op->default_pattern)); 

  MSF_WIDGET_SCREEN_ADD_WINDOW (screen, navigate_window->handle,
                                &menuPosition, 0, 0);

  MSF_WIDGET_SET_IN_FOCUS (screen, 1);
  MSF_WIDGET_SET_IN_FOCUS (navigate_window->handle, 1);

  op->state = update_navigate_window(dlg_handle, navigate_window->handle, selectgroup->handle, mime_types, op->file_name, &(op->dir_entries), op);


  return op->id;
}




/*
 * Runs the DLG package. When the module receives a signal that is
 * defined by MSF, the module must call this function because the
 * DLG package might be the receiver.
 *
 *
 * Returns:
 *    MSF_PACKAGE_SIGNAL_NOT_HANDLED
 *    MSF_PACKAGE_SIGNAL_HANDLED
 *    MSF_PACKAGE_OPERATION_COMPLETE
 */
int
msf_dlg_handle_signal (msf_pck_handle_t *handle,
                       MSF_UINT16        signal,
                       void             *p,
                       MSF_INT32        *id)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  int dispatched;

  if (dlg_handle == NULL)
    return MSF_PACKAGE_SIGNAL_NOT_HANDLED;

  {
    MSF_INT32 afi_id;
    int afi_return;
    afi_return = msf_afi_handle_signal (dlg_handle->afi_handle, signal, p, &afi_id);
    if (afi_return == MSF_PACKAGE_SIGNAL_HANDLED) {
      msf_dlg_op_t *op = dlg_handle->op;
      
      if (msf_dlg_pipe_find_op_from_afi_id(handle, afi_id, id))
        return MSF_PACKAGE_SIGNAL_HANDLED;

      while (op->afi_id != afi_id)
        op = op->next;
      *id = op->id;
      return MSF_PACKAGE_SIGNAL_HANDLED;
    }
    else if (afi_return == MSF_PACKAGE_OPERATION_COMPLETE) { 
      msf_dlg_op_t *op = dlg_handle->op;
      msf_pck_result_t afi_result;
      
      if (msf_dlg_pipe_handle_afi_complete(handle, afi_id, id)){
        msf_afi_result_free(dlg_handle->afi_handle, &afi_result);
        return MSF_PACKAGE_SIGNAL_HANDLED;
      }
      
      while (op->afi_id != afi_id)
        op = op->next;
      *id = op->id;

      msf_afi_get_result(dlg_handle->afi_handle, afi_id, &afi_result);
      
      if (op->state == MSF_DLG_STATE_OPEN_NAVIGATE_DELAYED){
        op->state = update_navigate_window_continue(dlg_handle, op->window->gadget->handle,
                       op->mime_types, &(op->dir_entries), &afi_result, op);
        /* Do not free afi_result as it will be used and freed later */
        return MSF_PACKAGE_SIGNAL_HANDLED;
      }
      else if (op->state == MSF_DLG_STATE_SAVE_AS_NAVIGATE_DELAYED){
        op->state = update_navigate_save_window_continue(dlg_handle, op->window->gadget->handle,
                       &(op->dir_entries), &afi_result, op->file_name);
        /* Do not free afi_result as it will be used and freed later */
        return MSF_PACKAGE_SIGNAL_HANDLED;
      }
      else if (op->state == MSF_DLG_STATE_SAVE_AS_FILE_EXISTS_DELAYED){
#ifndef WAP_SUPPORT
        if ((MSF_INT32)(afi_result._u.data) != MSF_AFI_ERROR_PATH){
          create_exists_dialog(dlg_handle, op, op->entered_name);
          op->state = MSF_DLG_STATE_SAVE_AS_EXISTS_DIALOG;
        }
        else{
          char* temp_file_name;
          msf_afi_result_free(dlg_handle->afi_handle, &afi_result);
          temp_file_name = MSF_MEM_ALLOC(dlg_handle->modid, strlen(op->file_name) + strlen(op->entered_name) + 1 );
          strcpy(temp_file_name, op->file_name);
          strcat(temp_file_name, op->entered_name);
          MSF_MEM_FREE(dlg_handle->modid, op->file_name);
          op->file_name = temp_file_name;
          op->status = MSF_DLG_RETURN_OK;
          op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
          return MSF_PACKAGE_OPERATION_COMPLETE;
        }
#else
        kal_bool file_exist = KAL_FALSE;
        char* temp_file_name;

        if ((MSF_INT32)(afi_result._u.data) != MSF_AFI_ERROR_PATH)
          file_exist = KAL_TRUE;
          
        msf_afi_result_free(dlg_handle->afi_handle, &afi_result);
        temp_file_name = MSF_MEM_ALLOC(dlg_handle->modid, strlen(op->file_name) + strlen(op->entered_name) + 1 );
        strcpy(temp_file_name, op->file_name);
        strcat(temp_file_name, op->entered_name);
        MSF_MEM_FREE(dlg_handle->modid, op->file_name);
        
		if (file_exist)
		{
			char *posix_file_name;
			posix_file_name = msf_dlg_resolve_path(dlg_handle->modid, temp_file_name);
			if (posix_file_name)
			{
				MSF_FILE_REMOVE(posix_file_name);
				MSF_MEM_FREE(dlg_handle->modid, posix_file_name);
			}
		}
        
        op->file_name = temp_file_name;
        op->status = MSF_DLG_RETURN_OK;
        op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;
        return MSF_PACKAGE_OPERATION_COMPLETE;
#endif
      }
      else if (op->state == MSF_DLG_STATE_SAVE_AS_EXISTS_DELETE_DELAYED){
        if (afi_result._u.i_val == MSF_AFI_OK)
          op->status = MSF_DLG_RETURN_OK;
        else
          op->status = MSF_DLG_RETURN_CANCELLED;
        msf_afi_result_free(dlg_handle->afi_handle, &afi_result);
        op->state = MSF_DLG_STATE_SAVE_AS_FINISHED;        
        return MSF_PACKAGE_OPERATION_COMPLETE;
      }
      else if (op->state == MSF_DLG_STATE_NEW_DIR_AFI_DELAYED){
        if (afi_result._u.i_val == MSF_AFI_OK){
          free_dlg_window(handle, op, op->window->next);
          op->state = update_navigate_save_window(handle, op->window->handle, op->window->gadget->handle,
                                                         op->mime_types, op->file_name, &(op->dir_entries), op);
        }
        else {
          create_error_popup_window(handle, op, MSF_STR_ID_DLG_ERROR_CREATE_DIR, MSF_DLG_STATE_NEW_DIR_NAME_EDIT);
        }
      }
      msf_afi_result_free(dlg_handle->afi_handle, &afi_result);
      return MSF_PACKAGE_SIGNAL_HANDLED;
    }
  }


  switch(signal) {
  case MSF_SIG_WIDGET_ACTION:
    {
      msf_widget_action_t* action = (msf_widget_action_t*)p;
      MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, dlg_handle->modid,
                  MSF_DLG_B00AB33679E7A1A655784C3FE449641F, "DLG: Received MSF_SIG_WIDGET_ACTION\n"));
      dispatched = msf_dlg_handle_widget_action (dlg_handle, id, action->handle, action->action);
    }
    break;
   case MSF_SIG_GET_ICONS_RESPONSE:
    {
      msm_get_icons_resp_t *z;
      msf_dlg_op_t *op; 

      z = (msm_get_icons_resp_t*)p;
      op = find_op_by_id (dlg_handle, z->id);
      
      if(op == NULL)
        return MSF_PACKAGE_SIGNAL_NOT_HANDLED;

      if (dlg_handle->n_items != MSF_DLG_ICONS_NOT_LOADED)
        dispatched = MSF_PACKAGE_SIGNAL_HANDLED;

      dlg_handle->icons = z->icon_list;
      dlg_handle->n_items = z->n_items;
      
      z->icon_list = NULL;
      z->n_items   = 0;

      if (op->state == MSF_DLG_STATE_SAVE_AS_NAVIGATE_DELAYED){
            op->state = update_navigate_save_window(dlg_handle, op->window->handle, 
                                                    op->window->gadget->handle, 
                                                    op->mime_types, 
                                                    op->file_name, 
                                                    &(op->dir_entries), op);
      }
      else if (op->state == MSF_DLG_STATE_OPEN_NAVIGATE_DELAYED){
        op->state = update_navigate_window(dlg_handle, op->window->handle, 
                                                op->window->gadget->handle, 
                                                op->mime_types, 
                                                op->file_name, 
                                                &(op->dir_entries), op);

      }
      *id = op->id;
      dispatched = MSF_PACKAGE_SIGNAL_HANDLED;
    }
    break;

  case MSF_SIG_WIDGET_USEREVT:
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, dlg_handle->modid,
                MSF_DLG_0CAF6E28C5A8CCFE38A1FCF45B218F54, "DLG: Received MSF_SIG_WIDGET_USEREVT\n"));
    dispatched = msf_dlg_handle_user_evt (dlg_handle, id, ((msf_widget_userevt_t*)p)->handle,  ((msf_widget_userevt_t*)p)->event);

    break;
  
  case MSF_SIG_TIMER_EXPIRED:
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, dlg_handle->modid,
                 MSF_DLG_C56002BEFCF0F898D6CCDB8A49D9180E, "DLG: Received MSF_SIG_TIMER_EXPIRED\n"));
    dispatched = msf_dlg_handle_timer_expired(dlg_handle, id, ((msf_timer_expired_t *)p)->timerID);
    break;

  case MSF_SIG_PIPE_NOTIFY:
    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, dlg_handle->modid,
                  MSF_DLG_034023B356F0D6D7078865928A3760E0, "DLG: Received MSF_SIG_PIPE_NOTIFY\n"));
    dispatched = msf_dlg_handle_pipe_notify(dlg_handle, id, p);
    break;

  default:
    dispatched = MSF_PACKAGE_SIGNAL_NOT_HANDLED;
    break;
  }
  return dispatched;
}


/*
 * Set private data connected to a specific DLG identifier. The private data
 * might be used by the module to indicate which sub module that was
 * invoked the operation. 
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_dlg_set_private_data (msf_pck_handle_t *handle, MSF_INT32 id, void *p)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  msf_dlg_op_t *op = find_op_by_id (dlg_handle, id);
  if (!op)
    return FALSE;
  op->priv_data = p;
  return TRUE;
}

/*
 * Get private data connected to a specific identifier. The private data
 * might be used by the module to indicate where to continue execution.
 * This function may be called after msf_afi_run has returned 
 * MSF_PACKAGE_OPERATION_COMPLETE.
 * If success returns the private data, otherwise returns NULL.
 */
void*
msf_dlg_get_private_data (msf_pck_handle_t *handle, MSF_INT32 id)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  msf_dlg_op_t *op = find_op_by_id (dlg_handle, id);
  if (!op)
    return NULL;
  return op->priv_data;
}

int
msf_dlg_terminate (msf_pck_handle_t* handle)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;

  while (dlg_handle->op)
    free_dlg_op(dlg_handle, dlg_handle->op);
  msf_afi_terminate(dlg_handle->afi_handle);
  MSF_WIDGET_RELEASE (dlg_handle->folder_image);
  MSF_WIDGET_RELEASE (dlg_handle->file_image);
  {
    msf_dcvt_t cvt_obj;
    msf_dcvt_init (&cvt_obj, MSF_DCVT_FREE, NULL, 0, dlg_handle->modid);
    msf_dcvt_array (&cvt_obj, sizeof (msf_icon_list_t), dlg_handle->n_items,
                   (void **)&(dlg_handle->icons), (msf_dcvt_element_t *)msf_cvt_icon_list);

  }
  
  MSF_MEM_FREE(dlg_handle->modid, dlg_handle);
  

  return TRUE;
}

int
msf_dlg_delete (msf_pck_handle_t* handle, MSF_INT32 id)
{
  msf_dlg_handle_t* dlg_handle = (msf_dlg_handle_t*) handle;
  msf_dlg_op_t *op = find_op_by_id (dlg_handle, id);
  
  if (!op)
    return FALSE;

  free_dlg_op(dlg_handle, op);
  return TRUE;
}

