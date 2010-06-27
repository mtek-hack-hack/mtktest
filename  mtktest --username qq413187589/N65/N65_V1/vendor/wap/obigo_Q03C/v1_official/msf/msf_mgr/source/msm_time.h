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










#ifndef _msm_time_h
#define _msm_time_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif






#define MSM_TIMER_SIG_SET                  MSM_SIG_DST_MSM_TIMER + 1
#define MSM_TIMER_SIG_RESET                MSM_SIG_DST_MSM_TIMER + 2
#define MSM_TIMER_SIG_EXPIRED              MSM_SIG_DST_MSM_TIMER + 3






void
msm_timer_init (void);

void
msm_timer_terminate (void);

void
msm_timer_set (MSF_UINT8 modId, MSF_UINT32 timerID, MSF_UINT32 dsecs);

void
msm_timer_reset (MSF_UINT8 modId, MSF_UINT32 timerID);

void
msm_timer_reset_all (MSF_UINT8 modId);

void
msm_timer_expired (int do_reset);

#endif
