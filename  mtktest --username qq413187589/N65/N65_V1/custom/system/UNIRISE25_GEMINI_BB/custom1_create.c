/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom1_create.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements custom1 component task create function
 *
 * Author:
 * -------
 *   system auto generator V0.30
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
* Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "custom_util.h"
#include "stack_init.h"
#include "stack_ltlcom.h"


/*************************************************************************
* Function declaration
 *************************************************************************/
static void custom1_main(task_entry_struct * task_entry_ptr);
static void custom2_main(task_entry_struct * task_entry_ptr);

/*************************************************************************
* FUNCTION
*  custom1_create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if (defined(G_SENSOR_SUPPORT) )
//Huyanwei Add It 
void SendMessagesOneToMMI(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
  	send_ilm = allocate_ilm(MOD_CUSTOM1);
	if( send_ilm == NULL)
	{
		times ++ ;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\nOne To MMI :%d\r\n",times);
#endif		
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM1;
   send_ilm->dest_mod_id = MOD_MMI ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesOneToOne(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
  	send_ilm = allocate_ilm(MOD_CUSTOM1);
	if( send_ilm == NULL)
	{
		times ++ ;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\nOne To One:%d\r\n",times);
#endif		
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM1;
   send_ilm->dest_mod_id = MOD_CUSTOM1 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesMMIToOne(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
   	send_ilm = allocate_ilm(MOD_MMI);
	if( send_ilm == NULL)
	{
		times ++ ;
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\nMMI To One:%d\r\n",times);
#endif		
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_MMI;
   send_ilm->dest_mod_id = MOD_CUSTOM1 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}
#endif

#if (defined(HORSERACE_SUPPORT) )
void SendMessagesTwoToMMI(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
	send_ilm = allocate_ilm(MOD_CUSTOM2);
	if( send_ilm == NULL)
	{
		times ++ ;
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM2;
   send_ilm->dest_mod_id = MOD_MMI ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesTwoToTwo(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
	send_ilm = allocate_ilm(MOD_CUSTOM2);
	if( send_ilm == NULL)
	{
		times ++ ;
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_CUSTOM2;
   send_ilm->dest_mod_id = MOD_CUSTOM2 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}

void SendMessagesMMIToTwo(msg_type MSG_ID )
{
   ilm_struct *send_ilm = NULL ;
   int times = 0 ;
   while(send_ilm == NULL)
   {
	   send_ilm = allocate_ilm(MOD_MMI);
	if( send_ilm == NULL)
	{
		times ++ ;
		if( times > 10)
			return;
		kal_sleep_task(10);
	}
   }
   send_ilm->src_mod_id = MOD_MMI;
   send_ilm->dest_mod_id = MOD_CUSTOM2 ;
   send_ilm->msg_id = MSG_ID;
   msg_send_ext_queue(send_ilm);
}
#endif



kal_bool
custom1_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom1_handler_info =
   {
      custom1_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom1_handler_info;
   return KAL_TRUE;
}

extern int GSensorInitedFlag ;
extern int GetDirection(void);
extern int SleepAtIdleScreen(void);
extern void SetGSensorSleepMode(unsigned char  Mode) ;


static void
custom1_main(task_entry_struct * task_entry_ptr)
{
    int direction = 0 ;
    ilm_struct current_ilm; 
    kal_uint32 my_index;
	
    static int FlagWork = 0;	

    //kal_get_my_task_index(&my_index);
	
    while ( 1 ) 
    { 
	     direction = 0 ;
	     receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm); 
	     //stack_set_active_module_id(my_index, current_ilm.dest_mod_id);	 
#if (defined(G_SENSOR_SUPPORT) ) 	     
#ifndef WIN32	 
	     switch (current_ilm.msg_id)
	     {
	     	      case MSG_ID_GSENSOR_ON:
				 if( FlagWork == 0)
				{
					FlagWork = 1 ;
					SetGSensorSleepMode(FlagWork);
				  	if (  GSensorInitedFlag == 1  )
					{
						SendMessagesOneToOne(MSG_ID_GSENSOR_WORK);
		     	      		}		  		
				}
			  	break;
	             case MSG_ID_GSENSOR_WORK:				
				if( FlagWork == 1 )
				{
					if (  GSensorInitedFlag == 1  )
					{
					   	direction= GetDirection();				
						if( direction == 1)
						{
							SendMessagesOneToMMI(MSG_ID_GSENSOR_RIGHT);	
						}
						else if ( direction == 2)
						{
							SendMessagesOneToMMI(MSG_ID_GSENSOR_LEFT);					
						}
					}		

					if( SleepAtIdleScreen() != 1)
					{
						SendMessagesOneToOne(MSG_ID_GSENSOR_WORK);
					}
				}
				break;
			case MSG_ID_GSENSOR_OFF:
				 {
				 	FlagWork = 0 ;	
				 	SetGSensorSleepMode(FlagWork);
				}			
				break;
			default:
		       	  break;
	      }
#endif		 
#endif		 
    		free_ilm(&current_ilm); 
		kal_sleep_task(15);
    }		
}


/*************************************************************************
* FUNCTION
*  custom2_create
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool
custom2_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct custom2_handler_info =
   {
      custom2_main,  /* task entry function */
      NULL,  /* task initialization function */
      NULL,  /* task configuration function */
      NULL,  /* task reset handler */
      NULL,  /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&custom2_handler_info;
   return KAL_TRUE;
}


extern void HorseRaceThreadTask(void);
extern int  HorseRaceThreadTaskFlag(void);
extern int HorseRaceInitedFlag  ;

static void
custom2_main(task_entry_struct * task_entry_ptr)
{

	int flag = 0 ;
	ilm_struct current_ilm;
	kal_uint32 my_index;
	static int FlagWork = 0;

	//kal_get_my_task_index(&my_index);
   
	while ( 1 ) 
	{
	 
		receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
		//stack_set_active_module_id(my_index, current_ilm.dest_mod_id);	 

#if (defined(HORSERACE_SUPPORT) )		   
#ifndef WIN32
		switch (current_ilm.msg_id)
		{
			case MSG_ID_HORSERACE_ON:
				if( FlagWork == 0)
				{
					if (  HorseRaceInitedFlag == 1  )
					{
						FlagWork = 1 ;		
						SendMessagesTwoToTwo(MSG_ID_HORSERACE_WORK);						
					}
				}
				break;
			case MSG_ID_HORSERACE_WORK:				
				if(FlagWork == 1)
				{
					if (  HorseRaceInitedFlag == 1  )
					{ 
						flag = HorseRaceThreadTaskFlag() ;
						if( flag == 1 )
						{
							HorseRaceThreadTask();
						}
					}
					SendMessagesTwoToTwo(MSG_ID_HORSERACE_WORK);
				}
				break;
			case MSG_ID_HORSERACE_OFF:
				{
					FlagWork = 0 ;				 
				 	//Make Sure Power Off State
					if (  HorseRaceInitedFlag == 1  )
					{ 
						HorseRaceThreadTask();
					}
				}
				break;
			default:
				break;
		}	  
#endif		
#endif		
		free_ilm(&current_ilm); 	
		kal_sleep_task(800);
	}      
}

