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














#ifndef _sec_sig_h
#define _sec_sig_h








#define W_SIG_DST_SEC_MAIN          0x010






#define SEC_SIGNAL_SENDTO(d, sig) \
  sec_signal_sendto ((d), (sig), 0, 0, 0, NULL)

#define SEC_SIGNAL_SENDTO_I(d, sig, i) \
  sec_signal_sendto ((d), (sig), i, 0, 0, NULL)

#define SEC_SIGNAL_SENDTO_U(d, sig, u) \
  sec_signal_sendto ((d), (sig), 0, (u), 0, NULL)

#define SEC_SIGNAL_SENDTO_IU(d, sig, i, u) \
  sec_signal_sendto ((d), (sig), (i), (u), 0, NULL)

#define SEC_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
  sec_signal_sendto ((d), (sig), 0, (u1), (u2), NULL)

#define SEC_SIGNAL_SENDTO_IUU(d, sig, i, u1, u2) \
  sec_signal_sendto ((d), (sig), (i), (u1), (u2), NULL)

#define SEC_SIGNAL_SENDTO_P(d, sig, p) \
  sec_signal_sendto ((d), (sig), 0, 0, 0, (p))

#define SEC_SIGNAL_SENDTO_IP(d, sig, i, p) \
  sec_signal_sendto ((d), (sig), (i), 0, 0, (p))

#define SEC_SIGNAL_SENDTO_UP(d, sig, u, p) \
  sec_signal_sendto ((d), (sig), 0, (u), 0, (p))

#define SEC_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
  sec_signal_sendto ((d), (sig), (i), (u), 0, (p))

#define SEC_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
  sec_signal_sendto ((d), (sig), (i), (u1), (u2), (p))






typedef struct sec_signal_st {
  struct sec_signal_st *next;
  int                 dst;      
  int                 type;     
  long int            i_param;  
  unsigned long int   u_param1;
  unsigned long int   u_param2;
  void               *p_param;
} sec_signal_t;




typedef void sec_signal_function_t (sec_signal_t *);









void
sec_signal_init (void);




void
sec_signal_terminate (void);





void
sec_signal_process (void);





int
sec_signal_queue_is_empty (void);




void
sec_signal_delete (sec_signal_t *sig);





void
sec_signal_register_dst (int dst, sec_signal_function_t *f);




void
sec_signal_deregister (int dst);




void
sec_signal_sendto (int dst,
                 int sig,
                 long int i_param,
                 unsigned long int u_param1,
                 unsigned long int u_param2,
                 void *p_param);




void
sec_signal_prepend (sec_signal_t *sig);

#endif
