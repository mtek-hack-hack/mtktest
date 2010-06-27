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

#ifndef _msf_act_h
#define _msf_act_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_pck_h
#include "msf_pck.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif


 /**********************************************************************
 * Defines 
 **********************************************************************/

/* Action types */
#define MSF_MIME_ACTION_TYPE_EXTERNAL    1
#define MSF_MIME_ACTION_TYPE_INTERNAL    2
#define MSF_MIME_ACTION_TYPE_PACKET      3
#define MSF_MIME_ACTION_TYPE_CATEGORY    4

/*Return codes*/
#define MSF_ACT_OK               0
#define MSF_ACT_CANCELLED       -1
#define MSF_ACT_ERROR_ACCESS    -2
#define MSF_ACT_ERROR_DELAYED   -3
#define MSF_ACT_ERROR_PATH      -4
#define MSF_ACT_ERROR_INVALID   -5

#define MSF_ACT_ERROR_INTERNAL  -6  /*This should be the last error code*/

/* operation types */
#define MSF_ACT_GET_ACTIONS      1
#define MSF_ACT_OBJECT_ACTION    2

/* Defines the Action command used for internal packets */
#define MSF_PACKET_OPERATION_ID_SAS      "save"

/* Blocked permissions */
#define MSF_PERMISSION_NONE_BLOCKED      0x0000
#define MSF_PERMISSION_FORWARD_BLOCKED   0x0002


 /**********************************************************************
 * Types
 **********************************************************************/
typedef struct {
  MSF_INT32             action_id;
  MSF_INT32             string_id;
  char*                 act_cmd;
} msf_act_action_entry_t;

typedef struct {
  MSF_INT32               result;
  MSF_INT32               num_actions;
  msf_act_action_entry_t  action_list[1];  /* List of actions. */
} msf_act_result_get_actions_t;

typedef struct msf_act_mime_action_st {
  char*                   mime_types;
  char*                   act_cmd;
  MSF_UINT8               modid;
  MSF_UINT32              name_id;
  int                     act_type;
  int                     category;
  MSF_UINT32              blocked_permissions;
} msf_act_mime_action_t;

/**********************************************************************
 * Global functions
 **********************************************************************/

/*
 * Initialises the action package.
 * Returns a handle if success, otherwise returns NULL.
 */
msf_pck_handle_t*
msf_act_init (MSF_UINT8 modId);

/*
 * Runs the action package. When the module receives a signal that is
 * defined by MSF, the module must call this function because the
 * action package might be the receiver.
 *
 * Returns:
 *    MSF_PACKAGE_SIGNAL_NOT_HANDLED
 *      The signal was not handled by the package, the caller
 *      must process the signal by itself.
 *    MSF_PACKAGE_SIGNAL_HANDLED
 *      The signal was handled by the package.
 *    MSF_PACKAGE_OPERATION_COMPLETE
 *      The signal was handled by the package and the operation is
 *      finished. In this case the id parameter indicates which operation
 *      that has finished. 
 */
int
msf_act_handle_signal (msf_pck_handle_t* handle, MSF_UINT16 signal,
                       void* p, MSF_INT32* id);

/*
 * Set private data connected to a specific operation. The private data
 * might be used by the module to indicate which sub module that
 * created the operation. This function may be called after a
 * operation function has been called and an operation id is available.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_act_set_private_data (msf_pck_handle_t* handle,
                          MSF_INT32 id, void* p);

/*
 * Get private data connected to a specific operation. The private data
 * might be used by the module to indicate which sub module that
 * created the operation. This function may be called after
 * msf_act_handle_signal has returned MSF_PACKAGE_OPERATION_COMPLETE.
 * If success returns the private data, otherwise returns NULL.
 */
void*
msf_act_get_private_data (msf_pck_handle_t* handle, MSF_INT32 id);

/*
 * Terminates the action package, release all resources allocated by
 * this package. If there are any unfinished operations, these operations are
 * deleted. Any private data must be released by the module itself.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_act_terminate (msf_pck_handle_t* handle);

/**********************************************************************
 * Delete 
 **********************************************************************/

/*
 * Deletes an unfinished operation. Any private data is not released by this
 * function. The module call this function when the module of any
 * reason must delete the operation before the finished state has been
 * reached.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_act_delete (msf_pck_handle_t* handle, MSF_INT32 id);

/**********************************************************************
 * Result
 **********************************************************************/

/*
 * Get the result of a completed operation. The caller must
 * call this function when msf_act_handle_signal has returned
 * MSF_PACKAGE_OPERATION_COMPLETE for this specific operation. This
 * function also releases all allocated resources connected to the
 * specific operation , but only if the function is called when the
 * operation is finished. Any private data associated with this 
 * operation must be freed by the using module before this function
 * is called.
 *
 * Arguments:
 * handle       The handle to the struct that holds action package information.
 * id           The id to the operation instance
 * result       The function initializes this parameter with current result
 *              type containing status code and optionally result
 *              data of the operation.
 *
 *              function                  result has a data that should be casted to:
 *              msf_act_get_actions       msf_act_result_get_actions_t *
 *              msf_act_object_action     MSF_INT32
 *
 *
 * Returns:     MSF_PACKAGE_ERROR on failure
 *              MSF_PACKAGE_COMPLETED if operation has finished
 *              MSF_PACKAGE_BUSY if operation has not finished yet
 */
int
msf_act_get_result(msf_pck_handle_t* handle, MSF_INT32 id, msf_pck_result_t* result);

/*
 * Free the storage allocated in the get result function
 *
 * Argument:
 * result       Result data to be freed.
 *
 * Returns:     TRUE if success, otherwise FALSE. 
 */

int
msf_act_result_free(msf_pck_handle_t* handle, msf_pck_result_t* result);



/**********************************************************************
 * Get actions
 **********************************************************************/

/* This operation is used to recieve the actions available for a specific mime type.
 * 
 * handle        The handle to the struct that holds all action package 
 *               information.
 * mime_type     The suitable actions for this mime type will be recieved
 * check_blocked_permission  DRM permission of the file. Specifïes the
 *                           permission(s) to be checked wether blocked  
 *                           or not (requested permission).
 *
 * Returns:      An id to this get action operation or MSF_PACKAGE_ERROR
 *   
 */

MSF_INT32
msf_act_get_actions    (msf_pck_handle_t  *handle,
                        const char        *mime_type,
                        MSF_INT32          check_blocked_permission);


#ifdef MSF_CFG_OBJECT_ACTION_EXT
/* This operation is used to recieve the actions available for a specific mime type.
 * 
 * handle        The handle to the struct that holds all action package 
 *               information.
 * mime_type     The suitable actions for this mime type will be recieved
 * check_blocked_permission  DRM permission of the file. Specifïes the
 *                           permission(s) to be checked wether blocked  
 *                           or not (requested permission).
 * excl_act_strings          An array of string pointers. Each string
 *                           (or command string) identifies an action
 *                           or a sub-action. All actions.and sub-actions
 *                           in this array will be excluded from the result.
 *                           That is, they are excluded when searching for
 *                           actions for the given mime type.
 * excl_act_strings_cnt      The number of strings in excl_act_strings.
 *
 * Returns:      An id to this get action operation or MSF_PACKAGE_ERROR
 *   
 */

MSF_INT32
msf_act_get_actions_ext(msf_pck_handle_t  *handle,
                        const char        *mime_type,
                        MSF_INT32          check_blocked_permission,
                        const char*        excl_act_strings[],
                        MSF_INT32          excl_act_strings_cnt);
#endif

/**********************************************************************
 * Object action
 **********************************************************************/

/* This operation performs the action specified by the action_id. If the action
 * needs more specified information from the end user, these dialogs are handled by
 * the operation
 * 
 * handle       The handle to the struct that holds all action package 
 *              information.
 * action_id    The identifier to the action to perform
 * mime_type    The mime type of file to perform the action on.
 * data_type    Tells if the data to perform the action on comes from a pipe, file or
 *              buffer. value must be one of the following constants:
 *                MsfResourceFile
 *                MsfResourcePipe
 *                MsfResourceBuffer
 * data         This parameter is only used when data comes from a 
 *              buffer. Note: This data must be available until the
 *              operation is complete.      
 * data_len     The size of the data. This parameter is only used 
 *              when data comes from a buffer.
 * src_path     The name of the pipe or file. This parameter is only
 *              used when data comes from a pipe or a file.
 * file_attrs   The file attributes of the file to perform the action on.
 * file_name    Optional file name that may specify for instance a destination
 *              file name.
 * check_blocked_permission  DRM permission of the file. Specifïes the
 *                           permission(s) to be checked wether blocked  
 *                           or not (requested permission).
 * screen       The screen that should be used for dialogs.
 *
 * Returns:     An id to this object action operation or MSF_PACKAGE_ERROR
 *   
 */
MSF_INT32
msf_act_object_action  (msf_pck_handle_t          *handle,
                        MSF_INT32                  action_id,
                        const char                *mime_type,
                        MsfResourceType            data_type,
                        void                      *data,
                        long                       data_len,
                        const char                *src_path,
                        const msf_pck_attr_list_t *file_attrs,
                        const char                *file_name,
                        MSF_INT32                  check_blocked_permission,
                        MsfScreenHandle            screen);


#ifdef MSF_CFG_OBJECT_ACTION_EXT
/* This operation performs the action specified by the action_id. If the action
 * needs more specified information from the end user, these dialogs are handled by
 * the operation
 * 
 * handle       The handle to the struct that holds all action package 
 *              information.
 * action_id    The identifier to the action to perform
 * mime_type    The mime type of file to perform the action on.
 * data_type    Tells if the data to perform the action on comes from a pipe, file or
 *              buffer. value must be one of the following constants:
 *                MsfResourceFile
 *                MsfResourcePipe
 *                MsfResourceBuffer
 * data         This parameter is only used when data comes from a 
 *              buffer. Note: This data must be available until the
 *              operation is complete.      
 * data_len     The size of the data. This parameter is only used 
 *              when data comes from a buffer.
 * src_path     The name of the pipe or file. This parameter is only
 *              used when data comes from a pipe or a file.
 * file_attrs   The file attributes of the file to perform the action on.
 * file_name    Optional file name that may specify for instance a destination
 *              file name.
 * check_blocked_permission  DRM permission of the file. Specifïes the
 *                           permission(s) to be checked wether blocked  
 *                           or not (requested permission).
 * screen                    The screen that should be used for dialogs.
 * excl_act_strings          An array of string pointers. Each string
 *                           (or command string) identifies an action
 *                           or a sub-action. All sub-actions in this
 *                           array will be excluded in any dialogs to 
 *                           the end user. The same excl_act_strings
 *                           parameter as in msf_act_get_actions should
 *                           be passed here.
 * excl_act_strings_cnt      The number of strings in excl_act_strings.
 *
 * Returns:     An id to this object action operation or MSF_PACKAGE_ERROR
 *   
 */
MSF_INT32
msf_act_object_action_ext(msf_pck_handle_t          *handle,
                          MSF_INT32                  action_id,
                          const char                *mime_type,
                          MsfResourceType            data_type,
                          void                      *data,
                          long                       data_len,
                          const char                *src_path,
                          const msf_pck_attr_list_t *file_attrs,
                          const char                *file_name,
                          MSF_INT32                  check_blocked_permission,
                          MsfScreenHandle            screen,
                          const char*                excl_act_strings[],
                          MSF_INT32                  excl_act_strings_cnt);
#endif

/* This operation performs the action specified by the action_id. If the action
 * needs more specified information from the end user, these dialogs are handled by
 * the operation
 * 
 * handle       The handle to the struct that holds all action package 
 *              information.
 * action_id    The identifier to the action to perform
 * mime_type    The mime type of file to perform the action on.
 * data_type    Tells if the data to perform the action on comes from a pipe, file or
 *              buffer. value must be one of the following constants:
 *                MsfResourceFile
 *                MsfResourcePipe
 *                MsfResourceBuffer
 * data         This parameter is only used when data comes from a 
 *              buffer. Note: This data must be available until the
 *              operation is complete.      
 * data_len     The size of the data. This parameter is only used 
 *              when data comes from a buffer.
 * src_path     The name of the pipe or file. This parameter is only
 *              used when data comes from a pipe or a file.
 * file_attrs   The file attributes of the file to perform the action on.
 * file_name    Optional file name that may specify for instance a destination
 *              file name.
 * check_blocked_permission  DRM permission of the file. Specifïes the
 *                           permission(s) to be checked wether blocked  
 *                           or not (requested permission).
 * screen                    The screen that should be used for dialogs.
 * content_type              The content type. Pass NULL if the content
 *                           type is same as mime_type. Otherwise
 *                           content type can for example be a DRM type or 
 *                           some other envelope type. This parameter
 *                           is passed on to the receiver of the object
 *                           action. 
 * excl_act_strings          An array of string pointers. Each string
 *                           (or command string) identifies an action
 *                           or a sub-action. All sub-actions in this
 *                           array will be excluded in any dialogs to 
 *                           the end user. The same excl_act_strings
 *                           parameter as in msf_act_get_actions should
 *                           be passed here.
 * excl_act_strings_cnt      The number of strings in excl_act_strings.
 *
 * Returns:     An id to this object action operation or MSF_PACKAGE_ERROR
 *   
 */
MSF_INT32
msf_act_object_action_drm(msf_pck_handle_t          *handle,
                          MSF_INT32                  action_id,
                          const char                *mime_type,
                          MsfResourceType            data_type,
                          void                      *data,
                          long                       data_len,
                          const char                *src_path,
                          const msf_pck_attr_list_t *file_attrs,
                          const char                *file_name,
                          MSF_INT32                  check_blocked_permission,
                          MsfScreenHandle            screen,
                          const char                *content_type, /* Presently, only passed on to internal actions. */
                          const char*                excl_act_strings[],
                          MSF_INT32                  excl_act_strings_cnt);



#endif
