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
 *  PhotoEditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PhotoEditor Source
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_PHOTOEDITOR__


#include "nvram_data_items.h"
#include "gui.h"        /* Gui functions */
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "wgui.h"       /* for GetDateTime() */
#include "CommonScreens.h"      /* DisplayPopup() */
#include "FileManagerDef.h"
#include "FileManagerGProt.h"   /* file path */
#include "FileMgr.h"
#include "lcd_sw_rnd.h" /* lcd size and color format */
#include "USBDeviceGprot.h"     /* USB MS mode */

#include "PhotoEditor.h"
#include "PhotoEditorGProt.h"
#include "PhoEdtResDef.h"
#include "PhotoArt.h"

#ifdef __PHOEDT_USE_APP_ASM__
#endif

#ifdef __PHOEDT_FEATURE_PHOART__

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern void mmi_phoart_init_app(void);
extern void mmi_scenmast_init_app(void);
extern void mmi_imgtile_init_app(void);

/*****************************************************************************
* Local Vairable                                                           
*****************************************************************************/
phoedt_cntx_struct g_phoedt_cntx;

#ifdef __PHOEDT_USE_APP_ASM__
PU8 g_phoedt_interrupt_buffer;
PU8 g_phoedt_original_buffer;
#else
U8 g_phoedt_interrupt_buffer[PHOEDT_FRAME_BUFFER_SIZE];
U8 g_phoedt_original_buffer[PHOEDT_FRAME_BUFFER_SIZE];
#endif /* __PHOEDT_USE_APP_ASM__ */
/*****************************************************************************
* Local Function                                                           
*****************************************************************************/
/* Photo Editor Applcation */
static void mmi_phoedt_hilight_app(void);
static void mmi_phoedt_entry_app_screen(void);
#ifdef __PHOEDT_USE_APP_ASM__
static U8 mmi_phoedt_del_scr_callback(void* ptr);
#endif
/*****************************************************************************
*
* Photo Editor Applcation                                                           
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_init_app
 * DESCRIPTION
 *  init photo editor applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phoedt_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_PHOEDT_APP, mmi_phoedt_hilight_app);

#ifdef __PHOEDT_FEATURE_PHOART__
    mmi_phoart_init_app();
#endif 

#ifdef __PHOEDT_FEATURE_SCENMAST__
    mmi_scenmast_init_app();
#endif 

#ifdef __PHOEDT_FEATURE_IMGTILE__
    mmi_imgtile_init_app();
#endif 

#ifdef __PHOEDT_USE_APP_ASM__
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_PHOEDT,
        STR_ID_PHOEDT_APP_NAME,
        IMG_ID_PHOEDT_APP_ICON,
        mmi_phoedt_stop_callback);
    g_phoedt_interrupt_buffer = NULL;
    g_phoedt_original_buffer = NULL;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_hilight_app
 * DESCRIPTION
 *  hilight phoedt menu item hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phoedt_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_phoedt_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_phoedt_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_entry_app_screen
 * DESCRIPTION
 *  entry photo editor applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_phoedt_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *guiBuffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
        /* block usb mass storage mode */
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* in mass storage mode */
            if (mmi_usb_check_path_exported((PS8) L"root"))
            {
                /* phone drive is exported, cant use this app */
                mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                return;
            }
        }
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __PHOEDT_USE_APP_ASM__
    if (NULL == g_phoedt_interrupt_buffer && NULL == g_phoedt_original_buffer)
    {
        if (!mmi_phoedt_alloc_app_asm())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                STR_ID_PHOEDT_APP_NAME,
                IMG_ID_PHOEDT_APP_ICON,
                PHOEDT_FRAME_BUFFER_SIZE<<1,
                mmi_phoedt_entry_app_screen);
            return;
        }
    }
#endif /* __PHOEDT_USE_APP_ASM__ */

    EntryNewScreen(SCR_ID_PHOEDT_APP, NULL, mmi_phoedt_entry_app_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_PHOEDT_APP);
   
    num_item = GetNumOfChild(MENU_ID_PHOEDT_APP);
    GetSequenceStringIds(MENU_ID_PHOEDT_APP, item_list);
    GetSequenceImageIds(MENU_ID_PHOEDT_APP, item_icons);
    SetParentHandler(MENU_ID_PHOEDT_APP);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_PHOEDT_APP, popup_list);

    ShowCategory52Screen(
        STR_ID_PHOEDT_APP_NAME,
        GetRootTitleIcon(MENU_ID_PHOEDT_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#ifdef __PHOEDT_USE_APP_ASM__
    SetDelScrnIDCallbackHandler(SCR_ID_PHOEDT_APP, mmi_phoedt_del_scr_callback);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_load_data
 * DESCRIPTION
 *  load photo artist's data from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phoedt_load_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded, avoid load again to save time */

    ReadRecord(
        NVRAM_EF_PHOTO_EDITOR_SETTING_LID,
        1,
        (void*)&g_phoedt_cntx.setting_data,
        NVRAM_EF_PHOTO_EDITOR_SETTING_SIZE,
        &error);

    /* first time init */
    if (g_phoedt_cntx.setting_data.pa_text_color == 0xffffffff)
    {
        memset(g_phoedt_cntx.setting_data.pa_add_text_string, 0, sizeof(g_phoedt_cntx.setting_data.pa_add_text_string));

        mmi_ucs2cpy(g_phoedt_cntx.setting_data.pa_add_text_string, (PS8) L"Hello!");

        g_phoedt_cntx.setting_data.pa_text_color = 0;
        g_phoedt_cntx.setting_data.pa_border_color = 0;
        g_phoedt_cntx.setting_data.pa_shadow_color = 0;
        g_phoedt_cntx.setting_data.pa_text_size = 1;    /* mediun */
        g_phoedt_cntx.setting_data.pa_text_italic = 0;

        g_phoedt_cntx.setting_data.ss_type_of_play = 0;
        g_phoedt_cntx.setting_data.ss_speed = 1;
        g_phoedt_cntx.setting_data.ss_effect = 0;
        g_phoedt_cntx.setting_data.ss_bgm = 0;
        g_phoedt_cntx.setting_data.ss_horz = 0;
        g_phoedt_cntx.setting_data.ss_sound_effect = 0;

        mmi_phoedt_store_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_store_data
 * DESCRIPTION
 *  load photo artist's data from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phoedt_store_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PHOTO_EDITOR_SETTING_LID,
        1,
        (void*)&g_phoedt_cntx.setting_data,
        NVRAM_EF_PHOTO_EDITOR_SETTING_SIZE,
        &error);
}


#ifdef __PHOEDT_USE_APP_ASM__
/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_alloc_app_asm
 * DESCRIPTION
 *  allocate memory from app asm's pool
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL        TRUE if memory is successfully allocated
 *****************************************************************************/
BOOL mmi_phoedt_alloc_app_asm(void)
{
    PU8 p_appmem_buf;
    
    p_appmem_buf = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_PHOEDT, PHOEDT_FRAME_BUFFER_SIZE << 1 );
    if (p_appmem_buf)
    {
        g_phoedt_interrupt_buffer = p_appmem_buf;
        g_phoedt_original_buffer = (p_appmem_buf+PHOEDT_FRAME_BUFFER_SIZE);
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_free_app_asm
 * DESCRIPTION
 *  free app based ASM used by photoeditor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phoedt_free_app_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_phoedt_interrupt_buffer);
    applib_mem_ap_free(g_phoedt_interrupt_buffer);
    g_phoedt_interrupt_buffer = NULL;
    g_phoedt_original_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of photoeditor applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_phoedt_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phoedt_free_app_asm();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phoedt_stop_callback
 * DESCRIPTION
 *  stop the program for app_based_memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_phoedt_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DeleteUptoScrID(SCR_ID_PHOEDT_APP);
    DeleteScreenIfPresent(SCR_ID_PHOEDT_APP);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_PHOEDT, KAL_TRUE);
}

#endif /* __PHOEDT_USE_APP_ASM__ */

#endif /* __PHOEDT_FEATURE_PHOART__ */ 
#endif /* __MMI_PHOTOEDITOR__ */ 

