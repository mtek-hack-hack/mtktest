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









#ifndef _stk_sig_h
#define _stk_sig_h







#define STK_MODULE_MAIN                 0x000
#define STK_MODULE_CMGR                 0x010
#define STK_MODULE_WSP                  0x030
#define STK_MODULE_WTP                  0x050
#define STK_MODULE_WTLS                 0x060
#define STK_MODULE_WTLSHM               0x070
#define STK_MODULE_WDP                  0x090
#define STK_MODULE_TRH                  0x0a0
#define STK_MODULE_HTTP                 0x0c0
#define STK_MODULE_TLS                  0x0d0
#define STK_MODULE_TLSHM                0x0e0






#define STK_SIGNAL_SENDTO(d, sig) \
  stk_signal_sendto ((d), (sig), 0, 0, 0, 0, NULL, NULL)


#define STK_SIGNAL_SENDTO_I(d, sig, i) \
  stk_signal_sendto ((d), (sig), i, 0, 0, 0, NULL, NULL)

#define STK_SIGNAL_SENDTO_U(d, sig, u) \
  stk_signal_sendto ((d), (sig), 0, 0, (u), 0, NULL, NULL)

#define STK_SIGNAL_SENDTO_P(d, sig, p) \
  stk_signal_sendto ((d), (sig), 0, 0, 0, 0, (p), NULL)


#define STK_SIGNAL_SENDTO_II(d, sig, i1, i2) \
  stk_signal_sendto ((d), (sig), (i1), (i2), 0, 0, NULL, NULL)

#define STK_SIGNAL_SENDTO_IU(d, sig, i, u) \
  stk_signal_sendto ((d), (sig), (i), 0, (u), 0, NULL, NULL)

#define STK_SIGNAL_SENDTO_IP(d, sig, i, p) \
  stk_signal_sendto ((d), (sig), (i), 0, 0, 0, (p), NULL)

#define STK_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
  stk_signal_sendto ((d), (sig), 0, 0, (u1), (u2), NULL, NULL)

#define STK_SIGNAL_SENDTO_UP(d, sig, u, p) \
  stk_signal_sendto ((d), (sig), 0, 0, (u), 0, (p), NULL)

#define STK_SIGNAL_SENDTO_PP(d, sig, p1, p2) \
  stk_signal_sendto ((d), (sig), 0, 0, 0, 0, (p1), (p2))


#define STK_SIGNAL_SENDTO_IIU(d, sig, i1, i2, u) \
  stk_signal_sendto ((d), (sig), (i1), (i2), (u), 0, NULL, NULL)

#define STK_SIGNAL_SENDTO_IIP(d, sig, i1, i2, p) \
  stk_signal_sendto ((d), (sig), (i1), (i2), 0, 0, (p), NULL)

#define STK_SIGNAL_SENDTO_IUU(d, sig, i1, u1, u2) \
  stk_signal_sendto ((d), (sig), (i1), 0, (u1), (u2), NULL, NULL)

#define STK_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
  stk_signal_sendto ((d), (sig), (i), 0, (u), 0, (p), NULL)

#define STK_SIGNAL_SENDTO_IPP(d, sig, i1, p1, p2) \
  stk_signal_sendto ((d), (sig), (i1), 0, 0, 0, (p1), (p2))

#define STK_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
  stk_signal_sendto ((d), (sig), 0, 0, (u1), (u2), (p), NULL)

#define STK_SIGNAL_SENDTO_UPP(d, sig, u, p1, p2) \
  stk_signal_sendto ((d), (sig), 0, 0, (u1), 0, (p1), (p2))


#define STK_SIGNAL_SENDTO_IIUU(d, sig, i1, i2, u1, u2) \
  stk_signal_sendto ((d), (sig), (i1), (i2), (u1), (u2), NULL, NULL)

#define STK_SIGNAL_SENDTO_IIUP(d, sig, i1, i2, u, p) \
  stk_signal_sendto ((d), (sig), (i1), (i2), (u), 0, (p), NULL)

#define STK_SIGNAL_SENDTO_IIPP(d, sig, i1, i2, p1, p2) \
  stk_signal_sendto ((d), (sig), (i1), (i2), 0, 0, (p1), (p2))

#define STK_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
  stk_signal_sendto ((d), (sig), (i), 0, (u1), (u2), (p), NULL)

#define STK_SIGNAL_SENDTO_IUPP(d, sig, i, u, p1, p2) \
  stk_signal_sendto ((d), (sig), (i), 0, (u), 0, (p1), (p2))

#define STK_SIGNAL_SENDTO_UUPP(d, sig, u1, u2, p1, p2) \
  stk_signal_sendto ((d), (sig), 0, 0, (u1), (u2), (p1), (p2))


#define STK_SIGNAL_SENDTO_IIUUP(d, sig, i1, i2, u1, u2, p) \
  stk_signal_sendto ((d), (sig), (i1), (i2), (u1), (u2), (p), NULL)

#define STK_SIGNAL_SENDTO_IIUPP(d, sig, i1, i2, u, p1, p2) \
  stk_signal_sendto ((d), (sig), (i1), (i2), (u), 0, (p1), (p2))

#define STK_SIGNAL_SENDTO_IUUPP(d, sig, i, u1, u2, p1, p2) \
  stk_signal_sendto ((d), (sig), (i1), 0, (u1), (u2), (p1), (p2))


#define STK_SIGNAL_SENDTO_IIUUPP(d, sig, i1, i2, u1, u2, p1, p2) \
  stk_signal_sendto ((d), (sig), (i1), (i2), (u1), (u2), (p1), (p2))






typedef struct stk_signal_st {
  struct stk_signal_st *next;
  int                   dst;      
  int                   type;     
  long int              i_param1;  
  long int              i_param2;  
  unsigned long int     u_param1;
  unsigned long int     u_param2;
  void                 *p_param1;
  void                 *p_param2;
} stk_signal_t;




typedef void stk_signal_function_t (stk_signal_t *);









void
stk_signal_init (void);




void
stk_signal_terminate (void);





void
stk_signal_process (void);





int
stk_signal_queue_is_empty (void);




void
stk_signal_delete (stk_signal_t *sig);





void
stk_signal_register_dst (int dst, stk_signal_function_t *f);




void
stk_signal_deregister (int dst);




void
stk_signal_sendto (int dst,
                   int sig,
                   long int i_param1,
                   long int i_param2,
                   unsigned long int u_param1,
                   unsigned long int u_param2,
                   void *p_param1,
                   void *p_param2);




void
stk_signal_prepend (stk_signal_t *sig);

#endif
