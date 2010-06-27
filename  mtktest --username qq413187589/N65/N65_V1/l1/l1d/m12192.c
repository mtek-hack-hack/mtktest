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
 *	m12192.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup Gain
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/


/*===============================================================================*/
/*                                                                               */
/* int L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain,          */
/*                            long *gain_setting )                               */
/*                                                                               */
/*===============================================================================*/
/*                                                                               */
/* rf_band      : RF Band. the value is 0 (GSM) or 1 (DCS)                       */
/* arfcn        : ARFCN number                                                   */
/* request_gain : Request Gain. the unit is 0.125 dBm                            */
/* *gain_setting: the Setting Value for tranceiver gain.                         */
/* return       : returned Actually Setting Gain. the unit is 0.125 dBm.         */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/* This program evaluates the AGC setting value by the request gain for Bright2. */
/* If the AGC component is changed, this file shall be modified by vendor        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "m12190.h"

/*================================================================================================*/

#define  ROUNDINT( n )                    ((int)(((n)>=0)?((n)+0.5):((n)-0.5)))
#define  GC_B                             ((GAIN_STEP)*(PWRRES))
#define  GC_A( bitno, gain  )             (short)ROUNDINT(((1+2*(bitno))*GC_B/2-(gain)*(PWRRES)))
#define  GBOUND( gain1, gain2 )           (short)ROUNDINT((((gain1)+(gain2))/2.0*(PWRRES)))
#define  BIT_NO( reqgain, A, B )          (((reqgain)+(A))/(B))
#define  REAL_GAIN( bitno, A, B )         ((bitno)*(B)-(A)+(B)/2)

/*================================================================================================*/

#if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*=========================================================================================*/

#if  IS_RF_BRIGHT4
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*===============================================================================================*/

#if  IS_RF_BRIGHT5P
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*===============================================================================================*/

#if  IS_RF_AERO
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if  IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/*AERO*/ #if  IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/           #if IS_GSM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/           #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*=========================================================================================*/

#if  IS_RF_AERO1PLUS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if  IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/*AERO1+*/ #if  IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/           #if IS_GSM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/           #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*=========================================================================================*/

#if  IS_RF_POLARIS1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*=========================================================================================*/

#if  0 /* AMR use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/    #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if IS_RF_SKY74117 /* GPRS use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/    #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74117*/    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*================================================================================================*/

#if IS_RF_SKY74400
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74400*/    #if IS_GPRS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74400*/    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*================================================================================================*/

#if  IS_RF_MT6119
/*MT6119*/
/*MT6119*/ #define  GAIN_STEP               2
/*MT6119*/
/*MT6119*/ #define  RF_GSM_MAXGAIN         (  68.0*(PWRRES))
/*MT6119*/ #define  RF_GSM_MINGAIN         ( -30.0*(PWRRES))
/*MT6119*/ #define  RF_DCS_MAXGAIN         (  68.0*(PWRRES))
/*MT6119*/ #define  RF_DCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6119*/ #define  RF_PCS_MAXGAIN         (  68.0*(PWRRES))
/*MT6119*/ #define  RF_PCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6119*/
/*MT6119*/ /* GSM900....................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6119*/ {  {  GBOUND(-10.0,-12.0 ), 0x0681A, GC_A(  0,-10.0 ) },
/*MT6119*/    {  GBOUND(-30.0,-30.0 ), 0x06812, GC_A(  9,-30.0 ) },
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /* DCS1800...................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6119*/ {  {  GBOUND(-10.0,-12.0 ), 0x0701A, GC_A(  0,-10.0 ) },
/*MT6119*/    {  GBOUND(-30.0,-30.0 ), 0x07012, GC_A(  9,-30.0 ) },
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /* PCS1900...................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6119*/ {  {  GBOUND(-10.0,-12.0 ), 0x0781A, GC_A(  0,-10.0 ) },
/*MT6119*/    {  GBOUND(-30.0,-30.0 ), 0x07812, GC_A(  9,-30.0 ) },
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /*...........................................................................*/
/*MT6119*/
/*MT6119*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6119*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*MT6119*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*MT6119*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*MT6119*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*MT6119*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6119*/ {  0,                                              /*#FrequencyBand400  */
/*MT6119*/    0,                                              /*#FrequencyBand850  */
/*MT6119*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6119*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6119*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6119*/
/*MT6119*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6119*/ {  int   max_gain, min_gain, real_gain;
/*MT6119*/    const int*    d32ptr;
/*MT6119*/    const sL1DAGCDATA*  agcptr;
/*MT6119*/    long  setting;
/*MT6119*/    int   bit_no;
/*MT6119*/
/*MT6119*/    /* evaluate the range of available gain */
/*MT6119*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6119*/    max_gain = *d32ptr++;
/*MT6119*/    min_gain = *d32ptr;
/*MT6119*/
/*MT6119*/    /* clipping the request gain to the avialable gain */
/*MT6119*/    if( request_gain>=max_gain )
/*MT6119*/    {  request_gain = max_gain;  }
/*MT6119*/    else  if( request_gain<=min_gain )
/*MT6119*/    {  request_gain = min_gain;  }
/*MT6119*/
/*MT6119*/    /* evaluate the real gain setting */
/*MT6119*/    agcptr = AGC_TABLE[rf_band];
/*MT6119*/    if( request_gain < agcptr->pos_gain )
/*MT6119*/    {  agcptr++;
/*MT6119*/    }
/*MT6119*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6119*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6119*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6119*/    }
/*MT6119*/
/*MT6119*/    *gain_setting = setting;
/*MT6119*/    return( real_gain );
/*MT6119*/ }
#endif

/*===============================================================================================*/

#if  IS_RF_MT6119C
/*MT6119C*/
/*MT6119C*/ #define  GAIN_STEP               2
/*MT6119C*/
/*MT6119C*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6119C*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6119C*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6119C*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6119C*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6119C*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6119C*/
/*MT6119C*/ /* GSM900....................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6119C*/ {  {  GBOUND( 34.0, 32.0 ), 0x12681A, GC_A( 11, 34.0 ) },
/*MT6119C*/    {  GBOUND(-6.0,-8.0 ), 0x00681A, GC_A(  32,-6.0 ) },
/*MT6119C*/    {  GBOUND(-26.0,-26.0 ), 0x006812, GC_A(  0,-26.0 ) },
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /* DCS1800...................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6119C*/ {  {  GBOUND( 32.0, 30.0 ), 0x12701A, GC_A( 11, 32.0 ) },
/*MT6119C*/    {  GBOUND(-8.0,-10.0 ), 0x00701A, GC_A(  32,-8.0 ) },
/*MT6119C*/    {  GBOUND(-28.0,-28.0 ), 0x007012, GC_A(  0,-28.0 ) },
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /* PCS1900...................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6119C*/ {  {  GBOUND( 32.0, 30.0 ), 0x12781A, GC_A( 11, 32.0 ) },
/*MT6119C*/    {  GBOUND(-8.0,-10.0 ), 0x00781A, GC_A(  32,-8.0 ) },
/*MT6119C*/    {  GBOUND(-28.0,-28.0 ), 0x007812, GC_A(  0,-28.0 ) },
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /*...........................................................................*/
/*MT6119C*/
/*MT6119C*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6119C*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*MT6119C*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*MT6119C*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*MT6119C*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*MT6119C*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6119C*/ {  0,                                              /*#FrequencyBand400  */
/*MT6119C*/    0,                                              /*#FrequencyBand850  */
/*MT6119C*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6119C*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6119C*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6119C*/
/*MT6119C*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6119C*/ {  int   max_gain, min_gain, real_gain;
/*MT6119C*/    const int*    d32ptr;
/*MT6119C*/    const sL1DAGCDATA*  agcptr;
/*MT6119C*/    long  setting;
/*MT6119C*/    int   bit_no;
/*MT6119C*/
/*MT6119C*/    /* evaluate the range of available gain */
/*MT6119C*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6119C*/    max_gain = *d32ptr++;
/*MT6119C*/    min_gain = *d32ptr;
/*MT6119C*/
/*MT6119C*/    /* clipping the request gain to the avialable gain */
/*MT6119C*/    if( request_gain>=max_gain )
/*MT6119C*/    {  request_gain = max_gain;  }
/*MT6119C*/    else  if( request_gain<=min_gain )
/*MT6119C*/    {  request_gain = min_gain;  }
/*MT6119C*/
/*MT6119C*/    /* evaluate the real gain setting */
/*MT6119C*/    agcptr = AGC_TABLE[rf_band];
/*MT6119C*/    if( request_gain < agcptr->pos_gain )
/*MT6119C*/    {  agcptr++;
/*MT6119C*/       if( request_gain < agcptr->pos_gain )
/*MT6119C*/       {  agcptr++;  }
/*MT6119C*/    }
/*MT6119C*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6119C*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6119C*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6119C*/    }
/*MT6119C*/
/*MT6119C*/    *gain_setting = setting;
/*MT6119C*/    return( real_gain );
/*MT6119C*/ }
#endif

/*===============================================================================================*/

#if  IS_RF_MT6129A
/*MT6129A*/
/*MT6129A*/ #define  GAIN_STEP               2
/*MT6129A*/
/*MT6129A*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129A*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129A*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129A*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129A*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129A*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129A*/
/*MT6129A*/ /* GSM900....................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129A*/ {  {  GBOUND( 18.0, 16.0 ), 0x126812, GC_A(  3, 18.0 ) },
/*MT6129A*/    {  GBOUND(-6.0,-8.0 ), 0x006812, GC_A(  32,-6.0 ) },
/*MT6129A*/    {  GBOUND(-26.0,-26.0 ), 0x006802, GC_A(  0,-26.0 ) },
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /* DCS1800...................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129A*/ {  {  GBOUND( 16.0, 14.0 ), 0x127012, GC_A(  3, 16.0 ) },
/*MT6129A*/    {  GBOUND(-8.0,-10.0 ), 0x007012, GC_A(  32,-8.0 ) },
/*MT6129A*/    {  GBOUND(-28.0,-28.0 ), 0x007002, GC_A(  0,-28.0 ) },
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /* PCS1900...................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129A*/ {  {  GBOUND( 16.0, 14.0 ), 0x127812, GC_A(  3, 16.0 ) },
/*MT6129A*/    {  GBOUND(-8.0,-10.0 ), 0x007812, GC_A(  32,-8.0 ) },
/*MT6129A*/    {  GBOUND(-28.0,-28.0 ), 0x007802, GC_A(  0,-28.0 ) },
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /*...........................................................................*/
/*MT6129A*/
/*MT6129A*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129A*/ {  {                   0,                   0 },   /*#FrequencyBand400  */
/*MT6129A*/    {                   0,                   0 },   /*#FrequencyBand850  */
/*MT6129A*/    { (int)RF_GSM_MAXGAIN, (int)RF_GSM_MINGAIN },   /* FrequencyBand900  */
/*MT6129A*/    { (int)RF_DCS_MAXGAIN, (int)RF_DCS_MINGAIN },   /* FrequencyBand1800 */
/*MT6129A*/    { (int)RF_PCS_MAXGAIN, (int)RF_PCS_MINGAIN },   /* FrequencyBand1900 */
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129A*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129A*/    0,                                              /*#FrequencyBand850  */
/*MT6129A*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129A*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129A*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129A*/
/*MT6129A*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129A*/ {  int   max_gain, min_gain, real_gain;
/*MT6129A*/    const int*    d32ptr;
/*MT6129A*/    const sL1DAGCDATA*  agcptr;
/*MT6129A*/    long  setting;
/*MT6129A*/    int   bit_no;
/*MT6129A*/
/*MT6129A*/    /* evaluate the range of available gain */
/*MT6129A*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129A*/    max_gain = *d32ptr++;
/*MT6129A*/    min_gain = *d32ptr;
/*MT6129A*/
/*MT6129A*/    /* clipping the request gain to the avialable gain */
/*MT6129A*/    if( request_gain>=max_gain )
/*MT6129A*/    {  request_gain = max_gain;  }
/*MT6129A*/    else  if( request_gain<=min_gain )
/*MT6129A*/    {  request_gain = min_gain;  }
/*MT6129A*/
/*MT6129A*/    /* evaluate the real gain setting */
/*MT6129A*/    agcptr = AGC_TABLE[rf_band];
/*MT6129A*/    if( request_gain < agcptr->pos_gain )
/*MT6129A*/    {  agcptr++;
/*MT6129A*/       if( request_gain < agcptr->pos_gain )
/*MT6129A*/       {  agcptr++;  }
/*MT6129A*/    }
/*MT6129A*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129A*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129A*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129A*/    }
/*MT6129A*/
/*MT6129A*/    *gain_setting = setting;
/*MT6129A*/    return( real_gain );
/*MT6129A*/ }
#endif

/*===============================================================================================*/

#if  IS_RF_MT6129B
/*MT6129B*/
/*MT6129B*/ #define  GAIN_STEP               2
/*MT6129B*/
/*MT6129B*/ #define  RF_GSM850_MAXGAIN      (  72.0*(PWRRES))
/*MT6129B*/ #define  RF_GSM850_MINGAIN      ( -26.0*(PWRRES))
/*MT6129B*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129B*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129B*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129B*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129B*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129B*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129B*/
/*MT6129B*/ /* GSM850....................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6129B*/ {  {  GBOUND( 48.0, 46.0 ), 0x126012, GC_A(  18, 48.0 ) },
/*MT6129B*/    {  GBOUND(-6.0,-8.0 ), 0x006012, GC_A(  32,-6.0 ) },
/*MT6129B*/    {  GBOUND(-26.0,-26.0 ), 0x006002, GC_A(  0,-26.0 ) },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /* GSM900....................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129B*/ {  {  GBOUND( 48.0, 46.0 ), 0x126812, GC_A(  18, 48.0 ) },
/*MT6129B*/    {  GBOUND(-6.0,-8.0 ), 0x006812, GC_A(  32,-6.0 ) },
/*MT6129B*/    {  GBOUND(-26.0,-26.0 ), 0x006802, GC_A(  0,-26.0 ) },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /* DCS1800...................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129B*/ {  {  GBOUND( 46.0, 44.0 ), 0x127012, GC_A(  18, 46.0 ) },
/*MT6129B*/    {  GBOUND(-8.0,-10.0 ), 0x007012, GC_A(  32,-8.0 ) },
/*MT6129B*/    {  GBOUND(-28.0,-28.0 ), 0x007002, GC_A(  0,-28.0 ) },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /* PCS1900...................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129B*/ {  {  GBOUND( 46.0, 44.0 ), 0x127812, GC_A(  18, 46.0 ) },
/*MT6129B*/    {  GBOUND(-8.0,-10.0 ), 0x007812, GC_A(  32,-8.0 ) },
/*MT6129B*/    {  GBOUND(-28.0,-28.0 ), 0x007802, GC_A(  0,-28.0 ) },
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /*...........................................................................*/
/*MT6129B*/
/*MT6129B*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129B*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6129B*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6129B*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6129B*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6129B*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129B*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129B*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6129B*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129B*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129B*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129B*/
/*MT6129B*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129B*/ {  int   max_gain, min_gain, real_gain;
/*MT6129B*/    const int*    d32ptr;
/*MT6129B*/    const sL1DAGCDATA*  agcptr;
/*MT6129B*/    long  setting;
/*MT6129B*/    int   bit_no;
/*MT6129B*/
/*MT6129B*/    /* evaluate the range of available gain */
/*MT6129B*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129B*/    max_gain = *d32ptr++;
/*MT6129B*/    min_gain = *d32ptr;
/*MT6129B*/
/*MT6129B*/    /* clipping the request gain to the avialable gain */
/*MT6129B*/    if( request_gain>=max_gain )
/*MT6129B*/    {  request_gain = max_gain;  }
/*MT6129B*/    else  if( request_gain<=min_gain )
/*MT6129B*/    {  request_gain = min_gain;  }
/*MT6129B*/
/*MT6129B*/    /* evaluate the real gain setting */
/*MT6129B*/    agcptr = AGC_TABLE[rf_band];
/*MT6129B*/    if( request_gain < agcptr->pos_gain )
/*MT6129B*/    {  agcptr++;
/*MT6129B*/       if( request_gain < agcptr->pos_gain )
/*MT6129B*/       {  agcptr++;  }
/*MT6129B*/    }
/*MT6129B*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129B*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129B*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129B*/    }
/*MT6129B*/
/*MT6129B*/    *gain_setting = setting;
/*MT6129B*/    return( real_gain );
/*MT6129B*/ }
#endif

/*===============================================================================================*/

#if  (IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6129C,D*/
/*MT6129C,D*/ #define  GAIN_STEP               2
/*MT6129C,D*/
/*MT6129C,D*/ #define  RF_GSM850_MAXGAIN      (  72.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM850_MINGAIN      ( -26.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM_MAXGAIN         (  72.0*(PWRRES))
/*MT6129C,D*/ #define  RF_GSM_MINGAIN         ( -26.0*(PWRRES))
/*MT6129C,D*/ #define  RF_DCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129C,D*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129C,D*/ #define  RF_PCS_MAXGAIN         (  70.0*(PWRRES))
/*MT6129C,D*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6129C,D*/
/*MT6129C,D*/ /* GSM850....................................................................*/

/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[3] =
/*MT6129C,D*/ {  {  GBOUND( 34.0, 32.0 ), 0x126012, GC_A(  11, 34.0 ) },
/*MT6129C,D*/    {  GBOUND( -6.0, -8.0 ), 0x006012, GC_A(  32,-6.0 ) },
/*MT6129C,D*/    {  GBOUND(-26.0,-26.0 ), 0x006002, GC_A(  0,-26.0 ) },
/*MT6129C,D*/ };

/*MT6129C,D*/ /* GSM900....................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[3] =
/*MT6129C,D*/ {  {  GBOUND( 34.0, 32.0 ), 0x126812, GC_A(  11, 34.0 ) },
/*MT6129C,D*/    {  GBOUND(-6.0,-8.0 ), 0x006812, GC_A(  32,-6.0 ) },
/*MT6129C,D*/    {  GBOUND(-26.0,-26.0 ), 0x006802, GC_A(  0,-26.0 ) },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /* DCS1800...................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[3] =
/*MT6129C,D*/ {  {  GBOUND( 32.0, 30.0 ), 0x127012, GC_A(  11, 32.0 ) },
/*MT6129C,D*/    {  GBOUND(-8.0,-10.0 ), 0x007012, GC_A(  32,-8.0 ) },
/*MT6129C,D*/    {  GBOUND(-28.0,-28.0 ), 0x007002, GC_A(  0,-28.0 ) },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /* PCS1900...................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[3] =
/*MT6129C,D*/ {  {  GBOUND( 32.0, 30.0 ), 0x127812, GC_A(  11, 32.0 ) },
/*MT6129C,D*/    {  GBOUND(-8.0,-10.0 ), 0x007812, GC_A(  32,-8.0 ) },
/*MT6129C,D*/    {  GBOUND(-28.0,-28.0 ), 0x007802, GC_A(  0,-28.0 ) },
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /*...........................................................................*/
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6129C,D*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6129C,D*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6129C,D*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6129C,D*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6129C,D*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6129C,D*/ {  0,                                              /*#FrequencyBand400  */
/*MT6129C,D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6129C,D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6129C,D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6129C,D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ const  sL1DAGCDATA *const  AGC_TABLE_GSM800in900PATH[] =
/*MT6129C,D*/ {  0,                                              /*#FrequencyBand400 (not support)  */                                                                          
/*MT6129C,D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900 (Get GSM850 signal from GSM900 input pins) */                                              
/*MT6129C,D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850 (Get GSM900 signal from GSM850 input pins, just avoid to camp on GSM900 network, not swap*/
/*MT6129C,D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800               */                                                                          
/*MT6129C,D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900               */                                                                          
/*MT6129C,D*/ };
/*MT6129C,D*/
/*MT6129C,D*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6129C,D*/
/*MT6129C,D*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6129C,D*/ {  int   max_gain, min_gain, real_gain;
/*MT6129C,D*/    const int*    d32ptr;
/*MT6129C,D*/    const sL1DAGCDATA*  agcptr;
/*MT6129C,D*/    long  setting;
/*MT6129C,D*/    int   bit_no;
/*MT6129C,D*/
/*MT6129C,D*/    /* evaluate the range of available gain */
/*MT6129C,D*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6129C,D*/    max_gain = *d32ptr++;
/*MT6129C,D*/    min_gain = *d32ptr;
/*MT6129C,D*/
/*MT6129C,D*/    /* clipping the request gain to the avialable gain */
/*MT6129C,D*/    if( request_gain>=max_gain )
/*MT6129C,D*/    {  request_gain = max_gain;  }
/*MT6129C,D*/    else  if( request_gain<=min_gain )
/*MT6129C,D*/    {  request_gain = min_gain;  }
/*MT6129C,D*/
/*MT6129C,D*/    /* evaluate the real gain setting */
/*MT6129C,D*/    if(  BBTXParameters.bbrx_gsm850_gsm900_swap )
/*MT6129C,D*/    {   agcptr = AGC_TABLE_GSM800in900PATH[rf_band];  }
/*MT6129C,D*/    else
/*MT6129C,D*/    {   agcptr = AGC_TABLE[rf_band];           }
/*MT6129C,D*/    
/*MT6129C,D*/    if( request_gain < agcptr->pos_gain )
/*MT6129C,D*/    {  agcptr++;
/*MT6129C,D*/       if( request_gain < agcptr->pos_gain )
/*MT6129C,D*/       {  agcptr++;  }
/*MT6129C,D*/    }
/*MT6129C,D*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6129C,D*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6129C,D*/       setting   = agcptr->setting + (bit_no<<5);
/*MT6129C,D*/    }
/*MT6129C,D*/
/*MT6129C,D*/    *gain_setting = setting;
/*MT6129C,D*/    return( real_gain );
/*MT6129C,D*/ }
#endif

/*===============================================================================================*/
#if  IS_RF_MT6139B
/*MT6139B*/
/*MT6139B*/ #define  GAIN_STEP               2
/*MT6139B*/
/*MT6139B*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_GSM850_MINGAIN      ( -32.0*(PWRRES))
/*MT6139B*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_GSM_MINGAIN         ( -32.0*(PWRRES))
/*MT6139B*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139B*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139B*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139B*/
/*MT6139B*/ /* GSM850....................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /* GSM900....................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /* DCS1800...................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /* PCS1900...................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139B*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /*...........................................................................*/
/*MT6139B*/
/*MT6139B*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139B*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139B*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139B*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139B*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139B*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139B*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139B*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139B*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139B*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139B*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139B*/ };
/*MT6139B*/
/*MT6139B*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139B*/
/*MT6139B*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139B*/ {  int   max_gain, min_gain, real_gain;
/*MT6139B*/    const int*    d32ptr;
/*MT6139B*/    const sL1DAGCDATA*  agcptr;
/*MT6139B*/    long  setting;
/*MT6139B*/    int   bit_no;
/*MT6139B*/
/*MT6139B*/    /* evaluate the range of available gain */
/*MT6139B*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139B*/    max_gain = *d32ptr++;
/*MT6139B*/    min_gain = *d32ptr;
/*MT6139B*/
/*MT6139B*/    /* clipping the request gain to the avialable gain */
/*MT6139B*/    if( request_gain>=max_gain )
/*MT6139B*/    {  request_gain = max_gain;  }
/*MT6139B*/    else  if( request_gain<=min_gain )
/*MT6139B*/    {  request_gain = min_gain;  }
/*MT6139B*/
/*MT6139B*/    /* evaluate the real gain setting */
/*MT6139B*/    agcptr = AGC_TABLE[rf_band];
/*MT6139B*/    if( request_gain < agcptr->pos_gain )
/*MT6139B*/    {  agcptr++;
/*MT6139B*/    }
/*MT6139B*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139B*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139B*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139B*/    }
/*MT6139B*/
/*MT6139B*/    *gain_setting = setting;
/*MT6139B*/    return( real_gain );
/*MT6139B*/ }

#endif
/*===============================================================================================*/

#if  IS_RF_MT6139C
/*MT6139C*/
/*MT6139C*/ #define  GAIN_STEP               2
/*MT6139C*/
/*MT6139C*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_GSM850_MINGAIN      ( -32.0*(PWRRES))
/*MT6139C*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_GSM_MINGAIN         ( -32.0*(PWRRES))
/*MT6139C*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139C*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139C*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6139C*/
/*MT6139C*/ /* GSM850....................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /* GSM900....................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /* DCS1800...................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /* PCS1900...................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139C*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6139C*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /*...........................................................................*/
/*MT6139C*/
/*MT6139C*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139C*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139C*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139C*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139C*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139C*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139C*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139C*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139C*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139C*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139C*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139C*/ };
/*MT6139C*/
/*MT6139C*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139C*/
/*MT6139C*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139C*/ {  int   max_gain, min_gain, real_gain;
/*MT6139C*/    const int*    d32ptr;
/*MT6139C*/    const sL1DAGCDATA*  agcptr;
/*MT6139C*/    long  setting;
/*MT6139C*/    int   bit_no;
/*MT6139C*/
/*MT6139C*/    /* evaluate the range of available gain */
/*MT6139C*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139C*/    max_gain = *d32ptr++;
/*MT6139C*/    min_gain = *d32ptr;
/*MT6139C*/
/*MT6139C*/    /* clipping the request gain to the avialable gain */
/*MT6139C*/    if( request_gain>=max_gain )
/*MT6139C*/    {  request_gain = max_gain;  }
/*MT6139C*/    else  if( request_gain<=min_gain )
/*MT6139C*/    {  request_gain = min_gain;  }
/*MT6139C*/
/*MT6139C*/    /* evaluate the real gain setting */
/*MT6139C*/    agcptr = AGC_TABLE[rf_band];
/*MT6139C*/    if( request_gain < agcptr->pos_gain )
/*MT6139C*/    {  agcptr++;
/*MT6139C*/    }
/*MT6139C*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139C*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139C*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139C*/    }
/*MT6139C*/
/*MT6139C*/    *gain_setting = setting;
/*MT6139C*/    return( real_gain );
/*MT6139C*/ }

#endif
/*===============================================================================================*/

#if  IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ #define  GAIN_STEP               2
/*MT6139E*/
/*MT6139E*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM850_MINGAIN      ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_GSM_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_DCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6139E*/ #define  RF_PCS_MINGAIN         ( -28.0*(PWRRES))
/*MT6139E*/
/*MT6139E*/ /* GSM850....................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), 0x000E02, GC_A(  0, -4.0 ) },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), 0x000C02, GC_A(  4,-32.0 ) },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* GSM900....................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), 0x000E02, GC_A(  0, -4.0 ) },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), 0x000C02, GC_A(  4,-32.0 ) },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* DCS1800...................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), 0x000E02, GC_A(  0, -4.0 ) },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), 0x000C02, GC_A(  4,-32.0 ) },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /* PCS1900...................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6139E*/ {  {  GBOUND( -4.0, -6.0 ), 0x000E02, GC_A(  0, -4.0 ) },
/*MT6139E*/    {  GBOUND(-32.0,-32.0 ), 0x000C02, GC_A(  4,-32.0 ) },
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /*...........................................................................*/
/*MT6139E*/
/*MT6139E*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6139E*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6139E*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6139E*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6139E*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6139E*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6139E*/ {  0,                                              /*#FrequencyBand400  */
/*MT6139E*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6139E*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6139E*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6139E*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6139E*/ };
/*MT6139E*/
/*MT6139E*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6139E*/
/*MT6139E*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6139E*/ {  int   max_gain, min_gain, real_gain;
/*MT6139E*/    const int*    d32ptr;
/*MT6139E*/    const sL1DAGCDATA*  agcptr;
/*MT6139E*/    long  setting;
/*MT6139E*/    int   bit_no;
/*MT6139E*/
/*MT6139E*/    /* evaluate the range of available gain */
/*MT6139E*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6139E*/    max_gain = *d32ptr++;
/*MT6139E*/    min_gain = *d32ptr;
/*MT6139E*/
/*MT6139E*/    /* clipping the request gain to the avialable gain */
/*MT6139E*/    if( request_gain>=max_gain )
/*MT6139E*/    {  request_gain = max_gain;  }
/*MT6139E*/    else  if( request_gain<=min_gain )
/*MT6139E*/    {  request_gain = min_gain;  }
/*MT6139E*/
/*MT6139E*/    /* evaluate the real gain setting */
/*MT6139E*/    agcptr = AGC_TABLE[rf_band];
/*MT6139E*/    if( request_gain < agcptr->pos_gain )
/*MT6139E*/    {  agcptr++;
/*MT6139E*/    }
/*MT6139E*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6139E*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6139E*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6139E*/    }
/*MT6139E*/
/*MT6139E*/    *gain_setting = setting;
/*MT6139E*/    return( real_gain );
/*MT6139E*/ }

#endif

/*===============================================================================================*/

#if  IS_RF_MT6140A
/*MT6140A*/
/*MT6140A*/ #define  GAIN_STEP               2
/*MT6140A*/
/*MT6140A*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_GSM850_MINGAIN      ( -32.0*(PWRRES))
/*MT6140A*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_GSM_MINGAIN         ( -32.0*(PWRRES))
/*MT6140A*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140A*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140A*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140A*/
/*MT6140A*/ /* GSM850....................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /* GSM900....................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /* DCS1800...................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /* PCS1900...................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140A*/ {  {  GBOUND( -4.0, -6.0 ), 0x000C02, GC_A(  32, -4.0 ) },
/*MT6140A*/    {  GBOUND(-44.0,-44.0 ), 0x000C02, GC_A(  0,-44.0 ) },
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /*...........................................................................*/
/*MT6140A*/
/*MT6140A*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140A*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140A*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140A*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140A*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140A*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140A*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140A*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140A*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140A*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140A*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140A*/ };
/*MT6140A*/
/*MT6140A*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140A*/
/*MT6140A*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140A*/ {  int   max_gain, min_gain, real_gain;
/*MT6140A*/    const int*    d32ptr;
/*MT6140A*/    const sL1DAGCDATA*  agcptr;
/*MT6140A*/    long  setting;
/*MT6140A*/    int   bit_no;
/*MT6140A*/
/*MT6140A*/    /* evaluate the range of available gain */
/*MT6140A*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140A*/    max_gain = *d32ptr++;
/*MT6140A*/    min_gain = *d32ptr;
/*MT6140A*/
/*MT6140A*/    /* clipping the request gain to the avialable gain */
/*MT6140A*/    if( request_gain>=max_gain )
/*MT6140A*/    {  request_gain = max_gain;  }
/*MT6140A*/    else  if( request_gain<=min_gain )
/*MT6140A*/    {  request_gain = min_gain;  }
/*MT6140A*/
/*MT6140A*/    /* evaluate the real gain setting */
/*MT6140A*/    agcptr = AGC_TABLE[rf_band];
/*MT6140A*/    if( request_gain < agcptr->pos_gain )
/*MT6140A*/    {  agcptr++;
/*MT6140A*/    }
/*MT6140A*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140A*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140A*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140A*/    }
/*MT6140A*/
/*MT6140A*/    *gain_setting = setting;
/*MT6140A*/    return( real_gain );
/*MT6140A*/ }

#endif
/*===============================================================================================*/

#if  IS_RF_MT6140B
/*MT6140B*/
/*MT6140B*/ #define  GAIN_STEP               2
/*MT6140B*/
/*MT6140B*/ #define  RF_GSM850_MAXGAIN      (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_GSM850_MINGAIN      ( -30.0*(PWRRES))
/*MT6140B*/ #define  RF_GSM_MAXGAIN         (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_GSM_MINGAIN         ( -30.0*(PWRRES))
/*MT6140B*/ #define  RF_DCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_DCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6140B*/ #define  RF_PCS_MAXGAIN         (  56.0*(PWRRES))
/*MT6140B*/ #define  RF_PCS_MINGAIN         ( -30.0*(PWRRES))
/*MT6140B*/
/*MT6140B*/ /* GSM850....................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000202, GC_A(  0, -4.0 ) },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /* GSM900....................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000202, GC_A(  0, -4.0 ) },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /* DCS1800...................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000202, GC_A(  0, -4.0 ) },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /* PCS1900...................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140B*/ {  {  GBOUND( -4.0, -6.0 ), 0x000202, GC_A(  0, -4.0 ) },
/*MT6140B*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /*...........................................................................*/
/*MT6140B*/
/*MT6140B*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140B*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140B*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140B*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140B*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140B*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140B*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140B*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140B*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140B*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140B*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140B*/ };
/*MT6140B*/
/*MT6140B*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140B*/
/*MT6140B*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140B*/ {  int   max_gain, min_gain, real_gain;
/*MT6140B*/    const int*    d32ptr;
/*MT6140B*/    const sL1DAGCDATA*  agcptr;
/*MT6140B*/    long  setting;
/*MT6140B*/    int   bit_no;
/*MT6140B*/
/*MT6140B*/    /* evaluate the range of available gain */
/*MT6140B*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140B*/    max_gain = *d32ptr++;
/*MT6140B*/    min_gain = *d32ptr;
/*MT6140B*/
/*MT6140B*/    /* clipping the request gain to the avialable gain */
/*MT6140B*/    if( request_gain>=max_gain )
/*MT6140B*/    {  request_gain = max_gain;  }
/*MT6140B*/    else  if( request_gain<=min_gain )
/*MT6140B*/    {  request_gain = min_gain;  }
/*MT6140B*/
/*MT6140B*/    /* evaluate the real gain setting */
/*MT6140B*/    agcptr = AGC_TABLE[rf_band];
/*MT6140B*/    if( request_gain < agcptr->pos_gain )
/*MT6140B*/    {  agcptr++;
/*MT6140B*/    }
/*MT6140B*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140B*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140B*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140B*/    }
/*MT6140B*/
/*MT6140B*/    *gain_setting = setting;
/*MT6140B*/    return( real_gain );
/*MT6140B*/ }

#endif
/*===============================================================================================*/

#if  IS_RF_MT6140C
/*MT6140C*/
/*MT6140C*/ #define  GAIN_STEP               2
/*MT6140C*/
/*MT6140C*/ #define  RF_GSM850_MAXGAIN      (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_GSM850_MINGAIN      ( -30.0*(PWRRES))
/*MT6140C*/ #define  RF_GSM_MAXGAIN         (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_GSM_MINGAIN         ( -30.0*(PWRRES))
/*MT6140C*/ #define  RF_DCS_MAXGAIN         (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_DCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140C*/ #define  RF_PCS_MAXGAIN         (  54.0*(PWRRES))
/*MT6140C*/ #define  RF_PCS_MINGAIN         ( -32.0*(PWRRES))
/*MT6140C*/
/*MT6140C*/ /* GSM850....................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), 0x000202, GC_A(  0, -6.0 ) },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /* GSM900....................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), 0x000202, GC_A(  0, -6.0 ) },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /* DCS1800...................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), 0x000202, GC_A(  0, -6.0 ) },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /* PCS1900...................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140C*/ {  {  GBOUND( -6.0, -8.0 ), 0x000202, GC_A(  0, -6.0 ) },
/*MT6140C*/    {  GBOUND(-30.0,-30.0 ), 0x000002, GC_A(  6,-30.0 ) },
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /*...........................................................................*/
/*MT6140C*/
/*MT6140C*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140C*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140C*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140C*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140C*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140C*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140C*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140C*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140C*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140C*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140C*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140C*/ };
/*MT6140C*/
/*MT6140C*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140C*/
/*MT6140C*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140C*/ {  int   max_gain, min_gain, real_gain;
/*MT6140C*/    const int*    d32ptr;
/*MT6140C*/    const sL1DAGCDATA*  agcptr;
/*MT6140C*/    long  setting;
/*MT6140C*/    int   bit_no;
/*MT6140C*/
/*MT6140C*/    /* evaluate the range of available gain */
/*MT6140C*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140C*/    max_gain = *d32ptr++;
/*MT6140C*/    min_gain = *d32ptr;
/*MT6140C*/
/*MT6140C*/    /* clipping the request gain to the avialable gain */
/*MT6140C*/    if( request_gain>=max_gain )
/*MT6140C*/    {  request_gain = max_gain;  }
/*MT6140C*/    else  if( request_gain<=min_gain )
/*MT6140C*/    {  request_gain = min_gain;  }
/*MT6140C*/
/*MT6140C*/    /* evaluate the real gain setting */
/*MT6140C*/    agcptr = AGC_TABLE[rf_band];
/*MT6140C*/    if( request_gain < agcptr->pos_gain )
/*MT6140C*/    {  agcptr++;
/*MT6140C*/    }
/*MT6140C*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140C*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140C*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140C*/    }
/*MT6140C*/
/*MT6140C*/    *gain_setting = setting;
/*MT6140C*/    return( real_gain );
/*MT6140C*/ }

#endif

/*===============================================================================================*/

#if  IS_RF_MT6140D
/*MT6140D*/
/*MT6140D*/ #define  GAIN_STEP               2
/*MT6140D*/ #define  PVOFSL                 34
/*MT6140D*/ #define  PVOFSH                 34
/*MT6140D*/ #define  RF_GSM850_MAXGAIN      (( 90-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM850_MINGAIN      ((  4-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM_MAXGAIN         (( 90-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_GSM_MINGAIN         ((  4-PVOFSL )*(PWRRES))
/*MT6140D*/ #define  RF_DCS_MAXGAIN         (( 88-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_DCS_MINGAIN         ((  2-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_PCS_MAXGAIN         (( 88-PVOFSH )*(PWRRES))
/*MT6140D*/ #define  RF_PCS_MINGAIN         ((  2-PVOFSH )*(PWRRES))
/*MT6140D*/
/*MT6140D*/ /* GSM850....................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_GSM850[2] =
/*MT6140D*/ {  {  GBOUND(( 30-PVOFSL ),( 28-PVOFSL ) ), 0x000202, GC_A(  0,( 30-PVOFSL ) ) },
/*MT6140D*/    {  GBOUND((  4-PVOFSL ),(  4-PVOFSL ) ), 0x000002, GC_A(  5,(  4-PVOFSL ) ) },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* GSM900....................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_GSM900[2] =
/*MT6140D*/ {  {  GBOUND(( 30-PVOFSL ),( 28-PVOFSL ) ), 0x000202, GC_A(  0,( 30-PVOFSL ) ) },
/*MT6140D*/    {  GBOUND((  4-PVOFSL ),(  4-PVOFSL ) ), 0x000002, GC_A(  5,(  4-PVOFSL ) ) },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* DCS1800...................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_DCS1800[2] =
/*MT6140D*/ {  {  GBOUND(( 28-PVOFSH ),( 26-PVOFSH ) ), 0x000202, GC_A(  0,( 28-PVOFSH ) ) },
/*MT6140D*/    {  GBOUND((  2-PVOFSH ),(  2-PVOFSH ) ), 0x000002, GC_A(  6,(  2-PVOFSH ) ) },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /* PCS1900...................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA  AGC_TABLE_PCS1900[2] =
/*MT6140D*/ {  {  GBOUND(( 28-PVOFSH ),( 26-PVOFSH ) ), 0x000202, GC_A(  0,( 28-PVOFSH ) ) },
/*MT6140D*/    {  GBOUND((  2-PVOFSH ),(  2-PVOFSH ) ), 0x000002, GC_A(  6,(  2-PVOFSH ) ) },
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /*...........................................................................*/
/*MT6140D*/
/*MT6140D*/ const  sL1DGAINRANGE GAIN_RANGE_TABLE[] =
/*MT6140D*/ {  {                   0,                      0    }, /*#FrequencyBand400  */
/*MT6140D*/    { (int)RF_GSM850_MAXGAIN, (int)RF_GSM850_MINGAIN }, /* FrequencyBand850  */
/*MT6140D*/    { (int)RF_GSM_MAXGAIN,    (int)RF_GSM_MINGAIN    }, /* FrequencyBand900  */
/*MT6140D*/    { (int)RF_DCS_MAXGAIN,    (int)RF_DCS_MINGAIN    }, /* FrequencyBand1800 */
/*MT6140D*/    { (int)RF_PCS_MAXGAIN,    (int)RF_PCS_MINGAIN    }, /* FrequencyBand1900 */
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ const  sL1DAGCDATA *const  AGC_TABLE[] =
/*MT6140D*/ {  0,                                              /*#FrequencyBand400  */
/*MT6140D*/    AGC_TABLE_GSM850,                               /* FrequencyBand850  */
/*MT6140D*/    AGC_TABLE_GSM900,                               /* FrequencyBand900  */
/*MT6140D*/    AGC_TABLE_DCS1800,                              /* FrequencyBand1800 */
/*MT6140D*/    AGC_TABLE_PCS1900,                              /* FrequencyBand1900 */
/*MT6140D*/ };
/*MT6140D*/
/*MT6140D*/ /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*MT6140D*/
/*MT6140D*/ int   L1D_RF_GetGainSetting( int rf_band, int arfcn, int request_gain, long *gain_setting )
/*MT6140D*/ {  int   max_gain, min_gain, real_gain;
/*MT6140D*/    const int*    d32ptr;
/*MT6140D*/    const sL1DAGCDATA*  agcptr;
/*MT6140D*/    long  setting;
/*MT6140D*/    int   bit_no;
/*MT6140D*/
/*MT6140D*/    /* evaluate the range of available gain */
/*MT6140D*/    d32ptr  = (int*)&(GAIN_RANGE_TABLE[rf_band]);
/*MT6140D*/    max_gain = *d32ptr++;
/*MT6140D*/    min_gain = *d32ptr;
/*MT6140D*/
/*MT6140D*/    /* clipping the request gain to the avialable gain */
/*MT6140D*/    if( request_gain>=max_gain )
/*MT6140D*/    {  request_gain = max_gain;  }
/*MT6140D*/    else  if( request_gain<=min_gain )
/*MT6140D*/    {  request_gain = min_gain;  }
/*MT6140D*/
/*MT6140D*/    /* evaluate the real gain setting */
/*MT6140D*/    agcptr = AGC_TABLE[rf_band];
/*MT6140D*/    if( request_gain < agcptr->pos_gain )
/*MT6140D*/    {  agcptr++;
/*MT6140D*/    }
/*MT6140D*/    {  bit_no    = BIT_NO( request_gain, agcptr->A, GC_B );
/*MT6140D*/       real_gain = REAL_GAIN( bit_no, agcptr->A, GC_B );
/*MT6140D*/       setting   = agcptr->setting + (bit_no<<4);
/*MT6140D*/    }
/*MT6140D*/
/*MT6140D*/    *gain_setting = setting;
/*MT6140D*/    return( real_gain );
/*MT6140D*/ }

#endif
/*===============================================================================================*/

#if  IS_RF_SKY74045
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*===============================================================================================*/

#if  IS_RF_AERO2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

/*===============================================================================================*/

#if  IS_RF_SKY74137
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/*===============================================================================================*/

#if  IS_RF_GRF6201
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*===============================================================================================*/
#if  IS_RF_IRFS3001    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*================================================================================================*/
