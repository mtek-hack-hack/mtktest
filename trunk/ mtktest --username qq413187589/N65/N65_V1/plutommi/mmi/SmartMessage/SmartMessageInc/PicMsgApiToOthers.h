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
 * PicMsgApiToOthers.h
 *
 * Project:
 * --------
 * PDG1
 *
 * Description:
 * ------------
 * This file defines global function prototypes of Picture Message application.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 */
#ifndef _MMI_PICMSG_API_H
#define _MMI_PICMSG_API_H

#define RING_TONE_MELODY_SIGNATURE  "4D454C4F44593A"

extern S16 mmi_smrt_message_type(U8 *SmsData);

#if (0)
/* under construction !*/
/* under construction !*/
#endif /* (0) */ 

/* Free the momory return by this API */
extern U8 *mmi_pmsg_convert_ota_to_bmp(U8 *otaData);

/* Free the momory return by this API */
extern U8 *mmi_pmsg_convert_bmp_to_ota(U8 *BmpBuffer);

extern BOOL mmi_pmsg_is_smart_picture(U8 *BmpData);

extern U16 mmi_pmsg_get_size_bmp_data(U8 *BmpData);
extern U16 mmi_pmsg_get_size_ota_data(U8 *OtaBuffer);

extern void mmi_pmsg_add_nokia_header(U8 *PictureMessage, U8 TotalSegment, U8 CurrentSegment);
extern U16 mmi_pmsg_add_picture_text(U8 *OtaData, U8 *TextBuffer);
extern S16 mmi_pmsg_add_bmp_header_info(U8 *BmpData);

/* Below APIs would be used by any application as per their need */
/* Detail information can be found at funtion definition header */
extern void mmi_pmsg_shift_n_bytes(S8 *Data, S16 offset, S16 nBytes, S16 length);
extern U8 mmi_pmsg_get_n_bits(U8 *Data, U16 Offset, U16 Bits);
extern S16 mmi_pmsg_string_search(S8 *Pattern, S8 *Text);

extern U8 mmi_pmsg_convert_ascii_hex_to_dec(S8 character);
extern U8 mmi_pmsg_convert_binary_dec_to_hex(const U8 DecimalVal, U8 part);
extern void mmi_pmsg_convert_ascii_hex_string_2_dec_string(U8 *DecStr, U8 *AsciiStr);
extern void mmi_pmsg_convert_dec_string_2_ascii_hex_string(U8 *AsciiStr, U8 *DecStr);

#endif /* _MMI_PICMSG_API_H */ 

