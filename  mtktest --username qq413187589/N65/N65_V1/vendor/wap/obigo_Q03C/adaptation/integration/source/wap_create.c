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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * wap_create.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for WAP task create function and message handler
 *   entry point.
 * Author:
 * -------
 * -------
 *
  *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _WAP_CREATE_C_

#ifndef __MTK_TARGET__
#include <windows.h>
#endif

#include "stdio.h"

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msm_env.h"

#include "soc_api.h"
#include "app2soc_struct.h"

#include "bra_cfg.h"

#include "bra_if.h"
#include "bra_view.h"
#include "bra_int.h"
#include "gv.h"
#include "tst_def.h"

#include "fat_fs.h"     /* file system */
#include "L4Dr.h"
#include "FileManagerGProt.h"
#include "fmt_struct.h"

#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"

#include "wap_ps_struct.h"

/* added by Kevin for handling interaction with MMI */
#include "mmiapi_struct.h"
/* added by Kevin ----end */

#ifdef MMS_SUPPORT
#include "mms_def.h"    /* MMS_REG_PATH_IMMEDIATE_RETRIEVAL */
#include "mea_cfg.h"    /* MEA_FOLDER_PATH */
#include "mea_def.h"    /* MEA_RETRIEVAL_MODE_AUTOMATIC ... */
/* MMS -pbook list Jo 030825 */
#include "WapDef.h"
#include "Msf_mem.h"
#include "mea_env.h"    /* for MEAc_startWithContentInserted */
#ifdef MMSAT_SUPPORT
#include "l4a.h"
#include "mmc_env.h"
#endif /* MMSAT_SUPPORT */ 
#ifdef __UNIFIED_MSG_SUPPORT__
#include "mea_if.h"
#endif
#endif /* MMS_SUPPORT */ 

#include "bra_int.h"
#include "wapadp.h"
#include "wap_cmn.h"
#include "widget.h"
#include "das_main.h"
#include "das_msg.h"
#include "wap_cmmn_utils.h"

#include <setjmp.h>


#ifdef BRA_CFG_CCA
#include "CentralConfigAgentGprot.h"
#include "CentralconfigAgentDefs.h"
#endif /*BRA_CFG_CCA*/


#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN
#include "DataAccountGprot.h"
#endif



// #define DEBUG_FILE_WITH_INJECTION       /* Justin */
// #define READ_WAP_DEFAULT_FROM_CONST /* Johnnie */
#define READ_WAP_DEFAULT_FROM_CUSTOM_PACK       /* Johnnie */

#if defined(READ_WAP_DEFAULT_FROM_CONST) || defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
#include "custom_wap_config.h"
#endif 

/* MSM */
typedef void (*msf_start_call_back_t) (void);
extern void MSF_start(kal_bool slow_start, msf_start_call_back_t callback);
extern void MSF_fsm(void);
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern kal_bool MSM_init(void);
extern kal_bool MSM_deinit(void);
extern void msf_timer_expiry_hdlr(ilm_struct *ilm_ptr);
extern int MSF_wapIsReady(void);
extern kal_uint32 wap_get_queue_size(void);

/* Signal */
extern void HDI_signalQueueInit(void);

/* Socket */
extern void HDIa_socketInit(void);
extern void HDIa_socketMsgHdlr(ilm_struct *ilm_ptr);
extern void HDIa_socketTermBearer(void);

/* Pipe */
extern void HDIa_pipeInit(void);

/* File */
extern void HDI_fileInit(void);
extern void HDI_fileDeinit(void);
extern void HDI_file_timer_expiry(ilm_struct *ilm_ptr);

/* Misc */
extern void set_log_filter(tst_inject_string_struct *inject_str);

/* Widget */
extern stack_timer_struct widget_timer;
extern void widget_timer_expiry(ilm_struct *ilm_ptr);
extern void widget_init(void);
extern void widget_deinit(void);
extern void widget_waiting_external_queue(void);
extern void widget_finish_external_queue(void);

/* WTAI */
extern void wtai_dial_call_req_hdlr(void);
extern void wtai_dial_call_rsp_hdlr(ilm_struct *ilm_ptr);
extern void wtai_send_dtmf_rsp_hdlr(local_para_struct *local_para_ptr);
extern void wtai_phb_add_entry_rsp_hdlr(local_para_struct *local_para_ptr);

/* WAP profile */
extern void wap_prof_access_hdlr(ilm_struct *ilm_ptr);
extern void wap_get_prof_list_req_hdlr(module_type req_src_id);
extern void wap_get_prof_content_req_hdlr(wap_get_prof_content_req_struct *content_req_ptr,
                                          module_type req_src_id);
extern void wap_get_bra_prof_id_req_hdlr(module_type req_src_id);

/* Key */
extern void widget_wap_mmi_key_ind(ilm_struct *ilm_ptr);

/* RPC */
extern void widget_mmiapi_remote_proc_call_req(ilm_struct *ilm_ptr);

#if defined(__TCPIP__) && defined(WAP_SUPPORT)
extern void bra_prs_set_gsm_profile_rsp(local_para_struct *);
extern void bra_prs_get_free_gsm_profile_rsp(local_para_struct *);
extern void bra_prs_set_gprs_profile_rsp(local_para_struct *);
extern void bra_prs_get_free_gprs_profile_rsp(local_para_struct *);
#endif /* defined(__TCPIP__) && defined(WAP_SUPPORT) */ 

#ifdef WAP_SUPPORT
// Deprecated
//extern void bra_prs_install_prov(void);
#endif /* WAP_SUPPORT */ 

/* MEMORY */
extern void wapadp_mem_init(MSF_UINT8 modId);
extern void wapadp_mem_free_all(MSF_UINT8 modId);
extern void wapadp_mem_enable_spare_mem(MSF_UINT8 modId);

/* DISCONNECT BEARER */
extern void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID);

/* PUSH */
extern void bra_psl_unread_check(void);

/* MMS */
#ifdef MMS_SUPPORT
extern kal_bool isMMSBusy(void);
extern int widget_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern int widget_ucs2_to_utf8_string(kal_uint8 *dest, int dest_size, const kal_uint8 *src);
extern void meaMeRegisterExitCallback(func_ptr funcPtr, void *param);

#ifdef __USB_IN_NORMAL_MODE__
extern kal_bool is_mms_storage_exported_to_pc(void);
extern void mms_unread_check(void);
extern void mmsImmediateRetrievalGet(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 
extern int msm_get_module_status(MSF_UINT8 modId);
extern char *SMAlib_getAttachment(char *filename);
#endif /* MMS_SUPPORT */ 

/* Global Vars */
kal_msgqid wap_ext_qid;
kal_uint8 wap_status;
kal_uint8 wap_action;
jmp_buf wap_jmpbuf;
kal_int32 wap_external_get_id;

#ifdef __MMI_DUAL_SIM__
static kal_uint8 sim_status;
static kal_uint8 sim_setting_mode;
#endif


#define MSG_MMI_EQ_POWER_ON_IND     0x01
#define MSG_MMI_READY_NOTIFY_REQ    0x02
#define MSG_WAP_SIM_INFO_NOTIFY_IND 0x04

extern void msm_remove_files_under_dir(const char *folder);
extern void msm_compute_checksum_critical_files(void);
extern void msm_compute_checksum_sec_files(void);

#define WAP_BRA_FILE_DIR "/bra"
#define WAP_MSM_FILE_DIR "/msm"
#define WAP_SEC_FILE_DIR "/sec"
#define WAP_SEC_STORAGE_DIR "/sec/storage"
#define WAP_COMMON_SETTING_FILE "/msm/registry.txt"
#define WAP_COMMON_SETTING_INITIAL_SIZE 1024
#define WAP_CRITICAL_CHKSUM_FILE "/msm/chksum1.dat"
#define WAP_SEC_CHKSUM_FILE "/msm/secchksum.dat"
#define WAP_MAX_WRITE_SIZE 512

#define WAP_INT_QUEUE_SIZE    (5)
#define WIDGET_QUEUE_SIZE_HIGH_WATERMARK     (15)

static kal_uint8 wap_int_q_size = 0;
static kal_uint8 wap_int_q_read_index = 0;
static kal_uint8 wap_int_q_write_index = 0;
static ilm_struct wap_int_q_array[WAP_INT_QUEUE_SIZE];

static kal_bool wap_is_timer_msg_in_int_q = KAL_FALSE;

#ifdef READ_WAP_DEFAULT_FROM_CUSTOM_PACK
static void wap_write_default(void);
static void wap_write_root_ca_default(void);
#else /* READ_WAP_DEFAULT_FROM_CUSTOM_PACK */ 
static void wap_write_wap_setting_to_file(kal_uint8 *wap_setting_data, kal_uint16 len);
static void wap_write_root_ca_to_file(kal_uint8 *root_ca_data, kal_uint16 len);
#endif /* READ_WAP_DEFAULT_FROM_CUSTOM_PACK */ 

/*************************************************************************
* Some helper function for DEBUG_FILE_WITH_INJECTION
*************************************************************************/

#ifdef DEBUG_FILE_WITH_INJECTION
/* Justin */
/* from char to \xAB */


/*****************************************************************************
 * FUNCTION
 *  utf8_modify_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]         
 *  src     [?]         
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void utf8_modify_name(unsigned char *dst, unsigned char *src, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < len - 5 && *src)
    {
        if (*src <= 127)
        {
            *dst++ = *src++;
            count++;
        }
        else
        {
            sprintf((char*)dst, "\\x%02x", (int)*src++);
            count += 4;
            dst += 4;
        }
    }
    *dst = 0;
}


/*****************************************************************************
 * FUNCTION
 *  chr_hex_to_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static unsigned char chr_hex_to_num(unsigned char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c >= 'a')
    {
        return c - 'a' + 10;
    }
    if (c >= 'A')
    {
        return c - 'A' + 10;
    }
    return c - '0';
}


/*****************************************************************************
 * FUNCTION
 *  utf8_modify_name_backward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  src         [?]         
 *  dst_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void utf8_modify_name_backward(unsigned char *dst, unsigned char *src, int dst_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* I'm not sure if UTF-8 contains backslash */
    while (count < dst_len - 2 && *src)
    {
        if (*src == '\\' && *(src + 1) == 'x')
        {
            /* FIXME no error checking here */
            unsigned char byte1 = chr_hex_to_num(*(src + 2));
            unsigned char byte2 = chr_hex_to_num(*(src + 3));

            *dst++ = (unsigned char)(byte1 * 16 + byte2);
            src += 4;
        }
        else
        {
            *dst++ = *src++;
        }
        count++;
    }
    *dst = 0;
}

#endif /* DEBUG_FILE_WITH_INJECTION */ 


#ifdef __MMI_DUAL_SIM__
/*****************************************************************************
 * FUNCTION
 *  wap_get_sim_status
 * DESCRIPTION
 *  This function is used to restart WAP when internal state is incorrect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 wap_get_sim_status(void)
{
    return sim_status;
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_sim_setting_mode
 * DESCRIPTION
 *  This function is used to restart WAP when internal state is incorrect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 wap_get_sim_setting_mode(void)
{
    return sim_setting_mode;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  notifiy_mmi_wap_poweroff_completed
 * DESCRIPTION
 *  This function is used to notify MMI that WAP poweroff procedure is completed
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void notifiy_mmi_wap_poweroff_completed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int isCalled = 0;    /* it should be called only once */

    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isCalled)
    {
        return;
    }
    isCalled = 1;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_BROWSER_POWEROFF_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  start_poweroff_watchdog
 * DESCRIPTION
 *  start watchdog timer for the poweroff procedure in order to
 *  prevent infinite loop in the termination process
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void start_poweroff_watchdog()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * NOT IMPLEMENTED. We should add a timer to invoke
     * notifiy_mmi_wap_poweroff_completed()
     * with the timer MSF_POWEROFF_TIMER_ID
     * and directly terminate the mobile suite
     */
}


/*****************************************************************************
 * FUNCTION
 *  wap_read_factory_setting
 * DESCRIPTION
 *  This function is used to read WAP factory setting, including profile,
 *  bookmark, common setting, and pre-install root-CA
 * CALLS
 *  
 * PARAMETERS
 *  file_idx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_read_factory_setting(kal_uint8 file_idx)
{
#if defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_idx == 0)
    {
        wap_write_default();
        if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
        {
            msm_compute_checksum_critical_files();
        }
    }
    else if (file_idx == 1)
    {
        wap_write_root_ca_default();
        if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
        {
            msm_compute_checksum_sec_files();
        }
    }
#elif defined(READ_WAP_DEFAULT_FROM_CONST)
    if (file_idx == 0)
    {
        wap_write_wap_setting_to_file((kal_uint8*) wap_default_setting, sizeof(wap_default_setting));
        if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
        {
            msm_compute_checksum_critical_files();
        }
    }
    else if (file_idx == 1)
    {
        wap_write_root_ca_to_file((kal_uint8*) wap_root_ca, sizeof(wap_root_ca));
        if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
        {
            msm_compute_checksum_sec_files();
        }
    }
#else 
    nvram_read_req_struct *nvram_read_req_ptr;
    ilm_struct *ilm_ptr = NULL;

    nvram_read_req_ptr =
        (nvram_read_req_struct*) construct_local_para((kal_uint16) sizeof(nvram_read_req_struct), TD_CTRL);

    if (file_idx == 0)
    {
        nvram_read_req_ptr->file_idx = NVRAM_EF_WAP_SETTING_LID;
    }
    else
    {
        nvram_read_req_ptr->file_idx = NVRAM_EF_ROOT_CA_LID;
    }
    nvram_read_req_ptr->access_id = 0;
    nvram_read_req_ptr->para = 1;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) nvram_read_req_ptr;
    ilm_ptr->msg_id = MSG_ID_NVRAM_READ_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_NVRAM, PS_NVRAM_SAP, ilm_ptr)
#endif 
}

#ifndef READ_WAP_DEFAULT_FROM_CUSTOM_PACK


/*****************************************************************************
 * FUNCTION
 *  wap_write_file
 * DESCRIPTION
 *  This function is used to write factory setting to file system
 * CALLS
 *  
 * PARAMETERS
 *  data            [?]         
 *  filename        [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int wap_write_file(kal_uint8 *data, char *filename, kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 writesize, ret, idx = 0;
    kal_int32 fd;
    kal_uint32 set_size = 0;

#ifdef READ_WAP_DEFAULT_FROM_CONST
    kal_uint8 file_end[3];
    kal_int32 left_size;
    kal_uint8 empty_data[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(empty_data, 0, 128);
#endif /* READ_WAP_DEFAULT_FROM_CONST */ 

    fd = HDIa_fileOpen(
            MSF_MODID_MSM,
            (char*)filename,
            HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
            0);
    if (fd < 0)
#ifdef __PRODUCTION_RELEASE__
        return -1;
#else 
        ASSERT(0)
#endif 
            while (size > 0)
        {
            writesize = (size > WAP_MAX_WRITE_SIZE) ? WAP_MAX_WRITE_SIZE : size;
            ret = HDIa_fileWrite(fd, &(data[idx]), writesize);
            if (ret < 0)
        #ifdef __PRODUCTION_RELEASE__
                return -1;
        #else 
                ASSERT(0)
        #endif 
                    size -= ret;
            idx += ret;
        }

    if (strcmp(filename, BRA_CFG_PROFILE_FILE_PATH) == 0)
    {
    #ifdef READ_WAP_DEFAULT_FROM_CONST
        left_size = BRA_CFG_PROF_INITIAL_SIZE - idx;
    #endif 
        set_size = BRA_CFG_PROF_INITIAL_SIZE;
    }
    else if (strcmp(filename, BRA_CFG_BOOKMARK_FILE_PATH) == 0)
    {
    #ifdef READ_WAP_DEFAULT_FROM_CONST
        left_size = BRA_CFG_BKM_INITIAL_SIZE - idx;
    #endif 
        set_size = BRA_CFG_BKM_INITIAL_SIZE;
    }
    else if (strcmp(filename, WAP_COMMON_SETTING_FILE) == 0)
    {
    #ifdef READ_WAP_DEFAULT_FROM_CONST
        left_size = WAP_COMMON_SETTING_INITIAL_SIZE - idx;
    #endif 
        set_size = WAP_COMMON_SETTING_INITIAL_SIZE;
    }

    if (set_size > 0)
    {
        if (left_size < 0)
        {
            left_size = 0;
        }
    #ifdef READ_WAP_DEFAULT_FROM_CONST
        file_end[0] = 0xfe;
        file_end[1] = (kal_uint8) ((left_size & 0x0000ff00) >> 8);
        file_end[2] = (kal_uint8) (left_size & 0x000000ff);
        ret = HDIa_fileWrite(fd, file_end, 3);
        if (ret != 3)
    #ifdef __PRODUCTION_RELEASE__
            return -1;
    #else 
            ASSERT(0)
    #endif 
                left_size -= 3;

        while (left_size > 0)
        {
            writesize = (left_size > 128) ? 128 : left_size;
            ret = HDIa_fileWrite(fd, empty_data, writesize);
            if (ret < 0)
        #ifdef __PRODUCTION_RELEASE__
                return -1;
        #else 
                ASSERT(0)
        #endif 
                    left_size -= ret;
        }

    #endif /* READ_WAP_DEFAULT_FROM_CONST */ 
        //Write empty data to replace set size
        //HDIa_fileSetSize(fd, set_size);
    }

    HDIa_fileClose(fd);
    return idx;
}
#endif /* READ_WAP_DEFAULT_FROM_CUSTOM_PACK */ 


/*****************************************************************************
 * FUNCTION
 *  wap_reserve_file
 * DESCRIPTION
 *  This function is used to reserve file space for a specified file
 * CALLS
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  filesize        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_reserve_file(const char *filename, kal_uint16 filesize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fd;
    char s[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = HDIa_fileOpen(MSF_MODID_MSM, filename, HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);

    if (fd < 0)
    {
        fd = HDIa_fileOpen(
                MSF_MODID_MSM,
                filename,
                HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                0);
        if (fd < 0)
    #ifdef __PRODUCTION_RELEASE__
            return;
    #else 
            ASSERT(0)
    #endif 
                HDIa_fileSetSize(fd, filesize);
        sprintf(s, "%c%c%c", 0xfe, ((filesize - 3) & 0xff00) >> 8, ((filesize - 3) & 0x00ff));
        HDIa_fileWrite(fd, s, strlen(s));
        HDIa_fileClose(fd);
    }
    else
    {
        HDIa_fileSetSize(fd, filesize);
        HDIa_fileClose(fd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_reserve_file_space
 * DESCRIPTION
 *  This function is used to reserve file space for necessary WAP files
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_reserve_file_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_reserve_file(BRA_CFG_HISTORY_FILE_PATH, BRA_CFG_HIST_INITIAL_SIZE);
    wap_reserve_file(BRA_CFG_RECENT_LIST_FILE_PATH, BRA_CFG_RPL_INITIAL_SIZE);
}

#ifndef READ_WAP_DEFAULT_FROM_CUSTOM_PACK


/*****************************************************************************
 * FUNCTION
 *  wap_write_wap_setting_to_file
 * DESCRIPTION
 *  This function is used to write factory setting of profile, bookmark,
 *  and common setting to file system
 * CALLS
 *  
 * PARAMETERS
 *  wap_setting_data        [?]         
 *  len                     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_write_wap_setting_to_file(kal_uint8 *wap_setting_data, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 type;
    kal_uint16 size, idx = 0;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (len > idx)
    {
        type = wap_setting_data[idx++];
        size = wap_setting_data[idx++] << 8;
        size += wap_setting_data[idx++];

        /* create necessary DIR first */
        switch (type)
        {
            case 'B':
                if (wap_action == WAP_ACTION_POWER_ON)
                {
                    idx += size;
                    continue;
                }
                else
                {
                    ret = HDIa_fileMkDir(WAP_BRA_FILE_DIR);
                }
                break;
            case 'P':
                if (wap_action == WAP_ACTION_POWER_ON)
                {
                    idx += size;
                    continue;
                }
                else
                {
                    ret = HDIa_fileMkDir(WAP_BRA_FILE_DIR);
                }
                break;
            case 'C':
                ret = HDIa_fileMkDir(WAP_MSM_FILE_DIR);
                break;
            default:
                return;
        }

        if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
    #ifdef __PRODUCTION_RELEASE__
            return;
    #else 
            ASSERT(0)
    #endif 
                /* write file */
                switch (type)
            {
                case 'B':
                    ret = wap_write_file(&(wap_setting_data[idx]), BRA_CFG_BOOKMARK_FILE_PATH, size);
                    break;
                case 'P':
                    ret = wap_write_file(&(wap_setting_data[idx]), BRA_CFG_PROFILE_FILE_PATH, size);
                    break;
                case 'C':
                    ret = wap_write_file(&(wap_setting_data[idx]), WAP_COMMON_SETTING_FILE, size);
                    break;
                default:
                    return;
            }

        if (ret < 0)
        #ifdef __PRODUCTION_RELEASE__
            return;
        #else 
            ASSERT(0)
        #endif 
                idx += ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_root_ca_to_file
 * DESCRIPTION
 *  This function is used to write pre-install root ca to file system
 * CALLS
 *  
 * PARAMETERS
 *  root_ca_data        [?]         
 *  len                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_write_root_ca_to_file(kal_uint8 *root_ca_data, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 fileidx;
    char filename[32];
    kal_uint16 size, idx = 0;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = HDIa_fileMkDir(WAP_SEC_FILE_DIR);
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
#ifdef __PRODUCTION_RELEASE__
        return;
#else 
        ASSERT(0)
#endif 
            ret = HDIa_fileMkDir(WAP_SEC_STORAGE_DIR);
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
#ifdef __PRODUCTION_RELEASE__
        return;
#else 
        ASSERT(0)
#endif 
            while (len > idx)
        {
            fileidx = root_ca_data[idx++];
            size = root_ca_data[idx++] << 8;
            size += root_ca_data[idx++];
            if (fileidx < '0' || fileidx > '9')
            {
                break;
            }
            sprintf(filename, "%s/S_%c", WAP_SEC_STORAGE_DIR, fileidx);
            ret = wap_write_file(&(root_ca_data[idx]), filename, size);
            if (ret < 0)
        #ifdef __PRODUCTION_RELEASE__
                return;
        #else 
                ASSERT(0)
        #endif 
                    idx += ret;
        }
}
#endif /* READ_WAP_DEFAULT_FROM_CUSTOM_PACK */ 

#if !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)


/*****************************************************************************
 * FUNCTION
 *  wap_factory_setting_hdlr
 * DESCRIPTION
 *  This function is used to read WAP factory setting, including profile,
 *  bookmark, common setting, and pre-install root-CA
 * CALLS
 *  
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 wap_factory_setting_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *nvram_read_cnf_ptr;
    kal_uint8 *peer_packed_pdu_ptr;
    kal_uint16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_ptr = (nvram_read_cnf_struct*) local_para_ptr;

    if (nvram_read_cnf_ptr->file_idx == NVRAM_EF_WAP_SETTING_LID)
    {
        if (nvram_read_cnf_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            peer_packed_pdu_ptr = get_pdu_ptr(peer_buff_ptr, &len);
            wap_write_wap_setting_to_file(peer_packed_pdu_ptr, len);
            if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
            {
                msm_compute_checksum_critical_files();
            }
        }
    }
    else if (nvram_read_cnf_ptr->file_idx == NVRAM_EF_ROOT_CA_LID)
    {
        if (nvram_read_cnf_ptr->result == NVRAM_IO_ERRNO_OK)
        {
            peer_packed_pdu_ptr = get_pdu_ptr(peer_buff_ptr, &len);
            wap_write_root_ca_to_file(peer_packed_pdu_ptr, len);
            if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
            {
                msm_compute_checksum_sec_files();
            }
        }
    }

    return nvram_read_cnf_ptr->file_idx;
}
#endif /* !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK) */ 


/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_restore_factory_cnf
 * DESCRIPTION
 *  This function is used to send MMI restore factory setting confirmation
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_mmi_restore_factory_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF;
    ilm_ptr->peer_buff_ptr = NULL;
SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)}


/*****************************************************************************
 * FUNCTION
 *  wap_send_fmt_format_rsp
 * DESCRIPTION
 *  This function is used to send FMT format response
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_fmt_format_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_fmt_format_rsp_strcut *fmt_format_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_format_rsp =
        (mmi_fmt_format_rsp_strcut*) construct_local_para((kal_uint16) sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);
    fmt_format_rsp->result = FS_NO_ERROR;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) fmt_format_rsp;
    ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
SEND_ILM(MOD_WAP, MOD_FMT, WAP_MMI_SAP, ilm_ptr)}

#ifdef __USB_IN_NORMAL_MODE__

#ifdef MMS_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_mms_enter_usb_mode_rsp
 * DESCRIPTION
 *  This function is used to send mms ready signal to MMI task for entering USB mode
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_mmi_mms_enter_usb_mode_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->msg_id = MSG_ID_MMS_ENTER_USB_MODE_RSP;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_mms_exit_usb_mode_rsp
 * DESCRIPTION
 *  This function is used to send mms ready signal to MMI task for exiting USB mode
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_mmi_mms_exit_usb_mode_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->msg_id = MSG_ID_MMS_EXIT_USB_MODE_RSP;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}
#endif /* MMS_SUPPORT */ 
#endif /* __USB_IN_NORMAL_MODE__ */ 

/*****************************************************************************
 * FUNCTION
 *  wap_send_j2me_mms_get_active_mms_attachment_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  filepath        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void wap_send_j2me_mms_get_active_mms_attachment_rsp(kal_uint8 result, kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
    mms_get_attachment_rsp_struct *get_attachment_rsp;
    int buffer_size = 261 * sizeof(kal_wchar);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_attachment_rsp = (mms_get_attachment_rsp_struct*)
        construct_local_para((kal_uint16) sizeof(mms_get_attachment_rsp_struct), TD_CTRL);
    get_attachment_rsp->result = result;
    if (filepath && (widget_ucs2_length((const kal_uint8 *)filepath) * 2 < buffer_size))
    {
        widget_ucs2_strcpy((kal_uint8 *)get_attachment_rsp->filepath, (const kal_uint8 *)filepath);
    }
    else
    {
        memset(get_attachment_rsp->filepath, 0x00, buffer_size);
    }

    ilm_ptr->msg_id = MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP;
    ilm_ptr->local_para_ptr = (local_para_struct*) get_attachment_rsp;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_J2ME, WAP_J2ME_SAP, ilm_ptr);
}

#ifdef WPS_TASK_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wap_send_wps_wap_ready_ind
 * DESCRIPTION
 *  This function is used to send WAP ready indication to WPS task, then WPS task
 *  can notify its user that it is ready to provide service
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_wps_wap_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->msg_id = MSG_ID_WAP_READY_IND;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_WPS, WPS_APP_SAP, ilm_ptr);
}

#endif /* WPS_TASK_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wap_ready_callback_func
 * DESCRIPTION
 *  This function is used for call back function when wap init. finish
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_ready_callback_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WPS_TASK_SUPPORT
    wap_send_wps_wap_ready_ind();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wap_delete_all_files
 * DESCRIPTION
 *  This function is used to remove all WAP related files
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_delete_all_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msm_remove_files_under_dir(WAP_BRA_FILE_DIR);
    msm_remove_files_under_dir(WAP_MSM_FILE_DIR);
    HDIa_fileRmDir(WAP_MSM_FILE_DIR);
    msm_remove_files_under_dir(WAP_SEC_STORAGE_DIR);

#ifdef MMS_SUPPORT
    if(HDIa_fileCheckDirExist(MEA_FOLDER_PATH))
    {
        HDIa_fileRemove(MEA_SIG_SET_FILE);
        HDIa_fileRemove(MEA_SIG_TEXT_FILE);
        HDIa_fileRemove(MEA_CREATION_MODE_SET_FILE);
        HDIa_fileRemove(MEA_IMAGE_RESIZE_SET_FILE);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wap_task_sleep
 * DESCRIPTION
 *  Put the wap task to sleep (wait protocol ready or give control to MMI task)
 * CALLS
 *  
 * PARAMETERS
 *  milliseconds        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_task_sleep(int milliseconds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sleep_task(kal_milli_secs_to_ticks(milliseconds));
}


/*****************************************************************************
 * FUNCTION
 *  wap_simulate_out_of_memory
 * DESCRIPTION
 *  Put the wap task to sleep (wait protocol ready or give control to MMI task)
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_simulate_out_of_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 20; i++)
    {
        MSF_MEM_ALLOC(MSF_MODID_MSM, 10 * 1024);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_init
 * DESCRIPTION
 *  This function should be called to Initialize the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_action = WAP_ACTION_NONE;
    wap_status = WAP_RESET_COMPLETE;
    wapadp_mem_init(WAP_MEM_POOL);
    MSM_init();
    HDI_signalQueueInit();
    HDIa_socketInit();
    HDIa_pipeInit();
    HDI_fileInit();

    wap_prepare_root_folder(L"z:\\@wap", "obigo_q03c");

    widget_init();

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_deinit
 * DESCRIPTION
 *  This function should be called to deinit the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSM_deinit();
    HDI_fileDeinit();
    widget_deinit();
    wapadp_mem_free_all(WAP_MEM_POOL);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_reset
 * DESCRIPTION
 *  This function should be called to reset the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_socketDiscBearerById(0xff);
    wap_status = WAP_RESET_ONGOING;
    wapadp_mem_enable_spare_mem(WAP_MEM_POOL);
    MSMc_terminateMobileSuite();
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcLen      [IN]        
 *  srcStr      [?]         
 *  dstStr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_utf8_to_ucs2(kal_uint16 srcLen, kal_uint8 *srcStr, char **dstStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *tempStr;
    long tempLen = 500, utf8Len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8Len = (long)srcLen;
    tempStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen);
    memset(tempStr, 0, tempLen);
    msf_charset_utf8_to_ucs2le((const char*)srcStr, &utf8Len, tempStr, &tempLen);
    *dstStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen);
    memcpy(*dstStr, tempStr, tempLen);
    MSF_MEM_FREE(MSF_MODID_MSM, tempStr);
    return (kal_uint16) tempLen;
}


/*****************************************************************************
 * FUNCTION
 *  wap_proc_inject_string
 * DESCRIPTION
 *  This function should be called from wap_fsm to process injection string
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_proc_inject_string(tst_inject_string_struct *inject_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inject_str->index < 2)
    {
        /* set log filter */
        set_log_filter(inject_str);
    }
    else if (inject_str->index == 5)
    {
        if (wap_status != WAP_RUNNING)
    #ifdef __PRODUCTION_RELEASE__
            wap_send_mmi_restore_factory_cnf();
    #else 
            ASSERT(0)
    #endif 
                wap_action = WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING, wap_reset(INDX_WAP);
    }
    else if (inject_str->index == 6)
    {
        kal_uint8 addr[4];
        kal_uint8 addr_len = 0;

        soc_gethostbyname(
            0,
            MOD_WAP,
            100,
            (const kal_char*)inject_str->string,
            (kal_uint8*) addr,
            (kal_uint8*) & addr_len,
            0,
            (kal_uint32) BRAif_getNetAccId());
    }
    else if (inject_str->index == 7)
    {
        ilm_struct *ilm_ptr;
        wap_mmi_lauch_browser_req_struct *lauch_p;

        lauch_p =
            (wap_mmi_lauch_browser_req_struct*) construct_local_para(
                                                    (kal_uint16) sizeof(wap_mmi_lauch_browser_req_struct),
                                                    TD_CTRL);
        lauch_p->browserMode = 0;
        lauch_p->browserIdentity = 0;
        lauch_p->noBearer = 0;
        lauch_p->bearer = NULL;

        lauch_p->noUrl = wap_utf8_to_ucs2(
                            (kal_uint16) strlen("http://wap.sina.com/"),
                            (kal_uint8*) "http://wap.sina.com/",
                            (char **)&(lauch_p->url));

        lauch_p->noGateway = wap_utf8_to_ucs2(
                                (kal_uint16) strlen("193.113.200.150"),
                                (kal_uint8*) "193.113.200.150",
                                (char **)&(lauch_p->gateway));

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ;
        ilm_ptr->peer_buff_ptr = NULL;
        ilm_ptr->local_para_ptr = (local_para_struct*) lauch_p;
        SEND_ILM(MOD_CC, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
    }
    else if (inject_str->index == 9)
    {
        wap_simulate_out_of_memory();
    }
#ifdef DEBUG_FILE_WITH_INJECTION
    else if (inject_str->index == 21)   /* get file size */
    {
        /* TODO compute checksum */

        long size = HDIa_fileGetSize((char*)inject_str->string);

        if (size >= 0)
        {
            kal_prompt_trace(MOD_WAP, "%s size %d", inject_str->string, (int)size);
        }
        else
        {
            kal_prompt_trace(MOD_WAP, "%s open error: No. %d", inject_str->string, (int)size);
        }
    }
    else if (inject_str->index == 22)   /* get file size (chinese+english) */
    {
        /* open chinese file name in the format by UTF8 string (\xAB) */
        char longname[128];
        long size;

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);
        size = HDIa_fileGetSize(longname);
        if (size >= 0)
        {
            kal_prompt_trace(MOD_WAP, "%s size %d", inject_str->string, (int)size);
        }
        else
        {
            kal_prompt_trace(MOD_WAP, "%s open error: No. %d", inject_str->string, (int)size);
        }
    }
    else if (inject_str->index == 23)   /* list directory */
    {
        int num_entry;
        int i;

        num_entry = HDIa_fileGetSizeDir((char*)inject_str->string);
        if (num_entry < 0)
        {
            kal_prompt_trace(MOD_WAP, "open dir failed");
        }
        else
        {
            /* it would show short file name by default */
            char namebuf[32];
            char namebuf_modified[200];
            int size;
            int type;

            kal_prompt_trace(MOD_WAP, "Start of directory %s", inject_str->string);
            for (i = 0; i < num_entry; i++)
            {
                HDIa_fileReadDir((char*)inject_str->string, i, namebuf, 32, &type, &size);
                utf8_modify_name((unsigned char*)namebuf_modified, (unsigned char*)namebuf, 128);
                kal_prompt_trace(MOD_WAP, "%s %s - %d", type == HDI_FILE_FILETYPE ? "f" : "d", namebuf_modified, size);
            }
            kal_prompt_trace(MOD_WAP, "End of directory %s", inject_str->string);
        }
    }
    else if (inject_str->index == 24)
    {   /* create file (UTF8) */
        char longname[128];
        int fd;

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);
        fd = HDIa_fileOpen(MSF_MODID_MSM, longname, HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 100);
        if (fd > 0)
        {
            HDIa_fileClose(fd);
            kal_prompt_trace(MOD_WAP, "Create success %s", longname);
        }
        else
        {
            /* However, it might return HDI_FILE_ERROR_DELAYED */
            kal_prompt_trace(MOD_WAP, "Create fail %d %s", fd, longname);
        }
    }
    else if (inject_str->index == 25)   /* get file checksum */
    {
        /* open chinese file name in the format by UTF8 string (\xAB) */
        extern int msm_compute_checksum_from_file(const char *filename);

        char longname[128];
        int checksum;

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);

        checksum = msm_compute_checksum_from_file(longname);

        kal_prompt_trace(MOD_WAP, "%s checksum %d", inject_str->string, checksum);
    }
    else if (inject_str->index == 26)   /* remove file */
    {
        /* open chinese file name in the format by UTF8 string (\xAB) */
        char longname[128];

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);

        HDIa_fileRemove(longname);
        kal_prompt_trace(MOD_WAP, "%s removed", inject_str->string);
    }
    else if (inject_str->index == 27)   /* show disk free space */
    {
        kal_uint32 size;

        size = msm_get_disk_free_space(WAP_STORAGE_SYSTEM);
        kal_prompt_trace(MOD_WAP, "Free space of wap system: %d", size);
        size = msm_get_disk_free_space(WAP_STORAGE_MMS);
        kal_prompt_trace(MOD_WAP, "Free space of /mms: %d", size);
        size = msm_get_disk_free_space(WAP_STORAGE_PUBLIC);
        kal_prompt_trace(MOD_WAP, "Free space of /public: %d", size);
    }
    else if (inject_str->index == 28)
    {
        int files, type;
        long size;
        int i = 0;
        char tmpName[256], pathName[256];
        char *root_folder = (char*)inject_str->string;

        files = HDIa_fileGetSizeDir(root_folder);

        kal_prompt_trace(MOD_WAP, "Total %d folders", files);

        if (files >= 1)
        {
            while ((HDIa_fileReadDir(root_folder, i, tmpName, 256, &type, (int*)&size) == HDI_FILE_OK) && (i < files))
            {
                strcpy(pathName, root_folder);
                strcat(pathName, "\\");
                strcat(pathName, tmpName);
                if (type == HDI_FILE_FILETYPE)
                {
                    size = HDIa_fileGetSize(pathName);
                    kal_prompt_trace(MOD_WAP, "f %d - %s ", (int)size, tmpName);
                }
                else
                {
                    int dummy = 0;

                    size = 0;
                    msm_get_folder_info_recursive(pathName, &dummy, &size);
                    kal_prompt_trace(MOD_WAP, "d %d/ - %s ", (int)size, tmpName);
                }

                i++;
            }
        }

        kal_prompt_trace(MOD_WAP, "End of %d folders", files);
    }
#endif /* DEBUG_FILE_WITH_INJECTION */ 
#if defined(FILE_DEBUG_VERBOSE) && defined(__MTK_TARGET__)
    else if (inject_str->index == 31)
    {
        extern void HDI_list_opened_files(void);

        HDI_list_opened_files();
    }
    else if (inject_str->index == 32)
    {
        extern void HDI_reset_number_opened_files(void);

        HDI_reset_number_opened_files();
    }
#endif /* defined(FILE_DEBUG_VERBOSE) && defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wap_ucs2_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcLen      [IN]        
 *  srcStr      [?]         
 *  dstStr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_ucs2_to_utf8(kal_uint16 srcLen, kal_uint8 *srcStr, char **dstStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *tempStr;
    long tempLen = 500, ucs2Len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2Len = (long)srcLen;
    tempStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen);
    memset(tempStr, 0, tempLen);
    msf_charset_ucs2le_to_utf8((const char*)srcStr, &ucs2Len, tempStr, &tempLen);
    *dstStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen + 1);
    strcpy(*dstStr, tempStr);
    MSF_MEM_FREE(MSF_MODID_MSM, tempStr);
    return (kal_uint16) tempLen;
}


/*****************************************************************************
 * FUNCTION
 *  wap_start_framework
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void wap_start_framework(void)
{
#if defined(READ_WAP_DEFAULT_FROM_CONST)
    if (HDIa_fileGetSizeDir(WAP_MSM_FILE_DIR) == HDI_FILE_ERROR_PATH)
    {
        /* first power on, so restore all wap setting */
        wap_action = WAP_ACTION_FIRST_POWER_ON;
        HDIa_fileMkDir(WAP_MSM_FILE_DIR);
        wap_read_factory_setting(0);
        wap_read_factory_setting(1);
        wap_reserve_file_space();
        wap_action = WAP_ACTION_NONE;
    }
    else
    {
        /* not first power on, restore common setting only -- registry.txt */
        wap_action = WAP_ACTION_POWER_ON;
        wap_read_factory_setting(0);
        wap_action = WAP_ACTION_NONE;
    }
#elif defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
    if (HDIa_fileGetSizeDir(WAP_MSM_FILE_DIR) == HDI_FILE_ERROR_PATH)
    {
        /* first power on, so restore all wap setting */
        wap_action = WAP_ACTION_FIRST_POWER_ON;
        HDIa_fileMkDir(WAP_MSM_FILE_DIR);
        wap_read_factory_setting(0);
        wap_read_factory_setting(1);
        wap_reserve_file_space();
        wap_action = WAP_ACTION_NONE;
    }
    else
    {
        wap_action = WAP_ACTION_NONE;
    }
#else
    if (HDIa_fileGetSizeDir(WAP_MSM_FILE_DIR) == HDI_FILE_ERROR_PATH)
    {
        /* first power on, so restore all wap setting */
        wap_action = WAP_ACTION_FIRST_POWER_ON;
        HDIa_fileMkDir(WAP_MSM_FILE_DIR);
    }
    else
    {
        /* not first power on, restore common setting only -- registry.txt */
        wap_action = WAP_ACTION_POWER_ON;
    }

    /* load factory setting first */
    wap_read_factory_setting(0);
#endif
    if (wap_status == WAP_RESET_COMPLETE)
    {
        MSF_start(KAL_TRUE, wap_ready_callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_fsm
 * DESCRIPTION
 *  (ilm_struct *ilm_ptr)
 *  This procedure is used to dispatch receiving message
 *  to message handler.
 * CALLS
 *  wap_fsm(ilm_struct *ilm_ptr)
 * PARAMETERS
 *  ilm_ptr     [IN]        First variable, used as input
 * RETURNS
 *  void
 *****************************************************************************/
void wap_fsm(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(WPS_SUPPORT) && !defined(WPS_TASK_SUPPORT)
    extern void wps_fsm(ilm_struct * ilm_ptr);
#endif

#if defined(__UNIFIED_MSG_SUPPORT__)
    extern void wap_um_msg_hdlr(ilm_struct * ilm_ptr);
  #if defined(__UNIFIED_COMPOSER_SUPPORT__)
    extern void wap_mma_msg_hdlr(ilm_struct *ilm_ptr);
  #endif
#endif 

#ifdef __MMI_MMS_BGSR_SUPPORT__
    extern void wap_bgsr_msg_hdlr(ilm_struct *ilm_ptr);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

    extern void wap_cca_msg_hdlr(ilm_struct *ilm_ptr);
    kal_bool is_shutdown_UI = KAL_FALSE;
#ifndef __MMI_DUAL_SIM__
    static kal_uint32 init_mask = MSG_MMI_EQ_POWER_ON_IND | MSG_MMI_READY_NOTIFY_REQ;
#else
    static kal_uint32 init_mask = MSG_MMI_EQ_POWER_ON_IND | MSG_MMI_READY_NOTIFY_REQ | MSG_WAP_SIM_INFO_NOTIFY_IND;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    HDIa_socketMsgHdlr(ilm_ptr);

#if defined(WPS_SUPPORT) && !defined(WPS_TASK_SUPPORT)
    wps_fsm(ilm_ptr);
#endif 

#ifdef __UNIFIED_MSG_SUPPORT__
    wap_um_msg_hdlr(ilm_ptr);
#endif 

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    wap_mma_msg_hdlr(ilm_ptr);
#endif 

#ifdef __MMI_MMS_BGSR_SUPPORT__
    wap_bgsr_msg_hdlr(ilm_ptr);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

    wap_cca_msg_hdlr(ilm_ptr);

    switch (ilm_ptr->msg_id)
    {
    #ifdef __SAT__
        case MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ:
            if (!MSF_wapIsReady())
            {
                bra_send_lauch_rsp_to_mmi(BRA_SAT_BRWOSER_BUSY);
            }
            else
            {
                char *url = NULL, *gateway = NULL, *bearer = NULL;
                kal_uint16 noUrl = 0, noGateway = 0, noBearer = 0;
                wap_mmi_lauch_browser_req_struct *lauch_p;

                lauch_p = (wap_mmi_lauch_browser_req_struct*) (ilm_ptr->local_para_ptr);

                /* convert bearer */
                if (lauch_p->noBearer > 0)
                {
                    noBearer = wap_ucs2_to_utf8(lauch_p->noBearer, lauch_p->bearer, &bearer);
                }

                /* convert url */
                if (lauch_p->noUrl > 0)
                {
                    noUrl = wap_ucs2_to_utf8(lauch_p->noUrl, lauch_p->url, &url);
                }

                /* covert gateway */
                if (lauch_p->noGateway > 0)
                {
                    noGateway = wap_ucs2_to_utf8(lauch_p->noGateway, lauch_p->gateway, &gateway);
                }

                BRAif_satLauchRequest(
                    lauch_p->browserMode,
                    lauch_p->browserIdentity,
                    (MSF_UINT8)lauch_p->sim_id,
                    noUrl,
                    (unsigned char*)url,
                    noBearer,
                    (unsigned char*)bearer,
                    noGateway,
                    (unsigned char*)gateway);

                MSF_MEM_FREE(MSF_MODID_MSM, bearer);
                MSF_MEM_FREE(MSF_MODID_MSM, url);
                MSF_MEM_FREE(MSF_MODID_MSM, gateway);
            }
            break;
    #endif /* __SAT__ */ 

        case MSG_ID_MMI_EQ_POWER_ON_IND:
            init_mask &= ~MSG_MMI_EQ_POWER_ON_IND;
            if (!init_mask && wap_status == WAP_RESET_COMPLETE && wap_action == WAP_ACTION_NONE)
            {
                wap_start_framework();
            }
            break;
        case MSG_ID_MMI_READY_NOTIFY_REQ:
            init_mask &= ~MSG_MMI_READY_NOTIFY_REQ;
            if (!init_mask && wap_status == WAP_RESET_COMPLETE && wap_action == WAP_ACTION_NONE)
            {
                wap_start_framework();
            }
            break;
#ifdef __MMI_DUAL_SIM__    
        case MSG_ID_WAP_SIM_INFO_NOTIFY_IND:
            {
                wap_sim_info_notify_ind_struct  *p = (wap_sim_info_notify_ind_struct*)ilm_ptr->local_para_ptr;

                sim_status = p->sim_status;
                sim_setting_mode = p->setting_mode;                

                if (msm_get_module_status(MSF_MODID_BRA) == MODULE_STATUS_ACTIVE)
                {                 
                    BRAif_handleSimInfoNotify((MSF_UINT8)p->sim_status, 
                                              (MSF_UINT8)p->setting_mode);
                }
                
                if (msm_get_module_status(MSF_MODID_MMS) == MODULE_STATUS_ACTIVE)
                {
                    MMSif_handleSimInfoNotify((MSF_UINT8)p->sim_status, 
                                              (MSF_UINT8)p->setting_mode);
                    mms_unread_check();                    
                }                
            }
            init_mask &= ~MSG_WAP_SIM_INFO_NOTIFY_IND;
            if (!init_mask && wap_status == WAP_RESET_COMPLETE && wap_action == WAP_ACTION_NONE)
            {
                wap_start_framework();
            }
            break;
#endif /* __MMI_DUAL_SIM__ */

        /* L4 IMSI response */
        case MSG_ID_MMI_SMU_GET_IMSI_RSP:
        {
            mmi_smu_get_imsi_rsp_struct* rsp_msg = (mmi_smu_get_imsi_rsp_struct*)(ilm_ptr->local_para_ptr);
            msf_registry_param_t param;
            kal_uint8 imsi_data[9];
            int i;

            if (rsp_msg->result == KAL_TRUE)
            {
                memset(imsi_data, 0, 9);

                /* convert IMSI (text format) to semi-octet */
                for (i=0; i<=8; i++)
                    imsi_data[i] = (kal_uint8)(rsp_msg->imsi[i*2]-'0') + (kal_uint8)((rsp_msg->imsi[i*2+1]-'0')<<4);
                imsi_data[8] = (kal_uint8)0xFF;

                /* fill in registry GET response struct */
                param.path = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, (MSF_UINT32)(strlen("/EXTERNAL")+1));
                strcpy(param.path, "/EXTERNAL");

                param.key = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, (MSF_UINT32)(strlen("NETW_SSD")+1));
                strcpy(param.key, "NETW_SSD");

                param.type = MSF_REGISTRY_TYPE_STR;
                param.value_bv_length = 9;
                param.value_bv = (unsigned char*)MSF_MEM_ALLOC(MSF_MODID_MSM, (MSF_UINT32)param.value_bv_length);
                memcpy(param.value_bv, imsi_data, param.value_bv_length);

                /* send response and free resources */
                MSMc_externalResponse((MSF_INT32)wap_external_get_id, &param);

                MSF_MEM_FREE(MSF_MODID_MSM, param.path);
                MSF_MEM_FREE(MSF_MODID_MSM, param.key);
                MSF_MEM_FREE(MSF_MODID_MSM, param.value_bv);
            }
            else
            {
                MSMc_externalResponse((MSF_INT32)wap_external_get_id, NULL);
            }
        }
            break;

        case MSG_ID_APP_SOC_BEARER_INFO_IND:
        {
            BRA_handleBearerInfo((void*)ilm_ptr->local_para_ptr);
        }
            break;
    #if !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
        case MSG_ID_NVRAM_READ_CNF:
        {
            msf_start_call_back_t callback = NULL;

            if (wap_factory_setting_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr) == NVRAM_EF_WAP_SETTING_LID)
            {
                if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
                {
                    wap_read_factory_setting(1);
                    break;
                }
                else if (wap_action == WAP_ACTION_POWER_ON)
                {
                    wap_action = WAP_ACTION_NONE;
                    callback = wap_ready_callback_func;
                }
            }
            else
            {
                if (wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
                {
                    wap_reserve_file_space();
                    wap_action = WAP_ACTION_NONE;
                    callback = wap_send_mmi_restore_factory_cnf;
                }
                else if (wap_action == WAP_ACTION_FIRST_POWER_ON)
                {
                    wap_reserve_file_space();
                    wap_action = WAP_ACTION_NONE;
                    callback = wap_ready_callback_func;
                }
            }
            if (wap_status == WAP_RESET_COMPLETE)
            {
                MSF_start(KAL_TRUE, callback);
            }
            break;
        }
    #endif /* !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK) */ 
        case MSG_ID_MMI_FMT_FORMAT_REQ:
            if (MSF_wapIsReady())
            {
                mmi_fmt_format_req_strcut *fmt_format_req = (mmi_fmt_format_req_strcut*) ilm_ptr->local_para_ptr;

                if (fmt_format_req->drive == (kal_uint8) HDI_FileGetDiskLabel(WAP_STORAGE_MMS))
                {
                    wap_action = WAP_ACTION_FMT_FORMAT;
                    wap_reset(INDX_WAP);
                }
                else
                {
                    wap_send_fmt_format_rsp();
                }
            }
            else
            {
                wap_send_fmt_format_rsp();
            }
            break;
        case MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ:
            if (!MSF_wapIsReady()
        #ifdef MMS_SUPPORT
                || isMMSBusy()
        #endif 
                )
            {
                wap_send_mmi_restore_factory_cnf();
                break;
            }
            wap_action = WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING;
            wap_reset(INDX_WAP);
            break;
        case MSG_ID_WAP_INTERNAL_ERROR_IND:
            wap_action = WAP_ACTION_RESET;
            wap_reset(INDX_WAP);
            break;
        case MSG_ID_WAP_BROWSER_STARTUP_REQ:
            /* Launch BRA UI */
            if (ilm_ptr->local_para_ptr == NULL)
            {
                BRAif_createUI(BRA_UI_MAIN_MENU, NULL);
            }
            else if (((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->type == WAP_BROWSER_GOTO_MAIN_MENU)
            {
                BRAif_createUI(BRA_UI_MAIN_MENU, NULL);
            }
            else if (((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->type == WAP_BROWSER_GOTO_HOMEPAGE)
            {
                BRAif_createUI(BRA_UI_HOMEPAGE, NULL);
            }
            else if (((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->type == WAP_BROWSER_GOTO_URL ||
                     ((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->type == WAP_BROWSER_GOTO_URL_BACKGROUND)
            {
                BRAif_createUI(
                    BRA_UI_GOTO_URL,
                    (const char*)(((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->url));
            }
            else if (((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->type == WAP_BROWSER_ADD_BOOKMARK)
            {
                BRAif_createUI(
                    BRA_UI_ADD_BOOKMARK,
                    (const char*)(((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->url));
            }
        #ifdef __UNIFIED_MSG_SUPPORT__
            else if (((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->type == WAP_BROWSER_VIEW_PUSH_MSG)
            {
                BRAif_viewPushMsg((MSF_UINT16) (((wap_browser_startup_req_struct*) ilm_ptr->local_para_ptr)->url[0]));
            }
        #endif /* __UNIFIED_MSG_SUPPORT__ */ 
            break;
        case MSG_ID_WAP_BROWSER_SHUTDOWN_REQ:
            if (wap_status != WAP_RUNNING)
        #ifdef __PRODUCTION_RELEASE__
                break;
        #else 
                ASSERT(0)
        #endif 
                    // wap_action = WAP_ACTION_SHUTDOWN;
                    // wap_reset(INDX_WAP);
                    is_shutdown_UI = KAL_TRUE;
            BRAif_destroyUI();
        /*
        #ifdef __J2ME__
            {
                extern void jas_display_progress_view(kal_bool is_open, int current, int total);

                jas_display_progress_view(KAL_FALSE, 0, 0);
            }
        #endif *//* __J2ME__ */ 
        #ifdef MMS_SUPPORT
            if (MSF_moduleIsRunning(MSF_MODID_MEA))
            {
                meaTerminateApp();
            }
        #endif /* MMS_SUPPORT */ 
            break;
        case MSG_ID_WAP_BROWSER_POWEROFF_REQ:
        {
            /*
             * Justin. Power off procedure
             * * Reference: wap_task_main
             */
            start_poweroff_watchdog();

            wap_action = WAP_ACTION_POWER_OFF;

            /* If WAP is currently running and is not in initialization process, then terminate WAP first. */
            if (wap_status == WAP_RUNNING && !MSF_wapIsInit())
            {
                wap_reset(INDX_WAP);
            }
            else
            {
                /* If wap task is not yet done with initialization, then do not perform termination
                   to avoid unexpected problems. Simply let the shutdown process continue. */
                wap_status = WAP_RESET_COMPLETE;
            }

            break;
            /* the subsequent MSF_fsm() might return prematurely
               before MSMa_terminated is executed if something is in the external queue */
        }
        case MSG_ID_TIMER_EXPIRY:
        {
            if (ilm_ptr->local_para_ptr == (void*)&widget_timer)
            {
                widget_timer_expiry(ilm_ptr);
                break;
            }
            else
            {
                kal_uint16 timer_indx = ((stack_timer_struct*) (ilm_ptr->local_para_ptr))->timer_indx;

                switch (timer_indx)
                {
                    case MSF_FILE_TIMER_ID:
                        HDI_file_timer_expiry(ilm_ptr);
                        break;
                    case MSF_MSM_TIMER_ID:
                        msf_timer_expiry_hdlr(ilm_ptr);
                        break;
                }
            }
            break;
        }
        case MSG_ID_WAP_DIAL_RSP:
            wtai_dial_call_rsp_hdlr(ilm_ptr);
            break;
        case MSG_ID_WAP_START_DTMF_RSP:
            wtai_send_dtmf_rsp_hdlr(ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WAP_SET_ENTRY_RSP:
            wtai_phb_add_entry_rsp_hdlr(ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_APP_SOC_DEACTIVATE_CNF:
        {
            app_soc_deactivate_cnf_struct *soc_deact_cnf_ptr;

            soc_deact_cnf_ptr = (app_soc_deactivate_cnf_struct*) ilm_ptr->local_para_ptr;
            /* if(soc_deact_cnf_ptr->result == KAL_TRUE) */
            {
                BRAa_setBearerState(SOC_DEACTIVATED);
                /*
                 * The data account info shall not be cleared because the new
                 * bearer request may be early than deactivate confirm
                 */
                /* HDIa_socketTermBearer(); */
            }
            wtai_dial_call_req_hdlr();
        }
            break;
        case MSG_ID_WAP_PROF_ACCESS_REQ:
            wap_prof_access_hdlr(ilm_ptr);
            break;
        case MSG_ID_WAP_MMI_READY_IND:
            bra_psl_unread_check();
            break;

            /* KEY */
        case MSG_ID_WAP_MMI_KEY_INDICATION:
            widget_wap_mmi_key_ind(ilm_ptr);
            break;

            /* RPC (remote procedure call) */
        case MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ:
            widget_mmiapi_remote_proc_call_req(ilm_ptr);
            break;

        case MSG_ID_WAP_BEARER_STATUS_IND:
            BRAif_handleBearerStatus(
                ((wap_bearer_status_ind_struct*)ilm_ptr->local_para_ptr)->bearer_type,
                ((wap_bearer_status_ind_struct*)ilm_ptr->local_para_ptr)->status);
            break;

        case MSG_ID_WAP_SELECT_BOOKMARK_REQ:
            BRAif_selectBookmark(0xFF);
            break;

        case MSG_ID_MMI_DA_DOWNLOAD_INFO_IND:
            BRA_handleDAinfo((void*)ilm_ptr->local_para_ptr);
            break;

    #if 0   /* Deprecated */
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
    #endif /* 0 */ /* WAP_SUPPORT */

    #if defined(__TCPIP__) && defined(WAP_SUPPORT)
            /*
             * for supporting provisioning of CSD/GPRS setting
             */

    #ifdef __CS_SERVICE__
            /* CSD */
        case MSG_ID_MMI_CC_SET_CSD_PROFILE_RSP:
            bra_prs_set_gsm_profile_rsp(ilm_ptr->local_para_ptr);
            break;

        case MSG_ID_MMI_CC_GET_FREE_CSD_PROFILE_NUM_RSP:
            bra_prs_get_free_gsm_profile_rsp(ilm_ptr->local_para_ptr);
            break;
    #endif /* __CS_SERVICE__ */ 

    #ifdef __PS_SERVICE__
            /* GPRS */
        case MSG_ID_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP:
            bra_prs_set_gprs_profile_rsp(ilm_ptr->local_para_ptr);
            break;

        case MSG_ID_MMI_PS_GET_GPRS_EMPTY_PROFILE_RSP:
            bra_prs_get_free_gprs_profile_rsp(ilm_ptr->local_para_ptr);
            break;
    #endif /* __PS_SERVICE__ */ 

    #endif /* defined(__TCPIP__) && defined(WAP_SUPPORT) */ 

    #ifdef MMS_SUPPORT
        case MSG_ID_MEA_STARTUP_REQ:
            MSMc_startModule(MSF_MODID_MEA, "-mode menu");
            break;
        case MSG_ID_MEA_STARTUP_NEW_MMS_REQ:
        {
            mea_new_mms_req_struct *local_data = (mea_new_mms_req_struct*) ilm_ptr->local_para_ptr;
            mms_content_entry_struct_peer_buf *peer_pdu = NULL;
            MSF_UINT16 peer_pdu_len = 0;

            if (local_data->mode == MEA_NEW_FILE)
            {
                MEAc_startWithContentInserted((char*)local_data->commandInfo);
                meaMeRegisterExitCallback((func_ptr)local_data->funcPtr, local_data->funcParam);
            }
            else if (local_data->mode == MEA_NEW_BUFFER)
            {
                if (ilm_ptr->peer_buff_ptr)
                {
                    peer_pdu = (mms_content_entry_struct_peer_buf*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &peer_pdu_len);
                }

                MEAc_startWithTextInserted((char *)local_data->commandInfo, (char *)peer_pdu, local_data->isContentTruncated);
            }
            else if (local_data->mode == MEA_NEW_ADDRESS)
            {
                char *meaNewCmd;    /* [56]; */
                int size;
                char *strAddress;

                size = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8*)local_data->commandInfo) + 1;
                strAddress = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
                widget_ucs2_to_utf8_string(
                    (kal_uint8*) strAddress,
                    size + 1,
                    (const kal_uint8*)local_data->commandInfo);

                //memset(meaNewCmd, 0x00, 56);  /* maximum phone number is 40. Notice: e-mail address will overflow*/
                //sprintf(meaNewCmd,"%s%lx\n","-mode new -to ", msgId);
                meaNewCmd = msf_cmmn_strcat(MSF_MODID_MSM, "-mode new -to ", (const char*)strAddress);
                MSMc_startModule(MSF_MODID_MEA, meaNewCmd);
                MSF_MEM_FREE(MSF_MODID_MSM, strAddress);
                MSF_MEM_FREE(MSF_MODID_MSM, meaNewCmd);
            }
            else if (local_data->mode == MEA_NEW_GENERAL)
            {
                if (ilm_ptr->peer_buff_ptr)
                {
                    peer_pdu = (mms_content_entry_struct_peer_buf*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &peer_pdu_len);
                }
        
                MEAc_startWithGeneralInserted((char *)peer_pdu->subject, (char *)peer_pdu->text_buffer, local_data->isContentTruncated, (char *)peer_pdu->addr, (char *)local_data->commandInfo);
                meaMeRegisterExitCallback((func_ptr)local_data->funcPtr, local_data->funcParam);
            }
            break;
        }

    #ifdef __UNIFIED_MSG_SUPPORT__
        case MSG_ID_MEA_UM_ENTRY_REQ:
        {
            mea_um_entry_req_struct *local_data = (mea_um_entry_req_struct*) ilm_ptr->local_para_ptr;

            switch ((MeaUmEntryTypeEnum) local_data->mode)
            {
                case MEA_UM_ENTRY_WRITE_MSG:
                    MEAif_createMessage(MSF_MODID_MSM);
                    break;
                case MEA_UM_ENTRY_READ_MSG:
                    MEAif_readMessage(MSF_MODID_MSM, local_data->msg_box, local_data->msg_index);
                    break;
                case MEA_UM_ENTRY_TEMPLATE:
                    MEAif_enterTemplate(MSF_MODID_MSM);
                    break;
                case MEA_UM_ENTRY_SETTING:
                    MEAif_enterSetting(MSF_MODID_MSM);
                    break;
                default:
                    ASSERT(0);
            }
            break;
        }
    #endif /* __UNIFIED_MSG_SUPPORT__ */ 

    #ifdef __USB_IN_NORMAL_MODE__
        case MSG_ID_MMS_ENTER_USB_MODE_REQ:
        {
            wap_send_mmi_mms_enter_usb_mode_rsp();
            break;
        }
        case MSG_ID_MMS_EXIT_USB_MODE_REQ:
        {
            if (is_mms_storage_exported_to_pc())    /* Check if MMS was disabled */
            {
                mmsImmediateRetrievalGet();
                HDIa_fileHideDir("/mms/");
            }
            wap_send_mmi_mms_exit_usb_mode_rsp();
            break;
        }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

        case MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ:
        {
            mms_get_attachment_req_struct *local_data = (mms_get_attachment_req_struct*) ilm_ptr->local_para_ptr;

            if (local_data->filename == NULL || msm_get_module_status(MSF_MODID_SMA) != MODULE_STATUS_ACTIVE)
            {
                wap_send_j2me_mms_get_active_mms_attachment_rsp(FALSE, NULL);
            }
            else
            {
                char *filename = NULL;
                char *vFileName = NULL;
                int size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) local_data->filename);

                filename = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);

                widget_ucs2_to_utf8_string((kal_uint8*) filename, size + 1, (const kal_uint8*)local_data->filename);
                if ((vFileName = SMAlib_getAttachment(filename)) != NULL)
                {
                    unsigned char *externalVFileName = NULL;

                    externalVFileName = HDI_FileNameTranslate(vFileName);
                    wap_send_j2me_mms_get_active_mms_attachment_rsp(TRUE, (kal_wchar*) externalVFileName);
                    HDI_FileNameFree(externalVFileName);
                    MSF_MEM_FREE(MSF_MODID_SMA, vFileName);
                }
                else
                {
                    wap_send_j2me_mms_get_active_mms_attachment_rsp(FALSE, NULL);
                }
            }
            break;
        }

            /* For MMC module */
    #ifdef MMSAT_SUPPORT
        case MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND:
        {
            wap_mmc_read_folder_status_req_ind_struct *local_data =
                (wap_mmc_read_folder_status_req_ind_struct*) ilm_ptr->local_para_ptr;
            wap_mmc_read_folder_status_req_ind_hldr(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data);
            break;
        }
        case MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND:
        {
            wap_mmc_upload_msg_req_ind_struct *local_data =
                (wap_mmc_upload_msg_req_ind_struct*) ilm_ptr->local_para_ptr;
            wap_mmc_upload_msg_req_ind_hldr(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data);
            break;
        }
        case MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND:
        {
            wap_mmc_delete_msg_req_ind_struct *local_data =
                (wap_mmc_delete_msg_req_ind_struct*) ilm_ptr->local_para_ptr;
            wap_mmc_delete_msg_req_ind_hldr(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data);
            break;
        }
        case MSG_ID_WAP_MMC_SEND_APPMMS_REQ:
        {
            kal_uint8 *pdu = NULL;
            kal_uint16 pdu_len = 0;
            wap_mmc_send_appmms_req_struct *local_data = (wap_mmc_send_appmms_req_struct*) ilm_ptr->local_para_ptr;

            pdu = (kal_uint8*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_len);
            ASSERT(pdu_len);
            wap_mmc_handle_send_appmms_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data, pdu, pdu_len);
            break;
        }
        case MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES:
        {
            wap_mmc_post_appmms_msg_part_res_struct *local_data =
                (wap_mmc_post_appmms_msg_part_res_struct*) ilm_ptr->local_para_ptr;
            wap_mmc_handle_post_appmms_msg_part_res(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data);
            break;
        }
        case MSG_ID_WAP_MMC_RECV_APPMMS_REQ:
        {
            wap_mmc_recv_appmms_req_struct *local_data = (wap_mmc_recv_appmms_req_struct*) ilm_ptr->local_para_ptr;

            *(local_data->app_id + local_data->app_id_len) = '\0';
            wap_mmc_handle_recv_appmms_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id, (MSF_INT8*) local_data->app_id);
            break;
        }
        case MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ:
        {
            wap_mmc_handle_read_appmms_msg_part_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id);
            break;
        }
        case MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ:
        {
            wap_mmc_cfg_appmms_appid_req_struct *local_data =
                (wap_mmc_cfg_appmms_appid_req_struct*) ilm_ptr->local_para_ptr;
            wap_mmc_handle_cfg_appmms_appid_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data);
            break;
        }
        case MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ:
        {
            wap_mmc_check_appmms_coming_req_struct *local_data =
                (wap_mmc_check_appmms_coming_req_struct*) ilm_ptr->local_para_ptr;
            wap_mmc_handle_check_appmms_coming_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data);
            break;
        }
        case MSG_ID_WAP_MMC_GET_MMS_PROF_REQ:
        {
            wap_mmc_get_mms_prof_req_struct *local_data = (wap_mmc_get_mms_prof_req_struct*) ilm_ptr->local_para_ptr;

            wap_mmc_handle_get_mms_prof_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id, local_data->access_id);
            break;
        }
        case MSG_ID_WAP_MMC_ABORT_APPMMS_REQ:
        {
            wap_mmc_handle_abort_appmms_req(ilm_ptr->src_mod_id, ilm_ptr->sap_id);
            break;
        }
    #endif /* MMSAT_SUPPORT */ 
    #endif /* MMS_SUPPORT */ 

        case MSG_ID_TST_INJECT_STRING:
        {
            tst_inject_string_struct *inject_str = (tst_inject_string_struct*) (ilm_ptr->local_para_ptr);

            wap_proc_inject_string(inject_str);
            break;
        }

        case MSG_ID_WAP_GET_PROF_LIST_REQ:
        {
            wap_get_prof_list_req_hdlr(ilm_ptr->src_mod_id);
            break;
        }

        case MSG_ID_WAP_GET_PROF_CONTENT_REQ:
        {
            wap_get_prof_content_req_hdlr(
                (wap_get_prof_content_req_struct*) ilm_ptr->local_para_ptr,
                ilm_ptr->src_mod_id);
            break;
        }

        case MSG_ID_WAP_GET_BRA_PROF_ID_REQ:
        {
            wap_get_bra_prof_id_req_hdlr(ilm_ptr->src_mod_id);
            break;
        }
        case MSG_ID_WAP_STATUS_UPDATE_IND:
        {
            /*
             * Before WAP receives this message, MMI doesn't need send it again.
             * We don't need the mutex to protect the variable because MMI task
             * and WAP task have the same priority and won't access the variable
             * at the same time.
             */
            widget_check_play_waiting_sound();
            WIPC_CTX->update_event_is_sent = 0;
            break;
        }
	    case MSG_ID_WAP_GET_USER_AGENT_REQ:
	    {
            extern void wap_get_user_agent_req_hdlr(module_type req_src_id);
            wap_get_user_agent_req_hdlr(ilm_ptr->src_mod_id);
            break;
	    }


#ifdef BRA_CFG_CCA
        case MSG_ID_MMI_CCA_APP_CONFIGURE_IND:
        {
            mmi_cca_app_configure_ind_struct  *ind;

            ind = (mmi_cca_app_configure_ind_struct*)ilm_ptr->local_para_ptr;
            BRAif_CcaAppConfigure((MSF_UINT16)ind->sim_id,
                                  (MSF_UINT16)ind->config_id,
                                  (MSF_INT32)ind->hConfig,
                                  (MSF_INT32)ind->num_symbols,
                                  (MSF_UINT16 *)ind->l1symbols,
                                  (MSF_INT32 *)ind->l1symbols_count);
            break;
        }

        case MSG_ID_MMI_CCA_APP_GET_PROF_IND:
        {
            mmi_cca_app_get_prof_ind_struct  *ind;

            ind = (mmi_cca_app_get_prof_ind_struct*)ilm_ptr->local_para_ptr;
            BRAif_CcaGetProfile((MSF_UINT16)ind->sim_id,
                                (MSF_UINT16)ind->app_id,
                                (MSF_INT32)ind->prof_id);
            break;
        }

        case MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND:
        {
            mmi_cca_app_update_prof_ind_struct *ind;

            ind = (mmi_cca_app_update_prof_ind_struct*)ilm_ptr->local_para_ptr;
            BRAif_CcaUpdateProfile((MSF_UINT16)ind->sim_id,
                                   (MSF_UINT16)ind->app_id,
                                   (MSF_INT32)ind->prof_id,
                                   (MSF_INT32)ind->hConfig);
            break;
        }
#endif /*BRA_CFG_CCA*/
        
#ifdef BRA_CFG_USE_DTCNT_SELECT_SCREEN
        case MSG_ID_MMI_PS_DTCNT_LIST_RSP:
        {
            mmi_ps_dtcnt_list_rsp_struct  *rsp;

            rsp = (mmi_ps_dtcnt_list_rsp_struct*)ilm_ptr->local_para_ptr;
            BRAif_handleNetIdSelectResponse((MSF_BOOL)rsp->result,
                                            (MSF_UINT16)rsp->app_id,
                                            (MSF_UINT32)rsp->num_id,
                                            (MSF_UINT32)rsp->bearer_scope,
                                            (MSF_UINT32*)rsp->bearer_type,
                                            (MSF_UINT32*)rsp->net_id);
            break;

        }
#endif /*BRA_CFG_USE_DTCNT_SELECT_SCREEN*/


        case MSG_ID_MMI_CBM_ALWAYS_ASK_SELECT_ACCOUNT_RESULT_IND:
        {
            mmi_cbm_always_ask_select_account_result_ind_struct *p;

            
            p = (mmi_cbm_always_ask_select_account_result_ind_struct*)ilm_ptr->local_para_ptr;
            BRAif_cbmSelectResult((MSF_UINT32)p->acct_id, 
                                  (MSF_BOOL)p->result);
            break;
        }

        case MSG_ID_MMI_CBM_ADD_BEARER_STATUS_NOTIFY_CNF:
        {
            mmi_cbm_add_bearer_status_notify_cnf_struct *p;


            p = (mmi_cbm_add_bearer_status_notify_cnf_struct*)ilm_ptr->local_para_ptr;
               
            BRAif_cbmAddBearerStatusNotify((MSF_UINT8)p->index, 
                                           (MSF_BOOL)p->result);
            break;
         }

        case MSG_ID_MMI_CBM_DEL_BEARER_STATUS_NOTIFY_CNF:
        {
             mmi_cbm_del_bearer_status_notify_cnf_struct *p;


             p = (mmi_cbm_del_bearer_status_notify_cnf_struct*)ilm_ptr->local_para_ptr;
              
             BRAif_cbmDelBearerStatusNotify((MSF_UINT32)p->acct_id, 
                                            (MSF_BOOL)p->result);
             break;
        }

        case MSG_ID_MMI_CBM_BEARER_STATUS_NOTIFY_IND:
        {
             mmi_cbm_bearer_status_notify_ind_struct *p;


             p = (mmi_cbm_bearer_status_notify_ind_struct*)ilm_ptr->local_para_ptr;
               
             BRAif_cbmDelBearerStatusNotify((MSF_UINT32)p->acct_id,
                                            (MSF_UINT32)p->status);
             break;
        }
        default:
            das_handle_message(ilm_ptr);
            break;
    }
    free_ilm(ilm_ptr);
    if (wap_status != WAP_RESET_COMPLETE)
    {
        MSF_fsm();  /* process MSF signal */
    }

    if (is_shutdown_UI)
    {
        /* Finish processing WAP internal queue */
        widget_notify_shutdown_UI_finished();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_restart_task
 * DESCRIPTION
 *  This function is used to restart WAP when internal state is incorrect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_restart_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(++restart_count < 5); */
    longjmp(wap_jmpbuf, 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_int_queue_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 wap_get_int_queue_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wap_int_q_size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_is_int_q_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wap_is_int_q_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wap_int_q_size == WAP_INT_QUEUE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  wap_read_int_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wap_read_int_q(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_int_q_size == 0)
    {
        return KAL_FALSE;
    }

    memcpy(ilm, wap_int_q_array + wap_int_q_read_index, sizeof(ilm_struct));

    if (ilm->msg_id == MSG_ID_TIMER_EXPIRY)
    {
        wap_is_timer_msg_in_int_q = KAL_FALSE;
    }

    wap_int_q_read_index++;
    if (wap_int_q_read_index == WAP_INT_QUEUE_SIZE)
    {
        wap_int_q_read_index = 0;
    }
    wap_int_q_size--;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_int_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wap_write_int_q(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_int_q_size == WAP_INT_QUEUE_SIZE)
    {
        return KAL_FALSE;
    }

    memcpy(wap_int_q_array + wap_int_q_write_index, ilm, sizeof(ilm_struct));
    wap_int_q_write_index++;
    if (wap_int_q_write_index == WAP_INT_QUEUE_SIZE)
    {
        wap_int_q_write_index = 0;
    }
    wap_int_q_size++;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fetch_msg_to_int_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_fetch_msg_to_int_q(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_get_queue_size() > WIDGET_QUEUE_SIZE_HIGH_WATERMARK)
    {
        /* Try to get the message from external queue to internal queue */
        while (!wap_is_int_q_full() && wap_get_queue_size())
        {
            receive_msg_ext_q(wap_ext_qid, &current_ilm);

            if (current_ilm.msg_id == MSG_ID_TIMER_EXPIRY)
            {
                if (wap_is_timer_msg_in_int_q == KAL_FALSE)
                {
                    /* There is no timer_expiry msg in intQ */
                    wap_write_int_q(&current_ilm);
                    wap_is_timer_msg_in_int_q = KAL_TRUE;
                }
                else
                {
                    /* drop timer_expiry msg because there is one msg in intQ */
                    stack_is_time_out_valid(&widget_timer);
                    stack_process_time_out(&widget_timer);
                }
            }
            else
            {
                wap_write_int_q(&current_ilm);
                hold_local_para(current_ilm.local_para_ptr);
                hold_peer_buff(current_ilm.peer_buff_ptr);
            }
            free_ilm(&current_ilm);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_queue_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_get_queue_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 queue_node_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_get_ext_queue_info(wap_ext_qid, &queue_node_number);

    return queue_node_number;
}


/*****************************************************************************
 * FUNCTION
 *  wap_task_main
 * DESCRIPTION
 *  This function is used to be WAP task entry point
 * CALLS
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wap_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

#ifdef WAP_QUEUE_SMS_PUSH
    {
        extern void HDI_registerSmsPush(void);

        HDI_registerSmsPush();
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

    msm_remove_files_under_dir(WAP_DOWNLOAD_FOLDER);

    memset(wap_int_q_array, 0, sizeof(ilm_struct) * WAP_INT_QUEUE_SIZE);
    wap_ext_qid = task_info_g[task_entry_ptr->task_indx].task_ext_qid;

    while (1)
    {
        widget_waiting_external_queue();
        if (wap_get_int_queue_size() == 0)
        {
            receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        }
        else
        {
            wap_read_int_q(&current_ilm);
        }
        widget_finish_external_queue();

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        if (setjmp(wap_jmpbuf) == 0)
        {
            wap_fsm(&current_ilm);  /* process external ILM */
        }
        else
        {
        #ifdef WPS_TASK_SUPPORT
            /* force the mutex owner to release because the control is out from Msf_fsm and Msf_wps_fsm */
            extern kal_mutexid wap_ctrl_mutex;
            extern kal_bool wap_in_critical_section;
            
            if(wap_in_critical_section == KAL_TRUE)
            {
                kal_give_mutex(wap_ctrl_mutex);
            }
        #endif /* WPS_TASK_SUPPORT */ 
            if (wap_action == WAP_ACTION_POWER_OFF)
            {
                /*
                 * exception happen in the last termination procedure invoked in wap_fsm()
                 * * We shall NOT call MSMc_terminateMobileSuite because it might become
                 * * infinite loop
                 */
                break;
            }

            /* Exception happen so terminate Mobile Suite */
            wap_action = WAP_ACTION_RESET;
            wap_reset(task_entry_ptr->task_indx);
            MSF_fsm();
        }

        if (wap_status == WAP_RESET_COMPLETE)
        {
            /* Note that MSMa_terminated and wap_deinit was called before this point */
            if (wap_action == WAP_ACTION_POWER_OFF)
            {
                break;  /* We don't restart WAP again */
            }
            else if (wap_action == WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING)
            {
                wap_delete_all_files(); /* delete all wap related files for restore factory setting */
                wap_action = WAP_ACTION_NONE;
                wap_send_mmi_restore_factory_cnf();
                break;
            }
            else if (wap_action == WAP_ACTION_SHUTDOWN)
            {
                wap_init(task_entry_ptr->task_indx);
                MSF_start(KAL_FALSE, NULL);
                MSF_fsm();
            }
            else if (wap_action == WAP_ACTION_FMT_FORMAT)
            {
                wap_init(task_entry_ptr->task_indx);
                MSF_start(KAL_TRUE, wap_send_fmt_format_rsp);
                MSF_fsm();
            }
            else if (wap_action == WAP_ACTION_RESET)
            {
				/* If browser is shutting down, don't invoke BRAif_createUI to display dialog
				   which will cause a deadlock of widget */
				if(widget_is_shutdown_UI() == 1)  /* Must called first because the flag will be reset by wap_init */
				{
					wap_init(task_entry_ptr->task_indx);
					MSF_start(KAL_FALSE, NULL);
					MSF_fsm();
				}
				else
				{
					wap_init(task_entry_ptr->task_indx);
					MSF_start(KAL_FALSE, NULL);
					MSF_fsm();
					BRAif_createUI(BRA_UI_RESET_COMPL, NULL);
					MSF_fsm();
				}
            }
        }
    }

    /*
     * Power off at this point
     * * it is critical to tell MMI that WAP is completed
     * * otherwise MMI will not finish the poweroff procedure
     */
    notifiy_mmi_wap_poweroff_completed();

    /*
     * dummy loop
     * * We don't want busy wait here
     */
    for (;;)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_create
 * DESCRIPTION
 *  This function is used to create CC task
 * CALLS
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct ms_handler_info = 
    {
        wap_task_main,  /* task entry function */
        wap_init,       /* task initialization function */
        NULL,           /* task configuration function */
        NULL,           /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & ms_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_support_background_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
int wap_support_background_image(void)
{
    /* 
     * WAP_CUSTOM_CFG_SUPPORT_BACKGROUND_IMAGE is defined in custom_wap_config.h
     * 
     * WAP supports background image has the defect.
     * The marquee donesn't work well when enable backgound image.
     * The marguee's background color is white and overlap the background image.
     */
#ifdef WAP_CUSTOM_CFG_SUPPORT_BACKGROUND_IMAGE
    return 1;
#else
    return 0;
#endif
}



/* __CUSTPACK_MULTIBIN     Johnnie   BEGIN */


/*****************************************************************************
 * FUNCTION
 *  wap_write_profile_entry
 * DESCRIPTION
 *  This function is used to the default value of each profile item of a profile
 * CALLS
 *  
 * PARAMETERS
 *  profile         [?]         
 *  entry           [?]         
 *  type            [IN]        
 *  profile_idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_write_profile_entry(kal_uint8 *profile, kal_uint8 *entry, kal_uint8 type, kal_uint8 profile_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 size = 0;
    kal_uint16 entry_len = strlen((char*)entry) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry_len == 1)
    {
        return 0;
    }

    profile[size++] = 0xff;
    profile[size++] = (kal_uint8) ((entry_len + 5) >> 8);
    profile[size++] = (kal_uint8) ((entry_len + 5) & 0x00ff);
    profile[size++] = 0x01;
    profile[size++] = profile_idx;
    profile[size++] = type;
    profile[size++] = (kal_uint8) ((entry_len) >> 8);
    profile[size++] = (kal_uint8) ((entry_len) & 0x00ff);
    memcpy(profile + size, entry, entry_len);
    size += entry_len;
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fill_profile
 * DESCRIPTION
 *  This function is used to the default value of a profile
 * CALLS
 *  
 * PARAMETERS
 *  profile         [IN]        
 *  profile_idx     [IN]        
 *  profile_raw     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_fill_profile(
            const custom_profile_content_struct *profile,
            kal_uint8 profile_idx,
            kal_uint8 *profile_raw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 size = 0;
    kal_uint16 add = 0;
    kal_uint8 *profile_entry = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, 256);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* proxy port */
    kal_sprintf((char*)profile_entry, "%d", profile->proxy_port);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_PROXY_PORT, profile_idx);
    size += add;

    /* profile name */
    kal_sprintf((char*)profile_entry, "%s", profile->profile_name);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_PROFILE_NAME, profile_idx);
    size += add;

    /* homepage url */
    kal_sprintf((char*)profile_entry, "%s", profile->homepage_url);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_HOMEPAGE_URL, profile_idx);
    size += add;

    /* data account */
    kal_sprintf((char*)profile_entry, "%d", profile->data_account);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_DATA_ACCOUNT, profile_idx);
    size += add;

    /* connection type */
    kal_sprintf((char*)profile_entry, "%d", profile->conn_type);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_CONN_TYPE, profile_idx);
    size += add;

    /* proxy IP */
    kal_sprintf(
        (char*)profile_entry,
        "%u.%u.%u.%u",
        profile->proxy_ip[0],
        profile->proxy_ip[1],
        profile->proxy_ip[2],
        profile->proxy_ip[3]);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_PROXY_IP, profile_idx);
    size += add;

    /* username */
    kal_sprintf((char*)profile_entry, "%s", profile->username);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_USERNAME, profile_idx);
    size += add;

    /* password */
    kal_sprintf((char*)profile_entry, "%s", profile->password);
    add = wap_write_profile_entry(profile_raw + size, profile_entry, CUSTOM_WAP_PROFILE_PASSWORD, profile_idx);
    size += add;

    MSF_MEM_FREE(MSF_MODID_MSM, profile_entry);
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_bkm_entry
 * DESCRIPTION
 *  This function is used to the default value of each bookmark item of a bookmark
 * CALLS
 *  
 * PARAMETERS
 *  bkm         [?]         
 *  name        [?]         
 *  url         [?]         
 *  idx         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_write_bkm_entry(kal_uint8 *bkm, kal_uint8 *name, kal_uint8 *url, kal_uint32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 size = 0;
    kal_uint8 name_len = strlen((char*)name) + 1;
    kal_uint16 url_len = strlen((char*)url) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url_len == 1)
    {
        return 0;
    }

    bkm[size++] = 0xff;
    bkm[size++] = (kal_uint8) ((name_len + url_len + 7) >> 8);
    bkm[size++] = (kal_uint8) ((name_len + url_len + 7) & 0x00ff);
    bkm[size++] = idx >> 24;
    bkm[size++] = (kal_uint8) ((idx & 0x00ff0000) >> 16);
    bkm[size++] = (kal_uint8) ((idx & 0x0000ff00) >> 8);
    bkm[size++] = (kal_uint8) (idx & 0x000000ff);
    bkm[size++] = name_len;
    memcpy(bkm + size, name, name_len);
    size += name_len;
    bkm[size++] = (kal_uint8) (url_len >> 8);
    bkm[size++] = (kal_uint8) (url_len & 0x00ff);
    memcpy(bkm + size, url, url_len);
    size += url_len;
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fill_bkm
 * DESCRIPTION
 *  This function is used to the default value of a bookmark
 * CALLS
 *  
 * PARAMETERS
 *  bkm     [IN]        
 *  idx     [IN]        
 *  raw     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_fill_bkm(const custom_bkm_content_struct *bkm, kal_uint8 idx, kal_uint8 *raw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 size = 0;
    kal_uint8 *bkm_name = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, CUSTOM_WAP_BKM_TITLE_LEN);
    kal_uint8 *bkm_url = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, CUSTOM_WAP_BKM_URL_LEN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bkm title */
    kal_sprintf((char*)bkm_name, "%s", bkm->bkm_name);
    kal_sprintf((char*)bkm_url, "%s", bkm->bkm_url);
    size = wap_write_bkm_entry(raw, bkm_name, bkm_url, (kal_uint32) idx);

    MSF_MEM_FREE(MSF_MODID_MSM, bkm_name);
    MSF_MEM_FREE(MSF_MODID_MSM, bkm_url);
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_bkm_entry
 * DESCRIPTION
 *  This function is used to the default value of each trust list item
 * CALLS
 *  
 * PARAMETERS
 *  bkm         [?]         
 *  name        [?]         
 *  url         [?]         
 *  idx         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_write_trustList_entry(kal_uint8 *tl, kal_uint32 type, kal_uint8 *address, kal_uint32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16  size = 0;
    kal_uint8   address_len = strlen((char*)address) + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address_len == 1)
    {
        return 0;
    }

    tl[size++] = 0xff;
    tl[size++] = (kal_uint8) ((4 + 4 + address_len) >> 8);
    tl[size++] = (kal_uint8) ((4 + 4 + address_len) & 0x00ff);
    tl[size++] = idx >> 24;
    tl[size++] = (kal_uint8) ((idx & 0x00ff0000) >> 16);
    tl[size++] = (kal_uint8) ((idx & 0x0000ff00) >> 8);
    tl[size++] = (kal_uint8) (idx & 0x000000ff);
    tl[size++] = (kal_uint8) ((type & 0x00ff0000) >> 24);
    tl[size++] = (kal_uint8) ((type & 0x00ff0000) >> 16);
    tl[size++] = (kal_uint8) ((type & 0x0000ff00) >> 8);
    tl[size++] = (kal_uint8) (type & 0x000000ff);

    memcpy(tl + size, address, address_len);
    size += address_len;
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fill_trustList
 * DESCRIPTION
 *  This function is used to the default value of a trust list
 * CALLS
 *  
 * PARAMETERS
 *  bkm     [IN]        
 *  idx     [IN]        
 *  raw     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_fill_trustList(const custom_trustList_content_struct *tl, kal_uint8 idx, kal_uint8 *raw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 size = 0;
    kal_uint8 *tl_address = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, CUSTOM_WAP_TRUSTLIST_LEN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sprintf((char*)tl_address, "%s", tl->tl_address);
    size = wap_write_trustList_entry(raw, tl->tl_type, tl_address, (kal_uint32) idx);

    MSF_MEM_FREE(MSF_MODID_MSM, tl_address);
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_default
 * DESCRIPTION
 *  This function is used to the default value of WAP bookmark and WAP/MMS profile
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_write_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8       i;
    kal_int32       fd;
    kal_uint8       *raw;
    kal_uint32      size = 0;
    kal_uint32      add = 0;
    kal_int32       left_size;
    kal_int32       ret;
    kal_uint8       profile_idx = 0;
#ifdef __MMI_DUAL_SIM__
    kal_uint8       sim_num;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    raw = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, 1024);

    ret = HDIa_fileMkDir(WAP_BRA_FILE_DIR);
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
        ASSERT(0)
#endif 
            fd = HDIa_fileOpen(
                    MSF_MODID_MSM,
                    (char*)BRA_CFG_PROFILE_FILE_PATH,
                    HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                    0);

    if (fd < 0)
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
        ASSERT(0);
#endif 

#ifdef __MMI_DUAL_SIM__
    for(sim_num = 0; sim_num < BRA_CFG_MAX_SIM_NUM; sim_num++)
    {
#endif
    for (i = 0; i < CUST_WAP_PROFILE_DEFAULT->n_wap_profiles; i++)
    {
        if (CUST_WAP_PROFILE_DEFAULT->profile[i].empty == 1)
        {
            continue;
        }

        profile_idx = i;
#ifdef __MMI_DUAL_SIM__
        profile_idx += sim_num * BRA_CFG_N_PROFILES;
#endif
        add = wap_fill_profile(&(CUST_WAP_PROFILE_DEFAULT->profile[i]), profile_idx, raw);
        ret = HDIa_fileWrite(fd, raw, add);
        if (ret != add)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0);
    #endif 
        size += add;
    }

#ifdef MMS_SUPPORT
    for (i = 0; i < CUST_MMS_PROFILE_DEFAULT->n_mms_profiles; i++)
    {
        if (CUST_MMS_PROFILE_DEFAULT->profile[i].empty == 1)
        {
            continue;
        }

        profile_idx = i + BRA_CFG_N_WAP_PROFILES;
#ifdef __MMI_DUAL_SIM__
        profile_idx += sim_num * BRA_CFG_N_PROFILES;
#endif
        add = wap_fill_profile(
                &(CUST_MMS_PROFILE_DEFAULT->profile[i]),
                (kal_uint8) profile_idx,
                raw);
        ret = HDIa_fileWrite(fd, raw, add);
        if (ret != add)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0);
    #endif 
        size += add;
    }
#endif /* MMS_SUPPORT */ 

#ifdef __MMI_DUAL_SIM__
    } /* for(sim_num = 0; sim_num < BRA_CFG_MAX_SIM_NUM; sim_num++) */
#endif

    left_size = WAP_CUSTOM_CFG_PROFILE_FILE_SIZE - size - 3;
    if (left_size <= 0)
#ifdef __PRODUCTION_RELEASE__
      goto error;
#else 
      ASSERT(0);
#endif 

    raw[0] = 0xfe;
    raw[1] = (kal_uint8) ((left_size & 0x0000ff00) >> 8);
    raw[2] = (kal_uint8) (left_size & 0x000000ff);

    ret = HDIa_fileWrite(fd, raw, 3);
    if (ret != 3)
#ifdef __PRODUCTION_RELEASE__
        goto error;
#else 
        ASSERT(0)
#endif 
            kal_mem_set(raw, 0, 128);

    while (left_size > 0)
    {
        add = (left_size > 128) ? 128 : left_size;

        ret = HDIa_fileWrite(fd, raw, add);
        if (ret < 0)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0)
    #endif 
                left_size -= ret;
    }

    HDIa_fileClose(fd);
    size = 0;

    fd = HDIa_fileOpen(
            MSF_MODID_MSM,
            (char*)BRA_CFG_BOOKMARK_FILE_PATH,
            HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
            0);

    if (fd < 0)
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
        ASSERT(0);
#endif 

    for (i = 0; i < CUST_WAP_BKM_DEFAULT->max_n_bkms; i++)
    {
        if (CUST_WAP_BKM_DEFAULT->bkm[i].empty == 1)
        {
            continue;
        }

        add = wap_fill_bkm(&(CUST_WAP_BKM_DEFAULT->bkm[i]), i, raw);
        ret = HDIa_fileWrite(fd, raw, add);
        if (ret != add)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0);
    #endif 
        size += add;
    }

    left_size = WAP_CUSTOM_CFG_BOOKMARK_FILE_SIZE - size - 3;

    raw[0] = 0xfe;
    raw[1] = (kal_uint8) ((left_size & 0x0000ff00) >> 8);
    raw[2] = (kal_uint8) (left_size & 0x000000ff);

    ret = HDIa_fileWrite(fd, raw, 3);
    if (ret != 3)
#ifdef __PRODUCTION_RELEASE__
        goto error;
#else 
        ASSERT(0)
#endif 
            kal_mem_set(raw, 0, 128);

    while (left_size > 0)
    {
        add = (left_size > 128) ? 128 : left_size;

        ret = HDIa_fileWrite(fd, raw, add);
        if (ret < 0)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0)
    #endif 
                left_size -= ret;
    }

    HDIa_fileClose(fd);
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
    size = 0;
    
    fd = HDIa_fileOpen(
        MSF_MODID_MSM,
        (char*)BRA_CFG_TRUSTLIST_FILE_PATH,
        HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
        0);
    
    if (fd < 0)
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
    ASSERT(0);
#endif 
    
    for (i = 0; i < CUST_WAP_TRUSTLIST_DEFAULT->max_n_trustLists; i++)
    {
        if (CUST_WAP_TRUSTLIST_DEFAULT->trustList[i].empty == 1)
        {
            continue;
        }

        add = wap_fill_trustList(&(CUST_WAP_TRUSTLIST_DEFAULT->trustList[i]), i, raw);
        ret = HDIa_fileWrite(fd, raw, add);
        if (ret != add)
#ifdef __PRODUCTION_RELEASE__
            goto error;
#else 
        ASSERT(0);
#endif 
        size += add;
    }

    left_size = WAP_CUSTOM_CFG_TRUSTLIST_FILE_SIZE - size - 3;
    
    raw[0] = 0xfe;
    raw[1] = (kal_uint8) ((left_size & 0x0000ff00) >> 8);
    raw[2] = (kal_uint8) (left_size & 0x000000ff);
    
    ret = HDIa_fileWrite(fd, raw, 3);
    if (ret != 3)
#ifdef __PRODUCTION_RELEASE__
        goto error;
#else 
    ASSERT(0)
#endif 
        kal_mem_set(raw, 0, 128);
    
    while (left_size > 0)
    {
        add = (left_size > 128) ? 128 : left_size;
        
        ret = HDIa_fileWrite(fd, raw, add);
        if (ret < 0)
#ifdef __PRODUCTION_RELEASE__
            goto error;
#else 
        ASSERT(0)
#endif 
            left_size -= ret;
    }
    
    HDIa_fileClose(fd);
#endif

    goto open_error;

#ifdef __PRODUCTION_RELEASE__
  error:
#endif 
    HDIa_fileClose(fd);

  open_error:
    MSF_MEM_FREE(MSF_MODID_MSM, raw);
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_root_ca_default
 * DESCRIPTION
 *  This function is used to the default value of WAP pre-installed root ca
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_write_root_ca_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;
    kal_int32 fd;
    kal_uint8 *raw;
    kal_uint32 size = 0;
    kal_int32 ret;
    char filename[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    raw = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, 1024);

    ret = HDIa_fileMkDir(WAP_SEC_FILE_DIR);
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
        ASSERT(0)
#endif 
            ret = HDIa_fileMkDir(WAP_SEC_STORAGE_DIR);
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
        ASSERT(0)
#endif 
            sprintf(filename, "%s/S_%u", WAP_SEC_STORAGE_DIR, 0);
    fd = HDIa_fileOpen(
            MSF_MODID_MSM,
            (char*)filename,
            HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
            0);

    if (fd < 0)
#ifdef __PRODUCTION_RELEASE__
        goto open_error;
#else 
        ASSERT(0);
#endif 

    j = 0;

    for (i = 0; i < CUST_WAP_ROOT_CA_DEFAULT->n_root_ca; i++)
    {
        if (CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].empty == 1)
        {
            continue;
        }
        j++;

        raw[size++] = 0x43,
            raw[size++] = 0x00,
            raw[size++] = 0x00,
            raw[size++] = 0x00,
            raw[size++] = j,
            raw[size++] =
            (kal_uint8) (((CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content_len + 1) & 0xff000000) >> 24);
        raw[size++] = (kal_uint8) (((CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content_len + 1) & 0x00ff0000) >> 16);
        raw[size++] = (kal_uint8) (((CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content_len + 1) & 0x0000ff00) >> 8);
        raw[size++] = (kal_uint8) ((CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content_len + 1) & 0x000000ff);
    }

    ret = HDIa_fileWrite(fd, raw, size);
    if (ret != size)
#ifdef __PRODUCTION_RELEASE__
        goto error;
#else 
        ASSERT(0);
#endif 

    HDIa_fileClose(fd);
    size = 0;
    j = 0;

    for (i = 0; i < CUST_WAP_ROOT_CA_DEFAULT->n_root_ca; i++)
    {
        if (wap_root_ca_default.root_ca[i].empty == 1)
        {
            continue;
        }
        j++;

        sprintf(filename, "%s/S_%u", WAP_SEC_STORAGE_DIR, j);
        fd = HDIa_fileOpen(
                MSF_MODID_MSM,
                (char*)filename,
                HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                0);

        if (fd < 0)
    #ifdef __PRODUCTION_RELEASE__
            goto open_error;
    #else 
            ASSERT(0);
    #endif 
        raw[0] = 'C';
        raw[1] = CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_type;
        ret = HDIa_fileWrite(fd, raw, 2);
        if (ret != 2)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0);
    #endif 
        ret = HDIa_fileWrite(
                fd,
                (void*)CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content,
                CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content_len);
        if (ret != CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].root_ca_content_len)
    #ifdef __PRODUCTION_RELEASE__
            goto error;
    #else 
            ASSERT(0);
    #endif 
        HDIa_fileClose(fd);
    }

    goto open_error;

#ifdef __PRODUCTION_RELEASE__
  error:
#endif 
    HDIa_fileClose(fd);

  open_error:
    MSF_MEM_FREE(MSF_MODID_MSM, raw);
}

/* __CUSTPACK_MULTIBIN     Johnnie   END */

