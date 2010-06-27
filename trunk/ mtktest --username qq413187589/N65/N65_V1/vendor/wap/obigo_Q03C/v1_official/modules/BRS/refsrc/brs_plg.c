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
/*
 * brs_plg.c
 *
 * Created by Anders Edenbrandt, Wed Oct 23 16:48:54 2002.
 *
 * Revision history:
 *
 */
/************************************************************
 * Registering of all plug-ins in the refsrc directory
 ************************************************************/

/************************************************************
 * Functions
 ************************************************************/

extern void brs_plab_register (void);
extern void brs_pltx_register (void);
extern void brs_plti_register (void);
extern void brs_plsms_register (void);

#ifdef MMS_SUPPORT
extern void brs_plmms_register (void);
#endif

#ifdef __SUPPORT_INFUSIO__
extern void brs_plege_register (void);
extern char support_ege_runtime;
#endif

#ifdef STREAM_SUPPORT
extern void brs_plrtsp_register (void);
#endif


void
brs_plg_init (void)
{
  /* Register the "about" scheme handler */
  brs_plab_register ();

  /* Register the handler of text/plain documents */
  brs_pltx_register ();

  brs_plti_register ();

  /* Register the "sms" and "smsto" scheme handler */
  brs_plsms_register();

#ifdef MMS_SUPPORT
  /* Register the "mms" and "mmsto" scheme handler */
  brs_plmms_register();
#endif

#ifdef __SUPPORT_INFUSIO__
  if(support_ege_runtime)
  {
    /* Register the "ege" scheme handler */
    brs_plege_register();
  }
#endif
#ifdef STREAM_SUPPORT
  /* Register the "rtsp" scheme handler */
  brs_plrtsp_register();
#endif
}





















