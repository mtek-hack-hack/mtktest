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

/*! \file maconf.g
 *  Header file for the configuration of the MEA.
 */

#ifndef _MACONF_H_
#define _MACONF_H_

#ifndef _MMS_DEF_H
#error You must include mms_def.h before maconf.h!
#endif

#ifndef _MATYPES_H_
#error You must include matypes.h before maconf.h!
#endif

#ifndef _msf_core_h
#error You must include msf_core.h before maconf.h!
#endif

/****************************************************************************
 * Constants 
 ****************************************************************************/

/* <! Schemes that are supported by the MEA */
#define MEA_CR_SCHEME               "Scheme"
#define MEA_CR_PATH                 "/MSM/RT_DB/MEA"

/*!\enum MeaConfigSignalId
 * \brief Signals in CONF
 */
typedef enum 
{
    /* 
     * Get the configuration and start the application GUI.
     */
    MEA_SIG_CONF_INITIAL_ACTIVATE,

    /* 
     * Start configuration menu GUI.
     */
    MEA_SIG_CONF_ACTIVATE,

    /* 
     * Start settings menu GUI.
     */
    MEA_SIG_CONF_ACTIVATE_SETTINGS,

    /* 
     * Terminate configuration menu GUI.
     */
    MEA_SIG_CONF_DEACTIVATE,

    /* The response from a get registry key operation
     * p_param = the response
     */
    MEA_SIG_CONF_GET_REG_RSP,

    /* External requests to refresh network status variables */
    MEA_SIG_CONF_GET_NETWORK_STATUS,

#ifdef WAP_SUPPORT
    /* Save conf value for message settings */
    MEA_SIG_CONF_SAVE_SETTINGS,

    /* Save creation settings */
    MEA_SIG_CONF_SAVE_COMPOSE,
#endif /* WAP_SUPPORT */

    /*! No signal !*/
    MEA_SIG_CONF_SIGMAX
} MeaConfigSignalId;

/* The name of the sender */
#define MEA_CONF_FROM_NAME_MAX_SIZE     50

/* The address of the sender */
#define MEA_CONF_FROM_ADDR_MAX_SIZE     50

/* The proxy address for the MMSC */
#define MEA_CONF_PROXY_ADDR_MAX_SIZE    50

/* The proxy URI for the MMSC */
#define MEA_CONF_PROXY_URI_MAX_SIZE     50

/* The proxy port for the MMSC */
#define MEA_CONF_PROXY_PORT_MAX_SIZE    6

/* Proxy scheme gadget properties */
#define MEA_CONF_PROXY_SCHEME_MAX_SIZE  50

/* WAP gateway address */
#define MEA_CONF_WAP_GATEWAY_MAX_SIZE   50

/* Username for the WAP gateway */
#define MEA_CONF_LOGIN_MAX_SIZE         25

/* Password for the WAP gateway */
#define MEA_CONF_PASSWD_MAX_SIZE        25

/* Realm */
#define MEA_CONF_REALM_MAX_SIZE         50

/* Secure port */
#define MEA_CONF_SEC_PORT_MAX_SIZE      6

/* HTTP port */
#define MEA_CONF_HTTP_PORT_MAX_SIZE     6

/* Max message size for immediate retrieval */
#define MEA_CONF_MSG_SIZE_MAX_SIZE      10

/* Maximum input size for the MMSC*/
#define MEA_CONF_MMSC_MAX_SIZE          300

/* Max length (characters) for message class definition */
#define MEA_CONF_ALLOW_STR_MAX_SIZE     100

#ifdef WAP_SUPPORT
#define MEA_CONF_ALLOW_SIG_MAX_SIZE     128
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Data types 
 *****************************************************************************/


/******************************************************************************
 * Function declarations 
 *****************************************************************************/

MeaConfig *meaGetConfig(void);
void meaCopyConfig(MeaConfig *dst);
void meaConfInit(void);
void meaConfTerminate(void);
int  meaIsCreateConfValid(void);
MSF_BOOL meaSaveOnSendCallback(char *str, int value, void *p1, int p2);
#ifdef WAP_SUPPORT
void meaProfNetworkCallback(char *path, char *key, int type, int ival, char *sval);
void meaSaveOnSendSet(int value);
MeaCreationModeType meaConfGetCreationMode(void);
  #ifdef JPG_ENCODE
MeaImageResizeType meaConfGetImageResize(void);
void meaConfGetImageResizeValue(MsfSize *size);
  #endif
MSF_BOOL meaConfGetAutoSignature(void);
#endif /* WAP_SUPPORT */
MSF_BOOL meaExpTimeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaReadReportCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaDelivReportCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaPriorityCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaSlideDurCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaReplyChargingCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaReplyChargingDeadlineCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaReplyChargingSizeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaRetrievalHomeModeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaRetrievalRoamModeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaImRetrSizeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaTreatAsDelCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaAllowAdvertCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaAllowPersonalCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaAllowInfoCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaAllowAutoCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaAllowAnonymCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaAllowStringCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaImServerCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaDeliveryReportAllowedCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaSendReadReportCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaDeliveryTimeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaMmscCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaNetworkCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaDownloadSizeCallback(char *str, int value, void *p1, int p2);
MSF_BOOL meaSenderVisibilityCallback(char *str, int value, void *p1, int p2);
void meaGetConfigData(MeaConfigMenu menu, int configId, const void *tmpData, 
    int *intValue, char **strValue, int *maxStrLen, MsfTextType *textType);
void meaUpdateNetworkStatusInfo(MeaStateMachine fsm, int signal);
#ifdef WAP_SUPPORT
MSF_BOOL meaDownloadSizeVerify(char * strbuf);
#else
void meaSaveProvisioningData(msf_registry_response_t *regRsp);
#endif /* WAP_SUPPORT*/
#endif /* _MACONF_H_ */


