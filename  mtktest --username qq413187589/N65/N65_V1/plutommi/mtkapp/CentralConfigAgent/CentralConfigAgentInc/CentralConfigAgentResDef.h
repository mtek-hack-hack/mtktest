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
 *  CentralConfigAgentResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_CCARESDEF_H
#define MMI_CCARESDEF_H


/* Screen IDs */
typedef enum {
    SCR_ID_CCA_PRE_INFO = CCA_BASE + 1,
    SCR_ID_CCA_PROGRESS,
    SCR_ID_CCA_POST_INFO,
    SCR_ID_CCA_NEW_SETTING_CONF,
    SCR_ID_CCA_AUTH
} cca_screen_enum;


/* String IDs */
typedef enum {
    STR_ID_CCA = CCA_BASE + 1,
    STR_ID_CCA_PROGRESS_TITLE,
    STR_ID_CCA_PROGRESS_CONTENT,
    STR_ID_CCA_PREINFO_TITLE,
    STR_ID_CCA_PREINFO_CONTENT,
    STR_ID_CCA_POSTINFO_TITLE,
    STR_ID_CCA_NEW_SETTING_CONF_TITLE,
    STR_ID_CCA_NEW_SETTING_CONF_CONTENT,
    STR_ID_CCA_AUTH_TITLE,
    STR_ID_CCA_AUTH_CONTENT,

    STR_ID_CCA_CONFIGURED,
    STR_ID_CCA_INVALID_SETTING,
    STR_ID_CCA_SETTING_SKIPPED,

    STR_ID_CCA_UNSUPPORTED_SETTING,
    STR_ID_CCA_CORRUPTED_SETTING,
    STR_ID_CCA_MISSING_DATA,

    STR_ID_CCA_INSTALL_SETTING,
    STR_ID_CCA_REPLACE_SETTING,
    STR_ID_CCA_SKIP_PROFILE,
    STR_ID_CCA_PROFILE_IN_USE,
    STR_ID_CCA_SKIP,
    STR_ID_CCA_ABORT_ASK,
    
    STR_ID_CCA_NEW_SETTING,
    STR_ID_CCA_PIN_NO_MORE_RETRY,
    STR_ID_CCA_PIN_RETRY,
    STR_ID_CCA_PIN_EMPTY,

    STR_ID_CCA_MEMFULL,
    STR_ID_CCA_PROFILE,

    STR_ID_CCA_DTACCT,
    STR_ID_CCA_BROWSER,
    STR_ID_CCA_MMS,
    STR_ID_CCA_WLAN,
    STR_ID_CCA_SIP,
    STR_ID_CCA_FOTA,
    STR_ID_CCA_EMAIL,
    STR_ID_CCA_IMPS,
    STR_ID_CCA_SYNCMLDS,
    STR_ID_CCA_SYNCMLDM,

    STR_ID_CCA_NOAPP,
    STR_ID_CCA_IS_SETTING_ABORTED,
   
/* #ifdef __MMI_DUAL_SIM__ */
    STR_ID_CCA_NEW_SIM1_SETTING,
    STR_ID_CCA_NEW_SIM2_SETTING,
    STR_ID_CCA_INSTALL_NEW_SIM1_SETTING,
    STR_ID_CCA_INSTALL_NEW_SIM2_SETTING,
/* #endif  __MMI_DUAL_SIM__ */

    STR_ID_CCA_MAX_ITEM
    
} cca_string_enum;


/* Image IDs */
typedef enum {
    IMG_ID_CCA = CCA_BASE + 1,
    IMG_ID_CCA_MAIN_ICON,  
    IMG_ID_CCA_MAX_ITEM
} cca_image_enum;


#endif  /* MMI_CCARESDEF_H */
