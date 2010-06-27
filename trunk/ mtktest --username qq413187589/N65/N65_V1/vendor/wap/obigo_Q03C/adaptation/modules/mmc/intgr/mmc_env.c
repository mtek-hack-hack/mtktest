/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * mmc_env.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for PC suite MMS Composer.
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */

#ifdef MMSAT_SUPPORT

#ifdef MMS_SUPPORT

#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_pipe.h"   /* MSF: Pipe handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_errc.h"
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "mcpdu.h"
#include "msig.h"
#include "fldmgr.h"
#include "mconfig.h"
#include "QueueGprot.h" /* For send an primitive to L4 */
#include "msf_def.h"
#include "stack_msgs.h" /* Stack timer */
#include "stack_timer.h"        /* Stack timer */
#include "l4a.h"
#include "wapadp.h"
#include "wap_ps_struct.h"
#include "mmc_env.h"
#include "mmc_jsr.h"
#include "bra_prof.h"
#include "widget_extension.h"
#include "mea_def.h"

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#include "mma_if_wrapper.h"
#endif

const char *MMC_VERSION = "MmsComposer1.0";

static int mmc_inside_run = 0;
static jmp_buf mmc_jmpbuf;
static MSF_INT32 mmcTimerId = 1000;
static MSF_INT8 timer_state = IDLE;
static MSF_INT8 isMmsStartup = FALSE;

MmcContext mmsContext;
MmcContext *mmsContext_p = &mmsContext;
extern mmc_jsr_appid_info_struct *mmc_jsr_appId_db[MMC_MAX_JSR_APP_ID_NUM];
extern mmc_jsr_index_struct *mmc_jsr_msg_db;

/* External Functions */
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern int msm_get_module_status(MSF_UINT8 modId);
extern char *MMSlib_getMessageFullPath(MSF_UINT8 modId, MmsMsgId msgId, MmsFileType fileType);
extern MmsResult genChkSumFile(MmsMsgId msgId);
extern MmsMsgId meaMMCGetCurrentActiveMsg(void);
extern void delChkSumFile(MmsMsgId msgId);
extern MSF_BOOL getMmsMsgSubAddr(MSF_UINT8 modId, MmsMsgId msgId, char **subject, char **address, int MaxBufSize);
extern MSF_UINT8 getSenderModule(void);
extern int widget_ucs2_to_utf8_length_in_bytes(const unsigned char *raw);
extern int widget_ucs2_to_utf8_string(unsigned char *dest, int dest_size, const unsigned char *src);
extern void meaMMCUpdateFolder(void);
extern void mmsUpdateIndicator(void);
extern void freeMmsSetHeader(MSF_UINT8 modId, MmsSetHeader *mHeader);
extern void wap_send_mmi_mms_refresh_ind(MeaFolder folder);
extern MeaFolder mmsFolder2MeaFolder(MmsFolderType folder);
/* Internal Functions */
static MmcResult writeMmsFolderStatusToFile(MmsListOfProperties *list);
MmcResult translateMmsResultToMmc(MmsResult result);
static void getAddressAndSubject(MmsMessageFolderInfo *fInfo, char *msg_addr, char *msg_subject);
static void createMessageFromMMC(MmsFileType suffix);
static void getMmsFolderStatusFromMMC(MmcFolderType folderId);

/* For l4c Signals */
static void wap_mmc_read_folder_status_output_req_hldr(
                module_type mod_id,
                sap_type sap_id,
                MmcResult result,
                MmcFolderInfo *folderInfo);
static void wap_mmc_upload_msg_output_req_hldr(module_type mod_id, sap_type sap_id, MmcResult result, MmsMsgId msgId);
static void wap_mmc_delete_msg_output_req_hldr(module_type mod_id, sap_type sap_id, MmcResult result);

#ifdef __UNIFIED_COMPOSER_SUPPORT__
#define MMC_IS_SERVICE_READY()  (msm_get_module_status (MSF_MODID_MMS) == MODULE_STATUS_ACTIVE && \
                                 msm_get_module_status (MSF_MODID_MMA) == MODULE_STATUS_ACTIVE)
#else
#define MMC_IS_SERVICE_READY()  (msm_get_module_status (MSF_MODID_MMS) == MODULE_STATUS_ACTIVE)
#endif

/*****************************************************************************
 * FUNCTION
 *  printMMCSigs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void printMMCSigs()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* printf("%d\n",MSG_ID_WAP_MMC_SEND_APPMMS_REQ); */
}


/*****************************************************************************
 * FUNCTION
 *  mmcCleanContext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmcCleanContext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX)
    {
        MSF_FILE_REMOVE(MMC_JSR_MSG_FILE);
        MMC_CNTX->mod_id = 0;
        MMC_CNTX->sap_id = 0;
        MMC_CNTX->op = 0;
        MMC_CNTX->state = 0;
        MMC_CNTX->msgId = 0;
        MMC_CNTX->curr_bdy_no = 0;
        MMC_CNTX->bdy_no = 0;
        MMC_CNTX->retrievalMode = 0;
        MMC_CNTX->flag = 0;
        kal_mem_set(MMC_CNTX->msg_filepath, 0, 100);
    }
}


/*****************************************************************************
 * FUNCTION
 *  isMmsReplyForMMC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL isMmsReplyForMMC(MSF_UINT16 signal, MSF_UINT32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX == NULL)
    {
        return FALSE;
    }
    switch (signal)
    {
        case MMS_SIG_CREATE_MSG_REPLY:
        {
            return MMC_CHECK_FLAG(MMC_FLAG_WAIT_CREATE_MSG_REPLY);
        }
        case MMS_SIG_MSG_DONE_REPLY:
        {
            return (MMC_CHECK_FLAG(MMC_FLAG_WAIT_CREATE_MSG_DONE_REPLY) && (MMC_CNTX->msgId == param));
        }
        case MMS_SIG_GET_FLDR_REPLY:
        {
            return MMC_CHECK_FLAG(MMC_FLAG_WAIT_GET_FOLDER_CONTENT_REPLY);
        }
        case MMS_SIG_SEND_MSG_REPLY:
        {
            return MMC_CHECK_FLAG(MMC_FLAG_WAIT_SEND_MSG_REPLY);
        }
        default:
            return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  createMessageFromMMC
 * DESCRIPTION
 *  The function sets create_msg_reply_wait to TRUE and then calls
 *  MMSif_createMessage(). The default folder is MMS_SUFFIX_SEND_REQ.
 * PARAMETERS
 *  suffix      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void createMessageFromMMC(MmsFileType suffix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMC_SET_FLAG(MMC_FLAG_WAIT_CREATE_MSG_REPLY);

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_createMessage(MSF_MODID_MMC, suffix);
#else
    if (!MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        MMSif_applicationReg(MSF_MODID_MMC);
    }
    MMSif_createMessage(MSF_MODID_MMC, suffix);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  createMessageDoneFromMMC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgId           [IN]        
 *  folderId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void createMessageDoneFromMMC(MmsMsgId msgId, MmsFolderType folderId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMC_CNTX->msgId = msgId;
    MMC_SET_FLAG(MMC_FLAG_WAIT_CREATE_MSG_DONE_REPLY);
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_createMessageDone(MSF_MODID_MMC, msgId, folderId);
#else
    if (!MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        MMSif_applicationReg(MSF_MODID_MMC);
    }
    MMSif_createMessageDone(MSF_MODID_MMC, msgId, folderId);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  sendMessageFromMMC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void sendMessageFromMMC(MmsMsgId msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMC_CNTX->msgId = msgId;
    MMC_SET_FLAG(MMC_FLAG_WAIT_SEND_MSG_REPLY);
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_sendMessage(MSF_MODID_MMC, msgId);
#else
    if (!MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        MMSif_applicationReg(MSF_MODID_MMC);
    }
    MMSif_sendMessage(MSF_MODID_MMC, msgId);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cancelSendMessageFromMMC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void cancelSendMessageFromMMC(MmsMsgId msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMC_CNTX->msgId = msgId;
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_sendCancel(MSF_MODID_MMC, msgId);
#else
    if (!MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        MMSif_applicationReg(MSF_MODID_MMC);
    }
    MMSif_sendCancel(MSF_MODID_MMC, msgId);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  getMmsFolderStatusFromMMC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folderId        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void getMmsFolderStatusFromMMC(MmcFolderType folderId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMC_SET_FLAG(MMC_FLAG_WAIT_GET_FOLDER_CONTENT_REPLY);
    if (folderId == MMC_INBOX)
    {
        folderId = (MmcFolderType) (MMC_INBOX | MMC_NOTIFY);
    }
#ifdef __UNIFIED_COMPOSER_SUPPORT__
    MMA_getFolderContent(MSF_MODID_MMC, folderId, 0, MMS_MAX_NO_OF_MSG - 1);
#else
    if (!MSF_moduleIsRunning(MSF_MODID_MEA))
    {
        MMSif_applicationReg(MSF_MODID_MMC);
    }
    MMSif_getFolderContent(MSF_MODID_MMC, folderId, 0, MMS_MAX_NO_OF_MSG - 1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  writeMmsFolderStatusToFile
 * DESCRIPTION
 *  Write mms folder status to information file
 * PARAMETERS
 *  list        [?]     
 * RETURNS
 *  MmcResult
 *****************************************************************************/
MmcResult writeMmsFolderStatusToFile(MmsListOfProperties *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    int filehandle = -1;
    int info_file_size = 0;
    int result = 0;
    MmcMessageInfo *msgInfo_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_FILE_REMOVE(MMC_INFO_FILE);
    filehandle = MSF_FILE_OPEN(
                    MSF_MODID_MMC,
                    MMC_INFO_FILE,
                    HDI_FILE_SET_WRONLY | HDI_FILE_SET_CREATE | HDI_FILE_SET_CUSTOM_BLOCKING,
                    0);
    if (filehandle < 0)
    {
        return MMC_RESULT_FILE_OPERATION_ERROR;
    }
    else if (list->noOfElements == 0)
    {
        MSF_FILE_CLOSE(filehandle);
        return MMC_RESULT_OK;
    }
    info_file_size = list->noOfElements * sizeof(MmcMessageInfo);
    msgInfo_p = (MmcMessageInfo*) MSF_MEM_ALLOC(MSF_MODID_MMC, info_file_size);
    if (!msgInfo_p)
    {
        MSF_FILE_CLOSE(filehandle);
        return MMC_RESULT_INSUFFICIENT_MEMORY;
    }

    memset((char*)msgInfo_p, 0x00, info_file_size);
    for (i = 0; i < list->noOfElements; i++)
    {
        msgInfo_p[i].msgId = list->msgPropertyList[i].msgFolderInfo.msgId;
        msgInfo_p[i].date = list->msgPropertyList[i].msgFolderInfo.date;
        msgInfo_p[i].offset = 0;
        msgInfo_p[i].size = list->msgPropertyList[i].msgFolderInfo.size;
        /* msgInfo_p[i].fileType=list->msgPropertyList[i].msgFolderInfo.suffix; */
        kal_sprintf(
            (char*)(msgInfo_p[i].filename),
            "%lx.%c",
            list->msgPropertyList[i].msgFolderInfo.msgId,
            list->msgPropertyList[i].msgFolderInfo.suffix);
        if (MMC_CNTX->retrievalMode == MMC_FULL)
        {
            getAddressAndSubject(
                &list->msgPropertyList[i].msgFolderInfo,
                (char*)&msgInfo_p[i].address,
                (char*)&msgInfo_p[i].subject);
        }
    }
    if ((result = MSF_FILE_WRITE(filehandle, msgInfo_p, info_file_size)) != info_file_size)
    {
        MSF_MEM_FREE(MSF_MODID_MMC, msgInfo_p);
        msgInfo_p = NULL;
        MSF_FILE_CLOSE(filehandle);
        if (result > 0 || result == HDI_FILE_ERROR_PATH)
        {
            MSF_FILE_REMOVE(MMC_INFO_FILE);
            return MMC_RESULT_FILE_OPERATION_ERROR;
        }
        else if (result == HDI_FILE_ERROR_FULL)
        {
            MSF_FILE_REMOVE(MMC_INFO_FILE);
            return MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        }
    }

    if (msgInfo_p)
    {
        MSF_MEM_FREE(MSF_MODID_MMC, msgInfo_p);
    }
    MSF_FILE_CLOSE(filehandle);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMC_ENV_66130A2A44D017740BF0788C882954C4, "%s(%d): MMC module write folder status to info.db file. \n",
                 __FILE__, __LINE__));
    return MMC_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmcMsfSignalHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmcMsfSignalHandler(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {

        case MSF_SIG_MODULE_EXECUTE_COMMAND:
            break;
        case MSF_SIG_MODULE_TERMINATE:
            MMCc_kill();
            break;
        case MSF_SIG_TIMER_EXPIRED:
        {
            timer_state = IDLE;
            if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
            {
                timer_state = BUSY;
                msf_timer_reset(MSF_MODID_MMC, --mmcTimerId);

            }
            else
            {
                isMmsStartup = TRUE;
            }
            break;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcMmsSignalHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal      [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmcMmsSignalHandler(MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsListOfProperties *newList = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (signal)
    {
        case MMS_SIG_CREATE_MSG_REPLY:
        {
            MmcResult result = MMC_RESULT_OK;

            MmsMsgReplySig *rep = (MmsMsgReplySig*) p;

            if (MMC_CHECK_FLAG(MMC_FLAG_WAIT_CREATE_MSG_REPLY))
            {
                MMC_UNSET_FLAG(MMC_FLAG_WAIT_CREATE_MSG_REPLY);
                if (MMC_CHECK_FLAG(MMC_FLAG_ABORT))
                {
                    fldrMgrDeleteMessage(MMC_CNTX->msgId);
                #ifdef MMS_FILE_PROTECT_SUPPORT
                    delChkSumFile(MMC_CNTX->msgId);
                #endif 
                    wap_mmc_reply_abort_appmms_rsp(MMC_CNTX->mod_id, MMC_CNTX->sap_id, MMC_RESULT_OK);
                    mmcCleanContext();
                    return;
                }

                if (MMC_CNTX->state == MMC_UPLOAD_MSG || MMC_CNTX->state == MMC_CREATE_MSG)
                {
                    if (rep->result == MMS_RESULT_OK)
                    {
                        char *filename = NULL;

                        filename = (char*)MMSlib_getMessageFullPath(MSF_MODID_MMC, rep->msgId, MMC_SUFFIX_SEND_REQ);

                        if (!filename)
                        {
                            result = MMC_RESULT_INSUFFICIENT_MEMORY;
                            goto exit_create_msg_err;
                        }

                        if (MSF_FILE_REMOVE(filename) != 0 || MSF_FILE_RENAME(MMC_CNTX->msg_filepath, filename) != 0)
                        {
                            MMC_MEM_FREE(filename);
                            result = MMC_RESULT_FILE_OPERATION_ERROR;
                            goto exit_create_msg_err;
                        }
                        else    /* Call Mmsif_createMessageDone() to parse the uploaded message file */
                        {
                            if (MMC_CNTX->op == MMC_OP_UPLOAD_MSG)
                            {
                                createMessageDoneFromMMC(rep->msgId, MMS_DRAFTS);
#ifdef __UNIFIED_MSG_SUPPORT__                                
                                wap_send_mmi_mms_refresh_ind(mmsFolder2MeaFolder(MMS_DRAFTS));
#endif /*__UNIFIED_MSG_SUPPORT__*/                                
                            }
                            else if (MMC_CNTX->op == MMC_OP_SEND_MSG)
                            {
                                createMessageDoneFromMMC(rep->msgId, MMS_HIDDEN);
                            }
                            else
                            {
                                ASSERT(0);
                            }
                            MMC_MEM_FREE(filename);
                        }
                    }
                    else
                    {
                      exit_create_msg_err:
                        if (MMC_CNTX->op == MMC_OP_UPLOAD_MSG)
                        {
                            wap_mmc_upload_msg_output_req_hldr(MMC_CNTX->mod_id, MMC_CNTX->sap_id, result, 0);
                        }
                        else if (MMC_CNTX->op == MMC_OP_SEND_MSG)
                        {
                            wap_mmc_reply_send_appmms_rsp(MMC_CNTX->mod_id, MMC_CNTX->sap_id, result);
                        }
                        else
                        {
                            ASSERT(0);
                        }
                        mmcCleanContext();
                        return;
                    }
                }
                else
                {
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                                 MMC_ENV_4FAFB9A447C37AAC5ACB3D7E47DAF3AC, "%s(%d): MMC module received an unexpected message created reply signal. \n", __FILE__,
                                 __LINE__));
                    ASSERT(0);
                }
            }
            break;
        }

        case MMS_SIG_MSG_DONE_REPLY:
        {
            MmsMsgReplySig *rep = (MmsMsgReplySig*) p;

            if (MMC_CHECK_FLAG(MMC_FLAG_WAIT_CREATE_MSG_DONE_REPLY) && MMC_CNTX->msgId == rep->msgId)
            {
                MMC_UNSET_FLAG(MMC_FLAG_WAIT_CREATE_MSG_DONE_REPLY);
                if (MMC_CHECK_FLAG(MMC_FLAG_ABORT))
                {
                    fldrMgrDeleteMessage(MMC_CNTX->msgId);
                #ifdef MMS_FILE_PROTECT_SUPPORT
                    delChkSumFile(MMC_CNTX->msgId);
                #endif 
                    wap_mmc_reply_abort_appmms_rsp(MMC_CNTX->mod_id, MMC_CNTX->sap_id, MMC_RESULT_OK);
                    mmcCleanContext();
                    return;
                }
                if (rep->result == MMS_RESULT_OK)
                {
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                                 MMC_ENV_E1323A7BBDCDCF322863B0745879EA04, "%s(%d): MMS composer insert a mms message successfully \n", __FILE__, __LINE__));
                #ifdef MMS_FILE_PROTECT_SUPPORT
                    genChkSumFile(rep->msgId);
                #endif 
                }
                if (MMC_CNTX->op == MMC_OP_UPLOAD_MSG)
                {
                    if (rep->result != MMS_RESULT_OK)
                    {
                        fldrMgrDeleteMessage(MMC_CNTX->msgId);
                    }
                    wap_mmc_upload_msg_output_req_hldr(
                        MMC_CNTX->mod_id,
                        MMC_CNTX->sap_id,
                        translateMmsResultToMmc(rep->result),
                        rep->msgId);
                    mmcCleanContext();
                }
                else if (MMC_CNTX->op == MMC_OP_SEND_MSG)
                {
                    if (rep->result != MMS_RESULT_OK)
                    {
                        /* Fail to insert one MMS message to Teleca MMS service. */
                        wap_mmc_reply_send_appmms_rsp(
                            MMC_CNTX->mod_id,
                            MMC_CNTX->sap_id,
                            translateMmsResultToMmc(rep->result));
                        mmcCleanContext();
                    }
                    else
                    {
                        /* Send the MMS message to Server */
                        sendMessageFromMMC(MMC_CNTX->msgId);
                    }
                }
                else
                {
                    ASSERT(0);
                }
            }
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                             MMC_ENV_683461D75580FC0497A9794A94DBC0C1, "%s(%d): MMC module received an unexpected message created done reply signal. \n",
                             __FILE__, __LINE__));
                ASSERT(0);
            }
            break;
        }
        case MMS_SIG_SEND_MSG_REPLY:
        {
            MmsResultSig *result = (MmsResultSig*) p;

            if (MMC_CHECK_FLAG(MMC_FLAG_WAIT_SEND_MSG_REPLY))
            {
                fldrMgrDeleteMessage(MMC_CNTX->msgId);
            #ifdef MMS_FILE_PROTECT_SUPPORT
                delChkSumFile(MMC_CNTX->msgId);
            #endif 
                if (MMC_CHECK_FLAG(MMC_FLAG_ABORT))
                {
                    if (result->result == MMS_RESULT_CANCELLED_BY_USER || result->result == MMS_RESULT_OK)
                    {
                        wap_mmc_reply_abort_appmms_rsp(MMC_CNTX->mod_id, MMC_CNTX->sap_id, MMC_RESULT_OK);
                    }
                    else
                    {
                        wap_mmc_reply_abort_appmms_rsp(
                            MMC_CNTX->mod_id,
                            MMC_CNTX->sap_id,
                            (kal_uint8) translateMmsResultToMmc(result->result));
                    }
                }
                else
                {
                    wap_mmc_reply_send_appmms_rsp(
                        MMC_CNTX->mod_id,
                        MMC_CNTX->sap_id,
                        (kal_uint8) translateMmsResultToMmc(result->result));
                }
                mmcCleanContext();
            }
            break;
        }
        case MMS_SIG_GET_FLDR_REPLY:
        {
            MmsListOfProperties *list = (MmsListOfProperties*) p;

            newList = MSF_MEM_ALLOC(MSF_MODID_MMC, sizeof(MmsListOfProperties));
            MMSif_copyMmsListOfProperties(newList, list, MSF_MODID_MMC);
            /* Codes */
            if (!MMC_CHECK_FLAG(MMC_FLAG_WAIT_GET_FOLDER_CONTENT_REPLY))
            {
                ASSERT(0);  /* Get an unexpected signal. */
            }
            MMC_UNSET_FLAG(MMC_FLAG_WAIT_GET_FOLDER_CONTENT_REPLY);
            switch (MMC_CNTX->state)
            {
                case MMC_READ_FOLDER:
                {
                    int i;
                    MmcFolderInfo *folderInfo = NULL;

                    folderInfo = (MmcFolderInfo*) MSF_MEM_ALLOC(MSF_MODID_MMC, sizeof(MmcFolderInfo));
                    if (!folderInfo)
                    {
                        ASSERT(0);
                    }
                    memset((char*)folderInfo, 0x00, sizeof(MmcFolderInfo));
                    folderInfo->numOUnreadMsg = 0;
                    folderInfo->numOfMsg = newList->noOfElements;
                    /* Transfer file path encoded by UTF8 to UCS2 */
                    {
                        char *fname = NULL;
                        int len = 0;

                        fname = (char*)HDI_FileNameTranslate(MMS_FOLDER);
                        if (!fname)
                        {
                            ASSERT(0);
                        }
                        len = widget_ucs2_length((kal_uint8*)fname) * 2;
                        if (len <= 100)
                        {
                            memcpy(folderInfo->mmsHomeDirectory, fname, len);
                        }
                        else
                        {
                            memcpy(folderInfo->mmsHomeDirectory, fname, 100);
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                                         MMC_ENV_2F7D3EA7CE372C5C7AFE50A7A95D0D34, "%s(%d):  The path of mms home directory  is too long. \n", __FILE__,
                                         __LINE__));
                        }
                        HDI_FileNameFree((unsigned char*)fname);
                        fname = NULL;
                        len = 0;

                        fname = (char*)HDI_FileNameTranslate(MMC_INFO_FILE);
                        if (!fname)
                        {
                            ASSERT(0);
                        }
                        len = widget_ucs2_length((kal_uint8*)fname) * 2;
                        if (len <= 100)
                        {
                            memcpy(folderInfo->infoFilePath, fname, len);
                        }
                        else
                        {
                            memcpy(folderInfo->mmsHomeDirectory, fname, 100);
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                                         MMC_ENV_2F7D3EA7CE372C5C7AFE50A7A95D0D34, "%s(%d):  The path of mms home directory  is too long. \n", __FILE__,
                                         __LINE__));
                        }
                        HDI_FileNameFree((unsigned char*)fname);
                    }
                    /* Get the number of unread messages */
                    for (i = 0; i < newList->noOfElements; i++)
                    {
                        if (newList->msgPropertyList[i].msgFolderInfo.read == FALSE)
                        {
                            folderInfo->numOUnreadMsg++;
                        }
                    }
                    /* Write all retrieved mms folder status to MMC_INFO */
                    wap_mmc_read_folder_status_output_req_hldr(
                        MMC_CNTX->mod_id,
                        MMC_CNTX->sap_id,
                        (MmcResult) writeMmsFolderStatusToFile(newList),
                        folderInfo);
                    MMSif_freeMmsListOfProperties(newList, MSF_MODID_MMC);
                    MSF_MEM_FREE(MSF_MODID_MMC, newList);
                    MSF_MEM_FREE(MSF_MODID_MMC, folderInfo);
                    /* MSF_MEM_FREE(MSF_MODID_MMC,folderInfo); */
                    break;
                }
                case MMC_DELETE_MSG:
                {
                    int i;

                    for (i = 0; i < newList->noOfElements; i++)
                    {
                        /* Check if MEA views the message */
                        if (MSF_moduleIsRunning(MSF_MODID_MEA) &&
                            newList->msgPropertyList[i].msgFolderInfo.msgId == meaMMCGetCurrentActiveMsg())
                        {
                            MMSif_freeMmsListOfProperties(newList, MSF_MODID_MMC);
                            wap_mmc_delete_msg_output_req_hldr(
                                MMC_CNTX->mod_id,
                                MMC_CNTX->sap_id,
                                MMC_RESULT_ACCESS_DENY);
                            return;
                        }
                    }
                    for (i = 0; i < newList->noOfElements; i++)
                    {
                        fldrMgrDeleteMessage(newList->msgPropertyList[i].msgFolderInfo.msgId);
                    #ifdef MMS_FILE_PROTECT_SUPPORT
                        delChkSumFile(newList->msgPropertyList[i].msgFolderInfo.msgId);
                    #endif 
                    }
                    if (MSF_moduleIsRunning(MSF_MODID_MEA))
                    {
                        /* Inform MEA of the deletion */
                    }
                    wap_mmc_delete_msg_output_req_hldr(MMC_CNTX->mod_id, MMC_CNTX->sap_id, MMC_RESULT_OK);
                    break;
                }
                default:
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMC_ENV_8D452FFB58B38E459172640E2CCB809F, "%s(%d): Got wrong signal in MMC \n", __FILE__,
                                 __LINE__));
                    break;
            }
            break;
            MMSif_freeMmsListOfProperties(newList, MSF_MODID_MMC);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcDestruct
 * DESCRIPTION
 *  destory the mmc module
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmcDestruct(MSF_UINT8 module, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  MMCc_kill
 * DESCRIPTION
 *  this function will be called MSF environment want terminate mmc module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMCc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_MMC);
    MSF_FILE_CLOSE_ALL(MSF_MODID_MMC);  /* Only if the module use files. */
    MSF_MEM_FREE_ALL(MSF_MODID_MMC);
    MSF_MODULE_IS_TERMINATED(MSF_MODID_MMC);
    MSF_KILL_TASK(MSF_MODID_MMC);
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, MMC_ENV_8B7B016D1B6D5A85EFC7A0D364879023, "%s(%d): MMC module is terminated.\n", __FILE__, __LINE__));
}


/*****************************************************************************
 * FUNCTION
 *  mmc_exception_handler
 * DESCRIPTION
 *  this function will be called when exception event happen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmc_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_inside_run)
    {
        longjmp(mmc_jmpbuf, 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcConvert
 * DESCRIPTION
 *  this function will be called module mmc receive message and want translate to internal message.
 * PARAMETERS
 *  module      [IN]        
 *  signal      [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *mmcConvert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  mmcInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmcInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmcTimerId = 1000;
    timer_state = IDLE;
    isMmsStartup = FALSE;
    kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));

    mmc_jsr_msg_db = NULL;
    for (i = 0; i < MMC_MAX_JSR_APP_ID_NUM; i++)
    {
        mmc_jsr_appId_db[i] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MMCc_start
 * DESCRIPTION
 *  this function will be called when module mmc is initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMCc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmc_inside_run = 0;
    memset(mmc_jmpbuf, 0, sizeof(mmc_jmpbuf));

    /* Initialize the memory allocator. Needed in most other functions. */
    MSF_MEM_INIT(MSF_MODID_MMC, mmc_exception_handler);

    /* Initiate internal global data */
    mmcInit();

    /* Register the signal queue */
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_MMC);

    /* Register conversion and destruction functions */
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_MMC, mmcConvert, mmcDestruct);

    /* Registrate the module into MSF */
    MSF_MODULE_IS_CREATED(MSF_MODID_MMC, (char*)MMC_VERSION);
    MSF_MODULE_IS_ACTIVE(MSF_MODID_MMC);
    memset(mmc_jsr_appId_db, 0x00, MMC_MAX_JSR_APP_ID_NUM * 4);
}


/*****************************************************************************
 * FUNCTION
 *  mmcReceiveExtSignal
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module mmc.
 * PARAMETERS
 *  srcModule       [IN]        
 *  signal          [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmcReceiveExtSignal(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srcModule)
    {
        case MSF_MODID_MSM:
            mmcMsfSignalHandler(signal, p);
            break;

        case MSF_MODID_MMS:
            mmcMmsSignalHandler(signal, p);
            break;

        default:
            break;
    }
    /* Delete signal */
    if (MSF_moduleIsRunning(MSF_MODID_MMC))
    {
        MSF_SIGNAL_DESTRUCT(MSF_MODID_MMC, signal, p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcSignalProcess
 * DESCRIPTION
 *  this function will be called when module mmc want process signal.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmcSignalProcess(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  MMCc_run
 * DESCRIPTION
 *  this function will be called when module mmc want process something.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMCc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmc_inside_run = 1;

    if (setjmp(mmc_jmpbuf) == 0)
    {
        /*
         * Get external signals and process one internal signal.
         */
        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_MMC, mmcReceiveExtSignal));
        mmcSignalProcess();
    }
    else
    {
        /*
         * A longjmp from xxx_exception_handler. If we are here there is no more
         * memory, and the situation could not be worse.
         * Send out an error and terminate as the figure above.
         */
        MSF_ERROR(MSF_MODID_MMC, MSF_ERR_MODULE_OUT_OF_MEMORY);

        MMCc_kill();
    }
    /* Clear the global variable, the module is now outside the Run function. */
    mmc_inside_run = 0;
}


/*****************************************************************************
 * FUNCTION
 *  MMCc_wantsToRun
 * DESCRIPTION
 *  this function will be called when MSF environment want to known
 *  module mmc have something to do or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int MMCc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if there are any signals in the external signal queue or
       in the internal signal queue. */

    if ((!isMmsStartup) && (timer_state == IDLE))
    {
        timer_state = BUSY;
        msf_timer_set(MSF_MODID_MMC, mmcTimerId++, 30);
    }

    return MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_MMC) > 0;
}


/*****************************************************************************
 * FUNCTION
 *  testProgram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void testProgram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * wap_mmc_read_folder_status_req_ind_struct Message;
     * Message.folderId=MMC_TEMPLATES;
     * Message.retrievalMode=MMC_FULL;
     * wap_mmc_read_folder_status_req_ind_hldr(&Message);
     */

    /*
     * wap_mmc_delete_msg_req_ind_struct Message;
     * Message.msgId=1;
     * Message.folderId=MMC_DRAFTS;
     * wap_mmc_delete_msg_req_ind_hldr(Message);
     */

    /*
     * wap_mmc_upload_msg_req_ind_struct Message;
     * strcpy(Message.filePath,"\\mms\\2.t");
     * wap_mmc_upload_msg_req_ind_hldr(&Message);
     */
}


/*****************************************************************************
 * FUNCTION
 *  translateMmsResultToMmc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmcResult translateMmsResultToMmc(MmsResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMS_RESULT_OK:
            return MMC_RESULT_OK;

        case MMS_RESULT_BUSY:
            return MMC_RESULT_BUSY;

        case MMS_RESULT_TOO_MANY_MSG:
            return MMC_RESULT_EXCEED_MAX_MSGS;

        case MMS_RESULT_FILE_NOT_FOUND:
            return MMC_RESULT_MESSAGE_ID_NOT_FOUND;

        case MMS_RESULT_FILE_READ_ERROR:
        case MMS_RESULT_FILE_WRITE_ERROR:
        case MMS_RESULT_DELAYED:
        case MMS_RESULT_EOF:
            return MMC_RESULT_FILE_OPERATION_ERROR;

        case MMS_RESULT_FOLDER_NOT_FOUND:
            return MMC_RESULT_INVALID_FOLDER;

        case MMS_RESULT_INSUFFICIENT_MEMORY:
            return MMC_RESULT_INSUFFICIENT_MEMORY;

        case MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            return MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;

        case MMS_RESULT_CANCELLED_BY_SYSTEM:
            return MMC_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM;

        case MMS_RESULT_INVALID_ADDRESS:
        case MMS_RESULT_INVALID_APPLICATION_HEADER:
        case MMS_RESULT_INVALID_CONTENT_ID:
        case MMS_RESULT_INVALID_CONTENT_LOCATION:
        case MMS_RESULT_INVALID_CONTENT_TYPE:
        case MMS_RESULT_INVALID_EXPIRY_TIME:
        case MMS_RESULT_INVALID_HEADER_SIZE:
        case MMS_RESULT_INVALID_MSG_CLASS:
        case MMS_RESULT_INVALID_REPLY_CHARGING_DEADLINE:
        case MMS_RESULT_INVALID_SIZE:
        case MMS_RESULT_INVALID_STORAGE_TYPE:
        case MMS_RESULT_INVALID_SUBJECT:
        case MMS_RESULT_INVALID_VERSION:
        case MMS_RESULT_INVALID_DATE:
        case MMS_RESULT_TRANSACTION_ID_MISSING:
        case MMS_RESULT_MESSAGE_CORRUPT:
        case MMS_RESULT_MESSAGE_EMPTY:
        case MMS_RESULT_WRONG_FILE_TYPE:
            return MMC_RESULT_INVALID_MESSAGE;

        default:
            return MMC_RESULT_ERROR;    /* An unknown error */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcMemAlloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmcMemAlloc(MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((mem_ptr = MSF_MEM_ALLOC(MSF_MODID_MMC, size)) != NULL);
    kal_mem_set(mem_ptr, 0x00, size);
    return mem_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  getAddressAndSubject
 * DESCRIPTION
 *  To get address and subject from mms message.
 * PARAMETERS
 *  fInfo           [?]     char **msg_addr, char **msg_subject
 *  msg_addr        [?]     
 *  msg_subject     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void getAddressAndSubject(MmsMessageFolderInfo *fInfo, char *msg_addr, char *msg_subject)
{
#ifdef MMS_FILE_PROTECT_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *subject = NULL;
    char *address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    getMmsMsgSubAddr(MSF_MODID_MMC, fInfo->msgId, &subject, &address, 40);
    if (subject)
    {
        memset(msg_subject, 0x00, 40);
        if (strlen(subject) > 39)
        {
            memcpy(msg_subject, subject, 39);
        }
        else
        {
            strcpy(msg_subject, subject);
        }
        MSF_MEM_FREE(MSF_MODID_MMC, subject);
    }
    if (address)
    {
        memset(msg_addr, 0x00, 40);
        if (strlen(address) > 39)
        {
            memcpy(msg_addr, address, 39);
        }
        else
        {
            strcpy(msg_addr, address);
        }
        MSF_MEM_FREE(MSF_MODID_MMC, address);
    }
#else /* MMS_FILE_PROTECT_SUPPORT */ 
    MmsMsgHandle msgHandle;
    MmsTransactionHandle transaction;
    MmsGetHeader header;
    MmsNotification notiheader;
    MmsResult ret = MMS_RESULT_ERROR;
    char *addr = NULL;
    char *buffer = NULL;
    int bufSize = 0;
    MSF_BOOL freeHeader = FALSE;
    MSF_BOOL freeBuffer = FALSE;
    char *subject = NULL, *address = NULL;
    MmsHeaderValue headerValue;
    MmsEncodedText enSubject;
    MmsAddress fromAddress;

    /* Get image dependent on the read status and priority */
    /* Open message and then get message header */
    freeHeader = FALSE;
    freeBuffer = FALSE;
    bufSize = 0;
    buffer = NULL;
    subject = NULL;
    addr = NULL;
    enSubject.charset = MMS_UNKNOWN_CHARSET;
    enSubject.text = NULL;
    fromAddress.address = NULL;
    fromAddress.addrType = MMS_UNSUPPORTED;
    fromAddress.name.charset = MMS_UNKNOWN_CHARSET;
    fromAddress.name.text = NULL;

    switch (fInfo->suffix)
    {
        case MMS_SUFFIX_DELIVERYREPORT:
        case MMS_SUFFIX_READREPORT:
            loadMmsDataToBuffer(MSF_MODID_MMC, fInfo->msgId, (MSF_UINT8) fInfo->suffix, &buffer, &bufSize);
            if (!buffer)
            {
                break;
            }
            freeBuffer = TRUE;
            if (mmsPduGet(buffer, bufSize, MMS_SUBJECT, &headerValue))
            {
                MSF_UINT32 notUsed = 0;
                int size = 0;

                size = (MSF_UINT32) ((unsigned char*)buffer - (unsigned char*)headerValue.subject) + bufSize;
                if (parseEncodedStringValue(MSF_MODID_MMC, headerValue.subject, size, &notUsed, &enSubject) != FALSE)
                {
                    subject = enSubject.text;
                }
            }

            if (parseFromAddress(MSF_MODID_MMC, (unsigned char*)buffer, bufSize, &fromAddress) != FALSE)
            {
                addr = fromAddress.address;
            }
            break;

        case MMS_SUFFIX_SEND_REQ:
        case MMS_SUFFIX_TEMPLATE:
        case MMS_SUFFIX_MSG:
        case MMS_SUFFIX_NOTIFICATION:
            memset(&header, 0x00, sizeof(MmsGetHeader));
            memset(&notiheader, 0x00, sizeof(notiheader));
            MMS_FILE_OPEN_BLOCK_FLAG = TRUE;
            if (MMSlib_messageOpen(MSF_MODID_MMC, fInfo->msgId, fInfo->suffix, &msgHandle) != MMS_RESULT_OK)
            {
                MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
                break;
            }
            else if (MMSlib_transactionOpen(MSF_MODID_MMC, &transaction) != MMS_RESULT_OK)
            {
                MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
                MMSlib_transactionClose(MSF_MODID_MMC, &transaction);
                break;
            }
            MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
            if (fInfo->suffix == MMS_SUFFIX_NOTIFICATION)
            {
                if ((ret = MMSlib_getNotification(MSF_MODID_MMC, &notiheader, &msgHandle, &transaction)) == MMS_RESULT_OK)
                {
                    freeHeader = TRUE;
                }
            }
            else
            {
                if ((ret = MMSlib_getMessageHeader(MSF_MODID_MMC, &header, &msgHandle, &transaction)) == MMS_RESULT_OK)
                {
                    freeHeader = TRUE;
                }
            }
            MMSlib_transactionClose(MSF_MODID_MMC, &transaction);
            MMSlib_messageClose(MSF_MODID_MMC, &msgHandle);
            msgHandle = NULL;
            transaction = NULL;
            if (freeHeader && header.subject.text)
            {
                subject = header.subject.text;
            }
            if (freeHeader && notiheader.subject.text)
            {
                subject = notiheader.subject.text;
            }
            /* hint = from */
            if (fInfo->suffix != MMS_SUFFIX_SEND_REQ && fInfo->suffix != MMS_SUFFIX_TEMPLATE)
            {
                if (fInfo->suffix == MMS_SUFFIX_NOTIFICATION)
                {
                    addr = notiheader.from.address;
                }
                else
                {
                    addr = header.from.address;
                }

            }
            else
            {
                if (header.to)
                {
                    addr = header.to->current.address;
                }
                else if (header.cc)
                {
                    addr = header.cc->current.address;
                }
                else if (header.bcc)
                {
                    addr = header.bcc->current.address;
                }
            }
            break;
    }
    /* subject */
    if ((NULL != subject) && (0 != strlen(subject)))
    {
        if (strlen(subject) < 40)
        {
            strcpy(msg_subject, subject);
        }
        else
        {
            memcpy(msg_subject, subject, 39);
        }
        if (enSubject.text)
        {
            MSF_MEM_FREE(MSF_MODID_MMC, enSubject.text);
        }
    }

    if (addr)
    {
        if (strlen(addr) < 40)
        {
            strcpy(msg_addr, addr);
        }
        else
        {
            memcpy(msg_addr, addr, 39);
        }
        if (fromAddress.address)
        {
            MSF_MEM_FREE(MSF_MODID_MMC, fromAddress.address);
        }
        if (fromAddress.name.text)
        {
            MSF_MEM_FREE(MSF_MODID_MMC, fromAddress.name.text);
        }
    }
    if (freeHeader)
    {
        if (fInfo->suffix == MMS_SUFFIX_NOTIFICATION)
        {
            freeMmsNotification(MSF_MODID_MMC, &notiheader);
        }
        else
        {
            freeMmsGetHeader(MSF_MODID_MMC, &header);
        }
    }
    if (freeBuffer)
    {
        MSF_MEM_FREE(MSF_MODID_MMC, buffer);
    }
#endif /* MMS_FILE_PROTECT_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_read_folder_status_req_ind_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_READ_FOLDER_STATUS_IND primitive to L4
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  Message     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_read_folder_status_req_ind_hldr(
        module_type mod_id,
        sap_type sap_id,
        wap_mmc_read_folder_status_req_ind_struct *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                 MMC_ENV_BDBCCA6915AE59A0B872C23902B76F56, "%s(%d): MMC module receives an wap_mmc_read_folder_status_req_ind signal, folder:%d and retrieval mode: %d. \n",
                 __FILE__, __LINE__, Message->folderId, Message->retrievalMode));
    if (MMC_IS_SERVICE_READY() == FALSE)
    {
        wap_mmc_read_folder_status_output_req_hldr(mod_id, sap_id, MMC_RESULT_MMS_NO_READY, NULL);
        return;
    }
    if (MMC_CNTX->state == MMC_IDLE)
    {

        if (Message->folderId == MMC_INBOX || Message->folderId == MMC_OUTBOX ||
            Message->folderId == MMC_SENT || Message->folderId == MMC_TEMPLATES || Message->folderId == MMC_DRAFTS)
        {
            if (Message->retrievalMode == MMC_BASIC || Message->retrievalMode == MMC_FULL)
            {
                /* Read MMS Folder Status */
                MMC_CNTX->retrievalMode = Message->retrievalMode;
                MMC_CNTX->state = MMC_READ_FOLDER;
                MMC_CNTX->mod_id = mod_id;
                MMC_CNTX->sap_id = sap_id;
                MSF_FILE_REMOVE(MMC_INFO_FILE);
                getMmsFolderStatusFromMMC(Message->folderId);
            }
            else
            {
                wap_mmc_read_folder_status_output_req_hldr(mod_id, sap_id, MMC_RESULT_INVALID_PARAMETER, NULL);
            }
        }
        else
        {
            wap_mmc_read_folder_status_output_req_hldr(mod_id, sap_id, MMC_RESULT_INVALID_PARAMETER, NULL);
        }
    }
    else
    {
        wap_mmc_read_folder_status_output_req_hldr(mod_id, sap_id, MMC_RESULT_BUSY, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_read_folder_status_output_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_READ_FOLDER_STATUS_RSP primitive to L4
 * PARAMETERS
 *  mod_id          [IN]        
 *  sap_id          [IN]        
 *  result          [IN]        MmcFolderInfo *folderInfo
 *  folderInfo      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_mmc_read_folder_status_output_req_hldr(
                module_type mod_id,
                sap_type sap_id,
                MmcResult result,
                MmcFolderInfo *folderInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ilm_struct *ilm_ptr = NULL;
    wap_mmc_read_folder_status_output_req_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_mmc_read_folder_status_output_req_struct*)
        construct_local_para(sizeof(wap_mmc_read_folder_status_output_req_struct), TD_CTRL);

    if (myMsgPtr)
    {
        memset((char*)myMsgPtr + 4, 0x00, (sizeof(wap_mmc_read_folder_status_output_req_struct) - 4));
        myMsgPtr->result = result;

        if (folderInfo)
        {
            myMsgPtr->numOfMsg = folderInfo->numOfMsg;
            myMsgPtr->numOfUnreadMsg = folderInfo->numOUnreadMsg;
            memset(myMsgPtr->mmsHomeDirectory, 0x00, 100);
            memset(myMsgPtr->infoFilePath, 0x00, 100);
            memcpy(
                myMsgPtr->mmsHomeDirectory,
                folderInfo->mmsHomeDirectory,
                (widget_ucs2_length((kal_uint8*)folderInfo->mmsHomeDirectory) * 2));
            memcpy(
                myMsgPtr->infoFilePath,
                folderInfo->infoFilePath,
                (widget_ucs2_length((kal_uint8*)folderInfo->infoFilePath) * 2));
        }
        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_MMC_READ_FOLDER_STATUS_OUTPUT_REQ; /* l4cMMS_DELETE_MSG_RSP */
        ilm_ptr->peer_buff_ptr = NULL;
        SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);

        if (result != MMC_RESULT_BUSY)
        {
            MMC_CNTX->state = MMC_IDLE;
            kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));

            if (MSF_moduleIsRunning(MSF_MODID_MMS) && getSenderModule() == MSF_MODID_MMC)
            {
                MMSif_applicationReg(0);
            }
        }
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                     MMC_ENV_D033E371546AD9D7A30DB7A6A79CA551, "%s(%d): MMC module returns wap_mmc_read_folder_status_uotput_req. result:%d, nMsg:%d and nUnreadMsg:%d \n",
                     __FILE__, __LINE__, result, myMsgPtr->numOfMsg, myMsgPtr->numOfUnreadMsg));
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                     MMC_ENV_76ECCCAD607C164F8B82C70565E85EC7, "%s(%d): MMC module can't get memory for wap_mmc_read_folder_status_uotput_req signal \n",
                     __FILE__, __LINE__));
        ASSERT(0);
    }
    /* MMCc_kill(); */
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_upload_msg_req_ind_hldr
 * DESCRIPTION
 *  Handle a WAP_MMC_UPLOAD_MSG_IND primitive from l4c
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  Message     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_upload_msg_req_ind_hldr(module_type mod_id, sap_type sap_id, wap_mmc_upload_msg_req_ind_struct *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len = 0, size = 0;
    MSF_UINT16 nMsgs = 0;
    MSF_UINT16 nUnreadMsgs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_IS_SERVICE_READY() == FALSE)
    {
        wap_mmc_upload_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_MMS_NO_READY, 0);
        return;
    }

    /* Max MMS num reached */
    fldrMgrGetNumberOfMessages(MMS_ALL_FOLDERS, &nMsgs, &nUnreadMsgs);
    if (nMsgs >= MMS_MAX_NO_OF_MSG - 1)
    {
        wap_mmc_upload_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_EXCEED_MAX_MSGS, 0);
        return;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                 MMC_ENV_05ED7ED676347CAFD4C50AE3B269DCA7, "%s(%d): MMC module receives an wap_mmc_upload_msg_req_ind signal. \n", __FILE__, __LINE__));
    if (MMC_CNTX->state == MMC_IDLE)
    {
        MMC_CNTX->op = MMC_OP_UPLOAD_MSG;
        MMC_CNTX->state = MMC_UPLOAD_MSG;
        MMC_CNTX->mod_id = mod_id;
        MMC_CNTX->sap_id = sap_id;
        if (Message->filePath)
        {

            memset(MMC_CNTX->msg_filepath, 0x00, 100);
            strcpy(MMC_CNTX->msg_filepath, HDI_EXTERNAL_PATH);

            len = widget_ucs2_to_utf8_length_in_bytes(Message->filePath);
            if (len >= (99 - HDI_EXTERNAL_LEN))
            {
                ASSERT(0);  /* File path is too long. */
            }
            widget_ucs2_to_utf8_string(
                (unsigned char*)(MMC_CNTX->msg_filepath + HDI_EXTERNAL_LEN),
                100 - HDI_EXTERNAL_LEN,
                (unsigned char*)Message->filePath);

            if ((size = MSF_FILE_GETSIZE(MMC_CNTX->msg_filepath)) > MMS_DEFAULT_MAX_MSG_SIZE)
            {
                /* The uploaded mms message file is too large. */
                wap_mmc_upload_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_ERROR_MESSAGE_TOO_LARGE, 0);
            }
            else if (size <= 0)
            {
                /* The uploaded mms message file is invalid. */
                wap_mmc_upload_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_INVALID_MESSAGE, 0);
            }
            else
            {
                createMessageFromMMC(MMS_SUFFIX_SEND_REQ);
            }
        }
        else
        {
            wap_mmc_upload_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_INVALID_PARAMETER, 0);
        }
    }
    else
    {
        wap_mmc_upload_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_BUSY, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_upload_msg_output_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_UPLOAD_MSG_RSP primitive to l4c
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  result      [IN]        MmsMsgId msgId
 *  msgId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_mmc_upload_msg_output_req_hldr(module_type mod_id, sap_type sap_id, MmcResult result, MmsMsgId msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    ilm_struct *ilm_ptr = NULL;
    wap_mmc_upload_msg_output_req_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_mmc_upload_msg_output_req_struct*) construct_local_para(
                                                    sizeof(wap_mmc_upload_msg_output_req_struct),
                                                    TD_CTRL);

    if (myMsgPtr)
    {
        memset((char*)myMsgPtr + 4, 0x00, (sizeof(wap_mmc_upload_msg_output_req_struct) - 4));
        myMsgPtr->result = result;
        myMsgPtr->msgId = msgId;

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_MMC_UPLOAD_MSG_OUTPUT_REQ; /* WAP_MMC_UPLOAD_MSG_OUTPUT_REQ */
        ilm_ptr->peer_buff_ptr = NULL;
        SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr) if (result != MMC_RESULT_BUSY)
        {
            MMC_CNTX->state = MMC_IDLE;
            kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));

            if (MSF_moduleIsRunning(MSF_MODID_MMS) && getSenderModule() == MSF_MODID_MMC)
            {
                MMSif_applicationReg(0);
            }
            if (result == MMC_RESULT_OK && MSF_moduleIsRunning(MSF_MODID_MMS))
            {
                if (MSF_moduleIsRunning(MSF_MODID_MEA))
                {
                    meaMMCUpdateFolder();   /* Tell MEA that a new mms message is inserted. */
                }
                else
                {
                    mmsUpdateIndicator();   /* Update indicator icon ourselves */
                }
            }
        }
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                     MMC_ENV_90228FED3C1EFECED7F3E33E6C1BCD89, "%s(%d): MMC module returns wap_mmc_upload_msg_uotput_req with result %d and msgid %d \n",
                     __FILE__, __LINE__, result, msgId));
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                     MMC_ENV_8E46B5156AB6F77D9FF7B64A7A387AC7, "%s(%d): MMC module can't get memory for wap_mmc_upload_msg_uotput_req signal \n", __FILE__,
                     __LINE__));
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_delete_msg_req_ind_hldr
 * DESCRIPTION
 *  Handle a WAP_MMC_DELETE_MSG_IND primitive from l4c
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  Message     [?]         
 *  MmcResult result(?)
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_delete_msg_req_ind_hldr(module_type mod_id, sap_type sap_id, wap_mmc_delete_msg_req_ind_struct *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                 MMC_ENV_3924CA1BD0ED1E767755FBCFC4D516D2, "%s(%d): MMC module receives a wap_mmc_deldete_msg_req_ind from l4c, msgid: %d and folderId: %d \n",
                 __FILE__, __LINE__, Message->msgId, Message->folderId));
    if (MMC_IS_SERVICE_READY() == FALSE)
    {
        wap_mmc_delete_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_MMS_NO_READY);
        return;
    }
    if (MMC_CNTX->state == MMC_IDLE)
    {
        MMC_CNTX->op = MMC_OP_DELETE_MSG;
        MMC_CNTX->state = MMC_DELETE_MSG;
        MMC_CNTX->mod_id = mod_id;
        MMC_CNTX->sap_id = sap_id;

        if (Message->folderId != 0x00)
        {
            if (Message->folderId == MMC_INBOX || Message->folderId == MMC_OUTBOX ||
                Message->folderId == MMC_SENT || Message->folderId == MMC_DRAFTS)
            {
                getMmsFolderStatusFromMMC(Message->folderId);
            }
            else
            {
                wap_mmc_delete_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_INVALID_FOLDER);
            }
        }
        else
        {
            /* Check if the wanted message was opened by MEA. If so, access request is denied. */
            if ((MSF_moduleIsRunning(MSF_MODID_MEA) && Message->msgId == meaMMCGetCurrentActiveMsg()) ||
                (fldrGetFileSuffix(Message->msgId) == MMS_SUFFIX_TEMPLATE))
            {
                wap_mmc_delete_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_ACCESS_DENY);
                return;
            }
            wap_mmc_delete_msg_output_req_hldr(
                mod_id,
                sap_id,
                translateMmsResultToMmc(fldrMgrDeleteMessage(Message->msgId)));
        #ifdef MMS_FILE_PROTECT_SUPPORT
            delChkSumFile(Message->msgId);
        #endif 
        }

    }
    else
    {
        wap_mmc_delete_msg_output_req_hldr(mod_id, sap_id, MMC_RESULT_BUSY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_delete_msg_output_req_hldr
 * DESCRIPTION
 *  Create a WAP_MMC_DELETE_MSG_RSP primitive to l4c
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_mmc_delete_msg_output_req_hldr(module_type mod_id, sap_type sap_id, MmcResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* send MMI dial request indication and initiate a MO call */
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_delete_msg_output_req_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_mmc_delete_msg_output_req_struct*) construct_local_para(
                                                    sizeof(wap_mmc_delete_msg_output_req_struct),
                                                    TD_CTRL);
    memset((char*)myMsgPtr + 4, 0x00, (sizeof(wap_mmc_delete_msg_output_req_struct) - 4));

    if (myMsgPtr)
    {
        myMsgPtr->result = result;
        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
        ilm_ptr->msg_id = MSG_ID_WAP_MMC_DELETE_MSG_OUTPUT_REQ; /* l4cMMS_DELETE_MSG_RSP */
        ilm_ptr->peer_buff_ptr = NULL;
        SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr) if (result != MMC_RESULT_BUSY)
        {
            MMC_CNTX->state = MMC_IDLE;
            kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));
            if (MSF_moduleIsRunning(MSF_MODID_MMS) && getSenderModule() == MSF_MODID_MMC)
            {
                MMSif_applicationReg(0);
            }
            if (result == MMC_RESULT_OK && MSF_moduleIsRunning(MSF_MODID_MMS))
            {
                if (MSF_moduleIsRunning(MSF_MODID_MEA))
                {
                    meaMMCUpdateFolder();   /* Tell MEA that some mms messages are deleted. */
                }
                else
                {
                    mmsUpdateIndicator();   /* Update indicator icon ourselves */
                }
            }
        }
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                     MMC_ENV_5D211EDDA58C554C4F97CD2E43979233, "%s(%d): MMC module returns wap_mmc_delete_msg_output_req with result %d. \n", __FILE__, __LINE__,
                     result));
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                     MMC_ENV_84B4534D6B13AD94D0304FFE2E555843, "%s(%d): MMC module can't get memory for wap_mmc_delete_msg_output_req signal \n", __FILE__,
                     __LINE__));
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_recv_appmms_req
 * DESCRIPTION
 *  This function is used to handle wap_mmc_handle_cfg_appmms_appid_req
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  appId           [?]         
 *  message(?)      [IN]        The wap_mmc_cfg_appmms_appid_req_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_recv_appmms_req(module_type mod_id, sap_type sap_id, MSF_INT8 *appId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 *buffer = NULL;
    MSF_UINT16 buffer_size = 0;
    wap_mmc_recv_appmms_rsp_struct response;
    MmcResult result = MMC_RESULT_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX->state != MMC_IDLE)
    {
        wap_mmc_recv_appmms_rsp_struct response;

        kal_mem_set(&response, 0x00, sizeof(response));
        response.result = MMC_RESULT_BUSY;
        wap_mmc_reply_recv_appmms_rsp(mod_id, sap_id, &response, NULL, 0);
        return;
    }
    MMC_CNTX->op = MMC_OP_RECV_MSG;
    MMC_CNTX->state = MMC_RECV_JSR_MSG_HDR;
    MMC_CNTX->mod_id = mod_id;
    MMC_CNTX->sap_id = sap_id;
    MMC_CNTX->msgId = mmcGenRecvJSRMsgRsp(appId, &response, &result, &buffer, &buffer_size);

    if (MMC_CNTX->msgId == 0)
    {
        mmcCleanContext();
        response.result = result;
        wap_mmc_reply_recv_appmms_rsp(mod_id, sap_id, &response, NULL, 0);
    }
    else
    {
        response.result = MMC_RESULT_OK;
        wap_mmc_reply_recv_appmms_rsp(mod_id, sap_id, &response, buffer, buffer_size);
        if (response.bdy_part_no != 0)
        {
            MMC_CNTX->bdy_no = response.bdy_part_no;
            MMC_CNTX->curr_bdy_no = 1;
            MMC_CNTX->state = MMC_RECV_JSR_MSG_BDY;
        }
        else
        {
            mmcRemoveMsgIdFromJSRIndex(MMC_CNTX->msgId);
            if (MSF_moduleIsRunning(MSF_MODID_MMS) && getSenderModule() == MSF_MODID_MMC)
            {
                MMSif_applicationReg(0);
            }
            if (MSF_moduleIsRunning(MSF_MODID_MEA))
            {
                meaMMCUpdateFolder();
            }
            mmsUpdateIndicator();   /* Update status */

            if (HDIa_widgetExtGetMMSMessageID() == MMC_CNTX->msgId)
            {
                HDIa_widgetExtClearMMS();
            }
            mmcCleanContext();
        }
        MMC_MEM_FREE(buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_reply_recv_appmms_rsp
 * DESCRIPTION
 *  This function is used to handle wap_mmc_handle_cfg_appmms_appid_req
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  response        [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 *  message(?)      [IN]        The wap_mmc_cfg_appmms_appid_req_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_reply_recv_appmms_rsp(
        module_type mod_id,
        sap_type sap_id,
        const wap_mmc_recv_appmms_rsp_struct *response,
        MSF_UINT8 *buffer,
        MSF_UINT16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_recv_appmms_rsp_struct *recv_appmms_rsp = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    MSF_UINT16 peer_pdu_len = 0;
    MSF_UINT8 *peer_pdu = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_appmms_rsp =
        (wap_mmc_recv_appmms_rsp_struct*) construct_local_para(sizeof(wap_mmc_recv_appmms_rsp_struct), TD_CTRL);
    recv_appmms_rsp->result = response->result;
    recv_appmms_rsp->priority = response->priority;
    recv_appmms_rsp->date = response->date;
    recv_appmms_rsp->from_addr_no = response->from_addr_no;
    recv_appmms_rsp->to_addr_no = response->to_addr_no;
    recv_appmms_rsp->cc_addr_no = response->cc_addr_no;
    recv_appmms_rsp->bdy_part_no = response->bdy_part_no;

    recv_appmms_rsp->start_cnt_id_len = response->start_cnt_id_len;
    memcpy(recv_appmms_rsp->start_cnt_id, response->start_cnt_id, 100);
    recv_appmms_rsp->reply_app_id_len = response->reply_app_id_len;
    memcpy(recv_appmms_rsp->reply_app_id, response->reply_app_id, 100);

    if (buffer)
    {
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(buffer_size, 0, 0, TD_CTRL);
        peer_pdu = (MSF_UINT8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        if (peer_pdu)
        {
            memcpy(peer_pdu, buffer, buffer_size);
        }
    }

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) recv_appmms_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_RECV_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = peer_buff_ptr;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_read_appmms_msg_part_req
 * DESCRIPTION
 *  This function is used to handle wap_mmc_handle_cfg_appmms_appid_req
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  message(?)      [IN]        The wap_mmc_cfg_appmms_appid_req_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_read_appmms_msg_part_req(module_type mod_id, sap_type sap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmc_read_appmms_msg_part_rsp_struct read_appmms_msg_part_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX->mod_id != mod_id || MMC_CNTX->sap_id != sap_id || MMC_CNTX->state != MMC_RECV_JSR_MSG_BDY)
    {
        kal_mem_set(&read_appmms_msg_part_rsp, 0x00, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
        read_appmms_msg_part_rsp.result = MMC_RESULT_ACCESS_DENY;
        wap_mmc_reply_read_appmms_msg_part_rsp(mod_id, sap_id, &read_appmms_msg_part_rsp);
    }
    else
    {
        if (mmcGenRecvJSRMsgBodyPartRsp(MMC_CNTX->msgId, MMC_CNTX->curr_bdy_no, &read_appmms_msg_part_rsp) != TRUE)
        {
            kal_mem_set(&read_appmms_msg_part_rsp, 0x00, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
            read_appmms_msg_part_rsp.result = MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
            wap_mmc_reply_read_appmms_msg_part_rsp(mod_id, sap_id, &read_appmms_msg_part_rsp);
            kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));
        }
        else
        {
            wap_mmc_reply_read_appmms_msg_part_rsp(mod_id, sap_id, &read_appmms_msg_part_rsp);
            MMC_CNTX->curr_bdy_no++;
            if (MMC_CNTX->curr_bdy_no > MMC_CNTX->bdy_no)
            {
                mmcRemoveMsgIdFromJSRIndex(MMC_CNTX->msgId);
                if (MSF_moduleIsRunning(MSF_MODID_MMS) && getSenderModule() == MSF_MODID_MMC)
                {
                    MMSif_applicationReg(0);
                }
                if (MSF_moduleIsRunning(MSF_MODID_MEA))
                {
                    meaMMCUpdateFolder();
                }
                mmsUpdateIndicator();   /* Update status */

                if (HDIa_widgetExtGetMMSMessageID() == MMC_CNTX->msgId)
                {
                    HDIa_widgetExtClearMMS();
                }
                mmcCleanContext();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_reply_read_appmms_msg_part_rsp
 * DESCRIPTION
 *  This function is used to reply read_appmms_msg_part_rsp to application
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  response        [IN]        The wap_mmc_read_appmms_msg_part_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_reply_read_appmms_msg_part_rsp(
        module_type mod_id,
        sap_type sap_id,
        wap_mmc_read_appmms_msg_part_rsp_struct *response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_read_appmms_msg_part_rsp_struct *read_appmms_msg_part_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_appmms_msg_part_rsp =
        (wap_mmc_read_appmms_msg_part_rsp_struct*)
        construct_local_para(sizeof(wap_mmc_read_appmms_msg_part_rsp_struct), TD_CTRL);
    read_appmms_msg_part_rsp->result = response->result;
    read_appmms_msg_part_rsp->encoding_scheme = response->encoding_scheme;
    /* Content-Type */
    read_appmms_msg_part_rsp->content_type_value = response->content_type_value;
    read_appmms_msg_part_rsp->content_type_len = response->content_type_len;
    memcpy(read_appmms_msg_part_rsp->content_type, response->content_type, 100);
    /* Content-Id */
    read_appmms_msg_part_rsp->content_id_len = response->content_id_len;
    memcpy(read_appmms_msg_part_rsp->content_id, response->content_id, 100);
    /* Content-Location */
    read_appmms_msg_part_rsp->content_location_len = response->content_location_len;
    memcpy(read_appmms_msg_part_rsp->content_location, response->content_location, 100);
    /* Media object filepath */
    read_appmms_msg_part_rsp->filepath_len = response->filepath_len;
    memcpy(read_appmms_msg_part_rsp->filepath, response->filepath, 200);

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) read_appmms_msg_part_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_cfg_appmms_appid_req
 * DESCRIPTION
 *  This function is used to handle wap_mmc_handle_cfg_appmms_appid_req
 * PARAMETERS
 *  mod_id      [IN]        The source module
 *  sap_id      [IN]        The sap_type
 *  message     [IN]        The wap_mmc_cfg_appmms_appid_req_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_cfg_appmms_appid_req(
        module_type mod_id,
        sap_type sap_id,
        wap_mmc_cfg_appmms_appid_req_struct *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmcResult result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmcCfgAppId(message->app_id, message->app_id_len, (MSF_BOOL) message->op, message->ind_module, sap_id);
    wap_mmc_reply_cfg_appmms_appid_rsp(mod_id, sap_id, result);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_reply_cfg_appmms_appid_rsp
 * DESCRIPTION
 *  This function is used to reply the response of configure application id
 * PARAMETERS
 *  mod_id      [IN]        The source module
 *  sap_id      [IN]        The sap_type
 *  result      [IN]        The result
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_reply_cfg_appmms_appid_rsp(module_type mod_id, sap_type sap_id, MmcResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_cfg_appmms_appid_rsp_struct *cfg_appmms_appid_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfg_appmms_appid_rsp =
        (wap_mmc_cfg_appmms_appid_rsp_struct*) construct_local_para(
                                                sizeof(wap_mmc_cfg_appmms_appid_rsp_struct),
                                                TD_CTRL);
    cfg_appmms_appid_rsp->result = (kal_uint8) result;
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) cfg_appmms_appid_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_send_post_appmms_msg_part_ind
 * DESCRIPTION
 *  This function is used to send ost_appmms_msg_part_ind to application.
 * PARAMETERS
 *  mod_id      [IN]        The source module
 *  sap_id      [IN]        The sap_type
 *  result      [IN]        The result
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_send_post_appmms_msg_part_ind(module_type mod_id, sap_type sap_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_post_appmms_msg_part_ind_struct *post_appmms_msg_part_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    post_appmms_msg_part_ind =
        (wap_mmc_post_appmms_msg_part_ind_struct*)
        construct_local_para(sizeof(wap_mmc_post_appmms_msg_part_ind_struct), TD_CTRL);
    post_appmms_msg_part_ind->result = result;
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) post_appmms_msg_part_ind;
    /* printf("%d,%d,%d,%d\n",MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND,MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES,MSG_ID_WAP_MMC_RECV_APPMMS_REQ,MSG_ID_WAP_MMC_RECV_APPMMS_RSP); */
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_post_appmms_msg_part_res
 * DESCRIPTION
 *  This function is used to send ost_appmms_msg_part_ind to application.
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  message         [?]         
 *  result(?)       [IN]        The result
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_post_appmms_msg_part_res(
        module_type mod_id,
        sap_type sap_id,
        wap_mmc_post_appmms_msg_part_res_struct *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmcResult result;
    MmsBodyParams *bdyParams = NULL;
    unsigned char *cnt_type = NULL;
    unsigned char *cnt_id = NULL;
    unsigned char *cnt_locaton = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX->mod_id != mod_id || MMC_CNTX->sap_id != sap_id || MMC_CNTX->state != MMC_PROCESS_JSR_SND_MSG_BDY)
    {
        wap_mmc_reply_send_appmms_rsp(mod_id, sap_id, MMC_RESULT_ACCESS_DENY);
        return;
    }
    if (strlen((char*)message->content_type) > 0)
    {
        cnt_type = message->content_type;
    }
    if (strlen((char*)message->content_id) > 0)
    {
        cnt_id = message->content_id;
    }
    if (strlen((char*)message->content_location) > 0)
    {
        cnt_locaton = message->content_location;
    }
    ASSERT(message);
    MMC_CNTX->curr_bdy_no++;
    bdyParams = mmcCreateBodyParams(message->encoding_scheme, cnt_type, cnt_id, cnt_locaton);

    result = mmcWriteMessageBodyPart(MMC_JSR_MSG_FILE, bdyParams, message->filepath);
    if (result != MMC_RESULT_OK)
    {
        wap_mmc_reply_send_appmms_rsp(mod_id, sap_id, result);
        mmcCleanContext();
        return;
    }

    if (MMC_CNTX->curr_bdy_no == MMC_CNTX->bdy_no)
    {
        /* Geneate MsgId in Teleca MMS service */
        MMC_CNTX->state = MMC_CREATE_MSG;
        createMessageFromMMC(MMS_SUFFIX_SEND_REQ);
    }
    else
    {
        wap_mmc_send_post_appmms_msg_part_ind(mod_id, sap_id, MMC_RESULT_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_send_appmms_req
 * DESCRIPTION
 *  This function is used to handle wap_mmc_handle_cfg_appmms_appid_req
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  message         [IN]        The wap_mmc_cfg_appmms_appid_req_struct
 *  buffer          [?]         
 *  buffer_size     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_send_appmms_req(
        module_type mod_id,
        sap_type sap_id,
        wap_mmc_send_appmms_req_struct *message,
        MSF_UINT8 *buffer,
        MSF_UINT16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 fsRet = -1;
    MmcResult result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX->state != MMC_IDLE)
    {
        wap_mmc_reply_send_appmms_rsp(mod_id, sap_id, MMC_RESULT_BUSY);
    }
    else
    {
        kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));
        MMC_CNTX->mod_id = mod_id;
        MMC_CNTX->sap_id = sap_id;
        MMC_CNTX->op = MMC_OP_SEND_MSG;
        MMC_CNTX->state = MMC_PROCESS_JSR_SND_MSG_HDR;
        MMC_CNTX->bdy_no = message->bdy_part_no;
        strcpy(MMC_CNTX->msg_filepath, MMC_JSR_MSG_FILE);

        fsRet = MSF_FILE_OPEN(
                    MSF_MODID_MMC,
                    MMC_CNTX->msg_filepath,
                    HDI_FILE_SET_RDWR | HDI_FILE_SET_CREATE | HDI_FILE_SET_CUSTOM_BLOCKING,
                    0);
        if (fsRet < 0)
        {
            wap_mmc_reply_cfg_appmms_appid_rsp(mod_id, sap_id, MMC_RESULT_FILE_OPERATION_ERROR);
            kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));
        }
        else
        {
            /* Retrieve subject, to, cc, bcc address lists */
            MSF_INT8 *start_cnt_id = NULL;
            MSF_INT8 *appId = NULL;
            MSF_INT8 *replyAppId = NULL;
            MSF_INT8 *subject = NULL;
            MmsCharset subject_charset = MMS_UTF8;
            MmsAddressList *to = NULL;
            MmsAddressList *cc = NULL;
            MmsAddressList *bcc = NULL;
            MSF_UINT16 datalen = 0;

            MSF_FILE_CLOSE(fsRet);
            /* Check start_cnt_Id */
            if (message->start_cnt_id_len > 0 && strlen((char*)message->start_cnt_id) > 0)
            {
                start_cnt_id = (MSF_INT8*) message->start_cnt_id;
            }
            /* Check appId */
            if (message->app_id_len > 0 && strlen((char*)message->app_id) > 0)
            {
                appId = (MSF_INT8*) message->app_id;
            }
            /* Check reply appId */
            if (message->reply_app_id_len > 0 && strlen((char*)message->reply_app_id) > 0)
            {
                replyAppId = (MSF_INT8*) message->reply_app_id;
            }
            ASSERT(buffer);
            /* Retrieve Subject */
            {
                MSF_UINT32 subject_len = *(MSF_UINT32*) buffer;
                MSF_UINT32 subject_charset_tp = *(MSF_UINT32*) (buffer + 4);

                if (subject_len > 0)
                {
                    subject = MMC_MEM_ALLOC(subject_len + 1);
                    memcpy(subject, buffer + 8, subject_len);
                    datalen = subject_len + 8;
                    subject_charset = (MmsCharset) subject_charset_tp;
                }
                else
                {
                    datalen = 4;
                }
            }
            /* Retrieve to addresses */
            while (message->to_addr_no > 0)
            {
                MSF_INT8 *address = NULL;
                MSF_UINT32 address_len = 0;
                MSF_UINT8 addrType;

                memcpy(&addrType, (char*)(buffer + datalen), 4);
                memcpy(&address_len, (char*)(buffer + datalen + 4), 4);
                address = MMC_MEM_ALLOC(address_len + 1);
                memcpy(address, buffer + datalen + 8, address_len);
                datalen += address_len + 8;
                ASSERT(mmcAddrListToMms(addrType, address, &to));
                MMC_MEM_FREE(address);
                message->to_addr_no--;
            }
            /* Retrieve cc addresses */
            while (message->cc_addr_no > 0)
            {
                MSF_INT8 *address = NULL;
                MSF_UINT32 address_len = 0;
                MSF_UINT8 addrType;

                memcpy(&addrType, (char*)(buffer + datalen), 4);
                memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

                address = MMC_MEM_ALLOC(address_len + 1);
                memcpy(address, buffer + datalen + 8, address_len);
                datalen += address_len + 8;
                ASSERT(mmcAddrListToMms(addrType, address, &cc));
                MMC_MEM_FREE(address);
                message->cc_addr_no--;
            }
            /* Retrieve bcc addresses */
            while (message->bcc_addr_no > 0)
            {
                MSF_INT8 *address = NULL;
                MSF_UINT32 address_len = 0;
                MSF_UINT8 addrType;

                memcpy(&addrType, (char*)(buffer + datalen), 4);
                memcpy(&address_len, (char*)(buffer + datalen + 4), 4);

                address = MMC_MEM_ALLOC(address_len + 1);
                memcpy(address, buffer + datalen + 8, address_len);
                datalen += address_len + 8;
                ASSERT(mmcAddrListToMms(addrType, address, &bcc));
                MMC_MEM_FREE(address);
                message->bcc_addr_no--;
            }
            /* Create Message header and write it to file */
            {
                MmsSetHeader *setHeader = NULL;

                /* Generate MMS message header */
                setHeader = mmcCreateMessageHeader(
                                !message->mms_type,
                                message->priority,
                                to,
                                cc,
                                bcc,
                                message->delivery_time,
                                subject,
                                subject_charset,
                                start_cnt_id,
                                appId,
                                replyAppId);

                if (setHeader == NULL)
                {
                    /* Fail to generate MMS header. */
                    if (to)
                    {
                        mmcFreeMmsAddressList(to);
                    }
                    if (cc)
                    {
                        mmcFreeMmsAddressList(cc);
                    }
                    if (bcc)
                    {
                        mmcFreeMmsAddressList(bcc);
                    }
                    if (subject)
                    {
                        MMC_MEM_FREE(subject);
                    }
                    wap_mmc_reply_send_appmms_rsp(mod_id, sap_id, MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR);
                    kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));
                    return;
                }
                if (subject)
                {
                    MMC_MEM_FREE(subject);
                }

                /* Write MMS message header to file */
                result = mmcWriteMessageHeader(MMC_JSR_MSG_FILE, setHeader, MMS_VERSION_10, message->bdy_part_no);
                freeMmsSetHeader(MSF_MODID_MMC, setHeader);
                if (result != MMC_RESULT_OK)
                {
                    wap_mmc_reply_send_appmms_rsp(mod_id, sap_id, MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR);
                    kal_mem_set(MMC_CNTX, 0x00, sizeof(MmcContext));
                }
                else
                {
                    if (MMC_CNTX->bdy_no == MMC_CNTX->curr_bdy_no)
                    {
                        /* Create msg Id in Teleca MMS serive */
                        MMC_CNTX->state = MMC_CREATE_MSG;
                        createMessageFromMMC(MMS_SUFFIX_SEND_REQ);
                        return;
                    }
                    else
                    {
                        MMC_CNTX->state = MMC_PROCESS_JSR_SND_MSG_BDY;
                        wap_mmc_send_post_appmms_msg_part_ind(mod_id, sap_id, MMC_RESULT_OK);
                    }
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_reply_send_appmms_rsp
 * DESCRIPTION
 *  This function is used to reply the response of sending MMS
 * PARAMETERS
 *  mod_id      [IN]        The source module
 *  sap_id      [IN]        The sap_type
 *  result      [IN]        The result
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_reply_send_appmms_rsp(module_type mod_id, sap_type sap_id, MmcResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_send_appmms_rsp_struct *send_appmms_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_appmms_rsp =
        (wap_mmc_send_appmms_rsp_struct*) construct_local_para(sizeof(wap_mmc_send_appmms_rsp_struct), TD_CTRL);
    send_appmms_rsp->result = (kal_uint8) result;
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) send_appmms_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_SEND_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_check_appmms_coming_req
 * DESCRIPTION
 *  This function is used to check if there are any MMS messages belong to the specific application id.
 * PARAMETERS
 *  mod_id      [IN]        The source module
 *  sap_id      [IN]        The sap_type
 *  message     [IN]        The wap_mmc_check_appmms_coming_req_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_check_appmms_coming_req(
        module_type mod_id,
        sap_type sap_id,
        wap_mmc_check_appmms_coming_req_struct *message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_BOOL result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmcCheckAppIdMsgs((MSF_INT8*) message->app_id, message->only_new);
    wap_mmc_reply_check_appmms_coming_rsp(mod_id, sap_id, result);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_reply_check_appmms_coming_rsp
 * DESCRIPTION
 *  This function is used to reply the result of check_appmms_coming_req to application.
 * PARAMETERS
 *  mod_id      [IN]        The source module
 *  sap_id      [IN]        The sap_type
 *  result      [IN]        The result
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_reply_check_appmms_coming_rsp(module_type mod_id, sap_type sap_id, MSF_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_check_appmms_coming_rsp_struct *check_appmms_coming_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    check_appmms_coming_rsp =
        (wap_mmc_check_appmms_coming_rsp_struct*) construct_local_para(
                                                    sizeof(wap_mmc_check_appmms_coming_rsp_struct),
                                                    TD_CTRL);
    check_appmms_coming_rsp->result = (result) ? (KAL_TRUE) : (KAL_FALSE);
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) check_appmms_coming_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_abort_appmms_req
 * DESCRIPTION
 *  This function is used to abort sending or receiving MMS
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  wap_mmc_upload_msg_req_ind_struct Message(?)
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_abort_appmms_req(module_type mod_id, sap_type sap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMC_CNTX->op != MMC_OP_SEND_MSG && MMC_CNTX->op != MMC_OP_RECV_MSG)
    {
        wap_mmc_reply_abort_appmms_rsp(mod_id, sap_id, MMC_RESULT_ACCESS_DENY);
    }
    else
    {
        if (MMC_CNTX->op == MMC_OP_SEND_MSG)
        {
            if (MMC_CNTX->state == MMC_PROCESS_JSR_SND_MSG_HDR || MMC_CNTX->state == MMC_PROCESS_JSR_SND_MSG_BDY)
            {
                goto reply_ret;
            }
            else if (MMC_CHECK_FLAG(MMC_FLAG_WAIT_SEND_MSG_REPLY))
            {
                cancelSendMessageFromMMC(MMC_CNTX->msgId);
            }
            MMC_SET_FLAG(MMC_FLAG_ABORT);

        }
        else
        {
          reply_ret:
            wap_mmc_reply_abort_appmms_rsp(mod_id, sap_id, MMC_RESULT_OK);
            MSF_FILE_REMOVE(MMC_JSR_MEDIA_OBJECT_FILE);
            mmcCleanContext();
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_reply_abort_appmms_rsp
 * DESCRIPTION
 *  This function is used to abort sending or receiving MMS
 * PARAMETERS
 *  mod_id      [IN]        
 *  sap_id      [IN]        
 *  result      [IN]        
 *  wap_mmc_upload_msg_req_ind_struct Message(?)
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_reply_abort_appmms_rsp(module_type mod_id, sap_type sap_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_abort_appmms_rsp_struct *abort_appmms_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abort_appmms_rsp =
        (wap_mmc_abort_appmms_rsp_struct*) construct_local_para(sizeof(wap_mmc_abort_appmms_rsp_struct), TD_CTRL);
    abort_appmms_rsp->result = result;
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) abort_appmms_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_ABORT_APPMMS_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_handle_get_mms_prof_req
 * DESCRIPTION
 *  This function is used to get MMS profile element specified.
 * PARAMETERS
 *  mod_id          [IN]        The source module
 *  sap_id          [IN]        The sap_type
 *  prof_id         [IN]        
 *  message(?)      [IN]        The wap_mmc_check_appmms_coming_req_struct
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_handle_get_mms_prof_req(module_type mod_id, sap_type sap_id, kal_uint32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern char *cfgGetStr(MmsConfigStr key);

    kal_uint8 result = 1;   /* not ready */
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_get_mms_prof_rsp_struct *get_mms_prof_rsp = NULL;
    kal_uint8 val_len = 0;
    kal_uint8 *value = NULL;

#ifdef MMS_SUPPORT
    if (MSF_moduleIsRunning(MSF_MODID_MMC))
    {
        switch (prof_id)
        {
            case WAP_MMS_PROF_MMSC_ADDRESS:
            {
                int mms_prof_id;

                value = MMC_MEM_ALLOC(256);
                mms_prof_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_MMS_PROF_ID);
                if (bra_prof_off_line_read_profile_key(mms_prof_id, BRA_PROF_KEY_HOMEPAGE_URL, (char*)value) > 0)
                {
                    val_len = strlen((char*)value) + 1;
                    if (val_len > 256)
                    {
                        ASSERT(0);  /* memory corruption */
                    }
                    result = 0;
                }
                break;
            }
        }
    }
#endif /* MMS_SUPPORT */ 
    get_mms_prof_rsp =
        (wap_mmc_get_mms_prof_rsp_struct*) construct_local_para(sizeof(wap_mmc_get_mms_prof_rsp_struct), TD_CTRL);
    get_mms_prof_rsp->result = result;
    get_mms_prof_rsp->value_len = val_len;
    if (val_len > 0 && value != NULL)
    {
        memcpy(get_mms_prof_rsp->value, value, val_len);
    }
    if (value != NULL)
    {
        MMC_MEM_FREE(value);
    }
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) get_mms_prof_rsp;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_GET_MMS_PROF_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmc_send_appmms_new_mms_ind
 * DESCRIPTION
 *  This function is used to send MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND to java module.
 * PARAMETERS
 *  mod_id          [IN]        
 *  sap_id          [IN]        
 *  app_id          [IN]        
 *  app_id_len      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_mmc_send_appmms_new_mms_ind(module_type mod_id, sap_type sap_id, MSF_UINT8 *app_id, MSF_UINT8 app_id_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmc_appmms_new_mms_ind_struct *appmms_new_mms_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    appmms_new_mms_ind =
        (wap_mmc_appmms_new_mms_ind_struct*) construct_local_para(sizeof(wap_mmc_appmms_new_mms_ind_struct), TD_CTRL);
    memcpy(appmms_new_mms_ind->app_id, app_id, app_id_len);
    appmms_new_mms_ind->app_id_len = app_id_len;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) appmms_new_mms_ind;
    ilm_ptr->msg_id = MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, mod_id, sap_id, ilm_ptr);
}
#endif /* MMS_SUPPORT */ 

#endif /* MMSAT_SUPPORT */ 

