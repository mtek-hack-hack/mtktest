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
 * bra_cbm.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   CBM always ask handler
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 *
 *******************************************************************************/



#ifndef _bra_cbm_h
#define _bra_cbm_h

#include "bra_cfg.h"



#include "ConnectManageGProt.h"


/* context */

MSF_UINT8 
bra_cbm_get_app_id(int prof_type);

MSF_UINT8 
bra_cbm_get_bra_app_id(void);

MSF_UINT8 
bra_cbm_get_mms_app_id(void);

MSF_UINT32 
bra_cbm_get_bra_asked_ext_net_id(void);

MSF_BOOL 
bra_cbm_is_bra_asked_ext_net_id_valid(void);

void 
bra_cbm_reset_ext_net_id(void);

MSF_UINT8 
bra_cbm_get_bra_bearer_status_notify_index(void);

int
bra_cbm_get_cbm_sim_id(int bra_sim_id);

void
bra_cbm_init(void);

void
bra_cbm_terminate(void);

void
bra_cbm_create_ui(void);

void 
bra_cbm_destroy_ui(void);


/* primitive received */
void
bra_cbm_handle_ask_select_result(void *p);

void
bra_cbm_handle_add_bearer_status_notify(void *p);

void
bra_cbm_handle_del_bearer_status_notify(void *p);

void
bra_cbm_handle_bearer_status_notify(void *p);

void
bra_cbm_create_view_bearer_detail_info_menu(void);



MSF_UINT32
bra_cbm_get_using_ext_net_id(void);


int 
bra_cbm_is_need_to_ask(void);









#endif /* _bra_cbm_h */










