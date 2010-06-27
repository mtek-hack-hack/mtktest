/***********************************************
File name : MTPNP_AD_common_def.h
Contents : MTPNP AD main define
History : Create by : Zhang Nan, Feb 26, 2007
************************************************/
#ifndef __MTPNP_AD_SLAVE_COMMON_DEFINE_H__
#define __MTPNP_AD_SLAVE_COMMON_DEFINE_H__

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_PFAL_Gemini_Def.h"
#else
#include "MTPNP_PFAL_slave_Def.h"
#endif
#include "MTPNP_AD_common_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define SLAVE_NETWORK_ID_LEN 6
#define MTPNP_MAX_IP_NUMBER_LEN   10
#define MTPNP_AD_SMS_INVALID_INDEX	0xffff
/*
* cc marco
*/
#define MTPNP_AD_INVALID_CALL_HANDLE   0xFF
#define MTPNP_AD_CC_HANDLE_2ND_INCOMING 0xE0    /* the low half byte is the call id to splict */
#define MTPNP_AD_SPEECH_MODE_NORMAL   1 /*normal mode */
#define MTPNP_AD_SPEECH_MODE_HEADSET   2        /* eatphone mode */
#define MTPNP_AD_SPEECH_MODE_HANDFREE   3       /* loudspeaker mode */
#define MTPNP_AD_SPEECH_MODE_BT_NORMAL   4      //Normal Bt Speech
#define MTPNP_AD_SPEECH_MODE_BT_RESUME   5      //resume Bt Speech
#define MTPNP_AD_SPEECH_MODE_STOP   6      //stop dsp for speech
/*
 * call History
*/
#define MTPNP_PFAL_MAX_CALLHISTORY_ENTRY  MAX_PHB_LN_ENTRY
/*
*phonebook
*/

#define MTPNP_AD_PB_SIM_MAXNAMELEN	14      //MTK UI SUPPORT
#define MTPNP_AD_PB_SIM_MAXNUMLEN	40      //MTK UI SUPPORT

#define MTPNP_AD_MAX_PLMN_LIST_LEN 16

typedef void (*MTPNP_EVENTHANDLER_FuncPtr) (void *);
typedef void (*MTPNP_CDT_FuncPtr) (void *, MTPNP_UINT32);
typedef void (*MTPNP_VEINT_FuncPtr) (MTPNP_UINT8);

typedef enum
{
    MTPNP_AD_CHV_RETRY_ALLOW = 0,
    MTPNP_AD_CHV_VERIFIED,
    MTPNP_AD_CHV_DISABLED,
    MTPNP_AD_CHV_BLOCKED,
    MTPNP_AD_CHV_DEAD,
    MTPNP_AD_CHV_INVALID_TYPE,
    MTPNP_AD_CHV_NOTINITED
} E_MTPNP_AD_CHV_STATUS;

typedef enum
{
    MTPNP_AD_SMU_VERIFY = 0,
    MTPNP_AD_SMU_DISABLE,
    MTPNP_AD_SMU_ENABLE,
    MTPNP_AD_SMU_CHANGE,
    MTPNP_AD_SMU_UNBLOCK
} E_MTPNP_AD_SMU_OPERATION;

typedef enum
{
    MTPNP_AD_CLIR_INVOKE,
    MTPNP_AD_CLIR_SUPPRESS,
    MTPNP_AD_CLIR_AUTO
} E_MTPNP_AD_CLIR;

typedef enum
{
    SLAVE_REL_HELD_OR_UDUB,     /*0 */
    SLAVE_REL_ACTIVE_AND_ACCEPT,        /*1 */
    SLAVE_REL_SPECIFIC_CALL,    /*2 */
    SLAVE_HOLD_ACTIVE_AND_ACCEPT,       /*3 */
    SLAVE_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL,     /*4 */
    SLAVE_ADD_HELD_CALL,        /*5 */
    SLAVE_EXPLICIT_CALL_TRANSFER,       /*6 */
    SLAVE_ACTIVATE_CCBS_CALL,   /*7 */
    SLAVE_REL_ALL_EXCEPT_WAITING_CALL,  /*8 */
    SLAVE_REL_SPECIFIC_ACTIVE_CALL,     /* 9 */
    SLAVE_SWAP_CALL,            /* 10 */
    SLAVE_REL_HELD,             /* 11 */
    SLAVE_REL_ACTIVE,           /* 12 */
    SLAVE_REL_ALL,              /* 13 */
    SLAVE_REL_ACTIVE_AND_RETRIEVE,        /*14 */
    SLAVE_INVALID_CRSS_TYPE = 255
} SLAVE_CHLD_TYPE_ENUM;

 /*ADN*/ typedef enum
{
    SLAVE_PHB_OP_NONE = 0,
    SLAVE_PHB_OP_READALL,
    SLAVE_PHB_OP_EDIT,
    SLAVE_PHB_OP_DEL,
    SLAVE_PHB_OP_DELALL
} SLAVE_ADN_OP_TYPE;

/* mercury resource define */

typedef struct
{
    MTPNP_UINT8 QOS_min_lvl;
    MTPNP_UINT8 QOS_max_lvl;
} ST_MTPNP_QOS_LEVEL;

typedef struct
{
    E_MTPNP_SLAVE_STARTUP_MODE card2_startup_mode;
    E_MTPNP_AD_POWERON_MODE card2_poweron_mode;
} ST_MTPNP_AD_STARTUP_STATUS;


typedef struct
{
    MTPNP_UINT8 chv1_count;
    MTPNP_UINT8 chv2_count;
    MTPNP_UINT8 ubchv1_count;
    MTPNP_UINT8 ubchv2_count;
    MTPNP_BOOL is_chv1_enabled;
    MTPNP_BOOL is_chv1_verified;
    E_MTPNP_AD_SMU_OPERATION smu_status;
    E_MTPNP_AD_CHV_STATUS chv_status;
    MTPNP_UINT8 CurrentPassword;
} ST_SIM_CHV_INFO;

#ifdef __cplusplus
}
#endif

#endif // __MTPNP_AD_SLAVE_COMMON_DEFINE_H__
