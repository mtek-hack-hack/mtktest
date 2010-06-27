/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/custom/drv/LCD/U25_06B_LCM/lcd_hw.h,v 1.2 2007/05/21 06:08:19 yangzeping Exp $
*
* $Id: lcd_hw.h,v 1.2 2007/05/21 06:08:19 yangzeping Exp $
*
* $Date: 2007/05/21 06:08:19 $
*
* $Name: 1.2 $
*
* $Locker$
*
* $Revision: 1.2 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: lcd_hw.h,v $
* Revision 1.2  2007/05/21 06:08:19  yangzeping
* UNI@yangzeping_20070521e 14:08 提交BEIW8,BEIW9的LCD驱动(176x220)
*
* Revision 1.1  2007/05/17 07:11:40  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 *    lcd_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for LCD driver.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _LCD_HW_H
#define _LCD_HW_H

#define N_lcd_reg   (22)

typedef struct {
    kal_uint16  addr;
    kal_uint16  para;
} lcd_reg_struct;

typedef struct {
    lcd_reg_struct reg[N_lcd_reg];
} lcd_data_struct;
#define LCD_OSC_START_HX8309 		0x0000
#define LCD_DRV_OUTCON_HX8309        	0x0001
#define LCD_DRV_WAV_FOM_HX8309	        0x0002
#define LCD_ENT_MOD_HX8309	        0x0003
#define LCD_COMPARE_CON1_HX8309		0x0004
#define LCD_COMPARE_CON2_HX8309		0x0005
#define LCD_DISP_CON1_HX8309		0x0007
#define LCD_DISP_CON2_HX8309	        0x0008
#define LCD_DISP_CON3_HX8309	        0x0009
#define LCD_FRAM_CYC_CON_HX8309		0x000b
#define LCD_EXT_DISP_CON_HX8309		0x000C

#define LCD_POWER_CON1_HX8309         	0x0010
#define LCD_POWER_CON2_HX8309         	0x0011
#define LCD_POWER_CON3_HX8309         	0x0012
#define LCD_POWER_CON4_HX8309         	0x0013

#define LCD_RAM_ADDR_SET_HX8309    	0x0021
#define LCD_WRITE_TO_RAM_HX8309    	0x0022
#define LCD_GAMA_CON1_HX8309           	0x0030
#define LCD_GAMA_CON2_HX8309  	        0x0031
#define LCD_GAMA_CON3_HX8309   	        0x0032
#define LCD_GAMA_CON4_HX8309  	        0x0033
#define LCD_GAMA_CON5_HX8309  	        0x0034
#define LCD_GAMA_CON6_HX8309  	        0x0035
#define LCD_GAMA_CON7_HX8309  	        0x0036
#define LCD_GAMA_CON8_HX8309  	        0x0037
#define LCD_GAMA_CON9_HX8309  	        0x0038
#define LCD_GAMA_CON10_HX8309  	        0x0039

#define LCD_GAT_SCAN_POSIN_HX8309	0x0040
#define LCD_VERI_SCRO_CON_HX8309        0x0041
#define LCD_FIRST_DISP_POS_HX8309       0x0042
#define LCD_SECOND_DISP_POS_HX8309      0x0043
#define LCD_HOR_RAM_ADDR_POS_HX8309 	0x0044
#define LCD_VER_RAM_ADDR_POS_HX8309 	0x0045
#endif   /*_LCD_HW_H*/

