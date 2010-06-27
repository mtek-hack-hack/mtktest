/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


 /*******************************************************************************
 * Filename:
 * ---------
 *   l1_const.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer1 global constants
 *
 * Author:
 * -------
 * -------
 *
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
 * removed!
 * removed!
 *
 *
 *******************************************************************************/

/******************************************************************************
 *
 *  File:            /home/gprs/l1/generic/SCCS/s.l1_const.h
 *  -----
 *
 *  SCCS Version:    2.11
 *  -------------
 *
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of Communications Consultants Worldwide Limited (C) 2001
 *
 *  Project:
 *  --------
 *
 *  Software Unit:  Layer1 global constants.
 *  --------------
 *
 *  Description:
 *  ------------
 *
 *
 *  Modification History:
 *  ---------------------
 *  Date       Vers  Auth  Details
 *  ----       ----  ----  -------
 *  28-Mar-01  2.1   VKL   Initial version.
 *  21-May-01  2.2   VKL   added ifdef WIN32 to disable warnings and define
 *                          _strdup
 *                         added comments
 *                         changed to multi band for testing (GSM+DCS)
 *                         added USF_FREE and USF_INVALID
 *  15-Jul-01  2.3   VKL   Added TimingAdvance_INVALID
 *                         Added frequence band and ARFCN range macros
 *                         Changed ARFCN macros for proper multiband support
 *  02-Sep-01  2.4   VKL   Add constants Power_INVALID, TX_POWER_MAX and TX_POWER_MIN
 *  12-Sep-01  2.5   VKL   Add #define MULTIBAND_SUPPORT, change values of Power_INVALID,
 *                         Power_EQUNDERFLOW and Power_EQOVERFLOW,remove AGC constants
 *  13-Sep-01  2.5   SGB   Remove #def MULTIBAND_SUPPORT - compiler option
 *  26-Sep-01  2.6   VKL   Added TimingAdvance_SAME_AS_BEFORE
 *  28-Sep-01  2.7   VKL   Added TFI_INVALID
 *  03-Oct-01  2.8   VKL   Change values of Power_INVALID, Power_EQUNDERFLOW
 *                         and Power_EQOVERFLOW to fit within byte
 *  11-Oct-01  2.9    SY      L1_AVAILABLE_BANDS to support EGSM and Change Power_MAX
 *  26-Oct-01  2.10  VKL   Add POWER_IS_INVALID macro
 *                         Change value of L1_SURROUND_MIN_EBIT_SB_TCH
 *  09-Oct-01  2.11  VKL   Change L1_SURROUND_MAX_CELLS from 32 to 65
 *
 *****************************************************************************/

#ifndef l1_generic_l1_const_h
#define l1_generic_l1_const_h

#include "mph_cnst.h"
#include "l1d_cid.h"


/* --- global flags --------------------------------------------------------- */
#ifndef __MTK_TARGET__
#define SIMULATION_SUPPORT  1
#define TRACING_SUPPORT     1
#define SCRIPTING_SUPPORT   1
#define HARDWARE_SIMULATION 1
#else
#define SIMULATION_SUPPORT  0
#define TRACING_SUPPORT     0
#define SCRIPTING_SUPPORT   0
#define HARDWARE_SIMULATION 0
#endif

/* --- ARFCN --------------------------------------------------------------- */

#define ARFCN_INVALID 32767


/* --- transmit power of this mobile --------------------------------------- */

#define TX_POWER_MAX 39
#define TX_POWER_MIN 0


/* --- power (in dB) ------------------------------------------------------- */

#define REPORT_RESOLUTION_BITS   2 /* 0.25 dB resolution */ /* !!important: please update the copy in m12194.c */
#define RSSI_RESOLUTION_BITS     3 /* 0.125 dB resolution */

#if REPORT_RESOLUTION_BITS > RSSI_RESOLUTION_BITS
#error "RSSI_RESOLUTION_BITS should be greater or equal to REPORT_RESOLUTION_BITS"
#endif

#define RSSI_FACTOR              (1<<RSSI_RESOLUTION_BITS)  /* !!important: please update the copy in m12194.c */
#define RSSI_MAGIC_VALUE         6550
#define RSSI_MAGIC_VALUE_SC      110000*3
#define RSSI_MAGIC_SAMPLE_NUM    6

#define Power_MIN         (-111*RSSI_FACTOR)
#define Power_MAX         (-10*RSSI_FACTOR)

#define Power_INVALID     1
#define Power_EQUNDERFLOW 2
#define Power_EQOVERFLOW  3

#define POWER_IS_INVALID(power) ((power)>=0)

/* --- frame numbers ------------------------------------------------------- */

#define HYPERFRAMES (26L*51L*2048L)

/* ------------------------------------------------------------------------- */

#define TFI_INVALID -1

/* ------------------------------------------------------------------------- */

#define L1_SURROUND_MAX_CELLS 33
#define L1_SURROUND_MIN_EBIT_SB_TCH 8125 /* window opens in middle of timeslot 6 */

/* -------------------------- threshold for AGC and AFC -------------------- */
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION

   #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION

      #define SNR_THRESHOLD_AGC_GMSK_SAIC_ON    (28)   /* Threshold of TSC_SINR after SAIC */
      #define SNR_THRESHOLD_AGC_GMSK_SAIC_OFF   (6)

      #define SNR_THRESHOLD_AFC_GMSK_SAIC_ON    (28)   /* Threshold of TSC_SINR  after SAIC */
      #define SNR_THRESHOLD_AFC_GMSK_SAIC_OFF   (6)
      
      #define MLFOE_FOE_SNR_THR                 (40)
      #define MLFOE_FOE_CVALUE_THR              (4)
      
      #if IS_EGPRS
      /*EGPRS*/#define SNR_THRESHOLD_AGC_EPSK            (13)   /* Threshold of C value */
      /*EGPRS*/#define SNR_THRESHOLD_AFC_EPSK            (13)   /* Threshold of C value */      
      #endif
      
   #else     
      #define SNR_THRESHOLD         4       /* Threshold of WSNR */
      #define SNR_THRESHOLD_DTX     6      
   #endif /* End of "IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION" */
   
#else 

   #define SNR_THRESHOLD         20
   #define SNR_THRESHOLD_DTX     12
   
#endif /*End of "IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION"*/

/* --- C Value-------------------------------------------------------------- */

#define C_VALUE_RESOLUTION_BITS  16

#if RSSI_RESOLUTION_BITS > C_VALUE_RESOLUTION_BITS
#error "C_VALUE_RESOLUTION_BITS should be greater or equal to RSSI_RESOLUTION_BITS"
#endif

#endif


