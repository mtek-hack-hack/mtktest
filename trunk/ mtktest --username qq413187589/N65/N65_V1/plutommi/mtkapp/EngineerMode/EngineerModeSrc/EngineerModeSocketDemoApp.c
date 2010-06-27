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
 * EngineerModeSocketDemoApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode socket demo application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#if (defined(__MMI_ENGINEER_MODE__) && defined(__TCPIP__))

#if !defined(__MTK_TARGET__)
#include <windows.h>
#endif 
#include "MMI_include.h"

/**********************/
/*****  Header Files *****/
/**********************/

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "MainMenuDef.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeProt.h"
#include "CustomCfg.h"
#include "audioInc.h"
#include "IdleAppDef.h"
#include "BootUp.h"
// #include "Profiles_prot.h"

#include "app2soc_struct.h"
#include "EngineerModeSocketAppPing.h"

soc_demo_app_transaction_struct *soc_demo_transaction = NULL;

/* Engineer Mode Socket Demo Application core functions */
int mmi_soc_demo_app_request(
        mmi_soc_demo_app_enum app_id,
        int account_id,
        char server_ip_address[4],
        char *url,
        int url_len,
        char *echo_text,
        int echo_text_len,
        mmi_soc_demo_app_rsp_t callback);

int mmi_soc_demo_app_request_abort(void);
void en_soc_output_result(int ret, char *out_str, int len);

/* HTTP apllication functions */
int en_soc_demo_http_send_request(void);
void en_soc_demo_tcp_app_recv_response(void);

/* DAYTIME and ECHO apllication functions */
int en_soc_demo_udp_app_send_request(void);
void en_soc_demo_udp_app_recv_response(void);

/* DNS apllication functions */
void en_soc_demo_get_host_by_name(mmi_soc_demo_app_enum app_id, const kal_uint8 *hostname);
void em_soc_demo_app_soc_get_host_by_name_ind(void *inMsg);

/* Socket handle functions */
kal_bool en_soc_demo_app_create_socket(void);
void em_soc_demo_app_socket_notify(void *inMsg);

/* timer event handler */
void em_soc_demo_app_start_timer(void);
void em_soc_demo_app_stop_timer(void);
void em_soc_demo_app_timer_handler(void);

/* misc function */
soc_demo_app_http_url_struct *en_soc_demo_http_get_parsed_url(const kal_int8 *in_str, int in_str_len);

/* external functions */
extern void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr);
extern void StopTimer(U16 timerid);

/* icmp tracert functions */
void em_soc_demo_icmp_recv_response(void);
void em_soc_demo_icmp_send_request(kal_int8 seq_number, kal_int8 socket_id, sockaddr_struct *server_ip_addr, kal_uint8 *icmp_data, kal_uint32 icmp_data_length);
mmi_soc_demo_app_addr_type_enum em_soc_demo_app_get_addr_type(kal_uint8 *addr, kal_int32 len, kal_uint8 *ip_addr);
kal_int8 em_soc_demo_icmp_set_ttl(kal_int8 socket_id, kal_uint8 ttl);
int em_soc_icmp_send_hdlr(mmi_soc_icmp_send_type_enum send_type);
void em_soc_icmp_sent_hdlr(void);
void em_soc_icmp_recv_ind_hdlr(kal_int8 *socket_id, kal_uint8 **rec_data);
void em_soc_icmp_receive_hdlr(sockaddr_struct *rsp_addr);
void em_soc_icmp_timer_hdlr(void);
void em_soc_icmp_error_hdlr(int ret);
void em_soc_icmp_dns_hdlr(kal_uint8 *addr, kal_uint8 len);
void em_soc_icmp_exp_hdlr(void);
kal_int32 em_soc_icmp_init_soc(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_soc_demo_app_request
 * DESCRIPTION
 *  MMI calls this function to send request to server in internet.
 *  This function will start a request and response transaction.
 *  When a transaction  already exists, the function will return Busy.
 * PARAMETERS
 *  app_id                  [IN]        Is ECHO,please specify server_ip_address[4], *echo_text and echo_text_len.
 *  account_id              [IN]        
 *  server_ip_address       [?]         
 *  url                     [?]         And *exco_text. They will be freed when the request-response transaction ends.
 *  url_len                 [IN]        
 *  echo_text               [?]         int echo_text_len
 *  echo_text_len           [IN]        
 *  callback                [IN]        
 *  char server_ip_address[4],(?)
 *  Note that following items.(?)
 * RETURNS
 *  0, EN_SOC_SUCCESS
 *  -1, EN_SOC_NO_MEMORY
 *  -2, EN_SOC_BUSY
 *  -3, EN_SOC_UNKNOWN_APP
 *  -4, EN_SOC_BEARER_FAIL
 *  -5, EN_SOC_CNT_RESET_BY_PEER
 *  -6, EN_SOC_PEER_NO_RESPONSE
 *  -7, EN_SOC_PEER_NOT_REACHABLE
 *  -8, EN_SOC_ERROR
 *  -9, EN_SOC_INVAL_PARA
 *****************************************************************************/
int mmi_soc_demo_app_request(
        mmi_soc_demo_app_enum app_id,
        int account_id,
        char server_ip_address[4],
        char *url,
        int url_len,
        char *echo_text,
        int echo_text_len,
        mmi_soc_demo_app_rsp_t callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction)
    {
        kal_print("Transaction existed!!");
        return EN_SOC_BUSY;
    }
    else
    {
        if ((soc_demo_transaction = OslMalloc(sizeof(soc_demo_app_transaction_struct))) == NULL)
        {
            kal_print("No memory");
            en_soc_output_result(EN_SOC_NO_MEMORY, NULL, 0);
            return EN_SOC_NO_MEMORY;
        }
        else
        {
            memset(soc_demo_transaction, 0, sizeof(soc_demo_app_transaction_struct));
            if ((soc_demo_transaction->rcvd_buffer = OslMalloc(MAX_RCV_BUFFER_SIZE)) == NULL)
            {
                kal_print("No memory");
                en_soc_output_result(EN_SOC_NO_MEMORY, NULL, 0);
                return EN_SOC_NO_MEMORY;
            }
            else
            {
                if ((soc_demo_transaction->snd_buffer = OslMalloc(MAX_SND_BUFFER_SIZE)) == NULL)
                {
                    kal_print("No memory");
                    en_soc_output_result(EN_SOC_NO_MEMORY, NULL, 0);
                    return EN_SOC_NO_MEMORY;
                }
                else
                {
                    /* Set  initial values to soc_demo_transaction */
                    memset((kal_int8*) soc_demo_transaction->rcvd_buffer, 0, MAX_RCV_BUFFER_SIZE);
                    memset((kal_int8*) soc_demo_transaction->snd_buffer, 0, MAX_SND_BUFFER_SIZE);

                    soc_demo_transaction->soc_demo_app_id = app_id;
                    soc_demo_transaction->nwt_acount_id = account_id;
                    if (server_ip_address)
                    {
                        memcpy(soc_demo_transaction->server_ip_addr.addr, server_ip_address, 4);
                        soc_demo_transaction->server_ip_addr.addr_len = 4;
                    }
                    soc_demo_transaction->url = (kal_int8*) url;
                    soc_demo_transaction->url_len = url_len;
                    soc_demo_transaction->snd_counter = 0;
                    soc_demo_transaction->rcvd_counter = 0;
                    soc_demo_transaction->callback = callback;
                    if (echo_text)
                    {
                        if (echo_text_len > MAX_SND_BUFFER_SIZE)
                        {
                            memcpy(soc_demo_transaction->snd_buffer, echo_text, MAX_SND_BUFFER_SIZE);
                            soc_demo_transaction->snd_data_len = MAX_SND_BUFFER_SIZE;
                        }
                        else
                        {
                            memcpy(soc_demo_transaction->snd_buffer, echo_text, echo_text_len);
                            soc_demo_transaction->snd_data_len = echo_text_len;
                        }

                        OslMfree(echo_text);
                    }
                    if (en_soc_demo_app_create_socket() == KAL_FALSE)
                    {
                        en_soc_output_result(EN_SOC_NO_MEMORY, NULL, 0);
                        return EN_SOC_NO_MEMORY;
                    }

                    switch (app_id)
                    {
                        case HTTP:
                        {
                            soc_demo_transaction->state = HTTP_DNS_QUERY;
                            return en_soc_demo_http_send_request();
                        }
                        case DNS:
                        {
                            (void)en_soc_demo_get_host_by_name(DNS, (kal_uint8*) soc_demo_transaction->url);
                            return EN_SOC_SUCCESS;
                        }
                        case DAYTIME:
                        {
                            soc_demo_transaction->server_ip_addr.port = SOC_DAYTIME_RESVD_PORT;
                            soc_demo_transaction->snd_data_len = 10;    /* garbage data */
                            return en_soc_demo_udp_app_send_request();
                        }
                        case ECHO:
                        {
                            soc_demo_transaction->server_ip_addr.port = SOC_ECHO_RESVD_PORT;
                            return en_soc_demo_udp_app_send_request();
                        }
                        case TRACERT:
                        {
                            if (em_soc_icmp_init_soc() < 0)
                            {
                                return EN_SOC_ERROR;
                            }
                            
                            memset(soc_demo_transaction->server_ip_addr.addr,0,MAX_SOCK_ADDR_LEN);
                            if (
                                em_soc_demo_app_get_addr_type((kal_uint8*)url, url_len, soc_demo_transaction->server_ip_addr.addr)
                                == SOC_ADDR_TYPE_DNAME )
                            {
                                soc_demo_transaction->state = HTTP_DNS_QUERY;
                                en_soc_demo_get_host_by_name(TRACERT, (kal_uint8*)soc_demo_transaction->url);
                                return EN_SOC_SUCCESS;
                            }
                            else
                            {
                                char str[64];
                                memset(str,0,64);
                                kal_sprintf(
                                    str,
                                    " %d.%d.%d.%d\n",
                                    soc_demo_transaction->server_ip_addr.addr[0],
                                    soc_demo_transaction->server_ip_addr.addr[1],
                                    soc_demo_transaction->server_ip_addr.addr[2],
                                    soc_demo_transaction->server_ip_addr.addr[3]
                                );
                                EmStartTraceRtResult(str);
                                soc_demo_transaction->state = REQ_SENT;
                                StartTimer(EM_GPRS_SOC_DEMO_APP_TIMER, SOC_DEMO_APP_POST_TIMEOUT, em_soc_icmp_timer_hdlr);
                                em_soc_icmp_send_hdlr(SOC_ICMP_SEND_NORMAL);
                                return EN_SOC_SUCCESS;
                            }
                        }
                        default:
                        {
                            en_soc_output_result(EN_SOC_UNKNOWN_APP, NULL, 0);
                            return EN_SOC_UNKNOWN_APP;
                        }

                    }
                }

            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_output_result
 * DESCRIPTION
 *  This function is used to output the transaction result.
 *  It will call user's callback function and then release all resources.
 * PARAMETERS
 *  ret         [IN]        
 *  out_str     [?]         
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void en_soc_output_result(int ret, char *out_str, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction)
    {
        kal_prompt_trace(MOD_MMI, "soc demp app result: %d", ret);
        soc_demo_transaction->callback(soc_demo_transaction->soc_demo_app_id, ret, out_str, len);
        if (ret != EN_SOC_SUCCESS)
        {
            soc_demo_transaction->state = SOC_CLOSING;
        }
        mmi_soc_demo_app_request_abort();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_soc_demo_app_request_abort
 * PARAMETERS
 *  void
 * RETURNS
 *  int result,
 *  0, EN_SOC_SUCCESS
 *  -1, EN_SOC_NO_MEMORY
 *  -2, EN_SOC_BUSY
 *  -3, EN_SOC_UNKNOWN_APP
 *  -4, EN_SOC_BEARER_FAIL
 *  -5, EN_SOC_CNT_RESET_BY_PEER
 *  -6, EN_SOC_PEER_NO_RESPONSE
 *  -7, EN_SOC_PEER_NOT_REACHABLE
 *  -8, EN_SOC_ERROR
 *  -9, EN_SOC_INVAL_PARA
 *****************************************************************************/
int mmi_soc_demo_app_request_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction)
    {
        if (soc_demo_transaction->socket_id >= 0)
        {
            ilm_struct *ilm_send = NULL;
            soc_close(soc_demo_transaction->socket_id);
            soc_close_nwk_account_by_id(MOD_MMI,soc_demo_transaction->nwt_acount_id);
            /* close socket and disconnect bearer here */
            ilm_send = allocate_ilm(MOD_MMI);
            ilm_send->msg_id = MSG_ID_APP_SOC_DEACTIVATE_REQ;
            ilm_send->peer_buff_ptr = NULL;
            ilm_send->local_para_ptr = NULL;
            SEND_ILM(MOD_MMI, MOD_SOC, SOC_APP_SAP, ilm_send);
        }
        soc_demo_transaction->post_retry_counter = 0;
        if (soc_demo_transaction->url)
        {
            OslMfree(soc_demo_transaction->url);
        }
        /* We have to free recv_buffer. */
        if (soc_demo_transaction->rcvd_buffer)
        {
            OslMfree(soc_demo_transaction->rcvd_buffer);
        }
        if (soc_demo_transaction->snd_buffer)
        {
            OslMfree(soc_demo_transaction->snd_buffer);
        }
        if (soc_demo_transaction->url_parsed_info)
        {
            if (soc_demo_transaction->url_parsed_info->host_name)
            {
                OslMfree(soc_demo_transaction->url_parsed_info->host_name);
            }
            if (soc_demo_transaction->url_parsed_info->url_link)
            {
                OslMfree(soc_demo_transaction->url_parsed_info->url_link);
            }
            OslMfree(soc_demo_transaction->url_parsed_info);
        }
        em_soc_demo_app_stop_timer();
        OslMfree(soc_demo_transaction);
        soc_demo_transaction = NULL;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_http_send_request
 * DESCRIPTION
 *  This fucntion is used to send HTTP request to specific server.
 *  And receive server's response.
 *  If SOC can't receive any data for now, SOC will send MSG_ID_APP_SOC_NOTIFY_IND to MMI.
 *  Then MMI will call em_soc_demo_app_socket_notify() to receive incoming data.
 * PARAMETERS
 *  void
 * RETURNS
 *  0, EN_SOC_SUCCESS
 *  -1, EN_SOC_NO_MEMORY
 *  -2, EN_SOC_BUSY
 *  -3, EN_SOC_UNKNOWN_APP
 *  -4, EN_SOC_BEARER_FAIL
 *  -5, EN_SOC_CNT_RESET_BY_PEER
 *  -6, EN_SOC_PEER_NO_RESPONSE
 *  -7, EN_SOC_PEER_NOT_REACHABLE
 *  -8, EN_SOC_ERROR
 *  -9, EN_SOC_INVAL_PARA
 *****************************************************************************/
int en_soc_demo_http_send_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction)
    {
        if (soc_demo_transaction->state == HTTP_DNS_QUERY &&
            (soc_demo_app_http_url_struct*) soc_demo_transaction->url_parsed_info == NULL)
        {
            soc_demo_transaction->url_parsed_info =
                (soc_demo_app_http_url_struct*) en_soc_demo_http_get_parsed_url(
                                                    soc_demo_transaction->url,
                                                    soc_demo_transaction->url_len);
            if (soc_demo_transaction->url_parsed_info)
            {

                (void)en_soc_demo_get_host_by_name(
                        HTTP,
                        (kal_uint8*) soc_demo_transaction->url_parsed_info->host_name);
                return EN_SOC_SUCCESS;
            }
            else
            {
                en_soc_output_result(EN_SOC_INVAL_PARA, NULL, 0);
                return EN_SOC_INVAL_PARA;
            }
        }
        else if (soc_demo_transaction->state == HTTP_TCP_CON_CREATING)
        {
            kal_int8 ret;

            char CRLF[3] = {0x0d, 0x0a, 0x00};
            soc_demo_transaction->state = HTTP_TCP_CON_CREATED;
            /* Create HTTP Get Message */

            soc_demo_transaction->snd_data_len = 0;
            strcat(soc_demo_transaction->snd_buffer, "GET ");
            soc_demo_transaction->snd_data_len += 4;

            if (soc_demo_transaction->url_parsed_info->url_link)
            {
                strcat(
                    (char*)soc_demo_transaction->snd_buffer,
                    (char*)soc_demo_transaction->url_parsed_info->url_link);
                soc_demo_transaction->snd_data_len += soc_demo_transaction->url_parsed_info->url_link_len;

                strcat((char*)soc_demo_transaction->snd_buffer, " ");
                soc_demo_transaction->snd_data_len += 2;
            }
            else
            {
                strcat((char*)soc_demo_transaction->snd_buffer, "/ ");
                soc_demo_transaction->snd_data_len += 2;
            }

            strcat((char*)soc_demo_transaction->snd_buffer, "HTTP/1.1");
            soc_demo_transaction->snd_data_len += 8;

            strcat((char*)soc_demo_transaction->snd_buffer, CRLF);
            soc_demo_transaction->snd_data_len += 2;

            strcat((char*)soc_demo_transaction->snd_buffer, "Host: ");
            soc_demo_transaction->snd_data_len += 6;

            strcat((char*)soc_demo_transaction->snd_buffer, (char*)soc_demo_transaction->url_parsed_info->host_name);
            soc_demo_transaction->snd_data_len += soc_demo_transaction->url_parsed_info->host_name_len;

            strcat((char*)soc_demo_transaction->snd_buffer, CRLF);
            soc_demo_transaction->snd_data_len += 2;

            strcat((char*)soc_demo_transaction->snd_buffer, "Connection: Closed");
            soc_demo_transaction->snd_data_len += 18;

            strcat((char*)soc_demo_transaction->snd_buffer, CRLF);
            soc_demo_transaction->snd_data_len += 2;

            strcat((char*)soc_demo_transaction->snd_buffer, CRLF);
            soc_demo_transaction->snd_data_len += 2;

            soc_demo_transaction->server_ip_addr.port = soc_demo_transaction->url_parsed_info->ser_port_num;

            kal_prompt_trace(
                MOD_MMI,
                "Http connect to %d.%d,%d,%d and port: %d",
                soc_demo_transaction->server_ip_addr.addr[0],
                soc_demo_transaction->server_ip_addr.addr[1],
                soc_demo_transaction->server_ip_addr.addr[2],
                soc_demo_transaction->server_ip_addr.addr[3],
                soc_demo_transaction->server_ip_addr.port);
            ret = soc_connect(soc_demo_transaction->socket_id, &soc_demo_transaction->server_ip_addr);
            kal_prompt_trace(MOD_MMI, "Http connect result is %d", ret);
            if (ret == SOC_SUCCESS)
            {
                en_soc_demo_http_send_request();
                return EN_SOC_SUCCESS;
            }
            else if (ret == SOC_WOULDBLOCK)
            {
                SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
                return EN_SOC_SUCCESS;
            }
            else
            {
                if (ret == SOC_ERROR)
                {
                    en_soc_output_result(EN_SOC_PEER_NOT_REACHABLE, NULL, 0);
                    return EN_SOC_PEER_NOT_REACHABLE;
                }
                else
                {
                    en_soc_output_result(EN_SOC_ERROR, NULL, 0);
                    return EN_SOC_ERROR;
                }
            }
        }
        else if (soc_demo_transaction->state == HTTP_TCP_CON_CREATED || soc_demo_transaction->state == REQ_SEND_RETRY ||
                 soc_demo_transaction->state == REQ_SENDING)
        {
            kal_int32 ret;

            if (soc_demo_transaction->state != REQ_SENDING)
            {
                soc_demo_transaction->snd_counter = 0;
            }
            soc_demo_transaction->state = REQ_SENDING;
            kal_prompt_trace(
                MOD_MMI,
                "Http send request to %d.%d,%d,%d and port: %d",
                soc_demo_transaction->server_ip_addr.addr[0],
                soc_demo_transaction->server_ip_addr.addr[1],
                soc_demo_transaction->server_ip_addr.addr[2],
                soc_demo_transaction->server_ip_addr.addr[3],
                soc_demo_transaction->server_ip_addr.port);
            ret = soc_send(
                    soc_demo_transaction->socket_id,
                    (kal_uint8*) (soc_demo_transaction->snd_buffer + soc_demo_transaction->snd_counter),
                    (soc_demo_transaction->snd_data_len - soc_demo_transaction->snd_counter),
                    0);
            kal_prompt_trace(MOD_MMI, "Http send request result, sent_bytes:%d", ret);
            if (ret > 0)
            {
                if (ret == (kal_int32) soc_demo_transaction->snd_data_len)
                {
                    soc_demo_transaction->state = REQ_SENT;
                    soc_demo_transaction->post_retry_counter++;
                    em_soc_demo_app_start_timer();  /* wait for servwer's response */
                    en_soc_demo_tcp_app_recv_response();
                    return EN_SOC_SUCCESS;
                }
                else
                {
                    soc_demo_transaction->snd_counter += ret;
                    return EN_SOC_SUCCESS;
                }
            }
            else
            {
                if (ret == SOC_WOULDBLOCK)
                {
                    /* waits for socket notify */
                    SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
                    return EN_SOC_SUCCESS;
                }
                else
                {
                    if (ret == SOC_ERROR)
                    {
                        en_soc_output_result(EN_SOC_PEER_NOT_REACHABLE, NULL, 0);
                        return EN_SOC_PEER_NOT_REACHABLE;
                    }
                    else
                    {
                        en_soc_output_result(EN_SOC_ERROR, NULL, 0);
                        return EN_SOC_ERROR;
                    }
                }
            }
        }
        else
        {
            en_soc_output_result(EN_SOC_ERROR, NULL, 0);
            return EN_SOC_ERROR;
        }
    }
    else
    {
        en_soc_output_result(EN_SOC_ERROR, NULL, 0);
        return EN_SOC_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_tcp_app_recv_response
 * DESCRIPTION
 *  The  em_soc_demo_app_socket_notify() calls this function to receive TCP incoming data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void en_soc_demo_tcp_app_recv_response(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction && soc_demo_transaction->state < RSP_RCVD)
    {
        int ret_val = 0;

        soc_demo_transaction->state = RSP_RCVING;
        ret_val = soc_recv(
                    soc_demo_transaction->socket_id,
                    (kal_uint8*) (soc_demo_transaction->rcvd_buffer + soc_demo_transaction->rcvd_counter),
                    (MAX_RCV_BUFFER_SIZE - soc_demo_transaction->rcvd_counter),
                    0);
        if (ret_val > 0)
        {
            soc_demo_transaction->rcvd_counter += ret_val;

            en_soc_output_result(
                EN_SOC_SUCCESS,
                (char*)soc_demo_transaction->rcvd_buffer,
                soc_demo_transaction->rcvd_counter);
        }
        else
        {
            if (ret_val == SOC_WOULDBLOCK)
            {
                SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
                return;
            }
            else
            {
                en_soc_output_result(EN_SOC_ERROR, NULL, 0);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_udp_app_send_request
 * DESCRIPTION
 *  This function is used to send UDP datagram to specific server.
 *  And receive server's response.
 *  If SOC can't receive any data for now, SOC will send MSG_ID_APP_SOC_NOTIFY_IND to MMI.
 *  Then MMI will call em_soc_demo_app_socket_notify() to receive incoming data.
 *  In the meantime, it will start a timer. If the timer is expired, there is no response from server.
 *  We will resend the request to the same server until retry counter reaches MAX_POST_RETRY_NUM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int en_soc_demo_udp_app_send_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction)
    {
        if (soc_demo_transaction->socket_id >= 0 && soc_demo_transaction->state >= SOC_CREATED)
        {

            /* Retry to send request to server */
            if (soc_demo_transaction->state == REQ_SEND_RETRY)
            {
                soc_demo_transaction->snd_counter = 0;
            }

            soc_demo_transaction->state = REQ_SENDING;
            ret = soc_sendto(
                    soc_demo_transaction->socket_id,
                    (kal_uint8*) (soc_demo_transaction->snd_buffer + soc_demo_transaction->snd_counter),
                    (soc_demo_transaction->snd_data_len - soc_demo_transaction->snd_counter),
                    0,
                    &soc_demo_transaction->server_ip_addr);
            if (ret > 0)
            {
                if (ret == (kal_int32) soc_demo_transaction->snd_data_len)
                {
                    soc_demo_transaction->state = REQ_SENT;
                    soc_demo_transaction->post_retry_counter++;
                    em_soc_demo_app_start_timer();  /* wait for servwer's response */
                    en_soc_demo_udp_app_recv_response();
                }
                else
                {
                    soc_demo_transaction->snd_counter += ret;
                }
                return EN_SOC_SUCCESS;
            }
            else
            {
                if (ret == SOC_WOULDBLOCK)
                {
                    SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
                    return EN_SOC_SUCCESS;
                }
                else
                {
                    en_soc_output_result(EN_SOC_ERROR, NULL, 0);
                    return EN_SOC_ERROR;
                }
            }
        }
        else
        {
            en_soc_output_result(EN_SOC_ERROR, NULL, 0);
            return EN_SOC_ERROR;
        }
    }
    else
    {
        en_soc_output_result(EN_SOC_ERROR, NULL, 0);
        return EN_SOC_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_udp_app_recv_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void en_soc_demo_udp_app_recv_response(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction && soc_demo_transaction->state < RSP_RCVD)
    {
        int ret_val = 0;

        soc_demo_transaction->state = RSP_RCVING;
        ret_val = soc_recvfrom(
                    soc_demo_transaction->socket_id,
                    (kal_uint8*) (soc_demo_transaction->rcvd_buffer + soc_demo_transaction->rcvd_counter),
                    (MAX_RCV_BUFFER_SIZE - soc_demo_transaction->rcvd_counter),
                    0,
                    &soc_demo_transaction->server_ip_addr);
        if (ret_val > 0)
        {
            soc_demo_transaction->rcvd_counter += ret_val;
            en_soc_output_result(
                EN_SOC_SUCCESS,
                (char*)soc_demo_transaction->rcvd_buffer,
                soc_demo_transaction->rcvd_counter);
        }
        else
        {
            if (ret_val == SOC_WOULDBLOCK)
            {
                SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
                return;
            }
            else
            {
                en_soc_output_result(EN_SOC_ERROR, NULL, 0);
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_get_host_by_name
 * DESCRIPTION
 *  This function is used to get ip address of specific host name.
 * PARAMETERS
 *  app_id          [IN]        (HTTP or DNS)
 *  hostname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void en_soc_demo_get_host_by_name(mmi_soc_demo_app_enum app_id, const kal_uint8 *hostname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_id != TRACERT)
    {
        soc_demo_transaction->state = REQ_SENDING;
    }
    ret = soc_gethostbyname(
            KAL_FALSE,
            MOD_MMI,
            (kal_int32) app_id,
            (kal_char*) hostname,
            (kal_uint8*) soc_demo_transaction->rcvd_buffer,
            (kal_uint8*) & soc_demo_transaction->rcvd_counter,
            0,
            (kal_uint8) soc_demo_transaction->nwt_acount_id);

    if (ret == SOC_SUCCESS)
    {
        if (app_id == DNS)
        {
            sprintf(
                (char*)soc_demo_transaction->rcvd_buffer,
                "%d.%d.%d.%d",
                (kal_uint8) * soc_demo_transaction->rcvd_buffer,
                (kal_uint8) * (soc_demo_transaction->rcvd_buffer + 1),
                (kal_uint8) * (soc_demo_transaction->rcvd_buffer + 2),
                (kal_uint8) * (soc_demo_transaction->rcvd_buffer + 3));

            soc_demo_transaction->rcvd_counter = strlen((char*)soc_demo_transaction->rcvd_buffer);
            en_soc_output_result(
                EN_SOC_SUCCESS,
                (char*)soc_demo_transaction->rcvd_buffer,
                soc_demo_transaction->rcvd_counter);
        }
        else if (app_id == HTTP)
        {
            memcpy(soc_demo_transaction->server_ip_addr.addr, soc_demo_transaction->rcvd_buffer, 4);
            soc_demo_transaction->rcvd_counter = 0;
            soc_demo_transaction->server_ip_addr.addr_len = 4;
            soc_demo_transaction->state = HTTP_TCP_CON_CREATING;
            en_soc_demo_http_send_request();

        }
        else if (app_id == TRACERT)
        {
            if (soc_demo_transaction->state == IDLE)
            {
                em_soc_icmp_exp_hdlr();
            }
            else if (soc_demo_transaction->state == HTTP_DNS_QUERY)
            {
                em_soc_icmp_dns_hdlr(
                    (kal_uint8*) soc_demo_transaction->rcvd_buffer,
                    (kal_uint8) soc_demo_transaction->rcvd_counter);
            }
        }
        else
        {
            en_soc_output_result(EN_SOC_UNKNOWN_APP, NULL, 0);
        }
    }
    else if (ret == SOC_WOULDBLOCK)
    {
        /* waits for APP_SOC_GET_HOST_BY_NAME_IND */
        SetProtocolEventHandler(em_soc_demo_app_soc_get_host_by_name_ind, MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
    }
    else
    {
        if (ret == SOC_ERROR)
        {
            en_soc_output_result(EN_SOC_PEER_NOT_REACHABLE, NULL, 0);
        }
        else
        {
            en_soc_output_result(EN_SOC_ERROR, NULL, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_app_soc_get_host_by_name_ind
 * DESCRIPTION
 *  This function is used to handle MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND from SOC.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_app_soc_get_host_by_name_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_get_host_by_name_ind_struct *dns_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!inMsg)
    {
        en_soc_output_result(EN_SOC_ERROR, NULL, 0);
    }
    dns_ind = (app_soc_get_host_by_name_ind_struct*) inMsg;
    /* Check if the result is OK */
    if (dns_ind->result == KAL_TRUE)
    {
        switch (dns_ind->request_id)
        {
                /* If app_id is DNS, the socket demo transactio is completed. */
            case DNS:
            {
                memcpy(soc_demo_transaction->rcvd_buffer, dns_ind->addr, dns_ind->addr_len);

                sprintf(
                    (char*)soc_demo_transaction->rcvd_buffer,
                    "%d.%d.%d.%d",
                    (kal_uint8) * soc_demo_transaction->rcvd_buffer,
                    (kal_uint8) * (soc_demo_transaction->rcvd_buffer + 1),
                    (kal_uint8) * (soc_demo_transaction->rcvd_buffer + 2),
                    (kal_uint8) * (soc_demo_transaction->rcvd_buffer + 3));

                soc_demo_transaction->rcvd_counter = strlen((char*)soc_demo_transaction->rcvd_buffer);

                en_soc_output_result(
                    EN_SOC_SUCCESS,
                    (char*)soc_demo_transaction->rcvd_buffer,
                    soc_demo_transaction->rcvd_counter);

                break;
            }
                /* If app_id is HTTP, call en_soc_demo_http_send_request() to send request this ip address. */
            case HTTP:
            {
                memcpy(soc_demo_transaction->server_ip_addr.addr, dns_ind->addr, dns_ind->addr_len);
                soc_demo_transaction->rcvd_counter = 0;
                soc_demo_transaction->server_ip_addr.addr_len = 4;
                soc_demo_transaction->state = HTTP_TCP_CON_CREATING;
                en_soc_demo_http_send_request();
                break;
            }
            case TRACERT:
            {
                if (soc_demo_transaction->state == IDLE)
                {
                    em_soc_icmp_exp_hdlr();
                }
                else if (soc_demo_transaction->state == HTTP_DNS_QUERY)
                {
                    em_soc_icmp_dns_hdlr(dns_ind->addr, dns_ind->addr_len);
                }
                break;
            }
            default:
                en_soc_output_result(EN_SOC_UNKNOWN_APP, NULL, 0);
                break;
        }
    }
    else
    {
        en_soc_output_result(EN_SOC_ERROR, NULL, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_app_create_socket
 * DESCRIPTION
 *  This function is used to create UDP or TCP socket
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
kal_bool en_soc_demo_app_create_socket()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 val = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction)
    {
        soc_demo_transaction->state = SOC_CREATING;
        switch (soc_demo_transaction->soc_demo_app_id)
        {
            case HTTP:
            {
                soc_demo_transaction->socket_id = soc_create(PF_INET, SOCK_STREAM, 0, MOD_MMI, soc_demo_transaction->nwt_acount_id);
                if (soc_demo_transaction->socket_id >= 0)
                {
                    if (soc_setsockopt(soc_demo_transaction->socket_id, SOC_NBIO, &val, sizeof(val)) < 0)
                    {
                        kal_print("Set socket to nonblock mode error !!");
                        return KAL_FALSE;
                    }
                    val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_CONNECT;
                    if (soc_setsockopt(soc_demo_transaction->socket_id, SOC_ASYNC, &val, sizeof(val)) < 0)
                    {
                        kal_print("Set socket to nonblock mode error !!");
                        return KAL_FALSE;
                    }
                    soc_demo_transaction->state = SOC_CREATED;
                    return KAL_TRUE;
                }
                else
                {
                    return KAL_FALSE;
                }
                break;
            }
            case DNS:
            case DAYTIME:
            case ECHO:
            {
                soc_demo_transaction->socket_id = soc_create(PF_INET, SOCK_DGRAM, 0, MOD_MMI, soc_demo_transaction->nwt_acount_id);
                if (soc_demo_transaction->socket_id >= 0)
                {
                    if (soc_setsockopt(soc_demo_transaction->socket_id, SOC_NBIO, &val, sizeof(val)) < 0)
                    {
                        kal_print("Set socket to nonblock mode error !!");
                        return KAL_FALSE;
                    }
                    val = SOC_READ | SOC_WRITE | SOC_CLOSE;
                    if (soc_setsockopt(soc_demo_transaction->socket_id, SOC_ASYNC, &val, sizeof(val)) < 0)
                    {
                        kal_print("Set socket to nonblock mode error !!");
                        return KAL_FALSE;
                    }
                    SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
                    soc_demo_transaction->state = SOC_CREATED;
                    return KAL_TRUE;
                }
                else
                {
                    return KAL_FALSE;
                }
            }
            case TRACERT:
            {
                kal_int8 ret = 0;
                /* create socket */
                soc_demo_transaction->socket_id = soc_create(
                    PF_INET,
                    SOCK_RAW,
                    IPPROTO_ICMP,
                    MOD_MMI,
                    soc_demo_transaction->nwt_acount_id);
                
                if (soc_demo_transaction->socket_id < 0)
                {
                    /* fail to create socket */
                    return KAL_FALSE;
                }
                soc_demo_transaction->state = SOC_CREATED;
                /* set socket to non-blocking mode */
                //val = KAL_FALSE;
                ret = soc_setsockopt(soc_demo_transaction->socket_id, SOC_NBIO, &val, sizeof(val));
                val = SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE;
                ret = soc_setsockopt(soc_demo_transaction->socket_id, SOC_ASYNC, &val, sizeof(val));
                
                if (ret < 0)
                {
                    /* fail to set socket option */
                    return KAL_FALSE;
                }
                return KAL_TRUE;
            }
            default:
                return KAL_FALSE;
        }
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_app_socket_notify
 * DESCRIPTION
 *  This function is used to handle events sent by SOC task
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_app_socket_notify(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *soc_notify = (app_soc_notify_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!soc_demo_transaction)
    {
        return;
    }
    kal_prompt_trace(MOD_MMI, "Got socket notify, event_type:%d", soc_notify->event_type);
    switch (soc_notify->event_type)
    {
        case SOC_WRITE:
        {
            switch (soc_demo_transaction->soc_demo_app_id)
            {
                case HTTP:
                    en_soc_demo_http_send_request();
                    break;
                case DAYTIME:
                case ECHO:
                    en_soc_demo_udp_app_send_request();
                    break;
                case TRACERT:
                    em_soc_icmp_send_hdlr(SOC_ICMP_SEND_RESEND);
                    break;
            }
            break;
        }
        case SOC_READ:
        {
            switch (soc_demo_transaction->soc_demo_app_id)
            {
                case HTTP:
                    en_soc_demo_tcp_app_recv_response();
                    break;
                case DAYTIME:
                case ECHO:
                    en_soc_demo_udp_app_recv_response();
                    break;
                case TRACERT:
                    if ( soc_demo_transaction->state != REQ_SENT)
                    {
                        em_soc_icmp_exp_hdlr();
                    }
                    else
                    {
                        em_soc_demo_icmp_recv_response();
                    }
                    break;
            }
            break;
        }
        case SOC_CONNECT:
        {
            if (soc_demo_transaction->soc_demo_app_id == HTTP)
            {
                if (soc_notify->result == KAL_TRUE)
                {
                    soc_demo_transaction->state = HTTP_TCP_CON_CREATED;
                    en_soc_demo_http_send_request();
                }
                else
                {
                    en_soc_output_result(EN_SOC_PEER_NOT_REACHABLE, NULL, 0);
                }
            }
            break;
        }
        case SOC_CLOSE:
        {
            en_soc_output_result(EN_SOC_CNT_RESET_BY_PEER, NULL, 0);
        }
        default:
            en_soc_output_result(EN_SOC_ERROR, NULL, 0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_app_start_timer
 * DESCRIPTION
 *  This function is used to start EM_GPRS_SOC_DEMO_APP_TIMER timer.
 *  The timeout value is SOC_DEMO_APP_POST_TIMEOUT.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_app_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(EM_GPRS_SOC_DEMO_APP_TIMER, SOC_DEMO_APP_POST_TIMEOUT, em_soc_demo_app_timer_handler);
}


/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_app_stop_timer
 * DESCRIPTION
 *  This function is used to stop EM_GPRS_SOC_DEMO_APP_TIMER timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_app_stop_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EM_GPRS_SOC_DEMO_APP_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_app_timer_handler
 * DESCRIPTION
 *  When EM_GPRS_SOC_DEMO_APP_TIMER expires,
 *  MMI will call this function to resend request to server.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_app_timer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (soc_demo_transaction->post_retry_counter < MAX_POST_RETRY_NUM)
    {
        soc_demo_transaction->state = REQ_SEND_RETRY;
        switch (soc_demo_transaction->soc_demo_app_id)
        {
            case HTTP:
                en_soc_demo_http_send_request();
                break;
            case DAYTIME:
            case ECHO:
                en_soc_demo_udp_app_send_request();
                break;
            default:
                en_soc_output_result(EN_SOC_UNKNOWN_APP, NULL, 0);
                break;
        }
    }
    else
    {
        en_soc_output_result(EN_SOC_PEER_NO_RESPONSE, NULL, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  en_soc_demo_http_get_parsed_url
 * DESCRIPTION
 *  This functino is used to parse uri given by user.
 *  It can retrieve hostname and port number.
 * PARAMETERS
 *  in_str      [IN]        
 *  str_len     [IN]        
 * RETURNS
 *  soc_demo_app_http_url_struct* (parsed uri information)
 *****************************************************************************/
soc_demo_app_http_url_struct *en_soc_demo_http_get_parsed_url(const kal_int8 *in_str, int str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *hostname = NULL;
    soc_demo_app_http_url_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = OslMalloc(sizeof(soc_demo_app_http_url_struct));
    if (rsp)
    {
        memset(rsp, 0, sizeof(soc_demo_app_http_url_struct));
        hostname = strstr((char*)in_str, "http://");
        if (!hostname)
        {
            OslMfree(rsp);
            return NULL;
        }
        else
        {
            char *slash, *colon;

            hostname += 7;  /* strlen(http://) */
            slash = strchr(hostname, '/');
            if (!slash)
            {
                colon = strchr(hostname, ':');
                if (colon)
                {
                    rsp->host_name_len = (colon - hostname);
                    rsp->host_name = OslMalloc((U16) (rsp->host_name_len + 1));
                    if (!rsp->host_name)
                    {
                        OslMfree(rsp);
                        return NULL;
                    }
                    memset(rsp->host_name, 0, rsp->host_name_len + 1);
                    memcpy(rsp->host_name, hostname, rsp->host_name_len);

                    rsp->ser_port_num = atoi(colon);
                }
                else
                {
                    rsp->ser_port_num = 80;
                    rsp->host_name_len = strlen(hostname);
                    rsp->host_name = OslMalloc((U16) (rsp->host_name_len + 1));
                    if (!rsp->host_name)
                    {
                        OslMfree(rsp);
                        return NULL;
                    }
                    memset(rsp->host_name, 0, rsp->host_name_len + 1);
                    memcpy(rsp->host_name, hostname, rsp->host_name_len);
                }
                return rsp;
            }
            else
            {
                colon = strchr(hostname, ':');
                if (colon)
                {
                    char *port_str;

                    rsp->host_name_len = (colon - hostname);
                    rsp->host_name = OslMalloc((U16) (rsp->host_name_len + 1));
                    if (!rsp->host_name)
                    {
                        OslMfree(rsp);
                        return NULL;
                    }
                    memset(rsp->host_name, 0, rsp->host_name_len + 1);
                    memcpy(rsp->host_name, hostname, rsp->host_name_len);

                    port_str = OslMalloc((U16) (slash - colon));
                    memset(port_str, 0, slash - colon);
                    if (!port_str)
                    {
                        OslMfree(rsp->host_name);
                        OslMfree(rsp);
                        return NULL;
                    }
                    strncpy(port_str, colon + 1, slash - colon - 1);
                    rsp->ser_port_num = atoi(port_str);
                    OslMfree(port_str);
                }
                else
                {
                    rsp->ser_port_num = 80;
                    rsp->host_name_len = slash - hostname;
                    rsp->host_name = OslMalloc((U16) (rsp->host_name_len + 1));
                    if (!rsp->host_name)
                    {
                        OslMfree(rsp);
                        return NULL;
                    }
                    memset(rsp->host_name, 0, rsp->host_name_len + 1);
                    memcpy(rsp->host_name, hostname, rsp->host_name_len);
                }
                rsp->url_link_len = strlen(slash);
                rsp->url_link = OslMalloc((U16) (rsp->url_link_len + 1));
                if (!rsp->url_link)
                {
                    OslMfree(rsp->host_name);
                    OslMfree(rsp->url_link);
                    OslMfree(rsp);
                    return NULL;
                }
                memset(rsp->url_link, 0, rsp->url_link_len + 1);
                memcpy(rsp->url_link, slash, rsp->url_link_len);
                return rsp;
            }
        }
    }
    else
    {
        return NULL;
    }
}

#define TRACE_ROUTE

/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_icmp_send_request
 * DESCRIPTION
 *  used to send out icmp echo request packet
 * PARAMETERS
 *  seq_number      [IN]        sequence number of the packet
 *  socket_id       [IN]        socket id
 *  server_ip_addr  [IN]        ptr to destination ip address
 *  icmp_data       [IN]        icmp packet data
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_icmp_send_request(kal_int8 seq_number, kal_int8 socket_id, sockaddr_struct *server_ip_addr, kal_uint8 *icmp_data, kal_uint32 icmp_data_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (socket_id >= 0)
    {
        kal_int32 bytes_sent;

        bytes_sent = soc_sendto(
                        socket_id,
                        icmp_data,
                        icmp_data_length,
                        0,
                        server_ip_addr);

        if (bytes_sent > 0)
        {
            em_soc_icmp_sent_hdlr();
            SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
        }
        else if ( bytes_sent == SOC_WOULDBLOCK ) /* (bytes_sent > 0) */
        {
            SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
        }
        else
        {
            em_soc_icmp_error_hdlr(EN_SOC_ERROR);
        }
    }
    else /* (soc_demo_transaction->socket_id >= 0 && soc_demo_transaction->state >= SOC_CREATED) */
    {
        if (soc_demo_transaction->state != REQ_SENT)
        {
            em_soc_icmp_exp_hdlr();
        }
        else
        {
            em_soc_icmp_error_hdlr(EN_SOC_ERROR);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_icmp_recv_response
 * DESCRIPTION
 *  used to receive packets
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_demo_icmp_recv_response(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret = 0;
    sockaddr_struct rsp_addr;
    kal_int8 socket_id;
    kal_uint8 *rcvd_buffer;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get socket id and buffer for receiving data */
    em_soc_icmp_recv_ind_hdlr(&socket_id, &rcvd_buffer);
    ret = soc_recvfrom(
            socket_id,
            rcvd_buffer,
            MAX_RCV_BUFFER_SIZE,
            0,
            &(rsp_addr));
    if (ret > 0)
    {
        em_soc_icmp_receive_hdlr(&(rsp_addr));
    }
    else /* (ret > 0) */
    {
        if (ret == SOC_WOULDBLOCK)
        {
            SetProtocolEventHandler(em_soc_demo_app_socket_notify, MSG_ID_APP_SOC_NOTIFY_IND);
        }
        else /* (ret == SOC_WOULDBLOCK) */
        {
            em_soc_icmp_error_hdlr(EN_SOC_ERROR);
        }
    }/* (ret > 0) */        
}

/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_icmp_recv_response
 * DESCRIPTION
 *  used to check if inputted data Domain Name or Ip address
 * PARAMETERS
 *  addr            [IN]        input data
 *  len             [IN]        data_length
 *  ip_addr         [IN/OUT]    parsed ip address array
 * RETURNS
 *  mmi_soc_demo_app_addr_type_enum
 *****************************************************************************/
mmi_soc_demo_app_addr_type_enum em_soc_demo_app_get_addr_type(kal_uint8 *addr, kal_int32 len, kal_uint8 *ip_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    kal_bool is_DNAME = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<len; i++)
    {
        if ( addr[i]<48 || addr[i] > 57 )
        {
            return SOC_ADDR_TYPE_DNAME;
        }
        else
        {
            is_DNAME = FALSE;
            break;
        }
    }

    if (ip_addr != NULL)
    {
        ip_addr[0] = (kal_uint8)atoi(strtok((char*)addr, "."));
        ip_addr[1] = (kal_uint8)atoi(strtok((char*)NULL, "."));
        ip_addr[2] = (kal_uint8)atoi(strtok((char*)NULL, "."));
        ip_addr[3] = (kal_uint8)atoi(strtok((char*)NULL, "."));
    }

    return SOC_ADDR_TYPE_IP;

}

/*****************************************************************************
 * FUNCTION
 *  em_soc_demo_icmp_set_ttl
 * DESCRIPTION
 *  used to set ttl value to ip header
 * PARAMETERS
 *  socket_id       [IN]        socket id
 *  ttl             [IN]        ttl value
 * RETURNS
 *  kal_int8
 *****************************************************************************/
kal_int8 em_soc_demo_icmp_set_ttl(kal_int8 socket_id, kal_uint8 ttl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return soc_setsockopt(
        socket_id,
        SOC_IP_TTL,
        &ttl,
        sizeof(ttl));
}

/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_init_soc
 * DESCRIPTION
 *  used to handle logic of sending/resending packets of trace route application
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
kal_int32 em_soc_icmp_init_soc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    soc_demo_transaction->snd_counter = 0;
    soc_demo_transaction->rcvd_counter = 0;

    soc_demo_transaction->server_ip_addr.addr[0] = 0;
    soc_demo_transaction->server_ip_addr.addr[1] = 0;
    soc_demo_transaction->server_ip_addr.addr[2] = 0;
    soc_demo_transaction->server_ip_addr.addr[3] = 0;
    soc_demo_transaction->server_ip_addr.addr_len = 4;
    soc_demo_transaction->server_ip_addr.port = SOC_TRACERT_PORT;
    ret = soc_bind(
        soc_demo_transaction->socket_id,
        &(soc_demo_transaction->server_ip_addr));
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_dns_hdlr
 * DESCRIPTION
 *  used to handle exceptions
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_dns_hdlr(kal_uint8 *addr, kal_uint8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char str[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(soc_demo_transaction->server_ip_addr.addr, addr, len);

    EmStartTraceRtResult((S8*)soc_demo_transaction->url);
    memset(str,0,64);
    kal_sprintf(
        str,
        " [%d.%d.%d.%d]\n",
        soc_demo_transaction->server_ip_addr.addr[0],
        soc_demo_transaction->server_ip_addr.addr[1],
        soc_demo_transaction->server_ip_addr.addr[2],
        soc_demo_transaction->server_ip_addr.addr[3]
    );
    EmAppendTraceRtResult((S8*)str);
    soc_demo_transaction->state = REQ_SENT;
    StartTimer(EM_GPRS_SOC_DEMO_APP_TIMER, SOC_DEMO_APP_POST_TIMEOUT, em_soc_icmp_timer_hdlr);
    em_soc_icmp_send_hdlr(SOC_ICMP_SEND_NORMAL);

}



/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_send_hdlr
 * DESCRIPTION
 *  used to handle logic of sending/resending packets of trace route application
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int em_soc_icmp_send_hdlr(mmi_soc_icmp_send_type_enum send_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8   icmp_data[10];
    kal_uint8   ttl = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (send_type)
    {
        case SOC_ICMP_SEND_NORMAL:
            soc_demo_transaction->snd_counter ++;
            ttl = soc_demo_transaction->snd_counter;
            /* initialize ICMP packet data */
            memset(icmp_data,0,10);
            icmp_data[0] = 8; /* Echo Request */
            icmp_data[1] = 0; /* Code */
            icmp_data[4] = (kal_uint8)(SOC_TRACERT_PORT>>8); /* identifier */
            icmp_data[5] = SOC_TRACERT_PORT; /* identifier */
            icmp_data[6] = (kal_uint8)((soc_demo_transaction->snd_counter-1)>>8); /* Sequence Number */
            icmp_data[7] = (kal_uint8)(soc_demo_transaction->snd_counter-1); /* Sequence Number */
            icmp_data[8] = (kal_uint8)soc_demo_transaction->snd_counter;
            icmp_data[9] = (kal_uint8)soc_demo_transaction->rcvd_counter;

            memcpy(soc_demo_transaction->snd_buffer, icmp_data, 10);
            soc_demo_transaction->snd_data_len = 10;
            
            em_soc_demo_icmp_set_ttl(soc_demo_transaction->socket_id, ttl);

            em_soc_demo_icmp_send_request(
                soc_demo_transaction->snd_counter,
                soc_demo_transaction->socket_id,
                &(soc_demo_transaction->server_ip_addr),
                (kal_uint8*)soc_demo_transaction->snd_buffer,
                soc_demo_transaction->snd_data_len);            
            break;
        case SOC_ICMP_SEND_RESEND:
            em_soc_demo_icmp_send_request(
                soc_demo_transaction->snd_counter,
                soc_demo_transaction->socket_id,
                &(soc_demo_transaction->server_ip_addr),
                (kal_uint8*)soc_demo_transaction->snd_buffer,
                soc_demo_transaction->snd_data_len);
            break;
        case SOC_ICMP_SEND_RETRY:
            soc_demo_transaction->post_retry_counter ++;
            em_soc_demo_icmp_send_request(
                soc_demo_transaction->snd_counter,
                soc_demo_transaction->socket_id,
                &(soc_demo_transaction->server_ip_addr),
                (kal_uint8*)soc_demo_transaction->snd_buffer,
                soc_demo_transaction->snd_data_len);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    
    return EN_SOC_SUCCESS;

}

/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_sent_hdlr
 * DESCRIPTION
 *  used to notify application that packet is sent successfully
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_sent_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&(soc_demo_transaction->snd_time));
}

/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_recv_ind_hdlr
 * DESCRIPTION
 *  used to get current socket id and receive buffer data
 * PARAMETERS
 *  socket_id       [IN]        socket_id
 *  rec_data        [IN/OUT]    receive buffer data ptr
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_recv_ind_hdlr(kal_int8 *socket_id, kal_uint8 **rec_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *socket_id = soc_demo_transaction->socket_id;
    *rec_data = (kal_uint8*)soc_demo_transaction->rcvd_buffer;
}

BOOL em_soc_icmp_check_reply_data(kal_int8 *rec_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check if rec_data correct? */
    if (rec_data[0] == 0)
    {/* Echo Reply */
        /* check identifier */
        if (rec_data[4] != (kal_uint8)(SOC_TRACERT_PORT>>8)
            || rec_data[5] != SOC_TRACERT_PORT )
        {
            return FALSE;
        }
        /* check sequence number */
        if (rec_data[6] != (kal_uint8)((soc_demo_transaction->snd_counter-1) >> 8)
            || rec_data[7] != (kal_uint8)(soc_demo_transaction->snd_counter-1))
        {
            return FALSE;
        }
        /* TODO: check ping data */
        if (rec_data[8] != (kal_uint8)(soc_demo_transaction->snd_counter)
            || rec_data[9] != (kal_uint8)(soc_demo_transaction->rcvd_counter))
        {
            return FALSE;
        }
        /* TODO: check ping size */
    }
    else if (rec_data[0] == 11) /* (rec_data[0] == 0) */
    {/* time exceeded */
        /* check identifier */
        if (rec_data[32] != (kal_uint8)(SOC_TRACERT_PORT>>8)
            || rec_data[33] != SOC_TRACERT_PORT )
        {
            return FALSE;
        }
        /* check sequence number */
        if (rec_data[34] != (kal_uint8)((soc_demo_transaction->snd_counter-1) >> 8)
            || rec_data[35] != (kal_uint8)(soc_demo_transaction->snd_counter-1))
        {
            return FALSE;
        }
        /* TODO: check ping size */
    }/* (rec_data[0] == 0) */
    return TRUE;
}
    
/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_receive_hdlr
 * DESCRIPTION
 *  used to handle received data
 * PARAMETERS
 *  rsp_addr        [IN]    ip address of the host sent out the packet
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_receive_hdlr(sockaddr_struct *rsp_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char str_buf[40];
    kal_int8 *rec_data = soc_demo_transaction->rcvd_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (str_buf,0,40);
    
    soc_demo_transaction->post_retry_counter = 0;

    kal_get_time(&(soc_demo_transaction->rcvd_time));
    
    if (rec_data[0] == 11 || rec_data[0] == 0)
    {/* time exceeded  or  Echo Reply */
        if (em_soc_icmp_check_reply_data(rec_data) == FALSE)
        {
            return;
        }
        soc_demo_transaction->rcvd_counter ++;

        StopTimer(EM_GPRS_SOC_DEMO_APP_TIMER);
    
        /* output replied data */
        kal_sprintf(
            str_buf,
            " %d %dms %d.%d.%d.%d\n",
            soc_demo_transaction->snd_counter,
            ((soc_demo_transaction->rcvd_time - soc_demo_transaction->snd_time) * 462) / 100 ,
            rsp_addr->addr[0],
            rsp_addr->addr[1],
            rsp_addr->addr[2],
            rsp_addr->addr[3]);
        EmAppendTraceRtResult((S8*) str_buf);
    
        if (rec_data[0] == 0) /* Echo Reply */
        {
            /* whole process done, close socket */
            kal_sprintf(
                str_buf,
                "Trace complete.");
            EmAppendTraceRtResult((S8*) str_buf);
            EmEndTraceRt();
            soc_demo_transaction->state = SOC_CLOSED;
            mmi_soc_demo_app_request_abort();
        }
        else /* (rec_data[0] == 0) */
        {
            StartTimer(EM_GPRS_SOC_DEMO_APP_TIMER, SOC_DEMO_APP_POST_TIMEOUT, em_soc_icmp_timer_hdlr);
            em_soc_icmp_send_hdlr(SOC_ICMP_SEND_NORMAL);
        }/* (rec_data[0] == 0) */
    }
    else if (rec_data[0] == 3)/*(rec_data[0] == 11 || rec_data[0] == 0)*/
    {/* Destination Unreachable */
        kal_sprintf(
            str_buf,
            " %d %dms Destination Unreachable\n",
            soc_demo_transaction->rcvd_counter,
            ((soc_demo_transaction->rcvd_time - soc_demo_transaction->snd_time) * 462) / 100);
        EmAppendTraceRtResult((S8*)str_buf);
        soc_demo_transaction->state = SOC_CLOSED;
        mmi_soc_demo_app_request_abort();
    }
    else if (rec_data[0] == 4 )/*(rec_data[0] == 11 || rec_data[0] == 0)*/
    {/* Router Overloaded */ 
        /* stop sending Request */
        kal_sprintf(
            str_buf,
            "%d, %dms, Router Overloaded\n",
            soc_demo_transaction->rcvd_counter,
            ((soc_demo_transaction->rcvd_time - soc_demo_transaction->snd_time) * 462) / 100);
        EmAppendTraceRtResult((S8*)str_buf);
        soc_demo_transaction->state = SOC_CLOSED;
        mmi_soc_demo_app_request_abort();
    }


}

/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_timer_hdlr
 * DESCRIPTION
 *  used to handle time out scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * The first digit of soc_demo_transaction->post_retry_counter means number of
     * timed-out happened continuously. 
     * The second digit of soc_demo_transaction->post_retry_counter means number of
     * timed-out happened for the same node
     */
    if (soc_demo_transaction->state != REQ_SENT)
    {
        em_soc_icmp_exp_hdlr();
    }
    else if ((soc_demo_transaction->post_retry_counter % 10)==1)
    {/* time-out twice for the same node */
        char str[21];
        
        memset(str,0,21);
        kal_sprintf(str, " %d * Timed out.\n", soc_demo_transaction->snd_counter);
        soc_demo_transaction->post_retry_counter += 9;
        EmAppendTraceRtResult((S8*) str);
        /*
        if (EmAppendTraceRtResult((S8*) str) == MMI_FALSE)
        {
            EmAbortTraceRtResult();
            return;
        }
        */
        StartTimer(EM_GPRS_SOC_DEMO_APP_TIMER, SOC_DEMO_APP_POST_TIMEOUT, em_soc_icmp_timer_hdlr);
        em_soc_icmp_send_hdlr(SOC_ICMP_SEND_NORMAL);
    }
    else if (soc_demo_transaction->post_retry_counter > 20)
    {/* time-out for 3 different nodes continuously */
        char str_buf[40];

        memset(str_buf, 0, 40);
        kal_sprintf(str_buf, " %d * Timed out.\nTrace Stopped!", soc_demo_transaction->snd_counter);
        EmAppendTraceRtResult((S8*) str_buf);
        EmEndTraceRt();
        
        soc_demo_transaction->state = SOC_CLOSED;
        mmi_soc_demo_app_request_abort();
    }
    else
    {
        StartTimer(EM_GPRS_SOC_DEMO_APP_TIMER, SOC_DEMO_APP_POST_TIMEOUT, em_soc_icmp_timer_hdlr);
        em_soc_icmp_send_hdlr(SOC_ICMP_SEND_RETRY);
    }

}


/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_error_hdlr
 * DESCRIPTION
 *  used to handle errors and show error messages
 * PARAMETERS
 *  int         [IN]        error cause
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_error_hdlr(int ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    soc_demo_transaction->state = SOC_CLOSED;
    mmi_soc_demo_app_request_abort();
    EmSocketShowErrorMsgByCause(ret);
}

/*****************************************************************************
 * FUNCTION
 *  em_soc_icmp_exp_hdlr
 * DESCRIPTION
 *  used to handle exceptions
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void em_soc_icmp_exp_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0);
}

#endif /* (defined(__MMI_ENGINEER_MODE__) && defined(__TCPIP__)) */ 

