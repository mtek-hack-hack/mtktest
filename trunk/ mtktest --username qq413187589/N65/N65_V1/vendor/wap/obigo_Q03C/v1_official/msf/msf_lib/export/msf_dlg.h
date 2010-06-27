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

#ifndef _msf_dlg_h
#define _msf_dlg_h

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

/*Dialog return values*/
#define MSF_DLG_RETURN_OK                0
#define MSF_DLG_RETURN_CANCELLED        -1
#define MSF_DLG_RETURN_TIME_OUT         -2
#define MSF_DLG_RETURN_NOT_AVAILABLE    -3

/*Dialog timeout defines to be used as prefered value*/
#define MSF_DLG_TIMOUT_INFINITE          0
#define MSF_DLG_TIMOUT_ALERT         10000
#define MSF_DLG_TIMOUT_WARNING       10000
#define MSF_DLG_TIMOUT_INFO          10000
#define MSF_DLG_TIMOUT_ERROR             MSF_DLG_TIMOUT_INFINITE

/*Dialog result types*/
#define MSF_DLG_TYPE_SAVE_AS             1
#define MSF_DLG_TYPE_OPEN                2

/* bit flags */
#define MSF_DLG_ALLOW_OVERWRITE         0x0001 /* Must be 0x0001 to allow backward compatibility*/
#define MSM_DLG_NO_EXTERNAL_MEMORY      0x0002 /*This flag is used to prevent objects to be stored on external memory.*/

/*DRM Permissions*/
#define MSF_DLG_PERMISSION_ALL              0x0001
#define MSF_DLG_PERMISSION_FORWARD          0x0002


 /**********************************************************************
 * Types
 **********************************************************************/

/**********************************************************************
 * Global constants
 **********************************************************************/

extern const unsigned char msf_dlg_folder_image[];
extern const unsigned short msf_dlg_folder_image_size;
extern const unsigned char msf_dlg_file_image[];
extern const unsigned short msf_dlg_file_image_size;

/**********************************************************************
 * Global functions
 **********************************************************************/

/*
 * Initialise the dialog package.
 * Returns a handle if success, otherwise returns NULL.
 */
msf_pck_handle_t*
msf_dlg_init (MSF_UINT8 modId);

/*
 * Runs the dialog package. When the module receives a signal that is
 * defined by MSF, the module must call this function because the
 * dialog package might be the receiver.
 *
 * Returns:
 *    MSF_PACKAGE_SIGNAL_NOT_HANDLED
 *      The signal was not handled by the package, the caller
 *      must process the signal by itself.
 *    MSF_PACKAGE_SIGNAL_HANDLED
 *      The signal was handled by the package.
 *    MSF_PACKAGE_OPERATION_COMPLETE
 *      The signal was handled by the package and the dialog is
 *      finished. In this case the id parameter indicates which dialog
 *      that has finished. 
 */
int
msf_dlg_handle_signal (msf_pck_handle_t* handle, MSF_UINT16 signal,
                       void* p, MSF_INT32* id);

/*
 * Set private data connected to a specific dialog. The private data
 * might be used by the module to indicate which sub module that was
 * created the dialog. This function may be called after a
 * msf_dlg_create_xxx function has been called.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_dlg_set_private_data (msf_pck_handle_t* handle,
                          MSF_INT32 id, void* p);

/*
 * Get private data connected to a specific dialog. The private data
 * might be used by the module to indicate which sub module that was
 * created the dialog. This function may be called after
 * msf_dlg_handle_signal has returned MSF_PACKAGE_OPERATION_COMPLETE.
 * If success returns the private data, otherwise returns NULL.
 */
void*
msf_dlg_get_private_data (msf_pck_handle_t* handle, MSF_INT32 id);

/*
 * Terminates the dialog package, release all resources allocated by
 * this package. If there is any open dialogs, these dialog are
 * deleted. Any private data must be released by the module itself.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_dlg_terminate (msf_pck_handle_t* handle);

/**********************************************************************
 * Delete 
 **********************************************************************/

/*
 * Deletes a created dialog. Any private data is not released by this
 * function. The module call this function when the module of any
 * reason must delete the dialog before the finished state has been
 * reached.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_dlg_delete (msf_pck_handle_t* handle, MSF_INT32 id);

/**********************************************************************
 * Result
 **********************************************************************/

/*
 * Get the result of a completed operation. The caller must
 * call this function when msf_dlg_handle_signal has returned
 * MSF_PACKAGE_OPERATION_COMPLETE for this specific dialog. This
 * function also releases all allocated resources connected to the
 * specific dialog , but only if the function is called when the
 * operation is finished. Any private data associated with this 
 * operation must be freed by the using module before this function
 * is called.
 * Returns TRUE if success, otherwise FALSE.
 */

int
msf_dlg_get_result(msf_pck_handle_t* handle, MSF_INT32 id, msf_pck_result_t* result);

/*
 * Free the storage allocated in the get result function
 *
 * Argument:
 * result       Result data to be freed.
 *
 * Returns:     TRUE if success, otherwise FALSE. 
 */

int
msf_dlg_result_free(msf_pck_handle_t* handle, msf_pck_result_t* result);



/**********************************************************************
 * Save as dialog
 **********************************************************************/

typedef struct {
  int   result;              /* MSF_DLG_RETURN_OK - the user selected a
                                file name,
                                MSF_DLG_RETURN_CANCELLED if user canceled
                                dialog.
                                MSF_DLG_RETURN_NOT_AVAILABLE if the dialog
                                is still active
                             */
  char  *file_name;          /* If result was TRUE, there is a file
                                name (including path) in this parameter,
                                otherwise NULL. */
} msf_dlg_result_save_as_t;


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
                        MSF_INT32 bit_flag);

/*
 * Get the result of a completed save as operation. The caller must
 * call this function when msf_dlg_handle_signal has returned
 * MSF_PACKAGE_OPERATION_COMPLETE for this specific dialog. This
 * function also releases all allocated resources connected to the
 * specific dialog , but only if the function is called when the
 * operation is finished.
 * Returns TRUE if success, otherwise FALSE.
 */

/**********************************************************************
 * Open dialog
 **********************************************************************/
typedef struct {
  int   result;              /* MSF_DLG_RETURN_OK - the user selected a
                                file,
                                MSF_DLG_RETURN_CANCELLED if user canceled
                                dialog.
                                MSF_DLG_RETURN_NOT_AVAILABLE if the dialog
                                is still active
                              */
  char  *file_name;          /* If result was TRUE, there is a file
                                name (including path) in this parameter,
                                otherwise NULL. */
} msf_dlg_result_open_t;

/*
 * Create an open dialog.
 *
 * Open parameters:
 *  screen        The screen that should be used for the dialog.
 *  permission    Do not show files when this permission(s) is not valid.
 *                E.g. if the caller will send forward the selected
 *                content, any DRM protected content must not be showed
 *                to the end user.
 * 
 *                MSF_DLG_PERMISSION_ALL              All files are shown
 *                MSF_DLG_PERMISSION_FORWARD          Forward locked files 
 *                                                    are not shown
 *
 *  mime_types    Which type of files that will be shown to the user.
 *                Wildcards is allowed in this parameter.
 * 
 * Returns a positive identifier if success, otherwise MSF_PACKAGE_ERROR.
 */
MSF_INT32
msf_dlg_create_open (msf_pck_handle_t* handle,
                     MsfScreenHandle screen,
                     int permission,
                     const char* mime_types);

/*
 * Get the result of a completed open operation. The caller must call
 * this function when msf_dlg_handle_signal has returned
 * MSF_PACKAGE_OPERATION_COMPLETE for this specific dialog. This
 * function also releases all allocated resources connected to the
 * specific dialog, but only if the function is called when the
 * operation is finished.
 * Returns TRUE if success, otherwise FALSE.
 */

#endif
