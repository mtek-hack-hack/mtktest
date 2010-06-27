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
 *  wndrv_ft_types.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Data structures provided by WLAN network driver.
 *  These data structures are used between FT and WNDRV.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _WNDRV_FT_TYPES_H
#define _WNDRV_FT_TYPES_H

#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included before wndrv_ft_types.h"
#endif

#ifndef _WNDRV_CNST_H
#error "wndrv_cnst.h should be included before wndrv_ft_types.h"
#endif

/* --- Enums ---------------------------------------------------------------- */
typedef enum
{
   WNDRV_TEST_SET_STOP = 0x00,
   WNDRV_TEST_SET_CONT_TX,
   WNDRV_TEST_SET_LOCAL_FREQ,
   WNDRV_TEST_SET_CARRIER_SUPP,
   WNDRV_TEST_SET_PKT_TX,
   WNDRV_TEST_SET_PWR_MGT,
   WNDRV_TEST_SET_PKT_RX,
   WNDRV_TEST_SET_REG_DOMAIN,
   WNDRV_TEST_SET_DBM_TO_DAC,
   WNDRV_TEST_SET_MCR32,
   WNDRV_TEST_SET_MCR16,
   WNDRV_TEST_SET_BBCR,
   WNDRV_TEST_SET_EEPROM,
   WNDRV_TEST_SET_TEST_MODE,
   WNDRV_TEST_SET_END
} wndrv_test_set_data_enum;


typedef enum
{
   WNDRV_TEST_QUERY_PKT_TX = 0x00,
   WNDRV_TEST_QUERY_PKT_RX,
   WNDRV_TEST_QUERY_CH_ID_LIST,
   WNDRV_TEST_QUERY_RX_COUNTER,
   WNDRV_TEST_QUERY_DBM_TO_DAC,
   WNDRV_TEST_QUERY_MCR32,
   WNDRV_TEST_QUERY_MCR16,
   WNDRV_TEST_QUERY_BBCR,
   WNDRV_TEST_QUERY_EEPROM,
   WNDRV_TEST_QUERY_DAC_IQ_OFFSET_CAL,
   WNDRV_TEST_QUERY_END
} wndrv_test_query_result_enum;

typedef enum
{  
   WNDRV_TEST_RATE_1M = 0,     /* 1M          */
   WNDRV_TEST_RATE_2M,         /* 2M          */
   WNDRV_TEST_RATE_5_5M,       /* 5.5M        */
   WNDRV_TEST_RATE_11M,        /* 11M         */
   WNDRV_TEST_RATE_6M,         /* 6M          */
   WNDRV_TEST_RATE_9M,         /* 9M          */
   WNDRV_TEST_RATE_12M,        /* 12M         */
   WNDRV_TEST_RATE_18M,        /* 18M         */
   WNDRV_TEST_RATE_24M,        /* 24M         */
   WNDRV_TEST_RATE_36M,        /* 36M         */
   WNDRV_TEST_RATE_48M,        /* 48M         */
   WNDRV_TEST_RATE_54M,        /* 54M         */
   WNDRV_TEST_RATE_COUNT       /* Total count */
} wndrv_test_rate_enum;


typedef enum
{  WNDRV_TX_ALL_ZEROS,
   WNDRV_TX_ALL_ONES,
   WNDRV_TX_ALTERNATE_BITS,
   WNDRV_TX_PSEUDO_RANDOM
} wndrv_test_pkt_tx_pattern_enum;


typedef enum
{  
   WNDRV_POWER_MODE_NORMAL,
   WNDRV_POWER_MODE_IDLE,
   WNDRV_POWER_MODE_SLEEP
} wndrv_test_pwr_mgt_enum;


typedef enum
{    
   WNDRV_STOP_RX,
   WNDRV_RF_RX_TEST_MODE  /* For RF Test use */
} wndrv_test_rx_mode_enum;


typedef enum
{
  WNDRV_RX_ANT_DIVERSITY_AGC,  /* AGC based selection */
  WNDRV_RX_ANT_DIVERSITY_MPDU, /* MPDU based selection */
  WNDRV_RX_ANT_FIXED_0,        /* Always 0 */ 
  WNDRV_RX_ANT_FIXED_1         /* Always 1 */
} wndrv_test_rx_ant_sel_enum;


typedef enum
{
  WNDRV_HOST_INTERFACE_SDIO,
  WNDRV_HOST_INTERFACE_HPI,
  WNDRV_HOST_INTERFACE_SPI,
  WNDRV_HOST_INTERFACE_CF_MEM,
  WNDRV_HOST_INTERFACE_CF_IO  
} wndrv_test_host_interface_enum;

/* --- Structs -------------------------------------------------------------- */

typedef struct
{
   kal_uint32            ch_freq;/* Frq, units are kHz */
   wndrv_test_rate_enum  tx_rate;
   kal_uint8             txAnt;  /* 0 for Antenna 0 and 1 for Antenna 1 */
   kal_uint16            tx_gain_dac;
} wndrv_test_tx_struct;


typedef struct
{
   kal_uint32                       ch_freq;           /* Frq, units are kHz */
   wndrv_test_rate_enum             tx_rate;           
   kal_uint16                       tx_gain_dac;       
   kal_uint32                       pktCount;          
   kal_uint32                       pktInterval;       /* interval between each Tx Packet */
   kal_uint32                       pktLength;         /* 24~1500 */
   wndrv_test_pkt_tx_pattern_enum   pattern;           /* content of the Tx Packet */
   kal_uint8                        txAnt;             /* 0 for Antenna 0 and 1 for Antenna 1 */
   kal_bool                         is_short_preamble; /* 0 for long preamble and 1 for short preamble */
   kal_uint8                        mac_header[ 24 ];  /* Frame Ctrl, Duration = 2bytes + 2bytes */
                                                       /* Address 1 = 6 bytes */ 
                                                       /* Address 2 = 6 bytes */ 
                                                       /* Address 3 = 6 bytes */ 
                                                       /* Sequence Ctrl = 2 bytes */
} wndrv_test_pkt_tx_struct;

typedef struct
{
   kal_uint32                  ch_freq;  /* Frq, units are kHz */
   wndrv_test_rate_enum             tx_rate;           
   kal_uint16                       tx_gain_dac;       
   kal_uint32                       pktCount;          
   kal_uint32                       pktInterval;       /* interval between each Tx Packet */
   kal_uint32                       pktLength;         /* 24~1500 */
   wndrv_test_pkt_tx_pattern_enum   pattern;           /* content of the Tx Packet */
   kal_uint8                        txAnt;             /* 0 for Antenna 0 and 1 for Antenna 1 */
   kal_uint32                       txFlags;
   kal_uint32                       targetAlc;
   kal_bool                         is_short_preamble; /* 0 for long preamble and 1 for short preamble */
   kal_uint8                        mac_header[ 24 ];  /* Frame Ctrl, Duration = 2bytes + 2bytes */
                                                       /* Address 1 = 6 bytes */ 
                                                       /* Address 2 = 6 bytes */ 
                                                       /* Address 3 = 6 bytes */ 
                                                       /* Sequence Ctrl = 2 bytes */
} wndrv_test_pkt_tx_structEX;

typedef struct
{
   kal_uint32                  ch_freq;  /* Frq, units are kHz */
   wndrv_test_rx_mode_enum     mode;
   wndrv_test_rx_ant_sel_enum  rxAnt;
} wndrv_test_pkt_rx_struct;


typedef struct
{
   kal_uint32            ch_freq; /* Frq, units are kHz */
   wndrv_test_rate_enum  tx_rate;
   kal_int32             dbm;
} wndrv_test_dbm2dac_struct;


typedef struct
{    
   kal_uint32  pkt_sent_count;  /* total num sent */
   kal_uint32  pkt_sent_acked;  /* acked num */    
} wndrv_test_tx_status_struct;

typedef struct
{    
   kal_uint32  pkt_sent_count;  /* total num sent */
   kal_uint32  pkt_sent_acked;  /* acked num */
   kal_uint16  avgAlc;
   kal_uint8   cckGainControl;
   kal_uint8   ofdmGainControl;
} wndrv_test_tx_status_structEX;

typedef struct
{    
   kal_uint32   int_rx_ok_num;          /* number of packets that Rx ok from interrupt */
   kal_uint32   int_crc_err_num;        /* number of packets that CRC error from interrupt */
   kal_uint32   pau_rx_pkt_count;       /* number of packets that Rx ok from PAU */
   kal_uint32   pau_crc_err_count;      /* number of packets that CRC error from PAU */
   kal_uint32   pau_cca_count;          /* CCA rising edge count */
   kal_uint32   pau_rx_fifo_full_count; /* number of lost packets due to FiFo full */
   kal_uint32   int_long_preamble_num;
   kal_uint32   int_short_preamble_num;
   kal_uint32   int_rate_ok_num[ WNDRV_TEST_RATE_COUNT ];
   kal_uint32   int_rate_crc_err_num[ WNDRV_TEST_RATE_COUNT ];
   kal_int32    int_rssi_max;
   kal_int32    int_rssi_min;
   kal_int32    int_rssi_mean;
   kal_int32    int_rssi_variance;
   kal_uint32   packetSize[WNDRV_PACKET_SIZE_COUNT];  /* 0~63, 64~127, 128~255, 256~511, 512~1023, 1024~2047 */
   kal_uint32   packetType[WNDRV_PACKET_TYPE_COUNT];   /* Data, Management, Control */
} wndrv_test_rx_status_struct;


typedef struct
{    
   kal_uint32 ch_num;    
   kal_uint8  ch_id[64];
} wndrv_test_ch_id_list_struct;


typedef struct
{    
   kal_int32  ED;    
   kal_int32  OSD;    
   kal_int32  SQ1;    
   kal_int32  SFD;    
   kal_int32  CRC16;
} wndrv_test_rx_counter_struct;


typedef struct
{
  /*  I channel:
      Bit 4: TXOS_CAL_ID[5]
      Bit 3: TXOS_CAL_ID[4]
      Bit 2: TXOS_CAL_ID[3]
      Bit 1: TXOS_CAL_ID[2]
      Bit 0: TXOS_CAL_ID[1]
      
      Q channel:
      Bit 4: TXOS_CAL_QD[5]
      Bit 3: TXOS_CAL_QD[4]
      Bit 2: TXOS_CAL_QD[3]
      Bit 1: TXOS_CAL_QD[2]
      Bit 0: TXOS_CAL_QD[1]         
   */
   kal_uint8  dac_i_ch_offset;
   kal_uint8  dac_q_ch_offset;
} wndrv_test_dac_iq_offset_struct;


typedef struct
{
   kal_uint32                      bb_chip_id;
   kal_char                        bb_chip_ver[32];
   kal_uint32                      rf_chip_id;
   kal_char                        rf_chip_ver[32];
   kal_bool                        support_802_11b;   
   kal_bool                        support_802_11a;     
   kal_bool                        support_802_11g;
   kal_bool                        eeprom_exist;
   kal_uint32                      eeprom_size;   /* unit is byte */
   wndrv_test_host_interface_enum  host_interface;
} wndrv_query_chip_capability_struct;


/* Note wndrv_test_peer_buff_mcr32_struct is used in peer_buff_ptr. */
typedef struct
{
   kal_uint32  mcr_index;   /* Addressing space is 0x000 ~ 0x512. */ 
   kal_uint32  mcr32;
} wndrv_test_peer_buff_mcr32_struct;


/* Note wndrv_test_peer_buff_mcr16_struct is used in peer_buff_ptr. */
typedef struct
{
   kal_uint32  mcr_index;   /* Addressing space is 0x000 ~ 0x512. */ 
   kal_uint16  mcr16;
} wndrv_test_peer_buff_mcr16_struct;


/* Note wndrv_test_peer_buff_bbcr_struct is used in peer_buff_ptr. */
typedef struct
{
   kal_uint32  bbcr_index;  /* Addressing space is 0x00 ~ 0x7f. */  
   kal_uint8   bbcr;
} wndrv_test_peer_buff_bbcr_struct;


/* Note wndrv_test_peer_buff_eeprom_struct is used in peer_buff_ptr. */
typedef struct
{
   kal_uint32  eeprom_index; /* Addressing space is determined by eeprom size. */
   kal_uint16  eeprom;
} wndrv_test_peer_buff_eeprom_struct;


/* --- Unions --------------------------------------------------------------- */

typedef union
{
   kal_int32                      dummy1;          /* WNDRV_TEST_SET_STOP         */
   wndrv_test_tx_struct           cont_tx;         /* WNDRV_TEST_SET_CONT_TX      */
   wndrv_test_tx_struct           local_freq;      /* WNDRV_TEST_SET_LOCAL_FREQ   */
   wndrv_test_tx_struct           carrier_supp;    /* WNDRV_TEST_SET_CARRIER_SUPP */
   wndrv_test_pkt_tx_structEX     pkt_tx;          /* WNDRV_TEST_SET_PKT_TX       */
   wndrv_test_pwr_mgt_enum        pwr_mgt;         /* WNDRV_TEST_SET_PWR_MGT      */
   wndrv_test_pkt_rx_struct       pkt_rx;          /* WNDRV_TEST_SET_PKT_RX       */
   kal_uint8                      country_code[2]; /* WNDRV_TEST_SET_REG_DOMAIN   */
   wndrv_test_dbm2dac_struct      dbm2dac;         /* WNDRV_TEST_SET_DBM_TO_DAC   */
   kal_int32                      dummy2;          /* WNDRV_TEST_SET_MCR32        */
   kal_int32                      dummy3;          /* WNDRV_TEST_SET_MCR16        */
   kal_int32                      dummy4;          /* WNDRV_TEST_SET_BBCR         */
   kal_int32                      dummy5;          /* WNDRV_TEST_SET_EEPROM       */
   kal_uint8                      test_mode;       /* WNDRV_TEST_SET_TEST_MODE    */
} wndrv_test_set_data_union;


typedef union
{
   wndrv_test_tx_status_structEX    pkt_tx;         /* WNDRV_TEST_QUERY_PKT_TX            */
   wndrv_test_rx_status_struct      pkt_rx;         /* WNDRV_TEST_QUERY_PKT_RX            */
   wndrv_test_ch_id_list_struct     ch_id_list;     /* WNDRV_TEST_QUERY_CH_ID_LIST        */
   wndrv_test_rx_counter_struct     rx_counter;     /* WNDRV_TEST_QUERY_RX_COUNTER        */
   kal_uint16                       tx_gain_dac;    /* WNDRV_TEST_QUERY_DBM_TO_DAC        */
   kal_int32                        dummy1;         /* WNDRV_TEST_QUERY_MCR32             */
   kal_int32                        dummy2;         /* WNDRV_TEST_QUERY_MCR16             */
   kal_int32                        dummy3;         /* WNDRV_TEST_QUERY_BBCR              */
   kal_int32                        dummy4;         /* WNDRV_TEST_QUERY_EEPROM            */
   wndrv_test_dac_iq_offset_struct  iq_offset;      /* WNDRV_TEST_QUERY_DAC_IQ_OFFSET_CAL */
} wndrv_test_query_result_union;


#endif /* _WNDRV_FT_TYPES_H */

