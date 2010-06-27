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
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
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

/* MSF */
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_int.h"
#include "msf_wid.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_errc.h"
#include "msf_mem.h"

/* MMS */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_vrsn.h"
#include "mea_def.h"
#include "mea_cfg.h"
#include "mea_env.h"
#include "matypes.h"
#include "masig.h"
#include "maintsig.h"
#include "macore.h"
#include "mamem.h"
#include "maaddr.h"
#include "mapbh.h"
#include "mauidia.h"
#ifdef WAP_SUPPORT
#include "mea_rc.h"
#include "mauicmn.h"
#include "mautils.h"  /* meaIsResizedFile() */
/* Widget */
#include "widget_extension.h"
#ifdef __UNIFIED_MSG_SUPPORT__
#include "mea_if.h"
#endif
#endif /* WAP_SUPPORT */
#ifdef  __USB_IN_NORMAL_MODE__
extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern kal_bool is_mms_storage_exported_to_pc(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
#endif /*__USB_IN_NORMAL_MODE__*/

/*!\file mea_env.c
 *	Integration functions.
 */

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void handleException(void);
extern kal_int32 mmi_chset_utf8_strlen(const kal_uint8 *s);
/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief This function is called in order to determine whether the MEA 
 *        application needs execution time.
 *
 * \return TRUE if the MEA wants execution time, otherwise FALSE.
 *****************************************************************************/
int MEAc_wantsToRun(void)
{
    if (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_MEA) > 0 )
    {
        return TRUE;
    }
    /* Return the status of the internal signal queue */
    return !meaSignalQueueIsEmpty();
}

/*!
 * \brief In order for the MEA to get execution time this function is called.
 *          On each "tick", it handles one external signal and one internal
 *          signal
 *
 *****************************************************************************/
void MEAc_run(void)
{
    int res;
    /* Set roll back entry point*/
    res = setjmp(meaJmpBuf);
    meaSetInsideRun(TRUE);
    /* Process signal if a longjmp has not occured */
    if (res == 0)
    {
        /* check the external message queue */
        while(MSF_SIGNAL_RETRIEVE(MSF_MODID_MEA, meaSignalReceive))
            ;
        /* Process one signal in the signal queue */
        meaSignalProcess();
    }
    else
    {
        if (MEA_PANIC_EXPLICIT == meaPanicMode)
        {
            /* Shut down the MEA immediately */
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
                MEA_ENV_4DFCE2D84AFF2861B46041993A8AAA84, "MEAc_run explicit panic \n"));
            if (meaIsModuleStarted(MSF_MODID_MMS))
            {
                /* Stop MMS service */
                meaModuleStop(MSF_MODID_MMS, TRUE);
            }
            else if (meaIsModuleStarted(MSF_MODID_SMA))
            {
                /* Stop SMA */
                meaModuleStop(MSF_MODID_SMA, TRUE);
            }
            else if (meaIsModuleStarted(MSF_MODID_SLS))
            {
                /* Stop SLS */
                meaModuleStop(MSF_MODID_SLS, TRUE);
            }
            else if(meaCheckDialogs())
            {
                /* Nothing to do until the current dialog closes */
            }
            else
            {
                /* Terminate the MEA */
                meaTerminate(FALSE);
#ifdef WAP_SUPPORT
                HDIa_widgetExtCloseTransitionAnimation();
#endif /* WAP_SUPPORT */				
            }
        }
        else if (MEA_PANIC_IMPLICIT == meaPanicMode)
        {
            /* Shutdown the application when the panic dialog has been disabled */
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
                MEA_ENV_5C7C6821C7F38CACFFB56919D475F75A, "MEAc_run implicit panic.\n"));
        }
        else
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
            MEA_ENV_1F9055A5DF31C00CDCA37808A8FBA113, "MEAc_run invalid setjmp value (%d)\n", res));
    }
    meaSetInsideRun(FALSE);
}

/*!
 * \brief Handles memory exceptions
 *
 *****************************************************************************/
static void handleException(void)
{
    if (meaIsInsideRun())
    {
        /* Terminate if inside a MEAc_run call */
        if (meaIsExceptionAllowed())
        {
            /* Report "Out of memory" to the integration */
            MSF_ERROR(MSF_MODID_MEA, MSF_ERR_MODULE_OUT_OF_MEMORY);
            /* Perform a long jump */
            MEA_TERMINATE;
        }
        else
        {
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                MEA_ENV_6CEAF561551AC59F732EC864E4786E01, "(%s) (%d) memory exception!\n", __FILE__, __LINE__));
        }
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MEA_ENV_74461E65ACF945F99467849471050459, "(%s) (%d) out of memory in an adaptor/connector call!\n", __FILE__,
            __LINE__));
    }
}

/*!
 * \brief Initiates MEA.
 *
 *****************************************************************************/
void MEAc_start(void)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MEA_ENV_38ABC611D8892950E0CC54020E440982, "MEAc_start()\n"));
    /* Initiate memory manager */
    MSF_MEM_INIT(MSF_MODID_MEA, handleException);
    /* Initiate internal global data */
    meaInit(FALSE);

    /* Register module */
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_MEA);

#ifdef __UNIFIED_MSG_SUPPORT__
    /* Register conversion and destruction functions */
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_MEA, mea_convert, mea_destruct);
#endif

    /* The module is started */
    /*lint -e{1776} */
    MSF_MODULE_IS_CREATED(MSF_MODID_MEA, MEA_VERSION);

#ifndef __UNIFIED_MSG_SUPPORT__
    {
        extern void set10RrAllStringRes(void);
  #ifdef MMS_FILE_PROTECT_SUPPORT
        extern void syncChkSumFile(void);
        syncChkSumFile();
  #endif
        set10RrAllStringRes();
    }
#endif

#ifdef __DRM_SUPPORT__
	(void)MSF_FILE_MKDIR(MMS_DRM_FOLDER);
	(void)MSF_FILE_MKDIR(MMS_DCF_FOLDER);
#endif /* __DRM_SUPPORT__ */
}

#ifdef WAP_SUPPORT
/*!
 * \brief Initiates MEA in new mode with text or content insertion, with subject and addr.
 *****************************************************************************/
void MEAc_startWithGeneralInserted(char *subject, char *text, MSF_BOOL isTruncated, char *addr, char *contentSource)
{

    msf_content_data_t contentData;
    int size;
    char *str = NULL;
    char *tmp_str = NULL;
    char *cmd = NULL; 
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, MEA_ENV_4A93CC25579B8BB435EBA7080B622F30, "MEAc_startWithTextInserted()\n"));

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    memset(&contentData, 0x00, sizeof(msf_content_data_t));
    contentData.routingIdentifier = msf_cmmn_strdup(MSF_MODID_MSM, "text/plain");
    contentData.routingFormat = MSF_ROUTING_TYPE_MIME;

    /* process file path */
    if(contentSource != NULL && contentSource[0] != 0)
    {
        const char * strMimeType;
        char * strContentSource = NULL;
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MEA_ENV_6D82A4C998BF548C524317FF17E024C1, "MEAc_startWithContentInserted()\n"));
    
        /* convert UCS2 to UTF8 */
        size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) contentSource) + 1;
        strContentSource = MSF_MEM_ALLOC(MSF_MODID_MSM, size);
        widget_ucs2_to_utf8_string((kal_uint8*)strContentSource,size,(kal_uint8*)contentSource);    
        contentData.contentSource = msf_cmmn_strcat(MSF_MODID_MSM, HDI_EXTERNAL_PATH, strContentSource);
        strMimeType = meaFileName2MimeType(contentData.contentSource);
    
        if (strMimeType == NULL)
        {
#ifdef JPG_ENCODE
            if(meaIsResizedFile(strContentSource))
            {
                MSF_FILE_REMOVE(strContentSource);
            }
#endif	
            HDIa_widgetExtShowPopup(MSF_MODID_MSM, MEA_GET_STR_ID(MSF_STR_ID_DLG_MIME_ACTION_NONE), MsfAlert, 0);
            MSF_MEM_FREE(MSF_MODID_MSM, strContentSource);
            HDIa_widgetExtCloseTransitionAnimation();
            return;
        }
        contentData.routingIdentifier = MSF_MEM_ALLOC(MSF_MODID_MSM, strlen(strMimeType)+1);
        strcpy(contentData.routingIdentifier, strMimeType);
    
        contentData.contentUrl = NULL;
        contentData.routingFormat = MSF_ROUTING_TYPE_MIME;
        contentData.contentParameters = NULL;
        contentData.contentData = NULL;
        contentData.contentDataLength=0;
        contentData.contentHeaders=NULL;
        contentData.contentDRMData=NULL;
        contentData.contentDRMDataExists=0;
        contentData.auxTypeIdentifier = NULL;
    }

    /* Text */
    if(text)
    {
        size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)text);
        if(size > 0)
        {
            contentData.contentData = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
            widget_ucs2_to_utf8_string((kal_uint8*)contentData.contentData, size + 1, (kal_uint8*)text);
            contentData.contentDataLength = size + 1;
        }
    }

    if(text || contentSource)
    {
        cmd = msf_cmmn_strdup(MSF_MODID_MSM, "-mode new -i");
    }
    else
    {
        cmd = msf_cmmn_strdup(MSF_MODID_MSM, "-mode new");
    }

    /* Subject */
    if(subject)
    {
        size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)subject);
        if(size > 0)
        {
            str = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
            widget_ucs2_to_utf8_string((kal_uint8*)str, size + 1,(kal_uint8*)subject);
            MSF_MEM_FREE(MSF_MODID_MSM, cmd);
            cmd = msf_cmmn_str3cat(MSF_MODID_MSM, cmd ," -subject ", str);
        }
    }

    if(isTruncated)
    {
        contentData.contentDataLength++;
    }

    /* addr */
    if(addr)
    {
        size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)addr);
        if(size > 0)
        {
            //str = msf_cmmn_strdup(MSF_MODID_MSM, addr);
            str = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
            widget_ucs2_to_utf8_string((kal_uint8*)str, size + 1,(kal_uint8*)addr);
            tmp_str = msf_cmmn_strdup(MSF_MODID_MSM, cmd);
            MSF_MEM_FREE(MSF_MODID_MSM, cmd);
            cmd = msf_cmmn_str3cat(MSF_MODID_MSM, tmp_str, " -to ", str);
        }
    }

    MSF_CONTENT_SEND_DRM_EXT(MSF_MODID_MSM, MSF_MODID_MEA, cmd, &contentData, 0, 0);
    MSF_MEM_FREE(MSF_MODID_MSM, contentData.routingIdentifier);
    MSF_MEM_FREE(MSF_MODID_MSM, contentData.contentData);
    MSF_MEM_FREE(MSF_MODID_MSM, str);
    MSF_MEM_FREE(MSF_MODID_MSM, cmd);
    MSF_MEM_FREE(MSF_MODID_MSM, tmp_str);
}

/*!
 * \brief Initiates MEA in new mode with text (buffer) insertion.
 *****************************************************************************/
void MEAc_startWithTextInserted(char *subject, char *text, MSF_BOOL isTruncated)
{

	msf_content_data_t contentData;
	int size;
	char *str = NULL;
       char* cmd = msf_cmmn_strdup(MSF_MODID_MSM, "-mode new -i");

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
      
	MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, MEA_ENV_4A93CC25579B8BB435EBA7080B622F30, "MEAc_startWithTextInserted()\n"));

	memset(&contentData, 0x00, sizeof(msf_content_data_t));
	contentData.routingIdentifier = msf_cmmn_strdup(MSF_MODID_MSM, "text/plain");
	contentData.routingFormat = MSF_ROUTING_TYPE_MIME;

	/* Text */
	if(text)
	{
		size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)text);
		if(size > 0)
		{
			contentData.contentData = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
			widget_ucs2_to_utf8_string((kal_uint8*)contentData.contentData, size + 1, (kal_uint8*)text);
			contentData.contentDataLength = size + 1;
		}
	}

	/* Subject */
	if(subject)
	{
		size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)subject);
		if(size > 0)
		{
			str = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
			widget_ucs2_to_utf8_string((kal_uint8*)str, size + 1,(kal_uint8*)subject);
			MSF_MEM_FREE(MSF_MODID_MSM, cmd);
			cmd = msf_cmmn_strcat(MSF_MODID_MSM, "-mode new -i -subject ", str);
		}
	}

	if(isTruncated)
	{
		contentData.contentDataLength++;
	}

	MSF_CONTENT_SEND_DRM_EXT(MSF_MODID_MSM, MSF_MODID_MEA, cmd, &contentData, 0, 0);
	MSF_MEM_FREE(MSF_MODID_MSM, contentData.routingIdentifier);
	MSF_MEM_FREE(MSF_MODID_MSM, contentData.contentData);
	MSF_MEM_FREE(MSF_MODID_MSM, str);
	MSF_MEM_FREE(MSF_MODID_MSM, cmd);
}


/*!
 * \brief Initiates MEA in new mode with content insertion.
 *****************************************************************************/
void MEAc_startWithContentInserted(char* contentSource)
{

	msf_content_data_t contentData;
	int size;
	const char * strMimeType;
	char * strContentSource = NULL;
	MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, MEA_ENV_6D82A4C998BF548C524317FF17E024C1, "MEAc_startWithContentInserted()\n"));

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

	/* convert UCS2 to UTF8 */
	size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) contentSource) + 1;
	strContentSource = MSF_MEM_ALLOC(MSF_MODID_MSM, size);
	widget_ucs2_to_utf8_string((kal_uint8*)strContentSource,size,(kal_uint8*)contentSource);	
	contentData.contentSource = msf_cmmn_strcat(MSF_MODID_MSM, HDI_EXTERNAL_PATH, strContentSource);
	strMimeType = meaFileName2MimeType(contentData.contentSource);

	if (strMimeType == NULL)
	{
#ifdef JPG_ENCODE
		if(meaIsResizedFile(strContentSource))
		{
			MSF_FILE_REMOVE(strContentSource);
		}
#endif	
		HDIa_widgetExtShowPopup(MSF_MODID_MSM, MEA_GET_STR_ID(MSF_STR_ID_DLG_MIME_ACTION_NONE), MsfAlert, 0);
		MSF_MEM_FREE(MSF_MODID_MSM, strContentSource);
		HDIa_widgetExtCloseTransitionAnimation();
		return;
	}
	contentData.routingIdentifier = MSF_MEM_ALLOC(MSF_MODID_MSM, strlen(strMimeType)+1);
	strcpy(contentData.routingIdentifier, strMimeType);

	contentData.contentUrl = NULL;
	contentData.routingFormat = MSF_ROUTING_TYPE_MIME;
	contentData.contentParameters = NULL;
	contentData.contentData = NULL;
	contentData.contentDataLength=0;
	contentData.contentHeaders=NULL;
	contentData.contentDRMData=NULL;
	contentData.contentDRMDataExists=0;
	contentData.auxTypeIdentifier = NULL;

	MSF_CONTENT_SEND_DRM_EXT(MSF_MODID_MSM, MSF_MODID_MEA, "-mode new -i", &contentData,0,0);
       MSF_MEM_FREE(MSF_MODID_MSM, strContentSource);
	MSF_MEM_FREE(MSF_MODID_MSM, contentData.routingIdentifier);
	MSF_MEM_FREE(MSF_MODID_MSM, contentData.contentUrl);
	if (contentData.contentSource)
	MSF_MEM_FREE(MSF_MODID_MSM, contentData.contentSource);
}

void meaTerminateApp(void)
{
    (void)MEA_SIGNAL_SENDTO(MEA_CORE_FSM, MEA_SIG_CORE_TERMINATE_APP);
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Kills the MEA module.
 *
 *****************************************************************************/
void MEAc_kill(void)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
        MEA_ENV_59528121117DCAABDC3F399AB250F673, "(%s) (%d) kill module is called.\n", __FILE__, __LINE__));
    MSF_PIPE_CLOSE_ALL(MSF_MODID_MEA);
    MSF_FILE_CLOSE_ALL(MSF_MODID_MEA);
    (void)MSF_WIDGET_RELEASE_ALL(MSF_MODID_MEA);
    MSF_MEM_FREE_ALL(MSF_MODID_MEA);
    MSF_KILL_TASK(MSF_MODID_MEA);
}

/* See the header file.
 * 
 *****************************************************************************/
MSF_BOOL MEAc_pbLaunchRsp(MSF_UINT16 result, MSF_UINT16 id, MeaPbItem *items)
{
    MeaAddrItem *cpy;
    MeaAddrItem *newItem;
    MeaPbItem   *tmp;

    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
        MEA_ENV_8289C1599050A853105E1C846187525A, "(%s) (%d) MEAc_pbLaunchRsp called, result = %d, id = %d!\n", __FILE__, 
        __LINE__, result, id));
    for(tmp = items; tmp != NULL; tmp = tmp->next)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MEA_ENV_6374B1ED8D4082DBAB99E9CA3E4CE7AE, "Phone book item: type = %d, addr = %s, name = %s\n", 
            tmp->type, tmp->addr, tmp->name));
    }
    
    /* If the result is ok copy the data */
    cpy = NULL;
    if (MEA_PB_LAUNCH_RESULT_OK == result)
    {
        while(NULL != items)
        {
            if (NULL == (newItem = meaPbhCopyItem(items))) //??
            {
                meaAddrListFree(&cpy);
                return FALSE;
            }
            /* Insert item */
            if (NULL != cpy)
            {
                newItem->next = cpy;
            }
            cpy = newItem;
            /* Log item */
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
                    MEA_ENV_F2242C76A6499FEDB996631E5253414D, "PB item: type = %d, name = \"%s\", addr = %s\n", 
                    newItem->addrType, newItem->name, newItem->address));
            /* Next item */
            items = items->next;
        }
    }
    /* Send the response */
    (void)MEA_SIGNAL_SENDTO_UUP(MEA_PBH_FSM, MEA_SIG_PBH_LAUNCH_RSP, 
        result, id, cpy);
    return TRUE;
}

/* See the header file.
 * 
 *****************************************************************************/
/*lint -e{818} */
MSF_BOOL MEAc_pbLookupNameRsp(MSF_UINT16 result, MSF_UINT16 instanceId, 
    MeaPbItem *item)
{
    MeaAddrItem *cpyItem = NULL;
    MeaPbhLookupItem *tmp;
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MEA_ENV_240C1403614E89FC1E789D2540790D27, "(%s) (%d) MEAc_pbLookupNameRsp result = %d, instanceId = %d, "
        "addrType = %d, name = %s, addr = %s\n", __FILE__, __LINE__, result, 
        instanceId, (NULL != item) ?item->type: 0, 
        (NULL != item) ? item->name: NULL, (NULL != item) ? item->addr: NULL));
    if ((MEA_PB_LOOKUP_RESULT_OK == result) && (NULL != item))
    {
        /* Copy the item */
        if (NULL == (cpyItem = meaPbhCopyItem(item)))
        {
            /* Prevent memory leak if the entry cannot be copied cannot be 
               sent */
            if (NULL != (tmp = meaPbhGetLookupEntry(instanceId)))
            {
                /*lint -e{774} */
                MEA_FREE(tmp);
            }
            return FALSE;
        }
    }
    /* Send the response */
    (void)MEA_SIGNAL_SENDTO_UUP(MEA_PBH_FSM, MEA_SIG_PBH_LOOKUP_RSP, 
        result, instanceId, cpyItem);
    return TRUE;
}


