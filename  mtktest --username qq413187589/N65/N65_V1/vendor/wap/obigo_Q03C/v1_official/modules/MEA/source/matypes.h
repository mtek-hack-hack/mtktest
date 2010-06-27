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

/* !\file matypes.h
 *  \brief Common data-types and constants used internally by the MEA.
 */

#ifndef _MATYPES_H_
#define _MATYPES_H_

#ifndef _MMS_DEF_H
#error mms_def.h needs be included before matypes.h!
#endif

#ifdef WAP_SUPPORT
#ifndef _stk_if_h
#include "stk_if.h"
#endif
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Constants
 *****************************************************************************/

#define MEA_MAX_SMIL_OBJS           3   /*!< The maximum number of objects
                                             for one slide */

/*!\enum MeaConnectionType
 * \brief Network connection types 
 */
typedef enum
{
#ifdef WAP_SUPPORT
    MEA_CONNECTION_TYPE_HTTP=STK_CONNECTION_TYPE_HTTP,
    MEA_CONNECTION_TYPE_WSP_CL=STK_CONNECTION_TYPE_WSP_CL,
    MEA_CONNECTION_TYPE_WSP_CO =STK_CONNECTION_TYPE_WSP_CO
#else
    MEA_CONNECTION_TYPE_HTTP,       /*!< HTTP */
    MEA_CONNECTION_TYPE_WSP_CL,     /*!< WAP connectionless  */
    MEA_CONNECTION_TYPE_WSP_CO      /*!< WAP connection oriented */
#endif /* WAP_SUPPORT */
}MeaConnectionType;


/* === CONFIG MENU CONSTANTS === */

/*!\enum MeaConfigMenu
 *  
 */
typedef enum
{
    MEA_CONFIG_MENU_DEFAULT,  /*!< Entry point for menu system */
    MEA_CONFIG_MENU_ROOT,     /*!< Corresponds to #MeaConfigGroups */
    MEA_CONFIG_MENU_COMPOSE,
    MEA_CONFIG_MENU_SEND,     /*!< Corresponds to #MeaConfigSend */
    MEA_CONFIG_MENU_FILTER,   /*!< Corresponds to #MeaConfigFilter */
    MEA_CONFIG_MENU_NETWORK,  /*!< Corresponds to #MeaConfigNetwork */
    MEA_CONFIG_MENU_MMS_SETTINGS,/*!< Corresponds to #MeaConfigSend */
    MEA_CONFIG_MENU_REP_CHRG_SETTINGS,/*< Corresponds to #MeaConfigReplyCharging*/
    MEA_CONFIG_MENU_RETRIEVE, /*!< Corresponds to #MeaConfigRetrieve */
    MEA_CONFIG_MENU_COUNT     /*!< Only for counting purposes */
}MeaConfigMenu;

/*! \enum MeaConfigGroups
 *  The different configuration groups/items
 */
typedef enum
{
#ifdef WAP_SUPPORT
    MEA_CONFIG_COMPOSE,               /*!< Creation setting >*/
#endif /* WAP_SUPPORT */
    MEA_CONFIG_SENDING,                 /*!< Message sending properties */
    MEA_CONFIG_RETRIEVAL,               /*!< Message retrieval; delayed or immediate */
    MEA_CONFIG_FILTER,                  /*!< Filters for immediate retrieval */
#ifdef WAP_SUPPORT // 4~6th menu items are edit profile, signature, memory status
    MEA_CONFIG_NETWORK,                 /*!< Network account, conn type, WAP gateway */
    MEA_CONFIG_MEMORY_STATUS,          /*!< Memory Status */
    MEA_CONFIG_MMSC,                    /*!< Proxy host, URI, port and scheme */
#else
    MEA_CONFIG_MMSC,                    /*!< Proxy host, URI, port and scheme */
    MEA_CONFIG_NETWORK,                 /*!< Network account, conn type, WAP gateway */
#endif /* WAP_SUPPORT */
    MEA_CONFIG_GROUPS_COUNT             /*!< Not used, it is just a counter */
}MeaConfigGroups;

/*! \enum MeaConfigNetwork
 *  Configuration items for network
 */
typedef enum
{
    MEA_CONFIG_CONN_TYPE,   /*!< Connection type */
    MEA_CONFIG_NET_ACCOUNT, /*!< Network account */
    MEA_CONFIG_WAP_GW,      /*!< WAP gateway */
    MEA_CONFIG_LOGIN,       /*!< WAP GW Login */
    MEA_CONFIG_PASSWD,      /*!< WAP GW Password */
    MEA_CONFIG_REALM,       /*!< Realm */
    MEA_CONFIG_SEC_PORT,    /*!< Secure port */
    MEA_CONFIG_HTTP_PORT,   /*!< HTTP port */
#ifdef __MMS_DUAL_SIM_SUPPORT__    
    MEA_CONFIG_SLAVE_CONN_TYPE,
    MEA_CONFIG_SLAVE_NET_ACCOUNT,
    MEA_CONFIG_SLAVE_WAP_GW,
    MEA_CONFIG_SLAVE_LOGIN,
    MEA_CONFIG_SLAVE_PASSWD,
    MEA_CONFIG_SLAVE_REALM,
    MEA_CONFIG_SLAVE_SEC_PORT,
    MEA_CONFIG_SLAVE_HTTP_PORT,
#endif /*__MMS_DUAL_SIM_SUPPORT__ */
    MEA_CONFIG_NETWORK_COUNT/*!< Not used, it is just a counter */
}MeaConfigNetwork;

/*! \enum MeaConfigFilter
 *  \brief Configuration items for message retrieval */
typedef enum
{
    MEA_CONFIG_IM_SERVER,       /*!< Immediate retrieval server */
    MEA_CONFIG_IM_SIZE,         /*!< Maximum msg size for immediate retrieval*/
    MEA_CONFIG_TREAT_AS_DEL,    /*!< Treat large msgs as delayed retrieval */
    MEA_CONFIG_RETR_SIZE,       /*!< Maximum retrieval size for a download */
    MEA_CONFIG_ALLOW_ANONYM,    /*!< Allow msgs with anonymous sender */
    MEA_CONFIG_ALLOW_PERSONAL,  /*!< Allow msgs with class PERSONAL */
    MEA_CONFIG_ALLOW_ADVERT,    /*!< Allow msgs with class ADVERTISEMENT */
    MEA_CONFIG_ALLOW_INFO,      /*!< Allow msgs with class INFORMATIONAL */
    MEA_CONFIG_ALLOW_AUTO,      /*!< Allow msgs with class AUTO */
    MEA_CONFIG_ALLOW_STRING,    /*!< Allow msgs with used defined string */
    Mea_CONFIG_RETR_COUNT       /*!< Not used, it is just a counter */
}MeaConfigFilter;

/*! \enum MeaConfigSend
 *  \brief Configuration items for message sending */
typedef enum
{
    MEA_CONFIG_EXP_TIME,    /*!< Expiry time */
    MEA_CONFIG_READ_REPORT, /*!< Read report */
    MEA_CONFIG_DELIV_REPORT,/*!< Delivery report */
    MEA_CONFIG_PRIORITY,    /*!< Priority */
    MEA_CONFIG_SAVE_ON_SEND,/*!< Save on send flag */
    MEA_CONFIG_SLIDE_DUR,   /*!< Slide duration */
    MEA_CONFIG_REPLY_CHRG_MENU, /*!< Reply charging menu */
    MEA_CONFIG_SENDER_VISIBILITY, /*!< Sender visibility, Show/Hide number */
    MEA_CONFIG_DELIVERY_TIME,           /*!< Delivery time */
    MEA_CONFIG_SEND_COUNT   /*!< Not used, it is just a counter */
}MeaConfigSend;

/*! \enum MeaConfigRetrieve
 *  \brief Configuration items for message sending */
typedef enum
{
    MEA_CONFIG_HOME_NETWORK,    /*!< Home network */
    MEA_CONFIG_ROAM_NETWORK,    /*!< Roaming network */
    MEA_CONFIG_SEND_READ_REPORT,/*!< Send read report */
    MEA_CONFIG_DELIVERY_REPORT_ALLOWED, /*!< Delivery report allowed */
    MEA_CONFIG_RETRIEVE_COUNT   /*!< Not used, it is just a counter */
}MeaConfigRetrieve;

/*! \enum MeaConfigReplyCharging
 *  \brief Configuration items for reply charging */
typedef enum
{
    MEA_CONFIG_REPLY_CHARGING,          /*!< Reply charging */
    MEA_CONFIG_REPLY_CHARGING_DEADLINE, /*!< Reply charging deadline */
    MEA_CONFIG_REPLY_CHARGING_SIZE      /*!< Reply charging size */
}MeaConfigReplyCharging;

/*! \enum MeaConfigCompose
 *  \brief Configuration items for message composing */
typedef enum
{
    MEA_CONFIG_COMP_CREATION_MODE,    /*!< Creation mode */
#ifdef JPG_ENCODE
    MEA_CONFIG_COMP_IMAGE_RESIZE,    /*!< Image resize */
#endif
    MEA_CONFIG_COMP_AUTO_SIGNATURE,    /*!< Auto signature */
    MEA_CONFIG_COMP_AUTO_SIGNATURE_TEXT,    /*!< Auto signature */
    MEA_CONFIG_COMP_COUNT   /*!< Not used, it is just a counter */
}MeaConfigCompose;

/*! \typedef MeaTimeDef
 * 
 */
typedef enum
{
    MEA_1_HOUR   = 3600,    /*!< One hour */
    MEA_12_HOURS = 43200,   /*!< 12 hours */
    MEA_1_DAY    = 86400,   /*!< One day */
    MEA_1_WEEK   = 604800,  /*!< One week */
    MEA_1_YEAR   = 31449600 /*!< One year */
}MeaTimeDef;

/*! \typedef MeaSizeDef
 * 
 */
typedef enum
{
    MEA_1_KB   = 1024,
    MEA_10_KB  = 10240
}MeaSizeDef;

/******************************************************************************
 * Data-types
 *****************************************************************************/

/*!\struct MeaLinkItem
 * \brief A data-structure for creating a list of links.
 */
typedef struct MeaLinkItemSt
{
    char *url;                  /*!< The link */
    struct MeaLinkItemSt *next; /*!< The next item or NULL */
}MeaLinkItem;

/*!\enum MeaConfig
 * \brief Configuration data that the user can set 
 */
typedef struct
{
    MmsAddressType      addressType;        /*!< MMS_EMAIL or MMS_PLMN*/
    unsigned int        proxyPort;          /*!< The proxy port e.g. 80 */
    int                 networkAccount;     /*!< The network account no */
    MeaConnectionType   connectionType;   /*!< The connection type */
    int                 retrievalMode;      /*!< 0 == automatic, 1 == always ask */
    int                 retrievalModeRoam;  /*!< 0 == automatic, 1 == always ask
                                             2 == Restricted */
    unsigned int        securePort;
    unsigned int        httpPort;
    unsigned int        maxMsgSize;         /*!< Maximum message size for Imm Ret*/
    unsigned int        maxRetrSize;        /*!< Maximum retrieval size */

    char                *fromName;          /*!< The name of user */
    char                *fromAddress;       /*!< The address of the user EMAIL or 
                                           PLMN*/
    char                *proxyHost;         /*!< host.domain.net */
    char                *proxyUri;          /*!< The proxy URI e.g. /proxy-relay */
    char                *proxyScheme;       /*!< The proxy relay scheme e.g. 
                                            http:// */
    char                *wapGateway;        /*!< WAP gateway */
    char                *login;             /*!< Login name for the WAP gateway */
    char                *passwd;            /*!< Password for the login */
    char                *realm;             /*!< Needed when using a proxy that 
                                             needs authentication */
    MmsVersion          proxyVersion;       /*!< The MMSC version */

    /* Message settings */
    int                 saveOnSend;         /*!< 1=Save in sent fldr,0=Don't save*/
    int                 slideDuration;      /*!< Default slide duration in sec */
    MSF_BOOL            readReport;         /*!< Send read report ?? */
    MSF_BOOL            deliveryReport;     /*!< Send delivery report ??*/
    MeaPriorityType     priority;           /*!< Message priority */
    MeaExpiryTimeType   expiryTime;       /*!< The expiry date of the message */
    MeaReplyChargingType replyCharging;      /*!< Reply charging */
    MeaReplyChargingDeadlineType replyChargingDeadline; /*!< Reply charging deadline */
    MeaReplyChargingSizeType replyChargingSize;     /*!< Reply charging size */


    /* Immediate retrieval filters */
    int                 allowPersonal;      /*!< Allow class PERSONAL */
    int                 allowAdvert;        /*!< Allow class ADVERTISMENT */
    int                 allowInfo;          /*!< Allow class INFORMATIONAL */
    int                 allowAuto;          /*!< Allow class AUTO */
    int                 allowAnonym;        /*!< Allow anonymous senders */
    int                 treatAsDel;         /*!< Treat as delayed retrieval */
    char                *allowString;       /*!< Allow user defined string class */
    char                *imServer;          /*!< Immediate retrieval server */

    MeaVisibilityType   senderVisibility;   /*!< 1 == hide, 0 == show */
    MmsDeliveryReport   deliveryReportAllowed; /*!< See mms_def.h */
    int                 sendReadReport;     /*!< 2 == Never, 1 == On request, 
                                             0 == Always */
    int                 deliveryTime;       /*!< 3 == 24h, 2 == 12h, 1 == 1h, 
                                             0 == Immediate */

    /* Network Status variables */
    int                 roamingStatus;       /*! Roaming status,
                                             0 == not roaming, 1 == roaming */
    int                 bearerStatus;        /*! Bearer status, 
                                             0 == N/A, 1 == available */
#ifdef __MMS_DUAL_SIM_SUPPORT__
    int                 slaveNetworkAccount;     /*!< The network account no */
    MeaConnectionType   slaveConnectionType;   /*!< The connection type */
    int                 slaveRoamingStatus;       /*! Roaming status,
                                             0 == not roaming, 1 == roaming */
   
    int                 slaveBearerStatus;        /*! Bearer status, 
                                             0 == N/A, 1 == available */

    unsigned int        slaveProxyPort;          /*!< The proxy port e.g. 80 */                                                
    char                *slaveProxyHost;         /*!< host.domain.net */
    char                *slaveProxyUri;          /*!< The proxy URI e.g. /proxy-relay */
    char                *slaveProxyScheme;       /*!< The proxy relay scheme e.g. 
                                            http:// */
    MmsVersion          slaveProxyVersion;       /*!< The MMSC version */
    char                *slaveWapGateway;        /*!< WAP gateway */
    char                *slaveLogin;             /*!< Login name for the WAP gateway */
    char                *slavePasswd;            /*!< Password for the login */
    char                *slaveRealm;             /*!< Needed when using a proxy that 
                                             needs authentication */
    unsigned int        slaveSecurePort;
    unsigned int        slaveHttpPort;
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
                                             

    /* Compose setting: N/A: we keep them as static global */
} MeaConfig;

/*!\struct MeaAddrItem
 * \brief Data-structure for storing a destination address when creating 
 *        messages
 */
typedef struct MeaAddrItemSt
{
    MeaAddrType addrType;   /*!< The type of address, see #MeaAddrType */
    char *name;             /*!< The name of the dest user, e.g., 
                                 "Homer Simpson". UTF-8 is used for character 
                                 encoding. */
    char *address;          /*!< The address (according to #MeaAddrType) in 
                                 US-ASCII */
    struct MeaAddrItemSt *next; /*!< The next item */
}MeaAddrItem;

/*!\struct MeaMoFileRef
 * Data-structure for a media objects location */
typedef struct 
{
    char       *path;      /* !< Path to file */
#ifdef MMS_SLIM_MEM
    int filehandle;	
    MSF_UINT32 tmppos;        /* !< Position in file */
    MSF_UINT32 tmpsize;       /* !< Size of object in file */	
#endif /* MMS_SLIM_MEM */
    MSF_UINT32 pos;        /* !< Position in file */
    MSF_UINT32 size;       /* !< Size of object in file */
}MeaMoFileRef;

/*!\struct MeaMoDataItem 
 * Data-structure for one body part */
typedef struct MeaMoDataItemSt
{
    struct
    {
        MeaMediaType        type;       /* !< The type of data */
        MmsContentType      *origType;  /* !< The original content-type 
                                              including parameters, used when
                                              unknown content is present */
#ifdef __DRM_SUPPORT__ 
        MeaMediaType	  drmType;	/* when type is MEA_MEDIA_TYPE_DRM_MESSAGE/MEA_MEDIA_TYPE_DRM_CONTENT, drmType would be the real wrapped object type */
#endif
    }content;
    char                    *name;      /* !< The name of the body-part: with path */
    int                     bpIndex;    /* !< The index of the body-part in 
                                              the message */
    unsigned char           *data;      /* !< Body-part data */
    unsigned int            size;       /* !< Body-part size in bytes */
#ifdef MMS_SLIM_MEM
    unsigned char           acessType;  /* 0: mo data in one file, 1: mo data in memory, 3: mo data is one part of a file */
    unsigned int            bytesInBuf; /* */
    unsigned int            bufsize;    /* !< Body-part size in bytes */
    void 					*meaObjectReader;
    void 					*meaAsioReader;
    void 					*meaAsioWriter;
    int 					isWaitWidgetRead;
#endif
#ifdef WAP_SUPPORT
    char 					*savename;  /* !< The name of the body-part: without path */
    MSF_UINT32 				reshandle;
    MSF_BOOL                isRestricted;
#endif
    MeaMoFileRef            *file;      /* !< If allocated; MO location info */
    struct MeaMoDataItemSt  *next;      /* !< The next body-part or NULL */
}MeaMoDataItem;

/*!\struct MeaPropItem 
 * \brief Message properties 
 */
typedef struct
{
    MeaAddrItem *to;                /*!< To address */
    MeaAddrItem *cc;                /*!< Cc address */
    MeaAddrItem *bcc;               /*!< Bcc address */
    MeaAddrItem *from;              /*!< From address */
    char *subject;                  /*!< The message subject */
    MSF_BOOL readReport;            /*!< Read report ?? */
    MSF_BOOL deliveryReport;        /*!< Delivery report ??*/
    char *replyChargingId;          /*!< Reply charging id */
    MeaPriorityType priority;       /*!< Message priority */
    MeaExpiryTimeType expiryTime;   /*!< The expiry date of the message */
    MeaReplyChargingType replyCharging; /*!< Reply charging */
    MeaReplyChargingDeadlineType replyChargingDeadline; /*!< Reply charging
                                                             deadline */
    MeaReplyChargingSizeType replyChargingSize; /*!< Reply charging size */
    MeaVisibilityType senderVisibility;   /*!< 1 == hide, 0 == show */
}MeaPropItem;

/*! \struct MeaMoItem
 *
 */
typedef struct 
{
    MeaMoDataItem   *object;    /*!< A reference to the object */
    MSF_UINT32      textColor;  /*!< The text color */
    MSF_UINT32      bgColor;    /*!< The background color */
    MSF_UINT32      begin;      /*!< The object timing */
    MSF_UINT32      end;        /*!< The object timing */
}MeaObjInfo;

/*!\struct MeaSmilSlide
 * The representation for one slide 
 */
typedef struct MeaSmilSlideSt
{
    MeaObjInfo *objects[MEA_MAX_SMIL_OBJS]; /* !< The objects that are 
                                                  present in the slide */
    unsigned int duration;                  /* !< The slide duration */
    struct MeaSmilSlideSt *next;            /* !< The next slide or NULL */
}MeaSmilSlide;

/*!\struct MeaSmilInfo 
 * SMIL information 
 */
typedef struct
{
    MSF_UINT32      bgColor;        /* !< The background color for the SMIL 
                                          presentation */
    MeaSmilSlide    *currentSlide;  /* !< The slide that is currently active*/
    MeaObjInfo      *currentMo;     /* !< The media object that is active */
    
    MeaMoDataItem   *mediaObjects;  /* !< The list of media objects */
    unsigned int    noOfSlides;     /* !< The total number of slides */
    MeaSmilSlide    *slides;        /* !< The list of slides */
    MSF_UINT32      fgColorDefault;  /* !< The default color for text */
}MeaSmilInfo;

/*! \struct MeaCtContentInsert
 *  Used to start the ME FSM and insert content into a SMIL presentation
 */
typedef struct
{
    unsigned char   *buffer;    /*!< The buffer containing the image */
    MSF_UINT32      bufferSize; /*!< The size of the buffer */
    char            *name;      /*!< The name of the media object */
    MeaMediaType    mediaType;  /*!< The media type of the image */
    MeaPropItem     *propItem;  /*!< Message properties */

    /* MTK-added field */
    MSF_UINT32 resHandle;  /* resource handle for image/video/audio */
    MSF_BOOL isTruncated;  /* Imported text may be truncated */
}MeaCtContentInsert;

/*\struct Timers used by MEA */
typedef enum
{
    MEA_PM_TIMER_ID = 0x1,
    MEA_MOB_TIMER_ID,
    MEA_COMM_TIMER_ID,
    MEA_MH_CREATE_DEF_TEMP_TIMER_ID,
#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    MEA_MOB_TEXT_HEIGHT_TIMER_ID
#endif
} SmaTimer;

#ifdef WAP_SUPPORT
typedef struct attachmentObject
{
	MSF_UINT8 mimetype_mode; //0: unsigned char (ex:0x9D->image/gif), 1:str (ex:audio/midi)		
	MSF_UINT8 mimetype_cvalue;
	MSF_UINT8 *mimetype_svalue;	
	MSF_BOOL isTextObject;   //for text object, ex: text/x-vCard, text/x-vCalender
	MmsCharset charset;      //UTF-8,UTF-16,US_ASCII,UCS2
	MSF_UINT8 *filename;     //RFC 2047 encoded
	MSF_UINT8 *filepath;     
	struct attachmentObject *next;
}attachmentObjectList;
#endif
#endif

