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
 *   aac_huffman_table.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  Huffman table for SBR decoding (AAC_PLUS driver)
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "media.h"
/* Syntax elements */
#define ID_SCE 0x0
#define ID_CPE 0x1
#define ID_CCE 0x2
#define ID_LFE 0x3
#define ID_DSE 0x4
#define ID_PCE 0x5
#define ID_FIL 0x6
#define ID_END 0x7

#define LEN_SE_ID 3
#define EXT_SBR_DATA     13
#define EXT_SBR_DATA_CRC 14
#define EXT_FIL            0
#define EXT_FILL_DATA      1
#define EXT_DATA_ELEMENT   2
#define EXT_DYNAMIC_RANGE 11
#define ANC_DATA           0

#define ONLY_LONG_SEQUENCE   0x0
#define LONG_START_SEQUENCE  0x1
#define EIGHT_SHORT_SEQUENCE 0x2
#define LONG_STOP_SEQUENCE   0x3

#define ZERO_HCB       0
#define FIRST_PAIR_HCB 5
#define QUAD_LEN       4
#define PAIR_LEN       2
#define NOISE_HCB      13
#define INTENSITY_HCB2 14
#define INTENSITY_HCB  15

#define MAX_WINDOW_GROUPS    8
#define MAX_SFB             51

typedef struct
{
    uint8  last_band;
    uint8  data_present;
    uint16 lag;
    uint8  lag_update;
    uint8  coef;
    uint8  long_used[MAX_SFB];
    uint8  short_used[8];
    uint8  short_lag_present[8];
    uint8  short_lag[8];
} ltp_info;

typedef struct
{
    uint8 limit;
    uint8 predictor_reset;
    uint8 predictor_reset_group_number;
    uint8 prediction_used[MAX_SFB];
} pred_info;

typedef struct
{
    uint8 number_pulse;
    uint8 pulse_start_sfb;
    uint8 pulse_offset[4];
    uint8 pulse_amp[4];
} pulse_info;

typedef struct
{
    uint8 n_filt[8];
    uint8 coef_res[8];
    uint8 length[8][4];
    uint8 order[8][4];
    uint8 direction[8][4];
    uint8 coef_compress[8][4];
    uint8 coef[8][4][32];
} tns_info;

typedef struct icStream{
    uint8      max_sfb;
    uint8      num_swb;
    uint8      num_window_groups;
    uint8      num_windows;
    uint8      window_sequence;
    uint8      window_group_length[8];
    uint8      window_shape;
    uint8      scale_factor_grouping;
    uint16     swb_offset[52];
    uint8      num_sec[8]; /* number of sections in a group */
    uint8      global_gain;
    uint8      ms_mask_present;
    uint8      noise_used;
    uint8      pulse_data_present;
    uint8      tns_data_present;
    uint8      gain_control_data_present;
    uint8      predictor_data_present;
    uint16     sect_sfb_offset[8][15*8];
    uint8      sect_cb[8][15*8];
    uint16     sect_start[8][15*8];
    uint16     sect_end[8][15*8];
    uint8      sfb_cb[8][8*15];
    int16      scale_factors[8][51];
    uint8      ms_used[MAX_WINDOW_GROUPS][MAX_SFB];
    int16      spectral_Data[1024];
    pulse_info pul;
    tns_info   tns;
    pred_info  pred;
    ltp_info   ltp;
    ltp_info   ltp2;
} iCS; /* individual channel stream */

/* 1st step table */
typedef struct
{
    uint8 offset;
    uint8 extra_bits;
} hcb;

/* 2nd step table with quadruple data */
typedef struct
{
    uint8 bits;
    int8  x;
    int8  y;
} hcb_2_pair;

typedef struct
{
    uint8 bits;
    int8  x;
    int8  y;
    int8  v;
    int8  w;
} hcb_2_quad;

/* binary search table */
typedef struct
{
    uint8 is_leaf;
    int8  data[4];
} hcb_bin_quad;

typedef struct
{
    uint8 is_leaf;
    int8  data[2];
} hcb_bin_pair;

/* table */
extern const uint8 num_swb_1024_window[];
extern const uint8 num_swb_128_window[];
extern const uint8 hcbN[];

extern const int hcb_2_quad_table_size[];
extern const int hcb_2_pair_table_size[];
extern const int hcb_bin_table_size[];

extern const uint16 *swb_offset_1024_window[];
extern const uint16 *swb_offset_128_window[];

/* "hcb_3.h" */
/* Binary search huffman table HCB_3 */
extern const hcb_bin_quad hcb3[];

/* "hcb_sf.h" */
/* Binary search huffman table HCB_SF */
extern const uint8 hcb_sf[][2];

extern const hcb *hcb_table[];
extern const hcb_2_quad *hcb_2_quad_table[];
extern const hcb_2_pair *hcb_2_pair_table[];
extern const hcb_bin_pair *hcb_bin_table[];