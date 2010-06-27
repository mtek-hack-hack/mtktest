/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: CECE MMS PROJ Ver 1.00
 
 File Name   : Cms_WSPMachineDecl.h

 Description : To Implement Browser application

 Last Modify : 06/22/2002
 
 Written By  : Mobilesoft Technology Shawn Pan

******************************************************************************/


//2003.10.30
MMS_MACHINE({
	INTEGER(state);INTEGER(mmsworking);INTEGER(use_target);INTEGER(immediate_recv);INTEGER(recv_msgsize);
	INTEGER(sendrecv_over);INTEGER(wap_port);CHARARR8(gateway_address);INTEGER(supported_recv_mms_maxsize);INTEGER(supported_send_mms_maxsize);
	OCTSTR(vfile_sendname);OCTSTR(vfile_recvname);OCTSTR(vfile_confirmname);
	OCTSTR(get_url);OCTSTR(mmsc_url);
	EVENT_POINTER(event_queue_head);EVENT_POINTER(event_queue_tail);
	
})

//send_vfile_head 等发送的虚拟文件名

#undef INTEGER
#undef OCTSTR		
#undef EVENT_POINTER
#undef CHARARR8
#undef MMS_MACHINE

