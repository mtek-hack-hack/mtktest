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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * EngineerModeSocketApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode socket application
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#if (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__))

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

/**********************/
/*****  Header Files *****/
/**********************/

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"

#include "MainMenuDef.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
#include "CustomCfg.h"
#include "audioInc.h"
#include "IdleAppDef.h"
#include "BootUp.h"
// #include "Profiles_prot.h"

#include "soc_api.h"
#include "app2soc_struct.h"
#include "EngineerModeSocketApp.h"
#include "EngineerModeSocketAppPing.h"

/*************************/
/*****  Extern Symbol *****/
/*************************/
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];

/*************************/
/*****  Global Symbol *****/
/*************************/
static U8 gEmPingIP1[EM_IPADDRES_LEN];
static U8 gEmPingIP2[EM_IPADDRES_LEN];
static U8 gEmPingIP3[EM_IPADDRES_LEN];
static U8 gEmPingIP4[EM_IPADDRES_LEN];
static U8 gEmPingSize[EM_MAX_INLINE_LEN];
static U8 gEmPingCount[EM_MAX_INLINE_LEN];
static U8 gEmPingTimeout[EM_MAX_INLINE_LEN];
static wgui_inline_item EmPingInlineItem[EM_MAX_INLINE_ITEM_LIST + 1];
static U8 iFdcs = 0;
static U8 EmPingCnt = 0;
ping_context_struct ping_context_g;
ping_context_struct *ping_ptr;

/*************************/
/*****  Marco Defination *****/
/*************************/
#define EM_PING_CNT_INC()       if( EmPingCnt++ >= MAX_SUB_MENUS )\
                                                        EmPingCnt = 0;

#define EM_PING_ADD_CONSOLE(buf)        {                                                                                  \
                                                                    buf[40] = '\0';                                        \
                                                                    mmi_asc_to_ucs2((PS8)subMenuData[EmPingCnt], buf);\
                                                                    subMenuDataPtrs[EmPingCnt] = subMenuData[EmPingCnt];   \
                                                                    if(EmPingCnt++ >= MAX_SUB_MENUS )                      \
                                                                       EmPingCnt = 0;                                      \
                                                                       }

#define CHECK_AND_STORE_PING_CONTEXT(a,b)        {                                                                                \
                                                                                     if( b == 0 )                                 \
                                                                                     {   EntryEmPingMenuParamError();  return;  } \
                                                                                     else                                         \
                                                                                     a = b;                                       \
                                                                                      }

/*************************/
/*****  Function Body    *****/
/*************************/


/*****************************************************************************
 * FUNCTION
 *  InitEngineerModeSocketApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEngineerModeSocketApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(EM_GPRS_PING_MENUID, HighlightEmSocketPing);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightEmSocketPing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightEmSocketPing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryEmSockePingMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EmPingPreparedIPAddressString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_buffer       [?]     
 *  IP1                 [?]     
 *  IP2                 [?]     
 *  IP3                 [?]     
 *  IP4                 [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingPreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Point[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) Point, (S8*) ".");

    mmi_ucs2cpy((PS8) string_buffer, (PS8) IP1);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP2);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP3);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP4);
}


/*****************************************************************************
 * FUNCTION
 *  EmPingInitInlinParam
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingInitInlinParam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) gEmPingIP1, (S8*) "255");
    mmi_asc_to_ucs2((S8*) gEmPingIP2, (S8*) "255");
    mmi_asc_to_ucs2((S8*) gEmPingIP3, (S8*) "255");
    mmi_asc_to_ucs2((S8*) gEmPingIP4, (S8*) "255");

    memset(gEmPingSize, 0, sizeof(gEmPingSize));
    memset(gEmPingCount, 0, sizeof(gEmPingCount));
    memset(gEmPingTimeout, 0, sizeof(gEmPingTimeout));
}


/*****************************************************************************
 * FUNCTION
 *  EmPingFillInlineStruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingFillInlineStruct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation((EmPingInlineItem + EM_GPRS_PING_IP), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((EmPingInlineItem + EM_GPRS_PING_SIZE), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((EmPingInlineItem + EM_GPRS_PING_COUNT), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((EmPingInlineItem + EM_GPRS_PING_TIMEOUT), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemCaption((EmPingInlineItem + EM_GPRS_PING_IP_STR), (U8*) GetString(EM_GPRS_PINGIP_TEXT));
    SetInlineItemCaption((EmPingInlineItem + EM_GPRS_PING_SIZE_STR), (U8*) GetString(EM_GPRS_PINGSIZE_TEXT));
    SetInlineItemCaption((EmPingInlineItem + EM_GPRS_PING_COUNT_STR), (U8*) GetString(EM_GPRS_PINGCOUNT_TEXT));
    SetInlineItemCaption((EmPingInlineItem + EM_GPRS_PING_TIMEOUT_STR), (U8*) GetString(EM_GPRS_PINGTIMEOUT_TEXT));

    BufferSize = EM_MAX_INLINE_LEN / ENCODING_LENGTH;
    SetInlineItemTextEdit((EmPingInlineItem + EM_GPRS_PING_SIZE), (U8*) (gEmPingSize), BufferSize, INPUT_TYPE_NUMERIC);
    SetInlineItemTextEdit(
        (EmPingInlineItem + EM_GPRS_PING_COUNT),
        (U8*) (gEmPingCount),
        BufferSize,
        INPUT_TYPE_NUMERIC);
    SetInlineItemTextEdit(
        (EmPingInlineItem + EM_GPRS_PING_TIMEOUT),
        (U8*) (gEmPingTimeout),
        BufferSize,
        INPUT_TYPE_NUMERIC);

    SetInlineItemIP4(
        (EmPingInlineItem + EM_GPRS_PING_IP),
        (U8*) gEmPingIP1,
        (U8*) gEmPingIP2,
        (U8*) gEmPingIP3,
        (U8*) gEmPingIP4,
        EmPingPreparedIPAddressString);

}


/*****************************************************************************
 * FUNCTION
 *  EntryEmSockePingMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmSockePingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_GPRS_PING_MENUID, ExitEmSocketPingMenu, NULL, NULL);

    EmSocketAppPingInit();
    EmPingInitInlinParam();
    InitializeCategory57Screen();
    DisableCategory57ScreenDone();
    EmPingFillInlineStruct();
    SetParentHandler(0);
    guiBuffer = GetCurrGuiBuffer(EM_GPRS_PING_MENUID);
    inputBuffer = GetCurrNInputBuffer(EM_GPRS_PING_MENUID, &inputBufferSize);   /* added for inline edit history */
    if (inputBuffer != NULL)
    {
        SetCategory57Data(EmPingInlineItem, EM_MAX_INLINE_ITEM_LIST, inputBuffer);
    }

    ShowCategory57Screen(
        EM_GPRS_PING_TEXT,
        EM_GPRS_PING_ICON,
        STR_GLOBAL_OK,
        ENGINEER_MODE_LSK_ICON,
        STR_GLOBAL_BACK,
        ENGINEER_MODE_RSK_ICON,
        EM_MAX_INLINE_ITEM_LIST,
        NULL,
        EmPingInlineItem,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EmPingCheckParam, GoBackHistory);
    SetCategory57LeftSoftkeyFunction(EmPingCheckParam);

}


/*****************************************************************************
 * FUNCTION
 *  ExitEmSocketPingMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEmSocketPingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = EM_GPRS_PING_MENUID;
    iFdcs = (U8) GetInlineEditUCS2Count(&EmPingInlineItem[1]);
    h.entryFuncPtr = EntryEmSockePingMenu;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  EntryEmPingMenuParamError
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmPingMenuParamError(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((U8*) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_ERROR, NULL, EM_NOTIFY_DURATION, (U8) WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  EmPingCheckParam
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingCheckParam(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S8 UniAddr[34];
    S8 AscAddr[34];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(AscAddr, (S8*) gEmPingCount);
    i = atoi(AscAddr);
    CHECK_AND_STORE_PING_CONTEXT(PING_CONTEXT_INFO(pingCount), i);

    mmi_ucs2_to_asc(AscAddr, (S8*) gEmPingSize);
    i = atoi(AscAddr);
    CHECK_AND_STORE_PING_CONTEXT(PING_CONTEXT_INFO(pingSize), i);

    mmi_ucs2_to_asc(AscAddr, (S8*) gEmPingTimeout);
    i = atoi(AscAddr);
    CHECK_AND_STORE_PING_CONTEXT(PING_CONTEXT_INFO(timeOutMS), i);

    EmPingPreparedIPAddressString((U8*) UniAddr, gEmPingIP1, gEmPingIP2, gEmPingIP3, gEmPingIP4);
    memset(AscAddr, 0, sizeof(AscAddr));
    mmi_ucs2_n_to_asc(AscAddr, UniAddr, 32);

    EmPingStart(AscAddr);

}


/*****************************************************************************
 * FUNCTION
 *  EmPingStart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  AscAddr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingStart(S8 *AscAddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_GPRS_PING_MENUID, ExitEmPingRspPage, NULL, NULL);

    EmPingCnt = 0;
    memset(subMenuData, 0, sizeof(subMenuData));
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
    }

    ShowCategory6Screen(
        EM_GPRS_PING_TEXT,
        (U16) 0,
        (U16) NULL,
        (U16) 0,
        STR_GLOBAL_BACK,
        (U16) 0,
        0,
        (PU8*) subMenuDataPtrs,
        NULL,
        0,
        NULL);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(EmPingStop, KEY_EVENT_UP);

    EmPingStartAct(AscAddr);

    SetProtocolEventHandler(EmPingSocNotify, MSG_ID_APP_SOC_NOTIFY_IND);
}


/*****************************************************************************
 * FUNCTION
 *  EmPingStop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingStop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_APP_SOC_NOTIFY_IND);

    EmPingStopTimer();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ExitEmPingRspPage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitEmPingRspPage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = EM_GPRS_PING_MENUID;
    currHistory.entryFuncPtr = EmPingCheckParam;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    GetCategory6History(currHistory.guiBuffer);
    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  EmPingSocNotify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingSocNotify(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*) inMsg;
    kal_bool ret_val = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (soc_notify->event_type)
    {
        case SOC_WRITE:
            EmPingSendPkt();
            break;

        case SOC_READ:
            if (PING_CONTEXT_INFO(state) == PING_ACTIVE)
            {
                ret_val = EmPingRecvPkt();
                if (ret_val == KAL_TRUE)
                {
                    EmPingSendPkt();
                }
            }
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmPingUpdateScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 *  param1      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingUpdateScreen(U8 cause, S32 param1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[80];
    double adc_value;
    sockaddr_struct *addr = &PING_CONTEXT_INFO(pingSrvAddr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case EM_PING_TIMEOUT:
            memset(buffer, 0, sizeof(buffer));
            sprintf(buffer, "Timeout...");
            EM_PING_ADD_CONSOLE(buffer);
            break;

        case EM_PING_START:
            memset(buffer, 0, sizeof(buffer));
            sprintf(buffer, "Start %d byte", PING_CONTEXT_INFO(pingSize));
            EM_PING_ADD_CONSOLE(buffer) break;

        case EM_PING_RECV:
            memset(buffer, 0, sizeof(buffer));
            sprintf(buffer, "R%02d: %dms", PING_CONTEXT_INFO(seqNo), param1);
            EM_PING_ADD_CONSOLE(buffer);
            break;

        case EM_PING_FIN:
            /* Output the statistics */
            memset(buffer, 0, sizeof(buffer));
            sprintf(buffer, "[Statstics] %d.%d.%d.%d", addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
            EM_PING_ADD_CONSOLE(buffer) memset(buffer, 0, sizeof(buffer));
            sprintf(
                buffer,
                "[Sn %d][Rv %d][Lst %d] (%d%c)",
                PING_CONTEXT_INFO(pingCount),
                PING_CONTEXT_INFO(rcvdCounter),
                PING_CONTEXT_INFO(lostCounter),
                ((PING_CONTEXT_INFO(lostCounter) * 100) / PING_CONTEXT_INFO(pingCount)),
                '%');
            EM_PING_ADD_CONSOLE(buffer) memset(buffer, 0, sizeof(buffer));
            sprintf(
                buffer,
                "[Min: %dms][Max: %dms][Avg: %dms]",
                PING_CONTEXT_INFO(minRspMS),
                PING_CONTEXT_INFO(maxRspMS),
                param1);
            EM_PING_ADD_CONSOLE(buffer) break;

        default:
            break;

    }

    ShowCategory6Screen(
        EM_GPRS_PING_TEXT,
        0,
        NULL,
        0,
        STR_GLOBAL_BACK,
        0,
        EmPingCnt,
        (PU8*) subMenuDataPtrs,
        NULL,
        (EmPingCnt - 1),
        NULL);

    SetRightSoftkeyFunction(EmPingStop, KEY_EVENT_UP);
    EntryNewScreen(EM_GPRS_PING_MENUID, ExitEmPingRspPage, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EmSocketAppPingInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmSocketAppPingInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ping_ptr = &ping_context_g;

    if (ping_ptr != NULL)
    {
        memset((void*)ping_ptr, 0, sizeof(ping_context_struct));

        PING_CONTEXT_INFO(state) = PING_INACTIVE;
        PING_CONTEXT_INFO(socketId) = -1;   /* Set a invalid value in case it's actually working. */
        PING_CONTEXT_INFO(pingCount) = 0;
        PING_CONTEXT_INFO(pingSize) = 0;
        PING_CONTEXT_INFO(pingStartFN) = 0;
        PING_CONTEXT_INFO(pingEndFN) = 0;
        PING_CONTEXT_INFO(timeOutMS) = 0;
        PING_CONTEXT_INFO(echo_req) = NULL;
        PING_CONTEXT_INFO(echo_rsp) = NULL;

        /* init statistic information */
        PING_CONTEXT_INFO(maxRspMS) = 0;
        PING_CONTEXT_INFO(minRspMS) = 0;
        PING_CONTEXT_INFO(avgRspMS) = 0;
        PING_CONTEXT_INFO(rcvdCounter) = 0;
        PING_CONTEXT_INFO(lostCounter) = 0;

        /* It's about the timer */
        /* 
         * stack_init_timer(
         * &(PING_CONTEXT_INFO(ping_rsp_timer)),
         * "PING_RSP_TIMER",
         * MOD_PING);
         */
    }

}

//==========================================
//=== Ping Lib
//==========================================


/*****************************************************************************
 * FUNCTION
 *  EmPingTimeourHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingTimeourHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char str_buff[100];
    kal_uint32 duration = 0;
    kal_uint32 avgRspMS = 0;
    sockaddr_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr = &PING_CONTEXT_INFO(pingSrvAddr);

    PING_CONTEXT_INFO(currCount)++;

    kal_sprintf(
        str_buff,
        "Timedout !seqNO: %d, currCounterL: %d",
        PING_CONTEXT_INFO(seqNo),
        PING_CONTEXT_INFO(currCount));
    kal_print(str_buff);

    if (PING_CONTEXT_INFO(pingCount) == PING_CONTEXT_INFO(currCount))
    {
        kal_print("Request timed out");
        EmPingUpdateScreen(EM_PING_TIMEOUT, -1);

        PING_CONTEXT_INFO(lostCounter)++;
        soc_close(PING_CONTEXT_INFO(socketId));
        if (PING_CONTEXT_INFO(echo_req) != NULL)
        {
            free_ctrl_buffer(PING_CONTEXT_INFO(echo_req));
        }
        if (PING_CONTEXT_INFO(echo_rsp) != NULL)
        {
            free_ctrl_buffer(PING_CONTEXT_INFO(echo_rsp));
        }
        PING_CONTEXT_INFO(echo_req) = NULL;
        PING_CONTEXT_INFO(echo_rsp) = NULL;
        PING_CONTEXT_INFO(state) = PING_INACTIVE;

        if (PING_CONTEXT_INFO(avgRspMS) == 0)
        {
            avgRspMS = 0;
        }
        else
        {
            avgRspMS = PING_CONTEXT_INFO(avgRspMS) / PING_CONTEXT_INFO(rcvdCounter);
        }
        /* Output the statistics */
        kal_mem_set(&str_buff[0], 0, 100);
        kal_sprintf(
            str_buff,
            "Ping statstics for %d.%d.%d.%d:",
            addr->addr[0],
            addr->addr[1],
            addr->addr[2],
            addr->addr[3],
            PING_CONTEXT_INFO(pingSize),
            duration);
        kal_print(str_buff);

        kal_mem_set(&str_buff[0], 0, 100);
        kal_sprintf(
            str_buff,
            "    Packets: Sent = %d, Received = %d, Lost = %d (%d%c loss)",
            PING_CONTEXT_INFO(pingCount),
            PING_CONTEXT_INFO(rcvdCounter),
            PING_CONTEXT_INFO(lostCounter),
            ((PING_CONTEXT_INFO(lostCounter) * 100) / PING_CONTEXT_INFO(pingCount)),
            '%');
        kal_print(str_buff);

        kal_mem_set(&str_buff[0], 0, 100);
        kal_sprintf(
            str_buff,
            "    Min: %dms, Max: %dms, Avg: %dms",
            PING_CONTEXT_INFO(minRspMS),
            PING_CONTEXT_INFO(maxRspMS),
            avgRspMS);
        kal_print(str_buff);

        EmPingUpdateScreen(EM_PING_FIN, avgRspMS);
    }
    else
    {
        if (PING_CONTEXT_INFO(state) == PING_ACTIVE)
        {
            PING_CONTEXT_INFO(lostCounter)++;
            kal_print("Request timed out");

            EmPingUpdateScreen(EM_PING_TIMEOUT, -1);
            EmPingSendPkt();
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EmPingSendPkt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingSendPkt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0;
    kal_uint16 j = 0;
    kal_bool ret_val = KAL_FALSE;
    kal_int16 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = PING_CONTEXT_INFO(currCount); j < PING_CONTEXT_INFO(pingCount); j++)
    {
        PING_CONTEXT_INFO(pingStartFN) = 0;
        PING_CONTEXT_INFO(pingEndFN) = 0;

        kal_mem_set(PING_CONTEXT_INFO(echo_req), 0, PING_CONTEXT_INFO(pingSize) + 8);

        PING_CONTEXT_INFO(echo_req[0]) = 8; /* echo req */

        PING_CONTEXT_INFO(echo_req[4]) = 0; /* identifier */
        PING_CONTEXT_INFO(echo_req[5]) = 100;

        PING_CONTEXT_INFO(echo_req[6]) = (kal_uint8) (PING_CONTEXT_INFO(seqNo) >> 8);   /* seq no */
        PING_CONTEXT_INFO(echo_req[7]) = (kal_uint8) (PING_CONTEXT_INFO(seqNo) & 0x00ff);

        for (i = 8; i < PING_CONTEXT_INFO(pingSize); i++)   /* dummy data */
        {
            PING_CONTEXT_INFO(echo_req[i]) = (kal_uint8) (j + 1);
        }

        //there are two choices: connect->send or sendto
        //where addr specifies the destionation of ping
        //sendto directly
        ret = soc_sendto(
                PING_CONTEXT_INFO(socketId),
                PING_CONTEXT_INFO(echo_req),
                (PING_CONTEXT_INFO(pingSize) + 8),
                0,
                &PING_CONTEXT_INFO(pingSrvAddr));
        if (ret != (PING_CONTEXT_INFO(pingSize) + 8))
        {
            if (ret == SOC_WOULDBLOCK)
            {
                kal_print("Socket said send it later");
                return;
            }

            kal_print("send ping error");
            soc_close(PING_CONTEXT_INFO(socketId));
            if (PING_CONTEXT_INFO(echo_req) != NULL)
            {
                free_ctrl_buffer(PING_CONTEXT_INFO(echo_req));
            }
            if (PING_CONTEXT_INFO(echo_rsp) != NULL)
            {
                free_ctrl_buffer(PING_CONTEXT_INFO(echo_rsp));
            }
            PING_CONTEXT_INFO(echo_req) = NULL;
            PING_CONTEXT_INFO(echo_rsp) = NULL;
            PING_CONTEXT_INFO(state) = PING_INACTIVE;

            return;

        }
        else
        {
            EmPingStartTimer(PING_CONTEXT_INFO(seqNo));
            /* PING_CONTEXT_INFO(currCount)++; */
            PING_CONTEXT_INFO(seqNo)++;
            PING_CONTEXT_INFO(pingStartFN) = TMD_System_Clock;
        }

        ret_val = EmPingRecvPkt();

        if (ret_val == KAL_FALSE)
        {
            break;
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EmPingRecvPkt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool EmPingRecvPkt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret_val = -1;
    kal_uint16 i = 0;
    kal_uint32 duration = 0;
    sockaddr_struct *addr = NULL;
    kal_char str_buff[100];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr = &PING_CONTEXT_INFO(pingSrvAddr);
    ret_val = soc_recv(PING_CONTEXT_INFO(socketId), PING_CONTEXT_INFO(echo_rsp), (PING_CONTEXT_INFO(pingSize) + 8), 0);

    kal_sprintf(str_buff, "Rcvd !seqNO: %d, currCounterL: %d", PING_CONTEXT_INFO(seqNo), PING_CONTEXT_INFO(currCount));
    kal_print(str_buff);

    if (ret_val > 0)
    {
        if ((PING_CONTEXT_INFO(echo_rsp[6]) * 256 + PING_CONTEXT_INFO(echo_rsp[7])) < PING_CONTEXT_INFO(currCount))
        {
            /* The is a invalid RSP for the waittime of this PING packet had been expiry, just ignore it */
            kal_print("Received a timed out response");
            return KAL_FALSE;
        }

        PING_CONTEXT_INFO(pingEndFN) = TMD_System_Clock;

        /* Stop timer */
        EmPingStopTimer();

        PING_CONTEXT_INFO(currCount)++;

        /* check identifier */
        if ((PING_CONTEXT_INFO(echo_rsp[4]) * 256 + PING_CONTEXT_INFO(echo_rsp[5])) != 100)
        {
            PING_CONTEXT_INFO(lostCounter)++;
            kal_print("Ping identifier wrong");
        }
        else
        {
            /* check seq no */
            if ((PING_CONTEXT_INFO(echo_rsp[6]) * 256 + PING_CONTEXT_INFO(echo_rsp[7])) !=
                (PING_CONTEXT_INFO(seqNo) - 1))
            {
                PING_CONTEXT_INFO(lostCounter)++;
                kal_print("Ping seq no wrong");
            }
            else
            {
                /* check ping data */
                for (i = 8; i < PING_CONTEXT_INFO(pingSize); i++)
                {
                    if (PING_CONTEXT_INFO(echo_rsp[i]) != (kal_uint8) PING_CONTEXT_INFO(currCount))
                    {
                        PING_CONTEXT_INFO(lostCounter)++;
                        kal_print("Ping data is wrong");
                        break;
                    }
                }

                if (i == PING_CONTEXT_INFO(pingSize))
                {
                    /* Pass all check */

                    /* Calculate the time period */
                    if (PING_CONTEXT_INFO(pingEndFN) >= PING_CONTEXT_INFO(pingStartFN))
                    {
                        duration = (((PING_CONTEXT_INFO(pingEndFN) - PING_CONTEXT_INFO(pingStartFN)) * 462) / 100);
                    }
                    else
                    {
                        duration =
                            (((2715647 + PING_CONTEXT_INFO(pingEndFN) - PING_CONTEXT_INFO(pingStartFN)) * 462) / 100);
                    }

                    /* Update statistics */
                    if (PING_CONTEXT_INFO(maxRspMS) < duration)
                    {
                        PING_CONTEXT_INFO(maxRspMS) = duration;
                    }

                    if ((PING_CONTEXT_INFO(minRspMS) == 0) || (PING_CONTEXT_INFO(minRspMS) > duration))
                    {
                        PING_CONTEXT_INFO(minRspMS) = duration;
                    }

                    PING_CONTEXT_INFO(avgRspMS) += duration;
                    PING_CONTEXT_INFO(rcvdCounter)++;

                    /* Output the result */
                    kal_sprintf(
                        str_buff,
                        "Reply from %d.%d.%d.%d: bytes=%d time=%dms",
                        addr->addr[0],
                        addr->addr[1],
                        addr->addr[2],
                        addr->addr[3],
                        PING_CONTEXT_INFO(pingSize),
                        duration);
                    kal_print(str_buff);
                    EmPingUpdateScreen(EM_PING_RECV, duration);

                    if (PING_CONTEXT_INFO(pingCount) == PING_CONTEXT_INFO(currCount))
                    {
                        soc_close(PING_CONTEXT_INFO(socketId));
                        if (PING_CONTEXT_INFO(echo_req) != NULL)
                        {
                            free_ctrl_buffer(PING_CONTEXT_INFO(echo_req));
                        }
                        if (PING_CONTEXT_INFO(echo_rsp) != NULL)
                        {
                            free_ctrl_buffer(PING_CONTEXT_INFO(echo_rsp));
                        }
                        PING_CONTEXT_INFO(echo_req) = NULL;
                        PING_CONTEXT_INFO(echo_rsp) = NULL;
                        PING_CONTEXT_INFO(state) = PING_INACTIVE;

                        /* Output the statistics */
                        kal_mem_set(&str_buff[0], 0, 100);
                        kal_sprintf(
                            str_buff,
                            "Ping statstics for %d.%d.%d.%d:",
                            addr->addr[0],
                            addr->addr[1],
                            addr->addr[2],
                            addr->addr[3],
                            PING_CONTEXT_INFO(pingSize),
                            duration);
                        kal_print(str_buff);

                        kal_mem_set(&str_buff[0], 0, 100);
                        kal_sprintf(
                            str_buff,
                            "    Packets: Sent = %d, Received = %d, Lost = %d (%d%c loss)",
                            PING_CONTEXT_INFO(pingCount),
                            PING_CONTEXT_INFO(rcvdCounter),
                            PING_CONTEXT_INFO(lostCounter),
                            ((PING_CONTEXT_INFO(lostCounter) * 100) / PING_CONTEXT_INFO(pingCount)),
                            '%');
                        kal_print(str_buff);

                        kal_mem_set(&str_buff[0], 0, 100);
                        kal_sprintf(
                            str_buff,
                            "    Min: %dms, Max: %dms, Avg: %dms",
                            PING_CONTEXT_INFO(minRspMS),
                            PING_CONTEXT_INFO(maxRspMS),
                            (PING_CONTEXT_INFO(avgRspMS) / PING_CONTEXT_INFO(rcvdCounter)));
                        kal_print(str_buff);

                        EmPingUpdateScreen(EM_PING_FIN, (PING_CONTEXT_INFO(avgRspMS) / PING_CONTEXT_INFO(rcvdCounter)));

                    }
                }
            }

            /* PING_CONTEXT_INFO(seqNo)++; */

        }

        return KAL_TRUE;
    }
    else if (ret_val == SOC_WOULDBLOCK)
    {
        /* return KAL_FALSE to break out the for loop and wait for notification or timeout message */
        return KAL_FALSE;
    }
    else
    {
        /* If happen, ask Kavien to have a look */
        ASSERT(ret_val > 0);
    }

    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  EmPingStartAct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serv_addr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingStartAct(kal_char *serv_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 acc_id = 5;  /* account id */
    kal_uint16 i, j = 0;
    kal_char str_buff[50];
    kal_uint8 val = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PING_CONTEXT_INFO(state) = PING_ACTIVE;

    /* Clean all the statistics for the previous session */
    PING_CONTEXT_INFO(maxRspMS) = 0;
    PING_CONTEXT_INFO(minRspMS) = 0;
    PING_CONTEXT_INFO(avgRspMS) = 0;
    PING_CONTEXT_INFO(rcvdCounter) = 0;
    PING_CONTEXT_INFO(lostCounter) = 0;

    if (PING_CONTEXT_INFO(echo_req) != NULL)
    {
        free_ctrl_buffer(PING_CONTEXT_INFO(echo_req));
    }

    if (PING_CONTEXT_INFO(echo_rsp) != NULL)
    {
        free_ctrl_buffer(PING_CONTEXT_INFO(echo_rsp));
    }

    /* PING_CONTEXT_INFO(socketId) = soc_create(PF_INET, SOCK_RAW, IPPROTO_ICMP, MOD_PING, acc_id); */
    PING_CONTEXT_INFO(socketId) = soc_create(PF_INET, SOCK_RAW, IPPROTO_ICMP, MOD_MMI, acc_id);

    if (PING_CONTEXT_INFO(socketId) >= 0)
    {

        if (soc_setsockopt(PING_CONTEXT_INFO(socketId), SOC_NBIO, &val, sizeof(val)) < 0)
        {
            kal_print("Set socket to nonblock mode error !!");
            return;
        }

        val = SOC_READ | SOC_WRITE;

        if (soc_setsockopt(PING_CONTEXT_INFO(socketId), SOC_ASYNC, &val, sizeof(val)) < 0)
        {
            kal_print("Set socket to nonblock mode error !!");
            return;
        }

        PING_CONTEXT_INFO(echo_req) = (kal_uint8*) get_ctrl_buffer(PING_CONTEXT_INFO(pingSize) + 8);
        PING_CONTEXT_INFO(echo_rsp) = (kal_uint8*) get_ctrl_buffer(PING_CONTEXT_INFO(pingSize) + 8);

        PING_CONTEXT_INFO(seqNo) = 0;
        PING_CONTEXT_INFO(currCount) = 0;

        PING_CONTEXT_INFO(pingSrvAddr.port) = 100;      /* identifier */
        PING_CONTEXT_INFO(pingSrvAddr.addr_len) = 4;    /* any */
        PING_CONTEXT_INFO(pingSrvAddr.addr[0]) = 0;
        PING_CONTEXT_INFO(pingSrvAddr.addr[1]) = 0;
        PING_CONTEXT_INFO(pingSrvAddr.addr[2]) = 0;
        PING_CONTEXT_INFO(pingSrvAddr.addr[3]) = 0;

        if (soc_bind(PING_CONTEXT_INFO(socketId), &PING_CONTEXT_INFO(pingSrvAddr)) != 0)
        {
            soc_close(PING_CONTEXT_INFO(socketId));
            if (PING_CONTEXT_INFO(echo_req) != NULL)
            {
                free_ctrl_buffer(PING_CONTEXT_INFO(echo_req));
            }

            if (PING_CONTEXT_INFO(echo_rsp) != NULL)
            {
                free_ctrl_buffer(PING_CONTEXT_INFO(echo_rsp));
            }
            PING_CONTEXT_INFO(echo_req) = NULL;
            PING_CONTEXT_INFO(echo_rsp) = NULL;

            kal_print("bind error");
        }

        PING_CONTEXT_INFO(pingSrvAddr.addr[0]) = atoi(strtok(serv_addr, "."));  /* ip string: "140.112.1.1" to integer */
        PING_CONTEXT_INFO(pingSrvAddr.addr[1]) = atoi(strtok(NULL, "."));
        PING_CONTEXT_INFO(pingSrvAddr.addr[2]) = atoi(strtok(NULL, "."));
        PING_CONTEXT_INFO(pingSrvAddr.addr[3]) = atoi(strtok(NULL, "."));
        PING_CONTEXT_INFO(pingSrvAddr.addr_len) = 4;

        kal_sprintf(
            str_buff,
            "Pinging %d.%d.%d.%d with %d bytes of data",
            PING_CONTEXT_INFO(pingSrvAddr.addr[0]),
            PING_CONTEXT_INFO(pingSrvAddr.addr[1]),
            PING_CONTEXT_INFO(pingSrvAddr.addr[2]),
            PING_CONTEXT_INFO(pingSrvAddr.addr[3]),
            PING_CONTEXT_INFO(pingSize));
        kal_print(str_buff);
        EmPingUpdateScreen(EM_PING_START, -1);
        EmPingSendPkt();

    }   /* if(s >= 0) */
    else
    {
        ASSERT(PING_CONTEXT_INFO(socketId) >= 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EmPingStartTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seqNo       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingStartTimer(kal_uint16 seqNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(EM_GPRS_PING_TIMER, PING_CONTEXT_INFO(timeOutMS), EmPingTimeourHandler);
}


/*****************************************************************************
 * FUNCTION
 *  EmPingStopTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmPingStopTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_GPRS_PING_TIMER);
}

#endif /* (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__)) */ 

