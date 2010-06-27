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
 * EngineerModeSocketDemoApp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implement the engineer mode socket demo application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#if (defined(__MMI_ENGINEER_MODE__) && defined(__TCPIP__))

#define MAX_SND_BUFFER_SIZE 1500
#define MAX_RCV_BUFFER_SIZE 1000
#define MAX_POST_RETRY_NUM 5    /* for UDP demo application, ex: DAYTIME and Echo */
#define SOC_DEMO_APP_POST_TIMEOUT 5000  /* It means that 5 seconds */
#define SOC_DAYTIME_RESVD_PORT 13
#define SOC_ECHO_RESVD_PORT 7
#define SOC_TRACERT_PORT  100

typedef enum
{
    HTTP,
    DNS,
    DAYTIME,
    ECHO,
    TRACERT
} mmi_soc_demo_app_enum;

typedef enum
{
    EN_SOC_INVAL_PARA = -9,
    EN_SOC_ERROR,
    EN_SOC_PEER_NOT_REACHABLE,
    EN_SOC_PEER_NO_RESPONSE,
    EN_SOC_CNT_RESET_BY_PEER,
    EN_SOC_BEARER_FAIL,
    EN_SOC_UNKNOWN_APP,
    EN_SOC_BUSY,
    EN_SOC_NO_MEMORY,
    EN_SOC_SUCCESS
} mmi_soc_demo_app_result;

typedef enum
{
    IDLE,
    SOC_CREATING,
    SOC_CREATED,
    HTTP_DNS_QUERY,
    HTTP_TCP_CON_CREATING,
    HTTP_TCP_CON_CREATED,
    REQ_SEND_RETRY,
    REQ_SENDING,
    REQ_SENT,
    RSP_RCVING,
    RSP_RCVD,
    SOC_CLOSING,
    SOC_CLOSED
} mmi_soc_demo_app_transaction_state_enum;

typedef enum
{
    SOC_ADDR_TYPE_IP,
    SOC_ADDR_TYPE_DNAME,
    SOC_ADDR_TYPE_INVALID,
    SOC_ADDR_TYPE_TOTAL
} mmi_soc_demo_app_addr_type_enum;

typedef enum
{
    SOC_ICMP_SEND_NORMAL,
    SOC_ICMP_SEND_RESEND,
    SOC_ICMP_SEND_RETRY,
    SOC_ICMP_SEND_END
} mmi_soc_icmp_send_type_enum;

typedef void (*mmi_soc_demo_app_rsp_t) (mmi_soc_demo_app_enum app_id_enum, int result, char *response,
                                        int response_len);

/* Structs */
typedef struct
{
    kal_uint8 *host_name;
    kal_int32 host_name_len;

    kal_uint8 *url_link;
    kal_int32 url_link_len;

    kal_int32 ser_port_num;

} soc_demo_app_http_url_struct;

typedef struct
{
    kal_uint32 soc_demo_app_id;

    kal_uint8 state;
    kal_int8 socket_id;
    kal_uint8 is_socket_opened;
    kal_uint8 post_retry_counter;

    kal_uint32 nwt_acount_id;
    kal_int8 *rcvd_buffer;
    kal_uint32 rcvd_data_len;
    kal_uint32 rcvd_counter;
    kal_uint32 rcvd_time;
    kal_char *snd_buffer;
    kal_uint32 snd_data_len;
    kal_uint32 snd_counter;
    kal_uint32 snd_time;
    kal_int8 *url;
    kal_int32 url_len;
    sockaddr_struct server_ip_addr;
    soc_demo_app_http_url_struct *url_parsed_info;
    mmi_soc_demo_app_rsp_t callback;
} soc_demo_app_transaction_struct;

extern int mmi_soc_demo_app_request(
            mmi_soc_demo_app_enum app_id,
            int account_id,
            char server_ip_address[4],
            char *url,
            int url_len,
            char *echo_text,
            int echo_text_len,
            mmi_soc_demo_app_rsp_t callback);

extern int mmi_soc_demo_app_request_abort(void);
#endif /* (defined(__MMI_ENGINEER_MODE__) && defined(__TCPIP__)) */ 

