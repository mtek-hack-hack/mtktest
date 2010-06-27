#ifndef WITH_mma

/* `mpa/privmpa.h' $Revision: 1.9 $ $Date: 1999/08/28 14:36:49 $
 *  * Crypto-System Toolbox, copyright 1995 Baltimore Inc.
 *  * This file contains any internal information for the library which
 * is needed to help the implementation in C.  It also is used to
 * isolate code which may not be directly portable.
 */

#ifndef _PRIVMPA_H /* prevent mulitiple inclusion */
#define _PRIVMPA_H

#include "mpa.h" /* For mpa_dig, MPA_BIT, & MPA_BIT_2 */

/* MACRO: HI(x)
 * Value: The high order half of the mpa_dig x.
 * Note:  If you use HI with a signed number it will extend the sign through
 *          and return the wrong result.
 */
#define HI(x) ((x) >> MPA_BIT_2)

/* MACRO: LO(x)
 * Value: The low order half of the mpa_dig x.
 */
#define LO(x) ((x) & (((mpa_dig) 1 << MPA_BIT_2) - 1))

/* Macro: COMB(hi, lo)
 * Value: Combination of two half-mpa_dig hi and lo into one value.
 * Note:  lo should not be larger than half an mpa_dig.
 */
#define COMB(hi,lo) (((hi) << MPA_BIT_2) + (lo))

/* Macro: MPA_TEMP_PLACES
 * Value: The number of mpa_dig which mpa_div() and mpa_sqrt() will try to
 *          grab off the stack in preference to allocating memory themselves.
 */
#ifndef MPA_TEMP_PLACES
#define MPA_TEMP_PLACES (256)
#endif /* not MPA_TEMP_PLACES */

#endif /* not PRIVMPA_H */

#endif
