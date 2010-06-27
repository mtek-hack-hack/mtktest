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

STATE_NAME(CMS_MMS_IDLE)
STATE_NAME(CMS_MMS_NET_CONNECTING)
STATE_NAME(CMS_MMS_NET_CONNECTED)  
STATE_NAME(CMS_MMS_WAP_CONNECTING)
STATE_NAME(CMS_MMS_WAP_CONNECTED)  

STATE_NAME(CMS_MMS_MSG_SENDING)  
STATE_NAME(CMS_MMS_MSG_SENDED) 

STATE_NAME(CMS_MMS_MSG_RECVING)
STATE_NAME(CMS_MMS_MSG_RECVED)
STATE_NAME(CMS_MMS_MSG_RECV_CMPED)
STATE_NAME(CMS_MMS_MSG_NOTIRESP_WAITING)
/*********************************************************/

ROW(CMS_MMS_IDLE,
	MMSConnectRequest,
	1,
	{
		idle_mcr_coning(machine,event);
	},
	CMS_MMS_NET_CONNECTING)

//user cancel cmsnetlink....
ROW(CMS_MMS_NET_CONNECTING,
	MMSAbort,
	1,
	{
		conning_mabort_idle(machine,event);
	},
	CMS_MMS_IDLE)

//可以通知外界状态为网络连接成功 如：//setstatus("net link success!");
ROW(CMS_MMS_NET_CONNECTING,
	MMSNetLinkedCfn,
	(event->MMSNetLinkedCfn.netlink_ok  == 1),
	{
		coning_mnlc_ok_coned(machine,event);
	},
	CMS_MMS_NET_CONNECTED)


ROW(CMS_MMS_NET_CONNECTING,
	MMSNetLinkedCfn,
	(event->MMSNetLinkedCfn.netlink_ok  == 0  && NETLINK_RETRY < MAX_NETLINK_RETRY) ,
	{
		NETLINK_RETRY++;
		mms_NetConnect();
		cms_mms_debug("mms lib *** net link retry","");
	},
	CMS_MMS_NET_CONNECTING)
// net link failed
ROW(CMS_MMS_NET_CONNECTING,
	MMSNetLinkedCfn,
	(event->MMSNetLinkedCfn.netlink_ok  == 0  && NETLINK_RETRY == MAX_NETLINK_RETRY) ,
	{
		coning_mnlc_maxretry_idle(machine,event);
	},
	CMS_MMS_IDLE)

ROW(CMS_MMS_NET_CONNECTED,
	MMSStartWAPOpen,
	1,
	{
		coned_mswo_wconing(machine,event);
	},
	CMS_MMS_WAP_CONNECTING)

//user abort when net connected
ROW(CMS_MMS_NET_CONNECTED,
	MMSAbort,
	1,
	{
		coned_ma_mmsidle(machine,event);
	},
	CMS_MMS_IDLE)

//user abort when wap is connecting
ROW(CMS_MMS_WAP_CONNECTING,
	MMSAbort,
	1,
	{
		wconing_abort_idle(machine,event);
	},
	CMS_MMS_IDLE)
//receive timeout or abort message from wap stack 2003.7.1
ROW(CMS_MMS_WAP_CONNECTING,
	MMSRcvAbort,
	1,
	{
		wconing_rcvabort_idle(machine,event);
	},
	CMS_MMS_IDLE)

ROW(CMS_MMS_WAP_CONNECTING,
	MMSWAPOpenCnf,
	(event->MMSWAPOpenCnf.wap_connected_ok == 1),
	{	
		wconing_mwoc_wok_wconed(machine,event);
	},
	CMS_MMS_WAP_CONNECTED)
ROW(CMS_MMS_WAP_CONNECTING,
	MMSWAPOpenCnf,
	(event->MMSWAPOpenCnf.wap_connected_ok == 0),
	{	
		wconing_mwoc_0_idle(machine,event);
	},
	CMS_MMS_IDLE)
//wap连接成功以后的接收过程
/*ROW(CMS_MMS_WAP_CONNECTED,
	MMSAbort,
	1,
	{
    	WSPEvent *wsp_event = NULL;
		machine->sendrecv_over = 1;
		wsp_event = wsp_event_create( Disconnect );
		wsp_handle_event(WSPGlobalMachine, wsp_event);
	},
	CMS_MMS_IDLE)
ROW(CMS_MMS_WAP_CONNECTED,
	MMSRcvAbort,
	1,
	{
		machine->sendrecv_over = 1;
    	if(mproc)
			mproc(LIB_STATUS_ERROR,"wap method failed!",MMS_ERR_WAP_DISCONNECTED);
	},
	CMS_MMS_IDLE)*///似乎用不到
ROW(CMS_MMS_WAP_CONNECTED,
	MMSWAPMethodInvoke,
	(machine->use_target == WSP_METHOD_GET),
	{	
		wconed_mwmi_get_recving(machine,event);
	},
	CMS_MMS_MSG_RECVING)

ROW(CMS_MMS_MSG_RECVING,
	MMSAbort,
	1,
	{
		recving_abort_idle(machine,event);
	},
	CMS_MMS_IDLE)
ROW(CMS_MMS_MSG_RECVING,
	MMSRcvAbort,
	1,
	{
		recving_rcvabort_idle(machine,event);
	},
	CMS_MMS_IDLE)

ROW(CMS_MMS_MSG_RECVING,
	MMSWAPMethodInvokeCnf,
	((machine->use_target == WSP_METHOD_GET) && event->MMSWAPMethodInvokeCnf.mms_data && event->MMSWAPMethodInvokeCnf.mms_data->data && event->MMSWAPMethodInvokeCnf.mms_data->len),
	{
		recving_micnf_get_recved(machine,event);
	},
	CMS_MMS_MSG_RECVED)
ROW(CMS_MMS_MSG_RECVING,
	MMSWAPMethodInvokeCnf,
	((machine->use_target == WSP_METHOD_GET) && (!(event->MMSWAPMethodInvokeCnf.mms_data) || !(event->MMSWAPMethodInvokeCnf.mms_data->data) || !(event->MMSWAPMethodInvokeCnf.mms_data->len))),
	{
		recving_micnf_get_idle(machine,event);
	},
	CMS_MMS_IDLE)
ROW(CMS_MMS_MSG_RECVED,
	MMSSendNotiResp,
	1,
	{	
		recved_notiresp_idle(machine,event);
	},
	CMS_MMS_MSG_NOTIRESP_WAITING)
ROW(CMS_MMS_MSG_NOTIRESP_WAITING,
	MMSAbort,
	1,
	{	
		cmmnw_mabort_idle(machine,event);
	},
	CMS_MMS_IDLE)

ROW(CMS_MMS_MSG_NOTIRESP_WAITING,
	MMSWAPMethodInvokeCnf,
	1,
	{	
		notiresp_handle(machine,event);
	},
	CMS_MMS_IDLE)
//20051019 chaozhuzh modify for state	MTK 
ROW(CMS_MMS_MSG_NOTIRESP_WAITING,
	MMSRcvAbort,
	1,
	{	
		notiresp_handle(machine,event);
	},
	CMS_MMS_IDLE)		
	/*
ROW(CMS_MMS_MSG_RECV_CMPED,
	MMSDisconnectRequest,//MMSConnectRequest,
	1,
	{
		recvcmped_disconreq_idle(machine,event);
	},
	CMS_MMS_IDLE)*/
//wap连接成功以后的发送过程
ROW(CMS_MMS_WAP_CONNECTED,
	MMSWAPMethodInvoke,
	(machine->use_target == WSP_METHOD_POST),
	{	
		//cms_mms_debug("666666",(short)0,(void*)NULL);
		cnted_post_sending(machine,event);
	},
	CMS_MMS_MSG_SENDING)
ROW(CMS_MMS_MSG_SENDING,
	MMSAbort,
	1,
	{
		snding_abort_1_idle(machine,event);
	},
	CMS_MMS_IDLE)
ROW(CMS_MMS_MSG_SENDING,
	MMSRcvAbort,
	1,
	{
		snding_rcvabort_1_idle(machine,event);
	},
	CMS_MMS_IDLE)

ROW(CMS_MMS_MSG_SENDING,
	MMSWAPMethodInvokeCnf,
	1,
	{	
		snding_mmic_1_snded(machine,event);
	},
	CMS_MMS_MSG_SENDED)
ROW(CMS_MMS_MSG_SENDED,
	MMSWAPMethodInvokeCnfHandle,
	1,
	{	
		sended_invcnf_recvcnf(machine,event);
	},
	CMS_MMS_IDLE)
#undef STATE_NAME
#undef ROW