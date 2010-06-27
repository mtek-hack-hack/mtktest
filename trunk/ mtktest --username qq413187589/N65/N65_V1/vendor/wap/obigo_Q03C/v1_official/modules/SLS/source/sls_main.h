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




#ifndef _SLS_MAIN_H
#define _SLS_MAIN_H

#ifndef _SLS_IF_H
#error sls_if.h must be included berfore sls_main.h!
#endif

#ifndef _MMS_DEF_H
#error mms_def.h must be included berfore sls_main.h!
#endif






typedef struct   
{
    const SlsMediaType       mediaType;         
    const char               *mimeType;         
    const MmsKnownMediaType  mmsMediaType;      
    const SlsMediaObjectType objectType;        
}SlsMediaTypeItem;





typedef enum 
{
    
    SMIL_MEDIA_OBJECT_AUDIO = 0,
    
    SMIL_MEDIA_OBJECT_IMG,
    



    SMIL_MEDIA_OBJECT_REF,
    
    SMIL_MEDIA_OBJECT_TEXT,
	
    SMIL_MEDIA_OBJECT_VIDEO
} SmilMediaObjectElement;







typedef struct SmilMediaObjectSt
{
    
    SmilMediaObjectElement mediaObjectElement;

    



    char *src;

    
    char *alt;

    
    char *region;

    
    char *begin; 

    
    char *end;

    
    MSF_UINT32 color;

    
    struct SmilMediaObjectSt *next;
}SmilMediaObject;








typedef struct
{
    
    SmilMediaObject *mobj;

    
    MSF_UINT32 dur;
    MSF_UINT8  used;
} SmilPar;





typedef struct Regions
{
    char    *id;         
    SlsSize  position;   
    SlsSize  size;       
	SlsFit	 fit;		 
    struct Regions *next; 
} Regions;





typedef struct
{
	MSF_BOOL				slsIsStarted;
    MSF_UINT8               client;
	MmsGetHeader			*mmsHeader;
	SlsUnrefItemList		*unrefItems;
	MSF_UINT32				noUnrefItems;
    MmsMsgId                msgId;
    MmsFileType             fileType;
    SmilPar*                 parList;

    Regions					*regions;
    SlsRootLayout           rootLayout;
    int                     slidePointer;
    int*                     elementStack;
    int						*stackP;
    int						smilBodyPartNumber;
    MSF_UINT32              smilSize;
    unsigned char			*smilData;
    MmsTransactionHandle    hTransaction;
    MmsMsgHandle            hMsg;
} InstanceData;
















void slsInit(void);







void slsSignalDispatcher(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p);






const SlsMediaTypeItem *slsGetSupportedMoList(void);

#endif 


