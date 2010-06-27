/*
 * Copyright (C) Obigo AB, 2002-2007.
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








#ifndef _brs_sig_h
#define _brs_sig_h







#define BRS_MODULE_MAIN                 0x000
#define BRS_MODULE_UA                   0x010
#define BRS_MODULE_PARSER               0x030
#define BRS_MODULE_CSS                  0x040
#define BRS_MODULE_DISPLAY              0x050
#define BRS_MODULE_LE                   0x070
#define BRS_MODULE_WMLS                 0x090
#define BRS_MODULE_PLUGIN               0x100
#define BRS_MODULE_OFFLINE              0x120






#define BRS_SIGNAL_SENDTO(d, sig) \
  brs_signal_sendto ((d), (sig), 0, 0, 0, 0, NULL, NULL)


#define BRS_SIGNAL_SENDTO_I(d, sig, i) \
  brs_signal_sendto ((d), (sig), i, 0, 0, 0, NULL, NULL)

#define BRS_SIGNAL_SENDTO_U(d, sig, u) \
  brs_signal_sendto ((d), (sig), 0, 0, (u), 0, NULL, NULL)

#define BRS_SIGNAL_SENDTO_P(d, sig, p) \
  brs_signal_sendto ((d), (sig), 0, 0, 0, 0, (p), NULL)


#define BRS_SIGNAL_SENDTO_II(d, sig, i1, i2) \
  brs_signal_sendto ((d), (sig), (i1), (i2), 0, 0, NULL, NULL)

#define BRS_SIGNAL_SENDTO_IU(d, sig, i, u) \
  brs_signal_sendto ((d), (sig), (i), 0, (u), 0, NULL, NULL)

#define BRS_SIGNAL_SENDTO_IP(d, sig, i, p) \
  brs_signal_sendto ((d), (sig), (i), 0, 0, 0, (p), NULL)

#define BRS_SIGNAL_SENDTO_UU(d, sig, u1, u2) \
  brs_signal_sendto ((d), (sig), 0, 0, (u1), (u2), NULL, NULL)

#define BRS_SIGNAL_SENDTO_UP(d, sig, u, p) \
  brs_signal_sendto ((d), (sig), 0, 0, (u), 0, (p), NULL)

#define BRS_SIGNAL_SENDTO_PP(d, sig, p1, p2) \
  brs_signal_sendto ((d), (sig), 0, 0, 0, 0, (p1), (p2))


#define BRS_SIGNAL_SENDTO_IIU(d, sig, i1, i2, u) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u), 0, NULL, NULL)

#define BRS_SIGNAL_SENDTO_IIP(d, sig, i1, i2, p) \
  brs_signal_sendto ((d), (sig), (i1), (i2), 0, 0, (p), NULL)

#define BRS_SIGNAL_SENDTO_IUU(d, sig, i1, i2, u) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u), 0, NULL, NULL)

#define BRS_SIGNAL_SENDTO_IUP(d, sig, i, u, p) \
  brs_signal_sendto ((d), (sig), (i), 0, (u), 0, (p), NULL)

#define BRS_SIGNAL_SENDTO_IPP(d, sig, i1, p1, p2) \
  brs_signal_sendto ((d), (sig), (i1), 0, 0, 0, (p1), (p2))

#define BRS_SIGNAL_SENDTO_UUP(d, sig, u1, u2, p) \
  brs_signal_sendto ((d), (sig), 0, 0, (u1), (u2), (p), NULL)

#define BRS_SIGNAL_SENDTO_UPP(d, sig, u, p1, p2) \
  brs_signal_sendto ((d), (sig), 0, 0, (u1), 0, (p1), (p2))


#define BRS_SIGNAL_SENDTO_IIUU(d, sig, i1, i2, u1, u2) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u1), (u2), NULL, NULL)

#define BRS_SIGNAL_SENDTO_IIUP(d, sig, i1, i2, u, p) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u), 0, (p), NULL)

#define BRS_SIGNAL_SENDTO_IIPP(d, sig, i1, i2, p1, p2) \
  brs_signal_sendto ((d), (sig), (i1), (i2), 0, 0, (p1), (p2))

#define BRS_SIGNAL_SENDTO_IUUP(d, sig, i, u1, u2, p) \
  brs_signal_sendto ((d), (sig), (i), 0, (u1), (u2), (p), NULL)

#define BRS_SIGNAL_SENDTO_IUPP(d, sig, i, u, p1, p2) \
  brs_signal_sendto ((d), (sig), (i), 0, (u), 0, (p1), (p2))

#define BRS_SIGNAL_SENDTO_UUPP(d, sig, u1, u2, p1, p2) \
  brs_signal_sendto ((d), (sig), 0, 0, (u1), (u2), (p1), (p2))


#define BRS_SIGNAL_SENDTO_IIUUP(d, sig, i1, i2, u1, u2, p) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u1), (u2), (p), NULL)

#define BRS_SIGNAL_SENDTO_IIUPP(d, sig, i1, i2, u, p1, p2) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u), 0, (p1), (p2))

#define BRS_SIGNAL_SENDTO_IUUPP(d, sig, i, u1, u2, p1, p2) \
  brs_signal_sendto ((d), (sig), (i1), 0, (u1), (u2), (p1), (p2))


#define BRS_SIGNAL_SENDTO_IIUUPP(d, sig, i1, i2, u1, u2, p1, p2) \
  brs_signal_sendto ((d), (sig), (i1), (i2), (u1), (u2), (p1), (p2))






typedef struct brs_signal_st {
  struct brs_signal_st *next;
  int                   dst;      
  int                   type;     
  long int              i_param1;  
  long int              i_param2;  
  unsigned long int     u_param1;
  unsigned long int     u_param2;
  void                 *p_param1;
  void                 *p_param2;
} brs_signal_t;




typedef void brs_signal_function_t (brs_signal_t *);









void
brs_signal_init (void);




void
brs_signal_terminate (void);





void
brs_signal_process (void);





int
brs_signal_queue_is_empty (void);




void
brs_signal_delete (brs_signal_t *sig);





void
brs_signal_register_dst (int dst, brs_signal_function_t *f);




void
brs_signal_deregister (int dst);




void
brs_signal_sendto (int dst,
                   int sig,
                   long int i_param1,
                   long int i_param2,
                   unsigned long int u_param1,
                   unsigned long int u_param2,
                   void *p_param1,
                   void *p_param2);




void
brs_signal_prepend (brs_signal_t *sig);

#endif
