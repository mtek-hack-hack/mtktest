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
 *   exif.c
 *
 * Project:
 * --------
 *   MT6226,MT6227,MT6228,MT6229
 *
 * Description:
 * ------------
 *   This file is intends for Exif encoder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <stdio.h>
#include <string.h>

#if (defined(EXIF_SUPPORT) || defined(PICTBRIDGE_SUPPORT))
#include "exif.h"
#include "exif_table.h"	

#include "Drm_gprot.h"
#include "kal_release.h"
#include "FSAL.h"
#include "rtc_sw.h"

STFSAL exif_FSAL;
kal_uint32 exif_FileSize;

#if(defined(EXIF_SUPPORT))

extern void RTC_GetTime(t_rtc *rtctime);
extern kal_char* release_verno(void);
extern void exif_update_MTK_para_struct(exif_MTK_para_struct *exif_MTK_para);

/* Global variables  */
kal_uint32	exif_IFD0_Entry_Switch= 0x0080;		/* Switch off all cam &cus entries as default */
kal_uint32	exif_ExifIFD_Entry_Switch= 0x0000; /* Switch off all cam & cus entries as default */
kal_uint32	exif_ExIFD_Entry_Switch=0x0000; 

kal_bool cam_para_get=KAL_FALSE;
kal_bool cus_para_get=KAL_FALSE;

kal_bool exif_AscOrder;

kal_uint8 exif_next_ExIFD_entry;

exif_cam_para_struct exif_cam_para;
exif_MTK_para_struct exif_MTK_para;

exif_LONG exif_ExifIFD_Offset;

kal_uint16	IFD0_Entry_Size;
kal_uint16	IFD0_Value_Size;
kal_uint16	ExifIFD_Entry_Size;
kal_uint16	ExifIFD_Value_Size;
kal_uint16	IFD_TiffHeader_Offset;

/* Number of entries of each IFD */
kal_uint16 exif_IFD0_count;
kal_uint16 exif_ExifIFD_count;

/* Buffer pointer*/
kal_uint8*  exif_Buffer;

/* Required Buffer Size for EXIF encoding*/
kal_uint16	exif_BufferSize;

exif_extend_entry_struct* ExIFD;
kal_uint8 ExIFD_Number_of_Entry=0;

/* tables */
exif_entry_struct IFD0[IFD0_Number_of_Entry]=
{
	//{exif_tag_Make,			EXIF_ASCII,		0,	&exif_cus_para.Make},
	//{exif_tag_Model,			EXIF_ASCII,		0,	&exif_cus_para.Model},
	{exif_tag_Orientation,		EXIF_SHORT,		1,	&exif_cam_para.Orientation},
	{exif_tag_XResolution,		EXIF_RATIONAL,	1,	&exif_cam_para.XResolution},
	{exif_tag_YResolution,		EXIF_RATIONAL,	1,	&exif_cam_para.YResolution},
	{exif_tag_ResolutionUnit,	EXIF_SHORT,		1,	&exif_cam_para.ResolutionUnit},

	{exif_tag_Software,			EXIF_ASCII,		0,	&exif_cam_para.Software},
	{exif_tag_DateTime,			EXIF_ASCII,		0,	&exif_cam_para.DateTime},
	{exif_tag_YCbCrPositioning,	EXIF_SHORT,		1,	&exif_cam_para.YCbCrPositioning},
	{exif_tag_ExifIFD,			EXIF_LONG,		1,	&exif_ExifIFD_Offset}
};

exif_entry_struct ExifIFD[ExifIFD_Number_of_Entry]=
{
	{exif_tag_ExposureTime,		EXIF_RATIONAL,	1,	&exif_cam_para.ExposureTime},
	{exif_tag_FNumber,			EXIF_RATIONAL,	1,	&exif_cam_para.FNumber},
	{exif_tag_ExposureProgram,	EXIF_SHORT,		1,	&exif_cam_para.ExposureProgram},
	{exif_tag_ISOSpeedRatings,	EXIF_SHORT,		1,	&exif_cam_para.ISOSpeedRatings},
	{exif_tag_ExifVersion,		EXIF_UNDEFINED,	4,	&exif_cam_para.ExifVersion},

	{exif_tag_DateTimeOriginal,	EXIF_ASCII,		0,	&exif_cam_para.DateTimeOriginal},
	{exif_tag_DateTimeDigitized,EXIF_ASCII,		0,	&exif_cam_para.DateTimeDigitized},
	{exif_tag_ComponentsConfig,	EXIF_UNDEFINED,	4,	&exif_cam_para.ComponentsConfig},
	{exif_tag_ExposureBiasValue,EXIF_SRATIONAL,	1,	&exif_cam_para.ExposureBiasValue},
	{exif_tag_MeteringMode,		EXIF_SHORT,		1,	&exif_cam_para.MeteringMode},

	{exif_tag_LightSource,		EXIF_SHORT,		1,	&exif_cam_para.LightSource},
	{exif_tag_Flash,			EXIF_SHORT,		1,	&exif_cam_para.Flash},
	{exif_tag_MakerNote,		EXIF_UNDEFINED,	sizeof(exif_MTK_para_struct),&exif_MTK_para},
	//{exif_tag_UserComment,	EXIF_UNDEFINED,	exif_Count_UserComment,&exif_cus_para.UserComment},
	{exif_tag_FlashpixVersion,	EXIF_UNDEFINED,	4,	&exif_cam_para.FlashpixVersion},

	{exif_tag_ColorSpace,		EXIF_SHORT,		1,	&exif_cam_para.ColorSpace},
	{exif_tag_PixelXDimension,	EXIF_LONG,		1,	&exif_cam_para.PixelXDimension},
	{exif_tag_PixelYDimension,	EXIF_LONG,		1,	&exif_cam_para.PixelYDimension},
	{exif_tag_ExposureMode,		EXIF_SHORT,		1,	&exif_cam_para.ExposureMode},
	{exif_tag_DigitalZoomRatio,	EXIF_RATIONAL,	1,	&exif_cam_para.DigitalZoomRatio},

	{exif_tag_SceneCaptureType,	EXIF_SHORT,		1,	&exif_cam_para.SceneCaptureType}
};


/* Exif Headers */
kal_uint8	exif_Header[exif_header_size]={0xff,0xe1,0x00,0x00,'E','x','i','f','\0',0};
const kal_uint8	exif_tiffHeader[tiff_header_size]={0x49,0x49,0x2a,0x00,0x08,0x00,0x00,0x00};

kal_uint16 exif_Accumulate_ASCII(char* str,kal_uint16* IFD_Value_Size);

kal_bool exif_Acc_IFD_Size(exif_entry_struct* Exif_entry,kal_uint16* IFD_count,kal_uint16* IFD_Entry_Size,kal_uint16* IFD_Value_Size);
void exif_Fillin_tag(exif_entry_struct* Exif_entry,kal_uint16* IFD_entry_offset,kal_uint16* IFD_value_offset);
void exif_Fillin_32(kal_uint8* Buffer, kal_uint16* Offset, kal_uint32 Value);
void exif_Fillin_16(kal_uint8* Buffer, kal_uint16* Offset, kal_uint16 Value);
void exif_Fillin_ASCII(kal_uint8* Buffer, kal_uint16* Offset, kal_char* Value,kal_uint32 count);

void exif_switch_cam_entry(kal_uint8 action);
void exif_switch_cus_entry(kal_uint8 action);
kal_bool exif_is_switched_on(kal_uint8 IFD,kal_uint8 Entry);
void exif_check_ExIFD_data(void);

kal_uint16 exif_Calculate_Buffer_Size(kal_uint32 BufferOffset);

kal_uint8 exif_get_next_extended_tag(kal_uint8 IFD,kal_uint16 MinTag);

exif_ASCII exif_sys_time[20]={'y','y','y','y','.','m','m','.','d','d',' ','h','h',':','m','m',':','s','s','\0'};

//exif_ASCII* exif_sys_time="yyyy:mm:dd hh:mm:ss";

void exif_uint8_to_char(kal_uint8 val,kal_char* h, kal_char* l)
{
 if(val>=100)
 {
  *h='9';	
  *l='9';	
  return;
 }
 *h=val/10;
 *l=val%10;
 return;	
}

void exif_get_sys_time()
{
 t_rtc exif_time;
 RTC_GetTime(&exif_time);	
 
 exif_sys_time[0]='2';
 if(exif_time.rtc_year>=100)
 {
  exif_sys_time[1]='1';
  exif_time.rtc_year-=100;
 }
 else
  exif_sys_time[1]='0';
  
 exif_sys_time[2]=(exif_time.rtc_year/10)+48;
 exif_sys_time[3]=(exif_time.rtc_year%10)+48;
 
 exif_sys_time[5]=(exif_time.rtc_mon/10)+48;
 exif_sys_time[6]=(exif_time.rtc_mon%10)+48;
 
 exif_sys_time[8]=(exif_time.rtc_day/10)+48;
 exif_sys_time[9]=(exif_time.rtc_day%10)+48;
 
 exif_sys_time[11]=(exif_time.rtc_hour/10)+48;
 exif_sys_time[12]=(exif_time.rtc_hour%10)+48;
 
 exif_sys_time[14]=(exif_time.rtc_min/10)+48;
 exif_sys_time[15]=(exif_time.rtc_min%10)+48;
 
 exif_sys_time[17]=(exif_time.rtc_sec/10)+48;
 exif_sys_time[18]=(exif_time.rtc_sec%10)+48;
}			

/* Set preDefined values to some of the IFD entries */
exif_cam_para_struct* exif_get_cam_para_struct(void)
{
	exif_get_sys_time();
	
	exif_cam_para.Orientation=1;
	exif_cam_para.XResolution[0]=72;
	exif_cam_para.XResolution[1]=1;
	exif_cam_para.YResolution[0]=72;
	exif_cam_para.YResolution[1]=1;
	exif_cam_para.ResolutionUnit=2;	/* inches */

	exif_cam_para.Software=(kal_char*)release_verno();
	exif_cam_para.DateTime=exif_sys_time; //"yyyy:mm:dd hh:mm:ss";
	
	exif_cam_para.YCbCrPositioning=2;/* co-siteded */

	/* Exif IFD default values */

	exif_cam_para.ExposureTime[0]=0;
	exif_cam_para.ExposureTime[1]=0;

	exif_cam_para.FNumber[0]=0;
	exif_cam_para.FNumber[1]=0;

	exif_cam_para.ExposureProgram=0;	/* Unknown*/

	exif_cam_para.ISOSpeedRatings=0;

	exif_cam_para.ExifVersion[3]='0';/* Supported Exif Version: 2.2*/
	exif_cam_para.ExifVersion[2]='2';
	exif_cam_para.ExifVersion[1]='2';
	exif_cam_para.ExifVersion[0]='0';

	exif_cam_para.DateTimeOriginal=0;
	exif_cam_para.DateTimeDigitized=0;
	
	exif_cam_para.ComponentsConfig[0]=1;	/* YCbCr */
	exif_cam_para.ComponentsConfig[1]=2;
	exif_cam_para.ComponentsConfig[2]=3;
	exif_cam_para.ComponentsConfig[3]=0;
	
	exif_cam_para.ExposureBiasValue[0]=0;
	exif_cam_para.ExposureBiasValue[1]=1;

	exif_cam_para.MeteringMode=0;
	exif_cam_para.LightSource=0;
	exif_cam_para.Flash=0;

	exif_cam_para.FlashpixVersion[3]='0';
	exif_cam_para.FlashpixVersion[2]='0';
	exif_cam_para.FlashpixVersion[1]='1';
	exif_cam_para.FlashpixVersion[0]='0';

	exif_cam_para.ColorSpace=1;	/* sRGB */

	exif_cam_para.PixelXDimension=0;
	exif_cam_para.PixelYDimension=0;

	exif_cam_para.ExposureMode=0; /* auto exposure */

	exif_cam_para.DigitalZoomRatio[0]=1;
	exif_cam_para.DigitalZoomRatio[1]=1;

	exif_cam_para.SceneCaptureType=0; /* standard */

	cam_para_get=KAL_TRUE;
	exif_switch_cam_entry(EXIF_SWITCH_ON);

	/* Temporly switch FNumber off*/
	exif_switch_IFD_entry(EXIF_EXIFIFD,EXIF_FNUMBER,EXIF_SWITCH_OFF);

	return &exif_cam_para;
}

exif_MTK_para_struct* exif_get_MTK_para_struct(void)
{
	strcpy(exif_MTK_para.title,"MediaTek");
	exif_MTK_para.version[0]=exif_MTK_specific_ver_main;
	exif_MTK_para.version[1]=exif_MTK_specific_ver_fraction;

	exif_update_MTK_para_struct(&exif_MTK_para);   

	cam_para_get=KAL_TRUE;
	exif_switch_IFD_entry(EXIF_EXIFIFD,EXIF_MAKER_NOTE,EXIF_SWITCH_ON);

	return &exif_MTK_para;
}

kal_uint16 exif_Fillin_Buffer(kal_uint8* Buffer,kal_uint32 BufferOffset)
{
	kal_uint16 BufferSize;

	ExIFD=exif_get_custom_specific_IFD(&ExIFD_Number_of_Entry);

	exif_check_ExIFD_data();

	BufferSize=exif_Calculate_Buffer_Size(BufferOffset);
	
	if(BufferSize==0) 
	 return BufferSize;
	else if(BufferSize>EXIF_MAXIMUM_SIZE)
	 ASSERT(0);

	exif_Fillin_Header(Buffer,BufferOffset);

	return BufferSize;

}

/* Used for MT6227*/
kal_uint16 exif_get_custom_IFD_and_buffer_size(kal_uint32 BufferOffset)
{
 kal_uint16 BufferSize;
 ExIFD=exif_get_custom_specific_IFD(&ExIFD_Number_of_Entry);
 exif_check_ExIFD_data();
 BufferSize=exif_Calculate_Buffer_Size(BufferOffset);

 if(BufferSize>EXIF_MAXIMUM_SIZE)
	 ASSERT(0);
 return BufferSize;
}

/* Accumulate the Exif Buffer Size */
kal_uint16 exif_Calculate_Buffer_Size(kal_uint32 BufferOffset)
{
 kal_uint8	i;
 kal_uint32	mask=1;

 if(!cam_para_get && !cus_para_get)
  return 0;
	//return exif_Overlap_Offset;
	

 IFD0_Entry_Size=0;
 IFD0_Value_Size=0;
 ExifIFD_Entry_Size=0;
 ExifIFD_Value_Size=0;

 exif_IFD0_count=0;
 exif_ExifIFD_count=0;
 //--Acc ExifIFD--
 if(exif_is_switched_on(EXIF_IFD0,EXIF_EXIF_IFD))
 {
    mask=1;
	for(i=0;i<ExifIFD_Number_of_Entry;i++)
	{
	 if((exif_ExifIFD_Entry_Switch & mask)==0)// This entry is switched off
	 {
		mask<<=1;
		continue;
	 }

	exif_Acc_IFD_Size(&ExifIFD[i],&exif_ExifIFD_count,&ExifIFD_Entry_Size,&ExifIFD_Value_Size);
	mask<<=1;

	}
 }
 //--Acc ExIFD--
 for(i=0;i<ExIFD_Number_of_Entry;i++)
 {
	if(ExIFD[i].exif_IFD_type==EXIF_IFD0)
	 exif_Acc_IFD_Size(&ExIFD[i].entry,&exif_IFD0_count,&IFD0_Entry_Size,&IFD0_Value_Size);
	else if(ExIFD[i].exif_IFD_type==EXIF_EXIFIFD && exif_is_switched_on(EXIF_IFD0,EXIF_EXIF_IFD))
	 exif_Acc_IFD_Size(&ExIFD[i].entry,&exif_ExifIFD_count,&ExifIFD_Entry_Size,&ExifIFD_Value_Size);
 }

 //--Acc IFD0--
 mask=1;
 for(i=0;i<EXIF_EXIF_IFD;i++)
 {
  	if((exif_IFD0_Entry_Switch & mask)==0)// This entry is switched off
	 {
		mask<<=1;
		continue;
	 }
	exif_Acc_IFD_Size(&IFD0[i],&exif_IFD0_count,&IFD0_Entry_Size,&IFD0_Value_Size);
	mask<<=1;
 }
 //--Acc ExifIFD entry of IFD0--
 if(exif_ExifIFD_count>0 && exif_is_switched_on(EXIF_IFD0,EXIF_EXIF_IFD))	
  exif_Acc_IFD_Size(&IFD0[EXIF_EXIF_IFD],&exif_IFD0_count,&IFD0_Entry_Size,&IFD0_Value_Size);

if(exif_IFD0_count==0 && exif_ExifIFD_count==0)
  return 0;
  //return exif_Overlap_Offset;

if(exif_IFD0_count>0)
 IFD0_Entry_Size+=(2+4);

if(exif_ExifIFD_count>0) 
 ExifIFD_Entry_Size+=(2+4);

/*-- Get TiffHeaderOffset --*/
 IFD_TiffHeader_Offset=BufferOffset+exif_header_size;

 exif_BufferSize=exif_header_size+tiff_header_size+IFD0_Entry_Size+IFD0_Value_Size+ExifIFD_Entry_Size+ExifIFD_Value_Size;

 /*//-- 4 bytes align--
 if(exif_BufferSize & 0x03 !=0)
	 exif_BufferSize=((exif_BufferSize+4)>>2)<<2;
*/

 /*--Fill IFD0 ExifIFD entry. 12: jpeg SOI marker and exif header, 8: Tiff Header --*/
 exif_ExifIFD_Offset=BufferOffset+exif_header_size+tiff_header_size+IFD0_Entry_Size+IFD0_Value_Size-IFD_TiffHeader_Offset;
 
 return exif_BufferSize;

}

kal_bool exif_Acc_IFD_Size(exif_entry_struct* Exif_entry,kal_uint16* IFD_entry_count,kal_uint16* IFD_Entry_Size,kal_uint16* IFD_Value_Size)
{
	if(Exif_entry->type!=EXIF_ASCII && Exif_entry->count==0)
		ASSERT(0);

	 switch(Exif_entry->type)
	 {
		case EXIF_ASCII:
			 if(*((char**)Exif_entry->value)!=0)
				{
					(*IFD_Entry_Size)+=12;
					Exif_entry->count=exif_Accumulate_ASCII(*((char**)Exif_entry->value),IFD_Value_Size);
					(*IFD_entry_count)++;
				} 
			break;
		case EXIF_SRATIONAL:
		case EXIF_RATIONAL:
			(*IFD_Entry_Size)+=12;
			//(*IFD_Value_Size)+=8;
			(*IFD_Value_Size)+=(8*Exif_entry->count);
			(*IFD_entry_count)++;
			break;
		case EXIF_SHORT:
			(*IFD_Entry_Size)+=12;
			if(Exif_entry->count>2)
			 (*IFD_Value_Size)+=(2*Exif_entry->count);
			(*IFD_entry_count)++;
			break;
		case EXIF_LONG:
			(*IFD_Entry_Size)+=12;
			if(Exif_entry->count>1)
			 (*IFD_Value_Size)+=(4*Exif_entry->count);
			(*IFD_entry_count)++;
			break;
		case EXIF_UNDEFINED:
			(*IFD_Entry_Size)+=12;
			if(Exif_entry->count>4)
			{
				(*IFD_Value_Size)+=Exif_entry->count;
				if(Exif_entry->count & 1 !=0)/*Force to half-word aligned*/
					(*IFD_Value_Size)++;
			}
			(*IFD_entry_count)++;
			break;		
		default:
			ASSERT(0);
			//return KAL_FALSE;
	 }
	return KAL_TRUE;
}

kal_uint16 exif_Accumulate_ASCII(char* str,kal_uint16* IFD_Value_Size)
{
	kal_uint16 EntryLength;
	 
	for(EntryLength=0;str[EntryLength]!='\0';EntryLength++);
	
	if(++EntryLength>4)
	(*IFD_Value_Size)+=EntryLength;

	if(EntryLength & 1 !=0)/*Force to half-word aligned*/
	 (*IFD_Value_Size)++;

	return EntryLength; 
}

kal_uint32 eixf_burst_mode_fill_header(kal_uint8* Buffer)
{
 kal_uint8* NewBuffer;

 if(Buffer[0]==0xff && Buffer[1]==0xd8)
	return 0;

 NewBuffer=Buffer-exif_BufferSize-2;

 IFD_TiffHeader_Offset=2+exif_header_size;
 exif_ExIFD_Entry_Switch=0xffffffff;

 cam_para_get=KAL_TRUE;	 //Re-Eanble
 exif_Fillin_Header(NewBuffer,2);
 
 NewBuffer[0]=0xff;
 NewBuffer[1]=0xd8;
 cam_para_get=KAL_FALSE; //Disable

 return exif_BufferSize+2;
}

void exif_set_extra_included_bytes(kal_uint32 padding_length)
{
   exif_BufferSize+=padding_length;
 }

kal_bool exif_Fillin_Header(kal_uint8* Buffer,kal_uint32 BufferOffset)
{
	kal_uint8	i;
	kal_uint32	mask;
	kal_uint16	j;
	kal_uint16	IFD_entry_offset;
	kal_uint16	IFD_value_offset;
	
	exif_Buffer=Buffer;
	exif_next_ExIFD_entry=0;

	if(!cam_para_get && !cus_para_get)
		return KAL_TRUE;

	if(exif_IFD0_count==0 && exif_ExifIFD_count==0)
		return KAL_TRUE;

	 /*--Fill in the length field of app0 marker--*/
   exif_Header[2]=(exif_BufferSize-2)>>8 & 0xff;
   exif_Header[3]=(exif_BufferSize-2) & 0xff;

	//-- copy JPEG,EXIF header --
	IFD_entry_offset=BufferOffset;
	for(j=0;j<exif_header_size;j++)
	 Buffer[IFD_entry_offset++]=exif_Header[j];

	//-- copy TiffHeader --
	for(j=0;j<tiff_header_size;j++)
	 Buffer[IFD_entry_offset++]=exif_tiffHeader[j];

	/************* Fillin IFD0 entries *************/
	IFD_value_offset=IFD_entry_offset+IFD0_Entry_Size;

	mask=1;

	exif_Fillin_16(Buffer, &IFD_entry_offset, exif_IFD0_count);//Fill in number of IFD0 entries


	for(i=0;i<EXIF_EXIF_IFD;i++)
	{
	 if((exif_IFD0_Entry_Switch & mask)==0)// This entry is switched off
	 {
		mask<<=1;
		continue;
	 }

	 if(IFD0[i].type==EXIF_ASCII && *((kal_char**)IFD0[i].value)==0)
	 {
		mask<<=1;
		continue;
	 }
	 //-- check Extended tags --
	 while((j=exif_get_next_extended_tag(EXIF_IFD0,IFD0[i].tag))!=255)
	 {
	  exif_Fillin_tag(&ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
	 }
	  exif_Fillin_tag(&IFD0[i],&IFD_entry_offset,&IFD_value_offset);
	 
	 mask<<=1;
	}

	 //--Fillin ExifIFD entry of IFD0--
	if(exif_ExifIFD_count>0 && exif_is_switched_on(EXIF_IFD0,EXIF_EXIF_IFD))
	{
	//-- check IFD0 Extended tags (before IFD0.ExifIFD tag)--
	while((j=exif_get_next_extended_tag(EXIF_IFD0,IFD0[EXIF_EXIF_IFD].tag))!=255)
	{
	 exif_Fillin_tag(&ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
	}	
	 exif_Fillin_tag(&IFD0[EXIF_EXIF_IFD],&IFD_entry_offset,&IFD_value_offset);
	}
	
	//-- check Rest IFD0 Extended tags --
	while((j=exif_get_next_extended_tag(EXIF_IFD0,exif_tag_MAXIMUM))!=255)
	{
	 exif_Fillin_tag(&ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
	}

	exif_Fillin_32(Buffer, &IFD_entry_offset,0);//no next IFD(IFD1)
	
	/************* Fill in exif_IFD entries *************/
	if((exif_IFD0_Entry_Switch & (1<<EXIF_EXIF_IFD))!=0)
	{
		IFD_entry_offset=IFD_value_offset;
		IFD_value_offset=IFD_entry_offset+ExifIFD_Entry_Size;
		  mask=1;

		exif_Fillin_16(Buffer, &IFD_entry_offset,exif_ExifIFD_count);//Fill in number of IFD0 entries

		for(i=0;i<ExifIFD_Number_of_Entry;i++)
		{
			if((exif_ExifIFD_Entry_Switch & mask)==0)// This entry is switched off
			{
			mask<<=1;
			continue;
			}

			if(ExifIFD[i].type==EXIF_ASCII && *((kal_char**)ExifIFD[i].value)==0)
			{
			mask<<=1;
			continue;
			}

			while((j=exif_get_next_extended_tag(EXIF_EXIFIFD,ExifIFD[i].tag))!=255)
			{
			 exif_Fillin_tag(&ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
			}

			exif_Fillin_tag(&ExifIFD[i],&IFD_entry_offset,&IFD_value_offset);
	 
			mask<<=1;
		}
		//-- check Rest ExifIFD Extended tags --
		while((j=exif_get_next_extended_tag(EXIF_EXIFIFD,exif_tag_MAXIMUM))!=255)
		{
		 exif_Fillin_tag(&ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
		}
	 
		exif_Fillin_32(Buffer, &IFD_entry_offset,0);//no next IFD(IFD1)
	}

	cam_para_get=KAL_FALSE;
	//cus_para_get=KAL_FALSE;
	//exif_switch_cam_entry(EXIF_SWITCH_OFF);
	//exif_switch_IFD_entry(EXIF_EXIFIFD,EXIF_MAKER_NOTE,EXIF_SWITCH_OFF);
	return	KAL_TRUE; 
}

void exif_Fillin_tag(exif_entry_struct* Exif_entry,kal_uint16* IFD_entry_offset,kal_uint16* IFD_value_offset)
{
	 kal_uint32	ValueOffset;
	 kal_uint16	j;

 	 ASSERT(Exif_entry->count>0);

	 exif_Fillin_16(exif_Buffer, IFD_entry_offset, Exif_entry->tag);

	 exif_Fillin_16(exif_Buffer, IFD_entry_offset, Exif_entry->type);

	 exif_Fillin_32(exif_Buffer, IFD_entry_offset, Exif_entry->count);

	switch(Exif_entry->type)
	 {
		case EXIF_UNDEFINED:
			//printf("FillinTag EXIF_UNDEFINED\n");
			if(Exif_entry->count>4)
				{
				 ValueOffset=*IFD_value_offset-IFD_TiffHeader_Offset;
				 exif_Fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
				 exif_Fillin_ASCII(exif_Buffer,IFD_value_offset,(exif_UNDEFINED*)Exif_entry->value,Exif_entry->count);
				}
				else
				{
				 for(j=0;j<Exif_entry->count;j++)
				 {
					exif_Buffer[(*IFD_entry_offset)++]=((exif_UNDEFINED*)Exif_entry->value)[j];
				 }
				 for(j=Exif_entry->count;j<4;j++)
					exif_Buffer[(*IFD_entry_offset)++]=0x00;
				}
			break;
		
		case EXIF_ASCII:
			//printf("FillinTag EXIF_ASCII\n");
			if(Exif_entry->count>4)
				{
				 ValueOffset=*IFD_value_offset-IFD_TiffHeader_Offset;
				 exif_Fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
				 exif_Fillin_ASCII(exif_Buffer,IFD_value_offset,*((kal_char**)Exif_entry->value),Exif_entry->count);
				}
				else
				{
				 for(j=0;j<Exif_entry->count;j++)
				 {
					exif_Buffer[(*IFD_entry_offset)++]=(*((kal_char**)Exif_entry->value))[j];
				 }
				for(j=Exif_entry->count;j<4;j++)
					exif_Buffer[(*IFD_entry_offset)++]=0x00;
				}
			break;		
		case EXIF_LONG:
			//printf("FillinTag EXIF_LONG\n");
			if(Exif_entry->count==1)
			exif_Fillin_32(exif_Buffer, IFD_entry_offset,((exif_LONG*)Exif_entry->value)[0]);
			else
			{
			 ValueOffset=*IFD_value_offset-IFD_TiffHeader_Offset;
			 exif_Fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
			 for(j=0;j<Exif_entry->count;j++)
			  exif_Fillin_32(exif_Buffer, IFD_value_offset,((exif_LONG*)Exif_entry->value)[j]);
			}
			break;		
		case EXIF_SRATIONAL:
		case EXIF_RATIONAL:
			//printf("FillinTag EXIF_RATIONAL\n");
			ValueOffset=*IFD_value_offset-IFD_TiffHeader_Offset;
			exif_Fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);

			for(j=0;j<Exif_entry->count;j++)
			{
			 exif_Fillin_32(exif_Buffer, IFD_value_offset, ((exif_RATIONAL*)Exif_entry->value)[j][0]);
			 exif_Fillin_32(exif_Buffer, IFD_value_offset, ((exif_RATIONAL*)Exif_entry->value)[j][1]);
			}
			break;
		case EXIF_SHORT:
			//printf("FillinTag EXIF_SHORT, count:%d\n",Exif_entry->count);
			if(Exif_entry->count==1)
			{
			 exif_Fillin_16(exif_Buffer, IFD_entry_offset,((exif_SHORT*)Exif_entry->value)[0]);
			 exif_Fillin_16(exif_Buffer, IFD_entry_offset,0);
			}
			else if(Exif_entry->count==2)
			{
			 exif_Fillin_16(exif_Buffer, IFD_entry_offset,((exif_SHORT*)Exif_entry->value)[0]);
			 exif_Fillin_16(exif_Buffer, IFD_entry_offset,((exif_SHORT*)Exif_entry->value)[1]);
			}
			else if(Exif_entry->count>2)
			{
			 ValueOffset=*IFD_value_offset-IFD_TiffHeader_Offset;
			 exif_Fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
			 for(j=0;j<Exif_entry->count;j++)
			 exif_Fillin_16(exif_Buffer, IFD_value_offset,((exif_SHORT*)Exif_entry->value)[j]);
			}
			break;
		default :
			ASSERT(0);
	 }
}
void exif_check_ExIFD_data(void)
{
 kal_uint8 i,j;
 kal_bool	IFD_switched=KAL_FALSE;

 if(ExIFD_Number_of_Entry==0) return;

 if(ExIFD_Number_of_Entry>EXIF_MAXIMUM_NUMBER_OF_EXIFD_ENTRIES)
	ASSERT(0);

 for(i=0;i<ExIFD_Number_of_Entry;i++)
 {
  ASSERT(/*ExIFD[i].exif_IFD_type>=EXIF_IFD0 && */ExIFD[i].exif_IFD_type<=EXIF_EXIFIFD);
  
  //--Checking double definition--
  for(j=0;j<IFD0_Number_of_Entry;j++)
  {
   ASSERT(ExIFD[i].entry.tag!=IFD0[j].tag);
   if(IFD0[j].tag>ExIFD[i].entry.tag) break;
  }
  for(j=0;j<ExifIFD_Number_of_Entry;j++)
  {
   ASSERT(ExIFD[i].entry.tag!=ExifIFD[j].tag);
   if(ExifIFD[j].tag>ExIFD[i].entry.tag) break;
  }
 }

 //--Checking ordering--
 exif_AscOrder=KAL_TRUE;


 for(i=1;i<ExIFD_Number_of_Entry;i++)
 {
  if(!IFD_switched && ExIFD[i].exif_IFD_type != ExIFD[i-1].exif_IFD_type)
  {
   IFD_switched=KAL_TRUE;
   continue;
  }
  if(IFD_switched && ExIFD[i].exif_IFD_type != EXIF_EXIFIFD)
  {
   exif_AscOrder=KAL_FALSE;
   break;
  }

  if(ExIFD[i].entry.tag<ExIFD[i-1].entry.tag)
  {
	exif_AscOrder=KAL_FALSE;
	break;
  }
 }

	exif_ExIFD_Entry_Switch=0xffffffff;

}

kal_uint8 exif_get_next_extended_tag(kal_uint8 IFD,kal_uint16 MinTag)
{
	kal_uint8 j,index=255;

	if(!exif_AscOrder)
	{
	 for(j=0;j<ExIFD_Number_of_Entry;j++)
	 {
		if( exif_is_switched_on(EXIF_EXIFD,j) && 
			ExIFD[j].exif_IFD_type==IFD && 
			ExIFD[j].entry.tag<MinTag)
		{
			index=j;
			MinTag=ExIFD[j].entry.tag;
		}
	 }
	}
	else
	{
	 if(exif_next_ExIFD_entry<ExIFD_Number_of_Entry && 
	 	exif_is_switched_on(EXIF_EXIFD,exif_next_ExIFD_entry) &&
		ExIFD[exif_next_ExIFD_entry].exif_IFD_type==IFD &&
		ExIFD[exif_next_ExIFD_entry].entry.tag<MinTag)
	 {

		 //printf("ExIFD:%x MinTag:%x\n",ExIFD[exif_next_ExIFD_entry].entry.tag,MinTag);
		index=exif_next_ExIFD_entry++;
	 }

	}

	/* switch off the selected tag */
	if(index<EXIF_MAXIMUM_NUMBER_OF_EXIFD_ENTRIES)
	{

	 exif_switch_IFD_entry(EXIF_EXIFD,index,EXIF_SWITCH_OFF);

	}
	else if(index>=EXIF_MAXIMUM_NUMBER_OF_EXIFD_ENTRIES && index !=255)
	ASSERT(0);


	//printf("count:%d index:%d\n",count,index);
	return index;
}

void exif_Fillin_16(kal_uint8* Buffer, kal_uint16* Offset, kal_uint16 Value)
{
	Buffer[(*Offset)++]=Value & 0xff;
	Buffer[(*Offset)++]=Value>>8 & 0xff;
}

void exif_Fillin_32(kal_uint8* Buffer, kal_uint16* Offset, kal_uint32 Value)
{
	Buffer[(*Offset)++]=Value & 0xff;
	Buffer[(*Offset)++]=Value>>8 & 0xff;
	Buffer[(*Offset)++]=Value>>16 & 0xff;
	Buffer[(*Offset)++]=Value>>24 & 0xff;
}

void exif_Fillin_ASCII(kal_uint8* Buffer, kal_uint16* Offset, kal_char* Value,kal_uint32 count)
{
	kal_uint32 j;

	ASSERT(count>0);

	for(j=0;j<count;j++)
		Buffer[(*Offset)++]=Value[j];

	if(count & 1 !=0)/*Force to half-word aligned*/
	 Buffer[(*Offset)++]=0x00;
}

void exif_switch_cam_entry(kal_uint8 action)
{
 kal_uint8 i;

 for(i=EXIF_ORIENTATION;i<=EXIF_YCBCR_POSITIONING;i++)
	exif_switch_IFD_entry(EXIF_IFD0,i,action);

 for(i=EXIF_EXPOSURE_TIME;i<EXIF_MAKER_NOTE;i++)
	exif_switch_IFD_entry(EXIF_EXIFIFD,i,action);

  for(i=EXIF_FLASHPIX_VERSION;i<=EXIF_SCENE_CAPTURE_TYPE;i++)
	exif_switch_IFD_entry(EXIF_EXIFIFD,i,action);
}

/* Switch On/Off IFD entries*/

void exif_switch_IFD_entry(kal_uint8 IFD,kal_uint8 Entry,kal_uint8 action)
{
	kal_uint32* IFD_switch;
	kal_uint32	mask;

	mask=1 << Entry;

	switch(IFD)
	{
		case EXIF_IFD0:
			IFD_switch=&exif_IFD0_Entry_Switch;
			break;
		case EXIF_EXIFIFD:
			IFD_switch=&exif_ExifIFD_Entry_Switch;
			break;
		case EXIF_EXIFD:
			IFD_switch=&exif_ExIFD_Entry_Switch;
			break;
		default: 
			ASSERT(0);
			return;
	}

	switch(action) 
	{
		case EXIF_SWITCH_ON:
			*IFD_switch |=mask;
			break;
		case EXIF_SWITCH_OFF:
			*IFD_switch &=~mask;
			break;
		default: 
			ASSERT(0);
			return;
	}

}


kal_bool exif_is_switched_on(kal_uint8 IFD,kal_uint8 Entry)
{
 kal_uint32	mask=1<<Entry;

 switch(IFD)
 {
  case EXIF_IFD0:
	return (exif_IFD0_Entry_Switch & mask)>>Entry;
  case EXIF_EXIFIFD:
 	return (exif_ExifIFD_Entry_Switch & mask)>>Entry;
  case EXIF_EXIFD:
	return (exif_ExIFD_Entry_Switch & mask)>>Entry;
  default:
	ASSERT(0);
 }
  return KAL_FALSE;
}

/********************* Below this line, It's Exif Parser *********************/
//STFSAL exif_FSAL;
kal_uint8 exif_parser_buffer[EXIF_PARSER_BUFFER_SIZE];
kal_uint8 exif_decoder_state=EXIF_DECODER_IDLE_STATE;


//--Exif para--
kal_uint16 exif_ByteOrder;
kal_uint32 exif_app1_boundary;
kal_uint32 exif_TiffOffset;
kal_uint32 exif_ReqBufferSize;
kal_uint32 exif_UsedBufferSize;

kal_char** exif_valueArr;
kal_uint16* exif_tagArr;

//--IFD0 para--
kal_uint32	IFD0_entry_pos;
kal_uint16	IFD0_entry_num;

//--ExifIFD para--
kal_uint32	ExifIFD_entry_pos;
kal_uint16	ExifIFD_entry_num;
kal_uint32	exif_MakerNote_pos;
kal_uint32	exif_MakerNote_size;

kal_bool exif_getNextMarker(kal_uint16* marker);
void exif_decoder_acc_tag(kal_uint16 tag,kal_uint16 type);
FSAL_Status exif_read_uint8(kal_uint8* byte);
FSAL_Status exif_read_uint16(kal_uint16 *pwValue);
FSAL_Status exif_read_uint32(kal_uint32 *puValue);
FSAL_Status exif_direct_read_uint16(kal_uint16 *pwValue);
FSAL_Status exif_direct_read_uint32(kal_uint32 *puValue);
FSAL_Status exif_seek_buffer(kal_uint32 offset, kal_uint8 ref);
kal_uint32 exif_set_entry(kal_char** str,kal_char* buffer,exif_dec_entry_struct* Exif_entry);

kal_uint32 Long_stringSize(kal_uint32 x);
kal_uint32 SLong_stringSize(kal_int32 x);
kal_uint32 Float_stringSize(float fp);
kal_uint8* Byte2Hex(kal_uint8 x);

/*************************************************************************
* FUNCTION
*   exif_open_jpeg_file()
*
* DESCRIPTION
*   This function is to open a jpeg file for parsing the exif header
*
* PARAMETERS
*   void* file_name_p
*
* RETURNS
*   The size of buffer required to store the parsing result. If 0 is 
*	returned, it means finding no exif header or somthing error
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 exif_open_jpeg_file(void* file_name_p)
{
 FSAL_Status eFSALRet;
 kal_uint16 marker,JumpDest,halfword,tag,type;
 kal_uint8 byte0,i,byte[2];
 kal_bool Exif_Found=KAL_FALSE;
 
 if(exif_decoder_state!=EXIF_DECODER_IDLE_STATE)
  exif_close_jpeg_file();

 eFSALRet = FSAL_Open(&exif_FSAL,file_name_p, FSAL_READ);
  
  if(eFSALRet !=FSAL_OK)
   {
	return 0;
   }
 FSAL_SetBuffer(&exif_FSAL, EXIF_PARSER_BUFFER_SIZE,exif_parser_buffer);

 eFSALRet = FSAL_Direct_GetFileSize(&exif_FSAL,&exif_FileSize);

 if(eFSALRet !=FSAL_OK)
   {
	return 0;
   }

 /* Check if it's a jpeg file */
 if(FSAL_Read_Bytes(&exif_FSAL, byte,2)==FSAL_OK)
 {
  if(byte[0]!=0xff || byte[1]!=0xD8)
   return 0;
 }

 while(!Exif_Found && exif_getNextMarker(&marker))
 {
  //printf("exif_FSAL.uFileOffset: %d, marker:%x\n",exif_FSAL.uFileOffset,marker);

  if(marker>0xffe1 && marker<= 0xffef)
	marker=0xffe0;

  switch(marker)
  {
    case 0xffe0:
		
		if(exif_direct_read_uint16(&JumpDest)!=FSAL_OK) return 0;
		
		JumpDest-=2;
		exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
		
		break;
	case 0xffe1:
		if(exif_direct_read_uint16(&JumpDest)!=FSAL_OK) return 0;

		//JumpDest+=(exif_FSAL.uFileOffset-2);
		JumpDest-=2;
		
		
		Exif_Found=KAL_TRUE;
		for(i=0;i<6;i++)
		{
		 if(exif_read_uint8(&byte0)!=FSAL_OK) return 0;
		 Exif_Found &=(byte0 == exif_Header[i+4]);
		}

		if(!Exif_Found)
		{
		 exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
		 Exif_Found=KAL_FALSE;
		 break;
		}
		
		if(exif_direct_read_uint16(&exif_ByteOrder)!=FSAL_OK) return 0;

		if(exif_ByteOrder!= EXIF_BIG_ENDIAN && exif_ByteOrder!= EXIF_LITTLE_ENDIAN)
		{
		 exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
		 Exif_Found=KAL_FALSE;
		 break;
		}

		if(exif_read_uint16(&halfword)!=FSAL_OK) return 0;

		if(halfword !=0x002a)
		{
		 exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
		 Exif_Found=KAL_FALSE;
		}
		break;
	case 0xffdb:
	case 0xffc0:
		return 0;
	
	default :
		break;
  }
 }

 //-- Exif Found!! --
 exif_TiffOffset=exif_FSAL.uFileOffset-4;

 if(exif_read_uint32(&IFD0_entry_pos)!=FSAL_OK) return 0;

 if(IFD0_entry_pos<8) return 0;
 
 exif_seek_buffer(IFD0_entry_pos-8,FS_FILE_CURRENT);

 if(exif_read_uint16(&IFD0_entry_num)!=FSAL_OK) return 0;

 IFD0_entry_pos+=exif_TiffOffset;

 //printf("IFD0_pos:%x,  IFD0 num:%x\n",IFD0_entry_pos,IFD0_entry_num);

 exif_ReqBufferSize=0;
 ExifIFD_entry_pos=0;
 ExifIFD_entry_num=0;

  //--acc IFD0--
 for(i=0;i<IFD0_entry_num;i++)
 {
  if(exif_read_uint16(&tag)!=FSAL_OK) return 0;
  if(exif_read_uint16(&type)!=FSAL_OK) return 0;
  
  exif_decoder_acc_tag(tag,type);
  //printf("IFD0 tag:%x, type:%d ,Reqsize:%d\n",tag,type,exif_ReqBufferSize);

  if(tag==0x8769)
  {
   exif_seek_buffer(4,FS_FILE_CURRENT);
   if(exif_read_uint32(&ExifIFD_entry_pos)!=FSAL_OK) return 0;
   
   ExifIFD_entry_pos+=exif_TiffOffset;
  }
  else
   exif_seek_buffer(8,FS_FILE_CURRENT);
 }
 
 //--acc ExifIFD--
 if(ExifIFD_entry_pos>0)
 {
  exif_seek_buffer(ExifIFD_entry_pos,FS_FILE_BEGIN);
  if(exif_read_uint16(&ExifIFD_entry_num)!=FSAL_OK) return 0;
 }

  for(i=0;i<ExifIFD_entry_num;i++)
 {
  if(exif_read_uint16(&tag)!=FSAL_OK) return 0;
  if(exif_read_uint16(&type)!=FSAL_OK) return 0;

   exif_decoder_acc_tag(tag,type);
  //printf("IFD0 tag:%x, type:%d ,Reqsize:%d\n",tag,type,exif_ReqBufferSize);
   exif_seek_buffer(8,FS_FILE_CURRENT);
 }
 
 exif_ReqBufferSize+=(sizeof(tag) * (IFD0_entry_num+ExifIFD_entry_num));
 exif_ReqBufferSize+=(sizeof(void*) * (IFD0_entry_num+ExifIFD_entry_num));
 
 /* Force to 4 byte align */
 exif_ReqBufferSize+=3;
 
 exif_decoder_state=EXIF_DECODER_PREPROCESS_DONE_STATE;
 return exif_ReqBufferSize;
}

#endif //(defined(EXIF_SUPPORT))

kal_bool exif_getNextMarker(kal_uint16* marker)
{
 kal_uint8 byte0=0,byte1=0;

 //printf("exif_FileSize:%d\n",exif_FileSize);

 if(exif_FSAL.uFileOffset>exif_FileSize) return KAL_FALSE;

 while(FSAL_Read_Bytes(&exif_FSAL, &byte1,1)==FSAL_OK)
 {
  //printf("exif_FSAL.uFileOffset: %x, byte0:%x, byte1:%x\n",exif_FSAL.uFileOffset,byte0,byte1);
  if(byte0==0xff && byte1!=0xff) 
  {
   (*marker)=(byte0<<8) | byte1 ;
	//printf(" getMarker %x%x\n",byte0,byte1);
    return KAL_TRUE;
  }
  byte0=byte1;
 }
 return KAL_FALSE;
}

#if (defined(EXIF_SUPPORT)) 

void exif_decoder_acc_tag(kal_uint16 tag,kal_uint16 type)
{
  /* These tags are with built in info */
  switch(tag)
  {
	case exif_tag_Orientation:
			exif_ReqBufferSize+=EXIF_DEC_Orientation_MAX_LEN;
			return;
	case exif_tag_ResolutionUnit:
			exif_ReqBufferSize+=EXIF_DEC_ResolutionUnit_MAX_LEN;
			return;
	case exif_tag_YCbCrPositioning:
			exif_ReqBufferSize+=EXIF_DEC_YCbCrPositioning_MAX_LEN;
			return;
	case exif_tag_ExposureProgram:
			exif_ReqBufferSize+=EXIF_DEC_ExposureProgram_MAX_LEN;
			return;
	case exif_tag_ComponentsConfig:
			exif_ReqBufferSize+=EXIF_DEC_ComponentsConfig_MAX_LEN;
			return;
	case exif_tag_MeteringMode:
			exif_ReqBufferSize+=EXIF_DEC_MeteringMode_MAX_LEN;
			return;
	case exif_tag_LightSource:
			exif_ReqBufferSize+=EXIF_DEC_LightSource_MAX_LEN;
			return;
	case exif_tag_Flash:
			exif_ReqBufferSize+=EXIF_DEC_Flash_MAX_LEN;
			return;
	case exif_tag_ColorSpace:
			exif_ReqBufferSize+=EXIF_DEC_ColorSpace_MAX_LEN;
			return;
	case exif_tag_ExposureMode:
			exif_ReqBufferSize+=EXIF_DEC_ExposureMode_MAX_LEN;
			return;
	case exif_tag_SceneCaptureType:
			exif_ReqBufferSize+=EXIF_DEC_SceneCaptureType_MAX_LEN;
			return;
	default :
		 break;
  }

  switch(type)
  {
   case EXIF_BYTE:
	exif_ReqBufferSize+=EXIF_BYTE_SHOW_LEN;
	break;
   case EXIF_ASCII:
   	exif_ReqBufferSize+=EXIF_ASCII_SHOW_LEN;
	break;
   case EXIF_SHORT:
   	exif_ReqBufferSize+=EXIF_SHORT_SHOW_LEN;
	break;
   case EXIF_LONG:
   	exif_ReqBufferSize+=EXIF_LONG_SHOW_LEN;
	break;
   case EXIF_RATIONAL:
   	exif_ReqBufferSize+=EXIF_RATIONAL_SHOW_LEN;
	break;
   case EXIF_SRATIONAL:
   	exif_ReqBufferSize+=EXIF_SRATIONAL_SHOW_LEN;
	break;
   case EXIF_SLONG:
   	exif_ReqBufferSize+=EXIF_SLONG_SHOW_LEN;
	break;
   case EXIF_UNDEFINED:
   	exif_ReqBufferSize+=EXIF_UNDEFINED_SHOW_LEN;
	break;
	}
}

/*************************************************************************
* FUNCTION
*   exif_parse_jpeg_file()
*
* DESCRIPTION
*   This function is to parse the exif header of a jpeg file.
*	Before calling this function, one should move the decoder state to
*	EXIF_DECODER_PREPROCESS_DONE_STATE by calling exif_open_jpeg_file().
*
* PARAMETERS
*   R_Buffer (Required Buffer for storing the result)
*
* RETURNS
*   Whether the parsing procedure finshied succeffuly
*
* GLOBALS AFFECTED
*
*************************************************************************/
EXIF_DEC_RESULT exif_parse_jpeg_file(kal_uint8* const R_Buffer,kal_uint32 BufferSize)
{
 kal_uint16 i;
 exif_dec_entry_struct Exif_entry;

 if(exif_decoder_state!=EXIF_DECODER_PREPROCESS_DONE_STATE)
  return EXIF_FILE_NOT_OPEN;
 
 if(BufferSize < exif_ReqBufferSize)
  return EXIF_DEC_BUFFER_OVERFLOW;

 exif_tagArr=(kal_uint16*)R_Buffer;
 
 /* force to 4 byte align */
 exif_valueArr=(kal_char**)((((kal_uint32)R_Buffer+2*(IFD0_entry_num+ExifIFD_entry_num)+3)>>2)<<2);
 
 exif_UsedBufferSize=(sizeof(Exif_entry.tag)+ sizeof(void*)) * (IFD0_entry_num+ExifIFD_entry_num)+4;
 
 //printf("R_Buffer:%d tagArr:%d, valueArr:%d, value_offset:%d\n",R_Buffer,tagArr,valueArr,value_offset);
 //printf("IFD0_entry_num:%d ExifIFD_entry_num:%d\n",IFD0_entry_num,ExifIFD_entry_num);

for(i=0;i<IFD0_entry_num;i++)
 {
  exif_valueArr[i]=0;
  exif_seek_buffer(IFD0_entry_pos+2+i*12,FS_FILE_BEGIN);

  if(exif_read_uint16(&Exif_entry.tag)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  if(exif_read_uint16(&Exif_entry.type)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  if(exif_read_uint32(&Exif_entry.count)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  if(exif_read_uint32(&Exif_entry.value)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  

  exif_tagArr[i]=Exif_entry.tag;

  //printf("IFD0, tag:%x, type:%d, count:%d\n",Exif_entry.tag,Exif_entry.type,Exif_entry.count);
  
  exif_UsedBufferSize+=exif_set_entry(&exif_valueArr[i],(kal_char*)(R_Buffer+exif_UsedBufferSize),&Exif_entry);
 
  //printf("value_offset:%d\n",value_offset);

}

for(i=IFD0_entry_num;i<IFD0_entry_num+ExifIFD_entry_num;i++)
 {
  exif_valueArr[i]=0;
  exif_seek_buffer(ExifIFD_entry_pos+2+(i-IFD0_entry_num)*12,FS_FILE_BEGIN);

  if(exif_read_uint16(&Exif_entry.tag)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  if(exif_read_uint16(&Exif_entry.type)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  if(exif_read_uint32(&Exif_entry.count)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  if(exif_read_uint32(&Exif_entry.value)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
  

  exif_tagArr[i]=Exif_entry.tag;

  //printf("ExifIFD, tag:%x, type:%d, count:%d",Exif_entry.tag,Exif_entry.type,Exif_entry.count);
  
  exif_UsedBufferSize+=exif_set_entry(&exif_valueArr[i],(kal_char*)(R_Buffer+exif_UsedBufferSize),&Exif_entry);
 
  //printf("value_offset:%d\n",value_offset);

}
 

 exif_decoder_state=EXIF_DECODER_PARSE_DONE_STATE;
 return EXIF_DEC_DONE;
}

kal_uint32 exif_set_entry(kal_char** str,kal_char* buffer,exif_dec_entry_struct* Exif_entry)
{
  double	 fp;
  kal_uint32 len=0,count=0,value,value1;
  kal_uint16 value16;
  kal_uint8 value8;
  kal_uint8* valueHex;
  kal_int32 Svalue,Svalue1;

  if((Exif_entry->tag==0x927c) && (Exif_entry->count>12))
  {
	exif_MakerNote_size=Exif_entry->count;
	exif_MakerNote_pos=Exif_entry->value+exif_TiffOffset;
  }

  if(Exif_entry->count<1) return 0;

  if(exif_ByteOrder==EXIF_LITTLE_ENDIAN)
  {
   value16=Exif_entry->value & 0xffff;
  }
  else
  {
   value16=(Exif_entry->value>>16);
  }

  switch(Exif_entry->tag)
  {
	case exif_tag_Orientation:
		if(value16<9)
		{
		 *str=buffer;
		 
		 while(len<strlen(exif_Orientation_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_Orientation_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_ResolutionUnit:
	    if(value16<4)
		{
		 *str=buffer;
		 while(len<strlen(exif_ResolutionUnit_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_ResolutionUnit_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_YCbCrPositioning:
	    if(value16<3)
		{
		 *str=buffer;
		 while(len<strlen(exif_YCbCrPositioning_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_YCbCrPositioning_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_ExposureProgram:
		if(value16<=8)
		{
		 *str=buffer;
		 while(len<strlen(exif_ExposureProgram_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_ExposureProgram_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_ComponentsConfig:
	    if((exif_ByteOrder==EXIF_LITTLE_ENDIAN && Exif_entry->value==0x030201) ||
		   (exif_ByteOrder==EXIF_BIG_ENDIAN && Exif_entry->value==0x01020300))
		{
		 *str=buffer;
		 while(len<strlen(exif_ComponentsConfig_table[0]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_ComponentsConfig_table[0][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		else if((exif_ByteOrder==EXIF_LITTLE_ENDIAN && Exif_entry->value==0x060504) ||
				(exif_ByteOrder==EXIF_BIG_ENDIAN && Exif_entry->value==0x04050600))
		{
		 *str=buffer;
		 while(len<strlen(exif_ComponentsConfig_table[1]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_ComponentsConfig_table[1][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_MeteringMode:
	   if(value16==255)
	    value16=8;
	   else if(value16>7 && value16<255)
	    value16=7;
	
	    if(value16<=8)
		{
		 *str=buffer;
		 while(len<strlen(exif_MeteringMode_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_MeteringMode_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_LightSource:
	    if(value16<23)
		{
		 *str=buffer;
		 while(len<strlen(exif_LightSource_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_LightSource_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_Flash:
	    if(value16<96)
		{
		 *str=buffer;
		 while(len<strlen(exif_Flash_table[value16]) /*&& len<EXIF_ASCII_SHOW_LEN-1*/)
		 {
			buffer[len]=exif_Flash_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_ColorSpace:
	    if(value16==1)
		{
		 *str="sRGB";
		 return 0;
		}
		else if(value16==0xffff)
		{
		 *str="Uncalibrated";
		 return 0;
		}
		break;
	case exif_tag_ExposureMode:
		if(value16<8)
		{
		 *str=buffer;
		 while(len<strlen(exif_ExposureMode_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_ExposureMode_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
	case exif_tag_SceneCaptureType:
		if(value16<4)
		{
		 *str=buffer;
		 while(len<strlen(exif_SceneCaptureType_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
		 {
			buffer[len]=exif_SceneCaptureType_table[value16][len];
			len++;
		 }
			buffer[len++]=0;
			return len;
		}
		break;
    case exif_tag_FlashpixVersion:
	case exif_tag_ExifVersion:
		{
		 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
		 return 0;
		 *str=buffer;
  	     exif_read_uint8(&value8);
		 if(value8!='0')
		  buffer[len++]=value8;
		 exif_read_uint8(&value8);
	 	 buffer[len++]=value8;
		 buffer[len++]='.';
		 exif_read_uint8(&value8);
	 	 buffer[len++]=value8;
		 exif_read_uint8(&value8);
		 if(value8!='0')
	 	  buffer[len++]=value8;
		 buffer[len++]=0;
		 return len;
		}
   }

 switch(Exif_entry->type)
 {
   case EXIF_BYTE:
	if(Exif_entry->count<=4)
	{
	 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;
	}
	else
	{
	 if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;	
	}

	*str=buffer;

	while(count++<Exif_entry->count)
	{
     exif_read_uint8(&value8);

	 if(len+Long_stringSize(value8)>=EXIF_BYTE_SHOW_LEN-2)
		 break;

	 len=sprintf(buffer+len,"%u",value8);
	 buffer[len++]=' ';
	}

	buffer[len++]=0;
	//printf("***len:%d %s***",len,buffer[0]);
  return len;

  case EXIF_SHORT:
	if(Exif_entry->count<=2)
	{
	 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;
	}
	else
	{
	 if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;	
	}
	*str=buffer;

	while(count++<Exif_entry->count)
	{
     exif_read_uint16(&value16);
	 if(len+Long_stringSize(value16)>=EXIF_SHORT_SHOW_LEN-2)
		 break;

	 len=sprintf(buffer+len,"%u",value16);
	 buffer[len++]=' ';
	}

	buffer[len++]=0;
	//printf("***len:%d %s***\n",len,buffer);
  return len;

  case EXIF_LONG:
	if(Exif_entry->count<=1)
	{
	 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;
	}
	else
	{
	 if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;	
	}

	//printf("--StringLen:%d \n",Long_stringSize(value));
	*str=buffer;
	while(count++<Exif_entry->count)
	{
	 exif_read_uint32(&value);

	 if((len+Long_stringSize(value) >= EXIF_LONG_SHOW_LEN-2))
		break;

	 len=sprintf(buffer+len,"%u",value);
	 buffer[len++]=' ';
	}

	buffer[len++]=0;
	//printf("***len:%d %s***\n",len,buffer);
  return len;

   case EXIF_SLONG:
	if(Exif_entry->count<=1)
	{
	 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;
	}
	else
	{
	 if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;	
	}

	//printf("--StringLen:%d \n",stringSize(value));

	*str=buffer;
	while(count++<Exif_entry->count)
	{
	 exif_read_uint32(&value);
	 Svalue=(kal_int32)value;

	 if((len+SLong_stringSize(Svalue) >= EXIF_SLONG_SHOW_LEN-2))
		break;

	 len=sprintf(buffer+len,"%u",Svalue);
	 buffer[len++]=' ';
	}

	buffer[len++]=0;
	//printf("***len:%d %s***",len,buffer[0]);
  return len;

  case EXIF_RATIONAL:
	if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
	 return 0;

	*str=buffer;
	if(Exif_entry->tag==exif_tag_ExposureTime)
	{
	while(count++<Exif_entry->count)
	{
	 exif_read_uint32(&value);
	 exif_read_uint32(&value1);

	 if(len+Long_stringSize(value)+Long_stringSize(value1)+1 >= EXIF_RATIONAL_SHOW_LEN-2)
		break;

	 len=sprintf(buffer+len,"%u",value);
	 buffer[len++]='/';
	 len+=sprintf(buffer+len,"%u",value1);
	 buffer[len++]=' ';
	}
	}
   else
	{
	 while(count++<Exif_entry->count)
	 {
	  exif_read_uint32(&value);
	  exif_read_uint32(&value1);

	  if(value==0 || value1==0)
      {
	   buffer[len++]='0';
       break;
	  }

	  fp=((double)value)/value1;

	  if(len+Float_stringSize(fp)+1 >= EXIF_RATIONAL_SHOW_LEN-2)
		break;
	  len=sprintf(buffer+len,EXIF_RATIONAL_PRECISION,fp);
	  buffer[len++]=' ';
	 }
   }
	buffer[len++]=0;
   return len;

   case EXIF_SRATIONAL:
	if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
		return 0;

	*str=buffer;
	if(0)
	{
	while(count++<Exif_entry->count)
	{
	 exif_read_uint32(&value);
	 exif_read_uint32(&value1);

	 if(len+SLong_stringSize(value)+SLong_stringSize(value1)+1 >= EXIF_SRATIONAL_SHOW_LEN-2)
		break;

	 len=sprintf(buffer+len,"%d",value);
	 //printf("*** %d %d",SLong_stringSize(value),SLong_stringSize(value1));
	 buffer[len++]='/';
	 len+=sprintf(buffer+len,"%d",value1);
	 buffer[len++]=' ';
	}
	}
	else
	{
	 while(count++<Exif_entry->count)
	 {
	  exif_read_uint32(&value);
	  exif_read_uint32(&value1);

	  if(value==0 || value1==0)
      {
	   buffer[len++]='0';
       break;
	  }

	  Svalue=(kal_int32)value;
	  Svalue1=(kal_int32)value1;
	  	
	  fp=((double)Svalue)/Svalue1;

	  if(len+Float_stringSize(fp)+1 >= EXIF_RATIONAL_SHOW_LEN-2)
		break;
	  len=sprintf(buffer+len,EXIF_RATIONAL_PRECISION,fp);
	  buffer[len++]=' ';
	 }
   }
	buffer[len++]=0;
   return len;

  case EXIF_ASCII:
	if(Exif_entry->count<=4)
	{
	 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;
	}
	else
	{
	 if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
	  return 0;	
	}
	
	*str=buffer;

	while(count++<Exif_entry->count && len<EXIF_ASCII_SHOW_LEN-1)
	  {
	   exif_read_uint8(&value8);
	   
	   //Check if the char is ASCII ot not
	   if(value8>=32 && value8<127)
	   buffer[len++]=(kal_char)(value8);
	   else
	    buffer[len++]=' ';
	  }
	buffer[len++]=0;
	return len;

  case EXIF_UNDEFINED:
	if(Exif_entry->count<=4)
	{
	 if(exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
		 return 0;
	}
	else
	{
	 if(exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
		 return 0;
	}
	//printf("#### buffer:%d\n",buffer);
	*str=buffer;
	while(count++< Exif_entry->count && (len+3<EXIF_UNDEFINED_SHOW_LEN-2))
	{
	 exif_read_uint8(&value8);

	 valueHex=Byte2Hex(value8);
	 buffer[len++]=valueHex[0];
	 buffer[len++]=valueHex[1];
	 buffer[len++]=' ';
	}
	buffer[len++]=0;
	return len;
  
  default:
    *str=0;
	return 0;
  }
}

#endif


//--Read uint16 as big endian--
FSAL_Status exif_direct_read_uint16(kal_uint16 *pwValue)
{
 kal_uint8 data[2];
 FSAL_Status ret;

 if(exif_FSAL.uFileOffset+2>exif_FileSize) return FSAL_READ_ERROR;

 if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 2))!=FSAL_OK)
   return ret;

 *pwValue = (kal_uint16)((data[0]<<8) + (data[1]));
 
 return FSAL_OK;
}

#if (defined(EXIF_SUPPORT))

FSAL_Status exif_read_uint8(kal_uint8 *pwValue)
{
 if(exif_FSAL.uFileOffset+1>exif_FileSize) return FSAL_READ_ERROR;

 return FSAL_Read_Bytes(&exif_FSAL,pwValue, 1);
}

FSAL_Status exif_read_uint16(kal_uint16 *pwValue)
{
 kal_uint8 data[2];
 FSAL_Status ret;

  FSAL_CHECK_ARG(pwValue!=NULL);

 if(exif_FSAL.uFileOffset+2>exif_FileSize) return FSAL_READ_ERROR;

 if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 2))!=FSAL_OK)
  return ret;

 if(exif_ByteOrder==EXIF_BIG_ENDIAN)
  *pwValue = (kal_uint16)((data[0]<<8) + (data[1]));
 else if(exif_ByteOrder==EXIF_LITTLE_ENDIAN)
  *pwValue = (kal_uint16)((data[1]<<8) + (data[0]));
 else
  return FSAL_FATAL_ERROR;
 
 return FSAL_OK;
}

FSAL_Status exif_read_uint32(kal_uint32 *puValue)
{
   kal_uint8 data[4];
   FSAL_Status ret;

   FSAL_CHECK_ARG(puValue!=NULL);

   if(exif_FSAL.uFileOffset+4>exif_FileSize) return FSAL_READ_ERROR;

   if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 4))!=FSAL_OK)
      return ret;

   if(exif_ByteOrder==EXIF_BIG_ENDIAN)
	*puValue = (kal_uint32)((data[0]<<24) + (data[1]<<16) + (data[2]<<8) + (data[3]));
   else if(exif_ByteOrder==EXIF_LITTLE_ENDIAN)
	*puValue = (kal_uint32)((data[3]<<24) + (data[2]<<16) + (data[1]<<8) + (data[0]));
   else
    return FSAL_FATAL_ERROR;

   return FSAL_OK;
}

FSAL_Status exif_direct_read_uint32(kal_uint32 *puValue)
{
   kal_uint8 data[4];
   FSAL_Status ret;

   FSAL_CHECK_ARG(puValue!=NULL);

  if(exif_FSAL.uFileOffset+4>exif_FileSize) return FSAL_READ_ERROR;

   if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 4))!=FSAL_OK)
      return ret;

   *puValue = (kal_uint32)((data[3]<<24) + (data[2]<<16) + (data[1]<<8) + (data[0]));

   return FSAL_OK;
}
#endif

FSAL_Status exif_seek_buffer(kal_uint32 offset, kal_uint8 ref)
{
	if(ref==FS_FILE_BEGIN)
	{
	 if(offset<exif_FileSize)
	  return FSAL_Seek(&exif_FSAL,offset);	 
	 else
	  return FSAL_SEEK_ERROR;
	}
	else if(ref==FS_FILE_CURRENT)
	{
	   if(exif_FSAL.uFileOffset+offset<exif_FileSize) 
		return FSAL_Seek(&exif_FSAL,exif_FSAL.uFileOffset+offset);
	   else
	    return FSAL_SEEK_ERROR;
	}
	else
	 return FSAL_SEEK_ERROR;
}

#if (defined(EXIF_SUPPORT))

 const kal_uint32 exif_sizeTable[] = { 9, 99, 999, 9999, 99999, 999999, 9999999,
                           99999999, 999999999, 0xffffffff};

 kal_uint32 Float_stringSize(float fp)
 {
  kal_uint32 len;
  len=sprintf((kal_char*)exif_parser_buffer,EXIF_RATIONAL_PRECISION,fp);
  ASSERT(len<EXIF_PARSER_BUFFER_SIZE);
  return len;
 }

 kal_uint32 Long_stringSize(kal_uint32 x)
 {
  kal_uint16 i;
  for (i=0; ; i++)
   if (x <= exif_sizeTable[i])
     return i+1;
 }

 kal_uint32 SLong_stringSize(kal_int32 x)
 {
  kal_uint16 i,p=0;
  if(x<0) 
  {
	x=-x;
	p++;
  }

  for (i=0; ; i++)
   if (x <= exif_sizeTable[i])
     return i+p+1;
 }

 const kal_uint8 exif_DigitTable[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
 kal_uint8 exif_temp_byte[2];

 kal_uint8* Byte2Hex(kal_uint8 x)
 {
   exif_temp_byte[0]=exif_DigitTable[x/16];
   exif_temp_byte[1]=exif_DigitTable[x%16];
  return exif_temp_byte;
 }

/*************************************************************************
* FUNCTION
*   exif_get_tag_list()
*
* DESCRIPTION
*   This function is to retrive tag description string from a jpeg file.
*	Before calling this function, one should move the decoder state to
*	EXIF_DECODER_PARSE_DONE_STATE by calling exif_parse_jpeg_file().
*
* PARAMETERS
*   tagList			The tag list 	
*   IFD0_Size		Record how many tags are there in IFD0
*   ExifIFD_Size	Record how many tags are there in ExifIFD
*
* RETURNS
*   
*
* GLOBALS AFFECTED
*
*************************************************************************/
void exif_get_tag_list(kal_uint16** tagList,kal_uint32* IFD0_Size,kal_uint32* ExifIFD_Size)
{
 if(exif_decoder_state!=EXIF_DECODER_PARSE_DONE_STATE)
 {
  *IFD0_Size=0;
  *ExifIFD_Size=0;
  *tagList=0;
 }
  *IFD0_Size=IFD0_entry_num;
  //printf("IFD0_Size: %d\n",*IFD0_Size);
  *ExifIFD_Size=ExifIFD_entry_num;
 //printf("ExifIFD_Size: %d\n",*ExifIFD_Size);
 *tagList=exif_tagArr;
}

/*************************************************************************
* FUNCTION
*   exif_get_tag_value()
*
* DESCRIPTION
*   This function is to retrive tag description string from a jpeg file.
*	Before calling this function, one should move the decoder state to
*	EXIF_DECODER_PARSE_DONE_STATE by calling exif_parse_jpeg_file().
*
* PARAMETERS
*   kal_uint16 tag
*
* RETURNS
*   kal_char* description, the conetnt of the tag.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_char* exif_get_tag_value(kal_uint16 tag)
{
 kal_uint16 i;

 if(exif_decoder_state!=EXIF_DECODER_PARSE_DONE_STATE)
	 return 0;

 for(i=0;i<IFD0_entry_num+ExifIFD_entry_num;i++)
 {
  if(tag==exif_tagArr[i])
	return exif_valueArr[i];
 }

 return 0;
}

/*************************************************************************
* FUNCTION
*   exif_close_jpeg_file()
*
* DESCRIPTION
*   This function is to close a jpeg file and clear the internal variables
*
* PARAMETERS
*   
*
* RETURNS
*   
*
* GLOBALS AFFECTED
*
*************************************************************************/
void exif_close_jpeg_file(void)
{
	exif_tagArr=0;
	exif_valueArr=0;
	FSAL_Close(&exif_FSAL);
	exif_decoder_state=EXIF_DECODER_IDLE_STATE;

	exif_ByteOrder=0;
	exif_TiffOffset=0;
	exif_ReqBufferSize=0;
	exif_FileSize=0;
	exif_app1_boundary=0;

	//--IFD0 para--
	IFD0_entry_pos=0;
	IFD0_entry_num=0;

	//--ExifIFD para--
	ExifIFD_entry_pos=0;
	ExifIFD_entry_num=0;
	exif_MakerNote_pos=0;
	exif_MakerNote_size=0;
}
#endif

/***************Used for picture-bridge*****************/
#if (defined(PICTBRIDGE_SUPPORT))

kal_bool exif_parse_jpeg_header(void* file_name_p,exif_header_info_struct* info)
{
 //STFSAL jpeg_FSAL;
 FSAL_Status eFSALRet;
 kal_bool return_value;
 kal_uint16 marker,JumpDest;
 kal_uint8 byte[2];
 kal_uint8 buffer[EXIF_JPEG_PARSER_BUFFER_SIZE];
	
  eFSALRet = FSAL_Open(&exif_FSAL,file_name_p, FSAL_READ);
  
  if(eFSALRet !=FSAL_OK)
   {
	return KAL_FALSE;
   }
 FSAL_SetBuffer(&exif_FSAL,EXIF_JPEG_PARSER_BUFFER_SIZE,buffer);
 FSAL_Direct_GetFileSize(&exif_FSAL,&exif_FileSize); 
 
  /* Check if it's a jpeg file */
 if(FSAL_Read_Bytes(&exif_FSAL,byte,2)==FSAL_OK)
 {
  if(byte[0]!=0xff || byte[1]!=0xD8)
   	{
    	 	return_value=KAL_FALSE;
		goto end;
  	}
 }
 
 while(exif_getNextMarker(&marker))
 {
  //printf("jpeg_FSAL.uFileOffset: %x, marker:%x\n",jpeg_FSAL.uFileOffset,marker);
  
  if(marker>=0xffe0 && marker<= 0xffef)
	marker=0xffe0;

  switch(marker)
  {
	case 0xffdd: //Restart interval
    case 0xffdb: //DQT
    case 0xffe0: //APP
	case 0xffc4://DHT
    {
     if(exif_direct_read_uint16(&JumpDest)!=FSAL_OK) 
   	{
    	 	return_value=KAL_FALSE;
		goto end;
  	}
	 
     JumpDest-=2;
     exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
     break;
    }
    
    case 0xffc0: //baseline
    case 0xffc2: //progresive
    {
     if(marker==0xffc2)
      info->progressive=KAL_FALSE;
     else 
      info->progressive=KAL_TRUE;
     
	 exif_seek_buffer(2,FS_FILE_CURRENT); // skip length
     exif_seek_buffer(1,FS_FILE_CURRENT); // skip precision
     
     exif_direct_read_uint16(&info->image_height);
     exif_direct_read_uint16(&info->image_width);
     
    	 return_value=KAL_TRUE;
    	 //break;
    	 goto end;
    }

    case 0xFFDA://SOS
    case 0xFFD9://EOI
    default:
    	 return_value=KAL_FALSE;
    	 break;
  }
 }

end:
FSAL_Close(&exif_FSAL);
 return return_value;
}
#endif //(defined(PICTBRIDGE_SUPPORT))
#endif //(defined(EXIF_SUPPORT) || defined(PICTBRIDGE_SUPPORT))
