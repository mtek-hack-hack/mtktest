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

#ifndef _SATYPES_H
#define _SATYPES_H


#ifndef _SLS_IF_H
#error sls_if.h must be included berfore satypes.h!
#endif

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*\struct Timers used by SMA */
typedef enum
{
    SMA_SLIDE_TIMER_ID = 1,
    SMA_DIALOG_TIMER_ID,
    SMA_ACTION_IMAGE_TIMER_ID,
    SMA_GET_TOTAL_TEXT_HEIGHT_TIMER_ID
} SmaTimer;

/*! \struct SmaSizeValue
 *  \brief Defines a 'window' size use SLS_ABS or SLS_REL for type.
 */
typedef struct
{
    MSF_UINT16 value; /*!< The value */
    MSF_UINT16 type;  /*!< Absolute or relative (%) position*/
} SmaSizeValue;

/*! \struct SmaSize
 *  \brief This type is used for either size or position of windows.
 */
typedef struct
{
    SmaSizeValue  cx;     /*!< Horizontal size or position */
    SmaSizeValue  cy;     /*!< Vertical size or position   */
}SmaSize;

/*! \struct SmaFit
 *  \brief Value of <fit> attribute, described in W3C SMIL 2.0
 */
typedef enum
{
    SMA_ATTR_FILL	  = 0,	/*!< Scale object to touch the edges of the box */
    SMA_ATTR_HIDDEN	  = 1,	/*!< See W3C SMIL 2.0   */
	SMA_ATTR_MEET	  = 2,	/*!< See W3C SMIL 2.0   */
	SMA_ATTR_SCROLL	  = 3,	/*!< See W3C SMIL 2.0   */
	SMA_ATTR_SLICE	  = 4,	/*!< See W3C SMIL 2.0   */
	SMA_ATTR_NOT_USED = 5	/*!< See W3C SMIL 2.0   */
}SmaFit;


/*! \struct SmaRegion
 *  \brief Defines the layout for a region. 
 */
typedef struct
{
    SmaSize position;   /*!< Position from top/left */
    SmaSize size;       /*!< Size of region         */
	SmaFit	fit;		/*!< fit attribute, used for image */
}SmaRegion;



/* \struct SmaRootSize size of the source device display */
typedef struct
{
    MSF_UINT16 width;
    MSF_UINT16 height;
} SmaRootSize;

/* \struct SmaData containing text, image and audio object*/
typedef struct
{
    MSF_UINT32          noOfRetries;/*!< Number of retries */
    MSF_UINT32          sizeRead;   /*!< size of data in buffer */ 
    MSF_UINT32          totalRead;  /*!< total size read */
    MSF_UINT32          bufferSize; /*!< Size of buffer */ 
    char                *buffer;    /*!< buffer containing object data*/ 
} SmaData;

/* \struct SmaImageObject information about an image object */
typedef struct
{
    SlsMediaType    type;
#ifdef __DRM_SUPPORT__
    SlsMediaType    drmType;  /* when type is SLS_DRM_MESSAGE/SLS_DRM_CONTENT, drmType would be the real wrapped object type */
#endif
    MSF_UINT32      size;
    MSF_UINT32      offset;
    SmaRegion       region;
    MSF_UINT32		bgColor;
    char			*alt;
} SmaImageObject;

/* \struct SmaAudioObject information about an image object */
typedef struct
{
    SlsMediaType    type;
#ifdef __DRM_SUPPORT__ 
    SlsMediaType    drmType;  /* when type is SLS_DRM_MESSAGE/SLS_DRM_CONTENT, drmType would be the real wrapped object type */
#endif
    MSF_UINT32      offset; 
    MSF_UINT32      size;
    MSF_UINT32		bgColor;
    char			*alt;
} SmaAudioObject;

/*!\struct SmaLinkItem
 * \brief A data-structure for creating a list of links.
 */
typedef struct SmaLinkItemSt
{
    char *url;                  /*!< The link */
    struct SmaLinkItemSt *next; /*!< The next item or NULL */
}SmaLinkItem;

/* \struct SmaAudioObject information about an image object */
typedef struct
{
    SlsMediaType    type;
    MSF_UINT32      size;
    MSF_UINT32      offset;
    MSF_UINT32      charset;
	MSF_UINT32		textColor;
    MSF_UINT32		bgColor;
    SmaRegion       region;
    SmaLinkItem     *links;  /*!< The links of the current slide */
} SmaTextObject;

/* \struct SmaObjectInfo containing text, image and audio object*/
typedef struct StructSmaObjectInfo
{
    SlsMediaObjectType   type;
    union
    {
        SmaImageObject  image;
		SmaImageObject  video;
        SmaAudioObject  audio;
        SmaTextObject   text;
    } info;
	char        *fileName;

    char        *boundary;
    MSF_UINT32  offset;
    MSF_BOOL    isDrm;
    struct StructSmaObjectInfo  *next;
} SmaObjectInfo;

/* \struct SmaSlide containing information about a slide. */
typedef struct StructSmaSlideInfo
{
    SmaObjectInfo               object;
    MSF_UINT32                  displayTime;
    MSF_UINT32					bgColor;
	struct StructSmaSlideInfo   *next;
}SmaSlideInfo;

/* \struct SmaPlayerInfo Static information */
typedef struct
{
    /* player information */
    MSF_UINT32      msgId;          /*!< message id containing the SMIL */
    MSF_UINT32      fileType;       /*!< file type */
#ifdef __UNIFIED_MSG_SUPPORT__
    MSF_UINT32      folder;  /* MmsFolderType */
    MSF_UINT32      recipientNo;
    MSF_BOOL    forwardLock;
#endif
    char            *filePath;      /*!< full path and file name */
    MSF_UINT8       sourceModule;   /*!< source module that requested to play a SMIL */
    MSF_BOOL        isPlaying;      /*!< is the state-machine in play mode or not*/
    MSF_BOOL        slsIsRunning;      /*!< Set to TRUE when initialized, else FALSE*/
#ifdef __UNIFIED_MESSAGE_MMS_MANUAL_PLAY__
    MSF_BOOL		isAutoplay;
#endif
    
    /* display and device information */
    SmaRootSize     rootSize;       /*!< size of the source device display */
	MSF_UINT32		rootBgColor;	/*!< default bgColor for whole slide show */

    /* SMIL information */
    MSF_UINT8       noOfSlides;     /*!< number of slides in current SMIL */
    MSF_UINT8       currentSlide;   /*!< current slide shown */
    SmaSlideInfo    slideInfo;      /*!< information about the SMIL */

	/* unreferenced attachments */
	MSF_BOOL			isNotified;	/*!< Is the attachment list shown */
	SlsUnrefItemList	*unrefList;	/*!< List of attachments */	

    /*! Used to hold data when reading displaying a media object */
    SmaData         data;
    MSF_UINT32      state;
	
	SlsResult     result;			/*!< Result of the operation */
} SmaPlayerInfo;

/* \struct SmaMediaTypeItem
 * \brief Used for defining a information needed for a media object.
 *
 */
typedef struct 
{
    const SlsMediaType          slsMediaType;   /*!< The media type, see 
                                                     #SlsMediaType */
    union
    {
        const MsfImageFormat    image;          /*!< The Msf image type */
        const MsfSoundFormat    audio;          /*!< The Msf audio type */
        const MsfVideoFormat    video;          /*!< The Msf video type */
    }msfFormat;
    SlsMediaObjectType          slsObjectType;  /*!< The type of object, see 
                                                     #SlsMediaObjectType*/
    const char                  *mimeType;         /*!< The mime-type */
}SmaMediaTypeItem;

/* \struct SmaMediaTypeItem
 * \brief Used for defining a information needed for a media object.
 *
 */
typedef struct 
{
    const char          *mimeType;      /*!< The mime-type */
    const char          *ending;        /*!< The file ending */
}SmaAttachmentTypeItem;


/*! \struct SmaDreResultItem
 *  \brief Used to transport data from the package handler to calling FSM's
 */
typedef struct 
{
    char *httpHeader;    /*!< The HTTP header provided to the object */
    char *drmRights;     /*!< The DRE rights associated with a DRM object */
}SmaDreResultItem;

/*! \enum SmaCharset Supported character sets within the smil module. */
typedef enum
{
    SMA_US_ASCII    = 3,   
    SMA_UTF8        = 106,
    SMA_USC2        = 1000,
    SMA_UTF16BE     = 1013, 
    SMA_UTF16LE     = 1014, 
    SMA_UTF16       = 1015, 
    SMA_GB2312      = 2025, 
    SMA_ISO_8859_1  = 4,
    SMA_UNKNOWN_CHARSET = 0
} SmaCharset;

/*********************************************
 * Exported function
 *********************************************/

#endif /* _SATYPES_H */


