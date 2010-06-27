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

#ifndef _MAPCKG_H_
#define _MAPCKG_H_


#ifndef _msf_def_h
#include "msf_def.h"
#endif

#ifndef _msf_hdr_h
#include "msf_hdr.h"
#endif

#ifndef _msf_pck_h
#include "msf_pck.h"
#endif


/**********************************************************************
 * Defines 
 **********************************************************************/
/*Result codes*/

/**********************************************************************
 * Types
 **********************************************************************/

/*! \brief Internal structure for callback handling data.
 *
 */
typedef struct
{
    MSF_INT32   sub_module;          /* Response receiver */
    MSF_UINT32  response_action;     /* Response internal signal */
    void        *custom_data;        /* Receiver custom data */
    MSF_BOOL    operation_active;    /* Has the operation been canceled? */
} mea_pckg_data_t;


typedef void        mea_pkg_handle_t;   /* This is dummy package handle type */
typedef MSF_UINT8   mea_pkg_id_t;       /* Package encapsulation internal package id */

/* Function pointer type for package handle signal */
typedef int (*mea_pckg_handle_signal_t)(
                       mea_pkg_handle_t *pkg_inst,
                       MSF_UINT16        signal,
                       void             *sig_data,
                       MSF_INT32        *id);

/* Function pointer type for package instance allocation */
typedef mea_pkg_handle_t *(*mea_pckg_init_t)(MSF_UINT8 mod_id);

/* Function pointer type for package get private data */
typedef void *(*mea_pckg_get_private_data_t)(
                       mea_pkg_handle_t *pkg_inst,
                       MSF_INT32         id);

/* Function pointer type for package get private data */
typedef int (*mea_pckg_set_private_data_t)(
                                           mea_pkg_handle_t *pkg_inst,
                                           MSF_INT32         id,
                                           void             *p);

/* Function pointer type for package terminate */
typedef int (*mea_pckg_terminate_t)(
                       mea_pkg_handle_t *pkg_inst);

/* Function pointer type for package delete */
typedef int (*mea_pckg_delete_t)(
                       mea_pkg_handle_t *pkg_inst,
                       MSF_INT32         id);

/* Function pointer type for package get result */
typedef int (*mea_pckg_get_result_t)(
                       mea_pkg_handle_t *pkg_inst, 
                       MSF_INT32         id,
                       msf_pck_result_t *result);

/* Function pointer type for package free result */
typedef int (*mea_pckg_free_result_t)(
                       mea_pkg_handle_t *pkg_inst,
                       msf_pck_result_t *result);

/*! \brief Internal structure for simplifying free.
 *
 */
typedef struct {
    msf_pck_result_t       oper_result;           /* Operation result */
    mea_pkg_handle_t       *pkg_handle;           /* package handle */
    mea_pckg_free_result_t free_fnc;              /* Free function ptr */    
    MSF_INT8               module;                /* Module memory ref */    
} mea_pckg_result_t;


/* Function pointer type for custom user module operation response handler */
typedef int (*mea_pckg_response_handler_t)(
                       MSF_INT32            sub_module, /* Module internal fsm or similar (optional) */
                       MSF_INT32            action,     /* What action to take at operation completion (optional) */
                       mea_pkg_id_t         pckg_id,    /* Package registration Id */
                       mea_pkg_handle_t     *pkg_inst,  /* Package instance handle */
                       MSF_INT32            id,         /* Package operation Id */
                       mea_pckg_result_t    *result,    /* Operation result data */
                       void                 *data);     /* Private_data, (optional) */

typedef struct mea_pckg_fnc_list_t
{
    mea_pckg_init_t             init_fnc;               /* Package instance allocation */
    mea_pckg_handle_signal_t    handle_signal_fnc;      /* Handle signal function ptr */
    mea_pckg_get_private_data_t get_private_data_fnc;   /* Get private data function ptr */
    mea_pckg_set_private_data_t set_private_data_fnc;   /* Get private data function ptr */
    mea_pckg_terminate_t        terminate_fnc;          /* Terminate handle function ptr */
    mea_pckg_delete_t           delete_fnc;             /* Delete operation function ptr */
    mea_pckg_get_result_t       get_result_fnc;         /* Get result function ptr */
    mea_pckg_free_result_t      free_result_fnc;        /* Free result function ptr */
} mea_pckg_fnc_list_t;


typedef struct mea_pckg_pkg_list_t
{
    mea_pkg_id_t                pckg_id;
    const mea_pckg_fnc_list_t  *package_fncs;               /* Package function pointers */
    
    struct mea_pckg_pkg_list_t *next;
} mea_pckg_pkg_list_t;


typedef struct mea_pckg_inst_list_t
{
    mea_pckg_pkg_list_t         *pkg_data;
    mea_pkg_handle_t            *pkg_inst;
    MSF_UINT32                  active_operations;
    MSF_BOOL                    terminate_requested;
    
    struct mea_pckg_inst_list_t *next;
} mea_pckg_inst_list_t;

typedef struct
{
    MSF_UINT8                    mod_id;          /* Usage context, for memory allocation */
    mea_pkg_id_t                 pkg_count;       /* Counter for package ID */
    mea_pckg_pkg_list_t         *reg_pkg_list;    /* List of registered packages */
    mea_pckg_inst_list_t        *reg_inst_list;   /* List of registered package instances */
    MSF_BOOL                     do_free_result;  /* Shal encapsulation auto free data ? */
    
    mea_pckg_response_handler_t  reg_handler;     /* Registered internal operation handler. */
} mea_pckg_handle_t;


/**********************************************************************
 * Global functions
 **********************************************************************/

/*!
 * \brief  Initialise the package dispatcher.
 * \return Returns a handle if success, otherwise returns NULL.
 */
mea_pckg_handle_t* mea_pckg_create(MSF_UINT8 mod_id);

/*! /brief Closes down all encapsulation activities.
 *
 * /param handle Encapsulation handle.
 */
void mea_pckg_destroy(mea_pckg_handle_t *handle);

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
 * \param handle, package encapsulator handle.
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
int mea_pckg_handle_signal( 
             mea_pckg_handle_t *handle,
             MSF_UINT16 signal, 
             void *sig_data
             );

/*!
 * \brief  Add definition of package functions.
 * \return Returns internal ID of the package.
 */
mea_pkg_id_t mea_pckg_reg_pckg(mea_pckg_handle_t* handle, const mea_pckg_fnc_list_t *fncs);

/*!
 * \brief  Add definition of package functions.
 * \return Returns TRUE if successful (fails if instances remains)
 */
int mea_pckg_unreg_pckg(mea_pckg_handle_t* handle, mea_pkg_id_t pckg_id);

/*!
 * \brief  Creates an instance of a package.
 * \param  pckgId, returned by mea_pckg_reg_pckg().
 * \return Returns a handle to the package.
*/
mea_pkg_handle_t *mea_pckg_create_inst(mea_pckg_handle_t* handle, mea_pkg_id_t pckg_id);

/*!
 * \brief  Terminates an instance of a package.
 *
 * Terminates the "pckgId" package, release all resources allocated by
 * this package. If there is any open dialogs, these dialog are
 * deleted. Any private data must be released before.
 * Returns TRUE  if success, otherwise FALSE.
 *
 * \param  pckgId, returned by mea_pckg_reg_pckg().
 * \param  panic, Terminate immediately (no garbage collection).
 * \return 
 */
int mea_pckg_terminate(mea_pckg_handle_t* handle, void *pck_inst, MSF_BOOL panic);

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
int mea_pckg_cancel(mea_pckg_handle_t* handle, void* pck_inst, MSF_INT32 id, void **private_data);

/*!
 * \brief Sets operation response function for package encapsulator.
 *
 * The supplied response function function is called whenever an operation
 * is completed.
 * It is up to the user module to decide what actions to take on the
 * completion of the operation. The dispacher MUST handle the private_data
 * supplied in the dispatcher function call.
 *
 * \param handle, The Package encapsulator handle.
 * \param response_handler, function pointer to user module response function 
 *
 * \return Returns TRUE is successful.
 */
int mea_pckg_set_response_handler(mea_pckg_handle_t* handle, mea_pckg_response_handler_t response_handler);

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
int mea_pckg_reg_operation(
          mea_pckg_handle_t *handle,
          mea_pkg_handle_t  *pck_inst,
          MSF_UINT32         oper_id,
          MSF_INT32          sub_module,
          MSF_INT32          action,
          void              *custom_data);

/*!
 * \brief  Free data retrived by get_result from an operation.
 */

void mea_pckg_free_result(mea_pckg_result_t *result);

/*!
 *
 */
MSF_UINT32 mea_pckg_get_result_uint(mea_pckg_result_t *result);

/*!
 *
 */
void *mea_pckg_get_result_data(mea_pckg_result_t *result);

#endif /* _MAPACK_H_ */


