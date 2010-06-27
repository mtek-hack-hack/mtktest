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
 * msf_afi.h 
 *
 * Advanced File Interface:
 * 
 * This package allow files to be saved with long (more than 8+3 
 * characters) file names. The file_name must be encoded using 
 * utf-8. The only restriction put on the filenames other than the
 * utf-8 encoding is that the character ':' is used as first and  
 * last character in folders defined by the MSF. This character  
 * MUST therefore not be the first character of of any other file 
 * or directory name 
 *
 * Created by Tomas Mandorf
 *
 * Revision  history:
 */

#ifndef _msf_afi_h
#define _msf_afi_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_pck_h
#include "msf_pck.h"
#endif

/**********************************************************************
 * Defines 
 **********************************************************************/
/*Return codes*/
#define MSF_AFI_OK                     0
#define MSF_AFI_ERROR_ACCESS          -1
#define MSF_AFI_ERROR_DELAYED         -2
#define MSF_AFI_ERROR_PATH            -3
#define MSF_AFI_ERROR_INVALID         -4
#define MSF_AFI_ERROR_SIZE            -5
#define MSF_AFI_ERROR_FULL            -6
#define MSF_AFI_ERROR_EOF             -7 
#define MSF_AFI_ERROR_EXIST           -8
#define MSF_AFI_ERROR_EXIST_LOCKED    -9 /* This code implies MSF_AFI_ERROR_EXIST */
#define MSF_AFI_ERROR_INTERNAL        -10  /* This should be the last error code */

/*Flags to be used with open file operation. 
  It is not possible to combine flags*/
#define MSF_AFI_RDONLY            1 /* Open file in read only mode */
#define MSF_AFI_WRONLY            2 /* Open file in write only mode. Creates
                                       new file if path do not exist*/
#define MSF_AFI_RDWR              3 /* Open file in read/write mode. Creates
                                       new file if path do not exist*/

#define MSF_AFI_OVERWRITE         0x1

#define MSF_AFI_MAX_FILE_READ_SIZE  512

/* operation types */
#define MSF_AFI_OPEN              1
#define MSF_AFI_CLOSE             2
#define MSF_AFI_READ              3
#define MSF_AFI_WRITE             4
#define MSF_AFI_SAVE              5
#define MSF_AFI_REMOVE            6
#define MSF_AFI_RENAME            7
#define MSF_AFI_SET_ATTR          8
#define MSF_AFI_GET_ATTR          9
#define MSF_AFI_GET_DIR           10
#define MSF_AFI_MKDIR             11
#define MSF_AFI_DELETE            12
#define MSF_AFI_EXIST             13

/* If no chars in the string supplied can be used as target filename, then
 * this string will be used as a base for that name.
 */
#define MSF_AFI_POSIX_FILENAME_FALLBACK   "posix"

/**********************************************************************
 * Types
 **********************************************************************/
typedef struct {
  MSF_INT32 result;     /* Result code for the operation:
                            MSF_AFI_OK
                            MSF_AFI_ERROR_EOF
                            MSF_AFI_ERROR_ACCESS 
                            MSF_AFI_ERROR_DELAYED 
                            MSF_AFI_ERROR_INVALID 
                            MSF_AFI_ERROR_EXIST*/
  int       file_handle; /* use in subsequent read/write etc. */
  char     *file_name;   /* posix format */
} msf_afi_result_open_t;

typedef struct {
  MSF_INT32  result;     /* Result code for the operation:
                              MSF_AFI_OK
                              MSF_AFI_ERROR_EOF
                              MSF_AFI_ERROR_ACCESS 
                              MSF_AFI_ERROR_DELAYED 
                              MSF_AFI_ERROR_INVALID */
  void      *data;       /* Pointer to data buffer supplied in 
                            the msf_afi_read call*/
  long       data_len;   /* Actual number of bytes read.
                            If result equals MSF_AFI_OK, this
                            value is the same as the input
                            parameter. If the result is 
                            MSF_AFI_ERROR_EOF the number of 
                            bytes read might be less than the 
                            requested. In all other cases this
                            parameter is set to zero*/
} msf_afi_result_read_t;

typedef struct {
  long   bytes_saved;
  char  *file_name; /* in posix format */
} msf_afi_additional_data_save_t;

typedef struct {
  MSF_INT32            result;     /* Result code for the operation*/
  msf_pck_attr_list_t *attr_list;  /* The attributes */
} msf_afi_result_get_attributes_t ;

typedef struct {
  MSF_BOOL             is_dir;    /* TRUE if Directory, else FALSE */
  char                *name;      /* Directory/File name */
  msf_pck_attr_list_t *attr_list; /* Attributes associated with the file.*/
} msf_afi_file_t;

typedef struct {
  MSF_INT32       result;
  int             num_entries;
  msf_afi_file_t  entry_list[1];  /* List of files and directories.*/
} msf_afi_result_dir_entries_t;


/**********************************************************************
 * Global functions
 **********************************************************************/

/*
 * Initialise the AFI package.
 * Returns a handle if success, otherwise returns NULL.
 */
msf_pck_handle_t *
msf_afi_init (MSF_UINT8 modid);

/*
 * Runs the AFI package. When the module receives a signal that is
 * defined by MSF, the module must call this function because the
 * AFI package might be the receiver.
 *
 * Returns:
 *    MSF_PACKAGE_SIGNAL_NOT_HANDLED
 *    MSF_PACKAGE_SIGNAL_HANDLED
 *    MSF_PACKAGE_OPERATION_COMPLETE
 */
int
msf_afi_handle_signal (msf_pck_handle_t *handle,
                       MSF_UINT16        signal,
                       void             *p,
                       MSF_INT32        *id);

/*
 * Set private data connected to a specific AFI identifier. The private data
 * might be used by the module to indicate which sub module that was
 * invoked the operation.
 * Returns TRUE if success, otherwise FALSE.
 */
int
msf_afi_set_private_data (msf_pck_handle_t *handle, MSF_INT32 id, void *p);

/*
 * Get private data connected to a specific identifier. The private data
 * might be used by the module to indicate where to continue execution.
 * This function may be called after msf_afi_run has returned 
 * MSF_PACKAGE_OPERATION_COMPLETE.
 * If success returns the private data, otherwise returns NULL.
 */
void *
msf_afi_get_private_data (msf_pck_handle_t *handle, MSF_INT32 id);

/*
 * Terminates the AFI package, release all resources allocated by
 * this package. If there are any open Files or other operations,
 * these will be deleted. Any private data must be released by the
 * module itself before this function is called.
 */
int
msf_afi_terminate (msf_pck_handle_t *handle);

/**********************************************************************
 * Delete
 **********************************************************************/
/*
 * Deletes an operation. Any private data is not released by this function.
 * The module calls this function when the module, for some reason must
 * delete the dialog before the finished state has been reached.
 * NOTE! Delete only works on the Save operation when saving from a pipe.
 *
 * handle   The handle to the struct that holds all file package information.
 * id       The id to the operation instance that is to be deleted
 * Returns: An id to this delete operation or MSF_PACKAGE_ERROR
 */
MSF_INT32
msf_afi_delete (msf_pck_handle_t *handle, MSF_INT32 id);

/**********************************************************************
 * Result
 **********************************************************************/
/*
 * Get the result from an operation
 *
 * handle The handle to the struct that holds file package information.
 * id     The id to the operation instance
 * result The function initializes this parameter with current result type
 *        containing status code and optionally result data of the operation.
 *        All functions may return MSF_AFI_ERROR_INTERNAL status code.
 *        All functions may return MSF_AFI_ERROR_DELAYED status code except
 *        msf_afi_close.
 *        All functions may return MSF_AFI_OK status code except msf_afi_exist.
 *
 *        Function/result type      Possible status codes
 *        msf_afi_open              MSF_AFI_ERROR_ACCESS  MSF_AFI_ERROR_PATH
 *                                  MSF_AFI_ERROR_PATH    MSF_AFI_ERROR_SIZE
 *                                  MSF_AFI_ERROR_FULL    MSF_AFI_ERROR_EXIST
 *          msf_afi_result_open_t
 *
 *        msf_afi_close             MSF_AFI_ERROR_INVALID
 *          MSF_INT32
 *
 *        msf_afi_read              MSF_AFI_ERROR_ACCESS  MSF_AFI_ERROR_INVALID
 *                                  MSF_AFI_ERROR_EOF
 *          msf_afi_result_read_t
 *
 *        msf_afi_write             MSF_AFI_ERROR_ACCESS  MSF_AFI_ERROR_INVALID
                                    MSF_AFI_ERROR_SIZE    MSF_AFI_ERROR_FULL
 *          MSF_INT32
 *
 *        msf_afi_save              MSF_AFI_ERROR_ACCESS  MSF_AFI_ERROR_INVALID
                                    MSF_AFI_ERROR_SIZE    MSF_AFI_ERROR_FULL
 *          MSF_INT32
 *
 *        msf_afi_remove            MSF_FILE_ERROR_ACCESS MSF_AFI_ERROR_PATH
 *                                  MSF_AFI_ERROR_INVALID
 *          MSF_INT32
 *
 *        msf_afi_rename            MSF_AFI_ERROR_ACCESS  MSF_AFI_ERROR_PATH
 *                                  MSF_AFI_ERROR_EXIST   MSF_AFI_ERROR_INVALID
 *          MSF_INT32
 *
 *        msf_afi_set_attributes    MSF_AFI_ERROR_PATH    MSF_AFI_ERROR_INVALID
 *          MSF_INT32
 *
 *        msf_afi_get_attributes    MSF_AFI_ERROR_PATH
 *          msf_afi_result_get_attributes_t *
 *
 *        msf_afi_get_dir_entries   MSF_AFI_ERROR_PATH    MSF_AFI_ERROR_INVALID
 *          msf_afi_result_dir_entries_t *
 *
 *        msf_afi_delete            MSF_AFI_ERROR_INVALID
 *          MSF_INT32
 *
 *        msf_afi_mkdir             MSF_AFI_ERROR_ACCESS  MSF_AFI_ERROR_PATH
 *                                  MSF_AFI_ERROR_FULL    MSF_AFI_ERROR_EXIST
 *          MSF_INT32
 *
 *        msf_afi_exist             MSF_AFI_ERROR_PATH  MSF_AFI_ERROR_EXIST
 *                                  MSF_AFI_ERROR_INVALID
 *          MSF_INT32
 *
 *        function                  additional data is a pointer to:
 *        msf_afi_save              msf_afi_additional_data_save_t
 *
 * Returns:
 *        MSF_PACKAGE_ERROR on failure
 *        MSF_PACKAGE_COMPLETED if operation has finished
 *        MSF_PACKAGE_BUSY if operation has not finished yet
 */
int
msf_afi_get_result (msf_pck_handle_t *handle,
                    MSF_INT32         id,
                    msf_pck_result_t *result);

/*
 * Free the storage allocated in the get result function
 *
 * handle       The handle to the struct that holds file package information.
 * result       Result data to be freed.
 *
 * Returns:     TRUE if success, otherwise FALSE.
 */
int
msf_afi_result_free (msf_pck_handle_t *handle, msf_pck_result_t *result);

/**********************************************************************
 * Save
 **********************************************************************/
/* This function is used to save a pipe, file, or buffer in a file with a
 * specified file name.
 *
 * handle     The handle to the struct that holds file package information.
 * file_name  Null terminated string containing the unique name of the file
 *            to save.
 * data_type  Tells if the data to save comes from a pipe, file or buffer.
 *            The value must be one of the following:
 *                 MSF_PCK_DATA_TYPE_FILE,
 *                 MSF_PCK_DATA_TYPE_PIPE,
 *                 MSF_PCK_DATA_TYPE_BUFFER
 * data_len   The size of the data.
 *            Used only when the data source is a buffer.
 * data       The data that shall be written to file.
 *            Used only when the data source is a buffer.
 * pathname   The name of the pipe or file. This parameter is only used when
 *            data comes from a pipe or file.
 * file_attr  File attribute list.
 *
 * Returns:   An id to this save operation or MSF_PACKAGE_ERROR
 */
MSF_INT32
msf_afi_save (msf_pck_handle_t          *handle,
              const char                *file_name,
              int                        data_type,
              long                       data_len,
              const char                *data,
              const char                *pathname,
              const msf_pck_attr_list_t *file_attr);
/*
 * flags      Save flags. Possible values are:
 *              MSF_AFI_OVERWRITE
 */
MSF_INT32
msf_afi_save_ext (msf_pck_handle_t          *handle,
                  const char                *file_name,
                  int                        data_type,
                  long                       data_len,
                  const char                *data,
                  const char                *pathname,
                  const msf_pck_attr_list_t *file_attr,
                  MSF_UINT32                 flags);

/**********************************************************************
 * Open
 **********************************************************************/
/* Initializes the specified file for read/write operations. It it not
 * necessary to open a file before its attributes are set/retrieved.
 *
 * NOTE! One (1) instance of the AFI package can only open one (1) instance of
 *       a file.
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_name   Null terminated string containing the unique name of the file
 *             to open. The filename cannot end with a '/'.
 * mode        The open mode to be used. Possible modes defined above.
 * attr_list   The list of file attributes that are set on creation.
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR: 
 *             NOTE! If the open operation may be delayed. This is not an
 *             error and the function returns an id, and therefore the 
 *             msf_afi_get_result must be called to determine if the 
 *             file is ready to be manipulated.
 */
MSF_INT32
msf_afi_open (msf_pck_handle_t          *handle,
              const char                *file_name,
              int                        mode,
              const msf_pck_attr_list_t *attr_list);

/**********************************************************************
 * Close
 **********************************************************************/
/* Closes the specified file.
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_handle The AFI handle returned from the Open operation.
 *
 * Returns:    An id or MSF_PACKAGE_ERROR
 *             NOTE! The close operation may be delayed. This is not an  
 *             error and the function returns an id, and therefore the 
 *             msf_afi_get_result must be called to determine if the 
 *             file is closed.
 */
MSF_INT32
msf_afi_close (msf_pck_handle_t *handle, MSF_INT32 file_handle);

/**********************************************************************
 * Write
 **********************************************************************/
/* Writes the specified number of bytes to the file pointed at by 
 * the file_handle parameter. The function does not return finished 
 * until all bytes have been written. If all bytes can not be written the 
 * function returns an error
 *
 * NOTE! It is not possible to make more than one (1) simultaneous write 
 *       operation on the same file handle. 
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_handle AFI File handle returned from the Open operation.
 * data        The data to be written.
 * data_len    The size in bytes of the data parameter.
 *
 * Returns:    An id for operation or MSF_PACKAGE_ERROR if failure.
 *             NOTE! The write operation may be delayed. This is not an  
 *             error and the function returns an id, and therefore the 
 *             msf_afi_get_result must be called to determine if the 
 *             operation is finished.
 */
MSF_INT32
msf_afi_write (msf_pck_handle_t *handle,
               MSF_INT32         file_handle,
               void             *data,
               long              data_len);

/**********************************************************************
 * Read
 **********************************************************************/
/* Reads the specified number of bytes from the file associated with 
 * the file_handle parameter. The function does not return Finished
 * until all bytes have been read. If it is not possible to read the
 * specified number of bytes the number of actually read bytes will 
 * be returned in the msf_afi_get_result call.
 * 
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_handle AFI File handle returned from the Open operation.
 * data        data buffer
 * data_len    Number of bytes to read into the data buffer.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR.
 *             NOTE! The read operation may be delayed. This is not an  
 *             error and the function returns an id, and therefore the 
 *             msf_afi_get_result must be called to determine if the 
 *             operation is finished.
 */
MSF_INT32
msf_afi_read (msf_pck_handle_t  *handle,
              MSF_INT32          file_handle,
              void              *data,
              long               data_len);

/**********************************************************************
 * Seek
 **********************************************************************/
/* Moves the file pointer of an open file, If the seek operation exceeds the
 * limits of the file an error is returned. Offset may be negative.
 * 
 * NOTE! This function is always synchronous and therefore do not implement  
 *       a get result function.
 *
 * file_handle AFI File handle returned from the Open operation.
 * offset      Distance in bytes to move.
 * seek_mode   Where from the offset should be counted.
 *             HDI_FILE_SEEK_SET offset from start of file
 *             HDI_FILE_SEEK_CUR relative offest from current position
 *             HDI_FILE_SEEK_END offset from end of file  
 *
 * Returns:    The new position of the file pointer, or a negative value
 *             if an error occurred - error codes:
 *
 *             MSF_AFI_ERROR_ACCESS The file was opened in 
 *                HDI_FILE_SET_APPEND mode. 
 *             MSF_AFI_ERROR_INVALID e.g. the fileHandle argument is not 
 *                an open file descriptor or the requested new cursor position
 *                exceeds the limits of the file.
 */
MSF_INT32
msf_afi_seek (msf_pck_handle_t  *handle,
              MSF_INT32          file_handle,
              long               offset,
              int                seek_mode);

/**********************************************************************
 * Remove
 **********************************************************************/
/* This function must be used to remove files
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * item        Null terminated string containing the unique name of the file
 *             to delete.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR.
 *             NOTE! The remove operation may be delayed. This is not an
 *             error and the function returns an id, and therefore the 
 *             msf_afi_get_result must be called to determine if the 
 *             operation is finished.
 */
MSF_INT32
msf_afi_remove (msf_pck_handle_t *handle, const char *item);


/**********************************************************************
 * Set attributes
 **********************************************************************/
/* Runs the set attributes operation that is used to set file attributes 
 * for a specific file.
 * 
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_name   Null terminated string containing the unique name of the file 
 *             to which the attributes will be set.
 * attr_list   A list of attributes.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR.
 *             NOTE! The set attributes operation may be delayed. This is
 *             not an  error and the function returns an id, and therefore
 *             the msf_afi_get_result must be called to  determine if the
 *             operation is finished.
 */
MSF_INT32
msf_afi_set_attributes (msf_pck_handle_t          *handle,
                        const char                *file_name,
                        const msf_pck_attr_list_t *attr_list);

/**********************************************************************
 * Get attributes
 **********************************************************************/
/* This operation is used to get attributes associated with a specific file.
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_name   Null terminated string containing the unique name of the file
 *             that has the attributes that shall be returned.
 * bit_mask    Bit mask to specify which attributes to return. If this flag
 *             is set to 0 all attributes will be returned.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR,
 *             NOTE! The get attributes operation may be delayed. This is
 *             not an  error and the function returns an id, and therefore 
 *             the msf_afi_get_result must be called to determine if the
 *             operation is finished.
 */
MSF_INT32
msf_afi_get_attributes (msf_pck_handle_t  *handle,
                        const char        *file_name,
                        MSF_UINT32         bit_mask);

/**********************************************************************
 * Get dir entries
 **********************************************************************/
/* This operation is used to get a list of all files and subdirectories
 * for a given directory.
 * 
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * dir_name    Null terminated string containing the unique name of the 
 *             directory that shall be read.
 * bit_mask    Bit mask to specify which attributes for each file and folder
 *             to include in the result If this flag is set to 0 all 
 *             attributes will be returned.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR,
 *             NOTE! The get dir entries operation may be delayed. This is  
 *             not an  error and the function returns an id, and therefore 
 *             the msf_afi_get_result must be called to  
 *             determine if the operation is finished.
 */
MSF_INT32
msf_afi_get_dir_entries (msf_pck_handle_t *handle,
                         const char       *dir_name,
                         MSF_UINT32        bit_mask);

/**********************************************************************
 * Rename
 **********************************************************************/
/* This operation is used to rename the file specified by 
 * old_name to the name specified by new_name. 
 * 
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * old_name    Null terminated string describing the old filename.
 * new_name    Null terminated string describing the new filename.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR,
 *             NOTE! The rename operation may be delayed. This is not an 
 *             error and the function returns an id, and therefore 
 *             the msf_afi_get_result must be called to determine if the 
 *             operation is finished.
 */
MSF_INT32
msf_afi_rename (msf_pck_handle_t *handle,
                const char       *old_name,
                const char       *new_name);

/**********************************************************************
 * Make Directory
 **********************************************************************/
/* This operation is used to create a new directory.
 * 
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * dir_name    Null terminated string describing path name of the directory 
 *             to create. More than one level of directories will be created
 *             if the path requires it.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR.
 *             NOTE! The mkdir operation may be delayed. This is
 *             not an  error and the function returns an id, and therfore 
 *             the msf_afi_get_result_mk_dir must be called to  
 *             determine if the operation is finished. 
 */
MSF_INT32
msf_afi_mkdir (msf_pck_handle_t *handle, const char *dir_name);

/**********************************************************************
 * Get Size of Directory
 **********************************************************************/
/* This function is used to determine the total size of the directory
 * including subdirectories. NOTE: only user root folders and user folders
 * are applicable.
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * dir_name    Null terminated string describing path name of the directory.
 *
 * Returns:    The size of the directory or NULL if dir_name is invalid.
 *             NOTE! This operation is synchronous.
 */
long
msf_afi_get_dir_size (msf_pck_handle_t *handle, const char *dir_name);

/**********************************************************************
 * Exist
 **********************************************************************/
/* Check if a specific file exist with attributes.
 *
 * handle      The handle to the struct that holds the file package instance
 *             data.
 * file_name   Null terminated string containing the name of the file that 
 *             should be checked for existence.
 *
 * Returns:    An id for the operation or MSF_PACKAGE_ERROR.
 *             NOTE! The exist operation may be delayed. This is not an error.
 *             The msf_afi_get_result must be called using the id to
 *             determine if the operation is finished.
 */
MSF_INT32
msf_afi_exist (msf_pck_handle_t *handle, const char *file_name);

#endif /*_msf_afi_h*/
