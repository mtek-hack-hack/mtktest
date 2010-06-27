#ifdef CMS_NEW_APP
//FOR CMS task
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "custom_util.h"
#include "stack_init.h"
#include "stack_ltlcom.h"
#include "EventsGprot.h"


//hardware platform valid
#ifdef MMI_ON_HARDWARE_P
/*************************************************************************
* Function declaration
 *************************************************************************/
static void custom_cms_main(task_entry_struct * task_entry_ptr);
void CMS_process_ilm (ilm_struct *current_ilm);
void custom_cms_init(void);
void custom_cms_config(void);
void custom_cms_reset(void);
void custom_cms_termination(void);
extern kal_bool mmi_check_msg( ilm_struct *ilm_ptr ); 
//extern void EntryScrMMSMenuList(void);
/*************************************************************************
* FUNCTION
*  customCMS_create
*
* DESCRIPTION
*  create CMS task , contains wap&mms&map modules
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
customCMS_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct customcms_handler_info =
   {
      custom_cms_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&customcms_handler_info;
   return KAL_TRUE;
}


//cms task entry function, receive external or internal message
void custom_cms_main(task_entry_struct *task_entry_ptr)
{
   ilm_struct current_ilm;
   kal_uint32   my_index;

   kal_get_my_task_index(&my_index);
   //wap_Tracer((char*)"-------------------custom_cms_main-------------------");

   while (1)
   {

      //receive internal message
      while (receive_msg_int_q(task_entry_ptr->task_indx, &current_ilm))
      {
           stack_set_active_module_id( my_index, current_ilm.dest_mod_id );
           CMS_process_ilm(&current_ilm);  /*process internal ILM */
      }

      //receive external message
      receive_msg_ext_q (
         task_info_g[task_entry_ptr->task_indx].task_ext_qid,
         &current_ilm);
      stack_set_active_module_id( my_index, current_ilm.dest_mod_id );
      CMS_process_ilm(&current_ilm); /*process external ILM */

   }

}


void custom_cms_init(void)
{
   //init information
}

void custom_cms_config(void)
{
   //init information
}

void custom_cms_reset(void)
{
   //init information
}

void custom_cms_termination(void)
{
   //init information
}

	
void CMS_test_response(void)
{
       ilm_struct *send_ilm;

       send_ilm = allocate_ilm(MOD_CMSWAP);
	send_ilm->src_mod_id = MOD_CMSWAP;
	send_ilm->dest_mod_id = MOD_CMSWAP;
	send_ilm->sap_id = 0;
	send_ilm->msg_id = MSG_ID_CMS_MAP_TEST;
	send_ilm->peer_buff_ptr = NULL;
	send_ilm->local_para_ptr = NULL;	
	msg_send_int_queue(send_ilm);

}

void CMS_wap_main( ilm_struct *ilm_ptr )
{
	ilm_struct *send_ilm;
	
	//kal_prompt_trace(MOD_MMI, "enter CMS_wap_main");	 
	//kal_prompt_trace(MOD_MMI, "CMS_wap_main ilm_ptr->msg_id = %d", ilm_ptr->msg_id);	
	if ( mmi_check_msg( ilm_ptr) == KAL_FALSE )
    {
		//kal_prompt_trace(MOD_MMI, "mmi_check_msg error");
		//mmi_err( MOD_TCM, MMI_ERR_MSG_CORRUPTED_SUBOP );
    }
    else
    {
		switch(ilm_ptr->msg_id)
		{	
		case MSG_ID_CMS_WAP_PARSER:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPARSER");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_PARSER;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_LAYOUT:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERLAYOUT");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_LAYOUT;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_DRAW:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERDRAW");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_DRAW;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;	

		case MSG_ID_CMS_WAP_NEWINPUTURL:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERNEWURI");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_NEWINPUTURL;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_PAGEUP:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEUP");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_PAGEUP;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
		
		case MSG_ID_CMS_WAP_PAGEDOWN:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEDOWN");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_PAGEDOWN;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_EDITBOX:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSEREDITBOX");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_EDITBOX;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_MAILADDRESS:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_MAILADDRESS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_MAILADDRESS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
			
		case MSG_ID_CMS_WAP_CALLREQUEST:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_CALLREQUEST");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_CALLREQUEST;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_STOREPHONENUM:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_STOREPHONENUM");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_STOREPHONENUM;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_WAP_NEXTLINKFOCUS:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_NEXTLINKFOCUS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_NEXTLINKFOCUS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_LASTLINKFOCUS:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_LASTLINKFOCUS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_LASTLINKFOCUS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
			
		case MSG_ID_CMS_WAP_RIGHTLINKFOCUS:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_NEXTLINKFOCUS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_RIGHTLINKFOCUS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_LEFTLINKFOCUS:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_NEXTLINKFOCUS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_LEFTLINKFOCUS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_SOCCLOSESUCCESS:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_NEXTLINKFOCUS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_SOCCLOSESUCCESS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_SOCCLOSEFAIL:
			//kal_prompt_trace(MOD_MMI, "MSG_ID_CMS_WAP_NEXTLINKFOCUS");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_SOCCLOSEFAIL;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_WAP_UPPAGE:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEUP");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_UPPAGE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
		
		case MSG_ID_CMS_WAP_DOWNPAGE:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEDOWN");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_DOWNPAGE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;	

		case MSG_ID_CMS_WAP_TOUCHPENDOWN:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEUP");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_TOUCHPENDOWN;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
		
		case MSG_ID_CMS_WAP_TOUCHPENUP:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEDOWN");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_TOUCHPENUP;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;		

		//changed by yangjun 06-07-25
		//修改一键上网帐号错误的死机问题
		case MSG_ID_CMS_WAP_DEVDEACTIVEATE:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERDEVDEACTIVEATE");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_DEVDEACTIVEATE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;	

		case MSG_ID_CMS_WAP_PAGEREFRESH:
			//kal_prompt_trace(MOD_MMI, "CMS_MESSAGE_BROWSERPAGEDOWN");
			
			send_ilm = allocate_ilm(MOD_CMSWAP);
			send_ilm->src_mod_id = MOD_CMSWAP;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_WAP_PAGEREFRESH;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;		
		default:
			break;
		}
    }	
}
void Cms_mms_main( ilm_struct *ilm_ptr )
{
	ilm_struct *send_ilm;
	
	//kal_prompt_trace(MOD_MMI, "Cms_mms_main");	   
	if ( mmi_check_msg( ilm_ptr) == KAL_FALSE )
    {
		//kal_prompt_trace(MOD_MMI, "mmi_check_msg error");
		//mmi_err( MOD_TCM, MMI_ERR_MSG_CORRUPTED_SUBOP );
    }
    else
    {
		switch(ilm_ptr->msg_id)
		{			

		case MSG_ID_CMS_MMS_NOTIFICATION_ARRIVE:
			//kal_prompt_trace(MOD_MMI, "MMS_NOTIFICATION_ARRIVE");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_NOTIFICATION_ARRIVE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;
			msg_send_ext_queue(send_ilm);
			break;

		case MSG_ID_CMS_MMS_RECV_SUCCESS:
			//kal_prompt_trace(MOD_MMI, "MMSRECV_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_RECV_SUCCESS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = NULL;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_SEND_SUCCESS:
			//kal_prompt_trace(MOD_MMI, "MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_SEND_SUCCESS;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_RECV_FAILED:
			//kal_prompt_trace(MOD_MMI, "MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_RECV_FAILED;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_SEND_FAILED_UNKNOWN:
			//kal_prompt_trace(MOD_MMI, "MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_SEND_FAILED_UNKNOWN;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_SEND_MESSAGE:
			//kal_prompt_trace(MOD_MMI, "wanggang MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_SEND_MESSAGE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_RECEIVE_MESSAGE:
			//kal_prompt_trace(MOD_MMI, "wanggang MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_RECEIVE_MESSAGE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_CONNECT_FAILED:
			//kal_prompt_trace(MOD_MMI, "wanggang MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_CONNECT_FAILED;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		case MSG_ID_CMS_MMS_PLAY_MESSAGE:
			//kal_prompt_trace(MOD_MMI, "wanggang MMS_SEND_SUCCESS");
			
			send_ilm = allocate_ilm(MOD_CMSMMS);
			send_ilm->src_mod_id = MOD_CMSMMS;
			send_ilm->dest_mod_id = MOD_MMI;
			send_ilm->sap_id = 0;
			send_ilm->msg_id = MSG_ID_CMS_MMS_PLAY_MESSAGE;
			send_ilm->peer_buff_ptr = NULL;
			send_ilm->local_para_ptr = ilm_ptr->local_para_ptr;	
			msg_send_ext_queue(send_ilm);
			break;
		default:
			break;
		}
    }	
}
/*cms task message process function*/
void CMS_process_ilm (ilm_struct *current_ilm)
{
     switch(current_ilm->dest_mod_id)
     {
         case MOD_CMSWAP:
		   CMS_wap_main(current_ilm);		 	
         break;

	 case MOD_CMSMMS:
		 Cms_mms_main(current_ilm);
         break;
         case MOD_CMSMAP:
         break;

         default:
	  break;
     }
     free_ilm( current_ilm );
}
#endif/*endif MMI_ON_HARDWARE_P*/
#endif
