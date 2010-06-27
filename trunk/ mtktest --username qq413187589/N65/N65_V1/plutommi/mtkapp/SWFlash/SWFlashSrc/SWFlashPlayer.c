/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * SWFlashPlayer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of swflash player
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_SWFLASH__
#ifdef SWFLASH_NEOMTEL

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"
#include "SettingProfile.h"

/* Mime type */
#include "app_mine.h"

/* File and Memory */
#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "rtfiles.h"
#include "med_smalloc.h"
#include "med_api.h"
/* Data Account */
#include "DataAccountGProt.h"
#include "DataAccountDef.h"
#include "wapadp.h"
#include "wap_ps_struct.h"

/* MDI */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_swflash.h"
#include "mdi_include.h"

/* NVRAM */

/* mmi_chset */
#include "Conversions.h"

/* Setting */
#include "SettingDefs.h"

/* Download Agent */
#include "DLAgentResDef.h"
#include "SettingProfile.h"

/* Silent or Meeting Mode */
#include "ProfileGprots.h"

/* LED */
#include "gpioInc.h"            

/*sim card*/
#include "simDetectionGprot.h"


#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h" 
#endif 

/* SWFlash */
#include "SWFlashGProt.h"
#include "SWFlashProt.h"
#include "SWFlashDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_SWFLASH_KEY_NUMBER (18)

/***************************************************************************** 
* Local Variable
*****************************************************************************/
typedef struct
{
    
    U8 volume;
    S8 *printable_str;
    MMI_BOOL is_load_setting;            /*if setting load is ready*/
    MMI_BOOL is_zdd;                     /*if the works is zdd file*/
    U8 srcAPP;                           /*indicate the command come from 
                                           0: filemgr 1: my favorite 2:other*/   
    MMI_BOOL is_nexturl_on;        /*if player will go to next url or not*/

    S16 layer_offset_x;
    S16 layer_offset_y;
    S16 layer_width;
    S16 layer_height;
    U16 swflash_cmp_full_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];

    gdi_handle swflash_play_layer;
    gdi_handle swflash_base_layer;
} mmi_swflash_context_struct;

static mmi_swflash_context_struct g_swflash_cntx;


/***************************************************************************** 
* Extern Variable
*****************************************************************************/
extern mdi_swflash_info_struct wgui_swflash_info;

/*****************************************************************************
* Local function                                                     
*****************************************************************************/

static void mmi_swflash_play_callback(MDI_RESULT result);
static void mmi_swflash_play_status(mdi_swflash_pl_state_enum state);

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_init_app
 * DESCRIPTION
 *  init video player applcation, register highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_swflash_cntx.is_load_setting = MMI_FALSE;
    g_swflash_cntx.is_zdd = MMI_FALSE;
    g_swflash_cntx.is_nexturl_on = MMI_FALSE;
    g_swflash_cntx.printable_str=NULL;
    mmi_swflash_load_setting();
    mdi_swflash_init();
    mmi_swflash_dl_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_load_setting
 * DESCRIPTION
 *  load setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S8 IMEIbuf[(15 + 1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swflash_cntx.is_load_setting)
    {
        return;
    }

    g_swflash_cntx.is_load_setting = MMI_TRUE;

    /* volume setting */
    ReadValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_IMEI_IMEISV_LID, 1, IMEIbuf, (15 + 1) * ENCODING_LENGTH, &error);

    mdi_swflash_set_imei(IMEIbuf);
    if (g_swflash_cntx.volume == 0xff)
    {
        g_swflash_cntx.volume = 4;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_file_full_path
 * DESCRIPTION
 *  set the file full path 
 * PARAMETERS
 *  path:the folder path 
 *  filename: the file name(not the full name)
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_swflash_set_file_full_path(const S8 *path,const S8 * filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cpy((PS8)g_swflash_cntx.swflash_cmp_full_path,path); 
    mmi_ucs2cat((PS8) g_swflash_cntx.swflash_cmp_full_path, (PS8) filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_menuId
 * DESCRIPTION
 *  Callback function from file manaegr
 * PARAMETERS
 *  filename        [?]         
 *  forward         [IN]        
 *  fullname        [?]         (Full path name of the file )(?)
 * RETURNS
 *  void
 *****************************************************************************/
 U16 mmi_swflash_get_menuId(void *filename, FMGR_FILE_INFO_STRUCT *info,MMI_BOOL forward,U8 src_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filefullname[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
    MDI_RESULT ret;
    U32 total_len = 0;
    U32 current_len = 0;
    U32 category = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filefullname passed from FileMgr is full file name, path included */
        
    mmi_ucs2cpy((PS8) filefullname, (PS8) filename);
    
    if(src_app == APP_FILEMANAGER)
    {
        g_swflash_cntx.srcAPP = 0;
    }
    else if(src_app == APP_MYFAVORITE)  
    {
        g_swflash_cntx.srcAPP = 1;
    }
    else
    {
        g_swflash_cntx.srcAPP = 2;
    
    }


    if(FMGR_FILTER_IS_SET(&info->file_type,FMGR_TYPE_CMP))
    {
        switch (g_swflash_cntx.srcAPP)
        {
            case 0: if(forward == MMI_TRUE)
                    {
                        return MITEM_FMGR_GEN_TYPE_OPTIONS;
                    }
                    else
                    {
                        return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;
                    }
                    break;
            case 1: return MENU_ID_SWFLASH_FAVORITE_FLIGHT;
                    break;
            default:if(forward == MMI_TRUE)
                    {
                        return MENU_ID_SWFLASH_LIST;
                    }
                    else
                    {
                        return MENU_ID_SWFLASH_SETTING_STORAGE;
                    }
                    break;
        }
    }
    /*check if the file is complete ,undemanged,size is reasonable*/
    ret = mdi_swflash_check_download_file((U16*) filefullname, &total_len, &current_len, &category);

    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        switch (g_swflash_cntx.srcAPP)
        {
            case 0: return MITEM_FMGR_GEN_TYPE_NO_SIM_OPTIONS;
                    break;
            case 1: return MENU_ID_SWFLASH_FAVORITE_FLIGHT;
                    break;
            default:return MENU_ID_SWFLASH_SETTING_STORAGE;
                    break;
        }
    }
    /*check if is zdd file*/
    if (FMGR_FILTER_IS_SET(&info->file_type,FMGR_TYPE_ZDD))
    {
        mmi_ucs2cpy((S8*) g_swflash_cntx.swflash_cmp_full_path, (S8*) filefullname);
        if ((mmi_bootup_get_active_flight_mode()==MMI_TRUE)||(mmi_bootup_is_sim_valid()==MMI_FALSE))
        {   
            g_swflash_cntx.is_zdd = MMI_TRUE;
            switch (g_swflash_cntx.srcAPP)
            {
                case 0: return MENU_ID_SWFLASH_OPTION2_FLIGHT;
                        break;
                case 1: return MENU_ID_SWFLASH_FAVORITE_FLIGHT;
                        break;
                default:return MENU_ID_SWFLASH_STORAGE_PHONE;
                        break;
            }
        }
        else
        {
            g_swflash_cntx.is_zdd = MMI_TRUE;
            switch (g_swflash_cntx.srcAPP)
            {
                case 0: return MENU_ID_SWFLASH_OPTION2;
                        break;
                case 1: return MENU_ID_SWFLASH_FAVORITE_DOWNLOAD;
                        break;
                default:return MENU_ID_SWFLASH_STORAGE_CARD;
                        break;
            }
        }
    }
    else
    {
        g_swflash_cntx.is_zdd = MMI_FALSE;
    }

    /*check play file status*/
    if (total_len > 0)
    {
       if(current_len == total_len)
        {
            /* can be used for playback */
            mmi_ucs2cpy((S8*) g_swflash_cntx.swflash_cmp_full_path, (S8*) filefullname);
            if (FMGR_FILTER_IS_SET(&info->file_type,FMGR_TYPE_VIS))
            {
                /*.vis total four digit*/
                mmi_ucs2ncpy((S8*)wgui_swflash_info.title,info->file_name,mmi_ucs2strlen((S8*)info->file_name)-4);
            }
            else
            {
                /*.ivis,mvis,kvis total five digit*/
                mmi_ucs2ncpy((S8*)wgui_swflash_info.title,info->file_name,mmi_ucs2strlen((S8*)info->file_name)-5);
            }
            /*store works date ,time ,size*/
            date_string(&(info->time), (PU16) & (wgui_swflash_info.date), DT_IDLE_SCREEN);
            time_string(&(info->time), (PU16) & (wgui_swflash_info.time), DT_IDLE_SCREEN);
            wgui_swflash_info.size = info->file_size;
            
            if (forward == MMI_TRUE)
            {
                switch (g_swflash_cntx.srcAPP)
                {
                    case 0: return MENU_ID_SWFLASH_OPTION1;
                            break;
                    case 1: return MENU_ID_SWFLASH_FAVORITE_OPTION;
                            break;
                    default:return MENU_ID_SWFLASH_SETTING_DATACNT;
                            break;
                }
            }
            else
            {
                switch (g_swflash_cntx.srcAPP)
                {
                    case 0: return MENU_ID_SWFLASH_OPTION1_NO_FORWARD;
                            break;
                    case 1: return MENU_ID_SWFLASH_FAVORITE_NO_FORWARD;
                            break;
                    default:return MENU_ID_SWFLASH_SETTING;
                            break;
                }
            }
        }
        else
        {
            return MENU_ID_SWFLASH_SETTING_STORAGE;
        }
    }
    else
    {
        return MENU_ID_SWFLASH_SETTING_STORAGE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_category
 * DESCRIPTION
 *  Callback function from file manaegr
 * PARAMETERS
 *  filename        [?]     
 *  downloaded      [?]     
 *  fullname        [?]         (Full path name of the file )(?)
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_swflash_get_category(void *filename, S32 *downloaded,FMGR_FILTER *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filefullname passed from FileMgr is full file name */
  
    *downloaded = 1;
    if (FMGR_FILTER_IS_SET(type,FMGR_TYPE_VIS))
    {
        return 1;  /*animation*/
    }
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_IVIS))
    {
        return 3;  /*game*/
    }
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_KVIS))
    {
        return 5;  /*kalaok*/
    }
    
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_MVIS))
    {
        return 7;  /*move clip*/
    }
    
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_ZDD))
    {
        return 9;  /*describle file*/
    } 
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_press_inc_volume
 * DESCRIPTION
 *  increase volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int silent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    silent = IsSilentModeActivated() || IsMeetingModeActivated();
    if (!silent && g_swflash_cntx.volume < 6)
    {
        S16 error;

        if (g_swflash_cntx.volume == 0)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);
            g_swflash_cntx.volume++;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
        else
        {
            g_swflash_cntx.volume++;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_press_dec_volume
 * DESCRIPTION
 *  depress the volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int silent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    silent = IsSilentModeActivated() || IsMeetingModeActivated();

    if (!silent && g_swflash_cntx.volume > 0)
    {
        S16 error;

        if (g_swflash_cntx.volume == 1)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
            g_swflash_cntx.volume--;
        }
        else
        {
            g_swflash_cntx.volume--;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }

        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_sms_interrupt_hdlr
 * DESCRIPTION
 *  the preprocess function of sms interrupt
 * PARAMETERS
 *  inMsg: the message come from framework
 * RETURNS
 *  void
 *****************************************************************************/

static U8 mmi_swflash_sms_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_TONE_ON);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_key_down
 * DESCRIPTION
 *  set_key down handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mdi_swflash_key_down_event(Keycode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_key_up
 * DESCRIPTION
 *  set_key up handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mdi_swflash_key_up_event(Keycode);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_key_handle
 * DESCRIPTION
 *  set_key_handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_set_key_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 swFlashScreenDigits[MMI_SWFLASH_KEY_NUMBER] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
        KEY_6,KEY_7, KEY_8, KEY_9, KEY_STAR,KEY_POUND,KEY_UP_ARROW,KEY_DOWN_ARROW,KEY_RIGHT_ARROW,KEY_LEFT_ARROW,
        KEY_ENTER,KEY_SEND};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    SetGroupKeyHandler(mmi_swflash_key_down, swFlashScreenDigits, MMI_SWFLASH_KEY_NUMBER, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_swflash_key_up, swFlashScreenDigits, MMI_SWFLASH_KEY_NUMBER, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_post_interrupt_hdlr
 * DESCRIPTION
 *  the post function of sms interrupt
 * PARAMETERS
 *  inMsg:the message come from framework
 * RETURNS
 *  void
 *****************************************************************************/

static U8 mmi_swflash_post_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_ON);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_interrupt_handler
 * DESCRIPTION
 * set_interrupt_handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_swflash_set_interrupt_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS, 
            mmi_swflash_sms_interrupt_hdlr,
        mmi_swflash_post_interrupt_hdlr);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_reset_interrupt_handler
 * DESCRIPTION
 * set_interrupt_handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_swflash_reset_interrupt_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wivg_render
 * DESCRIPTION
 *  callback function for category227
 * PARAMETERS
 *  coordinate      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_wivg_render(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* width and height need to assign before open_file for create buffer */
    g_swflash_cntx.layer_offset_x = coordinate->s16X;
    g_swflash_cntx.layer_offset_y = coordinate->s16Y;
    g_swflash_cntx.layer_width = coordinate->s16Width;
    g_swflash_cntx.layer_height = coordinate->s16Height;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_pen_event
 * DESCRIPTION
 *  touch screen callback function for category227
 * PARAMETERS
 *  pen_event      [in]     type of pen event
 *  point          [in]     coordinate of pen
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL  mmi_swflash_pen_event(mmi_pen_event_type_enum pen_event,mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    switch(pen_event)
    {
    case MMI_PEN_EVENT_DOWN:
        return mdi_swflash_pen_down_event(point);
        break;
    case MMI_PEN_EVENT_UP:
        return mdi_swflash_pen_up_event(point);
        break;
    case MMI_PEN_EVENT_MOVE:
        return mdi_swflash_pen_move_event(point);
        break;
    default:break;
    }
#endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_play_screen_delete_callback
 * DESCRIPTION
 *  this function is the callback function when swflash play screen is deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_swflash_play_screen_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.is_nexturl_on = MMI_FALSE;
    mmi_swflash_set_save_file(MMI_TRUE);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_entry_screen
 * DESCRIPTION
 *  the entry function of swflash play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_ENTRY_PLAY);
    mdi_swflash_set_is_from_player(MMI_TRUE);
    EntryNewScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play_exit_screen, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
    /* stop lcd sleep */
    TurnOnBacklight(0);
    /* stop LED patten */
    StopLEDPatternBackGround();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, VIS_PLAYER, &wgui_swflash_info);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }

  
    /* pause sound */
    mdi_audio_suspend_background_play();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    if (g_swflash_cntx.volume == 0)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
    }

    /*begin show category*/
    gdi_layer_lock_frame_buffer();          /*wait for decode ready*/

    ShowCategory227Screen(
        (PU8) GetString(STR_ID_SWFLASH_PLAYBACK),
        IMG_ID_SWFLASH_APP2,
        STR_ID_SWFLASH_PAUSE,
        0,
        STR_ID_SWFLASH_STOP,
        0,
        mmi_swflash_wivg_render,
        mmi_swflash_pen_event);

  
    /* create swflash layer on layer 1 */
    gdi_layer_multi_layer_enable();
    g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    
    gdi_layer_create(
        g_swflash_cntx.layer_offset_x,
        g_swflash_cntx.layer_offset_y,
        g_swflash_cntx.layer_width,
        g_swflash_cntx.layer_height,
        &g_swflash_cntx.swflash_play_layer);
    ASSERT(g_swflash_cntx.swflash_play_layer != GDI_LAYER_EMPTY_HANDLE);

    gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();

    gdi_layer_get_base_handle(&g_swflash_cntx.swflash_base_layer);
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, g_swflash_cntx.swflash_play_layer, 0, 0);

    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, MDI_DEVICE_SPEAKER2, mmi_swflash_play_callback);
    gdi_layer_unlock_frame_buffer();             /*decode ready*/

    gdi_layer_blt_previous(
               g_swflash_cntx.layer_offset_x - 1,
               g_swflash_cntx.layer_offset_y - 1,
               g_swflash_cntx.layer_width+ g_swflash_cntx.layer_offset_x,
               g_swflash_cntx.layer_height+ g_swflash_cntx.layer_offset_y);
    
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }
  
    /*for interaction*/
    mmi_swflash_set_key_handle();
    SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_OPTION_PLAY, (HistoryDelCBPtr)mmi_swflash_play_screen_delete_callback);
    /* Register function with right softkey */
    SetKeyHandler(mmi_swflash_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_swflash_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PLAY);
    mmi_swflash_set_interrupt_handler();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play2_entry_screen
 * DESCRIPTION
 *  the reenry function of swflash play,mainly for the re-entry of interrupted 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play2_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_ENTRY_PLAY2);
    mdi_swflash_set_is_from_player(MMI_TRUE);
    /* stop lcd sleep */
    TurnOnBacklight(0);
    /* stop LED patten */
    StopLEDPatternBackGround();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    EntryNewScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play_exit_screen, NULL, NULL);
    
    gdi_layer_lock_frame_buffer();          /*wait for decode ready*/


    ShowCategory227Screen(
        (PU8) GetString(STR_ID_SWFLASH_PLAYBACK),
        IMG_ID_SWFLASH_APP2,
        STR_ID_SWFLASH_PLAY,
        0,
        STR_GLOBAL_BACK,
        0,
        mmi_swflash_wivg_render,
		mmi_swflash_pen_event
      );

    /* pause sound */
    mdi_audio_suspend_background_play();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    if (g_swflash_cntx.volume == 0)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
    }

    /* create swflash layer on layer 1 */
    gdi_layer_multi_layer_enable();
    ASSERT(g_swflash_cntx.swflash_play_layer == GDI_LAYER_EMPTY_HANDLE);
    
    g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    gdi_layer_create(
        g_swflash_cntx.layer_offset_x,
        g_swflash_cntx.layer_offset_y,
        g_swflash_cntx.layer_width,
        g_swflash_cntx.layer_height,
        &g_swflash_cntx.swflash_play_layer);
    gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_layer_get_base_handle(&g_swflash_cntx.swflash_base_layer);
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, g_swflash_cntx.swflash_play_layer, 0, 0);

    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, VIS_PLAYER, &wgui_swflash_info);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }

    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, 0xFF, mmi_swflash_play_callback);
    gdi_layer_unlock_frame_buffer();          /*decode ready*/

    gdi_layer_blt_previous(
               g_swflash_cntx.layer_offset_x - 1,
               g_swflash_cntx.layer_offset_y - 1,
               g_swflash_cntx.layer_width+ g_swflash_cntx.layer_offset_x,
               g_swflash_cntx.layer_height+ g_swflash_cntx.layer_offset_y);
    
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE); 
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        return;
    }
    /*for interaction*/
    mmi_swflash_set_key_handle();
    SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_OPTION_PLAY, (HistoryDelCBPtr)mmi_swflash_play_screen_delete_callback);
    /*Register function with right softkey */
    SetKeyHandler(mmi_swflash_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_swflash_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
 
    mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_READY);
    mmi_swflash_set_interrupt_handler();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_exit_screen
 * DESCRIPTION
 *  the exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop playback */
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_EXIT_PLAY);
    mdi_swflash_set_is_from_player(MMI_FALSE);
    mdi_swflash_stop();
    
    /* free swflash layer */
    if (g_swflash_cntx.swflash_play_layer != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    }
     
    /*free resource*/
    mdi_swflash_close_file();
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, 0, 0, 0);
    gdi_layer_multi_layer_disable();

    /* resume audio */
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    mdi_audio_resume_background_play();

    TurnOffBacklight();
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* stop LED patten */
    StartLEDPatternBackGround();
   
    h.scrnID = SCR_ID_SWFLASH_OPTION_PLAY;
    h.entryFuncPtr = mmi_swflash_option_play2_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
    mmi_swflash_reset_interrupt_handler();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_play_status
 * DESCRIPTION
 *  play status change function
 * PARAMETERS
 *  mdi_swflash_pl_state_enum state:play state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_play_status(mdi_swflash_pl_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(state)
    {
        case MDI_SWFLASH_PL_STATE_READY:
            ChangeLeftSoftkey(STR_ID_SWFLASH_PLAY, 0);
            ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
          
            if( g_swflash_cntx.srcAPP == 1)
            {
                DeleteUptoScrID(SCR_FMGR_EXPLORER);
            }
                    
            SetLeftSoftkeyFunction(mmi_swflash_option_play_play, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_swflash_exit_play, KEY_EVENT_UP);
            break;
            
        case MDI_SWFLASH_PL_STATE_PLAY:
            ChangeLeftSoftkey(STR_ID_SWFLASH_PAUSE, 0);
            ChangeRightSoftkey(STR_ID_SWFLASH_STOP, 0);
            
            SetLeftSoftkeyFunction(mmi_swflash_option_play_pause, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);
            break;
            
        case MDI_SWFLASH_PL_STATE_PAUSE:
            ChangeLeftSoftkey(STR_ID_SWFLASH_RESUME, 0);
            ChangeRightSoftkey(STR_ID_SWFLASH_STOP, 0);

            SetLeftSoftkeyFunction(mmi_swflash_option_play_resume, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);
            break;
        case MDI_SWFLASH_PL_STATE_NULL:
            break;
        default:
            break;
    }
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_play
 * DESCRIPTION
 *  the function of play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, MDI_DEVICE_SPEAKER2, mmi_swflash_play_callback);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    }
    else
    {
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PLAY);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_pause
 * DESCRIPTION
 *  the function of pause
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_pause();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    }
    else
    {
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PAUSE);
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_stop
 * DESCRIPTION
 *  the function of stop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_stop();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    }
    else
    {
      
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_READY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_play_resume
 * DESCRIPTION
 *  the function of resume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_play_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_resume();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    }
    else
    {
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PLAY);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_play_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_PLAY_END);
    switch(result)
    {
    case MDI_SWFLASH_PL_RES_END_OF_FILE:
        mdi_swflash_on_end();
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_READY);
        break;
    case MDI_SWFLASH_PL_RES_DRM_END:
        break;
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_continue_confirm
 * DESCRIPTION
 *  confirm whether to continue downloading 
 * PARAMETERS
 *  void
 *  ret(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_dl_continue_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_SWFLASH_ASK_DOWNLOAD2),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_swflash_option_download, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_info_entry_screen
 * DESCRIPTION
 *  entry function of swflash info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_info_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_ENTER_INFO);
    if(g_swflash_cntx.is_zdd == MMI_TRUE)
    {
        g_swflash_cntx.is_zdd = MMI_FALSE;
        mmi_swflash_dl_continue_confirm();
    }
    else
    {
        ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, VIS_SCREEN, &wgui_swflash_info);
        if (ret == MDI_RES_SWFLASH_SUCCEED)
        {
           if(g_swflash_cntx.printable_str == NULL)
            {
                media_get_ext_buffer(MOD_MMI, (void **)&g_swflash_cntx.printable_str, 1000);
            }
            kal_mem_set(g_swflash_cntx.printable_str, 0, 1000);
            ret = mdi_swflash_transform_info(g_swflash_cntx.printable_str);
            mdi_swflash_close_file();
            if(ret == MDI_RES_SWFLASH_SUCCEED)
            {
                EntryNewScreen(SCR_ID_SWFLASH_OPTION_INFO, mmi_swflash_option_info_exit_screen, NULL, NULL);

                /* 8. Display Category74 Screen */
                ShowCategory74Screen(
                    STR_ID_SWFLASH_OPTION_INFO,
                    IMG_ID_SWFLASH_APP2,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (PU8)g_swflash_cntx.printable_str,
                    mmi_ucs2strlen(g_swflash_cntx.printable_str),
                    NULL);

                /* 9. Register function with right softkey */
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            }
            else
            {
                DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
            }
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        }
   }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_option_info_exit_screen
 * DESCRIPTION
 *  exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_info_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_SWFLASH_OPTION_INFO;
    h.entryFuncPtr = mmi_swflash_option_info_entry_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
    if (g_swflash_cntx.printable_str != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_swflash_cntx.printable_str);
        g_swflash_cntx.printable_str = NULL;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_storage_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_swflash_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_ucs2(filepath, buf);
        mmi_ucs2cat((PS8) filepath, (PS8) SWFLASH_STORAGE_FILEPATH_PHONE);
    }    
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_current_storage_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_swflash_get_current_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(filepath, (s8*)g_swflash_cntx.swflash_cmp_full_path);
    return MMI_TRUE;    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_enter_idle_screen_notify
 * DESCRIPTION
 *  notify function when return to idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_swflash_enter_idle_screen_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*nothing*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_exit_play
 * DESCRIPTION
 *  exit the player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_swflash_exit_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_swflash_set_save_file(MMI_TRUE);
    if (g_swflash_cntx.is_nexturl_on == MMI_FALSE)
    {
    GoBackHistory();
}
    else
    {
        mmi_swflash_start_wap_browser();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_set_next_url
 * DESCRIPTION
 *  set the next url for player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_set_next_url(MMI_BOOL flag_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.is_nexturl_on = flag_on;
}
#endif
#endif

