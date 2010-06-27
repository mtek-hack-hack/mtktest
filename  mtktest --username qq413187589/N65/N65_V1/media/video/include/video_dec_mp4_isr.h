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
 *   video_dec_mp4_isr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video decode isr definitions for mp4
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
 
#ifndef VIDEO_DEC_MP4_ISR_H
#define VIDEO_DEC_MP4_ISR_H

/* ISR file self checking parameters */
typedef struct
{
    kal_uint8     gpt_exception_protect_handle;
    kal_bool      b_gpt_active;
    kal_bool      b_check_reentry;
    kal_bool      b_check_exception;
    kal_bool      b_check_av_error;
    kal_bool      check_vlc_addr;
    kal_uint32   speed_recover_count;
    kal_uint32   vlc_addr;
}MPEG4_DEC_ISR_PARAM;

extern MPEG4_DEC_ISR_PARAM  g_mpeg4_dec_isr_param;

 /* Init ISR self parameter
  * @param None
  * @return None                                                        
  */
extern void mpeg4_dec_init_isr_param(void);


 /* Set VLC check parameters. 
 *  Set this before decode, and ISR check this parameter to see whether the VLC interrupt is legal or not.
 * @param b_check. Check VLC or not.   
 * @param addr. Decode atsrt addr. 
 * @return None                                                        
 */
extern void mpeg4_dec_set_isr_vlc_param(kal_bool b_check, kal_uint32 addr);


/* Decode HISR function. Parse the next frame.
 * @param None   
 * @return None                                                        
 */
extern void mpeg4_dec_HISR(void);

/* Decode LISR  function. Act in AV sync LISR context. 
 *  It should check whether next AV intr comes before error recover MP4 intr.
 * @param None   
 * @return None                                                        
 */
extern void mpeg4_dec_LISR(void);

#ifdef MP4_MOVE_LISR_TO_HISR 
/* Decode LISR  function. Act in AV sync HISR context. 
 *  It should check whether next AV intr comes before error recover MP4 intr.
 * @param None   
 * @return None                                                        
 */
extern void mpeg4_dec_first_HISR(void);
#endif

/* Seek HISR function. Check whether seek done or not in this function.
 * @param None   
 * @return None                                                        
 */
extern void mpeg4_dec_seek_HISR(void);


/* Seek LISR process function. Check exception(ex. re-entry). Check decode status.
 * @param None.   
 * @return None                                                        
 */
extern void mpeg4_dec_seek_lisr_process(kal_uint32 status);


/* Seek LISR function. 
 * @param None.   
 * @return None                                                        
 */
extern void mpeg4_dec_seek_LISR(void);

#ifdef MP4_MOVE_LISR_TO_HISR 
/* Seek HISR function. 
 * @param None.   
 * @return None                                                        
 */
void mpeg4_dec_seek_first_HISR(void);
#endif

#endif /*VIDEO_DEC_ISR_H*/
