/*
 * Copyright (C) Obigo AB, 2002-2005.
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
 





#ifndef _MLTYPES_H
#define _MLTYPES_H







typedef struct 
{
   void *buf;               
   long filePos;            
   void *bufferPos;           
   int sizeOfBuf;             
   int fileHandle;            
   MSF_BOOL isMessageFile;  
   int state;               
   int subState;            
   int counter;             
   void *tmpPtr;            
   MSF_UINT32 bytesLeft;    
} MmsTransaction;







typedef struct
{
    MmsMsgId msgId;                     
    int fileHandle;                     
    char *fileName;                     
    MmsMessageInfoHandle infoHandle;    
} MmsMessage;


 
typedef enum
{
    
    POS_TOTAL_NO_OF_PARTS,  
    
    POS_INT_MSG_NUMBER      
} MmsIntMsgInfo;


typedef enum
{
    POS_ENTRY_SIZE,        
    POS_ENTRY_START,       
    POS_DATA_SIZE,         
    POS_DATA_START,        
    POS_NO_OF_SUBPARTS,    
    POS_INT_PART_NUMBER    
} MmsIntPartInfo;
#endif 


