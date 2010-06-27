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
* Audio3DEffect.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is the header file of audio 3D sound effect setup.
*
* Author:
* -------
* Wilson Lien (mtk00676)
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _AUDIO_3D_EFFECT_H
#define _AUDIO_3D_EFFECT_H

/* if some header should be include before this one */
//#ifndef _PREINC_H
//#error "preinc.h should be included before header.h"
//#endif

/* 
 * Define
 */

#define MAX_AUDIO_REVERB_EFFECT_NUM  6

/* 
 * Typedef 
 */
typedef enum
{
    AUD_SURROUND_OFF,
    AUD_SURROUND_MODE1,
    AUD_SURROUND_MODE2,
    AUD_SURROUND_TOTAL
}audio_surround_mode_enum;

typedef struct
{
    U16 reverb_index;
    U16 surround_index;    
} audio_3d_effect_struct;

/* 
 * Extern Global Variable
 */
extern audio_3d_effect_struct g_mmi_aud_3d_cntx;

/* 
 * Extern Global Function
 */
extern void mmi_aud_reverb_effect_init(void);
extern void mmi_aud_reverb_effect_highlight_hdlr(void);
extern void mmi_aud_reverb_effect_hint_hdlr(U16 index);
extern void mmi_aud_reverb_effect_list_highlight_hdlr(S32 index);
extern void mmi_aud_reverb_effect_list_LSK_hdlr(void);
extern void mmi_entry_aud_reverb_effect_list(void);
extern BOOL mmi_aud_reverb_set_effect(U16 index);
extern void mmi_aud_reverb_init_effect(U16 index);
extern void mmi_aud_reverb_read_nvram(void);
extern void mmi_aud_reverb_write_nvram(void);
extern MMI_BOOL mmi_aud_reverb_get_status(void);


extern void mmi_aud_surround_effect_init(void);
extern void mmi_aud_surround_effect_highlight_hdlr(void);
extern void mmi_aud_surround_effect_hint_hdlr(U16 index);
extern void mmi_aud_surround_effect_set_status(U16 mode);
extern void mmi_entry_aud_surround_mode_list(void);

#endif /* _AUDIO_3D_EFFECT_H */ 

