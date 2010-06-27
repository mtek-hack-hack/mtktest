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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * audcoeff_default.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   The default value of audio coefficients
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef AUDCOEFF_COMMON_DOT_H
#define AUDCOEFF_COMMON_DOT_H

/*
 * AGC Configuration Parameter
 */
#define DEFAULT_AGC_MODE_LOUDSPK                  4
/* When the sound is output by the loudspeaker, the AGC mode will be applied as assiged in AGC_Mode_LoudSpk. 
   We recommend that set this value as 1, 2, 3 or 4 to enhance the loudness of sound output by loudspeaker.
   */

#define DEFAULT_AGC_MODE_HEADSET                  0
/* AGC_Mode_Headset: When the sound is output by the headset, the AGC mode will
   be applied as assiged in AGC_Mode_Headset.
   We recommend that set this value 0 or 1 to introduce no or less ditortion to Audio.
   */
/* AGC Mode Description
		0: The AGC is turned off.
		1: Non-Aggressive AGC. 
    2: Mid-Low aggressive AGC. 
    3: Mid-High aggressive AGC. 
    4: Most aggressive AGC. 
   */

/*
 * The Bluetooth DAI Hardware COnfiguration Parameter
 */
#define DEFAULT_BLUETOOTH_SYNC_TYPE               0
#define DEFAULT_BLUETOOTH_SYNC_LENGTH             1

/*
 * Speech enhancement parameter
 * AUX1 : BT_CARKIT (from W0643)
 * AUX2 : undefined
 * AUX3 : undefined
 */
#if defined(MT6226) || defined(MT6226D) || defined(MT6227) || defined(MT6227D) || defined(MT6226M) || defined(MT6228) || defined(MT6229_S00) || defined(MT6230_S00) || defined(MT6229_S01) || defined(MT6230_S01) || defined(MT6225) || defined(MT6268T) || defined(MT6223) || defined(MT6223P) || defined(MT6235) || defined(MT6238)

#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
    256,   221,  10756,     0,   853,     0,   400,     0 \
}

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
    0,   221,  10756,     0,   853,     0,   400,     0 \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
    0,   221,  10756,     0,   853,     0,   400,     0 \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
  128,   224,   5128,     0,   374,     0,   400,     0 \
}

#define DEFAULT_SPEECH_AUX1_MODE_PARA \
{ \
  128,   224,   5128,     0,   374,     0,   400,     0 \
}

#elif defined(MT6229_S02) || defined(MT6230_S02)
// KH: Must synchronize with DSP_SUPPORT_DRC in \mcu\l1audio\sp_enhance.c (asked by Pancho)

#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
    0,   221,  10756,     0,   853,     0,   400,     0 \
}

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
    0,   221,  10756,     0,   853,     0,   400,     0 \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
    0,   221,  10756,     0,   853,     0,   400,     0 \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
  128,   224,   5128,     0,   374,     0,   400,     0 \
}

#define DEFAULT_SPEECH_AUX1_MODE_PARA \
{ \
  128,   224,   5128,     0,   374,     0,   400,     0 \
}

#elif defined(MT6218) || defined(MT6218A) || defined(MT6218B) || defined(MT6219) || defined(MT6217)

#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
 16384,     0,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_AUX1_MODE_PARA \
{ \
 16384,     0,     0,     0,     0,     0,     0,     0 \
}

#elif defined(FPGA) || defined(MT6208) || defined(MT6205) || defined(MT6205A) || defined(MT6205B)

#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
0x1002,0x1000,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
0x1002,0x1000,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
0x1002,0x1000,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
0x0303,0x0100,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_AUX1_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

#else
#error New chip needs new default value of audio coefficients, or check l1d_cid.h for the compile option of new chip
#endif

#define DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_AUX2_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

#define DEFAULT_SPEECH_AUX3_MODE_PARA \
{ \
     0,     0,     0,     0,     0,     0,     0,     0 \
}

// 3D Surround effect variable default value
#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
#define DEFAULT_D_DISTANCE  			55
#define DEFAULT_D_LOUDSPEAKER  			5
#define DEFAULT_SURROUNDLEVELLOUDSPEAKER  	32
#endif

#if defined(AUD_REVERB)
/*
 * Audio Post Process Parameter - Reverb Sound Effect
 */
#define DEFAULT_TABLE_Reverb_CONCERT \
{ \
  1204,  1205,  1297,  1325,  1467,  1488,  1862,  1882, \
  1891,  1994,  2473,  2474,  1214,  1215,  1238,  1562, \
  1616,  1675,  1770,  1780,  1794,  1873,  2064,  2195, \
  1088,  1099,  1111,  1113,  1115,  1125,  1145,  1388, \
  1450,  1463,  1480,  2713,  1160,  1364,  1365,  1374, \
  1446,  1508,  1628,  1631,  1762,  1767,  1978,  2932, \
 13425,  3085, -3055,  3362, -4236,  1205,  1488,  2693, \
 10240, 10240, -3200,  1600,  5120,  8400,  8400,  5120, \
  1600,     0 \
}

#define DEFAULT_TABLE_Reverb_SHOWER \
{ \
   325,   373,   383,   385,   393,   394,   500,   747, \
   851,  1103,  1113,  1382,   313,   315,   437,   529, \
   535,   668,   687,   694,   820,   825,  1234,  1463, \
   298,   311,   377,   380,   392,   766,   788,  1005, \
  1195,  1242,  1251,  1257,   289,   324,   325,   379, \
   505,   617,   773,   774,   892,  1018,  1802,  1826, \
  5448,  4771, -4466,  4579, -4690,   383,   500,   883, \
  9216,  9216, -2592, -3589,  -419, 18057, 18057,  -419, \
 -3589,     0 \
}

#define DEFAULT_TABLE_Reverb_CHURCH \
{ \
  1879,  1909,  1910,  1925,  1962,  2453,  2459,  2473, \
  2474,  2517,  2518,  2935,  1872,  2070,  2071,  2076, \
  2140,  2178,  2688,  2851,  2854,  2970,  2971,  2972, \
  1870,  2045,  2138,  2148,  2154,  2191,  2201,  2231, \
  2233,  2294,  2433,  2468,  1654,  1920,  1921,  1937, \
  2105,  2226,  2799,  2800,  2817,  2847,  2848,  2850, \
 31523,   916,  -947,   568,  -654,   400,   500,   900, \
  8192,  8192, -2048,  1600,  5120,  8400,  8400,  5120, \
  1600,     0 \
}

#define DEFAULT_TABLE_Reverb_SMALLROOM \
{ \
   494,   540,   591,   609,   613,   672,   677,   963, \
   964,   966,   993,  1016,   331,   332,   372,   373, \
   382,   383,   446,   527,   630,   631,   762,   763, \
   331,   332,   333,   445,   446,   447,   630,   631, \
   632,   930,   931,  1016,   348,   371,   372,   373, \
   382,   383,   384,   526,   527,   762,   763,   764, \
 19971,   817, -1756,  1523, -1379,   591,   677,  1268, \
  9216,  9216, -2592,  1600,  5120,  8400,  8400,  5120, \
  1600,     0 \
}

#define DEFAULT_TABLE_Reverb_OPERA \
{ \
   503,   512,  1030,  1034,  1807,  1830,  1947,  1987, \
  2179,  2461,  2473,  2368,   522,   553,  1136,  1205, \
  1757,  1783,  1785,  1950,  2267,  2341,  2804,  2684, \
   626,   630,  1167,  1461,  1968,  2115,  2237,  2297, \
  2299,  2632,  2820,  2637,   557,   595,  1107,  1134, \
  1659,  1682,  1799,  1972,  2023,  2098,  2277,  1713, \
 17278,  3137,  -3120, 2929, -3155,  1030,  1947,  2977, \
 10240, 10240,  -3200, 1600,  5120,  8400,  8400,  5120, \
  1600,     0 \
}

#define DEFAULT_TABLE_Reverb_BATHROOM \
{ \
   446,   544,   627,   631,   784,   785,  1028,  1100, \
  1272,  1404,  1448,  1449,   437,   480,   529,   619, \
   812,   860,  1051,  1102,  1211,  1840,  2250,  2413, \
   448,   546,   601,   602,   618,   654,   778,  1130, \
  1296,  1346,  1410,  2788,   446,   488,   493,   518, \
   519,   693,   850,   927,  1088,  1822,  1954,  2592, \
 15974,  2483, -2544,  2658, -2462,   631,   619,   602, \
  5898,  5898,  5898, -3589,  -419, 18057, 18057,  -419, \
 -3589,     0 \
}

#endif // ... AUD_REVERB

#endif // ... AUDCOEFF_COMMON_DOT_H
