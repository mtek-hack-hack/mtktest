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
 * JProfileStorageHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for NVRAM storage related part for the profiles (BROWSER & MMS .....)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _JPROFILESTORAGEHANDLER_C
#define _JPROFILESTORAGEHANDLER_C


#if defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT)))

#include "JProvWap.h"

#include "JProfileHandlerResDef.h"
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "PhoneBookGprot.h"     /* For extern pBOOL GetUCS2Flag(PS8 buffer) fun */
#include "JMMSGprot.h"
#include "Conversions.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_brw_profile_name_list
 * DESCRIPTION
 *  This reads the browser profile name list from the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_brw_profile_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_wap_prof_name_arr_p == NULL)
    {
        g_ph_cntx.ph_wap_prof_name_arr_p =
            (nvram_wap_profile_name_array_struct*) jdd_MemAlloc(NVRAM_EF_WAP_PROFILE_NAMES_SIZE, 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.ph_wap_prof_name_arr_p == NULL)
    {
        ASSERT(0);
    }
    /* Itishree Ends */
    ReadRecord(
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        1,
        g_ph_cntx.ph_wap_prof_name_arr_p,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_mms_profile_name_list
 * DESCRIPTION
 *  This reads the MMS profile name list from the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_mms_profile_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.ph_mms_prof_name_arr_p == NULL)
    {
        g_ph_cntx.ph_mms_prof_name_arr_p =
            (nvram_mms_profile_name_array_struct*) jdd_MemAlloc(NVRAM_EF_MMS_PROFILE_NAMES_SIZE, 1);
    }
    /* Itishree Adds */
    if (g_ph_cntx.ph_mms_prof_name_arr_p == NULL)
    {
        ASSERT(0);
    }
    /* Itishree Ends */
    ReadRecord(
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        1,
        g_ph_cntx.ph_mms_prof_name_arr_p,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_profile_nvram_content_data
 * DESCRIPTION
 *  This reads the content data for the given profile index from the NVRAM
 * PARAMETERS
 *  index       [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_profile_nvram_content_data(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ph_cntx.profile_module == PH_BROWSER_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_ph_cntx.ph_wap_profile_p,
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (g_ph_cntx.profile_module == PH_MMS_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_ph_cntx.ph_mms_profile_p,
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_activated_profile_data
 * DESCRIPTION
 *  This gets the activated profile content data from the NVRAM into the global context of the activated profile
 * PARAMETERS
 *  profile     [IN]        Profile type(Browser,MMS.....)
 *  index       [IN]        Activated profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_activated_profile_data(ph_profile_enum profile, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile == PH_BROWSER_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_ph_cntx.ph_activated_wap_profile,
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (profile == PH_MMS_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_ph_cntx.ph_activated_mms_profile,
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_nvram_wap_profile
 * DESCRIPTION
 *  This API updates the NVRAM data for the browser profile (both Name & Content)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_nvram_wap_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    U32 index = g_ph_cntx.profile_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_ph_cntx.profile_display_p->profile_name))
    {
        if (GetUCS2Flag((S8*) g_ph_cntx.profile_display_p->profile_name))
        {
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_UCS;
            mmi_ucs2ncpy(
                (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name),
                (S8*) g_ph_cntx.profile_display_p->profile_name,
                NVRAM_WAP_PROFILE_PROFILE_NAME_LEN);
        }
        else
        {
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_ASCII;
            mmi_ucs2_to_asc(
                (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name),
                (S8*) g_ph_cntx.profile_display_p->profile_name);
        }
    }
    else
    {
        S8 temp_unicode[8];
        S8 temp[4];
        S8 *profile_name_p = NULL;

        profile_name_p = (S8*) GetString((MMI_ID_TYPE) STR_ID_PROF_HDLR_PROFILE);
        sprintf(temp, "%d", (index + 1));
        mmi_asc_to_ucs2((S8*) temp_unicode, (S8*) temp);
        mmi_ucs2cpy((S8*) g_ph_cntx.profile_display_p->profile_name, profile_name_p);
        mmi_ucs2cat((S8*) g_ph_cntx.profile_display_p->profile_name, temp_unicode);

        g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_UCS;
        mmi_ucs2ncpy(
            (S8*) (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name),
            (S8*) g_ph_cntx.profile_display_p->profile_name,
            NVRAM_WAP_PROFILE_PROFILE_NAME_LEN);
    }

    mmi_ucs2_to_asc((S8*) g_ph_cntx.ph_wap_profile_p->homepage_url, (S8*) (g_ph_cntx.profile_display_p->homepage_url));
    mmi_ucs2_to_asc((S8*) (g_ph_cntx.ph_wap_profile_p->username), (S8*) (g_ph_cntx.profile_display_p->username));
    mmi_ucs2_to_asc((S8*) (g_ph_cntx.ph_wap_profile_p->password), (S8*) (g_ph_cntx.profile_display_p->password));

    g_ph_cntx.ph_wap_profile_p->empty = 0x00;   /* Added By Itishree */
    if (index == g_ph_cntx.wap_actived_profile_index)
    {
        memcpy(g_ph_cntx.ph_activated_wap_profile, g_ph_cntx.ph_wap_profile_p, NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }

    WriteRecord(
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        (U16) (index + 1),
        g_ph_cntx.ph_wap_profile_p,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        &error);
    WriteRecord(
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        1,
        g_ph_cntx.ph_wap_prof_name_arr_p,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        &error);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteNHistory(1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_nvram_mms_profile
 * DESCRIPTION
 *  This API updates the NVRAM data for the MMS profile (both Name & Content)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_nvram_mms_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    U32 index = g_ph_cntx.profile_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) g_ph_cntx.profile_display_p->profile_name))
    {
        if (GetUCS2Flag((S8*) g_ph_cntx.profile_display_p->profile_name))
        {
            g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_UCS;
            mmi_ucs2ncpy(
                (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name),
                (S8*) g_ph_cntx.profile_display_p->profile_name,
                NVRAM_WAP_PROFILE_PROFILE_NAME_LEN);
        }
        else
        {
            g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_ASCII;
            mmi_ucs2_to_asc(
                (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name),
                (S8*) g_ph_cntx.profile_display_p->profile_name);
        }
    }
    else
    {
        S8 temp_unicode[8];
        S8 temp[4];
        S8 *profile_name_p;

        profile_name_p = (S8*) GetString((MMI_ID_TYPE) STR_ID_PROF_HDLR_PROFILE);
        sprintf(temp, "%d", (index + 1));
        mmi_asc_to_ucs2((S8*) temp_unicode, (S8*) temp);
        mmi_ucs2cpy((S8*) g_ph_cntx.profile_display_p->profile_name, profile_name_p);
        mmi_ucs2cat((S8*) g_ph_cntx.profile_display_p->profile_name, temp_unicode);

        g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_UCS;
        mmi_ucs2ncpy(
            (S8*) (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name),
            (S8*) g_ph_cntx.profile_display_p->profile_name,
            NVRAM_WAP_PROFILE_PROFILE_NAME_LEN);

    }

    mmi_ucs2_to_asc((S8*) g_ph_cntx.ph_mms_profile_p->mmsc_url, (S8*) (g_ph_cntx.profile_display_p->homepage_url));
    mmi_ucs2_to_asc((S8*) (g_ph_cntx.ph_mms_profile_p->username), (S8*) (g_ph_cntx.profile_display_p->username));
    mmi_ucs2_to_asc((S8*) (g_ph_cntx.ph_mms_profile_p->password), (S8*) (g_ph_cntx.profile_display_p->password));

    g_ph_cntx.ph_mms_profile_p->empty = 0x00;   /* Added By Itishree */
    if (index == g_ph_cntx.mms_actived_profile_index)
    {
        memcpy(g_ph_cntx.ph_activated_mms_profile, g_ph_cntx.ph_mms_profile_p, NVRAM_EF_MMS_PROFILE_CONTENT_SIZE);
    #if defined(MMS_SUPPORT)        /* dilip */
        mmi_jmms_set_profile();
    #endif 

    }

    WriteRecord(
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        (U16) (index + 1),
        g_ph_cntx.ph_mms_profile_p,
        NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
        &error);
    WriteRecord(
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        1,
        g_ph_cntx.ph_mms_prof_name_arr_p,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        &error);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_nvram_activated_wap_profile
 * DESCRIPTION
 *  Updates the NVRAM browser activated profile content data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_nvram_activated_wap_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        (U16) (g_ph_cntx.wap_actived_profile_index + 1),
        g_ph_cntx.ph_activated_wap_profile,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        &error);
}

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


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_prov_nvram_wap_profile
 * DESCRIPTION
 *  Updates the NVRAM browser profile data(Both Name & Content) with the provisioning data for the index selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_prov_nvram_wap_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;
    U8 conn_type;
    U32 len = 0;
    PROV_RETCODE retcode = MMI_TRUE;

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    U8 temp_profile_name[PROV_PROFILE_PROFILE_NAME_LEN * ENCODING_LENGTH] = {0, };
    PROV_RETCODE result = MMI_TRUE;
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    U32 index = g_ph_cntx.profile_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_JATAAYU_CCA_SUPPORT__
    g_ph_cntx.ph_wap_profile_p->data_account = g_ph_cntx.profile_display_p->data_account;
#endif 

    WriteRecord(
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        (U16) (index + 1),
        g_ph_cntx.ph_wap_profile_p,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        &error);

    if (index == g_ph_cntx.wap_actived_profile_index)
    {
        memcpy(g_ph_cntx.ph_activated_wap_profile, g_ph_cntx.ph_wap_profile_p, NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }

    conn_type = g_ph_cntx.ph_wap_profile_p->conn_type;
    if (NULL == g_ph_cntx.ph_wap_prof_name_arr_p)
    {
        mmi_ph_get_brw_profile_name_list();
    }
    g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].conn_type = conn_type;

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    ASSERT(g_prov_profile_name_p);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) temp_profile_name,
        (PROV_PROFILE_PROFILE_NAME_LEN * ENCODING_LENGTH),
        (U8*) g_prov_profile_name_p);

    len = mmi_ucs2strlen((PS8) temp_profile_name);

    if (len > 0)
    {
        result = mmi_ph_set_brw_profile_name_list((U8*) temp_profile_name, index, len);
    }
#else /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    if (g_prov_profile_name_p != NULL)
    {
        len = strlen((PS8) g_prov_profile_name_p);
        if (len > 0)
        {
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_ASCII;
            if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
            {
                len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
            }

            memcpy(
                g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name,
                g_prov_profile_name_p,
                len);
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name[len] = '\0';
            jdd_MemFree(g_prov_profile_name_p);
            g_prov_profile_name_p = NULL;
        }
        else
        {
            retcode = mmi_ph_handle_empty_profile_name(PH_BROWSER_PROV_PROFILE, index);
        }
    }
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    else
    {
        retcode = mmi_ph_handle_empty_profile_name(PH_BROWSER_PROV_PROFILE, index);
    }

    WriteRecord(
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        1,
        g_ph_cntx.ph_wap_prof_name_arr_p,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_update_prov_nvram_mms_profile
 * DESCRIPTION
 *  Updates the NVRAM MMS profile data(Both Name & Content) with the provisioing data for the index selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_update_prov_nvram_mms_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U32 len = 0;
    PROV_RETCODE retcode = MMI_TRUE;

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    U8 temp_profile_name[PROV_PROFILE_PROFILE_NAME_LEN * ENCODING_LENGTH] = {0, };
    PROV_RETCODE result = MMI_TRUE;
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    U32 index = g_ph_cntx.profile_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_JATAAYU_CCA_SUPPORT__
    g_ph_cntx.ph_mms_profile_p->data_account = g_ph_cntx.profile_display_p->data_account;
#endif 
    WriteRecord(
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        (U16) (index + 1),
        g_ph_cntx.ph_mms_profile_p,
        NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
        &error);

    if (index == g_ph_cntx.mms_actived_profile_index)
    {
        memcpy(g_ph_cntx.ph_activated_mms_profile, g_ph_cntx.ph_mms_profile_p, NVRAM_EF_MMS_PROFILE_CONTENT_SIZE);
    #if defined(MMS_SUPPORT)        /* dilip */
        mmi_jmms_set_profile();
    #endif 
    }

#ifdef __MMI_JATAAYU_CCA_SUPPORT__
    ASSERT(g_prov_profile_name_p);
    if (NULL == g_ph_cntx.ph_mms_prof_name_arr_p)
    {
        mmi_ph_get_mms_profile_name_list();
    }
    mmi_chset_utf8_to_ucs2_string(
        (U8*) temp_profile_name,
        (PROV_PROFILE_PROFILE_NAME_LEN * ENCODING_LENGTH),
        (U8*) g_prov_profile_name_p);

    len = mmi_ucs2strlen((PS8) temp_profile_name);

    if (len > 0)
    {
        result = mmi_ph_set_mms_profile_name_list((U8*) temp_profile_name, index, len);
    }
#else /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    if (g_prov_profile_name_p != NULL)
    {
        len = strlen((PS8) g_prov_profile_name_p);
        if (len > 0)
        {
            g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_ASCII;
            if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
            {
                len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
            }
            memcpy(
                g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name,
                g_prov_profile_name_p,
                len);
            g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name[len] = '\0';
            jdd_MemFree(g_prov_profile_name_p);
            g_prov_profile_name_p = NULL;
        }
        else
        {
            retcode = mmi_ph_handle_empty_profile_name(PH_MMS_PROV_PROFILE, index);
        }
    }
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 
    else
    {
        retcode = mmi_ph_handle_empty_profile_name(PH_MMS_PROV_PROFILE, index);
    }

    WriteRecord(
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        1,
        g_ph_cntx.ph_mms_prof_name_arr_p,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_set_brw_profile_name_list
 * DESCRIPTION
 *  This API updates the browser profile name list
 * PARAMETERS
 *  profile_name        [IN]        Profile Name
 *  index               [IN]        Index of the profile
 *  len                 [IN]        Length of the profile name
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_ph_set_brw_profile_name_list(U8 *profile_name, U32 index, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUCS2Flag((S8*) profile_name))
    {
        g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_UCS;
        if (len >= (PROV_PROFILE_PROFILE_NAME_LEN / 2))
        {
            len = (PROV_PROFILE_PROFILE_NAME_LEN / 2) - 1;
        }
        mmi_ucs2ncpy(
            (S8*) g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name,
            (S8*) profile_name,
            len);
    }
    else
    {
        g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_ASCII;
        if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
        {
            len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
        }

        mmi_ucs2_n_to_asc(
            (S8*) g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name,
            (S8*) profile_name,
            len * ENCODING_LENGTH);
        g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name[len] = '\0';
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_set_mms_profile_name_list
 * DESCRIPTION
 *  This API updates MMS profile name list
 * PARAMETERS
 *  profile_name        [IN]        Profile Name
 *  index               [IN]        Index of the profile
 *  len                 [IN]        Length of the profile name
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_ph_set_mms_profile_name_list(U8 *profile_name, U32 index, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetUCS2Flag((S8*) profile_name))
    {
        g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_UCS;

        if (len >= (PROV_PROFILE_PROFILE_NAME_LEN / 2))
        {
            len = (PROV_PROFILE_PROFILE_NAME_LEN / 2) - 1;
        }
        mmi_ucs2ncpy(
            (S8*) g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name,
            (S8*) profile_name,
            len);
    }
    else
    {
        g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_ASCII;
        if (len >= PROV_PROFILE_PROFILE_NAME_LEN)
        {
            len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
        }

        mmi_ucs2_n_to_asc(
            (S8*) g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name,
            (S8*) profile_name,
            len * ENCODING_LENGTH);
        g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name[len] = '\0';
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_handle_empty_profile_name
 * DESCRIPTION
 *  This API handles empty profile name(Both Browser & MMS)
 * PARAMETERS
 *  profile     [IN]        Profile type(Browser,MMS)
 *  index       [IN]        Index of the profile
 * RETURNS
 *  PROV_RETCODE
 *****************************************************************************/
PROV_RETCODE mmi_ph_handle_empty_profile_name(ph_profile_enum profile, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 len;
    S8 temp_unicode[8] = {0, };
    S8 temp[4] = {0, };
    S8 *profile_name_p = NULL;
    S8 temp_name[PROV_PROFILE_PROFILE_NAME_LEN] = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_name_p = (S8*) GetString((MMI_ID_TYPE) STR_ID_PROF_HDLR_PROFILE);
    len = mmi_ucs2strlen((S8*) profile_name_p);
    len += 2;   /* For index */

    if (GetUCS2Flag((S8*) profile_name_p))
    {
        if (len >= (PROV_PROFILE_PROFILE_NAME_LEN / 2))
        {
            len = (PROV_PROFILE_PROFILE_NAME_LEN / 2) - 1;
        }
        sprintf(temp, "%d", (index + 1));
        mmi_asc_to_ucs2((S8*) temp_unicode, (S8*) temp);
        mmi_ucs2ncpy(temp_name, profile_name_p, (len - 2));
        mmi_ucs2cat((S8*) temp_name, (S8*) temp_unicode);
        if (profile == PH_BROWSER_PROV_PROFILE)
        {
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_UCS;
            memcpy(
                g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name,
                temp_name,
                (len + 1) * ENCODING_LENGTH);
        }
        else if (profile == PH_MMS_PROV_PROFILE)
        {
            g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_UCS;
            memcpy(
                g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name,
                temp_name,
                (len + 1) * ENCODING_LENGTH);
        }
    }
    else
    {
        if (len >= (PROV_PROFILE_PROFILE_NAME_LEN))
        {
            len = PROV_PROFILE_PROFILE_NAME_LEN - 1;
        }
        mmi_ucs2_n_to_asc((S8*) temp_name, (S8*) profile_name_p, (len - 2) * ENCODING_LENGTH);

        sprintf(temp, "%d", (index + 1));
        strcat(temp_name, temp);
        len = strlen(temp_name);
        if (profile == PH_BROWSER_PROV_PROFILE)
        {
            memcpy(
                g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name,
                temp_name,
                len + 1);
            g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs = PH_DCS_ASCII;
        }
        else if (profile == PH_MMS_PROV_PROFILE)
        {
            memcpy(
                g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name,
                temp_name,
                len + 1);
            g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs = PH_DCS_ASCII;
        }
    }
    return MMI_TRUE;

}

#ifdef __MMI_JATAAYU_CCA_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_brw_profile_data
 * DESCRIPTION
 *  Reads profile name & content(browser) from NVRAM
 * PARAMETERS
 *  profile_list        [IN]        
 *  index               [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_brw_profile_data(prov_wap_profile_list_struct *profile_list, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(profile_list);
    if (index >= 0 && index < NVRAM_WAP_PROFILE_MAX)
    {
        ReadRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            profile_list->profile_content,
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (index == PROV_ACTIVATED_PROF_ID)
    {
        ReadValue(NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX, &g_ph_cntx.wap_actived_profile_index, DS_BYTE, &error);
        index = g_ph_cntx.wap_actived_profile_index;
        ReadRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            profile_list->profile_content,
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }

    if (g_ph_cntx.ph_wap_prof_name_arr_p == NULL)
    {
        mmi_ph_get_brw_profile_name_list();
    }
    if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs == PH_DCS_ASCII)
    {
        strcpy(
            (S8*) profile_list->profile_name,
            (S8*) g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name);
        /* (NVRAM_WAP_PROFILE_NAME_LEN / 2) - 1); */
    }
    else if (g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].dcs == PH_DCS_UCS)
    {
        mmi_chset_ucs2_to_utf8_string(
            (U8*) profile_list->profile_name,
            NVRAM_WAP_PROFILE_NAME_LEN,
            (U8*) g_ph_cntx.ph_wap_prof_name_arr_p->nvram_wap_profile_name_array[index].profile_name);
    }
    if (g_ph_cntx.ph_wap_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_wap_prof_name_arr_p);
        g_ph_cntx.ph_wap_prof_name_arr_p = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_get_mms_profile_data
 * DESCRIPTION
 *  Reads profile name & content(MMS) from NVRAM
 * PARAMETERS
 *  profile_list        [IN]        
 *  index               [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_get_mms_profile_data(prov_mms_profile_list_struct *profile_list, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(profile_list);
    if (index >= 0 && index < NVRAM_MMS_PROFILE_MAX)
    {
        ReadRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            profile_list->profile_content,
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (index == PROV_ACTIVATED_PROF_ID)
    {
        ReadValue(NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX, &g_ph_cntx.mms_actived_profile_index, DS_BYTE, &error);
        index = g_ph_cntx.mms_actived_profile_index;
        ReadRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            profile_list->profile_content,
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }
    if (g_ph_cntx.ph_mms_prof_name_arr_p == NULL)
    {
        mmi_ph_get_mms_profile_name_list();
    }

    if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs == PH_DCS_ASCII)
    {
        strcpy(
            (S8*) profile_list->profile_name,
            (S8*) g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name);
        /* (NVRAM_WAP_PROFILE_NAME_LEN - 1)); */
    }
    else if (g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].dcs == PH_DCS_UCS)
    {
        mmi_chset_ucs2_to_utf8_string(
            (U8*) profile_list->profile_name,
            NVRAM_WAP_PROFILE_NAME_LEN,
            (U8*) g_ph_cntx.ph_mms_prof_name_arr_p->nvram_mms_profile_name_array[index].profile_name);
    }

    if (g_ph_cntx.ph_mms_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_mms_prof_name_arr_p);
        g_ph_cntx.ph_mms_prof_name_arr_p = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_set_brw_profile_data
 * DESCRIPTION
 *  Saves profile name & content(Browser) into NVRAM
 * PARAMETERS
 *  profile_list        [IN]        
 *  index               [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_set_brw_profile_data(prov_wap_profile_list_struct *profile_list, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(profile_list);
    if (index >= 0 && index < NVRAM_WAP_PROFILE_MAX)
    {
        g_ph_cntx.profile_index = index;
    }
    else if (index == PROV_ACTIVATED_PROF_ID)
    {
        ReadValue(NVRAM_PH_ACTIVATED_WAP_PROFILE_INDEX, &g_ph_cntx.wap_actived_profile_index, DS_BYTE, &error);
        g_ph_cntx.profile_index = g_ph_cntx.wap_actived_profile_index;
    }
    g_prov_profile_name_p = (PU8) profile_list->profile_name;
    g_ph_cntx.ph_wap_profile_p = profile_list->profile_content;

    mmi_ph_update_prov_nvram_wap_profile();
    g_ph_cntx.profile_module = PH_BROWSER_PROV_PROFILE;
    if (index != PROV_ACTIVATED_PROF_ID)
    {
        mmi_ph_activate_selected_profile();
    }
    if (g_ph_cntx.ph_wap_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_wap_prof_name_arr_p);
        g_ph_cntx.ph_wap_prof_name_arr_p = NULL;
    }
    g_prov_profile_name_p = NULL;
    g_ph_cntx.ph_wap_profile_p = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ph_set_mms_profile_data
 * DESCRIPTION
 *  Saves profile name & content(MMS) into NVRAM
 * PARAMETERS
 *  profile_list        [IN]        
 *  index               [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ph_set_mms_profile_data(prov_mms_profile_list_struct *profile_list, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(profile_list);
    if (index >= 0 && index < NVRAM_MMS_PROFILE_MAX)
    {
        g_ph_cntx.profile_index = index;
    }
    else if (index == PROV_ACTIVATED_PROF_ID)
    {
        ReadValue(NVRAM_PH_ACTIVATED_MMS_PROFILE_INDEX, &g_ph_cntx.mms_actived_profile_index, DS_BYTE, &error);
        g_ph_cntx.profile_index = g_ph_cntx.mms_actived_profile_index;
    }
    g_prov_profile_name_p = (PU8) profile_list->profile_name;
    g_ph_cntx.ph_mms_profile_p = profile_list->profile_content;

    mmi_ph_update_prov_nvram_mms_profile();
    g_ph_cntx.profile_module = PH_MMS_PROV_PROFILE;
    if (
#if defined MMS_SUPPORT
           !mmi_jmms_is_mms_profile_in_use() &&
#endif 
           (index != PROV_ACTIVATED_PROF_ID))
    {
        mmi_ph_activate_selected_profile();
    }
    if (g_ph_cntx.ph_mms_prof_name_arr_p != NULL)
    {
        jdd_MemFree(g_ph_cntx.ph_mms_prof_name_arr_p);
        g_ph_cntx.ph_mms_prof_name_arr_p = NULL;
    }
    g_prov_profile_name_p = NULL;
    g_ph_cntx.ph_mms_profile_p = NULL;

}
#endif /* __MMI_JATAAYU_CCA_SUPPORT__ */ 

#endif /* defined (JATAAYU_SUPPORT) && (defined (WAP_SUPPORT) || (defined (MMS_SUPPORT))) */ 
#endif /* _JPROFILESTORAGEHANDLER_C */ 

