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
 * BTMMIObexSrc.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for entering password for OBEX Authentication.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_GOEP_AUTH__

#include "CommonScreens.h"
#include "MainMenuDef.h"        /* for MAIN_MENU_TITLE_EXTRA_APP_ICON  */

#include "wgui_status_icons.h"  /* for STATUS_ICON_BT */
#include "ProtocolEvents.h"
#include "SettingProfile.h"     /* for tone ID */
#include "gpioInc.h"    /* for turn on/off backlight */
#include "WrapperGprot.h"       /* IsMyTimerExist() */
#include "SettingDefs.h"
#include "SimDetectionGprot.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#ifdef __MMI_BT_BCHS_SUPPORT__
#include "BTMMIBCHS.h"
#include "BTMMIBCHSGprots.h"
#elif defined(__MMI_BT_MTK_SUPPORT__)
#include "BTMMICM.h"
#endif 

/* External Device Header Files */
#include "ExtDeviceDefs.h"
#include "BTMMIScrGprots.h"
#include "BTMMIScr.h"

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)

/*  Include: MMI header file */
#include "FileSystemDef.h"
#include "FileManagerGProt.h"
/* Trace Header Files */
#include "Bluetooth_struct.h"
#include "BTMMIObex.h"

#define AUTHPWD_OK         1
#define AUTHPWD_REJECT  2

#define AUTHPWD_INPUTBUF_LEN  32
#define AUTHPWD_UIBUF_LEN        128
#define BTDEV_NAME_LEN               100

extern kal_bool DefAuthHandling;

struct bt_mmi_obex_auth_context_struct
{
    /* for auth password input */
    U8 authpwd_input_buf[AUTHPWD_INPUTBUF_LEN];

    /* for "input password" and remote BT device name */
    U8 authpwd_ui_buf[AUTHPWD_UIBUF_LEN];

    /* to record remote BT device name */
    U8 rem_BTdev_name[BTDEV_NAME_LEN];

    /* to record the goep connection id */
    kal_uint8 goep_conn_id;

    /* endkey handler */
    FuncPtr endkey_down_hdlr;

};

static struct bt_mmi_obex_auth_context_struct btmmi_obexauth_cntx;

/* extern functions: implemented in BTMMIScr.c */
extern MMI_BOOL mmi_bt_test_ucs2(U16 *buf, U16 char_num);
void mmi_bt_truncate_ucs2_string(U16 *buf, U16 char_num, U16 truncate_char_num);

/* function prototype */
static void mmi_bt_entry_authpwd_input(void);
static void mmi_bt_exit_authpwd_input(void);
static void mmi_bt_authpwd_validation_func(U8 *text, U8 *cursor, S32 length);
static void mmi_bt_send_authpwd(void);
static void mmi_bt_authpwd_input_goback(void);
static void mmi_bt_authpwd_input_endkey(void);
static U8 mmi_bt_authpwd_input_scr_del_callback(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_auth_ind_hdlr
 * DESCRIPTION
 *  This function is to handle GOEP_AUTH_IND msg.
 * PARAMETERS
 *  auth_ind        AUTH_IND msg infomation     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_obex_auth_ind_hdlr(goep_auth_ind_struct *auth_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 utf8_char_cnt;
    U8 ucs2_str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btmmi_obexauth_cntx.goep_conn_id = auth_ind->goep_conn_id;

 
    //convert remote BT device name to UCS2
    /* get byte count for convert utf8 string to UCS2 string */
    /* get character count of utf8 string */
    /* +1 is for UCS2 NULL terminate */
    /* *ENCODING_LENGTH is for byte count of one UCS2 character */
    utf8_char_cnt = (U8) ((mmi_chset_utf8_strlen((kal_uint8*) auth_ind->dev_name) + 1) * ENCODING_LENGTH);

    //check utf8_char_cnt and BTDEV_NAME_LEN
    if (BTDEV_NAME_LEN > utf8_char_cnt)
    {
        ucs2_str_len = (U8) mmi_chset_utf8_to_ucs2_string(
                            (kal_uint8*)btmmi_obexauth_cntx.rem_BTdev_name, 
                            utf8_char_cnt, 
                            (kal_uint8*)auth_ind->dev_name);
    }
    else
    {
        ucs2_str_len = (U8) mmi_chset_utf8_to_ucs2_string(
						(kal_uint8*)btmmi_obexauth_cntx.rem_BTdev_name, 
						BTDEV_NAME_LEN, 
						(kal_uint8*)auth_ind->dev_name);

        /* allow (MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters  */
        /* so for UCS2 encoding, need MMI_BT_SCR_BD_NAME_LEN bytes */
        
        /* shall check if there is any two_byte character mixed in one_bye UCS2 string */
        /* if yes, then truncate the string to meet above rules((MMI_BT_BD_NAME_LEN/3) chinese characters or (MMI_BT_BD_NAME_LEN/3)*2 english characters)*/ 
        if(mmi_bt_test_ucs2((U16*)btmmi_obexauth_cntx.rem_BTdev_name, (U16)(ucs2_str_len/ENCODING_LENGTH)) )
        { 
            mmi_bt_truncate_ucs2_string((U16*)btmmi_obexauth_cntx.rem_BTdev_name, 
                                        (U16)(ucs2_str_len/ENCODING_LENGTH),
                                        (U16)((GOEP_MAX_DEV_NAME-2)/3)
                                       );           
        }        
    }

    mmi_bt_entry_authpwd_input();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_obex_disconnect_ind_hdlr
 * DESCRIPTION
 *    process disconnect indication msg
 * PARAMETERS
 *  disconnect_ind           
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_bt_obex_disconnect_ind_hdlr(goep_disconnect_ind_struct *disconnect_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 currScreenID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!DefAuthHandling)
        return;

    currScreenID = GetActiveScreenId();

    if (currScreenID == SCR_OBEX_INPUT_AUTHPWD)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_OBEX_INPUT_AUTHPWD);
    }
}


/*****************************************************************************
 * FUNCTION
 *  fill_uibuffer
 * DESCRIPTION
 *      fill ui buffer with specified format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void fill_uibuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lbracket_str[] = { '(', 0x00, 0x00, 0x00};
    U8 rbracket_str[] = { ')', 0x00, 0x00, 0x00};
    U8 colon_str[] = { ':', 0x00, 0x00, 0x00};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) btmmi_obexauth_cntx.authpwd_ui_buf, (const S8*)GetString(STR_OBEX_INPUT_AUTHPWD));

    mmi_ucs2cat((S8*) btmmi_obexauth_cntx.authpwd_ui_buf, (const S8*)lbracket_str);

    mmi_ucs2cat((S8*) btmmi_obexauth_cntx.authpwd_ui_buf, (const S8*)btmmi_obexauth_cntx.rem_BTdev_name);

    mmi_ucs2cat((S8*) btmmi_obexauth_cntx.authpwd_ui_buf, (const S8*)rbracket_str);
    mmi_ucs2cat((S8*) btmmi_obexauth_cntx.authpwd_ui_buf, (const S8*)colon_str);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_entry_authpwd_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_entry_authpwd_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_OBEX_INPUT_AUTHPWD, mmi_bt_exit_authpwd_input, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_OBEX_INPUT_AUTHPWD);
    inputBuffer = GetCurrInputBuffer(SCR_OBEX_INPUT_AUTHPWD);

    if (inputBuffer == NULL)
    {
        memset(btmmi_obexauth_cntx.authpwd_input_buf, 0, sizeof(U8) * AUTHPWD_INPUTBUF_LEN);
        memset(btmmi_obexauth_cntx.authpwd_ui_buf, 0, sizeof(U8) * AUTHPWD_UIBUF_LEN);

        fill_uibuffer();

        btmmi_obexauth_cntx.endkey_down_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

    }
    else
    {
        mmi_ucs2cpy((S8*) btmmi_obexauth_cntx.authpwd_input_buf, (S8*) inputBuffer);
    }

    RegisterInputBoxValidationFunction(mmi_bt_authpwd_validation_func);

    /* show category */
    ShowCategory111Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) btmmi_obexauth_cntx.authpwd_ui_buf,
        INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*) btmmi_obexauth_cntx.authpwd_input_buf,
        MMI_BT_MAX_PASSKEY_LENGHT,
        NULL,
        0,
        guiBuffer);

    /* set left & right softkey func */
    SetLeftSoftkeyFunction(mmi_bt_send_authpwd, KEY_EVENT_UP);
    SetCategory111RightSoftkeyFunction(mmi_bt_authpwd_input_goback, KEY_EVENT_UP);

    if (mmi_ucs2strlen((S8*) (btmmi_obexauth_cntx.authpwd_input_buf)) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }

    /* KEY_END handler */
    SetKeyHandler(mmi_bt_authpwd_input_endkey, KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);

    /* set screen delete callback */
    SetDelScrnIDCallbackHandler(SCR_OBEX_INPUT_AUTHPWD, (HistoryDelCBPtr) mmi_bt_authpwd_input_scr_del_callback);

    TurnOnBacklight(1);
    playRequestedTone(WARNING_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_exit_authpwd_input
 * DESCRIPTION
 *  This function is to exit auth password screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_exit_authpwd_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /*  Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to hold the history data */
    Scr.scrnID = SCR_OBEX_INPUT_AUTHPWD;
    Scr.entryFuncPtr = mmi_bt_entry_authpwd_input;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) btmmi_obexauth_cntx.authpwd_input_buf);
    GetCategoryHistory(Scr.guiBuffer);

    AddHistory(Scr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authpwd_validation_func
 * DESCRIPTION
 *  This function is to validate input
 * PARAMETERS
 *  text                
 *  cursor               
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_authpwd_validation_func(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  send_auth_res_msg
 * DESCRIPTION
 *   send auth_res msg to BT task
 * PARAMETERS
 *  rsp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void send_auth_res_msg(U8 rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;
    goep_auth_res_struct *goep_auth_res;
    U8 utf8_str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goep_auth_res = (goep_auth_res_struct*) construct_local_para(sizeof(goep_auth_res_struct), TD_CTRL);

    goep_auth_res->goep_conn_id = btmmi_obexauth_cntx.goep_conn_id;

    if (rsp == AUTHPWD_OK)
    {
        utf8_str_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)btmmi_obexauth_cntx.
                                                                authpwd_input_buf);

        utf8_str_len = mmi_chset_ucs2_to_utf8_string(
                        (kal_uint8*) goep_auth_res->passwd,
                        GOEP_MAX_PASSWD_SIZE,
                        (kal_uint8*) btmmi_obexauth_cntx.authpwd_input_buf);

        /* utf8_str_len counts the '\0' */
        goep_auth_res->passwd_len = utf8_str_len - 1;
    }
    else
    {
        memset(goep_auth_res->passwd, 0, GOEP_MAX_PASSWD_SIZE);
        goep_auth_res->passwd_len = 0;
    }

    memset(goep_auth_res->userid, 0, GOEP_MAX_USERID_SIZE);
    goep_auth_res->userid_len = 0;

    ilm_send = allocate_ilm(MOD_MMI);
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = MOD_BT;
    ilm_send->sap_id = BT_APP_SAP;
    ilm_send->msg_id = (kal_uint16) MSG_ID_GOEP_AUTH_RES;
    ilm_send->local_para_ptr = (local_para_struct*) goep_auth_res;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_send);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_send_authpwd
 * DESCRIPTION
 *  This function is to send authpwd request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_send_authpwd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_OBEX_INPUT_AUTHPWD, (HistoryDelCBPtr) NULL);

    send_auth_res_msg(AUTHPWD_OK);

    GoBackHistory();

    DefAuthHandling = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authpwd_input_scr_del_callback
 * DESCRIPTION
 *  This function is the screen delete callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_bt_authpwd_input_scr_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_OBEX_INPUT_AUTHPWD, (HistoryDelCBPtr) NULL);

    /* send auth_res msg to BT task */
    send_auth_res_msg(AUTHPWD_REJECT);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authpwd_input_goback
 * DESCRIPTION
 *  This function is
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_authpwd_input_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_OBEX_INPUT_AUTHPWD, (HistoryDelCBPtr) NULL);

    /* send auth_res msg to BT task */
    send_auth_res_msg(AUTHPWD_REJECT);

    GoBackHistory();

    DefAuthHandling = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_authpwd_input_endkey
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_authpwd_input_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDelScrnIDCallbackHandler(SCR_OBEX_INPUT_AUTHPWD, (HistoryDelCBPtr) NULL);

    /* send auth_res msg to BT task */
    send_auth_res_msg(AUTHPWD_REJECT);

    /* GoBackHistory(); */

    if (btmmi_obexauth_cntx.endkey_down_hdlr)
    {
        btmmi_obexauth_cntx.endkey_down_hdlr();
        btmmi_obexauth_cntx.endkey_down_hdlr = NULL;
    }
}

#endif /* defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) || defined(__MMI_OPP_SUPPORT__) */ 
#endif /* __MMI_BT_MTK_SUPPORT__ */ 

#endif /* __MMI_GOEP_AUTH__ */ 

