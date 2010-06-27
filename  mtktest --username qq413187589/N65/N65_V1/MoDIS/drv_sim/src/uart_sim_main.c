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
 * Filename:
 * ---------
 *   uart_sim_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   UART task main.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/************************
Macros Without Parameters
*************************/

#include "uart_sim_inc.h"

vp_contextT vport[MAX_VIRTUAL_PORT_SUPPORT];


static kal_bool vuart_reset( task_indx_type task_indx );
static void vuart_main(ilm_struct *ilm_ptr);
static kal_bool vuart_reset( task_indx_type task_indx );
static kal_bool vuart_init(task_indx_type task_indx);
static  void vuart_task_main(task_entry_struct *task_entry_ptr);

extern void vuart_handleDataInd(local_para_struct*,peer_buff_struct*);
extern void vuart_handleSetConfigInd(local_para_struct*);
extern void vp_setPort(kal_uint16 index, UART_PORT port);
/*****************************************************************************
* FUNCTION
*  uart_create
* DESCRIPTION
*   This function is message dispatcher for MM.
*
* PARAMETERS
*  ilm_ptr  IN    the ILM
* RETURNS
*  void
* GLOBALS AFFECTED
*
*****************************************************************************/

kal_bool vuart_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct handler_info =
	{
		vuart_task_main,			/* task entry function */
		vuart_init,			/* task initialization function */
		NULL,		/* task configuration function */
		vuart_reset,				/* task reset handler */
		NULL,				/* task termination handler */
	};

	*handle = (comptask_handler_struct *) &handler_info;
	return KAL_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mm_task_main
* DESCRIPTION
*   This function is message dispatcher for MM.
*
* PARAMETERS
*  ilm_ptr  IN    the ILM
* RETURNS
*  void
* GLOBALS AFFECTED
*
*****************************************************************************/

static  void vuart_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;

    kal_uint32   my_index;

    kal_get_my_task_index(&my_index);
    stack_set_active_module_id (my_index, MOD_VUART);

    while (1)
    {
        receive_msg_ext_q( task_info_g[task_entry_ptr->task_indx].task_ext_qid,
                         &current_ilm);
        vuart_main(&current_ilm);
        free_ilm(&current_ilm);
                
    }

}



/*****************************************************************************
* FUNCTION
*  mm_main
* DESCRIPTION
*   This function is message dispatcher for MM.
*
* PARAMETERS
*  ilm_ptr  IN    the ILM
* RETURNS
*  void
* GLOBALS AFFECTED
*
*****************************************************************************/
static void vuart_main(ilm_struct *ilm_ptr)
{

    switch(ilm_ptr->msg_id)
    {

        /* L4C */
        case MSG_ID_UART_DATA_IND:
            vuart_handleDataInd(ilm_ptr->local_para_ptr,ilm_ptr->peer_buff_ptr);
            break;

        case MSG_ID_UART_PUTBYTES_REQ:
            // do nothing, but free the ilm in uart_task_main
            break;

        case MSG_ID_UART_SET_CONFIG_IND:
            vuart_handleSetConfigInd(ilm_ptr->local_para_ptr);
            break;
            
        default:
            break;
    }

   
}

/*****************************************************************************
* FUNCTION
*  mm_reset
* DESCRIPTION
*   This function is just for template.
*
* PARAMETERS
* RETURNS
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
static kal_bool vuart_reset( task_indx_type task_indx )
{

   return KAL_TRUE;
}

kal_bool vuart_init(task_indx_type task_indx)
{
    kal_uint32 i;

    for(i=0;i< MAX_VIRTUAL_PORT_SUPPORT; i++)
    {
        kal_uint32 j;
        
        vport[i].owner = MOD_NIL;
        vport[i].port= uart_port_null;
        vport[i].is_WriteSuspend = KAL_FALSE;
        vport[i].currentDataPos = 0;
        vport[i].maxWriteLength= DEFAULT_TX_BUFFER_SIZE;
        for(j=0; j < MAX_RX_DATA_QUEUE; j++)
        {
            vport[i].rxDataArray[j] = NULL;
        } 
    }
    vp_setPort(0,uart_port1);
    return KAL_TRUE;
}
