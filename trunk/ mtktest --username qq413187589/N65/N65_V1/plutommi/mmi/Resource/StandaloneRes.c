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
 *   StandaloneRes.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements standalone resource related functions
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
 *******************************************************************************/

#include "MMI_features.h"

#include "string.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "gui_themes.h"
#include "FontDcl.h"
#include "wgui.h"
#include "DownloadProtos.h"
#include "pwic.h"
#include "IMERes.h"

#include "custom_jump_tbl.h"
#include "verno.h"
#ifdef __J2ME__
#include "j2me_custom.h"
#endif 

#if (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI))
extern void MMIResourceMismatchWarning(
                kal_int8 errType,
                kal_int8 errResType,
                kal_uint8 const *codeversion,
                kal_uint8 const *resversion);
#endif /* (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)) */ 

#include "resource_audio.h"
#include "nvram_user_defs.h"
#include "resource_custpack_jtbl.h"
#if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
#include "custom_wap_config.h"
#endif 

/* IMAGE variables */
extern void *image2ndJumpTbl[];
extern Type_Preamble_Content ImageResPreamble;
CUSTOM_IMAGE *nCustImageNames = NULL;
U16 CurrMaxImageNum = 0;
S32 n_MMI_themes = 0;

char *mmi_theme_phone_model;


#ifdef __MMI_THEMES_V2_SUPPORT__
theme_details_struct *MMI_themes;
#else 
MMI_theme **MMI_themes = NULL;
#endif 

/* 101205 audio resource Calvin Start */
/* AUTOGEN AUDIO variables */
extern void *autogenaudio2ndJumpTbl[];
extern Type_Preamble_Content AutogenAudioResPreamble;
CUSTOM_AUDIO *nCustAudioNames = NULL;
U16 CurrMaxAudioNum = 0;

/* 101205 audio resource Calvin End */

/* Audio variables */
extern const device_tones_struct *mtk_resource_tones[];
extern const audio_resource_struct mtk_resource_midis[];
extern const audio_resource_struct mtk_resource_sounds[];
extern const audio_resource_struct mtk_resource_ems_sounds[];
extern const audio_resource_struct mtk_resource_imelodys[];
extern const audio_resource_struct mtk_resource_ems_imelodys[];
extern const audio_resource_struct mtk_resource_message_sounds[];
extern const audio_resource_struct mtk_resource_mms_sounds[];

#ifdef DIGIT_TONE_SUPPORT
extern const audio_resource_struct mtk_resource_human_voice_tones[];
#endif 
#ifdef SIMPLE_TTS
extern const audio_resource_struct mtk_resource_tts_sounds[];
extern const start_end_t mtk_TTS_UCS2_MSB_index[];
extern const unsigned char mtk_TTS_UCS2_LSB[];
extern const unsigned short mtk_TTS_index_table[];
#endif /* SIMPLE_TTS */ 
#ifdef CUST_KEYPAD_TONE_SUPPORT
extern const audio_resource_struct mtk_resource_keypad_tones[];
#endif 

extern Type_Preamble_Content AudioResPreamble;

#ifdef DIGIT_TONE_SUPPORT
audio_resource_struct *resource_human_voice_tones = NULL;
#endif 
#ifdef SIMPLE_TTS
audio_resource_struct *resource_tts_sounds = NULL;
start_end_t *TTS_UCS2_MSB_index = NULL;
unsigned char *TTS_UCS2_LSB = NULL;
unsigned short *TTS_index_table = NULL;
#endif /* SIMPLE_TTS */ 
#ifdef CUST_KEYPAD_TONE_SUPPORT
audio_resource_struct *resource_keypad_tones = NULL;
#endif 

/* Str variables */
extern void *langpack2ndJumpTbl[];
extern Type_Preamble_Content LangPackResPreamble;

//071706 menu resource
CUSTOM_MENU *nCustMenus = NULL;

sLanguageDetails *gLanguageArray = NULL;
U16 gMaxDeployedLangs = 0;

StringResList *gStringList = NULL;

#if defined(__MMI_T9__)
#if defined(__MMI_T9_V7__)
const sIMEModuleDetails gIMEModule = T9V7;
#else 
const sIMEModuleDetails gIMEModule = T9V6;
#endif 
#elif defined(__MMI_ZI__)
const sIMEModuleDetails gIMEModule = ZiV6;
#else 
const sIMEModuleDetails gIMEModule = IME_OTHERS;
#endif 

const sIMEModeDetails *gIMEModeArray = NULL;
const sIMEModeDetails *gIMEQSearchModeArray = NULL;
const sIMELDBDetails *gIMELDBArray = NULL;

#if defined(__MMI_T9__)
#if defined(__MMI_T9_V7__)
#if defined(__MMI_T9_TR_CHINESE__)
T9ChineseData T9FARDATA gT9TRChineseLDB;
#endif /* defined(__MMI_T9_TR_CHINESE__) */
#if defined(__MMI_T9_SM_CHINESE__)
T9ChineseData T9FARDATA gT9SMChineseLDB;
#endif /* defined(__MMI_T9_SM_CHINESE__) */
#else /* defined(__MMI_T9_V7__) */
#if defined(__MMI_T9_TR_CHINESE__) 
T9ChineseData FARDATA gT9TRChineseLDB;
#endif /* defined(__MMI_T9_TR_CHINESE__) */
#if defined(__MMI_T9_SM_CHINESE__)
T9ChineseData FARDATA gT9SMChineseLDB;
#endif /* defined(__MMI_T9_SM_CHINESE__) */
#endif /* defined(__MMI_T9_V7__) */ 
#endif /* defined(__MMI_T9__) */ 

/* J2ME variables */
#ifdef __J2ME__
extern void *J2ME2ndJumpTbl[];
extern Type_Preamble_Content J2MEResPreamble;
#endif /* __J2ME__ */ 

custpack_nvram_header *custpack_nvram_header_ptr;

extern void *custpack2ndJumpTbl[];
extern Type_Preamble_Content CustPackResPreamble;

/* CustPack image variables */
CUSTOM_IMAGE *nCustImageNamesEXT = NULL;
U16 CurrMaxImageNumEXT = 0;
CUSTPACK_IMAGE_HEADER *pimage_header = NULL;

/* 101205 audio resource Calvin Start */
/* CustPack image variables */
CUSTOM_AUDIO *nCustAudioNamesEXT = NULL;
U16 CurrMaxAudioNumEXT = 0;
CUSTPACK_AUDIO_HEADER *paudio_header = NULL;


/*****************************************************************************
 * FUNCTION
 *  StandaloneResValidation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void StandaloneResValidation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JUMP_TABLE_ENTRY_ENUM res_type;
    kal_uint32 res_type_code, res_MAGIC;
    kal_char *project_ID;
    kal_int8 errorType = -1;
    kal_int8 errorResType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (res_type = JUMP_TABLE_ENTRY_START; res_type <= JUMP_TABLE_ENTRY_END; res_type++)
    {
        project_ID = (kal_char*) GET_Res_Addr(res_type, 0);
        res_type_code = *(kal_uint32*) GET_Res_Addr(res_type, RESOURCE_TYPE_OFFSET);
        res_MAGIC = *(kal_uint32*) GET_Res_Addr(res_type, MAGIC_NUM_OFFSET);

        /* Check consistency between JUMP TABLE and the RESOURCE BIN */
        if (strncmp(project_ID, (const char*)GET_Res_ProjectID(res_type), strlen(VERNO_STR)))
        {
            errorType = 0;
            errorResType = res_type;
            goto Validation_Exit;
        }

        if (res_MAGIC != GET_Res_Magic(res_type))
        {
            goto Validation_Exit;
        }

        /* ID verification: PROJECT_ID */
        if (strncmp(project_ID, VERNO_STR, strlen(VERNO_STR)))
        {
            errorType = 0;
            errorResType = res_type;
            goto Validation_Exit;
        }

        /* ID verification: RESOURCE TYPE */
        if (((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_AUDIO) &&
            ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_IMAGE) &&
            ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_LANG_PACK)
    #ifdef __J2ME__
            && ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_J2ME)
    #endif 
            && ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_CUSTPACK))
            goto Validation_Exit;

        /* MAGIC# verification */
        if (res_MAGIC != MAGIC_NUMBER)
        {
            goto Validation_Exit;
        }

    }

    return;

  Validation_Exit:
    {
        kal_uint8 dspl_text[PROJECTID_LEN];

        DRV_POWERON();

        if (strlen(VERNO_STR) < PROJECTID_LEN)
        {
            kal_mem_set(dspl_text, '\0', PROJECTID_LEN);
            strncpy((char*)dspl_text, (const char*)project_ID, sizeof(VERNO_STR));
            dspl_text[sizeof(VERNO_STR)] = '\0';

            MMIResourceMismatchWarning(
                errorType,
                errorResType,
                (kal_uint8 const*)VERNO_STR,
                (kal_uint8 const*)dspl_text);
        }
        else    /* VERNO string too long (> 32 characters) */
        {
            ASSERT(KAL_FALSE);
        }

        while (1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitializeResourceVariables
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitializeResourceVariables(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void **langpack_JTbl = (void **)GET_ResLangPack_Addr(ENTRY_PREAMBLE);
    void **custpack_header = (void **)GET_ResCUSTPACK_Addr(ENTRY_PREAMBLE);     /* __CUSTPACK_MULTIBIN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* IMAGE Initialization */
    {
        nCustImageNames = (CUSTOM_IMAGE*) (image2ndJumpTbl[0]);
        CurrMaxImageNum = *((unsigned short*)(image2ndJumpTbl[1]));
    #ifdef __MMI_THEMES_V2_SUPPORT__
        MMI_themes = (theme_details_struct*) (image2ndJumpTbl[2]);
    #else 
        MMI_themes = (MMI_theme **) (image2ndJumpTbl[2]);
    #endif 
        n_MMI_themes = *((S32*) (image2ndJumpTbl[3]));
        mmi_theme_phone_model = (char*)(image2ndJumpTbl[4]);
    }

    /* AUDIO Initialization */
    {
        resource_tones = (device_tones_struct **) mtk_resource_tones;

#ifndef MED_MODEM
    #ifdef MIDI_IN_CUSTPACK_BIN
        resource_midis =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->mtk_resource_midis;
    #else /* MIDI_IN_CUSTPACK_BIN */ 
        resource_midis = (audio_resource_struct*) mtk_resource_midis;
    #endif /* MIDI_IN_CUSTPACK_BIN */ 

    #ifdef SND_IN_CUSTPACK_BIN
        resource_sounds =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_sounds;
    #else /* SND_IN_CUSTPACK_BIN */ 
        resource_sounds = (audio_resource_struct*) mtk_resource_sounds;
    #endif /* SND_IN_CUSTPACK_BIN */ 

    #ifdef EMS_SND_IN_CUSTPACK_BIN
        resource_ems_sounds =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_ems_sounds;
    #else /* EMS_SND_IN_CUSTPACK_BIN */ 
        resource_ems_sounds = (audio_resource_struct*) mtk_resource_ems_sounds;
    #endif /* EMS_SND_IN_CUSTPACK_BIN */ 

    #ifdef IMY_IN_CUSTPACK_BIN
        resource_imelodys =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_imelodys;
    #else /* IMY_IN_CUSTPACK_BIN */ 
        resource_imelodys = (audio_resource_struct*) mtk_resource_imelodys;
    #endif /* IMY_IN_CUSTPACK_BIN */ 

    #ifdef EMS_IMY_IN_CUSTPACK_BIN
        resource_ems_imelodys =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_ems_imelodys;
    #else /* EMS_IMY_IN_CUSTPACK_BIN */ 
        resource_ems_imelodys = (audio_resource_struct*) mtk_resource_ems_imelodys;
    #endif /* EMS_IMY_IN_CUSTPACK_BIN */ 

    #ifdef MSG_SND_IN_CUSTPACK_BIN
        resource_message_sounds =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_message_sounds;
    #else /* MSG_SND_IN_CUSTPACK_BIN */ 
        resource_message_sounds = (audio_resource_struct*) mtk_resource_message_sounds;
    #endif /* MSG_SND_IN_CUSTPACK_BIN */ 

    #ifdef MMS_SND_IN_CUSTPACK_BIN
        resource_mms_sounds =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_mms_sounds;
    #else /* MMS_SND_IN_CUSTPACK_BIN */ 
        resource_mms_sounds = (audio_resource_struct*) mtk_resource_mms_sounds;
    #endif /* MMS_SND_IN_CUSTPACK_BIN */ 

    #ifdef DIGIT_TONE_SUPPORT
    #ifdef HUMAN_VOICE_IN_CUSTPACK_BIN
        resource_human_voice_tones =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_human_voice_tones;
    #else /* HUMAN_VOICE_IN_CUSTPACK_BIN */ 
        resource_human_voice_tones = (audio_resource_struct*) mtk_resource_human_voice_tones;
    #endif /* HUMAN_VOICE_IN_CUSTPACK_BIN */ 
    #endif /* DIGIT_TONE_SUPPORT */ 

    #ifdef SIMPLE_TTS
        resource_tts_sounds = (audio_resource_struct*) mtk_resource_tts_sounds;
        TTS_UCS2_MSB_index = (start_end_t*) mtk_TTS_UCS2_MSB_index;
        TTS_UCS2_LSB = (unsigned char*)mtk_TTS_UCS2_LSB;
        TTS_index_table = (unsigned short*)mtk_TTS_index_table;
    #endif /* SIMPLE_TTS */ 

    #ifdef CUST_KEYPAD_TONE_SUPPORT
    #ifdef CUST_KEYPAD_TONE_IN_CUSTPACK_BIN
        resource_keypad_tones =
            (audio_resource_struct*) ((custpack_audio_header*) (custpack_header[CUSTPACK_AUDIO]))->
            mtk_resource_keypad_tones;
    #else /* CUST_KEYPAD_TONE_IN_CUSTPACK_BIN */ 
        resource_keypad_tones = (audio_resource_struct*) mtk_resource_keypad_tones;
    #endif /* CUST_KEYPAD_TONE_IN_CUSTPACK_BIN */ 
    #endif /* CUST_KEYPAD_TONE_SUPPORT */ 
#endif /*not MED_MODEM*/    
    }

    /* 101205 audio resource Calvin Start */
    /* AUTOGEN AUDIO Initialization */
    {
        nCustAudioNames = (CUSTOM_AUDIO*) (autogenaudio2ndJumpTbl[0]);
        CurrMaxAudioNum = *((unsigned short*)(autogenaudio2ndJumpTbl[1]));
    }
    /* 101205 audio resource Calvin End */

#ifdef __J2ME__
    /* For backward compatiable old project without j2me feature */
    /* J2ME Initialization */
    {
        j2me_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_JAVA_GAME]);
        if (j2me_custom_file_info_ptr)
        {
            game_j2me_default_game_count = j2me_custom_file_info_ptr->default_mids_count;
            game_virtual_file_count = j2me_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }

	#ifdef __SUPPORT_INFUSIO__
        eureka_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_INFUSIO_EUREKA]);
        if (eureka_custom_file_info_ptr)
        {
            eureka_default_game_count = eureka_custom_file_info_ptr->default_mids_count;
            eureka_virtual_file_count = eureka_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }	
	#endif /* __SUPPORT_INFUSIO__ */
	
	#ifdef SUPPORT_SURFKITCHEN
        surfkitchen_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_SURFKITCHEN]);
        if (surfkitchen_custom_file_info_ptr)
        {
            surfkitchen_default_game_count = surfkitchen_custom_file_info_ptr->default_mids_count;
            surfkitchen_virtual_file_count = surfkitchen_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }	
	#endif /* SUPPORT_SURFKITCHEN */

	#ifdef SUPPORT_MUSICWAV
        musicwav_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_MUSICWAV]);
        if (musicwav_custom_file_info_ptr)
        {
            musicwav_default_game_count = musicwav_custom_file_info_ptr->default_mids_count;
            musicwav_virtual_file_count = musicwav_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }	
	#endif /* SUPPORT_MUSICWAV */
	
    }
#endif /* __J2ME__ */ 

    if (((kal_uint32) langpack_JTbl > 0x1) && ((kal_uint32) & LangPackResPreamble > 0x1))       /* dummy reference to make the variable exist */
    {
        gLanguageArray = (sLanguageDetails*) (langpack2ndJumpTbl[0]);
        gMaxDeployedLangs = *((unsigned short*)(langpack2ndJumpTbl[1]));

        gStringList = (StringResList*) (langpack2ndJumpTbl[2]);

        if (gIMEModule != *((sIMEModuleDetails*) (langpack2ndJumpTbl[6])))
        {
            ASSERT(0);
        }
        gIMEModeArray = (sIMEModeDetails*) (langpack2ndJumpTbl[3]);
        gIMEQSearchModeArray = (sIMEModeDetails*) (langpack2ndJumpTbl[4]);
        gIMELDBArray = (sIMELDBDetails*) (langpack2ndJumpTbl[5]);
    #if defined(__MMI_T9__)
    #if defined(__MMI_T9_TR_CHINESE__)
    #if defined(__MMI_T9_V7__)
        gT9TRChineseLDB = *((T9ChineseData const T9FARDATA*)(langpack2ndJumpTbl[7]));
    #else 
        gT9TRChineseLDB = *((T9ChineseData const FARDATA*)(langpack2ndJumpTbl[7]));
    #endif 
    #endif /* defined(__MMI_T9_TR_CHINESE__) */ 
    #if defined(__MMI_T9_SM_CHINESE__)
    #if defined(__MMI_T9_V7__)
        gT9SMChineseLDB = *((T9ChineseData const T9FARDATA*)(langpack2ndJumpTbl[8]));
    #else 
        gT9SMChineseLDB = *((T9ChineseData const FARDATA*)(langpack2ndJumpTbl[8]));
    #endif 
    #endif /* defined(__MMI_T9_SM_CHINESE__) */ 
    #endif /* defined(__MMI_T9__) */ 
        nCustMenus = (CUSTOM_MENU *)(langpack2ndJumpTbl[9]);//071706 menu resource
    }

    /* CustPack Initialization */
    if (((kal_uint32) custpack2ndJumpTbl > 0x1) && ((kal_uint32) & CustPackResPreamble > 0x1))  /* dummy reference to make the variable exist */
    {
        /* CustPack NVRAM Initialized in NVRAM init procedure */
        custpack_nvram_header_ptr = (custpack_nvram_header*) custpack_header[CUSTPACK_NVRAM];

        /* CustPack Image Initialization */
        pimage_header = (CUSTPACK_IMAGE_HEADER*) (custpack_header[CUSTPACK_IMAGE]);
        nCustImageNamesEXT = (CUSTOM_IMAGE*) pimage_header->CustImageNamesEXT;
        CurrMaxImageNumEXT = pimage_header->MaxImageNumEXT;

        /* CustPack Autogen Audio Initialization */
        paudio_header = (CUSTPACK_AUDIO_HEADER*) (custpack_header[CUSTPACK_AUTOGEN_AUDIO]);
        nCustAudioNamesEXT = (CUSTOM_AUDIO*) paudio_header->CustAudioNamesEXT;
        CurrMaxAudioNumEXT = paudio_header->MaxAudioNumEXT;

    #if defined(OBIGO_Q03C) && defined(WAP_SUPPORT)
        {
            wap_custpack_header *custpack_wap_header_ptr = (wap_custpack_header*) custpack_header[CUSTPACK_WAP];

            custpack_wap_default.wap_profile_default = custpack_wap_header_ptr->wap_profile_default;
            custpack_wap_default.mms_profile_default = custpack_wap_header_ptr->mms_profile_default;
            custpack_wap_default.wap_bkm_default = custpack_wap_header_ptr->wap_bkm_default;
            custpack_wap_default.wap_root_ca_default = custpack_wap_header_ptr->wap_root_ca_default;
            custpack_wap_default.wap_config_default = custpack_wap_header_ptr->wap_config_default;
            custpack_wap_default.mms_config_default = custpack_wap_header_ptr->mms_config_default;
        }
    #endif /* defined(OBIGO_Q03C) && defined(WAP_SUPPORT) */ 
    }

    StandaloneResValidation();
}


