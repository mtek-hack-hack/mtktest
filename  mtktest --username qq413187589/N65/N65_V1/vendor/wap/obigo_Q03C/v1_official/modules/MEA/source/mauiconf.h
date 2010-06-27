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

/*!\file mauiconf.h
 * \brief The GUI for the configuration view.
 */

#ifndef _MAUICONF_H_
#define _MAUICONF_H_

#ifdef WAP_SUPPORT //affect menu item, not string
#define MEA_CONFIG_MENU_MMS {MEA_STR_ID_CONFIG_VAL_PER, \
    MEA_STR_ID_CONFIG_DR, MEA_STR_ID_CONFIG_RR, MEA_STR_ID_CONFIG_PRIORITY,\
    0}
#else
#define MEA_CONFIG_MENU_MMS {MEA_STR_ID_CONFIG_VAL_PER, \
    MEA_STR_ID_CONFIG_RR, MEA_STR_ID_CONFIG_DR, MEA_STR_ID_CONFIG_PRIORITY,\
    MEA_STR_ID_REPLY_CHARGING, MEA_STR_ID_CONFIG_SEND_VISIBILITY, 0}
#endif /* WAP_SUPPORT */

#ifdef WAP_SUPPORT
#if defined(WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER) && WAP_CUSTOM_CFG_MMS_RETR_SIZE_FILTER == 1
#define MEA_CONFIG_MENU_MR { \
    MEA_STR_ID_MAX_RETR_SIZE, MEA_STR_ID_CONFIG_ANONYM, MEA_STR_ID_CONFIG_ADVERT, 0}
#else
#define MEA_CONFIG_MENU_MR { \
    MEA_STR_ID_CONFIG_ANONYM, MEA_STR_ID_CONFIG_ADVERT, 0}
#endif

#ifdef __MMI_MMS_BGSR_SUPPORT__
#define MEA_CONFIG_MENU_MS {MEA_STR_ID_CONFIG_VAL_PER, \
    MEA_STR_ID_CONFIG_RR, MEA_STR_ID_CONFIG_DR, MEA_STR_ID_CONFIG_PRIORITY, \
    MEA_STR_ID_DURATION, MEA_STR_ID_CONFIG_DELIVERY_TIME, MEA_STR_ID_CONFIG_SOS, 0}
#else /*__MMI_MMS_BGSR_SUPPORT__*/
#define MEA_CONFIG_MENU_MS {MEA_STR_ID_CONFIG_VAL_PER, \
    MEA_STR_ID_CONFIG_RR, MEA_STR_ID_CONFIG_DR, MEA_STR_ID_CONFIG_PRIORITY, \
    MEA_STR_ID_DURATION, MEA_STR_ID_CONFIG_DELIVERY_TIME, 0}
#endif  /*__MMI_MMS_BGSR_SUPPORT__*/ 
#else
#define MEA_CONFIG_MENU_MR {MEA_STR_ID_CONFIG_IM_SERVER, \
    MEA_STR_ID_CONFIG_IM_SIZE, MEA_STR_ID_CONFIG_TREAT_AS_DEL, \
    MEA_STR_ID_MAX_RETR_SIZE, MEA_STR_ID_CONFIG_ANONYM, \
    MEA_STR_ID_CONFIG_PERS, \
    MEA_STR_ID_CONFIG_ADVERT, MEA_STR_ID_CONFIG_INFO, MEA_STR_ID_CONFIG_AUTO, \
    MEA_STR_ID_CONFIG_USER_STRING, 0}

#define MEA_CONFIG_MENU_MS {MEA_STR_ID_CONFIG_VAL_PER, \
    MEA_STR_ID_CONFIG_RR, MEA_STR_ID_CONFIG_DR, MEA_STR_ID_CONFIG_PRIORITY, \
    MEA_STR_ID_REPLY_CHARGING, MEA_STR_ID_CONFIG_SEND_VISIBILITY, MEA_STR_ID_CONFIG_SOS, \
    MEA_STR_ID_DURATION, MEA_STR_ID_CONFIG_DELIVERY_TIME, 0}
#endif /* WAP_SUPPORT */

#define MEA_CONFIG_MENU_RETRIEVAL   {MEA_STR_ID_CONFIG_MSG_RETR_HOME_MODE, \
                                     MEA_STR_ID_CONFIG_MSG_RETR_ROAM_MODE, \
                                     MEA_STR_ID_CONFIG_SEND_READ_REPORT, \
                                     MEA_STR_ID_CONFIG_DELIVERY_REPORT_ALLOWED, 0}

#define MEA_CONFIG_MENU_REP_CHRG_ITEMS { MEA_STR_ID_REPLY_CHARGING, \
    MEA_STR_ID_REPLY_CHARGING_DEADLINE, MEA_STR_ID_REPLY_CHARGING_SIZE, 0}

#define MEA_CONFIG_MENU_MC {MEA_STR_ID_CREATION_MODE, \
	MEA_STR_ID_IMAGE_RESIZE, MEA_STR_ID_AUTO_SIGNATURE, 0}    /* not used actually */

#ifdef WAP_SUPPORT
#define MEA_CONFIG_MENU {MEA_STR_ID_CONFIG_COMPOSE, \
                         MEA_STR_ID_CONFIG_SENDING, \
                         MEA_STR_ID_CONFIG_MSG_RETRIEVAL, \
                         MEA_STR_ID_CONFIG_MSG_FILTERS, \
                         MEA_STR_ID_EDIT_PROFILE, \
                         MEA_STR_ID_MEMORY_STATUS}
                         
#else
#define MEA_CONFIG_MENU {MEA_STR_ID_CONFIG_SENDING, \
                         MEA_STR_ID_CONFIG_MSG_RETRIEVAL, \
                         MEA_STR_ID_CONFIG_MSG_FILTERS, \
                         MEA_STR_ID_CONFIG_MMSC, \
                         MEA_STR_ID_CONFIG_NETWORK}
#endif /* WAP_SUPPORT */

#define MEA_CONF_MENU_STRS_NETWORK {MEA_STR_ID_CONN_TYPE, \
                                 MEA_STR_ID_NETWORK_ACCOUNT, \
                                 MEA_STR_ID_WAP_GATEWAY, \
                                 MEA_STR_ID_LOGIN, \
                                 MEA_STR_ID_PASSWD, \
                                 MEA_STR_ID_REALM, \
                                 MEA_STR_ID_SEC_PORT, \
                                 MEA_STR_ID_HTTP_PORT}

#define MEA_CONFIG_MENU_SOS {MEA_STR_ID_OFF, \
                                MEA_STR_ID_ON, 0}
#define MEA_CONFIG_MENU_RR {MEA_STR_ID_OFF, \
                                MEA_STR_ID_ON, 0}
#define MEA_CONFIG_MENU_DR {MEA_STR_ID_OFF, \
                                MEA_STR_ID_ON, 0}
#define MEA_CONFIG_MENU_VALIDITY {MEA_STR_ID_CONFIG_1_HOUR, \
                                    MEA_STR_ID_CONFIG_6_HOURS, \
                                    MEA_STR_ID_CONFIG_12_HOURS, \
                                    MEA_STR_ID_CONFIG_1_DAY, \
                                    MEA_STR_ID_CONFIG_1_WEEK, \
                                    MEA_STR_ID_CONFIG_MAX,0}
#define MEA_CONFIG_MENU_PRIORITY {MEA_STR_ID_CONFIG_LOW, \
                                    MEA_STR_ID_CONFIG_NORMAL, \
                                    MEA_STR_ID_CONFIG_HIGH, 0}

#define MEA_CONFIG_MENU_ALLOW_PERSONAL  {MEA_STR_ID_REJECT, MEA_STR_ID_ALLOW, 0}

#define MEA_CONFIG_MENU_ALLOW_ADVERT    {MEA_STR_ID_REJECT, MEA_STR_ID_ALLOW, 0}

#define MEA_CONFIG_MENU_ALLOW_INFO      {MEA_STR_ID_REJECT, MEA_STR_ID_ALLOW, 0}

#define MEA_CONFIG_MENU_ALLOW_AUTO      {MEA_STR_ID_REJECT, MEA_STR_ID_ALLOW, 0}

#define MEA_CONFIG_MENU_ALLOW_ANONYM    {MEA_STR_ID_REJECT, MEA_STR_ID_ALLOW, 0}

#define MEA_CONFIG_MENU_TREAT_AS_DEL    {MEA_STR_ID_OFF, MEA_STR_ID_ON, 0}

#ifdef WAP_SUPPORT
#define MEA_CONFIG_MENU_RETRIEVAL_HOME  {MEA_STR_ID_DEL_RETRIEVAL, \
                                         MEA_STR_ID_IM_RETRIEVAL, \
                                         MEA_STR_ID_RES_RETRIEVAL_ROAM, 0} //MEA_STR_ID_RES_RETRIEVAL
#else
#define MEA_CONFIG_MENU_RETRIEVAL_HOME  {MEA_STR_ID_IM_RETRIEVAL, \
                                         MEA_STR_ID_DEL_RETRIEVAL, 0}
#endif /* WAP_SUPPORT */

#define MEA_CONFIG_MENU_RETRIEVAL_ROAM  {MEA_STR_ID_AUTO_RETRIEVAL_ROAM, \
                                         MEA_STR_ID_ASK_RETRIEVAL_ROAM, \
                                         MEA_STR_ID_RES_RETRIEVAL_ROAM, 0}

#define MEA_CONFIG_MENU_CONN_TYPE       {MEA_STR_ID_CONN_TYPE_HTTP, \
                                         MEA_STR_ID_CONN_TYPE_WSP_CL, \
                                         MEA_STR_ID_CONN_TYPE_WSP_CO, 0}

#define MEA_CONFIG_MENU_REPLY_CHARGING  {MEA_STR_ID_OFF,\
                                         MEA_STR_ID_ON,\
                                         MEA_STR_ID_TEXT_ONLY, 0}

#define MEA_CONFIG_MENU_REPLY_CHARGING_DEADLINE  {MEA_STR_ID_CONFIG_1_DAY,\
                                         MEA_STR_ID_CONFIG_1_WEEK,\
                                         MEA_STR_ID_CONFIG_MAX, 0}

#define MEA_CONFIG_MENU_REPLY_CHARGING_SIZE {MEA_STR_ID_CONFIG_1_KB,\
                                         MEA_STR_ID_CONFIG_10_KB,\
                                         MEA_STR_ID_CONFIG_MAX, 0}

#define MEA_CONFIG_MENU_SENDER_VISIBILITY {MEA_STR_ID_SHOW_NUMBER,\
                                           MEA_STR_ID_HIDE_NUMBER, 0}

#define MEA_CONFIG_MENU_DELIVERY_REPORT_ALLOWED {MEA_STR_ID_YES, \
                                                MEA_STR_ID_NO,0}

#define MEA_CONFIG_MENU_SEND_READ_REPORT {MEA_STR_ID_CONFIG_ON_REQUEST, \
                                          MEA_STR_ID_CONFIG_ALWAYS, \
                                          MEA_STR_ID_CONFIG_NEVER,0}
#ifdef __OP01_MMS_RETRIEVE_SETTING__
#define MEA_CFGMENU_ITEMS_RETRIEVE_ALLOWED  {MEA_STR_ID_LSK_YES, \
                                          MEA_STR_ID_RSK_NO,0}

#define MEA_CFGMENU_ITEMS_IMMEDIATELY_ROAM  {MEA_STR_ID_LSK_YES, \
                                           MEA_STR_ID_RSK_NO,0}

#define MEA_CFGMENU_ITEMS_DELIVERY_REPORT_ALLOWED    {MEA_STR_ID_RSK_NO, \
                                                    MEA_STR_ID_LSK_YES,0}

#define MEA_CFGMENU_ITEMS_SEND_READ_REPORT_ALLOWED   {MEA_STR_ID_RSK_NO, \
                                                    MEA_STR_ID_LSK_YES,0}
#endif /*__OP01_MMS_RETRIEVE_SETTING__*/

#define MEA_CONFIG_MENU_DELIVERY_TIME    {MEA_STR_ID_CONFIG_IMMEDIATE, \
                                          MEA_STR_ID_CONFIG_IN_ONE_HOUR, \
                                          MEA_STR_ID_CONFIG_IN_12_HOURS, \
                                          MEA_STR_ID_CONFIG_IN_24_HOURS,0}

#define MEA_CONFIG_MENU_COMP_CREATION_MODE {MEA_STR_ID_CREATION_MODE_FREE, \
                                          MEA_STR_ID_CREATION_MODE_RESTRICTED, 0}

#define MEA_CONFIG_MENU_COMP_AUTO_SIGNATURE {MEA_STR_ID_OFF, \
                                          MEA_STR_ID_ON, 0}

#ifdef JPG_ENCODE
    #if defined(MT6225) || defined(MT6223) || defined(MT6223P)
#define MEA_CONFIG_MENU_COMP_IMAGE_RESIZE {MEA_STR_ID_OFF, \
                                          MEA_STR_ID_160x120, \
                                          MEA_STR_ID_320x240, \
                                          0}
    #else	/*defined(MT6225) || defined(MT6223)*/
#define MEA_CONFIG_MENU_COMP_IMAGE_RESIZE {MEA_STR_ID_OFF, \
                                          MEA_STR_ID_160x120, \
                                          MEA_STR_ID_320x240, \
                                          MEA_STR_ID_640x480, \
                                          0}
    #endif	/*defined(MT6225) || defined(MT6223)*/			
#endif	/*JPG_ENCODE*/

/*! Maximum number of menu items per menu */
#ifdef WAP_SUPPORT
#define MEA_CONFIG_MAX_MENU_DEPTH 8
#else
#define MEA_CONFIG_MAX_MENU_DEPTH 12
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Constants
 *****************************************************************************/

 /******************************************************************************
 * Prototypes
 *****************************************************************************/

#ifdef WAP_SUPPORT
void meaDeleteConfMemoryStatusView(void);
#else
int  meaCreateConfigView(const MeaConfig *configValues);
#endif /* WAP_SUPPORT */
void meaConfigUiInit(void);
void meaDeleteConfigView(void);
MSF_BOOL meaConfigMenuCallback(char *str, int value, void *p1, int p2);
void meaConfigMenuBackCallback(void *p1, int p2);

MSF_BOOL meaConfigActivateMenu(MeaConfigMenu menu, int id, void *data);
void meaCreateConfComposeView(void);
void meaDeleteConfComposeView(void);
#endif


