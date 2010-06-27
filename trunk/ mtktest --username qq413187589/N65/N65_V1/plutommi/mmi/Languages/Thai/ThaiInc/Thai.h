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
 *  Thai.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Thai header file
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef THAI_H
#define THAI_H

#include "MMI_features.h"
#include "gui_data_types.h"
#include "MMIDataType.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define THAI_CLUSTER_ILLEGAL                    -1

#define THAI_CHAR_NONE                            0x0      
#define THAI_CHAR_CONSONANT                 0x04     /* 0000 0100 */

#define THAI_CHAR_LEAD_VOWEL                0x03     /* 0000 0011 */
#define THAI_CHAR_FOLLOW_VOWEL           0x0A     /* 0000 1010 */
#define THAI_CHAR_ABOVE_VOWEL              0x0A     /* 0000 1010 */
#define THAI_CHAR_BELOW_VOWEL             0x0A     /* 0000 1010 */

#define THAI_CHAR_TONE_MARK                 0x10      /* 0001 0000 */
#define THAI_CHAR_DIGIT                            0xFF      /* 1111 1111 */ 
#define THAI_CHAR_SIGN                             0x20      /* 0010 0000 */ 
#define THAI_CHAR_CURRENCY_SYMBOL      0xFF      /* 1111 1111 */ 

#define THAI_CHAR_OFFSET(x) (x - 0x0E01)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{   
    THAI_C_KO_KAI = 0x0E01,
    THAI_C_KHO_KHAI = 0x0E02,
    THAI_C_KHO_KHUAT = 0x0E03,
    THAI_C_KHO_KHWAI = 0x0E04,
    THAI_C_KHO_KHON = 0x0E05,
    THAI_C_KHO_RAKHANG = 0x0E06,
    THAI_C_NGO_NGU = 0x0E07,
    THAI_C_CHO_CHAN = 0x0E08,
    THAI_C_CHO_CHING = 0x0E09,
    THAI_C_CHO_CHANG = 0x0E0A,
    THAI_C_SO_SO = 0x0E0B,
    THAI_C_CHO_CHOE = 0x0E0C,
    THAI_C_YO_YING = 0x0E0D,
    THAI_C_DO_CHADA = 0x0E0E,
    THAI_C_TO_PATAK = 0x0E0F,
    THAI_C_THO_THAN = 0x0E10,
    THAI_C_THO_NANGMONTHO = 0x0E11,
    THAI_C_THO_PHUTHAO = 0x0E12,
    THAI_C_NO_NEN = 0x0E13,
    THAI_C_DO_DEK = 0x0E14,
    THAI_C_TO_TAO = 0x0E15,
    THAI_C_THO_THUNG = 0x0E16,
    THAI_C_THO_THAHAN = 0x0E17,
    THAI_C_THO_THONG = 0x0E18,
    THAI_C_NO_NU = 0x0E19,
    THAI_C_BO_BAIMAI = 0x0E1A,
    THAI_C_PO_PLA = 0x0E1B,
    THAI_C_PHO_PHUNG = 0x0E1C,
    THAI_C_FO_FA = 0x0E1D,
    THAI_C_PHO_PHAN = 0x0E1E,
    THAI_C_FO_FAN = 0x0E1F,
    THAI_C_PHO_SAMPHAO = 0x0E20,
    THAI_C_MO_MA = 0x0E21,
    THAI_C_YO_YAK = 0x0E22,
    THAI_C_RO_RUA = 0x0E23,
    THAI_C_RU = 0x0E24,
    THAI_C_LO_LING = 0x0E25,
    THAI_C_LU = 0x0E26,
    THAI_C_WO_WAEN = 0x0E27,
    THAI_C_SO_SALA = 0x0E28,
    THAI_C_SO_RUSI = 0x0E29,
    THAI_C_SO_SUA = 0x0E2A,
    THAI_C_HO_HIP = 0x0E2B,
    THAI_C_LO_CHULA = 0x0E2C,
    THAI_C_O_ANG = 0x0E2D,
    THAI_C_HO_NOKHUK = 0x0E2E,
    THAI_S_PAIYANNOI = 0x0E2F,
    THAI_FV_SARA_A = 0x0E30, /* following vowels */
    THAI_AV_MAIHAN_AKAT = 0x0E31, /* above vowels */
    THAI_FV_SARA_AA = 0x0E32, /* following vowels */
    THAI_FV_SARA_AM = 0x0E33, /* following vowels */
    THAI_AV_SARA_I = 0x0E34, /* above vowels */
    THAI_AV_SARA_II = 0x0E35, /* above vowels */
    THAI_AV_SARA_UE = 0x0E36, /* above vowels */
    THAI_AV_SARA_UEE = 0x0E37, /* above vowels */
    THAI_BV_SARA_U = 0x0E38, /* above vowels */
    THAI_BV_SARA_UU = 0x0E39, /* above vowels */
    THAI_BV_PHINTHU = 0x0E3A, /* below vowels */
    THAI_SB_BAHT = 0x0E3F, /* currency symbol */
    THAI_LV_SARA_E = 0x0E40, /* leading vowels */
    THAI_LV_SARA_AE = 0x0E41, /* leading vowels */
    THAI_LV_SARA_O = 0x0E42, /* leading vowels */
    THAI_LV_SARA_AI_MAIMUAN = 0x0E43, /* leading vowels */
    THAI_LV_SARA_AI_MAIMALAI = 0x0E44, /* leading vowels */
    THAI_S_LAKKHANGYAO = 0x0E45, /* signs */
    THAI_S_MAIYAMOK = 0x0E46, /* signs repetition */
    THAI_AV_MAITAIKHU = 0x0E47, /* above vowels */
    THAI_TM_MAI_EK = 0x0E48, /* tone mark */
    THAI_TM_MAI_THO = 0x0E49, /* tone mark */
    THAI_TM_MAI_TRI = 0x0E4A, /* tone mark */
    THAI_TM_MAI_CHATTAWA = 0x0E4B, /* tone mark */
    THAI_S_THANTHAKHAT = 0x0E4C, /* sign - cancellation mark */
    THAI_S_NIKHAHIT = 0x0E4D, /* sign - final nasal */
    THAI_S_YAMAKKAN = 0x0E4E, /* sign */
    THAI_S_FONGMAN = 0x0E4F, /* sign - used as a bullet */
    THAI_D_ZERO = 0x0E50, /* Thai digital 0 */
    THAI_D_ONE = 0x0E51, /* Thai digital 1 */
    THAI_D_TWO = 0x0E52, /* Thai digital 2 */
    THAI_D_THREE = 0x0E53, /* Thai digital 3 */
    THAI_D_FOUR = 0x0E54, /* Thai digital 4 */
    THAI_D_FIVE = 0x0E55, /* Thai digital 5 */
    THAI_D_SIX = 0x0E56, /* Thai digital 6 */
    THAI_D_SEVEN = 0x0E57, /* Thai digital 7 */
    THAI_D_EIGHT = 0x0E58, /* Thai digital 8 */
    THAI_D_NINE = 0x0E59, /* Thai digital 9 */
    THAI_S_ANGKHANKHU = 0x0E5A, /* sign */
    THAI_S_KHOMUT = 0x0E5B
}Thai_characters_enum;


typedef enum
{
    THAI_CHAR_POSITION_NONE,
    THAI_CHAR_POSITION_BASELINE,
    THAI_CHAR_POSITION_BELOW,
    THAI_CHAR_POSITION_ABOVE,
    THAI_CHAR_POSITION_UPGRADEABLE
}Thai_char_position_enum;


typedef struct
{
    U32 char_type                   :16;
    U32 char_position               :16;
}Thai_character_info_table_struct;



/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/


#endif /* THAI_H */ 



