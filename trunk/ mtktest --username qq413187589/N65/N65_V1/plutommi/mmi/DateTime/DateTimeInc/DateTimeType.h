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
 * Filename:
 * ---------
 * DateTimeType.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines structure for date/time related utility.
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
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : DateTimeType.h

   PURPOSE     : Contains structure 

   REMARKS     : nil

   AUTHOR      : Vijay Vaidya

   DATE     : .

**************************************************************/
#ifndef _MMI_DATETIMETYPE_H
#define _MMI_DATETIMETYPE_H
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
/* 
 * Define
 */

#define DOW(y,m,d) applib_dt_dow(y,m,d)
#define LastDayOfMonth(month,year)  applib_dt_last_day_of_mon(month, year)
#define DecrementTime(timeToDecrement,decrement,Result) \
   applib_dt_decrease_time((applib_time_struct *)&timeToDecrement, (applib_time_struct *)&decrement, (applib_time_struct *)Result)
#define CompareTime(referenceTime,compareTime,diff) \
   applib_dt_compare_time((applib_time_struct *)&referenceTime,(applib_time_struct *)&compareTime,(applib_time_struct *)diff)
#define IsLeapYear(year) applib_dt_is_leap_year(year)
#define mmi_dt_is_valid(t) applib_dt_is_valid((applib_time_struct *)t)
#define mmi_dt_utc_to_rtc(tz, utc,result) applib_dt_utc_to_rtc(tz,(applib_time_struct *)&utc,(applib_time_struct *)&result)
#define mmi_dt_mytime_2_utc_sec(currTime, daylightSaving) applib_dt_mytime_2_utc_sec((applib_time_struct *)currTime, daylightSaving)
#define mmi_dt_utc_sec_2_mytime(utc_sec,result, daylightSaving) applib_dt_utc_sec_2_mytime(utc_sec,(applib_time_struct *)result, daylightSaving)
#define mmi_dt_get_tz_string(result) applib_dt_get_tz_string(result)
#define mmi_dt_conv_utc_to_local(tz,utc_time) applib_dt_conv_utc_to_local(tz,utc_time)
#define mmi_dt_get_secure_time(t) applib_dt_get_secure_time((applib_time_struct *)t)
#define GetTimeDifference(t1, t2, result) \
   applib_get_time_difference((applib_time_struct *)t1, (applib_time_struct *)t2, (applib_time_struct *)result)
#define FindMaxTime(t1, t2) applib_find_max_time((applib_time_struct *)t1, (applib_time_struct *)t2)
#define DTGetRTCTime(t) applib_dt_get_rtc_time((applib_time_struct *)t)
#define GetDateTime(t) applib_dt_get_date_time((applib_time_struct *)t)
#define IncrementTime(t,increase,result)  applib_dt_increase_time((applib_time_struct *)&t, (applib_time_struct *)&increase, (applib_time_struct *)result)
#define InitTime()  applib_dt_init_time()
/* 
 * Typedef 
 */
/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#endif /* _MMI_DATETIMETYPE_H */ // #ifndef _MMI_DATETIMETYPE_H

