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
 * msf_log.h
 *
 * Created by Henrik Olsson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msf_log_h
#define _msf_log_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif
#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

/**********************************************************************
 * Module Logging
 **********************************************************************/

/* Logging levels */
#define MSF_LOG_DETAIL_LOW              HDI_LOG_TYPE_DETAILED_LOW
#define MSF_LOG_DETAIL_MEDIUM           HDI_LOG_TYPE_DETAILED_MEDIUM
#define MSF_LOG_DETAIL_HIGH             HDI_LOG_TYPE_DETAILED_HIGH


#ifdef MSF_LOG_MODULE

#include "stack_config.h"
#include "kal_non_specific_general_types.h"
#include "kal_trace.h"
#include "wap_trc.h"

#ifdef __MTK_TARGET__

#define MSF_LOG_MSG_ARGS_(type, modId, msgId, format, s, ...)       HDIa_logTrace (type, modId, msgId, format, __VA_ARGS__)
#define MSF_LOG_MSG_NOARG_(type, modId, msgId, format, s)           HDIa_logTrace (type, modId, msgId, format)
#define MSF_LOG_MSG_NOARG(x)                                        MSF_LOG_MSG_NOARG_ x
#define MSF_LOG_MSG_ARGS(x)                                         MSF_LOG_MSG_ARGS_ x

#else

#define MSF_LOG_MSG_NOARG(x)                                        HDIa_logTrace x
#define MSF_LOG_MSG_ARGS(x)                                         HDIa_logTrace x

#endif

#define MSF_LOG_MSG_OFF(x)                                          
#define MSF_LOG_MSG(x)                              HDIa_logMsg x
#define MSF_LOG_DATA(level, modId, data, dataLen)   HDIa_logData (level, modId, data, dataLen)
#else
#define MSF_LOG_MSG(x)
#define MSF_LOG_MSG_NOARG(x)
#define MSF_LOG_MSG_OFF(x)
#define MSF_LOG_MSG_ARGS(x)
#define MSF_LOG_DATA(level, modId, data, dataLen)
#endif


/**********************************************************************
 * Signal Logging
 **********************************************************************/

enum LogSignalWhen{ LS_SEND, LS_RECV};
#define LOG_SIG_CHUNK_SIZE 512


#ifdef MSF_LOG_SIGNALS   
typedef struct 
{
   char* pszStr;
   int   strLen;
   int   maxStrLen;
   int   collLevel;
   int   doLog;
   int   src;
   int   dest;
   int   allocator;
}LogSigHelper;

enum LogSigTypes
{
  LS_UINT,
  LS_UINT8,
  LS_UINT16,
  LS_UINT32,
  LS_INT,
  LS_INT8,
  LS_INT16,
  LS_INT32,
  LS_FLOAT32,
  LS_BYTES,
  LS_STR,
  LS_VOID,
  LS_COLL,
  LS_ITEMS
};

typedef struct  
{
   int id;
   char* str;
}LogSigMap;

void MSF_LogSigBegin(LogSigHelper* pObj, const char* signalName, MSF_UINT8 when, MSF_UINT8 src, MSF_UINT8 dest); 
void MSF_LogSigParam(LogSigHelper* pObj, const char* paramName, int type, void* paramValue, int paramSize);
void MSF_LogSigColl(LogSigHelper* pObj, const char* collName);
void MSF_LogSigCollEnd(LogSigHelper* pObj);
void MSF_LogSigEnd(LogSigHelper* pObj);
extern LogSigMap MSF_LogSigMap[LS_ITEMS + 1];
extern MSF_BOOL MSF_LogSigDoLog;

#define MSF_LOG_SIG_BEGIN(signalName, when, src, dest)\
{\
  LogSigHelper lsHelper;\
  lsHelper.doLog = MSF_LogSigDoLog;\
  if(lsHelper.doLog) { MSF_LogSigBegin(&lsHelper, signalName, when, src, dest); } 

#define MSF_LOG_SIG_UINT(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_UINT, &paramValue, sizeof(paramValue)); }

#define MSF_LOG_SIG_UINT8(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_UINT8, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_UINT16(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_UINT16, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_UINT32(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_UINT32, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_INT(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_INT, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_INT8(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_INT8, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_INT16(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_INT16, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_INT32(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_INT32, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_FLOAT(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_FLOAT32, &paramValue, sizeof(paramValue)); }
   
#define MSF_LOG_SIG_STR(paramName, paramValue)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_STR, &paramValue, paramValue ? (msf_cmmn_utf8_strlen(paramValue) + 1) : 0); }

#define MSF_LOG_SIG_BYTE(paramName, paramValue, paramLength)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_BYTES, &paramValue, paramValue ? paramLength : 0); }

#define MSF_LOG_SIG_VOID(paramName)\
  if(lsHelper.doLog) { MSF_LogSigParam(&lsHelper, paramName, LS_VOID, NULL, 0); }

#define MSF_LOG_SIG_COLL(collName)\
  if(lsHelper.doLog) { MSF_LogSigColl(&lsHelper, collName); }

#define MSF_LOG_SIG_COLL_END()\
  if(lsHelper.doLog) { MSF_LogSigCollEnd(&lsHelper); }


#define MSF_LOG_SIG_END()\
  if(lsHelper.doLog) { MSF_LogSigEnd(&lsHelper); }\
}

#else /*MSF_LOG_SIGNALS*/

#define MSF_LOG_SIG_BEGIN(signalName, when, src, dest)
#define MSF_LOG_SIG_UINT(paramName, paramValue)
#define MSF_LOG_SIG_UINT8(paramName, paramValue)
#define MSF_LOG_SIG_UINT16(paramName, paramValue)
#define MSF_LOG_SIG_UINT32(paramName, paramValue)
#define MSF_LOG_SIG_INT(paramName, paramValue)
#define MSF_LOG_SIG_INT8(paramName, paramValue)
#define MSF_LOG_SIG_INT16(paramName, paramValue)
#define MSF_LOG_SIG_INT32(paramName, paramValue)
#define MSF_LOG_SIG_FLOAT(paramName, paramValue)
#define MSF_LOG_SIG_STR(paramName, paramValue)
#define MSF_LOG_SIG_BYTE(paramName, paramValue, paramLength)
#define MSF_LOG_SIG_VOID(paramName)
#define MSF_LOG_SIG_COLL(collName)
#define MSF_LOG_SIG_COLL_END()
#define MSF_LOG_SIG_END()

#endif /*MSF_LOG_SIGNALS*/






#ifdef MSF_LOG_FC
typedef struct 
{
   void* pCriticalSection;
   void* pLogFuncCallObj;
   int nFields;
   int doLog;
}LogFuncCallHelper;

typedef struct 
{
   int nArrays;
   int arrayIndexes[10];
}ArrayDescr;


void      
logFuncCallBegin(LogFuncCallHelper* pLogFuncCallHelper, char* pszName);

void            
logFuncCallPreCall(LogFuncCallHelper* pLogFuncCallHelper);

void      
logFuncCallEnd(LogFuncCallHelper* pLogFuncCallHelper);

void 
logFuncCallUint8(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, MSF_UINT8* value, ArrayDescr* pArrayDescr);

void 
logFuncCallUint16(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, MSF_UINT16* value, ArrayDescr* pArrayDescr);

void
logFuncCallUint32(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, MSF_UINT32* value, ArrayDescr* pArrayDescr);

void
logFuncCallInt8(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, MSF_INT8* value, ArrayDescr* pArrayDescr);

void
logFuncCallInt16(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, MSF_INT16* value, ArrayDescr* pArrayDescr);

void
logFuncCallInt32(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, MSF_INT32* value, int size, ArrayDescr* pArrayDescr);

void 
logFuncCallPtr(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, void** pValue, ArrayDescr* pArrayDescr);

void
logFuncCallString(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, const char* value, ArrayDescr* pArrayDescr);


void
logFuncCallBytes(LogFuncCallHelper* pLogFuncCallHelper, const char* szName, const unsigned char* value, int length, ArrayDescr* pArrayDescr);
   extern MSF_BOOL MSF_LogFcDoLog;

   #define MSF_LOG_FC_PARAMS_DECLARE LogFuncCallHelper lfcHelper  
   #define MSF_LOG_FC_PARAMS_IMPLEMENT lfcHelper 
   #define MSF_LOG_FC_DISPATCH_MAP_DECLARE(modName)\
   extern  int\
   modName##_callFunc(const char* szFuncName);
   #define MSF_LOG_FC_DISPATCH_MAP_FUNC_PTR(modName) modName##_callFunc
   #define MSF_LOG_FC_DISPATCH_MAP_BEGIN(modName)\
   int\
   modName##_callFunc(const char* szFuncName)\
   {\
      int callFuncRetVal = -1; 

   #define MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(fName)\
      if((callFuncRetVal == -1) && !msf_cmmn_strcmp_nc(szFuncName, #fName))\
      {

   #define MSF_LOG_FC_DISPATCH_MAP_ENTRY_END\
         callFuncRetVal = 0;\
      }


   #define MSF_LOG_FC_DISPATCH_MAP_SUB_DISPATCH_MAP(fName)\
    if(callFuncRetVal == -1)\
    {\
       callFuncRetVal = fName##_callFunc(szFuncName);\
    }

   #define MSF_LOG_FC_DISPATCH_MAP_END\
      szFuncName = NULL;\
      return callFuncRetVal;\
   }

   #define MSF_LOG_FC_BEGIN(p)\
   LogFuncCallHelper lfcHelper;\
   lfcHelper.doLog = MSF_LogFcDoLog;\
   if(lfcHelper.doLog) { logFuncCallBegin(&lfcHelper, #p); }

   #define MSF_LOG_FC_PRE_IMPL\
   if(lfcHelper.doLog) { logFuncCallPreCall(&lfcHelper); }

   #define MSF_LOG_FC_END\
   if(lfcHelper.doLog) { logFuncCallEnd(&lfcHelper); }


   #define MSF_LOG_FC_UINT8(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallUint8(&lfcHelper, #p, &p, pArrayDescr); } 
   #define MSF_LOG_FC_UINT16(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallUint16(&lfcHelper, #p, &p, pArrayDescr); } 
   #define MSF_LOG_FC_UINT32(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallUint32(&lfcHelper, #p, &p, pArrayDescr); } 
   #define MSF_LOG_FC_INT8(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallInt8(&lfcHelper, #p, &p, pArrayDescr); } 
   #define MSF_LOG_FC_INT16(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallInt16(&lfcHelper, #p, &p, pArrayDescr); } 
   #define MSF_LOG_FC_INT32(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallInt32(&lfcHelper, #p, (MSF_INT32*)(&p), sizeof(p), pArrayDescr); } 
   #define MSF_LOG_FC_INT(p, pArrayDescr)    if(lfcHelper.doLog) { logFuncCallInt32(&lfcHelper, #p, (MSF_INT32*)(&p), sizeof(p), pArrayDescr); } 
   #define MSF_LOG_FC_STRING(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallString(&lfcHelper, #p, p, pArrayDescr); }
   #define MSF_LOG_FC_BYTES(p,l, pArrayDescr) if(lfcHelper.doLog) { logFuncCallBytes(&lfcHelper, #p, (unsigned char*)p, l, pArrayDescr); }
   #define MSF_LOG_FC_PTR(p, pArrayDescr) if(lfcHelper.doLog) { logFuncCallPtr(&lfcHelper, #p, (void**)&p, pArrayDescr); }
#else
   #define MSF_LOG_FC_PARAMS_DECLARE 
   #define MSF_LOG_FC_PARAMS_IMPLEMENT 
   #define MSF_LOG_FC_DISPATCH_MAP_DECLARE(modName)
   #define MSF_LOG_FC_DISPATCH_MAP_FUNC_PTR(modName) NULL
   #define MSF_LOG_FC_DISPATCH_MAP_BEGIN(modName) 
   #define MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(fName) 
   #define MSF_LOG_FC_DISPATCH_MAP_ENTRY_END 
   #define MSF_LOG_FC_DISPATCH_MAP_SUB_DISPATCH_MAP(fName)
   #define MSF_LOG_FC_DISPATCH_MAP_END
   #define MSF_LOG_FC_BEGIN(p)
   #define MSF_LOG_FC_PRE_IMPL
   #define MSF_LOG_FC_END
   #define MSF_LOG_FC_UINT8(p, pArrayDescr) 
   #define MSF_LOG_FC_UINT16(p, pArrayDescr) 
   #define MSF_LOG_FC_UINT32(p, pArrayDescr) 
   #define MSF_LOG_FC_INT8(p, pArrayDescr) 
   #define MSF_LOG_FC_INT16(p, pArrayDescr) 
   #define MSF_LOG_FC_INT32(p, pArrayDescr) 
   #define MSF_LOG_FC_INT(p, pArrayDescr) 
   #define MSF_LOG_FC_STRING(p, pArrayDescr)
   #define MSF_LOG_FC_BYTES(p,l, pArrayDescr)
   #define MSF_LOG_FC_PTR(p, pArrayDescr) 
#endif

#endif /*_MSF_LOG_H*/
