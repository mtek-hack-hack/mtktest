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
 * IPERF2MMI_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of IPERF and MMI.
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

#ifndef _IPERF2MMI_STRUCT_H_
#define	_IPERF2MMI_STRUCT_H_

#ifndef _IPERF_MMI_ENUMS_H_
#error	"iperf_mmi_enums.h should be included before iperf2mmi_struct.h"
#endif /* !_IPERF_MMI_ENUMS_H_ */


typedef struct
{
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       account_id;	/* Network account ID */    
    kal_uint8       job_id;	/* job id to avoid race condition */
    kal_bool        client;	/* -c: client mode */
    kal_bool        server;	/* -s: server mode */
    kal_bool        udp;	/* -u: udp or tcp */
    kal_bool        dual;	/* -d: dual testing mode */
    kal_uint32      faddr;	/* foreign address (client mode only) */
    kal_uint32      len;	/* -l: length of send buf, recv buf */
    kal_uint16      port;	/* -p: server port */
    kal_int32       window;	/* -w: TCP window size (socket buffer size) */
    kal_int32       mss;	/* -M: tcp mss */
    kal_uint32      bandwidth;	/* -b: udp bandwidth (bits/sec), UDP only*/
    kal_uint32      num;	/* -n: number of bytes to transmit */
    kal_uint32      time;	/* -t: time in seconds to transmit for, default=10 */
    iperf_tos       tos;	/* -S: type-of-service */
    kal_bool        rw_file;	/* read and write to file */
} mmi_iperf_run_req_struct;


typedef struct {
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       account_id;	/* Network account ID */    
    kal_bool        result;
} mmi_iperf_run_cnf_struct;


typedef struct {
    kal_uint8		ref_count;
    kal_uint16		msg_len;
    kal_uint8		account_id;	/* Network account ID */
    iperf_prot		prot;		/* protocl: TCP, UDP */
    kal_bool		result;		/* KAL_TRUE for success */

    kal_int32		xid;		/* transaction ID, not for display */
    double		    interval;	/* test interval (secs) */
    kal_uint32		transfer;	/* total data transferred (bytes) */
    double		    thruput;	/* measured throughput (bits/sec) */
    kal_int32       size;		/* TCP window size for TCP,
					   UDP buffer size for UdP */

    kal_uint32      laddr;		/* local addr, for 4-byte alignment */
    kal_uint32      faddr;		/* foreignaddr, for 4-byte alignment */
    kal_uint16      lport;		/* local port number */
    kal_uint16      fport;		/* foreign port number */

    /* below are UDP only */
    kal_int32       datagram_size;		/* send/recv datagram size */
    double		    jitter;		/* (ms) */
    kal_uint32		outorder;	/* number of out-of-order packets */
    kal_int32		lost_pkt;
    kal_int32		total_pkt;
    double		    loss_rate;	/* lost_pkt/total_pkt */

} mmi_iperf_report_ind_struct;

#endif /* !_IPERF2MMI_STRUCT_H_ */


