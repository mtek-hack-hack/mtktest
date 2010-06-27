#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

/* MTK head files*/
#include "wgui_status_icons.h"
#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "gui_data_types.h"
#include "GSM7BitDefaultAlphabet.h"
#include "wgui_categories_idlescreen.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_inputs.h"
#include "StatusIconRes.h"
#include "GlobalDefs.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "HistoryGprot.h"
#include "CommonScreens.h"
#include "EventsGprot.h"
#include "GlobalConstants.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
#include "EventsGprot.h"
#include "wgui_categories_inputsenum.h"
#include "GlobalScrEnum.h"
/* MTK head files*/

#include "CallHistoryEnum.h"
#include "CallSetUpEnum.h"
#include "ChatAppResDef.h"
#include "MessagesResourceData.h"
#include "NetworkSetupGProt.h"
#include "PhoneBookDef.h"
#include "ServiceDefs.h"
#include "vObjectsResDef.h"
#include "PhoneSetup.h"
#if defined(__MMI_EMAIL__)
#include "EmailAppGProt.h"
#include "EmailAppResDef.h"
#endif

/*MTPNP head files*/
#include "MTPNP_AD_master_header.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_Card2_MSISDN.h"
#include "MTPNP_PFAL_menuitem.h"
/*MTPNP head file*/

#include "MTPNP_PFAL_SMS_Chat.h"

extern MTPNP_INT MAIN_LCD_device_width;
extern MTPNP_INT MAIN_LCD_device_height;

#ifdef __MMI_SUBLCD__
extern MTPNP_INT SUB_LCD_device_width;
extern MTPNP_INT SUB_LCD_device_height;
#endif /* __MMI_SUBLCD__ */

MTPNP_UCHAR g_slave_nw_providername[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
MTPNP_UCHAR g_slave_servprovderName[MAX_LENGTH_SERVICE_PROVIDER * ENCODING_LENGTH];
MTPNP_UCHAR g_slave_operatorname[MAX_LENGTH_OPERATOR_NAME * ENCODING_LENGTH];
MTPNP_UCHAR g_slave_shortoperatorname[MAX_LENGTH_SHORT_OPERATOR_NAME * ENCODING_LENGTH];
MTPNP_UCHAR g_slave_ownername[MAX_LENGTH_OWNER_NUMBER * ENCODING_LENGTH];

UI_string_type g_slave_idle_screen_line1text = MTPNP_NULL;
UI_string_type g_slave_idle_screen_line2text = MTPNP_NULL;

extern MTPNP_UINT8 gNWProviderName[MAX_LENGTH_DISPLAY_NAME * ENCODING_LENGTH];
extern MTPNP_UINT8 gSignalStrengthLevel;

extern MTPNP_UINT8 eons_check_if_plmn_present(MTPNP_UINT8 *);
extern void eons_get_pnn_record_req(MTPNP_UINT8 recordNo);
extern MTPNP_UINT8 mmi_msg_need_mem_full_ind(void);

void MTPNP_PFAL_SetIdleScreenNetworkName(MTPNP_UCHAR * s)
{
    MTPNP_INT16 strlen, i, real_pos;
    MTPNP_INT8 start_flag = 0;

    real_pos = 0;
    strlen = (MTPNP_INT16) gui_strlen((UI_string_type) s) << 1;
    for (i = 0; i < strlen; i += 2)
    {
        if (s[i] != 0x20 || s[i + 1] != 0x00)
        {
            start_flag = 1;
        }
        if (start_flag == 1)
        {
            s[real_pos] = s[i];
            s[real_pos + 1] = s[i + 1];
            real_pos += 2;
        }
    }
    if (real_pos < strlen)
    {
        for (i = real_pos; i < strlen; i++)
        {
            s[i] = '\0';
        }
    }
    strlen = (MTPNP_INT16) gui_strlen((UI_string_type) s) << 1;
    for (i = strlen - 2; i > 0; i -= 2)
    {
        if (s[i] != 0x20 || s[i + 1] != 0x00)
        {
            break;
        }
        else
        {
            s[i] = '\0';
            s[i + 1] = '\0';
        }
    }
    g_slave_idle_screen_line1text = (UI_string_type) s;
}

void MTPNP_PFAL_SetIdleScreenNetworkStatus(MTPNP_UCHAR * s)
{
    MTPNP_INT16 strlen, i, real_pos;
    MTPNP_INT8 start_flag = 0;

    real_pos = 0;
    strlen = (MTPNP_INT16) gui_strlen((UI_string_type) s) << 1;
    for (i = 0; i < strlen; i += 2)
    {
        if (s[i] != 0x20 || s[i + 1] != 0x00)
        {
            start_flag = 1;
        }
        if (start_flag == 1)
        {
            s[real_pos] = s[i];
            s[real_pos + 1] = s[i + 1];
            real_pos += 2;
        }
    }
    if (real_pos < strlen)
    {
        for (i = real_pos; i < strlen; i++)
        {
            s[i] = '\0';
        }
    }
    strlen = (MTPNP_INT16) gui_strlen((UI_string_type) s) << 1;
    for (i = strlen - 2; i > 0; i -= 2)
    {
        if (s[i] != 0x20 || s[i + 1] != 0x00)
        {
            break;
        }
        else
        {
            s[i] = '\0';
            s[i + 1] = '\0';
        }
    }
    g_slave_idle_screen_line2text = (UI_string_type) s;
}

void MTPNP_PFAL_RefreshNwProviderName(MTPNP_UCHAR * plmn)
{
#if 0
#if ( (defined __MMI_EONS_SUPPORT__) && (defined MMI_ON_HARDWARE_P) )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* ( (defined __MMI_EONS_SUPPORT__) && (defined MMI_ON_HARDWARE_P) ) */
#endif
    mmi_netset_retrieve_opname_from_plmn(plmn, g_slave_nw_providername);
}

#define SetLine3Text MTPNP_PFAL_SetIdleScreenNetworkName
#define SetLine4Text MTPNP_PFAL_SetIdleScreenNetworkStatus

void MTPNP_PFAL_Empty_Slave_IdleField(void)
{
    SetLine3Text((MTPNP_UINT8 *) MTPNP_NULL);
    SetLine4Text((MTPNP_UINT8 *) MTPNP_NULL);
}

void MTPNP_PFAL_Show_Idle_NW_Register(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_SEARCHING_NW), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_Card2Closed(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD2_CLOSED), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_Card2_DuringClose(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD2_DURINGCLOSE), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_NetWorkFlag(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    MTPNP_BOOL OPN_Exist;
    MTPNP_BOOL SPN_Exist;
    MTPNP_BOOL MSISDN_Exist;
    MTPNP_UINT8 Scenario;
    MTPNP_UINT8 MSISDN_Flag;

    extern MTPNP_UINT8 gOpNameValid_2;
    extern MTPNP_UINT8 gSpnValid_2;
    extern MTPNP_UINT8 gPLMN_2[];

    extern idle_nitz_struct g_nitz_display_2;

    MTPNP_PFAL_Read_Show_Owner_Number_Flag(&MSISDN_Flag);
    MSISDN_Exist = ((MTPNP_BOOL) MSISDN_Flag) && (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_slave_ownername) != 0);

    OPN_Exist = gOpNameValid_2 && (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_slave_operatorname) != 0) /* && SHOW_OPN */ ;
    SPN_Exist = gSpnValid_2 && (MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_slave_servprovderName) != 0);

    if (IsChineseSet() && mmi_idle_is_camp_on_chinese_network(gPLMN_2) && !MTPNP_AD_Card2_IsRoam()) /* Trad. Chinese and Simp. Chinese only */
    {
        /* Ignore OPN because OPN does not have UCS2 encoding */
        Scenario = (gSpnValid_2 ? 2 : 0) + (MTPNP_PFAL_Is_Show_OPN() ? 1 : 0);
    }
    else
    {
        /* OPN*4 + SPN*2+ b1*1 */
        Scenario = (gOpNameValid_2 ? 4 : 0) + (gSpnValid_2 ? 2 : 0) + (MTPNP_PFAL_Is_Show_OPN() ? 1 : 0);
    }

    switch (Scenario)   /* OPN--SPN--b1 */
    {
        case 0:                             /* OPN=OFF, SPN=OFF, b1=0 */
        case 1:                             /* OPN=OFF, SPN=OFF, b1=1 */
            MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
            if (MSISDN_Exist)
            {
                MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2: Owner Name */
            }
            break;

        case 2: /* OPN=OFF, SPN=ON, b1=0 */
            if (MSISDN_Exist)
            {
                if (MTPNP_AD_Card2_IsRoam()/* && !mmi_idle_is_rplmn_in_spdi_list()*/)
                {
                    MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                    if (SPN_Exist/* && !mmi_idle_is_spn_b2_set()*/ && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_nw_providername) != 0)
                    {
                        MTPNP_PFAL_Show_Idle_SPN();  /* Line 2 = SPN */
                    }
                    else
                    {
                        MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2: Owner Name */
                    }
                }
                else
                {
                    MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2: Owner Name */
                    if (SPN_Exist)
                    {
                        SetLine3Text((MTPNP_UINT8*) g_slave_servprovderName); /* Line 1 = SPN */
                    }
                }
            }
            else
            {
                if (MTPNP_AD_Card2_IsRoam()/* && !mmi_idle_is_rplmn_in_spdi_list()*/)
                {
                    MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                    if (SPN_Exist/* && !mmi_idle_is_spn_b2_set()*/ && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_nw_providername) != 0)
                    {
                        MTPNP_PFAL_Show_Idle_SPN();  /* Line 2 = SPN */
                    }
                }
                else
                {
                    if (SPN_Exist)
                    {
                        SetLine3Text((MTPNP_UINT8*) g_slave_servprovderName);  /* Line 1 = SPN */
                    }
                    else
                    {
                        MTPNP_PFAL_Show_Idle_OPN();  /* Line 2 = NULL */
                    }
                }
            }
            break;

        case 3:                             /* OPN=OFF, SPN=ON, b1=1 */
            MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
            if (MTPNP_AD_Card2_IsRoam()/* && !mmi_idle_is_rplmn_in_spdi_list()*/)
            {
                if (SPN_Exist/* && !mmi_idle_is_spn_b2_set()*/ && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_nw_providername) != 0)
                {
                    MTPNP_PFAL_Show_Idle_SPN();  /* Line 2 = SPN */
                }
                else if (MSISDN_Exist)
                {
                    MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2: Owner Name */
                }
                else
                {
                    SetLine4Text((MTPNP_UINT8*) NULL);
                }
            }
            else
            {
                if (SPN_Exist && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_nw_providername) != 0)
                {
                    MTPNP_PFAL_Show_Idle_SPN();  /* Line 2 = SPN */
                }
                else if (MSISDN_Exist)
                {
                    MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2: Owner Name */
                }
                else
                {
                    SetLine4Text((MTPNP_UINT8*) NULL);
                }
            }
            break;

        case 4: /* OPN=ON, SPN=OFF, b1=0 */
        case 5: /* OPN=ON, SPN=OFF, b1=1 */
            if (MTPNP_AD_Card2_IsRoam() == MMI_TRUE)
            {
                MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                if (OPN_Exist)
                {
                    SetLine4Text((MTPNP_UINT8*) g_slave_operatorname); /* Line 2 = OPN */
                }
                else    /* They are both valid but NULL */
                {
                    SetLine4Text((MTPNP_UINT8*) NULL);
                }
            }
            else
            {
                if (OPN_Exist)
                {
                    SetLine3Text((MTPNP_UINT8*) g_slave_operatorname); /* Line 1 = OPN */
                }
                else    /* They are both valid but NULL */
                {
                    MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                }
                if (MSISDN_Exist)
                {
                    MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2 = Owner Name */
                }
            }
            break;

        case 6: /* OPN=ON, SPN=ON, b1=0 */
        case 7: /* OPN=ON, SPN=ON, b1=1 */
            if (MTPNP_AD_Card2_IsRoam() == MMI_TRUE/* && !mmi_idle_is_rplmn_in_spdi_list()*/)
            {
                MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                if (SPN_Exist && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_nw_providername) != 0)
                {
                    MTPNP_PFAL_Show_Idle_SPN();      /* Line 2 = SPN */
                }
                else if (MSISDN_Exist)
                {
                    MTPNP_PFAL_Show_Idle_OwnerName();
                }
                else
                {
                    SetLine4Text((MTPNP_UINT8*) NULL);
                }
            }
            else
            {
                if (OPN_Exist)
                {
                    SetLine3Text((MTPNP_UINT8*) g_slave_operatorname); /* Line 1 = OPN */
                    if (SPN_Exist/* && !mmi_idle_is_spn_b2_set()*/ && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_operatorname) != 0)
                    {
                        MTPNP_PFAL_Show_Idle_SPN();  /* Line 2 = SPN */
                    }
                    else if (MSISDN_Exist)
                    {
                        MTPNP_PFAL_Show_Idle_OwnerName();        /* Line 2 = MSISDN */
                    }
                    else
                    {
                        SetLine4Text((MTPNP_UINT8*) NULL);
                    }
                }
                else    /* They are both valid but NULL */
                {
                    if (MTPNP_PFAL_Is_Show_OPN())
                    {
                        MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                        if (SPN_Exist && mmi_ucs2icmp((S8*) g_slave_servprovderName, (S8*) g_slave_nw_providername) != 0)
                        {
                            MTPNP_PFAL_Show_Idle_SPN();  /* Line 2 = SPN */
                        }
                        else if (MSISDN_Exist)
                        {
                            MTPNP_PFAL_Show_Idle_OwnerName();        /* Line 2 = MSISDN */
                        }
                        else
                        {
                            SetLine4Text((MTPNP_UINT8*) NULL);
                        }
                    }
                    else
                    {
                        if (SPN_Exist)
                        {
                            SetLine3Text((MTPNP_UINT8*) g_slave_servprovderName);  /* Line 1: SPN */
                        }
                        else
                        {
                            MTPNP_PFAL_Show_Idle_OPN();  /* Line 1 = PLMN */
                        }

                        if (MSISDN_Exist)
                        {
                            MTPNP_PFAL_Show_Idle_OwnerName(); /* Line 2: Owner Name */
                        }
                    }
                }
            }
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

#ifdef __MMI_NITZ__
    mmi_idle_update_sim2_nitz_content();
    if (g_nitz_display_2.opname_from_nitz && mmi_idle_check_sim2_nitz_display_validation())
    {
        PRINT_INFORMATION("[Idle] Network name from NITZ");
        if (MTPNP_AD_Card2_IsRoam())
        {
            /* Roaming and receive NITZ network name */
            SetLine3Text(g_nitz_display_2.display_name);
        }
        else if (!OPN_Exist && mmi_idle_is_spn_b1_set()) /* not roaming but no OPN */
        {
            /* Network name from NITZ takes lower priority from OPN, but not replace SPN */
            SetLine3Text(g_nitz_display_2.display_name);
        }
    }
#endif /* __MMI_NITZ__ */ 
}

void MTPNP_PFAL_Show_Idle_NW_Noservice(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_NOSERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_NW_Manual(void)
{
    if (mmi_bootup_is_sim2_nw_registration_ok() == MMI_FALSE)
    {
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STR_SIM_INVALID_SIM_TITLE), MAX_LENGTH_DISPLAY_NAME - 1);
    }
    else
    {
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_NETSET_MANUAL_MODE),
                                   MAX_LENGTH_DISPLAY_NAME - 1);
    }
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_NW_Limitservice(void)
{
    if (mmi_bootup_is_sim2_nw_registration_ok() == MMI_FALSE)
    {
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STR_SIM_INVALID_SIM_TITLE), MAX_LENGTH_DISPLAY_NAME - 1);
    }
    else
    {
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_LIMITSERVICE), MAX_LENGTH_DISPLAY_NAME - 1);
    }
    SetLine3Text(g_slave_nw_providername);
}

#define SetLine1Text SetIdleScreenNetworkName
#define SetLine2Text SetIdleScreenNetworkStatus
void MTPNP_PFAL_Show_Idle_Card1Absent(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) gNWProviderName,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD1ABSENT), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine1Text(gNWProviderName);
}

void MTPNP_PFAL_Show_Idle_Card1Blocked(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) gNWProviderName,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD1_SIM_BLOCK), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine1Text(gNWProviderName);
}

void MTPNP_PFAL_Show_Idle_Card1Closed(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) gNWProviderName,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD1_CLOSED), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine1Text(gNWProviderName);
}

#undef SetLine1Text
#undef SetLine2Text

void MTPNP_PFAL_Show_Idle_Card2Absent(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD2ABSENT), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_Card2Blocked(void)
{
    MTPNP_PFAL_Unicode_Memory_Copy((MTPNP_CHAR *) g_slave_nw_providername,
                                   (MTPNP_CHAR *) GetString(STRING_MTPNP_CARD2_SIM_BLOCK), MAX_LENGTH_DISPLAY_NAME - 1);
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_OwnerName(void)
{
    SetLine4Text(g_slave_ownername);
}

void MTPNP_PFAL_Show_Idle_OPN(void)
{
    SetLine3Text(g_slave_nw_providername);
}

void MTPNP_PFAL_Show_Idle_SPN(void)
{
    SetLine4Text(g_slave_servprovderName);
}

void MTPNP_PFAL_Refresh_Card2_Owner_Number(void)
{
    MTPNP_UINT8 idx = 0, iCnt = 0;
    MTPNP_INT StringWidth, StringHeight;
    stFontAttribute prev_f;
    E_MTPNP_AD_LINE_TPYE line = MTPNP_AD_LINE_NONE;

    line = MTPNP_AD_Get_Card2CurrLineID();

    kal_prompt_trace(MTPNP_PFAL_Get_MTPNP_Task_Mod(), "line: %d", line);

    if (line == MTPNP_AD_LINE_1)
    {
        MTPNP_AD_Active_Owner_Number(MTPNP_AD_MSISDN_DISPLAY_DEFAULT, 0);
    }
    else
    {
        MTPNP_AD_Active_Owner_Number(MTPNP_AD_MSISDN_DISPLAY_DEFAULT, 1);
    }

    iCnt = MTPNP_AD_Get_Active_Owner_Info((MTPNP_CHAR *) g_slave_ownername);

    MTPNP_OSAL_memcpy(&prev_f, UI_font, sizeof(stFontAttribute));
    UI_set_font(&UI_DEFAULT_FONT);
    for (iCnt = (U8) MTPNP_PFAL_Unicode_String_Length((MTPNP_CHAR *) g_slave_ownername); iCnt > 0; iCnt--)
    {
        Get_StringWidthHeight((MTPNP_UINT8 *) g_slave_ownername, &StringWidth, &StringHeight);
        if ((StringWidth + 1) >= MAIN_LCD_device_width - (MMI_IDLE_STRING_MARGIN_GAP << 1))
        {
            g_slave_ownername[iCnt * ENCODING_LENGTH] = 0x0;

            g_slave_ownername[iCnt * ENCODING_LENGTH + 1] = 0x0;
        }
        else
        {
            break;
        }
    }
    UI_set_font(&prev_f);
}
 #if defined(__MMI_NOKIA_IDLE__)
extern U8 ldeStytleFlag;	
 #endif
void MTPNP_PFAL_Rearrange_StatusBar(void)
{
    E_MTPNP_AD_STATUS status;
    E_MTPNP_AD_LINE_TPYE card1_line_id;
    E_MTPNP_AD_LINE_TPYE card2_line_id;
    MTPNP_BOOL master_sms_is_full = MTPNP_FALSE, slave_sms_is_full = MTPNP_FALSE;

    /* if not slave plug in indicate, do not rearrange the statusbar */
    if (!MTPNP_AD_Slave_Is_Plugged())
        return;

    status = MTPNP_AD_Get_Status();

    card1_line_id = MTPNP_AD_Get_Card1CurrLineID();
    card2_line_id = MTPNP_AD_Get_Card2CurrLineID();

    master_sms_is_full = mmi_msg_need_mem_full_ind();
    if (MTPNP_AD_Card2_SMS_Is_Avail())
    {
        slave_sms_is_full = MTPNP_FALSE;
    }
    else
    {
        slave_sms_is_full = MTPNP_TRUE;
    }

    switch (status)
    {
    case MTPNP_AD_DUALCARD:
        /* signal icon */
        if (card1_line_id == MTPNP_AD_LINE_1)
        {
            /*#if defined(__MMI_NOKIA_IDLE__)
		   if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_STRENGTH_L1);
		   else
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
	     //#endif
        }
        else if (card1_line_id == MTPNP_AD_LINE_2)
        {
             /*#if defined(__MMI_NOKIA_IDLE__)
		   if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_STRENGTH_L2);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
		 //#endif
        }
        else
        {
        /*#if defined(__MMI_NOKIA_IDLE__)
		   if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_STRENGTH);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
		// #endif
        }
        if (card2_line_id == MTPNP_AD_LINE_1)
        {
       /* #if defined(__MMI_NOKIA_IDLE__)
		   if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_STRENGTH_L1);
		   else
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L1);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L1);
		 //#endif
        }
        else if (card2_line_id == MTPNP_AD_LINE_2)
        {
        /*#if defined(__MMI_NOKIA_IDLE__)
		   if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_STRENGTH_L2);
		   else
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L2);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L2);
		 //#endif
        }
        else
        {
       /* #if defined(__MMI_NOKIA_IDLE__)
		   if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_STRENGTH);
		   else
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
		 //#endif
        }
        /* sms icon */
        if (master_sms_is_full)
        {
            MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
        }
        else
        {
            MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
        }
        if (slave_sms_is_full)
        {
            MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
        }
        else
        {
            MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
        }
        /* CFU icon */
        CPHSDisplayCFUInd(NULL);
        MTPNP_PFAL_CC_DisplayCFUInd(NULL);
        break;
    case MTPNP_AD_CARD1:
        /* signal icon */
        if (card1_line_id == MTPNP_AD_LINE_1)
        {
            /*#if defined(__MMI_NOKIA_IDLE__)
              if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_STRENGTH_L1);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L1);
		// #endif
        }
        else if (card1_line_id == MTPNP_AD_LINE_2)
        {
        /*#if defined(__MMI_NOKIA_IDLE__)
          if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_STRENGTH_L2);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH_L2);
		 //#endif
        }
        else
        {
       /* #if defined(__MMI_NOKIA_IDLE__)
          if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_STRENGTH);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
		// #endif
        }
		/*#if defined(__MMI_NOKIA_IDLE__)
		  if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_CLOSED);
		   else
        MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
	     #else*/
        MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
		 //#endif
        /* sms icon */
        if (master_sms_is_full)
        {
            MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
        }
        else
        {
            MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
        }
        if (slave_sms_is_full)
        {
            MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
        }
        else
        {
            MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
        }
        /* CFU icon */
        HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD_L1);
        HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD_L2);
        HideStatusIcon(STATUS_ICON_SLAVE_CALLFORWARD);
        CPHSDisplayCFUInd(NULL);
        break;
    case MTPNP_AD_CARD2:
		/*#if defined(__MMI_NOKIA_IDLE__)
		  if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_CLOSED);
		   else
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
	     #else*/
        MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
		// #endif
        if (card2_line_id == MTPNP_AD_LINE_1)
        {
        /*#if defined(__MMI_NOKIA_IDLE__)
		  if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_STRENGTH_L1);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L1);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L1);
		// #endif
        }
        else if (card2_line_id == MTPNP_AD_LINE_2)
        {
        /*#if defined(__MMI_NOKIA_IDLE__)
		  if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_STRENGTH_L2);
		   else
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L2);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH_L2);
		// #endif
        }
        else
        {
        /*#if defined(__MMI_NOKIA_IDLE__)
		  if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_STRENGTH);
		   else
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
	     #else*/
            MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
		 //#endif
        }
        /* sms icon */
        if (master_sms_is_full)
        {
            MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
        }
        else
        {
            MTPNP_PFAL_Refresh_StatusBar_Card1_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
        }
        if (slave_sms_is_full)
        {
            MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_TRUE, MTPNP_FALSE);
        }
        else
        {
            MTPNP_PFAL_Refresh_StatusBar_Card2_SMS_Display(MTPNP_FALSE, MTPNP_FALSE);
        }
        /* CFU icon */
        HideStatusIcon(STATUS_ICON_CALL_DIVERT_L1);
        HideStatusIcon(STATUS_ICON_CALL_DIVERT_L2);
        HideStatusIcon(STATUS_ICON_CALL_DIVERT_L1L2);
        MTPNP_PFAL_CC_DisplayCFUInd(NULL);
        break;
    case MTPNP_AD_FLIGHT:
	 /* #if defined(__MMI_NOKIA_IDLE__)
		  if((GetActiveScreenId() == IDLE_SCREEN_ID)&& (ldeStytleFlag == 1))
		  {
		   	  MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_IDLE_MASTER_SIGNAL_CLOSED);
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_IDLE_SLAVE_SIGNAL_CLOSED);
		  }
		   else
		   {
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
                       MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
		   }
	  #else*/
        MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED);
        MTPNP_PFAL_Replace_StatusICON(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED);
	 // #endif
        /* sms icon */
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_INCOMING_SMS);
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SUBLCD_SMS);
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SLAVE_INCOMING_SMS);
        break;
    default:
        break;
    }

    /* handle missed call icon except flight mode */
    MTPNP_PFAL_CHIST_Rearrange_Missed_Call_Status_Icon();

#if defined(__MMI_MESSAGES_CHAT__)
	// Huyanwei Add It 
	MTPNP_PFAL_Refresh_StatusBar_Chat_Display(status);
#endif

#ifdef __MMI_EMAIL__
    mmi_email_bearer_status_show_icon();
#endif

    MTPNP_PFAL_Refresh_StatusBar();
	MTPNP_PFAL_check_SMS_Waiting_Icon();
}

void MTPNP_PFAL_Update_Slave_Cipher_Icon(MTPNP_BOOL cipher)
{
    if (cipher)
    {
        MTPNP_PFAL_Hide_StatusICON(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
    }
    else
    {
        MTPNP_PFAL_Show_StatusICON(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
    }

    MTPNP_PFAL_Refresh_StatusBar();
}

void MTPNP_PFAL_Rearrange_RootScreen(DUALMODE_SWITCH_STATUS *dm_switch)
{
    extern MTPNP_UINT16 simErrorDisplayString;
    DUALMODE_SWITCH_STATUS tmp_dm_switch;

    MTPNP_PFAL_Refresh_Slave_Idle_ServiceArea();
    memcpy(&tmp_dm_switch, dm_switch, sizeof (DUALMODE_SWITCH_STATUS));

    if (tmp_dm_switch.src_status == MTPNP_FLIGHTMODE_CONFIG && (g_pwr_context.CurrentServiceType == FULL_SERVICE || g_pwr_context_2.CurrentServiceType == FULL_SERVICE))
    {
        /* play camp on tone */
        g_pwr_context.IsCampOnTonePlayed = 1;
        g_pwr_context_2.IsCampOnTonePlayed = 1;
        mmi_phnset_flight_mode_camp_on_tone_hdlr();
    }

    if (g_idle_context.IsOnIdleScreen || g_idle_context.IsOnSimErrorScreen)
    {
        /* force to add root screen to history if current is on root screen */
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    }

    if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT)
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            // case 4, 8 ,12
            // still idle screen
            if ((MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_PFAL_Is_Card1CHVBlocked()) || 
                (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_PFAL_Is_Card2CHVBlocked()))
            {
                simErrorDisplayString = STR_SIM_BLOCK_MSG;
                HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_BLOCK, EntryScrnSimBlockRsp);
            }
            else
            {
                HistoryReplace(SCR_SIM_BLOCK, IDLE_SCREEN_ID, EntryIdleScreen);
            }
        }
        else
        {
            // case 2, 6 ,10
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
            {
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
                HistoryReplace(SCR_SIM_BLOCK, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
            }
            else
            {
                if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 && MTPNP_PFAL_Is_Card1CHVBlocked())
                {
                    simErrorDisplayString = STR_SIM_BLOCK_MSG;
                    HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_BLOCK, EntryScrnSimBlockRsp);
                    HistoryReplace(SCR_SIM_INSERTION, SCR_SIM_BLOCK, EntryScrnSimBlockRsp);
                }
                else
                {
                    HistoryReplace(SCR_SIM_INSERTION, IDLE_SCREEN_ID, EntryIdleScreen);
                    HistoryReplace(SCR_SIM_BLOCK, IDLE_SCREEN_ID, EntryIdleScreen);
                }
            }
        }
    }
    else
    {
        if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            // case 3, 7 ,11
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1)
            {
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
                HistoryReplace(SCR_SIM_BLOCK, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
            }
            else
            {
                if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 && MTPNP_PFAL_Is_Card2CHVBlocked())
                {
                    simErrorDisplayString = STR_SIM_BLOCK_MSG;
                    HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_BLOCK, EntryScrnSimBlockRsp);
                    HistoryReplace(SCR_SIM_INSERTION, SCR_SIM_BLOCK, EntryScrnSimBlockRsp);
                }
                else
                {
                    HistoryReplace(SCR_SIM_INSERTION, IDLE_SCREEN_ID, EntryIdleScreen);
                    HistoryReplace(SCR_SIM_BLOCK, IDLE_SCREEN_ID, EntryIdleScreen);
                }
            }
        }
        else
        {
            // case 1, 5 ,7
            // still insert sim screen
            if (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 || MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2)
            {
                simErrorDisplayString = STR_SIM_INSERTION_MSG;
                HistoryReplace(IDLE_SCREEN_ID, SCR_SIM_INSERTION, EntryScrnSimErrorScreen);
            }
            else
            {
                HistoryReplace(SCR_SIM_INSERTION, IDLE_SCREEN_ID, EntryIdleScreen);
            }
        }
    }

    /* reset all channels because the previous channel may no longer available after mode switch */
    MTPNP_AD_Free_Channel(MTPNP_AD_CALL_CHANNEL);
    MTPNP_AD_Free_Channel(MTPNP_AD_SMS_CHANNEL);
    MTPNP_AD_Free_Channel(MTPNP_AD_DATA_SERVICE_CHANNEL);
    MTPNP_AD_Free_Channel(MTPNP_AD_AUDIO_RECORD);

    /* sim error menu */
    if (IsScreenPresent(IDLE_SCREEN_ID))
    {
        mmi_sim_error_unhide_menu_items();
    }
    else
    {
        mmi_sim_error_hide_menu_items();
    }
}

void MTPNP_PFAL_Rearrange_NetworkIcons(DUALMODE_SWITCH_STATUS *dm_switch)
{
    DUALMODE_SWITCH_STATUS tmp_dm_switch;

    memcpy(&tmp_dm_switch, dm_switch, sizeof (DUALMODE_SWITCH_STATUS));

    if (tmp_dm_switch.src_status == MTPNP_FLIGHTMODE_CONFIG)
    {
        PhnsetFlightModeRestoreStatusIconFlags(MMI_TRUE);
        mmi_flight_mode_unhide_menu_items();
    }

    if (tmp_dm_switch.dest_status == MTPNP_FLIGHTMODE_CONFIG)
    {
        PhnsetFlightModeSaveStatusIconFlags(MMI_TRUE);
        mmi_flight_mode_hide_menu_items();
    }
}

void MTPNP_PFAL_Rearrange_SignalIcons(void)
{
    if (MTPNP_AD_Get_Status() == MTPNP_AD_DUALCARD)
    {
        if (MTPNP_AD_Get_Card1Status() != MTPNP_AD_SIMCARD_ABSENT)
        {
            if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
            {
                // do nothing...
            }
            else
            {
                // case 10
                MTPNP_PFAL_Update_SlaveQOS(0);
            }
        }
        else
        {
            if (MTPNP_AD_Get_Card2Status() != MTPNP_AD_SIMCARD_ABSENT)
            {
                gSignalStrengthLevel = 0;
                ChangeStatusIconLevel(STATUS_ICON_SIGNAL_STRENGTH, gSignalStrengthLevel);
            }
            else
            {
                // case 9
                MTPNP_PFAL_Update_SlaveQOS(0);
            }
        }
    }
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
