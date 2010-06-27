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
 *   isp_engmode.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6226M,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   This file is intends for ISP eng mode driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "stdio.h"
#include "string.h"
#include "kal_release.h"
#include "drv_features.h"
#if (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
#include "isp_if.h"
#include "med_api.h"
#include "ae_awb.h"
#if (defined(ISP_SUPPORT))
#include "image_sensor.h"
#include "camera_para.h"
#endif

kal_uint8 wbOutFixFlag;
/*************************************************************************
* FUNCTION
*	get_isp_engmode_group_count
*
* DESCRIPTION
*	This function gets ISP group count in engineering mode.
*
* PARAMETERS
*	group_count_ptr : pointer of group count
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_isp_engmode_group_count(kal_int32* group_count_ptr)
{
#if (defined(ISP_SUPPORT))
	*group_count_ptr=TOTAL_GROUP_NUMBER;
#endif /* ISP_SUPPORT */
}

/*************************************************************************
* FUNCTION
*	get_isp_engmode_group_info
*
* DESCRIPTION
*	This function gets ISP group information in engineering mode.
*
* PARAMETERS
*	group_idx : index of ISP group
*	group_name_ptr : name of group
*	item_count_ptr : item count of group
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_isp_engmode_group_info(kal_uint16 group_idx, kal_uint8* group_name_ptr, kal_int32* item_count_ptr)
{
#if (defined(ISP_SUPPORT))
	switch(group_idx)
	{
		case OUTDOOR_WB:
			sprintf((char*)group_name_ptr, "OUTDOOR_WB");
			*item_count_ptr=4;
		break;
		case COMPONENT_OFFSET:
			sprintf((char*)group_name_ptr, "COMPONENT_OFFSET");
			*item_count_ptr=4;
		break;
		case INTERPOLATION:
			sprintf((char*)group_name_ptr, "INTERPOLATION");
			*item_count_ptr=4;
		break;
		case AWB:
			sprintf((char*)group_name_ptr, "AWB");
			*item_count_ptr=12;
		break;
		case COMPONENT_GAIN:
			sprintf((char*)group_name_ptr, "COMPONENT_GAIN");
			*item_count_ptr=3;
		break;
		case MANUEL_WB_1:
			sprintf((char*)group_name_ptr, "MANUEL_WB_1");
			*item_count_ptr=4;
		break;
		case MANUEL_WB_2:
			sprintf((char*)group_name_ptr, "MANUEL_WB_2");
			*item_count_ptr=4;
		break;
		case MANUEL_WB_3:
			sprintf((char*)group_name_ptr, "MANUEL_WB_3");			
			*item_count_ptr=4;
		break;
		case MANUEL_WB_4:
			sprintf((char*)group_name_ptr, "MANUEL_WB_4");			
			*item_count_ptr=4;
		break;
		case MANUEL_WB_5:
			sprintf((char*)group_name_ptr, "MANUEL_WB_5");			
			*item_count_ptr=4;
		break;
		case AE:
			sprintf((char*)group_name_ptr, "AE");			
			*item_count_ptr=1;
		break;
		case COLOR_MATRIX:
			sprintf((char*)group_name_ptr, "COLOR_MATRIX");			
			*item_count_ptr=9;
		break;
		case EDGE:
			sprintf((char*)group_name_ptr, "EDGE");			
			*item_count_ptr=14;
		break;
		case COLOR_SUPPRESSION:
			sprintf((char*)group_name_ptr, "COLOR_SUPPRESSION");			
			*item_count_ptr=1;
		break;
		case GAMMA_SELECT:
			sprintf((char*)group_name_ptr, "GAMMA_SELECT");			
			*item_count_ptr=1;
		break;
		case GAMMA_TUNING:
			sprintf((char*)group_name_ptr, "GAMMA_TUNING");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE1:
			sprintf((char*)group_name_ptr, "GAMMA1_BALANCE");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE2:
			sprintf((char*)group_name_ptr, "GAMMA2_WEAK");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE3:
			sprintf((char*)group_name_ptr, "GAMMA3_ENHAN_MID");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE4:
			sprintf((char*)group_name_ptr, "GAMMA4_STD_045");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE5:
			sprintf((char*)group_name_ptr, "GAMMA5_SUP_045_LL");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE6:
			sprintf((char*)group_name_ptr, "GAMMA6_SUP_06_LL");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE7:
			sprintf((char*)group_name_ptr, "GAMMA7_ENHAN_LMID");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE8:
			sprintf((char*)group_name_ptr, "GAMMA8_STD_06");			
			*item_count_ptr=11;
		break;
		case GAMMA_PREDEFINE9:
			sprintf((char*)group_name_ptr, "GAMMA9_STD_10");			
			*item_count_ptr=11;
		break;
		case CONTRAST:
			sprintf((char*)group_name_ptr, "CONTRAST");			
			*item_count_ptr=1;
		break;
		case BRIGHTNESS:
			sprintf((char*)group_name_ptr, "BRIGHTNESS");			
			*item_count_ptr=1;
		break;
		case SATURATION:
			sprintf((char*)group_name_ptr, "SATURATION");			
			*item_count_ptr=2;
		break;
	}
#endif /* ISP_SUPPORT */
}

/*************************************************************************
* FUNCTION
*	get_isp_engmode_item_info
*
* DESCRIPTION
*	This function gets ISP item information in engineering mode.
*
* PARAMETERS
*	group_idx : index of ISP group
*	item_idx : index of item
*	info_ptr : information of item
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void get_isp_engmode_item_info(kal_uint16 group_idx, kal_uint16 item_idx, isp_engmode_item_info_struct* info_ptr)
{
#if (defined(ISP_SUPPORT))
	wbOutFixFlag = camera_oper_data.outdoor_fixWB_enable;
	switch(group_idx)
	{
		case OUTDOOR_WB:
			camera_oper_data.outdoor_fixWB_enable = 0;
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "R");			
					info_ptr->item_value=(REG_ISP_RGB_GAIN_CTRL2&0x01FF0000)>>16;
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "Gr");
					info_ptr->item_value=(REG_ISP_RGB_GAIN_CTRL2&0x000001FF);
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "B");
					info_ptr->item_value=(REG_ISP_RGB_GAIN_CTRL1&0x01FF0000)>>16;
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "Gb");
					info_ptr->item_value=REG_ISP_RGB_GAIN_CTRL2&0x000001FF;
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case COMPONENT_OFFSET:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "R");			
					info_ptr->item_value=(camera_para.ISP.reg[5]&0xFF000000)>>24;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "Gr");
					info_ptr->item_value=(camera_para.ISP.reg[5]&0x00FF0000)>>16;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "B");
					info_ptr->item_value=(camera_para.ISP.reg[5]&0x0000FF00)>>8;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "Gb");
					info_ptr->item_value=camera_para.ISP.reg[5]&0x000000FF;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case INTERPOLATION:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "DISLJ");
					info_ptr->item_value=camera_para.ISP.reg[28]&REG_CPS1_LINE_JUDGE_ENABLE_BIT;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "THRE_V");
					info_ptr->item_value=(camera_para.ISP.reg[29]&REG_INTERPOLATION1_THRESHOLD_V_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=REG_INTERPOLATION1_THRESHOLD_V_MASK>>24;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "THRE_SM");
					info_ptr->item_value=(camera_para.ISP.reg[29]&REG_INTERPOLATION1_THRESHOLD_SM_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_INTERPOLATION1_THRESHOLD_SM_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "THRE_DHV");
					info_ptr->item_value=(camera_para.ISP.reg[29]&REG_INTERPOLATION1_THRESHOLD_DHV_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_INTERPOLATION1_THRESHOLD_DHV_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case AWB:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "AWBALL");
					info_ptr->item_value=(camera_para.ISP.reg[17]&REG_PREPROCESS2_AWB_AREA_ALL_ENABLE_BIT)>>11;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "Axis R Gain");
					info_ptr->item_value=(camera_para.ISP.reg[36]&REG_AXIS_RGB_GAIN_R_GAIN_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_AXIS_RGB_GAIN_R_GAIN_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "Axis G Gain");
					info_ptr->item_value=(camera_para.ISP.reg[36]&REG_AXIS_RGB_GAIN_G_GAIN_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_AXIS_RGB_GAIN_G_GAIN_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "Axis B Gain");
					info_ptr->item_value=camera_para.ISP.reg[36]&REG_AXIS_RGB_GAIN_B_GAIN_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_AXIS_RGB_GAIN_B_GAIN_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "U_GAIN");
					info_ptr->item_value=(camera_para.ISP.reg[37]&REG_OPD_CONFIG_U_GAIN_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_U_GAIN_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "V_GAIN");
					info_ptr->item_value=(camera_para.ISP.reg[37]&REG_OPD_CONFIG_V_GAIN_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_V_GAIN_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "S_RB_P");
					info_ptr->item_value=(camera_para.ISP.reg[38]&REG_OPD_CONFIG_PARA_S_RB_P_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_PARA_S_RB_P_MASK>>24;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "S_RB_N");
					info_ptr->item_value=(camera_para.ISP.reg[38]&REG_OPD_CONFIG_PARA_S_RB_N_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_PARA_S_RB_N_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "S_MG_P");
					info_ptr->item_value=(camera_para.ISP.reg[38]&REG_OPD_CONFIG_PARA_S_MG_P_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_PARA_S_MG_P_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "S_MG_N");
					info_ptr->item_value=camera_para.ISP.reg[38]&REG_OPD_CONFIG_PARA_S_MG_N_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_PARA_S_MG_N_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "Y_HIGH_LIMIT");
					info_ptr->item_value=(camera_para.ISP.reg[37]&REG_OPD_CONFIG_COLOR_SUP_SEL_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_COLOR_SUP_SEL_MASK>>24;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 11:
					sprintf((char*)info_ptr->item_name_ptr, "Y_LOW_LIMIT");
					info_ptr->item_value=camera_para.ISP.reg[37]&REG_OPD_CONFIG_Y_LIMIT_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_OPD_CONFIG_Y_LIMIT_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case COMPONENT_GAIN:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "B_GAIN");
					info_ptr->item_value=(REG_ISP_RGB_GAIN_CTRL1 & REG_COMP_B_GAIN_CTRL_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=512;
					info_ptr->is_read_only=KAL_TRUE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GR_GAIN");
#if (defined(DRV_ISP_6219_SERIES))
					info_ptr->item_value=REG_ISP_RGB_GAIN_CTRL1 & REG_COMP_G_GAIN_CTRL_MASK;
#else
					info_ptr->item_value=REG_ISP_RGB_GAIN_CTRL1 & REG_COMP_GB_GAIN_CTRL_MASK;
#endif
					info_ptr->min=0;
					info_ptr->max=512;
					info_ptr->is_read_only=KAL_TRUE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "R_GAIN");
					info_ptr->item_value=(REG_ISP_RGB_GAIN_CTRL2 & REG_COMP_R_GAIN_CTRL_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=512;
					info_ptr->is_read_only=KAL_TRUE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case MANUEL_WB_1:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "Temperature");
					info_ptr->item_value=camera_para.AWB.LightSource[0][0];
					info_ptr->min=0;
					info_ptr->max=12000;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "R Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[0][1];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "G Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[0][2];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "B Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[0][3];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
			}
		break;
		case MANUEL_WB_2:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "Temperature");
					info_ptr->item_value=camera_para.AWB.LightSource[1][0];
					info_ptr->min=0;
					info_ptr->max=12000;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "R Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[1][1];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "G Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[1][2];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "B Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[1][3];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
			}
		break;
		case MANUEL_WB_3:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "Temperature");
					info_ptr->item_value=camera_para.AWB.LightSource[2][0];
					info_ptr->min=0;
					info_ptr->max=12000;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "R Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[2][1];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "G Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[2][2];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "B Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[2][3];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
			}
		break;
		case MANUEL_WB_4:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "Temperature");
					info_ptr->item_value=camera_para.AWB.LightSource[3][0];
					info_ptr->min=0;
					info_ptr->max=12000;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "R Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[3][1];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "G Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[3][2];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "B Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[3][3];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
			}
		break;
		case MANUEL_WB_5:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "Temperature");
					info_ptr->item_value=camera_para.AWB.LightSource[4][0];
					info_ptr->min=0;
					info_ptr->max=12000;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "R Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[4][1];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "G Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[4][2];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "B Gain");
					info_ptr->item_value=camera_para.AWB.LightSource[4][3];
					info_ptr->min=0;
					info_ptr->max=511;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
				break;
			}
		break;
		case AE:
					sprintf((char*)info_ptr->item_name_ptr, "AE target");
					info_ptr->item_value=camera_para.AE.TargetLum;
					info_ptr->min=camera_oper_data.ae_smooth_lower_bound;
					info_ptr->max=camera_oper_data.ae_smooth_upper_bound;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
		break;
		case COLOR_MATRIX:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "M11");
					info_ptr->item_value=(camera_para.ISP.reg[39]&REG_COLOR_MATRIX_M1_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M1_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "M12");
					info_ptr->item_value=(camera_para.ISP.reg[39]&REG_COLOR_MATRIX_M2_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M2_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "M13");
					info_ptr->item_value=camera_para.ISP.reg[39]&REG_COLOR_MATRIX_M3_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M3_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "M21");
					info_ptr->item_value=(camera_para.ISP.reg[40]&REG_COLOR_MATRIX_M1_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M1_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "M22");
					info_ptr->item_value=(camera_para.ISP.reg[40]&REG_COLOR_MATRIX_M2_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M2_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "M23");
					info_ptr->item_value=camera_para.ISP.reg[40]&REG_COLOR_MATRIX_M3_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M3_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "M31");
					info_ptr->item_value=(camera_para.ISP.reg[41]&REG_COLOR_MATRIX_M1_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M1_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "M32");
					info_ptr->item_value=(camera_para.ISP.reg[41]&REG_COLOR_MATRIX_M2_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M2_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "M33");
					info_ptr->item_value=camera_para.ISP.reg[41]&REG_COLOR_MATRIX_M3_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_COLOR_MATRIX_M3_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case EDGE:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "RGBEDGAINEN");
					info_ptr->item_value=(camera_para.ISP.reg[43]&REG_CPS2_RGB_EDGE_ENABLE_BIT)>>6;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "YEDGEN");
					info_ptr->item_value=(camera_para.ISP.reg[43]&REG_CPS2_Y_EDGE_ENABLE_BIT)>>5;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "YEGAIN");
					info_ptr->item_value=camera_para.ISP.reg[43]&REG_CPS2_Y_EDGE_GAIN_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_CPS2_Y_EDGE_GAIN_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "THRE_LEDGE");
					info_ptr->item_value=camera_para.ISP.reg[30]&REG_INTERPOLATION2_THRESHOLD_LEDGE_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_INTERPOLATION2_THRESHOLD_LEDGE_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "EGAIN_H");
					info_ptr->item_value=(camera_para.ISP.reg[32]&REG_EDGE_GAIN1_EGAIN_H_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=15;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "EGAIN_H2");
					info_ptr->item_value=(camera_para.ISP.reg[32]&REG_EDGE_GAIN1_EGAIN_H2_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_EDGE_GAIN1_EGAIN_H2_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "EGAIN_VB");
					info_ptr->item_value=(camera_para.ISP.reg[32]&REG_EDGE_GAIN1_EGAIN_VB_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=REG_EDGE_GAIN1_EGAIN_VB_MASK>>8;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "EGAINLINE");
					info_ptr->item_value=camera_para.ISP.reg[32]&REG_EDGE_GAIN1_EGAINLINE_MASK;
					info_ptr->min=0;
					info_ptr->max=15;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "EGAIN_HC");
					info_ptr->item_value=camera_para.ISP.reg[33]&REG_EDGE_GAIN2_EGAIN_HC_MASK;
					info_ptr->min=0;
					info_ptr->max=31;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "P_LIMIT");
					info_ptr->item_value=(camera_para.ISP.reg[12]&REG_PREPROCESS1_PIXEL_LIMIT_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_PREPROCESS1_PIXEL_LIMIT_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "LEDGEN");
					info_ptr->item_value=(camera_para.ISP.reg[28]&REG_CPS1_LINE_EDGE_ENABLE_BIT)>>1;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 11:
					sprintf((char*)info_ptr->item_name_ptr, "EMBOSS1");
					info_ptr->item_value=(camera_para.ISP.reg[31]&REG_EDGE_CORE_EMBOSS1_BIT)>>23;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 12:
					sprintf((char*)info_ptr->item_name_ptr, "EMBOSS2");
					info_ptr->item_value=(camera_para.ISP.reg[31]&REG_EDGE_CORE_EMBOSS2_BIT)>>22;
					info_ptr->min=0;
					info_ptr->max=1;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 13:
					sprintf((char*)info_ptr->item_name_ptr, "KNEESEL");
					info_ptr->item_value=(camera_para.ISP.reg[32]&REG_EDGE_GAIN1_KNEESEL_MASK)>>4;
					info_ptr->min=0;
					info_ptr->max=REG_EDGE_GAIN1_KNEESEL_MASK>>4;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case COLOR_SUPPRESSION:
					sprintf((char*)info_ptr->item_name_ptr, "CSUP_EDGE_GAIN");
					info_ptr->item_value=camera_para.ISP.reg[46]&REG_Y_CH_CONFIG_CSUP_EDGE_GAIN_MASK;
					info_ptr->min=0;
					info_ptr->max=REG_Y_CH_CONFIG_CSUP_EDGE_GAIN_MASK;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
		break;
		case GAMMA_SELECT:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_SELECT");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma_select;
					info_ptr->min=0;
					info_ptr->max=9;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_TRUE;
		break;
		case GAMMA_TUNING:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=(camera_para.ISP.reg[50]&REG_GAMMA_OPERATION_GAMMA_B1_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=(camera_para.ISP.reg[50]&REG_GAMMA_OPERATION_GAMMA_B2_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=(camera_para.ISP.reg[50]&REG_GAMMA_OPERATION_GAMMA_B3_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.ISP.reg[50]&REG_GAMMA_OPERATION_GAMMA_B4_MASK;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=(camera_para.ISP.reg[51]&REG_GAMMA_OPERATION_GAMMA_B5_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=(camera_para.ISP.reg[51]&REG_GAMMA_OPERATION_GAMMA_B6_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=(camera_para.ISP.reg[51]&REG_GAMMA_OPERATION_GAMMA_B7_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.ISP.reg[51]&REG_GAMMA_OPERATION_GAMMA_B8_MASK;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=(camera_para.ISP.reg[52]&REG_GAMMA_OPERATION_GAMMA_B9_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=(camera_para.ISP.reg[52]&REG_GAMMA_OPERATION_GAMMA_B10_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=(camera_para.ISP.reg[52]&REG_GAMMA_OPERATION_GAMMA_B11_MASK)>>8;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE1:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[0][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE2:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[1][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE3:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[2][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE4:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[3][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE5:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[4][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE6:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[5][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE7:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[6][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE8:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[7][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case GAMMA_PREDEFINE9:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B1");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][0];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B2");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][1];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 2:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B3");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][2];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 3:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B4");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][3];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 4:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B5");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][4];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 5:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B6");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][5];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 6:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B7");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][6];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 7:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B8");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][7];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 8:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B9");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][8];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 9:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B10");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][9];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 10:
					sprintf((char*)info_ptr->item_name_ptr, "GAMMA_B11");
					info_ptr->item_value=camera_para.PREDGAMMA.gamma[8][10];
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
		case CONTRAST:
					sprintf((char*)info_ptr->item_name_ptr, "CONTRAST");
					info_ptr->item_value=(camera_para.ISP.reg[46]&REG_Y_CH_CONFIG_CONTRAST_GAIN_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=REG_Y_CH_CONFIG_CONTRAST_GAIN_MASK>>16;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
		break;
		case BRIGHTNESS:
					sprintf((char*)info_ptr->item_name_ptr, "BRIGHTNESS");
					info_ptr->item_value=(camera_para.ISP.reg[46]&0x0000FF00)>>8;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
		break;
		case SATURATION:
			switch(item_idx)
			{
				case 0:
					sprintf((char*)info_ptr->item_name_ptr, "U11");
					info_ptr->item_value=(camera_para.ISP.reg[47]&REG_UV_CH_CONFIG_U11_MASK)>>24;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
				case 1:
					sprintf((char*)info_ptr->item_name_ptr, "V11");
					info_ptr->item_value=(camera_para.ISP.reg[47]&REG_UV_CH_CONFIG_V11_MASK)>>16;
					info_ptr->min=0;
					info_ptr->max=255;
					info_ptr->is_read_only=KAL_FALSE;
					info_ptr->is_need_restart=KAL_FALSE;
				break;
			}
		break;
	}

#endif /* ISP_SUPPORT */
}

/*************************************************************************
* FUNCTION
*	set_isp_engmode_item_info
*
* DESCRIPTION
*	This function sets ISP item information in engineering mode.
*
* PARAMETERS
*	group_idx :
*	item_idx :
*	item_value :
*
* RETURNS
*	KAL_TRUE : SUCCESS
*  KAL_FALSE : FAIL
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool set_isp_engmode_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{

#if (defined(ISP_SUPPORT))
	camera_oper_data.outdoor_fixWB_enable = wbOutFixFlag;
	switch(group_idx)
	{
		case OUTDOOR_WB:
			switch(item_idx)
			{
				case 0:
					camera_oper_data.out_Rgain = item_value;
				break;
				case 1:
					camera_oper_data.out_GRgain = item_value;
				break;
				case 2:
					camera_oper_data.out_Bgain = item_value;
				break;
				case 3:
					camera_oper_data.out_GBgain = item_value;
				break;
			}
		break;
		case COMPONENT_OFFSET:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[5]&=~0xFF000000;
					camera_para.ISP.reg[5]|=item_value<<24;
				break;
				case 1:
					camera_para.ISP.reg[5]&=~0x00FF0000;
					camera_para.ISP.reg[5]|=item_value<<16;
				break;
				case 2:
					camera_para.ISP.reg[5]&=~0x0000FF00;
					camera_para.ISP.reg[5]|=item_value<<8;
				break;
				case 3:
					camera_para.ISP.reg[5]&=~0x000000FF;
					camera_para.ISP.reg[5]|=item_value;
				break;
			}
		break;
		case INTERPOLATION:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[28]&=~REG_CPS1_LINE_JUDGE_ENABLE_BIT;
					camera_para.ISP.reg[28]|=item_value;
				break;
				case 1:
					camera_para.ISP.reg[29]&=~REG_INTERPOLATION1_THRESHOLD_V_MASK;
					camera_para.ISP.reg[29]|=item_value<<24;
				break;
				case 2:
					camera_para.ISP.reg[29]&=~REG_INTERPOLATION1_THRESHOLD_SM_MASK;
					camera_para.ISP.reg[29]|=item_value<<16;
				break;
				case 3:
					camera_para.ISP.reg[29]&=~REG_INTERPOLATION1_THRESHOLD_DHV_MASK;
					camera_para.ISP.reg[29]|=item_value<<8;
				break;
			}
		break;
		case AWB:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[17]&=~REG_PREPROCESS2_AWB_AREA_ALL_ENABLE_BIT;
					camera_para.ISP.reg[17]|=item_value<<11;
				break;
				case 1:
					camera_para.ISP.reg[36]&=~REG_AXIS_RGB_GAIN_R_GAIN_MASK;
					camera_para.ISP.reg[36]|=item_value<<16;
				break;
				case 2:
					camera_para.ISP.reg[36]&=~REG_AXIS_RGB_GAIN_G_GAIN_MASK;
					camera_para.ISP.reg[36]|=item_value<<8;
				break;
				case 3:
					camera_para.ISP.reg[36]&=~REG_AXIS_RGB_GAIN_B_GAIN_MASK;
					camera_para.ISP.reg[36]|=item_value;
				break;
				case 4:
					camera_para.ISP.reg[37]&=~REG_OPD_CONFIG_U_GAIN_MASK;
					camera_para.ISP.reg[37]|=item_value<<16;
				break;
				case 5:
					camera_para.ISP.reg[37]&=~REG_OPD_CONFIG_V_GAIN_MASK;
					camera_para.ISP.reg[37]|=item_value<<8;
				break;
				case 6:
					camera_para.ISP.reg[38]&=~REG_OPD_CONFIG_PARA_S_RB_P_MASK;
					camera_para.ISP.reg[38]|=item_value<<24;
				break;
				case 7:
					camera_para.ISP.reg[38]&=~REG_OPD_CONFIG_PARA_S_RB_N_MASK;
					camera_para.ISP.reg[38]|=item_value<<16;
				break;
				case 8:
					camera_para.ISP.reg[38]&=~REG_OPD_CONFIG_PARA_S_MG_P_MASK;
					camera_para.ISP.reg[38]|=item_value<<8;
				break;
				case 9:
					camera_para.ISP.reg[38]&=~REG_OPD_CONFIG_PARA_S_MG_N_MASK;
					camera_para.ISP.reg[38]|=item_value;
				break;
				case 10:
					camera_para.ISP.reg[37]&=~REG_OPD_CONFIG_COLOR_SUP_SEL_MASK;
					camera_para.ISP.reg[37]|=item_value<<24;
				break;
				case 11:
					camera_para.ISP.reg[37]&=~REG_OPD_CONFIG_Y_LIMIT_MASK;
					camera_para.ISP.reg[37]|=item_value;
				break;
			}
		break;
		case MANUEL_WB_1:
			switch(item_idx)
			{
				case 0:
					camera_para.AWB.LightSource[0][0]=item_value;
				break;
				case 1:
					camera_para.AWB.LightSource[0][1]=item_value;
				break;
				case 2:
					camera_para.AWB.LightSource[0][2]=item_value;
				break;
				case 3:
					camera_para.AWB.LightSource[0][3]=item_value;
				break;
			}
		break;
		case MANUEL_WB_2:
			switch(item_idx)
			{
				case 0:
					camera_para.AWB.LightSource[1][0]=item_value;
				break;
				case 1:
					camera_para.AWB.LightSource[1][1]=item_value;
				break;
				case 2:
					camera_para.AWB.LightSource[1][2]=item_value;
				break;
				case 3:
					camera_para.AWB.LightSource[1][3]=item_value;
				break;
			}
		break;
		case MANUEL_WB_3:
			switch(item_idx)
			{
				case 0:
					camera_para.AWB.LightSource[2][0]=item_value;
				break;
				case 1:
					camera_para.AWB.LightSource[2][1]=item_value;
				break;
				case 2:
					camera_para.AWB.LightSource[2][2]=item_value;
				break;
				case 3:
					camera_para.AWB.LightSource[2][3]=item_value;
				break;
			}
		break;
		case MANUEL_WB_4:
			switch(item_idx)
			{
				case 0:
					camera_para.AWB.LightSource[3][0]=item_value;
				break;
				case 1:
					camera_para.AWB.LightSource[3][1]=item_value;
				break;
				case 2:
					camera_para.AWB.LightSource[3][2]=item_value;
				break;
				case 3:
					camera_para.AWB.LightSource[3][3]=item_value;
				break;
			}
		break;
		case MANUEL_WB_5:
			switch(item_idx)
			{
				case 0:
					camera_para.AWB.LightSource[4][0]=item_value;
				break;
				case 1:
					camera_para.AWB.LightSource[4][1]=item_value;
				break;
				case 2:
					camera_para.AWB.LightSource[4][2]=item_value;
				break;
				case 3:
					camera_para.AWB.LightSource[4][3]=item_value;
				break;
			}
		break;
		case AE:
					camera_para.AE.TargetLum=item_value;
		break;
		case COLOR_MATRIX:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[39]&=~REG_COLOR_MATRIX_M1_MASK;
					camera_para.ISP.reg[39]|=item_value<<16;
				break;
				case 1:
					camera_para.ISP.reg[39]&=~REG_COLOR_MATRIX_M2_MASK;
					camera_para.ISP.reg[39]|=item_value<<8;
				break;
				case 2:
					camera_para.ISP.reg[39]&=~REG_COLOR_MATRIX_M3_MASK;
					camera_para.ISP.reg[39]|=item_value;
				break;
				case 3:
					camera_para.ISP.reg[40]&=~REG_COLOR_MATRIX_M1_MASK;
					camera_para.ISP.reg[40]|=item_value<<16;
				break;
				case 4:
					camera_para.ISP.reg[40]&=~REG_COLOR_MATRIX_M2_MASK;
					camera_para.ISP.reg[40]|=item_value<<8;
				break;
				case 5:
					camera_para.ISP.reg[40]&=~REG_COLOR_MATRIX_M3_MASK;
					camera_para.ISP.reg[40]|=item_value;
				break;
				case 6:
					camera_para.ISP.reg[41]&=~REG_COLOR_MATRIX_M1_MASK;
					camera_para.ISP.reg[41]|=item_value<<16;
				break;
				case 7:
					camera_para.ISP.reg[41]&=~REG_COLOR_MATRIX_M2_MASK;
					camera_para.ISP.reg[41]|=item_value<<8;
				break;
				case 8:
					camera_para.ISP.reg[41]&=~REG_COLOR_MATRIX_M3_MASK;
					camera_para.ISP.reg[41]|=item_value;
				break;
			}
		break;
		case EDGE:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[43]&=~REG_CPS2_RGB_EDGE_ENABLE_BIT;
					camera_para.ISP.reg[43]|=item_value<<6;
				break;
				case 1:
					camera_para.ISP.reg[43]&=~REG_CPS2_Y_EDGE_ENABLE_BIT;
					camera_para.ISP.reg[43]|=item_value<<5;
				break;
				case 2:
					camera_para.ISP.reg[43]&=~REG_CPS2_Y_EDGE_GAIN_MASK;
					camera_para.ISP.reg[43]|=item_value;
				break;
				case 3:
					camera_para.ISP.reg[30]&=~REG_INTERPOLATION2_THRESHOLD_LEDGE_MASK;
					camera_para.ISP.reg[30]|=item_value;
				break;
				case 4:
					camera_para.ISP.reg[32]&=~REG_EDGE_GAIN1_EGAIN_H_MASK;
					camera_para.ISP.reg[32]|=item_value<<24;
				break;
				case 5:
					camera_para.ISP.reg[32]&=~REG_EDGE_GAIN1_EGAIN_H2_MASK;
					camera_para.ISP.reg[32]|=item_value<<16;
				break;
				case 6:
					camera_para.ISP.reg[32]&=~REG_EDGE_GAIN1_EGAIN_VB_MASK;
					camera_para.ISP.reg[32]|=item_value<<8;
				break;
				case 7:
					camera_para.ISP.reg[32]&=~REG_EDGE_GAIN1_EGAINLINE_MASK;
					camera_para.ISP.reg[32]|=item_value;
				break;
				case 8:
					camera_para.ISP.reg[33]&=~REG_EDGE_GAIN2_EGAIN_HC_MASK;
					camera_para.ISP.reg[33]|=item_value;
				break;
				case 9:
					camera_para.ISP.reg[12]&=~REG_PREPROCESS1_PIXEL_LIMIT_MASK;
					camera_para.ISP.reg[12]|=item_value<<16;
				break;
				case 10:
					camera_para.ISP.reg[28]&=~REG_CPS1_LINE_EDGE_ENABLE_BIT;
					camera_para.ISP.reg[28]|=item_value<<1;
				break;
				case 11:
					camera_para.ISP.reg[31]&=~REG_EDGE_CORE_EMBOSS1_BIT;
					camera_para.ISP.reg[31]|=item_value<<23;
				break;
				case 12:
					camera_para.ISP.reg[31]&=~REG_EDGE_CORE_EMBOSS2_BIT;
					camera_para.ISP.reg[31]|=item_value<<22;
				break;
				case 13:
					camera_para.ISP.reg[32]&=~REG_EDGE_GAIN1_KNEESEL_MASK;
					camera_para.ISP.reg[32]|=item_value<<4;
				break;
			}
		break;
		case COLOR_SUPPRESSION:
					camera_para.ISP.reg[46]&=~REG_Y_CH_CONFIG_CSUP_EDGE_GAIN_MASK;
					camera_para.ISP.reg[46]|=item_value;
		break;
		case GAMMA_SELECT:
					camera_para.PREDGAMMA.gamma_select=item_value;
		break;
		case GAMMA_TUNING:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[50]&=~REG_GAMMA_OPERATION_GAMMA_B1_MASK;
					camera_para.ISP.reg[50]|=item_value<<24;
				break;
				case 1:
					camera_para.ISP.reg[50]&=~REG_GAMMA_OPERATION_GAMMA_B2_MASK;
					camera_para.ISP.reg[50]|=item_value<<16;
				break;
				case 2:
					camera_para.ISP.reg[50]&=~REG_GAMMA_OPERATION_GAMMA_B3_MASK;
					camera_para.ISP.reg[50]|=item_value<<8;
				break;
				case 3:
					camera_para.ISP.reg[50]&=~REG_GAMMA_OPERATION_GAMMA_B4_MASK;
					camera_para.ISP.reg[50]|=item_value;
				break;
				case 4:
					camera_para.ISP.reg[51]&=~REG_GAMMA_OPERATION_GAMMA_B5_MASK;
					camera_para.ISP.reg[51]|=item_value<<24;
				break;
				case 5:
					camera_para.ISP.reg[51]&=~REG_GAMMA_OPERATION_GAMMA_B6_MASK;
					camera_para.ISP.reg[51]|=item_value<<16;
				break;
				case 6:
					camera_para.ISP.reg[51]&=~REG_GAMMA_OPERATION_GAMMA_B7_MASK;
					camera_para.ISP.reg[51]|=item_value<<8;
				break;
				case 7:
					camera_para.ISP.reg[51]&=~REG_GAMMA_OPERATION_GAMMA_B8_MASK;
					camera_para.ISP.reg[51]|=item_value;
				break;
				case 8:
					camera_para.ISP.reg[52]&=~REG_GAMMA_OPERATION_GAMMA_B9_MASK;
					camera_para.ISP.reg[52]|=item_value<<24;
				break;
				case 9:
					camera_para.ISP.reg[52]&=~REG_GAMMA_OPERATION_GAMMA_B10_MASK;
					camera_para.ISP.reg[52]|=item_value<<16;
				break;
				case 10:
					camera_para.ISP.reg[52]&=~REG_GAMMA_OPERATION_GAMMA_B11_MASK;
					camera_para.ISP.reg[52]|=item_value<<8;
				break;
			}
		break;
		case GAMMA_PREDEFINE1:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[0][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[0][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[0][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[0][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[0][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[0][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[0][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[0][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[0][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[0][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[0][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE2:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[1][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[1][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[1][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[1][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[1][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[1][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[1][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[1][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[1][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[1][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[1][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE3:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[2][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[2][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[2][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[2][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[2][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[2][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[2][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[2][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[2][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[2][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[2][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE4:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[3][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[3][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[3][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[3][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[3][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[3][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[3][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[3][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[3][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[3][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[3][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE5:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[4][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[4][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[4][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[4][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[4][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[4][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[4][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[4][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[4][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[4][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[4][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE6:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[5][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[5][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[5][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[5][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[5][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[5][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[5][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[5][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[5][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[5][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[5][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE7:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[6][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[6][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[6][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[6][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[6][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[6][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[6][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[6][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[6][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[6][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[6][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE8:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[7][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[7][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[7][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[7][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[7][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[7][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[7][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[7][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[7][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[7][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[7][10]=item_value;
				break;
			}
		break;
		case GAMMA_PREDEFINE9:
			switch(item_idx)
			{
				case 0:
					camera_para.PREDGAMMA.gamma[8][0]=item_value;
				break;
				case 1:
					camera_para.PREDGAMMA.gamma[8][1]=item_value;
				break;
				case 2:
					camera_para.PREDGAMMA.gamma[8][2]=item_value;
				break;
				case 3:
					camera_para.PREDGAMMA.gamma[8][3]=item_value;
				break;
				case 4:
					camera_para.PREDGAMMA.gamma[8][4]=item_value;
				break;
				case 5:
					camera_para.PREDGAMMA.gamma[8][5]=item_value;
				break;
				case 6:
					camera_para.PREDGAMMA.gamma[8][6]=item_value;
				break;
				case 7:
					camera_para.PREDGAMMA.gamma[8][7]=item_value;
				break;
				case 8:
					camera_para.PREDGAMMA.gamma[8][8]=item_value;
				break;
				case 9:
					camera_para.PREDGAMMA.gamma[8][9]=item_value;
				break;
				case 10:
					camera_para.PREDGAMMA.gamma[8][10]=item_value;
				break;
			}
		break;
		case CONTRAST:
					camera_para.ISP.reg[46]&=~REG_Y_CH_CONFIG_CONTRAST_GAIN_MASK;
					camera_para.ISP.reg[46]|=item_value<<16;
		break;
		case BRIGHTNESS:
					camera_para.ISP.reg[46]&=~0x0000FF00;
					camera_para.ISP.reg[46]|=item_value<<8;
		break;
		case SATURATION:
			switch(item_idx)
			{
				case 0:
					camera_para.ISP.reg[47]&=~REG_UV_CH_CONFIG_U11_MASK;
					camera_para.ISP.reg[47]|=item_value<<24;
				break;
				case 1:
					camera_para.ISP.reg[47]&=~REG_UV_CH_CONFIG_V11_MASK;
					camera_para.ISP.reg[47]|=item_value<<16;
				break;
			}
		break;
	}
	return KAL_TRUE;
#endif /* ISP_SUPPORT */
}

#endif /* (defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES)) */
