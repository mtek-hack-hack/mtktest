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
 *	Res_UnifiedComposer.c
 *
 * Project:
 * --------
 *	MAUI
 *
 * Description:
 * ------------
 *	This file populates resource for Unified Composer.
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
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_RES_UC_C
#define _MMI_RES_UC_C
#include "MMI_features.h"

#ifdef __MMI_UNIFIED_COMPOSER__

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "UnifiedComposerResDef.h"
#include "UnifiedMessageResDef.h"

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"


/**************************************************************

	FUNCTION NAME		: PopulateUnifiedComposerResData

  	PURPOSE				: Register all the resources required by Unified Composer

	INPUT PARAMETERS	: void

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: nil

**************************************************************/
void PopulateUnifiedComposerResData (void)
{
	ADD_APPLICATION_STRING2 (STR_UC_INSERT_ID, "Insert", "Unified composer insert menu item string");
	ADD_APPLICATION_STRING2 (STR_UC_REMOVE_ID, "Remove", "Unified composer remove menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_REPLACE_ID, "Replace", "Unified composer replace menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_PREVIEW_ID, "Preview", "Unified composer preview menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SLIDE_OPTION_ID, "Slide Option", "Unified composer slide option menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_OPTION_ID, "Send Option", "Unified composer send option menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_MESSAGE_DETAIL_ID, "Message Detail", "Unified composer message detail menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_MESSAGE_TYPE_ID, "Message Type", "Unified composer message type setting menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_ADD_NUMBER_ID, "Add Number", "Unified composer add number menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_ADD_EMAIL_ID, "Add E-mail Address", "Unified composer add email address menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_ADD_NUMBER_BY_GROUP_ID, "Add Number by Group", "Unified composer add number by group menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_ADD_EMAIL_BY_GROUP_ID, "Add E-mail Address by Group", "Unified composer add email address by group menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_AND_SAVE_ID, "Send and Save", "Unified composer send and save menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_BACK_TO_EDIT_MSG_ID, "Back to Edit Message", "Unified composer back to edit msg menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_EXIT_ID, "Exit", "Unified composer exit menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_RESEND_ID, "Resend", "Unified composer resend menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_IMAGE_ID, "Image", "Unified composer image menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_AUDIO_ID, "Audio", "Unified composer audio menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_VIDEO_ID, "Video", "Unified composer video menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_TEXT_TEMPLATE_ID, "Text Template", "Unified composer text template menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_ATTACHMENT_ID, "Attachment", "Unified composer attachment menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_INSERT_NEW_SLIDE_ID, "Insert New Slide", "Unified composer insert new slide menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_DELETE_SLIDE_ID, "Delete Slide", "Unified composer delete slide menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_PREVIOUS_SLIDE_ID, "Previous Slide", "Unified composer previous slide menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_NEXT_SLUIDE_ID, "Next Slide", "Unified composer next slide menu item string");    
    ADD_APPLICATION_STRING2 (STR_UC_SLIDE_TIMING_ID, "Slide Time", "Unified composer slide timing menu item string");        
    ADD_APPLICATION_STRING2 (STR_UC_TO_ID, "To", "Unified composer to menu item string");        
    ADD_APPLICATION_STRING2 (STR_UC_CC_ID, "Cc", "Unified composer cc menu item string");        
    ADD_APPLICATION_STRING2 (STR_UC_BCC_ID, "Bcc", "Unified composer bcc menu item string");        
    ADD_APPLICATION_STRING2 (STR_UC_SUBJECT_ID, "Subject", "Unified composer subject menu item string");        
    ADD_APPLICATION_STRING2 (STR_UC_RECIPIENTS_ID, "Recipients", "Unified composer recipients menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_MSG_DETAIL_RECIPIENTS_ID, "Recipients No.", "Unified composer msg detail recipients string");    
    ADD_APPLICATION_STRING2 (STR_UC_CHANGED_TO_TEXT_MSG_ID, "Changed to Text Msg", "Unified composer type changed to SMS notification string");            
    ADD_APPLICATION_STRING2 (STR_UC_CHANGED_TO_MULTIMEDIA_MSG_ID, "Changed to Multimedia Msg", "Unified composer type changed to MMS notification string");            
    ADD_APPLICATION_STRING2 (STR_UC_TO_OPTION_ID, "To Option", "Unified composer to option title string");        
    ADD_APPLICATION_STRING2 (STR_UC_CC_OPTION_ID, "Cc Option", "Unified composer cc option title string");        
    ADD_APPLICATION_STRING2 (STR_UC_BCC_OPTION_ID, "Bcc Option", "Unified composer bcc option title string");        
    ADD_APPLICATION_STRING2 (STR_UC_MSG_SIZE_EXCEED_ID, "Msg Size Exceed", "Unified composer msg size exceed string");        
    ADD_APPLICATION_STRING2 (STR_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO_ID, "Size Not Enough(at least 30K)", "Unified composer size not enough for video string");        
    ADD_APPLICATION_STRING2 (STR_UC_ADDR_LENGTH_EXCEED_ID, "Address Length Exceed", "Unified composer address length exceed string");            
    ADD_APPLICATION_STRING2 (STR_UC_TEXT_MESSAGE_ID, "Text Message", "Unified composer text message string");
    ADD_APPLICATION_STRING2 (STR_UC_MULTIMEDIA_MESSAGE_ID, "Multimedia Message", "Unified composer multimedia message string");
    ADD_APPLICATION_STRING2 (STR_UC_PAGES_ID, "Pages No.", "Unified composer Number of Pages string");
    ADD_APPLICATION_STRING2 (STR_UC_TOTAL_MESSAGES_ID, "Total Messages", "Unified composer Total Messages string");
    ADD_APPLICATION_STRING2 (STR_UC_SIZE_ID, "Size", "Unified composer Size string");
    ADD_APPLICATION_STRING2 (STR_UC_FORWARD_ID, "Forward", "Unified composer Forward string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_ID, "Send", "Unified composer Send string");
    ADD_APPLICATION_STRING2 (STR_UC_PROHIBIT_BY_CREATION_MODE_ID, "Prohibited by Creation Mode", "Unified composer Prohibited by Creation Mode string");
    ADD_APPLICATION_STRING2 (STR_UC_NO_SPACE_ID, "No Space", "Unified composer No space string");
    ADD_APPLICATION_STRING2 (STR_UC_REMOVED_ID, "Removed", "Unified composer Removed string");
    ADD_APPLICATION_STRING2 (STR_UC_PLEASE_WAIT_ID, "Please Wait", "Unified composer Please Wait string");
    ADD_APPLICATION_STRING2 (STR_UC_MMS_ID, "MMS", "Unified composer MMS string");
    ADD_APPLICATION_STRING2 (STR_UC_STORAGE_FULL_ID, "Storage Full!", "Unified composer Storage Full string");      
    ADD_APPLICATION_STRING2 (STR_UC_FAIL_TO_INSERT_SIGNATURE_ID, "Fail to Insert Signature", "Unified composer Fail to Insert Signature string");      
    ADD_APPLICATION_STRING2 (STR_UC_DISCARD_EDITED_MSG_ID, "Discard Previous Edited Msg", "Unified composer Fail to Insert Signature string");            
	ADD_APPLICATION_STRING2 (STR_UC_WRITE_MSG_ID, "Write Message", "Unified composer write msg menu item String");      
    ADD_APPLICATION_STRING2 (STR_UC_STORAGE_FULL_DELETE_FILE_ID, "Storage Full! Please Delete File", "Unified composer Storage Full string");      
    ADD_APPLICATION_STRING2 (STR_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID, "Template List Already Full", "Template List Already Full string");      
    ADD_APPLICATION_STRING2 (STR_UC_STORAGE_FILE_IO_ERROR_ID, "File IO Error", "File IO Error string");      
    ADD_APPLICATION_STRING2 (STR_UC_STORAGE_FULL_MSG_CONTENT_LOSS_ID, "Storage Full! Msg Content Lost", "Unified composer Storage Full string");      
    ADD_APPLICATION_STRING2 (STR_UC_NO_RECEPIENT_ADDR_ID, "No Recepient Address", "Unified composer No Recepient Address string");          
    ADD_APPLICATION_STRING2 (STR_UC_CREATING_ID, "Creating", "Unified composer Creating string");          
    ADD_APPLICATION_STRING2 (STR_UC_SENDING_MMS_ID, "Sending MMS", "Unified composer Sending MMS string");          
    ADD_APPLICATION_STRING2 (STR_UC_SENT_ID, "Sent", "Unified composer Sent string");          
    ADD_APPLICATION_STRING2 (STR_UC_ABORT_FAIL_ID, "Abort Fail", "Unified composer Abort Fail string");              
    ADD_APPLICATION_STRING2 (STR_UC_ABORTED_ID, "Aborted", "Unified composer Aborted string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_SUCCESS_SAVE_SUCCESS, "Sent and Stored", "Unified composer Sent and Stored string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_SUCCESS_SAVE_FAIL, "Sent but Save Failed", "Unified composer Sent but Save Failed string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_FAIL_SAVE_SUCCESS, "Not Sent, Stored in Outbox", "Unified composer Not Sent, Stored in Outbox string");
    ADD_APPLICATION_STRING2 (STR_UC_SEND_FAIL_SAVE_FAIL, "Send and Save Failed", "Unified composer Send and Save Failed string");
    ADD_APPLICATION_STRING2 (STR_UC_CONTENT_ERROR_ID, "Content Error", "Unified composer content error string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_ID, "Validity Period", "Unified composer Validity Period string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_1_HOUR_ID, "1 Hour", "Unified composer Validity Period 1 Hour string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_6_HOUR_ID, "6 Hours", "Unified composer Validity Period 6 Hours string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_12_HOUR_ID, "12 Hours", "Unified composer Validity Period 12 Hours string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_1_DAY_ID, "1 Day", "Unified composer Validity Period 1 Day string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_1_WEEK_ID, "1 Week", "Unified composer Validity Period 1 Week string");
    ADD_APPLICATION_STRING2 (STR_UC_VALIDITY_PERIOD_MAX_ID, "Maximum", "Unified composer Validity Period Max string");
    ADD_APPLICATION_STRING2 (STR_UC_DELIVERY_REPORT_ID, "Delivery Report", "Unified composer Delivery Report string");
    ADD_APPLICATION_STRING2 (STR_UC_READ_REPORT_ID, "Read Report", "Unified composer Read Report string");
    ADD_APPLICATION_STRING2 (STR_UC_PRIORITY_ID, "Priority", "Unified composer Priority string");
    ADD_APPLICATION_STRING2 (STR_UC_PRIORITY_LOW_ID, "Low", "Unified composer Priority Low string");
    ADD_APPLICATION_STRING2 (STR_UC_PRIORITY_MEDIUM_ID, "Normal", "Unified composer Priority Normal string");
    ADD_APPLICATION_STRING2 (STR_UC_PRIORITY_HIGH_ID, "High", "Unified composer Priority High string");
    ADD_APPLICATION_STRING2 (STR_UC_DELIVERY_TIME_ID, "Delivery Time", "Unified composer Delivery Time string");
    ADD_APPLICATION_STRING2 (STR_UC_DELIVERY_TIME_IMMEDIATE_ID, "Immediate", "Unified composer Delivery Time Immediate string");
    ADD_APPLICATION_STRING2 (STR_UC_DELIVERY_TIME_1_HOUR_ID, "1 Hour Later", "Unified composer Delivery Time In 1 Hour string");
    ADD_APPLICATION_STRING2 (STR_UC_DELIVERY_TIME_12_HOUR_ID, "12 Hours Later", "Unified composer Delivery Time In 12 Hours string");
    ADD_APPLICATION_STRING2 (STR_UC_DELIVERY_TIME_24_HOUR_ID, "24 Hours Later", "Unified composer Delivery Time In 24 Hours string");    
    ADD_APPLICATION_STRING2 (STR_UC_ALLOW_ID, "Allow", "Unified composer Allow string");
    ADD_APPLICATION_STRING2 (STR_UC_NOT_ALLOW_ID, "Not Allow", "Unified composer Not ALLOW string");
    ADD_APPLICATION_STRING2 (STR_UC_ADDRESS_NUMBER_EXCEED_ID, "Number of Address Exceed", "Unified composer Address number exceed string");
    ADD_APPLICATION_STRING2 (STR_UC_GO_TO_SOME_SLIDE_ID, "Go To Some Slide", "Unified composer Go To Some Slide string");
    ADD_APPLICATION_STRING2 (STR_UC_DUPLICATE_ADDRESS_ID, "Duplicate Address", "Unified composer Duplicate Address string");    
    ADD_APPLICATION_STRING2 (STR_UC_PHB_NUMBER_ID, "Phonebook Number", "Unified composer Phonebook Number string");    
    ADD_APPLICATION_STRING2 (STR_UC_PHB_NAME_ID, "Phonebook Name", "Unified composer Phonebook Name string");    
    ADD_APPLICATION_STRING2 (STR_UC_BOOKMARK_ID, "Bookmark", "Unified composer bookmark string");
    ADD_APPLICATION_STRING2 (STR_UC_NOT_SUPPORT_ID, "Not Support", "Unified composer Not Support string");        
    ADD_APPLICATION_STRING2 (STR_UC_UNSUPPORT_CONTENT_ID, "Unrecognized Format", "Unified composer Unrecognized Format string");        
    ADD_APPLICATION_STRING2 (STR_UC_CREATION_MODE_MAX_MSG_SIZE_REACHED_ID, "Creation Mode: Msg Size Excceed", "Unified composer Creation Mode: Msg Size Excceed string");        
    ADD_APPLICATION_STRING2 (STR_UC_MAX_SLIDE_NUM_REACHED_ID, "Slide Number Exceed", "Unified composer Slide Number Exceed string");        
    ADD_APPLICATION_STRING2 (STR_UC_TOO_MANY_MSG_ID, "Maximum message number reached. Please delete some messages.", "Unified composer Maximum message number reached. Please delete some messages. string");        
    ADD_APPLICATION_STRING2 (STR_UC_CONFIG_ERROR_ID, "Incorrect Profile Setting", "Unified composer Incorrect Profile Setting string");        
    ADD_APPLICATION_STRING2 (STR_UC_CONNECT_ERROR_ID, "Communication Failed", "Unified composer Communication Failed string");        
    ADD_APPLICATION_STRING2 (STR_UC_SERVER_TIMEOUT_ID, "Server Timeout", "Unified composer Server Timeout string");        
    ADD_APPLICATION_STRING2 (STR_UC_SERVER_ERROR_ID, "Unknown Server Error", "Unified composer Unknown Server Error string");        
    ADD_APPLICATION_STRING2 (STR_UC_SERVICE_DENIED_ID, "Service Denied", "Unified composer Service Denied string");        
    ADD_APPLICATION_STRING2 (STR_UC_UNSUPPORT_CONTENT_BY_SERVER_ID, "Content Rejected by Server", "Unified composer Content Rejected by Server string");        
    ADD_APPLICATION_STRING2 (STR_UC_UNKNOWN_APN_ID, "Unknown APN", "Unified composer Unknown APN string");        
    ADD_APPLICATION_STRING2 (STR_UC_UNAUTHORIZED_ID, "Unauthorized Request", "Unified composer Unauthorized Request string");        
    ADD_APPLICATION_STRING2 (STR_UC_SEND_FAIL_ID, "Send Failed, Saved to Outbox", "Unified composer Send Failed string");        
    ADD_APPLICATION_STRING2 (STR_UC_SYSTEM_RESOURCES_EXHAUSTED_ID, "System Resource Exhausted", "Unified composer System Resource Exhausted string");        
    ADD_APPLICATION_STRING2 (STR_UC_FILE_CORRUPT_ID, "File Corrupted", "Unified composer File Corrupted string");        
    ADD_APPLICATION_STRING2 (STR_UC_FILE_EMPTY_ID, "File Empty", "Unified composer File Empty string");   
    ADD_APPLICATION_STRING2 (STR_UC_FAIL_TO_RESIZE_IMAGE_ID, "Failed to Resize Image", "Unified composer Failed to Resize Image string"); 
    ADD_APPLICATION_STRING2 (STR_UC_SLIDE_TEXT_TIMING_ID, "Text Timing", "Unified composer text timing menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SLIDE_IMAGE_TIMING_ID, "Image Timing", "Unified composer image timing menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SLIDE_AUDIO_TIMING_ID, "Audio Timing", "Unified composer audio timing menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SLIDE_VIDEO_TIMING_ID, "Video Timing", "Unified composer video timing menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_START_TIME_ID, "Start Time", "Unified composer start time menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_END_TIME_ID, "End Time", "Unified composer end time menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_EXCEED_SLIDE_TIME_ID, "Exceed Slide Time", "Unified composer Exceed Slide Time string");
    ADD_APPLICATION_STRING2 (STR_UC_NEW_IMAGE_ID, "From Camera", "Unified composer new image menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_NEW_AUDIO_ID, "From Sound Recorder", "Unified composer new audio menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_NEW_VIDEO_ID, "From Video Recorder", "Unified composer new video menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_INSERT_NEW_SLIDE_AFTER_ID, "Insert New Slide After", "Unified composer insert new slide after menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_INSERT_NEW_SLIDE_BEFORE_ID, "Insert New Slide Before", "Unified composer insert new slide before menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_SAVE_AS_TEMPLATE_ID, "Save as Template", "Unified composer Save as Template menu item string");
    ADD_APPLICATION_STRING2 (STR_UC_ADDR_LENGTH_TOO_SHORT_ID, "Address Length Too Short", "Unified composer address length too short string");            
    ADD_APPLICATION_STRING2 (STR_UC_LESS_THAN_MEDIA_TIME_ID, "Less Than Media Time", "Unified composer less than media time string");                
    ADD_APPLICATION_STRING2 (STR_UC_PREVIEW_SLIDE_LIST, "Slide List", "Unified composer Slide List Screen Title");
    ADD_APPLICATION_STRING2 (STR_UC_PREVIEW_GOTO, "Goto ", "Unified composer Goto Slide after Preview"); 
    ADD_APPLICATION_STRING2 (STR_UC_PREVIEW_SLIDE, "Slide", "Unified composer Slide Word to concat with Number"); 
        
    ADD_APPLICATION_STRING2 (STR_UC_CAN_NOT_PLAY_COMPLETE, "Not complete,OK?", "Can't play complete media object,OK?");        
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
    ADD_APPLICATION_STRING2(STR_UC_MMS_SIZE_CONFIRM_MSG_1, "The size of MMS is ", "size confirmation part1");
    ADD_APPLICATION_STRING2(STR_UC_MMS_SIZE_CONFIRM_MSG_2, "KB, send it?",        "size confirmation part2");
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/

    ADD_APPLICATION_STRING2 (STR_UC_INTERVAL_INFIX_ID, "and", "Unified composer interval infix string");
    ADD_APPLICATION_STRING2 (STR_UC_INTERVAL_PREFIX_ID, "Input value between", "Unified composer interval prefix string");                
    ADD_APPLICATION_STRING2 (STR_UC_SERVER_ID, "Server: ", "Unified composer mma return result prefix string");                
    
	ADD_APPLICATION_IMAGE2 (IMG_UC_SETTING_MSG_TYPE_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Setting\\\\UC_MGType.pbm",
							 	"UC Msg type Settings menu item Image");

	ADD_APPLICATION_IMAGE2 (IMG_UC_ENTRY_SCRN_CAPTION_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_MG.PNG",
								"UC Menu item common Image");

	ADD_APPLICATION_IMAGE2 (IMG_UC_TO_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_To.PBM",
							 	"UC TO address Icon");

	ADD_APPLICATION_IMAGE2 (IMG_UC_CC_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_CC.PBM",
								"UC CC address Icon");

	ADD_APPLICATION_IMAGE2 (IMG_UC_BCC_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_BCC.PBM",
							 	"UC BCC address Icon");

	ADD_APPLICATION_IMAGE2 (IMG_UC_SUBJECT_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_SB.PBM",
								"UC subject icon");

	ADD_APPLICATION_IMAGE2 (IMG_UC_MSG_DETAIL_ID,
								CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Creat\\\\UC_Detail.pbm",
							 	"UC message detail icon");

    ADD_APPLICATION_IMAGE2 (IMG_UC_DRM_THUMBNAIL_ID,
                              CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\DRM.gif",
                              "UC DRM prohibited image");
    
    ADD_APPLICATION_IMAGE2 (IMG_UC_VALIDITY_PERIOD_ID,
                                  CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Setting\\\\UC_period.pbm",
                                    "UC validity period icon");

    ADD_APPLICATION_IMAGE2 (IMG_UC_DELIVERY_REPORT_ID,
                                  CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Setting\\\\UC_Deliveryreport.pbm",
                                    "UC delivery report icon");

    ADD_APPLICATION_IMAGE2 (IMG_UC_READ_REPORT_ID,
                                  CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Setting\\\\UC_Readreport.pbm",
                                    "UC read report icon");    

    ADD_APPLICATION_IMAGE2 (IMG_UC_PRIORITY_ID,
                                  CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Setting\\\\UC_Priority.pbm",
                                    "UC priority icon");

    ADD_APPLICATION_IMAGE2 (IMG_UC_DELIVERY_TIME_ID,
                                  CUST_IMG_PATH"\\\\MainLCD\\\\UniComposer\\\\Setting\\\\UC_Deliverytime.pbm",
                                    "UC delivery time icon");


	/* UC option menu  */
	ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT,
    							0,	UC_OPT_TOTAL_NUM,
    							MENU_ID_UC_OPT_DONE,
                                MENU_ID_UC_OPT_INSERT,
                                MENU_ID_UC_OPT_REMOVE,
                                MENU_ID_UC_OPT_REPLACE,
                                MENU_ID_UC_OPT_PREVIEW,
                                MENU_ID_UC_OPT_SLIDE_OPT,
                                MENU_ID_UC_OPT_MSG_TYPE_OPT,
                                MENU_ID_UC_OPT_SEND_OPT,
                                MENU_ID_UC_OPT_MSG_DETAIL,
                                MENU_ID_UC_OPT_INPUT_METHOD,										
    							SHOW,	MOVEABLEWITHINPARENT,	DISP_LIST,
    							STR_GLOBAL_OPTIONS,	0));

    /* Done */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE,
    							MENU_ID_UC_OPT,	0,
    							SHOW,	MOVEABLEWITHINPARENT,	DISP_LIST,
    							STR_GLOBAL_DONE, 0));

    /* Address */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR,
                                0,  UC_OPT_ADDR_TOTAL_NUM,
                                MENU_ID_UC_OPT_ADDR_DONE,
                                MENU_ID_UC_OPT_ADDR_ADD_NUMBER,
                                MENU_ID_UC_OPT_ADDR_ADD_EMAIL,
                                MENU_ID_UC_OPT_ADDR_EDIT,
                                MENU_ID_UC_OPT_ADDR_DELETE,
                                MENU_ID_UC_OPT_ADDR_DELETE_ALL,
                                MENU_ID_UC_OPT_ADDR_ADD_NUMBER_GROUP,
                                MENU_ID_UC_OPT_ADDR_ADD_EMAIL_GROUP,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_OK, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_DONE,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_DONE, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_ADD_NUMBER,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ADD_NUMBER_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_ADD_EMAIL,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ADD_EMAIL_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_EDIT,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_EDIT, 0)); 

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_DELETE,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_DELETE, 0)); 

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_DELETE_ALL,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_DELETE_ALL, 0)); 

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_ADD_NUMBER_GROUP,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ADD_NUMBER_BY_GROUP_ID, 0)); 
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_ADDR_ADD_EMAIL_GROUP,
                                MENU_ID_UC_OPT_ADDR, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ADD_EMAIL_BY_GROUP_ID, 0));     

    /* Done option */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UC_OPT_DONE_OPT,
                                0,  
                                MENU_ID_UC_OPT_DONE_SEND,
                                MENU_ID_UC_OPT_DONE_SEND_AND_SAVE,
                                MENU_ID_UC_OPT_DONE_SAVE,
                            #if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
                                MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE,
                            #endif
                                MENU_ID_UC_OPT_DONE_BACK_TO_EDIT_MSG,
                                MENU_ID_UC_OPT_DONE_MSG_TYPE,
                                MENU_ID_UC_OPT_DONE_SEND_OPT,
                                MENU_ID_UC_OPT_DONE_EXIT,
                                MENU_ITEM_END,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_OK, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_SEND,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_SEND, 0));     

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_SEND_AND_SAVE,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SEND_AND_SAVE_ID, 0));     
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_SAVE,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_SAVE, 0));     
#if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SAVE_AS_TEMPLATE_ID, 0));        
#endif /* __MMI_MMS_2__ */

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_BACK_TO_EDIT_MSG,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_BACK_TO_EDIT_MSG_ID, 0));     
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_MSG_TYPE,
                            MENU_ID_UC_OPT_DONE_OPT, 0,
                            SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                            STR_UC_MESSAGE_TYPE_ID, 0)); 
    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_SEND_OPT,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SEND_OPTION_ID, 0));     

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_DONE_EXIT,
                                MENU_ID_UC_OPT_DONE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_EXIT_ID, 0));     
    

    /* Insert */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UC_OPT_INSERT,
                                MENU_ID_UC_OPT,
                                MENU_ID_UC_OPT_INSERT_IMAGE,
                            #ifdef __MMI_CAMERA__
                                MENU_ID_UC_OPT_INSERT_NEW_IMAGE,
                            #endif /* __MMI_CAMERA__ */
                                MENU_ID_UC_OPT_INSERT_AUDIO,
                            #ifdef __MMI_SOUND_RECORDER__
                                MENU_ID_UC_OPT_INSERT_NEW_AUDIO,
                            #endif /* __MMI_SOUND_RECORDER__ */
                                MENU_ID_UC_OPT_INSERT_VIDEO,
                            #ifdef __MMI_VIDEO_RECORDER__
                                MENU_ID_UC_OPT_INSERT_NEW_VIDEO,
                            #endif /* __MMI_VIDEO_RECORDER__ */
                                MENU_ID_UC_OPT_INSERT_TEXT_TEMPLATE,
                                MENU_ID_UC_OPT_INSERT_ATTACHMENT,
                                MENU_ID_UC_OPT_INSERT_PHB_NUMBER,
                                MENU_ID_UC_OPT_INSERT_PHB_NAME,
                                MENU_ID_UC_OPT_INSERT_BOOKMARK,
                                MENU_ITEM_END,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_INSERT_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_IMAGE,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_IMAGE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_AUDIO,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_AUDIO_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_VIDEO,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_VIDEO_ID, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_TEXT_TEMPLATE,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_TEXT_TEMPLATE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_ATTACHMENT,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ATTACHMENT_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_PHB_NUMBER,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_PHB_NUMBER_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_PHB_NAME,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_PHB_NAME_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_BOOKMARK,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_BOOKMARK_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_NEW_IMAGE,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_NEW_IMAGE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_NEW_AUDIO,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_NEW_AUDIO_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INSERT_NEW_VIDEO,
                                MENU_ID_UC_OPT_INSERT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_NEW_VIDEO_ID, 0));
    
    /* Remove */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REMOVE,
                                MENU_ID_UC_OPT,  UC_OPT_REMOVE_TOTAL_NUM,
                                MENU_ID_UC_OPT_REMOVE_IMAGE,
                                MENU_ID_UC_OPT_REMOVE_AUDIO,
                                MENU_ID_UC_OPT_REMOVE_VIDEO,
                                MENU_ID_UC_OPT_REMOVE_ATTACHMENT,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_REMOVE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REMOVE_IMAGE,
                                MENU_ID_UC_OPT_REMOVE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_IMAGE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REMOVE_AUDIO,
                                MENU_ID_UC_OPT_REMOVE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_AUDIO_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REMOVE_VIDEO,
                                MENU_ID_UC_OPT_REMOVE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_VIDEO_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REMOVE_ATTACHMENT,
                                MENU_ID_UC_OPT_REMOVE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ATTACHMENT_ID, 0));     

    /* Replace */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REPLACE,
                                MENU_ID_UC_OPT,  UC_OPT_REPLACE_TOTAL_NUM,
                                MENU_ID_UC_OPT_REPLACE_IMAGE,
                                MENU_ID_UC_OPT_REPLACE_AUDIO,
                                MENU_ID_UC_OPT_REPLACE_VIDEO,
                                MENU_ID_UC_OPT_REPLACE_ATTACHMENT,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_REPLACE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REPLACE_IMAGE,
                                MENU_ID_UC_OPT_REPLACE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_IMAGE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REPLACE_AUDIO,
                                MENU_ID_UC_OPT_REPLACE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_AUDIO_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REPLACE_VIDEO,
                                MENU_ID_UC_OPT_REPLACE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_VIDEO_ID, 0));    

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_REPLACE_ATTACHMENT,
                                MENU_ID_UC_OPT_REPLACE, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_ATTACHMENT_ID, 0));


    /* Preview */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_PREVIEW,
                                MENU_ID_UC_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_PREVIEW_ID, 0));

    /* Slide option */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UC_OPT_SLIDE_OPT,
                                MENU_ID_UC_OPT,
                        		MENU_ID_UC_OPT_SLIDE_OPT_INSERT,
                        		MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE,
                                MENU_ID_UC_OPT_SLIDE_OPT_DELETE,
                                MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS,
                                MENU_ID_UC_OPT_SLIDE_OPT_NEXT,
                                MENU_ID_UC_OPT_SLIDE_OPT_GO_TO,
                                MENU_ID_UC_OPT_SLIDE_OPT_TIMING,
                            #ifdef __MMI_MMS_2__
                                MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING,
                            #endif /* __MMI_MMS_2__ */
                                MENU_ITEM_END,
                        		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                        		STR_UC_SLIDE_OPTION_ID,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_INSERT,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_INSERT_NEW_SLIDE_AFTER_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_INSERT_NEW_SLIDE_BEFORE_ID, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_DELETE,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_DELETE_SLIDE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_PREVIOUS_SLIDE_ID, 0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_NEXT,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_NEXT_SLUIDE_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_GO_TO,
                                MENU_ID_UC_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_GO_TO_SOME_SLIDE_ID, 0)); 
    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SLIDE_TIMING_ID, 0));    

#ifdef __MMI_MMS_2__

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SLIDE_TEXT_TIMING_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SLIDE_IMAGE_TIMING_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SLIDE_AUDIO_TIMING_ID, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING,
                                MENU_ID_UC_OPT_SLIDE_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SLIDE_VIDEO_TIMING_ID, 0));
#endif /* __MMI_MMS_2__ */    

    /* Msg type */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_MSG_TYPE_OPT,
                                MENU_ID_UC_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_MESSAGE_TYPE_ID, 0));    
       
    /* Send option */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_SEND_OPT,
                                MENU_ID_UC_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_SEND_OPTION_ID, 0));

    /* Message detail */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_MSG_DETAIL,
                                MENU_ID_UC_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_MESSAGE_DETAIL_ID, 0));

    /* Input method */    
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_OPT_INPUT_METHOD,
                                MENU_ID_UC_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_INPUT_METHOD, 0));

    /* Msg type setting */
    ADD_APPLICATION_MENUITEM((MENU_ID_UC_SETTING_PREFERRED_TYPE,
                                MENU_ID_UM_SETTING,  0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_MESSAGE_TYPE_ID, IMG_UC_SETTING_MSG_TYPE_ID));       

    /* Exit */
    ADD_APPLICATION_MENUITEM2((MENU_ID_UC_EXIT_OPT,0,
                        		MENU_ID_UC_EXIT_OPT_SAVE, 
                        		MENU_ID_UC_EXIT_OPT_EXIT, 
                                MENU_ITEM_END,
                        		SHOW, MOVEABLEWITHINPARENT, DISP_LIST, 
                        		STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_EXIT_OPT_SAVE,
                                MENU_ID_UC_EXIT_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_GLOBAL_SAVE, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_UC_EXIT_OPT_EXIT,
                                MENU_ID_UC_EXIT_OPT, 0,
                                SHOW,   MOVEABLEWITHINPARENT,   DISP_LIST,
                                STR_UC_EXIT_ID, 0));
    	
}
#endif
#endif  //#ifndef __MMI_UNIFIED_COMPOSER__
#endif  //#ifndef _MMI_RES_UC_C

