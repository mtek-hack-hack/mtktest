/*******************************************************************************
 * Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.,
 * All rights reserved.
 * This is unpublished proprietary source code of MobileSoft Technology
 *
 * The copyright notice above does not evidence any actual or intended
 * publication of such source code  
 *******************************************************************************
 */

/*========================================================================
 * Module Name: cmswapmmsadp.c
 *
 * Module Function: 
 *     Author Name: 
 *     Create Date: 08/25/2005
 *
 *========================================================================
 */
 #ifdef CMS_NEW_APP
 /***************************************************************************** 
* Include files 
*****************************************************************************/
#include "Gui_ems.h"
#include "GSM7BitDefaultAlphabet.h"
//#include <windows.h>
#include  "Soc_api.h"

#include  "Kal_release.h"
#include "app_buff_alloc.h"
#include "ProtocolEvents.h"

#include  "Fs_func.h"
#include "WrapperGprot.h"
#include "stdlib.h"
#include "AudioInc.h"
#include "SSCStringHandle.h"
#include "FontRes.h"
#include "FontDcl.h"
#include "Fs_type.h"
#include "CommonScreens.h"
#include "Wgui_status_icons.h"

#include "WHTTP2Socket.h"
#include "cms_whttp.h"
#include "cmshttp.h"
#include "CmsFunc.h"
#include "CmsMMFile.h"

#include "CmsWapMmsAdp.h"
#include "MmsResourceData.h"
#include "WapResourceData.h"
#include "Globaldefs.h"
#include "gdi_include.h"
#include "App2soc_struct.h"
#include "Cmsnetwork.h"
#include "Cms_MMSProvide.h"
#include "CMSPushSMS.h"
#include "CmsBrowserCfg.h"
#include "CmsInfoDef.h"
#include "CmsPushBox.h"
#include "CmsBrowserSetup.h"
#include "CmsBookmark.h"
#include "Cms_whttp_public.h"
#include "app_datetime.h"
#include "DateTimeType.h"

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern enum _GPRSState 	GPRSState;
extern MMS_CONFIG		gconfig;	
extern kal_uint8 			wap_filename[MMS_FILE_NAME_LEN];

#ifdef CMS_PC_CONFIG_SOFTWARE
extern cms_wap_config_struct   cms_wap_config_default;
extern cms_mms_config_struct   cms_mms_config_default;
#endif
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#if defined(UNIRISE25_GEMINI_BB) || defined(SKYWORTH25_06B_BB) || defined(SKYWORTH23_07A_BB)
#define WAPMMS_USE_MEM  0
#else
#define WAPMMS_USE_MEM  1
#endif
#if WAPMMS_USE_MEM
KAL_ADM_ID cms_wapmms_mem_pool;
static kal_bool is_adm_pool_created = KAL_FALSE;
static kal_uint8 cms_mem_addr[WAPMMS_MEMORY_SZIE];
static kal_uint32 cms_subpool_size[] = { 8, 12, 16, 20, 24, 28, 32, 36, 40, 56, 60, 64, 72, 84, 96, 128, 144, 156, 208, 256, 268, 320, 412, 512, 564, 648, 712, 1536, 1636, 4752, 0xFFFFFFFF, 0 };
#else
#include "Med_utility.h"
#endif
/***************************************************************************** 
* Typedef 
*****************************************************************************/
#define SOCKET_RET_CODE_TO_HDI(errno)  sms_socket_retcode(errno)

/***************************************************************************** 
*  Global Variable
*****************************************************************************/
int 		OpenBGMusic=0;	
int 		OPenPushMessage=0;
int 		OPenSecurity=0;
int 		m_NetType=0;
U8		gphb_flag=CMS_PHB_NULL;
U8		phb_callbuf[MMS_MAX_SEND_TO_SIZE];		/* 电话本获得的地址*/
int 		WmlTimer_DefaultID;					/*Timer default ID*/

typedef struct
{
	 LOCAL_PARA_HDR
	 kal_int8   socket_id;
	 kal_uint8 event_type;
	 kal_bool  result;
	 kal_int8   error_cause;
	 kal_int32  detail_cause;
}cms_mmi_sock_notify_ind_struct;

extern kal_int8 		Socket_Id[3];
extern kal_uint8 		sms_push_buf[1024]; 
extern kal_int32 		pdu_len; 
extern sockaddr_struct 	mms_sock_addr;
extern void mmi_mms_exit_to_idle(void);
extern void mms_get_randstring(CMS_MMS_S8 filename[64]);
extern void mmi_wapmms_add_push_to_list (P_CMS_BROWSER_PUSH inPush);
extern int Cms_GetWTPSendRedirectAbotFlag(void);
extern void Cms_SetWTPSendRedirectAbotFalg(int flag);
extern int Cms_GetWspRedirectFlag(void);
extern void Cms_GetRedirectSetting(void);
extern void mms_get_all_boxes_count_size(U16* count, S32* msize);

extern int 			UnreadPushMessageNum;
extern U8 			Setting_Gateway[65];
extern U8 			Setting_Port[10];
 /******************************************************************************
 *                           				Init Memory                           *
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: cms_init_mem_pool
 *       Purpose: init WAPMMS memory pool
 *         Input:  None.
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
kal_uint8 	rcvd_addr[4];
kal_uint8* 	rcvd_counter;

static	int 	cms_malloc_num = 0;
extern 	int 	netacc_id;
extern 	int 	browserflag;
 /* ----------------------------------------------------------------------------
 * Function Name: cms_init_mem_pool
 *       Purpose: init WAPMMS memory pool
 *         Input:  None.
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_init_mem_pool()
{
#if WAPMMS_USE_MEM
	if( !is_adm_pool_created )
	{
		cms_wapmms_mem_pool = kal_adm_create( cms_mem_addr, WAPMMS_MEMORY_SZIE, cms_subpool_size, 0 );
		if(!cms_wapmms_mem_pool)
		{
			/* fail to create a dm pool */
			return;
		}	
		is_adm_pool_created = KAL_TRUE;
	}
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_destroy_mem_pool
 *       Purpose: destory WAPMMS memory pool
 *         Input:  None.
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_destroy_mem_pool()
{
#if WAPMMS_USE_MEM
	if( is_adm_pool_created )
	{
		kal_adm_delete( cms_wapmms_mem_pool );
		is_adm_pool_created = KAL_FALSE;
	}
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_Malloc
 *       Purpose: cms_wapmms_mem_pool is destination ADM, from where a memory piece will be allocated
 *         Input:  size(the required memory size).
 *        Output: None.
 *       Returns: Pointer of the allocated memory piece if operation successfully done, otherwise, NULL..
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void *mms_Malloc(unsigned int size )
{
#if WAPMMS_USE_MEM
	void *pointer = NULL;
	S32	total_left_memory_size = 0;
	S32	total_left_max_memory_size = 0;
	total_left_memory_size = kal_adm_get_total_left_size(cms_wapmms_mem_pool);
	total_left_max_memory_size = kal_adm_get_max_alloc_size(cms_wapmms_mem_pool);
	//kal_prompt_trace(MOD_NVRAM, "###total_left_memory_size=%d", (kal_char *)total_left_memory_size);
	//kal_prompt_trace(MOD_NVRAM, "###total_left_max_memory_size=%d", (kal_char *)total_left_max_memory_size);
	//kal_prompt_trace(MOD_NVRAM, "###malloc_size=%d", (kal_char *)size);
	if(!is_adm_pool_created)
	{
		return NULL;
	}
	if(size >= WAPMMS_MEMORY_SZIE)
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("###mms_Malloc->  cms_malloc_num=%d",(kal_char*)size);
#endif
		return NULL;
	}		
	if(size > total_left_memory_size ||size > total_left_max_memory_size)
	{
		//kal_prompt_trace(MOD_NVRAM, "###total_left_memory_size=%d",(kal_char*)total_left_memory_size);
		//kal_prompt_trace(MOD_NVRAM, "###total_left_max_memory_size=%d", (kal_char *)total_left_max_memory_size);	
		//DisplayPopup((U8*)GetString(STR_WAP_FAILURE_MEM_CAP_EXCEEDED), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, NULL);		
		return NULL;
	}
	else
	{
		pointer = kal_adm_alloc(cms_wapmms_mem_pool, (kal_uint32)size);
		memset(pointer,0,size);
		if(pointer!=NULL)
		{
			cms_malloc_num++;
			//adp_mmi_tracer("###mms_Malloc->end   cms_malloc_num=%d",(kal_char*)cms_malloc_num);
		}		
  		return pointer;
	}	
#else
    cms_malloc_num++;
    return med_alloc_ext_mem(size);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_Free
 *       Purpose: cms_wapmms_mem_pool is destination ADM, to which the memory pointer mem_addr will be returned.
 *         Input:  pointer(the memory pointer mem_addr will be returned).
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void mms_Free(void *pointer)
{
#if WAPMMS_USE_MEM
	if(pointer!=NULL)
	{	
		kal_adm_free( cms_wapmms_mem_pool, (void*)pointer );
		//adp_mmi_tracer("###^_^mms_free->end   cms_malloc_num=%d",(char*)cms_malloc_num);
		cms_malloc_num--;
	}
#else
    cms_malloc_num--;
    med_free_ext_mem(&pointer);
#endif
}
  /* ----------------------------------------------------------------------------
 * Function Name: cms_check_mem_size
 *       Purpose: check the memory pool
 *         Input:  the malloc size
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
BOOL cms_check_mem_size(S32 mem_size)
{
#if WAPMMS_USE_MEM
	S32	total_left_memory_size = 0;
	S32	total_left_max_memory_size = 0;
	total_left_memory_size = kal_adm_get_total_left_size(cms_wapmms_mem_pool);
	total_left_max_memory_size = kal_adm_get_max_alloc_size(cms_wapmms_mem_pool);
	if(mem_size >= total_left_memory_size ||mem_size >= total_left_max_memory_size)
	{
		DisplayPopup((U8*)GetString(STR_WAP_FAILURE_MEM_CAP_EXCEEDED), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);		
		return FALSE;
	}
	else
	{
		return TRUE;
	}	
#else
    if(med_ext_left_size() > mem_size)
    {
        return TRUE;
    }
    else
    {
        DisplayPopup((U8*)GetString(STR_WAP_FAILURE_MEM_CAP_EXCEEDED), IMG_GLOBAL_WARNING, NULL, CMS_WAP_POPUP_DELAY_TIME, WARNING_TONE);		
        return FALSE;
    }
#endif
}
 
 /******************************************************************************
 *                           				Init Data Account                           *
 ******************************************************************************/
  /* ----------------------------------------------------------------------------
 * Function Name: Cms_Dataaccount_Init
 *       Purpose: init network data account
 *         Input: None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void Cms_Dataaccount_Init(void)
{
	DataAccountReadyCheck(initaccountfuc);/*初始化帐号资料*/

}
void initaccountfuc(void)
{
/*必须设计一个空 函数*/
}
 /******************************************************************************
 *                           WTCP Socket                           *
 ******************************************************************************/
 kal_int8 SocketId = -10;
/* ----------------------------------------------------------------------------
 * Function Name: socket
 *       Purpose: create socket
 *         Input: af(socket address format),type(transmit type),protocol(protocol type)
 *        Output: None.
 *       Returns: socket id.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 extern DataAccountNode 		g_DataAccount[MAX_DATA_ACCOUNT_GSM_LIMIT];
 SOCKET socket(int af,int type,int protocol)
{
	if(netacc_id < 0)
	{
		netacc_id = DEFAULTNETACCID;
	}
	if(netacc_id < CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM)
	{
		if(g_DataAccount[netacc_id] .DialNumber[0] == 0)
		{
			//Cms_Brw_Cancle();/*20060725 juny delete*/
			DisplayPopup((U8*)GetString(STR_WAP_NETACCOUNT_ERROR), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, ERROR_TONE);
			return -1;
		}
	}
	wap_net_data_init();	
	SocketId=soc_create(PF_INET, 0, 0, MOD_MMI,netacc_id);

	adp_mmi_tracer("SocketID=%d",(char*)SocketId);
	adp_mmi_tracer("netacc_id=%d",(char*)netacc_id);		
	SetProtocolEventHandler(cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
	return SocketId;

}
/* ----------------------------------------------------------------------------
 * Function Name: cms_gethost_by_name_notify
 *       Purpose: get host by name
 *         Input: af(socket address format),type(transmit type),protocol(protocol type)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_gethost_by_name_notify(void* inMsg)
{
	if(MMS_HTTP_TASK == getHttpTaskType())
	{
		adp_mmi_tracer("==cms_gethost_by_name_notify1==","");
		//mmsEventPostEvent(MMS_GETHOSTIP_RETURN,NULL,NULL);
		mmsEventProcessEvent();
	}
	else
	{
		adp_mmi_tracer("==cms_gethost_by_name_notify2==","");
		NetPostEvent(EVENT_GETHOSTIP_RETURN, NULL, NULL);
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: gethostbyname
 *       Purpose: get host name by url
 *         Input: url(the web address)
 *        Output: None.
 *       Returns: 0..2 RequestId
 			  DNR_ERROR(7),fail
 			  DNR_OK(8),success
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int cmsgethostbyname(char *url)
{
	kal_int32 ret;
	adp_Tracer("==cmsgethostbyname in==");
	ret= soc_gethostbyname(KAL_FALSE, MOD_MMI,
				(kal_int32)0,
                     	(kal_char*)url,
                     	(kal_uint8*)rcvd_addr,
                     	(kal_uint8*)&rcvd_counter,
                     	0,
                     	(kal_uint8)netacc_id);//以前是netacc_id

	if(ret==SOC_SUCCESS)
	{	
		return 8;
	}
	else if(ret==SOC_WOULDBLOCK)
	{
		adp_mmi_tracer("==cms_gethost_by_name_notify==","");
		SetProtocolEventHandler( cms_gethost_by_name_notify, MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
		adp_mmi_tracer("==cms_gethost_by_name_notify==11","");
	}
	else if(ret == SOC_ERROR)	
	{
		return DNR_ERROR;	
	}	
}
/* ----------------------------------------------------------------------------
 * Function Name: gethostip
 *       Purpose: get host ip address
 *         Input: RequestId(the return value of gethostbyname function),IPaddress(the ip address of host)
 *        Output: None.
 *       Returns: 0,success
 			  SOCKET_ERROR,fail
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int gethostip(int RequestId,char *IPaddress)
{
	adp_Tracer("access_shoumingl:gethostip() in\n");
	if (NULL == IPaddress)
	{
		return -1;
	}
	else
	{
		int i = 0;
		char tempgateport[65] = {0};
	
		if (Setting_Gateway[0] == NULL)
		{
			memset(Setting_Gateway, 0, 65);
			memset(Setting_Port, 0, 10);
			Cms_Browser_GetGateWaySetup((P_CMS_BROWSER_U8)Setting_Gateway, (P_CMS_BROWSER_U8)Setting_Port);
		}
		
		while (Setting_Gateway[i*2] != NULL)
		{
			tempgateport[i] = Setting_Gateway[i*2];
			i++;	
		}
		strcpy(IPaddress, tempgateport);
		adp_Tracer("access_shoumingl:gethostip() out\n");
		return  0;
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: Connect
 *       Purpose: connect the destination ip address
 *         Input: socket(the socket id by socket function create),IPaddress(the ip address of host),port(the port number of host)
 *        Output: None.
 *       Returns: TRUE,operate success
 			  FALSE,operate fail
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 extern sockaddr_struct sock_addr;
int connect(SOCKET socket,char *ipaddress, int port)
{
	kal_int32 ret;
	adp_mmi_tracer("==connect1==%d",(char*)sock_addr.addr[0]);
	adp_mmi_tracer("==connect1==%d",(char*)sock_addr.addr[1]);
	adp_mmi_tracer("==connect1==%d",(char*)sock_addr.addr[2]);
	adp_mmi_tracer("==connect1==%d",(char*)sock_addr.addr[3]);
	adp_mmi_tracer("==port==%d",port);
	sock_addr.addr_len=4;

	adp_mmi_tracer("### connect!###","");
	adp_mmi_tracer("### connect socket id=%d###",socket);
	ret=soc_connect(socket,&sock_addr);

	adp_mmi_tracer("connect return =%d",(char*)ret);
	if(ret==SOC_WOULDBLOCK)
	{
		adp_mmi_tracer("SOC_WOULDBLOCK","");
		SetProtocolEventHandler( cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
		return ret;
	}
	
	return ret;
}
/* ----------------------------------------------------------------------------
 * Function Name: getlasterror
 *       Purpose: get the last socket error
 *         Input:   None.
 *        Output:  None.
 *       Returns: the error number
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int getlasterror()
{
	kal_int8	error;
	kal_int32	detail_cause;
	adp_mmi_tracer("###getlasterror!###","");
	soc_get_last_error(SocketId,&error, &detail_cause);
	return (int)error;
}
/* ----------------------------------------------------------------------------
 * Function Name: 	closesocket
 *       Purpose:	close  the socket and destory the socket resource
 *         Input:		s(the socket id by socket function create)
 *         Output:  	None.
 *         Returns: 	the close operate value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int closesocket(SOCKET s)
{
	kal_int8 ret = -1;
	adp_mmi_tracer((char *)"closesocket = %d", (char *)s);
	adp_mmi_tracer((char *)"SocketID = %d", (char *)SocketId);
	ret = soc_close((kal_int8)s);
	adp_mmi_tracer((char *)"closesocket  soc_close= %d", (char *)ret);
	
	if(ret == 0)
	{
		SocketId = -10;
		Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERSOCCLOSESUCCESS);
		//NetPostEvent(EVENT_NETCLOSE_RETURN,NETCLOSE_SUCEESS, NULL);
	}
	else
	{
		Cms_Browser_PostMessage(CMS_MESSAGE_BROWSERSOCCLOSEFAIL);
	}
	
	return ret;
}

void SocCloseSuccessEvent(void)
{
	NetPostEvent(EVENT_SOCKETCLOSED_RETURN,NULL, NULL);
}

void SocCloseFailEvent(void)
{
	NetPostEvent(EVENT_SOCKETCLOSED_RETURN,NULL, NULL);
}

/* ----------------------------------------------------------------------------
 * Function Name: 	send
 *       Purpose:	send the data
 *         Input:		s(the socket id by socket function create),sendbuf(the data buffer),len(the data length)
 *         Output:  	None.
 *         Returns: 	the length of sending
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 #define SOCKET_SEND_SIZE	1400
int send(SOCKET s,const char * sendbuf,int len)
{
	kal_int32 ret=0;
	char * tempsendbuf = NULL;
	int tempcount = 0;
	adp_Tracer("### send data!###");
	if(len<=0||sendbuf==NULL)
		return 0;
	if(len > SOCKET_SEND_SIZE)
	{
		while(len > SOCKET_SEND_SIZE)
		{
			if(tempsendbuf == NULL)
			{
				tempsendbuf = (char *)cms_malloc(SOCKET_SEND_SIZE+1);
			}
			else
			{
				cms_memset(tempsendbuf, 0x0, SOCKET_SEND_SIZE+1);
			}
			cms_memcpy(tempsendbuf, sendbuf+SOCKET_SEND_SIZE*tempcount, SOCKET_SEND_SIZE);
			ret = soc_send(s,(kal_uint8*)tempsendbuf,SOCKET_SEND_SIZE,0);
			tempcount ++;
			len = len - SOCKET_SEND_SIZE;
		}
		if(len > 0)
		{
			if(tempsendbuf != NULL)
			{
				cms_free(tempsendbuf);
			}
			tempsendbuf = cms_malloc(len);
			cms_memcpy(tempsendbuf, sendbuf+SOCKET_SEND_SIZE*tempcount, len);
			ret = soc_send(s,(kal_uint8*)tempsendbuf,len,0);
		}
	}
	else
	{
		ret = soc_send(s,(kal_uint8*)sendbuf,len,0);
	}
	adp_mmi_tracer("==soc_send==%d",(char*)ret);
	 if(ret==SOC_WOULDBLOCK)
	{
		SetProtocolEventHandler( cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
		return ret;
	}
	return ret;
}
/* ----------------------------------------------------------------------------
 * Function Name: 	recv
 *       Purpose:	recv the data
 *         Input:		s(the socket id by socket function create),recvbuf(the data buffer),len(the data length)
 *         Output:  	None.
 *         Returns: 	the length of receiving
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int  recv(SOCKET s,char * buf, int len,int flag)
{
	kal_int32 ret;
	adp_Tracer("### receive data!###");
	if(NULL == buf || len <= 0)
		return;
	ret = soc_recv(s,(kal_uint8*)buf,len,0);
	adp_mmi_tracer("recv ret= %d", ret);
	SetNetSocketReadEndState();
	if(ret==SOC_WOULDBLOCK)
	{
		SetProtocolEventHandler( cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
		return ret;
	}
	return ret;
}
/* ----------------------------------------------------------------------------
 * Function Name: 	bsd_setsockopt
 *       Purpose:	Set socket options
 *         Input:		vp_SocketId(the socket id by socket function create),vp_Level()
 *				vp_OptName(),pp_OptVal(),pp_OptLen()
 *         Output:  	None.
 *         Returns: 	the operate value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int bsd_setsockopt(int vp_SocketId, int vp_Level, int vp_OptName, char *pp_OptVal, int *pp_OptLen)
{
	kal_int8 ret;
	kal_uint8 val = 1;
	adp_Tracer("### bsd_setsockopt!###");
	ret=soc_setsockopt((kal_int8)vp_SocketId, SOC_NBIO, &val, sizeof(val));
	val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_CONNECT;
	ret=soc_setsockopt((kal_int8)vp_SocketId, SOC_ASYNC, &val, sizeof(val));
	return ret;
}
/* ----------------------------------------------------------------------------
 * Function Name: 	bsd_getsockopt
 *       Purpose:	Get socket options
 *         Input:		vp_SocketId(the socket id by socket function create),vp_Level()
 *				vp_OptName(),pp_OptVal(),pp_OptLen()
 *         Output:  	None.
 *         Returns: 	the operate value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int bsd_getsockopt(int vp_SocketId, int vp_Level, int vp_OptName, char *pp_OptVal, int *pp_OptLen)
{
	kal_int8 ret;
	adp_Tracer("### bsd_getsockopt!###");
	ret=soc_getsockopt(vp_SocketId, vp_OptName, (kal_uint8*)pp_OptVal, sizeof(pp_OptLen));
	return ret;
}
/* ----------------------------------------------------------------------------
 * Function Name: 	bsd_shutdown
 *       Purpose:	close socket
 *         Input:		id(the socket id by socket function create),howto(close type)
 *         Output:  	None.
 *         Returns: 	the operate value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int bsd_shutdown(int id,int howto)
{
	kal_int8 ret;
	adp_Tracer("###bsd_shutdown!###");
	ret=soc_shutdown(id, howto);
	return ret;
}
/* ----------------------------------------------------------------------------
 * Function Name: 	cms_socket_notify
 *       Purpose:	socket notify post message to http modle when create a stream socket
 *         Input:		(app_soc_notify_ind_struct *) inMsg
 *         Output:  	None.
 *         Returns: 	the operate value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
#if IA_JAVA_NOTIFY//for no support java
extern int JK_iatls;
extern void ia_socket_notify(void* inMsg);
#endif
void cms_socket_notify(void* inMsg)
{
	app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct *) inMsg;

	cms_mmi_sock_notify_ind_struct *soc_ind = (cms_mmi_sock_notify_ind_struct *) inMsg;
#if IA_JAVA_NOTIFY//for no support java
	if(JK_iatls)
	{
		ia_socket_notify((void* )inMsg);
		return;
	}
#endif	
	
	adp_mmi_tracer("Got socket notify, event_type:%d",soc_notify->event_type);	
	adp_mmi_tracer("soc_ind->socket_id = %d", soc_ind->socket_id);
	adp_mmi_tracer("Socket_Id[1]=%d", Socket_Id[1]);
	adp_mmi_tracer("Socket_Id[2]=%d", Socket_Id[2]);
	
	switch( soc_notify->event_type)
 	  {
	case SOC_ACCEPT:
		break;
	case SOC_WRITE:
	  	{
			if(soc_ind->socket_id == Socket_Id[0])
			{
				adp_Tracer("###sms:socket  send OK!!####");
				break;
			}
			else if(soc_ind->socket_id == Socket_Id[1])
			{
				adp_Tracer("mms:###socket  send OK!!####");
				if(MMS_HTTP_TASK == getHttpTaskType())
				{
					//mmsEventPostEvent(MMS_SOCKETBUFFERFREE,NULL,NULL);
					mmsEventProcessEvent();
				}
				else
				{
					mmsEventPostEvent(NETLINK_RETURN,NETLINK_SUCCESS,NULL);
					mmsEventProcessEvent();
				}
				break;
			}					
			else 
			{
				adp_Tracer("brw:###socket  send OK!!####");
				if(CmsGetNetType() == 0)
				{
					brwEventPostEvent(BRW_NETLINK_RETURN,BRW_NETLINK_SUCCESS,NULL);
					brwEventProcessEvent();
				}	
				else
				{
					NetPostEvent(EVENT_DATASENT_RETURN,NULL, NULL);
				}
				break;
			}		
  	     	}	
	case SOC_READ:
		adp_mmi_tracer("soc_ind->socket_id = %d", soc_ind->socket_id);
		if(soc_ind->socket_id == Socket_Id[0])
		{
			adp_Tracer("###sms:socket  receive OK!!####");
			sms_recv_data();
			adp_Tracer("###sms:SOC_READ!!####");
			break;
		}
		else if(soc_ind->socket_id == Socket_Id[1])
		{
			adp_Tracer("mms:###socket  receive OK!!####");
			if(MMS_HTTP_TASK == getHttpTaskType())
			{
				mmsEventPostEvent(DATAARRIVED,NULL,NULL);
				mmsEventProcessEvent();
			}
			else
			{				
				mmsEventPostEvent(DATAARRIVED,NULL,NULL);
				mmsEventProcessEvent();				
			}	
			break;
		}		
		else 
		{
			adp_Tracer("brw:###socket  receive OK!!####");
			if(CmsGetNetType() == 0)
			{
				brwEventPostEvent(BRW_DATAARRIVED,NULL,NULL);
				brwEventProcessEvent();
			}	
			else
			{
				NetPostEvent(EVENT_DATARRIVED,NULL, NULL);
				SetNetSocketReadEndState();
			}
			break;
		}	
	case SOC_CONNECT:
	       {
			   adp_mmi_tracer("==cms_socket_notify==SOC_CONNECT==","");
			   if(MMS_HTTP_TASK == getHttpTaskType())
			   {
				   if(soc_notify->result==KAL_TRUE)
				   {
					   adp_mmi_tracer("==cms_socket_notify==mms SOCKETCONNECT_SUCCESS==","");
					   //mmsEventPostEvent(MMS_SOCKETCONNECT_RETURN,MMS_SOCKETCONNECT_SUCCESS,NULL);
					   mmsEventProcessEvent();					
				   }
				   else
				   {
					   adp_mmi_tracer("==cms_socket_notify==mms SOCKETCONNECT_FAILED==","");
					   //mmsEventPostEvent(MMS_SOCKETCONNECT_RETURN,MMS_SOCKETCONNECT_FAILED,NULL);
					   mmsEventProcessEvent();							
				   }
			   }
			   else
			   {
				   if(soc_notify->result==KAL_TRUE)
				   {
					   adp_mmi_tracer("==cms_socket_notify==SOCKETCONNECT_SUCCESS==","");
					   NetPostEvent(EVENT_SOCKETCONNECT_RETURN,SOCKETCONNECT_SUCCESS, NULL);
				   }
				   else
				   {
					   adp_mmi_tracer("==cms_socket_notify==SOCKETCONNECT_FAILED==","");
					   NetPostEvent(EVENT_SOCKETCONNECT_RETURN,SOCKETCONNECT_FAILED, NULL);
				   }
			   }
			   break;
		   }
	case SOC_CLOSE:
	       {
			   if(MMS_HTTP_TASK == getHttpTaskType())
			   {
				   if(soc_notify->result==KAL_TRUE)
				   {
					   //mmsEventPostEvent(MMS_SOCKETCLOSED_RETURN,NULL,NULL);
					   mmsEventProcessEvent();	
				   }
				   else
				   {
					   int ret = -1;
					   if(SocketId >= 0)
					   {						
						   ret = soc_close(SocketId);
						   adp_mmi_tracer((char *)"cms_socket_notify SocketId  = %d",(char *)SocketId);
						   SocketId = -10;
						   adp_mmi_tracer((char *)"cms_socket_notify soc_close ret = %d",(char *)ret);
					   }
					   if(ret == 0)
					   {
						   //mmsEventPostEvent(MMS_SOCKETCLOSED_RETURN,NULL,NULL);
						   mmsEventProcessEvent();	
					   }
					   else
					   {
						   //mmsEventPostEvent(MMS_SOCKETCLOSED_RETURN,NULL,NULL);
						   mmsEventProcessEvent();	
					   }		   		
				   }			
			   }
			   else
			   {
				   if(soc_notify->result==KAL_TRUE)
				   {
					   NetPostEvent(EVENT_SOCKETCLOSED_RETURN,NULL, NULL);
				   }
				   else
				   {
					if(SocketId >= 0)
						closesocket(SocketId);
				   }
			   }	
			   break;
		   }		   
	default:
		adp_mmi_tracer("==cms_socket_notify==default:%d",soc_notify->event_type);			
		break;
		}
		adp_mmi_tracer("==cms_socket_notify==END^_^_^_^_^==","");
		
}
void cms_close_tcpsocket(void)
{
	if(SocketId >= 0)
			closesocket(SocketId);
}
 /******************************************************************************
 *                           					UDP Socket                           				    *
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: brw_NetConnect
 *       Purpose: connect the gprs network for browser
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 #include "cms_wap.h"
extern  enum _GPRSState GPRSState;
void brw_NetConnect(void)
{
	if(CmsGetNetType() == 1)
	{
		NetPostEvent(EVENT_NETLINK_RETURN, NETLINK_SUCCESS, NULL);
		GPRSState=GPRSOnline;
	}
	else
	{
		if (Socket_Id[2] < 0)
		{
			SocketStart(2);
		}
		else
		{
			brwEventPostEvent(BRW_NETLINK_RETURN,BRW_NETLINK_SUCCESS,NULL);
			brwEventProcessEvent();
		}
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: brw_NetDisconnect
 *       Purpose: disconnect the gprs network for browser
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void brw_NetDisconnect(void)
{
	NetPostEvent(EVENT_NETCLOSE_RETURN, NETCLOSE_SUCEESS, NULL);
	GPRSState=GPRSNull;
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_NetConnect
 *       Purpose: disconnect the gprs network for mms
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_NetConnect(void)
{
#ifdef MMS_SUPPORT_WAP12	
	adp_Tracer("mms_NetConnect WAP1.2.1......");
	SocketStart(1);
#else
	adp_Tracer("mms_NetConnect WAP2.0......");
	mmsEventPostEvent(NETLINK_RETURN,MMS_NETLINK_SUCCESS,NULL);
	mmsEventProcessEvent();
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_NetReConnect
 *       Purpose: reconnect the gprs network for mms when gateway need security connect
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_NetReConnect(int flag, unsigned char* ip_addr, unsigned short port)
{
	kal_uint8 val = KAL_TRUE;
	kal_uint32 acc_id;
	adp_Tracer((char *)"Cms_NetReConnect");

	acc_id = gconfig.gprs_mode + GSM_NET_ACCOUNT;

	adp_mmi_tracer((char *)"soc_create ... acc_id = %d",(char *)acc_id);
	Socket_Id[flag] = soc_create(PF_INET, 1, 0, MOD_MMI, acc_id);
	adp_mmi_tracer((char *)"soc_create ... socket_ID = %d",(char *)Socket_Id[flag]);

	kal_prompt_trace(MOD_NVRAM,"###create %d socket id!###%d", flag,Socket_Id[flag]);
	
	if(Socket_Id[flag] < 0)
	{
		/*error handle*/
		adp_Tracer("###create socket error!###");	
	} 
	else
	{
		/*set socket to  non-blocking mode*/
		if( soc_setsockopt(Socket_Id[flag],SOC_NBIO, &val, sizeof(val))< 0 )
		{
			adp_Tracer("###Set socket to block mode error !!###%");
			return;
		}
		/*set socket to Async  mode*/
		val=SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE | SOC_ACCEPT;
		if(soc_setsockopt(Socket_Id[flag],SOC_ASYNC, &val, sizeof(val)) < 0)
		{
			adp_Tracer("###Set socket to nonblock mode error !!###");
			return;
		}
#ifdef MMI_ON_HARDWARE_P
		SetProtocolEventHandler( cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND );
#endif
		cms_net_mms_data_init_again(ip_addr, port);
		mmsEventPostEvent(NETLINK_RETURN,MMS_NETLINK_SUCCESS,NULL);
		mmsEventProcessEvent();

	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_NetConnect
 *       Purpose: disconnect the gprs network for mms
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_NetDisconnect(void)
{
#ifdef MMS_SUPPORT_WAP12
	adp_Tracer("mms_NetDisconnect WAP1.2.1......");
	Cms_close_soc(1);  
#else	
	adp_Tracer("mms_NetDisconnect WAP2.0......");
	mmsEventPostEvent(NETLINK_RETURN,NETCLOSE_SUCEESS,NULL);
	mmsEventProcessEvent();
#endif	
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_SendPDU
 *       Purpose: send udp data
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_SendPDU(void *pp_data,long vp_length,unsigned char *host,int port)
{
	kal_int32 nrect = 0;

	adp_Tracer("Cms_SendPDU.................in");
	adp_mmi_tracer("socket send vp_length = %d", vp_length);
	if(Socket_Id[1]>=0)
	{
		if(Cms_GetWTPSendRedirectAbotFlag() == 1)
		{
			nrect = soc_sendto(Socket_Id[1], (kal_uint8 *)pp_data, (kal_int32)vp_length, 0, &mms_sock_addr);
			Cms_SetWTPSendRedirectAbotFalg(0);
		}
		else
		{
			if(Cms_GetWspRedirectFlag() == 1)
			{
				Cms_GetRedirectSetting();
			}
			nrect = soc_sendto(Socket_Id[1], (kal_uint8 *)pp_data, (kal_int32)vp_length, 0, &mms_sock_addr);
		}
	}	
	else if(Socket_Id[2]>=0)
	{
		if(Cms_GetWTPSendRedirectAbotFlag() == 1)
		{
			nrect = soc_sendto(Socket_Id[2], (kal_uint8 *)pp_data, (kal_int32)vp_length, 0, &sock_addr);
			Cms_SetWTPSendRedirectAbotFalg(0);
		}
		else
		{
			if(Cms_GetWspRedirectFlag() == 1)
			{
				Cms_GetRedirectSetting();
			}
			nrect = soc_sendto(Socket_Id[2], (kal_uint8 *)pp_data, (kal_int32)vp_length, 0, &sock_addr);
		}
	}
	adp_mmi_tracer("socket send............nrect==%d.....",(kal_char*)nrect);

	if (nrect > 0)
	{  
	
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_RecvPDU
 *       Purpose: recv udp data
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_RecvPDU(void *pp_data,long *pp_length,unsigned char *host,int port)
{
	kal_int32 	nRead = 0;	
	adp_Tracer("Cms_RecvPDU.................in");
	if(Socket_Id[1]>=0)
	{
		nRead = (long)soc_recvfrom(Socket_Id[1], (byte *)pp_data, RECVDATABUF, 0,  &mms_sock_addr);
		*pp_length = nRead;	
	}	
	else if(Socket_Id[2]>=0)
	{
		nRead = (long)soc_recvfrom(Socket_Id[2], (byte *)pp_data, RECVDATABUF, 0,  &sock_addr);
		*pp_length = nRead;
	}
	adp_mmi_tracer("mms:socket receive pp_length = %d", *pp_length);
	adp_mmi_tracer("mms:socket receive rect = %d", nRead);
	if (nRead > 0)
	{
		adp_mmi_tracer("mms:socket receive.... = %d", nRead);
	}
	else
	{
		adp_Tracer("mms:socket receive failed or unbolcked");
		*pp_length = 0;
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: mmswtptimerout
 *       Purpose: mms timerout callback 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmswtptimerout(void * time)
{
	adp_Tracer("==mmswtptimerout==");
#ifdef MMS_SUPPORT_WAP12
	mmsEventPostEvent(WTP_TIMEROUT_MSG,0,NULL);
	mmsEventProcessEvent();
#else
	
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: wapwtptimerout
 *       Purpose: wap timerout callback 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void wapwtptimerout(void * time)
{
	int *data=(int *)time;
	
	//adp_Tracer("==wapwtptimerout==");
	adp_mmi_tracer("==wapwtptimerout %d==",(char*)data);
/*20060914 wantao modify*/
	if(1 == CmsGetNetType())
	{
		brwEventPostEvent(BRW_WTP_TIMEROUT_MSG,0,NULL);
		brwEventProcessEvent();
	}
	else
	{
		mmsEventPostEvent(WTP_TIMEROUT_MSG,0,NULL);
		mmsEventProcessEvent();		
	}
}
/******************************************************************************
 *                           certificate manage		                       *
 ******************************************************************************/

 /******************************************************************************
 *                           timer manage		                       *
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetTickCounterValue
 *       Purpose: Calculates the processor time
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
unsigned long Cms_GetTickCounterValue ( void )
{
	return (unsigned long)CmsGetCurrentTime();
}
 /* ----------------------------------------------------------------------------
 * Function Name: CmsGetCurrentTime
 *       Purpose: Get Current time
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
long CmsGetCurrentTime(void)
{
	MYTIME			t;
    char			ret[64]; 
	char            temp[64];
	long   time = 0;
	
	GetDateTime(&t);     
	#if 0
	sprintf(ret,"%d",t.nYear);
    	sprintf(temp,"%d",t.nMonth);
	strcat(ret,(const char*)temp);
	sprintf(temp,"%d",t.nDay);
	strcat(ret,(const char*)temp);
	sprintf(temp,"%d",t.nHour);
	strcat(ret,(const char*)temp);
	sprintf(temp,"%d",t.nMin);
	strcat(ret,(const char*)temp);
	sprintf(temp,"%d",t.nSec);
	strcat(ret,(const char*)temp);
	sprintf(temp,"%d",t.DayIndex);
	strcat(ret,(const char*)temp);
	#endif
	return  mmi_dt_mytime_2_utc_sec(&t, 0);
	//time = atoi(ret);
	//return time;
}	
  /* ----------------------------------------------------------------------------
 * Function Name: CmsGetCurrentMtkTime
 *       Purpose: 获取当前平台格式时间
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void CmsGetCurrentMtkTime(P_CMS_BROWSER_U8 cmstime)
{
	MYTIME			t;

	GetDateTime(&t);     
	sprintf((char *)cmstime,"%d",t.nYear);
	adp_mmi_tracer("nYear=%d",(char*)t.nYear);
	Cms_hex_trace((kal_uint8 *)cmstime, (kal_int32)(sizeof(char)*12));
	if(t.nMonth < 10)
	{
		sprintf((char *)(cmstime+4),"%d",0);
		sprintf((char *)(cmstime+5),"%d",t.nMonth);
	}
	else
	{
		sprintf((char *)(cmstime+4),"%d",t.nMonth);
	}
    	
	adp_mmi_tracer("nMonth=%d",(char*)t.nMonth);	
	Cms_hex_trace((kal_uint8 *)cmstime, (kal_int32)(sizeof(char)*12));
	if(t.nDay < 10)
	{
		sprintf((char *)(cmstime+6),"%d",0);
		sprintf((char *)(cmstime+7),"%d",t.nDay);
	}
	else
	{
		sprintf((char *)(cmstime+6),"%d",t.nDay);
	}
	adp_mmi_tracer("nDay=%d",(char*)t.nDay);
	Cms_hex_trace((kal_uint8 *)cmstime, (kal_int32)(sizeof(char)*12));
	if(t.nHour < 10)
	{	
		sprintf((char *)(cmstime+8),"%d",0);
		sprintf((char *)(cmstime+9),"%d",t.nHour);
	}
	else
	{
		sprintf((char *)(cmstime+8),"%d",t.nHour);
	}
	
	adp_mmi_tracer("nHour=%d",(char*)t.nHour);
	Cms_hex_trace((kal_uint8 *)cmstime, (kal_int32)(sizeof(char)*12));
	if(t.nMin < 10)
	{
		sprintf((char *)(cmstime+10),"%d",0);
		sprintf((char *)(cmstime+11),"%d",t.nMin);
	}
	else
	{
		sprintf((char *)(cmstime+10),"%d",t.nMin);
	}
	
	adp_mmi_tracer("nMin=%d",(char*)t.nMin);
	Cms_hex_trace((kal_uint8 *)cmstime, (kal_int32)(sizeof(char)*12));
	return;
}

  /* ----------------------------------------------------------------------------
 * Function Name: mms_StartTimer
 *       Purpose: 启动定时器
 *         Input:  None
 *        Output: None.
 *       Returns: .
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_StartTimer(unsigned char id,long ms)
{
	adp_mmi_tracer("mms_StartTimer=%d",(char*)id);
	if (id == 1)
	{
		adp_mmi_tracer("mms_StartTimer1=%d",(char*)id);	
		id=id+CMS_WAPMMS_TIMER_BASE;
		StartTimerEx(id,ms,mmswtptimerout,NULL);
	}
	else
	{
		adp_mmi_tracer("mms_StartTimer2=%d",(char*)id);		
		id=id+CMS_WAPMMS_TIMER_BASE;
		//StartMyTimerInt(id,ms,wapwtptimerout,0);
		StartTimerEx(id,ms,wapwtptimerout,NULL);//mod by danny 20080130
	}
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_StopTimer
 *       Purpose: 关闭定时器
 *         Input:  None
 *        Output: None.
 *       Returns: .
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mms_StopTimer (unsigned char id)
{
	adp_mmi_tracer("mms_StopTimer = %d", id);
	id=id+CMS_WAPMMS_TIMER_BASE;
	StopTimer(id);
}

/*==============================================================
*   Function Name:	brw_StartTimer
*   Input        :  int timerid
					int timeout
*   Output       :  void
*   description  :	MTK start appoint timerid timer
*   author       :  
*   date         :
==============================================================*/
void brw_StartTimer(int timerid,int timeout)
{	
	if(timerid==3) 
	{
		timerid=timerid+CMS_WAPMMS_TIMER_BASE;
		StartTimerEx(timerid,timeout,Cms_Brw_MarqueeTimeExpier,0);
	}
	else
	{
		WmlTimer_DefaultID = timerid;
		timerid=timerid+CMS_WAPMMS_TIMER_BASE;		
		StartTimerEx(timerid,timeout,WmlTimerOut,0);
	}	
}
/*==============================================================
*   Function Name:	brw_StopTimer
*   Input        :  void
*   Output       :  void
*   description  :	stop MTK timerid timer
*   author       :  
*   date         :
==============================================================*/
void brw_StopTimer(int timerid)
{
	timerid=timerid+CMS_WAPMMS_TIMER_BASE;
	StopTimer(timerid);
}

/*==============================================================
*   Function Name:	WmlTimerOut
*   Input        :  void *time
*   Output       :  void
*   description  :	transfer Cms_Browser_TimerExpireEvent function when WmlTimer_DefaultID expire
*   author       :  
*   date         :
==============================================================*/
void WmlTimerOut(void *time)
{
	Cms_Browser_TimerExpireEvent(WmlTimer_DefaultID);
}
 /******************************************************************************
 *                           				trace interface		                       *
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: mms_Tracer
 *       Purpose: mms trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 /*彩信Tracer*/
void mms_Tracer(char* pData)
{
#ifdef TRACE_FOR_MTK
    if (NULL != pData) 
    {
		kal_prompt_trace(MOD_NVRAM, (char *)pData);
    }	
#endif	
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_mms_mmi_tracer
 *       Purpose: mms trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_mms_mmi_tracer(kal_char * data, kal_char * data1)
{
#ifdef TRACE_FOR_MTK
	kal_prompt_trace(MOD_NVRAM, (kal_char *)data, (kal_char *)data1);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_adp_mmi_tracer
 *       Purpose: adp trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
/* 适配层Tracer*/
void cms_adp_mmi_tracer(kal_char * data, kal_char * data1)
{
#ifdef TRACE_FOR_MTK
	kal_prompt_trace(MOD_NVRAM, (kal_char *)data, (kal_char *)data1);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_adp_Tracer
 *       Purpose: adp trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_adp_Tracer(kal_char * data)
{
#ifdef TRACE_FOR_MTK
	if (NULL != data && 0 != strlen((char *)data)) 
	{
		kal_prompt_trace(MOD_NVRAM, (kal_char *)data);
	}
#endif	
}
  /* ----------------------------------------------------------------------------
 * Function Name: cms_syncml_mmi_tracer
 *       Purpose: adp trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
/* SyncML ApplicationTracer*/
void cms_syncml_mmi_tracer(kal_char * data, kal_char * data1)
{
#ifdef TRACE_FOR_MTK
	kal_prompt_trace(MOD_NVRAM, (kal_char *)data, (kal_char *)data1);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_syncml_Tracer
 *       Purpose: syncml trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_syncml_Tracer(kal_char * data)
{
#ifdef TRACE_FOR_MTK
	if (NULL != data && 0 != strlen((char *)data)) 
	{
		kal_prompt_trace(MOD_NVRAM, (kal_char *)data);
	}
#endif	
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_hex_trace
 *       Purpose:打印数据
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_hex_trace(kal_uint8 *buf,kal_int32 pdu_len)
{
#ifdef TRACE_FOR_MTK
	char        tracebuf[128] = {0};
	char        temp[20] = {0};
	int         j = 0,k = 0;

	while ( (k*16) < pdu_len)
	{
		j = 0;
		memset(tracebuf, 0, 128);
		memset(temp,0,20);
		while ( (j < 16) && ((k*16+j)< pdu_len))
		{
			sprintf(temp, "0x%02X, ", buf[k*16+j]);
			strcat(tracebuf,temp);
			j++;
		}	
		kal_prompt_trace(MOD_NVRAM,"socket recv buf : %s", tracebuf);
		k++;
	}
#endif	
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_browser_mmi_tracer
 *       Purpose: browser trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
/* 浏览器Tracer*/
void cms_browser_mmi_tracer(kal_char * data, kal_char * data1)
{
#ifdef TRACE_FOR_MTK
	kal_prompt_trace(MOD_NVRAM, (kal_char *)data, (kal_char *)data1);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_wap_Tracer
 *       Purpose: browser trace
 *         Input:  None
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void cms_wap_Tracer(kal_char * data)
{
#ifdef TRACE_FOR_MTK
	if (NULL != data && 0 != strlen((char *)data)) 
	{
		kal_prompt_trace(MOD_NVRAM, (kal_char *)data);
	}
#endif	
}
 /******************************************************************************
 *                           			Cache & Snapshot		                       *
 ******************************************************************************/ 
/* ----------------------------------------------------------------------------
 * Function Name: Cms_GetCacheBlockLength
 *       Purpose: get the cache length
 *         Input:  None
 *        Output: None.
 *       Returns: the cache length.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
S32 Cms_GetCacheBlockLength(void)
{
	return CMS_CACHEDATABUF;
}
/* ----------------------------------------------------------------------------
 * Function Name: Cms_LoadCache
 *       Purpose: add the cache from flash to memory
 *         Input:  None
 *        Output: None.
 *       Returns: .
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void * Cms_LoadCache(void)
{	
	int mtkcache = NULL;
	unsigned char *tempbuf=NULL;
	unsigned int nread;
	unsigned int size;
	tempbuf = (unsigned char *)cms_malloc(CMS_CACHEDATABUF);
	cms_memset(tempbuf,0x0,CMS_CACHEDATABUF);
	if (tempbuf == NULL)
	{	
		return NULL;
	}
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapCachefilename(wap_filename);	
	mtkcache = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtkcache = FS_Open(L"C:\\wap\\CmsCacheFile.cnf",FS_READ_ONLY);
	if (mtkcache < 0)
	{
		mtkcache = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
		//mtkcache = FS_Open(L"C:\\wap\\CmsCacheFile.cnf",FS_CREATE);
		if (mtkcache < 0)
		{
			return NULL;
		}
		else
		{
			cms_memset(tempbuf, 0, CMS_CACHEDATABUF);		
			FS_Close(mtkcache);		
		}
	}
	else
	{
		cms_memset(tempbuf, 0, CMS_CACHEDATABUF);
		FS_GetFileSize(mtkcache, &size);			
		if((int)size>=CMS_CACHEDATABUF||(int)size<=0)
		{
			FS_Close(mtkcache);
			return tempbuf;
		}
		FS_Read(mtkcache, tempbuf, size, &nread);		
		FS_Close(mtkcache);
	}
	return 	tempbuf;
}
/* ----------------------------------------------------------------------------
 * Function Name: Cms_SaveCache
 *       Purpose: save the cache from memory to flash
 *         Input:  p_add(the cache pointer),len(the cache length)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_SaveCache(void * p_add, unsigned int len)
{
	//FS_Delete(L"C:\\wap\\CmsCacheFile.cnf");
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapCachefilename(wap_filename);	
	Cms_Adp_fdelete((const unsigned short *) wap_filename);
	if (len > 0 && p_add != NULL)
	{		
		unsigned int nwrite;
		int mtkcache = NULL;
		
		mtkcache = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);
		//mtkcache = FS_Open(L"C:\\wap\\CmsCacheFile.cnf",FS_CREATE);
		if (mtkcache < 0)
		{				
			return;
		}
		if((int)len<=0||(int)len>CMS_CACHEDATABUF)
		{
			FS_Close(mtkcache);
			return ;
		}	
		if(Cms_Adp_JudgeCSpace((int)len))	
		{
			FS_Close(mtkcache);
			DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
			return ;		
		}
		FS_Write(mtkcache, p_add, (unsigned int)len, &nwrite);
		FS_Close(mtkcache);
	}

}
/* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_SavePageSize
 *       Purpose: get the max size of save SNAPSHOT page 
 *         Input:  None
 *        Output: None.
 *       Returns: the max size of save SNAPSHOT page.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_Browser_SavePageSize(void)
{
	return CMS_SNAPSHOT_SIZE;
}
/* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_GetSavePageBuf
 *       Purpose: get the address of save SNAPSHOT page 
 *         Input:  None
 *        Output: None.
 *       Returns: the address of save SNAPSHOT page.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
char* Cms_Browser_GetSavePageBuf(void)
{
	char* PageBuff=NULL;
	PageBuff=cms_malloc(CMS_SNAPSHOT_SIZE);
	if(PageBuff==NULL)	
	{
		adp_Tracer("Save page buff is NULL");
		return NULL;
	}	
	else
		return PageBuff;
}
/******************************************************************************
                 				audio		                   
 ******************************************************************************/
/* ----------------------------------------------------------------------------
 * Function Name: Cms_PlayMusic
 *       Purpose: play music
 *         Input:  data_buf(the data of the music),data_len(the data length of the music)
 *			  content_type(the music formart)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
 #include "Aud_defs.h"
 unsigned char* PlayMusicBuffer=NULL;
void Cms_PlayMusic(unsigned char *data_buf,int data_len,Cms_ContentType_e content_type)
{
	if(PlayMusicBuffer!=NULL)
	{
		cms_free(PlayMusicBuffer);
		PlayMusicBuffer=NULL;
	}
	if(data_len>0)
		PlayMusicBuffer=(unsigned char*)cms_malloc(data_len+1);
	else
		return ;	

	if(PlayMusicBuffer!=NULL && data_buf!=NULL)
	{
		cms_memset(PlayMusicBuffer,0x0,data_len+1);
		cms_memcpy(PlayMusicBuffer,data_buf,data_len);	
	}	
	else
		return ;

	browser_mmi_tracer("content_type=%d",(char*)content_type);
	switch(content_type)
	{
	/*
	case MMS_TYPE_WAV:
		PlayAudioWavStream(PlayMusicBuffer, data_len, DEVICE_AUDIO_PLAY_INFINITE);
		break;
	case MMS_TYPE_IMY:
		PlayAudioStream(PlayMusicBuffer, data_len,MEDIA_IMELODY,DEVICE_AUDIO_PLAY_INFINITE);
		break;
	*/	
	case CMS_HTTP_CONTENT_MIDI:
		PlayAudioMidiStream(PlayMusicBuffer, data_len, DEVICE_AUDIO_PLAY_ONCE);
		break;	
	case CMS_HTTP_CONTENT_AMR:
		PlayAudioStream(PlayMusicBuffer, data_len, MEDIA_AMR,DEVICE_AUDIO_PLAY_ONCE);
		break;
	case CMS_HTTP_CONTENT_MP3:
		PlayAudioStream(PlayMusicBuffer, data_len, MEDIA_DAF,DEVICE_AUDIO_PLAY_ONCE);
		break;
	default:		
		break;	
	}

}
/* ----------------------------------------------------------------------------
 * Function Name: Cms_StopMusic
 *       Purpose: stop play music
 *         Input:  data_buf(the data of the music),data_len(the data length of the music)
 *			  content_type(the music formart)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void Cms_StopMusic (void)
{
	if(PlayMusicBuffer!=NULL)
	{
		cms_free(PlayMusicBuffer);
		PlayMusicBuffer=NULL;
	}
	StopAudioStream();	
}
/******************************************************************************
 *                           				browser setting		                       *
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_GetImageSetting
 *       Purpose: get the image setting value(yes or no to download audio)
 *         Input:  None
 *        Output: None.
 *       Returns: 1,petmit to download the image.
 *			  0,forbit to download image.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_Browser_GetImageSetting( void )
{
	return Cms_Browser_GetImgSetup();
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_GetMusicSetting
 *       Purpose: get the audio setting value(yes or no to download audio)
 *         Input:  None
 *        Output: None.
 *       Returns: 1,petmit to download the background music.
 *			  0,forbit to download the background music.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_Browser_GetMusicSetting( void )
{
	return OpenBGMusic;
}

 void Cms_Browser_SetupMusicOn(void)
 {
  	OpenBGMusic=1;
 }

void Cms_Browser_SetupMusicOff(void) 	
{
 	OpenBGMusic=0;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_GetPushMessageSetting
 *       Purpose: yes or no to open the push set
 *         Input:  None
 *        Output: None.
 *       Returns: 1,yes.
 *			  0,no
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_Browser_GetPushMessageSetting( void )
{
	return OPenPushMessage;
}

void Cms_Browser_SetupPushMessageOn(void)
{
  	OPenPushMessage=1;
}

void Cms_Browser_SetupPushMessageOff(void) 	
{
 	OPenPushMessage=0;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Brower_GetSecuritySetting
 *       Purpose: yes or no to open the security set
 *         Input:  None
 *        Output: None.
 *       Returns: 1,yes.
 *			  0,no
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 int Cms_Brower_GetSecuritySetting( void )
{
	return OPenSecurity;
}
void Cms_Browser_SetupSecurityOn(void)
{
  	OPenSecurity=1;
}
void Cms_Browser_SetupSecurityOff(void) 	
{
 	OPenSecurity=0;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Mms_GetSecuritySetting
 *       Purpose: yes or no to open the security set
 *         Input:  None
 *        Output: None.
 *       Returns: 1,yes.
 *			  0,no
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Mms_Is_Security_Connect = 0;
int Cms_Mms_GetSecuritySetting( void )
{
	return Mms_Is_Security_Connect;
}
void Cms_Mms_SetSecuritySetting( int flag )
{
	Mms_Is_Security_Connect = flag;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetDownloadMaxSize
 *       Purpose: get the max download size
 *         Input:  None
 *        Output: None.
 *       Returns: the max download size
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_GetDownloadMaxSize(void)
{
	return WAP_DOWNLOAD_MAX_SIZE;
}

 int Cms_GetJadMaxSize(void)
 {
  	return WAP_JAD_MAX_SIZE;
 }
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetLanguage
 *       Purpose: get the language format
 *         Input:  None
 *        Output: None.
 *       Returns: 1,Chinese.
 *			  0,English
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
extern sLanguageDetails gLanguageArray[MAX_LANGUAGES];
extern U16 	gCurrLangIndex;
int Cms_GetLanguage(void)
{
	adp_Tracer("enter Cms_GetLanguage");
	if(gCurrLangIndex == 0)
	{
		adp_Tracer(" Cms_GetLanguage CMS_ENGLISH");
		return CMS_ENGLISH;
	}	
	else if(gCurrLangIndex == 1) 
	{
		adp_Tracer(" Cms_GetLanguage1 CMS_CHINESE");	
		return CMS_CHINESE;
	}	
	else
	{
		adp_Tracer(" Cms_GetLanguage2 CMS_CHINESE");	
		return CMS_CHINESE;
	}	

}
 /* ----------------------------------------------------------------------------
 * Function Name: CmsGetNetType
 *       Purpose: get the current network type 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,cmnet.
 *			  0,cmwap
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int	CmsGetNetType( void )
{
	adp_mmi_tracer( "CmsGetNetType : %d\n", m_NetType );
#ifdef SUPPORT_SWITCH_PROTOCOL	
	return m_NetType;
#else
	return CMS_WAP_CONNECT_HTTP;
#endif
}
  /* ----------------------------------------------------------------------------
 * Function Name: CmsGetWapSupportArea
 *       Purpose: get the current area type 
 *         Input:  None
 *        Output: None.
 *       Returns: the area
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int	CmsGetWapSupportArea(void)
{
	return CURRENT_WAP_SUPPORT_AREA;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_SetupNetTypeOn
 *       Purpose: set current network type :http
 *         Input:  None
 *        Output: None
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void Cms_Browser_SetupNetTypeHttp(void)
{
  	m_NetType = CMS_WAP_CONNECT_HTTP;//http
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_SetupNetTypeOff
 *       Purpose: set current network type :WAP1.2.1
 *         Input:  None
 *        Output: None
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void Cms_Browser_SetupNetTypeWap(void) 	
{
 	m_NetType = CMS_WAP_CONNECT_WAP;//wap1.2
}
 /* ----------------------------------------------------------------------------
 * Function Name: brw_GetGatewayParameter
 *       Purpose: get the current gateway setting parameter  
 *         Input:  None
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void brw_GetGatewayParameter(unsigned char *p_Ip, int *p_Port)
{
	adp_Tracer("brw_GetGatewayParameter:\n" );
	p_Ip[0] = 0x0a;
	p_Ip[1] = 0x00;
	p_Ip[2] = 0x00;
	p_Ip[3] = 0xac;

	*p_Port = 80;
	return;
}
/* ----------------------------------------------------------------------------
 * Function Name: CTLprovisioning
 *       Purpose: get the current browser setting parameter  
 *         Input:  pBrowerSetting(browser setting),pBookmarkSetting(bookmark setting)
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
#ifdef SUPPORT_SMSMMS_COMBINE
extern void mms_file_manager_free_message(P_MESSAGELIST mlist);
extern void mms_file_manager_add_message_to_folder(P_MESSAGELIST mmsDigest, MMS_FOLDER_NAME folder, SET_MESSAGE flag);
#endif
void CTLprovisioning(P_CMS_SETTING pBrowerSetting,P_CMS_BOOKMARK pBookmarkSetting)
{
#ifdef SUPPORT_SMSMMS_COMBINE
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    	P_MESSAGELIST 		pMsg=NULL;
    	MMS_FOLDER_NAME 	folder;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mms_Tracer("^_^CTLprovisioning in");
	mmi_wapmms_judge_recv_wappush_del_last();

	pMsg = (P_MESSAGELIST)mms_Malloc(sizeof(MESSAGELIST));
	if (!pMsg)
	{
		mms_Tracer((char*)"fail to allocate pMsg!!!");
		return ;
	}
	memset(pMsg, 0, sizeof(MESSAGELIST));
	
	if(NULL != pBrowerSetting )
	{
		pMsg->msgtype=MESSAGE_OTA_SET;
		mms_Tracer("^_^CTLprovisioning in1");
		Cms_hex_trace(pBrowerSetting->pName, 20);
		mms_Tracer("^_^CTLprovisioning in2");
		Cms_hex_trace(pBrowerSetting->pID, 20);
		mms_Tracer("^_^CTLprovisioning in3");
		Cms_hex_trace(pBrowerSetting->Address.pISPName, 20);
		mms_Tracer("^_^CTLprovisioning in4");

		Cms_hex_trace(pBrowerSetting->Bookmark.pName, 20);
		mms_Tracer("^_^CTLprovisioning in5");
		Cms_hex_trace(pBrowerSetting->pMMSCenter, 20);
		mms_Tracer("^_^CTLprovisioning in6");
		Cms_hex_trace(pBrowerSetting->Address.PROXY.pPROXY, 20);
		mms_Tracer("^_^CTLprovisioning in7");
		Cms_hex_trace(pBrowerSetting->Address.pGPRSAccessPointName, 20);
		mms_Tracer("^_^CTLprovisioning in8");
		Cms_hex_trace(pBrowerSetting->Address.pPort, 20);
		
		if(NULL != pBrowerSetting->pName)
		{
			/* subject */
			pMsg->subject= (S8*)mms_Malloc(MMS_MAX_UTF_SUBJECT_SIZE);
			if (!pMsg->subject)
			{
				mms_Tracer((char*)"add wap push node...fail to allocate date!!!");
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->subject, 0, MMS_MAX_UTF_SUBJECT_SIZE);
			strcpy(pMsg->subject,(char*)pBrowerSetting->pName);
		}
		if(NULL != pBrowerSetting->pHomepage)
		{
			/* homepage url */
			pMsg->url = (S8*)mms_Malloc(MAX_URL_LENGTH);
			if (!pMsg->url)
			{
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->url, 0, MAX_URL_LENGTH);
			strcpy(pMsg->url,(char*)pBrowerSetting->pHomepage);
		}	
		if(NULL != pBrowerSetting->Address.pPort)
		{
			/* port */
			pMsg->ota_port= (S8*)mms_Malloc(MMS_MAX_INPUT_PORT_LENGTH);
			if (!pMsg->ota_port)
			{
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->ota_port, 0, MMS_MAX_INPUT_PORT_LENGTH);
			strcpy(pMsg->ota_port,(char*)pBrowerSetting->Address.pPort);
		}
		if(NULL != pBrowerSetting->Address.pSMSCAddress)
		{
			/* Address.pSMSCAddress */
			pMsg->ota_smsc= (S8*)mms_Malloc(MAX_URL_LENGTH);
			if (!pMsg->ota_smsc)
			{
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->ota_smsc, 0, MAX_URL_LENGTH);
			strcpy(pMsg->ota_smsc,(char*)pBrowerSetting->Address.pSMSCAddress);
		}			
		if(NULL != pBrowerSetting->pMMSCenter)
		{
			/* ota_murl */
			pMsg->ota_murl= (S8*)mms_Malloc(MAX_URL_LENGTH);
			if (!pMsg->ota_murl)
			{
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->ota_murl, 0, MAX_URL_LENGTH);
			strcpy(pMsg->ota_murl,(char*)pBrowerSetting->pMMSCenter);
		}	
		if(NULL != pBrowerSetting->Address.pGPRSAccessPointName)
		{
			/* AccessPointName */
			pMsg->ota_apn= (S8*)mms_Malloc(MAX_URL_LENGTH);
			if (!pMsg->ota_apn)
			{
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->ota_apn, 0, MAX_URL_LENGTH);
			strcpy(pMsg->ota_apn,(char*)pBrowerSetting->Address.pGPRSAccessPointName);
		}

		/*PROXY*/
		{
			if(NULL != pBrowerSetting->Address.PROXY.pPROXY)
			{
				/* PROXY*/
				pMsg->ota_gateway= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_gateway)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_gateway, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_gateway,(char*)pBrowerSetting->Address.PROXY.pPROXY);
			}
			if(NULL != pBrowerSetting->Address.PROXY.pAuthName)
			{
				/* PROXY.pAuthName*/
				pMsg->ota_user= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_user)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_user, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_user,(char*)pBrowerSetting->Address.PROXY.pAuthName);
			}
			if(NULL != pBrowerSetting->Address.PROXY.pAuthSecret)
			{
				/* PROXY.pAuthSecret*/
				pMsg->ota_passw= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_passw)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_passw, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_passw,(char*)pBrowerSetting->Address.PROXY.pAuthSecret);
			}
			if(NULL != pBrowerSetting->Address.PROXY.pLoginType)
			{
				/* PROXY.pLoginType*/
				pMsg->ota_logintype= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_logintype)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_logintype, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_logintype,(char*)pBrowerSetting->Address.PROXY.pLoginType);
			}
		}
		/*PPP */
		{
			if(NULL != pBrowerSetting->Address.PPP.pAuthName)
			{
				/* PPP.pAuthName*/
				pMsg->ota_user= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_user)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_user, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_user,(char*)pBrowerSetting->Address.PPP.pAuthName);
			}
			if(NULL != pBrowerSetting->Address.PPP.pAuthSecret)
			{
				/* PPP.pAuthSecret*/
				pMsg->ota_passw= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_passw)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_passw, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_passw,(char*)pBrowerSetting->Address.PPP.pAuthSecret);
			}
			if(NULL != pBrowerSetting->Address.PPP.pAuthType)
			{
				/* PPP.pAuthType*/
				pMsg->ota_authtype= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_authtype)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_authtype, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_authtype,(char*)pBrowerSetting->Address.PPP.pAuthType);
			}
			if(NULL != pBrowerSetting->Address.PPP.pLoginType)
			{
				/* PPP.pLoginType*/
				pMsg->ota_logintype= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_logintype)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_logintype, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_logintype,(char*)pBrowerSetting->Address.PPP.pLoginType);
			}
		}
		/*CSD*/
		{
			if(NULL != pBrowerSetting->Address.CSD.pDialString)
			{
				/* CSD.pDialString*/
				pMsg->ota_user= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_user)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_user, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_user,(char*)pBrowerSetting->Address.CSD.pDialString);
			}
			if(NULL != pBrowerSetting->Address.CSD.pCallType)
			{
				/* CSD.pCallType*/
				pMsg->ota_authtype= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_authtype)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_authtype, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_authtype,(char*)pBrowerSetting->Address.CSD.pCallType);
			}
			if(NULL != pBrowerSetting->Address.CSD.pCallSpeed)
			{
				/* CSD.pCallSpeed*/
				pMsg->ota_passw= (S8*)mms_Malloc(MAX_URL_LENGTH);
				if (!pMsg->ota_passw)
				{
					mms_file_manager_free_message(pMsg);
					pMsg = NULL;
					return ;
				}
				memset(pMsg->ota_passw, 0, MAX_URL_LENGTH);
				strcpy(pMsg->ota_passw,(char*)pBrowerSetting->Address.CSD.pCallSpeed);
			}
		}	

		cms_trace("CTLprovisioning: Cms_Browser_NewBookmarkAdd432");
	}
	else
	{
		pMsg->msgtype=MESSAGE_OTA_BOOKMARK;
		Cms_hex_trace(pBookmarkSetting->pName, 40);
		if(NULL != pBookmarkSetting->pName)
		{
			cms_trace("CTLprovisioning: Cms_Browser_NewBookmarkAdd11ret");
			/* subject */
			pMsg->subject= (S8*)mms_Malloc(MMS_MAX_UTF_SUBJECT_SIZE);
			if (!pMsg->subject)
			{
				mms_Tracer((char*)"subject malloc failed");
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->subject, 0, MMS_MAX_UTF_SUBJECT_SIZE);
			strcpy(pMsg->subject,(char*)pBookmarkSetting->pName);
		}
		if( NULL != pBookmarkSetting->pURL)
		{
			cms_trace("CTLprovisioning: Cms_Browser_NewBookmarkAdd1133");
			/* url */
			pMsg->url = (S8*)mms_Malloc(MAX_URL_LENGTH);
			if (!pMsg->url)
			{
				mms_file_manager_free_message(pMsg);
				pMsg = NULL;
				return ;
			}
			memset(pMsg->url, 0, MAX_URL_LENGTH);
			strcpy(pMsg->url,(char*)pBookmarkSetting->pURL);
		}
	}
	/* date */	
	pMsg->date = (S8*)mms_Malloc(MMS_MAX_DATE_LEN);
	if (!pMsg->date)
	{
		mms_Tracer((char*)"add wap push node...fail to allocate date!!!");
		mms_file_manager_free_message(pMsg);
		pMsg = NULL;
		return ;
	}
	memset(pMsg->date, 0, MMS_MAX_DATE_LEN);
	CmsTime2String(pMsg->date);
	mms_mmi_tracer("^_^pmsg->date=%s", (char*)pMsg->date);	

	pMsg->state='U';
	folder=MMS_RECEIVE_FOLDER;
	
	mms_file_manager_add_message_to_folder(pMsg,folder,SET_MESSAGE_NULL);
	mms_file_manager_free_message(pMsg);
	cms_trace("CTLprovisioning: Cms_Browser_NewBookmarkAdd:out");
#else
	//写数据到Push结构
	Cms_Browser_SaveOTAPush(pBrowerSetting,pBookmarkSetting);
#endif	
}
/******************************************************************************
                        				Pictogram	                     
 ******************************************************************************/ 
  /* ----------------------------------------------------------------------------
 * Function Name: cms_getpictogram
 *       Purpose: 
 *         Input:  pict_name,pict_type,pict_size,pict_content
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int cms_getpictogram(char *pict_name,	Cms_ContentType_e  *pict_type,	unsigned	int	  *pict_size,unsigned	char **pict_content )
{
	int		ret = 0;
	S8*  	image_buf = NULL;
	/* check param */
	if( NULL == pict_name )
	{
		return 0;
	}
	cms_trace("enter cms_getpictogram");
	if( NULL != cms_strstr(pict_name,"core/arrow/up") )
	{
		cms_trace("core/arrow/up");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_UP_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/arrow/down") )
	{
		cms_trace("core/arrow/down");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_DOWN_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/arrow/right") )
	{
		cms_trace("core/arrow/right");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_RIGHT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/arrow/left") )
	{
		cms_trace("core/arrow/left");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_LEFT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/arrow/upperRight") )
	{
		cms_trace("core/arrow/upperRight");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_UPPERRIGHT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/arrow/upperLeft") )
	{
		cms_trace("core/arrow/upperLeft");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_UPPERLEFT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/arrow/lowerRight") )
	{
		cms_trace("core/arrow/lowerRight");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_LOWERRIGHT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/arrow/lowerLeft") )
	{
		cms_trace("core/arrow/lowerLeft");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_LOWERLEFT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/arrow/fingerUp") )
	{
		cms_trace("core/arrow/fingerUp");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERUP_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;				
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/arrow/fingerDown") )
	{
		cms_trace("core/arrow/fingerDown");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERDOWN_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;				
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/arrow/fingerRight") )
	{
		cms_trace("core/arrow/fingerRight");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERRIGHT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;				
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/arrow/fingerLeft") )
	{
		cms_trace("core/arrow/fingerRight");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ARROW_FINGERLEFT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/1") )
	{
		cms_trace("core/button/1");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_1_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/button/2") )
	{
		cms_trace("core/button/2");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_2_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;				
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/3") )
	{
		cms_trace("core/button/3");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_3_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/4") )
	{
		cms_trace("core/button/4");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_4_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/5") )
	{
		cms_trace("core/button/5");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_5_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/6") )
	{
		cms_trace("core/button/6");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_6_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/7") )
	{
		cms_trace("core/button/7");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_7_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/8") )
	{
		cms_trace("core/button/8");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_8_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/9") )
	{
		cms_trace("core/button/9");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_9_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/button/0") )
	{
		cms_trace("core/button/0");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_BUTTON_0_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;		
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/makePhoneCall") )
	{
		cms_trace("core/action/makePhoneCall");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_MAKEPHONECALL_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;				
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/find") )
	{
		cms_trace("core/action/find");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_FIND_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/userAuthentication") )
	{
		cms_trace("core/action/userAuthentication");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_USERAUTHENTICATION_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/nextltem") )
	{
		cms_trace("core/action/nextltem");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_NEXTITEM_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/action/clear") )
	{
		cms_trace("core/action/clear");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_CLEAR_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/stop") )
	{
		cms_trace("core/action/stop");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_STOP_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/top") )
	{
		cms_trace("core/action/top");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_TOP_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/action/next") )
	{
		cms_trace("core/action/next");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_NEXT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/action/back") )
	{
		cms_trace("core/action/back");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_ACTION_BACK_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/message/receive") )
	{
		cms_trace("core/message/receive");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_RECEIVE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/message/send") )
	{
		cms_trace("core/message/send");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_SEND_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/message/message") )
	{
		cms_trace("core/message/message");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_MESSAGE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/message/attachment") )
	{
		cms_trace("core/message/attachment");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_ATTACHMENT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/message/folder") )
	{
		cms_trace("core/message/folder");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_FOLDER_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}
	else if( NULL != cms_strstr(pict_name,"core/message/inbox") )
	{
		cms_trace("core/message/inbox");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_INBOX_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/message/outbox") )
	{
		cms_trace("core/message/outbox");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MESSAGE_OUTBOX_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/state/secure") )
	{
		cms_trace("core/state/secure");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_STATE_SECURE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/state/insecure") )
	{
		cms_trace("core/state/insecure");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_STATE_INSECURE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/state/copyright") )
	{
		cms_trace("core/state/copyright");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_STATE_COPYRIGHT_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/state/trademark") )
	{
		cms_trace("core/state/trademark");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_STATE_TRADEMARK_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/state/underConstruction") )
	{
		cms_trace("core/state/underConstruction");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_STATE_UNDERCONSTRUCTION_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/state/beginner") )
	{
		cms_trace("core/state/beginner");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_STATE_BEGINNER_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/media/book") )
	{
		cms_trace("core/media/book");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_BOOK_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/media/video") )
	{
		cms_trace("core/media/video");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_VIDEO_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/media/cd") )
	{
		cms_trace("core/media/cd");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_CD_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/media/dvd") )
	{
		cms_trace("core/media/dvd");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_DVD_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/media/game") )
	{
		cms_trace("core/media/game");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_GAME_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/media/radio") )
	{
		cms_trace("core/media/radio");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_RADIO_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/media/tv") )
	{
		cms_trace("core/media/tv");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_MEDIA_TV_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/notice") )
	{
		cms_trace("core/info/notice");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_NOTICE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/info/charged") )
	{
		cms_trace("core/info/charged");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_CHARGED_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/freeofcharge") )
	{
		cms_trace("core/info/freeofcharge");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_FREEOFCHARGE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/new") )
	{
		cms_trace("core/info/new");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_NEW_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/position") )
	{
		cms_trace("core/info/position");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_POSITION_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/sharpdial") )
	{
		cms_trace("core/info/sharpdial");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_SHARPDIAL_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/tollfree") )
	{
		cms_trace("core/info/tollfree");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_TOLLFREE_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	else if( NULL != cms_strstr(pict_name,"core/info/reserved") )
	{
		cms_trace("core/info/reserved");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_RESERVED_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}	
	else if( NULL != cms_strstr(pict_name,"core/info/speechinfo") )
	{
		cms_trace("core/info/speechinfo");
		*pict_type = CMS_HTTP_CONTENT_GIF;
		image_buf = GetImage(IMG_WAP_PICTOGRAM_CORE_INFO_SPEECHINFO_ICON);
		*pict_content = (unsigned char*)(image_buf+8);
		*pict_size  =((*(*pict_content +3))<<8)+(*(*pict_content +2))-8;			
		ret = 1;
	}		
	cms_trace("out cms_getpictogram");
	return ret;
}
/******************************************************************************
                        				离线浏览	                     
 ******************************************************************************/ 
typedef struct tagOfflineStruct
{
	P_CMS_BROWSER_U8 currectURL[MAXSTOREOFFLINE];
	P_CMS_BROWSER_U8 fileName[MAXSTOREOFFLINE];
	P_CMS_BROWSER_U8 Title[MAXSTOREOFFLINE];
	CMS_BROWSER_U32 currentPos;	
}OfflineStruct,*P_OfflineStruct;

P_OfflineStruct pOfflineBrowser=NULL;
 /* ----------------------------------------------------------------------------
 * Function Name: InitBrwUIOffline
 *       Purpose: Init offline struct and read record for file to struct OfflineStruct 
 *         Input:  None
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void InitBrwUIOffline()
{
	pOfflineBrowser=cms_malloc(sizeof(OfflineStruct));
	if(pOfflineBrowser!=NULL)
	{
		cms_memset(pOfflineBrowser,0x0,sizeof(OfflineStruct));
		pOfflineBrowser->currentPos=-1;
		//从文件中读记录到pOfflineBrowser中
		Cms_Browser_ReadOfflineRecord();
	}
	else
	{
		cms_trace("InitBrwUIOffline failed");
	}	
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_GetOfflineTitleById
 *       Purpose: get offline title by ID 
 *         Input:  inputid(the snapshot id)
 *        Output: None.
 *       Returns: the title of the snapshot
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
P_CMS_BROWSER_U8 Cms_Browser_GetOfflineTitleById(CMS_BROWSER_U32 inputid)
{
	P_CMS_BROWSER_U8 pTitle = NULL; 

    if (NULL != pOfflineBrowser ) 
    {	
		if(inputid < MAXSTOREOFFLINE)
		{
			if(NULL != pOfflineBrowser->Title[inputid])
			{
				pTitle = pOfflineBrowser->Title[inputid];
			}			
			return pTitle;
		}
		else
		{
			return NULL;
		}
    }
    else
    {
        return NULL;
    }
	return NULL;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Delete_Offline
 *       Purpose: delete a selected offline record and snapshot file
 *         Input:  id(the snapshot id)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
CMS_BROWSER_VOID Cms_Browser_Delete_Offline(CMS_BROWSER_U32 id)
{
	CMS_BROWSER_U32 i = 0;

	adp_mmi_tracer("Cms_Browser_Delete_Offline id=%d",id);
	if(id >= MAXSTOREOFFLINE)
	{
		return;
	}

	/*Delete File*/
	if(pOfflineBrowser->currectURL[id]!=NULL)
	{
		cms_free(pOfflineBrowser->currectURL[id]);
		pOfflineBrowser->currectURL[id] = NULL;
	}

	if(pOfflineBrowser->fileName[id]!=NULL)
	{
		adp_mmi_tracer("cfileName=%s",pOfflineBrowser->fileName[id]);
		FS_Delete((const WCHAR *)pOfflineBrowser->fileName[id]);	
		cms_free(pOfflineBrowser->fileName[id]);
		pOfflineBrowser->fileName[id] = NULL;
	}

	if(pOfflineBrowser->Title[id]!=NULL )
	{
		cms_free(pOfflineBrowser->Title[id]);
		pOfflineBrowser->Title[id] = NULL;
	}
	
	for(i=id; i<MAXSTOREOFFLINE-1; i++)
	{
		pOfflineBrowser->currectURL[i] =pOfflineBrowser->currectURL[i+1];			
		pOfflineBrowser->fileName[i]  = pOfflineBrowser->fileName[i+1] ;
		pOfflineBrowser->Title[i]  = pOfflineBrowser->Title[i+1] ;
	}
	
	pOfflineBrowser->currectURL[i]=NULL;	
	pOfflineBrowser->fileName[i] = NULL;
	pOfflineBrowser->Title[i] =NULL;
	pOfflineBrowser->currentPos--;

	
	return;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_DeleteAll_Offline
 *       Purpose: delete all offline record and file
 *         Input:  None.
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
CMS_BROWSER_VOID Cms_Browser_DeleteAll_Offline(CMS_BROWSER_VOID)
{
	CMS_BROWSER_U32 i = 0; /* 循环变量 */
	if (NULL == pOfflineBrowser)
	{
		return ;
	}				
		
	for(i=0; i <MAXSTOREOFFLINE; i++)
	{
		if(pOfflineBrowser->currectURL[i] != NULL)
		{
			cms_free(pOfflineBrowser->currectURL[i]);
			pOfflineBrowser->currectURL[i] = NULL;
		}
             if (NULL != pOfflineBrowser->fileName[i]) 
             {
             		adp_mmi_tracer("cfileName=%s",pOfflineBrowser->fileName[i]);
			FS_Delete((const WCHAR *)pOfflineBrowser->fileName[i]);	
			
                	cms_free(pOfflineBrowser->fileName[i]);
               	pOfflineBrowser->fileName[i] = NULL;
             }
		 if(pOfflineBrowser->Title[i]!=NULL )
		{
			cms_free(pOfflineBrowser->Title[i]);
			pOfflineBrowser->Title[i] = NULL;
		}
	}
	pOfflineBrowser->currentPos = -1;
	
	return;
}
 /* ----------------------------------------------------------------------------
 * Function Name: cms_Brw_Offline_Browser
 *       Purpose: view the snapshot
 *         Input:  id(the snapshot id).
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_Brw_Offline_Browser(CMS_BROWSER_U32 id)
{
	if(pOfflineBrowser==NULL)
		return ;
	if(id >= MAXSTOREOFFLINE)
	{
		return;
	}
	if(pOfflineBrowser->currectURL[id]!=NULL&&	pOfflineBrowser->fileName[id]!= NULL)
	{
		unsigned char* Urlstr=pOfflineBrowser->currectURL[id];
		unsigned char*  filename=pOfflineBrowser->fileName[id];
		unsigned char* Titlestr=pOfflineBrowser->Title[id];
		unsigned char* ContentBuff=NULL;
		unsigned int BuffLen=0;
		adp_mmi_tracer("Id=%d",id);
		adp_mmi_tracer("filename=%s",filename);
		ContentBuff=(unsigned char*)Brw_Offline_GetFileContent(filename, &BuffLen);
		mms_Tracer((char*)"==cms_Brw_Offline_Browser in");
		if(ContentBuff!=NULL)
		{
			adp_mmi_tracer("BuffLen=%d",BuffLen);
			Cms_LocalPageLoad(Titlestr,(unsigned char*)Urlstr,(unsigned char*)ContentBuff,BuffLen);
		}
		else
		{
			mms_Tracer((char*)"==ContentBuff==NULL");
			//mmi_wap_offline_messagebox();
		}		
	}	
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Wap_GetOfflineNum
 *       Purpose: Get current Offline record num
 *         Input:  id(the snapshot id).
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
CMS_BROWSER_U32 Cms_Wap_GetOfflineNum(void)
{
	return pOfflineBrowser->currentPos+1;
}
 /* ----------------------------------------------------------------------------
 * Function Name: WAPSDK_SavePage
 *       Purpose: Save current snapshot file 
 *         Input:  pPageData(the page data),size(the size of page),curTitle(the page title),currenturl(the url of the page)
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
 void WAPSDK_SavePage(char *pPageData, int size, unsigned char*curTitle,unsigned char* currenturl )
 {
	char		file_name[MMS_FILE_NAME_LEN];
	 mms_Tracer((char*)"==WAPSDK_SavePage in");
	 adp_mmi_tracer("size=%d",size);
	 adp_mmi_tracer("curTitle=%s",curTitle);
	 adp_mmi_tracer("currenturl=%s",currenturl);
	 
	if(pOfflineBrowser==NULL)
	{
		mms_Tracer((char*)"==WAPSDK_SavePage 1111");
		return ;
	}	
	
	if(Cms_Wap_GetOfflineNum()>=MAXSTOREOFFLINE)
	{
		mms_Tracer((char*)"==WAPSDK_SavePage 2222");
		mmi_wap_offline_messagebox();
		return ;
	}		
	
	mms_get_randstring(file_name);
	adp_mmi_tracer("tempFileName=%s",file_name);
	if (size > 0&&pPageData!=NULL&&file_name!=NULL)
	{		
		unsigned int nwrite;
		int mtkOffline = NULL,urlCurrent=0;
	 	char tempFileName[256];
		int urllen=0,fileNameLen=0,TitleLen=0;
		int writeLen=0;

		cms_memset(tempFileName,0x0,sizeof(tempFileName));	
		sprintf(tempFileName,"%s%s.brw",CMS_WAP_APP_PATH,file_name);//"c:\\Offline\\%s.brw",filename);		
		pOfflineBrowser->currentPos++;
		
		if((int)pOfflineBrowser->currentPos < 0)
		{
			pOfflineBrowser->currentPos = 0;
			urlCurrent=0;
		}
		else
		{
			urlCurrent=pOfflineBrowser->currentPos;
		}	
		
		if (tempFileName !=NULL&&currenturl!= NULL)
		{       
			mms_Tracer((char*)"==WAPSDK_SavePage aaaa");			
			mtkOffline = Cms_Adp_fopen((S8*)tempFileName,FS_CREATE_ALWAYS);
			if (mtkOffline < 0)
			{	
				mms_Tracer((char*)"==create file failed");
				return;
			}
			if(size<=0||size>CMS_SNAPSHOT_SIZE)
			{
				FS_Close(mtkOffline);
				return ;
			}	
			if(Cms_Adp_JudgeCSpace((int)size))	
			{
				FS_Close(mtkOffline);
				DisplayPopup((U8*)GetString(STR_MMS_NO_PERSISTENT_STORAGE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return ;		
			}			
			writeLen=FS_Write(mtkOffline, pPageData, (unsigned int)size, &nwrite);
			FS_Close(mtkOffline);

			mms_Tracer((char*)"==WAPSDK_SavePage bbbb");
			
			if(NULL != pOfflineBrowser->currectURL[urlCurrent])
			{				
				cms_free(pOfflineBrowser->currectURL[urlCurrent]);
				pOfflineBrowser->currectURL[urlCurrent] = NULL;
			}				
		        if (NULL != pOfflineBrowser->fileName[urlCurrent]) 
		        {
		            cms_free(pOfflineBrowser->fileName[urlCurrent]);
		            pOfflineBrowser->fileName[urlCurrent] = NULL;
		        }
			if (NULL != pOfflineBrowser->Title[urlCurrent]) 
		        {
		            cms_free(pOfflineBrowser->Title[urlCurrent]);
		            pOfflineBrowser->Title[urlCurrent] = NULL;
		        }
			urllen = Cms_Browser_StrLen(currenturl);				
			pOfflineBrowser->currectURL[urlCurrent]  = (P_CMS_BROWSER_U8)cms_malloc((CMS_BROWSER_U32)(urllen + 1));          
			if(pOfflineBrowser->currectURL[urlCurrent] != NULL)
			{
				mms_Tracer((char*)"==WAPSDK_SavePage cccc");
				Cms_Browser_StrCpy(pOfflineBrowser->currectURL[urlCurrent], currenturl);
				
				fileNameLen= Cms_Browser_StrLen((P_CMS_BROWSER_U8)tempFileName);
				pOfflineBrowser->fileName[urlCurrent] = cms_malloc((CMS_BROWSER_U32)(fileNameLen + 1));
				Cms_Browser_StrCpy(pOfflineBrowser->fileName[urlCurrent], (P_CMS_BROWSER_U8)tempFileName);
			

				if(curTitle==NULL)//changed by xiaoyongqu 060809 修改保存无标题网页为快照问题
				{
					//pOfflineBrowser->Title[urlCurrent] = cms_malloc(9);
					//Cms_Browser_StrCpy(pOfflineBrowser->Title[urlCurrent], (P_CMS_BROWSER_U8)"*NoTitle*");
					pOfflineBrowser->Title[urlCurrent]=(P_CMS_BROWSER_U8)Cms_mms_uni16_8((char*)GetString(STR_WAP_NO_TITLE));
				
				}else
				{
					TitleLen=Cms_Browser_StrLen((P_CMS_BROWSER_U8)curTitle);
					pOfflineBrowser->Title[urlCurrent] = cms_malloc((CMS_BROWSER_U32)(TitleLen + 1));
					Cms_Browser_StrCpy(pOfflineBrowser->Title[urlCurrent], (P_CMS_BROWSER_U8)curTitle);
				}
			}		
			mmi_wap_offline_msgbox();//xiaoyongq 20060613		
			mms_Tracer((char*)"==WAPSDK_SavePage dddd");
		}
	} 	
	else
	{
		//20061025 xiaoyong.qu for bug 48628 add begin
		DisplayPopup((U8*)GetString(STR_WAP_BIG_FILE), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
		mms_Tracer((char*)"==WAPSDK_SavePage eeee");
	}	
	return ;
 }
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_ReadOfflineRecord
 *       Purpose: Read Offline Record
 *         Input:  None.
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
 void Cms_Browser_ReadOfflineRecord()
{	
	int mtkOffline = NULL;
	unsigned char *tempcontent=NULL;
	unsigned int nread;
	P_CMS_BROWSER_U8 title = NULL, url = NULL;
	CMS_BROWSER_U32 i = 0,j=0,Filesize=0;	
	CMS_BROWSER_U64 leng = 0;
	CMS_BROWSER_S32 flag = 0, ch = 0;
	CMS_BROWSER_BOOL isItem = CMS_BROWSER_TRUE;
	CMS_BROWSER_U8 item[10];
	CMS_BROWSER_U8  content[512];
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapOfflinefilename(wap_filename);	
	mtkOffline = Cms_Adp_fopen((S8*)wap_filename, FS_READ_ONLY);
	//mtkOffline = FS_Open(L"C:\\wap\\CmsBrwOffline.cnf",FS_READ_ONLY);
	if (mtkOffline < 0)
	{
		return;
	}
	FS_GetFileSize(mtkOffline, &Filesize);
	if((int)Filesize<=0)
	{
		FS_Close(mtkOffline);
		return ;
	}
	tempcontent = (unsigned char *)cms_malloc(Filesize);
	if (tempcontent == NULL)
	{
		FS_Close(mtkOffline);
		return;
	}
	cms_memset(tempcontent, 0, Filesize);
	FS_Read(mtkOffline, tempcontent, Filesize, &nread);
	FS_Close(mtkOffline);
	
	while(leng<=(CMS_BROWSER_U32)Filesize && i<MAXSTOREOFFLINE)
	{
		flag = tempcontent[leng];
		leng++;
					
		if(flag == '\n')
		{
			if(isItem == CMS_BROWSER_TRUE)
			{				
				for(j=0; j<10 && ch!='\n' && leng<=(CMS_BROWSER_U32)Filesize; j++)
				{
					ch = tempcontent[leng];
					leng++;
					if(leng<=(CMS_BROWSER_U32)Filesize)
					{
						item[j] = (CMS_BROWSER_U8)ch;
					}
				}
				
				if(leng>(CMS_BROWSER_U32)Filesize || j>10)
				{
					break;
				}
				
				if(j>0)
				{
					item[j-1] = 0;
				}
				adp_mmi_tracer("item =%s",item);
				if(Cms_Browser_StrCmp((P_CMS_BROWSER_U8)item, (P_CMS_BROWSER_U8)"cmstitle")==0)
				{			
					/*===Title ===*/
					ch = 0;
					
					for(j=0; j<512 && ch != '\n' && leng<=(CMS_BROWSER_U32)Filesize; j++)
					{
						ch = tempcontent[leng];
						leng++;
						if(leng<=(CMS_BROWSER_U32)Filesize)
						{
							content[j] = (CMS_BROWSER_U8)ch;
						}
					}
					
					if(leng>(CMS_BROWSER_U32)Filesize || j>512)
					{
						break;
					}
					
					if(j>0)
					{
						content[j-1] = 0;
					}
					
					title = (P_CMS_BROWSER_U8)cms_malloc(j);
					if(title != NULL)
					{
						if(pOfflineBrowser->Title[i] != NULL)
						{
							cms_free(pOfflineBrowser->Title[i]);
							pOfflineBrowser->Title[i]= NULL;
						}
						pOfflineBrowser->Title[i] = title;
						Cms_Browser_StrCpy(pOfflineBrowser->Title[i], (P_CMS_BROWSER_U8)content);
					}
					else
					{							
						break;
					}
				}
				else if(Cms_Browser_StrCmp((P_CMS_BROWSER_U8)item, (P_CMS_BROWSER_U8)"cmsurl")==0)
				{
					/*=== URL ===*/
					ch = 0;
					
					for(j=0; j<512 && ch != '\n' &&
						leng<=(CMS_BROWSER_U32)Filesize; j++)
					{
						ch = tempcontent[leng];
						leng++;
						if(leng<=(CMS_BROWSER_U32)Filesize)
						{
							content[j] = (CMS_BROWSER_U8)ch;
						}
					}
					
					if(j>512)
					{
						cms_free(pOfflineBrowser->Title[i]);
						pOfflineBrowser->Title[i] = NULL;
						break;
					}
					
					if(j>0)
					{
						content[j-1] = 0;
					}
					
					url = (P_CMS_BROWSER_U8)cms_malloc(j);
					if(url != NULL)
					{	
						if(pOfflineBrowser->currectURL[i] != NULL)
						{
							cms_free(pOfflineBrowser->currectURL[i]);
							pOfflineBrowser->currectURL[i] = NULL;
						}
						pOfflineBrowser->currectURL[i] = url;
						Cms_Browser_StrCpy(pOfflineBrowser->currectURL[i], (P_CMS_BROWSER_U8)content);
					}
					else
					{
						cms_free(pOfflineBrowser->Title[i]);
						pOfflineBrowser->Title[i] = NULL;
						break;
					}
				}
				else if(Cms_Browser_StrCmp((P_CMS_BROWSER_U8)item, (P_CMS_BROWSER_U8)"cmsfile")==0)
				{
					/*=== FileName ===*/
					ch = 0;
					
					for(j=0; j<512 && ch != '\n' &&
						leng<=(CMS_BROWSER_U32)Filesize; j++)
					{
						ch = tempcontent[leng];
						leng++;
						if(leng<=(CMS_BROWSER_U32)Filesize)
						{
							content[j] = (CMS_BROWSER_U8)ch;
						}
					}
					
					if(j>512)
					{
						cms_free(pOfflineBrowser->Title[i]);
						pOfflineBrowser->Title[i] = NULL;
						break;
					}
					
					if(j>0)
					{
						content[j-1] = 0;
					}
					
					url = (P_CMS_BROWSER_U8)cms_malloc(j);
					if(url != NULL)
					{	
						if(pOfflineBrowser->fileName[i] != NULL)
						{
							cms_free(pOfflineBrowser->fileName[i]);
							pOfflineBrowser->fileName[i] = NULL;
						}
						pOfflineBrowser->fileName[i] = url;
						Cms_Browser_StrCpy(pOfflineBrowser->fileName[i], (P_CMS_BROWSER_U8)content);
					}
					else
					{
						cms_free(pOfflineBrowser->Title[i]);
						pOfflineBrowser->Title[i] = NULL;
						break;
					}
				}
			
				else
				{
					if(pOfflineBrowser->currectURL[i] ==NULL &&pOfflineBrowser->Title[i]!=NULL)
					{
						cms_free(pOfflineBrowser->Title[i]);
						pOfflineBrowser->Title[i] = NULL;
					}
					break;
				}
				
				leng--;
				ch = 0;
			}
			else
			{
				isItem = CMS_BROWSER_FALSE;
			}
			
			if(pOfflineBrowser->currectURL[i] != NULL&&pOfflineBrowser->fileName[i]!=NULL)
			{		
				i++;
			}
		}
		else if(leng>(CMS_BROWSER_U32)Filesize)
		{
			break;
		}		
	}
	if(tempcontent!=NULL)
	{
		cms_free(tempcontent);
		tempcontent=NULL;
	}
	pOfflineBrowser->currentPos=i-1;	
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_WriteOfflineRecord
 *       Purpose: Write Offline Browser record to File 
 *         Input:  None.
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
void Cms_Browser_WriteOfflineRecord()
{	
	unsigned int nwrite;	
	int mtkOffline = NULL;
	P_CMS_BROWSER_U8 title = NULL, url = NULL,filename=NULL;
	CMS_BROWSER_U32 i = 0;	
	cms_memset(wap_filename,0,MMS_FILE_NAME_LEN);
	Cms_GetWapOfflinefilename(wap_filename);	
	Cms_Adp_fdelete((const unsigned short *) wap_filename);
	//FS_Delete(L"C:\\wap\\CmsBrwOffline.cnf");	
	mtkOffline = Cms_Adp_fopen((S8*)wap_filename, FS_CREATE);		
	//mtkOffline = FS_Open(L"C:\\wap\\CmsBrwOffline.cnf",FS_CREATE);
	if (mtkOffline < 0)
	{
		return;
	}
	else
	{
		if(pOfflineBrowser==NULL)
			return ;		
		while(i<MAXSTOREOFFLINE)
		{
			if( pOfflineBrowser->currectURL[i]!=NULL &&pOfflineBrowser->fileName[i]!=NULL&&pOfflineBrowser->Title[i]!=NULL)
			{	
				url =  pOfflineBrowser->currectURL[i];
				filename =pOfflineBrowser->fileName[i];
				title=pOfflineBrowser->Title[i];
				FS_Write(mtkOffline, "\n",1, &nwrite);
				FS_Write(mtkOffline, (P_CMS_BROWSER_U8)"cmstitle", 8, &nwrite);
				FS_Write(mtkOffline, "\n",1, &nwrite);
				FS_Write(mtkOffline, (P_CMS_BROWSER_U8)title,  Cms_Browser_StrLen(title), &nwrite);
				FS_Write(mtkOffline, "\n",1, &nwrite);
				FS_Write(mtkOffline, (P_CMS_BROWSER_U8)"cmsurl", 6, &nwrite);
				FS_Write(mtkOffline, "\n",1, &nwrite);				
				FS_Write(mtkOffline, (P_CMS_BROWSER_U8)url, Cms_Browser_StrLen(url),&nwrite);	
				FS_Write(mtkOffline, "\n",1, &nwrite);
				FS_Write(mtkOffline, (P_CMS_BROWSER_U8)"cmsfile", 7, &nwrite);
				FS_Write(mtkOffline, "\n",1, &nwrite);
				FS_Write(mtkOffline, (P_CMS_BROWSER_U8)filename,  Cms_Browser_StrLen(filename), &nwrite);				
			}
			i++;
		}	
		
		FS_Close(mtkOffline);
	}
}

 /******************************************************************************
                           				file operate		                       
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_fopen
 *       Purpose: open the flash file  
 *         Input:  FileName(file name),Flag(file opertae type)
 *        Output: None.
 *       Returns: >=0,open flash file success
 * 			  <0,open flash file fail
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
int Cms_Adp_fopen(S8* FileName, unsigned int Flag)
{
#ifdef  SUPPORT_MTK_PLATFORM
	MMS_FILE_HANDLE fd = 0;
	char*	filename_uni = NULL;
	
	mms_Tracer((char*)"______________Cms_fopen_______________");
	filename_uni = Cms_mms_uni8_16(FileName);
	fd = FS_Open((unsigned short*)filename_uni, Flag);
	mms_Free(filename_uni);
	filename_uni = NULL;	
	return fd;
#else
	FILE_HANDLE fp = 0;
	
	if(Flag == FS_READ_ONLY)
		fp = mmsf_Open(FileName,"rb");
	else if(Flag == FS_CREATE)
		fp = mmsf_Open(FileName,"wb");
	return fp;
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Adp_fclose
 *       Purpose: close the flash file  
 *         Input:  FileHandle(file handle)
 *        Output: None.
 *       Returns: FS_NO_ERROR,success
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
int Cms_Adp_fclose(MMS_FILE_HANDLE FileHandle)
{
	mms_Tracer((char*)"______________Cms_fclose_______________");
#ifdef SUPPORT_MTK_PLATFORM
	return FS_Close(FileHandle);	
#else
	mmsf_Close(FileHandle);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_fread
 *       Purpose: read the data from flash file  
 *         Input:  FileHandle(References the open file from which to read)
 *			 DataPtr(Specifies the address for the data to be read)
 *			 Length(Specifies the number of bytes to read)
 *			 Read(Pointer to an unsigned integer to receive the number of bytes actually read)
 *        Output: None.
 *       Returns: FS_NO_ERROR,success
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
int Cms_Adp_fread(MMS_FILE_HANDLE FileHandle, void * DataPtr, unsigned int Length, unsigned int * Read)
{
	mms_Tracer((char*)"______________Cms_fread_______________");
#ifdef SUPPORT_MTK_PLATFORM
	 return FS_Read(FileHandle,DataPtr,Length,Read);
#else
	return mmsf_Read(DataPtr,Length,1,FileHandle);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_fwrite
 *       Purpose: write the data from flash file  
 *         Input:  FileHandle(References the open file to write to)
 *			 DataPtr(Specifies the address of the data to be written)
 *			 Length(Specifies the number of bytes to write)
 *			 Written(Pointer to an unsigned integer to receive the number of bytes actually been written)
 *        Output: None.
 *       Returns: FS_NO_ERROR,success
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
int Cms_Adp_fwrite(MMS_FILE_HANDLE FileHandle, void * DataPtr, unsigned int Length, unsigned int * Written)
{
	mms_Tracer((char*)"______________Cms_fwrite_______________");
#ifdef SUPPORT_MTK_PLATFORM
	return FS_Write(FileHandle, DataPtr, Length, Written);
#else
	return mmsf_Write(DataPtr,Length,1,FileHandle);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_fdelete
 *       Purpose: delete the flash file  
 *         Input:  FileName(Must point to the name of the file to be deleted and may not contain wildcards)
 *        Output: None.
 *       Returns: FS_NO_ERROR,success
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_Adp_fdelete(const unsigned short * FileName)
{
#ifdef SUPPORT_MTK_PLATFORM
	char*	filename_uni = NULL;
	int		uni_len = 0;
	int     ret = 0;
	
	mms_Tracer((char*)"______________Cms_fdelete_______________");
	uni_len = Cms_Browser_Uni8_strlen((P_CMS_BROWSER_U8)FileName);
	filename_uni = (char *)mms_Malloc(uni_len*2+2);
	Cms_Browser_Uni8_16_big((P_CMS_BROWSER_U8)FileName,(P_CMS_BROWSER_U8)filename_uni);

	ret = FS_Delete((const unsigned short *)filename_uni);
	if(ret < 0)
	{
		mms_Tracer((char*)"Cms_fdelete:delete failed");
	}

	mms_Free(filename_uni);
	filename_uni = NULL;

	return ret;
#else
	return mmsf_Remove(FileName);
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetFileSize
 *       Purpose: get the current size of an open file.  
 *         Input:  FileHandle(References the open file for which to retrieve the file size)
 *			 Size(Must point to the int to receive the file's size)
 *        Output: None.
 *       Returns: FS_NO_ERROR,success
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
int Cms_Adp_GetFileSize (MMS_FILE_HANDLE FileHandle, unsigned int *Size)
{
#ifdef SUPPORT_MTK_PLATFORM
	return FS_GetFileSize(FileHandle,Size);
#else
	int filelength = 0;
	mmsf_Seek(FileHandle, 0, SEEK_END);
	
	filelength = mmsf_Tell(FileHandle);
	
	mmsf_Seek(FileHandle,0,SEEK_SET);
	*Size = filelength;
	return 1;
#endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Adp_FileExists
 *       Purpose:
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
pBOOL Cms_Adp_FileExists(S8* filename)
{
	MMS_FILE_HANDLE fh = 0;
	
	fh = Cms_Adp_fopen(filename, FS_READ_ONLY);	
	if (fh >= 0)
	{
		mms_Tracer((char*)"Cms_Adp_FileExists:file exist");
		Cms_Adp_fclose(fh);
		return TRUE;
	}
	else
	{
		mms_Tracer((char*)"Cms_Adp_FileExists:file is not exist");
		Cms_Adp_fclose(fh);
	}
	return FALSE;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Return_Mms_MaxSize
 *       Purpose:
 *         Input:  size(the file size)
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
long Cms_Return_Mms_MaxSize(void)
{
	/*system disk*/
	unsigned short path[]={0,0x3a,0x5c,0};
	FS_DiskInfo 	diskinfo;
	UINT 		freebytes;
	S32 			fs_RetDrv = FS_GetDrive(FS_DRIVE_V_NORMAL/*FS_DRIVE_I_SYSTEM*/, 1, FS_NO_ALT_DRIVE);

	if(fs_RetDrv>0){
		path[0] = (char)fs_RetDrv;
	}
	else{
		return -1;
	}
	FS_GetDiskInfo(path, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
	freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
	adp_mmi_tracer((char *)"Mms_MaxSize_space= %d", (char *)freebytes);
//	if (freebytes < MAX_SIZE_MMS_DEFINE)
	    return freebytes;
//	else
//	    return MAX_SIZE_MMS_DEFINE;
}
 
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Adp_JudgeCSpace
 *       Purpose:
 *         Input:  size(the file size)
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
BOOL Cms_Adp_JudgeCSpace(int size)
{
	/*system disk*/
	unsigned short path[]={0,0x3a,0x5c,0};
	FS_DiskInfo 	diskinfo;
	UINT 		freebytes;
	S32 			fs_RetDrv = FS_GetDrive(FS_DRIVE_V_NORMAL/*FS_DRIVE_I_SYSTEM*/, 1, FS_NO_ALT_DRIVE);

	if(fs_RetDrv>0){
		path[0] = (char)fs_RetDrv;
	}
	else{
		return -1;
	}
	Cms_hex_trace((kal_uint8 *)path, 6);
	FS_GetDiskInfo(path, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
	freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
	adp_mmi_tracer((char *)"JudgeCSpace= %d", (char *)freebytes);
	if (freebytes < size)
	    return TRUE;
	else
	    return FALSE;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Adp_JudgeCSpace
 *       Purpose:
 *         Input:  size(the file size)
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
BOOL Cms_Adp_JudgeDSpace(int size)
{
	/*user disk*/
	unsigned short path[]={0,0x3a,0x5c,0}; 
	FS_DiskInfo 	diskinfo;
	UINT 		freebytes;
   	S32 			fs_RetDrv = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);

	if(fs_RetDrv>0){
		path[0] = (char)fs_RetDrv;
	}
	else{
		return -1;
	}
	Cms_hex_trace((kal_uint8 *)path, 6);
	FS_GetDiskInfo(path, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
	freebytes = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
	adp_mmi_tracer((char *)"JudgeDSpace= %d", (char *)freebytes);
	if (freebytes < size)
	    return TRUE;
	else
	    return FALSE;
}
/******************************************************************************
 *                           				push operate		                       *
 ******************************************************************************/
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: conversion the bind return value.  
 *         Input:  ret(the bind function return value)
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int sms_socket_retcode(kal_int8 ret)
{
	if(ret >= 0)
	{
		adp_Tracer("###sms:return success !!###");
		return ret; /* success case */
	}
	
	switch(ret)
	{
	case SOC_INVALID_SOCKET:
		adp_Tracer("###sms:return error SOC_INVALID_SOCKET !!###");
		return -1;
		
	case SOC_INVAL:
		adp_Tracer("###sms:return error SOC_INVAL !!###");
		return -2;
		
	case SOC_WOULDBLOCK:
		adp_Tracer("###sms:return error SOC_WOULDBLOCK !!###");
		return -3;
		
	case SOC_MSGSIZE:
		adp_Tracer("###sms:return error SOC_MSGSIZE !!###");
		return -4;
		
	case SOC_LIMIT_RESOURCE:
		adp_Tracer("###sms:return error SOC_LIMIT_RESOURCE !!###");
		return -5;
	default: 
		adp_Tracer("###sms:return error SOCKET_INVALID_PARAM !!###");
		return -6;
	}
	
}
 /* ----------------------------------------------------------------------------
 * Function Name: mms_net_data_init
 *       Purpose: 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
static void mms_net_data_init(void)
{
	U8 tempgateport[10] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	adp_Tracer((char *)"mms_net_data_init");
	memset(&mms_sock_addr,0x00,sizeof(sockaddr_struct));
	mms_sock_addr.addr_len=4;
	while (gconfig.gateway[i*2] != NULL)
	{
		if (gconfig.gateway[i*2] != '.')
		{
			tempgateport[j] = gconfig.gateway[i*2];
			j++;	
		}
		else if (k<=2)
		{
			mms_sock_addr.addr[k] = Cms_Browser_atoi(tempgateport);
			memset(tempgateport, 0 , 10);
			j = 0;
			k++;
		}
		i++;
	}
	
	mms_sock_addr.addr[k] = Cms_Browser_atoi(tempgateport);
	cms_memset(tempgateport, 0x0 , 10);

	adp_mmi_tracer((char *)"sock_addr.addr[0]...................= %d", (char *)mms_sock_addr.addr[0]);
	adp_mmi_tracer((char *)"sock_addr.addr[1]...................= %d", (char *)mms_sock_addr.addr[1]);
	adp_mmi_tracer((char *)"sock_addr.addr[2]...................= %d", (char *)mms_sock_addr.addr[2]);
	adp_mmi_tracer((char *)"sock_addr.addr[3]...................= %d", (char *)mms_sock_addr.addr[3]);

	i = 0;
	while (gconfig.port[i*2] != NULL)
	{
		tempgateport[i] = gconfig.port[i*2];
		i ++;
	}
	mms_sock_addr.port = Cms_Browser_atoi(tempgateport);
	adp_mmi_tracer((char *)"mms_sock_addr.port ...................= %d", mms_sock_addr.port );
}
/* ----------------------------------------------------------------------------
 * Function Name: mms_net_data_init_again
 *       Purpose: reset the gateway ip and port addr
 *         Input:  None
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
 void cms_net_mms_data_init_again(unsigned char* ip_addr, unsigned short port)
{
	adp_Tracer((char *)"cms_net_mms_data_init_again");
	memset(&mms_sock_addr,0x00,sizeof(sockaddr_struct));
	mms_sock_addr.addr_len=4;
	mms_sock_addr.addr[0] = ip_addr[0];
	mms_sock_addr.addr[1] = ip_addr[1];
	mms_sock_addr.addr[2] = ip_addr[2];
	mms_sock_addr.addr[3] = ip_addr[3];
	mms_sock_addr.port = port;
	adp_mmi_tracer((char *)"mms_sock_addr.addr[0]...................= %d", (char *)mms_sock_addr.addr[0]);
	adp_mmi_tracer((char *)"mms_sock_addr.addr[1]...................= %d", (char *)mms_sock_addr.addr[1]);
	adp_mmi_tracer((char *)"mms_sock_addr.addr[2]...................= %d", (char *)mms_sock_addr.addr[2]);
	adp_mmi_tracer((char *)"mms_sock_addr.addr[3]...................= %d", (char *)mms_sock_addr.addr[3]);
	adp_mmi_tracer((char *)"mms_sock_addr.port...................= %d", (char *)mms_sock_addr.port);

}
/* ----------------------------------------------------------------------------
 * Function Name: cms_net_wap_data_init_again
 *       Purpose: reset the gateway ip and port addr
 *         Input:  None
 *        Output: None.
 *       Returns: None
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void cms_net_wap_data_init_again(unsigned char* ip_addr, unsigned short port)
{
	memset(&sock_addr,0x00,sizeof(sockaddr_struct));
	sock_addr.addr_len=4;
	sock_addr.addr[0] = ip_addr[0];
	sock_addr.addr[1] = ip_addr[1];
	sock_addr.addr[2] = ip_addr[2];
	sock_addr.addr[3] = ip_addr[3];
	sock_addr.port = port;
	adp_mmi_tracer((char *)"sock_addr.addr[0]...................= %d", (char *)sock_addr.addr[0]);
	adp_mmi_tracer((char *)"sock_addr.addr[1]...................= %d", (char *)sock_addr.addr[1]);
	adp_mmi_tracer((char *)"sock_addr.addr[2]...................= %d", (char *)sock_addr.addr[2]);
	adp_mmi_tracer((char *)"sock_addr.addr[3]...................= %d", (char *)sock_addr.addr[3]);
	adp_mmi_tracer((char *)"sock_addr.port...................= %d", (char *)sock_addr.port);
	
}
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: bind the socket port for push message.  
 *         Input:   socketId(the socket id which socket to bind)
 *			  addr(the address which to bind)
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int sms_socketBind (kal_int8 socketId, sockaddr_struct *addr)
{
	kal_int8 error;
	kal_uint8 onoff = KAL_TRUE;
	
	kal_prompt_trace(MOD_NVRAM,"sms:sms_socketBind: socketId=%d %d.%d.%d.%d:%d\n", socketId,\
		addr->addr[0],addr->addr[1],addr->addr[2],addr->addr[3],addr->port);
	
	soc_setsockopt(socketId, SOC_SILENT_LISTEN, &onoff, sizeof(onoff));
	error = soc_bind(socketId, addr);
	
	return SOCKET_RET_CODE_TO_HDI(error);
}
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void SocketStart(int flag)
{
	kal_uint8 val = KAL_TRUE;
	kal_uint32 acc_id;
	adp_Tracer((char *)"SocketStart");

	if(flag == 0)/*PUSH*/
	{		
		cms_memset(&sock_addr,0x0,sizeof(sockaddr_struct));
		acc_id = gconfig.gprs_mode + GSM_NET_ACCOUNT;
		Socket_Id[flag] = soc_create(PF_INET, SOCK_SMS, 0, MOD_MMI, acc_id);
	}
	else/*彩信浏览器WAP1.2.1*/
	{
		if(flag == 1)//20060816 wantao add for bug
		{
			netacc_id = gconfig.gprs_mode + GSM_NET_ACCOUNT;	
		}
		adp_mmi_tracer((char *)"soc_create ... acc_id = %d",(char *)acc_id);
		if(netacc_id < 0)
		{
			netacc_id = DEFAULTNETACCID;
		}
		if(netacc_id < CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM)
		{
			if(g_DataAccount[netacc_id] .DialNumber[0] == 0)
			{
				Cms_Brw_Cancle();
				DisplayPopup((U8*)GetString(STR_WAP_NETACCOUNT_ERROR), IMG_GLOBAL_WARNING, NULL, CMS_MMS_POPUP_DELAY_TIME, WARNING_TONE);
				return;
			}
		}
	   	Socket_Id[flag] = soc_create(PF_INET, 1, 0, MOD_MMI, netacc_id);
		//SocketId = Socket_Id[flag];//20060328 cocoma xu delete
	   	adp_mmi_tracer((char *)"soc_create ... socket_ID = %d",(char *)Socket_Id[flag]);
	}

	kal_prompt_trace(MOD_NVRAM,"###create %d socket id!###%d", flag,Socket_Id[flag]);
	
	if(Socket_Id[flag] < 0)
	{
		/*error handle*/
		adp_Tracer("###create socket error!###");	
	} 
	else
	{
		/*set socket to  non-blocking mode*/
		if( soc_setsockopt(Socket_Id[flag],SOC_NBIO, &val, sizeof(val))< 0 )
		{
			adp_Tracer("###Set socket to block mode error !!###%");
			return;
		}
		/*set socket to Async  mode*/
		val=SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE | SOC_ACCEPT;
		if(soc_setsockopt(Socket_Id[flag],SOC_ASYNC, &val, sizeof(val)) < 0)
		{
			adp_Tracer("###Set socket to nonblock mode error !!###");
			return;
		}
#ifdef MMI_ON_HARDWARE_P
		SetProtocolEventHandler( cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND );
#endif

		if(flag == 1)   //MMS Socket
		{
			mms_net_data_init();
			mmsEventPostEvent(NETLINK_RETURN,MMS_NETLINK_SUCCESS,NULL);
			mmsEventProcessEvent();
		}
		else if(flag ==2)  //Browser Socket
		{
			wap_net_data_init();
			brwEventPostEvent(BRW_NETLINK_RETURN,BRW_NETLINK_SUCCESS,NULL);
			brwEventProcessEvent();	
		}
		else   //Sms Socket
		{
			sock_addr.addr_len = 0;
			sock_addr.port   = 2948;  /*或者2949   4035 */
			
			if(sms_socketBind(Socket_Id[flag],&sock_addr)<0)
			{
				adp_Tracer("###sms:socket bind error !!###");
				return;	
			}
			adp_Tracer("###sms:socket start recving!!###");
			sms_recv_data();
		}	
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: receive the push data  
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
//for test push chaozhu.zhou 2007.04.03 add begin
#define TestPUSH 0
#if  TestPUSH
kal_uint8 testwappush[RECV_BUFLEN] = {
0x01, 0x06, 0x2C, 0x1F, 0x2A, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E,
0x2F, 0x78, 0x2D, 0x77, 0x61, 0x70, 0x2D, 0x70, 0x72, 0x6F, 0x76, 0x2E, 0x62, 0x72, 0x6F, 0x77,
0x73, 0x65, 0x72, 0x2D, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73, 0x00, 0x81, 0xEA, 0x01,
0x01, 0x6A, 0x00, 0x45, 0xC6, 0x06, 0x01, 0x87, 0x12, 0x45, 0x01, 0x87, 0x13, 0x11, 0x03, 0x31,
0x32, 0x33, 0x2E, 0x34, 0x35, 0x2E, 0x31, 0x32, 0x33, 0x2E, 0x36, 0x37, 0x00, 0x01, 0x87, 0x21,
0x11, 0x03, 0x2B, 0x34, 0x35, 0x38, 0x33, 0x35, 0x37, 0x32, 0x00, 0x01, 0x87, 0x22, 0x70, 0x01,
0x87, 0x23, 0x11, 0x03, 0x77, 0x61, 0x70, 0x75, 0x73, 0x65, 0x72, 0x00, 0x01, 0x87, 0x24, 0x11,
0x03, 0x77, 0x61, 0x70, 0x70, 0x61, 0x73, 0x73, 0x77, 0x00, 0x01, 0x87, 0x28, 0x72, 0x01, 0x87,
0x29, 0x6A, 0x01, 0x01, 0x86, 0x07, 0x11, 0x03, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x77,
0x61, 0x70, 0x2E, 0x64, 0x6B, 0x00, 0x01, 0xC6, 0x08, 0x01, 0x87, 0x15, 0x11, 0x03, 0x41, 0x42,
0x43, 0x20, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x00, 0x01, 0x01, 0xC6, 0x7F, 0x01, 0x87,
0x15, 0x11, 0x03, 0x41, 0x42, 0x43, 0x20, 0x57, 0x61, 0x70, 0x00, 0x01, 0x87, 0x17, 0x11, 0x03,
0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x77, 0x61, 0x70, 0x2E, 0x64, 0x6B, 0x00, 0x01, 0x01,
0x01};//209
kal_uint8 testmmspush[RECV_BUFLEN] = {
0x01, 0x06, 0x2C, 0x1F, 0x2A, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 
0x2F, 0x78, 0x2D, 0x77, 0x61, 0x70, 0x2D, 0x70, 0x72, 0x6F, 0x76, 0x2E, 0x62, 0x72, 0x6F, 0x77, 
0x73, 0x65, 0x72, 0x2D, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73, 0x00, 0x81, 0xEA, 0x01, 
0x01, 0x6A, 0x00, 0x45, 0xC6, 0x06, 0x01, 0x87, 0x12, 0x49, 0x01, 0x87, 0x13, 0x11, 0x03, 0x31, 
0x32, 0x33, 0x2E, 0x31, 0x32, 0x33, 0x2E, 0x31, 0x32, 0x33, 0x2E, 0x31, 0x32, 0x33, 0x00, 0x01, 
0x87, 0x14, 0x61, 0x01, 0x87, 0x1C, 0x11, 0x03, 0x6D, 0x6D, 0x73, 0x63, 0x2E, 0x6E, 0x6F, 0x6B, 
0x69, 0x61, 0x6E, 0x6F, 0x6B, 0x69, 0x61, 0x6E, 0x6F, 0x6B, 0x2E, 0x63, 0x6F, 0x6D, 0x00, 0x01, 
0x87, 0x22, 0x70, 0x01, 0x01, 0x86, 0x7C, 0x11, 0x03, 0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 
0x6E, 0x6F, 0x6B, 0x69, 0x61, 0x6E, 0x2E, 0x6F, 0x6B, 0x69, 0x61, 0x6E, 0x6F, 0x6B, 0x69, 0x61, 
0x6E, 0x6F, 0x6B, 0x69, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x3A, 0x38, 0x30, 0x30, 0x32, 0x2F, 0x00, 
0x01, 0xC6, 0x08, 0x01, 0x87, 0x15, 0x11, 0x03, 0x4D, 0x4D, 0x53, 0x20, 0x4E, 0x4F, 0x4B, 0x49, 
0x41, 0x20, 0x47, 0x50, 0x52, 0x53, 0x00, 0x01, 0x01, 0x01
};//186
#endif
//for test push chaozhu.zhou 2007.04.03 add end

void sms_recv_data()
{
	int         			sms_head_len = 0;
	CMS_MMS_S32 	flag_userdata_head = 0;
	int         			sms_head_len_off = 0;
	
	adp_Tracer("###sms:socket recv data !!###");

	memset(sms_push_buf,0,RECV_BUFLEN);
#if  TestPUSH
	//memcpy(sms_push_buf,testwappush,RECV_BUFLEN);
	//pdu_len =209;
	memcpy(sms_push_buf,testmmspush,RECV_BUFLEN);
	pdu_len =186;

#else
	pdu_len = soc_recv(Socket_Id[0],sms_push_buf, RECV_BUFLEN,0);
#endif
	adp_mmi_tracer("socket recv buf return: pdu_len = %d", pdu_len);
	if( pdu_len >=0) 
	{ 
		PUSH_SMS_AP sms_ap_id = -1;

		adp_Tracer("###sms:socket recv data success!!###");
		sms_ap_id = CmsDispatchPush(sms_push_buf,pdu_len);
		switch(sms_ap_id)
		{
		case NOT_PUSH_AP:
			break;

		case PUSH_MMS_AP:
			{
				mms_Tracer((char*)"it is a MMS push");
                		sms_head_len = CmsGetUnitVarValue(&(sms_push_buf[2]), (P_CMS_BROWSER_U8)(&sms_head_len_off));
				adp_mmi_tracer("sms_head_len = %d",sms_head_len);

				if(sms_head_len==0)
				{
					flag_userdata_head = 0;					
				}
				else
				{
					flag_userdata_head = 1;
				}
				MMS_sms_onpushmessage(sms_push_buf,pdu_len,flag_userdata_head,NULL);					
			}
			break;		
		default:
			{
				P_CMS_BROWSER_PUSH Cms_Push_Message = NULL;
				adp_mmi_tracer((char *)"it is a Browser push","");
				/* 添加判断push开关的设置*/
				if(0 == Cms_Browser_GetPushMessageSetting())
				{
					return;
				}
				adp_mmi_tracer("sms_head_len real = %d",(char *)pdu_len);
				Cms_Push_Message = (P_CMS_BROWSER_PUSH)CmsBRAccessNewPUSH(sms_push_buf, pdu_len);
				if(Cms_Push_Message != NULL)
				{
				#ifdef SUPPORT_SMSMMS_COMBINE
					/*加入PUSH 信息到彩信链表*/
					if(Cms_Push_Message->PUSHType!=CMS_BROWSER_OTA_SETTING_PUSH)
					{
						mmi_wapmms_judge_recv_wappush_del_last();
						mmi_wapmms_add_push_to_list(Cms_Push_Message);
					}
				#endif
					CmsBRFreePUSH(Cms_Push_Message);
					if(UnreadPushMessageNum < 20)
					{
						UnreadPushMessageNum ++;
					}
					ShowStatusIcon(STATUS_ICON_WAP);
					UpdateStatusIcons();
					adp_mmi_tracer("Cms_Browser_AccessNewPUSH is finish ok....","");
					mmi_mms_new_msg_ind();
					DisplayPopup((U8*)GetString(STR_WAP_WAPPUSHARRIVED_ID), IMG_GLOBAL_ACTIVATED, NULL, CMS_WAP_POPUP_DELAY_TIME, SUCCESS_TONE);
				}				
			}
			break;
		} 
		
	}	
}
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void  Cms_Reset_Soc(void)
{
	SetProtocolEventHandler( cms_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND );
}
 /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose: 
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int  Cms_close_soc(int flag)
{
	extern SOCKET	Socket;
	kal_int8 ret = 0;
	mms_Tracer((char*)"enter Cms_close_soc close socket");
	ret = soc_close(Socket_Id[flag]);
	adp_mmi_tracer((char *)"ret = soc_close(Socket_Id[flag]) = %d", (char *)ret);
	soc_close_nwk_account(MOD_MMI);
	Socket_Id[flag] = -10;
	Socket=INVALID_SOCKET;
	if(ret >= 0)
	{
		return ret;
	}
	else
	{
		return -10;
	}
}
 int  Cms_close_soc_bySocket()
{
	extern SOCKET	Socket;
	kal_int8 ret = 0;
	mms_Tracer((char*)"enter Cms_close_soc_bySocket");
	adp_mmi_tracer("socket %d",Socket);
	ret = soc_close(Socket);
	adp_mmi_tracer((char *)"ret = soc_close(Socket_Id[flag]) = %d", (char *)ret);
	soc_close_nwk_account(MOD_MMI);
	Socket=INVALID_SOCKET;
	if(ret >= 0)
	{
		return ret;
	}
	else
	{
		return -10;
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_close_mms_soc
 *       Purpose: close socket when mms reconnect
 *         Input:  None
 *        Output: None.
 *       Returns: 1,success
 *			  0,fail	
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int  Cms_close_mms_soc(int flag)
{
	kal_int8 ret = 0;
	mms_Tracer((char*)"enter Cms_close_mms_soc close socket");
	ret = soc_close(Socket_Id[flag]);
	adp_mmi_tracer((char *)"ret = soc_close(Socket_Id[flag]) = %d", (char *)ret);
	return ret;
}
/******************************************************************************
							screen setting		                       
 ******************************************************************************/  
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetORIGIN_X
 *       Purpose: get origin X postion 
 *         Input:  None
 *        Output: None.
 *       Returns: X postion value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_S32 Cms_GetORIGIN_X(CMS_BROWSER_VOID)
{
    return 0;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetORIGIN_Y
 *       Purpose: get origin Y postion 
 *         Input:  None
 *        Output: None.
 *       Returns: Y postion value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_S32 Cms_GetORIGIN_Y(CMS_BROWSER_VOID)
{
    //return 19;
   cms_trace("MMI_title_y=%d",MMI_title_y+MMI_title_height);
    return (MMI_title_y+MMI_title_height);
} 

 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetLINE_HIGHT
 *       Purpose: get a line hight
 *         Input:  None
 *        Output: None.
 *       Returns: line hight
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_GetLINE_HIGHT(CMS_BROWSER_VOID)
{
//    return 18;
    return pixtel_UI_get_character_height();
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetLINEHIGHT
 *       Purpose: get a line hight
 *         Input:  None
 *        Output: None.
 *       Returns: line hight
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_GetSCREEN_LINE(CMS_BROWSER_VOID)
{
    return MMI_content_height / pixtel_UI_get_character_height();
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetSCROLLBAR_W
 *       Purpose: get scrollbar W postion 
 *         Input:  None
 *        Output: None.
 *       Returns: scrollbar W postion value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_GetSCROLLBAR_W(CMS_BROWSER_VOID)
{
#if 0
#ifdef __MMI_TOUCH_SCREEN__
    return 15;/*客户根据屏幕大小自动调整*/
#else
	return 5;
#endif
#endif
	/*与平台滚动条参数相关*/
	return current_MMI_theme->scrollbar_size;
}
  /* ----------------------------------------------------------------------------
 * Function Name: Cms_Horizontal_GetSCROLLBAR_W
 *       Purpose: get  horizontal scrollbar W postion 
 *         Input:  None
 *        Output: None.
 *       Returns: scrollbar W postion value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 *				添加这个函数接口，区分垂直滚动条和水平滚动条的宽度，
 *				如果想单独改变其中之一的宽度就可以分别改变这两个函数接口。
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_Horizontal_GetSCROLLBAR_W(CMS_BROWSER_VOID)
{
	/*与平台滚动条参数相关*/
	return (current_MMI_theme->scrollbar_size);
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetSELECTHIGHT
 *       Purpose: get select box rect hight 
 *         Input:  None
 *        Output: None.
 *       Returns: select box rect hight value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_S32 Cms_GetSELECTHIGHT(CMS_BROWSER_VOID)
{
 //   return 19;
 #ifdef NO_SHOW_STATEBAR
 #ifndef WAP_SHOW_ACROSS_SCOLLBAR
 	return MMI_button_bar_height;
 #else
 	return MMI_button_bar_height+Cms_GetSCROLLBAR_W();
 #endif
 #else
 #ifndef WAP_SHOW_ACROSS_SCOLLBAR
 	return MMI_button_bar_height*2;
 #else
 	return MMI_button_bar_height*2+Cms_GetSCROLLBAR_W();
 #endif
 #endif
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetTITLEHIGHT
 *       Purpose: get title hight 
 *         Input:  None
 *        Output: None.
 *       Returns: title hight value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_GetTITLEHIGHT(CMS_BROWSER_VOID)
{
	cms_trace("MMI_title_y=%d",MMI_title_y);
	cms_trace("MMI_title_height=%d",MMI_title_height);
	cms_trace("MMI_content_y=%d",MMI_content_y);
	return (MMI_content_y);//(MMI_title_y+MMI_title_height);//changed by yangjun 05-10-25
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetSTATUSBAR_H
 *       Purpose: get status bar hight 
 *         Input:  None
 *        Output: None.
 *       Returns:status bar hight value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_GetSTATUSBAR_H(CMS_BROWSER_VOID)
{
    //return 20;
    cms_trace("MMI_button_bar_height=%d",MMI_button_bar_height);
    return MMI_button_bar_height+6;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetSCREEN_W
 *       Purpose: get screen width 
 *         Input:  None
 *        Output: None.
 *       Returns:screen width value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */   
CMS_BROWSER_S32 Cms_GetSCREEN_W(CMS_BROWSER_VOID)
{
    //return 128;
    cms_trace("UI_device_width=%d",UI_device_width);
    return UI_device_width;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetSCREEN_H
 *       Purpose: get screen hight 
 *         Input:  None
 *        Output: None.
 *       Returns:screen hight value
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */ 
CMS_BROWSER_S32 Cms_GetSCREEN_H(CMS_BROWSER_VOID)
{
   // return 160;
   cms_trace("UI_device_height=%d",UI_device_height);
   return UI_device_height;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetFONT_W
 *       Purpose: get font width 
 *         Input:  None
 *        Output: None.
 *       Returns:get font width
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_S32 Cms_GetFONT_W(void)
{
	/*如果字体是15*16，返回7*/
#if defined(__MMI_MAINLCD_240X320__)
	return 9;
#else
        return 7;
#endif
	/*如果字体是17*18，返回9*/
}
  /* ----------------------------------------------------------------------------
 * Function Name: Cms_GetFontWidth
 *       Purpose:获得字体类型的宽度
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
unsigned short Cms_GetFontWidth (unsigned char font_type,	/*(in)字体类型 */
								unsigned short word)	/*(in)一个字 */
{	
	unsigned short font_width = 0;
	switch( font_type )
	{
	case 1:
		if( 1 == word&&0x80  )
		{
			font_width = 16;
		}
		else
		{
			font_width = 8;
		}
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	default:
		break;
	}
	return font_width;
}
  /* ----------------------------------------------------------------------------
 * Function Name: 
 *       Purpose:
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
unsigned char Cms_GetFontTypeNum(void)
{
	return 1;
}

/*************************************************************************************************
 *                           				CMS MTK PHB INTERFACE	                       *
 *************************************************************************************************/  

/* ----------------------------------------------------------------------------
 * Function Name: mmi_cms_search_phb_callback
 *       Purpose:  
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_cms_search_phb_callback(MMI_PHB_VCARD_STRUCT *entity)
{
   if(entity != NULL)
   {
      if(strlen((S8*)entity->number)&&(gphb_flag==CMS_PHB_MMS))
      	{
      		memset(phb_callbuf,0,sizeof(phb_callbuf));
		if(strlen((S8*)entity->number)>=MMS_MAX_INPUT_SEND_TO_SIZE-1)
		{
         		AnsiiNToUnicodeString((S8*)phb_callbuf, (S8*)entity->number,MMS_MAX_INPUT_SEND_TO_SIZE-1);
		}
		else
		{
		         AnsiiToUnicodeString((S8*)phb_callbuf, (S8*)entity->number);
		}
	}
	if(strlen((S8*)entity->emailAddress)&&(gphb_flag==CMS_PHB_EMAIL))
      	{
      		memset(phb_callbuf,0,sizeof(phb_callbuf));
		if(strlen((S8*)entity->emailAddress)>=MMS_MAX_INPUT_SEND_TO_SIZE-1)
		{
         		AnsiiNToUnicodeString((S8*)phb_callbuf, (S8*)entity->emailAddress,MMS_MAX_INPUT_SEND_TO_SIZE-1);
		}
		else
		{
		         AnsiiToUnicodeString((S8*)phb_callbuf, (S8*)entity->emailAddress);
		}
	}
	GoBackHistory ();
   }
   else
   {
		DisplayPopup ((PU8)GetString (STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY,NULL, CMS_MMS_POPUP_DELAY_TIME, (U8)ERROR_TONE);
   }
}

/* ----------------------------------------------------------------------------
 * Function Name: mmi_cms_entry_search_from_phb
 *       Purpose:  
 *         Input: void
 *        Output: None.
 *       Returns: None.
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
void mmi_cms_entry_search_from_phb(void)
{
   mmi_phb_generic_enter_list(mmi_cms_search_phb_callback);
}

/*************************************************************************************************
 *                           							UTF8,unicode	                       *
 *************************************************************************************************/  
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_mms_uni8_16_2Sub
 *       Purpose: Subject:utf8到unicode转码,判断是否超过最大长度，否则截断并在其后加省略号
 *         Input:  buf_utf8: 待转换utf8码
 *        Output: None.
 *       Returns:转换成功后分配字符串空间首地址
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
char *Cms_mms_uni8_16_2Sub(char *buf_utf8)
{
	char		*buf_uni = NULL;
	char		real_sub[MMS_MAX_UTF_SUBJECT_SIZE] = {0};
	int		uni_len = 0;
	int 		i = 0 ,j = 0;
	int		str_num = 0;
	int		str_len = 0;

	str_len = strlen(buf_utf8)+1;
	while(i<str_len)
	{
		if( (*(buf_utf8+i) > 0) && *(buf_utf8+i) <= 0x7F)
			i++;
		else if( (*(buf_utf8+i) <= 0xDF) && (*(buf_utf8+i) >= 0xC0) &&
			(*(buf_utf8+i+1) <= 0xBF) && (*(buf_utf8+i+1) >= 0x80)  )
			i+=2;
		else if( ((*(buf_utf8+i) >= 0xE0 && *(buf_utf8+i) <= 0xEF) && 
			(*(buf_utf8+i+1) <= 0xBF && *(buf_utf8+i+1) >= 0x80) && 
			(*(buf_utf8+i+2) <= 0xBF && *(buf_utf8+i+2) >= 0x80)) )
			i+=3;
		else
		{
			i++;
			continue;
		}	
		str_num++;
		if(str_num==MMS_MAX_INPUT_SUBJECT_SIZE-7)
			j = i;
	}
	if(str_num > MMS_MAX_INPUT_SUBJECT_SIZE-4)
	{
		memcpy(real_sub,buf_utf8,j);
		strcat(real_sub,"...");
		str_len = j+4;
	}
	else
	{
        	strcpy(real_sub,buf_utf8);
	}
	
	uni_len = 2*str_len +2;
	buf_uni = (char *)mms_Malloc(uni_len);
	Cms_Browser_Uni8_16_big((P_CMS_BROWSER_U8)real_sub,(P_CMS_BROWSER_U8)buf_uni);
	return buf_uni;
}

 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni16_strlen
 *       Purpose:编码为UTF16的U8字串的实际字数
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_U32 Cms_Browser_Uni16_strlen(P_CMS_BROWSER_U8 string)
{
	CMS_BROWSER_U32 leng = 0,i=0;
    	
	while(*(string+i)!=0 || *(string+i+1)!=0)
	{
		leng++;
		i+=2;
	}
	return leng;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni16_Uni8_strlen
 *       Purpose:得到16位U8字符串转换为UTF8字符串的长度
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_U32 Cms_Browser_Uni16_Uni8_strlen(P_CMS_BROWSER_U8 string)
{
	CMS_BROWSER_U32 leng = 0,i=0;
	CMS_BROWSER_U16 temp_str = 0;

	if(string == NULL)
	{
		return 0;
	}
	
	while(*(string+i)!=0 || *(string+i+1)!=0)
	{
        temp_str = (CMS_BROWSER_U16)((*(string+i))*256 + *(string+i+1));
		if(temp_str>0 && temp_str<=0x7F)
			leng++;
		else if(temp_str>=0x80 && temp_str<=0x7FF)
			leng+=2;
		else if(temp_str>=0x800 && temp_str<=0xFFFF)
			leng+=3;
		i+=2;
	}
	
	return leng;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni16_Uni8_strlen_big
 *       Purpose:得到16位U8字符串转换为UTF8字符串的长度
 *			与上面函数的参数字节序相反
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_U32 Cms_Browser_Uni16_Uni8_strlen_big(P_CMS_BROWSER_U8 string)
{
	CMS_BROWSER_U32 leng = 0,i=0;
	CMS_BROWSER_U16 temp_str = 0;

	if(string == NULL)
	{
		return 0;
	}
	
	while(*(string+i)!=0 || *(string+i+1)!=0)
	{
        temp_str = (CMS_BROWSER_U16)((*(string+i+1))*256 + *(string+i));
		if(temp_str>0 && temp_str<=0x7F)
			leng++;
		else if(temp_str>=0x80 && temp_str<=0x7FF)
			leng+=2;
		else if(temp_str>=0x800 && temp_str<=0xFFFF)
			leng+=3;
		i+=2;
	}

	return leng;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni8_strlen
 *       Purpose:UTF8字符串的实际字数
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_U32 Cms_Browser_Uni8_strlen(P_CMS_BROWSER_U8 string)
{
	CMS_BROWSER_U32 leng = 0,i = 0,string_len = 0;
	string_len = Cms_Browser_StrLen(string);
	i=0;
	
	while(i<string_len)
	{
		if( (*(string+i) > 0) && *(string+i) <= 0x7F)
			i++;
		else if( (*(string+i) <= 0xDF) && (*(string+i) >= 0xC0) &&
			(*(string+i+1) <= 0xBF) && (*(string+i+1) >= 0x80)  )
			i+=2;
		else if( ((*(string+i) >= 0xE0 && *(string+i) <= 0xEF) && 
			(*(string+i+1) <= 0xBF && *(string+i+1) >= 0x80) && 
			(*(string+i+2) <= 0xBF && *(string+i+2) >= 0x80)) )
			i+=3;
		else
		{
			i++;
			continue;
		}
		
		leng++;
	}
	return leng;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni16_8
 *       Purpose:将一个UTF16的字符串转换为UTF8的字串
 *			(两个字符串的空间分配和释放不在此函数中进行)
 *         Input:  P_CMS_BROWSER_U16 uni_16 
  P_CMS_BROWSER_U8 uni_8
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
CMS_BROWSER_VOID Cms_Browser_Uni16_8(P_CMS_BROWSER_U8 uni_16_8, P_CMS_BROWSER_U8 uni_8)
{
	P_CMS_BROWSER_U16 uni_16 = NULL;
	CMS_BROWSER_U16   temp = 0;
	int i=0,j=0,leng = 0;
	
	if (NULL == uni_16_8 || NULL == uni_8)
	{
		return;
	}
	
	leng = Cms_Browser_Uni16_strlen(uni_16_8);
	uni_16 = (P_CMS_BROWSER_U16)mms_Malloc(leng*2+2);

	if(uni_16 == NULL)
	{
		return;
	}


	while(j<leng)
	{
		*(uni_16+j) = (CMS_BROWSER_U16 )((*uni_16_8)*256 + *(uni_16_8+1)) ;
		j++;
		if (j == leng)
		{
			break;
		}
		else
		{
			uni_16_8 = uni_16_8 + 2;
		}
	}
	*(uni_16+j) = 0;
	

	j=0;
	while(*(uni_16+j)!=0)
	{
		temp = *(uni_16+j);
		
		if( temp>0 && temp<0x80)
		{
			*(uni_8+i) = (CMS_BROWSER_U8)(temp); 
			i++;
		}
		else if(temp>=0x80 && temp<=0x7FF)
		{
			*(uni_8+i) = (CMS_BROWSER_U8)(temp >> 6) + 0xC0;
			*(uni_8+i+1) = (CMS_BROWSER_U8)(temp & 0x3F) + 0x80;
			i = i + 2;
		}
		else if(temp>=0x800 && temp<=0xFFFF)
		{
			*(uni_8+i) = (CMS_BROWSER_U8)(temp >> 12) + 0xE0;
			*(uni_8+i+1) =  (CMS_BROWSER_U8)((temp & 0xFC0) >> 6) + 0x80;
			*(uni_8+i+2) = (CMS_BROWSER_U8)(temp & 0x3F) + 0x80;
			i = i + 3;
		}

		j++;
	}
	*(uni_8+i) = 0;


	i = 0;
	mms_Free(uni_16);
	uni_16 = NULL;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni16_8_big
 *       Purpose:将一个UTF16的字符串转换为UTF8的字串
 *	                    (两个字符串的空间分配和释放不在此函数中进行)
 *				与Cms_Browser_Uni16_8的区别是输入的uni_16的字节序相反
 *         Input:  P_CMS_BROWSER_U16 uni_16 
 * 			  P_CMS_BROWSER_U8 uni_8
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_VOID Cms_Browser_Uni16_8_big(P_CMS_BROWSER_U8 uni_16_8, P_CMS_BROWSER_U8 uni_8)
{
	P_CMS_BROWSER_U16 uni_16 = NULL;
	CMS_BROWSER_U16   temp = 0;
	int i=0,j=0,leng = 0;
	
	if (NULL == uni_16_8 || NULL == uni_8)
	{
		return;
	}
	
	leng = Cms_Browser_Uni16_strlen(uni_16_8);
	uni_16 = (P_CMS_BROWSER_U16)mms_Malloc(leng*2+2);

	if(uni_16 == NULL)
	{
		return;
	}

	while(j<leng)
	{
		*(uni_16+j) = (CMS_BROWSER_U16 )(*(uni_16_8+1)*256 + *(uni_16_8)) ;
		j++;
		if (j == leng)
		{
			break;
		}
		else
		{
			uni_16_8 = uni_16_8 + 2;
		}
	}
	*(uni_16+j) = 0;
	
	j=0;
	while(*(uni_16+j)!=0)
	{
		temp = *(uni_16+j);
		
		if( temp>0 && temp<0x80)
		{
			*(uni_8+i) = (CMS_BROWSER_U8)(temp); 
			i++;
		}
		else if(temp>=0x80 && temp<=0x7FF)
		{
			*(uni_8+i) = (CMS_BROWSER_U8)(temp >> 6) + 0xC0;
			*(uni_8+i+1) = (CMS_BROWSER_U8)(temp & 0x3F) + 0x80;
			i = i + 2;
		}
		else if(temp>=0x800 && temp<=0xFFFF)
		{
			*(uni_8+i) = (CMS_BROWSER_U8)(temp >> 12) + 0xE0;
			*(uni_8+i+1) =  (CMS_BROWSER_U8)((temp & 0xFC0) >> 6) + 0x80;
			*(uni_8+i+2) = (CMS_BROWSER_U8)(temp & 0x3F) + 0x80;
			i = i + 3;
		}

		j++;
	}
	*(uni_8+i) = 0;

	mms_Free(uni_16);
	uni_16 = NULL;
}

  /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni8_16
 *       Purpose:将一个UTF8的字符串转换为UTF16的字串
 			(两个字符串的空间分配和释放不在此函数中进行)
 *         Input:  P_CMS_BROWSER_U8 uni_8
                      P_CMS_BROWSER_U32 uni_16 	
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_VOID Cms_Browser_Uni8_16(P_CMS_BROWSER_U8 uni_8,P_CMS_BROWSER_U8 uni_16)
{
	CMS_BROWSER_U32 i=0, o=0,len=0;
	CMS_BROWSER_U32 f =0;	
	CMS_BROWSER_U16      tem_str;
		
	if(uni_8 == NULL)
	{
		return;
	}		  
		  		  
	len = Cms_Browser_StrLen(uni_8);
	while(f<len)
	{
		if( (*(uni_8+f) > 0) && *(uni_8+f) <= 0x7F)
		 {
			o = 1;
			 tem_str = (CMS_BROWSER_U16) (*(uni_8+f));
		}
			  
		else if( (*(uni_8+f) <= 0xDF) && (*(uni_8+f) >= 0xC0) &&
				  (*(uni_8+f+1) <= 0xBF) && (*(uni_8+f+1) >= 0x80) )
		{
			 o =2;
			 tem_str = (CMS_BROWSER_U16) ( (CMS_BROWSER_U8)( ((*(uni_8+f)) & 0x1C)>>2 )*256 + (CMS_BROWSER_U8)(((*(uni_8+f)) & 0x03)<<6) + (*(uni_8+f+1) & 0x3F) );
		}
		 else if( ((*(uni_8+f) >= 0xE0 && *(uni_8+f) <= 0xEF) && 
				  (*(uni_8+f+1) <= 0xBF && *(uni_8+f+1) >= 0x80) && 
				  (*(uni_8+f+2) <= 0xBF && *(uni_8+f+2) >= 0x80)) )
		{
	
			{
				o= 3;
				tem_str = (CMS_BROWSER_U16) ( ((CMS_BROWSER_U8)((*(uni_8+f)) << 4) + (CMS_BROWSER_U8)(( *(uni_8+f+1) & 0x3C) >>2))*256 + (CMS_BROWSER_U8)(*(uni_8+f+1) << 6) + (*(uni_8+f+2) & 0x3F));
			}
		}
		 else 
		 {
			  o=1;
		 }
		*(uni_16+i) = (CMS_BROWSER_U8)((tem_str & 0xFF00) >> 8);
		*(uni_16+i+1) = (CMS_BROWSER_U8)(tem_str & 0x00FF);
		f+=o;
		 i+=2;
	}
	*(uni_16+i) = 0;
	*(uni_16+i+1) = 0;
		  
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_Uni8_16_big
 *       Purpose:	将一个UTF8的字符串转换为UTF16的字串
                 	   (两个字符串的空间分配和释放不在此函数中进行)
                	    与Cms_Browser_Uni8_16的区别是输出的uni_16字节序相反
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
CMS_BROWSER_VOID Cms_Browser_Uni8_16_big(P_CMS_BROWSER_U8 uni_8,P_CMS_BROWSER_U8 uni_16)
{
	CMS_BROWSER_U32 i=0, o=0,len;
	CMS_BROWSER_U32 f =0;
	
	CMS_BROWSER_U16      tem_str;
		
	if(uni_8 == NULL)
	{
		return;
	}		  
		  	  
		  len = Cms_Browser_StrLen(uni_8);
		  		  
		  while(f<len)
		  {
			  if( (*(uni_8+f) > 0) && *(uni_8+f) <= 0x7F)
			  {
				  o = 1;
				  tem_str = (CMS_BROWSER_U16) (*(uni_8+f));
			  }
			  
			  else if( (*(uni_8+f) <= 0xDF) && (*(uni_8+f) >= 0xC0) &&
				  (*(uni_8+f+1) <= 0xBF) && (*(uni_8+f+1) >= 0x80) )
			  {
				  o =2;
				  tem_str = (CMS_BROWSER_U16) ( (CMS_BROWSER_U8)( ((*(uni_8+f)) & 0x1C)>>2 )*256 + (CMS_BROWSER_U8)(((*(uni_8+f)) & 0x03)<<6) + (*(uni_8+f+1) & 0x3F) );
			  }
			  else if( ((*(uni_8+f) >= 0xE0 && *(uni_8+f) <= 0xEF) && 
				  (*(uni_8+f+1) <= 0xBF && *(uni_8+f+1) >= 0x80) && 
				  (*(uni_8+f+2) <= 0xBF && *(uni_8+f+2) >= 0x80)) )
			  {
				  {
					  o= 3;
					  tem_str = (CMS_BROWSER_U16) ( ((CMS_BROWSER_U8)((*(uni_8+f)) << 4) + (CMS_BROWSER_U8)(( *(uni_8+f+1) & 0x3C) >>2))*256 + (CMS_BROWSER_U8)(*(uni_8+f+1) << 6) + (*(uni_8+f+2) & 0x3F));
				  }
			  }else
			  o=1;
			  *(uni_16+i+1) = (CMS_BROWSER_U8)((tem_str & 0xFF00) >> 8);
			  *(uni_16+i) = (CMS_BROWSER_U8)(tem_str & 0x00FF);
			  
			  f+=o;
			  i+=2;
			  
		  }
		  *(uni_16+i) = 0;
		  *(uni_16+i+1) = 0;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_mms_uni8_16
 *       Purpose: utf8到unicode转码
 *         Input:  char *buf_utf8
 *        Output: None.
 *       Returns:转换成功后分配字符串空间首地址
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
char *Cms_mms_uni8_16(char *buf_utf8)
{

	char		  *buf_uni = NULL;
	int		       uni_len = 0;
	uni_len = 2*Cms_Browser_Uni8_strlen((P_CMS_BROWSER_U8 )buf_utf8)+2;
	buf_uni = (char *)mms_Malloc(uni_len);
	Cms_Browser_Uni8_16_big((P_CMS_BROWSER_U8)buf_utf8,(P_CMS_BROWSER_U8)buf_uni);
	return buf_uni;
}
  /* ----------------------------------------------------------------------------
 * Function Name: Cms_mms_uni16_8
 *       Purpose:  unicode 到utf8转码
 *         Input:   buf_utf8: 待转换unicode码
 *        Output: None.
 *       Returns:转换成功后分配字符串空间首地址
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
char *Cms_mms_uni16_8(char *buf_uni)
{
	char		  *buf_utf8 = NULL;
	int		       uni_len = 0;			
	uni_len = Cms_Browser_Uni16_Uni8_strlen_big((P_CMS_BROWSER_U8 )buf_uni);
	buf_utf8 = (char *)mms_Malloc(uni_len+1);
	memset(buf_utf8,0,uni_len+1);
	Cms_Browser_Uni16_8_big((P_CMS_BROWSER_U8)buf_uni,(P_CMS_BROWSER_U8)buf_utf8);
		
	return buf_utf8;
}
/* ----------------------------------------------------------------------------
 * Function Name: mmi_get_utf16_width
 *       Purpose:获取UTF16字体宽度
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
 CMS_BROWSER_U32 mmi_get_utf16_width(CMS_BROWSER_U8 font,CMS_BROWSER_U16 Utf16)
{
	return pixtel_UI_get_character_width(Utf16);	   
}
/* ----------------------------------------------------------------------------
 * Function Name: CmsTime2String
 *       Purpose:时间转换
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void CmsTime2String(S8* datetime)
{
	MYTIME	t;
	char    temp[64] = {0};

	GetDateTime(&t);
	sprintf(temp,"%4d%d%d%d%d%d%d%d%d%d%d",
		(int)t.nYear,(int)(t.nMonth/10),(int)(t.nMonth%10),
		(int)(t.nDay/10),(int)(t.nDay%10),(int)(t.nHour/10),(int)(t.nHour%10),
		(int)(t.nMin/10),(int)(t.nMin%10),(int)(t.nSec/10),(int)(t.nSec%10));
	strcpy(datetime,(const char*)temp);
	return;
}

 /* ----------------------------------------------------------------------------
 * Function Name: CMS_itoa_unicode
 *       Purpose: 整型转字符串(设置页播放时间所用)
 *         Input:  i: 待转换的整数 str: 转换后字符串地址
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void CMS_itoa_unicode(U16 i, char* str)
{
	U16	dem = 0;
	if(i>MMS_MAX_PLAY_TIME)
	{
		i =MMS_MAX_PLAY_TIME;
	}
	dem=i /10;
	if (dem > 0)
	{
		str[0] = (char)(dem + 48);
		str[2] = (char)(i - (dem * 10) + 48);
	}
	else
	{
		str[0] = (char)(i + 48);
	}
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_IsHttpSupportedFileType
 *       Purpose:
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int  Cms_IsHttpSupportedFileType( Cms_ContentType_e contenttype )
{
	/*默认都下载*/
	return 1;
}
  /* ----------------------------------------------------------------------------
 * Function Name: Cms_Browser_NetRequest_Response
 *       Purpose:开放给UI使用，返回核心库处理结果
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */
int Cms_Browser_NetRequest_Response(unsigned char type, int retvalue, unsigned char* buffer, int len)
{
	switch(type)
	{
	case CMS_HTTP_CONTENT_IMAGE_ZDD:
		break;
	case CMS_HTTP_CONTENT_IMAGE_VIS:
		break;	
	case CMS_HTTP_CONTENT_IMAGE_DRM:
		break;
	case CMS_HTTP_CONTENT_IMAGE_STL:
		break;		
	case CMS_HTTP_CONTENT_IMAGE_BILL:
		if(retvalue)
			adp_Tracer("send bill ok");
		else
			adp_Tracer("send bill fail");
		break;	
	default:
		break;
	}
 	return 1;
}
 /* ----------------------------------------------------------------------------
 * Function Name: Cms_SetUAProfile
 *       Purpose:设置Profile
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_SetUAProfile(char *UAProfile)
{
	if(UAProfile)
	{
		/*在此处设置Profile,由用户填写*/
		#ifdef CMS_PC_CONFIG_SOFTWARE
		strcpy((char *)UAProfile,(const char *)cms_wap_config_default.ua_prof_url);
		#else
		strcpy((char *)UAProfile,(const char *)"http://nds1.nds.nokia.com/uaprof/N6230r200.xml");
		#endif
	}
}
    /* ----------------------------------------------------------------------------
 * Function Name: Cms_SetUseragent
 *       Purpose:设置User Agent
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  

void	Cms_SetUseragent(unsigned char * u_a)
{
	if(u_a)
	{
		/*在此处设置User Agent,由用户填写*/
		//strcpy((char *)u_a,(const char *)"NEC-N5102/(2005.07.01)1.0/WAP2.0 Profile/MIDP-2.0 Configuration/CLDC-1.1");
		//strcpy((char *)u_a,(const char *)"Nokia6230/2.0 (03.14) Profile/MIDP-2.0 Configuration/CLDC-1.1");
		#ifdef CMS_PC_CONFIG_SOFTWARE
		strcpy((char *)u_a,(const char *)cms_wap_config_default.ua_header);
		#else
		strcpy((char *)u_a,(const char *)"LENOVO-i908/(2006.09.30)S106A/WAP2.0 Profile/MIDP2.0 Configuration/CLDC1.1");
		#endif
	}
}
/* ----------------------------------------------------------------------------
 * Function mmsGetNetType: 
 *       Purpose:获取当前彩信网络连接类型
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
int mmsGetNetType()
{
	return 0;/*仅支持WAP1.2.1*/
}
/* ----------------------------------------------------------------------------
 * Function CmsProcessIdleEvent: 
 *       Purpose:在返回待机界面时做处理，销毁占用的资源
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void CmsProcessIdleEvent(void)
{
	if(CmsGetCurrentMmsState())
	{
		mmi_mms_exit_to_idle();
	}
/*    else
    {
        mmi_update_mms_idel_icon();
    }*/
	if(CmsGetCurrentWapState())
	{
		ExitWapBrowserByEndkey();
	}
/*    else
    {
        cms_show_wappush_icon();
    }*/
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetResourceByID: 
 *       Purpose:核心库获取平台资源
 *         Input:  None
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
unsigned char* Cms_GetResourceByID(int infoId)
{
	S8 *Cms_BrwString;
	adp_mmi_tracer( "in Cms_GetResourceByID : %d\n", infoId );
	switch(infoId)
	{
	case CMS_STR_NO_SERVER:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_NO_SERVER);
		break;
	case CMS_STR_NO_SUCH_SERVER:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_NO_SUCH_SERVER);
		break;	
	case CMS_STR_DIALING_FAILED:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_DIALING_FAILED);
		break;			
	case CMS_STR_CONNECTION_DISC:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_CONNECTION_DISC);
		break;				
	case CMS_STR_DIALING_CON_DISC:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_DIALING_CON_DISC);
		break;
	case CMS_STR_DATA_ERROR:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_DATA_ERROR);
		break;	
	case CMS_STR_INVALID_ADDRESS:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_INVALID_ADDRESS);
		break;			
	case CMS_STR_INVALID_URL:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_INVALID_URL);
		break;		
	case CMS_STR_ERROR_PAGE:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_ERROR_PAGE);
		break;
	case CMS_STR_ERROR_PAGE_TRY:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_ERROR_PAGE_TRY);
		break;	
	case CMS_STR_GETWAY_ERROR:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_GETWAY_ERROR);
		break;			
	case CMS_STR_GETWAY_NO_RES:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_GETWAY_NO_RES);
		break;		
	case CMS_STR_SERVER_ERROR:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_SERVER_ERROR);
		break;
	case CMS_STR_TIME_OUT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_TIME_OUT);
		break;	
	case CMS_STR_RES_TIME_OUT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_RES_TIME_OUT);
		break;			
	case CMS_STR_UNSUPPORT_FILE:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_UNSUPPORT_FILE);
		break;					
	case CMS_STR_UNSUPPORT_SORRY:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_UNSUPPORT_SORRY);
		break;		
	case CMS_STR_SUBMIT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_SUBMIT);
		break;
	case CMS_STR_BUTTON:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_BUTTON);
		break;	
	case CMS_STR_RESET:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_RESET);
		break;			
	case CMS_STR_SUBJECT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_SUBJECT);
		break;			
	case CMS_STR_ISSURER:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_ISSURER);
		break;
	case CMS_STR_VALID_NOTBEFORE:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_VALID_NOTBEFORE);
		break;	
	case CMS_STR_VALID_NOTAFTER:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_VALID_NOTAFTER);
		break;			
	case CMS_STR_MD_ALGORITHMS:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_MD_ALGORITHMS);
		break;		
	case CMS_STR_SIGN_ALGO:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_SIGN_ALGO);
		break;
	case CMS_STR_SIGNATURE:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_SIGNATURE);
		break;	
	case CMS_STR_VALID_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_VALID_CERT);
		break;			
	case CMS_STR_INVALID_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_INVALID_CERT);
		break;	
	case CMS_STR_UNTRUST_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_UNTRUST_CERT);
		break;
	case CMS_STR_REVOKED_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_REVOKED_CERT);
		break;	
	case CMS_STR_EXPIER_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_EXPIER_CERT);
		break;			
	case CMS_STR_ERPURPOSE_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_ERPURPOSE_CERT);
		break;			
	case CMS_STR_UNMACTH_CERT:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_UNMACTH_CERT);
		break;	
	case CMS_STR_UNKNOWN_ERROR:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_UNKNOWN_ERROR);
		break;
	case CMS_STR_CERT_WARNING_PROBLEM:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_CERT_WARNING_PROBLEM);
		break;	
	case CMS_STR_ENCRYPT_METHOD:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_ENCRYPT_METHOD);
		break;			
	case CMS_STR_CERT_INFO:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_CERT_INFO);
		break;	
	case CMS_STR_MALLOC_FAILED:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_MALLOC_FAILED);
		break;
	case CMS_STR_NET_EXCEPTION:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_NET_EXCEPTION);
		break;	
	case CMS_STR_BIG_FILE:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_BIG_FILE);
		break;			
	case CMS_STR_BIG_FILE_TO_DOWN:      
		Cms_BrwString =(S8 *)GetString(STR_WAP_BIG_FILE_TO_DOWN);
		break;	
	case CMS_STR_CON_SECURED:                    // 安全连接
		Cms_BrwString =(S8 *)GetString(STR_WAP_CON_SECURED);
		break;
	case CMS_STR_CON_TO_SERVICE:                 // 正在连接到服务器
		Cms_BrwString =(S8 *)GetString(STR_WAP_CON_TO_SERVICE);
		break;
	case CMS_STR_SECURED_CA:          // 正与服务器进行安全链接，是否继续？
		Cms_BrwString =(S8 *)GetString(STR_WAP_SECURED_CA);
		break;
	case CMS_STR_DOWNLOADING_IMAGE:						//正在下载图片标题
		Cms_BrwString =(S8 *)GetString(STR_WAP_DOWNLOADING_IMAGE);
		break;
	case CMS_STR_DOWNLOADIMG_OK:							//下载完毕
		Cms_BrwString =(S8 *)GetString(STR_WAP_DOWNLOADIMG_OK);
		break;	
	default:
		Cms_BrwString = NULL;
		break;
		}
	return (unsigned char*)Cms_BrwString;
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapSetupfilename: 
 *       Purpose:浏览器设置文件
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapSetupfilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_SETUP_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapSetupfilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapBookfilename: 
 *       Purpose:书签保存文件
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapBookfilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_BOOKMARK_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapBookfilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapBookmarkfilename: 
 *       Purpose: 默认书签保存路径
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapBookmarkfilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_DEFAULT_BOOKMARK_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapBookmarkfilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapPushfilename: 
 *       Purpose:获取push文件存储文件名
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapPushfilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_PUSH_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapPushfilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapCachefilename: 
 *       Purpose:获取cache文件名
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapCachefilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_CACHE_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapCachefilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapOfflinefilename: 
 *       Purpose:获取离线浏览文件名
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapOfflinefilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_OFFLINE_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapOfflinefilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapHistoryfilename: 
 *       Purpose:获取历史纪录文件名
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapHistoryfilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_HISTORY_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapHistoryfilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function Cms_GetWapCookiefilename: 
 *       Purpose:获取Cookie 文件名
 *         Input:  filename
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
void Cms_GetWapCookiefilename(unsigned char *filename)
{
	if(filename)
	{
		strcpy((char *)filename,(const char *)WAP_COOKIE_FILENAME);
	}
	adp_mmi_tracer("Cms_GetWapCookiefilename=%s", (char*)filename);
}
/* ----------------------------------------------------------------------------
 * Function CmsDrmProvider: 
 *       Purpose:
 *         Input:  drmmime  "application/vnd.oma.drm.content" 
 *        Output: None.
 *       Returns:
 *         Notes: Copyright(C) 2005 MobileSoft Technology (NanJing) Co.,LTD.
 * ----------------------------------------------------------------------------
 */  
int CmsDrmProvider(unsigned char* drmmime,unsigned char* httpdata,unsigned int datalen,char *temppointer)
{
	adp_Tracer("^_^^_^^_^CmsDrmProvider in^_^^_^^_^");
	adp_mmi_tracer("CmsDrmProvider datalen=%d", (char*)datalen);
	
}
 
#endif
