/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */










#ifndef _msf_wtpd_h
#define _msf_wtpd_h

#ifdef STK_CONFIG_WTP





#define STK_WTP_MAX_NUM_TRANSACTIONS            12

#define STK_WTP_PDU_TYPE_INVOKE                 0x01
#define STK_WTP_PDU_TYPE_RESULT                 0x02
#define STK_WTP_PDU_TYPE_ACK                    0x03
#define STK_WTP_PDU_TYPE_ABORT                  0x04
#define STK_WTP_PDU_TYPE_SEGMENTED_INVOKE       0x05
#define STK_WTP_PDU_TYPE_SEGMENTED_RESULT       0x06
#define STK_WTP_PDU_TYPE_NACK                   0x07

#define STK_WTP_PDU_INVOKE_HEADERLEN            4
#define STK_WTP_PDU_RESULT_HEADERLEN            3
#define STK_WTP_PDU_ACK_HEADERLEN               3
#define STK_WTP_PDU_ABORT_HEADERLEN             4

#define STK_WTP_PDU_SEGM_INVOKE_HEADERLEN       4
#define STK_WTP_PDU_SEGM_RESULT_HEADERLEN       4
#define STK_WTP_PDU_NACK_HEADERLEN              4
#define STK_WTP_PDU_TPI_HEADERLEN               1



#define STK_WTP_STATE_INI_NULL                  1
#define STK_WTP_STATE_INI_RESULT_WAIT           2
#define STK_WTP_STATE_INI_RESULT_RESP_WAIT      3
#define STK_WTP_STATE_RES_LISTEN                4
#define STK_WTP_STATE_RES_TIDOK_WAIT            5
#define STK_WTP_STATE_RES_INVOKE_RESP_WAIT      6
#define STK_WTP_STATE_WAIT_TIMEOUT              7

#ifdef STK_CONFIG_WTP_SAR
#define STK_WTP_STATE_SAR_RES_RESP_WAIT         9
#define STK_WTP_STATE_INI_ACK_WAIT              10
#define STK_WTP_STATE_INI_SEGM_RESULT_WAIT      11
#define STK_WTP_STATE_SEND_GROUP                12
#define STK_WTP_STATE_BUILDING_GROUP            13
#define STK_WTP_STATE_ERROR                     20

#endif


#define STK_WTP_PROVIDER_ABORT                  0x00
#define STK_WTP_USER_ABORT                      0x01

#define STK_WTP_ERR_UNKNOWN                     0
#define STK_WTP_ERR_PROTOERR                    1
#define STK_WTP_ERR_INVALIDTID                  2
#define STK_WTP_ERR_NOTIMPLEMENTEDCL2           3
#define STK_WTP_ERR_NOTIMPLEMENTEDSAR           4
#define STK_WTP_ERR_NOTIMPLEMENTEDUACK          5
#define STK_WTP_ERR_WTPVERSIONONE               6
#define STK_WTP_ERR_CAPTEMPEXCEEDED             7
#define STK_WTP_ERR_NORESPONSE                  8
#define STK_WTP_ERR_MESSAGETOOLARGE             9
#define STK_WTP_ERR_INVALID_CLASS               10
#define STK_WTP_ERR_INVALID_BEARER              11

#define STK_WTP_FLAG_RID                        0x01
#define STK_WTP_FLAG_TTR                        0x02
#define STK_WTP_FLAG_GTR                        0x04



#define STK_WTP_FLAG_USER_ACK                   0x01
#define STK_WTP_FLAG_TIDOK_SENT                 0x02
#define STK_WTP_FLAG_TID_NEW                    0x04
#define STK_WTP_FLAG_HOLD_ON                    0x08

#ifdef STK_CONFIG_WTP_SAR
#define STK_WTP_FLAG_USE_SAR                    0x10
#define STK_WTP_FLAG_SPLIT_RESULT               0x20
#define STK_WTP_FLAG_SENT_NACK                  0x40
#define STK_WTP_FLAG_USER_SELECTED              0x80

#define STK_WTP_TPI_ERROR                       0x00
#define STK_WTP_TPI_INFO                        0x01
#define STK_WTP_TPI_OPTION                      0x02
#define STK_WTP_TPI_PSN                         0x03

#define STK_WTP_TPI_OPTION_TOTAL_MSG_SIZE       0x02
#define STK_WTP_TPI_OPTION_DELAY_TRANS_TIMER    0x03
#define STK_WTP_TPI_OPTION_MAX_GROUP_SIZE       0x04

#define STK_WTP_SAR_RECEIVE_GROUP_TIMEOUT_FLAG  0x400
#endif



#define STK_WTP_TID_W           0x4000     
#define STK_WTP_INVALID_TID     0xffff






#ifdef STK_CONFIG_WTP_SAR

typedef struct seg_st {
  struct seg_st *next;
  char          *data;
  int            data_pos;
  int            data_endpos;
  MSF_UINT8      segnum;
  int            flags;
} stk_wtp_segment_t;




typedef struct mseg_st {
  struct mseg_st    *next;
  stk_wtp_segment_t *seg;
} stk_wtp_missing_segment_t;

#endif





typedef struct stk_wtp_transaction_st {
  struct stk_wtp_transaction_st *next;

  int         request_id;
  MSF_UINT16  tid;                    
  int         cidx;
  int         state;
  int         timer_is_set;

  int         counter;
  MSF_UINT8   tr_class;               
  int         flags;
  int         datasource;
  char       *msg;
  int         msglen;
  int         msgpos;
  int         retry_interval;         
  int         max_rcr;                
  int         ack_interval_time;      
  int         max_aec;                
  int         wait_timeout_interval;  

#ifdef STK_CONFIG_WTP_SAR
  
  stk_wtp_segment_t         *invoke_group;
  stk_wtp_segment_t         *last_segment;
  stk_wtp_missing_segment_t *missing_segments;
  MSF_UINT32                 total_send_msg_size;
  MSF_UINT32                 max_send_msg_size;
  MSF_UINT32                 send_msg_size;
  MSF_UINT32                 max_send_group_size;
  MSF_UINT32                 delay_time;
  int                        segnum;
  int                        ack_psn;
  int                        group_retry_interval;    
  int                        segment_retry_interval;  

  
  stk_wtp_segment_t         *recv_seg_list;
  stk_wtp_segment_t         *last_recv_seg;
  MSF_UINT32                 total_recv_msg_size;
  MSF_UINT32                 max_recv_group_size;
  MSF_UINT32                 recv_msg_size;
  MSF_UINT32                 recv_group_size;
  MSF_UINT8                  num_recv_segments;
  MSF_UINT8                  first_segnum_in_current_group;
  int                        first_segnum_in_previous_group;
  int                        result_resp_received;
#endif
} stk_wtp_transaction_t;

typedef struct stk_wtp_mini_transaction_st {
  struct stk_wtp_mini_transaction_st *next;

  int        request_id;
  MSF_UINT16 tid;                    
  int        cidx;
  int        state;
  int        timer_is_set;
} stk_wtp_mini_transaction_t;




typedef struct {
  int                         cidx;         
  int                         num_tr;       
  stk_wtp_transaction_t      *tr;           
  stk_wtp_mini_transaction_t *mtr;          
} stk_wtp_connection_t;






extern int stk_wtp_num_transactions;    








#define STK_WTP_PDU_CONTINUE_FLAG(pdu)    (((unsigned char *)pdu)[0] & 0x80)
#define STK_WTP_PDU_TIDVE(pdu)            (((unsigned char *)pdu)[0] & 0x04)
#define STK_WTP_PDU_TIDOK_FLAG(pdu)       (((unsigned char *)pdu)[0] & 0x04)
#define STK_WTP_PDU_TYPE(pdu)             (MSF_UINT8)((((unsigned char *)pdu)[0] >> 3) & 0xf)
#define STK_WTP_PDU_TID(pdu)              (MSF_UINT16)((((unsigned char *)pdu)[1] << 8) | ((unsigned char *)pdu)[2])
#define STK_WTP_PDU_IS_LONG_TPI(pdu)      ((((unsigned char *)pdu)[0] >> 2) & 0x1)
#define STK_WTP_PDU_SHORT_TPI_LENGTH(pdu) (((unsigned char *)pdu)[0] & 0x3)
#define STK_WTP_PDU_RID_FLAG(pdu)         (((unsigned char *)pdu)[0] & 0x01)
#define STK_WTP_PDU_TTR_FLAG(pdu)         (((unsigned char *)pdu)[0] & 0x02)
#define STK_WTP_PDU_GTR_FLAG(pdu)         (((unsigned char *)pdu)[0] & 0x04)
#define STK_WTP_PDU_VERSION(pdu)          ((((unsigned char *)pdu)[3] >> 6) & 0x3)
#define STK_WTP_PDU_TIDNEW(pdu)           (((unsigned char *)pdu)[3] & 0x20)
#define STK_WTP_PDU_USER_ACK(pdu)         (((unsigned char *)pdu)[3] & 0x10)
#define STK_WTP_PDU_TR_CLASS(pdu)         (((unsigned char *)pdu)[3] & 0x03)

#endif
#endif
