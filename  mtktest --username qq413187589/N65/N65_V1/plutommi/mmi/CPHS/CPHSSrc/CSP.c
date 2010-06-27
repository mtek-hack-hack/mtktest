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
 *  CSP.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

   FILENAME : CSP.c

   PURPOSE     : Customer Service Profile

   REMARKS     : nil

   AUTHOR      : NEERAJ SHARMA

   DATE     : Aug 6,03

**************************************************************/
#include "MMI_include.h"
#include "CSP.h"
#ifdef __MOD_SMSAL__
#include "MessagesExDcl.h"
#endif 

U8 cpsInfoArray[CSP_TOTAL_SERVICE_GROUP];
U8 cpsInfoArray_2[CSP_TOTAL_SERVICE_GROUP];
U8 isCSPPresent = 0;
U8 bootupOver = 0;


/*****************************************************************************
 * FUNCTION
 *  SetCSPGroupService
 * DESCRIPTION
 *  Sets Bit in CSP Array about CSP Service as per
 *  service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
void SetCSPGroupService(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetBit(cpsInfoArray[serviceGroup], service);
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  SetCSPGroupService_2
 * DESCRIPTION
 *  Sets Bit in CSP Array about CSP Service as per
 *  service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
void SetCSPGroupService_2(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetBit(cpsInfoArray_2[serviceGroup], service);
}

#endif /*__MMI_DUAL_SIM_MASTER__*/


/*****************************************************************************
 * FUNCTION
 *  ResetCSPGroupService
 * DESCRIPTION
 *  Resets Bit in CSP Array about CSP Service as per
 *  service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCSPGroupService(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetBit(cpsInfoArray[serviceGroup], service);
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  ResetCSPGroupService_2
 * DESCRIPTION
 *  Resets Bit in CSP Array about CSP Service as per
 *  service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
void ResetCSPGroupService_2(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetBit(cpsInfoArray_2[serviceGroup], service);
}

#endif /*__MMI_DUAL_SIM_MASTER__*/


/*****************************************************************************
 * FUNCTION
 *  IsSetCSPGroupService
 * DESCRIPTION
 *  Checks if Bit ise set in CSP Array about CSP Service
 *  as per service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
U8 IsSetCSPGroupService(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (IsBitSet(cpsInfoArray[serviceGroup], service));
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  IsSetCSPGroupService_2
 * DESCRIPTION
 *  Checks if Bit ise set in CSP Array about CSP Service
 *  as per service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
U8 IsSetCSPGroupService_2(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (IsBitSet(cpsInfoArray_2[serviceGroup], service));
}

#endif /*__MMI_DUAL_SIM_MASTER__*/


/*****************************************************************************
 * FUNCTION
 *  IsResetCSPGroupService
 * DESCRIPTION
 *  Checks if Bit is reset in CSP Array about CSP Service
 *  as per service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
U8 IsResetCSPGroupService(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (IsBitReset(cpsInfoArray[serviceGroup], service));
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  IsResetCSPGroupService_2
 * DESCRIPTION
 *  Checks if Bit is reset in CSP Array about CSP Service
 *  as per service group & sevice
 * PARAMETERS
 *  serviceGroup        [IN]        Service Group of CSP
 *  service             [IN]        Service in the group
 * RETURNS
 *  void
 *****************************************************************************/
U8 IsResetCSPGroupService_2(U8 serviceGroup, U8 service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (IsBitReset(cpsInfoArray_2[serviceGroup], service));
}

#endif /*__MMI_DUAL_SIM_MASTER__*/


/*****************************************************************************
 * FUNCTION
 *  IsInformationNumberAlowed
 * DESCRIPTION
 *  Checks if Information Number is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
U8 IsInformationNumberAlowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cpsInfoArray[CSP_INFORMATION_NO_SERVICE_GROUP] == 0xFF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ClearCSPArray
 * DESCRIPTION
 *  Clears Information in CSP Array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearCSPArray(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)cpsInfoArray, 0xFF, CSP_TOTAL_SERVICE_GROUP);
#ifdef __MMI_DUAL_SIM_MASTER__
    memset((void*)cpsInfoArray_2, 0xFF, CSP_TOTAL_SERVICE_GROUP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  InitialiseCSPInfoArray
 * DESCRIPTION
 *  Initialises CSP Infor
 * PARAMETERS
 *  cspInfo     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void InitialiseCSPInfoArray(U8 *cspInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //PRINT_INFORMATION("<<CPHS>>In InitialiseCSPInfoArray");
    for (i = 0; i < 22; i++)
    {
        switch (cspInfo[i])
        {
            case 0x01:
                cpsInfoArray[CSP_CALL_OFFERING_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x02:
                cpsInfoArray[CSP_CALL_RESTRICTION_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x03:
                cpsInfoArray[CSP_OTHER_SS_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x04:
                cpsInfoArray[CSP_CALL_COMPLETION_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x05:
                cpsInfoArray[CSP_TELESERVICES_SERVICE_GROUP] = cspInfo[++i];
        #ifdef __MMI_CSP_SMS_COMMON_SETTING_ALWAYS_ON__
                cpsInfoArray[CSP_TELESERVICES_SERVICE_GROUP] |= 0x18; /* Always turn on SMS common setting */
        #endif
                break;
            case 0x06:
                cpsInfoArray[CSP_CPHS_TELESERVICES_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x07:
                cpsInfoArray[CSP_CPHS_FEATURES_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x08:
                cpsInfoArray[CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x09:
                cpsInfoArray[CSP_PHASE_2_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0xC0:
                cpsInfoArray[CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP] = cspInfo[++i];
        #ifdef __MMI_CSP_LANG_SEL_MENU_ALWAYS_ON__
                cpsInfoArray[CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP] |= 0x01; /* Always turn on language selection */
        #endif
                break;
            case 0xD5:
                cpsInfoArray[CSP_INFORMATION_NO_SERVICE_GROUP] = cspInfo[++i];
                break;
        }
    }
    isCSPPresent = 1;
    if (bootupOver)
    {
    #ifndef __MMI_DUAL_SIM_MASTER__
        CSPModifyHiliteHandlers();
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  InitialiseCSPInfoArray_2
 * DESCRIPTION
 *  Initialises CSP Infor
 * PARAMETERS
 *  cspInfo     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void InitialiseCSPInfoArray_2(U8 *cspInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //PRINT_INFORMATION("<<CPHS>>In InitialiseCSPInfoArray");
    for (i = 0; i < 22; i++)
    {
        switch (cspInfo[i])
        {
            case 0x01:
                cpsInfoArray_2[CSP_CALL_OFFERING_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x02:
                cpsInfoArray_2[CSP_CALL_RESTRICTION_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x03:
                cpsInfoArray_2[CSP_OTHER_SS_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x04:
                cpsInfoArray_2[CSP_CALL_COMPLETION_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x05:
                cpsInfoArray_2[CSP_TELESERVICES_SERVICE_GROUP] = cspInfo[++i];
        #ifdef __MMI_CSP_SMS_COMMON_SETTING_ALWAYS_ON__
                cpsInfoArray_2[CSP_TELESERVICES_SERVICE_GROUP] |= 0x18; /* Always turn on SMS common setting */
        #endif
                break;
            case 0x06:
                cpsInfoArray_2[CSP_CPHS_TELESERVICES_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x07:
                cpsInfoArray_2[CSP_CPHS_FEATURES_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x08:
                cpsInfoArray_2[CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0x09:
                cpsInfoArray_2[CSP_PHASE_2_SERVICE_GROUP] = cspInfo[++i];
                break;
            case 0xC0:
                cpsInfoArray_2[CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP] = cspInfo[++i];
        #ifdef __MMI_CSP_LANG_SEL_MENU_ALWAYS_ON__
                cpsInfoArray_2[CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP] |= 0x01; /* Always turn on language selection */
        #endif
                break;
            case 0xD5:
                cpsInfoArray_2[CSP_INFORMATION_NO_SERVICE_GROUP] = cspInfo[++i];
                break;
        }
    }
}

#endif /*__MMI_DUAL_SIM_MASTER__*/


/*****************************************************************************
 * FUNCTION
 *  CSPCallMain
 * DESCRIPTION
 *  Changes Hilite Handlers of CM in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallMain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOAC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC_exHC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BAIC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BIC_Roam))
    {
        mmi_frm_hide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_BARRING);
    }

    if (IsResetCSPGroupService(CSP_OTHER_SS_SERVICE_GROUP, CSP_CUG))
    {
        mmi_frm_hide_menu_item(MENU_SETTING_CALL_CLOSED_GP);
    }

    if (IsResetCSPGroupService(CSP_CALL_COMPLETION_SERVICE_GROUP, CSP_CW))
    {
        mmi_frm_hide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_WAIT);
    }

#ifdef __CPHS_FEATURE_DEFAULT_OFF__
    if (IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS) == 0)
    {
        mmi_frm_unhide_menu_item(MENU_LINE_SWCH);
    }
#else /* __CPHS_FEATURE_DEFAULT_OFF__ */
    if (IsResetCSPGroupService(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
    {
        mmi_frm_hide_menu_item(MENU_LINE_SWCH);
    }
#endif /* __CPHS_FEATURE_DEFAULT_OFF__ */
}


/*****************************************************************************
 * FUNCTION
 *  CSPPhoneSetup
 * DESCRIPTION
 *  Changes Hilite Handlers of Phone Setup in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPPhoneSetup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_Language))
    {
        mmi_frm_hide_menu_item(MENU_SETTING_LANGUAGE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPCallBarringMainMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Call Barring Main Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallBarringMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOAC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC_exHC))
    {
        mmi_frm_hide_menu_item(MENU_CALL_BARRING_OUTGOING);
    }

    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BAIC) &&
        IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BIC_Roam))
    {
        mmi_frm_hide_menu_item(MENU_CALL_BARRING_INCOMING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPCallBarringOutgoingMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Call Barring Outgoing Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallBarringOutgoingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOAC))
    {
        mmi_frm_hide_menu_item(MENU_BARRING_OUTGOING_ALLCALLS);
    }

    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC))
    {
        mmi_frm_hide_menu_item(MENU_BARRING_OUTGOING_INTERCALL);
    }

    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC_exHC))
    {
        mmi_frm_hide_menu_item(MENU_BARRING_OUTGOING_INTEREXCEPTHOME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPCallBarringIncomingMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Call Barring Incoming Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallBarringIncomingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BAIC))
    {
        mmi_frm_hide_menu_item(MENU_BARRING_INCOMING_ALLCALLS);
    }

    if (IsResetCSPGroupService(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BIC_Roam))
    {
        mmi_frm_hide_menu_item(MENU_BARRING_INCOMING_ROAMING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPCallForwardingMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Call Fwd. Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallForwardingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    U8 cfu_cnt = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFU))
    {
        mmi_frm_hide_menu_item(MENU8238_MNGCALL_CALFWD_VOICECALL);
    }

    if (IsResetCSPGroupService(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFNRc))
    {
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_UNREACHABLE);
    }
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    else
    {
        cfu_cnt++;
    }
#endif /* __MMI_SS_CF_ALLCOND_MENU__ */

    if (IsResetCSPGroupService(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFNRy))
    {
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_NOANSWER);
    }
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    else
    {
        cfu_cnt++;
    }
#endif /* __MMI_SS_CF_ALLCOND_MENU__ */

    if (IsResetCSPGroupService(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFB))
    {
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_BUSY);
    }
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    else
    {
        cfu_cnt++;
    }
#endif /* __MMI_SS_CF_ALLCOND_MENU__ */

#ifdef __MMI_SS_CF_ALLCOND_MENU__
    if (cfu_cnt == 3)
    {
        /* CPHS: if bit 5, 6, 7 are set as 1 for this group, a conditional forwarding menu is used to replace these 3 menus */
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_UNREACHABLE);
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_NOANSWER);
        mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_BUSY);
        mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_ALLCOND);
    }
#endif /* __MMI_SS_CF_ALLCOND_MENU__ */

    if (IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_Data))
    {
        mmi_frm_hide_menu_item(MENU8238_MNGCALL_CALFWD_DATACALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPCallerIdMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Caller ID Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallerIdMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP, CSP_CLI_block))
    {
        mmi_frm_hide_menu_item(MENU_CID_HIDE_ID);
    }

    if (IsResetCSPGroupService(CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP, CSP_CLI_send))
    {
        mmi_frm_hide_menu_item(MENU_CID_SHOW_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPCallHistoryMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Call History Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPCallHistoryMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_OTHER_SS_SERVICE_GROUP, CSP_AoC))
    {
        mmi_frm_hide_menu_item(MENU_CALL_HISTORY_CALLCOST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPNetworkSelectionMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Network Selection Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPNetworkSelectionMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_PLMN_MODE))
    {
        mmi_frm_hide_menu_item(MENU9186_SELECTION_MODE);
    }

    if (IsResetCSPGroupService(CSP_PHASE_2_SERVICE_GROUP, CSP_Multiple_Band))
    {
        mmi_frm_hide_menu_item(MENU9188_BAND_SELECTION);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPMesagesMainMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Messages Main Menu Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPMesagesMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_SM_MT))
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        mmi_frm_hide_menu_item(MENU_ID_UM_INBOX);
    #else
        mmi_frm_hide_menu_item(MESSAGES_MENU_INBOX_MENUID);
    #endif
    }

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_SM_MO))
    {
    #ifdef __MMI_UNIFIED_MESSAGE__
        mmi_frm_hide_menu_item(MENU_ID_UM_WRITE_MSG);
        mmi_frm_hide_menu_item(MENU_ID_UM_UNSENT);
        mmi_frm_hide_menu_item(MENU_ID_UM_SENT);
        mmi_frm_hide_menu_item(MENU_ID_UM_DRAFT);
    #else
        mmi_frm_hide_menu_item(MESSAGES_MENU_WMESSAGE_MENU_ID);
        mmi_frm_hide_menu_item(MESSAGES_MENU_OUTBOX_MENUID);
    #endif
    }

    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_SM_CB))
    {
        mmi_frm_hide_menu_item(MESSAGES_MENU_CB_MENUID);
    }

    if (IsResetCSPGroupService(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_VPS))
    {
        mmi_frm_hide_menu_item(MESSAGES_MENU_VMAIL_MENUID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPMessageSettingMenu
 * DESCRIPTION
 *  Changes Hilite Handlers of Message Setting Menu Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPMessageSettingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/07/01 new menu item architecture */
    if (IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Del_Conf) &&
        IsResetCSPGroupService(CSP_TELESERVICES_SERVICE_GROUP, CSP_Reply_path))
    {
        mmi_frm_hide_menu_item(SETUP_MENU_COMMONSETTING_MENUID);
    }
}

/* diamond, 2005/07/01 new menu item architecture */


/*****************************************************************************
 * FUNCTION
 *  CSPOutgoingCallManagement
 * DESCRIPTION
 *  Changes Hilite Handlers of Outgoing Call Management Menu Screen
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPOutgoingCallManagement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsResetCSPGroupService(CSP_OTHER_SS_SERVICE_GROUP, CSP_MPTY))
    {
        mmi_frm_hide_menu_item(MITEM2015_CM_CALL_CONFER);
    }

    if (IsResetCSPGroupService(CSP_CALL_COMPLETION_SERVICE_GROUP, CSP_HOLD))
    {
        mmi_frm_hide_menu_item(MITEM2010_CM_ACTIVE_HOLD);
    }
}

/* end, diamond */


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_puct_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  puct        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_puct_check(U8 puct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
    if (puct == 0 || sim_service_table_query(SERVICE_AOC, 0) == SERVICE_NOT_SUPPORT)
#else
    if (puct == 0 || sim_service_table_query(SERVICE_AOC) == SERVICE_NOT_SUPPORT)
#endif
    {
        mmi_frm_hide_menu_item(MENU_CALL_HISTORY_CALLCOST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_sim_lock_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_sim_lock_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* diamond, 2005/12/09 Hide "SIM Lock" menu if it is not support by SIM */
#ifdef __GEMINI__
    if (sim_service_table_query(SERVICE_CHV_DISABLE_FUNCTION, 0) == SERVICE_NOT_SUPPORT)
#else
    if (sim_service_table_query(SERVICE_CHV_DISABLE_FUNCTION) == SERVICE_NOT_SUPPORT)
#endif
    {
        mmi_frm_hide_menu_item(MENU9169_SIM_LOCK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CSPModifyHiliteHandlers
 * DESCRIPTION
 *  Modifies Hilite Handlers of all applications
 *  in Framework as per CSP Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSPModifyHiliteHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bootupOver = 1;
    if (isCSPPresent)
    {
        //PRINT_INFORMATION("<<CPHS>>CSP Present and Modifying Hilite Handlers");
        CSPCallBarringMainMenu();
        CSPCallBarringIncomingMenu();
        CSPCallBarringOutgoingMenu();
        CSPCallForwardingMenu();
        CSPCallerIdMenu();
        CSPCallMain();
        CSPPhoneSetup();
        CSPCallHistoryMenu();
        CSPNetworkSelectionMenu();
        CSPMesagesMainMenu();
        CSPMessageSettingMenu();
        CSPOutgoingCallManagement();    /* diamond, 2005/07/01 new menu item architecture */
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_main(U8 sim_source)
{
    mmi_cphs_rearrange_call_main_menu(sim_source);
    mmi_cphs_rearrange_call_barring_main_menu(sim_source);
    mmi_cphs_rearrange_call_barring_outgoing_menu(sim_source);
    mmi_cphs_rearrange_call_barring_incoming_menu(sim_source);
    mmi_cphs_rearrange_call_forwarding_menu(sim_source);
    mmi_cphs_rearrange_caller_id_menu(sim_source);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_main_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_main_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_source == SIM1)
    {
        /*
         * mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_BARRING);
         * mmi_frm_unhide_menu_item(MENU_SETTING_CALL_CLOSED_GP);
         * mmi_frm_unhide_menu_item(MENU8237_SCR8093_MNGCALL_MENU_WAIT);
         * #ifdef __CPHS_FEATURE_DEFAULT_OFF__
         * mmi_frm_hide_menu_item(MENU_LINE_SWCH);
         * #else
         * mmi_frm_unhide_menu_item(MENU_LINE_SWCH);
         * #endif
         */
    #ifdef __CPHS_FEATURE_DEFAULT_OFF__
        mmi_frm_hide_menu_item(MENU_LINE_SWCH);
    #endif

        CSPCallMain();
    }
    else if (sim_source == SIM2)
    {
        /*
         * mmi_frm_unhide_menu_item(MENU_MTPNP_CALL_BARRING);
         * mmi_frm_unhide_menu_item(MENU_MTPNP_CALL_WAIT);
         * mmi_frm_unhide_menu_item(MENU_MTPNP_LINE_SWITCH);
         */
    #ifdef __CPHS_FEATURE_DEFAULT_OFF__
        mmi_frm_hide_menu_item(MENU_MTPNP_LINE_SWITCH);
    #endif

        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOAC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC_exHC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BAIC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BIC_Roam))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CALL_BARRING);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_COMPLETION_SERVICE_GROUP, CSP_CW))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CALL_WAIT);
        }

    #ifdef __CPHS_FEATURE_DEFAULT_OFF__
        if (IsResetCSPGroupService_2(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS) == 0)
        {
            mmi_frm_unhide_menu_item(MENU_MTPNP_LINE_SWITCH);
        }
    #else /* __CPHS_FEATURE_DEFAULT_OFF__ */
        if (IsResetCSPGroupService_2(CSP_CPHS_TELESERVICES_SERVICE_GROUP, ALS))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_LINE_SWITCH);
        }
    #endif /* __CPHS_FEATURE_DEFAULT_OFF__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_barring_main_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_barring_main_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_CALL_BARRING_OUTGOING);
    mmi_frm_unhide_menu_item(MENU_CALL_BARRING_INCOMING);

    if (sim_source == SIM1)
    {
        CSPCallBarringMainMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOAC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC_exHC))
        {
            mmi_frm_hide_menu_item(MENU_CALL_BARRING_OUTGOING);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BAIC) &&
            IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BIC_Roam))
        {
            mmi_frm_hide_menu_item(MENU_CALL_BARRING_INCOMING);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_barring_outgoing_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_barring_outgoing_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_BARRING_OUTGOING_ALLCALLS);
    mmi_frm_unhide_menu_item(MENU_BARRING_OUTGOING_INTERCALL);
    mmi_frm_unhide_menu_item(MENU_BARRING_OUTGOING_INTEREXCEPTHOME);

    if (sim_source == SIM1)
    {
        CSPCallBarringOutgoingMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOAC))
        {
            mmi_frm_hide_menu_item(MENU_BARRING_OUTGOING_ALLCALLS);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC))
        {
            mmi_frm_hide_menu_item(MENU_BARRING_OUTGOING_INTERCALL);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BOIC_exHC))
        {
            mmi_frm_hide_menu_item(MENU_BARRING_OUTGOING_INTEREXCEPTHOME);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_barring_incoming_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_barring_incoming_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU_BARRING_INCOMING_ALLCALLS);
    mmi_frm_unhide_menu_item(MENU_BARRING_INCOMING_ROAMING);

    if (sim_source == SIM1)
    {
        CSPCallBarringIncomingMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BAIC))
        {
            mmi_frm_hide_menu_item(MENU_BARRING_INCOMING_ALLCALLS);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_RESTRICTION_SERVICE_GROUP, CSP_BIC_Roam))
        {
            mmi_frm_hide_menu_item(MENU_BARRING_INCOMING_ROAMING);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_forwarding_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_forwarding_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    U8 cfu_cnt = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MENU8238_MNGCALL_CALFWD_VOICECALL);
    mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_UNREACHABLE);
    mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_NOANSWER);
    mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_BUSY);
#ifdef __MMI_SS_CF_ALLCOND_MENU__
    mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_ALLCOND);
#endif
    mmi_frm_unhide_menu_item(MENU8238_MNGCALL_CALFWD_DATACALL);

    if (sim_source == SIM1)
    {
        CSPCallForwardingMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFU))
        {
            mmi_frm_hide_menu_item(MENU8238_MNGCALL_CALFWD_VOICECALL);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFNRc))
        {
            mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_UNREACHABLE);
        }
    #ifdef __MMI_SS_CF_ALLCOND_MENU__
        else
        {
            cfu_cnt++;
        }
    #endif /* __MMI_SS_CF_ALLCOND_MENU__ */

        if (IsResetCSPGroupService_2(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFNRy))
        {
            mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_NOANSWER);
        }
    #ifdef __MMI_SS_CF_ALLCOND_MENU__
        else
        {
            cfu_cnt++;
        }
    #endif /* __MMI_SS_CF_ALLCOND_MENU__ */

        if (IsResetCSPGroupService_2(CSP_CALL_OFFERING_SERVICE_GROUP, CSP_CFB))
        {
            mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_BUSY);
        }
    #ifdef __MMI_SS_CF_ALLCOND_MENU__
        else
        {
            cfu_cnt++;
        }
    #endif /* __MMI_SS_CF_ALLCOND_MENU__ */

    #ifdef __MMI_SS_CF_ALLCOND_MENU__
        if (cfu_cnt == 3)
        {
            /* CPHS: if bit 5, 6, 7 are set as 1 for this group, a conditional forwarding menu is used to replace these 3 menus */
            mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_UNREACHABLE);
            mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_NOANSWER);
            mmi_frm_hide_menu_item(MENU8239_CALFWD_VOICECALL_BUSY);
            mmi_frm_unhide_menu_item(MENU8239_CALFWD_VOICECALL_ALLCOND);
        }
    #endif /* __MMI_SS_CF_ALLCOND_MENU__ */

        if (IsResetCSPGroupService_2(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_Data))
        {
            mmi_frm_hide_menu_item(MENU8238_MNGCALL_CALFWD_DATACALL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_caller_id_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_caller_id_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * mmi_frm_unhide_menu_item(MENU_CID_HIDE_ID);
     * mmi_frm_unhide_menu_item(MENU_CID_SHOW_ID);
     */
    if (sim_source == SIM1)
    {
        CSPCallerIdMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP, CSP_CLI_block))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CALL_ID_HIDE_ID);
        }

        if (IsResetCSPGroupService_2(CSP_NUMBER_IDENTIFICATION_SERVICE_GROUP, CSP_CLI_send))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CALL_ID_SHOW_ID);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_call_history_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_call_history_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * mmi_frm_unhide_menu_item(MENU_CALL_HISTORY_CALLCOST);
     */
    if (sim_source == SIM1)
    {
        CSPCallHistoryMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_OTHER_SS_SERVICE_GROUP, CSP_AoC))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CALL_HISTORY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_network_selection_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_network_selection_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_source == SIM1)
    {
        /*
         * mmi_frm_unhide_menu_item(MENU9186_SELECTION_MODE);
         */
        CSPNetworkSelectionMenu();
    }
    else if (sim_source == SIM2)
    {
        /*
         * mmi_frm_unhide_menu_item(SCR_MTPNP_NETSET_SELECTION_MODE);
         */
        if (IsResetCSPGroupService_2(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_PLMN_MODE))
        {
            mmi_frm_hide_menu_item(SCR_MTPNP_NETSET_SELECTION_MODE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_message_main_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_message_main_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_frm_unhide_menu_item(MENU_ID_UM_INBOX);
    mmi_frm_unhide_menu_item(MENU_ID_UM_WRITE_MSG);
    mmi_frm_unhide_menu_item(MENU_ID_UM_UNSENT);
    mmi_frm_unhide_menu_item(MENU_ID_UM_SENT);
    mmi_frm_unhide_menu_item(MENU_ID_UM_DRAFT);
#else
    mmi_frm_unhide_menu_item(MESSAGES_MENU_INBOX_MENUID);
    mmi_frm_unhide_menu_item(MESSAGES_MENU_WMESSAGE_MENU_ID);
    mmi_frm_unhide_menu_item(MESSAGES_MENU_OUTBOX_MENUID);
#endif

    if (sim_source == SIM1)
    {
        /*
         * mmi_frm_unhide_menu_item(MESSAGES_MENU_CB_MENUID);
         * mmi_frm_unhide_menu_item(MESSAGES_MENU_VMAIL_MENUID);
         */
        CSPMesagesMainMenu();
    }
    else if (sim_source == SIM2)
    {
        /*
         * mmi_frm_unhide_menu_item(MENU_MTPNP_CB_MESSAGES);
         * mmi_frm_unhide_menu_item(MENU_MTPNP_VMAIL);
         */
        if (IsResetCSPGroupService_2(CSP_TELESERVICES_SERVICE_GROUP, CSP_SM_MT))
        {
        #ifdef __MMI_UNIFIED_MESSAGE__
            mmi_frm_hide_menu_item(MENU_ID_UM_INBOX);
        #else
            mmi_frm_hide_menu_item(MESSAGES_MENU_INBOX_MENUID);
        #endif
        }

        if (IsResetCSPGroupService_2(CSP_TELESERVICES_SERVICE_GROUP, CSP_SM_MO))
        {
        #ifdef __MMI_UNIFIED_MESSAGE__
            mmi_frm_hide_menu_item(MENU_ID_UM_WRITE_MSG);
            mmi_frm_hide_menu_item(MENU_ID_UM_UNSENT);
            mmi_frm_hide_menu_item(MENU_ID_UM_SENT);
            mmi_frm_hide_menu_item(MENU_ID_UM_DRAFT);
        #else
            mmi_frm_hide_menu_item(MESSAGES_MENU_WMESSAGE_MENU_ID);
            mmi_frm_hide_menu_item(MESSAGES_MENU_OUTBOX_MENUID);
        #endif
        }

        if (IsResetCSPGroupService_2(CSP_TELESERVICES_SERVICE_GROUP, CSP_SM_CB))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_CB_MESSAGES);
        }

        if (IsResetCSPGroupService_2(CSP_VALUE_ADDED_SERVICES_SERVICE_GROUP, CSP_VPS))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_VMAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_message_setting_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_message_setting_menu(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * mmi_frm_unhide_menu_item(SETUP_MENU_COMMONSETTING_MENUID);
     */
    if (sim_source == SIM1)
    {
        CSPMessageSettingMenu();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_TELESERVICES_SERVICE_GROUP, CSP_Del_Conf) &&
            IsResetCSPGroupService_2(CSP_TELESERVICES_SERVICE_GROUP, CSP_Reply_path))
        {
            mmi_frm_hide_menu_item(MENU_MTPNP_COMMONSETTING);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_outgoing_call_management
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_outgoing_call_management(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_unhide_menu_item(MITEM2015_CM_CALL_CONFER);
    mmi_frm_unhide_menu_item(MITEM2010_CM_ACTIVE_HOLD);

    if (sim_source == SIM1)
    {
        CSPOutgoingCallManagement();
    }
    else if (sim_source == SIM2)
    {
        if (IsResetCSPGroupService_2(CSP_OTHER_SS_SERVICE_GROUP, CSP_MPTY))
        {
            mmi_frm_hide_menu_item(MITEM2015_CM_CALL_CONFER);
        }

        if (IsResetCSPGroupService_2(CSP_CALL_COMPLETION_SERVICE_GROUP, CSP_HOLD))
        {
            mmi_frm_hide_menu_item(MITEM2010_CM_ACTIVE_HOLD);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cphs_rearrange_menu_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_source      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cphs_rearrange_menu_items(U8 sim_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cphs_rearrange_call_main_menu(sim_source);
    mmi_cphs_rearrange_call_barring_main_menu(sim_source);
    mmi_cphs_rearrange_call_barring_outgoing_menu(sim_source);
    mmi_cphs_rearrange_call_barring_incoming_menu(sim_source);
    mmi_cphs_rearrange_call_forwarding_menu(sim_source);
    mmi_cphs_rearrange_caller_id_menu(sim_source);
    mmi_cphs_rearrange_call_history_menu(sim_source);
    mmi_cphs_rearrange_network_selection_menu(sim_source);
    mmi_cphs_rearrange_message_main_menu(sim_source);
    mmi_cphs_rearrange_message_setting_menu(sim_source);
    mmi_cphs_rearrange_outgoing_call_management(sim_source);
}

#endif /* __MMI_DUAL_SIM_MASTER__ */

