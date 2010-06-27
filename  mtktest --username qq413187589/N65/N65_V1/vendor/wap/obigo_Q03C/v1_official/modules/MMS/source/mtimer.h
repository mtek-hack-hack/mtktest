/*
 * Copyright (C) Obigo AB, 2002-2005.
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





#ifndef _MTIMER_H
#define _MTIMER_H








#define M_TIMER_SET(dst, dsecs) \
    mTimerSet((dst), (dsecs), 0L)

#define M_TIMER_SET_I(dst, dsecs, i) \
    mTimerSet((dst), (dsecs), (i))

#define M_TIMER_RESET(dst) \
    mTimerReset((dst), 0L)

#define M_TIMER_RESET_I(dst, i) \
    mTimerReset((dst), (i))

#define M_TIMER_RESTART(dst, dsecs) \
mTimerRestart((dst), (dsecs), 0L)

#define M_TIMER_RESTART_I(dst, dsecs, i) \
mTimerRestart((dst), (dsecs), (i))





void mTimerEmergencyAbort(void);
void mTimerInit(void);
void mTimerTerminate(void);
void mTimerSet( MmsStateMachine dst, MSF_UINT32 dsecs, long param);
void mTimerRestart( MmsStateMachine dst, MSF_UINT32 dsecs, long param);
void mTimerReset( MmsStateMachine dst, long param);
void mTimerExpired(MSF_UINT32 timerId);

#endif 

