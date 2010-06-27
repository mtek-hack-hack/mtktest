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
 *   mmi_l3_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _MMI_L3_ENUMS_H
#define _MMI_L3_ENUMS_H

#define MAX_PDP_ADDR_LEN        16
#define MAX_APN_LEN             100

/* Modified by: CH_Liang 2005.01.25 */
#define MAX_EXT_PDP_CONTEXT	3
/* End of Modification, 2005.03.19. Reviewed by: Joseph */

/* SM/SNDCP related enumerations */ 

/* Modified by: CH_Liang 2005.01.25 */
#define TOT_NSAPI     GPRS_MAX_PDP_SUPPORT 
/* End of Modification, 2005.03.19. Reviewed by: Joseph */

#define QOS_LEN       11 /* 11 bytes is the Qos length */

/* Important Parameters related to NSAPI Values */
typedef enum
{
     NO_NSAPI = 0X00,
     MIN_VALID_NSAPI = 0X05,
/* Modified by: CH_Liang 2005.01.25 */
     MAX_VALID_NSAPI = MIN_VALID_NSAPI + GPRS_MAX_PDP_SUPPORT - 1
/* End of Modification, 2005.03.19. Reviewed by: Joseph */
}nsapi_session_enum;

typedef enum
{
/* Modified by: CH_Liang 2005.01.25 */
     TOT_MS_INITIATED_CONTEXT = GPRS_MAX_PDP_SUPPORT,
     TOT_NW_INITIATED_CONTEXT = GPRS_MAX_PDP_SUPPORT
/* End of Modification, 2005.03.19. Reviewed by: Joseph */
}max_contexts_enum;

/* Joseph:
 * This enum defination is used between 
 * TCM and SM and should SYNC with l4c_source_id_enum@l4c_common_enums.h
 */
typedef enum
{
   LMMI_ID,
   RMMI_ID,
   SAT_ID,
   INVALID_MMI_ID
} mmi_source_id_enum;


/* The following definitions have been packed in enumeration for future
 * increase of compression algorithms */

typedef enum
{
    SND_RFC_1144,
    SND_NUM_OF_PCOMP_ALGOS,
    SND_NO_PCOMP
}snd_pcomp_algo_enum;

typedef enum
{
    SND_V42_BIS,
    SND_NUM_OF_DCOMP_ALGOS,
    SND_NO_DCOMP
}snd_dcomp_algo_enum;

typedef enum
{
   PAP_AUTH,
   CHAP_AUTH
} pdp_auth_enum;
typedef enum
{
     IPV4_ADDR_TYPE = 0X21,
     IPV6_ADDR_TYPE = 0X67,
     PPP_ADDR_TYPE  = 0X01,
     OSP_IHOSS_ADDR_TYPE = 0X02,
     NULL_PDP_ADDR_TYPE = 0X03 /* This is added incase if no pdpaddrtype is 
                                  specified */
}pdp_addr_type_enum;

typedef enum
{
     IPV4_ADDR_LEN = 0X04,
     IPV6_ADDR_LEN = 0X10,
     PPP_ADDR_LEN  = 0X0,
     OSP_IHOSS_ADDR_LEN = 0X0,
    /* NULL_PDP_ADDR_LEN = 0X02  Incase if no pdpaddr is specified then this
                                 length will be null */
    NULL_PDP_ADDR_LEN = 0X01
}pdp_addr_len_enum;

typedef enum
{
     MIN_QOS_MOD = 1,
     REQ_QOS_MOD,
     TFT_MOD,
     TFT_MIN_QOS_MOD,
     TFT_REQ_QOS_MOD,
     PDP_ADDR_MOD,
     NEG_QOS_MOD,
     PDP_ADDR_NEG_QOS_MOD,
     NO_MOD
}context_mod_type_enum;

#endif


