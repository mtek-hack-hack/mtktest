/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: CECW MMS
 
 File Name   : MMSStateDecl.h

 Description : 

 Last Modify : 29/04/2003
 
 Written By  : Mobilesoft Technology

******************************************************************************/

/* 状态转换的宏定义		*/

STATE_NAME(CMS_BRW_IDLE)
STATE_NAME(CMS_BRW_NET_CONNECTING)
STATE_NAME(CMS_BRW_NET_CONNECTED)  
STATE_NAME(CMS_BRW_WAP_CONNECTING)
STATE_NAME(CMS_BRW_WAP_CONNECTED)  

STATE_NAME(CMS_BRW_MSG_SENDING)  
STATE_NAME(CMS_BRW_MSG_SENDED) 

STATE_NAME(CMS_BRW_MSG_RECVING)
STATE_NAME(CMS_BRW_MSG_RECVED)
STATE_NAME(CMS_BRW_MSG_RECV_CMPED)
/*********************************************************/

ROW(CMS_BRW_IDLE,
	BRWConnectRequest,
	1,
	{
		idle_bcr_coning(machine,event);
	},
	CMS_BRW_NET_CONNECTING)

ROW(CMS_BRW_NET_CONNECTING,
	BRWAbort,
	1,
	{
		conning_babort_idle(machine,event);
	},
	CMS_BRW_IDLE)

ROW(CMS_BRW_NET_CONNECTING,
	BRWNetLinkedCfn,
	(event->BRWNetLinkedCfn.netlink_ok  == 1),
	{
		coning_bnlc_ok_coned(machine,event);
	},
	CMS_BRW_NET_CONNECTED)


ROW(CMS_BRW_NET_CONNECTING,
	BRWNetLinkedCfn,
	(event->BRWNetLinkedCfn.netlink_ok  == 0  && BRW_NETLINK_RETRY < MAX_NETLINK_RETRY) ,
	{
		BRW_NETLINK_RETRY++;
		brw_NetConnect();
	},
	CMS_BRW_NET_CONNECTING)
// net link failed
ROW(CMS_BRW_NET_CONNECTING,
	BRWNetLinkedCfn,
	(event->BRWNetLinkedCfn.netlink_ok  == 0  && BRW_NETLINK_RETRY == MAX_NETLINK_RETRY) ,
	{
		coning_bnlc_maxretry_idle(machine,event);
	},
	CMS_BRW_IDLE)
ROW(CMS_BRW_NET_CONNECTED,
	BRWWAPIsOpen,
	1,
	{
		coned_brio_cbwcnned(machine,event);
	},
	CMS_BRW_WAP_CONNECTED)
ROW(CMS_BRW_NET_CONNECTED,
	BRWStartWAPOpen,
	1,
	{
		coned_bswo_wconing(machine,event);
	},
	CMS_BRW_WAP_CONNECTING)

//user abort when net connected
ROW(CMS_BRW_NET_CONNECTED,
	BRWAbort,
	1,
	{
		coned_ba_mmsidle(machine,event);
	},
	CMS_BRW_IDLE)

//user abort when wap is connecting
ROW(CMS_BRW_WAP_CONNECTING,
	BRWAbort,
	1,
	{
		wconing_babort_idle(machine,event);
	},
	CMS_BRW_IDLE)
//receive timeout or abort message from wap stack 2003.7.1
ROW(CMS_BRW_WAP_CONNECTING,
	BRWRcvAbort,
	1,
	{
		wconing_brcvabort_idle(machine,event);
	},
	CMS_BRW_IDLE)

ROW(CMS_BRW_WAP_CONNECTING,
	BRWWAPOpenCnf,
	(event->BRWWAPOpenCnf.wap_connected_ok == 1),
	{	
		wconing_bwoc_wok_wconed(machine,event);
	},
	CMS_BRW_WAP_CONNECTED)
ROW(CMS_BRW_WAP_CONNECTING,
	BRWWAPOpenCnf,
	(event->BRWWAPOpenCnf.wap_connected_ok == 0),
	{	
		wconing_bwoc_0_idle(machine,event);
	},
	CMS_BRW_IDLE)

ROW(CMS_BRW_WAP_CONNECTED,
	BRWWAPMethodInvoke,
	(machine->use_target == BRW_WSP_METHOD_GET),
	{	
		wconed_bwmi_get_recving(machine,event);
	},
	CMS_BRW_MSG_RECVING)

ROW(CMS_BRW_MSG_RECVING,
	BRWAbort,
	1,
	{
		recving_babort_idle(machine,event);
	},
	CMS_BRW_IDLE)
ROW(CMS_BRW_MSG_RECVING,
	BRWRcvAbort,
	1,
	{
		recving_brcvabort_idle(machine,event);
	},
	CMS_BRW_IDLE)

ROW(CMS_BRW_MSG_RECVING,
	BRWWAPMethodInvokeCnf,
	((machine->use_target == BRW_WSP_METHOD_GET) && event->BRWWAPMethodInvokeCnf.return_data && event->BRWWAPMethodInvokeCnf.return_data->data && event->BRWWAPMethodInvokeCnf.return_data->len),
	{
		mms_Tracer("recving to idle");
		recving_bicnf_get_recved(machine,event);
	},
	CMS_BRW_IDLE)
ROW(CMS_BRW_MSG_RECVING,
	BRWWAPMethodInvokeCnf,
	((machine->use_target == BRW_WSP_METHOD_GET) && (!(event->BRWWAPMethodInvokeCnf.return_data) || !(event->BRWWAPMethodInvokeCnf.return_data->data) || !(event->BRWWAPMethodInvokeCnf.return_data->len))),
	{
		recving_bicnf_get_idle(machine,event);
	},
	CMS_BRW_IDLE)

//wap连接成功以后的发送过程
ROW(CMS_BRW_WAP_CONNECTED,
	BRWWAPMethodInvoke,
	(machine->use_target == BRW_WSP_METHOD_POST),
	{	
		cnted_bpost_sending(machine,event);
	},
	CMS_BRW_MSG_SENDING)
ROW(CMS_BRW_MSG_SENDING,
	BRWAbort,
	1,
	{
		snding_babort_1_idle(machine,event);
	},
	CMS_BRW_IDLE)
ROW(CMS_BRW_MSG_SENDING,
	BRWRcvAbort,
	1,
	{
		snding_brcvabort_1_idle(machine,event);
	},
	CMS_BRW_IDLE)

ROW(CMS_BRW_MSG_SENDING,
	BRWWAPMethodInvokeCnf,
	1,
	{	
		snding_bmic_1_snded(machine,event);
	},
	CMS_BRW_MSG_SENDED)
		
ROW(CMS_BRW_MSG_SENDED,
	BRWWAPMethodInvokeCnfHandle,
	1,
	{	
		sended_binvcnf_recvcnf(machine,event);
	},
	CMS_BRW_IDLE)
#undef STATE_NAME
#undef ROW