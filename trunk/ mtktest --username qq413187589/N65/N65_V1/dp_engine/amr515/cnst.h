/*
*****************************************************************************
*
*      GSM AMR-NB speech codec   R98   Version 7.6.0   December 12, 2001
*                                R99   Version 3.3.0                
*                                REL-4 Version 4.1.0                
*
*****************************************************************************
*
*      File             : cnst.h
*      Purpose          : Speech codec constant parameters
*                       :  (encoder, decoder, and postfilter)
*
*****************************************************************************
*/
#ifndef cnst_h
#define cnst_h "$Id $"

#include "typedef.h"

#define L_TOTAL      320       /* Total size of speech buffer.             */
#define L_WINDOW     240       /* Window size in LP analysis               */
#define L_FRAME      160       /* Frame size                               */
#define L_FRAME_BY2  80        /* Frame size divided by 2                  */
#define L_SUBFR      40        /* Subframe size                            */
#define L_CODE       40        /* codevector length                        */
#define NB_TRACK     5         /* number of tracks                         */
#define STEP         5         /* codebook step size                       */
#define M            10        /* Order of LP filter                       */
#define MP1          (M+1)     /* Order of LP filter + 1                   */
#define MP2          (M+2)     /* Order of LP filter + 2                   */
#define LSF_GAP      205       /* Minimum distance between LSF after quan-
                                  tization; 50 Hz = 205                    */
#define AZ_SIZE       (4*M+4)  /* Size of array of LP filters in 4 subfr.s */
#define PIT_MIN       20       /* Minimum pitch lag (all other modes)      */
#define PIT_MAX       143      /* Maximum pitch lag                        */
#define PIT_MAX1      144      /* Maximum pitch lag                        */
#define L_INTERPOL    (10+1)   /* Length of filter for interpolation       */
#define L_INTER_SRCH  4        /* Length of filter for CL LTP search
                                  interpolation                            */
        
#define L_NEXT       40        /* Overhead in LP analysis                  */
#define SHARPMAX  13017        /* Maximum value of pitch sharpening        */
#define SHARPMIN  0            /* Minimum value of pitch sharpening        */
                                                                          
                                                                          
#define MAX_PRM_SIZE    57     /* max. num. of params                      */
#define MAX_SERIAL_SIZE 103    /* max. num. of serial bits for MR515       */
#define MAX_PACKED_SIZE (MAX_SERIAL_SIZE / 8 + 2)
                                                                          
#define GP_CLIP      15565        /* Pitch gain clipping = 0.95               */
#define N_FRAME      7            /* old pitch gains in average calculation   */

#define PRMNO_MR515  19

#define RR_SIZE      820

#define AMR_MAGIC_NUMBER "#!AMR\n"


extern const Word32 gamma1[M/2];
extern const Word32 gamma2[M/2];

#endif


