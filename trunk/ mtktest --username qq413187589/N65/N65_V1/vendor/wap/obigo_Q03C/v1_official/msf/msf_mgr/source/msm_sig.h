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













#ifndef _msm_sig_h
#define _msm_sig_h










#define MSM_SIG_DST_MSM_MAIN          0x010
#define MSM_SIG_DST_MSM_TIMER         0x020
#define MSM_SIG_DST_MSM_REGISTRY      0x030
#define MSM_SIG_DST_MSM_CMMN           0x040






#define MSM_SIGNAL_SENDTO(d, sig) \
  msm_signal_sendto ((d), (sig), 0, 0, 0, NULL)

#define MSM_SIGNAL_SENDTO_I(d, sig, i) \
  msm_signal_sendto ((d), (sig), i, 0, 0, NULL)

#define MSM_SIGNAL_SENDTO_U(d, sig, u) \
  msm_signal_sendto ((d), (sig), 0, (u), 0, NULL)

#define MSM_SIGNAL_SENDTO_IU(d, sig, i, u) \
  msm_signal_sendto ((d), (sig), (i), (u), 0, NULL)

#define MSM_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
  msm_signal_sendto ((d), (sig), 0, (u1), (u2), NULL)

#define MSM_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
  msm_signal_sendto ((d), (sig), (i), (u1), (u2), NULL)

#define MSM_SIGNAL_SENDTO_P(d, sig, p) \
  msm_signal_sendto ((d), (sig), 0, 0, 0, (p))

#define MSM_SIGNAL_SENDTO_IP(d, sig, i, p) \
  msm_signal_sendto ((d), (sig), (i), 0, 0, (p))

#define MSM_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
  msm_signal_sendto ((d), (sig), (i), (u), 0, (p))

#define MSM_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
  msm_signal_sendto ((d), (sig), (i), (u1), (u2), (p))






typedef struct msm_signal_st {
  struct msm_signal_st *next;
  int                 dst;      
  int                 type;     
  long int            i_param;  
  unsigned long int   u_param1;
  unsigned long int   u_param2;
  void               *p_param;
} msm_signal_t;




typedef void msm_signal_function_t (msm_signal_t *);









void
msm_signal_init (void);




void
msm_signal_terminate (void);





void
msm_signal_process (void);





int
msm_signal_queue_is_empty (void);




void
msm_signal_delete (msm_signal_t *sig);





void
msm_signal_register_dst (int dst, msm_signal_function_t *f);




void
msm_signal_deregister (int dst);




void
msm_signal_sendto (int dst,
                 int sig,
                 long int i_param,
                 unsigned long int u_param1,
                 unsigned long int u_param2,
                 void *p_param);




void
msm_signal_prepend (msm_signal_t *sig);

#endif
