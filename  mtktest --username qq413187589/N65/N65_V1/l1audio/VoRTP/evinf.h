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
 *   evinf.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   VoIP event logging definition
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef EVINF_DOT_H
#define EVINF_DOT_H

/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define EVINF_SYNCWORD                  0xAA55
#ifndef NULL
#define NULL                            0
#endif
#define INF_CONFIG_BASE                 0x0000
#define INF_VORTP_BASE                  0x0100
#define INF_NW_BASE                     0x0200

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
#ifndef UINT16
#define UINT16                          unsigned short
#define INT16                           signed short
#define UINT32                          unsigned long
#define INT32                           signed long
#define UINT8                           unsigned char
#define CHAR                            char
#define INT8                            signed char
#define BITSFIELD                       unsigned int
#endif
//#ifndef BOOL
//typedef enum { FALSE, TRUE} BOOL;
//#endif

typedef UINT32                          TICK;

#define _EVINF_HDR_ \
   UINT16           uSyncword;   /* event sync word */                      \
   UINT16           uInfoID;     /* the event info ID */                    \
   TICK             tFlush;      /* tick of the event flush */              \
   UINT32           uInfoLength; /* info length in bytes, including header */

typedef struct {
   _EVINF_HDR_
} EVINF_HEADER; /* followed by info-specific structural data */

#define EVINF_WRITE_HDR(ev,t,id,len) \
{                                    \
   (ev).uSyncword = EVINF_SYNCWORD;  \
   (ev).uInfoID = (UINT16)(id);      \
   (ev).tFlush = (TICK)(t);          \
   (ev).uInfoLength = (UINT32)(len); \
}

typedef enum {
   INF_CONFIG_MASK = INF_CONFIG_BASE,
   INF_CONFIG_CMD,

   INF_VORTP_MASK = INF_VORTP_BASE,
   INF_VORTP_ULSES_START,
   INF_VORTP_DLSES_START,
   INF_VORTP_ENCODING,
   INF_VORTP_DECODING,
   INF_VORTP_ULPKT_BORN,
   INF_VORTP_ULPKT_SENT,
   INF_VORTP_DLPKT_ARRIVE,
   INF_VORTP_DLPKT_PLAY,
   INF_VORTP_JITTER_PREBUFFER,
   INF_VORTP_JITTER_TIME,
   INF_VORTP_JITTER_SHRINK,
   
   INF_NW_RSSI = INF_NW_BASE, // Trace average and current RSSI (when RSSI below threshold)
   INF_NW_DISCONNECT,   // Trace disconnect AP
   INF_NW_CONNECT,      // Trace connect AP
   INF_NW_TX_FAIL,      // Trace TX retry fail
   INF_NW_SCAN_BEGIN,   // Trace scan begin and end
   INF_NW_SCAN_END,     // Trace scan begin and end
   INF_NW_ROAM_BEGIN,   // Trace roaming begin and end
   INF_NW_ROAM_END,     // Trace roaming begin and end
   INF_NW_TX_LINK_RATE, // Trace TX link rate
   INF_NW_AUTH_FAIL,    // Trace authentication fail
   INF_NW_ASSOC_FAIL,   // Trace association fail
   INF_NW_RX_DEAUTH,    // Trace receiving deauthenticate

   
   INF_ID_MAX = 0x7fff
} EVINF_INFO_ID;

/* Below define the enet info structure, all should be aligned to 2-byte boundary */

typedef struct {
   _EVINF_HDR_
   UINT16           uCodecType;
   UINT16           uCodecCapLength;
   UINT8            uSessionID;
   UINT8            PADDING;
} INF_VORTP_ULSES_START_STRUCT, INF_VORTP_DLSES_START_STRUCT; /* followed by codec capability data */

typedef struct {
   _EVINF_HDR_
   TICK             uTicksPerSecond;
   TICK             uTicksWrapped;
} INF_CONFIG_CMD_STRUCT;

typedef struct {
   _EVINF_HDR_
   TICK             tBegin;
   TICK             tEnd;
   UINT16           uPCMLength;
   UINT16           uBitstreamLength;
   UINT16           uCodecType; 
   UINT8            uFrameType;
   UINT8            uFrameInfo;
   UINT8            uSessionID;
   UINT8            PADDING;
} INF_VORTP_ENCODING_STRUCT, INF_VORTP_DECODING_STRUCT; /* followed by PCM and bitstream data */

typedef struct {
   _EVINF_HDR_
   UINT32           uRTPTimestamp;
   UINT16           uCodecType;
   UINT16           uRTPPayloadSize;
   UINT8            uFIFOWriteIdx;
   UINT8            uFIFOReadIdx;
   UINT8            uSessionID; // UINT8            bMarker:1, uSessionID:7;
   UINT8            PADDING;
} INF_VORTP_ULPKT_BORN_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uRTPTimestamp;
   TICK             tDelay;
   UINT16           uCodecType;
   UINT16           uRTPPayloadSize;
   UINT8            uFIFOWriteIdx;
   UINT8            uFIFOReadIdx;
   UINT8            uSessionID; // UINT8            bMarker:1, uSessionID:7;
   UINT8            PADDING;
} INF_VORTP_ULPKT_SENT_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uRTPTimestamp;
   UINT16           uCodecType;
   UINT16           uRTPPayloadSize;
   UINT16           uRTPSeqNo;
   UINT8            uJitterDepth;
   UINT8            uSessionID; // UINT8            bMarker:1, uSessionID:7;
} INF_VORTP_DLPKT_ARRIVE_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uRTPTimestamp;
   TICK             tDelay;
   UINT16           uCodecType;
   UINT16           uRTPPayloadSize;
   UINT16           uRTPSeqNo;
   UINT8            uJitterDepth;
   UINT8            uSessionID; // UINT8            bMarker:1, uSessionID:7;
} INF_VORTP_DLPKT_PLAY_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uGetTimestamp;
   UINT32           uOldestTimestamp;
   UINT32           uNewestTimestamp;
   BITSFIELD        uCurrentJitterTime:16, 
                    bPrebuffering:1, 
                    uInitiator:3, 
                    uConsecutiveBufferOverruns:6, 
                    uConsecutiveMarkerBits:6;
   UINT8            uSessionID;
   UINT8            PADDING;
} INF_VORTP_JITTER_PREBUFFER_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uOldestTimestamp;
   UINT32           uNewestTimestamp;
   UINT16           uPreviousJitterTime;
   UINT16           uCurrentJitterTime;
   UINT8            uJitterDepth;
   UINT8            uSessionID;
} INF_VORTP_JITTER_TIME_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uOldestTimestamp;
   UINT32           uNewestTimestamp;
   UINT16           uPreviousJitterTime;
   UINT16           uCurrentJitterTime;
   UINT8            uJitterDepth;
   UINT8            uSessionID;
   INT32            uJitterMean;
   INT32            uJitterVar;
   UINT16           uIncThreshold;
   UINT16           uDecThreshold;
} INF_VORTP_JITTER_TIME2_STRUCT;

typedef struct {
   _EVINF_HDR_
   BITSFIELD        uState:4,
                    uConfig:4,
                    uSessionID:8,
                    uDelayDiff:16;
} INF_VORTP_JITTER_SHRINK_STRUCT;

typedef struct {
   _EVINF_HDR_
   UINT32           uParm;
} INF_NW_EV_STRUCT;

/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/

/*****************************************************************************
*                  D A T A   D E C L A R A T I O N S
******************************************************************************
*/

/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/

/*****************************************************************************
*       I N L I N E   F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/

#endif

