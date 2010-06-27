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
 *    eint_def.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for external interrupt channel.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "eint.h"

#ifdef __CUST_NEW__

#include "eint_drv.h"
extern const kal_uint8 AUX_EINT_NO;
extern const kal_uint8 CHRDET_EINT_NO;

#if defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__)
extern const kal_uint8 CLAMDET_EINT_NO;
#endif   /* __PHONE_CLAMSHELL__ || __PHONE_SLIDE__ */

#ifdef __USB_ENABLE__
extern const kal_uint8 USB_EINT_NO;
#else /* __USB_ENABLE__ */
extern const kal_uint8 USB_EINT_NO;
#endif   /* __USB_ENABLE__ */

#ifdef __BT_SUPPORT__
extern const kal_uint8 BT_EINT_NO;
#endif   /* __BT_SUPPORT__ */

#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
extern const kal_uint8 CHR_USB_EINT_NO;
#endif   /* __CHARGER_USB_DETECT_WIHT_ONE_EINT__ */

#ifdef __SWDBG_SUPPORT__
extern const kal_uint8 SWDBG_EINT_NO;
#endif   /* __SWDBG_SUPPORT__ */

#if defined(MOTION_SENSOR_SUPPORT)
extern const kal_uint8 MOTION_SENSOR_EINT_NO;
#endif   /* MOTION_SENSOR_SUPPORT */

#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
extern const kal_uint8 TOUCH_PANEL_EINT_NO;
#endif   /* TOUCH_PANEL_SUPPORT || HAND_WRITING */

#ifdef __WIFI_SUPPORT__
extern const kal_uint8 WIFI_EINT_NO;
#endif   /* __WIFI_SUPPORT__ */

#ifdef __EXTRA_A_B_KEY_SUPPORT__
extern const kal_uint8 EXTRA_A_KEY_EINT_NO;
extern const kal_uint8 EXTRA_B_KEY_EINT_NO;
#endif
#if defined(__DIRECTION_SENSOR_SUPPORT__)
/* 2009.04.14 added by hongzhe.liu for motion sensor + */
extern const unsigned char MOTION_SENSOR_EINT_NO1;
extern const unsigned char MOTION_SENSOR_EINT_NO2;
/* 2009.04.14 added by hongzhe.liu for motion sensor - */
#endif
#else /* __CUST_NEW__ */

const kal_uint8 AUX_EINT_NO = 0;
const kal_uint8 CHRDET_EINT_NO = EINT_CHANNEL_NOT_EXIST;

#if defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__)
const kal_uint8 CLAMDET_EINT_NO = 1;
#endif   /* __PHONE_CLAMSHELL__ || __PHONE_SLIDE__ */

#ifdef __USB_ENABLE__
const kal_uint8 USB_EINT_NO = 2;
#else /* __USB_ENABLE__ */
const kal_uint8 USB_EINT_NO = EINT_CHANNEL_NOT_EXIST;
#endif   /* __USB_ENABLE__ */

#ifdef __BT_SUPPORT__
const kal_uint8 BT_EINT_NO = 4;
#endif   /* __BT_SUPPORT__ */

#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
const kal_uint8 CHR_USB_EINT_NO = 2;
#endif   /* __CHARGER_USB_DETECT_WIHT_ONE_EINT__ */

#ifdef __SWDBG_SUPPORT__
const kal_uint8 SWDBG_EINT_NO = EINT_CHANNEL_NOT_EXIST;
#endif   /* __SWDBG_SUPPORT__ */

#if defined(MOTION_SENSOR_SUPPORT)
const kal_uint8 MOTION_SENSOR_EINT_NO = EINT_CHANNEL_NOT_EXIST; 
#endif   /* MOTION_SENSOR_SUPPORT */

#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
const kal_uint8 TOUCH_PANEL_EINT_NO = 2;
#endif   /* TOUCH_PANEL_SUPPORT || HAND_WRITING */

#ifdef __WIFI_SUPPORT__
const kal_uint8 WIFI_EINT_NO = 7;
#endif   /* __WIFI_SUPPORT__ */

#endif /* __CUST_NEW__ */

#ifdef __CUST_NEW__

/*Unit: 10ms*/
kal_uint8 custom_eint_sw_debounce_time_delay[EINT_MAX_CHANNEL] = 
{
   EINT0_DEBOUNCE_TIME_DELAY,
   EINT1_DEBOUNCE_TIME_DELAY,
   EINT2_DEBOUNCE_TIME_DELAY,
   EINT3_DEBOUNCE_TIME_DELAY
};

#else /* __CUST_NEW__ */

/*Unit: 10ms*/
kal_uint8 custom_eint_sw_debounce_time_delay[EINT_MAX_CHANNEL] = 
{
   50,   /*EINT 0,500ms*/
   0,   /*EINT 1,500ms*/
   50,    /*EINT 2,500ms*/
   50
};

#endif /* __CUST_NEW__ */

kal_uint8 *custom_config_eint_sw_debounce_time_delay()
{
   return custom_eint_sw_debounce_time_delay;
}

kal_uint8 custom_eint_get_channel(eint_channel_type type)
{
   switch(type)
   {
      case aux_eint_chann:
         return ((kal_uint8)AUX_EINT_NO);

      case chrdet_eint_chann:
         return ((kal_uint8)CHRDET_EINT_NO);

#if defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__)
      case clamdet_eint_chann:
         return ((kal_uint8)CLAMDET_EINT_NO);
#endif   /* __PHONE_CLAMSHELL__ || __PHONE_SLIDE__ */

      case usb_eint_chann:
         return ((kal_uint8)USB_EINT_NO);

#ifdef __BT_SUPPORT__
      case bt_eint_chann:
         return ((kal_uint8)BT_EINT_NO);
#endif   /* __BT_SUPPORT__ */

#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
      case chr_usb_eint_chann:
      	return ((kal_uint8)CHR_USB_EINT_NO);
#endif

#ifdef __SWDBG_SUPPORT__
      case swdbg_eint_chann:
         return SWDBG_EINT_NO;
#endif   /* __SWDBG_SUPPORT__ */

#if defined(MOTION_SENSOR_SUPPORT)
      case motion_senosr_eint_chann:
         return ((kal_uint8)MOTION_SENSOR_EINT_NO);
#endif   /* MOTION_SENSOR_SUPPORT */

#if defined(TOUCH_PANEL_SUPPORT) || defined(HAND_WRITING)
      case touch_panel_eint_chann:   
         return TOUCH_PANEL_EINT_NO;
#endif   /* TOUCH_PANEL_SUPPORT || HAND_WRITING */

#ifdef __WIFI_SUPPORT__
      case wifi_eint_chann:
         return WIFI_EINT_NO;
#endif   /* __SWDBG_SUPPORT__ */

#ifdef __EXTRA_A_B_KEY_SUPPORT__
      case extra_a_key_eint_chann:
         return EXTRA_A_KEY_EINT_NO;

      case extra_b_key_eint_chann:
         return EXTRA_B_KEY_EINT_NO;
#endif

#if defined(__DIRECTION_SENSOR_SUPPORT__)
/* 2009.04.14 added by hongzhe.liu for motion sensor + */
 case motion_senosr_eint1_chann:
         return MOTION_SENSOR_EINT_NO1;

 case motion_senosr_eint2_chann:
         return MOTION_SENSOR_EINT_NO2;
/* 2009.04.14 added by hongzhe.liu for motion sensor - */
#endif
      default:
         ASSERT(0);         
   }
   return 100;
}

