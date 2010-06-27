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
 * CellBroadcast.C
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
 /**************************************************************

   FILENAME : CellBroadcast.c

   PURPOSE     : Cell Broadcast application 

   REMARKS     : nil

   AUTHOR      : Hariprasad, Magesh k

   DATE     : JAN 09,03

**************************************************************/
#include "MMI_include.h"
#ifdef __MOD_SMSAL__

/*  */

/* ... Add More MMI header */
#include "CommonScreens.h"
#include "ProtocolEvents.h"

/* ...Add MSG header */
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "CellBroadcastType.h"
/*  */
#include "Gui_ems.h"
#include "wgui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
/*  */

#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "SettingProt.h"
#include "PhoneBookGprot.h"

#include "GpioInc.h"
#include "IdleAppDef.h"

#include "CallManagementGprot.h"
#include "nvram_user_defs.h"

#include "SMSApi.h"
#include "SMSStruct.h"  /* temp!! */

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_AD_resdef.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_PFAL_Slave_CellBroadcast.h"
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_PFAL_Gemini_CellBroadcast.h"
#endif /* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
/*  */
#ifndef NVRAM_SMS_CB_CHNL_RECORD_SIZE
#define NVRAM_SMS_CB_CHNL_RECORD_SIZE  180
#endif 

#ifndef NVRAM_SMS_CB_SMS_RECORD_SIZE
/* MTK Joy modified for corrected NVRAM data size, 1207 */
#define NVRAM_SMS_CB_SMS_RECORD_SIZE   826
/* MTK end */
#endif /* NVRAM_SMS_CB_SMS_RECORD_SIZE */ 
//
//MTK Joy added for multipage CB, 0113
#define SWAP_USHORT(Var) *Var = *(unsigned short*)SwapEndian((void*)Var, sizeof(short))

#ifndef NVRAM_SMS_CB_SMS_PAGE_SIZE
#define NVRAM_SMS_CB_SMS_PAGE_SIZE        94
#endif 
#ifndef NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL
#define NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL         30
#endif 
#ifndef NVRAM_SMS_CB_SMS_INFO_SIZE
#define NVRAM_SMS_CB_SMS_INFO_SIZE        20
#endif 
#define SMS_CB_SMS_PAGE_SIZE_UCS2         82
/* MTK end */
#define MESSAGES_CB_BOOTUP_TIMEOUT_DURATION 3000        /* 3 Seconds */
static msg_cb_channel_nvram_struct cbNvramStruct;
static U8 IsCBMessageReadOperRequired = TRUE;
static msg_cb_msg_index_struct cbMsgIndex;
static msg_cb_msg_info_struct cbMsgInfo;

static void mmi_msg_pre_entry_cb_channel_settings(void);

static void mmi_msg_cb_read_content_from_nvram(U8 page, U8 page_num, U8* buff);
static void mmi_msg_cb_read_content_for_display(U8 index, U8 content_state, U8 unread_change);

static void mmi_msg_cb_get_msg_list_index(S32 nIndex);

static U8 IsCBChannelFull = FALSE;
static U8 L4cTotalMidNum;


static U8 dispCBMessage[NVRAM_SMS_CB_SMS_PAGE_SIZE * ENCODING_LENGTH * MAX_CB_MSG_PAGE + ENCODING_LENGTH];
static U32 dispCBLength = 0;
static U16 cbChnlEditorIcons[MAX_CB_CHNL_INLINE_ITEM] = 
{
    IMG_CB_CHNL_TITLE,
    IMG_SMS_COMMON_NOIMAGE,
    IMG_CB_CHNL_NUMBER,
    IMG_SMS_COMMON_NOIMAGE
};
const U16 cbDefaultChnlNameStrId[SMS_CB_MAX_ENTRY] = 
{
    STR_CB_CHNL_NAME_1,
    STR_CB_CHNL_NAME_2,
    STR_CB_CHNL_NAME_3,
    STR_CB_CHNL_NAME_4,
    STR_CB_CHNL_NAME_5,
    STR_CB_CHNL_NAME_6,
    STR_CB_CHNL_NAME_7,
    STR_CB_CHNL_NAME_8,
    STR_CB_CHNL_NAME_9,
    STR_CB_CHNL_NAME_10,
    STR_CB_CHNL_NAME_11,
    STR_CB_CHNL_NAME_12,
    STR_CB_CHNL_NAME_13,
    STR_CB_CHNL_NAME_14,
    STR_CB_CHNL_NAME_15,
    STR_CB_CHNL_NAME_16,
    STR_CB_CHNL_NAME_17,
    STR_CB_CHNL_NAME_18,
    STR_CB_CHNL_NAME_19,
    STR_CB_CHNL_NAME_20,
    STR_CB_CHNL_NAME_21,
    STR_CB_CHNL_NAME_22,
    STR_CB_CHNL_NAME_23,
    STR_CB_CHNL_NAME_24,
    STR_CB_CHNL_NAME_25,
    STR_CB_CHNL_NAME_26,
    STR_CB_CHNL_NAME_27,
    STR_CB_CHNL_NAME_28,
    STR_CB_CHNL_NAME_29,
    STR_CB_CHNL_NAME_30,
    STR_CB_CHNL_NAME_31,
    STR_CB_CHNL_NAME_32,
    STR_CB_CHNL_NAME_33,
    STR_CB_CHNL_NAME_34,
    STR_CB_CHNL_NAME_35,
    STR_CB_CHNL_NAME_36,
    STR_CB_CHNL_NAME_37,
    STR_CB_CHNL_NAME_38,
    STR_CB_CHNL_NAME_39,
    STR_CB_CHNL_NAME_40,
};

/*  */

/**************************************************************

            revised part--variable

**************************************************************/
static msg_cb_info_struct cb_info;
static msg_cb_state_enum cb_state;
static msg_cb_display_struct cb_display;
extern wgui_inline_item wgui_inline_items[];

/*************************************************************

            Cb language

*************************************************************/
const U16 LangEnumAndStrID[MAX_LANG_SUPPORT] = 
{
	STR_LANG_GERMAN,
	STR_LANG_ENGLISH,
	STR_LANG_ITALIAN,
	STR_LANG_FRENCH,
	STR_LANG_SPANISH,
	STR_LANG_DUTCH,
	STR_LANG_SWEDISH,
	STR_LANG_DANISH,
	STR_LANG_PORTUGUESE,
	STR_LANG_FINNISH,
	STR_LANG_NORWEGIAN,
	STR_LANG_GREEK,
	STR_LANG_TURKISH,
	STR_LANG_HUNGARIAN,
	STR_LANG_POLISH,
	STR103_MITEM103_CB_LANGUAGE_UNSPECIFIED,
	STR_LANG_CZECH,
	STR_LANG_HEBREW,
	STR_LANG_ARABIC,
	STR_LANG_RUSSIAN,
	STR_LANG_AFAR,
	STR_LANG_ABKHAZIAN,
	STR_LANG_AFRIKAANS,
	STR_LANG_AMHARIC,
	STR_LANG_ARABIC,
	STR_LANG_ASSAMESE,
	STR_LANG_AYMARA,
	STR_LANG_AZERBAIJANI,
	STR_LANG_BASHKIR,
	STR_LANG_BYELORUSSIAN,
	STR_LANG_BULGARIAN,
	STR_LANG_BIHARI,
	STR_LANG_BISLAMA,
	STR_LANG_BENGALI,
	STR_LANG_TIBETAN,
	STR_LANG_BRETON,
	STR_LANG_CATALAN,
	STR_LANG_CORSICAN,
	STR_LANG_CZECH,
	STR_LANG_WELSH,
	STR_LANG_DANISH,
	STR_LANG_GERMAN,
	STR_LANG_BHUTANI,
	STR_LANG_GREEK,
	STR_LANG_ENGLISH,
	STR_LANG_ESPERANTO,
	STR_LANG_SPANISH,
	STR_LANG_ESTONIAN,
	STR_LANG_BASQUE,
	STR_LANG_PERSIAN,
	STR_LANG_FINNISH,
	STR_LANG_FIJI,
	STR_LANG_FAROESE,
	STR_LANG_FRENCH,
	STR_LANG_FRISIAN,
	STR_LANG_IRISH,
	STR_LANG_SCOTS_GAELIC,
	STR_LANG_GALICIAN,
	STR_LANG_GUARANI,
	STR_LANG_GUJARATI,
	STR_LANG_HAUSA,
	STR_LANG_HEBREW,
	STR_LANG_HINDI,
	STR_LANG_CROATIAN,
	STR_LANG_HUNGARIAN,
	STR_LANG_ARMENIAN,
	STR_LANG_INTERLINGUA,
	STR_LANG_INDONESIAN,
	STR_LANG_INTERLINGUE,
	STR_LANG_INUPIAK,
	STR_LANG_ICELANDIC,
	STR_LANG_ITALIAN,
	STR_LANG_INUKTITUT,
	STR_LANG_JAPANESE,
	STR_LANG_JAVANESE,
	STR_LANG_GEORGIAN,
	STR_LANG_KAZAKH,
	STR_LANG_GREENLANDIC,
	STR_LANG_CAMBODIAN,
	STR_LANG_KANNADA,
	STR_LANG_KOREAN,
	STR_LANG_KASHMIRI,
	STR_LANG_KURDISH,
	STR_LANG_KIRGHIZ,
	STR_LANG_LATIN,
	STR_LANG_LINGALA,
	STR_LANG_LAOTHIAN,
	STR_LANG_LITHUANIAN,
	STR_LANG_LATVIAN,
	STR_LANG_MALAGASY,
	STR_LANG_MAORI,
	STR_LANG_MACEDONIAN,
	STR_LANG_MALAYALAM,
	STR_LANG_MONGOLIAN,
	STR_LANG_MOLDAVIAN,
	STR_LANG_MARATHI,
	STR_LANG_MALAY,
	STR_LANG_MALTESE,
	STR_LANG_BURMESE,
	STR_LANG_NAURU,
	STR_LANG_NEPALI,
	STR_LANG_DUTCH,
	STR_LANG_NORWEGIAN,
	STR_LANG_OCCITAN,
	STR_LANG_OROMO,
	STR_LANG_ORIYA,
	STR_LANG_PUNJABI,
	STR_LANG_POLISH,
	STR_LANG_PASHTO,
	STR_LANG_PORTUGUESE,
	STR_LANG_QUECHUA,
	STR_LANG_RHAETO_ROMANCE,
	STR_LANG_KIRUNDI,
	STR_LANG_ROMANIAN,
	STR_LANG_RUSSIAN,
	STR_LANG_KINYARWANDA,
	STR_LANG_SANSKRIT,
	STR_LANG_SINDHI,
	STR_LANG_SANGHO,
	STR_LANG_SERBO_CROATIAN,
	STR_LANG_SINHALESE,
	STR_LANG_SLOVAK,
	STR_LANG_SLOVENIAN,
	STR_LANG_SAMOAN,
	STR_LANG_SHONA,
	STR_LANG_SOMALI,
	STR_LANG_ALBANIAN,
	STR_LANG_SERBIAN,
	STR_LANG_SISWATI,
	STR_LANG_SESOTHO,
	STR_LANG_SUNDANESE,
	STR_LANG_SWEDISH,
	STR_LANG_SWAHILI,
	STR_LANG_TAMIL,
	STR_LANG_TELUGU,
	STR_LANG_TAJIK,
	STR_LANG_THAI,
	STR_LANG_TIGRINYA,
	STR_LANG_TURKMEN,
	STR_LANG_TAGALOG,
	STR_LANG_SETSWANA,
	STR_LANG_TONGA,
	STR_LANG_TURKISH,
	STR_LANG_TSONGA,
	STR_LANG_TATAR,
	STR_LANG_TWI,
	STR_LANG_UIGHUR,
	STR_LANG_UKRAINIAN,
	STR_LANG_URDU,
	STR_LANG_UZBEK,
	STR_LANG_VIETNAMESE,
	STR_LANG_VOLAPUK,
	STR_LANG_WOLOF,
	STR_LANG_XHOSA,
	STR_LANG_YIDDISH,
	STR_LANG_YORUBA,
	STR_LANG_ZHUANG,
	STR_LANG_CHINESE,
	STR_LANG_ZULU,
	0
};


/*****************************************************************************
 * FUNCTION
 *  MMICbsDecodeLang
 * DESCRIPTION
 *  Decode CB language
 * PARAMETERS
 *  char1           [IN]            Char 1
 *  char2           [IN]            Char 2
 *  lang_type       [IN/OUT]        Language type
 * RETURNS
 *  void
 *****************************************************************************/
void MMICbsDecodeLang(U8 char1, U8 char2, msg_cb_lang_enum *lang_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *lang_type = MMI_CBS_INVALID;
    switch (char1)
    {
        case 'a':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_AA;
                    break;
                case 'b':
                    *lang_type = MMI_CBS2_AB;
                    break;
                case 'f':
                    *lang_type = MMI_CBS2_AF;
                    break;
                case 'm':
                    *lang_type = MMI_CBS2_AM;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_AR;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_AS;
                    break;
                case 'y':
                    *lang_type = MMI_CBS2_AY;
                    break;
                case 'z':
                    *lang_type = MMI_CBS2_AZ;
                    break;
            }
            break;
        case 'b':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_BA;
                    break;
                case 'e':
                    *lang_type = MMI_CBS2_BE;
                    break;
                case 'g':
                    *lang_type = MMI_CBS2_BG;
                    break;
                case 'h':
                    *lang_type = MMI_CBS2_BH;
                    break;
                case 'i':
                    *lang_type = MMI_CBS2_BI;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_BN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_BO;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_BR;
                    break;
            }
            break;
        case 'c':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_CA;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_CO;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_CS;
                    break;
                case 'y':
                    *lang_type = MMI_CBS2_CY;
                    break;
            }
            break;
        case 'd':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_DA;
                    break;
                case 'e':
                    *lang_type = MMI_CBS2_DE;
                    break;
                case 'z':
                    *lang_type = MMI_CBS2_DZ;
                    break;
            }
            break;
        case 'e':
            switch (char2)
            {
                case 'l':
                    *lang_type = MMI_CBS2_EL;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_EN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_EO;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_ES;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_ET;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_EU;
                    break;
            }
            break;
        case 'f':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_FA;
                    break;
                case 'i':
                    *lang_type = MMI_CBS2_FI;
                    break;
                case 'j':
                    *lang_type = MMI_CBS2_FJ;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_FO;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_FR;
                    break;
                case 'y':
                    *lang_type = MMI_CBS2_FY;
                    break;
            }
            break;
        case 'g':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_GA;
                    break;
                case 'd':
                    *lang_type = MMI_CBS2_GD;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_GL;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_GN;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_GU;
                    break;
            }
            break;
        case 'h':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_HA;
                    break;
                case 'e':
                    *lang_type = MMI_CBS2_HE;
                    break;
                case 'i':
                    *lang_type = MMI_CBS2_HI;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_HR;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_HU;
                    break;
                case 'y':
                    *lang_type = MMI_CBS2_HY;
                    break;
            }
            break;
        case 'i':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_IA;
                    break;
                case 'd':
                    *lang_type = MMI_CBS2_ID;
                    break;
                case 'e':
                    *lang_type = MMI_CBS2_IE;
                    break;
                case 'k':
                    *lang_type = MMI_CBS2_IK;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_IS;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_IT;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_IU;
                    break;
            }
            break;
        case 'j':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_JA;
                    break;
                case 'w':
                    *lang_type = MMI_CBS2_JW;
                    break;
            }
            break;
        case 'k':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_KA;
                    break;
                case 'k':
                    *lang_type = MMI_CBS2_KK;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_KL;
                    break;
                case 'm':
                    *lang_type = MMI_CBS2_KM;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_KN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_KO;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_KS;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_KU;
                    break;
                case 'y':
                    *lang_type = MMI_CBS2_KY;
                    break;
            }
            break;
        case 'l':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_LA;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_LN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_LO;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_LT;
                    break;
                case 'v':
                    *lang_type = MMI_CBS2_LV;
                    break;
            }
            break;
        case 'm':
            switch (char2)
            {
                case 'g':
                    *lang_type = MMI_CBS2_MG;
                    break;
                case 'i':
                    *lang_type = MMI_CBS2_MI;
                    break;
                case 'k':
                    *lang_type = MMI_CBS2_MK;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_ML;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_MN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_MO;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_MR;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_MS;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_MT;
                    break;
                case 'y':
                    *lang_type = MMI_CBS2_MY;
                    break;
            }
            break;
        case 'n':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_NA;
                    break;
                case 'e':
                    *lang_type = MMI_CBS2_NE;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_NL;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_NO;
                    break;
            }
            break;
        case 'o':
            switch (char2)
            {
                case 'c':
                    *lang_type = MMI_CBS2_OC;
                    break;
                case 'm':
                    *lang_type = MMI_CBS2_OM;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_OR;
                    break;
            }
            break;
        case 'p':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_PA;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_PL;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_PS;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_PT;
                    break;
            }
            break;
        case 'q':
            switch (char2)
            {
                case 'u':
                    *lang_type = MMI_CBS2_QU;
                    break;
            }
            break;
        case 'r':
            switch (char2)
            {
                case 'm':
                    *lang_type = MMI_CBS2_RM;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_RN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_RO;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_RU;
                    break;
                case 'w':
                    *lang_type = MMI_CBS2_RW;
                    break;
            }
            break;
        case 's':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_SA;
                    break;
                case 'd':
                    *lang_type = MMI_CBS2_SD;
                    break;
                case 'g':
                    *lang_type = MMI_CBS2_SG;
                    break;
                case 'h':
                    *lang_type = MMI_CBS2_SH;
                    break;
                case 'i':
                    *lang_type = MMI_CBS2_SI;
                    break;
                case 'k':
                    *lang_type = MMI_CBS2_SK;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_SL;
                    break;
                case 'm':
                    *lang_type = MMI_CBS2_SM;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_SN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_SO;
                    break;
                case 'q':
                    *lang_type = MMI_CBS2_SQ;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_SR;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_SS;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_ST;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_SU;
                    break;
                case 'v':
                    *lang_type = MMI_CBS2_SV;
                    break;
                case 'w':
                    *lang_type = MMI_CBS2_SW;
                    break;
            }
            break;
        case 't':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_TA;
                    break;
                case 'e':
                    *lang_type = MMI_CBS2_TE;
                    break;
                case 'g':
                    *lang_type = MMI_CBS2_TG;
                    break;
                case 'h':
                    *lang_type = MMI_CBS2_TH;
                    break;
                case 'i':
                    *lang_type = MMI_CBS2_TI;
                    break;
                case 'k':
                    *lang_type = MMI_CBS2_TK;
                    break;
                case 'l':
                    *lang_type = MMI_CBS2_TL;
                    break;
                case 'n':
                    *lang_type = MMI_CBS2_TN;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_TO;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_TR;
                    break;
                case 's':
                    *lang_type = MMI_CBS2_TS;
                    break;
                case 't':
                    *lang_type = MMI_CBS2_TT;
                    break;
                case 'w':
                    *lang_type = MMI_CBS2_TW;
                    break;
            }
            break;
        case 'u':
            switch (char2)
            {
                case 'g':
                    *lang_type = MMI_CBS2_UG;
                    break;
                case 'k':
                    *lang_type = MMI_CBS2_UK;
                    break;
                case 'r':
                    *lang_type = MMI_CBS2_UR;
                    break;
                case 'z':
                    *lang_type = MMI_CBS2_UZ;
                    break;
            }
            break;
        case 'v':
            switch (char2)
            {
                case 'i':
                    *lang_type = MMI_CBS2_VI;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_VO;
                    break;
            }
            break;
        case 'w':
            switch (char2)
            {
                case 'o':
                    *lang_type = MMI_CBS2_WO;
                    break;
            }
            break;
        case 'x':
            switch (char2)
            {
                case 'h':
                    *lang_type = MMI_CBS2_XH;
                    break;
            }
            break;
        case 'y':
            switch (char2)
            {
                case 'i':
                    *lang_type = MMI_CBS2_YI;
                    break;
                case 'o':
                    *lang_type = MMI_CBS2_YO;
                    break;
            }
            break;
        case 'z':
            switch (char2)
            {
                case 'a':
                    *lang_type = MMI_CBS2_ZA;
                    break;
                case 'h':
                    *lang_type = MMI_CBS2_ZH;
                    break;
                case 'u':
                    *lang_type = MMI_CBS2_ZU;
                    break;
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  DecodeCbsDcs
 * DESCRIPTION
 *  Decode Cb DCS
 * PARAMETERS
 *  dcs                 [IN]            DCS
 *  char1               [IN]            Char 1
 *  char2               [IN]            Char 2
 *  char3               [IN]            Char 3
 *  lang_type           [IN/OUT]        Language type
 *  alphabet_type       [IN/OUT]        Alphabet type
 *  msg_class           [IN/OUT]        Message class
 *  is_compress         [IN/OUT]        Is compress
 *  is_reserved         [IN/OUT]        Is reserved
 * RETURNS
 *  skip character
 *****************************************************************************/
U8 DecodeCbsDcs(
    U8 dcs,
    U8 char1,
    U8 char2,
    U8 char3,
    msg_cb_lang_enum *lang_type,
    smsal_dcs_enum *alphabet_type,
    msg_cb_class_enum *msg_class,
    pBOOL *is_compress,
    pBOOL *is_reserved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 coding_group = (dcs >> 4);
    kal_uint8 coding_bits = (dcs & 0x0f);
    kal_uint8 skip_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *lang_type = MMI_CBS0_LANG_UNSPECIFIED;
    *alphabet_type = SMSAL_DEFAULT_DCS;
    *msg_class = MMI_CBS_CLASS_UNSPECIFIED;

    *is_compress = KAL_FALSE;
    *is_reserved = KAL_FALSE;

    switch (coding_group)
    {
        case 0x00:
            *lang_type = (msg_cb_lang_enum) coding_bits;
            break;
        case 0x01:
            /* 
             * GSM7: PS side already unpack 
             * UCS2: PS side didn't unpack 
             */
            if (coding_bits == 0)   /* GSM7 */
            {
                if (char3 == 0x0d)  /* CR */
                {
                    MMICbsDecodeLang(char1, char2, lang_type);
                    skip_char = 3;
                }
            }
            else if (coding_bits == 1)  /* UCS2 */
            {
                *alphabet_type = SMSAL_UCS2_DCS;
                MMICbsDecodeLang((U8) (char1 & 0x7f), (U8) (((char2 & 0x3f) << 1) | ((char1 & 0x80) >> 7)), lang_type);
                skip_char = 2;
            }
            /* MTK end */
            else
            {
                *is_reserved = KAL_TRUE;
            }
            break;
        case 0x02:
            if (coding_bits < 0x04)
            {
                *lang_type = (msg_cb_lang_enum) (16 + coding_bits);
            }
            else
            {
                *is_reserved = KAL_TRUE;
            }
            break;
        case 0x03:
            *is_reserved = KAL_TRUE;
            break;
        case 0x04:  /* General Data Coding Scheme */
        case 0x05:
        case 0x06:
        case 0x07:
            if ((coding_group & 0x02) != 0)
            {
                *is_compress = KAL_TRUE;
            }
            if ((coding_group & 0x01) == 0x01)
            {
                *msg_class = (msg_cb_class_enum) (dcs & 0x03);
            }
            *alphabet_type = (smsal_dcs_enum) (dcs & 0x0C);
            break;
        case 0x08:  /* 0x08 - 0x0d: Reserved */
        case 0x09:
        case 0x0a:
        case 0x0b:
        case 0x0c:
        case 0x0d:
            *is_reserved = KAL_TRUE;
            break;
        case 0x0e:  /* defined by WAP forum */
            break;
        case 0x0f:  /* Data Coding/Message Class */
            *alphabet_type = (smsal_dcs_enum) (dcs & 0x04);
            *msg_class = (msg_cb_class_enum) (dcs & 0x03);
            break;
        default:
            break;
    }
    return skip_char;
}   /* end of DecodeCbsDcs */


/*****************************************************************************
 * FUNCTION
 *  DeleteCBMessage
 * DESCRIPTION
 *  Delete CB message
 * PARAMETERS
 *  delet_index       [IN]        Index
 * RETURNS
 *  delete length
 *****************************************************************************/
U8 DeleteCBMessage(U8 delete_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 i = 0;
	U8 *page_buff;
    U8 delete_page = cbMsgInfo.MsgPage[delete_index];
	U8 dest_page = 0;
	U8 scr_page = 0;
	U8 move_page = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DELETE_CB_MESSAGE, delete_index);
	MMI_ASSERT(delete_index < cbMsgIndex.currCBTotal);

	page_buff = OslMalloc(NVRAM_SMS_CB_SMS_PAGE_SIZE);

	for(i = 0; i < delete_index; i++)
	{
		dest_page += cbMsgInfo.MsgPage[i];
	}

	cbMsgIndex.currCBTotal--;
	if (delete_index < cbMsgIndex.currCBTotal)
    {
    	scr_page = dest_page;
    	for (i = delete_index; i < cbMsgIndex.currCBTotal; i++)
    	{
    		U16 j;
	
			scr_page += cbMsgInfo.MsgPage[i];
			move_page = cbMsgInfo.MsgPage[i + 1];
			
	        for (j = scr_page; j < (scr_page + move_page) && (j < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); j++)
	        {
	            U16 scr_index = j + 1;
				U16 dest_index = dest_page + 1;

	            if (ReadRecord(NVRAM_EF_SMS_CB_SMS_LID, scr_index, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) < 0)
	            {
	            	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DELETE_CB_MESSAGE_1, error);
	            }


	            if (WriteRecord(NVRAM_EF_SMS_CB_SMS_LID, dest_index, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
	                NVRAM_SMS_CB_SMS_PAGE_SIZE)
	            {
	                MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DELETE_CB_MESSAGE_2, error);
				}
				dest_page++;
	        }
			
            cbMsgInfo.MsgDCS[i] = cbMsgInfo.MsgDCS[i + 1];
            cbMsgInfo.MsgPage[i] = cbMsgInfo.MsgPage[i + 1];
            cbMsgInfo.MsgMI[i] = cbMsgInfo.MsgMI[i + 1];
			
			cb_display.immediate[i] = cb_display.immediate[i + 1];
			cb_display.unread[i] = cb_display.unread[i + 1];
    	}
    }

	/* reset the unused nvram space (Size = the delete cb message space size) */
	memset(page_buff, 0, NVRAM_SMS_CB_SMS_PAGE_SIZE);
    for (i = dest_page; (i < (dest_page + delete_page)) && (i < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); i++)
    {
        U16 reset_index = i + 1;

        if (WriteRecord(NVRAM_EF_SMS_CB_SMS_LID, reset_index, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
            NVRAM_SMS_CB_SMS_PAGE_SIZE)
        {
            MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DELETE_CB_MESSAGE_3, error);
		}
    }
	OslMfree(page_buff);

	/* reset the last cb message info */
    cbMsgInfo.MsgDCS[cbMsgIndex.currCBTotal] = 0;
    cbMsgInfo.MsgPage[cbMsgIndex.currCBTotal] = 0;
    cbMsgInfo.MsgMI[cbMsgIndex.currCBTotal] = SMS_CB_UNUSED_CBMI;

	/* reset the last cb message diplay info */
	cb_display.immediate[cbMsgIndex.currCBTotal] = FALSE;
	cb_display.unread[cbMsgIndex.currCBTotal] = FALSE;

	if (cbMsgIndex.currCBIndex != MAX_STORE_CB_MSG)
	{
		if (delete_index == cbMsgIndex.currCBIndex)
		{
			cbMsgIndex.currCBIndex = MAX_STORE_CB_MSG;
		}
		else if (delete_index < cbMsgIndex.currCBIndex)
		{
			cbMsgIndex.currCBIndex--;
		}
	}

	if (cb_display.currindex != MAX_STORE_CB_MSG)
	{
		if (delete_index == cb_display.currindex)
		{
			cb_display.currindex = MAX_STORE_CB_MSG;
		}
		else if (delete_index < cb_display.currindex)
		{
			cb_display.currindex--;
		}
	}

	if (GetMessagesCurrScrnID() == SCR_ID_MSG_CB_MESSAGE_LIST)
	{
		if ((delete_index < cb_display.msg_hilite_index) || 
			(cb_display.msg_hilite_index == (U8)cbMsgIndex.currCBTotal))
		{
			cb_display.msg_hilite_index--;
		}
	}

    return delete_page;
}


/*****************************************************************************
 * FUNCTION
 *  AddCBMessage
 * DESCRIPTION
 *  Add CB message to NVRAM(A new CB Message Always Add the first of the NVRAM)
 * PARAMETERS
 *  cbMI            [IN]        Cbmi
 *  cbDCS           [IN]        Cb DCS
 *  cbPage          [IN]        Cb page number
 *  cbMsg           [IN]        Cb message pointer
 *  totalLen        [IN]        Cb message length
 * RETURNS
 *  void
 *****************************************************************************/
void AddCBMessage(U16 cbMI, U8 cbDCS, U8 cbPage, PU8 cbMsg, U16 totalLen)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    S16 error = 0;
	msg_cb_lang_enum langType;
	smsal_dcs_enum alphabetType;
	msg_cb_class_enum msgClass;
	pBOOL isCompress;
	pBOOL isReserved;
	U8 curr_total_page = 0;
	U8 i;
	U8* page_pointer;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_ADD_CB_MESSAGE, cbMsgIndex.currCBTotal);
	MMI_ASSERT(cbMsgIndex.currCBTotal < MAX_STORE_CB_MSG)
	
	if (cbMsgIndex.pCBMsgContent != NULL)
	{
		OslMfree(cbMsgIndex.pCBMsgContent);
	}
	cbMsgIndex.pCBMsgContent = OslMalloc(cbPage * NVRAM_SMS_CB_SMS_PAGE_SIZE);

	memcpy(cbMsgIndex.pCBMsgContent, cbMsg, totalLen);
	
    DecodeCbsDcs(
        cbDCS,
        cbMsg[0],
        cbMsg[1],
        cbMsg[2],
        &langType,
        &alphabetType,
        &msgClass,
        &isCompress,
        &isReserved);
    switch (alphabetType)
    {
        case SMSAL_DEFAULT_DCS:
        case SMSAL_RESERVED_DCS:
            memset(
                cbMsgIndex.pCBMsgContent + totalLen,
                0x0D,
                cbPage * NVRAM_SMS_CB_SMS_PAGE_SIZE - totalLen);
            break;
        case SMSAL_8BIT_DCS:
        case SMSAL_UCS2_DCS:
            memset(
                cbMsgIndex.pCBMsgContent + totalLen,
                0x00,
                cbPage * NVRAM_SMS_CB_SMS_PAGE_SIZE - totalLen);
            break;
    }

	if (cbMsgIndex.currCBTotal > 0)
	{
		U8 dest_page = 0;
		U8 scr_page = 0;

		for (i = 0; i < cbMsgIndex.currCBTotal; i++)
		{
			curr_total_page += cbMsgInfo.MsgPage[i];
		}

		dest_page = curr_total_page + cbPage;
		if ((curr_total_page > 0) && (dest_page <= NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL))
		{
			U8 *page_buff;
			
			page_buff = OslMalloc(NVRAM_SMS_CB_SMS_PAGE_SIZE);
			
			scr_page = curr_total_page;

			/* Note: if wanted to handle the index = 0 page, the read or write record is (index + 1) */
			for(i = 0; i < curr_total_page; i++)
			{
		        if (ReadRecord(NVRAM_EF_SMS_CB_SMS_LID, scr_page, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) < 0)
		        {
		        	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DELETE_CB_MESSAGE_1, error);
		        }

		        if (WriteRecord(NVRAM_EF_SMS_CB_SMS_LID, dest_page, page_buff, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
		            NVRAM_SMS_CB_SMS_PAGE_SIZE)
		        {
		            MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DELETE_CB_MESSAGE_2, error);
				}
				scr_page--;
				dest_page--;
			}
			OslMfree(page_buff);
		}
		
		for (i = cbMsgIndex.currCBTotal - 1; ; i--)
		{
            cbMsgInfo.MsgDCS[i + 1] = cbMsgInfo.MsgDCS[i];
            cbMsgInfo.MsgPage[i + 1] = cbMsgInfo.MsgPage[i];
            cbMsgInfo.MsgMI[i + 1] = cbMsgInfo.MsgMI[i];

			cb_display.unread[i + 1] = cb_display.unread[i];
			cb_display.immediate[i + 1] = cb_display.immediate[i];

			if (i == 0)
			{
				break;
			}
		}
	}

	page_pointer = cbMsgIndex.pCBMsgContent;

    for (i = 0; (i < cbPage) && (i < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); i++)
    {
        U16 index = i + 1;

        if (WriteRecord(NVRAM_EF_SMS_CB_SMS_LID, index, page_pointer, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) !=
            NVRAM_SMS_CB_SMS_PAGE_SIZE)
        {
			MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_ADD_CB_MESSAGE_1, error);
		}
		page_pointer += NVRAM_SMS_CB_SMS_PAGE_SIZE;
	}
    cbMsgInfo.MsgDCS[0] = cbDCS;
    cbMsgInfo.MsgPage[0] = cbPage;
    cbMsgInfo.MsgMI[0] = cbMI;

	cb_display.unread[0] = TRUE;
	cb_display.immediate[0] = FALSE;

    cbMsgIndex.currCBTotal++;

	if (cbMsgIndex.currCBIndex != MAX_STORE_CB_MSG)
	{
		cbMsgIndex.currCBIndex++;
	}

	if (cb_display.currindex != MAX_STORE_CB_MSG)
	{
		cb_display.currindex++;
	}


	if ((GetMessagesCurrScrnID() == SCR_ID_MSG_CB_MESSAGE_LIST) &&
		(cb_display.msg_hilite_index < (MAX_STORE_CB_MSG - 1)))
	{
		cb_display.msg_hilite_index++;
	}
}


/*****************************************************************************
 * FUNCTION
 *  ReadCbChnlInfoFromNvram
 * DESCRIPTION
 *  Read CB channel info from NVRAM, to be removed after L4 provide interface
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReadCbChnlInfoFromNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadRecord(NVRAM_EF_SMS_CB_CHNL_LID, 1, &cbNvramStruct, NVRAM_SMS_CB_CHNL_RECORD_SIZE, &error) < 0)
    {
		MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_CHNL_INFO_FROM_NVRAM, error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WriteCbChnlInfoToNvram
 * DESCRIPTION
 *  Write CB channel info to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WriteCbChnlInfoToNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WriteRecord(NVRAM_EF_SMS_CB_CHNL_LID, 1, &cbNvramStruct, NVRAM_SMS_CB_CHNL_RECORD_SIZE, &error) !=
        NVRAM_SMS_CB_CHNL_RECORD_SIZE)
    {
		MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_WRITE_CHNL_INFO_FROM_NVRAM, error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ReadCBMessageInfoFromNvram
 * DESCRIPTION
 *  Read CB Message info from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReadCBMessageInfoFromNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadRecord(NVRAM_EF_SMS_CB_SMS_INFO_LID, 1, &cbMsgInfo, NVRAM_SMS_CB_SMS_INFO_SIZE, &error) < 0)
    {
		MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_MESSAGE_INFO_FROM_NVRAM, error);
    }

	for (i = 0; i < MAX_STORE_CB_MSG; i++)
	{
		if (cbMsgInfo.MsgPage[i] == 0)
		{
			break;
		}
	}
	cbMsgIndex.currCBTotal = i;
}


/*****************************************************************************
 * FUNCTION
 *  WriteCBMessageInfoToNvram
 * DESCRIPTION
 *  Write CB message info to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WriteCBMessageInfoToNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (WriteRecord(NVRAM_EF_SMS_CB_SMS_INFO_LID, 1, &cbMsgInfo, NVRAM_SMS_CB_SMS_INFO_SIZE, &error) !=
        NVRAM_SMS_CB_SMS_INFO_SIZE)
    {
    	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_WRITE_MESSAGE_INFO_FROM_NVRAM, error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ConvertCBForDisplay
 * DESCRIPTION
 *  Convert CB message for display, according to its DCS
 * PARAMETERS
 *  data        [IN]            Message data
 *  len         [IN]            Message length
 *  format      [IN]            Message format
 *  outLen      [IN/OUT]        Message output length
 * RETURNS
 *  void
 *****************************************************************************/
void ConvertCBForDisplay(U8 *data, U16 len, U8 format, U32 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 outLength;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_CONVERT_CB_FOR_DISPLAY, len, format);
    if (len > 0)
    {
        switch (format)
        {
            case (MMI_DEFAULT_DCS):
            {
                U8 *tempData;

                tempData = OslMalloc(len);;
                ConvertGSM7BitDefaultEncodingToAscii(tempData, data, len, &outLength);
                mmi_asc_n_to_ucs2((PS8) dispCBMessage, (PS8) tempData, outLength);
                memset((void*)&dispCBMessage[outLength * ENCODING_LENGTH], 0, ENCODING_LENGTH);
                OslMfree(tempData);
                if (outLen != NULL)
                {
                    *outLen = (U32) outLength *ENCODING_LENGTH + ENCODING_LENGTH;
                }
            }
                break;

            case (MMI_8BIT_DCS):
                mmi_asc_n_to_ucs2((PS8) dispCBMessage, (PS8) data, len);
                memset((void*)&dispCBMessage[len * ENCODING_LENGTH], 0, ENCODING_LENGTH);
                if (outLen != NULL)
                {
                    *outLen = len * ENCODING_LENGTH + ENCODING_LENGTH;
                }
                break;

            case (MMI_UCS2_DCS):
                memset((void*)dispCBMessage, 0, len + 1 + ENCODING_LENGTH);
                memcpy(dispCBMessage, data, len);
                if (outLen != NULL)
                {
                    *outLen = len + ENCODING_LENGTH;
                }
                {
                    U16 *tempData;
                    int i;

                    tempData = (U16*) dispCBMessage;
                    for (i = 0; i < len; i += 2)
                    {
                        SWAP_USHORT(tempData);
                        tempData++;
                    }
                }
                break;
        }
        return;
    }
    else
    {
        memset((void*)dispCBMessage, 0, ENCODING_LENGTH);
        if (outLen != NULL)
        {
            *outLen = ENCODING_LENGTH;
        }
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_read_cb_content_for_display
 * DESCRIPTION
 *  Read CB message content From Nvram and convert it to the display buffer
 * PARAMETERS
 *  index         	[IN]            Message index
 * 	content_state	[IN]            Messages content state for read
 *  unread_change	[IN]			Change unread flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_cb_read_content_for_display(U8 index, U8 content_state, U8 unread_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U8 page = cbMsgInfo.MsgPage[index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_CONTENT_FOR_DISPLAY, index, content_state);

	/* cbMsgIndex.pCBMsgContent store content from the new arrival cb message or NVRAM */
	/* If read the cb message in the read message box, always read the content from the NVRAM; */
	if ((content_state == MMI_CB_CONTENT_FOR_READ_MESSAGE) ||
		(cbMsgIndex.content_state != content_state))
	{
		U8 start_page = 0;
		U8 i;

		if (cbMsgIndex.pCBMsgContent != NULL)
		{
			OslMfree(cbMsgIndex.pCBMsgContent);
		}
		cbMsgIndex.pCBMsgContent = OslMalloc(page * NVRAM_SMS_CB_SMS_PAGE_SIZE);
	
		for (i = 0; i < index; i++)
		{
			start_page += cbMsgInfo.MsgPage[i];
		}
		mmi_msg_cb_read_content_from_nvram(start_page, page, cbMsgIndex.pCBMsgContent);
	}

	if (cbMsgIndex.pCBMsgContent != NULL)
	{
		U8 dcs = cbMsgInfo.MsgDCS[index];
		U16 msg_len = page * NVRAM_SMS_CB_SMS_PAGE_SIZE;

		ReadCBMessageContent(
			(PU32)&dispCBLength,
			cbMsgIndex.pCBMsgContent,
			msg_len,
			dcs);
		
		OslMfree(cbMsgIndex.pCBMsgContent);
		cbMsgIndex.pCBMsgContent = NULL;
		cbMsgIndex.content_state = MMI_CB_CONTENT_NONE;
	}
	
	if (unread_change == TRUE)
	{
		if (cb_display.unread[index] == TRUE)
		{
			cb_display.unread[index] = FALSE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_read_content_from_nvram
 * DESCRIPTION
 *  Read CB message content From Nvram
 * PARAMETERS
 *  start_page    	[IN]            start page
 *  page_num        [IN]            page number
 *  buff      		[OUT]           Output content buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_cb_read_content_from_nvram(U8 start_page, U8 page_num, U8* buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S16 error = 0;
	U8* page_pointer = buff;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_CONTENT_FROM_NVRAM, start_page, page_num);

    for (i = start_page; (i < (start_page + page_num)) && (i < NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL); i++)
    {
        U16 scr_index = (U16)i + 1;

        if (ReadRecord(NVRAM_EF_SMS_CB_SMS_LID, scr_index, page_pointer, NVRAM_SMS_CB_SMS_PAGE_SIZE, &error) < 0)
        {
        	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_CONTENT_FROM_NVRAM_1, error);
        }
		page_pointer += NVRAM_SMS_CB_SMS_PAGE_SIZE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ReadCBMessageContent
 * DESCRIPTION
 *  Read CB message content for dislpay
 * PARAMETERS
 *  outLen          [IN/OUT]        Output length
 *  msgData         [IN]            Message data
 *  msgLength       [IN]            Message length
 *  dcs             [IN]            Message DCS
 * RETURNS
 *  void
 *****************************************************************************/
void ReadCBMessageContent(PU32 outLen, PU8 msgData, U16 msgLength, U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msg_cb_lang_enum langType;
    smsal_dcs_enum alphabetType;
    msg_cb_class_enum msgClass;
    pBOOL isCompress;
    pBOOL isReserved;

    /* MTK add Kevin */
    U8 skipChar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK end */
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_CB_MESSAGE_CONTENT_FROM_NVRAM);

    /* MTK add Kevin */
    skipChar = DecodeCbsDcs(
                dcs,
                msgData[0],
                msgData[1],
                msgData[2],
                &langType,
                &alphabetType,
                &msgClass,
                &isCompress,
                &isReserved);
    /* MTK end */

    if (isCompress == TRUE || isReserved == TRUE)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_DOES_NOT_SUPPORT),
            IMG_GLOBAL_WARNING,
            0,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
        DeleteMessagesHistoryNodes();
    }
    else
    {
    	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_READ_CB_MESSAGE_CONTENT_FROM_NVRAM, alphabetType);
        switch (alphabetType)
        {
                /* MTK add Kevin for skipping some characters containing dcs info */
            case SMSAL_DEFAULT_DCS:
            case SMSAL_RESERVED_DCS:
                ConvertCBForDisplay(msgData + skipChar, (U16) (msgLength - skipChar), SMSAL_DEFAULT_DCS, outLen);
                break;
            case SMSAL_8BIT_DCS:
                ConvertCBForDisplay(msgData + skipChar, (U16) (msgLength - skipChar), SMSAL_8BIT_DCS, outLen);
                break;
            case SMSAL_UCS2_DCS:
                ConvertCBForDisplay(msgData + skipChar, (U16) (msgLength - skipChar), SMSAL_UCS2_DCS, outLen);
                break;
                /* MTK end */
            default:
                ConvertCBForDisplay(msgData + skipChar, (U16) (msgLength - skipChar), SMSAL_DEFAULT_DCS, outLen);
                break;
        }

		mmi_msg_cb_remove_fill_bit(dispCBMessage, *outLen);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_cb_mode_req
 * DESCRIPTION
 *  Get CB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_cb_mode_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MSG_ID_MMI_SMS_GET_CB_MODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_cb_mode_rsp_active
 * DESCRIPTION
 *  Get CB mode for current status
 * PARAMETERS
 *  inMsg       [IN]        L4 response message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_cb_mode_rsp_active(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT *msgRsp = (MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_GET_CB_MODE_RSP_ACTIVE);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (msgRsp->result == TRUE)
    {
        cb_info.mode = msgRsp->mode;
        memset(cb_display.mode, 0, ENCODING_LENGTH);
        if (cb_info.mode == TRUE)
        {
            mmi_ucs2cpy((S8*) cb_display.mode, (S8*) GetString((U16) STR_GLOBAL_ON));
        }
        else
        {
            mmi_ucs2cpy((S8*) cb_display.mode, (S8*) GetString((U16) STR_GLOBAL_OFF));
        }
        mmi_msg_entry_cb_main_menu();
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_CB_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_cb_mode_rsp_display
 * DESCRIPTION
 *  Get CB mode to display channel list
 * PARAMETERS
 *  inMsg       [IN]        L4 reponse message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_cb_mode_rsp_display(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT *msgRsp = (MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_GET_CB_MODE_RSP_DISPLAY);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (msgRsp->result == TRUE)
    {
        U8 i = 0;
        U8 total = 0;
        U8 addindex = msgRsp->total_mid_num;

        /* delete if apply new interface */
        ReadCbChnlInfoFromNvram();
        /* end */

        L4cTotalMidNum = msgRsp->total_mid_num;

        for (i = 0; i < msgRsp->total_mid_num; i++)
        {
            if (msgRsp->info.mid[i] != SMSAL_CB_UNUSED_CBMI)
            {
                U8 j = 0;

                cb_info.cbchnlentry[total].mi = msgRsp->info.mid[i];
                cb_info.cbchnlentry[total].mask = msgRsp->info.mid_mask[i];
                cb_info.cbchnlentry[total].index = i;
                /* delete if apply new interface */
                memset(cb_info.cbchnlentry[total].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
                while ((cbNvramStruct.l4MidIndex[j] != i) && (j < SMS_CB_MAX_ENTRY))
                {
                    j++;
                }
                if (j == SMS_CB_MAX_ENTRY)
                {
                    memset((S8*) cb_info.cbchnlentry[total].name, 0, MAX_CB_CHNL_NAME_LENGTH);
                    cb_info.cbchnlentry[total].dcs = PHB_ASCII;
                }
                else
                {
                    memcpy(
                        (S8*) cb_info.cbchnlentry[total].name,
                        (S8*) cbNvramStruct.chnlNames[j].name,
                        MAX_CB_CHNL_NAME_LENGTH);
                    cb_info.cbchnlentry[total].dcs = cbNvramStruct.chnlNames[j].name_dcs;
                }
                /* end */
                total++;
            }
            else
            {
                if (addindex == msgRsp->total_mid_num)
                {
                    addindex = i;
                }
            }
        }

        cb_info.totalmi = total;
        memset(&cbNvramStruct, 0xff, sizeof(msg_cb_channel_nvram_struct));
        for (i = 0; i < cb_info.totalmi; i++)
        {
            cbNvramStruct.l4MidIndex[i] = cb_info.cbchnlentry[i].index;
            cbNvramStruct.chnlNames[i].name_dcs = cb_info.cbchnlentry[i].dcs;
            memcpy(
                (S8*) cbNvramStruct.chnlNames[i].name,
                (S8*) cb_info.cbchnlentry[i].name,
                MAX_CB_CHNL_NAME_LENGTH + 1);
        }
        /* delete if apply new interface */
        WriteCbChnlInfoToNvram();
        /* end */
        switch (cb_state)
        {
            case SMS_CB_CHNL_SETTING_STATE:
                if (cb_info.totalmi == msgRsp->total_mid_num)
                {
                    IsCBChannelFull = TRUE;
                }
                mmi_msg_entry_cb_channel_settings();
                break;

            case SMS_CB_CHNL_SELECT_STATE:
                if (cb_info.totalmi == 0)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) WARNING_TONE);
                }
                else
                {
                    mmi_msg_entry_cb_channel_select();
                }
                break;
            case SMS_CB_CHNL_EDIT_STATE:
            case SMS_CB_CHNL_DELETE_STATE:
                if (cb_info.totalmi == 0)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_EMPTY),
                        IMG_GLOBAL_EMPTY,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) WARNING_TONE);
                }
                else
                {
                    mmi_msg_entry_cb_channel_list();
                }
                break;
            case SMS_CB_CHNL_ADD_STATE:
                if (cb_info.totalmi == msgRsp->total_mid_num)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_CB_CHNL_FULL),
                        IMG_GLOBAL_WARNING,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) WARNING_TONE);
                }
                else
                {
                    cb_display.addindex = addindex;
                    memset(cb_display.name, 0, (MAX_CB_CHNL_NAME_LENGTH + 1) * ENCODING_LENGTH);
                    memset(cb_display.mi, 0, (MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH);
                    cb_display.dcs = PHB_ASCII;
                    mmi_msg_entry_cb_channel_edit();
                }
                break;
            case SMS_CB_READ_MESSAGE_STATE:
                mmi_msg_entry_cb_read_message();
                break;
            default:
				MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_GET_CB_MODE_RSP_DISPLAY_1);
                break;
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_CB_ERROR_MESSAGE),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_cb_mode_rsp_language
 * DESCRIPTION
 *  Get CB mode to display CB language list
 * PARAMETERS
 *  inMsg       [IN]        L4 response message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_cb_mode_rsp_language(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT *msgRsp = (MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_GET_CB_MODE_RSP_LANGUAGE);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    /* if incoming call ringing or alarm playing, do not show response result in case interrupt current screen */
    if (mmi_msg_check_interrupt() == TRUE)
    {
        return;
    }
    if (msgRsp->result == TRUE)
    {
        U8 i = 0;
        U8 total = 0;
        U8 firstByte = 0;
        U8 secondByte = 0;

        pBOOL isCompress;
        pBOOL isReserved;
        msg_cb_lang_enum langType;
        smsal_dcs_enum alphabetType;
        msg_cb_class_enum msgClass;

        for (i = 0; i < msgRsp->total_dcs_num; i++)
        {
            if (msgRsp->info.dcs[i] != SMSAL_CB_UNUSED_DCS)
            {

                firstByte = (msgRsp->info.dcs[i] & 0xff00) >> 8;
                secondByte = (msgRsp->info.dcs[i] & 0x00ff);
                if (firstByte == 0x00)
                {
                    DecodeCbsDcs(secondByte, 0, 0, 0, &langType, &alphabetType, &msgClass, &isCompress, &isReserved);
                }
                else
                {
                    MMICbsDecodeLang(firstByte, secondByte, &langType);
                }

                if ((langType != MMI_CBS0_LANG_UNSPECIFIED) && (langType != MMI_CBS_INVALID))
                {
                	U8 j;
					U8 is_duplicate = FALSE;
					
					for(j = 0; j < total; j++)
					{
						if(cb_info.cblanentry[j].langType == langType)
						{
							is_duplicate = TRUE;
							break;
						}
					}

					if(is_duplicate == FALSE)
					{
	                    cb_info.cblanentry[total].langType = langType;
						cb_info.cblanentry[total].dcs = msgRsp->info.dcs[i];
	                    cb_info.cblanentry[total].mask = msgRsp->info.dcs_mask[i];
	                    cb_info.cblanentry[total].index = i;
	                    total++;
					}
                }
            }
            firstByte = 0;
            secondByte = 0;
        }
        cb_info.totaldcs = total;
        cb_info.dcsall = msgRsp->info.is_all_language_on;
        mmi_msg_entry_cb_language();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_cb_mode_req
 * DESCRIPTION
 *  Set CB mode request
 * PARAMETERS
 *  para        [IN]        Setting type flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_cb_mode_req(U8 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_FRM_CB_SET_CB_MODE_REQ_STRUCT *msgReq;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteCbChnlInfoToNvram();
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MSG_ID_MMI_SMS_SET_CB_MODE_REQ;
    msgReq = (MMI_FRM_CB_SET_CB_MODE_REQ_STRUCT*) OslConstructDataPtr(sizeof(MMI_FRM_CB_SET_CB_MODE_REQ_STRUCT));

    if ((para & SMSAL_CB_MI) == SMSAL_CB_MI)
    {
        for (i = 0; i < SMS_CB_MAX_ENTRY; i++)
        {
            msgReq->info.mid[i] = SMSAL_CB_UNUSED_CBMI;
        }
        for (i = 0; i < cb_info.totalmi; i++)
        {
            msgReq->info.mid[cb_info.cbchnlentry[i].index] = cb_info.cbchnlentry[i].mi;
        }
    }
    if (((para & SMSAL_CB_MI) == SMSAL_CB_MI) || ((para & SMSAL_CB_MI_MASK) == SMSAL_CB_MI_MASK))
    {
        for (i = 0; i < SMS_CB_MAX_ENTRY; i++)
        {
            msgReq->info.mid_mask[i] = 1;
        }
        for (i = 0; i < cb_info.totalmi; i++)
        {
            msgReq->info.mid_mask[cb_info.cbchnlentry[i].index] = cb_info.cbchnlentry[i].mask;
        }
    }
    if ((para & SMSAL_CB_DCS_MASK) == SMSAL_CB_DCS_MASK)
    {
        //Set the language back to remove the duplicate language
		para |= SMSAL_CB_DCS;
        for (i = 0; i < SMS_CB_MAX_LANG; i++)
        {
            msgReq->info.dcs_mask[i] = 1;
			msgReq->info.dcs[i] = SMSAL_CB_UNUSED_DCS;
        }
        for (i = 0; i < cb_info.totaldcs; i++)
        {
            msgReq->info.dcs_mask[cb_info.cblanentry[i].index] = cb_info.cblanentry[i].mask;
        	msgReq->info.dcs[cb_info.cblanentry[i].index] = cb_info.cblanentry[i].dcs;
        }
    }
    if ((para & SMSAL_CB_ALL_LANG) == SMSAL_CB_ALL_LANG)
    {
        msgReq->info.is_all_language_on = (kal_bool)cb_info.dcsall;
    }
    msgReq->info.para_ind = para;
    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_cb_mode_rsp
 * DESCRIPTION
 *  Set CB mode response
 * PARAMETERS
 *  inMsg       [IN]        L4 reponse message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_cb_mode_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_CB_SET_CB_MODE_RSP_STRUCT *msgRsp = (MMI_FRM_CB_SET_CB_MODE_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_SET_CB_MODE_RSP, msgRsp->result);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    if (msgRsp->result == TRUE)
    {
        switch (cb_state)
        {
            case SMS_CB_DEFAULT_SETTINGS_MODE_STATE:
                if (msgRsp->result == TRUE)
                {
                    RstRestoreDisplayPopup(MMI_TRUE);
                }
                else
                {
                    RstRestoreDisplayPopup(MMI_FALSE);
                }
                break;

            case SMS_CB_CHNL_SELECT_STATE:
            case SMS_CB_CHNL_EDIT_STATE:
                DisplayPopup(
                    (PU8) GetString(STR_SMS_SAVE_SUCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
                DeleteMessagesHistoryNodes();
                break;

            case SMS_CB_CHNL_ADD_STATE:
                if (cb_info.totalmi == L4cTotalMidNum)
                {
                    IsCBChannelFull = TRUE;
                }
                DisplayPopup(
                    (PU8) GetString(STR_ID_MSG_SMS_ADD_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
                DeleteMessagesHistoryNodes();
                break;

            case SMS_CB_CHNL_DELETE_STATE:
                if (IsCBChannelFull == TRUE)
                {
                    IsCBChannelFull = FALSE;
                }
                if (g_msg_cntx.currHiliteIndex == cb_info.totalmi)
                {
                    g_msg_cntx.currHiliteIndex--;
                }
                DisplayPopup(
                    (PU8) GetString(STR_MESSAGES_DELETED_ID),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MESSAGES_POPUP_TIME_OUT,
                    (U8) SUCCESS_TONE);
                if (cb_info.totalmi == 0)
                {
                    DeleteScreenIfPresent(SCR_ID_MSG_CB_CHANNEL_LIST);
                }
                break;

            case SMS_CB_LANGUAGE_STATE:
                if (msgRsp->result == TRUE)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_SMS_SAVE_SUCESS),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) SUCCESS_TONE);
                    DeleteMessagesHistoryNodes();
                }
                else
                {
                    DisplayPopup(
                        (PU8) GetString(STR_MESSAGES_UNKNOWN_ERROR),
                        IMG_GLOBAL_UNFINISHED,
                        1,
                        MESSAGES_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                    DeleteMessagesHistoryNodes();
                }
                break;
        }
    }
    else
    {
        if (cb_state == SMS_CB_DEFAULT_SETTINGS_MODE_STATE)
        {
            RstRestoreDisplayPopup(MMI_FALSE);
        }
        else
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_CHANNEL_LIST);
            DisplayPopup(
                (PU8) GetString(STR_CB_ERROR_MESSAGE),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            DeleteMessagesHistoryNodes();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_subscribe_cb_req
 * DESCRIPTION
 *  Subscribe CB request
 * PARAMETERS
 *  subscribe       [IN]        Subscribe type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_subscribe_cb_req(U8 subscribe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    MMI_FRM_CB_SUBSCRIBE_REQ_STRUCT *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_SUBSCRIBE_CB_REQ);
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MSG_ID_MMI_CB_SUBSCRIBE_REQ;
    msgReq = (MMI_FRM_CB_SUBSCRIBE_REQ_STRUCT*) OslConstructDataPtr(sizeof(MMI_FRM_CB_SUBSCRIBE_REQ_STRUCT));
    msgReq->on_off = subscribe;
    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_subscribe_cb_rsp
 * DESCRIPTION
 *  Subscribe CB response
 * PARAMETERS
 *  inMsg       [IN]        L4 reponse message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_subscribe_cb_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_CB_SUBSCRIBE_RSP_STRUCT *msgRsp = (MMI_FRM_CB_SUBSCRIBE_RSP_STRUCT*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_SUBSCRIBE_CB_RSP, msgRsp->result);
    ClearProtocolEventHandler(PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP);
    if (msgRsp->result == TRUE)
    {
        if (cb_state == SMS_CB_DEFAULT_SETTINGS_MODE_STATE)
        {
            U8 i = 0;

            for (i = 0; i < SMS_CB_MAX_ENTRY; i++)
            {
                cb_info.cbchnlentry[i].mask = 1;
            }
            for (i = 0; i < SMS_CB_MAX_LANG; i++)
            {
                cb_info.cblanentry[i].mask = 1;
            }
            cb_info.dcsall = 1;
            SetProtocolEventHandler(mmi_msg_set_cb_mode_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
            mmi_msg_set_cb_mode_req(SMSAL_CB_MI_MASK | SMSAL_CB_DCS_MASK);
        }
        else
        {
            U8 subscribe = (!cb_info.mode);

            cb_info.mode = subscribe;
            memset(cb_display.mode, 0, ENCODING_LENGTH);
            if (cb_info.mode == TRUE)
            {
                mmi_ucs2cpy((S8*) cb_display.mode, (S8*) GetString((U16) STR_GLOBAL_ON));
            }
            else
            {
                mmi_ucs2cpy((S8*) cb_display.mode, (S8*) GetString((U16) STR_GLOBAL_OFF));
            }
            mmi_msg_refresh_cb_main_menu();
        }
    }
    else
    {
        if (cb_state == SMS_CB_DEFAULT_SETTINGS_MODE_STATE)
        {
            RstRestoreDisplayPopup(MMI_FALSE);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_CB_ERROR_MESSAGE),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_new_cb_ind
 * DESCRIPTION
 *  Handle new CB indication
 * PARAMETERS
 *  inMsg       [IN]        L4 response message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_new_cb_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FRM_CB_MSG_IND_STRUCT *CbsMsg = (MMI_FRM_CB_MSG_IND_STRUCT*) inMsg;
    U8 i = 0;
    U8 deleteIndex = 0;
    U16 inCBMI = SMS_CB_UNUSED_CBMI;
    U8 inCBDCS = 0;
    U8 inCBPage = 0;
    U8 currCBPageTotal = 0;
	MMI_BOOL is_immediate_mode = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND);
#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    handle_new_cb_ind(inMsg);
#endif
    if (IsCBMessageReadOperRequired)
    {
        IsCBMessageReadOperRequired = FALSE;
        ReadCBMessageInfoFromNvram();
    }
    inCBMI = CbsMsg->mi;
    inCBDCS = CbsMsg->dcs;
    inCBPage = ((CbsMsg->msg_length) / NVRAM_SMS_CB_SMS_PAGE_SIZE);
    if (((CbsMsg->msg_length) % NVRAM_SMS_CB_SMS_PAGE_SIZE) != 0)
    {
        inCBPage++;
    }
    inCBPage = (inCBPage > MAX_CB_MSG_PAGE) ? MAX_CB_MSG_PAGE : inCBPage;
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_1, inCBPage);

    for (i = 0; i < cbMsgIndex.currCBTotal; i++)
    {
        currCBPageTotal += cbMsgInfo.MsgPage[i];
    }
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_2, currCBPageTotal);

    /* gs code is the first two most significant bits in the first octet */
	if ((CbsMsg->sn & 0xc000) == 0)
    {
		is_immediate_mode = MMI_TRUE;
    }
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_3, is_immediate_mode);


	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_4, cbMsgIndex.currCBTotal);
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_5, cb_display.currindex);
	
	if (((currCBPageTotal + inCBPage) <= NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL))
	{
		if (cbMsgIndex.currCBTotal == MAX_STORE_CB_MSG)
		{
			for (deleteIndex = (MAX_STORE_CB_MSG - 1); ; deleteIndex--)
			{
				if (deleteIndex != cb_display.currindex)
				{
					break;
				}

				if (deleteIndex == 0)
				{
					break;
				}
			}

			MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_7, deleteIndex);
            DeleteCBMessage(deleteIndex);
        }
	}
    else
    {
		U8 curr_total_message = cbMsgIndex.currCBTotal;

		/* Remove the oldest one */
		deleteIndex = curr_total_message - 1;
        for (i = 0; i < curr_total_message; i++)
        {
			if (deleteIndex == cb_display.currindex)
			{
				deleteIndex--;
			}
			else
			{
				MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_HANDLE_NEW_CB_IND_8, deleteIndex);
				/* Note: cbMsgIndex.currCBTotal will decrement when delete a CB messaeg */
				currCBPageTotal -= DeleteCBMessage(deleteIndex);
				deleteIndex--;

				if ((currCBPageTotal + inCBPage) <= NVRAM_SMS_CB_SMS_PAGE_NUM_TOTAL)
				{
					break;
				}
			}
        }
    }

    AddCBMessage(inCBMI, inCBDCS, inCBPage, CbsMsg->msg_data, CbsMsg->msg_length);

    if (is_immediate_mode == MMI_TRUE)
    {
        cb_display.immediate[0] = TRUE;
    }

    mmi_msg_new_cb_ind();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_new_cb_ind
 * DESCRIPTION
 *  New CB message indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_MMI_MSG_NEW_CB_IND);

    TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
	
	cbMsgIndex.content_state = MMI_CB_CONTENT_FOR_NEW_POPUP_IND;
    if (IsMMIInIdleState() || GetMessagesCurrScrnID() == SCR_ID_MSG_CB_MESSAGE_IDLE ||
        GetMessagesCurrScrnID() == SCR_ID_MSG_CB_MESSAGE_IND)
    {
        ClearKeyEvents();   /* key flussing */

        if (IsKeyPadLockState())
        {
            EntryIdleScreen();
        }
        else
        {
        #ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
            if (cb_display.immediate[0] == TRUE)
            {
                cbMsgIndex.currCBIndex = 0;
				mmi_msg_entry_new_cb_ind();
            }
            else if (GetMessagesCurrScrnID() != SCR_ID_MSG_CB_MESSAGE_IDLE)
            {
                cbMsgIndex.currCBIndex = 0;
				mmi_msg_entry_new_cb_ind();
            }
        #else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */ 
            cbMsgIndex.currCBIndex = 0;
			mmi_msg_entry_new_cb_ind();
        #endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
        }
    }
    else if (GetMessagesCurrScrnID() == SCR_ID_MSG_CB_MESSAGE_LIST)
    {
        mmi_msg_entry_cb_read_message();
        DeleteScreenIfPresent(SCR_ID_MSG_CB_MESSAGE_LIST);
    }

    WriteCBMessageInfoToNvram();    /* ->no need!!! only write when shut down: check if ok */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_new_cb_message
 * DESCRIPTION
 *  Delete new CB message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_new_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteCBMessage((U8)cbMsgIndex.currCBIndex);
    WriteCBMessageInfoToNvram();

    DisplayPopup(
        (PU8) GetString(STR_MESSAGES_DELETED_ID),
        IMG_GLOBAL_ACTIVATED,
        1,
        MESSAGES_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE);

	DeleteScreenIfPresent(SCR_ID_MSG_CB_MESSAGE_IDLE);
    cb_display.currindex = MAX_STORE_CB_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_new_cb_ind
 * DESCRIPTION
 *  Reset CB unread index before go back screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(cb_display.unread, 0, MAX_STORE_CB_MSG);
	if (cbMsgIndex.pCBMsgContent != NULL)
	{
		OslMfree(cbMsgIndex.pCBMsgContent);
		cbMsgIndex.pCBMsgContent = NULL;
		cbMsgIndex.content_state = MMI_CB_CONTENT_NONE;
	}

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_new_cb_ind
 * DESCRIPTION
 *  Reset CB unread index before go to idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_end_key_from_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&cb_display.unread, 0, MAX_STORE_CB_MSG);

	if (cbMsgIndex.pCBMsgContent != NULL)
	{
		OslMfree(cbMsgIndex.pCBMsgContent);
		cbMsgIndex.pCBMsgContent = NULL;
		cbMsgIndex.content_state = MMI_CB_CONTENT_NONE;
	}

    ExecCurrEndKeyDownHandler();
}

#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_new_cb_ind_string
 * DESCRIPTION
 *  Get new msg indication string
 * PARAMETERS
 *  void
 * RETURNS
 *  new msg indication string
 *****************************************************************************/
U8 *mmi_msg_get_new_cb_ind_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];
    static S8 temp[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
    for (i = 0; i < cb_info.totalmi; i++)
    {
        if ((cb_info.cbchnlentry[i].mi == cbMsgInfo.MsgMI[cbMsgIndex.currCBIndex]) &&
            (strlen((S8*) cb_info.cbchnlentry[i].name) > 0))
        {
            break;
        }
    }
    if (i < cb_info.totalmi)
    {
        if (cb_info.cbchnlentry[i].dcs == PHB_ASCII)
        {
            mmi_asc_to_ucs2(temp, (S8*) cb_info.cbchnlentry[i].name);
        }
        else
        {
            mmi_ucs2cpy(temp, (S8*) cb_info.cbchnlentry[i].name);
        }
    }
    else
    {
        sprintf((PS8) number, "%d", cbMsgInfo.MsgMI[cbMsgIndex.currCBIndex]);
        mmi_asc_to_ucs2(temp, (S8*) number);
    }
    return (U8*) temp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_new_cb_immediate_ind
 * DESCRIPTION
 *  Entry new CB indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_new_cb_immediate_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_MESSAGE_IDLE, mmi_msg_exit_generic, NULL, NULL);
    GetCurrEndKeyDownHandler();

    if (!IsKeyPadLockState())   /* keypad is unlocked */
    {
		mmi_msg_cb_read_content_for_display(cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, TRUE);

        SetMessagesCurrScrnID(SCR_ID_MSG_CB_MESSAGE_IDLE);
        GetCurrEndKeyDownHandler();
        ShowCategory74Screen(
            STR_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_DELETE,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) dispCBMessage,
            (S32) dispCBLength,
            NULL);
        SetLeftSoftkeyFunction(mmi_msg_pre_delete_new_cb_message, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_pre_entry_cb_idle_use_number, KEY_SEND, KEY_EVENT_UP);
    }
    else    /* keypad is locked */
    {
		mmi_msg_cb_read_content_for_display(cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, FALSE);

        ShowCategory74Screen(
            STR_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) dispCBMessage,
            (S32) dispCBLength,
            NULL);
        /* prevent category scrolling */
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_new_cb_normal_ind
 * DESCRIPTION
 *  Entry new CB indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_new_cb_normal_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_MESSAGE_IND, mmi_msg_exit_generic, NULL, NULL);
    SetMessagesCurrScrnID(SCR_ID_MSG_CB_MESSAGE_IND);
    GetCurrEndKeyDownHandler();

#ifndef __MMI_DUAL_SIM_MASTER__
    if (!IsKeyPadLockState())   /* keypad is unlocked */
    {
        ShowCategory154Screen(
            0,
            0,
            STR_SCR6035_LSK,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            (PU8) GetString(STR_NEW_MESSAGE_FROM_ID),
            (PU8) mmi_msg_get_new_cb_ind_string(),
            IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
            NULL);
        SetRightSoftkeyFunction(mmi_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_msg_entry_new_cb_immediate_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else    /* keypad is locked */
    {
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) GetString(STR_NEW_MESSAGE_FROM_ID),
            (PU8) mmi_msg_get_new_cb_ind_string(),
            IMG_NEW_MESSAGE_NOTIFICATION_MSG_IN_IDLE,
            NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
	if (!IsKeyPadLockState())   /* keypad is unlocked */
    {
        ShowCategory154Screen(
            0,
            0,
            STR_SCR6035_LSK,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_SMS_COMMON_NOIMAGE,
            (PU8) GetString(STRING_MTPNP_NEW_MASTER_MESSAGE_FROM_ID),
            (PU8) mmi_msg_get_new_cb_ind_string(),
            IMG_NEW_MESSAGE_NOTIFICATION_MSG,
            NULL);
        SetRightSoftkeyFunction(mmi_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_msg_entry_new_cb_immediate_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else    /* keypad is locked */
    {
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) GetString(STRING_MTPNP_NEW_MASTER_MESSAGE_FROM_ID),
            (PU8) mmi_msg_get_new_cb_ind_string(),
            IMG_NEW_MESSAGE_NOTIFICATION_MSG,
            NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_new_cb_ind
 * DESCRIPTION
 *  Entry new CB indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_ENTRY_NEW_CB_IND_TWO_MODE, cb_display.immediate[cbMsgIndex.currCBIndex]);

    if (cb_display.immediate[cbMsgIndex.currCBIndex] == TRUE)
    {
        mmi_msg_entry_new_cb_immediate_ind();
    }
    else if (GetMessagesCurrScrnID() != SCR_ID_MSG_CB_MESSAGE_IDLE)
    {
        mmi_msg_entry_new_cb_normal_ind();
    }
}

#else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_new_cb_ind
 * DESCRIPTION
 *  Entry new CB indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_ENTRY_NEW_CB_IND_SINGLE_MODE);
	EntryNewScreen(SCR_ID_MSG_CB_MESSAGE_IDLE, mmi_msg_exit_generic, NULL, NULL);

    if (IsKeyPadLockState() == 0)
    {
		mmi_msg_cb_read_content_for_display(cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, TRUE);

        SetMessagesCurrScrnID(SCR_ID_MSG_CB_MESSAGE_IDLE);
        GetCurrEndKeyDownHandler();
        ShowCategory74Screen(
            STR_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_DELETE,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) dispCBMessage,
            (S32) dispCBLength,
            NULL);
        SetLeftSoftkeyFunction(mmi_msg_pre_delete_new_cb_message, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_msg_go_back_from_new_cb_ind, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_pre_entry_cb_idle_use_number, KEY_SEND, KEY_EVENT_UP);
    }
    else
    {
		mmi_msg_cb_read_content_for_display(cbMsgIndex.currCBIndex, MMI_CB_CONTENT_FOR_NEW_POPUP_IND, FALSE);

        ShowCategory74Screen(
            STR_CB_MSG_IND_INFORMATION_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (PU8) dispCBMessage,
            (S32) dispCBLength,
            NULL);
        /* prevent category scrolling */
        SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
}
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_delete_new_cb_message
 * DESCRIPTION
 *  pre delete new cb message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_delete_new_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_MSG_CB_MESSAGE_IDLE;
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    h.entryFuncPtr = mmi_msg_entry_new_cb_immediate_ind;
#else /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
	h.entryFuncPtr = mmi_msg_entry_new_cb_ind;
#endif /* __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__ */
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);

	mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_DELETE_MESSAGE_QUERY, mmi_msg_delete_new_cb_message, GoBackHistory);
	mmi_msg_entry_confirm_generic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_need_new_cb_ind
 * DESCRIPTION
 *  Check if new CB indication is needed
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: indication needed, FALSE: indication not needed
 *****************************************************************************/
U8 mmi_msg_need_new_cb_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_NEED_NEW_CB_IND, cbMsgIndex.currCBTotal);

    if (cbMsgIndex.currCBTotal == 0)
    {
        return FALSE;
    }
    for (i = (cbMsgIndex.currCBTotal - 1);; i--)
    {
        if (cb_display.unread[i] == TRUE)
        {
            cbMsgIndex.currCBIndex = i;
			MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_NEED_NEW_CB_IND_1, i);

            return TRUE;
        }
        if (i == 0)
        {
            break;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_restore_cb
 * DESCRIPTION
 *  Restore CB settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_restore_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_DEFAULT_SETTINGS_MODE_STATE;
    SetProtocolEventHandler(mmi_msg_subscribe_cb_rsp, PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP);
    mmi_msg_subscribe_cb_req(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_subscribe_cb
 * DESCRIPTION
 *  Subscribe CB
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_subscribe_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode = !cb_info.mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    SetProtocolEventHandler(mmi_msg_subscribe_cb_rsp, PRT_MSG_ID_MMI_CB_SUBSCRIBE_RSP);
    mmi_msg_subscribe_cb_req(mode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_save_cb_channel
 * DESCRIPTION
 *  Save CB channel info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_save_cb_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mi = 0;
    U8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH] = {0, 0};
    U16 length;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_ucs2strlen((S8*) cb_display.mi)) == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) WARNING_TONE);
        return;
    }
    memset(&number, 0, (MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH);
    length = mmi_ucs2_n_to_asc(
                (S8*) number,
                (S8*) cb_display.mi,
                (mmi_ucs2strlen((S8*) cb_display.mi)) * ENCODING_LENGTH);
    number[length] = '\0';
    mi = atoi((S8*) number);
    if (mi > MAX_CB_CHNL_NUMBER)
    {
        DisplayPopup(
            (PU8) GetString(STR_CB_CHNL_NUMBER_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    for (i = 0; i < cb_info.totalmi; i++)
    {
        if ((cb_state == SMS_CB_CHNL_EDIT_STATE) && (i == g_msg_cntx.currHiliteIndex))
        {
            continue;
        }
        if (cb_info.cbchnlentry[i].mi == (U16) mi)
        {
            DisplayPopup(
                (PU8) GetString(STR_CB_CHNL_DUPLICATE_NUMBER_NOT_ALLOWED),
                IMG_GLOBAL_UNFINISHED,
                1,
                MESSAGES_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }
    }
    if (cb_state == SMS_CB_CHNL_ADD_STATE)
    {
        mmi_msg_add_cb_channel((U16) mi);
    }
    else
    {
        mmi_msg_edit_cb_channel((U16) mi);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_save_cb_channel
 * DESCRIPTION
 *  Save CB channel info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_save_cb_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 query_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_state == SMS_CB_CHNL_ADD_STATE)
    {
    	query_str_id = STR_ID_MSG_CB_ADD_CHANNEL_QUERY;
    }
    else
    {
    	query_str_id = STR_ID_MSG_SMS_SAVE_CHANGES_QUERY;	
    }
    mmi_msg_set_confirm_screen(query_str_id, mmi_msg_save_cb_channel, Messages2GoBackHistory);
    mmi_msg_entry_confirm_generic();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_select_cb_channel
 * DESCRIPTION
 *  Select CB channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_select_cb_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cb_info.totalmi; i++)
    {
        cb_info.cbchnlentry[i].mask = cb_display.mask[i + 1];
    }
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(mmi_msg_set_cb_mode_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    mmi_msg_set_cb_mode_req(SMSAL_CB_MI_MASK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_add_cb_channel
 * DESCRIPTION
 *  Add CB channel
 * PARAMETERS
 *  mi      [IN]        Mi to be added
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_add_cb_channel(U16 mi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_info.cbchnlentry[cb_info.totalmi].index = cb_display.addindex;
    cb_info.cbchnlentry[cb_info.totalmi].mask = 1;
    cb_info.cbchnlentry[cb_info.totalmi].mi = mi;
    memset(cb_info.cbchnlentry[cb_info.totalmi].name, 0, ENCODING_LENGTH);
    if (GetUCS2Flag((PS8) cb_display.name))
    {
        cb_display.dcs = PHB_UCS2;
    }
    else
    {
        cb_display.dcs = PHB_ASCII;
    }
    if (cb_display.dcs == PHB_ASCII)
    {
        mmi_ucs2_to_asc((S8*) cb_info.cbchnlentry[cb_info.totalmi].name, (S8*) cb_display.name);
    }
    else
    {
        mmi_ucs2cpy((S8*) cb_info.cbchnlentry[cb_info.totalmi].name, (S8*) cb_display.name);
    }
    cb_info.cbchnlentry[cb_info.totalmi].dcs = cb_display.dcs;
    /* delete if apply new interface */
    memset(cbNvramStruct.chnlNames[cb_info.totalmi].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
    memcpy(
        cbNvramStruct.chnlNames[cb_info.totalmi].name,
        (S8*) cb_info.cbchnlentry[cb_info.totalmi].name,
        MAX_CB_CHNL_NAME_LENGTH);
    cbNvramStruct.chnlNames[cb_info.totalmi].name_dcs = cb_display.dcs;
    cbNvramStruct.l4MidIndex[cb_info.totalmi] = cb_display.addindex;
    WriteCbChnlInfoToNvram();
    /* end */
    cb_info.totalmi++;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(mmi_msg_set_cb_mode_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    mmi_msg_set_cb_mode_req(SMSAL_CB_MI | SMSAL_CB_MI_MASK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_edit_cb_channel
 * DESCRIPTION
 *  Edit CB channel
 * PARAMETERS
 *  mi      [IN]        Mi to be modified
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_edit_cb_channel(U16 mi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].mi = mi;
    memset(cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
    if (GetUCS2Flag((PS8) cb_display.name))
    {
        cb_display.dcs = PHB_UCS2;
    }
    else
    {
        cb_display.dcs = PHB_ASCII;
    }
    if (cb_display.dcs == PHB_ASCII)
    {
        mmi_ucs2_n_to_asc(
            (S8*) cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name,
            (S8*) cb_display.name,
            MAX_CB_CHNL_NAME_LENGTH * ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2cpy((S8*) cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name, (S8*) cb_display.name);
    }
    cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].dcs = cb_display.dcs;
    /* delete if apply new interface */
    memset(cbNvramStruct.chnlNames[g_msg_cntx.currHiliteIndex].name, 0, MAX_CB_CHNL_NAME_LENGTH + 1);
    memcpy(
        cbNvramStruct.chnlNames[g_msg_cntx.currHiliteIndex].name,
        (S8*) cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name,
        MAX_CB_CHNL_NAME_LENGTH);
    cbNvramStruct.chnlNames[g_msg_cntx.currHiliteIndex].name_dcs = cb_display.dcs;
    WriteCbChnlInfoToNvram();
    /* end */
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(mmi_msg_set_cb_mode_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    mmi_msg_set_cb_mode_req(SMSAL_CB_MI);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_cb_channel
 * DESCRIPTION
 *  Delete CB channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_cb_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = (g_msg_cntx.currHiliteIndex + 1); i < cb_info.totalmi; i++)
    {
        memcpy(&cb_info.cbchnlentry[i - 1], &cb_info.cbchnlentry[i], sizeof(msg_cb_channel_struct));
    }
    cb_info.totalmi--;
    cb_info.cbchnlentry[cb_info.totalmi].mi = SMSAL_CB_UNUSED_CBMI;
    cb_info.cbchnlentry[cb_info.totalmi].mask = 0;
    memset(cb_info.cbchnlentry[cb_info.totalmi].name, 0, MAX_CB_CHNL_NAME_LENGTH);
    memset(&cbNvramStruct, 0xff, sizeof(msg_cb_channel_nvram_struct));
    for (i = 0; i < cb_info.totalmi; i++)
    {
        cbNvramStruct.l4MidIndex[i] = cb_info.cbchnlentry[i].index;
        cbNvramStruct.chnlNames[i].name_dcs = cb_info.cbchnlentry[i].dcs;
        memcpy((S8*) cbNvramStruct.chnlNames[i].name, (S8*) cb_info.cbchnlentry[i].name, MAX_CB_CHNL_NAME_LENGTH + 1);
    }
    WriteCbChnlInfoToNvram();
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(mmi_msg_set_cb_mode_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    mmi_msg_set_cb_mode_req(SMSAL_CB_MI | SMSAL_CB_MI_MASK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_select_cb_language
 * DESCRIPTION
 *  Select CB language
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_select_cb_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cb_info.totaldcs; i++)
    {
        cb_info.cblanentry[i].mask = cb_display.mask[i + 1];
    }
    cb_info.dcsall = cb_display.mask[0];
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetProtocolEventHandler(mmi_msg_set_cb_mode_rsp, PRT_MSG_ID_MMI_SMS_SET_CB_MODE_RSP);
    mmi_msg_set_cb_mode_req(SMSAL_CB_DCS_MASK | SMSAL_CB_ALL_LANG);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_refresh_cb_main_menu
 * DESCRIPTION
 *  Refresh CB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_refresh_cb_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCR_ID_MSG_CB_MAIN_MENU)
    {
        S32 index = GetChildMenuIDIndexByParentMenuID(MESSAGES_MENU_CB_MENUID, MITEM102_CB_SERVICE);;
        if (index != -1)
        {
            Category52ChangeItemDescription(index, cb_display.mode);
        }
        if (cb_info.mode == TRUE)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
        }
        SetLeftSoftkeyFunction(mmi_msg_subscribe_cb, KEY_EVENT_UP);
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_main_menu
 * DESCRIPTION
 *  Entry CB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *popUpList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_MAIN_MENU, mmi_msg_exit_generic, mmi_msg_entry_cb_main_menu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_MAIN_MENU);

    numItems = GetNumOfChild(MESSAGES_MENU_CB_MENUID);
    GetSequenceStringIds(MESSAGES_MENU_CB_MENUID, nStrItemList);
    SetParentHandler(MESSAGES_MENU_CB_MENUID);
    ConstructHintsList(MESSAGES_MENU_CB_MENUID, popUpList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_CB_MAIN_MENU);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MAIN_MENU);

    ShowCategory52Screen(
        STR_CB_MENUENTRY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        popUpList,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_main_menu
 * DESCRIPTION
 *  Get CB mode request before entry CB main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_sms_get_sms_list_size(MMI_FRM_SMS_NOBOX) == MMI_FRM_SMS_INVALID_INDEX)
    {
        DisplayPopup(
            (PU8) GetString(STR_CB_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }
    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    else if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    cb_state = SMS_CB_SERVICE_MODE_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_active, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_settings
 * DESCRIPTION
 *  Entry CB channel settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_CHNL_SETTING_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_channel_settings
 * DESCRIPTION
 *  Entry CB channel settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_channel_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_CHANNEL_SETTINGS, mmi_msg_exit_generic, mmi_msg_entry_cb_channel_settings, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_CHANNEL_SETTINGS);

    if (IsCBChannelFull == TRUE)
    {
        mmi_frm_hide_menu_item(MITEM104_CB_CHANNEL_ADD);
    }
    else
    {
        mmi_frm_unhide_menu_item(MITEM104_CB_CHANNEL_ADD);
    }
    numItems = GetNumOfChild_Ext(MITEM103_CB_CHANNEL_ENBL_OPTIONS);
    GetSequenceStringIds_Ext(MITEM103_CB_CHANNEL_ENBL_OPTIONS, nStrItemList);

    SetParentHandler(MITEM103_CB_CHANNEL_ENBL_OPTIONS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetMessagesCurrScrnID(SCR_ID_MSG_CB_CHANNEL_SETTINGS);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_CHANNEL_SETTINGS);

    ShowCategory52Screen(
        STR101_MITEM102_CB_CHANNELS,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_bootup
 * DESCRIPTION
 *  Get CB mode request in bootup procedure.
 *  This is for filling up cb_info to display channel name when getting a CB message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_BOOT_UP_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_channel_select
 * DESCRIPTION
 *  Entry CB channel select screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_channel_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U16 numItems;
    U8 i = 0;
    U8 selectall = TRUE;
    U8 number[MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_CHANNEL_LIST, mmi_msg_exit_generic, mmi_msg_entry_cb_channel_select, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_CHANNEL_LIST);

    mmi_ucs2ncpy(
        (S8*) subMenuDataPtrs[0],
        (S8*) GetString((U16) STR_CB_ALL_CHANNELS_FOR_SELECT),
        MAX_CB_CHNL_NAME_LENGTH * ENCODING_LENGTH);
    for (i = 0; i < cb_info.totalmi; i++)
    {
        if (strlen((S8*) cb_info.cbchnlentry[i].name) == 0)
        {
            memset(number, 0, sizeof(number));
            sprintf((PS8) number, "%d", cb_info.cbchnlentry[i].mi);
            mmi_asc_to_ucs2((S8*) subMenuDataPtrs[i + 1], (S8*) number);
        }
        else
        {
            if (cb_info.cbchnlentry[i].dcs == PHB_ASCII)
            {
                mmi_asc_to_ucs2((S8*) subMenuDataPtrs[i + 1], (S8*) cb_info.cbchnlentry[i].name);
            }
            else
            {
                mmi_ucs2cpy((S8*) subMenuDataPtrs[i + 1], (S8*) cb_info.cbchnlentry[i].name);
            }
        }
        cb_display.mask[i + 1] = cb_info.cbchnlentry[i].mask;
        if (cb_display.mask[i + 1] == 0)
        {
            selectall = FALSE;
        }
    }

    cb_display.mask[0] = selectall;
    numItems = cb_info.totalmi + 1;

    SetMessagesCurrScrnID(SCR_ID_MSG_CB_CHANNEL_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_CHANNEL_LIST);

    mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_SAVE_CHANGES_QUERY, mmi_msg_select_cb_channel, Messages2GoBackHistory);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    ShowCategory140Screen(
        STR_CB_SELECT_CHNL,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        numItems,
        (U8 **) subMenuDataPtrs,
        (U8*) cb_display.mask,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(special_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_select
 * DESCRIPTION
 *  Get CB mode request before enter CB channel select
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_CHNL_SELECT_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_channel_list
 * DESCRIPTION
 *  Entry CB channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_CHANNEL_LIST, mmi_msg_exit_generic, mmi_msg_entry_cb_channel_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_CHANNEL_LIST);
    if (guiBuffer != NULL)
    {
        hiliteitem = (g_msg_cntx.currHiliteIndex < cb_info.totalmi) ? g_msg_cntx.currHiliteIndex : 0;
    }
    RegisterHighlightHandler(GetHiliteIndex);

    SetMessagesCurrScrnID(SCR_ID_MSG_CB_CHANNEL_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_CHANNEL_LIST);
    ShowCategory184Screen(
        STR_CB_CHNL_LIST,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        cb_info.totalmi,
        mmi_msg_cb_channel_list_get_item,
        mmi_msg_cb_channel_list_get_hint,
        hiliteitem,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (cb_state == SMS_CB_CHNL_EDIT_STATE)
    {
        SetLeftSoftkeyFunction(mmi_msg_pre_entry_cb_channel_edit, KEY_EVENT_UP);
    }
    else
    {
        mmi_msg_set_confirm_screen(STR_ID_MSG_CB_DELETE_CHANNEL_QUERY, mmi_msg_delete_cb_channel, GoBackHistory);
        SetLeftSoftkeyFunction(mmi_msg_entry_confirm_generic, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_channel_list_get_item
 * DESCRIPTION
 *  Get CB channel list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_cb_channel_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= cb_info.totalmi))
    {
        return FALSE;
    }

    if (cb_info.cbchnlentry[item_index].dcs == PHB_ASCII)
    {
        if (strlen((S8*) cb_info.cbchnlentry[item_index].name) == 0)
        {
            memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
            sprintf((PS8) number, "%d", cb_info.cbchnlentry[item_index].mi);
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) number);
        }
        else
        {
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) cb_info.cbchnlentry[item_index].name);
        }
    }
    else
    {
        if (mmi_ucs2strlen((S8*) cb_info.cbchnlentry[item_index].name) == 0)
        {
            memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
            sprintf((PS8) number, "%d", cb_info.cbchnlentry[item_index].mi);
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) number);
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) cb_info.cbchnlentry[item_index].name);
        }
    }
    *img_buff_p = get_image(IMG_CB_CHNL_TITLE);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_channel_list_get_hint
 * DESCRIPTION
 *  Get CB channel list hint
 * PARAMETERS
 *  item_index      [IN]            
 *  hint_array      [?]             
 *  a(?)            [IN]            Item index
 *  b(?)            [IN/OUT]        Hint array
 * RETURNS
 *  TRUE: display hint, FALSE: not display hint
 *****************************************************************************/
S32 mmi_msg_cb_channel_list_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen((S8*) cb_info.cbchnlentry[item_index].name) == 0)
    {
        return 0;
    }

    memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
    sprintf((PS8) number, "%d", cb_info.cbchnlentry[item_index].mi);
    mmi_asc_n_to_ucs2((S8*) hint_array[0], (S8*) number, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_add
 * DESCRIPTION
 *  Before add CB channel, check if unused CBMI available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_CHNL_ADD_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_list_edit
 * DESCRIPTION
 *  Before enter CB channel edit, get chennel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_list_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_CHNL_EDIT_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_list_delete
 * DESCRIPTION
 *  Before enter CB channel delete, get chennel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_list_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_CHNL_DELETE_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_cb_channel_inline_item
 * DESCRIPTION
 *  Set CB channel inline item for channel edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_cb_channel_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_CB_CHNL_TITLE));
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[1],
        STR_CB_CHNL_TITLE_FULL_EDIT,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        (U8*) cb_display.name,
        MAX_CB_CHNL_NAME_LENGTH + 1,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_msg_inline_generic_custom_function);
    SetInlineItemCaption(&wgui_inline_items[2], (U8*) GetString(STR_CB_CHNL_NUMBER));
    SetInlineItemTextEdit(
        &wgui_inline_items[3],
        (U8*) cb_display.mi,
        MAX_CB_CHNL_NUMBER_LENGTH + 1,
        INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[3]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_channel_edit
 * DESCRIPTION
 *  Entry CB channel edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;
    PU8 inputBuffer = NULL;
    U16 inputBufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_CHANNEL_EDIT, mmi_msg_exit_cb_channel_edit, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_CHANNEL_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_MSG_CB_CHANNEL_EDIT, &inputBufferSize);
    InitializeCategory57Screen();
    mmi_msg_set_cb_channel_inline_item();
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_CB_CHNL_INLINE_ITEM, inputBuffer);
    }

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_CHANNEL_EDIT);
    SetMessagesCurrScrnID(SCR_ID_MSG_CB_CHANNEL_EDIT);

    ShowCategory57Screen(
        STR_CB_CHNL_EDITOR,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_CB_CHNL_INLINE_ITEM,
        cbChnlEditorIcons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_msg_pre_save_cb_channel, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_cb_channel_edit
 * DESCRIPTION
 *  Exit CB channel inline edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_cb_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = SCR_ID_MSG_CB_CHANNEL_EDIT;
    SetMessagesCurrScrnID(0);

    currHistory.scrnID = SCR_ID_MSG_CB_CHANNEL_EDIT;
    CloseCategory57Screen();
    currHistory.entryFuncPtr = mmi_msg_entry_cb_channel_edit;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_channel_edit
 * DESCRIPTION
 *  Before edit CB channel, set the item for edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].mi > MAX_CB_CHNL_NUMBER_TO_EDIT)
    {
        DisplayPopup(
            (PU8) GetString(STR_CB_CHNL_NUMBER_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    cb_display.dcs = cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].dcs;
    if (cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].dcs == PHB_ASCII)
    {
        mmi_asc_to_ucs2((S8*) cb_display.name, (S8*) cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name);
    }
    else
    {
        mmi_ucs2cpy((S8*) cb_display.name, (S8*) cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].name);
    }

    memset(number, 0, sizeof(number));
    sprintf((S8*) number, "%d", cb_info.cbchnlentry[g_msg_cntx.currHiliteIndex].mi);
    memset(cb_display.mi, 0, sizeof(cb_display.mi));
    mmi_asc_n_to_ucs2((S8*) cb_display.mi, (S8*) number, strlen((S8*) number));
    mmi_msg_entry_cb_channel_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_language
 * DESCRIPTION
 *  Entry CB language list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 numItems;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_LANGUAGE, mmi_msg_exit_generic, mmi_msg_entry_cb_language, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_LANGUAGE);

    mmi_ucs2ncpy(
        (S8*) subMenuDataPtrs[0],
        (S8*) GetString((U16) STR_CB_ALL_LANGUAGES_FOR_SELECT),
        MAX_CB_CHNL_NAME_LENGTH * ENCODING_LENGTH);
    for (i = 0; i < cb_info.totaldcs; i++)
    {
        mmi_ucs2cpy(
            (S8*) subMenuDataPtrs[i + 1],
            (PS8) GetString((U16) LangEnumAndStrID[cb_info.cblanentry[i].langType]));
        cb_display.mask[i + 1] = cb_info.cblanentry[i].mask;
    }
    cb_display.mask[0] = cb_info.dcsall;
    numItems = cb_info.totaldcs + 1;

    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_LANGUAGE);
    SetMessagesCurrScrnID(SCR_ID_MSG_CB_LANGUAGE);

    mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_SAVE_CHANGES_QUERY, mmi_msg_select_cb_language, Messages2GoBackHistory);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_msg_entry_confirm_generic, GoBackHistory);
    ShowCategory140Screen(
        STR103_SCR101_CAPTION,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        numItems,
        (U8 **) subMenuDataPtrs,
        (U8*) cb_display.mask,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(special_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_language
 * DESCRIPTION
 *  Before enter CB language screen, get language list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_state = SMS_CB_LANGUAGE_STATE;
    SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_language, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
    mmi_msg_get_cb_mode_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_read_message
 * DESCRIPTION
 *  Entry CB message list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_read_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_MESSAGE_LIST, mmi_msg_exit_generic, mmi_msg_entry_cb_read_message, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_MESSAGE_LIST);

    if ((guiBuffer != NULL) || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_ID_MSG_CB_MESSAGE_LIST)
        || (g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes == SCR_ID_MSG_CB_MESSAGE))
    {
    	list_menu_category_history *h;

		hiliteitem = (cb_display.msg_hilite_index < cbMsgIndex.currCBTotal) ? cb_display.msg_hilite_index : 0;
		h = (list_menu_category_history*)guiBuffer;
 		h->highlighted_item = (S16)hiliteitem;
	}
    RegisterHighlightHandler(mmi_msg_cb_get_msg_list_index);

    SetMessagesCurrScrnID(SCR_ID_MSG_CB_MESSAGE_LIST);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MESSAGE_LIST);
    ShowCategory184Screen(
        STR101_MITEM102_CB_READ_MESSAGE,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        cbMsgIndex.currCBTotal,
        mmi_msg_cb_read_message_get_item,
        NULL,
        hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_msg_pre_entry_cb_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_pre_entry_cb_message, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_read_message
 * DESCRIPTION
 *  Before entering CB message list screen, get channel info for display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_read_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cbMsgIndex.currCBTotal == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
        cb_state = SMS_CB_READ_MESSAGE_STATE;
        SetProtocolEventHandler(mmi_msg_get_cb_mode_rsp_display, PRT_MSG_ID_MMI_SMS_GET_CB_MODE_RSP);
        mmi_msg_get_cb_mode_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_read_message_get_item
 * DESCRIPTION
 *  Get CB message list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_msg_cb_read_message_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[(MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1) * ENCODING_LENGTH];
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= cbMsgIndex.currCBTotal))
    {
        return FALSE;
    }

    for (i = 0; i < cb_info.totalmi; i++)
    {
        if ((cb_info.cbchnlentry[i].mi == cbMsgInfo.MsgMI[item_index]) &&
            (strlen((S8*) cb_info.cbchnlentry[i].name) > 0))
        {
            break;
        }
    }
    if (i < cb_info.totalmi)
    {
        if (cb_info.cbchnlentry[i].dcs == PHB_ASCII)
        {
            mmi_asc_to_ucs2((S8*) str_buff, (S8*) cb_info.cbchnlentry[i].name);
        }
        else
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) cb_info.cbchnlentry[i].name);
        }
    }
    else
    {
        memset(number, 0, MAX_CB_CHNL_NUMBER_DISPLAY_LENGTH + 1);
        sprintf((PS8) number, "%d", cbMsgInfo.MsgMI[item_index]);
        mmi_asc_to_ucs2((S8*) str_buff, (S8*) number);
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_go_back_from_cb_message
 * DESCRIPTION
 *  Reset current display index before go back screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_go_back_from_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* When new cb message arrival, it will add message or delete some message(no space to store it);
	 * If the cb_display.currindex changed In the cb message view screen,
	 * then back to the cb message list, the highlight will be change to 
	 * the original message index(cb_display.currindex)which the cb message view screen show.
	 */
	if (cb_display.currindex != MAX_STORE_CB_MSG)
	{
		cb_display.msg_hilite_index = cb_display.currindex;
	}

    cb_display.currindex = MAX_STORE_CB_MSG;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_end_key_from_cb_message
 * DESCRIPTION
 *  Reset current display index before go to idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_end_key_from_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() == FALSE)
    {
        cb_display.currindex = MAX_STORE_CB_MSG;
    }
    ExecCurrEndKeyDownHandler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_message
 * DESCRIPTION
 *  Pre-Entry CB message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_display.currindex = cb_display.msg_hilite_index;
	mmi_msg_cb_read_content_for_display(cb_display.currindex, MMI_CB_CONTENT_FOR_READ_MESSAGE, TRUE);
	mmi_msg_entry_cb_message();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_message
 * DESCRIPTION
 *  Entry CB message screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_MSG_CB_MESSAGE, mmi_msg_exit_generic, mmi_msg_entry_cb_message, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_MESSAGE);

    SetMessagesCurrScrnID(SCR_ID_MSG_CB_MESSAGE);
    SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MESSAGE);

    mmi_msg_set_confirm_screen(STR_ID_MSG_SMS_DELETE_MESSAGE_QUERY, mmi_msg_delete_cb_message, GoBackHistory);
    GetCurrEndKeyDownHandler();
    ShowCategory74Screen(
        STR_CB_MESSAGE_BODY,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_DELETE,
        IMG_SMS_COMMON_NOIMAGE,
        STR_GLOBAL_BACK,
        IMG_SMS_COMMON_NOIMAGE,
        (PU8) dispCBMessage,
        (S32) (cbMsgInfo.MsgPage[cb_display.currindex] * NVRAM_SMS_CB_SMS_PAGE_SIZE * ENCODING_LENGTH),
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_msg_entry_confirm_generic, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_msg_go_back_from_cb_message, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_go_back_from_cb_message, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_end_key_from_cb_message, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_msg_entry_cb_use_number, KEY_SEND, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_cb_message
 * DESCRIPTION
 *  Delete CB message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_delete_cb_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_MMI_MSG_DELETE_CB_MESSAGE, cb_display.currindex);

    SetMessagesScrnIdDelUpToHistoryNodes(SCR_ID_MSG_CB_MESSAGE);
    if (cbMsgInfo.MsgPage[cb_display.currindex] > 0)
    {
    	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_MMI_MSG_DELETE_CB_MESSAGE_1);
		if (cbMsgIndex.pCBMsgContent != NULL)
		{
			OslMfree(cbMsgIndex.pCBMsgContent);
			cbMsgIndex.pCBMsgContent = NULL;
		}


        DeleteCBMessage(cb_display.currindex);
        WriteCBMessageInfoToNvram();

        if (cbMsgIndex.currCBTotal == 0)
        {
            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MESSAGE_LIST);
        }
        else
        {
            if (cb_display.msg_hilite_index == (U8)cbMsgIndex.currCBTotal)
            {
                cb_display.msg_hilite_index--;
            }
            else if (cb_display.msg_hilite_index > (U8)cbMsgIndex.currCBTotal)
            {
                cb_display.msg_hilite_index = 0;
            }

            SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MESSAGE);
        }
        DisplayPopup(
            (PU8) GetString(STR_MESSAGES_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
        cb_display.currindex = MAX_STORE_CB_MSG;
        DeleteMessagesHistoryNodes();
    }
    else
    {
        SetMessagesScrnIdToDelHistoryNodes(SCR_ID_MSG_CB_MESSAGE_LIST);
        DisplayPopup(
            (PU8) GetString(STR_CB_ERROR_MESSAGE),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        DeleteMessagesHistoryNodes();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_mode
 * DESCRIPTION
 *  Highlight CB mode handler, check current CB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_subscribe_cb,
        GoBackHistory);

    if (cb_info.mode == TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_hint_cb_mode
 * DESCRIPTION
 *  Hint CB mode handler
 * PARAMETERS
 *  index       [IN]        Current menu index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_hint_cb_mode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    mmi_ucs2cpy((S8*) hintData[index], (S8*) cb_display.mode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_read_message
 * DESCRIPTION
 *  Highlight CB read message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_read_message(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_read_message,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_language
 * DESCRIPTION
 *  Highlight CB language handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_language,
        GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_channel_settings
 * DESCRIPTION
 *  Highlight CB channel settings handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_channel_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_channel_settings,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_channel_select
 * DESCRIPTION
 *  Highlight CB channel select handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_channel_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_channel_select,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_channel_add
 * DESCRIPTION
 *  Highlight CB channel add handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_channel_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_channel_add,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_channel_edit
 * DESCRIPTION
 *  Highlight CB channel edit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_channel_list_edit,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_highlight_cb_channel_delete
 * DESCRIPTION
 *  Highlight CB channel delete handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_highlight_cb_channel_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_highlight_generic(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        mmi_msg_pre_entry_cb_channel_list_delete,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_cb_idle_use_number
 * DESCRIPTION
 *  Pre -Entry function for CB use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_cb_idle_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_MSG_CB_MESSAGE_IDLE;
#ifdef __MMI_MESSAGES_TWO_CB_MODES_DISPLAY__
    h.entryFuncPtr = mmi_msg_entry_new_cb_immediate_ind;
#else 
    h.entryFuncPtr = mmi_msg_entry_new_cb_ind;
#endif 
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);

    mmi_msg_entry_cb_use_number();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_entry_cb_use_number
 * DESCRIPTION
 *  Entry function for CB use number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_entry_cb_use_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numbersCount = 0;
    U8 *guiBuffer = NULL;
    S8 number[(MAX_DIGITS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) number, 0, sizeof(number));
    numbersCount = ObtainNumbersFromMessageText((S8*) number, dispCBMessage, (U16) dispCBLength, 0);

    if (numbersCount > 0)
    {
        EntryNewScreen(SCR_ID_MSG_CB_USE_NUMBER_LIST, mmi_msg_exit_generic, mmi_msg_entry_cb_use_number, NULL);
        GetCurrEndKeyDownHandler();

        guiBuffer = GetCurrGuiBuffer(SCR_ID_MSG_CB_USE_NUMBER_LIST);
        RegisterHighlightHandler(GetHiliteIndex);
        SetMessagesCurrScrnID(SCR_ID_MSG_CB_USE_NUMBER_LIST);

        ShowCategory53Screen(
            STR_USE_NUMBER_CAPTION,
            IMG_SMS_ENTRY_SCRN_CAPTION,
            STR_GLOBAL_DIAL,
            IMG_SMS_COMMON_NOIMAGE,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numbersCount,
            (U8 **) g_msg_cntx.numbersList,
            (U16*) gIndexIconsImageList,
            NULL,
            0,
            0,
            guiBuffer);

#ifdef __MMI_DUAL_SIM_MASTER__
       	SetLeftSoftkeyFunction(mmi_msg_dial_use_number_ext, KEY_EVENT_UP);
       	SetKeyHandler(mmi_msg_dial_use_number_ext, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		MTPNP_PFAL_CC_HandleSendKeys(mmi_msg_dial_use_number,KEY_EVENT_UP);
#else /* __MMI_DUAL_SIM_MASTER__ */
        SetLeftSoftkeyFunction(mmi_msg_dial_use_number, KEY_EVENT_UP);
        SetKeyHandler(mmi_msg_dial_use_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_dial_use_number, KEY_SEND, KEY_EVENT_UP);
#endif /* __MMI_DUAL_SIM_MASTER__ */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_msg_end_key_from_new_cb_ind, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_NONUMBER_NOTIFICATION),
            IMG_GLOBAL_EMPTY,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitCellBroadcastProtocolEventHanler
 * DESCRIPTION
 *  Init CB protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCellBroadcastProtocolEventHanler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_msg_handle_new_cb_ind, PRT_MSG_ID_MMI_CB_MSG_IND);
    #ifdef __MMI_DUAL_SIM_SINGLE_CALL__
    SetSlaveProtocolEventHandler(handle_new_cb_ind, PRT_MSG_ID_MMI_CB_MSG_IND);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  InitCBNVRAMData
 * DESCRIPTION
 *  Init CB NVRAMData
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCBNVRAMData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsCBMessageReadOperRequired)
    {
        IsCBMessageReadOperRequired = FALSE;
        ReadCBMessageInfoFromNvram();
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitCellBroadcastApp
 * DESCRIPTION
 *  Init CB application: highlight handler, data structure
 * PARAMETERS
 *  void
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void InitCellBroadcastApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_INIT_CELL_BROADCAST_APP);

    /* Set Hilite Handlers */
    SetHiliteHandler(MITEM102_CB_SERVICE, mmi_msg_highlight_cb_mode);
    SetHintHandler(MITEM102_CB_SERVICE, mmi_msg_hint_cb_mode);
    SetHiliteHandler(MITEM102_CB_READ_MESSAGE, mmi_msg_highlight_cb_read_message);
    SetHiliteHandler(MITEM102_CB_LANGUAGE, mmi_msg_highlight_cb_language);
    SetHiliteHandler(MITEM102_CB_CHANNELS, mmi_msg_highlight_cb_channel_settings);
    SetHiliteHandler(MITEM104_CB_CHANNEL_ADD, mmi_msg_highlight_cb_channel_add);
    SetHiliteHandler(MITEM104_CB_CHANNEL_EDIT, mmi_msg_highlight_cb_channel_edit);
    SetHiliteHandler(MITEM104_CB_CHANNEL_DELETE, mmi_msg_highlight_cb_channel_delete);
    SetHiliteHandler(MITEM104_CB_CHANNEL_SELECT, mmi_msg_highlight_cb_channel_select);
}


/*****************************************************************************
 * FUNCTION
 *  ResetCBInfoStructs
 * DESCRIPTION
 *  Reset Cb info structures
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCBInfoStructs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_RESET_CB_INFO_STRUCTS);

    memset(&cbNvramStruct, 0, sizeof(msg_cb_channel_nvram_struct));
    memset(&cbMsgInfo, 0, sizeof(msg_cb_msg_info_struct));
    memset(&cbMsgIndex, 0, sizeof(msg_cb_msg_index_struct));

	cb_display.currindex = MAX_STORE_CB_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  DeInitCellBroadcastApp
 * DESCRIPTION
 *  Deinit Cb applications: reset data structures, write CB message to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeInitCellBroadcastApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_TRACE_G6_SMS, TRC_MMI_CB_DEINIT_CELL_BROADCAST_APP);
   
    WriteCBMessageInfoToNvram();
    memset(&cbNvramStruct, 0, sizeof(msg_cb_channel_nvram_struct));
    memset(&cbMsgIndex, 0, sizeof(msg_cb_msg_info_struct));
    memset(&cbMsgIndex, 0, sizeof(msg_cb_msg_index_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_remove_fill_bit
 * DESCRIPTION
 *  Remove Fill Bit [CR]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_cb_remove_fill_bit(U8* buffer, U32 max_buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16* in = (U16*)buffer;
	U16* out = (U16*)buffer;
	U16 curr_char = *in;
	U16 pre_char = '\0';
	U16 skip_count = 0;
	U32 len = max_buff_len / ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while ((curr_char != '\0') && (len > 0))
   	{	
   		//If Only save a CR ('\n') char
		if ((pre_char == 0x0D) && (curr_char == 0x0D))
		{
			skip_count++;
		}
		else
		{
			*out = *in;
			out++;
		}

		in++;
		len --;
		
		pre_char = curr_char;
		curr_char = *in;
	}


	if (skip_count > 0)
	{
		memset((U8*)out, 0, skip_count * ENCODING_LENGTH);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_cb_get_msg_list_index
 * DESCRIPTION
 *  Get current highlight cb message list index
 * PARAMETERS
 *  nIndex      [IN]         Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_cb_get_msg_list_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cb_display.msg_hilite_index = (U8)nIndex;
}


#endif /* __MOD_SMSAL__ */ 
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

