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
 * msf_core.h
 *
 * Created by Ingmar Persson
 *
 * Revision history:
 *
 */
#ifndef _msf_core_h
#define _msf_core_h

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"
#endif
#ifndef _msf_int_h
#include "msf_int.h"
#endif

/**********************************************************************
 * Global MSF Signals in Moblie Suite
 **********************************************************************/

#define MSF_SIG_MODULE_START            ((MSF_MODID_MSM << 8) + 0x01)
#define MSF_SIG_MODULE_TERMINATE        ((MSF_MODID_MSM << 8) + 0x02)
#define MSF_SIG_MODULE_STATUS           ((MSF_MODID_MSM << 8) + 0x03)
#define MSF_SIG_MODULE_EXECUTE_COMMAND  ((MSF_MODID_MSM << 8) + 0x04)

#define MSF_SIG_TIMER_SET               ((MSF_MODID_MSM << 8) + 0x05)
#define MSF_SIG_TIMER_RESET             ((MSF_MODID_MSM << 8) + 0x06)
#define MSF_SIG_TIMER_EXPIRED           ((MSF_MODID_MSM << 8) + 0x07)

#define MSF_SIG_WIDGET_NOTIFY           ((MSF_MODID_MSM << 8) + 0x08)
#define MSF_SIG_WIDGET_ACTION           ((MSF_MODID_MSM << 8) + 0x09)
#define MSF_SIG_WIDGET_USEREVT          ((MSF_MODID_MSM << 8) + 0x0A)
#define MSF_SIG_WIDGET_ACCESS_KEY       ((MSF_MODID_MSM << 8) + 0x0B)

#define MSF_SIG_PIPE_NOTIFY             ((MSF_MODID_MSM << 8) + 0x0C)

#define MSF_SIG_SOCKET_CONNECT_RESPONSE ((MSF_MODID_MSM << 8) + 0x0D)
#define MSF_SIG_SOCKET_NOTIFY           ((MSF_MODID_MSM << 8) + 0x0E)
#define MSF_SIG_SOCKET_HOST_BY_NAME     ((MSF_MODID_MSM << 8) + 0x0F)

#define MSF_SIG_FILE_NOTIFY             ((MSF_MODID_MSM << 8) + 0x10)

#define MSF_SIG_REG_SET                 ((MSF_MODID_MSM << 8) + 0x11)
#define MSF_SIG_REG_GET                 ((MSF_MODID_MSM << 8) + 0x12)
#define MSF_SIG_REG_DELETE              ((MSF_MODID_MSM << 8) + 0x13)

#define MSF_SIG_REG_RESPONSE            ((MSF_MODID_MSM << 8) + 0x14)

#define MSF_SIG_CONTENT_SEND            ((MSF_MODID_MSM << 8) + 0x15)
#define MSF_SIG_CONTENT_SEND_ACK        ((MSF_MODID_MSM << 8) + 0x16)

#define MSF_SIG_TEL_MAKE_CALL_RESPONSE  ((MSF_MODID_MSM << 8) + 0x17)
#define MSF_SIG_TEL_SEND_DTMF_RESPONSE  ((MSF_MODID_MSM << 8) + 0x18)

#define MSF_SIG_PB_ADD_ENTRY_RESPONSE   ((MSF_MODID_MSM << 8) + 0x19)

#define MSF_SIG_GET_ICONS               ((MSF_MODID_MSM << 8) + 0x1A)
#define MSF_SIG_GET_ICONS_RESPONSE      ((MSF_MODID_MSM << 8) + 0x1B)

#define MSF_SIG_OBJECT_ACTION           ((MSF_MODID_MSM << 8) + 0x1C)

#define MSF_SIG_PIM_OPEN_RESPONSE       ((MSF_MODID_MSM << 8) + 0x1D)
#define MSF_SIG_PIM_CLOSE_RESPONSE      ((MSF_MODID_MSM << 8) + 0x1E)
#define MSF_SIG_PIM_ADDR_LOOKUP_RESPONSE      ((MSF_MODID_MSM << 8) + 0x1F)
#define MSF_SIG_PIM_ADDR_LOOKUP_NAME_RESPONSE ((MSF_MODID_MSM << 8) + 0x20)
#define MSF_SIG_PIM_ADDR_GET_RECORD_RESPONSE  ((MSF_MODID_MSM << 8) + 0x21) 
#define MSF_SIG_PIM_ADDR_SET_RECORD_RESPONSE  ((MSF_MODID_MSM << 8) + 0x22) 

#define MSF_DLG_OPEN_RESPONSE_SIG       ((MSF_MODID_MSM << 8) + 0x23)
#define MSF_DLG_SAVE_RESPONSE_SIG       ((MSF_MODID_MSM << 8) + 0x24)
#define MSF_SAS_SAVE_AS_RESPONSE_SIG    ((MSF_MODID_MSM << 8) + 0x25)

/**********************************************************************
 * Type definitions
 **********************************************************************/

typedef struct {
  char*           path;
  char*           key;
  MSF_UINT8       type;
  MSF_INT32       value_i;
  unsigned char*  value_bv;
  MSF_UINT16      value_bv_length;
} msf_registry_param_t;

typedef struct {
  MSF_UINT16     drmDataLength;
  unsigned char *drmData;
  char          *drmContentHeaders;

} msf_content_drm_data_t;


typedef struct  {
  MSF_UINT8               routingFormat;
  char*                   routingIdentifier;
  char*                   contentUrl;
  char*                   contentSource;
  char*                   contentParameters;
  char*                   contentHeaders;
  MSF_INT32               networkAccountId;
  MSF_UINT8               contentDataType;
  MSF_UINT32              contentDataLength;
  unsigned char*          contentData;
  MSF_UINT8               contentDRMDataExists;
  msf_content_drm_data_t *contentDRMData;
  char*                   auxTypeIdentifier;
} msf_content_data_t;


typedef struct {
  MSF_UINT8 type;
  union {
    char      *s_value;
    MSF_INT32  i_value;
  }_u;
} msf_mime_list_t;

typedef struct {
  MSF_UINT32 mime_hash;
  char      *s_mime;
  MSF_INT32  i_mime;
  MSF_UINT8  resource_type;
  char      *resource_str_id;
  MSF_UINT32 resource_int_id;
} msf_icon_list_t;

/**********************************************************************
 * Signal structures that are connected to the signals above.
 **********************************************************************/

/* Module */
typedef struct {
  MSF_UINT8           modId;  /* The module that shall be started. */
  char*               startOptions;
  MSF_UINT8           contentDataExists;
  msf_content_data_t* contentData;
  /* msf_content_area_t contentArea;*/
} msf_module_start_t;

typedef struct {
  MSF_UINT8     modId;  /* The module that shall be terminated. */
} msf_module_terminate_t;

typedef struct {
  MSF_UINT8     status;
  MSF_UINT8     modId;
  char*         modVersion; /* Only used when the module is activated */
} msf_module_status_t;

typedef struct  {
  MSF_UINT8           srcModId;
  char*               commandOptions;
  MSF_UINT8           contentDataExists;
  msf_content_data_t* contentData;
 /* msf_content_area_t contentArea;*/
} msf_module_execute_cmd_t;

/* Timer */
typedef struct {
  MSF_UINT32    timerID;
  MSF_UINT32    timerInterval;
} msf_timer_set_t;

typedef struct {
  MSF_UINT32    timerID;
} msf_timer_reset_t;

typedef struct {
  MSF_UINT32    timerID;
} msf_timer_expired_t;

/* Widget */
typedef struct {
  MSF_UINT32          handle;
  MsfNotificationType notificationType;
} msf_widget_notify_t;

typedef struct {
  MSF_UINT32    handle;
  MSF_UINT32    action;
} msf_widget_action_t;

typedef struct {
  MSF_UINT32    handle;
  MsfEvent      event;
} msf_widget_userevt_t;

typedef struct {
  MSF_UINT32    handle;
  MSF_UINT32    accessKey;
} msf_widget_access_key_t;


/* Pipes */
typedef struct {
  MSF_INT32 handle;
  MSF_INT16 eventType;
} msf_pipe_notify_t;


/* Sockets */
typedef struct {
  MSF_INT32 socketId;
  MSF_INT16 result;
} msf_socket_connect_response_t;

typedef struct {
  MSF_INT32 socketId;
  MSF_INT16 eventType;
} msf_socket_notify_t;

typedef struct {
  MSF_INT32     requestId;
  MSF_INT16     result;
  MSF_INT16     addrLen;
  unsigned char addr[16];
} msf_socket_host_by_name_t;


/* File */
typedef struct {
  MSF_INT32 fileHandle;
  MSF_INT16 eventType;
} msf_file_notify_t;


/* Registry */
/* MSF_SIG_REG_GET, MSF_SIG_REG_DELETE */
typedef struct {
  MSF_INT16 id;
  char*     path;
  char*     key;
} msf_registry_identifier_t;

/* MSF_SIG_REG_SET, MSF_SIG_REG_RESPONSE */
typedef struct {
  MSF_INT16        id;
  char*            path;
  unsigned char*   next_element;
  unsigned char*   buffer_start;
  unsigned char*   buffer_end;
} msf_registry_response_t;

/* Content routing */
typedef struct {
  MSF_UINT8           destModId;
  MSF_UINT8           sendAck;
  MSF_UINT8           id;
  MSF_UINT8           contentDataExists;
  char*               startOptions;
  msf_content_data_t* contentData;
  /* msf_content_area_t contentArea;*/
} msf_content_send_t;

typedef struct {
  MSF_UINT8  id;
  MSF_UINT8  status;
} msf_content_send_ack_t;

/* Telephone */
typedef struct {
  MSF_UINT16 telId;
  MSF_INT16  result;
} msf_tel_make_call_resp_t;

typedef struct {
  MSF_UINT16 telId;
  MSF_INT16  result;
} msf_tel_send_dtmf_resp_t;

/* PhoneBook */
typedef struct {
  MSF_UINT16 pbId;
  MSF_INT16  result;
} msf_pb_add_entry_resp_t;


typedef struct  {
  char                *mime_type;
  MsfResourceType      data_type;
  unsigned char       *data;
  MSF_INT32            data_len;
  char                *src_path;
  char                *file_name;
  MSF_INT32            excl_act_strings_cnt;
  char               **excl_act_strings;
  MSF_BOOL             cleanup;
} msm_object_action_t;


typedef struct {
  MSF_UINT8         src;
  MSF_UINT32        id;
  MSF_UINT16        n_items;
  msf_mime_list_t  *mime_list;
}msm_get_icon_map_table_t;

typedef struct {
  MSF_UINT32        id;
  MSF_UINT16        n_items;
  msf_icon_list_t  *icon_list;
} msm_get_icons_resp_t;

#ifdef MSF_CONFIG_PIM

/* PIM */
typedef struct{
  MSF_UINT16        requestId; 
  MSF_UINT16        result;
} msf_pim_open_resp_t;

typedef struct{
  MSF_UINT16        requestId;
  MSF_UINT16        result;
} msf_pim_close_resp_t;

typedef struct{
  MSF_UINT16            requestId; 
  MSF_UINT16            recordInfoLen;
  MsfPimAddrRecordInfo *recordInfos;
  MSF_UINT16            result;
} msf_pim_addr_lookup_resp_t;

typedef struct{
  MSF_UINT16        requestId; 
  char             *name; 
  MSF_UINT32        recordId;
  MSF_UINT16        result;
} msf_pim_addr_lookup_name_resp_t;

typedef struct{
  MSF_UINT16        requestId;
  MSF_UINT32        fieldsLen;
  MsfPimField      *fields; 
  MSF_UINT32        recordId;
  MSF_UINT16        result;
} msf_pim_addr_get_record_resp_t;

typedef struct{
  MSF_UINT16        requestId;
  MSF_UINT32        recordId;
  MSF_UINT16        result;
} msf_pim_addr_set_record_resp_t;

#endif /*MSF_CONFIG_PIM*/


typedef struct {
  MSF_UINT32              id;        /* operation identifier */
  long                    status;    /* status of operation */
  char*                   file_name;
} msf_dlg_save_response_sig_t;

typedef struct {
  MSF_UINT32              id;        /* operation identifier */
  long                    status;    /* status of operation */
  char*                   file_name;
} msf_dlg_open_response_sig_t;

typedef struct {
  MSF_UINT32              id;        /* operation identifier */
  long                    status;    /* status of operation */
  char*                   file_name;
} msf_sas_save_as_response_sig_t;

/**********************************************************************
 * Conversion routines for signal structs
 **********************************************************************/

int
msf_cvt_content_data (msf_dcvt_t *obj, msf_content_data_t *p);

int
msf_cvt_module_start (msf_dcvt_t *obj, msf_module_start_t *p);

int
msf_cvt_module_terminate (msf_dcvt_t *obj, msf_module_terminate_t *p);

int
msf_cvt_module_status (msf_dcvt_t *obj, msf_module_status_t *p);

int
msf_cvt_module_execute_cmd (msf_dcvt_t *obj, msf_module_execute_cmd_t *p);

int
msf_cvt_timer_set (msf_dcvt_t *obj, msf_timer_set_t *p);

int
msf_cvt_timer_reset (msf_dcvt_t *obj, msf_timer_reset_t *p);

int
msf_cvt_timer_expired (msf_dcvt_t *obj, msf_timer_expired_t *p);

int
msf_cvt_wid_notify (msf_dcvt_t *obj, msf_widget_notify_t *p);

int
msf_cvt_wid_action (msf_dcvt_t *obj, msf_widget_action_t *p);

int
msf_cvt_wid_user_event (msf_dcvt_t *obj, msf_widget_userevt_t *p);

int
msf_cvt_wid_access_key (msf_dcvt_t *obj, msf_widget_access_key_t *p);

int
msf_cvt_pipe_notify (msf_dcvt_t *obj, msf_pipe_notify_t *p);

int
msf_cvt_file_notify (msf_dcvt_t *obj, msf_file_notify_t *p);

int
msf_cvt_socket_connect_response (msf_dcvt_t *obj, msf_socket_connect_response_t *p);

int
msf_cvt_socket_notify (msf_dcvt_t *obj, msf_socket_notify_t *p);

int
msf_cvt_socket_host_by_name (msf_dcvt_t *obj, msf_socket_host_by_name_t *p);

int
msf_cvt_registry_identifier (msf_dcvt_t *obj, msf_registry_identifier_t *p);

int
msf_cvt_content_send (msf_dcvt_t *obj, msf_content_send_t *p);

int
msf_cvt_content_send_ack (msf_dcvt_t *obj, msf_content_send_ack_t *p);

int
msf_cvt_tel_make_call_resp (msf_dcvt_t *obj, msf_tel_make_call_resp_t *p);

int
msf_cvt_tel_send_dtmf_resp (msf_dcvt_t *obj, msf_tel_send_dtmf_resp_t *p);

int
msf_cvt_pb_add_entry_resp (msf_dcvt_t *obj, msf_pb_add_entry_resp_t *p);

int
msf_cvt_icon_list(msf_dcvt_t *obj, msf_icon_list_t *p);

int
msf_cvt_get_icons_resp (msf_dcvt_t *obj, msm_get_icons_resp_t *p);

int
msf_cvt_object_action(msf_dcvt_t *obj, msm_object_action_t *p);

#ifdef MSF_CONFIG_PIM

int
msf_cvt_pim_open_resp(msf_dcvt_t *obj, msf_pim_open_resp_t *p);

int
msf_cvt_pim_close_resp(msf_dcvt_t *obj, msf_pim_close_resp_t *p);

int
msf_cvt_pim_addr_lookup_resp(msf_dcvt_t *obj, msf_pim_addr_lookup_resp_t *p);

int
msf_cvt_pim_addr_lookup_name_resp(msf_dcvt_t *obj, msf_pim_addr_lookup_name_resp_t *p);

int
msf_cvt_pim_addr_get_record_resp(msf_dcvt_t *obj, msf_pim_addr_get_record_resp_t *p);

int
msf_cvt_pim_addr_set_record_resp(msf_dcvt_t *obj, msf_pim_addr_set_record_resp_t *p);

#endif /*MSF_CONFIG_PIM*/

int
msf_cvt_open_dlg_response (msf_dcvt_t *obj, msf_dlg_open_response_sig_t *p);

int
msf_cvt_save_dlg_response (msf_dcvt_t *obj, msf_dlg_save_response_sig_t *p);

int
msf_cvt_save_as_response (msf_dcvt_t *obj, msf_sas_save_as_response_sig_t *p);

/**********************************************************************
 * Module status
 **********************************************************************/

#define MODULE_STATUS_NULL          0
#define MODULE_STATUS_STANDBY       1
#define MODULE_STATUS_CREATED       2
#define MODULE_STATUS_ACTIVE        3
#define MODULE_STATUS_SHUTTING_DOWN 4
#define MODULE_STATUS_TERMINATED    5



/**********************************************************************
 * Signaling macros
 **********************************************************************/

#define MSF_SIGNAL_REGISTER_QUEUE    HDIa_signalRegisterQueue

#define MSF_SIGNAL_DEREGISTER_QUEUE  HDIa_signalDeregisterQueue

#define MSF_SIGNAL_QUEUE_LENGTH      HDIa_signalQueueLength

#define MSF_SIGNAL_REG_FUNCTIONS     msf_signal_reg_functions

#define MSF_SIGNAL_CREATE            msf_signal_create

#define MSF_SIGNAL_SEND              msf_signal_send

#define MSF_SIGNAL_RETRIEVE          msf_signal_retrieve

#define MSF_SIGNAL_DESTRUCT          msf_signal_destruct

#define MSF_SIGNAL_GET_SIGNAL_ID     msf_signal_get_signal_id

#define MSF_SIGNAL_GET_SOURCE        msf_signal_get_source

#define MSF_SIGNAL_GET_DESTINATION   msf_signal_get_destination

#define MSF_SIGNAL_GET_USER_DATA     msf_signal_get_user_data


/**********************************************************************
 * Type definitions to signaling:
 **********************************************************************/

typedef void* convert_function_t (MSF_UINT8 module, MSF_UINT16 signal, void* buffer);
typedef void receive_function_t (MSF_UINT8 src_module, MSF_UINT16 signal, void* p);
typedef void destruct_function_t (MSF_UINT8 module, MSF_UINT16 signal, void* p);


/**********************************************************************
 * Time/Timer macros
 **********************************************************************/

#define MSF_TIME_ZONE_UNKNOWN        HDI_TIME_ZONE_UNKNOWN


#define MSF_TIME_GET_CURRENT         HDIa_timeGetCurrent

#define MSF_TIME_GET_TIME_ZONE       HDIa_timeGetTimeZone

#define MSF_TIME_GET_SECURE_CLOCK    HDIa_timeSecureClock

#define MSF_TIMER_SET                msf_timer_set

#define MSF_TIMER_RESET              msf_timer_reset

/**********************************************************************
 * Module macros
 **********************************************************************/

#define MSF_MODULE_IS_CREATED       msf_module_is_created

#define MSF_MODULE_IS_ACTIVE        msf_module_is_active

#define MSF_MODULE_IS_TERMINATED    msf_module_is_terminated

#define MSF_MODULE_START            msf_module_start

#define MSF_MODULE_TERMINATE        msf_module_terminate

#define MSF_KILL_TASK               HDIa_killTask


/**********************************************************************
 * Registry macros
 **********************************************************************/

#define MSF_REGISTRY_TYPE_INT       0
#define MSF_REGISTRY_TYPE_STR       1
#define MSF_REGISTRY_TYPE_DELETED   2


#define MSF_REGISTRY_SET_INIT           msf_registry_set_init

#define MSF_REGISTRY_SET_PATH           msf_registry_set_path

#define MSF_REGISTRY_SET_ADD_KEY_INT    msf_registry_set_add_key_int

#define MSF_REGISTRY_SET_ADD_KEY_STR    msf_registry_set_add_key_str

#define MSF_REGISTRY_SET_COMMIT         msf_registry_set_commit

#define MSF_REGISTRY_GET                msf_registry_get

#define MSF_REGISTRY_DELETE             msf_registry_delete

#define MSF_REGISTRY_RESPONSE_GET_NEXT  msf_registry_response_get_next

#define MSF_REGISTRY_RESPONSE_GET_PREV  msf_registry_response_get_prev

#define MSF_REGISTRY_RESPONSE_PEEK		msf_registry_response_peek

#define MSF_REGISTRY_RESPONSE_FREE      msf_registry_response_free

/**********************************************************************
 * Content Routing macros
 **********************************************************************/

#define MSF_ROUTING_TYPE_MIME           1
#define MSF_ROUTING_TYPE_EXT            2
#define MSF_ROUTING_TYPE_PAPPID         3
#define MSF_ROUTING_TYPE_SCHEME         4

#define MSF_CONTENT_DATA_RAW            0
#define MSF_CONTENT_DATA_FILE           1
#define MSF_CONTENT_DATA_PIPE           2
#define MSF_CONTENT_DATA_NONE           3

#define MSF_CONTENT_STATUS_SUCCEED      0
#define MSF_CONTENT_STATUS_FAILED       1

#define MSF_CONTENT_SEND                msf_content_send_no_drm_no_ext
#define MSF_CONTENT_SEND_DRM            msf_content_send_no_ext
#define MSF_CONTENT_SEND_DRM_EXT        msf_content_send

/**********************************************************************
 * Object Action macros
 **********************************************************************/
#define MSF_OBJECT_ACTION               msf_object_action

#ifdef MSF_CFG_OBJECT_ACTION_EXT
#define MSF_OBJECT_ACTION_EXT           msf_object_action_ext
#endif

/**********************************************************************
 * Icon macros
 **********************************************************************/
#define MSF_GET_ICONS                   msf_get_icons

/**********************************************************************
 * Exported messaging functions:
 **********************************************************************/

void
msf_signal_reg_functions (MSF_UINT8 module, convert_function_t *cf,
                                            destruct_function_t *df);

void*
msf_signal_create (MSF_UINT16 sigUid, MSF_UINT8 srcModId, MSF_UINT8 destModId,
                   MSF_UINT16 userDataLength);

void
msf_signal_send (void* buffer);

int
msf_signal_retrieve (MSF_UINT8 modId, receive_function_t *rf);

void
msf_signal_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p);

MSF_UINT16
msf_signal_get_signal_id (void* buffer);

MSF_UINT8
msf_signal_get_source (void* buffer);

MSF_UINT8
msf_signal_get_destination (void* buffer);

void*
msf_signal_get_user_data (void* buffer, MSF_UINT16* userDataLength);


/**********************************************************************
 * Exported timer functions:
 **********************************************************************/

void
msf_timer_set (MSF_UINT8 modId, int timerID, MSF_UINT32 timeInterval);

void
msf_timer_reset (MSF_UINT8 modId, int timerID);


/**********************************************************************
 * Exported module functions:
 **********************************************************************/

void
msf_module_is_created (MSF_UINT8 module_src, char* modVersion);

void
msf_module_is_active (MSF_UINT8 module_src);

void
msf_module_is_terminated (MSF_UINT8 module_src);

void
msf_module_start (MSF_UINT8 module_src, MSF_UINT8 module, char* startOptions,
                  msf_content_data_t* contentData, void* contentArea);

void
msf_module_terminate (MSF_UINT8 module_src, MSF_UINT8 module);


/**********************************************************************
 * Exported registry functions:
 **********************************************************************/

void*
msf_registry_set_init (MSF_UINT8 modId);

void
msf_registry_set_path (void* handle, char* path);

void
msf_registry_set_add_key_int (void* handle, char* key, MSF_INT32 value);

void
msf_registry_set_add_key_str (void* handle, char* key, unsigned char* value,
                              MSF_UINT16 valueLength);

void
msf_registry_set_commit (void* handle);

void
msf_registry_get (MSF_UINT8 modId, int id, char* path, char* key);

void
msf_registry_delete (MSF_UINT8 modId, char* path, char* key);

int
msf_registry_response_get_next (msf_registry_response_t* handle, msf_registry_param_t* param);

int
msf_registry_response_get_prev (msf_registry_response_t* handle, msf_registry_param_t* param);

int
msf_registry_response_peek (msf_registry_response_t* handle, msf_registry_param_t* param);

void
msf_registry_response_free (MSF_UINT8 modId, msf_registry_response_t* handle);


/**********************************************************************
 * Exported content routing functions:
 **********************************************************************/

void
msf_content_send (MSF_UINT8 src_modId, MSF_UINT8 dest_modId,
                  char* startOptions, msf_content_data_t* contentData, int sendAck, MSF_UINT8 id);

void
msf_content_send_no_ext (MSF_UINT8 src_modId, MSF_UINT8 dest_modId, char* startOptions, 
                         msf_content_data_t* contentData, int sendAck, MSF_UINT8 id);
void
msf_content_send_no_drm_no_ext (MSF_UINT8 src_modId, MSF_UINT8 dest_modId, char* startOptions, 
                                msf_content_data_t* contentData, int sendAck, MSF_UINT8 id);

/**********************************************************************
 * Exported Icon functions:
 **********************************************************************/
#define MSF_MIME_TYPE_STR 0x0001
#define MSF_MIME_TYPE_INT 0x0002

#define MSF_ICON_RESOURCE_TYPE_PREDEFINED 0x0001
#define MSF_ICON_RESOURCE_TYPE_FILE       0x0002

void
msf_get_icons (MSF_UINT8 src_modId, MSF_UINT32 id, 
               MSF_UINT16 n_items, msf_mime_list_t mime_list[]);


/**********************************************************************
 * Exported Object Action functions:
 **********************************************************************/
void
msf_object_action(MSF_UINT8             src_modId, 
                  const char           *mime_type,
                  MsfResourceType       data_type,
                  const unsigned char  *data,
                  MSF_INT32             data_len,
                  const char           *src_path,
                  const char           *file_name);

#ifdef MSF_CFG_OBJECT_ACTION_EXT
void
msf_object_action_ext(MSF_UINT8             src_modId, 
                      const char           *mime_type,
                      MsfResourceType       data_type,
                      const unsigned char  *data,
                      MSF_INT32             data_len,
                      const char           *src_path,
                      const char           *file_name,
                      const char*           excl_act_strings[],
                      MSF_INT32             excl_act_strings_cnt);
#endif

/**********************************************************************
 * Only used internally:
 **********************************************************************/

  /* 6 bytes = 2 bytes signal + 1 byte source + 1 byte dest + 2 bytes data length. */
#define MSF_SIGNAL_HEADER_LENGTH   6


#define MSF_REG_SET_TYPE_PATH             0
#define MSF_REG_SET_TYPE_INT              1
#define MSF_REG_SET_TYPE_STR              2
#define MSF_REG_SET_TYPE_DELETED          3

#define MSF_REG_MODID_INTEGRATION         -1

void*
msf_registry_set_int_commit (void* handle);

void
msf_registry_set_free_handle (MSF_UINT8 modId, void* handle);

#endif
