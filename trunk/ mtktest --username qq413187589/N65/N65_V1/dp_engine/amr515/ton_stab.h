/*
********************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
********************************************************************************
*
*      File             : ton_stab.h
*      Purpose          : Tone stabilization routines 
*
********************************************************************************
*/
#ifndef ton_stab_h
#define ton_stab_h "$Id $"
 
/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
#include "typedef.h"
#include "cnst.h"

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

/* state variable */
typedef struct {

   /* counters */
   Word16 count;
   
   /* gain history Q11 */
   Word16 gp[N_FRAME];
   
} tonStabState;

/*
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/
void ton_stab_reset( void );
/* reset of pre processing state (i.e. set state memory to zero)
   returns 0 on success
 */

Word16 check_lsp( void );

Word16 check_gp_clipping(Word16 g_pitch    /* i   : pitch gain              */
);

void update_gp_clipping(Word16 g_pitch    /* i   : pitch gain              */
);
#endif


