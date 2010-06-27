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
 *   wapadp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Common definition of wap adaptation for internal use
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
#ifndef _WAPADP_H
#define _WAPADP_H

#include "custom_wap_config.h"
#include "wps_defs.h"

/* Common */
/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum
{
    WAP_STORAGE_SYSTEM = 0,
    WAP_STORAGE_MMS,    /* Hold MMS data */
    WAP_STORAGE_PUBLIC,  /* Default place for public data (Users can choose another partition) */
    WAP_STORAGE_EXTERNAL,
    WAP_STORAGE_VIRTUAL
} wap_storage_enum;

typedef enum
{
    WAP_SERVICE_MMS = 0,
    WAP_SERVICE_BROWSER
} wap_service_enum;


/******************************************************************************
  *  Common functions. All WAP/MMS soultion will support the following functions.
  ******************************************************************************/

#ifdef GDI_USING_PNG

#define WAP_CFG_ACCEPT_HEADER_COMMON_1 \
  "image/vnd.wap.wbmp, " \
  "image/gif, " \
  "image/bmp, " \
  "image/png, " \
  "audio/amr," \
  "audio/imelody, " \
  "audio/midi, " \
  "audio/wav, " \
  "application/vnd.wap.wtls-ca-certificate, "\
  "application/x-x509-ca-cert, "\
  "application/vnd.wap.hashed-certificate, "\
  "application/vnd.wap.signed-certificate, "\
  "*/*"

#else

#define WAP_CFG_ACCEPT_HEADER_COMMON_1 \
  "image/vnd.wap.wbmp, " \
  "image/gif, " \
  "image/bmp, " \
  "audio/amr," \
  "audio/imelody, " \
  "audio/midi, " \
  "audio/wav, " \
  "application/vnd.wap.wtls-ca-certificate, "\
  "application/x-x509-ca-cert, "\
  "application/vnd.wap.hashed-certificate, "\
  "application/vnd.wap.signed-certificate, "\
  "*/*"

#endif


#ifdef  __J2ME__

#define WAP_CFG_ACCEPT_HEADER_COMMON \
  "text/vnd.sun.j2me.app-descriptor, "\
  "application/java-archive, "\
  WAP_CFG_ACCEPT_HEADER_COMMON_1

#else

#define WAP_CFG_ACCEPT_HEADER_COMMON WAP_CFG_ACCEPT_HEADER_COMMON_1

#endif


#define WAP_CFG_ACCEPT_HEADER_WAP_1_2_1 \
  "application/vnd.wap.wmlc, " \
  "application/vnd.wap.wmlscriptc, " \
  "text/vnd.wap.wml, " \
  WAP_CFG_ACCEPT_HEADER_COMMON
  
#define WAP_CFG_ACCEPT_HEADER_WAP_2_0 \
  "application/xhtml+xml; profile=http://www.wapforum.org/xhtml, " \
  "application/vnd.wap.xhtml+xml, " \
  WAP_CFG_ACCEPT_HEADER_WAP_1_2_1 \
  ", text/html"
  
#define WAP_CFG_ACCEPT_HEADER_WML \
  "text/vnd.wap.wml, " \
  WAP_CFG_ACCEPT_HEADER_COMMON
  
#define WAP_CFG_ACCEPT_HEADER_XHTML \
  "application/xhtml+xml; profile=http://www.wapforum.org/xhtml, " \
  "application/vnd.wap.xhtml+xml, " \
  WAP_CFG_ACCEPT_HEADER_COMMON
  
#define WAP_CFG_ACCEPT_HEADER_HTML \
  "text/html, " \
  WAP_CFG_ACCEPT_HEADER_COMMON


#define WAP_USER_AGENT_TABLE { \
    {"Default", EM_WAP_USERAGENT_BRAND_MTK, WAP_CUSTOM_CFG_DEFAULT_UA_HEADER, WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL}, \
    {"Nokia N72", EM_WAP_USERAGENT_BRAND_NOKIA, "NokiaN72/2.0617.1.0.3 Series60/2.8 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/NN72r100.xml"}, \
    {"Nokia E70", EM_WAP_USERAGENT_BRAND_NOKIA, "NokiaE70-1/3.0 (1.0610.05.06) SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/NE70-1r100.xml"}, \
    {"Nokia N93", EM_WAP_USERAGENT_BRAND_NOKIA, "NokiaN93-1/20.0.041 SymbianOS/9.1 Series60/3.0 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/NN93r100.xml"}, \
    {"Nokia 6680", EM_WAP_USERAGENT_BRAND_NOKIA, "Nokia6680/1.0 (4.04.07) SymbianOS/8.0 Series60/2.6 Profile/MIDP-2.0Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/N6680r100.xml"}, \
    {"Nokia 6280", EM_WAP_USERAGENT_BRAND_NOKIA, "Nokia6280/2.0 (03.60) Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/N6280r100.xml"}, \
    {"Nokia 3230", EM_WAP_USERAGENT_BRAND_NOKIA, "Nokia3230/2.0 (5.0614.0) SymbianOS/7.0s Series60/2.1 Profile/MIDP-2.0Configuration/CLDC-1.0", "http://nds.nokia.com/uaprof/N3230r100.xml"}, \
    {"Nokia 6230", EM_WAP_USERAGENT_BRAND_NOKIA, "Nokia6230/2.0 (03.15) Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://nds.nokia.com/uaprof/N6230r100.xml"}, \
    {"SonyEricsson W900i", EM_WAP_USERAGENT_BRAND_SE, "SonyEricssonW900i/R1L Browser/NetFront/3.3 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/W900iR101-3G.xml"}, \
    {"SonyEricsson W800i", EM_WAP_USERAGENT_BRAND_SE, "SonyEricssonW800i/R1L Browser/SEMC-Browser/4.2 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/W800iR101.xml"}, \
    {"SonyEricsson K700i", EM_WAP_USERAGENT_BRAND_SE, "SonyEricssonK700i/R2AG SEMC-Browser/4.0.3 Profile/MIDP-1.0 MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/K700iR201.xml"}, \
    {"SonyEricsson Z800", EM_WAP_USERAGENT_BRAND_SE, "SonyEricssonZ800/R1X Browser/SEMC-Browser/4.1 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://wap.sonyericsson.com/UAprof/Z800R101.xml"}, \
    {"Samsung D608", EM_WAP_USERAGENT_BRAND_SAMSUNG, "SAMSUNG-SGH-D608/1.0/WAP2.0 Profile/MIDP-2.0 Configuration/CL", "http://wap.samsungmobile.com/uaprof/SGH-D608.xml"}, \
    {"Motorola E1070", EM_WAP_USERAGENT_BRAND_MOTO, "MOT-E1070/85.83.50R MIB/BER2.2 Profile/MIDP-2.0 Configuration/CLDC-1.1", "http://motorola.handango.com/phoneconfig/E1070/Profile/E1070.rdf"} }

/**************************
  *  WAP Engineering Option
  **************************/
typedef enum
{
    EM_WAP_USERAGENT_OPT,
    EM_WAP_ACCEPTHEADER_OPT,
    EM_MMS_VERSION_OPT,
    EM_WAP_OFFLINE_PAGE_OPT
} em_wap_option_enum;

/**************************
  *  WAP User Agent
  **************************/
typedef enum
{
    EM_WAP_USERAGENT_MAUI_E800,
    EM_WAP_USERAGENT_NOKIA_N72,
    EM_WAP_USERAGENT_NOKIA_E70,
    EM_WAP_USERAGENT_NOKIA_N93,
    EM_WAP_USERAGENT_NOKIA_6680,
    EM_WAP_USERAGENT_NOKIA_6280,
    EM_WAP_USERAGENT_NOKIA_3230,
    EM_WAP_USERAGENT_NOKIA_6230,
    EM_WAP_USERAGENT_SE_W900I,
    EM_WAP_USERAGENT_SE_W800I,
    EM_WAP_USERAGENT_SE_K700I,
    EM_WAP_USERAGENT_SE_Z800,
    EM_WAP_USERAGENT_SAMSUNG_D608,
    EM_WAP_USERAGENT_MOTO_E1070,
    EM_WAP_USERAGENT_MAX
} em_wap_user_agent_enum;

/**************************
  *  WAP User Agent Brand
  **************************/
typedef enum{
	EM_WAP_USERAGENT_BRAND_MTK,
	EM_WAP_USERAGENT_BRAND_SE,
	EM_WAP_USERAGENT_BRAND_NOKIA,
	EM_WAP_USERAGENT_BRAND_MOTO,
	EM_WAP_USERAGENT_BRAND_SHARP,
	EM_WAP_USERAGENT_BRAND_SAMSUNG
} em_wap_user_agent_brand_enum;

/**************************
  *  WAP Accpet Header
  **************************/
typedef enum
{
    EM_WAP_ACCEPTHEADER_WAP121,
    EM_WAP_ACCEPTHEADER_WAP20,
    EM_WAP_ACCEPTHEADER_WML,
    EM_WAP_ACCEPTHEADER_XHTML,
    EM_WAP_ACCEPTHEADER_HTML,
    EM_WAP_ACCEPTHEADER_MAX
} em_wap_accept_header_enum;

/**************************
  *  MMS Version
  **************************/
typedef enum
{
    EM_MMS_VERSION_DEFAULT,
    EM_MMS_VERSION_10,
    EM_MMS_VERSION_11,
    EM_MMS_VERSION_12,
    EM_MMS_VERSION_MAX
} em_mms_version_enum;

/**************************
  *  MMS content class
  **************************/
typedef enum
{
    WAP_MMS_CONTENT_CLASS_TEXT = 0,
    WAP_MMS_CONTENT_CLASS_IMAGE_BASIC,
    WAP_MMS_CONTENT_CLASS_IMAGE_RICH,
    WAP_MMS_CONTENT_CLASS_VIDEO_BASIC,
    WAP_MMS_CONTENT_CLASS_VIDEO_RICH,
    WAP_MMS_CONTENT_CLASS_UNKNOWN    
} wap_mms_content_class_enum;

/**************************
  *  WAP profile access SAP enum and definition
  **************************/
#define WAP_PROF_MAX_NAME_SIZE 40
#define WAP_PROF_MAX_UID_SIZE 30
#define WAP_PROF_MAX_PWD_SIZE 30

#define MEA_MAX_ENCODE_ADDRESS_LENGTH   122 /*60*ENCODING_LENGTH + ENCODING_LENGTH*/
#define MEA_MAX_ENCODE_SUBJECT_LENGTH   82 /*MEA_MAX_SUBJECT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH*/
#define MEA_MAX_ENCODE_TEXT_LENGTH      1226 /*MEA_MAX_TEXT_LENGTH * ENCODING_LENGTH + ENCODING_LENGTH*/
typedef enum
{
    WAP_PROF_SUCCESS,
    WAP_PROF_NOT_READY,
    WAP_PROF_BUSY,
    WAP_PROF_INVALID_ID
} wap_prof_error_eumm;

typedef enum
{
    WAP_PROF_CONN_TYPE_HTTP,
    WAP_PROF_CONN_TYPE_WSP_CO,
    WAP_PROF_CONN_TYPE_WSP_CL
} wap_prof_conn_type_enum;

typedef enum
{
    WAP_BROWSER_GOTO_MAIN_MENU,
    WAP_BROWSER_GOTO_HOMEPAGE,
    WAP_BROWSER_GOTO_URL,
    WAP_BROWSER_ADD_BOOKMARK,
    WAP_BROWSER_GOTO_URL_BACKGROUND,
    WAP_BROWSER_VIEW_PUSH_MSG = 8
} wap_browser_startup_opt_enum;

extern kal_bool wap_suppress_popup_flag;
extern void wap_suppress_popup(kal_bool is_true);
extern kal_bool wap_is_new_msg_popup_handled(void);

#ifdef WAP_SUPPORT
extern kal_bool wap_enable_debug_assert;
extern kal_uint8 global_wap_user_agent;
extern kal_uint8 global_wap_accept_header;
extern kal_uint8 global_mms_version;
extern kal_bool global_offline_page;
extern void em_wap_change_setting(kal_uint8 opt, kal_uint8 val);
extern int wap_bearer_csd_is_disc(void);
extern int wap_url_is_valid(const char *url);
extern int wap_browser_is_open(void);
extern void wap_entry_no_ready_screen(wap_service_enum service_id);
extern char *wap_get_user_agent(void);
extern const char *wap_get_accept_header(void);
extern module_type wap_get_service_module(kal_uint32 msg_id);

/* WAP Browser Entry Function */
extern void goto_mobile_suite_screen(void);
extern int wap_start_browser(kal_uint8 option, const kal_uint8 *url);
extern void wap_on_enter_usb_mode(void);
extern int wap_is_ready(void);
extern int wap_is_init(void);
extern void wap_plmn_number_indication_callback(const unsigned char *plmn_number);

#ifdef __MMI_DUAL_SIM__
extern void wap_roaming_status_indication_callback(int simId, unsigned long isRoaming);
#else
extern void wap_roaming_status_indication_callback(unsigned long isRoaming);
#endif

#endif /* WAP_SUPPORT */ 

#ifdef MMS_SUPPORT
typedef enum
{
    MEA_NEW_ADDRESS,
    MEA_NEW_FILE,	/* image, audio, attachment */
    MEA_NEW_BUFFER,  /* text */
    MEA_NEW_GENERAL
} MeaNewTypeEnum;

typedef void (*func_ptr) (void *);
typedef struct
{
    MeaNewTypeEnum mode;
    char *addr;
    char *subject;
    char *file_path;  /* UCS2 MMI filename */
    char *text_buffer;
    
    func_ptr callback;
    void *callback_param;
} mms_content_entry_struct;

typedef struct
{
    MeaNewTypeEnum mode;
    char addr[MEA_MAX_ENCODE_ADDRESS_LENGTH];
    char subject[MEA_MAX_ENCODE_SUBJECT_LENGTH];
    char file_path[MEA_MAX_ENCODE_ADDRESS_LENGTH];  /* UCS2 MMI filename (not used)*/
    char text_buffer[MEA_MAX_ENCODE_TEXT_LENGTH];
    
    func_ptr callback;
    void *callback_param;
} mms_content_entry_struct_peer_buf;

/* MMS Entry Function */
extern int mms_is_ready(void);
extern void goto_mms_screen(void);
extern void mms_content_insert_hdlr(char *content_source);
extern void mms_content_insert_hdlr_with_callback(mms_content_entry_struct *data);
extern void mms_address_insert_hdlr(char *address);
extern void mms_text_insert_hdlr(char * subject, unsigned int subject_len, char * text, unsigned int text_len);
extern void mms_general_insert_hdlr(mms_content_entry_struct *data);
extern int wap_content_is_mms_forward(const char *filename);
extern void mms_on_enter_usb_mode(void);
extern void mms_on_exit_usb_mode(void);
extern wap_mms_content_class_enum wap_get_mms_content_class(void);
extern kal_uint32 wap_get_max_mms_size_in_restricted_mode(void);
extern void wap_get_max_mms_image_resolution_in_restricted_mode(kal_int32 *width, kal_int32 *height);
#endif /* MMS_SUPPORT */ 

#ifdef __UNIFIED_MSG_SUPPORT__
extern void wap_um_entry_msg_wap_push(kal_uint16 msg_box_type, kal_uint16 msg_index);
extern void wap_um_entry_msg_mms(kal_uint16 msg_box_type, kal_uint16 msg_index);
extern void wap_um_entry_write_mms(void);
extern void wap_um_entry_template_mms(void);
extern void wap_um_entry_setting_mms(void);
extern int wap_is_message_resource_available(void);
#endif /* __UNIFIED_MSG_SUPPORT__ */ 


typedef enum
{
    WAP_DL_ERROR_OK,
    WAP_DL_ERROR_CANCELLED,
    WAP_DL_ERROR_INVALID_SESSION_ID,
    WAP_DL_ERROR_CONNECTION_CLOSED,
    WAP_DL_ERROR_INVALID_FILE,
    WAP_DL_ERROR_DISK_FULL,
    WAP_DL_ERROR_FILE_ACCESS,
    WAP_DL_ERROR_FILE_READ_ONLY
} wap_dl_error_enum;

typedef enum
{
    WAP_DL_STATUS_DOWNLOADING,
    WAP_DL_STATUS_COMPLETE,
    WAP_DL_STATUS_ABORTED,
    WAP_DL_STATUS_CANCELLED
} wap_dl_status_enum;


/*****************************************************************************/
/* WCSS related                                                              */
/*****************************************************************************/

/* It should not be too large because it takes stack space (support 40 WCSS format string content) */
#define WIDGET_MAX_FORMAT_PATTERN_LEN        (82)

/* Handling UCS2 string not aligned with 2 bytes. (Obigo adopts UTF8 by default) */
#ifndef CAST_PU8
#define CAST_PU8(RAW)   ((kal_uint8*)(RAW))
#endif
#ifndef CAST_CPU8
#define CAST_CPU8(RAW)  ((const kal_uint8*)(RAW))
#endif
#ifndef GET_U8_BYTE_TO_U16
#define GET_U8_BYTE_TO_U16(RAW, i)  ((kal_uint16)(CAST_CPU8(RAW)[i]))
#endif

#ifndef STR_SIZE
#define STR_SIZE(len) ((len)<<1)
#endif
#ifndef CHR_AT
#define CHR_AT(RAW, n) ((kal_uint16)(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n))+(GET_U8_BYTE_TO_U16(RAW, STR_SIZE(n)+1)<<8)))
#endif
#ifndef STR_AT
#define STR_AT(RAW, n) ((void*)(CAST_PU8(RAW)+STR_SIZE(n)))
#endif
#ifndef SET_CHR_AT
#define SET_CHR_AT(RAW, n, value)   do {                          \
                              kal_uint8 *_p = STR_AT(RAW, n);     \
                              kal_uint16 v= (kal_uint16) (value); \
                              _p[0] = (kal_uint8) (v & 0xff);     \
                              _p[1] = (kal_uint8) (v >> 8);       \
                           } while (0)
#endif
#ifndef CHR
#define CHR(x)      ((kal_uint16)(x))
#endif

/* WCSS related API */
extern void widget_init_input_CSS_pattern(const char *input_pattern);
extern kal_uint8 * widget_get_input_CSS_format_pattern(void);
extern kal_bool widget_is_match_CSS_pattern(void *input_buffer);
extern int widget_set_wcss_input_format_default_value(kal_uint8 *buffer, int *max_len, const char *format_pattern);


/* this struct and all its parameters malloc using MSF_MODID_WIDGET module ID */
typedef struct
{
    char *content;          /* zero-terminated UTF8 format */
    char *addr;             /* send to address in ascii */
} wap_message_editor_t;

#ifdef JATAAYU_SUPPORT

#ifdef __PRODUCTION_RELEASE__
#define WAP_DBG_ASSERT(_expr)
#else /* __PRODUCTION_RELEASE__ */ 
#define WAP_DBG_ASSERT(_expr) {ASSERT(_expr);}
#endif /* __PRODUCTION_RELEASE__ */ 


#elif defined(OBIGO_Q03C)

#ifdef WAP_SUPPORT
/*
 * Used wapadp.lib to determine MMI capabilities.
 */
extern int wap_mmi_capability_imelody(void);
extern int wap_mmi_capability_changeable_font(void);
extern int wap_mmi_capability_large_font(void);

#define WAP_IMELODY_SUPPORT()    wap_mmi_capability_imelody()
#define WAP_CHANGEABLE_FONT()    wap_mmi_capability_changeable_font()
#define WAP_LARGE_FONT()         wap_mmi_capability_large_font()
#endif /* WAP_SUPPORT */ 

/*
 * Start function
 */
extern void widget_MMI_on_exit_CM(void);
extern void widget_MMI_on_enter_idle_screen(void);
extern int widget_MMI_check_and_display_new_msg(void);
extern int widget_MMI_check_and_display_new_msg_when_keypad_lock(
            unsigned short KeyLockLSKStringID,
            unsigned short KeyLockLSKIconID,
            unsigned short KeyLockRSKStringID,
            unsigned short KeyLockRSKIconID);

#ifdef MMS_SUPPORT
/*
 * When MMS editor selects the number from the phonebook, 
 * goback the history via theis function
 */
extern void widget_MMI_fullscreen_editor_update_from_phonebook(unsigned char *data);

#endif /* MMS_SUPPORT */ 

#define WIDGET_VIRTUAL_FILE_SUPPORT

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern kal_uint8 wap_status;
extern kal_int32 wap_external_get_id;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* Download support */
extern void notifiy_mmi_wap_add_downloaded(int type, char *filename);
extern void notifiy_mmi_wap_delete_download_index(int type, char *filename);
extern int get_free_slot_of_downloaded_file(int type);

extern int msm_add_download_file_check(long file_size);
extern int msm_rescan_download_file_stats(void);
extern void msm_update_download_file_stats(long file_size);
extern void msm_remove_download_file_stats(long file_size);

/* Task */
extern void wap_task_sleep(int milliseconds);
extern int MSF_wapIsReady(void);
extern int MSF_wapIsInit(void);

/* File API */
extern kal_uint8 *HDI_FileNameTranslate(const char *src);
extern void HDI_FileNameFree(kal_uint8 *fname);

#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
extern int HDIa_fileGenVirtualFileName(int fileHandle, char *vfs_name, int name_len, int offset, int len);
#endif 

extern int HDIa_fileCheckDirExist(const char *dirName);
extern int HDI_FileGetDiskLabel(wap_storage_enum type);

/* Pipe */
extern int HDIa_pipeDeleteByHandle(int handle);

/* Socket */
extern void HDIa_socketDiscBearerById(signed long networkAccountID);

/* Filesystem support */
#define HDI_EXTERNAL_PATH            "/external/"
#define HDI_EXTERNAL_LEN             10

#ifdef __USB_IN_NORMAL_MODE__
#define MAX_CACHE_PDU_FILE_NUM 10
extern void HDIa_fileHideDir(const char *dirName);
#endif /* __USB_IN_NORMAL_MODE__ */ 

extern kal_uint32 msm_get_disk_free_space(kal_uint8 disk_index);
extern kal_bool msm_copy_file(const char *dstName, const char *srcName);
extern void msm_copy_files_under_dir(const char *srcFolder, const char *dstFolder);
extern void msm_remove_files_under_dir(const char *folder);

extern void msm_get_folder_info(char *path, int *file_num, long *file_size);
extern void msm_get_folder_info_recursive(char *path, int *file_num, long *file_size);

/*
 * MMS
 */
extern void meaTerminateApp(void);

extern void mms_set_indicator(int statusType);
extern int mms_current_indicator_type(void);
extern kal_bool mms_has_new_message(void);

extern void widget_MMI_fullscreen_editor_update_from_phonebook(kal_uint8 *data);
#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
extern void wap_mms_send_msg(kal_uint32 msg_id);
#endif /*#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))*/
/*
 * Widget internal
 */
extern void widget_notify_shutdown_UI_finished(void);

/* 
 * WAP_DBG_ASSERT -  Non-fatal error. Test if something strange happened, removed in production release
 *                We may want to gaurentee input value is correct, but do not want to waste time in production release.
 * WAP_RST_ASSERT -  Understandable/traceable/expected error, sometimes for unsupported integration API, 
 *                or due to resource limitation (but not error). We can restart the mobile suite to solve it.
 *                This can be used only inside setjmp().
 * WAP_VERBOSE_ASSERT - Actually there is some problem, but we will not fix it anytime soon.
 * WAP_BYPASS_ASSERT -  This check is important, we do not want to use WAP_DBG_ASSERT because QA should not ignore it.
 *                However, it is not a real error case that cause problem immediately, and we do not use ASSERT()
 *                in order to prevent unnecessary ASSERT() at critical scenarios (e.g. boot-up).
 * ASSERT         -  We are sure that this should not happen, and we don't know how to recover from it.
 *                (Maybe memory is corrupted)
 */
extern void wap_restart_task(void);
extern kal_bool wap_enable_debug_assert;

#ifdef __PRODUCTION_RELEASE__
#define WAP_DBG_ASSERT(_expr)
#define WAP_VERBOSE_ASSERT(_expr)
#define WAP_BYPASS_ASSERT(_expr)
#define WAP_RST_ASSERT(_expr) {if(!(_expr)) {wap_restart_task();}}
#else /* __PRODUCTION_RELEASE__ */ 
#define WAP_DBG_ASSERT(_expr) {if(wap_enable_debug_assert) ASSERT(_expr);}
#define WAP_VERBOSE_ASSERT(_expr)       /* Enable it if you want */
#define WAP_BYPASS_ASSERT(_expr) ASSERT(_expr)
#define WAP_RST_ASSERT(_expr) {if(!(_expr)) {if (wap_enable_debug_assert) {ASSERT(0);} else {wap_restart_task();}}}
#endif /* __PRODUCTION_RELEASE__ */ 

#endif /* OBIGO_Q03C */
#endif /* _WAPADP_H */ 

