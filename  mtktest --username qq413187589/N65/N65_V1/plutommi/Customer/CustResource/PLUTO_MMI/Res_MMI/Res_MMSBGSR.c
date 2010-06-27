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
 *	Res_MMSBGSR.c
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file populates resource for Unified Message.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_RES_BGSR_C
#define _MMI_RES_BGSR_C
#include "MMI_features.h"

#ifdef __MMI_MMS_BGSR_SUPPORT__


#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMSBGSRResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


/**************************************************************

	FUNCTION NAME		: PopulateMMSBGSRResData

  	PURPOSE				: Register all the resources required by Unified Message

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void PopulateMMSBGSRResData (void)
{
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_OK,"OK","OK");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_INCALL,"Fail:In Call","Fail:In Call");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_NOT_READY,"Fail:Not Ready","Fail:Not Ready");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_BUSY,"Fail:Busy","Fail:Busy");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY,"Fail:Insufficient Memory","Fail:Insufficient Memory");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE,"Fail:Insufficient Storage","Fail:Insufficient Storage");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_FILE_NOT_FOUND,"Fail:File Not Found","Fail:File Not Found");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_FILE_CORRUPTED,"Fail:File Corrupted","Fail:File Corrupted");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_FILE_IN_USE,"Fail:File In Use","Fail:File In Use");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_FILE_IO,"Fail:IO","Fail:IO");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_FOLDER_NOT_FOUND,"Fail:Folder Not Found","Fail:Folder Not Found");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT,"Fail:Unsupport Content","Fail:Unsupport Content");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT,"Fail:Comm Unsupport Content","Fail:Comm Unsupport Content");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR,"Fail:Comm Config Error","Fail:Comm Config Error");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR,"Fail:Comm Connect Error","Fail:Comm Connect Error");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_SERVER_ERROR,"Fail:Comm Server Error","Fail:COmm Server Error");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT,"Fail:Comm Server Timeout","Fail:Comm Server Timeout");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED,"Fail:Comm Service Denied","Fail:Comm Service Denied");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_UNKNOWN_APN,"Fail:Comm Unknown APN","Fail:Comm Unknown APN");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED,"Fail:Comm Unauthorized","Fail:Comm Unauthorized");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_USER_CANCEL,"Fail:User Cancel","Fail:User Cancel");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_INVALID_PARAMETER,"Fail:Invalid Parameter","Fail:Invalid Parameter");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_INVALID_MSGID,"Fail:Invalid Message ID","Fail:Invalid Message ID");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_INVALID_FOLDER,"Fail:Invalid Folder","Fail:Invalid Folder");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_QUEUE_FULL,"Fail:Queue Full","Fail:Queue Full");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_MSGID_IS_USING,"Fail:Message ID Is Using","Fail:Message ID Is Using");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED,"Fail:Max Message Size Reached","Fail:Max Message Size Reached");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM,"Fail:Update Checksum Invalid Parameter","Fail:Update Checksum Invalid Parameter");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE,"Fail:Access In USB Mode","Fail:Access In USB Mode");
	ADD_APPLICATION_STRING2(STR_ID_BGSR_RESULT_FAIL,"Fail","Fail");
    ADD_APPLICATION_STRING2(STR_ID_BGSR_MESSAGE_IS_TRANSMITTING,"The Message Is Transmitting","The Message Is Transmitting");
    ADD_APPLICATION_STRING2(STR_ID_BGSR_SEND_FAIL_RESEND,"Send fail. It will resend.","Send fail. It will resend.");    
    
}
#endif

#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#endif  /*_MMI_RES_BGSR_C*/

