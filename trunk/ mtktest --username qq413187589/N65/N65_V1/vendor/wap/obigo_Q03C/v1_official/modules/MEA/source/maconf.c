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

/* MSF */
#include "msf_core.h"
#include "msf_log.h"
#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_def.h"
#include "msf_mem.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_url.h"
#include "msf_cmmn.h"

/* STK */
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */

/* MMS */
#include "mms_def.h"
#ifdef WAP_SUPPORT
#include "mms_cfg.h" //for MMS_DEFAULT_MAX_MSG_SIZE
#endif /* WAP_SUPPORT */

/* MEA */
#include "mea_def.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "mea_rc.h"
#include "maintsig.h"
#include "macore.h"
#include "maintsig.h"
#include "maconf.h"
#include "mauiconf.h"
#include "mauicmn.h"
#include "mamem.h"
#include "mauidia.h"
#include "mamh.h"

#ifdef WAP_SUPPORT
#include "msm.h"  /* msm_get_module_status() */
#include "msf_file.h"  //for MSF_FILE_SET_RDONLY
/* Widget */
#include "kal_release.h"
#include "widget_extension.h"
/* BRA */
#include "bra_prof.h" //for BRA_PROF_ID_CMN

extern void meaConfigInlineMenuSave(ctk_screen_handle scrid);
extern void meaConfigInlineMenuCancel(ctk_screen_handle scrId);
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
#endif /* WAP_SUPPORT */
/*! \file maconf.c
 *! \brief The configuration logic.
 */

#ifdef WAP_SUPPORT
/******************************************************************************
 * Data-types
 *****************************************************************************/
typedef struct 
{
    const char            *asString;
    const MeaConfigNetwork asInteger;
}MeaConfType;
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Structures
 *****************************************************************************/

typedef enum
{
    MEA_CONF_S_UNINITIALIZED,   /*<! Mea config is uninitialized */
    MEA_CONF_S_INITIALIZED      /*<! Mea config is initialized */
}MeaConfState;

typedef struct {
    MeaStateMachine fsm;    /*<! Callback fsm for external requests */
    int             signal; /*<! Callback signal for external requests */
    MeaConfState    state;  /*<! The state of MeaConf */
}MeaConfInstance;

typedef enum
{
    MEA_PRS_KEY_MMSC_URL,
    MEA_PRS_KEY_NET_CONNECTION_TYPE,
    MEA_PRS_KEY_NETWORK_ACCOUNT_ID,
    MEA_PRS_KEY_WAP_GW,
    MEA_PRS_KEY_LOGIN,
    MEA_PRS_KEY_PASSWORD,
    MEA_PRS_KEY_HTTP_PORT
}MeaPrsKeyId;

#ifndef WAP_SUPPORT
typedef enum
{
    MEA_PRS_KEY_CLEANSE_YES,
    MEA_PRS_KEY_CLEANSE_NO,
}MeaPrsKeyCleanse;

typedef struct 
{
    char                *prsStr;    /*!< Received string from PRS */
    MeaPrsKeyId         keyId;      /*!< string/path/key combo identifier */
    MeaConfigNetwork    groupId;    /*!< Network group id */
    MeaPrsKeyCleanse    cleanse;    /*!< Whether to clear when receiving 
                                         provisioned settings */
}MeaPrsKeyTable;

/*
 *	Received string from PRS, enumerating identifier, network group
 */
#define MEA_PRS_KEYS {\
{"mmsc_url",       MEA_PRS_KEY_MMSC_URL,            -1,                     MEA_PRS_KEY_CLEANSE_NO},\
{"px_type",        MEA_PRS_KEY_NET_CONNECTION_TYPE, MEA_CONFIG_CONN_TYPE,   MEA_PRS_KEY_CLEANSE_NO},\
{"net_account_id", MEA_PRS_KEY_NETWORK_ACCOUNT_ID,  MEA_CONFIG_NET_ACCOUNT, MEA_PRS_KEY_CLEANSE_NO},\
{"px_address",     MEA_PRS_KEY_WAP_GW,              MEA_CONFIG_WAP_GW,      MEA_PRS_KEY_CLEANSE_YES},\
{"px_auth_name",   MEA_PRS_KEY_LOGIN,               MEA_CONFIG_LOGIN,       MEA_PRS_KEY_CLEANSE_YES},\
{"px_auth_secret", MEA_PRS_KEY_PASSWORD,            MEA_CONFIG_PASSWD,      MEA_PRS_KEY_CLEANSE_YES},\
{"px_port",        MEA_PRS_KEY_HTTP_PORT,           MEA_CONFIG_HTTP_PORT,   MEA_PRS_KEY_CLEANSE_YES},\
{NULL, 0,0}}
#endif /* ~WAP_SUPPORT */

/* Configuration IDs */
/*lint -e{751} */
typedef enum
{
    GET_CONFIG_UNDEFINED,
    GET_CONFIG_ADDRESS,
    GET_CONFIG_MMSC,
    GET_CONFIG_IM_RETR,
    GET_CONFIG_RETR,
    GET_CONFIG_STK,
    GET_CONFIG_COM_GW,
    GET_CONFIG_ADDITIONAL,
    GET_CONFIG_EXTERNAL,
    GET_CONFIG_NETWORK_STATUS,
    GET_CONFIG_REPORT,
    GET_CONFIG_COUNT
}ConfigGroups;

/******************************************************************************
 * Macros
 *****************************************************************************/

/* Validate port number */
#define VALIDATE_PORT(p) ( (p >= MEA_CFG_MIN_PORT) && ( p <= MEA_CFG_MAX_PORT))

/******************************************************************************
 * Constants 
 *****************************************************************************/

static char configRegistryGroup[GET_CONFIG_COUNT][30] =
{
    "",
    MMS_REG_PATH_ADDRESS,
    MMS_REG_PATH_COM_MMSC,
    MMS_REG_PATH_IMMEDIATE_RETRIEVAL,
    MMS_REG_PATH_RETRIEVAL,
    MMS_REG_PATH_COM_STK,
    MMS_REG_PATH_COM_GW,
    MEA_REG_PATH_MMS,
    MEA_REG_PATH_EXT,
    MMS_REG_PATH_NETWORK_STATUS,
    MMS_REG_PATH_REPORT
};

#ifdef WAP_SUPPORT
static const MeaConfType confType[] = 
	{
	  {MMS_REG_KEY_NETWORK_ACCOUNT, MEA_CONFIG_NET_ACCOUNT},     
	  {MMS_REG_KEY_STK_CONNECTION_TYPE, MEA_CONFIG_CONN_TYPE},       
	  {MMS_REG_KEY_GW_ADDRESS,     MEA_CONFIG_WAP_GW},       
	  {MMS_REG_KEY_GW_PASSWORD,    MEA_CONFIG_PASSWD},   
	  {MMS_REG_KEY_GW_HTTP_PORT,   MEA_CONFIG_HTTP_PORT},       
	  {MMS_REG_KEY_GW_REALM,       MEA_CONFIG_REALM},       
	  {MMS_REG_KEY_GW_SECURE_PORT, MEA_CONFIG_SEC_PORT},
	  {MMS_REG_KEY_GW_USERNAME,    MEA_CONFIG_LOGIN},
#ifdef __MMS_DUAL_SIM_SUPPORT__    
      {MMS_REG_KEY_SLAVE_SIM_NETWORK_ACCOUNT, MEA_CONFIG_SLAVE_NET_ACCOUNT},     
      {MMS_REG_KEY_SLAVE_SIM_STK_CONNECTION_TYPE, MEA_CONFIG_SLAVE_CONN_TYPE},       
      {MMS_REG_KEY_SLAVE_SIM_GW_ADDRESS,     MEA_CONFIG_SLAVE_WAP_GW},       
      {MMS_REG_KEY_SLAVE_SIM_GW_PASSWORD,    MEA_CONFIG_SLAVE_PASSWD},   
      {MMS_REG_KEY_SLAVE_SIM_GW_HTTP_PORT,   MEA_CONFIG_SLAVE_HTTP_PORT},       
      {MMS_REG_KEY_SLAVE_SIM_GW_REALM,       MEA_CONFIG_SLAVE_REALM},       
      {MMS_REG_KEY_SLAVE_SIM_GW_SECURE_PORT, MEA_CONFIG_SLAVE_SEC_PORT},
      {MMS_REG_KEY_SLAVE_SIM_GW_USERNAME,    MEA_CONFIG_SLAVE_LOGIN},
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
	};

static MeaCreationModeType confCreationMode = MEA_CREATION_MODE_FREE;
  #ifdef JPG_ENCODE
static MeaImageResizeType confImageResize = MEA_IMAGE_RESIZE_160x120;
  #endif
#else /* WAP_SUPPORT */
static const MeaPrsKeyTable prsKeys[] = MEA_PRS_KEYS;

#endif /* WAP_SUPPORT */
/******************************************************************************
 * Global variables 
 *****************************************************************************/


static MeaConfig config; /*!<Global configuration data  */
static MeaConfInstance *confInstance; /*!< Global instance */

static msf_scheme_t suppSchemes[] = {msf_scheme_http,
    msf_scheme_https, (msf_scheme_t)0}; /*MEA_SUPPORTED_COMM_SCHEMES*/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

static void handleGetRegRsp(MeaConfInstance *inst, MeaConfig *conf, 
                            msf_registry_response_t *reg);
static void meaClearConfig(MeaConfig *conf);
static void meaConfig(MeaSignal *sig);
static void readRegistry(void);
static void getNetworkStatus(MeaConfInstance *inst, MeaStateMachine fsm, 
    int signal);
#ifdef __MMS_DUAL_SIM_SUPPORT__
static int  saveSettings(MmsSimCardEnum simId, const MeaConfig *tmpConfig, MeaConfigGroups group);
#else
static int  saveSettings(const MeaConfig *tmpConfig, MeaConfigGroups group);
#endif
static MSF_BOOL saveNetworkSettings(const MeaConfig *tmpConfig, 
                                    MeaConfigNetwork group);
static int saveImRetrSettings(const MeaConfig *tmpConfig, MeaConfigFilter group);
static int saveMsgSendSettings(const MeaConfig *tmpConfig,MeaConfigSend group);
static int saveMsgReplyChargingSettings(const MeaConfig *tmpConfig,
                                        MeaConfigReplyCharging group);
static MSF_BOOL setParamInt(const msf_registry_param_t *param, const char *key, 
    int *dest);
static MSF_BOOL setParamStr(const msf_registry_param_t *param, const char *key, 
    char **dest);
static void setRegStr(char *str, void *handle, const char *key);
static void setDstStr(char **dst, char *src);
static void deleteConfInstance(MeaConfInstance **instance);
static MSF_BOOL saveRetrievalSettings(const MeaConfig *tmpConfig, 
    MeaConfigRetrieve item);

static void meaConfSetCreationMode(MeaCreationModeType mode);
#ifdef JPG_ENCODE
static void meaConfSetImageResize(MeaImageResizeType irType);
#endif
static MSF_BOOL meaWriteSignatureFile(int isOn, char* content);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Initiates the MEA Config FSM by registering a signalhandler
 *****************************************************************************/
void meaConfInit(void)
{
    meaClearConfig(meaGetConfig());
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MACONF_3CF11884A780FABC0A5C842DFC1FC33E, "meaConfigInit()\n"));
    meaSignalRegisterDst(MEA_CONFIG_FSM, meaConfig); /* set sig-handler */
}

/*!
 * \brief Terminates the MEA Config FSM
 *****************************************************************************/
void meaConfTerminate(void)
{
    meaSignalDeregister(MEA_CONFIG_FSM); /* remove sig-handler */
    deleteConfInstance(&confInstance);
    meaClearConfig(meaGetConfig());
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MACONF_072B27D060E93DBB99282F6A33C487DE, "meaConfTerminate()\n"));
#ifdef WAP_SUPPORT
    meaDeleteConfMemoryStatusView();
    meaDeleteConfComposeView();
#endif /* WAP_SUPPORT */
}

/*!
 * \brief Initiates an instance
 * \param The instance to initiate
 *****************************************************************************/
static void initConfInstance(MeaConfInstance **instance)
{
    *instance = MEA_ALLOC(sizeof(MeaConfInstance));
    /* Clear the structure */
    memset(*instance, 0, sizeof(MeaConfInstance));
    (*instance)->state = MEA_CONF_S_UNINITIALIZED;
}

/*!
 * \brief Deletes an instance
 * \param The instance to delete
 *****************************************************************************/
static void deleteConfInstance(MeaConfInstance **instance)
{
    MeaConfInstance *inst;
    
    if (*instance != NULL)
    {
        inst = *instance;

        MEA_FREE(inst);
        *instance = NULL;
    }
}

/*!
 * \brief Handles the response when getting configuration from the registry.
 *
 * \param conf The configuration struct to add the received settings to. 
 * \param req  The registry response from MSF registry.
 *
 *****************************************************************************/

static void handleGetRegRsp(MeaConfInstance *inst, MeaConfig *conf, 
                            msf_registry_response_t *reg)
{
    msf_registry_param_t  param;
    int stkConnectionType;
    void *setHandle;
    int tmpInt;
    MSF_BOOL valueSet;
    
    switch(reg->id)
    {
    case GET_CONFIG_UNDEFINED:
        /* Someone outside the MEA application has updated the registry */
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            /* CR12706. Manually updating MMSC version in MEA registry. */
            if (!msf_cmmn_strcmp_nc(param.path, MEA_REG_PATH_MMS) && 
                !msf_cmmn_strcmp_nc(param.key, MEA_REG_KEY_MMSC_VERSION)) 
            {
                if (MMS_VERSION_10 == param.value_i ||
                    MMS_VERSION_11 == param.value_i) 
                {
                    /* Write the new version value to registry */
                    setHandle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
                    MSF_REGISTRY_SET_PATH(setHandle, (char *)MMS_REG_PATH_COM_MMSC);
                    MSF_REGISTRY_SET_ADD_KEY_INT(setHandle, 
                        (char *)MMS_REG_KEY_PROXY_RELAY_VERSION, param.value_i);
                    MSF_REGISTRY_SET_COMMIT(setHandle);        
                    /* Save the new value in the config variables */
                    conf->proxyVersion = (MmsVersion)param.value_i;
                }
                continue;
            }
        }
        break;
    case GET_CONFIG_ADDRESS:
        /* Address */
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (setParamInt(&param, MMS_REG_KEY_FROM_ADDRESS_TYPE, &tmpInt))
            {
                conf->addressType = (MmsAddressType)tmpInt;
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_FROM_NAME, 
                    &(conf->fromName)))
            {
                continue;
            }
        }
        break;
    case GET_CONFIG_IM_RETR:
        valueSet = FALSE;
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (setParamInt(&param, MMS_REG_KEY_IMMEDIATE_RETRIEVAL, &tmpInt))
            {
#ifdef WAP_SUPPORT
                if (0 == tmpInt || 1 == tmpInt)
                    conf->retrievalMode  = tmpInt;
                else
                    conf->retrievalMode  = MEA_RETRIEVAL_MODE_RESTRICTED;                    
#else
                conf->retrievalMode  = (TRUE == tmpInt)
                    ? MEA_RETRIEVAL_MODE_AUTOMATIC
                    : MEA_RETRIEVAL_MODE_ALWAYS_ASK;
#endif /* WAP_SUPPORT */
                valueSet = TRUE;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_MAX_SIZE_OF_MSG, &tmpInt))
            {
                conf->maxMsgSize = (unsigned int)tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_CLASS_PERSONAL, &tmpInt))
            {
                conf->allowPersonal = tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_CLASS_ADVERTISEMENT, &tmpInt))
            {
                conf->allowAdvert = tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_CLASS_INFORMATIONAL, &tmpInt))
            {
                conf->allowInfo = tmpInt;
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_CLASS_STRING, 
                &(conf->allowString)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_IMMEDIATE_RETRIEVAL_SERVER, 
                &(conf->imServer)))
            {
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_ANONYMOUS_SENDER, &tmpInt))
            {
                conf->allowAnonym = tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_TREAT_AS_DELAYED_RETRIEVAL, 
                &tmpInt))
            {
                conf->treatAsDel = tmpInt;
                continue;
            }            
        }
        if (!valueSet)
        {
            /* must initialize MEA and registry with default setting */
            meaGetConfig()->retrievalMode = MEA_CFG_RETRIEVAL_MODE;
            (void)saveRetrievalSettings(meaGetConfig(), MEA_CONFIG_HOME_NETWORK);
        }
        break;
    case GET_CONFIG_RETR:
        valueSet = FALSE;
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (setParamInt(&param, MMS_REG_KEY_MAX_RETRIEVAL_SIZE, &tmpInt))
            {
                conf->maxRetrSize = (unsigned int)tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_RETRIEVAL_ROAM_MODE, &tmpInt))
            {
                conf->retrievalModeRoam = (MMS_ROAM_DEFAULT == tmpInt)
                    ? MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC
                    : (MMS_ROAM_DELAYED == tmpInt)
                    ? MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK
                    : MEA_RETRIEVAL_MODE_ROAMING_RESTRICTED;
                valueSet = TRUE;
                continue;
            }
        }
        if (!valueSet)
        {
            /* must initialize MEA and registry with default setting */
            meaGetConfig()->retrievalModeRoam = 
                MEA_CFG_RETRIEVAL_MODE_ROAMING;
            (void)saveRetrievalSettings(meaGetConfig(), MEA_CONFIG_ROAM_NETWORK);
        }

        break;
    case GET_CONFIG_MMSC:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (setParamStr(&param, MMS_REG_KEY_PROXY_RELAY, 
                    &(conf->proxyHost)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_POST_URI, 
                    &(conf->proxyUri)))
            {
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_PORT, &tmpInt))
            {
                conf->proxyPort = (unsigned int)tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_PROXY_RELAY_VERSION, &tmpInt))
            {
                conf->proxyVersion = (MmsVersion)tmpInt;
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_PROXY_RELAY_SCHEME, 
                    &(conf->proxyScheme)))
            {
                continue;
            }
#ifdef __MMS_DUAL_SIM_SUPPORT__
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY, 
                    &(conf->slaveProxyHost)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_POST_URI, 
                    &(conf->slaveProxyUri)))
            {
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_PORT, &tmpInt))
            {
                conf->slaveProxyPort = (unsigned int)tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY_VERSION, &tmpInt))
            {
                conf->slaveProxyVersion = (MmsVersion)tmpInt;
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY_SCHEME, 
                    &(conf->slaveProxyScheme)))
            {
                continue;
            }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        }
        break;
    case GET_CONFIG_STK:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {

            if (setParamInt(&param, MMS_REG_KEY_NETWORK_ACCOUNT, &tmpInt))
            {
                conf->networkAccount= tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_STK_CONNECTION_TYPE, &tmpInt))
            {
                stkConnectionType = tmpInt;
                /* Convert connection type */
                switch (stkConnectionType)
                {
                case STK_CONNECTION_TYPE_HTTP:
                    conf->connectionType = MEA_CONNECTION_TYPE_HTTP;
                    break;
                case STK_CONNECTION_TYPE_WSP_CO:
                    conf->connectionType = MEA_CONNECTION_TYPE_WSP_CO;
                    break;
                case STK_CONNECTION_TYPE_WSP_CL:
                    conf->connectionType = MEA_CONNECTION_TYPE_WSP_CL;
                    break;
                }
                continue;
            }
#ifdef __MMS_DUAL_SIM_SUPPORT__
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_NETWORK_ACCOUNT, &tmpInt))
            {
                conf->slaveNetworkAccount= tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_STK_CONNECTION_TYPE, &tmpInt))
            {
                stkConnectionType = tmpInt;
                /* Convert connection type */
                switch (stkConnectionType)
                {
                case STK_CONNECTION_TYPE_HTTP:
                    conf->slaveConnectionType = MEA_CONNECTION_TYPE_HTTP;
                    break;
                case STK_CONNECTION_TYPE_WSP_CO:
                    conf->slaveConnectionType = MEA_CONNECTION_TYPE_WSP_CO;
                    break;
                case STK_CONNECTION_TYPE_WSP_CL:
                    conf->slaveConnectionType = MEA_CONNECTION_TYPE_WSP_CL;
                    break;
                }
                continue;
            }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        }
        break;
    case GET_CONFIG_COM_GW:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (setParamStr(&param, MMS_REG_KEY_GW_ADDRESS, 
                    &(conf->wapGateway)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_GW_USERNAME, 
                    &(conf->login)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_GW_PASSWORD, 
                    &(conf->passwd)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_GW_REALM, 
                    &(conf->realm)))
            {
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_GW_SECURE_PORT, &tmpInt))
            {
                conf->securePort= (unsigned int)tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_GW_HTTP_PORT, &tmpInt))
            {
                conf->httpPort = (unsigned int)tmpInt;
                continue;
            }
#ifdef __MMS_DUAL_SIM_SUPPORT__
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_GW_ADDRESS, 
                    &(conf->slaveWapGateway)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_GW_USERNAME, 
                    &(conf->slaveLogin)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_GW_PASSWORD, 
                    &(conf->slavePasswd)))
            {
                continue;
            }
            if (setParamStr(&param, MMS_REG_KEY_SLAVE_SIM_GW_REALM, 
                    &(conf->slaveRealm)))
            {
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_GW_SECURE_PORT, &tmpInt))
            {
                conf->slaveSecurePort= (unsigned int)tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_GW_HTTP_PORT, &tmpInt))
            {
                conf->slaveHttpPort = (unsigned int)tmpInt;
                continue;
            }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        }
        break;
    case GET_CONFIG_ADDITIONAL:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (setParamInt(&param, MEA_REG_KEY_SAVE_ON_SEND, &tmpInt))
            {
                conf->saveOnSend = tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_PRIORITY, &tmpInt))
            {
                conf->priority = (MeaPriorityType)tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_EXP_TIME, &tmpInt))
            {
                conf->expiryTime = (MeaExpiryTimeType)tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_READ_REPORT, &tmpInt))
            {
                conf->readReport = tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_DELIVERY_REPORT, &tmpInt))
            {
                conf->deliveryReport= tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_SLIDE_DUR, &tmpInt))
            {
                conf->slideDuration= tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_REPLY_CHARGING, &tmpInt))
            {
                conf->replyCharging = (MeaReplyChargingType)tmpInt;
                continue;
            }
            if (setParamInt(&param, MEA_REG_KEY_REPLY_CHARGING_DEADLINE,
                &tmpInt))
            {
                conf->replyChargingDeadline = (MeaReplyChargingDeadlineType)tmpInt;
            }
            if (setParamInt(&param, MEA_REG_KEY_REPLY_CHARGING_SIZE,
                &tmpInt))
            {
                conf->replyChargingSize = (MeaReplyChargingSizeType)tmpInt;
            }

            if (setParamInt(&param, MEA_REG_KEY_SENDER_VISIBILITY, &tmpInt))
            {
                conf->senderVisibility = (MeaVisibilityType)tmpInt;
            }

            if (setParamInt(&param, MEA_REG_KEY_SEND_READ_REPORT, &tmpInt))
            {
                conf->sendReadReport = tmpInt;
            }

            if (setParamInt(&param, MEA_REG_KEY_DELIVERY_TIME, &tmpInt))
            {
                conf->deliveryTime = tmpInt;
            }

        }
        break;
    case GET_CONFIG_EXTERNAL:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param)) 
        {
            if (!msf_cmmn_strcmp_nc(param.key, MEA_REG_KEY_MSISDN))
            {
                if (param.value_bv_length > 0)
                {
                    /* There was a value in the registry => Use it */
                    MEA_FREE(conf->fromAddress);
                    conf->fromAddress = MEA_ALLOC(param.value_bv_length + 1);
                    (void)strcpy(conf->fromAddress, 
                        (const char *)param.value_bv);
                    setHandle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
                    MSF_REGISTRY_SET_PATH(setHandle, 
                        (char *)MMS_REG_PATH_ADDRESS);
                    setRegStr(conf->fromAddress, setHandle, 
                        (char *)MMS_REG_KEY_FROM_ADDRESS);
                    MSF_REGISTRY_SET_COMMIT(setHandle);                                                                        
                }
                continue;
            }
        }
        /* Check if we got any values from the registry */
#ifdef WAP_SUPPORT
        if (!conf->fromAddress || strlen(conf->fromAddress)==0)
#else
        if (!conf->fromAddress)
#endif /* WAP_SUPPORT */
        {
            /* There was no value in the registry => Use default */
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MACONF_446F7C8772A060CDE5B72A5C00658B28, "(%s) (%d) WARNING!!! MSISDN was not set in registry!\n", 
                __FILE__, __LINE__));
            conf->fromAddress = MEA_ALLOC(strlen(MEA_CFG_MSISDN) + 1);
            (void)strcpy(conf->fromAddress, MEA_CFG_MSISDN);
            setHandle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
            MSF_REGISTRY_SET_PATH(setHandle, (char *)MMS_REG_PATH_ADDRESS);
            setRegStr(conf->fromAddress, setHandle, 
                (char *)MMS_REG_KEY_FROM_ADDRESS);
            MSF_REGISTRY_SET_COMMIT(setHandle);                                
        }
        break;

    case GET_CONFIG_NETWORK_STATUS:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param))
        {
            if (setParamInt(&param, MMS_REG_KEY_NETWORK_STATUS_BEARER, &tmpInt))
            {
                conf->bearerStatus = tmpInt;
                continue;
            }
            if (setParamInt(&param, MMS_REG_KEY_NETWORK_STATUS_ROAMING, &tmpInt))
            {
                conf->roamingStatus = tmpInt;
                continue;
            }
#ifdef __MMS_DUAL_SIM_SUPPORT__
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_NETWORK_STATUS_ROAMING, &tmpInt))
            {
                conf->slaveRoamingStatus = tmpInt;
                continue;
            }            
            if (setParamInt(&param, MMS_REG_KEY_SLAVE_SIM_NETWORK_STATUS_BEARER, &tmpInt))
            {
                conf->slaveBearerStatus = tmpInt;
                continue;
            }
            
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
            
        }
        /* alert any waiting fsm that network status data have been updated */
        if (inst->fsm != MEA_NOTUSED_FSM)
        {
            (void)MEA_SIGNAL_SENDTO(inst->fsm, inst->signal);
            inst->fsm = MEA_NOTUSED_FSM;
            inst->signal = 0;
        }
        break;

    case GET_CONFIG_REPORT:
        while (MSF_REGISTRY_RESPONSE_GET_NEXT(reg, &param))
        {
            if (setParamInt(&param, MMS_REG_KEY_REPORT_ALLOWED, &tmpInt))
            {
                conf->deliveryReportAllowed = tmpInt;
            }
        }
        break;
        
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_24740BAEF94A496E24195B7534A59EEF, "(%s) (%d) erroneous config id!\n", __FILE__, __LINE__));
        break;
    }
    /* Free the response data */
    MSF_REGISTRY_RESPONSE_FREE(MSF_MODID_MEA, reg);
}

/*!
 * \brief       Clears a configuration struct
 * \param conf  Pointer to the struct to be cleared
 *****************************************************************************/
static void meaClearConfig(MeaConfig *conf)
{
    if (NULL == conf)
    {
        return;
    }
    MEA_FREE(conf->fromAddress);
    MEA_FREE(conf->fromName);
    MEA_FREE(conf->proxyHost);
    MEA_FREE(conf->proxyUri); 
    MEA_FREE(conf->proxyScheme);
    MEA_FREE(conf->wapGateway);
    MEA_FREE(conf->login);
    MEA_FREE(conf->passwd);
    MEA_FREE(conf->realm);
    MEA_FREE(conf->allowString);
    MEA_FREE(conf->imServer);
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MEA_FREE(conf->slaveProxyHost);
    MEA_FREE(conf->slaveProxyUri); 
    MEA_FREE(conf->slaveProxyScheme);
    MEA_FREE(conf->slaveWapGateway);
    MEA_FREE(conf->slaveLogin);
    MEA_FREE(conf->slavePasswd);
    MEA_FREE(conf->slaveRealm);
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    memset(conf, 0, sizeof(MeaConfig)); /* sets all pointers to NULL */
}

/*!
 * \brief Use the MEA for the schemes "mms:", "mmsto:" and "mailto:".
 *
 *****************************************************************************/
static void setContentRoutingInformation(void)
{
#ifdef MEA_CFG_CT_BROWSER_SCHEMES
    void* setHandle;
    setHandle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    MSF_REGISTRY_SET_PATH(setHandle, MEA_CR_PATH);
    MSF_REGISTRY_SET_ADD_KEY_STR(setHandle, MEA_CR_SCHEME, 
        (unsigned char *)MEA_CFG_CT_BROWSER_SCHEMES,
        sizeof(MEA_CFG_CT_BROWSER_SCHEMES));
    MSF_REGISTRY_SET_COMMIT(setHandle);
#endif
}

/*!
 * \brief Set initial MMS settings.
 *
 *****************************************************************************/
static void setMmsSettings(void)
{
    void *setHandle;
    int ver;

    /*
     *	Init non-configurable MMS registry settings.
     */
    config.addressType = MMS_PLMN;
    ver = MEA_CFG_MMSC_VERSION;
    setHandle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
#ifdef WAP_SUPPORT //for MMS may use 1.0 version
    config.proxyVersion = (MmsVersion)ver;
  #ifdef  __MMS_DUAL_SIM_SUPPORT__
    config.slaveProxyVersion = (MmsVersion)ver;
  #endif /*__MMS_DUAL_SIM_SUPPORT__*/
#else
    MSF_REGISTRY_SET_PATH(setHandle, (char *)MMS_REG_PATH_COM_MMSC);
    /*lint -e{774} */
    if (ver != MMS_VERSION_10 && ver != MMS_VERSION_11)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_DBBE2C555CEA288C8E3901D02F4CDBA4, "(%s) (%d) Erroneous MMSC version. Defaulting to 1.1!\n", 
            __FILE__, __LINE__));
        ver = MMS_VERSION_11;
    }
    MSF_REGISTRY_SET_ADD_KEY_INT(setHandle, (char*)MMS_REG_KEY_PROXY_RELAY_VERSION,
        ver);
#endif /* WAP_SUPPORT */
    MSF_REGISTRY_SET_PATH(setHandle, (char *)MMS_REG_PATH_ADDRESS);
    MSF_REGISTRY_SET_ADD_KEY_INT(setHandle, (char *)MMS_REG_KEY_FROM_ADDRESS_TYPE,
        config.addressType);
    MSF_REGISTRY_SET_PATH(setHandle, (char *)MEA_REG_PATH_MMS);
    MSF_REGISTRY_SET_ADD_KEY_INT(setHandle, (char *)MEA_REG_KEY_MMSC_VERSION,
        ver);

    /* Store in registry */
    MSF_REGISTRY_SET_COMMIT(setHandle);
    
    /*
     *	Init configurable settings.
     */
#ifdef WAP_SUPPORT
    config.deliveryReport   = (MSF_BOOL)MEA_CFG_DELIVERY_REPORT;
#else
    config.deliveryReport   = MEA_CFG_DELIVERY_REPORT;
#endif /* WAP_SUPPORT */
    config.expiryTime       = MEA_CFG_EXPIRY_TIME;
    config.priority         = MEA_CFG_PRIORITY;
    config.readReport       = (MSF_BOOL)MEA_CFG_READ_REPORT;
    config.saveOnSend       = MEA_CFG_SAVE_ON_SEND;
    config.slideDuration    = MEA_CFG_DEFAULT_DURATION/1000;
    config.allowPersonal    = MEA_CFG_ALLOW_PERSONAL;
    config.allowAdvert      = MEA_CFG_ALLOW_ADVERT;
    config.allowInfo        = MEA_CFG_ALLOW_INFO;
    config.allowAuto        = MEA_CFG_ALLOW_AUTO; 
    config.allowAnonym      = MEA_CFG_ALLOW_ANONYM;
    config.treatAsDel       = MEA_CFG_TREAT_AS_DELAYED;
    config.replyCharging    = MEA_CFG_REPLY_CHARGING;
    config.replyChargingDeadline = MEA_CFG_REPLY_CHARGING_DEADLINE;
    config.replyChargingSize = MEA_CFG_REPLY_CHARGING_SIZE;
    config.senderVisibility = MEA_CFG_SHOW_NUMBER;
    config.deliveryReportAllowed = MEA_CFG_DELIVERY_REPORT_ALLOWED;
    config.sendReadReport   = MEA_CFG_SEND_READ_REPORT;
    config.deliveryTime     = MEA_CFG_DELIVERY_TIME;

    config.allowString = (char*)MEA_ALLOC(strlen(MEA_CFG_ALLOW_STRING) + 1);
    (void)strcpy(config.allowString, MEA_CFG_ALLOW_STRING);

    config.imServer = (char*)MEA_ALLOC(strlen(MEA_CFG_IM_SERVER) + 1);
    (void)strcpy(config.imServer, MEA_CFG_IM_SERVER);

#ifdef WAP_SUPPORT
    config.maxMsgSize = MMS_DEFAULT_MAX_MSG_SIZE;
#else
    config.maxMsgSize = MEA_CFG_MAX_MSG_SIZE;
#endif /* WAP_SUPPORT */
    config.maxRetrSize = MEA_CFG_MIN_RETR_SIZE;

    config.roamingStatus = MEA_CFG_DEFAULT_ROAMING_STATUS;
    config.bearerStatus = MEA_CFG_DEFAULT_BEARER_STATUS;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    config.slaveRoamingStatus = MEA_CFG_DEFAULT_ROAMING_STATUS;
    config.slaveBearerStatus = MEA_CFG_DEFAULT_BEARER_STATUS;
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
}

#ifdef WAP_SUPPORT
void meaProfNetworkCallback(char *path, char *key, int type, int ival, char *sval)
{
	if (!MSF_moduleIsRunning(MSF_MODID_MMS))
		return;
	if (0 == msf_cmmn_strcmp_nc(key, MMS_REG_KEY_PROXY_RELAY))
	{
		sval = msf_cmmn_strdup(MSF_MODID_MEA, sval);
		meaMmscCallback(sval, 0, NULL, 0);	
	}
#ifdef __MMS_DUAL_SIM_SUPPORT__
	else if (0 == msf_cmmn_strcmp_nc(key, MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY))
	{
		sval = msf_cmmn_strdup(MSF_MODID_MEA, sval);
		meaMmscCallbackExt(MMS_SIM_CARD_SLAVE, sval, 0, NULL, 0);	
	}
#endif
	else
	{
	    int i;
        for (i = 0; i< MEA_CONFIG_NETWORK_COUNT; i++)
        {
            if (0 == msf_cmmn_strcmp_nc(key, confType[i].asString))
            {
				if (type)
					sval = msf_cmmn_strdup(MSF_MODID_MEA, sval);
				meaNetworkCallback(sval, ival, NULL, confType[i].asInteger);
                return;
            }
		}
	}
}

/*!
 * \brief  Check if the setting of MMSC is invalid or not. 
 * \param  str The new value.
 * \return -1 for valide value, else string id for warning indicator.
 *****************************************************************************/
/*lint -e{818} */
MSF_UINT32 meaCheckMmscSetting(char *str)
{
    char *tmpPort;
    int i;
    msf_scheme_t tmpSchemeType;
    MSF_BOOL unsupp;

    if (!msf_url_is_valid(str))
    {
        return MEA_STR_ID_INVALID_PROXY_HOST;
    }
    tmpSchemeType = msf_url_get_scheme_type(str);
    unsupp = TRUE;
    for (i = 0; suppSchemes[i] != 0; i++)
    {
        if (suppSchemes[i] == tmpSchemeType)
        {
            unsupp = FALSE;
            break;
        }
    }
    if (unsupp)
    {
        return MEA_STR_ID_INVALID_PROXY_SCHEME;        
    }

    tmpPort = msf_url_get_port(MSF_MODID_MEA, str);
    if (tmpPort)
    {
        i = atoi(tmpPort);
        if (!VALIDATE_PORT(i))
        {
            MEA_FREE(tmpPort);
            return MEA_STR_ID_INVALID_PROXY_PORT;
        }
    }
	 return 0;
}

void meaSaveOnSendSet(int value)
{
	if (config.saveOnSend != value)
	{
	    void* handle= MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
		config.saveOnSend = value;
		/* Create new registry instance  */ 
		MSF_REGISTRY_SET_PATH (handle, MEA_REG_PATH_MMS);
		MSF_REGISTRY_SET_ADD_KEY_INT(handle, MEA_REG_KEY_SAVE_ON_SEND, value);
		// Set configuration
		MSF_REGISTRY_SET_COMMIT(handle); 
	}	
}

int meaGetSaveOnSend(void)
{
	return config.saveOnSend;
}

static void initConfCreationMode(void)
{
	int openMode = MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
	int fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_CREATION_MODE_SET_FILE, openMode, 0);
	char modeChar = '\0';

	if (fileHandle > 0 && MSF_FILE_READ(fileHandle, &modeChar, 1) >0)
	{
		switch(modeChar)
		{
		case '0':
			meaConfSetCreationMode(MEA_CREATION_MODE_FREE);
			break;
		case '1':
			meaConfSetCreationMode(MEA_CREATION_MODE_RESTRICTED);
			break;
		default:
			MSF_FILE_CLOSE(fileHandle);
			MSF_FILE_REMOVE(MEA_CREATION_MODE_SET_FILE);		/* The file is corrupted */
			meaConfSetCreationMode(MEA_CREATION_MODE_FREE);
			return;
		}
	}
    MSF_FILE_CLOSE(fileHandle);
}

MeaCreationModeType meaConfGetCreationMode()
{
	if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
		initConfCreationMode();

	return confCreationMode;
}

static void meaConfSetCreationMode(MeaCreationModeType mode)
{
	confCreationMode = mode;
}

static MSF_BOOL meaConfCreationModeSave(MeaCreationModeType mode)
{
	int fileHandle;
	int openMode = MSF_FILE_SET_WRONLY |MSF_FILE_SET_CREATE |HDI_FILE_SET_CUSTOM_BLOCKING;
	char modeChar='\0';
	MSF_BOOL ret = TRUE;

	if (!HDIa_fileCheckDirExist(MEA_FOLDER_PATH))
	{
		(void)MSF_FILE_MKDIR(MEA_FOLDER_PATH);
	}

	modeChar = '0'+mode;
	fileHandle = MSF_FILE_OPEN( MSF_MODID_MSM, MEA_CREATION_MODE_SET_FILE, openMode, 0);
	if (fileHandle>=0)
	{
		if (MSF_FILE_WRITE(fileHandle, &modeChar, 1) < 0)
			ret = FALSE;
		else
			meaConfSetCreationMode(mode);
		
		MSF_FILE_CLOSE(fileHandle);
	}
	else
	{
		MSF_FILE_REMOVE(MEA_CREATION_MODE_SET_FILE);
		ret = FALSE;
	}
	return ret;
}

#ifdef JPG_ENCODE
static void initConfImageResize(void)
{
	int openMode = MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
	int fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_IMAGE_RESIZE_SET_FILE, openMode, 0);
	char modeChar = '\0';

	if (fileHandle > 0 && MSF_FILE_READ(fileHandle, &modeChar, 1) >0)
	{
		switch(modeChar)
		{
		case '0':
			meaConfSetImageResize(MEA_IMAGE_RESIZE_OFF);
			break;
		case '1':
			meaConfSetImageResize(MEA_IMAGE_RESIZE_160x120);
			break;
		case '2':
			meaConfSetImageResize(MEA_IMAGE_RESIZE_320x240);
			break;
		case '3':
			meaConfSetImageResize(MEA_IMAGE_RESIZE_640x480);
			break;
		default:
			MSF_FILE_CLOSE(fileHandle);
			MSF_FILE_REMOVE(MEA_IMAGE_RESIZE_SET_FILE);		/* The file is corrupted */
			meaConfSetImageResize(MEA_IMAGE_RESIZE_OFF);
			return;
		}
	}
    MSF_FILE_CLOSE(fileHandle);
}

MeaImageResizeType meaConfGetImageResize()
{
	if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
		initConfImageResize();

	return confImageResize;
}

void meaConfGetImageResizeValue(MsfSize *size)
{
    ASSERT(size != NULL);
    switch(meaConfGetImageResize())
    {
        case MEA_IMAGE_RESIZE_OFF:
            size->width = 0;
            size->height = 0;
            break;
        case MEA_IMAGE_RESIZE_160x120:
            size->width = 160;
            size->height = 120;
            break;
        case MEA_IMAGE_RESIZE_320x240:
            size->width = 320;
            size->height = 240;
            break;
        case MEA_IMAGE_RESIZE_640x480:
            size->width = 640;
            size->height = 480;
            break;
        default:
            ASSERT(0);	/* shouldn't be here */
            break;						
    }
}

static void meaConfSetImageResize(MeaImageResizeType irType)
{
	confImageResize= irType;
}

static MSF_BOOL meaConfImageResizeSave(MeaImageResizeType irType)
{
	int fileHandle;
	int openMode = MSF_FILE_SET_WRONLY |MSF_FILE_SET_CREATE |HDI_FILE_SET_CUSTOM_BLOCKING;
	char modeChar='\0';
	MSF_BOOL ret = TRUE;

	if (!HDIa_fileCheckDirExist(MEA_FOLDER_PATH))
	{
		(void)MSF_FILE_MKDIR(MEA_FOLDER_PATH);
	}

	modeChar = '0'+irType;
	fileHandle = MSF_FILE_OPEN( MSF_MODID_MSM, MEA_IMAGE_RESIZE_SET_FILE, openMode, 0);
	if (fileHandle>=0)
	{
		if (MSF_FILE_WRITE(fileHandle, &modeChar, 1) < 0)
			ret = FALSE;
		else
			meaConfSetImageResize(irType);
		
		MSF_FILE_CLOSE(fileHandle);
	}
	else
	{
		MSF_FILE_REMOVE(MEA_IMAGE_RESIZE_SET_FILE);
		ret = FALSE;
	}
	return ret;
}
#endif /* JPG_ENCODE */

void saveCreationSettings(ctk_screen_handle scrId)
{
    // CTK
    ctk_layout_handle			layoutId = ctk_screen_get_layout(scrId);
    ctk_inline_item_type_enum	itemType;
    ctk_inline_result_union		itemValue;
	int isOn;

	MeaCreationModeType mode;
	MeaImageResizeType irType;
	
	ctk_inline_get_result(layoutId, (MEA_CONFIG_COMP_CREATION_MODE + 1) * 2 - 1,&itemType, &itemValue);
	ASSERT(itemType == CTK_INLINE_ITEM_TYPE_SELECT);
	mode = itemValue.select_highlight;

#ifdef JPG_ENCODE
	ctk_inline_get_result(layoutId, (MEA_CONFIG_COMP_IMAGE_RESIZE + 1) * 2 - 1,&itemType, &itemValue);
	ASSERT(itemType == CTK_INLINE_ITEM_TYPE_SELECT);
	irType = itemValue.select_highlight;
#endif
	ctk_inline_get_result(layoutId, (MEA_CONFIG_COMP_AUTO_SIGNATURE + 1) * 2 - 1,&itemType, &itemValue);
	ASSERT(itemType == CTK_INLINE_ITEM_TYPE_SELECT);
	isOn = itemValue.select_highlight;
	ctk_inline_get_result(layoutId, (MEA_CONFIG_COMP_AUTO_SIGNATURE_TEXT + 1) * 2 - 2,&itemType, &itemValue);
	ASSERT(itemType == CTK_INLINE_ITEM_TYPE_EDITOR);

    meaDeleteConfComposeView();
	if (meaConfCreationModeSave(mode) 
#ifdef JPG_ENCODE
		&& meaConfImageResizeSave(irType)
#endif
		&& meaWriteSignatureFile(isOn, itemValue.input_buffer)
	)
	{
		meaShowDialog(MEA_GET_STR_ID(BRA_STR_ID_SAVED), MEA_DIALOG_PROMPT_DONE);
	}
	else
	{	
        	meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), MEA_DIALOG_ERROR);
		/*
		 * Note that we should always create another window to input again because the  
		 * underlying GUI inline implementation might have problems by pressing "Done" twice
		 */
		meaCreateConfComposeView(); //focus corrent index
	}
}

MSF_BOOL meaConfGetAutoSignature(void)
{
	int openMode = MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
    int fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_SIG_SET_FILE, openMode, 0);
    MSF_BOOL ret = FALSE;
    
	if (fileHandle > 0)
	{
	    char chr;
        int sigFileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_SIG_TEXT_FILE, openMode, 0);

	    if (MSF_FILE_READ(fileHandle, &chr, 1) > 0 && chr == '1' && sigFileHandle > 0)
		{
		    ret = TRUE;
		}
        MSF_FILE_CLOSE(sigFileHandle);
	}
    MSF_FILE_CLOSE(fileHandle);
    return ret;
}

char *meaConfGetAutoSignatureText(void)
{
	int openMode = MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
	int fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, MEA_SIG_TEXT_FILE, openMode, 0);
	int result = 0;
	
	if (fileHandle > 0)
	{
		char *text = NULL;
		text= MEA_ALLOC(MEA_CONF_ALLOW_SIG_MAX_SIZE*3+1);
		result = MSF_FILE_READ(fileHandle, text, MEA_CONF_ALLOW_SIG_MAX_SIZE*3+1);
		MSF_FILE_CLOSE(fileHandle);
		if (result > 0)
			return text;
	}	
	return NULL;
}

static MSF_BOOL meaWriteSignatureFile(int isOn, char* content)
{
	//int result;
	int fileHandle;
	int openMode = MSF_FILE_SET_WRONLY |MSF_FILE_SET_CREATE |HDI_FILE_SET_CUSTOM_BLOCKING;
	int strLength = (content? widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)content): 0);
	char s;
	MSF_BOOL ret = TRUE;

	if (!HDIa_fileCheckDirExist(MEA_FOLDER_PATH))
	{
		(void)MSF_FILE_MKDIR(MEA_FOLDER_PATH);
	}

	MSF_FILE_REMOVE(MEA_SIG_TEXT_FILE);
	if (strLength > 0)
	{
	    //if text is not empty, create the signature text file
		fileHandle = MSF_FILE_OPEN(MSF_MODID_MSM, MEA_SIG_TEXT_FILE, openMode, 0);
		if (fileHandle <0)
		{
		    ret = FALSE;
		}
		else
		{
			char *str = MEA_ALLOC(strLength+1);
			widget_ucs2_to_utf8_string((kal_uint8 *) str, strLength+1, (kal_uint8 *)content);
			if (MSF_FILE_WRITE(fileHandle,(char *)str, strLength+1) <0)  // != size
			{
				MSF_FILE_REMOVE(MEA_SIG_TEXT_FILE);
				ret = FALSE;
			}
			MSF_FILE_CLOSE(fileHandle);
			MEA_FREE(str);
		}
	}
	if (isOn == 0 || ret == FALSE )
		s = '0';
	else
		s = '1';
	fileHandle = MSF_FILE_OPEN( MSF_MODID_MSM, MEA_SIG_SET_FILE, openMode, 0);
	if (fileHandle>=0)
	{
		//result=
		if (MSF_FILE_WRITE(fileHandle, &s, 1) < 0)
			ret = FALSE;
		MSF_FILE_CLOSE(fileHandle);
	}
	else
	{
		MSF_FILE_REMOVE(MEA_SIG_SET_FILE);
		ret = FALSE;
	}
	return ret;
}

#endif /* WAP_SUPPORT */
/*!
 * \brief MEA Config FSM signal handler
 * \param sig The incoming signal
 ******************************************************************************/
static void meaConfig(MeaSignal *sig)
{
    static int getConfigCount; /* counter for get registry operations */
    
    if (NULL == sig)
    {
        meaPanic(TRUE);
        return;
    }
    
    switch (sig->type)
    {
#ifdef WAP_SUPPORT
    case MEA_SIG_CONF_SAVE_SETTINGS:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            meaConfigInlineMenuSave((ctk_screen_handle)sig->u_param2);
        else
            meaConfigInlineMenuCancel((ctk_screen_handle)sig->u_param2);
        break;
    case MEA_SIG_CONF_SAVE_COMPOSE:
        if ((MeaConfirmDialogResult)sig->u_param1 == MEA_CONFIRM_DIALOG_OK)
            saveCreationSettings((ctk_screen_handle)sig->u_param2);
        else
            meaDeleteConfComposeView();
        break;
#endif /* WAP_SUPPORT */
    case MEA_SIG_CONF_ACTIVATE:
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_BC42E6A40EA6C50D6139F8A57ADE1F96, "meaConfig(): GUI activation\n"));
        
        (void)meaConfigActivateMenu(MEA_CONFIG_MENU_DEFAULT, 
            (int)MEA_CONFIG_MENU_DEFAULT, NULL);
        break;
        
    case MEA_SIG_CONF_ACTIVATE_SETTINGS:
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_4921CFC6EE7B108613AD24A6ED3C1B7F, "meaConfig(): GUI settings activation\n"));
        (void)meaConfigActivateMenu(MEA_CONFIG_MENU_MMS_SETTINGS,
            0, (MeaPropItem*)sig->p_param);
        break;

    case MEA_SIG_CONF_INITIAL_ACTIVATE:
        /* init instance */
        initConfInstance(&confInstance);

        getConfigCount = 0;
        /* Init MMS settings */
        setMmsSettings();
        /* Tell the framework that the MEA handles mmsto and mailto schemes */
        setContentRoutingInformation();

        /* Read configuration from registry */
        readRegistry();
        /* Read additional setting */
        initConfCreationMode();
#ifdef JPG_ENCODE
        initConfImageResize();
#endif

        break;

    case MEA_SIG_CONF_DEACTIVATE:
        if (MEA_STARTUP_MODE_CONFIG == meaGetStartupMode()) 
        {
            /*
             *	If we started MEA in config mode we request to close down MEA 
             *  new and let all running FSMs run their work first.
             */
            (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);            
        }
        break;
        
    case MEA_SIG_CONF_GET_REG_RSP:
        handleGetRegRsp(confInstance, meaGetConfig(), 
            (msf_registry_response_t*)sig->p_param);
        ++getConfigCount;
        /*  Start the GUI for the application when the configuration has been 
         *  received. The -1 is because the first enum field is not used
         *  for getting configuration values
         */
        if (MEA_CONF_S_UNINITIALIZED == confInstance->state &&
            getConfigCount >= (GET_CONFIG_COUNT - 1))
        {
#ifdef WAP_SUPPORT
            if (meaGetStartupMode() == MEA_STARTUP_MODE_NEW)
#endif /* WAP_SUPPORT */
                meaActivateStartupFsm();
            confInstance->state = MEA_CONF_S_INITIALIZED;
        }
        break;

    case MEA_SIG_CONF_GET_NETWORK_STATUS:
        /* Refresh network status variables */
        getNetworkStatus(confInstance, (MeaStateMachine)sig->u_param1, 
            (int)sig->u_param2);
        break;
        
    default :
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_FD06FE59291931BAC9FC0E06E4ABE4AD, "meaConfig(): Mysterious signal recieved"));
        break;
    } 
    /* Delete the signal */
    meaSignalDelete(sig);
}

/*!
 * \brief  Callback for changing setting of SaveOnSend-flag. This function can 
 *         handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new save on send setting.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaSaveOnSendCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_C89DBEF4A711FF206EF14DB1E6CA6CAD, "meaSaveOnSendCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    config.saveOnSend = value;
    if (!saveMsgSendSettings(meaGetConfig(), MEA_CONFIG_SAVE_ON_SEND))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of validity period a.k.a. expiry time
 *         This function can handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new expiry time setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration data should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818}*/
MSF_BOOL meaExpTimeCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;

    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value < MEA_EXPIRY_1_HOUR || value > MEA_EXPIRY_MAX) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_28AEEE01944645125A88E0C3316A6CE0, "meaExpTimeCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp)
    {
        tmpConfig = meaGetConfig();
        tmpConfig->expiryTime = (MeaExpiryTimeType)value;
        if (!saveMsgSendSettings(tmpConfig, MEA_CONFIG_EXP_TIME))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->expiryTime = (MeaExpiryTimeType)value;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of read report. This function can 
 *         handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new read report setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration data should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaReadReportCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;
    
    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_231E65A83EDCEBBCC134B94432F4C9C4, "meaReadReportCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp)
    {
        tmpConfig = meaGetConfig();
        tmpConfig->readReport = value;
        if (!saveMsgSendSettings(meaGetConfig(), MEA_CONFIG_READ_REPORT))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->readReport = value;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of delivery report. This function can 
 *         handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new delivery report setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaDelivReportCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;
    
    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
           MACONF_43310759F4E7D6089CEDFA9268D64C3C, "meaDelivReportCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp)
    {
        tmpConfig = meaGetConfig();
        tmpConfig->deliveryReport = value;
        if (!saveMsgSendSettings(meaGetConfig(), MEA_CONFIG_DELIV_REPORT))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->deliveryReport = value;        
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of priority. This function can handle
 *         both global and temporary setting.
 * \param  str N/A.
 * \param  value The new priority setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaPriorityCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;
    
    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value < MEA_PRIORITY_LOW || value > MEA_PRIORITY_HIGH) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
           MACONF_DC628077C951863424323FB320EFFA6D, "meaPriorityCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp)
    {
        tmpConfig = meaGetConfig();
        tmpConfig->priority = (MeaPriorityType)value;
        if (!saveMsgSendSettings(meaGetConfig(), MEA_CONFIG_PRIORITY))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->priority = (MeaPriorityType)value;
        
    }

    return TRUE;
}

/*!
 * \brief  Callback for changing setting of slide duration
 * \param  str The new slide duration.
 * \param  value N/A.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaSlideDurCallback(char *str, int value, void *p1, int p2)
{
    int tmpVal;
    MeaConfig *tmpConfig;

    if (0 != value || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_740D64B8BFF5072F9F1FC1B8B62BC8C4, "(%s) (%d) value is not 0\n", __FILE__, 
            __LINE__));
    }
    tmpVal = atoi(str);
    /* Check boundaries */
    if (tmpVal <= 0 || tmpVal > MEA_CFG_MAX_DURATION) 
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        /*lint -e{774} */
        MEA_FREE(str);
        return FALSE;
    }
    tmpConfig = (MeaConfig*)p1;
    if (!tmpConfig)
    {
        tmpConfig = meaGetConfig();
    }
    tmpConfig->slideDuration = tmpVal;
    if (!p1)
    {
        if (!saveMsgSendSettings(tmpConfig, MEA_CONFIG_SLIDE_DUR))
        {
            MEA_FREE(str);
            return FALSE;
        }
    }
    /*lint -e{774} */
    MEA_FREE(str);
    return TRUE;
}


/*!
 * \brief  Callback for changing setting of reply charging. This function can 
 *         handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new reply charging setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaReplyChargingCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;
    
    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value < MEA_REPLY_CHARGING_OFF || value > MEA_REPLY_CHARGING_TEXT_ONLY) 
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
           MACONF_C8C15BC042489937740FD9517C05AA92, "meaReplyChargingCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp) 
    {
        tmpConfig = meaGetConfig();
        tmpConfig->replyCharging = (MeaReplyChargingType)value;
        if (!saveMsgReplyChargingSettings(meaGetConfig(),
            MEA_CONFIG_REPLY_CHARGING))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->replyCharging = (MeaReplyChargingType)value;        
    }

    return TRUE;
}

/*!
 * \brief  Callback for changing setting of reply charging. This function can 
 *         handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new reply charging deadline setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaReplyChargingDeadlineCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;
    
    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value < MEA_REPLY_CHARGING_DEADLINE_1_DAY || 
        value > MEA_REPLY_CHARGING_DEADLINE_MAX)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
           MACONF_4D1B6C80142028F19A6E2B5D92A434DA, "meaReplyChargingDeadlineCallback(): Impossible value (%d) received",
           value));
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp) 
    {
        tmpConfig = meaGetConfig();
        tmpConfig->replyChargingDeadline = (MeaReplyChargingDeadlineType)value;
        if (!saveMsgReplyChargingSettings(meaGetConfig(),
            MEA_CONFIG_REPLY_CHARGING_DEADLINE))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->replyChargingDeadline = (MeaReplyChargingDeadlineType)value;        
    }

    return TRUE;
}

/*!
 * \brief  Callback for changing setting of reply charging. This function can 
 *         handle both global and temporary setting.
 * \param  str N/A.
 * \param  value The new reply charging size setting.
 * \param  p1 A pointer to the configuration data to change. NULL if global
 *         configuration should be used.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaReplyChargingSizeCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;
    
    if (str || p2) 
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value < MEA_REPLY_CHARGING_SIZE_1_KB || 
        value > MEA_REPLY_CHARGING_SIZE_MAX)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
           MACONF_81E1CEB9C0733E1A265C83C25309A9F9, "meaReplyChargingSizeCallback(): Impossible value (%d) received",
           value));
        return FALSE;
    }
    msgProp = (MeaPropItem*)p1;
    if (!msgProp) 
    {
        tmpConfig = meaGetConfig();
        tmpConfig->replyChargingSize = (MeaReplyChargingSizeType)value;
        if (!saveMsgReplyChargingSettings(meaGetConfig(),
            MEA_CONFIG_REPLY_CHARGING_SIZE))
        {
            return FALSE;
        }
    }
    else
    {
        msgProp->replyChargingSize = (MeaReplyChargingSizeType)value;        
    }

    return TRUE;
}

/*!
 * \brief  Callback for changing setting of retrieval home network mode. 
 * \param  str N/A.
 * \param  value The new value.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaRetrievalHomeModeCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
#ifdef WAP_SUPPORT
    if (value != MEA_RETRIEVAL_MODE_AUTOMATIC && value != MEA_RETRIEVAL_MODE_ALWAYS_ASK && 
        value !=MEA_RETRIEVAL_MODE_RESTRICTED)
#else
    if (value != 0 && value != 1)
#endif /* WAP_SUPPORT */
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
         MACONF_B2C3D7FCAD80A49605E40911F23555AE, "meaRetrievalHomeModeCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
#ifdef __MMI_MMS_BGSR_SUPPORT__
    if(value == MEA_RETRIEVAL_MODE_ALWAYS_ASK && config.retrievalMode == MEA_RETRIEVAL_MODE_AUTOMATIC)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_MH_FSM, MEA_SIG_MH_BGSR_CANCEL_ALL_DOWNLOAD);
    }
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
    config.retrievalMode = value;
    return saveRetrievalSettings(meaGetConfig(), MEA_CONFIG_HOME_NETWORK);
}

/*!
 * \brief  Callback for changing setting of retrieval roaming network mode. 
 * \param  str N/A.
 * \param  value The new value.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaRetrievalRoamModeCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1 && value != 2)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
         MACONF_06D56DBBD45097B72ABFDEF64AEFA87A, "meaRetrievalRoamModeCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    config.retrievalModeRoam = value;
    if (!saveRetrievalSettings(meaGetConfig(), MEA_CONFIG_ROAM_NETWORK))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of maximum size for immediate 
 *         retrieval. 
 * \param  str The new value.
 * \param  value N/A.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaImRetrSizeCallback(char *str, int value, void *p1, int p2)
{
    int tmpVal;
    if (value || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    tmpVal = atoi(str);
#ifdef WAP_SUPPORT
    if (tmpVal < MEA_CFG_MIN_MSG_SIZE || tmpVal > MMS_DEFAULT_MAX_MSG_SIZE)
#else
    if (tmpVal < MEA_CFG_MIN_MSG_SIZE || tmpVal > MEA_CFG_MAX_MSG_SIZE)
#endif /* WAP_SUPPORT */
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        /*lint -e{774} */
        MEA_FREE(str);
        return FALSE;
    }
    config.maxMsgSize = (unsigned int)tmpVal;
    if (!saveImRetrSettings(meaGetConfig(), MEA_CONFIG_IM_SIZE))
    {
        MEA_FREE(str);
        return FALSE;
    }
    /*lint -e{774} */
    MEA_FREE(str);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of the treat-as-delayed flag. 
 * \param  str N/A..
 * \param  value 1=YES, 0=NO.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaTreatAsDelCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_6C3A0A8688B6D45AE67C36A3AB640E12, "(%s) (%d) Some values are not 0\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MACONF_FC30084B75C42A141A0F23EA1F4F452E, "meaTreatAsDelCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }
    config.treatAsDel = value;
    if (!saveImRetrSettings(meaGetConfig(), MEA_CONFIG_TREAT_AS_DEL))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting for allowing class ADVERTISE messages.
 * \param  str N/A.
 * \param  value 1=ALLOW, 0=REJECT.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaAllowAdvertCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        return FALSE;
    }
    config.allowAdvert = value;
    if (!saveImRetrSettings(meaGetConfig(), MEA_CONFIG_ALLOW_ADVERT))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting for allowing class PERSONAL messages.
 * \param  str N/A.
 * \param  value 1=ALLOW, 0=REJECT.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaAllowPersonalCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        return FALSE;
    }
    config.allowPersonal = value;
    if (!saveImRetrSettings(meaGetConfig(), MEA_CONFIG_ALLOW_PERSONAL))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief  Callback for changing setting for allowing class INFO messages.
 * \param  str N/A.
 * \param  value 1=ALLOW, 0=REJECT.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaAllowInfoCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        return FALSE;
    }
    config.allowInfo = value;
    (void)saveImRetrSettings(meaGetConfig(), MEA_CONFIG_ALLOW_INFO);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting for allowing class AUTO messages.
 * \param  str N/A.
 * \param  value 1=ALLOW, 0=REJECT.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaAllowAutoCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        return FALSE;
    }
    config.allowAuto = value;
    (void)saveImRetrSettings(meaGetConfig(), MEA_CONFIG_ALLOW_AUTO);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting for allowing anonymous senders.
 * \param  str N/A.
 * \param  value 1=ALLOW, 0=REJECT.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaAllowAnonymCallback(char *str, int value, void *p1, int p2)
{
    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
            MEA_DIALOG_ERROR);
        return FALSE;
    }
    config.allowAnonym = value;
    (void)saveImRetrSettings(meaGetConfig(), MEA_CONFIG_ALLOW_ANONYM);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of user defined string class 
 *         for immediate retrieval filtering.
 * \param  str The new value.
 * \param  value N/A.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaAllowStringCallback(char *str, int value, void *p1, int p2)
{
    if (value || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_31627B5B56BB4DC193625C9605BA86B1, "(%s) (%d) The values are not 0\n", __FILE__, 
            __LINE__));
    }
    MEA_FREE(config.allowString);
    config.allowString = str;
    (void)saveImRetrSettings(meaGetConfig(), MEA_CONFIG_ALLOW_STRING);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of immediate retrieval server. 
 * \param  str The new value.
 * \param  value N/A.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaImServerCallback(char *str, int value, void *p1, int p2)
{
    if (value || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (!msf_url_is_valid(str))
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_HOST), 
            MEA_DIALOG_ERROR);
        MEA_FREE(str);
        return FALSE;
    }
    MEA_FREE(config.imServer);
    config.imServer = str;
    (void)saveImRetrSettings(meaGetConfig(), MEA_CONFIG_IM_SERVER);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of MMSC. 
 * \param  str The new value.
 * \param  value N/A.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaMmscCallback(char *str, int value, void *p1, int p2)
{
    char *tmpScheme, *newScheme;
    char *tmpHost;
    char *tmpPath, *newPath;
    char *tmpPort;
    int i;
    msf_scheme_t tmpSchemeType;
    MSF_BOOL unsupp;

    if (value || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }

    if (!msf_url_is_valid(str))
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_HOST), 
            MEA_DIALOG_ERROR);
        MEA_FREE(str);
        return FALSE;
    }
    tmpSchemeType = msf_url_get_scheme_type(str);
    unsupp = TRUE;
    for (i = 0; suppSchemes[i] != 0; i++)
    {
        if (suppSchemes[i] == tmpSchemeType)
        {
            unsupp = FALSE;
            break;
        }
    }
    if (unsupp)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_SCHEME), 
            MEA_DIALOG_ERROR);
        MEA_FREE(str);
        return FALSE;        
    }

    tmpPort = msf_url_get_port(MSF_MODID_MEA, str);
    if (tmpPort)
    {
        i = atoi(tmpPort);
        if (!VALIDATE_PORT(i))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_PORT), 
                MEA_DIALOG_ERROR);            
            MEA_FREE(str);
            /*lint -e{774} */
            MEA_FREE(tmpPort);
            return FALSE;
        }
    }
    
    tmpScheme = msf_url_get_scheme(MSF_MODID_MEA, str);
    tmpHost = msf_url_get_host(MSF_MODID_MEA, str);
    tmpPath = (char *)msf_url_find_path((const char *)str);
    if (NULL != tmpScheme)
    {
        newScheme = MEA_ALLOC(strlen(tmpScheme) + 1 + 3);
        sprintf(newScheme, "%s://", tmpScheme);
        /*lint -e{774} */
        MEA_FREE(tmpScheme);
        setDstStr(&(config.proxyScheme), newScheme);
    }
    setDstStr(&(config.proxyHost), tmpHost);
    newPath = NULL;
    if (tmpPath)
    {
        newPath = MEA_ALLOC(strlen(tmpPath) + 1);
        strcpy(newPath, tmpPath);
        tmpPath = NULL;
    }
    setDstStr(&(config.proxyUri), newPath);
    if (NULL != tmpPort)
    {
        config.proxyPort = (unsigned int)atoi(tmpPort);
        /*lint -e{774} */
        MEA_FREE(tmpPort);
    }
    else
    {
        config.proxyPort = 0;
    }
#ifdef __MMS_DUAL_SIM_SUPPORT__
    (void)saveSettings(MMS_SIM_CARD_MASTER, meaGetConfig(), MEA_CONFIG_MMSC);

#else
    (void)saveSettings(meaGetConfig(), MEA_CONFIG_MMSC);
#endif
    MEA_FREE(str);
    return TRUE;
}

#ifdef __MMS_DUAL_SIM_SUPPORT__
/*!
 * \brief  Callback for changing setting of MMSC. 
 * \param  str The new value.
 * \param  value N/A.
 * \param  p1 N/A.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaMmscCallbackExt(MmsSimCardEnum simId, char *str, int value, void *p1, int p2)
{
    char *tmpScheme, *newScheme;
    char *tmpHost;
    char *tmpPath, *newPath;
    char *tmpPort;
    int i;
    msf_scheme_t tmpSchemeType;
    MSF_BOOL unsupp;

    if (value || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }

    if (!msf_url_is_valid(str))
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_HOST), 
            MEA_DIALOG_ERROR);
        MEA_FREE(str);
        return FALSE;
    }
    tmpSchemeType = msf_url_get_scheme_type(str);
    unsupp = TRUE;
    for (i = 0; suppSchemes[i] != 0; i++)
    {
        if (suppSchemes[i] == tmpSchemeType)
        {
            unsupp = FALSE;
            break;
        }
    }
    if (unsupp)
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_SCHEME), 
            MEA_DIALOG_ERROR);
        MEA_FREE(str);
        return FALSE;        
    }

    tmpPort = msf_url_get_port(MSF_MODID_MEA, str);
    if (tmpPort)
    {
        i = atoi(tmpPort);
        if (!VALIDATE_PORT(i))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_PROXY_PORT), 
                MEA_DIALOG_ERROR);            
            MEA_FREE(str);
            /*lint -e{774} */
            MEA_FREE(tmpPort);
            return FALSE;
        }
    }
    
    tmpScheme = msf_url_get_scheme(MSF_MODID_MEA, str);
    tmpHost = msf_url_get_host(MSF_MODID_MEA, str);
    tmpPath = (char *)msf_url_find_path((const char *)str);
    if (NULL != tmpScheme)
    {
        newScheme = MEA_ALLOC(strlen(tmpScheme) + 1 + 3);
        sprintf(newScheme, "%s://", tmpScheme);
        /*lint -e{774} */
        MEA_FREE(tmpScheme);
        if(simId == MMS_SIM_CARD_MASTER)
        {
            setDstStr(&(config.proxyScheme), newScheme);
        }
        else
        {
            setDstStr(&(config.slaveProxyScheme), newScheme);
        }
    }
    if(simId == MMS_SIM_CARD_MASTER)
    {
        setDstStr(&(config.proxyHost), tmpHost);
    }
    else
    {
        setDstStr(&(config.slaveProxyHost), tmpHost);
    }
    

    newPath = NULL;
    if (tmpPath)
    {
        newPath = MEA_ALLOC(strlen(tmpPath) + 1);
        strcpy(newPath, tmpPath);
        tmpPath = NULL;
    }
    if(simId == MMS_SIM_CARD_MASTER)
    {
        setDstStr(&(config.proxyUri), newPath);
    }
    else
    {
        setDstStr(&(config.slaveProxyUri), newPath);
    }


    if (NULL != tmpPort)
    {
        if(simId == MMS_SIM_CARD_MASTER)
        {
            config.proxyPort = (unsigned int)atoi(tmpPort);
        }
        else
        {
            config.slaveProxyPort = (unsigned int)atoi(tmpPort);
        }


        /*lint -e{774} */
        MEA_FREE(tmpPort);
    }
    else
    {
        if(simId == MMS_SIM_CARD_MASTER)
        {
            config.proxyPort = 0;
        }
        else
        {
            config.slaveProxyPort = 0;
        }
    }
    (void)saveSettings(simId, meaGetConfig(), MEA_CONFIG_MMSC);


    MEA_FREE(str);
    return TRUE;
}
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
/*!
 * \brief  Callback for changing network settings. 
 * \param  str The new string value if applicable.
 * \param  value The new integer value if applicable.
 * \param  p1 N/A.
 * \param  p2 The selected setting. See #MeaConfigNetwork.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaNetworkCallback(char *str, int value, void *p1, int p2)
{
    MeaConfigNetwork choice;
    MeaConfig *conf;
#ifndef WAP_SUPPORT
    int tmp;
    char *buffer;
#endif /* WAP_SUPPORT */

    if (p1)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_915834D8E4DC4987D269DA594BBE4270, "(%s) (%d) p1 is not NULL\n", __FILE__, 
            __LINE__));
    }
    choice = (MeaConfigNetwork)p2;
    conf = meaGetConfig();
    switch (choice) 
    {
    case MEA_CONFIG_CONN_TYPE :
        if (value < MEA_CONNECTION_TYPE_HTTP || 
            value > MEA_CONNECTION_TYPE_WSP_CO) 
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
                __FILE__, __LINE__, value));
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                MEA_DIALOG_ERROR);            
            return FALSE;
        }
        conf->connectionType = (MeaConnectionType)value;
        break;
    case MEA_CONFIG_NET_ACCOUNT :
        if (value < 0)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
                __FILE__, __LINE__, value));
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                MEA_DIALOG_ERROR);            
            return FALSE;
        }
        conf->networkAccount = value;
        break;
    case MEA_CONFIG_WAP_GW :
#ifdef WAP_SUPPORT
        if (str && !msf_url_is_valid(str))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_WAP_GATEWAY),
                MEA_DIALOG_ERROR);
            return FALSE;
        }
#else
        if (str)
        {
            /*
             *	This is a fix (TR15500) to get msf_url_is_valid() to check the ip
             *  values in the wap gateway address. The check is not performed
             *  unless there is an ecoding scheme included in the url. The default
             *  scheme "http://" is always added here, just to get it checked.
             */
            buffer = MEA_ALLOC(strlen(str) + strlen("http://") + 1);
            sprintf(buffer, "%s%s", "http://", str);
            if (!msf_url_is_valid(buffer))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_WAP_GATEWAY),
                    MEA_DIALOG_ERROR);
                MEA_FREE(buffer);
                return FALSE;
            }
            MEA_FREE(buffer);
        }
#endif /* WAP_SUPPORT */
        MEA_FREE(conf->wapGateway);
        conf->wapGateway = str;
        break;
    case MEA_CONFIG_LOGIN :
        MEA_FREE(conf->login);
        conf->login = str;
        break;
    case MEA_CONFIG_PASSWD :
        MEA_FREE(conf->passwd);
        conf->passwd = str;        
        break;
    case MEA_CONFIG_REALM :
        MEA_FREE(conf->realm);
        conf->realm = str;        
        break;
    case MEA_CONFIG_SEC_PORT :
#ifdef WAP_SUPPORT
        if (value < 0)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
                __FILE__, __LINE__, value));
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                MEA_DIALOG_ERROR);            
            return FALSE;
        }
        conf->securePort = (unsigned int)value;
#else
        if (NULL != str)
        {
            tmp = atoi(str);
            if (!VALIDATE_PORT(tmp))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
                    MEA_DIALOG_ERROR);            
                /*lint -e{774} */
                MEA_FREE(str);
                return FALSE;
            }
        }
        conf->securePort = (unsigned int)(str ? atoi(str) : 0);
        MEA_FREE(str);
#endif /* WAP_SUPPORT */
        break;
    case MEA_CONFIG_HTTP_PORT :
        
        if (!VALIDATE_PORT(value))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
                MEA_DIALOG_ERROR);            
            /*lint -e{774} */
                
            return FALSE;
        }
        
        conf->httpPort = (unsigned int)(value );
       
        break;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    case MEA_CONFIG_SLAVE_CONN_TYPE :
        if (value < MEA_CONNECTION_TYPE_HTTP || 
            value > MEA_CONNECTION_TYPE_WSP_CO) 
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
                __FILE__, __LINE__, value));
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                MEA_DIALOG_ERROR);            
            return FALSE;
        }
        conf->slaveConnectionType = (MeaConnectionType)value;
        break;
        
        case MEA_CONFIG_SLAVE_NET_ACCOUNT :
            if (value < 0)
            {
                MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                    MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
                    __FILE__, __LINE__, value));
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                    MEA_DIALOG_ERROR);            
                return FALSE;
            }
            conf->slaveNetworkAccount = value;
            break;
            
        
    case MEA_CONFIG_SLAVE_WAP_GW :
        
#ifdef WAP_SUPPORT
        if (str && !msf_url_is_valid(str))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_WAP_GATEWAY),
                MEA_DIALOG_ERROR);
            return FALSE;
        }
#else
        if (str)
        {
            /*
             *	This is a fix (TR15500) to get msf_url_is_valid() to check the ip
             *  values in the wap gateway address. The check is not performed
             *  unless there is an ecoding scheme included in the url. The default
             *  scheme "http://" is always added here, just to get it checked.
             */
            buffer = MEA_ALLOC(strlen(str) + strlen("http://") + 1);
            sprintf(buffer, "%s%s", "http://", str);
            if (!msf_url_is_valid(buffer))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_WAP_GATEWAY),
                    MEA_DIALOG_ERROR);
                MEA_FREE(buffer);
                return FALSE;
            }
            MEA_FREE(buffer);
        }
#endif /* WAP_SUPPORT */
        MEA_FREE(conf->slaveWapGateway);
        conf->slaveWapGateway = str;
        break;

    case MEA_CONFIG_SLAVE_LOGIN :
        MEA_FREE(conf->slaveLogin);
        conf->slaveLogin = str;
        break;

    case MEA_CONFIG_SLAVE_PASSWD :

        MEA_FREE(conf->slavePasswd);
        conf->slavePasswd = str;        
        break;
    case MEA_CONFIG_SLAVE_REALM:

        MEA_FREE(conf->slaveRealm);
        conf->slaveRealm = str;        
        break;
    case MEA_CONFIG_SLAVE_SEC_PORT:

        
#ifdef WAP_SUPPORT
        if (value < 0)
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
                MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
                __FILE__, __LINE__, value));
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_ERROR), 
                MEA_DIALOG_ERROR);            
            return FALSE;
        }
        conf->slaveSecurePort = (unsigned int)value;
#else
        if (NULL != str)
        {
            tmp = atoi(str);
            if (!VALIDATE_PORT(tmp))
            {
                (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
                    MEA_DIALOG_ERROR);            
                /*lint -e{774} */
                MEA_FREE(str);
                return FALSE;
            }
        }
        conf->slaveSecurePort = (unsigned int)(str ? atoi(str) : 0);
        MEA_FREE(str);
#endif /* WAP_SUPPORT */
        break;
    case MEA_CONFIG_SLAVE_HTTP_PORT :
        
        if (!VALIDATE_PORT(value))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
                MEA_DIALOG_ERROR);            
            /*lint -e{774} */
                
            return FALSE;
        }
        
        conf->slaveHttpPort = (unsigned int)(value );
       
        break;
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    case MEA_CONFIG_NETWORK_COUNT:
    default:
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MACONF_B48B483C8AF14C1FEC1F45F7763414CD, "(%s) (%d) Impossible value (%d) received.\n", 
            __FILE__, __LINE__, p2));
    }
    return saveNetworkSettings(conf, choice);
}

#ifdef WAP_SUPPORT
MSF_BOOL meaDownloadSizeVerify(char * strbuf)
{
	int tmpVal;
    char * dlgStr;
    tmpVal = atoi(strbuf) * MEA_1_KB;
    if (tmpVal >= 0 && (tmpVal < MEA_CFG_MIN_RETR_SIZE 
        || tmpVal > MEA_CFG_MAX_RETR_SIZE))
    {
        dlgStr = meaGetIntervalString(MEA_STR_ID_INTERVAL_PREFIX,
            MEA_CFG_MIN_RETR_SIZE, MEA_STR_ID_INTERVAL_INFIX, 
            MEA_CFG_MAX_RETR_SIZE / MEA_1_KB);
        if (!showErrorDlg(dlgStr))
        {
            /* If we were unable to create the dynamic dialog we 
             * try to show a static message */
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
                MEA_DIALOG_ERROR);
        }
        MEA_FREE(dlgStr);
        MEA_FREE(strbuf);
        return FALSE;
    }
    return TRUE;			
}
#endif /* WAP_SUPPORT */

/*!
 * \brief  Callback for changing maximum download size. 
 * \param  str The new string value if applicable.
 * \param  value The new integer value if applicable.
 * \param  p1 N/A.
 * \param  p2 The selected setting. See #MeaConfigFilter.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
 /*lint -e{818} */
MSF_BOOL meaDownloadSizeCallback(char *str, int value, void *p1, int p2)
{
    int tmpVal;
    char *dlgStr;

    if (value || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_91949392208D9BC1D386E40E864C14E5, "(%s) (%d) something is not NULL\n", __FILE__, 
            __LINE__));
    }
#ifdef WAP_SUPPORT
    tmpVal = atoi(str) * MEA_1_KB;
#else
    tmpVal = atoi(str);
#endif /* WAP_SUPPORT */
    /*  We don't need to check for negative values since they are restricted
     *  from the form */
#ifdef WAP_SUPPORT
    if (tmpVal >= 0 && (tmpVal < MEA_CFG_MIN_RETR_SIZE 
        || tmpVal > MEA_CFG_MAX_RETR_SIZE))
    {
        dlgStr = meaGetIntervalString(MEA_STR_ID_INTERVAL_PREFIX,
            MEA_CFG_MIN_RETR_SIZE, MEA_STR_ID_INTERVAL_INFIX, 
            MEA_CFG_MAX_RETR_SIZE / MEA_1_KB);
#else
    if (tmpVal > 0 && (tmpVal < MEA_CFG_MIN_RETR_SIZE 
        || tmpVal > MEA_CFG_MAX_RETR_SIZE))
    {
        dlgStr = meaGetIntervalString(MEA_STR_ID_INTERVAL_PREFIX,
            MEA_CFG_MIN_RETR_SIZE, MEA_STR_ID_INTERVAL_INFIX, 
            MEA_CFG_MAX_RETR_SIZE);
#endif /* WAP_SUPPORT */
        if (!showErrorDlg(dlgStr))
        {
            /* If we were unable to create the dynamic dialog we 
             * try to show a static message */
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_VALUE), 
                MEA_DIALOG_ERROR);
        }
        MEA_FREE(dlgStr);
        /*lint -e{774} */
        MEA_FREE(str);
        return FALSE;
    }
    config.maxRetrSize = (unsigned int)tmpVal;
    (void)saveImRetrSettings(meaGetConfig(), MEA_CONFIG_RETR_SIZE);
    /*lint -e{774} */
    MEA_FREE(str);
    return TRUE;
}

/*!
 * \brief  Callback for changing setting of Sender visibility. 
 * \param  str N/A.
 * \param  value The new value.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaSenderVisibilityCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;
    MeaPropItem *msgProp;

    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
         MACONF_5AC48ED604014EDD68DF65C0497F6B58, "meaSenderVisibilityCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }    

    msgProp = (MeaPropItem*)p1;
    if (!msgProp)
    {
        tmpConfig = meaGetConfig();
        tmpConfig->senderVisibility = (MeaVisibilityType)value;
        (void)saveMsgSendSettings(tmpConfig, MEA_CONFIG_SENDER_VISIBILITY);
    }
    else
    {
        msgProp->senderVisibility = (MeaVisibilityType)value;        
    }

    return TRUE;
}

/*!
 * \brief  Callback for changing setting for Delivery Report Allowed. 
 * \param  str N/A.
 * \param  value The new value changed in the MEA GUI.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaDeliveryReportAllowedCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;

    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
         MACONF_F147B166677362E875F27934A57653F1, "meaDeliveryReportAllowedCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }    

    tmpConfig = meaGetConfig();
    /* Convert MEA value to MMS setting */
    if (value == 1)
    {
        tmpConfig->deliveryReportAllowed = MMS_DELIVERY_REPORT_NO;
    }
    else
    {
        tmpConfig->deliveryReportAllowed = MMS_DELIVERY_REPORT_YES;
    }  
    (void)saveRetrievalSettings(tmpConfig, MEA_CONFIG_DELIVERY_REPORT_ALLOWED);

    return TRUE;
}

/*!
 * \brief  Callback for changing setting for Send Read Report. 
 * \param  str N/A.
 * \param  value The new value.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaSendReadReportCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;

    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1 && value != 2)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
         MACONF_F7DD27E837BF32FE6BD2F6952CFE39FC, "meaSendReadReportCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }    

    tmpConfig = meaGetConfig();
    tmpConfig->sendReadReport = value;
    (void)saveRetrievalSettings(tmpConfig, MEA_CONFIG_SEND_READ_REPORT);

    return TRUE;
}

/*!
 * \brief  Callback for changing setting for Delivery Time. 
 * \param  str N/A.
 * \param  value The new value.
 * \param  p1 A pointer to the configuration data to change.
 * \param  p2 N/A.
 * \return TRUE on successful save of value, else FALSE.
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL meaDeliveryTimeCallback(char *str, int value, void *p1, int p2)
{
    MeaConfig *tmpConfig;

    if (str || p1 || p2)
    {
        /* Some meaningless logging not to get warnings */
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MACONF_B9D4C698FD22FED9B4B272041A608D47, "(%s) (%d) str is not NULL\n", __FILE__, 
            __LINE__));
    }
    if (value != 0 && value != 1 && value != 2 && value != 3)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
         MACONF_69561A8877CC8EBC767B7167A857A166, "meaDeliveryTimeCallback(): Impossible value (%d) received", value));
        /* This should not happen since we restrict the value in the form */
        return FALSE;
    }    

    tmpConfig = meaGetConfig();
    tmpConfig->deliveryTime = value;
    (void)saveMsgSendSettings(tmpConfig, MEA_CONFIG_DELIVERY_TIME);

    return TRUE;
}


/*!
 * \brief  Returns the address of the global configuration data storage struct
 * \return The address of the MeaConfig struct
 *****************************************************************************/
MeaConfig *meaGetConfig(void)
{
    return &config;
}

/*!
 * \brief Checks if the configuration is set so that a message can be created.
 * 
 * \return TRUE if the configuration is ok, otherwise FALSE.
 *****************************************************************************/
int meaIsCreateConfValid(void)
{
    /* Maybe we should verify from address here but how do we know
     * if we want to use insert address token instead?
     */

    /* Verify MMSC version */
#ifdef WAP_SUPPORT
    if ( (config.proxyVersion == MMS_VERSION_PREVIOUS_MAJOR) ||
         (config.proxyVersion == MMS_VERSION_NEXT_MAJOR))
#else
    if ( (config.proxyVersion != MMS_VERSION_10) &&
         (config.proxyVersion != MMS_VERSION_11))
#endif /* WAP_SUPPORT */
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief Reads one specific configuration group from the registry. The 
 *        configurations are received through a signal.
 * \param The group to read
 *****************************************************************************/
static void readRegistryGroup(ConfigGroups group)
{
    /* only read valid groups */
    if (group <= GET_CONFIG_UNDEFINED || group >= GET_CONFIG_COUNT)
    {
        return;
    }

    /* get the group */
    if (GET_CONFIG_EXTERNAL != group) 
    {
    MSF_REGISTRY_GET(MSF_MODID_MEA, group, configRegistryGroup[(int)group], 
        NULL);
}
    else
    {
#ifdef WAP_SUPPORT //tmp fix
        MSF_REGISTRY_GET(MSF_MODID_MEA, group, configRegistryGroup[(int)group], 
            NULL);
#else
        MSF_REGISTRY_GET(MSF_MODID_MEA, group, configRegistryGroup[(int)group], 
            MEA_REG_KEY_MSISDN);
#endif /* WAP_SUPPORT */
    }
}

/*!
 * \brief Reads the configuration from the registry. The configurations are
 *        received through a signal.
 *
 *****************************************************************************/
static void readRegistry()
{
    int i;

    /* Get all registry entries needed to configure the MMS Service */
    for (i = (int)GET_CONFIG_UNDEFINED+1; i <= (int)GET_CONFIG_COUNT; i++)
    {
        readRegistryGroup((ConfigGroups)i);
    }
}


/*!
 * \brief Update internal config struct with network status registry values
 * \param inst   The current instance
 * \param fsm    The fsm to call when response is received
 * \param signal The signal to use when response is received
 *****************************************************************************/
static void getNetworkStatus(MeaConfInstance *inst, MeaStateMachine fsm, 
    int signal)
{
    inst->fsm = fsm;
    inst->signal = signal;
    readRegistryGroup(GET_CONFIG_NETWORK_STATUS);
}

/*!
 * \brief Saves the settings to the registry
 *
 * \param tmpConfig The configuration to save.
 * \param group The configuration group to save, See #MeaConfigGroups.
 *****************************************************************************/
static MSF_BOOL saveSettings(
#ifdef __MMS_DUAL_SIM_SUPPORT__
	MmsSimCardEnum simId,
#endif	
	const MeaConfig *tmpConfig,
	MeaConfigGroups group)
{
    void* handle;
    /* Create new registry instance */
    handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    if (NULL == handle)
    {
        return FALSE;
    }
    /* Set params for one group */
    switch (group)
    {
    case MEA_CONFIG_MMSC:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_MMSC);
        /* Proxy address */
#ifdef __MMS_DUAL_SIM_SUPPORT__
        if (simId == MMS_SIM_CARD_MASTER)
        {
            setRegStr(tmpConfig->proxyHost, handle, (char *)MMS_REG_KEY_PROXY_RELAY);
            /* Proxy POST URI */
            setRegStr(tmpConfig->proxyUri, handle, (char *)MMS_REG_KEY_POST_URI);
            /* Proxy scheme */
            setRegStr(tmpConfig->proxyScheme, handle, 
                (char *)MMS_REG_KEY_PROXY_RELAY_SCHEME);
            /* Proxy port */
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_PORT,
                (long)tmpConfig->proxyPort);
        }
        else if (MMS_SIM_CARD_SLAVE)
        {
            setRegStr(tmpConfig->slaveProxyHost, handle, (char *)MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY);
            /* Proxy POST URI */
            setRegStr(tmpConfig->slaveProxyUri, handle, (char *)MMS_REG_KEY_SLAVE_SIM_POST_URI);
            /* Proxy scheme */
            setRegStr(tmpConfig->slaveProxyScheme, handle, 
                (char *)MMS_REG_KEY_SLAVE_SIM_PROXY_RELAY_SCHEME);
            /* Proxy port */
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_SLAVE_SIM_PORT,
                (long)tmpConfig->slaveProxyPort);
        }
#else
        setRegStr(tmpConfig->proxyHost, handle, (char *)MMS_REG_KEY_PROXY_RELAY);
        /* Proxy POST URI */
        setRegStr(tmpConfig->proxyUri, handle, (char *)MMS_REG_KEY_POST_URI);
        /* Proxy scheme */
        setRegStr(tmpConfig->proxyScheme, handle, 
            (char *)MMS_REG_KEY_PROXY_RELAY_SCHEME);
        /* Proxy port */
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_PORT,
            (long)tmpConfig->proxyPort);
#endif	/*__MMS_DUAL_SIM_SUPPORT__*/
        break;
        /* This is only a group, i.e., not handled here */
    case MEA_CONFIG_SENDING:
    case MEA_CONFIG_RETRIEVAL:
    case MEA_CONFIG_FILTER:
    case MEA_CONFIG_NETWORK:
    case MEA_CONFIG_GROUPS_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACONF_89FCA19D3ED81F5363D01A907EA7E401, "(%s) (%d) erroneous configuration group\n", __FILE__, 
            __LINE__));
        break;
    }
    /* Set configuration */
    MSF_REGISTRY_SET_COMMIT(handle);   
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MACONF_9C775216EFC45D09ED9F351C3E45B926, "(%s) (%d) Config group %d saved\n", __FILE__, __LINE__, (int)group));
    return TRUE;
}


/*!
 * \brief Saves the retrieval settings to the registry
 *
 * \param tmpConfig The configuration to save.
 * \param item The item to save, See #MeaConfigRetrieve.
 *****************************************************************************/
static MSF_BOOL saveRetrievalSettings(const MeaConfig *tmpConfig, 
    MeaConfigRetrieve item)
{
    void* handle;
    /* Create new registry instance */
    handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    if (NULL == handle)
    {
        return FALSE;
    }
    /* Set params for one group */
    switch (item)
    {
    case MEA_CONFIG_HOME_NETWORK:
        /* Immediate or delayed retrieval  */
        MSF_REGISTRY_SET_PATH (handle,
            (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        
#ifdef WAP_SUPPORT
        if (MEA_RETRIEVAL_MODE_RESTRICTED == tmpConfig->retrievalMode)
        {
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
                (char *)MMS_REG_KEY_IMMEDIATE_RETRIEVAL,
                MEA_RETRIEVAL_MODE_RESTRICTED);
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
                (char *)MMS_REG_KEY_NOTIFY_RESP_MODE,
                MMS_NOTIFY_RESPONSE_REJECT);
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_IMMEDIATE_RETRIEVAL, 
                MEA_RETRIEVAL_MODE_RESTRICTED, NULL);
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_NOTIFY_RESP_MODE, 
                MMS_NOTIFY_RESPONSE_REJECT, NULL);
        }
        else
        {
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
                (char *)MMS_REG_KEY_IMMEDIATE_RETRIEVAL,
                MEA_RETRIEVAL_MODE_AUTOMATIC == tmpConfig->retrievalMode
                ? TRUE : FALSE);
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
                (char *)MMS_REG_KEY_NOTIFY_RESP_MODE,
                MMS_NOTIFY_RESPONSE_NORMAL);
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_IMMEDIATE_RETRIEVAL, 
                MEA_RETRIEVAL_MODE_AUTOMATIC == tmpConfig->retrievalMode
                ? TRUE : FALSE, NULL);
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_NOTIFY_RESP_MODE, 
                MMS_NOTIFY_RESPONSE_NORMAL, NULL);
        }
        /*
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
            (char *)MMS_REG_KEY_IMMEDIATE_RETRIEVAL,
            MEA_RETRIEVAL_MODE_AUTOMATIC == tmpConfig->retrievalMode
            ? 1 : MEA_RETRIEVAL_MODE_ALWAYS_ASK ==
            tmpConfig->retrievalMode
            ? 0: MEA_RETRIEVAL_MODE_RESTRICTED);
        */
#else
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
            (char *)MMS_REG_KEY_IMMEDIATE_RETRIEVAL,
            MEA_RETRIEVAL_MODE_AUTOMATIC == tmpConfig->retrievalMode
            ? TRUE : FALSE);
#endif /* WAP_SUPPORT */
        break;
    case MEA_CONFIG_ROAM_NETWORK:
        /* Immediate or delayed retrieval when roaming  */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_RETRIEVAL); 
        
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
            (char *)MMS_REG_KEY_RETRIEVAL_ROAM_MODE,
            MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC == 
            tmpConfig->retrievalModeRoam ? MMS_ROAM_DEFAULT 
            : MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK == 
            tmpConfig->retrievalModeRoam
#ifdef WAP_SUPPORT //change MMS_ROAM_RESTRICTED to MMS_ROAM_REJECT
            ? MMS_ROAM_DELAYED : MMS_ROAM_REJECT);
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_RETRIEVAL_ROAM_MODE, 
            MEA_RETRIEVAL_MODE_ROAMING_AUTOMATIC == 
            tmpConfig->retrievalModeRoam ? MMS_ROAM_DEFAULT 
            : MEA_RETRIEVAL_MODE_ROAMING_ALWAYS_ASK == 
            tmpConfig->retrievalModeRoam ? MMS_ROAM_DELAYED : 
            MMS_ROAM_REJECT, NULL);
#else
            ? MMS_ROAM_DELAYED : MMS_ROAM_RESTRICTED);   
#endif /* WAP_SUPPORT */

        break;
    case MEA_CONFIG_SEND_READ_REPORT:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS); 
        /* Send read reports or not  */
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_SEND_READ_REPORT,
            tmpConfig->sendReadReport);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_SEND_READ_REPORT, 
            tmpConfig->sendReadReport, NULL);
#endif /* WAP_SUPPORT */
        break;
    case MEA_CONFIG_DELIVERY_REPORT_ALLOWED:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_REPORT); 
        /* Send read reports or not  */
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_REPORT_ALLOWED,
            tmpConfig->deliveryReportAllowed);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_REPORT_ALLOWED, 
            tmpConfig->deliveryReportAllowed, NULL);
#endif /* WAP_SUPPORT */
        break;
    case MEA_CONFIG_RETRIEVE_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACONF_1E7011CC238B8143488B1E869952B2BC, "(%s) (%d) erroneous configuration item\n", __FILE__, 
            __LINE__));
        break;
    }
    /* Set configuration */
    MSF_REGISTRY_SET_COMMIT(handle);   
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MACONF_1FBAC9051452E329BD7B6DD25C3183C4, "(%s) (%d) Retrieval config item %d saved\n", __FILE__, __LINE__, 
        (int)item));
    return TRUE;
}

/*!
 * \brief Saves network settings to the registry.
 *
 * \param tmpConfig The configuration to save.
 * \param group The configuration group to save. See #MeaConfigNetwork.
 *****************************************************************************/
static MSF_BOOL saveNetworkSettings(const MeaConfig *tmpConfig, 
                               MeaConfigNetwork group)
{
    void* handle;
    /* Create new registry instance */
    handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    if (NULL == handle)
    {
        return FALSE;
    }
    switch (group)
    {
    case MEA_CONFIG_CONN_TYPE:
        /* Connection type */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_STK);
        switch (tmpConfig->connectionType)
        {
        case MEA_CONNECTION_TYPE_HTTP:
            MSF_REGISTRY_SET_ADD_KEY_INT(handle,
                (char *)MMS_REG_KEY_STK_CONNECTION_TYPE, STK_CONNECTION_TYPE_HTTP);
            break;
        case MEA_CONNECTION_TYPE_WSP_CL:
            MSF_REGISTRY_SET_ADD_KEY_INT(handle,
                (char *)MMS_REG_KEY_STK_CONNECTION_TYPE, 
                STK_CONNECTION_TYPE_WSP_CL);
            break;
        case MEA_CONNECTION_TYPE_WSP_CO:
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
                (char *)MMS_REG_KEY_STK_CONNECTION_TYPE, 
                STK_CONNECTION_TYPE_WSP_CO);
            break;
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MACONF_7CACE4E927451F40C35E3870AA18A1A9, "(%s) (%d) erroneous connection type.\n", __FILE__, __LINE__));
            break;
        }
        break;
        
    case MEA_CONFIG_NET_ACCOUNT:
        /* Network account */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_STK);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_NETWORK_ACCOUNT, 
            tmpConfig->networkAccount);
        break;
        
    case MEA_CONFIG_WAP_GW:
        /* WAP gateway */
		MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->wapGateway, handle, MMS_REG_KEY_GW_ADDRESS);
        break;
        
    case MEA_CONFIG_LOGIN:
		MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->login, handle, MMS_REG_KEY_GW_USERNAME);
        break;
        
    case MEA_CONFIG_PASSWD:
		MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->passwd, handle, MMS_REG_KEY_GW_PASSWORD);
        break;
        
    case MEA_CONFIG_REALM:
		MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->realm, handle, MMS_REG_KEY_GW_REALM);
        break;

    case MEA_CONFIG_SEC_PORT:
        /* Secure port */
		MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_GW_SECURE_PORT, 
        (long)tmpConfig->securePort);
        break;
        
    case MEA_CONFIG_HTTP_PORT:
        /* HTTP port */
		MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_GW_HTTP_PORT, 
            (long)tmpConfig->httpPort);
        break;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    case MEA_CONFIG_SLAVE_CONN_TYPE:
        /* Connection type */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_STK);
        switch (tmpConfig->slaveConnectionType)
        {
        case MEA_CONNECTION_TYPE_HTTP:
            MSF_REGISTRY_SET_ADD_KEY_INT(handle,
                (char *)MMS_REG_KEY_SLAVE_SIM_STK_CONNECTION_TYPE, STK_CONNECTION_TYPE_HTTP);
            break;
        case MEA_CONNECTION_TYPE_WSP_CL:
            MSF_REGISTRY_SET_ADD_KEY_INT(handle,
                (char *)MMS_REG_KEY_SLAVE_SIM_STK_CONNECTION_TYPE, 
                STK_CONNECTION_TYPE_WSP_CL);
            break;
        case MEA_CONNECTION_TYPE_WSP_CO:
            MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
                (char *)MMS_REG_KEY_SLAVE_SIM_STK_CONNECTION_TYPE, 
                STK_CONNECTION_TYPE_WSP_CO);
            break;
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MACONF_7CACE4E927451F40C35E3870AA18A1A9, "(%s) (%d) erroneous connection type.\n", __FILE__, __LINE__));
            break;
        }
        break;
        
    case MEA_CONFIG_SLAVE_NET_ACCOUNT:
        /* Network account */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_STK);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_SLAVE_SIM_NETWORK_ACCOUNT, 
            tmpConfig->slaveNetworkAccount);
        break;
        
    case MEA_CONFIG_SLAVE_WAP_GW:
        /* WAP gateway */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->slaveWapGateway, handle, MMS_REG_KEY_SLAVE_SIM_GW_ADDRESS);
        break;
        
    case MEA_CONFIG_SLAVE_LOGIN:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->slaveLogin, handle, MMS_REG_KEY_SLAVE_SIM_GW_USERNAME);
        break;
        
    case MEA_CONFIG_SLAVE_PASSWD:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->slavePasswd, handle, MMS_REG_KEY_SLAVE_SIM_GW_PASSWORD);
        break;
        
    case MEA_CONFIG_SLAVE_REALM:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        setRegStr(tmpConfig->slaveRealm, handle, MMS_REG_KEY_SLAVE_SIM_GW_REALM);
        break;

    case MEA_CONFIG_SLAVE_SEC_PORT:
        /* Secure port */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_SLAVE_SIM_GW_SECURE_PORT, 
        (long)tmpConfig->slaveSecurePort);
        break;
        
    case MEA_CONFIG_SLAVE_HTTP_PORT:
        /* HTTP port */
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_COM_GW);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_SLAVE_SIM_GW_HTTP_PORT, 
            (long)tmpConfig->slaveHttpPort);
        break;

#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    case MEA_CONFIG_NETWORK_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACONF_89FCA19D3ED81F5363D01A907EA7E401, "(%s) (%d) erroneous configuration group\n", __FILE__, 
            __LINE__));
        break;
    }
    /* Set configuration */
    MSF_REGISTRY_SET_COMMIT(handle);   
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MACONF_9C775216EFC45D09ED9F351C3E45B926, "(%s) (%d) Config group %d saved\n", __FILE__, __LINE__, (int)group));
    return TRUE;
}

/*!
 * \brief Saves the immediate retrieval settings to the registry
 *
 * \param tmpConfig The configuration to save.
 * \param group The configuration group to save, e.g., MMSC.
 *****************************************************************************/
static MSF_BOOL saveImRetrSettings(const MeaConfig *tmpConfig, MeaConfigFilter group)
{
    void* handle;
    /* Create new registry instance */
    handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    if (NULL == handle)
    {
        return FALSE;
    }
    /* Set params for one group */
    switch (group)
    {
    case MEA_CONFIG_IM_SIZE:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_MAX_SIZE_OF_MSG,
            (MSF_INT32)tmpConfig->maxMsgSize);
        break;

    case MEA_CONFIG_RETR_SIZE:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_MAX_RETRIEVAL_SIZE,
            (MSF_INT32)tmpConfig->maxRetrSize);
#ifdef WAP_SUPPORT
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_MAX_RETRIEVAL_SIZE, 
		   (MSF_INT32)tmpConfig->maxRetrSize, NULL);
#endif /* WAP_SUPPORT */
        break;

    case MEA_CONFIG_TREAT_AS_DEL:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, 
            (char *)MMS_REG_KEY_TREAT_AS_DELAYED_RETRIEVAL, 
            (MSF_INT32)tmpConfig->treatAsDel);
        break;
        
    case MEA_CONFIG_ALLOW_PERSONAL:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_CLASS_PERSONAL,
            tmpConfig->allowPersonal);
        break;
        
    case MEA_CONFIG_ALLOW_ADVERT:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_CLASS_ADVERTISEMENT,
            tmpConfig->allowAdvert);
#ifdef WAP_SUPPORT
       bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_CLASS_ADVERTISEMENT, 
		   tmpConfig->allowAdvert, NULL);
#endif /* WAP_SUPPORT */
        break;
        
    case MEA_CONFIG_ALLOW_INFO:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_CLASS_INFORMATIONAL,
            tmpConfig->allowInfo);
        break;
        
    case MEA_CONFIG_ALLOW_AUTO:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_CLASS_AUTO,
            tmpConfig->allowAuto);
        break;

    case MEA_CONFIG_ALLOW_ANONYM:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MMS_REG_KEY_ANONYMOUS_SENDER,
            tmpConfig->allowAnonym);
#ifdef WAP_SUPPORT
       bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MMS_REG_KEY_ANONYMOUS_SENDER, 
		   tmpConfig->allowAnonym, NULL);
#endif /* WAP_SUPPORT */
        break;
        
    case MEA_CONFIG_ALLOW_STRING:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        setRegStr(tmpConfig->allowString, handle, MMS_REG_KEY_CLASS_STRING);
        break;

    case MEA_CONFIG_IM_SERVER:
        MSF_REGISTRY_SET_PATH (handle, (char *)MMS_REG_PATH_IMMEDIATE_RETRIEVAL);
        setRegStr(tmpConfig->imServer, handle, 
            MMS_REG_KEY_IMMEDIATE_RETRIEVAL_SERVER);
        break;
    case Mea_CONFIG_RETR_COUNT:        
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACONF_89FCA19D3ED81F5363D01A907EA7E401, "(%s) (%d) erroneous configuration group\n", __FILE__, 
            __LINE__));
        break;
    }
    /* Set configuration */
    MSF_REGISTRY_SET_COMMIT(handle);   
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MACONF_9C775216EFC45D09ED9F351C3E45B926, "(%s) (%d) Config group %d saved\n", __FILE__, __LINE__, (int)group));
    return TRUE;
}

/*!
 * \brief Saves the message send settings to the registry
 *
 * \param tmpConfig The configuration to save.
 * \param group The configuration group to save, e.g., MMSC.
 *****************************************************************************/
static MSF_BOOL saveMsgSendSettings(const MeaConfig *tmpConfig, MeaConfigSend group)
{
    void* handle;
    /* Create new registry instance */
    handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    if (NULL == handle)
    {
        return FALSE;
    }
    /* Set params for one group */
    switch (group)
    {
    case MEA_CONFIG_SAVE_ON_SEND:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_SAVE_ON_SEND,
            tmpConfig->saveOnSend);
        break;
        
    case MEA_CONFIG_PRIORITY:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_PRIORITY,
            tmpConfig->priority);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_PRIORITY, 
            tmpConfig->priority, NULL);
#endif /* WAP_SUPPORT */
        break;
        
    case MEA_CONFIG_EXP_TIME:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_EXP_TIME,
            tmpConfig->expiryTime);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_EXP_TIME, 
            tmpConfig->expiryTime, NULL);
#endif /* WAP_SUPPORT */
        break;
        
    case MEA_CONFIG_READ_REPORT:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_READ_REPORT,
            tmpConfig->readReport);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_READ_REPORT, 
            tmpConfig->readReport, NULL);
#endif /* WAP_SUPPORT */
        break;
        
    case MEA_CONFIG_DELIV_REPORT:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_DELIVERY_REPORT,
            tmpConfig->deliveryReport);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_DELIVERY_REPORT, 
            tmpConfig->deliveryReport, NULL);
#endif /* WAP_SUPPORT */
        break;
        
    case MEA_CONFIG_SLIDE_DUR:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_SLIDE_DUR,
            tmpConfig->slideDuration);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_SLIDE_DUR, 
            tmpConfig->slideDuration, NULL);
#endif /* WAP_SUPPORT */
        break;

    case MEA_CONFIG_SENDER_VISIBILITY:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        /* Immediate or delayed retrieval when roaming  */
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_SENDER_VISIBILITY,
            tmpConfig->senderVisibility);
        break;
        
    case MEA_CONFIG_DELIVERY_TIME:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS); 
        /* Deliver message immediately or delayed  */
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_DELIVERY_TIME,
            tmpConfig->deliveryTime);
#ifdef WAP_SUPPORT
        bra_prof_change_key_int_value(BRA_PROF_ID_CMN, MEA_REG_KEY_DELIVERY_TIME, 
            tmpConfig->deliveryTime, NULL);
#endif /* WAP_SUPPORT */
        break;

    case MEA_CONFIG_REPLY_CHRG_MENU:
    case MEA_CONFIG_SEND_COUNT:
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACONF_89FCA19D3ED81F5363D01A907EA7E401, "(%s) (%d) erroneous configuration group\n", __FILE__, 
            __LINE__));
        return FALSE;
    }
    /* Set configuration */
    MSF_REGISTRY_SET_COMMIT(handle);   
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MACONF_9C775216EFC45D09ED9F351C3E45B926, "(%s) (%d) Config group %d saved\n", __FILE__, __LINE__, (int)group));
    return TRUE;
}

/*!
 * \brief Saves the reply charging settings to the registry
 *
 * \param tmpConfig The configuration to save.
 * \param group The configuration group to save, e.g., deadline.
 *****************************************************************************/
static MSF_BOOL saveMsgReplyChargingSettings(const MeaConfig *tmpConfig,
    MeaConfigReplyCharging group)
{
    void* handle;
    /* Create new registry instance */
    handle = MSF_REGISTRY_SET_INIT(MSF_MODID_MEA);
    if (NULL == handle)
    {
        return FALSE;
    }
    /* Set params for one group */
    switch (group)
    {
    case MEA_CONFIG_REPLY_CHARGING:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_REPLY_CHARGING,
            tmpConfig->replyCharging);
        break;
    case MEA_CONFIG_REPLY_CHARGING_DEADLINE:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle,
            (char *)MEA_REG_KEY_REPLY_CHARGING_DEADLINE,
            tmpConfig->replyChargingDeadline);
        break;
    case MEA_CONFIG_REPLY_CHARGING_SIZE:
        MSF_REGISTRY_SET_PATH (handle, (char *)MEA_REG_PATH_MMS);
        MSF_REGISTRY_SET_ADD_KEY_INT(handle, (char *)MEA_REG_KEY_REPLY_CHARGING_SIZE,
            tmpConfig->replyChargingSize);
        break;        
    default:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MACONF_89FCA19D3ED81F5363D01A907EA7E401, "(%s) (%d) erroneous configuration group\n", __FILE__, 
            __LINE__));
        return FALSE;
    }
    /* Set configuration */
    MSF_REGISTRY_SET_COMMIT(handle);   
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA,
        MACONF_9C775216EFC45D09ED9F351C3E45B926, "(%s) (%d) Config group %d saved\n", __FILE__, __LINE__, (int)group));
    return TRUE;
}

/*!
 * \brief Matches the param and the key, if they are the same the param's value
 *        are set.
 *
 * \param param The param to check.
 * \param key   The key which to match against the param.
 * \param dest  The destination to write the result to.
 * \return      TRUE if the param matches the key, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL setParamInt(const msf_registry_param_t *param, const char *key, 
    int *dest)
{
    if (0 != msf_cmmn_strcmp_nc(param->key, key))
    {
        return FALSE;
    }
    if (dest == NULL)
    {
        return FALSE;
    }
    *dest = param->value_i;
    return TRUE;
}

/*!
 * \brief Matches the param and the key, if they are the same the param's value
 *        are set.
 *
 * \param param The param to check.
 * \param key The key which to match against the param.
 * \param dest The destination to write the result to.
 * \return TRUE if the param matches the key, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL setParamStr(const msf_registry_param_t *param, const char *key, 
    char **dest)
{
    if (0 != msf_cmmn_strcmp_nc(param->key, key))
        return FALSE;
    MEA_FREE(*dest);
    *dest = MEA_ALLOC(param->value_bv_length + 1);
    strcpy(*dest, (const char *)param->value_bv);   
    return TRUE;
}

/*!
 * \brief Sets a param string value.
 *
 * \param str The string to set.
 * \param handle The handle of the param.
 * \param key The key to assign a value to.
 *****************************************************************************/
static void setRegStr(char *str, void *handle, const char *key)
{
    if (NULL == str)
    {
        MSF_REGISTRY_SET_ADD_KEY_STR(handle, (char *)key, (unsigned char *)"",
            (MSF_UINT16)(sizeof("")));
    }
    else
    {
        MSF_REGISTRY_SET_ADD_KEY_STR(handle, (char *)key, (unsigned char *)str,
            (MSF_UINT16)(strlen(str) + 1));
    }
}

/*!
 * \brief Sets a string value but deallocates the memory of destination if
 *        it exists.
 *
 * \param dst The memory to set.
 * \param src The new string value.
 *****************************************************************************/
static void setDstStr(char **dst, char *src)
{
    MEA_FREE(*dst);
    *dst = src;
}

/*!
 * \brief Gets configuration data for config GUI.
 *        This function returns 
 *
 * \param menu The menu to get data for. See #MeaConfigMenu.
 * \param configId The menu item to get data for. Valid IDs are from 
 *                 #MeaConfigGroups, #MeaConfigFilter and #MeaConfigSend.
 * \param tmpData NULL if global data should be used. Otherwise temporary data.
 * \param intValue The configuration data if it is an integer. Default 0.
 * \param strValue The configuration data if it is a string. Default NULL.
 *                 #MEA_CONFIG_MMSC, #MEA_CONFIG_SLIDE_DUR and 
 *                 #MEA_CONFIG_SLIDE_DUR as configId will cause a memory 
 *                 allocation that has to be freed.
 * \param maxStrLen Returns maximum number of characters in the string.
 * \param textType Returns the text type of the string if applicable.
 *****************************************************************************/
void meaGetConfigData(MeaConfigMenu menu, int configId, const void *tmpData, 
    int *intValue, char **strValue, int *maxStrLen, MsfTextType *textType)
{
    MeaConfig *conf;
    char *configMMSC;
    unsigned int len;
    int MmsIntValue;

    *strValue = NULL;
    *intValue = 0;
    *maxStrLen = 0;
    *textType = MsfText;

    conf = meaGetConfig();
    switch (menu) 
    {
    case MEA_CONFIG_MENU_ROOT:
        switch (configId)
        {
        case MEA_CONFIG_MMSC:
            len = 0;
            if (conf->proxyPort > 0)
            {
                len = strlen((conf->proxyScheme ? conf->proxyScheme 
                    : "http://")) + strlen((conf->proxyHost ? 
                    conf->proxyHost : "")) + 6 /*port*/ + 
                    strlen((conf->proxyUri ? conf->proxyUri : "")) +
                    strlen(":") + 1;
                if (len <= MEA_CONF_MMSC_MAX_SIZE)
                {
                    len = MEA_CONF_MMSC_MAX_SIZE + 1;
                }
                configMMSC = MEA_ALLOC((unsigned int)len);                    
                sprintf(configMMSC, "%s%s:%u%s", 
                    (conf->proxyScheme ? conf->proxyScheme : "http://"),
                    (conf->proxyHost ? conf->proxyHost : ""), 
                    conf->proxyPort, (conf->proxyUri ? conf->proxyUri : ""));
            }
            else
            {
                len = strlen((conf->proxyScheme ? conf->proxyScheme 
                    : "http://")) + 
                    strlen((conf->proxyHost ? conf->proxyHost : "")) +
                    strlen((conf->proxyUri ? conf->proxyUri : "")) + 1;
                if (len <= MEA_CONF_MMSC_MAX_SIZE)
                {
                    len = MEA_CONF_MMSC_MAX_SIZE + 1;
                }
                configMMSC = MEA_ALLOC((unsigned int)len);
                sprintf(configMMSC, "%s%s%s",
                    (conf->proxyScheme ? conf->proxyScheme : "http://"),
                    (conf->proxyHost ? conf->proxyHost : ""), 
                    (conf->proxyUri ? conf->proxyUri : ""));
            }            

            *maxStrLen = (int)len;
            *textType = MsfUrl;
            *strValue = configMMSC;
            break;
        default:
            break;
        }
        break;
    case MEA_CONFIG_MENU_SEND:
        switch (configId)
        {
        case MEA_CONFIG_EXP_TIME:
            *intValue = (tmpData ? (int)((MeaPropItem*)tmpData)->expiryTime : 
            conf->expiryTime);
            break;
        case MEA_CONFIG_READ_REPORT:
            *intValue = (tmpData ? ((MeaPropItem*)tmpData)->readReport : 
            conf->readReport);
            break;
        case MEA_CONFIG_DELIV_REPORT:
            *intValue = (tmpData ? ((MeaPropItem*)tmpData)->deliveryReport : 
            conf->deliveryReport);
            break;
        case MEA_CONFIG_PRIORITY:
            *intValue = (tmpData ? (int)((MeaPropItem*)tmpData)->priority : 
            conf->priority);
            break;
        case MEA_CONFIG_SAVE_ON_SEND:
            *intValue = conf->saveOnSend;
            break;
        case MEA_CONFIG_SLIDE_DUR:
            *strValue = MEA_ALLOC(MEA_CFG_DURATION_SIZE + 1);
            sprintf(*strValue, "%d", conf->slideDuration);            
            *maxStrLen = MEA_CFG_DURATION_SIZE;
            *textType = MsfInteger;
            break;
        case MEA_CONFIG_SENDER_VISIBILITY:
            *intValue = (tmpData ? (int)((MeaPropItem*)tmpData)->senderVisibility : conf->senderVisibility);
            break;
        case MEA_CONFIG_DELIVERY_TIME:
            *intValue = conf->deliveryTime;
            break;
        default:
            break;
        }
        break;            
    case MEA_CONFIG_MENU_REP_CHRG_SETTINGS:
        switch (configId)
        {
        case MEA_CONFIG_REPLY_CHARGING:
            *intValue = (tmpData ? (int)((MeaPropItem*)tmpData)->replyCharging 
                : conf->replyCharging);
            break;
        case MEA_CONFIG_REPLY_CHARGING_DEADLINE:
            *intValue = (tmpData 
                ? (int)((MeaPropItem*)tmpData)->replyChargingDeadline
                : conf->replyChargingDeadline);
            break;
        case MEA_CONFIG_REPLY_CHARGING_SIZE:
            *intValue = (tmpData 
                ? (int)((MeaPropItem*)tmpData)->replyChargingSize
                : conf->replyChargingSize);
            break;
        default:
            break;
        }
        break;
    case MEA_CONFIG_MENU_FILTER:
        switch (configId)
        {
        case MEA_CONFIG_IM_SERVER:
            *strValue = conf->imServer;
            *maxStrLen = MEA_CONF_MMSC_MAX_SIZE;
            *textType = MsfUrl;
            break;
        case MEA_CONFIG_IM_SIZE:
            *strValue = MEA_ALLOC(MEA_CFG_MAX_IM_RETR_SIZE_DIGITS + 1);
            sprintf(*strValue, "%d", conf->maxMsgSize);            
            *maxStrLen = MEA_CFG_MAX_IM_RETR_SIZE_DIGITS;
            *textType = MsfInteger;
            break;
        case MEA_CONFIG_RETR_SIZE:
            *strValue = MEA_ALLOC(MEA_CFG_MAX_RETRIEVAL_SIZE_DIGITS + 1);
#ifdef WAP_SUPPORT
            sprintf(*strValue, "%d", conf->maxRetrSize / MEA_1_KB);
#else
            sprintf(*strValue, "%d", conf->maxRetrSize);            
#endif /* WAP_SUPPORT */
            *maxStrLen = MEA_CFG_MAX_RETRIEVAL_SIZE_DIGITS;
            *textType = MsfInteger;
            break;
        case MEA_CONFIG_TREAT_AS_DEL:
            *intValue = conf->treatAsDel;
            break;
        case MEA_CONFIG_ALLOW_ANONYM:
            *intValue = conf->allowAnonym;
            break;
        case MEA_CONFIG_ALLOW_PERSONAL:
            *intValue = conf->allowPersonal;            
            break;
        case MEA_CONFIG_ALLOW_ADVERT:
            *intValue = conf->allowAdvert;            
            break;
        case MEA_CONFIG_ALLOW_INFO:
            *intValue = conf->allowInfo;            
            break;
        case MEA_CONFIG_ALLOW_AUTO:
            *intValue = conf->allowAuto;            
            break;
        case MEA_CONFIG_ALLOW_STRING:
            *strValue = conf->allowString;
            *maxStrLen = MEA_CONF_ALLOW_STR_MAX_SIZE;
            *textType = MsfText;
            break;
        default:
            break;
        }
    	break;
    case MEA_CONFIG_MENU_NETWORK:
        switch (configId)
        {
        case MEA_CONFIG_CONN_TYPE :
            *intValue = (int)conf->connectionType;
            break;
        case MEA_CONFIG_NET_ACCOUNT :
            *intValue = conf->networkAccount;
            break;
        case MEA_CONFIG_WAP_GW :
            *strValue = conf->wapGateway;
            *maxStrLen = MEA_CONF_WAP_GATEWAY_MAX_SIZE;
            *textType = MsfText;
            break;
        case MEA_CONFIG_LOGIN :
            *strValue = conf->login;
            *maxStrLen = MEA_CONF_LOGIN_MAX_SIZE;
            *textType = MsfText;
            break;
        case MEA_CONFIG_PASSWD :
            *strValue = conf->passwd;
            *maxStrLen = MEA_CONF_PASSWD_MAX_SIZE;
            *textType = MsfPasswordText;
            break;
        case MEA_CONFIG_REALM :
            *strValue = conf->realm;
            *maxStrLen = MEA_CONF_REALM_MAX_SIZE;
            *textType = MsfText;
            break;
        case MEA_CONFIG_SEC_PORT :
            *strValue = MEA_ALLOC(MEA_CONF_SEC_PORT_MAX_SIZE + 1);
            sprintf(*strValue, "%d", (int)conf->securePort);            
            *maxStrLen = MEA_CONF_SEC_PORT_MAX_SIZE;
            *textType = MsfInteger;
            break;
        case MEA_CONFIG_HTTP_PORT :
            *strValue = MEA_ALLOC(MEA_CONF_HTTP_PORT_MAX_SIZE + 1);
            sprintf(*strValue, "%d", (int)conf->httpPort);
            *maxStrLen = MEA_CONF_HTTP_PORT_MAX_SIZE;
            *textType = MsfInteger;
            break;
#ifdef __MMS_DUAL_SIM_SUPPORT__
        case MEA_CONFIG_SLAVE_CONN_TYPE :
            *intValue = (int)conf->slaveConnectionType;
            break;
        case MEA_CONFIG_SLAVE_NET_ACCOUNT :
            *intValue = conf->slaveNetworkAccount;
            break;
        case MEA_CONFIG_SLAVE_WAP_GW :
            *strValue = conf->slaveWapGateway;
            *maxStrLen = MEA_CONF_WAP_GATEWAY_MAX_SIZE;
            *textType = MsfText;
            break;
        case MEA_CONFIG_SLAVE_LOGIN :
            *strValue = conf->slaveLogin;
            *maxStrLen = MEA_CONF_LOGIN_MAX_SIZE;
            *textType = MsfText;
            break;
        case MEA_CONFIG_SLAVE_PASSWD :
            *strValue = conf->slavePasswd;
            *maxStrLen = MEA_CONF_PASSWD_MAX_SIZE;
            *textType = MsfPasswordText;
            break;
        case MEA_CONFIG_SLAVE_REALM :
            *strValue = conf->slaveRealm;
            *maxStrLen = MEA_CONF_REALM_MAX_SIZE;
            *textType = MsfText;
            break;
        case MEA_CONFIG_SLAVE_SEC_PORT :
            *strValue = MEA_ALLOC(MEA_CONF_SEC_PORT_MAX_SIZE + 1);
            sprintf(*strValue, "%d", (int)conf->slaveSecurePort);            
            *maxStrLen = MEA_CONF_SEC_PORT_MAX_SIZE;
            *textType = MsfInteger;
            break;
        case MEA_CONFIG_SLAVE_HTTP_PORT :
            *strValue = MEA_ALLOC(MEA_CONF_HTTP_PORT_MAX_SIZE + 1);
            sprintf(*strValue, "%d", (int)conf->slaveHttpPort);
            *maxStrLen = MEA_CONF_HTTP_PORT_MAX_SIZE;
            *textType = MsfInteger;
            break;
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        case MEA_CONFIG_NETWORK_COUNT:
            conf->roamingStatus = 0;
#ifdef __MMS_DUAL_SIM_SUPPORT__
            conf->slaveRoamingStatus = 0;
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
            break;         

        default:
            break;
        }
        break; 
        
    case MEA_CONFIG_MENU_RETRIEVE:
      switch (configId)
      {
        case MEA_CONFIG_HOME_NETWORK:
            *intValue = conf->retrievalMode;
            break;
        case MEA_CONFIG_ROAM_NETWORK:
            *intValue = conf->retrievalModeRoam;
            break;
        case MEA_CONFIG_SEND_READ_REPORT:
            *intValue = conf->sendReadReport;
            break;
        case MEA_CONFIG_DELIVERY_REPORT_ALLOWED:
            MmsIntValue = conf->deliveryReportAllowed;
            if (MmsIntValue == MMS_DELIVERY_REPORT_NO)
            {
                *intValue = 1;
            }
            else
            {
                /* Design decision: Convert MMS_DELIVERY_REPORT_NOT_SET to 0 */
                *intValue = 0;
            }        
            break;
      }
      break;
    case MEA_CONFIG_MENU_COMPOSE:
      switch (configId)
      {
        case MEA_CONFIG_COMP_CREATION_MODE:
            *intValue = meaConfGetCreationMode();
            break;
#ifdef JPG_ENCODE
        case MEA_CONFIG_COMP_IMAGE_RESIZE:
            *intValue = meaConfGetImageResize();
            break;
#endif
        case MEA_CONFIG_COMP_AUTO_SIGNATURE:
            *intValue = meaConfGetAutoSignature();
            break;
        case MEA_CONFIG_COMP_AUTO_SIGNATURE_TEXT:
            *strValue = meaConfGetAutoSignatureText();
            *maxStrLen = MEA_CONF_ALLOW_SIG_MAX_SIZE;
            break;
      }
      break;
    case MEA_CONFIG_MENU_DEFAULT:
    case MEA_CONFIG_MENU_MMS_SETTINGS:
    case MEA_CONFIG_MENU_COUNT:
    default:
        break;
    }
}


/*!
 * \brief Displays an error dialog from a string.
 *
 * \param str The string to show in the dialog.
 * \return TRUE on success, else FALSE.
 *****************************************************************************/
void meaUpdateNetworkStatusInfo(MeaStateMachine fsm, int signal)
{
    (void)MEA_SIGNAL_SENDTO_UU(MEA_CONFIG_FSM, MEA_SIG_CONF_GET_NETWORK_STATUS,
        fsm, (unsigned int)signal);
}

#ifndef WAP_SUPPORT
/*!
 * \brief Saves a provisioning element to the registry
 * 
 * \param param the provisioning element
 *****************************************************************************/
static void SaveProvisioningElement(msf_registry_param_t *param)
{
    char *str;
    int i;
    MeaConnectionType connType;

    if ((NULL != param) && (NULL != param->key))
    {
        for (i = 0; prsKeys[i].prsStr != NULL; i++)
        {
            if (msf_cmmn_strcmp_nc(param->key, prsKeys[i].prsStr) == 0) 
            {
                switch (prsKeys[i].keyId)
                {                            
                case MEA_PRS_KEY_MMSC_URL:
                case MEA_PRS_KEY_WAP_GW:
                case MEA_PRS_KEY_LOGIN:
                case MEA_PRS_KEY_PASSWORD:
                    /*
                     *	String values
                     */
                    str = NULL;
                    if (param->value_bv_length > 0)
                    {
                        MEA_CALLOC(str, param->value_bv_length+1);
                        memcpy(str, param->value_bv, param->value_bv_length);
                    } /* if */
                    if (MEA_PRS_KEY_MMSC_URL == prsKeys[i].keyId)
                    {
                        /* Special case, mmsc needs to be treated differently */
                        meaMmscCallback(str, 0, NULL, 0);
                    }
                    else
                    {
                        meaNetworkCallback(str, 0, 0, prsKeys[i].groupId);
                    } /* if */
                    break;                            
                    
                case MEA_PRS_KEY_HTTP_PORT:
                case MEA_PRS_KEY_NETWORK_ACCOUNT_ID:
                    /*
                     *	Integer values
                     */
                    meaNetworkCallback(NULL, param->value_i, 0, 
                        prsKeys[i].groupId);
                    break;
                    
                case MEA_PRS_KEY_NET_CONNECTION_TYPE:
                    /*
                     *	Mapping needed 
                     */
                    switch (param->value_i)
                    {
                    case STK_CONNECTION_TYPE_HTTP:
                        connType = MEA_CONNECTION_TYPE_HTTP;
                        break;
                    case STK_CONNECTION_TYPE_WSP_CL:
                        connType = MEA_CONNECTION_TYPE_WSP_CL;
                        break;
                    case STK_CONNECTION_TYPE_WSP_CO:
                        connType = MEA_CONNECTION_TYPE_WSP_CO;
                        break;
                    default :
                        connType = -1;
                        break;
                    } /* switch */
                    if (-1 != connType)
                    {
                        meaNetworkCallback(NULL, connType, 0, 
                            prsKeys[i].groupId);
                    } /* if */
                    break;
                    
                    default :
                        break;
                } /* switch */
            } /* if */
        } /* for */
    } /* if */
} /* SaveProvisioningElement */

/*!
 * \brief Handles input from PRS and adds it to the registry
 *
 * \param regRsp    Structure with all provisioned settings
 *****************************************************************************/
void meaSaveProvisioningData(msf_registry_response_t *regRsp)
{    
    msf_registry_param_t param;
    int i;

    /*
     *	First, clear everything.
     */
    for (i = 0; prsKeys[i].prsStr != NULL; i++)
    {
        if (MEA_PRS_KEY_CLEANSE_YES == prsKeys[i].cleanse)
        {
        /*
         *	Simulate receival of zero'ed param
         */
        memset(&param, 0, sizeof(msf_registry_param_t));
        param.key = prsKeys[i].prsStr;
        SaveProvisioningElement(&param);
        } /* if */
    } /* for */

    /*
     *	Then, fill in received provisioning parameters one by one
     */
    while (MSF_REGISTRY_RESPONSE_GET_NEXT(regRsp, &param))
    {
        SaveProvisioningElement(&param);
    } /* while */
}
#endif /* ~WAP_SUPPORT */


