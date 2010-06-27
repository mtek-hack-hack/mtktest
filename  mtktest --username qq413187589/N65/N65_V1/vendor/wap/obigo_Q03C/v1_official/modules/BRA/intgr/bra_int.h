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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * bra_int.h
 *
 * Created by Mats Tedenvall
 *
 * Revision  history:
 *
 */

#ifndef _bra_int_h
#define _bra_int_h

#ifndef _msf_def_h   
#include "msf_def.h"
#endif


#define BRA_ADDRTYPE_PHONENO    0x01
#define BRA_ADDRTYPE_IPV4       0x02
#define BRA_ADDRTYPE_TEXT       0x03


void
BRAa_stopBearerTimer(void);

int
BRAa_bearerCsdIsDisc(void);

void
BRAa_bearerDiscCsd(void);

void
BRAa_setBearerType(int net_id);

int
BRAa_getBearerType(void);

void
BRAa_setBearerState(int state);

int
BRAa_bearerInConn(void);

void
BRAa_userCancel(void);

void
BRAa_loadingComplete(void);

void
BRAa_setStatusIcon(void);

void
BRAa_setSecureIcon(int sec_class);

void
BRA_handleBearerInfo(void *p);

void
BRA_handleDAinfo(void *p);

#ifdef __SAT__

typedef enum
{
  BRA_SAT_LAUCH_SUCC,
  BRA_SAT_BRWOSER_BUSY,
  BRA_SAT_BEARER_UNAVAILABLE,
  BRA_SAT_PARAM_GATEWAY_ERROR,
  BRA_SAT_PARAM_URL_ERROR,
  BRA_SAT_PROV_DATA_ERROR
} bra_sat_lauch_res_enum;

typedef enum
{
  BRA_SAT_USER_TERMINATION,
  BRA_SAT_ERROR_TERMINATION
} bra_sat_browser_termination_mode_enum;

void
bra_send_lauch_rsp_to_mmi(MSF_UINT8 res);

void
bra_send_termination_to_mmi(MSF_UINT8 cause);

#endif /*__SAT__*/

#endif /*_bra_int_h*/


