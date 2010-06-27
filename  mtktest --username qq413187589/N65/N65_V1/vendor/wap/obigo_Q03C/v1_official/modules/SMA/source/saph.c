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
 * Description:     Utility functions for SMA.
 */

/* !\file sma_ph.c
 */

/* MSF */
#include "msf_mem.h" 
#include "msf_def.h"
#include "msf_cmmn.h"
#include "msf_core.h"
#include "msf_dlg.h"
#include "msf_sas.h"

#ifdef MSF_CONFIG_DRE
#include "msf_lib.h"
#include "msf_dre.h"
#endif

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"
#include "satypes.h"
#include "sapckg.h"
#include "saintsig.h"
#include "saui.h"

#ifdef MSF_CONFIG_DRE
#include "samem.h"
#endif

/******************************************************************************
 * Data-types
 *****************************************************************************/

static sma_pckg_handle_t *pHandle;      /* Package encapsulation handle */

/* SAS */
static sma_pkg_handle_t *sasHandle;
static sma_pkg_id_t      sasId;			/* Sas package ID */

/* DRM */
#ifdef MSF_CONFIG_DRE

typedef enum
{
    SMA_DRE_NONE,
    SMA_DRE_EXTRACT_HEAD,
    SMA_DRE_EXTRACT_OBJECT
}SmaDreState;


static sma_pkg_handle_t *dreHandle;    /* Dre instance ID */
static sma_pkg_id_t      dreId;		   /* Dre  package ID */
static MSF_UINT32        drePckId;     /* Dre instance ID */
static SmaDreState       dreState;
#endif


/* SAS */
static const sma_pckg_fnc_list_t sasFuncList = {
	msf_sas_init, 
    msf_sas_handle_signal,
    msf_sas_get_private_data, 
    (sma_pckg_set_private_data_t) msf_sas_set_private_data,
    msf_sas_terminate, 
    msf_sas_delete,
    msf_sas_get_result,
    msf_sas_result_free
};

#ifdef MSF_CONFIG_DRE
/* DRE */
static const sma_pckg_fnc_list_t dreFuncList = 
{
	msf_dre_init, 
    (sma_pckg_handle_signal_t) msf_dre_handle_signal,
    msf_dre_get_private_data, 
    (sma_pckg_set_private_data_t) msf_dre_set_private_data,
    msf_dre_terminate, 
    msf_dre_delete,
    msf_dre_get_result,
    msf_dre_result_free
};
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*! \brief SMA package operation completion entry point function.
 *
 * \param fsm      Fsm to forward signal to.
 * \param signal   Signal to send to fsm.
 * \param pkg_inst Package instance to completed operation.
 * \param id       Package operation ID.
 * \param result   Package operation result (type-cast per operation)
 * \param data     Private data provided at registration of operation.
 *
 * \return 0.
 *
 * NOTE: The result is deallocated when this function returns.
 *       If result data is to be kept, either copy or snatch pointer
 *       and set it to NULL (so that the free operation not can free it). 
 *****************************************************************************/
static int smaPacketSignalHand(MSF_INT32 fsm, MSF_INT32 signal, 
    sma_pkg_id_t pckg_id, sma_pkg_handle_t *pkg_inst, MSF_INT32 id,
    sma_pckg_result_t *result, void *data)
{
	msf_sas_result_save_as_t *sas_result;

#ifdef MSF_CONFIG_DRE
    msf_dre_result_extract_obj_t *dreObjResult;
    msf_dre_result_extract_msg_t *dreMsgResult;
    SmaDreResultItem *dreResult = NULL;
#endif
    SmaResult smaResult;

	(void)data;
	
	if ((sasHandle == pkg_inst) && (sasId == pckg_id))
	{
		sas_result = ((msf_sas_result_save_as_t*)sma_pckg_get_result_data(result));
        smaResult = (MSF_SAS_RETURN_ERROR != sas_result->result) ? 
            SMA_RESULT_OK: SMA_RESULT_ERROR;
		(void)SMA_SIGNAL_SENDTO_I((SmaStateMachine)fsm, signal, smaResult);
/*		sma_pckg_free_result(result);*/

		(void)msf_sas_delete (sasHandle, id);

	}
#ifdef MSF_CONFIG_DRE
    else if (dreId == pckg_id)
    {
        if (dreHandle == pkg_inst)
	    {
            if (SMA_DRE_EXTRACT_HEAD == dreState)
            {
		        dreMsgResult = ((msf_dre_result_extract_msg_t *)sma_pckg_get_result_data(result));
                smaResult = (MSF_DRE_RETURN_OK == dreMsgResult->result) ? 
                                SMA_RESULT_OK: SMA_RESULT_ERROR;
                if (SMA_RESULT_OK == smaResult)
                {
                    /* Allocate a buffer for sending the result */
                    dreResult = SMA_ALLOC(sizeof(SmaDreResultItem));
                    /* Copy the result */
                    dreResult->httpHeader = 
                        msf_cmmn_strdup(MSF_MODID_SMA, dreMsgResult->http_hdr);
                    dreResult->drmRights  = (char *)
                        msf_cmmn_strdup(MSF_MODID_SMA, 
                        (const char *)dreMsgResult->drm_data);
                }
                /* Send the response */
                SMA_SIGNAL_SENDTO_UUP(fsm, signal, smaResult, 
                    dreMsgResult->bytes_read, dreResult);
            }
            else if (SMA_DRE_EXTRACT_OBJECT == dreState)
            {
		        dreObjResult = ((msf_dre_result_extract_obj_t *)sma_pckg_get_result_data(result));
                smaResult = (MSF_DRE_RETURN_OK == dreObjResult->result) ? 
                    SMA_RESULT_OK: SMA_RESULT_ERROR;
                
                SMA_SIGNAL_SENDTO_UUP(fsm, signal, smaResult, 
                    dreObjResult->data_len, dreObjResult->data);
                dreObjResult->data = NULL;
                dreObjResult->data_len = 0;
            }
/*            sma_pckg_free_result(result);*/

		    (void)msf_dre_delete(dreHandle, id);
	    }
        /*
	    else
	    {
		    sma_pckg_free_result(result);
	    }
        */
    }
#endif
    /*
	else
	{
		sma_pckg_free_result(result);
	}
  */
    return 0;
}

/*! \brief Initiates the package handling for SMA.
 *
 * \return TRUE on successful initialization.
 *
 * Initializes the:
 * - Dialog package
 * - Afi package
 *
 *****************************************************************************/
MSF_BOOL smaPhInit(void)
{
    /* Initiate encapsulation */
    if (NULL == (pHandle = sma_pckg_create(MSF_MODID_SMA)))
    {
        return FALSE;
    }
	pHandle->do_free_result = TRUE;

	/* SAS */
    if (0 == (sasId = sma_pckg_reg_pckg(pHandle, &sasFuncList)))
    {
        return FALSE;
    }
    if (NULL == (sasHandle = sma_pckg_create_inst(pHandle, sasId)))
    {
        return FALSE;
    }
    /* Sets callback function */
    if (!sma_pckg_set_response_handler(pHandle, (sma_pckg_response_handler_t) smaPacketSignalHand))
    {
        return FALSE;
    }
    #ifdef MSF_CONFIG_DRE
	/* DRE */
    if (0 == (dreId = sma_pckg_reg_pckg(pHandle, &dreFuncList)))
    {
        return FALSE;
    }
    if (NULL == (dreHandle = sma_pckg_create_inst(pHandle, dreId)))
    {
        return FALSE;
    }
    /* Sets callback function */
    if (!sma_pckg_set_response_handler(pHandle, (sma_pckg_response_handler_t) smaPacketSignalHand))
    {
        return FALSE;
    }
    #endif
    return TRUE;
}

/*! \brief Terminates SMA package handling
 *
 * Terminates packages:
 * - Dialog package
 * - Afi package
 * - Sas package
 * - DRE package
 *
 *****************************************************************************/
void smaPhTerminate(MSF_BOOL panic)

{
	/* Terminate SAS */
	if (sma_pckg_terminate(pHandle, sasHandle, panic))
	{
		sasHandle = NULL;
	}
	(void)sma_pckg_unreg_pckg(pHandle, sasId);
    #ifdef MSF_CONFIG_DRE
    (void)sma_pckg_unreg_pckg(pHandle, dreId);
    #endif

	if (0 != pHandle)
	{
		sma_pckg_destroy(pHandle);
	}
    pHandle = 0;
} /* smaPhTerminate */


/*! \brief Calls package encapsulation signal handler.
 *
 * \param signal   External signal to handle.
 * \param p        Signal data.
 *
 * \return Returns TRUE if signal is consumed.
 *****************************************************************************/
MSF_BOOL smaPhHandleSignal(MSF_UINT16 signal, void *p)
{
    int res;

    res = sma_pckg_handle_signal(pHandle, signal, p);
    switch(res)
    {
    case MSF_PACKAGE_OPERATION_COMPLETE:
    case MSF_PACKAGE_SIGNAL_NOT_HANDLED:
        return FALSE;
    case MSF_PACKAGE_SIGNAL_HANDLED:
        return TRUE;
    default:
        return FALSE;
    }
} /* smaPhHandleSignal */


/****************************** SAS ******************************************/
/*! \brief Creates a dialog for Save As 
 *
 * \param fsm       Fsm that receives internal signal at completion.
 * \param signal    Signal to send to fsm at completion of the operation.
 * \param mimeTypes Comma separated list of mime-types wildcard '*' are allowed.
 * \param fileName  The file name of the object to save
 * \param data      The data to save.
 * \param dataLen   The length of the data to save.
 * \param drmRights The DRM header provided by the DRE package, or NULL if no 
 *                  DRM header exists.
 * \return A handle to the operation or 0 if the operation fails.
 *****************************************************************************/
MSF_UINT32 smaCreateSaveAs(SmaStateMachine fsm, int signal, 
	const char *mimeTypes, const char *fileName, char *data, MSF_UINT32 dataLen, 
    const char *drmRights)
{
	MSF_INT32 operId;
	msf_pck_attr_list_t *attrList;
	MSF_UINT32 ret;

	msf_pck_attr_init(&attrList);
	(void)msf_pck_add_attr_string_value (MSF_MODID_SMA, &attrList, 
		MSF_PCK_ATTRIBUTE_MIME, mimeTypes);
	(void)msf_pck_add_attr_int_value (MSF_MODID_SMA, &attrList,
		MSF_PCK_ATTRIBUTE_SIZE, (int)dataLen);
    /* Check if this is a DRM object */
    if (NULL != drmRights)
    {
        /* Set the DRM attribute */
        (void)msf_pck_add_attr_string_value(MSF_MODID_SMA, &attrList, 
            MSF_PCK_ATTRIBUTE_DRM, drmRights);

#ifdef MSF_CONFIG_DRE
		/* Guarantees that the FL is visible for CMA too when DRE is used */
		if(0 == strcmp(MSF_DRE_FORWARD_LOCK_DATA, drmRights))
		{
	        (void)msf_pck_add_attr_int_value(MSF_MODID_SMA, &attrList, 
            MSF_PCK_ATTRIBUTE_FLAGS,MSF_PCK_FLAG_DRM_FORWARD_LOCK);
		}
#endif
    }

	if ((operId = msf_sas_create_save_as(sasHandle, fileName, mimeTypes, 
		MSF_PCK_DATA_TYPE_BUFFER, data, (long)dataLen, NULL, attrList, 
		smaGetScreenHandle(), MSF_SAS_ALLOW_OVERWRITE)) > 0)
    {
        (void)sma_pckg_reg_operation(pHandle, sasHandle, (MSF_UINT32)operId, fsm, 
			signal, NULL);
        ret = (MSF_UINT32)operId;
    }
    else
    {
        ret = 0;
    } /* if */

	msf_pck_attr_free(MSF_MODID_SMA, attrList);

	return ret;
} /* smaCreateSaveAs */

/*! \brief Extract the DRM information from a "application/vnd.oma.drm.message"
 *
 * \param fsm       Fsm that receives internal signal at completion.
 * \param signal    Signal to send to fsm at completion of the operation.
 * \param filePath	file path to drm message.
 * \param offset	The drm object´s offset in the file.
 * \return TRUE if successful.
 *****************************************************************************/
MSF_BOOL smaDreGetMsgHeader(SmaStateMachine fsm, int signal, char *filePath,
    MSF_UINT32 offset, const char *boundary)
{ 
#ifdef MSF_CONFIG_DRE
	MSF_INT32 operId;    
	msf_dre_input_t inData;	

    memset(&inData, 0, sizeof(msf_dre_input_t));
	inData.data_type = MSF_PCK_DATA_TYPE_FILE;
	inData._u.file.pos = offset;
	inData._u.file.pathname = filePath;
    dreState = SMA_DRE_EXTRACT_HEAD;

	operId = msf_dre_extract_msg(dreHandle, &inData, boundary);

	if (operId > 0)
	{
		sma_pckg_reg_operation(pHandle, dreHandle, operId, fsm, signal, NULL);
        return TRUE;
	}
	else
	{
        dreState = SMA_DRE_NONE;
		return FALSE;
	}
#else
    (void)boundary;
    (void)offset;
    (void)filePath;
    (void)signal;
    (void)fsm;
    return FALSE;
#endif
}

/*! \brief Extract the DRM information from a "application/vnd.oma.drm.message"
 *
 * \param fsm       Fsm that receives internal signal at completion.
 * \param signal    Signal to send to fsm at completion of the operation.
 * \param filePath	file path to DRM message.
 * \param outPipePath The pipe to read from, if the asBuffer is set to FALSE.
 * \param drmHeader The 
 * \param offset	The drm object´s offset in the file.
 * \return TRUE if successful.
 *****************************************************************************/
MSF_BOOL smaDreGetObject(SmaStateMachine fsm, int signal, char *inFilePath, 
    char **outPipePath, char *drmHeader, const char* boundary, 
    MSF_UINT32 offset, MSF_BOOL asBuffer)
{
#ifdef MSF_CONFIG_DRE
    MSF_INT32 operId;
	msf_dre_input_t  inData;
	msf_dre_output_t  outData;
	
	/* Set input data */
    memset(&outData, 0, sizeof(msf_dre_output_t));
    memset(&inData, 0, sizeof(msf_dre_input_t));
	inData.data_type = MSF_PCK_DATA_TYPE_FILE; 
	inData._u.file.pathname = inFilePath;
	inData._u.file.pos = offset;
    dreState = SMA_DRE_EXTRACT_OBJECT;

	operId = msf_dre_extract_obj(dreHandle, &inData, boundary, drmHeader, 
        (asBuffer) ? MSF_PCK_DATA_TYPE_BUFFER: MSF_PCK_DATA_TYPE_PIPE, 
        &outData);
	
	if (operId > 0)
	{
		sma_pckg_reg_operation(pHandle, dreHandle, operId, fsm, signal, NULL);
        if (!asBuffer)
        {
		    *outPipePath = msf_cmmn_strdup(MSF_MODID_SMA, 
                outData._u.pipe.new_pathname);
        }
        return TRUE;
	}
	else
	{
        dreState = SMA_DRE_NONE;
		return FALSE;
	}	
#else
    (void)asBuffer;
    (void)offset;
    (void)boundary;
    (void)drmHeader;
    (void)outPipePath;
    (void)inFilePath;
    (void)signal;
    (void)fsm;
    return FALSE;
#endif
}

