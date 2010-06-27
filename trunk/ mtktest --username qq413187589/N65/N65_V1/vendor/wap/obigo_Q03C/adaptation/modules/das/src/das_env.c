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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   das_env.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements DAS modules thread related function
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
#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"

#include "ctk.h"
#include "das_main.h"

extern int das_wantsToRun;

/**********************************************************************
 * Function declarations
 **********************************************************************/

static void das_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p);

/**********************************************************************
 * Function definitions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  DASc_start
 * DESCRIPTION
 *  this function will be called when module jas is initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DASc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    das_init();
}


/*****************************************************************************
 * FUNCTION
 *  DASc_wantsToRun
 * DESCRIPTION
 *  this function will be called when MSF environment want to known module jas have something to do or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int DASc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_DAS) > 0 || das_wantsToRun);
}


/*****************************************************************************
 * FUNCTION
 *  DASc_run
 * DESCRIPTION
 *  this function will be called when module JAS want process something.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DASc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (setjmp(das_jmpbuf) == 0)
    {
        das_insideRun = TRUE;

        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_DAS, das_receive));

        das_process();

        das_insideRun = FALSE;
        das_wantsToRun = FALSE;
    }
    else
    {
        /*
         * A longjmp from das_exception_handler. If we are here there is no more
         * * memory, and the situation could not be worse.
         * * Send out an error and terminate.
         */
        MSF_ERROR(MSF_MODID_DAS, MSF_ERR_MODULE_OUT_OF_MEMORY);
        MSF_PIPE_CLOSE_ALL(MSF_MODID_DAS);
        MSF_FILE_CLOSE_ALL(MSF_MODID_DAS);
        MSF_WIDGET_RELEASE_ALL(MSF_MODID_DAS);
        MSF_MEM_FREE_ALL(MSF_MODID_DAS);
        MSF_MODULE_IS_TERMINATED(MSF_MODID_DAS);
        MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_DAS);
        MSF_KILL_TASK(MSF_MODID_DAS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  DASc_kill
 * DESCRIPTION
 *  this function will be called MSF environment want terminate jas module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DASc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_PIPE_CLOSE_ALL(MSF_MODID_DAS);
    MSF_FILE_CLOSE_ALL(MSF_MODID_DAS);
    MSF_WIDGET_RELEASE_ALL(MSF_MODID_DAS);
    MSF_MEM_FREE_ALL(MSF_MODID_DAS);
    MSF_KILL_TASK(MSF_MODID_DAS);
}


/*****************************************************************************
 * FUNCTION
 *  das_receive
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  srcModule       [IN]        
 *  signal          [IN]        
 *  p               [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void das_receive(MSF_UINT8 srcModule, MSF_UINT16 signal, void *p)
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
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_DAS, DAS_ENV_47EBAD081A2B64226BDE30054D0926E6, "DAS: Received MSF_SIG_MODULE_EXECUTE_COMMAND\n"));

            das_execute_commands(srcModule, p);
            MSF_SIGNAL_DESTRUCT(MSF_MODID_DAS, signal, p);
            break;
        case MSF_SIG_PIPE_NOTIFY:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PRS, DAS_ENV_126C1138F85E2D63C63D403A1625FA07, "DAS: Received MSF_SIG_PIPE_NOTIFY\n"));

            das_handle_pipe_notify(((msf_pipe_notify_t*) p)->handle, ((msf_pipe_notify_t*) p)->eventType);
            MSF_MEM_FREE(MSF_MODID_DAS, p);
            break;
        case MSF_SIG_MODULE_TERMINATE:
            das_terminate();
            break;
        default:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PRS, DAS_ENV_ECA18A1F0BEDED2E0A123B14F4837B1A, "DAS: Received unknown signal (%04x)\n", signal));
            MSF_MEM_FREE(MSF_MODID_DAS, p);
            break;
    }
}
