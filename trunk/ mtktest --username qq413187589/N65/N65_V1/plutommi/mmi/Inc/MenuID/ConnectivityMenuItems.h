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
 *  ConnectivityMenuItems.h
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

MENU_CONN_IRDA_MAIN,
    /* Priyesh - Memory Card Support */
    MENU_CONN_IRDA_ACTIVATION, MENU_CONN_IRDA_STORAGE,
    /* Priyesh - Memory Card Support */
    MENU_CONN_IRDA_OPEN, MENU_CONN_IRDA_CLOSE, MENU_CONN_IRDA_PERIOD,
    /* Priyesh - Memory Card Support */
    MENU_CONN_IRDA_STORAGE_PHONE, MENU_CONN_IRDA_STORAGE_CARD,
    //Priyesh - Memory Card Support
    /* general BT menu */
    MENU_CONN_BT_MAIN,
    MENU_CONN_BT_POWER,
    MENU_CONN_BT_SCH_AUDIO_DEV,
    MENU_CONN_BT_REMOTE_CONTROL,
    MENU_CONN_BT_MYDEV,
    MENU_CONN_BT_ACT_DEV,
    MENU_CONN_BT_SET,
    MENU_CONN_BT_SET_VIS,
    MENU_CONN_BT_SET_NAME,
    MENU_CONN_BT_SET_AUTH,
    MENU_CONN_BT_SET_AUDIO_PATH,
    MENU_CONN_BT_SET_AUDIO_PATH_PHONE, MENU_CONN_BT_SET_AUDIO_PATH_HF, MENU_CONN_BT_SET_FTP, 
    MENU_CONN_BT_SET_SIMAP,
    MENU_CONN_BT_ABOUT,
    /* BT FTP client menu */
    MENU_CONN_FTP_SETTING,
    MENU_CONN_FTP_SHARED_FOLDER,
    MENU_CONN_FTP_SHARED_FOLDER_OPTION_OPEN,
    MENU_CONN_FTP_SHARED_FOLDER_OPTION_SELECT,
    MENU_CONN_FTP_ACCESS_RIGHT,
    MENU_CONN_FTP_ACCESS_RIGHT_OPTION_FULLY_CONTROL,
    MENU_CONN_FTP_ACCESS_RIGHT_OPTION_READ_ONLY,
    MENU_CONN_FTP_FILE_BROWSER,
    MENU_CONN_FTP_FILE_OPTION,
    MENU_CONN_FTP_FOLDER_OPTION,
    MENU_CONN_FTP_EMPTY_FOLDER_OPTION,
    MENU_CONN_FTP_GEN_OPTION_REFRESH,
    MENU_CONN_FTP_GEN_OPTION_DETAIL,
    MENU_CONN_FTP_GEN_OPTION_BACK_TO_ROOT_DIR,
    MENU_CONN_FTP_GEN_OPTION_DISCONNECT, 
    MENU_CONN_FTP_FOLDER_OPTION_OPEN, 
    MENU_CONN_FTP_FILE_OPTION_GET,
    MENU_CONN_FTP_FILE_OPTION_ADD_TO_LIST,
    MENU_CONN_FTP_GEN_OPTION_SHOW_LIST,
    MENU_CONN_FTP_GEN_OPTION_GET_LIST_FILE, 
    MENU_CONN_FTP_FILE_OPTION_GET_ALL, 
    MENU_CONN_FTP_LIST_OPTION,
    MENU_CONN_FTP_LIST_OPTION_UP, 
    MENU_CONN_FTP_LIST_OPTION_DOWN, 
    MENU_CONN_FTP_LIST_OPTION_DELETE,
    MENU_CONN_FTP_LIST_OPTION_DELETE_ALL,

    /* BT BIP menu */
    MENU_CONN_BIP_SETTING,
    MENU_CONN_BIP_SHARED_FOLDER,
    MENU_CONN_BIP_SHARED_FOLDER_OPTION_OPEN,
    MENU_CONN_BIP_SHARED_FOLDER_OPTION_SELECT,
    MENU_CONN_BIP_IMGLIST_BROWSER,
    MENU_CONN_BIP_IMGLIST_OPTION,
    MENU_CONN_BIP_OPTION_IMG_DETAIL,
    MENU_CONN_BIP_OPTION_GET,
    MENU_CONN_BIP_OPTION_GET_ALL,
    MENU_CONN_BIP_OPTION_REFRESH,
    MENU_CONN_BIP_OPTION_GET_THM,
    MENU_CONN_BIP_OPTION_DISCONNECT, 


    MENU_ID_CONNECTIVITY,
    
    

