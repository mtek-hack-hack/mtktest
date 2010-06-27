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
 *  InfoNum.c
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
/**************************************************************

   FILENAME : InfoNum.c

   PURPOSE     : Information Number

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Aug 13,03

**************************************************************/
#include "MMI_include.h"
#include "InfoNum.h"
#include "CommonScreens.h"
#include "CallManagementGprot.h"
#include "GSM7BitDefaultAlphabet.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

static INFONUM GlobalInfoNum[MAX_INFO_NUM_ITEMS + 1];   /* 1 is added for 0th Node */
static INFONUM *info;
static INFONUM *displayInfoNum;
static INFONUM *hiliteInfoNum;

static U8 currentLevel = 0;
static U8 InfoNumHistory[MAX_INFO_NUM_LEVELS];
static U8 hiliteInfoNumIndex;
static U8 saveInfoNum;
static U8 saveInfoNumPremium;
static S8 infoItemCount = (S8) - 1;

static U8 *infoNumberToBeDialed;

U8 isInfoNumPresent = 0;

extern void goto_demo_under_construction(void);


/*****************************************************************************
 * FUNCTION
 *  InfoMalloc
 * DESCRIPTION
 *  Mallocs Information for Info Num from
 *  Global Array
 * PARAMETERS
 *  void
 * RETURNS
 *  Pointer to returned memory
 *****************************************************************************/
INFONUM *InfoMalloc()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infoItemCount++;
    if (infoItemCount == MAX_INFO_NUM_ITEMS + 1)
    {
        return NULL;
    }
    return (&GlobalInfoNum[infoItemCount]);
}


/*****************************************************************************
 * FUNCTION
 *  StoreCurrInfoNum
 * DESCRIPTION
 *  Stores Current Menu at Information Number node passed
 *  as per data from PS
 * PARAMETERS
 *  info        [IN]        Information Number Node wher dats is to be saved
 *  infoNum     [IN]        Info from L4
 * RETURNS
 *  void
 *****************************************************************************/
void StoreCurrInfoNum(INFONUM *info, l4csmu_info_num_struct *infoNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[41 * ENCODING_LENGTH];
    U8 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info->index = infoNum->index_level;
    if (infoNum->alpha_id_size > 21)
    {
        len = 21;
    }
    else
    {
        len = infoNum->alpha_id_size;
    }
    memcpy(temp, infoNum->alpha_id, len);
    temp[len] = 0;
#ifdef __UCS2_ENCODING
    mmi_asc_to_ucs2((PS8) info->alphaId, (PS8) temp);
#else 
    mmi_ucs2cpy(info->alphaId, temp);
#endif 
    if (infoNum->ton_npi != 0xFF)
    {
        if (infoNum->digit_size > 3)
        {
            len = 3;
        }
        else
        {
            len = infoNum->digit_size;
        }
        memcpy(temp, infoNum->digit, len);
        temp[len] = 0;
    #ifdef __UCS2_ENCODING
        mmi_asc_to_ucs2((PS8) info->number, (PS8) temp);
    #else 
        mmi_ucs2cpy(info->number, temp);
    #endif 
    }
    info->nsi = infoNum->network_specific;
    info->psi = infoNum->premium_rate;
}


/*****************************************************************************
 * FUNCTION
 *  InitialiseInformationArray
 * DESCRIPTION
 *  Initialised Information number array
 * PARAMETERS
 *  noInfoNum       [IN]        No of nodes
 *  infoNum         [IN]        Data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void InitialiseInformationArray(U8 noInfoNum, l4csmu_info_num_struct *infoNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j = 0;
    INFONUM *currInfo;
    INFONUM *addInfo;
    INFONUM *currParent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info = InfoMalloc();

    info->parent = NULL;
    info->child = NULL;
    info->next = NULL;
    info->previous = NULL;
    info->index = 0;
    info->noOfChildren = 0;
    mmi_ucs2cpy((PS8) info->alphaId, GetString(SERVICES_INFO_NUM_STRING_ID));
    currParent = info;
    currInfo = info;

    /* StoreCurrInfoNum(info, &infoNum[0]); */

    for (i = 0; i < noInfoNum; i++)
    {
        if (infoNum[i].index_level == 0)
        {
            j++;
            continue; /* invalid index level, skip this one */
        }

        addInfo = InfoMalloc();
        if (addInfo == NULL)
        {
            break;
        }
        if (currInfo->index == infoNum[i].index_level)
        {
            /* Add Sibling of Parent */
            currInfo->next = addInfo;
            currParent->noOfChildren++;
            addInfo->parent = currParent;
            addInfo->previous = currInfo;
            addInfo->next = NULL;
            addInfo->child = NULL;
            addInfo->noOfChildren = 0;

        }
        else if (currInfo->index < infoNum[i].index_level)
        {
            /* Add first Child of Parent */
            currInfo->child = addInfo;
            currParent = currInfo;
            currParent->noOfChildren = 1;
            addInfo->parent = currParent;
            addInfo->previous = NULL;
            addInfo->next = NULL;
            addInfo->child = NULL;
            addInfo->noOfChildren = 0;
        }
        else
        {
            /* Go up one level */
            while (currInfo->index != infoNum[i].index_level)
            {
                currInfo = currInfo->parent;
            }
            currParent = currInfo->parent;

            currInfo->next = addInfo;
            currParent->noOfChildren++;
            addInfo->parent = currParent;
            addInfo->previous = currInfo;
            addInfo->next = NULL;
            addInfo->child = NULL;
            addInfo->noOfChildren = 0;

        }
        StoreCurrInfoNum(addInfo, &infoNum[i]);
        currInfo = addInfo;
    }
    if (i == j)
    {
        isInfoNumPresent = 0;
    }
    else
    {
        isInfoNumPresent = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EnterScrInfoNumber
 * DESCRIPTION
 *  Entry Screen for Information Number App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EnterScrInfoNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currentLevel = 0;
    displayInfoNum = info;
    for (i = 0; i < MAX_INFO_NUM_LEVELS; i++)
    {
        InfoNumHistory[currentLevel] = 0;
    }
    DisplayInformationNumber();
}


/*****************************************************************************
 * FUNCTION
 *  DisplayInformationNumber
 * DESCRIPTION
 *  Entry Screen for each Information Number Screen Level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayInformationNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *Strings[MAX_SUB_MENUS];
    U8 *Hints[MAX_SUB_MENUS];
    INFONUM *currInfo = displayInfoNum;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SERVICES_INFO_NUM_SCREEN_ID, ExitInfoNumScreen, NULL, NULL);

    saveInfoNum = 1;
    nNumofItem = 0;
    currInfo = currInfo->child;
    Strings[nNumofItem] = currInfo->alphaId;
    Hints[nNumofItem] = hintData[nNumofItem];
    if (currInfo->child)
    {
        Hints[nNumofItem] = NULL;
    }
    else
    {
        Hints[nNumofItem] = currInfo->number;
    }
    nNumofItem++;
    /* micha0202, remove compile warning */
    currInfo = currInfo->next;
    while (currInfo)    /* Ignore the warning, intentional */
    {
        Strings[nNumofItem] = currInfo->alphaId;
        if (currInfo->child)
        {
            Hints[nNumofItem] = NULL;
        }
        else
        {
            Hints[nNumofItem] = currInfo->number;
        }
        nNumofItem++;
        currInfo = currInfo->next;
    }
    RegisterHighlightHandler(InfoNumberScrHiliteHandler);
    displayInfoNum = displayInfoNum->child;
    ShowCategory53Screen(
        SERVICES_INFO_NUM_STRING_ID,
        SERVICES_INFO_NUM_IMAGE_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        Strings,
        (PU16) gIndexIconsImageList,
        Hints,
        LIST_MENU,
        InfoNumHistory[currentLevel],
        0);
    SetLeftSoftkeyFunction(GoAheadInfoNum, KEY_EVENT_UP);
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(GoAheadInfoNum, KEY_EVENT_UP);
#else /* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(GoAheadInfoNum, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    SetRightSoftkeyFunction(GoBackInfoNum, KEY_EVENT_UP);
    SetKeyHandler(GoBackInfoNum, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  InfoNumberScrHiliteHandler
 * DESCRIPTION
 *  Hilite Handler for each Information Number Screen Level
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void InfoNumberScrHiliteHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hiliteInfoNumIndex = (U8) index;
    hiliteInfoNum = displayInfoNum;
    for (i = 0; i < index; i++)
    {
        hiliteInfoNum = hiliteInfoNum->next;
    }
    if (hiliteInfoNum->noOfChildren)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(SERVICES_INFO_DIAL_STRING_ID, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoAheadInfoNum
 * DESCRIPTION
 *  LSK Handler for each Information Number Screen Level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoAheadInfoNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hiliteInfoNum->noOfChildren)
    {
        if (hiliteInfoNum->nsi && mmi_bootup_is_roaming() == MMI_TRUE)
        {
            DisplayRoamingInfoNum();
        }
        else
        {
            saveInfoNum = 0;
            displayInfoNum = hiliteInfoNum;
            InfoNumHistory[currentLevel] = hiliteInfoNumIndex;
            currentLevel++;
            DisplayInformationNumber();
        }
    }
    else
    {
        infoNumberToBeDialed = hiliteInfoNum->number;
        if (hiliteInfoNum->nsi && mmi_bootup_is_roaming() == MMI_TRUE)
        {
            DisplayRoamingInfoNum();
        }
        else if (hiliteInfoNum->psi)
        {
            DisplayPremimumInfoNum();
        }
        else
        {
            MakeCall((PS8) infoNumberToBeDialed);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackInfoNum
 * DESCRIPTION
 *  RSK Handler for each Information Number Screen Level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackInfoNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currentLevel)
    {
        saveInfoNum = 0;
        InfoNumHistory[currentLevel] = 0;
        currentLevel--;
        displayInfoNum = hiliteInfoNum->parent->parent;
        DisplayInformationNumber();
    }
    else
    {
        displayInfoNum = info;
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitInfoNumScreen
 * DESCRIPTION
 *  Exit Handler for each Information Number Screen Level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitInfoNumScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (saveInfoNum)
    {
        history currHistory;
        S16 nHistory = 0;

        displayInfoNum = hiliteInfoNum->parent;
        InfoNumHistory[currentLevel] = hiliteInfoNumIndex;
        currHistory.scrnID = SERVICES_INFO_NUM_SCREEN_ID;
        currHistory.entryFuncPtr = DisplayInformationNumber;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayPremimumInfoNum
 * DESCRIPTION
 *  Displays Premium Info Number Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayPremimumInfoNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SERVICES_INFO_PREMIUM_SCREEN_ID, ExitDisplayPremimumInfoNum, NULL, NULL);

    saveInfoNumPremium = 1;
    ShowCategory2Screen(
        SERVICES_INFO_NUM_STRING_ID,
        SERVICES_INFO_NUM_IMAGE_ID,
        SERVICES_INFO_DIAL_STRING_ID,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        SERVICES_INFO_PREMIUM_STRING_ID,
        NULL);
    SetLeftSoftkeyFunction(DisplayPremimumInfoNumOK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ExitDisplayPremimumInfoNum
 * DESCRIPTION
 *  Exit Handler for Premium Info Number Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitDisplayPremimumInfoNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (saveInfoNumPremium)
    {
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SERVICES_INFO_PREMIUM_SCREEN_ID;
        currHistory.entryFuncPtr = DisplayPremimumInfoNum;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
        AddHistory(currHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayPremimumInfoNumOK
 * DESCRIPTION
 *  LSK Handler for Premium Info Number Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayPremimumInfoNumOK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    saveInfoNumPremium = 0;
    MakeCall((PS8) infoNumberToBeDialed);
}


/*****************************************************************************
 * FUNCTION
 *  DisplayRoamingInfoNum
 * DESCRIPTION
 *  Entry function for Roaming Info Number Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayRoamingInfoNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SERVICES_INFO_ROAMING_SCREEN_ID, NULL, DisplayRoamingInfoNum, NULL);

    saveInfoNumPremium = 1;
    ShowCategory2Screen(
        SERVICES_INFO_NUM_STRING_ID,
        SERVICES_INFO_NUM_IMAGE_ID,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        SERVICES_INFO_ROAMING_STRING_ID,
        NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

