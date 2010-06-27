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
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES
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
 * MCD_SS_PARAMETERS_H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _MCD_SS_PARAMETERS_H
#define _MCD_SS_PARAMETERS_H
/**************************************************************
 * Module name: SS-Asn
 **************************************************************/
#define maxNumOfCCBS_Requests 5
#define maxNumOfBasicServiceGroups 13
#define maxAddressLength 20
#define maxISDN_SubaddressLength 21
#define maxISDN_AddressLength 9
#define maxUSSD_StringLength 160
typedef struct CliRestrictionOption
{
	kal_uint32 value;
} CliRestrictionOption;


typedef enum
{
	permanent = 0,
	temporaryDefaultRestricted = 1,
	temporaryDefaultAllowed = 2
} clirestrictionoption_enum;

typedef struct OverrideCategory
{
	kal_uint32 value;
} OverrideCategory;


typedef enum
{
	overrideEnabled = 0,
	overrideDisabled = 1
} overridecategory_enum;

typedef struct SS_Code
{
	kal_uint8 octs [1];
} SS_Code;


typedef struct CCBS_Index
{
	kal_uint32 value;
} CCBS_Index;


typedef struct SS_Status
{
	kal_uint8 octs [1];
} SS_Status;


typedef struct EMLPP_Priority
{
	kal_uint32 value;
} EMLPP_Priority;


typedef struct USSD_DataCodingScheme
{
	kal_uint8 octs [1];
} USSD_DataCodingScheme;


typedef struct USSD_String
{
	kal_uint32 octsLen;
	kal_uint8 *octs;
} USSD_String;


typedef struct USSDIA5_String
{
	kal_uint32 octsLen;
	kal_uint8 *octs;
} USSDIA5_String;


typedef struct AlertingPattern
{
	kal_uint8 octs [1];
} AlertingPattern;


typedef struct EraseCC_EntryArg
{
	SS_Code* ss_Code;
	kal_uint8 ccbs_IndexOpt;
	CCBS_Index* ccbs_Index;
} EraseCC_EntryArg;


typedef struct EraseCC_EntryRes
{
	SS_Code* ss_Code;
	kal_uint8 ss_StatusOpt;
	SS_Status* ss_Status;
} EraseCC_EntryRes;


typedef struct BearerServiceCode
{
	kal_uint8 octs [1];
} BearerServiceCode;


typedef struct TeleserviceCode
{
	kal_uint8 octs [1];
} TeleserviceCode;


typedef struct BasicServiceCode
{
	kal_uint8 dummyOpt;
	BearerServiceCode* dummy;

	kal_uint8 bearerServiceOpt;
	BearerServiceCode* bearerService;

	kal_uint8 teleserviceOpt;
	TeleserviceCode* teleservice;

} BasicServiceCode;


typedef struct BasicServiceCodeSeq
{
	kal_uint8 dummyOpt;
	BearerServiceCode* dummy;
	kal_uint8 bearerServiceOpt;
	BearerServiceCode* bearerService;
	kal_uint8 teleserviceOpt;
	TeleserviceCode* teleservice;
} BasicServiceCodeSeq;


typedef struct BasicServiceGroupList
{
	kal_uint32 listLen;
	BasicServiceCode* list [13];
} BasicServiceGroupList;


typedef struct AddressString
{
	kal_uint32 octsLen;
	kal_uint8 *octs;
} AddressString;


typedef struct AddressString ISDN_AddressString;
typedef struct ISDN_SubaddressString
{
	kal_uint32 octsLen;
	kal_uint8 *octs;
} ISDN_SubaddressString;


typedef struct ForwardingOptions
{
	kal_uint8 octs [1];
} ForwardingOptions;


typedef struct NoReplyConditionTime
{
	kal_uint32 value;
} NoReplyConditionTime;


typedef struct ForwardingFeature
{
	kal_uint8 basicServiceOpt;
	BasicServiceCode* basicService;
	kal_uint8 ss_StatusOpt;
	SS_Status* ss_Status;
	kal_uint8 forwardedToNumberOpt;
	AddressString* forwardedToNumber;
	kal_uint8 forwardedToSubaddressOpt;
	ISDN_SubaddressString* forwardedToSubaddress;
	kal_uint8 forwardingOptionsOpt;
	ForwardingOptions* forwardingOptions;
	kal_uint8 noReplyConditionTimeOpt;
	NoReplyConditionTime* noReplyConditionTime;
	kal_uint8 longForwardedToNumberOpt;
	AddressString* longForwardedToNumber;
} ForwardingFeature;


typedef struct ForwardingFeatureList
{
	kal_uint32 listLen;
	ForwardingFeature* list [13];
} ForwardingFeatureList;


typedef struct CCBS_Feature
{
	kal_uint8 ccbs_IndexOpt;
	CCBS_Index* ccbs_Index;
	kal_uint8 b_subscriberNumberOpt;
	AddressString* b_subscriberNumber;
	kal_uint8 b_subscriberSubaddressOpt;
	ISDN_SubaddressString* b_subscriberSubaddress;
	kal_uint8 basicServiceGroupOpt;
	BasicServiceCodeSeq* basicServiceGroup;
} CCBS_Feature;


typedef struct CCBS_FeatureList
{
	kal_uint32 listLen;
	CCBS_Feature* list [5];
} CCBS_FeatureList;


typedef struct GenericServiceInfo
{
	SS_Status* ss_Status;
	kal_uint8 cliRestrictionOptionOpt;
	CliRestrictionOption* cliRestrictionOption;
	kal_uint8 maximumEntitledPriorityOpt;
	EMLPP_Priority* maximumEntitledPriority;
	kal_uint8 defaultPriorityOpt;
	EMLPP_Priority* defaultPriority;
	kal_uint8 ccbs_FeatureListOpt;
	CCBS_FeatureList* ccbs_FeatureList;
	kal_uint8 nbrSBOpt;
	kal_uint32 nbrSB;
	kal_uint8 nbrUserOpt;
	kal_uint32 nbrUser;
	kal_uint8 nbrSNOpt;
	kal_uint32 nbrSN;
} GenericServiceInfo;


typedef struct InterrogateSS_Res
{
	kal_uint8 ss_StatusOpt;
	SS_Status* ss_Status;

	kal_uint8 basicServiceGroupListOpt;
	BasicServiceGroupList* basicServiceGroupList;

	kal_uint8 forwardingFeatureListOpt;
	ForwardingFeatureList* forwardingFeatureList;

	kal_uint8 genericServiceInfoOpt;
	GenericServiceInfo* genericServiceInfo;

} InterrogateSS_Res;


typedef struct RegisterSS_Arg
{
	SS_Code* ss_Code;
	kal_uint8 basicServiceOpt;
	BasicServiceCode* basicService;
	kal_uint8 forwardedToNumberOpt;
	AddressString* forwardedToNumber;
	kal_uint8 forwardedToSubaddressOpt;
	ISDN_SubaddressString* forwardedToSubaddress;
	kal_uint8 noReplyConditionTimeOpt;
	NoReplyConditionTime* noReplyConditionTime;
	kal_uint8 defaultPriorityOpt;
	EMLPP_Priority* defaultPriority;
	kal_uint8 nbrUserOpt;
	kal_uint32 nbrUser;
} RegisterSS_Arg;


typedef struct SS_ForBS_Code
{
	SS_Code* ss_Code;
	kal_uint8 basicServiceOpt;
	BasicServiceCode* basicService;
} SS_ForBS_Code;


typedef struct CallBarringFeature
{
	kal_uint8 basicServiceOpt;
	BasicServiceCode* basicService;
	kal_uint8 ss_StatusOpt;
	SS_Status* ss_Status;
} CallBarringFeature;


typedef struct CallBarringFeatureList
{
	kal_uint32 listLen;
	CallBarringFeature* list [13];
} CallBarringFeatureList;


typedef struct CallBarringInfo
{
	kal_uint8 ss_CodeOpt;
	SS_Code* ss_Code;
	CallBarringFeatureList* callBarringFeatureList;
} CallBarringInfo;


typedef struct ForwardingInfo
{
	kal_uint8 ss_CodeOpt;
	SS_Code* ss_Code;
	ForwardingFeatureList* forwardingFeatureList;
} ForwardingInfo;


typedef struct SS_SubscriptionOption
{
	kal_uint8 cliRestrictionOptionOpt;
	CliRestrictionOption* cliRestrictionOption;

	kal_uint8 overrideCategoryOpt;
	OverrideCategory* overrideCategory;

} SS_SubscriptionOption;


typedef struct SS_Data
{
	kal_uint8 ss_CodeOpt;
	SS_Code* ss_Code;
	kal_uint8 ss_StatusOpt;
	SS_Status* ss_Status;
	kal_uint8 ss_SubscriptionOptionOpt;
	SS_SubscriptionOption* ss_SubscriptionOption;
	kal_uint8 basicServiceGroupListOpt;
	BasicServiceGroupList* basicServiceGroupList;
	kal_uint8 defaultPriorityOpt;
	EMLPP_Priority* defaultPriority;
	kal_uint8 nbrUserOpt;
	kal_uint32 nbrUser;
} SS_Data;


typedef struct SS_Info
{
	kal_uint8 forwardingInfoOpt;
	ForwardingInfo* forwardingInfo;

	kal_uint8 callBarringInfoOpt;
	CallBarringInfo* callBarringInfo;

	kal_uint8 ss_DataOpt;
	SS_Data* ss_Data;

} SS_Info;


typedef struct USSD_Arg
{
	USSD_DataCodingScheme* ussd_DataCodingScheme;
	USSD_String* ussd_String;
	kal_uint8 alertingPatternOpt;
	AlertingPattern* alertingPattern;
	kal_uint8 msisdnOpt;
	AddressString* msisdn;
} USSD_Arg;


typedef struct USSD_Res
{
	USSD_DataCodingScheme* ussd_DataCodingScheme;
	USSD_String* ussd_String;
} USSD_Res;


typedef struct GuidanceInfo
{
	kal_uint32 value;
} GuidanceInfo;


typedef enum
{
	enterPW = 0,
	enterNewPW = 1,
	enterNewPW_Again = 2
} guidanceinfo_enum;

typedef struct Password
{
	kal_uint8 octs [4];
} Password;


typedef struct CUG_Index
{
	kal_uint32 value;
} CUG_Index;


typedef struct OperationCode
{
	kal_uint8 localValueOpt;
	kal_uint32 localValue;

	kal_uint8 globalValueOpt;
	kal_uint32 globalValueLen;
	kal_uint8 *globalValue;

} OperationCode;


typedef struct OperationCode CallDeflection;
typedef struct ForwardCUG_InfoArg
{
	kal_uint8 cug_IndexOpt;
	CUG_Index* cug_Index;
	kal_uint8 suppressPrefCUGOpt;
	kal_uint8 suppressOAOpt;
} ForwardCUG_InfoArg;


#define max10TimesUnitsPerTime 8191
typedef struct E1
{
	kal_uint32 value;
} E1;


#define max10TimesTimeInterval 8191
typedef struct E2
{
	kal_uint32 value;
} E2;


#define max100TimesScalingFactor 8191
typedef struct E3
{
	kal_uint32 value;
} E3;


#define max10TimesIncrement 8191
typedef struct E4
{
	kal_uint32 value;
} E4;


#define max10TimesIncrementPerDataInterval 8191
typedef struct E5
{
	kal_uint32 value;
} E5;


#define maxNumberOfSegmentsPerDataInterval 8191
typedef struct E6
{
	kal_uint32 value;
} E6;


#define max10TimesInitialTime 8191
typedef struct E7
{
	kal_uint32 value;
} E7;


typedef struct ChargingInformation
{
	kal_uint8 e1Opt;
	E1* e1;
	kal_uint8 e2Opt;
	E2* e2;
	kal_uint8 e3Opt;
	E3* e3;
	kal_uint8 e4Opt;
	E4* e4;
	kal_uint8 e5Opt;
	E5* e5;
	kal_uint8 e6Opt;
	E6* e6;
	kal_uint8 e7Opt;
	E7* e7;
} ChargingInformation;


typedef struct ForwardChargeAdviceArg
{
	SS_Code* ss_Code;
	ChargingInformation* chargingInformation;
} ForwardChargeAdviceArg;


typedef struct SS_Notification
{
	kal_uint8 octs [1];
} SS_Notification;


typedef struct ECT_CallState
{
	kal_uint32 value;
} ECT_CallState;


typedef enum
{
	alerting = 0,
	active = 1
} ect_callstate_enum;

typedef struct NameSet
{
	USSD_DataCodingScheme* dataCodingScheme;
	kal_uint32 lengthInCharacters;
	USSD_String* nameString;
} NameSet;


typedef struct Name
{
	kal_uint8 namePresentationAllowedOpt;
	NameSet* namePresentationAllowed;
	kal_uint8 presentationRestrictedOpt;
	kal_uint8 nameUnavailableOpt;
	kal_uint8 namePresentationRestrictedOpt;
	NameSet* namePresentationRestricted;
} Name;


typedef struct NameIndicator
{
	kal_uint8 callingNameOpt;
	Name* callingName;
} NameIndicator;


typedef struct RemotePartyNumber
{
	AddressString* partyNumber;
	kal_uint8 partyNumberSubaddressOpt;
	ISDN_SubaddressString* partyNumberSubaddress;
} RemotePartyNumber;


typedef struct RDN
{
	kal_uint8 presentationAllowedAddressOpt;
	RemotePartyNumber* presentationAllowedAddress;
	kal_uint8 presentationRestrictedOpt;
	kal_uint8 numberNotAvailableDueToInterworkingOpt;
	kal_uint8 presentationRestrictedAddressOpt;
	RemotePartyNumber* presentationRestrictedAddress;
} RDN;


typedef struct ECT_Indicator
{
	kal_uint32 ect_CallState;
	kal_uint8 rdnOpt;
	RDN* rdn;
} ECT_Indicator;


typedef struct NotifySS_Arg
{
	kal_uint8 ss_CodeOpt;
	SS_Code* ss_Code;
	kal_uint8 ss_StatusOpt;
	SS_Status* ss_Status;
	kal_uint8 ss_NotificationOpt;
	SS_Notification* ss_Notification;
	kal_uint8 callIsWaiting_IndicatorOpt;
	kal_uint8 callOnHold_IndicatorOpt;
	kal_uint32 callOnHold_Indicator;
	kal_uint8 mpty_IndicatorOpt;
	kal_uint8 cug_IndexOpt;
	CUG_Index* cug_Index;
	kal_uint8 clirSuppressionRejectedOpt;
	kal_uint8 ect_IndicatorOpt;
	ECT_Indicator* ect_Indicator;
	kal_uint8 nameIndicatorOpt;
	NameIndicator* nameIndicator;
	kal_uint8 ccbs_FeatureOpt;
	CCBS_Feature* ccbs_Feature;
	kal_uint8 alertingPatternOpt;
	AlertingPattern* alertingPattern;
} NotifySS_Arg;


typedef struct RegisterCC_EntryRes
{
	kal_uint8 ccbs_FeatureOpt;
	CCBS_Feature* ccbs_Feature;
} RegisterCC_EntryRes;


typedef struct UUS_Service
{
	kal_uint32 value;
} UUS_Service;


typedef enum
{
	uUS1 = 1,
	uUS2 = 2,
	uUS3 = 3
} uus_service_enum;

typedef struct UserUserServiceArg
{
	kal_uint32 uUS_Service;
	kal_uint8 uUS_Required;
} UserUserServiceArg;


typedef struct CallDeflectionArg
{
	AddressString* deflectedToNumber;
	kal_uint8 deflectedToSubaddressOpt;
	ISDN_SubaddressString* deflectedToSubaddress;
} CallDeflectionArg;


#endif /*_MCD_SS_PARAMETERS_H*/
