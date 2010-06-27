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
 *   camera_para.c
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   Camera Parameter for PixArt VGA Sensor (OV9640)
 *
 ****************************************************************************/
#if defined(ANALOG_TV_SUPPORT)

#include "drv_comm.h"
#include "stdio.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "sccb.h"
#include "ae_awb.h"
#include "camera_para.h"

//nvram_camera_para_struct	camera_para;
//nvram_camera_gamma_struct	camera_gamma;
//nvram_camera_defect_struct	camera_defect;
extern kal_uint8	camera_system_operation_mode;
// _Camera_Parameter_Structure_START_
nvram_camera_defect_struct camera_defect_analog_tv={0xFFFFFFFF};
/* STRUCT: nvram_camera_para_struct */
nvram_camera_para_struct camera_para_analog_tv=
{
	/* STRUCT: ISP */
	{
			/* ARRAY: ISP.reg[144] */
		{
			0xA3020074, 0x0FFF0FFF, 0x00000000, 0x00010000, //CAM+000H,0
			0x00000001, 0x00000000, 0x00000040, 0x0000000F, //CAM+0010H,4
			0x00000000, 0x00000000, 0x00000000, 0x00000000,  //CAM+0020H,8
			0x00000100, 0x00800080, 0x00800080, 0x10203040, //CAM+0030H,12
			0x80000000, 0x00410040, 0x0010000C, 0x1020000C,  //CAM+0040H,16
			0x2030000C, 0x00100C18, 0x10200C18, 0x20300C18,  //CAM+0050H,20
			0x00101824, 0x10201824, 0x20301824, 0x082C0721,   //CAM+0060H,24
			0x00000000, 0x0A041910, 0x00000514, 0x061FC810,   //CAM+0070H,28  /*COREH=6,COREH2=1F,CORE_CON=10*/
			0x01080802, 0x02020002, 0x24800F0F, 0x101F8224, //CAM+0080H,32/*HA=1,HB=8,VB=8,VA=2,VC=2,HC=2,ETH3=24,E_TH1_V=10*/		
			0x003F3F3F, 0x841F1F04, 0x361E0E04, 0x00389385, 
			0x00893289, 0x00839336, 0x00202020, 0x00000048, 
//			0x00888888, 0x00000000, 0x00401F30, 0x20200000, //0x00408030	/*UNI@bw_070410A 提高TV显示亮度*/		
//			0x00888888, 0x00000000, 0x00307030, 0x20200000, //0x00408030	/*UNI@bw_070410A 提高TV显示亮度*/	OK	
			0x00888888, 0x00000000, 0x00307090, 0x20200000, //0x00408030	/*UNI@bw_070410A 提高TV显示亮度*/		
			0x00FF91B8, 0x00018080, 0x2C556E80, 0x94AAC1D7,			
			0xE1EBF500, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x245C5C24, 0x245C5C24, 0x125801B8, 0x13200160, 
			0x00325065, 0x7694AEC5, 0xDAE4EDF7, 0x32506576, 
			0x94AEC5DA, 0xE4EDF700, 0x32506576, 0x94AEC5DA, 
			0xE4EDF700, 0x00000000, 0x00000000, 0x00000000, 
			0x32506576, 0x94AEC5DA, 0xE4EDF700, 0x00800080, 
			0x00800080, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x60708090, 0xA0B0C0D0, 0xE0F00000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x404040FF, 0x00204060, 
			0x8090A0B0, 0xC0D0E0F0, 0x20406080, 0x90A0B0C0, 
			0xD0E0F000, 0x20406080, 0x90A0B0C0, 0xD0E0F000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000
		}
	},

	/* STRUCT: PREDGAMMA */
	{
		/* PREDGAMMA.gamma_select */ 0x00, 		/* ARRAY: PREDGAMMA.gamma[9][11] */
		{
			/* ARRAY: PREDGAMMA.gamma[0][11] */
			{
				0x28, 0x4E, 0x67, 0x78, 0x91, 0xA8, 0xC0, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[1][11] */
			{
				0x20, 0x3C, 0x55, 0x69, 0x8D, 0xA8, 0xC0, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[2][11] */
			{
				0x14, 0x28, 0x46, 0x64, 0x91, 0xB4, 0xCE, 0xE0, 
				0xE8, 0xF0, 0xF8
			},

			/* ARRAY: PREDGAMMA.gamma[3][11] */
			{
				0x49, 0x64, 0x78, 0x88, 0xA4, 0xBA, 0xCE, 0xE0, 
				0xE8, 0xF0, 0xF8
			},

			/* ARRAY: PREDGAMMA.gamma[4][11] */
			{
				0x29, 0x59, 0x75, 0x88, 0xA4, 0xBA, 0xCE, 0xE0, 
				0xE8, 0xF0, 0xF8
			},

			/* ARRAY: PREDGAMMA.gamma[5][11] */
			{
				0x14, 0x30, 0x50, 0x69, 0x87, 0xA5, 0xBE, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[6][11] */
			{
				0x17, 0x30, 0x53, 0x74, 0x99, 0xAB, 0xBE, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[7][11] */
			{
				0x30, 0x49, 0x5D, 0x6F, 0x8D, 0xA8, 0xC0, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[8][11] */
			{
				0x10, 0x20, 0x30, 0x40, 0x60, 0x80, 0xA0, 0xC0, 
				0xD0, 0xE0, 0xF0
			}
		}
	},

	/* STRUCT: Comp */
	{
		/* STRUCT: shading_cap */
		{
				0x00000000, 0x00000000, 0x00204060, 0x8090A0B0,
				0xC0D0E0F0, 0x20406080, 0x90A0B0C0, 0xD0E0F000,
				0x20406080, 0x90A0B0C0, 0xD0E0F000
		},
		/* STRUCT: autodefect_pre_low */		
		{
				0x00000000, 0x00002020
		},
		/* STRUCT: autodefect_cap_nor */		
		{
				0x00000000, 0x00002020
		},
		/* STRUCT: autodefect_cap_low */		
		{
				0x00000000, 0x00002020
		},
		/* STRUCT: shading_spare_1 */
		{
				0x00000000, 0x00000000, 0x00204060, 0x8090A0B0,
				0xC0D0E0F0, 0x20406080, 0x90A0B0C0, 0xD0E0F000,
				0x20406080, 0x90A0B0C0, 0xD0E0F000
		},
		/* STRUCT: shading_spare_2 */
		{
				0x00000000, 0x00000000, 0x00204060, 0x8090A0B0,
				0xC0D0E0F0, 0x20406080, 0x90A0B0C0, 0xD0E0F000,
				0x20406080, 0x90A0B0C0, 0xD0E0F000
		}		
	},

	/* STRUCT: AE */
	{
		/* AE.iniShutter */ 0x0118, /* AE.TargetLum */ 0x58, /* AE.StepperEV */ 0x02, 40
	},

	/* STRUCT: AWB */
	{
		/* ARRAY: AWB.LightSource[5][4] */
		{
			/* ARRAY: AWB.LightSource[0][4] */
			{
				0x1D4C, 0x009D, 0x0082, 0x0080
			},

			/* ARRAY: AWB.LightSource[1][4] */
			{
				0x1964, 0x0099, 0x0082, 0x0080
			},

			/* ARRAY: AWB.LightSource[2][4] */
			{
				0x0FA0, 0x0080, 0x0080, 0x00C2
			},

			/* ARRAY: AWB.LightSource[3][4] */
			{
				0x0ED8, 0x0080, 0x0093, 0x00D3
			},

			/* ARRAY: AWB.LightSource[4][4] */
			{
				0x0AF0, 0x0080, 0x00B2, 0x0120
			}
		},
		/* ARRAY: MAX AWB */
		0x009D, 0x00B2, 0x0120
	},

	/* STRUCT: SENSOR */
	{
		/* ARRAY: SENSOR.reg[34] */
		{
			 { 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }         // 32~35
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }                                               // 68~69
			//------------------------Engineer mode---------------------------------
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }, { 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, ISP_DRIVING_8MA }
			//------------------------Engineer mode---------------------------------
		},
		//------------------------CCT mode---------------------------------
			{
		           { 0x00, 0x00 } ,{ 0x69, 0x40 } ,{ 0x69, 0x40 }
		       }
		//------------------------CCT mode---------------------------------	
	}
};

 nvram_camera_gamma_struct camera_gamma_analog_tv=	{
			0x00000000, 0x01010101, 0x02020202, 0x03030303, 		// CAM+1000~100C,(27)0,0~15
			0x04040404, 0x05050505, 0x06060606, 0x07070707, 		// CAM+1010~101C,(27)4,16~31
			0x08080808, 0x09090909, 0x0A0A0A0A, 0x0B0B0B0B,  		// CAM+1020~102C,(27)8,32~47
			0x0C0C0C0C, 0x0D0D0D0D, 0x0E0E0E0E, 0x0F0F0F0F, 		// CAM+1030~103C,(27)12,48~63
			0x10101010, 0x11111111, 0x12121212, 0x13131313, 		// CAM+1040~104C,(27)16,64~79
			0x14141414, 0x15151515, 0x16161616, 0x17171717, 		// CAM+1050~105C,(27)20,80~95
			0x18181818, 0x19191919, 0x1A1A1A1A, 0x1B1B1B1B, 		// CAM+1060~106C,(27)24,96~111
			0x1C1C1C1C, 0x1D1D1D1D, 0x1E1E1E1E, 0x1F1F1F1F, 		// CAM+1070~107C,(27)28,112~127
			0x20202020, 0x21212121, 0x22222222, 0x23232323, 		// CAM+1080~108C,(27)32,128~143
			0x24242424, 0x25252525, 0x26262626, 0x27272727, 		// CAM+1090~109C,(27)36,144~159
			0x28282828, 0x29292929, 0x2A2A2A2A, 0x2B2B2B2B, 		// CAM+10A0~10AC,(27)40,160~175
			0x2C2C2C2C, 0x2D2D2D2D, 0x2E2E2E2E, 0x2F2F2F2F, 		// CAM+10B0~10BC,(27)44,176~191		
			0x30303030, 0x31313131, 0x32323232, 0x33333333, 		// CAM+10C0~10CC,(27)48,192~207
			0x34343434, 0x35353535, 0x36363636, 0x37373737, 		// CAM+10D0~10DC,(27)52,208~223
			0x38383838, 0x39393939, 0x3A3A3A3A, 0x3B3B3B3B, 		// CAM+10E0~10EC,(27)56,224~239		
			0x3C3C3C3C, 0x3D3D3D3D, 0x3E3E3E3E, 0x3F3F3F3F, 		// CAM+10F0~10FC,(27)60,240~255
			0x40404040, 0x41414141, 0x42424242, 0x43434343, 		// CAM+1100~110C,(27)64,256~271
			0x44444444, 0x45454545, 0x46464646, 0x47474747, 		// CAM+1110~111C,(27)68,272~287
			0x48484848, 0x49494949, 0x4A4A4A4A, 0x4B4B4B4B, 		// CAM+1120~112C,(27)72,288~303
			0x4C4C4C4C, 0x4D4D4D4D, 0x4E4E4E4E, 0x4F4F4F4F,		// CAM+1130~113C,(27)76,304~319
			0x50505050, 0x51515151, 0x52525252, 0x53535353, 		// CAM+1140~114C,(27)80,320~335
			0x54545454, 0x55555555, 0x56565656, 0x57575757, 		// CAM+1150~115C,(27)84,336~351
			0x58585858, 0x59595959, 0x5A5A5A5A, 0x5B5B5B5B, 		// CAM+1160~116C,(27)88,352~367
			0x5C5C5C5C, 0x5D5D5D5D, 0x5E5E5E5E, 0x5F5F5F5F, 		// CAM+1170~117C,(27)92,368~383
			0x60606060, 0x61616161, 0x62626262, 0x63636363, 		// CAM+1180~118C,(27)96,384~399
			0x64646464, 0x65656565, 0x66666666, 0x67676767, 		// CAM+1190~119C,(27)100,400~415
			0x68686868, 0x69696969, 0x6A6A6A6A, 0x6B6B6B6B, 		// CAM+11A0~11AC,(27)104,416~431
			0x6C6C6C6C, 0x6D6D6D6D, 0x6E6E6E6E, 0x6F6F6F6F, 		// CAM+11B0~11BC,(27)108,432~447
			0x70707070, 0x71717171, 0x72727272, 0x73737373, 		// CAM+11C0~11CC,(27)112,448~463
			0x74747474, 0x75757575, 0x76767676, 0x77777777, 		// CAM+11D0~11DC,(27)116,464~479
			0x78787878, 0x79797979, 0x7A7A7A7A, 0x7B7B7B7B, 		// CAM+11E0~11EC,(27)120,480~495
			0x7C7C7C7C, 0x7D7D7D7D, 0x7E7E7E7E, 0x7F7F7F7F, 		// CAM+11F0~11FC,(27)124,496~511
			0x80808080, 0x81818181, 0x82828282, 0x83838383, 		// CAM+1200~120C,(27)128,512~527
			0x84848484, 0x85858585, 0x86868686, 0x87878787, 		// CAM+1210~121C,(27)132,528~543
			0x88888888, 0x89898989, 0x8A8A8A8A, 0x8B8B8B8B, 		// CAM+1220~122C,(27)136,544~559
			0x8C8C8C8C, 0x8D8D8D8D, 0x8E8E8E8E, 0x8F8F8F8F, 		// CAM+1230~123C,(27)140,560~575
			0x90909090, 0x91919191, 0x92929292, 0x93939393, 		// CAM+1240~124C,(27)144,576~591
			0x94949494, 0x95959595, 0x96969696, 0x97979797, 		// CAM+1250~125C,(27)148,592~607
			0x98989898, 0x99999999, 0x9A9A9A9A, 0x9B9B9B9B,  		// CAM+1260~126C,(27)152,608~623
			0x9C9C9C9C, 0x9D9D9D9D, 0x9E9E9E9E, 0x9F9F9F9F, 		// CAM+1270~127C,(27)156,624~639
			0xA0A0A0A0, 0xA1A1A1A1, 0xA2A2A2A2, 0xA3A3A3A3, 		// CAM+1280~128C,(27)160,640~655
			0xA4A4A4A4, 0xA5A5A5A5, 0xA6A6A6A6, 0xA7A7A7A7, 		// CAM+1290~129C,(27)164,656~671
			0xA8A8A8A8, 0xA9A9A9A9, 0xAAAAAAAA, 0xABABABAB, 		// CAM+12A0~12AC,(27)168,672~687
			0xACACACAC, 0xADADADAD, 0xAEAEAEAE, 0xAFAFAFAF, 		// CAM+12B0~12BC,(27)172,688~703
			0xB0B0B0B0, 0xB1B1B1B1, 0xB2B2B2B2, 0xB3B3B3B3, 		// CAM+12C0~12CC,(27)176,704~719
			0xB4B4B4B4, 0xB5B5B5B5, 0xB6B6B6B6, 0xB7B7B7B7, 		// CAM+12D0~12DC,(27)180,720~735
			0xB8B8B8B8, 0xB9B9B9B9, 0xBABABABA, 0xBBBBBBBB, 		// CAM+12E0~12EC,(27)184,736~751
			0xBCBCBCBC, 0xBDBDBDBD, 0xBEBEBEBE, 0xBFBFBFBF, 		// CAM+12F0~12FC,(27)188,752~767
			0xC0C0C0C0, 0xC1C1C1C1, 0xC2C2C2C2, 0xC3C3C3C3, 		// CAM+1300~130C,(27)192,768~783
			0xC4C4C4C4, 0xC5C5C5C5, 0xC6C6C6C6, 0xC7C7C7C7, 		// CAM+1310~131C,(27)196,784~799
			0xC8C8C8C8, 0xC9C9C9C9, 0xCACACACA, 0xCBCBCBCB, 		// CAM+1320~132C,(27)200,800~815
			0xCCCCCCCC, 0xCDCDCDCD, 0xCECECECE, 0xCFCFCFCF,		// CAM+1330~133C,(27)204,816~831
			0xD0D0D0D0, 0xD1D1D1D1, 0xD2D2D2D2, 0xD3D3D3D3, 		// CAM+1340~134C,(27)208,832~847
			0xD4D4D4D4, 0xD5D5D5D5, 0xD6D6D6D6, 0xD7D7D7D7, 		// CAM+1350~135C,(27)212,848~863
			0xD8D8D8D8, 0xD9D9D9D9, 0xDADADADA, 0xDBDBDBDB, 		// CAM+1360~136C,(27)216,864~879
			0xDCDCDCDC, 0xDDDDDDDD, 0xDEDEDEDE, 0xDFDFDFDF, 		// CAM+1370~137C,(27)220,880~895
			0xE0E0E0E0, 0xE1E1E1E1, 0xE2E2E2E2, 0xE3E3E3E3, 		// CAM+1380~138C,(27)224,896~911
			0xE4E4E4E4, 0xE5E5E5E5, 0xE6E6E6E6, 0xE7E7E7E7, 		// CAM+1390~139C,(27)228,912~927
			0xE8E8E8E8, 0xE9E9E9E9, 0xEAEAEAEA, 0xEBEBEBEB, 		// CAM+13A0~13AC,(27)232,928~943
			0xECECECEC, 0xEDEDEDED, 0xEEEEEEEE, 0xEFEFEFEF, 		// CAM+13B0~13BC,(27)236,944~959
			0xF0F0F0F0, 0xF1F1F1F1, 0xF2F2F2F2, 0xF3F3F3F3, 		// CAM+13C0~13CC,(27)240,960~975
			0xF4F4F4F4, 0xF5F5F5F5, 0xF6F6F6F6, 0xF7F7F7F7, 		// CAM+13D0~13DC,(27)244,976~991
			0xF8F8F8F8, 0xF9F9F9F9, 0xFAFAFAFA, 0xFBFBFBFB, 		// CAM+13E0~13EC,(27)248,992~1007
			0xFCFCFCFC, 0xFDFDFDFD, 0xFEFEFEFE, 0xFFFFFFFF};       // CAM+13F0~13FC,(27)252,1008~1023
// _Camera_Parameter_Structure_END_

void init_analog_tv_operation_para(camera_operation_para_struct *oper_data)
{
   oper_data->capture_delay_frame=2;			/* Switch Preview to Capture */
   oper_data->preview_delay_frame=8;			/* Wait Preview Stable */
}

void  analog_tv_para_to_isp(void)
{
#if (defined(MT6228)||defined(MT6229))	
	kal_uint32	i;
	/* common register start */
	REG_ISP_RGB_OFFSET_ADJUS=camera_para_analog_tv.ISP.reg[5];//0014h
	for(i=12;i<53;i++)//0030h~00D0h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para_analog_tv.ISP.reg[i];
	for(i=71;i<87;i++)//011Ch~0158h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para_analog_tv.ISP.reg[i];
	for(i=88;i<99;i++)//01A0h~01C8
		*((volatile unsigned int *) (CAMERA_base + i*4 + 64))=camera_para_analog_tv.ISP.reg[i];
	REG_ISP_FLASH_CTRL=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+2];//01D4h
	/* copy ISP_FRAME_COUNT 0x1D8[15:8] but reserve other control bits */	
	REG_ISP_RESET &= ~REG_CAM_RESET_ISP_FRAME_COUNT_MASK;//0x01D8
	REG_ISP_RESET |= camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+3]&REG_CAM_RESET_ISP_FRAME_COUNT_MASK;
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+5];//01E0h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+6];//01E4h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+7];//01E8h
	/* disable copy 0214h~023Ch global variable to reg  */	
	REG_ISP_IMGPROC_HUE0=camera_para_analog_tv.ISP.reg[128];//0240h
	REG_ISP_IMGPROC_HUE1=camera_para_analog_tv.ISP.reg[129];//0244h
	/* common register end */
	
	if(camera_system_operation_mode==0)	
	{
		Set_camera_shading_mode(camera_oper_data.shading_table_mode_set);/* set shading lut mode */
	}
      // Eng. Mode Gamma Table Select
	if(camera_para.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][10]);
	}
#elif (defined(MT6226)||defined(MT6226M)||defined(MT6227))
	kal_uint32	i;
	kal_uint32 temp1, temp2;	

	REG_ISP_RGB_OFFSET_ADJUS=camera_para_analog_tv.ISP.reg[5];//0014h
	for(i=12;i<53;i++)//0030h~00D0h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para_analog_tv.ISP.reg[i];
	for(i=71;i<95;i++)//011Ch~0178h
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para_analog_tv.ISP.reg[i];
	REG_ISP_FLASH_CTRL=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+2];//01D4h	
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL3=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+5];//01E0h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL4=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+6];//01E4h
	REG_ISP_HISTOGRAM_BOUNDARY_CTRL5=camera_para_analog_tv.ISP.reg[AutoDefect_Reg1_ID+7];//01E8h
	/* disable copy 0214h~023Ch global variable to reg  */	
	for(i=139;i<144;i++)//024Ch~025Ch
		*((volatile unsigned int *) (CAMERA_base + i*4 + 32))=camera_para_analog_tv.ISP.reg[i];
	//bypass gamma		
	temp1 = REG_ISP_COLOR_PROCESS_STAGE_CTRL2;//by gamma
	temp2 = REG_ISP_GAMMA_OPERATION3;//output to memory
	DISABLE_GAMMA_FUNCTION_BYPASS;//disable gamma
	DISABLE_1024_GAMMA_TABLE;//disable output to memory
	for(i=0;i<256;i++)//1000h~13FCh gamma table 1024
		INTMEM_GAMMA_1024(i)=camera_gamma_analog_tv.gamma[i];
	//restore gamma enable	
	REG_ISP_COLOR_PROCESS_STAGE_CTRL2 = temp1;//recover gamma
	REG_ISP_GAMMA_OPERATION3 = temp2;//recover output to memory
	if(camera_system_operation_mode==0)	
	{	
		Set_camera_shading_mode(camera_oper_data.shading_table_mode_set);/* set shading lut mode */		
	}
      // Eng. Mode Gamma Table Select
	if(camera_para_analog_tv.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][10]);
	}
#elif (defined(MT6219))
	kal_uint32	i;

	*((volatile unsigned int *) (CAMERA_base + 20))=camera_para_analog_tv.ISP.reg[5];
	for(i=13;i<53;i++)
	{
		*((volatile unsigned int *) (CAMERA_base + i*4))=camera_para_analog_tv.ISP.reg[i];
	}
	if(camera_para_analog_tv.PREDGAMMA.gamma_select!=0)
	{
		SET_GAMMA_B1(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][0]);
		SET_GAMMA_B2(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][1]);
		SET_GAMMA_B3(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][2]);
		SET_GAMMA_B4(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][3]);
		SET_GAMMA_B5(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][4]);
		SET_GAMMA_B6(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][5]);
		SET_GAMMA_B7(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][6]);
		SET_GAMMA_B8(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][7]);
		SET_GAMMA_B9(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][8]);
		SET_GAMMA_B10(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][9]);
		SET_GAMMA_B11(camera_para_analog_tv.PREDGAMMA.gamma[camera_para_analog_tv.PREDGAMMA.gamma_select-1][10]);
	}
#endif	
}

#endif
