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
 * custom_uc_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains unified composer configuration constant. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_UC_CONFIG_H
#define _CUSTOM_UC_CONFIG_H

#ifdef __UNIFIED_COMPOSER_SUPPORT__

#ifndef _CUSTOM_WAP_CONFIG_H
#error "Please include custom_wap_config.h first"
#endif 

#include "customer_ps_inc.h"

/* If the text content exceeds this value, send the msg by MMS rather than SMS. */
#define MMI_UC_CUSTOM_MAX_MO_SMS_SEGMENT (MMI_SMS_MAX_MSG_SEG)

#define MMI_UC_CUSTOM_MAX_FILE_PATH_LEN         (260) /* refer to FMGR_MAX_PATH_LEN */

#if (defined(OBIGO_Q05A) && defined(MMS_SUPPORT))  /*Note: if mms solution changes, aslo check if need to update here*/
#define MMI_UC_CUSTOM_MAX_ADDR_LEN		(312) 
#else /* OBIGO_Q05A,  MMS_SUPPORT*/
#define MMI_UC_CUSTOM_MAX_ADDR_LEN		(60) /* refer to MMI_UC_MAX_ADDR_LEN */
#endif /* OBIGO_Q05A,  MMS_SUPPORT */

#define MMI_UC_ADM_MEM_SIZE    ((WAP_CUSTOM_CFG_MAX_MMS_SLIDES * MMI_UC_CUSTOM_MAX_FILE_PATH_LEN * 2 * 2) + \
                                (WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT * MMI_UC_CUSTOM_MAX_FILE_PATH_LEN * 2) + \
                                (WAP_CUSTOM_CFG_MAX_MMS_ADDRESS * MMI_UC_CUSTOM_MAX_ADDR_LEN * 2) + \
                                (5 * 1024))
                                
extern kal_uint8 mmi_uc_adm_mem[MMI_UC_ADM_MEM_SIZE];

extern kal_uint8 mmi_uc_custom_get_max_mo_sms_segment(void);                                
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */


#endif /* _CUSTOM_UC_CONFIG_H */
