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
 *   DevApp_ReadRes.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "string.h"
#include "GlobalMenuItems.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "gui_themes.h"
#include "FontDcl.h"
#ifdef __POPULATE_ENGINE_
#include "ExportMMIFunc.h"
#endif 
#include "DebugInitDef.h"

#include "CustResDef.h"
#include "Gui_Setting.h"
#include "PopulateRes.h"
#include "PlmnEnum.h"
#include "CustDataProts.h"
#include "taskinit.h"
#include "stdafx.h"
#include "buildcfg.h"
#include "fontdcl.h"
#include "SSCStringHandle.h"

extern U16 gCurrLangIndex;
extern const StringResList DevApp_gStringList[];
extern unsigned short DevApp_CurrMaxSearchImageId;
extern const CUSTOM_IMAGE_SEARCH_MAP DevApp_ImageIdSearchMap[];
extern const CUSTOM_IMAGE DevApp_nCustImageNames[];
extern const CUSTOM_IMAGE_MAP DevApp_ImageIdMap[];
extern unsigned short DevApp_CurrMaxSearchAudioId;
extern CUSTOM_AUDIO_SEARCH_MAP DevApp_AudioIdSearchMap[];
extern const CUSTOM_AUDIO DevApp_nCustAudioNames[];
extern const CUSTOM_AUDIO_MAP DevApp_AudioIdMap[];
extern const CUSTOM_MENU      DevApp_nCustMenus[];


/*****************************************************************************
 * FUNCTION
 *  DevAppGetString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  StringId        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *DevAppGetString(U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 nFirst = 0;
    S32 nLast = DevApp_gStringList[gCurrLangIndex].nTotalStrMapSearch;
    S32 nMid;
    CUSTOM_STRMAP_SEARCH *pStrMapSearch;
    CUSTOM_STRING *pStringRes;
    CUSTOM_STRING_MAP *pStringMapRes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pStringRes = DevApp_gStringList[gCurrLangIndex].pStringRes;
    pStringMapRes = DevApp_gStringList[gCurrLangIndex].pStringMap;
    pStrMapSearch = DevApp_gStringList[gCurrLangIndex].pStrMapSearch;

    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((pStrMapSearch[nMid].nMinStrId <= StringId) && (pStrMapSearch[nMid].nMaxStrId >= StringId))
        {
            return (S8*) &pStringRes[(pStringMapRes
                            [((pStrMapSearch[nMid].nMapIndex) + (StringId) - (pStrMapSearch[nMid].nMinStrId))]) << 1];
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
    return (S8*) "";
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *DevAppGetImage(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = DevApp_CurrMaxSearchImageId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;;
        if ((DevApp_ImageIdSearchMap[nMid].minImageId <= ImageId) &&
            (DevApp_ImageIdSearchMap[nMid].maxImageId >= ImageId))
        {

            return (S8*)
                DevApp_nCustImageNames[DevApp_ImageIdMap
                                       [(DevApp_ImageIdSearchMap[nMid].index) + (ImageId) -
                                        (DevApp_ImageIdSearchMap[nMid].minImageId)].nImageNum].pImage;
        }
        if (ImageId > DevApp_ImageIdSearchMap[nMid].minImageId)
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
 *  DevAppGetAudio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  AudioId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *DevAppGetAudio(U16 AudioId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = DevApp_CurrMaxSearchAudioId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((DevApp_AudioIdSearchMap[nMid].minAudioId <= AudioId) &&
            (DevApp_AudioIdSearchMap[nMid].maxAudioId >= AudioId))
        {
            return (S8*)
                DevApp_nCustAudioNames[DevApp_AudioIdMap
                                       [(DevApp_AudioIdSearchMap[nMid].index) + (AudioId) -
                                        (DevApp_AudioIdSearchMap[nMid].minAudioId)].nAudioNum].pAudio;
        }
        if (AudioId > DevApp_AudioIdSearchMap[nMid].minAudioId)
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

/* under construction */


/*****************************************************************************
 * FUNCTION
 *  DevAppGetParentItemId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetParentItemId(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[ItemId - MENU_ID_DEVAPP_START].nParentId;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetNumOfChild
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetNumOfChild(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[ItemId - MENU_ID_DEVAPP_START].nNumofMenuItem;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetStringIdOfItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetStringIdOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[ItemId - MENU_ID_DEVAPP_START].nStrId;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetImageIdOfItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetImageIdOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[ItemId - MENU_ID_DEVAPP_START].nImageId;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetDispAttributeOfItem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetDispAttributeOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[ItemId - MENU_ID_DEVAPP_START].nDispAttribute;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetSeqItemId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevApp_nCustMenus[ParentItemId - MENU_ID_DEVAPP_START].nOrderMenuItemId[Seq];
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemStringId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetSeqItemStringId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DevAppGetStringIdOfItem((U16)(DevApp_nCustMenus[ParentItemId - MENU_ID_DEVAPP_START].nOrderMenuItemId[Seq] + MENU_ID_DEVAPP_START));
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSeqItemImageId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 DevAppGetSeqItemImageId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetImageIdOfItem((U16)(DevApp_nCustMenus[ParentItemId - MENU_ID_DEVAPP_START].nOrderMenuItemId[Seq] + MENU_ID_DEVAPP_START));
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceItemIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ItemIds             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DevAppGetSequenceItemIds(U16 ParentItemId, U16 *ItemIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[ParentItemId - MENU_ID_DEVAPP_START].nNumofMenuItem; j++)
    {
        ItemIds[j] = DevApp_nCustMenus[ParentItemId - MENU_ID_DEVAPP_START].nOrderMenuItemId[j];
    }
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceStringIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringIds           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DevAppGetSequenceStringIds(U16 ParentItemId, U16 *StringIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[ParentItemId  - MENU_ID_DEVAPP_START].nNumofMenuItem; j++)
    {
        StringIds[j] = GetStringIdOfItem(DevApp_nCustMenus[ParentItemId  - MENU_ID_DEVAPP_START].nOrderMenuItemId[j]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetIndexOfStringId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringId            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 DevAppGetIndexOfStringId(U16 ParentItemId, U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[ParentItemId  - MENU_ID_DEVAPP_START].nNumofMenuItem; j++)
    {
        if (StringId == DevApp_nCustMenus[ParentItemId  - MENU_ID_DEVAPP_START].nOrderMenuItemId[j])
        {
            return (U8) j;
        }
    }
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  DevAppGetSequenceImageIds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ImageIds            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void DevAppGetSequenceImageIds(U16 ParentItemId, U16 *ImageIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < DevApp_nCustMenus[ParentItemId  - MENU_ID_DEVAPP_START].nNumofMenuItem; j++)
    {
        ImageIds[j] = GetImageIdOfItem((U16)(DevApp_nCustMenus[ParentItemId  - MENU_ID_DEVAPP_START].nOrderMenuItemId[j] + MENU_ID_DEVAPP_START));
    }
}

