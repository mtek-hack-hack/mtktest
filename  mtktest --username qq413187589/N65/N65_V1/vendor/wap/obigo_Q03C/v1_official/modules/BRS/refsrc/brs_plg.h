/*
 * Copyright (C) Obigo AB, 2002-2007.
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
 * brs_plg.h
 *
 * Created by Anders Edenbrandt, Mon Oct 14 13:29:50 2002.
 *
 * Revision history:
 *
 */
/************************************************************
 * API for plug-ins
 ************************************************************/
#ifndef _brs_plg_h
#define _brs_plg_h

#ifndef  _msf_def_h
#include "msf_def.h"
#endif


/************************************************************
 * Constants
 ************************************************************/

/* The different types of plug-ins supported */
#define BRS_PLG_TYPE_REQUEST_URL                  1
#define BRS_PLG_TYPE_PROCESS_CONTENT              2
#define BRS_PLG_TYPE_RUN_WMLS_FUNC                3

/* Status codes, used in ... */
#define BRS_PLG_STATUS_OK                         0
#define BRS_PLG_STATUS_NO_NAVIGATION              1
#define BRS_PLG_STATUS_EXTERNAL_DISPLAY           2

/* Types of WMLScript variables */
#define BRS_PLG_WMLS_VAR_INVALID                  0
#define BRS_PLG_WMLS_VAR_INTEGER                  1
#define BRS_PLG_WMLS_VAR_FLOAT                    2
#define BRS_PLG_WMLS_VAR_STRING                   3
#define BRS_PLG_WMLS_VAR_BOOLEAN                  4

/* Error codes returned by read/write operations on sinks/sources: */
#define BRS_PLG_ERROR_DELAYED                     -1
#define BRS_PLG_ERROR_EOF                         -2
#define BRS_PLG_ERROR                             -3


/************************************************************
 * Type definitions
 ************************************************************/

/* WMLScript variable: used for parameters and return values
 * for WMLScript Function plug-ins */
typedef struct {
  char type;
  union {
    MSF_INT32    i_val;
    MSF_FLOAT32  f_val;
    MSF_BOOL     b_val;
    struct {
      int   charset;
      int   s_len;
      char *s;
    } s_val;
  } _u;
} brs_plg_wmls_var_t;

/* Function parameter for the request function */
typedef union {
  struct {
    char *url;
    char *fragment;
    char *headers;
  } request_url;

  struct {
    char *url;
    char *fragment;
    char *headers;
    void *doc;
  } proc_cont;

  struct {
    int                 lib_index;
    int                 func_index;
    int                 num_params;
    brs_plg_wmls_var_t *params;
  } run_wmls_func;
} brs_plg_request_data_t;

/* Function parameter for the response function */
typedef union {
  struct {
    int   status_code;
    char *headers;
  } request_url;

  struct {
    int status_code;
  } proc_cont;

  struct {
    int                 status_code;
    brs_plg_wmls_var_t *result;
  } run_wmls_func;
} brs_plg_response_data_t;

typedef union {
  struct {
    int empty;
  } request_url;

  struct {
    int empty;
  } proc_cont;

  struct {
    int num_params;
  } run_wmls_func;
} brs_plg_info_t;

/****************************************
 * Functions implemented by a plug-in.
 ****************************************/

typedef struct brs_plg_st brs_plg_t;

/*
 * Called to initialize a new plug-in instance.
 */
typedef void
brs_plg_instantiate_t (brs_plg_t *pl);

/*
 * Called each time the plug-in gets to run.
 */
typedef void
brs_plg_run_t (brs_plg_t *pl);

/*
 * Called when a plug-in instance is being deleted.
 * Should deallocate any private data.
 */
typedef void
brs_plg_delete_t (brs_plg_t *pl);

/*
 * Called to deliver the initial request to the plug-in.
 */
typedef void
brs_plg_request_t (brs_plg_t *pl, brs_plg_request_data_t *req);

/*
 * Called to deliver the response to a HTTP request.
 */
typedef void
brs_plg_http_response_t (brs_plg_t *pl, int http_status,
                         int stream_id, char *headers);

/*
 * Called to deliver a signal to the plug-in. 
 */
typedef void
brs_plg_sig_response_t (brs_plg_t *pl, int signal, int value);

/*
 * The plug-in type.
 */
struct brs_plg_st {
  brs_plg_run_t           *pl_run;
  brs_plg_delete_t        *pl_delete;
  brs_plg_request_t       *pl_request;
  brs_plg_sig_response_t  *pl_sig_response;
  brs_plg_http_response_t *pl_http_response;

  int                      pl_id;          /* Plug-in ID, filled in by BRS */
  int                      pl_instance_id; /* BRS instance using this plug-in
                                            * (filled in by BRS)*/
  void                    *pl_data;        /* Plug-in private data */
};


/************************************************************
 * Functions
 ************************************************************/

/*
 * Register a plug-in.
 * For a plug-in of type
 *   BRS_PLG_TYPE_REQUEST_URL, the 'descriptor' parameter is a scheme name
 *   BRS_PLG_TYPE_PROCESS_CONTENT, a MIME content-type
 *   BRS_PLG_TYPE_RUN_WMLS_FUNCTION, a lib index and func index, e.g., "12/34"
 * Returns a handle that can be used when calling brs_plg_deregister below,
 * or -1 on error.
 */
int
brs_plg_register (int plugin_type,
                  const char *descriptor,
                  brs_plg_info_t *info,
                  brs_plg_instantiate_t *instantiate);

/*
 * Remove a plug-in from the set of registered plug-ins.
 */
void
brs_plg_deregister (int handle);


/**************************************************
 * Functions implemented by BRS,
 * callable from a plug-in:
 **************************************************/

/*
 * Schedule the plug-in to be run again.
 * When next it becomes the plug-in's turn to run,
 * the function pl->pl_run will be called.
 */
void
brs_plg_schedule (brs_plg_t *pl);

/*
 * Called to deliver information about the processing
 * of a request.
 */
void
brs_plg_response (brs_plg_t *pl, brs_plg_response_data_t *res);

/*
 * Called when a plug-in instance has finished its work
 * and can be removed. The actual removal of
 * the plug-in instance is initiated by the browser who
 * calls pl->pl_delete.
 */
void
brs_plg_done (brs_plg_t *pl);

/*
 * Called when a plug-in instance has encountered
 * an error and wants to abort processing.
 * Just as with brs_plg_done, the actual removal of
 * the plug-in instance is initiated by the browser who
 * calls pl->pl_delete.
 */
void
brs_plg_abort (brs_plg_t *pl, int error_code);

/*
 * Request the retrieval of a resource indicated by the URL.
 * The response comes by way of calling the function pl_http_response
 * in the plug-in structure.
 * Returns a stream ID that is later passed back in the callback
 * function, or -1 on error.
 */
int
brs_plg_http_request (brs_plg_t *pl, char *url, char *headers);

/*
 * Write data to the plug-ins data sink.
 * Returns the actual number of bytes written,
 * or -1 on error (e.g., if the read end of the stream has been closed).
 */
int
brs_plg_sink_write (brs_plg_t *pl, void *buf, int buf_len);

/*
 * Close the data sink.
 */
void
brs_plg_sink_close (brs_plg_t *pl);

/*
 * Read from a data source.
 * Returns the actual number of bytes read,
 * or -1 on error (e.g., if the write end of the stream has been closed).
 */
int
brs_plg_source_read (brs_plg_t *pl, int source_id, void *buf, int buf_len);

/*
 * Close a data source.
 */
void
brs_plg_source_close (brs_plg_t *pl, int source_id);

/*
 * Attach a charset-converting filter to an input source.
 * This way, input is automatically converted to UTF-8.
 * Returns -1 on error, and 0 otherwise.
 */
int
brs_plg_source_attach_read_filter (brs_plg_t *pl, int source_id, int charset);

/*
 * Delete an array of WMLScript variables.
 */
void
brs_plg_wmlsvar_array_delete (int num_elements, brs_plg_wmls_var_t *var);

/*
 * Set a WML variable in the Browser's context.
 */
void
brs_plg_set_wml_variable (brs_plg_t *pl, char *name, char *value);

/*
 * Get the value of a WML variable in the Browser's context.
 * The plug-in must free the returned string (using brs_plg_free).
 */
char *
brs_plg_get_wml_variable (brs_plg_t *pl, char *name);


/*
 * Allocate memory.
 */
void *
brs_plg_alloc (int size);

/*
 * Free memory allocated with brs_plg_alloc.
 */
void
brs_plg_free (void *p);

#endif
