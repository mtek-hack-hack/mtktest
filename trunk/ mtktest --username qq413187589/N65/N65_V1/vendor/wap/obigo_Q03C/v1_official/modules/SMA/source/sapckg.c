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

/*--- Include files ---*/
/* MSF */
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */ 
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_pck.h"    /* MSF: MSF File API */ 

/* SMA*/
#include "sapckg.h"

/*!
 * \brief  Initialise the package dispatcher.
 * \return Returns a handle if success, otherwise returns NULL.
 */
sma_pckg_handle_t* sma_pckg_create(MSF_UINT8 mod_id)
{
    sma_pckg_handle_t *pckg = 0;

    pckg = (sma_pckg_handle_t*) MSF_MEM_ALLOC(mod_id, sizeof(sma_pckg_handle_t));
    if (pckg == NULL)
    {
        return NULL;
    }

    pckg->mod_id = mod_id;
    pckg->reg_pkg_list = NULL;
    pckg->reg_inst_list = NULL;
    pckg->reg_handler = NULL;
    pckg->pkg_count = 0;
    pckg->do_free_result = TRUE;
    return pckg;
}

/*!
 * \brief This function encapsulates the package operation dispatching.
 *
 * This function should be called by the user module at reception
 * of an external signal.
 *
 * This functions scans through all registered package instances,
 * to ask if the received signal is to be consumed by the package
 * instance. If consumed the get_result function of the package is
 * called to see if the operation is completed.
 *
 * If an operation turns out to be completed a call is made to
 * the registered custom response handler.
 *
 * \param signal, The external signal Id.
 * \param sigData, The signal data supplied with the external signal.
 *
 * \return The function returns wheather the signal was consumed or not.
 *
 * Returns:
 *    MSF_PACKAGE_SIGNAL_NOT_HANDLED
 *      The signal was not handled by the package, the caller
 *      must process the signal by itself.
 *    MSF_PACKAGE_SIGNAL_HANDLED
 *      The signal was handled by the package.
 *    MSF_PACKAGE_OPERATION_COMPLETE
 *      The signal was handled by the package and the dialog is
 *      finished. In this case the id parameter indicates which dialog
 *      that has finished. 
 */

int sma_pckg_handle_signal( 
                       sma_pckg_handle_t *handle,
                       MSF_UINT16 signal, 
                       void *sig_data)
{
    int                   result = MSF_PACKAGE_SIGNAL_NOT_HANDLED;
    sma_pckg_inst_list_t *list = 0;
    sma_pckg_inst_list_t *inst = 0;
    sma_pckg_data_t      *private_data;
    MSF_INT32             oper_id = 0;
    msf_pck_result_t      oper_result;
    sma_pckg_result_t    *int_result = NULL;

    if (handle == NULL)
    {
        return result;
    }

    list = handle->reg_inst_list;

    while (result == MSF_PACKAGE_SIGNAL_NOT_HANDLED && list != NULL)
    {
        result = list->pkg_data->package_fncs->handle_signal_fnc(list->pkg_inst, signal, sig_data, &oper_id);
        if (result == MSF_PACKAGE_OPERATION_COMPLETE)
        {
            /*
             *	Increment operation counter.
             */
            --list->active_operations;

            /*
             *	Get private data from operation:
             */
            private_data = list->pkg_data->package_fncs->get_private_data_fnc(list->pkg_inst, oper_id);

            /*
             *	Get result data from operation:
             */
            /* dont care about result */
			(void)list->pkg_data->package_fncs->get_result_fnc(
				list->pkg_inst, oper_id, &oper_result);


            if (TRUE == list->terminate_requested)
            {                
                /*
                 *	Free encapsulation data
                 */
                MSF_MEM_FREE(handle->mod_id, private_data);

                /*
                 *	Free package data and terminate
                 */
				/* dont care about result */
                (void)list->pkg_data->package_fncs->free_result_fnc(
					list->pkg_inst, &oper_result);

                if (list->active_operations == 0)
                {

					/* dont care about result */
					(void)sma_pckg_terminate(handle, list->pkg_inst, FALSE);
                }
                
                return MSF_PACKAGE_OPERATION_COMPLETE;
            }

            if (FALSE == private_data->operation_active)
            {                            
                /*
                 *	Free encapsulation data
                 */
                MSF_MEM_FREE(handle->mod_id, private_data);
                
				/* dont care about result */
                (void)list->pkg_data->package_fncs->free_result_fnc(
					list->pkg_inst, &oper_result);

                return MSF_PACKAGE_OPERATION_COMPLETE;
            }

            int_result = MSF_MEM_ALLOC(handle->mod_id, sizeof(sma_pckg_result_t));
            if (NULL == int_result)
            {
                /* dont care about result */
                (void)list->pkg_data->package_fncs->free_result_fnc(
					list->pkg_inst, &oper_result);
                
                return FALSE;
            }
            
            int_result->pkg_handle = list->pkg_inst;
            int_result->free_fnc = list->pkg_data->package_fncs->free_result_fnc;
            int_result->module = handle->mod_id;
            int_result->oper_result._u.data = oper_result._u.data;
            int_result->oper_result.type = oper_result.type;
            
            /*
             *	Call response handler with operation data:
             */
			++list->active_operations;
            (void)(*handle->reg_handler)(
                private_data->sub_module,
                (MSF_INT32)private_data->response_action,
                list->pkg_data->pckg_id,
                list->pkg_inst,
                oper_id,
                int_result,
                private_data->custom_data);
            --list->active_operations;

            /*
             *	Free encapsulation data
             */
            MSF_MEM_FREE(handle->mod_id, private_data);

            /*
             *	Free result data from operation:
             */
            if (TRUE == handle->do_free_result)
            {
                sma_pckg_free_result(int_result);
            }

            return result;
        }
        else
        {
            inst = list;
            list = list->next;
            
            if (TRUE == inst->terminate_requested &&
                inst->active_operations == 0)
            {                
                /* dont care about result */
                (void)sma_pckg_terminate(handle, inst->pkg_inst, FALSE);
            }
        }        
    }

    return result;
} /* sma_pckg_handle_signal() */


MSF_UINT32 sma_pckg_get_result_uint(const sma_pckg_result_t *result)
{
    return (MSF_UINT32)result->oper_result._u.i_val;
}

void *sma_pckg_get_result_data(const sma_pckg_result_t *result)
{
    return result->oper_result._u.data;
}

/*!
 * \brief  Add definition of package functions.
 * \return Returns internal ID of the package.
 */
sma_pkg_id_t sma_pckg_reg_pckg(sma_pckg_handle_t* handle, const sma_pckg_fnc_list_t *fncs)
{
    sma_pckg_pkg_list_t *list = 0;

    if (handle == NULL || fncs == NULL)
    {
        return 0;
    }

    /*
     *	Allocate and initiate into list:
     */
    list = (sma_pckg_pkg_list_t*) MSF_MEM_ALLOC(handle->mod_id, sizeof(sma_pckg_pkg_list_t));
    if (list == NULL)
    {
        return 0;
    }

    list->next = handle->reg_pkg_list;
    handle->reg_pkg_list = list;
    handle->pkg_count++;
    list->pckg_id = handle->pkg_count;
    list->package_fncs = fncs;

    return list->pckg_id;
} /* sma_pckg_reg_pckg */

/*!
 * \brief  Add definition of package functions.
 * \return Returns TRUE if successful (fails if instances rsmains)
 */
int sma_pckg_unreg_pckg(sma_pckg_handle_t* handle, sma_pkg_id_t pckg_id)
{
    sma_pckg_pkg_list_t *list = 0;
    sma_pckg_pkg_list_t *prev = NULL;
    sma_pckg_inst_list_t *inst = NULL;
    
    if (handle == NULL)
    {
        return FALSE;
    }


    list = handle->reg_pkg_list;
    while (list != NULL && list->pckg_id != pckg_id)
    {
        prev = list;
        list = list->next;
    }

    if (list == NULL)
    {
        /*
         *	Package not found.
         */
        return FALSE;
    }

    /*
     *	Verify that no instance is active:
     */
    inst = handle->reg_inst_list;
    while (inst != NULL && inst->pkg_data != list)
    {
        inst = inst->next;
    }
    if (inst != NULL)
    {
        /*
         *	Package instanse still active:
         */
        return FALSE;
    }

    /*
     *	Unlink and free:
     */
    if (prev == NULL)
    {
        handle->reg_pkg_list = list->next;
    }
    else
    {
        prev->next = list->next;
    }
    list->next = NULL;
    list->package_fncs = NULL;
    MSF_MEM_FREE(handle->mod_id, list);

    return TRUE;
} /* sma_pckg_unreg_pckg() */

/*!
 * \brief  Creates an instance of a package.
 * \param  pckgId, returned by sma_pckg_reg_pckg().
 * \return Returns a handle to the package.
 */
sma_pkg_handle_t *sma_pckg_create_inst(sma_pckg_handle_t* handle, sma_pkg_id_t pckg_id)
{
    sma_pckg_pkg_list_t   *list = 0;
    sma_pckg_inst_list_t  *inst = NULL;
    sma_pkg_handle_t      *p = NULL;
    
    
    if (handle == NULL)
    {
        return NULL;
    }

    /*
     *	Locate package:
     */
    list = handle->reg_pkg_list;
    while (list != NULL && list->pckg_id != pckg_id)
    {
        list = list->next;
    }

    if (list == NULL)
    {
        /*
         *	Package not found.
         */
        return NULL;
    }

    /*
     *	Create new package instance:
     */
    p = list->package_fncs->init_fnc(handle->mod_id);
    if (p == NULL)
    {
        return NULL;
    }

    /*
     *	Allocate and link:
     */
    inst = (sma_pckg_inst_list_t*) MSF_MEM_ALLOC(handle->mod_id, sizeof(sma_pckg_inst_list_t));
    if (inst == NULL)
    {
        /*
         *	Memory allocation failure:
         */
        return NULL;
    }

    inst->pkg_data = list;
    inst->pkg_inst = p;
    inst->next = handle->reg_inst_list;
    inst->terminate_requested = FALSE;
    inst->active_operations = 0;
    
    handle->reg_inst_list = inst;

    return p;
} /* sma_pckg_create_inst() */

/*!
 * \brief  Terminates an instance of a package.
 *
 * Terminates the "pckgId" package, release all resources allocated by
 * this package. If there is any open dialogs, these dialog are
 * deleted. Any private data must be released before.
 * Returns TRUE  if success, otherwise FALSE.
 *
 * \param  pckgId, returned by sma_pckg_reg_pckg().
 * \return 
 */
int sma_pckg_terminate(sma_pckg_handle_t* handle, const void *pck_inst, 
	MSF_BOOL panic)
{
    sma_pckg_inst_list_t  *inst = NULL;
    sma_pckg_inst_list_t  *prev = NULL;
    
    if (handle == NULL)
    {
        return FALSE;
    }

    /*
     *	Locate package instance:
     */
    inst = handle->reg_inst_list;
    while (inst != NULL && inst->pkg_inst != pck_inst)
    {
        prev = inst;
        inst = inst->next;
    }

    if (inst == NULL)
    {
        /*
         *	Instance not found:
         */
        return FALSE;
    }

    inst->terminate_requested = TRUE;
    
    if (FALSE == panic && inst->active_operations > 0)
    {
        return TRUE;
    }
    
    /*
     *	Terminate the package instance:
     */
    if (!inst->pkg_data->package_fncs->terminate_fnc(inst->pkg_inst))
    {
		return FALSE;
    }
    
    /*
     *	Unlink and free:
     */
    if (prev == NULL)
    {
        handle->reg_inst_list = inst->next;
    }
    else
    {
        prev->next = inst->next;
    }
    inst->next = NULL;
    inst->pkg_data = NULL;
    inst->pkg_inst = NULL;
    MSF_MEM_FREE(handle->mod_id, inst);

    return TRUE;
} /* sma_pckg_terminate */

/*
 * \brief Deletes/cancels an operation.
 *
 * Deletes a created operation. Any private data is not released by 
 * this function. The module call this function when the module of any
 * reason must delete the operation before the finished state has been
 * reached.
 *
 * \param Handle, package instance handle
 * \param id, package operation id
 * \param private_data, returns pointer to any private_data, this must be
 *        deallocated by the caller.
 *
 * \return Returns TRUE  if success, otherwise FALSE.
 */
int sma_pckg_cancel(const sma_pckg_handle_t* handle, const void* pkg_inst, 
	MSF_INT32 id, void **private_data)
{
    sma_pckg_inst_list_t  *inst = NULL;
    sma_pckg_data_t       *int_data;
 
    (*private_data) = NULL; 

    if (handle == NULL)
    {
        return FALSE;
    }

    /*
     *	Locate package instance:
     */
    inst = handle->reg_inst_list;
    while (inst != NULL && inst->pkg_inst != pkg_inst)
    {
        inst = inst->next;
    }

    if (inst == NULL)
    {
        /*
         *	Instance not found:
         */
        return FALSE;
    }

    /*
     *	First get any private data connected to the operation:
     */
    int_data = inst->pkg_data->package_fncs->get_private_data_fnc(inst->pkg_inst, id);
    if (FALSE == int_data)
    {
        return FALSE;
    }

    /*
     *	Return private data to free:
     */
    (*private_data) = int_data->custom_data;
    int_data->custom_data = NULL;
    int_data->operation_active = FALSE;
    
    /*
     *	Deletes the package operation:
     */
    if (NULL != inst->pkg_data->package_fncs->delete_fnc)
    {
        if (FALSE == inst->pkg_data->package_fncs->delete_fnc(inst->pkg_inst, id))
        {
            return TRUE;
        }

        /*
         *	Free insternal encapsulation data:
         */
        MSF_MEM_FREE(handle->mod_id, int_data);
    }

    return TRUE;
} /* sma_pckg_delete */

/*!
 * \brief Sets dispatcher function for package handler.
 *
 * The supplied dispatcher function is called whenever an operation
 * is completed.
 * It is up to the user module to decide what actions to take on the
 * completion of the operation. The dispacher MUST handle the private_data
 * supplied in the dispatcher function call.
 *
 * \param handle, The Package encapsulator handle.
 * \param dispatcher, function pointer to user module dispatcher 
 *
 * \return Returns TRUE is successful.
 */
int sma_pckg_set_response_handler(sma_pckg_handle_t* handle, sma_pckg_response_handler_t response_handler)
{
    if (handle == NULL)
    {
        return FALSE;
    }
    handle->reg_handler = response_handler;

    return TRUE;
} /* sma_pckg_set_response_handler() */

/*!
 * \brief Registers an started package operation and registers response action.
 *
 * This function is called to start a package operation.
 * Whenever the operation is completed the response function set earlier
 * is called with the sub_module, action and custom data parameters passed
 * to this function as well as the operation Id.
 *
 * \param handle, The Package encapsulator handle.
 * \param pck_inst, Handle to the package instance.
 * \param oper_id, The id of the started operation.
 * \param sub_module, Data to the response handler.
 * \param action, Data to the response handler.
 * \param custom_data, custom data pointer to the response handler.
 *
 * \return Returns TRUE is successful.
 */
int sma_pckg_reg_operation(
          const sma_pckg_handle_t *handle,
          sma_pkg_handle_t  *pck_inst,
          MSF_UINT32         oper_id,
          MSF_INT32          sub_module,
          MSF_INT32          action,
          void              *custom_data)
{
    msf_pck_result_t     oper_result;
    sma_pckg_data_t      *private_data = NULL;
    sma_pckg_inst_list_t *inst = NULL;
    sma_pckg_result_t    *result = NULL;
    int                   status;
 
    if (handle == NULL)
    {
        return FALSE;
    }

    /*
     *	Locate package instance:
     */
    inst = handle->reg_inst_list;
    while (inst != NULL && inst->pkg_inst != pck_inst)
    {
        inst = inst->next;
    }

    if (inst == NULL)
    {
        /*
         *	Instance not found:
         */
        return FALSE;
    }


    /*
     *	First check if operation is delayed:
     */
    status = inst->pkg_data->package_fncs->get_result_fnc(pck_inst, 
		(MSF_INT32)oper_id, &oper_result);

    
    if (MSF_PACKAGE_COMPLETED == status)
    {
        result = MSF_MEM_ALLOC(handle->mod_id, sizeof(sma_pckg_result_t));
        if (NULL == result)
        {
			/* dont care about result */
            (void)inst->pkg_data->package_fncs->free_result_fnc(
				inst->pkg_inst, &oper_result);
            
            return FALSE;
        }
        result->pkg_handle = inst->pkg_inst;
        result->free_fnc = inst->pkg_data->package_fncs->free_result_fnc;
        result->module = handle->mod_id;
        result->oper_result._u.data = oper_result._u.data;
        result->oper_result.type = oper_result.type;
        
        /*
         *	Operation completed, call response function.
         */
		++inst->active_operations;	
        (void)(*handle->reg_handler)(
            sub_module,
            action,
            inst->pkg_data->pckg_id,
            pck_inst,
            (MSF_INT32)oper_id,
            result,
            custom_data);
		--inst->active_operations;

        /*
         *	Free encapsulation data
         */
        MSF_MEM_FREE(handle->mod_id, private_data);

        /*
         *	Free result data from operation:
         */
        if (TRUE == handle->do_free_result)
        {
            sma_pckg_free_result(result);
        }

        return TRUE;
    }
    else if (MSF_PACKAGE_ERROR == status)
    {
        return FALSE;
    }
    else /* operation delayed */
    {
        /*
         *	Some irrelevant data was returned....free...
         */
		/* dont care about result */
        (void)inst->pkg_data->package_fncs->free_result_fnc(
			inst->pkg_inst, &oper_result);

        /*
         *	Set private data from operation:
         */
        private_data = MSF_MEM_ALLOC(handle->mod_id, sizeof(sma_pckg_data_t));
        if (private_data == NULL)
        {
            return FALSE;
        }
        private_data->custom_data = custom_data;
        private_data->response_action = (MSF_UINT32)action;
        private_data->sub_module = sub_module;
        private_data->operation_active = TRUE;

        /*
         *	Increment operation counter.
         */
        ++inst->active_operations;

        return inst->pkg_data->package_fncs->set_private_data_fnc(pck_inst, 
			(MSF_INT32)oper_id, private_data);
    }
} /* sma_pckg_reg_operation() */

/*!
 * \brief  Free data retrived by get_result from an operation.
 */
void sma_pckg_free_result(sma_pckg_result_t *result)
{
    if (NULL != result)
    {
        /* do not care about result */
		(void)result->free_fnc(result->pkg_handle, &(result->oper_result));
        MSF_MEM_FREE(result->module, result);
    }
}

/*! /brief Closes down all encapsulation activities.
 *
 * /param handle Encapsulation handle.
 */
void sma_pckg_destroy(sma_pckg_handle_t *handle)
{
    sma_pckg_inst_list_t *inst_list = NULL;
    sma_pckg_pkg_list_t *pckg_list = NULL;
	sma_pckg_pkg_list_t *tmp_pckg_list = NULL;
    
    inst_list = handle->reg_inst_list;
    while (NULL != inst_list)
    {
        
		/* do not care about result */
		(void)sma_pckg_terminate(handle, inst_list->pkg_inst, TRUE);
		inst_list = handle->reg_inst_list;
    }

    pckg_list = handle->reg_pkg_list;
    while (NULL != pckg_list)
    {
		tmp_pckg_list = pckg_list->next;
        /* do not care about result */
		(void)sma_pckg_unreg_pckg(handle, pckg_list->pckg_id);
        pckg_list = tmp_pckg_list;
    }

    MSF_MEM_FREE(handle->mod_id, handle);
}


