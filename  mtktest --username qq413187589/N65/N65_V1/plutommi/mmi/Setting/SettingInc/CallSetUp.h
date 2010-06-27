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
 * CallSetUp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   <file description>.
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : Callorwarding.h

   PURPOSE     : Call application 

   REMARKS     : nil

   AUTHOR      : Vandana Dhawan 

   DATE     : 29th April 2003 

**************************************************************/

#ifndef _PIXTEL_CALLFORWARDINGSTRUCT_H
#define _PIXTEL_CALLFORWARDINGSTRUCT_H

/* micha0727 */
#include "PhoneBookTypes.h"

#define CS_NOTIFYDURATION              UI_POPUP_NOTIFYDURATION_TIME

#define LINE1 0
#define LINE2 1
#define MAX_LINE_NUM 2
#define BARR_SIM_PASS_LEN  4
#define MAX_CTR_NUM_DIGITS 6
#define MAX_DISP_UCS2      400*ENCODING_LENGTH

typedef enum
{
    CF_COND_STAGE_NONE,
    CF_COND_STAGE_UNREACH,
    CF_COND_STAGE_NOANS,    
    CF_COND_STAGE_BUSY,        
    CF_COND_STAGE_TOTAL
} CF_COND_STAGE_ENUM;


typedef struct
{
    U8 CallerID;
    U8 CallerIDInput;
    U8 CTRStatus;
    U8 CTRStatusInput;
    U8 CTRNumber[MAX_CTR_NUM_DIGITS *ENCODING_LENGTH];
    U8 CTRNumberInput[MAX_CTR_NUM_DIGITS *ENCODING_LENGTH];
    U8 CTDStatus;
    U8 CTDInput;
    U8 AutoRedialStatus;
    U8 AutoRedialInput;
    U8 LineID;
    U8 LineIDInput;
#ifdef __MMI_LINE_SWITCH_SHOW_NUMBER__
    U8 LineInfo[(MAX_PB_NUMBER_LENGTH + 25) *ENCODING_LENGTH];
#else 
    U8 LineInfo[25 *ENCODING_LENGTH];
#endif 
    U8 SSDisplayBuffer[MAX_DISP_UCS2];
    U8 SSBarPassStep;
    U8 SSBarType;
    U8 SSBarAction;
    U8 SSBarPassOld[BARR_SIM_PASS_LEN *ENCODING_LENGTH + 4];
    U8 SSBarPassNew[BARR_SIM_PASS_LEN *ENCODING_LENGTH + 4];
    U8 SSBarPassCfrm[BARR_SIM_PASS_LEN *ENCODING_LENGTH + 4];
    U8 SSCFType;
    U8 SSCFCondQueryStage;
    U8 SSCFNum[(MAX_CC_ADDR_LEN *ENCODING_LENGTH) + 2];
    U8 SSCFNumFromPHB;
    U8 SSCFNoAnsTimeIndex;
} CallSetupContext;

extern CallSetupContext g_callset_context;

extern void CALLSETWaitingRsp(void *);
extern void CALLSETForwardRsp(void *);
extern void CALLSETBarringRsp(void *);
extern void CALLSETBarringPassRsp(void *);
extern void AppendBScodeString(U8, PS8);
extern void CALLSETLineInUseRsp(void *);
extern void CALLSETClipRsp(void *info);
extern void CALLSETClirRsp(void *info);
extern void CALLSETColpRsp(void *info);
extern void CALLSETColrRsp(void *info);
extern void CALLSETCnapRsp(void *info);
extern void CALLSETCcbsQueryRsp(void *info);
extern void ResetCFCondStage(void);

/* micha1228 */
extern void CALLSETEmlppQueryRsp(void *info);
extern void EntryCALLSETGeneralSSResut(void);

#ifdef __MMI_SS_SHOW_CAUSE__
extern void ShowCauseString(U16, PS8);
#endif 

/* IP Number begin */

#define MAX_IP_NUMBER      3
#define MAX_IP_NUMBER_LEN  10

/* Start by Julia */
#define MAX_BLACK_LIST_NUMBER 5
#define MAX_BLACK_LIST_NUMBER_LEN   20
/* End by Julia */

#endif /* _PIXTEL_CALLFORWARDINGSTRUCT_H */ 

