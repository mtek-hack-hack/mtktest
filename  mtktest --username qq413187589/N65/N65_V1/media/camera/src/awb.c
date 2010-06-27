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
 *   awb.c
 *
 * Project:
 * --------
 *   MT6219,MT6226,MT6227,MT6228,MT6229,MT6230
 *
 * Description:
 * ------------
 *   Auto White Balance Algorithm
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "drv_features.h" 
#if ((defined(DRV_ISP_6219_SERIES)||defined(DRV_ISP_6227_SERIES)||defined(DRV_ISP_6225_SERIES)||defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))&&defined(ISP_SUPPORT))
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "ae_awb.h"
#include "af.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "sccb.h"
#include "camera_para.h"
#include "med_api.h"
#include "gpio_sw.h"
#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
#endif

#if (!defined(DRV_ISP_6219_SERIES))
#include "isp_flashlight.h"
#endif

/**************   AWB DECLARATION    ***************************************/
#if (defined(DRV_ISP_6219_SERIES))
kal_uint16	AWB_Rgain=128,AWB_Ggain=128,AWB_Bgain=128;
kal_uint16	tmp_Rgain=128,tmp_Ggain=128,tmp_Bgain=128;
#else
kal_uint16	AWB_Rgain=128,AWB_GRgain=128,AWB_Bgain=128,AWB_GBgain=128;
kal_uint16	tmp_Rgain=128,tmp_GRgain=128,tmp_Bgain=128,tmp_GBgain=128;
kal_uint16	Manual_AWB_Rgain=128,Manual_AWB_GRgain=128,Manual_AWB_Bgain=128,Manual_AWB_GBgain=128;
#endif
kal_uint16	Rgain_max=128,Ggain_max=128,Bgain_max=128;
kal_uint16	Rgain_min=128,Ggain_min=128,Bgain_min=128;
kal_uint32	Acc_R,Acc_G,Acc_B;
kal_uint32	Acc_Cnt;
kal_uint8	fstAwbInitFlag=0;
kal_bool	awbFastFlag;

extern kal_bool awb_enable_flag_backup;
/****************************************************************************
 *          AWB  Main
 ****************************************************************************/
void init_awb(void)
{
	ENABLE_AWB_AREA_ALL;		
	ENABLE_OPD_COUNTER;
	DISABLE_BYPASS_INTERPOLATION_MOD;	
	SEL_COLOR_SUP_MODE(4);		
	SET_OPD_MOD_Y_LIMIT(4);		

	awb_enable_flag=ISP_ON;
	awb_config(640,480);
	awb_gain_max_min();
	fstAwbInitFlag = 0;
	awb_fast_method(KAL_FALSE);
}

void awb_on_off(kal_bool flag)
{
	awb_enable_flag=flag;
	awb_enable_flag_backup=awb_enable_flag;
	if ( flag && (fstAwbInitFlag==0) ) {
		awbEntryCnt = 0;
		fstAwbInitFlag = 1;
	}

}

void awb_fast_method(kal_bool flag)
{
	awbFastFlag = flag;	
	
}

void awb_reset(void)
{
#if (defined(DRV_ISP_6219_SERIES))
	AWB_Rgain=128;
	AWB_Ggain=128;
	AWB_Bgain=128;
#else
	AWB_Rgain=128;
	AWB_GRgain=128;
	AWB_Bgain=128;
	AWB_GBgain=128;
#endif	
}	

/****************************************************************************
 *          Auto White Balance												*
 ****************************************************************************/
void awb_config(kal_uint16 Hsize,kal_uint16 Vsize)
{
	SET_AWB_WINDOW(1,1,Hsize>>4-1,Vsize>>4-1);	
}

void awb_set_gain(void)
{
#if (defined(DRV_ISP_6219_SERIES))	
	SET_INTER_STAGE1_R_GAIN((kal_uint32)(AWB_Rgain&0x01FF));
	SET_INTER_STAGE1_G_GAIN((kal_uint32)(AWB_Ggain&0x01FF));
	SET_INTER_STAGE1_B_GAIN((kal_uint32)(AWB_Bgain&0x01FF));
#else
	SET_INTER_STAGE1_R_GAIN((kal_uint32)(AWB_Rgain&0x01FF));
	SET_INTER_STAGE1_GR_GAIN((kal_uint32)(AWB_GRgain&0x01FF));
	SET_INTER_STAGE1_B_GAIN((kal_uint32)(AWB_Bgain&0x01FF));
	SET_INTER_STAGE1_GB_GAIN((kal_uint32)(AWB_GBgain&0x01FF));
#endif	
}

void awb_set_manual_gain(kal_uint8 light)
{
	switch(light)
	{
		case CAM_WB_AUTO :
			awb_on_off(KAL_TRUE);
			break;
		case CAM_WB_CLOUD :
			awb_on_off(KAL_FALSE);
#if (defined(DRV_ISP_6219_SERIES))
			AWB_Rgain=camera_para.AWB.LightSource[0][1];
			AWB_Ggain=camera_para.AWB.LightSource[0][2];
			AWB_Bgain=camera_para.AWB.LightSource[0][3];
#else
			AWB_Rgain =camera_para.AWB.LightSource[0][1];
			AWB_GRgain=camera_para.AWB.LightSource[0][2];
			AWB_Bgain =camera_para.AWB.LightSource[0][3];
			AWB_GBgain=camera_para.AWB.LightSource[0][2];
#endif
			break;
		case CAM_WB_DAYLIGHT :
			awb_on_off(KAL_FALSE);
#if (defined(DRV_ISP_6219_SERIES))
			AWB_Rgain=camera_para.AWB.LightSource[1][1];
			AWB_Ggain=camera_para.AWB.LightSource[1][2];
			AWB_Bgain=camera_para.AWB.LightSource[1][3];
#else
			AWB_Rgain =camera_para.AWB.LightSource[1][1];
			AWB_GRgain=camera_para.AWB.LightSource[1][2];
			AWB_Bgain =camera_para.AWB.LightSource[1][3];
			AWB_GBgain=camera_para.AWB.LightSource[1][2];
#endif
			break;
		case CAM_WB_INCANDESCENCE :
			awb_on_off(KAL_FALSE);
#if (defined(DRV_ISP_6219_SERIES))
			AWB_Rgain=camera_para.AWB.LightSource[2][1];
			AWB_Ggain=camera_para.AWB.LightSource[2][2];
			AWB_Bgain=camera_para.AWB.LightSource[2][3];
#else
			AWB_Rgain =camera_para.AWB.LightSource[2][1];
			AWB_GRgain=camera_para.AWB.LightSource[2][2];
			AWB_Bgain =camera_para.AWB.LightSource[2][3];
			AWB_GBgain=camera_para.AWB.LightSource[2][2];
#endif
			break;
		case CAM_WB_FLUORESCENT :
			awb_on_off(KAL_FALSE);
#if (defined(DRV_ISP_6219_SERIES))
			AWB_Rgain=camera_para.AWB.LightSource[3][1];
			AWB_Ggain=camera_para.AWB.LightSource[3][2];
			AWB_Bgain=camera_para.AWB.LightSource[3][3];
#else
			AWB_Rgain =camera_para.AWB.LightSource[3][1];
			AWB_GRgain=camera_para.AWB.LightSource[3][2];
			AWB_Bgain =camera_para.AWB.LightSource[3][3];
			AWB_GBgain=camera_para.AWB.LightSource[3][2];
#endif
			break;
		case CAM_WB_TUNGSTEN :
			awb_on_off(KAL_FALSE);
#if (defined(DRV_ISP_6219_SERIES))
			AWB_Rgain=camera_para.AWB.LightSource[4][1];
			AWB_Ggain=camera_para.AWB.LightSource[4][2];
			AWB_Bgain=camera_para.AWB.LightSource[4][3];
#else
			AWB_Rgain =camera_para.AWB.LightSource[4][1];
			AWB_GRgain=camera_para.AWB.LightSource[4][2];
			AWB_Bgain =camera_para.AWB.LightSource[4][3];
			AWB_GBgain=camera_para.AWB.LightSource[4][2];
#endif
			break;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
		case CAM_WB_MANUAL :
			awb_on_off(KAL_FALSE);
			AWB_Rgain =camera_para.AWB.LightSource[5][1];
			AWB_GRgain=camera_para.AWB.LightSource[5][2];
			AWB_Bgain =camera_para.AWB.LightSource[5][3];
			AWB_GBgain=camera_para.AWB.LightSource[5][2];
			break;
#endif
		default :
			ASSERT(0);
			break;
	}
}

void awb_save_manual_gain(kal_uint8 light, kal_uint16 color_temp, kal_uint16 r_gain, kal_uint16 g_gain, kal_uint16 b_gain)
{
	switch(light)
	{
		case CAM_WB_AUTO :
			break;
		case CAM_WB_CLOUD :
			camera_para.AWB.LightSource[0][0]=color_temp;
			camera_para.AWB.LightSource[0][1]=r_gain;
			camera_para.AWB.LightSource[0][2]=g_gain;
			camera_para.AWB.LightSource[0][3]=b_gain;
#if (!defined(DRV_ISP_6219_SERIES))
			camera_para.AWB.LightSource[0][4]=g_gain;
#endif
			break;
		case CAM_WB_DAYLIGHT :
			camera_para.AWB.LightSource[1][0]=color_temp;
			camera_para.AWB.LightSource[1][1]=r_gain;
			camera_para.AWB.LightSource[1][2]=g_gain;
			camera_para.AWB.LightSource[1][3]=b_gain;
#if (!defined(DRV_ISP_6219_SERIES))
			camera_para.AWB.LightSource[1][4]=g_gain;
#endif
			break;
		case CAM_WB_INCANDESCENCE :
			camera_para.AWB.LightSource[2][0]=color_temp;
			camera_para.AWB.LightSource[2][1]=r_gain;
			camera_para.AWB.LightSource[2][2]=g_gain;
			camera_para.AWB.LightSource[2][3]=b_gain;
#if (!defined(DRV_ISP_6219_SERIES))
			camera_para.AWB.LightSource[2][4]=g_gain;
#endif
			break;
		case CAM_WB_FLUORESCENT :
			camera_para.AWB.LightSource[3][0]=color_temp;
			camera_para.AWB.LightSource[3][1]=r_gain;
			camera_para.AWB.LightSource[3][2]=g_gain;
			camera_para.AWB.LightSource[3][3]=b_gain;
#if (!defined(DRV_ISP_6219_SERIES))
			camera_para.AWB.LightSource[3][4]=g_gain;
#endif
			break;
		case CAM_WB_TUNGSTEN :
			camera_para.AWB.LightSource[4][0]=color_temp;
			camera_para.AWB.LightSource[4][1]=r_gain;
			camera_para.AWB.LightSource[4][2]=g_gain;
			camera_para.AWB.LightSource[4][3]=b_gain;
#if (!defined(DRV_ISP_6219_SERIES))
			camera_para.AWB.LightSource[4][4]=g_gain;
#endif
			break;
#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))			
		case CAM_WB_MANUAL :
			camera_para.AWB.LightSource[5][0]=0xFFFF;
			camera_para.AWB.LightSource[5][1]=r_gain;
			camera_para.AWB.LightSource[5][2]=g_gain;
			camera_para.AWB.LightSource[5][3]=b_gain;
#if (!defined(DRV_ISP_6219_SERIES))
			camera_para.AWB.LightSource[5][4]=g_gain;
#endif
			break;
#endif			
		default :
			ASSERT(0);
			break;
	}
	awb_gain_max_min();
}

void awb_read_all_manual_gain(kal_uint16 manualWB[5][4])
{
	kal_uint8 i,j;

#if (!defined(DRV_ISP_6219_SERIES))	
	for(i=0;i<5;i++)
#else
	for(i=0;i<6;i++)
#endif
	{
		for(j=0;j<4;j++)
		{
			manualWB[i][j]=camera_para.AWB.LightSource[i][j];
		}
	}
}


void awb_gain_max_min(void)
{
	kal_uint8 i,j;
	kal_uint16 max[3],min[3];
	
	for(j=1;j<4;j++)
	{
		max[j-1]=camera_para.AWB.LightSource[0][j];
		min[j-1]=camera_para.AWB.LightSource[0][j];
		for(i=1;i<5;i++)
		{
			if(camera_para.AWB.LightSource[i][j]>max[j-1])
			{
				max[j-1]=camera_para.AWB.LightSource[i][j];
			}
			if(camera_para.AWB.LightSource[i][j]<min[j-1])
			{
				min[j-1]=camera_para.AWB.LightSource[i][j];
			}
		}
	}
	
	Rgain_max=max[0];
	Ggain_max=max[1];
	Bgain_max=max[2];
	Rgain_min=min[0];
	Ggain_min=min[1];
	Bgain_min=min[2];
}

#if (defined(DRV_ISP_6228_SERIES)||defined(DRV_ISP_6229_SERIES))
void camera_manual_wb_setting(void)
{
	/* clear isp setting : AWB, CC, Flare, Edge, Gamma, Sat */
	SET_INTER_STAGE1_R_GAIN(128);
	SET_INTER_STAGE1_GR_GAIN(128);
	SET_INTER_STAGE1_B_GAIN(128);
	SET_INTER_STAGE1_GB_GAIN(128);
	SET_COLOR_MATRIX1(0x20,0,0);
	SET_COLOR_MATRIX2(0,0x20,0);
	SET_COLOR_MATRIX3(0,0,0x20);
	SET_AWB_R_GAIN(128);										
	SET_AWB_G_GAIN(128);
	SET_AWB_B_GAIN(128);
	DISABLE_RGB_EDGE_GAIN;
	DISABLE_Y_EDGE;
	ENABLE_GAMMA_FUNCTION_BYPASS;
	SET_HUE_U_GAIN(0x20);
	SET_HUE_V_GAIN(0x20);
}

void camera_mwb_process(camera_mwb_process_struct *mwb_data)
{
	/* calculate RGB data & set manual wb gain */	
	kal_uint32 rgain=128, ggain=128, bgain=128;
	

	/* RGB565 */

#if 0 /* RGB888 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	

	if(!((Acc_R==0)||(Acc_G==0)||(Acc_B==0)))
	{
		if((Acc_B>=Acc_G)&&(Acc_B>=Acc_R))
		{
		    if(Acc_R > 128){
			    rgain=Acc_B/(Acc_R>>7);
			}
			else{
			    rgain=Acc_B/Acc_R*128;
			}
			
			if(Acc_G > 128){
			    ggain=Acc_B/(Acc_G>>7);
			}
			else{
			    ggain=Acc_B/Acc_G*128;
			}
			
			bgain=128;
		}
		else if((Acc_G>=Acc_R)&&(Acc_G>=Acc_B))
		{
		    if(Acc_R > 128){
			    rgain=Acc_G/(Acc_R>>7);
			}
			else{
			    rgain=Acc_G/Acc_R*128;
			}
			
			ggain=128;
			
			if(Acc_B > 128){
			    bgain=Acc_G/(Acc_B>>7);
			}
			else{
			    bgain=Acc_G/Acc_B*128;
			}
		}
		else if((Acc_R>=Acc_G)&&(Acc_R>=Acc_B))
		{
			rgain=128;
			
			if(Acc_G > 128){
			    ggain=Acc_R/(Acc_G>>7);
			}
			else{
			    ggain=Acc_R/Acc_G*128;
			}
			
			if(Acc_B > 128){
			    bgain=Acc_R/(Acc_B>>7);
			}
			else {
			    bgain=Acc_R/Acc_B*128;
			}
			
		}
	
		if(rgain>0x01FF)
			rgain=0x01FF;
		if(ggain>0x01FF)
			ggain=0x01FF;
		if(bgain>0x01FF)
			bgain=0x01FF;
	
		camera_para.AWB.LightSource[5][1]=rgain;
		camera_para.AWB.LightSource[5][2]=ggain;
		camera_para.AWB.LightSource[5][3]=bgain;
		camera_para.AWB.LightSource[5][4]=ggain;
	}
	else
	{
		camera_para.AWB.LightSource[5][1]=128;
		camera_para.AWB.LightSource[5][2]=128;
		camera_para.AWB.LightSource[5][3]=128;
		camera_para.AWB.LightSource[5][4]=128;
	}


}


void backup_mwb_setting(void)
{
	Manual_AWB_Rgain =camera_para.AWB.LightSource[5][1];
	Manual_AWB_GRgain=camera_para.AWB.LightSource[5][2];
	Manual_AWB_Bgain =camera_para.AWB.LightSource[5][3];
	Manual_AWB_GBgain=camera_para.AWB.LightSource[5][4];
}

void restore_mwb_setting(void)
{
	camera_para.AWB.LightSource[5][1]=Manual_AWB_Rgain ;
	camera_para.AWB.LightSource[5][2]=Manual_AWB_GRgain;
	camera_para.AWB.LightSource[5][3]=Manual_AWB_Bgain ;
	camera_para.AWB.LightSource[5][4]=Manual_AWB_GBgain;
}
#endif

/****************************************************************************
 *          Flash Light	Control 											 *
 ****************************************************************************/
void  flashlight_awb_proc(void)
{       
#if (!(defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT)))		    
#endif
#if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))		
    kal_uint8   i, weight_p1, weight_p2;
    kal_uint16  awb_flash_1, awb_flash_2, awb_flash_rg, awb_flash_bg; 
    kal_int32   awb_weight_1=0, awb_weight_2=0; 
    
    // cal flashlight awb index and weight
    flashlight_awb_idx = AE_INDEX_Backup+device_support_info.ae.minEv/100;            
    if(AE_INDEX<AE_INDEX_Backup)
    {
        flashlight_awb_weight = 0;
    }
    else
    {
        flashlight_awb_weight = AE_INDEX - AE_INDEX_Backup;
        if(flashlight_awb_weight>16) flashlight_awb_weight = 16;
    }
    if((AE_INDEX_Backup==0)&&(avglum>((EVSTEP_FLASH_01[FLASHLIGHT_CENTER_AE_NUM-3]*expo_level)>>7)))
        flashlight_awb_idx += 1;
        // decide flashlight_awb_idx
    flashlight_awb_r_backup = AWB_Rgain;
    flashlight_awb_g_backup = AWB_GRgain;
    flashlight_awb_b_backup = AWB_Bgain; 
    for(i=0;i<FLASHLIGHT_MAX_TBL_SIZE;i++)
        {
            if(flashlight_awb_idx<=xenon_awb_mix_tbl[0][i])
            {
            awb_weight_1 = xenon_awb_mix_tbl[1][i]*(flashlight_awb_weight)/16;
            awb_weight_2 = xenon_awb_mix_tbl[2][i]*(flashlight_awb_weight)/16;
                if((i>0)&&(xenon_awb_mix_tbl[0][i]!=xenon_awb_mix_tbl[0][i-1]))
                {
                    weight_p1 = xenon_awb_mix_tbl[1][i-1]*(flashlight_awb_weight)/16;   
                    weight_p2 = xenon_awb_mix_tbl[2][i-1]*(flashlight_awb_weight)/16;                      
                awb_weight_1 = awb_weight_1 + 
                    (xenon_awb_mix_tbl[0][i]-flashlight_awb_idx)*(weight_p1-awb_weight_1)/
                        (xenon_awb_mix_tbl[0][i]-xenon_awb_mix_tbl[0][i-1]);
                awb_weight_2 = awb_weight_2 + 
                    (xenon_awb_mix_tbl[0][i]-flashlight_awb_idx)*(weight_p2-awb_weight_2)/
                        (xenon_awb_mix_tbl[0][i]-xenon_awb_mix_tbl[0][i-1]);                                                        
                }
                break;
            }
        }
        // calculate AWB Gain            
        if((device_support_info.autoflash.fwb_rgain>=device_support_info.autoflash.fwb_bgain)&&
           (device_support_info.autoflash.fwb_ggain>=device_support_info.autoflash.fwb_bgain))
        {   // B min 
        awb_flash_1 = (128-awb_weight_1)*AWB_Rgain/AWB_Bgain +
                    awb_weight_1*device_support_info.autoflash.fwb_rgain/
                    device_support_info.autoflash.fwb_bgain;
        awb_flash_2 = (128-awb_weight_2)*AWB_GRgain/AWB_Bgain +
                    awb_weight_2*device_support_info.autoflash.fwb_ggain/
                    device_support_info.autoflash.fwb_bgain;                
            awb_flash_rg = awb_flash_1*128/awb_flash_2;
            awb_flash_bg = 128*128/awb_flash_2;
        }           
        else if((device_support_info.autoflash.fwb_rgain>=device_support_info.autoflash.fwb_ggain)&&
                (device_support_info.autoflash.fwb_bgain>=device_support_info.autoflash.fwb_ggain))
        {   // G min
        awb_flash_rg = (128-awb_weight_1)*AWB_Rgain/AWB_GRgain +
                    awb_weight_1*device_support_info.autoflash.fwb_rgain/
                    device_support_info.autoflash.fwb_ggain;
        awb_flash_bg = (128-awb_weight_2)*AWB_Bgain/AWB_GRgain +
                    awb_weight_2*device_support_info.autoflash.fwb_bgain/
                    device_support_info.autoflash.fwb_ggain;                                
        }
        else
        {   // R min
        awb_flash_1 = (128-awb_weight_1)*AWB_GRgain/AWB_Rgain + 
                    awb_weight_1*device_support_info.autoflash.fwb_ggain/
                    device_support_info.autoflash.fwb_rgain;
        awb_flash_2 = (128-awb_weight_2)*AWB_Bgain/AWB_Rgain + 
                    awb_weight_2*device_support_info.autoflash.fwb_bgain/
                    device_support_info.autoflash.fwb_rgain;                                                
            awb_flash_rg = 128*128/awb_flash_1;
            awb_flash_bg = awb_flash_2*128/awb_flash_1;
        }      
        // check awb gain
        if((awb_flash_rg>128)&&(awb_flash_bg>128))
        {   // result G min
            AWB_Rgain  = awb_flash_rg;
            AWB_GRgain = 128;
            AWB_GBgain = 128;
            AWB_Bgain  = awb_flash_bg;
        }
        else if(awb_flash_rg<awb_flash_bg)
        {   // result R min
            AWB_Rgain = 128;
            AWB_GRgain= AWB_Rgain*128/awb_flash_rg;                       
            AWB_GBgain= AWB_GRgain;                                       
            AWB_Bgain = AWB_GRgain*awb_flash_bg/128;   
        }
        else
        {   // result B min
            AWB_Bgain = 128;
            AWB_GRgain = AWB_Bgain*128/awb_flash_bg;
            AWB_GBgain = AWB_GRgain;                    
            AWB_Rgain = AWB_GRgain*awb_flash_rg/128;                       
        }            
    awb_set_gain();  
#endif  // #if (defined(XENON_FLASHLIGHT_ANTI_RED_EYE)||defined(XENON_FLASHLIGHT))		    
}

#endif /* MT6219||MT6228||MT6226||MT6227||MT6229 */
