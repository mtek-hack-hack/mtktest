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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/*! \file mea_def.h
 *  \brief Definitions for the MEA module.
 */

#ifndef _MEA_DEF_H
#define _MEA_DEF_H

/*--- Definitions/Declarations ---*/

/* Registry declarations  */

/*! The path for the registry settings for external settings
 */
#define MEA_REG_PATH_EXT                    "/EXTERNAL"

/*! Key for the MSISDN.
 */
#define MEA_REG_KEY_MSISDN                  "MSISDN"

/*! The path for the registry settings for the MEA
 */
#define MEA_REG_PATH_MMS                    "/MEA/mms"

/*! Key for setting the "Save on send" feature.
 */
#define MEA_REG_KEY_SAVE_ON_SEND            "SavOnSnd"

/*! Key for setting default value for read report.
 */
#define MEA_REG_KEY_READ_REPORT             "ReadRpt"

/*! Key for setting default value for delivery report.
 */
#define MEA_REG_KEY_DELIVERY_REPORT         "DelRpt"

/*! Key for setting default value for priority.
 */
#define MEA_REG_KEY_PRIORITY                "Priority"

/*! Key for setting default value for slide duration.
 */
#define MEA_REG_KEY_SLIDE_DUR               "SlideDur"

/*! Key for setting default value for expiry time.
 */
#define MEA_REG_KEY_EXP_TIME                "ExpTime"

/*! Key for setting default value for reply charging.
 */
#define MEA_REG_KEY_REPLY_CHARGING          "RepChrg"

/*! Key for setting default value for reply charging deadline 
 */
#define MEA_REG_KEY_REPLY_CHARGING_DEADLINE "RepChDln"

/*! Key for setting default value for reply charging size
 */
#define MEA_REG_KEY_REPLY_CHARGING_SIZE     "RepChSiz"

/*! Key for setting default value for the MMSC version.
 *  Only for testing purposes.
 */
#define MEA_REG_KEY_MMSC_VERSION            "MmscVer"

/*! Key for setting default value for the Sender visibility.
 */
#define MEA_REG_KEY_SENDER_VISIBILITY       "SendVsbl"

/*! Key for setting default value for the Send read report
 */
#define MEA_REG_KEY_SEND_READ_REPORT        "SndRdRp"

/*! Key for setting default value for the Delivery Time.
 */
#define MEA_REG_KEY_DELIVERY_TIME           "DlvrTime"

/*! \brief Global expiry times in seconds */

/*! Expiry date  one h in seconds.
 */
#define MEA_EXPIRY_1_HOUR_IN_SEC            3600

/*! Expiry date 12h in seconds.
 */
#define MEA_EXPIRY_12_HOURS_IN_SEC          43200

/*! Expiry date one day in seconds.
 */
#define MEA_EXPIRY_1_DAY_IN_SEC             86400

/*! Expiry date one week in seconds.
 */
#define MEA_EXPIRY_1_WEEK_IN_SEC            604800

/*! Expiry date maximum (1 year) in seconds.
 */
#define MEA_EXPIRY_MAX_IN_SEC               31449600 /* A year as max */

#ifdef WAP_SUPPORT 
/*! Expiry date 6h in seconds.
 */
#define MEA_EXPIRY_6_HOURS_IN_SEC          21600

#define MEA_SMIL_FILE_NAME          "s.smil" /*! The filename used for the SMIL part in multi-part related messages */
#define MEA_SMIL_CONTENT_ID          "MMMM"

#define MEA_IMAGE_REGION            "Image" /*!< The image region name definition */
#define MEA_TEXT_REGION             "Text"  /*!< The text region name definition */

#define MEA_UNKNOWN_MIME_STR   "application/unknown"

#define UCS2_ENCODING_LENGTH 2 //for utf8 to ucs2

#define MEA_RESTRICTED_MESSAGE_SIZE  (300 * 1024)  /* 300K */
#define MEA_RESTRICTED_RESOLUTION  (640 * 480)
#endif /* WAP_SUPPORT */

/*--- Types ---*/

/*! \enum MeaMediaGroupType
 *  Media type definitions */
typedef enum
{
    MEA_MEDIA_GROUP_NONE  = 0x00,    /* !< None */
    MEA_MEDIA_GROUP_IMAGE = 0x01,    /* !< Image */
    MEA_MEDIA_GROUP_TEXT  = 0x02,    /* !< Text */
    MEA_MEDIA_GROUP_AUDIO = 0x04,     /* !< Audio */
    MEA_MEDIA_GROUP_DRM = 0x08,
    MEA_MEDIA_GROUP_VIDEO = 0x10,
    MEA_MEDIA_GROUP_ATTACHMENT = 0x20
}MeaMediaGroupType;

/* !\enum MeaMediaType 
 *  \brief Supported media types 
 */
typedef enum
{
    MEA_MEDIA_TYPE_UNSUPPORT = -2,  /*!< The media type is not support, and cannot insert as attachment (for restricted mode)*/
    MEA_MEDIA_TYPE_UNKNOWN = -1,     /*!< The media type is not known */

    /* Text */
    MEA_MEDIA_TYPE_TEXT_PLAIN = 0,  /*!< Plain text */
    MEA_MEDIA_TYPE_TEXT_SMIL,       /*!< The SMIL presentation; text/smil */

    /* Image */
    MEA_MEDIA_TYPE_JPEG,            /*!< A JPEG picture */
    MEA_MEDIA_TYPE_GIF,             /*!< A GIF picture */
    MEA_MEDIA_TYPE_WBMP,            /*!< A WBMP picture */
    MEA_MEDIA_TYPE_BMP,             /*!< A BMP picture */
#ifdef GDI_USING_PNG
    MEA_MEDIA_TYPE_PNG,             /*!< A BMP picture */
#endif

    /* Audio */
    MEA_MEDIA_TYPE_AMR, /*!< A AMR audio file */
#ifdef AMRWB_DECODE
    MEA_MEDIA_TYPE_AWB,
#endif /* AMRWB_DECODE */
    MEA_MEDIA_TYPE_WAV,             /*!< A WAV audio file */
    MEA_MEDIA_TYPE_VM,
    MEA_MEDIA_TYPE_MIDI,            /*!< A MIDI audio file  */
#ifdef DAF_DECODE
    MEA_MEDIA_TYPE_MP3,             /*!< A MP3 audio file */
#endif /* DAF_DECODE */
    MEA_MEDIA_TYPE_IMY,             /*!< A iMelody audio file */
#ifdef YAMAHA_MA3
    MEA_MEDIA_TYPE_SMAF,
#endif
#ifdef WMA_DECODE
    MEA_MEDIA_TYPE_WMA,
#endif
#ifdef AAC_DECODE
    MEA_MEDIA_TYPE_AAC,
#endif
#if defined(MP4_CODEC) && defined(AAC_DECODE)
    MEA_MEDIA_TYPE_M4A,
#endif
#ifdef AIFF_DECODE
    MEA_MEDIA_TYPE_AIFF,
#endif
#ifdef AU_DECODE
    MEA_MEDIA_TYPE_BASIC,
#endif

    /* Video */
    MEA_MEDIA_TYPE_3GP,
    MEA_MEDIA_TYPE_MP4,
    MEA_MEDIA_TYPE_MPEG,
#ifdef MJPG_SUPPORT
    MEA_MEDIA_TYPE_AVI,
#endif

    MEA_MEDIA_TYPE_VCARD,         /*!< A vCard file  */
    MEA_MEDIA_TYPE_VCALENDAR,  /*!< A vCalendar */
    MEA_MEDIA_TYPE_DRM_MESSAGE,
    MEA_MEDIA_TYPE_DRM_CONTENT,

    /* Delimiter */
    MEA_MEDIA_TYPE_END_TYPE    /*!< this type should always be last.*/
} MeaMediaType;

/*! \enum MeaExpiryTimeType
 *  \brief The Expiry time for a message
 */
typedef enum
{
    MEA_EXPIRY_1_HOUR,      /*!< One hour */
    MEA_EXPIRY_6_HOURS,     /*!< 6 hours */
    MEA_EXPIRY_12_HOURS,    /*!< 12 hours */
    MEA_EXPIRY_1_DAY,       /*!< One day */
    MEA_EXPIRY_1_WEEK,      /*!< One week */
    MEA_EXPIRY_MAX          /*!< The maximum expiry time */
}MeaExpiryTimeType;

/* !\enum MeaPriorityType
 *  \brief The message priority
 */
typedef enum
{
    MEA_PRIORITY_LOW,       /*!< Low priority */
    MEA_PRIORITY_NORMAL,    /*!< Normal priority */
    MEA_PRIORITY_HIGH       /*!< High priority */
}MeaPriorityType;

/* !\enum MeaReplyChargingType
 *  \brief Reply charging setting for message creation
 */
typedef enum
{
    MEA_REPLY_CHARGING_OFF,       /*!< Reply charging off */
    MEA_REPLY_CHARGING_ON,        /*!< Reply charging on */
    MEA_REPLY_CHARGING_TEXT_ONLY  /*!< Reply charging for text messages only */
}MeaReplyChargingType;

/* !\enum MeaVisibilityType
 *  \brief Sender visibility setting
 */
typedef enum
{
    MEA_SENDER_SHOW,            /*!< Show sender */
    MEA_SENDER_HIDE             /*!< Hide sender */
}MeaVisibilityType;

/* !\enum MeaReplyChargingDeadlineType
 *  \brief Reply charging deadline setting for message creation
 */
typedef enum
{
    MEA_REPLY_CHARGING_DEADLINE_1_DAY  = 0, /*!< Reply ch. dl 1 day */
    MEA_REPLY_CHARGING_DEADLINE_1_WEEK,     /*!< Reply ch. dl 1 week */
    MEA_REPLY_CHARGING_DEADLINE_MAX         /*!< Max reply ch. time 1yr */    
}MeaReplyChargingDeadlineType;

/* !\enum MeaReplyChargingSizeType
 *  \brief Reply charging size setting for message creation
 */
typedef enum
{
    MEA_REPLY_CHARGING_SIZE_1_KB  =  0, /*!< Reply charging max size 1 KB */
    MEA_REPLY_CHARGING_SIZE_10_KB,      /*!< Reply charging max size 10 KB */
    MEA_REPLY_CHARGING_SIZE_MAX         /*!< Unlimited reply charging size */
}MeaReplyChargingSizeType;

/* !\enum MeaRetrievalModeType
 *  \brief Retrieval mode setting 
 */
typedef enum
{
#ifdef WAP_SUPPORT
    MEA_RETRIEVAL_MODE_ALWAYS_ASK = 0,	/*! < Delayed retrieval mode */
    MEA_RETRIEVAL_MODE_AUTOMATIC  = 1,	/*! < Immediate retrieval mode */
    MEA_RETRIEVAL_MODE_RESTRICTED = 2
#else
    MEA_RETRIEVAL_MODE_AUTOMATIC  = 0,  /*! < Immediate retrieval mode */
    MEA_RETRIEVAL_MODE_ALWAYS_ASK = 1   /*! < Delayed retrieval mode */
#endif /* WAP_SUPPORT */
}MeaRetrievalModeType;


/* !\enum MeaRetrievalModeRoamingType
 *  \brief Retrieval mode setting when roaming 
 */
typedef enum
{
    MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC  = 0,  /*! < Use same setting as home */
    MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK = 1,  /*! < Delayed retrieval mode */
    MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED = 2   /*! < Restricted mode */
}MeaRetrievalModeRoamingType;
#ifdef __OP01_MMS_RETRIEVE_SETTING__
typedef enum
{
    MEA_DELIVERY_REPORT_YES,            /*!< Always send read report */
    MEA_DELIVERY_REPORT_NO              /*!< Never send read report */
}MeaDeliveryReportType;
#endif /*__OP01_MMS_RETRIEVE_SETTING__*/

/*! The default setting for Send read report. 0=On request 1=Always 2=Never*/

/* !\enum MeaSendReadReportType
 *  \brief Setting for how read report requests should be handled
 */
typedef enum
{   
    MEA_SEND_READ_REPORT_ON_REQUEST = 0,    /*!< Send read report on request */
    MEA_SEND_READ_REPORT_ALWAYS,            /*!< Always send read report */
    MEA_SEND_READ_REPORT_NEVER              /*!< Never send read report */
}MeaSendReadReportType;

/* !\enum MeaDeliveryTimeType
 *  \brief Setting for delivery time
 */
typedef enum
{
    MEA_DELIVERY_TIME_IMMEDIATE = 0,    /*!< Immediate */
    MEA_DELIVERY_TIME_1_HOUR,           /*!< 1 hour */
    MEA_DELIVERY_TIME_12_HOURS,         /*!< 12 hours */
    MEA_DELIVERY_TIME_24_HOURS          /*!< 24 hours */
}MeaDeliveryTimeType;

typedef enum
{
    MEA_CREATION_MODE_FREE = 0,
    MEA_CREATION_MODE_RESTRICTED
}MeaCreationModeType;


typedef enum
{
    MEA_IMAGE_RESIZE_OFF = 0,
    MEA_IMAGE_RESIZE_160x120,
    MEA_IMAGE_RESIZE_320x240,
    MEA_IMAGE_RESIZE_640x480
}MeaImageResizeType;

/* Callback return value for choosing file from File Manager */
typedef enum 
{
    MEA_INSERT_OK,						/* OK */
    MEA_WARNING_INSERT_LARGE_OBJ,	/* Warning: Object size */
    MEA_WARNING_INSERT_LARGE_MMS,	/* Warning: MMS size */
    MEA_ERR_INSERT,						/* Error: Misc. */
    MEA_ERR_INSERT_UNKNOWN,			/* Error: Unknown MIME */
    MEA_ERR_INSERT_DRM,				/* Error: DRM */
    MEA_ERR_INSERT_RESIZE,				/* Error: Resize failed */
    MEA_ERR_INSERT_LARGE,				/* Error: Object too large */
    MEA_ERR_INSERT_EMPTY,				/* Error: Empty object */
    MEA_ERR_INSERT_CORRUPT,				/* Error: Object corrupted */
    MEA_ERR_INSERT_DISK_FULL,			/* Error: Disk full */
    MEA_ERR_INSERT_RESOURCE_EXHAUSTED,	/* Error: No memory */
    MEA_ERR_INSERT_UNRESTRICTED		/* Error: Unrestricted object */
} MeaInsertResult;

/*! \enum MeaFolder 
 *  Folders valid for MEA */
typedef enum 
{
    MEA_FOLDER_NONE  = 0x00, /*!< Only for operations where the current folder
                                 needs to be updated or when to display the
                                 navigation menu and no folder is active. */
    MEA_FOLDER_INBOX = 0x01,  /*!< The Inbox folder */
    MEA_FOLDER_DRAFTS = 0x02,        /*!< The Drafts folder */
    MEA_FOLDER_SENT = 0x04,          /*!< The Sent folder */
    MEA_FOLDER_OUTBOX = 0x08,        /*!< The Outbox folder */
    MEA_FOLDER_TEMPLATE = 0x10,      /*!< The template folder */
    MEA_FOLDER_ARCHIVE = 0x20,		/*!< The Archive folder>*/
    MEA_FOLDER_USER_TEMPLATE = 0x40,
    MEA_FOLDER_COUNT          /*!< Not used only a counter */
}MeaFolder;

/*!\enum MeaAddrType
 * \brief Possible address-types when creating messages
 */
typedef enum
{
    MEA_ADDR_TYPE_NONE      = 0x00,     /*!< No valid address */
    MEA_ADDR_TYPE_PLMN      = 0x01,     /*!< Phone no */
    MEA_ADDR_TYPE_EMAIL     = 0x02,     /*!< Email */
    MEA_ADDR_TYPE_IPV4      = 0x04      /*!< IP address */
}MeaAddrType;

/*!
* Use name param instead of file name param. 
* The ShangHai CMCC MMSC has compatibility issue with T610 if we don't define this option.
*/
#define MMS_USE_NAME_PARMS

#endif /* _MEA_DEF_H */


