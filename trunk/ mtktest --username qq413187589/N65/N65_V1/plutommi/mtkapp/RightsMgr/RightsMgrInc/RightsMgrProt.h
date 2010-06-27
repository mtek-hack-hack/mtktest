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
 *  RightsMgrProt.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Header file for Rights Manager internal usage
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
#ifndef __RIGHTSMGRPROT_H__
#define __RIGHTSMGRPROT_H__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "EventsGProt.h"
#include "GlobalDefs.h"
#include "GlobalMenuItems.h"

#include "RightsMgrResDef.h"
#include "app_datetime.h"
#include "FileMgr.h"
#include "drm_gprot.h"

#ifdef __MMI_RMGR__
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_RMGR_LIST_RO_NUM (10)
#define MMI_RMGR_WHITE_LIST_NUM (5)
#define MMI_RMGR_WHITE_LIST_URL_MAX_LEN (128)
#define MMI_RMGR_MAX_GEN_INFO_NUM (5)
#define MMI_RMGR_MAX_HTTP_PROFILE_NUM (5)

typedef enum
{
    MMI_RMGR_RO_DETAIL_STATUS,
    MMI_RMGR_RO_DETAIL_SHAREABLE,
/*    
    MMI_RMGR_RO_DETAIL_DOMAIN,
    MMI_RMGR_RO_DETAIL_COUNT,
    MMI_RMGR_RO_DETAIL_LEFT,
*/    
    MMI_RMGR_RO_DETAIL_TOTAL
}mmi_rmgr_ro_detail_enum;

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* rights manager context structure */
typedef struct
{
    MMI_BOOL trans_state;
    U8 rmgr_sel_idx;    /* rights manager selection index */

    /* list ro */
    S8 alias[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    S32 ro_idx;
    
    /* white list */
    U8 url_sel_idx;  /* white list url selection index */
    S8 input_buffer[(MMI_RMGR_WHITE_LIST_URL_MAX_LEN + 1) *ENCODING_LENGTH];
    
    S32 current_idx;
} mmi_rmgr_cntx_struct;

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
extern mmi_rmgr_cntx_struct *const mmi_rmgr_p;
extern const U16 g_mmi_rmgr_number_icons[];

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void mmi_rmgr_list_ro_entry_main(void);
extern void mmi_rmgr_whitelist_entry_main(void);
extern void mmi_rmgr_gen_info_entry_main(void);
extern void mmi_rmgr_sweep_entry_main(void);
extern void mmi_rmgr_http_profile_entry_main(void);
extern void mmi_rmgr_ui_init(void);
extern void mmi_rmgr_send_sweep_req(S32 index);
extern U16 mmi_rmgr_get_root_icon(void);
extern void mmi_rmgr_send_process_database_req(kal_uint8 type, kal_int32 index, kal_wchar *path);
extern void mmi_rmgr_send_process_database_cnf(void *msg);
extern void mmi_rmgr_entry_db_progressing(void);
extern void mmi_rmgr_entry_db(void);
extern void mmi_rmgr_entry_fmgr(void);
extern kal_bool mmi_rmgr_populate_drm_info_aux(kal_wchar *path, kal_uint8 app_perm, kal_uint8 *data, kal_int32 ref);
#endif /* __MMI_RMGR__ */

/***************************************************************************** 
 * External Function 
 *****************************************************************************/
#ifdef __DRM_SUPPORT__
extern kal_int32 DRM_get_ro_num(void);
extern kal_bool DRM_get_ro_list(kal_int32 index, kal_char *alias, kal_uint32 size);
extern kal_bool DRM_free_ro_list(void *);
extern kal_bool DRM_toggle_tracking(kal_bool to_get);
extern kal_int32 DRM_get_domain_num(void);
extern kal_bool DRM_get_trust_state(void);
extern kal_bool DRM_get_ro_shareability(kal_int32 index);
extern kal_bool DRM_get_ro_status(kal_int32 index);
extern kal_int32 DRM_get_version(void);
extern kal_uint8 DRM_get_object_method_by_ref(kal_int32 ro_index);
extern kal_int32 DRM_get_constraint_by_ref(kal_int32 ro_index, kal_uint8 permission, drm_constraint_struct *cons);
extern void DRM_free_ro_detail(void);
extern kal_bool DRM_get_whitelist(kal_char *list_buffer, kal_uint8 index);    
extern kal_int32 DRM_add_whitelist(kal_char *list_buffer);
extern kal_bool DRM_del_whitelist(kal_char *list_buffer);
extern void DRM_free_whitelist(void);

extern kal_bool DRM_get_secure_time(applib_time_struct *time);
#endif
#endif /* __RIGHTSMGRPROT_H__ */ 

