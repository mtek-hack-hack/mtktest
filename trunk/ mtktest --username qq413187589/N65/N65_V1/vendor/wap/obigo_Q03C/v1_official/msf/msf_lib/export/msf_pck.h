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

#ifndef _msf_pck_h
#define _msf_pck_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_rc_h
#include "msf_rc.h"
#endif


/**********************************************************************
 * Defines
 **********************************************************************/

#define MSF_PACKAGE_SIGNAL_HANDLED      1
#define MSF_PACKAGE_SIGNAL_NOT_HANDLED  2
#define MSF_PACKAGE_OPERATION_COMPLETE  3

/* Package return values */
#define MSF_PACKAGE_ERROR              -1 /* An error has occured */
#define MSF_PACKAGE_COMPLETED           0 /* e.g. an operation is complete */
#define MSF_PACKAGE_BUSY                1 /* e.g. operation delayed */

#define MSF_PCK_DATA_TYPE_FILE          0
#define MSF_PCK_DATA_TYPE_PIPE          1
#define MSF_PCK_DATA_TYPE_BUFFER        2

#define MSF_PCK_ATTR_TYPE_STRING        1
#define MSF_PCK_ATTR_TYPE_INT           2
#define MSF_PCK_ATTR_TYPE_BYTE          3


/*File Attributes*/
#define MSF_PCK_ATTRIBUTE_VENDOR            0x0001
#define MSF_PCK_ATTRIBUTE_DESCRIPTION       0x0002
#define MSF_PCK_ATTRIBUTE_CREATED           0x0004  /*Read only attribute set automatically by AFI*/
#define MSF_PCK_ATTRIBUTE_MIME              0x0008  /*Mimetype*/
#define MSF_PCK_ATTRIBUTE_DRM               0x0010  /*DRM permissions*/
#define MSF_PCK_ATTRIBUTE_ICON              0x0020  /*Posix Path to icon file*/
#define MSF_PCK_ATTRIBUTE_FLAGS             0x0040  /*Any of the flags defined below in file flags*/
#define MSF_PCK_ATTRIBUTE_SIZE              0x0080  /*File size not including the size 
                                                      needed to store file attributes*/
#define MSF_PCK_ATTRIBUTE_USER              0x0100  /*User supplied attribute which
                                                      is left untouched by the AFI.*/
#define MSF_PCK_ATTRIBUTE_MIME_INTERNAL     0x0200  /* Internal mime type. If the MIME attribute 
                                                       is e.g. application/vnd.oma.drm.content,
                                                       this attribute describes the mime type of
                                                       the object inside the DRM content */
#define MSF_PCK_ATTRIBUTE_RIGHTS_ISSUER_URL 0x0400  /* The rights issuer url to a DRM content. */
#define MSF_PCK_ATTRIBUTE_CONTENT_URI       0x0800  /* The content uri to a DRM content. */




/*File Flags*/
#define MSF_PCK_FLAG_PROTECTED        0x0001   /*This file is protected and cannot
                                                 be removed*/
#define MSF_PCK_FLAG_USER_PROTECTED   0x0002   /*If set this file has been locked 
                                                 for changed by the user, Users may
                                                 unlock this protection*/
#define MSF_PCK_FLAG_NAME_PROTECTED   0x0004   /*The name of this file is protected
                                                 and cannot be changed*/
#define MSF_PCK_FLAG_DRM_FORWARD_LOCK 0x0008   /* This DRM file is forward locked. */

#define MSF_PCK_FLAG_DRM_CONSUMABLE   0x0010   /* This DRM file has consumable rights. */


/* Other Defines*/

#define MSF_USER_FOLDER_ID_CHAR  ':' /*This character is used as the first and last
                                       character of User Root Folder and User Folder
                                       directory names used in pathnames */

#define MSF_USER_ROOT_FOLDER_TYPE       0
#define MSF_USER_FOLDER_TYPE            1  /*NOT IMPLEMENTED*/

/**********************************************************************
 * Types
 **********************************************************************/
typedef void msf_pck_handle_t;

typedef struct {
  MSF_INT32    id;
  const void  *private_data;
} msf_pck_pd_item_t;

typedef struct {
  int               num_items;
  msf_pck_pd_item_t list[1];
} msf_pck_pd_list_t;

/*Types used for handling file attributes.*/
typedef struct msf_pck_attr_list_st {
  struct msf_pck_attr_list_st *next;
  MSF_UINT8      type;        /* Type of attribute value*/
  MSF_UINT32     attribute;   /* The attribute */
  union {
    char        *s;
    MSF_INT32    i;
    struct {
      MSF_UINT8 *b_value;
      MSF_INT32  b_len;
    } bv;
  } _u;
} msf_pck_attr_list_t;

/*User Folder types*/
typedef struct {
  MSF_UINT32   str_id;
  const char  *fld_id;
  int          external;
} msf_pck_root_folder_item_t;

typedef struct {
  int                        n_rf;
  msf_pck_root_folder_item_t rf[1];
} msf_pck_root_folders_t;

typedef struct {
  MSF_UINT32   str_id;
  const char  *fld_id;
} msf_pck_user_folder_item_t;

typedef struct {
  int                        n_uf;
  msf_pck_user_folder_item_t uf[1];
} msf_pck_user_folders_t;

/* Result data type. Each module defines and use its own type values */
typedef struct {
  MSF_INT8     type;  /* result type Package specific*/
  union {
    void      *data;  /* data to cast to result type */
    MSF_INT32  i_val;
  } _u;
  void        *additional_data;  /* data to cast to additional result type */
} msf_pck_result_t;

/* Description of mandatory package functions. */

/**********************************************************************
 * Functions to get information from the User Root Folder and 
 * User Folders table.
 **********************************************************************/


/*
 * This function returns the maximum folder depth of the specified root
 * folder.
 */
int 
msf_pck_get_urf_max_depth (const char *folder_id);

/*
 * This function returns the absolute posix path to the root 
 * folder associated with the folder id.
 */
const char * const
msf_pck_get_posix_path (const char *folder_id);

/*
 * This function returns the user folder's parent folder_id. If the
 * user folder is not found (i.e. if the folder id belongs to a
 * user root folder) NULL is returned.
 */
const char * const
msf_pck_get_parent_folder_id (const char *user_folder_id);

/*
 * This function returns String resource id for the specified root folder. 
 * The type parameter is used to indicate if this is a User Root Folder or
 * a User Folder. 
 * NOTE! The Type parameter must be set to MSF_USER_ROOT_FOLDER_TYPE in
 *       this implementation.
 */
MSF_UINT32
msf_pck_get_res_id_from_uf_id (const char *folder_id, int type);


/*
 * This function returns a list of root folders defined to be used to 
 * contain the specified content type.
 */
void
msf_pck_get_urf_from_mime (MSF_UINT8               mod_id,
                           const char             *mime_type,
                           msf_pck_root_folders_t **result);

/*
 * This function returns a list of all User Root Folders.
 */
void
msf_pck_get_all_root_folders (MSF_UINT8                mod_id,
                              msf_pck_root_folders_t **result);

/*
 * This function returns a list of all User Folders.
 */
void
msf_pck_get_all_user_folders (MSF_UINT8                mod_id,
                              msf_pck_user_folders_t **result);

/*
 * This function returns a localized version of the pathname parameter.
 * It is the callers responsibility to free the returned string
 */
char *
msf_pck_get_localized_pathname (MSF_UINT8 mod_id, const char *pathname);

/*
 * This function returns a localized version of the user folder name parameter 
 * (where the folder name parameter includes the MSF_USER_FOLDER_ID_CHAR).
 * It is the callers responsibility to free the returned string
 */
char *
msf_pck_get_localized_uf (MSF_UINT8 mod_id, const char *pathname);

/* Returns TRUE if path is a user folder name. */
int
msf_pck_is_uf (MSF_UINT8 mod_id, const char *path);

/*
 * This function returns a localized version of the user folder name
 * parameter, where the folder name parameter does not include any
 * MSF_USER_FOLDER_ID_CHAR. The current working directory is supplied in cwd.
 * It is the callers responsibility to free the returned string
 */
char *
msf_pck_get_local_uf (MSF_UINT8   mod_id,
                      const char *cwd,
                      const char *folder);

/**********************************************************************
 * Functions to create file attribute lists
 **********************************************************************/
/*
 * Initializes the supplied file attribute list. Must be called 
 * before adding anything to the list.
 */
void
msf_pck_attr_init (msf_pck_attr_list_t **p);

/*
 * Free the memory held by the file attribute list pointer.
 */
void
msf_pck_attr_free (MSF_UINT8 modid, msf_pck_attr_list_t *p);

/*
 * Adds a string attribute to the file attribute list.
 * Returns TRUE if successful.
 *
 * Arguments:
 * modid      (IN)      The module identifier 
 * p          (IN/OUT)  The list to which the attribute will be added.
 * attribute  (IN)      The attribute identifier as defined above.
 * s          (IN)      The string to add.
 */
int
msf_pck_add_attr_string_value (MSF_UINT8             modid,
                               msf_pck_attr_list_t **p,
                               MSF_UINT32            attribute,
                               const char           *s);

/*
 * Adds an integer attribute to the file attribute list.
 * Returns TRUE if successful.
 *
 * Arguments:
 * modid      (IN)      The module identifier 
 * p          (IN/OUT)  The list to which the attribute will be added.
 * attribute  (IN)      The attribute identifier as defined above.
 * i          (IN)      The integer value to add.
 */
int
msf_pck_add_attr_int_value (MSF_UINT8             modid,
                            msf_pck_attr_list_t **p,
                            MSF_UINT32            attribute,
                            MSF_INT32             i);

/*
 * Adds a byte string attribute to the file attribute list.
 * Returns TRUE if successful.
 *
 * Arguments:
 * modid      (IN)      The module identifier 
 * p          (IN/OUT)  The list to which the attribute will be added.
 * attribute  (IN)      The attribute identifier as defined above.
 * bv         (IN)      The byte value to add.
 * length     (IN)      The length in bytes of the byte value to add.
 */
int
msf_pck_add_attr_byte_value (MSF_UINT8             modid,
                             msf_pck_attr_list_t **p,
                             MSF_UINT32            attribute,
                             const unsigned char  *bv,
                             long int              length);

/*
 * Returns the size in bytes of the memory occupied by the supplied file
 * attribute list.
 */
int
msf_pck_attr_get_size (const msf_pck_attr_list_t *p);

/*
 * Create a string corresponding to a file attribute list.
 * NOTE: it is the caller's responsibility to deallocate the string.
 */
void
msf_pck_attr_to_string (MSF_UINT8                   modid,
                        const msf_pck_attr_list_t  *p,
                        long                       *length,
                        unsigned char             **attr_string);

/*
 * Create a file attribute list corresponding to a string.
 * NOTE: it is the caller's responsibility to deallocate the
 * returned attribute list.
 */
msf_pck_attr_list_t *
msf_pck_attr_to_list (MSF_UINT8      modid,
                      long           length,
                      unsigned char *attr_string);

/*
 * Duplicates the file attribute list supplied.
 * NOTE: it is the caller's responsibility to deallocate the
 * returned file attribute list.
 */
msf_pck_attr_list_t *
msf_pck_attr_dupl (MSF_UINT8                   modid,
                   const msf_pck_attr_list_t  *p);


/**********************************************************************
 * Utility functions for mime types
 **********************************************************************/

MSF_BOOL
msf_pck_mime_type_in_list (const char *mime_type, const char *mime_list);


#endif

