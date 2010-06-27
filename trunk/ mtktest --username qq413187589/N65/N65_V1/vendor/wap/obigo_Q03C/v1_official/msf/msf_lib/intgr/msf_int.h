/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_int.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msf_int_h
#define _msf_int_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif


/**********************************************************************
 * Messaging
 **********************************************************************/

#define HDI_SIGNAL_OK                    0
#define HDI_SIGNAL_ERROR_QUEUE_FULL     -1
#define HDI_SIGNAL_ERROR_QUEUE_UNKNOWN  -2

void
HDIa_signalRegisterQueue (MSF_UINT8 modId);

void
HDIa_signalDeregisterQueue (MSF_UINT8 modId);

void*
HDIa_signalAllocMemory (MSF_UINT16 signalLength);

void
HDIa_signalFreeMemory (void* signalData);

int
HDIa_signalSend (MSF_UINT8 destModId, void* signalData, MSF_UINT16 signalDataLength);

void*
HDIa_signalRetrieve (MSF_UINT8 destModId);

int
HDIa_signalQueueLength (MSF_UINT8 modId);


/**********************************************************************
 * Named Pipes
 **********************************************************************/

/* Notification types */
#define HDI_PIPE_EVENT_CLOSED                     1
#define HDI_PIPE_EVENT_READ                       2
#define HDI_PIPE_EVENT_WRITE                      3

#ifdef NEW_PIPE_ERROR_EVENT
#define HDI_PIPE_EVENT_CLOSED_ERROR               4
#endif

/* Error codes */
#define HDI_PIPE_ERROR_BAD_HANDLE                 -1
#define HDI_PIPE_ERROR_INVALID_PARAM              -2
#define HDI_PIPE_ERROR_EXISTS                     -3
#define HDI_PIPE_ERROR_IS_OPEN                    -4
#define HDI_PIPE_ERROR_DELAYED                    -5
#define HDI_PIPE_ERROR_RESOURCE_LIMIT             -6
#define HDI_PIPE_ERROR_CLOSED                     -7
#define HDI_PIPE_ERROR_NOT_FOUND                  -8

#ifdef NEW_PIPE_ERROR_EVENT
#define HDI_PIPE_ERROR_CLOSED_ERROR               -9
#endif

int
HDIa_pipeCreate (MSF_UINT8 modId, const char* name);

int
HDIa_pipeOpen (MSF_UINT8 modId, const char *name);

int
HDIa_pipeClose (int handle);

#ifdef NEW_PIPE_ERROR_EVENT
int
HDIa_pipeCloseError (int handle);
#endif

int
HDIa_pipeDelete (const char* name);

long
HDIa_pipeRead (int handle, void* buf, long bufSize);

long
HDIa_pipeWrite (int handle, void* buf, long bufSize);

int
HDIa_pipePoll (int handle);

int
HDIa_pipeStatus (int handle, int *isOpen, long *available);

void
HDIa_pipeCloseAll (MSF_UINT8 modId);


/**********************************************************************
 * File
 **********************************************************************/

#define HDI_FILE_SET_RDONLY      1
#define HDI_FILE_SET_WRONLY      2
#define HDI_FILE_SET_RDWR        4
#define HDI_FILE_SET_APPEND      8  
#define HDI_FILE_SET_CREATE      16
#define HDI_FILE_SET_EXCL        32
#define HDI_FILE_SET_BUFFERED    64

#define HDI_FILE_SEEK_SET        1
#define HDI_FILE_SEEK_CUR        2
#define HDI_FILE_SEEK_END        3

#define HDI_FILE_DIRTYPE         1
#define HDI_FILE_FILETYPE        2

#define HDI_FILE_EVENT_READ      1
#define HDI_FILE_EVENT_WRITE     2

#define HDI_FILE_READ_READY      1
#define HDI_FILE_WRITE_READY     2

#define HDI_FILE_OK              0
#define HDI_FILE_ERROR_ACCESS   -1
#define HDI_FILE_ERROR_DELAYED  -2
#define HDI_FILE_ERROR_PATH     -3
#define HDI_FILE_ERROR_INVALID  -4
#define HDI_FILE_ERROR_SIZE     -5
#define HDI_FILE_ERROR_FULL     -6
#define HDI_FILE_ERROR_EOF      -7
#define HDI_FILE_ERROR_EXIST    -8

int
HDIa_fileOpen (MSF_UINT8 modId, const char* fileName, int mode, long size);

int
HDIa_fileClose (int fileHandle);

long
HDIa_fileWrite (int fileHandle, void* data, long size);

long
HDIa_fileRead (int fileHandle, void* data, long size);

void
HDIa_fileFlush (int fileHandle);

long
HDIa_fileSeek (int fileHandle, long offset, int seekMode);

int
HDIa_fileRemove (const char* fileName);

int
HDIa_fileRename (const char *srcName, const char *dstName);

int
HDIa_fileMkDir (const char* dirName);

int
HDIa_fileRmDir (const char* dirName);

int
HDIa_fileGetSizeDir(const char *dirName);

int
HDIa_fileReadDir (const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size);

int
HDIa_fileReadDirLong (const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, long *size);

#ifdef MSF_USE_FILE_READ_DIR_SEQ
int
HDIa_fileReadDirSeq(const char *dirName, int pos, char *nameBuf, int nameBufLength, int *type, int *size,int *dirHandle);
	
void 
HDIa_fileReadDirSeqClose(int *dirHandle);
#endif /* MSF_USE_FILE_READ_DIR_SEQ*/

void 
HDIa_fileSelect(int fileHandle, int eventType);

long
HDIa_fileSetSize (int fileHandle, long size);

long
HDIa_fileGetSize (const char* fileName);

void
HDIa_fileCloseAll (MSF_UINT8 modId);

/**********************************************************************
 * Time
 **********************************************************************/

#define HDI_TIME_ZONE_UNKNOWN       9999

MSF_UINT32
HDIa_timeGetCurrent (void);

MSF_INT16
HDIa_timeGetTimeZone (void);

MSF_UINT32
HDIa_timeSecureClock (void);

/**********************************************************************
 * Sockets
 **********************************************************************/

/* Socket types */
#define HDI_SOCKET_TYPE_UDP                       1
#define HDI_SOCKET_TYPE_TCP                       2
#define HDI_SOCKET_TYPE_SMS_DATA                  3
#define HDI_SOCKET_TYPE_SMS_RAW                   4

/* Bearers */
#define HDI_SOCKET_BEARER_IP_ANY                  0
#define HDI_SOCKET_BEARER_GSM_SMS                 3
#define HDI_SOCKET_BEARER_GSM_CSD                 10
#define HDI_SOCKET_BEARER_GSM_GPRS                11
#define HDI_SOCKET_BEARER_WIFI                    12
#define HDI_SOCKET_BEARER_BT                      150
#define HDI_SOCKET_BEARER_ANY                     255

/* Notification types */
#define HDI_SOCKET_EVENT_ACCEPT                   1
#define HDI_SOCKET_EVENT_CLOSED                   2
#define HDI_SOCKET_EVENT_CONNECTED                3
#define HDI_SOCKET_EVENT_RECV                     4
#define HDI_SOCKET_EVENT_SEND                     5

#define HDI_SOCKET_ERROR_BAD_ID                   -1
#define HDI_SOCKET_ERROR_INVALID_PARAM            -2
#define HDI_SOCKET_ERROR_MSG_SIZE                 -3
#define HDI_SOCKET_ERROR_DELAYED                  -4
#define HDI_SOCKET_ERROR_RESOURCE_LIMIT           -5
#define HDI_SOCKET_ERROR_CONNECTION_FAILED        -6
#define HDI_SOCKET_ERROR_HOST_NOT_FOUND           -7
#define HDI_SOCKET_ERROR_CLOSED                   -8


/* Address Type */
typedef struct {
  MSF_INT16     addrLen;
  unsigned char addr[16];   /* Enough for IPv6 */
  MSF_UINT16    port;
} msf_sockaddr_t;


int
HDIa_socketCreate (MSF_UINT8 modId, int socketType, MSF_INT32 networkAccountID);

int
HDIa_socketClose (int socketId);

int
HDIa_socketAccept (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketBind (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketConnect (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketGetName (int socketId, msf_sockaddr_t *addr);

int
HDIa_socketListen (int socketId);

long
HDIa_socketRecv (int socketId, void *buf, long bufLen);

long
HDIa_socketRecvFrom (int socketId, void *buf, long bufLen, msf_sockaddr_t *fromAddr);

long
HDIa_socketSend (int socketId, void *data, long dataLen);

long
HDIa_socketSendTo (int socketId, void *data, long dataLen, msf_sockaddr_t *toAddr);

int
HDIa_socketSelect (int socketId, int eventType);

void
HDIa_socketCloseAll (MSF_UINT8 modId);

void
HDIa_socketGetHostByName (MSF_UINT8 modId, int requestId, const char *domainName);

void
HDIa_socketGetHostByNameNId (MSF_UINT8 modId, int requestId, const char *domainName, MSF_INT32 networkAccountID);

/**********************************************************************
 * Network Account
 **********************************************************************/

#define HDI_NETWORK_ACCOUNT_ERROR_BAD_ID -1
#define HDI_NETWORK_ACCOUNT_ERROR_NO_MORE_ID -2
#define HDI_NETWORK_ACCOUNT_ERROR_BEARER_NOT_FOUND -3

int
HDIa_networkAccountGetBearer(MSF_INT32 networkAccountId);

int
HDIa_networkAccountGetName(MSF_INT32 networkAccountId, char *buf, int bufLen);

MSF_INT32
HDIa_networkAccountGetFirst(void);

MSF_INT32
HDIa_networkAccountGetNext(MSF_INT32 networkAccountId);

MSF_INT32
HDIa_networkAccountGetId(int bearer);


/**********************************************************************
 * Telephone
 **********************************************************************/

/* Result types */
#define HDI_TEL_OK                            0
#define HDI_TEL_ERROR_UNSPECIFIED             -1
#define HDI_TEL_ERROR_CALLED_PARTY_IS_BUSY    -105
#define HDI_TEL_ERROR_NETWORK_NOT_AVAILABLE   -106
#define HDI_TEL_ERROR_CALLED_PARTY_NO_ANSWER  -107
#define HDI_TEL_ERROR_NO_ACTIVE_CONNECTION    -108
#define HDI_TEL_ERROR_INVALID                 -200

void
HDIa_telMakeCall (MSF_UINT8 modId, MSF_UINT16 telId, const char* number);

void
HDIa_telSendDtmf (MSF_UINT8 modId, MSF_UINT16 telId, const char* dtmf);


/**********************************************************************
 * Phonebook
 **********************************************************************/

/* Result types */
#define HDI_PB_OK                             0
#define HDI_PB_ERROR_UNSPECIFIED              -1
#define HDI_PB_ERROR_IN_NAME                  -100
#define HDI_PB_ERROR_NUMBER_TO_LONG           -102
#define HDI_PB_ERROR_PHONE_BOOK_ENTRY         -103
#define HDI_PB_ERROR_PHONE_BOOK_IS_FULL       -104
#define HDI_PB_ERROR_INVALID                  -200

void
HDIa_pbAddEntry (MSF_UINT8 modId, MSF_UINT16 pbId, const char* name, const char* number);

 
 /**********************************************************************
 * Logging
 **********************************************************************/

#define HDI_LOG_TYPE_DETAILED_LOW       0
#define HDI_LOG_TYPE_DETAILED_MEDIUM    1
#define HDI_LOG_TYPE_DETAILED_HIGH      2
#define HDI_LOG_TYPE_MEMORY             3

void
HDIa_logTrace (int type, MSF_UINT8 modId, int msgId, char *format, ...);

void
HDIa_logMsg (int type, MSF_UINT8 modId, const char *format, ...);

void
HDIa_logData (int type, MSF_UINT8 modId, const unsigned char *data, int dataLen);

void
HDIa_logSignal (MSF_UINT8 srcModId, MSF_UINT8 dstModId, const char *data);


/**********************************************************************
 * Widget
 **********************************************************************/
#define MsfScreenHandle     MSF_UINT32
#define MsfWindowHandle     MSF_UINT32
#define MsfGadgetHandle     MSF_UINT32
#define MsfActionHandle     MSF_UINT32
#define MsfImageHandle      MSF_UINT32
#define MsfStringHandle     MSF_UINT32
#define MsfFontFamilyNumber MSF_UINT32

#define MsfIconHandle       MSF_UINT32
#define MsfSoundHandle      MSF_UINT32
#define MsfMoveHandle       MSF_UINT32
#define MsfRotationHandle   MSF_UINT32
#define MsfColorAnimHandle  MSF_UINT32
#define MsfStyleHandle      MSF_UINT32
#define MsfBrushHandle      MSF_UINT32
#define MsfAccessKeyHandle  MSF_UINT32

#define HDI_WIDGET_ERROR_UNEXPECTED    -1
#define HDI_WIDGET_ERROR_NOT_SUPPORTED -2

typedef struct {
  MSF_INT16 x;
  MSF_INT16 y;
}MsfPosition;


typedef struct {
  MSF_INT16 height;
  MSF_INT16 width;
} MsfSize;

typedef enum {
  MsfHigh = 0,
  MsfMiddle = 1,
  MsfLow = 2,
  MsfVerticalPosDefault = 3
} MsfVerticalPos;

typedef enum {
  MsfLeft = 0,
  MsfCenter = 1,
  MsfRight = 2,
  MsfHorizontalPosDefault = 3
} MsfHorizontalPos;

typedef struct {
  MsfVerticalPos verticalPos;
  MsfHorizontalPos horisontalPos;
}MsfAlignment;



typedef struct {
  MsfSize displaySize;
  int isTouchScreen;
  int hasDragAbility;
  int isColorDisplay;
  int numberOfColors;
  MSF_INT32 supportedMsfEvents; /*Deprecated*/
} MsfDeviceProperties;

typedef enum {
  MsfBack = 0,
  MsfCancel = 1,
  MsfExit = 2,
  MsfHelp = 3,
  MsfOk = 4,
  MsfMenu = 5,
  MsfStop = 6,
  MsfSelect = 7
} MsfActionType;

typedef enum {
  MsfImplicitChoice = 0,
  MsfExclusiveChoice = 1,
  MsfMultipleChoice = 2,
  MsfExclusiveChoiceDropDown = 3
} MsfChoiceType;


#define MSF_CHOICE_ELEMENT_SELECTED   0x01
#define MSF_CHOICE_ELEMENT_DISABLED   0x02
#define MSF_CHOICE_ELEMENT_FOCUSED    0x04 


typedef struct {
  int iconPos;
  int indexPos;
  int string1Pos;
  int string2Pos;
  int image1Pos;
  int image2Pos;
} MsfElementPosition;

typedef enum {
  MsfAlert    = 0,
  MsfConfirmation = 1,
  MsfWarning    = 2,
  MsfInfo     = 3,
  MsfError    = 4,
  MsfPrompt   = 5
} MsfDialogType;

typedef enum {
MsfInteractiveBar = 0,
MsfProgressBar = 1,
MsfVerticalScrollBar = 2,
MsfHorizontalScrollBar = 3
} MsfBarType ;

typedef enum {
   MsfTimeType = 0,
   MsfDateType = 1,
   MsfDateTime = 2
} MsfDateTimeType;

typedef enum {
  MsfText = 0,
  MsfName = 1,
  MsfIpAddress = 2,
  MsfUrl = 3,
  MsfEmailAddress = 4,
  MsfPhoneNumber = 5,
  MsfNumeric = 6,
  MsfNumber = 7,
  MsfInteger = 8,
  MsfPasswordText = 9,
  MsfPasswordNumber = 10,
  MsfPredictive = 11,
  MsfFile = 12,
  MsfFilePath = 13,
  MsfNoTextType = 14
} MsfTextType;

typedef struct {
  int day;
  int month;
  int year;
} MsfDate;

typedef struct {
  int hours;
  int minutes;
  int seconds;
} MsfTime;


typedef enum {
  MsfButton = 0,
  MsfButtonPressed = 1,
  MsfRadioButton = 2,
  MsfRadioButtonPressed = 3,
  MsfCheckBox = 4, 
  MsfCheckBoxChecked = 5, 
  MsfKey = 6,
  MsfBullet = 7,
  MsfTick = 8,
  MsfSquare = 9,
  MsfCircle = 10,
  MsfDisk = 11,
  MsfArrowHead = 12,
  MsfIcon1 = 13,
  MsfIcon2 = 14,
  MsfIcon3 = 15,
  MsfIcon4 = 16
} MsfIconType;

typedef enum {
  MsfPress = 0,
  MsfRelease = 1,
  MsfRepeat = 2
}MsfEventClass;

typedef enum {
  MsfKey_0 = 0, MsfKey_1 = 1, MsfKey_2 = 2, MsfKey_3 = 3, MsfKey_4 = 4,
  MsfKey_5 = 5, MsfKey_6 = 6, MsfKey_7 = 7, MsfKey_8 = 8, MsfKey_9 = 9, 
  MsfKey_Star = 10, MsfKey_Pound = 11, MsfKey_Up = 12, MsfKey_Down = 13, 
  MsfKey_Left = 14, MsfKey_Right = 15, MsfKey_Select = 16,
  MsfKey_Clear = 17, MsfKey_Yes = 18, MsfKey_No = 19, MsfKey_Menu = 20,
  MsfKey_Soft1 = 21, MsfKey_Soft2 = 22, MsfKey_Soft3 = 23,
  MsfKey_Soft4 = 24, MsfKey_Function1 = 25, MsfKey_Function2 = 26,
  MsfKey_Function3 = 27, MsfKey_Function4 = 28, MsfPointer = 29,
  MsfKey_Undefined = 30, MsfKey_PageUp = 31, MsfKey_PageDown = 32 
} MsfEventType;

#define MSF_EVENT_MODE_SHIFT      0x01
#define MSF_EVENT_MODE_ALT	      0x02 
#define MSF_EVENT_MODE_CTRL       0x04
#define MSF_EVENT_MODE_MULTITAP   0x08

typedef enum {
  MsfNotifyLostFocus = 0,
  MsfNotifyFocus = 1,
  MsfNotifyStateChange = 2,
  MsfNotifyMoveResize = 3,
  MsfNotifyResourceLoaded = 4,
  MsfNotifyResourceFailed = 5,
  MsfNotifyMarqueeDone = 6
#ifdef IMAGE_DECOMP_NOTIFY
  ,MsfNotifyResourceDecompressed = 7
  ,MsfNotifyResourceDecompressionFailed = 8
#endif

} MsfNotificationType;

typedef struct {
  MSF_UINT8  eventMode;
  MsfEventClass eventClass;
  MsfEventType eventType;
  MsfPosition position;
} MsfEvent;


typedef struct {
  int r;
  int g;
  int b;
} MsfColor;

typedef enum {
  MsfFontNormal = 0,
  MsfFontOblique = 1,
  MsfFontItalic = 2
} MsfFontStyle;

typedef enum {
  MsfGenericFontSerif = 0,
  MsfGenericFontSansSerif = 1,
  MsfGenericFontCursive = 2,
  MsfGenericFontFantasy = 3,
  MsfGenericFontMonospace = 4
}MsfGenericFont;

typedef struct {
  MsfFontStyle fontStyle;
  int size;
  int weight;
  int stretch;
  int variant;
  MsfFontFamilyNumber fontFamily;   
} MsfFont;

typedef enum {
  MsfNone = 0,
  MsfDotted = 1,
  MsfDashed = 2,
  MsfSemiDotted = 3,
  MsfSolid = 4,
  MsfDouble = 5,
  MsfGroove = 6,
  MsfRidge = 7,
  MsfInset = 8,
  MsfOutset = 9
} MsfLine;

typedef struct {
  int thickness;
  MsfLine style;
} MsfLineStyle;

#define MSF_TEXT_DECORATION_UNDERLINE       0x01
#define MSF_TEXT_DECORATION_OVERLINE        0x02
#define MSF_TEXT_DECORATION_STRIKETHROUGH   0x04
#define MSF_TEXT_DECORATION_SHADOW          0x08
#define MSF_TEXT_DECORATION_BLINK           0x10


typedef struct {
  int decoration;
  int letterSpacing;
  int wordSpacing;
  int lineSpacing;
  int capitalization; 
  MsfAlignment alignment;	
} MsfTextProperty;



typedef enum {
  MsfNoPadding = 0,
  MsfHorisontal = 1,
  MsfVertical = 2,
  MsfTile = 3,
  MsfFullPadding = 4
}MsfPadding;


typedef struct {
  MsfImageHandle image;
  MsfAlignment alignment;
  MsfPadding padding;
}MsfPattern;


typedef enum {
  MsfImageZoom100 = 0,
  MsfImageZoom10 = 1,
  MsfImageZoom25 = 2,
  MsfImageZoom50 = 3,
  MsfImageZoom75 = 4,
  MsfImageZoom125 = 5,
  MsfImageZoom150 = 6,
  MsfImageZoom200 = 7,
  MsfImageZoom400 = 8,
  MsfImageZoom800 = 9,
  MsfImageZoomAutofit = 10
}MsfImageZoom;


typedef enum {
  MsfBmp = 1,
  MsfPictogram = 2,
  MsfGif = 0x1d,
  MsfJpeg = 0x1e,
  MsfPng = 0x20,
  MsfWbmp = 0x21
} MsfImageFormat;

typedef enum {
  MsfUtf8 = 106
} MsfStringFormat;

typedef enum {
  MsfAmr = 0,
  MsfMp3 = 1,
  MsfMidi = 2,
  MsfWav = 3,
  MsfVm = 4
} MsfSoundFormat;

typedef enum {
  MsfClick = 0, MsfTone = 1, MsfSound_1 = 2, MsfSound_2 = 3, MsfSound_3 = 4, 
  MsfSound_4 = 5, MsfSound_5 = 6, MsfSound_6 = 7, MsfSound_7 = 8, MsfSound_8 = 9, 
  MsfSignal_1 = 10, MsfSignal_2 = 11, MsfSignal_3 = 12, MsfSignal_4 = 13, 
  MsfSignal_5 = 14, MsfSignal_6 = 15, MsfSignal_7 = 16, MsfSignal_8 = 17, 
  MsfMelody_1 = 18, MsfMelody_2 = 19, MsfMelody_3 = 20, MsfMelody_4 = 21, 
  MsfMelody_5 = 22, MsfMelody_6 = 23, MsfMelody_7 = 24, MsfMelody_8 = 25
} MsfPredefinedSound;

typedef enum {
  MsfMoveNormal = 0,
  MsfMoveAccelerate = 1,
  MsfMoveDescelerate = 2
} MsfMoveProperty;

typedef enum {
  MsfNoDecoration = 0,
  MsfDecorationBlink = 1,
  MsfDecorationLasVegas = 2,
  MsfDecorationAnts = 3,
  MsfDecorationShimmer = 4,
  MsfDecorationSparkle = 5
} MsfDecoration;

typedef enum {
  MsfMarqueeNone = 0,
  MsfMarqueeScroll = 1, 
  MsfMarqueeSlide = 2, 
  MsfMarqueeAlternate = 3,
  MsfMarqueeInsideScroll = 4
} MsfMarqueeType;


typedef enum {
  MsfResourceFile = 0,
  MsfResourcePipe = 1,
  MsfResourceBuffer = 2
} MsfResourceType;

typedef struct {
  const char* data;
  int dataSize;
  int moreData;
} MsfDirectData;

typedef union {
  const char* resource;
  MsfDirectData* directData;
} MsfCreateData;




/****************************************************************
  Widget General
 ***************************************************************/
int HDIa_widgetDeviceGetProperties(MsfDeviceProperties* theDeviceProperties);

int HDIa_widgetSetInFocus (MSF_UINT32 handle, int focus);

int HDIa_widgetHasFocus (MSF_UINT32 handle);

int HDIa_widgetRelease (MSF_UINT32 handle);

int HDIa_widgetReleaseAll (MSF_UINT8 modId);

MSF_UINT32 HDIa_widgetCopy (MSF_UINT8 modId, MSF_UINT32 handle);

int HDIa_widgetRemove(MSF_UINT32 handle, MSF_UINT32 handleToBeRemoved);

int HDIa_widgetAddAction (MSF_UINT32 handle, MsfActionHandle action);

int HDIa_widgetHandleMsfEvt(MSF_UINT32 handle, int msfEventType, int override, int unsubscribe);

int HDIa_widgetSetTitle (MSF_UINT32 handle, MsfStringHandle title);

int HDIa_widgetSetBorder (MSF_UINT32 handle, MsfLineStyle borderStyle);

int HDIa_widgetSetPosition(MSF_UINT32 handle, MsfPosition* position, MsfAlignment* alignment);

int HDIa_widgetSetSize (MSF_UINT32 handle, MsfSize* size);

int HDIa_widgetGetPosition (MSF_UINT32 handle, MsfPosition* position);

int HDIa_widgetGetSize (MSF_UINT32 handle, MsfSize* size);

int HDIa_widgetAddAnimation(MSF_UINT32 handle, MSF_UINT32 animation);

int HDIa_widgetSetDecoration(MSF_UINT32 handle, MsfDecoration decoration);

int HDIa_widgetMsfEvent2Utf8(MsfEvent *event, int multitap, char* buffer);

/****************************************************************
 SCREEN 
 ***************************************************************/
MsfScreenHandle HDIa_widgetScreenCreate (MSF_UINT8 modId, int notify, MsfStyleHandle defaultStyle);

int HDIa_widgetScreenSetNotify (MsfScreenHandle screen, int notify);
  
int HDIa_widgetScreenAddWindow (MsfScreenHandle screen, MsfWindowHandle window, MsfPosition* position, MsfScreenHandle nextScreen, MsfWindowHandle nextWindow);

MsfWindowHandle HDIa_widgetScreenActiveWindow (MsfScreenHandle screen);
  

/****************************************************************
 WINDOW 
 ***************************************************************/

int HDIa_widgetWindowAddGadget(MsfWindowHandle window, MsfGadgetHandle gadget, 
                               MsfPosition* position, MsfAlignment* alignment);
  
int HDIa_widgetWindowSetTicker (MsfWindowHandle window, MsfStringHandle tickerText);

#define MSF_WINDOW_PROPERTY_SCROLLBARVER  0x0001
#define MSF_WINDOW_PROPERTY_SCROLLBARHOR  0x0002
#define MSF_WINDOW_PROPERTY_TITLE         0x0004
#define MSF_WINDOW_PROPERTY_BORDER        0x0008
#define MSF_WINDOW_PROPERTY_SECURE        0x0010
#define MSF_WINDOW_PROPERTY_BUSY          0x0020
#define MSF_WINDOW_PROPERTY_TICKER_MODE   0x0040
#define MSF_WINDOW_PROPERTY_TICKER        0x0080
#define MSF_WINDOW_PROPERTY_NOTIFY        0x0100
#define MSF_WINDOW_PROPERTY_SINGLEACTION  0x0200
#define MSF_WINDOW_PROPERTY_ALWAYSONTOP   0x0400
#define MSF_WINDOW_PROPERTY_DISABLED      0x0800
#define MSF_WINDOW_PROPERTY_MOVERESIZE    0x1000

  
int HDIa_widgetWindowSetProperties (MsfWindowHandle window, int propertyMask);

int HDIa_widgetWindowSpecificSize (MsfWindowHandle window, MsfSize* size, int minimalSize);


/****************************************************************
 PAINTBOX 
 ***************************************************************/
MsfWindowHandle HDIa_widgetPaintboxCreate (MSF_UINT8 modId, MsfSize* size, 
                                           int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetPaintboxRedrawArea (MsfWindowHandle paintbox, MsfSize* size, MsfPosition* pos);
  

/****************************************************************
 FORM 
 ***************************************************************/
MsfWindowHandle HDIa_widgetFormCreate (MSF_UINT8 modId, MsfSize* size, int propertyMask,
                                       MsfStyleHandle defaultStyle);


/****************************************************************
 TEXT 
 ***************************************************************/
int HDIa_widgetTextSetText (MSF_UINT32 text, MsfStringHandle initialString, MsfTextType type, int maxSize, MsfStringHandle inputString, int singleLine);
    
int HDIa_widgetTextMaxSize (MSF_UINT32 text);
  
int HDIa_widgetTextClear (MSF_UINT32 text);

int HDIa_widgetTextSetProperty (MSF_UINT32 handle, MsfColor* color, MsfFont* font, MsfTextProperty* textProperty);

int HDIa_widgetTextGetProperty(MSF_UINT32 handle, MsfColor* color, MsfFont* font, MsfTextProperty* textProperty, MsfPosition* baseline);


/****************************************************************
 EDITOR 
 ***************************************************************/
MsfWindowHandle HDIa_widgetEditorCreate (MSF_UINT8 modId, MsfStringHandle initialString, 
                                         MsfStringHandle inputString, MsfTextType type, 
                                         int maxSize, int singleLine, MsfSize* size, 
                                         int propertyMask, MsfStyleHandle defaultStyle);

MsfWindowHandle HDIa_widgetEditorCreateCss (MSF_UINT8 modId, MsfStringHandle initialString, 
                                           MsfStringHandle inputString, MsfTextType type, 
                                           const char* formatString, int inputRequired, 
                                           int maxSize, int singleLine, 
                                           MsfSize* size, int propertyMask, MsfStyleHandle defaultStyle);

/****************************************************************
 CHOICE 
 ***************************************************************/
int HDIa_widgetChoiceSetElement (MSF_UINT32 choice, int index, MsfStringHandle string1, MsfStringHandle string2, MsfImageHandle image1, MsfImageHandle image2, int insert);

#ifdef MSF_CONFIG_TOOLTIP
int HDIa_widgetChoiceSetElementTT (MSF_UINT32 choice, int index, 
                                   MsfStringHandle string1, MsfStringHandle string2, 
                                   MsfImageHandle image1, MsfImageHandle image2, 
                                   MsfStringHandle tooltip, 
                                   int insert);
#endif
int HDIa_widgetChoiceRemoveElement (MSF_UINT32 choice, int index);  
    
int HDIa_widgetChoiceGetElemState (MSF_UINT32 choice, int index);

int HDIa_widgetChoiceSetElemState (MSF_UINT32 choice, int index, int state);
  
#define MSF_CHOICE_ELEMENT_ICON     0x01 
#define MSF_CHOICE_ELEMENT_INDEX    0x02 
#define MSF_CHOICE_ELEMENT_STRING_1 0x04 
#define MSF_CHOICE_ELEMENT_STRING_2 0x08 
#define MSF_CHOICE_ELEMENT_IMAGE_1  0x10 
#define MSF_CHOICE_ELEMENT_IMAGE_2  0x20 
    
int HDIa_widgetChoiceAttrProperty (MSF_UINT32 choice, MsfElementPosition* elementPos, int bitmask);

int HDIa_widgetChoiceElemProperty(MSF_UINT32 choice, int index, MsfElementPosition* elementPos, int bitmask);

int HDIa_widgetChoiceSize (MSF_UINT32 choice);


/****************************************************************
 MENU 
 ***************************************************************/
MsfWindowHandle HDIa_widgetMenuCreate (MSF_UINT8 modId, MsfChoiceType type, MsfSize* size, 
                                       MsfActionHandle implicitSelectAction, MsfElementPosition* 
                                       elementPos, int bitmask, int propertyMask, 
                                       MsfStyleHandle defaultStyle);

MsfWindowHandle HDIa_widgetMenuAppCreate (MSF_UINT8 modId, MsfActionHandle implicitSelectAction,
                                          MsfElementPosition* elementPos, int bitmask,
                                          int propertyMask, MsfStyleHandle defaultStyle);


/****************************************************************
 DIALOG 
 ***************************************************************/

MsfWindowHandle HDIa_widgetDialogCreate (MSF_UINT8 modId, MsfStringHandle dialogText, 
                                         MsfDialogType type, MSF_UINT32 timeoutTime, 
                                         int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetDialogSetAttr (MsfWindowHandle dialog, MsfStringHandle dialogText, MSF_UINT32 timeoutTime);
  
int HDIa_widgetDialogAddInput (MsfWindowHandle dialog, MsfStringHandle label, MsfStringHandle inputText, MsfTextType inputMode, int maxSize);

int HDIa_widgetDialogRemoveInput (MsfWindowHandle dialog, int index);

int HDIa_widgetDialogSetInputAttr (MsfWindowHandle dialog, int index, MsfStringHandle label, MsfStringHandle inputText, MsfTextType inputMode, int maxSize);

/****************************************************************
 ACTION 
 ***************************************************************/
MsfActionHandle HDIa_widgetActionCreate (MSF_UINT8 modId, MsfStringHandle label, int 
                                         actionType, int priority, int propertyMask);

int HDIa_widgetActionSetAttr (MsfActionHandle action, int actionType, int priority);

int HDIa_widgetActionGetAttr (MsfActionHandle action, int* actionType, int* priority);

#define MSF_ACTION_PROPERTY_ENABLED       0x0001
#define MSF_ACTION_PROPERTY_SINGLEACTION  0x0002

int HDIa_widgetActionSetProperties (MsfActionHandle action, int propertyMask);

/****************************************************************
 GADGET 
 ***************************************************************/
#define MSF_GADGET_PROPERTY_SCROLLBARVER  0x01
#define MSF_GADGET_PROPERTY_SCROLLBARHOR  0x02
#define MSF_GADGET_PROPERTY_LABEL         0x04
#define MSF_GADGET_PROPERTY_BORDER        0x08
#define MSF_GADGET_PROPERTY_TICKERMODE    0x10
#define MSF_GADGET_PROPERTY_FOCUS         0x20
#define MSF_GADGET_PROPERTY_NOTIFY        0x40
#define MSF_GADGET_PROPERTY_ALWAYSONTOP   0x80
#define MSF_GADGET_PROPERTY_MOVERESIZE    0x1000

int HDIa_widgetGadgetSetProperties (MsfGadgetHandle gadget, int propertyMask);



/****************************************************************
 STRING GADGET 
 ***************************************************************/
MsfGadgetHandle HDIa_widgetStringGadgetCreate (MSF_UINT8 modId, MsfStringHandle text, 
                                               MsfSize* size, int singleLine, int propertyMask, 
                                               MsfStyleHandle defaultStyle);
  
int HDIa_widgetStringGadgetSet (MsfGadgetHandle stringGadget, MsfStringHandle text, int singleLine);
    

/****************************************************************
 TEXT INPUT GADGET 
 ***************************************************************/
MsfGadgetHandle HDIa_widgetTextInputCreate (MSF_UINT8 modId, MsfStringHandle initialString, 
                                            MsfStringHandle inputString, MsfTextType type, 
                                            int maxSize, int singleLine, MsfSize* size, 
                                            int propertyMask, MsfStyleHandle defaultStyle);

MsfGadgetHandle HDIa_widgetTextInputCreateCss (MSF_UINT8 modId, MsfStringHandle initialString, 
                                              MsfStringHandle inputString, MsfTextType type, 
                                              const char* formatString, int inputRequired, 
                                              int maxSize, int singleLine, 
                                              MsfSize* size, int propertyMask, MsfStyleHandle defaultStyle);


/****************************************************************
 SELECT GROUP GADGET 
 ***************************************************************/
MsfGadgetHandle HDIa_widgetSelectgroupCreate (MSF_UINT8 modId, MsfChoiceType type, 
                                              MsfSize* size, MsfElementPosition* elementPos, 
                                              int bitmask, int propertyMask, 
                                              MsfStyleHandle defaultStyle);


/****************************************************************
 IMAGE GADGET
 ***************************************************************/
MsfGadgetHandle HDIa_widgetImageGadgetCreate(MSF_UINT8 modId, MsfImageHandle image, 
                                             MsfSize* size, MsfImageZoom imageZoom, 
                                             int propertyMask, MsfStyleHandle defaultStyle);
    
int HDIa_widgetImageGadgetSet(MsfGadgetHandle imageGadget, MsfImageHandle image, 
                              MsfImageZoom imageZoom);
  

/****************************************************************
 DATE TIME GADGET
 ***************************************************************/
MsfGadgetHandle HDIa_widgetDateTimeCreate (MSF_UINT8 modId, MsfDateTimeType mode, 
                                           MsfTime* time, MsfDate* date, MsfSize* size, 
                                           int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetDateTimeSetValues (MsfGadgetHandle datetimeGadget, MsfDateTimeType mode, MsfTime* time, MsfDate* date);
  
int HDIa_widgetDateTimeGetValues (MsfGadgetHandle datetimeGadget, MsfTime* time, MsfDate* date);


/****************************************************************
 BAR GADGET
 ***************************************************************/
MsfGadgetHandle HDIa_widgetBarCreate (MSF_UINT8 modId, MsfBarType barType,
                                            int maxValue, int initialValue, MsfSize* size,
                                            int propertyMask, MsfStyleHandle defaultStyle);

int HDIa_widgetBarSetValues (MsfGadgetHandle bar, int value, int maxValue);

int HDIa_widgetBarGetValues (MsfGadgetHandle bar, int* value, int* maxValue);



/****************************************************************
 LOW LEVEL
 ***************************************************************/
int HDIa_widgetHoldDraw(MSF_UINT32 msfHandle);

int HDIa_widgetPerformDraw(MSF_UINT32 msfHandle);

int HDIa_widgetDrawLine (MSF_UINT32 msfHandle, 
                         MsfPosition* start, 
                         MsfPosition* end);

int HDIa_widgetDrawRect (MSF_UINT32 msfHandle, MsfPosition* position, 
                         MsfSize* size, int fill);

int HDIa_widgetDrawIcon (MSF_UINT32 msfHandle, MsfIconHandle icon, 
                         MsfPosition* position);

int HDIa_widgetDrawArc (MSF_UINT32 msfHandle, MsfPosition* position, 
                        MsfSize* size, int startAngle,
                        int angleExtent, int fill);

int HDIa_widgetDrawString(MSF_UINT32 msfHandle, MsfStringHandle string, 
                          MsfPosition* position, MsfSize* maxSize, 
                          int index, int nbrOfChars, int baseline, 
                          int useBrushStyle);

int HDIa_widgetDrawPolygon (MSF_UINT32 msfHandle, int nrOfCorners, 
                            MSF_INT16* corners, int fill);

int HDIa_widgetDrawImage(MSF_UINT32 msfHandle, MsfImageHandle image, 
                         MsfPosition* position, MsfSize* maxSize, 
                         MsfImageZoom imageZoom);

int HDIa_widgetDrawAccessKey(MSF_UINT32 msfHandle, 
                             MsfAccessKeyHandle accessKey, 
                             MsfPosition* position);


/****************************************************************
 STYLE
 ***************************************************************/
MsfStyleHandle HDIa_widgetStyleCreate(MSF_UINT8 modId, MsfColor* color, 
                                      MsfColor* backgroundColor, 
                                      MsfPattern* foreground, 
                                      MsfPattern* background, 
                                      MsfLineStyle* lineStyle, 
                                      MsfFont* font, 
                                      MsfTextProperty* textProperty);

MsfBrushHandle HDIa_widgetGetBrush(MSF_UINT32 handle);

int HDIa_widgetSetColor (MSF_UINT32 msfHandle, MsfColor* color,
                         int background);

int HDIa_widgetSetLineStyle (MSF_UINT32 msfHandle,
                             MsfLineStyle* style);

int HDIa_widgetSetTextProperty (MSF_UINT32 msfHandle, 
                                MsfTextProperty* textProperty);

int HDIa_widgetSetPattern (MSF_UINT32 msfHandle, MsfPattern* pattern,
                           int background);

int HDIa_widgetSetFont (MSF_UINT32 msfHandle, MsfFont* font);

int HDIa_widgetFontGetFamily (int nrOfFonts, char* fontNames, 
                              MsfGenericFont genericFont, 
                              MsfFontFamilyNumber * fontFamilyNumber);

int HDIa_widgetGetColor (MSF_UINT32 msfHandle, MsfColor* color, 
                         int background);

int HDIa_widgetGetFont (MSF_UINT32 msfHandle, MsfFont* font);

int HDIa_widgetFontGetValues(MsfFont* font, int* ascent, 
                             int* height, int* xHeight);

int HDIa_widgetGetLineStyle (MSF_UINT32 msfHandle, 
                             MsfLineStyle* msfLineStyle);

int HDIa_widgetGetTextProperty (MSF_UINT32 msfHandle, 
                                MsfTextProperty* textProperty);

int HDIa_widgetGetPattern(MSF_UINT32 msfHandle, int background, 
                          MsfPattern* pattern);

int HDIa_widgetSetMarquee(MSF_UINT32 handle, MsfMarqueeType marqueeType, 
                          int direction, int repeat, int scrollAmount, 
                          int scrollDelay);



/****************************************************************
 STRING
 ***************************************************************/
MsfStringHandle HDIa_widgetStringCreate (MSF_UINT8 modId, 
                                         const char* stringData, 
                                         MsfStringFormat stringFormat, 
                                         int length, 
                                         MsfStyleHandle defaultStyle);

MsfStringHandle HDIa_widgetStringGetPredefined (MSF_UINT32 resId);

MsfStringHandle HDIa_widgetStringCreateText (MSF_UINT8 modId, 
                                             MSF_UINT32 handle, 
                                             int index);
  
int HDIa_widgetStringGetLength(MsfStringHandle string,
                               int lengthInBytes, 
                               MsfStringFormat format);
  
int HDIa_widgetStringGetData(MsfStringHandle string, 
                             char* buffer, 
                             MsfStringFormat format);

int HDIa_widgetStringCompare(MsfStringHandle string1, 
                             MsfStringHandle string2);

int HDIa_widgetStringGetVisible(MsfStringHandle string, 
                                MSF_UINT32 handle, MsfSize* size,
                                int startIndex, 
                                int includeInitialWhiteSpaces, 
                                int* nbrOfCharacters, 
                                int* nbrOfEndingWhiteSpaces, 
                                int* nbrOfInitialWhiteSpaces);

int HDIa_widgetStringGetSubSize(MsfStringHandle string, 
                                MSF_UINT32 handle, int index, 
                                int nbrOfChars, int subwidth,
                                MsfSize* size);


/****************************************************************
 ICON
 ***************************************************************/
MsfIconHandle HDIa_widgetIconCreate (MSF_UINT8 modId, MsfIconType iconType, MsfStyleHandle defaultStyle);


/****************************************************************
 IMAGE
 ***************************************************************/
MsfImageHandle HDIa_widgetImageCreate (MSF_UINT8 modId, const char* imageData,
                                       int imageDataSize, MsfImageFormat imageFormat,
                                       int moreData, MsfStyleHandle defaultStyle);

int HDIa_widgetImageNextPart (MsfImageHandle image, char* imageData,
                              int imageDataSize, int moreData);
 
MsfImageHandle HDIa_widgetImageCreateIcon(MSF_UINT8 modId, MsfIconHandle icon,
                                          MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageCreateResource(MSF_UINT8 modId, char* resource, 
                                              MsfResourceType resourceType, 
                                              MsfImageFormat imageFormat);
  
MsfImageHandle HDIa_widgetImageCreateEmpty (MSF_UINT8 modId, MsfSize* size,
                                            MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageCreateFrame(MSF_UINT8 modId, MsfSize* size, MsfPosition* pos,
                                           MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageCreateFormat(MSF_UINT8 modId, MsfCreateData* imageData, 
                                            const char* imageFormat, MsfResourceType resourceType, 
                                            MsfStyleHandle defaultStyle);

MsfImageHandle HDIa_widgetImageGetPredefined(MSF_UINT32 resId, const char* resString);


/****************************************************************
 SOUND
 ***************************************************************/
MsfSoundHandle HDIa_widgetSoundCreate (MSF_UINT8 modId, char* soundData, 
                                       MsfSoundFormat soundFormat, 
                                       int size, int moreData);

int HDIa_widgetSoundNextPart (MsfSoundHandle sound, char* soundData, int size, int moreData);

int HDIa_widgetSoundPlay (MsfSoundHandle sound);

int HDIa_widgetSoundPlayPredefined (MsfPredefinedSound sound);

int HDIa_widgetSoundStop (MsfSoundHandle sound);

MsfSoundHandle HDIa_widgetSoundCreateResource(MSF_UINT8 modId, 
                                              char* resource, 
                                              MsfResourceType resourceType, 
                                              MsfSoundFormat soundFormat);

MsfSoundHandle HDIa_widgetSoundCreateFormat(MSF_UINT8 modId, MsfCreateData* soundData, 
                                            const char* soundFormat, MsfResourceType resourceType);

MsfSoundHandle HDIa_widgetSoundGetPredefined(MSF_UINT32 resId);


/****************************************************************
 ACCESS KEYS
 ***************************************************************/
MsfAccessKeyHandle HDIa_widgetSetAccessKey(MSF_UINT32 handle,
                                           char* accessKeyDefinition,
                                           int override, int index,
                                           int visualise);

int HDIa_widgetRemoveAccessKey(MSF_UINT32 handle, 
                               MsfAccessKeyHandle accessKey);

/****************************************************************
 ANIMATION
 ***************************************************************/
MsfMoveHandle HDIa_widgetMoveCreate (MSF_UINT8 modId, MsfPosition* origin,
                                     MsfPosition* destination, int duration, 
                                     int nrOfSteps, MsfMoveProperty property, int repeat);

MsfRotationHandle HDIa_widgetRotationCreate (MSF_UINT8 modId, int startAngle, 
                                             int endAngle, int duration, int nrOfSteps, 
                                             MsfMoveProperty property, int repeat);

MsfColorAnimHandle HDIa_widgetColorAnimCreate (MSF_UINT8 modId, MsfColor* startColor, 
                                              MsfColor* endColor, int duration, 
                                              int nrOfSteps, MsfMoveProperty property, int repeat);



/**********************************************************************
 * Object Actions
 **********************************************************************/
void HDIa_objectAction (const char *action_cmd, const char *mime_type, 
                        MsfResourceType data_type, const unsigned char *data, 
                        MSF_INT32 data_len, const char *src_path, 
                        const char *default_name);

#ifdef MSF_CONFIG_PIM

/**********************************************************************
 * PIM
 **********************************************************************/

/* PIM field */
typedef struct
{
	MSF_UINT16 field;
  MSF_UINT8  type;
  MSF_UINT32 length;
	MSF_UINT8  *data;
	}MsfPimField;

/* Record info */
typedef struct
{
  MSF_UINT16 field;
  MSF_UINT8  type;
  MSF_UINT32 length;
	MSF_UINT8  *data;
	MSF_UINT32 recordId;
}MsfPimAddrRecordInfo;


/* Field types */
#define HDI_PIM_ADDR_FIELD_NAME                 1
#define HDI_PIM_ADDR_FIELD_SHORT_NAME           2
#define HDI_PIM_ADDR_FIELD_NICK_NAME            3
#define HDI_PIM_ADDR_FIELD_JOB_TITLE            4
#define HDI_PIM_ADDR_FIELD_STREET               5
#define HDI_PIM_ADDR_FIELD_CITY                 6
#define HDI_PIM_ADDR_FIELD_ZIP                  7
#define HDI_PIM_ADDR_FIELD_STATE                8
#define HDI_PIM_ADDR_FIELD_COUNTRY              9
#define HDI_PIM_ADDR_FIELD_POST_CODE            10
#define HDI_PIM_ADDR_FIELD_TEL                  11
#define HDI_PIM_ADDR_FIELD_MOBILE               12
#define HDI_PIM_ADDR_FIELD_TEL_FAX              13
#define HDI_PIM_ADDR_FIELD_EMAIL                14
#define HDI_PIM_ADDR_FIELD_BIRTHDAY             15
#define HDI_PIM_ADDR_FIELD_HOMEPAGE             16
#define HDI_PIM_ADDR_FIELD_GROUP                17
#define HDI_PIM_ADDR_FIELD_CATEGORY             18
#define HDI_PIM_ADDR_FIELD_PICTURE              19
#define HDI_PIM_ADDR_FIELD_SOUND                20
#define HDI_PIM_ADDR_FIELD_VOICE_MAIL_BOX       21
#define HDI_PIM_ADDR_FIELD_IM                   22

/* Location types */
#define HDI_PIM_WORK                        1
#define HDI_PIM_HOME                        2

/* Result types */
#define HDI_PIM_OK                          0
#define HDI_PIM_ERROR_NOT_OPEN              -1 
#define HDI_PIM_ERROR_NO_RECORD             -2
#define HDI_PIM_ERROR_CANCEL_BY_USER        -3
#define HDI_PIM_ERROR_UNSPECIFIED           -4
#define HDI_PIM_ERROR_INVALID               -5
#define HDI_PIM_ERROR_MEM_FULL              -6
#define HDI_PIM_ERROR_DUPLICATE_RECORD      -7

/* Pim objects */
#define HDI_PIM_OBJECT_PHONE_BOOK           1
#define HDI_PIM_OBJECT_CALENDAR             2
#define HDI_PIM_OBJECT_TODO                 3
#define HDI_PIM_OBJECT_ALARM                4

/* Filters */
#define HDI_PIM_ADDR_FILTER_MOBILE          1
#define HDI_PIM_ADDR_FILTER_FAX             2
#define HDI_PIM_ADDR_FILTER_STREET          3
#define HDI_PIM_ADDR_FILTER_EMAIL           4
#define HDI_PIM_ADDR_FILTER_IM              5
#define HDI_PIM_ADDR_FILTER_PHONE           6
#define HDI_PIM_ADDR_FILTER_TEL             7
#define HDI_PIM_ADDR_FILETR_GROUP           8
#define HDI_PIM_ADDR_FILTER_PIC             9
#define HDI_PIM_ADDR_FILTER_SOUND           10
#define HDI_PIM_ADDR_FILTER_URI             11
#define HDI_PIM_ADRR_FILTER_ALL             12
#define HDI_PIM_ADRR_FILTER_NONE            13


void 
HDIa_pimOpen (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 pimObject);

void 
HDIa_pimClose (MSF_UINT8 modId, MSF_UINT16 requestId);

void 
HDIa_pimAddrLookup (MSF_UINT8 modId, MSF_UINT16 requestId,  
                    MSF_UINT16 resultFilter, const char* positionStr);

void 
HDIa_pimAddrLookupName (MSF_UINT8 modId, MSF_UINT16 requestId, 
                        MSF_UINT16 searchFilter, MSF_UINT16 nameField,
                        const char* searchStr);

void 
HDIa_pimAddrGetRecord (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT32 recordId);


void 
HDIa_pimAddrSetRecord (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 setFilter, 
                       const char *name, MsfResourceType dataType, const MSF_UINT8 *data, 
                       MSF_UINT32 len, const char *srcPath, const char *mimeType);


#endif /*MSF_CONFIG_PIM*/

/**********************************************************************
 * Memory
 **********************************************************************/

#ifdef MSF_CONFIG_INTERNAL_MALLOC

void*
HDIa_memInternalInit (MSF_UINT8 modId, MSF_UINT32* size);

#else

void*
HDIa_memAlloc (MSF_UINT8 modId, MSF_UINT32 size);

void
HDIa_memFree (MSF_UINT8 modId, void* p);

#endif

void*
HDIa_memExternalAlloc (MSF_UINT8 modId, MSF_UINT32 size);

void
HDIa_memExternalFree (MSF_UINT8 modId, void* p);

/**********************************************************************
 * Errors
 **********************************************************************/

/* Main error code categories */
#define HDI_ERR_SYSTEM                              0x100
#define HDI_ERR_MODULE                              0x200

/* System errors */
#define HDI_ERR_SYSTEM_REG_ABORTED                  HDI_ERR_SYSTEM + 1
#define HDI_ERR_SYSTEM_REG_FILE_CORRUPT             HDI_ERR_SYSTEM + 2
#define HDI_ERR_SYSTEM_FATAL                        HDI_ERR_SYSTEM + 3
#define HDI_ERR_SYSTEM_REG_TXT_FILE                 HDI_ERR_SYSTEM + 4
#define HDI_ERR_SYSTEM_REG_TXT_PARSE                HDI_ERR_SYSTEM + 5

/* Module errors */
#define HDI_ERR_MODULE_OUT_OF_MEMORY                HDI_ERR_MODULE + 1


void
HDIa_error (MSF_UINT8 modId, int errorNo);


/**********************************************************************
 * Module
 **********************************************************************/

MSF_UINT8
HDIa_getModuleID (void);

void
HDIa_killTask (MSF_UINT8 modId);

#endif
