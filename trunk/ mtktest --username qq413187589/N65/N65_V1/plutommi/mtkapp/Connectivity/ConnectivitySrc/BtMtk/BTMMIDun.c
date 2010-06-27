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
 * BTMMIDUN.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for dun application.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_BT_MTK_SUPPORT__
#ifdef __MMI_DUN_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"  
#include "gpioInc.h"  

/* MMI Nvram access */

/* Trace Header Files */


/*Call Management related API */
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"

/* MMI BT profile related files */
#include "ProfilesDefs.h"
#include "ProfileGprots.h"

/*External Device Header Files*/
#include "ExtDeviceDefs.h"
#include "BTMMICm.h"

/* HFP */
#include "bt_dm_struct.h"
#include "bluetooth_struct.h"
#include "BTMMIDun.h"
#include "BTMMIDunGprots.h"

#include "bluetooth_bm_struct.h"
#include "btbm_adp.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern U8 *BTBMGetLocalStoredName(U8 *bdAddr);
extern void mmi_bth_activate_cnf_hdler(U32 profile_id);
extern void mmi_bth_deactivate_cnf_hdler(U32 profile_id);
extern void mmi_bth_connect_cnf_hdler(
                MMI_BOOL result,
                U32 lap,
                U8 uap,
                U16 nap,
                U8 *name_p /* utf8 encoding */ ,
                U32 profile_id,
                U32 connection_id);

extern void mmi_bth_connect_ind_hdler(
                U32 lap,
                U8 uap,
                U16 nap,
                U8 *name_p /* utf8 encoding */ ,
                U32 profile_id,
                U32 connection_id);
extern void mmi_bth_disconnect_cnf_hdler(MMI_BOOL result, U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id);
extern void mmi_bth_disconnect_ind_hdler(U32 lap, U8 uap, U16 nap, U32 profile_id, U32 connection_id);



/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_dun_cntx_struct g_mmi_dun_cntx;

/***************************************************************************** 
* Function
*****************************************************************************/
/*****************************************************************************
* FUNCTION
*	mmi_bth_dun_init
* DESCRIPTION
*	 This function is to
*
* PARAMETERS
*	a	IN/OUT		first variable, used as returns
*	b	IN 		second variable
* RETURNS
*	NONE.
* GLOBALS AFFECTED
*	 external_global
*****************************************************************************/
void 		mmi_bth_dun_init(void)
{
	mmi_bth_init_dun_event_handler();
	g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_IDLE;
	g_mmi_dun_cntx.connect_id = 0;
	g_mmi_dun_cntx.port = 0;
	g_mmi_dun_cntx.lap = 0;
	g_mmi_dun_cntx.uap = 0;
	g_mmi_dun_cntx.nap = 0;
	
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_init_event_handler
* DESCRIPTION
*   This function is to
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_init_dun_event_handler(void)
{
  	MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_INIT_EVENT_HDLR );

    /* Init protocol event handler */
     SetProtocolEventHandler(mmi_bth_dun_activate_cnf_hdler, MSG_ID_BT_DUN_ACTIVATE_CNF);
     SetProtocolEventHandler(mmi_bth_dun_deactivate_cnf_hdler, MSG_ID_BT_DUN_DEACTIVATE_CNF);
     SetProtocolEventHandler(mmi_bth_dun_disconnect_cnf_hdler, MSG_ID_BT_DUN_DISCONNECT_CNF);
     SetProtocolEventHandler(mmi_bth_dun_connect_ind_hdler, MSG_ID_BT_DUN_CONNECT_IND);
     SetProtocolEventHandler(mmi_bth_dun_disconnect_ind_hdler, MSG_ID_BT_DUN_DISCONNECT_IND);

    

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_activate_req_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_activate_req_hdler(void)
{
	mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_ACTIVATE_REQ, NULL, NULL);
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_activate_cnf_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_activate_cnf_hdler(void *msg)
{
    mmi_bth_activate_cnf_hdler((U32)MMI_BTH_DUN_PROFILE_UUID);
    g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_ACTIVATE;
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_deactivate_req_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_deactivate_req_hdler(void)
{
	mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_DEACTIVATE_REQ, NULL, NULL);
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_deactivate_cnf_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_deactivate_cnf_hdler(void *msg)
{
    mmi_bth_deactivate_cnf_hdler((U32)MMI_BTH_DUN_PROFILE_UUID);
    g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_IDLE;
    g_mmi_dun_cntx.connect_id = 0;
    g_mmi_dun_cntx.port = 0;
    g_mmi_dun_cntx.lap = 0;
    g_mmi_dun_cntx.uap = 0;
    g_mmi_dun_cntx.nap = 0;

}


/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_connect_ind_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_connect_ind_hdler(void *msg)
{
       kal_uint8 bd_addr[6];
	kal_uint8* name = NULL;
	
	bt_dun_connect_ind_struct *msg_p = (bt_dun_connect_ind_struct *)msg;
       
	g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_CONNECT;
	g_mmi_dun_cntx.connect_id = msg_p->cid;
	g_mmi_dun_cntx.port = msg_p->port;
	g_mmi_dun_cntx.lap = msg_p->lap;
	g_mmi_dun_cntx.uap = msg_p->uap;
	g_mmi_dun_cntx.nap = msg_p->nap;


	CONVERT_BDADDR2ARRAY(bd_addr, msg_p->lap, msg_p->uap, msg_p->nap);
	name = BTBMGetLocalStoredName(bd_addr);
       //PRINT_INFORMATION("mmi_bth_spp_connect_ind_hdler(): get device name=%s",name);
       

	/* inform CM connect result */
	mmi_bth_connect_ind_hdler(  
		msg_p->lap,
		msg_p->uap,
		msg_p->nap,
		name,
		MMI_BTH_DUN_PROFILE_UUID,
		msg_p->cid);
	/* callback user profiles */

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_disconnect_req_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void        mmi_bth_dun_disconnect_req_hdler(mmi_bth_bt_addr device_addr, U32 connect_id)
{
	bt_dun_disconnect_req_struct* msg_p;
	
	msg_p = (bt_dun_disconnect_req_struct*)
		construct_local_para(sizeof(bt_dun_disconnect_req_struct), TD_CTRL);
	msg_p->port = g_mmi_dun_cntx.port;
	
	mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_DISCONNECT_REQ, msg_p, NULL);
	
	g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_DISCONNECT;

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_disconnect_cnf_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_disconnect_cnf_hdler(void *msg)
{
	   mmi_bth_disconnect_cnf_hdler(KAL_TRUE, 
											   g_mmi_dun_cntx.lap,
											   g_mmi_dun_cntx.uap,
											   g_mmi_dun_cntx.nap, 
											   MMI_BTH_DUN_PROFILE_UUID, 
											   g_mmi_dun_cntx.connect_id);
	   
	g_mmi_dun_cntx.connect_id = 0;
	g_mmi_dun_cntx.port = 0;
	g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_ACTIVATE;
	g_mmi_dun_cntx.lap = 0;
	g_mmi_dun_cntx.uap = 0;
	g_mmi_dun_cntx.nap = 0;
	
	//mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_ACTIVATE_REQ, NULL, NULL);

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_dun_disconnect_ind_hdler
* DESCRIPTION
*   This function is to 
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_dun_disconnect_ind_hdler(void *msg)
{

    bt_dun_disconnect_ind_struct *msg_p = (bt_dun_disconnect_ind_struct *)msg;

	     if(msg_p->port == g_mmi_dun_cntx.port)
	     {

                if(g_mmi_dun_cntx.state == MMI_BTH_DUN_STAT_DISCONNECT)
                {
                    mmi_bth_disconnect_cnf_hdler(
                       KAL_TRUE,    
	                g_mmi_dun_cntx.lap,
	                g_mmi_dun_cntx.uap,
	                g_mmi_dun_cntx.nap,
	                MMI_BTH_DUN_PROFILE_UUID,
	                g_mmi_dun_cntx.connect_id);
                }
                else
                mmi_bth_disconnect_ind_hdler(  
	             g_mmi_dun_cntx.lap,
	             g_mmi_dun_cntx.uap,
	             g_mmi_dun_cntx.nap,
	             MMI_BTH_DUN_PROFILE_UUID,
	             g_mmi_dun_cntx.connect_id);
				
                g_mmi_dun_cntx.connect_id = 0;
	         g_mmi_dun_cntx.port = 0;
	         g_mmi_dun_cntx.state = MMI_BTH_DUN_STAT_ACTIVATE;
	         g_mmi_dun_cntx.lap = 0;
	         g_mmi_dun_cntx.uap = 0;
	         g_mmi_dun_cntx.nap = 0;
	     }
		 


}




#endif //__MMI_DUN_SUPPORT__
#endif //__MMI_BT_MTK_SUPPORT__

