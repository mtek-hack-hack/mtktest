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
 *	mm_mmi_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for enum definition MM and MMI/L4.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _MM_MMI_ENUMS_H
#define _MM_MMI_ENUMS_H

typedef enum
{
    /* These enums are used between mm-sublayer, AS and MMI */
    NORMAL_DETACH = 0,
    POWER_SWITCHED_OFF = 1
}power_status_enum;

typedef enum
{
     GPRS_DETACH = 1,  /* 10.5.5.5, TS 24.008 */
     IMSI_DETACH_MS_TO_N,
     COMBINED_GPRS_IMSI_DETACH
}ms_to_nw_detach_type_enum;

typedef enum
{
     REATTACH_REQD = 1,  /* 10.5.5.5, TS 24.008 */
     REATTACH_NOT_REQD,
     IMSI_DETACH_N_TO_MS
}nw_to_ms_detach_type_enum;

typedef enum
{
    NO_STATUS = 1,
    PROC_STARTED,
    PROC_SUCCESSFUL,
    PROC_FAILED,
    PROC_REJECTED
}proc_status_enum;

/* These values are used in GMM, TCM and ATCI modules */
typedef enum
{
    NO_PROCEDURE = 1,
    INITIAL_CELL_SELECTION,
    ATTACH_PROCEDURE,
    DETACH_PROCEDURE,
    RAU_PROCEDURE,
    PERIODIC_RAU_PROCEDURE,
    NEW_CELL_UPDATE_PROCEDURE,
    SERVICE_PROCEDURE,
    COMBINED_RAU,
    COMBINED_RA_LA_WITH_IMSI_ATTACH,
    GMM_PAGE_RSP,
    SMS_EST_REQ,
    SM_DATA_REQ
}gmm_proc_enum;

/* Gor GPRS MMI. */
typedef enum {
	GMMREG_GPRS_CELL_FOUND,
	GMMREG_GPRS_REGISTERING
} gmmreg_ps_service_info_enum;

typedef enum {
       GMMREG_CIPHER_OFF,
	GMMREG_CIPHER_ON,
	GMMREG_CIPHER_INVALID=0xff
} gmmreg_cipher_ind_enum; /* ripple: cipher ind */

#define MAX_SIZE_OF_MS_RA_CAP  52
#define MAX_SIZE_OF_MS_NW_CAP  10
#define SIZE_OF_CLASSMARK1     1
#define SIZE_OF_CLASSMARK2     3
#define SIZE_OF_DRX_PARAMETER  2
#define MAX_NW_NAME_LENGTH     24
#define MAX_LSA_LENGTH         3

#endif


