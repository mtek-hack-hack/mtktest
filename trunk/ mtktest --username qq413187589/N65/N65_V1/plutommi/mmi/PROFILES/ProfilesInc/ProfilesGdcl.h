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
 * ProfilesGdcl.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Profiles application global variables
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
/*
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ProfilesGdcl.h

   PURPOSE     : Profiles application global variables

   REMARKS     : nil

   AUTHOR      : Ashima Bajaj

   DATE     : 

**************************************************************/
#ifndef _PIXCOM_PROFILESGDCL_H
#define _PIXCOM_PROFILESGDCL_H

S32 gcurrHiliteIndexOne = 0;    /* Current hilite index value */

/* S32 gcurrHiliteIndextwo = 0; */
U16 g_profiles_melody_list_index = 0;
S32 gcommonvolumehandler = 0;
U8 gprofilenvram = 0;

/* S8 gprofileNameArr[MAX_ELEMENTS-2][20 * ENCODING_LENGTH]; //array for profilenames */
//U8 gSec = 0;
U8 gprofileId = 0, gactivatedprofile = 0;
//U8 gcurrprofileID = 0;
U8 glastactivatedprofile = 0;
//S8 tempstring[52];
//S32 gringvol_level = 0;
//S32 gkeypadvol_level = 0;
//S32 gearphonevol_level = 0;
U8 fieldStates[3];
U8 fieldStatesExtraTone[4];

/* U8 gextratonestring[40][40]; */
S32 gcommonvolumelevel = 0;
//U8 gpopupToneId;
U16 gcurrentaudioId = 0;
U16 glastaudioId = 0;
U8 glastColorID = 0;
U8 gcurrentColorId = 0;
U16 gstartRingId;
U16 gtotalRingId;
U16 gstartMidiId;
U16 gtotalMidiId;
U16 gstartGeneralToneId;
U16 gtotalGeneralToneId;
U16 gstartMiscToneId;
U16 gtotalMiscToneId;

U16 gcallbackToneId; /*the playing tone id of callback type ring tone playing, so that the correct tone id can be stopped*/

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
U32 gstartExtMelodyId;
U32 gtotalExtMelodyId;
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 

PROFILE gprofiles[MAX_ELEMENTS];
PROFILE gcurrentprofile;
pBOOL gloudSpeaker = 0;
U8 gprofileheadset = 0;
//U8 gloudsplastprofile = 0;
pBOOL gPlayReqToneFlag = TRUE;

#endif /* _PIXCOM_PROFILESGDCL_H */ 

