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










#ifndef _msm_cmmn_h
#define _msm_cmmn_h

#ifndef _msf_core_h
#include "msf_core.h"
#endif





#define MSM_CMMN_SIG_OBJECT_ACTION        MSM_SIG_DST_MSM_CMMN + 1
#define MSM_CMMN_SIG_GET_ICONS            MSM_SIG_DST_MSM_CMMN + 2
#define MSM_CMMN_SIG_WIDGET_ACTION        MSM_SIG_DST_MSM_CMMN + 3
#define MSM_CMMN_SIG_ACT_FINISHED         MSM_SIG_DST_MSM_CMMN + 4








void
msm_cmmn_init (void);


void
msm_cmmn_terminate (void);

#ifdef CONTENT_OBJECT_ACTION_DISABLE
void msf_cmmn_info_dialog(MsfStringHandle str);
#endif








int
msm_cmmn_handle_package_signal(MSF_UINT16 signal, void *p);








void
msm_content_send_ack (MSF_UINT8 modId, MSF_UINT8 id, MSF_UINT8 status);







#endif
