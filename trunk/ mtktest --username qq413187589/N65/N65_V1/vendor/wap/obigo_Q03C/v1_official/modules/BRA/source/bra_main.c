/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * bra_main.c
 *
 * This file contain the Browser Reference Applications main functionality
 * such as Initialization and Termination functions. State handlers and the
 * internal signal receive funtion.
 *
 */

#include "msf_core.h"
#include "msf_log.h"
#include "msf_file.h"
#include "msf_lib.h"
#include "msf_cmmn.h"
#include "msf_pipe.h"

#include "bra_cfg.h"
#include "bra_vrsn.h"
#include "bra_cmn.h"
#include "bra_win.h"
#include "bra_if.h"
#include "bra_main.h"
#include "bra_req.h"
#include "bra_sig.h"
#include "bra_inse.h"
#include "bra_file.h"
#include "bra_bkm.h"
#include "bra_prof.h"
#include "bra_view.h"
#include "bra_sif.h"
#include "bra_opt.h"
#include "bra_rpl.h"
#include "bra_dlg.h"
#include "bra_act.h"
#include "bra_set.h"
#include "bra_int.h"
#include "bra_ofln.h"

#ifdef BRA_CONFIG_PROVISIONING
#include "bra_prs.h"
#endif
#ifdef BRA_CONFIG_UIS_PUSH_SL
#include "bra_psl.h"
#endif


#ifdef BRA_CFG_CCA
#include "bra_cca.h"
#endif

#include "bra_cbm.h"

#ifdef BRA_CFG_DUAL_SIM
#include "bra_sim.h"
#endif


#include "msf_env.h"
#include "msf_chrs.h"

#ifdef __DRM_SUPPORT__
#include "kal_release.h"
#include "fat_fs.h"
#include "drm_def.h"
#include "drm_main.h"
#include "msf_mime.h"
#endif

#include "SMSApi.h"
#include "smsal_l4c_enum.h"
#include "brs_plh.h"

#include "wapadp.h"
#include "widget_extension.h"
#include "widget.h"

#include "DLAgentDef.h"


#ifdef BRA_CFG_DUAL_SIM
#include "wap_cmn.h"
#endif

/******************************************************************************
 * Local Defines
 ******************************************************************************/
/* for phone book */
#define BRA_PHONEBOOK_NUM_MAX_CHAR              (40)
#define BRA_PHONEBOOK_NAME_ASCII_MAX_CHAR       (30)
#define BRA_PHONEBOOK_NAME_UTF8_MAX_CHAR        (14)

#define BRAa_PHONEBOOK_NUM_PREFIX_CHAR          '+'
#define BRA_IS_ASCII(s)  ((s) > 0  && (s) <= 127)



/* Command line parameters */
#define BRA_CL_MODE				    "-mode"
#define BRA_CL_MODE_HOMEPAGE	"homepage"
#define BRA_CL_MODE_MENU		  "menu"
#define BRA_CL_MODE_URL			  "url"
#define BRA_CL_MODE_RESUME    "resume"

typedef struct {
  MsfWindowHandle window;
  MsfActionHandle ok;
  MsfActionHandle exit;
} bra_auth_dlg_t;

/* This comment is part of an example to add a start mode to BRA.
 * The full example is described in the BRA Reference Manual 
 *
 * Ex: 1.1
 *
 * 1. Add a new command string here.
 *
 * #define BRA_CL_MODE_SET_AND_LOAD_HOME "set_and_load_home" 
 */

/******************************************************************************
 * Global variables
 ******************************************************************************/

static int bra_main_terminate;
static MSF_UINT32 bra_module_state;
static void *bra_main_start_cmd;
static int bra_main_active;
jmp_buf bra_jmpbuf;
int     bra_inside_run;
int     bra_browser_entry_from_menu;

static int bra_download_job_count;
static int bra_download_active_job_count;

#if 0
/* under construction !*/
#endif

#ifdef __DRM_SUPPORT__
static MSF_INT32 drm_file_handle = -1;
static MSF_INT32 drm_content_type = -1;
static kal_wchar *drm_ucs2file;
static char      *drm_pipe_name;
#endif








#ifdef __SUPPORT_INFUSIO__
extern void mmi_java_start_infusio_eureka_client(kal_char* command);
#endif /* __SUPPORT_INFUSIO__ */

#ifdef __MMI_VIDEO_STREAM__
extern void mmi_vdoply_send_rtsp_url_req(PS8 rtsp_url);  
#endif

extern void wap_enter_sms_editor_handler(void *p);
#ifdef MMS_SUPPORT
extern void wap_enter_mms_editor_handler(void *p);
#endif


extern void HDIa_socketDiscBearerById (MSF_INT32 networkAccountID);
extern void msm_dlg_destroy_act_dlg(void);
extern void msf_dlg_destroy_act_dlg_op(void);
extern int MSF_moduleIsRunning(MSF_UINT8 modId);  
extern void bra_prs_handle_destroy_ui(void);
extern void HDIa_releaseBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);

/******************************************************************************
 * Local Functions
 *****************************************************************************/
void bra_main_content_register(void)
{
  void *handle;
  handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
  MSF_REGISTRY_SET_PATH (handle, (char*)"/MSM/RT_DB/BRA");
  MSF_REGISTRY_SET_ADD_KEY_STR (handle, "Scheme", 
          (unsigned char*)BRA_CFG_CONTENT_SCHEME, (MSF_UINT16) (strlen(BRA_CFG_CONTENT_SCHEME) +1));
  MSF_REGISTRY_SET_COMMIT (handle);
}

void bra_main_content_deregister(void)
{
  MSF_REGISTRY_DELETE (MSF_MODID_BRA, (char*)"/MSM/RT_DB/BRA", NULL);
}


/*
 *  When a module previously started by BRA is active it returns a. 
 *  signal. This function handles such notifications. 
 *
 *  Return: Void
 */
static void
bra_module_status (bra_signal_t *sig)
{
  MSF_UINT8       src_module;
  MSF_UINT8       status;

  status = (MSF_UINT8)sig->i_param;
  src_module = (MSF_UINT8)sig->u_param1;

  switch(src_module)
  {
  case MSF_MODID_BRS:
    if (status == MODULE_STATUS_ACTIVE)
      bra_sif_handle_brs_active();
    else if (status == MODULE_STATUS_TERMINATED)
      bra_sif_handle_brs_terminated();
    break;
#ifdef BRA_CONFIG_UIS_PUSH_SL
  case MSF_MODID_UIS:
     MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
                   BRA_MAIN_D5CCDD8FED4800B932368B1C91F0839A, "BRA: received module status from UIS status = %i\n", status));

    if (status == MODULE_STATUS_ACTIVE)
      bra_psl_set_uis_state_active ();
    else if (status == MODULE_STATUS_TERMINATED)
      bra_psl_uis_terminated();
    break;
#endif

  default:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
      BRA_MAIN_44255C6F0F63A7EAE0EE5E52EEDFACF1, "BRA: ERROR: Sorce module not handled in switch. (function: bra_module_status)\n"));
    break;

  }
}


/*
 * This function continues to terminates the BRA.
 * It frees all allocated memory and terminates the internal
 * signal queue. Before returning the macro MSF_MODULE_IS_TERMINATED
 * is called to notify MSF that the BRA is terminated.
 *
 * Retrun Void
 */
static void
bra_main_continue_terminate (void)
{
  /*If module status is anything else but BRA_NULL_STATE return*/
  if (bra_module_state != BRA_NULL_STATE)
    return;

  /*Terminate History list*/
  bra_rpl_destroy(); 
  /*Close all windows*/
  bra_win_destroy();

  /*Free allocated memory*/
  bra_cmn_free_local_hompage ();
  bra_cmn_free_current_page ();
  bra_prof_destroy (BRA_PROF_ID_BRA);
#ifdef BRA_CONFIG_PROVISIONING
  bra_prs_terminate ();
#endif
  //bra_req_destroy_address_list ();
  bra_req_clear_pending_req_url ();
  bra_opt_remove_do_elements ();
  //Q03C1
  bra_act_disable_object_action();

  bra_cbm_terminate();

#ifdef BRA_CFG_DUAL_SIM
  bra_sim_terminate(); 
#endif

  /*BRA is no longer active*/
  bra_main_active = 0;

  /*Remove all widgets*/
  MSF_WIDGET_RELEASE_ALL (MSF_MODID_BRA);

  /*remove signal queue*/
  MSF_SIGNAL_DEREGISTER_QUEUE (MSF_MODID_BRA);
	bra_signal_terminate ();

	MSF_MEM_FREE_ALL (MSF_MODID_BRA);
	MSF_MODULE_IS_TERMINATED (MSF_MODID_BRA);
	MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_LOW, MSF_MODID_BRA, BRA_MAIN_EC1C80F82B907323DADF397A528C1E2E, "BRA: Terminated\n"));
  
  MSF_KILL_TASK (MSF_MODID_BRA);

#ifdef __SAT__
  bra_send_termination_to_mmi(BRA_SAT_ERROR_TERMINATION);
#endif
}


/*
 * This function is the start of the termination routine.
 * It starts by terminating the BRS (if activated by BRA). 
 * If the BRS never was started the termination process is
 * continued, otherwise it waits until BRS return that it
 * is terminated.
 *
 * Retrun Void
 */
static void
bra_terminate (void)
{
  int delayed = 0;

  /*Set the status variable to indicate that we want to terminate the BRA*/
  bra_main_terminate = 1;

  bra_act_terminate (); //Q03C1

  bra_main_remove_module_state(BRA_INITIALIZED);

  if (bra_sif_get_brs_status () != BRA_SIF_BRS_NOT_ACTIVE)
  {
    BRSif_deleteInstance (MSF_MODID_BRA, bra_sif_get_brs_id ());
	  MSF_MODULE_TERMINATE(MSF_MODID_BRA, MSF_MODID_BRS);
    delayed++;
  }
#ifdef BRA_CONFIG_UIS_PUSH_SL
  if (bra_psl_uis_terminate () == 1)
    delayed++;
#endif

  if(delayed == 0)
    bra_main_continue_terminate ();
}

#ifdef __DRM_SUPPORT__

static void bra_proc_drm_right (int from_push)
{
  extern drm_proc_enum DRM_process_file(kal_uint8 *mime_type, kal_wchar *file_path, kal_bool temp_use);
  const char * const drm_right_xml = "application/vnd.oma.drm.rights+xml";
  const char * const drm_right_wbxml = "application/vnd.oma.drm.rights+wbxml";   
  int bytes_write;
  drm_proc_enum drm_result;

  if(FS_GetFileSize(drm_file_handle, (UINT*)&bytes_write) != FS_NO_ERROR || bytes_write <= 0)
  {           
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_DRM_RO_FORMAT, MsfError, 0);
    FS_Close(drm_file_handle);
    drm_file_handle = -1;
    FS_Delete(drm_ucs2file);
    BRA_FREE(drm_ucs2file);
    drm_ucs2file = NULL;
    return;
  }

  FS_Close(drm_file_handle);
  drm_file_handle = -1;
  
  if(drm_content_type == MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_WBXML)
    drm_result = DRM_process_file((kal_uint8*)drm_right_wbxml, drm_ucs2file, KAL_FALSE);
  else
    drm_result = DRM_process_file((kal_uint8*)drm_right_xml, drm_ucs2file, KAL_FALSE);

  BRA_FREE(drm_ucs2file);
  drm_ucs2file = NULL;

  if(!bra_view_if_has_viewable_page()
     && !bra_win_get_window(BRA_WIN_ID_INSE)
     && !bra_win_get_window(BRA_WIN_ID_OPT)
     && !bra_win_get_window(BRA_WIN_ID_PUSH_MSG_OPT_DLG))
  {
    bra_destroy_ui();
  }

  if (drm_result == DRM_RESULT_INVALID_FORMAT)
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_DRM_RO_FORMAT, MsfError, 0);
  else if (drm_result == DRM_RESULT_FILE_EXISTS)
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_DRM_RO_EXISTS, MsfError, 0);
  else
    HDIa_widgetExtRegisterDRMRightNotification(BRA_STR_DRM_RO_RECEIVED, MsfInfo);
}

static int bra_read_drm_pipe (MSF_INT32 handle, MSF_INT32 file_handle)
{
   char *buf;
   int read_len, ret, bytes_write;

   buf = BRA_ALLOC(1024);
   while(1)
   {
     read_len = MSF_PIPE_READ(handle, buf, 1024);
     if(read_len > 0)
     {
       ret = FS_Write(file_handle, buf, read_len, (UINT*)&bytes_write);
       if(ret == FS_NO_ERROR && read_len == bytes_write)
         continue;
     }
     break;
   }
   BRA_FREE(buf);

   if(read_len == MSF_PIPE_ERROR_DELAYED && MSF_PIPE_POLL (handle) == 0)
     return 1;

   MSF_PIPE_CLOSE(handle);
   MSF_PIPE_DELETE(drm_pipe_name);
   BRA_FREE(drm_pipe_name);
   drm_pipe_name = NULL;
   return 0;
}

static void bra_read_drm_right (MSF_INT32 handle, MSF_UINT32 eventType)
{
  if(drm_file_handle <= 0)
  {
    MSF_PIPE_CLOSE(handle);
    if(drm_pipe_name != NULL)
    {
      MSF_PIPE_CLOSE(handle);
      MSF_PIPE_DELETE(drm_pipe_name);
      BRA_FREE(drm_pipe_name);
      drm_pipe_name = NULL;
    }           
    return;
  }

  switch(eventType)
  {
  case MSF_PIPE_EVENT_READ:   
    if(!bra_read_drm_pipe(handle, drm_file_handle))
      bra_proc_drm_right(FALSE);          
    break;
  default:
    MSF_PIPE_CLOSE(handle);
    MSF_PIPE_DELETE(drm_pipe_name);                                
    BRA_FREE(drm_pipe_name);
    drm_pipe_name = NULL;
    bra_proc_drm_right(FALSE);
    break;
  }
}

static void bra_handle_drm_right(msf_module_execute_cmd_t *cl)
{
  const char * const drm_right_xml = "application/vnd.oma.drm.rights+xml";
  const char * const drm_right_wbxml = "application/vnd.oma.drm.rights+wbxml";
  char *tmpfile;
  
  drm_content_type = -1;

  if(strstr(cl->contentData->contentHeaders, drm_right_wbxml) != NULL)
    drm_content_type = MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_WBXML;
  else if(strstr(cl->contentData->contentHeaders, drm_right_xml) != NULL)
    drm_content_type = MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_XML;
  else
    return;

  /* write rights object to file and then process it */  
  tmpfile = BRA_ALLOC(128);        
  if(drm_content_type == MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_WBXML)
    sprintf(tmpfile, "Z:\\@BRA_DRM\\%lu.drc", HDIa_timeGetCurrent());
  else
    sprintf(tmpfile, "Z:\\@BRA_DRM\\%lu.dr", HDIa_timeGetCurrent());
  drm_ucs2file = (kal_wchar*)BRA_ALLOC((strlen(tmpfile)+1)*2);
  widget_utf8_to_ucs2_string((kal_uint8*)drm_ucs2file, (strlen(tmpfile)+1)*2, (kal_uint8*)tmpfile);
  BRA_FREE(tmpfile);

  drm_file_handle = FS_Open(drm_ucs2file, FS_READ_WRITE|FS_CREATE);
  if(drm_file_handle <= 0)
  {
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_DRM_RO_FORMAT, MsfError, 0);
    BRA_FREE(drm_ucs2file);
    drm_ucs2file = NULL;
    return;
  }

  if(cl->contentData->contentDataType == MSF_CONTENT_DATA_RAW)
  {
    int bytes_write, ret;
    ret = FS_Write(drm_file_handle, cl->contentData->contentData, cl->contentData->contentDataLength, (UINT*)&bytes_write);
    if(ret == FS_NO_ERROR && bytes_write == cl->contentData->contentDataLength)
      bra_proc_drm_right(TRUE);
    else
    {
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_DRM_RO_FORMAT, MsfError, 0);
      FS_Close(drm_file_handle);
      drm_file_handle = -1;
      FS_Delete(drm_ucs2file);
      BRA_FREE(drm_ucs2file);
      drm_ucs2file = NULL;
    }
  }
  else if(cl->contentData->contentDataType == MSF_CONTENT_DATA_PIPE)
  {
    int pipeHandle = MSF_PIPE_OPEN(MSF_MODID_BRA, cl->contentData->contentSource);
    if (pipeHandle < 0) 
    {
      HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_DRM_RO_FORMAT, MsfError, 0);
      MSF_PIPE_DELETE (cl->contentData->contentSource);
      FS_Close(drm_file_handle);
      drm_file_handle = -1;
      FS_Delete(drm_ucs2file);
      BRA_FREE(drm_ucs2file);
      drm_ucs2file = NULL;
    }
    else
    {
      drm_pipe_name = BRA_ALLOC(strlen(cl->contentData->contentSource) + 1);      
      strcpy(drm_pipe_name, cl->contentData->contentSource);

      if(!bra_read_drm_pipe(pipeHandle, drm_file_handle))
        bra_proc_drm_right(FALSE);
    }
  }
}

#endif /* __DRM_SUPPORT__ */

/*
 * The command line passed to BRA by the starting module is parsed by 
 * this function. It handles three different start-up modes:
 * -mode menu
 * -mode url
 * -mode homepage
 *
 * If the BRA is not fully initialized the command line is saved and when the BRS is
 * and when the BRA is activated the command line is once again passed to this  
 * function and parsed.
 *
 * This comment is part of an example to add a start mode to BRA.
 * The full example is described in the BRA Reference Manual 
 *
 * Ex: 1.2
 *
 * 2. This function needs to be modified to be able to parse out the new
 *    command line parameters: 
 *
 *    "-mode set_and_load_home title url"
 *
 * Return: Void
 */
static void
bra_main_parse_parameters(void * p)
{
	char *modeStart;
	char *paramStart = NULL;
	char *paramStop  = NULL;
	msf_module_execute_cmd_t *cl;
  char *cmd;

	cl = ((msf_module_execute_cmd_t*)p);
  
  cmd = cl->commandOptions;
  
  if (bra_module_state != BRA_INITIALIZED)
  {
    bra_main_start_cmd = p;
    return;
  }
  
  if (cmd != NULL)
  {
    modeStart = strstr(cmd, BRA_CL_MODE);
    
    if (modeStart != NULL)
    {
      paramStart = modeStart + sizeof(BRA_CL_MODE);
      paramStart = msf_cmmn_skip_blanks(paramStart);
      paramStop  = msf_cmmn_skip_field(paramStart);
    }

    if (paramStart != NULL)
    {
      if (bra_main_active == 0)
      {
        if (strcmp(paramStart,BRA_CL_MODE_HOMEPAGE) == 0)
        {
          bra_send_request((bra_cmn_get_homepage())->url);
        }
        else if ((strcmp(paramStart, BRA_CL_MODE_RESUME) == 0) && ((bra_cmn_get_current_page ())->url != NULL))
        {
          bra_send_request((bra_cmn_get_current_page ())->url);
        }
        else if (strncmp(paramStart, BRA_CL_MODE_URL, 3) == 0)
        {
          paramStart = paramStop + 1;
          paramStop  = msf_cmmn_skip_field(paramStart);
          bra_send_request(paramStart);
        }
        /* This comment is part of an example to add a start mode to BRA.
        * The full example is described in the BRA Reference Manual 
        *
        * Ex: 1.3
        *
        * 3. Add a comparison statement here to determine if next parameter is
        *    "set_and_load_home". It the parameter indicate that this is a
        *    Set and Load Home request add code to parse out "title" and "url".
        *    If all parameters were correct call the functions to set the title
        *    and url as homepage and then load the new homepage.
        *    The code for this might look like this
        *
        *    else if (strncmp(paramStart, BRA_CL_MODE_SET_AND_LOAD_HOME, 17) == 0)
        *    {
        *      url   = extract_url_parameter ( ... );
        *      title = extract_title_parameter ( ... );
        *
        *      bra_cmn_set_local_hompage_title(title);
        *      bra_cmn_set_local_hompage_url(url);
        *
        *      bra_cmn_set_homepage (title, url);
        *
        *      bra_send_request(url);
        *    }
        */
        
        else
        {
          /*In all other cases use default*/
          bra_create_int_serv_menu();
        }
      }
      else 
      {
        /*If this call is due to content routing, load url and take focus*/
        if (strcmp (cmd, "http") == 0)
        {
          bra_send_request(cmd);  
        }
        else
        {
          MSF_WIDGET_SET_IN_FOCUS (bra_win_get_screen (), 1);
        }
      }
    }

    MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, MSF_SIG_MODULE_EXECUTE_COMMAND, p);
    bra_main_start_cmd = NULL;
    
    bra_main_active = 1;
    return;
  }
  
  if (cl->contentDataExists == 1)
  {
    if ((cl->contentData->contentUrl) != NULL && (cl->contentData->contentDataType == MSF_CONTENT_DATA_NONE))
    {
      bra_send_request(cl->contentData->contentUrl);
      bra_win_close_window(BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
    }
#ifdef __DRM_SUPPORT__
    if ((cl->contentData->contentDataType == MSF_CONTENT_DATA_RAW && cl->contentData->contentData != NULL)
        || (cl->contentData->contentDataType == MSF_CONTENT_DATA_PIPE && cl->contentData->contentSource != NULL))
    {
      bra_handle_drm_right(cl);
    } 
#endif    
  }
  
  bra_main_active = 1;
  
  MSF_SIGNAL_DESTRUCT (MSF_MODID_BRA, MSF_SIG_MODULE_EXECUTE_COMMAND, p);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*
 * This is the main functin is in the BRA. It receives all internal signals and 
 * dispaches them to the correct function.
 */
static void
bra_main (bra_signal_t *sig)
{
  switch (sig->type) 
  {
  case BRA_MAIN_SIG_CONTINUE_CREATE_UI:
    bra_handle_continue_create_ui(sig->p_param);
    bra_signal_delete(sig);
    break;

  case BRA_MAIN_SIG_TERMINATE:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_MAIN_1DDB41D6E52E96C9700808DDDFDB6F3B, "BRA: received signal BRA_MAIN_SIG_TERMINATE\n"));
    bra_signal_delete (sig);
    bra_terminate();
    break;

  case BRA_MAIN_SIG_CONTINUE_TERMINATE:
    /*Delete this signal first*/
    bra_signal_delete (sig);
    bra_main_continue_terminate();
    break;

  case BRA_MAIN_SIG_STATUS:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_MAIN_649DC1C14EDA5918C9369BA195167649, "BRA: received signal BRA_MAIN_SIG_STATUS\n"));
    bra_module_status (sig);
    bra_signal_delete (sig);
    break;

  case BRA_MAIN_SIG_EXECUTE_COMMAND:
    bra_main_parse_parameters(sig->p_param);
    bra_signal_delete (sig);
    break;

  case BRA_MAIN_SIG_WIDGET_ACTION:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
      BRA_MAIN_9018FA811F0BC7431D02D85C5C74A5AE, "BRA: received signal BRA_MAIN_SIG_WIDGET_ACTION\n"));    
    bra_widget_action (sig->u_param1, sig->u_param2);
    bra_signal_delete (sig);
    break;

  case BRA_MAIN_SIG_WIDGET_NOTIFY:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
      BRA_MAIN_261EC6F73923C61BF27B66F15DBECBCE, "BRA: received signal BRA_MAIN_SIG_WIDGET_NOTIFY\n"));    
    bra_win_handle_notify ((MsfWindowHandle)sig->u_param1, (MsfNotificationType)sig->u_param2);
    bra_signal_delete (sig);
    break;
    
#ifdef __DRM_SUPPORT__
  case BRA_MAIN_SIG_PIPE_NOTIFY:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
      BRA_MAIN_D62BA5640C9BE28D1455E9ACCDF0E52C, "BRA: received signal BRA_MAIN_SIG_PIPE_NOTIFY\n"));    
    bra_read_drm_right (sig->i_param, sig->u_param1);
    bra_signal_delete (sig);
    break;
#endif	
    
  case BRA_MAIN_SIG_FILE_NOTIFY:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, 
      BRA_MAIN_3A9851D5C4F7010F1EE1B2330DEAF0F0, "BRA: received signal BRA_MAIN_SIG_FILE_NOTIFY\n"));    
    bra_file_execute_file_task ();
    bra_signal_delete (sig);
    break;

  case BRA_MAIN_SIG_BRS_CREATE_RESPONSE:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_4513780B808DC8130AD5BC09F7E39D30, "BRA: received signal BRA_MAIN_SIG_BRS_CREATE_RESPONSE\n"));
    bra_sif_brs_create_responce (sig->p_param);
    bra_signal_delete (sig);
    break;

  case BRA_MAIN_SIG_CONT_FILE_TASK:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_21C1816C2EBC9C2428FEA68BF8E84E2D, "BRA: received signal BRA_MAIN_SIG_CONT_FILE_TASK\n"));
    bra_file_execute_file_task ();
    bra_signal_delete (sig);
    break;

#ifdef BRA_CONFIG_UIS_PUSH_SL
  case BRA_MAIN_SIG_PSL_NEW_MSG:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_A845BE826A5D752ECAA664AC3D297955, "BRA: received signal BRA_MAIN_SIG_PSL_NEW_MSG\n"));
    bra_psl_new_sl_msg_notification (sig->p_param);
    bra_signal_delete (sig);
    break;

  case BRA_MAIN_SIG_REPLY_MSG:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_2798B6D965E180A673DE26481E6B4E84, "BRA: received signal BRA_MAIN_SIG_REPLY_MSG\n"));
    bra_psl_msg_reply (sig->p_param);
    bra_signal_delete (sig);
    break;
    
#endif
    
#ifdef BRA_CONFIG_PROVISIONING
  case BRA_MAIN_SIG_PRS_CONTINUE:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_EB76CBC2720A3F16E138317CEC0F095D, "BRA: received signal BRA_MAIN_SIG_PRS_CONTINUE\n"));
    bra_prs_continue (sig->p_param);
    bra_signal_delete (sig);
    break;
#endif
    
#ifdef BRA_CFG_CCA
    
  case BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_C1583B2E9827C023B920E284E8F61E9C, "BRA: BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE\n"));
    bra_cca_handle_profile_install_continue();
    bra_signal_delete (sig);
    break;
    
#endif /*BRA_CFG_CCA*/
    
    
    
    /************************************************************
    * Internal signals of package notification: Q03C1
    ************************************************************/
  case BRA_MAIN_SIG_ACT_FINISHED:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,
      BRA_MAIN_446E3E603745EA25A6F60FB26B11ADB1, "BRA: received signal BRA_MAIN_SIG_ACT_FINISHED\n"));
    bra_act_finished (sig->i_param);
    bra_signal_delete (sig);
    break;

  default:
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_MAIN_EE60CB289F5A998C0E90E703FB64A0AC, "BRA: received unknown signal: %d\n", sig->type));
    bra_signal_delete (sig);
  }
}

static void
bra_exception_handler (void)
{
  /*If inside the bra_run function make longjmp, else do nothing, which will result in that the 
    memory allocation macro return NULL;*/
  if (bra_inside_run)
    longjmp (bra_jmpbuf,1);
}

/******************************************************************************
 * Exported Functions
 *****************************************************************************/

/*
 *  Function sets the state of BRA to stat. This function is
 *  used during startup and termination. The state is typically
 *  used when reading the registry. This is a delayed operation 
 *  and therfore we need to remember the state so the initialization
 *  routine is aware that it can't return MODULE_ACTIVE.
 *
 *  Return: Void
 */
void 
bra_main_set_module_state(MSF_UINT32 state)
{
  bra_module_state |= state;
}

/*
 *  Function removes the previously set state of BRA to stat. 
 *  used during startup and termination. 
 *
 *  Return: Void
 */
void 
bra_main_remove_module_state(MSF_UINT32 state)
{
  MSF_UINT32 mask = 0xFFFFFFFF;

  mask ^= state;
  bra_module_state &= mask;

}


/*
 * This function is called when the deleayed registry read operation 
 * returns. The function parses all keys in the responce.
 *
 * PARAMETERS
 *
 * response  : The response structure from Registry (msf_registry_response_t)
 *
 * RETURN    : void
 */
void
bra_main_reg_responce(void *response)
{
  msf_registry_param_t p;
  msf_registry_response_t* resp_hdl = (msf_registry_response_t*)response;

  while (MSF_REGISTRY_RESPONSE_GET_NEXT (resp_hdl, &p))
  {
    if (strcmp(p.key, BRA_INSE_REG_KEY_CURRENT_TITLE) == 0)
    {
        bra_cmn_set_current_page ((char*)p.value_bv, 0, BRA_INSE_SET_CURRENT_TITLE );
    }
    else if (strcmp(p.key, BRA_INSE_REG_KEY_CURRENT_URL) == 0)
    {
        bra_cmn_set_current_page (0, (char*)p.value_bv, BRA_INSE_SET_CURRENT_URL);
    }    
#ifdef BRA_CFG_PROF_FALLBACK
    else if (strcmp(p.key, BRA_PROF_KEY_NET_ID) == 0 && 
             strcmp(p.path, "/BRS/BRA") == 0 && 
             bra_sif_get_brs_status () != BRA_SIF_BRS_NOT_ACTIVE)
    {
        bra_sif_fallback_continue((int)p.value_i);
    }
#endif
  }

  msf_registry_response_free (MSF_MODID_BRA, resp_hdl);

  bra_main_remove_module_state(BRA_READING_REGISTRY);
    
  bra_init_done ();
}

/*
 * This function is called to try if BRA has finished the initialization process.
 * If the module is finished it starts parsing the command line if available.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_init_done (void)
{
  if (bra_module_state == BRA_NULL_STATE){
    /* tells MSF that the module is active. If the module will use other */
    /* modules, this call must wait until these are up and running. */
    MSF_MODULE_IS_ACTIVE (MSF_MODID_BRA);
    
    bra_main_set_module_state(BRA_INITIALIZED);

    if (bra_main_start_cmd != NULL)
    {
      bra_main_parse_parameters(bra_main_start_cmd);
    }

/* double check if new wap_sim_info primtives are sent to wap task while BRA is initializing */
#ifdef BRA_CFG_DUAL_SIM
    BRAif_handleSimInfoNotify((MSF_UINT8)wap_get_sim_status(),
        (MSF_UINT8)wap_get_sim_setting_mode());
#endif /* BRA_CFG_DUAL_SIM */

    MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_LOW, MSF_MODID_BRA, BRA_MAIN_D5FF0C4882AA47F0A4C523BD38D34EF8, "BRA: Initialization is done!\n"));
  }
}

/*
 * This function initializes the Browser Reference Application module
 * and allocates all neccessary resources. It reads bookmarks and profiles.
 * It also issues a request to read the registry.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_init (void)
{
  /*Initialize global variables*/
  bra_inside_run = 0;
  bra_module_state   = BRA_NULL_STATE;
  bra_main_terminate = 0;
  bra_main_start_cmd = NULL;
  bra_main_active    = 0;
  bra_browser_entry_from_menu = 0;

  bra_main_set_module_state (BRA_INITIALIZING);

	MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_LOW, MSF_MODID_BRA, BRA_MAIN_21F2F55A230061CCF53D08FADDC53290, "BRA: Initialization Starts!\n"));

  /*Initialize memory management*/
  MSF_MEM_INIT (MSF_MODID_BRA, bra_exception_handler);

  bra_act_init (); //Q03C1

  /* Register the module convention functions. (These are not used 
   * since the BRA have no external API but are included as a development 
   * reference for integrators)
   */
  MSF_SIGNAL_REG_FUNCTIONS (MSF_MODID_BRA, bra_convert, bra_destruct);

  /*Register external signal queue*/
  MSF_SIGNAL_REGISTER_QUEUE (MSF_MODID_BRA);

  /*Notify MSF that the module is created. Note! The module is created but not active*/
  MSF_MODULE_IS_CREATED (MSF_MODID_BRA, BRA_VERSION);

  /**/
  bra_signal_init ();
	/* register the destination for the signals sent to this module */
  bra_signal_register_dst (W_SIG_DST_BRA_MAIN, bra_main);

  /*Make sure that the BRA file directory exist*/
  MSF_FILE_MKDIR ("/bra");

  bra_file_start();
  
  bra_req_init_request_url();

  //bra_req_init_address_list();
  
  bra_rpl_init();

  bra_opt_init ();
#ifdef BRA_CONFIG_PROVISIONING
  bra_prs_init ();
#endif

  bra_widget_create_screen ();

  /*Initialize navigation variables e.g. current page and home*/
  bra_cmn_init_navigation_items ("", "", BRA_CFG_DEFAULT_HOMPAGE_TITLE, BRA_CFG_DEFAULT_HOMPAGE_URL);

  bra_main_content_register ();
    
  MSF_REGISTRY_GET(MSF_MODID_BRA, 1, "/BRA", NULL);

  bra_main_set_module_state(BRA_READING_REGISTRY);

  bra_sif_init();

  bra_sif_set_brs_status (BRA_SIF_BRS_NOT_ACTIVE);
  
#ifdef BRA_CONFIG_SECURITY
  bra_sif_set_security_class (0, 0, 0);
#endif


  bra_cbm_init();  /* should do this before profile initialized */

  
#ifdef BRA_CFG_DUAL_SIM
  bra_sim_init(); /* should do this before profile initialized */
#endif

  bra_prof_initialize();

#ifdef BRA_CONFIG_UIS_PUSH_SL
  bra_psl_init();
#endif

  bra_main_remove_module_state(BRA_INITIALIZING);


#ifdef BRA_CFG_CCA
  bra_cca_init();
#endif
  


   /* init BRA profile */
   /*
   #ifdef __J2ME__
   {
     extern void JASif_initChannel(void);      
     JASif_initChannel();
   }
   #endif  
   */

#ifdef __DRM_SUPPORT__
  FS_CreateDir(L"Z:\\@BRA_DRM\\");
#endif

  bra_init_done ();

}

static void
bra_handle_brs_terminated (MsfActionType response)
{
  if (bra_browser_entry_from_menu)
  {
#ifdef BRA_CFG_DUAL_SIM
    BRAif_createUI(BRA_UI_MAIN_MENU, NULL);
#else
    bra_view_create_view();
    bra_create_int_serv_menu();
#endif
  }
}

static void bra_set_registry(char *path, char *key, const int ival, const char *sval)
{
  void *reg_handle;

  reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_BRA);
  MSF_REGISTRY_SET_PATH (reg_handle, path);

  if(sval == NULL)
    MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, key, ival);    
  else
    MSF_REGISTRY_SET_ADD_KEY_STR (reg_handle, 
                                  key, 
                                  (unsigned char*)BRA_CMN_HNV(sval) , 
                                  (MSF_UINT16)(strlen (BRA_CMN_HNV (sval))+1));

  MSF_REGISTRY_SET_COMMIT (reg_handle);
}

void
bra_goto_url (char *url)
{
  if(bra_win_get_window(BRA_WIN_ID_VIEWPORT) != NULL)	
  {
    if(!check_url(url) || !bra_cmn_url_is_valid(url))
     HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_INVALID_URL, MsfError, 0);
    else
    {
      /* WAP screen already exists */  	
      bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);
      bra_send_request(url);
    }
    BRA_FREE(url);
    return;
  }    
  
  /* check if enough space for cache */
  if(msm_get_disk_free_space(WAP_STORAGE_SYSTEM) < BRA_CFG_MAX_CACHE_SIZE)
    bra_set_registry("/BRS/BRA", BRS_REGISTRY_KEY_CACHE_ON, 0, NULL);
  else
    bra_set_registry("/BRS/BRA", BRS_REGISTRY_KEY_CACHE_ON, 1, NULL);    

  /* hold display */
  bra_win_disable_focus();

  /* should commit profile here if select another SIM different the one
   * which the profile loaded belongs to in ask mode */
  bra_prof_restore_bra_active_profile(TRUE);
  
  if(!check_url(url) || !bra_cmn_url_is_valid(url))
  {
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_INVALID_URL, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);
    /* resume display */
    bra_win_enable_focus();
  }
  else
  {
    bra_view_create_view();
    /* resume display show do this before send request,
       because bra_destroy_ui may be called int bra_send_request
       we can not set widget focus after the widget screen is destroyed.
    */
    bra_win_enable_focus();
    bra_send_request(url);
  }

  BRA_FREE(url);
}

void
bra_add_bookmark (char *url)
{
  MSF_WIDGET_SET_IN_FOCUS(bra_win_get_screen(), 1);
  bra_bkm_create_offline_add_bookmark_form(url);
}


void
bra_handle_create_ui(void *p)
{
#ifdef BRA_CFG_DUAL_SIM
  bra_sim_create_ui(p);
#else
  BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_CREATE_UI, p);
#endif
}


void
bra_handle_destroy_ui(void)
{
  bra_destroy_ui();
}


void
bra_handle_continue_create_ui(void  *p)
{
  bra_cbm_create_ui();

#ifdef BRA_CFG_OFFLINE_PAGES
  bra_ofln_reset_offline_state();
#endif
  if(((bra_create_ui_t*)p)->type == BRA_UI_GOTO_URL)
  {
    bra_browser_entry_from_menu = 0;
    bra_sif_init();
    bra_goto_url(((bra_create_ui_t*)p)->url);
  }
  else if(((bra_create_ui_t*)p)->type == BRA_UI_ADD_BOOKMARK)
  {
#ifdef BRA_CFG_DUAL_SIM
    bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
#endif
    bra_add_bookmark(((bra_create_ui_t*)p)->url);
  }
  else
  {
    bra_create_ui(((bra_create_ui_t*)p)->type);
  }
  BRA_FREE(p);

#ifdef BRA_CFG_DUAL_SIM  
  if (bra_win_get_window(BRA_WIN_ID_EDIT_SIM_MENU))
      bra_win_close_window(BRA_WIN_CLOSE_ID, BRA_WIN_ID_EDIT_SIM_MENU);
#endif /* BRA_CFG_DUAL_SIM */
}


void
bra_create_ui (MSF_UINT8 p)
{
  
  MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_CREATE_UI, "BRA: bra_create_ui(): typ=%d", p));

  /* check if enough space for cache */
  if(msm_get_disk_free_space(WAP_STORAGE_SYSTEM) < BRA_CFG_MAX_CACHE_SIZE)
    bra_set_registry("/BRS/BRA", BRS_REGISTRY_KEY_CACHE_ON, 0, NULL);
  else
    bra_set_registry("/BRS/BRA", BRS_REGISTRY_KEY_CACHE_ON, 1, NULL);    

  /* hold display */
  bra_win_disable_focus();

  bra_sif_init();

  bra_prof_restore_bra_active_profile(TRUE);
  
  if(p == BRA_UI_PROF_MENU)
  {
    /* create profile menu */
    bra_prof_create_profile_menu(BRA_PROF_ID_MMS);
  }
  else if(p == BRA_UI_RESET_COMPL)
  {
    /* warning dialog */
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_INTERNAL_ERROR, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        NULL);    
  }
  else if(p == BRA_UI_MEM_FULL)
  {
    /* warning dialog */
    bra_dlg_create_dlg (MsfError,
                        BRA_STR_OUT_OF_MEMORY, 
                        BRA_STR_OK, 
                        0,
                        0, 
                        bra_handle_brs_terminated);    
  }
  else
  {
    switch(p)
    {
     case BRA_UI_MAIN_MENU:
       /* create view and main menu */
       bra_browser_entry_from_menu = 1;
       bra_view_create_view();
       bra_create_int_serv_menu();
       break;
     case BRA_UI_VIEWPORT:
       /* create view for push */
       bra_view_create_view();
       break;
     case BRA_UI_HOMEPAGE:
		  /* create view and then go to homepage */       
		  if(!check_url((bra_cmn_get_homepage())->url) || !bra_cmn_url_is_valid((bra_cmn_get_homepage())->url)) 
		  {
			  bra_dlg_create_dlg (MsfError,
				  BRA_STR_INVALID_URL, 
				  BRA_STR_OK, 
				  0,
				  0, 
				  NULL);
			  break;
		  }
		  else /*	Validate gateway IP before bra_view_create_view() to avoid dangling view */
		  {
			  int conn_type = bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_CON_TYPE);
			  if(conn_type == BRA_SET_CONNECTION_TYPE_WSP_CL || conn_type == BRA_SET_CONNECTION_TYPE_WSP_CO)
			  {
				  char *s = bra_prof_get_key_str_value (BRA_PROF_ID_BRA, "prx_addr");  
				  if (s == NULL || strlen((const char*)s) == 0 || !check_ip(s))
				  {
					  bra_dlg_create_dlg (MsfError,
						  BRA_STR_INVALID_GATEWAY_IP, 
						  BRA_STR_OK, 
						  0,
						  0, 
						  NULL);

					  break;
				  }    
			  }
		  }
      bra_browser_entry_from_menu = 0;
      bra_view_create_view();
      /* resume display */
      bra_win_enable_focus();
      bra_send_request((bra_cmn_get_homepage())->url);
      break;
     default:
       return;
     }
   }

   /* resume display */
  if (p != BRA_UI_HOMEPAGE)
    bra_win_enable_focus();

   bra_cbm_create_ui();
}

void
bra_destroy_ui(void)
{
  int instal_prov;


  MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_MAIN_302130BCB192CB32EFDD4FEBA50238EA, "BRA: bra_destroy_ui():\n"));

  bra_cbm_destroy_ui();
    
#ifdef BRA_CFG_DUAL_SIM
  bra_sim_destroy_ui(); /* please call this earlier, because WTAI may need send response before BRS instance is deleted */
#endif

  if (bra_get_da_download_active_job_count() > 0)
  {
    bra_da_wap_notify_browser_closed();
  }
  
  instal_prov = bra_prs_if_instal_dialog_exist();
  
  msf_dlg_destroy_act_dlg_op();
  msm_dlg_destroy_act_dlg(); 
  bra_cmn_set_current_page ("", "", BRA_INSE_SET_CURRENT_TITLE | BRA_INSE_SET_CURRENT_URL);

  if (bra_sif_get_brs_status () != BRA_SIF_BRS_NOT_ACTIVE)
  {
    if(MSF_moduleIsRunning(MSF_MODID_BRS))
    {
#ifdef BRA_CFG_USE_SPLASH
      bra_view_reset_splash_timer();
#endif
      BRSif_deleteInstance (MSF_MODID_BRA, bra_sif_get_brs_id ());
      MSF_MODULE_TERMINATE(MSF_MODID_BRA, MSF_MODID_BRS);
    }
#ifdef __SAT__
    bra_send_termination_to_mmi(BRA_SAT_USER_TERMINATION);
#endif
  }

  HDIa_releaseBearer(MSF_MODID_BRA, BRAif_getNetAccId());
    
#ifdef BRA_CFG_PROF_FALLBACK
    if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_DUAL)) {
      MSF_LOG_MSG_NOARG((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA, BRA_MAIN_68947FDE54D44E72CEAB424A08719985, "BRA: bra_destroy_ui: reset dual net-id to GPRS\n"));

      // release GPRS bearer if dual_id mode and currently using CSD connection..
      //if (bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID) == bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GSM))
      HDIa_releaseBearer(MSF_MODID_BRA, bra_prof_get_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS));

      bra_prof_change_key_int_value(
            BRA_PROF_ID_BRA,
            BRA_PROF_KEY_NET_ID,
            bra_prof_get_key_int_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_GPRS),
            NULL);
    }
#endif
  bra_win_close_window (BRA_WIN_CLOSE_TO_ID_FORCE, BRA_WIN_ID_VIEWPORT);
  bra_win_close_window (BRA_WIN_CLOSE_ID, BRA_WIN_ID_VIEWPORT);  
  if(instal_prov)
    bra_prs_handle_destroy_ui();

#ifdef BRA_CFG_CCA 
  bra_cca_handle_key_end_event();
#endif
}

void
bra_show_auth_dialog(void *p)
{
  bra_show_auth_dlg_t *auth_dlg_p = (bra_show_auth_dlg_t*)p;

  bra_view_reset_request_timer();
#ifdef BRA_CFG_USE_SPLASH
  bra_view_reset_splash_timer();
#endif

  bra_dlg_create_auth_form(auth_dlg_p->module, auth_dlg_p->requestId, auth_dlg_p->authType,
    auth_dlg_p->realm, auth_dlg_p->username, auth_dlg_p->warnings);

  BRA_FREE(auth_dlg_p->realm);
  BRA_FREE(auth_dlg_p->username);

  /* set focus to avoid java screen cover */
  MSF_WIDGET_SET_IN_FOCUS (bra_win_get_screen (), 1);  
}

void
bra_show_dialog(void *p)
{
  bra_show_dlg_t *dlg_p;

  dlg_p = (bra_show_dlg_t*)p;

  bra_dlg_create_dlg ((MsfDialogType)(dlg_p->dlg_type),
                      dlg_p->ms, 
                      BRA_STR_OK, 
                      0,
                      0, 
                      NULL);   

  MSF_WIDGET_RELEASE(dlg_p->ms);
}

void
bra_show_dialog_ext(void *p)
{
  bra_show_dlg_ext_t *dlg_p;

  dlg_p = (bra_show_dlg_ext_t*)p;

  bra_dlg_create_dlg ((MsfDialogType)(dlg_p->dlg_type),
                      dlg_p->ms, 
                      BRA_STR_OK, 
                      0,
                      0, 
                      (bra_action_handle_t)(dlg_p->callback));

  MSF_WIDGET_RELEASE(dlg_p->ms);
}

extern void 
wtai_telMakeCall (MSF_UINT8 modId, MSF_UINT16 telId, const char* number);
extern void 
wtai_telSendDtmf (MSF_UINT8 modId, MSF_UINT16 telId, const char* dtmf);
extern void 
wtai_pbAddEntry (MSF_UINT8 modId, MSF_UINT16 pbId, const char* name, const char* number);

static MSF_UINT8 wtai_modId;
static MSF_UINT16 wtai_id;
static char *wtai_number = NULL;
static char *wtai_name = NULL;

static void
bra_make_call_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    wtai_telMakeCall(wtai_modId, wtai_id, (const char*)wtai_number);
  }
  else
  {
    HDIc_telMakeCallResponse(wtai_modId, wtai_id, HDI_TEL_ERROR_UNSPECIFIED);
  }
  BRA_FREE(wtai_number);
  wtai_number = NULL;
}

void 
bra_make_call(void *p)
{
  MsfStringHandle ms;
  bra_wtai_make_call_t *wtai_p = (bra_wtai_make_call_t*)p;
  char *s, *t;
  MSF_UINT8 l;
  char      *mark;
  MSF_UINT8  mark_len;
  
  wtai_modId = wtai_p->modId;
  wtai_id = wtai_p->telId;
  if(strlen(wtai_p->number) >= 40)
    wtai_p->number[40] = '\0';
  wtai_number = BRA_ALLOC(strlen(wtai_p->number)+1);
  strcpy(wtai_number, wtai_p->number);

  l = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_DIAL, 1, MsfUtf8);
  t = BRA_ALLOC(l + 1);
  MSF_WIDGET_STRING_GET_DATA (BRA_STR_DIAL, t, MsfUtf8);

  mark_len = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_QUESTION_MARK, 1, MsfUtf8);
  mark = BRA_ALLOC(mark_len + 1);
  MSF_WIDGET_STRING_GET_DATA (BRA_STR_QUESTION_MARK, mark, MsfUtf8);

  s = BRA_ALLOC (l + 1 + strlen(wtai_number) + 1 + 1 + strlen(mark));  
  sprintf(s, "%s %s %s",t, wtai_number, mark);

  if(strlen(s) > 28)
  {
    s[25] = '.';
    s[26] = '.';
    s[27] = '.';
    s[28] = '\0';
  }
  
  ms = BRA_STRCONV(s);
  bra_win_disable_focus();  //Jo make call

  bra_dlg_create_dlg (MsfConfirmation,
                      ms, 
                      BRA_STR_OK, 
                      BRA_STR_CANCEL,
                      0, 
                      bra_make_call_confirmation);    
  bra_win_enable_focus();  //Jo make call

  /* BRS do not send the END_TRANSACTION to BRA until BRS receive the response,
     so here do not need to set the request timer */
  bra_view_reset_request_timer();

  MSF_WIDGET_RELEASE(ms);
  BRA_FREE(wtai_p->number);
  BRA_FREE(s);
  BRA_FREE(t);
  BRA_FREE(mark);
}

static void
bra_send_dtmf_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    wtai_telSendDtmf(wtai_modId, wtai_id, (const char*)wtai_number);
  }
  else
  {
    HDIc_telSendDtmfResponse(wtai_modId, wtai_id, HDI_TEL_ERROR_UNSPECIFIED);
  }
  BRA_FREE(wtai_number);
  wtai_number = NULL;
}

void 
bra_send_dtmf(void *p)
{
  MsfStringHandle ms;
  bra_wtai_send_dtmf_t *wtai_p = (bra_wtai_send_dtmf_t*)p;
  char *s, *t;
  MSF_UINT8 l;
  MSF_UINT8 mark_len;
  char      *mark;
  

  wtai_modId = wtai_p->modId;
  wtai_id = wtai_p->telId;
  if(strlen(wtai_p->dtmf) >= 40)
    wtai_p->dtmf[40] = '\0';
  wtai_number = BRA_ALLOC(strlen(wtai_p->dtmf)+1);
  strcpy(wtai_number, wtai_p->dtmf);

  l = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_SEND_DTMF, 1, MsfUtf8);
  t = BRA_ALLOC(l + 1);
  MSF_WIDGET_STRING_GET_DATA (BRA_STR_SEND_DTMF, t, MsfUtf8);

  mark_len = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_QUESTION_MARK, 1, MsfUtf8);
  mark = BRA_ALLOC(mark_len + 1);
  MSF_WIDGET_STRING_GET_DATA (BRA_STR_QUESTION_MARK, mark, MsfUtf8);

  s = BRA_ALLOC(l + 1 + strlen(wtai_number) + 1 + 1 + strlen(mark));
  sprintf(s, "%s %s %s", t, wtai_number, mark);

  if(strlen(s) > 28)
  {
    s[25] = '.';
    s[26] = '.';
    s[27] = '.';
    s[28] = '\0';
  }
  
  ms = BRA_STRCONV(s);

  bra_dlg_create_dlg (MsfConfirmation,
                      ms, 
                      BRA_STR_OK, 
                      BRA_STR_CANCEL,
                      0, 
                      bra_send_dtmf_confirmation);    
  
  /* BRS do not send the END_TRANSACTION to BRA until BRS receive the response,
     so here do not need to set the request timer */
  bra_view_reset_request_timer();

  MSF_WIDGET_RELEASE(ms);
  BRA_FREE(wtai_p->dtmf);
  BRA_FREE(s);
  BRA_FREE(t);
  BRA_FREE(mark);
}

static void
bra_pb_add_entry_confirmation(MsfActionType response)
{
  if(response == MsfOk)
  {
    wtai_pbAddEntry(wtai_modId, wtai_id, (const char*)wtai_name, (const char*)wtai_number);
  }
  else
  {
    HDIc_pbAddEntryResponse(wtai_modId, wtai_id, HDI_TEL_ERROR_UNSPECIFIED);
  }
  BRA_FREE(wtai_name);
  wtai_name = NULL;
  BRA_FREE(wtai_number);
  wtai_number = NULL;
}



char*
bra_pb_get_phone_number(const char* number)
{
  int      len;
  int      max_char;
  char     *real_num;
  
  
  if (number == NULL || 0 == (len = strlen(number)))
  {
    real_num = BRA_ALLOC(1);
    real_num[0] = '\0';
  }
  else
  {
    if (number[0] == BRAa_PHONEBOOK_NUM_PREFIX_CHAR)
      max_char = BRA_PHONEBOOK_NUM_MAX_CHAR + 1;
    else
      max_char = BRA_PHONEBOOK_NUM_MAX_CHAR;
    if (max_char > len)
      max_char = len;
    real_num = BRA_ALLOC(max_char + 1);
    strncpy(real_num, number, max_char);
    real_num[max_char] = '\0';
  }
  return real_num;
}

char*
bra_pb_get_phone_name(const char* name)
{
  int    len;
  int    index;
  int    max_len;
  char   *real_name;
  
  if (name == NULL)
  {
    real_name = BRA_ALLOC(1);
    real_name[0] = '\0';
    return real_name;
  }
  
  len = widget_utf8_length((const kal_uint8 *)name);
  if (len <= BRA_PHONEBOOK_NAME_UTF8_MAX_CHAR)
  {
    max_len = len;
  }
  else
  {
    if (len >= BRA_PHONEBOOK_NAME_ASCII_MAX_CHAR)
      len = BRA_PHONEBOOK_NAME_ASCII_MAX_CHAR;
    for (index = 0; index < len; index++)
    {
      if (!BRA_IS_ASCII(name[index]))
        break;
    }
    if (index == len) /* not find UTF8 char*/
      max_len = len;
    else
      max_len = BRA_PHONEBOOK_NAME_UTF8_MAX_CHAR;
  }
  real_name = bra_cmn_trunc_utf8_str((char*)name, max_len);
  return real_name;
}

void 
bra_pb_add_entry(void *p)
{
  MsfStringHandle ms;
  bra_wtai_pb_add_entry_t *wtai_p = (bra_wtai_pb_add_entry_t*)p;
  char *s, *t;
  MSF_UINT8 l;
  MSF_UINT8 mark_len;
  char*     mark;


  wtai_modId = wtai_p->modId;
  wtai_id = wtai_p->pbId;

  wtai_number = bra_pb_get_phone_number((const char*)wtai_p->number);
  wtai_name = bra_pb_get_phone_name((const char*)wtai_p->name);
  
  l = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_ADD, 1, MsfUtf8);
  t = BRA_ALLOC(l + 1);
  MSF_WIDGET_STRING_GET_DATA (BRA_STR_ADD, t, MsfUtf8);

  mark_len = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_QUESTION_MARK, 1, MsfUtf8);
  mark = BRA_ALLOC(mark_len + 1);
  MSF_WIDGET_STRING_GET_DATA (BRA_STR_QUESTION_MARK, mark, MsfUtf8);

  
  s = BRA_ALLOC(l + 1 + strlen(wtai_name) + 1 + strlen(wtai_number) + 1 + 1 + strlen(mark));
  sprintf(s, "%s %s %s %s", t, wtai_name, wtai_number, mark);
  
  ms = BRA_STRCONV(s);

  bra_dlg_create_dlg (MsfConfirmation,
                      ms, 
                      BRA_STR_OK, 
                      BRA_STR_CANCEL,
                      0, 
                      bra_pb_add_entry_confirmation);    

  /* BRS do not send the END_TRANSACTION to BRA until BRS receive the response,
     so here do not need to set the request timer */
  bra_view_reset_request_timer();

  MSF_WIDGET_RELEASE(ms);
  BRA_FREE(wtai_p->name);
  BRA_FREE(wtai_p->number);
  BRA_FREE(s);
  BRA_FREE(t);
  BRA_FREE(mark);
}


static char *extscheme_data = 0;
static MSF_UINT8 extscheme_schType;
static MSF_UINT16 extscheme_id;

static void
bra_send_sms(char* number)
{
  extern void wap_enter_sms_editor_handler(void *p);
  wap_message_editor_t *smsdata;


  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_MAIN_0D7C90F5C3B91CDDBAA3CE3D7B8C7614, "BRA: bra_send_sms(%s)\n", number));

  smsdata = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, wap_message_editor_t);
  memset((S8*)smsdata, 0, sizeof(wap_message_editor_t));
  smsdata->addr = msf_cmmn_strdup(MSF_MODID_WIDGET, number);

  widget_execute_MMI_p(wap_enter_sms_editor_handler, (void*)smsdata, FALSE);
}

static void
bra_send_ege(char* param)
{
	MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_MAIN_391954D0CCFA16D7C5B7890BE9CD89CB, "BRA: bra_send_ege(%s)\n", param));

#ifdef __SUPPORT_INFUSIO__
	mmi_java_start_infusio_eureka_client(param);
#endif /* __SUPPORT_INFUSIO__ */

}

static void
bra_send_rtsp(char* tgturl)
{
  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_MAIN_5D5B141E27623C12ADE517849DB377D9, "BRA: bra_send_rtsp(%s)\n", tgturl));

#ifdef __MMI_VIDEO_STREAM__
  mmi_vdoply_send_rtsp_url_req(tgturl);
#endif
}

static void
bra_send_mms(char* number)
{
#ifdef MMS_SUPPORT
  MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRA, BRA_MAIN_231CB188C5C145935333FECC088565DD, "BRA: bra_send_mms(%s)\n", number));
#ifdef __UNIFIED_COMPOSER_SUPPORT__
  {
    wap_message_editor_t *mmsdata;

    mmsdata = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, wap_message_editor_t);
    memset((S8*)mmsdata, 0, sizeof(wap_message_editor_t));
    mmsdata->addr = msf_cmmn_strdup(MSF_MODID_WIDGET, number);

    //mms_address_insert_hdlr(ucs2number);
    widget_execute_MMI_p(wap_enter_mms_editor_handler, (void*)mmsdata, FALSE);
  }
#else
  {
    char *meaNewCmd;
    extern void MSMc_startModule (MSF_UINT8 modId, char* startOptions);

    meaNewCmd = msf_cmmn_strcat(MSF_MODID_BRA, "-mode new -to ", (const char*)number);
    MSMc_startModule(MSF_MODID_MEA, meaNewCmd);

    MSF_MEM_FREE(MSF_MODID_BRA, meaNewCmd);
  }
#endif  /* __UNIFIED_COMPOSER_SUPPORT__ */
#endif  /* MMS_SUPPORT */
}

static void
bra_extscheme_conf_resp (MsfActionType response)
{
  if (response == MsfOk)
  {  
    switch(extscheme_schType)
    {
      case BRA_SCHEME_SMS:
        bra_send_sms(extscheme_data);
        break;
      case BRA_SCHEME_EGE:
        bra_destroy_ui();
        bra_send_ege(extscheme_data);
        break;
      case BRA_SCHEME_RTSP:
        // bra_destroy_ui();
        bra_send_rtsp(extscheme_data);
        break;
   	  case BRA_SCHEME_MMS:
        bra_destroy_ui();
        bra_send_mms(extscheme_data);
        break;
    }
  }
  else
  {
    if (bra_view_if_has_viewable_page()) {
      bra_view_enable();
    } else if (bra_win_non_viewport_win_exists()) {
      /* put paintbox to the back */
      //bra_view_set_paintbox_in_focus(1);
      bra_view_disable();
    } else
      bra_destroy_ui();
  }
  
  BRA_FREE(extscheme_data);
  extscheme_data = 0;
}

void
bra_handle_extscheme(void *p)
{
  bra_handle_extscheme_t *param = (bra_handle_extscheme_t*)p;
  MsfStringHandle ms;

  extscheme_schType = param->schType;
  extscheme_id = param->id;
  if (extscheme_data)
    BRA_FREE(extscheme_data);
  extscheme_data = msf_cmmn_strdup(MSF_MODID_BRA, (const char*)param->data);
  BRA_FREE(param->data);

  switch (param->schType)
  {
    case BRA_SCHEME_SMS:
	{ 
	  MSF_UINT8 l = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_LOAD_SCHEME_SMS_CONF, 1, MsfUtf8);	/* include zero-terminate */
	  MSF_UINT8 datalen = strlen(extscheme_data);
      char *s = BRA_ALLOC (l + datalen + 1); /* zero-terminate char included in "l", additional 1 char for '?' */
      
	  MSF_WIDGET_STRING_GET_DATA (BRA_STR_LOAD_SCHEME_SMS_CONF, s, MsfUtf8);
      memcpy(s+(l-1), extscheme_data, datalen);
	  s[l+datalen-1] = '?';
	  s[l+datalen] = 0;

	  ms = MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, s, MsfUtf8, l+datalen, 0);
	  BRA_FREE(s);
	}
      break;
    case BRA_SCHEME_EGE:
      ms = BRA_STR_LOAD_SCHEME_EGE_CONF;
      break;
    case BRA_SCHEME_RTSP:
      ms = BRA_STR_LOAD_SCHEME_RTSP_CONF;
      break;
   	case BRA_SCHEME_MMS:
	{ 
	  MSF_UINT8 l = MSF_WIDGET_STRING_GET_LENGTH(BRA_STR_LOAD_SCHEME_MMS_CONF, 1, MsfUtf8);	/* include zero-terminate */
	  MSF_UINT8 datalen = strlen(extscheme_data);
      char *s = BRA_ALLOC (l + datalen + 1); /* zero-terminate char included in "l", additional 1 char for '?' */
      
	  MSF_WIDGET_STRING_GET_DATA (BRA_STR_LOAD_SCHEME_MMS_CONF, s, MsfUtf8);
      memcpy(s+(l-1), extscheme_data, datalen);
	  s[l+datalen-1] = '?';
	  s[l+datalen] = 0;

	  ms = MSF_WIDGET_STRING_CREATE(MSF_MODID_BRA, s, MsfUtf8, l+datalen, 0);
	  BRA_FREE(s);
	}
      break;
    default:
      //brs_plh_handle_response_signal(extscheme_id, 0, HDI_TEL_ERROR_UNSPECIFIED);
      BRA_FREE(extscheme_data);
      extscheme_data = 0;
      return;
  }

  bra_dlg_create_dlg (MsfConfirmation,
                      ms, 
                      BRA_STR_YES, 
                      BRA_STR_NO,
                      0, 
                      bra_extscheme_conf_resp);

  /* BRS do not send the END_TRANSACTION to BRA until BRS receive the response,
     so here do not need to set the request timer */
  bra_view_reset_request_timer();

}

int
bra_check_dialog_is_extscheme(void)
{
  return (bra_dlg_get_dialog_callback()==bra_extscheme_conf_resp);
}

#ifdef __SAT__

void 
bra_sat_lauch_request(void *p)
{
  bra_sat_lauch_request_t *lauch_p = (bra_sat_lauch_request_t*)p;
  char *url = NULL, *gateway = NULL;
  MSF_UINT8 res;
  MSF_INT32 nw_acc_id = -1;
  int i;


  if(bra_view_is_busy())
  {    
    res = BRA_SAT_BRWOSER_BUSY;
    goto lauch_err;
  }

#ifdef BRA_CFG_PROF_FALLBACK
  if(bra_sif_is_pending_bearer_switch())
  {    
    res = BRA_SAT_BRWOSER_BUSY;
    goto lauch_err;
  }

#endif /* BRA_CFG_PROF_FALLBACK */

  if(lauch_p->noBearer > 0)
  {
    for(i = 0; i < lauch_p->noBearer; i++)
    {
      int bearer = -1;

      if(lauch_p->bearer[i] == 0x01)
        bearer = HDI_SOCKET_BEARER_GSM_CSD;
#ifdef __PS_SERVICE__      
      else if(lauch_p->bearer[i] == 0x03)
        bearer = HDI_SOCKET_BEARER_GSM_GPRS;
#endif
      if(bearer > 0)
      {
        if((nw_acc_id = HDIa_networkAccountGetId(bearer)) >= 0)                  
          break;       
      }
    }
    
    if(lauch_p->noBearer > 0 && i == lauch_p->noBearer)
    {      
      res = BRA_SAT_BEARER_UNAVAILABLE;
      goto lauch_err;
    }
  }

  if(lauch_p->browserMode == 0x00)
  {
    /* launch browser, if not already launched. 
       nothing to do */
  }
  else if(lauch_p->browserMode == 0x02)
  {
    /* use the existing browser (the browser shall not use the active existing secured session) 
       nothing to do */
  }
  else if(lauch_p->browserMode == 0x03)
  {
    /* close the existing browser session and launch new browser session */
    if(bra_sif_get_brs_status() != BRA_SIF_BRS_NOT_ACTIVE)
    {
      BRSif_deleteInstance (MSF_MODID_BRA, bra_sif_get_brs_id ());
      bra_sif_set_brs_status(BRA_SIF_BRS_ACTIVE);
    }
  }

  /* process gateway */
  if(lauch_p->noGateway > 0 && check_ip((char*)(lauch_p->gateway)))
  {
    gateway = BRA_ALLOC(lauch_p->noGateway+1);
    strcpy((char*)gateway, (const char*)(lauch_p->gateway));
  }      
  else
  {
    /* error */
    /*res = BRA_SAT_PARAM_GATEWAY_ERROR;
    goto lauch_err;*/
  }

  if(lauch_p->noUrl > 0)
  {
    if(!check_url((char*)(lauch_p->url)) || !bra_cmn_url_is_valid((char*)(lauch_p->url))) 
    {
      /* error */
      res = BRA_SAT_PARAM_URL_ERROR;
      goto lauch_err;
    }
    else
    {
      url = BRA_ALLOC(lauch_p->noUrl+1);
      strcpy((char*)url, (const char*)(lauch_p->url));
    }
  }
  else
  {
    url = BRA_ALLOC(strlen((bra_cmn_get_homepage())->url)+1);
    strcpy((char*)url, (const char*)((bra_cmn_get_homepage())->url));
  }

  if(!url)
  {
    res = BRA_SAT_PARAM_URL_ERROR;
    goto lauch_err;
  }

  if(!bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    bra_create_ui(BRA_UI_VIEWPORT);
  
#ifdef BRA_CFG_DUAL_SIM
  /* because the UI is already created,so do not need to select SIM again 
     because the browser is not busy, so we can select and commit another profile again */
  if (lauch_p->sim_id == BRA_SIM_ID_DEFAULT)
      lauch_p->sim_id = bra_sim_get_bra_sim_id_in_active_use();

  bra_sim_set_widget_sim_icon(lauch_p->sim_id);

  if (bra_prof_get_profile_sim_id() != lauch_p->sim_id)
  {
    int   new_prof_id;
    
    
    new_prof_id = bra_prof_get_sim_activated_profile_id(BRA_PROF_ID_BRA, lauch_p->sim_id);
    bra_prof_set_sim_selected_profile(BRA_PROF_ID_BRA, lauch_p->sim_id, new_prof_id, NULL);
    bra_prof_commit_profile();
  }
#endif /* BRA_CFG_DUAL_SIM */ 

  if(gateway)
    bra_prof_commit_key_str_value (BRA_PROF_ID_BRA, BRA_PROF_KEY_PRX_ADDR, gateway);

  if(nw_acc_id >= 0)
  {
#ifdef BRA_CFG_CONN_ALWAYS_ASK
    bra_prof_commit_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID_IS_ASK, 0);
#endif
    bra_prof_commit_key_int_value(BRA_PROF_ID_BRA, BRA_PROF_KEY_NET_ID, nw_acc_id);
  }

  bra_win_close_window (BRA_WIN_CLOSE_TO_ID, BRA_WIN_ID_VIEWPORT);    
  bra_send_request(url);
  res = BRA_SAT_LAUCH_SUCC;  
/* BRA_CFG_DUAL_SIM */
lauch_err:

  BRA_FREE(gateway);
  BRA_FREE(url);
  BRA_FREE(lauch_p->url);
  BRA_FREE(lauch_p->bearer);
  BRA_FREE(lauch_p->gateway);
  
  bra_send_lauch_rsp_to_mmi(res);
}

#endif  

void bra_da_download_info(MSF_UINT32 jobCount, MSF_UINT32 activeJobCount)
{
    bra_download_job_count = jobCount;
    bra_download_active_job_count = activeJobCount;
    
    if (jobCount == 0)
    {
        if (bra_win_get_window(BRA_WIN_ID_INSE))
        {
            bra_inse_remove_download_item();
        }
        if (bra_win_get_window(BRA_WIN_ID_OPT))
        {
            bra_opt_remove_download_item();
        }
    }
}

int bra_get_da_download_job_count()
{
    return bra_download_job_count;
}

int bra_get_da_download_active_job_count()
{
    return bra_download_active_job_count;
}

void bra_da_wap_notify_display_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_da_wap_notify_ind_struct *da_wap_notify;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    da_wap_notify =
        (mmi_da_wap_notify_ind_struct*) construct_local_para((kal_uint16) sizeof(mmi_da_wap_notify_ind_struct), TD_CTRL);
    da_wap_notify->notify = MMI_DA_WAP_NOTIFY_DISPLAY_LIST;
    
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) da_wap_notify;
    ilm_ptr->msg_id = MSG_ID_MMI_DA_WAP_NOTIFY_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

void bra_da_wap_notify_browser_closed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_da_wap_notify_ind_struct *da_wap_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    da_wap_notify =
        (mmi_da_wap_notify_ind_struct*) construct_local_para((kal_uint16) sizeof(mmi_da_wap_notify_ind_struct), TD_CTRL);
    da_wap_notify->notify = MMI_DA_WAP_NOTIFY_BROWSER_CLOSED;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) da_wap_notify;
    ilm_ptr->msg_id = MSG_ID_MMI_DA_WAP_NOTIFY_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


int
bra_is_wap_in_active_use(void)
{
  /* in connecting or has viewable page */
  if (bra_view_is_busy() || bra_view_if_has_viewable_page())
  {
    return TRUE;
  }
    
#ifdef BRA_CFG_PROF_FALLBACK
  if (bra_sif_is_pending_bearer_switch())
  {
    return TRUE;
  }
#endif /* BRA_CFG_PROF_FALLBACK */
  return FALSE;    
}



