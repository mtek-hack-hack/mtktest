#include <windows.h>

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "app_buff_alloc.h"

#include "stacklib.h"
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"

#include "device.h"

#include "l4a.h"
#include <stdio.h>
#include <stdlib.h>

void w32_battery_status_ind(int status,int voltage)
{
	l4c_eq_battery_status_lind(status,voltage);
}
void w32_charger_in(void)
{
	w32_battery_status_ind(PMIC_CHARGER_IN,2);
}
void w32_charger_out(void)
{
	w32_battery_status_ind(PMIC_CHARGER_OUT,2);
}
/*
void w32_usb_ind(int action)
{
	l4a_sendmsg_ilm(MOD_L4C,MOD_MMI,MSG_ID_MMI_EQ_USBDETECT_IND,action);
}
void w32_usb_in(void)
{
	w32_usb_ind(DEVUSB_DETECT_ACTION_PLUGIN);
}
void w32_usb_out(void)
{
	w32_usb_ind(DEVUSB_DETECT_ACTION_PLUGOUT);
}
*/
void w32_incoming_call(void)
{
	kal_uint8	call_id;
	l4c_number_struct	num;
	l4c_sub_addr_struct	sub_addr;
	kal_uint8	name[30];
	kal_uint8	auto_answer;
	kal_uint8	call_type;

	call_id = 1;
	num.type = 0x01;
	num.length = 0x0a;
	num.number[0] = 0x30;
	num.number[1] = 0x39;
	num.number[2] = 0x38;
	num.number[3] = 0x32;
	num.number[4] = 0x34;
	num.number[5] = 0x34;
	num.number[6] = 0x38;
	num.number[7] = 0x37;
	num.number[8] = 0x30;
	num.number[9] = 0x32;
	num.number[10] = 0x00;

	sub_addr.type = 0x00;
	sub_addr.length = 0x00;

	name[0] = 0x00;
	name[1] = 0x02;
	name[2] = 0x00;
	name[3] = 0x00;
	name[4] = 0xd4;
	name[5] = 0xe1;
	name[6] = 0x56;
	name[7] = 0x08;
	name[8] = 0x30;
	name[9] = 0xf7;
	name[10] = 0x06;
	name[11] = 0x00;
	name[12] = 0xb4;
	name[13] = 0xbb;
	name[14] = 0x1b;
	name[15] = 0x00;
	name[16] = 0x00;
	name[17] = 0x02;
	name[18] = 0x00;
	name[19] = 0x00;
	name[20] = 0x00;
	name[21] = 0x00;

	auto_answer = 0x00;
	call_type = 0x00;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}
#define URL "h\0t\0t\0p\0:\0/\0/\0m\0t\0k\0000\0000\0004\0008\0001\0/\0B\0l\0o\0c\0k\0B\0u\0s\0t\0e\0r\0.\0j\0a\0r\0\0"
#define FILE_NAME "c\0:\0\\\0x\0.\0j\0a\0r\0\0"
typedef struct _java_wap_get_file_and_save_req_struct_t {
	LOCAL_PARA_HDR
	kal_uint32			session_id;
	kal_wchar*			download_url;
	kal_wchar*			save_file_path;
} java_wap_get_file_and_save_req_struct;

typedef struct _java_wap_post_data_req_struct_t {
	LOCAL_PARA_HDR
	kal_wchar *save_file_path;
	kal_wchar *url;
	kal_char *content_type;
	kal_char *body;
	int body_size;
} java_wap_post_data_req_struct;


void w32_download(void)
{
#ifdef __MMI_GAME_JAVA__
	ilm_struct *ilm_ptr=NULL;
	java_wap_get_file_and_save_req_struct *p=
			(java_wap_get_file_and_save_req_struct*) construct_local_para(
			(kal_uint16)(sizeof(java_wap_get_file_and_save_req_struct)),0);

	p->session_id = 10;

	p->download_url = get_ctrl_buffer(66);
	memcpy(p->download_url,URL,66);

	p->save_file_path = get_ctrl_buffer(20);
	memcpy(p->save_file_path,FILE_NAME,20);

	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm( MOD_J2ME );

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_JAVA_WAP_GET_FILE_AND_SAVE_REQ;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(MOD_J2ME,MOD_WAP,WAP_J2ME_SAP,ilm_ptr);
#endif
}
#define POST_URL "h\0t\0t\0p\0:\0/\0/\0m\0t\0k\0000\0000\0004\0008\0001\0/\0001\000.\0p\0h\0p\0\0"
#define POST_CONTENT_TYPE "text/html"
#define POST_BODY   "900 Success"

void w32_post_data(void)
{
#ifdef __MMI_GAME_JAVA__
	ilm_struct *ilm_ptr=NULL;
	java_wap_post_data_req_struct *p=
			(java_wap_post_data_req_struct*) construct_local_para(
			(kal_uint16)(sizeof(java_wap_post_data_req_struct)),0);
	p->url = get_ctrl_buffer(66);
	memcpy(p->url,POST_URL,66);

	p->body = get_ctrl_buffer(12);
	memcpy(p->body,POST_BODY,12);

	p->body_size = strlen(p->body);

	p->content_type = get_ctrl_buffer(10);
	memcpy(p->content_type,POST_CONTENT_TYPE,10);

	p->save_file_path = get_ctrl_buffer(20);
	memcpy(p->save_file_path,FILE_NAME,20);


	/* First allocate a memory for an interlayer message structure */
	ilm_ptr = allocate_ilm( MOD_J2ME );

	ilm_ptr->msg_id = (kal_uint16) MSG_ID_JAVA_WAP_POST_DATA_REQ;/* Set the message id */
	ilm_ptr->peer_buff_ptr = NULL;/* there are no peer message */
	ilm_ptr->local_para_ptr = (local_para_struct *)p;

	SEND_ILM(MOD_J2ME,MOD_WAP,WAP_J2ME_SAP,ilm_ptr);
#endif
}

void w32_set_channel(void)
{
#ifdef __MMI_GAME_JAVA__
	JASif_initChannel();
#endif
}

extern void mmiapi_sms_app_data_ind(mmi_sms_app_data_ind_struct *msg,module_type mod_src);


static void _w32_send_sms(int seg,int total_seg,int ref,int len,char *data,int dcs,int port)
{
}
	

void w32_send_single_sms(void)
{
	char data[] = {0x48,0x65,0x6c,0x6c,0x6f,0x1b,0x3d,0x21,0x00,0x23,0x02,0x25,0x1b,0x14,0x26,0x2a,0x28,0x29,0x11,0x2b,0x1b,0x40,0x57,0x6f,0x72,0x6c,0x64};
	_w32_send_sms(1,1,0,sizeof(data),data,SMSAL_DEFAULT_DCS,5432);
}
void w32_send_multi_sms(void)
{
	
	char data[] = {(char)0x4e,(char)0x2d,(char)0x65,(char)0x87,(char)0x6e,(char)0x2c,(char)0x8a,(char)0x66};
	_w32_send_sms(1,1,0,sizeof(data),data,SMSAL_UCS2_DCS,5432);
}
void w32_send_single_binary_sms(void)
{
	char data[] = {0,1,2,3,4,5,6,7,8,9};
	_w32_send_sms(1,1,0,sizeof(data),data,SMSAL_8BIT_DCS,5432);
}

void w32_gsm_timealarm(void)
{
	rtc_format_struct rtc_time;
	rtc_time.rtc_sec = 0x00;
	rtc_time.rtc_min = 0x32;
	rtc_time.rtc_hour = 0x00;
	rtc_time.rtc_day = 0x04;
	rtc_time.rtc_mon = 0x01;
	rtc_time.rtc_wday = 0x04;
	rtc_time.rtc_year = 0x04;


	l4a_sendmsg_ilm(MOD_L4C,MOD_MMI,MSG_ID_MMI_EQ_ALARM_IND,&rtc_time);
		
}
