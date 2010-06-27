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
 * bra_sim.c
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




#include "bra_cfg.h"


#ifdef BRA_CFG_DUAL_SIM

#include "bra_sim.h"
#include "bra_int.h" 
#include "bra_cmn.h"
#include "bra_prof.h"
#include "bra_file.h"
#include "bra_main.h"
#include "bra_str.h"
#include "bra_win.h"
#include "bra_dlg.h"
#include "bra_if.h"
#include "bra_set.h"
#include "bra_cbm.h"
#include "bra_sig.h"
#include "bra_view.h"
#include "bra_psl.h"

#include "brs_if.h"
#include "msf_log.h"
#include "msf_core.h"
#include "msf_chrt.h"


#include "msm.h"
#include "kal_release.h"
#include "wapadp.h"
#include "wap_ps_struct.h"


#include "ConnectManageGProt.h"


#include "wap_cmn.h"


/*-----------------------------------------------------------------------------*/


typedef struct  
{
    MsfWindowHandle         window;
    MsfActionHandle         accept;
    MsfActionHandle         back;
    bra_sim_menu_type_enum  type;
}bra_sim_menu_t;


typedef struct  
{
    int              asked_sim_id;          /* INVALID, SIM1 and SIM2 */
    int              prof_type;             /* only used in edit profile menu */
    int              sim_status;
    int              setting_mode;
    int              sim_num;               /* no SIM, SIM1, SIM2, DUAL SIM */
    bra_create_ui_t  *data;
    bra_sim_select_sim_result_t wtai_cb;
}bra_sim_context_t;


static bra_sim_context_t  bra_sim_cntx;





/*-----------------------------------------------------------------------------*/

static void
bra_sim_check_sim_info(bra_sim_info_notify_t *sim_info);

static void
bra_sim_init_sim_info(void);

static void
bra_sim_set_sim_info(int sim_status, int setting_mode);

static void
bra_sim_check_push_status_icon(void);


/* Dual SIM menu */
static void
bra_sim_create_dual_sim_menu(bra_sim_menu_type_enum type);

static void
bra_sim_delete_dual_sim_menu (bra_win_t *win);

static void
bra_sim_action_dual_sim_menu (bra_win_t *win, MSF_UINT32 bra_action);

static void
bra_sim_handle_select_sim(bra_sim_id_enum sim_id);

static void
bra_sim_delete_select_sim_menu (bra_win_t *win);

static void
bra_sim_action_select_sim_menu (bra_win_t *win, MSF_UINT32 bra_action);

static void
bra_sim_select_sim_menu_in_focus (bra_win_t *win);

static void
bra_sim_activate_select_sim(bra_sim_id_enum sim_id);

static MsfStringHandle
bra_sim_get_sim_error_message(void);



/*-----------------------------------------------------------------------------*/

extern void 
bra_psl_cancel_push_indicator(void); 





/*-----------------------------------------------------------------------------*/



bra_sim_id_enum
bra_sim_get_sim_card_number(void)
{
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_GET_SIM_CARD_NUMBER, "BRA: bra_sim_get_sim_card_number(): num=%d\n", bra_sim_cntx.sim_num));

    return bra_sim_cntx.sim_num;
}


bra_sim_id_enum
bra_sim_get_setting_mode(void)
{
  return bra_sim_cntx.setting_mode;
}


int 
bra_sim_set_widget_sim_icon(int sim_id)
{
    int     icon_id;


    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_SET_WIDGET_SIM_ICON, "BRA: bra_sim_set_widget_sim_icon(): sim_id=%d\n", sim_id));

    switch (sim_id)
    {
    case BRA_SIM_ID_SIM1:
        icon_id = WAP_SERVICE_ON_MASTER_SIM;
        break;

    case BRA_SIM_ID_SIM2:
        icon_id = WAP_SERVICE_ON_SLAVE_SIM;
        break;

    case BRA_SIM_ID_DUAL_SIM:
        icon_id = WAP_SERVICE_ON_UNKNOWN_SIM;
        break;
    
    case BRA_SIM_ID_NO_SIM:
        icon_id = WAP_SERVICE_ON_UNKNOWN_SIM;
        break;

    default:
        icon_id = WAP_SERVICE_ON_UNKNOWN_SIM;
        break;
    }
    return (int)HDIa_widgetExtEnableSIMService((widget_service_on_sim_enum)icon_id);
}


int
bra_sim_get_widget_sim_id(int bra_sim_id)
{
    int     sim_id;
    
    
    switch (bra_sim_id)
    {
    case BRA_SIM_ID_SIM1:
        sim_id = WAP_SERVICE_ON_MASTER_SIM;
        break;
        
    case BRA_SIM_ID_SIM2:
        sim_id = WAP_SERVICE_ON_SLAVE_SIM;
        break;
        
    case BRA_SIM_ID_DUAL_SIM:
        sim_id = WAP_SERVICE_ON_UNKNOWN_SIM;
        break;
        
    default:
        sim_id = WAP_SERVICE_ON_UNKNOWN_SIM;
        break;
    }
    return sim_id;
}



int
bra_sim_get_bra_sim_id(int wap_sim_id)
{
    int   bra_sim_id = BRA_SIM_ID_INVALID;
    
    
    switch(wap_sim_id)
    {
    case WAP_SIM_ID_SIM1:
        bra_sim_id = BRA_SIM_ID_SIM1;
        break;
        
    case WAP_SIM_ID_SIM2:
        bra_sim_id = BRA_SIM_ID_SIM2;
        break;
        
    case WAP_SIM_ID_DUAL_SIM:
        bra_sim_id = BRA_SIM_ID_DUAL_SIM;
        break;
        
    case WAP_SIM_ID_NO_SIM:
        bra_sim_id = BRA_SIM_ID_NO_SIM;
        break;
        
    case WAP_SIM_ID_FLIGHT_MODE:
        bra_sim_id = BRA_SIM_ID_FLIGHT_MODE;
        break;
        
    case WAP_SIM_ID_DEFAULT:
        bra_sim_id = BRA_SIM_ID_DEFAULT; 
        break;
        
    default:
        bra_sim_id = BRA_SIM_ID_INVALID;
        break;
    }
    
    return bra_sim_id;
}


int
bra_sim_get_wap_sim_id(int bra_sim_id)
{
    int  wap_sim_id = WAP_SIM_ID_DEFAULT;


    switch (bra_sim_id)
    {
    case BRA_SIM_ID_SIM1:
        wap_sim_id = WAP_SIM_ID_SIM1;
        break;
        
    case BRA_SIM_ID_SIM2:
        wap_sim_id = WAP_SIM_ID_SIM2;
        break;
        
    case BRA_SIM_ID_DUAL_SIM:
        wap_sim_id = WAP_SIM_ID_DUAL_SIM;
        break;
        
    case BRA_SIM_ID_NO_SIM:
        wap_sim_id = WAP_SIM_ID_NO_SIM;
        break;
        
    case BRA_SIM_ID_FLIGHT_MODE:
        wap_sim_id = WAP_SIM_ID_FLIGHT_MODE;
        break;
        
    case BRA_SIM_ID_INVALID:
        wap_sim_id = WAP_SIM_ID_NO_SIM; //?
        break;
        
    default:
        wap_sim_id = WAP_SIM_ID_DEFAULT;
        break;
    }
    
    return  wap_sim_id;
}


int
bra_sim_get_asked_sim_id(void)
{
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_GET_ASKED_SIM_ID, "BRA: bra_sim_get_asked_sim_id(): sim_id=%d\n",
        bra_sim_cntx.asked_sim_id));

    return bra_sim_cntx.asked_sim_id;
}


int
bra_sim_get_bra_sim_id_in_active_use(void)
{
    int     sim_id;
    int     sim_info;

    
    sim_info = bra_sim_get_sim_card_number();
    if (sim_info == BRA_SIM_ID_SIM1 || sim_info == BRA_SIM_ID_SIM2)
        return sim_info;
    if (sim_info == BRA_SIM_ID_NO_SIM) /* temp ??? */
        return BRA_SIM_ID_SIM1;
    if (0 == bra_prof_is_profile_loaded(0))
        return BRA_SIM_ID_SIM1;

    /* the BRA_CMN_KEY_BRA_SIM_ID will be modified when to check the SIM number
       so, if not asked, use the activated one */
    sim_id = bra_sim_get_asked_sim_id(); 
    if (sim_id == BRA_SIM_ID_INVALID)
        sim_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);

    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_GET_BRA_SIM_ID_IN_ACTIVE_USE, "BRA: bra_sim_get_bra_sim_id_in_active_use(): sim_id=%d\n", sim_id));
    
        return sim_id;
}


void
bra_sim_init(void)
{
    bra_sim_cntx.asked_sim_id = BRA_SIM_ID_INVALID;
    bra_sim_cntx.prof_type = BRA_PROF_ID_BRA;
    bra_sim_cntx.data = NULL;
    bra_sim_cntx.wtai_cb = NULL;
    bra_sim_init_sim_info();
}


void
bra_sim_terminate(void)
{
    bra_sim_cntx.asked_sim_id = BRA_SIM_ID_INVALID;
    if (bra_sim_cntx.data)
        MSF_SIGNAL_DESTRUCT(MSF_MODID_BRA, BRA_SIG_CREATE_UI, bra_sim_cntx.data);
    bra_sim_cntx.data = NULL;
    bra_sim_cntx.prof_type = BRA_PROF_ID_BRA;
    bra_sim_cntx.setting_mode = BRA_SIM_ID_NO_SIM;
    bra_sim_cntx.sim_status = BRA_SIM_ID_NO_SIM;
}


static void
bra_sim_check_sim_info(bra_sim_info_notify_t *sim_info)
{
    kal_uint8  sim_status;
    kal_uint8  setting_mode;
    
    
    if (sim_info == NULL)
        return;
    sim_status = wap_get_sim_status();
    setting_mode = wap_get_sim_setting_mode();
    
    sim_info->sim_status = bra_sim_get_bra_sim_id((int)sim_status);
    sim_info->setting_mode = bra_sim_get_bra_sim_id((int)setting_mode);
    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_CHECK_SIM_INFO, "BRA: bra_sim_check_sim_info(): sim_status =%d, setting_mode =%d", 
        sim_info->sim_status, sim_info->setting_mode));
}


static void
bra_sim_init_sim_info(void)
{
    bra_sim_info_notify_t   sim_info;


    bra_sim_check_sim_info(&sim_info);
    bra_sim_set_sim_info(sim_info.sim_status, sim_info.setting_mode);
}


static void
bra_sim_set_sim_info(int sim_status, int setting_mode)
{
    bra_sim_cntx.sim_status = sim_status;
    bra_sim_cntx.setting_mode = setting_mode;


    /* block SIM: no SIM; invalid SIM : SIM id */
    switch (sim_status)
    {
    case BRA_SIM_ID_NO_SIM:
        bra_sim_cntx.sim_num = BRA_SIM_ID_NO_SIM;
        break;

    case BRA_SIM_ID_SIM1:
        if (bra_sim_cntx.setting_mode == BRA_SIM_ID_SIM2)
            bra_sim_cntx.sim_num = BRA_SIM_ID_NO_SIM;
        else
            bra_sim_cntx.sim_num = BRA_SIM_ID_SIM1;
        break;

    case BRA_SIM_ID_SIM2:
        if (bra_sim_cntx.setting_mode == BRA_SIM_ID_SIM1)
            bra_sim_cntx.sim_num = BRA_SIM_ID_NO_SIM;
        else
            bra_sim_cntx.sim_num = BRA_SIM_ID_SIM2;
        break;

    case BRA_SIM_ID_DUAL_SIM:
        if (bra_sim_cntx.setting_mode == BRA_SIM_ID_FLIGHT_MODE)
            bra_sim_cntx.sim_num = BRA_SIM_ID_DUAL_SIM;
        else
            bra_sim_cntx.sim_num = bra_sim_cntx.setting_mode;
        break;

    default:
        ASSERT(!"Error sim status");
        break;
    }

    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_SET_SIM_INFO, "BRA: bra_sim_set_sim_info(): sim_status =%d, setting_mode =%d, sim_num=%d", 
        bra_sim_cntx.sim_status, bra_sim_cntx.setting_mode, bra_sim_cntx.sim_num));
}


void
bra_sim_create_ui(void *data)
{
    bra_create_ui_t  *p;
    int              act_sim;
    int              is_ask = 0;
    bra_sim_id_enum  sim_info = BRA_SIM_ID_INVALID;
    

    bra_sim_init_sim_info();
    bra_sim_check_sim_number();

    p = (bra_create_ui_t*)data;
    bra_sim_cntx.data = data;
    bra_sim_cntx.wtai_cb = NULL;

    /* DLAgent may call wap_start_browser() with WAP_BROWSER_GOTO_URL_BACKGROUND while browser is running
     * so, here need to check this and do not show the select SIM menu in always ask mode 
     */
    if (bra_sim_cntx.asked_sim_id != BRA_SIM_ID_INVALID &&
        p->type == BRA_UI_GOTO_URL &&
        bra_win_get_window(BRA_WIN_ID_VIEWPORT))
    {
        bra_sim_set_widget_sim_icon(bra_sim_get_bra_sim_id_in_active_use());
        BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_CREATE_UI, bra_sim_cntx.data);
        bra_sim_cntx.data = NULL;
        return;
    }

    bra_sim_cntx.asked_sim_id = BRA_SIM_ID_INVALID;
    act_sim = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);
    if (p->type == BRA_UI_GOTO_URL || p->type == BRA_UI_HOMEPAGE ||
        p->type == BRA_UI_MAIN_MENU || p->type == BRA_UI_VIEWPORT)
    {
        sim_info = bra_sim_get_sim_card_number();
        if (sim_info == BRA_SIM_ID_DUAL_SIM)
        {
            is_ask = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK);
            if (is_ask == TRUE)
            {
                bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
                bra_sim_create_select_sim_menu();
            }
            else
            {
                bra_sim_set_widget_sim_icon(act_sim);
                BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_CREATE_UI, bra_sim_cntx.data);
                bra_sim_cntx.data = NULL;
            }
        }
        else 
        {
            bra_sim_set_widget_sim_icon(sim_info);
            BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_CREATE_UI, bra_sim_cntx.data);
            bra_sim_cntx.data = NULL;
        }
    }
    else
    {
        bra_sim_set_widget_sim_icon(act_sim);
        BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_CREATE_UI, bra_sim_cntx.data);
        bra_sim_cntx.data = NULL;
    }

    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_CREATE_UI, "BRA: bra_sim_create_ui(): type=%d, act_sim=%d, sim_num=%d, is_ask=%d", 
        p->type, act_sim, sim_info, is_ask));

}


void
bra_sim_destroy_ui(void)
{
    bra_sim_cntx.asked_sim_id = BRA_SIM_ID_INVALID;
    if (bra_sim_cntx.data)
        MSF_SIGNAL_DESTRUCT(MSF_MODID_BRA, BRA_SIG_CREATE_UI, bra_sim_cntx.data);
    bra_sim_cntx.data = NULL;
    if (bra_sim_cntx.wtai_cb != NULL)
    {
        (bra_sim_cntx.wtai_cb)(0, 0);
        bra_sim_cntx.wtai_cb = NULL;
    }
    /* restore the title icon */
    bra_sim_set_widget_sim_icon(BRA_SIM_ID_DUAL_SIM);
}


static void
bra_sim_check_push_status_icon(void)
{
    int   sim_num;


    sim_num = bra_sim_get_sim_card_number();
    if (sim_num == BRA_SIM_ID_NO_SIM || 
        bra_sim_cntx.setting_mode == BRA_SIM_ID_FLIGHT_MODE)
    {
        bra_psl_cancel_push_indicator();
    }
    else
    {
        bra_psl_unread_check();
    }
}


void
bra_sim_check_sim_number(void)
{
    int     is_ask;
    int     sim_num;
    int     act_bra_sim;
    int     is_changed = FALSE;
 
    
    /* check this SIM card in slot now */
    sim_num = bra_sim_get_sim_card_number();
    act_bra_sim = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);
    is_ask = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK);

    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_CHECK_SIM_NUMBER, "BRA: bra_sim_check_sim_number(): sim_num=%d, act_bra_sim=%d, is_ask=%d\n", 
        sim_num, act_bra_sim, is_ask));

    if (sim_num == BRA_SIM_ID_DUAL_SIM)
    {
        if (is_ask == TRUE && act_bra_sim != BRA_SIM_ID_SIM1)
        {
            if (bra_sim_get_asked_sim_id() == BRA_SIM_ID_INVALID)
            {
                is_changed = TRUE;
                bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID, BRA_SIM_ID_SIM1, NULL);
            }
        }
    }
    else /* SIM1, SIM2, NO SIM */
    {
        if(is_ask != 0)
        {
            is_changed = TRUE;
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK, 0, NULL);
        }
        if (sim_num == BRA_SIM_ID_NO_SIM)
            sim_num = BRA_SIM_ID_SIM1;   /* temp */
        if (act_bra_sim != sim_num)
        {
            is_changed = TRUE;
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID, sim_num, NULL);
        }
    }
    if (is_changed == TRUE)
        bra_cmn_check_profile_checksum();
}


int
bra_sim_is_need_to_ask(void)
{
    int     is_ask;


    ASSERT(bra_prof_is_profile_loaded(0));

    is_ask = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK);
    if (is_ask == FALSE)
        return FALSE;
    if (bra_sim_get_asked_sim_id() != BRA_SIM_ID_INVALID)
    {
        /* check this scenario: first enter WAP from push, visit a URL but failed, go back to
           push context menu, then accept this URL again, should show ask SIM menu again */
        if (!bra_win_get_window(BRA_WIN_ID_INSE) && 
            !bra_win_get_window(BRA_WIN_ID_OPT) &&
             bra_win_get_window(BRA_WIN_ID_VIEWPORT))
        {
            bra_sim_destroy_ui();
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    /* if just activate the always ask menu item and do not exit the browser */
    if(bra_win_get_window(BRA_WIN_ID_INSE) || bra_win_get_window(BRA_WIN_ID_OPT))
        return FALSE;
    return TRUE;
}


void
bra_sim_handle_sim_info_notify(void *p)
{
    bra_sim_info_notify_t   *data;
    
    
    data = (bra_sim_info_notify_t*)p;
    if (data == NULL)
        return;
    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_HANDLE_SIM_INFO_NOTIFY, "BRA: bra_sim_handle_sim_info_notify(): sim_status=%d, setting_mode=%d", 
        data->sim_status, data->setting_mode));

    if (bra_sim_cntx.sim_status == data->sim_status && 
        bra_sim_cntx.setting_mode == data->setting_mode)
        return;

    if (!bra_prof_is_profile_loaded(0))
        return;
    /* can only be NO SIM, SIM1, SIM2, DUAL SIM, FLIGHT MODE */
    bra_sim_set_sim_info(data->sim_status, data->setting_mode);
    /* just not to handle the scenario that SIM in slot but not detected */
    if (bra_is_wap_in_active_use())
        return;

    /* update push indication */
    bra_sim_check_push_status_icon();

    bra_sim_check_sim_number();

    bra_prof_restore_bra_active_profile(TRUE);
}



/*---------------------------Dual SIM Menu-------------------------------------*/


static bra_sim_menu_t*
bra_sim_alloc_bra_sim_menu(void)
{
    bra_sim_menu_t   *p;


    p = BRA_ALLOCTYPE(bra_sim_menu_t);
    p->window = 0;
    p->accept = 0;
    p->back = 0;
    p->type = 0;
    return p;
}


static void
bra_sim_free_bra_sim_menu(bra_sim_menu_t *menu)
{
    if (menu != NULL)
    {
        MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
            BRA_SIM_FREE_BRA_SIM_MENU, "BRA: bra_sim_free_bra_sim_menu(): win=%d, window=%d, accept=%d, back=%d", 
            menu, menu->window, menu->accept, menu->back));

        MSF_WIDGET_REMOVE (bra_win_get_screen (), menu->window); 
        MSF_WIDGET_RELEASE (menu->window); 
        MSF_WIDGET_RELEASE (menu->accept);
        MSF_WIDGET_RELEASE (menu->back);
        BRA_FREE (menu);
    }
}


void 
bra_sim_create_select_sim_menu(void)
{
    bra_sim_create_dual_sim_menu(BRA_SIM_MENU_TYPE_SELECT_SIM);
}


void
bra_sim_create_edit_sim_menu(int prof_type)
{
    bra_sim_cntx.prof_type = prof_type;
    bra_sim_create_dual_sim_menu(BRA_SIM_MENU_TYPE_EDIT_SIM);
}


void
bra_sim_create_wtai_select_sim_menu(bra_sim_select_sim_result_t callback)
{
    int         sim_id;


    if (bra_win_get_window(BRA_WIN_ID_EDIT_SIM_MENU))
    {
        if (callback)
            callback(0, 0);
        return;
    }
    sim_id = bra_sim_get_sim_card_number();
    if (sim_id != BRA_SIM_ID_DUAL_SIM)
    {
        if (callback)
            callback(1, sim_id);
        return;
    }
    bra_sim_cntx.wtai_cb = callback;
    bra_win_disable_focus();
    bra_sim_create_dual_sim_menu(BRA_SIM_MENU_TYPE_WTAI_SELECT_SIM);
    bra_win_enable_focus();
}


static void
bra_sim_create_dual_sim_menu(bra_sim_menu_type_enum type)
{
    bra_sim_menu_t      *win;
//    MsfDeviceProperties  prop;
    MSF_UINT8            i = 0;
    MsfStringHandle      sim1_str;
    MsfStringHandle      sim2_str;
    MsfPosition          pos = BRA_CFG_MENU_POS;
    

    bra_view_disable();
//    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);

    if (type == BRA_SIM_MENU_TYPE_WTAI_SELECT_SIM)
    {
        sim1_str = BRA_STR_SIM1_CALL;
        sim2_str = BRA_STR_SIM2_CALL;
    }
    else
    {
        sim1_str = BRA_STR_SIM1;
        sim2_str = BRA_STR_SIM2;
    }

    win = bra_sim_alloc_bra_sim_menu();
    win->type = type;
    win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfSelect, 1, 0x8000);
    win->back = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK, MsfBack, 1, 0x8000);
    /* MSF_WIDGET_DEVICE_GET_PROPERTIES is used to get current size not the default size
     * so, if we show this menu on the MMS SMIL player or MMS Viewer screen, current size
     * is smaller than the default size, just to set the size parameter to NULL, let widget
     * to get the default size automically, or may be can use the MSF_WIDGET_MENU_APP_CREATE()
     * to show this menu screen
    */
    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA, MsfImplicitChoice, NULL,
        win->accept, 0, MSF_CHOICE_ELEMENT_STRING_1, 0x8000, 0 );
    
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, sim1_str,  0, 
        bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i, sim2_str,  0,
        bra_cmn_get_list_num_image(i), 0, TRUE);
    i++;
    
    if (win->type == BRA_SIM_MENU_TYPE_EDIT_SIM)
        MSF_WIDGET_SET_TITLE (win->window, BRA_STR_EDIT_PROFILE);
    else if (win->type == BRA_SIM_MENU_TYPE_WTAI_SELECT_SIM)
        MSF_WIDGET_SET_TITLE (win->window, BRA_STR_SELECT_CALL);
    else
        MSF_WIDGET_SET_TITLE (win->window, BRA_STR_SELECT_SIM);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window, MSF_WINDOW_PROPERTY_TITLE);

    MSF_WIDGET_ADD_ACTION (win->window, win->accept);
    MSF_WIDGET_ADD_ACTION (win->window, win->back);
    
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_CREATE_DUAL_SIM_MENU, "BRA: bra_sim_create_dual_sim_menu(): win=%d, window=%d, accept=%d, back=%d", 
        win, win->window, win->accept, win->back));

    bra_win_show_window (BRA_WIN_ID_EDIT_SIM_MENU, 
        (bra_win_t*)win, 
        &pos, 
        bra_sim_delete_dual_sim_menu, 
        NULL,
        bra_sim_action_dual_sim_menu);
}  


static void
bra_sim_delete_dual_sim_menu (bra_win_t *win)
{
    bra_sim_free_bra_sim_menu((bra_sim_menu_t*)win);
    bra_sim_cntx.prof_type = -1;
}


static void
bra_sim_action_dual_sim_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
    bra_sim_menu_t      *p;
    int                 i = 0;
    int                 sim_id = BRA_SIM_ID_INVALID;

    
    p = (bra_sim_menu_t *)win;
    
    if (bra_action == p->back)
    {
        if (p->type == BRA_SIM_MENU_TYPE_SELECT_SIM)
        {
            bra_sim_destroy_ui();   
        }
        else if (p->type == BRA_SIM_MENU_TYPE_WTAI_SELECT_SIM)
        {
            if (bra_sim_cntx.wtai_cb != NULL)
            {
                (bra_sim_cntx.wtai_cb)(0, 0);
                bra_sim_cntx.wtai_cb = NULL;
            }
        }
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    }
    else if (bra_action == p->accept)
    {
        if (bra_cmn_is_menu_item_selected(p->window, i++))    
        {
            sim_id = BRA_SIM_ID_SIM1;
        }
        else if (bra_cmn_is_menu_item_selected(p->window, i++))    
        {
            sim_id = BRA_SIM_ID_SIM2;
        }

        if (p->type == BRA_SIM_MENU_TYPE_EDIT_SIM)
            bra_prof_create_profile_list_menu(bra_sim_cntx.prof_type, sim_id);
        else if(p->type == BRA_SIM_MENU_TYPE_SELECT_SIM)
            bra_sim_handle_select_sim(sim_id);
        else if (p->type == BRA_SIM_MENU_TYPE_WTAI_SELECT_SIM)
        {
            if (bra_sim_cntx.wtai_cb != NULL)
            {
                (bra_sim_cntx.wtai_cb)(1, sim_id);
                bra_sim_cntx.wtai_cb = NULL;
            }
            bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
        }
    }
}



static void
bra_sim_handle_select_sim(bra_sim_id_enum sim_id)
{
    ASSERT(sim_id == BRA_SIM_ID_SIM1 || sim_id == BRA_SIM_ID_SIM2);

    bra_sim_cntx.asked_sim_id = sim_id;
    BRA_SIGNAL_SENDTO_P(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONTINUE_CREATE_UI, bra_sim_cntx.data);
    bra_sim_cntx.data = NULL;
    bra_sim_set_widget_sim_icon(sim_id);
    bra_prof_restore_bra_active_profile(TRUE);
    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_HANDLE_SELECT_SIM, "BRA: bra_sim_handle_select_sim(): sim_id=%d\n", sim_id));
}


void
bra_sim_create_profile_select_sim_menu(void)
{
    int                       i = 0;
    bra_sim_menu_t            *win;
    MsfDeviceProperties       prop;
    MsfPosition               pos = BRA_CFG_MENU_POS;
    
    
    MSF_WIDGET_DEVICE_GET_PROPERTIES(&prop);
    win = bra_sim_alloc_bra_sim_menu();
    win->accept = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_OK, MsfSelect, 1, 0x8000);
    win->back   = MSF_WIDGET_ACTION_CREATE(MSF_MODID_BRA, BRA_STR_BACK, MsfBack, 1, 0x8000);
    
    win->window = MSF_WIDGET_MENU_CREATE(MSF_MODID_BRA, MsfMultipleChoice,
        &prop.displaySize, win->accept, 0,
        MSF_CHOICE_ELEMENT_STRING_1 | MSF_CHOICE_ELEMENT_ICON, 0x8000, 0);
    
    HDIa_widgetExtMenuProfileStyle(win->window);   
    MSF_WIDGET_SET_TITLE (win->window, BRA_STR_SELECT_SIM);
    MSF_WIDGET_WINDOW_SET_PROPERTIES (win->window, MSF_WINDOW_PROPERTY_TITLE);

    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_ALWAYS_ASK,  0, 0, 0, TRUE);
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_SIM1,  0, 0, 0, TRUE);
    MSF_WIDGET_CHOICE_SET_ELEMENT (win->window, i++, BRA_STR_SIM2,   0, 0, 0, TRUE);
    
    MSF_WIDGET_ADD_ACTION (win->window, win->accept);
    MSF_WIDGET_ADD_ACTION (win->window, win->back);
    
    bra_win_show_window (BRA_WIN_ID_SELECT_SIM_MENU, 
        (bra_win_t*)win, &pos, 
        bra_sim_delete_select_sim_menu, 
        bra_sim_select_sim_menu_in_focus,
        bra_sim_action_select_sim_menu);
}


static void
bra_sim_delete_select_sim_menu (bra_win_t *win)
{
    bra_sim_free_bra_sim_menu((bra_sim_menu_t*)win);
}

static void
bra_sim_select_sim_menu_in_focus (bra_win_t *win)
{
    bra_sim_menu_t              *p; 
    int                         i = 0;
    int                         sim_id;
    int                         is_ask;
    int                         sel_id; 
    

    p = (bra_sim_menu_t*)win;
    MSF_WIDGET_CHOICE_SET_ELEMENT (p->window, i++, BRA_STR_ALWAYS_ASK, 0, 0, 0, FALSE);
    MSF_WIDGET_CHOICE_SET_ELEMENT (p->window, i++, BRA_STR_SIM1, 0, 0, 0, FALSE);
    MSF_WIDGET_CHOICE_SET_ELEMENT (p->window, i++, BRA_STR_SIM2, 0, 0, 0, FALSE);

    is_ask = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK);
    sim_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);
    if (is_ask != 0)
        sel_id = 0;
    else if (sim_id == BRA_SIM_ID_SIM1)
        sel_id = 1;
    else if (sim_id == BRA_SIM_ID_SIM2)
        sel_id = 2;
    else
        sel_id = 0;

    for (i = 0; i < BRA_CFG_MAX_SIM_NUM + 1; i++)
    {
        if (i == sel_id)
            MSF_WIDGET_CHOICE_SET_ELEM_STATE (p->window, i, MSF_CHOICE_ELEMENT_SELECTED);
        else
            MSF_WIDGET_CHOICE_SET_ELEM_STATE (p->window, i, 0);
    }
}


static void
bra_sim_action_select_sim_menu (bra_win_t *win, MSF_UINT32 bra_action)
{
    int                i = 0;
    bra_sim_menu_t     *p = (bra_sim_menu_t *)win;
    
    
    if (bra_action == p->back)
    {
        bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    }
    else if (bra_action == p->accept)
    {
        if (bra_cmn_is_menu_item_selected(p->window, i++))
        {
            bra_sim_activate_select_sim(BRA_SIM_ID_ALWAYS_ASK);
        }
        else if (bra_cmn_is_menu_item_selected(p->window, i++))
        {
            bra_sim_activate_select_sim(BRA_SIM_ID_SIM1);
        }
        else if (bra_cmn_is_menu_item_selected(p->window, i++))
        {
            bra_sim_activate_select_sim(BRA_SIM_ID_SIM2);
        }
    //    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    }
}


static void
bra_sim_activate_select_sim(bra_sim_id_enum sim_id)
{
    int     sim_info;
    int     act_sim_id;
    int     is_sim_ask;
    int     act_prof_id = -1;
    int     is_changed = FALSE;
    

    sim_info = bra_sim_get_sim_card_number();
    if (sim_info == BRA_SIM_ID_NO_SIM && sim_id != BRA_SIM_ID_SIM1 ||
        sim_info != BRA_SIM_ID_DUAL_SIM && sim_id != sim_info)
    {
        MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
            BRA_SIM_ACTIVATE_SELECT_SIM_ERR, "BRA: bra_sim_activate_select_sim(): sim_id=%d, sim_num=%d, sim_status=%d, setting_mode=%d",
            sim_id, sim_info, bra_sim_cntx.sim_status, bra_sim_cntx.setting_mode));
        
        /* if no SIM, can not start browser */
        HDIa_widgetExtShowPopup(MSF_MODID_BRA, bra_sim_get_sim_error_message(), MsfError, 0);
        return;
    }
    
    is_sim_ask = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK);
    if (sim_id == BRA_SIM_ID_ALWAYS_ASK)
    {
        if (is_sim_ask == FALSE)
        {
            is_changed = TRUE;
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK, 1, NULL);
        }
    }
    else 
    {
        if (is_sim_ask == TRUE)        
        {
            is_changed = TRUE;
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID_IS_ASK, 0, NULL);
        }
        act_sim_id = bra_prof_get_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID);
        if (sim_id != act_sim_id)    
        {
            is_changed = TRUE;
            bra_prof_change_key_int_value(BRA_PROF_ID_CMN, BRA_CMN_KEY_BRA_SIM_ID, sim_id, NULL);
        }

        act_prof_id = bra_prof_get_sim_activated_profile_id(BRA_PROF_ID_BRA, sim_id);
        
        if (sim_id != bra_prof_get_profile_sim_id() || act_prof_id != bra_prof_get_absolute_profile())        
        {
            bra_prof_set_sim_selected_profile(BRA_PROF_ID_BRA, sim_id, act_prof_id, NULL);
            bra_prof_commit_profile();
            BRAa_setBearerType(bra_prof_get_key_int_value(bra_prof_get_profile_id(), BRA_PROF_KEY_NET_ID)); 
        }
        bra_sim_set_widget_sim_icon(sim_id);
    }
    if (is_changed == TRUE)
        bra_cmn_check_profile_checksum();
    bra_win_close_window (BRA_WIN_CLOSE_CURRENT, 0);
    HDIa_widgetExtShowPopup(MSF_MODID_BRA, BRA_STR_ACTIVATED, MsfPromptSaveDone,0);

    MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BRA,
        BRA_SIM_ACTIVATE_SELECT_SIM, "BRA: bra_sim_activate_select_sim(): sel_sim_id=%d, sim_num=%d, is_ask=%d, act_prof_id=%d\n",
        sim_id, sim_info, is_sim_ask, act_prof_id));

}


static MsfStringHandle
bra_sim_get_sim_error_message(void)
{
    MsfStringHandle   ms = 0;
    
    
    /* only check error status */

    switch (bra_sim_cntx.sim_status)
    {
    case BRA_SIM_ID_SIM1:
        ms = BRA_STR_SIM2_NOT_EXIST;
        break;
        
    case BRA_SIM_ID_SIM2:
        ms = BRA_STR_SIM1_NOT_EXIST;
        break;

    case BRA_SIM_ID_DUAL_SIM:
        {
            if (bra_sim_cntx.setting_mode == BRA_SIM_ID_SIM1)
                ms = BRA_STR_SIM2_NOT_OPEN;
            else if (bra_sim_cntx.setting_mode == BRA_SIM_ID_SIM2)
                ms = BRA_STR_SIM1_NOT_OPEN;
            break;
        }
    case BRA_SIM_ID_NO_SIM:
        ms = BRA_STR_NO_SIM_IS_AVAILABLE;
        break;

    default:
        break;
    }
    return ms;
}








#endif /* BRA_CFG_DUAL_SIM */

