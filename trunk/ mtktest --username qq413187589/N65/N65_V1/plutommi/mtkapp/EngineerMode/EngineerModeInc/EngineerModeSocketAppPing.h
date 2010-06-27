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
 * EngineerModeSocketAppPing.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implement the engineer mode ping appliaction
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* MTK Add Robin 1001 for saperate MMI feature by project */
#include "MMI_features.h"
/* MTK End */

#if (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__))

/* Define constance */
#define MAX_PDU_LENGTH 1500
#define MAX_UL_PDU_LENGTH 8192

/* Import necessary functions */
#if MTK_KAL_MNT
#define TMD_System_Clock (0)
#else 
extern kal_int32 TMD_System_Clock;
#endif 

/* Macros */
#define PING_CONTEXT_INFO(x)       ((ping_ptr)->x)

/* Structs */
typedef struct
{
    kal_uint8 state;
    kal_int8 socketId;
    kal_uint16 pingCount;
    kal_uint16 pingSize;
    kal_char inputBuffer[MAX_UL_PDU_LENGTH];
    kal_uint32 pingStartFN;
    kal_uint32 pingEndFN;
    sockaddr_struct pingSrvAddr;
    kal_uint16 timeOutMS;

    /* Ongoing information */
    kal_uint16 currCount;
    kal_uint16 seqNo;

    /* Statistic information */
    kal_uint32 maxRspMS;
    kal_uint32 minRspMS;
    kal_uint32 avgRspMS;
    kal_uint32 rcvdCounter;
    kal_uint32 lostCounter;

    kal_uint8 *echo_req;
    kal_uint8 *echo_rsp;

} ping_context_struct;

/* Enums */
typedef enum
{
    PING_INACTIVE = 0,
    PING_ACTIVE
} ping_state_enum;

#if ( defined(MMI_ON_WIN32))
#define kal_sprintf       sprintf
#define kal_mem_set       memset
#define free_ctrl_buffer  OslMfree
#define get_ctrl_buffer    OslMalloc
#define soc_close
#define kal_print
#define soc_sendto
#define ASSERT
#define soc_recv
#define soc_bind
#define soc_setsockopt
#define soc_create
#elif ( !defined(__MTK_TARGET__) )
#define kal_print
#define soc_close
#define soc_sendto
#define soc_recv
#define soc_bind
#define soc_setsockopt
#define soc_create
#endif 

#endif /* (defined(__MMI_ENGINEER_MODE__) && defined(__MMI_GPRS_PING_APP__) && defined(__TCPIP__) && defined(__PS_SERVICE__)) */ 

