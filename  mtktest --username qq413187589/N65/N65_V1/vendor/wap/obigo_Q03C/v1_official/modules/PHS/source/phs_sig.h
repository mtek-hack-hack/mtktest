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








 





#ifndef _phs_sig_h
#define _phs_sig_h








#define PHS_MODULE_MAIN           0x000
#define PHS_MODULE_PARSER         0x020
#define PHS_MODULE_SIA            0x030
#define PHS_MODULE_HTTP           0x040
#define PHS_MODULE_MPRT           0x050
#define PHS_MODULE_MSG            0x060






#define PHS_SIGNAL_SENDTO_UP(d, sig, u, p) \
  phs_signal_sendto ((d), (sig), 0, 0, (u), (p))

#define PHS_SIGNAL_SENDTO_IU(d, sig, i, u) \
  phs_signal_sendto ((d), (sig), (i), 0, (u), NULL)

#define PHS_SIGNAL_SENDTO_IIU(d, sig, i1, i2, u) \
  phs_signal_sendto ((d), (sig), (i1), (i2), (u), NULL)

#define PHS_SIGNAL_SENDTO_P(d, sig, p) \
  phs_signal_sendto ((d), (sig), 0, 0, 0, (p))

#define PHS_SIGNAL_SENDTO_I(d, sig, i) \
  phs_signal_sendto ((d), (sig), (i), 0, 0, NULL)






typedef struct phs_signal_st {
  struct phs_signal_st *next;
  int                   dst;      
  int                   type;     
  long int              i_param1;  
  long int              i_param2;  
  unsigned long int     u_param;
  void                 *p_param;
} phs_signal_t;




typedef void phs_signal_function_t (phs_signal_t *);









void
phs_signal_init (void);




void
phs_signal_terminate (void);




void
phs_signal_process (void);





int
phs_signal_queue_is_empty (void);




void
phs_signal_delete (phs_signal_t *sig);





void
phs_signal_register_dst (int dst, phs_signal_function_t *f);










void
phs_signal_sendto (int dst,
                 int sig,
                 long int i_param1,
                 long int i_param2,
                 unsigned long int u_param,
                 void *p_param);


#endif


