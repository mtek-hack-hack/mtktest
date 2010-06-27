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
    
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_def.h"    /* MSF: Global definitions */ 
#include "msf_core.h"   /* MSF: System core call */ 
#include "msf_dcvt.h"   /* MSF: Type conversion routines */ 
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_wid.h"    /* MSF: Widget handling */ 

#ifdef WAP_SUPPORT
#include "widget_extension.h"  /* for satypes.h */
#endif

/* SLS */
#include "sls_def.h"
#include "sls_cfg.h"
#include "sls_if.h"

/* SMA */
#include "sma_def.h"
#include "sma_if.h"
#include "sma_vrsn.h"   /* Version information */
#include "sasig.h"
#include "saintsig.h"
#include "satypes.h"
#include "samain.h"
#include "sma_env.h"

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/
/* The following two variables are used to handle out-of-memory situations. The
 * naming of variables and functions for these are somewhat different due to 
 * MSF. The variable mms_inside_run is used to indicate if the call comes 
 * via the SMAc_run function so that it is safe to longjmp back to SMAc_run in
 * case of an out-of-memory situation. It is actually a BOOL but in order to
 * be exactly the same as other modules, it has type int and will use 0 and 1
 * to indicate TRUE and FALSE. */
static jmp_buf      sma_jmpbuf;     /* Buffer for longjmp */
static int          sma_inside_run; /* If call originates from SMAc_run or not */


/*--- Prototypes ---*/
static void sma_exception_handler(void);

/*****************************************************************************/

/*
 * Prepares SMA for running.
 *
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
void SMAc_start(void)
{
    sma_inside_run = 0;
    memset( sma_jmpbuf, 0, sizeof(sma_jmpbuf));

    /* Initialize the memory allocator. Needed in most other functions. */
    MSF_MEM_INIT(MSF_MODID_SMA, sma_exception_handler);

    /* Register the signal queue */ 
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_SMA);

    /* Register conversion and destruction functions */
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_SMA, sma_convert, sma_destruct);
    
    /* Registrate the module into MSF */
    MSF_MODULE_IS_CREATED(MSF_MODID_SMA, (char *)SMA_VERSION);
} /* SMAc_start */

/*
 * Perform an execution 'tick' for SMA.
 *
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
void SMAc_run(void)
{
    int jmpResult = 0;
	SmaResult sma_exit_result;

    sma_inside_run = 1;
	jmpResult = setjmp( sma_jmpbuf);

	/* Copy the jump buffer */
	/*lint -e{545} */
	smaSetJumpBuffer( &sma_jmpbuf );

    if ( jmpResult == 0)
    {
        if (MSF_SIGNAL_QUEUE_LENGTH( MSF_MODID_SMA) > 0)
        {
            /* Retrieve ONE external signal. Can't take'em all since it can be MANY */
            (void) MSF_SIGNAL_RETRIEVE(MSF_MODID_SMA, smaReceiveExtSignal);
        } /* if */

        smaSignalProcess();   /* Process one signal and return. */
    }
    else
    {
        if (SMA_PANIC_OUT_OF_MEMORY == smaPanicMode)
        {
           /*
            * A longjmp from alloc. If we are here there is no more
            * memory, and the situation could not be worse.
            * Terminate the SMA and let the TDA re-initialise it again.
            */
            SMAc_kill();
        } 
        else if (SMA_PANIC_NO_DIALOG == smaPanicMode)
        {
		    sma_exit_result = getSmaExitResult();
            exitSmilPlayer(sma_exit_result, TRUE);
        } 
        else if (SMA_PANIC_TERMINATE == smaPanicMode)
        {
		    sma_exit_result = getSmaExitResult();
            exitSmilPlayer(sma_exit_result, FALSE);
            SMAc_kill();
        }/* if */
    }
    sma_inside_run = 0;
} /* SMAc_run */



/*
 * Check if SMA wants to run. 
 *
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
int SMAc_wantsToRun(void)
{
    return !smaSignalQueueIsEmpty() ||
        MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_SMA) > 0;
} /* SMAc_wantsToRun */

/*
 * Emergency terminate function. Used by MSF to kill the module.
 *
 * Please note: Doxygen dokumentation, see file description in top of file.
 *****************************************************************************/
void SMAc_kill (void)
{
    (void)MSF_WIDGET_RELEASE_ALL(MSF_MODID_SMA);
    
	MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_SMA);
	MSF_MEM_FREE_ALL(MSF_MODID_SMA);
    MSF_KILL_TASK(MSF_MODID_SMA);
	MSF_MODULE_IS_TERMINATED(MSF_MODID_SMA);
} /* SMAc_kill */

/*!
 * \brief Used to handle memory exceptions and to emergency stop the SMA Application
 *
 * Odd function name to be consistent with external requirements.
 *
 *****************************************************************************/
static void sma_exception_handler(void)
{
    if (sma_inside_run)
    {
        smaPanicMode = SMA_PANIC_OUT_OF_MEMORY;
        longjmp( sma_jmpbuf, SMA_PANIC);
    }
    else
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, 
            SMA_ENV_4F0AE80D93BF5AF1741C3F381F017DE0, "%s(%d): Insufficient memory!\n", __FILE__, __LINE__));

        SMAc_kill();
    } /* if */
} /* sma_exception_handler */

