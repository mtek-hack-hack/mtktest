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
 * drm_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef DRM_DEF_H
#define DRM_DEF_H

#include "drm_errcode.h"

#define DRM_PERMISSION_NONE         0x00
#define DRM_PERMISSION_PLAY         0x01
#define DRM_PERMISSION_DISPLAY      0x02
#define DRM_PERMISSION_EXECUTE      0x04
#define DRM_PERMISSION_PRINT        0x08
#define DRM_PERMISSION_EXPORT       0x10
#define DRM_PERMISSION_ALL          0x80

#ifdef __DRM_SUPPORT__
#define MAX_PATH_LENGTH       261
#define MAX_KEY_LENGTH        36
#define MAX_ID_LENGTH         256
#define MAX_LINE_LENGTH       128
#define MAX_FILE_HANDLE       32

#define DRM_DEFAULT_WAIT 25 /* seconds */



#define DRM_CONSTRAINT_UNINIT       0x00
#define DRM_CONSTRAINT_COUNT        0x01
#define DRM_CONSTRAINT_DATETIME     0x02
#define DRM_CONSTRAINT_INTERVAL     0x04
#define DRM_CONSTRAINT_NONE         0x08
/* <2.0> */
#define DRM_CONSTRAINT_TIMEDCOUNT   0x10
#define DRM_CONSTRAINT_ACCUMULATED  0X20
#define DRM_CONSTRAINT_INDIVIDUAL   0X40
#define DRM_CONSTRAINT_SYSTEM       0X80

#define DRM_MIMETYPE_MESSAGE            "application/vnd.oma.drm.message"
#define DRM_MIMETYPE_CONTENT            "application/vnd.oma.drm.content"
#define DRM_MIMETYPE_RIGHTS             "application/vnd.oma.drm.rights+xml"
#define DRM_MIMETYPE_RIGHTS_WB          "application/vnd.oma.drm.rights+wbxml"

/* <2.0> */
#define DRM_MIMETYPE_ROAP_PDU           "application/vnd.oma.drm.roap-pdu+xml"
#define DRM_MIMETYPE_ROAP_TRIGGER       "application/vnd.oma.drm.roap-trigger+xml"

typedef enum
{
    DRM_METHOD_NONE = 0,
    DRM_METHOD_FORWARD_LOCK = 1,
    DRM_METHOD_COMBINED_DELIVERY = 2,
    DRM_METHOD_SEPARATE_DELIVERY = 4,
    DRM_METHOD_V2 = 8
} drm_method_enum;

typedef enum
{
    DRM_PROCESS_TYPE_NORMAL,
    DRM_PROCESS_TYPE_VIRTUAL,
    DRM_PROCESS_TYPE_ASYNC,
    DRM_PROCESS_TYPE_BUFFER,
    DRM_PROCESS_TYPE_INVLID
} drm_process_type;

#define DRM_NOR_PATH \
      L"Z:\\@DRM\\"

#define DRM_RO_PATH \
      L"Z:\\@DRM_ro\\"

#define DRM_TEMP_DECRYPTED_FOLDER \
      L"Z:\\@DRM_dec\\"

#define DRM_TEMP_DECODE_FILE \
          L"Z:\\@DRM_dec\\tmp"

#define DRM_MMS_PATH \
      L"Z:\\@MMS_DRM\\"

#define DRM_DEFAULT_APP_PATH "z:\\@DRM\\"
#define DRM_DEFAULT_RP_PATH DRM_DEFAULT_APP_PATH"rp\\"
#define DRM_DEFAULT_CER_PATH DRM_DEFAULT_APP_PATH"bscidrm2\\"
#define DRM_DEFAULT_TEMP_PATH DRM_DEFAULT_APP_PATH"tmp\\"

#define DRM_MAX_XML_SIZE (3*1024)

typedef enum
{
    DRM_STATUS_NO_RIGHTS,
    DRM_STATUS_RIGHTS_PRESENT,
    DRM_STATUS_RIGHTS_IN_FUTURE,
    DRM_STATUS_RIGHTS_PENDING,
    DRM_STATUS_CONTENT_PENDING
} drm_status_enum;

typedef struct
{
    kal_int32 status;
    kal_int32 used_count;
    kal_int32 total_count;
    kal_int32 start_time;
    kal_int32 end_time;
    kal_int32 interval;
    kal_int32 start_intv;
    kal_int32 end_intv;
#ifdef __DRM_V02__
    kal_int32 timed_count;
    kal_int32 total_timed_count;
    kal_uint32 period;
    kal_int32 accum_dur;
    kal_int32 total_accum_dur;
    kal_int32 is_individual;
    kal_uint32 sys_num;
#endif /* __DRM_V02__ */ 
    kal_uint8 type;
} drm_constraint_struct;

#ifdef __DRM_MTK__
#define __DRM_MTK_V1_MULTIPLE_RO__
#endif 

typedef struct
{
    kal_uint8 key[MAX_KEY_LENGTH];
    kal_uint8 issuer[MAX_LINE_LENGTH];
    drm_constraint_struct play;
    drm_constraint_struct display;
    drm_constraint_struct execute;
    drm_constraint_struct print;
    kal_uint32 offset;
    kal_uint32 data_len;
    kal_uint32 mime_type;
    kal_uint32 delta;
    kal_uint8 key_len;
    kal_uint8 permission;
    kal_uint8 status;
    kal_uint8 method;
#ifdef __DRM_MTK_V1_MULTIPLE_RO__
    kal_uint8 PADDING[4];
    kal_uint8 num[4];   /* number of constraint appended after original RO */
    drm_constraint_struct *append_cons;
#endif /* __DRM_MTK_V1_MULTIPLE_RO__ */ 
} drm_rights_struct;

typedef struct
{
    drm_rights_struct rights;
    kal_wchar content_path[MAX_PATH_LENGTH];
    kal_char content_id[MAX_ID_LENGTH];
} drm_info_struct;

typedef void (*drm_activate_callback) (kal_uint8 serial, kal_int32 result);

#endif /* __DRM_SUPPORT__ */ 
#endif /* DRM_DEF_H */ 

