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
 *   wgui_touch_screen.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui-level functions for touch screen.
 *
 * 
 *
 * Author:
 * -------
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
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   FILENAME : ReadRes.c

   PURPOSE     : Helper Functions   to Read/Get the Customizable Resources like Strings,Images,MenuItems..etc. 

   REMARKS     : nil

   AUTHOR      : Subramanya BG   

   DATE     : 20thSept 2002.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
**********************************************************************************/
/*  Include: MMI header file */
#include "string.h"
#include "GlobalMenuItems.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "gui_themes.h"
#include "FontDcl.h"
#include "gui.h"
#include "wgui.h"
#include "DownloadProtos.h"
#include "MMI_features.h"
#include "wgui_categories_res.h"

#ifdef __MMI_THEMES_V2_SUPPORT__
#include "ThemeManager.h"
#include "MMIThemes.h"
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

/* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#include "ResMemMgrGprot.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
/* 101806 E-NFB end */

#include "PhoneSetupGprots.h"
#include "SATDefs.h"
#ifdef __POPULATE_ENGINE_
#include "ExportMMIFunc.h"
#endif 
#include "DebugInitDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MAX_LANGUAGE_NUM 15

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define STRING_TYPE_ENFB    0xFF
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
U8 *gp_language_struct[MAX_LANGUAGE_NUM];
static U8 MenuItemMask[(MAX_MENU_ITEMS_VALUE / 8) + 1];

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern const CUSTOM_STRING_MAP *gpStringMapRes;
extern const CUSTOM_STRING *gpStringRes;
extern const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern const CUSTOM_IMAGE_MAP ImageIdMap[];
extern const CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[];
extern const CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern const CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMapEXT[];
extern const CUSTOM_MENU *nCustMenus;

/* MTK Elvis for R2L characters */
extern BOOL r2lMMIFlag;

/* MTK end */

extern U16 gMaxDeployedLangs;
extern U16 gCurrLangIndex;

/* extern StringResList gStringList[MAX_LANGUAGES]; */
extern StringResList *gStringList;

extern sLanguageDetails *gLanguageArray;

/* decalred in the CustImageRes.c */
extern CUSTOM_IMAGE *nCustImageNames;

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern CUSTOM_IMAGE *nCustImageNamesEXT;    /* 040805 CustPack: Calvin added */

/* __CUSTPACK_MULTIBIN Calvin END */

/* decalred in the CustScreenData.c */
extern CUSTOM_SCREEN nCustScreens[MAX_SCREEN_IDS];

/* declared in the CustMenuDataRes.c */

extern U16 CurrMaxStringId;     /* Max String Ids */
extern U16 CurrMaxStringNum;    /* Max Number Ids */
extern U16 CurrMaxStringIdSearch;

extern U16 CurrMaxImageId;  /* Max String Ids */
extern U16 CurrMaxSearchImageId;
extern U16 CurrMaxImageNum; /* Max Number Ids */

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
/* 040805 CustPack: Calvin added */
extern U16 CurrMaxImageIdEXT;   /* Max String Ids */
extern U16 CurrMaxSearchImageIdEXT;
extern U16 CurrMaxImageNumEXT;  /* Max Number Ids */

/* Calvin end */
/* __CUSTPACK_MULTIBIN Calvin END */

extern const CUSTOM_AUDIO_MAP AudioIdMap[];
extern const CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMap[];
extern const CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern const CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMapEXT[];
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern const U32 CurrMaxENFBAssociatedIDNum;
extern const CUSTOM_ENFB AssociatedID_map[];
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

extern CUSTOM_AUDIO *nCustAudioNames;
extern CUSTOM_AUDIO *nCustAudioNamesEXT;

extern U16 CurrMaxAudioId;
extern U16 CurrMaxSearchAudioId;
extern U16 CurrMaxAudioNum;

extern U16 CurrMaxAudioIdEXT;
extern U16 CurrMaxSearchAudioIdEXT;
extern U16 CurrMaxAudioNumEXT;

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern thm_contex_struct g_thm_cntx;
extern theme_details_struct g_tm_activated_theme;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

U8 g_curr_thm_index = 0;
extern MMI_theme *current_MMI_theme;


/* 101205 audio resource Calvin End */

/***************************************************************************** 
* Global Function
*****************************************************************************/
#ifdef __SAT__
extern void SATEVDLLangSel(U8 *);
#endif

#ifdef DEVAPP_RESOURCE
extern S8* DevAppGetString(U16 StringId);
extern S8* DevAppGetImage(U16 ImageId);
extern S8* DevAppGetAudio(U16 AudioId);
extern U16 DevAppGetParentItemId(U16 ItemId);
extern U16 DevAppGetNumOfChild(U16 ItemId);
extern U16 DevAppGetStringIdOfItem(U16 ItemId);
extern U16 DevAppGetImageIdOfItem(U16 ItemId);
extern U16 DevAppGetDispAttributeOfItem(U16 ItemId);
extern U16 DevAppGetSeqItemId(U16 ParentItemId, U16 Seq);
extern U16 DevAppGetSeqItemStringId(U16 ParentItemId, U16 Seq);
extern U16 DevAppGetSeqItemImageId(U16 ParentItemId, U16 Seq);
extern void DevAppGetSequenceItemIds(U16 ParentItemId, U16 *ItemIds);
extern void DevAppGetSequenceStringIds(U16 ParentItemId, U16 *StringIds);
extern U8 DevAppGetIndexOfStringId(U16 ParentItemId, U16 StringId);
extern void DevAppGetSequenceImageIds(U16 ParentItemId, U16 *ImageIds);
#endif

#ifndef __MTK_TARGET__
/* MTE image resource replacement */
extern U8 *mmi_mte_get_image_resource_buffer_by_id(U32 image_id);
extern S32 mmi_mte_is_resource_replacement_working(void);
extern S32 mmi_mte_is_active(void);
#endif /* __MTK_TARGET__ */

static const S8 empty_wstr[] = {0x00, 0x00};


/* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_if_enfb
 * DESCRIPTION
 *  test if img is an E-NFB image resource
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  MMI_BOOL    MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_if_enfb(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (img[0] == IMAGE_TYPE_ENFB)
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
 *  mmi_frm_enfb_if_associated
 * DESCRIPTION
 *  test if img is associated with other images
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  MMI_BOOL    MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_if_associated(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (img[1])
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
 *  mmi_frm_enfb_get_img_assid
 * DESCRIPTION
 *  get associated ID number of E-NFB image resource
 * PARAMETERS
 *  id      [IN]    image pointer
 * RETURNS
 *  U16             associated ID numer
 *****************************************************************************/
U32 mmi_frm_enfb_get_img_assid(const U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 1; i < CurrMaxENFBAssociatedIDNum; i++)
	{
		const CUSTOM_ENFB *enfb = NULL;
        U16 count;

		enfb = AssociatedID_map + i;
        count = AssociatedID_map[i].count;
		for (j = 0; j < count; j++)
		{
			if (enfb->IDs[j] == id)
			{
				return i;
			}
		}
	}

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_assid_count
 * DESCRIPTION
 *  get IDs count within an associated ID group
 * PARAMETERS
 *  assid   [IN]    image pointer
 * RETURNS
 *  U32             IDs count
 *****************************************************************************/
U16 mmi_frm_enfb_get_assid_count(const U16 assid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return AssociatedID_map[assid].count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_offset
 * DESCRIPTION
 *  get E-NFB image offset
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  U32             image offset
 *****************************************************************************/
U32 mmi_frm_enfb_get_img_offset(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)img[4] | (img[5] << 8) | (img[6] << 16) | (img[7] << 24);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_size
 * DESCRIPTION
 *  get E-NFB image size
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  U32             image size
 *****************************************************************************/
U32 mmi_frm_enfb_get_img_size(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)img[8] | (img[9] << 8) | (img[10] << 16) | (img[11] << 24);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_list
 * DESCRIPTION
 *  get E-NFB image list
 * PARAMETERS
 *  id      [IN]    image id
 *  list    [OUT]   image list
 * RETURNS
 *  U32             image offset
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_get_img_list(const U16 assid, const U16 count, mmi_frm_resmem_res_info_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (list != NULL)
	{
		for (i = 0; i < count; i++)
		{
			const U8 *img;

			img = AssociatedID_map[assid].Ptr[i].pImage;

			list[i].id = AssociatedID_map[assid].IDs[i];
			list[i].offset = mmi_frm_enfb_get_img_offset(img);
			list[i].size = mmi_frm_enfb_get_img_size(img);
		}

		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
/* 101806 E-NFB end */


/*****************************************************************************
 * FUNCTION
 *  GetStringLang
 * DESCRIPTION
 *  Function to get string associated with the stringId
 *  
 *  The function uses the variable CurrMaxStringId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  StringId        [IN]        
 *  lang_index      [IN]        
 *  U16(?)          [IN]        StringId
 *  char(?)         [OUT]       Displayed String.
 * RETURNS
 *  the String Mapped with the Id.
 *****************************************************************************/
S8 *GetStringLang(U16 StringId, U16 lang_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = CurrMaxStringIdSearch;
    S32 nMid;
    CUSTOM_STRMAP_SEARCH *pStrMapSearch;
    CUSTOM_STRING *pStringRes;
    CUSTOM_STRING_MAP *pStringMapRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pStringRes = gStringList[lang_index].pStringRes;
    pStringMapRes = gStringList[lang_index].pStringMap;
    pStrMapSearch = gStringList[lang_index].pStrMapSearch;

    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;;
        if ((pStrMapSearch[nMid].nMinStrId <= StringId) && (pStrMapSearch[nMid].nMaxStrId >= StringId))
        {
        #ifdef __ASCII
            return (S8*) &
                pStringRes[(pStringMapRes
                            [((pStrMapSearch[nMid].nMapIndex) + (StringId) - (pStrMapSearch[nMid].nMinStrId))])];
        #endif /* __ASCII */ 
        #ifdef __UCS2_ENCODING
            return (S8*) &
                pStringRes[(pStringMapRes
                            [((pStrMapSearch[nMid].nMapIndex) + (StringId) - (pStrMapSearch[nMid].nMinStrId))]) << 1];
        #endif /* __UCS2_ENCODING */ 
        }
        if (StringId > pStrMapSearch[nMid].nMinStrId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

#ifdef __ASCII
    return (S8*) "";
#else
    return (S8*) empty_wstr;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetString
 * DESCRIPTION
 *  Function to get string associated with the stringId
 *  
 *  The function uses the variable CurrMaxStringId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  StringId        [IN]        
 *  U16(?)          [IN]        StringId
 *  char(?)         [OUT]       Displayed String.
 * RETURNS
 *  the String Mapped with the Id.
 *****************************************************************************/
S8 *GetString(U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = CurrMaxStringIdSearch;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if (StringId >= DEVAPP_BASE)
    {
        S8 *ret_string = DevAppGetString(StringId);

        return ret_string;
    }
#endif

    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;;
        if ((gpStrMapSearch[nMid].nMinStrId <= StringId) && (gpStrMapSearch[nMid].nMaxStrId >= StringId))
        {
            return (S8*) &
                gpStringRes[(gpStringMapRes
                             [((gpStrMapSearch[nMid].nMapIndex) + (StringId) -
                               (gpStrMapSearch[nMid].nMinStrId))]) << 1];
        }
        if (StringId > gpStrMapSearch[nMid].nMinStrId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return (S8*) empty_wstr;
}


/*****************************************************************************
 * FUNCTION
 *  fread_all
 * DESCRIPTION
 *  Function to get filename associated with the ImageId
 *  
 *  The function uses the variable CurrMaxImageId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  handle          [IN]        
 *  dest            [?]         
 *  dest_size       [IN]        
 *  want_size       [IN]        
 *  U16(?)          [IN]        ImageId.
 *  char(?)         [OUT]       Displayed Image Filename.
 * RETURNS
 *  Returns the filename associated with the ImageId.
 *****************************************************************************/
#if defined(__MMI_DEFAULT_THEME_3__)

#include "filesystemdef.h"
static U16 cache_image_id;
static U32 cache_image_content[30000 / 4];

/* MTK added, Max: to clear gif cache 0202, modified by JF */
#if !defined(__BW_MMI__) && !defined(WIN32)     /* Target version shall use this library */
extern void GIF_clear_cache(void);
#endif 
/* MTK end */
static kal_bool fread_all(FS_HANDLE handle, U8 *dest, S32 dest_size, S32 want_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dest_size >= want_size);

    FS_Seek(handle, 0, FS_FILE_BEGIN);

    while (want_size > 0)
    {
        S32 nRead;

        if (FS_Read(handle, dest, want_size, (kal_uint32*) & nRead) != FS_NO_ERROR)
        {
            return KAL_FALSE;
        }

        want_size -= nRead;
        dest += nRead;
    }
    return KAL_TRUE;
}
#endif /* defined(__MMI_DEFAULT_THEME_3__) */ 


#ifdef __MMI_THEMES_V2_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetImageFromTheme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S8 *GetImageFromTheme(
        U16 ImgID,
        U16 ImgIndex,
        const CUSTOM_IMAGE_MAP *ImgIDMap,
        const CUSTOM_IMAGE_SEARCH_MAP *ImgIDSearchMap,
        const CUSTOM_IMAGE *ImgNames)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_does_theme_have_alt_image())
    {
        if (mmi_tm_is_theme_dirty_bit_set(ImgIndex))
        {
            S32 nArrayIndex;

            if (mmi_tm_get_curr_theme_type() == THEME_TYPE_SYSTEM)
            {
                return (S8*)mmi_tm_get_system_theme_image(
                        mmi_tm_get_theme_image_offset_or_index(ImgID, &nArrayIndex));
            }
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
            else
            {
                U32 nImageIndex = mmi_tm_get_theme_image_offset_or_index(ImgID, &nArrayIndex);

                if (nImageIndex > 0)
                {
                    S8 *pImageData;
#ifdef __MMI_DLT_CACHE_SUPPORT__
                    U8 image_type = mmi_tm_get_image_load_type(nArrayIndex);

                    if (image_type != THEME_IMG_LOAD_NEVER)
                    {
                        pImageData = (PS8) mmi_tm_find_img_in_cache(nArrayIndex, image_type);
                        
                        if (!pImageData)
                        {
                            pImageData = (PS8) mmi_tm_add_img_id_to_cache(nArrayIndex, nImageIndex, image_type);
                            if (!pImageData)
                            {
                                pImageData = (PS8) mmi_tm_get_downloaded_theme_image(nImageIndex, nArrayIndex);
                                if (!pImageData)
                                {
                                    return NULL;
                                }
                            }
                        }
                        return pImageData;
                    }
                    else
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
                    {
                        pImageData = (PS8) mmi_tm_get_downloaded_theme_image(nImageIndex, nArrayIndex);
                        if (!pImageData)
                        {
                            return NULL;
                        }

                        return pImageData;
                    }
                }
                else
                {
                    return NULL;
                }

            }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        }
    }
    return NULL;
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  GetImageFromIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S8 *GetImageFromIndex(
        U16 ImgID,
        const CUSTOM_IMAGE_MAP *ImgIDMap,
        const CUSTOM_IMAGE_SEARCH_MAP *ImgIDSearchMap,
        const CUSTOM_IMAGE *ImgNames,
        U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = count - 1;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast)/2;
        if ((ImgIDSearchMap[nMid].minImageId <= ImgID) &&
            (ImgIDSearchMap[nMid].maxImageId >= ImgID))
        {
            U16 img_index;

            img_index = (U16)ImgIDMap[(ImgIDSearchMap[nMid].index) + (ImgID) - (ImgIDSearchMap[nMid].minImageId)].nImageNum;

#ifdef __MMI_THEMES_V2_SUPPORT__
            {   /* get image from theme */
                S8 *img = GetImageFromTheme(ImgID, img_index, ImgIDMap, ImgIDSearchMap, ImgNames);
                if (img != NULL)
                {
                    return img;
                }
            }
#endif /* __MMI_THEMES_V2_SUPPORT__ */

            return (S8*) (ImgNames[img_index].pImage);
        }

        if (ImgID > ImgIDSearchMap[nMid].minImageId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetImageRaw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetImageRaw(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if (ImageId >= DEVAPP_BASE)
    {
        S8 *ret_image = DevAppGetImage(ImageId);

        return ret_image;
    }
#endif

    if (ImageId >= NV_RAM_FILE_IMAGE_ID_BASE &&
        ImageId <= NV_RAM_FILE_IMAGE_ID_BASE_END)
    {
        S8 *image_src = GetImageFileSystem(ImageId);

#if defined(__MMI_DEFAULT_THEME_3__)
        /*
         * Justin 0201. We patch BMP_file_display to avoid display BMP "file" as transparent image
         * * but we do not patch _show_transparent_bitmap in order to prevent possible side-effects 
         * * This is a temporary fix until we use GDI to replace wingui
         */
        if (image_src[0] == IMAGE_TYPE_BMP_FILE)
        {
            return image_src;
        }

        if (cache_image_id != ImageId)
        {
            FS_HANDLE file = FS_Open((U8*) (image_src + 6), FS_READ_ONLY);

            if (file != (FS_HANDLE) NULL)
            {
                S32 size;

                FS_GetFileSize(file, &size);

                /* cast type to signed int 1228 */
                if (size < (S32) (sizeof(cache_image_content) - 6))     /* test the file size */
                {
                    if (fread_all(file, ((U8*) cache_image_content) + 6, (S32) (sizeof(cache_image_content) - 6), size))
                    {
                        U8 *header = (U8*) cache_image_content;

                        switch (image_src[0])
                        {
                            case IMAGE_TYPE_BMP_FILE:
                                header[0] = IMAGE_TYPE_BMP;
                                break;
                            case IMAGE_TYPE_GIF_FILE:
                                header[0] = IMAGE_TYPE_GIF;
                                /* clear gif cache 0202 */
                                /* Target version shall use this library */
#if !defined(__BW_MMI__) && !defined(WIN32)
                                GIF_clear_cache();
#endif 
                                break;
                            default:
                                FS_Close(file);
                                return image_src;
                        }

                        header[1] = (U8) NULL;
                        header[2] = (U8) (size & 0x000000ff);
                        header[3] = (U8) ((size >> 8) & 0x000000ff);
                        header[4] = (U8) ((size >> 16) & 0x000000ff);
                        header[5] = (U8) ((size >> 24) & 0x000000ff);

                        cache_image_id = ImageId;
                        FS_Close(file);
                        return (S8*) & (cache_image_content[0]);
                    }
                }
                FS_Close(file);
            }
        }
        else
        {
            return (S8*) & (cache_image_content[0]);
        }
#endif /* defined(__MMI_DEFAULT_THEME_3__) */ 
        return image_src;
    }
    else
    {
        S8 *img;

        img = GetImageFromIndex(
                ImageId,
                ImageIdMap,
                ImageIdSearchMap,
                nCustImageNames,
                CurrMaxSearchImageId);

        /* CustPack */
        if (img == NULL)
        {
            img = GetImageFromIndex(
                    ImageId,
                    ImageIdMapEXT,
                    ImageIdSearchMapEXT,
                    nCustImageNamesEXT,
                    CurrMaxSearchImageIdEXT);
        }

        if (img != NULL)
        {
            return img;
        }
        else
        {
            return (S8*) (nCustImageNames[0].pImage);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetImageTheme
 * DESCRIPTION
 *  This function is to get the specific images stores in system or downloadable
 *  theme structure. It differs from GetImageFromTheme(), which is only for
 *  downloadable theme.
 * PARAMETERS
 *  ImageId     [IN]  Image ID
 * RETURNS
 *  Pointer to the image
 *****************************************************************************/
static S8 *GetImageTheme(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ImageId)
    {
        case CHECKBOX_ON_IMAGE_ID:  /* check-box image */
            img = (U8*)(current_MMI_theme->list_check_selected_image);
            break;

        case CHECKBOX_OFF_IMAGE_ID:
            img = (U8*)(current_MMI_theme->list_check_unselected_image);
            break;

        case RADIO_ON_IMAGE_ID:     /* radio selector image */
            img = (U8*)(current_MMI_theme->list_radio_selected_image);
            break;

        case RADIO_OFF_IMAGE_ID:
            img = (U8*)(current_MMI_theme->list_radio_unselected_image);
            break;

        case IMG_H_SELECT_LEFT:     /* in-line editor, left-right selector */
            img = (U8*)(current_MMI_theme->inline_edit_left_arrow_image);
            break;

        case IMG_H_SELECT_RIGHT:
            img = (U8*)(current_MMI_theme->inline_edit_right_arrow_image);
            break;

        default:
            break;
    }

    return (S8*) img;
}


/* 101806 E-NFB start */
/*****************************************************************************
 * FUNCTION
 *  GetImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetImage(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    /* MTE image resource replacement */
    if (mmi_mte_is_resource_replacement_working())
    {
        /* only handle image resources here. */
        if (img = mmi_mte_get_image_resource_buffer_by_id((U32)ImageId))
        {
            return img;
        }
    }        
#endif /* __MTK_TARGET__ */
    
    /* get specific images stored in theme structure */
    img = (U8*)GetImageTheme(ImageId);
    if (img != NULL)
    {
        return (S8*)img;
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* check cache */
    img = mmi_frm_resmem_if_ramed(ImageId);
    if (img != NULL)
    {
        return (S8*)img;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* load image raw data */
    img = (U8*)GetImageRaw(ImageId);
    if (img == NULL)
    {
		return (S8*)img;
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* check E-NFB */
    if (mmi_frm_enfb_if_enfb(img) == MMI_TRUE)
    {
        U32 offset, size;

        /* get size & offset */
        offset = mmi_frm_enfb_get_img_offset(img);
        size = mmi_frm_enfb_get_img_size(img);

        /* check associated */
        if (mmi_frm_enfb_if_associated(img) == MMI_FALSE)
        {
            /* load one image from E-NFB */
            img = mmi_frm_resmem_load_single_image(ImageId, offset, size);
        }
        else
        {
            U16 assid, count;
            mmi_frm_resmem_res_info_struct *list;

            /* get associated ID & count */
            assid = mmi_frm_enfb_get_img_assid(ImageId);
            count = mmi_frm_enfb_get_assid_count(assid);

            /* allocated memory */
            list = OslMalloc(count * sizeof(mmi_frm_resmem_res_info_struct));
            if (list != NULL)
            {
                memset(list, 0, count * sizeof(mmi_frm_resmem_res_info_struct));

                /* get associated list */
                if (mmi_frm_enfb_get_img_list(assid, count, list) == MMI_TRUE)
                {
                    /* load associated images from E-NFB */
                    img = mmi_frm_resmem_load_multi_image(ImageId, list, count);
                }

                /* free memory */
                OslMfree(list);
                list = NULL;
            }
            else
            {
                /* memory allocation failed, load only one image */
                img = mmi_frm_resmem_load_single_image(ImageId, offset, size);
            }
        }
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    return (S8*)img;
}
/* 101806 E-NFB end */


#ifdef __MMI_THEMES_V2_SUPPORT__        /* ritesh */


/*****************************************************************************
 * FUNCTION
 *  GetImageIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 GetImageIndex(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = CurrMaxSearchImageId;
    S32 nMid = (nFirst + nLast) / 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;
        if ((ImageIdSearchMap[nMid].minImageId <= ImageId) && (ImageIdSearchMap[nMid].maxImageId >= ImageId))
        {
            break;
        }
        if (ImageId > ImageIdSearchMap[nMid].minImageId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return ImageIdMap[(ImageIdSearchMap[nMid].index) + (ImageId) - (ImageIdSearchMap[nMid].minImageId)].nImageNum;
}


/*****************************************************************************
 * FUNCTION
 *  GetDefaultImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetDefaultImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) (nCustImageNames[0].pImage);
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

/* 101205 Audio Resource Calvin Start */


/*****************************************************************************
 * FUNCTION
 *  GetAudio
 * DESCRIPTION
 *  Function to get audio data associated with the AudioId
 *  
 *  The function uses the variable CurrMaxAudioId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  AudioId     [IN]        
 *  U16(?)      [IN]        AudioId.
 *  char(?)     [OUT]       Displayed Audio data pointer
 * RETURNS
 *  Returns the audio datad with the AudioId.
 *****************************************************************************/
S8 *GetAudio(U16 AudioId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = CurrMaxSearchAudioId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if (AudioId >= DEVAPP_BASE)
    {
        S8 *ret_audio = DevAppGetAudio(AudioId);

        return ret_audio;
    }
#endif

    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((AudioIdSearchMap[nMid].minAudioId <= AudioId) && (AudioIdSearchMap[nMid].maxAudioId >= AudioId))
        {
            return (S8*)
                nCustAudioNames[AudioIdMap
                                [(AudioIdSearchMap[nMid].index) + (AudioId) -
                                 (AudioIdSearchMap[nMid].minAudioId)].nAudioNum].pAudio;
        }
        if (AudioId > AudioIdSearchMap[nMid].minAudioId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    /* for custpack */
    nFirst = 0;
    nLast = CurrMaxSearchAudioIdEXT;
    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((AudioIdSearchMapEXT[nMid].minAudioId <= AudioId) && (AudioIdSearchMapEXT[nMid].maxAudioId >= AudioId))
        {

            return (S8*)
                nCustAudioNamesEXT[AudioIdMapEXT
                                   [(AudioIdSearchMapEXT[nMid].index) + (AudioId) -
                                    (AudioIdSearchMapEXT[nMid].minAudioId)].nAudioNum].pAudio;
        }
        if (AudioId > AudioIdSearchMapEXT[nMid].minAudioId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return (S8*) (nCustAudioNames[0].pAudio);;
}

/* 101205 Audio Resource Calvin End */


/*****************************************************************************
 * FUNCTION
 *  GetParentItemId
 * DESCRIPTION
 *  Function to get Parent MenuItemId of the Given MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       Parent MenuItemId of the given MenuItemId.
 * RETURNS
 *  the Parent MenuItemId.
 *****************************************************************************/
U16 GetParentItemId(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetParentItemId(ItemId);
    }
#endif

    return nCustMenus[ItemId - 1].nParentId;

}

/* MTK Leo add 20040409, to sync titleicon */


/*****************************************************************************
 * FUNCTION
 *  GetRootParentIndex
 * DESCRIPTION
 *  Function to get Parent MenuItemId of the Given MenuItemId in Mainmenu
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       Parent MenuItemId of the given MenuItemId in Mainmenu.
 * RETURNS
 *  the Parent MenuItemId in Mainmenu.
 *****************************************************************************/
U16 GetRootParentIndex(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 RootId;
    U16 parent_id;
    U16 idx;

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    U16 parent_idx = 0;
    U16 grand_parent_id = 0;
    U16 num_of_child = 0;
    U16 total_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = GetParentItemId(ItemId);

    /* Group menu id */
    if (parent_id == 1)
    {
        return 0;
    }

    grand_parent_id = GetParentItemId(parent_id);

    RootId = ItemId;

    while (grand_parent_id != IDLE_SCREEN_MENU_ID)
    {
        RootId = parent_id;
        parent_id = grand_parent_id;
        grand_parent_id = GetParentItemId(grand_parent_id);
        if (parent_id == 0)
        {
            return 0xff;
        }
    }

    num_of_child = GetNumOfChild(IDLE_SCREEN_MENU_ID);
    for (parent_idx = 0; parent_idx < num_of_child; parent_idx++)
    {
        if (GetSeqItemId(IDLE_SCREEN_MENU_ID, parent_idx) == parent_id)
        {
            num_of_child = GetNumOfChild(parent_id);
            for (idx = 0; idx < num_of_child; idx++)
                if (GetSeqItemId(parent_id, idx) != RootId)
                {
                    total_idx++;
                }
                else
                {
                    return total_idx;
                }
        }
        else
        {
            total_idx += GetNumOfChild(GetSeqItemId(IDLE_SCREEN_MENU_ID, parent_idx));
        }
    }

    return 0xff;

#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    RootId = ItemId;
    parent_id = GetParentItemId(ItemId);
    if (parent_id != IDLE_SCREEN_MENU_ID)
    {   /* ItemId is not one of the itemIds of mainmenu */
        RootId = parent_id;
        parent_id = GetParentItemId(parent_id);
        while (parent_id != IDLE_SCREEN_MENU_ID)
        {
            RootId = parent_id;
            parent_id = GetParentItemId(parent_id);
            if (parent_id == 0)
            {
                return 0xff;
            }
        }
    }   /* RootId is the menu id in mainmenu */
    for (idx = 0; idx < nCustMenus[0].nNumofMenuItem; idx++)
    {
        if (nCustMenus[0].nOrderMenuItemId[idx] == RootId)
        {
            break;
        }
    }

    return idx;
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
}

/* MTK Leo end */


/*****************************************************************************
 * FUNCTION
 *  GetNumOfChild
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       Number of Childrens of the given MenuItemId.
 * RETURNS
 *  Number of Childrens.
 *****************************************************************************/
U16 GetNumOfChild(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetNumOfChild(ItemId);
    }
#endif
    return nCustMenus[ItemId - 1].nNumofMenuItem;
}


/*****************************************************************************
 * FUNCTION
 *  GetStringIdOfItem
 * DESCRIPTION
 *  Function to get StringId of the Given MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       StringId.
 * RETURNS
 *  StringId of the given MenuItemId.
 *****************************************************************************/
U16 GetStringIdOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetStringIdOfItem(ItemId);
    }
#endif
    return nCustMenus[ItemId - 1].nStrId;

}


/*****************************************************************************
 * FUNCTION
 *  GetImageIdOfItem
 * DESCRIPTION
 *  Function to get ImageId of the given MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       ImageId.
 * RETURNS
 *  ImageId of the given MenuItemId.
 *****************************************************************************/
U16 GetImageIdOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetImageIdOfItem(ItemId);
    }
#endif

    if (ItemId == MAIN_MENU_CALL_HISTORY)
    {
        ItemId = MAIN_MENU_CALL_HISTORY;
    }
    return nCustMenus[ItemId - 1].nImageId;

}


/*****************************************************************************
 * FUNCTION
 *  GetDispAttributeOfItem
 * DESCRIPTION
 *  Function to get DispAttributes of the given MenuItemId.
 *  
 *  DispAttribute are like Matrix,List,Circular,Tab..etc.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       DispAttribute.
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
U16 GetDispAttributeOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetDispAttributeOfItem(ItemId);
    }
#endif
    return nCustMenus[ItemId - 1].nDispAttribute;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemId
 * DESCRIPTION
 *  Function to get MenuItemId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 *  U16(?)              [OUT]       MenuItemId.
 * RETURNS
 *  MenuItemId of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
U16 GetSeqItemId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetSeqItemId(ParentItemId, Seq);
    }
#endif
    return nCustMenus[ParentItemId - 1].nOrderMenuItemId[Seq];

}

/*****************************************************************************
 * FUNCTION
 *  GetChildMenuIDIndexByParentMenuID
 * DESCRIPTION
 *  Function to get the index of the given MenuItemId in the child sequence of the parent MenuItem.
 *  No hide attribute consideration.
 * PARAMETERS
 *  parentMenuId        [IN]        
 *  childMenuId         [IN]        
 *  a(?)                [IN]        Parent menu id
 *  b(?)                [IN]        Child menu id
 * RETURNS
 *  index >= 0: child manu id is a child of parent menu id, -1: if not
 *****************************************************************************/
S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    U16 nMenuItemList[MAX_SUB_MENUS];
    U16 numItems = GetNumOfChild(parentMenuId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds(parentMenuId, nMenuItemList);

    for (index = 0; index < numItems; index++)
    {
        if (nMenuItemList[index] == childMenuId)
        {
            return index;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemStringId
 * DESCRIPTION
 *  Function to get StringId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 *  U16(?)              [OUT]       StringId of the MenuItem.
 * RETURNS
 *  StringId of the MenuItem of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
U16 GetSeqItemStringId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetSeqItemStringId(ParentItemId, Seq);
    }
#endif

    return GetStringIdOfItem(nCustMenus[ParentItemId - 1].nOrderMenuItemId[Seq]);

}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemImageId
 * DESCRIPTION
 *  Function to get ImageId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 *  U16(?)              [OUT]       ImageId of the MenuItem.
 * RETURNS
 *  ImageId of the MenuItem of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
U16 GetSeqItemImageId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetSeqItemImageId(ParentItemId, Seq);
    }
#endif
    return GetImageIdOfItem(nCustMenus[ParentItemId - 1].nOrderMenuItemId[Seq]);

}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceItemIds
 * DESCRIPTION
 *  Function to get all the MenuItemIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ItemIds             [?]         
 *  fills(?)            [OUT]       The input parameter. Memory is allocated by the caller.
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 *) PoU16er containing the Array of MenuItemId.
 * RETURNS
 *  void
 *****************************************************************************/
void GetSequenceItemIds(U16 ParentItemId, U16 *ItemIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        DevAppGetSequenceItemIds(ParentItemId, ItemIds);
    }
#endif

    for (j = 0; j < nCustMenus[ParentItemId - 1].nNumofMenuItem; j++)
    {
        ItemIds[j] = nCustMenus[ParentItemId - 1].nOrderMenuItemId[j];
    }

}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceStringIds
 * DESCRIPTION
 *  Function to get all the StringIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringIds           [?]         
 *  fills(?)            [OUT]       The input parameter. Memory is allocated by the caller.
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 *) PoU16er containing the Array of StringIds.
 * RETURNS
 *  void
 *****************************************************************************/
void GetSequenceStringIds(U16 ParentItemId, U16 *StringIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        DevAppGetSequenceStringIds(ParentItemId, StringIds);
    }
#endif

    for (j = 0; j < nCustMenus[ParentItemId - 1].nNumofMenuItem; j++)
    {
        StringIds[j] = GetStringIdOfItem(nCustMenus[ParentItemId - 1].nOrderMenuItemId[j]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  GetIndexOfStringId
 * DESCRIPTION
 *  Function to get the index of StringIds in the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringId            [IN]        
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 ) StringId
 * RETURNS
 *  U8
 *****************************************************************************/
U8 GetIndexOfStringId(U16 ParentItemId, U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetIndexOfStringId(ParentItemId, StringId);
    }
#endif

    for (j = 0; j < nCustMenus[ParentItemId - 1].nNumofMenuItem; j++)
        if (StringId == nCustMenus[ParentItemId - 1].nOrderMenuItemId[j])
        {
            return (U8) j;
        }
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceImageIds
 * DESCRIPTION
 *  Function to get all the ImageIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ImageIds            [?]         
 *  fills(?)            [OUT]       The input parameter. Memory is allocated by the caller.
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 *) PoU16er containing the Array of ImageIds.
 * RETURNS
 *  void
 *****************************************************************************/
void GetSequenceImageIds(U16 ParentItemId, U16 *ImageIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( ParentItemId >= MENU_ID_DEVAPP_START )
    {
        DevAppGetSequenceImageIds(ParentItemId, ImageIds);
    }
#endif
    for (j = 0; j < nCustMenus[ParentItemId - 1].nNumofMenuItem; j++)
    {
        ImageIds[j] = GetImageIdOfItem(nCustMenus[ParentItemId - 1].nOrderMenuItemId[j]);
    }

}


#ifdef __MMI_THEMES_V2_SUPPORT__
extern theme_details_struct *MMI_themes;
#else 
extern CONST_HARDWARE MMI_theme **MMI_themes;
#endif 
extern S32 n_MMI_themes;


/*****************************************************************************
 * FUNCTION
 *  GetThemesNames
 * DESCRIPTION
 *  Retrieves the existing themes
 * PARAMETERS
 *  dest            [?]         
 *  Array(?)        [OUT]       Of pointers
 * RETURNS
 *  Number of themes
 *****************************************************************************/
S32 GetThemesNames(U8 **dest[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 noOfThemes = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
    {
        return noOfThemes;
    }

    *dest = NULL;
    return n_MMI_themes;
}


/*****************************************************************************
 * FUNCTION
 *  SetThemes
 * DESCRIPTION
 *  Set the theme
 * PARAMETERS
 *  index       [IN]        To  the global theme structure
 * RETURNS
 *  void
 *****************************************************************************/
void SetThemes(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_thm_index = index;
    //      set_MMI_theme((MMI_theme *)MMI_themes[index]);
    //      MMI_apply_current_theme();
}

extern void MMI_apply_current_theme(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_get_phone_model
 * DESCRIPTION
 *  This function gets the phone model in theme res
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const PS8 mmi_get_phone_model(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* PMT SUKRIT START 070806 */
#ifndef DEMO_PROJECT
    extern PS8 mmi_theme_phone_model;   /* defined in standalone res */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_theme_phone_model;/* Customer should define their own phone model */
#else /* DEMO_PROJECT */ 
        extern kal_char* release_hw_ver(void); 
 
        return release_hw_ver(); /* Demo H/W will use verno string */
#endif /* DEMO_PROJECT */ 
    /* PMT SUKRIT END 070806 */
}



/*****************************************************************************
 * FUNCTION
 *  UpdateUITheme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateUITheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    /* If MTE is active, no theme activation is allowed. */
    if (mmi_mte_is_active())
    {
        return;
    }
#endif /* __MTK_TARGET__ */
    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)  /* fixed for usb */
    {
        if (g_tm_activated_theme.theme != current_MMI_theme)
        {
            set_MMI_theme(g_tm_activated_theme.theme);
            MMI_apply_current_theme();
        }
    }
    else
    {
        if (MMI_themes[g_curr_thm_index-1].theme != current_MMI_theme)
        {
            set_MMI_theme((MMI_theme*) MMI_themes[g_curr_thm_index-1].theme);
            MMI_apply_current_theme();
        }
    }
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    if (MMI_themes[g_curr_thm_index] != current_MMI_theme)
    {
        set_MMI_theme((MMI_theme*) MMI_themes[g_curr_thm_index]);
        MMI_apply_current_theme();
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetLanguages
 * DESCRIPTION
 *  Get the language list.
 * PARAMETERS
 *  pppLanguages        [IN]        
 *  U16(?)              [OUT]       
 *  an(?)               [IN]        Array for getting the language list
 * RETURNS
 *  the number of languages deployed
 *****************************************************************************/
U16 GetLanguages(U8 ***pppLanguages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //Robin 1121, prevent memory leak
    //*pppLanguages = OslMalloc(gMaxDeployedLangs*sizeof(U8*));
    *pppLanguages = &gp_language_struct[0];

    for (nCount = 0; (nCount < gMaxDeployedLangs && nCount < MAX_LANGUAGE_NUM); ++nCount)
    {
        (*pppLanguages)[nCount] = (U8*) gLanguageArray[nCount].aName;
        /* ++nCount; */
    }

    //Robin 1121, prevent memory leak
    //return gMaxDeployedLangs;
    return nCount;
}


/*****************************************************************************
 * FUNCTION
 *  GetLanguageIndex
 * DESCRIPTION
 *  Get the index of language specified by ssc_string.
 *  
 *  Return 0, if not found.
 * PARAMETERS
 *  ssc_str         [?]         
 *  index(?)        [OUT]       (1 based)
 *  U8(?)           [IN]        * ssc_string of lang
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetLanguageIndex(S8 *ssc_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ssc_str == NULL)
    {
        return 0xFFFF;
    }

    for (idx = 0; idx < gMaxDeployedLangs; idx++)
    {
        if (strcmp(ssc_str, (S8*) gLanguageArray[idx].aLangSSC) == 0)
        {
            return idx;
        }
    }
    return 0xFFFF;
}


/*****************************************************************************
 * FUNCTION
 *  GetLanguageIndexByLangCode
 * DESCRIPTION
 *  Get the index of language specified by language code.
 *  
 *  Return 0, if not found.
 * PARAMETERS
 *  lang_code         [?]         
 *  index(?)        [OUT]       (1 based)
 *  U8(?)           [IN]        * langauge code of lang
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetLanguageIndexByLangCode(S8 *lang_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;
    U8 LangCode[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lang_code == NULL)
    {
        return 0xFFFF;
    }

    for (idx = 0; idx < gMaxDeployedLangs; idx++)
    {
        memcpy(LangCode, gLanguageArray[idx].aLangCountryCode, 2);
        LangCode[2] = '\0';

        if (strncmp(lang_code, (S8*)LangCode, 2) == 0)
        {
            return idx;
        }
    }
    return 0xFFFF;
}


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_if_enfb_str
 * DESCRIPTION
 *  test if data is an E-NFB string resource
 * PARAMETERS
 *  data    [IN]    data pointer
 * RETURNS
 *  MMI_BOOL    MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_if_enfb_str(const U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (data[0] == STRING_TYPE_ENFB)
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
 *  mmi_frm_enfb_get_str_offset
 * DESCRIPTION
 *  get E-NFB string offset
 * PARAMETERS
 *  data    [IN]    data pointer
 * RETURNS
 *  U32             data offset
 *****************************************************************************/
U32 mmi_frm_enfb_get_str_offset(const U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)data[4] | (data[5] << 8) | (data[6] << 16) | (data[7] << 24);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_str_size
 * DESCRIPTION
 *  get E-NFB string size
 * PARAMETERS
 *  data    [IN]    data pointer
 * RETURNS
 *  U32             data size
 *****************************************************************************/
U32 mmi_frm_enfb_get_str_size(const U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)data[8] | (data[9] << 8) | (data[10] << 16) | (data[11] << 24);
}
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  SetCurrentLanguage
 * DESCRIPTION
 *  Set the current language to the index.
 * PARAMETERS
 *  nIndex      [IN]        Of lang to set
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL gLanguageSettingOnBootUp = TRUE;
extern void mmi_phb_callergroup_set_name_by_language(void);

#if defined(__MMI_VRSI__)
extern void mmi_vrsi_init_central_change_language_reset(void);
#endif 

void SetCurrentLanguage(S8 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
    U8 LangCode[6];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex >= gMaxDeployedLangs)
    {
        nIndex = 0;
    }
    gCurrLangIndex = nIndex;
    
    r2lMMIFlag = IsL2RMMIStyle();
    
#if defined(__MMI_LANG_HINDI__ ) || defined(__MMI_LANG_MARATHI__ )
    set_current_language_for_hindi_rules();
#endif 
    
    gpStringRes = gStringList[gCurrLangIndex].pStringRes;
    gpStringMapRes = gStringList[gCurrLangIndex].pStringMap;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if(mmi_frm_enfb_if_enfb(gpStringRes) == MMI_TRUE)
    {
        U32 offset[2], size[2];
        U8 *ptr[2] = {0};
        
        /* read ENFB string resource information */
        offset[0] = mmi_frm_enfb_get_str_offset(gpStringRes);
        size[0] = mmi_frm_enfb_get_str_size(gpStringRes);
        offset[1] = (U32)gpStringMapRes[0];
        size[1] = (U32)gpStringMapRes[1];

        /* load string data */
		mmi_frm_resmem_load_str_suite(ptr, offset, size, 2);
        
        /* re-assign pointer */
        gpStringRes = (CUSTOM_STRING *)ptr[0];
        gpStringMapRes = (CUSTOM_STRING_MAP *)ptr[1];
    }
    else
    {
        /* ENFB is enabled,
         * but the string resource is not a valid one */
        MMI_ASSERT(0);
    }
#endif

    gpStrMapSearch = gStringList[gCurrLangIndex].pStrMapSearch;
    CurrMaxStringNum = gStringList[gCurrLangIndex].nTotalStrRes;
    CurrMaxStringId = gStringList[gCurrLangIndex].nTotalStrMap;
    CurrMaxStringIdSearch = gStringList[gCurrLangIndex].nTotalStrMapSearch;

    if (gLanguageSettingOnBootUp == FALSE)
    {
        PhnsetReinitHomeCityIdx();
    }
    else
    {
        gLanguageSettingOnBootUp = FALSE;
    }

    /* Change caller group name default vaule when change lanaguage */
    mmi_phb_callergroup_set_name_by_language();

#if defined(__MMI_VRSI__)
    /* Reset voice command central command according to the language. */
    mmi_vrsi_init_central_change_language_reset();
#endif /* defined(__MMI_VRSI__) */ 

    /* send langauge code, the first two character is langauge code */
#ifdef __SAT__
    memcpy(LangCode, gLanguageArray[gCurrLangIndex].aLangCountryCode, 2);
    LangCode[2] = '\0';
    SATEVDLLangSel((PU8) LangCode);
#endif /* __SAT__ */
}

/* MTK added, Max: to solve schedule power on/off change home city issue 1202 */


/*****************************************************************************
 * FUNCTION
 *  ResetLanguageSettingFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetLanguageSettingFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gLanguageSettingOnBootUp = TRUE;
}

/* MTK end */

/* MTK Leo add, for mini_tab_bar */


/*****************************************************************************
 * FUNCTION
 *  GetSeqItems
 * DESCRIPTION
 *  Get child menuitems.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  id(?)               [IN]        Of parent
 * RETURNS
 *  void
 *****************************************************************************/
U16 *GetSeqItems(U16 ParentItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nCustMenus[ParentItemId - 1].nOrderMenuItemId;
}

/* MTK Leo end */

/* APIs for hide some menuitems at run time */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_hide_menu_item
 * DESCRIPTION
 *  Set the bit represented the menuitem on to hide it
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_hide_menu_item(U16 menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = menu_item_id - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_item_id < MAX_MENU_ITEMS_VALUE)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        MenuItemMask[idx] |= (1 << (7 - reminding));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_unhide_menu_item
 * DESCRIPTION
 *  Reset the bit represented the menuitem on to unhide it
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_unhide_menu_item(U16 menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = menu_item_id - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_item_id < MAX_MENU_ITEMS_VALUE)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        MenuItemMask[idx] &= ~(1 << (7 - reminding));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_test_menu_item_hide
 * DESCRIPTION
 *  test if the menuitem is hidden or not
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  MMI_BOOL MMI_TRUE if the menuitem is hidden
 *****************************************************************************/
MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = menu_item_id - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_item_id < MAX_MENU_ITEMS_VALUE)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        if ((MenuItemMask[idx] >> (7 - reminding)) & 1)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetNumOfChild_Ext
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId considering MenuItemMask.
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  U16   Number of Childrens.
 *****************************************************************************/
U16 GetNumOfChild_Ext(U16 menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0, num_child = nCustMenus[menu_item_id - 1].nNumofMenuItem;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_child; i++)
    {
        if (!mmi_frm_test_menu_item_hide(nCustMenus[menu_item_id - 1].nOrderMenuItemId[i]))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemId_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id & index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   item id
 *****************************************************************************/
U16 GetSeqItemId_Ext(U16 parent_item_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, idx = 0;
    U16 item_id = 0;
    U8 child_count = (U8) nCustMenus[parent_item_id - 1].nNumofMenuItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ( parent_item_id >= MENU_ID_DEVAPP_START )
    {
        return DevAppGetSeqItemId(parent_item_id, index);
    }
#endif

    for (i = 0; i < child_count; i++)
    {
        item_id = nCustMenus[parent_item_id - 1].nOrderMenuItemId[i];
        if (!mmi_frm_test_menu_item_hide(item_id))  /* the item is not hidden */
        {
            if (idx == index)
            {
                break;
            }
            else
            {
                idx++;
            }
        }
    }
    MMI_ASSERT(i < child_count);    /* all children are hidden */
    return item_id;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemStringId_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id and index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   string id
 *****************************************************************************/
U16 GetSeqItemStringId_Ext(U16 parent_item_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = (U8) GetSeqItemId_Ext(parent_item_id, index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetStringIdOfItem(idx);
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemImageId_Ext
 * DESCRIPTION
 *  Function to get Image Id of the given parent_item_id and index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   image id
 *****************************************************************************/
U16 GetSeqItemImageId_Ext(U16 parent_item_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = (U8) GetSeqItemId_Ext(parent_item_id, index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetImageIdOfItem(idx);
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceItemIds_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  ItemIds             [IN/OUT]        Array of the child menuitem id
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 GetSequenceItemIds_Ext(U16 parent_item_id, U16 *ItemIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < nCustMenus[parent_item_id - 1].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[parent_item_id - 1].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            ItemIds[ret_idx++] = nCustMenus[parent_item_id - 1].nOrderMenuItemId[j];
        }
    }
    return ret_idx;
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceStringIds_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  StringIds           [IN/OUT]        Array of string ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 GetSequenceStringIds_Ext(U16 parent_item_id, U16 *StringIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < nCustMenus[parent_item_id - 1].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[parent_item_id - 1].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            StringIds[ret_idx++] = GetStringIdOfItem(nCustMenus[parent_item_id - 1].nOrderMenuItemId[j]);
        }
    }
    return ret_idx;
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceImageIds_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  ImageIds            [IN/OUT]        Array of image ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 GetSequenceImageIds_Ext(U16 parent_item_id, U16 *ImageIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < nCustMenus[parent_item_id - 1].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[parent_item_id - 1].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            ImageIds[ret_idx++] = GetImageIdOfItem(nCustMenus[parent_item_id - 1].nOrderMenuItemId[j]);
        }
    }
    return ret_idx;
}


/*****************************************************************************
 * FUNCTION
 *  GetIndexOfStringId_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  StringId            [IN]        Id of the string
 * RETURNS
 *  U8 index
 *****************************************************************************/
U8 GetIndexOfStringId_Ext(U16 parent_item_id, U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < nCustMenus[parent_item_id - 1].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[parent_item_id - 1].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            if (StringId == nCustMenus[parent_item_id - 1].nOrderMenuItemId[j])
            {
                return (U8) ret_idx;
            }
            ret_idx++;
        }
    }

    return (U8) 0;
}

