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
 *
 * Filename:
 * ---------
 * customer_cmux_setting.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the setting of CMUX.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"

#ifdef __CMUX_SUPPORT__

#define DEFAULT_BUFFER_SIZE 512 /* N1 = 64*/
#define DEFAULT_LOW_THRESHOLD 0
#define DEFAULT_HIGH_THRESHOLD 448
#define DATA_BUFFER_SIZE 2048 /* N1 = 512 */
#define DATA_LOW_THRESHOLD 0
#define DATA_HIGH_THRESHOLD 1536/* DATA_BUFFER_SIZE - N1 */


/*Channel definition - four options*/
#define CHANNEL_0 0x00
#define CHANNEL_1 0x01  // 0000 0001  -> data channel (only one channel can be set for data service)
#define CHANNEL_2 0x02  // 0000 0010  -> indication channel (unsolicited code)
#define CHANNEL_3 0x04  // 0000 0100  -> control channel    (AT command control)
                        // 0000 0110  -> control + indication channel (AT command control and unsolicited code)

#if (CHANNEL_1 == 0x01)
#define DATA_CHANNEL 1 
#elif (CHANNEL_2 == 0x01)
#define DATA_CHANNEL 2
#elif (CHANNEL_3 == 0x01)
#define DATA_CHANNEL 3
#endif

#define RX_BUFFER_SIZE_CH_0 DEFAULT_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_0 DEFAULT_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_0 DEFAULT_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_0 DEFAULT_BUFFER_SIZE

#if (DATA_CHANNEL == 1)
#define RX_BUFFER_SIZE_CH_1 DATA_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_1 DATA_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_1 DATA_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_1 DATA_BUFFER_SIZE
#else
#define RX_BUFFER_SIZE_CH_1 DEFAULT_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_1 DEFAULT_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_1 DEFAULT_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_1 DEFAULT_BUFFER_SIZE
#endif

#if (DATA_CHANNEL == 2)
#define RX_BUFFER_SIZE_CH_2 DATA_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_2 DATA_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_2 DATA_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_2 DATA_BUFFER_SIZE
#else
#define RX_BUFFER_SIZE_CH_2 DEFAULT_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_2 DEFAULT_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_2 DEFAULT_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_2 DEFAULT_BUFFER_SIZE
#endif

#if (DATA_CHANNEL == 3)
#define RX_BUFFER_SIZE_CH_3 DATA_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_3 DATA_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_3 DATA_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_3 DATA_BUFFER_SIZE
#else
#define RX_BUFFER_SIZE_CH_3 DEFAULT_BUFFER_SIZE
#define RX_BUFFER_LOW_THRESHOLD_CH_3 DEFAULT_LOW_THRESHOLD
#define RX_BUFFER_HIGH_THRESHOLD_CH_3 DEFAULT_HIGH_THRESHOLD
#define TX_BUFFER_SIZE_CH_3 DEFAULT_BUFFER_SIZE
#endif







static kal_uint8 rxBuffer_0[RX_BUFFER_SIZE_CH_0];
static kal_uint8 rxBuffer_1[RX_BUFFER_SIZE_CH_1];
static kal_uint8 rxBuffer_2[RX_BUFFER_SIZE_CH_2];
static kal_uint8 rxBuffer_3[RX_BUFFER_SIZE_CH_3];

static kal_uint8 txBuffer_0[TX_BUFFER_SIZE_CH_0];
static kal_uint8 txBuffer_1[TX_BUFFER_SIZE_CH_1];
static kal_uint8 txBuffer_2[TX_BUFFER_SIZE_CH_2];
static kal_uint8 txBuffer_3[TX_BUFFER_SIZE_CH_3];

typedef struct {
    kal_uint8 channel_type;
    int txBufferSize;
    kal_uint8 *txBuffer;
    int rxBufferSize;
    kal_uint8 *rxBuffer;
    int rxLowThreshold;
    int rxHighThreshold;
}DlcConfigStruct;

#define DLC_CONFIG(idx) { CHANNEL_ ## idx , \
                          TX_BUFFER_SIZE_CH_ ## idx , \
                          txBuffer_ ## idx , \
                          RX_BUFFER_SIZE_CH_ ## idx , \
                          rxBuffer_ ## idx , \
                          RX_BUFFER_LOW_THRESHOLD_CH_ ## idx , \
                          RX_BUFFER_HIGH_THRESHOLD_CH_ ## idx }

const DlcConfigStruct dlcConfig[]={
    DLC_CONFIG(0) ,
    DLC_CONFIG(1) ,
    DLC_CONFIG(2) ,
    DLC_CONFIG(3)
};


kal_uint8* cmux_getDlcRxBuffer(kal_uint8 channel,kal_uint32 *size,kal_uint32 *lowThreshold,kal_uint32 *highThreshold)
{
    *size = dlcConfig[channel].rxBufferSize;
    *lowThreshold  = dlcConfig[channel].rxLowThreshold;
    *highThreshold  = dlcConfig[channel].rxHighThreshold;
    return dlcConfig[channel].rxBuffer;
}

kal_uint8* cmux_getDlcTxBuffer(kal_uint8 channel,kal_uint32 *size)
{
    *size = dlcConfig[channel].txBufferSize;
    return dlcConfig[channel].txBuffer;
}

void cmux_releaseDlcBuffer(kal_uint8* buffer)
{
}

kal_uint8 cmux_get_channel_def(kal_uint8 channel)
{
    return dlcConfig[channel].channel_type;
}

#endif

