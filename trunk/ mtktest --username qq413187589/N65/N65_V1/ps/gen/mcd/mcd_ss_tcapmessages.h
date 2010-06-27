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
 * MCD_SS_TCAPMESSAGES_H
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
#ifndef _MCD_SS_TCAPMESSAGES_H
#define _MCD_SS_TCAPMESSAGES_H
/**************************************************************
 * Module name: TCAPMessages
 **************************************************************/
typedef struct GeneralProblem
{
	kal_uint32 value;
} GeneralProblem;


typedef struct InvokeProblem
{
	kal_uint32 value;
} InvokeProblem;


typedef struct ReturnResultProblem
{
	kal_uint32 value;
} ReturnResultProblem;


typedef struct ReturnErrorProblem
{
	kal_uint32 value;
} ReturnErrorProblem;


typedef struct InvokeIdType
{
	kal_uint32 value;
} InvokeIdType;


typedef struct Invoke
{
	InvokeIdType* invokeID;
	kal_uint8 linkedIDOpt;
	InvokeIdType* linkedID;
	kal_uint8 localValueOpt;
	kal_uint32 localValue;

	kal_uint8 globalValueOpt;
	kal_uint32 globalValueLen;
	kal_uint8 *globalValue;

	kal_uint8 parameterOpt;
	kal_uint32 parameterLen;
	kal_uint8 *parameter;
} Invoke;


typedef struct ReturnResult
{
	InvokeIdType* invokeID;
	kal_uint8 resultOpt;
	kal_uint8 localValueOpt;
	kal_uint32 localValue;

	kal_uint8 globalValueOpt;
	kal_uint32 globalValueLen;
	kal_uint8 *globalValue;

	kal_uint32 parameterLen;
	kal_uint8 *parameter;
} ReturnResult;


typedef struct ReturnError
{
	InvokeIdType* invokeID;
	kal_uint8 localValueOpt;
	kal_uint32 localValue;

	kal_uint8 globalValueOpt;
	kal_uint32 globalValueLen;
	kal_uint8 *globalValue;

	kal_uint8 parameterOpt;
	kal_uint32 parameterLen;
	kal_uint8 *parameter;
} ReturnError;


typedef struct Reject
{
	kal_uint8 derivableOpt;
	InvokeIdType* derivable;

	kal_uint8 not_derivableOpt;

	kal_uint8 generalProblemOpt;
	GeneralProblem* generalProblem;

	kal_uint8 invokeProblemOpt;
	InvokeProblem* invokeProblem;

	kal_uint8 returnResultProblemOpt;
	ReturnResultProblem* returnResultProblem;

	kal_uint8 returnErrorProblemOpt;
	ReturnErrorProblem* returnErrorProblem;

} Reject;


typedef struct Component
{
	kal_uint8 invokeOpt;
	Invoke* invoke;

	kal_uint8 returnResultLastOpt;
	ReturnResult* returnResultLast;

	kal_uint8 returnErrorOpt;
	ReturnError* returnError;

	kal_uint8 rejectOpt;
	Reject* reject;

	kal_uint8 returnResultNotLastOpt;
	ReturnResult* returnResultNotLast;

} Component;


typedef struct ComponentPortion
{
	kal_uint32 ComponentPortionLen;
	Component* ComponentPortion [1];
} ComponentPortion;


#endif /*_MCD_SS_TCAPMESSAGES_H*/
