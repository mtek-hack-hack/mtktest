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
 * mph_types.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Common constant and enum definitions for MediaTek GSM/GPRS software
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _MPH_TYPES_H
#define _MPH_TYPES_H
/*
 * Definitions for GSM related types
 */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included before mph_types.h"
#endif

typedef kal_int16  ARFCN;
typedef kal_int8   BSIC;
typedef kal_int8   TSC;
typedef kal_int8   TimeSlot;    /* Timeslot Number */
typedef kal_uint8  TimeSlotMask;  /* Timeslot Mask */
typedef kal_int8   SubChannel;
typedef kal_int16  Power; /* in dBm */
typedef kal_uint8  RxlevPower;   /* in Rxlev */
typedef kal_uint8  TimingAdvance;
typedef kal_int32  FrameNumber;
typedef kal_uint16 RAChData;

typedef kal_int8   TFI;
typedef kal_int8   PowerControlLevel;
typedef kal_int16  PowerSum;
typedef kal_uint8  BlockData;
typedef kal_int8   LoopMode;
typedef kal_int8   USF;

typedef enum
{
   BTSPowerControlModeNoPowerControl,
   BTSPowerControlModeA,
   BTSPowerControlModeB
} BTSPowerControlMode;

typedef enum
{
   CodingSchemeNone,
   CodingSchemeCS1,
   CodingSchemeCS2,
   CodingSchemeCS3,
   CodingSchemeCS4,
  #ifdef __EGPRS_MODE__
   CodingSchemeMCS1,
   CodingSchemeMCS2,
   CodingSchemeMCS3,
   CodingSchemeMCS4,
   CodingSchemeMCS5,
   CodingSchemeMCS6,
   CodingSchemeMCS7,
   CodingSchemeMCS8,
   CodingSchemeMCS9, 
  #endif
   CodingSchemePRACh8,
   CodingSchemePRACh11
} CodingScheme;

typedef enum
{
   PuncturingSchemeNone,
   PuncturingScheme1,
   PuncturingScheme2,
   PuncturingScheme3
} PuncturingScheme;


typedef enum
{
   PBCChModeNone,
   PBCChModeAll,
   PBCChModePSI1Only,
   PBCChModeHROnly,
   PBCChModeLROnly,
   PBCChModePSI1HR,
   PBCChModePSI1LR,
   PBCChModeHRLR,
   PBCChModeB0OnTC0Only
} PBCChMode;

/*
@enum LogChannel | DCh channel type.
*/
typedef enum
{
   LogTChF,   /* @emem Full rate trafic channel */
   LogTChH,   /* @emem Half rate trafic channel*/
   LogSDCCh4, /* @emem Standalone dedicated control channel combined */
   LogSDCCh8  /* @emem Standalone dedicated control channel uncombined */
} LogChannel;

/*
@enum TChMode | TCh channel mode.
*/
typedef enum
{
   TChModeNone,       /* @emem Undefined channel mode */
   TChModeFSig,       /* @emem Full rate singnalling only */
   TChModeFS,         /* @emem Full rate speech */
   TChModeF144,       /* @emem Full rate data 14400 */
   TChModeF96,        /* @emem Full rate data 9600 */
   TChModeF48,        /* @emem Full rate data 4800 */
   TChModeF24,        /* @emem Full rate data 2400 */

/* TODO maybe get rid of these because they are redundant */
   TChModeHSig,       /* @emem Half rate singnalling only */
   TChModeHS,         /* @emem Half rate speech */
   TChModeH48,        /* @emem Half rate data 4800 */
   TChModeH24,        /* @emem Half rate data 2400 */
   TChModeEFS,        /* Enhanced full rate speech */

/* AMR speech modes used by RR, L1A and L1C. */
   TChModeAFS,        /* @emem AMR Full rate speech */
   TChModeAHS,        /* @emem AMR Half rate speech */

/* AMR speech modes used by L1D. */   
   TChModeAFS1220,    /* @emem AMR Full rate speech 12.2k */
   TChModeAFS1020,    /* @emem AMR Full rate speech 10.2k */
   TChModeAFS795,     /* @emem AMR Full rate speech 7.95k */
   TChModeAFS740,     /* @emem AMR Full rate speech 7.4k  */
   TChModeAFS670,     /* @emem AMR Full rate speech 6.7k  */
   TChModeAFS590,     /* @emem AMR Full rate speech 5.9k  */
   TChModeAFS515,     /* @emem AMR Full rate speech 5.15k */
   TChModeAFS475,     /* @emem AMR Full rate speech 4.75k */

   TChModeAHS795,     /* @emem AMR Half rate speech 7.95k */
   TChModeAHS740,     /* @emem AMR Half rate speech 7.4k  */
   TChModeAHS670,     /* @emem AMR Half rate speech 6.7k  */
   TChModeAHS590,     /* @emem AMR Half rate speech 5.9k  */
   TChModeAHS515,     /* @emem AMR Half rate speech 5.15k */
   TChModeAHS475      /* @emem AMR Half rate speech 4.75k */
} TChMode;

#ifdef __EGPRS_MODE__
typedef struct
{
  CodingScheme   codingScheme;
   BlockData*        header;
  BlockData*     blockData;
   BlockData*        blockData2;
   PuncturingScheme  puncturingScheme_1;	// for the 1st RLC block in the radio block, no use in CS1~4
   PuncturingScheme  puncturingScheme_2;	// for the 2nd RLC block in the radio block, no use in CS1~4
} PrePacketBlockSpec;
#else
typedef struct
{
  CodingScheme   codingScheme;
  BlockData*     blockData;
} PrePacketBlockSpec;
#endif

typedef struct
{
   PrePacketBlockSpec  block[4];
} PrePacketUplinkSpec;

/* elly20070709, Add a structure for INJECT message */
typedef struct
{
   kal_bool l1_no_service_test;
} L1InjectMessage;


#endif /* _MPH_TYPES_H */

