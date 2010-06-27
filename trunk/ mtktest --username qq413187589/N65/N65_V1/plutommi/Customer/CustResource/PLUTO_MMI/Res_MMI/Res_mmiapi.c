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
 *	Res_mmiapi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to dispatch the message
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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

#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"
#include "mmiapi_res.h"
void PopulateMmiapiRes(void)
{

	ADD_APPLICATION_STRING2(MMIAPI_STR_ID_DONE,"Done","Done");
	ADD_APPLICATION_STRING2(MMIAPI_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(MMIAPI_STR_ID_INPUT_METHOD,"Input Method","Input Method");
	ADD_APPLICATION_STRING2(MMIAPI_STR_ID_OPTION,"Option","Option");
	ADD_APPLICATION_STRING2(MMIAPI_STR_ID_INPUT_TITLE,"Input","Input");

	ADD_APPLICATION_MENUITEM((
		MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION,0,3,
		MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
		MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
		MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
		SHOW, NONMOVEABLE, 
		DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((
				MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
				MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE, 
				DISP_LIST,MMIAPI_STR_ID_DONE,NULL));

	ADD_APPLICATION_MENUITEM((
				MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
				MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE, 
				DISP_LIST,MMIAPI_STR_ID_CANCEL,NULL));

	ADD_APPLICATION_MENUITEM((
				MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
				MMIAPI_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE, 
				DISP_LIST,MMIAPI_STR_ID_INPUT_METHOD,NULL));

}

#endif


