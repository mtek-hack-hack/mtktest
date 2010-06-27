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
 * Filename:
 * ---------
 * NITZ.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * This file defines prototypes and structure of NITZ application.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************
   FILENAME : NITZ.h
   PURPOSE     : NITZ Inlcude File
   REMARKS     : nil
   AUTHOR      : Restructured by Gurinder
   DATE     : Restructured on Dec-01-2003
**************************************************************/
#ifndef _MMI_NITZ_H
#define _MMI_NITZ_H

#include "MMI_features.h"
#if defined(__MMI_NITZ__)
#include "MMIDataType.h"
#include "DateTimeType.h"
#include "NITZResDef.h"

/* 
 * Define
 */
#define NITZ_NOTIFY_LENGTH 250
#ifndef NEGATIVE
#define NEGATIVE 0
#endif 

#ifndef POSITIVE
#define POSITIVE 1
#endif 

/* 
 * Typedef 
 */
typedef struct
{
    S16 NITZTimeZone;
    MYTIME NITZTime;
    MYTIME RecvTime;    /* received time of NITZ message */
    S8 *Message;
    U8 IsNITZPending;
    S8 IsAccepted;
    U8 NWFullName[MAX_NW_LEN *ENCODING_LENGTH];
    U8 NWShortName[MAX_NW_LEN *ENCODING_LENGTH];
    BOOL AddCI;
    U8 isValidTZ;
#ifdef __MMI_NITZ_TZ_SUPPORT__
    S16 NITZDST;
    U8 TimeZoneP;
    U8 DSTP;
#endif
} nitz_context_struct;

/* 
 * Extern Global Variable
 */
extern nitz_context_struct g_nitz_cntx;

/* 
 * Extern Global Function
 */

extern void NITZHandler(void *);
extern void EntryNitzScreen(void);
extern void ExitNitzScreen(void);
extern void NITZIgnore(void);
extern void NITZAccept(void);
extern S16 NITZGetTimeZone(U8);
extern U8 NITZConvertTime(U8);
extern S8 *NITZMessageString(void);
extern void NITZTimeZoneString(S16 timezone, S8 *string);
extern U8 mmi_nitz_get_nw_name(U8 dcs, U8 len, BOOL add_ci, S8 *dstStr, S8 *srcStr);
extern U8 mmi_nitz_check_dt(void);
extern void mmi_nitz_get_nitz_nw_name(U8* plmn, U8* nwname, U8 len, BOOL* add_ci);
#ifdef __MMI_DUAL_SIM__
extern void mmi_nitz_get_nitz_nw_name_sim2(U8* plmn, U8* nwname, U8 len, BOOL* add_ci);
#endif /*__MMI_DUAL_SIM__*/
extern void mmi_nitz_write_nw_name_to_nvram(U8 sim_type, nitz_nw_name_struct *nw_name);

extern void mmi_nitz_time_res_rsp(void *info);

#ifdef __MMI_NITZ_TZ_SUPPORT__
extern U8 mmi_nitz_check_tz(void);
#endif 
#endif /* defined(__MMI_NITZ__) */ 
#endif /* _MMI_NITZ_H */ 

