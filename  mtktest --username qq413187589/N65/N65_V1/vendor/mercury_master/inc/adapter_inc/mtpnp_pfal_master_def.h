/***********************************************
File name : MTPNP_PFAL_Def.h
Contents : the definition of platform abstract layer
History : Create by : Zhang Nan, Mar 3, 2007
************************************************/
#ifndef __MTPNP_PFAL_MASTER_DEF_H__
#define __MTPNP_PFAL_MASTER_DEF_H__

#include "MTPNP_SDK_common_if.h"
#include "MTPNP_PFAL_Common_Def.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef enum
{
    RECVD_COUNT = 0,
    SENT_COUNT
} E_MTPNP_PFAL_SMS_HISTORY;

typedef enum
{
    MTPNP_PFAL_BIG_5_ENCODING,
    MTPNP_PFAL_GB2312_ENCODING,
    MTPNP_PFAL_NO_OF_TEXT_ENCODING
} E_MTPNP_PFAL_TEXT_ENCODING;

typedef enum
{
    PFAL_BYTE = 1,
    PFAL_SHORT = 2,
    PFAL_DOUBLE = 8
} E_NVRAM_DATASIZE;

typedef enum
{
    MTPNP_AD_NVRAM_DUALCARD = 0,
    MTPNP_AD_NVRAM_CARD1,
    MTPNP_AD_NVRAM_CARD2,
    MTPNP_AD_NVRAM_FLIGHT,
    MTPNP_AD_NVRAM_QUERY,

    MTPNP_AD_NVRAM_NONE,
    MTPNP_AD_NVRAM_MAX = MTPNP_AD_NVRAM_NONE
} E_MTPNP_AD_NVRAM_STATUS;

typedef enum
{
    MTPNP_AD_SETTING_TYPE_CHV1,
    MTPNP_AD_SETTING_TYPE_UBCHV1,
    MTPNP_AD_SETTING_TYPE_CHV2,
    MTPNP_AD_SETTING_TYPE_UBCHV2
} E_MTPNP_AD_SECURITYTYPE;

/* sms show begin */
typedef enum
{
    MTPNP_AD_FILTER_ALL,
    MTPNP_AD_FILTER_MASTER,
    MTPNP_AD_FILTER_SLAVE
} E_MTPNP_AD_FILTER_RULE;

typedef enum
{
    MTPNP_AD_SHOW_MIXED,
    MTPNP_AD_SHOW_DIVIDED
} E_MTPNP_AD_SHOW_STYLE;
/* sms show end */

typedef struct
{
    MTPNP_UINT16 menuId;
    MTPNP_UINT16 strId;         /* single card stringid */
    MTPNP_UINT16 strDMId;       /* dual card stirng id */
#if 0
/* under construction !*/
/* under construction !*/
#endif
} ST_MTPNP_AD_MENU;

typedef struct
{
    MTPNP_UINT8 type;
    MTPNP_UINT8 length;
    MTPNP_UINT8 number[GSM_ADDR_LEN];
} ST_MTPNP_PFAL_ADDR;

/*#if defined(WIN32)
#pragma pack(pop)
#endif*/ /* WIN32 */

#ifdef __cplusplus
}
#endif

#endif // __MTPNP_PFAL_MASTER_DEF_H__
