#define __NEWSIMULATOR

#include "MMI_include.h"

#include "Ucs2prot.h"

#include "wgui_inline_edit.h"

#include "ServiceDefs.h"
#include "CommonScreens.h"
#include "ProfileHandlerTypes.h"
#include "ProfileHandlerProts.h"
#include "ProfileHandlerResDef.h"

#include "custom_nvram_editor_data_item.h"


#undef __NEWSIMULATOR

#ifdef __MMI_BROWSER_2__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_brw_profile_name_list
 * DESCRIPTION
 *  This reads the browser profile name list from the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_get_brw_profile_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error, size;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 10; i++)
    {
        g_prof_cntx.content_index_array[i] = 0;
    }
    if (g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE] == NULL)
    {
        g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE] =
            (nvram_profile_name_array_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_NAMES_SIZE);
    }
    size = sizeof(nvram_profile_name_array_struct);

    ReadRecord(NVRAM_EF_WAP_PROFILE_NAMES_LID, 1, g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE], size, &error);
    /* mmi_ucs2cpy((S8*)g_prof_name_arr_p->nvram_profile_name_array[0].profile_name,(S8*)"FET"); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_mms_profile_name_list
 * DESCRIPTION
 *  This reads the browser profile name list from the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_get_mms_profile_name_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NVRAM_PROFILE_MAX; i++)
    {
        g_prof_cntx.content_index_array[i] = 0;
    }
    if (g_prof_name_arr_p[BRW_PROF_MMS_PROFILE] == NULL)
    {
        g_prof_name_arr_p[BRW_PROF_MMS_PROFILE] =
            (nvram_profile_name_array_struct*) OslMalloc(NVRAM_EF_MMS_PROFILE_NAMES_SIZE);
    }
    ReadRecord(
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        1,
        g_prof_name_arr_p[BRW_PROF_MMS_PROFILE],
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        &error);
    /* mmi_ucs2cpy((S8*)g_prof_name_arr_p->nvram_profile_name_array[0].profile_name,(S8*)"FET"); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_update_nvram_profile
 * DESCRIPTION
 *  This API updates the NVRAM data for the browser profile (both Name & Content)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_update_nvram_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error, size;

    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_update_profile_index();
    if (mmi_ucs2strlen((S8*) g_prof_cntx.profile_display_p->profile_name))
    {
        if (GetUCS2Flag((S8*) g_prof_cntx.profile_display_p->profile_name))
        {
            g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs = BRW_PROF_DCS_UCS;
            mmi_ucs2ncpy(
                (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name),
                (S8*) g_prof_cntx.profile_display_p->profile_name,
                NVRAM_PROFILE_NAME_LEN);
        }
        else
        {
            g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs = BRW_PROF_DCS_ASCII;
            mmi_ucs2_to_asc(
                (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name),
                (S8*) g_prof_cntx.profile_display_p->profile_name);
        }
    }
    else
    {
        S8 temp_unicode[8];
        S8 temp[4];
        S8 *profile_name_p;

        profile_name_p = (S8*) get_string((MMI_ID_TYPE) STR_ID_PROF_HDLR_PROFILE);
        gui_itoa((S32) (index + 1), (U16*) temp, 10);
        mmi_asc_to_ucs2((S8*) temp_unicode, (S8*) temp);
        mmi_ucs2cpy((S8*) g_prof_cntx.profile_display_p->profile_name, profile_name_p);
        mmi_ucs2cat((S8*) g_prof_cntx.profile_display_p->profile_name, temp_unicode);

        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].dcs = BRW_PROF_DCS_UCS;
        mmi_ucs2ncpy(
            (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].profile_name),
            (S8*) g_prof_cntx.profile_display_p->profile_name,
            NVRAM_PROFILE_NAME_LEN);
    }

    mmi_ucs2_to_asc(
        (S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->url,
        (S8*) (g_prof_cntx.profile_display_p->url));
    mmi_ucs2_to_asc(
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->username),
        (S8*) (g_prof_cntx.profile_display_p->username));
    mmi_ucs2_to_asc(
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->password),
        (S8*) (g_prof_cntx.profile_display_p->password));

    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        size = sizeof(nvram_profile_content_struct);
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].content_index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            size,
            &error);
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[g_prof_cntx.profile_module],
            NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
            &error);
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        size = sizeof(nvram_profile_content_struct);
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[index].content_index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            size,
            &error);
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[g_prof_cntx.profile_module],
            NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
            &error);
    }
    if (g_prof_cntx.prov_flag == BRW_NO_PROVISIONING
		 && g_prof_cntx.active_profile_modified == FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteNHistory(1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_nvram_add_new_profile
 * DESCRIPTION
 *  This API updates the NVRAM data for the browser profile (both Name & Content)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_nvram_add_new_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error, size;

    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_brw_prof_update_profile_index();
    if (mmi_ucs2strlen((S8*) g_prof_cntx.profile_display_p->profile_name))
    {
        if (GetUCS2Flag((S8*) g_prof_cntx.profile_display_p->profile_name))
        {
            g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].dcs =
                BRW_PROF_DCS_UCS;

            mmi_ucs2ncpy(
                (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].profile_name),
                (S8*) g_prof_cntx.profile_display_p->profile_name,
                NVRAM_PROFILE_NAME_LEN);
        }
        else
        {
            g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].dcs =
                BRW_PROF_DCS_ASCII;

            mmi_ucs2_to_asc(
                (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].profile_name),
                (S8*) g_prof_cntx.profile_display_p->profile_name);
        }
    }
    else
    {
        S8 temp_unicode[8];
        S8 temp[4];
        S8 *profile_name_p;

        profile_name_p = (S8*) get_string((MMI_ID_TYPE) STR_ID_PROF_HDLR_PROFILE);
        gui_itoa((S32) (index + 1), (U16*) temp, 10);
        mmi_asc_to_ucs2((S8*) temp_unicode, (S8*) temp);
        mmi_ucs2cpy((S8*) g_prof_cntx.profile_display_p->profile_name, profile_name_p);
        mmi_ucs2cat((S8*) g_prof_cntx.profile_display_p->profile_name, temp_unicode);

        g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].dcs =
            BRW_PROF_DCS_UCS;

        mmi_ucs2ncpy(
            (S8*) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].profile_name),
            (S8*) g_prof_cntx.profile_display_p->profile_name,
            NVRAM_PROFILE_NAME_LEN);
    }

    g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].
        permission_bits = BRW_PROF_READ_WRITE;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->editable = BRW_PROF_READ_WRITE;

    mmi_ucs2_to_asc(
        (S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->url,
        (S8*) (g_prof_cntx.profile_display_p->url));
    mmi_ucs2_to_asc(
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->username),
        (S8*) (g_prof_cntx.profile_display_p->username));
    mmi_ucs2_to_asc(
        (S8*) (g_prof_profile_content_p[g_prof_cntx.profile_module]->password),
        (S8*) (g_prof_cntx.profile_display_p->password));

    /* if (index == g_prof_cntx.wap_actived_profile_index)
       {
       memcpy(g_prof_activated_profile_content, g_prof_profile_content_p, NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
       } */
    size = sizeof(nvram_profile_name_array_struct);
    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].content_index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);

        WriteRecord(
            NVRAM_EF_WAP_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[g_prof_cntx.profile_module],
            NVRAM_EF_WAP_PROFILE_NAMES_SIZE /* size */ ,
            &error);

    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        size = sizeof(nvram_profile_name_array_struct);
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (g_prof_name_arr_p[g_prof_cntx.profile_module]->nvram_profile_name_array[g_prof_cntx.profile_count1].content_index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);

        WriteRecord(
            NVRAM_EF_MMS_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[g_prof_cntx.profile_module],
            NVRAM_EF_MMS_PROFILE_NAMES_SIZE /* size */ ,
            &error);
    }
    /* g_prof_name_arr_p->nvram_profile_name_array[g_prof_cntx.profile_count1].content_index=
       g_prof_name_arr_p->nvram_profile_name_array[index].content_index; */
    if (g_prof_cntx.prov_flag == BRW_NO_PROVISIONING)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteNHistory(1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_activated_profile_data
 * DESCRIPTION
 *  This gets the activated profile content data from the NVRAM into the global context of the activated profile
 * PARAMETERS
 *  profile     [IN]        Profile type(Browser,MMS.....)
 *  index       [IN]        Activated profile index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_get_activated_profile_data(prof_profile_enum profile, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile == BRW_PROF_BROWSER_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_prof_activated_profile_content[profile],
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (profile == BRW_PROF_MMS_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_prof_activated_profile_content[profile],
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_get_profile_nvram_content_data
 * DESCRIPTION
 *  This reads the content data for the given profile index from the NVRAM
 * PARAMETERS
 *  index       [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_get_profile_nvram_content_data(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        ReadRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_prof_get_content
 * DESCRIPTION

 * PARAMETERS
 *         
 * RETURNS
 *  nvram_profile_content_struct
 *****************************************************************************/
nvram_profile_content_struct * mmi_prof_get_content(prof_profile_enum profile_type,U16 index)
{
	nvram_profile_content_struct *profile_content = NULL;
	S16 error;
	

	if (profile_type == BRW_PROF_BROWSER_PROFILE)
    {
        profile_content = (nvram_profile_content_struct *)OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
		if (profile_content != NULL)
		{
			ReadRecord(
				NVRAM_EF_WAP_PROFILE_CONTENT_LID,
				(U16) (index + 1),
				profile_content,
				NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
				&error);
		}
    }
    else if (profile_type == BRW_PROF_MMS_PROFILE)
    {
        profile_content = (nvram_profile_content_struct *)OslMalloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE);
		if (profile_content != NULL)
		{
			ReadRecord(
				NVRAM_EF_MMS_PROFILE_CONTENT_LID,
				(U16) (index + 1),
				profile_content,
				NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
				&error);
		}
    }    
	
	return profile_content;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_prov_dm_create_default_profile
 * DESCRIPTION

 * PARAMETERS
 *         
 * RETURNS
 *  nvram_profile_content_struct
 *****************************************************************************/
nvram_profile_content_struct * mmi_prov_dm_create_default_profile(prof_profile_enum profile_type)
{
	nvram_profile_content_struct *profile_content = NULL;

	if (profile_type == BRW_PROF_BROWSER_PROFILE)
    {
        profile_content = (nvram_profile_content_struct *)OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
		if (profile_content != NULL)
		{
			memset((void *)profile_content,'\0',NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);			
		}
    }
    else if (profile_type == BRW_PROF_MMS_PROFILE)
    {
        profile_content = (nvram_profile_content_struct *)OslMalloc(NVRAM_EF_MMS_PROFILE_CONTENT_SIZE);
		if (profile_content != NULL)
		{
			memset((void *)profile_content,'\0',NVRAM_EF_MMS_PROFILE_CONTENT_SIZE);
		}
    }    
	if (profile_content != NULL)
	{
		profile_content->proxy_port = MMI_DM_PROF_DEFAULT_PORTNBR;
		profile_content->conn_type =  MMI_DM_PROF_DEFAULT_CONN_TYPE;
		profile_content->data_account_primary_id = MMI_DM_PROF_DEFAULT_PRIMARY_ID;
		profile_content->data_account_secondary_id = MMI_DM_PROF_DEFAULT_SECONDARY_ID;
		strncpy((S8*)profile_content->url,BRW_PROF_DEFAULT_URL_NAME,BRW_PROF_DEFAULT_URL_SIZE);
	}

	return profile_content;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_dm_prov_update_profile
 * DESCRIPTION

 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_dm_prov_update_profile (nvram_profile_content_struct *profile_content, S32 index, prof_profile_enum profile_type)
{
	S16 size,error;
	
	size = sizeof(nvram_profile_content_struct);

	if (profile_type == BRW_PROF_BROWSER_PROFILE)
    {
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].content_index + 1),
            profile_content,
            size,
            &error);
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[profile_type],
            NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
            &error);
    }
    else if (profile_type == BRW_PROF_MMS_PROFILE)
    {
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (g_prof_name_arr_p[profile_type]->nvram_profile_name_array[index].content_index + 1),
            profile_content,
            size,
            &error);
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_NAMES_LID,
            1,
            g_prof_name_arr_p[profile_type],
            NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
            &error);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_reset_profile_content
 * DESCRIPTION
 *  This reads the content data for the given profile index from the NVRAM
 * PARAMETERS
 *  index       [IN]        Index of the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_reset_profile_content(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_profile_content_p[g_prof_cntx.profile_module] == NULL)
    {
        g_prof_profile_content_p[g_prof_cntx.profile_module] =
            (nvram_profile_content_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_CONTENT_SIZE);
    }
    g_prof_profile_content_p[g_prof_cntx.profile_module]->editable = 0;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->empty = 0;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_port = 0;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_primary_id = 0;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->data_account_secondary_id = 0;
    g_prof_profile_content_p[g_prof_cntx.profile_module]->conn_type = 0;
    mmi_asc_to_ucs2((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->url, "\0");
    mmi_asc_to_ucs2((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->username, "\0");
    mmi_asc_to_ucs2((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->password, "\0");
    mmi_asc_to_ucs2((S8*) g_prof_profile_content_p[g_prof_cntx.profile_module]->proxy_ip, "0000");

    if (g_prof_cntx.profile_module == BRW_PROF_BROWSER_PROFILE)
    {
        WriteRecord(
            NVRAM_EF_WAP_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
            &error);
    }
    else if (g_prof_cntx.profile_module == BRW_PROF_MMS_PROFILE)
    {
        WriteRecord(
            NVRAM_EF_MMS_PROFILE_CONTENT_LID,
            (U16) (index + 1),
            g_prof_profile_content_p[g_prof_cntx.profile_module],
            NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
            &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_set_wap_default_profile_list
 * DESCRIPTION
 *  This reads the browser profile name list from the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_set_wap_default_profile_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE] == NULL)
    {
        g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE] =
            (nvram_profile_name_array_struct*) OslMalloc(NVRAM_EF_WAP_PROFILE_NAMES_SIZE);
    }
    size = sizeof(nvram_profile_name_array_struct);

    g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE] = 0x00;

    WriteValue(
        NVRAM_BRW_ACTIVATED_WAP_PROFILE_INDEX,
        &g_prof_cntx.actived_profile_content_index[BRW_PROF_BROWSER_PROFILE],
        DS_BYTE,
        &error);
    ReadRecord(NVRAM_EF_WAP_PROFILE_NAMES_LID, 1, g_prof_name_arr_p[BRW_PROF_BROWSER_PROFILE], size, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_prof_set_mms_default_profile_list
 * DESCRIPTION
 *  This reads the browser profile name list from the NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_prof_set_mms_default_profile_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prof_name_arr_p[BRW_PROF_MMS_PROFILE] == NULL)
    {
        g_prof_name_arr_p[BRW_PROF_MMS_PROFILE] =
            (nvram_profile_name_array_struct*) OslMalloc(NVRAM_EF_MMS_PROFILE_NAMES_SIZE);
    }
    size = sizeof(nvram_profile_name_array_struct);

    g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE] = 0x00;

    WriteValue(
        NVRAM_BRW_ACTIVATED_MMS_PROFILE_INDEX,
        &g_prof_cntx.actived_profile_content_index[BRW_PROF_MMS_PROFILE],
        DS_BYTE,
        &error);
    ReadRecord(NVRAM_EF_MMS_PROFILE_NAMES_LID, 1, g_prof_name_arr_p[BRW_PROF_MMS_PROFILE], size, &error);
}

#endif /* __MMI_BROWSER_2__ */ 

