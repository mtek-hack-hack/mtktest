
/**************************************************************

	FILENAME	: Res_CmsMms.c

  	PURPOSE		: Populate Resource for MMS

	REMARKS		: nil

	AUTHOR		: 

	DATE		: 

**************************************************************/
#ifdef CMS_NEW_APP
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "MMI_features.h"


#include "MmsResourceData.h"
#include "WapResourceData.h"
#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"




/* ----------------------------------------------------------------------------
 * Function Name: PopulateCmsMMSResData
 *       Purpose: 
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void PopulateCmsMMSResData (void)
{
	/*----------------------------------------------------------------*/
	/*Add string                                             */
	/*----------------------------------------------------------------*/
	
	/*---   1   MMS MAIN -----------------------*/
	ADD_APPLICATION_STRING2 (STR_CMS_MMS_MENUENTRY, "MMS", "MMS menu item String");

	ADD_APPLICATION_STRING2 (STR_CMS_MESSAGE_MENUENTRY, "Message", "message menu item String");

	ADD_APPLICATION_STRING2 (STR_NEW_SMS_MMS, "New Message", "write new mms");
	ADD_APPLICATION_STRING2 (STR_MMS_WMESSAGE, "New Mms", "write new mms");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX, "Inbox", "Inbox");
	ADD_APPLICATION_STRING2 (STR_MMS_OUTBOX, "Outbox", "Outbox");
	ADD_APPLICATION_STRING2 (STR_MMS_DRAFTBOX, "Draftbox", "Draftbox");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES, "Mms Templates", "Mms Templates");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_MENUENTRY, "Mms Setting", "Mms setting");
	ADD_APPLICATION_STRING2 (STR_MMS_MEMORY_STATUS, "Mms Memory Status", "Mms Memory Status");

	ADD_APPLICATION_STRING2 (STR_SMS_MMS_TEMPLATES, "Message Templates", "Message Templates");
	ADD_APPLICATION_STRING2 (STR_SMS_MMS_SETTING, "Message Setting", "Message Setting");
	ADD_APPLICATION_STRING2 (STR_SMS_MMS_MEMORY_STATUS, "Memory Status", "Memory Status");
	ADD_APPLICATION_STRING2 (STR_SMS_MEMORY_STATUS, "Sms Memory Status", "Sms Memory Status");
	
	/*---   1-1  NEW MESSAGE  -----------------------*/
	ADD_APPLICATION_STRING2 ( STR_MMS_TO_ID, "To", "mms to String");
	ADD_APPLICATION_STRING2 ( STR_MMS_CC_ID, "Cc", "mms cc String");
	ADD_APPLICATION_STRING2 ( STR_MMS_BCC_ID, "Bcc", "mms Bcc String");
	ADD_APPLICATION_STRING2 ( STR_MMS_SUBJECT_ID, "Subject", "mms Subject String");
	ADD_APPLICATION_STRING2 ( STR_MMS_CONTENT_ID, "Content", "mms Content String");
	ADD_APPLICATION_STRING2 (STR_MMS_SEND_OPTIONS, "Send Options", "Send Options");

	/*---   1-1-1  Sendto Options  -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_SENDTO_OPTIONS, "Sendto Options", "Sendto Options");
	ADD_APPLICATION_STRING2 (STR_MMS_ID_ADD_NUMBER, "Add Number", "Add Number");
	ADD_APPLICATION_STRING2 (STR_MMS_ID_ADD_EMAIL, "Add E-mail", "Add E-mail");
	
	/*---   1-1-5  Edit Options  -----------------------*/
	ADD_APPLICATION_STRING2 (STR_EDIT_OPTIONS, "Edit Options", "Edit Options");

	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_EDITTEXT, "Text Edit", "Text Edit");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_EMPTYTEXT, "Clear Text", "Clear Text");	
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_INSERTNEWIMAGE, "Add Image", "insert new image");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_DELCURRENTIMAGE, "Remove Image", "delete current image");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_ADDMUSIC, "Add Music", "add music");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_DELCURRENTMUSIC, "Remove Music", "delete current music");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_INSERTNEWACCESSORY, "Add Accessory", "insert new accessory");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_DELCURRENTACCESSORY, "Remove Accessory", "delete current accessory");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_FRAMETIME, "Frame Time", "Frame Time");
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_INSERTNEWFRAME, "New Frame", "insert new frame");	
	ADD_APPLICATION_STRING2 (STR_MMS_CONTENT_OPTIONS_DELCURRENTFRAME, "Delete Frame", "Delete Currentframe");
	
	/*---   1-1-6   Send Option -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_SEND_OPTIONS_SEND, "Send", "Send message");
	ADD_APPLICATION_STRING2 (STR_MMS_SEND_OPTIONS_VIEW, "View", "view message");
	ADD_APPLICATION_STRING2 (STR_MMS_SEND_OPTIONS_SAVE, "Save", "Save message");
	ADD_APPLICATION_STRING2 (STR_MMS_SEND_OPTIONS_SEND_SAVE, "Send Then Save", "Send then save");

	/*---   1-2   INBOX -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS, "Inbox Options", "Inbox Options");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_REPLY, "Reply", "reply msg");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_DETAILS, "Details", "details of message");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_FORWARD, "Forward", "forward msg");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_SAVE_IMAGE, "Save Images", "save images");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_SAVE_MUSIC, "Save Music", "save music");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_SAVE_ACCESSORY, "Save Accessories", "save accessories");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_GET_DETAILS, "Get Number", "get number");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_DOWNLOAD, "Download", "download msg");

	/*---   1-2-1-3   view details -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_NUM_USAGE, "Usage", "Usage");
	ADD_APPLICATION_STRING2 (STR_MMS_MEMORY_USED, "Used", "Used");
	ADD_APPLICATION_STRING2 (STR_MMS_MEMORY_REMAIN, "Remain", "Remain");
	
	/*---   1-2-1-5   save image -----------------------*/
	ADD_APPLICATION_STRING2 (STR_IMAGE_SAVE, "Image List", "Image");
	ADD_APPLICATION_STRING2 (STR_MMS_IMAGE, "Image", "Image");
	
	/*---   1-2-1-6   save music -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MUSIC_SAVE, "Music List", "Music");
	ADD_APPLICATION_STRING2 (STR_MMS_MUSIC, "Music", "Music");
	ADD_APPLICATION_STRING2 (STR_ACCESSORY_SAVE, "Accessory List", "Accessory");
	ADD_APPLICATION_STRING2 (STR_MMS_ACCESSORY, "Accessory", "Accessory");
	
	/*---   1-2-2-1 push download   -----------------------*/


	/*---   1-3   OUTBOX   -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_OUTBOX_OPTIONS, "Outbox Options", "Outbox Options");
	

	/*---   1-4   DRAFTBOX   -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_DRAFTBOX_OPTIONS, "Draftbox Options", "Draftbox Options");

	/*---   1-5   TEMPLATES   -----------------------*/
	
	/*---   1-6   MMS SETTING   -----------------------*/

	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_SEND_OPTIONS, "Send Setting", "Send Setting");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_RECEIVE_OPTIONS, "Receive Setting", "Send Setting");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_MMSC_OPTIONS, "Mmsc Setting", "Mmsc Setting");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_NET_OPTIONS, "Net Setting", "Net Setting");
	
	/*---   1-6-1   Send Setting   -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_EXPIRES, "Expires", "Expires");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_DELIVERY_RPT, "Delivery Report", "delivery report");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_ANONYMOUS, "Anonymous Send", "Anonymous Send");
	ADD_APPLICATION_STRING2 (	STR_MMS_SETTINGS_READ_REPORT, "Read Report", "Read Report");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_PRIORITY, "Priority", "Priority Setting");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_MAX_SEND, "Max Send", "Max Send");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_FRAME_TIME, "Frame Time", "Frame Time");

	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_PRIORITY_LOW, "Low", "low priority");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_PRIORITY_NORMAL, "Normal", "normal priority");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_PRIORITY_HIGH, "High", "high priority");

	ADD_APPLICATION_STRING2 (STR_MSG_SETTINGS_ON, "On", "on");
	ADD_APPLICATION_STRING2 (STR_MSG_SETTINGS_OFF, "Off", "off");
	
	/*---   1-6-2   Retrieve Setting   -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_RETRIEVE_MODE, "Retrieve Mode", "Retrieve Mode Setting");
	ADD_APPLICATION_STRING2 (STR_MSG_SETTINGS_RETRIEVEMODE_MANUAL, "Manual", "manual  retrieve");
	ADD_APPLICATION_STRING2 (STR_MSG_SETTINGS_RETRIEVEMODE_AUTO, "Auto", "auto retrieve");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_MAX_RECEIVE, "Max Retrieve", "Max Retrieve");
	
	/*---   1-6-3   Mmsc Setting   -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_NETWORK_CFG_MMSCENTRE, "MMS Centre", "mms centre");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_NETWORK_CFG_GATEWAY, "Gateway", "mms gateway");
	ADD_APPLICATION_STRING2 (STR_CMCC_CENTRE_ADDRESS, "http://mmsc.monternet.com/", "centre address");
	ADD_APPLICATION_STRING2 (STR_CMCC_GATEWAY, "10.0.0.172", "gateway");
	ADD_APPLICATION_STRING2 (STR_MMS_PORT, "Port", "Port");
	
	/*---   1-6-4   Net Setting   -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_GSM_MODE, "GSM Mode", "GSM Mode");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_GPRS_MODE, "GPRS Mode", "GPRS Mode");
	
	/*---   1-7   MEMORY STATUS   -----------------------*/

	
	/*---   Globa   String -----------------------*/
	ADD_APPLICATION_STRING2 (STR_MMS_NEXT_SLIDE, "Next Frame", "Next frame");
	ADD_APPLICATION_STRING2 (STR_MMS_PREV_SLIDE, "Previous Frame", "Previous frame");
	ADD_APPLICATION_STRING2 (STR_MMS_REPLY, "Re", "Reply");
	ADD_APPLICATION_STRING2 (STR_MMS_FORWARD, "Fw", "Forward");
	ADD_APPLICATION_STRING2 (STR_MMS_PLAY, "Play", "play message");
	ADD_APPLICATION_STRING2 (STR_MMS_STOPPREV, "Stop", "stop");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTINGS_PLAYMUSIC, "Play Music", "Play music");

	ADD_APPLICATION_STRING2 (STR_MMS_REPLY_MMS, "MMS Reply", "MMS Reply");
	ADD_APPLICATION_STRING2 (STR_MMS_REPLY_SMS, "SMS Reply", "SMS Reply");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_MMS_REPLY, "MMS Reply", "MMS Reply");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_OPTIONS_SMS_REPLY, "SMS Reply", "SMS Reply");

	ADD_APPLICATION_STRING2 (STR_MMS_DELETE, "Delete", "Delete");
	ADD_APPLICATION_STRING2 (STR_MMS_DELETE_ALL, "Delete All", "Delete All");
	ADD_APPLICATION_STRING2 (STR_MMS_DELETE_ALL_MMS, "Delete All Mms", "Delete All Mms");

	ADD_APPLICATION_STRING2 (STR_REMOVE_CONFIRM, "Remove Confirm", "remove confirm or not");
	ADD_APPLICATION_STRING2 (STR_REMOVE_OK, "Remove OK", "remove ok");
	ADD_APPLICATION_STRING2 (STR_DELETE_CONFIRM, "Delete Confirm", "delete confirm or not");
	ADD_APPLICATION_STRING2 (STR_DELETE_OK, "Delete OK", "delete ok");

	
	ADD_APPLICATION_STRING2 (STR_MMS_DOWNLOAD_CHECK, "Check Download", "Check Download");
	ADD_APPLICATION_STRING2 (STR_RETRIEVE_NOW, "Retrieve Now", "retrieve now or not");
	ADD_APPLICATION_STRING2 (STR_MMS_RETRIEVING, "Retrieving", "Retrieving message");
	ADD_APPLICATION_STRING2 (STR_RETRIEVE_OK, "Retrieve OK", "retrieve ok");
	ADD_APPLICATION_STRING2 (STR_MMS_SENDING, "Sending", "sending message");
	ADD_APPLICATION_STRING2 (STR_SEND_OK, "Send OK", "Send OK");
	
	ADD_APPLICATION_STRING2 (STR_SEND_LIST_NULL, "To Address is Empty", "address is empty");
	ADD_APPLICATION_STRING2 (STR_MORE_ADDRESS, "More To Addresses", "more To addresses");
	ADD_APPLICATION_STRING2 (STR_MMS_SENDTO_OPTIONS_ADD, "Add", "Add Sendto");
	ADD_APPLICATION_STRING2 (STR_MMS_SENDTO_OPTIONS_DELETE, "Remove", "Delete Sendto");

	ADD_APPLICATION_STRING2 (STR_SAVE_MESSAGE, "Save Message", "save message or not");	
	ADD_APPLICATION_STRING2 (STR_SAVE_OK, "Save OK", "save ok");
	ADD_APPLICATION_STRING2 (STR_SEND_SAVE_OK, "Send and Save OK", "Send and Save OK");



	ADD_APPLICATION_STRING2 (STR_ILLEGAL_INPUT, "Illegal Input", "Illegal input");
	ADD_APPLICATION_STRING2 (STR_FILE_EXISTED, "File Existed", "File existed");
	ADD_APPLICATION_STRING2 (STR_TYPE_ERROR, "Media Type Error", "Media type error");
	ADD_APPLICATION_STRING2 (STR_CONTENT_NULL, "Message Content is Empty", "content empty");

	
	ADD_APPLICATION_STRING2 (STR_SET_CONFIRMED, "Set Confirmed", "message config set confirmed");
	ADD_APPLICATION_STRING2 (STR_MMS_FILE_PROCESS_ERROR, "File Process Error", "File Process Error");
	ADD_APPLICATION_STRING2 (STR_MMS_NUMBER_REPEAT, "Number Repeated", "Number Repeated");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_ERROR, "MMS SETTING Error", "MMS SETTING Error");
	ADD_APPLICATION_STRING2 (STR_MMS_CANCLE_SUCESS, "MMS Cancel Success", "MMS Cancel Success");

	
	ADD_APPLICATION_STRING2 (STR_SIZE_OVERFLOW, "Beyond Max Size", "beyond max size");
	ADD_APPLICATION_STRING2 (STR_ADDRESS_ERROR, "Illegal To Address", "Illegal To address");
	ADD_APPLICATION_STRING2 (STR_SEND_FAILED, "Send Failed", "Send failed");
	ADD_APPLICATION_STRING2 (STR_RETRIEVE_FAILED, "Retrieve Failed", "Retrieve failed");
	ADD_APPLICATION_STRING2 (STR_MESSAGE_ARRIVED, "Multimedia message arrived", "new mms arrived");
	ADD_APPLICATION_STRING2 (STR_RETRIEVED_MMS, "retrieved message", "retrieved message");


	ADD_APPLICATION_STRING2 (STR_NO_SUBJECT, "No Subject", "No subject");	
	ADD_APPLICATION_STRING2 (STR_NOTIFICATION, "Notification", "notification");
	ADD_APPLICATION_STRING2 (STR_MMS_MSG_SIZE, "Message Size:", "Message Size:");	
	ADD_APPLICATION_STRING2 (STR_MMS_EDIT, "Edit", "edit message");	
	
	ADD_APPLICATION_STRING2 (STR_MMS_SLIDE_NUM, "The", "The");
	ADD_APPLICATION_STRING2 (STR_MMS_FRAME, "Frame", "Frame");
	ADD_APPLICATION_STRING2 (STR_MMS_HINT_FRAMES, "frame(s)", "frame(s)");
	ADD_APPLICATION_STRING2 (STR_MMS_HINT_MESSAGES, "message(s)", "message(s)");
	ADD_APPLICATION_STRING2 (STR_MMS_SENDER, "Sender", "sender");
	ADD_APPLICATION_STRING2 (STR_MMS_HINT_RECEIVER, "receivers", "receivers");
	
	ADD_APPLICATION_STRING2 (STR_MMS_INPUT_EMPTY, "Input Empty", "Input Empty");
	ADD_APPLICATION_STRING2 (STR_MMS_MEDIA_FILE_ERROR, "Media File Error", "Media File Error");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_NO_IMAGE, "No Image", "No Image");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_NO_MUSIC, "No Music", "No Music");
	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_NO_ACCESSORY, "No Accessory", "No Accessory");
	ADD_APPLICATION_STRING2 (STR_MMS_COMPLETE, "Confirm", "Confirm");
	

	ADD_APPLICATION_STRING2 (STR_MMS_SIZE_REACHED_MAX, "Reached Max Size", "Reached Max Size");
	ADD_APPLICATION_STRING2 (STR_MMS_COUNT_REACHED_MAX, "Reached Max Count", "Reached Max Count");
	ADD_APPLICATION_STRING2 (STR_MMS_SIZE_WILL_REACH_MAX, "Reach Max Size Soon", "Reach Max Size Soon");
	ADD_APPLICATION_STRING2 (STR_MMS_COUNT_WILL_REACH_MAX, "Reach Max Count Soon", "Reach Max Count Soon");
	ADD_APPLICATION_STRING2 (STR_MMS_MORE_FRAME_FORWARD, "Cannot forward message over 20 frames", "Cannot forward message over 20 frames");

	ADD_APPLICATION_STRING2 (STR_MMS_MAX_30K_FORWARD, "Cannot forward message over 30K", "Cannot forward message over 30K");
	ADD_APPLICATION_STRING2 (STR_MMS_MAX_50K_FORWARD, "Cannot forward message over 50K", "Cannot forward message over 50K");
	ADD_APPLICATION_STRING2 (STR_MMS_MAX_70K_FORWARD, "Cannot forward message over 70K", "Cannot forward message over 70K");
	ADD_APPLICATION_STRING2 (STR_MMS_MAX_100K_FORWARD, "Cannot forward message over 100K", "Cannot forward message over 100K");
	ADD_APPLICATION_STRING2 (STR_MMS_FLASH_WRITE_ERROR, "Fail to save message", "Fail to save message");
	ADD_APPLICATION_STRING2 (STR_MMS_WRONG_NOTIFICATION, "Invalid notification", "Invalid push message");
	ADD_APPLICATION_STRING2 (STR_MMS_SAVE_MEDIA_FORMAT_UNKNOWN, "Media format unknown", "cannot save media which format is unknown");
	ADD_APPLICATION_STRING2 (STR_MMS_PUSH_OPERATING, "Message is retrieving", "avoid operate the retrieving PUSH message");
	ADD_APPLICATION_STRING2 (STR_MMS_SIZE_TOO_BIG, "MMS Too Big", "MMS Too Big");
	
	ADD_APPLICATION_STRING2 (STR_MMS_QUOTA_EXCEEDED, "MMS Quota Exceeded Remain:", "MMS Quota Exceeded Remain:");
	ADD_APPLICATION_STRING2 (STR_EXPIRED_MMS, "message expired", "message expired");
	ADD_APPLICATION_STRING2 (STR_REJECTED_MMS, "message rejected", "message rejected");

	ADD_APPLICATION_STRING2 (STR_MMS_SENT, "Sent", "Sent");
	ADD_APPLICATION_STRING2 (STR_MMS_CREATE, "Create", "Create");

	ADD_APPLICATION_STRING2 (STR_EMPTY_INBOX, "Empty Inbox", "Empty Inbox");
	ADD_APPLICATION_STRING2 (STR_EMPTY_OUTBOX, "Empty Outbox", "Empty Outbox");
	ADD_APPLICATION_STRING2 (STR_EMPTY_DRAFTBOX, "Empty Draftbox", "Empty Draftbox");
	ADD_APPLICATION_STRING2 (STR_EMPTY_ALLBOX, "Empty All Boxes", "Empty all boxes");
	ADD_APPLICATION_STRING2 (STR_EMPTY_OK, "Empty OK", "Empty OK");
	ADD_APPLICATION_STRING2 (STR_MMS_REACHED_MAX, "MMS Too Big", "MMS Too Big");

	ADD_APPLICATION_STRING2 (STR_MMS_INBOX_IS_EMPTY, "Inbox is empty", "Inbox is empty");
	ADD_APPLICATION_STRING2 (STR_MMS_OUTBOX_IS_EMPTY, "Outbox is empty", "Outbox is empty");
	ADD_APPLICATION_STRING2 (STR_MMS_DRAFTBOX_IS_EMPTY, "Draftbox is empty", "Draftbox is empty");

	ADD_APPLICATION_STRING2 (STR_MMS_ONE_HOUR, "One Hour", "One Hour");
	ADD_APPLICATION_STRING2 (STR_MMS_ONE_DAY, "One Day", "One Day");
	ADD_APPLICATION_STRING2 (STR_MMS_ONE_WEEK, "One Week", "One Week");
	ADD_APPLICATION_STRING2 (STR_MMS_MAX, "Max", "Max");
	ADD_APPLICATION_STRING2 (STR_MMS_SETTING_SAVE, "Save Mms Setting", "Save Mms Setting");
	ADD_APPLICATION_STRING2 (STR_MMS_FRAME_TIME_VALIDATION, "Please input 1~60", "please input 1~60");
	ADD_APPLICATION_STRING2 (STR_MMS_INVALIDATION, "Indvalidation input", "Indvalidation input");
	ADD_APPLICATION_STRING2 (STR_MMS_INPUT_NULL, "Input Null ", "Input Null ");

	ADD_APPLICATION_STRING2 (STR_MMS_30K, "30K", "30K");
	ADD_APPLICATION_STRING2 (STR_MMS_50K, "50K", "50K");
	ADD_APPLICATION_STRING2 (STR_MMS_70K, "70K", "70K");
	ADD_APPLICATION_STRING2 (STR_MMS_100K, "100K", "100K");
	ADD_APPLICATION_STRING2 (STR_MMS_HOUR, "Hour", "Hour");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES, "Templates", "Templates");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_TITLE_01, "Templates One", "Templates One");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_TITLE_02, "Templates Two", "Templates Two");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_TITLE_03, "Templates Three", "Templates Three");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_TITLE_04, "Templates Four", "Templates Four");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_TITLE_05, "Templates Five", "Templates Five");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_OPTIONS, "Templates Options", "Templates Options");
	ADD_APPLICATION_STRING2 (STR_MMS_TEMPLATES_OPTIONS_WRITE, "Write Message", "Write Message From Template");
	ADD_APPLICATION_STRING2(STR_MMS_NO_PERSISTENT_STORAGE, "Not Enough Storage", "Not enough message storage. Delete messages to free storage space.");	
	ADD_APPLICATION_STRING2 (STR_MSG_NOT_READY_YET,		"Message Not Ready Yet","Message  not ready yet String");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_EDIT_SETTING, "Edit Setting", "Edit Setting");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_MODIFY_SERVICE_ID,"Modify Setting Name", "Modify Setting Name");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_PUSH_MESSAGE,"Wap Push", "Wap Push");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_OTA_BOOKMARK,"Bookmark name", "BookMark");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_OTA_SETTING,"Wap setting", "Wap Setting Name");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_OTA_ADD_BOOKMARK,"Add to bookmark", "BookMark");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_OTA_ADD_SETTING,"Save setting", "Wap Setting Name");
	ADD_APPLICATION_STRING2 (STR_MMS_WAP_OTA_CANNOT_SET,"Can not modify default setting", "Can not modify default setting");
	ADD_APPLICATION_STRING2 (STR_MMS_ALLBOX, "All Boxes", "all box");
	ADD_APPLICATION_STRING2 (STR_EMPTY_BOX, "Empty Box", "empty box");	
	ADD_APPLICATION_STRING2 (STR_MMS_ALLBOXES_ARE_EMPTY, "All boxes are empty", "All boxes are empty");
	ADD_APPLICATION_STRING2 (STR_MMS_NEW_MESSAGE_FROM, "Mms from", "mms from");
	ADD_APPLICATION_STRING2 (STR_MMS_WAITING, "Waiting", "Waiting");

	/*----------------------------------------------------------------*/
	/* Add image                                               */
	/*----------------------------------------------------------------*/
	ADD_APPLICATION_IMAGE2 (IMG_MESSAGE_SIM_MMS_MENUENTRY,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\MMS.gif",
							 	"MMS menu item Image");

 	ADD_APPLICATION_IMAGE2 (IMG_MMS_WMESSAGE,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\NewMsg.gif",
							 	"write new mms message");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\Inbox.gif",
							 	"mms inbox");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_OUTBOX,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\Outbox.gif",
							 	"mms outbox");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_DRAFTBOX,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\DraftBoxMms.gif",
							 	"mms draft box");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_MESSAGE_TEMPLATE,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\Template.gif",
							 	"mms Template");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_EMPTYBOX,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\EmptyBox.gif",
							 	"mms empty box");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_MESSAGE_SETTING,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\MsgSettings.gif",
							 	"mms message setting");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_MESSAGE_MEMORY,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\MainMenu\\\\Memory.gif",
							 	"mms memory");

	/*Creat MMS*/
	ADD_APPLICATION_IMAGE2 (IMG_MMS_WMESSAGE_SENDTO,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\To.gif",
							 	"send to ");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_WMESSAGE_SENDCC,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\Cc.gif",
							 	"send cc ");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_WMESSAGE_SENDBCC,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\Bcc.gif",
							 	"send bcc ");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_WMESSAGE_SUBJECT,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\Subject.gif",
							 	"subject");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_WMESSAGE_CONTENT,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\Edit.gif",
							 	"edit content");	
	ADD_APPLICATION_IMAGE2 (IMG_MMS_SEND_OPTIONS,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\SendOptions.gif",
							 	"send options");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_PICTURE_ADDED,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\PictureAdded.gif",
							 	"picture added");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_MUSIC_ADDED,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\MusicAdded.gif",
							 	"music added");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_PICTUREMUSIC_ADDED,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\Mms\\\\NewMsg\\\\PictureAndMusic.gif",
							 	"picture and music added");
	/*MMS Inbox*/
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_RPT,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\MmsDeliveryReport.gif",
							 	"mms delivery report");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_PUSH_READ,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\ReadMmsPush.gif",
							 	"read notification");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_PUSH_UNREAD,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\NoReadMmsPush.gif",
							 	"unread mms notification");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_READ,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\ReadMms.gif",
							 	"read message");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_UNREAD,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\NoReadMms.gif",
							 	"unread message");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_READREPORT,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\MmsReadReport.gif",
							 	"mms read report");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_WAPPUSH_READ,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\ReadWapPush.gif",
							 	"read wap push");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_INBOX_WAPPUSH_UNREAD,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\NoReadWapPush.gif",
							 	"unread wap push");	
	/*MMS Draftbox*/
	ADD_APPLICATION_IMAGE2 (IMG_MMS_DRAFTBOX_DRAFT,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Draftbox\\\\DraftBoxMms.gif",
							 	"draft message");
	/*MMS Outbox*/
	ADD_APPLICATION_IMAGE2 (IMG_MMS_OUTBOX_SENDT,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Outbox\\\\OutboxMmsSuccess.gif",
							 	"message sent successfully");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_OUTBOX_SENDF,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Outbox\\\\OutboxMmsFailed.gif",
							 	"message sent unsuccessfully");
	
	ADD_APPLICATION_IMAGE2 (IMG_MMS_SENDING,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Sending.gif",
							 	"sending message");

	ADD_APPLICATION_IMAGE2 (IMG_MMS_RETRIEVING,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Retrieving.gif",
							 	"retrieving message");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_PLAY_SAVE_MUSIC,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\PlayMusic.gif",
							 	"playing music");
	ADD_APPLICATION_IMAGE2 (IMG_MMS_PLAY_UNKNOW_MEDIATYPE,	
								CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Inbox\\\\Unkonwtype.gif",
							 	"unknow media type");	
#ifdef SUPPORT_MMS_TEMPLATES
   	ADD_APPLICATION_IMAGE2(IMG_MMS_TEMPLATES_01,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Template\\\\MMS_T01.gif",
								"mms template image 01 ");
   	ADD_APPLICATION_IMAGE2(IMG_MMS_TEMPLATES_02,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Template\\\\MMS_T02.gif",
								"mms template image 02 ");
   	ADD_APPLICATION_IMAGE2(IMG_MMS_TEMPLATES_03,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Template\\\\MMS_T03.gif",
								"mms template image 03 ");
   	ADD_APPLICATION_IMAGE2(IMG_MMS_TEMPLATES_04,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Template\\\\MMS_T04.gif",
								"mms template image 04 ");
   	ADD_APPLICATION_IMAGE2(IMG_MMS_TEMPLATES_05,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\WapMms\\\\MMS\\\\Template\\\\MMS_T05.gif",
								"mms template image 05 ");
#endif
	/*----------------------------------------------------------------*/
	/* Add menu                                                */
	/*----------------------------------------------------------------*/
	//main mms ----------------(New /Inbox/Outbox/Draftbox/Templates/Setting/Memory)
	ADD_APPLICATION_MENUITEM((MESSAGES_MENU_MMS_MENUID, MAIN_MENU_MESSAGES_MENUID,NUM_MMS_MAIN_MENU, 
                                                        #ifdef SUPPORT_SMSMMS_COMBINE
                                                        SMSMMS_MENU_WMESSAGE_MENUID,
                                                        #else
                                                        MMS_MENU_WMESSAGE_MENUID,
                                                        #endif
								MMS_MENU_INBOX_MENUID,
								MMS_MENU_OUTBOX_MENUID,
								#ifdef __MMI_CLUB_MULTI_MMSBOX__
								//MENU_CLUB_MULTI_MMSBOX,
								#endif
								MMS_MENU_DRAFTBOX_MENUID,
								#ifdef SUPPORT_MMS_TEMPLATES
									#ifdef SUPPORT_SMSMMS_COMBINE
									SMSMMS_MENU_TEMPLATES_MENUID,
									#else
									MMS_MENU_TEMPLATES_MENUID,
									#endif
								#endif
								#ifdef SUPPORT_EMPTY_BOX
								MMS_MENU_EMPTY_BOX_MENUID,
								#endif
								#ifdef SUPPORT_SMSMMS_COMBINE
								SMSMMS_MENU_SETTING_MENUID,
								#else
								MMS_MENU_MSG_SETTINGS_MENUID,
								#endif
								#ifdef SUPPORT_SMSMMS_COMBINE
								SMSMMS_MENU_MEMORY_STATUS_MENUID,
								#else
								MMS_MENU_MEMORY_STATUS_MENUID,
								#endif
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								#ifdef SUPPORT_SMSMMS_COMBINE
								STR_CMS_MESSAGE_MENUENTRY	,IMG_MESSAGE_SIM_MMS_MENUENTRY));
								#else
								STR_CMS_MMS_MENUENTRY,	IMG_MESSAGE_SIM_MMS_MENUENTRY));
								#endif

								
	#ifdef SUPPORT_SMSMMS_COMBINE

	//new ----------------------(new sms /new mms)
    	ADD_APPLICATION_MENUITEM((SMSMMS_MENU_WMESSAGE_MENUID,MESSAGES_MENU_MMS_MENUID,2,
                                                        MESSAGES_MENU_WMESSAGE_MENU_ID,
                                                        MMS_MENU_WMESSAGE_MENUID,                               
                                                        HIDE, NONMOVEABLE, DISP_LIST, 
                                                        STR_NEW_SMS_MMS,IMG_MMS_WMESSAGE));            
        #endif
		
	//new message--------------(To/CC/BCC/Subject/Edit Content/Send)
	ADD_APPLICATION_MENUITEM((MMS_MENU_WMESSAGE_MENUID,
	                    	                        	#ifdef SUPPORT_SMSMMS_COMBINE
                                                    	SMSMMS_MENU_WMESSAGE_MENUID,
                                                    	#else
	                                                	MESSAGES_MENU_MMS_MENUID,
	                                                	#endif
	                                                	NUM_MMS_WMESSAGE_MENU,
								MMS_WMESSAGE_TO_MENUID,
								MMS_WMESSAGE_CC_MENUID,
								MMS_WMESSAGE_BCC_MENUID,
								MMS_WMESSAGE_SUBJECT_MENUID,
								MMS_WMESSAGE_CONTENT_MENUID,
								MMS_SEND_OPTIONS_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_WMESSAGE,IMG_MMS_WMESSAGE));

	
	//add subject------------(Subject)
	ADD_APPLICATION_MENUITEM((MMS_WMESSAGE_SUBJECT_MENUID,MMS_MENU_WMESSAGE_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SUBJECT_ID,IMG_MMS_WMESSAGE_SUBJECT));
	//Edit Content------------(Edit Content )
	ADD_APPLICATION_MENUITEM((MMS_WMESSAGE_CONTENT_MENUID,MMS_MENU_WMESSAGE_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_CONTENT_ID,IMG_MMS_WMESSAGE_CONTENT));

	//add Send To------------(Add Phone Number/Add Email)
	ADD_APPLICATION_MENUITEM((MMS_WMESSAGE_TO_MENUID,MMS_MENU_WMESSAGE_MENUID,NUM_MMS_SENDTO,
								MMS_SENDTO_OPTIONS_ADD_NUMBER_MENUID,
								MMS_SENDTO_OPTIONS_ADD_EMAIL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TO_ID,IMG_MMS_WMESSAGE_SENDTO));

	//add Send Cc------------(Add Phone Number/Add Email)
	ADD_APPLICATION_MENUITEM((MMS_WMESSAGE_CC_MENUID,MMS_MENU_WMESSAGE_MENUID,NUM_MMS_SENDTO,
								MMS_SENDTO_OPTIONS_ADD_NUMBER_MENUID,
								MMS_SENDTO_OPTIONS_ADD_EMAIL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_CC_ID,IMG_MMS_WMESSAGE_SENDCC));

	//add Send Bcc------------(Add Phone Number/Add Email)
	ADD_APPLICATION_MENUITEM((MMS_WMESSAGE_BCC_MENUID,MMS_MENU_WMESSAGE_MENUID,NUM_MMS_SENDTO,
								MMS_SENDTO_OPTIONS_ADD_NUMBER_MENUID,
								MMS_SENDTO_OPTIONS_ADD_EMAIL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_BCC_ID,IMG_MMS_WMESSAGE_SENDBCC));
		
	//Send Options------------(Send/View/Save/Send Save)
	ADD_APPLICATION_MENUITEM((MMS_SEND_OPTIONS_MENUID,MMS_MENU_WMESSAGE_MENUID,NUM_MMS_SEND_OPTIONS,
								MMS_SEND_OPTIONS_SEND_MENUID,
								MMS_SEND_OPTIONS_VIEW_MENUID,
								MMS_SEND_OPTIONS_SAVE_MENUID,
								MMS_SEND_OPTIONS_SEND_SAVE_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS,IMG_MMS_SEND_OPTIONS));
	// Send-------------------(Send )
	ADD_APPLICATION_MENUITEM((MMS_SEND_OPTIONS_SEND_MENUID,MMS_SEND_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_SEND,IMG_GLOBAL_L1));
	//Send View---------------( Send View)
	ADD_APPLICATION_MENUITEM((MMS_SEND_OPTIONS_VIEW_MENUID,MMS_SEND_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_VIEW,IMG_GLOBAL_L2));
	// Save(Send Option)--------(Save(Send Option) )
	ADD_APPLICATION_MENUITEM((MMS_SEND_OPTIONS_SAVE_MENUID,MMS_SEND_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_SAVE,IMG_GLOBAL_L3));
	// Send And Save-----------( Send And Save)
	ADD_APPLICATION_MENUITEM((MMS_SEND_OPTIONS_SEND_SAVE_MENUID,MMS_SEND_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_SEND_SAVE,IMG_GLOBAL_L4));


	//SendTo Options ------------(Add Number/Add Email/Amend/Delete/Delete All )
	ADD_APPLICATION_MENUITEM((MMS_SENDTO_OPTIONS_MENUID,NULL,NUM_MMS_SENDTO_OPTIONS,
								MMS_SENDTO_OPTIONS_ADD_NUMBER_MENUID,
								MMS_SENDTO_OPTIONS_ADD_EMAIL_MENUID,
								MMS_SENDTO_OPTIONS_AMEND_MENUID,
								MMS_SENDTO_OPTIONS_DELETE_MENUID,
								MMS_SENDTO_OPTIONS_DELETE_ALL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SENDTO_OPTIONS,NULL));
	// SendTo Add Number--------(Add Number )
	ADD_APPLICATION_MENUITEM((MMS_SENDTO_OPTIONS_ADD_NUMBER_MENUID,MMS_SENDTO_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_ID_ADD_NUMBER,IMG_GLOBAL_L1));
	// SendTo Add Email----------( Add Email)
	ADD_APPLICATION_MENUITEM((MMS_SENDTO_OPTIONS_ADD_EMAIL_MENUID,MMS_SENDTO_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_ID_ADD_EMAIL,IMG_GLOBAL_L2));
	// SendTo Amend-------------(Amend )
	ADD_APPLICATION_MENUITEM((MMS_SENDTO_OPTIONS_AMEND_MENUID,MMS_SENDTO_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_EDIT,IMG_GLOBAL_L3));
	// SendTo Delete--------------( Delete)
	ADD_APPLICATION_MENUITEM((MMS_SENDTO_OPTIONS_DELETE_MENUID,MMS_SENDTO_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE,IMG_GLOBAL_L4));
	// SendTo Delete All -----------( Delete All)
	ADD_APPLICATION_MENUITEM((MMS_SENDTO_OPTIONS_DELETE_ALL_MENUID,MMS_SENDTO_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL,IMG_GLOBAL_L5));

	//Inbox Options  --------------(INBOX )
	ADD_APPLICATION_MENUITEM((MMS_MENU_INBOX_MENUID,MESSAGES_MENU_MMS_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_INBOX,IMG_MMS_INBOX));
	
	//Inbox Options1  --------------(Play/Reply/Details/Forward/Save Image/Save Music/Get Number/Download/Delete/Delete All )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS1_MENUID,NULL,NUM_MMS_INBOX_OPTIONS1,
								MMS_INBOX_OPTIONS_PLAY_MENUID,
								MMS_INBOX_OPTIONS_REPLY_MENUID,
								MMS_INBOX_OPTIONS_DETAILS_MENUID,
								MMS_INBOX_OPTIONS_FORWARD_MENUID,
								MMS_INBOX_OPTIONS_SAVE_IMAGE_MENUID,
								MMS_INBOX_OPTIONS_SAVE_MUSIC_MENUID,
								MMS_INBOX_OPTIONS_SAVE_ACCESSORY_MENUID,
								MMS_INBOX_OPTIONS_GET_DETAILS_MENUID,
								MMS_INBOX_OPTIONS_DELETE_MENUID,
								MMS_INBOX_OPTIONS_DELETE_ALL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS,NULL));
	
	//Inbox Options1  --------------(Play)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_PLAY_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_PLAY,IMG_GLOBAL_L1));
#ifdef SUPPORT_SMSMMS_COMBINE
	//Inbox Options1  --------------(MMS Reply/SMS Reply)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_REPLY_MENUID,NULL,NUM_MMS_INBOX_REPLY_OPTIONS,
								MMS_INBOX_OPTIONS_MMS_REPLY_MENUID,
								MMS_INBOX_OPTIONS_SMS_REPLY_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_REPLY,IMG_GLOBAL_L2));	
	//Inbox Options1  --------------(MMS Reply )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_MMS_REPLY_MENUID,MMS_INBOX_OPTIONS_REPLY_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_MMS_REPLY,IMG_GLOBAL_L1));
	//Inbox Options1  --------------(SMS Reply )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_SMS_REPLY_MENUID,MMS_INBOX_OPTIONS_REPLY_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_SMS_REPLY,IMG_GLOBAL_L2));
#else
	//Inbox Options1  --------------(Reply )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_REPLY_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_REPLY,IMG_GLOBAL_L2));
#endif	

	//Inbox Options1  --------------(Details )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_DETAILS_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_DETAILS,IMG_GLOBAL_L3));	
	//Inbox Options1  --------------(Forward )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_FORWARD_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_FORWARD,IMG_GLOBAL_L4));
	//Inbox Options1  --------------(Save Image )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_SAVE_IMAGE_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_SAVE_IMAGE,IMG_GLOBAL_L5));
	//Inbox Options1  --------------(Save Music )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_SAVE_MUSIC_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_SAVE_MUSIC,IMG_GLOBAL_L6));

	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_SAVE_ACCESSORY_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_SAVE_ACCESSORY,IMG_GLOBAL_L7));
	//Inbox Options1  --------------(Dial/Save number)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_GET_DETAILS_MENUID,NULL,NUM_MMS_INBOX_GET_NUMBER_OPTIONS,
								MMS_INBOX_OPTIONS_DIAL_NUMBER_MENUID,
								MMS_INBOX_OPTIONS_SAVE_NUMBER_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_GET_DETAILS,IMG_GLOBAL_L7));	
	//Inbox Options1  --------------(Dial )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_DIAL_NUMBER_MENUID,MMS_INBOX_OPTIONS_GET_DETAILS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_GLOBAL_DIAL,IMG_GLOBAL_L1));
	//Inbox Options1  --------------(Save number )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_SAVE_NUMBER_MENUID,MMS_INBOX_OPTIONS_GET_DETAILS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_SAVE,IMG_GLOBAL_L2));

	//Inbox Options1  --------------(Delete)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_DELETE_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE,IMG_GLOBAL_L8));	
	//Inbox Options1  --------------(Delete All)
	#ifdef SUPPORT_SMSMMS_COMBINE
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_DELETE_ALL_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL_MMS,IMG_GLOBAL_L9));	
	#else
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_DELETE_ALL_MENUID,MMS_INBOX_OPTIONS1_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL,IMG_GLOBAL_L9));	
	#endif

	//Inbox Options2  --------------(Download /Details/Delete)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS2_MENUID,NULL,NUM_MMS_INBOX_OPTIONS2,
								MMS_INBOX_OPTIONS_DOWNLOAD_MENUID,
								MMS_INBOX_OPTIONS_PUSH_DETAILS_MENUID,
								MMS_INBOX_OPTIONS_PUSH_DELETE_MENUID,
								MMS_INBOX_OPTIONS_PUSH_DELETE_ALL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS,NULL));

	//Inbox Options2  --------------(Download )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_DOWNLOAD_MENUID,MMS_INBOX_OPTIONS2_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_DOWNLOAD,IMG_GLOBAL_L1));	
	//Inbox Options2  --------------(Details )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_PUSH_DETAILS_MENUID,MMS_INBOX_OPTIONS2_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_DETAILS,IMG_GLOBAL_L2));
	//Inbox Options2  --------------(Delete )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_PUSH_DELETE_MENUID,MMS_INBOX_OPTIONS2_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE,IMG_GLOBAL_L3));
	//Inbox Options2  --------------(Delete All )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_OPTIONS_PUSH_DELETE_ALL_MENUID,MMS_INBOX_OPTIONS2_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL_MMS,IMG_GLOBAL_L4));
#ifdef SUPPORT_SMSMMS_COMBINE
	//Inbox WapOptions  --------------(Link /Delete/Delete All)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_WAP_OPTIONS_MENUID,NULL,3,
								MMS_INBOX_WAP_OPTIONS_LINK,
								MMS_INBOX_WAP_OPTIONS_DELETE,
								MMS_INBOX_WAP_OPTIONS_DELETE_ALL,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS,NULL));

	//Inbox WapOptions  --------------(Link )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_WAP_OPTIONS_LINK,MMS_INBOX_WAP_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_WAP_LINK,IMG_GLOBAL_L1));	
	//Inbox WapOptions  --------------(Delete )
	ADD_APPLICATION_MENUITEM((MMS_INBOX_WAP_OPTIONS_DELETE,MMS_INBOX_WAP_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE,IMG_GLOBAL_L2));
	//Inbox WapOptions  --------------(Delete All)
	ADD_APPLICATION_MENUITEM((MMS_INBOX_WAP_OPTIONS_DELETE_ALL,MMS_INBOX_WAP_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL,IMG_GLOBAL_L3));
#endif
	//Outbox ---------------------(Outbox)
	ADD_APPLICATION_MENUITEM((MMS_MENU_OUTBOX_MENUID,MESSAGES_MENU_MMS_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_OUTBOX,IMG_MMS_OUTBOX));
	//Outbox Options  --------------(Send/Forward/Play/Details/Delete/Delete All)
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_MENUID,NULL,NUM_MMS_OUTBOX_OPTIONS,
								MMS_OUTBOX_OPTIONS_SEND_MENUID,
								MMS_OUTBOX_OPTIONS_FORWARD_MENUID,
								MMS_OUTBOX_OPTIONS_PLAY_MENUID,
								MMS_OUTBOX_OPTIONS_DETAIL_MENUID,
								MMS_OUTBOX_OPTIONS_DELETE_MENUID,
								MMS_OUTBOX_OPTIONS_DELETE_ALL_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_OUTBOX_OPTIONS,NULL));
	//Outbox Options  --------------(Send)
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_SEND_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_SEND,IMG_GLOBAL_L1));
	//Outbox Options  --------------(Forward)
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_FORWARD_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_FORWARD,IMG_GLOBAL_L2));
	//Outbox Options  --------------(Play)
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_PLAY_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_PLAY,IMG_GLOBAL_L3));
	//Outbox Options  --------------(Details)
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_DETAIL_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_DETAILS,IMG_GLOBAL_L4));
	//Outbox Options  --------------(Delete)
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_DELETE_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE,IMG_GLOBAL_L5));
	//Outbox Options  --------------(Delete All)
	#ifdef SUPPORT_SMSMMS_COMBINE
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_DELETE_ALL_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL_MMS,IMG_GLOBAL_L6));
	#else
	ADD_APPLICATION_MENUITEM((MMS_OUTBOX_OPTIONS_DELETE_ALL_MENUID,MMS_OUTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL,IMG_GLOBAL_L6));
	#endif
	

	//Draftbox -----------------------(Draftbox)
	ADD_APPLICATION_MENUITEM((MMS_MENU_DRAFTBOX_MENUID,MESSAGES_MENU_MMS_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_DRAFTBOX,IMG_MMS_DRAFTBOX_DRAFT));
	
	//Draftbox Options  --------------(Send/Play/Edit/Details/Delete/Delete All/Send And Save)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_MENUID,NULL,NUM_MMS_DRAFTBOX_OPTIONS,
								MMS_DRAFTBOX_OPTIONS_SEND_MENUID,
								MMS_DRAFTBOX_OPTIONS_PLAY_MENUID,
								MMS_DRAFTBOX_OPTIONS_EDIT_MENUID,
								MMS_DRAFTBOX_OPTIONS_DETAIL_MENUID,
								MMS_DRAFTBOX_OPTIONS_DELETE_MENUID,
								MMS_DRAFTBOX_OPTIONS_DELETE_ALL_MENUID,
								MMS_DRAFTBOX_OPTIONS_SEND_SAVE_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DRAFTBOX_OPTIONS,NULL));
	
	//Draftbox Options  --------------(Send)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_SEND_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
 								STR_MMS_SEND_OPTIONS_SEND,IMG_GLOBAL_L1));
	//Draftbox Options  --------------(Play)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_PLAY_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_PLAY,IMG_GLOBAL_L2));
	//Draftbox Options  --------------(Edit)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_EDIT_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_EDIT,IMG_GLOBAL_L3));
	//Draftbox Options  --------------(Details)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_DETAIL_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_DETAILS,IMG_GLOBAL_L4));
	//Draftbox Options  --------------(Delete)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_DELETE_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE,IMG_GLOBAL_L5));
	//Draftbox Options  --------------(Delete All)
	#ifdef SUPPORT_SMSMMS_COMBINE
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_DELETE_ALL_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL_MMS,IMG_GLOBAL_L6));
	#else
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_DELETE_ALL_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_DELETE_ALL,IMG_GLOBAL_L6));
	#endif
	//Draftbox Options  --------------(Send And Save)
	ADD_APPLICATION_MENUITEM((MMS_DRAFTBOX_OPTIONS_SEND_SAVE_MENUID,MMS_DRAFTBOX_OPTIONS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
 								STR_MMS_SEND_OPTIONS_SEND_SAVE,IMG_GLOBAL_L7));	

	#ifdef SUPPORT_SMSMMS_COMBINE
	//Message Setting ----------------------( sms  Setting/ mms Setting)
    	ADD_APPLICATION_MENUITEM((SMSMMS_MENU_SETTING_MENUID,MESSAGES_MENU_MMS_MENUID,2,
                                                        MESSAGES_MENU_MSG_SETTINGS_MENUID,
                                                        MMS_MENU_MSG_SETTINGS_MENUID,                               
                                                        HIDE, NONMOVEABLE, DISP_LIST, 
                                                        STR_SMS_MMS_SETTING,IMG_MMS_MESSAGE_SETTING));            
       #endif
	   
	//MMS Setting --------------(Send /Retireving/MMSC/Net)
	ADD_APPLICATION_MENUITEM((MMS_MENU_MSG_SETTINGS_MENUID,
		                    	                     #ifdef SUPPORT_SMSMMS_COMBINE
                                                    	SMSMMS_MENU_SETTING_MENUID,
                                                    	#else
	                                                	MESSAGES_MENU_MMS_MENUID,
	                                                	#endif
								NUM_MMS_SETTINGS,
								MMS_SEND_SETTINGS_MENUID,
								MMS_RETRIEVING_SETTINGS_MENUID,
								MMS_EDIT_SETTING_OPTION_MENUID,
								//MMS_MMSC_SETTINGS_MENUID,
								//MMS_NET_SETTINGS_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SETTING_MENUENTRY,IMG_MMS_MESSAGE_SETTING));
	
	//MMS Setting --------------(Send)
	ADD_APPLICATION_MENUITEM((MMS_SEND_SETTINGS_MENUID,MMS_MENU_MSG_SETTINGS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
 								STR_MMS_SETTING_SEND_OPTIONS,IMG_GLOBAL_L1));
	//MMS Setting --------------(Retireving)
	ADD_APPLICATION_MENUITEM((MMS_RETRIEVING_SETTINGS_MENUID,MMS_MENU_MSG_SETTINGS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SETTING_RECEIVE_OPTIONS,IMG_GLOBAL_L2));
	//MMS Setting --------------(Edit Setting Option)
	ADD_APPLICATION_MENUITEM((MMS_EDIT_SETTING_OPTION_MENUID,MMS_MENU_MSG_SETTINGS_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_WAP_EDIT_SETTING,IMG_GLOBAL_L3));

	//MMS Setting --------------(Edit Setting Option(Activate/Edit))
	ADD_APPLICATION_MENUITEM((MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID,NULL,2,
								MMS_MSG_SETTINGS_SERVICE_SET_MENUID,
								MMS_MSG_SETTINGS_SERVICE_EDIT_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_GLOBAL_OPTIONS,NULL));

	//MMS Setting --------------(Edit Setting Option(Activate))
	ADD_APPLICATION_MENUITEM((MMS_MSG_SETTINGS_SERVICE_SET_MENUID,MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_GLOBAL_ACTIVATE,IMG_GLOBAL_L1));

	//MMS Setting --------------(Edit Setting Option(Edit))
	ADD_APPLICATION_MENUITEM((MMS_MSG_SETTINGS_SERVICE_EDIT_MENUID,MMS_MSG_SETTINGS_SERVICE_OPTION_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_GLOBAL_EDIT,IMG_GLOBAL_L2));

	#ifdef SUPPORT_MMS_TEMPLATES

	#ifdef SUPPORT_SMSMMS_COMBINE
	//Sms_Mms templates ----------------------( sms  Templates/ mms Templates)
    	ADD_APPLICATION_MENUITEM((SMSMMS_MENU_TEMPLATES_MENUID,MESSAGES_MENU_MMS_MENUID,2,
                                                        MESSAGES_MENU_TEMPLATES_MENUID,
                                                        MMS_MENU_TEMPLATES_MENUID,                               
                                                        HIDE, NONMOVEABLE, DISP_LIST, 
                                                        STR_SMS_MMS_TEMPLATES,IMG_MMS_MESSAGE_TEMPLATE));            
       #endif
	//MMS Templates--------------(Templates)
	ADD_APPLICATION_MENUITEM((MMS_MENU_TEMPLATES_MENUID,
		                    	                     #ifdef SUPPORT_SMSMMS_COMBINE
                                                    	SMSMMS_MENU_TEMPLATES_MENUID,
                                                    	#else
	                                                	MESSAGES_MENU_MMS_MENUID,
	                                                	#endif
								NUM_MMS_TEMPLATES_TITLE,
								MMS_TEMPLATES_TITLE_01_MENUID,
								MMS_TEMPLATES_TITLE_02_MENUID,
								MMS_TEMPLATES_TITLE_03_MENUID,
								MMS_TEMPLATES_TITLE_04_MENUID,
								MMS_TEMPLATES_TITLE_05_MENUID,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_TEMPLATES,IMG_MMS_MESSAGE_TEMPLATE));
	//MMS Templates List One--------------(Templates List)
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATES_TITLE_01_MENUID,MMS_MENU_TEMPLATES_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_TITLE_01,IMG_GLOBAL_L1));	
	//MMS Templates List Two--------------(Templates List)
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATES_TITLE_02_MENUID,MMS_MENU_TEMPLATES_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_TITLE_02,IMG_GLOBAL_L2));	
	//MMS Templates List Three--------------(Templates List)
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATES_TITLE_03_MENUID,MMS_MENU_TEMPLATES_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_TITLE_03,IMG_GLOBAL_L3));	
	//MMS Templates List Four--------------(Templates List)
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATES_TITLE_04_MENUID,MMS_MENU_TEMPLATES_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_TITLE_04,IMG_GLOBAL_L4));	
	//MMS Templates List Five--------------(Templates List)
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATES_TITLE_05_MENUID,MMS_MENU_TEMPLATES_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_TITLE_05,IMG_GLOBAL_L5));	
	//Templates Options  --------------(View /Details/Write)
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATES_OPTION_MENUID,NULL,NUM_MMS_TEMPLATES_OPTIONS,
								MMS_TEMPLATE_OPTION_VIEW_MENUID,
								MMS_TEMPLATE_OPTION_PROPERTIES_MENUID,
								MMS_TEMPLATE_OPTION_WRITE_MENUID,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_OPTIONS,NULL));
	//Templates Options  --------------(View )
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATE_OPTION_VIEW_MENUID,MMS_TEMPLATES_OPTION_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_SEND_OPTIONS_VIEW,IMG_GLOBAL_L1));	
	//Templates Options  --------------(Details )
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATE_OPTION_PROPERTIES_MENUID,MMS_TEMPLATES_OPTION_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_INBOX_OPTIONS_DETAILS,IMG_GLOBAL_L2));
	//Templates Options  --------------(Write )
	ADD_APPLICATION_MENUITEM((MMS_TEMPLATE_OPTION_WRITE_MENUID,MMS_TEMPLATES_OPTION_MENUID,0,
								HIDE, NONMOVEABLE, DISP_LIST, 
								STR_MMS_TEMPLATES_OPTIONS_WRITE,IMG_GLOBAL_L3));
	#endif

	#ifdef SUPPORT_EMPTY_BOX
	ADD_APPLICATION_MENUITEM((MMS_MENU_EMPTY_BOX_MENUID,MESSAGES_MENU_MMS_MENUID,NUM_MMS_EMPTY_BOX,
								MMS_MENU_EMPTY_INBOX_MENUID,
								MMS_MENU_EMPTY_OUTBOX_MENUID,
								MMS_MENU_EMPTY_DRAFTBOX_MENUID,
								MMS_MENU_EMPTY_ALLBOX_MENUID,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_EMPTY_BOX,IMG_MMS_EMPTYBOX));
	
	ADD_APPLICATION_MENUITEM((MMS_MENU_EMPTY_INBOX_MENUID,MMS_MENU_EMPTY_BOX_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_INBOX,IMG_GLOBAL_L1));
	ADD_APPLICATION_MENUITEM((MMS_MENU_EMPTY_OUTBOX_MENUID,MMS_MENU_EMPTY_BOX_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_OUTBOX,IMG_GLOBAL_L2));
	ADD_APPLICATION_MENUITEM((MMS_MENU_EMPTY_DRAFTBOX_MENUID,MMS_MENU_EMPTY_BOX_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_DRAFTBOX,IMG_GLOBAL_L3));
	ADD_APPLICATION_MENUITEM((MMS_MENU_EMPTY_ALLBOX_MENUID,MMS_MENU_EMPTY_BOX_MENUID,0,
								HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_ALLBOX,IMG_GLOBAL_L4));
	#endif

	#ifdef SUPPORT_SMSMMS_COMBINE

	//Memory Status ----------------------( sms Status/ mms Status)
    	ADD_APPLICATION_MENUITEM((SMSMMS_MENU_MEMORY_STATUS_MENUID,MESSAGES_MENU_MMS_MENUID,2,
                                                        MESSAGES_MENU_MEMSTATUS_MENUID,
                                                        MMS_MENU_MEMORY_STATUS_MENUID,                               
                                                        HIDE, NONMOVEABLE, DISP_LIST, 
                                                        STR_SMS_MMS_MEMORY_STATUS,IMG_MMS_MESSAGE_MEMORY));
        #endif
	//Memory Status--------------(Mms Memory Status)
	ADD_APPLICATION_MENUITEM((MMS_MENU_MEMORY_STATUS_MENUID,
		                    	                     #ifdef SUPPORT_SMSMMS_COMBINE
                                                    	SMSMMS_MENU_MEMORY_STATUS_MENUID,
                                                    	#else
	                                                	MESSAGES_MENU_MMS_MENUID,
	                                                	#endif
								0,HIDE, MOVEABLEWITHINPARENT, DISP_LIST, 
								STR_MMS_MEMORY_STATUS,IMG_MMS_MESSAGE_MEMORY));

	/*----------------------------------------------------------------*/

	
}
#endif
#endif


