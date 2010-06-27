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
 * Filename:
 * ---------
 * custom_nvram_sec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM security customization.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUSTOM_NVRAM_SEC_H
#define CUSTOM_NVRAM_SEC_H
#if !defined(__MAUI_BASIC__)
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

//=========================================================================
// CUST PARA Configuration                                                 
//=========================================================================
#ifdef __CUST_PARA_SUPPORT__
typedef struct {
	// CustPara_ST structure members is defined by customer 
	kal_uint8	dummy[4096];
} CustPara_ST;
#endif

//=========================================================================
// SML Configuration                                                       
//=========================================================================
#define NVRAM_MSP_DECRYPT 0
#define NVRAM_MSP_ENCRYPT 1

#define NVRAM_SECRET_KEY_SIZE 		8

/* Whenever nvram_sml_context_struct's size or members are changed,  
   be sure to assign an unique version number to SEC_RO_STRUCT_VER.  
   Otherwise, PC side tool has no idea how to compose it */
#define SEC_RO_STRUCT_VER		  1
/************************************************************************
 * Define the basic unit of categories                                  *
 ************************************************************************/
#define SML_SIZE_OF_CAT_N      3 /* MCC/MNC */
#define SML_SIZE_OF_CAT_NS     4 /* MCC/MNC + HLR */
#define SML_SIZE_OF_CAT_SP     4 /* MCC/MNC + GID1 */
#define SML_SIZE_OF_CAT_C      5 /* MCC/MNC + GID1 + GID2 */
#define SML_SIZE_OF_CAT_SIM    8 /* IMSI */
/* Define the maximum suppot categories */
#define SML_MAX_SUPPORT_CAT_N       30
#define SML_MAX_SUPPORT_CAT_NS      30 
#define SML_MAX_SUPPORT_CAT_SP      30
#define SML_MAX_SUPPORT_CAT_C       30
#define SML_MAX_SUPPORT_CAT_SIM     30
/* Define the total size of each category */
#define SML_CFG_CAT_N_SIZE          (SML_MAX_SUPPORT_CAT_N * SML_SIZE_OF_CAT_N)   
#define SML_CFG_CAT_NS_SIZE         (SML_MAX_SUPPORT_CAT_NS * SML_SIZE_OF_CAT_NS)
#define SML_CFG_CAT_SP_SIZE         (SML_MAX_SUPPORT_CAT_SP * SML_SIZE_OF_CAT_SP)
#define SML_CFG_CAT_C_SIZE          (SML_MAX_SUPPORT_CAT_C * SML_SIZE_OF_CAT_C)
#define SML_CFG_CAT_SIM_SIZE        (SML_MAX_SUPPORT_CAT_SIM * SML_SIZE_OF_CAT_SIM)
/* Define the support category size */
#define SML_SUPPORT_CAT_SIZE    7 /* SML_CAT_SIZE in sml_cat_enum */

/************************************************************************
 * Define Key management behavior
 ************************************************************************/
/* Define the key length in bytes */
#define SML_MAX_SUPPORT_KEY_LEN     8
/* */

/************************************************************************
 * Linked Category Support 
 ************************************************************************/
#define SML_SIZE_OF_LINK_NS_SP          5  /* MCC/MNC + HLR+ GID1 */
#define SML_SIZE_OF_LINK_SIM_C          10 /* IMSI + GID1 + GID2 */
/* Define the maximum support num of categories */
#define SML_MAX_SUPPORT_LINK_NS_SP      10
#define SML_MAX_SUPPORT_LINK_SIM_C      10
/* define the total size of link category */
#define SML_CFG_CAT_NS_SP_SIZE          (SML_SIZE_OF_LINK_NS_SP * SML_MAX_SUPPORT_LINK_NS_SP)
#define SML_CFG_CAT_SIM_C_SIZE          (SML_SIZE_OF_LINK_SIM_C * SML_MAX_SUPPORT_LINK_SIM_C)

/*************************************************************************
 * Define Range Support
 ************************************************************************/
#define SML_CAT_NS_RANGE_SIZE           2   /* ex: 00FF 0~255 for HLR */
 
/************************************************************************ 
 * Define Automatically Lock 
 ************************************************************************/
#define SML_AUTOLOCK_NUM_N_CATEGORY     SML_MAX_SUPPORT_N_CAT 
#define SML_AUTOLOCK_NUM_NS_CATEGORY    SML_MAX_SUPPORT_NS_CAT
#define SML_AUTOLOCK_NUM_SP_CATEGORY    SML_MAX_SUPPORT_SP_CAT
#define SML_AUTOLOCK_NUM_C_CATEGORY     SML_MAX_SUPPORT_C_CAT
#define SML_AUTOLOCK_NUM_SIM_CATEGORY   SML_MAX_SUPPORT_SIM_CAT

/************************************************************************
 * Define Maximum Retry Count
 ************************************************************************/
#define SML_MAX_RETRY_COUNT             5
#define SML_RETRY_TIMEOUT               3 /* in sec */
#define SML_RETRY_COUNT_N_CAT           SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_NS_CAT          SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_SP_CAT          SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_C_CAT           SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_SIM_CAT         SML_MAX_RETRY_COUNT

/* Define general control key structure */
typedef struct {
    kal_uint8 state;    /* Default Value or NULL */
    kal_uint8 key[SML_MAX_SUPPORT_KEY_LEN];   
} sml_control_key_struct;

/* Define general lock structure */
typedef struct {
    kal_uint8 state;                    /* sml_state_enum */    
    kal_uint8 retry_count;              /* SML_RETRY_COUNT_X_CAT */
    kal_uint8 autolock_count;           /* SML_AUTOLOCK_NUM_X_CAT */
    kal_uint8 num;                      /* num of valid sets */
} sml_category_meta_struct;

typedef struct {
    kal_uint32  magic_head;                                 /* 4 */
    sml_category_meta_struct    cat[SML_SUPPORT_CAT_SIZE];  /* (4 * 7) */
    sml_control_key_struct      key[SML_SUPPORT_CAT_SIZE];  /* (9 * 7) */
    kal_uint8   code_cat_n[SML_CFG_CAT_N_SIZE];             /* (30 * 3)*/
    kal_uint8   code_cat_ns[SML_CFG_CAT_NS_SIZE];           /* (30 * 4)*/
    kal_uint8   code_cat_sp[SML_CFG_CAT_SP_SIZE];           /* (30 * 4)*/
    kal_uint8   code_cat_c[SML_CFG_CAT_C_SIZE];             /* (30 * 5)*/
    kal_uint8   code_cat_sim[SML_CFG_CAT_SIM_SIZE];         /* (30 * 8)*/
    kal_uint8   code_cat_ns_sp[SML_CFG_CAT_NS_SP_SIZE];     /* (5 * 10)*/
    kal_uint8   code_cat_sim_c[SML_CFG_CAT_SIM_C_SIZE];     /* (10 * 10)*/
    kal_uint8   range_cat_ns[SML_CAT_NS_RANGE_SIZE];        /* 2 */
    kal_uint32 magic_tail;                                  /* 4 */
} sml_context_struct;                                       /* 971 */
typedef sml_context_struct nvram_sml_context_struct;

/************************************************************************
 * Define SML Misc.
 ***********************************************************************/
/* define the magic number of file header and tail */
#define SML_MAGIC_HEAD_VALUE            (sizeof(sml_context_struct))
#define SML_MAGIC_TAIL_VALUE              0x26598088
/* define the SML flags */
#define SML_FLAG_CAT_N             0x01
#define SML_FLAG_CAT_NS            0x02
#define SML_FLAG_CAT_SP            0x04
#define SML_FLAG_CAT_C             0x08
#define SML_FLAG_CAT_SIM           0x10

#ifdef __SECURE_RO_ENABLE__
/************************************************************************
 * Define Secure RO
 ***********************************************************************/

#define NVRAM_SECRET_KEY_MAX_SIZE	128

typedef struct {

	/* --- FIXED section BEGIN ----------------------------------------------- */

	/* NOTICE!! This section is FIXED. */
	/* DO NOT delete any member, add new member or change data type and size. */

	/* a unique version to identify SEC_RO_T structure layout */
	kal_uint32		         m_sec_ro_ver;				

	/* custom secret key */
    kal_uint8                m_custom_secret_key[NVRAM_SECRET_KEY_MAX_SIZE];

    /* custom secret key len */
    kal_uint32               m_custom_secret_key_len;

	/* --- FIXED section END -------------------------------------------------*/

    nvram_sml_context_struct nvram_ef_sml;
} SEC_RO_ST;
#else /* __SECURE_RO_ENABLE__ */
extern const kal_uint8 *NVRAM_EF_SECUPACK_DEFAULT[];
#endif /* __SECURE_RO_ENABLE__ */
extern const nvram_sml_context_struct NVRAM_EF_SML_DEFAULT;

extern void custom_nvram_get_key(char *init_key, unsigned char *keys);
extern void custom_nvram_encrypt(unsigned char const *keys, unsigned char *buffer, unsigned int length, int scrambleIndex);
extern void custom_nvram_decrypt(unsigned char const *keys, unsigned char *buffer, unsigned int length, int scrambleIndex);
#ifdef __cplusplus
}
#endif 
#endif /* !defined(__MAUI_BASIC__) */ 
#endif /* CUSTOM_NVRAM_SEC_H */ 

