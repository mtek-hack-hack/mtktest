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
 *  CentralConfigAgentConfig.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Target Application Configuration File
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_CCA_SUPPORT__

#include "CentralConfigAgentGProt.h"


/*----------------------------------------------------------------*/
/* DECLARATIONS: DATA ACCOUNT                                     */
/*----------------------------------------------------------------*/
static const U16 dtacct_l1symbols[]     =   {CCA_NS_OMA_NAPDEF};
extern cca_status_enum mmi_dtcnt_ota_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list);

/*----------------------------------------------------------------*/
/* DECLARATIONS: WLAN                                             */
/*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_OTAP_OMAEXT__)
    static const U16 wlan_l1symbols[]       =   {CCA_NS_OMA_NAPDEF};
#elif defined(__MMI_WLAN_OTAP_DMP__)
/* under construction !*/
#endif
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    extern cca_status_enum mmi_wlan_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list);
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

/*----------------------------------------------------------------*/
/* DECLARATIONS: BROWSER                                          */
/*----------------------------------------------------------------*/
static const S8 *browser_appids[]       =   {"w2"};
static const U16 browser_l1symbols[]    =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};

/*----------------------------------------------------------------*/
/* DECLARATIONS: MMS                                              */
/*----------------------------------------------------------------*/
static const S8 *mms_appids[]           =   {"w4", "ap0005"};
static const U16 mms_l1symbols[]        =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};

/*----------------------------------------------------------------*/
/* DECLARATIONS: SIP                                              */
/*----------------------------------------------------------------*/
//static const S8 *sip_appids[]           =   {"ap0002"};
//static const U16 sip_l1symbols[]        =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};
#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */

/*----------------------------------------------------------------*/
/* DECLARATIONS: EMAIL                                            */
/*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    static const S8 *email_appids[]         =   {"25", "110", "143"};
    static const U16 email_l1symbols[]      =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};
#endif  /* __MMI_EMAIL_OTAP__ */

/*----------------------------------------------------------------*/
/* DECLARATIONS: SyncML-DS                                        */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_CCA_SUPPORT__
    static const S8 *syncmlds_appids[]      =   {"w5"};
    static const U16 syncmlds_l1symbols[]   =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};
#endif  /* __MMI_SYNCML_CCA_SUPPORT__ */

/*----------------------------------------------------------------*/
/* DECLARATIONS: SyncML-DM                                        */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DM_OTAP__
    static const S8 *syncmldm_appids[]      =   {"w7"};
    static const U16 syncmldm_l1symbols[]   =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};
#endif /* __MMI_SYNCML_DM_OTAP__ */

/*----------------------------------------------------------------*/
/* DECLARATIONS: IMPS                                             */
/*----------------------------------------------------------------*/
#ifdef __MMI_IMPS_OTA__
    static const S8 *imps_appids[]          =   {"wA"};
    static const U16 imps_l1symbols[]       =   {CCA_NS_OMA_PROXY, CCA_NS_OMA_APPLICATION};
#endif  /* __MMI_IMPS_OTA__ */

/*----------------------------------------------------------------*/
/* DECLARATIONS: FOTA                                             */
/*----------------------------------------------------------------*/
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif



/*----------------------------------------------------------------*/
/* Target Application Configuration                               */
/*----------------------------------------------------------------*/

const cca_app_config_struct cca_app_config_g[] = 
{
/*  {config_id, fpAppCheckDoc, appids, num_appids, l1node_symbols, num_l1node_symbols}
 *
 *  config_id:      Application Config ID, eg, CCA_CONFIG_DTACCT, CCA_CONFIG_BROWSER (defined in CentralConfigAgentConst.h)
 *  fpAppCheckDoc:  Application callback checking whether it has interests in this document
 *  appids:         Array of strings indicating its APPID value(s)
 *  num_appids:     Number of APPIDs listed in appids array
 *  l1node_symbols: Array of CCA Symbols indicating the interested level 1 node symbols
 *  num_l1node_symbols:  Number of level 1 node symbols listed in l1node_symbols
 *
 */

/*----------------------------------------------------------------*/
/* APP CONFIG: DATA ACCOUNT                                       */
/*----------------------------------------------------------------*/
    {CCA_CONFIG_DTACCT, mmi_dtcnt_ota_is_cca_target, NULL, 0, dtacct_l1symbols, sizeof(dtacct_l1symbols)/sizeof(U16)},

/*----------------------------------------------------------------*/
/* APP CONFIG: WLAN                                               */
/*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_OTAP_OMAEXT__)
	{CCA_CONFIG_WLAN, mmi_wlan_is_cca_target, NULL, 0, wlan_l1symbols, sizeof(wlan_l1symbols) / sizeof(U16)},
#elif defined(__MMI_WLAN_OTAP_DMP__)
/* under construction !*/
#endif

/*----------------------------------------------------------------*/
/* APP CONFIG: BROWSER                                            */
/*----------------------------------------------------------------*/
#if defined(OBIGO_Q03C)
    /* Obigo Q03C */
    {CCA_CONFIG_BROWSER, 0, browser_appids, sizeof(browser_appids)/sizeof(S8*), browser_l1symbols, sizeof(browser_l1symbols)/sizeof(U16)},
#elif defined(__MMI_BROWSER_2__)
    /* Obigo Q05A */
    {CCA_CONFIG_BROWSER, 0, browser_appids, sizeof(browser_appids)/sizeof(S8*), browser_l1symbols, sizeof(browser_l1symbols)/sizeof(U16)},
#elif defined(JATAAYU_SUPPORT)
    /* Jataayu */
    {CCA_CONFIG_BROWSER, 0, browser_appids, sizeof(browser_appids)/sizeof(S8*), browser_l1symbols, sizeof(browser_l1symbols)/sizeof(U16)},
#endif

/*----------------------------------------------------------------*/
/* APP CONFIG: MMS                                                */
/*----------------------------------------------------------------*/
#if defined(OBIGO_Q03C)
    /* Obigo Q03C */
    {CCA_CONFIG_MMS, 0, mms_appids, sizeof(mms_appids)/sizeof(S8*), mms_l1symbols, sizeof(mms_l1symbols)/sizeof(U16)},
#elif defined(__MMI_BROWSER_2__)
    /* Obigo Q05A */
    {CCA_CONFIG_MMS, 0, mms_appids, sizeof(mms_appids)/sizeof(S8*), mms_l1symbols, sizeof(mms_l1symbols)/sizeof(U16)},
#elif defined(JATAAYU_SUPPORT)
    /* Jataayu */
    {CCA_CONFIG_MMS, 0, mms_appids, sizeof(mms_appids)/sizeof(S8*), mms_l1symbols, sizeof(mms_l1symbols)/sizeof(U16)},
#endif

/*----------------------------------------------------------------*/
/* APP CONFIG: SIP                                                */
/*----------------------------------------------------------------*/
    //{CCA_CONFIG_SIP, 0, sip_appids, sizeof(sip_appids)/sizeof(S8*), sip_l1symbols, sizeof(sip_l1symbols)/sizeof(U16)},
#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
#endif /* __MMI_VOIP_OTAP_DMP__ */

/*----------------------------------------------------------------*/
/* APP CONFIG: EMAIL                                              */
/*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    {CCA_CONFIG_EMAIL, 0, email_appids, sizeof(email_appids)/sizeof(S8*), email_l1symbols, sizeof(email_l1symbols)/sizeof(U16)},
#endif  /* __MMI_EMAIL_OTAP__ */

/*----------------------------------------------------------------*/
/* APP CONFIG: SyncML-DS                                          */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_CCA_SUPPORT__
    {CCA_CONFIG_SYNCMLDS, 0, syncmlds_appids, sizeof(syncmlds_appids)/sizeof(S8*), syncmlds_l1symbols, sizeof(syncmlds_l1symbols)/sizeof(U16)},
#endif  /* __MMI_SYNCML_CCA_SUPPORT__ */

/*----------------------------------------------------------------*/
/* APP CONFIG: SyncML-DM                                          */
/*----------------------------------------------------------------*/
#ifdef __MMI_SYNCML_DM_OTAP__
    {CCA_CONFIG_SYNCMLDM, 0, syncmldm_appids, sizeof(syncmldm_appids)/sizeof(S8*), syncmldm_l1symbols, sizeof(syncmldm_l1symbols)/sizeof(U16)},
#endif /* __MMI_SYNCML_DM_OTAP__ */

/*----------------------------------------------------------------*/
/* APP CONFIG: IMPS                                               */
/*----------------------------------------------------------------*/
#ifdef __MMI_IMPS_OTA__
    {CCA_CONFIG_IMPS, 0, imps_appids, sizeof(imps_appids)/sizeof(S8*), imps_l1symbols, sizeof(imps_l1symbols)/sizeof(U16)},
#endif  /* __MMI_IMPS_OTA__ */

/*----------------------------------------------------------------*/
/* APP CONFIG: FOTA                                               */
/*----------------------------------------------------------------*/
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
#endif


/* please insert above this line */
    {0xFFFF, 0, 0, 0, 0, 0}
};



/*****************************************************************************
 * FUNCTION
 *  mmi_cca_get_module_id_by_app
 * DESCRIPTION
  *  get KAL module ID based on CCA's app_id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
module_type mmi_cca_get_module_id_by_app(U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (app_id)
    {
        case CCA_APP_DTACCT:
            return MOD_MMI;
        case CCA_APP_WLAN:
            return MOD_MMI;
        case CCA_APP_BROWSER:
#if defined(OBIGO_Q03C)
            return MOD_WAP;
#elif defined(__MMI_BROWSER_2__)
            return MOD_MMI;
#elif defined(JATAAYU_SUPPORT)
            return MOD_WAP;
#else
            return MOD_NIL;
#endif
        case CCA_APP_MMS:
#if defined(OBIGO_Q03C)
            return MOD_WAP;
#elif defined(__MMI_BROWSER_2__)
            return MOD_MMI;
#elif defined(JATAAYU_SUPPORT)
            return MOD_WAP;
#else
            return MOD_NIL;
#endif
        case CCA_APP_SIP:
            return MOD_MMI;
        case CCA_APP_EMAIL:
            return MOD_MMI;
        case CCA_APP_SYNCMLDS:
            return MOD_MMI;
        case CCA_APP_SYNCMLDM:
            return MOD_MMI;
        case CCA_APP_IMPS:
            return MOD_MMI;
        case CCA_APP_FOTA:
            return MOD_MMI;
    }
    return MOD_NIL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_get_module_id_by_config
 * DESCRIPTION
 *  get KAL module ID based on CCA's config_id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
module_type mmi_cca_get_module_id_by_config(U16 config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cca_get_module_id_by_app((U16)CCA_GET_APP(config_id));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cca_get_app_names
 * DESCRIPTION
 *  get application display name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID_TYPE mmi_cca_get_app_names(U16 config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (config_id)
    {
        case CCA_CONFIG_DTACCT:
            return STR_ID_CCA_DTACCT;
        case CCA_CONFIG_WLAN:
            return STR_ID_CCA_WLAN;
        case CCA_CONFIG_BROWSER:
            return STR_ID_CCA_BROWSER;
        case CCA_CONFIG_MMS:
            return STR_ID_CCA_MMS;
        case CCA_CONFIG_SIP:
            return STR_ID_CCA_SIP;
        case CCA_CONFIG_EMAIL:
            return STR_ID_CCA_EMAIL;
        case CCA_CONFIG_SYNCMLDS:
            return STR_ID_CCA_SYNCMLDS;
        case CCA_CONFIG_SYNCMLDM:
            return STR_ID_CCA_SYNCMLDM;
        case CCA_CONFIG_IMPS:
            return STR_ID_CCA_IMPS;
#ifdef __MMI_WLAN_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }
    return 0;
}

#endif  /* __MMI_CCA_SUPPORT__ */


