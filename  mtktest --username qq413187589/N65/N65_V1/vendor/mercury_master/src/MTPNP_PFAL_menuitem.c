#include "mmi_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

#include "MTPNP_PFAL_custom_menuitem_def.h"
#include "MTPNP_AD_Master_common_def.h"
#if defined(__MMI_EMAIL__)
#include "EmailAppGProt.h"
#endif


static void mmi_frm_show_dm_menu_item(MTPNP_BOOL isShow, U16 num, const ST_MTPNP_AD_MENU * menu)
{
    FuncPtrShort menuFuncPtr;
    MTPNP_UINT16 i;

    if (isShow)
    {
        menuFuncPtr = mmi_frm_unhide_menu_item;
    }
    else
    {
        menuFuncPtr = mmi_frm_hide_menu_item;
    }

    for (i = 0; i < num; i++)
    {
        (*menuFuncPtr) (menu[i].menuId);

#if 0                           /* according to candy */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }
}

#ifdef SYNCML_DM_SUPPORT
void MTPNP_PFAL_Rearrange_Syncml_DM(MTPNP_BOOL master_isShow)
{    
    if (master_isShow == MTPNP_TRUE)
    {
        mmi_frm_unhide_menu_item(MENU_ID_DMUI_MAIN);
        return;
    }

    mmi_frm_hide_menu_item(MENU_ID_DMUI_MAIN);
}
#endif /* SYNCML_DM_SUPPORT */

void MTPNP_PFAL_Rearrange_MenuItem(void)
{
    E_MTPNP_AD_STATUS status;
    MTPNP_BOOL master_isShow = MTPNP_FALSE, slave_isShow = MTPNP_FALSE;
    E_MTPNP_AD_SIMCARD_STATUS sim1_status, sim2_status;

    /* if not slave plug in indicate, hide the related card2 menu item, do not rearrange the menu item */
    if (!MTPNP_AD_Slave_Is_Plugged())
    {
        MTPNP_PFAL_Hide_AllCard2_MenuItemEntry();
        return;
    }

    status = MTPNP_AD_Get_Status();

    sim1_status = MTPNP_AD_Get_Card1Status();
    sim2_status = MTPNP_AD_Get_Card2Status();

    if ((status & MTPNP_AD_CARD1) && sim1_status == MTPNP_AD_SIMCARD_VALID)
    {
        master_isShow = MTPNP_TRUE;
    }
    if ((status & MTPNP_AD_CARD2) && sim2_status == MTPNP_AD_SIMCARD_VALID)
    {
        slave_isShow = MTPNP_TRUE;
    }

    mmi_frm_show_dm_menu_item(master_isShow, sizeof(MasterMenuId) / sizeof(ST_MTPNP_AD_MENU), MasterMenuId);
    mmi_frm_show_dm_menu_item(slave_isShow, sizeof(SlaveMenuId) / sizeof(ST_MTPNP_AD_MENU), SlaveMenuId);

    if ((master_isShow == MTPNP_FALSE) && (slave_isShow == MTPNP_FALSE))
    {
        mmi_frm_hide_menu_item(MENU_MTPNP_DM_NETWORK_SETUP);
        
    #ifdef __IP_NUMBER__
        mmi_frm_hide_menu_item(MENU_SETTING_IP_NUMBER);
    #endif /* __IP_NUMBER__ */ 
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_MTPNP_DM_NETWORK_SETUP);
        
    #ifdef __IP_NUMBER__
        mmi_frm_unhide_menu_item(MENU_SETTING_IP_NUMBER);
    #endif /* __IP_NUMBER__ */ 
    }

#ifdef SYNCML_DM_SUPPORT
    MTPNP_PFAL_Rearrange_Syncml_DM(master_isShow);
#endif 

    MTPNP_PFAL_Rearrange_Phb_Menuitem();
#ifdef __MMI_EMAIL__
    mmi_email_bearer_status_show_icon();
#endif
}


void MTPNP_PFAL_Hide_AllCard2_MenuItemEntry(void)
{
    mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(SlaveMenuId) / sizeof(ST_MTPNP_AD_MENU), SlaveMenuId);
    mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(SlavePhbMenuId) / sizeof(ST_MTPNP_AD_MENU), SlavePhbMenuId);
}

void MTPNP_PFAL_Rearrange_Phb_Menuitem(void)
{
    E_MTPNP_AD_SIMCARD_STATUS sim1_status, sim2_status;

    sim1_status = MTPNP_AD_Get_Card1Status();
    sim2_status = MTPNP_AD_Get_Card2Status();

    if ((sim1_status | sim2_status) < MTPNP_AD_SIMCARD_VALID)
    {
        /* dual SIM invalid */
        mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(MasterPhbMenuId) / sizeof(ST_MTPNP_AD_MENU), MasterPhbMenuId);
        mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(SlavePhbMenuId) / sizeof(ST_MTPNP_AD_MENU), SlavePhbMenuId);
        //MTPNP_PFAL_Hide_IPDial_Menuitem();
    }
    else if ((sim1_status & sim2_status) >= MTPNP_AD_SIMCARD_VALID)
    {
        /* dual SIM valid */
        mmi_frm_show_dm_menu_item(MTPNP_TRUE, sizeof(MasterPhbMenuId) / sizeof(ST_MTPNP_AD_MENU), MasterPhbMenuId);
        mmi_frm_show_dm_menu_item(MTPNP_TRUE, sizeof(SlavePhbMenuId) / sizeof(ST_MTPNP_AD_MENU), SlavePhbMenuId);
    }
    else
    {
        if (sim1_status < MTPNP_AD_SIMCARD_VALID)
        {
            /* card1 invalid */
            mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(MasterPhbMenuId) / sizeof(ST_MTPNP_AD_MENU), MasterPhbMenuId);
            mmi_frm_show_dm_menu_item(MTPNP_TRUE, sizeof(SlavePhbMenuId) / sizeof(ST_MTPNP_AD_MENU), SlavePhbMenuId);
        }
        if (sim2_status < MTPNP_AD_SIMCARD_VALID)
        {
            /* card2 invalid */
            mmi_frm_show_dm_menu_item(MTPNP_TRUE, sizeof(MasterPhbMenuId) / sizeof(ST_MTPNP_AD_MENU), MasterPhbMenuId);
            mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(SlavePhbMenuId) / sizeof(ST_MTPNP_AD_MENU), SlavePhbMenuId);
        }
    }
}

void MTPNP_PFAL_Hide_IPDial_Menuitem(void)
{
    mmi_frm_show_dm_menu_item(MTPNP_FALSE, sizeof(IPDialMenuId) / sizeof(ST_MTPNP_AD_MENU), IPDialMenuId);
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
