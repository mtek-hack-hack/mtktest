/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: CECW MMS PROJ Ver 1.00
 
 File Name   : Cms_MMSEventDecl.h

 Description : MMS EVENT DECL

 Last Modify : 06/22/2002
 
 Written By  : Mobilesoft Technology

******************************************************************************/


MMS_EVENT(MMSConnectRequest,
			{
         INTEGER(temp);
          })

MMS_EVENT(MMSAbort,
			{
             INTEGER(aborttype);
          })

/*MMS_EVENT(MMSConReqTimeOut,
			{
             INTEGER(timeout_times);
          })
*/
MMS_EVENT(MMSRcvAbort,
			{
             INTEGER(aborttype);
          })
MMS_EVENT(MMSNetLinkedCfn,
			{
         INTEGER(netlink_ok);
          })
MMS_EVENT(MMSStartWAPOpen,
			{
         INTEGER(temp);
          })
MMS_EVENT(MMSWAPOpenCnf,
			{
         INTEGER(wap_connected_ok);
          })

MMS_EVENT(MMSStartWAPGet,
			{
         OCTSTR(get_url);
		 OCTSTR(vfile_recvname);
          })

MMS_EVENT(MMSStartWAPPost,
			{
         INTEGER(wap_connected_ok);
          })

MMS_EVENT(MMSWAPMethodInvoke,
			{
         INTEGER(temp);
          })

MMS_EVENT(MMSWAPMethodInvokeCnf,
			{
         OCTSTR(mms_data);
		 INTEGER(err_code);
          })
MMS_EVENT(MMSWAPMethodInvokeCnfHandle,
			{
         OCTSTR(mms_data);
          })
MMS_EVENT(MMSSendNotiResp,
			{
         INTEGER(temp);
          })
MMS_EVENT(MMSDisconnectRequest,
			{
         INTEGER(temp);
          })

#undef MMS_EVENT
#undef OCTSTR
#undef INTEGER
