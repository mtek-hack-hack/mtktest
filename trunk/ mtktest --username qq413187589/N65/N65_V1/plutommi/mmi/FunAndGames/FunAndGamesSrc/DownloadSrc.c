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
 *	DownloadSrc.c
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file implements screen flow and API of Download application
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
 /**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: DownloadSrc.c

  	PURPOSE		: Main functions of the Fun and Games, Download application

	REMARKS		: nil

	AUTHOR		: Gurinder

	DATE		: July-08-2003

**************************************************************/
#include "MMI_include.h"
#include "FunAndGamesDefs.h"
#include "FunAndGamesProts.h"
#include "CommonScreens.h"
#include "IdleAppDef.h"
#include "resource_audio.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"
#include "stdio.h"
#include "DownloadProtos.h"
#include "DownloadDefs.h"
#include "string.h"
#include "WallpaperDefs.h"
#include "ScreenSaverDefs.h"
#include "gpioInc.h"
#include "SettingDefs.h"
#include "WPSSProtos.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#endif

#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "IdleAppDef.h"
#include "SimDetectionGexdcl.h"

/* 
** Define
*/

/* 031705 Calvin modified */
#include "gui.h"
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#endif
/* Calvin end */

#define DWNL_FULL_SCR_IMG_NAME	"ful"
#define DWNL_FAC_ASS_IMG_NAME "ass"
#define DWNL_FAC_TONE_NAME "mid"
#define DWNL_FAC_IMELODY_NAME "imy"
#define DWNL_IMG_GIF_EXT	"gif"

/* 
** Typedef 
*/


/* 
** Local Variable
*/
static	DYNAUDIOINFO gDwnlFacToneInfo[MAXIMUM_FACTORY_TONES];
static	DYNIMAGEINFO gDwnlFacAssImageInfo[MAXIMUM_ASSOCIATED_FACTORY_IMAGES];
static	DYNIMAGEINFO gDwnlFacFullScrImageInfo[MAXIMUM_FULLSCREEN_FACTORY_IMAGES];


#if defined(__MMI_IMELODY_SUPPORT__)
static	DYNAUDIOINFO gDwnlFacIMelodyInfo[MAXIMUM_FACTORY_IMELODY];
#endif


static U8 gDwnlImageData[MAX_IMAGE_HEADER_LENGTH + MAX_IMAGE_NAME_PATH_WIDTH + MAX_IMAGE_NAME_WIDTH];

#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
DYNAUDIOINFO gDwnlThmToneInfo[MAXIMUM_THEMES_TONES];
#endif
/* 
** Local Function
*/

/* 
** Global Variable
*/
extern CUSTOM_IMAGE nCustImageNames[];
//extern U8 gIsOnIdleScreen;
// extern U8 gIsSimValid;

dwnl_context_struct g_dwnl_cntx;

const S8 wbmpExtn[] = {'.','\0','w','\0','b','\0','m','\0','p','\0','\0','\0'};
const S8 wbmExtn[] = {'.','\0','w','\0','b','\0','m','\0','\0','\0'};
const S8 bmpExtn[] = {'.','\0','b','\0','m','\0','p','\0','\0','\0'};

/* 
** Global Function
*/

#if defined(__MMI_IMELODY_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  GetFactoryIMelodyInfo
* DESCRIPTION
*   Function to fill Audio Info Data for factory iMelody to Caller Pointer
* PARAMETERS
*  	factoryAudioInfo	IN	address pointer to the table of factory iMelody
* RETURNS
*	total number of downloaded factory iMelody
* GLOBALS AFFECTED
*   none
*****************************************************************************/
U8 GetFactoryIMelodyInfo(DYNAUDIOINFO ** factoryAudioInfo)
{
	*factoryAudioInfo=gDwnlFacIMelodyInfo;
	return g_dwnl_cntx.TotalFacIMelodies;
}
#endif


/*****************************************************************************
* FUNCTION
*  InitDownloadNVRAM
* DESCRIPTION
*   Initilize Download Data from NVRAM at Bootup
* PARAMETERS
*	none
* RETURNS
*	none
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void InitDownloadNVRAM(void)
{
	U8 i;
	U8 FileNamePath[MAX_IMAGE_HEADER_LENGTH + MAX_IMAGE_NAME_PATH_WIDTH + MAX_IMAGE_NAME_WIDTH];
	FS_HANDLE fileHandle;
	S8 tmpFileName[MAX_IMAGE_NAME_WIDTH];

	/* factory full screen images */
	g_dwnl_cntx.TotalFacFullScrImages = 0;
	for(i=1; i<=MAXIMUM_FULLSCREEN_FACTORY_IMAGES; i++)
	{
		sprintf(tmpFileName,"%s%d.%s",DWNL_FULL_SCR_IMG_NAME,i,DWNL_IMG_GIF_EXT);
		mmi_asc_to_ucs2((PS8)gDwnlFacFullScrImageInfo[g_dwnl_cntx.TotalFacFullScrImages].ImageName, (PS8)tmpFileName);

		mmi_asc_to_ucs2((PS8)FileNamePath, FULLSCREEN_FACTORY_IMAGE_PATH);
		mmi_ucs2cat((PS8)FileNamePath,(PS8)gDwnlFacFullScrImageInfo[g_dwnl_cntx.TotalFacFullScrImages].ImageName);
		fileHandle= FS_Open((U16*)FileNamePath,FS_READ_ONLY);
		if(fileHandle>0)
		{
			gDwnlFacFullScrImageInfo[g_dwnl_cntx.TotalFacFullScrImages].ImagesId=FULLSCREEN_FACTORY_IMAGE_BASE + i - 1;
			g_dwnl_cntx.TotalFacFullScrImages++;
            FS_Commit(fileHandle);
            FS_Close(fileHandle);
		}
	}

	/* factory associated images */
	g_dwnl_cntx.TotalFacAssoImages=0;
	for(i=1; i<=MAXIMUM_ASSOCIATED_FACTORY_IMAGES; i++)
	{
		sprintf(tmpFileName,"%s%d.%s",DWNL_FAC_ASS_IMG_NAME,i,DWNL_IMG_GIF_EXT);
		mmi_asc_to_ucs2((PS8)gDwnlFacAssImageInfo[g_dwnl_cntx.TotalFacAssoImages].ImageName, (PS8)tmpFileName);
		mmi_asc_to_ucs2((PS8)FileNamePath, ASSOCIATE_FACTORY_IMAGE_PATH);

		mmi_ucs2cat((PS8)FileNamePath,(PS8)gDwnlFacAssImageInfo[g_dwnl_cntx.TotalFacAssoImages].ImageName);
		fileHandle= FS_Open((U16*)FileNamePath,FS_READ_ONLY);
		if(fileHandle>0)
		{
			gDwnlFacAssImageInfo[g_dwnl_cntx.TotalFacAssoImages].ImagesId=ASSOCIATED_FACTORY_IMAGE_BASE + i - 1;
			g_dwnl_cntx.TotalFacAssoImages++;
            FS_Commit(fileHandle);
            FS_Close(fileHandle);
		}
	}

	/* factory tones */
	g_dwnl_cntx.TotalFacTones = 0;
	for(i=1; i<=MAXIMUM_FACTORY_TONES; i++)
	{
		sprintf(tmpFileName,"%s%d.%s",DWNL_FAC_TONE_NAME,i,DWNL_FAC_TONE_NAME);
		mmi_asc_to_ucs2((PS8)gDwnlFacToneInfo[g_dwnl_cntx.TotalFacTones].AudioName, (PS8)tmpFileName);
		mmi_asc_to_ucs2((PS8)FileNamePath, FACTORY_TONE_PATH);

		mmi_ucs2cat((PS8)FileNamePath,(PS8)gDwnlFacToneInfo[g_dwnl_cntx.TotalFacTones].AudioName);
		fileHandle= FS_Open((U16*)FileNamePath,FS_READ_ONLY);
		if(fileHandle>0)
		{
			gDwnlFacToneInfo[g_dwnl_cntx.TotalFacTones].AudioId=FACTORY_TONES_BASE + i - 1;
			g_dwnl_cntx.TotalFacTones++;
            FS_Commit(fileHandle);
            FS_Close(fileHandle);
		}
	}
	
#if defined(__MMI_IMELODY_SUPPORT__)
	/* factory iMelodies */
	g_dwnl_cntx.TotalFacIMelodies=0;
	i=0;
	for(i=1; i<=MAXIMUM_FACTORY_IMELODY; i++)
	{	
		sprintf(tmpFileName,"%s%d.%s",DWNL_FAC_IMELODY_NAME,i,DWNL_FAC_IMELODY_NAME);	
		mmi_asc_to_ucs2((PS8)gDwnlFacIMelodyInfo[g_dwnl_cntx.TotalFacIMelodies].AudioName, (PS8)tmpFileName);
		mmi_asc_to_ucs2((PS8)FileNamePath, FACTORY_IMELODY_PATH);

		mmi_ucs2cat((PS8)FileNamePath,(PS8)gDwnlFacIMelodyInfo[g_dwnl_cntx.TotalFacIMelodies].AudioName);
		fileHandle= FS_Open((U16 *)FileNamePath,FS_READ_ONLY);
		if(fileHandle>0)
		{
			gDwnlFacIMelodyInfo[g_dwnl_cntx.TotalFacIMelodies].AudioId=FACTORY_IMELODY_BASE + i - 1;
			g_dwnl_cntx.TotalFacIMelodies++;
            FS_Commit(fileHandle);
            FS_Close(fileHandle);
		}
	}
#endif

}


/*****************************************************************************
* FUNCTION
*  SyncDownloadFileSystem
* DESCRIPTION
*   To sync files between downloaded table and file system.
*	Delete files that are not in downloaded table
* PARAMETERS
*	a.	IN		path to be sync
*	b.	IN		table to be sync
* RETURNS
*	none
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void SyncDownloadFileSystem(S8 *DirPath, DYNAMICINFO* dynInfo)
{
	S8 SearchString[MAX_IMAGE_NAME_PATH_WIDTH+MAX_SEARCH_STR_LENGTH];
	S8 tempString[MAX_IMAGE_NAME_PATH_WIDTH+MAX_SEARCH_STR_LENGTH];
	S8 FileName[MAX_IMAGE_NAME_WIDTH];
	FS_HANDLE fileHandle;
	
	strcpy(tempString, DirPath );
	strcat(tempString, AST_SEARCH_STR);
	mmi_asc_to_ucs2((PS8)SearchString, (PS8)tempString);	
	
	if((fileHandle = FS_FindFirst((PU16)SearchString, 0, 0, NULL, (PU16)FileName, MAX_IMAGE_NAME_WIDTH))!= FS_NO_ERROR)
		return;
	else
	{
		U8 i = 0 ;
		do
		{
			if(dynInfo->DynInfoType == IMAGEINFO)
			{
				for(i = 0; i<dynInfo->NoOfEntries; i++)
					if(mmi_ucs2cmp((PS8)dynInfo->DYNINFOUNION.ImageInfo[i].ImageName, FileName) == 0)
						break;
			}
			else if(dynInfo->DynInfoType == AUDIOINFO)
			{
				for(i = 0; i<dynInfo->NoOfEntries; i++)
					if(mmi_ucs2cmp((PS8)dynInfo->DYNINFOUNION.AudioInfo[i].AudioName, FileName) == 0)
						break;
			}

			if(i == dynInfo->NoOfEntries)	/* could not find any file in the table */
			{
				strcpy(tempString, DirPath);
				mmi_asc_to_ucs2((PS8)SearchString, (PS8)tempString);
				mmi_ucs2cat((PS8)SearchString,(PS8)FileName);

				if(FS_Delete((U16 *)SearchString) != FS_NO_ERROR )
					PRINT_INFORMATION("Error Deleteing File %s", FileName);
				else
					PRINT_INFORMATION("File Deleted %s", FileName);
			}
		}while(FS_FindNext(fileHandle, NULL, (PU16) FileName, MAX_IMAGE_NAME_WIDTH) == FS_NO_ERROR);
	}
    FS_Commit(fileHandle);
    FS_Close(fileHandle);
}


/*****************************************************************************
* FUNCTION
*  GetImageFileSystem
* DESCRIPTION
*   Function to get filename associated with the ImageId
* PARAMETERS
*	ImageId		IN		index of image
* RETURNS
*	pointer to filename
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S8* GetImageFileSystem(U16 ImageId)
{
	U8 *filename = NULL;

	if(ImageId>=FULLSCREEN_FACTORY_IMAGE_BASE && ImageId<=FULLSCREEN_FACTORY_IMAGE_BASE_END)
	{
		U8 i;
		for(i=0;i<g_dwnl_cntx.TotalFacFullScrImages;i++)
		{
			if(gDwnlFacFullScrImageInfo[i].ImagesId==ImageId) 
			{
				filename=gDwnlFacFullScrImageInfo[i].ImageName;
			}
			if(i==g_dwnl_cntx.TotalFacFullScrImages) return (S8*)(nCustImageNames[0].pImage);
		}
		gDwnlImageData[0] = GetFileExtension((PS8)filename);
 
		mmi_asc_to_ucs2((PS8)&gDwnlImageData[MAX_IMAGE_HEADER_LENGTH], FULLSCREEN_FACTORY_IMAGE_PATH);
	}
	else if(ImageId>=ASSOCIATED_FACTORY_IMAGE_BASE && ImageId<=ASSOCIATED_FACTORY_IMAGE_BASE_END)
	{
		U8 i;
		for(i=0;i<g_dwnl_cntx.TotalFacAssoImages;i++)
		{
			if(gDwnlFacAssImageInfo[i].ImagesId==ImageId) 
			{
				filename=gDwnlFacAssImageInfo[i].ImageName;
			}
		}

		if(i==g_dwnl_cntx.TotalFacAssoImages) 
			return (S8*)(nCustImageNames[0].pImage);
		
		gDwnlImageData[0] = GetFileExtension((PS8)filename);
 
		mmi_asc_to_ucs2((PS8)&gDwnlImageData[MAX_IMAGE_HEADER_LENGTH], ASSOCIATE_FACTORY_IMAGE_PATH);
	}	

	else
	{
		/* Default Empty Image */
		return (S8*)(nCustImageNames[0].pImage);
	}

	memset(&gDwnlImageData[1],0xFF,MAX_IMAGE_HEADER_LENGTH-1);
	mmi_ucs2cat((PS8)gDwnlImageData,(PS8)filename);
	return (S8*)(gDwnlImageData);
}


/*****************************************************************************
* FUNCTION
*  GetFileExtension
* DESCRIPTION
*   Function to get extension of filename 
* PARAMETERS
*	pFileName		IN		filename
* RETURNS
*	image type
* GLOBALS AFFECTED
*   none
*****************************************************************************/
U8 GetFileExtension(S8*	pFileName)
{
	S32	nLength;
	S8*	pFilePtr	=	NULL;

	nLength = mmi_ucs2strlen(pFileName);
	--nLength;
	nLength*=ENCODING_LENGTH;

	while(nLength && 
		(pFileName[nLength] != '.') && (pFileName[nLength-1] == '\0'))
		nLength-=2;

	if(nLength)
		pFilePtr = pFileName+nLength;

	if(pFilePtr &&
		(!(mmi_ucs2cmp((PS8)pFilePtr,(PS8)wbmpExtn))||
		!(mmi_ucs2cmp((PS8)pFilePtr,(PS8)wbmExtn)))
		)
	{
		return IMAGE_TYPE_WBMP_FILE;
	}
	else if (pFilePtr && 
		(!mmi_ucs2cmp((PS8)pFilePtr,(PS8)bmpExtn)))
	{
		return IMAGE_TYPE_BMP_FILE;
	}		
	else
	{
		return IMAGE_TYPE_GIF_FILE;
	}

}


/*****************************************************************************
* FUNCTION
*  GetAudioNameWithPathInFileSystem
* DESCRIPTION
*   To Provide Name of Audio With Full Path In File System( Download/Factory)
* PARAMETERS
*	AudioId		IN		index of audio file
*	AudioData	IN/OUT	buffer to store file path+name
* RETURNS
*	pointer to the filename
* GLOBALS AFFECTED
*   none
*****************************************************************************/
S8 *GetAudioNameWithPathInFileSystem(U16 AudioId, PS8 AudioData)
{
	S8 *filename = NULL;
//	static S8 AudioData[MAX_IMAGE_NAME_PATH_WIDTH + MAX_IMAGE_NAME_WIDTH];
	if(AudioId>=FACTORY_TONES_BASE && AudioId<=FACTORY_TONES_BASE_END)
	{
		U8 i;
		for(i=0;i<g_dwnl_cntx.TotalFacTones;i++)
		{
			if(gDwnlFacToneInfo[i].AudioId==AudioId) 
			{
				filename=(PS8)gDwnlFacToneInfo[i].AudioName;
				break;
			}
		}
		if(i==g_dwnl_cntx.TotalFacTones) 
			return NULL;

		mmi_asc_to_ucs2((PS8)AudioData, FACTORY_TONE_PATH);

		mmi_ucs2cat(AudioData,(PS8)filename);
		return AudioData;
	}
#if defined(__MMI_IMELODY_SUPPORT__)		
	else if(AudioId>=FACTORY_IMELODY_BASE && AudioId<=FACTORY_IMELODY_BASE_END)
	{
		U8 i;
		for(i=0;i<g_dwnl_cntx.TotalFacIMelodies;i++)
		{
			if(gDwnlFacIMelodyInfo[i].AudioId==AudioId) 
			{
				filename=(PS8)gDwnlFacIMelodyInfo[i].AudioName;
				break;
			}
		}
		if(i==g_dwnl_cntx.TotalFacIMelodies) return NULL;

		mmi_asc_to_ucs2((PS8)AudioData, FACTORY_IMELODY_PATH);

		mmi_ucs2cat((PS8)AudioData,(PS8)filename);
		return AudioData;
	}
#endif


#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
	else if(AudioId>=COMPOSED_RINGTONE_BASE && AudioId<=COMPOSED_RINGTONE_BASE_END)
	{
	#ifndef WIN32
		filename = GetComposedIMelodyNameInFileSystem(AudioId);
		if(filename != NULL)
		{
		
			mmi_asc_to_ucs2((PS8)AudioData, (S8*)RINGCOMPOSER_PATH);

			mmi_ucs2cat((PS8)AudioData,(PS8)filename);
			return AudioData;
		}
		else
			return NULL;
	#endif
	}
#endif

#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
	else if(AudioId>=THEME_V2_TONE_BASE && AudioId<=THEME_V2_TONE_BASE_END)
	{
		U8 i;
		for(i=0;i<MAXIMUM_THEMES_TONES;i++)
		{
			if((U16)gDwnlThmToneInfo[i].AudioId==AudioId)
			{
				/*Changes for virtual tone file*/
				mmi_ucs2cpy(AudioData, (S8*)mmi_tm_get_audio_filename(i));
				return AudioData;
			}
		}
	}
#endif 

	return NULL;
}



/*****************************************************************************
* FUNCTION
*	GetFactoryTonesInfo
* DESCRIPTION
*   Function to fill Audio Info Factory Data to Caller Pointer
* PARAMETERS
*	factoryAudioInfo  IN/OUT	address pointer to the table of factory audio
* RETURNS
*	total number of factory tones
* GLOBALS AFFECTED
*	none
*****************************************************************************/
U8 GetFactoryTonesInfo(DYNAUDIOINFO ** factoryAudioInfo)
{
	*factoryAudioInfo=gDwnlFacToneInfo;
	return g_dwnl_cntx.TotalFacTones;
}


/*****************************************************************************
* FUNCTION
*	GetFullScreenFactoryImagesInfo
* DESCRIPTION
*   Function to get filename & Id associated with the Full Screen Factory Image
* PARAMETERS
*	factoryFileInfo  IN/OUT	address pointer to table of factory image
* RETURNS
*	total number of factory images
* GLOBALS AFFECTED
*	none
*****************************************************************************/
U8 GetFullScreenFactoryImagesInfo(DYNIMAGEINFO ** factoryFileInfo)
{
	*factoryFileInfo=gDwnlFacFullScrImageInfo;
	return g_dwnl_cntx.TotalFacFullScrImages;
}


/*****************************************************************************
* FUNCTION
*	GetAssociatedFactoryImagesInfo
* DESCRIPTION
*   Function to get filename & Id associated with the Associated Factory Image
* PARAMETERS
*	factoryFileInfo  IN/OUT	address pointer to table of associated factory image
* RETURNS
*	total number of associated factory images
* GLOBALS AFFECTED
*	none
*****************************************************************************/
U8 GetAssociatedFactoryImagesInfo(DYNIMAGEINFO ** factoryFileInfo)
{
	*factoryFileInfo=gDwnlFacAssImageInfo;
	return g_dwnl_cntx.TotalFacAssoImages;
}


/*****************************************************************************
* FUNCTION
*	getFactoryImageRelativeIndex
* DESCRIPTION
*   To get Factory Image Relative Index( Image Id - Base of Factory )
* PARAMETERS
*	ImageId  IN		file index of image
* RETURNS
*	the relative Id correspoding to base for factory image, 
*	0 if image if is not a factory id
* GLOBALS AFFECTED
*	none
*****************************************************************************/
U8 getFactoryImageRelativeIndex(U16 ImageId)
{
	if(ImageId>=FULLSCREEN_FACTORY_IMAGE_BASE && ImageId<=FULLSCREEN_FACTORY_IMAGE_BASE_END)
		return ImageId - FULLSCREEN_FACTORY_IMAGE_BASE + 1;
	else 
		return 0;
}

/*****************************************************************************
* FUNCTION
*	StopAudioFileSystem
* DESCRIPTION
*   To stop Audio file specified by Audio Id
* PARAMETERS
*	a  IN		file index
* RETURNS
*	none
* GLOBALS AFFECTED
*	none
*****************************************************************************/
void StopAudioFileSystem(U16 AudioId)
{
//	S8 AudioData[MAX_IMAGE_NAME_PATH_WIDTH + MAX_IMAGE_NAME_WIDTH];
//	AudioStopIMelodyFile((PU8)GetAudioNameWithPathInFileSystem(AudioId,(PS8)AudioData));
	mdi_audio_stop_file();
}


#if defined __MMI_DOWNLOADABLE_THEMES_SUPPORT__
U8 GetThemeV2TonesInfo(DYNAUDIOINFO  **downloadThemeTones)
{
 *downloadThemeTones=gDwnlThmToneInfo;
	return MAXIMUM_THEMES_TONES;
}
#endif
