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
 * ProfileMgrGProt.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__

#ifndef _PROFILE_MGR_GPROT_H_
#define _PROFILE_MGR_GPROT_H_

/* Check dependence header files exist */
#ifndef _FILE_MGR_H_
#error "FileMgr.h should be included"
#endif 

/***************************************
 * Defination
 ***************************************/
#define MAXIMUM_EXT_MELODY_NUM            5
#define PMG_EXT_MELODY_BEGIN                  (NV_RAM_FILE_EXT_MELODY_ID_BASE)
#define PMG_EXT_MELODY_END                     (PMG_EXT_MELODY_BEGIN + MAXIMUM_EXT_MELODY_NUM-1)

/*
 * #define MAX_EXT_MELODY_EXTENSION_WIDTH    ((5+1)*ENCODING_LENGTH)
 * #define MAX_EXT_MELODY_PREFIX_WIDTH       ((31+1)*ENCODING_LENGTH)
 */

#define MAX_EXT_MELODY_PATH_WIDTH        ( ((FMGR_MAX_PATH_LEN>>1)+1) * ENCODING_LENGTH)
#define MAX_EXT_MELODY_NAME_WIDTH         ( (FMGR_MAX_FILE_LEN+1) * ENCODING_LENGTH )
#define MAX_EXT_MELODY_FULLNAME_WIDTH        ( MAX_EXT_MELODY_PATH_WIDTH +                                     \
                                                                                   MAX_EXT_MELODY_NAME_WIDTH - \
                                                                                   ENCODING_LENGTH )    /* Every width has a null termainate character */

/*
 * handle short & long filename for ext melody
 */
#define IS_EXTMELODY_SHORTNAME(x) ((x)[1] != 0)
#define MARK_EXTMELODY_SHORTNAME(x) ((x)[1] = 1)
#define UNMARK_EXTMELODY_SHORTNAME(x) ((x)[1] = 0)

/***************************************
 * Type Defination
 ***************************************/
typedef struct
{
    U8 filepath[MAX_EXT_MELODY_PATH_WIDTH];
    U8 filename[MAX_EXT_MELODY_NAME_WIDTH];
    U16 id;
} DYNEXTMELODYELEM;

typedef struct
{
    U32 ValidBit;
    U8 TotleNum;
    DYNEXTMELODYELEM info[MAXIMUM_EXT_MELODY_NUM];
} DYNEXTMELODYINFO;

typedef enum
{
    PMG_ADDFILE_ERR_UNKNOWN,
    PMG_ADDFILE_ERR_SUCCESS,
    PMG_ADDFILE_ERR_STR_TOO_LONG,
    PMG_ADDFILE_ERR_STRFILE_TOO_LONG,
    PMG_ADDFILE_ERR_STRPATH_TOO_LONG,
    PMG_ADDFILE_ERR_SLOT_FULL,
    PMG_ADDFILE_ERR_SLOT_OCCUPIED,
    PMG_ADDFILE_ERR_INVAILD_NAME,
    PMG_ADDFILE_ERR_FILE_TOO_LARGE,
    PMG_ADDFILE_ERR_DUPLICATED,
    PMG_ADDFILE_ERR_DRM_PROHIBTED,

    PMG_ADDFILE_ERR_LAST
} PMG_ADDFILE_ERRNO;

typedef enum
{
    PMG_FMGR_DEL_UNKNOW,

    PMG_FMGR_DEL_CERTAIN,
    PMG_FMGR_DEL_ALL,

    PMG_FMGR_DEL_LAST
} PMG_DELFILE_ACTION;

/***************************************
 * Extern Function Declaration
 ***************************************/
extern pBOOL PmgIsEmptySlot(U8 slot);
extern BOOL PmgIsIdExist(U32 soundId);
extern BOOL PmgQueryFileExistById(U32 soundId);
extern BOOL PmgQueryFileExistBySlot(U8 slot);
#ifdef __DRM_SUPPORT__
extern BOOL PmgQueryFileDRMForwardableBySlot(U8 slot);
#endif
extern U8 PmgFindFirstEmptySlot(void);
extern U8 PmgGetExtMelodyNum(void);
extern U8 PmgGetExtMelodyInfo(DYNEXTMELODYINFO **ExtMelodInfo);
extern pBOOL PmgDelExtMelodyByPathFileName(S8 *pathfileName);
extern void PmgFmgrAddExtMelodyFunc(S8 *pathfileName);
extern BOOL PmgFmgrDelExtMelodyFunc(S8 *pathfileName, PMG_DELFILE_ACTION action);
extern PMG_ADDFILE_ERRNO PmgAddExtMelodyByPathFileName(S8 *pathfileName);      /* fileName is unicode */
extern PMG_ADDFILE_ERRNO PmgReplaceExtMelodyBySlotPathFileName(S8 *pathfileName, U8 freeSlot); /* fileName is unicode */
extern PMG_ADDFILE_ERRNO PmgAddExtMelodyBySlotPathFileName(S8 *pathfileName, U8 freeSlot);     /* fileName is unicode */
extern PMG_ADDFILE_ERRNO PmgSeparateFilePathName(
                            S8 *pathfileName,
                            S8 *pathname,
                            U16 pathsize,
                            S8 *filename,
                            U16 filesize);
extern U8 PmgGetSlotByPathFileName(S8 *pathfileName);
extern S8 *PmgGetFileNameByFilePath(S8 *pathfileName);
extern void PmgGetExtMelodyRange(U32 *startId, U32 *totalId);
extern pBOOL PmgGetFilePathNameByAudioId(S8 *buf, U16 size, U16 AudioId);

//void PmgSendPlayExtMelodyMsg(S8 *filename);
//void PmgSendStopExtMelodyMsg(void);
extern void PmgDelExtMelodyBySlot(U8 slot);
extern pBOOL PmgDelExtMelodyById(U16 id);
extern U8 PmgGetSlotById(U16 Id);
extern void PmgConstructPathFileName(S8 *buf, U16 size, S8 *path, S8 *file);
extern S8 *PmgGetFileExt(S8 *buf);
extern PMG_ADDFILE_ERRNO PmgCheckImyMidFileSize(S8 *path);
extern void PmgRemoveFileExt(S8 *buf);      /* Notice! This function will change the buffer context */
extern void PmgRemoveFileDAFExt(S8 *buf);   /* Notice! This function will change the buffer context */
extern void PmgSetShortFileName(BOOL is_short);

#endif /* _PROFILE_MGR_GPROT_H_ */ 

#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

