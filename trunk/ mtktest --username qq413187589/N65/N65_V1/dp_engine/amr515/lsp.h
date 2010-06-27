/*
********************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
********************************************************************************
*
*      File             : lsp.h
*      Purpose          : Conversion from A(z) to LSP. Quantization and
*                         interpolation of LSPs.
*
********************************************************************************
*/
#ifndef lsp_h
#define lsp_h "$Id $"
 
/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
#include "typedef.h"
#include "q_plsf.h"

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
typedef struct {
   /* Past LSPs */
   Word32      lsp_old[M/2];
   Word32      lsp_old_q[M/2];
} lspState;

extern lspState lspSt;

/*
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/
/*
**************************************************************************
*
*  Function    : lsp_reset
*  Purpose     : Resets state memory
*  Returns     : 0 on success
*
**************************************************************************
*/
void lsp_reset( void );

/*
**************************************************************************
*
*  Function    : lsp
*  Purpose     : Conversion from LP coefficients to LSPs.
*                Quantization of LSPs.
*  Description : Generates 2 sets of LSPs from 2 sets of
*                LP coefficients for mode 12.2. For the other
*                modes 1 set of LSPs is generated from 1 set of
*                LP coefficients. These LSPs are quantized with
*                Matrix/Vector quantization (depending on the mode)
*                and interpolated for the subframes not yet having
*                their own LSPs.
*                
**************************************************************************
*/
void lsp(
        Word32 *az,           /* i/o : interpolated LP parameters Q12          */
        Word32 *azQ,          /* o   : quantization interpol. LP parameters Q12*/
        Word32 *lsp_new,      /* o   : new lsp vector                          */ 
        Word16 **anap         /* o   : analysis parameters                     */
        );

#endif


