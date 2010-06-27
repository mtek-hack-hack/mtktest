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
 * bra_main.h
 *
 * This file contain the Browser Reference Applications main functionality
 * such as Initialization and Termination functions. State handlers and the
 * internal signal receive funtion.
 */


#ifndef _bra_main_h
#define _bra_main_h

#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_mem_h
#include "msf_mem.h"
#endif
#ifndef _msf_lib_h
#include "msf_lib.h"
#endif


/************************************************************
 * Variables used for exeption handling
 ************************************************************/
extern jmp_buf bra_jmpbuf;
extern int     bra_inside_run;
extern int     bra_browser_entry_from_menu;


/*********************************************
 * Signal destinations which is
 * used by bra_sig, are defined here.
 *********************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0


typedef enum
{
  BRA_MAIN_SIG_VIEW_MESSAGE,				      
  BRA_MAIN_SIG_TERMINATE,				       
  BRA_MAIN_SIG_STATUS,					          
  BRA_MAIN_SIG_WIDGET_ACTION,			      
  BRA_MAIN_SIG_SOCKET_HOST_BY_NAME,	    
  BRA_MAIN_SIG_PIPE_NOTIFY,              
  BRA_MAIN_SIG_FILE_NOTIFY,             
  BRA_MAIN_SIG_EXECUTE_COMMAND,			    
    
  BRA_MAIN_SIG_CONTINUE_TERMINATE,       
  BRA_MAIN_SIG_BRS_CREATE_RESPONSE,      
    
  BRA_MAIN_SIG_CONT_FILE_TASK,           
    
  BRA_MAIN_SIG_PRS_CONTINUE,             
    
  BRA_MAIN_SIG_PSL_NEW_MSG,              
  BRA_MAIN_SIG_REPLY_MSG,                

  BRA_MAIN_SIG_ACT_FINISHED,             
  BRA_MAIN_SIG_AFI_FINISHED,             
    
  BRA_MAIN_SIG_AFI_DONE,                 
    
  BRA_MAIN_SIG_WIDGET_NOTIFY,            
    
    
#ifdef BRA_CFG_CCA
  BRA_MAIN_SIG_CCA_PROF_INSTALL_CONTINUE,	
#endif /* BRA_CFG_CCA */
    
  BRA_MAIN_SIG_CONTINUE_CREATE_UI,

  BRA_MAIN_SIG_MAX_ITEM
}bra_main_sig_enum;




/*********************************************
 * Initialization states
 *********************************************/
#define  BRA_NULL_STATE         ((MSF_UINT32)(0x0000))
#define  BRA_BKM_INITIALIZING   ((MSF_UINT32)(0x0001))
#define  BRA_BKM_TERMINATING    ((MSF_UINT32)(0x0002))
#define  BRA_READING_REGISTRY   ((MSF_UINT32)(0x0004))
#define  BRA_READING_PROFILE    ((MSF_UINT32)(0x0008))
#define  BRA_READING_HISTORY    ((MSF_UINT32)(0x0010))
#define  BRA_STARTING_PSL       ((MSF_UINT32)(0x0020))
#define  BRA_TERMINATING_PSL    ((MSF_UINT32)(0x0040))
#define  BRA_INITIALIZED        ((MSF_UINT32)(0x0080))
#define  BRA_INITIALIZING       ((MSF_UINT32)(0x0100))
#define  BRA_READING_RECENT_PAGE_LIST ((MSF_UINT32)(0x0200))
/*********************************************
 * Exported function
 *********************************************/

/*
 * Function sets the state of BRA to stat. This function is
 * used during startup and termination. The state is typically
 * used when reading the registry. This is a delayed operation 
 * and therfore we need to remember the state so the initialization
 * routine is aware that it can't return MODULE_ACTIVE.
 *
 * PARAMETERS
 *
 * state     : The state as defined above to be set
 *
 * RETURN    : viod
 */
void 
bra_main_set_module_state(MSF_UINT32 state);

/*
 * Function removes the previously set state of BRA to stat. 
 * used during startup and termination. 
 *
 * PARAMETERS
 *
 * state     : The state to be removed
 *
 * RETURN    : void
 */
void 
bra_main_remove_module_state(MSF_UINT32 state);

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
bra_main_reg_responce(void *response);

/*
 * This function is called to try if BRA has finished the initialization process.
 * If the module is finished it starts parsing the command line if available.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bra_init_done (void);

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
bra_init (void);

void
bra_goto_url (char *url);

void
bra_add_bookmark (char *url);

void
bra_handle_create_ui(void *p);

void
bra_handle_continue_create_ui(void  *p);

void
bra_handle_destroy_ui(void);

void
bra_create_ui (MSF_UINT8 p);

void
bra_destroy_ui (void);

void
bra_show_auth_dialog (void *p);

void
bra_show_dialog (void *p);

void
bra_show_dialog_ext (void *p);

void
bra_make_call(void *p);

void
bra_send_dtmf(void *p);

void
bra_pb_add_entry(void *);

void
bra_handle_extscheme(void *p);

int
bra_check_dialog_is_extscheme(void);

#ifdef __SAT__

void 
bra_sat_lauch_request(void *p);

#endif /*__SAT__*/

void bra_da_download_info(MSF_UINT32 jobCount, MSF_UINT32 activeJobCount);

int
bra_get_da_download_job_count(void);

int
bra_get_da_download_active_job_count(void);

void
bra_da_wap_notify_display_list(void);

void
bra_da_wap_notify_browser_closed(void);

int
bra_is_wap_in_active_use(void);



#endif /* _bra_main_h */

