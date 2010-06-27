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
 * HardwareEvents.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * © 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : HardwareEvents.h

   PURPOSE     : struct, defines & globle variables

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : sep' 03, 2002

**************************************************************/

#ifndef _PIXCOM_HARDWARE_EVENT_H
#define _PIXCOM_HARDWARE_EVENT_H

/* hardware events */
#ifdef MMI_ON_WIN32
/*** Setting Messages *********/

//#define HW_SET_TIME_REQ                                                       551
//#define HW_SET_TIME_REQ_SUCCESS                                       552
#define HW_SET_TIME_REQ_FAILURE              553

//#define HW_SET_TIME_FORMAT_REQ                                        554
//#define HW_SET_TIME_FORMAT_REQ_SUCCESS                        555
#define HW_SET_TIME_FORMAT_REQ_FAILURE       556

//#define HW_SET_DATE_REQ                                                       560
//#define HW_SET_DATE_REQ_SUCCESS                                       561
#define HW_SET_DATE_REQ_FAILURE              562

//#define HW_SET_DATE_FORMAT_REQ                                        563
//#define HW_SET_DATE_FORMAT_REQ_SUCCESS                        564
#define HW_SET_DATE_FORMAT_REQ_FAILURE       565

//#define HW_SET_FIXED_DAIL_REQ                                 283
//#define HW_SET_FIXED_DAIL_RES                                 284

//#define HW_SET_BARRED_DIAL_REQ                                        286
//#define HW_SET_BARRED_DIAL_RES                                        287

//#define HW_SET_SIM_LOCK_REQ                                           289
//#define HW_SET_SIM_LOCK_RES                                           290

//#define HW_CHANGE_PASSWORD_REQ                                        291
//#define HW_CHANGE_PASSWORD_RES                                        292

//#define HW_AUTO_REDIAL_REQ                                            293
//#define HW_AUTO_REDIAL_RES                                            294
//#define HW_SET_PHONE_LOCK_REQ                                 293
//#define HW_SET_PHONE_LOCK_RES                                 294

#endif /* MMI_ON_WIN32 */ 

#endif /* _PIXCOM_HARDWARE_EVENT_H */ 

