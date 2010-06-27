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
 * CellBroadcastType.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
/**************************************************************

   FILENAME : CellBroadcastType.h

   PURPOSE     : Cell Broadcast application 

   REMARKS     : nil

   AUTHOR      : Hariprasad, Magesh k

   DATE     : JAN 09,03

**************************************************************/

#ifndef _PIXCOM_CELL_BROADCAST_TYPE_H
#define _PIXCOM_CELL_BROADCAST_TYPE_H

#include "MMIDataType.h"
#include "MessagesL4Def.h"
#include "Gui_data_types.h"

#define MAX_CB_MSG_PAGE          15
#define MAX_CB_MSG_TOTAL_PAGE    30
#define MAX_STORE_CB_MSG            5
#define MAX_CB_CHNL_NAME_LENGTH     14  /* note!!!! */
#define MAX_CB_CHNL_NUMBER       65534
#define MAX_CB_CHNL_NUMBER_LENGTH   3
#define MAX_CB_CHNL_NUMBER_TO_EDIT  999
#define MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH 5
#define MAX_CB_CHNL_INLINE_ITEM     4
#define MAX_CB_SERVICE_MODE_STR     12 * ENCODING_LENGTH
#define MAX_LANG_SUPPORT            180

typedef enum
{
	MMI_CB_CONTENT_NONE,
	MMI_CB_CONTENT_FOR_DISP_IN_IDLE_SCREEN,
	MMI_CB_CONTENT_FOR_NEW_POPUP_IND,
	MMI_CB_CONTENT_FOR_READ_MESSAGE
} msg_cb_msg_content_state_enum;

typedef struct
{
    S8 currCBTotal;
    S8 currCBIndex;
	U8 content_state;
    PU8 pCBMsgContent;
} msg_cb_msg_index_struct;

typedef struct
{
    U8 MsgDCS[MAX_STORE_CB_MSG];
    U8 MsgPage[MAX_STORE_CB_MSG];
    U16 MsgMI[MAX_STORE_CB_MSG];
} msg_cb_msg_info_struct;

typedef struct
{
    U8 MsgContent;
} msg_cb_msg_content_struct;

typedef struct
{
    U8 name_dcs;
    U8 name[MAX_CB_CHNL_NAME_LENGTH + ENCODING_LENGTH];
} msg_cb_channel_name_struct;

typedef struct  /* save channel names... */
{
    U8 l4MidIndex[SMS_CB_MAX_ENTRY];
    msg_cb_channel_name_struct chnlNames[SMS_CB_MAX_ENTRY];
} msg_cb_channel_nvram_struct;  /* shall be removed!!!! */

typedef struct
{
    U8 index;
    U8 mask;
    U8 dcs;
	U8 langType;
} msg_cb_language_struct;

typedef struct
{
    U8 index;
    U8 mask;
    U16 mi;
    U8 dcs;
    U8 name[MAX_CB_CHNL_NAME_LENGTH + 1];
} msg_cb_channel_struct;

typedef struct
{
    U8 mode;
    U8 totalmi;
    U8 totaldcs;
    U8 dcsall;
    msg_cb_language_struct cblanentry[SMS_CB_MAX_LANG];
    msg_cb_channel_struct cbchnlentry[SMS_CB_MAX_ENTRY];
} msg_cb_info_struct;

typedef struct
{
    U8 addindex;
    U8 currindex;
	U8 msg_hilite_index;
    U8 unread[MAX_STORE_CB_MSG];
    U8 immediate[MAX_STORE_CB_MSG];
    U8 mode[MAX_CB_SERVICE_MODE_STR];
    U8 mask[SMS_CB_MAX_ENTRY + 1];
    U8 dcs;
    U8 name[(MAX_CB_CHNL_NAME_LENGTH + 1) *ENCODING_LENGTH];
    U8 mi[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) *ENCODING_LENGTH];
} msg_cb_display_struct;

typedef enum
{
    SMS_CB_NONE_STATE = 0,
    SMS_CB_BOOT_UP_STATE,
    SMS_CB_DEFAULT_SETTINGS_MODE_STATE,
    SMS_CB_SERVICE_MODE_STATE,
    SMS_CB_READ_MESSAGE_STATE,
    SMS_CB_CHNL_SETTING_STATE,
    SMS_CB_CHNL_SELECT_STATE,
    SMS_CB_CHNL_ADD_STATE,
    SMS_CB_CHNL_EDIT_STATE,
    SMS_CB_CHNL_DELETE_STATE,
    SMS_CB_LANGUAGE_STATE
} msg_cb_state_enum;

typedef enum
{
    MMI_CBS0_GERMAN = 0,
    MMI_CBS0_ENGLISH,
    MMI_CBS0_ITALIAN,
    MMI_CBS0_FRENCH,
    MMI_CBS0_SPANISH,
    MMI_CBS0_DUTCH,
    MMI_CBS0_SWEDISH,
    MMI_CBS0_DANISH,
    MMI_CBS0_PORTUGUESE,
    MMI_CBS0_FINNISH,
    MMI_CBS0_NORWEGIAN,
    MMI_CBS0_GREEK,
    MMI_CBS0_TURKISH,
    MMI_CBS0_HUNGARIAN,
    MMI_CBS0_POLISH,
    MMI_CBS0_LANG_UNSPECIFIED,

    MMI_CBS1_CZECH = 16,
    MMI_CBS1_HEBREW,
    MMI_CBS1_ARABIC,
    MMI_CBS1_RUSSIAN,

    MMI_CBS2_AA,    /* AFAR, 20 */
    MMI_CBS2_AB,    /* ABKHAZIAN */
    MMI_CBS2_AF,    /* AFRIKAANS */
    MMI_CBS2_AM,    /* AMHARIC */
    MMI_CBS2_AR,    /* ARABIC */
    MMI_CBS2_AS,    /* ASSAMESE */
    MMI_CBS2_AY,    /* AYMARA */
    MMI_CBS2_AZ,    /* AZERBAIJANI */

    MMI_CBS2_BA,    /* BASHKIR */
    MMI_CBS2_BE,    /* BYELORUSSIAN */
    MMI_CBS2_BG,    /* BULGARIAN, 30 */
    MMI_CBS2_BH,    /* BIHARI */
    MMI_CBS2_BI,    /* BISLAMA */
    MMI_CBS2_BN,    /* BENGALI; BANGLA */
    MMI_CBS2_BO,    /* TIBETAN */
    MMI_CBS2_BR,    /* BRETON */

    MMI_CBS2_CA,    /* CATALAN */
    MMI_CBS2_CO,    /* CORSICAN */
    MMI_CBS2_CS,    /* CZECH */
    MMI_CBS2_CY,    /* WELSH */

    MMI_CBS2_DA,    /* DANISH, 40 */
    MMI_CBS2_DE,    /* GERMAN */
    MMI_CBS2_DZ,    /* BHUTANI */

    MMI_CBS2_EL,    /* GREEK */
    MMI_CBS2_EN,    /* ENGLISH */
    MMI_CBS2_EO,    /* ESPERANTO */
    MMI_CBS2_ES,    /* SPANISH */
    MMI_CBS2_ET,    /* ESTONIAN */
    MMI_CBS2_EU,    /* BASQUE */

    MMI_CBS2_FA,    /* PERSIAN */
    MMI_CBS2_FI,    /* FINNISH, 50 */
    MMI_CBS2_FJ,    /* FIJI */
    MMI_CBS2_FO,    /* FAROESE */
    MMI_CBS2_FR,    /* FRENCH */
    MMI_CBS2_FY,    /* FRISIAN */

    MMI_CBS2_GA,    /* IRISH */
    MMI_CBS2_GD,    /* SCOTS GAELIC */
    MMI_CBS2_GL,    /* GALICIAN */
    MMI_CBS2_GN,    /* GUARANI */
    MMI_CBS2_GU,    /* GUJARATI */

    MMI_CBS2_HA,    /* HAUSA, 60 */
    MMI_CBS2_HE,    /* HEBREW (FORMERLY IW) */
    MMI_CBS2_HI,    /* HINDI */
    MMI_CBS2_HR,    /* CROATIAN */
    MMI_CBS2_HU,    /* HUNGARIAN */
    MMI_CBS2_HY,    /* ARMENIAN */

    MMI_CBS2_IA,    /* INTERLINGUA */
    MMI_CBS2_ID,    /* INDONESIAN (FORMERLY IN) */
    MMI_CBS2_IE,    /* INTERLINGUE */
    MMI_CBS2_IK,    /* INUPIAK */
    MMI_CBS2_IS,    /* ICELANDIC, 70 */
    MMI_CBS2_IT,    /* ITALIAN */
    MMI_CBS2_IU,    /* INUKTITUT */

    MMI_CBS2_JA,    /* JAPANESE */
    MMI_CBS2_JW,    /* JAVANESE */

    MMI_CBS2_KA,    /* GEORGIAN */
    MMI_CBS2_KK,    /* KAZAKH */
    MMI_CBS2_KL,    /* GREENLANDIC */
    MMI_CBS2_KM,    /* CAMBODIAN */
    MMI_CBS2_KN,    /* KANNADA */
    MMI_CBS2_KO,    /* KOREAN, 80 */
    MMI_CBS2_KS,    /* KASHMIRI */
    MMI_CBS2_KU,    /* KURDISH */
    MMI_CBS2_KY,    /* KIRGHIZ */

    MMI_CBS2_LA,    /* LATIN */
    MMI_CBS2_LN,    /* LINGALA */
    MMI_CBS2_LO,    /* LAOTHIAN */
    MMI_CBS2_LT,    /* LITHUANIAN */
    MMI_CBS2_LV,    /* LATVIAN, LETTISH */

    MMI_CBS2_MG,    /* MALAGASY */
    MMI_CBS2_MI,    /* MAORI, 90 */
    MMI_CBS2_MK,    /* MACEDONIAN */
    MMI_CBS2_ML,    /* MALAYALAM */
    MMI_CBS2_MN,    /* MONGOLIAN */
    MMI_CBS2_MO,    /* MOLDAVIAN */
    MMI_CBS2_MR,    /* MARATHI */
    MMI_CBS2_MS,    /* MALAY */
    MMI_CBS2_MT,    /* MALTESE */
    MMI_CBS2_MY,    /* BURMESE */

    MMI_CBS2_NA,    /* NAURU */
    MMI_CBS2_NE,    /* NEPALI, 100 */
    MMI_CBS2_NL,    /* DUTCH */
    MMI_CBS2_NO,    /* NORWEGIAN */

    MMI_CBS2_OC,    /* OCCITAN */
    MMI_CBS2_OM,    /* (AFAN) OROMO */
    MMI_CBS2_OR,    /* ORIYA */

    MMI_CBS2_PA,    /* PUNJABI */
    MMI_CBS2_PL,    /* POLISH */
    MMI_CBS2_PS,    /* PASHTO, PUSHTO */
    MMI_CBS2_PT,    /* PORTUGUESE */

    MMI_CBS2_QU,    /* QUECHUA, 110 */

    MMI_CBS2_RM,    /* RHAETO-ROMANCE */
    MMI_CBS2_RN,    /* KIRUNDI */
    MMI_CBS2_RO,    /* ROMANIAN */
    MMI_CBS2_RU,    /* RUSSIAN */
    MMI_CBS2_RW,    /* KINYARWANDA */

    MMI_CBS2_SA,    /* SANSKRIT */
    MMI_CBS2_SD,    /* SINDHI */
    MMI_CBS2_SG,    /* SANGHO */
    MMI_CBS2_SH,    /* SERBO-CROATIAN */
    MMI_CBS2_SI,    /* SINHALESE, 120 */
    MMI_CBS2_SK,    /* SLOVAK */
    MMI_CBS2_SL,    /* SLOVENIAN */
    MMI_CBS2_SM,    /* SAMOAN */
    MMI_CBS2_SN,    /* SHONA */
    MMI_CBS2_SO,    /* SOMALI */
    MMI_CBS2_SQ,    /* ALBANIAN */
    MMI_CBS2_SR,    /* SERBIAN */
    MMI_CBS2_SS,    /* SISWATI */
    MMI_CBS2_ST,    /* SESOTHO */
    MMI_CBS2_SU,    /* SUNDANESE, 130 */
    MMI_CBS2_SV,    /* SWEDISH */
    MMI_CBS2_SW,    /* SWAHILI */

    MMI_CBS2_TA,    /* TAMIL */
    MMI_CBS2_TE,    /* TELUGU */
    MMI_CBS2_TG,    /* TAJIK */
    MMI_CBS2_TH,    /* THAI */
    MMI_CBS2_TI,    /* TIGRINYA */
    MMI_CBS2_TK,    /* TURKMEN */
    MMI_CBS2_TL,    /* TAGALOG */
    MMI_CBS2_TN,    /* SETSWANA, 140 */
    MMI_CBS2_TO,    /* TONGA */
    MMI_CBS2_TR,    /* TURKISH */
    MMI_CBS2_TS,    /* TSONGA */
    MMI_CBS2_TT,    /* TATAR */
    MMI_CBS2_TW,    /* TWI */

    MMI_CBS2_UG,    /* UIGHUR */
    MMI_CBS2_UK,    /* UKRAINIAN */
    MMI_CBS2_UR,    /* URDU */
    MMI_CBS2_UZ,    /* UZBEK */

    MMI_CBS2_VI,    /* VIETNAMESE, 150 */
    MMI_CBS2_VO,    /* VOLAPUK */

    MMI_CBS2_WO,    /* WOLOF */

    MMI_CBS2_XH,    /* XHOSA */

    MMI_CBS2_YI,    /* YIDDISH (FORMERLY JI) */
    MMI_CBS2_YO,    /* YORUBA */

    MMI_CBS2_ZA,    /* ZHUANG */
    MMI_CBS2_ZH,    /* CHINESE */
    MMI_CBS2_ZU,    /* ZULU, 158 */
    MMI_CBS_INVALID = 255
} msg_cb_lang_enum;

typedef enum
{
    MMI_CBS_CLASS0 = 0,
    MMI_CBS_CLASS1,
    MMI_CBS_CLASS2,
    MMI_CBS_CLASS3,
    MMI_CBS_CLASS_UNSPECIFIED
} msg_cb_class_enum;

extern void InitCellBroadcastApp(void);
extern void InitCellBroadcastProtocolEventHanler(void);
extern void DeInitCellBroadcastApp(void);
extern void ResetCBInfoStructs(void);

extern void AddCBMessage(U16 cbMI, U8 cbDCS, U8 cbPage, PU8 cbMsg, U16 totalLen);
extern U8 DeleteCBMessage(U8 index);
extern void ReadCBMessageContent(PU32 outLen, PU8 msgData, U16 msgLength, U8 dcs);
extern void ConvertCBForDisplay(U8 *data, U16 len, U8 format, U32 *outLen);

extern void ReadCBMessageInfoFromNvram(void);
extern void WriteCBMessageInfoToNvram(void);
extern void ReadCbChnlInfoFromNvram(void);
extern void WriteCbChnlInfoToNvram(void);

/**************************************

   new!!!

**************************************/
extern void mmi_msg_get_cb_mode_req(void);
extern void mmi_msg_get_cb_mode_rsp_active(void *inMsg);
extern void mmi_msg_get_cb_mode_rsp_display(void *inMsg);
extern void mmi_msg_get_cb_mode_rsp_language(void *inMsg);
extern void mmi_msg_set_cb_mode_req(U8 para);
extern void mmi_msg_set_cb_mode_rsp(void *inMsg);
extern void mmi_msg_subscribe_cb_req(U8 subscribe);
extern void mmi_msg_subscribe_cb_rsp(void *inMsg);
extern void mmi_msg_handle_new_cb_ind(void *inMsg);
extern void mmi_msg_new_cb_ind(void);
extern void mmi_msg_delete_new_cb_message(void);
extern void mmi_msg_go_back_from_new_cb_ind(void);
extern void mmi_msg_end_key_from_new_cb_ind(void);

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
extern U8 *mmi_msg_get_new_cb_ind_string(void);
extern void mmi_msg_entry_new_cb_immediate_ind(void);
extern void mmi_msg_entry_new_cb_normal_ind(void);
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */ 
extern void mmi_msg_entry_new_cb_ind_when_kpl(U16 LSKStringtID, U16 LSKIconID, U16 RSKStringID, U16 RSKIconID);
extern void mmi_msg_entry_new_cb_ind(void);
extern U8 mmi_msg_need_new_cb_ind(void);
extern void mmi_msg_restore_cb(void);
extern void mmi_msg_subscribe_cb(void);
extern void mmi_msg_save_cb_channel(void);
extern void mmi_msg_select_cb_channel(void);
extern void mmi_msg_add_cb_channel(U16 mi);
extern void mmi_msg_edit_cb_channel(U16 mi);
extern void mmi_msg_delete_cb_channel(void);
extern void mmi_msg_select_cb_language(void);
extern void mmi_msg_refresh_cb_main_menu(void);
extern void mmi_msg_entry_cb_main_menu(void);
extern void mmi_msg_pre_entry_cb_main_menu(void);
extern void mmi_msg_entry_cb_channel_settings(void);
extern void mmi_msg_pre_entry_cb_channel_bootup(void);
extern void mmi_msg_entry_cb_channel_select(void);
extern void mmi_msg_pre_entry_cb_channel_select(void);
extern void mmi_msg_entry_cb_channel_list(void);
extern pBOOL mmi_msg_cb_channel_list_get_item(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern S32 mmi_msg_cb_channel_list_get_hint(S32 item_index, UI_string_type *hint_array);
extern void mmi_msg_pre_entry_cb_channel_add(void);
extern void mmi_msg_pre_entry_cb_channel_list_edit(void);
extern void mmi_msg_pre_entry_cb_channel_list_delete(void);
extern void mmi_msg_set_cb_channel_inline_item(void);
extern void mmi_msg_entry_cb_channel_edit(void);
extern void mmi_msg_exit_cb_channel_edit(void);
extern void mmi_msg_pre_entry_cb_channel_edit(void);
extern void mmi_msg_entry_cb_language(void);
extern void mmi_msg_pre_entry_cb_language(void);
extern void mmi_msg_entry_cb_read_message(void);
extern void mmi_msg_pre_entry_cb_read_message(void);
extern pBOOL mmi_msg_cb_read_message_get_item(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);
extern void mmi_msg_go_back_from_cb_message(void);
extern void mmi_msg_end_key_from_cb_message(void);
extern void mmi_msg_entry_cb_message(void);
extern void mmi_msg_delete_cb_message(void);
extern void mmi_msg_pre_entry_cb_message(void);

extern void mmi_msg_highlight_cb_mode(void);
extern void mmi_msg_hint_cb_mode(U16 index);
extern void mmi_msg_highlight_cb_read_message(void);
extern void mmi_msg_highlight_cb_language(void);
extern void mmi_msg_highlight_cb_channel_settings(void);
extern void mmi_msg_highlight_cb_channel_select(void);
extern void mmi_msg_highlight_cb_channel_add(void);
extern void mmi_msg_highlight_cb_channel_edit(void);
extern void mmi_msg_highlight_cb_channel_delete(void);

extern void mmi_msg_pre_entry_cb_idle_use_number(void);
extern void mmi_msg_entry_cb_use_number(void);

extern void mmi_msg_pre_delete_new_cb_message(void);

extern U8 DecodeCbsDcs(
			    U8 dcs,
			    U8 char1,
			    U8 char2,
			    U8 char3,
			    msg_cb_lang_enum *lang_type,
			    smsal_dcs_enum *alphabet_type,
			    msg_cb_class_enum *msg_class,
			    pBOOL *is_compress,
			    pBOOL *is_reserved);

extern void MMICbsDecodeLang(U8 char1, U8 char2, msg_cb_lang_enum *lang_type);

extern void mmi_msg_cb_remove_fill_bit(U8* buffer, U32 max_buff_len);

#endif /* _PIXCOM_CELL_BROADCAST_TYPE_H */ 

