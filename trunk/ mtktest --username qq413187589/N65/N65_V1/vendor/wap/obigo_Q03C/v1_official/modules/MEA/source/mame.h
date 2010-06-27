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

/*! \file mame.h
 *  \brief Message editor (properties) control logic. 
 */

#ifndef _MAME_H_
#define _MAME_H_

/******************************************************************************
 * Constants
 *****************************************************************************/

/* The maximum length for a input value */
#define MEA_ME_MAX_ADDRESS_SIZE     40
/*!\enum MeaMeSignalId
 * Signals for the ME FSM */
typedef enum 
{
    /*! Starts the message editor 
     *  u_param1 = startupMode 
     *  u_param2 = message id
     *  p_param  = content routing info, see #MeaMeImg.
     */
    MEA_SIG_ME_ACTIVATE,

    /*! Response from the getMessageInfo request
     *  p_param = see #MmsListOfProperties.
     */
    MEA_SIG_ME_GET_MSG_INFO_RSP,

    /*! Start reading message from disk to internal representation
     *  params: none used
     */
    MEA_SIG_ME_MR_START,    

    /*! Reading of message from disk completed
     *  u_param1 = the result, see #MeaMrResult
     *  u_param2 = number of objects exceeding size limitations 
     *  p_param = the retrieved message, see #MeaMessage
     */
    MEA_SIG_ME_MR_DONE,    

    /*! Deactivate the message editor
     *  params: none used
     */
    MEA_SIG_ME_DEACTIVATE,

    /*! Edit content of current message
     *  params: none used
     */
    MEA_SIG_ME_EDIT_CONTENT,

    /*! Edit properties of current message
     *  params: none used
     */
     MEA_SIG_ME_EDIT_PROPERTIES,

    /*! Sending and saving of the current message, 
     *  u_param1 = requesting fsm 
     *  u_param2 = callback signal 
     */
    MEA_SIG_ME_SAVE,
        
    /*! Save the current message as a template,
     *  u_param1 = requesting fsm 
     *  u_param2 = callback signal 
     */
    MEA_SIG_ME_SAVE_AS_TEMPLATE,
        
    /*! 10-Send the current message,
     *  u_param1 = requesting fsm 
     *  u_param2 = callback signal 
     */
    MEA_SIG_ME_SEND,
    /*! Send the current message,
     *  u_param1 = requesting fsm 
     *  u_param2 = callback signal 
     */
    MEA_SIG_ME_SAVE_AND_SEND,

    MEA_SIG_ME_SAVE_CONFIRM,

	MEA_SIG_ME_SEND_WITH_SIGN_DONE,

    /*! Saves the current message temporarily so that it can be previewed,
     *  u_param1 = requesting fsm 
     *  u_param2 = callback signal 
     */
    MEA_SIG_ME_SAVE_PREVIEW,

    /*! Callback signal used for message saving through MCR FSM. 
     *  i_param  = the message type, see #MmsFileType.
     *  u_param1 = result, see #MeaMcrResult, 
     *  u_param2 = msgId
     */
    MEA_SIG_ME_SAVE_DONE,

    /*! This signal is sent to the ME when the message has been sent
     *  u_param1 = result, see #MeaSendResult
     *  u_param2 = msgId  
     */
    MEA_SIG_ME_SEND_DONE,
    
    /*---- Navigation menu ----*/

    /*! Show navigation menu
     *  params: none used
     */
    MEA_SIG_ME_NAV_ACTIVATE,

    /*! Deleted the navigation menu
     *  params: none used
     */
    MEA_SIG_ME_NAV_DEACTIVATE,

    /*! Signal sent to the MEA_ME_FSM when the End User presses ok during
     *    creation of message properties.
     *  params: none used
     */
    MEA_SIG_ME_PROP_NEXT,
    
    /*! Signal sent to the MEA_ME_FSM when the End User presses back or chooses
     *    back in the navigation menu 
     *  params: none used
     */
    MEA_SIG_ME_PROP_BACK,
    
    /*! Deactivates the address input view
     *  params: none used
     */
    MEA_SIG_ME_ADDR_INPUT_DEACTIVATE,
    
    /*! Adds one or more recipient address to the current message
     *  p_param  = The addresses to append. See #MeaAddrItem
     *  u_param1 = The address to change (To or Cc), see #MeaMeProperty
     */
    MEA_SIG_ME_ADD_RECEPIENTS,

    /*! Changes a recipient address
     *  u_param1 = The address to change (To or Cc), see #MeaMeProperty
     *  u_param2 = The index of the item to change
     *  p_param  = The new entry
     */
    MEA_SIG_ME_CHANGE_RECEPIENT,

    /*! Address lookup 
     *  p_param = The lookup entry, see #MeaAddrItem
     */
    MEA_SIG_ME_LOOKUP_RSP,

    /*! Deactivates the address list view.
     *  params: none used
     */
    MEA_SIG_ME_ADDR_LIST_DEACTIVATE,

    /*! Activates the navigation menu for the address list view menu.
     *  params: none used
     */
    MEA_SIG_ME_ADDR_LIST_MENU_ACTIVATE,

    /*! Deactivates the navigation menu for the address list view menu.
     *  params: none used
     */
    MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE,

    /*! Deletes a address from the list of addresses.
     *  u_param1 = The field type, MEA_ME_TO or MEA_ME_CC
     *  u_param2 = 
     */
    MEA_SIG_ME_DELETE_ADDR_ITEM,

    /*! A send or save requested from the property editor has finished
     *	u_param1 = the result as an MSF_BOOL
     */
     MEA_SIG_ME_PROP_SAVE_DONE,
     MEA_SIG_ME_PROP_SAVE_AS_TEMPLATE_DONE,
     MEA_SIG_ME_PROP_SEND_DONE,

    /*! A send or save requested from the navigation menu has finished
     *	u_param1 = the result as an MSF_BOOL
     */
     MEA_SIG_ME_MENU_SAVE_DONE,
     MEA_SIG_ME_MENU_SAVE_AS_TEMPLATE_DONE,
     MEA_SIG_ME_MENU_SEND_DONE
    , MEA_SIG_ME_REMOVE_UNRESTRICTED_OBJECT
    , MEA_SIG_ME_CREATE_PROP_VIEW
    , MEA_SIG_ME_CREATE_PROP_RR_CONFIRM /* For show RR confirm after enter edit prop screen*/
    , MEA_SIG_ME_PROP_VIEW_SHOW_POPUP   /* Handle popup before prop view screen */
    , MEA_SIG_ME_REMOVE_INVALID_OBJECT /*remove invalid object when UC support*/
    ,MEA_SIG_ME_ADD_DEFAULT_TEMP_CONT
    ,MEA_SIG_ME_SAVE_AS_DEF_TEMPLATE
}MeaMeSignalId;

/*!\enum MeaMeStartupMode 
 * \brief Startup message types for the ME 
 */
typedef enum
{
	MEA_ME_STARTUP_NEW_MIXED = 0x01,    /*!< New multi-part mixed message */
    MEA_ME_STARTUP_NEW_SMIL,            /*!< New SMIL message             */
    MEA_ME_STARTUP_EDIT,				/*!< Edit message                 */
    MEA_ME_STARTUP_FORWARD,             /*!< Forward message              */
    MEA_ME_STARTUP_REPLY,               /*!< Reply to message             */
    MEA_ME_STARTUP_REPLY_ALL,           /*!< Reply to message             */
    MEA_ME_STARTUP_NEW_TEMPLATE,        /*!< Create a template message    */
    MEA_ME_STARTUP_APPEND_SIGNATURE,
    MEA_ME_STARTUP_SAVE_AS_TEMPLATE,
    MEA_ME_STARTUP_CREATE_DEF_TEMP,
    MEA_ME_STARTUP_FROM_TEMPLATE        /*!< Create message from template */
}MeaMeStartupMode;

/* !\enum MeaMeProperty
 *  \brief The different types of input fields in the message property editor
 */
typedef enum
{
    MEA_ME_NONE,    /*!< None of the properties selected */
    MEA_ME_TO,      /*!< The To field */
    MEA_ME_CC,      /*!< The Cc field */
    MEA_ME_BCC,     /*!< The Bcc field */
    MEA_ME_SUBJECT  /*!< The Subject field */
}MeaMeProperty;

/* Checks if a new SMIL message should be created */
#ifdef WAP_SUPPORT
#define MEA_ME_IS_NEW_SMIL_MSG(m) ((MEA_ME_STARTUP_NEW_SMIL == m) ||\
    (MEA_ME_STARTUP_REPLY == m) || (MEA_ME_STARTUP_NEW_TEMPLATE == m) ||\
    (MEA_ME_STARTUP_REPLY_ALL == m))
#else
#define MEA_ME_IS_NEW_SMIL_MSG(m) ((MEA_ME_STARTUP_NEW_SMIL == m) ||\
    (MEA_ME_STARTUP_REPLY == m) || (MEA_ME_STARTUP_NEW_TEMPLATE == m))
#endif /* WAP_SUPPORT */

/* Allow to send the message or not */
#define MEA_ME_ALLOW_SEND(m)    ((MEA_ME_STARTUP_NEW_TEMPLATE != m) && \
    (MEA_ME_STARTUP_EDIT != m))

/* Allow the  "save to template" operation */
#define MEA_ME_ALLOW_SAVE_TEMPLATE(m)  ((MEA_ME_STARTUP_NEW_SMIL == m) ||\
    (MEA_ME_STARTUP_EDIT == m) || (MEA_ME_STARTUP_FROM_TEMPLATE == m))

/******************************************************************************
 * Data-structures
 *****************************************************************************/

/* !\struct MeaMeInstance */
typedef struct
{
    MeaMeStartupMode    mode;           /*!< The start-up mode for the ME */
    MmsMsgId            origMsgId;      /*!< The msg id of the originating msg*/
    MmsFileType         origFileType;   /*!< Originating file type */
#ifdef __UNIFIED_MSG_SUPPORT__
    MSF_BOOL            delOrigMsgFlg;        /*!< Whether to delete original msg  */
#endif
    MSF_BOOL            delOrigMsgAttachmentFlg;        /*!< Whether delete attachments of the original msg */
    MmsTimeSec          lastSaved;      /*!< Last saved time */
    MSF_BOOL            sendFlg;        /*!< Whether to send when created */
    MeaCtContentInsert  *ct;            /*!< Temporary storage when inserting*/

    MeaMessage          *theMessage;    /*!< The message being edited */
    MeaStateMachine     mcrFsm;         /*!< Callback FSM */
    int                 mcrSig;         /*!< Callback signal */
    
}MeaMeInstance;

/******************************************************************************
 * Prototype declarations 
 *****************************************************************************/

void meaMeInit(void); 
void meaMeTerminate(void);
void meaMeTerminateGui(void);
#ifdef WAP_SUPPORT
void meaMeClearNavMenuSignal(void);
MSF_BOOL meaMeIsHavingEmptySlide(void);
MSF_BOOL meaMeSubjectUpdate(char *strValue);
unsigned int meaMeGetSlideCount(void);
unsigned int meaMeCalculateMsgSize(void);
void meaDisplayInlineProperty(MeaMeProperty theProperty);
int meaMeAddressAlreadyExists(MeaAddrItem *current, MeaAddrItem *items);
void meaMeAddressFilter(MeaAddrItem **list, MeaAddrType filter);
#endif /* WAP_SUPPORT */

#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
MSF_BOOL meaMeIsSaveAsTemplateMode(void);
#endif

#endif /* _MAME_H_ */


