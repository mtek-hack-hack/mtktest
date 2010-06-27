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

/*******************************************************************************
 * Filename:
 * ---------
 *  WriteRes.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**********************************************************************************
   FILENAME : WriteRes.c

   PURPOSE     : Helper Functions   to Write/Generate the Customizable Resources like Strings,Images,MenuItems..etc. 

   REMARKS     : nil

   AUTHOR      : Subramanya BG 

   DATE     : 20thSept 2002.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
**********************************************************************************/
#include "GlobalMenuItems.h"
#include "buildcfg.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "mmi_features.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "OslMemory.h"
// #include "UCS2prot.h"
//#include "Unicodexdcl.h"
#include "CustResDef.h"
#include "gui_resource_type.h"
#include "gdi_features.h"
#include "ABMLoader.h"


/* buffer size for shell command */
#define SHELL_CMD_BUFLEN            (MAX_FILENAME_LEN + 100)

#define MAX_NAME_LENGTH             100
#define MENUITEM_ID_TYPE            9
#define PARENT_ITEM_ID_TYPE         8
#define NUMBER_OF_MENUITEMS_TYPE    7
#define MENU_ITEM_ORDER_TYPE        6
#define HIDE_FLAG_TYPE              5
#define MOVEABLE_FLAG_TYPE          4
#define DISPLAY_ATTRIBUTE_TYPE      3
#define MENU_ITEM_STRING_ID_TYPE    2
#define MENU_ITEM_IMAGE_ID_TYPE     1
#define TRUE                        1
#define FALSE                       0
#define IMAGE_DESCRIPTOR_SIZE       2
#define BUFFER_SIZE                 4096
#define BUFFER_SIZE1                16

#define OUTPUT_DATA_FILENAME        "..\\..\\Customer\\CustResource\\CustImgDataHW.h"
#define OUTPUT_DATA_FILENAME_EXT    "..\\..\\Customer\\CustResource\\CustImgDataHWExt.h"
#define OUTPUT_MENUTREE_FILENAME    "..\\..\\Customer\\CustResource\\CustMenuTree_Out.c"
#define OUTPUT_IMAGE_NAMES_END      "[] =\n{"
#define NOIMAGE_FILENAMEBUFFER      "..\\\\..\\\\Customer\\\\IMAGES\\\\NOIMAGE.BMP"
#define DEFAULT_FILENAMEBUFFER      "..\\..\\Customer\\Images\\Default.bmp"
#define DEFAULT_FILEBUFFER          "________CUSTOMER__IMAGES__DEFAULT_BMP"

#define AUDIO_OUTPUT_DATA_FILENAME      "..\\..\\Customer\\CustResource\\CustAdoDataHW.h"
#define AUDIO_OUTPUT_DATA_FILENAME_EXT  "..\\..\\Customer\\CustResource\\CustAdoDataHWExt.h"
#define OUTPUT_AUDIO_NAMES_END          "[] =\n{"
#define NOAUDIO_FILENAMEBUFFER          "..\\\\..\\\\Customer\\\\AUDIO\\\\NOAUDIO.MP3"
#define AUDIO_DEFAULT_FILENAMEBUFFER    "..\\..\\Customer\\Audio\\Default.mp3"
#define AUDIO_DEFAULT_FILEBUFFER        "________CUSTOMER__AUDIO__DEFAULT_MP3"

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define ENFB_IMAGE_DATA_FILENAME    "..\\..\\Customer\\CustResource\\CustENFBImgData"//100206 ENFB support
#endif

#define MYFCLOSE(fp)    \
    do                  \
    {                   \
        if (fp != NULL) \
        {               \
            fclose(fp); \
            fp = NULL;  \
        }               \
    } while (0)

image_type_enum ExtImageFlag = SYSTEM_IMAGE;
BOOL ExtAudioFlag = FALSE;

#ifdef DEVELOPER_BUILD_FIRST_PASS

static U8 is_first = 1;
static U32 image_idx = 1;
static U32 audio_idx = 1;

void Extract_Name(S8 *dest, S8 *src, U32 res_type);
MMI_BOOL Iload(S8 *string, U16 *pType);
MMI_BOOL Aload(S8 *string, PU16 pType);

extern int BMPLoader(char *in_filename, char *out_filename, S8 color_depth);

extern CUSTOM_STRING *gpStringRes;
extern CUSTOM_STRING_MAP *gpStringMapRes;

extern FILE *StringListFile;
extern FILE *EnumListFile;

U8 StrIsPopulate[MAX_STRING_MAP_SIZE];
U8 *StrEnum[MAX_STRING_MAP_SIZE];
U8 *Str[MAX_STRING_MAP_SIZE];

extern FILE *OutputImgIDFile;
extern FILE *OutputMenutreeIDFile;
extern FILE *RepeatIDListFile;

#include "ImageGetDimension.h"

#define _POPULATE_RES_C

S32 g_ressize = 0;
S8 g_resmenu_filename[MAX_FILENAME_LEN] = "";

#ifdef _POPULATE_RES_C
extern mmi_resource_base_struct g_mmi_resource_base_table[];
extern FILE *fpMenuResourceUsage;
extern FILE *fpImageResourceUsage;
extern FILE *fpAudioResourceUsage;
extern FILE *fpStringResourceUsage;

U32 g_resimg_count = 0;
U32 g_resado_count = 0;
CUSTOM_RESOURCE_SIZE g_resimg_table[MAX_IMAGE_IDS_SIZE];
CUSTOM_RESOURCE_SIZE g_resado_table[MAX_AUDIO_IDS_SIZE];
#endif /* _POPULATE_RES_C */

extern CUSTOM_IMAGE nCustImageNames[];
extern IMAGENAME_LIST ImageNameList[];
extern CUSTOM_IMAGE_MAP ImageIdMap[];
extern CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[];

extern IMAGENAME_LIST ImageNameListEXT[];
extern CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMapEXT[];

extern FILE *OutputAdoIDFile;

/* decalred in the CustAudioRes.c */
extern CUSTOM_AUDIO nCustAudioNames[];
extern AUDIONAME_LIST AudioNameList[];
extern CUSTOM_AUDIO_MAP AudioIdMap[];
extern CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMap[];
extern AUDIONAME_LIST AudioNameListEXT[];
extern CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMapEXT[];

/* declared in the CustMenuDataRes.c */
extern CUSTOM_MENU nCustMenus[];

/* Global Variables */
S8 filename_buffer[BUFFER_SIZE];
S8 autoimagename_buffer[BUFFER_SIZE];
FILE *nfb_img_res_file;
S8 *output_image_names = NULL;
S32 n_supported_extensions = 1;

#define SUPPORT_N_MEDIA_TYPE     3
S8 *support_media_ext[SUPPORT_N_MEDIA_TYPE] = { "AVI", "3GP", "MP4" };

FILE *dest_file;
int toolFlag = 0;       /* decide if this is run by CustPack tool */
int resultFailFlag = 0; /* decide if this is run by CustPack tool */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
FILE *enfb_img_data_file;
int enfbFlag = 0;
int disableENFB = 0;
U32 enfb_offset = 0;
U32 enfb_size = 0;
#endif

typedef struct Resource_Info
{
    S8 *filename_ext;
    U8 file_type;
} RESOURCE_INFO;

#define MAX_SEQUENTIAL_IMAGE_FRAME      512
#define SUPPORT_N_SEQUENTIAL_IMAGE_TYPE 3

RESOURCE_INFO sequential_image[SUPPORT_N_SEQUENTIAL_IMAGE_TYPE] = {
    {"BMP", IMAGE_TYPE_BMP_SEQUENCE},
    {"JPG", IMAGE_TYPE_JPG_SEQUENCE},
#ifdef __MMI_ALPHA_BLENDING__        
    {"PNG", IMAGE_TYPE_ABM_SEQUENCE}
#else /* __MMI_ALPHA_BLENDING__ */
    {"PNG", IMAGE_TYPE_PNG_SEQUENCE}
#endif /* __MMI_ALPHA_BLENDING__ */
};

RESOURCE_INFO image_resource_info[] = 
{
    {"BMP", IMAGE_TYPE_BMP},
    {"PBM", IMAGE_TYPE_DEVICE_BITMAP},
    {"GIF", IMAGE_TYPE_GIF},
    {"JPG", IMAGE_TYPE_JPG},
    {"AVI", IMAGE_TYPE_AVI},
    {"3GP", IMAGE_TYPE_3GP},
    {"MP4", IMAGE_TYPE_MP4},
    {"PNG", IMAGE_TYPE_PNG},
    {"PPN", IMAGE_TYPE_PPN},
    {"M3D", IMAGE_TYPE_M3D},
    {"CMP", IMAGE_TYPE_SWFLASH},
    {"VIS", IMAGE_TYPE_VIS}
};

RESOURCE_INFO audio_resource_info[] = {
    {"MP3", AUDIO_TYPE_MP3},
    {"IMY", AUDIO_TYPE_IMY},
    {"MID", AUDIO_TYPE_MID},
    {"WAV", AUDIO_TYPE_WAV},
    {"MMF", AUDIO_TYPE_MMF},
    {"PCM", AUDIO_TYPE_PCM},
    {"DVI", AUDIO_TYPE_DVI},
    {"AMR", AUDIO_TYPE_AMR},
    {"AAC", AUDIO_TYPE_AAC},
    {"WMA", AUDIO_TYPE_WMA},
    {"M4A", AUDIO_TYPE_M4A}
};

S32 sequential_interval[MAX_SEQUENTIAL_IMAGE_FRAME];

S8 CustImgPath[] = CUST_IMG_PATH;
S8 CustAdoPath[] = CUST_ADO_PATH;

#ifdef __UCS2_ENCODING
static U16 AnsiiToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer);
#endif 

U16 CurrMaxStringId;
extern U16 CurrMaxImageNum;
extern U16 CurrMaxImageId;
extern U16 CurrMaxMenuItemIndex;

extern U16 CurrMaxImageNumEXT;
extern U16 CurrMaxImageIdEXT;

extern U16 CurrMaxAudioNum;
extern U16 CurrMaxAudioId;
extern U16 CurrMaxAudioNumEXT;
extern U16 CurrMaxAudioIdEXT;

#ifdef __POPULATE_ENGINE_
void AddStringInfo(int StrId, char *pString, char *pStringDisplay);
void AddImageInfo(int ImgId, char *pImage, char *pIMageDisplay);
void AddApplicationInfo(U32 nId, S8 *pName, U32 nMinId, U32 nMaxId);
#endif /* __POPULATE_ENGINE_ */ 

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
MMI_BOOL ENFBAssociatedIDFlag = MMI_FALSE;
MMI_BOOL ENFBAssociatedIDAdded = MMI_FALSE;
extern unsigned short CurrMaxENFBAssociatedIDNum;
extern CUSTOM_ENFB_STR ENFBAssociatedIDList[];
#endif

/* Local Functions */
#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
static U32 GetOffsetFromResourceBase(U16 ImageID);
#endif
static void ConvertToPrintable(S8 *original, S8 *converted);
static U16 MenuItemPresent(U16 ItemId);
static S32 Load_Image_Data(
        FILE *output_file,
        FILE *input_file,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height);
static S32 Load_Audio_Data(
        FILE *output_file, 
        FILE *input_file, 
        U8 audio_identifier);
static void Write_Sequential_Image_Header(
        FILE *output_file,
        U8 image_identifier,
        S32 n_frames,
        U8 play_count,
        S32 *seq_filesize,
        S32 *seq_offset,
        U32 width,
        U32 height);
static void Write_Sequential_Image_File(
        FILE *output_file,
        FILE *input_file,
        S32 filesize);
static MMI_BOOL Write_Sequential_Image(
        char *pathname,
        U16 *pType,
        char *output_name,
        FILE *output_file);
static MMI_BOOL Write_Processed_Data(
        char *filename,
        U8 type,
        char *output_name,
        FILE *output_file);
static MMI_BOOL Write_Unprocessed_Data(
        char *filename,
        FILE *image_file,
        S32 nImageSize,
        U16 *pType,
        char *output_name,
        FILE *output_file);
static U8 ExtractExtension(S8 *src, U32 res_type);
static BOOL ChangeExtension(S8 *src, U32 res_type, S32 ext_type);
static U8 isEmsImage(S8 *path);
static MMI_BOOL isMainmenuImage(S8 *path);
static U8 isSubmenuImage(S8 *path);


/*****************************************************************************
 * FUNCTION
 *  file_exist
 * DESCRIPTION
 *  test whether the file exists
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL file_exist(S8* filename)
{
    FILE *testfp;

    testfp = fopen(filename, "rb");
    if (testfp != NULL)
    {
        fclose(testfp);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  SetENFBAssociatedID
 * DESCRIPTION
 *  start to record associated ID list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL SetENFBAssociatedID(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* if flag = false, set flag = true, allocate memory, and no++ */
	if (ENFBAssociatedIDFlag == MMI_FALSE)
	{
		CUSTOM_ENFB_STR *enfb;
        int str_size = 256;
		int i;

		ENFBAssociatedIDFlag = MMI_TRUE;

		CurrMaxENFBAssociatedIDNum++;

		enfb = &ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum];
		enfb->count = 0;
		enfb->IDs = (U16 *)malloc(MAX_ASSOCIATED_LIST_IDS*sizeof(U16));
		enfb->Ptr = (S8 **)malloc(MAX_ASSOCIATED_LIST_IDS*sizeof(S8*));
		for (i = 0; i < MAX_ASSOCIATED_LIST_IDS ; i++)
		{
			enfb->Ptr[i] = (S8 *)malloc(str_size*sizeof(S8));
		}

		return MMI_TRUE;
	}
	/* error: cannot set flag twice */
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  AddENFBAssociatedIDItem
 * DESCRIPTION
 *  add item to current associated list
 * PARAMETERS
 *  ImageID		[IN]
 *  filename	[IN]
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL AddENFBAssociatedIDItem(U16 ImageID, S8 *filename, U32 type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* if flag = true, record this item: imagd ID & pointer variable */
	if (ENFBAssociatedIDFlag == MMI_TRUE)
	{
		CUSTOM_ENFB_STR *enfb;
        int i;

		enfb = &ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum];
		enfb->IDs[enfb->count] = ImageID;
		Extract_Name(enfb->Ptr[enfb->count], filename, type);
        for (i = 0; i < strlen(enfb->Ptr[enfb->count]); i++)
        {
            enfb->Ptr[enfb->count][i] = toupper(enfb->Ptr[enfb->count][i]);
        }
		enfb->count++;

		return MMI_TRUE;
	}
	/* if flag = false, do not record this item */
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  ResetENFBAssociatedID
 * DESCRIPTION
 *  end of one associated ID list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL ResetENFBAssociatedID(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* if flag = true, set flag = false */
	if (ENFBAssociatedIDFlag == MMI_TRUE)
	{
		ENFBAssociatedIDFlag = MMI_FALSE;

		/* if current associated list is empty, reuse it for next list */
		if (ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum].count == 0)
		{
			CurrMaxENFBAssociatedIDNum--;
		}

		return MMI_TRUE;
	}
	/* error: can not set flag = false twice */
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrENFBAssociatedID
 * DESCRIPTION
 *  end of one associated ID list
 * PARAMETERS
 *  void
 * RETURNS
 *  U32		current associated ID
 *****************************************************************************/
U16 GetCurrENFBAssociatedID(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (ENFBAssociatedIDFlag == MMI_TRUE)
	{
	    return CurrMaxENFBAssociatedIDNum;
	}
	else
	{
        return 0;
	}
}


/*****************************************************************************
 * FUNCTION
 *  IfItemExistENFBAssociatedID
 * DESCRIPTION
 *  test if the ImageID has already existed in one associated ID list
 * PARAMETERS
 *  ImageID     [IN]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL IfItemExistENFBAssociatedID(S8 *filename, U32 type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    int i, j, k;
    int str_size = 256;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    for (i = 1; i <= (int)CurrMaxENFBAssociatedIDNum; i++)
    {
		CUSTOM_ENFB_STR *enfb;
        S8 *ptr;

		enfb = &ENFBAssociatedIDList[i];
        for (j = 0; j <= (int)enfb->count; j++)
        {
            ptr = (S8 *)malloc(str_size*sizeof(S8));
            Extract_Name(ptr, filename, type);
            for (k = 0; k < strlen(ptr); k++)
            {
                ptr[k] = toupper(ptr[k]);
            }
            if (strcmp((char *)ptr, (char *)enfb->Ptr[j]) == 0)
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}
#endif


#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
static U32 GetOffsetFromResourceBase(U16 ImageID)
{
    U32 i = 0;
    
    while (1)
    {
        if (strncmp(g_mmi_resource_base_table[i].appname, "END", 3) == 0)
        {
            break;
        }
        else if ((ImageID >= g_mmi_resource_base_table[i].min) &&
                 (ImageID < g_mmi_resource_base_table[i].max))
        {
            return i;
        }
        else
        {
            i++;
        }
    }

    return 0xFFFFFFFF;
}


#define RESPRT(fp, app, base, ID, strID, size, data, resfile)   \
    do                                                          \
    {                                                           \
        fprintf(fp, "%s\t%d\t%d\t%s\t%d\t%s\t%s\n",             \
                app, base, ID, strID, size, data, resfile);     \
    } while (0)


#define RESPRTONERECORD(fp, nImgId, data, enum_value, resfile)      \
    do                                                              \
    {                                                               \
        if (fp != NULL)                                             \
        {                                                           \
            U32 offset = GetOffsetFromResourceBase(nImgId);         \
            if (offset == 0xFFFFFFFF)                               \
            {                                                       \
                RESPRT(fp, "NO_APP", -1, nImgId, enum_value,        \
                       g_ressize, data, resfile);                   \
            }                                                       \
            else                                                    \
            {                                                       \
                RESPRT(fp,                                          \
                       g_mmi_resource_base_table[offset].appname,   \
                       g_mmi_resource_base_table[offset].min,       \
                       nImgId, enum_value, g_ressize, data,         \
                       resfile);                                    \
            }                                                       \
        }                                                           \
    } while (0)
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */


/*****************************************************************************
 * FUNCTION
 *  InitStrPopulate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitStrPopulate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_STRING_MAP_SIZE; i++)
    {
        StrIsPopulate[i] = 0;
    }

}

/* MTK Leo add, to store new string */


/*****************************************************************************
 * FUNCTION
 *  ConvertToPrintable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  original        [?]     
 *  converted       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void ConvertToPrintable(S8 *original, S8 *converted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j = 0, strlength = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlength = wcslen((wchar_t*) original);
    for (i = 0; i < strlength * 2; i++)
    {
        if (original[i] == 10)
        {
            converted[j] = 92;
            converted[++j] = 0;
            converted[++j] = 'n';
            j++;
        }
        else
        {
            converted[j++] = original[i];
        }
    }
    if (strlength == 0)
    {   /* If NULL string, fill in " " */
        converted[0] = 20;
        converted[1] = '\0';
        converted[2] = '\0';
        converted[3] = '\0';
    }
    else
    {
        converted[j++] = '\0';
        converted[j] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  AnsiiToUnicodeString
 * DESCRIPTION
 *  Converts Ansii encode string to unicode
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be as large
 * PARAMETERS
 *  pOutBuffer      [OUT]     
 *  pInBuffer       [IN]     
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 AnsiiToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer != '\0')
    {
        pOutBuffer[++count] = *pInBuffer;
        pOutBuffer[++count] = 0;
        pInBuffer++;
    }

    pOutBuffer[++count] = '\0';
    pOutBuffer[++count] = '\0';
    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  SetStringWithDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nStrId          [IN]        
 *  pString1        [IN]         
 *  pDisplay1       [IN]         
 *  enum_value      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void SetStringWithDisplay(U16 nStrId, S8 *pString1, S8 *pDisplay1, S8 *enum_value, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pString = NULL;
    S8 *pEnum_value = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ressize = 1;  //strlen(pString1);
#ifdef _POPULATE_RES_C
    if (strstr(pString1, "\n") == NULL)
    {
        RESPRTONERECORD(fpStringResourceUsage, nStrId, pString1, enum_value, resfile);
    }
    else
    {
        RESPRTONERECORD(fpStringResourceUsage, nStrId, "N/A", enum_value, resfile);
    }
#endif /* _POPULATE_RES_C */

    if (*pString1 == '\0')
    {
        /* for null string, replace with a specific marker(20) */
        pString = malloc(4);
        *pString = 20;
        *(pString + 1) = '\0';
        *(pString + 2) = '\0';
        *(pString + 3) = '\0';
    }
    else
    {
        pString = malloc((strlen(pString1) + 1) * 2);
        AnsiiToUnicodeString(pString, pString1);
    }

    pEnum_value = malloc((strlen(enum_value) + 1) * 2);
    AnsiiToUnicodeString(pEnum_value, enum_value);

    /* Leo remove, no need to set limit */
    //      if(CurrMaxStringId >= MAX_STRING_IDS) return;   /* Can't add more than max number of string ids allowed */
    //      if (gpStringMapRes[nStrId]==(U16)-1) 
    if (StrIsPopulate[nStrId] == 0)
    {
        CurrMaxStringId++;
        StrIsPopulate[nStrId] = 1;
        StrEnum[nStrId] = pEnum_value;
        Str[nStrId] = pString;
    }
    else    /* 102604 MTK Calvin added */
    {
        fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nStrId, enum_value, "String");
    }
}


/*****************************************************************************
 * FUNCTION
 *  AddApp
 * DESCRIPTION
 *  Function to Add a new application into the framework
 * PARAMETERS
 *  nId         [IN]        App Id
 *  pName       [IN]        Application name.
 *  nMinId      [IN]        Minimum Id value supported
 *  nMaxId      [IN]        Maximum Id value
 * RETURNS
 *  void
 *****************************************************************************/
void AddApp(U32 nId, S8 *pName, U16 nMinId, U16 nMaxId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ResourceInfo sInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sInfo.nAppId = nId;
    sInfo.nMaxId = nMaxId;
    sInfo.nMinId = nMinId;
    sInfo.pValue = pName;
}


/*****************************************************************************
 * FUNCTION
 *  SetString
 * DESCRIPTION
 *  Function to Update the Customizable Resource String & Mapping Array.
 * PARAMETERS
 *  StrId           [IN]        
 *  String1         [?]         
 *  enum_value      [?]         
 *  U16(?)          [OUT]       String Number which is Mapped with the StringId.
 * RETURNS
 *  StringNumber which is mapped with the StringID.(?)
 *****************************************************************************/
void SetString(U16 StrId, S8 *String1, S8 *enum_value, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetStringWithDisplay(StrId, String1, String1, enum_value, resfile);  /* 040805 CustPack: Calvin revised */
}


/*****************************************************************************
 * FUNCTION
 *  SetImage
 * DESCRIPTION
 *  Function to Update the Customizable Image Filename & Mapping Array.
 * PARAMETERS
 *  ImgId           [IN]        
 *  filename        [?]         
 *  enum_value      [?]         
 *  res_type        [IN]        
 *  U16(?)          [OUT]       Image Number which is Mapped with the ImageId.
 * RETURNS
 *  Image Number which is mapped with the ImageId.(?)
 *****************************************************************************/
void SetImage(U16 ImgId, S8 *filename, S8 *enum_value, U32 res_type, S8 *resfile)  /* 120304 Calvin modified for media resource */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetImageWithBuffer(ImgId, filename, "", enum_value, res_type, FALSE, resfile);       /* 040805 CustPack: Calvin revised */
}


/*****************************************************************************
 * FUNCTION
 *  SetNFBImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void SetNFBImage(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nType;
    S16 nStrlen;
    S8 upperFileName[MAX_FILENAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strcpy(filename_buffer, filename);
    
    if (strlen(filename_buffer) >= MAX_FILENAME_LEN)
    {
        filename_buffer[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename_buffer);

    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename_buffer[nStrlen]);
        --nStrlen;
    }

    ExtImageFlag = NFB_PROGRESS_IMAGE;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    disableENFB = 1;
#endif
    Iload(upperFileName, &nType);
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    disableENFB = 0;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  SetImageWithBuffer
 * DESCRIPTION
 *  Function to copy the image file to buffer
 * PARAMETERS
 *  nImgId              [IN]        
 *  filename            [?]         
 *  pDisplayName        [?]         
 *  enum_value          [?]         
 *  res_type            [IN]        
 *  imgFlag             [IN]        
 *  S8(?)               [OUT]       -> filename of the image to be displayed.
 *  U16(?)              [IN]        -> ImageId
 * RETURNS
 *  void
 *****************************************************************************/
void SetImageWithBuffer(U16 nImgId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL imgFlag, S8 *resfile)      /* 120304 Calvin modified for media resource */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 found = 0;
    S16 nStrlen;
    ResourceInfo sInfo;
    U16 nType;
    S8 upperFileName[MAX_FILENAME_LEN];
    unsigned short *pCurrMaxImageId;
    unsigned short *pCurrMaxImageNum;
    IMAGENAME_LIST *pImageNameList;
    CUSTOM_IMAGE_MAP *pImageIdMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgFlag == TRUE)
    {
        ExtImageFlag = EXT_IMAGE;
        pCurrMaxImageId = &CurrMaxImageIdEXT;
        pCurrMaxImageNum = &CurrMaxImageNumEXT;
        pImageNameList = ImageNameListEXT;
        pImageIdMap = ImageIdMapEXT;
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        #ifdef MULTIPLE_BINARY_FILES
        disableENFB = 1;
        #endif
    #endif
    }
    else
    {
        ExtImageFlag = SYSTEM_IMAGE;
        pCurrMaxImageId = &CurrMaxImageId;
        pCurrMaxImageNum = &CurrMaxImageNum;
        pImageNameList = ImageNameList;
        pImageIdMap = ImageIdMap;
    }

    if (*pCurrMaxImageId >= MAX_IMAGE_IDS_SIZE)
    {
        return; /* Can't add more than max number of image ids allowed */
    }

    fprintf(OutputImgIDFile, "file name%d = %s \n", image_idx++, filename);

    if (strlen(filename) >= MAX_FILENAME_LEN)
    {
        filename[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename);

    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename[nStrlen]);
        --nStrlen;
    }

    if (pImageIdMap[nImgId].nImageNum != (U16)-1)
    {
        switch (res_type)
        {
            case RES_IMAGE:
                fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nImgId, enum_value, "Image");
                break;
            case RES_MEDIA:
                fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nImgId, enum_value, "Media");
                break;
            default:
                printf("Non supported resource type!\n");
        }

        return;
    }

    for (i = 0; i < *pCurrMaxImageNum; i++)
    {
        if (!strcmp(pImageNameList[i].filename, upperFileName))
        {
            found = 1;
            break;
        }
    }

    g_ressize = 0;

    if (found)
    {
        pImageIdMap[nImgId].nImageNum = i;
        (*pCurrMaxImageId)++;
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__//100206 ENFB support
        if ((disableENFB == 0) && (ENFBAssociatedIDFlag == MMI_TRUE))
        {
            if (IfItemExistENFBAssociatedID(upperFileName, res_type))//already in other associated group
            {
                AddENFBAssociatedIDItem(nImgId, upperFileName, res_type);
            }
            else
            {
                fprintf(RepeatIDListFile, "\n\n!!!!!!!!!!!!%d\t%s\t\t%s!!!!!!!!!!!!!\n\n", nImgId, enum_value, upperFileName);
            }
        }
    #endif

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
        {
            S8 str1[MAX_IMAGE_NAMES_SIZE];
            S8 str2[MAX_IMAGE_NAMES_SIZE];
            U32 i, j;

            strcpy(str1, filename);
            for (j = 0; j < strlen(str1); j++)
            {
                str1[j] = toupper(str1[j]);
            }
            for (i = 0; i < g_resimg_count; i++)
            {
                strcpy(str2, g_resimg_table[i].filename);
                for (j = 0; j < strlen(str1); j++)
                {
                    str2[j] = toupper(str2[j]);
                }
                if (strcmp(str1, str2) == 0)
                {
                    g_ressize = g_resimg_table[i].size;
                    break;
                }
            }
        }
        RESPRTONERECORD(fpImageResourceUsage, nImgId, filename, enum_value, resfile);
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */
    }
    else
    {
        if (Iload(upperFileName, &nType))
        {
            strcpy(pImageNameList[*pCurrMaxImageNum].filename, upperFileName);
            pImageIdMap[nImgId].nImageNum = *pCurrMaxImageNum;
            (*pCurrMaxImageNum)++;
            (*pCurrMaxImageId)++;
        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            if ((disableENFB == 0) && (ENFBAssociatedIDFlag == MMI_TRUE))
            {
                if (ENFBAssociatedIDAdded == MMI_TRUE)//already in other associated group
                {
                    AddENFBAssociatedIDItem(nImgId, upperFileName, res_type);
                    ENFBAssociatedIDAdded = MMI_FALSE;
                }
            }
        #endif

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
            g_resimg_table[g_resimg_count].size = g_ressize;
            strcpy(g_resimg_table[g_resimg_count].filename, filename);
            g_resimg_count ++;
            RESPRTONERECORD(fpImageResourceUsage, nImgId, filename, enum_value, resfile);
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */
        }
        /* CustPack: let new set of images share the same resource of default image */
        else
        {
            if (toolFlag)
            {
                resultFailFlag = 1;
            }
            strcpy(ImageNameList[CurrMaxImageNum].filename, DEFAULT_FILEBUFFER);
            ImageIdMap[nImgId].nImageNum = CurrMaxImageNum;
            CurrMaxImageNum++;
            CurrMaxImageId++;
        }
    }
    sInfo.pDisplayValue = pDisplayName;
    sInfo.pValue = upperFileName;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    disableENFB = 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SetAudioWithBuffer
 * DESCRIPTION
 *  Function to copy the audio file to buffer
 * PARAMETERS
 *  nAdoId              [IN]        -> audio ID
 *  filename            [IN]        -> audio resource filename
 *  pDisplayName        [IN]        -> displayed enum name
 *  enum_value          [IN]        -> enun value
 *  res_type            [IN]        -> resource type
 *  adoFlag             [IN]        -> audio flag
 *  resfile             [OUT]       -> filename of the audio to be generated.
 * RETURNS
 *  void
 *****************************************************************************/
void SetAudioWithBuffer(
        U16 nAdoId,
        S8 *filename,
        S8 *pDisplayName,
        S8 *enum_value,
        U32 res_type,
        BOOL adoFlag,
        S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 found = 0;
    S16 nStrlen;
    U16 nType;
    S8 upperFileName[MAX_FILENAME_LEN];
    unsigned short *pCurrMaxAudioId;
    unsigned short *pCurrMaxAudioNum;
    AUDIONAME_LIST *pAudioNameList;
    CUSTOM_AUDIO_MAP *pAudioIdMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (adoFlag == TRUE)
    {
        ExtAudioFlag = TRUE;
        pCurrMaxAudioId = &CurrMaxAudioIdEXT;
        pCurrMaxAudioNum = &CurrMaxAudioNumEXT;
        pAudioNameList = AudioNameListEXT;
        pAudioIdMap = AudioIdMapEXT;
    }
    else
    {
        ExtAudioFlag = FALSE;
        pCurrMaxAudioId = &CurrMaxAudioId;
        pCurrMaxAudioNum = &CurrMaxAudioNum;
        pAudioNameList = AudioNameList;
        pAudioIdMap = AudioIdMap;
    }

    if (*pCurrMaxAudioId >= MAX_AUDIO_IDS_SIZE)
    {
        /* Can't add more than max number of audio ids allowed */
        return;
    }

    fprintf(OutputAdoIDFile, "file name%d = %s \n", audio_idx++, filename);

    if (strlen(filename) >= MAX_FILENAME_LEN)
    {
        filename[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename, "")))
    {
        strcpy(filename_buffer, NOAUDIO_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename);

    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename[nStrlen]);
        --nStrlen;
    }

    if (pAudioIdMap[nAdoId].nAudioNum != (U16)-1)
    {
        switch (res_type)
        {
            case RES_AUDIO:
                fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nAdoId, enum_value, "Audio");
                break;
                
            default:
                printf("Non supported resource type!\n");
                return;
        }

        return;
    }

    for (i = 0; i < *pCurrMaxAudioNum; i++)
    {
        if (!strcmp(pAudioNameList[i].filename, upperFileName))
        {
            found = 1;
            break;
        }
    }

    g_ressize = 0;

    if (found)
    {
        pAudioIdMap[nAdoId].nAudioNum = i;
        (*pCurrMaxAudioId)++;

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
        {
            S8 str1[MAX_AUDIO_NAMES_SIZE];
            S8 str2[MAX_AUDIO_NAMES_SIZE];
            U32 i, j;

            strcpy(str1, filename);
            for (j = 0; j < strlen(str1); j++)
            {
                str1[j] = toupper(str1[j]);
            }
            for (i = 0; i < g_resado_count; i++)
            {
                strcpy(str2, g_resado_table[i].filename);
                for (j = 0; j < strlen(str1); j++)
                {
                    str2[j] = toupper(str2[j]);
                }
                if (strcmp(str1, str2) == 0)
                {
                    g_ressize = g_resado_table[i].size;
                    break;
                }
            }
        }
        RESPRTONERECORD(fpAudioResourceUsage, nAdoId, filename, enum_value, resfile);
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */
    }
    else
    {
        if (Aload(upperFileName, &nType))
        {
            strcpy(pAudioNameList[*pCurrMaxAudioNum].filename, upperFileName);
            pAudioIdMap[nAdoId].nAudioNum = *pCurrMaxAudioNum;
            (*pCurrMaxAudioNum)++;
            (*pCurrMaxAudioId)++;

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
            g_resado_table[g_resado_count].size = g_ressize;
            strcpy(g_resado_table[g_resado_count].filename, filename);
            g_resado_count ++;
            RESPRTONERECORD(fpAudioResourceUsage, nAdoId, filename, enum_value, resfile);
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */
        }
        else
        {
            if (toolFlag)
            {
                resultFailFlag = 1;
            }
            strcpy(AudioNameList[CurrMaxAudioNum].filename, AUDIO_DEFAULT_FILEBUFFER);
            AudioIdMap[nAdoId].nAudioNum = CurrMaxAudioNum;
            CurrMaxAudioNum++;
            CurrMaxAudioId++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  MenuItemPresent
 * DESCRIPTION
 *  Function to find ImageId
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [IN]        -> ImageId
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 MenuItemPresent(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CurrMaxMenuItemIndex; i++)
    {
        if (nCustMenus[i].nMenuItemId == ItemId)
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PrintMenuItems
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure, for MenuTree Tool usage
 * PARAMETERS
 *  arg1        [?]         
 *  U16(?)      [IN]        -> variable argument list
 * RETURNS
 *  void
 *****************************************************************************/
static char is_dummy_code = 0;  /* To check if it needs to generate for menu tree tool or not. */
void PrintMenuItems(char *arg1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* static U8 is_first=1; */
    FILE *fout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_dummy_code == 1)
    {
        return;
    }

    if (is_first)
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "w");
        is_first = 0;
    }
    else
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "a");
    }

    if (fout != NULL)
    {
        fprintf(fout, "ADD_APPLICATION_MENUITEM2(%s);\n", arg1);
        fclose(fout);
    }

}


/*****************************************************************************
 * FUNCTION
 *  PrintMenuItems2
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure, for MenuTree Tool usage
 * PARAMETERS
 *  arg1        [?]         
 *  U16(?)      [IN]        -> variable argument list
 * RETURNS
 *  void
 *****************************************************************************/
void PrintMenuItems2(char *arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* static U8 is_first=1; */
    FILE *fout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_dummy_code == 1)
    {
        return;
    }

    if (is_first)
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "w");
        is_first = 0;
    }
    else
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "a");
    }

    if (fout != NULL)
    {
        fprintf(fout, "ADD_APPLICATION_MENUITEM3(%s);\n", arg1);
        fclose(fout);
    }

}


/*****************************************************************************
 * FUNCTION
 *  SetMenuItem
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure
 * PARAMETERS
 *  arg1        [IN]        
 *  U16(?)      [IN]        -> variable argument list
 * RETURNS
 *  void
 *****************************************************************************/
void SetMenuItem(U16 arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 MemberCounter = 9;
    U16 i = arg1;
    U16 j;
    U16 menuItemID;
    va_list argumentPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 091004 MTK Calvin removed to reduce populate time */
    //FILE  *fout;
    //static U8 is_first=1;

    //if (is_first)
    //{
    //   fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"w");
    //   is_first= 0;
    //}
    /* MTK Calvin end */

#ifdef _POPULATE_RES_C
    va_start(argumentPtr, arg1);
#endif /* _POPULATE_RES_C */

    RESPRT(fpMenuResourceUsage, "NO_APP", -1, i, "unknown", 1, "none", g_resmenu_filename);

    /* Need to decide whether menu item already present */
    if (!MenuItemPresent(i))
    {
        /* 091004 MTK Calvin removed fopen and fclose to reduce populate time and replaced fout with OutputMenutreeIDFile */
        /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
        fprintf(OutputMenutreeIDFile, "ADD_APPLICATION_MENUITEM2((", arg1);
        /* fclose(fout); */

        is_dummy_code = 0;
        while (MemberCounter)
        {
            switch (MemberCounter)
            {
                case MENUITEM_ID_TYPE:
                    menuItemID = i - 1;

                    nCustMenus[menuItemID].nMenuItemId = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case PARENT_ITEM_ID_TYPE:
                    nCustMenus[menuItemID].nParentId = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case NUMBER_OF_MENUITEMS_TYPE:
                    nCustMenus[menuItemID].nNumofMenuItem = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case MENU_ITEM_ORDER_TYPE:
                    if (nCustMenus[menuItemID].nNumofMenuItem == 0)
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) 0;
                    }
                    else
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) malloc(sizeof(U16) * MENU_ITEM_SIZE);
                        for (j = 0; j < nCustMenus[menuItemID].nNumofMenuItem; j++)
                        {
                            /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                            fprintf(OutputMenutreeIDFile, "%d,", i);
                            /* fclose(fout); */
                            nCustMenus[menuItemID].nOrderMenuItemId[j] = i;
                            i = va_arg(argumentPtr, int);
                        }
                    }
                    break;
                case HIDE_FLAG_TYPE:
                    nCustMenus[menuItemID].nHideFlag = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case MOVEABLE_FLAG_TYPE:
                    nCustMenus[menuItemID].nMovable = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case DISPLAY_ATTRIBUTE_TYPE:
                    nCustMenus[menuItemID].nDispAttribute = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case MENU_ITEM_STRING_ID_TYPE:
                    nCustMenus[menuItemID].nStrId = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    /* fclose(fout); */
                    break;
                case MENU_ITEM_IMAGE_ID_TYPE:
                    nCustMenus[menuItemID].nImageId = i;
                    /* fout = fopen(OUTPUT_MENUTREE_ID_FILENAME,"a"); */
                    fprintf(OutputMenutreeIDFile, "%d));\n", i);
                    /* fclose(fout); */
                    break;
            }
            if (MemberCounter != MENU_ITEM_ORDER_TYPE)
            {
                i = va_arg(argumentPtr, int);
            }

            MemberCounter--;
        }
        /* MTK Calvin end */
    }
    else
    {
        is_dummy_code = 1;
    }

    va_end(argumentPtr);
}


/*****************************************************************************
 * FUNCTION
 *  SetMenuItem2
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure
 * PARAMETERS
 *  arg1        [IN]        
 *  U16(?)      [IN]        -> variable argument list
 * RETURNS
 *  void
 *****************************************************************************/
void SetMenuItem2(U16 arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 MemberCounter = 9;
    U16 i = arg1;
    U16 j;
    U16 menuItemID;
    va_list argumentPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(argumentPtr, arg1);

#ifdef _POPULATE_RES_C
    RESPRT(fpMenuResourceUsage, "NO_APP", -1, i, "unknown", 1, "none", g_resmenu_filename);
#endif /* _POPULATE_RES_C */

    /* Need to decide whether menu item already present */
    if (!MenuItemPresent(i))
    {
        fprintf(OutputMenutreeIDFile, "ADD_APPLICATION_MENUITEM2((", arg1);

        is_dummy_code = 0;
        while (MemberCounter)
        {
            switch (MemberCounter)
            {
                case MENUITEM_ID_TYPE:
                    menuItemID = i - 1;

                    nCustMenus[menuItemID].nMenuItemId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case PARENT_ITEM_ID_TYPE:
                    nCustMenus[menuItemID].nParentId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MENU_ITEM_ORDER_TYPE:
                    if ( /* nCustMenus[menuItemID].nNumofMenuItem==0 || */ i == MENU_ITEM_END)
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) 0;
                        fprintf(OutputMenutreeIDFile, "0,");
                        i = va_arg(argumentPtr, int);
                    }
                    else
                    {
                        U16 number_of_child = 0;

                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) malloc(sizeof(U16) * MENU_ITEM_SIZE);
                        while (i < MENU_ITEM_END)
                        {
                            nCustMenus[menuItemID].nOrderMenuItemId[number_of_child] = i;
                            i = va_arg(argumentPtr, int);

                            number_of_child++;
                        }
                        nCustMenus[menuItemID].nNumofMenuItem = number_of_child;        /* Set number of child field */
                        fprintf(OutputMenutreeIDFile, "%d,", number_of_child);
                        for (i = 0; i < number_of_child; i++)
                        {
                            fprintf(OutputMenutreeIDFile, "%d,", nCustMenus[menuItemID].nOrderMenuItemId[i]);
                        }
                        i = va_arg(argumentPtr, int);   /* read in next argument. */
                    }
                    break;

                case HIDE_FLAG_TYPE:
                    nCustMenus[menuItemID].nHideFlag = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MOVEABLE_FLAG_TYPE:
                    nCustMenus[menuItemID].nMovable = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case DISPLAY_ATTRIBUTE_TYPE:
                    nCustMenus[menuItemID].nDispAttribute = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MENU_ITEM_STRING_ID_TYPE:
                    nCustMenus[menuItemID].nStrId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MENU_ITEM_IMAGE_ID_TYPE:
                    nCustMenus[menuItemID].nImageId = i;
                    fprintf(OutputMenutreeIDFile, "%d));\n", i);
                    break;
            }
            if (MemberCounter != MENU_ITEM_ORDER_TYPE)
            {
                i = va_arg(argumentPtr, int);
            }

            if (MemberCounter == PARENT_ITEM_ID_TYPE)   /* Skip NUMBER_OF_MENUITEMS_TYPE field */
            {
                MemberCounter -= 2;
            }
            else
            {
                MemberCounter--;
            }
        }
    }
    else
    {
        is_dummy_code = 1;
    }

    va_end(argumentPtr);
}


/*****************************************************************************
 * FUNCTION
 *  Get_Image_Identifier
 * DESCRIPTION
 *  Identifies the image , BMP , ppf etc
 *  
 *  This function will be refined later when multiple
 *  image type will be supported by the frame work
 *  rt. now it just a added hook to make the design complete
 * PARAMETERS
 *  extension_type      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 Get_Image_Identifier(S32 extension_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (extension_type < 0)
    {
        ret = 0;
    }

    else if (extension_type == 0)
    {
        ret = 1;
    }

    return (U8) ret;

}


/*****************************************************************************
 * FUNCTION
 *  Load_Image_Data
 * DESCRIPTION
 *  Identifies the image , BMP , ppf etc
 * PARAMETERS
 *  output_file             [IN]        -> Name of the file to which buffer
 *  input_file              [IN]        ->  Name of the input image file
 *  image_identifier        [IN]        -> image identifier
 *  n_frames                [IN]        -> no of frames
 *  is(?)                   [IN]        To be written
 * RETURNS
 *  S32 --> file size
 *****************************************************************************/
static S32 Load_Image_Data(
        FILE *output_file,
        FILE *input_file,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size, i, o = 0;
    U8 ch;
    U32 width_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(n_frames==0)
    {
        n_frames = 1;
    }
    
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);
    
    if (image_identifier == IMAGE_TYPE_BMP ||
        image_identifier == IMAGE_TYPE_GIF ||
        image_identifier == IMAGE_TYPE_JPG ||
        image_identifier == IMAGE_TYPE_PNG)
    {
        if ((file_size >> 24) > 0)
        {
            printf("\nImage is too big.\n");
            return 0;
        }
    }

    if (toolFlag)
    {
        fprintf(dest_file, "%c%c", image_identifier, n_frames);
        if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
            image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_M3D ||
            image_identifier == IMAGE_TYPE_SWFLASH)
        {
            fprintf(
                dest_file,
                "%c%c%c%c%c%c",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (file_size & 0xff000000) >> 24,
                0,
                0);
        }
        else
        {
            fprintf(
                dest_file,
                "%c%c%c%c%c%c",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        }
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    else if (enfbFlag == 1) /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
    {
        fprintf(enfb_img_data_file, "%c%c", image_identifier, n_frames);
        if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
            image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_M3D ||
            image_identifier == IMAGE_TYPE_SWFLASH)
        {
            fprintf(
                enfb_img_data_file,
                "%c%c%c%c%c%c",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (file_size & 0xff000000) >> 24,
                0,
                0);
            enfb_size = 8 + file_size;
        }
        else
        {
            fprintf(
                enfb_img_data_file,
                "%c%c%c%c%c%c",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
            enfb_size = 8 + file_size;
        }
        
        /* write ENFB header to CustImgDataxxx.h */
        fprintf(
            output_file,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t",
            (U8) 255,                   //type
            (U8) ENFBAssociatedIDAdded, //associated id
            (U8) 0,                     //reserved
            (U8) 0,                     //reserved
            (U8) (enfb_offset & 0xff),
            (U8) ((enfb_offset >> 8) & 0xff),
            (U8) ((enfb_offset >> 16) & 0xff),
            (U8) ((enfb_offset >> 24) & 0xff),
            (U8) (enfb_size & 0xff),
            (U8) ((enfb_size >> 8) & 0xff),
            (U8) ((enfb_size >> 16) & 0xff),
            (U8) ((enfb_size >> 24) & 0xff));
        
        enfb_offset += enfb_size;
    }
#endif
    
    else
    {
        fprintf(output_file, "\n\t0x%02X, 0x%02X, ", image_identifier, n_frames);
        if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
            image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_M3D ||
            image_identifier == IMAGE_TYPE_SWFLASH)
        {
            fprintf(
                output_file,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x00, 0x00,\n\t",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (file_size & 0xff000000) >> 24);
        }
        else
        {
            fprintf(
                output_file,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        }
    }

    for (i = 0; i < file_size; i++)
    {
        ch = fgetc(input_file);

        if (toolFlag)
        {
            fputc(ch, dest_file);
        }
        
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        /* write image data to ENFB image data file */
        else if (enfbFlag == 1)
        {
            fputc(ch, enfb_img_data_file);
        }
    #endif
        
        else
        {
            fprintf(output_file, "0x%02X, ", ch);
            o++;
            if ((o % 16) == 0)
            {
                fprintf(output_file, "\n\t");
            }
        }
    }

    return file_size + 8;
}


/*****************************************************************************
 * FUNCTION
 *  Load_Audio_Data
 * DESCRIPTION
 *  load and write audio header and data
 * PARAMETERS
 *  output_file             [IN]        -> Name of the file to which buffer
 *  input_file              [IN]        ->  Name of the input audio file
 *  audio_identifier        [IN]        -> audio identifier
 *  is(?)                   [IN]        To be written
 * RETURNS
 *  S32 --> file size
 *****************************************************************************/
static S32 Load_Audio_Data(
        FILE *output_file, 
        FILE *input_file, 
        U8 audio_identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size, i, o = 0;
    U8 ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    if (toolFlag)
    {
        fprintf(
            dest_file,
            "%c%c%c%c%c%c%c%c",
            audio_identifier,
            file_size & 0xff,
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24,
            0,
            0,
            0);
    }
    else
    {
        fprintf(
            output_file,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x00, 0x00, 0x00,\n\t",
            audio_identifier,
            file_size & 0xff,
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24);
    }

    for (i = 0; i < file_size; i++)
    {
        ch = fgetc(input_file);

        if (toolFlag)
        {
            fputc(ch, dest_file);
        }
        else
        {
            fprintf(output_file, "0x%02X, ", ch);
            o++;
            if ((o % 16) == 0)
            {
                fprintf(output_file, "\n\t");
            }
        }
    }

    return file_size + 8;
}


/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image_Header
 * DESCRIPTION
 *  construct the header for sequential images
 * PARAMETERS
 *  output_file             [IN]        output file handle
 *  image_identifier        [IN]        sequential image type
 *  n_frames                [IN]        the number of the frames
 *  play_count              [IN]        number of playing times
 *  seq_filesize            [IN]        pointer to a list of file sizes
 *  seq_offset              [OUT]       pointer to a list of offsets
 *  width                   [IN]        maximun width
 *  height                  [IN]        maximun height
 * RETURNS
 *  void
 *****************************************************************************/
static void Write_Sequential_Image_Header(
        FILE *output_file,
        U8 image_identifier,
        S32 n_frames,
        U8 play_count,
        S32 *seq_filesize,
        S32 *seq_offset,
        U32 width,
        U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 offset = 8;
    S32 real_size;
    U32 width_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);
    
    if (toolFlag == 1)
    {
        /* the major header */
        fprintf(dest_file, "%c%c%c%c%c%c%c%c",
                image_identifier,
                n_frames,
                play_count,
                0, 0,    /* file size (not used) */
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            fprintf(dest_file, "%c%c%c%c", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);  /* the offset for each file */
            fprintf(dest_file, "%c%c%c%c", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);  /* the size for each file */
            fprintf(dest_file, "%c%c%c%c", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24);      /* the interval for each file */
            offset += real_size;
        }
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
    else if (enfbFlag == 1) 
    {
        S32 data_size = 0;
        for (i = 0; i < n_frames; i++)
        {
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            data_size += real_size;
        }
        enfb_size = 8 + 12*n_frames + data_size;
        
        /* write ENFB header to CustImgDataxxx.h */
        fprintf(
            output_file,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t",
            (U8) 255,                   //type
            (U8) ENFBAssociatedIDAdded, //associated id
            (U8) 0,                     //reserved
            (U8) 0,                     //reserved
            (U8) (enfb_offset & 0xff),
            (U8) ((enfb_offset >> 8) & 0xff),
            (U8) ((enfb_offset >> 16) & 0xff),
            (U8) ((enfb_offset >> 24) & 0xff),
            (U8) (enfb_size & 0xff),
            (U8) ((enfb_size >> 8) & 0xff),
            (U8) ((enfb_size >> 16) & 0xff),
            (U8) ((enfb_size >> 24) & 0xff));
        
        /* image header/data to ENFB image data file */
        /* the major header */
        fprintf(enfb_img_data_file, "%c%c%c%c%c%c%c%c",
                image_identifier,
                n_frames,
                play_count,
                0, 0,    /* file size (not used) */
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            fprintf(enfb_img_data_file, "%c%c%c%c", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);  /* the offset for each file */
            fprintf(enfb_img_data_file, "%c%c%c%c", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);  /* the size for each file */
            fprintf(enfb_img_data_file, "%c%c%c%c", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24);      /* the interval for each file */
            offset += real_size;
        }
        
        enfb_offset += enfb_size;
    }
#endif

    else
    {
        /* the major header */
        fprintf(output_file, "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
                image_identifier,
                n_frames,
                play_count,
                0, 0,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            fprintf(output_file, "0x%02X, 0x%02X, 0x%02X, 0x%02X, ", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);        /* the offset for each file */
            fprintf(output_file, "0x%02X, 0x%02X, 0x%02X, 0x%02X, ", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);        /* the size for each file */
            fprintf(output_file, "0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24); /* the interval for each file */
            offset += real_size;

            g_ressize += seq_filesize[i];
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image_File
 * DESCRIPTION
 *  write raw date from a frame of an image to the output file
 * PARAMETERS
 *  output_file     [IN]        output file handle
 *  input_file      [IN]        input file handle
 *  filesize        [IN]        the input file size
 * RETURNS
 *  void
 *****************************************************************************/
static void Write_Sequential_Image_File(
        FILE *output_file,
        FILE *input_file,
        S32 filesize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 o = 0;
    U8 ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (toolFlag == 1)
    {
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            fprintf(dest_file, "%c", ch);
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            /* for 4 byte alignment */
            fprintf(dest_file, "%c", 0);
        }
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
    else if (enfbFlag == 1) 
    {
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            fprintf(enfb_img_data_file, "%c", ch);
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            /* for 4 byte alignment */
            fprintf(enfb_img_data_file, "%c", 0);
        }
    }
#endif
    
    else
    {
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            fprintf(output_file, "0x%02X, ", ch);
            o++;
            if ((o % 16) == 0)
            {
                fprintf(output_file, "\n\t");
            }
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            /* for 4 byte alignment */
            fprintf(output_file, "0x00, ");
        }

        if ((o % 16) != 0)
        {
            fprintf(output_file, "\n\t");
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image
 * DESCRIPTION
 *  write sequential image
 * PARAMETERS
 *  pathname        [IN]        path name for sequential image
 *  pType           [OUT]       image type
 *  output_name     [IN]        output variable name
 *  output_file     [OUT]       output file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Write_Sequential_Image(
        char *pathname,
        U16 *pType,
        char *output_name,
        FILE *output_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sequential_filesize[MAX_SEQUENTIAL_IMAGE_FRAME];
    S32 sequential_offset[MAX_SEQUENTIAL_IMAGE_FRAME];
    S8 filename[BUFFER_SIZE];
    FILE *imgfp;
    S32 sequential_frame;
    S32 sequence_counter;
    S32 n_frames;
    S32 type = -1;
    U32 width = 0, height = 0;
    U32 seq_max_width = 0, seq_max_height = 0;
    S32 j;
    U8 play_count = 0;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the right extension file name */
#if defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__)
    for (j = SUPPORT_N_SEQUENTIAL_IMAGE_TYPE - 1; j >= 0; j--)  /* search from PNG */
#else
    for (j = 0; j < SUPPORT_N_SEQUENTIAL_IMAGE_TYPE; j++)       /* search from BMP */
#endif
    {
        sprintf(filename, "%s\\\\0.%s", pathname, sequential_image[j].filename_ext);
        imgfp = fopen(filename, "rb");
        if (imgfp != NULL)
        {
            *pType = (U16) sequential_image[j].file_type;
            type = j;
            MYFCLOSE(imgfp);
            break;
        }
    }
    if (type == -1)
    {
        return MMI_FALSE;
    }

    /* read during & find how many files are in sequence */
    sprintf(filename, "%s\\\\interval.txt", pathname);
    imgfp = fopen(filename, "r");
    if (imgfp == NULL)
    {
        printf("ERROR: Can't find %s\n", filename);
        return MMI_FALSE;
    }
    else
    {
        S32 count = 0;
        S32 duration;

        sequence_counter = 0;
        while(fscanf(imgfp, " %d", &duration) == 1)
        {
            sequential_interval[sequence_counter++] = duration;
        }

        /* we will recognize "LOOP " as prefix */
        play_count = (fscanf(imgfp, " LOOP %d", &count) == 1) ? ((U8)count) : (0);

        MYFCLOSE(imgfp);
    }
    
    for (j = 0; j < sequence_counter; j++)
    {
        sprintf(filename, "%s\\\\%d.%s", pathname, j, sequential_image[type].filename_ext);
        imgfp = fopen(filename, "rb");
        if (imgfp != NULL)
        {
#ifdef __MMI_ALPHA_BLENDING__
            /* If PNG, we will convert it to ABM */
            if (sequential_image[type].file_type == IMAGE_TYPE_ABM_SEQUENCE)
            {
                S8 tempBMPFile[BUFFER_SIZE];
                S8 tempCommand[SHELL_CMD_BUFLEN];
                U8 *buffer;
                S32 size, width, height;
                FILE *outfp = NULL;

                /* convert PNG to 32-bits BMP */
                strcpy((char*)tempBMPFile, (const char*)filename);
                ChangeExtension(tempBMPFile, RES_IMAGE, IMAGE_TYPE_BMP);
                sprintf(tempCommand, "convert.exe -channel Alpha -negate %s %s", filename, tempBMPFile);
                printf("%s\n", tempCommand);
                system(tempCommand);

                /* convert 32-bits BMP to ABM */
                buffer = (U8*)malloc(ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(U8));
                ABM_load(tempBMPFile,
                        __MMI_DEVICE_BMP_FORMAT__,
                        IMAGE_TYPE_PNG, /* non PBM */
                        buffer,
                        &size, &width, &height);

                sequential_filesize[j] = size;

                sprintf(tempBMPFile, "%s\\\\%d.abm", pathname, j);
                outfp = fopen(tempBMPFile, "wb+");
                if (outfp != NULL)
                {
                    S32 wsize;
                    
                    wsize = fwrite(buffer, sizeof(U8), size, outfp);
                    if (wsize != size)
                    {
                        printf("[ABM sequence] size not match:\t%s\n", tempBMPFile);
                    }
                    fclose(outfp);
                }

                free(buffer);
            }
            else
#endif /* __MMI_ALPHA_BLENDING__ */
            {
                fseek(imgfp, 0, SEEK_END);
                sequential_filesize[j] = ftell(imgfp);
                fseek(imgfp, 0, SEEK_SET);
            }

            MYFCLOSE(imgfp);
        }
        else
        {
            return MMI_FALSE;
        }
    }

    /* write each image raw data */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__                
    sprintf(filename, "%s\\\\0.%s", pathname, sequential_image[type].filename_ext);
    enfb_ret = Image_Test(filename, &enfb_width, &enfb_height);
    if (enfb_ret!= ENFB_IMAGE_NONE)
    {
        enfbFlag = 1;
        if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
        {
            ENFBAssociatedIDAdded = MMI_TRUE;
        }
    }
    //printf("sequential %s --> %d x %d\n", autofilename_buffer, enfb_width, enfb_height);
#endif

    sequential_frame = sequence_counter;

    /* construct the data structure name */
    if (output_file == NULL)
    {
        return MMI_FALSE;
    }
    fprintf(output_file, "__align(4) const U8 %s%s", output_name, OUTPUT_IMAGE_NAMES_END);

    /* get width and height */
    for (j = 0; j < sequence_counter; j++)
    {
        sprintf(filename, "%s\\\\%d.%s", pathname, j, sequential_image[type].filename_ext);
        imgfp = fopen(filename, "rb");
        if (imgfp != NULL)
        {
            MYFCLOSE(imgfp);
            n_frames = Image_Get_Dimensions(filename, &width, &height);
            if (n_frames < 1)
            {
                printf("Image get dimensions failed:\t%s\n", filename);
            }
            if (width > seq_max_width) 
            {
                seq_max_width = width;
            }
            if (height > seq_max_height)
            {
                seq_max_height = height;
            }
        }
        else
        {
            return MMI_FALSE;
        }
    }

    /* write header of sequential images */
    Write_Sequential_Image_Header(output_file, sequential_image[type].file_type, sequential_frame, play_count, sequential_filesize, sequential_offset, seq_max_width, seq_max_height);

    /* load all files in the sequence   */
    for (j = 0; j < sequence_counter; j++)
    {
#ifdef __MMI_ALPHA_BLENDING__
        if (sequential_image[type].file_type == IMAGE_TYPE_ABM_SEQUENCE)
        {
            sprintf(filename, "%s\\\\%d.abm", pathname, j);
        }
        else
#endif /* __MMI_ALPHA_BLENDING__ */
        {
            sprintf(filename, "%s\\\\%d.%s", pathname, j, sequential_image[type].filename_ext);
        }
        imgfp = fopen(filename, "rb");
        if (imgfp != NULL)
        {
            Write_Sequential_Image_File(output_file, imgfp, sequential_filesize[j]);
            MYFCLOSE(imgfp);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    fprintf(output_file, "\n};\n");

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfbFlag = 0;
#endif

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Write_Processed_Data
 * DESCRIPTION
 *  write processed data
 * PARAMETERS
 *  pathname        [IN]        path name for sequential image
 *  type            [IN]        image type
 *  output_name     [IN]        output variable name
 *  output_file     [OUT]       output file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Write_Processed_Data(
        char *filename,
        U8 type,
        char *output_name,
        FILE *output_file)
{
    FILE *imgfp;
    int ret;
    S8 tempDestFile[] = "TEMPIMAGE";

    imgfp = fopen(filename, "rb");
    if (imgfp != NULL)
    {
        MYFCLOSE(imgfp);
        switch (type)
        {
            case IMAGE_TYPE_GIF:
                GIFLoader(filename, tempDestFile);
                break;

            case IMAGE_TYPE_DEVICE_BITMAP:
                ret = BMPLoader(filename, tempDestFile, __MMI_DEVICE_BMP_FORMAT__);
                if (toolFlag)
                {
                    if (ret == 0)
                    {
                        resultFailFlag = 1;
                    }
                }
                break;

            case IMAGE_TYPE_ABM:
                ret = ABMLoader(filename, tempDestFile);
                if (ret != ABM_ENC_RETURN_USE_ABM)
                {
                    if (toolFlag)
                    {
                        resultFailFlag = 1;
                    }
                    return MMI_FALSE;
                }
                break;

            default:
                return MMI_FALSE;
        }

        if (toolFlag == 0)
        {
            FILE *fp;

            fp = fopen(tempDestFile, "rb");
            if (fp != NULL)
            {
                fprintf(output_file, "__align(4) const U8 %s[] =\n", output_name);
                if (ExtImageFlag == NFB_PROGRESS_IMAGE)
                {
                    if (nfb_img_res_file != NULL)
                    {
                        fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_name);
                    }
                    else
                    {
                        printf("nfb_img_res_file not opened\n");
                    }
                }

                if (output_file != NULL)
                {
                    while (!feof(fp))
                    {
                        S8 buffer[200];
                        size_t size;

                        size = fread(buffer, 1, 200, fp);
                        if (size)
                        {
                            fwrite(buffer, 1, size, output_file);
                        }
                    }
                    fputs("\n", output_file);
                }

                MYFCLOSE(fp);
            }
        }
    }
    else
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Write_Unprocessed_Data
 * DESCRIPTION
 *  write unprocessed data
 * PARAMETERS
 *  pathname        [IN]        path name for sequential image
 *  pType           [OUT]       image type
 *  output_name     [IN]        output variable name
 *  output_file     [OUT]       output file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Write_Unprocessed_Data(
        char *filename,
        FILE *image_file,
        S32 nImageSize,
        U16 *pType,
        char *output_name,
        FILE *output_file)
{
    U8 image_identifier;
    MMI_BOOL failure_flag = MMI_TRUE;
    S32 n_frames = 0;
    U32 width = 0, height = 0;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif

    /* Currently assuming that all single files are BMP */
    if (nImageSize == 0)
    {
        image_identifier = IMAGE_TYPE_INVALID;
    }
    else
    {
        /* for read images with same filename but different in ".bmp" and ".gif" */
        image_identifier = ExtractExtension(filename, RES_IMAGE);
    }
    /* To be changed later for multiple file types */
    *pType = ExtractExtension(filename, RES_IMAGE);

#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
    if (image_identifier == IMAGE_TYPE_GIF ||
        image_identifier == IMAGE_TYPE_JPG)
    {
        FILE *fp;

        fp = fopen(filename, "rb");
        if (fp != NULL)
        {
            S32 fs;

            fseek(fp, 0, SEEK_END);
            fs = ftell(fp);
            MYFCLOSE(fp);

            if ((fs + 8/* header */) > GDI_IMAGE_SINGLE_BANK_CACHE_SIZE)
            {
                fprintf(stderr, "[Single Bank]:\timage oversize,\t%s\n", filename_buffer);
                failure_flag = MMI_FALSE;
                exit(1);
            }
        }
        else
        {
            failure_flag = MMI_FALSE;
        }
    }
#endif

    if (failure_flag == MMI_TRUE)
    {
        /* get frame count, width and height of the image */
        if (image_identifier == IMAGE_TYPE_BMP ||
            image_identifier == IMAGE_TYPE_GIF ||
            image_identifier == IMAGE_TYPE_JPG ||
            image_identifier == IMAGE_TYPE_PNG)
        {
            n_frames = Image_Get_Dimensions(filename, &width, &height);
            if (n_frames <= 0)
            {
                printf("\nGet dimensions failed:\t%s", filename_buffer);
                failure_flag = MMI_FALSE;
            }
        }
    }

    if (failure_flag == MMI_TRUE)
    {
        /* load the data */
        /* construct the data structure name */
        if (image_identifier == IMAGE_TYPE_GIF || image_identifier == IMAGE_TYPE_3GP ||
            image_identifier == IMAGE_TYPE_MP4 || image_identifier == IMAGE_TYPE_AVI ||
            image_identifier == IMAGE_TYPE_PNG || image_identifier == IMAGE_TYPE_M3D ||
            image_identifier == IMAGE_TYPE_SWFLASH)
        {
            fprintf(output_file, "__align(4) ");
        }
        fprintf(output_file, "const U8 %s%s", output_name, OUTPUT_IMAGE_NAMES_END);

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfb_ret = Image_Test(filename_buffer, &enfb_width, &enfb_height);
        if (enfb_ret != ENFB_IMAGE_NONE)
        {
            enfbFlag = 1;
            if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
            {
                ENFBAssociatedIDAdded = MMI_TRUE;
            }
        }
#endif

        g_ressize = Load_Image_Data(output_file, image_file, image_identifier, n_frames, width, height);
        if (g_ressize == 0)
        {
            failure_flag = MMI_FALSE;
        }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfbFlag = 0;
#endif

        if (ExtImageFlag == NFB_PROGRESS_IMAGE)
        {
            printf("NFB_PROGRESS_IMAGE\n");
            if (nfb_img_res_file != NULL)
            {
                fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_image_names);
            }
            else
            {
                printf("nfb_img_res_file not opened\n");
            }
        }

        fprintf(output_file, "\n };\n");
    }

    return failure_flag;
}


/*****************************************************************************
 * FUNCTION
 *  Extract_Name
 * DESCRIPTION
 *  Exract image name from the supplied string
 * PARAMETERS
 *  dest            [OUT]       -> Extrected file name from string
 *  src             [IN]        -> string containing file name and path
 *  res_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Extract_Name(S8 *dest, S8 *src, U32 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 iLen = strlen(src);
    U16 nCount = 0;

    S8 *pSrc = src;
    char a, b;
    S8 *pCustPath;
    U32 ExtFlag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            pCustPath = CustImgPath;
            ExtFlag = ExtImageFlag;
            break;

        case RES_AUDIO:
            pCustPath = CustAdoPath;
            ExtFlag = ExtAudioFlag;
            break;

        default:
            printf("res_type in Extract_Name is invalid!!");
            pCustPath = CustImgPath;
            ExtFlag = ExtImageFlag;
            break;
    }

    iLen = strlen(pCustPath);

    for (nCount = 0; nCount < iLen; nCount++)
    {
        a = toupper(pCustPath[nCount]);
        b = toupper(src[nCount]);
        if (a != b)
        {
            break;
        }
    }
    if (iLen == nCount)
    {
        pSrc = &src[iLen];
    }

    iLen = strlen(pSrc);
    nCount = 0;

    while (iLen)
    {
        if ((pSrc[nCount] == '.') || (pSrc[nCount] == '-') || (pSrc[nCount] == ' ') || (pSrc[nCount] == '\\'))
        {
            dest[nCount] = '_';
        }
        else
        {
            dest[nCount] = pSrc[nCount];
        }

        ++nCount;
        --iLen;
    }

    /* __CUSTPACK_MULTIBIN Calvin BEGIN */
    if (ExtFlag == 1)   /* 040805 CustPack: Calvin added */
    {
        dest[nCount] = '_'; /* add a '_' in the end to distinguish from the original */
        dest[nCount + 1] = '\0';
    }
    /* __CUSTPACK_MULTIBIN Calvin END */
    else
    {
        dest[nCount] = '\0';
    }
    return;
}

/* 101205 audio resource Calvin End */

/* 101205 audio resource Calvin Satrt */


/* 070306 Alpha layer Start */
/*****************************************************************************
 * FUNCTION
 *  ExtractExtension
 * DESCRIPTION
 *  Function Extracting the extension
 * PARAMETERS
 *  src             [?]         
 *  res_type        [IN]        -> resource type
 *  string(?)       [IN]        -> string containing file name
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 ExtractExtension(S8 *src, U32 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 type_number;
    U8 ret = 0;
    S8 *arr;
    RESOURCE_INFO *pResource_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = strlen(src) - 1;
    arr = src+i;

    for (j = 0; j < 5 ; j--)
    {
        if(*arr == '.')
        {
            arr++;
            break;
        }
        else
    {
            arr--;
        }
    }

    if(j >= 5)
    {
        return ret;
    }

    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;

        case RES_AUDIO:
            ret = AUDIO_TYPE_INVALID;
            pResource_info = audio_resource_info;
            type_number = sizeof(audio_resource_info) / sizeof(RESOURCE_INFO);
            break;

        default:
            printf("res_type in Extract_Name is invalid!!");
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;
    }

    for (i = 0; i < type_number; i++)
    {
        if (!(strcmp(arr, pResource_info[i].filename_ext)))
        {
            ret = pResource_info[i].file_type;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ChangeExtension
 * DESCRIPTION
 *  Function Change the extension
 * PARAMETERS
 *  src             [IN]        -> string containing file name 
 *  res_type        [IN]        -> resource type
 *  ext_type        [IN]        -> extension type
 * RETURNS
 *  BOOL
 *****************************************************************************/
static BOOL ChangeExtension(S8 *src, U32 res_type, S32 ext_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 type_number;
    U8 ret = 0;
    S8 *arr;
    RESOURCE_INFO *pResource_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = strlen(src) - 1;
    arr = src+i;

    for (j = 0; j < 5 ; j--)
    {
        if(*arr == '.')
        {
            arr++;
            break;
        }
        else
        {
            arr--;
        }
    }

    if (j >= 5)
    {
        return FALSE;
    }

    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;

        case RES_AUDIO:
            ret = AUDIO_TYPE_INVALID;
            pResource_info = audio_resource_info;
            type_number = sizeof(audio_resource_info) / sizeof(RESOURCE_INFO);
            break;

        default:
            printf("res_type in Extract_Name is invalid!!");
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;
    }

    for (i = 0; i < type_number; i++)
    {
        if (pResource_info[i].file_type == ext_type)
        {
            break;
        }
    }

    if (i >= type_number)
    {
        return FALSE;
    }

    for (j = 0; j < 5; j++)
    {
        *(arr+j) = *(pResource_info[i].filename_ext+j);
    }

    return TRUE;
}
/* 070306 Alpha layer End */


/*****************************************************************************
 * FUNCTION
 *  isEmsImage
 * DESCRIPTION
 *  Decide if the iamge is used for EMS picture
 *  
 *  use EMS_IMAGE_PATH (defined in CustDataRes.h) to decide if a EMS picture
 * PARAMETERS
 *  path        [IN]        -> string containing file name and path
 * RETURNS
 *  U8 --> 1: EMS picture, 0: Not EMS picture
 *****************************************************************************/
static U8 isEmsImage(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ems_path[] = EMS_IMAGE_PATH;
    U8 pos = 0, ems_len = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ems_len = strlen(ems_path);
    pos = strlen(path) - 1;
    while (path[pos] != '\\')
    {
        /* __CUSTPACK_MULTIBIN Calvin BEGIN */
        if (pos == 0)   /* 040805 CustPack: Calvin added */
        {
            return 0;
        }
        /* __CUSTPACK_MULTIBIN Calvin END */
        pos--;
    }
    pos -= ems_len + 1;
    for (i = 0; i < ems_len; i++)
    {
        if (ems_path[i] != path[pos])
        {
            return 0;
        }
        else
        {
            pos++;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  isMainmenuImage
 * DESCRIPTION
 *  Decide if the iamge is used for Mainmenu picture
 * PARAMETERS
 *  path        [IN]        -> string containing file name and path
 * RETURNS
 *  U8 --> 1: Matrix Mainmenu picture, 0: Not Matrix mainmenu picture
 *****************************************************************************/
static MMI_BOOL isMainmenuImage(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((strstr(path, "\\MATRIX\\") != NULL) && (strstr(path, ".GIF") != NULL))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  isSubmenuImage
 * DESCRIPTION
 *  Decide if the iamge is used for Submenu picture
 *  
 *  use SUBMENU_IMAGE_PATH (defined in CustDataRes.h) to decide if a EMS picture
 * PARAMETERS
 *  path        [IN]        -> string containing file name and path
 * RETURNS
 *  U8 --> 1: Submenu picture, 0: Not Submenu picture
 *****************************************************************************/
static U8 isSubmenuImage(S8 *path)
{
#ifndef __MMI_SLIM_LISTMENU_NUMBER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
#else /* __MMI_SLIM_LISTMENU_NUMBER__ */ 
    S8 submenu_path[] = SUBMENU_IMAGE_PATH;
    U8 pos = 0, submenu_len = 0, i = 0;

    if (strstr(path, submenu_path) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    /*
     * submenu_len = strlen(submenu_path);
     * pos = strlen (path)-1;
     * while (path[pos]!='\\') pos--;
     * pos-=submenu_len+1;
     * for ( i=0; i<submenu_len; i++){
     * if ( submenu_path[i] != path[pos] ) return 0;
     * else pos++;
     * }
     * return 1;
     */
#endif /* __MMI_SLIM_LISTMENU_NUMBER__ */ 
}

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
/* 040805 CustPack: Calvin added */


/*****************************************************************************
 * FUNCTION
 *  ToUpper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 ToUpper(S8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return toupper(ch);
}

/* Calvin end */
/* __CUSTPACK_MULTIBIN Calvin END */


/*****************************************************************************
 * FUNCTION
 *  Iload
 * DESCRIPTION
 *  load the file image to buffer and writes to CustImgRes.c, etc.
 * PARAMETERS
 *  string      [IN]        string containing file name and path
 *  pType       [OUT]       image type
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL Iload(S8 *string, PU16 pType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *image_data_file = NULL;
    FILE *output_data_file = NULL;
    char *curr_output_data_filename;
    S8 autofilename_buffer[BUFFER_SIZE];
    S8 tempBMPFile[BUFFER_SIZE];
    S32 j;
    MMI_BOOL failure_flag;
    S32 nImageSize = 0;
    U8 staticFlag = 1;  /* Non animated image */
    S32 ext_type = -1;
    int ret = 1;
    S16 filenameLen;
    S8 tempCommand[SHELL_CMD_BUFLEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset g_ressize, size of the resource for usage manitor */
    g_ressize = 0;

    /* decide output file by mode: CustPack, system, and NFB */
    if (ExtImageFlag == EXT_IMAGE)
    {
        curr_output_data_filename = OUTPUT_DATA_FILENAME_EXT;
    }
    else if (ExtImageFlag == SYSTEM_IMAGE)
    {
        curr_output_data_filename = OUTPUT_DATA_FILENAME;
    }
    else
    {
        curr_output_data_filename = NFB_IMAGE_DATA_FILENAME;
        nfb_img_res_file = fopen(NFB_IMAGE_RES_FILENAME, "ab");
    }

    if (toolFlag == 1)
    {
        curr_output_data_filename = "temp";
    }

    strcpy(filename_buffer, curr_output_data_filename);

    /* open output file */
    output_data_file = fopen(filename_buffer, "ab");
    while (output_data_file == NULL)
    {
        Sleep(50);
        output_data_file = fopen(filename_buffer, "ab");
    }

    /* set output variable name of the resource */
    output_image_names = (S8*) malloc(MAX_FILENAME_LEN);
    strcpy(filename_buffer, string);
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);
    }
    Extract_Name(output_image_names, filename_buffer, RES_IMAGE);

#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    /* set sub-menu list icon image to default 1, 2, 3, ... */
    if (isSubmenuImage(filename_buffer))
    {
        int i, len;

        len = strlen(filename_buffer);

        for (i = len; i > 0; i--)
        {
            if (filename_buffer[i - 0] == 'U' && filename_buffer[i - 1] == 'N' && filename_buffer[i - 2] == 'E' &&
                filename_buffer[i - 3] == 'M' && filename_buffer[i - 4] == 'B' && filename_buffer[i - 5] == 'U' &&
                filename_buffer[i - 6] == 'S')
            {
                filename_buffer[i + 1] = '2';
                break;
            }
            else
            {
                filename_buffer[i + 1] = filename_buffer[i];
            }

        }
        filename_buffer[len + 1] = '\0';
    }
#endif /* __MMI_SLIM_LISTMENU_NUMBER__ */ 

    failure_flag = MMI_FALSE;

    /* For 128x128, it does not support ABM.
     * In order not to modify res_xxx.c, we have to
     * find the correct filename automatically */
    /* This rule, renaming PNG -> other format, will apply for all */
    if (file_exist(filename_buffer) == MMI_FALSE)
    {
        ext_type = ExtractExtension(filename_buffer, RES_IMAGE);
        if (ext_type == IMAGE_TYPE_PNG)
        {
            S32 i, count;

            count = sizeof(image_resource_info)/sizeof(RESOURCE_INFO);
            for (i = 0; i < count; i++)
            {
                ChangeExtension(filename_buffer, RES_IMAGE, image_resource_info[i].file_type);
                if (file_exist(filename_buffer) == MMI_TRUE)
                {
                    break;
                }
            }
            if (i == count)
            {
                ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PNG);
                printf("[ABM] %s\tcannot open file for all supported formats!!!\n", filename_buffer);
            }
        }
    }

    /* ABM encoding */
    if ((failure_flag == MMI_FALSE) &&
        !isEmsImage(filename_buffer))
    {
        ext_type = ExtractExtension(filename_buffer, RES_IMAGE);

#ifdef __MMI_ALPHA_BLENDING__        
        /* If PNG, we will convert it to ABM conditionally */
        if (ext_type == IMAGE_TYPE_PNG)
        {
            /* convert PNG to 32-bits BMP */
            strcpy((char*)tempBMPFile, (const char*)filename_buffer);
            ChangeExtension(tempBMPFile, RES_IMAGE, IMAGE_TYPE_BMP);
            strcat(tempBMPFile, "A");
            sprintf(tempCommand, "convert.exe -channel Alpha -negate png:%s bmp:%s", filename_buffer, tempBMPFile);
            printf("%s\n", tempCommand);
            system(tempCommand);

            /* convert 32-bits BMP to ABM */
            failure_flag = Write_Processed_Data(tempBMPFile, IMAGE_TYPE_ABM, output_image_names, output_data_file);
        }
        else
#endif /* __MMI_ALPHA_BLENDING__ */

        /* If BMP/PBM, we will convert it to ABM conditionally */
        if ((ext_type == IMAGE_TYPE_BMP) ||
            (ext_type == IMAGE_TYPE_DEVICE_BITMAP))
        {
            failure_flag = Write_Processed_Data(filename_buffer, IMAGE_TYPE_ABM, output_image_names, output_data_file);
        }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        /* all of the resource above may not be converted to ABM certainly 
         * if not, it will be populated as usual */
    }

    if (failure_flag == MMI_FALSE)
    {
#ifdef __MMI_ALPHA_LAYER_SUPPORT__
        /* fetch PNG by GIF or BMP,
         * application can add PNG file directly without modifying Res_XXX.c */
        ext_type = ExtractExtension(filename_buffer, RES_IMAGE);
        if (ext_type == IMAGE_TYPE_GIF || ext_type == IMAGE_TYPE_BMP)
        {
            ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PNG);
        }
        /* fetch PPN by PBM */
        else if (ext_type == IMAGE_TYPE_DEVICE_BITMAP)
        {
            ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PPN);
        }

        image_data_file = fopen(filename_buffer, "rb");
        if (image_data_file == NULL)
        {
            ChangeExtension(filename_buffer, RES_IMAGE, ext_type);
        }
        else
        {
            MYFCLOSE(image_data_file);
        }
#endif

        /* convert PPN to PBM */
        ext_type = ExtractExtension(filename_buffer, RES_IMAGE);
        if (ext_type == IMAGE_TYPE_PPN)
        {
            strcpy((char*)tempBMPFile, (const char*)filename_buffer);
            ChangeExtension(tempBMPFile, RES_IMAGE, IMAGE_TYPE_DEVICE_BITMAP);
            sprintf(tempCommand,"convert.exe png:%s bmp:%s", filename_buffer, tempBMPFile);
            system(tempCommand);
            strcpy((char*)filename_buffer, (const char*)tempBMPFile);
        }

        filenameLen = strlen(filename_buffer);

        /* process EMS image */
        if (isEmsImage(filename_buffer))
        {
            image_data_file = fopen(filename_buffer, "rb");
            if (image_data_file != NULL)
            {
                MYFCLOSE(image_data_file);

                if (toolFlag == 0)
                {
                    if (output_data_file != NULL)
                    {
                        fprintf(output_data_file, "const U8 %s[] = ", output_image_names);
                        MYFCLOSE(output_data_file);
                    }
                }
                ret = bmp2ems(filename_buffer, curr_output_data_filename, 1, 0);
                if (toolFlag)
                {
                    if (ret == 0)
                    {
                        resultFailFlag = 1;
                    }
                }

                failure_flag = MMI_TRUE;
            }
            else
            {
                failure_flag = MMI_FALSE;
            }
        }
        /* process PRP */
        else if ((filename_buffer[filenameLen - 1] == 'P') &&
                 (filename_buffer[filenameLen - 2] == 'R') &&
                 (filename_buffer[filenameLen - 3] == 'P'))
        {
            failure_flag = Write_Processed_Data(filename_buffer, IMAGE_TYPE_GIF, output_image_names, output_data_file);
        }
        /* process PBM */
        else if ((filename_buffer[filenameLen - 1] == 'M') &&
                 (filename_buffer[filenameLen - 2] == 'B') &&
                 (filename_buffer[filenameLen - 3] == 'P'))
        {
            failure_flag = Write_Processed_Data(filename_buffer, IMAGE_TYPE_DEVICE_BITMAP, output_image_names, output_data_file);
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        else
        {
            image_data_file = fopen(filename_buffer, "rb");
            /* MTK Leo add, for read images with same filename but different in ".bmp" and ".gif" */
            if (image_data_file == NULL)
            {
                if (filename_buffer[filenameLen - 1] == 'P' &&
                    filename_buffer[filenameLen - 2] == 'M' &&
                    filename_buffer[filenameLen - 3] == 'B')
                {
                    filename_buffer[filenameLen - 1] = 'F';
                    filename_buffer[filenameLen - 2] = 'I';
                    filename_buffer[filenameLen - 3] = 'G';
                }
                else if (filename_buffer[filenameLen - 1] == 'F' &&
                         filename_buffer[filenameLen - 2] == 'I' &&
                         filename_buffer[filenameLen - 3] == 'G')
                {
                    filename_buffer[filenameLen - 1] = 'P';
                    filename_buffer[filenameLen - 2] = 'M';
                    filename_buffer[filenameLen - 3] = 'B';
                }

                image_data_file = fopen(filename_buffer, "rb");
            }

            if (image_data_file == NULL)
            {
                FILE *fail = fopen("fail.txt", "a+");

                if (fail != NULL)
                {
                    if (toolFlag == 0)
                    {
                        fprintf(fail, "%s\n", filename_buffer);
                        MYFCLOSE(fail);
                    }
                }

                failure_flag = Write_Sequential_Image(filename_buffer, pType, output_image_names, output_data_file);
                if (failure_flag == MMI_TRUE)
                {
                    staticFlag = 0;
                }
            }
            else
            {
                MYFCLOSE(image_data_file);
            }

            /* process static image */
            if ((failure_flag == MMI_FALSE) && (staticFlag))
            {
                image_data_file = fopen(filename_buffer, "rb");

                if (image_data_file != NULL)
                {
                    /* patch added by vikram for getting image file size */
                    fseek(image_data_file, 0, SEEK_END);
                    nImageSize = ftell(image_data_file);
                    fseek(image_data_file, 0, SEEK_SET);

                    failure_flag = Write_Unprocessed_Data(
                            filename_buffer,
                            image_data_file,
                            nImageSize,
                            pType,
                            output_image_names,
                            output_data_file);

                    MYFCLOSE(image_data_file);
                }
            }
        }
    }

    /* 120704 Calvin added for populating with .bmp or .gif but actually extsion name is not */
    if (failure_flag == MMI_FALSE)
    {
        /* printf("*************failed !!!********************\n"); */
        /* try each supported extension */
        for (j = 0; j < SUPPORT_N_MEDIA_TYPE; j++)
        {
            S32 l;

            for (l = 0; l < 3; l++)
            {
                filename_buffer[filenameLen - 1 - l] = support_media_ext[j][2 - l];
            }

            image_data_file = fopen(filename_buffer, "rb");
            if (image_data_file != NULL)
            {
                break;
            }
        }

        if (image_data_file != NULL)
        {
            failure_flag = MMI_TRUE;

            fseek(image_data_file, 0, SEEK_END);
            nImageSize = ftell(image_data_file);
            fseek(image_data_file, 0, SEEK_SET);

            failure_flag = Write_Unprocessed_Data(
                    filename_buffer,
                    image_data_file,
                    nImageSize,
                    pType,
                    output_image_names,
                    output_data_file);

            MYFCLOSE(image_data_file);
        }
    }

    MYFCLOSE(image_data_file);
    MYFCLOSE(output_data_file);
    MYFCLOSE(nfb_img_res_file);
    free(output_image_names);

    return failure_flag;
}


/*****************************************************************************
 * FUNCTION
 *  Aload
 * DESCRIPTION
 *  Load the file audio to buffer and writes to CustAdoRes.c
 * PARAMETERS
 *  string      [IN]        -> audio resource filename
 *  pType       [OUT]       -> type
 * RETURNS
 *  void* --> buffer containing Audio data
 *****************************************************************************/
MMI_BOOL Aload(S8 *string, PU16 pType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *audio_data_file = NULL;
    MMI_BOOL failure_flag;
    U8 audio_identifier;
    S32 nAudioSize = 0;
    S16 filenameLen;
    char *curr_output_data_filename;
    FILE *output_data_file = NULL;
    S8 *output_audio_names = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ressize = 0;

    if (ExtAudioFlag == TRUE)
    {
        curr_output_data_filename = AUDIO_OUTPUT_DATA_FILENAME_EXT;
    }
    else
    {
        curr_output_data_filename = AUDIO_OUTPUT_DATA_FILENAME;
    }

    if (toolFlag == 1)
    {
        curr_output_data_filename = "temp";
    }

    strcpy(filename_buffer, curr_output_data_filename);

    output_data_file = fopen(filename_buffer, "ab");
    while (output_data_file == NULL)
    {
        Sleep(50);
        output_data_file = fopen(filename_buffer, "ab");
    }

    output_audio_names = (S8*) malloc(MAX_FILENAME_LEN);
    strcpy(filename_buffer, string);
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOAUDIO_FILENAMEBUFFER);
    }

    Extract_Name(output_audio_names, filename_buffer, RES_AUDIO);

    failure_flag = MMI_FALSE;
    filenameLen = strlen(filename_buffer);

    if (failure_flag == MMI_FALSE)
    {
        audio_data_file = fopen(filename_buffer, "rb");
        if (audio_data_file == NULL)
        {
            /* Add extension add search */
            FILE *fail = fopen("fail.txt", "a+");

            if (fail != NULL)
            {
                if (toolFlag == 0)
                {
                    fprintf(fail, "%s\n", filename_buffer);
                    MYFCLOSE(fail);
                }
            }

            failure_flag = MMI_FALSE;
        }
        else
        {
            failure_flag = MMI_TRUE;
            fseek(audio_data_file, 0, SEEK_END);
            nAudioSize = ftell(audio_data_file);
            fseek(audio_data_file, 0, SEEK_SET);
        }

        if (failure_flag == MMI_TRUE)
        {
            if (nAudioSize == 0)
            {
                audio_identifier = AUDIO_TYPE_INVALID;
            }
            else
            {
                audio_identifier = ExtractExtension(filename_buffer, RES_AUDIO);
            }
            /* To be changed later for multiple file types */
            *pType = ExtractExtension(filename_buffer, RES_AUDIO);      /* 101205 audio resource Calvin */

            /*   Load the data  */

            /* Construct the data structure name */
            fprintf(output_data_file, "__align(4) const U8 %s%s", output_audio_names, OUTPUT_AUDIO_NAMES_END);

            g_ressize = Load_Audio_Data(output_data_file, audio_data_file, audio_identifier);

            fprintf(output_data_file, "\n };\n");
        }
    }

    MYFCLOSE(audio_data_file);
    MYFCLOSE(output_data_file);
    free(output_audio_names);

    return failure_flag;
}

/* 101205 audio resource Calvin End */


/*****************************************************************************
 * FUNCTION
 *  ClearHWIMageFile
 * DESCRIPTION
 *  Clear image file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHWIMageFile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(OUTPUT_DATA_FILENAME, "w+");
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }

    /* __CUSTPACK_MULTIBIN Calvin BEGIN */
    fp = fopen(OUTPUT_DATA_FILENAME_EXT, "w+"); /* 040805 CustPack: Calvin added */
    /* __CUSTPACK_MULTIBIN Calvin END */
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }

    /* 101205 audio resource Calvin Satrt */
    fp = fopen(AUDIO_OUTPUT_DATA_FILENAME, "w+");
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }

    fp = fopen(AUDIO_OUTPUT_DATA_FILENAME_EXT, "w+");
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }
    /* 101205 audio resource Calvin End */
    
    /* 100206 ENFB support Satrt */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfb_img_data_file = fopen(ENFB_IMAGE_DATA_FILENAME, "w+");
    
    if (enfb_img_data_file)
    {
        fclose(enfb_img_data_file);
    }
    enfb_img_data_file = fopen(ENFB_IMAGE_DATA_FILENAME, "ab");
#endif
    /* 100206 ENFB support End */
}
#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

#if defined(CUSTOMIZATION_BUILD_FIRST_PASS) || defined(CUSTOMIZATION_BUILD_SECOND_PASS)
CURR_SCREEN_RESOURCE gsCurrScreenInfo;
extern CUSTOM_MENU nCustMenus[MAX_MENU_ITEMS];
extern U16 CurrMaxMenuItemIndex;


/*****************************************************************************
 * FUNCTION
 *  SetCurrentScreenStrings
 * DESCRIPTION
 *  SEt the current screen strings
 * PARAMETERS
 *  nNum        [IN]        ..
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentScreenStrings(U16 nNum, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nId;
    U16 nCount = 0;
    va_list vlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(vlist, nNum);

    gsCurrScreenInfo.nNoOfStrings = nNum;

    while (nNum > nCount)
    {
        nId = va_arg(vlist, U16);
        gsCurrScreenInfo.nStringIdList[nCount] = nId;
        ++nCount;
    }
    va_end(vlist);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentScreenImages
 * DESCRIPTION
 *  SEt the current screen images
 * PARAMETERS
 *  nNum        [IN]        ..
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentScreenImages(U16 nNum, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nId;
    U16 nCount = 0;
    va_list vlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(vlist, nNum);

    gsCurrScreenInfo.nNoOfImages = nNum;

    while (nNum > nCount)
    {
        nId = va_arg(vlist, U16);
        gsCurrScreenInfo.nImageIdList[nCount] = nId;
        ++nCount;
    }
    va_end(vlist);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  AppendCurrentScreenImages
 * DESCRIPTION
 *  SEt the current screen images
 * PARAMETERS
 *  nNum        [IN]        
 *  pList       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AppendCurrentScreenImages(int nNum, U16 *pList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount = 0;
    U16 i = 0;
    U8 flag = 0;
    U16 nOrgCount = gsCurrScreenInfo.nNoOfImages;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gsCurrScreenInfo.nNoOfImages = nNum + gsCurrScreenInfo.nNoOfImages;

    while (nNum > nCount)
    {
        flag = 0;
        //for(i = nOrgCount+1;i<(nOrgCount+nCount ) ;i++)
        //for(i = (nOrgCount+nCount);i>0 ;i--)
        for (i = 0; i < nCount; i++)
        {
            if (gsCurrScreenInfo.nImageIdList[i + nOrgCount] == pList[nCount])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            gsCurrScreenInfo.nImageIdList[nOrgCount + nCount] = pList[nCount];
        }

        ++nCount;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  AppendCurrentScreenStrings
 * DESCRIPTION
 *  SEt the current screen images
 * PARAMETERS
 *  nNum        [IN]        
 *  pList       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AppendCurrentScreenStrings(int nNum, U16 *pList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount = 0;
    U16 nOrgCount = gsCurrScreenInfo.nNoOfStrings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gsCurrScreenInfo.nNoOfStrings = nNum + gsCurrScreenInfo.nNoOfStrings;

    while (nNum > nCount)
    {
        gsCurrScreenInfo.nStringIdList[nOrgCount + nCount] = pList[nCount];
        ++nCount;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentScreenMenus
 * DESCRIPTION
 *  SEt the current screen menus
 * PARAMETERS
 *  nNum        [IN]        ..
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentScreenMenus(U16 nNum, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nId;
    U16 nCount = 0;
    U16 nParentIdCount = 0;
    va_list vlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(vlist, nNum);

    gsCurrScreenInfo.nNoOfMenus = nNum;

    while (nNum > nCount)
    {
        nId = va_arg(vlist, U16);
        gsCurrScreenInfo.sMenuInfo[nCount].nId = nId;
        nParentIdCount = 0;
        while (nParentIdCount > CurrMaxMenuItemIndex)
        {
            if (nCustMenus[nParentIdCount].nMenuItemId == nId)
            {
                gsCurrScreenInfo.sMenuInfo[nCount].nParentId = nCustMenus[nParentIdCount].nParentId;
                break;
            }
            ++nParentIdCount;
        }
        ++nCount;
    }
    va_end(vlist);
    return;
}

#endif /* defined(CUSTOMIZATION_BUILD_FIRST_PASS) || defined(CUSTOMIZATION_BUILD_SECOND_PASS) */ 

