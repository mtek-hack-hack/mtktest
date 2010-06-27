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
 * custom_nvram_extra.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file defines the methods to manuplate the file object defined in NVRAM data items. 
 *   
 *
 * Author:
 * -------
 * -------
 ****************************************************************************/
#ifndef CUSTOM_NVRAM_EXTRA_H
#define CUSTOM_NVRAM_EXTRA_H
#if !defined(__MAUI_BASIC__)
/***************************************************************************** 
* Define
*****************************************************************************/
/***************************************************************************** 
* Typedef 
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
typedef enum
{
    SMU_REG_PS_KEY_A,
    SMU_SECURITY_INDICATION_U8,
    SMU_AUTO_LOCK_ITEM_U8,
    SMU_NP_CODE_A,
    SMU_NP_KEY_A,
    SMU_NSP_CODE_A,
    SMU_NSP_KEY_A,
    SMU_NP_OF_SP_A,
    SMU_NP_OF_CP_A,
    SMU_GID1_A,
    SMU_GID2_A,
    SMU_SP_KEY_A,
    SMU_CP_KEY_A,
    SMU_IMSI_CODE_A,
    SMU_IMSI_KEY_A,
    SMU_PHONE_KEY_A,
    SMU_LAST_IMSI_A,
    SMU_PIN1_A,
    SMU_PIN1_VALID_U8,
    SMU_PHONE_LOCK_VERIFIED_U8,
    SMU_ICCID_A
} smu_item_enum;

typedef struct
{
#ifdef __GEMINI__
    /* Data object ptr */
    void *smu_security_info_ptr_0;
    void *smu_security_info_ptr_1;
    /* Load a new data object */
      kal_bool(*load) (void *, kal_uint8);             /* pobjFromlid */
    /* Update a the data object */
      kal_bool(*update) (void *, kal_uint8);           /* pobjTolid */
    /* Release the data object */
      kal_bool(*destoy) (kal_uint8);
    /* Query the value of the item in kal_uint8 */
      kal_uint8(*query_u8) (smu_item_enum, kal_uint8); /* eItem */
    /* Query the value of the item in kal_uint8[] */
    void (*query_a) (smu_item_enum,         /* eItem */
                     kal_uint8 *,           /* pstrTo */
                     kal_uint8,
                     kal_uint8);            /* chlen */
    /* Assign the value of the item in kal_uint8 */
    void (*assign_u8) (smu_item_enum,       /* eItem */
                       kal_uint8, kal_uint8);          /* Value */
    /* Assign the value of the item in string with length */
    void (*assign_a) (smu_item_enum,        /* eItem */
                      kal_uint8 *,          /* pValue */
                      kal_uint8,
                      kal_uint8);           /* len */
    /* Compare the string with the data item */
      kal_bool(*match) (smu_item_enum,      /* eItem */
                        kal_uint8 *,        /* pstr */
                        kal_uint8,
                        kal_uint8);         /* len */
#else
    /* Data object ptr */
    void *smu_security_info_ptr;
    /* Load a new data object */
      kal_bool(*load) (void *);             /* pobjFromlid */
    /* Update a the data object */
      kal_bool(*update) (void *);           /* pobjTolid */
    /* Release the data object */
      kal_bool(*destoy) (void);
    /* Query the value of the item in kal_uint8 */
      kal_uint8(*query_u8) (smu_item_enum); /* eItem */
    /* Query the value of the item in kal_uint8[] */
    void (*query_a) (smu_item_enum,         /* eItem */
                     kal_uint8 *,           /* pstrTo */
                     kal_uint8);            /* chlen */
    /* Assign the value of the item in kal_uint8 */
    void (*assign_u8) (smu_item_enum,       /* eItem */
                       kal_uint8);          /* Value */
    /* Assign the value of the item in string with length */
    void (*assign_a) (smu_item_enum,        /* eItem */
                      kal_uint8 *,          /* pValue */
                      kal_uint8);           /* len */
    /* Compare the string with the data item */
      kal_bool(*match) (smu_item_enum,      /* eItem */
                        kal_uint8 *,        /* pstr */
                        kal_uint8);         /* len */
#endif    
} nvram_ef_ms_security_struct;

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
typedef enum {
    SML_STATE_NULL,
    SML_STATE_LOCK,
    SML_STATE_UNLOCK,
    SML_STATE_AUTOLOCK,
    SML_STATE_DISABLE	
} sml_state_enum;

typedef enum {
    SML_KEY_EMPTY,
    SML_KEY_SET
} sml_key_state_enum;

typedef enum {
    SML_OP_UNLOCK,
    SML_OP_LOCK,
    SML_OP_ADD,
    SML_OP_REMOVE,
    SML_OP_DISABLE
} sml_op_enum;

typedef enum {
    SML_CAT_N,
    SML_CAT_NS,
    SML_CAT_SP,
    SML_CAT_C,
    SML_CAT_SIM,
    SML_CAT_NS_SP,
    SML_CAT_SIM_C,
    SML_CAT_SIZE
} sml_cat_enum;

typedef enum {
    SML_MAGIC_HEAD,
    SML_MAGIC_TAIL,
    SML_CAT_META,
    SML_CAT_KEY,
    SML_CAT_CODE,
    SML_CAT_RANGE    
} sml_ctx_enum;

typedef struct {
#ifdef __GEMINI__
    void    * pObj_0;
    void    * pObj_1;
    void    (* give)(void * /* pLidToObj */, kal_uint8);
    void    (* take)(void * /* pObjToLid */, kal_uint8);
    void    (* destory)(kal_uint8);
    void    * (* getItem)(sml_cat_enum,sml_ctx_enum,kal_uint16 * /* length */, kal_uint8);
    void    (* putItem)(sml_cat_enum,sml_ctx_enum,void * /* pItem */, kal_uint16 * /* plen */, kal_uint8);
#else
    void    * pObj;
    void    (* give)(void * /* pLidToObj */);
    void    (* take)(void * /* pObjToLid */);
    void    (* destory)(void);
    void    * (* getItem)(sml_cat_enum,sml_ctx_enum,kal_uint16 * /* length */);
    void    (* putItem)(sml_cat_enum,sml_ctx_enum,void * /* pItem */, kal_uint16 * /* plen */);
#endif
} nvram_ef_sml_obj_struct;


 
/***************************************************************************** 
* Extern Global Variable                                                                    
*****************************************************************************/

extern nvram_ef_ms_security_struct *pSmuSecurityInfog;
extern nvram_ef_sml_obj_struct *pSMLg;

/************************************************************************ 
 * Test SIM card handling
 ************************************************************************/
#define SML_TESTSIM_ALW_REJECT  0
#define SML_TESTSIM_ALW_ALLOW   1
#define SML_TESTSIM_INI_ALLOW   2
/* Customer defined field */
#define SML_TESTSIM_OP_MODE     SML_TESTSIM_ALW_ALLOW

extern kal_uint8 sml_Testsim_op_mode(void);

/************************************************************************ 
 * MASTER-SLAVE Behavior
 ************************************************************************/
/* Customer defined field */
#define SML_MASTER_KEY_ENABLE     KAL_FALSE

extern kal_bool sml_is_Masterkey_enable(void);

/***************************************************************************** 
* Extern Global Function                                                                    
*****************************************************************************/
#ifdef __GEMINI__
extern kal_uint16 sml_Load( void * pLid, kal_uint8 source );
extern kal_uint16 sml_Save( void * pLid, kal_uint8 source );
extern kal_bool sml_Unlock( sml_cat_enum cat,
                            kal_uint8 * key, 
                            kal_uint8 key_len, 
                            kal_uint8 source );
extern kal_bool sml_Lock( sml_cat_enum cat, 
                          kal_uint8 * key, 
                          kal_uint8 key_len, 
                          kal_uint8 source );
extern kal_bool sml_Add( sml_cat_enum cat, 
                         kal_uint8 * code, 
                         kal_uint8 len, 
                         kal_uint8 * key, 
                         kal_uint8 key_len, 
                         kal_uint8 * remain, 
                         kal_uint8 source );
extern kal_bool sml_Remove( sml_cat_enum cat, kal_uint8 source );
extern kal_bool sml_Reset( sml_cat_enum cat, 
                           kal_uint8 * key, 
                           kal_uint8 key_len, 
                           kal_uint8 source );
extern kal_bool sml_Disable( sml_cat_enum cat, kal_uint8 source );
extern void sml_Status( sml_cat_enum cat, 
                        kal_uint8 * state, 
                        kal_uint8 * retry_count, 
                        kal_uint8 * num_of_sets, 
                        kal_uint8 * space_of_sets, 
                        kal_uint8 * key_state, 
                        kal_uint8 * auto_lock_count, 
                        kal_uint8 source );
extern kal_bool sml_Autolock( sml_cat_enum cat, 
                              kal_uint8 * code, 
                              kal_uint8 len, 
                              kal_uint8 * remain, 
                              kal_uint8 source );
extern kal_uint8 sml_Catcode( sml_cat_enum cat, 
                              kal_uint8 * imsi, 
                              kal_uint8 * gid1, 
                              kal_uint8 * gid2, 
                              kal_uint8 mnc_len, 
                              kal_uint8 * code );
extern kal_bool sml_Check( sml_cat_enum cat, 
                           kal_uint8 * code, 
                           kal_uint8 len,
                           kal_uint8 * remain, 
                           kal_uint8 source );
extern kal_uint16 sml_Nvram_get_lid_size( kal_uint8 file_idx );
extern kal_bool sml_Process_autolock( kal_uint8 * imsi, 
                                      kal_uint8 * gid1, 
                                      kal_uint8 * gid2, 
                                      kal_uint8 num_mnc, 
                                      kal_uint8 * remain_count, 
                                      kal_uint8 source );
extern kal_uint8 sml_Is_autolock( kal_uint8 source );
extern kal_bool sml_Verify( sml_cat_enum cat, 
                             kal_uint8 * key, 
                             kal_uint8 len, 
                             kal_uint8 * retry_count, 
                             kal_uint8 source );
extern kal_bool sml_Verify_OTA( sml_cat_enum cat,
                                kal_uint8 * key, 
                                kal_uint8 len, 
                                kal_uint8 source );
extern kal_bool sml_CheckVisa(const kal_uint8 * imsi, 
                              kal_uint8 mnc_len);
#else
extern kal_uint16 sml_Load( void * pLid );
extern kal_uint16 sml_Save( void * pLid );
extern kal_bool sml_Unlock( sml_cat_enum cat,
                            kal_uint8 * key, 
                            kal_uint8 key_len );
extern kal_bool sml_Lock( sml_cat_enum cat, 
                          kal_uint8 * key, 
                          kal_uint8 key_len );
extern kal_bool sml_Add( sml_cat_enum cat, 
                         kal_uint8 * code, 
                         kal_uint8 len, 
                         kal_uint8 * key, 
                         kal_uint8 key_len, 
                         kal_uint8 * remain );
extern kal_bool sml_Remove( sml_cat_enum cat );
extern kal_bool sml_Reset( sml_cat_enum cat, 
                           kal_uint8 * key, 
                           kal_uint8 key_len );
extern kal_bool sml_Disable( sml_cat_enum cat );
extern void sml_Status( sml_cat_enum cat, 
                        kal_uint8 * state, 
                        kal_uint8 * retry_count, 
                        kal_uint8 * num_of_sets, 
                        kal_uint8 * space_of_sets, 
                        kal_uint8 * key_state, 
                        kal_uint8 * auto_lock_count );
extern kal_bool sml_Autolock( sml_cat_enum cat, 
                              kal_uint8 * code, 
                              kal_uint8 len, 
                              kal_uint8 * remain );
extern kal_uint8 sml_Catcode( sml_cat_enum cat, 
                              kal_uint8 * imsi, 
                              kal_uint8 * gid1, 
                              kal_uint8 * gid2, 
                              kal_uint8 mnc_len, 
                              kal_uint8 * code );
extern kal_bool sml_Check( sml_cat_enum cat, 
                           kal_uint8 * code, 
                           kal_uint8 len,
                           kal_uint8 * remain );
extern kal_uint16 sml_Nvram_get_lid_size( kal_uint8 file_idx );
extern kal_bool sml_Process_autolock( kal_uint8 * imsi, 
                                      kal_uint8 * gid1, 
                                      kal_uint8 * gid2, 
                                      kal_uint8 num_mnc, 
                                      kal_uint8 * remain_count );
extern kal_uint8 sml_Is_autolock( void );
extern kal_bool sml_Verify( sml_cat_enum cat, 
                             kal_uint8 * key, 
                             kal_uint8 len, 
                             kal_uint8 * retry_count );
extern kal_bool sml_Verify_OTA( sml_cat_enum cat,
                                kal_uint8 * key, 
                                kal_uint8 len );
extern kal_bool sml_CheckVisa(const kal_uint8 * imsi, 
                              kal_uint8 mnc_len);
#endif

/*
 * NVRAM Shutdown Callback
 */
typedef struct
{
    kal_uint16 LID;
    kal_bool (*get_data)(kal_uint8 *buffer, kal_uint16 buf_size);
}nvram_shutdown_cb_struct;
extern nvram_shutdown_cb_struct nvram_shutdown_cb_table[];

extern kal_bool flc2_write_nvram_statistics_callback(kal_uint8 *buffer, kal_uint16 buf_size);


#endif /* !defined(__MAUI_BASIC__) */ 
#endif /* CUSTOM_NVRAM_EXTRA_H */ 

