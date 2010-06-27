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
**   Includes
*/

#include "kal_non_specific_general_types.h"
                                   
/*------ Basic time uint definition. Please do not change!! ------------------*/
#define KAL_TICKS_5_SEC             (1083)      /* 5 sec */
#define KAL_TICKS_30_SEC            (6500)      /* 30 sec */
#define KAL_TICKS_1_MIN             (13001)     /* 1 min */

#define RECOVER_TICKS_20_SEC    (KAL_TICKS_5_SEC+KAL_TICKS_5_SEC+KAL_TICKS_5_SEC+KAL_TICKS_5_SEC)
#define RECOVER_TICKS_30_SEC    (KAL_TICKS_30_SEC)
#define RECOVER_TICKS_1_MIN     (KAL_TICKS_1_MIN)
#define RECOVER_TICKS_2_MIN     (KAL_TICKS_1_MIN + KAL_TICKS_1_MIN)
/*------ End of Basic time uint definition. Please do not change!! ----------*/


/* -------------Adjustable definition and array value begins---------------- */
#define RECOVERY_TIMER_LEVEL  19  /* This value can be customized */

const kal_uint32 NORMAL_SERVICE_RECOVERY_TIMER_INTERVAL[RECOVERY_TIMER_LEVEL] =
{ RECOVER_TICKS_20_SEC, RECOVER_TICKS_20_SEC, RECOVER_TICKS_20_SEC,
  RECOVER_TICKS_20_SEC, RECOVER_TICKS_20_SEC, RECOVER_TICKS_20_SEC,
  RECOVER_TICKS_30_SEC, RECOVER_TICKS_30_SEC, RECOVER_TICKS_30_SEC,
  RECOVER_TICKS_30_SEC, RECOVER_TICKS_30_SEC, RECOVER_TICKS_30_SEC,
  RECOVER_TICKS_1_MIN,  RECOVER_TICKS_1_MIN,  RECOVER_TICKS_1_MIN, 
  RECOVER_TICKS_1_MIN,  RECOVER_TICKS_1_MIN,  RECOVER_TICKS_1_MIN,
  RECOVER_TICKS_2_MIN };

/*---------- End of adjustable definition and array value------------------*/
  
kal_uint8 rr_get_recovery_timer_level(void);

/*****************************************************************************
* FUNCTION
*  rr_get_recovery_timer_level
* DESCRIPTION
*   This function is used to define the recovery timer level number
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 rr_get_recovery_timer_level(void)
{
   return (RECOVERY_TIMER_LEVEL);
}  

