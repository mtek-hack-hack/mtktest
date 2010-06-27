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
 *	fs_quota.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *    This file defines quota setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __FS_QM_SUPPORT__

#ifndef _KAL_RELEASE_H
#include "kal_release.h"
#endif

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

#ifdef __J2ME__
#include "j2me_custom_param.h"
#endif /* __J2ME__ */

#include "customer_ps_inc.h"

#ifdef __EMAIL__
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"    /* local/peer struct */

#include "rtc_sw.h"

#include "email_mmi.h"
#include "email_export.h"
#endif

#include "nvram_user_defs.h"

#ifdef WAP_SUPPORT
#include "custom_wap_config.h"
#endif

/************************ Description of QuotaSet ************************************************
QuotaStruct: {Path in bytes, Priority, Qmin in bytes, Qmax in bytes, Uint}
Rule:
1. Path
   (1) Capital 'Z' in Path means the primary system drive
   (2) The character unit of Path is in byte
   (3) Except the default null end entry, path cannot be NULL and must be
       ended with backslash
   (4) The first char of each folder must be '@'
       Example: "E:\\@Folder\\"
   (5) Only support one level folder
       Example: "E:\\@Folder1\\@SubFolder\\" is invalid
2. Priority:
   FS_QP_HIG_ENUM (1) - Cannot be removed anyway except over quota (version upgrade)
   FS_QP_MID_ENUM (2) - Always removed entirely if over quota.
                        Optional removed if RFS is not enough.
   FS_QP_LOW_ENUM (3) - Always removed entirely if over quota.
                        Optional removed if RFS is not enough.
   FS_QP_DEL_ENUM (4) - Always removed entirely when booting up
3. Qmin (lower bound - reserved space) & Qmax (upper bound - quota space)
   (1) Qmax can set to be unlimited (FS_QMAX_NO_LIMIT)
   (2) 0 <= Qmin <= Qmax < FS_QMAX_NO_LIMIT
   (3) RFS (Required Free Space):
       (Qnow, the space you have used, is internal data tracked inside File System)
         for each entry
         {
            if(Qmin > Qnow)
               RFS += (Qmin - Qnow);
         }
   (4) MRS (Minimum Reserved Space) =
         (Qmin of FS_QP_DEL_ENUM) + (Qmin of FS_QP_LOW_ENUM) +
         (Qmin of FS_QP_MID_ENUM) + (Qmin of FS_QP_HIG_ENUM)
   (5) Note that NVRAM is a special case in Quota Management. File System will
       reserve the space for NVRAM at runtime automatically. You don't have to
       anything about NVRAM here.
       If (MRS + NVRAM) is over drive size, assertion will be issued when boot up check
   (6) Note that if you have 100 files under system drive and each one of them
       is just 3 bytes, you have to reserve (100* ClusterSize),
       not (100*3) bytes. Because the physical allocation unit in File System is in "cluster"
   (7) If you don't know how to count the space, you can use FS_GetFolderSize()
       in file system to help you evalute the size at development stage
4. Uint:
   FS_COUNT_IN_BYTE     : Indicate the Qmin and Qmax setting are counted in byte
   FS_COUNT_IN_CLUSTER  : Indicate the Qmin and Qmax setting are counted in cluster
*/

/************************ SweepCheck Flow ************************
1. Check each folder or file under root directory
2. If folder with DEL priority (listed in the QuotaSet table) is found, remove it entirely
3. If folder listed in the QuotaSet table is over quota, remove it entirely
4. If RFS is not enough for QuotaSet, jump to step 6
5. Return
6. If memory is not enough (1K+ 0.5K control buffer), jump to step 5
7. If file is found, remove it
   Else jump to step 9
8. If RFS is enough, jump to step 5
   Else jump to step 7
9. If folder not defined in the QuotaSet table is found, remove it entirely
   Else jump to step 11
10.If RFS is enough, jump to step 5
   Else jump to step 9
11.If folder with LOW priority (listed in the QuotaSet table) is found, remove it entirely
   Else jump to step 14
12.Update RFS to RFS' (because some space is freed by LOW)
13.If RFS' is enough, jump to step 5
   Else jump to step 11
14.If folder with MID priority (listed in the QuotaSet table) is found, remove it entirely
15.Jump to step 5
*/

/************************ QM Run Time Monitor ************************
1. If deletion, Qnow will be updated then
2. If need to allocate, check as step 3
3. If (over quota) return FS_DISK_FULL
   Else if (RFS for others is not enough) return FS_DISK_FULL
   Else if (Drive free is not enough for the allocation)  return FS_DISK_FULL
   Else update Qnow after allocation
*/

/************************ User Configuration ************************/
//Set your entry below
//Max quota set entry number is 40
const FS_QuotaStruct gFS_ExtQuotaSet[] =
{
            {"Z:\\@FACTORY\\",   FS_QP_HIG_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#ifdef __DRM_SUPPORT__
            {"Z:\\@DRM\\",       FS_QP_HIG_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@DRM_ro\\",    FS_QP_HIG_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@DRM_dec\\",   FS_QP_DEL_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef WAP_SUPPORT
   #ifdef OBIGO_Q03C
      #ifdef MMS_SUPPORT
        #ifdef __MMI_DUAL_SIM__
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM, 160*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #else
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM, 150*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
            {"Z:\\@wcache\\",    FS_QP_DEL_ENUM,  50*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
         #ifndef MMS_IN_LARGE_STORAGE
            {"Z:\\@mms\\",       FS_QP_HIG_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
         #endif
         #if defined(__DRM_SUPPORT__)
            {"Z:\\@MMS_DRM\\",   FS_QP_DEL_ENUM, 100*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@BRA_DRM\\",   FS_QP_DEL_ENUM,   4*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
         #endif /* __DRM_SUPPORT__ */
      #else /* MMS_SUPPORT */
        #ifdef __MMI_DUAL_SIM__
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM,  90*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #else
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM,  80*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
        #endif
            {"Z:\\@wcache\\",    FS_QP_DEL_ENUM,  50*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
      #endif /* MMS_SUPPORT */
   #elif defined(JATAAYU_SUPPORT)
       #if defined(MMS_SUPPORT) && !defined(MMS_IN_LARGE_STORAGE)
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM, 210*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@mms\\",       FS_QP_HIG_ENUM, 100*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
       #else /* defined(MMS_SUPPORT) && !defined(MMS_IN_LARGE_STORAGE) */ 
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM, 310*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
       #endif /* defined(MMS_SUPPORT) && !defined(MMS_IN_LARGE_STORAGE) */ 
   #elif defined(OBIGO_Q05A)
            {"Z:\\@wap\\",       FS_QP_HIG_ENUM, 200*1024,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
      #if defined(MMS_SUPPORT) && !defined(MMS_IN_LARGE_STORAGE)
            {"Z:\\@mms\\",       FS_QP_HIG_ENUM,        0,  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
      #endif
   #endif
#endif /* WAP_SUPPORT */

#ifdef __EMAIL__
#ifndef __NO_IMAP__
#define EMAIL_PS_IMAP_QUOTA_PER_FOLDER_CACHE_SIZE ( \
			sizeof(kal_uint32) + \
			sizeof(kal_uint16) + \
			sizeof(imap_cache_list_struct) * (IMAP_CACHE_MAX_ENTRY_NUM_PER_MAILBOX) \
			)
			
#define EMAIL_PS_IMAP_QUOTA_PER_FOLDER_UIDL_SIZE ( \
			16 + \
			sizeof(kal_uint16) + \
			sizeof(kal_uint32) * (IMAP_CACHE_MAX_ENTRY_NUM_PER_MAILBOX) \
			)
			
#define EMAIL_PS_IMAP_QUOTA_PER_FOLDER_SIZE ( \
			(EMAIL_PS_IMAP_QUOTA_PER_FOLDER_CACHE_SIZE) + \
			(EMAIL_PS_IMAP_QUOTA_PER_FOLDER_UIDL_SIZE) \
			)
			
#define EMAIL_PS_IMAP_QUOTA_TOTAL_SIZE \
			((EMAIL_PS_IMAP_QUOTA_PER_FOLDER_SIZE) * (MMI_EMAIL_MAX_FOLDERS))
#else /* __NO_IMAP__ */
#define EMAIL_PS_IMAP_QUOTA_TOTAL_SIZE 0
#endif /* __NO_IMAP__ */

#ifdef __MMI_EMAIL_DRM_SUPPORT__
#define EMAIL_PS_DRM_QUOTA_SIZE     MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE
#else
#define EMAIL_PS_DRM_QUOTA_SIZE     0
#endif

	         {"Z:\\@email_sys\\", FS_QP_HIG_ENUM, ((8+EMAIL_MAX_MSG_NUM*sizeof(email_nv_mb_entry_struct))*2)+4216+1024+MMI_EMAIL_MAX_MSG_SIZE+10*1024
              +(sizeof(email_nv_uidl_entry_struct)*EMAIL_UIDL_ENTRY_NUM+2048)+(sizeof(pop3_msg_uid_struct)*EMAIL_MAX_UIDL_NUM + 
			  EMAIL_PS_IMAP_QUOTA_TOTAL_SIZE + MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE * 2 + EMAIL_PS_DRM_QUOTA_SIZE),
			  FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},	         
	         {"Z:\\@email\\",     FS_QP_HIG_ENUM, 0,         FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __EMAIL__ */

#ifdef __EMS_SUPPORT__
            {"Z:\\@Image\\",     FS_QP_HIG_ENUM,       0,   FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
            {"Z:\\@Audio\\",     FS_QP_HIG_ENUM,       0,   FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __EMS_SUPPORT__ */

#ifdef __J2ME__
            {"Z:\\@Java\\",      FS_QP_MID_ENUM,200*1024,
             (DEFAULT_MAX_STORAGE_SPACE ? DEFAULT_MAX_STORAGE_SPACE : FS_QMAX_NO_LIMIT), FS_COUNT_IN_BYTE},
#endif  /* __J2ME__ */

#ifdef VR_CYBERON
            {"Z:\\@VRDB\\",      FS_QP_HIG_ENUM, 58*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},   // (2.85 * 20) + 1 = 58
#elif defined( VR_ITRI )
            {"Z:\\@VRDB\\",      FS_QP_HIG_ENUM, 85*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},   // (4.2 * 20) + 1 = 85
#endif /* VR */

            {"Z:\\@USER\\",      FS_QP_MID_ENUM,       0, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},

#ifdef __IMPS__
            {"Z:\\@imps\\",      FS_QP_HIG_ENUM, 80*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE}, //MMI 35K + IMPS 45K
#endif /* __IMPS_ */

#ifdef __XDM__
            {"Z:\\@pocxdm\\",    FS_QP_HIG_ENUM, 30*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __XDM__ */

#ifdef __POC__
            {"Z:\\@poc\\",       FS_QP_HIG_ENUM, 30*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __POC__ */

#ifdef __SIP__
            {"Z:\\@sip\\",       FS_QP_HIG_ENUM, 30*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __SIP__ */

#if defined (__MMI_FTC_SUPPORT__) && defined (__MMI_FTS_SUPPORT__)
            {"Z:\\@ftp\\",       FS_QP_HIG_ENUM, 60*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#elif defined(__MMI_FTS_SUPPORT__)
            {"Z:\\@ftp\\",       FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#else
            {"Z:\\@ftp\\",       FS_QP_HIG_ENUM, 40*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __MMI_AVATAR__
            {"Z:\\@avatar\\",    FS_QP_HIG_ENUM,    200*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef SWFLASH_NEOMTEL
            {"Z:\\@swflash\\",    FS_QP_HIG_ENUM,    300*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif

#ifdef __CSTAR__
            {"Z:\\@ime\\",       FS_QP_HIG_ENUM,    32*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE}, // fixed size 32Kb
#endif

#ifdef __MMI_BPP_SUPPORT__
            {"Z:\\@bpp\\",       FS_QP_HIG_ENUM, 10*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_BPP_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            {"Z:\\@SMSArch\\",   FS_QP_HIG_ENUM, CM_SMS_MAX_ARMSG_NUM*100, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __MMI_VIDEO_STREAM__
            {"Z:\\@VideoStream\\", FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_RECORDER__
            {"Z:\\@Video\\",     FS_QP_HIG_ENUM, 1*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef SYNCML_DM_SUPPORT
            {"Z:\\@dm\\",       FS_QP_HIG_ENUM, 32*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* SYNCML_DM_SUPPORT */

#ifdef __BT_BIP_PROFILE__
            {"Z:\\@bip\\",       FS_QP_HIG_ENUM, 20*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __BT_BIP_PROFILE__ */

#ifdef __CERTMAN_SUPPORT__
            {"Z:\\@certman\\",       FS_QP_HIG_ENUM, 80*1024, FS_QMAX_NO_LIMIT, FS_COUNT_IN_BYTE},
#endif /* __CERTMAN_SUPPORT__ */

   {NULL, 0, 0, 0, 0} //Entry for End
};

/************* Do not modify anything behind this line *************/
#ifndef __MTK_TARGET__
#define FS_MAX_QSET 32
#elif defined(BUILD_TIME_CHECK_GEN)
#define FS_MAX_QSET 32
#else
const UINT FS_MAX_QSET = ((sizeof(gFS_ExtQuotaSet)/sizeof(FS_QuotaStruct)) - 1);
#endif
FS_InternQStruct gFS_IntQuotaSet[FS_MAX_QSET+1]; //each entry size is 12 bytes

#endif // __FS_QM_SUPPORT__


