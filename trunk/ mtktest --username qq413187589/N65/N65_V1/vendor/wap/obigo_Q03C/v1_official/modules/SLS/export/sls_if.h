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
/*! \file sls_if.h
 * \brief  SMIL service exported functions
 */

#ifndef _SLS_IF_H
#define _SLS_IF_H

#ifndef _SLS_CFG_H
#error You must first include sls_cfg.h
#endif
/*--- Macros ---*/

/* 
 * Used in SlsSizeValue to define the type of the value 
 */
#define SLS_ABS              0  /*!< Value is absolute */ 
#define SLS_REL              1  /*!< Value is relative */ 

/*! Max length for filename of a media object */
#define SLS_MAX_MO_FILE_NAME_LEN 16

/*! Used when setting colors for root-layout and text when no color needs to be
    set */
#define SLS_COLOR_NOT_USED      (0xFF000000)

/*--- Types ---*/

/*! \enum SlsResult Result values sent from the SMIL module. */
typedef enum
{
    /*! The operation is successful and finished. */
    SLS_RESULT_OK,

    /*! Too many consecutive calls to a API function has been made 
     *  without waiting for the outcome of the previous calls.
     */
    SLS_RESULT_BUSY,

    /*! The SMIL has not been created.
     */
    SLS_RESULT_SMIL_NOT_CREATED,

    /*! An unknown error has occurred. */
    SLS_RESULT_ERROR,

    /*! The slide has no media objects. */
    SLS_RESULT_MISSING_MEDIA_OBJECTS,

    /*! The media object has no src. */
    SLS_RESULT_MISSING_MEDIA_OBJECT_SRC,

    /*! The SMIL content is invalid. */
    SLS_RESULT_SMIL_INVALID,

    /*! Read file has been delayed, wait for MSF signal MSF_FILE_EVENT_READ. */
    SLS_RESULT_FILE_DELAY,

    /*! Could not read from the source file. */
    SLS_RESULT_FILE_READ_FAILURE,

    /*! The buffer was filled during file read operation */
    SLS_RESULT_BUFFER_FULL,

	/*! SMIL parsing failed, XML corrupt */
    SLS_RESULT_PARSING_FAILED,

	/*! The slide has no body part */
    SLS_RESULT_MISSING_BODY_PART,

	/*! The SMIL has to many slides */
    SLS_RESULT_TO_MANY_SLIDES

} SlsResult;

/*! \struct SlsValue
 *  \brief Defines a 'window' size use SLS_ABS or SLS_REL for type.
 */
typedef struct
{
    MSF_UINT16 value; /*!< The value */
    MSF_UINT16 type;  /*!< Absolute or relative (%) position*/
} SlsSizeValue;

/*! \struct SlsSize
 *  \brief This type is used for either size or position of windows.
 */
typedef struct
{
    SlsSizeValue  cx;     /*!< Horizontal size or position */
    SlsSizeValue  cy;     /*!< Vertical size or position   */
}SlsSize;

/*! \struct SlsRootLayout
 *  \brief This type is used to present the root layout data.
 */
typedef struct
{
    MSF_UINT32    bgColor;  /*!< The background color for the display */
    SlsSizeValue  cx;       /*!< Horizontal size or position */
    SlsSizeValue  cy;       /*!< Vertical size or position   */
}SlsRootLayout;

/*! \struct SlsFit
 *  \brief Value of <fit> attribute, described in W3C SMIL 2.0
 */
typedef enum
{
    SLS_ATTR_FILL	  = 0,	/*!< Scale object to touch the edges of the box */
    SLS_ATTR_HIDDEN	  = 1,	/*!< See W3C SMIL 2.0   */
	SLS_ATTR_MEET	  = 2,	/*!< See W3C SMIL 2.0   */
	SLS_ATTR_SCROLL	  = 3,	/*!< See W3C SMIL 2.0   */
	SLS_ATTR_SLICE	  = 4,	/*!< See W3C SMIL 2.0   */
	SLS_ATTR_NOT_USED = 5	/*!< See W3C SMIL 2.0   */
}SlsFit;

/*! \struct SlsRegion
 *  \brief Defines the layout for a region. 
 */
typedef struct
{
    SlsSize position;   /*!< Position from top/left		   */
    SlsSize size;       /*!< Size of region				   */
	SlsFit  fit;		/*!< fit attribute, used for image */
}SlsRegion;



/*
 *	!\brief List of unreferenced media objects in the SMIL message
 */
typedef struct SlsUnrefItemSt
{
	MSF_UINT32				size;           /*!< Size of the media object */	
	MSF_UINT32				offset;         /*!< Position in file */	
	SlsMediaType			mediaType;      /*!< Media type */	
	char					*fileName;      /*!< Name of media object */	
    char                    *contentType;   /*!< contentType of object */
	char					*boundary;      /*!< The boundary, used for DRM */
	struct SlsUnrefItemSt	*next;          /*!< Next attachment */	
}SlsUnrefItemList;


/*! \struct SlsTextMediaObject
 *  \brief  Contains information about a media object (MO).
 */
typedef struct
{
    SlsMediaType type;          /*!< Type of MO */	
    MSF_UINT32   size;          /*!< Size of MO in bytes */
    MSF_UINT32   offset;        /*!< Offset of MO in the MO data file */
    MSF_UINT32   charset;       /*!< Char-set of text */
	MSF_UINT32   color;			/*!< Text color */
    SlsRegion    region;        /*!< Positioning of the MO  */
	char		 *fileName;     /*!< FileName */
    char         *boundary;     /*!< The boundary, used for DRM */
    char         *mimeType;     /*!< The mimetype of the media object */
} SlsTextMediaObject;



/*! \struct SlsImageMediaObject
 *  \brief  Contains information about a media object (MO).
 */
typedef struct
{
    SlsMediaType type;          /*!< Type of MO */	
    MSF_UINT32   size;          /*!< Size of MO in bytes */
    MSF_UINT32   offset;        /*!< Offset of MO in the MO data file */
    SlsRegion    region;        /*!< Positioning of the MO  */

	char		 *fileName;     /*!< FileName */
	char		 *alt;	        /*!< alt param */
    char         *boundary;     /*!< The boundary, used for DRM */
    char         *mimeType;     /*!< The mimetype of the media object */
} SlsImageMediaObject;


/*! \struct SlsVideoMediaObject
 *  \brief  Contains information about a media object (MO).
 */
typedef struct
{
    SlsMediaType type;          /*!< Type of MO */	
    MSF_UINT32   size;          /*!< Size of MO in bytes */
    MSF_UINT32   offset;        /*!< Offset of MO in the MO data file */
    SlsRegion    region;        /*!< Positioning of the MO  */

	char		 *fileName;     /*!< FileName */
	char		 *alt;	        /*!< alt param */
    char         *boundary;     /*!< The boundary, used for DRM */
    char         *mimeType;     /*!< The mimetype of the media object */
} SlsVideoMediaObject;

/*! \struct SlsMediaAudioObject
 *  \brief  Contains information about a media object (MO).
 */
typedef struct
{
    SlsMediaType type;          /*!< Type of MO */	
    MSF_UINT32   size;          /*!< Size of MO in bytes */
    MSF_UINT32   offset;        /*!< Offset of MO in the MO data file */
	char		 *fileName;     /*!< FileName. */
	char		 *alt;	        /*!< alt param */
    char         *boundary;     /*!< The boundary, used for DRM */
    char         *mimeType;     /*!< The mimetype of the media object */
} SlsAudioMediaObject;

/*! \struct 
 *  \brief  Contains information about a slide
 */
typedef struct
{
    SlsTextMediaObject  text;       /*!< Text MO */
    SlsImageMediaObject image;      /*!< Image MO */
	SlsVideoMediaObject video;      /*!< Video MO */
    SlsAudioMediaObject audio;      /*!< Audio MO */
    MSF_UINT32          duration;   /*!< Slide duration */
} SlsSlideInfo;


/*! \struct SlsMediaObject
 *  \brief  Contains information about a media object (MO).
 * The strings region and src must be NULL terminated.
 */
typedef struct
{
    SlsMediaType    type;    /*!< Type of MO */
    char            *region; /*!< Name of the region to use for this MO  */
    char            *src;    /*!< Reference to the MO */
    MSF_UINT32      beginT;  /*!< The start-time, 0 if not used */
    MSF_UINT32      endT;    /*!< The stop-time, 0 if not used */
    MSF_UINT32      color;   /*!< Color - only used for text color at the time */
} SlsMediaObject;

/*! \struct 
 *  \brief Signal data for SLS_openSmil.
 */
typedef struct
{
    MSF_UINT32 msgId;   /*!< Message ID */
    MSF_UINT32 fileType;/*!< Message type (MMS_SUFFIX_SEND_REQ|MMS_SUFFIX_MSG */
} SlsOpenSmilReq;


/*! \struct 
 *  \brief  Signal data for SLS_openSmil response.
 */
typedef struct
{
    SlsResult     result;			/*!< Result of the operation */
    MSF_UINT8     noOfSlides;		/*!< Number of slides in the SMIL */
    SlsRootLayout rootLayout;		/*!< Window size on the originators device */
	SlsUnrefItemList *unrefItems;	/*!< Unreferenced items */
    char         *file;   /*!< MO data file, including path, NULL terminated */
} SlsOpenSmilRsp;

/*! \struct 
 *  \brief  Signal data for SLS_closeSmil response.
 */
typedef struct
{
    SlsResult result; /*!< Result of the operation */
} SlsCloseSmilRsp;

/*! \struct 
 *  \brief  Signal data for SlsGetSlideInfo.
 */
typedef struct
{
    MSF_UINT8    slideNo; /*!< What slide */
} SlsGetSlideInfoReq;

/*! \struct 
 *  \brief  Signal data for SlsGetSlideInfo response.
 */
typedef struct
{
    SlsResult     result;    /*!< Result of the operation */
    SlsSlideInfo  slideInfo; /*!< Information about the slide */
} SlsGetSlideInfoRsp;


/*!
 *  \brief  Handle used internally by SLS during SMIL creation.
 */
typedef void* SlsCreateSmilHandle;

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Signals ---*/

/*!
 * \brief Request signal for SLS_openSmil()
 * Data type: SlsOpenSmilReq
 * 
 *****************************************************************************/
#define SLS_OPEN_SMIL_REQ       ((MSF_MODID_SLS << 8) + 0x01)

/*!
 * \brief Response signal for SLS_openSmil()
 * Data type: SlsOpenSmilRsp
 * 
 *****************************************************************************/
#define SLS_OPEN_SMIL_RSP       ((MSF_MODID_SLS << 8) + 0x02)

/*!
 * \brief Request signal for SLS_closeSmil()
 * Data type: SlsCloseSmilReq
 * 
 *****************************************************************************/
#define SLS_CLOSE_SMIL_REQ      ((MSF_MODID_SLS << 8) + 0x03)

/*!
 * \brief Response signal for SLS_closeSmil()
 * Data type: SlsCloseSmilRsp
 * 
 *****************************************************************************/
#define SLS_CLOSE_SMIL_RSP      ((MSF_MODID_SLS << 8) + 0x04)

/*!
 * \brief Request signal for SLS_getSlideInfo()
 * Data type: SlsGetSlideInfoReq
 * 
 *****************************************************************************/
#define SLS_GET_SLIDE_INFO_REQ  ((MSF_MODID_SLS << 8) + 0x05)

/*!
 * \brief Response signal for SLS_getSlideInfo()
 * Data type: SlsGetSlideInfoRsp
 * 
 *****************************************************************************/
#define SLS_GET_SLIDE_INFO_RSP  ((MSF_MODID_SLS << 8) + 0x06)


/*--- Definitions/Declarations ---*/

/*!
 * \brief Starts the SLS API, must be called before any other calls.
 * 
 *****************************************************************************/
SlsResult SLSif_startInterface(void);

/*!
 * \brief Opens a MMS message and parses the SMIL part. 
 * The method is asynchronous and the response is received in 
 * the signal SLS_OPEN_SMIL_RSP.
 * 
 * \param modId Module ID of the calling module
 * \param msgId Message ID of the message to be opened
 * \param fileType Type of message (MMS_SUFFIX_SEND_REQ|MMS_SUFFIX_MSG)
 * \return Result code
 *****************************************************************************/
SlsResult SLSif_openSmil(MSF_UINT8 sender, MSF_UINT32 msgId, 
    MSF_UINT32 fileType);

/*!
 * \brief This method deallocates the resources from a previous call 
 * to SLS_openSmil. 
 * The method is asynchronous and the response is received in the
 * signal SLS_CLOSE_SMIL_RSP.
 * 
 * \param modId Module ID of the calling module
 * \return Result code
 *****************************************************************************/
SlsResult SLSif_closeSmil(MSF_UINT8 modId);

/*!
 * \brief Gets information about a given slide. 
 * The method is asynchronous and the response is received in the 
 * signal SLS_GET_SLIDE_INFO_RSP
 * 
 * \param modId Module ID of the calling module
 * \param slideNo The slide to get information about
 * \return Result code
 *****************************************************************************/
SlsResult SLSif_getSlideInfo(MSF_UINT8 modId, MSF_UINT8 slideNo);

/*!
 * \brief Opens the message file and prepares for reading data.
 * This function must be called before the first call to SLS_getMediaObject.
 * 
 * \param modId Module id of the calling module 
 * \param fileHandle File handle to set
 * \param msgId Message id for the message that contains the media object
 * \param fileType Type of message (MMS_SUFFIX_SEND_REQ|MMS_SUFFIX_MSG)
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_startGetMediaObject(MSF_UINT8 modId, MSF_INT32 *fileHandle, 
    MSF_UINT32 msgId, MSF_UINT32  fileType);

/*!
 * \brief Close the message file.
 * This function must be called after the last call to SLS_getMediaObject.
 * 
 * 
 * \param fileHandle Handle to file to close
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_stopGetMediaObject(MSF_INT32 fileHandle);

/*!
 * \brief Gets media object data.
 * Several calls to this function might be used to get all media object data.
 * The result code tells if another call must be used:
 *   SLS_RESULT_OK - All data is read and the operation i complete.
 *   MSF_FILE_ERROR_DELAYED - Operation is postponed, wait for signal
 *                          MSF_FILE_EVENT_READ and call SLS_getMediaObject 
 *                          again after receiving this signal.
 *   SLS_RESULT_FILE_READ_FAILURE - Operation has failed.
 * 
 *
 * \param moSize Total size of media object to get
 * \param offset Offset in file where to get media object
 * \param data  Buffer where to store media object
 * \param dataSize IN: size of data buffer OUT: size read.
 * \prarm totalRead Size of media object that has been read
 * \param fileHandle handle to file containing media object
 * \return Result code
 *****************************************************************************/
SlsResult  SLSlib_getMediaObject(MSF_UINT32 moSize, MSF_UINT32 offset,
    unsigned char *data, MSF_UINT32 *dataSize, MSF_UINT32 *totalRead,
    MSF_INT32 fileHandle);

/*!
 * \brief Creates a new SMIL message
 * 
 * \param modId Module id of the calling module
 * \param rootLayout Root layout (window size) for the new message
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_createSmil(MSF_UINT8 modId, SlsCreateSmilHandle *handle,
    const SlsRootLayout *rootlayout);

/*!
 * \brief Creates a new region
 * 
 * \param modId Module id of the calling module
 * \param region Size and position of the region
 * \param name Name of the region
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_createRegion(MSF_UINT8 modId, 
    const SlsCreateSmilHandle *handle, const SlsRegion *region,
    const char *name);

/*!
 * \brief Cancels the creation of a smil message and frees all
 *  resources
 * 
 * \param modId Module id of the calling module 
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_cancelCreateSmil(MSF_UINT8 modId,
    const SlsCreateSmilHandle *handle);

/*!
 * \brief Creates a new slide to the SMIL message
 * 
 * \param modId Module id of the calling module 
 * \param duration Slide duration in seconds
 * \param text Text MO, NULL if not used
 * \param image Image MO, NULL if not used
 * \param video Video MO, NULL if not used
 * \param audio Audio MO, NULL if not used
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_createSlide(MSF_UINT8  modId,
    const SlsCreateSmilHandle *handle, MSF_INT32 duration,
    const SlsMediaObject *text, const SlsMediaObject *image,
    const SlsMediaObject *video, const SlsMediaObject *audio);  

/*!
 * \brief Generates a SMIL message and frees all used resources
 * The buffer is allocated in the function and the caller is responsible 
 * for deallocating the buffer.
 * 
 * \param modId Module id of the calling module 
 * \param buffer Pointer to the data buffer
 * \return Result code
 *****************************************************************************/
SlsResult SLSlib_generateSmil(MSF_UINT8 modId,
    const SlsCreateSmilHandle *handle, char **buffer);

/*!
 * \brief Converts a serialized signal buffer into signal struct
 * The function is called from MSF when signals is to be converted.
 * 
 * \param modId The calling module identity
 * \param signal Signal identity
 * \param buffer The signal buffer
 *****************************************************************************/
void *SLS_convert(MSF_UINT8 modId, MSF_UINT16 signal, void *buffer);

/*!
 * \brief Deallocate a signal buffer
 *
 * This function is used by the MSF to free signal memory.
 *
 * Type: Function call
 *
 * \param modId The calling module identity
 * \param signal Signal identity
 * \param p The signal buffer
 *****************************************************************************/
void SLS_destruct(MSF_UINT8 modId, MSF_UINT16 signal, void* p);


#endif /* _SLS_IF_H */


