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
 * EmsMiscell.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : MessagesMiscell.h

   PURPOSE     : ---

   REMARKS     : ---

   AUTHOR      : Hiran and Magesh k

   DATE     : ---

**************************************************************/

#ifndef _PIXCOM_EMS_MISCELL_H
#define _PIXCOM_EMS_MISCELL_H

/* MTK added for compile issue */
#include "l4dr.h"
/* MTK end */
#include "MMIDataType.h"
#include "ems.h"

typedef struct
{
    EMSData emsData;
    U8 validFlag;
} msg_ems_data_struct;

/*  */
#if defined(__MMI_MESSAGES_EMS__)
extern U8 GetFmtTextSize(void);
extern void SetFmtTextSize(void);
extern void SetFmtTextStyle(void);
extern U8 GetFmtTextAlignment(void);
extern void SetFmtTextAlignment(void);
extern void SetFmtTextNewParagraph(void);
extern void EntryScrEmsFormatTextMenu(void);
extern void ExitScrEmsFormatTextMenu(void);
extern void EntryScrFmtTextSizeMenu(void);
extern void EntryScrFmtTextStyleMenu(void);
extern void EntryScrFmtAlignmentMenu(void);
extern void EntryScrFmtNewParagraphMenu(void);

extern void HighlightEditOptionInsertObject(void);
extern void HighlightEmsFormattingTextHandler(void);

extern void HighlightInsObjPicture(void);
extern void HighlightInsObjMyPicture(void);
extern void HighlightInsObjPredefinedAnimation(void);
extern void HighlightInsObjMyAnimation(void);
extern void HighlightInsObjMelody(void);
extern void HighlightInsObjMyMelody(void);
extern void HighlightInsObjPredefinedSound(void);

/*  */
extern void EntryEMSObjectList(void);
extern void ExitEMSObjectList(void);
extern void EntryScrInsertObjectMenu(void);
extern void ExitScrInsertObjectMenu(void);
extern void PreEntryScrSaveObjectName(void);
extern void EntryScrSaveObjectName(void);
extern void ExitScrSaveObjectName(void);
extern void EntryScrSaveObjectList(void);
extern void ExitScrSaveObjectList(void);
extern void EntryScrPreviewEmsObject(void);
extern void ExitScrPreviewEmsObject(void);
extern void GetEmsDwonloadObjectDisplayListDetails(U16 *lskStrID, U8 **strItemListPtr);
extern void PreviewEmsObjectIsDone(void);
extern void SaveEmsObjectNameAndDownLoadEmsObject(void);
extern void GetEmsObjectHiliteIndex(S32 nIndex);
extern void ChangeEmsObjectTitleWithIndex(S32 nIndex);
extern void StopEmsObjectIMelodyAndSoundIfAny(void);
extern void PlayEmsManufacturerSound(void);

#if defined(__MMI_IMELODY_SUPPORT__)
extern void PlayWapDownlaodIMelody(void);
extern void PlayUserComposeIMelody(void);
extern void PlayEmsManufacturerIMelody(void);
extern void PlayEmsUserDefinedIMelody(void);
#endif /* defined(__MMI_IMELODY_SUPPORT__) */ 
extern void EntryEmsSaveObjectOption(void);
extern void ExitEmsSaveObjectOption(void);
extern void HighlightEmsSaveObjectDone(void);
extern S32 mmi_ems_create_ems_folder(void);

extern U8 EmsPictureNum(void);

#if defined(__MMI_IMELODY_SUPPORT__)
extern U8 EmsMelodyNum(void);
#endif 
#endif /* defined(__MMI_MESSAGES_EMS__) */ 
#if defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__)
extern void mmi_ems_send_vobject(void);
extern EMSTATUS mmi_ems_wrap_vobject(void);
#endif /* defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) */ 

/*  */
extern void ErrorHandlingWhileInsertingObject(EMSTATUS emsObjectStatus);
#endif /* _PIXCOM_EMS_MISCELL_H */ 

