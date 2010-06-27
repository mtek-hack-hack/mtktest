/*
*****************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
*****************************************************************************
*
*      File             : cod_amr.h
*      Purpose          : Main encoder routine operating on a frame basis.
*
*****************************************************************************
*/
#ifndef cod_amr_h
#define cod_amr_h "$Id $"

/*
*****************************************************************************
*                         INCLUDE FILES
*****************************************************************************
*/
#include "typedef.h"
#include "cnst.h"
#include "lpc.h"
#include "lsp.h"
#include "ton_stab.h"
 
/*
*****************************************************************************
*                         DEFINITION OF DATA TYPES
*****************************************************************************
*/
/*-----------------------------------------------------------*
 *    Coder constant parameters (defined in "cnst.h")        *
 *-----------------------------------------------------------*
 *   L_WINDOW    : LPC analysis window size.                 *
 *   L_NEXT      : Samples of next frame needed for autocor. *
 *   L_FRAME     : Frame size.                               *
 *   L_FRAME_BY2 : Half the frame size.                      *
 *   L_SUBFR     : Sub-frame size.                           *
 *   M           : LPC order.                                *
 *   MP1         : LPC order+1                               *
 *   L_TOTAL7k4  : Total size of speech buffer.              *
 *   PIT_MIN7k4  : Minimum pitch lag.                        *
 *   PIT_MAX     : Maximum pitch lag.                        *
 *   L_INTERPOL  : Length of filter for interpolation        *
 *-----------------------------------------------------------*/

/*
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/

UWord32 AMR515_BufferSize( void );
UWord16 AMR515_SetBuffer( void *buf, UWord32 buf_size );
void AMR515_Reset( void );
void AMR515_End( void );

UWord16 *AMR515_Encode(
            Word32 *new_speech,        /* i   : speech input (L_FRAME)         */
            Word32 *packed_size        /* o   : serial bit stream           */
            );

 
#endif


