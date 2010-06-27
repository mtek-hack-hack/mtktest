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
 * video_glb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    video global header files. Other modules should include this header file
 *    to use video driver.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
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
 *    Rev 1.12   Jul 11 2005 17:49:30   mtk00288
 * revise the core reset prototype.
 * Resolution for 11921: [LPWR][Add feature]Add LPWR module
 *
 *    Rev 1.11   Jun 27 2005 19:53:34   mtk00288
 * add the definitions about 6228 option
 * Resolution for 11670: [Video][Bugfix]Bugfix MT6228 video  driver in maui_sw load
 *
 *    Rev 1.10   Jun 06 2005 10:33:04   mtk00288
 * add MT6228/MT6226/MT6227/MT6229 option
 * Resolution for 11205: [Video/Drv][Add feature]Add MT6228 option
 *
 *    Rev 1.9   May 17 2005 00:58:38   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.8   May 11 2005 17:22:36   mtk00288
 * add MP4VIDEO_ENC_GLB_STRUCT structure.
 * Resolution for 11011: [Video][Bugfix]Add global variable when the dynamic memory is not initiailzed.
 *
 *    Rev 1.7   Jan 18 2005 00:49:10   BM
 * append new line in W05.04
 *
 *    Rev 1.6   Oct 29 2004 12:06:02   mtk00288
 * Adjust/Add the API prototype for future development.
 * Resolution for 8459: [Video][Modify] Adjust the software architecture to meet future development
 *
 *    Rev 1.5   Oct 27 2004 17:59:32   mtk00288
 * Move some global definitions to video_glb.h
 * Resolution for 8435: [Video][Modify]Modify to meet new camera interface
 *
 *    Rev 1.4   Jul 08 2004 17:49:10   mtk00288
 * Adjust the comments for structure/function.
 * Resolution for 6544: [Video][Add feature]Add media file recovery mechanism
 *
 *    Rev 1.3   Jul 02 2004 18:36:04   mtk00288
 * Add comments in header files
 * Resolution for 6420: [Video][Bugfix]Change the show when play speed exceed the mcu loading.
 *
 *    Rev 1.2   Jun 27 2004 14:39:14   mtk00288
 * Add the error report mechanism.
 * Resolution for 6264: [Video][Add feature]Video error report mechanism
 *
 *    Rev 1.1   May 24 2004 15:24:48   mtk00288
 * add error message, and avoid header file include header file.
 * Resolution for 5428: [Drv][Add feature]Add video driver
 *
 *    Rev 1.0   May 14 2004 16:55:12   admin
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/



#ifndef __VIDEO_GLB_H__
#define __VIDEO_GLB_H__



#ifndef __VIDEO_ENC_GLB_H__
   #error "Please include video_enc_glb.h before video_glb.h"
#endif

#ifndef __VIDEO_DEC_GLB_H__
   #error "Please include video_dec_glb.h before video_glb.h"
#endif

#ifndef __MED_STATUS_H__
   #error "Please include med_status.h before video_glb.h"
#endif

#if defined(__VIDEO_EDITOR__)
   #include    "video_editor.h"
#endif
#include "video_editor_glb.h"
#include "video_dsp.h"
#include "video_codec.h"

#define VIDEO_DEBUG_MODE

/* video encode/ decode parameter */

extern VIDEO_DEC_STRUCT *g_video_dec_info_ptr;

extern VIDEO_ENC_STRUCT *g_video_enc_info_ptr;

extern VIDEO_DEC_STATUS_STRUCT g_video_dec_status;

extern VIDEO_ENC_STATUS_STRUCT g_video_enc_status;

extern VIDEO_EDITOR_STRUCT VIDEO_EDITOR_DATA;



#endif /* __VIDEO_GLB_H__ */
