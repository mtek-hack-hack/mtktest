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
#ifndef _mma_def_h
#define _mma_def_h

/**********************************************************************
 * Function declarations
 **********************************************************************/
extern kal_bool mmi_uc_is_uc_screen_in_history(void);

/**********************************************************************
 * Macro definition
 **********************************************************************/
/* memory */
#define MMA_CALLOC(p, s)        p = MSF_MEM_ALLOC(MSF_MODID_MMA, s); memset((p), 0, (s))
#define MMA_ALLOC(s)      MSF_MEM_ALLOC(MSF_MODID_MMA, s)
#define MMA_FREE(p)        if (NULL != (p)) MSF_MEM_FREE(MSF_MODID_MMA, (p))

/* folder */
#ifdef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
#define MMA_IS_FOLDER_EXIST(f)  (f == MMA_FOLDER_INBOX || f == MMA_FOLDER_OUTBOX || f == MMA_FOLDER_SENT || \
                                 f == MMA_FOLDER_DRAFT || f == MMA_FOLDER_TEMPLATE || f == MMA_FOLDER_ARCHIVE || \
                                 f == MMA_FOLDER_USRDEF_TEMPLATE)
#else
#define MMA_IS_FOLDER_EXIST(f)  (f == MMA_FOLDER_INBOX || f == MMA_FOLDER_OUTBOX || f == MMA_FOLDER_SENT || \
                                 f == MMA_FOLDER_DRAFT || f == MMA_FOLDER_TEMPLATE || f == MMA_FOLDER_ARCHIVE)
#endif
                                 
/**********************************************************************
 * Constant definition
 **********************************************************************/
/* queue management */
#define MMA_MMS_MAX_SIG_HANDLING_NUM  18  /* MMS_SIG_CREATE_MSG_REPLY ~ MMS_SIG_GET_MSG_INFO_REPLY */
#define MMA_MODID_NONE MSF_NUMBER_OF_MODULES

/* restricted mode: originally defined in mea_def.h since editor was originally in MEA */
#define MMA_RESTRICTED_MESSAGE_SIZE  (300 * 1024)  /* 300K */
#define MMA_RESTRICTED_RESOLUTION    (640 * 480)

/* Time constant */
#define MMA_1_SEC_IN_DSEC    10      /* decimal seconds per second */
#define MMA_1_SEC_IN_MSEC    1000    /* decimal seconds per second */
#define MMA_1_HOUR_IN_SEC    3600    /* seconds per hour */
#define MMA_12_HOURS_IN_SEC  43200   /* seconds for 12 hours */
#define MMA_1_DAY_IN_SEC     86400   /* seconds per day */
#define MMA_1_WEEK_IN_SEC    604800  /* seconds per week */

typedef enum
{
    MMA_SEND_NONE,
    MMA_SEND_START,
    MMA_SEND_PENDING,
    MMA_SEND_SENDING,
    MMA_SEND_FINISHED
}mma_send_state_enum;

typedef enum
{
    PARSE_STATE_STARTED,
    PARSE_STATE_MMS_HEADER_PARSING,
    PARSE_STATE_SLS_ACTIVATING,
    PARSE_STATE_SMIL_OPENING,
    PARSE_STATE_SLIDE_CONTENT_PARSING,
    PARSE_STATE_SLIDE_CONTENT_DONE,
    PARSE_STATE_SLS_DEACTIVATING,
    PARSE_STATE_SLS_DEACTIVATED,
    PARSE_STATE_TEMPLATE_CONTENT_REPLACING,
    PARSE_STATE_CONTENT_FILTERING,
    PARSE_STATE_SMIL_ADDING,
    PARSE_STATE_XML_CREATING,
    PARSE_STATE_ABORTED,
    PARSE_STATE_FINISHED
} mma_parse_state_enum;

typedef enum
{
    CREATE_STATE_STARTED,
    CREATE_STATE_XML_PARSING,
    CREATE_STATE_CREATION_PREPROCESSING,
    CREATE_STATE_CREATING,
    CREATE_STATE_MMS_HEADER_PARSING,
    CREATE_STATE_MMS_HEADER_CREATING,
    CREATE_STATE_MMS_BODY_COPYING,
    CREATE_STATE_MMS_SMIL_CREATING,
    CREATE_STATE_MMS_BODY_CREATING,
    CREATE_STATE_MMS_INFO_CREATING,
    CREATE_STATE_MMS_FINALIZING,
    CREATE_STATE_FINISHED
} mma_create_state_enum;

typedef enum
{
    PREVIEW_STATE_STARTED,
    PREVIEW_STATE_SMA_ACTIVATING,
    PREVIEW_STATE_SMIL_PLAYING,
    PREVIEW_STATE_SMIL_PLAYED,
    PREVIEW_STATE_SMA_DEACTIVATING,
    PREVIEW_STATE_SMA_DEACTIVATED,
    PREVIEW_STATE_FINISHED
} mma_preview_state_enum;

typedef enum
{
    DELETE_STATE_STARTED,
    DELETE_STATE_FOLDER_LIST_GETTING,
    DELETE_STATE_FOLDER_LIST_DELETING_LOOP,
    DELETE_STATE_DELETING,
    DELETE_STATE_FINISHED
} mma_delete_state_enum;

typedef enum
{
    MMA_DRM_METHOD_NONE,
    MMA_DRM_METHOD_FORWARD_LOCK,
    MMA_DRM_METHOD_COMBINED_DELIVERY,
    MMA_DRM_METHOD_SEPARATE_DELIVERY
} mma_drm_method_enum;

typedef enum
{
    MMA_PLAIN_TEXT,     /*!< The message is of type plain text */
    MMA_SMIL,           /*!< The message is of type SMIL */
    MMA_MULTIPART_MIXED,/*!< The message is of type Multipart/mixed */
    MMA_MULTIPART_ALTERNATIVE, /*!< The message is of type multipart/alternative*/
    MMA_UNSUPPORTED     /*!< The message type is not supported */
}mma_mms_multipart_enum;

typedef enum
{
    MMA_SEND_TIMER_ID = 0x1     /* for retry interval countdown */
}mma_timer_id_enum;

/**********************************************************************
 * Structure definition
 **********************************************************************/
typedef struct
{
    kal_bool is_active;
    kal_uint32 timer_id;
}mma_timer_struct;

typedef struct 
{
    kal_uint32 ilm_sender;
    kal_uint32 ilm_msg_id;
    kal_uint32 req_id;
    void *entry_info;
}mma_request_entry_struct;

typedef struct 
{
    kal_uint32 id;  /* Assigned sequence ID for sending request */

    kal_uint32 ilm_sender;
    kal_uint8 mms_sender;
    kal_uint8 app_id;
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_bool send_and_save;
    kal_bool is_read_report;
    mma_folder_enum folder;  /* box to save in if send_and_save = TRUE */

    mma_send_state_enum state;
    kal_uint8 percent;
    kal_uint8 retry;
    kal_uint8 retry_countdown;
}mma_send_request_entry_struct;

typedef struct
{
    union {
        MmsGetHeader *g_header;  /* used when parsing */
        MmsSetHeader *s_header;  /* used when creating */
    }header;
    
    mma_mms_multipart_enum multipart_type;
    kal_uint32 body_no;
}mma_header_struct;

typedef struct mma_object_struct_t
{
    SlsMediaType type;
    kal_uint32 size;
    kal_uint32 offset;
    kal_uint32 charset;    /* used for text */
    char *filePath;     /* file path. In virtual file case, this indicates the parent file */
    char *fileName;     /*!< FileName */
    char *boundary;     /*!< The boundary, used for DRM */
    char *mimeType;     /*!< The mimetype of the media object */
    char *alt;          /* used for image/video */
    kal_bool isAttachment;
    kal_bool isVirtualFile;

    kal_uint16 xmlId;      /* used for indexing in xml */
#ifdef __DRM_SUPPORT__
    mma_drm_type_enum xmlDrmType;  /* used for DRM type in xml */
    SlsMediaType drmType;
    char *drmMimeType;
#endif
    struct mma_object_struct_t *next;
}mma_object_struct;

typedef struct
{
    mma_object_struct *obj;
    SlsRegion region;       /* used for image/video/text */
    kal_uint32 text_color;  /* used for text */
    kal_uint8 begin;
    kal_uint8 end;
    kal_uint16 id;  /* = obj->xmlId */
}mma_slide_object_struct;

typedef struct mma_slide_struct_t
{
    mma_slide_object_struct image;
    mma_slide_object_struct video;
    mma_slide_object_struct audio;
    mma_slide_object_struct text;
    struct mma_slide_struct_t *next;
    kal_uint16 duration;

    kal_uint16 xmlId;      /* used for indexing in xml */
}mma_slide_struct;

typedef struct mma_unref_list_struct_t
{
    mma_object_struct *attachment;
    struct mma_unref_list_struct_t *next;
}mma_unref_list_struct;

typedef struct
{
    SlsRootLayout root_layout;
    mma_slide_layout_enum layout;
    kal_uint32 slide_no;
    mma_slide_struct *slides;
    mma_object_struct *objects;
    mma_slide_struct *current_slide;
    mma_object_struct *current_object;
    mma_unref_list_struct *unref_list;  /* attachment */
}mma_body_struct;

typedef struct
{
    /* refer to wap_mma_get_content_req_struct */
    kal_uint8 app_id;
    kal_uint32 msg_id;
    mma_app_mode_enum mode;
    mma_creation_mode_enum creation_mode;
    kal_uint32 header_size;
    kal_uint32 body_size;
    kal_uint32 xml_size;
    kal_wchar *xml_filepath;
    kal_uint32 buffer_index;

    /* FSM context */    
    mma_header_struct *header;
    mma_body_struct *body;

    MmsMsgHandle m_handle;  /* MmsMessage */
    MmsTransactionHandle t_handle;
    mma_parse_state_enum state;
    kal_uint32 sub_state;
}mma_get_content_info_struct;

typedef struct
{
    /* refer to wap_mma_create_req_struct */
    kal_uint8 app_id;
    kal_uint32 o_msg_id;  /* send / forward */
    mma_app_mode_enum mode;
    kal_uint32 xml_size;
    kal_wchar *xml_filepath;
    kal_uint32 buffer_index;
    kal_bool more;

    /* FSM context */    
    kal_uint32 msg_id;
    mma_header_struct *header;
    mma_body_struct *body;

    MmsMsgHandle m_handle;  /* MmsMessage */
    MmsTransactionHandle t_handle;
    MmsGetHeader *o_header;  /* send / forward */
    kal_int32 r_handle;  /* file handle for read operation */
    kal_int32 w_handle;  /* file handle for write operation */
    kal_uint32 r_byte;  /* byte number which has been read */
    kal_uint32 w_byte;  /* byte number which has been written */
    mma_create_state_enum state;
    kal_uint32 sub_state;
    mma_result_enum result;
}mma_create_mms_info_struct;

typedef struct
{
    /* refer to wap_mma_save_req_struct */
    kal_uint32 app_id;
    kal_uint32 msg_id;
    mma_folder_enum folder;
}mma_move_mms_info_struct;

typedef struct
{
    /* refer to wap_mma_cancel_send_req_struct */
    kal_uint32 app_id;
    kal_uint32 msg_id;
}mma_cancel_send_mms_info_struct;

typedef struct
{
    /* refer to wap_mma_preview_req_struct */
    kal_uint8 app_id;
    kal_uint32 msg_id;
    mma_preview_state_enum state;
}mma_preview_mms_info_struct;

typedef struct
{
    kal_uint8 app_id;
    kal_uint32 notif_id;
    kal_uint32 bytes_received;
    kal_uint8 percent;
}mma_download_mms_info_struct;

typedef mma_cancel_send_mms_info_struct mma_cancel_download_info_struct;

typedef struct
{
    /* refer to wap_mma_msg_is_valid_req_struct */
    kal_uint8 app_id;
    kal_uint32 *msg_id_list;
}mma_check_mms_info_struct;

typedef struct
{
    /* refer to wap_mma_delete_req_struct */
    kal_uint8 app_id;
    kal_uint32 msg_id;
    mma_folder_enum box;
    MmsListOfProperties *list;
    kal_uint32 curr;  /* keep track of the list deleting progress */
    mma_delete_state_enum state;
}mma_delete_mms_info_struct;

#endif /* _mma_def_h */
