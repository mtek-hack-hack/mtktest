/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    mexe_struct.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for MExE appliction.
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

#ifndef _MEXE_STRUCTURE_H_
#define _MEXE_STRUCTURE_H_

#include "kal_non_specific_general_types.h"

typedef enum
{
    MExE_CERTIFICATE_WTLS,
    MExE_CERTIFICATE_X509,
    MExE_CERTIFICATE_X968,
    MExE_CERTIFICATE_ALL
} MExE_CERTIFICATE_ENUM;

typedef enum
{
    ROOT_PUBLIC_KEY_OPERATOR,      /* EF ORPK */
    ROOT_PUBLIC_KEY_ADMINISTRATOR, /* EF ARPK */
    ROOT_PUBLIC_KEY_PARTY,         /* EF TPRPK */
    ROOT_PUBLIC_KEY_NONE
} ROOT_PUBLIC_KEY_ENUM;

#define MAX_MExE_IDENTIFIER_LEN 128
#define MAX_MExE_DATA_LEN 1600

/*------------------------------------------------------------*/

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type; /* MExE_CERTIFICATE_ENUM */
    kal_uint16 mod_id;
} mmi_get_sim_certificate_req_struct;

/*---------------------------------------------------------*/

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 idx;
    kal_uint8 authority_certificate;
    kal_uint8 certificate_type;
    kal_uint16 data_length;
    kal_uint8 data[MAX_MExE_DATA_LEN];
    kal_uint16 key_identifier_length;
    kal_uint8 key_identifier[MAX_MExE_IDENTIFIER_LEN];
    kal_uint16 certificate_identifier_length;
    kal_uint8 certificate_identifier[MAX_MExE_IDENTIFIER_LEN];
} mmi_send_sim_certificate_record_ind_struct;

/*---------------------------------------------------------*/

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 next; /* TRUE: continue to send next, FALSE: abort to send */
} mmi_send_sim_certificate_record_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 total;
} mmi_get_sim_certificate_rsp_struct;

/*---------------------------------------------------------*/

#endif /* _MEXE_STRUCTURE_H_ */ 

