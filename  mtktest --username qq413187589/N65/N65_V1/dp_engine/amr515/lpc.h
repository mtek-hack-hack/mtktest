/*
********************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
********************************************************************************
*
*      File             : lpc.h
*      Purpose          : 2 LP analyses centered at 2nd and 4th subframe
*                         for mode 12.2. For all other modes a
*                         LP analysis centered at 4th subframe is 
*                         performed.
*
********************************************************************************
*/
#ifndef lpc_h
#define lpc_h "$Id $"

/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
#include "typedef.h"

/*
********************************************************************************
*                         LOCAL VARIABLES AND TABLES
********************************************************************************
*/
/*
********************************************************************************
*                         DEFINITION OF DATA TYPES
********************************************************************************
*/
/*
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/
void lpc_reset( void );
/* reset of pre processing state (i.e. set state memory to zero)
   returns 0 on success
 */

void lpc(
    Word32 *sig,        /* i  : Input signal           Q15  */
    Word32 *temp_buf,   /* n  : Input signal           Q15  */
    Word32 *a           /* o  : predictor coefficients Q12  */
);

#endif

