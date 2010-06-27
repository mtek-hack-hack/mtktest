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








#ifndef _stk_main_h
#define _stk_main_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#ifndef _msf_core_h
#include "msf_core.h"
#endif

#ifndef _msf_mem_h
#include "msf_mem.h"
#endif

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif

#ifndef _stk_if_h
#include "stk_if.h"
#endif




extern jmp_buf stk_jmpbuf;     
extern int     stk_inside_run; 






#ifdef STK_SEQUENCE_LOGS
#ifndef _msf_log_h
#include "msf_log.h"
#endif
#define STK_SEQUENCE_LOG(msg)      HDIa_logMsg (MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRS, msg)

#else
#define STK_SEQUENCE_LOG(msg)
#endif


#define STK_MEM_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_STK, (x))
#define STK_MEM_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_STK, x)
#define STK_MEM_FREE(x)       MSF_MEM_FREE (MSF_MODID_STK, (x))






#if(defined(STK_CONFIG_WTLS) || defined(STK_CONFIG_TLS) || defined (STK_CONFIG_DIGEST_AUTH))  
#define STK_USING_SECURITY
#endif

#define STK_SIG_SOCKET_CONNECT_RESPONSE            STK_MODULE_MAIN + 1
#define STK_SIG_SOCKET_NOTIFY                      STK_MODULE_MAIN + 2
#define STK_SIG_TIMER_EXPIRED                      STK_MODULE_MAIN + 3
#define STK_SIG_NOTIFY                             STK_MODULE_MAIN + 4
#define STK_SIG_FILE_NOTIFY                        STK_MODULE_MAIN + 5









#define STK_DATA_READ_READY                        1
#define STK_DATA_WRITE_READY                       2
#define STK_DATA_CLOSED                            3
#define STK_DATA_READ_DONE                         4
                                                  
                          
#define STK_REG_PATH_STK                           0
#define STK_REG_PATH_COOKIE                        1
#define STK_REG_PATH_CHANNEL                       2
#define STK_REG_PATH_CACHE                         3
#define STK_REG_PATH_HEADER                        4
#define STK_REG_PATH_MIME                          5

                                                  
#define STK_REG_KEY_ENABLED                        0

#define STK_REG_KEY_MAX_SIZE                       1
#define STK_REG_KEY_LIFETIME                       2
#define STK_REG_KEY_MODE                           3

#define STK_REG_KEY_CONNTYPE                       4
#define STK_REG_KEY_NET_ID                         5
#define STK_REG_KEY_TIMEOUT                        6
#define STK_REG_KEY_OPTIONS                        7
#define STK_REG_KEY_PORT                           8 
#define STK_REG_KEY_SEC_PORT                       9

#define STK_REG_KEY_PROXY_IP                       10
#define STK_REG_KEY_USERNAME                       11
#define STK_REG_KEY_PASSWORD                       12
#define STK_REG_KEY_REALM                          13
#define STK_REG_KEY_HEADERS                        14

#define STK_REG_KEY_UA_PROFILE                     15
#define STK_REG_KEY_UA_PROFILE_DIFF                16

#define STK_REG_KEY_DYNAMIC_HEADER                 17





void
stk_init (void);

void
stk_terminate (void);

void
stk_init_done (void);

void
stk_terminate_done (void);

void
stk_module_status (msf_module_status_t *p);




MSF_BOOL
stk_httpReply (MSF_UINT8 dst, int requestId, int status,
               const char *newUrl, const char *headers,
               long socketId, MSF_INT32 securityId, int protocol,
               const char *cacheFileName, int numEntries,
               stk_content_t *content);




void
stk_httpStatus (MSF_UINT8 dst, int requestId, int status);




void
stk_httpRequestAborted(MSF_UINT8 dst, int requestId, int errorCode);




void
stk_clearDone (MSF_UINT8 dst, int operation);




void
stk_connectionCreated (MSF_UINT8 dst, int connectionId);




#ifdef STK_CONFIG_TLS
void
stk_streamConnectionCreated (MSF_UINT8 dst, int connectionId, 
                             const char *receivePipeName, int socketId);
#endif




void
stk_connectionClosed (MSF_UINT8 dst, int connectionId, int errorCode);




void
stk_recvRequest (MSF_UINT8 dst, int connectionId, int parentId, int requestId,
                 msf_sockaddr_t *fromAddr, int method, const char *url,
                 const char *headers, int numEntries,
                 stk_content_t *content);




void
stk_recvReply (MSF_UINT8 dst, int connectionId, int requestId,
               int status, const char *headers, int numEntries,
               stk_content_t *content);




void
stk_requestAborted (MSF_UINT8 dst, int connectionId, int requestId,
                    int errorCode);


int
stk_new_handle (void);






int
stk_datasource_init (int module, int id, int type, void *data, long datalen,
                     const char *pathname);

void
stk_datasource_close (int src_handle);

long
stk_datasource_read (int src_handle, void *buf, long buflen);

long
stk_datasource_datalen (int src_handle);


int
stk_datasink_init (int module, int id, int type, void *data,long datalen, const char *pathname, int append_to_file);

long
stk_datasink_write (int sink_handle, void *buf, long buflen);

void
stk_datasink_close (int sink_handle, int error);

void
stk_data_pipe_notification (int handle, int eventType);

void
stk_data_file_notification (int handle, int eventType);






void
stk_timer_expired (int timer_id);

void
stk_timer_reset_all (int module);

void
stk_timer_set (int module, int interval, int id1, MSF_UINT32 id2);

void
stk_timer_reset (int module, int id1, MSF_UINT32 id2);






void
stk_reg_response(msf_registry_response_t *p);

const char*
stk_reg_get_path_string(int value);

const char*
stk_reg_get_key_string(int value);

int
stk_reg_get_str_value (int key, int param, char **str, int* str_len);

void
stk_reg_get_mime_type (MSF_UINT8 module_id, int request_id, char *filePath);

#endif
