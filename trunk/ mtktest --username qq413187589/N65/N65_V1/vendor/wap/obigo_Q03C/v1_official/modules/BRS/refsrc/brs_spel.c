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
 * brs_spel.c
 *
 * Created by Jan Oberg. 021023
 *
 * Revision history:
 *   021023, JNOG Created
 *
 */
/************************************************************
 * This file is used for:
 * + draw and get the sizes of the markup
 *   elements: input(type=button) and button.
 ************************************************************/

#include "brs_spel.h"


/************************************************************
 * Function definitions
 ************************************************************/

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
              int          selected)
{
  msfHandle = msfHandle;
  position = position;
  size = size;
  btn_color = btn_color;
  selected = selected;
  return FALSE;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
