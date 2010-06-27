/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2004
*
*****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 * mmc_jsr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides JAVA MMS functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#define MMC_JSR_C

#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */

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
#include "mmsl_if.h"
#include "mcpdu.h"
#include "msig.h"
#include "fldmgr.h"
#include "mltypes.h"
#include "mutils.h"
#include "mms_aApp.h"
#include "QueueGprot.h" /* For send an primitive to L4 */
#include "msf_def.h"
#include "stack_timer.h"        /* Stack timer */
#include "l4a.h"
#include "wapadp.h"
#include "wap_ps_struct.h"
#include "mmc_env.h"
#include "mmc_jsr.h"
#include "app_str.h"
#include "app_asyncfile.h"

#ifdef MMS_SUPPORT

extern MSF_BOOL MMS_FILE_OPEN_BLOCK_FLAG;
extern MmcContext *mmsContext_p;

extern unsigned char *createBodyPartHeader(
                        MSF_UINT8 modId,
                        MSF_UINT32 *encHeaderLen,
                        const MmsBodyParams *bodyParams,
                        MSF_UINT32 size,
                        MmsResult *result);
extern unsigned char *createWspSendHeader(
                        MSF_UINT8 modId,
                        const MmsSetHeader *header,
                        MSF_UINT32 *length,
                        MmsResult *result,
                        MmsVersion version,
                        MSF_UINT32 numOfBodyParts);
extern char *MMSlib_getMessageFullPath(MSF_UINT8 modId, MmsMsgId msgId, MmsFileType fileType);
extern MmsMessageFolderInfo *fldrMgrGetMsgInfo(MSF_UINT32 msgId);
extern int msm_get_module_status(MSF_UINT8 modId);
extern MSF_UINT32 fileName2MsgId(char *fName);
extern MmcResult translateMmsResultToMmc(MmsResult result);

mmc_jsr_index_struct *mmc_jsr_msg_db = NULL;
mmc_jsr_appid_info_struct *mmc_jsr_appId_db[MMC_MAX_JSR_APP_ID_NUM];

typedef struct
{
    char fileName[MMS_FILE_LEN];
    MSF_UINT32 msgId;
    MSF_UINT32 size;
    char suffix;
} mmsFileInFolder;


/*****************************************************************************
 * FUNCTION
 *  mmcRemoveMsgInfoFromList
 * DESCRIPTION
 *  This function is used to remove mmc_jsr_msg_info to list
 * PARAMETERS
 *  list        [IN/OUT]        The mmc_jsr_msg_info list
 *  msgId       [IN]            MsgId
 *  target      [IN]            Mmc_jsr_msg_info pointer
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcRemoveMsgInfoFromList(mmc_jsr_msg_info **list, MSF_UINT32 msgId, mmc_jsr_msg_info *target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_msg_info *msg_info_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list == NULL || *list == NULL)
    {
        return FALSE;
    }

    msg_info_list = *list;

    while (msg_info_list)
    {
        if (msg_info_list->msgId == msgId || (target != NULL && msg_info_list == target))
        {
            if (msg_info_list == *list)
            {
                *list = msg_info_list->next;
                if (msg_info_list->next)
                {
                    msg_info_list->next->prev = msg_info_list->next;
                }
            }
            else
            {
                msg_info_list->prev->next = msg_info_list->next;
                if (msg_info_list->next)
                {
                    msg_info_list->next->prev = msg_info_list->prev;
                }
            }
            fldrMgrDeleteMessage(msg_info_list->msgId);
        #ifdef MMS_FILE_PROTECT_SUPPORT
            delChkSumFile(msg_info_list->msgId);
        #endif 
            MMC_MEM_FREE(msg_info_list);
            return TRUE;
        }
        msg_info_list = msg_info_list->next;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcRemoveMsgInfoFromListRescurive
 * DESCRIPTION
 *  This function is used to remove all mmc_jsr_msg_info in one list
 * PARAMETERS
 *  list        [IN/OUT]        The mmc_jsr_msg_info list
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcRemoveMsgInfoFromListRescurive(mmc_jsr_msg_info **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_msg_info *msg_info_list;
    mmc_jsr_msg_info *msg_info_list_tp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list == NULL || *list == NULL)
    {
        return FALSE;
    }

    msg_info_list = *list;
    while (msg_info_list)
    {
        msg_info_list_tp = msg_info_list->next;
        fldrMgrDeleteMessage(msg_info_list->msgId);
    #ifdef MMS_FILE_PROTECT_SUPPORT
        delChkSumFile(msg_info_list->msgId);
    #endif 
        MMC_MEM_FREE(msg_info_list);
        msg_info_list = msg_info_list_tp;
    }
    *list = NULL;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcInsertMsgInfoToList
 * DESCRIPTION
 *  This function is used to insert mmc_jsr_msg_info to list
 * PARAMETERS
 *  list            [IN/OUT]        The mmc_jsr_msg_info list
 *  msgId           [IN]            MsgId
 *  isChecked       [IN]            IsChecked
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcInsertMsgInfoToList(mmc_jsr_msg_info **list, MSF_UINT32 msgId, MSF_BOOL isChecked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_msg_info *new_msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list == NULL)
    {
        return FALSE;
    }
    new_msg_info = (mmc_jsr_msg_info*) MMC_MEM_ALLOC(sizeof(mmc_jsr_msg_info));
    ASSERT(new_msg_info);
    new_msg_info->msgId = msgId;
    new_msg_info->isChecked = isChecked;
    if (*list == NULL)
    {
        new_msg_info->prev = new_msg_info;
        *list = new_msg_info;
        return TRUE;
    }
    else
    {
        mmc_jsr_msg_info *msg_info_list = *list;

        while (msg_info_list->next)
        {
            if (msg_info_list->msgId == msgId)
            {
                /* Error. You can not come here. */
                MMC_MEM_FREE(new_msg_info);
                return TRUE;
            }
            msg_info_list = msg_info_list->next;
        }
        msg_info_list->next = new_msg_info;
        new_msg_info->prev = msg_info_list;
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcRemoveAppIdnfoFromList
 * DESCRIPTION
 *  This function is used to remove mmc_jsr_appid_object_list_struct to list
 * PARAMETERS
 *  list        [IN/OUT]        The mmc_jsr_appid_object_list_struct list
 *  appId       [IN]            AppId
 *  target      [IN]            Mmc_jsr_appid_object_list_struct pointer
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcRemoveAppIdnfoFromList(
            mmc_jsr_appid_object_list_struct **list,
            MSF_INT8 *appId,
            mmc_jsr_appid_object_list_struct *target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_appid_object_list_struct *appid_info_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list == NULL || *list == NULL)
    {
        return FALSE;
    }

    appid_info_list = *list;
    while (appid_info_list)
    {
        if ((appid_info_list->appid && appId && strcmp((char*)appid_info_list->appid, (char*)appId) == 0) ||
            (target != NULL && appid_info_list == target))
        {
            if (appid_info_list == *list)
            {
                *list = appid_info_list->next;
                if (appid_info_list->next)
                {
                    appid_info_list->next->prev = appid_info_list->next;
                }
            }
            else
            {
                appid_info_list->prev->next = appid_info_list->next;
                if (appid_info_list->next)
                {
                    appid_info_list->next->prev = appid_info_list->prev;
                }
            }
            MMC_MEM_FREE(appid_info_list->appid);
            mmcRemoveMsgInfoFromListRescurive(&appid_info_list->msgs);
            MMC_MEM_FREE(appid_info_list);
            return TRUE;
        }
        appid_info_list = appid_info_list->next;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcRemoveAppIdnfoFromListRescurive
 * DESCRIPTION
 *  This function is used to remove all mmc_jsr_appid_object_list_struct in one list
 * PARAMETERS
 *  list        [IN/OUT]        The mmc_jsr_appid_object_list_struct list
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcRemoveAppIdnfoFromListRescurive(mmc_jsr_appid_object_list_struct **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_appid_object_list_struct *appid_info_list;
    mmc_jsr_appid_object_list_struct *appid_info_list_tp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list == NULL || *list == NULL)
    {
        return FALSE;
    }

    appid_info_list = *list;
    while (appid_info_list)
    {
        appid_info_list_tp = appid_info_list->next;
        MMC_MEM_FREE(appid_info_list->appid);
        mmcRemoveMsgInfoFromListRescurive(&appid_info_list->msgs);
        MMC_MEM_FREE(appid_info_list);
        appid_info_list = appid_info_list_tp;
    }
    *list = NULL;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcInsertAppIdInfoToList
 * DESCRIPTION
 *  This function is used to insert mmc_jsr_appid_object_list_struct to list
 * PARAMETERS
 *  list        [IN/OUT]        The mmc_jsr_appid_object_list_struct list
 *  appid       [IN]            Appid
 *  msgs        [IN]            Msgs
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcInsertAppIdInfoToList(
            mmc_jsr_appid_object_list_struct **list,
            const MSF_INT8 *appid,
            mmc_jsr_msg_info *msgs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_appid_object_list_struct *new_appid_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list == NULL)
    {
        return FALSE;
    }

    new_appid_info = MMC_MEM_ALLOC(sizeof(mmc_jsr_appid_object_list_struct));
    ASSERT(new_appid_info);
    new_appid_info->appid = MMC_MEM_ALLOC(strlen((char*)appid) + 1);
    ASSERT(new_appid_info->appid);
    strcpy((char*)new_appid_info->appid, (char*)appid);
    new_appid_info->msgs = msgs;
    if (*list == NULL)
    {
        new_appid_info->prev = new_appid_info;
        *list = new_appid_info;
        return TRUE;
    }
    else
    {
        mmc_jsr_appid_object_list_struct *appid_info_list = *list;

        while (appid_info_list->next)
        {
            appid_info_list = appid_info_list->next;
        }
        appid_info_list->next = new_appid_info;
        new_appid_info->prev = appid_info_list;
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcRemoveMsgIdFromJSRIndex
 * DESCRIPTION
 *  This function is used to remove msgId from MMC JSR index
 * PARAMETERS
 *  msgId       [IN]        MsgId
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcRemoveMsgIdFromJSRIndex(MSF_UINT32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_jsr_msg_db == NULL)
    {
        mmcRestoreJSRIndex();
    }
    if (mmc_jsr_msg_db->jsr_mms_info)
    {
        mmc_jsr_appid_object_list_struct *appids_list = mmc_jsr_msg_db->jsr_mms_info;

        while (appids_list)
        {
            if (appids_list->msgs)
            {
                mmc_jsr_msg_info *msgs_list = appids_list->msgs;

                while (msgs_list)
                {
                    if (msgs_list->msgId == msgId)
                    {
                        mmcRemoveMsgInfoFromList(&appids_list->msgs, msgId, NULL);
                        if (appids_list->msgs == NULL)
                        {
                            mmcRemoveAppIdnfoFromList(&mmc_jsr_msg_db->jsr_mms_info, appids_list->appid, NULL);
                        }
                        mmcWriteJSRIndex();
                        return TRUE;
                    }
                    msgs_list = msgs_list->next;
                }
            }
            appids_list = appids_list->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcInsertMsgIdToJSRIndex
 * DESCRIPTION
 *  This function is used to insert msgId to MMC JSR index
 * PARAMETERS
 *  appId           [IN]        AppId
 *  msgId           [IN]        MsgId
 *  isChecked       [IN]        IsChecked
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcInsertMsgIdToJSRIndex(const MSF_INT8 *appId, MSF_UINT32 msgId, MSF_BOOL isChecked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmc_jsr_msg_info *msgs = NULL;
    MSF_BOOL ret = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_jsr_msg_db == NULL)
    {
        mmcRestoreJSRIndex();
    }
    if (mmc_jsr_msg_db->jsr_mms_info)
    {
        mmc_jsr_appid_object_list_struct *appids_list = mmc_jsr_msg_db->jsr_mms_info;

        while (appids_list)
        {
            if (appids_list->appid && strcmp((char*)appids_list->appid, (char*)appId) == 0)
            {
                ret = mmcInsertMsgInfoToList(&appids_list->msgs, msgId, isChecked);
                goto exit;
            }
            appids_list = appids_list->next;
        }
    }
    ret =
        (mmcInsertMsgInfoToList(&msgs, msgId, isChecked) &
         mmcInsertAppIdInfoToList(&mmc_jsr_msg_db->jsr_mms_info, appId, msgs));
  exit:
    if (ret == TRUE)
    {
        mmcWriteJSRIndex();
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmcIsJSRMsg
 * DESCRIPTION
 *  This function is used to generate the checksum of data
 * PARAMETERS
 *  msgId           [IN]        
 *  data(?)         [IN]        Input data
 *  datalen(?)      [IN]        Data length
 * RETURNS
 *  void
 *****************************************************************************/
MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_jsr_msg_db == NULL)
    {
        mmcRestoreJSRIndex();
    }

    if (mmc_jsr_msg_db->jsr_mms_info)
    {
        mmc_jsr_appid_object_list_struct *appids_list = mmc_jsr_msg_db->jsr_mms_info;

        while (appids_list)
        {
            if (appids_list->msgs)
            {
                mmc_jsr_msg_info *msgs_list = appids_list->msgs;

                while (msgs_list)
                {
                    if (msgs_list->msgId == msgId)
                    {
                        return TRUE;
                    }
                    msgs_list = msgs_list->next;
                }
            }
            appids_list = appids_list->next;
        }

    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcGenChecksumFromFile
 * DESCRIPTION
 *  This function is used to generate the checksum of file
 * PARAMETERS
 *  filepath            [IN]            Filepath
 *  startpos            [IN]            File startpos
 *  checksum            [IN/OUT]        Output checksum
 *  max_chrs_line       [?]             
 *  max_chr_line(?)     [IN/OUT]        Max characters number of one line
 * RETURNS
 *  0 means success. negative means fail
 *****************************************************************************/
MSF_BOOL mmcGenChecksumFromFile(
            MSF_INT8 *filepath,
            MSF_UINT32 startpos,
            MSF_UINT32 *checksum,
            MSF_UINT32 *max_chrs_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT16 i;
    MSF_UINT8 buf[512];
    MSF_INT32 ret = 0;
    MSF_INT32 fileHandle;
    MSF_INT32 fileSize;
    MSF_UINT32 length;
    MSF_UINT32 sum = 0;
    MSF_BOOL CR = FALSE;
    MSF_UINT32 max_chrs_num = 0;
    MSF_UINT32 chrs_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileHandle = MSF_FILE_OPEN(MSF_MODID_MMC, (char*)filepath, HDI_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
    if (fileHandle < 0)
    {
        return fileHandle;
    }

    ret = MSF_FILE_GETSIZE((char*)filepath);
    if (ret < 0)
    {
        goto exit;
    }
    fileSize = ret;

    ret = MSF_FILE_SEEK(fileHandle, startpos, MSF_FILE_SEEK_SET);
    if (ret < 0)
    {
        goto exit;
    }

    fileSize -= startpos;

    while (fileSize)
    {
        if (fileSize > 512)
        {
            length = 512;
        }
        else
        {
            length = fileSize;
        }
        if ((ret = MSF_FILE_READ(fileHandle, buf, length)) < 0)
        {
            goto exit;
        }
        for (i = 0; i < length; i++)
        {
            sum += buf[i];
            chrs_num++;
            if (*(buf + i) == '\r')
            {
                CR = TRUE;
            }
            else if (*(buf + i) == '\n')
            {
                if (CR == TRUE)
                {
                    if (chrs_num > max_chrs_num)
                    {
                        max_chrs_num = chrs_num;
                    }
                    chrs_num = 0;
                    CR = FALSE;
                }
            }
            else
            {
                CR = FALSE;
            }
        }
        fileSize -= length;
    }
    *checksum = sum;
    *max_chrs_line = max_chrs_num;
    MSF_FILE_CLOSE(fileHandle);
    return TRUE;
  exit:
    MSF_FILE_CLOSE(fileHandle);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcGenCheckSumFromBuffer
 * DESCRIPTION
 *  This function is used to generate the checksum of data
 * PARAMETERS
 *  data        [IN]        Input data
 *  datalen     [IN]        Data length
 * RETURNS
 *  void
 *****************************************************************************/
MSF_UINT32 mmcGenCheckSumFromBuffer(MSF_UINT8 *data, MSF_UINT32 datalen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 sum = 0;
    MSF_UINT32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < datalen; i++)
    {
        sum += *(data + i);
    }
    return sum;
}


/*****************************************************************************
 * FUNCTION
 *  mmcCfgAppId
 * DESCRIPTION
 *  This function is used to check if there are any mms messages for the specific application id.
 * PARAMETERS
 *  app_id_str          [?]         
 *  app_id_strlen       [IN]        
 *  isRemove            [IN]        
 *  ind_module          [IN]        
 *  sap_id              [IN]        
 *  app_id(?)           [IN]        The application id
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MmcResult mmcCfgAppId(
            MSF_UINT8 *app_id_str,
            MSF_UINT8 app_id_strlen,
            MSF_BOOL isRemove,
            module_type ind_module,
            sap_type sap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id_str == NULL || app_id_strlen == 0)
    {
        return MMC_RESULT_INVALID_PARAMETER;
    }
    if (isRemove == TRUE)
    {
        for (i = 0; i < MMC_MAX_JSR_APP_ID_NUM; i++)
        {
            if (mmc_jsr_appId_db[i] && mmc_jsr_appId_db[i]->appId &&
                strcmp((char*)mmc_jsr_appId_db[i]->appId, (char*)app_id_str) == 0)
            {
                MMC_MEM_FREE(mmc_jsr_appId_db[i]->appId);
                MMC_MEM_FREE(mmc_jsr_appId_db[i]);
                mmc_jsr_appId_db[i] = NULL;
                return MMC_RESULT_OK;
            }
        }
        return MMC_RESULT_ERROR_APPID_NOT_FOUND;
    }
    else
    {
        MSF_INT32 empty_slot = -1;

        for (i = 0; i < MMC_MAX_JSR_APP_ID_NUM; i++)
        {
            if (mmc_jsr_appId_db[i] == NULL)
            {
                empty_slot = i;
            }
            else
            {
                if (mmc_jsr_appId_db[i]->appId && strcmp((char*)mmc_jsr_appId_db[i]->appId, (char*)app_id_str) == 0)
                {
                    return MMC_RESULT_ERROR_APPID_EXIST;
                }
            }
            if (empty_slot < 0)
            {
                return MMC_RESULT_ERROR_APPID_FULL;
            }
            else
            {
                mmc_jsr_appId_db[i] = MMC_MEM_ALLOC(sizeof(mmc_jsr_appid_info_struct));
                mmc_jsr_appId_db[i]->appId = MMC_MEM_ALLOC(app_id_strlen + 1);
                memcpy(mmc_jsr_appId_db[i]->appId, app_id_str, app_id_strlen);
                mmc_jsr_appId_db[i]->ind_module = ind_module;
                mmc_jsr_appId_db[i]->ind_sap_id = sap_id;
                return MMC_RESULT_OK;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcGetJsrAppIdInfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id_str      [?]     
 *  ind_module      [?]     
 *  ind_sap_id      [?]     
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mmcGetJsrAppIdInfo(MSF_INT8 *app_id_str, module_type *ind_module, sap_type *ind_sap_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMC_MAX_JSR_APP_ID_NUM; i++)
    {
        if (mmc_jsr_appId_db[i] && mmc_jsr_appId_db[i]->appId &&
            strcmp((char*)mmc_jsr_appId_db[i]->appId, (char*)app_id_str) == 0)
        {
            *ind_module = mmc_jsr_appId_db[i]->ind_module;
            *ind_sap_id = mmc_jsr_appId_db[i]->ind_sap_id;
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcGenRecvJSRMsgRsp
 * DESCRIPTION
 *  This function is used to generate response for MSG_ID_WAP_MMC_RECV_APPMMS_REQ.
 * PARAMETERS
 *  appId           [?]             
 *  response        [IN/OUT]        The output wap_mmc_recv_appmms_rsp_struct
 *  result          [?]             
 *  buffer          [IN/OUT]        The output peer buffer in MSG_ID_WAP_MMC_RECV_APPMMS_RSP
 *  buffer_size     [IN/OUT]        The buffer size
 *  app_id(?)       [IN]            The application id
 * RETURNS
 *  msgId (0 means fail)
 *****************************************************************************/
MSF_UINT32 mmcGenRecvJSRMsgRsp(
            MSF_INT8 *appId,
            wap_mmc_recv_appmms_rsp_struct *response,
            MmcResult *result,
            MSF_UINT8 **buffer,
            MSF_UINT16 *buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 msgId = 0;
    MSF_INT8 *buf = NULL;
    MSF_UINT16 buf_size = 0;

    mmc_jsr_appid_object_list_struct *appids_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appId == NULL || response == NULL)
    {
        *result = MMC_RESULT_INVALID_PARAMETER;
        return 0;
    }
    else if (mmc_jsr_msg_db == NULL)
    {
        mmcRestoreJSRIndex();
    }

    appids_list = mmc_jsr_msg_db->jsr_mms_info;
    while (appids_list)
    {
        if (appids_list->appid && msf_cmmn_strcmp_nc((char*)appids_list->appid, (char*)appId) == 0)
        {
            MmsGetHeader header;
            MSF_UINT16 datalen = 0;

            ASSERT(appids_list->msgs);
            msgId = appids_list->msgs->msgId;

            if (mmcGetMmsMsgHeader(msgId, &header) == FALSE)
            {
                mmcRemoveMsgIdFromJSRIndex(msgId);
                *result = MMC_RESULT_ERROR_MSG_CORRUPTED;
                return 0;
            }

            kal_mem_set(response, 0x00, sizeof(wap_mmc_recv_appmms_rsp_struct));
            response->bdy_part_no = header.bodyInfoList.numOfEntries;
            response->date = header.date;
            if (header.priority == MMS_PRIORITY_LOW)
            {
                response->priority = 0;
            }
            else if (header.priority == MMS_PRIORITY_HIGH)
            {
                response->priority = 2;
            }
            else
            {
                response->priority = 1;
            }
            /* Calculate numbers of from, cc and bcc addresses and buffer size required */
            /* Subject */
            buf_size += 4;  /* subject_data_len 4bytes; */
            if (header.subject.text)
            {
                buf_size += 4;  /* subject_encode_type 4bytes */
                if (*(header.subject.text) == 0x7F)
                {
                    buf_size += (strlen(header.subject.text) - 1);
                }
                else
                {
                    buf_size += strlen(header.subject.text);
                }

            }
            /* from address */
            if (header.from.address)
            {
                response->from_addr_no = 1;
                buf_size += (8 + strlen(header.from.address));
            }

            /* to address */
            if (header.to)
            {
                MmsAddressList *to_list = header.to;

                while (to_list)
                {
                    if (to_list->current.address)
                    {
                        response->to_addr_no += 1;
                        buf_size += (8 + strlen(to_list->current.address));
                    }
                    to_list = to_list->next;
                }
            }
            /* cc address */
            if (header.cc)
            {
                MmsAddressList *cc_list = header.cc;

                while (cc_list)
                {
                    if (cc_list->current.address)
                    {
                        response->cc_addr_no += 1;
                        buf_size += (8 + strlen(cc_list->current.address));
                    }
                    cc_list = cc_list->next;
                }
            }

            /* Get Start Content-Id and reply application id */
            response->start_cnt_id_len = 0;
            response->reply_app_id_len = 0;
            if (header.bodyInfoList.contentType && header.bodyInfoList.contentType->params)
            {
                MmsAllParams *params = header.bodyInfoList.contentType->params;

                while (params)
                {
                    if ((params->param == MMS_START_REL || params->param == MMS_START_REL_14) ||
                        (params->key != NULL && msf_cmmn_strcmp_nc((char*)params->key, "start") == 0))
                    {
                        if (params->value.string)
                        {
                            response->start_cnt_id_len = strlen((char*)params->value.string);
                            if (response->start_cnt_id_len > 99)
                            {
                                response->start_cnt_id_len = 99;
                            }
                            memcpy(response->start_cnt_id, params->value.string, response->start_cnt_id_len);
                        }
                    }
                    else if (params->key != NULL &&
                             msf_cmmn_strcmp_nc((char*)params->key, "Reply-To-Application-ID") == 0)
                    {
                        if (params->value.string)
                        {
                            response->reply_app_id_len = strlen((char*)params->value.string);
                            if (response->reply_app_id_len > 99)
                            {
                                response->reply_app_id_len = 99;
                            }
                            memcpy(response->reply_app_id, params->value.string, response->reply_app_id_len);
                        }
                    }
                    params = params->next;
                }
            }
            buf = MMC_MEM_ALLOC(buf_size);
            ASSERT(buf);

            /* Step 1: Pack subject */
            if (header.subject.text)
            {
                MSF_UINT32 subject_len = strlen(header.subject.text);

                if (*(header.subject.text) == 0x7F)
                {
                    subject_len -= 1;
                }

                *(MSF_UINT32*) buf = subject_len;
                *(MSF_UINT32*) (buf + 4) = header.subject.charset;
                if (*(header.subject.text) == 0x7F)
                {
                    memcpy(buf + 8, (header.subject.text + 1), subject_len);
                }
                else
                {
                    memcpy(buf + 8, header.subject.text, subject_len);
                }
                datalen += (8 + subject_len);
            }
            else
            {
                *(MSF_UINT32*) buf = 0; /* subject_data_len=0 */
                datalen += 4;
            }
            /* Step 2: Pack from address field */
            if (response->from_addr_no == 1)
            {
                int address_len = strlen(header.from.address);

                memcpy((char*)(buf + datalen), &header.from.addrType, 4);
                memcpy((char*)(buf + datalen + 4), &address_len, 4);
                memcpy((char*)(buf + datalen + 8), header.from.address, address_len);
                datalen += (8 + address_len);
            }

            /* Step 3: Pack to address field */
            if (header.to)
            {
                MmsAddressList *to_list = header.to;

                while (to_list)
                {
                    if (to_list->current.address)
                    {

                        int address_len = strlen(to_list->current.address);

                        memcpy((char*)(buf + datalen), &to_list->current.addrType, 4);
                        memcpy((char*)(buf + datalen + 4), &address_len, 4);
                        memcpy((char*)(buf + datalen + 8), to_list->current.address, address_len);
                        datalen += (8 + address_len);
                    }
                    to_list = to_list->next;
                }
            }
            /* Step 4: Pack cc address field */
            if (header.cc)
            {
                MmsAddressList *cc_list = header.cc;

                while (cc_list)
                {
                    if (cc_list->current.address)
                    {
                        int address_len = strlen(cc_list->current.address);

                        memcpy((char*)(buf + datalen), &cc_list->current.addrType, 4);
                        memcpy((char*)(buf + datalen + 4), &address_len, 4);
                        memcpy((char*)(buf + datalen + 8), cc_list->current.address, address_len);
                        datalen += (8 + address_len);
                    }
                    cc_list = cc_list->next;
                }
            }
            ASSERT(datalen <= buf_size);
            *buffer = (MSF_UINT8*) buf;
            *buffer_size = datalen;
            freeMmsGetHeader(MSF_MODID_MMC, &header);
            *result = MMC_RESULT_OK;
            return msgId;
        }
        appids_list = appids_list->next;
    }
    *result = MMC_RESULT_NO_MSG_FOR_JAVA;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmcGenRecvJSRMsgBodyPartRsp
 * DESCRIPTION
 *  This function is used to check if there are any mms messages for the specific application id.
 * PARAMETERS
 *  msgId           [IN]        
 *  bdy_no          [IN]        
 *  response        [?]         
 *  app_id(?)       [IN]        The application id
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
extern const char *msf_int_to_mime(MSF_INT32 known_value);
MSF_BOOL mmcGenRecvJSRMsgBodyPartRsp(
            MSF_UINT32 msgId,
            MSF_UINT32 bdy_no,
            wap_mmc_read_appmms_msg_part_rsp_struct *response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsGetHeader header;
    MSF_UINT32 curr_bdy_no = 0;
    MmsBodyInfoList *bdy_list = NULL;
    char *content_type_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mmcGetMmsMsgHeader(msgId, &header));
    ASSERT(header.bodyInfoList.numOfEntries >= bdy_no);

    kal_mem_set(response, 0x00, sizeof(wap_mmc_read_appmms_msg_part_rsp_struct));
    bdy_list = &header.bodyInfoList;
    while (bdy_list && curr_bdy_no != bdy_no)
    {
        bdy_list = bdy_list->next;
        curr_bdy_no++;
    }
    ASSERT(bdy_list);

    /* Step 1: Get Content-Type */
    response->content_type_value = bdy_list->contentType->knownValue;
    if (response->content_type_value == MMS_VALUE_AS_STRING)
    {
        content_type_str = (char*)bdy_list->contentType->strValue;
    }
    else
    {
        content_type_str = (char*)msf_int_to_mime(response->content_type_value);
    }
    if (content_type_str)
    {
        response->content_type_len = strlen(content_type_str);
        if (response->content_type_len > 255)
        {
            response->content_type_len = 255;
        }
        memcpy(response->content_type, content_type_str, response->content_type_len);
    }

    /* Step 2: Get Charset */
    if (bdy_list->contentType && bdy_list->contentType->params)
    {
        MmsAllParams *params = bdy_list->contentType->params;

        while (params)
        {
            if (params->param == MMS_CHARSET)
            {
                response->encoding_scheme = params->value.integer;
                break;
            }
            params = params->next;
        }
    }
    /* Step 3: Get Content-Location and Content-Id */
    if (bdy_list->entryHeader)
    {
        MmsEntryHeader *entries = bdy_list->entryHeader;

        while (entries)
        {
            if (entries->headerType == MMS_WELL_KNOWN_CONTENT_LOCATION)
            {
                if (entries->value.wellKnownFieldName)
                {
                    response->content_location_len = strlen((char*)entries->value.wellKnownFieldName);
                    if (response->content_location_len > 99)
                    {
                        response->content_location_len = 99;
                    }
                    memcpy(
                        response->content_location,
                        entries->value.wellKnownFieldName,
                        response->content_location_len);
                }
            }
            else if (entries->headerType == MMS_WELL_KNOWN_CONTENT_ID)
            {
                if (entries->value.wellKnownFieldName)
                {
                    response->content_id_len = strlen((char*)entries->value.wellKnownFieldName);
                    if (response->content_id_len > 99)
                    {
                        response->content_id_len = 99;
                    }
                    memcpy(response->content_id, entries->value.wellKnownFieldName, response->content_id_len);
                }
            }
            entries = entries->next;
        }
    }

    /* Write body to file */
    {
        MSF_INT32 rdFileHandle = -1;
        MSF_INT32 wrFileHandle = -1;
        MSF_UINT8 buf[512];
        MSF_UINT32 datalen = 0;
        MSF_UINT32 curr_pos = 0;
        MSF_INT8 *jsr_msg_filename = (MSF_INT8*) MMSlib_getMessageFullPath(MSF_MODID_MMC, msgId, MMC_SUFFIX_MSG);

        ASSERT(jsr_msg_filename);

        MSF_FILE_REMOVE(MMC_JSR_MEDIA_OBJECT_FILE);

        curr_pos = bdy_list->startPos;

        rdFileHandle = MSF_FILE_OPEN(
                        MSF_MODID_MMC,
                        (char*)jsr_msg_filename,
                        HDI_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                        0);
        if (rdFileHandle < 0)
            ASSERT(0) MSF_FILE_SEEK(rdFileHandle, curr_pos, MSF_FILE_SEEK_SET);

        wrFileHandle = MSF_FILE_OPEN(
                        MSF_MODID_MMC,
                        MMC_JSR_MEDIA_OBJECT_FILE,
                        HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                        bdy_list->size);
        if (wrFileHandle < 0)
        {
            MSF_FILE_CLOSE(rdFileHandle);
            MMC_MEM_FREE(jsr_msg_filename);
            freeMmsGetHeader(MSF_MODID_MMC, &header);
            return FALSE;   /* No free storage */
        }

        while (curr_pos < (bdy_list->startPos + bdy_list->size))
        {
            datalen = (bdy_list->startPos + bdy_list->size - curr_pos);
            if (datalen > 500)
            {
                datalen = 500;
            }

            /* read data from jsr mms message */
            ASSERT(MSF_FILE_READ(rdFileHandle, buf, datalen));
            /* write data to jsr media object */
            ASSERT(MSF_FILE_WRITE(wrFileHandle, buf, datalen));
            curr_pos += datalen;
        }
        MSF_FILE_CLOSE(rdFileHandle);
        MSF_FILE_CLOSE(wrFileHandle);
        /* Translate UTF8 filename to UCS2 filename */
        {
            char *fname = NULL;
            int len = 0;

            fname = (char*)HDI_FileNameTranslate(MMC_JSR_MEDIA_OBJECT_FILE);
            if (!fname)
            {
                ASSERT(0);
            }
            len = app_ucs2_strlen((kal_int8*) fname) * 2;
            if (len <= 198)
            {
                response->filepath_len = len;
                memcpy(response->filepath, fname, len);
            }
            else
            {
                memcpy(response->filepath, fname, 198);
            }
            HDI_FileNameFree((unsigned char*)fname);
        }
        MMC_MEM_FREE(jsr_msg_filename);
    }
    freeMmsGetHeader(MSF_MODID_MMC, &header);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcAddrListToMms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addrType        [IN]        
 *  address         [?]         
 *  mmsAddr         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mmcAddrListToMms(MSF_UINT8 addrType, MSF_INT8 *address, MmsAddressList **mmsAddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAddressList *addrItem = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address == NULL || mmsAddr == NULL)
    {
        return FALSE;
    }

    addrItem = MMC_MEM_ALLOC(sizeof(MmsAddressList));
    addrItem->current.addrType = addrType;
    addrItem->current.address = (char*)msf_cmmn_strdup(MSF_MODID_MMC, (char*)address);
    ASSERT(addrItem->current.address);

    if (*mmsAddr == NULL)
    {
        *mmsAddr = addrItem;
    }
    else
    {
        MmsAddressList *addrs_list = *mmsAddr;

        while (addrs_list->next)
        {
            addrs_list = addrs_list->next;
        }
        addrs_list->next = addrItem;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcFreeMmsAddressList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addrList        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmcFreeMmsAddressList(MmsAddressList *addrList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAddressList *cur = addrList;
    MmsAddressList *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (NULL != cur)
    {
        MMC_MEM_FREE(cur->current.address);
        cur->current.address = NULL;
        MMC_MEM_FREE(cur->current.name.text);
        cur->current.name.text = NULL;
        prev = cur;
        cur = cur->next;
        MMC_MEM_FREE(prev);
        prev = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcAddStrParam
 * DESCRIPTION
 *  This function is used to insert a string param first in the list of params
 * PARAMETERS
 *  allParams       [IN]        The current list.
 *  param           [IN]        The param to insert.
 *  strKeyValue     [IN]        
 *  strValue        [IN]        The string value for the param to insert. The strValue can be released after the call to this function.
 * RETURNS
 *  TRUE or FALSE(?)
 *****************************************************************************/
void mmcAddStrParam(
        struct MmsAllParamsStruct **allParams,
        MmsParam param,
        const char *strKeyValue,
        const char *strValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAllParams *newParam = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newParam = MMC_MEM_ALLOC(sizeof(MmsAllParams));
    /* Set param value */
    newParam->param = param;
    if (param == MMS_TEXT_KEY)
    {
        newParam->key = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMC, strKeyValue);
    }
    newParam->type = MMS_PARAM_STRING;
    newParam->value.string = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMC, strValue);
    /* Insert param. Insert first in the list */
    newParam->next = *allParams;
    *allParams = (struct MmsAllParamsStruct*)newParam;
}


/*****************************************************************************
 * FUNCTION
 *  mmcAddIntParam
 * DESCRIPTION
 *  This function is used to insert a string param first in the list of params
 * PARAMETERS
 *  allParams       [IN]        The current list.
 *  param           [IN]        The param to insert.
 *  value           [IN]        The integer value for the param to insert.
 * RETURNS
 *  TRUE or FALSE(?)
 *****************************************************************************/
void mmcAddIntParam(struct MmsAllParamsStruct **allParams, MmsParam param, MSF_UINT32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAllParams *newParam = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newParam = MMC_MEM_ALLOC(sizeof(MmsAllParams));
    /* Set param value */
    newParam->param = param;

    newParam->type = MMS_PARAM_INTEGER;
    newParam->value.integer = value;
    /* Insert param. Insert first in the list */
    newParam->next = *allParams;
    *allParams = (struct MmsAllParamsStruct*)newParam;
}


/*****************************************************************************
 * FUNCTION
 *  mmcAddStrEntry
 * DESCRIPTION
 *  This function is used to insert a string param first in the list of params
 * PARAMETERS
 *  entryHeads      [IN]        The current list.
 *  type            [IN]        The MmsEntryHeaderValueType
 *  strValue        [IN]        The string value for the param to insert. The strValue can be released after the call to this function.
 * RETURNS
 *  void
 *****************************************************************************/
void mmcAddStrEntry(MmsEntryHeader **entryHeads, MmsEntryHeaderValueType type, const char *strValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsEntryHeader *newEntry = MMC_MEM_ALLOC(sizeof(MmsEntryHeader));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set value */
    newEntry->headerType = type;
    newEntry->value.wellKnownFieldName = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMC, strValue);
    /* Insert param. Insert first in the list */
    newEntry->next = *entryHeads;
    *entryHeads = newEntry;
}


/*****************************************************************************
 * FUNCTION
 *  mmcCreateMessageHeader
 * DESCRIPTION
 *  This function is used to geberate mms messages header
 * PARAMETERS
 *  isSmil              [IN]        
 *  priority            [IN]        
 *  to_list             [?]         
 *  cc_list             [?]         
 *  bcc_list            [?]         
 *  delivery_time       [IN]        
 *  subject             [?]         
 *  subject_charset     [IN]        
 *  start_cnt_id        [?]         
 *  appId               [?]         
 *  reply_appId         [?]         
 *  app_id(?)           [IN]        The application id
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MmsSetHeader *mmcCreateMessageHeader(
                MSF_BOOL isSmil,
                MSF_UINT8 priority,
                MmsAddressList *to_list,
                MmsAddressList *cc_list,
                MmsAddressList *bcc_list,
                MSF_UINT32 delivery_time,
                MSF_INT8 *subject,
                MmsCharset subject_charset,
                MSF_INT8 *start_cnt_id,
                MSF_INT8 *appId,
                MSF_INT8 *reply_appId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MmsSetHeader *header = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create Header */
    header = MMC_MEM_ALLOC(sizeof(MmsSetHeader));
    header->contentType = MMC_MEM_ALLOC(sizeof(MmsContentType));

    /* SMIL */
    if (isSmil)
    {
        header->contentType->knownValue = MMS_VND_WAP_MULTIPART_RELATED;

        /* Start rel */
        mmcAddStrParam(&header->contentType->params, MMS_START_REL, NULL, (char*)start_cnt_id);

        /* Start type */
        mmcAddStrParam(&header->contentType->params, MMS_TYPE_REL, NULL, MMS_MEDIA_TYPE_STRING_SMIL);
    }
    else
    {
        /* Multipart/Mixed */
        /* Do not set type to Plain Text for messages with 0 bodyparts (empty) */
        /* in order to comply with other brands */
        header->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
    }

    /* Application-ID */
    if (appId != NULL)
    {
        mmcAddStrParam(&header->contentType->params, MMS_TEXT_KEY, "Application-ID", (char*)appId);
    }

    /* Reply-To-Application-ID */
    if (reply_appId != NULL)
    {
        mmcAddStrParam(&header->contentType->params, MMS_TEXT_KEY, "Reply-To-Application-ID", (char*)reply_appId);
    }

    /* From: */
    header->fromType = MMS_FROM_INSERT_ADDRESS;

    /* To/Cc/Bcc, assume this simple copy process works. */
    header->to = to_list;
    header->cc = cc_list;
    header->bcc = bcc_list;

    /* Subject: */
    if (subject != NULL)
    {
        MSF_UINT32 i, datalen;

        datalen = strlen((char*)subject);
        header->subject.text = MMC_MEM_ALLOC(datalen + 2);
        subject_charset = MMS_US_ASCII;

        for (i = 0; i < datalen; i++)
        {
            if (*(subject + i) & 0x80)
            {
                subject_charset = MMS_UTF8;
                break;
            }
        }
        if (*subject & 0x80)
        {
            datalen += 1;
            *header->subject.text = 0x7F;
            sprintf(header->subject.text + 1, "%s", subject);
        }
        else
        {
            sprintf(header->subject.text, "%s", subject);
        }
        header->subject.charset = subject_charset;
    }

    /* Date, must be done ahead of expiry and delivery time */
    header->date = mmsGetGMTtime(FALSE);

    /* Delivery reports */
    header->deliveryReport = MMS_DELIVERY_REPORT_NO;
    /* Read reports */
    header->readReply = MMS_READ_REPLY_NO;

    /* Message class */
    header->msgClass.classIdentifier = MMS_MESSAGE_CLASS_NOT_SET;

    /* Priority */
    if (priority == 0)
    {
        header->priority = MMS_PRIORITY_LOW;
    }
    else if (priority == 2)
    {
        header->priority = MMS_PRIORITY_HIGH;
    }
    else
    {
        header->priority = MMS_PRIORITY_NORMAL;
    }

    header->replyCharging = MMS_REPLY_CHARGING_NOT_SET;
    /* Sender visibility */
    header->visibility = MMS_SENDER_SHOW;

    /* Delivery time (relative) */
    header->deliveryTimeType = MMS_TIME_RELATIVE;
    header->deliveryTime = delivery_time;

    /* Expiry time */
    header->expiryTimeType = MMS_TIME_RELATIVE;
    header->expiryTime = 604800;    /* One week */

    return header;
}


/*****************************************************************************
 * FUNCTION
 *  mmcCreateBodyParams
 * DESCRIPTION
 *  
 * PARAMETERS
 *  charset                 [IN]        
 *  content_type            [IN]        
 *  content_id              [IN]        
 *  content_location        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsBodyParams *mmcCreateBodyParams(
                MmsCharset charset,
                const unsigned char *content_type,
                const unsigned char *content_id,
                const unsigned char *content_location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsBodyParams *bp = MMC_MEM_ALLOC(sizeof(MmsBodyParams));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bp->contentType.knownValue = MMS_VALUE_AS_STRING;
    bp->contentType.strValue = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMC, (char*)content_type);
    bp->targetType = MMS_MULTIPART_MESSAGE;

    mmcAddStrEntry(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_ID, (char*)content_id);
    mmcAddStrEntry(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_LOCATION, (char*)content_location);
    if (charset != 0)
    {
        mmcAddIntParam(&bp->contentType.params, MMS_CHARSET, charset);
    }
    return bp;
}


/*****************************************************************************
 * FUNCTION
 *  mmcWriteMessageHeader
 * DESCRIPTION
 *  This function is used to write MmsSetHeader to file
 * PARAMETERS
 *  filename        [?]         
 *  header          [IN]        
 *  version         [IN]        
 *  no_body         [IN]        
 *  app_id(?)       [IN]        The application id
 * RETURNS
 *  MmcResult
 *****************************************************************************/
MmcResult mmcWriteMessageHeader(char *filename, const MmsSetHeader *header, MmsVersion version, MSF_UINT32 no_body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 wrFileHandle = -1;
    MSF_UINT8 *buffer = NULL;
    MSF_UINT32 buffer_size = 0;
    MmsResult result = MMS_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_FILE_REMOVE(filename);
    buffer = createWspSendHeader(MSF_MODID_MMC, header, &buffer_size, &result, version, no_body);
    if (buffer == NULL)
    {
        return MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR;
    }
    else if (result != MMS_RESULT_OK)
    {
        MMC_MEM_FREE(buffer);
        return MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR;
    }
    else
    {
        MSF_INT32 ret;

        wrFileHandle = MSF_FILE_OPEN(
                        MSF_MODID_MMC,
                        filename,
                        MSF_FILE_SET_CREATE | MSF_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                        0);
        if (wrFileHandle < 0)
        {
            MMC_MEM_FREE(buffer);
            return MMC_RESULT_FILE_OPERATION_ERROR;
        }
        ret = MSF_FILE_WRITE(wrFileHandle, buffer, buffer_size);
        MSF_FILE_CLOSE(wrFileHandle);
        if (ret == HDI_FILE_ERROR_FULL)
        {
            return MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        }
        else if (ret < 0 || ret != buffer_size)
        {
            return MMC_RESULT_ERROR_FAIL_TO_WR_MMS_HDR;
        }
    }
    return MMC_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmcWriteMessageBodyPart
 * DESCRIPTION
 *  This function is used to write MmsSetHeader to file
 * PARAMETERS
 *  filename                [?]         
 *  bdyParams               [IN]        
 *  content_filepath        [?]         
 *  app_id(?)               [IN]        The application id
 * RETURNS
 *  MmcResult
 *****************************************************************************/
MmcResult mmcWriteMessageBodyPart(char *filename, const MmsBodyParams *bdyParams, kal_wchar *content_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 fsRet = -1;
    MSF_INT32 wrFileHandle = -1;
    MSF_INT32 rdFileHandle = -1;
    MSF_UINT8 *buf = NULL;
    MSF_UINT32 buf_Size = 0;
    MSF_UINT32 fileSize = 0;
    MmsResult result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(bdyParams);
    fileSize = applib_get_file_size(content_filepath);
    if (fileSize == 0)
    {
        return MMC_RESULT_INVALID_MESSAGE_BODY;
    }

    buf = createBodyPartHeader(MSF_MODID_MMC, &buf_Size, bdyParams, fileSize, &result);
    if (result != MMS_RESULT_OK)
    {
        return translateMmsResultToMmc(result);
    }

    wrFileHandle = MSF_FILE_OPEN(MSF_MODID_MMC, filename, MSF_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
    if (wrFileHandle < 0)
    {
        MMC_MEM_FREE(buf);
        return MMC_RESULT_FILE_OPERATION_ERROR;
    }

    MSF_FILE_SEEK(wrFileHandle, 0, MSF_FILE_SEEK_END);
    fsRet = MSF_FILE_WRITE(wrFileHandle, buf, buf_Size);
    if (fsRet < 0 || fsRet != buf_Size)
    {
        MMC_MEM_FREE(buf);
        MSF_FILE_CLOSE(wrFileHandle);
        if (fsRet == HDI_FILE_ERROR_FULL)
        {
            return MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        }
        else
        {
            return MMC_RESULT_FILE_OPERATION_ERROR;
        }
    }

    rdFileHandle = FS_Open(content_filepath, FS_READ_ONLY);
    if (rdFileHandle < 0)
    {
        MMC_MEM_FREE(buf);
        MSF_FILE_CLOSE(wrFileHandle);
        return MMC_RESULT_FILE_OPERATION_ERROR;
    }
    MMC_MEM_FREE(buf);
    buf = MMC_MEM_ALLOC(512);
    while (fileSize)
    {
        kal_uint32 rd_no = 0;

        if (fileSize > 512)
        {
            buf_Size = 512;
        }
        else
        {
            buf_Size = fileSize;
        }
        ASSERT(FS_Read(rdFileHandle, buf, buf_Size, &rd_no) == 0);
        fsRet = MSF_FILE_WRITE(wrFileHandle, buf, buf_Size);
        if (fsRet < 0 || fsRet != buf_Size)
        {
            MMC_MEM_FREE(buf);
            FS_Close(rdFileHandle);
            MSF_FILE_CLOSE(wrFileHandle);
            if (fsRet == HDI_FILE_ERROR_FULL)
            {
                return MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
            }
            else
            {
                return MMC_RESULT_FILE_OPERATION_ERROR;
            }
        }
        fileSize -= buf_Size;
    }
    MMC_MEM_FREE(buf);
    FS_Close(rdFileHandle);
    MSF_FILE_CLOSE(wrFileHandle);
    return MMC_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmcCheckAppIdMsgs
 * DESCRIPTION
 *  This function is used to check if there are any mms messages for the specific application id.
 * PARAMETERS
 *  app_id_str      [?]         
 *  isOnlyNew       [IN]        
 *  app_id(?)       [IN]        The application id
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcCheckAppIdMsgs(MSF_INT8 *app_id_str, MSF_BOOL isOnlyNew)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_jsr_msg_db == NULL)
    {
        mmcRestoreJSRIndex();
    }

    if (mmc_jsr_msg_db->jsr_mms_info)
    {
        mmc_jsr_appid_object_list_struct *appids_list = mmc_jsr_msg_db->jsr_mms_info;

        while (appids_list)
        {
            if (appids_list->appid && strcmp((char*)appids_list->appid, (char*)app_id_str) == 0)
            {
                mmc_jsr_msg_info *msgs_list = appids_list->msgs;

                while (msgs_list)
                {
                    if (msgs_list->isChecked == FALSE)
                    {
                        msgs_list->isChecked = TRUE;
                        mmcWriteJSRIndex();
                        return TRUE;
                    }
                    else
                    {
                        if (isOnlyNew == FALSE)
                        {
                            return TRUE;
                        }
                    }
                    msgs_list = msgs_list->next;
                }
                return FALSE;
            }
            appids_list = appids_list->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcGetDigitOfInteger
 * DESCRIPTION
 *  This function is used to calculate the digit number of one integer
 * PARAMETERS
 *  num     [IN]        Integer
 * RETURNS
 *  digit
 *****************************************************************************/
MSF_UINT8 mmcGetDigitOfInteger(MSF_UINT32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 buf[11];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sprintf((char*)buf, "%d", (int)num);
    return strlen((char*)buf);
}


/*****************************************************************************
 * FUNCTION
 *  mmcGetCurrSizeOfJSRIndex
 * DESCRIPTION
 *  This function is used to calculate the filesize of MMC JSR index
 * PARAMETERS
 *  jsr_mms_info        [?]     
 *  max_chr_in_line     [?]     
 * RETURNS
 *  filesize
 *****************************************************************************/
MSF_UINT32 mmcGetCurrSizeOfJSRIndex(mmc_jsr_appid_object_list_struct *jsr_mms_info, MSF_UINT32 *max_chr_in_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 sum = 0;
    MSF_UINT32 chrs = 0;
    MSF_UINT32 max_chrs = 0;

    mmc_jsr_appid_object_list_struct *jsr_appids_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *max_chr_in_line = 0;
    if (jsr_mms_info == NULL)
    {
        return 0;
    }

    jsr_appids_list = jsr_mms_info;

    while (jsr_appids_list)
    {
        if (jsr_appids_list->appid)
        {
            chrs = strlen((char*)jsr_appids_list->appid) + 2;  /* appid string+\r\n */
            sum += chrs;
            if (chrs > max_chrs)
            {
                max_chrs = chrs;
            }
        }
        chrs = 0;
        if (jsr_appids_list->msgs)
        {
            mmc_jsr_msg_info *msgs_list = jsr_appids_list->msgs;

            while (msgs_list)
            {
                chrs += (mmcGetDigitOfInteger(msgs_list->msgId) + 2);   /* msgid:isChecked */
                if (msgs_list->next)
                {
                    chrs += 1;  /* ',' */
                }
                msgs_list = msgs_list->next;
            }
            chrs += 5;  /* \r\n*\r\n */
            sum += chrs;
            if (chrs > max_chrs)
            {
                max_chrs = chrs;
            }
        }
        jsr_appids_list = jsr_appids_list->next;
    }
    *max_chr_in_line = max_chrs;
    return sum;
}


/*****************************************************************************
 * FUNCTION
 *  mmcWriteJSRIndex
 * DESCRIPTION
 *  This function is used to write MMC JSR index file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MSF_BOOL mmcWriteJSRIndex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmc_jsr_appid_object_list_struct *appids_list;
    MSF_INT8 *buf = NULL;
    MSF_UINT32 buf_size = 0;
    MSF_UINT32 datalen = 0;
    MSF_UINT32 checksum = 0;
    MSF_UINT32 fileSize = 0;
    MSF_INT32 fileHandle = -1;
    MSF_INT32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_jsr_msg_db == NULL || mmc_jsr_msg_db->jsr_mms_info == NULL)
    {
        return FALSE;
    }
    fileSize = mmcGetCurrSizeOfJSRIndex(mmc_jsr_msg_db->jsr_mms_info, &buf_size);
    ASSERT(fileSize);

    MSF_FILE_REMOVE(MMC_JSR_INDEX_FILE_TMP);
    fileHandle = MSF_FILE_OPEN(
                    MSF_MODID_MMC,
                    MMC_JSR_INDEX_FILE_TMP,
                    MSF_FILE_SET_CREATE | MSF_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                    fileSize);
    if (fileHandle < 0)
    {
        return FALSE;
    }
    buf_size += 13;
    buf = MMC_MEM_ALLOC(buf_size);
    ASSERT(buf);
    appids_list = mmc_jsr_msg_db->jsr_mms_info;

    MSF_FILE_SEEK(fileHandle, 12, MSF_FILE_SEEK_SET);
    while (appids_list)
    {
        ASSERT(appids_list->appid);
        {
            datalen = 0;
            kal_sprintf((char*)buf, "%s\r\n", appids_list->appid);
            datalen = strlen((char*)appids_list->appid) + 2;
            ASSERT(buf_size >= datalen);
            checksum += mmcGenCheckSumFromBuffer((MSF_UINT8*) buf, datalen);
            ret = MSF_FILE_WRITE(fileHandle, buf, datalen);
            if (ret < 0)
            {
                MSF_FILE_CLOSE(fileHandle);
                MMC_MEM_FREE(buf);
                return FALSE;
            }
        }
        ASSERT(appids_list->msgs);
        {
            mmc_jsr_msg_info *msgs_list = appids_list->msgs;

            datalen = 0;
            while (msgs_list)
            {
                kal_sprintf((char*)(buf + datalen), "%d:%1d", (unsigned int)msgs_list->msgId, msgs_list->isChecked);
                datalen += mmcGetDigitOfInteger(msgs_list->msgId) + 2;
                if (msgs_list->next)
                {
                    kal_sprintf((char*)(buf + datalen), ",");
                    datalen += 1;
                }
                msgs_list = msgs_list->next;
            }
            kal_sprintf((char*)(buf + datalen), "\r\n*\r\n");
            datalen += 5;
            ASSERT(buf_size >= datalen);
            checksum += mmcGenCheckSumFromBuffer((MSF_UINT8*) buf, datalen);
            ret = MSF_FILE_WRITE(fileHandle, buf, datalen);
            if (ret < 0)
            {
                MSF_FILE_CLOSE(fileHandle);
                MMC_MEM_FREE(buf);
                return FALSE;
            }
        }
        appids_list = appids_list->next;
    }
    MSF_FILE_SEEK(fileHandle, 0, MSF_FILE_SEEK_SET);
    kal_sprintf((char*)buf, "%10d\r\n", (unsigned int)checksum);
    ret = MSF_FILE_WRITE(fileHandle, buf, 12);
    if (ret < 0)
    {
        MSF_FILE_CLOSE(fileHandle);
        MMC_MEM_FREE(buf);
        return FALSE;
    }
    MSF_FILE_CLOSE(fileHandle);
    MMC_MEM_FREE(buf);
    MSF_FILE_REMOVE(MMC_JSR_INDEX_FILE);
    MSF_FILE_RENAME(MMC_JSR_INDEX_FILE_TMP, MMC_JSR_INDEX_FILE);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmcGetMmsMsgHeader
 * DESCRIPTION
 *  This function is used to retrieve mms headers of one mms message
 * PARAMETERS
 *  msgId       [IN]            Msg_id
 *  header      [IN/OUT]        MmsGetHeader
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcGetMmsMsgHeader(MSF_UINT32 msgId, MmsGetHeader *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_BOOL isSuccess = FALSE;
    MmsMsgHandle msgHandle = NULL;
    MmsTransactionHandle transaction = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(header, 0x00, sizeof(MmsGetHeader));
    MMS_FILE_OPEN_BLOCK_FLAG = TRUE;
    if (MMSlib_messageOpen(MSF_MODID_MMC, msgId, MMS_SUFFIX_MSG, &msgHandle) != MMS_RESULT_OK)
    {
        MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
        if (msgHandle)
        {
            MMSlib_messageClose(MSF_MODID_MMC, &msgHandle);
            msgHandle = NULL;
        }
        return FALSE;
    }
    else if (MMSlib_transactionOpen(MSF_MODID_MMC, &transaction) != MMS_RESULT_OK)
    {
        MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
        if (msgHandle)
        {
            MMSlib_messageClose(MSF_MODID_MMC, &msgHandle);
            msgHandle = NULL;
        }
        if (transaction)
        {
            MMSlib_transactionClose(MSF_MODID_MMC, &transaction);
            transaction = NULL;
        }
        return FALSE;
    }
    MMS_FILE_OPEN_BLOCK_FLAG = FALSE;
    if (MMSlib_getMessageHeader(MSF_MODID_MMC, header, &msgHandle, &transaction) == MMS_RESULT_OK)
    {
        isSuccess = TRUE;
    }
    if (msgHandle)
    {
        MMSlib_messageClose(MSF_MODID_MMC, &msgHandle);
    }
    if (transaction)
    {
        MMSlib_transactionClose(MSF_MODID_MMC, &transaction);
    }
    msgHandle = NULL;
    transaction = NULL;
    return isSuccess;
}


/*****************************************************************************
 * FUNCTION
 *  mmcIsRecvMMSForJava
 * DESCRIPTION
 *  This function is used to check if the received MMS message belongs to JAVA.
 *  If yes, it will insert the msgId to Java MMS message database.
 * PARAMETERS
 *  msgId       [IN]        Msg_id
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
MSF_BOOL mmcIsRecvMMSForJava(MSF_UINT32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void wap_mmc_send_appmms_new_mms_ind(
                    module_type mod_id,
                    sap_type sap_id,
                    MSF_UINT8 * app_id,
                    MSF_UINT8 app_id_len);

    if (fldrGetFileSuffix(msgId) == MMS_SUFFIX_MSG)
    {
        MmsGetHeader header;

        if (mmcGetMmsMsgHeader(msgId, &header) == TRUE)
        {
            if (header.bodyInfoList.contentType && header.bodyInfoList.contentType->params)
            {
                /* Check if there is application id in content-type */
                MmsAllParams *params = header.bodyInfoList.contentType->params;

                while (params)
                {
                    if (params->key != NULL && params->value.string != NULL &&
                        msf_cmmn_strcmp_nc((char*)params->key, "Application-ID") == 0)
                    {
                        module_type ind_module;
                        sap_type ind_sap_id;

                        mmcInsertMsgIdToJSRIndex((MSF_INT8*) params->value.string, msgId, FALSE);
                        if (mmcGetJsrAppIdInfo((MSF_INT8*) params->value.string, &ind_module, &ind_sap_id) == TRUE)
                        {
                            wap_mmc_send_appmms_new_mms_ind(
                                ind_module,
                                ind_sap_id,
                                (MSF_UINT8*) params->value.string,
                                strlen((char*)params->value.string));
                        }
                        freeMmsGetHeader(MSF_MODID_MMC, &header);
                        return TRUE;
                    }

                    params = params->next;
                }
            }
            freeMmsGetHeader(MSF_MODID_MMC, &header);
            return FALSE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmcRestoreJSRIndex
 * DESCRIPTION
 *  This function is used to restore MMC JSR index file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmcRestoreJSRIndex()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 line_len = 0;
    MSF_INT32 ret = -1;
    MSF_INT32 fileHandle = -1;
    MSF_INT8 *buf;
    MSF_UINT32 buf_size = 0;
    MSF_BOOL updateJSRIndex = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmc_jsr_msg_db == NULL)
    {
        mmc_jsr_msg_db = MMC_MEM_ALLOC(sizeof(mmc_jsr_index_struct));
        ASSERT(mmc_jsr_msg_db);
    }

    if (mmcGenChecksumFromFile((MSF_INT8*) MMC_JSR_INDEX_FILE, 12, &mmc_jsr_msg_db->checksum, &buf_size) < 0)
    {
        /* The MMC JSR index may be corrupted. Remove all Java mms messages */
        kal_mem_set(mmc_jsr_msg_db, 0x00, sizeof(mmc_jsr_index_struct));
        return;
    }
    else
    {
        if (buf_size < 12)
        {
            buf_size = 12;  /* First Line needs at leatse 12 bytes: Checksum */
        }
        buf_size++;
        /* buf_size is max bytes of all lines in this index file */
        buf = (MSF_INT8*) MMC_MEM_ALLOC(buf_size);
        ASSERT(buf);

        /* Retreive checksum of this index file */
        fileHandle = MSF_FILE_OPEN(MSF_MODID_MMC, MMC_JSR_INDEX_FILE, HDI_FILE_SET_RDONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0);
        if (fileHandle < 0)
        {
            kal_mem_set(mmc_jsr_msg_db, 0x00, sizeof(mmc_jsr_index_struct));
            return;
        }
        else
        {

            /* Read checksum from file */
            applib_file_read_line(
                (kal_int32) fileHandle,
                (kal_uint8*) buf,
                (kal_uint32) buf_size,
                (kal_uint32*) & line_len,
                (kal_int32*) & ret);
            if (line_len <= 2)
            {
                goto exit_index_corrupted;
            }
            /* replace '\r','\n' with '\0','\0' */
            *(buf + line_len - 1) = '\0';
            *(buf + line_len) = '\0';
            if (atoi((char*)buf) != mmc_jsr_msg_db->checksum)
            {
              exit_index_corrupted:
                /* index file is corrupted. */
                MSF_FILE_CLOSE(fileHandle);
                MSF_FILE_REMOVE(MMC_JSR_INDEX_FILE);
                kal_mem_set(mmc_jsr_msg_db, 0x00, sizeof(mmc_jsr_index_struct));
                return;
            }
        }

        while (1)
        {
            MSF_INT8 *appid_string = NULL;
            mmc_jsr_msg_info *msgs_list = NULL;
            MSF_UINT8 step = 1;

            for (step = 1; step < 4; step++)
            {
                applib_file_read_line(
                    fileHandle,
                    (kal_uint8*) buf,
                    buf_size,
                    (kal_uint32*) & line_len,
                    (kal_int32*) & ret);
                if (ret == 0 && line_len == 0)  /* End of File */
                {
                    MSF_FILE_CLOSE(fileHandle);
                    MMC_MEM_FREE(buf);
                    if (updateJSRIndex == TRUE)
                    {
                        mmcWriteJSRIndex();
                    }
                    return;
                }
                else if (ret < 0)
                {
                    MSF_FILE_CLOSE(fileHandle);
                    MMC_MEM_FREE(buf);
                    /* To-Do-List: clean appids object list */
                    mmcRemoveAppIdnfoFromListRescurive(&mmc_jsr_msg_db->jsr_mms_info);
                    kal_mem_set(mmc_jsr_msg_db, 0x00, sizeof(mmc_jsr_index_struct));
                    return;
                }
                ASSERT(line_len > 2);
                /* replace '\r','\n' with '\0','\0' */
                *(buf + line_len - 1) = '\0';
                *(buf + line_len - 2) = '\0';

                if (step == 1)  /* Step 1: Read appid from file */
                {
                    appid_string = MMC_MEM_ALLOC(strlen((char*)buf) + 1);
                    ASSERT(appid_string);
                    strcpy((char*)appid_string, (char*)buf);
                }
                else if (step == 2) /* Step 2: Read msgid and isChecked string */
                {
                    MSF_INT8 *text = buf;
                    MSF_INT8 *colon = NULL;
                    MSF_INT8 *next_token = NULL;
                    MSF_UINT32 msgId;
                    MSF_BOOL isChecked;

                    while (text)
                    {
                        next_token = (MSF_INT8*) strchr((char*)text, ',');
                        if (next_token != NULL)
                        {
                            *next_token++ = '\0';
                        }
                        colon = (MSF_INT8*) strchr((char*)text, ':');
                        ASSERT(colon);
                        *colon++ = '\0';
                        msgId = atoi((char*)text);
                        isChecked = atoi((char*)colon);
                        if (msm_get_module_status(MSF_MODID_MMS) == MODULE_STATUS_ACTIVE && checkMsgId(msgId) == TRUE)
                        {
                            mmcInsertMsgInfoToList(&msgs_list, msgId, isChecked);
                        }
                        else
                        {
                            updateJSRIndex = TRUE;
                        }
                        text = next_token;
                    }
                }
                else if (step == 3)     // Step 3: */r/n
                {
                    if (msgs_list != NULL)
                    {
                        mmcInsertAppIdInfoToList(&mmc_jsr_msg_db->jsr_mms_info, appid_string, msgs_list);
                    }
                    else
                    {
                        if (appid_string)
                        {
                            MMC_MEM_FREE(appid_string);
                        }
                    }
                }

            }

        }
    }
}
#endif /* MMS_SUPPORT */ 

