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
 *  RightsMgrGenInfo.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  General Infomation screen of Rights Manager  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Include 
 */
#include "MMI_include.h"

#ifdef __MMI_RMGR__

#include "custom_mmi_default_value.h"
#include "RightsMgrProt.h"

#include "App_datetime.h"

/*
 * Global Variable
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_gen_info_entry_main
 * DESCRIPTION
 *  Entry function of the general info main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_gen_info_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *info;
    U32 v = 0;
    kal_wchar tempString[30];
    applib_time_struct time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_RMGR_GEN_INFO_MAIN, NULL, mmi_rmgr_gen_info_entry_main, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_RMGR_GEN_INFO_MAIN);
    
    info = (PU8)subMenuData;

    /* Version */
    v = DRM_get_version();
    mmi_ucs2cpy((PS8)info, (PS8)GetString(STR_ID_RMGR_VERSION));
    
    kal_wsprintf(
        tempString,
        " %d.%d\n",
        (v&0xFFFF0000)>>16,
        (v&0x0000FFFF));
    mmi_ucs2cat((PS8)info, (PS8)tempString);

    /* Time */
    mmi_ucs2cat((PS8)info, (PS8)GetString(STR_ID_RMGR_TIME));
    
    if (DRM_get_secure_time(&time))
    {
        kal_wsprintf(
            tempString,
            " %d/%d/%d\n",
            time.nYear, time.nMonth, time.nDay);
        mmi_ucs2cat((PS8)info, (PS8)tempString);
    }
    else
    {
        mmi_ucs2cat((PS8)info, (PS8)GetString(STR_GLOBAL_NOT_AVAILABLE));
        mmi_ucs2cat((PS8)info, (PS8)L"\n");
    }
    

    /* Status */
    mmi_ucs2cat((PS8)info, (PS8)GetString(STR_ID_RMGR_STATUS));
    mmi_ucs2cat((PS8)info, (PS8)L" ");

    if (DRM_get_trust_state())
    {
        mmi_ucs2cat((PS8)info, (PS8)GetString(STR_GLOBAL_NO));
        
    }
    else
    {
        mmi_ucs2cat((PS8)info, (PS8)GetString(STR_GLOBAL_YES));        
    }
    mmi_ucs2cat((PS8)info, (PS8)L"\n");

    /* Tracking */
    mmi_ucs2cat((PS8)info, (PS8)GetString(STR_ID_RMGR_TRANS));
    mmi_ucs2cat((PS8)info, (PS8)L": ");
    if (DRM_toggle_tracking(MMI_TRUE))
    {
        mmi_ucs2cat((PS8)info, (PS8)GetString(STR_GLOBAL_ON));        
    }
    else
    {
        mmi_ucs2cat((PS8)info, (PS8)GetString(STR_GLOBAL_OFF));        
    }
        
    mmi_ucs2cat((PS8)info, (PS8)L"\n");


    ShowCategory74Screen(
        STR_ID_RMGR,
        mmi_rmgr_get_root_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#endif /* __MMI_RMGR__ */ 

