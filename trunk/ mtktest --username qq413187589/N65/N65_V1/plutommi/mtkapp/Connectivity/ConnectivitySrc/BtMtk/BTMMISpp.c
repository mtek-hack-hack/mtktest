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
 * BTMMISPP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for SPP application.
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
#ifdef __MMI_SPP_SUPPORT__
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
#include "BTMMISpp.h"
#include "BTMMISppGprots.h"

#include "bluetooth_bm_struct.h"
#include "btbm_adp.h"

//Add by mtk01411: 2007-0401
#include "uart_sw.h"


/***************************************************************************** 
* External Variable
*****************************************************************************/

extern void mmi_gis_gps_sdp_result_ind_callback(kal_uint8 srv_chnl_num);
extern void mmi_gis_gps_sdp_search_cnf_callback(kal_uint8 result);
extern void mmi_gis_gps_connect_cnf_callback(U8 result,U8 server_chnl_num,U8 con_id,U16 port,mmi_bth_bt_addr bd_addr);
extern void mmi_gis_gps_uart_owner_ind_callback(U16 port);
extern void mmi_gis_gps_uart_ready_to_read_ind_callback(U16 port);
extern void mmi_gis_gps_uart_ready_to_write_ind_callback(U16 port);
extern void mmi_gis_gps_uart_plugout_ind_callback(U16 port);
extern void mmi_gis_gps_disconnect_ind_callback(void);
extern void mmi_gis_gps_disconnect_cnf_callback(kal_bool result);
#ifdef __MMI_SPP_SCO_SUPPORT__
extern void mmi_gis_gps_audio_connect_cnf_callback(kal_uint8 result, kal_uint16 port);
extern void mmi_gis_gps_audio_connect_ind_callback(kal_uint16 port);
extern void mmi_gis_gps_audio_disconnect_cnf_callback(kal_uint8 result, kal_uint16 port);
extern void mmi_gis_gps_audio_disconnect_ind_callback(kal_uint16 port);
#endif

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

//Define in bt_adp_spp.c : Add by mtk01411 2007-0401
kal_bool IsThisPortAsSPPServer(UART_PORT port);
extern module_type UART_GetOwnerID(UART_PORT port);
extern kal_uint8* BtGet_SPPClientFirstConnDataPattern(kal_uint8* len);


/* Define in bt_adp_spp.c : For Testing usage */
extern kal_uint8 MMI_SPP_SCO_SDP_PROCESS_HDLER_SET;
extern btbm_bd_addr_t MMI_SPP_SCO_CON_REQ_ADDR;
extern kal_uint8 MMI_SPP_SDP_ATD_TYPE;
extern kal_uint8 MMI_SPP_CHNL_ALWAYS_DISC_FIRST;

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
mmi_spp_cntx_struct g_mmi_spp_cntx[MMI_BTH_SPP_MAX_CONNECTION];


mmi_spp_client_sdap_cntx_struct g_mmi_spp_sdap_cntx[MMI_BTH_SPP_CLIENT_SDAP_MAX_CONNECTION];
U8  mmi_bth_spp_sdp_operation_status;
U8  mmi_bth_spp_connect_operation_status;
U8  mmi_bth_current_spp_client_num;
U16 mmi_bth_connected_port_num;
U8 current_sppclientapp_table_inx;
U8 current_sppserverapp_table_inx;


#ifdef __MMI_SPP_SCO_SUPPORT__
U8  mmi_bth_spp_audio_connect_operation_status;
U8  mmi_bth_spp_audio_disconnect_operation_status;
#endif


/*Note that: NUM_SPP_CLIENTS is reference from bt_common_config.h
  *And this value is dependent on the make file's VIRTUAL_PORTS_NUM
  * 
  *[Rule] The maximum number of SPP Clients and Servers could be equal to (VIRTUAL_PORTS_NUM - 3)
  */
RegisteredClientFuncSet SPPClientAppTable[NUM_SPP_CLIENTS]=
{
#ifdef __MMI_GPS__
    /* First SPP Client Application Func Set */
    {
        mmi_gis_gps_sdp_search_cnf_callback,                
        mmi_gis_gps_sdp_result_ind_callback,                    
        mmi_gis_gps_connect_cnf_callback,                     
        mmi_gis_gps_uart_owner_ind_callback,                
        mmi_gis_gps_uart_ready_to_read_ind_callback,    
        mmi_gis_gps_uart_ready_to_write_ind_callback,   
        mmi_gis_gps_uart_plugout_ind_callback,              
        mmi_gis_gps_disconnect_ind_callback,                 
        mmi_gis_gps_disconnect_cnf_callback,                 
#ifdef __MMI_SPP_SCO_SUPPORT__
        mmi_gis_gps_audio_connect_cnf_callback,           
        mmi_gis_gps_audio_connect_ind_callback,           
        mmi_gis_gps_audio_disconnect_cnf_callback,       
        mmi_gis_gps_audio_disconnect_ind_callback,       
#endif        
        FALSE
    }
 
#elif defined (__MMI_SPP_CLIENT_USAGE_DEMO__) /* For Demo usage: SPPClientApp1 callback function */
    {
        SPPClientApp1_SDP_Search_Cnf_CB, 
        SPPClientApp1_SDP_Result_Ind_CB,   
        SPPClientApp1_Connect_Cnf_CB,
        SPPClientApp1_Uart_Owner_Ind_CB,
        SPPClientApp1_Uart_Ready_To_Read_Ind_CB,
        SPPClientApp1_Uart_Ready_To_Write_Ind_CB,
        SPPClientApp1_Uart_Plugout_Ind_CB,
        SPPClientApp1_Disconnect_Ind_CB,
        SPPClientApp1_Disconnect_Cnf_CB,
#ifdef __MMI_SPP_SCO_SUPPORT__
        SPPClientApp1_Audio_Connect_Cnf_CB,
        SPPClientApp1_Audio_Connect_Ind_CB,
        SPPClientApp1_Audio_Disconnect_Cnf_CB,
        SPPClientApp1_Audio_Disconnect_Ind_CB,
#endif        
        FALSE
    }
#else
		{
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
			NULL,
#ifdef __MMI_SPP_SCO_SUPPORT__
        NULL,
        NULL,
        NULL,
        NULL,
#endif        
        FALSE			
		} 
#endif /* end #ifdef __MMI_GPS__ */    
    /* Second SPP Client Application Func Set */
};


 /* All SPP Server services (including SPP_SCO Server if SPP_SCO_SERVER is enabled) occupies the port range from (start_of_virtual_port) to (start_of_virtual_port + NUM_SPP_SERVERS-1)
   * Because the SPP_SCO_Serivce uses the port number : start_of_virtual_port + NUM_SPP_SERVER-1
   * From (start_of_virtual_port)  to (start_of_virtual_port + NUM_SPP_SERVERS-2): Other General SPP Server Services (i.e., Non_SPP_SCO_SERVER)
   * customer can decide which port is reserved for its application
   *
   * Example: 
   * SPP Game Server Application uses the port start_of_virtual_port,
   * --> it should fill Game Server's callback func sets in this table's entry with start_of_virtual_port
   * 
   * If other general SPP Server is not necessary to change the default uart port owner, it is not necessary to register theis usage port and theirs callback func sets in this table
   * 
   * Example: 
   * NUM_SPP_SERVER = 3, 
   * port = start_of_virtual_port ~ (start_of_virtual_port +1) : are other general spp server and 
   * port = start_of_virtual_port+2 : SPP_SCO_SERVER
   * 
   * 1)The SPP Server port (1st SPP server: start_of_virtual_port): used for Game Server Application
   * 2)The SPP Server port (2nd SPP server: start_of_virtual_port+1): used for Phonesuite (it is not necessary to change default uart port owner), 
   *    so it is not necessary to register its callback func sets in this table. (the data is received/sent via L4C)
   * 3)The SPP Server port (3rd SPP server: start_of_virtual_port+2): used for Chat Room Server Application
   * 4)The SPP SCO Server port (start_of_virtual_port+3): If SPP SCO Server wants to process data (not in L4C), it can register its callback func sets in this table 
   * [Reminder]: If the SPP Server registers its callback func sets in this table:
   *                    When the SPP Client is trying to connect to this SPP Server, the SPP Client must send its the specific pattern string as the first data to Server,
   *                    In this way, the bt stack will transfer uart port owner from L4 to MMI upon receiving its first data which is the specific pattern
   *                    PS: This specific pattern string is defined in custom\common\bt_commom_config.c, and this pattern is obtained via the function BtGet_SPPClientFirstConnDataPattern()
   */ 
RegisteredServerFuncSet SPPServerAppTable[NUM_SPP_SERVERS]=
{
    /* SPP_SCO Server needs to process uart data by itself instead of MMI, registers its callback func sets in table. */
#ifdef __MMI_SPP_CLIENT_USAGE_DEMO__
    {
        start_of_virtual_port + NUM_SPP_SERVERS -1,
        SPPServerApp1_Connect_Ind_CB,    
        SPPServerApp1_Uart_Owner_Ind_CB,
        SPPServerApp1_Uart_Ready_To_Read_Ind_CB,
        SPPServerApp1_Uart_Ready_To_Write_Ind_CB,
        SPPServerApp1_Uart_Plugout_Ind_CB,
        SPPServerApp1_Disconnect_Ind_CB
#ifdef __MMI_SPP_SCO_SUPPORT__
        ,
        SPPServerApp1_Audio_Connect_Cnf_CB,
        SPPServerApp1_Audio_Connect_Ind_CB,
        SPPServerApp1_Audio_Disconnect_Cnf_CB,
        SPPServerApp1_Audio_Disconnect_Ind_CB
#endif       
    }
#else
    /* IN THIS AREA, THE ACTUAL SERVER APP. CALLBACK FUNCTION SET MUST BE FILLED 
      * LIKE THE ABOVE EXAMPLE FOR DEMO USAGE (SPPServerApp1_xxx functions)
      * PLEASE FILL WITH THE FOLLOWING NULL AS THE ACTUAL CALLNACK FUNC
      */
    {  
        start_of_virtual_port + NUM_SPP_SERVERS -1,
        NULL,    
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
#ifdef __MMI_SPP_SCO_SUPPORT__
        ,
        NULL,
        NULL,
        NULL,
        NULL
#endif       
    }
#endif /* end #ifdef __MMI_SPP_CLIENT_USAGE_DEMO__ */
#if (NUM_SPP_SERVERS >1)
    , /* comma, following is 2nd entry of this table */
    
    /* Game Server Application */
    {
        start_of_virtual_port + NUM_SPP_SERVERS -2, 
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
#ifdef __MMI_SPP_SCO_SUPPORT__
        ,
        NULL,
        NULL,
        NULL,
        NULL
#endif       

    }
#endif

};


/***************************************************************************** 
* Function
*****************************************************************************/
static U8 mmi_bth_spp_general_sdp_query_request(U8 attribute_type,U8 app_inx, mmi_bth_bt_addr bd_addr);
U8 mmi_bth_spp_connect_req(U8 app_inx, mmi_bth_spp_connect_type_enum connection_type, mmi_bth_bt_addr bd_addr,S8 server_channel_num);
#ifdef __MMI_SPP_SCO_SUPPORT__
U8 mmi_bth_spp_audio_connect_req(U16 port);
U8 mmi_bth_spp_audio_disconnect_req(U16 port);
#endif

/*****************************************************************************
* FUNCTION
*	mmi_bth_spp_init
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
void    mmi_bth_spp_init(void)
{
    kal_int8 i = 0;
    mmi_bth_spp_sdp_operation_status = MMI_BTH_SPP_SDP_PROCESS_NONE;
    mmi_bth_spp_connect_operation_status = MMI_BTH_SPP_CONNECT_PROCESS_NONE;
    mmi_bth_connected_port_num = 0xFFFF;
#if 0
#ifdef  __MMI_SPP_SCO_SUPPORT__ 
/* under construction !*/
/* under construction !*/
#endif
#endif

    mmi_bth_current_spp_client_num =0;
    mmi_bth_init_spp_event_handler();

    
    for(i = 0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        g_mmi_spp_cntx[i].state = MMI_BTH_SPP_STAT_IDLE;
        g_mmi_spp_cntx[i].connect_id = 0;
        g_mmi_spp_cntx[i].port = 0;
        g_mmi_spp_cntx[i].lap = 0;
        g_mmi_spp_cntx[i].uap = 0;
        g_mmi_spp_cntx[i].nap = 0;
        g_mmi_spp_cntx[i].server_chnl_num = (S8)-1; /* -1 is default value */

#ifdef __MMI_SPP_SCO_SUPPORT__       
        /* SPP_SCO feature only */
        g_mmi_spp_cntx[i].audio_state = MMI_BTH_SPP_STAT_AUDIO_IDLE;
#endif
        g_mmi_spp_cntx[i].app_inx = 0;

    }
}

/* Add by mtk01411: 2007-0707 */
mmi_spp_cntx_struct* mmi_bth_spp_find_available_entry(void)
{
    int i=0;
    for(i=0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        /* Note: if state is MMI_BTH_SPP_STAT_ACTIVATE, but audio_state is not MMI_BTH_SPP_STAT_AUDIO_IDLE:
          * This means that: SPP Connection is disconnected, but SCO link is still connected
          * So this entry is still used, not an available entry!
          */
        if((g_mmi_spp_cntx[i].state == MMI_BTH_SPP_STAT_ACTIVATE)
 #ifdef __MMI_SPP_SCO_SUPPORT__           
           && (g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_IDLE)
 #endif          
           )
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_AVAILABLE_ENTRY_INX,i);
            return &g_mmi_spp_cntx[i];
        }
    }
    return NULL;    
}

/* Add by mtk01411: 2007-0707 */
mmi_spp_cntx_struct* mmi_bth_spp_find_entry_by_connect_type(mmi_bth_spp_state_enum state, mmi_bth_bt_addr bd_addr,S8 server_channel_num)
{
    int i=0;
    for(i=0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        if(g_mmi_spp_cntx[i].state == state)
        {
            if((g_mmi_spp_cntx[i].lap == bd_addr.lap) 
                && (g_mmi_spp_cntx[i].nap == bd_addr.nap)
                && (g_mmi_spp_cntx[i].uap == bd_addr.uap)
                && (g_mmi_spp_cntx[i].server_chnl_num == server_channel_num)
                )
            {
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_CONNECT_TYPE_INX,i);
                return &g_mmi_spp_cntx[i];
            }
            else if((g_mmi_spp_cntx[i].lap == bd_addr.lap)
                        && (g_mmi_spp_cntx[i].nap == bd_addr.nap)
                        && (g_mmi_spp_cntx[i].uap == bd_addr.uap)
                        && (server_channel_num == 0)
                      )
            {
                MMI_BT_ASSERT(0);
            }
                        
        }   
    }
    return NULL;
}


#ifdef __MMI_SPP_SCO_SUPPORT__
/* Add by mtk01411: 2007-0710 */
mmi_spp_cntx_struct* mmi_bth_spp_find_existing_sco_entry(mmi_bth_bt_addr bd_addr, S8 srv_chnl_num, U16 port)
{
    int i=0;
    for(i=0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        if((g_mmi_spp_cntx[i].state == MMI_BTH_SPP_STAT_ACTIVATE)
            && (g_mmi_spp_cntx[i].audio_state== MMI_BTH_SPP_STAT_AUDIO_CONNECTED)          
          )
        {
            /* This entry is RFCOMM channel is closed, but its corresponding SCO link is still alive */

            if(srv_chnl_num != -1)
            {
                /* Check bd_address and srv_chnnl_num: in the case of connection request */
                if((g_mmi_spp_cntx[i].lap == bd_addr.lap) 
                    && (g_mmi_spp_cntx[i].nap == bd_addr.nap)
                    && (g_mmi_spp_cntx[i].uap == bd_addr.uap)
                    && (g_mmi_spp_cntx[i].server_chnl_num == srv_chnl_num)
                )

                {
                    /*2007-0715:  The server channel num must be check, too. 
                      * It must be sure the srv_chnl_num whic SPPClient Application wants to connect is that one supported SCO functionality.
                      * Ex: If ths SPPClient App. just wants to connect to the remote device's general SPP Server(i.e., Non-SPP SCO Server),
                      *       in this situation, an new available entry should be allocated for this connection instead of an existing SCO entry due to same bd address!!
                      */
                    /* Reset this entry's context  for reuse again */
                    g_mmi_spp_cntx[i].port = 0;
                    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_EXISTING_SCO_ENTRY_INX,i);
                    return &g_mmi_spp_cntx[i];
                }
            }
            else
            {
                /* In this case: The SPPSever Application receives an incomming connected_ind */
                if((g_mmi_spp_cntx[i].lap == bd_addr.lap) 
                    && (g_mmi_spp_cntx[i].nap == bd_addr.nap)
                    && (g_mmi_spp_cntx[i].uap == bd_addr.uap)
                    && (g_mmi_spp_cntx[i].port == port)
                )

                {
                    /*2007-0715:  The port must be check, too. 
                      * It must be sure the port is that one supported SCO functionality.
                      * Ex: If ths SPPClient App. just wants to connect to the remote device's general SPP Server(i.e., Non-SPP SCO Server),
                      *       in this situation, an new available entry should be allocated for this connection instead of an existing SCO entry due to same bd address!!
                      */
                    /* Reset this entry's context  for reuse again */
                    g_mmi_spp_cntx[i].port = 0;
                    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_EXISTING_SCO_ENTRY_INX,i);
                    return &g_mmi_spp_cntx[i];
                }

            }

        }
    }
    return NULL;
}
#endif


/* Add by mtk01411: 2007-0709 */
mmi_spp_cntx_struct* mmi_bth_spp_find_entry_by_port(U16 port)
{
    int i=0;
    for(i=0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        if(g_mmi_spp_cntx[i].port == port)
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT_INX,i);
            return &g_mmi_spp_cntx[i];
        }   
    }
    return NULL;

}

/* Add by mtk01411: 2007-0722 */
U16 mmi_bth_spp_find_port_by_srvchnlnum(mmi_bth_bt_addr addr, S8 srv_chnl_num)
{
    int i=0;
    for (i=0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        if( (g_mmi_spp_cntx[i].server_chnl_num == srv_chnl_num)

            && (g_mmi_spp_cntx[i].lap == addr.lap)
            && (g_mmi_spp_cntx[i].uap == addr.uap)
            && (g_mmi_spp_cntx[i].nap == addr.nap)
          )
            return g_mmi_spp_cntx[i].port;
    }
    return 0xFFFF;
}

/* Add by mtk01411: 2007-0711 */
kal_int8 search_inx_of_spp_server_app_registerfunc_table(U16 port)
{
    kal_int8 i=0;
    for(i=0; i < NUM_SPP_SERVERS; i++)
    {
        if(port == SPPServerAppTable[i].service_registered_port)
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SEARCH_SPPSRVAPPTABLE_BY_PORT_INX,i);
            return i;
        }
    }
    return -1;
}

/* Add by mtk01411: 2007-0717 */
void mmi_bth_reset_spp_entry(kal_uint8 inx)
{
    g_mmi_spp_cntx[inx].server_chnl_num = (S8)-1; /* -1 is the default value */
    g_mmi_spp_cntx[inx].app_inx = 0;
    g_mmi_spp_cntx[inx].connect_id = 0;
    g_mmi_spp_cntx[inx].port = 0;
    g_mmi_spp_cntx[inx].lap = 0;
    g_mmi_spp_cntx[inx].uap = 0;
    g_mmi_spp_cntx[inx].nap = 0;
    g_mmi_spp_cntx[inx].state = MMI_BTH_SPP_STAT_ACTIVATE;
#ifdef __MMI_SPP_SCO_SUPPORT__    
    g_mmi_spp_cntx[inx].audio_state = MMI_BTH_SPP_STAT_AUDIO_IDLE;
#endif

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
void mmi_bth_init_spp_event_handler(void)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_BT_G7_INIT_EVENT_HDLR );

    /* Init protocol event handler */
    SetProtocolEventHandler(mmi_bth_spp_activate_cnf_hdler, MSG_ID_BT_SPP_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_spp_deactivate_cnf_hdler, MSG_ID_BT_SPP_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_bth_spp_disconnect_cnf_hdler, MSG_ID_BT_SPP_DISCONNECT_CNF);
    SetProtocolEventHandler(mmi_bth_spp_connect_ind_hdler, MSG_ID_BT_SPP_CONNECT_IND);
    SetProtocolEventHandler(mmi_bth_spp_disconnect_ind_hdler, MSG_ID_BT_SPP_DISCONNECT_IND);
    /* Add: 2007-0112 : for upper layer to determine accept this SPP connection or nor */
    SetProtocolEventHandler(mmi_bth_spp_authroize_hdler, MSG_ID_BT_SPP_AUTH_REQ);  


    SetProtocolEventHandler(mmi_bth_spp_sdp_attribute_search_result_ind_hdler, MSG_ID_BT_BM_SEARCH_ATTRIBUT_RESULT_IND);  
    SetProtocolEventHandler(mmi_bth_spp_sdp_attribute_search_cnf_hdler, MSG_ID_BT_BM_SEARCH_ATTRIBUTE_CNF);  
#if 0
/* under construction !*/
/* under construction !*/
#endif

    /* Add: 2007-0326 : for SPP client test */	 
    SetProtocolEventHandler(mmi_bth_spp_connect_cnf_hdler, MSG_ID_BT_SPP_CONNECT_CNF); 

    /* Add: 2007-0401: for SPP client test: Simulate MMI receives the msg MSG_ID_BT_MMI_UART_OWNER_IND */
    SetProtocolEventHandler(mmi_bth_spp_uart_owner_ind_hdler,MSG_ID_BT_SPP_UART_OWNER_IND);
    SetProtocolEventHandler(mmi_bth_spp_uart_readyToRead_ind_hdler,MSG_ID_UART_READY_TO_READ_IND);
    SetProtocolEventHandler(mmi_bth_spp_uart_readyToWrite_ind_hdler,MSG_ID_UART_READY_TO_WRITE_IND);
    /* Add: 2007-0409 : to process UART_PLUGOUT_IND */
    SetProtocolEventHandler(mmi_bth_spp_uart_plugout_ind_hdler,MSG_ID_UART_PLUGOUT_IND);
     
#ifdef __MMI_SPP_SCO_SUPPORT__
    /* Add: 2007-0709 Set SPP SCO related event handler */
    SetProtocolEventHandler(mmi_bth_spp_audio_connect_cnf_hdler,MSG_ID_BT_SPP_AUDIO_CONNECT_CNF);    
    SetProtocolEventHandler(mmi_bth_spp_audio_connect_ind_hdler,MSG_ID_BT_SPP_AUDIO_CONNECT_IND);    
    SetProtocolEventHandler(mmi_bth_spp_audio_disconnect_cnf_hdler,MSG_ID_BT_SPP_AUDIO_DISCONNECT_CNF);    
    SetProtocolEventHandler(mmi_bth_spp_audio_disconnect_ind_hdler,MSG_ID_BT_SPP_AUDIO_DISCONNECT_IND);  
#endif
#if defined (__MMI_SPP_CLIENT_USAGE_DEMO__) && defined(__MMI_SPP_SCO_SUPPORT__)
    SetProtocolEventHandler(mmi_bth_spp_sco_rssi_ind_hdler,MSG_ID_BT_SPP_SCO_RSSI_IND);
#endif
}

#ifdef __MMI_SPP_CLIENT_USAGE_DEMO__
void BT_SPP_Client_Test(void)
{
    bt_bm_search_attribute_req_struct * btbm_adp_msg = NULL;
    btbm_bd_addr_t bd_addr_t;
    OS_MemSet((U8*)(&bd_addr_t), 0, sizeof(bd_addr_t));
    
    bd_addr_t.lap = MMI_SPP_SCO_CON_REQ_ADDR.lap;
    bd_addr_t.uap = MMI_SPP_SCO_CON_REQ_ADDR.uap;
    bd_addr_t.nap = MMI_SPP_SCO_CON_REQ_ADDR.nap;  
    
    btbm_adp_msg = (bt_bm_search_attribute_req_struct *)
    construct_local_para(sizeof(bt_bm_search_attribute_req_struct),TD_UL);
        OS_MemCopy((U8*)(&btbm_adp_msg->bd_addr), (U8*)(&bd_addr_t), sizeof(bd_addr_t));
    
    btbm_adp_msg->sdap_uuid = 0x00001101; /* 0x1101: SPP UUID */
   
    if(MMI_SPP_SDP_ATD_TYPE == 0)
        btbm_adp_msg->attribute_id = MMI_BTH_SDP_AID_PROTOCOL_DESC_LIST;

#ifdef __MMI_SPP_SCO_SUPPORT__    
    else if(MMI_SPP_SDP_ATD_TYPE == 1)
        btbm_adp_msg->attribute_id = MMI_BTH_SDP_AID_SUPPORTED_CAPABILITIES; /* Support Capabilities */
#endif
    PRINT_INFORMATION("MMI_SPP_SDP_ATD_TYPE=%d, attribute_id=%04X",MMI_SPP_SDP_ATD_TYPE,btbm_adp_msg->attribute_id);
#if 0
/* under construction !*/
/* under construction !*/
#endif
    /* Determine SDP event Process handler : For SPP Client Application usage */
    if(MMI_SPP_SCO_SDP_PROCESS_HDLER_SET == 0)
    {
        SetProtocolEventHandler(mmi_bth_spp_sdp_attribute_search_result_ind_hdler, MSG_ID_BT_BM_SEARCH_ATTRIBUT_RESULT_IND);  
        SetProtocolEventHandler(mmi_bth_spp_sdp_attribute_search_cnf_hdler, MSG_ID_BT_BM_SEARCH_ATTRIBUTE_CNF);  

        if(mmi_bth_spp_sdp_operation_status == MMI_BTH_SPP_SDP_PROCESS_NONE)
            /*mmi_bth_spp_sdp_operation_status = MMI_BTH_SPP_SDP_ONGOING;*/
            mmi_bth_spp_sdp_operation_status = 0 + 1; /* app_inx = 0 */
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_SDP_REQUEST_ONGOING_APP_INX, mmi_bth_spp_sdp_operation_status-1);
            
        }

    }
    else if(MMI_SPP_SCO_SDP_PROCESS_HDLER_SET == 1)    
    {
        /* Determine SDP event Process handler : For Testing usage */
        SetProtocolEventHandler(mmi_bth_spp_service_attribute_ind_hdler,MSG_ID_BT_BM_SEARCH_ATTRIBUT_RESULT_IND);
        SetProtocolEventHandler(mmi_bth_spp_service_attribute_result_hdler,MSG_ID_BT_BM_SEARCH_ATTRIBUTE_CNF); 
    }
    
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_SEARCH_ATTRIBUTE_REQ, (local_para_struct*)btbm_adp_msg, NULL);
    g_mmi_spp_sdap_cntx[0].srv_chnl_num_no = 0;
}

/* Idle Screen: Press *#905#  */
void BT_SPECIAL_TEST(void)
{
    BT_SPP_Client_Test();
}

/* SPP RFCOMM Connecte Request: establish a RFCOMM channel 
  * This function is used with SDP Event Process Handler set 0 (i.e., MMI_SPP_SCO_SDP_PROCESS_HDLER_SET=0)
  * Idle Screen: Press *#909# 
  */
void BT_SPP_CONNECT_REQ_TEST(void)
{
    /* Directly call connect request function */
    mmi_bth_spp_connect_type_enum con_type;
    mmi_bth_bt_addr mmi_bt_addr;
    mmi_bt_addr.lap = 0;
    mmi_bt_addr.lap = MMI_SPP_SCO_CON_REQ_ADDR.lap;
    mmi_bt_addr.uap = 0;
    mmi_bt_addr.uap = MMI_SPP_SCO_CON_REQ_ADDR.uap;
    mmi_bt_addr.nap = 0;
    mmi_bt_addr.nap = MMI_SPP_SCO_CON_REQ_ADDR.nap;

    if(MMI_SPP_SDP_ATD_TYPE == 0)
        /* Ask SDP with AID = ProtocolDescriptorList for general SPP Server */
        con_type = MMI_BTH_SPP_CLIENT_WITHOUT_SCO_REQ; 

#ifdef __MMI_SPP_SCO_SUPPORT__    
    else if(MMI_SPP_SDP_ATD_TYPE == 1)
        /* Ask SDP with AID = Support Capabilities for SPP_SCO Server */
        con_type = MMI_BTH_SPP_CLIENT_WITH_SCO_REQ;  
#endif

    mmi_bth_spp_connect_req(0, con_type, mmi_bt_addr, g_mmi_spp_sdap_cntx[0].srv_chnl_num[0]);
}



/* AUDIO_CONNECT_REQ 
  * Idle Screen: Press *#906#
  */
void BT_SPP_SCO_CONNECT_REQ_TEST(void)
{
    S8 srv_chnl_num = g_mmi_spp_sdap_cntx[0].srv_chnl_num[0] ;
    mmi_bth_bt_addr mmi_btaddr;
    U16 port = 0;
    
    mmi_btaddr.lap = 0;
    mmi_btaddr.lap = MMI_SPP_SCO_CON_REQ_ADDR.lap;
    mmi_btaddr.uap = 0;
    mmi_btaddr.uap = MMI_SPP_SCO_CON_REQ_ADDR.uap;
    mmi_btaddr.nap = 0;
    mmi_btaddr.nap = MMI_SPP_SCO_CON_REQ_ADDR.nap;

#ifdef __MMI_SPP_SCO_SUPPORT__
    if(mmi_bth_connected_port_num!= 0xFFFF)
        mmi_bth_spp_audio_connect_req(mmi_bth_connected_port_num);
#endif

    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

/* AUDIO_DISCONNECT_REQ 
  * Idle Screen: Press *#907#
  */
void BT_SPP_SCO_DISCONNECT_REQ_TEST(void)
{
    S8 srv_chnl_num = g_mmi_spp_sdap_cntx[0].srv_chnl_num[0] ;
    mmi_bth_bt_addr mmi_btaddr;
    U16 port = 0;

    mmi_btaddr.lap = 0;
    mmi_btaddr.lap = MMI_SPP_SCO_CON_REQ_ADDR.lap;
    mmi_btaddr.uap = 0;
    mmi_btaddr.uap = MMI_SPP_SCO_CON_REQ_ADDR.uap;
    mmi_btaddr.nap = 0;
    mmi_btaddr.nap = MMI_SPP_SCO_CON_REQ_ADDR.nap;
#if 0
/* under construction !*/
#endif

#ifdef __MMI_SPP_SCO_SUPPORT__
    if(mmi_bth_connected_port_num!= 0xFFFF)
        mmi_bth_spp_audio_disconnect_req(mmi_bth_connected_port_num);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

}
#endif /* end #ifdef __MMI_SPP_CLIENT_USAGE_DEMO__ */

/* This is testing function used with BT_SPP_SCO_xxx() */
void mmi_bth_spp_service_attribute_ind_hdler(void *msg)
{
    kal_uint8 i=0;
    kal_uint8 srv_chnl_num = 0;
    
    bt_bm_search_attribut_result_ind_struct* attribute_ind = 
                    (bt_bm_search_attribut_result_ind_struct*) msg;
    srv_chnl_num = attribute_ind ->data[0]; 
    if(g_mmi_spp_sdap_cntx[0].srv_chnl_num_no  < MMI_BTH_SPP_CLIENT_AVAILABLE_PORT)
    {
        g_mmi_spp_sdap_cntx[0].srv_chnl_num[g_mmi_spp_sdap_cntx[0].srv_chnl_num_no] = srv_chnl_num;
        g_mmi_spp_sdap_cntx[0].srv_chnl_num_no++;
    }

}

/* This is testing function used with BT_SPP_SCO_xxx() */
void mmi_bth_spp_service_attribute_result_hdler(void *msg)
{
    kal_uint8 result = 0;
    mmi_bth_spp_connect_type_enum con_type;
    S8 srv_chnl_num = g_mmi_spp_sdap_cntx[0].srv_chnl_num[0] ;
    bt_spp_connect_req_struct* bt_spp_connect_req = NULL; 
    bt_bm_search_attribute_cnf_struct* attribute_result = 
                    (bt_bm_search_attribute_cnf_struct*) msg;

    if(attribute_result ->result == BTBM_ADP_SUCCESS)
    {
        /* Directly call connect request function */
        mmi_bth_bt_addr mmi_bt_addr;
        mmi_bt_addr.lap = 0;
        mmi_bt_addr.lap = MMI_SPP_SCO_CON_REQ_ADDR.lap;
        mmi_bt_addr.uap = 0;
        mmi_bt_addr.uap = MMI_SPP_SCO_CON_REQ_ADDR.uap;
        mmi_bt_addr.nap = 0;
        mmi_bt_addr.nap = MMI_SPP_SCO_CON_REQ_ADDR.nap;

        if(MMI_SPP_SDP_ATD_TYPE == 0)
            /* Ask SDP with AID = ProtocolDescriptorList for general SPP Server */
            con_type = MMI_BTH_SPP_CLIENT_WITHOUT_SCO_REQ; 

#ifdef __MMI_SPP_SCO_SUPPORT__        
        else if(MMI_SPP_SDP_ATD_TYPE == 1)
            /* Ask SDP with AID = Support Capabilities for SPP_SCO Server */
            con_type = MMI_BTH_SPP_CLIENT_WITH_SCO_REQ;  
#endif    

        mmi_bth_spp_connect_req(0, con_type, mmi_bt_addr, srv_chnl_num);
    }
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
}



/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_sdp_query_request
* DESCRIPTION
*   1.This function is to send spp's sdp request for a SPP Client's Application.
*   2.This sdp request is used to ask the server channel number of the corresponding SPP Server provided by the remote device
*   Add by mtk01411: 2007-0628 
* PARAMETERS
*  a  IN      first variable app_inx: It is the index of SPPClientAppTable which the SPP Client's Application registered 
*  b  IN      second variable bd_addr: It is the bluetooth address of the remote device
* RETURNS
*  U8 result: The SPP Client Application should check the return value from this function (Accept or Reject this SDP request)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

U8 mmi_bth_spp_sdp_query_request(U8 app_inx, mmi_bth_bt_addr bd_addr)
{
    
    return mmi_bth_spp_general_sdp_query_request(MMI_BTH_SPP_SDP_WITH_ATTRIB_PROTOCOL_DESCRIPTOR_LIST,app_inx,bd_addr);
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_sdp_query_request
* DESCRIPTION
*   1.This function is to send spp's sdp request for a SPP Client's Application.
*   2.This sdp request is used to ask the server channel number of the corresponding SPP Server provided by the remote device
*   Add by mtk01411: 2007-0628 
* PARAMETERS
*  a  IN      first variable app_inx: It is the index of SPPClientAppTable which the SPP Client's Application registered 
*  b  IN      second variable bd_addr: It is the bluetooth address of the remote device
* RETURNS
*  U8 result: The SPP Client Application should check the return value from this function (Accept or Reject this SDP request)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

#ifdef __MMI_SPP_SCO_SUPPORT__
U8 mmi_bth_spp_audio_sdp_query_request(U8 app_inx, mmi_bth_bt_addr bd_addr)
{
    return mmi_bth_spp_general_sdp_query_request(MMI_BTH_SPP_SDP_WITH_ATTRIB_SUPPORTED_CAPABILITIES,app_inx,bd_addr);
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_general_sdp_query_request
* DESCRIPTION
*   1.This function is to send spp's sdp request for a SPP Client's Application.
*   2.This sdp request is used to ask the server channel number of the corresponding SPP Server provided by the remote device
*   Add by mtk01411: 2007-0628 
* PARAMETERS
*  a  IN      first variable app_inx: It is the index of SPPClientAppTable which the SPP Client's Application registered 
*  b  IN      second variable bd_addr: It is the bluetooth address of the remote device
* RETURNS
*  U8 result: The SPP Client Application should check the return value from this function (Accept or Reject this SDP request)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
static U8 mmi_bth_spp_general_sdp_query_request(U8 attribute_type,U8 app_inx, mmi_bth_bt_addr bd_addr)
{
    bt_bm_search_attribute_req_struct * btbm_adp_msg = NULL;    
    btbm_bd_addr_t bd_addr_t;

    /* app_inx can be from 0, if the sdp query is not going now: set mmi_bth_spp_sdp_operation_status = app_inx +1 */
    if(mmi_bth_spp_sdp_operation_status == MMI_BTH_SPP_SDP_PROCESS_NONE)
        /*mmi_bth_spp_sdp_operation_status = MMI_BTH_SPP_SDP_ONGOING;*/
        mmi_bth_spp_sdp_operation_status = app_inx + 1;
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_SDP_REQUEST_ONGOING_APP_INX, mmi_bth_spp_sdp_operation_status-1);
        return MMI_BTH_REJECT_SPP_SDP_REQUEST;  

    }
    memset((U8*)(&bd_addr_t), 0, sizeof(bd_addr_t));

    bd_addr_t.lap = bd_addr.lap;
    bd_addr_t.nap = bd_addr.nap;
    bd_addr_t.uap = bd_addr.uap;
    
    btbm_adp_msg = (bt_bm_search_attribute_req_struct *)construct_local_para(sizeof(bt_bm_search_attribute_req_struct),TD_UL);
    memcpy((U8*)(&btbm_adp_msg->bd_addr), (U8*)(&bd_addr_t), sizeof(bd_addr_t));
        
    btbm_adp_msg->sdap_uuid = MMI_BTH_SPP_PROFILE_UUID; /* 0x1101: SPP UUID */
    
    if(attribute_type == MMI_BTH_SPP_SDP_WITH_ATTRIB_PROTOCOL_DESCRIPTOR_LIST)
        btbm_adp_msg->attribute_id = MMI_BTH_SDP_AID_PROTOCOL_DESC_LIST;   /* 0x0004: ProtocolDescriptorList */

#ifdef __MMI_SPP_SCO_SUPPORT__
    else if(attribute_type == MMI_BTH_SPP_SDP_WITH_ATTRIB_SUPPORTED_CAPABILITIES)
        btbm_adp_msg->attribute_id = MMI_BTH_SDP_AID_SUPPORTED_CAPABILITIES;     /* 0x0310: Supported Capabilities */ 
 #endif
 
    mmi_bth_send_msg(MOD_BT,
                                      BT_APP_SAP,
                                      MSG_ID_BT_BM_SEARCH_ATTRIBUTE_REQ,
                                      (local_para_struct*)btbm_adp_msg,
                                      NULL);

    return MMI_BTH_ACCEPT_SPP_SDP_REQUEST;


}




/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_sdp_attribute_search_result_ind_hdler
* DESCRIPTION
*   1.This function is to report the server_channel_number of SPP Server to the SPP Client's Application
*   2.If the server channel number is gotten from SDP Response, the callback function is invoked by MMI.
*   3.From the app_inx obtained from the mmi_bth_spp_sdp_query_request function, the corresponding callback function of SPP Client's Application is invoked
*   Note: 1. Each SPP Client Application registers its corresponding callback function in the table SPPClientAppTable
*            From the SPPClientAppTable's inx, the callback functions belonged to certain SPP Client Application can be found
              2. Because there maybe serveral server channel numbers of SPP Server provided by the remote device,
                  this function may be invoked serveral times.
*   Add by mtk01411: 2007-0628 
* PARAMETERS
*  a  IN      first variable msg: It contains the server channel number of its corresponding SPP Server provided by the remote device
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_sdp_attribute_search_result_ind_hdler(void *msg)
{
    bt_bm_search_attribut_result_ind_struct *btbm_adp_msg;
    U8 server_channel_num = 0;
    S8 i =0;
    kal_uint8 app_inx = 0;
    btbm_adp_msg = (bt_bm_search_attribut_result_ind_struct *)msg;
    server_channel_num = btbm_adp_msg->data[0];

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SDP_RESULT_SRV_CHNL_NUM,server_channel_num);

    if(mmi_bth_spp_sdp_operation_status != MMI_BTH_SPP_SDP_PROCESS_NONE)
    {
        app_inx = mmi_bth_spp_sdp_operation_status -1;
        /* When the Search CNF is received, set mmi_bth_spp_sdp_operation_status = NONE in mmi_bth_spp_sdp_attribute_search_cnf_hdler()*/
    }    
    else
        MMI_BT_ASSERT(0);


    if(g_mmi_spp_sdap_cntx[0].srv_chnl_num_no  < MMI_BTH_SPP_CLIENT_AVAILABLE_PORT)
    {
        g_mmi_spp_sdap_cntx[0].srv_chnl_num[g_mmi_spp_sdap_cntx[0].srv_chnl_num_no] = server_channel_num;
        g_mmi_spp_sdap_cntx[0].srv_chnl_num_no++;
    }
    
 
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx);   
    /* Notify each SPP Client's Application */
    for(i=0; i < NUM_SPP_CLIENTS; i++)
    {
        if((i == app_inx) || (SPPClientAppTable[i].always_notified == KAL_TRUE))
        {
            /* This index (mmi_bth_spp_sdp_operation_status-1) is the requested one 
              * or the application wants to receive callback notification, it must callback to its application 
              */
            if(SPPClientAppTable[i].bt_spp_sdp_attribute_search_result_ind_hdler)
                (*SPPClientAppTable[i].bt_spp_sdp_attribute_search_result_ind_hdler)(server_channel_num); 
        }
             
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_sdp_attribute_search_cnf_hdler
* DESCRIPTION
*   1.This function is to notify the result of sdp request  to a SPP Client's Application.
*   2.From the app_inx recorded in the variable mmi_bth_spp_sdp_operation_status,
*   the callback function of its SPP Client's Application can be found through the app_inx of the table SPPClientAppTable
*   Add by mtk01411: 2007-0628 
* PARAMETERS
*  a  IN      first variable msg: It contains the result of sdp request (success or failure) 
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_sdp_attribute_search_cnf_hdler(void *msg)
{
     
    bt_bm_search_attribute_cnf_struct *btbm_adp_msg;
    U8 result = 0;
    S8 i =0;
    kal_uint8 app_inx = 0;
    btbm_adp_msg = (bt_bm_search_attribute_cnf_struct *)msg;
    result = btbm_adp_msg->result;

    if(mmi_bth_spp_sdp_operation_status != MMI_BTH_SPP_SDP_PROCESS_NONE)
    {
        app_inx = mmi_bth_spp_sdp_operation_status -1;
        mmi_bth_spp_sdp_operation_status = MMI_BTH_SPP_SDP_PROCESS_NONE;
}
    else
        MMI_BT_ASSERT(0);
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SDP_SEARCH_CNF_RESULT,result);
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx); 
    /* Notify each SPP Client's Application */
    for(i=0; i < NUM_SPP_CLIENTS; i++)
    {
        if((i == app_inx) || (SPPClientAppTable[i].always_notified == KAL_TRUE))
        {
            /* This index (mmi_bth_spp_sdp_operation_status-1) is the requested one 
              * or the application wants to receive callback notification, it must callback to its application 
              */
            if(SPPClientAppTable[i].bt_spp_sdp_attribute_search_cnf_hdler)
                (*SPPClientAppTable[i].bt_spp_sdp_attribute_search_cnf_hdler)(result); 
        }
             
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_connect_req
* DESCRIPTION
*   This function is used to establish a SPP connection by a  SPP Client's Application.
*   Add by mtk01411: 2007-0628 
* PARAMETERS
*  a  IN      first variable app_inx: This is the inx which the SPP Client Application registered in the table SPPClientAppTable
*  b  IN      second variabe connection_type: SPP_CONNECT_REQ without SCO(e.g., GPS Application, Game Application) or SPP_CONNECT_REQ with SCO(Cordless Phone Application) ... etc.
*  c  IN      third variable bd_addr: The remote device's address for this SPP Client Application to connect
*  d  IN      fourth variable server_channel_num: It is the server channel number which the SPP Client Application wants to connect   
* RETURNS
*  U8 result: Accept or Rejct this connection request (If this connection request is accepted, the conneciton cnf will be sent from the remote deivce later)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

U8 mmi_bth_spp_connect_req(U8 app_inx, mmi_bth_spp_connect_type_enum connection_type, mmi_bth_bt_addr bd_addr,S8 server_channel_num)
{
    bt_spp_connect_req_struct* bt_spp_connect_req;
    S8 i=0;
    mmi_spp_cntx_struct* spp_client_entry = NULL;
    U32 connection_msg_id = 0;

    if(mmi_bth_spp_connect_operation_status == MMI_BTH_SPP_CONNECT_PROCESS_NONE)
        mmi_bth_spp_connect_operation_status = MMI_BTH_SPP_CONNECT_ONGOING;
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CON_REQ_REJECT);
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,mmi_bth_spp_connect_operation_status);
        return MMI_BTH_REJECT_SPP_CONNECT;

    }
    if(mmi_bth_current_spp_client_num == NUM_SPP_CLIENTS)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CON_REQ_NO_FREE_ENTRY);
        return MMI_BTH_SPP_NO_FREE_ENTRY;
    }  
    /* Check if this time's connect request bd_addr and server_chnl is already connected or not */
    spp_client_entry = mmi_bth_spp_find_entry_by_connect_type(MMI_BTH_SPP_STAT_CONNECTED,bd_addr,server_channel_num);
    if(spp_client_entry != NULL)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CON_REQ_REJECT_ALREADY_CONNECTED);
        return MMI_BTH_SPP_CONNECT_REQ_REJECT_WITH_ALREADY_CONNECTED;
    }
    spp_client_entry = mmi_bth_spp_find_entry_by_connect_type(MMI_BTH_SPP_STAT_CONNECT_REQ,bd_addr,server_channel_num);
    if(spp_client_entry != NULL)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CON_REQ_REJECT_ALREADY_CONNECTING);
        return MMI_BTH_SPP_CONNECT_REQ_REJECT_WITH_ALREADY_CONNECTING;
    }

    /* Check if any entry with audio_state is AUDIO_CONNECT and its bd_address is the same with this request one or not 
      * In this case: RFCOMM channel is closed, but ACL link is not disconnected due to existing other channel connected,
      * So the SCO link may still be connected due to 
      *  1) ACL link is active or 
      *  2) ACL link is disconnected but SPP Client Application does not to terminate its corresponding SCO link
      * Try to search the entry matched the following two conditions:
      * 1) audio_state is AUDIO_CONNECT
      * 2) bd_addres is the same with this time requested bd_address
      */
#ifdef __MMI_SPP_SCO_SUPPORT__      
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_TRY_FIND_EXIST_SCO_ENTRY);
    spp_client_entry = mmi_bth_spp_find_existing_sco_entry(bd_addr,server_channel_num,0);
    if(spp_client_entry == NULL)
    {
        /* Try to find an available entry with state is IDLE and audio_state is AUDIO_IDLE for this connect request */
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_TRY_FIND_FREE_ENTRY);
        spp_client_entry = mmi_bth_spp_find_available_entry();
        
    }
#else

        /* Try to find an available entry with state is IDLE and audio_state is AUDIO_IDLE for this connect request */
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_TRY_FIND_FREE_ENTRY);
        spp_client_entry = mmi_bth_spp_find_available_entry();

#endif

    
    if(spp_client_entry != NULL)
    {
        spp_client_entry->server_chnl_num = server_channel_num;
        spp_client_entry->app_inx = app_inx;
        spp_client_entry->lap = 0;
        spp_client_entry->lap = bd_addr.lap;
        spp_client_entry->nap = 0;
        spp_client_entry->nap = bd_addr.nap;
        spp_client_entry->uap = 0;
        spp_client_entry->uap = bd_addr.uap;
        spp_client_entry->state= MMI_BTH_SPP_STAT_CONNECT_REQ;
        mmi_bth_current_spp_client_num++;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CON_REQ_NO_FREE_ENTRY);
        return MMI_BTH_SPP_NO_FREE_ENTRY;
    }
    
    if(connection_type == MMI_BTH_SPP_CLIENT_WITHOUT_SCO_REQ)
        connection_msg_id = MSG_ID_BT_SPP_CONNECT_REQ;

#ifdef __MMI_SPP_SCO_SUPPORT__     
    else if(connection_type == MMI_BTH_SPP_CLIENT_WITH_SCO_REQ)
        connection_msg_id = MSG_ID_BT_SPP_SCO_CONNECT_REQ;
#endif

    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_INVALID_CON_REQ_TYPE,connection_type);
        return MMI_BTH_SPP_INVALID_CONNECTION_TYPE;

    }
    bt_spp_connect_req = (bt_spp_connect_req_struct *)construct_local_para(sizeof(bt_spp_connect_req_struct),TD_UL); 
    bt_spp_connect_req->lap = 0;
    bt_spp_connect_req->lap = bd_addr.lap;
    bt_spp_connect_req->nap = 0;
    bt_spp_connect_req->nap = bd_addr.nap;
    bt_spp_connect_req->uap = 0;
    bt_spp_connect_req->uap = bd_addr.uap; 
    bt_spp_connect_req->server_chnl_num = server_channel_num;
    
    mmi_bth_send_msg(MOD_BT,
                                      BT_APP_SAP,
                                      connection_msg_id,
                                      (local_para_struct*)bt_spp_connect_req,
                                      NULL);  

    return MMI_BTH_ACCEPT_SPP_CONNECT;
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_connect_req
* DESCRIPTION
*   1.This function is used to report the result of SPP conneciton request to a  SPP Client's Application.
*   2.The app_inx can be found through the search of the array g_mmi_spp_cntx with comparsion of connection_type, bd_adress, and server channel number
*   3.The callback function can be invoked via the app_inx of the table SPPClientAppTable
*   Add by mtk01411: 2007-0326
* PARAMETERS
*  a  IN      first variable msg: It contains the result of spp connection request (success or failure)
                                            If the result is successful, the connection_id and port will be valid for this SPP Client Application 
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_connect_cnf_hdler(void* msg)
{
    kal_bool result = KAL_FALSE;
    kal_uint8 bd_addr[6];
    kal_uint8* name = NULL;
    int i=0;
    mmi_bth_bt_addr connected_bt_addr;
    mmi_spp_cntx_struct* spp_client_entry = NULL;
    kal_uint8 app_inx = 0;
    
    bt_spp_connect_cnf_struct* bt_spp_connect_cnf = (bt_spp_connect_cnf_struct*)msg;

    connected_bt_addr.lap = 0;
    connected_bt_addr.lap = bt_spp_connect_cnf->lap;
    connected_bt_addr.uap = 0;
    connected_bt_addr.uap = bt_spp_connect_cnf->uap;
    connected_bt_addr.nap = 0;
    connected_bt_addr.nap = bt_spp_connect_cnf->nap;

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SUPPORT_MAX_SPP_CONS,MMI_BTH_SPP_MAX_CONNECTION);

    if(mmi_bth_spp_connect_operation_status == MMI_BTH_SPP_CONNECT_ONGOING)
        mmi_bth_spp_connect_operation_status = MMI_BTH_SPP_CONNECT_PROCESS_NONE;    
    else
        MMI_BT_ASSERT(0);     

    spp_client_entry = mmi_bth_spp_find_entry_by_connect_type(MMI_BTH_SPP_STAT_CONNECT_REQ, connected_bt_addr, bt_spp_connect_cnf->server_chnl_num);
    if(spp_client_entry == NULL)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_ENTRY_ADDR_SRV_CHNL_NUM,connected_bt_addr.lap,connected_bt_addr.uap,connected_bt_addr.nap,bt_spp_connect_cnf->server_chnl_num);
        return;
    }
    app_inx = spp_client_entry->app_inx;

    /* This means that some err happens in spp connect procedure */
    if(bt_spp_connect_cnf->result >0)
    {
        result = KAL_FALSE;
        spp_client_entry->lap = 0;
        spp_client_entry->nap = 0;
        spp_client_entry->uap = 0;
        spp_client_entry->server_chnl_num = (S8)-1; /* the default value is -1 */
        spp_client_entry->app_inx = 0;
        spp_client_entry->state = MMI_BTH_SPP_STAT_ACTIVATE;
        mmi_bth_current_spp_client_num--;
        
    }    
    else if(bt_spp_connect_cnf->result == 0)
    {
        result = KAL_TRUE;
        /* If result == KAL_TRUE: meaning that SPP Client establishes the connection successfully */
        spp_client_entry->state = MMI_BTH_SPP_STAT_CONNECTED;
        spp_client_entry->connect_id = bt_spp_connect_cnf->cid;
        spp_client_entry->port = (U16)bt_spp_connect_cnf->port;
        spp_client_entry->lap = bt_spp_connect_cnf->lap;
        spp_client_entry->uap = bt_spp_connect_cnf->uap;
        spp_client_entry->nap = bt_spp_connect_cnf->nap;
        spp_client_entry->server_chnl_num = bt_spp_connect_cnf->server_chnl_num;

        /*Only for testing mode: *#906# and *#907#: AUDIO_CONNECT_REQ and AUDIO_DISCONNECT_REQ */
        mmi_bth_connected_port_num = spp_client_entry->port; 

        /* If this connection is established successfully, the name can be obtained via the following function */   
        CONVERT_BDADDR2ARRAY(bd_addr, bt_spp_connect_cnf->lap, bt_spp_connect_cnf->uap, bt_spp_connect_cnf->nap);
        name = BTBMGetLocalStoredName(bd_addr); 
    }
    
   
    /* Notify MMI BTH CM Module */
    mmi_bth_connect_cnf_hdler(  result, 
                                bt_spp_connect_cnf->lap, 
                                bt_spp_connect_cnf->uap, 
                                bt_spp_connect_cnf->nap,
                                name, 
                                MMI_BTH_SPP_PROFILE_UUID,
                                bt_spp_connect_cnf->cid);

    /* Notify each SPP Client's Application */
    connected_bt_addr.lap = 0;
    connected_bt_addr.lap = bt_spp_connect_cnf->lap;
    connected_bt_addr.nap = 0;
    connected_bt_addr.nap = bt_spp_connect_cnf->nap;
    connected_bt_addr.uap = 0;
    connected_bt_addr.uap = bt_spp_connect_cnf->uap;

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx);
    for(i=0; i < NUM_SPP_CLIENTS; i++)
    { 
        if((i == app_inx) || (SPPClientAppTable[i].always_notified == KAL_TRUE))
        {
            if(SPPClientAppTable[i].bt_spp_connect_cnf_hdler)
                (*SPPClientAppTable[i].bt_spp_connect_cnf_hdler)(result,
                                                                                            bt_spp_connect_cnf->server_chnl_num, /* server_channel_num */
                                                                                            bt_spp_connect_cnf->cid,
                                                                                            bt_spp_connect_cnf->port,
                                                                                            connected_bt_addr
                                                                                            );    
        }
    }
    

}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_connect_ind_hdler
* DESCRIPTION
*   This function is to report a incoming SPP connection
*
* PARAMETERS
*  a  IN/OUT      first variable, used as returns
*  b  IN       second variable
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_spp_connect_ind_hdler(void *msg)
{
    bt_spp_connect_ind_struct *msg_p = (bt_spp_connect_ind_struct *)msg;
    kal_uint8 i;
    kal_uint8 bd_addr[6];
    kal_uint8* name = NULL;
    mmi_spp_cntx_struct* spp_server_entry = NULL;
    mmi_bth_bt_addr mmi_bd_addr;

    /* Check if any entry with audio_state is AUDIO_CONNECT and its bd_address is the same with this request one or not 
      * In this case: RFCOMM channel is closed, but ACL link is not disconnected due to existing other channel connected,
      * So the SCO link may still be connected due to 
      *  1) ACL link is active or 
      *  2) ACL link is disconnected but SPP Client Application does not to terminate its corresponding SCO link
      * Try to search the entry matched the following two conditions:
      * 1) audio_state is AUDIO_CONNECT
      * 2) bd_addres is the same with this time requested bd_address
      */

    mmi_bd_addr.lap = 0;
    mmi_bd_addr.lap = msg_p->lap;
    mmi_bd_addr.uap =0;
    mmi_bd_addr.uap = msg_p->uap;
    mmi_bd_addr.nap = 0;
    mmi_bd_addr.nap = msg_p->nap;

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SUPPORT_MAX_SPP_CONS,MMI_BTH_SPP_MAX_CONNECTION);

#ifdef __MMI_SPP_SCO_SUPPORT__    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_TRY_FIND_EXIST_SCO_ENTRY);
    spp_server_entry = mmi_bth_spp_find_existing_sco_entry(mmi_bd_addr,-1,(U16)msg_p->port);
    if(spp_server_entry == NULL)
    {
        /* Try to find an available entry with state is IDLE and audio_state is AUDIO_IDLE for this connect request */
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_TRY_FIND_FREE_ENTRY);
        spp_server_entry = mmi_bth_spp_find_available_entry();
       
        
    }
#else
       /* Try to find an available entry with state is IDLE and audio_state is AUDIO_IDLE for this connect request */
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_TRY_FIND_FREE_ENTRY);
        spp_server_entry = mmi_bth_spp_find_available_entry(); 
#endif
    
    if(spp_server_entry != NULL)
    {
        kal_int8 inx =0;
        spp_server_entry->state = MMI_BTH_SPP_STAT_CONNECTED;
        spp_server_entry->connect_id = msg_p->cid;
        spp_server_entry->port = (U16)msg_p->port;
        spp_server_entry->lap = 0;
        spp_server_entry->lap = msg_p->lap;
        spp_server_entry->uap = 0;
        spp_server_entry->uap = msg_p->uap;
        spp_server_entry->nap = 0;
        spp_server_entry->nap = msg_p->nap;
        /* Add by mtk01411 2007-0628: server_chnl_num=-1, because this entry is used for SPP Server */
        spp_server_entry->server_chnl_num = (S8)-1;
        
        /*Only for testing mode: *#906# and *#907#: AUDIO_CONNECT_REQ and AUDIO_DISCONNECT_REQ */
        mmi_bth_connected_port_num = spp_server_entry->port;
        
        spp_server_entry->app_inx = 0;
        CONVERT_BDADDR2ARRAY(bd_addr, msg_p->lap, msg_p->uap, msg_p->nap);
        name = BTBMGetLocalStoredName(bd_addr);
        //PRINT_INFORMATION("mmi_bth_spp_connect_ind_hdler(): get device name=%s",name);
    
        /* inform CM connect result */
        mmi_bth_connect_ind_hdler(  
            msg_p->lap,
            msg_p->uap,
            msg_p->nap,
            name,
            MMI_BTH_SPP_PROFILE_UUID,
            msg_p->cid);

        /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(spp_server_entry->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_connect_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_connect_ind_hdler)(spp_server_entry->connect_id, spp_server_entry->port, mmi_bd_addr);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,spp_server_entry->port);

        }
        
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CON_IND_NO_FREE_ENTRY);
        
    }
}


#ifdef __MMI_SPP_SCO_SUPPORT__

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_connect_req
* DESCRIPTION
*   This function is used to establish a SPP SCO connection by a  SPP Client's Application.
*   Add by mtk01411: 2007-0709
* PARAMETERS
*  a  IN      first variable port: This is the port number carried in the message uart_owner_ind
* RETURNS
*  U8 result: Accept or Rejct this SCO connection request (If this SCO connection request is accepted, the SCO conneciton cnf will be sent from the remote deivce later)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

U8 mmi_bth_spp_audio_connect_req(U16 port)
{
    mmi_spp_cntx_struct* spp_entry = NULL;
    bt_spp_audio_connect_req_struct * btbm_adp_msg = NULL;
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT,port); 
    spp_entry = mmi_bth_spp_find_entry_by_port(port);

    if(spp_entry != NULL)
    {
       if (spp_entry->state == MMI_BTH_SPP_STAT_CONNECTED)
       {
            spp_entry->audio_state = MMI_BTH_SPP_STAT_AUDIO_CONNECT_REQ;
            /* For SPP SCO Server: register its callback func sets to table */ 
            btbm_adp_msg = (bt_spp_audio_connect_req_struct *)
                construct_local_para(sizeof(bt_spp_audio_connect_req_struct),TD_UL);

            btbm_adp_msg->port = port; 
            
            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_AUDIO_CONNECT_REQ, (local_para_struct*)btbm_adp_msg, NULL);
            return MMI_BTH_ACCEPT_SPP_AUDIO_CONNECT;
       }
       else
       {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_INVALID_WHEN_AUDIO_CON_REQ,spp_entry->state);
            return MMI_BTH_SPP_INVAILD_STATE;
       }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_MATCHED_ENTRY);
        return MMI_BTH_SPP_AUDIO_CONNECT_INVALID_PORT;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_connect_cnf_hdler
* DESCRIPTION
*   This function is used to report the result of  a SPP SCO connection to a  original initiator SPP Client's Application.
*   Add by mtk01411: 2007-0709
* PARAMETERS
*  a  IN      first variable msg: This variable contains a port number the same with the one carried in the message uart_owner_ind
                                            This variable also contains the result of this SCO setup 
* RETURNS
*  U8 result: Accept or Rejct this SCO connection request (If this SCO connection request is accepted, the SCO conneciton cnf will be sent from the remote deivce later)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_audio_connect_cnf_hdler(void *msg)
{
    mmi_spp_cntx_struct* spp_entry = NULL;
    bt_spp_audio_connect_cnf_struct* mmi_bt_spp_audio_connect_cnf = NULL;
    kal_bool IsServerFlag = KAL_FALSE;
    mmi_bt_spp_audio_connect_cnf = (bt_spp_audio_connect_cnf_struct*)msg;

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT,mmi_bt_spp_audio_connect_cnf->port);
    spp_entry = mmi_bth_spp_find_entry_by_port(mmi_bt_spp_audio_connect_cnf->port);
    
    if(spp_entry!=NULL)
    {
        if(spp_entry->audio_state == MMI_BTH_SPP_STAT_AUDIO_CONNECT_REQ)
            spp_entry->audio_state = MMI_BTH_SPP_STAT_AUDIO_CONNECTED;
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_AUDIO_CON_CNF_HDLER_AUDIO_STATE,spp_entry->audio_state);
            MMI_BT_ASSERT(0);
        }

    }
    else
    {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_MATCHED_ENTRY);
            return;
    }

    IsServerFlag = IsThisPortAsSPPServer(mmi_bt_spp_audio_connect_cnf->port);
    
    if(!IsServerFlag)
    {
        /* SPPClientApplication */
        
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,spp_entry->app_inx);                
        /* Find the app_inx of SPP Client Application which initiates this spp audio request */
        if(SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_connect_cnf_hdler)
            (*SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_connect_cnf_hdler)(mmi_bt_spp_audio_connect_cnf->result,mmi_bt_spp_audio_connect_cnf->port);
                         
        
   }
   else
   {
        kal_int8 inx =0;

        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_AUDIO_CON_CNF_HDLER_SWITCH_TO_AUDIO_CONNECT,spp_entry->audio_state);
        
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(mmi_bt_spp_audio_connect_cnf->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_audio_connect_cnf_hdler)
                (*SPPServerAppTable[inx].bt_spp_audio_connect_cnf_hdler)(mmi_bt_spp_audio_connect_cnf->result, mmi_bt_spp_audio_connect_cnf->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,mmi_bt_spp_audio_connect_cnf->port);

        }


    }
    
    
}



/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_connect_ind_hdler
* DESCRIPTION
*   This function is used to report an event : an incoming SPP SCO connection to a SPP Client's Application.
*   Add by mtk01411: 2007-0709
* PARAMETERS
*  a  IN      first variable msg: This variable contains a port number the same with the one carried in the message uart_owner_ind                                            
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_audio_connect_ind_hdler(void *msg)
{
    mmi_spp_cntx_struct* spp_entry = NULL;
    bt_spp_audio_connect_ind_struct* mmi_bt_spp_audio_connect_ind = NULL;
    kal_bool IsServerFlag = KAL_FALSE;
    mmi_bt_spp_audio_connect_ind = (bt_spp_audio_connect_ind_struct*)msg;

    /* Using this port to find its corresponding spp client entry, via spp client entry to find the app_inx */
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT,mmi_bt_spp_audio_connect_ind->port);

    spp_entry = mmi_bth_spp_find_entry_by_port(mmi_bt_spp_audio_connect_ind->port);
    if(spp_entry != NULL)
    {
        if(spp_entry->state == MMI_BTH_SPP_STAT_CONNECTED)
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_AUDIO_CON_CNF_HDLER_SWITCH_TO_AUDIO_CONNECT,spp_entry->audio_state);
            spp_entry->audio_state = MMI_BTH_SPP_STAT_AUDIO_CONNECTED;
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_AUDIO_CON_IND_HDLER_CON_STATE,spp_entry->state);
            MMI_BT_ASSERT(0);
        }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_MATCHED_ENTRY);
        return;
    }

    IsServerFlag = IsThisPortAsSPPServer(mmi_bt_spp_audio_connect_ind->port);
    if(!IsServerFlag)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,spp_entry->app_inx);   
        /* Callback to this SPP Client Application */
        if(SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_connect_ind_hdler)
            (*SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_connect_ind_hdler)(mmi_bt_spp_audio_connect_ind->port);
    }
    else
    {
        kal_int8 inx =0;
        
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(mmi_bt_spp_audio_connect_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_audio_connect_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_audio_connect_ind_hdler)(mmi_bt_spp_audio_connect_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,mmi_bt_spp_audio_connect_ind->port);

        }
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_disconnect_req
* DESCRIPTION
*   This function is used to terminate a SPP SCO connection by a  SPP Client's Application.
*   Add by mtk01411: 2007-0709
* PARAMETERS
*  a  IN      first variable port: This is the port number carried in the message uart_owner_ind
* RETURNS
*  U8 result: Accept or Rejct this SCO disconnection request (If this SCO disconnection request is accepted, the SCO disconneciton cnf will be sent from the remote deivce later)
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
U8 mmi_bth_spp_audio_disconnect_req(U16 port)
{
    mmi_spp_cntx_struct* spp_entry = NULL;
    bt_spp_audio_disconnect_req_struct * btbm_adp_msg = NULL;
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT,port);

    spp_entry = mmi_bth_spp_find_entry_by_port(port);

    if(spp_entry != NULL)
    {
        /* If the SPPClient Application disc SPP profile directly and audio link is connected, then:
          * It must disconnect audio link first and change its state !!!
          * After audio link is disconnected, it must disc SPP profile 
          */
        if((spp_entry->state == MMI_BTH_SPP_STAT_DISC_AUDIO_LINK_FRIST_THEN_DISC_SPP_CHNL)
            && (spp_entry->audio_state == MMI_BTH_SPP_STAT_AUDIO_DISCONNECT_REQ)  
            )
        {
            /* user has already presses disc button for SPP connection, should reject this audio disconnection request!*/
            return MMI_BTH_SPP_AUDIO_ALREADY_DISCONNECTING_DUE_TO_SPP_DISC_REQ;
        }
    
        else if ((spp_entry->state == MMI_BTH_SPP_STAT_DISC_AUDIO_LINK_FRIST_THEN_DISC_SPP_CHNL)
                    && (spp_entry->audio_state == MMI_BTH_SPP_STAT_AUDIO_CONNECTED)
                   )
        {
                /* This case: user presses the disc button for SPP connection */
                btbm_adp_msg = (bt_spp_audio_disconnect_req_struct *)
                    construct_local_para(sizeof(bt_spp_audio_disconnect_req_struct),TD_UL);
                btbm_adp_msg->port = port;
                mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_AUDIO_DISCONNECT_REQ, (local_para_struct*)btbm_adp_msg, NULL);

                spp_entry->audio_state = MMI_BTH_SPP_STAT_AUDIO_DISCONNECT_REQ;
            
                return MMI_BTH_ACCEPT_SPP_AUDIO_DISCONNECT;
        }
        else 
        {
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_INVALID_WHEN_AUDIO_DISCON_REQ,spp_entry->audio_state);
                return MMI_BTH_SPP_INVAILD_STATE;
        }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_MATCHED_ENTRY);
        return MMI_BTH_SPP_AUDIO_DISCONNECT_INVALID_PORT;
    }
        
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_disconnect_cnf_hdler
* DESCRIPTION
*   This function is used to report the result of  a SPP SCO discconnection to a  original initiator SPP Client's Application.
*   Add by mtk01411: 2007-0709
* PARAMETERS
*  a  IN      first variable msg: This variable contains a port number the same with the one carried in the message uart_owner_ind
                                            This variable also contains the result of this SCO termination 
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_audio_disconnect_cnf_hdler(void *msg)
{
    mmi_spp_cntx_struct* spp_entry = NULL;
    kal_bool IsServerFlag = KAL_FALSE;
    bt_spp_audio_disconnect_cnf_struct* mmi_bt_spp_audio_disconnect_cnf = NULL;
    mmi_bt_spp_audio_disconnect_cnf = (bt_spp_audio_disconnect_cnf_struct*)msg;

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT,mmi_bt_spp_audio_disconnect_cnf->port);    

    spp_entry  = mmi_bth_spp_find_entry_by_port(mmi_bt_spp_audio_disconnect_cnf->port);
    /* Check if the entry of this spp connection in array g_mmi_spp_cntx[] is necessary to reset or not */
    if(spp_entry!=NULL)
    {
        if(spp_entry->audio_state == MMI_BTH_SPP_STAT_AUDIO_DISCONNECT_REQ)
            spp_entry->audio_state = MMI_BTH_SPP_STAT_AUDIO_IDLE;
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_AUDIO_DISC_CNF_HDLER_AUDIO_STATE,spp_entry->audio_state);
            MMI_BT_ASSERT(0);
        }

        
        if(spp_entry->state == MMI_BTH_SPP_STAT_ACTIVATE)      
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_RESET_ENTRY);
            /* Reset the entry of the array g_mmi_spp_cntx[]: Because RFCOMM channel is already closed */
            spp_entry->app_inx = 0;
            spp_entry->server_chnl_num = (S8)-1; /* -1 is the default value */
            spp_entry->connect_id = 0;
            spp_entry->port = 0;
            spp_entry->lap = 0;
            spp_entry->nap = 0;
            spp_entry->uap = 0;
            
        }
        else if (spp_entry->state == MMI_BTH_SPP_STAT_DISC_AUDIO_LINK_FRIST_THEN_DISC_SPP_CHNL)
        {
            /* The audio link is disconnected, it is time to disconnect SPP chnl */
            mmi_bth_bt_addr addr;
            addr.lap = spp_entry->lap;
            addr.uap = spp_entry->uap;
            addr.uap = spp_entry->nap;
            spp_entry->state = MMI_BTH_SPP_STAT_CONNECTED;
             /*Because the audio disconnect cnf is triggered byour device's SPP Profile disconnection, 
               *this event can not be callback to SPP Application 
               * The SPP Chnl disconnection cnf or ind event is expected later !
               */
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_RECV_AUDIO_DISC_CNF_THEN_DISC_SPP_CHNL);   
            mmi_bth_spp_disconnect_req_hdler(addr,spp_entry->connect_id);
            return;

        }
        else
        {
            /* DO NOT Reset the entry of the array g_mmi_spp_cntx[]: Because the disconnect of SPP connection needs this entry's info to callback */
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_NOT_RESET_ENTRY_DUE_TO_RFCHNL_NOT_CLOSED,spp_entry->state);
        }

    }
    else
    {
        /* Log failed message */
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_MATCHED_ENTRY);
        return;
    }

    IsServerFlag = IsThisPortAsSPPServer(mmi_bt_spp_audio_disconnect_cnf->port);

    if(!IsServerFlag)
    {  
        /* Find the app_inx of SPP Client Application which initiates this spp audio request */
        if(SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_disconnect_cnf_hdler)
            (*SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_disconnect_cnf_hdler)(mmi_bt_spp_audio_disconnect_cnf->result,mmi_bt_spp_audio_disconnect_cnf->port);
        
    }
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(mmi_bt_spp_audio_disconnect_cnf->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_audio_disconnect_cnf_hdler)
                (*SPPServerAppTable[inx].bt_spp_audio_disconnect_cnf_hdler)(mmi_bt_spp_audio_disconnect_cnf->result, mmi_bt_spp_audio_disconnect_cnf->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,mmi_bt_spp_audio_disconnect_cnf->port);

        }

    }
    
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_audio_disconnect_ind_hdler
* DESCRIPTION
*   This function is used to report an event : an incoming SPP SCO disconnection to a SPP Client's Application.
*   Add by mtk01411: 2007-0709
* PARAMETERS
*  a  IN      first variable msg: This variable contains a port number the same with the one carried in the message uart_owner_ind                                            
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_audio_disconnect_ind_hdler(void *msg)
{
    mmi_spp_cntx_struct* spp_entry = NULL;
    kal_bool IsServerFlag = KAL_FALSE;
    mmi_bth_spp_audio_state_enum previous_audio_state;
    bt_spp_audio_disconnect_ind_struct* mmi_bt_spp_audio_disconnect_ind = NULL;
    mmi_bt_spp_audio_disconnect_ind = (bt_spp_audio_disconnect_ind_struct*)msg;

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_FIND_ENTRY_BY_PORT,mmi_bt_spp_audio_disconnect_ind->port);
    
    spp_entry = mmi_bth_spp_find_entry_by_port(mmi_bt_spp_audio_disconnect_ind->port);
    if(spp_entry != NULL)
    {
        previous_audio_state = spp_entry->audio_state;
        spp_entry->audio_state = MMI_BTH_SPP_STAT_AUDIO_IDLE;
        if(spp_entry->state == MMI_BTH_SPP_STAT_ACTIVATE)
        {
            /* Reset the entry of the array g_mmi_spp_cntx[]: Because RFCOMM channel is already closed */
            spp_entry->app_inx = 0;
            spp_entry->server_chnl_num = (S8)-1; /* -1 is the default value */
            spp_entry->connect_id = 0;
            spp_entry->port = 0;
            spp_entry->lap = 0;
            spp_entry->nap = 0;
            spp_entry->uap = 0;

        }
        else if (spp_entry->state == MMI_BTH_SPP_STAT_DISC_AUDIO_LINK_FRIST_THEN_DISC_SPP_CHNL)
        {
            /* The audio link is disconnected, it is time to disconnect SPP chnl */
            mmi_bth_bt_addr addr;
            addr.lap = spp_entry->lap;
            addr.uap = spp_entry->uap;
            addr.uap = spp_entry->nap;
            spp_entry->state = MMI_BTH_SPP_STAT_CONNECTED;
            /*Because the audio disconnect ind is triggered by remote device, it event can be callback to SPP Application */
            MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_RECV_AUDIO_DISC_IND_THEN_DISC_SPP_CHNL);
            mmi_bth_spp_disconnect_req_hdler(addr,spp_entry->connect_id);

            /* Because this case is disc audio link first, and remote device also tries to disconnect audio link 
              * The audio_disc_ind is sent from bt stack, the callback is not necessary!
              * The initiation procedure is that SPP Application does spp chnl disconnection
              */
           
            return;
            
        }
        else
        {
            /* DO NOT Reset the entry of the array g_mmi_spp_cntx[]: Because the disconnect of SPP connection needs this entry's info to callback */
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_NOT_RESET_ENTRY_DUE_TO_RFCHNL_NOT_CLOSED,spp_entry->state);
        }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CANNOT_FIND_MATCHED_ENTRY);
        return;
    }
    

    IsServerFlag = IsThisPortAsSPPServer(mmi_bt_spp_audio_disconnect_ind->port);

    if(!IsServerFlag)
    {
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX, spp_entry->app_inx);     
        if(SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_disconnect_ind_hdler)
        {
            (*SPPClientAppTable[spp_entry->app_inx].bt_spp_audio_disconnect_ind_hdler)(mmi_bt_spp_audio_disconnect_ind->port);
        }
    }
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(mmi_bt_spp_audio_disconnect_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_audio_disconnect_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_audio_disconnect_ind_hdler)(mmi_bt_spp_audio_disconnect_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,mmi_bt_spp_audio_disconnect_ind->port);

        }

    }
}    

#endif /* end #ifdef __MMI_SPP_SCO_SUPPORT__ */

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_uart_plugout_ind_hdler
* DESCRIPTION
*   1.This function is used to send uart_plugout_cnf to BT stack by a  SPP Client's Application.
*   2.Because the SPP Client Application may change the uart port owner,
*   it should reset the uart port owner as MOD_MMI before the SPP Client Application calls this function.
*   3.When the SPP Client Application calls this function, it means that the related ending procedure has been done by SPP Client Application,
*   it is time to notify the BT stack to reset the uart port owner to default module (ie. MOD_L4)  
*   Add by mtk01411: 2007-0326
* PARAMETERS
*  a  IN      first variable port: This is the port which has been plugout.
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_uart_plugout_ind_hdler(void *msg)
{
    kal_uint8 i=0;
    kal_bool IsServerFlag = KAL_FALSE;
    uart_plugin_ind_struct* uart_plugout_ind = (uart_plugin_ind_struct*)msg;
    kal_uint8 app_inx = 0;
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_UART_PLUGOUT_IND,uart_plugout_ind->port);

    IsServerFlag = IsThisPortAsSPPServer(uart_plugout_ind->port);

    if(!IsServerFlag)
    {
    
        /* Notify SPP Client Application 
          * The SPP Client Application should do somthing upon receipt of UART_PLUGOUT_IND
          */
        for (i=0; i< NUM_SPP_CLIENTS; i++)
        {
            if(uart_plugout_ind->port == g_mmi_spp_cntx[i].port)
            {
                app_inx = g_mmi_spp_cntx[i].app_inx;
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx);
                if(SPPClientAppTable[app_inx].bt_spp_uart_plugout_ind_hdler)
                    (*SPPClientAppTable[app_inx].bt_spp_uart_plugout_ind_hdler)(g_mmi_spp_cntx[i].port);
            
            }
        }
    }
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(uart_plugout_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_uart_plugout_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_uart_plugout_ind_hdler)(uart_plugout_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,uart_plugout_ind->port);

        }

    }
    
}



/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_send_uart_plugout_cnf_hdler
* DESCRIPTION
*   1.This function is used to send uart_plugout_cnf to BT stack by a  SPP Client's Application.
*   2.Because the SPP Client Application may change the uart port owner,
*   it should reset the uart port owner as MOD_MMI before the SPP Client Application calls this function.
*   3.When the SPP Client Application calls this function, it means that the related ending procedure has been done by SPP Client Application,
*   it is time to notify the BT stack to reset the uart port owner to default module (ie. MOD_L4)  
*   Add by mtk01411: 2007-0708
* PARAMETERS
*  a  IN      first variable port: This is the port which has been plugout.
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_send_uart_plugout_cnf_hdler(U16 port)
{

    /* Check if this port is owned by MMI previously 
      * Before the SPP Client Application calls this function, it should reset the uart port owner as MOD_MMI.
      */

    if(UART_GetOwnerID(port) == MOD_MMI)
    {
        bt_spp_uart_plugout_cnf_struct* bt_spp_uart_plugout_cnf = NULL;
        bt_spp_uart_plugout_cnf = construct_local_para(sizeof(bt_spp_uart_plugout_cnf_struct),TD_UL);
        bt_spp_uart_plugout_cnf->port = port;        
        
        MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SEND_UART_PLUGOUT_CNF,port);
        /* Send MSG_ID_BT_SPP_UART_PLUGOUT_CNF to BT: This is necessary */
        mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_UART_PLUGOUT_CNF, (local_para_struct*)bt_spp_uart_plugout_cnf, NULL);
        
    }
    else
    {
        //PRINT_INFORMATION("MMI receives the request to send uart_plugout_cnf, but MMI is not owner of port=%d",port);
        MMI_BT_ASSERT(0);
        
    }


}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_uart_owner_ind_hdler
* DESCRIPTION
*   1. This function is used to notify uart_owner_ind to MMI
*   2. MMI will report this message to the SPP Client Application which requested to establish SPP connection previously.
*   3. The SPP connection cnf will be received before this message,
*   the port number can be used to search the array g_mmi_spp_cntx to find the app_inx
*   4. The app_inx of the table SPPClientAppTable can be used to fine the registered callback function of SPP Client Application
*   5. Notify the SPP Client Application of uart_owner_ind via the reigstered callback function
*   6. The SPP Client Application may change the uart port owner upon receipt of  the uart_owner_ind msg.
*   7. In order to let BT stack can send uart_ready_to_read_ind msg to correct uart owner Module,
*   8. the SPP Client Application should call the this function to notify the BT stack that it already sets the uart port owner completely.
*   Note: If the SPP Client Application changes the uart owner port, this function must be invoked after changing the uart port owner. 
*   Add by mtk01411: 2007-0708
* PARAMETERS
*  a  IN      first variable port: It contains the port number which the MMI is the owner of it
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_uart_owner_ind_hdler(void *msg)
{
    bt_spp_uart_owner_ind_struct* bt_spp_uart_owner_ind = NULL;
    kal_uint8 i=0;
    kal_uint8 app_inx = 0;
    kal_bool IsServerFlag = KAL_FALSE;
    
    bt_spp_uart_owner_ind = (bt_spp_uart_owner_ind_struct*)msg;
    
    /* PRINT_INFORMATION("MMI receives uart_owner_ind, set owner now"); */
    /* Set the uart port owner module as MOD_MMI,
      * But the SPP Client Application may change the uart port owner upon receipt the message uart_owner_ind 
      * The SPP Client Application must be resonsible for sending uart_owner_cnf to BT stack no matterr it changes the uart owner or not.
      * In this way, the BT stack can send uart_ready_to_read_ind to the correct module.
      */
    UART_Open(bt_spp_uart_owner_ind->port, MOD_MMI);

    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_RECV_UART_OWNER_IND,bt_spp_uart_owner_ind->port);

    IsServerFlag = IsThisPortAsSPPServer(bt_spp_uart_owner_ind->port);
    if(!IsServerFlag)
    {
        /* Notify SPP Client Application */
        for (i=0; i< NUM_SPP_CLIENTS; i++)
        {
            if(bt_spp_uart_owner_ind->port == g_mmi_spp_cntx[i].port)
            {
                app_inx = g_mmi_spp_cntx[i].app_inx;
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx);
                if(SPPClientAppTable[app_inx].bt_spp_uart_owner_ind_hdler)
                    (*SPPClientAppTable[app_inx].bt_spp_uart_owner_ind_hdler)(g_mmi_spp_cntx[i].port);
            }
        }
    }
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(bt_spp_uart_owner_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_uart_owner_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_uart_owner_ind_hdler)(bt_spp_uart_owner_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,bt_spp_uart_owner_ind->port);

        }

    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_send_uart_owner_cnf_hdler
* DESCRIPTION
*   1.This function is used to send uart_owner_cnf to BT stack by a  SPP Client's Application.
*   2.The SPP Client Application may change the uart port owner upon receipt of  the uart_owner_ind msg.
*   3.In order to let BT stack can send uart_ready_to_read_ind msg to correct uart owner Module,
*   the SPP Client Application should call the this function to notify the BT stack that it already sets the uart port owner completely.
*   Note: If the SPP Client Application changes the uart owner port, this function must be invoked after changing the uart port owner. 
*   Add by mtk01411: 2007-0708
* PARAMETERS
*  a  IN      first variable port: This is the port number which is necessary to send uart_owner_cnf for it.
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_send_uart_owner_cnf_hdler(U16 port)
{
    bt_spp_uart_owner_cnf_struct* bt_spp_uart_owner_cnf = NULL;
    bt_spp_uart_owner_cnf = construct_local_para(sizeof(bt_spp_uart_owner_cnf_struct),TD_UL);
    bt_spp_uart_owner_cnf->port = port;
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SEND_UART_OWNER_CNF,port);
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_UART_OWNER_CNF, (local_para_struct*)bt_spp_uart_owner_cnf, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_uart_readyToRead_ind_hdler
* DESCRIPTION
*   1.This function is used to handle uart_ready_to_read_ind for MMI if this uart port owner is MMI.
*   2.If the SPP Client Application has changed the uart port owner upon receipt of  the uart_owner_ind msg,
*   then this uart_ready_to_read_ind message will not be sent to MMI and processed in MMI. 
*   So the uart port owner module (not MOD_MMI) should process this uart_ready_to_read_ind message instead of MOD_MMI 
*
*   Note: If the SPP Client Application changes the uart owner port, this function must be invoked after changing the uart port owner. 
*   Add by mtk01411: 2007-0708
* PARAMETERS
*  a  IN      first variable port: It contains the port number which the data in the buffer is ready to be read.
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_uart_readyToRead_ind_hdler(void *msg)
{
    /*It should distinguish this received data is for SPP client or SPP server*/
    /*Using port number to find its portType of SPPOSDev*/
 
    uart_ready_to_read_ind_struct* uart_rtr_ind = (uart_ready_to_read_ind_struct*)msg;
    kal_uint8 i=0;
    kal_uint8 app_inx = 0;
    kal_bool IsServerFlag = KAL_FALSE;
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_RECV_UART_READY_TO_READ_IND,uart_rtr_ind->port);
    
    /*Check if MOD_MMI is the owner of this port or not: Add by mtk01411 2007-0402*/
    if(UART_GetOwnerID(uart_rtr_ind->port) != MOD_MMI) 
        return;

    IsServerFlag = IsThisPortAsSPPServer(uart_rtr_ind->port);
    if(!IsServerFlag)
    {
        /* Notify SPP Client Application: Only if the SPP Client Application has never changed uart port owner */
        for (i=0; i< NUM_SPP_CLIENTS; i++)
        {
            if(uart_rtr_ind->port == g_mmi_spp_cntx[i].port)
            {
                /* Because the SPP Client Application, so its app_inx will be recorded */
                app_inx = g_mmi_spp_cntx[i].app_inx;
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx);
                if(SPPClientAppTable[app_inx].bt_spp_uart_ready_to_read_ind_hdler)
                    (*SPPClientAppTable[app_inx].bt_spp_uart_ready_to_read_ind_hdler)(g_mmi_spp_cntx[i].port);
            }
        }
    }
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(uart_rtr_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_uart_ready_to_read_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_uart_ready_to_read_ind_hdler)(uart_rtr_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,uart_rtr_ind->port);

        }

    }
        
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    
}

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_uart_readyToWrite_ind_hdler
* DESCRIPTION
*   1.This function is used to handle uart_ready_to_write_ind for MMI if this uart port owner is MMI.
*   2.If the SPP Client Application has changed the uart port owner upon receipt of  the uart_owner_ind msg,
*   then this uart_ready_to_write_ind message will not be sent to MMI and processed in MMI.
*   So the uart port owner module (not MOD_MMI) should process this uart_ready_to_write_ind message instead of MOD_MMI    
*   
*   Note: If the SPP Client Application changes the uart owner port, this function must be invoked after changing the uart port owner. 
*   Add by mtk01411: 2007-0707
* PARAMETERS
*  a  IN      first variable msg: It contains the port number which is ready to be written to the buffer.
* RETURNS
*  void
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/

void mmi_bth_spp_uart_readyToWrite_ind_hdler(void *msg)
{
    uart_ready_to_write_ind_struct* uart_rtw_ind = (uart_ready_to_write_ind_struct*)msg;
    kal_uint8 i=0;
    kal_uint8 app_inx = 0;
    kal_bool IsServerFlag = KAL_FALSE;
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_RECV_UART_READY_TO_WRITE_IND,uart_rtw_ind->port);    

    /*Check if MOD_MMI is the owner of this port or not: Add by mtk01411 2007-0402*/
    if(UART_GetOwnerID(uart_rtw_ind->port) != MOD_MMI) 
        return;

    IsServerFlag = IsThisPortAsSPPServer(uart_rtw_ind->port);
    if(!IsServerFlag)
    {
        /* Notify SPP Client Application: Only if the SPP Client Application has never changed the uart port owner */
        for (i=0; i< NUM_SPP_CLIENTS; i++)
        {
            if(uart_rtw_ind->port == g_mmi_spp_cntx[i].port)
            {
                app_inx = g_mmi_spp_cntx[i].app_inx;
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_APP_INX,app_inx);
                if(SPPClientAppTable[app_inx].bt_spp_uart_ready_to_write_ind_hdler)
                    (*SPPClientAppTable[app_inx].bt_spp_uart_ready_to_write_ind_hdler)(g_mmi_spp_cntx[i].port);
            }
        }
    }
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(uart_rtw_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_uart_ready_to_write_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_uart_ready_to_write_ind_hdler)(uart_rtw_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,uart_rtw_ind->port);

        }

    }

}


/* Add 2007-0112 */
void mmi_bth_spp_authroize_hdler(void* msg)
{
    /* Check MS's call state */
    bt_spp_auth_rsp_struct* bt_spp_auth_rsp = NULL; 
    bt_spp_auth_req_struct* bt_spp_auth_req = (bt_spp_auth_req_struct*)msg;  
       
    bt_spp_auth_rsp = construct_local_para (sizeof(bt_spp_auth_rsp_struct),TD_UL); 
    bt_spp_auth_rsp->result = KAL_TRUE; 
    bt_spp_auth_rsp->port = bt_spp_auth_req->port;


    /* Other codes is needed modify here*/ 
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_AUTH_RSP, (local_para_struct*)bt_spp_auth_rsp, NULL);

}




/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_activate_req_hdler
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
void     mmi_bth_spp_activate_req_hdler(void)
{
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_ACTIVATE_REQ, NULL, NULL);
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_activate_cnf_hdler
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
void     mmi_bth_spp_activate_cnf_hdler(void *msg)
{
    kal_uint8 i;

    mmi_bth_activate_cnf_hdler((U32)MMI_BTH_SPP_PROFILE_UUID);

    for(i = 0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        g_mmi_spp_cntx[i].state = MMI_BTH_SPP_STAT_ACTIVATE;

 #ifdef __MMI_SPP_SCO_SUPPORT__       
        g_mmi_spp_cntx[i].audio_state = MMI_BTH_SPP_STAT_AUDIO_IDLE;
 #endif
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_deactivate_req_hdler
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
void     mmi_bth_spp_deactivate_req_hdler(void)
{
    mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_DEACTIVATE_REQ, NULL, NULL);

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_deactivate_cnf_hdler
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
void     mmi_bth_spp_deactivate_cnf_hdler(void *msg)
{
    kal_uint8 i;

    mmi_bth_deactivate_cnf_hdler((U32)MMI_BTH_SPP_PROFILE_UUID);

    for(i = 0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        g_mmi_spp_cntx[i].state = MMI_BTH_SPP_STAT_IDLE;
        g_mmi_spp_cntx[i].connect_id = 0;
        g_mmi_spp_cntx[i].port = 0;
        g_mmi_spp_cntx[i].lap = 0;
        g_mmi_spp_cntx[i].uap = 0;
        g_mmi_spp_cntx[i].nap = 0;
        g_mmi_spp_cntx[i].server_chnl_num = (S8)-1;
        g_mmi_spp_cntx[i].app_inx = 0;

#ifdef __MMI_SPP_SCO_SUPPORT__
        g_mmi_spp_cntx[i].audio_state = MMI_BTH_SPP_STAT_AUDIO_IDLE;
#endif
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_disconnect_req_hdler
* DESCRIPTION
*   This function is to request to disconnect a SPP conneciton
*
* PARAMETERS
*  a  IN/OUT      first variable device_addr: It is the bluetooth address of the remote device
*  b  IN       second variable connect_id: It is the connection_id of this SPP connection
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void        mmi_bth_spp_disconnect_req_hdler(mmi_bth_bt_addr device_addr, U32 connect_id)
{
    kal_uint8 i;
    bt_spp_disconnect_req_struct* msg_p;

    for(i = 0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        
        
        if(g_mmi_spp_cntx[i].connect_id == connect_id)
        {
            if(MMI_SPP_CHNL_ALWAYS_DISC_FIRST == 1)
                    goto send_spp_chnl_disc_req;  

#ifdef __MMI_SPP_SCO_SUPPORT__            
            if(g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_IDLE)
#endif                
            {
send_spp_chnl_disc_req:
            
            msg_p = (bt_spp_disconnect_req_struct*)
            construct_local_para(sizeof(bt_spp_disconnect_req_struct), TD_CTRL);
            msg_p->port = g_mmi_spp_cntx[i].port;

            mmi_bth_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_SPP_DISCONNECT_REQ, msg_p, NULL);

            //g_mmi_spp_cntx[i].connect_id = 0;
            //g_mmi_spp_cntx[i].port = 0;
            g_mmi_spp_cntx[i].state = MMI_BTH_SPP_STAT_DISCONNECT_REQ;
            //g_mmi_spp_cntx[i].lap = 0;
            //g_mmi_spp_cntx[i].uap = 0;
            //g_mmi_spp_cntx[i].nap = 0;
            }
            
#ifdef __MMI_SPP_SCO_SUPPORT__            
            else if (g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_CONNECTED)
            {
                U8 rc = 0;
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_AUDIO_LINK_FIRST);
                g_mmi_spp_cntx[i].state = MMI_BTH_SPP_STAT_DISC_AUDIO_LINK_FRIST_THEN_DISC_SPP_CHNL;
                rc = mmi_bth_spp_audio_disconnect_req(g_mmi_spp_cntx[i].port);
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_AUDIO_LINK_RC,rc);
                
            }
            else if (g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_DISCONNECT_REQ)
            {
                /* If the Audio Link is disconnecting:
                  * This SPP Chnl disconenct request will be rejected !
                  * SPP Application must wait for Audio disconnect cnf, then does spp chl disconnect request again !
                  */
                return; 
            }
            else
            {
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_REQ_HDLER_AUDIO_STATE,g_mmi_spp_cntx[i].audio_state);

            }
            
#endif /* end #ifdef __MMI_SPP_SCO_SUPPORT__ */  

            break;
        }

    }

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_disconnect_cnf_hdler
* DESCRIPTION
*   1.This function is to notify the disconnection_cnf message 
*   2. If this SPP conneciton is requested by a SPP Client Application previously,
     it is time to callback to it upon receipt of disconnection_cnf message
     3. The callback function registered by a SPP Client Application can be found via the app_inx of the table SPPClientAppTable
     4. The app_inx can be obtained via search of the array g_mmi_spp_cntx with comparsion of state, bt_address and port number.
* PARAMETERS
*  a  IN/OUT      first variable msg: It contains the result of SPP disconneciton
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_spp_disconnect_cnf_hdler(void *msg)
{
    kal_uint8 i;
    kal_bool result = KAL_FALSE;
    kal_bool IsServerFlag = KAL_FALSE;
    bt_spp_disconnect_cnf_struct* mmi_bt_spp_disconnect_cnf = (bt_spp_disconnect_cnf_struct*)msg; 
    kal_uint8 app_inx = 0;
    kal_bool notifed_client = KAL_FALSE;

    if(mmi_bt_spp_disconnect_cnf->result > 0)
        result = KAL_FALSE;
    else if(mmi_bt_spp_disconnect_cnf->result == 0)
        result = KAL_TRUE;
    
    IsServerFlag = IsThisPortAsSPPServer(mmi_bt_spp_disconnect_cnf->port);

    for(i = 0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        if( (g_mmi_spp_cntx[i].state == MMI_BTH_SPP_STAT_DISCONNECT_REQ)
            /*
            && (g_mmi_spp_cntx[i].lap == mmi_bt_spp_disconnect_cnf->lap)
            && (g_mmi_spp_cntx[i].nap == mmi_bt_spp_disconnect_cnf->nap)
            && (g_mmi_spp_cntx[i].uap == mmi_bt_spp_disconnect_cnf->uap)
            */
            && (g_mmi_spp_cntx[i].port == mmi_bt_spp_disconnect_cnf->port)
          )
        {



        
            mmi_bth_disconnect_cnf_hdler(   result, 
                                            g_mmi_spp_cntx[i].lap,
                                            g_mmi_spp_cntx[i].uap,
                                            g_mmi_spp_cntx[i].nap, 
                                            MMI_BTH_SPP_PROFILE_UUID, 
                                            g_mmi_spp_cntx[i].connect_id);

            if(g_mmi_spp_cntx[i].server_chnl_num!= -1)
            {
                /*This is disconnection cnf is for SPP Client*/
                notifed_client = KAL_TRUE;
                app_inx = g_mmi_spp_cntx[i].app_inx;
            }  
            g_mmi_spp_cntx[i].state = MMI_BTH_SPP_STAT_ACTIVATE;

#ifdef __MMI_SPP_SCO_SUPPORT__
            if(g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_IDLE)
#endif
            { 
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_CNF_HDLER_RESET_ENTRY);
                
                if(g_mmi_spp_cntx[i].server_chnl_num!= -1)
                    mmi_bth_current_spp_client_num--;
#if 0                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                
                mmi_bth_reset_spp_entry(i); 
            }
#ifdef __MMI_SPP_SCO_SUPPORT__            
            else
            {
                /* DO NOT Reset this entry due to it will be used under AUDIO_DISCONNECT_CNF/IND callback */
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_CNF_HDLER_NOT_RESET_ENTRY, g_mmi_spp_cntx[i].audio_state);
                MMI_BT_ASSERT(0);
            }
#endif /* end #ifdef __MMI_SPP_SCO_SUPPORT__ */  

            break;
            
          
        }
    }
       
    /* Notify SPP Client Application */
    if(!IsServerFlag)
    {
        for(i=0; i < NUM_SPP_CLIENTS; i++)
        { 
            if((i == app_inx) || (SPPClientAppTable[i].always_notified == KAL_TRUE))
            {
                if(SPPClientAppTable[i].bt_spp_disconnect_cnf_hdler)
                    (*SPPClientAppTable[i].bt_spp_disconnect_cnf_hdler)(result);
            }   
        }
    }
       
    

}
/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_disconnect_ind_hdler
* DESCRIPTION
*   This function is to report the termination of one SPP connection
*
* PARAMETERS
*  a  IN      first variable msg: It contains the connection_ind of SPP connection which has been terminated
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void     mmi_bth_spp_disconnect_ind_hdler(void *msg)
{
    bt_spp_disconnect_ind_struct *mmi_bt_spp_disconnect_ind = (bt_spp_disconnect_ind_struct *)msg;
    kal_uint8 i;
    kal_uint8 app_inx=0; 
    kal_bool notified_client = KAL_FALSE;
    kal_bool IsServerFlag = KAL_FALSE;

    IsServerFlag = IsThisPortAsSPPServer(mmi_bt_spp_disconnect_ind->port);

    for(i = 0; i < MMI_BTH_SPP_MAX_CONNECTION; i++)
    {
        if(g_mmi_spp_cntx[i].port == mmi_bt_spp_disconnect_ind->port)
        {
            if(g_mmi_spp_cntx[i].state == MMI_BTH_SPP_STAT_DISCONNECT_REQ)
            {
                mmi_bth_disconnect_cnf_hdler(KAL_TRUE, 
                    g_mmi_spp_cntx[i].lap,
                    g_mmi_spp_cntx[i].uap,
                    g_mmi_spp_cntx[i].nap,
                    MMI_BTH_SPP_PROFILE_UUID,
                    g_mmi_spp_cntx[i].connect_id);

            }
            else 
            {
                mmi_bth_disconnect_ind_hdler(  
                    g_mmi_spp_cntx[i].lap,
                    g_mmi_spp_cntx[i].uap,
                    g_mmi_spp_cntx[i].nap,
                    MMI_BTH_SPP_PROFILE_UUID,
                    g_mmi_spp_cntx[i].connect_id);
            }


            if(g_mmi_spp_cntx[i].server_chnl_num !=-1)
            {
                /*This is disconnection ind is for SPP Client*/
                notified_client = KAL_TRUE;
                app_inx = g_mmi_spp_cntx[i].app_inx;
            }

#ifdef __MMI_SPP_SCO_SUPPORT__            
            if(g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_IDLE)
#endif                
            {
               MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_IND_HDLER_RESET_ENTRY); 
                
               if(g_mmi_spp_cntx[i].server_chnl_num !=-1)
                    mmi_bth_current_spp_client_num--;
#if 0               
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                 
                mmi_bth_reset_spp_entry(i);  
            }

#ifdef __MMI_SPP_SCO_SUPPORT__   
            else if (g_mmi_spp_cntx[i].audio_state == MMI_BTH_SPP_STAT_AUDIO_CONNECTED)
            {
                /* Note: 2007-0717
                  * In this case: The remote device disconnects SPP chnl first,
                  * The audio link should be disconnect due to the SPP chnl terminated.
                  * Because the registered SCO handler is removed when SPP chnl is closed,
                  * the result of this sco disconneciton request will not be reported to MMI.
                  *
                  * Although it is possible to receive disc_ind instead of disc_cnf for disc_req,
                  * But for our design:
                  * If we sends spp chnl disconnect req, then the audio link will be disconnected first.
                  * It is possible to enter this case (audio link is still connected)
                  * In this case: disc_ind is due to remote device terminates spp chnl connection
                  */
                  U8 rc = 0;
                  
                  rc = mmi_bth_spp_audio_disconnect_req(g_mmi_spp_cntx[i].port);
                  if(rc != MMI_BTH_ACCEPT_SPP_AUDIO_CONNECT)
                        MMI_BT_ASSERT(0);
                  
                  /* Reset this entry: Due to SPP chnl is already disconnected. 
                    * No audio_disconnect_cnf will be sent from BT stack and no callback will be invoked by BTMMISPP for SPP Application
                    */
                  if(g_mmi_spp_cntx[i].server_chnl_num !=-1)
                        mmi_bth_current_spp_client_num--;  
                  mmi_bth_reset_spp_entry(i);  
            }
            else
            {
                /* DO NOT Reset this entry due to it will be used under AUDIO_DISCONNECT_CNF/IND callback */
                MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_DISC_IND_HDLER_NOT_RESET_ENTRY, g_mmi_spp_cntx[i].audio_state);
                if(g_mmi_spp_cntx[i].server_chnl_num !=-1)
                        mmi_bth_current_spp_client_num--;  
                mmi_bth_reset_spp_entry(i);  

                MMI_BT_ASSERT(0);  
    
            }
            
#endif /* end #ifdef __MMI_SPP_SCO_SUPPORT__ */

            break;

        }

    }

    /* Notify SPP Client Application */
    if(!IsServerFlag)
    {
        for(i=0; i < NUM_SPP_CLIENTS; i++)
        { 
            if((i == app_inx) || (SPPClientAppTable[i].always_notified == KAL_TRUE))
            {
                if(SPPClientAppTable[i].bt_spp_disconnect_ind_hdler)
                    (*SPPClientAppTable[i].bt_spp_disconnect_ind_hdler)();
            }
        }    

}
    else
    {
        kal_int8 inx =0;
         /* Check if it is necessary to notify SPP Server Application or not */
        inx = search_inx_of_spp_server_app_registerfunc_table(mmi_bt_spp_disconnect_ind->port);
        if(inx != -1)
        {
            if(SPPServerAppTable[inx].bt_spp_disconnect_ind_hdler)
                (*SPPServerAppTable[inx].bt_spp_disconnect_ind_hdler)(mmi_bt_spp_disconnect_ind->port);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVICE_NOT_REG_CALLBACK_FUNC,mmi_bt_spp_disconnect_ind->port);

        }


    }

}

#ifdef  __MMI_SPP_CLIENT_USAGE_DEMO__

U16 SPPClientSendFirstDataPattern(U16 port)
{
    kal_uint16 returnWriteLen = 0;
    kal_uint8 WRingBuf[51];
    kal_uint8 pattern_len = 0;
    memset(WRingBuf, 0, 51);
    memcpy(WRingBuf, (const U8*)BtGet_SPPClientFirstConnDataPattern(&pattern_len), pattern_len);
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_CLIENT_SEND_FIRST_DATA);
    returnWriteLen = UART_PutBytes(port, (kal_uint8*)WRingBuf, pattern_len, MOD_MMI);
    if(returnWriteLen!= pattern_len)
        MMI_BT_ASSERT(0);
}

/* The following example functions are used for SPPClient Application */

void SPPClientApp1_SDP_Result_Ind_CB(kal_uint8 srv_chnl_num)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_SDP_RESULT_IND_CB);
}
void SPPClientApp1_SDP_Search_Cnf_CB(kal_uint8 result)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_SDP_SEARCH_CNF_CB);
}
void SPPClientApp1_Connect_Cnf_CB(U8 result,U8 server_chnl_num,U8 con_id,U16 port,mmi_bth_bt_addr bd_addr)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_CONNECT_CNF_CB);
}
void SPPClientApp1_Uart_Owner_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_UART_OWNER_IND_CB);
    mmi_bth_spp_send_uart_owner_cnf_hdler(port);

#ifdef __MMI_SPP_SCO_SUPPORT__    
    if(MMI_SPP_SDP_ATD_TYPE == 1)
    {     
        
        SPPClientSendFirstDataPattern(port);
    }
#endif

}
void SPPClientApp1_Uart_Ready_To_Read_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_UART_READY_TO_READ_IND_CB);
}
void SPPClientApp1_Uart_Ready_To_Write_Ind_CB(U16 port)
{
     MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_UART_READY_TO_WRITE_IND_CB);
}
void SPPClientApp1_Uart_Plugout_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_UART_PLUGOUT_IND_CB);
    UART_SetOwner(port,MOD_MMI);
    mmi_bth_spp_send_uart_plugout_cnf_hdler(port);
}
void SPPClientApp1_Disconnect_Ind_CB(void)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_DISCONNECT_IND_CB);
}
void SPPClientApp1_Disconnect_Cnf_CB(kal_bool result)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_DISCONNECT_CNF_CB);
}

#ifdef __MMI_SPP_SCO_SUPPORT__

/*****************************************************************************
* FUNCTION
*  mmi_bth_spp_sco_rssi_ind_hdler
* DESCRIPTION
*   This function is to report the rssi value sent from btstack
*
* PARAMETERS
*  a  IN      first variable msg: It contains the rssi_ind of SPP connection which has been terminated
* RETURNS
*  NONE.
* GLOBALS AFFECTED
*   external_global
*****************************************************************************/
void mmi_bth_spp_sco_rssi_ind_hdler(void* msg)
{
    bt_spp_sco_rssi_ind_struct* rssi_ind = (bt_spp_sco_rssi_ind_struct*)msg;
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SCO_RSSI_VAL,rssi_ind->bd_address[0],rssi_ind->bd_address[1],rssi_ind->bd_address[2],rssi_ind->bd_address[3],rssi_ind->bd_address[4],rssi_ind->bd_address[5],rssi_ind->rssi_value);
}

void SPPClientApp1_Audio_Connect_Cnf_CB(kal_uint8 result, kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_AUDIO_CONNECT_CNF_CB);
}
void SPPClientApp1_Audio_Connect_Ind_CB(kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_AUDIO_CONNECT_IND_CB);
}
void SPPClientApp1_Audio_Disconnect_Cnf_CB(kal_uint8 result, kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_AUDIO_DISCONNECT_CNF_CB);
}
void SPPClientApp1_Audio_Disconnect_Ind_CB(kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_SPP_CLIENT_APP_AUDIO_DISCONNECT_IND_CB);
}
#endif

/* The following example functions are used for SPPServer Application   */
void SPPServerApp1_Connect_Ind_CB(U8 con_id,U16 port,mmi_bth_bt_addr bd_addr)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_CONNECT_IND_CB);
}
void SPPServerApp1_Uart_Owner_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_UART_OWNER_IND_CB);
    mmi_bth_spp_send_uart_owner_cnf_hdler(port);
}
void SPPServerApp1_Uart_Ready_To_Read_Ind_CB(U16 port)
{
    kal_uint16 returnReadLen = 0;
    kal_uint8 status =0;
    kal_uint8 RRingBuf[51];
    kal_bool IsServerFlag = KAL_FALSE;
    kal_uint8 pattern_len = 0;

    memset(RRingBuf, 0, 51);
    
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_UART_READY_TO_READ_IND_CB);
    if(UART_GetOwnerID(port) != MOD_MMI)
        return;

    returnReadLen = UART_GetBytes(port, RRingBuf, 50, &status, MOD_MMI);
    PRINT_INFORMATION("MMI Recv UART_READY_TO_READ_IND, SPP Srv Recv Data=%s",RRingBuf);
       
}
void SPPServerApp1_Uart_Ready_To_Write_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_UART_READY_TO_WRITE_IND_CB);
}
void SPPServerApp1_Uart_Plugout_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_UART_PLUGOUT_IND_CB);
    mmi_bth_spp_send_uart_plugout_cnf_hdler(port);
}
void SPPServerApp1_Disconnect_Ind_CB(U16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_DISCONNECT_IND_CB);
}

#ifdef __MMI_SPP_SCO_SUPPORT__
void SPPServerApp1_Audio_Connect_Cnf_CB(kal_uint8 result, kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_AUDIO_CONNECT_CNF_CB);
}
void SPPServerApp1_Audio_Connect_Ind_CB(kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_AUDIO_CONNECT_IND_CB);
}
void SPPServerApp1_Audio_Disconnect_Cnf_CB(kal_uint8 result, kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_AUDIO_DISCONNECT_CNF_CB);
}
void SPPServerApp1_Audio_Disconnect_Ind_CB(kal_uint16 port)
{
    MMI_TRACE(MMI_TRACE_G7_MISC,MMI_SPP_SERVER_APP_AUDIO_DISCONNECT_IND_CB);
}
#endif /* end #ifdef __MMI_SPP_SCO_SUPPORT__   */
#endif /* end #ifedf __MMI_SPP_CLIENT_USAGE_DEMO__ */

#endif //__MMI_SPP_SUPPORT__
#endif //__MMI_BT_MTK_SUPPORT__
