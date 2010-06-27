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

#ifndef _msf_sas_h
#define _msf_sas_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#ifndef _msf_pck_h
#include "msf_pck.h"
#endif


 /**********************************************************************
 * Defines 
 **********************************************************************/

#define MSF_SAS_RETURN_OK                0
#define MSF_SAS_RETURN_CANCELLED        -1
#define MSF_SAS_RETURN_NOT_AVAILABLE    -2
#define MSF_SAS_RETURN_ERROR            -3

/* operation types */
#define MSF_SAS_TYPE                     1

/* bit flags */
#define MSF_SAS_ALLOW_OVERWRITE         0x0001 /* Must be 0x0001 to allow backward compatibility*/
#define MSM_SAS_NO_EXTERNAL_MEMORY      0x0002 /*This flag is used to prevent object to be stored on external memory.*/
#define MSF_SAS_DO_NOT_SHOW_DIALOG      0x0004

/* Default afi-filename for files saved without dialogs shown */
#define MSF_SAS_CFG_DEFAULT_FILENAME "/:picture:/temp.dat"

/* Number of steps in which to update the progressbar */
#define MSF_SAS_CFG_PROGRESS_STEPS      100

/* If file size is unknown the progressbar will increase to this value (in bytes) and then restart */
#define MSF_SAS_CFG_BAR_DEFAULT_MAX_VALUE   20000

/* Defines if the save as file browser dialog should not be shown */
/* #define MSF_SAS_CFG_DO_NOT_SHOW_DIALOG */

/**********************************************************************
 * Global functions
 **********************************************************************/

/*
 * Initialise the save as package.
 * Returns a handle if success, otherwise returns NULL.
 */
msf_pck_handle_t*
msf_sas_init (MSF_UINT8 modId);

/*
 * Runs the save as package. When the module receives a signal that is
 * defined by MSF, the module must call this function because the
 * dialog package might be the receiver.
 *
 * Returns:
 *    MSF_PACKAGE_SIGNAL_NOT_HANDLED
 *      The signal was not handled by the package, the calling module
 *      must process the signal by itself.
 *    MSF_PACKAGE_SIGNAL_HANDLED
 *      The signal was handled by the package.
 *    MSF_PACKAGE_OPERATION_COMPLETE
 *      The signal was handled by the package and the save as operation is 
 *      finished. In this case the id parameter indicates which operation that 
 *      is finished. 
 */
int
msf_sas_handle_signal (msf_pck_handle_t* handle, MSF_UINT16 signal, void* p,
                       MSF_INT32* id);

/*
 * Set private data connected to a specific save as operation. The private 
 * data might be used by the module to indicate which sub module that started 
 * the save as operation. This function may be called after a
 * msf_sas_create_xxx function has been called.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_sas_set_private_data (msf_pck_handle_t* handle, MSF_INT32 id, void* p);

/*
 * Get private data connected to a specific save as operation. The private 
 * data might be used by the module to indicate which sub module that has
 * started the operation. This function may be called after 
 * msf_sas_handle_signal returned MSF_PACKAGE_OPERATION_COMPLETE.
 * If success returns the private data, otherwise returns MSF_PACKAGE_ERROR.
 */
void*
msf_sas_get_private_data (msf_pck_handle_t* handle, MSF_INT32 id);


/*
 * Terminates the save as package, release all resources allocated by
 * this package. If there is any open dialogs, these dialog are
 * deleted. Any private data must be released by the module itself.
 * Returns TRUE  if success, otherwise FALSE.
 */
int
msf_sas_terminate (msf_pck_handle_t* handle);

/**********************************************************************
 * Delete 
 **********************************************************************/

/*
 * Deletes a created save as operation. Any private data is not released by 
 * this function. The module call this function when the module of any
 * reason must delete the operation before the finished state has been
 * reached.
 * Returns TRUE  if success, otherwise FALSE.
 */
int
msf_sas_delete (msf_pck_handle_t* handle, MSF_INT32 id);

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
msf_sas_get_result(msf_pck_handle_t* handle, MSF_INT32 id, msf_pck_result_t* result);

/*
 * Free the storage allocated in the get result function
 *
 * Argument:
 * result       Result data to be freed.
 *
 * Returns:     TRUE if success, otherwise FALSE. 
 */

int
msf_sas_result_free(msf_pck_handle_t* handle, msf_pck_result_t* result);


/**********************************************************************
 * Save as Operation
 **********************************************************************/

typedef struct {
  int   result;              /* MSF_SAS_RETURN_OK if success, 
                                MSF_SAS_RETURN_CANCELLED if operation 
                                    was canceled by the user 
                                MSF_SAS_RETURN_NOT_AVAILABLE if result
                                    function is called when operation is 
                                    not finished
                                MSF_SAS_RETURN_ERROR if the operation was 
                                    aborted due to an unexpected error, 
                                    e.g. file error*/
  char  *file_name;          /* If result was MSF_SAS_RETURN_OK, there is a 
                                file name in this parameter, otherwise NULL.*/
  char  *fn_posix;           /* destination in posix format */
} msf_sas_result_save_as_t;


/*
 * Create a save as operation.
 *
 * Save as parameters:
 *  file_name             Suggested user friendly name of the file.
 *  mime_type             The mime type of file to save.
 *  data_type             Tells if the data to save comes from a pipe, file or
 *                        buffer. value must be one of the following constants:
 *                          MSF_PCK_DATA_TYPE_FILE,
 *                          MSF_PCK_DATA_TYPE_PIPE,
 *                          MSF_PCK_DATA_TYPE_BUFFER
 *  data                  The data that shall be written to file. This 
 *                        parameter is only used when data comes from a 
 *                        buffer. Note: This data must be available until the
 *                        operation is complete.      
 *  data_len              The size of the data. This parameter is only used 
 *                        when data comes from a buffer.
 *  pathname              The name of the pipe or file. This parameter is only
 *                        used when data comes from a pipe or a file.
 *  screen                The screen that should be used for the dialog.
 *  file_attrs            the file attributes that should be stored with the
 *                        specified file.
 *  bit_flag              MSF_SAS_ALLOW_OVERWRITE   -  if bit is set, the package will prompt
 *                          the user about the replace and possibly replace the existing file.
 *                        MSF_SAS_DO_NOT_SHOW_DIALOG   -  if bit is set, the package will not 
 *                          allow the user to select position or name of the file to save, but
 *                          the file will be saved to a temporary default position with a default
 *                          name.
 *                        MSM_SAS_NO_EXTERNAL_MEMORY - If this bit is set no folders on
 *                          external memory will be possible to select as save destination.
 * 
 * Returns positive number denoting an id if ok and MSF_PACKAGE_ERROR otherwise.
 */
MSF_INT32
msf_sas_create_save_as (msf_pck_handle_t* handle,
                        const char* file_name,
                        const char* mime_type,
                        int   data_type,
                        void* data,
                        long  data_len,
                        const char *pathname,
                        const msf_pck_attr_list_t *file_attrs,
                        MsfScreenHandle screen,
                        MSF_INT32 bit_flag);

/*
 * The get result function of a finished save as operation returnes the following values
 * The module must call this function when msf_sas_handle_signal has returned 
 * MSF_PACKAGE_OPERATION_COMPLETE for this specific operation. This function also releases 
 * all allocated  resources connected to the specific dialog, but only if the function 
 * is called when the operation is finished.  * Returns TRUE if success, otherwise FALSE.
 *
 * Parameter cast type: msf_sas_result_save_as_t
 *
 * Parameters:
 * 
 * result      					MSF_SAS_RETURN_OK if success, 
 *                              MSF_SAS_RETURN_CANCELLED if operation 
 *                                  was canceled by the user 
 *                              MSF_SAS_RETURN_NOT_AVAILABLE if result
 *                                  function is called when operation is 
 *                                  not finished
 *                                  aborted due to an unexpected error, 
 *                                  e.g. file error
 * char  *file_name;            If result was MSF_SAS_RETURN_OK, there is a 
 *                              file name in this parameter, otherwise NULL. 
 *
 */



#endif
