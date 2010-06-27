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
 * brs_spel.h
 *
 * Created by Jan Oberg, 
 *
 * Revision  history:
 *   021023  JNOG, Created.
 *
 */
#ifndef _brs_btn_h
#define _brs_btn_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_int_h
#include "msf_int.h"
#endif

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif


/**********************************************************************
 * Constants
 **********************************************************************/

#define BRS_LE_BUTTON_EXTENT 1
#define BRS_LE_BUTTON_LEFT_SIZE (2 + BRS_LE_BUTTON_EXTENT)
#define BRS_LE_BUTTON_RIGHT_SIZE (2 + BRS_LE_BUTTON_EXTENT)
#define BRS_LE_BUTTON_TOP_SIZE (2 + BRS_LE_BUTTON_EXTENT)
#define BRS_LE_BUTTON_BOTTOM_SIZE (2 + BRS_LE_BUTTON_EXTENT)


/**********************************************************************
 * Exported functions
 **********************************************************************/

/*
 * This function can be implemented to customize the look of buttons. If you choose to
 * implement it and draw button background and borders yourself, return TRUE to signal
 * that the layout engine should not draw its own button.
 */
int
brs_btn_draw (MSF_UINT32   msfHandle, 
              MsfPosition* position, 
              MsfSize*     size, 
              MsfColor*    btn_color,
              int          selected);
#endif
