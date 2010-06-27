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
 *   exif.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _EXIF_H
#define _EXIF_H

#include "kal_non_specific_general_types.h"

#if (defined(EXIF_SUPPORT))	
/* Exif specifiec data types */
typedef kal_uint8	exif_BYTE;
typedef kal_char	exif_ASCII;
typedef kal_uint16	exif_SHORT;
typedef kal_uint32	exif_LONG;
typedef exif_LONG	exif_RATIONAL[2];
typedef kal_char	exif_UNDEFINED;
typedef kal_int32	exif_SLONG;
typedef exif_SLONG	exif_SRATIONAL[2];

enum exif_type{	EXIF_BYTE=1,
				EXIF_ASCII,
				EXIF_SHORT,
				EXIF_LONG,
				EXIF_RATIONAL,
				EXIF_UNDEFINED=7,
				EXIF_SLONG=9,
				EXIF_SRATIONAL,
				
				/* Used only in tag <UserComment> */
				EXIF_JIS,
				EXIF_UNICODE
				};

/* Supported 0th IFD tags */
#define exif_tag_Make				0x010f	/* A, Manufacturer of image input equipment */
#define exif_tag_Model				0x0110	/* A, Model of image input equipment */
#define	exif_tag_Orientation		0x0112	/* S, Image rotation */
#define exif_tag_XResolution		0x011a	/* R, Image resolution in width direction */
#define exif_tag_YResolution		0x011b	/* R, Image resolution in height direction */
#define exif_tag_ResolutionUnit		0x0128	/* S, Unit of X and Y resolution */
#define exif_tag_Software			0x0131	/* A, Software used */
#define exif_tag_DateTime			0x0132	/* A, The date and time of image creation */
#define exif_tag_YCbCrPositioning	0x0213	/* S, Y and C positioning */
#define exif_tag_ExifIFD			0x8769	/* L, Exif IFD Pointer */

/* Supported Exif IFD tags */
#define exif_tag_ExposureTime		0x829a	/* R, Exposure time */
#define exif_tag_FNumber			0x829d	/* R, F number */
#define	exif_tag_ExposureProgram	0x8822	/* S, Exposure Program */
#define	exif_tag_ISOSpeedRatings	0x8827	/* S, ISO speed ratings */
#define	exif_tag_ExifVersion		0x9000	/* U, Exif Version */
#define	exif_tag_DateTimeOriginal	0x9003	/* A, Date and time original image was generated */
#define	exif_tag_DateTimeDigitized	0x9004	/* A, Date and time image was made digital data */
#define exif_tag_ComponentsConfig	0x9101	/* U, Meaning of each component */
#define exif_tag_ExposureBiasValue	0x9204	/* SR, Exposure bias */
#define exif_tag_MeteringMode		0x9207	/* S, Metering mode */
#define exif_tag_LightSource		0x9208	/* S, Light source */
#define exif_tag_Flash				0x9209	/* S, Flash */
#define exif_tag_MakerNote			0x927c	/* U, Manufacturer notes */
//#define exif_tag_UserComment		0x9286	/* U, User comments */
#define exif_tag_FlashpixVersion	0xa000	/* U, Supported Flashpix version */
#define exif_tag_ColorSpace			0xa001	/* S, Color space information */
#define exif_tag_PixelXDimension	0xa002	/* L, Valid image width */
#define exif_tag_PixelYDimension	0xa003	/* L, Valid image height */
#define exif_tag_ExposureMode		0xa402	/* S, Exposure mode */
#define exif_tag_DigitalZoomRatio	0xa404	/* R, Digital zoom ratio */
#define exif_tag_SceneCaptureType	0xa406	/* S, Scene capture type */

#define exif_tag_MAXIMUM			65535

//#define exif_Count_MakerNote		20		/* Count of tag, <MakerNote> */
//#define exif_Count_UserComment		30		/* Count of tag, <UserComment> */
//#define exif_Overlap_Offset			2

//#define IFD0_Number_of_Entry	9
//#define ExifIFD_Number_of_Entry	21

#define exif_header_size 10 
#define tiff_header_size 8

enum exif_IFD_type
{
	EXIF_IFD0,
	EXIF_EXIFIFD,

	EXIF_EXIFD,
	EXIF_NO_IFD_DEFINE
};

enum exif_IFD_entry_switch
{
	EXIF_SWITCH_ON,
	EXIF_SWITCH_OFF
};

enum exif_IFD0_Entry
{
	//EXIF_MAKE,
	//EXIF_MODEL,
	EXIF_ORIENTATION,
	EXIF_X_RESOLUTION,
	EXIF_Y_RESOLUTION,
	EXIF_RESOLUTION_UNIT,
	EXIF_SOFTWARE,
	EXIF_DATETIME,
	EXIF_YCBCR_POSITIONING,
	EXIF_EXIF_IFD,

	IFD0_Number_of_Entry
};
enum exif_EXIFIFD_Entry
{
	EXIF_EXPOSURE_TIME,
	EXIF_FNUMBER,
	EXIF_EXPOSURE_PROGRAM,
	EXIF_ISO_SPEED_RATINGS,

	EXIF_EXIF_VERSION,
	EXIF_DATE_TIME_ORIGINAL,
	EXIF_DATE_TIME_DIGITIZED,
	EXIF_COMPONENTS_CONFIG,

	EXIF_EXPOSURE_BIAS_VALUE,
	EXIF_METERING_MODE,
	EXIF_LIGHT_SOURCE,
	EXIF_FLASH,

	EXIF_MAKER_NOTE,
	//EXIF_USER_COMMENT,
	EXIF_FLASHPIX_VERSION,
	EXIF_COLOR_SPACE,

	EXIF_PIXEL_X_DIMENSION,
	EXIF_PIXEL_y_DIMENSION,
	EXIF_EXPOSURE_MODE,
	EXIF_DIGITAL_ZOOM_RATIO,

	EXIF_SCENE_CAPTURE_TYPE,

	ExifIFD_Number_of_Entry
};


typedef struct
{
 //exif_ASCII*	Make;
 //exif_ASCII*	Model;
 exif_SHORT		Orientation;
 exif_RATIONAL	XResolution;
 exif_RATIONAL	YResolution;
 exif_SHORT		ResolutionUnit;				/* 2:inches, 3:centermeters */
 exif_ASCII*	Software;
 exif_ASCII*	DateTime;					/* yyyy:mm:dd hh:mm:ss */
 exif_SHORT		YCbCrPositioning;			/* 1:centered, 2:co-siteded*/
 //exif_LONG ExifIFD;

 /* Supported Exif IFD tags */
 exif_RATIONAL	ExposureTime;
 exif_RATIONAL	FNumber;
 exif_SHORT		ExposureProgram;
 exif_SHORT		ISOSpeedRatings;
 exif_UNDEFINED ExifVersion[4];
 exif_ASCII*	DateTimeOriginal;
 exif_ASCII*	DateTimeDigitized;
 exif_UNDEFINED	ComponentsConfig[4];	/* 1230=YCbCr, 4560=RGB */
 exif_SRATIONAL	ExposureBiasValue;
 exif_SHORT		MeteringMode;
 exif_SHORT		LightSource;
 exif_SHORT		Flash;
 //exif_UNDEFINED	MakerNote[exif_Count_MakerNote];
 //exif_UNDEFINED	UserComment[exif_Count_UserComment];
 exif_UNDEFINED	FlashpixVersion[4];
 exif_SHORT		ColorSpace;
 exif_LONG		PixelXDimension;
 exif_LONG		PixelYDimension;
 exif_SHORT		ExposureMode;
 exif_RATIONAL	DigitalZoomRatio;
 exif_SHORT		SceneCaptureType;
} exif_cam_para_struct;
/*
typedef struct
{
 exif_ASCII*	Make;
 exif_ASCII*	Model;
 exif_UNDEFINED	UserComment[exif_Count_UserComment];
} exif_cus_para_struct;
*/

/* MTK specific tags, version: 0.1 */
#define exif_MTK_specific_ver_main 0
#define exif_MTK_specific_ver_fraction 1

typedef struct
{
  kal_char		title[10];
  kal_uint8		version[2];
  kal_uint32	mtk_para[300];
} exif_MTK_para_struct;

typedef struct
{
	kal_uint16	tag;
	kal_uint16	type;
	kal_uint32	count;
	void*		value;
} exif_entry_struct;

typedef struct
{
	kal_uint8	exif_IFD_type;
	exif_entry_struct	entry;
} exif_extend_entry_struct;

#define EXIF_MAXIMUM_NUMBER_OF_EXIFD_ENTRIES 32
#define EXIF_MAXIMUM_SIZE	3*1024

/* Switch On/Off IFD entries */
void exif_switch_IFD_entry(kal_uint8 IFD,kal_uint8 Entry,kal_uint8 action);

/* Set IFD0, ExifIFD to default values */
exif_cam_para_struct* exif_get_cam_para_struct(void);
exif_MTK_para_struct* exif_get_MTK_para_struct(void);

/* Interface to MT6227 */
kal_uint16 exif_get_custom_IFD_and_buffer_size(kal_uint32 BufferOffset);
kal_bool exif_Fillin_Header(kal_uint8* Buffer,kal_uint32 BufferOffset);

/* Interface to MT6228 */
kal_uint16 exif_Fillin_Buffer(kal_uint8* Buffer,kal_uint32 BufferOffset);

/* Interface to burst mode */
kal_uint32 eixf_burst_mode_fill_header(kal_uint8* Buffer);

/* Interface to customer */
exif_extend_entry_struct* exif_get_custom_specific_IFD(kal_uint8* Number_OF_Entry);

/* For use of including padding bytes into exif header */
void exif_set_extra_included_bytes(kal_uint32 padding_length);

/******** Below this line, It's used for Exif Parser ********/
#define EXIF_BIG_ENDIAN		0x4d4d
#define EXIF_LITTLE_ENDIAN	0x4949

#define EXIF_PARSER_BUFFER_SIZE	256
#define EXIF_RATIONAL_PRECISION		"%1.3f"

/* Show Length of each type of tag, '\0' included */
#define EXIF_BYTE_SHOW_LEN	4
#define EXIF_ASCII_SHOW_LEN 35
//#define EXIF_ASCII_SHOW_LEN 80
#define EXIF_UNDEFINED_SHOW_LEN 20
#define EXIF_SHORT_SHOW_LEN 8
#define EXIF_LONG_SHOW_LEN 14
#define EXIF_SLONG_SHOW_LEN 14
#define EXIF_RATIONAL_SHOW_LEN 24
#define EXIF_SRATIONAL_SHOW_LEN 24

#define EXIF_DEC_Orientation_MAX_LEN		11
#define EXIF_DEC_ResolutionUnit_MAX_LEN	12
#define EXIF_DEC_YCbCrPositioning_MAX_LEN	9
#define EXIF_DEC_ExposureProgram_MAX_LEN	18
#define EXIF_DEC_ComponentsConfig_MAX_LEN	6
#define EXIF_DEC_MeteringMode_MAX_LEN		24
#define EXIF_DEC_LightSource_MAX_LEN		17
#define EXIF_DEC_Flash_MAX_LEN				80
#define EXIF_DEC_ColorSpace_MAX_LEN			13
#define EXIF_DEC_ExposureMode_MAX_LEN		16
#define EXIF_DEC_SceneCaptureType_MAX_LEN	12

#define EXIF_MAXIMUM_SHOW_LEN   EXIF_ASCII_SHOW_LEN

enum exif_decoder_state
{
	EXIF_DECODER_IDLE_STATE,
	EXIF_DECODER_PREPROCESS_DONE_STATE,
	EXIF_DECODER_PARSE_DONE_STATE
};

typedef enum
{
	EXIF_DEC_DONE,
	EXIF_DEC_BUFFER_OVERFLOW,
	EXIF_DEC_FILE_READ_ERROR,
	EXIF_FILE_NOT_OPEN
}EXIF_DEC_RESULT;

typedef struct
{
	kal_uint16	tag;
	kal_uint16	type;
	kal_uint32	count;
	kal_uint32	value;
} exif_dec_entry_struct;

kal_uint32 exif_open_jpeg_file(void* file_name_p);
EXIF_DEC_RESULT exif_parse_jpeg_file(kal_uint8* const Buffer,kal_uint32 BufferSize);
void exif_get_tag_list(kal_uint16** tagList,kal_uint32* IFD0_Size,kal_uint32* ExifIFD_Size);
kal_char* exif_get_tag_value(kal_uint16 tag);
void exif_close_jpeg_file(void);

#endif

#if (defined(PICTBRIDGE_SUPPORT))

#define EXIF_JPEG_PARSER_BUFFER_SIZE	32

typedef struct
{
 kal_bool	progressive;	
 kal_uint16	image_width;
 kal_uint16	image_height;
} exif_header_info_struct;

kal_bool exif_parse_jpeg_header(void* file_name_p,exif_header_info_struct* info);

#endif
#endif /* _EXIF_H */