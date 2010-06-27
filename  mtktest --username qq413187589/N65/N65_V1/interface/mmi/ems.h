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
 *	ems.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains data types and function prototypes for EMS library.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _EMS_H
#define _EMS_H

#ifdef EMS_ON_WIN32 

#define ems_mem_cpy memcpy
#define ems_mem_set memset
#define ems_mem_cmp memcmp
#define ems_get_buffer malloc
#define ems_free_buffer free

#else

#define ems_mem_cpy kal_mem_cpy
#define ems_mem_set kal_mem_set
#define ems_mem_cmp kal_mem_cmp
#define ems_get_buffer get_ctrl_buffer
#define ems_free_buffer free_ctrl_buffer

#endif /* EMS_ON_WIN32 */

/*===================================
 * constants
 *===================================*/
#define EMS_MAX_ANIM_PREDEF_NO	(14) /* 0~14 */
#define EMS_MAX_SND_PREDEF_NO	   (9) /* 0~9 */
#define EMS_MAX_IMELODY_SIZE     (128)
#define EMS_MAX_PIC_SIZE         (128)

/*===================================
 * enum
 *===================================*/

typedef enum
{
   EMS_ATTB_NORMAL  = 0x00,
   EMS_ATTB_NOT_FW  = 0x01
} EMSATTRIBUTE;

typedef enum
{
   EMS_ALIGN_LEFT     = 0x00,
   EMS_ALIGN_CENTER   = 0x01,
   EMS_ALIGN_RIGHT    = 0x02,   
   EMS_ALIGN_LANG_DEP = 0x03 /* language dependent (default) */
} EMSALIGNMENT;

typedef enum
{
   EMS_FONTSIZE_NORMAL = 0x00,
   EMS_FONTSIZE_LARGE  = 0x04,
   EMS_FONTSIZE_SMALL  = 0x08
} EMSFONTSIZE;

typedef enum
{   
   EMS_TYPE_TEXT_FORMAT,      /* eg, alignment, bold, ... */
   EMS_TYPE_PREDEF_SND,       /* predefined sound */
   EMS_TYPE_USERDEF_SND,      /* user defined sound */
   EMS_TYPE_PREDEF_ANM,       /* predefined animation */
   EMS_TYPE_USERDEF_ANM,      /* small/large animation */   
   EMS_TYPE_PIC,              /* picture */      
   NUM_OF_EMS_SUPPORTED_OBJ,/* internal use by EMS library */
   EMS_TYPE_VCARD,            /* vCard */
   EMS_TYPE_VCALENDAR         /* vCalendar */

} EMSTYPE;

typedef enum
{
   EMS_OK=0,
   EMS_INVALID_OBJECT,
   EMS_NO_SPACE,
   EMS_INVALID_DCS,
   EMS_NOT_SUPPORT_COLOR_PIC, /* color picture suppored in Release 5 */
   EMS_NULL_POINTER,          /* application pass a NULL pointer */
   EMS_NO_MEMORY,             /* EMS library run out of memory */
   EMS_ALREADY_INITIALIZED,   /* EMS library already be initialized */
   EMS_NOT_INITIALIZED,       /* EMS library is not be initialized */
   EMS_EMS_DATA_EXCEEDED,     /* EMS Data exceeds the max. supported number */
   EMS_INVALID_EMS_DATA,      
   EMS_UNSPECIFIED_ERROR,
   EMS_INVALID_PORT_NUM,
   EMS_NOT_SUPPORT_OBJECT,    /* used by __SLIM_EMS__ compile option */
   EMS_IGNORE_NOT_FW_OBJ,     /* NOT_FW object is ignored in EMSCopy function */
   EMS_INVALID_EMS50_IE,      /* indicate the message includes invalid EMS50 IE */
   EMS_NO_ALIGNMENT_FMT,       /* text alignment is not allowed. */

   /* the following is used by MMI */
   EMS_INVALID_FILE_NAME = 100,        /* used when user inputs invalid file name for object to be saved */
   EMS_EMPTY_FILE_NAME,         /* used when user inputs empty file name for object to be saved */

   EMS_STATUS_END
} EMSTATUS;

/* Release 5 feature */
typedef enum
{
   EMS_BLACK	= 0x00,
   EMS_DARK_GREY,
   EMS_DARK_RED,
   EMS_DARK_YELLOW,
   EMS_DARK_GREEN,
   EMS_DARK_GYAN,
   EMS_DARK_BLUE,
   EMS_DARK_MAGENTA,
   EMS_GREY,
   EMS_WHITE,
   EMS_BRIGHT_RED	,
   EMS_BRIGHT_YELLOW,
   EMS_BRIGHT_GREEN,
   EMS_BRIGHT_GYAN,
   EMS_BRIGHT_BLUE,
   EMS_BRIGHT_MAGENTA	

} EMSCOLOR;


/*===================================
 * struct/union
 *===================================*/
 
/* Text Format  */
typedef struct
{    
   /* Format Mode */
   EMSFONTSIZE FontSize;   
   EMSALIGNMENT Alignment;  
      
   /* 0: off 1: on */
   kal_bool isBold;      
   kal_bool isItalic;   
   kal_bool isUnderline;
   kal_bool isStrikethrough;

   
   EMSCOLOR bgColor; /* Release 5 feature */   
   EMSCOLOR fgColor; /* Release 5 feature */  

   /* filled by EMS library, unit: octets */
   kal_uint16 textLength; 

} EMSTextFormat;

 /* Picture  */
typedef struct
{      
   kal_uint8  *pdu;
   kal_uint16 pdu_length;
   kal_uint8  attribute; 

   kal_uint8 bitsPerPixel; 
   kal_uint8 vDim;  /* verical number of pixtels */
   kal_uint8 hDim;  /* horizontal number of pixtels */
} EMSPicture;

/* Animation  */
typedef struct
{      
   kal_uint8  *pdu;   
   kal_uint16 pdu_length;
   kal_uint8  attribute; 

   kal_uint8 bitsPerPixel; 
   kal_uint8 vDim;  /* verical number of pixtels */
   kal_uint8 hDim;  /* horizontal number of pixtels */
   kal_uint8 cFrame;    /* count of frames */
   kal_uint8 cRepeat;   /* number of repetitions*/
   kal_uint8 Duration;  /* in tenths of a second, eg, 0: 0.1s15: 1.6s */
} EMSAnim;

 /* Sound  */
typedef struct
{      
   kal_uint8  *pdu;
   kal_uint16 pdu_length;
   kal_uint8  attribute; 
} EMSSound;

 /* vCard and vCalendar */
typedef struct
{      
   kal_uint8 *pdu;
   kal_uint16 pdu_length;
   kal_uint8  attribute; 
} EMSVApp;

typedef struct
{      
   kal_uint8  *pdu;
   kal_uint16 pdu_length;
   kal_uint8  attribute; 
} EMSCommon;


typedef union
{
   EMSTextFormat  text_format; 
   EMSPicture     picture;
   EMSSound	      sound;	
   EMSAnim        animation;    
   EMSVApp	      vapp;	
   EMSCommon      common;
} EMSObjData;

typedef struct _EMSObject
{        
   kal_uint8          Type;          	
   kal_uint8          PredefNo;         	
   kal_uint16         OffsetToText;  /* offset to Text (in octets) */
   EMSObjData        *data;   	    /* picture, sound, etc */
   struct _EMSObject *prev;          /* pointer to previous object */
   struct _EMSObject *next;          /* pointer to next object */
   
} EMSObject;

typedef struct
{	
   kal_uint16    OffsetToText; /* in octets */ 
   EMSObject    *Object; 
} EMSPosition;

typedef struct
{	
   kal_bool	    isPortNumSet; 
   kal_uint16   src_port;
   kal_uint16   dst_port;
} EMSPort;


typedef struct
{	
   
   /* After add/remove text or object, 
    * MMI could check this flag to know 
    * whether segment change, eg, 1 -> 2 or 3 -> 2.	 
    */
   kal_bool	isSegChange; 

   /* The number of required segments to carry this EMS. 
    * Initial value is 1.    
    */
   kal_uint8	requiredSegment;

   /* The number of remaining characters in current segment. 
    * Initial value is 160 if DCS is GSM7-bit, otherwise is 140.	 
    */
   kal_uint8	segRemainingOctet;			

   /* The number of usable characters in current segment. */
   /* If it is 1st segment, it will be 140 or 160.  */
   /* Otherwise, it is equal to maxUsableLenPerSeg. */
   kal_uint8    segUsableOctet;

   /* The number of total remaining characters.	 */
   kal_uint16	totalRemainingOctet;			

   /* The number of usable characters exclude concatenated ie. */
   kal_uint8   maxUsableLenPerSeg;  

} EMSReminder;


typedef struct 
{
   EMSPosition    CurrentPosition;
   EMSObject	  *CurrentTextFormatObj;
   EMSObject	  *listHead;
   EMSObject	  *listTail;

   kal_uint8      id;               
   kal_uint8     *textBuffer;	     /* buffer to hold text */
   kal_uint16     textLength;	     /* size acutal used (in octets) */
   kal_uint16     textBufferSize;  /* size allocated for text (in octets) */
   
   kal_uint8      dcs;               /* used when EMS contains Text */       
   kal_uint8      *oridcs;            /* used to reserve sms original dcs */  
   /* Data Coding Scheme For Procotol Stack
    * It includes Message Class and Character Set. (ie. above dcs value)
    * Please refer to  3GPP 23.038 Clause 4 SMS Data Coding Scheme for detail.
    */
   kal_uint8      ps_dcs; 

   /* User Data Header Indicator		
    * In the case of concatenated or EMS, this flag will be set to TRUE
    */
   kal_bool	      udhi;		
   kal_bool       isConcat;
  	  	
   EMSReminder    Reminder; 

   EMSPort        PortNum;

   /* used by EMS library internally */
   void *internal;   
} EMSData;




/*===================================
 * function prototypes
 *===================================*/
#ifdef __cplusplus 
extern "C" 
{
#endif

/* Initialize / DeInitialize Category */
extern
EMSTATUS EMSInitialize(void);

extern
EMSTATUS EMSDeInitialize(void);

extern 
EMSTATUS InitializeEMSData (EMSData *emsData, kal_uint8 dcs);

extern
EMSTATUS ReleaseEMSData (EMSData *emsData);

/* Position Management Category */
extern
void ResetCurrentPosition(EMSData *data);

extern
void GoToEndPosition (EMSData *data);

extern
kal_uint16 BackwardCurrentPosition(EMSData *data, kal_uint16 steps);

extern
kal_uint16 ForwardCurrentPosition(EMSData *data, kal_uint16 steps);

extern
kal_uint16 CancelCurrentPosition(EMSData *data, kal_uint16 steps);


/* Object Management Category */
extern
EMSTATUS AddObject(EMSData *emsData, 
                   kal_uint8 type, 
                   EMSObjData *objData,
                   kal_uint8 PredefNo);



/* Text Management Category */

/* each character consumes two octets
 * GSM7-bit / 8-bit : 1st octet is padding with zero 
 */
extern
EMSTATUS AddString(EMSData *emsData , 
                   kal_uint8 *string, 
                   kal_uint16 num_char,
                   EMSTextFormat *txt_fmt);
extern
void ResetTextFormat(EMSTextFormat *txt_fmt);

extern EMSTATUS AddTextAlignment(EMSData *emsData, kal_uint16 offsetToText, 
                                 EMSTextFormat *txt_fmt);


/* Pack / Unpack Category */
extern
EMSTATUS EMSPack(EMSData *emsData,
                 kal_uint8     need_new_ref,
                 kal_uint8     *numOfMsg,
                 kal_uint8     *TPUD[],
                 kal_uint8		 TPUDLen[]);


extern
EMSTATUS EMSUnPack(EMSData *emsData,
                   kal_uint8      udhi,
                   kal_uint8      numOfMsg,
                   kal_uint8      *TPUD[],
                   kal_uint8      TPUDLen[],
                   kal_uint8      PERDCS[]);

extern
EMSTATUS EMSMsgPreview(kal_uint8     numOfMsg,
			              kal_uint8     dcs,
                       kal_uint8     udhi,
                       kal_uint8     *TPUD[],
                       kal_uint8     TPUDLen[],
                       kal_uint16    BuffLen,    /* octets */ 
                       kal_uint8     *textBuff,
                       kal_uint8     *is_obj_present, 
                       kal_uint16    *textLen);   /* octets */


/* Miscellaneous Category */
extern
EMSTATUS EMSSetDCS(EMSData *emsData, kal_uint8 dcs);

extern
EMSTATUS EMSSetOriDCS(EMSData *emsData, kal_uint8 ORIDCS[], kal_uint8 numOfMsg);

extern
void ems_decode_dcs(kal_uint8 dcs, kal_bool  *is_compress);

extern
EMSTATUS EMSResetPortNum(EMSData *emsData);

extern
EMSTATUS EMSSetPortNum(EMSData *emsData, kal_uint16 src_port, kal_uint16 dst_port);

extern
kal_bool GetUDHIBit(kal_uint8 fo);


extern
EMSTATUS CopyEMSData(EMSData *dest, EMSData *src);

extern
void EMSConcatMsgRefFunc(kal_uint16(*)(void));

extern
kal_uint8 EMSGetNextObject(EMSData     *data, 
                           EMSPosition *p, 
                           kal_uint16  *c, 
                           EMSObject   **o);

extern
kal_uint8 EMSGetPreviousObject(EMSData     *data, 
                               EMSPosition *p, 
                               kal_uint16  *c, 
                               EMSObject   **o);

extern
kal_int32 EMSGetObjectSize (kal_uint8 type, EMSObjData *objdata);

extern
kal_int32 EMSGetObjectSizeWithCheck ( kal_uint8 type, EMSObjData *objdata, kal_bool *isAllow );


extern EMSTATUS EMSSetCompressMode(kal_bool mode);

extern kal_bool EMSIsReusedObj(EMSData *emsData, EMSObject *obj_q);

#ifdef __cplusplus
}
#endif

#endif /* _EMS_H */

