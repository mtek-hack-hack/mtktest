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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_Ems.c

  	PURPOSE		: Populate Resource for EMS

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-19-2003

**************************************************************/
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MessagesResDef.h"
#include "CustResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

void PopulateEMSObjectResources(void)
{
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
#endif
   ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_0_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\IRONIC.gif","EMS built in animation 1");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_1_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\GLAD.gif","EMS built in animation 2");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_2_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\SCEPTIC.gif","EMS built in animation 3");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_3_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\SAD.gif","EMS built in animation 4");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_4_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\WOW.gif","EMS built in animation 5");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_5_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\CRY.gif","EMS built in animation 6");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_6_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\WINK.gif","EMS built in animation 7");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_7_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\LAUGH.gif","EMS built in animation 8");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_8_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\INDIFF.gif","EMS built in animation 9");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_9_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\KISS.gif","EMS built in animation 10");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_10_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\CONFUSE.gif","EMS built in animation 11");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_11_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\TONGUE.gif","EMS built in animation 12");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_12_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\ANGRY.gif","EMS built in animation 13");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_13_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\GLASS.gif","EMS built in animation 14");
	ADD_APPLICATION_IMAGE2(EMS_BI_ANIMATION_14_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\DEVIL.gif","EMS built in animation 15");
	ADD_APPLICATION_IMAGE2(EMS_EDITOR_SOUND_OBJECT_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\sound.bmp","Icon used to indicate Sound objects in EMS");
	ADD_APPLICATION_IMAGE2(EMS_EDITOR_MELODY_OBJECT_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\melody.bmp","Icon used to indicate Melody objects in EMS");
	ADD_APPLICATION_IMAGE2(EMS_CAN_INSERT_OBJECT_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\can.bmp","Icon to indicate that an EMS object can be inserted");
	ADD_APPLICATION_IMAGE2(EMS_CANNOT_INSERT_OBJECT_ID,CUST_IMG_PATH"\\\\MAINLCD\\\\Sms\\\\EMS\\\\cannt.bmp","Icon to indicate that an EMS object cannot be inserted");
}

#endif


