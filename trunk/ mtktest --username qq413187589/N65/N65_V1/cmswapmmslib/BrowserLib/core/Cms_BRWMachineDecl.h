/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: CECE BRW PROJ Ver 1.00
 
 File Name   : Cms_WSPMachineDecl.h

 Description : To Implement Browser application

 Last Modify : 06/22/2002
 
 Written By  : Mobilesoft Technology Shawn Pan

******************************************************************************/


//2003.10.30
BRW_MACHINE({
	INTEGER(state);INTEGER(brwworking);INTEGER(use_target);INTEGER(recv_msgsize);
	INTEGER(sendrecv_over);INTEGER(wap_port);CHARARR8(gateway_address);
	OCTSTR(data_to_send);OCTSTR(recv_data);
	OCTSTR(get_url);OCTSTR(post_url);
	EVENT_POINTER(event_queue_head);EVENT_POINTER(event_queue_tail);
	
})

//send_vfile_head 等发送的虚拟文件名

#undef INTEGER
#undef OCTSTR		
#undef EVENT_POINTER
#undef CHARARR8
#undef BRW_MACHINE

