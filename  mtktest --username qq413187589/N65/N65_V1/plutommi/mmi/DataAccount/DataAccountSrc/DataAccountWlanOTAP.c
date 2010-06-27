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
 *  DataAccountWlanOTAP.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  The file implements the functionality for Over-The-Air Provisioning (OTAP)
 *  of WLAN data account. The WLAN OTAP feature is enabled when the MMI WLAN 
 *  data account application is enabled and one of the specification support
 *  is turned on by CCA.
 *  
 *  Currently, two OTAP specifications is implemented in the file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "DataAccountCommon.h"

/* 
 * Turn on WLAN OTAP when at least one of OTAP specifications is supported.
 */
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

/* Std C headers. */
#include "limits.h"

/* CCA message ID. */
#include "ProtocolEvents.h"

/* MMI trace. */

/* Conversion between different Unicode encodings. */
#include "Conversions.h"

/* Default profile's name. */
#define DEFAULT_PROFILE_NAME    (L"New Profile")

/* Constants for auto renaming. */
#define DUP_NAME_SUFFIX_PATTERN (L"(00)")   /* Appended pattern         */
#define DUP_NAME_SUFFIX_LEN     (4)         /* Length of pattern        */
#define DUP_NAME_SUFFIX_NUM     (100)       /* Num of values in pattern */

/* WLAN data account control block. */
extern mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
extern mmi_wlan_display_struct g_wlan_display_context;
extern mmi_wlan_setting_struct g_wlan_setting_context;

/* Since the application has the property that it is only triggered when a
   configuration document is arrived, we dynamically allocate the control 
   block to save memory. */
static mmi_wlan_otap_struct *g_wlan_otap = NULL;


/*
 * Private function prototypes.
 */
static S32 mmi_wlan_hex_to_dec(U8 input);
static MMI_BOOL mmi_wlan_hex_to_psk(U8 *dst, const U8 *src, S32 len);
static MMI_BOOL mmi_wlan_is_ascii_string(const U8 *utf8_str);
static MMI_BOOL mmi_wlan_is_appended_pattern(const U8 *name, U8 *value);
static void mmi_wlan_update_appended_pattern(U8 *dup_name, const U8 **name, U8 num_names);
static void mmi_wlan_resolve_duplicate_name(U8 *dup_name, const U8 **name, U8 num_names);
static void mmi_wlan_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status);
static mmi_wlan_otap_struct *mmi_wlan_new_otap_cntx(U16 conf_id, S32 doc_hdl);
static void mmi_wlan_free_otap_cntx(void);
static U8 mmi_wlan_abort_otap_app(void *dummy);
static void mmi_wlan_init_slim_profile(mmi_wlan_slim_profile_struct *prof);
static S16 mmi_wlan_new_otap_profile(mmi_wlan_otap_struct *cntx);
static void mmi_wlan_free_otap_profile(mmi_wlan_otap_struct *cntx, S16 index);
static MMI_BOOL mmi_wlan_validate_wep_key(const mmi_wlan_slim_profile_struct * prof);
static MMI_BOOL mmi_wlan_validate_profile(const mmi_wlan_slim_profile_struct *prof);
static void mmi_wlan_show_info(U16 msg_id);
static void mmi_wlan_provision_profile(mmi_wlan_profile_struct *dst, const mmi_wlan_slim_profile_struct *src);
static U8 mmi_wlan_install_profiles(void);
static void mmi_wlan_auto_rename_profile(S16 src_idx);
static MMI_BOOL mmi_wlan_is_duplicate_name(S16 src_idx);
static void mmi_wlan_replacement_save(void);
static void mmi_wlan_entry_replacement_confirm(void);
static void mmi_wlan_replacement_highlight_hdlr(S32 index);
static void mmi_wlan_entry_replacement(void);
static MMI_BOOL mmi_wlan_is_empty_profile(U8 i);
static void mmi_wlan_next_profile(void);
static void mmi_wlan_find_empty_profile(void);
static void mmi_wlan_entry_installation(void);


U8 g_wlan_otap_replace;
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_hex_to_dec
 * DESCRIPTION
 *  This function converts a hexadecimal character to its decimal value.
 * PARAMETERS
 *  input           [IN]            Input hexadecimal character
 * RETURNS
 *  If input is a hexadecimal character, return its decimal value. Otherwise,
 *  return -1.
 *****************************************************************************/
S32 mmi_wlan_hex_to_dec(U8 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input >= '0' && input <= '9') 
    {
        return input - '0';
    } 
    else if (input >= 'a' && input <= 'f')
    {
        return input - 'a' + 10;    
    }
    else if (input >= 'A' && input <= 'F')
    {
        return input - 'A' + 10;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_hex_to_psk
 * DESCRIPTION
 *  This function converts a hexadecimal character string to the pre-shared
 *  key, where each hexadecimal character represents 4-bits in the destination.
 * PARAMETERS
 *  dst             [OUT]           Output raw data
 *  src             [IN]            Input hexadecimal character string
 *  len             [IN]            Length of the string
 * RETURNS
 *  On success, return TRUE. On error, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_hex_to_psk(U8 *dst, const U8 *src, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msb, lsb;
    S32 ret;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (len % 2 != 0) 
    {
        return MMI_FALSE;
    }
    
    for (i = 0; i < len; i += 2)
    {
        if ((ret = mmi_wlan_hex_to_dec(src[i])) < 0) 
        {
            return MMI_FALSE;
        }
        msb= (U8)ret;

        if ((ret = mmi_wlan_hex_to_dec(src[i + 1])) < 0) 
        {
            return MMI_FALSE;
        }
        lsb = (U8)ret;
        
        dst[i / 2] = (msb << 4) + lsb;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_is_ascii_string
 * DESCRIPTION
 *  This function checks whether the input UTF-8 encoded string is an ASCII
 *  string.
 * PARAMETERS
 *  utf8_str        [IN]            Input UTF-8 encoded string
 * RETURNS
 *  If input string is ASCII string, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_is_ascii_string(const U8 *utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If this is an ASCII string, each octet should be an ASCII character. */
    for ( ; *utf8_str != '\0'; ++utf8_str)
    {
        if (*utf8_str > 0x7F) 
        {
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_is_appended_pattern
 * DESCRIPTION
 *  This function examines whether the name has an appended pattern (\d\d).
 *  If the name has the pattern and value is not NULL, set value to \d\d.
 * PARAMETERS
 *  name            [IN]            Name to be examined
 *  value           [OUT]           Return the value of \d\d
 * RETURNS
 *  If name has an appended pattern, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_is_appended_pattern(const U8 *name, U8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U8 *start, *end, *iter;
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_len = mmi_ucs2strlen((S8 *)name);

    /* Examine whether the name has the appended pattern. */
    if (str_len < DUP_NAME_SUFFIX_LEN) 
    {
        return MMI_FALSE;
    } 
    else 
    {
        start = name + (str_len - DUP_NAME_SUFFIX_LEN) * ENCODING_LENGTH;
        end   = name + (str_len - 1) * ENCODING_LENGTH;

        if (*start != '(' || *(start + 1) != '\0') 
        {
            return MMI_FALSE;
        }

        if (*end != ')' || *(end + 1) != '\0') 
        {
            return MMI_FALSE;
        }

        for (iter = start + ENCODING_LENGTH; iter != end; iter += ENCODING_LENGTH) 
        {
            if (*iter < '0' || *iter > '9' || *(iter + 1) != '\0') 
            {
                return MMI_FALSE;
            }
        }
    }

    /* Save the value in the pattern. */
    if (value != NULL) 
    {
        start = name + (str_len - 3) * ENCODING_LENGTH; /* decimal  */
        end   = name + (str_len - 2) * ENCODING_LENGTH; /* unit     */
        *value = (*start - '0') * 10 + (*end - '0');
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_appended_pattern
 * DESCRIPTION
 *  The function updates the values of the pattern (\d\d) in the duplicate 
 *  name.
 * PARAMETERS
 *  dup_name        [IN/OUT]        The name to be updated
 *  name            [IN]            The other names
 *  num_names       [IN]            Number of the other names
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_appended_pattern(U8 *dup_name, const U8 **name, U8 num_names)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 map[DUP_NAME_SUFFIX_NUM];
    U8 value, min;
    S32 str_len;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialize the map. All numbers are not used. */
    memset(map, 0, DUP_NAME_SUFFIX_NUM);

    str_len = mmi_ucs2strlen((S8 *)dup_name);

    /* Mark used values as one. */ 
    for (i = 0; i < num_names; ++i)
    {
        /* String length must be identical. */
        if (str_len != mmi_ucs2strlen((S8 *)name[i])) 
        {
            continue;
        }
        
        /* Prefix of names must be the same as the prefix of duplicate name. */
        if (mmi_ucs2ncmp((S8 *)dup_name, (S8 *)name[i], str_len - DUP_NAME_SUFFIX_LEN) != 0) 
        {
            continue;
        }
        
        if (mmi_wlan_is_appended_pattern(name[i], &value) == MMI_TRUE) 
        {
            map[value] = 1;
        }
    }

    /* Find the minimum unused position. If all values are used, still produce
       a pattern with a duplicate value 99. */
    min = DUP_NAME_SUFFIX_NUM - 1;
    
    for (i = 1; i < DUP_NAME_SUFFIX_NUM; ++i) 
    {
        if (map[i] == 0) 
        {
            min = i;
            break;
        }
    }

    /* Update the value in the pattern. */
    *(dup_name + (str_len - 2) * ENCODING_LENGTH) = (min % 10) + '0';
    *(dup_name + (str_len - 3) * ENCODING_LENGTH) = (min / 10) + '0';
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_resolve_duplicate_name
 * DESCRIPTION
 *  This function updates the duplicate name according to the circumstance of
 *  the name array.
 * PARAMETERS
 *  dup_name        [IN/OUT]        The duplicate name to be updated
 *  name            [IN]            The other names
 *  num_names       [IN]            Number of the other names
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_resolve_duplicate_name(U8 *dup_name, const U8 **name, U8 num_names)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U8 *ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If tail does not have an appended pattern (\d\d), append a pattern. */
    if (mmi_wlan_is_appended_pattern(dup_name, NULL) == MMI_FALSE) 
    {
        str_len = mmi_ucs2strlen((S8 *)dup_name);

        /* Whether spaces are enough for appending the pattern (\d\d). */
        if (str_len + DUP_NAME_SUFFIX_LEN + 1 > MAX_WLAN_PROF_NAME_LEN) 
        {
            /* Spaces are not enough. Truncate the tail. */
            ptr = dup_name + (MAX_WLAN_PROF_NAME_LEN - 1 - DUP_NAME_SUFFIX_LEN) * ENCODING_LENGTH;
            *(ptr)     = '\0';
            *(ptr + 1) = '\0';
        }
        
        mmi_ucs2cat((S8 *)dup_name, (S8 *)DUP_NAME_SUFFIX_PATTERN);
    }

    /* Update the values in the pattern. */
    mmi_wlan_update_appended_pattern(dup_name, name, num_names);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_send_cca_app_configure_rsp
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of 
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  status          [IN]            Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_CCA_WLAN_SEND_RSP, status);

    /* Allocate memory. It will assert on error. */
    data = (mmi_cca_app_configure_rsp_struct *)OslConstructDataPtr(sizeof(mmi_cca_app_configure_rsp_struct));

    data->config_id = conf_id;
    data->hConfig   = doc_hdl;
    data->status    = status;

    /* Send the response message. */
    message.oslSrcId        = MOD_MMI;
    message.oslDestId       = MOD_MMI;
    message.oslMsgId        = PRT_MMI_CCA_APP_CONFIGURE_RSP;
    message.oslDataPtr      = (oslParaType *)data;
    message.oslPeerBuffPtr  = NULL;
    
    OslMsgSendExtQueue(&message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_new_otap_cntx
 * DESCRIPTION
 *  This function allocates and initializes the control block of WLAN OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
mmi_wlan_otap_struct *mmi_wlan_new_otap_cntx(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wlan_otap_struct *cntx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    cntx = (mmi_wlan_otap_struct *)OslMalloc(sizeof(mmi_wlan_otap_struct));
    if (cntx == NULL) 
    {
        return NULL;
    }

    /* Clear the entire structure. */
    memset(cntx, 0, sizeof(mmi_wlan_otap_struct));

    /* Save the identifier for this configuration process. */
    cntx->conf_id = conf_id;
    cntx->doc_hdl = doc_hdl;

    /* Allow to process nodes and parameters until a NAPDEF node comes. */
    cntx->is_active = MMI_FALSE;

    /* Initialize the index for replacement to an invalid index. */
    for (i = 0; i < MAX_WLAN_OTA_PROF_NUM; ++i) 
    {
        cntx->dst_idx[i] = -1;
    }

    /* Initialize the index for replacement to an invalid index. */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; ++i)
    {
        cntx->src_idx[i]     = -1;
        cntx->sel_dst_idx[i] = -1;
    }
    
    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_free_otap_cntx
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_free_otap_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Nothing to do. Return. */
    if (g_wlan_otap == NULL) 
    {
        return;
    }
    
    /* Free all profiles. */
    for (i = 0; i < g_wlan_otap->num_profiles; ++i) 
    {
        OslMfree(g_wlan_otap->profile[i]);
    }

    /* Free the control block. */
    OslMfree(g_wlan_otap);
    g_wlan_otap = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_abort_otap_app
 * DESCRIPTION
 *  This function should be called to exit the WLAN OTAP application. It is 
 *  registered as a delete screen callback such that it can be called when END
 *  key is pressed to return to idle screen.
 * PARAMETERS
 *  dummy           [IN]            Dummy parameter. Always be zero.
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop 
 *  delete other nodes in history stack. Here, always return FALSE.
 *****************************************************************************/
U8 mmi_wlan_abort_otap_app(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Terminated. Send a response back to CCA and free memory. */    
    mmi_wlan_send_cca_app_configure_rsp(g_wlan_otap->conf_id, g_wlan_otap->doc_hdl, CCA_STATUS_ENDKEY_PRESSED);
    mmi_wlan_free_otap_cntx();
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_init_slim_profile
 * DESCRIPTION
 *  This function initializes a slim WLAN profile.
 * PARAMETERS
 *  prof            [OUT]           Profile to be initialized
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_init_slim_profile(mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(prof, 0, sizeof(mmi_wlan_slim_profile_struct));

    mmi_ucs2cpy((S8 *)prof->name, (S8 *)DEFAULT_PROFILE_NAME);
    
    prof->network_type   = WLAN_NETWORK_TYPE_INFRA;
    prof->encrypt_mode   = WLAN_ENCRYPT_MODE_NONE;
    prof->auth_mode      = WLAN_AUTH_MODE_OPEN;
    
    prof->wep_key_index  = MAX_WEP_KEY_NUM;             /* Invalid index    */
    prof->wep_key_len    = WLAN_WEP_KEY_ENCRYPT_TOTAL;  /* Invalid key len  */
    prof->wep_key_format = WLAN_WEP_KEY_FORMAT_ASCII;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_new_otap_profile
 * DESCRIPTION
 *  This function allocates a temporary storage for WLAN profile. And it will 
 *  turn on the flag such that we can process subsequent nodes/parameters
 *  again.
 * PARAMETERS
 *  cntx            [IN]            control block for WLAN OTA provisioning
 * RETURNS
 *  On success, return the index of the newly allocated profile. Otherwise, 
 *  return -1, i.e., an invalid index.
 *****************************************************************************/
S16 mmi_wlan_new_otap_profile(mmi_wlan_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* No more temporary profile storage. */
    if (cntx->num_profiles == MAX_WLAN_OTA_PROF_NUM) 
    {
        return -1;
    }
    
    /* Obtain the index. */
    index = cntx->num_profiles;
    
    /* Allocate memory for the profile. */
    cntx->profile[index] = (mmi_wlan_slim_profile_struct *)OslMalloc(sizeof(mmi_wlan_slim_profile_struct));
    if (cntx->profile[index] == NULL) 
    {
        return -1;
    }

    /* Initialize the allocated slim WLAN profile. */
    mmi_wlan_init_slim_profile(cntx->profile[index]);

    /* Now, we can update the number of profiles. */
    ++cntx->num_profiles;

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_free_otap_profile
 * DESCRIPTION
 *  This function frees the specified profile in the control block.
 * PARAMETERS
 *  cntx            [IN]            Control block of WLAN OTA provisioning
 *  index           [IN]            Index of the profile to be freed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_free_otap_profile(mmi_wlan_otap_struct *cntx, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Whether the index is legal. */
    if (index >= cntx->num_profiles) 
    {
        MMI_ASSERT(0);
    }
    
    /* Release the specified profile. */
    OslMfree(cntx->profile[index]);

    /* Shift the other profiles. */
    for (i = index + 1; i < cntx->num_profiles; ++i) 
    {
        cntx->profile[i - 1] = cntx->profile[i];
    }
    cntx->profile[cntx->num_profiles - 1] = NULL;

    /* Now, we can update the number of profiles. */
    --cntx->num_profiles;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_validate_eap
 * DESCRIPTION
 *  The function validates whether a correct EAP setting is presented.
 * PARAMETERS
 *  prof            [IN]            A provisioned profile    
 * RETURNS
 *  On success, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_validate_eap(const mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Currently, only EAP-SIM is supported. */
    if (prof->auth_type1 != WLAN_EAP_SIM) 
    {
        return MMI_FALSE;
    }
    
    /* Whether the username/password have been provided. */
    if (strlen((S8 *)prof->username) == 0 || strlen((S8 *)prof->password) == 0) 
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_validate_wep_key
 * DESCRIPTION
 *  The function validates whether a correct WEP key is presented.
 * PARAMETERS
 *  prof            [IN]            A provisioned profile    
 * RETURNS
 *  On success, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_validate_wep_key(const mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Whether the wep key index is legal. */
    if (prof->wep_key_index >= MAX_WEP_KEY_NUM) 
    {
        return MMI_FALSE;
    }

    /* Return TRUE if WEP setting are meaningful. */
    str_len = strlen((S8 *)prof->wep_key);

    if (prof->wep_key_len == WLAN_WEP_KEY_ENCRYPT_64 && 
        prof->wep_key_format == WLAN_WEP_KEY_FORMAT_ASCII)
    {
        return str_len == 5? MMI_TRUE: MMI_FALSE;   /* WEP64, ASCII  */
    }
    else if (prof->wep_key_len == WLAN_WEP_KEY_ENCRYPT_64 && 
             prof->wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
    {
        return str_len == 10? MMI_TRUE: MMI_FALSE;  /* WEP64, HEX    */
    }
    else if (prof->wep_key_len == WLAN_WEP_KEY_ENCRYPT_128 && 
             prof->wep_key_format == WLAN_WEP_KEY_FORMAT_ASCII)
    {
        return str_len == 13? MMI_TRUE: MMI_FALSE;  /* WEP128, ASCII */
    }
    else if (prof->wep_key_len == WLAN_WEP_KEY_ENCRYPT_128 && 
             prof->wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
    {
        return str_len == 26? MMI_TRUE: MMI_FALSE;  /* WEP128, HEX   */
    }

    /* All other situations are illegal. Return FALSE. */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_validate_profile
 * DESCRIPTION
 *  The function validates a provisioned profile.
 * PARAMETERS
 *  prof            [IN]            A provisioned profile    
 * RETURNS
 *  On success, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_validate_profile(const mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* NAPDEF node's node ID */
    if (mmi_chset_utf8_strlen((kal_uint8 *)prof->node_id) == 0) 
    {
        return MMI_FALSE;
    }

    /* Name */
    if (mmi_ucs2strlen((S8 *)prof->name) == 0) 
    {
        return MMI_FALSE;    
    }
    
    /* SSID */
    if (prof->ssid_len == 0) 
    {
        return MMI_FALSE;
    }

    /* Network type. Ad-hoc network does not has authentication server.
       IEEE802.1X and WPA need authentication server and can't be used. */
    if (prof->network_type == WLAN_NETWORK_TYPE_ADHOC && 
        (prof->auth_mode == WLAN_AUTH_MODE_IEEE8021X || 
         prof->auth_mode == WLAN_AUTH_MODE_WPA))
    {
        return MMI_FALSE;
    }

    /* 
     * Authentication mode 
     */
    switch (prof->auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:
            /* OPEN must turn on NONE or WEP encryption. */
            if (prof->encrypt_mode != WLAN_ENCRYPT_MODE_NONE && 
                prof->encrypt_mode != WLAN_ENCRYPT_MODE_WEP)
            {
                return MMI_FALSE;
            }
            break;
            
        case WLAN_AUTH_MODE_SHARED:
            /* SHARED must turn on NONE or WEP encryption. */
            if (prof->encrypt_mode != WLAN_ENCRYPT_MODE_NONE && 
                prof->encrypt_mode != WLAN_ENCRYPT_MODE_WEP)
            {
                return MMI_FALSE;
            }

            /* SHARED alwalys needs a correct WEP key. */
            if (mmi_wlan_validate_wep_key(prof) == MMI_FALSE) {
                return MMI_FALSE;
            }
            break;
                
        case WLAN_AUTH_MODE_IEEE8021X:
            /* IEEE802.1X must turn on WEP encryption. */
            if (prof->encrypt_mode != WLAN_ENCRYPT_MODE_WEP) 
            {
                return MMI_FALSE;
            }

            if (mmi_wlan_validate_eap(prof) == MMI_FALSE)
            {
                return MMI_FALSE;
            }
            break;
            
        case WLAN_AUTH_MODE_WPA:
            /* WPA must turn on TKIP or AES encryption. */
            if (prof->encrypt_mode != WLAN_ENCRYPT_MODE_TKIP && 
                prof->encrypt_mode != WLAN_ENCRYPT_MODE_AES) 
            {
                return MMI_FALSE;
            }
            
            if (mmi_wlan_validate_eap(prof) == MMI_FALSE)
            {
                return MMI_FALSE;
            }
            break;

        case WLAN_AUTH_MODE_WPAPSK:
            /* WPA-PSK must turn on TKIP or AES. */
            if (prof->encrypt_mode != WLAN_ENCRYPT_MODE_TKIP && 
                prof->encrypt_mode != WLAN_ENCRYPT_MODE_AES) 
            {
                return MMI_FALSE;
            }
            break;
            
        default:
            return MMI_FALSE; /* Discard profile */
    }
    
    /* 
     * Encryption mode
     */
    switch (prof->encrypt_mode)
    {
        case WLAN_ENCRYPT_MODE_NONE:
            break;
            
        case WLAN_ENCRYPT_MODE_WEP:
            /* Whether WEP key is correctly presented except under IEEE802.1X, 
               which provides the key automatically. */
            if (prof->auth_mode != WLAN_AUTH_MODE_IEEE8021X && 
                mmi_wlan_validate_wep_key(prof) == MMI_FALSE) 
            {
                return MMI_FALSE;
            }
            break;

        case WLAN_ENCRYPT_MODE_TKIP:
        case WLAN_ENCRYPT_MODE_AES:
            /* Whether psk or passphrase is presented. Note that WPA don't
               need to provide key here. It uses dynamic key. */
            if (prof->auth_mode != WLAN_AUTH_MODE_WPA && 
                prof->psk[32] == 0 && prof->passphrase[0] == '\0') 
            {
                return MMI_FALSE;
            }
            break;

        default:
            return MMI_FALSE; /* Discard profile */
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_show_info
 * DESCRIPTION
 *  This function shows a notification screen with the specified message.
 * PARAMETERS
 *  msg_id          [IN]            Message to be shown
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_show_info(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DisplayPopup(
        (U8 *)GetString(msg_id),
        IMG_GLOBAL_INFO,
        1,
        DATA_ACCOUNT_NOTIFY_TIMEOUT,
        WARNING_TONE);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_provision_profile
 * DESCRIPTION
 *  This function setups a WLAN profile from a slim profile.
 * PARAMETERS
 *  dst             [OUT]           Destination profile
 *  src             [IN]            Source slim profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_provision_profile(
        mmi_wlan_profile_struct *dst, 
        const mmi_wlan_slim_profile_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Clear the profile. */
    mmi_wlan_init_profile(dst);

    mmi_ucs2cpy((S8 *)dst->name, (S8 *)src->name);   /* Name             */
    dst->ssid_len = src->ssid_len;                  /* SSID length      */
    memcpy(dst->ssid, src->ssid, dst->ssid_len);    /* SSID             */
    dst->network_type = src->network_type;          /* Network type     */
    dst->encrypt_mode = src->encrypt_mode;          /* Encryption       */
    dst->auth_mode    = src->auth_mode;             /* Authentication   */

    /* WEP settings */
    if (dst->auth_mode == WLAN_AUTH_MODE_SHARED || 
        dst->encrypt_mode == WLAN_ENCRYPT_MODE_WEP)
    {
        dst->wep_key_index  = src->wep_key_index;
        dst->wep_key_len    = src->wep_key_len;
        dst->wep_key_format = src->wep_key_format;
        strcpy((S8 *)dst->wep_key, (S8 *)src->wep_key);
    }

    /* Pre-shared key settings. */
    if (dst->auth_mode == WLAN_AUTH_MODE_WPAPSK)
    {
        /* Default uses psk; otherwise, compute psk from passphrase. */
        if (src->psk[32] != 0)
        {
            memcpy(dst->psk, src->psk, 32);
        }
        else
        {
            strcpy((S8 *)dst->passphrase, (S8 *)src->passphrase);
            
        #ifdef __MTK_TARGET__
            pbkdf2_sha1(
                (S8 *)dst->passphrase,
                (S8 *)dst->ssid,
                dst->ssid_len,
                4096,
                dst->psk,
                32);
        #else
            memcpy(dst->psk, src->passphrase, 32);
        #endif
        }

        /* PSK is always provided. Turn on the flag. */
        dst->psk[32] = 1;
    }

    /* EAP settings. */
    if (dst->auth_mode == WLAN_AUTH_MODE_IEEE8021X || 
        dst->auth_mode == WLAN_AUTH_MODE_WPA)
    {
        dst->auth_type1 = src->auth_type1;
        strcpy((S8 *)dst->username, (S8 *)src->username);
        strcpy((S8 *)dst->password, (S8 *)src->password);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_install_profiles
 * DESCRIPTION
 *  This function installs each incoming profile that has been chosen to 
 *  install.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of installed profiles.
 *****************************************************************************/
U8 mmi_wlan_install_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wlan_slim_profile_struct *src_prof;
    mmi_wlan_profile_struct dst_prof;
    mmi_wlan_profile_struct *temp = NULL;
    S16 src_idx;
    U8 data_acct_id;
    S16 error;
    U8 num_installed;
    U8 i, j, k;
    U32 size = 0;
    U8 old_network;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Delete screens associated with the last profile. Clear delete screen
       callback temporarily to prevent from terminating app. */
    ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, NULL);
    GoBackToHistory(SCR_ID_CCA_PROGRESS);
    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, mmi_wlan_abort_otap_app);

    /* Obtain the WLAN data account ID. */
#ifdef __MTK_TARGET__
    data_acct_id = mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_WIFI);
#else
    data_acct_id = 20;
#endif

    /* Install each profile. To make sure the order of installed profiles are
       correct, scan the slots, rather than profiles in the control block. */

    num_installed = 0;

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; ++i)
    {
        /* Continue when no incoming profile plans to install in this slot. */
        if ((src_idx = g_wlan_otap->src_idx[i]) < 0) 
        {
            continue;
        }

        src_prof = g_wlan_otap->profile[src_idx];
        memcpy(&dst_prof, &g_wlan_prof_list[i], sizeof(mmi_wlan_profile_struct));
        old_network = g_wlan_prof_list[i].network_type;
        //dst_prof = &g_wlan_prof_list[i];
        
        /* Setup profile. Note that all context of dst_prof will be reset. */
        mmi_wlan_provision_profile(&dst_prof, src_prof);

        /* Setup new priority, profile_id and update pointer. */
        /*dst_prof->priority = priority;
        dst_prof->profile_id = ++g_wlan_setting_context.profile_id_count;
        
        /* replace profile */
        if(g_wlan_otap_replace)
        {
            g_wlan_otap_replace = FALSE;
            /* changed ap profile network_type */
            
            if(dst_prof.network_type != old_network)
            {
                /* adhoc -> Infrastructure*/
                if(dst_prof.network_type == WLAN_NETWORK_TYPE_INFRA)
                {
                    if(dst_prof.priority == g_wlan_display_context.infra_prof_num + 1)
                    {
                        g_wlan_display_context.infra_prof_num++;
                        g_wlan_display_context.adhoc_prof_num--;
                    }
                    else
                    {
                        temp = &dst_prof;
                        for(j = (dst_prof.priority - 1); j > g_wlan_display_context.infra_prof_num; j--)
                        {
                            g_wlan_profile[j] = g_wlan_profile[j - 1];
                            g_wlan_profile[j]->priority++;
                        }
                        g_wlan_profile[g_wlan_display_context.infra_prof_num ] = temp;
                        g_wlan_profile[g_wlan_display_context.infra_prof_num ]->priority = g_wlan_display_context.infra_prof_num + 1;
                        g_wlan_display_context.infra_prof_num++;
                        g_wlan_display_context.adhoc_prof_num--;
                    }
                }
                else /* Infrastructure -> adhoc */
                {
                    if(dst_prof.priority == g_wlan_display_context.infra_prof_num)
                    {
                        g_wlan_display_context.infra_prof_num--;
                        g_wlan_display_context.adhoc_prof_num++;
                    }
                    else
                    {
                        temp = &dst_prof;
                        for(j = (g_wlan_prof_list[i].priority); j < g_wlan_display_context.infra_prof_num; j++)
                        {
                            g_wlan_profile[j-1] = g_wlan_profile[j];
                            g_wlan_profile[j]->priority--;
                        }
                        g_wlan_profile[g_wlan_display_context.infra_prof_num - 1] = temp;
                        g_wlan_profile[g_wlan_display_context.infra_prof_num - 1]->priority = g_wlan_display_context.infra_prof_num;
                        g_wlan_display_context.infra_prof_num--;
                        g_wlan_display_context.adhoc_prof_num++;
                    }
                }
            }
            else
            {
                dst_prof.priority = g_wlan_prof_list[i].priority;
                memcpy(&g_wlan_prof_list[i], &dst_prof, sizeof(mmi_wlan_profile_struct));
            }
        }
        else
        {
            /* Find an empty slot index first */
            for (k = 0; k < MAX_WLAN_DATA_ACCOUNT_NUM; k++)
            {
                if (g_wlan_prof_list[k].ssid_len == 0)
                {
                    break;
                }
            }
            
            if(dst_prof.network_type == WLAN_NETWORK_TYPE_INFRA)
            {
                if(g_wlan_display_context.adhoc_prof_num == 0)
                {
                    dst_prof.priority = ++g_wlan_display_context.prof_num;
                    dst_prof.profile_id = ++g_wlan_setting_context.profile_id_count;
                    
                    memcpy(&g_wlan_prof_list[k], &dst_prof, sizeof(mmi_wlan_profile_struct));
                    g_wlan_profile[g_wlan_prof_list[k].priority - 1] = &g_wlan_prof_list[k];
                    g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[k];
                }
                else
                {
                    for(j = g_wlan_display_context.prof_num; j > g_wlan_display_context.infra_prof_num; j--)
                    {
                        g_wlan_profile[j] = g_wlan_profile[j-1];
                        g_wlan_profile[j]->priority++;
                    }
                    
                    dst_prof.priority = g_wlan_display_context.infra_prof_num + 1;
                    dst_prof.profile_id = ++g_wlan_setting_context.profile_id_count;
                    memcpy(&g_wlan_prof_list[k], &dst_prof, sizeof(mmi_wlan_profile_struct));
                    g_wlan_profile[g_wlan_display_context.infra_prof_num] = &g_wlan_prof_list[k];
                    g_wlan_display_context.prof_num++;
                }
                g_wlan_display_context.infra_prof_num++;
            }
            else 
            {
                g_wlan_display_context.adhoc_prof_num++;
                
                dst_prof.priority = ++g_wlan_display_context.prof_num;
                dst_prof.profile_id = ++g_wlan_setting_context.profile_id_count;
                
                memcpy(&g_wlan_prof_list[k], &dst_prof, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[g_wlan_prof_list[k].priority - 1] = &g_wlan_prof_list[k];
                g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[k];
            }
        }
        
        for (k = 0; k < MAX_WLAN_DATA_ACCOUNT_NUM; k++)
        {
            if (g_wlan_prof_list[k].priority > 0)
            {                
                size = WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, k + 1, &g_wlan_prof_list[k], NVRAM_MAX_WLAN_PROFILE_SIZE, &error);
                
                if ( size < NVRAM_MAX_WLAN_PROFILE_SIZE)
                {
                    MMI_ASSERT(0);
                }
            }
        }
        
        
        /* Notify CCA the success of installing each WLAN profile. */
        mmi_cca_oma_add_dataacctid(g_wlan_otap->doc_hdl, (S8 *)src_prof->node_id, data_acct_id);
        
        /* Install successfully. Update counter. */        
        ++num_installed;
    }
    
    /* profile_id_count has been updated. Save the context in the NVRAM. */
    WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_wlan_setting_context, NVRAM_MAX_WLAN_SETTING_SIZE, &error);
    if (error != NVRAM_WRITE_SUCCESS) 
    {
        MMI_ASSERT(0);
    }

    return num_installed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auto_rename_profile
 * DESCRIPTION
 *  This function renames the specified provisioned profile that has duplicate
 *  name.
 * PARAMETERS
 *  src_idx         [IN]            Used to specified the profile
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_auto_rename_profile(S16 src_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U8 *name[MAX_WLAN_DATA_ACCOUNT_NUM];
    U8 num_names;
    S16 dst_idx, i_src_idx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Inform user the auto renaming. */
    /* mmi_wlan_show_info(STR_ID_DTCNT_WLAN_AUTO_RENAME_PROFILE); */

    /* Collect the other profiles' names. */
    num_names = 0;
    dst_idx = g_wlan_otap->dst_idx[src_idx];

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; ++i)
    {
        /* Skip itself. */
        if (dst_idx == i) 
        {
            continue;
        }

        /* Obtain the name of the profile in the i-th slot at present. */
        i_src_idx = g_wlan_otap->src_idx[i];

        if (i_src_idx >= 0)
        {
            /* i-th slot has been selected to install an incoming profile. */
            name[num_names++] = g_wlan_otap->profile[i_src_idx]->name;
        }
        else if (g_wlan_prof_list[i].ssid_len != 0)
        {
            /* A profile exists in i-th slot before OTA provisioning. */
            name[num_names++] = g_wlan_prof_list[i].name;
        }
    }

    /* Auto renaming. */
    mmi_wlan_resolve_duplicate_name(g_wlan_otap->profile[src_idx]->name, name, num_names);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_is_duplicate_name
 * DESCRIPTION
 *  This function examines whether the specified provisioning profile has a 
 *  duplicate name.
 * PARAMETERS
 *  src_idx         [IN]            Used to specify the profile
 * RETURNS
 *  When there is a duplication, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_is_duplicate_name(S16 src_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *name;
    S16 dst_idx, i_src_idx;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain info about this specified provisioned profile. */
    name    = g_wlan_otap->profile[src_idx]->name;
    dst_idx = g_wlan_otap->dst_idx[src_idx];

    /* Check duplication by scanning all profiles. */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; ++i)
    {
        /* Skip itself. */
        if (dst_idx == i) 
        {
            continue;
        }

        /* Obtain the name of the profile in the i-th slot at present. */
        i_src_idx = g_wlan_otap->src_idx[i];

        if (i_src_idx >= 0)
        {
            /* i-th slot has been selected to install a incoming profile. */
            if (mmi_ucs2cmp((S8 *)name, (S8 *)g_wlan_otap->profile[i_src_idx]->name) == 0) 
            {
                return MMI_TRUE;
            }
        }
        else if (g_wlan_prof_list[i].ssid_len != 0)
        {
            /* A profile exists in i-th slot before OTA provisioning. */
            if (mmi_ucs2cmp((S8 *)name, (S8 *)g_wlan_prof_list[i].name) == 0) 
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_replacement_save
 * DESCRIPTION
 *  This function saves the information to replace an existing profile with
 *  the current provisioned one.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_replacement_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 src_idx, dst_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* The index of profile in profile list that plans to be replaced. */
    dst_idx = g_wlan_otap->sel_dst_idx[g_wlan_otap->choice];

    /* Whether the profile has been selected to be replaced during OTA
       provisioning. If yes, the previously provisioned profile is replaced
       here and will not be install consequently. */
    src_idx = g_wlan_otap->src_idx[dst_idx];
    
    if (src_idx >= 0) 
    {
        g_wlan_otap->dst_idx[src_idx] = -1;
    }
    
    /* Save the replacement result. */
    g_wlan_otap->src_idx[dst_idx]           = g_wlan_otap->iter;
    g_wlan_otap->dst_idx[g_wlan_otap->iter] = dst_idx;

    /* Whether the profile's name is duplicate. */
    if (mmi_wlan_is_duplicate_name(g_wlan_otap->iter) == MMI_TRUE) 
    {
        mmi_wlan_auto_rename_profile(g_wlan_otap->iter);
    }

    g_wlan_otap_replace = TRUE;
    /* Go to next profile if it is presented. */
    mmi_wlan_next_profile();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_replacement_confirm
 * DESCRIPTION
 *  This function shows a confirmation screen to confirm a replacement.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_replacement_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* The profile is in use. Can't be replaced. */
    if (g_wlan_otap->choice == g_wlan_otap->in_use)
    {
        mmi_wlan_show_info(STR_ID_DTCNT_WLAN_ERROR_PROFILE_IN_USE);
        return;
    }

    /* Now, confirm the replacement with the user. */
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_DTCNT_WLAN_REPLACE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_wlan_replacement_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_replacement_highlight_hdlr
 * DESCRIPTION
 *  This highlight handler remembers the item chosen to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_replacement_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_otap->choice = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_replacement
 * DESCRIPTION
 *  This function shows all WLAN profiles installed on the system such that 
 *  users can select an existing profile to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *prof_name[MAX_WLAN_DATA_ACCOUNT_NUM];
    S16 sel_idx, i_src_idx;
    U8 *gui_buffer;
    U8 count;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Initialize an invalid used index of an existing profile. */
    g_wlan_otap->in_use = -1;
    
    /* Obtain the list of profiles that can be replaced. */
    count = 0;

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; ++i)
    {
        if (g_wlan_prof_list[i].ssid_len == 0)
        {
            /* The slot is originally empty, but has been chosen to install
               incoming profile during OTA provisioning. */
            i_src_idx = g_wlan_otap->src_idx[i];
            sel_idx   = g_wlan_display_context.prof_num + (count++);

            prof_name[sel_idx] = g_wlan_otap->profile[i_src_idx]->name;
            g_wlan_otap->sel_dst_idx[sel_idx] = i;
        }
        else
        {
            /* The profile is originally used. */
            i_src_idx = g_wlan_otap->src_idx[i];
            sel_idx   = g_wlan_prof_list[i].priority - 1;

            /* Whether the slot has been chosen to install incoming profiles. */
            if (i_src_idx >= 0) 
            {
                prof_name[sel_idx] = g_wlan_otap->profile[i_src_idx]->name;
            } 
            else 
            {
                prof_name[sel_idx] = g_wlan_prof_list[i].name;
            }

            g_wlan_otap->sel_dst_idx[sel_idx] = i;

            /* The profile is in use. Can't be replaced. Remember the index. */
            if (&g_wlan_prof_list[i] == g_wlan_display_context.connected_wlan_profile) 
            {
                g_wlan_otap->in_use = sel_idx;
            }
        }
    }
    
    /* prof_num + count MUST be max number of profiles. */
    MMI_ASSERT((g_wlan_display_context.prof_num + count) == MAX_WLAN_DATA_ACCOUNT_NUM);
    
    /* 
     * Entry screen.
     */
    EntryNewScreen(SCR_ID_DTCNT_WLAN_REPLACE_PROFILE, NULL, mmi_wlan_entry_replacement, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_REPLACE_PROFILE);

    RegisterHighlightHandler(mmi_wlan_replacement_highlight_hdlr);

    /* TODO: gIndexIconsImageList only has numeric icons from 1 to 30. */
    ShowCategory53Screen(
        STR_ID_DTCNT_WLAN_REPLACE_PROFILE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_WLAN_DATA_ACCOUNT_NUM,
        prof_name,
        (U16 *)gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_wlan_entry_replacement_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_wlan_entry_replacement_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_is_empty_profile
 * DESCRIPTION
 *  This function examines whether the i-th slot in the profile list is used.
 * PARAMETERS
 *  i               [IN]            Used to specify i-th profile
 * RETURNS
 *  Return TRUE when profile is empty. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_is_empty_profile(U8 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* The profile is used originally. */
    if (g_wlan_prof_list[i].ssid_len != 0) 
    {
        return MMI_FALSE;
    }

    /* The profile is selected during the OTA provisioning. */
    if (g_wlan_otap->src_idx[i] >= 0) 
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_next_profile
 * DESCRIPTION
 *  This function leads us to process next incoming profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_next_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_installed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Increase the index of the iterator to process next profile. */
    ++g_wlan_otap->iter;

    /* Whether there is another profile needed to be installed. */
    if (g_wlan_otap->iter < g_wlan_otap->num_profiles) 
    {
        /* Try to install next profile. */
        mmi_wlan_entry_installation();
    } 
    else 
    {
        /* Now, save the profiles in the NVRAM. */
        num_installed = mmi_wlan_install_profiles();

        /* Send a response back to CCA and free memory. */    
        if (num_installed == 0) 
        {
            mmi_wlan_send_cca_app_configure_rsp(g_wlan_otap->conf_id, g_wlan_otap->doc_hdl, CCA_STATUS_SETTING_SKIPPED);
        } 
        else 
        {
            mmi_wlan_send_cca_app_configure_rsp(g_wlan_otap->conf_id, g_wlan_otap->doc_hdl, CCA_STATUS_OK);
        }

        /* Free all allocated memory. */
        mmi_wlan_free_otap_cntx();

        /* Clear the delete screen callback. */
        ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
void mmi_wlan_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find an empty profile. */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; ++i)
    {
        /* Whether the profile is empty. */
        if (mmi_wlan_is_empty_profile(i) == MMI_TRUE) 
        {
            /* Remember the index of the empty profile. */
            g_wlan_otap->dst_idx[g_wlan_otap->iter] = i;
            g_wlan_otap->src_idx[i] = g_wlan_otap->iter;

            /* Whether the profile's name is duplicate. */
            if (mmi_wlan_is_duplicate_name(g_wlan_otap->iter) == MMI_TRUE) 
            {
                mmi_wlan_auto_rename_profile(g_wlan_otap->iter);
            }
            
            /* Go to the next profile if it is presented. */
            mmi_wlan_next_profile();
            
            return;
        }
    }

    /* Can not find a empty profile. Enter profile replacement. */
    mmi_wlan_entry_replacement();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_installation
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wlan_slim_profile_struct *prof;
    S8 *info;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the current interesting profile. */
    prof = (mmi_wlan_slim_profile_struct *)g_wlan_otap->profile[g_wlan_otap->iter];

    /* Obtain a temporary buffer to show messages. */
    info = (S8 *)subMenuData;

    /* Profile name */
    mmi_ucs2cpy(info, GetString(STR_ID_DTCNT_WLAN_NAME));
    mmi_ucs2cat(info, (S8 *)L":  ");
    mmi_ucs2cat(info, (S8 *)prof->name);
    mmi_ucs2cat(info, (S8 *)L"\n\n");
    
    /* SSID */
    mmi_ucs2cat(info, GetString(STR_ID_DTCNT_WLAN_SSID));
    mmi_ucs2cat(info, (S8 *)L":  ");
    mmi_asc_to_ucs2(info + mmi_ucs2strlen(info) * ENCODING_LENGTH, (S8 *)prof->ssid);
    mmi_ucs2cat(info, (S8 *)L"\n\n");
    
    /* Network type */
    mmi_ucs2cat(info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));
    mmi_ucs2cat(info, (S8 *)L":  ");

    switch (prof->network_type)
    {
        case WLAN_NETWORK_TYPE_ADHOC:
            mmi_ucs2cat(info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC));
            break;

        case WLAN_NETWORK_TYPE_INFRA:
            mmi_ucs2cat(info, GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA));
            break;

        default:
            MMI_ASSERT(0);  /* Impossible to reach here. */
    }

    mmi_ucs2cat(info, (S8 *)L"\n\n");

    /* 
     * Security solution 
     */    
    mmi_ucs2cat(info, GetString(STR_ID_DTCNT_WLAN_SECURITY));
    mmi_ucs2cat(info, (S8 *)L":  ");

    switch (prof->auth_mode)
    {
        case WLAN_AUTH_MODE_OPEN:

            if (prof->encrypt_mode == WLAN_ENCRYPT_MODE_WEP) 
            {
                mmi_ucs2cat(info, (S8 *)L"WEP\n\n");
            } 
            else 
            {
                mmi_ucs2cat(info, GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN));
            }
            break;

        case WLAN_AUTH_MODE_SHARED:
            
            mmi_ucs2cat(info, (S8 *)L"WEP\n\n");
            break;
            
        case WLAN_AUTH_MODE_IEEE8021X:
            
            mmi_ucs2cat(info, (S8 *)L"IEEE802.1X\n\n");
            break;

        case WLAN_AUTH_MODE_WPA:

            switch (prof->encrypt_mode) 
            {
                case WLAN_ENCRYPT_MODE_TKIP:
                    mmi_ucs2cat(info, (S8 *)L"WPA\n\n");
                    break;
            
                case WLAN_ENCRYPT_MODE_AES:
                    mmi_ucs2cat(info, (S8 *)L"WPA2\n\n");
                    break;
            
                default:
                    MMI_ASSERT(0);  /* Impossible to reach here. */
            }
            break;
            
        case WLAN_AUTH_MODE_WPAPSK:

            if (prof->network_type == WLAN_NETWORK_TYPE_ADHOC)
            {
                /* No matter the encryption method is TKIP or AES, this is 
                   callled WPA-NONE for ad-hoc network. */
                mmi_ucs2cat(info, (S8 *)L"WPA-NONE\n\n");
            }
            else
            {
                /* For infrastructure mode, determine it by the encryption. */
                switch (prof->encrypt_mode) 
                {
                    case WLAN_ENCRYPT_MODE_TKIP:
                        mmi_ucs2cat(info, (S8 *)L"WPA-PSK\n\n");
                        break;
                
                    case WLAN_ENCRYPT_MODE_AES:
                        mmi_ucs2cat(info, (S8 *)L"WPA2-PSK\n\n");
                        break;
                
                    default:
                        MMI_ASSERT(0);  /* Impossible to reach here. */
                }
            }
            
            break;

        default:

            /* After profile validation, it's impossible to reach here. */
            MMI_ASSERT(0);
    }

    
    /* 
     * Entry screen. 
     */
    EntryNewScreen(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, NULL, mmi_wlan_entry_installation, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE);

    ShowCategory74Screen(
        STR_ID_DTCNT_WLAN_INSTALL_PROFILE,
        GetRootTitleIcon(MENU_ID_WLAN_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (U8 *)info,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_wlan_find_empty_profile, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_wlan_next_profile, KEY_EVENT_UP);

    /* 
    SetKeyHandler(mmi_wlan_find_empty_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_wlan_next_profile, KEY_LEFT_ARROW, KEY_EVENT_DOWN); 
    */

    /* Delete screens associated with previous profile. Clear delete screen 
       callback temporarily to prevent from terminating app. */
    ClearDelScrnIDCallbackHandler(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, NULL);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_REPLACE_PROFILE);
    DeleteScreenIfPresent(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE);
    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, mmi_wlan_abort_otap_app);
}


/*****************************************************************************
 * Use OMA extension OTAP spec.
 *****************************************************************************/
#if defined(__MMI_WLAN_OTAP_OMAEXT__)

static U32 mmi_wlan_base64_decoder(S8 *dst, U32 dst_size, const S8 *src, U32 src_size);
static MMI_BOOL mmi_wlan_has_otap_profile(cca_iterator_struct *param_list);

static cca_status_enum mmi_wlan_proc_cca_param_wepkey(
                        const cca_core_data_struct *param, 
                        mmi_wlan_slim_profile_struct *prof);
static cca_status_enum mmi_wlan_proc_cca_param_eap(
                        const cca_core_data_struct *param, 
                        mmi_wlan_slim_profile_struct *prof);
static cca_status_enum mmi_wlan_proc_cca_param_wlan(
                        const cca_core_data_struct *param, 
                        mmi_wlan_slim_profile_struct *prof);
static cca_status_enum mmi_wlan_proc_cca_param_napdef(
                        const cca_core_data_struct *param, 
                        mmi_wlan_otap_struct *cntx);
static cca_status_enum mmi_wlan_proc_cca_nodes(
                        S32 doc_hdl, 
                        S32 node_hdl, 
                        U16 symbol, 
                        cca_iterator_struct *param_list, 
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_base64_decoder
 * DESCRIPTION
 *  This function decodes the Base64 encoded data according to the RFC 1341.
 * PARAMETERS
 *  dst             [OUT]           Buffer for storing the decoded data
 *  dst_size        [IN]            Size of the dst buffer
 *  src             [IN]            Buffer of the input Base64 encoded data
 *  src_size        [IN]            #characters of the Base64 encoded data
 * RETURNS
 *  On success, it returns the number of decoded octets that are stored in the
 *  dst buffer. On error, 0 is returned, e.g., when the size of dst buffer is
 *  too small. 
 *****************************************************************************/
U32 mmi_wlan_base64_decoder(S8 *dst, U32 dst_size, const S8 *src, U32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Codebook used to decode Base64 data. Please refer to RFC 1341 and ASCII
     * encoding for more details.
     */
    const U8 codebook[] = 
    {
        62, 0xFF, 0xFF, 0xFF, 63,                       /* +, /     */
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61,         /* 0-9      */
        0xFF, 0xFF, 0xFF, 0, 0xFF, 0xFF, 0xFF,          /* =        */
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,                   /* A-Z      */
        10, 11, 12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23, 24, 25,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,             /* garbage  */
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35,         /* a-z      */
        36, 37, 38, 39, 40, 41, 42, 43,
        44, 45, 46, 47, 48, 49, 50, 51
    };

    U8 in[4], out[3];               /* buffers to decode a quantum  */
    S8 count;                       /* #octet decoded for a quantum */
    U32 num_octets;                 /* #octet decoded from source   */
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialize the number of octets decoded from the Base64 data. */
    num_octets = 0;

    /* Start the Base64 decoding process. */
    for (i = 0; i < src_size;) 
    {
        /* Initialize #octet decoded for a quantum without padding. */
        count = 3;

        /* Obtain a quantum to be decoded. */
        for (j = 0; j < 4; ++j) 
        {

            /* Ignore line breaks and other characters not found in the
               table of Base64 specification. */
            do 
            {
                /* Read one character from the Base64 data. If the data steam 
                   is empty, assign the padding character '='. */
                if (i < src_size) 
                {
                    in[j] = src[i++];
                } 
                else 
                {
                    in[j] = '=';
                }

                /* Padding happened. Decrease count for the decoded result.
                   Note that count might be negative when there is nothing to
                   commit to the destination buffer. */
                if (in[j] == '=') 
                {
                    --count;
                }

                /* decode the character by table look-up. */
                if (in[j] >= '+' && in[j] <= 'z') 
                {
                    in[j] = codebook[in[j] - '+'];
                } 
                else 
                {
                    in[j] = 0xFF;
                }
            } while (in[j] == 0xFF);
        }

        /* decode the quantum. */
        out[0] = (U8)(in[0] << 2 | in[1] >> 4);
        out[1] = (U8)(in[1] << 4 | in[2] >> 2);
        out[2] = (U8)(in[2] << 6 | in[3]);

        /* commit the result when we have decoded octets actually. */
        if (count > 0) 
        {
            /* check whether the size of the dst buffer is enough. */
            if (num_octets + count > dst_size || UINT_MAX - count < num_octets) 
            {
                return 0;
            }

            /* commit the result to the destination buffer. */
            memcpy(dst + num_octets, out, count);
            num_octets += count;
        }
    }

    return num_octets;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_has_otap_profile
 * DESCRIPTION
 *  This function checks whether there is a new WLAN profile in the document.
 *  The input data list contains the parameters and their values of a NAPDEF
 *  node. Care should be take that the input iterator is reset after calling
 *  the function.
 * PARAMETERS
 *  param_list       [IN]           Parameter list for a NAPDEF node
 * RETURNS
 *  If there is a new WLAN profile, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_has_otap_profile(cca_iterator_struct *param_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *bearer;
    S32 num_bearers;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Extract the value of the parameter BEARER. */
    status = mmi_cca_doc_get_nodedata_ints(param_list, CCA_NS_OMA_BEARER, &bearer, &num_bearers);
    mmi_cca_iterator_restart(param_list);

    if (status != CCA_STATUS_OK) 
    {
        return MMI_FALSE;
    }

    /* Whether there is a WLAN bearer. */ 
    while (--num_bearers >= 0)
    {
        if (bearer[num_bearers] == CCA_NS_VAL_WLAN) 
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_proc_cca_param_wepkey
 * DESCRIPTION
 *  This function processes the parameter of WEPKEY node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_wlan_proc_cca_param_wepkey(
                    const cca_core_data_struct *param, 
                    mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_octets;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_LENGTH:
            
            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }
            
            switch (atoi(param->values.s[0]))
            {
                case 40:
                    /* 40-bits WEP key  +  24-bits IV  =  64 bits */
                    prof->wep_key_len = WLAN_WEP_KEY_ENCRYPT_64;
                    break;

                case 104:
                    /* 104-bits WEP key  +  24-bits IV  =  128 bits */
                    prof->wep_key_len = WLAN_WEP_KEY_ENCRYPT_128;
                    break;

                default:
                    return CCA_STATUS_FAIL;            
            }
            
            break;

        case CCA_NS_OMA_DATA:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (mmi_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Compute the WEP key. */
            num_octets = mmi_wlan_base64_decoder(
                            (S8 *)prof->wep_key, 
                            MAX_WEP_KEYSTR_LEN - 1, 
                            param->values.s[0], 
                            strlen(param->values.s[0]));

            /* Fail when wep_key buffer is too small, or length is illegal. */
            if (num_octets != 5 && num_octets != 13) 
            {
                return CCA_STATUS_FAIL;
            }

            prof->wep_key[num_octets] = '\0';

            /* Set WEP key length when this entry is not set yet. */
            if (prof->wep_key_len == WLAN_WEP_KEY_ENCRYPT_TOTAL) 
            {
                if (num_octets == 5) 
                {
                    prof->wep_key_len = WLAN_WEP_KEY_ENCRYPT_64;
                } 
                else
                {
                    prof->wep_key_len = WLAN_WEP_KEY_ENCRYPT_128;
                }
            }
            
            break;

        case CCA_NS_OMA_INDEX:
        default:
            break;
    }
    
    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_proc_cca_param_eap
 * DESCRIPTION
 *  The function processes the parameter of EAP node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile    
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_wlan_proc_cca_param_eap(
                    const cca_core_data_struct *param, 
                    mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_EAPTYPE:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_INT) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Only support EAP SIM currently. */
            switch (param->values.i[0])
            {
                case CCA_NS_VAL_EAP_SIM:
                    prof->auth_type1 |= WLAN_EAP_SIM;
                    break;
                    
                default:
                    return CCA_STATUS_FAIL;
            }
            
            break;

        case CCA_NS_OMA_USERNAME:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the username is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len + 1 > MAX_USERNAME_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (mmi_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Obtain the username. Zero-terminate username. */
            strcpy((S8 *)prof->username, param->values.s[0]);        
            
            break;

        case CCA_NS_OMA_PASSWORD:

            
            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the password is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len + 1 > MAX_PASSWORD_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (mmi_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Obtain the password. Zero-terminate password. */
            strcpy((S8 *)prof->password, param->values.s[0]);            
            
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_proc_cca_param_wlan
 * DESCRIPTION
 *  This function processes the parameter of WLAN node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  prof            [IN/OUT]        The current provisioned profile
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_wlan_proc_cca_param_wlan(
                    const cca_core_data_struct *param, 
                    mmi_wlan_slim_profile_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    U8 base64_buf[64];
    S32 value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_PRI_SSID:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether the length of the SSID is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len + 1 > MAX_SSID_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (mmi_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Get SSID in ASCII format. Zero-terminate SSID. */
            prof->ssid_len = str_len;
            strcpy((S8 *)prof->ssid, param->values.s[0]);

            break;
        
        case CCA_NS_OMA_NETMODE:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_INT) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Extract setting. */
            switch (param->values.i[0])
            {
                case CCA_NS_VAL_INFRA:
                    prof->network_type = WLAN_NETWORK_TYPE_INFRA;
                    break;

                case CCA_NS_VAL_ADHOC:
                    prof->network_type = WLAN_NETWORK_TYPE_ADHOC;
                    break;

                default:
                    return CCA_STATUS_FAIL;
            }
            
            break;

        case CCA_NS_OMA_WPA_PRES_KEY_ASC:
            
            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the length of the passphrase is legal. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len + 1 < MIN_PASSPHRASE_LEN || str_len + 1 > MAX_PASSPHRASE_LEN) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (mmi_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Get passphrase in ASCII format. Zero-terminate passphrase. */
            strcpy((S8 *)prof->passphrase, param->values.s[0]);

            break;

        case CCA_NS_OMA_WPA_PRES_KEY_HEX:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Length of the Base64 data should be 88 bytes for 64 HEX chars 
               (256 bits). Please refer to Base64 encoding method. */
            str_len = mmi_chset_utf8_strlen((kal_uint8 *)param->values.s[0]);
            if (str_len != 88) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Whether this is a ASCII string. */
            if (mmi_wlan_is_ascii_string((U8 *)param->values.s[0]) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Obtain the HEX format pre-shared key. It should be 64 bytes. */
            if (mmi_wlan_base64_decoder(
                    (S8 *)base64_buf, 
                    sizeof(base64_buf) / sizeof(U8), 
                    param->values.s[0], 
                    str_len) != 64) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Convert 64 bytes HEX data to 256 bits raw data. */
            if (mmi_wlan_hex_to_psk(prof->psk, base64_buf, 64) == MMI_FALSE) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Turn on the 33-bytes when PSK is set. */
            prof->psk[32] = 1;
            
            break;

        case CCA_NS_OMA_WEPKEYIND:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Check whether the index is legal. */
            value = atoi(param->values.s[0]);
            
            if (value < 0 || value >= MAX_WEP_KEY_NUM) 
            {
                return CCA_STATUS_FAIL;
            }

            prof->wep_key_index = value;
            
            break;

        case CCA_NS_OMA_WEPAUTHMODE:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_INT) 
            {
                return CCA_STATUS_FAIL;
            }

            /* Extract the setting. */
            switch (param->values.i[0])
            {
                case CCA_NS_VAL_OPEN:
                    prof->auth_mode = WLAN_AUTH_MODE_OPEN;
                    break;
            
                case CCA_NS_VAL_SHARED:
                    prof->auth_mode = WLAN_AUTH_MODE_SHARED;
                    break;
            
                default:
                    return CCA_STATUS_FAIL;
            }
            
            break;

        case CCA_NS_OMA_SECMODE:
        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_proc_cca_param_napdef
 * DESCRIPTION
 *  This function processes the parameter of WLAN node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The WLAN OTAP control block
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_wlan_proc_cca_param_napdef(
                    const cca_core_data_struct *param, 
                    mmi_wlan_otap_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_NODEID:

            /* Whether the value is presented and the type is legal. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Whether the string's raw length is legal. */
            str_len = strlen(param->values.s[0]);
            if (str_len + 1 > MAX_NODE_ID_LEN) 
            {
                return CCA_STATUS_FAIL;
            }
            
            /* Extract the node id. Store it as UTF-8 string. */
            strcpy((S8 *)cntx->node_id, param->values.s[0]);

            break;

        case CCA_NS_OMA_NAME:

            /* Whether the value is presented and the type is legal. If it's
               illegal, default name will be used. Still return OK. */
            if (param->size <= 0 || param->type != CCA_DT_STR) 
            {
                return CCA_STATUS_OK;   /* Error-tolerant for profile's name */
            }

            /* Extract the profile's name. If the name is too long, it will be
               truncated by the function. */
            mmi_chset_utf8_to_ucs2_string(
                cntx->name, 
                MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH, 
                (U8 *)param->values.s[0]);

            break;
                        
        case CCA_NS_OMA_NAPID:
        case CCA_NS_OMA_BEARER:
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum mmi_wlan_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wlan_otap_struct *cntx;
    cca_core_data_struct *param;
    S8 *value_s;
    S32 value_i;
    S32 wep_key_index;
    cca_status_enum status;
    S16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Obtain the control block. */
    cntx = (mmi_wlan_otap_struct *)user_data;

    /* We always process NAPDEF nodes to obtain node_id. We always process
       WLAN nodes to obtain profiles. For other nodes, the behavior is
       controlled by is_active parameter. */
    if (symbol != WLAN_OTAP_NS_NAPDEF && symbol != WLAN_OTAP_NS_WLAN &&
        cntx->is_active != MMI_TRUE) 
    {
        return CCA_STATUS_OK;
    }

    /* 
     * Dispatch the node according to the node symbol.
     */
    status = CCA_STATUS_OK;             /* Initialize the status variable   */
    index  = cntx->num_profiles - 1;    /* Obtain the last profile          */
    
    switch (symbol)
    {
        case WLAN_OTAP_NS_NAPDEF:

            /* Clear node_id and name for previous NAPDEF node. */
            memset(cntx->node_id, 0, MAX_NODE_ID_LEN);
            memset(cntx->name, 0, MAX_WLAN_PROF_NAME_LEN * ENCODING_LENGTH);

            /* Traverse each parameter in NAPDEF node. */ 
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = mmi_wlan_proc_cca_param_napdef(param, cntx);
            }

            /* NAPDEF doesn't know the correctness of a WLAN profile. Always 
               return OK. */
            return CCA_STATUS_OK;
            
        case WLAN_OTAP_NS_WLAN:

            /* Whether we have node_id */
            if (strlen((S8 *)cntx->node_id) == 0) 
            {
                cntx->is_active = MMI_FALSE;
                return CCA_STATUS_FAIL;
            }
            
            /* Prepare a storage for the new profile. And get the new index. */
            if ((index = mmi_wlan_new_otap_profile(cntx)) < 0)
            {
                cntx->is_active = MMI_FALSE;
                return CCA_STATUS_FAIL;
            }

            /* Enable to process parameters/nodes in the WLAN node. */
            cntx->is_active = MMI_TRUE;

            /* Remember the name, and node_id which this profile belongs to. */
            if (mmi_ucs2strlen((S8 *)cntx->name) != 0) 
            {
                mmi_ucs2cpy((S8 *)cntx->profile[index]->name, (S8 *)cntx->name);
            }
            strcpy((S8 *)cntx->profile[index]->node_id, (S8 *)cntx->node_id);
                        
            /* Before processing other parameters, obtain the security mode. */
            if (mmi_cca_doc_get_nodedata_int_first(param_list, CCA_NS_OMA_SECMODE, &value_i) == CCA_STATUS_OK)
            {
                switch (value_i)
                {
                    case CCA_NS_VAL_WEP:
                        cntx->profile[index]->auth_mode     = WLAN_AUTH_MODE_SHARED;
                        cntx->profile[index]->encrypt_mode  = WLAN_ENCRYPT_MODE_WEP;
                        break;
                
                    case CCA_NS_VAL_8021X:
                        cntx->profile[index]->auth_mode     = WLAN_AUTH_MODE_IEEE8021X;
                        cntx->profile[index]->encrypt_mode  = WLAN_ENCRYPT_MODE_WEP;
                        break;
                
                    case CCA_NS_VAL_WPA:
                        cntx->profile[index]->auth_mode     = WLAN_AUTH_MODE_WPA;
                        cntx->profile[index]->encrypt_mode  = WLAN_ENCRYPT_MODE_TKIP;
                        break;
                
                    case CCA_NS_VAL_WPA_PRESHARED_KEY:
                        cntx->profile[index]->auth_mode     = WLAN_AUTH_MODE_WPAPSK;
                        cntx->profile[index]->encrypt_mode  = WLAN_ENCRYPT_MODE_TKIP;
                        break;
                
                    case CCA_NS_VAL_WPA2:
                        cntx->profile[index]->auth_mode     = WLAN_AUTH_MODE_WPA;
                        cntx->profile[index]->encrypt_mode  = WLAN_ENCRYPT_MODE_AES;
                        break;
                
                    case CCA_NS_VAL_WPA2_PRESHARED_KEY:
                        cntx->profile[index]->auth_mode     = WLAN_AUTH_MODE_WPAPSK;
                        cntx->profile[index]->encrypt_mode  = WLAN_ENCRYPT_MODE_AES;
                        break;
                
                    default:
                        return CCA_STATUS_FAIL;
                }
            }
            
            /* Traverse other parameter in WLAN node */
            mmi_cca_iterator_restart(param_list);

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = mmi_wlan_proc_cca_param_wlan(param, cntx->profile[index]);
            }
            break;

        case WLAN_OTAP_NS_EAP:

            /* Traverse each parameter in EAP node */
            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = mmi_wlan_proc_cca_param_eap(param, cntx->profile[index]);
            }
            break;
            
        case WLAN_OTAP_NS_WEPKEY:

            /* Return if WEP key has been set. */
            if (strlen((S8 *)cntx->profile[index]->wep_key) != 0) 
            {
                return CCA_STATUS_OK;
            }

            /* Pre-determine the key index if it's presented. */
            if (mmi_cca_doc_get_nodedata_str_first(param_list, CCA_NS_OMA_INDEX, &value_s) != CCA_STATUS_OK)
            {
                wep_key_index = MAX_WEP_KEY_NUM; /* Init an invalid index */
            }
            else
            {
                /* If it's presented, the range must be correct. */
                wep_key_index = atoi(value_s);
                
                if (wep_key_index < 0 || wep_key_index >= MAX_WEP_KEY_NUM) 
                {
                    return CCA_STATUS_OK;
                }
            }
            
            /* If WEP key index is specified in WLAN node, it must match the
               index in this WEPKEY node. */
            if (cntx->profile[index]->wep_key_index < MAX_WEP_KEY_NUM)
            {
                if (wep_key_index != cntx->profile[index]->wep_key_index) 
                {
                    return CCA_STATUS_OK;
                } 
            }
            
            /* Traverse each parameter in WEPKEY node */
            mmi_cca_iterator_restart(param_list);

            while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = mmi_wlan_proc_cca_param_wepkey(param, cntx->profile[index]);
            }

            /* If successfully get the WEP key, update the key index. */
            if (strlen((S8 *)cntx->profile[index]->wep_key) != 0) 
            {
                cntx->profile[index]->wep_key_index = (wep_key_index < MAX_WEP_KEY_NUM? wep_key_index: 0);
            }
            
            break;

        case WLAN_OTAP_NS_SEC_SSID:
        case WLAN_OTAP_NS_CERT:
        
            /* Useless characteristic type. Still return OK since the profile 
               might work well even without these settings. And this will be 
               checked in the validation phase. */
            return CCA_STATUS_OK;

        default:
            /* A traversing not matched to the namespace definition. */
            MMI_ASSERT(0);
    }


    /* If the node or any parameters of the node can not be processed, update
       the context to stop processing the current profile. And release the 
       memory of the current profile. */
    if (status == CCA_STATUS_FAIL)
    {
        cntx->is_active = MMI_FALSE;
        mmi_wlan_free_otap_profile(cntx, index);
    }
    
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to WLAN
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the WLAN settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, 
            WLAN_OTAP_NS_NAPDEF, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, 
            WLAN_OTAP_NS_WLAN, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_SEC_SSID, 
            WLAN_OTAP_NS_SEC_SSID, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_EAP, 
            WLAN_OTAP_NS_EAP, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_EAP, CCA_NS_OMA_CERT, 
            WLAN_OTAP_NS_CERT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_WLAN, CCA_NS_OMA_WEPKEY, 
            WLAN_OTAP_NS_WEPKEY, 0xFFFF
    };

    cca_status_enum status;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_G7_MISC, MMI_CCA_WLAN_RECV_DOC);

    /* Whether any other OTA provisioning process is still running. */
    if (g_wlan_otap != NULL) 
    {
        MMI_ASSERT(0);  /* Guaranteed by CCA that this should not happen */
    }
    
    /* Init control block and save the ID/handle for the response msg. */
    g_wlan_otap = mmi_wlan_new_otap_cntx(conf_id, doc_hdl);

    if (g_wlan_otap == NULL) 
    {
        mmi_wlan_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_FAIL);
        return;
    }
    
    /* Extract WLAN settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                doc_hdl, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                mmi_wlan_proc_cca_nodes, 
                g_wlan_otap);


    /* Whether each profile contains all mandatory fields. */
    for (i = 0; i < g_wlan_otap->num_profiles; ) 
    {
        /* If valid, examine next profile. If invalid, free the profile. */
        if (mmi_wlan_validate_profile(g_wlan_otap->profile[i]) == MMI_TRUE)
        {
            ++i;
        } 
        else 
        {
            /* Profiles are shifted. No need to increase the index. */
            mmi_wlan_free_otap_profile(g_wlan_otap, i);
            status = CCA_STATUS_FAIL;
        }
    }

    /* If there is no correct WLAN profile, send a FAIL response message back
       to CCA. Popup a notification screen to inform the user. */
    if (g_wlan_otap->num_profiles == 0) 
    {
        /* Display the notification screen. */
        /* mmi_wlan_show_info(STR_ID_DTCNT_WLAN_ERROR_NO_PROFILES); */
        
        /* Now, terminate the WLAN OTA provisioning application. */
        mmi_wlan_send_cca_app_configure_rsp(conf_id, doc_hdl, CCA_STATUS_INVALID_SETTING);
        mmi_wlan_free_otap_cntx();
        return;
    }

    /* 
     * Start the WLAN OTA provisioning application to interact with user.
     */
    
    /* Popup a notification screen if any incoming profile is problematic. */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Setup callback to free memory and send message back to CCA when users
       press END key and return to idle screen, or when the app exits. */
    SetDelScrnIDCallbackHandler(SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, mmi_wlan_abort_otap_app);

    /* Ready to install profiles. */
    mmi_wlan_entry_installation();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to WLAN data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to WLAN data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
cca_status_enum mmi_wlan_is_cca_target(
                    U16 conf_id, 
                    S32 doc_hdl, 
                    cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *node_list, *param_list;
    S32 num_nodes, num_params;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether NAPDEF nodes are presented in the document. */
    status = mmi_cca_doc_get_nodes(doc_hdl, CCA_NS_OMA_NAPDEF, &node_list, &num_nodes);
    if (status != CCA_STATUS_OK) 
    {
        return CCA_STATUS_NOT_FOUND;
    }

    /* Check whether there are NAPDEF nodes that have a BEARER parameter with
       the value of WLAN. */
    while (mmi_cca_iterator_next(node_list) != NULL)
    {
        /* Extract all parameters and their values in the current node. */
        status = mmi_cca_doc_get_nodedata(node_list, &param_list, &num_params);
        if (status != CCA_STATUS_OK) 
        {
            continue;   /* No need to release param iterator here */
        }
        
        /* Whether there is a WLAN bearer in the NAPDEF node */
        if (mmi_wlan_has_otap_profile(param_list) == MMI_TRUE)
        {
            /* Release memory and return OK */    
            mmi_cca_iterator_release(node_list);
            mmi_cca_iterator_release(param_list);
            return CCA_STATUS_OK;
        }

        /* Release memory for the current node. */
        mmi_cca_iterator_release(param_list);
    }
    
    /* Release memory and return NOT_FOUND */
    mmi_cca_iterator_release(node_list);
    
    return CCA_STATUS_NOT_FOUND;
}


/***************************************************************************** 
 * Use the proprietary OTAP spec. 
 *****************************************************************************/
#elif defined(__MMI_WLAN_OTAP_DMP__)
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

