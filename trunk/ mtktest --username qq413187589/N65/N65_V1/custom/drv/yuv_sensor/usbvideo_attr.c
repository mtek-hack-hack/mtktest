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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/custom/drv/yuv_sensor/OV7670/usbvideo_attr.c,v 1.1 2007/05/17 07:11:47 bw Exp $
*
* $Id: usbvideo_attr.c 268 2009-09-28 06:17:23Z liuhongzhe $
*
* $Date: 2009-09-28 14:17:23 +0800 (星期一, 28 九月 2009) $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 268 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: usbvideo_attr.c,v $
* Revision 1.1  2007/05/17 07:11:47  bw
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
 *   usbvideo_attr.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Camera Parameter for Webcam attribute define
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
#include "isp_if.h"
#include "med_api.h"
#include "image_sensor.h"
#include "camera_para.h"

#if (defined(WEBCAM_SUPPORT))
#include "usbvideo_cam_if.h"
/* supported feature list */
const USBVideo_Attr_Info ATTR_INFO[] =
{
#if (!defined(YUV_SENSOR_SUPPORT))    
	{USBVIDEO_ATTRIBUTE_BRIGHTNESS, KAL_TRUE, KAL_TRUE},
	{USBVIDEO_ATTRIBUTE_CONTRAST, KAL_TRUE, KAL_TRUE},
	{USBVIDEO_ATTRIBUTE_HUE, KAL_TRUE, KAL_TRUE},	
	{USBVIDEO_ATTRIBUTE_HUE_AUTO, KAL_TRUE, KAL_TRUE},		
	{USBVIDEO_ATTRIBUTE_SATURATION, KAL_TRUE, KAL_TRUE},		
	{USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, KAL_TRUE, KAL_TRUE},						
	{USBVIDEO_ATTRIBUTE_SHARPNESS, KAL_TRUE, KAL_TRUE},			
	{USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION, KAL_TRUE, KAL_TRUE},				
	{USBVIDEO_ATTRIBUTE_GAMMA, KAL_TRUE, KAL_TRUE},								
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP, KAL_TRUE, KAL_TRUE},							
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO, KAL_TRUE, KAL_TRUE},									
#else   /* YUV_SENSOR_SUPPORT */	
	{USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY, KAL_TRUE, KAL_TRUE},						
	{USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION, KAL_TRUE, KAL_TRUE},				
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP, KAL_TRUE, KAL_TRUE},							
	{USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO, KAL_TRUE, KAL_TRUE},
#endif
};

/* supported video size list */
const USBVideo_Video_Size_Info VIDEO_SIZE[] =
{
	{USBVIDEO_VIDEO_SIZE_1, 160, 120, 0xC000, 912382, 38012, 500000, 500000, 500000, 0},
	{USBVIDEO_VIDEO_SIZE_2, 320, 240, 0xC000, 912384, 38016, 500000, 500000, 500000, 0},
#if (!defined(MT6225))    
	{USBVIDEO_VIDEO_SIZE_3, 640, 480, 0xC000, 912384, 38016, 500000, 500000, 500000, 0}	
#endif
};

/* supported still image size list */
const USBVideo_Still_Size_Info STILL_SIZE[] =
{
	{USBVIDEO_STILL_SIZE_1, 160, 120, 0xC000},
	{USBVIDEO_STILL_SIZE_2, 320, 240, 0xC000},
	{USBVIDEO_STILL_SIZE_3, 640, 480, 0xC000}
};

/* supported compression type list*/
const USBVideo_Compression_Info STILL_COMPRESSION[] =
{
	//{USBVIDEO_COMPRESSION_1, JPEG_ENCODER_GOOD_QUALITY},
	{USBVIDEO_COMPRESSION_1, JPEG_ENCODER_POOR_QUALITY},
	{USBVIDEO_COMPRESSION_2, JPEG_ENCODER_FAIR_QUALITY}
};
const USBVIDEO_VIDEO_SIZE_TYPE g_default_video_size = USBVIDEO_VIDEO_SIZE_1;
const USBVIDEO_STILL_SIZE_TYPE g_default_still_size = USBVIDEO_STILL_SIZE_1;
const USBVIDEO_COMPRESSION_TYPE g_default_compression = USBVIDEO_COMPRESSION_1;

/*************************************************************************
 * Customer Folder.. 
 *************************************************************************/
/*************************************************************************
* FUNCTION
*	usbvideo_camera_set_attr
*
* DESCRIPTION
*	This function set camera attr
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void usbvideo_camera_set_attr(USBVideo_Attr_Value *attr)
{
	USBVIDEO_ATTRIBUTE_TYPE attr_type = attr->type;
	if(usbvideo_image_sensor_func==NULL)
	{
		usbvideo_camera_init();
		//ASSERT(0);
	}

	if(attr_type<=USBVIDEO_ATTRIBUTE_CT_MAX)
	{
		if( usbvideo_cam_command_CT_map[GET_ATTR_CT_IDX(attr_type)] == USBVIDEO_CAM_ATTR_FIX )
		{
				attr->value = 0;
		}
	}
	else
	{
		if( usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(attr_type)] == USBVIDEO_CAM_ATTR_FIX )
		{
			attr->value = 0;
		}
		else if( usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(attr_type)] == USBVIDEO_CAM_ATTR_SENSOR )
		{
			usbvideo_image_sensor_func->usbvideo_set_attr_value(attr);
		}
		else if( usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(attr_type)] == USBVIDEO_CAM_ATTR_ISP )
		{
			usbvideo_camera_effect_setting_attr(attr);	// ISP/IPP
		}
	}
}	/* usbvideo_camera_set_attr() */

void usbvideo_camera_get_attr(USBVideo_Attr_Value *attr)
{
	USBVIDEO_ATTRIBUTE_TYPE attr_type = attr->type;

	if(usbvideo_image_sensor_func==NULL)
	{
		usbvideo_camera_init();
		//ASSERT(0);
	}

	if(attr_type<=USBVIDEO_ATTRIBUTE_CT_MAX)
	{
	}
	else
	{
		if( usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(attr_type)] == USBVIDEO_CAM_ATTR_SENSOR )
		{
			usbvideo_image_sensor_func->usbvideo_get_attr_value(attr);
		}
		else if( usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(attr_type)] == USBVIDEO_CAM_ATTR_ISP )
		{
			usbvideo_camera_effect_getting_attr(attr);	// ISP/IPP
		}
	}
}

const USBVideo_Attr_Info* get_usbvideo_attr_info(kal_uint8 *p_size)
{
	*p_size = sizeof(ATTR_INFO)/sizeof(USBVideo_Attr_Info);
	return ATTR_INFO;
}

const USBVideo_Video_Size_Info* get_usbvideo_video_size(kal_uint8 *p_size)
{
	*p_size = sizeof(VIDEO_SIZE)/sizeof(USBVideo_Video_Size_Info);
	return VIDEO_SIZE;
}

const USBVIDEO_VIDEO_SIZE_TYPE get_usbvideo_default_video_index(void)
{
	return g_default_video_size;
}

const USBVideo_Still_Size_Info* get_usbvideo_still_size(kal_uint8 *p_size)
{
	*p_size = sizeof(STILL_SIZE)/sizeof(USBVideo_Still_Size_Info);
	return STILL_SIZE;
}

const USBVIDEO_STILL_SIZE_TYPE get_usbvideo_default_still_index(void)
{
	return g_default_still_size;
}

const USBVideo_Compression_Info* get_usbvideo_compression(kal_uint8 *p_size)
{
	*p_size = sizeof(STILL_COMPRESSION)/sizeof(USBVideo_Compression_Info);
	return STILL_COMPRESSION;
}

const USBVIDEO_COMPRESSION_TYPE get_usbvideo_default_compression_index(void)
{
	return g_default_compression;
}

/* function tables for USB driver*/
USBVideo_Camera_Param usbvideo_cam_get_param_ISP =
{
	get_usbvideo_attr_info,
	get_usbvideo_video_size,
	get_usbvideo_default_video_index,
	get_usbvideo_still_size,
	get_usbvideo_default_still_index,
	get_usbvideo_compression,
	get_usbvideo_default_compression_index,
	usbvideo_camera_get_attr
};

const USBVideo_Camera_Param* USBVideo_Get_Camera_Param(void)
{
	return(&usbvideo_cam_get_param_ISP);
}

/*************************************************************************
 * Customer Folder.. (Webcam Function Map)
 *************************************************************************/
/* translate the preivious infomrations into functions */
void usbvideo_cmd_mapping(void)
{
	/* PU Part */
	kal_uint32 i;
	for(i=0;i<(sizeof(ATTR_INFO)/sizeof(USBVideo_Attr_Info));i++)
	{
#if (!defined(YUV_SENSOR_SUPPORT))    	    
		usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(ATTR_INFO[i].type)] = USBVIDEO_CAM_ATTR_ISP;
#else   /* YUV_SENSOR_SUPPORT */
		usbvideo_cam_command_PU_map[GET_ATTR_PU_IDX(ATTR_INFO[i].type)] = USBVIDEO_CAM_ATTR_SENSOR;
#endif	/* YUV_SENSOR_SUPPORT */	
	}
}

void usbvideo_get_attr(USBVideo_Attr_Value *attr)
{
	/* Sensor Attributes Get */	
    usbvideo_camera_effect_getting_attr(attr);    
}

void usbvideo_set_attr(USBVideo_Attr_Value *attr)
{
	USBVIDEO_ATTRIBUTE_TYPE attr_type = attr->type;
	kal_uint32 attr_value = attr->value;
	/* Sensor Attributes Set */	
	// update attr PU current value
    usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(attr_type)] = attr_value;	
	switch(attr_type)
	{
		case USBVIDEO_ATTRIBUTE_POWER_LINE_FREQUENCY:
			if(attr_value==0)	/* 50Hz */
				image_sensor_func->yuv_sensor_setting(CAM_PARAM_BANDING,CAM_BANDING_50HZ);
			else					/* 60Hz or Disable */
				image_sensor_func->yuv_sensor_setting(CAM_PARAM_BANDING,CAM_BANDING_60HZ);
		break;		
        case USBVIDEO_ATTRIBUTE_BACKLIGHT_COMPENSATION:
            image_sensor_func->yuv_sensor_setting(CAM_PARAM_EXPOSURE,attr_value);
        break;
        case USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO:                        
            if(attr_value>0)    /* AUTO */
                image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,CAM_WB_AUTO);
        //break;                /* To update TMP */
        case USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP:            
			if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP_AUTO)] == 0 )
			{
				if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)]>5800)
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,CAM_WB_DAYLIGHT);
				else if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)]>=4800)					
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,CAM_WB_INCANDESCENCE);											
				else if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)]>=3800)											
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,CAM_WB_FLUORESCENT);																
				else if(usbvideo_attr_PU_value_list[GET_ATTR_PU_IDX(USBVIDEO_ATTRIBUTE_WHITE_BALANCE_TMP)]>=2800)					
					image_sensor_func->yuv_sensor_setting(CAM_PARAM_WB,CAM_WB_TUNGSTEN);						
			}
        break;            
    }														

	return;
}

/* function tables for media task */
usbvideo_sensor_func_struct usbvideo_func=
{
	usbvideo_cmd_mapping,
	usbvideo_get_attr,
	usbvideo_set_attr
};

void usbvideo_camera_func_config(void)
{
	usbvideo_image_sensor_func = &usbvideo_func;
}

#endif	// END_OF_WEBCAM_SUPPORT