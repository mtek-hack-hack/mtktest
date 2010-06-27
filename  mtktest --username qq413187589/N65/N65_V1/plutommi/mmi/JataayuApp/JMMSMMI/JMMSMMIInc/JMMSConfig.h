/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  JMMSConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains the configuration settings for mms
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSCONFIG_H
#define __MMI_JMMSCONFIG_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_wap_config.h"

/* 
 * Define
 */

#define MAX_POSSIBLE_ADDRESSES 20       /* According to OMA conformance */
#define MAX_POSSIBLE_ADDRESS_LENGHT_RECEIVED 312        /* According to OMA conformance */
#define MAX_POSSIBLE_NUMBER_LENGHT_SENT   40
#define MAX_POSSIBLE_EMAIL_LENGHT_SENT 60
#define MAX_POSSIBLE_SLIDES            (wap_custom_get_max_mms_slides())

#define MAX_POSSIBLE_MESSAGES           wap_custom_get_max_mms_num()-1
#define MAX_POSSIBLE_MESSAGES_THRESHOLD     wap_custom_get_max_mms_warning_num()
#define MAX_MMS_MSG_SIZE               wap_custom_get_max_mms_msg_size()
#define E_JMMS_DEAFULT_COMM_ERROR_CODE 1
#define E_MEMORY_FULL_ERROR 2
#define E_COMMUNICATION_ABORTED 3
#define E_MESSAGE_EXPIRED 4

// #define MAX_POSSIBLE_SUBJECT_LENGTH  40      ///according to OMA conformance

// #define MAX_MSG_SIZE_IN_KB 300
#define MAX_SUBJECT_LENGTH 40

#define MAX_RECIPIENTS_CAPTION_LENGTH  40
#define MAX_FILES_CAPTION_LENGTH    30
/* PMT VIKAS START 20050325 */
#define MAX_SLIDES_CAPTION_LENGTH      50       /* vikas added 10 more for size */
/* PMT VIKAS END 20050325 */

#define MAX_VALIDITY_PERIOD_VALUE      31449600 /* A year as max */
#define MAX_VERSION_LENGTH    3

#define MAX_PROGRESS_SCREEN_HINT_LEN  100

#define MAX_FILE_LENGTH          16
#define MMS_MMSC_URLS_FILE_NAME     "c:\\mmscurls.txt"

/* NVRAM */
#define NVRAM_JMMS_COMPOSE_SETTINGS_SIZE  272
#define NVRAM_JMMS_SENDING_SETTINGS_SIZE  16

#define MAX_READ_UNREAD_STATUS_BYTES   ( (((((wap_custom_get_max_mms_num()/8)+1) + 3)/4)*4) )

#define DEFAULT_SLIDE_DURATION                5000      /* /ms */
#define DEFAULT_HOME_RETRIEVAL_MODE              E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE    /* /immedaite */
#define DEFAULT_ROAMING_RETRIEVAL_MODE         E_ROAMING_RETRIEVAL_AS_HOME
#define DEFAULT_ADVERTISEMENT_FILTER_VALUE       E_ALLOW
#define DEFAULT_ANONYMOUS_FILTER_VALUE        E_ALLOW
#define  DEFAULT_DELIVERY_REPORT_DURING_SENDING  E_OFF
#define DEFAULT_READ_REPORT_DURING_SENDING       E_OFF
#define DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL E_ON
#define DEFAULT_READ_REPORT_DURING_RETRIEVAL     E_READ_REPORT_SEND_ON_REQUEST

#define JMMS_WRONG_CONTENT_TYPE_ERROR 80
#define MMS_SUPPORTED_CONTENT_CLASS wap_get_mms_content_class()
#define MMS_SUPPORTED_CONTENT_CLASS_MAX_SIZE_RESTRICTED_MODE wap_get_max_mms_size_in_restricted_mode()

#ifdef USE_HW_GIF_DECODER_V2
#define MAX_ALLOWED_INDIVIDUAL_MEDIA_SIZE 1024
#else 
#define MAX_ALLOWED_INDIVIDUAL_MEDIA_SIZE 300
#endif 
// #define MAX_ALLOWED_INDIVIDUAL_MEDIA_SIZE wap_custom_get_max_size_limit_for_individual_inline_media()
#define __MMI_JMMS_NO_OMA_CONF_273__
#ifdef __MMI_JMMS_NO_OMA_CONF_273__
// #define __MMI_JMMS_CONF_RETRIVE_SIZE__
#endif 
/* HIMANSHU 05122006 START */
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT) && defined(JPG_ENCODE) && !( defined(MT6223) || defined(MT6223P)))
#define __MMI_MMS_MEGA_PIXEL_SUPPORT__
#endif 
/* HIMANSHU 05122006 END */

#define __MMI_JMMS_JAVA_MMS_SUPPORT__
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
#define __MMI_JMMS_REDUCE_CHINESE_SUBJECT__
#endif 
#ifdef __MMI_UNIFIED_COMPOSER__
#define __MMI_JMMS_EXPIRY_HANDLING__
#define __MMI_JMMS_RESPONSE_TIMEOUT__
#define __MMI_JMMS_SEND_RETRIES__
#define __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
/* #define __MMI_JMMS_TEST_RESPONSE_TIMEOUT__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#endif /* __MMI_JMMSCONFIG_H */ 

