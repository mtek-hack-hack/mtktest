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
 *    Eint.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This files define external interrupt constants definition
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EINT_H__
#define __EINT_H__

#include "kal_release.h"

 /*************************************************************************
  * EINT Configuration
  *************************************************************************/
#define  LEVEL_HIGH           1
#define  LEVEL_LOW            0
   
#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )

#error "111111111111111111"
   #define  EINT_Base            0x80020050
   #define  EINT_MASK_EINT0      0x0001
   #define  EINT_MASK_EINT1      0x0002
   #define  EINT_MASK_EINT2      0x0004
   #define  EINT_MASK_EINT3      0x0008
   #define  EINT_MASK_EINT(_no)  (EINT_MASK_EINT0 << (_no))
   
   #define  EINT_INTACK_EINT0    0x0001
   #define  EINT_INTACK_EINT1    0x0002
   #define  EINT_INTACK_EINT2    0x0004
   #define  EINT_INTACK_EINT3    0x0008
   #define  EINT_INTACK_EINT(_no)  (EINT_INTACK_EINT0 << (_no))
   
   #define  EINT_STATUS_EINT0    0x0001
   #define  EINT_STATUS_EINT1    0x0002
   #define  EINT_STATUS_EINT2    0x0004
   #define  EINT_STATUS_EINT3    0x0008
   #define  EINT_STATUS_EINT(_no)  (EINT_STATUS_EINT0 << (_no))
   
   #define  EINT_CON_HIGHLEVEL   0x0800
   #define  EINT_CON_LOWLEVEL    0x0000
   #define  EINT_CON_DEBOUNCE    0x07ff
   #define  EINT_CON_DEBOUNCE_EN 0x8000
   
   #define  EINT_MAX_CHANNEL     3   
   #define  EINT_TOTAL_CHANNEL   3

   #define EINT_CHANNEL_NOT_EXIST 3

   #define EINTaddr(_no)  (*(volatile kal_uint16 *)(EINT_Base+(0x10*_no)))

#else


#if defined(MT6238)

   /* SHK: MT6238 here. */

   #define  EINT_Base            	   0x81010120
   #define  EINT_MASK_EINT0      0x0001
   #define  EINT_MASK_EINT1      0x0002
   #define  EINT_MASK_EINT2      0x0004
   #define  EINT_MASK_EINT3      0x0008
   #define  EINT_MASK_EINT4      0x0010
   #define  EINT_MASK_EINT5      0x0020
   #define  EINT_MASK_EINT6      0x0040
   #define  EINT_MASK_EINT7      0x0080
   #define  EINT_MASK_EINT8      0x0100
   #define  EINT_MASK_EINT9      0x0200
   #define  EINT_MASK_EINTA      0x0400
   #define  EINT_MASK_EINTB      0x0800
   #define  EINT_MASK_EINTC      0x1000
   #define  EINT_MASK_EINTD      0x2000   
   #define  EINT_MASK_EINT(_no)  (EINT_MASK_EINT0 << (_no))
   
   #define  EINT_INTACK_EINT0      0x0001
   #define  EINT_INTACK_EINT1      0x0002
   #define  EINT_INTACK_EINT2      0x0004
   #define  EINT_INTACK_EINT3      0x0008
   #define  EINT_INTACK_EINT4      0x0010
   #define  EINT_INTACK_EINT5      0x0020
   #define  EINT_INTACK_EINT6      0x0040
   #define  EINT_INTACK_EINT7      0x0080
   #define  EINT_INTACK_EINT8      0x0100
   #define  EINT_INTACK_EINT9      0x0200
   #define  EINT_INTACK_EINTA      0x0400
   #define  EINT_INTACK_EINTB      0x0800
   #define  EINT_INTACK_EINTC      0x1000
   #define  EINT_INTACK_EINTD      0x2000   
   #define  EINT_INTACK_EINT(_no)  (EINT_INTACK_EINT0 << (_no))
   
   #define  EINT_STATUS_EINT0      0x0001
   #define  EINT_STATUS_EINT1      0x0002
   #define  EINT_STATUS_EINT2      0x0004
   #define  EINT_STATUS_EINT3      0x0008
   #define  EINT_STATUS_EINT4      0x0010
   #define  EINT_STATUS_EINT5      0x0020
   #define  EINT_STATUS_EINT6      0x0040
   #define  EINT_STATUS_EINT7      0x0080
   #define  EINT_STATUS_EINT8      0x0100
   #define  EINT_STATUS_EINT9      0x0200
   #define  EINT_STATUS_EINTA      0x0400
   #define  EINT_STATUS_EINTB      0x0800
   #define  EINT_STATUS_EINTC      0x1000
   #define  EINT_STATUS_EINTD      0x2000   
   #define  EINT_STATUS_EINT(_no)  (EINT_STATUS_EINT0 << (_no))
   
   #define  EINT_CON_HIGHLEVEL   0x0800
   #define  EINT_CON_LOWLEVEL    0x0000
   #define  EINT_CON_DEBOUNCE    0x07ff   /*channel 4~7 doesn't have debounce mechanism*/
   #define  EINT_CON_DEBOUNCE_EN 0x8000
   
   #define EINTaddr(_no)  (*(volatile kal_uint16 *)(EINT_Base+(0x10*_no)))
   

#else
   //Huyanwei Touch Here
   #define  EINT_Base            0x80020120
   #define  EINT_MASK_EINT0      0x0001
   #define  EINT_MASK_EINT1      0x0002
   #define  EINT_MASK_EINT2      0x0004
   #define  EINT_MASK_EINT3      0x0008
   #if 1
   //Huyanwei Add It 
   #define  EINT_MASK_EINT4      0x0010
   #define  EINT_MASK_EINT5      0x0020
   #define  EINT_MASK_EINT6      0x0040
   #define  EINT_MASK_EINT7      0x0080
   #endif
   #define  EINT_MASK_EINT(_no)  (EINT_MASK_EINT0 << (_no))
   
   #define  EINT_INTACK_EINT0    0x0001
   #define  EINT_INTACK_EINT1    0x0002
   #define  EINT_INTACK_EINT2    0x0004
   #define  EINT_INTACK_EINT3    0x0008
   #if 1
   //Huyanwei Add It 
   #define  EINT_INTACK_EINT4    0x0010
   #define  EINT_INTACK_EINT5    0x0020
   #define  EINT_INTACK_EINT6    0x0040
   #define  EINT_INTACK_EINT7    0x0080
   #endif
   #define  EINT_INTACK_EINT(_no)  (EINT_INTACK_EINT0 << (_no))
   
   #define  EINT_STATUS_EINT0    0x0001
   #define  EINT_STATUS_EINT1    0x0002
   #define  EINT_STATUS_EINT2    0x0004
   #define  EINT_STATUS_EINT3    0x0008
   #if 1
   //Huyanwei Add It 
   #define  EINT_STATUS_EINT4    0x0010
   #define  EINT_STATUS_EINT5    0x0020
   #define  EINT_STATUS_EINT6    0x0040
   #define  EINT_STATUS_EINT7    0x0080
   #endif
   #define  EINT_STATUS_EINT(_no)  (EINT_STATUS_EINT0 << (_no))
   
   #define  EINT_CON_HIGHLEVEL   0x0800
   #define  EINT_CON_LOWLEVEL    0x0000
   #define  EINT_CON_DEBOUNCE    0x07ff   /*channel 4~7 doesn't have debounce mechanism*/
   #define  EINT_CON_DEBOUNCE_EN 0x8000
   
   #define EINTaddr(_no)  (*(volatile kal_uint16 *)(EINT_Base+(0x10*_no)))
#endif
   
#if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6225) || defined(MT6227D) || defined(MT6223) || defined(MT6226D) || defined(MT6223P)

   #define  EINT_MAX_CHANNEL     8
   #define  EINT_TOTAL_CHANNEL   8   
   
#elif defined(MT6238)

   #define  EINT_MAX_CHANNEL     14        /* All EINT channels are with hardware debouncing,
                                             				level / edge trigger interrupt configurable */ 
                                             
   #define  EINT_TOTAL_CHANNEL   14        

#else /* MT6226 || MT6227 || MT6226M || MT6225 */

   #define  EINT_MAX_CHANNEL     4        /* EINT numbered 4~7 with hardware debouncing,
                                             level / edge trigger interrupt configurable */ 
                                             
   #define  EINT_TOTAL_CHANNEL   8        /* EINT numbered 0~3 with hardware debouncing,
                                             level / edge trigger interrupt configurable */
#endif   /* MT6226 || MT6227 || MT6226M || MT6225 */


#define EINT_CHANNEL_NOT_EXIST   8

#endif
   

/*Engineering mode*/
typedef enum 
{
   aux_eint_chann,
   chrdet_eint_chann,
   melody_eint_chann,
   clamdet_eint_chann,
   touch_panel_eint_chann,
   usb_eint_chann,
   chr_usb_eint_chann,
   bt_eint_chann,
   swdbg_eint_chann,
   motion_senosr_eint_chann,
   tdmb_eint_chann,
   wifi_eint_chann,
   otg_idpin_eint_chann,
   sync_lcm_chann,
   extra_a_key_eint_chann,
   extra_b_key_eint_chann
/* 2009.04.14 added by hongzhe.liu for motion sensor + */
#if (defined(__DIRECTION_SENSOR_SUPPORT__))
   ,motion_senosr_eint1_chann
   ,motion_senosr_eint2_chann
#endif   
/* 2009.04.14 added by hongzhe.liu for motion sensor - */
} eint_channel_type;

typedef struct 
{
   kal_uint8 eint_sw_debounce_handle;
   kal_bool eint_intr_allow;
   kal_uint8 eint_no;
} EINT_SW_DEBOUNCE_STRUCT;

typedef struct 
{
 	void (*eint_func[EINT_TOTAL_CHANNEL])(void);
  	kal_uint32 eint_active[EINT_TOTAL_CHANNEL];
	kal_bool eint_auto_umask[EINT_TOTAL_CHANNEL];
} eint_func;
     
extern void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_lisr)(void), kal_bool auto_umask);
extern void EXTRA_EINT_Registration(kal_uint8 eintno, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask);
extern void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms);
extern void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity);
extern kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens);
extern void EINT_LISR(void);
extern void EINT_Mask(kal_uint8 eintno);
extern void EINT_UnMask(kal_uint8 eintno);
extern kal_uint32 EINT_SaveAndMask(kal_uint8 eintno);
extern void EINT_RestoreMask(kal_uint8 eintno, kal_uint32 val);
extern void EINT_DISABLE(kal_uint8 eintno); 
extern kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time);

/*************************************************************************
 * Customized functions' prototype
 *************************************************************************/
extern kal_uint8 *custom_config_eint_sw_debounce_time_delay(void);
extern kal_uint8 custom_eint_get_channel(eint_channel_type type);   
#endif /* __EINT_H__ */

