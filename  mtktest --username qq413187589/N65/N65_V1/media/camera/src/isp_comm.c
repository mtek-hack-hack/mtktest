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
 *   camera_comm.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6226M,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   Camera ISP configuration function
 *
 * Author:
 * -------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h" 
#if defined(ISP_SUPPORT)
#include "drv_comm.h"
#include "stdio.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "sccb.h"
#include "ae_awb.h"
#include "camera_para.h"
#include "med_api.h"
#include "isp_device_if.h"
#include "exif.h"
#if (defined(AF_SUPPORT))
#include "af.h"
#endif

extern kal_uint8	camera_system_operation_mode;
extern kal_uint16 	isp_grab_start_x,isp_grab_start_y;

kal_uint8	shading_apply_mode=CAMERA_SHADING_NORMAL_SET;

// apply camera_para to ISP, AE&AWB and SENSOR 
void apply_camera_para_to_reg(void)
{
	// write camera_para to isp register 
	camera_para_to_isp();

	// write camera_para to ae 
	camera_para_to_ae();

	// write camera_para to sensor register 
	camera_para_to_sensor();
}

// update camera_para from ISP, AE&AWB and SENSOR 
void update_camera_para_from_reg(void)
{
	// update camera_para from isp register 
	isp_to_camera_para();

	// update camera_para from ae 
		// no function call to update camera_para from ae, because ae firmware already update it automatically 

	// update camera_para from sensor register 
	sensor_to_camera_para();
}

// interface to apply camera_para to ISP, AE&AWB 
void load_camera_para(void)
{
	// write camera_para to isp register 
	camera_para_to_isp();

	// write camera_para to ae 
	camera_para_to_ae();
	
}

// interface to apply camera_para to ISP, AE&AWB 	
void camera_para_to_isp(void)
{
#if (defined(DRV_ISP_6228_SERIES))
	kal_uint32	i;
	kal_uint32 	temp1;
	/* common register start */
	REG_ISP_RGB_OFFSET_ADJUS=camera_para.ISP.reg[5];//0014h
	temp1 = REG_ISP_PREPROCESS_CTRL1& (~REG_PREPROCESS1_GAIN_COMPENSATION_MASK);
	temp1 |= camera_para.ISP.reg[12] & REG_PREPROCESS1_GAIN_COMPENSATION_MASK;	
	REG_ISP_PREPROCESS_CTRL1= temp1;//0x0030h
	for(i=13;i<53;i++)//0034h~00D0h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	for(i=71;i<87;i++)//011Ch~0158h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	for(i=88;i<99;i++)//01A0h~01C8
		*((volatile unsigned int *) (CAMERA_base + i*4 + 64))=camera_para.ISP.reg[i];
	REG_ISP_FLASH_CTRL=camera_para.ISP.reg[AutoDefect_Reg1_ID+2];//01D4h
	/* copy ISP_FRAME_COUNT 0x1D8[15:8] but reserve other control bits */	
	REG_ISP_RESET &= ~REG_CAM_RESET_ISP_FRAME_COUNT_MASK;//0x01D8
	REG_ISP_RESET |= camera_para.ISP.reg[AutoDefect_Reg1_ID+3]&REG_CAM_RESET_ISP_FRAME_COUNT_MASK;
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3=camera_para.ISP.reg[AutoDefect_Reg1_ID+5];//01E0h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4=camera_para.ISP.reg[AutoDefect_Reg1_ID+6];//01E4h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5=camera_para.ISP.reg[AutoDefect_Reg1_ID+7];//01E8h
	/* disable copy 0214h~023Ch global variable to reg  */	
	REG_ISP_IMGPROC_HUE0=camera_para.ISP.reg[128];//0240h
	REG_ISP_IMGPROC_HUE1=camera_para.ISP.reg[129];//0244h
	/* common register end */
	
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)	
	{
		Set_camera_shading_mode(camera_oper_data.shading_table_mode_set);/* set shading lut mode */
	}
      // Eng. Mode Gamma Table Select
	if(camera_para.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][10]);
	}
#elif (defined(DRV_ISP_6229_SERIES))	
	kal_uint32	i;
	kal_uint32 temp1, temp2;	
	
	REG_ISP_RGB_OFFSET_ADJUS=camera_para.ISP.reg[5];//0014h
	temp1 = REG_ISP_PREPROCESS_CTRL1& (~REG_PREPROCESS1_GAIN_COMPENSATION_MASK);
	temp1 |= camera_para.ISP.reg[12] & REG_PREPROCESS1_GAIN_COMPENSATION_MASK;	
	REG_ISP_PREPROCESS_CTRL1= temp1;//0x0030h	
	for(i=13;i<52;i++)//0034h~00CDh
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	/* set gamma 1024 disable & 00D0h */
	*((volatile unsigned int *) (CAMERA_base + gamma_global_1024_no*4))=camera_para.ISP.reg[gamma_global_1024_no]&(~REG_GAMMA_OPERATION_1024_ENABLE_BIT);		
	for(i=71;i<95;i++)//011Ch~0178h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	for(i=104;i<115;i++)//01A0h~01C8h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];	
	REG_ISP_FLASH_CTRL=camera_para.ISP.reg[AutoDefect_Reg1_ID+2];//01D4h	
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3=camera_para.ISP.reg[AutoDefect_Reg1_ID+5];//01E0h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4=camera_para.ISP.reg[AutoDefect_Reg1_ID+6];//01E4h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5=camera_para.ISP.reg[AutoDefect_Reg1_ID+7];//01E8h
	/* disable copy 0214h~023Ch global variable to reg  */	
	for(i=147;i<152;i++)//024Ch~025Ch
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	//bypass gamma		
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	ENABLE_GAMMA_FUNCTION_BYPASS;//disable gamma
	DISABLE_1024_GAMMA_TABLE;//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
		INTMEM_GAMMA_1024(i)=camera_gamma.gamma[i];
	//restore gamma enable	
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)	
	{	
		Set_camera_shading_mode(camera_oper_data.shading_table_mode_set);/* set shading lut mode */		
	}
      // Eng. Mode Gamma Table Select
	if(camera_para.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][10]);
	}	
#elif (defined(DRV_ISP_6227_SERIES))
	kal_uint32	i;
	kal_uint32 temp1, temp2;	
	
	REG_ISP_RGB_OFFSET_ADJUS=camera_para.ISP.reg[5];//0014h
	temp1 = REG_ISP_PREPROCESS_CTRL1& (~REG_PREPROCESS1_GAIN_COMPENSATION_MASK);
	temp1 |= camera_para.ISP.reg[12] & REG_PREPROCESS1_GAIN_COMPENSATION_MASK;	
	REG_ISP_PREPROCESS_CTRL1= temp1;//0x0030h		
	for(i=13;i<52;i++)//0034h~00ECh
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	/* set gamma 1024 disable & 00D0h */
	*((volatile unsigned int *) (CAMERA_base + gamma_global_1024_no*4))=camera_para.ISP.reg[gamma_global_1024_no]&(~REG_GAMMA_OPERATION_1024_ENABLE_BIT);	
	for(i=71;i<95;i++)//011Ch~0178h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	REG_ISP_FLASH_CTRL=camera_para.ISP.reg[AutoDefect_Reg1_ID+2];//01D4h	
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3=camera_para.ISP.reg[AutoDefect_Reg1_ID+5];//01E0h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4=camera_para.ISP.reg[AutoDefect_Reg1_ID+6];//01E4h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5=camera_para.ISP.reg[AutoDefect_Reg1_ID+7];//01E8h
	/* disable copy 0214h~023Ch global variable to reg  */	
	for(i=139;i<144;i++)//024Ch~025Ch
		*((volatile unsigned int *) (CAMERA_base + i*4 + 32))=camera_para.ISP.reg[i];
	//bypass gamma		
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	ENABLE_GAMMA_FUNCTION_BYPASS;//disable gamma
	DISABLE_1024_GAMMA_TABLE;//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
		INTMEM_GAMMA_1024(i)=camera_gamma.gamma[i];
	//restore gamma enable	
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)	
	{	
		Set_camera_shading_mode(camera_oper_data.shading_table_mode_set);/* set shading lut mode */		
	}
      // Eng. Mode Gamma Table Select
	if(camera_para.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][10]);
	}
#elif (defined(DRV_ISP_6219_SERIES))
	kal_uint32	i;
	
	*((volatile unsigned int *) (CAMERA_base + 20))=camera_para.ISP.reg[5];
	for(i=13;i<53;i++)//0034h~00D0h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para.ISP.reg[i];
	if(camera_para.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para.PREDGAMMA.gamma[camera_para.PREDGAMMA.gamma_select-1][10]);
	}
#endif	
}

void isp_to_camera_para(void)
{
#if (defined(DRV_ISP_6228_SERIES))
	kal_uint32	i;
	camera_para.ISP.reg[5]=REG_ISP_RGB_OFFSET_ADJUS;//0014h
	for(i=12;i<53;i++)//0030h~00D0h
		camera_para.ISP.reg[i] = *((volatile unsigned int *)(CAMERA_base + i*4));
	for(i=71;i<87;i++)//011Ch~0158h
		camera_para.ISP.reg[i] = *((volatile unsigned int *)(CAMERA_base + i*4));
	for(i=88;i<99;i++)//01A0h~01C8
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4 + 64));
	camera_para.ISP.reg[AutoDefect_Reg1_ID+2]=REG_ISP_FLASH_CTRL;//01D4h
	/* copy ISP_FRAME_COUNT 0x1D8[15:8] but reserve other control bits */	
	camera_para.ISP.reg[AutoDefect_Reg1_ID+3] &= ~REG_CAM_RESET_ISP_FRAME_COUNT_MASK;//0x01D8
	camera_para.ISP.reg[AutoDefect_Reg1_ID+3] |= REG_ISP_RESET&REG_CAM_RESET_ISP_FRAME_COUNT_MASK;
	camera_para.ISP.reg[AutoDefect_Reg1_ID+5]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL3;//01E0h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+6]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL4;//01E4h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+7]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL5;//01E8h
	/* disable copy 0214h~023Ch shading reg to global variable */	
	camera_para.ISP.reg[128]=REG_ISP_IMGPROC_HUE0;//0240h
	camera_para.ISP.reg[129]=REG_ISP_IMGPROC_HUE1;//0244h
#elif (defined(DRV_ISP_6229_SERIES))
	kal_uint32	i;
	kal_uint32 temp1, temp2;
	
	camera_para.ISP.reg[5]=REG_ISP_RGB_OFFSET_ADJUS;//0014h
	for(i=12;i<52;i++)//0030h~00D0h
		camera_para.ISP.reg[i] = *((volatile unsigned int *)(CAMERA_base + i*4));
	camera_para.ISP.reg[gamma_global_1024_no] &= REG_GAMMA_OPERATION_1024_ENABLE_BIT;
	camera_para.ISP.reg[gamma_global_1024_no] |= (*((volatile unsigned int *)(CAMERA_base + gamma_global_1024_no*4)) &
		(~REG_GAMMA_OPERATION_1024_ENABLE_BIT));
	for(i=71;i<87;i++)//011Ch~0158h
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4));
	for(i=88;i<95;i++)//0160h~0178h
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4));
	camera_para.ISP.reg[AutoDefect_Reg1_ID+2]=REG_ISP_FLASH_CTRL;//01D4h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+5]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL3;//01E0h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+6]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL4;//01E4h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+7]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL5;//01E8h
	/* disable copy 0214h~023Ch shading reg to global variable */
	for(i=147;i<152;i++)//024Ch~025Ch
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4));
	//bypass gamma	
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	ENABLE_GAMMA_FUNCTION_BYPASS;//disable gamma
	DISABLE_1024_GAMMA_TABLE;//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
		camera_gamma.gamma[i]=INTMEM_GAMMA_1024(i);
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
	//restore gamma enable	
#elif (defined(DRV_ISP_6227_SERIES))
	kal_uint32	i;
	kal_uint32 temp1, temp2;
	
	camera_para.ISP.reg[5]=REG_ISP_RGB_OFFSET_ADJUS;//0014h
	for(i=12;i<52;i++)//0030h~00D0h
		camera_para.ISP.reg[i] = *((volatile unsigned int *)(CAMERA_base + i*4));
	camera_para.ISP.reg[gamma_global_1024_no] &= REG_GAMMA_OPERATION_1024_ENABLE_BIT;
	camera_para.ISP.reg[gamma_global_1024_no] |= (*((volatile unsigned int *)(CAMERA_base + gamma_global_1024_no*4)) &
		(~REG_GAMMA_OPERATION_1024_ENABLE_BIT));
	for(i=71;i<87;i++)//011Ch~0158h
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4));
	for(i=88;i<95;i++)//0160h~0178h
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4));
	camera_para.ISP.reg[AutoDefect_Reg1_ID+2]=REG_ISP_FLASH_CTRL;//01D4h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+5]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL3;//01E0h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+6]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL4;//01E4h
	camera_para.ISP.reg[AutoDefect_Reg1_ID+7]=REG_ISP_HISTOGRAM_BOUNDARY_CTRL5;//01E8h
	/* disable copy 0214h~023Ch shading reg to global variable */
	for(i=139;i<144;i++)//024Ch~025Ch
		camera_para.ISP.reg[i]=*((volatile unsigned int *) (CAMERA_base + i*4 + 32));
	//bypass gamma	
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	ENABLE_GAMMA_FUNCTION_BYPASS;//disable gamma
	DISABLE_1024_GAMMA_TABLE;//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
		camera_gamma.gamma[i]=INTMEM_GAMMA_1024(i);
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
	//restore gamma enable	
#elif (defined(DRV_ISP_6219_SERIES))
	kal_uint32	i;
	
	camera_para.ISP.reg[5] = *((volatile unsigned int *)(CAMERA_base+20));
	for(i=13;i<53;i++)//0034h~00D0h
	{
		camera_para.ISP.reg[i] = *((volatile unsigned int *)(CAMERA_base + i*4));
	}
#endif
}

void camera_para_to_ae(void)
{
#if (!defined(DRV_ISP_6225_SERIES))
	ae_set_expovalue(camera_para.AE.TargetLum);
	ae_select_stepperev(camera_para.AE.StepperEV);
	eShutter=camera_para.AE.iniShutter;
#if (!defined(DRV_ISP_6219_SERIES))
//	AE_INDEX=camera_para.AE.iniExpoIdx;
#else   // MT6219
	image_sensor_func->set_sensor_eshutter(eShutter);
#endif
#endif
}

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
/* different register setting for shading & autodefect */
/* apply global variable to reg */
void apply_camera_shading_to_reg(camera_comp_set_num p_set_mode)
{
	kal_uint32 i;
	kal_uint16 sensor_width,sensor_height;	
	kal_uint32 temp1, temp2;
	image_sensor_func->get_sensor_size(&sensor_width,&sensor_height);	
	if (shading_apply_mode == CAMERA_SHADING_PREVIEW_COPY2_TAKE)
	{	
		if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
		{		
			/* set radius factor */
			temp1 = camera_para.ISP.reg[Shading_Reg1_ID];
			/* set center Y */
			temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
			if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
			{
				temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
			}
			else
			{
				temp2 = 0;
			}
			temp1 &= ~REG_SHADING_CENTERY_MASK;
			temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
			/* set center X */
			temp2 = temp1&REG_SHADING_CENTERX_MASK;
			if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
			{
				temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
			}
			else
			{
				temp2 = 0;
			}
			temp1 &= ~REG_SHADING_CENTERX_MASK;
			temp1 |= temp2&REG_SHADING_CENTERX_MASK;
			*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
			for(i=1;i<11;i++)//0214h~023Ch
				*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.ISP.reg[Shading_Reg1_ID+i];
		}
		else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
		{			
		      	if((exposure_window.exposure_window_width >= sensor_width) || 	// FULL Mode
	      			(exposure_window.exposure_window_height >= sensor_height))			
			{
				/* set radius factor */
				temp1 = camera_para.ISP.reg[Shading_Reg1_ID];
				temp2 = (temp1&REG_SHADING_RADIUS_FACTOR_MASK)>>12;
				temp2 += 1;
				temp1 &= ~REG_SHADING_RADIUS_FACTOR_MASK;
				temp1 |= ((temp2<<12)&REG_SHADING_RADIUS_FACTOR_MASK);
				/* set center Y */
				temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
				temp2 = temp2*2;
				if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
				{
					temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERY_MASK;
				temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
				/* set center X */
				temp2 = temp1&REG_SHADING_CENTERX_MASK;
				temp2 = temp2*2;
				if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
				{
					temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERX_MASK;
				temp1 |= temp2&REG_SHADING_CENTERX_MASK;
				*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
				for (i=1;i<11;i++)
					*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.ISP.reg[Shading_Reg1_ID+i];
			}
			else//Preview size
			{
				/* set radius factor */
				temp1 = camera_para.ISP.reg[Shading_Reg1_ID];
				/* set center Y */
				temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
				if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
				{
					temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERY_MASK;
				temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
				/* set center X */
				temp2 = temp1&REG_SHADING_CENTERX_MASK;
				if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
				{
					temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERX_MASK;
				temp1 |= temp2&REG_SHADING_CENTERX_MASK;
				*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
				for(i=1;i<11;i++)//0214h~023Ch
			*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.ISP.reg[Shading_Reg1_ID+i];
	}
		}
	}
	else if (shading_apply_mode == CAMERA_SHADING_TAKE_COPY2_PREVIEW)
	{	
		if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
		{		
			/* set radius factor */
			temp1 = camera_para.COMP.shading_cap[0];
			temp2 = (temp1&REG_SHADING_RADIUS_FACTOR_MASK)>>12;
			temp2 -= 1;
			temp1 &= ~REG_SHADING_RADIUS_FACTOR_MASK;
			temp1 |= ((temp2<<12)&REG_SHADING_RADIUS_FACTOR_MASK);
			/* set center Y */
			temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
			temp2 = (temp2+1)>>1;
			if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
			{
				temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
			}
			else
			{
				temp2 = 0;
			}			
			temp1 &= ~REG_SHADING_CENTERY_MASK;
			temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
			/* set center X */
			temp2 = temp1&REG_SHADING_CENTERX_MASK;
			temp2 = (temp2+1)>>1;
			if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
			{
				temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
			}
			else
			{
				temp2 = 0;
			}			
			temp1 &= ~REG_SHADING_CENTERX_MASK;
			temp1 |= temp2&REG_SHADING_CENTERX_MASK;
			*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
			for(i=1;i<11;i++)//0214h~023Ch
				*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.COMP.shading_cap[i];
		}
		else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
		{			
		      	if((exposure_window.exposure_window_width >= sensor_width) || 	// FULL Mode
	      			(exposure_window.exposure_window_height >= sensor_height))			
			{
				/* set radius factor */
				temp1 = camera_para.COMP.shading_cap[0];
				/* set center Y */
				temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
				if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
				{
					temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERY_MASK;
				temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
				/* set center X */
				temp2 = temp1&REG_SHADING_CENTERX_MASK;
				if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
				{
					temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
				}
				else
				{
					temp2 = 0;
				}						
				temp1 &= ~REG_SHADING_CENTERX_MASK;
				temp1 |= temp2&REG_SHADING_CENTERX_MASK;
				*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
				for (i=1;i<11;i++)
			*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.COMP.shading_cap[i];
}
			else
			{
				/* set radius factor */
				temp1 = camera_para.COMP.shading_cap[0];
				temp2 = (temp1&REG_SHADING_RADIUS_FACTOR_MASK)>>12;
				temp2 -= 1;
				temp1 &= ~REG_SHADING_RADIUS_FACTOR_MASK;
				temp1 |= ((temp2<<12)&REG_SHADING_RADIUS_FACTOR_MASK);
				/* set center Y */
				temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
				temp2 = (temp2+1)>>1;
				if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
				{
					temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERY_MASK;
				temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
				/* set center X */
				temp2 = temp1&REG_SHADING_CENTERX_MASK;
				temp2 = (temp2+1)>>1;
				if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
				{
					temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
				}
				else
				{
					temp2 = 0;
				}						
				temp1 &= ~REG_SHADING_CENTERX_MASK;
				temp1 |= temp2&REG_SHADING_CENTERX_MASK;
				*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
				for(i=1;i<11;i++)//0214h~023Ch
					*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.COMP.shading_cap[i];
			}
		}
	}	
	else//other or normal mode
	{	
		if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
		{		
			/* set radius factor */
			temp1 = camera_para.ISP.reg[Shading_Reg1_ID];
			/* set center Y */
			temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
			if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
			{
				temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
			}
			else
			{
				temp2 = 0;
			}
			temp1 &= ~REG_SHADING_CENTERY_MASK;
			temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
			/* set center X */
			temp2 = temp1&REG_SHADING_CENTERX_MASK;
			if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
			{
				temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
			}
			else
	{		
				temp2 = 0;
			}
			temp1 &= ~REG_SHADING_CENTERX_MASK;
			temp1 |= temp2&REG_SHADING_CENTERX_MASK;
			*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
			for(i=1;i<11;i++)//0214h~023Ch
			*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.ISP.reg[Shading_Reg1_ID+i];
	}
		else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
	{			
	      if((exposure_window.exposure_window_width >= sensor_width) || 	// FULL Mode
	      	(exposure_window.exposure_window_height >= sensor_height))			
			{
				/* set radius factor */
				temp1 = camera_para.COMP.shading_cap[0];
				/* set center Y */
				temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
				if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
				{
					temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERY_MASK;
				temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
				/* set center X */
				temp2 = temp1&REG_SHADING_CENTERX_MASK;
				if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
				{
					temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
				}
				else
				{
					temp2 = 0;
				}						
				temp1 &= ~REG_SHADING_CENTERX_MASK;
				temp1 |= temp2&REG_SHADING_CENTERX_MASK;
				*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
				for (i=1;i<11;i++)
			*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.COMP.shading_cap[i];
}
			else
			{
				/* set radius factor */
				temp1 = camera_para.ISP.reg[Shading_Reg1_ID];
				/* set center Y */
				temp2 = (temp1&REG_SHADING_CENTERY_MASK)>>16;
				if (2*(isp_grab_start_y - exposure_window.grab_start_y) < temp2)
				{
					temp2 -= 2*(isp_grab_start_y - exposure_window.grab_start_y);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERY_MASK;
				temp1 |= ((temp2<<16)&REG_SHADING_CENTERY_MASK);
				/* set center X */
				temp2 = temp1&REG_SHADING_CENTERX_MASK;
				if (2*(isp_grab_start_x - exposure_window.grab_start_x) < temp2)
				{
					temp2 -= 2*(isp_grab_start_x - exposure_window.grab_start_x);
				}
				else
				{
					temp2 = 0;
				}
				temp1 &= ~REG_SHADING_CENTERX_MASK;
				temp1 |= temp2&REG_SHADING_CENTERX_MASK;
				*((volatile unsigned int *) ISP_SHADING_CTRL1_REG) = temp1;
				for(i=1;i<11;i++)//0214h~023Ch
					*((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4)) = camera_para.ISP.reg[Shading_Reg1_ID+i];				
			}					
	}
}
}

/* apply reg to global variable */
void update_camera_shading_from_reg(camera_comp_set_num p_set_mode)
{
	kal_uint32 i;
	if ((p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)||
		(p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET))
		for(i=0;i<11;i++)//0214h~023Ch
			camera_para.ISP.reg[i+Shading_Reg1_ID] = *((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4));
	else if ((p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)||
			(p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET))
		for (i=0;i<11;i++)
			camera_para.COMP.shading_cap[i] = *((volatile unsigned int *) (ISP_SHADING_CTRL1_REG + i*4 ));
}

/* apply global variable to reg */
void apply_camera_autodefect_to_reg(camera_comp_set_num p_set_mode)
{
	REG_ISP_AUTO_DEFECT_CTRL1 &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
	if (p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.ISP.reg[AutoDefect_Reg1_ID]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.ISP.reg[AutoDefect_Reg1_ID+1]; //0x1D0
	}
	else if (p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.COMP.autodefect_pre_low[0]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.COMP.autodefect_pre_low[1]; //0x1D0		
	}	
	else if (p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.COMP.autodefect_cap_nor[0]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.COMP.autodefect_cap_nor[1]; //0x1D0		
}
	else if (p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET)
	{
		REG_ISP_AUTO_DEFECT_CTRL1 |= REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK&camera_para.COMP.autodefect_cap_low[0]; //0x1CC
		REG_ISP_AUTO_DEFECT_CTRL2 = camera_para.COMP.autodefect_cap_low[1]; //0x1D0		
		
	}
}

/* apply reg to global variable */
void update_camera_autodefect_from_reg(camera_comp_set_num p_set_mode)
{
	if (p_set_mode == CAMERA_COMP_PREVIEW_NORMAL_SET)
	{
		camera_para.ISP.reg[AutoDefect_Reg1_ID] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.ISP.reg[AutoDefect_Reg1_ID] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.ISP.reg[AutoDefect_Reg1_ID+1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0
	}
	else if (p_set_mode == CAMERA_COMP_PREVIEW_LOWLIGHT_SET)
	{
		camera_para.COMP.autodefect_pre_low[0] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.COMP.autodefect_pre_low[0] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.COMP.autodefect_pre_low[1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0		
	}	
	else if (p_set_mode == CAMERA_COMP_CAPTURE_NORMAL_SET)
	{
		camera_para.COMP.autodefect_cap_nor[0] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.COMP.autodefect_cap_nor[0] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.COMP.autodefect_cap_nor[1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0		
	}
	else if (p_set_mode == CAMERA_COMP_CAPTURE_LOWLIGHT_SET)
	{
		camera_para.COMP.autodefect_cap_low[0] &= ~REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK;//reserve AE_interval 0x1CC[15:8]
		camera_para.COMP.autodefect_cap_low[0] |= REG_ISP_AUTO_DEFECT_CTRL1&REG_AUTO_DEFECT_CTRL1_BIT31_16_MASK; //0x1CC
		camera_para.COMP.autodefect_cap_low[1] = REG_ISP_AUTO_DEFECT_CTRL2; //0x1D0		
		
	}
}

kal_uint8 Set_camera_shading_mode(camera_shading_mode_set_num p_shading_set)
{
	kal_uint32 temp1=0, temp2=0;
	kal_uint8 r_shading=CAMERA_SHADING_NORMAL_SET;
	if (p_shading_set == CAMERA_SHADING_PREVIEW_COPY2_TAKE)
	{
		r_shading = CAMERA_SHADING_PREVIEW_COPY2_TAKE;
	}
	else if (p_shading_set == CAMERA_SHADING_TAKE_COPY2_PREVIEW)
	{
		/* check redius factor */
		temp1 = camera_para.COMP.shading_cap[0];
		temp2 = (temp1&REG_SHADING_RADIUS_FACTOR_MASK)>>12;
		if (temp2 < 1)
		{
			r_shading = CAMERA_SHADING_SET_FAIL_KEEP_NORMAL_SET;
		}
		else
		{
			r_shading = CAMERA_SHADING_TAKE_COPY2_PREVIEW;		
		}
	}
	else
	{
		r_shading = CAMERA_SHADING_NORMAL_SET;
	}
	shading_apply_mode = r_shading;
	return r_shading;
}

kal_uint8 Get_camera_shading_mode(void)
{
	return shading_apply_mode;
}

#endif

// interface to get/set camera_para global variable 
nvram_camera_para_struct *get_camera_para(void)
{
	return &camera_para;
}

void set_camera_para(const nvram_camera_para_struct *p_cam_para)
{
	if( NULL != p_cam_para ) {
		camera_para = *p_cam_para;
	}
}

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
nvram_camera_defect_struct *get_camera_defect(void)
{
	return &camera_defect;
}
	
void set_camera_defect(const nvram_camera_defect_struct *p_cam_defect)
{
	if( NULL != p_cam_defect ) {
		camera_defect = *p_cam_defect;
	}	
}
	
nvram_camera_lens_struct *get_camera_lens(void)
{
	return &camera_lens;	
}
	
void set_camera_lens(const nvram_camera_lens_struct *p_cam_lens)
{
	if( NULL != p_cam_lens ) {
		camera_lens = *p_cam_lens;
	}	
}	

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
nvram_camera_gamma_struct *get_camera_gamma(void)
{
	return &camera_gamma;
}
	
void set_camera_gamma(const nvram_camera_gamma_struct *p_cam_gamma)
{
	if( NULL != p_cam_gamma ) {
		camera_gamma = *p_cam_gamma;
	}		
}
#endif

#endif

// interface to get default hardcoded camera_para 
const nvram_camera_para_struct *get_default_camera_para(void)
{
	return &CAMERA_PARA_DEFAULT_VALUE;
}

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
const nvram_camera_defect_struct *get_default_camera_defect(void)
{
	return &CAMERA_DEFECT_DEFAULT_VALUE;
}

const nvram_camera_lens_struct *get_default_camera_lens(void)
{
	return &CAMERA_LENS_DEFAULT_VALUE;
}

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6228_SERIES)))
const nvram_camera_gamma_struct *get_default_camera_gamma(void)
{
   return &CAMERA_GAMMA_DEFAULT_VALUE;
}
#endif
#endif

#if (!(defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6225_SERIES)))
// Defect Table Interface START
#if (defined(__MTK_TARGET__))
#pragma arm section rwdata = "INTERNRW1", zidata = "INTERNZI1"
#endif
kal_uint32 isp_defect_table[MAX_DEFECT_NUM];
#if (defined(__MTK_TARGET__))
#pragma arm section rwdata , zidata
#endif
// interface to apply camera_para to defect pixel
void load_defect_table_para(kal_uint8	table_id)
{
	kal_uint32	i=0, start_idx, end_idx, idx;	
	kal_uint16	x, y, x_offset=0, y_offset=0;		

	/* calculate x, y offset */
	if(camera_system_operation_mode==CAMERA_SYSTEM_NORMAL_MODE)		
	{
	x_offset = (DRV_Reg32(ISP_TG_GRAB_RANGE_PIXEL_CONFIG_REG)>>16) - exposure_window.grab_start_x;
	y_offset = (DRV_Reg32(ISP_TG_GRAB_RANGE_LINE_CONFIG_REG)>>16) - exposure_window.grab_start_y;
	}
	/* Load capture/preview defect table */	
	if(table_id==DEFECT_MODE_CAPTURE)	
	{
		start_idx = 0;
		end_idx = MAX_DEFECT_NUM;
	}
	else							
		{
		start_idx = MAX_DEFECT_NUM;
		end_idx = MAX_DEFECT_NUM+MAX_PV_DEFECT_NUM;
		}
	idx  = 0;	
	for(i=start_idx;i<end_idx;i++)
		{
			if(camera_defect.defect[i]==0xFFFFFFFF)
				break;
		/* Check defect pixel pos inside image or not */
		if( ((camera_defect.defect[i]&0xFFFF)>=x_offset) &&
			 (((camera_defect.defect[i]>>16)&0xFFFF)>=y_offset) )
		{
			x = (camera_defect.defect[i]&0xFFFF) - x_offset;		// shift
			y = ((camera_defect.defect[i]>>16)&0xFFFF) - y_offset;
			isp_defect_table[idx] = (y<<16) | x;							
			idx++;
		}		
	}
 	isp_defect_table[idx] = 0xFFFFFFFF;		

	/* set defect table address */ 
	REG_ISP_DEFECT_PIXEL_TABLE_ADDR = (unsigned int)(&isp_defect_table);  
	REG_ISP_DEFECT_PIXEL_CONFIG |= 0x00040000;  // Add Defect Table Line Buffer
}
// Defect Table Interface END
#endif

void apply_take_image_with_gamma_1024_by_flag(void)
{
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	if (camera_para.ISP.reg[gamma_global_1024_no] & REG_GAMMA_OPERATION_1024_ENABLE_BIT)
		ENABLE_1024_GAMMA_TABLE
	else
		DISABLE_1024_GAMMA_TABLE
#endif
}

void recover_preview_with_gamma_1024_disabled(void)
{
#if (defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6229_SERIES))
	DISABLE_1024_GAMMA_TABLE
#endif
}

/****************************************************************************
 *          EXIF																	*
 ****************************************************************************/
 #if ((!defined(DRV_ISP_6219_SERIES))&&defined(EXIF_SUPPORT))
void exif_update_MTK_para_struct(exif_MTK_para_struct* para)
{
	exif_MTK_camera_para_struct* mtk_para_data;
	
	mtk_para_data=(exif_MTK_camera_para_struct*)para->mtk_para;
	
	exif_update_MTK_para_struct_AEAWB(mtk_para_data);
#if (defined(AF_SUPPORT))
	exif_update_MTK_para_struct_AF(mtk_para_data);
#endif
}
#endif
#endif
