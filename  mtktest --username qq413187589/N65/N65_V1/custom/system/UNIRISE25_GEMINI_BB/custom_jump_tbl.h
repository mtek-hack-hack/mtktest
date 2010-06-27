/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_jump_tbl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for indirect jump table for multiple binary load
 *
 * Author:
 * -------
 *   system auto generator V0.30
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_JUMP_TBL_H_
#define _CUSTOM_JUMP_TBL_H_

#if ( (defined(__MTK_TARGET__) || defined (MTK_KAL_MNT) || defined(KAL_ON_OSCAR) ) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__) ) 

#include "kal_release.h"
#include "resource_verno.h"

extern const Type_Preamble_Content system_jump_table[];

//__CUSTPACK_MULTIBIN
typedef enum 
{
   JUMP_TABLE_ENTRY_START, 
   
   JUMP_TABLE_ENTRY_LANG_PACK = JUMP_TABLE_ENTRY_START, 
   JUMP_TABLE_ENTRY_CUSTPACK,
   JUMP_TABLE_ENTRY_AUTOGEN_AUDIO,
   JUMP_TABLE_ENTRY_END = JUMP_TABLE_ENTRY_CUSTPACK

} JUMP_TABLE_ENTRY_ENUM;


#define JUMP_TABLE_ENTRY_END              JUMP_TABLE_ENTRY_CUSTPACK


/* Macros for addressing each resource */
#define GET_Res_Addr(R, X)                (((kal_uint32 *) (system_jump_table[R].StartAddress)) + X)
#define GET_Res_ProjectID(X)              (system_jump_table[X].ProjectID)
#define GET_Res_Magic(X)                  (system_jump_table[X].Magic)


#if defined(MULTIPLE_BINARY_FILES) && defined(__MTK_TARGET__)


extern Type_Preamble_Content AudioResPreamble;
extern void* audio2ndJumpTbl[];

extern Type_Preamble_Content AutogenAudioResPreamble;
extern void* autogenaudio2ndJumpTbl[];

extern Type_Preamble_Content ImageResPreamble;
extern void* image2ndJumpTbl[];

#ifdef __J2ME__
extern Type_Preamble_Content J2MEResPreamble;
extern void* J2ME2ndJumpTbl[];
#endif /*__J2ME__*/

#define CONST_RES_IMAGE_ADDR              ((kal_uint32 *)&ImageResPreamble)
#define CONST_RES_IMAGE_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_IMAGE_CONTENT_SIZE      ((kal_uint32)0)
#define CONST_RES_AUDIO_ADDR              ((kal_uint32 *)&AudioResPreamble)
#define CONST_RES_AUDIO_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_AUDIO_CONTENT_SIZE      ((kal_uint32)0)

#define CONST_RES_AUTOGEN_AUDIO_ADDR              ((kal_uint32 *)&AutogenAudioResPreamble)
#define CONST_RES_AUTOGEN_AUDIO_TBL_SIZE          ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_CONTENT_SIZE      ((kal_uint32)0)

#ifdef __J2ME__
#define CONST_RES_J2ME_ADDR               ((kal_uint32 *)&J2MEResPreamble)
#define CONST_RES_J2ME_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_J2ME_CONTENT_SIZE       ((kal_uint32)0)
#endif /*__J2ME__*/  


/* Macros below specific for multiple binary files or multiple load segments only */
/* Collection of Lang Pack */
extern kal_uint32  Load$$LANG_PACK_ROM$$Base;
extern kal_uint32  Image$$LANG_PACK_ROM$$Length;
extern kal_uint32  Image$$LANG_PACK_ROM_CONTENT$$Length;

//__CUSTPACK_MULTIBIN__
extern kal_uint32  Load$$CUSTPACK_ROM$$Base;
extern kal_uint32  Image$$CUSTPACK_ROM$$Length;
extern kal_uint32  Image$$CUSTPACK_ROM_CONTENT$$Length;


/* macro of resource address and size for const arrary initialization */
#define GET_ResLangPack_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_LANG_PACK, X)
#define CONST_RES_LANG_PACK_ADDR          (&Load$$LANG_PACK_ROM$$Base)
#define CONST_RES_LANG_PACK_TBL_SIZE      ((kal_uint32)&Image$$LANG_PACK_ROM$$Length)
#define CONST_RES_LANG_PACK_CONTENT_SIZE  ((kal_uint32)&Image$$LANG_PACK_ROM_CONTENT$$Length)


//__CUSTPACK_MULTIBIN__
#define GET_ResCUSTPACK_Addr(X)           GET_Res_Addr(JUMP_TABLE_ENTRY_CUSTPACK, X)
#define CONST_RES_CUSTPACK_ADDR           (&Load$$CUSTPACK_ROM$$Base)
#define CONST_RES_CUSTPACK_TBL_SIZE       ((kal_uint32)&Image$$CUSTPACK_ROM$$Length)
#define CONST_RES_CUSTPACK_CONTENT_SIZE   ((kal_uint32)&Image$$CUSTPACK_ROM_CONTENT$$Length)



#else /* MULTIPLE_BINARY_FILES && __MTK_TARGET__ */

extern Type_Preamble_Content AudioResPreamble;
extern void* audio2ndJumpTbl[];
extern Type_Preamble_Content AutogenAudioResPreamble;
extern void* autogenaudio2ndJumpTbl[];
extern Type_Preamble_Content ImageResPreamble;
extern void* image2ndJumpTbl[];
extern Type_Preamble_Content LangPackResPreamble ;
extern void* langpack2ndJumpTbl[];

#ifdef __J2ME__
extern Type_Preamble_Content J2MEResPreamble;
extern void* J2ME2ndJumpTbl[];
#endif /*__J2ME__*/

extern Type_Preamble_Content CustPackResPreamble ;
extern void* custpack2ndJumpTbl[];


#define CONST_RES_IMAGE_ADDR                   ((kal_uint32 *)&ImageResPreamble)
#define CONST_RES_IMAGE_TBL_SIZE               ((kal_uint32)0)
#define CONST_RES_IMAGE_CONTENT_SIZE           ((kal_uint32)0)
#define CONST_RES_AUDIO_ADDR                   ((kal_uint32 *)&AudioResPreamble)
#define CONST_RES_AUDIO_TBL_SIZE               ((kal_uint32)0)
#define CONST_RES_AUDIO_CONTENT_SIZE           ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_ADDR           ((kal_uint32 *)&AutogenAudioResPreamble)
#define CONST_RES_AUTOGEN_AUDIO_TBL_SIZE       ((kal_uint32)0)
#define CONST_RES_AUTOGEN_AUDIO_CONTENT_SIZE   ((kal_uint32)0)
#define CONST_RES_LANG_PACK_ADDR               ((kal_uint32 *)&LangPackResPreamble)
#define CONST_RES_LANG_PACK_TBL_SIZE           ((kal_uint32)0)
#define CONST_RES_LANG_PACK_CONTENT_SIZE       ((kal_uint32)0)
#define CONST_RES_CUSTPACK_ADDR                ((kal_uint32 *)&CustPackResPreamble)
#define CONST_RES_CUSTPACK_TBL_SIZE            ((kal_uint32)0)
#define CONST_RES_CUSTPACK_CONTENT_SIZE        ((kal_uint32)0)

#ifdef __J2ME__
#define CONST_RES_J2ME_ADDR                    ((kal_uint32 *)&J2MEResPreamble)
#define CONST_RES_J2ME_TBL_SIZE                ((kal_uint32)0)
#define CONST_RES_J2ME_CONTENT_SIZE            ((kal_uint32)0)
#endif /*__J2ME__*/


#define GET_ResImage_Addr(X)                   ((kal_uint32 *)&image2ndJumpTbl)
#define GET_ResAudio_Addr(X)                   ((kal_uint32 *)&audio2ndJumpTbl)
#define GET_ResAutogenAudio_Addr(X)            ((kal_uint32 *)&autogenaudio2ndJumpTbl)
#define GET_ResFont_Addr(X)                    ((kal_uint32 *)&font2ndJumpTbl)
#define GET_ResStr_Addr(X)                     ((kal_uint32 *)&str2ndJumpTbl)
#define GET_ResIME_Addr(X)                     ((kal_uint32 *)&IME2ndJumpTbl)
#define GET_ResLangPack_Addr(X)                ((kal_uint32 *)&langpack2ndJumpTbl)
#define GET_ResCUSTPACK_Addr(X)                ((kal_uint32 *)&custpack2ndJumpTbl)

#ifdef __J2ME__
#define GET_ResJ2ME_Addr(X)                    ((kal_uint32 *)&J2ME2ndJumpTbl)
#endif /*__J2ME__*/


#endif /* MULTIPLE_BINARY_FILES && __MTK_TARGET__ */

#endif /* (__MTK_TARGET__ || MTK_KAL_MNT || KAL_ON_OSCAR) && (!__MAUI_BASIC__) && (!__L1_STANDALONE__) */

#endif /* _CUSTOM_JUMP_TBL_H_ */
