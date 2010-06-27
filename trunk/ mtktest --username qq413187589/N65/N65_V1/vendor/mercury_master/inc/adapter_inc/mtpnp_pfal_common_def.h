/***********************************************
File name : MTPNP_PFAL_Def.h
Contents : the definition of platform abstract layer
History : Create by : Zhang Nan, Mar 3, 2007
************************************************/
#ifndef __MTPNP_PFAL_COMMON_DEF_H__
#define __MTPNP_PFAL_COMMON_DEF_H__
#include "MTPNP_SDK_common_if.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define MTPNP_ZERO		0
#define GSM_ADDR_LEN	41
#define GSM_SMS_SEG_LEN	160
#define MTPNP_AD_EF_ZERO_DEFAULT		0x00
#define MTPNP_AD_EF_FF_DEFAULT		0xFF


typedef void (*MTPNP_AD_FuncPtr) (void);
typedef void (*MTPNP_AD_FuncPtrShort) (MTPNP_UINT16);
typedef void (*MTPNP_AD_TimerFuncPtr) (void *);

/*#if defined(WIN32)
#pragma pack(push)
#pragma pack(4)
#endif*/ /* WIN32 */
#ifndef MTPNP_LOCAL_PARA_HDR
#define MTPNP_LOCAL_PARA_HDR MTPNP_UINT8 ref_count;\
						MTPNP_UINT16 msg_len;
#endif

#ifndef MTPNP_PEER_BUFF_HDR
#define MTPNP_PEER_BUFF_HDR \
   MTPNP_UINT16	pdu_len; \
   MTPNP_UINT8	ref_count; \
   MTPNP_UINT8   	pb_resvered; \
   MTPNP_UINT16	free_header_space; \
   MTPNP_UINT16	free_tail_space;
#endif
/*
* MTK platform define number charset
*/
typedef enum
{
    MTPNP_PFAL_NCS_BCD = 0x01,
    MTPNP_PFAL_NCS_ASCII = 0x04,
    MTPNP_PFAL_NCS_UCS2 = 0x08
} E_MTPNP_PFAL_NUMBER_CHARSET;

typedef struct
{
MTPNP_LOCAL_PARA_HDR} ST_LOCAL_DATA;

typedef struct
{
MTPNP_PEER_BUFF_HDR} ST_PEER_BUFF;

typedef struct
{
    MTPNP_UINT32 src_mod_id;
    MTPNP_UINT32 dest_mod_id;
    MTPNP_UINT32 msg_id;
    MTPNP_UINT32 sap_id;
    ST_LOCAL_DATA *local_para_ptr;
    ST_PEER_BUFF *peer_buff_ptr;
} ST_ILM;

typedef struct
{
    MTPNP_LOCAL_PARA_HDR 
    MTPNP_UCHAR MTPNP_Data[1];
} ST_MTPNP_SDK_MSG_REQ;

typedef struct
{
    MTPNP_LOCAL_PARA_HDR
    MTPNP_UINT32 pDll;
} ST_MTPNP_DLLTASK_EVENT;



/*#if defined(WIN32)
#pragma pack(pop)
#endif*/ /* WIN32 */

#ifdef __cplusplus
}
#endif
#endif // __MTPNP_PFAL_COMMON_DEF_H__
