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
 *  Help.c
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

   FILENAME : Helpc.h

   PURPOSE     : 

   REMARKS     : nil

   AUTHOR      : Manish Vohra

   DATE     : 12/03/03

**************************************************************/

#include "MMI_include.h"
#include "HelpResDef.h"
#include "HelpProt.h"
#include "HelpDcl.h"


/*****************************************************************************
 * FUNCTION
 *  InitHelp
 * DESCRIPTION
 *  Initialize Help
 *  
 *  Call this function at boot up time find
 *  help is enabled or not,
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;
    S32 status = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsHelpEnabled = 1;
    status = ReadValue(NVRAM_HELP_ENABLED_FLAG, &gIsHelpEnabled, DS_BYTE, &error);
    if (error != NVRAM_READ_SUCCESS)
    {
        PRINT_INFORMATION("[InitHelp] NVRAM READ FAILURE ");
    }

}


/*****************************************************************************
 * FUNCTION
 *  SetHelpEnableFlag
 * DESCRIPTION
 *  Set a global variable
 *  
 *  This function is called by organizer when help is
 *  made set in the Radio Button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetHelpEnableFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gIsHelpEnabled = 1;

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreenShowHelp
 * DESCRIPTION
 *  Entry function for Help Dispplay Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreenShowHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 currScrenID = 0;
    U16 stringID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currScrenID = GetCurrScreenID();
    stringID = GetHelpStringID(currScrenID);
    /* JL remove ExecuteCurrExitHandler(); */
    EntryNewScreen(SCR_HELP, NULL, EntryScreenShowHelp, NULL);
    ShowCategory21Screen(STR_HELP_CAPTION, 0, 0, 0, STR_GLOBAL_OK, 0, stringID, NULL);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* JL remove SetExitHandler(SCR_HELP,ExitScreenShowHelp); */

}


/*****************************************************************************
 * FUNCTION
 *  ExitScreenShowHelp
 * DESCRIPTION
 *  Exit function for Help Dispplay Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScreenShowHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_HELP;
    h.entryFuncPtr = EntryScreenShowHelp;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  ShowHelp
 * DESCRIPTION
 *  Call back when phone is left idle for
 *  some time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 stringID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stringID = GetCurrScreenID();
    if (stringID)
    {
        EntryScreenShowHelp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EnableHelp
 * DESCRIPTION
 *  Needs to be called in the entry functions
 *  for which help needs to be displayed
 * PARAMETERS
 *  ScrnID          [IN]        
 *  ScreenID(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EnableHelp(U16 ScrnID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrScreenID = ScrnID;
    StartTimer(HELP_APPLICATION_TIMER, HELP_APPLICATION_TIMEOUT, ShowHelp);
}


/*****************************************************************************
 * FUNCTION
 *  DisableHelp
 * DESCRIPTION
 *  Needs to be called from the exit functions
 *  of screens for which help needs to be displayed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisableHelp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gCurrScreenID = 0;
    StopTimer(HELP_APPLICATION_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrScreenID
 * DESCRIPTION
 *  return the current Screen ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetCurrScreenID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gCurrScreenID;
}


/*****************************************************************************
 * FUNCTION
 *  GetHelpStringID
 * DESCRIPTION
 *  return the current STRING ID
 *  corresponding to the screen ID
 * PARAMETERS
 *  currScrenID     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetHelpStringID(U16 currScrenID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 count = gMaxHelpStrings;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MTK added by JL to avoid the infinite loop
    //for(count; count >= 0; --count)
    for (count = 0; count < gMaxHelpStrings; count++)
    {

        if (HelpArrMap[count].ScreenID == currScrenID)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        return HelpArrMap[count].StringID;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  AddScreenHelp
 * DESCRIPTION
 *  Fills the HelpArrMap
 * PARAMETERS
 *  ScreenID        [IN]        
 *  StringID        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AddScreenHelp(U16 ScreenID, U16 StringID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 count;
    U8 flag = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < gMaxHelpStrings; ++count)
    {

        if (HelpArrMap[count].ScreenID == ScreenID)
        {
            flag = 0;
            break;
        }

    }
    if (flag)
    {
        HelpArrMap[gMaxHelpStrings].ScreenID = ScreenID;
        HelpArrMap[gMaxHelpStrings].StringID = StringID;
        ++gMaxHelpStrings;
    }

}

