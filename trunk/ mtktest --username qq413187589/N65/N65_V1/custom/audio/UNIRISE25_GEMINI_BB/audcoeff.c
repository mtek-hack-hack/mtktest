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
 * audcoeff.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   Default FIR Coefficients Table
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "l1audio.h"
#include "audcoeff_default.h"

const unsigned char  L1SP_MICROPHONE1  = L1SP_LNA_0;
const unsigned char  L1SP_MICROPHONE2  = L1SP_LNA_1;

const unsigned char  L1SP_SPEAKER1     = L1SP_BUFFER_0;
const unsigned char  L1SP_SPEAKER2     = L1SP_BUFFER_ST;
const unsigned char  L1SP_LOUD_SPEAKER = L1SP_BUFFER_ST_M|L1SP_BUFFER_EXT;

const signed short Speech_Input_FIR_Coeff[6][45] = {
   { /* 0: Input FIR coefficients for 2G/3G Normal mode */
      -99,   259,  -684,    97,  -552,
       13,   112,   -14,   -51,  -549,
     -458,  -545,  -217, -1091,   334,
     -606, -1150,  1028, -4535,  2274,
    -7032, -1165, 31129, -1165, -7032,
     2274, -4535,  1028, -1150,  -606,
      334, -1091,  -217,  -545,  -458,
     -549,   -51,   -14,   112,    13,
     -552,    97,  -684,   259,   -99
   },
   { /* 1: Input FIR coefficients for 2G/3G/VoIP Headset mode */
      32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
          0,     0,     0,     0,     0,
          0,     0,     0,     0,     0,
          0,     0,     0,     0,     0
   },
   { /* 2: Input FIR coefficients for 2G/3G Handfree mode */
  -99,   259,  -684,    97,  -552,
    13,   112,   -14,   -51,  -549,
  -458,  -545,  -217, -1091,   334,
  -606, -1150,  1028, -4535,  2274,
 -7032, -1165, 31129, -1165, -7032,
  2274, -4535,  1028, -1150,  -606,
   334, -1091,  -217,  -545,  -458,
  -549,   -51,   -14,   112,    13,
  -552,    97,  -684,   259,   -99
   },
   { /* 3: Input FIR coefficients for 2G/3G/VoIP BT mode */
    32767,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0 
   },
   { /* 4: Input FIR coefficients for VoIP Normal mode */
   -99,   259,  -684,    97,  -552,
    13,   112,   -14,   -51,  -549,
  -458,  -545,  -217, -1091,   334,
  -606, -1150,  1028, -4535,  2274,
 -7032, -1165, 31129, -1165, -7032,
  2274, -4535,  1028, -1150,  -606,
   334, -1091,  -217,  -545,  -458,
  -549,   -51,   -14,   112,    13,
  -552,    97,  -684,   259,   -99
   },
   { /* 5: Input FIR coefficients for VoIP Handfree mode */
   -99,   259,  -684,    97,  -552,
    13,   112,   -14,   -51,  -549,
  -458,  -545,  -217, -1091,   334,
  -606, -1150,  1028, -4535,  2274,
 -7032, -1165, 31129, -1165, -7032,
  2274, -4535,  1028, -1150,  -606,
   334, -1091,  -217,  -545,  -458,
  -549,   -51,   -14,   112,    13,
  -552,    97,  -684,   259,   -99
   }
};
const signed short Speech_Output_FIR_Coeff[6][45] = {
   { /* 0: Output FIR coefficients for 2G/3G Normal mode */
  -672,  1022, -1255,  1099,  -926,
    38,   386, -1619,  1790, -2685,
  1752, -2100,   424,   345, -3048,
  3143, -6490,  7493, -6263,  6486,
 -1589,-12952, 31129,-12952, -1589,
  6486, -6263,  7493, -6490,  3143,
 -3048,   345,   424, -2100,  1752,
 -2685,  1790, -1619,   386,    38,
  -926,  1099, -1255,  1022,  -672
   },
   { /* 1: Output FIR coefficients for 2G/3G/VoIP Headset mode */
 32767,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0 
   },
   { /* 2: Output FIR coefficients for 2G/3G Handfree mode */
    32767,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0 
   },
   { /* 3: Output FIR coefficients for 2G/3G/VoIP BT mode */
    32767,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0 
   },
   { /* 4: Output FIR coefficients for VoIP Normal mode */
  -672,  1022, -1255,  1099,  -926,
    38,   386, -1619,  1790, -2685,
  1752, -2100,   424,   345, -3048,
  3143, -6490,  7493, -6263,  6486,
 -1589,-12952, 31129,-12952, -1589,
  6486, -6263,  7493, -6490,  3143,
 -3048,   345,   424, -2100,  1752,
 -2685,  1790, -1619,   386,    38,
  -926,  1099, -1255,  1022,  -672
   },
   { /* 5: Output FIR coefficients for VoIP Handfree mode */
 32767,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,
        0,     0,     0,     0,     0 
   }
};
   
const unsigned short Ext_op_on_delay   = 0;     /* count in frames, 1 frame = 4.615ms */
const unsigned short Ext_op_off_delay  = 0;     /* count in frames, 1 frame = 4.615ms */

const unsigned short   DG_DL_Speech    = 0x1000;
const unsigned short   DG_Microphone   = 0x1400;
const unsigned short   DG_DAF          = 32767;
const unsigned short   DG_MIDI         = 304;
const unsigned short   DG_IMY          = 3072;

/*
 * AGC Configuration Parameter
 * Refer to audcoeff_default.h
 */
const unsigned char AGC_Mode_LoudSpk = DEFAULT_AGC_MODE_LOUDSPK;  
const unsigned char AGC_Mode_Headset = DEFAULT_AGC_MODE_HEADSET;  

/*
 * The Bluetooth DAI Hardware COnfiguration Parameter
 * Refer to audcoeff_default.h
 */
const unsigned char Bluetooth_Sync_Type = DEFAULT_BLUETOOTH_SYNC_TYPE;
const unsigned char Bluetooth_Sync_Length = DEFAULT_BLUETOOTH_SYNC_LENGTH;

/*
 * 3D Surround Loudspeaker Mode Customization Parameter.
 * Details about these three variables are illustrated in Audio Post-Processing Interface doc.
 */
#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
const int D_Distance = DEFAULT_D_DISTANCE;
const int D_Loudspeaker = DEFAULT_D_LOUDSPEAKER;
const int SurroundLevelLoudspeaker = DEFAULT_SURROUNDLEVELLOUDSPEAKER;
#endif

