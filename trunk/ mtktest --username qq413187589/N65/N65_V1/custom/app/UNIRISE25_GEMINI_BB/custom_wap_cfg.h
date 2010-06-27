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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_wap_cfg.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains WAP/MMS custom configuration constant. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CUSTOM_WAP_CFG_H__
#define __CUSTOM_WAP_CFG_H__
 
#ifdef JATAAYU_SUPPORT
//#define WAP_CUSTOM_CFG_MAX_CACHE_SIZE  (20*1024)
//#define WAP_CUSTOM_CFG_MAX_COOKIES_SIZE  20
//#define WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG       15
//#define WAP_CUSTOM_CFG_DEFAULT_UA_HEADER  "MAUI WAP Browser"
//#define WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL   ""
//#define WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT   300
//#define WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGES_ON         1
//#define WAP_CUSTOM_CFG_DEFAULT_SHOW_HISTORY_AS_URL    0
//#define WAP_CUSTOM_CFG_DEFAULT_SHOW_SERVICE_INBOX_MSG	1
//#define WAP_CUSTOM_CFG_DEFAULT_IMAGE_SELECTION_ON		0
//#define CUSTOM_WAP_BKM_TITLE_LEN 41
//#define WAP_CUSTOM_CFG_N_NBR_BOOKMARKS 20
//#define CUSTOM_WAP_BKM_URL_LEN 129
//#define CUSTOM_WAP_HISTORY_TITLE_LEN      41
//#define CUSTOM_WAP_CFG_N_NBR_HISTORY      10
//#define CUSTOM_WAP_HISTORY_TITLE_LEN      41
//#define CUSTOM_WAP_HISTORY_URL_LEN        129
//#define WAP_CUSTOM_CFG_MMS_VERSION 1    /* 1: 1.0, 2: 1.1, 3: 1.2, 4:latest version */
//#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER "MAUI MMS User Agent"
//#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_PROF_URL   ""
//#define WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG 101
//#define WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE   (300*1024)
//#define WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG 95
//#define WAP_CUSTOM_CFG_MAX_MMS_SLIDES 20
//#define WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY   2
//#define WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY   0       /* Customer can reduce this value to zero, if they don't want resend MMS when error occurs. */
//#define WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY   2       /* This value isn't recommeded to reduce. */
//#define WAP_CUSTOM_CFG_MMS_GET_TIMEOUT   400    /* 40 seconds */
//#define WAP_CUSTOM_CFG_MMS_POST_TIMEOUT   1200  /* 120 seconds, this value isn't recommeded to reduce. */
//#define WAP_CUSTOM_CFG_MAX_MMS_SLIDES 20
//#define WAP_CUSTOM_CFG_MAX_MMS_ADDRESS 20
//#define WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT 3
#endif /* JATAAYU_SUPPORT */ 

#ifdef OBIGO_Q03C    /* Obigo only */
//#define WAP_CUSTOM_CFG_N_WAP_PROFILES  10
//#define WAP_CUSTOM_CFG_N_MMS_PROFILES  10
//#define WAP_CUSTOM_CFG_N_NBR_BOOKMARKS 20
//#define WAP_CUSTOM_CFG_N_ROOT_CA       3

//#define WAP_CUSTOM_CFG_MAX_CACHE_SIZE  (50*1024)
//#define WAP_CUSTOM_CFG_DEFAULT_UA_HEADER  "MAUI WAP Browser"
//#define WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL   ""
//#define WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT   300
//#define WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG       15
//#define WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER "MAUI MMS User Agent"
//#define WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG 101
#define WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE   (100*1024)
//#define WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG 95
//#define WAP_CUSTOM_CFG_MAX_MMS_CACHE_PUSH_NUM 10
//#define WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY   2
//#define WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY   0       /* Customer can reduce this value to zero, if they don't want resend MMS when error occurs. */
//#define WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY   2       /* This value isn't recommeded to reduce. */
//#define WAP_CUSTOM_CFG_MMS_GET_TIMEOUT   400    /* 40 seconds */
//#define WAP_CUSTOM_CFG_MMS_POST_TIMEOUT   1200  /* 120 seconds, this value isn't recommeded to reduce. */
//#define WAP_CUSTOM_CFG_MMS_SLIDE_DURATION 8000  /* ms (unused) */
//#define WAP_CUSTOM_CFG_MMS_IMMED_RETRIEVAL_MODE 1       /* 0: auto, 1: deferred, 2: restricted (unused) */
//#define WAP_CUSTOM_CFG_MMS_ROAM_RETRIEVAL_MODE 1        /* 0: auto, 1: deferred, 2: restricted (unused) */
//#define WAP_CUSTOM_CFG_MMS_ALLOW_ADVERTIMSEMENT 1       /* 0: no, 1: yes (unused) */
//#define WAP_CUSTOM_CFG_MMS_ALLOW_ANONYMOUS 1    /* 0: no, 1: yes (unused) */
//#define WAP_CUSTOM_CFG_MMS_REQ_DELIVERY_REPORT 1        /* 0: no, 1: yes (unused) */
//#define WAP_CUSTOM_CFG_MMS_REQ_READ_REPORT 1    /* 0: no, 1: yes (unused) */
//#define WAP_CUSTOM_CFG_MMS_SEND_DELIVERY_REPORT 1       /* 0: no, 1: yes (unused) */
//#define WAP_CUSTOM_CFG_MMS_SEND_READ_REPORT 1   /* 0: no, 1: yes (unused) */
//#define WAP_CUSTOM_CFG_MMS_VERSION 1    /* 0: default, 1: 1.0, 2: 1.1, 3: latest version (unused) */
//#define WAP_CUSTOM_CFG_MAX_MMS_SLIDES 20
//#define WAP_CUSTOM_CFG_MAX_MMS_ADDRESS 20
//#define WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT 3

#endif /* OBIGO_Q03C */ 

#ifdef OBIGO_Q05A

//#define WAP_CUSTOM_CFG_BROWSER_MEM_SIZE   2000 * 1024

#endif /* OBIGO_Q05A */
#endif /* __CUSTOM_WAP_CFG_H__ */
