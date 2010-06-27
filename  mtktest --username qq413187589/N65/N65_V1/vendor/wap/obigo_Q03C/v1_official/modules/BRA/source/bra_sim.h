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
 * bra_sim.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Dual SIM handler
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 *
 *******************************************************************************/



#ifndef _bra_sim_h
#define _bra_sim_h

#include "bra_cfg.h"


#ifdef BRA_CFG_DUAL_SIM

typedef enum
{
    BRA_SIM_ID_INVALID = -1,
    BRA_SIM_ID_DEFAULT,
    BRA_SIM_ID_SIM1,
    BRA_SIM_ID_SIM2,
    BRA_SIM_ID_ALWAYS_ASK,
    BRA_SIM_ID_DUAL_SIM,
    BRA_SIM_ID_NO_SIM,
    BRA_SIM_ID_FLIGHT_MODE,
    BRA_SIM_ID_MAX_ITEM
}bra_sim_id_enum;


typedef enum
{
    BRA_SIM_MENU_TYPE_EDIT_SIM,
    BRA_SIM_MENU_TYPE_SELECT_SIM,
    BRA_SIM_MENU_TYPE_WTAI_SELECT_SIM,
    BRA_SIM_MENU_TYPE_MAX_ITEM
}bra_sim_menu_type_enum;


typedef void (*bra_sim_select_sim_result_t)(int result, int sim_id);

bra_sim_id_enum
bra_sim_get_sim_card_number(void);

bra_sim_id_enum
bra_sim_get_setting_mode(void);

int
bra_sim_get_widget_sim_id(int bra_sim_id);

int 
bra_sim_set_widget_sim_icon(int sim_id);

int
bra_sim_is_need_to_ask(void);

int
bra_sim_get_bra_sim_id(int wap_sim_id);

int
bra_sim_get_wap_sim_id(int bra_sim_id);

int
bra_sim_get_asked_sim_id(void);

int
bra_sim_get_bra_sim_id_in_active_use(void);

void
bra_sim_init(void);

void
bra_sim_terminate(void);

void
bra_sim_create_ui(void *data);

void
bra_sim_destroy_ui(void);


void
bra_sim_check_sim_number(void);

void
bra_sim_handle_sim_info_notify(void *p);

void 
bra_sim_create_select_sim_menu(void);


void
bra_sim_create_profile_select_sim_menu(void);

void
bra_sim_create_edit_sim_menu(int prof_type);

void
bra_sim_create_wtai_select_sim_menu(bra_sim_select_sim_result_t callback);



#endif /* BRA_CFG_DUAL_SIM */





















#endif /* _bra_sim_h */






