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
 *
 * Filename:
 * ---------
 *   dcmgr.h
 *
 * Project:
 * --------
 *   MAUI (MT6226/MT6227/MT6228/MT6229)
 *
 * Description:
 * ------------
 *   Dynamic Code Manager for dynamic code relocation into TCM(internal SRAM)
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
*  Maintenance / Configuration Notes
*  ================================================================================
*   
*  Definitions :
*  ==============
*   
*  DYNAMIC_CODE_NUM         : Total number of DCM candidates (regardless of DCM 
*                             target pool)
*  DYNAMIC_CODE_XXX         : Identity number of DCM candidate, must be an
*                             incremental number
*                             Note, must not change the pre-fix DYNAMIC_CODE_
*  DCM_TARGET_NUM           : Total number DCM target pools
*  DCM_TARGET_ADDRESSx      : Start Address of DCM target pool x, must be consistent
*                             with scattter file
*  DCM_TARGET_SIZEx         : Size of DCM target pool x
*
*  DCM_SCAT_CODEx_AVAILABLE : The xth DCM identity is available for certain BB-chip
*  
*  DCM_TARGET_CONFIGURE     : Specify DCM target pool of the entire DCM candidates
*                             according to their identity
*                          
*  SOP to add-in a new DCM candidates :
*  =====================================
*  New candidate, DYNAMIC_CODE_EXAMMPLE
*
*  STEP 1 :  increment DYNAMIC_CODE_NUM by 1 and define identity number for 
*            new DCM candidate
*
*            #define DYNAMIC_CODE_NUM        N
*            #define DYNAMIC_CODE_EXAMMPLE  (N-1)
*            
*  STEP 2 :  edit scatter file
*
*  STEP 3 :  change the DCM_TARGET_NUM, and create DCM_TARGET_ADDRESSx
*            together with DCM_TARGET_SIZEx in case of new DCM target pool 
*            is needed
*            
*  STEP 4 :  define DCM_SCAT_CODEN_AVAILABLE for specific BB-chip if it
*            is not common candidates
*  
*  STEP 5 :  specify DCM target pool ID for all DCM candidates
*            Despite of availability, each DCM ID must be specified with a 
*            DCM target pool, 0 if unavailable
*
*  STEP 6 :  edit dcmgr.c, declare the correspondence linker symbol, and 
*            assign as an entry of DCM_linker_symbols_by_dynamic_code_id[].
*
*  STEP 7 :  in case of new DCM target pool added, create a new entry 
*            for the following array in dcmgr.c
*            current_dynamic_code_id[]
*            DCM_target_pool_addr[]
*            DCM_target_pool_size[]
*
*****************************************************************************/

#ifndef __DCMGR_H
#define __DCMGR_H

#include "kal_release.h"

#if ( !defined(MT6208) && !defined(MT6205B) && !defined(MT6217) && !defined(MT6218B) && !defined(MT6219) )

#define DYNAMIC_CODE_MANAGER

/* define dynamic code information */
#define DYNAMIC_CODE_NUM      6
#define DYNAMIC_CODE_NONE     -1
#define DYNAMIC_CODE_AMR515   0
#define DYNAMIC_CODE_G3D      1
#define DYNAMIC_CODE_CTM      2
#define DYNAMIC_CODE_G729     3
#define DYNAMIC_CODE_SBC      4
#define DYNAMIC_CODE_BCODE    5


#if defined(MT6228) || defined(MT6229)  || defined(MT6230)
extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE2$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        2
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE2$$Base)
#define DCM_TARGET_SIZE2      0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6238)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5002D000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5002A800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE7_AVAILABLE   /* AUD_REVERB */
#define DCM_SCAT_CODE8_AVAILABLE   /* AUD_RESAMPLE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0

/* ---------------------------------------------------------------------------------- */
#elif defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)
extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE6_AVAILABLE   /* BCODE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,1

/* ---------------------------------------------------------------------------------- */
#elif defined(MT6225)
extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0

/* ---------------------------------------------------------------------------------- */
#elif defined(MT6223) || defined(MT6223P)
extern kal_uint32 Image$$DYNAMIC_CODE3$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE3$$Base)
#define DCM_TARGET_SIZE1      0x1280      /* 4736 Bytes */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  0,0,1,0,1,0

#else

#error Overlay region for dynamic code relocation should be determined for new chipset

#endif

/* Dynamic code manager for relocate code into the overlay TCM region */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size );
void DCM_Unload( kal_int32 dynamic_code_id );
kal_bool DCM_Isloaded( kal_int32 dynamic_code_id );

#endif /* !MT6205B && !MT6217 && !MT6218B && !MT6219 */

#endif
