/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: CECW BRW PROJ Ver 1.00
 
 File Name   : Cms_BRWEventDecl.h

 Description : BRW EVENT DECL

 Last Modify : 06/22/2002
 
 Written By  : Mobilesoft Technology

******************************************************************************/


BRW_EVENT(BRWConnectRequest,
			{
         INTEGER(temp);
          })

BRW_EVENT(BRWAbort,
			{
             INTEGER(aborttype);
          })


BRW_EVENT(BRWRcvAbort,
			{
             INTEGER(aborttype);
          })
BRW_EVENT(BRWNetLinkedCfn,
			{
         INTEGER(netlink_ok);
          })
BRW_EVENT(BRWWAPIsOpen,
			{
         INTEGER(temp);
          })
BRW_EVENT(BRWStartWAPOpen,
			{
         INTEGER(temp);
          })
BRW_EVENT(BRWWAPOpenCnf,
			{
         INTEGER(wap_connected_ok);
          })

BRW_EVENT(BRWStartWAPGet,
			{
         OCTSTR(get_url);
		 OCTSTR(vfile_recvname);
          })

BRW_EVENT(BRWStartWAPPost,
			{
         INTEGER(wap_connected_ok);
          })

BRW_EVENT(BRWWAPMethodInvoke,
			{
         INTEGER(temp);
          })

BRW_EVENT(BRWWAPMethodInvokeCnf,
			{
         OCTSTR(return_data);
		 INTEGER(err_code);
          })
BRW_EVENT(BRWWAPMethodInvokeCnfHandle,
			{
         OCTSTR(userdata);
          })
BRW_EVENT(BRWSendNotiResp,
			{
         INTEGER(temp);
          })
BRW_EVENT(BRWDisconnectRequest,
			{
         INTEGER(temp);
          })

#undef BRW_EVENT
#undef OCTSTR
#undef INTEGER
