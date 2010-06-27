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
 * JMMSGdcl.h
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
#ifndef _MMI_JMMS_GDCL_H
#define _MMI_JMMS_GDCL_H

#include "JMMSStructs.h"
/* if some header should be include before this one */

/***************************************************************************** 
* Define 
*****************************************************************************/
// #define MAX_CONTENT_TYPE     37

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/* keep this array synchronized with color resource seq in jmms_res_enum.h */
const U32 g_jmms_color_RGB_list[MAX_JMMS_COLOR_NUM - 1] = 
{
    0x00000064, /* Black: color 1 */
    0xFFFFFF64, /* White: color 2 */
    0xFF000064, /* Red: color 3 */
    0x0000F764, /* Blue: color 4 Value changed to 0000F7 as 0000FF is transparent color */
    0x00FF0064, /* Green: color 5 */
};

JC_INT8 *g_content_type_list[][2] = 
{
#if defined(__MMI_VCALENDAR__)
    {"text/x-vCalendar", "vcs"},
#endif 
#if defined(__MMI_VCARD__)
    {"text/x-vCard", "vcf"},
#endif 
    {"text/plain", "txt"},

    {"image/gif", "gif"},
#if defined(JPG_DECODE)
    {"image/jpeg", "jpg"},
#endif 
    {"image/bmp", "bmp"},
    {"image/vnd.wap.wbmp", "wbmp"},

    {"audio/amr", "amr"},
    {"audio/midi", "mid"},

#if defined(MP4_CODEC)
    {"video/3gpp", "3gp"},
    {"video/3gpp2", "3g2"},
    {"video/mp4", "mp4"},
#endif /* defined(MP4_CODEC) */ 
    {"\0", "\0"}

};

mmi_jmms_context_struct *g_jmms_context = NULL;

#endif /* _MMI_JMMS_GDCL_H */ 

