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
 *  CentralConfigAgentConst.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_CCACONST_H
#define MMI_CCACONST_H

#include "MMI_include.h"   /* for trace group */



/* for TRACE info   temporary defined here */
/* should change this to MMI_CONN_TRC_G9_CCA on maui 
 * and 07B , keep MMI_TRACE_G7_MISC on 07A */

#define CCA_TRACE_INFO        MMI_CONN_TRC_G9_CCA
#define CCA_TRACE_WARNING     MMI_CONN_TRC_G9_CCA
#define CCA_TRACE_ERROR       MMI_CONN_TRC_G9_CCA


#define CCA_TREE_MAX_CHILDS     20
#define CCA_TREE_MAX_LEVELS     10  /* includes root, so max 10 = root + level 1 to 9 */
#define CCA_MAX_PIN_CHARS       32
//#define CCA_MAX_NUM_APPS        10
//#define CCA_MAX_APPNAME_CHARS   32
#define CCA_MAX_REF_BY_ENTRIES  10
#define CCA_MAX_APPS            20

/* for operations on currently activated profile */
#define CCA_PROF_CURRENT        -1


typedef enum
{
    MMI_CCA_SIM_ID_DEFAULT,
    MMI_CCA_SIM_ID_SIM1,
    MMI_CCA_SIM_ID_SIM2,
    MMI_CCA_SIM_ID_MAX_ITM
}mmi_cca_sim_id_enum;

typedef enum
{
    CCA_STATUS_OK,
    CCA_STATUS_FAIL,

    CCA_STATUS_INVALID_SETTING,
    CCA_STATUS_SETTING_SKIPPED,
    CCA_STATUS_ENDKEY_PRESSED,

    CCA_STATUS_ABORT,
    CCA_STATUS_ENDLIST,
    CCA_STATUS_MEMFULL,
    CCA_STATUS_NOT_FOUND,
    CCA_STATUS_TYPE_MISMATCHED,
    CCA_STATUS_INVALID_ITER,
    CCA_STATUS_INVALID_HANDLE,

    CCA_STATUS_UNSUPPORTED_SETTING,
    CCA_STATUS_CORRUPTED_SETTING,
    CCA_STATUS_MISSING_DATA,

    CCA_STATUS_OUT_OF_RANGE,
	CCA_STATUS_CCA_BUSY,

    CCA_STATUS_LAST
} cca_status_enum;

typedef enum
{
    CCA_STATE_IDLE = 0,
    CCA_STATE_PROVISIONING,
    CCA_STATE_ASYNC,

    CCA_STATE_LAST
} cca_state_enum;

typedef enum
{
    CCA_OPER_NULL = 0,
    CCA_OPER_GET,
    CCA_OPER_UPDATE,

    CCA_OPER_LAST
} cca_oper_enum;

typedef enum
{
    CCA_FL_STSCHILD = 0x01,
    CCA_FL_STSPARENT = 0x02,

    CCA_FL_LAST
} cca_flag_enum;

typedef enum {
    CCA_TR_LIST,
    CCA_TR_PREORDER
} cca_traverse_type_enum;

/*
 * NODELIST:
 *   ------  ------  ------  ------
 *   |Next|--|Next|--|Next|--|Next|---0
 *   |Node|  |Node|  |Node|  |Node|
 *   ------  ------  ------  ------
 *
 * NODECHAIN:
 *   ------  ------  ------  ------
 *   |Node|--|Node|--|Node|--|Node|---0
 *   ------  ------  ------  ------
 */
typedef enum {
    CCA_IT_NODELIST,
    CCA_IT_NODECHAIN,
    CCA_IT_DATALIST,
    CCA_IT_DOC
} cca_iter_type_enum;

typedef enum {
    CCA_DT_INT = 0,
    CCA_DT_STR
} cca_data_type_enum;

typedef enum {
    CCA_MFID_WITHIN_APP_CONFIGURE,
    CCA_MFID_SIZE
} cca_memfull_cb_id_enum;

/***** Spec ID / Application ID / Configuration ID
 * Each ID = 2 bytes const (16 bits)
 * Spec ID = high byte = 256 specs --> { ssss cccc }
 *           where ssss = higher 4 bits = spec ID
 *                 cccc = lower 4 bits = category ID
 * App ID = low byte = 256 applications
 */
// xxxx 0000 0000 0000
#define CCA_SPEC_NULL   0x0000
#define CCA_SPEC_OMA    0x1000
#define CCA_GET_SPEC(x) (x & 0xF000)

// 0000 xxxx 0000 0000
#define CCA_CATE_NULL   0x0000
#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
#endif

#define CCA_GET_CATE(x) (x & 0x0F00)

// 0000 0000 xxxx xxxx
#define CCA_APP_TEST        0x0001
#define CCA_APP_DTACCT      0x0002
#define CCA_APP_WLAN        0x0003
#define CCA_APP_BROWSER     0x0004
#define CCA_APP_MMS         0x0005
#define CCA_APP_SIP         0x0006
#define CCA_APP_IMPS        0x0007
#define CCA_APP_EMAIL       0x0008
#define CCA_APP_SYNCMLDS    0x0009
#define CCA_APP_SYNCMLDM    0x000A
#define CCA_APP_FOTA        0x000B

#define CCA_GET_APP(x) (x & 0x00FF)


#define CCA_CONFIG_TEST         (CCA_APP_TEST    | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_DTACCT       (CCA_APP_DTACCT  | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_WLAN         (CCA_APP_WLAN    | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_BROWSER      (CCA_APP_BROWSER | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_MMS          (CCA_APP_MMS     | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_SIP          (CCA_APP_SIP     | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_IMPS         (CCA_APP_IMPS    | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_EMAIL        (CCA_APP_EMAIL   | CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_SYNCMLDS     (CCA_APP_SYNCMLDS| CCA_SPEC_OMA | CCA_CATE_NULL)
#define CCA_CONFIG_SYNCMLDM     (CCA_APP_SYNCMLDM| CCA_SPEC_OMA | CCA_CATE_NULL)
#ifdef __MMI_WLAN_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_FOTA_OTAP_DMP__
/* under construction !*/
/* under construction !*/
#endif



/***** Namespace Convension
 * Each symbol = 2 bytes const (16 bits)
 * Namespace ID = higher 6 bits = 64 namespaces (inc all specs + apps)
 * Symbol ID = lower 10 bits = 1024 symbols in each namespace
 */
// xxxx xx00 0000 0000
#define CCA_NS_TEST     0x0000
#define CCA_NS_CCA      0x0400
#define CCA_NS_VAL	    0x0800
#define CCA_NS_OMA	    0x0C00

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
#endif

#define CCA_NS__NULL    0xFFFF
#define CCA_NS_CLEARNS	0x03FF


/***** OMA Client Provisioning Value Symbols Section
 * Each value symbol = lower 10 bits of a symbol identifier
 * to clearly distinguish between values in various nodes (especially between offical and proprietary spec)
 * value symbols section is further divided into 2 parts:
 *     Namespace ID = upper 6 bits = 64 namespaces
 *     Value Section ID = mid 4 bits = 16 value sections
 *     Value Symbol ID = lower 6 bits = 64 value symbols per section
 * shall 64 symbols not sufficient for a particular value section
 * a second value section may be declared to store the remaining value symbols of that section.
 */
// 0000 00xx xx00 0000
#define CCA_NS_VAL__SECTION_NULL    (0x0040 | CCA_NS_VAL)
#define CCA_NS_VAL__SECTION_OMA     (0x0080 | CCA_NS_VAL)

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) || defined(__MMI_FOTA_OTAP_DMP__)
/* under construction !*/
#endif

#endif  /* MMI_CCACONST_H */
