/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   wav_codec.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Wave codec functions, adapted from g711.c 1.10
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "wav.h"

#include "G711_CNG_typedef.h"
#include "G711_CNG_armdsp_m.h"
#include "G711_CNG_dspfns_m.h"
#define  SIGN_BIT    (0x80)      /* Sign bit for a A-law byte.       */
#define  QUANT_MASK  (0x0F)      /* Quantization field mask.         */
#define  NSEGS       (8)         /* Number of A-law segments.        */
#define  SEG_SHIFT   (4)         /* Left shift for segment number.   */
#define  SEG_MASK    (0x70)      /* Segment field mask.              */
#define  BIAS        (0x84)      /* Bias for linear code.            */
#define FIXED(v)      ((Word16)(16384.0 * (v) + 0.5))
#define FRAME_SAMPLE  80

const int16 sintab[] = {
       0,   201,   402,   603,   804,  1005,  1206,  1406,
    1607,  1808,  2009,  2209,  2410,  2610,  2811,  3011,
    3211,  3411,  3611,  3811,  4011,  4210,  4409,  4608,
    4807,  5006,  5205,  5403,  5601,  5799,  5997,  6195,
    6392,  6589,  6786,  6983,  7179,  7375,  7571,  7766,
    7961,  8156,  8351,  8545,  8739,  8933,  9126,  9319,
    9511,  9703,  9895, 10087, 10278, 10469, 10659, 10849,
   11038, 11227, 11416, 11604, 11792, 11980, 12166, 12353,
   12539, 12724, 12909, 13094, 13278, 13462, 13645, 13827,
   14009, 14191, 14372, 14552, 14732, 14911, 15090, 15268,
   15446, 15623, 15799, 15975, 16150, 16325, 16499, 16672,
   16845, 17017, 17189, 17360, 17530, 17699, 17868, 18036,
   18204, 18371, 18537, 18702, 18867, 19031, 19194, 19357,
   19519, 19680, 19840, 20000, 20159, 20317, 20474, 20631,
   20787, 20942, 21096, 21249, 21402, 21554, 21705, 21855,
   22005, 22153, 22301, 22448, 22594, 22739, 22883, 23027,
   23169, 23311, 23452, 23592, 23731, 23869, 24006, 24143,
   24278, 24413, 24546, 24679, 24811, 24942, 25072, 25201,
   25329, 25456, 25582, 25707, 25831, 25954, 26077, 26198,
   26318, 26438, 26556, 26673, 26789, 26905, 27019, 27132,
   27244, 27355, 27466, 27575, 27683, 27790, 27896, 28001,
   28105, 28208, 28309, 28410, 28510, 28608, 28706, 28802,
   28897, 28992, 29085, 29177, 29268, 29358, 29446, 29534,
   29621, 29706, 29790, 29873, 29955, 30036, 30116, 30195,
   30272, 30349, 30424, 30498, 30571, 30643, 30713, 30783,
   30851, 30918, 30984, 31049, 31113, 31175, 31237, 31297,
   31356, 31413, 31470, 31525, 31580, 31633, 31684, 31735,
   31785, 31833, 31880, 31926, 31970, 32014, 32056, 32097,
   32137, 32176, 32213, 32249, 32284, 32318, 32350, 32382,
   32412, 32441, 32468, 32495, 32520, 32544, 32567, 32588,
   32609, 32628, 32646, 32662, 32678, 32692, 32705, 32717,
   32727, 32736, 32744, 32751, 32757, 32761, 32764, 32766,
   32767
};

const uint16 Alaw_Tab[256] = {
0xEA80, 0xEB80, 0xE880, 0xE980, 0xEE80, 0xEF80, 0xEC80, 0xED80,
0xE280, 0xE380, 0xE080, 0xE180, 0xE680, 0xE780, 0xE480, 0xE580,
0xF540, 0xF5C0, 0xF440, 0xF4C0, 0xF740, 0xF7C0, 0xF640, 0xF6C0,
0xF140, 0xF1C0, 0xF040, 0xF0C0, 0xF340, 0xF3C0, 0xF240, 0xF2C0,
0xAA00, 0xAE00, 0xA200, 0xA600, 0xBA00, 0xBE00, 0xB200, 0xB600,
0x8A00, 0x8E00, 0x8200, 0x8600, 0x9A00, 0x9E00, 0x9200, 0x9600,
0xD500, 0xD700, 0xD100, 0xD300, 0xDD00, 0xDF00, 0xD900, 0xDB00,
0xC500, 0xC700, 0xC100, 0xC300, 0xCD00, 0xCF00, 0xC900, 0xCB00,
0xFEA8, 0xFEB8, 0xFE88, 0xFE98, 0xFEE8, 0xFEF8, 0xFEC8, 0xFED8,
0xFE28, 0xFE38, 0xFE08, 0xFE18, 0xFE68, 0xFE78, 0xFE48, 0xFE58,
0xFFA8, 0xFFB8, 0xFF88, 0xFF98, 0xFFE8, 0xFFF8, 0xFFC8, 0xFFD8,
0xFF28, 0xFF38, 0xFF08, 0xFF18, 0xFF68, 0xFF78, 0xFF48, 0xFF58,
0xFAA0, 0xFAE0, 0xFA20, 0xFA60, 0xFBA0, 0xFBE0, 0xFB20, 0xFB60,
0xF8A0, 0xF8E0, 0xF820, 0xF860, 0xF9A0, 0xF9E0, 0xF920, 0xF960,
0xFD50, 0xFD70, 0xFD10, 0xFD30, 0xFDD0, 0xFDF0, 0xFD90, 0xFDB0,
0xFC50, 0xFC70, 0xFC10, 0xFC30, 0xFCD0, 0xFCF0, 0xFC90, 0xFCB0,
0x1580, 0x1480, 0x1780, 0x1680, 0x1180, 0x1080, 0x1380, 0x1280,
0x1D80, 0x1C80, 0x1F80, 0x1E80, 0x1980, 0x1880, 0x1B80, 0x1A80,
0x0AC0, 0x0A40, 0x0BC0, 0x0B40, 0x08C0, 0x0840, 0x09C0, 0x0940,
0x0EC0, 0x0E40, 0x0FC0, 0x0F40, 0x0CC0, 0x0C40, 0x0DC0, 0x0D40,
0x5600, 0x5200, 0x5E00, 0x5A00, 0x4600, 0x4200, 0x4E00, 0x4A00,
0x7600, 0x7200, 0x7E00, 0x7A00, 0x6600, 0x6200, 0x6E00, 0x6A00,
0x2B00, 0x2900, 0x2F00, 0x2D00, 0x2300, 0x2100, 0x2700, 0x2500,
0x3B00, 0x3900, 0x3F00, 0x3D00, 0x3300, 0x3100, 0x3700, 0x3500,
0x0158, 0x0148, 0x0178, 0x0168, 0x0118, 0x0108, 0x0138, 0x0128,
0x01D8, 0x01C8, 0x01F8, 0x01E8, 0x0198, 0x0188, 0x01B8, 0x01A8,
0x0058, 0x0048, 0x0078, 0x0068, 0x0018, 0x0008, 0x0038, 0x0028,
0x00D8, 0x00C8, 0x00F8, 0x00E8, 0x0098, 0x0088, 0x00B8, 0x00A8,
0x0560, 0x0520, 0x05E0, 0x05A0, 0x0460, 0x0420, 0x04E0, 0x04A0,
0x0760, 0x0720, 0x07E0, 0x07A0, 0x0660, 0x0620, 0x06E0, 0x06A0,
0x02B0, 0x0290, 0x02F0, 0x02D0, 0x0230, 0x0210, 0x0270, 0x0250,
0x03B0, 0x0390, 0x03F0, 0x03D0, 0x0330, 0x0310, 0x0370, 0x0350
};

const uint16 Ulaw_Tab[256] = {
0x8284, 0x8684, 0x8A84, 0x8E84, 0x9284, 0x9684, 0x9A84, 0x9E84,
0xA284, 0xA684, 0xAA84, 0xAE84, 0xB284, 0xB684, 0xBA84, 0xBE84,
0xC184, 0xC384, 0xC584, 0xC784, 0xC984, 0xCB84, 0xCD84, 0xCF84,
0xD184, 0xD384, 0xD584, 0xD784, 0xD984, 0xDB84, 0xDD84, 0xDF84,
0xE104, 0xE204, 0xE304, 0xE404, 0xE504, 0xE604, 0xE704, 0xE804,
0xE904, 0xEA04, 0xEB04, 0xEC04, 0xED04, 0xEE04, 0xEF04, 0xF004,
0xF0C4, 0xF144, 0xF1C4, 0xF244, 0xF2C4, 0xF344, 0xF3C4, 0xF444,
0xF4C4, 0xF544, 0xF5C4, 0xF644, 0xF6C4, 0xF744, 0xF7C4, 0xF844,
0xF8A4, 0xF8E4, 0xF924, 0xF964, 0xF9A4, 0xF9E4, 0xFA24, 0xFA64,
0xFAA4, 0xFAE4, 0xFB24, 0xFB64, 0xFBA4, 0xFBE4, 0xFC24, 0xFC64,
0xFC94, 0xFCB4, 0xFCD4, 0xFCF4, 0xFD14, 0xFD34, 0xFD54, 0xFD74,
0xFD94, 0xFDB4, 0xFDD4, 0xFDF4, 0xFE14, 0xFE34, 0xFE54, 0xFE74,
0xFE8C, 0xFE9C, 0xFEAC, 0xFEBC, 0xFECC, 0xFEDC, 0xFEEC, 0xFEFC,
0xFF0C, 0xFF1C, 0xFF2C, 0xFF3C, 0xFF4C, 0xFF5C, 0xFF6C, 0xFF7C,
0xFF88, 0xFF90, 0xFF98, 0xFFA0, 0xFFA8, 0xFFB0, 0xFFB8, 0xFFC0,
0xFFC8, 0xFFD0, 0xFFD8, 0xFFE0, 0xFFE8, 0xFFF0, 0xFFF8, 0x0000,
0x7D7C, 0x797C, 0x757C, 0x717C, 0x6D7C, 0x697C, 0x657C, 0x617C,
0x5D7C, 0x597C, 0x557C, 0x517C, 0x4D7C, 0x497C, 0x457C, 0x417C,
0x3E7C, 0x3C7C, 0x3A7C, 0x387C, 0x367C, 0x347C, 0x327C, 0x307C,
0x2E7C, 0x2C7C, 0x2A7C, 0x287C, 0x267C, 0x247C, 0x227C, 0x207C,
0x1EFC, 0x1DFC, 0x1CFC, 0x1BFC, 0x1AFC, 0x19FC, 0x18FC, 0x17FC,
0x16FC, 0x15FC, 0x14FC, 0x13FC, 0x12FC, 0x11FC, 0x10FC, 0x0FFC,
0x0F3C, 0x0EBC, 0x0E3C, 0x0DBC, 0x0D3C, 0x0CBC, 0x0C3C, 0x0BBC,
0x0B3C, 0x0ABC, 0x0A3C, 0x09BC, 0x093C, 0x08BC, 0x083C, 0x07BC,
0x075C, 0x071C, 0x06DC, 0x069C, 0x065C, 0x061C, 0x05DC, 0x059C,
0x055C, 0x051C, 0x04DC, 0x049C, 0x045C, 0x041C, 0x03DC, 0x039C,
0x036C, 0x034C, 0x032C, 0x030C, 0x02EC, 0x02CC, 0x02AC, 0x028C,
0x026C, 0x024C, 0x022C, 0x020C, 0x01EC, 0x01CC, 0x01AC, 0x018C,
0x0174, 0x0164, 0x0154, 0x0144, 0x0134, 0x0124, 0x0114, 0x0104,
0x00F4, 0x00E4, 0x00D4, 0x00C4, 0x00B4, 0x00A4, 0x0094, 0x0084,
0x0078, 0x0070, 0x0068, 0x0060, 0x0058, 0x0050, 0x0048, 0x0040,
0x0038, 0x0030, 0x0028, 0x0020, 0x0018, 0x0010, 0x0008, 0x0000
};

static const short seg_end[] = {
   0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF
};

/* copy from CCITT G.711 specifications */
static const unsigned char _u2a[128] = {        /* u- to A-law conversions */
   1,    1,    2,    2,    3,    3,    4,    4,
   5,    5,    6,    6,    7,    7,    8,    8,
   9,    10,   11,   12,   13,   14,   15,   16,
   17,   18,   19,   20,   21,   22,   23,   24,
   25,   27,   29,   31,   33,   34,   35,   36,
   37,   38,   39,   40,   41,   42,   43,   44,
   46,   48,   49,   50,   51,   52,   53,   54,
   55,   56,   57,   58,   59,   60,   61,   62,
   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,
   80,   82,   83,   84,   85,   86,   87,   88,
   89,   90,   91,   92,   93,   94,   95,   96,
   97,   98,   99,   100,  101,  102,  103,  104,
   105,  106,  107,  108,  109,  110,  111,  112,
   113,  114,  115,  116,  117,  118,  119,  120,
   121,  122,  123,  124,  125,  126,  127,  128
};

static const unsigned char _a2u[128] = {        /* A- to u-law conversions */
   1,    3,    5,    7,    9,    11,   13,   15,
   16,   17,   18,   19,   20,   21,   22,   23,
   24,   25,   26,   27,   28,   29,   30,   31,
   32,   32,   33,   33,   34,   34,   35,   35,
   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   47,   48,   48,   49,   49,
   50,   51,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,   64,
   65,   66,   67,   68,   69,   70,   71,   72,
   73,   74,   75,   76,   77,   78,   79,   80,
   80,   81,   82,   83,   84,   85,   86,   87,
   88,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,   100,  101,  102,  103,
   104,  105,  106,  107,  108,  109,  110,  111,
   112,  113,  114,  115,  116,  117,  118,  119,
   120,  121,  122,  123,  124,  125,  126,  127
};

// Remove the DC part of decoded speech output signal.
// Prevent the low freq noise which comes from G711_CNG_PreProcess
// Perform high-pass IIR filter
void RemoveDC(short *speech_in, unsigned int *prep_xn_1_2, unsigned int *prep_yn_1_2)
{
   int i;
   unsigned short *pIn;
   UWord32 xn, xn_1_2, yn, yn_1_2;
   Word32 temp;
   const Word32 numer = (unsigned)FIXED(0.94598) + ((unsigned)FIXED(-1.89195) << 16);
   const Word32 denom = (unsigned)FIXED(1.8890) + ((unsigned)FIXED(-0.8949) << 16);  

   pIn = (unsigned short *)speech_in;   
   
   xn_1_2 = *prep_xn_1_2;
   yn_1_2 = *prep_yn_1_2;
   
   for (i=FRAME_SAMPLE; i>0; i--) {
      // y(n) = 1.889033*y(n-1) - 0.894874 * y(n-2) + 0.945976 * x(n) - 1.891953 * x(n-1) + 0.945976 * x(n-2)
      xn = *pIn;
      temp = smulbb(denom, yn_1_2);
      temp = smlabb(numer, xn, temp);
      temp = smlatt(denom, yn_1_2, temp);
      temp = smlatb(numer, xn_1_2, temp);
      temp = smlabt(numer, xn_1_2, temp);
      xn_1_2 = (xn_1_2 << 16) + xn;
      temp = temp >> 14;

      yn = sature(temp) & 0xffff;      
      yn_1_2 = (yn_1_2 << 16) + yn;
      *pIn++ = yn;
   }
   // Save the result of High Pass Filter
   *prep_xn_1_2 = xn_1_2;
   *prep_yn_1_2 = yn_1_2;
}


static int search( int val, const short *table, int size )
{
   int i;

   for(i = 0; i < size; i++) {
      if (val <= *table++)
         return (i);
   }
   return (size);
}

/*
 * linear2alaw() - Convert a 16-bit linear PCM value to 8-bit A-law
 *
 * linear2alaw() accepts an 16-bit integer and encodes it as A-law data.
 *
 *    Linear Input Code Compressed Code
 * ------------------------   ---------------
 * 0000000wxyza         000wxyz
 * 0000001wxyza         001wxyz
 * 000001wxyzab         010wxyz
 * 00001wxyzabc         011wxyz
 * 0001wxyzabcd         100wxyz
 * 001wxyzabcde         101wxyz
 * 01wxyzabcdef         110wxyz
 * 1wxyzabcdefg         111wxyz
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */
int linear2alaw( int p_val )  /* 2's complement (16-bit range) */
{
   int      mask;
   int      seg;
   unsigned char  aval;
   int      pcm_val = (p_val >> 3) << 3;

   if (pcm_val >= 0) {
      mask = 0xD5;      /* sign (7th) bit = 1 */
   }
   else {
      mask = 0x55;      /* sign bit = 0 */
      pcm_val = -pcm_val - 8;
   }

   /* Convert the scaled magnitude to segment number. */
   seg = search(pcm_val, seg_end, 8);

   /* Combine the sign, segment, and quantization bits. */

   if (seg >= 8)     /* out of range, return maximum value. */
      return (0x7F ^ mask);
   else {
      aval = seg << SEG_SHIFT;
      if (seg < 2)
         aval |= (pcm_val >> 4) & QUANT_MASK;
      else
         aval |= (pcm_val >> (seg + 3)) & QUANT_MASK;
      return (aval ^ mask);
   }
}

/*
 * alaw2linear() - Convert an A-law value to 16-bit linear PCM
 *
 */
unsigned short alaw2linear ( unsigned char a_val )
{
   int      t;
   int      seg;

   a_val ^= 0x55;

   t = (a_val & QUANT_MASK) << 4;
   seg = ((unsigned)a_val & SEG_MASK) >> SEG_SHIFT;
   switch (seg) {
   case 0:
      t += 8;
      break;
   case 1:
      t += 0x108;
      break;
   default:
      t += 0x108;
      t <<= seg - 1;
   }
   return (unsigned short)(short)((a_val & SIGN_BIT) ? t : -t);
}

/*
 * linear2ulaw() - Convert a linear PCM value to u-law
 *
 * In order to simplify the encoding process, the original linear magnitude
 * is biased by adding 33 which shifts the encoding range from (0 - 8158) to
 * (33 - 8191). The result can be seen in the following encoding table:
 *
 * Biased Linear Input Code   Compressed Code
 * ------------------------   ---------------
 * 00000001wxyza        000wxyz
 * 0000001wxyzab        001wxyz
 * 000001wxyzabc        010wxyz
 * 00001wxyzabcd        011wxyz
 * 0001wxyzabcde        100wxyz
 * 001wxyzabcdef        101wxyz
 * 01wxyzabcdefg        110wxyz
 * 1wxyzabcdefgh        111wxyz
 *
 * Each biased linear code has a leading 1 which identifies the segment
 * number. The value of the segment number is equal to 7 minus the number
 * of leading 0's. The quantization interval is directly available as the
 * four bits wxyz.  * The trailing bits (a - h) are ignored.
 *
 * Ordinarily the complement of the resulting code word is used for
 * transmission, and so the code word is complemented before it is returned.
 *
 * For further information see John C. Bellamy's Digital Telephony, 1982,
 * John Wiley & Sons, pps 98-111 and 472-476.
 */
int linear2ulaw( int p_val )  /* 2's complement (16-bit range) */
{
   int      mask;
   int      seg;
   unsigned char  uval;
   int      pcm_val = (int)(short)p_val;

   /* Get the sign and the magnitude of the value. */
   if (pcm_val < 0) {
      pcm_val = BIAS - pcm_val;
      mask = 0x7F;
   }
   else {
      pcm_val += BIAS;
      mask = 0xFF;
   }

   /* Convert the scaled magnitude to segment number. */
   seg = search(pcm_val, seg_end, 8);

   /*
    * Combine the sign, segment, quantization bits;
    * and complement the code word.
    */
   if (seg >= 8)     /* out of range, return maximum value. */
      return (0x7F ^ mask);
   else {
      uval = (seg << 4) | ((pcm_val >> (seg + 3)) & 0xF);
      return (uval ^ mask);
   }

}

/*
 * ulaw2linear() - Convert a u-law value to 16-bit linear PCM
 *
 * First, a biased linear code is derived from the code word. An unbiased
 * output can then be obtained by subtracting 33 from the biased code.
 *
 * Note that this function expects to be passed the complement of the
 * original code word. This is in keeping with ISDN conventions.
 */
unsigned short ulaw2linear( unsigned char u_val )
{
   int      t;

   /* Complement to obtain normal u-law value. */
   u_val = ~u_val;

   /*
    * Extract and bias the quantization bits. Then
    * shift up by the segment number and subtract out the bias.
    */
   t = ((u_val & QUANT_MASK) << 3) + BIAS;
   t <<= ((unsigned)u_val & SEG_MASK) >> SEG_SHIFT;

   return (unsigned short)(short)((u_val & SIGN_BIT) ? (BIAS - t) : (t - BIAS));
}

/* A-law to u-law conversion */
unsigned char alaw2ulaw( unsigned char aval )
{
   aval &= 0xff;
   return ((aval & 0x80) ? (0xFF ^ _a2u[aval ^ 0xD5]) :
       (0x7F ^ _a2u[aval ^ 0x55]));
}

/* u-law to A-law conversion */
unsigned char ulaw2alaw( unsigned char uval )
{
   uval &= 0xff;
   return ((uval & 0x80) ? (0xD5 ^ (_u2a[0xFF ^ uval] - 1)) :
       (0x55 ^ (_u2a[0x7F ^ uval] - 1)));
}

/* ------------------------------------------------------------------------------ */

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"

/* Intel ADPCM step variation table */
static const short indexTable[16] = {
    -1, -1, -1, -1, 2, 4, 6, 8,
    -1, -1, -1, -1, 2, 4, 6, 8,
};

/* Intel ADPCM step sizes table */
static const short stepsizeTable[90] =
{
       7,     8,     9,    10,    11,    12,    13,    14,    16,    17,
      19,    21,    23,    25,    28,    31,    34,    37,    41,    45,
      50,    55,    60,    66,    73,    80,    88,    97,   107,   118,
     130,   143,   157,   173,   190,   209,   230,   253,   279,   307,
     337,   371,   408,   449,   494,   544,   598,   658,   724,   796,
     876,   963,  1060,  1166,  1282,  1411,  1552,  1707,  1878,  2066,
    2272,  2499,  2749,  3024,  3327,  3660,  4026,  4428,  4871,  5358,
    5894,  6484,  7132,  7845,  8630,  9493, 10442, 11487, 12635, 13899,
   15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};

/* Microsoft ADPCM step variation table */
static const short stepAdjustTable[] = {
        230, 230, 230, 230, 307, 409, 512, 614,
        768, 614, 512, 409, 307, 230, 230, 230
};

/* Microsoft ADPCM coefficient table */
const short iCoeff[7][2] = {
                        { 256,   0},
                        { 512,-256},
                        {   0,   0},
                        { 192,  64},
                        { 240,   0},
                        { 460,-208},
                        { 392,-232}
};
#pragma arm section rwdata, rodata , zidata
#endif /* Note: for ROM code */

/*
**************************************************************************
* Initialze the data used by the coder.
**************************************************************************
*/
void dviAdpcm_Init( dviAdpcm_State *state )
{
   state->index = 0;
   state->valpred = 0;
   return;
}

#if defined(MT6223) || defined(MT6223P)
#pragma arm section code = "SBC_DYNAMIC_CODE"
#else
#pragma arm section code = "INTERNCODE"
#endif
/*
**************************************************************************
* Encode linear to ADPCM
**************************************************************************
*/
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
unsigned char dviAdpcm_Encode( unsigned short pcm, dviAdpcm_State *state )
{
   int sign;         /* Current adpcm sign bit */
   int diff;         /* Difference between val and valprev */
   int step;         /* Stepsize */
   int delta;        /* Current adpcm output value */
   int vpdiff;       /* Current change to valpred */
   int index_cache = state->index;
   int valpred_cache = state->valpred;
   int val = (int)(short)pcm;

   step = stepsizeTable[index_cache];

   /* Step 1 - compute difference with previous value */
   diff = val - valpred_cache;
   sign = (diff < 0) ? 8 : 0;
   if (sign) diff = (-diff);

   /* Step 2 - Divide and clamp */
   /* Note:
   ** This code *approximately* computes:
   **    delta = diff*4/step;
   **    vpdiff = (delta+0.5)*step/4;
   ** but in shift step bits are dropped. The net result of this is
   ** that even if you have fast mul/div hardware you cannot put it to
   ** good use since the fixup would be too expensive.
   */
   delta = 0;

   vpdiff = (step >> 3);

   if (diff >= step) {
      delta = 4;
      diff -= step;
      vpdiff += step;
   }

   step >>= 1;

   if (diff >= step) {
      delta |= 2;
      diff -= step;
      vpdiff += step;
   }

   step >>= 1;

   if(diff >= step) {
      delta |= 1;
      vpdiff += step;
   }

   if ( sign ) valpred_cache -= vpdiff; /* Step 3 - Update previous value */
   else valpred_cache += vpdiff;

   if( valpred_cache > 32767 )     /* Step 4 - Clamp previous value to 16 bits */
      valpred_cache = 32767;
   else if( valpred_cache < -32768 )
      valpred_cache = -32768;
   state->valpred = valpred_cache;

   /* Step 5 - Assemble value, update index and step values */
   delta |= sign;

   index_cache += indexTable[delta];

   if(index_cache < 0)
      index_cache = 0;
   else if ( index_cache > 88 )
      index_cache = 88;
   state->index = index_cache;
   return delta;
}
#endif /* Note: for ROM code */

/*
**************************************************************************
* Decode Linear from ADPCM
**************************************************************************
*/

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
int dviAdpcm_Decode( int delta, dviAdpcm_State *state )
{
   int step;        /* Stepsize */
   int vpdiff;      /* Current change to valpred */
   int index_cache = state->index;

   step = stepsizeTable[index_cache];

   /* Step 2 - Find new index value (for later) */
   index_cache += indexTable[delta];
   if ( index_cache < 0 )
      index_cache = 0;
   else if ( index_cache > 88 )
      index_cache = 88;
   state->index = index_cache;

   vpdiff = step >> 3;
   if (delta & 4) vpdiff += step;
   if (delta & 2) vpdiff += step>>1;
   if (delta & 1) vpdiff += step>>2;

   {
      int valpred_cache = state->valpred;

      if (delta & 8) {
      	valpred_cache -= vpdiff;
      } else {
      	valpred_cache += vpdiff;
      }

      if (valpred_cache < -32768)
         valpred_cache = -32768;
      else if (valpred_cache> 32767)
         valpred_cache = 32767;

      state->valpred = valpred_cache;
      return valpred_cache;
   }
}
#endif /* Note: for ROM code */

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
short ms_adpcm_decode_sample( uint8 error_delta, MS_ADPCM_STATE *state )
{
   int linearSample, delta;

	linearSample = ((state->iSamp1 * state->iCoeff1) +
      (state->iSamp2 * state->iCoeff2)) >> 8;

	if ( error_delta & 0x08)
		linearSample += state->iDelta * (error_delta-0x10);
	else
		linearSample += state->iDelta * error_delta;

	/* Clamp linearSample to a signed 16-bit value. */
	if (linearSample < -32768)
		linearSample = -32768;
	else if (linearSample > 32767)
		linearSample = 32767;

	delta = ((int) state->iDelta * stepAdjustTable[error_delta]) >> 8;
   state->iDelta = (delta < 16) ? 16:delta;
	state->iSamp2 = state->iSamp1;
	state->iSamp1 = linearSample;

	/*
		Because of earlier range checking, new_sample will be
		in the range of an int16.
	*/
	return (short) linearSample;
}
#endif /* Note: for ROM code */

int16 my_cos( int32 idx )
{
   int32 frac;

   if( idx < 0 )
      idx = -idx;
   idx &= 0xFFFF;
   if( idx >= 0x8000 ) {
      idx = 0x10000 - idx;
   }
   frac = idx & 0x3F;
   idx = (idx >> 6) & 0x3FF;
   if( idx < 256 )
      return (sintab[256-idx] * (0x40-frac) + sintab[256-idx-1] * frac) >> 6;
   return (-sintab[idx-256] * (0x40-frac) - sintab[idx-256+1] * frac) >> 6;
}

/*
 * Bit reverse the number
 *
 * Change 11100000b to 00000111b or vice-versa
 */
static int permute( int index, int fft_size_bits )
{
   int   n1, result, loop;

   n1 = 1 << fft_size_bits;
   result = 0;

   for (loop = 0; loop < fft_size_bits; loop++)  {
      n1 >>= 1;         /* n1 / 2.0 */
      if (index < n1)
         continue;

      result += (1 << loop);
      index -= n1;
   }

   return result;
}

void my_fft( int16 *real, int16 *imag, int fft_size_bits )
{
   unsigned i1, i2, i3, i4, y, loop1, loop2;
   int    loop, z1, z2;
   int    a1, a2, b1, b2;
   int fft_size = 1 << fft_size_bits;

   /* Scale the data */
   for (loop = 0; loop < fft_size; loop++)  {
      real[loop] >>= fft_size_bits;
      imag[loop] >>= fft_size_bits;
   }

   i1 = fft_size >> 1;
   i2 = 1;

   for (loop = 0; loop < fft_size_bits; loop++)  {
      i3 = 0;
      i4 = i1;

      for (loop1 = 0; loop1 < i2; loop1++)  {
         y = permute( i3 / i1, fft_size_bits );
         z1 =  my_cos( y * 0x10000 >> fft_size_bits );
         z2 = -my_cos( 0x4000 - (y * 0x10000 >> fft_size_bits) );

         for (loop2 = i3; loop2 < i4; loop2++)  {
            a1 = real[loop2];
            a2 = imag[loop2];

            b1 = (z1*real[loop2+i1] - z2*imag[loop2+i1])>>15;
            b2 = (z2*real[loop2+i1] + z1*imag[loop2+i1])>>15;

            real[loop2]      = (int16)(a1 + b1);
            imag[loop2]      = (int16)(a2 + b2);

            real[loop2 + i1] = (int16)(a1 - b1);
            imag[loop2 + i1] = (int16)(a2 - b2);
         }

         i3 += (i1 << 1);
         i4 += (i1 << 1);
      }

      i1 >>= 1;
      i2 <<= 1;
   }
}

#pragma arm section code