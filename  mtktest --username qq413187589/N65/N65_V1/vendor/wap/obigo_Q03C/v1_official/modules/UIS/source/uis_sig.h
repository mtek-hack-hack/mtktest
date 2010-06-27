/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */








 






#ifndef _uis_sig_h
#define _uis_sig_h








#define UIS_MODULE_MAIN           0x000
#define UIS_MODULE_MSG_STORE      0x020





#define UIS_SIGNAL_SENDTO_UP(d, sig, u, p) \
  uis_signal_sendto ((d), (sig), 0, (u), (p))

#define UIS_SIGNAL_SENDTO_IU(d, sig, i, u) \
  uis_signal_sendto ((d), (sig), (i), (u), NULL)

#define UIS_SIGNAL_SENDTO_P(d, sig, p) \
  uis_signal_sendto ((d), (sig), 0, 0, (p))

#define UIS_SIGNAL_SENDTO_I(d, sig, i) \
  uis_signal_sendto ((d), (sig), (i), 0, NULL)






typedef struct uis_signal_st {
  struct uis_signal_st *next;
  int                   dst;      
  int                   type;     
  long int              i_param;  
  unsigned long int     u_param;
  void                 *p_param;
} uis_signal_t;




typedef void uis_signal_function_t (uis_signal_t *);









void
uis_signal_init (void);




void
uis_signal_terminate (void);




void
uis_signal_process (void);





int
uis_signal_queue_is_empty (void);




void
uis_signal_delete (uis_signal_t *sig);





void
uis_signal_register_dst (int dst, uis_signal_function_t *f);










void
uis_signal_sendto (int dst,
                 int sig,
                 long int i_param,
                 unsigned long int u_param,
                 void *p_param);


#endif


