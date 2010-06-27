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
 *  DownloadProtos.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/

/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: DownloadProtos.h

  	PURPOSE		: Resource IDs for the FunAndGames Application

	REMARKS		: nil

	AUTHOR		: Gurinder

	DATE		: 

**************************************************************/

#ifndef DOWNLOADPROTOS_H
#define DOWNLOADPROTOS_H

#include "AudioInc.h"
#include "DownloadDefs.h"
/* 
** Define
*/

/* 
** Typedef 
*/

/* 
** Extern Global Variable
*/

/* 
** Extern Global Function
*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
U8 GetThemeV2TonesInfo(DYNAUDIOINFO  **downloadThemeTones); //ritesh
#endif
#if defined(__MMI_IMELODY_SUPPORT__)
U8 GetFactoryIMelodyInfo(DYNAUDIOINFO ** factoryAudioInfo);
U8 GetDownloadIMelodyInfo(DYNAUDIOINFO ** downloadAudioInfo);
#endif

#if defined(__MMI_IMELODY_SUPPORT__)
S8 AddDownloadedIMelody(S8 *fileName);
#endif

#if defined(__MMI_IMELODY_SUPPORT__)
pBOOL DeleteDownloadImelodyIndexByFileName(U8 *imelodyName);
#endif

#if defined(__MMI_IMELODY_SUPPORT__)
U8 GetFreeDownloadImelodySlot(void);
#endif


#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
extern U8 GetComposedIMelodyInfo(DYNAUDIOINFO ** downloadAudioInfo);
extern S8 *GetComposedIMelodyNameInFileSystem(U16 AudioId);
#endif

extern U8 GetFileExtension(S8*	pFileName);
extern S8* GetImageFileSystem(U16 ImageId);
#endif


extern U8 GetFactoryTonesInfo(DYNAUDIOINFO ** factoryAudioInfo);
extern U8 GetFullScreenFactoryImagesInfo(DYNIMAGEINFO ** factoryFileInfo);
extern U8 GetAssociatedFactoryImagesInfo(DYNIMAGEINFO ** factoryFileInfo);
extern U8 getFactoryImageRelativeIndex(U16 ImageId);
