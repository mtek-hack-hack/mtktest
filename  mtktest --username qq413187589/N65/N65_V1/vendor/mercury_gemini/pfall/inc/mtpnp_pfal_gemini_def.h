/***********************************************
File name : MTPNP_PFAL_Def.h
Contents : the definition of platform abstract layer
History : Create by : Zhang Nan, Mar 3, 2007
************************************************/
#ifndef __MTPNP_PFAL_SLAVE_DEF_H__
#define __MTPNP_PFAL_SLAVE_DEF_H__

#include "MTPNP_SDK_common_if.h"
#include "MTPNP_PFAL_Common_Def.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* MDV message queue structure */
typedef struct
{
    MTPNP_UINT32 dwMsgID;
    MTPNP_UINT32 dwSeqID;       /* Ask a command sequence ID then fill out this variable when issue a REQ command */
    MTPNP_UINT32 dwStsID;       /* Returned status */
} ST_ALHDR;

typedef struct
{
    ST_ALHDR al_hdr;
    MTPNP_UINT32 pDll;
} ST_MTPNP_DLLTASK_EVENT_EX1;

typedef struct
{
    ST_ALHDR al_hdr;
    MTPNP_UCHAR MTPNP_Data[1];
} ST_MTPNP_SDK_MSG_REQ_EX1;

typedef struct
{
    ST_ALHDR al_hdr;
    void *pLocalbuf;
} ST_MTPNP_COMM_DATA_EX1;

typedef struct
{
    MTPNP_UINT8 bDestTask;
    MTPNP_UINT8 bSrcTask;
    MTPNP_UINT8 bEvtID;
    MTPNP_UINT8 bSystem;
    void *pDataPtr;
    MTPNP_UINT16 wDataLen;
    MTPNP_UINT8 bPadding1;
    MTPNP_UINT8 bPadding2;
    MTPNP_UINT8 bPadding3;
    MTPNP_UINT8 bPadding4;
    MTPNP_UINT8 bPadding5;
    MTPNP_UINT8 bPadding6;
} ST_ILM_EX1;
/* MDV message queue structure */

/*#if defined(WIN32)
#pragma pack(pop)
#endif*/ /* WIN32 */

#ifdef __cplusplus
}
#endif

#endif // __MTPNP_PFAL_SLAVE_DEF_H__
