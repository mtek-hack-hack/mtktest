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










#ifndef _msm_h
#define _msm_h

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif





#define MSM_MAIN_SIG_START_MODULE       MSM_SIG_DST_MSM_MAIN + 1
#define MSM_MAIN_SIG_TERMINATE_MODULE   MSM_SIG_DST_MSM_MAIN + 2
#define MSM_MAIN_SIG_TERMINATE          MSM_SIG_DST_MSM_MAIN + 3
#define MSM_MAIN_SIG_MODULE_STATUS      MSM_SIG_DST_MSM_MAIN + 4
#define MSM_MAIN_SIG_REG_RESPONSE       MSM_SIG_DST_MSM_MAIN + 5
#define MSM_MAIN_SIG_CONTENT_SEND       MSM_SIG_DST_MSM_MAIN + 6
#define MSM_MAIN_SIG_AFI_FINISHED       MSM_SIG_DST_MSM_MAIN + 7
#define MSM_MAIN_SIG_REG_TERMINATED     MSM_SIG_DST_MSM_MAIN + 8







#define MSM_ALLOC(s)      MSF_MEM_ALLOC(MSF_MODID_MSM,s)
#define MSM_ALLOCTYPE(t)  MSF_MEM_ALLOCTYPE(MSF_MODID_MSM,t)
#define MSM_FREE(p)       MSF_MEM_FREE(MSF_MODID_MSM,p)






extern jmp_buf msm_jmpbuf;      
extern int     msm_inside_run;  










void
msm_start (const char* options);




void
msm_init_done (void);





int
msm_modid_str2int (const char* string_modId);





char*
msm_get_sub_path (char* src, char* dst);





int
msm_get_module_status (MSF_UINT8 modId);







void
msm_object_action (const char           *mime_type,
                   MsfResourceType       data_type,
                   const unsigned char  *data,
                   MSF_INT32             data_len,
                   const char           *src_path,
                   const char           *file_name,
                   const char*           excl_act_strings[],
                   MSF_INT32             excl_act_strings_cnt,
                   MSF_BOOL              cleanup,
                   MSF_UINT8             ack_dest_modid,
                   MSF_UINT8             ack_id);








int
msm_handle_package_signal(MSF_UINT16 signal, void *p);


#endif
