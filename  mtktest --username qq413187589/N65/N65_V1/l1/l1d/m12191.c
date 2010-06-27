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
 *	m12191.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup Synthesizer
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
/* void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )  */
/* void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )  */
/*                                                                               */
/*===============================================================================*/
/*                                                                               */
/* arfcn  : the request ARFCN number.                                            */
/* *rfN   : returned RF N counter setting                                        */
/* *ifN   : returned IF N counter setting                                        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */
/*                                                                               */
/* This program evaluates the PLL setting value by the request arfcn for Si4133. */
/* If the PLL component is changed, this file shall be modified by vendor        */
/*                                                                               */
/* ----------------------------------------------------------------------------- */

#include "l1d_cid.h"
#include "m12190.h"
#include "l1d_reg.h"

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
#endif

/*=========================================================================================*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if  IS_RF_AERO
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if  IS_RF_AERO1PLUS
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

/*=========================================================================================*/

#if  IS_RF_SKY74117
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if  IS_RF_SKY74400
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if  IS_RF_MT6119
/*MT6119*/ void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119*/ {  int   Nfrac;
/*MT6119*/
/*MT6119*/    switch(rf_band)
/*MT6119*/    {
/*MT6119*/       case  FrequencyBand900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=70)
/*MT6119*/          {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6119*/             {  Nfrac = 80*(arfcn-0)+4760;
/*MT6119*/                *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN :  6~70    */
/*MT6119*/             {  Nfrac = 80*(arfcn-6)+40;
/*MT6119*/                *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6119*/             {  Nfrac = 80*(arfcn-71)+40;
/*MT6119*/                *rfN = (9L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6119*/                *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1800 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=716)
/*MT6119*/          {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6119*/             {  Nfrac = 40*(arfcn-512)+2220;
/*MT6119*/                *rfN = (5L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN : 587~716  */
/*MT6119*/             {  Nfrac = 40*(arfcn-587)+20;
/*MT6119*/                *rfN = (6L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6119*/             {  Nfrac = 40*(arfcn-717)+20;
/*MT6119*/                *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN : 847~885  */
/*MT6119*/             {  Nfrac = 40*(arfcn-847)+20;
/*MT6119*/                *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=741)
/*MT6119*/          {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6119*/             {  Nfrac = 40*(arfcn-512)+1220;
/*MT6119*/                *rfN = (10L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/             else                                        /*  ARFCN : 612~741  */
/*MT6119*/             {  Nfrac = 40*(arfcn-612)+20;
/*MT6119*/                *rfN = (11L<<16) | (Nfrac<<3) | 1;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6119*/             *rfN = (12L<<16) | (Nfrac<<3) | 1;
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       default :
/*MT6119*/       {
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/    }
/*MT6119*/    *ifN = 0;
/*MT6119*/ }
/*MT6119*/ /* =========================================================================== */
/*MT6119*/
/*MT6119*/ char mt6119_d_flag = 0;
/*MT6119*/
/*MT6119*/ void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119*/ {  int   Nfrac;
/*MT6119*/
/*MT6119*/    switch(rf_band)
/*MT6119*/    {
/*MT6119*/       case  FrequencyBand900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=110)
/*MT6119*/          {  if(arfcn<=52)
/*MT6119*/             {  if(arfcn<=3)                     /* ARFCN : 0~3       */
/*MT6119*/                {  Nfrac = 88*(arfcn-0)+1600;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 4~52     */
/*MT6119*/                {  Nfrac = 90*(arfcn-4)+460;
/*MT6119*/                   *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=61)                    /* ARFCN : 53~61     */
/*MT6119*/                {  Nfrac = 88*(arfcn-53)+1064;
/*MT6119*/                   *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 62~110    */
/*MT6119*/                {  Nfrac = 90*(arfcn-62)+480;
/*MT6119*/                   *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=124)
/*MT6119*/             {  if(arfcn<=118)                   /* ARFCN : 111~118   */
/*MT6119*/                {  Nfrac = 88*(arfcn-111)+968;
/*MT6119*/                   *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 119~124  */
/*MT6119*/                {  Nfrac = 90*(arfcn-119)+410;
/*MT6119*/                   *rfN = (15L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=1018)                  /* ARFCN : 975~1018 */
/*MT6119*/                {  Nfrac = 90*(arfcn-975)+890;
/*MT6119*/                   *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 1019~1023 */
/*MT6119*/                {  Nfrac = 88*(arfcn-1019)+1160;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1800 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=734)
/*MT6119*/          {  if(arfcn<=618)
/*MT6119*/             {  if(arfcn<=520)                   /* ARFCN : 512~520   */
/*MT6119*/                {  Nfrac = 44*(arfcn-512)+1844;
/*MT6119*/                   *rfN = (8L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 521~618   */
/*MT6119*/                {  Nfrac = 45*(arfcn-521)+400;
/*MT6119*/                   *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=636)                   /* ARFCN : 619~636   */
/*MT6119*/                {  Nfrac = 44*(arfcn-619)+1352;
/*MT6119*/                   *rfN = (9L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 637~734   */
/*MT6119*/                {  Nfrac = 45*(arfcn-637)+420;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=849)
/*MT6119*/             {  if(arfcn<=752)                   /* ARFCN : 735~752   */
/*MT6119*/                {  Nfrac = 44*(arfcn-735)+1256;
/*MT6119*/                   *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                             /* ARFCN : 753~849   */
/*MT6119*/                {  Nfrac = 45*(arfcn-753)+440;
/*MT6119*/                   *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else                                /* ARFCN : 850~867   */
/*MT6119*/             {  if(arfcn<=867)
/*MT6119*/                 {  Nfrac = 44*(arfcn-850)+1116;
/*MT6119*/                   *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                }
/*MT6119*/                else                            /* ARFCN : 868~885   */
/*MT6119*/                {  Nfrac = 45*(arfcn-868)+415;
/*MT6119*/                   *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       case  FrequencyBand1900 :
/*MT6119*/       {
/*MT6119*/          if(arfcn<=727)
/*MT6119*/          {  if(arfcn<=612)
/*MT6119*/             {  if(arfcn<=514)                /* ARFCN : 512~514   */
/*MT6119*/                {  Nfrac = 44*(arfcn-512)+1444;
/*MT6119*/                   *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                 }
/*MT6119*/                 else
/*MT6119*/                 {  Nfrac = 45*(arfcn-515)+430;  /* ARFCN : 515~612   */
/*MT6119*/                   *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/             else
/*MT6119*/             {  if(arfcn<=629)                /* ARFCN : 613~629   */
/*MT6119*/                {  Nfrac = 44*(arfcn-613)+688;
/*MT6119*/                   *rfN = (15L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 1;
/*MT6119*/                 }
/*MT6119*/                 else
/*MT6119*/                 {  Nfrac = 45*(arfcn-630)+405;  /* ARFCN : 630~727   */
/*MT6119*/                   *rfN = (17L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                   mt6119_d_flag = 0;
/*MT6119*/                }
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          else
/*MT6119*/          {  if(arfcn<=745)                      /* ARFCN : 728~745   */
/*MT6119*/               {  Nfrac = 44*(arfcn-728)+548;
/*MT6119*/                *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                mt6119_d_flag = 1;
/*MT6119*/             }
/*MT6119*/             else                                /* ARFCN : 746~810   */
/*MT6119*/             {  Nfrac = 45*(arfcn-746)+425;
/*MT6119*/                *rfN = (18L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119*/                mt6119_d_flag = 0;
/*MT6119*/             }
/*MT6119*/          }
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/       default :
/*MT6119*/       {
/*MT6119*/          break;
/*MT6119*/       }
/*MT6119*/    }
/*MT6119*/    *ifN = 0;
/*MT6119*/ }
#endif

/*================================================================================================*/

#if  IS_RF_MT6119C
/*MT6119C*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119C*/{  int   Nfrac;
/*MT6119C*/
/*MT6119C*/   switch(rf_band)
/*MT6119C*/   {
/*MT6119C*/      case  FrequencyBand900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=70)
/*MT6119C*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6119C*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6119C*/               *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN :  6~70    */
/*MT6119C*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6119C*/               *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6119C*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6119C*/               *rfN = (9L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6119C*/               *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1800 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=716)
/*MT6119C*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6119C*/               *rfN = (5L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN : 587~716  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6119C*/               *rfN = (6L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6119C*/               *rfN = (7L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN : 847~885  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6119C*/               *rfN = (8L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=741)
/*MT6119C*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6119C*/               *rfN = (10L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/            else                                        /*  ARFCN : 612~741  */
/*MT6119C*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6119C*/               *rfN = (11L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6119C*/            *rfN = (12L<<16) | (Nfrac<<3) | 1;
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      default :
/*MT6119C*/      {
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/   }
/*MT6119C*/   *ifN = 0;
/*MT6119C*/}
/*MT6119C*//* =========================================================================== */
/*MT6119C*/
/*MT6119C*/char mt6119_d_flag = 0;
/*MT6119C*/
/*MT6119C*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6119C*/{  int   Nfrac;
/*MT6119C*/
/*MT6119C*/   switch(rf_band)
/*MT6119C*/   {
/*MT6119C*/      case  FrequencyBand900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=104)
/*MT6119C*/         {  if(arfcn<=45)
/*MT6119C*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6119C*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6119C*/                  *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 37~45     */
/*MT6119C*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6119C*/                  *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6119C*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6119C*/                  *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 96~104    */
/*MT6119C*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6119C*/                  *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=1001)
/*MT6119C*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6119C*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6119C*/                  *rfN = (13L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 975~1001  */
/*MT6119C*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6119C*/                  *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6119C*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6119C*/                  *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 1011~1023 */
/*MT6119C*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6119C*/                  *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1800 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=715)
/*MT6119C*/         {  if(arfcn<=597)
/*MT6119C*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6119C*/                  *rfN = (8L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 580~597   */
/*MT6119C*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6119C*/                  *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else
/*MT6119C*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6119C*/                  *rfN = (9L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 698~715   */
/*MT6119C*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6119C*/                  *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=833)
/*MT6119C*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6119C*/                  *rfN = (10L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/               }
/*MT6119C*/               else                             /* ARFCN : 816~833   */
/*MT6119C*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6119C*/                  *rfN = (12L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else                                /* ARFCN : 834~885   */
/*MT6119C*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6119C*/               *rfN = (11L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      case  FrequencyBand1900 :
/*MT6119C*/      {
/*MT6119C*/         if(arfcn<=706)
/*MT6119C*/         {  if(arfcn<=606)
/*MT6119C*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6119C*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6119C*/                  *rfN = (14L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 1;
/*MT6119C*/              }
/*MT6119C*/              else
/*MT6119C*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6119C*/                  *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/                  mt6119_d_flag = 0;
/*MT6119C*/               }
/*MT6119C*/            }
/*MT6119C*/            else                                /* ARFCN : 607~706   */
/*MT6119C*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6119C*/               *rfN = (15L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         else
/*MT6119C*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6119C*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6119C*/               *rfN = (17L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 0;
/*MT6119C*/            }
/*MT6119C*/            else                                /* ARFCN : 725~810   */
/*MT6119C*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6119C*/               *rfN = (16L<<16) | (Nfrac<<3) | 0x400001L;
/*MT6119C*/               mt6119_d_flag = 1;
/*MT6119C*/            }
/*MT6119C*/         }
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/      default :
/*MT6119C*/      {
/*MT6119C*/         break;
/*MT6119C*/      }
/*MT6119C*/   }
/*MT6119C*/   *ifN = 0;
/*MT6119C*/}
#endif

/*================================================================================================*/

#if  IS_RF_MT6129A
/*MT6129A*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129A*/{  int   Nfrac;
/*MT6129A*/
/*MT6129A*/   switch(rf_band)
/*MT6129A*/   {
/*MT6129A*/      case  FrequencyBand900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=70)
/*MT6129A*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129A*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129A*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN :  6~70    */
/*MT6129A*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129A*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129A*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129A*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129A*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1800 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=716)
/*MT6129A*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129A*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN : 587~716  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129A*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129A*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN : 847~885  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129A*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=741)
/*MT6129A*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129A*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/            else                                        /*  ARFCN : 612~741  */
/*MT6129A*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129A*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129A*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      default :
/*MT6129A*/      {
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/   }
/*MT6129A*/   *ifN = 0;
/*MT6129A*/}
/*MT6129A*//* =========================================================================== */
/*MT6129A*/
/*MT6129A*/char mt6119_d_flag = 0;
/*MT6129A*/
/*MT6129A*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129A*/{  int   Nfrac;
/*MT6129A*/
/*MT6129A*/   switch(rf_band)
/*MT6129A*/   {
/*MT6129A*/      case  FrequencyBand900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=104)
/*MT6129A*/         {  if(arfcn<=45)
/*MT6129A*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129A*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129A*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 37~45     */
/*MT6129A*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129A*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129A*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129A*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 96~104    */
/*MT6129A*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129A*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=1001)
/*MT6129A*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129A*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129A*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 975~1001  */
/*MT6129A*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129A*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129A*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129A*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 1011~1023 */
/*MT6129A*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129A*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1800 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=715)
/*MT6129A*/         {  if(arfcn<=597)
/*MT6129A*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129A*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 580~597   */
/*MT6129A*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129A*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else
/*MT6129A*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129A*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 698~715   */
/*MT6129A*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129A*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=833)
/*MT6129A*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129A*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/               }
/*MT6129A*/               else                             /* ARFCN : 816~833   */
/*MT6129A*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129A*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else                                /* ARFCN : 834~885   */
/*MT6129A*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129A*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      case  FrequencyBand1900 :
/*MT6129A*/      {
/*MT6129A*/         if(arfcn<=706)
/*MT6129A*/         {  if(arfcn<=606)
/*MT6129A*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129A*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129A*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 1;
/*MT6129A*/              }
/*MT6129A*/              else
/*MT6129A*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129A*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/                  mt6119_d_flag = 0;
/*MT6129A*/               }
/*MT6129A*/            }
/*MT6129A*/            else                                /* ARFCN : 607~706   */
/*MT6129A*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129A*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         else
/*MT6129A*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129A*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129A*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 0;
/*MT6129A*/            }
/*MT6129A*/            else                                /* ARFCN : 725~810   */
/*MT6129A*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129A*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129A*/               mt6119_d_flag = 1;
/*MT6129A*/            }
/*MT6129A*/         }
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/      default :
/*MT6129A*/      {
/*MT6129A*/         break;
/*MT6129A*/      }
/*MT6129A*/   }
/*MT6129A*/   *ifN = 0;
/*MT6129A*/}
#endif

/*================================================================================================*/

#if  IS_RF_MT6129B
/*MT6129B*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129B*/{  int   Nfrac;
/*MT6129B*/
/*MT6129B*/   switch(rf_band)
/*MT6129B*/   {
/*MT6129B*/      case  FrequencyBand850 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=202)
/*MT6129B*/         {  if(arfcn<=137)                              /*  ARFCN :  128~137    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-128)+4440;
/*MT6129B*/               *rfN = (2L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN :  138~202    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-138)+40;
/*MT6129B*/               *rfN = (3L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {                                             /*  ARFCN :  203~251   */
/*MT6129B*/               Nfrac = 80*(arfcn-203)+40;
/*MT6129B*/               *rfN = (4L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=70)
/*MT6129B*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129B*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN :  6~70    */
/*MT6129B*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129B*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129B*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129B*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129B*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1800 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=716)
/*MT6129B*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129B*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN : 587~716  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129B*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129B*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN : 847~885  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129B*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=741)
/*MT6129B*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129B*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/            else                                        /*  ARFCN : 612~741  */
/*MT6129B*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129B*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129B*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      default :
/*MT6129B*/      {
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/   }
/*MT6129B*/   *ifN = 0;
/*MT6129B*/}
/*MT6129B*//* =========================================================================== */
/*MT6129B*/
/*MT6129B*/char mt6119_d_flag = 0;
/*MT6129B*/
/*MT6129B*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129B*/{  int   Nfrac;
/*MT6129B*/
/*MT6129B*/   switch(rf_band)
/*MT6129B*/   {
/*MT6129B*/      case  FrequencyBand850 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=197)
/*MT6129B*/         {  if(arfcn<=147)
/*MT6129B*/            {  if(arfcn<=138)
/*MT6129B*/               {                                /* ARFCN : 128~138     */
/*MT6129B*/                  Nfrac = 88*(arfcn-128)+3848;
/*MT6129B*/                  *rfN = (5L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else
/*MT6129B*/               {                                /* ARFCN : 139~147     */
/*MT6129B*/                  Nfrac = 90*(arfcn-139)+2680;
/*MT6129B*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {                                   /* ARFCN : 148~197     */
/*MT6129B*/                  Nfrac = 88*(arfcn-148)+408;
/*MT6129B*/                  *rfN = (6L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=206)
/*MT6129B*/            {                                   /* ARFCN : 198~206   */
/*MT6129B*/                  Nfrac = 90*(arfcn-198)+2790;
/*MT6129B*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {                                   /* ARFCN : 207~251 */
/*MT6129B*/                  Nfrac = 88*(arfcn-207)+400;
/*MT6129B*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=104)
/*MT6129B*/         {  if(arfcn<=45)
/*MT6129B*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129B*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129B*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 37~45     */
/*MT6129B*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129B*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129B*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129B*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 96~104    */
/*MT6129B*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129B*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=1001)
/*MT6129B*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129B*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129B*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 975~1001  */
/*MT6129B*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129B*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129B*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129B*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 1011~1023 */
/*MT6129B*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129B*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1800 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=715)
/*MT6129B*/         {  if(arfcn<=597)
/*MT6129B*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129B*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 580~597   */
/*MT6129B*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129B*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else
/*MT6129B*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129B*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 698~715   */
/*MT6129B*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129B*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=833)
/*MT6129B*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129B*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/               }
/*MT6129B*/               else                             /* ARFCN : 816~833   */
/*MT6129B*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129B*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else                                /* ARFCN : 834~885   */
/*MT6129B*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129B*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      case  FrequencyBand1900 :
/*MT6129B*/      {
/*MT6129B*/         if(arfcn<=706)
/*MT6129B*/         {  if(arfcn<=606)
/*MT6129B*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129B*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129B*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 1;
/*MT6129B*/              }
/*MT6129B*/              else
/*MT6129B*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129B*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/                  mt6119_d_flag = 0;
/*MT6129B*/               }
/*MT6129B*/            }
/*MT6129B*/            else                                /* ARFCN : 607~706   */
/*MT6129B*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129B*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         else
/*MT6129B*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129B*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129B*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 0;
/*MT6129B*/            }
/*MT6129B*/            else                                /* ARFCN : 725~810   */
/*MT6129B*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129B*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129B*/               mt6119_d_flag = 1;
/*MT6129B*/            }
/*MT6129B*/         }
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/      default :
/*MT6129B*/      {
/*MT6129B*/         break;
/*MT6129B*/      }
/*MT6129B*/   }
/*MT6129B*/   *ifN = 0;
/*MT6129B*/}
#endif

/*=========================================================================================*/

#if  (IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6129C,D*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129C,D*/{  int   Nfrac;
/*MT6129C,D*/
/*MT6129C,D*/   switch(rf_band)
/*MT6129C,D*/   {
/*MT6129C,D*/      case  FrequencyBand850 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=202)
/*MT6129C,D*/         {  if(arfcn<=137)                              /*  ARFCN :  128~137    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-128)+4440;
/*MT6129C,D*/               *rfN = (2L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN :  138~202    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-138)+40;
/*MT6129C,D*/               *rfN = (3L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {                                             /*  ARFCN :  203~251   */
/*MT6129C,D*/               Nfrac = 80*(arfcn-203)+40;
/*MT6129C,D*/               *rfN = (4L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=70)
/*MT6129C,D*/         {  if(arfcn<=5)                                /*  ARFCN :   0~5    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-0)+4760;
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN :  6~70    */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-6)+40;
/*MT6129C,D*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=124)                              /*  ARFCN : 71~124   */
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-71)+40;
/*MT6129C,D*/               *rfN = (9L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  Nfrac = 80*(arfcn-975)+840;              /*  ARFCN : 975~1023 */
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1800 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=716)
/*MT6129C,D*/         {  if(arfcn<=586)                              /*  ARFCN : 512~586  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-512)+2220;
/*MT6129C,D*/               *rfN = (5L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 587~716  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-587)+20;
/*MT6129C,D*/               *rfN = (6L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=846)                              /*  ARFCN : 717~846  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-717)+20;
/*MT6129C,D*/               *rfN = (7L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 847~885  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-847)+20;
/*MT6129C,D*/               *rfN = (8L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=741)
/*MT6129C,D*/         {  if(arfcn<=611)                              /*  ARFCN : 512~611  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-512)+1220;
/*MT6129C,D*/               *rfN = (10L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                        /*  ARFCN : 612~741  */
/*MT6129C,D*/            {  Nfrac = 40*(arfcn-612)+20;
/*MT6129C,D*/               *rfN = (11L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  Nfrac = 40*(arfcn-742)+20;                  /*  ARFCN : 742~810  */
/*MT6129C,D*/            *rfN = (12L<<17) | (Nfrac<<4) | 1;
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      default :
/*MT6129C,D*/      {
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/   }
/*MT6129C,D*/   *ifN = 0;
/*MT6129C,D*/}
/*MT6129C,D*//* =========================================================================== */
/*MT6129C,D*/
/*MT6129C,D*/char mt6119_d_flag = 0;
/*MT6129C,D*/
/*MT6129C,D*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6129C,D*/{  int   Nfrac;
/*MT6129C,D*/
/*MT6129C,D*/   switch(rf_band)
/*MT6129C,D*/   {
/*MT6129C,D*/      case  FrequencyBand850 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=197)
/*MT6129C,D*/         {  if(arfcn<=147)
/*MT6129C,D*/            {  if(arfcn<=138)
/*MT6129C,D*/               {                                /* ARFCN : 128~138     */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-128)+3848;
/*MT6129C,D*/                  *rfN = (5L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else
/*MT6129C,D*/               {                                /* ARFCN : 139~147     */
/*MT6129C,D*/                  Nfrac = 90*(arfcn-139)+2680;
/*MT6129C,D*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {                                   /* ARFCN : 148~197     */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-148)+408;
/*MT6129C,D*/                  *rfN = (6L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=206)
/*MT6129C,D*/            {                                   /* ARFCN : 198~206   */
/*MT6129C,D*/                  Nfrac = 90*(arfcn-198)+2790;
/*MT6129C,D*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {                                   /* ARFCN : 207~251 */
/*MT6129C,D*/                  Nfrac = 88*(arfcn-207)+400;
/*MT6129C,D*/                  *rfN = (7L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=104)
/*MT6129C,D*/         {  if(arfcn<=45)
/*MT6129C,D*/            {  if(arfcn<=36)                     /* ARFCN : 0~36       */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-0)+1600;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 37~45     */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-37)+3430;
/*MT6129C,D*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=95)                    /* ARFCN : 46~95     */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-46)+448;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 96~104    */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-96)+3540;
/*MT6129C,D*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=1001)
/*MT6129C,D*/            {  if(arfcn<=124)                   /* ARFCN : 105~124   */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-105)+440;
/*MT6129C,D*/                  *rfN = (13L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 975~1001  */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-975)+2488;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=1010)                  /* ARFCN : 1002~1010 */
/*MT6129C,D*/               {  Nfrac = 90*(arfcn-1002)+3320;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 1011~1023 */
/*MT6129C,D*/               {  Nfrac = 88*(arfcn-1011)+456;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1800 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=715)
/*MT6129C,D*/         {  if(arfcn<=597)
/*MT6129C,D*/            {  if(arfcn<=579)                   /* ARFCN : 512~579   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-512)+1844;
/*MT6129C,D*/                  *rfN = (8L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 580~597   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-580)+3055;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else
/*MT6129C,D*/            {  if(arfcn<=697)                   /* ARFCN : 598~697   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-598)+428;
/*MT6129C,D*/                  *rfN = (9L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 698~715   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-698)+3165;
/*MT6129C,D*/                  *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=833)
/*MT6129C,D*/            {  if(arfcn<=815)                   /* ARFCN : 716~815   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-716)+420;
/*MT6129C,D*/                  *rfN = (10L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/               }
/*MT6129C,D*/               else                             /* ARFCN : 816~833   */
/*MT6129C,D*/               {  Nfrac = 45*(arfcn-816)+3275;
/*MT6129C,D*/                  *rfN = (12L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 834~885   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-834)+412;
/*MT6129C,D*/               *rfN = (11L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      case  FrequencyBand1900 :
/*MT6129C,D*/      {
/*MT6129C,D*/         if(arfcn<=706)
/*MT6129C,D*/         {  if(arfcn<=606)
/*MT6129C,D*/            {  if(arfcn<=588)                /* ARFCN : 512~588   */
/*MT6129C,D*/               {  Nfrac = 44*(arfcn-512)+1444;
/*MT6129C,D*/                  *rfN = (14L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 1;
/*MT6129C,D*/              }
/*MT6129C,D*/              else
/*MT6129C,D*/              {  Nfrac = 45*(arfcn-589)+3760;  /* ARFCN : 589~606   */
/*MT6129C,D*/                  *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/                  mt6119_d_flag = 0;
/*MT6129C,D*/               }
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 607~706   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-607)+424;
/*MT6129C,D*/               *rfN = (15L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         else
/*MT6129C,D*/         {  if(arfcn<=724)                      /* ARFCN : 707~724   */
/*MT6129C,D*/              {  Nfrac = 45*(arfcn-707)+3870;
/*MT6129C,D*/               *rfN = (17L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 0;
/*MT6129C,D*/            }
/*MT6129C,D*/            else                                /* ARFCN : 725~810   */
/*MT6129C,D*/            {  Nfrac = 44*(arfcn-725)+416;
/*MT6129C,D*/               *rfN = (16L<<17) | (Nfrac<<4) | 0x800001L;
/*MT6129C,D*/               mt6119_d_flag = 1;
/*MT6129C,D*/            }
/*MT6129C,D*/         }
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/      default :
/*MT6129C,D*/      {
/*MT6129C,D*/         break;
/*MT6129C,D*/      }
/*MT6129C,D*/   }
/*MT6129C,D*/   *ifN = 0;
/*MT6129C,D*/}
#endif

/*=========================================================================================*/
#if  (IS_RF_MT6139B)
/*MT6139B*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139B*/{  
/*MT6139B*/   switch(rf_band)
/*MT6139B*/   {
/*MT6139B*/      case  FrequencyBand850 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=201)
/*MT6139B*/         {  if(arfcn<=136)
/*MT6139B*/            {                                /* ARFCN : 128~136     */
/*MT6139B*/             //   Nfrac = (arfcn-128)<<1+112;
/*MT6139B*/             //   *rfN = (66L<<12) | (Nfrac<<4) | 0x00001L;
/*MT6139B*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 137~201     */
/*MT6139B*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {                                 /* ARFCN : 202~251     */
/*MT6139B*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=69)
/*MT6139B*/         {  if(arfcn<=4)
/*MT6139B*/            {                                /* ARFCN : 0~4     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 5~69     */
/*MT6139B*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {  if(arfcn<=124)
/*MT6139B*/            {                                /* ARFCN : 70~124     */
/*MT6139B*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 975~1023     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139B*/            }   
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1800 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=715)
/*MT6139B*/         {  if(arfcn<=585)
/*MT6139B*/            {                                /* ARFCN : 512~585     */
/*MT6139B*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 586~715     */
/*MT6139B*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {  if(arfcn<=845)
/*MT6139B*/            {                                /* ARFCN : 716~845     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 846~885     */
/*MT6139B*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139B*/            }   
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=740)
/*MT6139B*/         {  if(arfcn<=610)
/*MT6139B*/            {                                /* ARFCN : 512~610     */
/*MT6139B*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                               /* ARFCN : 611~740     */
/*MT6139B*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {    
/*MT6139B*/                                            /* ARFCN : 741~810     */
/*MT6139B*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139B*/              
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      default :
/*MT6139B*/      {
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/   }
/*MT6139B*/   *ifN = 0;
/*MT6139B*/}
/*MT6139B*//* =========================================================================== */
/*MT6139B*/
/*MT6139B*/
/*MT6139B*/
/*MT6139B*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139B*/{  
/*MT6139B*/   switch(rf_band)
/*MT6139B*/   {
/*MT6139B*/      case  FrequencyBand850 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=231)
/*MT6139B*/         {  if(arfcn<=166)
/*MT6139B*/            {                                /* ARFCN : 128~166     */
/*MT6139B*/             //   Nfrac = (arfcn-128)<<1+52;
/*MT6139B*/             //   *rfN = (63L<<12) | (Nfrac<<4) | 0x80001L;
/*MT6139B*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 167~231     */
/*MT6139B*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {                                 /* ARFCN : 232~251     */
/*MT6139B*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=124)
/*MT6139B*/         {  if(arfcn<=99)
/*MT6139B*/            {  if(arfcn<=34)
/*MT6139B*/               {                                /* ARFCN : 0~34     */
/*MT6139B*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/               }
/*MT6139B*/               else
/*MT6139B*/               {                                /* ARFCN : 35~99     */
/*MT6139B*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/               }
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 100~124     */
/*MT6139B*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {  if(arfcn<=993)
/*MT6139B*/            {                                /* ARFCN : 975~993     */
/*MT6139B*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 994~1023     */
/*MT6139B*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x180001L; /* 0x080001L; */
/*MT6139B*/            }   
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1800 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=670)
/*MT6139B*/         {  if(arfcn<=540)
/*MT6139B*/            {                                /* ARFCN : 512~540     */
/*MT6139B*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 541~670     */
/*MT6139B*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {  if(arfcn<=800)
/*MT6139B*/            {                                /* ARFCN : 671~800     */
/*MT6139B*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                              /* ARFCN : 801~885     */
/*MT6139B*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x200001L; /* 0x280001L; */
/*MT6139B*/            }   
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      case  FrequencyBand1900 :
/*MT6139B*/      {
/*MT6139B*/         if(arfcn<=750)
/*MT6139B*/         {  if(arfcn<=620)
/*MT6139B*/            {                                /* ARFCN : 512~620     */
/*MT6139B*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x300001L; /* 0x380001L; */
/*MT6139B*/            }   
/*MT6139B*/            else   
/*MT6139B*/            {                               /* ARFCN : 621~750     */
/*MT6139B*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x300001L; /* 0x380001L; */
/*MT6139B*/            }   
/*MT6139B*/         }      
/*MT6139B*/         else   
/*MT6139B*/         {    
/*MT6139B*/                                            /* ARFCN : 751~810     */
/*MT6139B*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x300001L; /* 0x380001L; */
/*MT6139B*/              
/*MT6139B*/         }
/*MT6139B*/         
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/      default :
/*MT6139B*/      {
/*MT6139B*/         break;
/*MT6139B*/      }
/*MT6139B*/   }
/*MT6139B*/   *ifN = 0;
/*MT6139B*/}
#endif

/*=========================================================================================*/

#if  IS_RF_MT6139C
/*MT6139C*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139C*/{  
/*MT6139C*/   switch(rf_band)
/*MT6139C*/   {
/*MT6139C*/      case  FrequencyBand850 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=201)
/*MT6139C*/         {  if(arfcn<=136)
/*MT6139C*/            {                                /* ARFCN : 128~136     */
/*MT6139C*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 137~201     */
/*MT6139C*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {                                 /* ARFCN : 202~251     */
/*MT6139C*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=69)
/*MT6139C*/         {  if(arfcn<=4)
/*MT6139C*/            {                                /* ARFCN : 0~4     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 5~69     */
/*MT6139C*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {  if(arfcn<=124)
/*MT6139C*/            {                                /* ARFCN : 70~124     */
/*MT6139C*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 975~1023     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139C*/            }   
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1800 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=715)
/*MT6139C*/         {  if(arfcn<=585)
/*MT6139C*/            {                                /* ARFCN : 512~585     */
/*MT6139C*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 586~715     */
/*MT6139C*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {  if(arfcn<=845)
/*MT6139C*/            {                                /* ARFCN : 716~845     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 846~885     */
/*MT6139C*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139C*/            }   
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=740)
/*MT6139C*/         {  if(arfcn<=610)
/*MT6139C*/            {                                /* ARFCN : 512~610     */
/*MT6139C*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                               /* ARFCN : 611~740     */
/*MT6139C*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {    
/*MT6139C*/                                            /* ARFCN : 741~810     */
/*MT6139C*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139C*/              
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      default :
/*MT6139C*/      {
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/   }
/*MT6139C*/   *ifN = 0;
/*MT6139C*/}
/*MT6139C*//* =========================================================================== */
/*MT6139C*/
/*MT6139C*/
/*MT6139C*/
/*MT6139C*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139C*/{  
/*MT6139C*/   switch(rf_band)
/*MT6139C*/   {
/*MT6139C*/      case  FrequencyBand850 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=231)
/*MT6139C*/         {  if(arfcn<=166)
/*MT6139C*/            {                                /* ARFCN : 128~166     */
/*MT6139C*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 167~231     */
/*MT6139C*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {                                 /* ARFCN : 232~251     */
/*MT6139C*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=124)
/*MT6139C*/         {  if(arfcn<=99)
/*MT6139C*/            {  if(arfcn<=34)
/*MT6139C*/               {                                /* ARFCN : 0~34     */
/*MT6139C*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/               }
/*MT6139C*/               else
/*MT6139C*/               {                                /* ARFCN : 35~99     */
/*MT6139C*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/               }
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 100~124     */
/*MT6139C*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {  if(arfcn<=993)
/*MT6139C*/            {                                /* ARFCN : 975~993     */
/*MT6139C*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 994~1023     */
/*MT6139C*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6139C*/            }   
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1800 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=670)
/*MT6139C*/         {  if(arfcn<=540)
/*MT6139C*/            {                                /* ARFCN : 512~540     */
/*MT6139C*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 541~670     */
/*MT6139C*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {  if(arfcn<=800)
/*MT6139C*/            {                                /* ARFCN : 671~800     */
/*MT6139C*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                              /* ARFCN : 801~885     */
/*MT6139C*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139C*/            }   
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      case  FrequencyBand1900 :
/*MT6139C*/      {
/*MT6139C*/         if(arfcn<=750)
/*MT6139C*/         {  if(arfcn<=620)
/*MT6139C*/            {                                /* ARFCN : 512~620     */
/*MT6139C*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139C*/            }   
/*MT6139C*/            else   
/*MT6139C*/            {                               /* ARFCN : 621~750     */
/*MT6139C*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139C*/            }   
/*MT6139C*/         }      
/*MT6139C*/         else   
/*MT6139C*/         {    
/*MT6139C*/                                            /* ARFCN : 751~810     */
/*MT6139C*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139C*/              
/*MT6139C*/         }
/*MT6139C*/         
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/      default :
/*MT6139C*/      {
/*MT6139C*/         break;
/*MT6139C*/      }
/*MT6139C*/   }
/*MT6139C*/   *ifN = 0;
/*MT6139C*/}
#endif

/*=========================================================================================*/

#if  IS_RF_MT6139E
/*MT6139E*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139E*/{  
/*MT6139E*/   switch(rf_band)
/*MT6139E*/   {
/*MT6139E*/      case  FrequencyBand850 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=201)
/*MT6139E*/         {  if(arfcn<=136)
/*MT6139E*/            {                                /* ARFCN : 128~136     */
/*MT6139E*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x400001L;
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 137~201     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x400001L;
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {                                 /* ARFCN : 202~251     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x400001L;
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *rfN |= 0x100000L;
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=69)
/*MT6139E*/         {  if(arfcn<=4)
/*MT6139E*/            {                                /* ARFCN : 0~4     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 5~69     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {  if(arfcn<=124)
/*MT6139E*/            {                                /* ARFCN : 70~124     */
/*MT6139E*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 975~1023     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6139E*/            }   
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *rfN &= (~(0x100000L));
/*MT6139E*/
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1800 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=715)
/*MT6139E*/         {  if(arfcn<=585)
/*MT6139E*/            {                                /* ARFCN : 512~585     */
/*MT6139E*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 586~715     */
/*MT6139E*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {  if(arfcn<=845)
/*MT6139E*/            {                                /* ARFCN : 716~845     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 846~885     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6139E*/            }   
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *rfN |= 0x100000L;
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=740)
/*MT6139E*/         {  if(arfcn<=610)
/*MT6139E*/            {                                /* ARFCN : 512~610     */
/*MT6139E*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                               /* ARFCN : 611~740     */
/*MT6139E*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {    
/*MT6139E*/                                            /* ARFCN : 741~810     */
/*MT6139E*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6139E*/              
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MT6139E*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *rfN &= (~(0x100000L));
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      default :
/*MT6139E*/      {
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/   }
/*MT6139E*/   *ifN = 0;
/*MT6139E*/}
/*MT6139E*//* =========================================================================== */
/*MT6139E*/
/*MT6139E*/
/*MT6139E*/
/*MT6139E*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6139E*/{  
/*MT6139E*/   switch(rf_band)
/*MT6139E*/   {
/*MT6139E*/      case  FrequencyBand850 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=231)
/*MT6139E*/         {  if(arfcn<=166)
/*MT6139E*/            {                                /* ARFCN : 128~166     */
/*MT6139E*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 167~231     */
/*MT6139E*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {                                 /* ARFCN : 232~251     */
/*MT6139E*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x080001L; /* 0x080001L; */
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=124)
/*MT6139E*/         {  if(arfcn<=99)
/*MT6139E*/            {  if(arfcn<=34)
/*MT6139E*/               {                                /* ARFCN : 0~34     */
/*MT6139E*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/               }
/*MT6139E*/               else
/*MT6139E*/               {                                /* ARFCN : 35~99     */
/*MT6139E*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/               }
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 100~124     */
/*MT6139E*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {  if(arfcn<=993)
/*MT6139E*/            {                                /* ARFCN : 975~993     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x180001L; /* 0x180001L; */
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 994~1023     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x180001L; /* 0x080001L; */
/*MT6139E*/            }   
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1800 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=670)
/*MT6139E*/         {  if(arfcn<=540)
/*MT6139E*/            {                                /* ARFCN : 512~540     */
/*MT6139E*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 541~670     */
/*MT6139E*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {  if(arfcn<=800)
/*MT6139E*/            {                                /* ARFCN : 671~800     */
/*MT6139E*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                              /* ARFCN : 801~885     */
/*MT6139E*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6139E*/            }   
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      case  FrequencyBand1900 :
/*MT6139E*/      {
/*MT6139E*/         if(arfcn<=750)
/*MT6139E*/         {  if(arfcn<=620)
/*MT6139E*/            {                                /* ARFCN : 512~620     */
/*MT6139E*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/            }   
/*MT6139E*/            else   
/*MT6139E*/            {                               /* ARFCN : 621~750     */
/*MT6139E*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/            }   
/*MT6139E*/         }      
/*MT6139E*/         else   
/*MT6139E*/         {    
/*MT6139E*/                                            /* ARFCN : 751~810     */
/*MT6139E*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6139E*/              
/*MT6139E*/         }
/*MT6139E*/         
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/      default :
/*MT6139E*/      {
/*MT6139E*/         break;
/*MT6139E*/      }
/*MT6139E*/   }
/*MT6139E*/   *ifN = 0;
/*MT6139E*/}
#endif
/*=========================================================================================*/

#if  IS_RF_MT6140A
/*MT6140A*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140A*/{  
/*MT6140A*/   switch(rf_band)
/*MT6140A*/   {
/*MT6140A*/      case  FrequencyBand850 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=201)
/*MT6140A*/         {  if(arfcn<=136)
/*MT6140A*/            {                                /* ARFCN : 128~136     */
/*MT6140A*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 137~201     */
/*MT6140A*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {                                 /* ARFCN : 202~251     */
/*MT6140A*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=69)
/*MT6140A*/         {  if(arfcn<=4)
/*MT6140A*/            {                                /* ARFCN : 0~4     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 5~69     */
/*MT6140A*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {  if(arfcn<=124)
/*MT6140A*/            {                                /* ARFCN : 70~124     */
/*MT6140A*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 975~1023     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140A*/            }   
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1800 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=715)
/*MT6140A*/         {  if(arfcn<=585)
/*MT6140A*/            {                                /* ARFCN : 512~585     */
/*MT6140A*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 586~715     */
/*MT6140A*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {  if(arfcn<=845)
/*MT6140A*/            {                                /* ARFCN : 716~845     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 846~885     */
/*MT6140A*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140A*/            }   
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=740)
/*MT6140A*/         {  if(arfcn<=610)
/*MT6140A*/            {                                /* ARFCN : 512~610     */
/*MT6140A*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                               /* ARFCN : 611~740     */
/*MT6140A*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {    
/*MT6140A*/                                            /* ARFCN : 741~810     */
/*MT6140A*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140A*/              
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      default :
/*MT6140A*/      {
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/   }
/*MT6140A*/   *ifN = 0;
/*MT6140A*/}
/*MT6140A*//* =========================================================================== */
/*MT6140A*/
/*MT6140A*/
/*MT6140A*/
/*MT6140A*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140A*/{  
/*MT6140A*/   switch(rf_band)
/*MT6140A*/   {
/*MT6140A*/      case  FrequencyBand850 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=231)
/*MT6140A*/         {  if(arfcn<=166)
/*MT6140A*/            {                                /* ARFCN : 128~166     */
/*MT6140A*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 167~231     */
/*MT6140A*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {                                 /* ARFCN : 232~251     */
/*MT6140A*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=124)
/*MT6140A*/         {  if(arfcn<=99)
/*MT6140A*/            {  if(arfcn<=34)
/*MT6140A*/               {                                /* ARFCN : 0~34     */
/*MT6140A*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/               }
/*MT6140A*/               else
/*MT6140A*/               {                                /* ARFCN : 35~99     */
/*MT6140A*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/               }
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 100~124     */
/*MT6140A*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {  if(arfcn<=993)
/*MT6140A*/            {                                /* ARFCN : 975~993     */
/*MT6140A*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 994~1023     */
/*MT6140A*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140A*/            }   
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1800 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=670)
/*MT6140A*/         {  if(arfcn<=540)
/*MT6140A*/            {                                /* ARFCN : 512~540     */
/*MT6140A*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 541~670     */
/*MT6140A*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {  if(arfcn<=800)
/*MT6140A*/            {                                /* ARFCN : 671~800     */
/*MT6140A*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                              /* ARFCN : 801~885     */
/*MT6140A*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x600001L; /* 0x280001L; */
/*MT6140A*/            }   
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      case  FrequencyBand1900 :
/*MT6140A*/      {
/*MT6140A*/         if(arfcn<=750)
/*MT6140A*/         {  if(arfcn<=620)
/*MT6140A*/            {                                /* ARFCN : 512~620     */
/*MT6140A*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x700001L; /* 0x380001L; */
/*MT6140A*/            }   
/*MT6140A*/            else   
/*MT6140A*/            {                               /* ARFCN : 621~750     */
/*MT6140A*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x700001L; /* 0x380001L; */
/*MT6140A*/            }   
/*MT6140A*/         }      
/*MT6140A*/         else   
/*MT6140A*/         {    
/*MT6140A*/                                            /* ARFCN : 751~810     */
/*MT6140A*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x700001L; /* 0x380001L; */
/*MT6140A*/              
/*MT6140A*/         }
/*MT6140A*/         
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/      default :
/*MT6140A*/      {
/*MT6140A*/         break;
/*MT6140A*/      }
/*MT6140A*/   }
/*MT6140A*/   *ifN = 0;
/*MT6140A*/}
#endif
/*=========================================================================================*/

#if  IS_RF_MT6140B
/*MT6140B*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140B*/{  
/*MT6140B*/   switch(rf_band)
/*MT6140B*/   {
/*MT6140B*/      case  FrequencyBand850 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=201)
/*MT6140B*/         {  if(arfcn<=136)
/*MT6140B*/            {                                /* ARFCN : 128~136     */
/*MT6140B*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 137~201     */
/*MT6140B*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {                                 /* ARFCN : 202~251     */
/*MT6140B*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=69)
/*MT6140B*/         {  if(arfcn<=4)
/*MT6140B*/            {                                /* ARFCN : 0~4     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 5~69     */
/*MT6140B*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {  if(arfcn<=124)
/*MT6140B*/            {                                /* ARFCN : 70~124     */
/*MT6140B*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 975~1023     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140B*/            }   
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1800 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=715)
/*MT6140B*/         {  if(arfcn<=585)
/*MT6140B*/            {                                /* ARFCN : 512~585     */
/*MT6140B*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 586~715     */
/*MT6140B*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {  if(arfcn<=845)
/*MT6140B*/            {                                /* ARFCN : 716~845     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 846~885     */
/*MT6140B*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140B*/            }   
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=740)
/*MT6140B*/         {  if(arfcn<=610)
/*MT6140B*/            {                                /* ARFCN : 512~610     */
/*MT6140B*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                               /* ARFCN : 611~740     */
/*MT6140B*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {    
/*MT6140B*/                                            /* ARFCN : 741~810     */
/*MT6140B*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140B*/              
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      default :
/*MT6140B*/      {
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/   }
/*MT6140B*/   *ifN = 0;
/*MT6140B*/}
/*MT6140B*//* =========================================================================== */
/*MT6140B*/
/*MT6140B*/
/*MT6140B*/
/*MT6140B*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140B*/{  
/*MT6140B*/   switch(rf_band)
/*MT6140B*/   {
/*MT6140B*/      case  FrequencyBand850 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=231)
/*MT6140B*/         {  if(arfcn<=166)
/*MT6140B*/            {                                /* ARFCN : 128~166     */
/*MT6140B*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 167~231     */
/*MT6140B*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {                                 /* ARFCN : 232~251     */
/*MT6140B*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=124)
/*MT6140B*/         {  if(arfcn<=99)
/*MT6140B*/            {  if(arfcn<=34)
/*MT6140B*/               {                                /* ARFCN : 0~34     */
/*MT6140B*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/               }
/*MT6140B*/               else
/*MT6140B*/               {                                /* ARFCN : 35~99     */
/*MT6140B*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/               }
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 100~124     */
/*MT6140B*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {  if(arfcn<=993)
/*MT6140B*/            {                                /* ARFCN : 975~993     */
/*MT6140B*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 994~1023     */
/*MT6140B*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140B*/            }   
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1800 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=670)
/*MT6140B*/         {  if(arfcn<=540)
/*MT6140B*/            {                                /* ARFCN : 512~540     */
/*MT6140B*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 541~670     */
/*MT6140B*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {  if(arfcn<=800)
/*MT6140B*/            {                                /* ARFCN : 671~800     */
/*MT6140B*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                              /* ARFCN : 801~885     */
/*MT6140B*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140B*/            }   
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      case  FrequencyBand1900 :
/*MT6140B*/      {
/*MT6140B*/         if(arfcn<=750)
/*MT6140B*/         {  if(arfcn<=620)
/*MT6140B*/            {                                /* ARFCN : 512~620     */
/*MT6140B*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140B*/            }   
/*MT6140B*/            else   
/*MT6140B*/            {                               /* ARFCN : 621~750     */
/*MT6140B*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140B*/            }   
/*MT6140B*/         }      
/*MT6140B*/         else   
/*MT6140B*/         {    
/*MT6140B*/                                            /* ARFCN : 751~810     */
/*MT6140B*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140B*/              
/*MT6140B*/         }
/*MT6140B*/         
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/      default :
/*MT6140B*/      {
/*MT6140B*/         break;
/*MT6140B*/      }
/*MT6140B*/   }
/*MT6140B*/   *ifN = 0;
/*MT6140B*/}
#endif
/*=========================================================================================*/
/*=========================================================================================*/

#if  IS_RF_MT6140C
/*MT6140C*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140C*/{  
/*MT6140C*/   switch(rf_band)
/*MT6140C*/   {
/*MT6140C*/      case  FrequencyBand850 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=201)
/*MT6140C*/         {  if(arfcn<=136)
/*MT6140C*/            {                                /* ARFCN : 128~136     */
/*MT6140C*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 137~201     */
/*MT6140C*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {                                 /* ARFCN : 202~251     */
/*MT6140C*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=69)
/*MT6140C*/         {  if(arfcn<=4)
/*MT6140C*/            {                                /* ARFCN : 0~4     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 5~69     */
/*MT6140C*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {  if(arfcn<=124)
/*MT6140C*/            {                                /* ARFCN : 70~124     */
/*MT6140C*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 975~1023     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140C*/            }   
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1800 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=715)
/*MT6140C*/         {  if(arfcn<=585)
/*MT6140C*/            {                                /* ARFCN : 512~585     */
/*MT6140C*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 586~715     */
/*MT6140C*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {  if(arfcn<=845)
/*MT6140C*/            {                                /* ARFCN : 716~845     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 846~885     */
/*MT6140C*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140C*/            }   
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=740)
/*MT6140C*/         {  if(arfcn<=610)
/*MT6140C*/            {                                /* ARFCN : 512~610     */
/*MT6140C*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                               /* ARFCN : 611~740     */
/*MT6140C*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {    
/*MT6140C*/                                            /* ARFCN : 741~810     */
/*MT6140C*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140C*/              
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      default :
/*MT6140C*/      {
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/   }
/*MT6140C*/   *ifN = 0;
/*MT6140C*/}
/*MT6140C*//* =========================================================================== */
/*MT6140C*/
/*MT6140C*/
/*MT6140C*/
/*MT6140C*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140C*/{  
/*MT6140C*/   switch(rf_band)
/*MT6140C*/   {
/*MT6140C*/      case  FrequencyBand850 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=231)
/*MT6140C*/         {  if(arfcn<=166)
/*MT6140C*/            {                                /* ARFCN : 128~166     */
/*MT6140C*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 167~231     */
/*MT6140C*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {                                 /* ARFCN : 232~251     */
/*MT6140C*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=124)
/*MT6140C*/         {  if(arfcn<=99)
/*MT6140C*/            {  if(arfcn<=34)
/*MT6140C*/               {                                /* ARFCN : 0~34     */
/*MT6140C*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/               }
/*MT6140C*/               else
/*MT6140C*/               {                                /* ARFCN : 35~99     */
/*MT6140C*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/               }
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 100~124     */
/*MT6140C*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {  if(arfcn<=993)
/*MT6140C*/            {                                /* ARFCN : 975~993     */
/*MT6140C*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 994~1023     */
/*MT6140C*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140C*/            }   
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1800 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=670)
/*MT6140C*/         {  if(arfcn<=540)
/*MT6140C*/            {                                /* ARFCN : 512~540     */
/*MT6140C*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 541~670     */
/*MT6140C*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {  if(arfcn<=800)
/*MT6140C*/            {                                /* ARFCN : 671~800     */
/*MT6140C*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                              /* ARFCN : 801~885     */
/*MT6140C*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140C*/            }   
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      case  FrequencyBand1900 :
/*MT6140C*/      {
/*MT6140C*/         if(arfcn<=750)
/*MT6140C*/         {  if(arfcn<=620)
/*MT6140C*/            {                                /* ARFCN : 512~620     */
/*MT6140C*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140C*/            }   
/*MT6140C*/            else   
/*MT6140C*/            {                               /* ARFCN : 621~750     */
/*MT6140C*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140C*/            }   
/*MT6140C*/         }      
/*MT6140C*/         else   
/*MT6140C*/         {    
/*MT6140C*/                                            /* ARFCN : 751~810     */
/*MT6140C*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140C*/              
/*MT6140C*/         }
/*MT6140C*/         
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/      default :
/*MT6140C*/      {
/*MT6140C*/         break;
/*MT6140C*/      }
/*MT6140C*/   }
/*MT6140C*/   *ifN = 0;
/*MT6140C*/}
#endif
/*=========================================================================================*/

#if  IS_RF_MT6140D
/*MT6140D*/void  L1D_RF_GetRxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140D*/{  
/*MT6140D*/   switch(rf_band)
/*MT6140D*/   {
/*MT6140D*/      case  FrequencyBand850 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=201)
/*MT6140D*/         {  if(arfcn<=136)
/*MT6140D*/            {                                /* ARFCN : 128~136     */
/*MT6140D*/                *rfN = (66L<<12) | ((arfcn-72)<<5) | 0x000001L;
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 137~201     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-137)<<5) | 0x000001L;
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {                                 /* ARFCN : 202~251     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-202)<<5) | 0x000001L;
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         // Get GSM850 signal from GSM900 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap ) *rfN |= 0x100000L;
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=69)
/*MT6140D*/         {  if(arfcn<=4)
/*MT6140D*/            {                                /* ARFCN : 0~4     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn+60)<<5) | 0x100001L;
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 5~69     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-5)<<5) | 0x100001L;
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {  if(arfcn<=124)
/*MT6140D*/            {                                /* ARFCN : 70~124     */
/*MT6140D*/                *rfN = (73L<<12) | ((arfcn-70)<<5) | 0x100001L;
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 975~1023     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-964)<<5) | 0x100001L;
/*MT6140D*/            }   
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         // Get GSM900 signal from GSM850 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_gsm850_gsm900_swap )  *rfN &= (~(0x100000L));
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1800 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=715)
/*MT6140D*/         {  if(arfcn<=585)
/*MT6140D*/            {                                /* ARFCN : 512~585     */
/*MT6140D*/                *rfN = (69L<<12) | ((arfcn-456)<<4) | 0x200001L;
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 586~715     */
/*MT6140D*/                *rfN = (70L<<12) | ((arfcn-586)<<4) | 0x200001L;
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {  if(arfcn<=845)
/*MT6140D*/            {                                /* ARFCN : 716~845     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-716)<<4) | 0x200001L;
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 846~885     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-846)<<4) | 0x200001L;
/*MT6140D*/            }   
/*MT6140D*/         }
/*MT6140D*/
/*MT6140D*/         // Get PCS1900 signal from DCS1800 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap ) *rfN |= 0x100000L;         
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=740)
/*MT6140D*/         {  if(arfcn<=610)
/*MT6140D*/            {                                /* ARFCN : 512~610     */
/*MT6140D*/                *rfN = (74L<<12) | ((arfcn-481)<<4) | 0x300001L;
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                               /* ARFCN : 611~740     */
/*MT6140D*/                *rfN = (75L<<12) | ((arfcn-611)<<4) | 0x300001L;
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {    
/*MT6140D*/                                            /* ARFCN : 741~810     */
/*MT6140D*/            *rfN = (76L<<12) | ((arfcn-741)<<4) | 0x300001L;
/*MT6140D*/              
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         // Get DCS1800 signal from PCS1900 input pins if flag=1
/*MT6140D*/         if( BBTXParameters.bbrx_dcs1800_pcs1900_swap)  *rfN &= (~(0x100000L));
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      default :
/*MT6140D*/      {
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/   }
/*MT6140D*/   *ifN = 0;
/*MT6140D*/}
/*MT6140D*//* =========================================================================== */
/*MT6140D*/
/*MT6140D*/
/*MT6140D*/
/*MT6140D*/void  L1D_RF_GetTxPLLSetting( int rf_band, int arfcn, long *rfN, long *ifN )
/*MT6140D*/{  
/*MT6140D*/   switch(rf_band)
/*MT6140D*/   {
/*MT6140D*/      case  FrequencyBand850 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=231)
/*MT6140D*/         {  if(arfcn<=166)
/*MT6140D*/            {                                /* ARFCN : 128~166     */
/*MT6140D*/                *rfN = (63L<<12) | ((arfcn-102)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 167~231     */
/*MT6140D*/                *rfN = (64L<<12) | ((arfcn-167)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {                                 /* ARFCN : 232~251     */
/*MT6140D*/                *rfN = (65L<<12) | ((arfcn-232)<<5) | 0x480001L; /* 0x080001L; */
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=124)
/*MT6140D*/         {  if(arfcn<=99)
/*MT6140D*/            {  if(arfcn<=34)
/*MT6140D*/               {                                /* ARFCN : 0~34     */
/*MT6140D*/                   *rfN = (68L<<12) | ((arfcn+30)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/               }
/*MT6140D*/               else
/*MT6140D*/               {                                /* ARFCN : 35~99     */
/*MT6140D*/                   *rfN = (69L<<12) | ((arfcn-35)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/               }
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 100~124     */
/*MT6140D*/                *rfN = (70L<<12) | ((arfcn-100)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {  if(arfcn<=993)
/*MT6140D*/            {                                /* ARFCN : 975~993     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-929)<<5) | 0x580001L; /* 0x180001L; */
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 994~1023     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-994)<<5) | 0x580001L; /* 0x080001L; */
/*MT6140D*/            }   
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1800 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=670)
/*MT6140D*/         {  if(arfcn<=540)
/*MT6140D*/            {                                /* ARFCN : 512~540     */
/*MT6140D*/                *rfN = (65L<<12) | ((arfcn-411)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 541~670     */
/*MT6140D*/                *rfN = (66L<<12) | ((arfcn-541)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {  if(arfcn<=800)
/*MT6140D*/            {                                /* ARFCN : 671~800     */
/*MT6140D*/                *rfN = (67L<<12) | ((arfcn-671)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                              /* ARFCN : 801~885     */
/*MT6140D*/                *rfN = (68L<<12) | ((arfcn-801)<<4) | 0x680001L; /* 0x280001L; */
/*MT6140D*/            }   
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      case  FrequencyBand1900 :
/*MT6140D*/      {
/*MT6140D*/         if(arfcn<=750)
/*MT6140D*/         {  if(arfcn<=620)
/*MT6140D*/            {                                /* ARFCN : 512~620     */
/*MT6140D*/                *rfN = (71L<<12) | ((arfcn-491)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/            }   
/*MT6140D*/            else   
/*MT6140D*/            {                               /* ARFCN : 621~750     */
/*MT6140D*/                *rfN = (72L<<12) | ((arfcn-621)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/            }   
/*MT6140D*/         }      
/*MT6140D*/         else   
/*MT6140D*/         {    
/*MT6140D*/                                            /* ARFCN : 751~810     */
/*MT6140D*/            *rfN = (73L<<12) | ((arfcn-751)<<4) | 0x780001L; /* 0x380001L; */
/*MT6140D*/              
/*MT6140D*/         }
/*MT6140D*/         
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/      default :
/*MT6140D*/      {
/*MT6140D*/         break;
/*MT6140D*/      }
/*MT6140D*/   }
/*MT6140D*/   *ifN = 0;
/*MT6140D*/}
#endif
/*===========================================================================*/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

/*=========================================================================================*/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*=========================================================================================*/

#if IS_RF_GRF6201
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if IS_RF_IRFS3001
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
