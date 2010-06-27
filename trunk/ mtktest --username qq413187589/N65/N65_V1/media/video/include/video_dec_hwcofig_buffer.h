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
 *    video_dec_hwcofig_buffer.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines the content of HW register buffer that store HW register content
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef VIDEO_DEC_HWCOFIG_BUFFER_H
#define VIDEO_DEC_HWCOFIG_BUFFER_H

#define  Buffer_WRITE(ptr,data)       (*(ptr) = (data))
#define  Buffer_READ(ptr)             (*(ptr))         
/**
 * g_mpeg4_register_Buffer : a temporal buffer for MPEG-4/H.263 Video control register 
 * length = 0x80 bytes
 * 0x00 - 0x1F for Base Address
 * 0x20 - 0x5F for Data struct.
 * 0x60 - 0x7F for VLC DMA
 *
 */   
/* MP4 base address*/
#define BUFFER_MP4_Baseaddr                     ((volatile kal_uint32)g_mpeg4_dec_info_ptr->hardware_register)
#define BUFFER_MP4_CODEC_BASE		               (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000000)  /*R/W*/
#define BUFFER_MP4_VOP_ADDR	                  (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000004)  /*18~31 RO 0~17 R/W */ 
#define BUFFER_MP4_REF_ADDR			            (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000008)  /*18~31 RO 0~17 R/W */ 
#define BUFFER_MP4_REC_ADDR			            (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000000C)  /*18~31 RO 0~17 R/W */ 
#define BUFFER_MP4_STORE_ADDR			            (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000010)  /*18~31 RO 0~17 R/W */ 
#define BUFFER_MP4_DACP_ADDR			            (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000014)  /*18~31 RO 0~17 R/W */ 
#define BUFFER_MP4_MVP_ADDR			            (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000018)  /*18~31 RO 0~17 R/W */ 
#define BUFFER_MP4_DEBLOCK_ADDR			         (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000001C)  /*18~31 RO 0~17 R/W */ 

/* VOP structure */
#define BUFFER_MP4_VOP_STRUC0                   (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000020)   /*R/W*/
#define BUFFER_MP4_VOP_STRUC1                   (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000024)   /*R/W*/
#define BUFFER_MP4_VOP_STRUC2                   (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000028)   /*R/W*/
#define BUFFER_MP4_VOP_STRUC3                   (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000002C)   /*R/W*/
#define BUFFER_MP4_MB_STRUC0                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000030)   /*R/W*/
#define BUFFER_MP4_MB_STRUC1                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000034)   /*R/W*/
#define BUFFER_MP4_MB_STRUC2                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000038)   /*R/W*/
#define BUFFER_MP4_MB_STRUC3                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000003C)   /*R/W*/
#define BUFFER_MP4_MB_STRUC4                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000040)   /*R/W*/
#define BUFFER_MP4_MB_STRUC5                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000044)   /*R/W*/
#define BUFFER_MP4_MB_STRUC6                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000048)   /*R/W*/
#define BUFFER_MP4_MB_STRUC7                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000004C)   /*R/W*/
/* VLC DMA */  
#define BUFFER_MP4_VLC_COMD                     (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000060)    /*WO*/
#define BUFFER_MP4_VLC_STS                      (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000064)    /*RO*/
#define BUFFER_MP4_VLC_ADDR                     (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000068)    /*WO*/
#define BUFFER_MP4_VLC_BIT                      (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000006C)    /*WO*/
#define BUFFER_MP4_VLC_LIMIT                    (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000070)    /*R/W*/
#define BUFFER_MP4_VLC_WORD                     (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000074)    /*RO*/
#define BUFFER_MP4_VLC_BITCNT                   (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000078)    /*RO*/
#define BUFFER_MP4_FRAME_DURATION               (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x0000007c)    /*RO*/

#ifdef DRV_MP4_V2_ENHANCE
#define BUFFER_MP4_QS_ADDR                      (volatile kal_uint32 *)(BUFFER_MP4_Baseaddr+0x00000080)
#endif    


#endif   /*VIDEO_DEC_HWCOFIG_BUFFER_H*/
