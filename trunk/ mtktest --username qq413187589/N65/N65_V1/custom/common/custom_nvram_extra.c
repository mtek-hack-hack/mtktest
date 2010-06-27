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
 * custom_nvram_extra.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is the implementation of the methods to manuplate the file object defined 
 *    in NVRAM data items.
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "kal_release.h"

/* Task Message Communication */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* local/peer struct */
#include "stack_ltlcom.h"

/* Buffer Management */
#include "app_buff_alloc.h"

#include "nvram_defs.h"
#include "nvram_user_defs.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_nvram_extra.h"
#include "custom_nvram_sec.h"

#if !defined(__MAUI_BASIC__)
/* 
 * NVRAM common reset folder
 */
#ifdef __DRM_V02__
#ifdef __MTK_TARGET__
__align(2) 
#endif
static const kal_wchar DRM_FOLDER[]= L"Z:\\@DRM";
#endif

#ifdef __CERTMAN_SUPPORT__
static const kal_wchar CERTMAN_FOLDER[]= L"z:\\@certman";
#endif

const kal_wchar * NVRAM_COMMON_CLEAN_FOLDER_LIST[NVRAM_MAX_CLEAN_FOLDERS] =
{
#ifdef __DRM_V02__
    DRM_FOLDER,
#endif
#ifdef __CERTMAN_SUPPORT__
    CERTMAN_FOLDER,
#endif
    NULL
};
#if !defined(__L1_STANDALONE__)

/*
 * NVRAM Shutdown Callback
 */
nvram_shutdown_cb_struct nvram_shutdown_cb_table[] =
{
    {NVRAM_EF_FLC_STATISTICS_LID, flc2_write_nvram_statistics_callback},
    {0, NULL}
};
#endif /* !__L1_STANDALONE__ */

/***************************************************************************** 
* Define of SMU
*****************************************************************************/

/* 
 *   BEGIN:PH add for smu_security_info_struct (NVRAM_EF_MS_SECURITY_LID)
 * typedef struct
 * {
 *     kal_uint8                reg_ps_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                security_indication;
 *     kal_uint8                auto_lock_item;
 *     kal_uint8                np_code[NVRAM_EDITOR_NUM_OF_BYTE_NP * NVRAM_EDITOR_NUM_NP];
 *     kal_uint8                np_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                nsp_code[NVRAM_EDITOR_NUM_OF_BYTE_NSP * NVRAM_EDITOR_NUM_NSP];
 *     kal_uint8                nsp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                np_of_sp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
 *     kal_uint8                np_of_cp[NVRAM_EDITOR_NUM_OF_BYTE_NP];
 *     kal_uint8                gid1[NVRAM_EDITOR_NUM_GID];
 *     kal_uint8                gid2[NVRAM_EDITOR_NUM_GID];
 *     kal_uint8                sp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                cp_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                imsi_code[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
 *     kal_uint8                imsi_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                phone_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
 *     kal_uint8                last_imsi[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
 *     kal_uint8                pin1[NVRAM_EDITOR_NUM_PIN1];
 *     kal_uint8                pin1_valid;
 *     kal_uint8                phone_lock_verified;
 *  }smu_security_info_struct;
 *
 */

kal_bool is_gid1_matched(kal_uint8 *sim_gid1);

#ifdef __GEMINI__
/* Load a new data object */
static kal_bool smu_load(void *, kal_uint8);   /* pobjFromlid */
/* Update a the data object */
static kal_bool smu_update(void *, kal_uint8); /* pobjTolid */
/* Release the data object */
static kal_bool smu_destory(kal_uint8);
/* Query the value of the item in kal_uint8 */
static kal_uint8 smu_query_u8(smu_item_enum, kal_uint8);   /* eItem */
/* Query the value of the item in kal_uint8[] */
static void smu_query_a(
                /* eItem */ smu_item_enum,
                /* pstrTo */ kal_uint8 *,
                /* chlen */ kal_uint8, kal_uint8);
/* Assign the value of the item in kal_uint8 */
static void smu_assign_u8(
                /* eItem */ smu_item_enum,
                /* chValue */ kal_uint8, kal_uint8);
/* Assign the value of the item in string with length */
static void smu_assign_a(
                /* eItem */ smu_item_enum,
                /* pstrValue */ kal_uint8 *,
                /* chlen */ kal_uint8, kal_uint8);
/* Compare the string with the data item */
static kal_bool smu_match(
                    /* eItem */ smu_item_enum,
                    /* pstrValue */ kal_uint8 *,
                    /* chlen */ kal_uint8, kal_uint8);
#else
/* Load a new data object */
static kal_bool smu_load(void *);   /* pobjFromlid */
/* Update a the data object */
static kal_bool smu_update(void *); /* pobjTolid */
/* Release the data object */
static kal_bool smu_destory(void);
/* Query the value of the item in kal_uint8 */
static kal_uint8 smu_query_u8(smu_item_enum);   /* eItem */
/* Query the value of the item in kal_uint8[] */
static void smu_query_a(
                /* eItem */ smu_item_enum,
                /* pstrTo */ kal_uint8 *,
                /* chlen */ kal_uint8);
/* Assign the value of the item in kal_uint8 */
static void smu_assign_u8(
                /* eItem */ smu_item_enum,
                /* chValue */ kal_uint8);
/* Assign the value of the item in string with length */
static void smu_assign_a(
                /* eItem */ smu_item_enum,
                /* pstrValue */ kal_uint8 *,
                /* chlen */ kal_uint8);
/* Compare the string with the data item */
static kal_bool smu_match(
                    /* eItem */ smu_item_enum,
                    /* pstrValue */ kal_uint8 *,
                    /* chlen */ kal_uint8);
#endif

 /***************************************************************************** 
* Typedef of SMU
*****************************************************************************/

/***************************************************************************** 
* Local Variable of SMU
*****************************************************************************/
static nvram_ef_ms_security_struct nvram_ef_ms_security_obj_g = 
{
#ifdef __GEMINI__
    NULL,
    NULL,
    smu_load,
    smu_update,
    smu_destory,
    smu_query_u8,
    smu_query_a,
    smu_assign_u8,
    smu_assign_a,
    smu_match
#else
    NULL,
    smu_load,
    smu_update,
    smu_destory,
    smu_query_u8,
    smu_query_a,
    smu_assign_u8,
    smu_assign_a,
    smu_match
#endif    
};

/***************************************************************************** 
* Global Variable of SMU
*****************************************************************************/

nvram_ef_ms_security_struct *pSmuSecurityInfog = &nvram_ef_ms_security_obj_g;

/***************************************************************************** 
* Global Function of SMU
*****************************************************************************/

/* Define your GID1 code here!! */
/***************************************************************************** 
 * The maximum length supported of GID1 is 20 bytes, represented as sim_gid1[20]
 * Modify gid1[20] array to support multiple sets of GID1 code
 * For example,
 *     With GID1 length 5 bytes, if there are 2 sets of GID1 code, 
 *       1st GID1:  0x11, 0x22, 0x33, 0x44, 0x55
 *      2nd GID1:  0x66, 0x77, 0x88, 0x99, 0xAA
 *       You should set gid1_length = 5, gid1_set = 2, and assign gid1[20] as followed:
 *       gid1[20] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 
 *                        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
 * Important: Use '0xFF' as the rest element of gid1 array
 * 
 * You may extend the size of gid1[] array to support plenty sets of GID1 code as you want
 *****************************************************************************/
kal_bool is_gid1_matched(kal_uint8 *sim_gid1)
{
    /* Open GID1_SECURITY_CHECK */
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
#endif       


    /* Close GID1_SECURITY_CHECK, return KAL_TRUE */
//#if 0
      	return KAL_TRUE;
//#endif
    
}

/***************************************************************************** 
*  
*****************************************************************************/
kal_uint8 is_HW_VERIFICATION_enabled(void)
{
    return 0;
    // 0 - disable HW verification
    // 1 - enable for SIM1 only
    // 2 - enable for SIM2 only
}

/***************************************************************************** 
* Local Function of SMU
*****************************************************************************/

/* Load a new data object */


/*****************************************************************************
 * FUNCTION
 *  smu_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pobjFromlid     [?]     
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __GEMINI__
static kal_bool smu_load(void *pobjFromlid, kal_uint8 source)
#else
static kal_bool smu_load(void *pobjFromlid)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    if (smu_destory(source))
    {
        kal_print("SMU: previous obj not free!");
    }

    if (source==0)
    {
        nvram_ef_ms_security_obj_g.smu_security_info_ptr_0 = get_ctrl_buffer(sizeof(smu_security_info_struct));
        kal_mem_set((kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0, 0xFF, sizeof(smu_security_info_struct));
        kal_mem_cpy(
            (kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0,
            (kal_uint8*) pobjFromlid,
            sizeof(smu_security_info_struct));
        return KAL_TRUE;
    }
    else
    {
        nvram_ef_ms_security_obj_g.smu_security_info_ptr_1 = get_ctrl_buffer(sizeof(smu_security_info_struct));
        kal_mem_set((kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1, 0xFF, sizeof(smu_security_info_struct));
        kal_mem_cpy(
            (kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1,
            (kal_uint8*) pobjFromlid,
            sizeof(smu_security_info_struct));
        return KAL_TRUE;
    }

#else

    if (smu_destory())
    {
        kal_print("SMU: previous obj not free!");
    }

    nvram_ef_ms_security_obj_g.smu_security_info_ptr = get_ctrl_buffer(sizeof(smu_security_info_struct));
    kal_mem_set((kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr, 0xFF, sizeof(smu_security_info_struct));
    kal_mem_cpy(
        (kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr,
        (kal_uint8*) pobjFromlid,
        sizeof(smu_security_info_struct));
    return KAL_TRUE;
    
#endif

}

/* Update a the data object */


/*****************************************************************************
 * FUNCTION
 *  smu_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pobjTolid       [?]     
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __GEMINI__
static kal_bool smu_update(void *pobjTolid, kal_uint8 source)
#else
static kal_bool smu_update(void *pobjTolid)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    if (source==0)
    {
        ASSERT(nvram_ef_ms_security_obj_g.smu_security_info_ptr_0 != NULL);
        kal_mem_cpy(
            (kal_uint8*) pobjTolid,
            (kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0,
            sizeof(smu_security_info_struct));
        return KAL_TRUE;
    }
    else
    {
        ASSERT(nvram_ef_ms_security_obj_g.smu_security_info_ptr_1 != NULL);
        kal_mem_cpy(
            (kal_uint8*) pobjTolid,
            (kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1,
            sizeof(smu_security_info_struct));
        return KAL_TRUE;
    }

#else

    ASSERT(nvram_ef_ms_security_obj_g.smu_security_info_ptr != NULL);
    kal_mem_cpy(
        (kal_uint8*) pobjTolid,
        (kal_uint8*) nvram_ef_ms_security_obj_g.smu_security_info_ptr,
        sizeof(smu_security_info_struct));
    return KAL_TRUE;

#endif

}

/* Release the data object */


/*****************************************************************************
 * FUNCTION
 *  smu_destory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __GEMINI__
static kal_bool smu_destory(kal_uint8 source)
#else
static kal_bool smu_destory(void)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    if (source==0)
    {
        if (nvram_ef_ms_security_obj_g.smu_security_info_ptr_0 != NULL)
        {
            free_ctrl_buffer(nvram_ef_ms_security_obj_g.smu_security_info_ptr_0);
            return KAL_TRUE;
        }
        return KAL_FALSE;
    }
    else
    {
        if (nvram_ef_ms_security_obj_g.smu_security_info_ptr_1 != NULL)
        {
            free_ctrl_buffer(nvram_ef_ms_security_obj_g.smu_security_info_ptr_1);
            return KAL_TRUE;
        }
        return KAL_FALSE;
    }

#else

    if (nvram_ef_ms_security_obj_g.smu_security_info_ptr != NULL)
    {
        free_ctrl_buffer(nvram_ef_ms_security_obj_g.smu_security_info_ptr);
        return KAL_TRUE;
    }
    return KAL_FALSE;

#endif

}

/* Query the value of the item in kal_uint8 */


/*****************************************************************************
 * FUNCTION
 *  smu_query_u8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __GEMINI__
static kal_uint8 smu_query_u8(smu_item_enum eItem, kal_uint8 source)
#else
static kal_uint8 smu_query_u8(smu_item_enum eItem)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    smu_security_info_struct *info_ptr;

    if (source==0)
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0;
    else
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1;
    
#else

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            return info_ptr->security_indication;
            break;
        case SMU_AUTO_LOCK_ITEM_U8:
            return info_ptr->auto_lock_item;
            break;
        case SMU_PIN1_VALID_U8:
            return info_ptr->pin1_valid;
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            return info_ptr->phone_lock_verified;
            break;
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
        case SMU_PHONE_KEY_A:
        case SMU_LAST_IMSI_A:
        case SMU_PIN1_A:
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
    return 0;
}

/* Query the value of the item in kal_uint8[] */


/*****************************************************************************
 * FUNCTION
 *  smu_query_a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 *  pstrTo      [?]         
 *  chlen       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __GEMINI__

static void smu_query_a(smu_item_enum eItem, kal_uint8 *pstrTo, kal_uint8 chlen, kal_uint8 source)
#else
static void smu_query_a(smu_item_enum eItem, kal_uint8 *pstrTo, kal_uint8 chlen)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    smu_security_info_struct *info_ptr;

    if (source==0)
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0;
    else
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1;

#else

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr;

#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
        case SMU_AUTO_LOCK_ITEM_U8:
        case SMU_PIN1_VALID_U8:
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(0);
            break;
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
        case SMU_PHONE_KEY_A:
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(pstrTo, info_ptr->last_imsi, NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            kal_mem_cpy(pstrTo, info_ptr->pin1, NVRAM_EDITOR_NUM_PIN1);
            break;
	 case SMU_ICCID_A:
	     kal_mem_cpy(pstrTo, info_ptr->iccid, NVRAM_EDITOR_NUM_OF_BYTE_ICCID);
	     break;
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
}

/* Assign the value of the item in kal_uint8 */


/*****************************************************************************
 * FUNCTION
 *  smu_assign_u8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem       [IN]        
 *  chValue     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __GEMINI__
static void smu_assign_u8(smu_item_enum eItem, kal_uint8 chValue, kal_uint8 source)
#else
static void smu_assign_u8(smu_item_enum eItem, kal_uint8 chValue)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    smu_security_info_struct *info_ptr;

    if (source==0)
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0;
    else
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1;

#else

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            info_ptr->security_indication = chValue;
            break;
        case SMU_AUTO_LOCK_ITEM_U8:
            info_ptr->auto_lock_item = chValue;
            break;
        case SMU_PIN1_VALID_U8:
            info_ptr->pin1_valid = chValue;
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            info_ptr->phone_lock_verified = chValue;
            break;
        case SMU_REG_PS_KEY_A:
        case SMU_NP_CODE_A:
        case SMU_NP_KEY_A:
        case SMU_NSP_CODE_A:
        case SMU_NSP_KEY_A:
        case SMU_NP_OF_SP_A:
        case SMU_NP_OF_CP_A:
        case SMU_GID1_A:
        case SMU_GID2_A:
        case SMU_SP_KEY_A:
        case SMU_CP_KEY_A:
        case SMU_IMSI_CODE_A:
        case SMU_IMSI_KEY_A:
        case SMU_PHONE_KEY_A:
        case SMU_LAST_IMSI_A:
        case SMU_PIN1_A:
        default:
            //ASSERT(0);  /* drop through! Wrong items */
            break;
    }
}

/* Assign the value of the item in string with length */


/*****************************************************************************
 * FUNCTION
 *  smu_assign_a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem           [IN]        
 *  pstrValue       [?]         
 *  chlen           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __GEMINI__
static void smu_assign_a(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen, kal_uint8 source)
#else
static void smu_assign_a(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__

    smu_security_info_struct *info_ptr;

    if (source==0)
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0;
    else
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1;

#else

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr;

#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
        case SMU_AUTO_LOCK_ITEM_U8:
        case SMU_PIN1_VALID_U8:
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(0);
            break;
        case SMU_REG_PS_KEY_A:
            break;
        case SMU_NP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_NP_KEY_A:
            break;
        case SMU_NSP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NSP);
            kal_mem_cpy(info_ptr->nsp_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NSP);
        case SMU_NSP_KEY_A:
            break;
        case SMU_NP_OF_SP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_of_sp, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_NP_OF_CP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            kal_mem_cpy(info_ptr->np_of_cp, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_NP);
            break;
        case SMU_GID1_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            kal_mem_cpy(info_ptr->gid1, pstrValue, chlen);
            break;
        case SMU_GID2_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            kal_mem_cpy(info_ptr->gid2, pstrValue, chlen);
            break;
        case SMU_SP_KEY_A:
            break;
        case SMU_CP_KEY_A:
            break;
        case SMU_IMSI_CODE_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(info_ptr->imsi_code, pstrValue, chlen);
            break;
        case SMU_IMSI_KEY_A:
            break;
        case SMU_PHONE_KEY_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            kal_mem_cpy(info_ptr->phone_key, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            kal_mem_cpy(info_ptr->last_imsi, pstrValue, chlen);
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            kal_mem_cpy(info_ptr->pin1, pstrValue, NVRAM_EDITOR_NUM_PIN1);
            break;
	 case SMU_ICCID_A:
	     kal_mem_cpy(info_ptr->iccid, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_ICCID);
	     break;
        default:
            //ASSERT(0);
            break;
    }
}

/* Compare the string with the data item */


/*****************************************************************************
 * FUNCTION
 *  smu_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eItem           [IN]        
 *  pstrValue       [?]         
 *  chlen           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __GEMINI__
static kal_bool smu_match(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen, kal_uint8 source)
#else
static kal_bool smu_match(smu_item_enum eItem, kal_uint8 *pstrValue, kal_uint8 chlen)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 idx = 0;

#ifdef __GEMINI__

    smu_security_info_struct *info_ptr;

    if (source==0)
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_0;
    else
        info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr_1;

#else

    smu_security_info_struct *info_ptr = (smu_security_info_struct*) nvram_ef_ms_security_obj_g.smu_security_info_ptr;

#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(NULL != info_ptr);
    switch (eItem)
    {
        case SMU_SECURITY_INDICATION_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->security_indication == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_AUTO_LOCK_ITEM_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->auto_lock_item == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PIN1_VALID_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->pin1_valid == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PHONE_LOCK_VERIFIED_U8:
            //ASSERT(chlen == sizeof(kal_uint8));
            if (info_ptr->phone_lock_verified == *pstrValue)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_REG_PS_KEY_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->reg_ps_key, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_KEY) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            for (idx = 0; idx < NVRAM_EDITOR_NUM_NP; idx++)
            {
                if (kal_mem_cmp(
                        pstrValue,
                        (kal_uint8*) & (info_ptr->np_code[idx * NVRAM_EDITOR_NUM_OF_BYTE_NP]),
                        NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
                {
                    return KAL_TRUE;    /* Find one! */
                }
            }
            return KAL_FALSE;
            break;
        case SMU_NP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->np_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NSP_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NSP);
            for (idx = 0; idx < NVRAM_EDITOR_NUM_NSP; idx++)
            {
                if (kal_mem_cmp(
                        pstrValue,
                        (kal_uint8*) & (info_ptr->nsp_code[idx * NVRAM_EDITOR_NUM_OF_BYTE_NSP]),
                        NVRAM_EDITOR_NUM_OF_BYTE_NSP) == 0)
                {
                    return KAL_TRUE;    /* Find one! */
                }
            }
            return KAL_FALSE;
            break;
        case SMU_NSP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->nsp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_OF_SP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            if (kal_mem_cmp(pstrValue, info_ptr->np_of_sp, NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_NP_OF_CP_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_NP);
            if (kal_mem_cmp(pstrValue, info_ptr->np_of_cp, NVRAM_EDITOR_NUM_OF_BYTE_NP) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_GID1_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            if (kal_mem_cmp(info_ptr->gid1, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_GID2_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_GID);
            if (kal_mem_cmp(info_ptr->gid2, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_SP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->sp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_CP_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->cp_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_IMSI_CODE_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            if (kal_mem_cmp(info_ptr->imsi_code, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_IMSI) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_IMSI_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->imsi_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PHONE_KEY_A:
            //ASSERT(chlen <= NVRAM_EDITOR_NUM_OF_BYTE_KEY);
            if (kal_mem_cmp(info_ptr->phone_key, pstrValue, chlen) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_LAST_IMSI_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_OF_BYTE_IMSI);
            if (kal_mem_cmp(info_ptr->last_imsi, pstrValue, NVRAM_EDITOR_NUM_OF_BYTE_IMSI) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;
        case SMU_PIN1_A:
            //ASSERT(chlen == NVRAM_EDITOR_NUM_PIN1);
            if (kal_mem_cmp(info_ptr->pin1, pstrValue, NVRAM_EDITOR_NUM_PIN1) == 0)
            {
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
            break;

	 case SMU_ICCID_A:
	     if(kal_mem_cmp(info_ptr->iccid,
			           pstrValue,
			           NVRAM_EDITOR_NUM_OF_BYTE_ICCID) == 0)
		    return KAL_TRUE;
	     else
		    return KAL_FALSE;
		break;

        default:
            //ASSERT(0);
            break;
    }
    return KAL_FALSE;
}

/* END: PH smu_security_info_struct (NVRAM_EF_MS_SECURITY_LID)  */

/* Define your Block list here!! */
/***************************************************************************** 
 * For example 2 digits MNC case: MCC\MNC 466 97 => 0x46 0x69 0x7F 
 *             3 digits MNC case: MCC\MNC 466 285 => 0x46 0x62 0x85
 * !!!IMPORTANT: USE three 0xFF at the end of array to terminate !!! 
 *****************************************************************************/
static const kal_uint8 smlVISA[] = {
/* Insert your items here */

//0x46, 0x61, 0x1F,   // Item 1
//0x46, 0x69, 0x2F,   // Item 2

/* Do not modify the 0xFF 0xFF 0xFF below */
0xFF, 0xFF, 0xFF }; // Do not modify this line!



/* BEGIN: PH sml_context_struct (NVRAM_EF_SML_LID) */
/******************************************************************************
 * New SML Architecture
 *****************************************************************************/
/******************************************************************************
 *    typedef struct {
 *        kal_uint32  magic_head;
 *        sml_category_meta_struct    cat[SML_CAT_SIZE];
 *        sml_control_key_struct      key[SML_CAT_SIZE];
 *        kal_uint8   code_cat_n[SML_CFG_CAT_N_SIZE];
 *        kal_uint8   code_cat_ns[SML_CFG_CAT_NS_SIZE];
 *        kal_uint8   code_cat_sp[SML_CFG_CAT_SP_SIZE];
 *        kal_uint8   code_cat_c[SML_CFG_CAT_C_SIZE];
 *        kal_uint8   code_cat_sim[SML_CFG_CAT_SIM_SIZE];
 *        kal_uint8   code_cat_ns_sp[SML_CFG_CAT_NS_SP_SIZE];
 *        kal_uint8   code_cat_sim_c[SML_CFG_CAT_SIM_C_SIZE];
 *        kal_uint8   range_cat_ns[SML_CAT_NS_RANGE_SIZE]
 *        kal_uint32 magic_tail;         
 *    } sml_context_struct;
 *****************************************************************************/ 

/***************************************************************************** 
 * Typedef of SML
 *****************************************************************************/
#ifdef __GEMINI__
static void sml_give( void * pLidToObj, kal_uint8 source );
static void sml_take( void * pObjToLid, kal_uint8 source );
static void sml_destory( kal_uint8 source );
static void * sml_getItem( sml_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength,
                           kal_uint8 source
                         );
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength,
                         kal_uint8 source
                       );
#else
static void sml_give( void * pLidToObj );
static void sml_take( void * pObjToLid );
static void sml_destory( void );
static void * sml_getItem( sml_cat_enum cat, 
                           sml_ctx_enum item, 
                           kal_uint16 * plength 
                         );
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void * pItem, 
                         kal_uint16 * plength 
                       );
#endif

/* define the Local variable of SML object */
static nvram_ef_sml_obj_struct SMLOBJ = {
#ifdef __GEMINI__
    NULL,    
    NULL,    
#else
    NULL,    
#endif
    sml_give,
    sml_take,
    sml_destory,
    sml_getItem,
    sml_putItem
};

/* define the Global access pointer of SML object */
nvram_ef_sml_obj_struct * pSMLg = &SMLOBJ;

/*******************************************************************************
 * Define the method of the object
 *******************************************************************************/
/*******************************************************************************
 * FUNCTION  
 *  sml_give
 * DESCRIPTION
 *  This method copys the LID files read from NVRAM to the SML obj
 * PARAMETERS
 *  IN          * pLidToObj
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
#ifdef __GEMINI__
sml_context_struct * sml_context_switch(kal_uint8 source)
{
    if (source==0)
        return pSMLg->pObj_0;
    else
        return pSMLg->pObj_1;
}
#endif

#ifdef __GEMINI__
static void sml_give( void *pLidToObj, kal_uint8 source )
#else
static void sml_give( void *pLidToObj )
#endif
{
    
    kal_uint32 magic_head = 0;
    
    kal_uint32 magic_tail = 0;
    
    sml_context_struct * pObj = NULL;
    
#ifdef __GEMINI__

    sml_context_struct * pObj_temp = NULL;
    pObj_temp = sml_context_switch(source);

    if(NULL != pObj_temp)
    {
    
        kal_print("SML: object is exist!");
    
        free_ctrl_buffer(pObj_temp);
        
        pObj_temp = NULL;
    
    }

#else

    if(NULL != pSMLg->pObj)
    {
    
        kal_print("SML: object is exist!");
    
        free_ctrl_buffer(pSMLg->pObj);
        
        pSMLg->pObj = NULL;
    
    }
    
#endif
       
    pObj = (sml_context_struct *) get_ctrl_buffer(sizeof(sml_context_struct));
    
    kal_mem_cpy(pObj,
                pLidToObj,
                sizeof(sml_context_struct)
                ); 
    
    /* Check magic head and tail */
    magic_head = pObj->magic_head;
    
    magic_tail = pObj->magic_tail;

//  Mark for temporary solution of SIM-ME-Lock
    ASSERT((magic_head == sizeof(sml_context_struct))
           && (magic_tail == SML_MAGIC_TAIL_VALUE));
    
#ifdef __GEMINI__
    if (source==0)
            pSMLg->pObj_0 = pObj;
    else
            pSMLg->pObj_1 = pObj;
#else
    pSMLg->pObj = pObj;
#endif

}

/*******************************************************************************
 * FUNCTION  
 *  sml_take
 * DESCRIPTION
 *  This method copys the contex of the SML object to the provided NVRAM LID.
 * PARAMETERS
 *  OUT         * pObjToLid
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
#ifdef __GEMINI__
static void sml_take( void *pObjToLid, kal_uint8 source )
#else
static void sml_take( void *pObjToLid )
#endif
{
    
    kal_uint32 magic_head = 0;
    
    kal_uint32 magic_tail = 0;
    
#ifdef __GEMINI__
    sml_context_struct * pObj = (sml_context_struct *) sml_context_switch(source);
#else
    sml_context_struct * pObj = (sml_context_struct *) pSMLg->pObj;
#endif
     
    /* Check magic head and tail */
    magic_head = pObj->magic_head;
    
    magic_tail = pObj->magic_tail;

//  Mark for temporary solution of SIM-ME-Lock
//    ASSERT((magic_head == SML_MAGIC_HEAD_VALUE)
//           && (magic_tail == SML_MAGIC_TAIL_VALUE));
           
    kal_mem_cpy(pObjToLid,
                pObj,
                sizeof(sml_context_struct)
                );

} 

/*******************************************************************************
 * FUNCTION  
 *  sml_destory
 * DESCRIPTION
 *  This method free the SML object in memory if it is not used.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/    
#ifdef __GEMINI__
static void sml_destory(kal_uint8 source )
#else
static void sml_destory( void )
#endif
{
#ifdef __GEMINI__

    sml_context_struct * pObj = (sml_context_struct *) sml_context_switch(source);

    if(NULL != pObj)
        free_ctrl_buffer(pObj);
    
    pObj = NULL;

#else

    if(NULL != pSMLg->pObj)
        free_ctrl_buffer(pSMLg->pObj);
    
    pSMLg->pObj = NULL;
    
#endif
}

/*******************************************************************************
 * FUNCTION  
 *  sml_getItem
 * DESCRIPTION
 *  This method returns the structure pointer and length of the structure
 *  of the desired SML object items.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  OUT         *length
 * RETURN
 *  void *
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/
#ifdef __GEMINI__
static void * sml_getItem( sml_cat_enum category, 
                           sml_ctx_enum item, 
                           kal_uint16 *plength,
                           kal_uint8 source)
#else
static void * sml_getItem( sml_cat_enum category, 
                           sml_ctx_enum item, 
                           kal_uint16 *plength )
#endif
{
    
#ifdef __GEMINI__
    sml_context_struct *pObj = (sml_context_struct *) sml_context_switch(source);
#else
    sml_context_struct *pObj = (sml_context_struct *) pSMLg->pObj;
#endif
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        
        case SML_MAGIC_HEAD:
        
        case SML_MAGIC_TAIL:
        
            //ASSERT(0);
        
            break;
        
        case SML_CAT_META:
        
            *plength = sizeof(sml_category_meta_struct);
        
            return (sml_category_meta_struct *) &(pObj->cat[category]);
        
            break;
        
        case SML_CAT_KEY:
        
            *plength = sizeof(sml_control_key_struct);
        
            return (sml_control_key_struct *) &(pObj->key[category]);
        
            break;
        
        case SML_CAT_CODE:
        
            switch(category)
            {
        
                case SML_CAT_N:
        
                    *plength = SML_CFG_CAT_N_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_n[0]);
        
                    break;
        
                case SML_CAT_NS:
        
                    *plength = SML_CFG_CAT_NS_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_ns[0]);
        
                    break;
        
                case SML_CAT_SP:
        
                    *plength = SML_CFG_CAT_SP_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sp[0]);
        
                    break;
        
                case SML_CAT_C:
        
                    *plength = SML_CFG_CAT_C_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_c[0]);
        
                    break;
        
                case SML_CAT_SIM:
        
                    *plength = SML_CFG_CAT_SIM_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sim[0]);
        
                    break;
        
                case SML_CAT_NS_SP:
        
                    *plength = SML_CFG_CAT_NS_SP_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_ns_sp[0]);
        
                    break;
        
                case SML_CAT_SIM_C:
        
                    *plength = SML_CFG_CAT_SIM_C_SIZE;
        
                    return (kal_uint8 *) &(pObj->code_cat_sim_c[0]);
        
                    break;
        
            }
        
            break;
        
        case SML_CAT_RANGE:
        
            switch(category)
            {

                case SML_CAT_N:
                    
                    *plength = 0;
                    
                    return NULL;
                    
                    break;

                case SML_CAT_NS:
                    
                    *plength = SML_CAT_NS_RANGE_SIZE;
                    
                    return (kal_uint8 *) &(pObj->range_cat_ns[0]);

                    break;

                case SML_CAT_SP:

                    *plength = 0;
                    
                    return NULL;
                    
                    break;

                case SML_CAT_C:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_SIM:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_NS_SP:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

                case SML_CAT_SIM_C:
                    
                    *plength = 0;
                    
                    return NULL;

                    break;

            }            

            break;

        default:
                
            break;   

    }

    return NULL;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_putItem
 * DESCRIPTION
 *  This method set the desired items of the SML object.
 * PARAMETERS
 *  IN          cat
 *  IN          item
 *  IN          *pItem
 *  IN          *plength
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength,
                         kal_uint8 source)

#else
static void sml_putItem( sml_cat_enum cat, 
                         sml_ctx_enum item, 
                         void *pItem, 
                         kal_uint16 *plength )
#endif
{
    
#ifdef __GEMINI__
    sml_context_struct *pObj = (sml_context_struct *) sml_context_switch(source);
#else
    sml_context_struct *pObj = (sml_context_struct *) pSMLg->pObj;
#endif
    
    ASSERT(NULL != pObj);
    
    switch(item)
    {
        
        case SML_MAGIC_HEAD:
        
        case SML_MAGIC_TAIL:
        
            //ASSERT(0);
        
            break;
        
        case SML_CAT_META:
        
            //ASSERT(*plength == sizeof(sml_category_meta_struct));
            
            kal_mem_cpy(&(pObj->cat[cat]),
                        pItem,
                        *plength
                        );
        
            break;
        
        case SML_CAT_KEY:
        
            //ASSERT(*plength == sizeof(sml_control_key_struct));
        
            kal_mem_cpy(&(pObj->key[cat]),
                        pItem,
                        *plength
                        );
        
            break;
        
        case SML_CAT_CODE:
        
            switch(cat)
            {
        
                case SML_CAT_N:
        
                    //ASSERT(*plength <= SML_CFG_CAT_N_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_n[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_NS:
        
                    //ASSERT(*plength <= SML_CFG_CAT_NS_SIZE);
                    
                    kal_mem_cpy(&(pObj->code_cat_ns[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SP:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SP_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sp[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_C:
        
                    //ASSERT(*plength <= SML_CFG_CAT_C_SIZE);
                            
                    kal_mem_cpy(&(pObj->code_cat_c[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SIM:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SIM_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sim[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_NS_SP:
        
                    //ASSERT(*plength <= SML_CFG_CAT_NS_SP_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_ns_sp[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
                case SML_CAT_SIM_C:
        
                    //ASSERT(*plength <= SML_CFG_CAT_SIM_C_SIZE);
        
                    kal_mem_cpy(&(pObj->code_cat_sim_c[0]),
                                pItem,
                                *plength
                                );
        
                    break;
        
            }
        
            break;
        
        case SML_CAT_RANGE:
        
            switch(cat)
            {

                case SML_CAT_N:

                    break;

                case SML_CAT_NS:

                    //ASSERT(*plength <= SML_CAT_NS_RANGE_SIZE);
                    
                    kal_mem_cpy(&(pObj->range_cat_ns[0]),
                                pItem,
                                *plength
                                );

                    break;

                case SML_CAT_SP:

                    break;

                case SML_CAT_C:

                    break;

                case SML_CAT_SIM:

                    break;

                case SML_CAT_NS_SP:

                    break;

                case SML_CAT_SIM_C:

                    break;

            }            

            break;

        default:

            break;   

    }
    
}

/* Define the Global handler of SML */
/*******************************************************************************
 * FUNCTION  
 *  sml_Load
 * DESCRIPTION
 *  This function loads the SML obj from NVRAM LID (NVRAM_READ_CNF)
 * PARAMETERS
 *  IN          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_uint16 sml_Load( void *pLid, kal_uint8 source )
#else
kal_uint16 sml_Load( void *pLid )
#endif
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    kal_uint16 length = sizeof(sml_context_struct);

#ifdef __GEMINI__
    /* Clean the old ones */
    (*p->destory)(source);

    /* Load the new one */
    (*p->give)(pLid, source);
#else
    /* Clean the old ones */
    (*p->destory)();

    /* Load the new one */
    (*p->give)(pLid);
#endif

    return length;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Save
 * DESCRIPTION
 *  This function saves the SML obj to NVRAM LID (NVRAM_WRITE_REQ)
 * PARAMETERS
 *  OUT          pLid
 * RETURN
 *  kal_uint16  Obj size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_uint16 sml_Save( void *pLid, kal_uint8 source )
#else
kal_uint16 sml_Save( void *pLid )
#endif
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    kal_uint16 length = sizeof(sml_context_struct);

#ifdef __GEMINI__
    (*p->take)(pLid, source);
#else
    (*p->take)(pLid);
#endif

    return length;
    
}


/*******************************************************************************
 * FUNCTION  
 *  sml_Unlock
 * DESCRIPTION
 *  This function unlock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Unlock( sml_cat_enum cat, 
                     kal_uint8 *key, 
                     kal_uint8 key_len,
                     kal_uint8 source)
#else
kal_bool sml_Unlock( sml_cat_enum cat, 
                     kal_uint8 *key, 
                     kal_uint8 key_len )
#endif                     
{
    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length);
#endif
    
    if((meta->state == SML_STATE_LOCK)&&(meta->retry_count > 0))
    {
        
        if(kal_mem_cmp(&(catkey->key[0]),key,key_len))
        {
            
            meta->retry_count--;
            
            /* Fail! Passwd not match! return KAL_FALSE; */
            
        }
        else
        {
            
            /* Success! return KAL_TRUE; */

            result = KAL_TRUE;

            meta->state = SML_STATE_UNLOCK;

            switch(cat)
            {
                
                case SML_CAT_N:
                
                    meta->retry_count = SML_RETRY_COUNT_N_CAT;
                    
                break;
                case SML_CAT_NS:
 
                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                    
                break;
                case SML_CAT_SP:
                    
                    meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                    
                break;
                case SML_CAT_C:
                    
                    meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                    
                break;
                case SML_CAT_SIM:
                   
                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                    
                break;
                case SML_CAT_NS_SP:
                    
                    meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                    
                break;
                case SML_CAT_SIM_C:
                    
                    meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                    
                break;    
                default:
                break;
                
            }           
                      
        }
        
    }

    return result;
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Lock
 * DESCRIPTION
 *  This function Lock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Lock( sml_cat_enum cat, 
                   kal_uint8 *key, 
                   kal_uint8 key_len,
                   kal_uint8 source)
#else
kal_bool sml_Lock( sml_cat_enum cat, 
                   kal_uint8 *key, 
                   kal_uint8 key_len )
#endif                   
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    

#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
 
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length); 
#endif

    /* 
     * Perform Key state check. If the key is default SET, it must be equal 
     * to the key provided by the user. If it is not, the key will be set as 
     * the key provided by the user.
     */

    ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );
    
    if( SML_KEY_SET == catkey->state )
    {
    
        if( 0 == kal_mem_cmp(catkey->key,key,key_len) ) 
            result = KAL_TRUE;

    }
    else
    {
    
        result = KAL_TRUE;

    }

    /* Change the SML state if the category is not empty */
    
    if( (SML_STATE_UNLOCK == meta->state) 
        &&(KAL_TRUE == result) )
    {
    
        if( meta->num > 0 )
        {
        
            if( SML_KEY_EMPTY == catkey->state )
            {
            
                kal_mem_cpy(catkey->key,key,key_len);

            }

            meta->state = SML_STATE_LOCK;

        }
        else
        {
        
            kal_print("SML: The category is empty!");

            result = KAL_FALSE;

        }

    }
    else
    {

        result = KAL_FALSE;
    
    }
 
    return result;
    
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Add
 * DESCRIPTION
 *  This function is used to add code into the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          * code
 *  IN          len
 *  IN          * key
 *  IN          key_len
 *  OUT         * remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Add( sml_cat_enum cat, 
                  kal_uint8 *code, 
                  kal_uint8 len,
                  kal_uint8 *key,
                  kal_uint8 key_len,
                  kal_uint8 *remain,
                  kal_uint8 source)
#else
kal_bool sml_Add( sml_cat_enum cat, 
                  kal_uint8 *code, 
                  kal_uint8 len,
                  kal_uint8 *key,
                  kal_uint8 key_len,
                  kal_uint8 *remain )
#endif                  
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__    
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length); 
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length);
#endif

    switch(cat)
    {
        
        case SML_CAT_N:

            //ASSERT(SML_SIZE_OF_CAT_N == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
            *remain = (length - offset) / SML_SIZE_OF_CAT_N;
                    
        break;
        
        case SML_CAT_NS:

            //ASSERT(SML_SIZE_OF_CAT_NS == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

            *remain = (length - offset) / SML_SIZE_OF_CAT_NS;        
            
        break;
        
        case SML_CAT_SP:
            
            //ASSERT(SML_SIZE_OF_CAT_SP == len);

            offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

            *remain = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
        break;

        case SML_CAT_C:

            //ASSERT(SML_SIZE_OF_CAT_C == len);
                        
            offset = (meta->num) * SML_SIZE_OF_CAT_C;   

            *remain = (length - offset) / SML_SIZE_OF_CAT_C;                
            
        break;
        
        case SML_CAT_SIM:

           //ASSERT(SML_SIZE_OF_CAT_SIM == len);
           
           offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

            *remain = (length - offset) / SML_SIZE_OF_CAT_SIM;               
            
        break;
        
        case SML_CAT_NS_SP:

            //ASSERT(SML_SIZE_OF_LINK_NS_SP == len);

            offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

            *remain = (length - offset) / SML_SIZE_OF_LINK_NS_SP;                    
            
        break;
        
        case SML_CAT_SIM_C:
            
            //ASSERT(SML_SIZE_OF_LINK_SIM_C == len);
            
            offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

            *remain = (length - offset) / SML_SIZE_OF_LINK_SIM_C;                
            
        break;    
        
        default:
            
        break;
        
    }           

    /* 
     * Perform Key state check. If the key is default SET, it must be equal 
     * to the key provided by the user. If it is not, the key will be set as 
     * the key provided by the user.
     */

    //ASSERT( key_len <= SML_MAX_SUPPORT_KEY_LEN );
    
    if( SML_KEY_SET == catkey->state )
    {
    
        if( 0 == kal_mem_cmp(catkey->key,key,key_len) ) 
            result = KAL_TRUE;

    }
    else
    {
    
        result = KAL_TRUE;

    }    
    
    /* Check if the space is available */
    if( (*remain > 0)
        && (SML_STATE_UNLOCK == meta->state)
        && (KAL_TRUE == result) )
    {

        if(SML_KEY_EMPTY == catkey->state)
        {
        
            kal_mem_cpy(catkey->key,key,key_len);
            
        }

        kal_mem_cpy((kal_uint8 *)(pdata+offset),
                    code,
                    len
                    );
        
        meta->num ++;

        (*remain)--;

        meta->state = SML_STATE_LOCK;
        
    }
    else
    {

        kal_print("SML: Add fail!");
    
        result = KAL_FALSE;

    }
    
    return result;

}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Remove
 * DESCRIPTION
 *  This function is used to remove the desired category
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Remove( sml_cat_enum cat, kal_uint8 source )
#else
kal_bool sml_Remove( sml_cat_enum cat )
#endif
{

    nvram_ef_sml_obj_struct * p = pSMLg;

    sml_category_meta_struct * meta = NULL;

    sml_control_key_struct * catkey = NULL;

    kal_uint8 * pdata = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length);
#endif

    if( SML_STATE_UNLOCK == meta->state )
    {

        kal_mem_set(pdata,0xFF,length);

        if( SML_KEY_EMPTY == catkey->state )
        {

            kal_mem_set(catkey->key,0xFF,SML_MAX_SUPPORT_KEY_LEN);
            
        }

        meta->num = 0;

        result = KAL_TRUE;

    }
    
    return result;
    
}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Disable
 * DESCRIPTION
 *  This function is used to disable the desired category
 * PARAMETERS
 *  IN          cat
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Disable( sml_cat_enum cat, kal_uint8 source )
#else
kal_bool sml_Disable( sml_cat_enum cat )
#endif
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
#endif
 
    if( SML_STATE_UNLOCK == meta->state )
    {
    
        meta->state = SML_STATE_DISABLE;

        result = KAL_TRUE;
        
    }
    
    return result;

}
 
/*******************************************************************************
 * FUNCTION  
 *  sml_Reset
 * DESCRIPTION
 *  This function is used to reset the retry counter
 * PARAMETERS
 *  IN          cat
 *  IN          * key
 *  IN          key_len
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Reset( sml_cat_enum cat, 
                    kal_uint8 *key, 
                    kal_uint8 key_len,
                    kal_uint8 source)
#else
kal_bool sml_Reset( sml_cat_enum cat, 
                    kal_uint8 *key, 
                    kal_uint8 key_len )
#endif
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint16 length = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source);  
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length);  
#endif

    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Status
 * DESCRIPTION
 *  This function is used to query the status of the category
 * PARAMETERS
 *  IN          cat
 *  OUT         *state 
 *  OUT         *retry_count
 *  OUT         *num_of_sets
 *  OUT         *space_of_sets
 *  OUT         *key_state
 *  OUT         *auto_lock_count
 * RETURN
 *  void
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
void sml_Status( sml_cat_enum cat, 
                 kal_uint8 *state,
                 kal_uint8 *retry_count,
                 kal_uint8 *num_of_sets,
                 kal_uint8 *space_of_sets,
                 kal_uint8 *key_state,
                 kal_uint8 *auto_lock_count,
                 kal_uint8 source)
#else
void sml_Status( sml_cat_enum cat, 
                 kal_uint8 *state,
                 kal_uint8 *retry_count,
                 kal_uint8 *num_of_sets,
                 kal_uint8 *space_of_sets,
                 kal_uint8 *key_state,
                 kal_uint8 *auto_lock_count)
#endif                 
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 
   
#ifdef __GEMINI__   
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length); 
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length);
#endif

    if(state)
        *state = meta->state;
    
    if(retry_count)
        *retry_count = meta->retry_count;
    
    if(num_of_sets)
        *num_of_sets = meta->num;
    
    if(key_state)
        *key_state = catkey->state;

    if(auto_lock_count)
        *auto_lock_count = meta->autolock_count;

    if(space_of_sets)
    {
        switch(cat)
        {
        
            case SML_CAT_N:

            offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
            *space_of_sets = (length - offset) / SML_SIZE_OF_CAT_N;
                    
            break;
        
            case SML_CAT_NS:

            offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_NS;        
            
            break;
        
            case SML_CAT_SP:
            
            offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
            break;

            case SML_CAT_C:
                        
            offset = (meta->num) * SML_SIZE_OF_CAT_C;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_C;                
            
            break;
        
            case SML_CAT_SIM:
           
            offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

            *space_of_sets  = (length - offset) / SML_SIZE_OF_CAT_SIM;               
            
            break;
        
            case SML_CAT_NS_SP:

            offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_LINK_NS_SP;                    
            
            break;
        
            case SML_CAT_SIM_C:
                        
            offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

            *space_of_sets  = (length - offset) / SML_SIZE_OF_LINK_SIM_C;                
            
            break;    
        
            default:
            
            break; 
            
        }         
    }

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Autolock
 * DESCRIPTION
 *  This function is used to autolock the desired category
 * PARAMETERS
 *  IN          cat
 *  IN          *code
 *  IN          len
 *  OUT          *remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Autolock( sml_cat_enum cat, 
                       kal_uint8 *code,
                       kal_uint8 len,
                       kal_uint8 *remain,
                       kal_uint8 source)
#else
kal_bool sml_Autolock( sml_cat_enum cat, 
                       kal_uint8 *code,
                       kal_uint8 len,
                       kal_uint8 *remain )
#endif                       
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length);
#endif

    if((meta->state != SML_STATE_AUTOLOCK)||
       (meta->autolock_count == 0))
    {
    
        *remain = 0;

        return KAL_FALSE;

    }
    
    switch(cat)
    {
        
        case SML_CAT_N:

            if(SML_SIZE_OF_CAT_N == len)
            {
            
                offset = (meta->num) * SML_SIZE_OF_CAT_N;
            
                *remain = (length - offset) / SML_SIZE_OF_CAT_N;

                result = KAL_TRUE;

            }
                    
        break;
        
        case SML_CAT_NS:

            if(SML_SIZE_OF_CAT_NS == len)
            {
                
                offset = (meta->num) * SML_SIZE_OF_CAT_NS;        

                *remain = (length - offset) / SML_SIZE_OF_CAT_NS;    

                result = KAL_TRUE;

            }
            
        break;
        
        case SML_CAT_SP:
            
            if(SML_SIZE_OF_CAT_SP == len)
            {

                offset = (meta->num) * SML_SIZE_OF_CAT_SP;        

                *remain = (length - offset) / SML_SIZE_OF_CAT_SP;        
            
                result = KAL_TRUE;

            }

        break;

        case SML_CAT_C:

            if(SML_SIZE_OF_CAT_C == len)
            {
            
                offset = (meta->num) * SML_SIZE_OF_CAT_C;   

                *remain = (length - offset) / SML_SIZE_OF_CAT_C;                

                result = KAL_TRUE;

            }

        break;
        
        case SML_CAT_SIM:

           if(SML_SIZE_OF_CAT_SIM == len)
           {

                offset = (meta->num) * SML_SIZE_OF_CAT_SIM;  

                *remain = (length - offset) / SML_SIZE_OF_CAT_SIM; 
                
                result = KAL_TRUE;
           }            

        break;
        
        case SML_CAT_NS_SP:

            if(SML_SIZE_OF_LINK_NS_SP == len)
            {

                offset = (meta->num) * SML_SIZE_OF_LINK_NS_SP;   

                *remain = (length - offset) / SML_SIZE_OF_LINK_NS_SP; 

                result = KAL_TRUE;
                
            }
            
        break;
        
        case SML_CAT_SIM_C:
            
            if(SML_SIZE_OF_LINK_SIM_C == len)
            {

                offset = (meta->num) * SML_SIZE_OF_LINK_SIM_C;   

                *remain = (length - offset) / SML_SIZE_OF_LINK_SIM_C;  
                
                result = KAL_TRUE;

            }
            
        break;    
        
        default:
            
        break;
        
    }           

    if(result == KAL_FALSE)
    {

        *remain = meta->autolock_count;
        
        return KAL_FALSE;
        
    }
    
    /* Check if the space is available */
    if(*remain > 0)
    {

        kal_mem_cpy((kal_uint8 *)(pdata+offset),
                    code,
                    len
                    );
        
        meta->num ++;

        meta->autolock_count--;

        if(meta->autolock_count == 0)
        {

            meta->state = SML_STATE_LOCK;

            kal_print("SML: Autolock finished!");

        }

        *remain = meta->autolock_count;

        result = KAL_TRUE;
        
    }
    else
    {

        kal_print("SML: Autolock fail! Clean remain count!");

        meta->autolock_count = 0;
        
        meta->state = SML_STATE_LOCK;

        result = KAL_TRUE;
        
    }
    
    return result;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Check
 * DESCRIPTION
 *  This function is used to check if the code is in the Pass list
 * PARAMETERS
 *  IN          cat
 *  IN          *code
 *  IN          len
 *  OUT          *remain
 * RETURN
 *  kal_bool
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Check( sml_cat_enum cat, 
                    kal_uint8 *code,
                    kal_uint8 len,
                    kal_uint8 *remain,
                    kal_uint8 source)
#else
kal_bool sml_Check( sml_cat_enum cat, 
                    kal_uint8 *code,
                    kal_uint8 len,
                    kal_uint8 *remain )
#endif
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    kal_uint8 *pdata = NULL;

    kal_uint8 idx = 0;

    kal_uint16 length = 0, offset = 0; 

    kal_bool result = KAL_FALSE;
    
#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length, source);
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    pdata = (kal_uint8 *) (*p->getItem)(cat,SML_CAT_CODE,&length);
#endif

    *remain = meta->retry_count;

    if(SML_STATE_LOCK != meta->state)
    {
    
        /* ALWAYS PASSED if the category is not locked! */
        
        return KAL_TRUE;

    }

    switch(cat)
    {
        
        case SML_CAT_N:

            if(SML_SIZE_OF_CAT_N == len)
            {
                      
                for(idx = 0; idx < meta->num; idx++)
                {

                    offset = idx * SML_SIZE_OF_CAT_N;
                
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {
                    
                        result = KAL_TRUE;

                        break;

                    }
                    
                }

            }
                    
        break;
        
        case SML_CAT_NS:

            if(SML_SIZE_OF_CAT_NS == len)
            {
                
                for(idx = 0; idx < meta->num; idx++)
                {

                    offset = idx * SML_SIZE_OF_CAT_NS;
                
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {

                        result = KAL_TRUE;

                        break;

                    }
                    
                }

            }
            
        break;
        
        case SML_CAT_SP:
            
            if(SML_SIZE_OF_CAT_SP == len)
            {

                for(idx = 0; idx < meta->num; idx++)
                {

                    offset = idx * SML_SIZE_OF_CAT_SP;
                
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {

                        result = KAL_TRUE;

                        break;

                    }
                    
                }

            }

        break;

        case SML_CAT_C:

            if(SML_SIZE_OF_CAT_C == len)
            {
            
                for(idx = 0; idx < meta->num; idx++)
                {
            
                    offset = idx * SML_SIZE_OF_CAT_C;
            
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {
            
                        result = KAL_TRUE;
            
                        break;
            
                    }
                
                }
                
            }

        break;
        
        case SML_CAT_SIM:

           if(SML_SIZE_OF_CAT_SIM == len)
           {

                for(idx = 0; idx < meta->num; idx++)
                {

                    offset = idx * SML_SIZE_OF_CAT_SIM;
                
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {

                        result = KAL_TRUE;

                        break;

                    }
                    
                }
                
           }            

        break;
        
        case SML_CAT_NS_SP:

            if(SML_SIZE_OF_LINK_NS_SP == len)
            {

                for(idx = 0; idx < meta->num; idx++)
                {

                    offset = idx * SML_SIZE_OF_LINK_NS_SP;
                
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {

                        result = KAL_TRUE;

                        break;

                    }
                    
                }
                
            }
            
        break;
        
        case SML_CAT_SIM_C:
            
            if(SML_SIZE_OF_LINK_SIM_C == len)
            {

                for(idx = 0; idx < meta->num; idx++)
                {

                    offset = idx * SML_SIZE_OF_LINK_SIM_C;
                
                    if(kal_mem_cmp(code,(pdata+offset),len)==0)
                    {

                        result = KAL_TRUE;

                        break;

                    }
                    
                }

            }
            
        break;    
        
        default:
            
        break;
        
    }           

    return result;
    
}
/*******************************************************************************
 * FUNCTION  
 *  sml_Catcode
 * DESCRIPTION
 *  This function is used to compose the code of each category
 * PARAMETERS
 *  IN          cat
 *  IN          *imsi
 *  IN          *gid1
 *  IN          *gid2
 *  IN          mnc_len
 *  OUT          *code
 * RETURN
 *  kal_uint8   code length
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_Catcode( sml_cat_enum cat,
                       kal_uint8 *imsi,
                       kal_uint8 *gid1,
                       kal_uint8 *gid2,
                       kal_uint8 mnc_len,
                       kal_uint8 *code )
{

    if(mnc_len == 3)
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);
        code[3] = (imsi[4] & 0xF0) | (imsi[5] & 0x0F);
    }
    else
    {
        code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);
        code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);
        code[2] = (imsi[3] & 0xF0) | 0x0F;
        code[3] = ((imsi[4] & 0x0F) << 4) | ((imsi[4] & 0xF0) >> 4);
    }

    switch(cat)
    {
        
        case SML_CAT_N:

            return SML_SIZE_OF_CAT_N;
                    
        break;
        
        case SML_CAT_NS:

            return SML_SIZE_OF_CAT_NS;
            
        break;
        
        case SML_CAT_SP:

            if(gid1)
            {
                code[3] = gid1[0];
                
                return SML_SIZE_OF_CAT_SP;

            }

        break;

        case SML_CAT_C:
            
            if(gid1 && gid2 )
            {

                code[3] = gid1[0];

                code[4] = gid2[0];

                return SML_SIZE_OF_CAT_C;

            }
                               
        break;
        
        case SML_CAT_SIM:

            kal_mem_cpy(code,&(imsi[1]),8);
            
            return SML_SIZE_OF_CAT_SIM;          
            
        break;
        
        case SML_CAT_NS_SP:

            if(gid1)
            {            

                code[4] = gid1[0];

                return SML_SIZE_OF_LINK_NS_SP;

            }  

        break;
        
        case SML_CAT_SIM_C:

            kal_mem_cpy(code,&(imsi[1]),8);

            if(gid1 && gid2)
            {

                code[8] = gid1[0];

                code[9] = gid2[0];
                
                return SML_SIZE_OF_LINK_SIM_C;

            }
                  
        break;    
        
        default:
            
        break;
        
    }           

    return 0;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Nvram_get_size
 * DESCRIPTION
 *  This function is used to query the status of the category
 * PARAMETERS
 *  IN          file_idx
 * RETURN
 *  kal_uint16 file size
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
kal_uint16 sml_Nvram_get_lid_size(kal_uint8 file_idx)
{

    switch(file_idx)
    {
        case NVRAM_EF_MS_SECURITY_LID:
            
            return sizeof(smu_security_info_struct);

            break;

        case NVRAM_EF_SML_LID:

            return sizeof(sml_context_struct);

            break;

        default:

            return 0;

            break;

    }

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Process_autolock
 * DESCRIPTION
 *  This function is used process autolock function
 * PARAMETERS
 *  IN          cat
 *  OUT         *state 
 *  OUT         *retry_count
 *  OUT         *num_of_sets
 *  OUT         *space_of_sets
 *  OUT         *key_state
 *  OUT         *auto_lock_count
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Process_autolock( kal_uint8 * imsi,
                               kal_uint8 * gid1,
                               kal_uint8 * gid2,
                               kal_uint8 num_mnc,
                               kal_uint8 * remain_count,
                               kal_uint8 source)
#else
kal_bool sml_Process_autolock( kal_uint8 * imsi,
                               kal_uint8 * gid1,
                               kal_uint8 * gid2,
                               kal_uint8 num_mnc,
                               kal_uint8 * remain_count )
#endif
{

    kal_bool result = KAL_FALSE;

    sml_cat_enum cat = SML_CAT_N;

    kal_uint8 code[10] = {0xFF}, len = 0, count = 0;

    kal_mem_set( (kal_uint8 *) &(code[0]), 
                  0xFF, 
                  10 
                  );
    
    *remain_count = 0;

    for(cat = SML_CAT_N; cat < SML_CAT_SIZE; cat++)
    {
    
        len = sml_Catcode( cat,
                           imsi,
                           gid1, 
                           gid2, 
                           num_mnc, 
                           code );

#ifdef __GEMINI__
        if(KAL_TRUE == sml_Autolock( cat, 
                                     code, 
                                     len, 
                                     &count,
                                     source
                                     ))
#else
        if(KAL_TRUE == sml_Autolock( cat, 
                                     code, 
                                     len, 
                                     &count
                                     ))
#endif
        {

            result = KAL_TRUE;

        }

        if(count > *remain_count)
        {
        
            *remain_count = count; 

        }
            
    }

    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Is_autolock
 * DESCRIPTION
 *  This function is used to query if there is autolock shall be processed
 * PARAMETERS
 *  void
 * RETURN
 *  kal_uint8    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_uint8 sml_Is_autolock( kal_uint8 source )
#else
kal_uint8 sml_Is_autolock( void )
#endif
{

    nvram_ef_sml_obj_struct *p = pSMLg;

    sml_category_meta_struct *meta = NULL;

    sml_cat_enum cat = SML_CAT_N;

    kal_uint16 length = 0;

    kal_uint8 result = 0;

    for(cat = SML_CAT_N; cat < SML_CAT_SIZE; cat++)
    {

#ifdef __GEMINI__
        meta = (sml_category_meta_struct *) (*p->getItem)(cat,
                                                          SML_CAT_META,
                                                          &length,
                                                          source);
#else
        meta = (sml_category_meta_struct *) (*p->getItem)(cat,
                                                          SML_CAT_META,
                                                          &length);
#endif

        if(meta->state == SML_STATE_AUTOLOCK)
        {
            result++;
        }
    }

    return result;
    
}

/*******************************************************************************
 * FUNCTION  
 *  sml_Verify
 * DESCRIPTION
 *  This function is used to verify the SML lock keys
 * PARAMETERS
 *  void
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Verify( sml_cat_enum cat,
                      kal_uint8 * key,
                      kal_uint8 len,
                      kal_uint8 * retry_count,
                      kal_uint8 source)
#else
kal_bool sml_Verify( sml_cat_enum cat,
                      kal_uint8 * key,
                      kal_uint8 len,
                      kal_uint8 * retry_count)
#endif                      
{

    nvram_ef_sml_obj_struct *p = pSMLg;
    
    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_bool result = KAL_FALSE;

    kal_uint16 length = 0;

#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length); 
#endif    

    if(kal_mem_cmp(catkey->key,key,len)==0)
    {

        result = KAL_TRUE;
        
        switch(cat)
        {
            
            case SML_CAT_N:
            
                meta->retry_count = SML_RETRY_COUNT_N_CAT;
                
            break;
            case SML_CAT_NS:
        
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                
            break;
            case SML_CAT_SP:
                
                meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                
            break;
            case SML_CAT_C:
                
                meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                
            break;
            case SML_CAT_SIM:
               
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                
            break;
            case SML_CAT_NS_SP:
                
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                
            break;
            case SML_CAT_SIM_C:
                
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                
            break;    
            default:
            break;
            
        }           

    }
    else
    {

        meta->retry_count--;

        result = KAL_FALSE;
        
    }

    *retry_count = meta->retry_count;
    
    return result;
    
}

/* END: PH sml_context_struct (NVRAM_EF_SML_LID) */

/*******************************************************************************
 * FUNCTION  
 *  sml_Testsim_op_mode
 * DESCRIPTION
 *  This function is used to query the testsim handling rule
 * PARAMETERS
 *  void
 * RETURN
 *  SML_TESTSIM_ALW_REJECT  0
 *  SML_TESTSIM_ALW_ALLOW   1
 *  SML_TESTSIM_INI_ALLOW   2
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_uint8 sml_Testsim_op_mode(void)
{

    return SML_TESTSIM_OP_MODE;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_is_Masterkey_enable
 * DESCRIPTION
 *  This function is used to query the Masterkey handling rule
 * PARAMETERS
 *  void
 * RETURN
 * kal_bool
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 

kal_bool sml_is_Masterkey_enable(void)
{

    return SML_MASTER_KEY_ENABLE;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_Verify_OTA
 * DESCRIPTION
 *  This function is used to process OTA
 * PARAMETERS
 *  void
 * RETURN
 *  kal_bool    result
 * GLOBALS AFFECTED
 *  SMLOBJ
 *******************************************************************************/ 
#ifdef __GEMINI__
kal_bool sml_Verify_OTA( sml_cat_enum cat,
                          kal_uint8 * key,
                          kal_uint8 len,
                          kal_uint8 source)
#else
kal_bool sml_Verify_OTA( sml_cat_enum cat,
                          kal_uint8 * key,
                          kal_uint8 len )
#endif                          
{
    nvram_ef_sml_obj_struct *p = pSMLg;
    
    sml_category_meta_struct *meta = NULL;

    sml_control_key_struct *catkey = NULL;

    kal_bool result = KAL_FALSE;

    kal_uint16 length = 0;

#ifdef __GEMINI__
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length, source);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length, source); 
#else
    meta = (sml_category_meta_struct *) (*p->getItem)(cat,SML_CAT_META,&length);
    catkey = (sml_control_key_struct *) (*p->getItem)(cat,SML_CAT_KEY,&length); 
#endif    

    if(kal_mem_cmp(catkey->key,key,len)==0)
    {

        result = KAL_TRUE;

        if(SML_STATE_LOCK == meta->state)
            meta->state = SML_STATE_UNLOCK;
        
        switch(cat)
        {
            
            case SML_CAT_N:
            
                meta->retry_count = SML_RETRY_COUNT_N_CAT;
                
            break;
            case SML_CAT_NS:
        
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;                    
                
            break;
            case SML_CAT_SP:
                
                meta->retry_count = SML_RETRY_COUNT_SP_CAT;
                
            break;
            case SML_CAT_C:
                
                meta->retry_count = SML_RETRY_COUNT_C_CAT;                    
                
            break;
            case SML_CAT_SIM:
               
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;     
                
            break;
            case SML_CAT_NS_SP:
                
                meta->retry_count = SML_RETRY_COUNT_NS_CAT;
                
            break;
            case SML_CAT_SIM_C:
                
                meta->retry_count = SML_RETRY_COUNT_SIM_CAT;
                
            break;    
            default:
            break;
            
        }           

    }
    else
    {

        result = KAL_FALSE;
        
    }
    
    return result;

}

/*******************************************************************************
 * FUNCTION  
 *  sml_CheckVisa
 * DESCRIPTION
 *  This function is used to handle special Block SIM cards 
 * PARAMETERS
 *  IN          *imsi
 *  IN          mnc_len
 * RETURN
 *  kal_bool  
 * GLOBALS AFFECTED
 *  NONE
 *******************************************************************************/ 
kal_bool sml_CheckVisa(const kal_uint8 * imsi, kal_uint8 mnc_len)
{

    const kal_uint8 *  code_ptr = &(smlVISA[0]);

    kal_uint8 code[3] = {0};
    

    code[0] = (imsi[1] & 0xF0) | (imsi[2] & 0x0F);

    code[1] = (imsi[2] & 0xF0) | (imsi[3] & 0x0F);

    if(3 == mnc_len)
    {

        code[2] = (imsi[3] & 0xF0) | (imsi[4] & 0x0F);

    }
    else
    {
    
        code[2] = (imsi[3] & 0xF0) | 0x0F;

    }

    while(0xFF != *code_ptr) /* Break if first byte is 0xFF */
    {

        if(0==kal_mem_cmp(code_ptr,code,3))
        {
            
            return KAL_TRUE;
            
        }

        code_ptr += 3;

    }

    return KAL_FALSE;


}
#endif /* !defined(__MAUI_BASIC__) */ 

