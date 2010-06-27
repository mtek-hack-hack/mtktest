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
























#ifndef _brs_sifs_h
#define _brs_sifs_h

#include "brs_cfg.h"
#ifdef BRS_CONFIG_WMLS

#include "brs_silt.h"
#include "brs_sifr.h"
#include "brs_sibp.h"

typedef struct {
  brs_si_t_head head;
} brs_si_fs_t;




brs_si_fs_t *
brs_si_FS_New (void);








void
brs_si_FS_Delete (brs_si_fs_t **pThis, brs_si_structBPInfo *bpi);













void
FS_Push (brs_si_fs_t *thisx, brs_si_frame_t **pFrame, MSF_UINT32 returnIP);






brs_si_frame_t *
FS_Pop (brs_si_fs_t *thisx);

#endif
#endif
