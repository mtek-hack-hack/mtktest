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
 *    melody.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for melody note table.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MELODY_H
#define MELODY_H

typedef enum {    
 C0=0, C0sharp, D0, D0sharp, E0, F0, F0sharp, G0, G0sharp, A0, A0sharp, B0, 
 C1, C1sharp, D1, D1sharp, E1, F1, F1sharp, G1, G1sharp, A1, A1sharp, B1,
 C2, C2sharp, D2, D2sharp, E2, F2, F2sharp, G2, G2sharp, A2, A2sharp, B2,
 C3, C3sharp, D3, D3sharp, E3, F3, F3sharp, G3, G3sharp, A3, A3sharp, B3,
 C4, C4sharp, D4, D4sharp, E4, F4, F4sharp, G4, G4sharp, A4, A4sharp, B4,
 C5, C5sharp, D5, D5sharp, E5, F5, F5sharp, G5, G5sharp, A5, A5sharp, B5,
 C6, C6sharp, D6, D6sharp, E6, F6, F6sharp, G6, G6sharp, A6, A6sharp, B6,
 C7, C7sharp, D7, D7sharp, E7, F7, F7sharp, G7, G7sharp, A7, A7sharp, B7
} MusicalNote;		/* KEY define here!! */

//=============Adaption====================================
#define Notespace    255

typedef struct
{
	kal_uint16 duration;  /* in ms */
	kal_uint8 pitch;
	kal_uint8 volume;
} MelodyNoteStruct;

typedef struct
{
   kal_uint8 timbre;
	kal_uint16 notesNum;
	MelodyNoteStruct *notes;
} MelodyTrackStruct;

typedef struct
{
 	MelodyTrackStruct  *tracks[4];
} MelodyStruct;

typedef struct
{
   kal_uint16   frequency;         /* in hz */
   kal_uint16   on_duration;       /* in ms */
   kal_uint16   off_duration;       /* in ms */
}FreqStruct;

typedef struct
{
   FreqStruct   *f[4];
}ToneStruct;
#endif   /* MELODY_H */

