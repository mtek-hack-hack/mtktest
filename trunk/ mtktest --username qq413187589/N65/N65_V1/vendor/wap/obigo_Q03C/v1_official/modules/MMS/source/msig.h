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





#ifndef _MSIG_H
#define _MSIG_H















typedef enum
{
    M_FSM_ASYNC,              
    M_FSM_CONT,               
    M_FSM_COH_GET,            
    M_FSM_COH_POST,           
    M_FSM_COH_PUSH_RECEIVE,   
    M_FSM_COH_SEND,           
    M_FSM_COH_WAP,            
    M_FSM_CORE_CONFIG,        
    M_FSM_CORE_MAIN,          
    M_FSM_FLDR_MANAGER,       
    M_FSM_MMH_HANDLER,        
    M_FSM_MMH_FETCH,          
    M_FSM_MSR_SEND,           
    M_FSM_MSR_RECEIVE,        
    M_FSM_MSR_NOTIFY,         


    M_FSM_MAX_REGS            

} MmsStateMachine;













typedef enum
{
    
    MMS_SIG_COMMON_BASE             = 1000,

    
    MMS_SIG_COMMON_TIMER_EXPIRED    = (MMS_SIG_COMMON_BASE + 1)
} MmsSignalId;

#define M_SIGNAL_SENDTO(d, sig) \
    mSignalSendTo((d), (sig), 0L, (unsigned long)0L, (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_I(d, sig, i) \
    mSignalSendTo((d), (sig), (i), (unsigned long)0L, (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_IU(d, sig, i, u) \
    mSignalSendTo((d), (sig), (i), (u), 0L, NULL)

#define M_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
    mSignalSendTo((d), (sig), (i), (u1), (u2), NULL)

#define M_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
    mSignalSendTo((d), (sig), (i), (u), (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
    mSignalSendTo((d), (sig), (i), (u1), (u2), (p))

#define M_SIGNAL_SENDTO_IP(d, sig, i, p) \
    mSignalSendTo((d), (sig), (i), (unsigned long)0L, (unsigned long)0L, (p))

#define M_SIGNAL_SENDTO_U(d, sig, u) \
    mSignalSendTo((d), (sig), 0L, (u), (unsigned long)0L, NULL)

#define M_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
    mSignalSendTo((d), (sig), 0L, (u1), (u2), NULL)

#define M_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
    mSignalSendTo((d), (sig), 0L, (u1), (u2), (p))

#define M_SIGNAL_SENDTO_UP(d, sig, u, p) \
    mSignalSendTo((d), (sig), 0L, (u), 0L, (p))

#define M_SIGNAL_SENDTO_P(d, sig, p) \
    mSignalSendTo((d), (sig), 0L, (unsigned long)0L, (unsigned long)0L, (p))




typedef struct MmsSignalStruct 
{
    struct MmsSignalStruct *next;       
    MmsStateMachine         dst;        
    MSF_UINT32              type;       
    long                    i_param;    
    unsigned long           u_param1;   
    unsigned long           u_param2;   
    void                   *p_param;    
} MmsSignal;




typedef void MSignalFunction (MmsSignal *);




void mSignalEmergencyAbort(void);




void mSignalFlush(MmsStateMachine dst, MmsSignalId id, long i_param,
    unsigned long u_param1, unsigned long u_param2, const void *p_param);




void mSignalInit(void);




void mSignalTerminate(void);




void mSignalProcess(void);






int mSignalQueueIsEmpty(void);




void mSignalDelete(MmsSignal *sig);




void mSignalDeregister(MmsStateMachine dst);





void mSignalRegisterDst(MmsStateMachine dst, MSignalFunction *f);




MmsSignal *mSignalSendTo(MmsStateMachine dst, MSF_UINT32 sig, long i_param,
    unsigned long u_param1, unsigned long u_param2, void *p_param);




void mSignalPrepend(MmsSignal *sig);

#endif 


