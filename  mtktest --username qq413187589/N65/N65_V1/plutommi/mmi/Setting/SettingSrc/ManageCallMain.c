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
 * ManageCallMain.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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

   FILENAME : ManageCall.c

   PURPOSE     : CallSetup Main Menu 

   REMARKS     : nil

   AUTHOR      : Vanita Jain

   DATE     : 

**************************************************************/
#include "MMI_include.h"
#include "CSP.h"

#include "MainMenuDef.h"
#include "PhoneBookTypes.h"
/* Start by Julia */
#include "PhoneBookGprot.h"
/* End by Julia */
#include "CallmanagementIdDef.h"
#include "CallManagementStruct.h"
/* MTK Leo add 20040321, for new simulator, used by CallSetup.h */
#include "l4c_common_enum.h"
/* MTK Leo end */
#include "CallSetup.h"
#include "ManageCallMain.h"
#include "SettingProt.h"
#include "SettingDefs.h"
#include "CallSetUpEnum.h"
#include "CommonScreens.h"
#include "SettingGprots.h"
#include "MessagesExDcl.h"
/* micha0901 */
#include "ProfileGprots.h"

#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "CallStructureManagementProt.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif/* __MMI_DUAL_SIM_MASTER__*/

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */

CallSetupContext g_callset_context;

extern MMI_OWNER_NUMBER_STRUCT gDispOwnerNumber[];

#ifdef __IP_NUMBER__
static U8 IPSetting = 0xff;
static U8 IPNumber[MAX_IP_NUMBER][(MAX_IP_NUMBER_LEN + 1) * ENCODING_LENGTH];
static U8 newIPNum[(MAX_IP_NUMBER_LEN + 1) * ENCODING_LENGTH];
static S32 curIPNumIndex = 0;

#ifdef __MMI_DUAL_SIM_MASTER__
static U8 mtpnpIPSetting = 0xff;
#endif/* __MMI_DUAL_SIM_MASTER__*/
#endif /* __IP_NUMBER__ */ 
/* Start by Julia */
#ifdef __MMI_CM_BLACK_LIST__
static pBOOL gBlackListFlag = FALSE;
static U8 BlackListNum[MAX_BLACK_LIST_NUMBER][(MAX_BLACK_LIST_NUMBER_LEN + 1) * ENCODING_LENGTH];       /* black list number stored in NVRAM */
static U8 dispBlackListNum[MAX_BLACK_LIST_NUMBER][(MAX_BLACK_LIST_NUMBER_LEN + 1) * ENCODING_LENGTH];   /* temp black list number for displaying reason */
static S32 curBlackListNumIndex = 0;
#endif /* __MMI_CM_BLACK_LIST__ */ 
/* End by Julia */
#ifdef __MMI_SS_SHOW_CAUSE__
const SSCauseDisplayStruct CauseDisplay[] = 
{
    {CM_UNASSIGNED_NUM, "cm unassigned num"},
    {CM_NO_ROUTE_TO_DESTINATION, "cm no route to destination"},
    {CM_CHANNEL_UN_ACCP, "cm channel un accp"},
    {CM_OPR_DTR_BARRING, "cm opr dtr barring"},
    {CM_CALL_BARRED, "cm call barred"},
    {CM_RESERVED, "cm reserved"},
    {CM_NORMAL_CALL_CLR, "cm normal call clr"},
    {CM_USER_BUSY, "cm user busy"},
    {CM_NO_USER_RESPONDING, "cm no user responding"},
    {CM_NO_ANSWER_ON_ALERT, "cm no answer on alert"},
    {CM_CALL_REJECTED, "cm call rejected"},
    {CM_NUMBER_CHANGED, "cm number changed"},
    {CM_PRE_EMPTION, "cm pre emption"},
    {CM_NON_SEL_USER_CLEAR, "cm non sel user clear"},
    {CM_DEST_OUT_OF_ORDER, "cm dest out of order"},
    {CM_INVALID_NUMBER_FORMAT, "cm invalid number format"},
    {CM_FACILITY_REJECT, "cm facility reject"},
    {CM_RES_STATUS_ENQ, "cm res status enq"},
    {CM_NORMAL_UNSPECIFIED, "cm normal unspecified"},
    {CM_NO_CIRCUIT_CHANNEL_AVAIL, "cm no circuit channel avail"},
    {CM_NETWORK_OUT_OF_ORDER, "cm network out of order"},
    {CM_TEMPORARY_FAILURE, "cm temporary failure"},
    {CM_SWITCH_EQUIPMENT_CONGESTION, "cm switch equipment congestion"},
    {CM_ACCESS_INFO_DISCARDED, "cm access info discarded"},
    {CM_REQUESTED_CKT_CHANEL_NOT_AVIL, "cm requested ckt chanel not avil"},
    {CM_RESOURCE_UNAVAIL_UNSPECIFIED, "cm resource unavail unspecified"},
    {CM_QOS_UNAVAIL, "cm qos unavail"},
    {CM_REQ_FAC_NOT_SUBS, "cm req fac not subs"},
    {CM_IC_BAR_CUG, "cm ic bar cug"},
    {CM_BEARER_CAP_NOT_AUTHORISED, "cm bearer cap not authorised"},
    {CM_BEARER_CAP_NOT_AVAIL, "cm bearer cap not avail"},
    {CM_SER_UNAVAILABLE, "cm ser unavailable"},
    {CM_BEARER_SER_UNIMPL, "cm bearer ser unimpl"},
    {CM_ACM_EXCEEDED, "cm acm exceeded"},
    {CM_REQ_FACILITY_UNAVAIL, "cm req facility unavail"},
    {CM_RESTR_DIGITAL_INFO, "cm restr digital info"},
    {CM_SER_OPT_UNIMPL, "cm ser opt unimpl"},
    {CM_INVALID_TI_VALUE, "cm invalid ti value"},
    {CM_USER_NOT_IN_CUG, "cm user not in cug"},
    {CM_INCOMPATIBLE_DEST, "cm incompatible dest"},
    {CM_INVALID_TRANSIT_NW_SEL, "cm invalid transit nw sel"},
    {CM_SEMANTIC_ERR, "cm semantic err"},
    {CM_INVALID_MANDATORY_INF, "cm invalid mandatory inf"},
    {CM_MSG_TYPE_UNIMPL, "cm msg type unimpl"},
    {CM_MSG_TYPE_NOT_COMPATIBLE, "cm msg type not compatible"},
    {CM_IE_NON_EX, "cm ie non ex"},
    {CM_COND_IE_ERR, "cm cond ie err"},
    {CM_INCOMP_MESG_WITH_STATE, "cm incomp mesg with state"},
    {CM_RECOVERY_ON_TIMER_EXPIRY, "cm recovery on timer expiry"},
    {CM_PROTOCOL_ERR_UNSPECIFIED, "cm protocol err unspecified"},
    {CM_INTER_WRK_UNSPECIFIED, "cm inter wrk unspecified"},
    {TELEMATIC_INT_WRK_NOT_SUPPORT, "telematic int wrk not support"},
    {SMS_TYPE0_NOT_SUPPORT, "sms type0 not support"},
    {CANNOT_REPLACE_MSG, "cannot replace msg"},
    {UNSPECIFIED_PID_ERROR, "unspecified pid error"},
    {ALPHABET_NOT_SUPPORT, "alphabet not support"},
    {MSG_CLASS_NOT_SUPPORT, "msg class not support"},
    {UNSPECIFIED_TP_DCS, "unspecified tp dcs"},
    {CMD_CANNOT_ACTION, "cmd cannot action"},
    {CMD_NOT_SUPPORT, "cmd not support"},
    {UNSPECIFIED_CMD_ERROR, "unspecified cmd error"},
    {TPDU_NOT_SUPPORT, "tpdu not support"},
    {SC_BUSY, "sc busy"},
    {NO_SC_SUBSCRIPTION, "no sc subscription"},
    {SC_SYS_FAILURE, "sc sys failure"},
    {INVALID_SME_ADDR, "invalid sme addr"},
    {DEST_SME_BARRED, "dest sme barred"},
    {SM_REJ_DUP_SM, "sm rej dup sm"},
    {TP_VPF_NOT_SUPPORT, "tp vpf not support"},
    {TP_VP_NOT_SUPPORT, "tp vp not support"},
    {SIM_STORAGE_FULL, "sim storage full"},
    {NO_SMS_STO_IN_SIM, "no sms sto in sim"},
    {ERROR_IN_MS, "error in ms"},
    {MEM_CAP_EXCEEDED, "mem cap exceeded"},
    {SMS_SAT_BUSY, "sms sat busy"},
    {SMS_SAT_DL_ERROR, "sms sat dl error"},
    {SMS_CP_RETRY_EXCEED, "sms cp retry exceed"},
    {SMS_RP_TR1M_TIMEOUT, "sms rp tr1m timeout"},
    {SMS_CONNECTION_BROKEN, "sms connection broken"},
    {UNSPECIFIED_TP_FCS, "unspecified tp fcs"},
    {INVALID_PDU_MODE_PARA, "invalid pdu mode para"},
    {INVALID_TEXT_MODE_PARA, "invalid text mode para"},
    {SMS_SIM_FAILURE, "sms sim failure"},
    {MEM_FAILURE, "mem failure"},
    {INVALID_MEM_INDEX, "invalid mem index"},
    {MEM_FULL, "mem full"},
    {SCA_UNKNOWN, "sca unknown"},
    {NO_CNMA_EXPECTED, "no cnma expected"},
    {SMSAL_UNSPECIFIED_ERROR_CAUSE, "smsal unspecified error cause"},
    {SMSAL_NO_ERROR, "smsal no error"},
    {MSG_LEN_EXCEEDED, "msg len exceeded"},
    {INVALID_REQ_PARAMETER, "invalid req parameter"},
    {SMS_ME_STORAGE_FAILURE, "sms me storage failure"},
    {SMSAL_INVALID_BEARER, "smsal invalid bearer"},
    {SMSAL_INVALID_SERVICE_MODE, "smsal invalid service mode"},
    {SMSAL_INVALID_STORAGE_TYPE, "smsal invalid storage type"},
    {SMSAL_INVALID_MSG_FORMAT, "smsal invalid msg format"},
    {TOO_MANY_MO_CONCAT_MSG, "too many mo concat msg"},
    {SMSAL_NOT_READY, "smsal not ready"},
    {SMSAL_NO_MO_SERVICE, "smsal no mo service"},
    {NOT_SUPP_SR_CMD_IN_STORAGE, "not supp sr cmd in storage"},
    {SMSAL_NOT_SUPPORT_MSG_TYPE, "smsal not support msg type"},
    {CSMCC_CMD_NOT_ALLOW, "csmcc cmd not allow"},
    {CSMCC_ILLEGAL_CALL_ID, "csmcc illegal call id"},
    {CSMCC_CALL_ALLOC_FAIL, "csmcc call alloc fail"},
    {CSMCC_BC_FILL_FAIL, "csmcc bc fill fail"},
    {CSMCC_CALL_RE_EST, "csmcc call re est"},
    {CSMCC_ILLEGAL_DTMF_TONE, "csmcc illegal dtmf tone"},
    {CSMCC_ILLEGAL_BC, "csmcc illegal bc"},
    {CSMCC_MODIFY_ACTUAL_MODE, "csmcc modify actual mode"},
    {CSMCC_DATA_ACT_FAIL, "csmcc data act fail"},
    {CSMCC_NO_RESPONSE_FROM_NW, "csmcc no response from nw"},
    {CSMCC_CALL_ACCEPT_NOT_ALLOW, "csmcc call accept not allow"},
    {CM_SS_ERR_UNKNOWNSUBSCRIBER, "cm ss err unknownsubscriber"},
    {CM_SS_ERR_ILLEGALSUBSCRIBER, "cm ss err illegalsubscriber"},
    {CM_SS_ERR_BEARERSERVICENOTPROVISIONED, "cm ss err bearerservicenotprovisioned"},
    {CM_SS_ERR_TELESERVICENOTPROVISIONED, "cm ss err teleservicenotprovisioned"},
    {CM_SS_ERR_ILLEGALEQUIPMENT, "cm ss err illegalequipment"},
    {CM_SS_ERR_CALLBARRED, "cm ss err callbarred"},
    {CM_SS_ERR_ILLEGALSS_OPERATION, "cm ss err illegalss operation"},
    {CM_SS_ERR_SS_ERRORSTATUS, "cm ss err ss errorstatus"},
    {CM_SS_ERR_SS_NOTAVAILABLE, "cm ss err ss notavailable"},
    {CM_SS_ERR_SS_SUBSCRIPTIONVIOLATION, "cm ss err ss subscriptionviolation"},
    {CM_SS_ERR_SS_INCOMPABILITY, "cm ss err ss incompability"},
    {CM_SS_ERR_FACILITYNOTSUPPORTED, "cm ss err facilitynotsupported"},
    {CM_SS_ERR_ABSENTSUBSCRIBER, "cm ss err absentsubscriber"},
    {CM_SS_ERR_SHORTTERMDENIAL, "cm ss err shorttermdenial"},
    {CM_SS_ERR_LONGTERMDENIAL, "cm ss err longtermdenial"},
    {CM_SS_ERR_SYSTEMFAILURE, "cm ss err systemfailure"},
    {CM_SS_ERR_DATAMISSING, "cm ss err datamissing"},
    {CM_SS_ERR_UNEXPECTEDDATAVALUE, "cm ss err unexpecteddatavalue"},
    {CM_SS_ERR_PW_REGISTRATIONFAILURE, "cm ss err pw registrationfailure"},
    {CM_SS_ERR_NEGATIVEPW_CHECK, "cm ss err negativepw check"},
    {CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION, "cm ss err numberofpw attemptsviolation"},
    {CM_SS_ERR_POSITIONMETHODFAILURE, "cm ss err positionmethodfailure"},
    {CM_SS_ERR_UNKNOWNALPHABET, "cm ss err unknownalphabet"},
    {CM_SS_ERR_USSD_BUSY, "cm ss err ussd busy"},
    {CM_SS_ERR_REJECTEDBYUSER, "cm ss err rejectedbyuser"},
    {CM_SS_ERR_REJECTEDBYNETWORK, "cm ss err rejectedbynetwork"},
    {CM_SS_ERR_DEFLECTIONTOSERVEDSUBSCRIBER, "cm ss err deflectiontoservedsubscriber"},
    {CM_SS_ERR_SPECIALSERVICECODE, "cm ss err specialservicecode"},
    {CM_SS_ERR_INVALIDDEFLECTIONTONUMBER, "cm ss err invaliddeflectiontonumber"},
    {CM_SS_ERR_MAXNUMBEROFMPTY_PARTICIPANTSEXCEEDED, "cm ss err maxnumberofmpty participantsexceeded"},
    {CM_SS_ERR_RESOURCESNOTAVAILABLE, "cm ss err resourcesnotavailable"},
    {CM_SS_GENERALPROBLEM_UNRECOGNIZEDCOMPONENT, "cm ss generalproblem unrecognizedcomponent"},
    {CM_SS_GENERALPROBLEM_MISTYPEDCOMPONENT, "cm ss generalproblem mistypedcomponent"},
    {CM_SS_GENERALPROBLEM_BADLYSTRUCTUREDCOMPONENT, "cm ss generalproblem badlystructuredcomponent"},
    {CM_SS_INVOKEPROBLEM_DUPLICATEINVOKEID, "cm ss invokeproblem duplicateinvokeid"},
    {CM_SS_INVOKEPROBLEM_UNRECOGNIZEDOPERATION, "cm ss invokeproblem unrecognizedoperation"},
    {CM_SS_INVOKEPROBLEM_MISTYPEDPARAMETER, "cm ss invokeproblem mistypedparameter"},
    {CM_SS_INVOKEPROBLEM_RESOURCELIMITATION, "cm ss invokeproblem resourcelimitation"},
    {CM_SS_INVOKEPROBLEM_INITIATINGRELEASE, "cm ss invokeproblem initiatingrelease"},
    {CM_SS_INVOKEPROBLEM_UNRECOGNIZEDLINKDID, "cm ss invokeproblem unrecognizedlinkdid"},
    {CM_SS_INVOKEPROBLEM_LINKEDRESONSEUNEXPECTED, "cm ss invokeproblem linkedresonseunexpected"},
    {CM_SS_INVOKEPROBLEM_UNEXPECTEDLINKEDOPERATION, "cm ss invokeproblem unexpectedlinkedoperation"},
    {CM_SS_RETURNRESULTPROBLEM_RR_UNRECOGNIZEDINVOKEID, "cm ss returnresultproblem rr unrecognizedinvokeid"},
    {CM_SS_RETURNRESULTPROBLEM_RR_RETURNRESULTUNEXPECTED, "cm ss returnresultproblem rr returnresultunexpected"},
    {CM_SS_RETURNRESULTPROBLEM_RR_MISTYPEDPARAMETER, "cm ss returnresultproblem rr mistypedparameter"},
    {CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDINVOKEID, "cm ss returnerrorproblem re unrecognizedinvokeid"},
    {CM_SS_RETURNERRORPROBLEM_RE_RETURNERRORUNEXPECTED, "cm ss returnerrorproblem re returnerrorunexpected"},
    {CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDERROR, "cm ss returnerrorproblem re unrecognizederror"},
    {CM_SS_RETURNERRORPROBLEM_RE_UNEXPECTEDERROR, "cm ss returnerrorproblem re unexpectederror"},
    {CM_SS_RETURNERRORPROBLEM_RE_MISTYPEDPARAMETER, "cm ss returnerrorproblem re mistypedparameter"},
    {CM_MM_CAUSE_NONE, "cm mm cause none"},
    {CM_MM_IMSI_UNKNOWN_IN_HLR, "cm mm imsi unknown in hlr"},
    {CM_MM_ILLEGAL_MS, "cm mm illegal ms"},
    {CM_MM_IMSI_UNKNOWN_IN_VLR, "cm mm imsi unknown in vlr"},
    {CM_MM_IMEI_NOT_ACCEPTED, "cm mm imei not accepted"},
    {CM_MM_ILLEGAL_ME, "cm mm illegal me"},
    {CM_MM_GPRS_NOT_ALLOWED, "cm mm gprs not allowed"},
    {CM_MM_GPRS_NON_GPRS_NOT_ALLOWED, "cm mm gprs non gprs not allowed"},
    {CM_MM_MS_ID_NOT_DERIVED_BY_NW, "cm mm ms id not derived by nw"},
    {CM_MM_IMPLICIT_DETACH, "cm mm implicit detach"},
    {CM_MM_PLMN_NOT_ALLOWED, "cm mm plmn not allowed"},
    {CM_MM_LOCATION_AREA_NOT_ALLOWED, "cm mm location area not allowed"},
    {CM_MM_ROAMING_AREA_NOT_ALLOWED, "cm mm roaming area not allowed"},
    {CM_MM_GPRS_NOT_ALLOWED_IN_PLMN, "cm mm gprs not allowed in plmn"},
    {CM_MM_NO_SUITABLE_CELLS_IN_LA, "cm mm no suitable cells in la"},
    {CM_MM_MSC_TEMP_NOT_REACHABLE, "cm mm msc temp not reachable"},
    {CM_MM_NETWORK_FAILURE, "cm mm network failure"},
    {CM_MM_MAC_FAILURE, "cm mm mac failure"},
    {CM_MM_SYNC_FAILURE, "cm mm sync failure"},
    {CM_MM_CONGESTION, "cm mm congestion"},
    {CM_MM_SERV_OPTION_NOT_SUPPORTED, "cm mm serv option not supported"},
    {CM_MM_REQ_SERV_OPTION_NOT_SUBSCRIBED, "cm mm req serv option not subscribed"},
    {CM_MM_SERV_OPTION_TEMP_OUT_OF_ORDER, "cm mm serv option temp out of order"},
    {CM_MM_CALL_CANNOT_BE_IDENTIFIED, "cm mm call cannot be identified"},
    {CM_MM_NO_PDP_CONTEXT_ACTIVATED, "cm mm no pdp context activated"},
    {CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN, "cm mm retry upon entry into newcell min"},
    {CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX, "cm mm retry upon entry into newcell max"},
    {CM_MM_SEMANTICALLY_INCORRECT_MSG, "cm mm semantically incorrect msg"},
    {CM_MM_INVALID_MM_MAND_INFO, "cm mm invalid mm mand info"},
    {CM_MM_MSG_TYPE_NON_EXISTENT, "cm mm msg type non existent"},
    {CM_MM_MSG_TYPE_NOT_IMPLEMENTED, "cm mm msg type not implemented"},
    {CM_MM_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE, "cm mm msg type incompat with proto state"},
    {CM_MM_IE_NOT_IMPLEMENTED, "cm mm ie not implemented"},
    {CM_MM_CONDITIONAL_MM_IE_ERROR, "cm mm conditional mm ie error"},
    {CM_MM_MSG_NOT_COMPAT_WITH_PROTO_STATE, "cm mm msg not compat with proto state"},
    {CM_MM_PROTO_ERROR_UNSPECIFIED, "cm mm proto error unspecified"},
    {CM_MM_ACCESS_BARRED, "cm mm access barred"},
    {CM_MM_ASSIGNMENT_REJECT, "cm mm assignment reject"},
    {CM_MM_RANDOM_ACCES_FAILURE, "cm mm random acces failure"},
    {CM_MM_RR_NO_SERVICE, "cm mm rr no service"},
    {CM_MM_RR_CONN_RELEASE, "cm mm rr conn release"},
    {CM_MM_AUTH_FAILURE, "cm mm auth failure"},
    {CM_MM_IMSI_DETACH, "cm mm imsi detach"},
    {CM_MM_ABORT_BY_NW, "cm mm abort by nw"},
    {CM_MM_CONN_TIMEOUT, "cm mm conn timeout"},
    {CM_MM_CM_ENQUEUE_FAIL, "cm mm cm enqueue fail"},
    {CM_MM_NOT_UPDATED, "cm mm not updated"},
    {CM_MM_STATE_NOT_ALLOWED_CM, "cm mm state not allowed cm"},
    {CM_MM_EMERGENCY_NOT_ALLOWED, "cm mm emergency not allowed"},
    {CM_MM_NO_SERVICE, "cm mm no service"},
    {CM_MM_ACCESS_CLASS_BARRED, "cm mm access class barred"},
    {SIM_CAUSE_CMD_SUCCESS, "sim cause cmd success"},
    {SIM_CAUSE_CMD_FAIL, "sim cause cmd fail"},
    {SIM_CAUSE_FATAL_ERROR, "sim cause fatal error"},
    {SIM_CAUSE_NO_INSERTED, "sim cause no inserted"},
    {SIM_CAUSE_CHV_NOT_INIT, "sim cause chv not init"},
    {SIM_CAUSE_CHV_VERIFY_ERROR, "sim cause chv verify error"},
    {SIM_CAUSE_CHV_BLOCK, "sim cause chv block"},
    {SIM_CAUSE_ACCESS_NOT_ALLOW, "sim cause access not allow"},
    {SIM_CAUSE_SAT_CMD_BUSY, "sim cause sat cmd busy"},
    {SIM_CAUSE_DL_ERROR, "sim cause dl error"},
    {SIM_CAUSE_MEMORY_PROBLEM, "sim cause memory problem"},
    {SIM_CAUSE_TECHNICAL_PROBLEM, "sim cause technical problem"},
    {SIM_CAUSE_PUK_UNLOCK, "sim cause puk unlock"},
    {(U16) NULL, ""}
};

#endif /* __MMI_SS_SHOW_CAUSE__ */ 


/*****************************************************************************
 * FUNCTION
 *  InitManageCalls
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitManageCalls()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitCallerId();
    InitCallWaiting();
    InitCallForwarding();
    InitCallBarring();
    InitLineSwitch();
    InitGroupListApp();

    SetHiliteHandler(MENU8237_SCR8093_MNGCALL_MENU_MAIN, HighlightManageCalls);
    SetHiliteHandler(MENU_SETTING_CALL_REMINDER, HighlightCALLSETCallTimeReminder);
    SetHiliteHandler(MENU_SETTING_CALL_TIME_DISPLAY, HighlightCALLSETCallTimeDisplay);
    SetHiliteHandler(MENU9140_AUTO_REDIAL, HighlightCALLSETAutoRedial);
    /* micha0908 */
#ifndef __MMI_REMOVE_CUG__
    SetHiliteHandler(MENU_SETTING_CALL_CLOSED_GP, HighlightCALLSETClosedUserGroup);
#endif 

    SetHintHandler(MENU_CALLER_ID, HintCALLSETCallerID);
    SetHintHandler(MENU_LINE_SWCH, HintCALLSETLineSwitch);
    SetHintHandler(MENU_SETTING_CALL_REMINDER, HintCALLSETCallTimeReminder);
    SetHintHandler(MENU_SETTING_CALL_TIME_DISPLAY, HintCALLSETCallTimeDisplay);
    SetHintHandler(MENU9140_AUTO_REDIAL, HintCALLSETAutoRedial);
    g_callset_context.SSCFNumFromPHB = FALSE;

#ifdef __IP_NUMBER__
    SetHiliteHandler(MENU_SETTING_IP_NUMBER, HighlightIPNumber);
    InitIPNumber();
#endif /* __IP_NUMBER__ */ 
    /* Start by Julia */
#ifdef __MMI_CM_BLACK_LIST__
    SetHiliteHandler(MENU_SETTING_BLACK_LIST, HighlightBlackList);
    SetHintHandler(MENU_SETTING_BLACK_LIST, HintBlackList);
    InitBlackList();
#endif /* __MMI_CM_BLACK_LIST__ */ 
    /* End by Julia */
}


/*****************************************************************************
 * FUNCTION
 *  HintCALLSETCallerID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCALLSETCallerID(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    switch (g_callset_context.CallerID)
    {
        case 0:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_CLI_HIDE_ID));
            break;
        case 1:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_CLI_SEND_ID));
            break;
        case 2:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_CLI_SET_NETWORK));
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  HintCALLSETLineSwitch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCALLSETLineSwitch(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
    S8 tempstr[10];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (g_callset_context.LineID == LINE1)
    {
        mmi_ucs2cpy((S8*) g_callset_context.LineInfo, (S8*) GetString(STR_LSW_LINE1));
    #ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
        if (mmi_ucs2strlen((S8*) gDispOwnerNumber[0].name) > 0)
        {
            mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[0].name);
        }
        else if (mmi_ucs2strlen((S8*) gDispOwnerNumber[0].number) > 0)
        {
            mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[0].number);
        }
    #endif /* __MMI_LINE_SWITCH_SHOW_NUMBER__ */ 
    }
    else
    {
        mmi_ucs2cpy((S8*) g_callset_context.LineInfo, (S8*) GetString(STR_LSW_LINE2));
    #ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
        if (mmi_ucs2strlen((S8*) gDispOwnerNumber[1].name) > 0)
        {
            mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[1].name);
        }
        else if (mmi_ucs2strlen((S8*) gDispOwnerNumber[1].number) > 0)
        {
            mmi_asc_to_ucs2((S8*) tempstr, (S8*) ",");
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) tempstr);
            mmi_ucs2cat((S8*) g_callset_context.LineInfo, (S8*) gDispOwnerNumber[1].number);
        }
    #endif /* __MMI_LINE_SWITCH_SHOW_NUMBER__ */ 
    }
    mmi_ucs2cpy((S8*) hintData[index], (PS8) g_callset_context.LineInfo);

}


/*****************************************************************************
 * FUNCTION
 *  HintCALLSETCallTimeReminder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCALLSETCallTimeReminder(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    switch (CallTimeReminderStatus())
    {
        case 0:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
            break;
        case 1:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_SETTING_CR_SING));
            break;
        case 2:
            mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_SETTING_CR_PERIOD));
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  HintCALLSETCallTimeDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCALLSETCallTimeDisplay(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (GetCallTimeDisplay())
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }

}


/*****************************************************************************
 * FUNCTION
 *  HintCALLSETAutoRedial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCALLSETAutoRedial(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[(index)], 0, MAX_SUB_MENU_SIZE);
    if (AutoRedialOnOffStatus())
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }

}


/*****************************************************************************
 * FUNCTION
 *  HighlightManageCalls
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightManageCalls()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetKeyHandler(EntryCALLSETMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(EntryCALLSETMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETMain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETMain()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */

    /* U32 maskingByte=0xFFFFFFFF;
       U32 menuItemId=0xFFFFFFFF; */
    U8 *CallSetupType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_MAIN, NULL, EntryCALLSETMain, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_MAIN);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU8237_SCR8093_MNGCALL_MENU_MAIN);

    /* 4. Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU8237_SCR8093_MNGCALL_MENU_MAIN); */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceStringIds_Ext(MENU8237_SCR8093_MNGCALL_MENU_MAIN, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU8237_SCR8093_MNGCALL_MENU_MAIN);

    ConstructHintsList(MENU8237_SCR8093_MNGCALL_MENU_MAIN, CallSetupType);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category1 Screen */

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    ShowCategory52Screen(
        STR_SCR8093_MNGCALL_MENU_CAPTION,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        CallSetupType,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  AppendBScodeString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bscode_input        [IN]        
 *  temp_string         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void AppendBScodeString(U8 bscode_input, PS8 temp_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((U8) bscode_input)
    {
        case L4_ALL_TELESERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_TELESERVICES));
            break;
        case L4_TELEPHONY:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_TELEPHONY));
            break;
        case L4_ALL_DATA_TELESERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_DATA_TELESERVICES));
            break;
        case L4_FACSIMILE_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_FACSIMILE_SERVICES));
            break;
        case L4_SHORT_MESSAGE_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_SHORT_MESSAGE_SERVICES));
            break;
        case L4_ALL_TELESERVICES_EXCEPT_SMS:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_TELESERVICES_EXCEPT_SMS));
            break;
        case L4_VOICE_GROUP_CALL_SERVICE:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_VOICE_GROUP_CALL_SERVICE));
            break;
        case L4_VOICE_BROADCAST_SERVICE:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_VOICE_BROADCAST_SERVICE));
            break;
        case L4_ALL_BEARER_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_BEARER_SERVICES));
            break;
        case L4_ALL_ASYNC_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_ASYNC_SERVICES));
            break;
        case L4_ALL_SYNC_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_SYNC_SERVICES));
            break;
        case L4_ALL_DATA_CIRCUIT_SYNC:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_DATA_CIRCUIT_SYNC));
            break;
        case L4_ALL_DATA_CIRCUIT_ASYNC:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_DATA_CIRCUIT_ASYNC));
            break;
        case L4_ALL_GPRS_BEARER_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_ALL_GPRS_BEARER_SERVICES));
            break;
        case L4_BS_ALLPADACCESSCA_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_BS_ALLPADACCESSCA_SERVICES));
            break;
        case L4_BS_ALLDATAPDS_SERVICES:
            mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_L4_BS_ALLDATAPDS_SERVICES));
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETAutoRedial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETAutoRedial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.AutoRedialInput = (U8) GetCurrHiliteID();
    if (g_callset_context.AutoRedialStatus == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 1 Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryScrAutoRedial, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrAutoRedial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrAutoRedial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Store the updated Value */

    if (g_callset_context.AutoRedialStatus == 0)
    {
        data = 1;
    }

    WriteValue(NVRAM_SETTING_AUTOREDIAL, &data, DS_BYTE, &error);
    if (data)
    {
        mmi_ucs2cpy((S8*) hintData[g_callset_context.AutoRedialInput], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(g_callset_context.AutoRedialInput, (U8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        g_callset_context.AutoRedialStatus = 1;
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[g_callset_context.AutoRedialInput], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(g_callset_context.AutoRedialInput, (U8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        g_callset_context.AutoRedialStatus = 0;
    }
    RedrawCategoryFunction();
    HighlightCALLSETAutoRedial();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallTimeDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallTimeDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.CTDInput = (U8) GetCurrHiliteID();
    if (g_callset_context.CTDStatus == 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryCallTimeDisplay, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCallTimeDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCallTimeDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_callset_context.CTDStatus == 0)
    {
        data = 1;
    }
    WriteValue(NVRAM_SETTING_CALL_TIME_DISPLAY, &data, DS_BYTE, &error);
    if (data)
    {
        mmi_ucs2cpy((S8*) hintData[g_callset_context.CTDInput], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(g_callset_context.CTDInput, (U8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        g_callset_context.CTDStatus = 1;
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[g_callset_context.CTDInput], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(g_callset_context.CTDInput, (U8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        g_callset_context.CTDStatus = 0;
    }
    RedrawCategoryFunction();
    HighlightCALLSETCallTimeDisplay();
}

/* micha0908 */
#ifndef __MMI_REMOVE_CUG__


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETClosedUserGroup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETClosedUserGroup()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetKeyHandler(EntryCALLSETCUGMain, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntryCALLSETCUGMain, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* __MMI_REMOVE_CUG__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightCALLSETCallTimeReminder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCALLSETCallTimeReminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(EntryCALLSETCallTimeReminder, KEY_EVENT_UP);

    /* micha0424 */
    SetKeyHandler(EntryCALLSETCallTimeReminder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETCallTimeReminder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETCallTimeReminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[3];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */

    //micha1229
    //      U16 nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;              /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_CTR, NULL, EntryCALLSETCallTimeReminder, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_CTR);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_SETTING_CALL_REMINDER);

    /* 4. Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem(MENU_SETTING_CALL_REMINDER); */

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_SETTING_CALL_REMINDER, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_SETTING_CALL_REMINDER);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(CtrHandler);

    /* 8 Display Category1 Screen */

    ShowCategory11Screen(
        STR_SETTING_CALL_REMINDER,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        (U16) g_callset_context.CTRStatusInput,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(SendCtr, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  CtrHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *  
 *  Author            : Vanita Jain(?)
 *****************************************************************************/
void CtrHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_callset_context.CTRStatusInput = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  SendCtr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendCtr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = g_callset_context.CTRStatusInput;
    if (data == 0)
    {
        WriteValue(NVRAM_SETTING_CTR, &data, DS_BYTE, &error);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        /* micha0706 */
        DeleteScreenIfPresent(SCR_ID_CALLSET_CTR);
    }
    else
    {
        EntryCALLSETCtrTime();
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETCtrTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETCtrTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_CTR_TIME, ExitCALLSETCtrTime, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CALLSET_CTR_TIME);
    inputBuffer = GetCurrInputBuffer(SCR_ID_CALLSET_CTR_TIME);

    if (inputBuffer == NULL)
    {
        if (g_callset_context.CTRStatusInput != 0 && gui_atoi((UI_string_type) g_callset_context.CTRNumber) != 0
            && g_callset_context.CTRStatus == g_callset_context.CTRStatusInput)
        {
        #ifdef __COUNTDOWN_PERIODIC_CTR_MODE__
            if (g_callset_context.CTRStatusInput != 1)
            {
                S8 temp_buf[6];
                S32 ctr_time = 0;

                ctr_time = gui_atoi((UI_string_type) g_callset_context.CTRNumber);
                if ((ctr_time <= 60) && (ctr_time >= 0))
                {
                    ctr_time = 60 - ctr_time;
                    sprintf(temp_buf, "%d", ctr_time);
                    memset(g_callset_context.CTRNumberInput, 0, MAX_CTR_NUM_DIGITS * ENCODING_LENGTH);
                    mmi_asc_to_ucs2((PS8) g_callset_context.CTRNumberInput, temp_buf);
                }
                else
                {
                    memset(g_callset_context.CTRNumberInput, 0, 6 * ENCODING_LENGTH);
                }
            }
            else
            {
                mmi_ucs2cpy((S8*) g_callset_context.CTRNumberInput, (S8*) g_callset_context.CTRNumber);
            }
        #else /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 
            mmi_ucs2cpy((S8*) g_callset_context.CTRNumberInput, (S8*) g_callset_context.CTRNumber);
        #endif /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 
        }
        else
        {
            memset(g_callset_context.CTRNumberInput, 0, MAX_CTR_NUM_DIGITS * ENCODING_LENGTH);
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) g_callset_context.CTRNumberInput, (S8*) inputBuffer);
    }

    if (g_callset_context.CTRStatusInput == 1)
    {
        ShowCategory69Screen(
            STR_CTR_REM,
        #ifdef __MMI_UCM__
            GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
            MAIN_MENU_TITLE_SETTINGS_ICON,
        #endif /* __MMI_UCM__ */
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_SETTING_CR_RANGE2,
            INPUT_TYPE_NUMERIC,
            g_callset_context.CTRNumberInput,
            5,
            guiBuffer);
    }
    else
    {
    #ifdef __COUNTDOWN_PERIODIC_CTR_MODE__
        ShowCategory69Screen(
            STR_CTR_REM,
        #ifdef __MMI_UCM__
            GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
            MAIN_MENU_TITLE_SETTINGS_ICON,
        #endif /* __MMI_UCM__ */

            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_SETTING_CR_RANGE3,
            INPUT_TYPE_NUMERIC,
            g_callset_context.CTRNumberInput,
            3,
            guiBuffer);
    #else /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 
        ShowCategory69Screen(
            STR_CTR_REM,
        #ifdef __MMI_UCM__
            GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
        #else
            MAIN_MENU_TITLE_SETTINGS_ICON,
        #endif /* __MMI_UCM__ */
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            STR_SETTING_CR_RANGE1,
            INPUT_TYPE_NUMERIC,
            g_callset_context.CTRNumberInput,
            3,
            guiBuffer);
    #endif /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 
    }

    SetLeftSoftkeyFunction(EntryCtrTimeDone, KEY_EVENT_UP);
    SetCategory69RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryCtrTimeDone
 * DESCRIPTION
 *  gets name input from user
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCtrTimeDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 err = 0;
    historyNode *History;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_callset_context.CTRStatusInput == 1)
    {
        if (gui_atoi((UI_string_type) g_callset_context.CTRNumberInput) < 1 ||
            gui_atoi((UI_string_type) g_callset_context.CTRNumberInput) > 3000)
        {
            err = 1;
        }
    }
    else
    {
    #ifdef __COUNTDOWN_PERIODIC_CTR_MODE__
        if (gui_atoi((UI_string_type) g_callset_context.CTRNumberInput) < 0 ||
            gui_atoi((UI_string_type) g_callset_context.CTRNumberInput) > 30)
    #else /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 
        if (gui_atoi((UI_string_type) g_callset_context.CTRNumberInput) < 30 ||
            gui_atoi((UI_string_type) g_callset_context.CTRNumberInput) > 60)
    #endif /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 
        {
            err = 1;
        }
    }
    if (mmi_ucs2strlen((PS8) g_callset_context.CTRNumberInput) == 0)
    {
        err = 1;
    }

    if (err == 1)
    {
        err = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID), IMG_GLOBAL_ERROR, 0, ST_NOTIFYDURATION, ERROR_TONE);
        if (GetHistoryScrID(SCR_ID_CALLSET_CTR_TIME, &History) == ST_SUCCESS)
        {
            if (History->inputBuffer != NULL)
            {
                memset(History->inputBuffer, 0, ENCODING_LENGTH);
            }
            if (History->guiBuffer != NULL)
            {
                memset(History->guiBuffer, 0, 2);
            }
        }
    }
    else
    {
        SendCtrTime();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCtrTimeDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCtrTimeDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    Scr.scrnID = SCR_SETTING_CTR_TIME_DONE;
    Scr.entryFuncPtr = EntryCtrTimeDone;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}


/*****************************************************************************
 * FUNCTION
 *  SendCtrTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SendCtrTime()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 time = 0;

    U16 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = g_callset_context.CTRStatusInput;
    time = (U16) gui_atoi((UI_string_type) g_callset_context.CTRNumberInput);

#ifdef __COUNTDOWN_PERIODIC_CTR_MODE__
    if (data == 2)
    {
        time = 60 - time;
    }
#endif /* __COUNTDOWN_PERIODIC_CTR_MODE__ */ 

    WriteValue(NVRAM_SETTING_CTR, &data, DS_BYTE, &error);
    WriteValue(NVRAM_SETTING_CTR_TIME, &time, DS_SHORT, &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, 0);
    /* micha0706 */
    DeleteScreenIfPresent(SCR_ID_CALLSET_CTR);
    DeleteScreenIfPresent(SCR_ID_CALLSET_CTR_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCALLSETCtrTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCALLSETCtrTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;    /* Variable to hold the history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_ID_CALLSET_CTR_TIME;
    Scr.entryFuncPtr = EntryCALLSETCtrTime;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) g_callset_context.CTRNumberInput);

    GetCategoryHistory(Scr.guiBuffer);
    AddHistory(Scr);
}

#ifdef __MMI_SS_SHOW_CAUSE__


/*****************************************************************************
 * FUNCTION
 *  ShowCauseString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause_number        [IN]        
 *  temp_string         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCauseString(U16 cause_number, PS8 temp_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    S8 TempBuff[MAX_DISP_UCS2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) temp_string, (PS8) GetString(STR_GLOBAL_NOT_DONE));
    for (i = 0; CauseDisplay[i].cause_number != (U16) NULL; i++)
    {
        if (cause_number == CauseDisplay[i].cause_number)
        {
            mmi_asc_to_ucs2((PS8) TempBuff, (PS8) CauseDisplay[i].cause_string);
            mmi_ucs2cat((PS8) temp_string, (PS8) TempBuff);
            return;
        }
    }
    mmi_ucs2cat((PS8) temp_string, (PS8) GetString(STR_UNKNOWN_CAUSE));
}

#endif /* __MMI_SS_SHOW_CAUSE__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetCtrStatus
 * DESCRIPTION
 *  Show whether PowerSaving Feature is on or off
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
SETTING_CTR GetCtrStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_CTR, &data, DS_BYTE, &error);
    /* micha1229 */
    return ((SETTING_CTR) data);
}


/*****************************************************************************
 * FUNCTION
 *  GetCtrTime
 * DESCRIPTION
 *  Show whether PowerSaving Feature is on or off
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
U16 GetCtrTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_CTR_TIME, &time, DS_SHORT, &error);

    return time;

}


/*****************************************************************************
 * FUNCTION
 *  AutoRedialOnOffStatus
 * DESCRIPTION
 *  Show whether AutoRedial Feature is on or off
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
MMI_BOOL AutoRedialOnOffStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_AUTOREDIAL, &data, DS_BYTE, &error);

    if (data == 1)
    {
        g_callset_context.AutoRedialStatus = 1;
        return MMI_TRUE;
    }
    else if (data == 0xff)
    {
        data = 0;
        WriteValue(NVRAM_SETTING_AUTOREDIAL, &data, DS_BYTE, &error);
        g_callset_context.AutoRedialStatus = 0;
        return MMI_FALSE;
    }
    else
    {
        g_callset_context.AutoRedialStatus = 0;
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CallTimeReminderStatus
 * DESCRIPTION
 *  Show whether AutoRedial Feature is on or off
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
U8 CallTimeReminderStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data = 0;
    U16 ctrTime = 0;
    S16 error;
    S8 temp_buf[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_CTR, &data, DS_BYTE, &error);
    ReadValue(NVRAM_SETTING_CTR_TIME, &ctrTime, DS_SHORT, &error);

    if (ctrTime == 0xffff)
    {
        ctrTime = 0;
        WriteValue(NVRAM_SETTING_CTR_TIME, &ctrTime, DS_SHORT, &error);
    }

    if (data == 0xff)
    {
        data = 0;
        WriteValue(NVRAM_SETTING_CTR, &data, DS_BYTE, &error);
    }

    g_callset_context.CTRStatusInput = data;
    g_callset_context.CTRStatus = data;

    if (ctrTime == 0 || data == 0)
    {
        memset(g_callset_context.CTRNumberInput, 0, MAX_CTR_NUM_DIGITS * ENCODING_LENGTH);
        memset(g_callset_context.CTRNumber, 0, MAX_CTR_NUM_DIGITS * ENCODING_LENGTH);
    }
    else
    {
        sprintf(temp_buf, "%d", ctrTime);
        mmi_asc_to_ucs2((PS8) g_callset_context.CTRNumberInput, temp_buf);
        mmi_ucs2cpy((PS8) g_callset_context.CTRNumber, (PS8) g_callset_context.CTRNumberInput);
    }
    return (data);
}


/*****************************************************************************
 * FUNCTION
 *  GetCallTimeDisplay
 * DESCRIPTION
 *  Show whether CallTime Display Feature is on or off
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *  
 *  Author            : Vanita Jain
 *****************************************************************************/
MMI_BOOL GetCallTimeDisplay(void)
{
#ifdef __MMI_DISABLE_CALL_TIME_DISPLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
#else /* __MMI_DISABLE_CALL_TIME_DISPLAY__ */ 
    U8 data = 0;
    S16 error;

    ReadValue(NVRAM_SETTING_CALL_TIME_DISPLAY, &data, DS_BYTE, &error);

    if (data == 1)
    {
        g_callset_context.CTDStatus = 1;
        return MMI_TRUE;
    }
    else if (data == 0xff)
    {
        data = 1;   /* Default =ON */
        g_callset_context.CTDStatus = 1;
        WriteValue(NVRAM_SETTING_CALL_TIME_DISPLAY, &data, DS_BYTE, &error);
        return MMI_TRUE;
    }
    else
    {
        g_callset_context.CTDStatus = 0;
        return MMI_FALSE;
    }
#endif /* __MMI_DISABLE_CALL_TIME_DISPLAY__ */ 
}

/* micha0921 begin */


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETGeneralSSResutScr
 * DESCRIPTION
 *  entry function for call waiting result screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETGeneralSSResutScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CALLSET_GENERAL_SS_RESULT, NULL, EntryCALLSETGeneralSSResut, NULL);
    RemoveSSReqScr();

    ShowCategory74Screen(
        STR_GLOBAL_DONE,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        g_callset_context.SSDisplayBuffer,
        mmi_ucs2strlen((PS8) g_callset_context.SSDisplayBuffer),
        NULL);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCALLSETGeneralSSResut
 * DESCRIPTION
 *  entry function for call waiting result screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCALLSETGeneralSSResut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM__
    if ((mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) == 0 &&
        mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) == 0) ||
        GetActiveScreenId() == SCR_CM_REQUESTINGUSSD)
#else /* __MMI_UCM__ */ 
    if ((!isIncomingCall()) || (GetActiveScreenId() == SCR_CM_REQUESTINGUSSD))
#endif /* __MMI_UCM__ */
    {
        RemoveSSReqScr();
        EntryCALLSETGeneralSSResutScr();
    }
    else
    {
        HistoryReplace(SCR_CM_REQUESTINGUSSD, SCR_ID_CALLSET_GENERAL_SS_RESULT, EntryCALLSETGeneralSSResutScr);
    }
}

/* micha0921 end */

#ifdef __IP_NUMBER__


/*****************************************************************************
 * FUNCTION
 *  InitIPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DUAL_SIM_MASTER__
    SetHiliteHandler(MENU_MTPNP_IP_NUM_ACTIVATE, HighlightCard2IPNumActivate);
#endif/* __MMI_DUAL_SIM_MASTER__*/
    SetHiliteHandler(MENU_IP_NUM_ACTIVATE, HighlightIPNumActivate);
    SetHiliteHandler(MENU_IP_NUM_EDIT, HighlightIPNumEdit);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(EntryScrViewIPNumbers, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrViewIPNumbers, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  LoadIPNumbers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LoadIPNumbers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DUAL_SIM_MASTER__
    ReadValue(NVRAM_SLAVE_IP_NUMBER_SETTING, &mtpnpIPSetting, DS_BYTE, &error);
#endif/* __MMI_DUAL_SIM_MASTER__*/
    ReadValue(NVRAM_IP_NUMBER_SETTING, &IPSetting, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_IP_NUMBER_LID, 1, IPNumber, sizeof(IPNumber), &error);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrViewIPNumbers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrViewIPNumbers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 highlite = 0;
    U8 *guiBuffer;
    U8 i;
    U16 PPIcons[MAX_IP_NUMBER];
    PU8 nStrItems[MAX_IP_NUMBER];

#ifdef __MMI_DUAL_SIM_MASTER__
    E_MTPNP_AD_STATUS mtpnpStatus;
#endif/* __MMI_DUAL_SIM_MASTER__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SETTING_IP_NUMBER, NULL, EntryScrViewIPNumbers, NULL);

    for (i = 0; i < MAX_IP_NUMBER; i++)
    {
        PPIcons[i] = 0;
        if (IPNumber[i][0] == 0)
        {
            nStrItems[i] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
        }
        else
        {
            nStrItems[i] = IPNumber[i];
        }
    }

#ifdef __MMI_DUAL_SIM_MASTER__
    mtpnpStatus = MTPNP_AD_Get_UsableSide();
    switch(mtpnpStatus)
    {
       case MTPNP_AD_DUALSIM_UNUSABLE:
	case MTPNP_AD_SIMCARD1_NOSIM_USABLE:
	case MTPNP_AD_SIMCARD2_NOSIM_USABLE:
		break;
	case MTPNP_AD_SIMCARD1_USABLE:
		if (IPSetting != 0xff)
		{
			highlite = IPSetting;
			PPIcons[IPSetting] = IMG_VICON;
		}
		break;
	case MTPNP_AD_SIMCARD2_USABLE:
		if(mtpnpIPSetting != 0xff)
		{
			highlite = mtpnpIPSetting;
			PPIcons[mtpnpIPSetting] = IMG_VICON;
		}
		break;
	case MTPNP_AD_DUALSIM_USABLE:
		if(IPSetting != 0xff)
		{
			PPIcons[IPSetting] = IMG_MTPNP_VICON_M;
		}
		if(mtpnpIPSetting != 0xff)
		{
			if(IPSetting == mtpnpIPSetting)
				PPIcons[mtpnpIPSetting] = IMG_MTPNP_VICON_BOTH;
			else
				PPIcons[mtpnpIPSetting] = IMG_MTPNP_VICON_S;
		}
		if((mtpnpIPSetting != 0xff) && (IPSetting != 0xff))
		{
                   highlite = (IPSetting < mtpnpIPSetting) ? IPSetting : mtpnpIPSetting;
		}
		else if(IPSetting != 0xff)
		{
                   highlite = IPSetting;
		}
		else if(mtpnpIPSetting != 0xff)
		{
                   highlite = mtpnpIPSetting;
		}
		else
		{
                   highlite = 0;
		}
		break;
	default:
		break;
    }
#else /* __MMI_DUAL_SIM_MASTER__*/
    if (IPSetting != 0xff)
    {
        highlite = IPSetting;
        PPIcons[IPSetting] = IMG_VICON;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
    RegisterHighlightHandler(SetCurIPNumberIndex);
    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_IP_NUMBER);

    ShowCategory53Screen(
        STR_SETTING_IP_NUMBER,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_IP_NUMBER,
        (U8 **) nStrItems,
        (U16*) PPIcons,
        NULL,
        0,
        (U16) highlite,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryScrIPNumberOptions, KEY_EVENT_UP);
	SetKeyHandler(EntryScrIPNumberOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  SetCurIPNumberIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurIPNumberIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curIPNumIndex = index;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrIPNumberOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIPNumberOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 nStrItem[3];

#ifdef __MMI_DUAL_SIM_MASTER__
    E_MTPNP_AD_STATUS mtpnpStatus;
#endif/* __MMI_DUAL_SIM_MASTER__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    mtpnpStatus = MTPNP_AD_Get_UsableSide();
    switch(mtpnpStatus)
    {
       case MTPNP_AD_DUALSIM_UNUSABLE:
	case MTPNP_AD_SIMCARD1_NOSIM_USABLE:
	case MTPNP_AD_SIMCARD2_NOSIM_USABLE:
	       mmi_frm_hide_menu_item(MENU_IP_NUM_ACTIVATE);
		mmi_frm_hide_menu_item(MENU_MTPNP_IP_NUM_ACTIVATE);
		break;
	case MTPNP_AD_DUALSIM_USABLE:
		mmi_frm_unhide_menu_item(MENU_IP_NUM_ACTIVATE);
		mmi_frm_unhide_menu_item(MENU_MTPNP_IP_NUM_ACTIVATE);
		break;
	case MTPNP_AD_SIMCARD1_USABLE:
		mmi_frm_unhide_menu_item(MENU_IP_NUM_ACTIVATE);
		mmi_frm_hide_menu_item(MENU_MTPNP_IP_NUM_ACTIVATE);
		break;
	case MTPNP_AD_SIMCARD2_USABLE:
		mmi_frm_hide_menu_item(MENU_IP_NUM_ACTIVATE);
		mmi_frm_unhide_menu_item(MENU_MTPNP_IP_NUM_ACTIVATE);
		break;
	default:
		break;
    }
#endif/* __MMI_DUAL_SIM_MASTER__*/
    EntryNewScreen(SCR_SETTING_IP_NUM_OPN, NULL, EntryScrIPNumberOptions, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_IP_NUM_OPN);

#ifdef __MMI_DUAL_SIM_MASTER__
    nNumofItem = GetNumOfChild_Ext(MENU_SETTING_IP_NUM_OPN);
    GetSequenceStringIds_Ext(MENU_SETTING_IP_NUM_OPN, nStrItem);
#else/* __MMI_DUAL_SIM_MASTER__*/
    nNumofItem = GetNumOfChild(MENU_SETTING_IP_NUM_OPN);
    GetSequenceStringIds(MENU_SETTING_IP_NUM_OPN, nStrItem);
#endif/* __MMI_DUAL_SIM_MASTER__*/
    SetParentHandler(MENU_SETTING_IP_NUM_OPN);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItem,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightIPNumActivate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIPNumActivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(ActivateIPNumber, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(ActivateIPNumber, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  HighlightCard2IPNumActivate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCard2IPNumActivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(ActivateCard2IPNumber, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(ActivateCard2IPNumber, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif/* __MMI_DUAL_SIM_MASTER__*/

/*****************************************************************************
 * FUNCTION
 *  HighlightIPNumEdit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightIPNumEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) newIPNum, (PS8) IPNumber[curIPNumIndex]);
    SetLeftSoftkeyFunction(EntryScrIPNumberEdit, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryScrIPNumberEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ActivateIPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) IPNumber[curIPNumIndex]) == 0)
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
        
        return;
    }
    IPSetting = curIPNumIndex;
    WriteValue(NVRAM_IP_NUMBER_SETTING, &IPSetting, DS_BYTE, &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_ACTIVATED), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_SETTING_IP_NUM_OPN);
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  ActivateCard2IPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateCard2IPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) IPNumber[curIPNumIndex]) == 0)
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
        
        return;
    }
    mtpnpIPSetting = curIPNumIndex;
    WriteValue(NVRAM_SLAVE_IP_NUMBER_SETTING, &mtpnpIPSetting, DS_BYTE, &error);
    DisplayPopup((PU8) GetString(STR_GLOBAL_ACTIVATED), IMG_GLOBAL_ACTIVATED, 1, 1000, SUCCESS_TONE);
    DeleteScreenIfPresent(SCR_SETTING_IP_NUM_OPN);
}
#endif /* __MMI_DUAL_SIM_MASTER__*/

/*****************************************************************************
 * FUNCTION
 *  EntryScrIPNumberEdit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrIPNumberEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SETTING_IP_NUM_EDIT, NULL, EntryScrIPNumberEdit, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_IP_NUM_EDIT);

    /*if (guiBuffer == NULL)
    {
        memset(newIPNum, 0, 20);
    }*/

    ShowCategory5Screen(
        STR_SETTING_IP_NUMBER,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_PHONE_NUMBER,
        (PU8) newIPNum,
        MAX_IP_NUMBER_LEN + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(SetIPNumber, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SetIPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetIPNumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_ucs2strlen((PS8) newIPNum) == 0 && (IPSetting == curIPNumIndex || mtpnpIPSetting == curIPNumIndex))
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (mmi_ucs2strlen((PS8) newIPNum) == 0 && IPSetting == curIPNumIndex)
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        DisplayPopup(
            (U8*)GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        return;
    }
    else if (mmi_ucs2strlen((PS8) newIPNum) >= MAX_IP_NUMBER_LEN)
    {
        newIPNum[MAX_IP_NUMBER_LEN * 2] = 0;
        newIPNum[MAX_IP_NUMBER_LEN * 2 + 1] = 0;
    }
    mmi_ucs2cpy((PS8) IPNumber[curIPNumIndex], (PS8) newIPNum);

    WriteRecord(NVRAM_EF_IP_NUMBER_LID, 1, IPNumber, sizeof(IPNumber), &error);

    GoBackToHistory(SCR_SETTING_IP_NUMBER);
    DeleteScreenIfPresent(SCR_SETTING_IP_NUM_EDIT);
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrIPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_str     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetCurrIPNumber(U8 *num_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_str != NULL)
    {
        num_str[0] = 0;

        if (IPSetting != 0xff)
        {
            mmi_ucs2_to_asc((PS8) num_str, (PS8) IPNumber[IPSetting]);
        }
    }
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  GetCurrCard2IPNumber
 * DESCRIPTION
 *  
 * PARAMETERS
 *  num_str     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetCurrCard2IPNumber(U8 *num_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_str != NULL)
    {
        num_str[0] = 0;

        if (mtpnpIPSetting != 0xff)
        {
            mmi_ucs2_to_asc((PS8) num_str, (PS8) IPNumber[mtpnpIPSetting]);
        }
    }
}
#endif/* __MMI_DUAL_SIM_MASTER__*/

/*****************************************************************************
 * FUNCTION
 *  GetCurrIPNumberUCS2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetCurrIPNumberUCS2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IPSetting != 0xff)
    {
        return (S8*) IPNumber[IPSetting];
    }
    else
    {
        return NULL;
    }
}

#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  GetCurrCard2IPNumberUCS2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetCurrCard2IPNumberUCS2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mtpnpIPSetting != 0xff)
    {
        return (S8*) IPNumber[mtpnpIPSetting];
    }
    else
    {
        return NULL;
    }
}
#endif/* __MMI_DUAL_SIM_MASTER__*/
#endif /* __IP_NUMBER__ */ 

/*****************************************************************************
 * FUNCTION
 *  GetBlackListMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL GetBlackListMode(void)
{
#ifdef __MMI_CM_BLACK_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gBlackListFlag;
#else
    return FALSE;
#endif
}



/*****************************************************************************
 * FUNCTION
 *  IsBlackListNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  number      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL IsBlackListNum(PU8 number)
{
#ifdef __MMI_CM_BLACK_LIST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U8 tmpNumber[MAX_NUMBER];
    U8 tmpBlackListNumber[MAX_NUMBER];
    U32 newNumber, newBlackListNum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index=0; index< MAX_NUMBER; index++)
	{
		PRINT_INFORMATION("black list number[%d]:%c\n\n",index,number[index]);
	}
	
	memset(tmpNumber, 0, ENCODING_LENGTH);
    mmi_ucs2_to_asc((PS8) tmpNumber, (PS8) number);

    newNumber = mmi_phb_util_convert_number_to_int(tmpNumber);

    for (index = 0; index < MAX_BLACK_LIST_NUMBER; index++)
    {
        mmi_ucs2_to_asc((PS8) tmpBlackListNumber, (PS8) BlackListNum[index]);
        newBlackListNum = mmi_phb_util_convert_number_to_int(tmpBlackListNumber);
        if (newNumber == newBlackListNum)
        {
            return TRUE;
        }

    }
    return FALSE;
#else
    return FALSE;
#endif
}

/* Start by Julia */
#ifdef __MMI_CM_BLACK_LIST__


/*****************************************************************************
 * FUNCTION
 *  InitBlackList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitBlackList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_SETTING_BLACK_LIST_MODE, HighlightBlackListMode);
    SetHiliteHandler(MENU_SETTING_BLACK_LIST_NUM, HighlightBlackListNum);
    SetHintHandler(MENU_SETTING_BLACK_LIST_MODE, HintBlackListMode);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightBlackList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBlackList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(EntryScrBlackList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrBlackList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBlackListMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBlackListMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetBlackListMode() == TRUE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrBlackListMode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightBlackListNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightBlackListNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_BLACK_LIST_NUMBER; index++)
    {
        mmi_ucs2cpy((PS8) dispBlackListNum[index], (PS8) BlackListNum[index]);
    }
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetKeyHandler(EntryScrBlackListNum, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrBlackListNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HintBlackList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintBlackList(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, MAX_SUB_MENU_SIZE);
    if (GetBlackListMode() == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  HintBlackListMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintBlackListMode(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, MAX_SUB_MENU_SIZE);
    if (GetBlackListMode() == TRUE)
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrBlackList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrBlackList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 nStrItem[3];
    U8 *BlackListType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SETTING_BLACK_LIST, NULL, EntryScrBlackList, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_BLACK_LIST);

    nNumofItem = GetNumOfChild(MENU_SETTING_BLACK_LIST);
    GetSequenceStringIds(MENU_SETTING_BLACK_LIST, nStrItem);
    SetParentHandler(MENU_SETTING_BLACK_LIST);
    ConstructHintsList(MENU_SETTING_BLACK_LIST, BlackListType);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_SETTING_BLACK_LIST,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItem,
        (U16*) gIndexIconsImageList,
        BlackListType,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrBlackListMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrBlackListMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (GetBlackListMode() == TRUE)
    {
        SetBlackListMode(FALSE);
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(0, (U8*) GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        SetBlackListMode(TRUE);
        mmi_ucs2cpy((S8*) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(0, (U8*) GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    RedrawCategoryFunction();
    HighlightBlackListMode();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScrBlackListNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrBlackListNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 index;
    U16 BlackListNumImageList[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_SETTING_BLACK_LIST_NUM, ExitScrBlackListNum, NULL, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_SETTING_BLACK_LIST_NUM);

    /* 3 Set current parent id */
    InitializeCategory57Screen();

    for (index = 0; index < MAX_BLACK_LIST_NUMBER; index++)
    {
        SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemTextEdit(
            &wgui_inline_items[index],
            (PU8) dispBlackListNum[index],
            MAX_BLACK_LIST_NUMBER_LEN + 1,
            INPUT_TYPE_PHONE_NUMBER | INPUT_TYPE_PLUS_CHARACTER_HANDLING);
        DisableInlineItemHighlight(&wgui_inline_items[index]);
    }
    BlackListNumImageList[0] = IMG_GLOBAL_L1;
    BlackListNumImageList[1] = IMG_GLOBAL_L2;
    BlackListNumImageList[2] = IMG_GLOBAL_L3;
    BlackListNumImageList[3] = IMG_GLOBAL_L4;
    BlackListNumImageList[4] = IMG_GLOBAL_L5;
    /* added for inline edit history */
    inputBuffer = GetCurrNInputBuffer(SCR_SETTING_BLACK_LIST_NUM, &inputBufferSize);

    RegisterHighlightHandler(SetCurrBlackListNumIndex);

    /* added for inline edit history */
    if ((guiBuffer != NULL) && (guiBuffer[0] != 0))
    {
        /* sets the data */
        SetCategory57Data(wgui_inline_items, MAX_BLACK_LIST_NUMBER, inputBuffer);
    }

    /* DisableCategory57ScreenDone(); */

    ShowCategory57Screen(
        STR_SETTING_BLACK_LIST_NUM,
    #ifdef __MMI_UCM__
        GetRootTitleIcon(MENU_ID_UCM_CALL_SETTING),
    #else
        MAIN_MENU_TITLE_SETTINGS_ICON,
    #endif /* __MMI_UCM__ */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_BLACK_LIST_NUMBER,
        BlackListNumImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(EntryScrSetBlackListNumConfirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrBlackListNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrBlackListNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize;    /* added for inline edit history */
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_SETTING_BLACK_LIST_NUM;
    currHistory.entryFuncPtr = EntryScrBlackListNum;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);

    /* added for inline edit history */
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrSetBlackListNumConfirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrSetBlackListNumConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(SetBlackListNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoToBlackList, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  GoToBlackList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoToBlackList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_SETTING_BLACK_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  SetBlackListMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetBlackListMode(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gBlackListFlag = flag;
    WriteValue(NVRAM_BLACK_LIST_SETTING, &gBlackListFlag, DS_BYTE, &error);
}

/*****************************************************************************
 * FUNCTION
 *  SetBlackListNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetBlackListNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MAX_BLACK_LIST_NUMBER; index++)
    {
        mmi_ucs2cpy((PS8) BlackListNum[index], (PS8) dispBlackListNum[index]);
    }
    WriteRecord(NVRAM_EF_BLACK_LIST_LID, 1, BlackListNum, sizeof(BlackListNum), &error);

    DisplayPopup(
        (PU8)GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_SETTING_BLACK_LIST_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  LoadBlackListNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void LoadBlackListNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BLACK_LIST_SETTING, &gBlackListFlag, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_BLACK_LIST_LID, 1, BlackListNum, sizeof(BlackListNum), &error);
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrBlackListNumIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrBlackListNumIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curBlackListNumIndex = index;
}
#endif /* __MMI_CM_BLACK_LIST__ */ 
/* End by Julia */

