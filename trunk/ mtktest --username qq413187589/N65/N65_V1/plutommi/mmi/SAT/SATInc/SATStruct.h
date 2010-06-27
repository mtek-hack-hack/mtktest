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

/*******************************************************************************
 * Filename:
 * ---------
 * SATStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SIM application toolkit related functions
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SATStruct.h

   PURPOSE     : SAT application 

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Mar 24,03

**************************************************************/
#ifndef _PIXTEL_SATSTRUCT_H
#define _PIXTEL_SATSTRUCT_H

#ifdef __USAT__
#include "DateTimeType.h"       /* MYTIME */
#endif 

typedef struct sat_icon_struct
{
    U8 iconAttr;
    U8 iconId;
} SATICON;

typedef struct
{
    U8 itemId;
    U16 itemLen;
    U8 itemDcs;
    U8 *itemData;
    U8 nextAction;
    U8 IconID;
#ifdef __USAT__
    U8 itemTextFormatting[4];   /* one item can only have one text formatting */
#endif 
} SATMENUITEM;

typedef struct
{
    U8 cmdDetail[5];
    U8 isHelpInfoAvailable;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 cmdDetail_2[5];
    U8 isHelpInfoAvailable_2;
#endif
    U8 numOfItem;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 numOfItem_2;
#endif
    U8 isSentRsp;
    U16 alphaIdLen;
    U8 dcsOfAlphaId;
    U8 *alphaId;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 *alphaId_2;
#endif
    U8 isIconAvailable;
    U8 IconID;
    U8 iconAttr;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 isIconAvailable_2;
    U8 IconID_2;
    U8 iconAttr_2;
#endif
    U8 noItemIconIdList;
    U8 itemIconListAttr;
    U8 noNextActionIndList;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 noItemIconIdList_2;
    U8 itemIconListAttr_2;
    U8 noNextActionIndList_2;
#endif
    /* diamond, 2005/08/28 record the last selected item for backward move to SAT main menu */
    U8 selectedMenuItem;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 selectedMenuItem_2;
#endif
#ifdef __USAT__
    U16 noTextAttribute;
    U8 *textFormatting; /* alpha id can have multiple text formattings */
#endif /* __USAT__ */ 
    SATMENUITEM *menuItems;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    SATMENUITEM *menuItems_2;
#endif
} SATSETUPMENU;

typedef struct
{
    U8 cmdDetail[5];
    U8 isHelpInfoAvailable;
    U8 defaultIndex;
    U8 numOfItem;
    U8 isSentRsp;
    U16 alphaIdLen;
    U8 dcsOfAlphaId;
    U8 *alphaId;
    U8 isIconAvailable;
    U8 IconID;
    U8 iconAttr;
    U8 noItemIconIdList;
    U8 itemIconListAttr;
    U8 noNextActionIndList;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 CMDfromSIM;
#endif
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting; /* alpha id can have multiple text formattings */
#endif /* __USAT__ */ 
    SATMENUITEM *menuItems;
} SATSUBMENU;

typedef struct
{
    U8 cmdDetail[5];
    U8 clearTextType;
    U8 immediateRes;
    U16 textStringLen;
    U8 *textString;
    U8 dcsOfTextString;
    U8 sentRsp;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 CMDfromSIM;
#endif
#ifdef __USAT__
    U8 countdownStarted;
    U32 duration;
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATDISPLAYTEXT;

typedef struct
{
    U8 cmdDetail[5];
    U8 isHelpInfoAvailable;
    U16 typeOfInput;
    U8 lenOfMinInput;
    U8 lenOfMaxInput;
    U16 lenOfTextString;
    U16 lenOfDefaultText;
    U16 lenOfInputString;
    U8 *textString;
    U8 *defaultText;
    U8 *inputString;
    U8 dcsOfTextString;
    U8 dcsOfDefaultText;
    U8 dcsOfInputString;
    U8 sentRsp;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATGETINPUT;

typedef struct
{
    U8 cmdDetail[5];
    U8 isHelpInfoAvailable;
    U16 typeOfInput;
    U8 dcsOfTextString;
    U8 *textString;
    U16 lenOfTextString;
    U8 dcsOfInputString;
    U8 inputString[4];
    U8 sentRsp;
    U8 isIconAvailable;
#ifdef __USAT__
    U8 countdownStarted;
    U32 duration;
    MYTIME startTime;
    MYTIME stopTime;
    U8 immediateDigitRes;
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    SATICON iconInfo;
} SATGETINKEY;

typedef struct
{
    U8 cmdDetail[5];
    U8 condition;
    U32 duration;
    U8 typeOfModification;
    U8 noAddr;
    U8 addr[41];
    U8 noSubaddr;
    U8 subAddr[21];
    U8 noCcp;
    U8 ccp[15];
    U8 alphaId1Present;
    U16 noAlphaId1;
    U8 *alphaId1;
    U8 dcsOfAlphaId1;
    U8 alphaId2Present;
    U16 noAlphaId2;
    U8 *alphaId2;
    U8 dcsOfAlphaId2;
    U8 *number;
    U8 isFromHistory;
    U8 isSentRsp;
    U8 exitCause;
    U8 passedConfirmScreen;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute1;
    U8 *textFormatting1;
    U16 noTextAttribute2;
    U8 *textFormatting2;
#endif /* __USAT__ */ 
    U8 isIcon1Available;
    SATICON iconInfo1;
    U8 isIcon2Available;
    SATICON iconInfo2;
} SATCALLSETUP;

typedef struct
{
    U8 cmdDetail[5];
    U8 informUser;
    U16 noAlphaId;
    U8 *alphaId;
    U8 dcsOfAlphaId;
    U8 stage1Res;
    U8 passedConf;
    U8 isSmsPackedRequired;
    U8 noAddr;
    U8 addr[41];
    U8 tpduLength;
    U8 tpdu[175];
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATSENDSMS;

typedef struct
{
    U8 cmdDetail[5];
    U8 informUser;
    U16 noAlphaId;
    U8 *alphaId;
    U8 dcsOfAlphaId;
    U8 stage1Res;
    /* diamond, 2005/12/12 Display SS reponse */
    U8 sentRsp;
    U8 ssStringLen;
    U8 *ssString;   /* original 7-bit sms packed SS string */
    U8 *textString; /* display SS string */
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATSENDSS;

typedef struct
{
    U8 cmdDetail[5];
    U8 informUser;
    U16 noAlphaId;
    U8 *alphaId;
    U8 dcsOfAlphaId;
    U8 stage1Res;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATSENDUSSD;

typedef struct
{
    U8 cmdDetail[5];
    U8 informUser;
    U16 noAlphaId;
    U8 *alphaId;
    U8 dcsOfAlphaId;
    U8 toneId;
    U8 sentRsp;
    U32 duration;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 CMDfromSIM;
#endif
#ifdef __USAT__
    U8 vibration;
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATPLAYTONE;

typedef struct
{
    U16 instance;
    U16 offset;
    U16 length;
    U16 reqlength;
    U8 width;
    U8 height;
    U8 coding;
    U8 cycle;
    U8 curcycle;
} SATIMAGEINSTANCE;

typedef struct
{
    U8 red;
    U8 green;
    U8 blue;
} SATCOLORDATA;

typedef struct
{
    U8 iconId;
    U8 noOfImages;
    SATIMAGEINSTANCE *imageInst;
    U8 *imageData;
    U8 noOfCLUT;
    U16 locOfCLUT;
    SATCOLORDATA *CLUTData;
} SATIMAGERECORD;

typedef struct
{
    U8 cmdDetail[5];
    U8 browserMode;
    U8 browserIdentity;
    U8 provisionFileId[10];
    U16 noAlphaId;
    U8 *alphaId;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U16 noUrl;
    U8 *url;
    U16 noBearer;
    U8 *bearer;
    U16 noGateway;
    U8 *gateway;
    U8 dcsOfGateway;
    U8 passedConf;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATLAUNCHBROWSER;

typedef struct
{
    U8 cmdDetail[5];
    U8 informUser;
    U16 noAlphaId;
    U8 *alphaId;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U8 noDtmf;
    U8 *dtmf;
    U8 stage1Res;
    U8 passedConf;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATSENDDTMF;

typedef struct
{
    U8 cmdDetail[5];
    U16 noAlphaId;
    U8 *alphaID;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U8 informUser;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATRUNATCOMMAND;

typedef struct
{
    U8 *iconData;
    U8 iconID;
    U8 gotFromSIM;
    /* diamond, 2005/05/26 icon */
    U8 iconAvailable;
} SATICONIMAGE;

/* diamond, 2005/05/31 sim file change notification */
#define MAX_FILE_CHANGE_NOTIFY_CALLBACK 3

typedef struct
{
    U8 isSATPresent;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 isSATPresent_2;
#endif
    U8 isInSATScreen;
    U8 isInSATMenu;
    U8 isInSATCall;
    U8 gotStage1Rsp;
    U8 lastSATCmd;
    U8 highlightedIndex;
    U8 waitTimeExpired;
    U8 currGetIconIndex;
    /* diamond, 2005/05/26 icon */
    U8 isCMDIconSupported;
    U8 getImageStage;
#ifdef __MMI_SAT_DISPLAY_TEXT_WITH_KEYPAD_LOCK__
    U8 idleSATCmd;
#endif
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 CMDfromSIM;
    U8 satIndex;
#endif
    U16 waitString;
    U16 waitImage;
    U8 *exitCondition;
    U8 *idleTextPtr;
    U8 *idleIconPtr;
    U8 *guiBufferPointer;
    FuncPtr postponedSATScreen;
    FuncPtr noResponseFuncPtr;
    FuncPtr helpFuncPtr;
    FuncPtr historyFuncPtr;
    /* diamond, 2005/05/31 sim file change notification */
    FuncPtrShort simFuncPtr[MAX_FILE_CHANGE_NOTIFY_CALLBACK];
    SATICONIMAGE iconList[MAX_ICON_SUPPORT];
} SATCONTEXT;

typedef struct
{
    U8 cmdDetail[5];
    U16 noTextString;
    U8 *textString;
    U8 dcsOfTextString;
    U8 isIconAvailable;
    SATICON iconInfo;
} SATDISPLAYIDLETEXT;

#ifdef __SATCE__
typedef struct
{
    U8 cmdDetail[5];
    U16 noAlphaId;
    U8 *alphaID;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U8 informUser;
    U8 Stage1Res;
    U8 Stage2Res;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATOPENCHANNEL;

typedef struct
{
    U8 cmdDetail[5];
    U16 noAlphaId;
    U8 *alphaID;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U8 informUser;
    U8 StageRes;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATCLOSECHANNEL;

typedef struct
{
    U8 cmdDetail[5];
    U16 noAlphaId;
    U8 *alphaID;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U8 informUser;
    U8 StageRes;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATSENDDATA;

typedef struct
{
    U8 cmdDetail[5];
    U16 noAlphaId;
    U8 *alphaID;
    U8 isAlphaIdPresent;
    U8 dcsOfAlphaId;
    U8 informUser;
    U8 StageRes;
#ifdef __USAT__
    U8 frameId;
    U16 noTextAttribute;
    U8 *textFormatting;
#endif /* __USAT__ */ 
    U8 isIconAvailable;
    SATICON iconInfo;
} SATRECVDATA;
#endif /* __SATCE__ */ 

typedef struct
{
    U8 number_of_changes;
    U8 *file_change_list;
#if (defined __MMI_DUAL_SIM_SINGLE_CALL__) || (defined __MMI_DUAL_SIM_MASTER__)
    U8 CMDfromSIM;
#endif
} SATFILECHANGE;

#endif /* _PIXTEL_SATSTRUCT_H */ 

