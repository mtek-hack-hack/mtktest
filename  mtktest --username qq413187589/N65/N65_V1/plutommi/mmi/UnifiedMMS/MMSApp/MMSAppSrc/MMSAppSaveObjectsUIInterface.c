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
 *  MMSAppSaveObjectsUIInterface.c
 * 
 * Project:
 * --------
 *  MAUI
 * 
 * Description:
 * ------------
 *  MMS Option 'Save Objects' Related Highlight Handler APIs
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_MMSAPPSAVEOBJECTSUIINTERFACE_C
#define _MMI_MMSAPPSAVEOBJECTSUIINTERFACE_C

#ifdef __MMI_MMS_2__

#include "SettingProfile.h"
#include "MMSAppGprot.h"
#include "MMSAppProt.h"
#include "MMSAppSaveObjects.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_view_attachments
 * DESCRIPTION
 *  Highlight Handler for the Attachment Option in Save Objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_view_attachments(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_menu_id(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_umms_entry_view_attachment, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_entry_view_attachment, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_save_text_object
 * DESCRIPTION
 *  Highlight Handler for the Image Option in Save Objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_save_text_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_menu_id(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_media_as, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_entry_save_media_as, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_save_image_object
 * DESCRIPTION
 *  Highlight Handler for the Image Option in Save Objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_save_image_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_menu_id(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_media_as, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_entry_save_media_as, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_save_audio_object
 * DESCRIPTION
 *  Highlight Handler for the Audio Option in Save Objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_save_audio_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_menu_id(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_media_as, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_entry_save_media_as, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_highlight_save_video_object
 * DESCRIPTION
 *  Highlight Handler for the Video Option in Save Objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_highlight_save_video_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_menu_id(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_media_as, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_umms_entry_save_media_as, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_view_attachment_highlight_hdlr
 * DESCRIPTION
 *  Highlight Handler for the Attachment List
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_view_attachment_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_set_hilite_index(index);
}

#endif /* __MMI_MMS_2__ */

#endif /* _MMI_MMSAPPSAVEOBJECTSUIINTERFACE_C */ 

