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

	FILENAME	: Res_MtkApp.c

  	PURPOSE		: Populate Resource for MtkApp

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-15-2003

**************************************************************/

//MTK Add Robin 1001 for saperate MMI feature by project
#include "MMI_features.h"
//MTK End

#include "CustomCfg.h"


#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "WapResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


void PopulateWapRes(void)
{
#ifdef OBIGO_Q03C
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// wap status icon

#ifdef __MMI_DUAL_SIM__

    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\JSR\\\\Master\\\\mms_messagejsr_sim1.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\JSR\\\\Slave\\\\mms_messagejsr_sim2.bmp","java mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_OUTBOX_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\master\\\\SB_UTBOX_sim1.bmp","mms menu icon outbox");
    ADD_APPLICATION_IMAGE2(MEA_IMG_OUTBOX_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\slave\\\\SB_UTBOX_sim2.bmp","mms menu icon outbox");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\SB_SET_sim1.bmp","mms draft message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Listmenuicon\\\\SB_SET_sim2.bmp","mms draft message icon");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_SENT_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\master\\\\SB_UTBOX_sim1.bmp","mms menu icon sent");
    ADD_APPLICATION_IMAGE2(MEA_IMG_SENT_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\slave\\\\SB_UTBOX_sim2.bmp","mms menu icon sent");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_sim1.bmp","unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_sim2.bmp","unread forward-lock mms icon");    
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_h_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_h_sim2.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_L_sim1.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_L_sim2.bmp","unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_sim1.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_read_sim2.bmp","forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_h_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_read_h_sim2.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Master\\\\mms_lock_read_L_sim1.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\lock\\\\Slave\\\\mms_lock_read_L_sim2.bmp","forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_sim1.bmp","mms unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_sim2.bmp","mms unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_h_sim1.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_h_sim2.bmp","mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_message_l_sim1.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_message_l_sim2.bmp","mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_sim1.bmp","mms read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_sim2.bmp","mms read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_h_sim1.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_h_sim2.bmp","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Master\\\\mms_messageread_l_sim1.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\message\\\\Slave\\\\mms_messageread_l_sim2.bmp","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_sim1.bmp","mms notification icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_sim2.bmp","mms notification icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_HIGH_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_h_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_HIGH_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_h_sim2.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_LOW_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Master\\\\notification_l_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF_PRIO_LOW_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\notification\\\\Slave\\\\notification_l_sim2.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Master\\\\mms_read_sim1.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Slave\\\\mms_read_sim2.bmp","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Master\\\\mms_read_read_SIM1.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\readreport\\\\Slave\\\\mms_read_read_SIM2.bmp","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Master\\\\mms_delivery_sim1.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Slave\\\\mms_delivery_sim2.bmp","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ_SIM_1,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Master\\\\mms_delivery_read_sim1.bmp","mms delivery report message read icon");
    ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ_SIM_2,CUST_IMG_PATH"\\\\MainLCD\\\\DualSIM\\\\MMS\\\\deliveryreport\\\\Slave\\\\mms_delivery_read_sim2.bmp","mms delivery report message read icon");




    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WAP_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PNG","WAP Menu Item Icon");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_CONNECTED,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\CSD_C_SIM1.pbm","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_CONNECTING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\CSD_SIM1.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_DISCONNECT,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\DualSIM\\\\TB_SV_SIM1.PNG","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_CONNECTED,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\GPRS_C_SIM1.pbm","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_CONNECTING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\GPRS_SIM1.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_DISCONNECT,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\DualSIM\\\\TB_SV_SIM1.PNG","");

    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WAP_LOGO_MASTER_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\DualSIM\\\\TB_SV_SIM1.PNG","WAP Menu Item Icon (Master SIM)");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WAP_LOGO_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\DualSIM\\\\TB_SV_SIM2.PNG","WAP Menu Item Icon (Slave SIM)");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_CONNECTED_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\CSD_C_SIM2.pbm"," for slave SIM");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_CONNECTING_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\CSD_SIM2.gif","for slave SIM");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_DISCONNECT_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\DualSIM\\\\TB_SV_SIM2.PNG","for slave SIM");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_CONNECTED_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\GPRS_C_SIM2.pbm","for slave SIM");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_CONNECTING_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\DualSIM\\\\GPRS_SIM2.gif","for slave SIM");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_DISCONNECT_SLAVE_SIM,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\DualSIM\\\\TB_SV_SIM2.PNG","for slave SIM");

#else /* #ifdef __MMI_DUAL_SIM__ */

    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WAP_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PNG","WAP Menu Item Icon");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_CONNECTED,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\CSD_C.pbm","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_CONNECTING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\CSD.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_CSD_DISCONNECT,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PNG","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_CONNECTED,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\GPRS_C.pbm","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_CONNECTING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\GPRS.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_GPRS_DISCONNECT,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PNG","");

#endif /* #ifdef __MMI_DUAL_SIM__ */


    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WIFI_CONNECTED,CUST_IMG_PATH"\\\\MainLCD\\\\WLAN\\\\Titlebar\\\\TB_disconnect.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WIFI_CONNECTING,CUST_IMG_PATH"\\\\MainLCD\\\\WLAN\\\\Titlebar\\\\TB_busy.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_WIFI_DISCONNECT,CUST_IMG_PATH"\\\\MainLCD\\\\WLAN\\\\Titlebar\\\\TB_disconnect.gif","");
    ADD_APPLICATION_IMAGE2(WAP_IMAGE_SECURITY,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\KEY.pbm","");


	//ADD_APPLICATION_IMAGE2(WAP_IMAGE_BUSY_ANIMATOR,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\busy_icon.gif","wap busy animate image");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_USERNAME,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_NAME.PBM","Image of Username");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_PASSWORD,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_PASS.PBM","Image of Password");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_BOOKMARK,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_BOMK.pbm","wap menu icon bookmark");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_EDIT_ADDRESS,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_ETAD.pbm","wap menu icon edit address");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_DOWNLOAD,CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\DL_AP.pbm","wap menu icon download");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_HOMEPAGE,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_HOME.pbm","wap menu icon homepage");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_RECENT_PAGE,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_RTPAGE.pbm","wap menu icon recent pages");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_OFFLINE_PAGE,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_OFLN.pbm","wap menu icon offline pages");
	ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_SETTING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_SET.pbm","wap menu icon setting");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_PUSH_INBOX,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_INBOX.pbm","wap push inbox icon");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_PUSH_READ,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_READ.pbm","wap push read message icon");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_PUSH_UREAD,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_UNREAD.pbm","wap push unread message icon");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_PUSH_EREAD,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_EREAD.pbm","wap push expired read message icon");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_PUSH_EUREAD,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_EUNREAD.pbm","wap push expired unread message icon");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB1,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB1.pbm","list number icon 1");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB2,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB2.pbm","list number icon 2");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB3,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB3.pbm","list number icon 3");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB4,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB4.pbm","list number icon 4");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB5,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB5.pbm","list number icon 5");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB6,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB6.pbm","list number icon 6");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB7,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB7.pbm","list number icon 7");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB8,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB8.pbm","list number icon 8");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB9,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB9.pbm","list number icon 9");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB10,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB10.pbm","list number icon 10");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB11,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB11.pbm","list number icon 11");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB12,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB12.pbm","list number icon 12");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB13,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB13.pbm","list number icon 13");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB14,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB14.pbm","list number icon 14");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB15,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB15.pbm","list number icon 15");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB16,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB16.pbm","list number icon 16");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB17,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB17.pbm","list number icon 17");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB18,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB18.pbm","list number icon 18");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB19,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB19.pbm","list number icon 19");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB20,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB20.pbm","list number icon 20");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB21,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB21.pbm","list number icon 21");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB22,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB22.pbm","list number icon 22");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB23,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB23.pbm","list number icon 23");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB24,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB24.pbm","list number icon 24");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB25,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB25.pbm","list number icon 25");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB26,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB26.pbm","list number icon 26");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB27,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB27.pbm","list number icon 27");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB28,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB28.pbm","list number icon 28");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB29,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB29.pbm","list number icon 29");
   ADD_APPLICATION_IMAGE2(WAP_IMAGE_SW_LIST_NB30,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Listmenuicon\\\\L_NB30.pbm","list number icon 30");

   ADD_APPLICATION_IMAGE2(BRA_IMG_SPLASH_SCREEN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Progress\\\\BroswerLoading.gif","browser splash screen image");

#ifdef MMS_SUPPORT
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.pbm","mms unread message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_JAVA,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Jsr\\\\mms_messagejsr.pbm","java mms icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_h.pbm","mms high priority unread message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_l.pbm","mms low priority unread message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.pbm","mms read message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_h.pbm","mms high priority read message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_READ_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_l.pbm","mms low priority read message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_LETTER_CREATED,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.pbm","mms draft message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_NOTIF,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.pbm","mms notification icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_RR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read.pbm","mms read report message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_RR_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read_read.pbm","mms read report message read icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_DR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery.pbm","mms delivery report message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_DR_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery_read.pbm","mms delivery report message read icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_BROKEN_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_QUE"__MMI_RES_TYPE_POPUP_SCREEN__,"mms broken image icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_AUDIO,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\audio.pbm","mms audio icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_ATTACHMENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\attachfile.pbm","mms attachment icon in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_FRAME,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS-template.gif","mms image frame in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_PIC_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\pic_icon.pbm","mms image icon in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_EDITOR_VIDEO_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\video_icon.pbm","mms video icon in SMIL editor");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SMIL_SLIDING_BAR_REGION,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\bar.gif","mms sliding bar background icon");

   ADD_APPLICATION_IMAGE2(MEA_IMG_AUDIO_ERROR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Audio_error.gif","Broken audio icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_ERROR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_error.gif","Broken image icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_VIDEO_ERROR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Video_error.gif","Broken video icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_AUDIO_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Audio_lock.gif","Lock audio icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_IMAGE_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_lock.gif","Lock image icon");

#ifdef __MMI_TOUCH_SCREEN__
   ADD_APPLICATION_IMAGE2(MEA_IMG_MOB_UP_ARROW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Touch\\\\th_mob_up.gif","Up arrow in mixed-object message");
   ADD_APPLICATION_IMAGE2(MEA_IMG_MOB_DOWN_ARROW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Touch\\\\th_mob_down.gif","Down arrow in mixed-object message");
#endif /* __MMI_TOUCH_SCREEN__ */
   ADD_APPLICATION_IMAGE2(MEA_IMG_TEMPLATE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\mmstemplate.pbm","mms template message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock.pbm","unread forward-lock mms icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read.pbm","forward-locked mms message icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_h.pbm","unread forward-lock mms icon with high priority");
   ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_l.pbm","unread forward-lock mms icon with high priority");
   ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_HIGH,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_h.pbm","forward-locked mms message icon with low priority");
   ADD_APPLICATION_IMAGE2(MEA_IMG_FORWARD_LOCK_READ_PRIO_LOW,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_l.pbm","forward-locked mms message icon with low priority");
   ADD_APPLICATION_IMAGE2(MEA_IMG_WRITE_MESSAGE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_WRITE.pbm","mms menu icon write message");
   ADD_APPLICATION_IMAGE2(MEA_IMG_INBOX,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_INBOX.pbm","mms menu icon inbox");
   ADD_APPLICATION_IMAGE2(MEA_IMG_OUTBOX,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_UTBOX.pbm","mms menu icon outbox");
   ADD_APPLICATION_IMAGE2(MEA_IMG_DRAFTS,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_drafts.pbm","mms menu icon draft");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_sent.pbm","mms menu icon sent");
   ADD_APPLICATION_IMAGE2(MEA_IMG_TEMPLATES,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_TEMP.pbm","mms menu icon templates");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SETTINGS,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_SET.pbm","mms menu icon settings");

   ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_NORMAL,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MG.png","message title icon");
   ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_BUSY,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\titlebar\\\\MMSC.gif","mms title icon for busy state");
   ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_RING,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\titlebar\\\\MMSR.gif","mms title icon for busy state");
   ADD_APPLICATION_IMAGE2(MEA_IMG_TITLE_ATTACHMENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\titlebar\\\\Attachfile.PBM","mms title icon for attachment");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_FROM,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\from.pbm","mms message editor icon for <from>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_TO,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\to.pbm","mms message editor icon for <to>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_CC,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\cc.pbm","mms message editor icon for <cc>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_BCC,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\bcc.pbm","mms message editor icon for <bcc>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_SUBJECT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\sb.pbm","mms message editor icon for <subject>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_CONTENT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\content.pbm","mms message editor icon for <edit content>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_LAYOUT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\layout.pbm","mms message editor icon for <layout>");
   ADD_APPLICATION_IMAGE2(MEA_IMG_EDITOR_SIZE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\editor\\\\size.pbm","mms message editor icon for <size>");

   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_PERIOD,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_period.pbm","mms setting icon for expired period");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_DR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_deliveryreport.pbm","mms setting icon for delivery report");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_RR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_readreport.pbm","mms setting icon for read report");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_PRIORITY,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_Priority.pbm","mms setting icon for priority");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_SLIDE_DUR,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_stiming.pbm","mms setting icon for slide duration");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SEND_DELIVERY_TIME,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_deliverytime.pbm","mms setting icon for delivery time");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SIG_STATUS,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_sig_status.pbm","mms setting icon for turning on/off auto signature");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SIG_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_sig_image.pbm","mms setting icon for signature image");
   ADD_APPLICATION_IMAGE2(MEA_IMG_SET_SIG_TEXT,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Setting\\\\mms_sig_text.pbm","mms setting icon for signature text");

#ifndef __MMI_MMS_TEMPLATES_NUM__
#define __MMI_MMS_TEMPLATES_NUM__ 5
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>0)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_01,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T01.gif","mms template image 01 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_02,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T02.gif","mms template image 02 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_03,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T03.gif","mms template image 03 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_04,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T04.gif","mms template image 04 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_05,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T05.gif","mms template image 05 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>5)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_06,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T06.gif","mms template image 06 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>6)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_07,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T07.gif","mms template image 07 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>7)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_08,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T08.gif","mms template image 08 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>8)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_09,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T09.gif","mms template image 09 ");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>9)
   ADD_APPLICATION_IMAGE2(MMS_IMG_TEMPLATES_10,CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\template\\\\MMS_T10.gif","mms template image 10 ");
#endif
#endif /* MMS_SUPPORT */

	ADD_APPLICATION_MENUITEM((WAP_MENU_FULLSCREEN_EDITOR_OPTION,0,3,
		WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
		WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
		WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
		SHOW, NONMOVEABLE,
		DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((
				WAP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
				WAP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,WIDGET_STR_ID_DONE,NULL));

	ADD_APPLICATION_MENUITEM((
				WAP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
				WAP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,WIDGET_STR_ID_CANCEL,NULL));

	ADD_APPLICATION_MENUITEM((
				WAP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
				WAP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,WIDGET_STR_ID_INPUT_METHOD,NULL));

	/*MTK:BEGIN:generate_wap_string_resource*/
	ADD_APPLICATION_STRING2(BRA_STR_ID_ACCEPT,"Accept","Accept");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ACCESS_RESTR_WML,"WML access violation","WML access violation");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ACCESS_RESTR_WMLS,"WMLScript access violation","WMLScript access violation");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ACCOUNT,"Data account","Data account");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ACTIVATE_PROFILE,"Activate profile","Activate profile");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ADDRESS,"Address","Address");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ADD_BOOKMARK,"Add bookmark","Add bookmark");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ALWAYS,"Always","Always");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ASK,"Ask","Ask");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BOOKMARKS,"Bookmarks","Bookmarks");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BROWSER_OPTIONS,"Browser options","Browser options");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CACHE,"Cache","Cache");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CACHE_MODE,"Cache mode","Cache mode");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CACHE_SIZE,"Cache size","Cache size");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CERTIFICATES,"Certificates","Certificates");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CHANGE_AUTH_PIN,"Change auth. pin","Change auth. pin");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CHANGE_SIGN_TEXT_PIN,"Change signText pin","Change signText pin");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CLEAR_CACHE,"Clear cache","Clear cache");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CLEAR_CACHE_ASK,"Clear cache?","Clear cache?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CLEAR_COOKIES,"Clear cookies","Clear cookies");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CLEAR_COOKIES_ASK,"Clear cookies?","Clear cookies?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONNECTION,"Connection","Connection");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONNECTION_FAILED,"Connection failed","Connection failed");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONN_LESS,"Connectionless","Connectionless");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONN_ORIENT,"WAP","WAP connection type");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONN_TYPE,"Connection type","Connection type");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONTRACTS,"Contracts","Contracts");
	ADD_APPLICATION_STRING2(BRA_STR_ID_COOKIES,"Cookies","Cookies");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CURENT_CERT,"Current certificate","Current certificate");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DEFAULT_PROFILE_NAME,"Profile","Profile");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE,"Delete","Delete");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE_ASK,"Delete?","Delete?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETED,"Deleted","Deleted");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE_ALL,"Delete all","Delete all");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE_ALL_ASK,"Delete all?","Delete all?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE_ALL_INBOX,"Delete all inbox","Delete all inbox?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE_BOOKMARK,"Delete bookmark?","Delete bookmark?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EDIT,"Edit","Edit");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EDIT_BOOKMARK,"Edit bookmark","Edit bookmark");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EDIT_HOMEPAGE,"Edit homepage","Edit homepage");
	ADD_APPLICATION_STRING2(BRA_STR_ID_VIEW_URL,"View URL","View URL");
	ADD_APPLICATION_STRING2(BRA_STR_ID_VIEW_CURRENT_URL,"View URL","View URL");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EDIT_PROFILE,"Edit profile","Edit profile");
	ADD_APPLICATION_STRING2(BRA_STR_ID_VIEW_PROFILE,"View profile","View profile");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ENABLE_COOKIES,"Enable cookies","Enable cookies");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ENTER_ADDRESS,"Enter address","Enter address");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERROR_COMMUNICATION,"Error in communication","Error in communication");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_BKM_FULL,"Bookmarks list is full","Bookmarks list is full");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_INVALID_IP,"Invalid IP address","Invalid IP address");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_TRUSTLIST_FULL,"Trust list is full","Trust list is full");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_SELECT_PROFILE,"Please select a profile first","Please select a profile first");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_TITLE_URL_INVALID,"Invalid title or URL","Invalid title or URL");
    ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_TITLE_URL_TOOLONG,"Title or URL too long","Title or URL too long");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_UNDEFINED_ERROR,"Unspecified error","Unspecified error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EXIT,"Exit","Exit");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EXPIRES,"Expires:","Expires:");
	ADD_APPLICATION_STRING2(BRA_STR_ID_FROM,"From:","From:");
	ADD_APPLICATION_STRING2(BRA_STR_ID_GATEWAY,"IP address","IP address");
	ADD_APPLICATION_STRING2(BRA_STR_ID_GOTO,"Goto","Goto");
	ADD_APPLICATION_STRING2(BRA_STR_ID_HOMEPAGE,"Homepage","Homepage");
	ADD_APPLICATION_STRING2(BRA_STR_ID_HOST_NOT_FOUND,"Unknown host","Unknown host");
	ADD_APPLICATION_STRING2(BRA_STR_ID_HTTP,"HTTP","HTTP");
	ADD_APPLICATION_STRING2(BRA_STR_ID_HTTP_URL,"http://","http://");
	ADD_APPLICATION_STRING2(BRA_STR_ID_IF_SAME_HOST,"If on same host","If on same host");
	ADD_APPLICATION_STRING2(BRA_STR_ID_IMAGE_OPT,"Show images","Show images");
	ADD_APPLICATION_STRING2(BRA_STR_ID_INTERNAL_ERROR,"Internal error","Internal error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_INVALID_INPUT,"Invalid input","Invalid input");
	ADD_APPLICATION_STRING2(BRA_STR_ID_INVALID_URL,"Invalid URL","Invalid URL");
	ADD_APPLICATION_STRING2(BRA_STR_ID_LOADING_DOC,"Loading document","Loading document");
	ADD_APPLICATION_STRING2(BRA_STR_ID_LOADING_OBJ,"Loading objects","Loading objects");
	ADD_APPLICATION_STRING2(BRA_STR_ID_MANAGE_BKM,"Manage bookmarks","Manage bookmarks");
	ADD_APPLICATION_STRING2(BRA_STR_ID_MESSAGE,"Message:","Message:");
	ADD_APPLICATION_STRING2(BRA_STR_ID_MESSAGE_FORTITLE,"Message","Message");
	ADD_APPLICATION_STRING2(BRA_STR_ID_NEVER,"Never","Never");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DISABLE,"Disable","Disable");
	ADD_APPLICATION_STRING2(BRA_STR_ID_WITHOUT_CONFIRM,"Without confirm","Without confirm");
	ADD_APPLICATION_STRING2(BRA_STR_ID_CONFIRM,"Confirm","Confirm");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ADD_NEW,"Add new","Add new");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PHONE_NO,"number","number");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DOMAIN_NAME,"Domain name","Domain name");
	ADD_APPLICATION_STRING2(BRA_STR_ID_NEW_PUSH_MSG,"New service message","New service message");
	ADD_APPLICATION_STRING2(BRA_STR_ID_NO_HISTORY,"No history available","No history available");
	ADD_APPLICATION_STRING2(BRA_STR_ID_OFF,"Off","Off");
	ADD_APPLICATION_STRING2(BRA_STR_ID_OK,"OK","OK");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ON,"On","On");
	ADD_APPLICATION_STRING2(BRA_STR_ID_OPTIONS,"Options","Options");
	ADD_APPLICATION_STRING2(BRA_STR_ID_OUT_OF_MEMORY,"not enough memory","not enough memory");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PARSER_ERROR,"Parser error","Parser error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_INSTAL,"Install setting?","Install setting?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_WAP_INSTAL,"Install WAP setting?","Install WAP setting?");
    ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_MMS_INSTAL,"Install MMS setting?","Install MMS setting?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PRX_ADDR,"Proxy address","Proxy address");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PRX_PORT,"Proxy port","Proxy port");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PRX_PWD,"Password","Password");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PRX_UID,"Username","Username");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_INBOX,"Service inbox","Service inbox");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_UM_INBOX,"Inbox","Inbox");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_LOAD_ALWAYS,"Accept always","Accept always");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_LOAD_AUTH,"Accept authenticated or trusted","Accept authenticated or trusted");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_LOAD_NEVER,"Never accept","Never accept");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_LOAD_NON_WAP,"Accept non WAP push","Accept non WAP push");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_LOAD_SL,"Load push SL messages","Load push SL messages");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_SECURITY,"Push security","Push security");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_SETTINGS,"Service message settings","Service message settings");
	ADD_APPLICATION_STRING2(BRA_STR_ID_PUSH_SL_SETTINGS,"Push SL settings","Push SL settings");
	ADD_APPLICATION_STRING2(BRA_STR_ID_RECENT_PAGES,"Recent pages","Recent pages");
	ADD_APPLICATION_STRING2(BRA_STR_ID_REFRESH,"Refresh","Refresh");
	ADD_APPLICATION_STRING2(BRA_STR_ID_RENAME,"Rename profile","Rename profile");
	ADD_APPLICATION_STRING2(BRA_STR_ID_REQUEST_TIMED_OUT,"Request timed out","Request timed out");
	ADD_APPLICATION_STRING2(BRA_STR_ID_REQUIRE_FRAMES,"This page requrie frame support","This page requrie frame support");
	ADD_APPLICATION_STRING2(BRA_STR_ID_RESEND_POST_WARNING,"Please use refresh","Please use refresh");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SAVE_AS_HOMEP,"Set as homepage","Set as homepage");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SCHEME_NOT_SUPPORTED,"Unsupported scheme","Unsupported scheme");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SECURITY,"Security","Security");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SECURITY_INFO,"Security info","Security info");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SEC_CLEAR_SESSION,"Clear session","Clear session");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SEC_CONNECTION_FAILED,"Secure connection failed","Secure connection failed");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_BOOKMARK,"Select bookmark","Select bookmark");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_PROFILE,"Select profile","Select profile");
    ADD_APPLICATION_STRING2(BRA_STR_ID_SEND,"Send","Send");
    ADD_APPLICATION_STRING2(BRA_STR_ID_VIA_SMS,"via SMS","via SMS");
    ADD_APPLICATION_STRING2(BRA_STR_ID_VIA_MMS,"via MMS","via MMS");
    ADD_APPLICATION_STRING2(BRA_STR_ID_VIA_EMAIL,"via Email","via Email");
    ADD_APPLICATION_STRING2(BRA_STR_ID_USB_MODE_EXP_WARNING,"USB: Function not allowed","USB: Function not allowed");
    ADD_APPLICATION_STRING2(BRA_STR_ID_NO_SIMCARD_WARNING,"No SIM: Function not allowed","No SIM: Function not allowed");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SESSION_INFO,"Session info","Session info");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SETTINGS,"Settings","Settings");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_DEF_NET_ID,"Account","Account");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_NET_ID,"Data account","Data account");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_NO_NET_IDS,"No data accounts","No data accounts");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_ENABLE_PUSH,"Enable push","Enable push");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_PUSH_TRUSTSETTING,"Trust setting","Trust setting");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_PUSH_SLSETTING,"SL setting","SL setting");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_PUSH_TRUSTLIST,"Trust list","Trust list");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SET_PUSH_ADDTO_TRUSTLIST,"Add to trust list","Add to trust list");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SOUND_OPT,"Play sounds","Play sounds");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_INVALID_PHONENO,"Invalid number","Invalid number");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_INVALID_DOMAINNAME,"Invalid domain name","Invalid domain name");
	ADD_APPLICATION_STRING2(BRA_STR_ID_START_TITLE,"Internet services","Internet services");
	ADD_APPLICATION_STRING2(BRA_STR_ID_TIMEOUT,"Timeout","Timeout");
	ADD_APPLICATION_STRING2(BRA_STR_ID_TITLE,"Title","Title");
	ADD_APPLICATION_STRING2(BRA_STR_ID_UNKNOWN_CHARSET,"Unknown charset","Unknown charset");
	ADD_APPLICATION_STRING2(BRA_STR_ID_URL,"URL:","URL:");
	ADD_APPLICATION_STRING2(BRA_STR_ID_WMLS_ERROR,"WMLScript error","WMLScript error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EMPTY,"Empty","Empty");
	ADD_APPLICATION_STRING2(BRA_STR_ID_READ,"Read","Read");
	ADD_APPLICATION_STRING2(BRA_STR_ID_EMPTY_LIST,"<Empty>","<Empty>");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SAVE_AS_FAIL, "Download failed", "Download failed");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DELETE_SUCCESS, "Delete successfully", "Delete successfully");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SAS_OPERATION_CANCELED, "Operation cancelled", "Operation cancelled");
	ADD_APPLICATION_STRING2(BRA_STR_ID_YES, "Yes", "Yes");
	ADD_APPLICATION_STRING2(BRA_STR_ID_NO, "No", "No");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SAME_ITEM_EXIT, "The same item exist", "The same item exist");
	ADD_APPLICATION_STRING2(BRA_STR_ID_INVALID_GATEWAY_IP, "Invalid gateway IP", "Invalid gateway IP");
	ADD_APPLICATION_STRING2(BRA_STR_ID_TRUSTED_CERTIFICATES, "Trusted certificates", "Trusted certificates");
	ADD_APPLICATION_STRING2(BRA_STR_ID_LONG_IDLE_DISCONNECT, "Disconnect for long idle", "Disconnect for long idle");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BEARER_GSM_CSD, "GSM data", "GSM data");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BEARER_GPRS, "GPRS", "GPRS");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BEARER_WIFI, "Wireless LAN", "Wireless LAN");
	ADD_APPLICATION_STRING2(BRA_STR_ID_BEARER_GPRS_GSM_DUAL, "GPRS/GSM", "GPRS/GSM");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_GPRS, "GPRS account selection", "GPRS account selection");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_GSM_CSD, "GSM data account selection", "GSM data account selection");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SWITCH_GSM_CSD, "Connection failed,retry with GSM dialup?", "Connection failed,retry with GSM dialup?");
    ADD_APPLICATION_STRING2(BRA_STR_ID_SWITCH_GSM_GPRS_LOAD, "GPRS detected,retry with GPRS?", "GPRS detected,retry with GPRS?");
    ADD_APPLICATION_STRING2(BRA_STR_ID_SWITCH_GSM_GPRS_IDLE, "GPRS detected,switch to GPRS?", "GPRS detected,switch to GPRS?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SAVING, "Saving", "Saving");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SAVE, "Save", "Save");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SAVE_ASK, "Save?", "Save?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SAVED, "Saved", "Saved");
   ADD_APPLICATION_STRING2(BRA_STR_ID_DIAL, "Dial", "Dial");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SEND_DTMF, "Send DTMF", "Send DTMF");
   ADD_APPLICATION_STRING2(BRA_STR_ID_ADD, "Add", "Add");
   ADD_APPLICATION_STRING2(BRA_STR_ID_DRM_RO_RECEIVED, "DRM rights received", "DRM rights received");
   ADD_APPLICATION_STRING2(BRA_STR_ID_OFFLINE_PAGES, "Offline pages", "Offline pages");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SAVE_OFFLINE_PAGE, "Save as offline page", "Save as offline page");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SAVE_OFFLINE_PAGE_FAIL, "Save offline page failed", "Save offline page failed");
   ADD_APPLICATION_STRING2(BRA_STR_ID_UPDATE_OFFLINE_PAGE, "Offline page exist, update?", "Offline page exist, update?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_OFFLINE_PAGE_FULL, "Offline page full", "Offline page full");
   ADD_APPLICATION_STRING2(BRA_STR_ID_OFFLINE_PAGE_NOTFOUND, "Something is wrong with this page", "Something is wrong with this page");
   ADD_APPLICATION_STRING2(BRA_STR_ID_ERR_PHONEBOOK_FULL, "Phone storage full", "Phone storage full");
   ADD_APPLICATION_STRING2(BRA_STR_ID_20_SECS, "20 secs", "20 secs");
   ADD_APPLICATION_STRING2(BRA_STR_ID_30_SECS, "30 secs", "30 secs");
   ADD_APPLICATION_STRING2(BRA_STR_ID_60_SECS, "60 secs", "60 secs");
   ADD_APPLICATION_STRING2(BRA_STR_ID_2_MINS, "2 mins", "2 mins");
   ADD_APPLICATION_STRING2(BRA_STR_ID_DELETING, "Deleting", "Deleting");
   ADD_APPLICATION_STRING2(BRA_STR_ID_NEED_ACTIVE_VOICE_CALL, "Need an active voice call", "Need an active voice call");
   ADD_APPLICATION_STRING2(BRA_STR_ID_ENTER_SELECT_MODE, "Save image", "Enter select mode");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_PICTURE, "Select picture", "Select picture to save");
   ADD_APPLICATION_STRING2(BRA_STR_ID_ENTERING_SELECT_MODE, "Entering picture select mode", "Entering picture select mode");
   ADD_APPLICATION_STRING2(BRA_STR_ID_INVALID_PROV, "Invalid setting content", "Invalid setting content");
   ADD_APPLICATION_STRING2(BRA_STR_ID_UNSUPPORT_PROV, "Unsupported setting content", "Unsupported setting content");
   ADD_APPLICATION_STRING2(BRA_STR_ID_INVALID_DRM_RO_FORMAT, "Invalid rights", "Invalid right");
   ADD_APPLICATION_STRING2(BRA_STR_ID_DRM_RO_EXISTS, "Rights exists", "Rights exists");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_BOOKMARK_INSTAL, "Install bookmark?", "Install bookmark?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_CONTENT_TOO_LARGE, "Requested entity too large", "Requested entity too large");
   ADD_APPLICATION_STRING2(BRA_STR_ID_RESET, "Reset", "Reset");
   ADD_APPLICATION_STRING2(BRA_STR_ID_CHOOSE, "Choose", "Choose");
   ADD_APPLICATION_STRING2(BRA_STR_ID_NOCERT, "Could not show certificate", "Could not show certificate");
   ADD_APPLICATION_STRING2(BRA_STR_ID_LOAD_SCHEME_SMS_CONF, "Send SMS to ", "Send SMS to ");
   ADD_APPLICATION_STRING2(BRA_STR_ID_LOAD_SCHEME_EGE_CONF, "Activate JAVA and terminate browser?", "Activate JAVA and terminate browser?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_LOAD_SCHEME_RTSP_CONF, "Activate streaming and terminate browser?", "Activate streaming and terminate browser?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_LOAD_SCHEME_MMS_CONF, "Send MMS to ", "Send MMS to ");
   ADD_APPLICATION_STRING2(BRA_STR_ID_CANCEL_PROV, "Cancel?", "Cancel?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_LOAD_EXPIRED_MSG_CONF, "Load expired message?", "Load expired message?");
#ifdef __MMI_PUSH_ACCEPT_CONFIRM__
   ADD_APPLICATION_STRING2(BRA_STR_ID_ACCEPT_URL_CONF,       "Connect to this URL?",  "Connect to this URL?");
#endif  
   ADD_APPLICATION_STRING2(BRA_STR_ID_ACTIVATED, "Activated", "Activated");

   ADD_APPLICATION_STRING2(BRA_STR_ID_AUTHENTICATION, "Authentication", "Authentication"); 

   /*#ifdef BRA_CFG_CCA*/
   ADD_APPLICATION_STRING2(BRA_STR_ID_BROWSER, "Browser", "Browser application name");
   ADD_APPLICATION_STRING2(BRA_STR_ID_MMS, "MMS", "MMS application name");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PROFILE, "Profile", "Profile");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PROFILE_NAME, "Profile name", "Profile name");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SKIP, "Skip", "Skip");
   ADD_APPLICATION_STRING2(BRA_STR_ID_INSTALL, "Install", "Install");
   ADD_APPLICATION_STRING2(BRA_STR_ID_INSTALL_SETTING, "Install setting", "Install setting");
   ADD_APPLICATION_STRING2(BRA_STR_ID_REPLACE_SETTING, "Replace setting", "Replace setting");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SKIP_PROFILE, "Skip this profile?", "Skip this profile?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PROFILE_IN_USE, "Profile in use", "Profile in use");
   /*#endif BRA_CFG_CCA*/


   /* BRA_CFG_DUAL_SIM */
   ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_SIM, "Select SIM", "Select SIM");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM1, "SIM1", "SIM1");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM2, "SIM2", "SIM2");
   ADD_APPLICATION_STRING2(BRA_STR_ID_ALWAYS_ASK, "Always ask", "Always ask");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SELECT_CALL, "Call", "Call");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM1_CALL, "SIM1 voice call", "SIM1 voice call");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM2_CALL, "SIM2 voice call", "SIM2 voice call");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM1_NOT_EXIST, "SIM1 not available", "SIM1 not available");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM2_NOT_EXIST, "SIM2 not available", "SIM2 not available");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM1_NOT_OPEN, "SIM1 not open", "SIM1 not open");
   ADD_APPLICATION_STRING2(BRA_STR_ID_SIM2_NOT_OPEN, "SIM2 not open", "SIM2 not open");
   ADD_APPLICATION_STRING2(BRA_STR_ID_NO_SIM_IS_AVAILABLE, "No SIM is available", "No SIM is available");
   ADD_APPLICATION_STRING2(BRA_STR_ID_BEARER_DETAIL_INFO, "Connection information", "Connection information");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_SIM1_INSTALL, "Install SIM1 setting?", "Install SIM1 setting?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_SIM2_INSTALL, "Install SIM2 setting?", "Install SIM2 setting?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_SIM1_WAP_INSTALL, "Install SIM1 WAP setting?", "Install SIM1 WAP setting?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_SIM2_WAP_INSTALL, "Install SIM2 WAP setting?", "Install SIM2 WAP setting?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_SIM1_MMS_INSTALL, "Install SIM1 MMS setting?", "Install SIM1 MMS setting?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_PRS_SIM2_MMS_INSTALL, "Install SIM2 MMS setting?", "Install SIM2 MMS setting?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_CALL_CONFLICT, "Unable to Connect", "Unable to Connect");
   /* BRA_CFG_DUAL_SIM */
   ADD_APPLICATION_STRING2(BRA_STR_ID_SUBMIT_ASK, "Submit?", "Submit?");
   ADD_APPLICATION_STRING2(BRA_STR_ID_QUESTION_MARK, "?", "?");





	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(BRS_STR_ID_BUTTON,"Button","Button");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_IMODE_DLG_CANCEL_MSG,"No","No");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_IMODE_DLG_OK_MSG,"Yes","Yes");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_IMODE_DLG_USER_MSG,"Send mobile phone info?","Send mobile phone info?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_INPUT_FORMAT_USER_MSG,"At least one field is malformed.","At least one field is malformed.");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_INPUT_FORMAT_USER_MSG_INPUT_REQ,"The field cannot be empty.","The field cannot be empty.");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_INPUT_FORMAT_USER_MSG_LAST_CHAR,"The last character was not allowed.","The last character was not allowed.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(BRS_STR_ID_REDIRECT_POST,"Redirected request received. Resubmit user data ?","Redirected request received. Resubmit user data ?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESEND_POST,"Do you want to resubmit user data ?","Do you want to resubmit user data ?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESET,"Reset","Reset");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUBMIT,"Submit","Submit");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DEFAULT_SCRPT_WRN_MSG,"Unsupport scripts in content.","Unsupport scripts in content.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG,"Do you wish to load this object ?","Do you wish to load this object?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_ERROR_COMMUNICATION,"Error in Communication","Error in Communication");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_2,"], with URL = [","], with URL = [");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_3,"] ?","] ?");
//	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_4,"Unknown","Unknown");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ENABLE_COOKIES_CONF,"Enable cookies?","Enable cookies?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DISABLE_COOKIES_CONF,"Disable cookies?","Disable cookies?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ENABLE_CACHE_CONF,"Enable cache?","Enable cache?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DISABLE_CACHE_CONF,"Disable cache?","Disable cache?");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERROR_GPRS_UNKNOWN_APN,"APN error","APN error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERROR_GPRS_AUTHENTICATION_FAILURE,"GPRS authentication error","GPRS authentication error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERROR_GPRS_UNSUPPORTED_SERVICE_OPTION,"GPRS not support","GPRS not support");
	ADD_APPLICATION_STRING2(BRA_STR_ID_ERROR_GPRS_UNSUBSCRIBED_SERVICE_OPTION,"GPRS not subscribed","GPRS not subscribed");
    ADD_APPLICATION_STRING2(BRA_STR_ID_ERROR_CSD_AUTH_FAIL,"CSD authentication error","CSD authentication error");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_ACCEPT,"Accept","Accept");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_DELETE,"Delete","Delete");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_HELP,"Help","Help");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_OPTIONS,"Options","Options");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_PREV,"Previous","Previous");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_RESET,"Reset","Reset");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DO_TYPE_UNKNOWN,"Unknown","Unknown");
	ADD_APPLICATION_STRING2(BRA_STR_ID_MSG_DELETED,"Message has been deleted","Message has been deleted");
	ADD_APPLICATION_STRING2(BRA_STR_ID_MSG_REPLACED,"Message has been replaced","Message has been replaced");
	ADD_APPLICATION_STRING2(BRA_STR_ID_DOWNLOAD,"Download list","Download list");
	ADD_APPLICATION_STRING2(BRA_STR_ID_SUSPEND_DOWNLOAD,"Still downloading. Suspend?","Still downloading. Suspend?");
    ADD_APPLICATION_STRING2(BRA_STR_ID_AUTH_FAILED,"Authentication failed","Authentication failed");
	//////////////////////////////////////////////////////
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(MEA_STR_ID_SIM_1,"SIM 1","SIM 1");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SIM_2,"SIM 2","SIM 2");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CHOOSE_SIM,"Please choose a SIM card","Please choose a SIM card");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FORWARD_WITH_EDIT_CONTENT,"Do you want to edit content?","Do you want to edit content?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SERVER_TIMEOUT,"Server Timeout","Server Timeout");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOT_AVAILABLE,"Not Available","Not Available");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MAX_TEXT_LEN_REACHED,"Max text length reached!","Max text length reached!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_INVALID_OBJECT,"Invalid Object Remove.","Invalid Object Remove.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADDRESS_FIELD_MISSING,"At least one address field must be filled in.","At least one address field must be filled in.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_EMAIL,"Add E-mail","Add E-mail");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_IMAGE,"Add Image","Add Image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_MEDIA_OBJECT,"Add media object","Add media object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_NUMBER,"Add Number","Add Number");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_RECIPIENT,"Add Recipient","Add Recipient");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_RECIPIENT_QUEST,"Add recipient?","Add recipient?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_OF_RECIPIENTS,"recipients","recipients");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_FORWARD,"The message is forward prohibited","The message is forward prohibited");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_FORWARD_LOCK,"The message is edit prohibited","The message is edit prohibited");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_TEXT,"Add text","Add text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_BOOKMARK_TEXT,"Add Bookmark Text","Add Bookmark Text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONTENT_TRUNCATED,"Content too long. Truncate it","Content too long. Truncate it");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ALLOW,"Allow","Allow");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACH_ERROR,"Unable to show attachment!","Unable to show attachment!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACH_TITLE,"Attachment","Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BYTES_RECEIVED," bytes received."," bytes received.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BYTES_SENT," bytes sent."," bytes sent.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CC,"Cc: ","Cc: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CLOSE_MEA,"Do you want to close the Messenger Application?","Do you want to close the Messenger Application?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG,"Settings","Settings");
    ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_6_HOURS,"6 Hours","6 Hours");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_12_HOURS,"12 Hours","12 Hours");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_DAY,"1 Day","1 Day");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_HOUR,"1 Hour","1 Hour");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_WEEK,"1 Week","1 Week");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ADVERT,"Advertisement","Advertisement");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ANONYM,"Anonymous senders","Anonymous senders");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETRIEVAL,"Retrieval","Retrieval");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_AUTO,"AUTO messages","AUTO messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_DR,"Delivery report","Delivery report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNSUPPORTED_HEADER_FIELDS,"Failed to open the originating message since it contains unsupported header fields!","Failed to open the originating message since it contains unsupported header fields!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_HIGH,"High","High");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IM_SERVER,"Immediate server","Immediate server");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IM_SIZE,"Immediate limit","Immediate limit");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_INFO,"INFORMATIONAL messages","INFORMATIONAL messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_LOW,"Low","Low");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MAX,"Max","Max");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MMSC,"MMSC","MMSC");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_FILTERS,"Filter","Filter");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETRIEVAL,"Retrieve","Retrieve");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_NETWORK,"Network","Network");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_NORMAL,"Normal","Normal");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_PERS,"PERSONAL messages","PERSONAL messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_PRIORITY,"Priority","Priority");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_RR,"Read report","Read report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SENDING,"Send","Send");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SOS,"Auto save","Auto save");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_TREAT_AS_DEL,"Treat as delayed","Treat as delayed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_USER_STRING,"STRING messages","STRING messages");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_VAL_PER,"Validity period","Validity period");
#endif /* MMS_SUPPORT */
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONNECTING,"connecting.","connecting.");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE,"Connection type","Connection type");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE_HTTP,"HTTP","HTTP");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE_WSP_CL,"WSP CL","WSP CL");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONN_TYPE_WSP_CO,"WSP CO","WSP CO");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DATE,"Date:","Date:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DEFERRED,"Deferred.","Deferred.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE,"Delete","Delete");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL,"Delete All","Delete All");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_MSG_QUEST,"Do you want to delete the message?","Do you want to delete the message?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_MSG_QUEST,"Delete?","Delete?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_SLIDE,"Delete Slide","Delete Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELIV_REPORT,"Delivery report","Delivery report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DEL_RETRIEVAL,"Delayed","Delayed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DIAL,"Dial","Dial");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DONE,"Done","Done");
#endif /* MMS_SUPPORT */
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD,"Download","Download");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_SIZE,"Download size","Download size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOTIFICATION_SIZE,"File size","File size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_COMM_UNAVAILABLE,"The server is temporarily unavailable.","The server is temporarily unavailable.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOADING_MM,"Downloading message.","Downloading message.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_FAILED,"Message download failed!","Message download failed!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_FAILED_ILLEGAL_PDU,"Invalid download data","Invalid download data");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_REQ1,"Download a ","Download a ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_REQ2,"K MMS","K MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DRAFTS,"Draft","Draft");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DURATION,"Slide Timing","Slide Timing");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT,"Edit","Edit");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_AUDIO,"Edit Audio","Edit Audio");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_CONTENT,"Edit Content","Edit Content");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_FAILED_RESOURCES_EXHAUSTED,"Message creation failed. System resources exhausted!","Message creation failed. System resources exhausted!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_IMAGE,"Edit Image","Edit Image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_MESSAGE,"Edit Message","Edit Message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_TEXT,"Edit text","Edit text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY,"Empty","Empty");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_LIST,"<Empty>","<Empty>");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY199,"","");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY212,"","");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY213,"","");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY214,"","");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING,"","");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING023," "," ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING024," "," ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING025," "," ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EMPTY_STRING034," "," ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ERROR,"Error","Error");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EXIT,"Exit","Exit");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EXPIRED,"Expired.","Expired.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_DISPLAY_JSR_MMS,"Read only by JAVA","Read only by JAVA");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_DISPLAY_MM,"Failed to display the message!","Failed to display the message!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_DISPLAY_NOTIF,"Erroneous notification!","Erroneous notification!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_EDIT,"Failed to edit the message","Failed to edit the message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_REPLY,"Failed to reply the message","Failed to reply the message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_READ_MO,"Failed to add media object","Failed to add media object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_ADD_EMPTY_OBJECT, "Failed to add empty file","Failed to add empty file");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_LARGE_RESOLUTION, "Image larger than supported","Image larger than supported");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_FILE_CORRUPT, "File may be corrupted","File may be corrupted");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SAVE,"Failed to save message!","Failed to save message!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_CONNECTION,"Connection error. Save to Outbox","Connection error. Save to Outbox");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_FORWARD,"Failed to forward message","Failed to forward message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SEND,"Failed to send message!","Failed to send message!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SEND_RR,"The read report could not be sent!","The read report could not be sent!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FORWARD,"Forward","Forward");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FORWARDED,"Forwarded.","Forwarded.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FROM,"From: ","From: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_GENERATING_MESSAGE,"Generating message.","Generating message.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_HTTP_PORT,"HTTP port","HTTP port");
	ADD_APPLICATION_STRING2(MEA_STR_ID_IM_RETRIEVAL,"Immediate","Immediate");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INBOX,"Inbox","Inbox");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INDETERMINATE,"Indeterminate.","Indeterminate.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INSERT_SLIDE,"Insert New Slide","Insert New Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_SLIDE_BEFORE,"Add Slide Before","Add Slide Before");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_SLIDE_AFTER,"Add Slide After","Add Slide After");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INTERVAL_INFIX," and "," and ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INTERVAL_PREFIX,"Input value between ","Input value between ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_ADDRESS,"Invalid from address!","Invalid from address!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_MESSAGE,"Message is invalid!","Message is invalid!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_MMS_VERSION,"The configuration is not valid. Please check the MMSC version number.","The configuration is not valid. Please check the MMSC version number.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_PROXY_HOST,"Invalid proxy address!","Invalid proxy address!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_PROXY_PORT,"Invalid proxy port!","Invalid proxy port!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_PROXY_SCHEME,"Invalid proxy scheme!","Invalid proxy scheme!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_RECIP_ADDRESS,"Invalid recipient address!","Invalid recipient address!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_VALUE,"Invalid input value!","Invalid input value!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_WAP_GATEWAY,"Invalid WAP gateway!","Invalid WAP gateway!");
    ADD_APPLICATION_STRING2(MEA_STR_ID_UNAUTHORIZED_ACCESS,"Unauthorized access","Unauthorized access");
	ADD_APPLICATION_STRING2(MEA_STR_ID_KB,"kB","kB");
	ADD_APPLICATION_STRING2(MEA_STR_ID_LOGIN,"Login","Login");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MAX_RETR_SIZE,"Max retrieval size","Max retrieval size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MENU,"menu","menu");
	//ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SENT,"Message was sent successfully.","Message was sent successfully.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SENT,"Sent","Sent");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSENGER_APP,"Messenger application","Messenger application");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ME_INVALID_CONFIG,"The configuration is not valid. Please check \"From\" address and the MMSC version number.","The configuration is not valid. Please check \"From\" address and the MMSC version number.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ME_TITLE,"Message editor","Message editor");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MMS,"MMS","MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NETWORK_ACCOUNT,"Network account","Network account");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEW_MMS_MSG,"New MMS Message","New MMS Message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEW_MSG_FROM_TEMPL,"Create message from template","Create message from template");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEW_SMIL,"New multimedia message","New multimedia message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEXT_SLIDE,"Next Slide","Next Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO,"No","No");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOT_ENOUGH_MEM,"Not enough memory to complete this operation!","Not enough memory to complete this operation!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NOT_READ,"Deleted, not read.","Deleted, not read.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_OF_RECIPIENTS," recipients."," recipients.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_PERSISTENT_STORAGE,"Not enough message storage. Delete messages to free storage space.","Not enough message storage. Delete messages to free storage space.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OFF,"Off","Off");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ON,"On","On");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OPTIONS,"Options","Options");
	ADD_APPLICATION_STRING2(MEA_STR_ID_OUTBOX,"Outbox","Outbox");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PANIC,"Internal error. The application is going to close.","Internal error. The application is going to close.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PASSWD,"Password","Password");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PHONE_BOOK,"Phone book","Phone book");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PREVIEW_SMIL,"Preview multimedia message","Preview multimedia message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PREVIOUS_SLIDE,"Previous Slide","Previous Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PROPERTIES,"Properties","Properties");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READ,"Read.","Read.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READING_MSG,"Reading message.....","Reading message.....");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READ_REPORT,"Read report","Read report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_READ_REPORT_SEND,"A read report has been requested for this message. Do you want to send a read report?","A read report has been requested for this message. Do you want to send a read report?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REALM,"Realm","Realm");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RECIPIENTS,"Recipients:","Recipients:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REJECT,"Reject","Reject");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REJECTED,"Rejected.","Rejected.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_AUDIO,"Remove Audio","Remove Audio");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_IMAGE,"Remove Image","Remove Image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_TEXT,"Remove Text","Remove Text");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_VIDEO, "Add Video", "Add Video");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_VIDEO, "Edit Video", "Edit Video");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_VIDEO, "Remove Video", "Remove Video");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REM_MEDIA_OBJ,"Remove current media object","Remove current media object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY,"Reply","Reply");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_SMS,"Reply by SMS","Reply by SMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_TO_ALL,"Reply All","Reply All");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RETRIEVED,"Retrieved.","Retrieved.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RETR_SIZE_EXCEEDED,"A too large message was blocked","A too large message was blocked");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE,"Save","Save");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_AND_SEND,"Save and Send","Save and Send");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_AS_TEMPLATE,"Save as template","Save as template");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_TO_PHONE_BOOK,"Save To Phone Book","Save To Phone Book");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEC_PORT,"Secure port","Secure port");
#endif /* MMS_SUPPORT */
	ADD_APPLICATION_STRING2(MEA_STR_ID_SELECT,"Select","Select");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEND,"Send","Send");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SENDING_MSG,"Sending MMS","Sending MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEND_OPTIONS,"Send Options","Send Options");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SEND_ONLY,"Send Only","Send Only");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SENT,"Sent","Sent");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SLIDE_LIMIT_REACHED,"Maximum number of slides reached!","Maximum number of slides reached!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_STATUS,"Status:","Status:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SUBJECT,"Subject: ","Subject: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEMPLATES,"Template","Template");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TO,"To:","To:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TO_MANY_RECIPIENTS,"To many recipients.","To many recipients.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNKOWN,"Unknown.","Unknown.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNRECOGNIZED,"Unrecognized.","Unrecognized.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_USE_DETAILS,"Use Details","Use Details");
	ADD_APPLICATION_STRING2(MEA_STR_ID_VIEW,"View","View");
	ADD_APPLICATION_STRING2(MEA_STR_ID_VIEW_ATTACHMENTS,"View attachments","View attachments");
	ADD_APPLICATION_STRING2(MEA_STR_ID_VIEW_TITLE,"View message","View message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WAP_GATEWAY,"WAP gateway","WAP gateway");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRITE_MESSAGE,"Write Message","Write Message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRITE_MMS,"Write MMS","Write MMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRITE_SMS,"Write SMS","Write SMS");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WRONG_MESSAGE_TYPE,"Unsupported message type!","Unsupported message type!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_YES,"Yes","Yes");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RE,"RE: ","RE: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FW,"FW: ","FW: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED,"Maximum message size reached","Maximum message size reached");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_SIZE_WARNING,"Recipient may not be able to view large MMS","Recipient may not be able to view large MMS");
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
    ADD_APPLICATION_STRING2(MEA_STR_ID_MSGSIZE_PROMPT_1, "The size of MMS is", "The size of MMS is");
    ADD_APPLICATION_STRING2(MEA_STR_ID_MSGSIZE_PROMPT_2, "KB, send it?", "KB, send it?");
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
	ADD_APPLICATION_STRING2(MEA_STR_ID_DOWNLOAD_EXPIRED_MM_CONFIRM,"The MM is expired. Download it?","The MM is expired. Download it?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_CHARGING,"Reply charging","Reply charging");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_CHARGING_DEADLINE,"Reply charging deadline","Reply charging deadline");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REPLY_CHARGING_SIZE,"Reply charging size","Reply charging size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEXT_ONLY,"Text only","Text only");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_1_KB,"1 KB","1 KB");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_10_KB,"10 KB","10 KB");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SELECT_COLOR,"Select color","Select color");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BG_COLOR,"Background color","Background color");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETR_HOME_MODE,"Home network","Home network");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_MSG_RETR_ROAM_MODE,"Roaming network","Roaming network");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_RETRIEVAL_ROAM,"Automatic","Automatic");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ASK_RETRIEVAL_ROAM,"Ask","Ask");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RES_RETRIEVAL_ROAM,"Rejected","Rejected");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SEND_VISIBILITY,"Sender visibility","Sender visibility");
	ADD_APPLICATION_STRING2(MEA_STR_ID_HIDE_NUMBER,"Show number","Show number");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SHOW_NUMBER,"Hide number","Hide number");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SEND_READ_REPORT,"Send Read Report","Send Read Report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ALWAYS,"Always","Always");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_ON_REQUEST,"On request","On request");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_NEVER,"Never","Never");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_DELIVERY_TIME,"Delivery time","Delivery time");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IMMEDIATE,"Immediate","Immediate");
#ifdef __OP01_MMS_RETRIEVE_SETTING__
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_SEND_READ_REPORT_ALLOWED,"Send Read Report","Send Read Report");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_RETRIEVE_ALLOWED,"Retrieve Allowed","Retrieve Allowed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_RETRIEVE_IM_ROAM,"Retrieve Immediately(ROAM)","Retrieve Immediately(ROAM)");
#endif
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IN_ONE_HOUR,"In 1 hour","In 1 hour");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IN_12_HOURS,"In 12 hours","In 12 hours");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_IN_24_HOURS,"In 24 hours","In 24 hours");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PLAY_SOUND,"Play Audio","Play Audio");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PLAY_VIDEO,"Play Video","Play Video");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_DELIVERY_REPORT_ALLOWED,"Delivery report allowed","Delivery report allowed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_AUDIO,"Add Audio","Add Audio");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEXT_COLOR,"Add text color","Add text color");
	ADD_APPLICATION_STRING2(MEA_STR_ID_BCC,"Bcc:","Bcc:");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEXT_MISSING,"The text can not be displayed","The text can not be displayed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SINGLE_OBJECT_SIZE_WARNING,"Recipient may not be able to view large media","Recipient may not be able to view large media");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_INSERT_DRM,"Failed to insert DRM object","Failed to insert DRM object");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_RESIZE_IMAGE,"Failed to resize image","Failed to resize image");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_DOWNLOAD_REQ1,"You are currently not in your home network and there might be additional charges on transactions. Do you want to download the message with size","You are currently not in your home network and there might be additional charges on transactions. Do you want to download the message with size");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_DOWNLOAD_REQ2,"K?","K?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_SEND_REQ1,"You are currently not in your home network and there might be additional charges on transactions. Do you want to send the message with size ","You are currently not in your home network and there might be additional charges on transactions. Do you want to send the message with size ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ROAM_SEND_REQ2,"K?","K?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_INVALID_NETWORK_SETTINGS,"Your network settings are invalid. Please check MMSC and WAP settings","Your network settings are invalid. Please check MMSC and WAP settings");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_BUSY,"The called party is busy","The called party is busy");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_NO_NETWORK,"The network is not available","The network is not available");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_NO_ANSWER,"The called party did not answer","The called party did not answer");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_NOT_A_NUMBER,"Invalid number","Invalid number");	//
	ADD_APPLICATION_STRING2(MEA_STR_ID_CALL_ERROR,"Could not place call","Could not place call");
	ADD_APPLICATION_STRING2(MEA_STR_ID_UNHANDLED_LINK,"Cannot handle this link","Cannot handle this link");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_GET_MESSAGE_INFO,"Failed to open original message","Failed to open original message");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_OPEN_WINDOW,"Failed to open window","Failed to open window");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MAX_NUMBER_OF_MSG,"Max number of stored messages reached. Please delete messages.","Storage Full for New Incoming MMS!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_TO_SEND_REFUSED,"The message was not accepted by the server due to size or some other reason.","Not accepted by the server.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NUMBER_OF_MSG_WARNING,"Near max number of stored messages. Please delete messages.","Near max number of stored MMS. Please delete messages.");

	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_INVALID_NUMBER,"Invalid Number Removed","Invalid Number Removed");
    ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_ARCHIVE, "Move to archive", "Move to archive");
    ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_ARCHIVE_QUERY, "Move to archive?", "Move to archive?");    
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADDRESS_ALREADY_EXISTS,"Address Already Exists","Address Already Exists");
    ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACH_MAXIMUM_REACHED,"Maximum attachment number reached", "Maximum attachment number reached");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ADD_ATTACHMENT,"Add Attachment","Add Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_ATTACHMENT_REMOVED,"Attachment was removed","Attachment was removed");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_SIGNATURE,"Auto Signature","Auto Signature");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_SIGNATURE_ERROR_TOO_MANY_SLIDES,"No Signature Due to Too Many Slides","No Signature Due to Too Many Slides");
	ADD_APPLICATION_STRING2(MEA_STR_ID_AUTO_SIGNATURE_ERROR_SIZE_TOO_LARGE,"No Signature Due to Size Too Large","No Signature Due to Size Too Large");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CONFIG_COMPOSE,"Compose","Compose");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE,"Creation Mode","Creation Mode");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE_FREE,"Free","Free");
	ADD_APPLICATION_STRING2(MEA_STR_ID_CREATION_MODE_RESTRICTED,"Restricted","Restricted");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MIME_ACTION_NONE,"Restricted mode: unsupported content", "Restricted mode: unsupported content");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_REMOVE_OBJ_REQ,"Restricted mode: remove unsupported content?","Restricted mode: remove unsupported content?");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_EDIT,"Restricted mode: edit prohibited","Restricted mode: edit prohibited");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_SEND,"Restricted mode: send prohibited","Restricted mode: send prohibited");
    ADD_APPLICATION_STRING2(MEA_STR_ID_RESTRICTED_MODE_FAIL_TO_FORWARD,"Restricted mode: forward prohibited","Restricted mode: forward prohibited");
	ADD_APPLICATION_STRING2(MEA_STR_ID_IMAGE_RESIZE,"Image Resizing","Image Resizing");
	ADD_APPLICATION_STRING2(MEA_STR_ID_640x480,"640x480","640x480");
	ADD_APPLICATION_STRING2(MEA_STR_ID_320x240,"320x240","320x240");
	ADD_APPLICATION_STRING2(MEA_STR_ID_160x120,"160x120","160x120");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_ARCHIVE,"Delete All Archive?","Delete All Archive?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_INBOX,"Delete All Inbox?","Delete All Inbox?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_OUTBOX,"Delete All Outbox?","Delete All Outbox?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_TEMPLATE,"Delete All Template?","Delete All Template?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_SENT,"Delete All Sent?","Delete All Sent?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DELETE_ALL_DRAFTS,"Delete All Drafts?","Delete All Drafts?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_DIAL,"Dial","Dial");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_ATTACHMENT,"Edit Attachment","Edit Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_EDIT_PROFILE,"Server Profile","Server Profile");
	ADD_APPLICATION_STRING2(MEA_STR_ID_FREE, "Free Space: ","Free Space: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_LSK_READ,"Read","Read");
	ADD_APPLICATION_STRING2(MEA_STR_ID_LSK_YES,"Yes","Yes");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MEMORY_STATUS,"Memory Status","Memory Status");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MSG,"msg","msg");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MSGS,"msgs","msgs");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_CONTENT, "No Content", "No Content");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_NUMBER, "No Number!", "No Number!");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NO_SUBJECT, "(No Subject)", "(No Subject)");
	ADD_APPLICATION_STRING2(MEA_STR_ID_PLY_SMIL_BUSY,"System Busy","System Busy");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_ATTACHMENT,"Remove Attachment","Remove Attachment");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RESEND,"Resend","Resend");
	ADD_APPLICATION_STRING2(MEA_STR_ID_RSK_NO,"No","No");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVED_AND_SENT,"Saved and Sent","Saved and Sent");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SAVE_TO_DRAFTS,"Save to Draft","Save to Draft");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SLIDE,"Slide","Slide");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SLIDES,"Slides","Slides");
#endif /* MMS_SUPPORT */
	ADD_APPLICATION_STRING2(MEA_STR_ID_STORAGE_FULL,"Storage Full!","Storage Full!");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(MEA_STR_ID_TOO_MANY_CONNECTIONS,"Too many connections","Too many connections");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TOTAL,"Used Space: ","Used Space: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_USAGE,"Usage: ","Usage: ");
	ADD_APPLICATION_STRING2(MEA_STR_ID_TEMPLATE_CORRUPT,"The template is corrupted","The template is corrupted");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MESSAGE_CORRUPT,"Message may be corrupted. Please remove it.","Message may be corrupted. Please remove it.");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMOVE_CORRUPT_MESSAGE_REQ,"Message corrupted. Remove it?","Message corrupted. Remove it?");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SERVER,"Server","Server");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MOVE_TO_DRAFT,"Move To Draft","Move To Draft");
	ADD_APPLICATION_STRING2(MEA_STR_ID_SHOW_STATUS,"Status","Status");
	ADD_APPLICATION_STRING2(MEA_STR_ID_WAITING,"Waiting","Waiting");
	ADD_APPLICATION_STRING2(MEA_STR_ID_NEXT_TRANS_TIME,"Next Transmission Time","Next Transmission Time");
	ADD_APPLICATION_STRING2(MEA_STR_ID_MINS,"Mins","Mins");
	ADD_APPLICATION_STRING2(MEA_STR_ID_REMAIN_QUOTA,"The Remaining Quota","The Remaining Quota");

       ADD_APPLICATION_STRING2(MEA_STR_ID_TEMPLATES_FOLDER_LIST, "MMS Templates", "MMS Templates");
       ADD_APPLICATION_STRING2(MEA_STR_ID_DEFAULT_TEMPLATES, "Default", "Default");
       ADD_APPLICATION_STRING2(MEA_STR_ID_USER_TEMPLATES, "User Defined", "User Defined");
       ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_SAVE_AS_TEMPLATE, "Failed to Save Template!", "Failed to Save Template!");
    ADD_APPLICATION_STRING2(MEA_STR_ID_NUMBER_TOO_LONG, "SMS Number Limit Exceeded", "SMS Number Limit Exceeded");
    ADD_APPLICATION_STRING2(MEA_STR_ID_FAILED_ENTER_DEF_TEMPLATE, "Enter template fail", "Enter template fail");
	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(MMS_STR_ID_EMPTY_STRING," "," ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_FROM,"From: ","From: ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_MSGID,"Message ID: ","Message ID: ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_READ,"READ: ","READ: ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_SENT,"Sent:       ","Sent:       ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_SUBJECT,"Subject:    ","Subject:    ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_TO,"To:         ","To:         ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_WAS_READ,"\\n\\nwas read on ","\\n\\nwas read on ");
	ADD_APPLICATION_STRING2(MMS_STR_ID_RR_TEXT_YOUR_MSG,"Your message\\n\\n","Your message\\n\\n");
#if (__MMI_MMS_TEMPLATES_NUM__>0)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_01,"Happy birthday","Happy birthday");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>1)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_02,"Call me","Call me");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>2)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_03,"Take care","Take care");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>3)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_04,"I am busy now","I am busy now");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>4)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_05,"I'll be late","I'll be late");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>5)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_06,"Miss you","Miss you");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>6)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_07,"Thank you","Thank you");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>7)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_08,"Where are you?","Where are you?");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>8)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_09,"The appointment is cancelled","The appointment is cancelled");
#endif
#if (__MMI_MMS_TEMPLATES_NUM__>9)
	ADD_APPLICATION_STRING2(MMS_STR_ID_TEMPLATES_TITLE_10,"Everything is OK","Everything is OK");
#endif
#endif /* MMS_SUPPORT */

	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_SAVE,"Save","Save");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_EDIT_FILENAME,"Edit filename","Edit filename");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_ROOT_FOLDER,"My Content", "My Content");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_SAVE_HERE,"Save here","Save here");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TEXT1,"","");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TEXT2," already exists. Replace it?"," already exists. Replace it?");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TITLE,"File exists","File exists");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TEXT1,"","");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TEXT2,"  exists and cannot be replaced.","  exists and cannot be replaced.");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TITLE,"File exists","File exists");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SAVE_ERROR,"Save Error","Save Error");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SAVE_NOT_ALLOWED, "This file type may not be saved.","This file type may not be saved.");
 	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_BAR_TITLE,"Downloading...","Downloading...");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ACTION_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_TITLE,"Unexpected error","Unexpected error");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_FULL,"Disk space is not enough","Disk space is not enough");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_SIZE,"File size exceeds maximum value","File size exceeds maximum value");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MIME_ACTION_SAVE,"Save As","Save As");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_CREATE_DIR,"Create folder","Create folder");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_CREATE_DIR,"Create new folder","Create new folder");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ERROR_CREATE_DIR,"Cannot create folder with the name.","Cannot create folder with the name.");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_COMMON_ERROR,"Error","Error");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ERROR_NAME,"The specified name is invalid.","The specified name is invalid.");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_PERCENT," % done"," % done");
	ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_BYTES_SAVED," bytes saved.", " bytes saved.");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CANNOT_SAVE,"Cannot save this file type!", "Cannot save this file type!");
	ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE2,".", ".");
	ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE3," kBytes", " kBytes");
	ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE4," MBytes", " MBytes");
	ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE5," Bytes", " Bytes");
	ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_MIME_ACTION_NONE,"Unsupported content.", "Unsupported content.");
	ADD_APPLICATION_STRING2(MSF_STR_ID_MIME_ACTION_SET_RINGTONE,"Set ringtone", "Set ringtone");
	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(PHS_STR_ID_ACCEPT_MSG,"Accept push","Accept push");
	ADD_APPLICATION_STRING2(PHS_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(PHS_STR_ID_DECLINE_MSG,"Decline push","Decline push");
	ADD_APPLICATION_STRING2(PHS_STR_ID_NO_WHITELIST_MSG,"Push from unauthorised sender","Push from unauthorised sender");
	ADD_APPLICATION_STRING2(PHS_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(PHS_STR_ID_SIA_CONFIRM_MSG,"Would you like to set up a new push connection?","Would you like to set up a new push connection?");
	ADD_APPLICATION_STRING2(PRS_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(PRS_STR_ID_EMPTY," "," ");
	ADD_APPLICATION_STRING2(PRS_STR_ID_ENTER_PIN,"Enter the PIN","Enter the PIN");
	ADD_APPLICATION_STRING2(PRS_STR_ID_ENTER_PIN_AGAIN,"Wrong PIN Code!","Wrong PIN Code!");
	ADD_APPLICATION_STRING2(PRS_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(PRS_STR_ID_PIN_TITLE,"PIN Dialog","PIN Dialog");
	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(SEC_STR_ID_ALLOW_DEL_TITLE,"Delete keys","Delete keys");
	ADD_APPLICATION_STRING2(SEC_STR_ID_APR,"April","April");
	ADD_APPLICATION_STRING2(SEC_STR_ID_AUG,"August","August");
	ADD_APPLICATION_STRING2(SEC_STR_ID_AUTH_KEY,"authentication key","authentication key");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT1,"Store unknown certificate?","Store unknown certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT10,"No trusted certificate, continue?","No trusted certificate, continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT11,"No user certificate, continue?","No user certificate, continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT12,"The contract has been deleted","The contract has been deleted");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT13,"Could not delete the contract","Could not delete the contract");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT14,"Could not show the certificate","Could not show the certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT15,"Could not delete the certificate","Could not delete the certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT16,"No trusted certificate. continue?","No trusted certificate. continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT17,"Cannot store the certificate","Cannot store the certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT18,"Unknown server, continue?","Unknown server, continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT19,"Error in certificate. continue?","Error in certificate. continue?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT2,"Overwrite existed same certificate?","Overwrite existed same certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT3,"Overwrite existed old certificate?","Overwrite existed old certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT4,"Overwrite existed new certificate?","Overwrite existed new certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT5,"The certificate has been stored.","The certificate has been stored.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CERT7,"Remove existed old trust certificate?","Remove existed old trust certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHANGE_PIN_NEW,"Enter a new PIN for the ","Enter a new PIN for the ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHANGE_PIN_NEW2,"Enter the new PIN again ","Enter the new PIN again ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHANGE_PIN_OLD,"Enter the old PIN ","Enter the old PIN ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHANGE_PIN_TITLE,"Change PIN","Change PIN");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHOOSE_CERT_PUB_KEY_TITLE,"Choose a certificate to get the public key from:","Choose a certificate to get the public key from:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CHOOSE_CERT_TITLE,"Choose a certificate:","Choose a certificate:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CONFIRM_TITLE,"Confirmation","Confirmation");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CONF_DISP_NAME_TITLE,"Confirm display name","Confirm display name");
	ADD_APPLICATION_STRING2(SEC_STR_ID_CONTRACT,"Contract:","Contract:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_DEC,"December","December");
	ADD_APPLICATION_STRING2(SEC_STR_ID_DELETE,"Delete","Delete");
	ADD_APPLICATION_STRING2(SEC_STR_ID_EMPTY," "," ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_EMPTY1,"Choose certificate","Choose certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_ENTER_HASH,"Enter hash for the display name:","Enter hash for the display name:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_FEB,"February","February");
	ADD_APPLICATION_STRING2(SEC_STR_ID_FR_NAME,"Friendly name:","Friendly name:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_GEN_PIN,"Enter a PIN for the ","Enter a PIN for the ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_GEN_PIN_TITLE,"Generate PIN","Generate PIN");
	ADD_APPLICATION_STRING2(SEC_STR_ID_HASH_TITLE,"Hash","Hash");
	ADD_APPLICATION_STRING2(SEC_STR_ID_INPUT_ERROR,"Some error occurred. Try again","Some error occurred. Try again");
	ADD_APPLICATION_STRING2(SEC_STR_ID_ISSUER,"Issuer:","Issuer:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_JAN,"January","January");
	ADD_APPLICATION_STRING2(SEC_STR_ID_JULY,"July","July");
	ADD_APPLICATION_STRING2(SEC_STR_ID_JUNE,"June","June");
	ADD_APPLICATION_STRING2(SEC_STR_ID_MARCH,"March","March");
	ADD_APPLICATION_STRING2(SEC_STR_ID_MAY,"May","May");
	ADD_APPLICATION_STRING2(SEC_STR_ID_NONREP_KEY,"non-repudiation key","non-repudiation key");
	ADD_APPLICATION_STRING2(SEC_STR_ID_NOV,"November","November");
	ADD_APPLICATION_STRING2(SEC_STR_ID_OCT,"October","October");
	ADD_APPLICATION_STRING2(SEC_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(SEC_STR_ID_OVERWRITE,"Overwrite","Overwrite");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_ALLOW_DEL_AUT,"PUK to delete all authentication keys and connected user certificates","PUK to delete all authentication keys and connected user certificates");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_ALLOW_DEL_NR,"PUK to delete all non-repudiation keys and connected user certificates","PUK to delete all non-repudiation keys and connected user certificates");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_CONNECT,"the PIN to the authentication key to connect","the PIN to the authentication key to connect");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_DEL_CERT,"the PIN to the authentication key to delete certificate","the PIN to the authentication key to delete certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_DIALOG,"Enter ","Enter ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_DIALOG_TITLE,"PIN Dialog","PIN Dialog");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_GEN_AUT_KEY,"a PIN to to generate authentication key","a PIN to to generate authentication key");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_GEN_NR_KEY,"a PIN to generate non-repudiation key","a PIN to generate non-repudiation key");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_MISMATCH,"The new PINs did not match. Enter a new PIN for the ","The new PINs did not match. Enter a new PIN for the ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_OPEN_WIM,"the PIN to the authentication key to open WIM","the PIN to the authentication key to open WIM");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_PUK,"the PUK","the PUK");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_SIGN_TEXT,"the PIN to the non-repudiation key to","the PIN to the non-repudiation key to");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_STORE_CERT,"the PIN to the authentication key to store certificate","the PIN to the authentication key to store certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_TOO_LONG,"The PIN was to long. Enter a PIN for the ","The PIN was to long. Enter a PIN for the ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_PIN_TOO_SHORT,"The PIN was to short. Enter a PIN for the ","The PIN was to short. Enter a PIN for the ");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SEP,"September","September");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_3DES,"Encryption algorithm: Triple DES","Encryption algorithm: Triple DES");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_KEYLEN,"Encryption key length:","Encryption key length:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_NULL,"Encryption algorithm: NULL","Encryption algorithm: NULL");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_RC4_128,"Encryption algorithm: RC4 128","Encryption algorithm: RC4 128");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_RC4_40,"Encryption algorithm: RC4 40","Encryption algorithm: RC4 40");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_RC5,"Encryption algorithm: RC5","Encryption algorithm: RC5");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_RC5_40,"Encryption algorithm: RC5 40","Encryption algorithm: RC5 40");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_RC5_56,"Encryption algorithm: RC5 56","Encryption algorithm: RC5 56");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_ENCR_RC5_64,"Encryption algorithm: RC5 64","Encryption algorithm: RC5 64");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_HMAC_KEYLEN,"HMAC key length:","HMAC key length:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_INFO_TITLE,"Session info","Session info");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_DHE_DSS,"Key exchange algorithm: DHE DSS","Key exchange algorithm: DHE DSS");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_KEYLEN,"Key exchange key length:","Key exchange key length:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_NULL,"Key exchange algorithm: NULL","Key exchange algorithm: NULL");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_RSA,"Key exchange algorithm: RSA","Key exchange algorithm: RSA");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_RSA_512,"Key exchange algorithm: RSA 512","Key exchange algorithm: RSA 512");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_RSA_768,"Encryption algorithm: RC5 768","Encryption algorithm: RC5 768");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_RSA_ANON,"Key exchange algorithm: RSA ANON","Key exchange algorithm: RSA ANON");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_RSA_ANON_512,"Key exchange algorithm: RSA ANON 512","Key exchange algorithm: RSA ANON 512");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_KEYEXCH_RSA_ANON_768,"Key exchange algorithm: RSA ANON 768","Key exchange algorithm: RSA ANON 768");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_MD5,"HMAC algorithm:MD5","HMAC algorithm:MD5");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_SHA1,"HMAC algorithm:SHA-1","HMAC algorithm:SHA-1");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_SSL,"Connection type:SSL","Connection type:SSL");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_TLS,"Connection type:TLS","Connection type:TLS");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SESS_WTLS,"Connection type:WTLS","Connection type:WTLS");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SHOW_CERT_NAMES_TITLE,"Certificate names","Certificate names");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SHOW_CERT_TITLE,"Certificate","Certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SHOW_CONTRACTS_TITLE,"Contract","Contract");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SIGNATURE,"Signature:","Signature:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SIGN_TEXT1,"Do you want to sign this:","Do you want to sign this:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_STORE,"Store","Store");
	ADD_APPLICATION_STRING2(SEC_STR_ID_STORED_CONTRACTS_TITLE,"Stored contracts","Stored contracts");
	ADD_APPLICATION_STRING2(SEC_STR_ID_STORE_CERT,"Store this certificate?","Store this certificate?");
	ADD_APPLICATION_STRING2(SEC_STR_ID_STORE_CERT_TITLE,"Store certificate","Store certificate");
	ADD_APPLICATION_STRING2(SEC_STR_ID_SUBJECT,"Subject:","Subject:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_TIME,"Time:","Time:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_VAL_NOT_AFT,"Valid not after:","Valid not after:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_VAL_NOT_BEF,"Valid not before:","Valid not before:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_VIEW,"View","View");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_COULD_NOT_STORE_CONTRACT,"The contract could not be stored.","The contract could not be stored.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_GENERAL_ERROR,"An error occured.","An error occured.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_INSUFFICIENT_MEMORY,"Not enough memory to perform the action.","Not enough memory to perform the action.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_INVALID_PARAMETER,"Invalid input.","Invalid input.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_AUT_KEY_HANDSHAKE,"No authentication key exists (noticed when opening the WIM).","No authentication key exists (noticed when opening the WIM).");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_AUT_KEY_OPEN_WIM,"No authentication key was found when trying to open the WIM.","No authentication key was found when trying to open the WIM.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_KEY,"No key was found.","No key was found.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_KEY_CHANGE_AUTH,"No authentication key was found when trying to change it.","No authentication key was found when trying to change it.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_KEY_CHANGE_NONREP,"No non-repudiation key was found when trying to change it.","No non-repudiation key was found when trying to change it.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_KEY_CONNECT,"No authentication key was found when trying to connect.","No authentication key was found when trying to connect.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_KEY_DELETE_CERT,"No authentication key was found when trying to delete a certificate.","No authentication key was found when trying to delete a certificate.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_KEY_STORE_CERT,"No authentication key was found when trying to store a certificate.","No authentication key was found when trying to store a certificate.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_MISSING_NR_KEY_SIGN_TEXT,"No non-repudiation key was found when trying to sign a text.","No non-repudiation key was found when trying to sign a text.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_TITLE,"Warning","Warning");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WARNING_USER_NOT_VERIFIED,"The user has not been verified.","The user has not been verified.");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WRONG_HASH,"Input error, try again:","Input error, try again:");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WRONG_OLD_PIN,"The wrong old PIN was entered. Enter a PIN for the","The wrong old PIN was entered. Enter a PIN for the");
	ADD_APPLICATION_STRING2(SEC_STR_ID_WRONG_PIN,"Could not verify the input. Enter","Could not verify the input. Enter");
	ADD_APPLICATION_STRING2(SEC_STR_ID_FINGERPRINT, "Fingerprint:", "Fingerprint:");
	//////////////////////////////////////////////////////
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(SMA_STR_ID_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(SMA_STR_ID_EMPTY_STRING," "," ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ERR_NO_MEMORY,"Not enough persistent storage.","Not enough persistent storage.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ERR_WRITING_FILE,"Error writing file.","Error writing file.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_LINKS,"Links","Links");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_NEXT,"Next page","Next page");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_PLAY,"Play","Play");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_PREVIOUS,"Previous page","Previous page");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_AUDIO,"Save audio","Save audio");
#endif /* MMS_SUPPORT */
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_IMAGE,"Save image","Save image");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(SMA_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_EXIT,"Exit","Exit");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_OK," "," ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_PLAY,"Play","Play");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_ACTION_STOP,"Stop","Stop");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_MENU_ACTION_BACK,"Back","Back");
	ADD_APPLICATION_STRING2(SMA_STR_ID_SLIDE_MENU_ACTION_SELECT,"Select","Select");
	ADD_APPLICATION_STRING2(SMA_STR_ID_UNKNOWN_TEXT,"The text could not be displayed.","The text could not be displayed.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_OBJECT,"Save Object","Save Object");
	ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_VIDEO,"Save video","Save video");
        ADD_APPLICATION_STRING2(SMA_STR_ID_MENU_SAVE_TEXT,"Save text","Save text");
	ADD_APPLICATION_STRING2(SMA_STR_ID_FAILED_TO_SAVE,"Failed to save the media object.","Failed to save the media object.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_FAILED_TO_SAVE_DRM,"The object is protected and cannot be saved.","The object is protected and cannot be saved.");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ATTACHMENTS,"View attachments","View attachments");
	ADD_APPLICATION_STRING2(SMA_STR_ID_ATTACHMENT_LIST,"Attachment List","Attachment List");
	ADD_APPLICATION_STRING2(SMA_STR_ID_CALL_BUSY,"Called party is busy","Called party is busy");
#endif /* MMS_SUPPORT */
	ADD_APPLICATION_STRING2(SMA_STR_ID_CALL_FAILED,"Call failed","Call failed");
#ifdef MMS_SUPPORT
	ADD_APPLICATION_STRING2(SMA_STR_ID_UI_OPEN,"Open ","Open ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_UI_CALL,"Call ","Call ");
	ADD_APPLICATION_STRING2(SMA_STR_ID_NOT_ABLE_PLAY_ALL_SLIDES,"Not able to play all slides ","Not able to play all slides ");
#endif /* MMS_SUPPORT */
	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(STK_STR_ID_EXIT,"Exit","Exit");
	ADD_APPLICATION_STRING2(STK_STR_ID_NON_SECURE,"Warning: Transmitted unprotected!","Warning: Transmitted unprotected!");
	ADD_APPLICATION_STRING2(STK_STR_ID_PASSWORD,"Password:","Password:");
	ADD_APPLICATION_STRING2(STK_STR_ID_REALM_LABEL,"Realm:","Realm:");
	ADD_APPLICATION_STRING2(STK_STR_ID_SAVE_PASSWORD,"Save Username and Password","Save Username and Password");
	ADD_APPLICATION_STRING2(STK_STR_ID_SAVE_USERNAME,"Save Username","Save Username");
	ADD_APPLICATION_STRING2(STK_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(STK_STR_ID_TITLE_PROXY,"Enter Proxy Password","Enter Proxy Password");
	ADD_APPLICATION_STRING2(STK_STR_ID_TITLE_SERVER,"Enter Server Password","Enter Server Password");
	ADD_APPLICATION_STRING2(STK_STR_ID_USERNAME,"UserName:","UserName:");
	//////////////////////////////////////////////////////
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_CANCEL,"Cancel","Cancel");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_CANT_INPUT_EMPTY_VALUE,"Can't input empty value!","Can't input empty value!");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_CANT_SWITCH_INPUT_METHOD, "Can't set input method", "Can't set input method");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_DONE,"Done","Done");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INPUT_FORMAT_ERROR,"Input format error!","Input format error!");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INPUT_METHOD,"Input Method","Input Method");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INPUT_TITLE,"Input","Input");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_OK,"Ok","Ok");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_OPTION,"Option","Option");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_SAVEAS_NAME_INVALID_CHARS,"Please input alphabets and numbers only","Please input alphabets and numbers only");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_PLEASE_WAIT, "Please Wait", "Please Wait");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_IMAGE_RESIZE, "Resizing image", "Resizing image");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_SEARCH, "Search", "Search");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_PUSH, "New Service Message", "Push message prompt");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_PROVISION, "New Setting", "Provision message prompt");
#ifdef __MMI_DUAL_SIM__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_PROVISION_SIM_1, "New SIM1 Setting", "SIM1 Provision message prompt");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_PROVISION_SIM_2, "New SIM2 Setting", "SIM2 Provision message prompt");
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_MSG, "New MMS Message", "MMS message prompt");
#ifdef __MMI_DUAL_SIM__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_1, "New MMS Message(SIM 1)", "MMS message prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_MSG_SIM_2, "New MMS Message(SIM 2)", "MMS message prompt(SIM 2)");
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION, "New MMS Message", "MMS notification prompt");
#ifdef __MMI_DUAL_SIM__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_1, "New MMS Message(SIM 1)", "MMS notification prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_NOTIFICATION_SIM_2, "New MMS Message(SIM 2)", "MMS notification prompt(SIM 2)");    
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT, "New MMS Report", "MMS report prompt");
#ifdef __MMI_DUAL_SIM__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_1, "New MMS Report(SIM 1)", "MMS report prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_READ_REPORT_SIM_2, "New MMS Report(SIM 2)", "MMS report prompt(SIM 2)");    
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT, "New MMS Report", "MMS report prompt");
#ifdef __MMI_DUAL_SIM__
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_1, "New MMS Report(SIM 1)", "MMS report prompt(SIM 1)");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_RECEIVED_MMS_DELIVERY_REPORT_SIM_2, "New MMS Report(SIM 2)", "MMS report prompt(SIM 2)");    
#endif
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_A, "invalid WCSS format - A", "invalid WCSS format - A");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_A, "invalid WCSS format - a", "invalid WCSS format - a");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__UPPERCASE_X, "invalid WCSS format - X", "invalid WCSS format - X");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_X, "invalid WCSS format - x", "invalid WCSS format - x");
	ADD_APPLICATION_STRING2(WIDGET_STR_ID_INVALID_WCSS__LOWERCASE_N, "invalid WCSS format - n", "invalid WCSS format - n");

	/* workaround */
	ADD_APPLICATION_STRING2(WAP_STR_ID_LAST_DUMMY ,"dummy","dummy");
#elif (defined OBIGO_Q05A)
	/* MSF */
    ADD_APPLICATION_STRING2(MSF_STR_ID_MNU_BOOKMARK, "Download more", "Download more");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_PICTURE, "My Pictures", "My Pictures");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_SOUND, "My Sounds", "My Sounds");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_VIDEO, "My Videos", "My Videos");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_APP, "My Applications", "My Applications");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_ANIM, "My Animations", "My Animations");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_EXT, "Memory Card", "Memory Card");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_BOOKMARK, "My Bookmarks", "My Bookmarks");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_OFLN_PGS, "Offline Pages", "Offline Pages");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_BKM_PERS, "Persistent Bookmarks", "Persistent Bookmarks");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_TEMPLATES, "My Templates", "My Templates");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_OTH_DOCS, "My Other Documents", "My Other Documents");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_CONTACTS, "My Contacts", "My Contacts");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_SCHEDULER, "Scheduler", "Scheduler");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_MEMO, "Memo", "Memo");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_GAMES, "My Games", "My Games");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ROOT_FOLDER_SKINS, "My Skins", "My Skins");
    ADD_APPLICATION_STRING2(MSF_STR_ID_USER_FOLDER_NATURE, "Nature Pictures", "Nature Pictures");
    ADD_APPLICATION_STRING2(MSF_STR_ID_USER_FOLDER_WORK, "Work Pictures", "Work Pictures");
    ADD_APPLICATION_STRING2(MSF_STR_ID_USER_FOLDER_VACATION, "Vacation Pictures", "Vacation Pictures");
    ADD_APPLICATION_STRING2(MSF_STR_ID_USER_FOLDER_MUSIC, "My Music", "My Music");
    ADD_APPLICATION_STRING2(MSF_STR_ID_USER_FOLDER_SOUNDS, "My Sounds", "My Sounds");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UILIST_LBL_SELECT, "Select", "Select");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UILIST_LBL_OPTION, "Options", "Options");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UILIST_LBL_BACK, "Back", "Back");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UILIST_LBL_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UI_COMP_TITLE_ERROR, "Error", "Error");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCCL_EMPTY_TITLE, "Empty list", "Empty list");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCCL_EMPTY_TEXT, "There are no supported items in the list.", "There are no supported items in the list.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCDG_MESSAGE_ACTION_OK, "OK", "OK");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCDG_PROMPT_ACTION_OK, "OK", "OK");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCDG_PROMPT_ACTION_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCSL_ACTION_OK, "OK", "OK");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCSL_ACTION_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCFL_TEXT_ROOT_FOLDER, "My Content", "My Content");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCFL_SIZE, "Size: %0s", "Size: %0s");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCFL_CANNOT_OPEN_CONTENT, "Cannot open content.", "Cannot open content.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCFL_CANNOT_OPEN_FOLDER, "Cannot open folder.", "Cannot open folder.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_YES, "Yes", "Yes");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_NO, "No", "No");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_OPTION, "Options", "Options");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_SELECT, "Select", "Select");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_BACK, "Back", "Back");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_DELETE, "Delete", "Delete");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_UP, "Up", "Up");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_PGUP, "Page up", "Page up");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_DOWN, "Down", "Down");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_PGDOWN, "Page down", "Page down");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_LEFT, "Left", "Left");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_PREV, "Prev", "Prev");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_RIGHT, "Right", "Right");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_NEXT, "Next", "Next");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_PLAY, "Play", "Play");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_STOP, "Stop", "Stop");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_PAUSE, "Pause", "Pause");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_CHECK, "Check", "Check");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_UNCHECK, "Uncheck", "Uncheck");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_CALL, "Call", "Call");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_EDIT, "Edit", "Edit");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_CLEAR, "Clear", "Clear");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_REWIND, "Rewind", "Rewind");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_REWIND_STOP, "Stop rewind", "Stop rewind");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_FORWARD, "Forward", "Forward");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CMD_ACTION_FORWARD_STOP, "Stop forward", "Stop forward");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SAVE, "Save", "Save");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_OPEN, "Open", "Open");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_DISPLAY, "Display", "Display");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_PLAY, "Play", "Play");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_LOAD_URL, "Open", "Open");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SET, "Set as", "Set as");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SET_SCREENSAVER, "Screensaver", "Screensaver");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SET_GREETING, "Greeting", "Greeting");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SET_WALLPAPER, "Wallpaper", "Wallpaper");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SET_RINGTONE, "Ringtone", "Ringtone");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SEND_AS, "Send as", "Send as");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_MSG, "Message", "Message");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_EMAIL, "Email", "Email");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_BLUETOOTH, "Bluetooth", "Bluetooth");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_INFRARED, "Infrared", "Infrared");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_USB, "USB", "USB");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_POSTCARD, "Postcard", "Postcard");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_CALL, "Call", "Call");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_VIDEO_CALL, "Video call", "Video call");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_ADD_TO_CALENDAR, "Add to calendar", "Add to calendar");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_ADD_TO_CONTACT, "Add to contact", "Add to contact");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_ADD_BOOKMARK, "Add bookmark", "Add bookmark");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_UPLOAD_TO_ALBUM, "Upload to album", "Upload to album");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_MOVE_TO_ALBUM, "Move", "Move");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_COPY_TO_ALBUM, "Copy", "Copy");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_GET_PHOTO, "Get photo", "Get photo");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_GET_AUDIO, "Get audio", "Get audio");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_GET_VIDEO, "Get video", "Get video");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_PICK_FROM_CONTACT, "Pick from contact", "Pick from contact");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_SET_SKIN, "Skin", "Skin");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_MT1_TEST1, "MT1 obj-act test1", "MT1 obj-act test1");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_MT1_TEST2, "MT1 obj-act test2", "MT1 obj-act test2");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ACT_IMPL_MT1_TEST3, "MT1 obj-act test3", "MT1 obj-act test3");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_OK, "OK", "OK");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_BACK, "Back", "Back");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_SAVE_HERE, "Save here", "Save here");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_OPEN, "Open", "Open");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_CREATE_DIR, "Create folder", "Create folder");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SWITCH_TO_MEMCARD, "Switch to memory card", "Switch to memory card");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SWITCH_TO_HANDSET, "Switch to handset memory", "Switch to handset memory");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SWITCH_TO_MULTI, "Multiple select", "Multiple select");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ACTION_MINIMIZE, "Minimize", "Minimize");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CMD_MULTI_CHECK_ALL, "Check all", "Check all");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CMD_MULTI_UNCHECK_ALL, "Uncheck all", "Uncheck all");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CMD_MULTI_OK, "Open", "Open");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CMD_MULTI_BACK, "Back", "Back");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_SAVE_HERE, "Save here", "Save here");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_INFORMATION, "Information", "Information");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_ERROR, "Error", "Error");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_CREATE_FOLDER, "Create folder", "Create folder");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CREATE_FOLDER_DELAYED, "Cannot create folder until previous create folder operation has finished.", "Cannot create folder until previous create folder operation has finished.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_CREATE_FOLDER_NOT_ALLOWED, "Not allowed to create folder here.", "Not allowed to create folder here.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ENTER_FOLDER_NAME, "Enter folder name", "Enter folder name");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_PROMPT_NAME, "Name", "Name");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_FOLDER_EXISTS, "Folder already exists", "Folder already exists");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_FOLDER_EXISTS, "Cannot create folder. Folder already exists.", "Cannot create folder. Folder already exists.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_FOLDER_NAME_INVALID, "Folder name invalid", "Folder name invalid");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_FOLDER_NAME_INVALID, "The specified folder name is invalid.", "The specified folder name is invalid.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_NO_MEM_CARD, "No memory card", "No memory card");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_NO_MEM_CARD, "There is no memory card inserted.", "There is no memory card inserted.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_MEM_CARD_READ_ONLY, "Memory card read only", "Memory card read only");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_MEM_CARD_READ_ONLY, "Cannot save to memory card. Memory card is read only.", "Cannot save to memory card. Memory card is read only.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_MEM_CARD_NO_PERMISSION, "No permission", "No permission");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TEXT_MEM_CARD_NO_PERMISSION, "Not permitted to save this content to external memory.", "Not permitted to save this content to external memory.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SAVE_NO_PERMISSION, "Not allowed to save here.", "Not allowed to save here.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_SAVE_FILE, "Save file", "Save file");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ENTER_FILE_NAME, "Enter file name", "Enter file name");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_EXISTS, "File exists", "File exists");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TEXT1, "", "");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_EXISTS_TEXT2, " already exists. Replace it?", " already exists. Replace it?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TEXT1, "", "");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_REPLACE_TEXT2, " already exists and cannot be replaced.", " already exists and cannot be replaced.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_FILE_NAME_INVALID, "File name invalid", "File name invalid");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_FILE_NAME_INVALID, "The specified file name is invalid.", "The specified file name is invalid.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_NO_SLOTS, "No slots", "No slots");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_SLOTS_FREE, "No free file slot in this folder.", "No free file slot in this folder.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_SLOTS_AT_ALL, "Cannot save files in this folder. This folder has no file slots.", "Cannot save files in this folder. This folder has no file slots.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_TITLE_NOT_ENOUGH_SPACE, "No space", "No space");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NOT_ENOUGH_FREE_SPACE, "Not enough free space to save file.", "Not enough free space to save file.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NOT_ENOUGH_TOTAL_SPACE, "This folder cannot hold files of this size. Choose another folder.", "This folder cannot hold files of this size. Choose another folder.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ERROR_CANNOT_SAVE_FILE, "Cannot save file", "Cannot save file");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ERROR_CREATE_FOLDER, "Cannot create folder.", "Cannot create folder.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ERROR_REPLACE_FILE, "Unable to replace file.", "Unable to replace file.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_ERROR_UNEXPECTED, "Unexpected error.", "Unexpected error.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_SAVE_CANCELED, "Save canceled", "Save canceled");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_NO_FILES, "There are no files to select.", "There are no files to select.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DLG_MULTI_NO_ELEM_SEL, "There are no elements selected.", "There are no elements selected.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_TITLE_BAR, "Saving progress", "Saving progress");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ACTION_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_BAR_TEXT, "Saving...", "Saving...");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_BYTES_SAVED, " bytes saved.", " bytes saved.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_KBYTES_SAVED, " KB saved.", " KB saved.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_MBYTES_SAVED, " MB saved.", " MB saved.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_PERCENT, " % done.", " % done.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_TITLE_INFORMATION, "Information", "Information");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_TITLE_ERROR, "Error", "Error");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_TITLE_CANNOT_SAVE_FILE, "Cannot save file", "Cannot save file");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_TITLE_NOT_ENOUGH_SPACE, "No space", "No space");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_FULL_FREE, "Save failed due to lack of space. Free space now?", "Save failed due to lack of space. Free space now?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_FULL, "There is no free space left.", "There is no free space left.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_SIZE, "File size exceeds system maximum file size.", "File size exceeds system maximum file size.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE2, ".", ".");
    ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE3, " KB", " KB");
    ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE4, " MB", " MB");
    ADD_APPLICATION_STRING2(MSF_STR_ID_PROPERTIES_SIZE5, " B", " B");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_OPEN, "Open", "Open");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_DELETE, "Delete", "Delete");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_REMOVE_PROTECTION, "Remove protection", "Remove protection");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_QUOTA_INFO, "Quota info", "Quota info");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_MULTIPLE_SELECT, "Multiple select", "Multiple select");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_DELETE_SELECTED, "Delete", "Delete");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_CHECK_ALL, "Check all", "Check all");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_UNCHECK_ALL, "Uncheck all", "Uncheck all");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_INFORMATION, "Information", "Information");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_FREE_SPACE, "Free space?", "Free space?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_STOP_FREEING_SPACE, "Stop freeing space?", "Stop freeing space?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_REMOVE_PROTECTION, "Remove protection?", "Remove protection?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_DELETE_FILE, "Delete file?", "Delete file?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_DELETE_FILES, "Delete files?", "Delete files?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_TITLE_CONTINUE, "Continue free space?", "Continue free space?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_BYTES, "Bytes", "Bytes");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_KBYTES, "KB", "KB");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_MBYTES, "MB", "MB");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_FREE_NOW, "Free space now?", "Free space now?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_REMOVE, "Delete <file_name> of size <size> <unit>?", "Delete <file_name> of size <size> <unit>?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_REMOVE_MULTI, "Delete these <nbr_of_files> files of total size <size> <unit>?", "Delete these <nbr_of_files> files of total size <size> <unit>?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_REMOVE_PROTECTION_DLG, "<file_name> is protected. Remove protection?", "<file_name> is protected. Remove protection?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_NEED, "Another <size> <unit> of free space needed.", "Another <size> <unit> of free space needed.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_SPACE, "An extra <size> <unit> of space freed.", "An extra <size> <unit> of space freed.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_FREED, "<size> <unit> of space free.", "<size> <unit> of space free.");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_CONTINUE, "Continue to free space?", "Continue to free space?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DEL_STOP, "Stop freeing space now?", "Stop freeing space now?");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_MONDAY, "Monday", "Monday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_TUESDAY, "Tuesday", "Tuesday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_WEDNESDAY, "Wednesday", "Wednesday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_THURSDAY, "Thursday", "Thursday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_FRIDAY, "Friday", "Friday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_SATURDAY, "Saturday", "Saturday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_SUNDAY, "Sunday", "Sunday");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_MONDAY_SHORT, "Mon", "Mon");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_TUESDAY_SHORT, "Tue", "Tue");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_WEDNESDAY_SHORT, "Wed", "Wed");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_THURSDAY_SHORT, "Thu", "Thu");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_FRIDAY_SHORT, "Fri", "Fri");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_SATURDAY_SHORT, "Sat", "Sat");
    ADD_APPLICATION_STRING2(MSF_STR_ID_DAY_SUNDAY_SHORT, "Sun", "Sun");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JANUARY, "January", "January");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_FEBRUARY, "February", "February");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_MARCH, "March", "March");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_APRIL, "April", "April");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_MAY, "May", "May");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JUNE, "June", "June");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JULY, "July", "July");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_AUGUST, "August", "August");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_SEPTEMBER, "September", "September");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_OCTOBER, "October", "October");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_NOVEMBER, "November", "November");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_DECEMBER, "December", "December");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JANUARY_SHORT, "Jan", "Jan");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_FEBRUARY_SHORT, "Feb", "Feb");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_MARCH_SHORT, "Mar", "Mar");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_APRIL_SHORT, "Apr", "Apr");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_MAY_SHORT, "May", "May");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JUNE_SHORT, "Jun", "Jun");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_JULY_SHORT, "Jul", "Jul");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_AUGUST_SHORT, "Aug", "Aug");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_SEPTEMBER_SHORT, "Sep", "Sep");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_OCTOBER_SHORT, "Oct", "Oct");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_NOVEMBER_SHORT, "Nov", "Nov");
    ADD_APPLICATION_STRING2(MSF_STR_ID_MONTH_DECEMBER_SHORT, "Dec", "Dec");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ASCII_TO_UTF8, "ASCII", "ASCII");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN1_TO_UTF8, "Latin-1", "Latin-1");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UTF16_TO_UTF8, "UTF-16", "UTF-16");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UCS2_TO_UTF8, "UCS-2", "UCS-2");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN2_TO_UTF8, "Latin-2", "Latin-2");
    ADD_APPLICATION_STRING2(MSF_STR_ID_HEBREW_TO_UTF8, "Hebrew", "Hebrew");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SHIFT_JIS_TO_UTF8, "Shift-JIS", "Shift-JIS");
    ADD_APPLICATION_STRING2(MSF_STR_ID_UTF8_TO_UTF8, "UTF-8", "UTF-8");
    ADD_APPLICATION_STRING2(MSF_STR_ID_BIG5_TO_UTF8, "Big5", "Big5");
    ADD_APPLICATION_STRING2(MSF_STR_ID_EUC_JP_TO_UTF8, "EUC-JP", "EUC-JP");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN3_TO_UTF8, "Latin-3", "Latin-3");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN4_TO_UTF8, "Latin-4", "Latin-4");
    ADD_APPLICATION_STRING2(MSF_STR_ID_CYRILLIC_TO_UTF8, "Cyrillic", "Cyrillic");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ARABIC_TO_UTF8, "Arabic", "Arabic");
    ADD_APPLICATION_STRING2(MSF_STR_ID_GREEK_TO_UTF8, "Greek", "Greek");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN5_TO_UTF8, "Latin-5", "Latin-5");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN6_TO_UTF8, "Latin-6", "Latin-6");
    ADD_APPLICATION_STRING2(MSF_STR_ID_EUC_KR_TO_UTF8, "EUC-KR", "EUC-KR");
    ADD_APPLICATION_STRING2(MSF_STR_ID_THAI_TO_UTF8, "Thai", "Thai");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN7_TO_UTF8, "Latin-7", "Latin-7");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN8_TO_UTF8, "Latin-8", "Latin-8");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN9_TO_UTF8, "Latin-9", "Latin-9");
    ADD_APPLICATION_STRING2(MSF_STR_ID_LATIN10_TO_UTF8, "Latin-10", "Latin-10");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1251_TO_UTF8, "Win-1251", "Win-1251");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1252_TO_UTF8, "Win-1252", "Win-1252");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1253_TO_UTF8, "Win-1253", "Win-1253");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1254_TO_UTF8, "Win-1254", "Win-1254");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1255_TO_UTF8, "Win-1255", "Win-1255");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_1256_TO_UTF8, "Win-1256", "Win-1256");
    ADD_APPLICATION_STRING2(MSF_STR_ID_WIN_874_TO_UTF8, "Win-874", "Win-874");
    ADD_APPLICATION_STRING2(MSF_STR_ID_GB2312_TO_UTF8, "GB2312", "GB2312");
    ADD_APPLICATION_STRING2(MSF_STR_ID_ISO_2022_JP_TO_UTF8, "ISO 2022JP", "ISO 2022JP");
    ADD_APPLICATION_STRING2(MSF_STR_ID_SAS_ERROR_PATH, "The chosen folder does not exist.", "The chosen folder does not exist.");

	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0043_30_DLG_INF_YN, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_QUE.gif", "Image of info confirmation icon");
	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0044_30_DLG_INF_Y, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_INF.gif", "Image of info icon");
	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0045_30_DLG_ALERT_YN, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_QUE.gif", "Image of warning confirmation icon");
	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0046_30_DLG_ALERT_Y, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_WARN.bmp", "Image of warning icon");
	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0047_30_DLG_ERROR_YN, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_QUE.gif", "Image of error confirmation icon");
	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0048_30_DLG_ERROR_Y, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_ERR.gif", "Image of error icon");
	ADD_APPLICATION_IMAGE2(MSF_IMAGE_ID_0051_30_DLG_PROMPT_DEF, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_QUE.gif", "Image of confirmation icon");

	/* BRS */
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_UNCHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\radiobutton\\\\ro_uns.bmp", "Image of Unchecked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_CHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\radiobutton\\\\ro_s.bmp", "Image of Checked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_UNCHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\radiobutton\\\\ro_duns.bmp", "Image of Disabled Unchecked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_RADIO_CHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\radiobutton\\\\ro_ds.bmp", "Image of Disabled Checked Radio Button");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_UNCHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_UNS.bmp", "Image of Unchecked CheckBox");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_CHECKED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_S.bmp", "Image of Checked CheckBox");	    
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_UNCHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_DUNS.bmp", "Image of Disabled Unchecked CheckBox");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_CHECKBOX_CHECKED_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_DS.bmp", "Image of Disabled Checked CheckBox");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_BROKEN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_Broken.pbm", "Image of a broken image");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_BGSOUND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_BGSound.pbm", "Image of Background Sound");
	ADD_APPLICATION_IMAGE2(BRS_IMG_ID_ICON_IMG_TO_LARGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_larger.pbm", "Image of a too-large image");


	ADD_APPLICATION_STRING2(BRS_STR_ID_BUTTON, "Button", "Button");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_NOTIFICATION, "The page is not in cache, reload?", "The page is not in cache, reload?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_NOTIFICATION_OBJECT_1, "An object with url = [", "An object with url = [");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_NOTIFICATION_OBJECT_2, "] is not in cache, reload?", "] is not in cache, reload?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CACHE_TITLE, "Cache", "Cache");
	ADD_APPLICATION_STRING2(BRS_STR_ID_CONFIRM_TITLE, "Confirm", "Confirm");
	ADD_APPLICATION_STRING2(BRS_STR_ID_DOWNLOAD_FAILED_TITLE, "Download failed", "Download failed");
	ADD_APPLICATION_STRING2(BRS_STR_ID_ENABLE_SCRIPT_DLG_MSG, "This site uses scripts. Do you want to enable scripting?", "This site uses scripts. Do you want to enable scripting?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_ENABLE_SCRIPT_DLG_TITLE, "Script disabled", "Script disabled");
	ADD_APPLICATION_STRING2(BRS_STR_ID_HTTP_TO_HTTPS_DLG_MSG, "Entering secure connection, continue?", "Entering secure connection, continue?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_HTTPS_TO_HTTP_DLG_MSG, "Connection no longer secure, continue?", "Connection no longer secure, continue?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_INPUT_TITLE, "Input", "Input");
	ADD_APPLICATION_STRING2(BRS_STR_ID_INVALID_INPUT, "Invalid input! Proceed?", "Invalid input! Proceed?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_JAM_CONFIRM, "Start midlet?", "Start midlet?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_1, "Do you wish to load this object of mime-type = [", "Do you wish to load this object of mime-type = [");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_2, "], with url = [", "], with url = [");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_3, "]?", "]?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_NO_MIME_MSG_4, "Unknown", "Unknown");
	ADD_APPLICATION_STRING2(BRS_STR_ID_REDIRECT_POST, "Redirected request received. Resubmit user data?", "Redirected request received. Resubmit user data?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESEND_POST, "Do you want to resubmit user data?", "Do you want to resubmit user data?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_RESET, "Reset", "Reset");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAS_DOWNLOAD_CANCEL, "Downloading was canceled!", "Downloading was canceled!");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAS_DOWNLOAD_ERROR, "An error occurred.", "An error occurred.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAS_DOWNLOAD_SUCCESS, "File successfully saved.", "File successfully saved.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SAVE_COMPLETE_TITLE, "Save complete", "Save complete");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SCRIPT_DISABLED_NOTIFICATION, "This site uses scripts. Scripting support is disabled", "This site uses scripts. Scripting support is disabled");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SECURITY, "Security", "Security");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUBMIT, "Submit", "Submit");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_2WAY_NAVIGATION, "2 Way navigation", "2 Way navigation");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_4WAY_NAVIGATION, "4 Way navigation", "4 Way navigation");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_FRAMES_AS_LINKS, "This page contains frames. In order to view the content of a frame, navigate to it and press select.", "This page contains frames. In order to view the content of a frame, navigate to it and press select.");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_FULL, "Standard", "Standard");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_NARROW, "Screen Optimized", "Screen Optimized");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_TEXT, "Text only", "Text only");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_REND_WRAP, "Text Wrap", "Text Wrap");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_SCROLLING_NAVIGATION, "Scrolling", "Scrolling");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_CREATING, "Creating Thumbnail", "Creating Thumbnail");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_FRAME_PAGE, "Page contains frames, no thumbnail will be created", "Page contains frames, no thumbnail will be created");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_THUMBNAIL_SMALL_PAGE, "No need for a thumbnail", "No need for a thumbnail");
	ADD_APPLICATION_STRING2(BRS_STR_ID_SUI_ZOOM, "Zoom:", "Zoom:");
	ADD_APPLICATION_STRING2(BRS_STR_ID_UNHANDLED_CONTENT_TYPE, "Unknown content type! Download anyway?", "Unknown content type! Download anyway?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_UNSECURE_CONTENT, "This page contains both secure and nonsecure items. Do you want to display the nonsecure items?", "This page contains both secure and nonsecure items. Do you want to display the nonsecure items?");
	ADD_APPLICATION_STRING2(BRS_STR_ID_WML_SCRIPT_ALERT_TITLE, "WML script", "WML script");

    /* MMA */
    ADD_APPLICATION_IMAGE2(MMA_IMG_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_MMSAT.pbm", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LOCK_MODE, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SB_MMSLOCK.pbm", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_JAVA, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Jsr\\\\mms_messagejsr.pbm", "");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_h.pbm", "read forward-locked mms message icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read_l.pbm", "read forward-locked mms message icon with low priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_h.pbm", "unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_l.pbm", "unread forward-lock mms icon with high priority");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock.pbm", "unread forward-lock mms icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_FORWARD_LOCK_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\lock\\\\mms_lock_read.pbm", "read forward-locked mms message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message.pbm", "mms unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread.pbm", "mms read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_h.pbm","mms high priority read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_READ_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_messageread_l.pbm","mms low priority read message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_PRIO_HIGH, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_h.pbm", "mms high priority unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_PRIO_LOW, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\message\\\\mms_message_l.pbm", "mms low priority unread message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_NOTIF, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\notification\\\\notification.pbm", "mms notification icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_LETTER_CREATED, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\draft\\\\mmsdraft.pbm", "mms draft message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_RR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read.pbm","mms read report message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_RR_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\readreport\\\\mms_read_read.pbm","mms read report message read icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_DR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery.pbm","mms delivery report message icon");
    ADD_APPLICATION_IMAGE2(MMA_IMG_DR_READ, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\deliveryreport\\\\mms_delivery_read.pbm","mms delivery report message read icon");

    ADD_APPLICATION_STRING2(MMA_STR_ID_MESSAGE_CORRUPT, "[Corrupted MMS]", "[Corrupted MMS]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_DELIVERY_REPORT, "[Delivery Report]", "[Delivery Report]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_READ_REPORT, "[Read Report]", "[Read Report]");
    ADD_APPLICATION_STRING2(MMA_STR_ID_MMS_NO_SUBJECT, "[No Subject]", "[No Subject]");

    /* MMS */
    ADD_APPLICATION_STRING2(MMS_STR_EMPTY_STRING, " ", " ");
    ADD_APPLICATION_STRING2(MMS_STR_ID_READ_REPORT, "[Read Report]", "[Read Report]");
    ADD_APPLICATION_STRING2(MMS_STR_ID_YOUR_MESSAGE_BEEN_READ, "Your message has been read at ", "Your message has been read at ");
    ADD_APPLICATION_STRING2(MMS_STR_ID_RR_UNKNOWN_TO, "Unknown", "Unknown");

    /* PHS */
    ADD_APPLICATION_STRING2(PHS_STR_ID_UNKNOWN_SENDER, "Unknown Address", "Unknown Address");
    ADD_APPLICATION_STRING2(PHS_STR_ID_ACCEPT_MSG, "Accept", "Accept");
    ADD_APPLICATION_STRING2(PHS_STR_ID_DECLINE_MSG, "Decline", "Decline");
    ADD_APPLICATION_STRING2(PHS_STR_ID_ADD_TO_WHITELIST, "Accept and add to whitelist", "Accept and add to whitelist");
    ADD_APPLICATION_STRING2(PHS_STR_ID_ADD_TO_BLACKLIST, "Decline and add to blacklist", "Decline and add to blacklist");
    ADD_APPLICATION_STRING2(PHS_STR_ID_PUSH_TYPE_CO, "Cache Operation", "Cache Operation");
    ADD_APPLICATION_STRING2(PHS_STR_ID_PUSH_TYPE_SIR, "Session Initiation Request", "Session Initiation Request");
    ADD_APPLICATION_STRING2(PHS_STR_ID_SIR_CONFIRM_MSG, "Would you like to set up a new push connection?", "Would you like to set up a new push connection?");

    /* SES */
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_VIEW_CERTIFICATES_ITEM, "Certificates", "Certificates");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_VIEW_CONTRACTS_ITEM, "Contracts", "Contracts");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_VIEW_SESSION_INFO_ITEM, "Session info", "Session info");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_VIEW_CURRENT_CERTIFICATE_ITEM, "Current certificate", "Current certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_CHANGE_AUTH_PIN_ITEM, "Change authentication PIN", "Change authentication PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_CHANGE_SIGN_PIN_ITEM, "Change SignText PIN", "Change SignText PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_UNBLOCK_AUTH_PIN_ITEM, "Unblock authentication PIN", "Unblock authentication PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_MENU_UNBLOCK_SIGN_PIN_ITEM, "Unblock SignText PIN", "Unblock SignText PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_MAIN_MENU, "Security", "Security");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_MISSING_KEY, "Missing key", "Missing key");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORED_CONTRACTS, "Contract names", "Contract names");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CONTRACT_DETAILS, "Contract details", "Contract details");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CONFIRM, "Confirm", "Confirm");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_GEN_PIN, "Generate PIN", "Generate PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_HASH, "Hashed CA", "Hashed CA");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CERT_DETAILS, "Certificate details", "Certificate details");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORE, "Store", "Store");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_SHOW_CERT_NAMES, "Certificate Names", "Certificate Names");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CHANGE_PIN, "Change PIN", "Change PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_ENTER_PIN, "Enter PIN", "Enter PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CHOOSE_CERT, "Choose client certificate", "Choose client certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CHOOSE_CERT_PUB_KEY, "Choose signing certificate", "Choose signing certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_VALIDATION_ERROR, "Validation error", "Validation error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CLIENT_CERT, "Client certificate", "Client certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_ERROR, "Error", "Error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_OVERWRITE, "Certificate overwrite", "Certificate overwrite");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_MISSING_CERT, "Missing certificate", "Missing certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORE_SUCCEEDED, "Store succeeded", "Store succeeded");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_DELETE, "Delete", "Delete");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_PIN_CHANGED, "PIN changed", "PIN changed");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_UNBLOCK_AUTH_PIN, "Unblock PIN", "Unblock PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_UNBLOCK_SIGN_PIN, "Unblock PIN", "Unblock PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_INVALID_PIN, "Invalid PIN", "Invalid PIN");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_INVALID_PUK, "Invalid PUK", "Invalid PUK");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_STORE_ERROR, "Store error", "Store error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_DELETE_ERROR, "Delete error", "Delete error");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_SIGN_FAILED, "Signing failed", "Signing failed");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_SIGN_SUCCEEDED, "Signing successful", "Signing successful");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_PIN_BLOCKED, "PIN blocked", "PIN blocked");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_PIN_UNBLOCKED, "PIN unblocked", "PIN unblocked");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_PUK_BLOCKED, "PUK blocked", "PUK blocked");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_DIMMED, "Item unavailable", "Item unavailable");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_CURRENT_CERT, "Current certificate", "Current certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_SESSION_INFO, "Session information", "Session information");
    ADD_APPLICATION_STRING2(SES_STR_ID_TITLE_EMPTY_LIST, "Empty list", "Empty list");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE, "Store certificate?", "Store certificate?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_NOT_VERIFIED, "Could not validate the certificate. Store anyway?", "Could not validate the certificate. Store anyway?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_SAME, "Certificate with same date exists. Overwrite?", "Certificate with same date exists. Overwrite?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_NEWER, "Certificate with older date exists. Overwrite?", "Certificate with older date exists. Overwrite?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_STORE_OLDER, "Certificate with newer date exists. Overwrite?", "Certificate with newer date exists. Overwrite?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_CONNECT, "Could not validate certificate. Connect anyway?", "Could not validate certificate. Connect anyway?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_CONNECT_TEMP, "Connect and accept this certificate temporarily.", "Connect and accept this certificate temporarily.");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_CONNECT_ALWAYS, "Connect and accept this certificate permanently.", "Connect and accept this certificate permanently.");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_VIEW_CERT, "View certificate.", "View certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_CONNECT_NO_USER, "No matching client certificate found. Connect with server authentication, without client authentication?", "No matching client certificate found. Connect with server authentication, without client authentication?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_DELETE_CERT, "Delete certificate?", "Delete certificate?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_DELETE_CONTRACT, "Delete contract?", "Delete contract?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_SIGN_TEXT, "Sign text?", "Sign text?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_UNBLOCK_PIN1, "The authentication PIN is blocked. Unblock now?", "The authentication PIN is blocked. Unblock now?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONFIRM_UNBLOCK_PIN2, "The SignText PIN is blocked. Unblock now?", "The SignText PIN is blocked. Unblock now?");
    ADD_APPLICATION_STRING2(SES_STR_ID_CHOOSE_CERT, "Choose certificate", "Choose certificate");
    ADD_APPLICATION_STRING2(SES_STR_ID_CANCEL, "Cancel", "Cancel");
    ADD_APPLICATION_STRING2(SES_STR_ID_BACK, "Back", "Back");
    ADD_APPLICATION_STRING2(SES_STR_ID_DELETE, "Delete", "Delete");
    ADD_APPLICATION_STRING2(SES_STR_ID_VIEW, "View", "View");
    ADD_APPLICATION_STRING2(SES_STR_ID_STORE, "Store", "Store");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_AUTH_PUK, "Enter authentication PUK:", "Enter authentication PUK:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_SIGN_PUK, "Enter SignText PUK:", "Enter SignText PUK:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_ENTER, "Enter new PIN:", "Enter new PIN:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_ENTER_AGAIN, "Re-enter new PIN:", "Re-enter new PIN:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_OPEN_WIM, "Enter PIN to the authentication key to open the secure storage:", "Enter PIN to the authentication key to open the secure storage:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_CONNECT, "Enter PIN to the authentication key to connect:", "Enter PIN to the authentication key to connect:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_SIGN_TEXT, "Enter SignText PIN:", "Enter SignText PIN:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_STORE_CERT, "Enter PIN to the authentication key to store certificate:", "Enter PIN to the authentication key to store certificate:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_DELETE_CERT, "Enter PIN to the authentication key to delete certificate:", "Enter PIN to the authentication key to delete certificate:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_DELETE_CONTRACT, "Enter PIN to the authentication key to delete contract:", "Enter PIN to the authentication key to delete contract:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_DELETE_AUTH_KEYS, "Enter authentication PUK to delete all authentication keys and connected user certificates:", "Enter authentication PUK to delete all authentication keys and connected user certificates:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_DELETE_SIGN_KEYS, "Enter SignText PUK to delete all SignText keys and connected user certificates:", "Enter SignText PUK to delete all SignText keys and connected user certificates:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_CHANGE_AUTH, "Enter old authentication PIN:", "Enter old authentication PIN:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_CHANGE_SIGN, "Enter old SignText PIN:", "Enter old SignText PIN:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_GENERATE_AUTH_KEY, "Enter authentication PIN to generate new authentication key:", "Enter authentication PIN to generate new authentication key:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_PIN_GENERATE_SIGN_KEY, "Enter authentication PIN to generate new SignText key:", "Enter authentication PIN to generate new SignText key:");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_HASH_ENTER, "Enter hash for the display name: ", "Enter hash for the display name: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_CERT_ENTER_NAME, "Enter client certificate name: ", "Enter client certificate name: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_NUM_TRIES_LEFT, "Number of tries left: ", "Number of tries left: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_PROMPT_LAST_PIN_TRY, "Last try!", "Last try!");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_STORED, "Certificate has been stored.", "Certificate has been stored.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_NOT_STORED, "Certificate could not be stored.", "Certificate could not be stored.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_DELETED, "Certificate has been deleted.", "Certificate has been deleted.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_NOT_DELETED, "Certificate could not be deleted.", "Certificate could not be deleted.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CERT_NOT_SHOWN, "Could not show the certificate.", "Could not show the certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CONTRACT_DELETED, "Contract has been deleted.", "Contract has been deleted.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CONTRACT_NOT_DELETED, "Contract could not be deleted.", "Contract could not be deleted.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_CONTRACT_NOT_SHOWN, "Could not show the contract.", "Could not show the contract.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_AUTH_PIN_CHANGED, "The authentication PIN is now changed.", "The authentication PIN is now changed.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_SIGN_PIN_CHANGED, "The SignText PIN is now changed.", "The SignText PIN is now changed.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_AUTH_PIN_UNBLOCKED, "The authentication PIN is now unblocked.", "The authentication PIN is now unblocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_SIGN_PIN_UNBLOCKED, "The SignText PIN is now unblocked.", "The SignText PIN is now unblocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_SIGN_SUCCEEDED, "The text has been signed.", "The text has been signed.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_NO_CERTS, "Certificate list is empty.", "Certificate list is empty.");
    ADD_APPLICATION_STRING2(SES_STR_ID_INFO_NO_CONTRACTS, "Contract list is empty.", "Contract list is empty.");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_CONNECTION_TYPE, "Connection type", "Connection type");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_SSL, "SSL", "SSL");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS, "TLS", "TLS");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS, "WTLS", "WTLS");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_SERVER_AUTH, "Server authenticated", "Server authenticated");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_CLIENT_AUTH, "Client authenticated", "Client authenticated");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_YES, "Yes", "Yes");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_NO, "No", "No");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_HMAC_ALG, "HMAC algorithm", "HMAC algorithm");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_SHA1, "SHA-1", "SHA-1");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_MD5, "MD5", "MD5");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_HMAC_KEY_LEN, "HMAC key length", "HMAC key length");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_ALG, "Encryption algorithm", "Encryption algorithm");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_NULL, "NULL", "NULL");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC5, "RC5", "RC5");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC5_40, "RC5 40", "RC5 40");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC5_56, "RC5 56", "RC5 56");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC5_64, "RC5 64", "RC5 64");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_3DES, "Triple DES", "Triple DES");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC4_40, "RC4 40", "RC4 40");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC4_128, "RC4 128", "RC4 128");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_DES_40, "DES 40", "DES 40");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_DES, "DES", "DES");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_RC4_56, "RC4 56", "RC4 56");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_AES_128, "AES 128", "AES 128");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_ENCR_KEY_LEN, "Encryption key length", "Encryption key length");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_KEY_EXCH_ALG, "Key exchange algorithm", "Key exchange algorithm");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_NULL, "NULL", "NULL");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_SHARED_SECRET, "Shared secret", "Shared secret");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_DH_ANON, "DH ANON", "DH ANON");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_DH_ANON_512, "DH ANON 512", "DH ANON 512");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_DH_ANON_768, "DH ANON 768", "DH ANON 768");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_RSA_ANON, "RSA ANON", "RSA ANON");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_RSA_ANON_512, "RSA ANON 512", "RSA ANON 512");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_RSA_ANON_768, "RSA ANON 768", "RSA ANON 768");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_RSA, "RSA", "RSA");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_RSA_512, "RSA 512", "RSA 512");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_RSA_768, "RSA 768", "RSA 768");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_ECDH_ANON, "ECDH ANON", "ECDH ANON");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_ECDH_ANON_113, "ECDH ANON 113", "ECDH ANON 113");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_ECDH_ANON_131, "ECDH ANON 131", "ECDH ANON 131");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_WTLS_KEY_EXCH_ECDH_ECDSA, "ECDH ECDSA", "ECDH ECDSA");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_NULL, "NULL", "NULL");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_RSA, "RSA", "RSA");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_RSA_EXPORT, "RSA Export", "RSA Export");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DH_DSS_EXPORT, "DH DSS Export", "DH DSS Export");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DH_DSS, "DH DSS", "DH DSS");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DH_RSA_EXPORT, "DH RSA Export", "DH RSA Export");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DH_RSA, "DH RSA", "DH RSA");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DHE_DSS_EXPORT, "DHE DSS Export", "DHE DSS Export");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DHE_DSS, "DHE DSS", "DHE DSS");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DHE_RSA_EXPORT, "DHE RSA Export", "DHE RSA Export");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DHE_RSA, "DHE RSA", "DHE RSA");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DH_ANON_EXPORT, "DH ANON Export", "DH ANON Export");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_DH_ANON, "DH ANON", "DH ANON");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_TLS_KEY_EXCH_RSA_EXPORT1024, "RSA Export 1024", "RSA Export 1024");
    ADD_APPLICATION_STRING2(SES_STR_ID_SESS_KEY_EXCH_KEY_LEN, "Key exchange key length", "Key exchange key length");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_LOCATION, "Storage location: ", "Storage location: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_PHONE, "Phone memory", "Phone memory");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_SIM, "SIM card", "SIM card");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_VAL_NOT_BEF, "Valid not before: ", "Valid not before: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_VAL_NOT_AFT, "Valid not after: ", "Valid not after: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_ISSUER, "Issuer: ", "Issuer: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_SUBJECT, "Subject: ", "Subject: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_SERIAL_NO, "Serial number: ", "Serial number: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CERT_FINGERPRINT, "Fingerprint (MD5): ", "Fingerprint (MD5): ");
    ADD_APPLICATION_STRING2(SES_STR_ID_CONTRACT, "Contract: ", "Contract: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_SIGNATURE, "Signature: ", "Signature: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_TIME, "Time: ", "Time: ");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PIN_TOO_LONG, "The PIN was too long.", "The PIN was too long.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PIN_TOO_SHORT, "The PIN was too short.", "The PIN was too short.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PIN_MISMATCH, "The new PIN values did not match.", "The new PIN values did not match.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PIN_FALSE, "Wrong PIN code entered.", "Wrong PIN code entered.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_HASH_FALSE, "The wrong hash was entered.", "The wrong hash was entered.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PIN1_LOCKED, "The authentication PIN is blocked. Use the security menu in order to unblock the authentication PIN.", "The authentication PIN is blocked. Use the security menu in order to unblock the authentication PIN.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PIN2_LOCKED, "The SignText PIN is blocked. Use the security menu in order to unblock the SignText PIN.", "The SignText PIN is blocked. Use the security menu in order to unblock the SignText PIN.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_INVALID_KEY, "The key is invalid.", "The key is invalid.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_KEY_LENGTH, "The key length is invalid.", "The key length is invalid.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_UNKNOWN_CERTIFICATE_TYPE, "Unknown certificate type.", "Unknown certificate type.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_MATCHING_ROOT_CERTIFICATE, "Client does not have a matching CA certificate.", "Client does not have a matching CA certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_BAD_CERTIFICATE, "Bad certificate.", "Bad certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_CERTIFICATE, "Missing certificate.", "Missing certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NOT_FOUND, "Not found.", "Not found.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_INVALID_COMMON_NAME, "Invalid common name.", "Invalid common name.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_PUK, "Missing PUK.", "Missing PUK.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_WRONG_PUK, "Wrong PUK code entered.", "Wrong PUK code entered.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_AUT_KEY_OPEN_WIM, "No authentication key was found when opening the secure storage.", "No authentication key was found when opening the secure storage.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_KEY_CONNECT, "No authentication key was found when trying to connect.", "No authentication key was found when trying to connect.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_KEY_STORE_CERT, "No authentication key was found when trying to store a certificate.", "No authentication key was found when trying to store a certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_KEY_DELETE_CERT, "No authentication key was found when trying to delete a certificate.", "No authentication key was found when trying to delete a certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_KEY_DELETE_CONTRACT, "No authentication key was found when trying to delete a contract.", "No authentication key was found when trying to delete a contract.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_KEY_CHANGE_AUTH, "No authentication key was found when trying to change it.", "No authentication key was found when trying to change it.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_KEY_CHANGE_SIGN, "No SignText key was found when trying to change it.", "No SignText key was found when trying to change it.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_NR_KEY_SIGN_TEXT, "No SignText key was found when trying to sign a text.", "No SignText key was found when trying to sign a text.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PRIV_KEY_NOT_FOUND, "No private key found.", "No private key found.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_WIM_NOT_INITIALISED, "WIM not initialized.", "WIM not initialized.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_INTERNAL_ERROR, "Internal error.", "Internal error.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SIGN_OTHER_ERROR, "Signing error.", "Signing error.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SIGN_MISSING_CERTIFICATE, "Missing SignText certificate.", "Missing SignText certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_CA_CERTIFICATE_EXPIRED, "The certificate has expired.", "The certificate has expired.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_CERTIFICATE_EXPIRED, "The certificate has expired.", "The certificate has expired.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_IS_ROOT_CERTIFICATE, "Root certificate (not CA), i.e. cannot validate.", "Root certificate (not CA), i.e. cannot validate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_MISSING_GATEWAY_CERT, "Gateway has not sent a certificate.", "Gateway has not sent a certificate.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PUK1_LOCKED, "The authentication PUK is blocked. Contact customer center.", "The authentication PUK is blocked. Contact customer center.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PUK2_LOCKED, "The SignText PUK is blocked. Contact customer center.", "The SignText PUK is blocked. Contact customer center.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_PUKS_LOCKED, "The authentication PUK and the SignText PUK are blocked. Contact customer center.", "The authentication PUK and the SignText PUK are blocked. Contact customer center.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_FILE_SYSTEM, "Cannot access the file system.", "Cannot access the file system.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_GENERAL_ERROR, "General error.", "General error.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_REACHED_USER_CERT_LIMIT, "Certificate store is full.", "Certificate store is full.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_AUTH_PIN, "No authentication PIN exists.", "No authentication PIN exists.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_SIGN_PIN, "No SignText PIN exists.", "No SignText PIN exists.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_AUTH_PIN_BLOCKED, "Authentication PIN blocked.", "Authentication PIN blocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SIGN_PIN_BLOCKED, "SignText PIN blocked.", "SignText PIN blocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_AUTH_PUK, "No authentication PUK exists.", "No authentication PUK exists.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_SIGN_PUK, "No SignText PUK exists.", "No SignText PUK exists.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_AUTH_PUK_BLOCKED, "Authentication PUK blocked.", "Authentication PUK blocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SIGN_PUK_BLOCKED, "SignText PUK blocked.", "SignText PUK blocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SESSION_INFO_MISSING, "No session active.", "No session active.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SESSION_CERT_MISSING, "No session certificate available.", "No session certificate available.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_AUTH_PIN_NOT_BLOCKED, "Authentication PIN is not blocked.", "Authentication PIN is not blocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_SIGN_PIN_NOT_BLOCKED, "SignText PIN is not blocked.", "SignText PIN is not blocked.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_CERTIFICATES, "No certificates stored.", "No certificates stored.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_NO_CONTRACTS, "No contracts stored.", "No contracts stored.");
    ADD_APPLICATION_STRING2(SES_STR_ID_ERR_LOCKED_CERTIFICATE, "The certificate can not be deleted.", "The certificate can not be deleted.");

	/* OWL */
	ADD_APPLICATION_STRING2(OWL_STR_ID_TRUNCATE, ".....", ".....");
	ADD_APPLICATION_STRING2(OWL_STR_ID_PADDING, "  ", "  ");
	ADD_APPLICATION_STRING2(OWL_STR_ID_RM_ERROR_DLG_TITLE, "Skin Error", "Skin Error");
	ADD_APPLICATION_STRING2(OWL_STR_ID_RM_ERROR_DLG_BODY, "Loading default skin!", "Loading default skin!");
	ADD_APPLICATION_STRING2(OWL_STR_ID_RM_ERROR_DLG_BODY_VERSION, "Wrong skin version, restoring to default skin!", "Wrong skin version, restoring to default skin!");

	/* OWL PICTOGRAM */
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\up.bmp", "Image of pictogram up");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\down.bmp", "Image of pictogram down");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_RIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\right.BMP", "Image of pictogram right");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_LEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\left.BMP", "Image of pictogram left");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_UPPERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\upperright.bmp", "Image of pictogram uppperright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_UPPERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\upperleft.BMP", "Image of pictogram upperleft");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_LOWERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\lowerright.bmp", "Image of pictogram lowerright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_LOWERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\lowerleft.BMP", "Image of pictogram lowerleft");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERUP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerup.bmp", "Image of pictogram fingerup");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERDOWN, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerdown.bmp", "Image of pictogram fingerdown");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerright.bmp", "Image of pictogram fingerright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ARROW_FINGERLEFT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\Arrow\\\\fingerleft.bmp", "Image of pictogram fingerleft");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_1, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\1.bmp", "Image of pictogram button 1");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_2, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\2.bmp", "Image of pictogram button 2");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_3, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\3.bmp", "Image of pictogram button 3");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_4, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\4.bmp", "Image of pictogram button 4");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_5, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\5.bmp", "Image of pictogram button 5");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_6, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\6.bmp", "Image of pictogram button 6");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_7, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\7.bmp", "Image of pictogram button 7");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_8, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\8.bmp", "Image of pictogram button 8");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_9, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\9.bmp", "Image of pictogram button 9");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_BUTTON_0, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\button\\\\0.bmp", "Image of pictogram button 0");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_MAKEPHONECALL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\makephonecall.bmp", "Image of pictogram action makephonecall");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_FIND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\find.bmp", "Image of pictogram action find");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_USERAUTHENTICATION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\userauthentication.bmp", "Image of pictogram action userauthentication");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_PASSWORD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\password.bmp", "Image of pictogram action password");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_NEXTITEM, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\nextitem.bmp", "Image of pictogram action nextitem");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_CLEAR, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\clear.bmp", "Image of pictogram action clear");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_STOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\stop.bmp", "Image of pictogram action stop");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_TOP, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\top.bmp", "Image of pictogram action top");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_NEXT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\next.bmp", "Image of pictogram action next");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_ACTION_BACK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\action\\\\back.bmp", "Image of pictogram action back");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_RECEIVE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\receive.bmp", "Image of pictogram message receive");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_SEND, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\send.bmp", "Image of pictogram message send");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_MESSAGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\message.bmp", "Image of pictogram message message");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_DOCUMENT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\document.bmp", "Image of pictogram message document");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_ATTACHMENT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\attachment.bmp", "Image of pictogram message attachment");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_FOLDER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\folder.bmp", "Image of pictogram message folder");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_INBOX, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\inbox.bmp", "Image of pictogram message inbox");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MESSAGE_OUTBOX, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\message\\\\outbox.bmp", "Image of pictogram message outbox");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_SECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\secure.bmp", "Image of pictogram state secure");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_INSECURE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\insecure.bmp", "Image of pictogram state insecure");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_COPYRIGHT, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\copyright.bmp", "Image of pictogram state copyright");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_TRADEMARK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\trademark.bmp", "Image of pictogram state trademark");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_UNDERCONSTRUCTION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\underconstruction.bmp", "Image of pictogram state underconstruction");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_STATE_BEGINNER, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\state\\\\beginner.bmp", "Image of pictogram state beginner");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_BOOK, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\book.bmp", "Image of pictogram media book");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_VIDEO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\video.bmp", "Image of pictogram media video");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_CD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\cd.bmp", "Image of pictogram media cd");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_DVD, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\dvd.bmp", "Image of pictogram media dvd");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_GAME, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\game.bmp", "Image of pictogram media game");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_RADIO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\radio.bmp", "Image of pictogram media radio");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_MEDIA_TV, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\media\\\\tv.bmp", "Image of pictogram media tv");

	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_NOTICE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\notice.bmp", "Image of pictogram info notice");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_CHARGED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\charged.bmp", "Image of pictogram info charged");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_FREEOFCHARGE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\freeofcharge.bmp", "Image of pictogram info freeofcharge");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_NEW, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\new.bmp", "Image of pictogram info new");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_POSITION, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\position.bmp", "Image of pictogram info position");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_TOLLFREE, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\tollfree.bmp", "Image of pictogram info tollfree");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_SHARPDIAL, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\sharpdial.bmp", "Image of pictogram info sharpdial");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_RESERVED, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\reserved.bmp", "Image of pictogram info reserved");
	ADD_APPLICATION_IMAGE2(OWL_IMAGE_ID_PICT_CORE_INFO_SPEECHINFO, CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\pictogram\\\\core\\\\info\\\\speechinfo.bmp", "Image of pictogram info speechinfo");

	/* OWL Adp */
	ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_INPUT_TITLE, "Input", "Input");
	//ADD_APPLICATION_STRING2(OWL_ADP_STR_ID_CANT_SWITCH_INPUT_METHOD,"Can't Set Input Method","Can't Set Input Method");

    ADD_APPLICATION_IMAGE2(OWL_ADP_IMAGE_WAP_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SV.PBM","WAP Menu Item Icon");

	ADD_APPLICATION_MENUITEM((OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,0,3,
		OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
		OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
		OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
		SHOW, NONMOVEABLE,
		DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_DONE,
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_DONE,NULL));

	ADD_APPLICATION_MENUITEM((
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_CANCEL,
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_CANCEL,NULL));

	ADD_APPLICATION_MENUITEM((
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION_INPUT_METHOD,
				OWL_ADP_MENU_FULLSCREEN_EDITOR_OPTION,
				0, SHOW, NONMOVEABLE,
				DISP_LIST,STR_GLOBAL_INPUT_METHOD,NULL));

    /* VDS */
    ADD_APPLICATION_STRING2(VDS_STR_ID_LOADING, "Loading.", "loading video text.");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_LOADING,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_loading.bmp","VDS loading icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_PLAY,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_play.bmp","vid playing icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_BROKEN,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_broken.bmp","VDS broken icon");
    ADD_APPLICATION_IMAGE2(VDS_IMG_ID_AUDIO,CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\vds\\\\vds_audio.bmp","VDS audio icon");

#elif (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
	PopulateJaatayuMMSRes();
#endif
#ifdef __MMI_MMS_2__
	PopulateMMSAppResource();
#endif
}
#endif


