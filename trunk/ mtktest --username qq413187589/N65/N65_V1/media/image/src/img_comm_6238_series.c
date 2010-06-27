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
 *   img_comm_6238_series.c
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   MT6238 image data path
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
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

/**
 * \mainpage
 *
 * \dot
 * digraph jpeg_encode_idp {
 * rankdir=LR;
 * PRZ_R2 [label="PRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_R2 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R0_R [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IPP2_R [label="IPP2" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW2_R [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT1_R [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_L [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R0_L [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IPP2_L [label="IPP2" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW2_L [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT1_L [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="blue" fontcolor="white"];
 * VDODEC_RDMA [label="Video\nDecoder\nRDMA" URL="\ref imgdma_video_decode" style=filled fillcolor="blue" fontcolor="white"];
 * IRT0 [label="Rotator_0" URL="\ref imgdma_irt0" style=filled fillcolor="blue" fontcolor="white"];
 * MP4_DEBLK [label="Deblocking\nfilter" URL="\ref imgdma_mp4_deblk" style=filled fillcolor="blue" fontcolor="white"];
 * IBR1 [label="IBR1" URL="\ref imgdma_ibr1" style=filled fillcolor="blue" fontcolor="white"];
 * R2Y0_R [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * PRZ_R1 [label="PRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_R1 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * DRZ [label="DRZ" URL="\ref drz" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R1_R [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW1_R [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="blue" fontcolor="white"];
 * IBR2 [label="IBR2" URL="\ref imgdma_ibr2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT2 [label="Rotator_2" URL="\ref imgdma_irt2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT3 [label="Rotator_3" URL="\ref imgdma_irt3" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_DECODER [label="JPEG\nDecoder"];
 * PRZ_BLK [label="Block-based\nConversion" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * CRZ_R2 [label="CRZ" URL="\ref crz" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_DMA [URL="\ref imgdma_jpeg" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_ENCODER [label="JPEG\nEncoder"];
 * Y2R1_L [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW1_L [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="blue" fontcolor="white"];
 * LCD;
 * ISP;
 * CRZ_R1 [label="CRZ" URL="\ref crz" style=filled fillcolor="blue" fontcolor="white"];
 * OVL [URL="\ref imgdma_ovl" style=filled fillcolor="blue" fontcolor="white"];
 * VDOENC_WDMA [label="Video\nEncoder\nWDMA" URL="\ref imgdma_video_encode" style=filled fillcolor="blue" fontcolor="white"];
 * TV_OUT_R1 [label="TV Out"];
 * TV_OUT_R2 [label="TV Out"];
 * TV_OUT_R3 [label="TV Out"];
 * PRZ_or_CRZ [label="PRZ\nor\nCRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * R2Y0_L [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * MPEG4_CODEC [label="MPEG-4 Codec\nor\nH.264e Decoder"];
 * ICON_FB [label="Icon\nBuffer"];
 * {
 *   rank=same;
 *   Y2R1_L;
 *   IBW1_L;
 *   LCD;
 *   ICON_FB;
 * }
 * {
 *   rank=same;
 *   PRZ_or_CRZ;
 *   R2Y0_L;
 * }
 * {
 *   rank=same;
 *   MP4_DEBLK;
 *   IPP1_L;
 * }
 * {
 *   rank=same;
 *   IRT0;
 *   IBW2_L;
 *   IRT3;
 * }
 * {
 *   rank=same;
 *   MPEG4_CODEC;
 *   VDODEC_RDMA;
 *   IRT1_L;
 *   IBR2;
 * }
 * subgraph cluster_FB
 * {
 *   rank=same;
 *   label="External Memory";
 *   BMP_FB [label="BMP or Pixel Buffer"];
 *   VOP_FB [label="VOP Frame Buffer"];
 *   REC_FB [label="Rec Frame Buffer"];
 *   LCD_FB_1 [label="LCD Frame Buffer"];
 *   LCD_FB_2 [label="LCD Frame Buffer"];
 *   JPEG_FB_1 [label="JPEG File Buffer"];
 *   JPEG_FB_2 [label="JPEG File Buffer"];
 *   TV_FB_1 [label="TV Out Buffer"];
 *   TV_FB_2 [label="TV Out Buffer"];
 *   THUMB_FB [label="Thumbnail Buffer"];
 * }
 * {
 *   rank=same;
 *   IBR1;
 *   VDOENC_WDMA;
 *   TV_OUT_R1;
 *   IRT1_R;
 *   TV_OUT_R2;
 *   JPEG_DECODER;
 *   JPEG_ENCODER;
 *   TV_OUT_R3;
 *   IBW1_R;
 * }
 * {
 *   rank=same;
 *   PRZ_R1;
 *   IPP1_R2;
 *   CRZ_R2;
 *   JPEG_DMA;
 * }
 * {
 *   rank=same;
 *   IPP1_R1;
 *   PRZ_R2;
 *   DRZ;
 * }
 * {
 *   rank=same;
 *   ISP;
 *   CRZ_R1;
 *   OVL;
 * }
 * BMP_FB -> IBR1 -> R2Y0_R -> PRZ_R1 -> IPP1_R1;
 * MPEG4_CODEC -> VOP_FB [dir=back];
 * REC_FB -> TV_OUT_R1;
 * VDODEC_RDMA -> REC_FB [dir=back];
 * LCD_FB_2 -> TV_OUT_R2;
 * IBR2 -> LCD_FB_2 [dir=back];
 * TV_FB_2 -> TV_OUT_R3;
 * IRT2 -> IBR2 [dir=back];
 * PRZ_or_CRZ -> IRT0 [dir=back];
 * MP4_DEBLK -> IRT0 [dir=back];
 * MP4_DEBLK -> IPP1_L;
 * LCD_FB_1 -> IRT1_R -> IBW2_R -> IPP2_R -> Y2R0_R -> IPP1_R2 -> PRZ_R2 [dir=back];
 * IRT1_L -> LCD_FB_1;
 * LCD -> IRT2 [dir=back];
 * IRT3 -> TV_FB_1;
 * IBW1_L -> LCD;
 * IBW2_L -> IRT1_L;
 * LCD -> IBW2_L [dir=back];
 * IPP1_L -> Y2R0_L;
 * IPP1_R1 -> OVL;
 * IPP2_L -> IBW2_L;
 * Y2R0_L -> IPP2_L;
 * THUMB_FB -> IBW1_R -> Y2R1_R -> DRZ [dir=back];
 * Y2R1_L -> IBW1_L;
 * PRZ_or_CRZ -> R2Y0_L [dir=back];
 * PRZ_R1 -> IPP1_R2;
 * Y2R1_L -> PRZ_or_CRZ [dir=back];
 * PRZ_or_CRZ -> IPP1_L;
 * CRZ_R1 -> OVL;
 * CRZ_R2 -> OVL;
 * IPP1_R2 -> CRZ_R2 [dir=back];
 * VOP_FB -> VDOENC_WDMA -> OVL [dir=back];
 * JPEG_DMA -> OVL [dir=back];
 * DRZ -> OVL [dir=back];
 * PRZ_R2 -> OVL [dir=back];
 * IRT0 -> VDODEC_RDMA [dir=back];
 * PRZ_or_CRZ -> MP4_DEBLK [dir=back];
 * JPEG_FB_1 -> JPEG_DECODER -> PRZ_BLK -> CRZ_R2;
 * JPEG_FB_2 -> JPEG_ENCODER -> JPEG_DMA [dir=back];
 * ISP -> CRZ_R1;
 * LCD -> ICON_FB [dir=back];
 * LCD -> IRT3;
 * MPEG4_CODEC -> REC_FB;
 * R2Y0_L -> IRT2 [dir=back];
 * }
 * \enddot
 * Note that the blue components in the above graph are
 * clickable (in the HTML output).
 */

#include "reg_base.h"
#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "jpeg.h"
#include "imgproc.h"
#include "resizer.h"
#include "image_effect.h"
#include "img_comm.h"
#include "imgdma.h"
#include "mp4_deblk_6238_series.h"

#ifdef MTK_SLEEP_ENABLE
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
#endif

/** \brief This function will configure jpeg encode data
 * path.
 *
 * \dot
 * digraph jpeg_encode_idp {
 * rankdir=LR;
 * PRZ_R2 [label="PRZ" URL="\ref prz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IPP1_R2 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * Y2R0_R [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IPP2_R [label="IPP2" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBW2_R [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT1_R [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IPP1_L [label="IPP1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * Y2R0_L [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IPP2_L [label="IPP2" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBW2_L [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT1_L [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * VDODEC_RDMA [label="Video\nDecoder\nRDMA" URL="\ref imgdma_video_decode" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT0 [label="Rotator_0" URL="\ref imgdma_irt0" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * MP4_DEBLK [label="Deblocking\nfilter" URL="\ref imgdma_mp4_deblk" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBR1 [label="IBR1" URL="\ref imgdma_ibr1" style=filled fillcolor="blue" fontcolor="white"];
 * R2Y0_R [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * PRZ_R1 [label="PRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_R1 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * DRZ [label="DRZ" URL="\ref drz" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R1_R [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW1_R [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="blue" fontcolor="white"];
 * IBR2 [label="IBR2" URL="\ref imgdma_ibr2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT2 [label="Rotator_2" URL="\ref imgdma_irt2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT3 [label="Rotator_3" URL="\ref imgdma_irt3" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * JPEG_DECODER [label="JPEG\nDecoder" color="grey" fontcolor="grey"];
 * PRZ_BLK [label="Block-based\nConversion" URL="\ref prz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * CRZ_R2 [label="CRZ" URL="\ref crz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * JPEG_DMA [URL="\ref imgdma_jpeg" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_ENCODER [label="JPEG\nEncoder"];
 * Y2R1_L [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBW1_L [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * LCD [color="grey" fontcolor="grey"];
 * ISP [color="grey" fontcolor="grey"];
 * CRZ_R1 [label="CRZ" URL="\ref crz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * OVL [URL="\ref imgdma_ovl" style=filled fillcolor="blue" fontcolor="white"];
 * VDOENC_WDMA [label="Video\nEncoder\nWDMA" URL="\ref imgdma_video_encode" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * TV_OUT_R1 [label="TV Out" color="grey" fontcolor="grey"];
 * TV_OUT_R2 [label="TV Out" color="grey" fontcolor="grey"];
 * TV_OUT_R3 [label="TV Out" color="grey" fontcolor="grey"];
 * PRZ_or_CRZ [label="PRZ\nor\nCRZ" URL="\ref prz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * R2Y0_L [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * MPEG4_CODEC [label="MPEG-4 Codec\nor\nH.264e Decoder" color="grey" fontcolor="grey"];
 * ICON_FB [label="Icon\nBuffer" color="grey" fontcolor="grey"];
 * {
 *   rank=same;
 *   Y2R1_L;
 *   IBW1_L;
 *   LCD;
 *   ICON_FB;
 * }
 * {
 *   rank=same;
 *   PRZ_or_CRZ;
 *   R2Y0_L;
 * }
 * {
 *   rank=same;
 *   MP4_DEBLK;
 *   IPP1_L;
 * }
 * {
 *   rank=same;
 *   IRT0;
 *   IBW2_L;
 *   IRT3;
 * }
 * {
 *   rank=same;
 *   MPEG4_CODEC;
 *   VDODEC_RDMA;
 *   IRT1_L;
 *   IBR2;
 * }
 * subgraph cluster_FB
 * {
 *   rank=same;
 *   label="External Memory";
 *   BMP_FB [label="BMP or Pixel Buffer"];
 *   VOP_FB [label="VOP Frame Buffer" color="grey" fontcolor="grey"];
 *   REC_FB [label="Rec Frame Buffer" color="grey" fontcolor="grey"];
 *   LCD_FB_1 [label="LCD Frame Buffer" color="grey" fontcolor="grey"];
 *   LCD_FB_2 [label="LCD Frame Buffer" color="grey" fontcolor="grey"];
 *   JPEG_FB_1 [label="JPEG File Buffer" color="grey" fontcolor="grey"];
 *   JPEG_FB_2 [label="JPEG File Buffer"];
 *   TV_FB_1 [label="TV Out Buffer" color="grey" fontcolor="grey"];
 *   TV_FB_2 [label="TV Out Buffer" color="grey" fontcolor="grey"];
 *   THUMB_FB [label="Thumbnail Buffer"];
 * }
 * {
 *   rank=same;
 *   IBR1;
 *   VDOENC_WDMA;
 *   TV_OUT_R1;
 *   IRT1_R;
 *   TV_OUT_R2;
 *   JPEG_DECODER;
 *   JPEG_ENCODER;
 *   TV_OUT_R3;
 *   IBW1_R;
 * }
 * {
 *   rank=same;
 *   PRZ_R1;
 *   IPP1_R2;
 *   CRZ_R2;
 *   JPEG_DMA;
 * }
 * {
 *   rank=same;
 *   IPP1_R1;
 *   PRZ_R2;
 *   DRZ;
 * }
 * {
 *   rank=same;
 *   ISP;
 *   CRZ_R1;
 *   OVL;
 * }
 * BMP_FB -> IBR1 -> R2Y0_R -> PRZ_R1 -> IPP1_R1;
 * MPEG4_CODEC -> VOP_FB [dir=back color="grey"];
 * REC_FB -> TV_OUT_R1 [color="grey"];
 * VDODEC_RDMA -> REC_FB [dir=back color="grey"];
 * LCD_FB_2 -> TV_OUT_R2 [color="grey"];
 * IBR2 -> LCD_FB_2 [dir=back color="grey"];
 * TV_FB_2 -> TV_OUT_R3 [color="grey"];
 * IRT2 -> IBR2 [dir=back color="grey"];
 * PRZ_or_CRZ -> IRT0 [dir=back color="grey"];
 * MP4_DEBLK -> IRT0 [dir=back color="grey"];
 * MP4_DEBLK -> IPP1_L [color="grey"];
 * LCD_FB_1 -> IRT1_R -> IBW2_R -> IPP2_R -> Y2R0_R -> IPP1_R2 -> PRZ_R2 [dir=back color="grey"];
 * IRT1_L -> LCD_FB_1 [color="grey"];
 * LCD -> IRT2 [dir=back color="grey"];
 * IRT3 -> TV_FB_1 [color="grey"];
 * IBW1_L -> LCD [color="grey"];
 * IBW2_L -> IRT1_L [color="grey"];
 * LCD -> IBW2_L [dir=back color="grey"];
 * IPP1_L -> Y2R0_L [color="grey"];
 * IPP1_R1 -> OVL;
 * IPP2_L -> IBW2_L [color="grey"];
 * Y2R0_L -> IPP2_L [color="grey"];
 * THUMB_FB -> IBW1_R -> Y2R1_R -> DRZ [dir=back];
 * Y2R1_L -> IBW1_L [color="grey"];
 * PRZ_or_CRZ -> R2Y0_L [dir=back color="grey"];
 * PRZ_R1 -> IPP1_R2 [color="grey"];
 * Y2R1_L -> PRZ_or_CRZ [dir=back color="grey"];
 * PRZ_or_CRZ -> IPP1_L [color="grey"];
 * CRZ_R1 -> OVL [color="grey"];
 * CRZ_R2 -> OVL [color="grey"];
 * IPP1_R2 -> CRZ_R2 [dir=back color="grey"];
 * VOP_FB -> VDOENC_WDMA -> OVL [dir=back color="grey"];
 * JPEG_DMA -> OVL [dir=back];
 * DRZ -> OVL [dir=back];
 * PRZ_R2 -> OVL [dir=back color="grey"];
 * IRT0 -> VDODEC_RDMA [dir=back color="grey"];
 * PRZ_or_CRZ -> MP4_DEBLK [dir=back color="grey"];
 * JPEG_FB_1 -> JPEG_DECODER -> PRZ_BLK -> CRZ_R2 [color="grey"];
 * JPEG_FB_2 -> JPEG_ENCODER -> JPEG_DMA [dir=back];
 * ISP -> CRZ_R1 [color="grey"];
 * LCD -> ICON_FB [dir=back color="grey"];
 * LCD -> IRT3 [color="grey"];
 * MPEG4_CODEC -> REC_FB [color="grey"];
 * R2Y0_L -> IRT2 [dir=back color="grey"];
 * }
 * \enddot
 *
 * \ingroup idp
 *
 * \param scenario_id
 * \param jpeg_para
 */
 
#if (defined(DRV_JPG_HW_ENC_SUPPORT))

kal_uint8
config_jpeg_encode_data_path_6238_series(
  MMDI_SCENERIO_ID scenario_id,
  jpeg_encode_process_struct *jpeg_para)
{
  /* check the owner of this data path currently. */
  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  
  /* check the scenerio ID of this data path. */
  if ((scenario_id != SCENARIO_JPEG_ENCODE_ID) &&
      (scenario_id != SCENARIO_MPEG_SNAPSHOT_ID))
  {
    ASSERT(0);
  }
  
  if (SCENARIO_JPEG_ENCODE_ID == scenario_id)
  {
    intmem_init((kal_uint32 *)jpeg_para->intmem_start_address,
                jpeg_para->intmem_size);
    extmem_init((kal_uint32 *)jpeg_para->extmem_start_address,
                jpeg_para->extmem_size);
  }
  
  {
    /* config IBR1 */   
    IMGDMA_IBR1_STRUCT ibr1_struct;
    
    memset(&ibr1_struct, 0, sizeof(IMGDMA_IBR1_STRUCT));
    
    ibr1_struct.base_addr = jpeg_para->image_buffer_address;
    ibr1_struct.pixel_number = jpeg_para->image_width * jpeg_para->image_height ;
    ibr1_struct.data_type = jpeg_para->type;
    ibr1_struct.data_order = jpeg_para->data_order;
    
    ibr1_struct.int_en = KAL_FALSE;
    
    IMGDMA_IBR1Config(&ibr1_struct);
  }
  
  {
    /* config R2Y0 */
    SET_IMGPROC_R2Y0_SRC(IMGPROC_R2Y0_IO_IBR1_TO_R2Y0 | 
                         IMGPROC_R2Y0_IO_R2Y0_TO_PRZ);
  }
  
  {
    RESZ_PRZ_STRUCT prz_struct;
    
    memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
    
    prz_struct.image_src = RESZ_SOURCE_R2Y;
    
    prz_struct.output_to_CRZ = KAL_FALSE;
    prz_struct.output_to_IPP1 = KAL_TRUE;
    prz_struct.output_to_Y2R1 = KAL_FALSE;
    
    prz_struct.dedicate_memory = KAL_TRUE;
    prz_struct.continous = KAL_FALSE;
    prz_struct.int_en = KAL_FALSE;
    prz_struct.src_height = jpeg_para->image_height;
    prz_struct.src_width = jpeg_para->image_width;
    prz_struct.tar_height = jpeg_para->target_height;
    prz_struct.tar_width = jpeg_para->target_width;
    prz_struct.work_mem_line = 4;
    prz_struct.work_mem_addr = 0x40000000;
    prz_struct.coarse_en = KAL_FALSE;
    
    RESZ_PRZConfig(&prz_struct);
  }
  
  {
    /* config IPP1 */
    SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                        IMGPROC_IPP_IO_IPP1_TO_OVL);
  }
  
  {
    /* config OVL */
    IMGDMA_OVL_STRUCT ovl_struct;
    
    memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
    
    ovl_struct.int_en = KAL_FALSE;
    ovl_struct.restart = KAL_FALSE;
    ovl_struct.pixel_engine = PIXEL_ENGINE_IPP1;
    
    ovl_struct.ouput_jpeg = KAL_TRUE;
    ovl_struct.ouput_drz = KAL_TRUE;
    ovl_struct.output_vdoenc = KAL_FALSE;
    ovl_struct.ouput_y2r0 = KAL_FALSE;
    ovl_struct.ouput_prz = KAL_FALSE;
    
    ovl_struct.overlay_frame_mode = jpeg_para->overlay_frame_mode;
    
    if (KAL_TRUE == ovl_struct.overlay_frame_mode)
    {
      ovl_struct.overlay_frame_buffer_address = jpeg_para->overlay_frame_buffer_address;
      ovl_struct.overlay_frame_width = jpeg_para->overlay_frame_width;
      ovl_struct.overlay_frame_height = jpeg_para->overlay_frame_height;
      ovl_struct.overlay_frame_target_width = jpeg_para->target_width;
      ovl_struct.overlay_frame_target_height = jpeg_para->target_height;
      ovl_struct.overlay_color_depth = jpeg_para->overlay_color_depth;
      ovl_struct.overlay_frame_source_key = jpeg_para->overlay_frame_source_key;
    }
    
    IMGDMA_OVLConfig(&ovl_struct);
  }
  
  /* config JPEG DMA */
  {
    IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
    
    memset(&jpeg_dma_struct, 0, sizeof(IMGDMA_JPEG_DMA_STRUCT));
    
    jpeg_dma_struct.restart = KAL_FALSE;
    jpeg_dma_struct.int_enable = KAL_FALSE;
    
    if (SCENARIO_JPEG_ENCODE_ID == scenario_id)
    {
      jpeg_dma_struct.jpeg_file_buffer_address = 
        IMGDMA_JPEGDMAGetWorkingMem(
          KAL_FALSE,
                                    jpeg_para->jpeg_yuv_mode,
                                    jpeg_para->target_width);
    }
#if (defined(MP4_CODEC))
    else
    {
      /* get memory from MPEG4 interface because the
       * memory is occupied by MPEG4 decoder
       */
      jpeg_dma_struct.jpeg_file_buffer_address = video_dec_get_snapshot_imgdma_mem();
      
      if (0 == jpeg_dma_struct.jpeg_file_buffer_address)
      {
        jpeg_dma_struct.jpeg_file_buffer_address = 
          IMGDMA_JPEGDMAGetWorkingMem(
            KAL_FALSE,
                                      jpeg_para->jpeg_yuv_mode,
                                      jpeg_para->target_width);
        
        video_dec_set_snapshot_imgdma_mem(jpeg_dma_struct.jpeg_file_buffer_address);
      }
    }
#endif /* (defined(MP4_CODEC)) */
    
    jpeg_dma_struct.target_width = jpeg_para->target_width;
    jpeg_dma_struct.target_height = jpeg_para->target_height;
    
    /* YUV420, YUV422 or Gray mode */
    switch (jpeg_para->jpeg_yuv_mode)
    {
    case JPEG_FORMAT_GRAY:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_GRAY;
      break;
      
    case JPEG_FORMAT_YUV422:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV422;
      break;
      
    case JPEG_FORMAT_YUV420:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV420;
      break;
      
    case JPEG_FORMAT_YUV411:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV411;
      break;
      
    default:
      ASSERT(0);
      break;
    }
    
    IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);
  }
  
  if (KAL_TRUE == jpeg_para->thumbnail_mode)
  {
    /* config DRZ */
    {
      RESZ_DRZ_STRUCT drz_struct;
    
      memset(&drz_struct, 0, sizeof(RESZ_DRZ_STRUCT));
    
      drz_struct.image_src = RESZ_SOURCE_IBW3;
      drz_struct.auto_restart = KAL_FALSE;
      drz_struct.int_en = KAL_FALSE;
      drz_struct.src_height = jpeg_para->target_height;
      drz_struct.src_width = jpeg_para->target_width;
      drz_struct.tar_width = jpeg_para->thumbnail_width;
      drz_struct.tar_height = jpeg_para->thumbnail_height;
    
      RESZ_DRZConfig(&drz_struct);
    }
    
    /* config Y2R1 */
    {
      SET_IMGPROC_Y2R1_SRC(IMGPROC_Y2R1_IO_DRZ_TO_Y2R1 |
                           IMGPROC_Y2R1_IO_Y2R1_TO_IBW1);
    }
    
    /* config IBW1 */
    {
      IMGDMA_IBW1_STRUCT ibw1_struct;
      
      memset(&ibw1_struct, 0, sizeof(IMGDMA_IBW1_STRUCT));
      
      ibw1_struct.int_enable = KAL_FALSE;
      ibw1_struct.output_format = IMGDMA_IBW1_OUTPUT_TYPE_RGB888;
      ibw1_struct.base1_addr = (kal_uint32)(jpeg_para->jpeg_file_start_address + 20);
      ibw1_struct.base2_addr = (kal_uint32)(jpeg_para->jpeg_file_start_address + 20);
      ibw1_struct.width = jpeg_para->thumbnail_width;
      ibw1_struct.height = jpeg_para->thumbnail_height;
      ibw1_struct.lcd_trigger = KAL_FALSE;
      ibw1_struct.auto_restart = KAL_FALSE;
      ibw1_struct.dc_couple = KAL_FALSE; 
      ibw1_struct.pan = KAL_FALSE; 
      ibw1_struct.pitch_enable = KAL_FALSE;
      ibw1_struct.alpha = 0;
      
      IMGDMA_IBW1Config(&ibw1_struct);
    }
  }
  
#if 1
  /* config jpeg encoder */
  config_jpeg_encode_path(jpeg_para);
#else
/* under construction !*/
#endif
  
  {
    START_IBW1();
    
    ENABLE_Y2R1();
    ENABLE_IMGPROC_HW_Y2R1();
    
    START_DRZ();
    START_IMGDMA_JPEG();
    
    if (KAL_TRUE == jpeg_para->overlay_frame_mode)
    {
      START_OVL();
    }
    
    ENABLE_IMGPROC_HW_IPP(); 
    
    ENABLE_PRZ_H_LINE();
    ENABLE_PRZ_V_LINE();   
    
    ENABLE_R2Y0();
    ENABLE_IMGPROC_HW_R2Y0();
    
    START_IBR1();
  }
  
  return 0;
}

/** \brief close the jpeg encode data path
 * \ingroup idp
 */
void
close_jpeg_encode_data_path_6238_series(void)
{
  STOP_IBR1();
  
  DISABLE_IMGPROC_HW_R2Y0();
  DISABLE_R2Y0();
  
  RESET_PRZ;
  
  DISABLE_IMGPROC_HW_IPP();
  
  STOP_OVL();
  
  STOP_IMGDMA_JPEG();
  
  STOP_DRZ();
  
  DISABLE_IMGPROC_HW_Y2R1();
  DISABLE_Y2R1();
  
  STOP_IBW1();
  
#if 0
/* under construction !*/
#else
  ASSERT(0);
#endif
}

/** \brief This function will configure jpeg decode data
 * path.
 *
 * \dot
 * digraph jpeg_encode_idp {
 * rankdir=LR;
 * PRZ_R2 [label="PRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_R2 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R0_R [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IPP2_R [label="IPP2" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW2_R [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT1_R [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_L [label="IPP1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * Y2R0_L [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IPP2_L [label="IPP2" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBW2_L [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT1_L [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * VDODEC_RDMA [label="Video\nDecoder\nRDMA" URL="\ref imgdma_video_decode" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT0 [label="Rotator_0" URL="\ref imgdma_irt0" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * MP4_DEBLK [label="Deblocking\nfilter" URL="\ref imgdma_mp4_deblk" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBR1 [label="IBR1" URL="\ref imgdma_ibr1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * R2Y0_R [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * PRZ_R1 [label="PRZ" URL="\ref prz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IPP1_R1 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * DRZ [label="DRZ" URL="\ref drz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * Y2R1_R [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBW1_R [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBR2 [label="IBR2" URL="\ref imgdma_ibr2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT2 [label="Rotator_2" URL="\ref imgdma_irt2" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IRT3 [label="Rotator_3" URL="\ref imgdma_irt3" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * JPEG_DECODER [label="JPEG\nDecoder"];
 * PRZ_BLK [label="Block-based\nConversion" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * CRZ_R2 [label="CRZ" URL="\ref crz" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_DMA [URL="\ref imgdma_jpeg" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * JPEG_ENCODER [label="JPEG\nEncoder"];
 * Y2R1_L [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * IBW1_L [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * LCD [color="grey" fontcolor="grey"];
 * ISP [color="grey" fontcolor="grey"];
 * CRZ_R1 [label="CRZ" URL="\ref crz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * OVL [URL="\ref imgdma_ovl" style=filled fillcolor="blue" fontcolor="white"];
 * VDOENC_WDMA [label="Video\nEncoder\nWDMA" URL="\ref imgdma_video_encode" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * TV_OUT_R1 [label="TV Out" color="grey" fontcolor="grey"];
 * TV_OUT_R2 [label="TV Out" color="grey" fontcolor="grey"];
 * TV_OUT_R3 [label="TV Out" color="grey" fontcolor="grey"];
 * PRZ_or_CRZ [label="PRZ\nor\nCRZ" URL="\ref prz" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * R2Y0_L [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="lightskyblue1" color="grey" fontcolor="white"];
 * MPEG4_CODEC [label="MPEG-4 Codec\nor\nH.264e Decoder" color="grey" fontcolor="grey"];
 * ICON_FB [label="Icon\nBuffer" color="grey" fontcolor="grey"];
 * {
 *   rank=same;
 *   Y2R1_L;
 *   IBW1_L;
 *   LCD;
 *   ICON_FB;
 * }
 * {
 *   rank=same;
 *   PRZ_or_CRZ;
 *   R2Y0_L;
 * }
 * {
 *   rank=same;
 *   MP4_DEBLK;
 *   IPP1_L;
 * }
 * {
 *   rank=same;
 *   IRT0;
 *   IBW2_L;
 *   IRT3;
 * }
 * {
 *   rank=same;
 *   MPEG4_CODEC;
 *   VDODEC_RDMA;
 *   IRT1_L;
 *   IBR2;
 * }
 * subgraph cluster_FB
 * {
 *   rank=same;
 *   label="External Memory";
 *   BMP_FB [label="BMP or Pixel Buffer" color="grey" fontcolor="grey"];
 *   VOP_FB [label="VOP Frame Buffer" color="grey" fontcolor="grey"];
 *   REC_FB [label="Rec Frame Buffer" color="grey" fontcolor="grey"];
 *   LCD_FB_1 [label="LCD Frame Buffer" color="grey" fontcolor="grey"];
 *   LCD_FB_2 [label="LCD Frame Buffer" color="grey" fontcolor="grey"];
 *   JPEG_FB_1 [label="JPEG File Buffer" color="grey" fontcolor="grey"];
 *   JPEG_FB_2 [label="JPEG File Buffer" color="grey" fontcolor="grey"];
 *   TV_FB_1 [label="TV Out Buffer" color="grey" fontcolor="grey"];
 *   TV_FB_2 [label="TV Out Buffer" color="grey" fontcolor="grey"];
 *   THUMB_FB [label="Thumbnail Buffer" color="grey" fontcolor="grey"];
 * }
 * {
 *   rank=same;
 *   IBR1;
 *   VDOENC_WDMA;
 *   TV_OUT_R1;
 *   IRT1_R;
 *   TV_OUT_R2;
 *   JPEG_DECODER;
 *   JPEG_ENCODER;
 *   TV_OUT_R3;
 *   IBW1_R;
 * }
 * {
 *   rank=same;
 *   PRZ_R1;
 *   IPP1_R2;
 *   CRZ_R2;
 *   JPEG_DMA;
 * }
 * {
 *   rank=same;
 *   IPP1_R1;
 *   PRZ_R2;
 *   DRZ;
 * }
 * {
 *   rank=same;
 *   ISP;
 *   CRZ_R1;
 *   OVL;
 * }
 * BMP_FB -> IBR1 -> R2Y0_R -> PRZ_R1 -> IPP1_R1 [color="grey"];
 * MPEG4_CODEC -> VOP_FB [dir=back color="grey"];
 * REC_FB -> TV_OUT_R1 [color="grey"];
 * VDODEC_RDMA -> REC_FB [dir=back color="grey"];
 * LCD_FB_2 -> TV_OUT_R2 [color="grey"];
 * IBR2 -> LCD_FB_2 [dir=back color="grey"];
 * TV_FB_2 -> TV_OUT_R3 [color="grey"];
 * IRT2 -> IBR2 [dir=back color="grey"];
 * PRZ_or_CRZ -> IRT0 [dir=back color="grey"];
 * MP4_DEBLK -> IRT0 [dir=back color="grey"];
 * MP4_DEBLK -> IPP1_L [color="grey"];
 * LCD_FB_1 -> IRT1_R -> IBW2_R -> IPP2_R -> Y2R0_R -> IPP1_R2 -> PRZ_R2 [dir=back];
 * IRT1_L -> LCD_FB_1 [color="grey"];
 * LCD -> IRT2 [dir=back color="grey"];
 * IRT3 -> TV_FB_1 [color="grey"];
 * IBW1_L -> LCD [color="grey"];
 * IBW2_L -> IRT1_L [color="grey"];
 * LCD -> IBW2_L [dir=back color="grey"];
 * IPP1_L -> Y2R0_L [color="grey"];
 * IPP1_R1 -> OVL [color="grey"];
 * IPP2_L -> IBW2_L [color="grey"];
 * Y2R0_L -> IPP2_L [color="grey"];
 * THUMB_FB -> IBW1_R -> Y2R1_R -> DRZ [dir=back color="grey"];
 * Y2R1_L -> IBW1_L [color="grey"];
 * PRZ_or_CRZ -> R2Y0_L [dir=back color="grey"];
 * PRZ_R1 -> IPP1_R2 [color="grey"];
 * Y2R1_L -> PRZ_or_CRZ [dir=back color="grey"];
 * PRZ_or_CRZ -> IPP1_L [color="grey"];
 * CRZ_R1 -> OVL [color="grey"];
 * CRZ_R2 -> OVL;
 * IPP1_R2 -> CRZ_R2 [dir=back color="grey"];
 * VOP_FB -> VDOENC_WDMA -> OVL [dir=back color="grey"];
 * JPEG_DMA -> OVL [dir=back color="grey"];
 * DRZ -> OVL [dir=back color="grey"];
 * PRZ_R2 -> OVL [dir=back];
 * IRT0 -> VDODEC_RDMA [dir=back color="grey"];
 * PRZ_or_CRZ -> MP4_DEBLK [dir=back color="grey"];
 * JPEG_FB_1 -> JPEG_DECODER -> PRZ_BLK -> CRZ_R2;
 * JPEG_FB_2 -> JPEG_ENCODER -> JPEG_DMA [dir=back color="grey"];
 * ISP -> CRZ_R1 [color="grey"];
 * LCD -> ICON_FB [dir=back color="grey"];
 * LCD -> IRT3 [color="grey"];
 * MPEG4_CODEC -> REC_FB [color="grey"];
 * R2Y0_L -> IRT2 [dir=back color="grey"];
 * }
 * \enddot
 *
 * \ingroup idp
 *
 * \param scenario_id
 * \param jpeg_para
 */
kal_uint8
config_jpeg_decode_data_path_6238_series(
  MMDI_SCENERIO_ID const scenario_id,
  jpeg_decode_process_struct const * const jpeg_para)
{
  kal_uint16 target_width, target_height;
  kal_uint16 display_width = 0, display_height = 0;
  kal_uint16 src_width, src_height, image_width, image_height;
  kal_uint16 max_prz_width = 0, max_prz_height = 0;
  kal_uint8 dummy_pixel, dummy_line;
  kal_uint32 jpeg_decode_int_mem_size = 0, address_offset = 0;
  
  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  
  if (scenario_id != SCENARIO_JPEG_DECODE_ID)
  {
    ASSERT(0);
  }
  
  //Please Wei help check
  DRV_WriteReg32(0x84000020,1);
  
  intmem_init((kal_uint32*)jpeg_para->intmem_start_address, jpeg_para->intmem_size);
  extmem_init((kal_uint32*)jpeg_para->extmem_start_address, jpeg_para->extmem_size);
  
  if (KAL_FALSE == jpeg_para->memory_output)
  {
    display_width = jpeg_para->image_width;
    display_height = jpeg_para->image_height;
    
    max_prz_width = jpeg_para->image_width << 1;
    max_prz_height = jpeg_para->image_height << 1;
  }
  else if (KAL_TRUE == jpeg_para->memory_output)
  {
    display_width = jpeg_para->memory_output_width;
    display_height = jpeg_para->memory_output_height;
    
    max_prz_width = jpeg_para->memory_output_width << 1;
    max_prz_height = jpeg_para->memory_output_height << 1;
  }
  else
  {
    ASSERT(0);
  }
  
  /* |<---- src_width ----->|
   * |<-- image_width ->|
   * +------------------+---+
   * |                  |   |
   * |                  |   |
   * |                  |   |
   * |                  |   |
   * |                  |   |
   * |                  |   |
   * |                  |   |
   * +------------------+   |
   * |                      |
   * |                      |
   * +----------------------+
   */
  src_width = jpeg_file_para.jpg_decode_width;
  src_height = jpeg_file_para.jpg_decode_height;
  
  image_width = jpeg_file_para.jpg_width;
  image_height = jpeg_file_para.jpg_height;
  
  dummy_pixel = src_width - image_width;
  dummy_line = src_height - image_height;
  
  {
    kal_uint32 bpp;
    
    switch (jpeg_para->image_data_format)
    {
    case IMGDMA_IBW_OUTPUT_RGB565: bpp = 2; break;
    case IMGDMA_IBW_OUTPUT_RGB888: bpp = 3; break;
    default:
      ASSERT(0);
      break;
    }
    
    if ((((jpeg_para->image_clip_x2 - jpeg_para->image_clip_x1 + 1) *
          (jpeg_para->image_clip_y2 - jpeg_para->image_clip_y1 + 1))
         * bpp) >
        jpeg_para->image_buffer_size)
    {
      return JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH;
    }
  }
  
  if ((image_width != src_width) && (display_width != image_width))
  {
    target_width = (src_width * display_width / image_width) + 1;
  }
  else
  {
    target_width = src_width * display_width / image_width;
  }
  
  if ((image_height != src_height) && (display_height != image_height))
  {
    target_height = (src_height * display_height / image_height) + 1;
  }
  else
  {
    target_height = (src_height * display_height / image_height);
  }
  
  if ((0 == target_width) && (0 == target_height))
  {
    target_width = src_width;
    target_height = src_height;
  }
  
  dummy_pixel = (target_width * dummy_pixel) / src_width;
  dummy_line = (target_height * dummy_line) / src_height;
  
  if (KAL_TRUE == jpeg_para->memory_output)
  {
    if (jpeg_para->memory_output_buffer_size < ((target_width * target_height * 3) >> 1))
    {
      return JPEG_DECODE_TARGET_BUFFER_NOT_ENOUGH;
    }
  }
  
  /* config PRZ */
  {
    RESZ_PRZ_STRUCT  prz_struct;
    
    memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
    
    prz_struct.image_src = RESZ_SOURCE_JPEG_DECODER;
    
    /* If CRZ & PRZ both want to use the dedicated buffer,
     * the CRZ will get it because it has higher priority.
     */
    prz_struct.dedicate_memory = KAL_FALSE;
    /* Pixel-based working memory.
     *
     * I just want to use the coarse resizing stage, thus I
     * don't need to allocate line buffer for PRZ.
     */
    prz_struct.work_mem_line = 0;
    prz_struct.work_mem_addr = 0;
    
    prz_struct.coarse_en = KAL_TRUE;
    
    prz_struct.continous = KAL_FALSE;
    prz_struct.int_en = KAL_FALSE;
    
    prz_struct.output_to_CRZ = KAL_TRUE;
    prz_struct.output_to_IPP1 = KAL_FALSE;
    prz_struct.output_to_Y2R1 = KAL_FALSE;
    
    if ((src_width >= (max_prz_width << 3)) &&
        (src_height >= (max_prz_height << 3)))
    {
      prz_struct.coarse_ratio = BLOCK_CS_1_64;
      src_width >>= 3;
      src_height >>= 3;
    }
    else if ((src_width >= (max_prz_width << 2)) &&
             (src_height >= (max_prz_height << 2)))
    {
      prz_struct.coarse_ratio = BLOCK_CS_1_16;
      src_width >>= 2;
      src_height >>= 2;
    }
    else if ((src_width >= (max_prz_width << 1)) &&
             (src_height >= (max_prz_height << 1)))
    {
      prz_struct.coarse_ratio = BLOCK_CS_1_4;
      src_width >>= 1;
      src_height >>= 1;
    }
    else
    {
      prz_struct.coarse_ratio = BLOCK_CS_1_1;
    }
    
    if (src_width > 2048)
    {
      return JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL;
    }
    if (src_height > 2048)
    {
      return JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL;
    }
    if (target_width > 2048)
    {
      return JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL;
    }
    if (target_height > 2048)
    {
      return JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL;
    }
    
    /* the 'src_width' & 'src_height' is the result width &
     * height after the coarse resizing stage.
     */
    prz_struct.src_height = src_height;
    prz_struct.src_width = src_width;
    prz_struct.tar_height = src_height;
    prz_struct.tar_width = src_width;
    
    prz_struct.y_h_factor = jpeg_file_para.y_h_sample_factor;
    prz_struct.y_v_factor = jpeg_file_para.y_v_sample_factor;
    
    if (1 == jpeg_file_para.number_of_component)
    {
      /* No U, V component */
      prz_struct.u_h_factor = 6;
      prz_struct.u_v_factor = 6;
      
      prz_struct.v_h_factor = 6;
      prz_struct.v_v_factor = 6;
    }
    else if (3 == jpeg_file_para.number_of_component)
    {
      prz_struct.u_h_factor = jpeg_file_para.u_h_sample_factor;
      prz_struct.u_v_factor = jpeg_file_para.u_v_sample_factor;
      
      prz_struct.v_h_factor = jpeg_file_para.v_h_sample_factor;
      prz_struct.v_v_factor = jpeg_file_para.v_v_sample_factor;
    }
    
    if ((target_width > src_width) || (target_height > src_height))
    {
      jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.y_v_sample_factor << 3) + jpeg_file_para.y_v_sample_factor)) & 0xFFFFFFFC) + 4);
      jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.u_v_sample_factor << 3) + jpeg_file_para.u_v_sample_factor)) & 0xFFFFFFFC) + 4);
      jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.v_v_sample_factor << 3) + jpeg_file_para.v_v_sample_factor)) & 0xFFFFFFFC) + 4);
      
      if (jpeg_decode_int_mem_size > jpeg_para->intmem_size)
      {
        return JPEG_DECODE_INT_BUFFER_NOT_ENOUGH;
      }
      
      prz_struct.y_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * ((jpeg_file_para.y_v_sample_factor << 3) + jpeg_file_para.y_v_sample_factor)));
      prz_struct.u_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * ((jpeg_file_para.u_v_sample_factor << 3) + jpeg_file_para.u_v_sample_factor)));
      prz_struct.v_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * ((jpeg_file_para.v_v_sample_factor << 3) + jpeg_file_para.v_v_sample_factor)));
      prz_struct.y_line_buff_size = ((jpeg_file_para.y_v_sample_factor << 3) + jpeg_file_para.y_v_sample_factor);
    }
    else
    {
      jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.y_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
      jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.u_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
      jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.v_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
      
      if (jpeg_decode_int_mem_size > jpeg_para->intmem_size)
      {
        return JPEG_DECODE_INT_BUFFER_NOT_ENOUGH;
      }
      
      prz_struct.y_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * (jpeg_file_para.y_v_sample_factor << 3)));
      prz_struct.u_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * (jpeg_file_para.u_v_sample_factor << 3)));
      prz_struct.v_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * (jpeg_file_para.v_v_sample_factor << 3)));
      prz_struct.y_line_buff_size = ((jpeg_file_para.y_v_sample_factor << 3));
    }
    
    RESZ_PRZConfig(&prz_struct);
  }
  
  /* config CRZ */
  {
    RESZ_CRZ_STRUCT crz_struct;
    
    memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
    
    crz_struct.image_src = RESZ_SOURCE_PRZ;
    
    if (KAL_TRUE == jpeg_para->memory_output)
    {
      crz_struct.output_to_OVL = KAL_TRUE;
      crz_struct.output_to_IPP1 = KAL_FALSE;
    }
    else
    {
      crz_struct.output_to_OVL = KAL_FALSE;
      crz_struct.output_to_IPP1 = KAL_TRUE;
    }
    
    crz_struct.output_to_Y2R1 = KAL_FALSE;
    
    crz_struct.dedicate_memory = KAL_TRUE;
    crz_struct.work_mem_line = 4; 
    crz_struct.work_mem_addr = 0x40000000;
    
    crz_struct.continous = KAL_FALSE;
    crz_struct.int_en = KAL_FALSE;
    
    crz_struct.src_height = src_height;
    crz_struct.src_width = src_width;
    crz_struct.tar_height = target_height;
    crz_struct.tar_width = target_width;
    
    crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
    
    RESZ_CRZConfig(&crz_struct);
  }
  
  if (KAL_FALSE == jpeg_para->memory_output)
  {
    /* config IPP1 */
    {
      SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_CRZ_TO_IPP1 |
                          IMGPROC_IPP_IO_IPP2_TO_IBW2);
    }
    
    /* config IBW2 */
    {
      IMGDMA_IBW2_STRUCT ibw2_struct;
      
      memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
      
      ibw2_struct.lcd_trigger = KAL_FALSE;
      ibw2_struct.direct_couple = KAL_FALSE;
      ibw2_struct.int_en = KAL_FALSE;
      ibw2_struct.pan = KAL_TRUE;
      ibw2_struct.restart = KAL_FALSE;
      
      ibw2_struct.width = target_width;
      ibw2_struct.height = target_height;
      
      ibw2_struct.clip_left = jpeg_para->image_clip_x1;
      ibw2_struct.clip_right = jpeg_para->image_clip_x2;
      ibw2_struct.clip_top = jpeg_para->image_clip_y1;
      ibw2_struct.clip_bottom = jpeg_para->image_clip_y2;
      
      ibw2_struct.output_IRT1 = KAL_TRUE;
      
      IMGDMA_IBW2Config(&ibw2_struct);
    }
    
    /* config IRT1 */
    {
      IMGDMA_IRT1_STRUCT irt1_struct;
      kal_uint32 bpp;
      
      memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
      
      switch (jpeg_para->image_data_format)
      {
      case IMGDMA_IBW_OUTPUT_RGB565:
        irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
        bpp = 2;
        break;
        
      case IMGDMA_IBW_OUTPUT_RGB888:
        irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
        bpp = 3;
        break;
        
      default:
        ASSERT(0);
        break;
      }
      
      irt1_struct.pitch_enable = jpeg_para->image_pitch_mode;
      
      if (KAL_TRUE == irt1_struct.pitch_enable)
      {
        irt1_struct.buf1_line_pitch = jpeg_para->image_pitch_bytes;
        irt1_struct.buf2_line_pitch = jpeg_para->image_pitch_bytes;
        
        address_offset = jpeg_para->image_pitch_bytes * jpeg_para->image_clip_y1;
      }
      else
      {
        address_offset = target_width * bpp * jpeg_para->image_clip_y1;
      }
      
      if (address_offset > jpeg_para->image_buffer_address)
      {
        ASSERT(0);
      }
      
      irt1_struct.frame1_base_addr = jpeg_para->image_buffer_address - address_offset;
      irt1_struct.frame2_base_addr = jpeg_para->image_buffer_address - address_offset;
      
      irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
      if (IRT1_ROT_180 == irt1_struct.rotate)
      {
        /* frame_pitch register is only dependent on whether performing
         * rotation by 180 degree or not.
         */
        /* buf1 frame pitch */
        irt1_struct.buf1_frame_pitch = (target_width * target_height) * bpp;
        
        /* buf2 frame pitch */
        irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
      }
      else
      {
        irt1_struct.buf1_frame_pitch = 0;
        irt1_struct.buf2_frame_pitch = 0;
      }
      
      irt1_struct.int_en = KAL_TRUE;
      //irt1_struct.cb = jpeg_decode_cb;
      //Please Wei help check
      irt1_cb = jpeg_decode_cb;
      irt1_struct.restart = KAL_FALSE;
      irt1_struct.flip = KAL_FALSE;
      irt1_struct.trigger_lcd = KAL_FALSE;
      
      irt1_struct.width = target_width;
      irt1_struct.height = target_height;
      
      irt1_struct.alpha = 0;
      
      irt1_struct.fifo_len = 8;
      
      /* allocate working memory for IRT1. */
      if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
          ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
      {
        irt1_struct.fifo_base_addr = 0;
      }
      else
      {
        irt1_struct.fifo_base_addr =
          IMGDMA_IRT1GetWorkingMem(
            KAL_TRUE,
            target_width,
            bpp,
            irt1_struct.fifo_len);
      }
      
      IMGDMA_IRT1Config(&irt1_struct);
    }
    
    /* start this data path. */
    {
      ENABLE_IRT1();
      START_IBW2();
      
      ENABLE_IPP_Y2R0();
      ENABLE_IMGPROC_HW_IPP();
      
      ENABLE_CRZ();
      ENABLE_BLOCK_CS_BLOCK();
    }
  }
  else
  {
    /* The source width & height of DRZ is the output width
     * & height of CRZ.
     */
    src_width = target_width;
    src_height = target_height;
    
    display_width = jpeg_para->image_width;
    display_height = jpeg_para->image_height;
    
    target_width = display_width * src_width / (src_width - dummy_pixel);
    target_height = display_height * src_height / (src_height - dummy_line);
    
    /* config OVL */
    {
      IMGDMA_OVL_STRUCT ovl_struct;
      
      memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
      
      ovl_struct.int_en = KAL_FALSE;
      ovl_struct.restart = KAL_FALSE;
      ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
      
      ovl_struct.ouput_drz = KAL_TRUE;
      ovl_struct.output_vdoenc = KAL_TRUE;
      ovl_struct.ouput_jpeg = KAL_FALSE;
      ovl_struct.ouput_y2r0 = KAL_FALSE;
      ovl_struct.ouput_prz = KAL_FALSE;
      
      ovl_struct.overlay_frame_mode = KAL_FALSE;
      
      IMGDMA_OVLConfig(&ovl_struct);
    }
    
    /* config DRZ */
    {
      RESZ_DRZ_STRUCT drz_struct;
      
      memset(&drz_struct, 0, sizeof(RESZ_DRZ_STRUCT));
      
      drz_struct.image_src = RESZ_SOURCE_IBW3;
      drz_struct.auto_restart = KAL_FALSE;
      drz_struct.int_en = KAL_TRUE;
      drz_struct.src_height = src_height;
      drz_struct.src_width = src_width;
      drz_struct.tar_height = target_height;
      drz_struct.tar_width = target_width;
      
      RESZ_DRZConfig(&drz_struct);
    }
    
    /* config Y2R1 */
    {
      SET_IMGPROC_Y2R1_SRC(IMGPROC_Y2R1_IO_DRZ_TO_Y2R1 |
                           IMGPROC_Y2R1_IO_Y2R1_TO_IBW1);
    }
    
    {
      /* config IBW1 */
      IMGDMA_IBW1_STRUCT ibw1_struct;
      kal_uint32 bpp;
      
      memset(&ibw1_struct, 0, sizeof(IMGDMA_IBW1_STRUCT));
      
      ibw1_struct.int_enable = KAL_TRUE;
      ibw1_struct.cb = jpeg_decode_cb;
      
      switch (jpeg_para->image_data_format)
      {
      case IMGDMA_IBW_OUTPUT_RGB565:
        ibw1_struct.output_format = IMGDMA_IBW1_OUTPUT_TYPE_RGB565;
        bpp = 2;
        break;
        
      case IMGDMA_IBW_OUTPUT_RGB888:
        ibw1_struct.output_format = IMGDMA_IBW1_OUTPUT_TYPE_RGB888;
        bpp = 3;
        break;
        
      default:
        ASSERT(0);
        break;
      }
      
      if (jpeg_para->image_pitch_mode == KAL_TRUE)
      {
        ibw1_struct.pitch_enable = KAL_TRUE;
        ibw1_struct.pitch1_bytes = jpeg_para->image_pitch_bytes;
        ibw1_struct.pitch2_bytes = jpeg_para->image_pitch_bytes;
        
        address_offset = jpeg_para->image_pitch_bytes * jpeg_para->image_clip_y1;
      }
      else
      {
        ibw1_struct.pitch_enable = KAL_FALSE;
        
        address_offset = target_width * bpp * jpeg_para->image_clip_y1;
      }
      
      if (address_offset > jpeg_para->image_buffer_address)
      {
        ASSERT(0);
      }
      
      ibw1_struct.base1_addr = jpeg_para->image_buffer_address - address_offset;
      ibw1_struct.base2_addr = jpeg_para->image_buffer_address - address_offset;
      
      ibw1_struct.width = target_width;
      ibw1_struct.height = target_height;
      
      ibw1_struct.lcd_trigger = KAL_FALSE;
      ibw1_struct.auto_restart = KAL_FALSE;
      ibw1_struct.dc_couple = KAL_FALSE; 
      
      ibw1_struct.pan = KAL_TRUE;
      ibw1_struct.clip_left = jpeg_para->image_clip_x1;
      ibw1_struct.clip_right = jpeg_para->image_clip_x2;
      ibw1_struct.clip_top = jpeg_para->image_clip_y1;
      ibw1_struct.clip_bottom = jpeg_para->image_clip_y2;
      
      ibw1_struct.alpha = 0;
      
      IMGDMA_IBW1Config(&ibw1_struct);
    }
    
    /* only YUV output is supported for TV output buffer */
    /* config video encode DMA write */
    {
      IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
      
      memset(&video_encode_dma_struct, 0, sizeof(IMGDMA_VIDEO_ENCODE_STRUCT));
      
      video_encode_dma_struct.restart = KAL_FALSE;
      video_encode_dma_struct.w_trigger_r = KAL_FALSE;
      
      video_encode_dma_struct.read_done_int = KAL_FALSE;
      video_encode_dma_struct.wrtie_done_int = KAL_FALSE;
      
      video_encode_dma_struct.y_base_addr1 = (kal_uint32)jpeg_para->memory_output_buffer_address;
      video_encode_dma_struct.u_base_addr1 = (kal_uint32)jpeg_para->memory_output_buffer_address +
        src_width * src_height;
      video_encode_dma_struct.v_base_addr1 = (kal_uint32)jpeg_para->memory_output_buffer_address +
        ((src_width * src_height * 5) >> 2);
      
      video_encode_dma_struct.y_base_addr2 = video_encode_dma_struct.y_base_addr1;
      video_encode_dma_struct.u_base_addr2 = video_encode_dma_struct.u_base_addr1;
      video_encode_dma_struct.v_base_addr2 = video_encode_dma_struct.v_base_addr1;
      
      video_encode_dma_struct.encode_width = src_width;
      video_encode_dma_struct.encode_height = src_height;
      
      video_encode_dma_struct.flip = KAL_FALSE;
      video_encode_dma_struct.bypass = KAL_FALSE;
      
      IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);
    }
    
    /* start this data path. */
    {
      START_IMGDMA_VIDEO_ENCODE();
      
      START_IBW1();
      
      ENABLE_Y2R1();
      ENABLE_IMGPROC_HW_Y2R1();
      
      START_DRZ();
      
      ENABLE_CRZ();
      ENABLE_BLOCK_CS_BLOCK();
    }
  }
  
  return 0;
}

/** 
 * \brief close jpeg decode data path
 * 
 */
void
close_jpeg_decode_data_path_6238_series(void)
{
  RESET_PRZ;
  RESET_CRZ();
  
  DISABLE_IMGPROC_HW_IPP();
  DISABLE_IPP_Y2R0();
  
  STOP_IBW2();
  DISABLE_IRT1();
}

/** 
 * 
 * 
 * @param scenario_id 
 * @param jpeg_para 
 * 
 * @return 
 */
kal_uint8
config_jpeg_resize_data_path_6238_series(
  MMDI_SCENERIO_ID scenario_id,
  jpeg_file_resize_struct *jpeg_para)
{
  kal_uint16 target_width, target_height;
  kal_uint16 src_width, src_height, image_width, image_height;
  kal_uint8 dummy_pixel, dummy_line;
  kal_uint8 thumbnail_ratio_w, thumbnail_ratio_h;

  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  
  if (scenario_id != SCENARIO_JPEG_RESIZE_ID)
  {
    ASSERT(0);
  }

  if (jpeg_para->target_width * jpeg_para->target_height >= 1300000)
  {
    jpeg_para->thumbnail_mode = KAL_TRUE;
    
    /* make sure the thumbnail size < 160*160 */
    if (0 == (jpeg_para->target_width % 160))
    {
      thumbnail_ratio_w = jpeg_para->target_width / 160;
    }
    else
    {
      thumbnail_ratio_w = jpeg_para->target_width / 160 + 1;
    }
    
    if (0 == (jpeg_para->target_height % 120))
    {
      thumbnail_ratio_h = jpeg_para->target_height / 120;
    }
    else
    {
      thumbnail_ratio_h = jpeg_para->target_height / 120 + 1;
    }
    
    if (thumbnail_ratio_w < thumbnail_ratio_h)
    {
      thumbnail_ratio_w = thumbnail_ratio_h;
    }
    
    jpeg_para->thumbnail_width = jpeg_para->target_width / thumbnail_ratio_w;
    jpeg_para->thumbnail_height = jpeg_para->target_height / thumbnail_ratio_w;
  }
  else
  {
    jpeg_para->thumbnail_mode = KAL_FALSE;
  }

  intmem_init((kal_uint32 *)jpeg_para->intmem_start_address, jpeg_para->intmem_size);
  extmem_init((kal_uint32 *)jpeg_para->extmem_start_address, jpeg_para->extmem_size);
  
  src_width = jpeg_file_para.jpg_decode_width;
  src_height = jpeg_file_para.jpg_decode_height;
  
  image_width = jpeg_file_para.jpg_width;
  image_height = jpeg_file_para.jpg_height;
  
  dummy_pixel = src_width - image_width;
  dummy_line = src_height - image_height;
  
  if ((image_width != src_width) && (jpeg_para->target_width != image_width))
  {
    target_width = (src_width * jpeg_para->target_width / image_width) + 1;
  }
  else
  {
    target_width = src_width * jpeg_para->target_width / image_width;
  }

  if ((image_height != src_height) && (jpeg_para->target_height != image_height))
  {
    target_height = (src_height * jpeg_para->target_height / image_height) + 1;
  }
  else
  {
    target_height = (src_height * jpeg_para->target_height / image_height);
  }
  
  if ((0 == target_width) && (0 == target_height))
  {
    target_width = src_width;
    target_height = src_height;
  }
  
  dummy_pixel = (target_width * dummy_pixel) / src_width;
  dummy_line = (target_height * dummy_line) / src_height;
  
  /* config PRZ */
  {
    RESZ_PRZ_STRUCT  prz_struct;
    
    memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
    
    prz_struct.image_src = RESZ_SOURCE_JPEG_DECODER;
    
    /* If CRZ & PRZ both want to use the dedicated buffer,
     * the CRZ will get it because it has higher priority.
     */
    prz_struct.dedicate_memory = KAL_FALSE;
    /* Pixel-based working memory.
     *
     * I just want to use the coarse resizing stage, thus I
     * don't need to allocate line buffer for PRZ.
     */
    prz_struct.work_mem_line = 0;
    prz_struct.work_mem_addr = 0;
    
    prz_struct.coarse_en = KAL_TRUE;
    
    prz_struct.continous = KAL_FALSE;
    prz_struct.int_en = KAL_FALSE;
    
    prz_struct.output_to_CRZ = KAL_TRUE;
    prz_struct.output_to_IPP1 = KAL_FALSE;
    prz_struct.output_to_Y2R1 = KAL_FALSE;
    
    prz_struct.coarse_ratio = BLOCK_CS_1_1;
    
    if (src_width > 2048)
    {
      return JPEG_DECODE_SRC_WIDHT_TOO_LARGE_FAIL;
    }
    if (src_height > 2048)
    {
      return JPEG_DECODE_SRC_HEIGHT_TOO_LARGE_FAIL;
    }
    if (target_width > 2048)
    {
      return JPEG_DECODE_TARGET_WIDTH_TOO_LARGE_FAIL;
    }
    if (target_height > 2048)
    {
      return JPEG_DECODE_TARGET_HEIGHT_TOO_LARGE_FAIL;
    }
    
    /* the 'src_width' & 'src_height' is the result width &
     * height after the coarse resizing stage.
     */
    prz_struct.src_height = src_height;
    prz_struct.src_width = src_width;
    prz_struct.tar_height = src_height;
    prz_struct.tar_width = src_width;
    
    prz_struct.y_h_factor = jpeg_file_para.y_h_sample_factor;
    prz_struct.y_v_factor = jpeg_file_para.y_v_sample_factor;
    
    if (1 == jpeg_file_para.number_of_component)
    {
      /* No U, V component */
      prz_struct.u_h_factor = 6;
      prz_struct.u_v_factor = 6;
      
      prz_struct.v_h_factor = 6;
      prz_struct.v_v_factor = 6;
    }
    else if (3 == jpeg_file_para.number_of_component)
    {
      prz_struct.u_h_factor = jpeg_file_para.u_h_sample_factor;
      prz_struct.u_v_factor = jpeg_file_para.u_v_sample_factor;
      
      prz_struct.v_h_factor = jpeg_file_para.v_h_sample_factor;
      prz_struct.v_v_factor = jpeg_file_para.v_v_sample_factor;
    }
    
    {
      kal_uint32 jpeg_decode_int_mem_size = 0;
    
      if ((target_width > src_width) || (target_height > src_height))
      {
        jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.y_v_sample_factor << 3) + jpeg_file_para.y_v_sample_factor)) & 0xFFFFFFFC) + 4);
        jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.u_v_sample_factor << 3) + jpeg_file_para.u_v_sample_factor)) & 0xFFFFFFFC) + 4);
        jpeg_decode_int_mem_size += (((src_width * ((jpeg_file_para.v_v_sample_factor << 3) + jpeg_file_para.v_v_sample_factor)) & 0xFFFFFFFC) + 4);
      
        if (jpeg_decode_int_mem_size > jpeg_para->intmem_size)
        {
          return JPEG_DECODE_INT_BUFFER_NOT_ENOUGH;
        }
      
        prz_struct.y_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * ((jpeg_file_para.y_v_sample_factor << 3) + jpeg_file_para.y_v_sample_factor)));
        prz_struct.u_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * ((jpeg_file_para.u_v_sample_factor << 3) + jpeg_file_para.u_v_sample_factor)));
        prz_struct.v_line_buff_addr = (kal_uint32)intmem_get_buffer((src_width * ((jpeg_file_para.v_v_sample_factor << 3) + jpeg_file_para.v_v_sample_factor)));
        prz_struct.y_line_buff_size = ((jpeg_file_para.y_v_sample_factor << 3) + jpeg_file_para.y_v_sample_factor);
      }
      else
      {
        jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.y_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
        jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.u_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
        jpeg_decode_int_mem_size += (((src_width * (jpeg_file_para.v_v_sample_factor << 3)) & 0xFFFFFFFC) + 4);
      
        if (jpeg_decode_int_mem_size > jpeg_para->intmem_size)
        {
          return JPEG_DECODE_INT_BUFFER_NOT_ENOUGH;
        }
      
        prz_struct.y_line_buff_addr = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.y_v_sample_factor << 3)));
        prz_struct.u_line_buff_addr = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.u_v_sample_factor << 3)));
        prz_struct.v_line_buff_addr = (kal_uint32) intmem_get_buffer((src_width * (jpeg_file_para.v_v_sample_factor << 3)));
        prz_struct.y_line_buff_size = ((jpeg_file_para.y_v_sample_factor << 3));
      }
    }
    
    RESZ_PRZConfig(&prz_struct);
  }
  
  /* config CRZ */
  {
    RESZ_CRZ_STRUCT crz_struct;
    
    memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
    
    crz_struct.image_src = RESZ_SOURCE_PRZ;
    
    crz_struct.output_to_OVL = KAL_TRUE;
    crz_struct.output_to_IPP1 = KAL_FALSE;
    crz_struct.output_to_Y2R1 = KAL_FALSE;
    
    crz_struct.dedicate_memory = KAL_TRUE;
    crz_struct.work_mem_line = 4; 
    crz_struct.work_mem_addr = 0x40000000;
    
    crz_struct.continous = KAL_FALSE;
    crz_struct.int_en = KAL_FALSE;
    
    crz_struct.src_height = src_height;
    crz_struct.src_width = src_width;
    crz_struct.tar_height = target_height;
    crz_struct.tar_width = target_width;
    
    crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
    
    RESZ_CRZConfig(&crz_struct);
  }
  
  {
    /* config OVL */
    IMGDMA_OVL_STRUCT ovl_struct;
    
    memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
    
    ovl_struct.int_en = KAL_FALSE;
    ovl_struct.restart = KAL_FALSE;
    ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    
    ovl_struct.ouput_jpeg = KAL_TRUE;
    ovl_struct.ouput_drz = KAL_TRUE;
    ovl_struct.output_vdoenc = KAL_FALSE;
    ovl_struct.ouput_y2r0 = KAL_FALSE;
    ovl_struct.ouput_prz = KAL_FALSE;
    
    ovl_struct.overlay_frame_mode = jpeg_para->overlay_frame_mode;
    
    if (KAL_TRUE == ovl_struct.overlay_frame_mode)
    {
      ovl_struct.overlay_frame_buffer_address = jpeg_para->overlay_frame_buffer_address;
      ovl_struct.overlay_frame_width = jpeg_para->overlay_frame_width;
      ovl_struct.overlay_frame_height = jpeg_para->overlay_frame_height;
      ovl_struct.overlay_frame_target_width = jpeg_para->target_width;
      ovl_struct.overlay_frame_target_height = jpeg_para->target_height;
      ovl_struct.overlay_color_depth = jpeg_para->overlay_color_depth;
      ovl_struct.overlay_frame_source_key = jpeg_para->overlay_frame_source_key;
    }
    
    IMGDMA_OVLConfig(&ovl_struct);
  }
  
  if (KAL_TRUE == jpeg_para->thumbnail_mode)
  {
    /* config DRZ */
    {
      RESZ_DRZ_STRUCT drz_struct;
    
      memset(&drz_struct, 0, sizeof(RESZ_DRZ_STRUCT));
    
      drz_struct.image_src = RESZ_SOURCE_IBW3;
      drz_struct.auto_restart = KAL_FALSE;
      drz_struct.int_en = KAL_FALSE;
      drz_struct.src_height = jpeg_para->target_height;
      drz_struct.src_width = jpeg_para->target_width;
      drz_struct.tar_width = jpeg_para->thumbnail_width;
      drz_struct.tar_height = jpeg_para->thumbnail_height;
    
      RESZ_DRZConfig(&drz_struct);
    }
    
    /* config Y2R1 */
    {
      SET_IMGPROC_Y2R1_SRC(IMGPROC_Y2R1_IO_DRZ_TO_Y2R1 |
                           IMGPROC_Y2R1_IO_Y2R1_TO_IBW1);
    }
    
    /* config IBW1 */
    {
      IMGDMA_IBW1_STRUCT ibw1_struct;
      
      memset(&ibw1_struct, 0, sizeof(IMGDMA_IBW1_STRUCT));
      
      ibw1_struct.int_enable = KAL_FALSE;
      ibw1_struct.output_format = IMGDMA_IBW1_OUTPUT_TYPE_RGB888;
      ibw1_struct.base1_addr = (kal_uint32)(jpeg_para->target_jpeg_file_address + 20);
      ibw1_struct.base2_addr = (kal_uint32)(jpeg_para->target_jpeg_file_address + 20);
      ibw1_struct.width = jpeg_para->thumbnail_width;
      ibw1_struct.height = jpeg_para->thumbnail_height;
      ibw1_struct.lcd_trigger = KAL_FALSE;
      ibw1_struct.auto_restart = KAL_FALSE;
      ibw1_struct.dc_couple = KAL_FALSE; 
      ibw1_struct.pan = KAL_FALSE; 
      ibw1_struct.pitch_enable = KAL_FALSE;
      ibw1_struct.alpha = 0;
      
      IMGDMA_IBW1Config(&ibw1_struct);
    }
  }
  
  /* config JPEG DMA */
  {
    IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
    
    memset(&jpeg_dma_struct, 0, sizeof(IMGDMA_JPEG_DMA_STRUCT));
    
    jpeg_dma_struct.restart = KAL_FALSE;
    jpeg_dma_struct.int_enable = KAL_FALSE;
    
    jpeg_dma_struct.target_width = jpeg_para->target_width;
    jpeg_dma_struct.target_height = jpeg_para->target_height;
    
    jpeg_dma_struct.jpeg_file_buffer_address = 
      IMGDMA_JPEGDMAGetWorkingMem(KAL_FALSE,
                                  jpeg_para->jpeg_yuv_mode,
                                  jpeg_para->target_width);
    
    /* YUV420, YUV422 or Gray mode */
    switch (jpeg_para->jpeg_yuv_mode)
    {
    case JPEG_FORMAT_GRAY:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_GRAY;
      break;
      
    case JPEG_FORMAT_YUV422:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV422;
      break;
      
    case JPEG_FORMAT_YUV420:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV420;
      break;
      
    case JPEG_FORMAT_YUV411:
      jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV411;
      break;
      
    default:
      ASSERT(0);
      break;
    }
    
    IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);
  }
  
  /* start this data path. */
  {
    START_IBW1();
    
    ENABLE_Y2R1();
    ENABLE_IMGPROC_HW_Y2R1();
    
    START_DRZ();
    
    START_IMGDMA_JPEG();
    if (jpeg_para->overlay_frame_mode==KAL_TRUE)
    START_OVL();
    
    ENABLE_CRZ();
    ENABLE_PRZ();
  }
  
#if 1
  config_jpeg_resize_path(jpeg_para);
#else
/* under construction !*/
#endif
  
  return 0;
}

void
close_jpeg_resize_data_path_6238_series(void)
{
  RESET_PRZ;
  RESET_CRZ();
  
  STOP_OVL();
  
  STOP_IMGDMA_JPEG();
  
  STOP_DRZ();
  
  DISABLE_IMGPROC_HW_Y2R1();
  DISABLE_Y2R1();
  
  STOP_IBW1();
  
#if 1
  close_jpeg_module(KAL_TRUE, KAL_FALSE, KAL_TRUE);
#else
/* under construction !*/
#endif
}
#endif /// #if (defined(DRV_JPG_HW_ENC_SUPPORT))

kal_uint8
config_image_resize_data_path_6238_series(
  MMDI_SCENERIO_ID scenario_id,
  resize_struct *resize_para)
{
  kal_uint32 address_offset = 0;
  
  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  if (scenario_id != SCENARIO_RESIZE_ID)
  {
    ASSERT(0);
  }

  intmem_init((kal_uint32 *)resize_para->intmem_start_address, resize_para->intmem_size);
  extmem_init((kal_uint32 *)resize_para->extmem_start_address, resize_para->extmem_size);
  
  /* config IBR1 */
  {
    IMGDMA_IBR1_STRUCT ibr1_struct;
    
    memset(&ibr1_struct, 0, sizeof(IMGDMA_IBR1_STRUCT));
    
    ibr1_struct.base_addr = resize_para->src_image_address;
    ibr1_struct.pixel_number = (resize_para->src_pitch * resize_para->src_height);// Please Wei fix it
    ibr1_struct.data_type = resize_para->type;
    ibr1_struct.data_order = resize_para->data_order;
    ibr1_struct.int_en = KAL_FALSE;
    
    IMGDMA_IBR1Config(&ibr1_struct);
  }
  
  {
    /* config R2Y0 */
    SET_IMGPROC_R2Y0_SRC(IMGPROC_R2Y0_IO_IBR1_TO_R2Y0 | 
                         IMGPROC_R2Y0_IO_R2Y0_TO_PRZ);
  }
  
  /* config PRZ */
  {
    RESZ_PRZ_STRUCT prz_struct;
    
    memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
    
    prz_struct.image_src = RESZ_SOURCE_R2Y;
    prz_struct.dedicate_memory = KAL_TRUE;
    prz_struct.continous = KAL_FALSE;
    prz_struct.int_en = KAL_FALSE;
    
    prz_struct.output_to_CRZ = KAL_FALSE;
    prz_struct.output_to_IPP1 = KAL_TRUE;
    prz_struct.output_to_Y2R1 = KAL_FALSE;
    
    prz_struct.coarse_en = KAL_FALSE;
    prz_struct.src_height = resize_para->src_height;
    prz_struct.src_width = resize_para->src_pitch;
    prz_struct.tar_height = resize_para->target_height;
    prz_struct.tar_width = resize_para->target_pitch;
    prz_struct.work_mem_line = 4;
    
    if (prz_struct.src_height > 2048 ||
        prz_struct.src_width > 2048 ||
        prz_struct.tar_height > 2048 ||
        prz_struct.tar_width > 2048)
    {
      return 1;
    }
    
    RESZ_PRZConfig(&prz_struct);
  }
  
  {
    /* config IPP1 */
    SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 | //Please Wei fix it
                        IMGPROC_IPP_IO_IPP2_TO_IBW2);
  }
  
  /* config IBW2 */
  {
    IMGDMA_IBW2_STRUCT ibw2_struct;
      
    memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
      
    ibw2_struct.lcd_trigger = KAL_FALSE;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.pan = KAL_TRUE;
    ibw2_struct.restart = KAL_FALSE;
      
    ibw2_struct.width = resize_para->target_pitch;
    ibw2_struct.height = resize_para->target_height;
      
    ibw2_struct.clip_left = resize_para->image_clip_x1;
    ibw2_struct.clip_right = resize_para->image_clip_x2;
    ibw2_struct.clip_top = resize_para->image_clip_y1;
    ibw2_struct.clip_bottom = resize_para->image_clip_y2;
    ibw2_struct.output_IRT1=KAL_TRUE;//Please Wei help fix it  
      
    IMGDMA_IBW2Config(&ibw2_struct);
  }
    
  /* config IRT1 */
  {
    IMGDMA_IRT1_STRUCT irt1_struct;
    kal_uint32 bpp;
      
    memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
      
    switch (resize_para->image_data_format)
    {
    case IMGDMA_IBW_OUTPUT_RGB565:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
      bpp = 2;
      break;
        
    case IMGDMA_IBW_OUTPUT_RGB888:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
      bpp = 3;
      break;
        
    default:
      ASSERT(0);
      break;
    }
      
    irt1_struct.pitch_enable = resize_para->image_pitch_mode;
      
    if (KAL_TRUE == irt1_struct.pitch_enable)
    {
      irt1_struct.buf1_line_pitch = resize_para->image_pitch_bytes;
      irt1_struct.buf2_line_pitch = resize_para->image_pitch_bytes;
        
      address_offset = resize_para->image_pitch_bytes * resize_para->image_clip_y1;
    }
    else
    {
      address_offset = resize_para->target_pitch * bpp * resize_para->image_clip_y1;
    }
      
    if (address_offset > resize_para->dest_image_address)
    {
      ASSERT(0);
    }
      
    irt1_struct.frame1_base_addr = resize_para->dest_image_address - address_offset;
    irt1_struct.frame2_base_addr = resize_para->dest_image_address - address_offset;
      
    irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
    if (IRT1_ROT_180 == irt1_struct.rotate)
    {
      /* frame_pitch register is only dependent on whether performing
       * rotation by 180 degree or not.
       */
      /* buf1 frame pitch */
      irt1_struct.buf1_frame_pitch =
        (resize_para->target_pitch * resize_para->target_height) * bpp;
      
      /* buf2 frame pitch */
      irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
    }
    else
    {
      irt1_struct.buf1_frame_pitch = 0;
      irt1_struct.buf2_frame_pitch = 0;
    }
      
    irt1_struct.int_en = KAL_FALSE;//Please Wei fix it
    irt1_struct.cb = NULL;//jpeg_decode_cb;//
    irt1_struct.restart = KAL_FALSE;
    irt1_struct.flip = KAL_FALSE;
    irt1_struct.trigger_lcd = KAL_FALSE;
      
    irt1_struct.width = resize_para->target_pitch;
    irt1_struct.height = resize_para->target_height;
      
    irt1_struct.alpha = 0;
      
    irt1_struct.fifo_len = 8;
      
    /* allocate working memory for IRT1. */
    if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
        ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
    {
      irt1_struct.fifo_base_addr = 0;
    }
    else
    {
      irt1_struct.fifo_base_addr =
        IMGDMA_IRT1GetWorkingMem(KAL_FALSE,
                                 resize_para->target_pitch,
                                 bpp,
                                 irt1_struct.fifo_len);
    }
    
    IMGDMA_IRT1Config(&irt1_struct);
  }
  
  /* start data path. */
  {
    ENABLE_IRT1();
    START_IBW2();
    
    ENABLE_IPP_Y2R0();
    ENABLE_IMGPROC_HW_IPP();
    
    ENABLE_PRZ();
    
    ENABLE_R2Y0();
    ENABLE_IMGPROC_HW_R2Y0();
    
    START_IBR1();
  }
  
  return 0;
}

void
close_image_resize_data_path_6238_series(void)
{
  STOP_IBR1();
  
  DISABLE_IMGPROC_HW_R2Y0();
  DISABLE_R2Y0();
  
  RESET_PRZ;
  
  DISABLE_IMGPROC_HW_IPP();
  DISABLE_IPP_Y2R0();
  
  STOP_IBW2();
  DISABLE_IRT1();
}

kal_uint8
config_video_encode_data_path_6238_series(
  MMDI_SCENERIO_ID scenario_id,
  video_encode_data_path_struct *video_para)
{
  kal_uint16 crz_out_width, crz_out_height;
  
  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  
  if (scenario_id != SCENARIO_MPEG_ENCODE_ID)
  {
    ASSERT(0);
  }
  
  current_video_buffer_count = 0;
  img_dma_ibw2_int = KAL_FALSE;
  
  kal_mem_cpy(&video_encode_config_data, video_para, sizeof(video_encode_data_path_struct));
  
  if (KAL_TRUE == video_para->init_mem)
  {
    intmem_init((kal_uint32 *)video_para->intmem_start_address, video_para->intmem_size);
    extmem_init((kal_uint32 *)video_para->extmem_start_address, video_para->extmem_size);
  }
  
  crz_out_width = video_para->encode_width;
  crz_out_height = video_para->encode_height;
  
  /* config CRZ */
  {
    RESZ_CRZ_STRUCT crz_struct;
    
    memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
    
    crz_struct.image_src = RESZ_SOURCE_ISP;
    crz_struct.output_to_OVL = KAL_TRUE;//Please Wei fix it
    crz_struct.dedicate_memory = KAL_TRUE;
    crz_struct.continous = KAL_TRUE;
    crz_struct.int_en = KAL_FALSE;
    crz_struct.src_height = video_para->image_src_height;
    crz_struct.src_width = video_para->image_src_width;
    crz_struct.tar_height = crz_out_height;
    crz_struct.tar_width = crz_out_width;
    crz_struct.work_mem_line = 4;
    crz_struct.work_mem_addr = 0x40000000;
    
    RESZ_CRZConfig(&crz_struct);
  }
  
  {
    /* config OVL */
    IMGDMA_OVL_STRUCT ovl_struct;
    
    memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
    
    ovl_struct.int_en = KAL_FALSE;
    ovl_struct.restart = KAL_TRUE;
    ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
    
    ovl_struct.ouput_jpeg = KAL_FALSE;
    ovl_struct.ouput_drz = KAL_FALSE;
    ovl_struct.output_vdoenc = KAL_TRUE;
    ovl_struct.ouput_y2r0 = KAL_FALSE;
    ovl_struct.ouput_prz = KAL_FALSE;
    
    ovl_struct.overlay_frame_mode = video_para->overlay_frame_mode;
    
    if (KAL_TRUE == ovl_struct.overlay_frame_mode)
    {
      ovl_struct.overlay_frame_buffer_address = video_para->overlay_frame_buffer_address;
      ovl_struct.overlay_frame_width = video_para->overlay_frame_width;
      ovl_struct.overlay_frame_height = video_para->overlay_frame_height;
      ovl_struct.overlay_frame_target_width = crz_out_width;
      ovl_struct.overlay_frame_target_height = crz_out_height;
      ovl_struct.overlay_color_depth = video_para->overlay_color_depth;
      ovl_struct.overlay_frame_source_key = video_para->overlay_frame_source_key;
    }
    
    IMGDMA_OVLConfig(&ovl_struct);
  }
  
  /* config video encode DMA Write */
  {
    IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
    
    memset(&video_encode_dma_struct, 0, sizeof(IMGDMA_VIDEO_ENCODE_STRUCT));
    
    video_encode_dma_struct.restart = KAL_TRUE;
    video_encode_dma_struct.w_trigger_r = KAL_TRUE;
    video_encode_dma_struct.read_done_int = KAL_FALSE;
    video_encode_dma_struct.wrtie_done_int = KAL_TRUE;
    video_encode_dma_struct.bypass = KAL_TRUE;//Please Wei check it.
    
    if (KAL_TRUE == video_para->init_mem)
    {
      video_encode_dma_struct.y_base_addr1 = (kal_uint32)extmem_get_buffer(crz_out_width * crz_out_height);
      video_encode_dma_struct.u_base_addr1 = (kal_uint32)extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
      video_encode_dma_struct.v_base_addr1 = (kal_uint32)extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
      video_encode_dma_struct.y_base_addr2 = (kal_uint32)extmem_get_buffer(crz_out_width * crz_out_height);
      video_encode_dma_struct.u_base_addr2 = (kal_uint32)extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
      video_encode_dma_struct.v_base_addr2 = (kal_uint32)extmem_get_buffer((crz_out_width * crz_out_height) >> 2);
    }
    else
    {
      /* use original setting */
      video_encode_dma_struct.y_base_addr1 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
      video_encode_dma_struct.u_base_addr1 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR1;
      video_encode_dma_struct.v_base_addr1 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR1;
      
      video_encode_dma_struct.y_base_addr2 = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
      video_encode_dma_struct.u_base_addr2 = REG_IMGDMA_VIDEO_ENCODE_U_BASE_ADDR2;
      video_encode_dma_struct.v_base_addr2 = REG_IMGDMA_VIDEO_ENCODE_V_BASE_ADDR2;
    }
    
    video_encode_dma_struct.encode_width = crz_out_width;
    video_encode_dma_struct.encode_height = crz_out_height;
    
    IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);
  }
  
  vid_enc_w_cb1 = video_para->video_encode_cb;
  vid_enc_w_cb = NULL;
  
#ifdef TV_OUT_SUPPORT
  if (KAL_TRUE == video_para->tv_output)
  {
    /* config Video encode write DMA */
    tv_output_owner = TV_OUT_OWNER_VID_DMA_W;
    tv_out_current_fb = 0;
    
    vid_enc_w_cb = mpeg4_vid_enc_w_cb;
    
    video_encode_config_data.tv_output_buffer1_address = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
    video_encode_config_data.tv_output_buffer2_address = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
    
    set_tv_output_data_format(TV_DATA_YUV420);
    set_tv_src_size(TV_OUT_OWNER_VID_DMA_W, crz_out_width, crz_out_height);
  }
#endif
  
  if (KAL_TRUE == video_para->init_mem)
  {
    mpeg4_video_buffer[0] = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR1;
    mpeg4_video_buffer[1] = REG_IMGDMA_VIDEO_ENCODE_Y_BASE_ADDR2;
  }
  
   /* config IRT0*/ //Please Wei fix it
   {
      IMGDMA_IRT0_STRUCT irt0_struct;
      
      memset(&irt0_struct, 0, sizeof(IMGDMA_IRT0_STRUCT));

      irt0_struct.int_en=KAL_FALSE; /**< enable int or not */
      irt0_struct.restart=KAL_TRUE; /**< restart or not */
      irt0_struct.src_video_dec=KAL_FALSE; /**< video dec or video enc as source */
      irt0_struct.buf_h264=KAL_FALSE; /**< h.264 or mp4 buffer */
      irt0_struct.rotate=IRT0_ROT_OFF; /**< rotate direction */
      irt0_struct.flip=KAL_FALSE; /**< flip or not */
      irt0_struct.bypass=KAL_TRUE; /**< bypass rotate or not */
      irt0_struct.output=IRT0_OUTPUT_PRZ; /**< output module */
      irt0_struct.fifo_base=0; /**< fifo base address */
      irt0_struct.width=crz_out_width; /**< width */
      irt0_struct.height=crz_out_height; /**< height */
      irt0_struct.pix_num=crz_out_width*crz_out_height; /**< total pixel number */
      irt0_struct.fifo_len=0; /**< fifo len */
      
      IMGDMA_IRT0Config(&irt0_struct);
   }
  
  
  /* config PRZ */
  {
    RESZ_PRZ_STRUCT prz_struct;
    
    memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
    
    prz_struct.image_src = RESZ_SOURCE_ROTATOR;//RESZ_SOURCE_MPEG4_ENCODE_DMA;//Please Wei fix it
    prz_struct.dedicate_memory = KAL_FALSE;
    prz_struct.continous = KAL_TRUE;
    prz_struct.int_en = KAL_FALSE;
    
    prz_struct.output_to_CRZ = KAL_FALSE;
    prz_struct.output_to_IPP1 = KAL_TRUE;
    prz_struct.output_to_Y2R1 = KAL_FALSE;
    
    prz_struct.coarse_en = KAL_FALSE;
    prz_struct.src_height = crz_out_height;
    prz_struct.src_width = crz_out_width;
    prz_struct.tar_height = video_para->display_height;
    prz_struct.tar_width = video_para->display_width;
    prz_struct.work_mem_line = 4;
    
    if (KAL_TRUE == video_para->init_mem)
    {
      /* get the max size memory first */
      prz_struct.work_mem_addr = RESZ_PRZGetWorkingMem(
        KAL_FALSE, prz_struct.tar_width);
    }
    else
    {
      /* use the original memory */
      prz_struct.work_mem_addr = (kal_uint32)REG_PRZ_WORK_MEM_ADDR;
    }
    
    RESZ_PRZConfig(&prz_struct);
  }
  
  /* config IPP1 */
  SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                      IMGPROC_IPP_IO_IPP2_TO_IBW2);

  /* config IBW2 */
  {
    IMGDMA_IBW2_STRUCT ibw2_struct;
      
    memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
      
    ibw2_struct.lcd_trigger = KAL_FALSE;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.int_en = KAL_FALSE;
    ibw2_struct.pan = KAL_FALSE;
    ibw2_struct.restart = KAL_TRUE;
    ibw2_struct.output_IRT1=KAL_TRUE;//please Wei fix it	
      
    ibw2_struct.width = video_para->display_width;
    ibw2_struct.height = video_para->display_height;
    
    IMGDMA_IBW2Config(&ibw2_struct);
  }
    
  /* config IRT1 */
  {
    IMGDMA_IRT1_STRUCT irt1_struct;
    kal_uint32 bpp;
      
    memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
      
    switch (video_para->image_data_format)
    {
    case IMGDMA_IBW_OUTPUT_RGB565:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
      bpp = 2;
      break;
        
    case IMGDMA_IBW_OUTPUT_RGB888:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
      bpp = 3;
      break;
        
    default:
      ASSERT(0);
      break;
    }
      
    irt1_struct.pitch_enable = video_para->image_pitch_mode;
      
    if (KAL_TRUE == irt1_struct.pitch_enable)
    {
      irt1_struct.buf1_line_pitch = video_para->image_pitch_bytes;
      irt1_struct.buf2_line_pitch = video_para->image_pitch_bytes;
    }
    
    irt1_struct.frame1_base_addr = video_para->frame_buffer_address;
    irt1_struct.frame2_base_addr = video_para->frame_buffer_address;
      
    irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
    if (IRT1_ROT_180 == irt1_struct.rotate)
    {
      /* frame_pitch register is only dependent on whether performing
       * rotation by 180 degree or not.
       */
      /* buf1 frame pitch */
      irt1_struct.buf1_frame_pitch =
        (video_para->display_width * video_para->display_height) * bpp;
        
      /* buf2 frame pitch */
      irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
    }
    else
    {
      irt1_struct.buf1_frame_pitch = 0;
      irt1_struct.buf2_frame_pitch = 0;
    }
      
    irt1_struct.int_en = KAL_FALSE;//Please Wei fix it
    irt1_struct.cb = NULL;//????? Please Wei fix it
    irt1_struct.restart = KAL_TRUE;
    irt1_struct.flip = KAL_FALSE;
    irt1_struct.trigger_lcd = KAL_TRUE;//Please Wei fix it
      
    irt1_struct.width = video_para->display_width;
    irt1_struct.height = video_para->display_height;
      
    irt1_struct.alpha = 0;
      
    irt1_struct.fifo_len = 8;
      
    /* allocate working memory for IRT1. */
    if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
        ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
    {
      irt1_struct.fifo_base_addr = 0;
    }
    else
    {
      irt1_struct.fifo_base_addr =
        IMGDMA_IRT1GetWorkingMem(KAL_TRUE,
                                 video_para->display_width,
                                 bpp,
                                 irt1_struct.fifo_len);
    }
    
    IMGDMA_IRT1Config(&irt1_struct);
  }
  
  {
    ENABLE_IRT1();
    START_IBW2();
    
    ENABLE_IPP_Y2R0();
    ENABLE_IMGPROC_HW_IPP();
    
    ENABLE_PRZ();
    ENABLE_IRT0();
    
    START_IMGDMA_VIDEO_ENCODE();
    if(KAL_TRUE==video_para->overlay_frame_mode)
    START_OVL();
    
    ENABLE_CRZ();
  }
  
  return 0;
}

void
reconfig_purevideo_encode_data_path_6238_series(
  MMDI_SCENERIO_ID scenario_id,
  video_encode_data_path_struct *video_para)
{
}

void
close_video_encode_data_path_6238_series(void)
{
  RESET_CRZ();
  STOP_OVL();
  STOP_IMGDMA_VIDEO_ENCODE();
  DISABLE_IRT0();
  RESET_PRZ;
  DISABLE_IMGPROC_HW_IPP();
  DISABLE_IPP_Y2R0();
  STOP_IBW2();
  DISABLE_IRT1();
}

/** 
 * \brief This function will configure video decode data
 * path.
 * 
 * \dot
 * digraph jpeg_encode_idp {
 * rankdir=LR;
 * PRZ_R2 [label="PRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_R2 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R0_R [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IPP2_R [label="IPP2" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW2_R [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT1_R [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_L [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R0_L [label="YUV\n2\nRGB_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IPP2_L [label="IPP2" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW2_L [label="IBW2" URL="\ref imgdma_ibw2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT1_L [label="Rotator_1" URL="\ref imgdma_irt1" style=filled fillcolor="blue" fontcolor="white"];
 * VDODEC_RDMA [label="Video\nDecoder\nRDMA" URL="\ref imgdma_video_decode" style=filled fillcolor="blue" fontcolor="white"];
 * IRT0 [label="Rotator_0" URL="\ref imgdma_irt0" style=filled fillcolor="blue" fontcolor="white"];
 * MP4_DEBLK [label="Deblocking\nfilter" URL="\ref imgdma_mp4_deblk" style=filled fillcolor="blue" fontcolor="white"];
 * IBR1 [label="IBR1" URL="\ref imgdma_ibr1" style=filled fillcolor="blue" fontcolor="white"];
 * R2Y0_R [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * PRZ_R1 [label="PRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * IPP1_R1 [label="IPP1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * DRZ [label="DRZ" URL="\ref drz" style=filled fillcolor="blue" fontcolor="white"];
 * Y2R1_R [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW1_R [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="blue" fontcolor="white"];
 * IBR2 [label="IBR2" URL="\ref imgdma_ibr2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT2 [label="Rotator_2" URL="\ref imgdma_irt2" style=filled fillcolor="blue" fontcolor="white"];
 * IRT3 [label="Rotator_3" URL="\ref imgdma_irt3" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_DECODER [label="JPEG\nDecoder"];
 * PRZ_BLK [label="Block-based\nConversion" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * CRZ_R2 [label="CRZ" URL="\ref crz" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_DMA [URL="\ref imgdma_jpeg" style=filled fillcolor="blue" fontcolor="white"];
 * JPEG_ENCODER [label="JPEG\nEncoder"];
 * Y2R1_L [label="YUV\n2\nRGB_1" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * IBW1_L [label="IBW1" URL="\ref imgdma_ibw1" style=filled fillcolor="blue" fontcolor="white"];
 * LCD;
 * ISP;
 * CRZ_R1 [label="CRZ" URL="\ref crz" style=filled fillcolor="blue" fontcolor="white"];
 * OVL [URL="\ref imgdma_ovl" style=filled fillcolor="blue" fontcolor="white"];
 * VDOENC_WDMA [label="Video\nEncoder\nWDMA" URL="\ref imgdma_video_encode" style=filled fillcolor="blue" fontcolor="white"];
 * TV_OUT_R1 [label="TV Out"];
 * TV_OUT_R2 [label="TV Out"];
 * TV_OUT_R3 [label="TV Out"];
 * PRZ_or_CRZ [label="PRZ\nor\nCRZ" URL="\ref prz" style=filled fillcolor="blue" fontcolor="white"];
 * R2Y0_L [label="RGB\n2\nYUV_0" URL="\ref imgproc" style=filled fillcolor="blue" fontcolor="white"];
 * MPEG4_CODEC [label="MPEG-4 Codec\nor\nH.264e Decoder"];
 * ICON_FB [label="Icon\nBuffer"];
 * {
 *   rank=same;
 *   Y2R1_L;
 *   IBW1_L;
 *   LCD;
 *   ICON_FB;
 * }
 * {
 *   rank=same;
 *   PRZ_or_CRZ;
 *   R2Y0_L;
 * }
 * {
 *   rank=same;
 *   MP4_DEBLK;
 *   IPP1_L;
 * }
 * {
 *   rank=same;
 *   IRT0;
 *   IBW2_L;
 *   IRT3;
 * }
 * {
 *   rank=same;
 *   MPEG4_CODEC;
 *   VDODEC_RDMA;
 *   IRT1_L;
 *   IBR2;
 * }
 * subgraph cluster_FB
 * {
 *   rank=same;
 *   label="External Memory";
 *   BMP_FB [label="BMP or Pixel Buffer"];
 *   VOP_FB [label="VOP Frame Buffer"];
 *   REC_FB [label="Rec Frame Buffer"];
 *   LCD_FB_1 [label="LCD Frame Buffer"];
 *   LCD_FB_2 [label="LCD Frame Buffer"];
 *   JPEG_FB_1 [label="JPEG File Buffer"];
 *   JPEG_FB_2 [label="JPEG File Buffer"];
 *   TV_FB_1 [label="TV Out Buffer"];
 *   TV_FB_2 [label="TV Out Buffer"];
 *   THUMB_FB [label="Thumbnail Buffer"];
 * }
 * {
 *   rank=same;
 *   IBR1;
 *   VDOENC_WDMA;
 *   TV_OUT_R1;
 *   IRT1_R;
 *   TV_OUT_R2;
 *   JPEG_DECODER;
 *   JPEG_ENCODER;
 *   TV_OUT_R3;
 *   IBW1_R;
 * }
 * {
 *   rank=same;
 *   PRZ_R1;
 *   IPP1_R2;
 *   CRZ_R2;
 *   JPEG_DMA;
 * }
 * {
 *   rank=same;
 *   IPP1_R1;
 *   PRZ_R2;
 *   DRZ;
 * }
 * {
 *   rank=same;
 *   ISP;
 *   CRZ_R1;
 *   OVL;
 * }
 * BMP_FB -> IBR1 -> R2Y0_R -> PRZ_R1 -> IPP1_R1;
 * MPEG4_CODEC -> VOP_FB [dir=back];
 * REC_FB -> TV_OUT_R1;
 * VDODEC_RDMA -> REC_FB [dir=back];
 * LCD_FB_2 -> TV_OUT_R2;
 * IBR2 -> LCD_FB_2 [dir=back];
 * TV_FB_2 -> TV_OUT_R3;
 * IRT2 -> IBR2 [dir=back];
 * PRZ_or_CRZ -> IRT0 [dir=back];
 * MP4_DEBLK -> IRT0 [dir=back];
 * MP4_DEBLK -> IPP1_L;
 * LCD_FB_1 -> IRT1_R -> IBW2_R -> IPP2_R -> Y2R0_R -> IPP1_R2 -> PRZ_R2 [dir=back];
 * IRT1_L -> LCD_FB_1;
 * LCD -> IRT2 [dir=back];
 * IRT3 -> TV_FB_1;
 * IBW1_L -> LCD;
 * IBW2_L -> IRT1_L;
 * LCD -> IBW2_L [dir=back];
 * IPP1_L -> Y2R0_L;
 * IPP1_R1 -> OVL;
 * IPP2_L -> IBW2_L;
 * Y2R0_L -> IPP2_L;
 * THUMB_FB -> IBW1_R -> Y2R1_R -> DRZ [dir=back];
 * Y2R1_L -> IBW1_L;
 * PRZ_or_CRZ -> R2Y0_L [dir=back];
 * PRZ_R1 -> IPP1_R2;
 * Y2R1_L -> PRZ_or_CRZ [dir=back];
 * PRZ_or_CRZ -> IPP1_L;
 * CRZ_R1 -> OVL;
 * CRZ_R2 -> OVL;
 * IPP1_R2 -> CRZ_R2 [dir=back];
 * VOP_FB -> VDOENC_WDMA -> OVL [dir=back];
 * JPEG_DMA -> OVL [dir=back];
 * DRZ -> OVL [dir=back];
 * PRZ_R2 -> OVL [dir=back];
 * IRT0 -> VDODEC_RDMA [dir=back];
 * PRZ_or_CRZ -> MP4_DEBLK [dir=back];
 * JPEG_FB_1 -> JPEG_DECODER -> PRZ_BLK -> CRZ_R2;
 * JPEG_FB_2 -> JPEG_ENCODER -> JPEG_DMA [dir=back];
 * ISP -> CRZ_R1;
 * LCD -> ICON_FB [dir=back];
 * LCD -> IRT3;
 * MPEG4_CODEC -> REC_FB;
 * R2Y0_L -> IRT2 [dir=back];
 * }
 * \enddot
 * Note that the blue components in the above graph are
 * clickable (in the HTML output).
 *
 * \param scenario_id 
 * \param video_para 
 * \param lcd_para 
 * 
 * \return 
 */
kal_uint8
config_video_decode_data_path_6238_series(
  MMDI_SCENERIO_ID const scenario_id,
  video_decode_data_path_struct * const video_para,
  lcd_frame_update_struct * const lcd_para)
{
  // remember to add it back.
  //#if (defined(MP4_CODEC) && defined(ISP_SUPPORT))
  
  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  
  if (scenario_id != SCENARIO_MPEG_DECODE_ID)
  {
    ASSERT(0);
  }
  
  intmem_init((kal_uint32 *)video_para->intmem_start_address, video_para->intmem_size);
  extmem_init((kal_uint32 *)video_para->extmem_start_address, video_para->extmem_size);
  
  /* put this value into a global variable,
   * video_decode_lcd_id, so that I can use it in the
   * close_video_decode_data_path().
   */
  video_decode_lcd_id = lcd_para->lcd_id;
  
  video_display = video_para->display;
  
  /* reset mp4 every time. */
  ENABLE_MP4_DEBLK_CORE_RST();
  ENABLE_MP4_DEBLK_APB_RST(); 
  
  /* config MP4 deblock */
  {
    MP4_DEBLK_STRUCT mp4_deblk_struct;
    
    memset(&mp4_deblk_struct, 0, sizeof(MP4_DEBLK_STRUCT));
    
    mp4_deblk_struct.width = video_para->video_src_width;
    mp4_deblk_struct.height = video_para->video_src_height;
    mp4_deblk_struct.int_enable = KAL_FALSE;
    mp4_deblk_struct.rot = IRT0_ROT_OFF;
    mp4_deblk_struct.flip_enable = KAL_FALSE;
    
    mp4_deblk_struct.output_crz = KAL_TRUE;  /* output to crz */
    mp4_deblk_struct.output_prz = KAL_FALSE;  /* output to prz */
    mp4_deblk_struct.output_ipp = KAL_FALSE;  /* output to ipp */
    
    mp4_deblk_struct.fifo_addr = 
      MP4_DEBLK_GetWorkingMem(KAL_TRUE,
                              IRT0_ROT_OFF,
                              video_para->video_src_width,
                              video_para->video_src_height);
    
    mp4_deblk_struct.quant_addr = video_para->mp4_deblk_quant_buf;
    
    MP4_DEBLK_Config(&mp4_deblk_struct);
  }
  
  /* config CRZ */
  {
    RESZ_CRZ_STRUCT crz_struct;
    
    memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
    
    crz_struct.image_src = RESZ_SOURCE_MP4_DEBLOCKING;
    crz_struct.dedicate_memory = KAL_TRUE;
    crz_struct.continous = KAL_TRUE;
    crz_struct.int_en = KAL_FALSE;
    
    crz_struct.output_to_OVL = KAL_FALSE;
    crz_struct.output_to_IPP1 = KAL_TRUE;
    crz_struct.output_to_Y2R1 = KAL_FALSE;
    
    crz_struct.src_height = video_para->video_src_height;
    crz_struct.src_width = video_para->video_src_width;
    
    crz_struct.tar_height = video_para->resize_tar_height;
    crz_struct.tar_width = video_para->resize_tar_width;
    
    crz_struct.work_mem_line = 4;
    crz_struct.work_mem_addr = 0x40000000;
    crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
    
    RESZ_CRZConfig(&crz_struct);
  }
  
  /* config IPP */
  {
    SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_CRZ_TO_IPP1 |
                        IMGPROC_IPP_IO_IPP2_TO_IBW2);
    ENABLE_IPP_Y2R0();
    
    //.... have to add it back..... adjustment_contrast_video_decode(video_para->contrast_level);
    //.... have to add it back..... adjustment_brightness_video_decode(video_para->brightness_level);
  }
  
#ifdef __VIDEO_EDITOR__
  config_video_decode_effect(video_para->effect);
#endif
  
  /* config IBW2 */
  {
    IMGDMA_IBW2_STRUCT ibw2_struct;
    
    memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
    
    ibw2_struct.lcd_trigger = KAL_FALSE;
    ibw2_struct.direct_couple = KAL_FALSE;
    ibw2_struct.int_en = KAL_FALSE;
    
    if (KAL_TRUE == video_para->pan)
    {
      ibw2_struct.pan = KAL_TRUE;
      
      /* video_para->display_width/height is for pan mode. */
      ibw2_struct.clip_left = 0;
      ibw2_struct.clip_right = video_para->display_width -1;
      ibw2_struct.clip_top = 0;
      ibw2_struct.clip_bottom = video_para->display_height - 1;
    }
    else
    {
      ibw2_struct.pan = KAL_FALSE;
    }
    
    ibw2_struct.restart = KAL_TRUE;
    
    ibw2_struct.width = video_para->resize_tar_width;
    ibw2_struct.height = video_para->resize_tar_height;
    
    ibw2_struct.output_IRT1 = KAL_TRUE;
    
    IMGDMA_IBW2Config(&ibw2_struct);
  }
    
  /* config IRT1 */
  {
    IMGDMA_IRT1_STRUCT irt1_struct;
    kal_uint32 bpp = 0;
    
    memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
    
    switch (video_para->image_data_format)
    {
      /* Yeah... I know... This is ugly, the string of the
       * IRT1 output format enumeration is embedded with
       * _IBW_, but because of forward compatibility, I
       * have to use these names.
       */
    case IMGDMA_IBW_OUTPUT_RGB565:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
      bpp = 2;
      break;
      
    case IMGDMA_IBW_OUTPUT_RGB888:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
      bpp = 3;
      break;
      
    default:
      ASSERT(0);
      break;
    }
    
    irt1_struct.pitch_enable = video_para->image_pitch_mode;
    
    if (KAL_TRUE == irt1_struct.pitch_enable)
    {
      irt1_struct.buf1_line_pitch = video_para->image_pitch_bytes;
      irt1_struct.buf2_line_pitch = video_para->image_pitch_bytes;
    }
    
    irt1_struct.frame1_base_addr = video_para->frame_buffer_address;
    irt1_struct.frame2_base_addr = video_para->frame_buffer_address;
      
    irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
    if (IRT1_ROT_180 == irt1_struct.rotate)
    {
      /* frame_pitch register is only dependent on whether performing
       * rotation by 180 degree or not.
       */
      /* buf1 frame pitch */
      irt1_struct.buf1_frame_pitch =
        (video_para->resize_tar_width * video_para->resize_tar_height) * bpp;
      
      /* buf2 frame pitch */
      irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
    }
    else
    {
      irt1_struct.buf1_frame_pitch = 0;
      irt1_struct.buf2_frame_pitch = 0;
    }
    
    irt1_struct.int_en = KAL_FALSE;
    irt1_struct.cb = NULL;
    irt1_struct.restart = KAL_FALSE;
    irt1_struct.flip = KAL_FALSE;
    
    if (KAL_TRUE == video_para->display)
    {
      irt1_struct.trigger_lcd = KAL_TRUE;
    }
    else
    {
      irt1_struct.trigger_lcd = KAL_FALSE;
    }
    
    irt1_struct.width = video_para->resize_tar_width;
    irt1_struct.height = video_para->resize_tar_height;
    
    irt1_struct.alpha = 0;
    
    irt1_struct.fifo_len = 8;
    
    /* allocate working memory for IRT1. */
    if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
        ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
    {
      irt1_struct.fifo_base_addr = 0;
    }
    else
    {
      irt1_struct.fifo_base_addr =
        IMGDMA_IRT1GetWorkingMem(KAL_FALSE,
                                 video_para->resize_tar_width,
                                 bpp,
                                 irt1_struct.fifo_len);
    }
    
    IMGDMA_IRT1Config(&irt1_struct);
  }
  
  /* config IRT0 */
  {
    IMGDMA_IRT0_STRUCT irt0_struct;
    
    memset(&irt0_struct, 0, sizeof(IMGDMA_IRT0_STRUCT));
    
    irt0_struct.int_en = KAL_FALSE;
    
    irt0_struct.restart = KAL_TRUE;
    irt0_struct.src_video_dec = KAL_TRUE;
    irt0_struct.buf_h264 = KAL_FALSE;
    irt0_struct.rotate = IRT0_ROT_OFF;
    irt0_struct.flip = KAL_FALSE;
    irt0_struct.bypass = KAL_FALSE;
    irt0_struct.output = IRT0_OUTPUT_MP4DEBLK;
    irt0_struct.width = video_para->video_src_width;
    irt0_struct.height = video_para->video_src_height;
    irt0_struct.pix_num = (video_para->video_src_width * video_para->video_src_height);
    irt0_struct.fifo_len = 8;
    irt0_struct.fifo_base =
      IMGDMA_IRT0GetWorkingMem(
        KAL_FALSE,
        video_para->video_src_width,
        video_para->video_src_height,
        irt0_struct.rotate,
        irt0_struct.fifo_len);
    
    IMGDMA_IRT0Config(&irt0_struct);
  }
  
  /* config video decode DMA */
  {
    IMGDMA_VIDEO_DECODE_STRUCT video_decode_dma_struct;
    
    memset(&video_decode_dma_struct, 0, sizeof(IMGDMA_VIDEO_DECODE_STRUCT));
    
    video_decode_dma_struct.decode_done_int = KAL_FALSE;
    video_decode_dma_struct.width = video_para->video_src_width;
    video_decode_dma_struct.height = video_para->video_src_height;
    
    video_decode_dma_struct.width = video_para->video_src_width;
    video_decode_dma_struct.height = video_para->video_src_height;
    
    SET_IMGDMA_VIDEO_DEC_PIXNUM(video_decode_dma_struct.width * video_decode_dma_struct.height);
    
    video_decode_dma_struct.buf_h264 = KAL_FALSE;
    
    video_decode_dma_struct.rot = IRT0_ROT_OFF;
    video_decode_dma_struct.flip = KAL_FALSE;
    
    video_decode_dma_struct.bypass_irt0 = KAL_FALSE;
    
    IMGDMA_VIDEODECODE_DMAConfig(&video_decode_dma_struct);
  }
  
  {
    lcd_frame_update_struct lcd_data;
    
    if (KAL_TRUE == video_para->display)
    {
      lcd_data.module_id = lcd_para->module_id;
      lcd_data.lcd_id = lcd_para->lcd_id;
      lcd_data.fb_update_mode = LCD_HW_TRIGGER_MODE;
      
      lcd_data.lcm_start_x = lcd_para->lcm_start_x;
      lcd_data.lcm_start_y = lcd_para->lcm_start_y;
      lcd_data.lcm_end_x = lcd_para->lcm_end_x;
      lcd_data.lcm_end_y = lcd_para->lcm_end_y;
      
      lcd_data.roi_offset_x = lcd_para->roi_offset_x;
      lcd_data.roi_offset_y = lcd_para->roi_offset_y;
      
      lcd_data.update_layer = lcd_para->update_layer;
      lcd_data.hw_update_layer = lcd_para->hw_update_layer;
      lcd_data.roi_background_color = lcd_para->roi_background_color;
      lcd_data.hw_trigger_src = LCD_HW_TRIGGER_IRT1;
      lcd_data.memory_output = KAL_FALSE;
      lcd_data.block_mode_flag = KAL_FALSE;
      lcd_data.lcd_block_mode_cb = NULL;
      
#ifdef TV_OUT_SUPPORT
      if ((video_para->tv_output == KAL_TRUE) &&
          ((tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE1) ||
           (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE4)))
      {
        lcd_data.tv_output = KAL_TRUE;
        lcd_data.tv_output_width = video_para->tv_output_width;
        lcd_data.tv_output_height = video_para->tv_output_height;
        lcd_data.tv_output_offset_x = video_para->tv_output_offset_x;
        lcd_data.tv_output_offset_y = video_para->tv_output_offset_y;
        lcd_data.tv_output_frame_buffer1_address = lcd_para->tv_output_frame_buffer1_address;
        lcd_data.tv_output_frame_buffer2_address = lcd_para->tv_output_frame_buffer2_address;
        lcd_data.tv_output_frame_buffer_size = lcd_para->tv_output_frame_buffer_size;
        tv_output_owner = TV_OUT_OWNER_MMI;
      }
      else
      {
        lcd_data.tv_output = KAL_FALSE;
      }
#else
      lcd_data.tv_output = KAL_FALSE;
#endif /* #ifdef TV_OUT_SUPPORT */
      
      lcd_fb_update(&lcd_data);
    }
    
#ifdef TV_OUT_SUPPORT
    if ((video_para->tv_output == KAL_TRUE) &&
        ((tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE2) ||
         (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE3)))
    {
      lcd_data.tv_output = KAL_FALSE;
      tv_output_owner = TV_OUT_OWNER_MP4_DEC;
      set_tv_src_size(TV_OUT_OWNER_MP4_DEC, video_para->tv_output_display_width, video_para->tv_output_display_height);
    }
#endif /*#ifdef TV_OUT_SUPPORT */
  }
  
  /* Yeah.. I know, this is ugly, too. Why should I start
   * the whole data path in the 'config_xxx' function?
   * However, because of forward compability, I have to
   * start it here.
   */
  {
    ENABLE_IRT1();
    START_IBW2();
    
    ENABLE_IMGPROC_HW_IPP();
    
    ENABLE_CRZ();
    
    ENABLE_MP4_DEBLK_START();
    ENABLE_IRT0();
    
    /* I can not start the video decode DMA in this
     * function, because the starting point should be put
     * into 'video_decode_display' function below.
     */
    // START_IMGDMA_VIDEO_DECODE();
  }
  
  //#endif /*defined(MP4_CODEC) && defined(ISP_SUPPORT)*/
  
  return 0;
}

void
video_decode_display_6238_series(
  video_decode_data_path_struct const * const video_para)
{
  volatile kal_uint16 i;
  
  kal_uint32 save_irq_mask;
  
  /* to avoid race condition, Video LISR() and GPT HISR */
  save_irq_mask = SaveAndSetIRQMask();
  
  if (KAL_FALSE == video_para->drop_lcm_frame)
  {
    STOP_IMGDMA_VIDEO_DECODE();
    DISABLE_IRT1();
    
    /* Reset MP4 DEBLK every times. */
    ENABLE_MP4_DEBLK_CORE_RST();
    ENABLE_MP4_DEBLK_APB_RST(); 
    
    /* config MP4 deblock */
    {
      MP4_DEBLK_STRUCT mp4_deblk_struct;
      
      memset(&mp4_deblk_struct, 0, sizeof(MP4_DEBLK_STRUCT));
    
      mp4_deblk_struct.width = video_para->video_src_width;
      mp4_deblk_struct.height = video_para->video_src_height;
      mp4_deblk_struct.int_enable = KAL_FALSE;
      mp4_deblk_struct.rot = IRT0_ROT_OFF;
      mp4_deblk_struct.flip_enable = KAL_FALSE;
      
      mp4_deblk_struct.output_crz = KAL_TRUE;  /* output to crz */
      mp4_deblk_struct.output_prz = KAL_FALSE;  /* output to prz */
      mp4_deblk_struct.output_ipp = KAL_FALSE;  /* output to ipp */
    
      mp4_deblk_struct.fifo_addr = 
        MP4_DEBLK_GetWorkingMem(KAL_TRUE,
                                IRT0_ROT_OFF,
                                video_para->video_src_width,
                                video_para->video_src_height);
      
      mp4_deblk_struct.quant_addr = video_para->mp4_deblk_quant_buf;
      
      MP4_DEBLK_Config(&mp4_deblk_struct);
    }
    
    ENABLE_MP4_DEBLK_START();
    
    if (KAL_FALSE == video_para->discard_frame_address)
    {
      REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR = video_para->video_y_buffer_address;
      REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR = video_para->video_u_buffer_address;
      REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR = video_para->video_v_buffer_address;
    }
    
#ifdef TV_OUT_SUPPORT
    /* 'lcd_sleeping_state' is defined in 'lcd_if.c" if
     * 'TV_OUT_SUPPORT' is defined.
     */
    if (KAL_FALSE == lcd_sleeping_state)
    {
#endif
      if ((REG_LCD_ROI_HW_CTRL != 0) || (KAL_FALSE == video_display))
      {
        ENABLE_IRT1();
        START_IMGDMA_VIDEO_DECODE();
      }
#ifdef TV_OUT_SUPPORT
    }
#endif
  }
  
#ifdef TV_OUT_SUPPORT
  if (video_para->tv_output == KAL_TRUE)
  {
    if ((tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE2) ||
        (tv_output_config_data.tv_output_mode == TV_OUTPUT_MODE3))
    {
      if (video_para->discard_frame_address == KAL_FALSE)
      {
        tv_fb_update_yuv420(
          TV_OUT_OWNER_MP4_DEC,
          video_para->video_y_buffer_address,
          video_para->video_u_buffer_address,
          video_para->video_v_buffer_address);
      }
    }
  }
#endif
  
  RestoreIRQMask(save_irq_mask);
  
  for (i = 0; i < 0x80; i++)
  {
  }
}

void
close_video_decode_data_path_6238_series(void)
{
  if (KAL_TRUE == video_display)
  {
    lcd_stop_hw_update(video_decode_lcd_id);
  }
  
  STOP_IMGDMA_VIDEO_DECODE();
  
  DISABLE_IRT0();
  DISABLE_MP4_DEBLK_START();
  
  RESET_CRZ();
  
  DISABLE_IMGPROC_HW_IPP();
  DISABLE_IPP_Y2R0();
  
  STOP_IBW2();
  DISABLE_IRT1();
}

kal_uint8
config_filter_effect_data_path_6238_series(ipp_effect_struct *ipp_para)
{
  /* config IPP */
  sw_block_filter_6238_series(ipp_para);
  
  return 0;
}

kal_uint8
config_pixel_effect_data_path_6238_series(ipp_effect_struct *ipp_para)
{
}

void
close_image_effect_data_path_6238_series(void)
{
}

kal_uint8
image_resize_process_6238_series(resize_struct *resize_para)
{
}

kal_bool
open_image_data_path_6238_series(MMDI_SCENERIO_ID scenario_id)
{
  kal_uint32 save_irq_mask;
  
  /* special case because MPEG_SNAPSHOT will be active in MPEG4_DECODE period */
  if ((SCENARIO_MPEG_DECODE_ID == current_image_data_path_owner) &&
      (SCENARIO_MPEG_SNAPSHOT_ID == scenario_id))
  {
    return KAL_TRUE;
  }
  
  if (current_image_data_path_owner != SCENARIO_UNKNOW_ID)
  {
    ASSERT(0);
    return KAL_FALSE;
  }
  
  // Turn on PRZ clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_PRZ;
  // Turn on resizer dedicated line buffer clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_RESZLB;
  // Turn on CRZ clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_CRZ;
  // Turn on DRZ clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_DRZ;
  // Turn on image processor clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGPROC;
  // Turn on image DMA clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_IMGDMA;
  /// Turn on MP4 DEBLK clock
  DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_MP4;
  
  save_irq_mask = SaveAndSetIRQMask();
  current_image_data_path_owner = scenario_id;
  RestoreIRQMask(save_irq_mask);
  
#ifdef MTK_SLEEP_ENABLE
  if (image_data_path_sleep_mode_handler == 0xFF)
  {
    image_data_path_sleep_mode_handler = L1SM_GetHandle();
  }
  
  L1SM_SleepDisable(image_data_path_sleep_mode_handler);
#endif
  
  switch (scenario_id)
  {
  case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
  case SCENARIO_JPEG_ENCODE_ID:
  case SCENARIO_JPEG_DECODE_ID:
  case SCENARIO_JPEG_RESIZE_ID:
#if (defined(WEBCAM_SUPPORT))
  case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
#endif
  case SCENARIO_MPEG_SNAPSHOT_ID:
    jpeg_codec_power_up();
    break;
    
  case SCENARIO_IMG_EFFECT_ID:
    /* enable IPP for configure the parameters of IPP */
    RESET_IPP;
    ENABLE_IPP;
    
    REG_IMGPROC_IPP_CFG = 0;
    REG_IMGPROC_R2Y0_CFG = 0;
    REG_IMGPROC_R2Y1_CFG = 0;
    REG_IMGPROC_IPP_SDTCON = 0;
    REG_IMGPROC_Y2R1_SDTCON = 0;
    break;
    
  default:
    break;
  }
  
  return KAL_TRUE;
}

void
close_image_data_path_6238_series(MMDI_SCENERIO_ID scenario_id)
{
  kal_uint32 save_irq_mask;
  kal_uint32 reg;
  
  if (SCENARIO_MPEG_SNAPSHOT_ID == scenario_id)
  {
    /* special case because MPEG_SNAPSHOT will be active in MPEG4_DECODE period */
    close_jpeg_encode_data_path();
    current_image_data_path_owner = SCENARIO_UNKNOW_ID;
    return;
  }
  
  if (current_image_data_path_owner != scenario_id)
  {
    ASSERT(0);
  }
  
  switch (scenario_id)
  {
  case SCENARIO_CAMERA_PREVIEW_ID:
    close_camera_preview_data_path();
    break;
    
#if (defined(WEBCAM_SUPPORT))
  case SCENARIO_USBVIDEO_CAPTURE_JPEG_ID:
#endif
  case SCENARIO_CAMERA_CAPTURE_JPEG_ID:
    close_camera_capture_jpeg_data_path();
    break;
    
  case SCENARIO_CAMERA_CAPTURE_MEM_ID:
    close_camera_capture_mem_data_path();
    break;
    
  case SCENARIO_CAMERA_CAPTURE_BARCODE_ID:
    close_camera_capture_barcode_data_path();
    break;
    
  case SCENARIO_MPEG_ENCODE_ID:
    close_video_encode_data_path();
    break;
    
  case SCENARIO_MPEG_DECODE_ID:
    close_video_decode_data_path();
    break;
    
  case SCENARIO_JPEG_DECODE_ID:
    close_jpeg_decode_data_path();
    break;
    
  case SCENARIO_JPEG_ENCODE_ID:
    close_jpeg_encode_data_path();
    break;
    
  case SCENARIO_JPEG_RESIZE_ID:
    close_jpeg_resize_data_path();
    break;
    
  case SCENARIO_IMG_EFFECT_ID:
    close_image_effect_data_path();
    break;
    
  case SCENARIO_RESIZE_ID:
    close_image_resize_data_path();
    break;        
    
  case SCENARIO_RGB2YUV420_ID:
    stop_RGB2YUV420_data_path();
    break;
    
#ifdef __VIDEO_EDITOR__        
  case SCENARIO_VIDEO_EDITOR_ID:
    close_video_editor_data_path();
    break;
#endif    
    
#ifdef __3G_VIDEO_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__3G_VIDEO_CALL__*/    
  }
  
  save_irq_mask = SaveAndSetIRQMask();
  
  /* IMGDMA */
  reg = DRV_Reg32(IMGDMA_STATUS_REG);
  REG_IMGDMA_INT_ACK = (reg & 0xffff);
  
  /* PRZ */
  reg = DRV_Reg32(PRZ_INT_STATUS_REG);
  
  /* CRZ */
  reg = DRV_Reg32(CRZ_INT_STATUS_REG);
  
  /* DRZ */
  REG_DRZ_INT_ACK = 0x1;
  /* clear MP4 DEBLK interrupt, ACK */
  REG_MP4_DEBLK_IRQ_ACK = 0x1;
  
  RestoreIRQMask(save_irq_mask);
  
  // Turn off PRZ clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_PRZ;
  // Turn off resizer dedicated line buffer clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_RESZLB;
  // Turn off CRZ clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_CRZ;
  // Turn off DRZ clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_DRZ;
  // Turn off image processor clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_IMGPROC;
  // Turn off image DMA clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_IMGDMA;
  /// Turn off MP4 DEBLK clock
  DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_MP4;
  
  current_image_data_path_owner = SCENARIO_UNKNOW_ID;
#ifdef TV_OUT_SUPPORT
  tv_output_owner = TV_OUT_OWNER_MMI;
#endif
  
#ifdef MTK_SLEEP_ENABLE
  L1SM_SleepEnable(image_data_path_sleep_mode_handler);
#endif
  
  {
    if ((scenario_id != SCENARIO_RGB2YUV420_ID) &&
        (scenario_id != SCENARIO_VIDEO_EDITOR_ID))
    {
      if (scenario_id != SCENARIO_MPEG_ENCODE_ID)
      {
        intmem_deinit();
        extmem_deinit();
      }
      else
      {
        /* Used for MPEG_ENCODE */
        if (release_mpeg4_mem())
        {
          intmem_deinit();
          extmem_deinit();
        }
      }
    }
  }
}

void
image_data_path_init_6238_series(void)
{
  IMGDMA_Init();
  IMGPROC_Init();
  MP4_DEBLK_Init();
  RESZ_PRZInit();
  RESZ_CRZInit();
  RESZ_DRZInit();
}

kal_bool
idp_register_app_6238_series(MMDI_SCENERIO_ID new_app,
                             MMDI_SCENERIO_ID *old_app)
{
  *old_app = current_image_data_path_owner;
  
  if (current_image_data_path_owner == SCENARIO_UNKNOW_ID)
  {
    /* no exist app */
    return KAL_TRUE;
  }
  else
  {
    /* MPEG decode and MPEG snapshot can coexist */
    if ((current_image_data_path_owner == SCENARIO_MPEG_DECODE_ID) &&
        (new_app == SCENARIO_MPEG_SNAPSHOT_ID))
    {
      return KAL_TRUE;
    }
    
    if ((new_app == SCENARIO_MPEG_DECODE_ID) &&
        (current_image_data_path_owner == SCENARIO_MPEG_SNAPSHOT_ID))
    {
      return KAL_TRUE;
    }
    
    return KAL_FALSE;
  }
}
// 6238 camera preview start
kal_uint8 config_camera_preview_data_path_6238_series(MMDI_SCENERIO_ID scenario_id, camera_preview_data_path_struct *preview_para)
{         
   
   /*check owner id*/    
   if (current_image_data_path_owner != scenario_id)
       ASSERT(0);
   if (scenario_id != SCENARIO_CAMERA_PREVIEW_ID)
       ASSERT(0);
       
   /*check tv out buffer size*/        
   #ifdef TV_OUT_SUPPORT
      if (preview_para->tv_output == KAL_TRUE)
      {
        if ((preview_para->tv_output_buffer_size)<((preview_para->tv_output_width * preview_para->tv_output_height*3)>>1))
              ASSERT(0);
      }
   #endif/* TV_OUT_SUPPORT */
      
   /*memory init*/
   intmem_init((kal_uint32*) preview_para->intmem_start_address, preview_para->intmem_size);
   extmem_init((kal_uint32*) preview_para->extmem_start_address, preview_para->extmem_size);

   {            
      /* config CRZ */      
      RESZ_CRZ_STRUCT crz_struct;
    
      memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
      
      crz_struct.image_src = RESZ_SOURCE_ISP;            
      crz_struct.output_to_OVL = KAL_TRUE;
      crz_struct.output_to_IPP1 = KAL_FALSE;            
      crz_struct.output_to_Y2R1 = KAL_FALSE;      
      crz_struct.dedicate_memory = KAL_TRUE;
      crz_struct.work_mem_line = 4; 
      crz_struct.work_mem_addr = 0x40000000;     
      crz_struct.continous = KAL_TRUE;
      crz_struct.int_en = KAL_FALSE;      
      crz_struct.src_width = preview_para->image_src_width;
      crz_struct.src_height = preview_para->image_src_height;      
      crz_struct.tar_width = preview_para->preview_width;
      crz_struct.tar_height = preview_para->preview_height;            
      crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
      
      RESZ_CRZConfig(&crz_struct);            
   }  
   
   {
     /* config OVL */
     IMGDMA_OVL_STRUCT ovl_struct;
     
     memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
     
     ovl_struct.int_en = KAL_FALSE;
     ovl_struct.restart = KAL_TRUE;
     ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
     
     ovl_struct.ouput_jpeg = KAL_FALSE;
     ovl_struct.ouput_drz = KAL_FALSE;
     ovl_struct.output_vdoenc = KAL_FALSE;
     ovl_struct.ouput_y2r0 = KAL_FALSE;
     ovl_struct.ouput_prz = KAL_TRUE;
     
     ovl_struct.overlay_frame_mode = preview_para->overlay_frame_mode;
     
     if (KAL_TRUE == ovl_struct.overlay_frame_mode)
     {
        ovl_struct.overlay_frame_buffer_address = preview_para->overlay_frame_buffer_address;
        ovl_struct.overlay_frame_width = preview_para->overlay_frame_width;
        ovl_struct.overlay_frame_height = preview_para->overlay_frame_height;
        ovl_struct.overlay_frame_target_width = preview_para->preview_width;
        ovl_struct.overlay_frame_target_height = preview_para->preview_height;
        ovl_struct.overlay_color_depth = preview_para->overlay_color_depth;
        ovl_struct.overlay_frame_source_key = preview_para->overlay_frame_source_key;
     }
     
     IMGDMA_OVLConfig(&ovl_struct);
  }
   /* config PRZ */
  {
     RESZ_PRZ_STRUCT prz_struct;
     
     memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
     
     prz_struct.image_src = RESZ_SOURCE_IBW4;
     prz_struct.dedicate_memory = KAL_FALSE;
     prz_struct.continous = KAL_TRUE;
     prz_struct.int_en = KAL_FALSE;
     
     prz_struct.output_to_CRZ = KAL_FALSE;
     prz_struct.output_to_IPP1 = KAL_TRUE;
     prz_struct.output_to_Y2R1 = KAL_FALSE;
     
     prz_struct.coarse_en = KAL_FALSE;
     prz_struct.src_width = preview_para->preview_width;
     prz_struct.src_height = preview_para->preview_height;
     prz_struct.tar_width = preview_para->preview_width;
     prz_struct.tar_height = preview_para->preview_height;
     
     prz_struct.work_mem_line = 4;
     
     if((prz_struct.tar_width%2)==0)
         prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, prz_struct.tar_width);
     else
         prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, (prz_struct.tar_width+1));
                        
     RESZ_PRZConfig(&prz_struct);
   }
   /* config IPP1 */
   {
      SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                          IMGPROC_IPP_IO_IPP2_TO_IBW2);
                                
   }  
   /* config IBW2 */
   {
      IMGDMA_IBW2_STRUCT ibw2_struct;
      
      memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
      
      ibw2_struct.lcd_trigger = KAL_FALSE;                         
      ibw2_struct.direct_couple = KAL_FALSE;                       
      ibw2_struct.int_en = KAL_FALSE;                              
      ibw2_struct.pan = KAL_FALSE;                                 
      ibw2_struct.restart = KAL_TRUE;                             
      ibw2_struct.output_IRT1=KAL_TRUE;                            
                                                                   
      ibw2_struct.width = preview_para->preview_width;              
      ibw2_struct.height = preview_para->preview_height;            
                                                                   
      ibw2_struct.clip_left = 0;                                   
      ibw2_struct.clip_right = preview_para->preview_width;         
      ibw2_struct.clip_top = 0;
      ibw2_struct.clip_bottom = preview_para->preview_height;
            
      IMGDMA_IBW2Config(&ibw2_struct);
   }
   /*?????, need to add new interface to MMI*/
   /*IRT1 config*/
     /* config IRT1 */
  {
    IMGDMA_IRT1_STRUCT irt1_struct;
    kal_uint32 bpp;
      
    memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
      
    switch (preview_para->image_data_format)
    {
    case IMGDMA_IBW_OUTPUT_RGB565:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
      bpp = 2;
      break;
        
    case IMGDMA_IBW_OUTPUT_RGB888:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
      bpp = 3;
      break;        
    default:
      ASSERT(0);
      break;
    }
      
    irt1_struct.pitch_enable = preview_para->image_pitch_mode;
      
    if (KAL_TRUE == irt1_struct.pitch_enable)
    {
      irt1_struct.buf1_line_pitch = preview_para->image_pitch_bytes;
      irt1_struct.buf2_line_pitch = preview_para->image_pitch_bytes;
    }
    
    irt1_struct.frame1_base_addr = preview_para->frame_buffer_address;
    irt1_struct.frame2_base_addr = preview_para->frame_buffer_address1;
      
    irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
    if (IRT1_ROT_180 == irt1_struct.rotate)
    {
      /* frame_pitch register is only dependent on whether performing
       * rotation by 180 degree or not.
       */
      /* buf1 frame pitch */
      irt1_struct.buf1_frame_pitch =
        (preview_para->preview_width * preview_para->preview_height) * bpp;
        
      /* buf2 frame pitch */
      irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
    }
    else
    {
      irt1_struct.buf1_frame_pitch = 0;
      irt1_struct.buf2_frame_pitch = 0;
    }
      
    irt1_struct.int_en = KAL_FALSE;
    irt1_struct.cb = NULL;
    irt1_struct.restart = KAL_TRUE;
    irt1_struct.flip = KAL_FALSE;
    irt1_struct.trigger_lcd = KAL_TRUE;
      
    irt1_struct.width = preview_para->preview_width;
    irt1_struct.height = preview_para->preview_height;
      
    irt1_struct.alpha = 0;
      
    irt1_struct.fifo_len = 8;
      
    /* allocate working memory for IRT1. */
    if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
        ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
    {
      irt1_struct.fifo_base_addr = 0;
    }
    else
    {
      irt1_struct.fifo_base_addr =
        IMGDMA_IRT1GetWorkingMem(KAL_TRUE,
                                 preview_para->preview_width,
                                 bpp,
                                 irt1_struct.fifo_len);
    }
    
    IMGDMA_IRT1Config(&irt1_struct);
  }      	
  
   /*enable all HW module*/
   ENABLE_IRT1();  
   START_IBW2();    
   ENABLE_IMGPROC_HW_IPP();
   ENABLE_IPP_Y2R0();                              
   ENABLE_PRZ();    
   if (KAL_TRUE == preview_para->overlay_frame_mode)   
   	  START_OVL();                   
   ENABLE_CRZ();    
              
   return 0; 
         
}   /* config_camera_preview_data_path_6238_series() */

/*****************************************************************************
 * FUNCTION
 *  reconfig_camera_preview_data_path_6238_series
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  preview_para        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void reconfig_camera_preview_data_path_6238_series(MMDI_SCENERIO_ID scenario_id, camera_preview_data_path_struct *preview_para)
{
    kal_uint16 crz_out_width, crz_out_height;
    volatile kal_uint32 crz_count = 0, crz_count1 = 0, output_width_height;
    volatile kal_uint8 i;
    kal_uint8 reset_all_data_path_flag = KAL_FALSE;

    if (current_image_data_path_owner != scenario_id)
        ASSERT(0);
    if (scenario_id != SCENARIO_CAMERA_PREVIEW_ID)
        ASSERT(0);

    crz_out_width = REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF;
    crz_out_height = (REG_CRZ_TARGET_IMAGE_SIZE & 0xFFFF0000) >> 16;

    /*remove 6228 protection for weak HW */    

    /* not turn off before reconfig resizer, 6238 new feature*/    
    RESZ_CRZ_change_size(preview_para->image_src_width, preview_para->image_src_height,
                         crz_out_width, crz_out_height);
                         

}   /* reconfig_camera_preview_data_path_6238_series() */
/*****************************************************************************
 * FUNCTION
 *  close_camera_preview_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_preview_data_path_6238_series(void)
{ 
	lcd_stop_hw_update(MAIN_LCD);
   /*reset video encode write DMA call back function*/
   vid_enc_w_cb = NULL;      
   /*disable all HW module*/
   RESET_CRZ();    
   STOP_OVL();    
   STOP_IMGDMA_VIDEO_ENCODE();    
   RESET_PRZ;       
   STOP_IBW2();    
   DISABLE_IRT1();  
   DISABLE_IMGPROC_HW_IPP();
   DISABLE_IPP_Y2R0();    
}   /* close_camera_preview_data_path_6238_series() */
// 6238 camera preview end


// 6238 camera capture to JPEG start
kal_uint8 config_camera_capture_jpeg_data_path_6238_series(
                  MMDI_SCENERIO_ID scenario_id,
                  camera_capture_jpeg_data_path_struct *capture_para)
{
    kal_uint8 thumbnail_ratio_w, thumbnail_ratio_h;    

   /*check onwer id*/
    if (current_image_data_path_owner != scenario_id)
        ASSERT(0);
    if (scenario_id != SCENARIO_CAMERA_CAPTURE_JPEG_ID)
        ASSERT(0);
   /*check size*/
    if (capture_para->image_capture_width * capture_para->image_capture_height >= 1300000)
    {
        capture_para->thumbnail_mode = KAL_TRUE;
        /* make sure the thumbnail size < 160*120 */
        if ((capture_para->image_capture_width % 160) == 0)
        {
            thumbnail_ratio_w = capture_para->image_capture_width / 160;
        }
        else
        {
            thumbnail_ratio_w = capture_para->image_capture_width / 160 + 1;
        }
        if ((capture_para->image_capture_height % 120) == 0)
        {
            thumbnail_ratio_h = capture_para->image_capture_height / 120;
        }
        else
        {
            thumbnail_ratio_h = capture_para->image_capture_height / 120 + 1;
        }
        /*use the smaller one to get the bigger thumbnail */
        if (thumbnail_ratio_w > thumbnail_ratio_h)
        {
            thumbnail_ratio_w = thumbnail_ratio_h;
        }
        /*width and height must use the same ratio, otherwise thumbnail will be strange*/
        capture_para->thumbnail_width = capture_para->image_capture_width / thumbnail_ratio_w;
        capture_para->thumbnail_height = capture_para->image_capture_height / thumbnail_ratio_w;
    }
    else
    {
        capture_para->thumbnail_mode = KAL_FALSE;
    }
    
    /*XXXXX remove to JPEG*/
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif  

    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

    {            
       /* config CRZ */      
       RESZ_CRZ_STRUCT crz_struct;
     
       memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
       
       crz_struct.image_src = RESZ_SOURCE_ISP;            
       crz_struct.output_to_OVL = KAL_TRUE;
       crz_struct.output_to_IPP1 = KAL_FALSE;            
       crz_struct.output_to_Y2R1 = KAL_FALSE;      
       crz_struct.dedicate_memory = KAL_TRUE;
       crz_struct.work_mem_line = 4; 
       crz_struct.work_mem_addr = 0x40000000;     
       if (capture_para->snapshot_number > 1)
          crz_struct.continous = KAL_TRUE;
       else   
          crz_struct.continous = KAL_FALSE;
          
       crz_struct.int_en = KAL_FALSE;      
       crz_struct.src_width = capture_para->image_src_width;
       crz_struct.src_height = capture_para->image_src_height;      
       crz_struct.tar_width = capture_para->image_capture_width;
       crz_struct.tar_height = capture_para->image_capture_height;            
       crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
       
       RESZ_CRZConfig(&crz_struct);            
    }  
    
    {
      /* config OVL */
      IMGDMA_OVL_STRUCT ovl_struct;
      
      memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
      
      ovl_struct.int_en = KAL_FALSE;
      if (capture_para->snapshot_number > 1)
         ovl_struct.restart = KAL_TRUE;
      else   
         ovl_struct.restart = KAL_FALSE;
      ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
      
      ovl_struct.ouput_jpeg = KAL_TRUE;
      ovl_struct.ouput_drz = KAL_TRUE;
      ovl_struct.output_vdoenc = KAL_FALSE;
      ovl_struct.ouput_y2r0 = KAL_FALSE;
      
      if (capture_para->display==KAL_TRUE)
      ovl_struct.ouput_prz = KAL_TRUE;
      
      ovl_struct.overlay_frame_mode = capture_para->overlay_frame_mode;
      
      if (KAL_TRUE == ovl_struct.overlay_frame_mode)
      {
         ovl_struct.overlay_frame_buffer_address = capture_para->overlay_frame_buffer_address;
         ovl_struct.overlay_frame_width = capture_para->overlay_frame_width;
         ovl_struct.overlay_frame_height = capture_para->overlay_frame_height;
         ovl_struct.overlay_frame_target_width = capture_para->display_width;
         ovl_struct.overlay_frame_target_height = capture_para->display_height;
         ovl_struct.overlay_color_depth = capture_para->overlay_color_depth;
         ovl_struct.overlay_frame_source_key = capture_para->overlay_frame_source_key;
      }
      
      IMGDMA_OVLConfig(&ovl_struct);
    }
    
    /* add thumbnail */    
    if (KAL_TRUE == capture_para->thumbnail_mode)
    {
      /* config DRZ */
      {
        RESZ_DRZ_STRUCT drz_struct;
      
        memset(&drz_struct, 0, sizeof(RESZ_DRZ_STRUCT));
      
        drz_struct.image_src = RESZ_SOURCE_IBW3;
        drz_struct.auto_restart = KAL_FALSE;
        drz_struct.int_en = KAL_FALSE;
        drz_struct.src_width = capture_para->image_capture_width;
        drz_struct.src_height = capture_para->image_capture_height;      
        drz_struct.tar_width = capture_para->thumbnail_width;
        drz_struct.tar_height = capture_para->thumbnail_height;
      
        RESZ_DRZConfig(&drz_struct);
      }
      
      /* config Y2R1 */
      {
        SET_IMGPROC_Y2R1_SRC(IMGPROC_Y2R1_IO_DRZ_TO_Y2R1 |
                             IMGPROC_Y2R1_IO_Y2R1_TO_IBW1);
      }
      
      /* config IBW1 */
      {
        IMGDMA_IBW1_STRUCT ibw1_struct;
        
        memset(&ibw1_struct, 0, sizeof(IMGDMA_IBW1_STRUCT));
        
        ibw1_struct.int_enable = KAL_FALSE;
        ibw1_struct.output_format = IMGDMA_IBW1_OUTPUT_TYPE_RGB888;
        ibw1_struct.base1_addr = (kal_uint32)(capture_para->jpeg_file_start_address1 + 20);
        ibw1_struct.base2_addr = (kal_uint32)(capture_para->jpeg_file_start_address1 + 20);
        ibw1_struct.width = capture_para->thumbnail_width;
        ibw1_struct.height = capture_para->thumbnail_height;
        ibw1_struct.lcd_trigger = KAL_FALSE;
        if (capture_para->snapshot_number > 1)
            ibw1_struct.auto_restart = KAL_TRUE;
        else
            ibw1_struct.auto_restart = KAL_FALSE;    
        ibw1_struct.dc_couple = KAL_FALSE; 
        ibw1_struct.pan = KAL_FALSE; 
        ibw1_struct.pitch_enable = KAL_FALSE;
        ibw1_struct.alpha = 0;
        
        IMGDMA_IBW1Config(&ibw1_struct);
      }
    }    
    /*display*/
    if (capture_para->display == KAL_TRUE)
    {
       /* config PRZ */
       {
          RESZ_PRZ_STRUCT prz_struct;
          
          memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
          
          prz_struct.image_src = RESZ_SOURCE_IBW4;
          prz_struct.dedicate_memory = KAL_FALSE;
          if (capture_para->snapshot_number > 1)
             prz_struct.continous = KAL_TRUE;
          else   
             prz_struct.continous = KAL_FALSE;
             
          prz_struct.int_en = KAL_FALSE;          
          prz_struct.output_to_CRZ = KAL_FALSE;
          prz_struct.output_to_IPP1 = KAL_TRUE;
          prz_struct.output_to_Y2R1 = KAL_FALSE;
          
          prz_struct.coarse_en = KAL_FALSE;
          prz_struct.src_width = capture_para->image_capture_width;
          prz_struct.src_height = capture_para->image_capture_height;
          prz_struct.tar_width = capture_para->display_width;
          prz_struct.tar_height = capture_para->display_height;
          
          prz_struct.work_mem_line = 4;
          
          if((prz_struct.tar_width%2)==0)
              prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, prz_struct.tar_width);
          else
              prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, (prz_struct.tar_width+1));
                             
          RESZ_PRZConfig(&prz_struct);
        }
        /* config IPP1 */
        {
           SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                               IMGPROC_IPP_IO_IPP2_TO_IBW2);
                                     
        }  
        /* config IBW2 */
        {
           IMGDMA_IBW2_STRUCT ibw2_struct;
           
           memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
           
           ibw2_struct.lcd_trigger = KAL_FALSE;                         
           ibw2_struct.direct_couple = KAL_FALSE;                       
           ibw2_struct.int_en = KAL_FALSE;                              
           ibw2_struct.pan = KAL_FALSE;                                 
           if (capture_para->snapshot_number > 1)
              ibw2_struct.restart = KAL_TRUE;                             
           else    
              ibw2_struct.restart = KAL_FALSE;
           ibw2_struct.output_IRT1=KAL_TRUE;                                                                                                    
           ibw2_struct.width = capture_para->display_width;              
           ibw2_struct.height = capture_para->display_height;            
                                                                        
           ibw2_struct.clip_left = 0;                                   
           ibw2_struct.clip_right = capture_para->display_width;         
           ibw2_struct.clip_top = 0;
           ibw2_struct.clip_bottom = capture_para->display_height;
                 
           IMGDMA_IBW2Config(&ibw2_struct);
        }
        /*?????, need to add new interface to MMI*/
        /*IRT1 config*/
          /* config IRT1 */
       {
         IMGDMA_IRT1_STRUCT irt1_struct;
         kal_uint32 bpp;
           
         memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
           
         switch (capture_para->image_data_format)
         {
         case IMGDMA_IBW_OUTPUT_RGB565:
           irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
           bpp = 2;
           break;
             
         case IMGDMA_IBW_OUTPUT_RGB888:
           irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
           bpp = 3;
           break;        
         default:
           ASSERT(0);
           break;
         }
           
         irt1_struct.pitch_enable = capture_para->image_pitch_mode;
           
         if (KAL_TRUE == irt1_struct.pitch_enable)
         {
           irt1_struct.buf1_line_pitch = capture_para->image_pitch_bytes;
           irt1_struct.buf2_line_pitch = capture_para->image_pitch_bytes;
         }
         
         irt1_struct.frame1_base_addr = capture_para->frame_buffer_address;
         irt1_struct.frame2_base_addr = capture_para->frame_buffer_address;
           
         irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
         if (IRT1_ROT_180 == irt1_struct.rotate)
         {
           /* frame_pitch register is only dependent on whether performing
            * rotation by 180 degree or not.
            */
           /* buf1 frame pitch */
           irt1_struct.buf1_frame_pitch =
             (capture_para->display_width * capture_para->display_height) * bpp;
             
           /* buf2 frame pitch */
           irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
         }
         else
         {
           irt1_struct.buf1_frame_pitch = 0;
           irt1_struct.buf2_frame_pitch = 0;
         }
           
         irt1_struct.int_en = KAL_FALSE;
         irt1_struct.cb = NULL;
         if (capture_para->snapshot_number > 1)
            irt1_struct.restart = KAL_TRUE;
         else
            irt1_struct.restart = KAL_FALSE;    
         irt1_struct.flip = KAL_FALSE;
         irt1_struct.trigger_lcd = KAL_TRUE;
           
         irt1_struct.width = capture_para->display_width;
         irt1_struct.height = capture_para->display_height;
           
         irt1_struct.alpha = 0;
           
         irt1_struct.fifo_len = 8;
           
         /* allocate working memory for IRT1. */
         if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
             ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
         {
           irt1_struct.fifo_base_addr = 0;
         }
         else
         {
           irt1_struct.fifo_base_addr =
             IMGDMA_IRT1GetWorkingMem(KAL_TRUE,
                                      capture_para->display_width,
                                      bpp,
                                      irt1_struct.fifo_len);
         }
         
         IMGDMA_IRT1Config(&irt1_struct);
       }      
     }
     /*JPEG encode*/
     {
        IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
        
        memset(&jpeg_dma_struct, 0, sizeof(IMGDMA_JPEG_DMA_STRUCT));
        if (capture_para->snapshot_number > 1)
           jpeg_dma_struct.restart = KAL_TRUE;
        else
           jpeg_dma_struct.restart = KAL_FALSE;
           
        jpeg_dma_struct.int_enable = KAL_FALSE;
        
        jpeg_dma_struct.target_width = capture_para->image_capture_width;
        jpeg_dma_struct.target_height = capture_para->image_capture_height;
        
        jpeg_dma_struct.jpeg_file_buffer_address = IMGDMA_JPEGDMAGetWorkingMem(KAL_FALSE,
                                                   capture_para->jpeg_yuv_mode,
                                                   capture_para->image_capture_width);
        
        /* YUV420, YUV422 or Gray mode */
        switch (capture_para->jpeg_yuv_mode)
        {
        case JPEG_FORMAT_GRAY:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_GRAY;
          break;
          
        case JPEG_FORMAT_YUV422:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV422;
          break;
          
        case JPEG_FORMAT_YUV420:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV420;
          break;
          
        case JPEG_FORMAT_YUV411:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV411;
          break;
          
        default:
          ASSERT(0);
          break;
        }
        
        IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);
     }        
    
   /*enable all HW module*/
   if (capture_para->display==KAL_TRUE)
   {      	      	
   ENABLE_IRT1();  
   START_IBW2();    
   ENABLE_IMGPROC_HW_IPP();
   ENABLE_IPP_Y2R0();                              
   ENABLE_PRZ();      
   }
   if (KAL_TRUE == capture_para->overlay_frame_mode) 
      START_OVL();                   
   ENABLE_CRZ();    
   START_IMGDMA_JPEG();
   START_DRZ();
   START_IBW1();     
   ENABLE_Y2R1();                              
   ENABLE_IMGPROC_HW_Y2R1();                           
    
   /*XXXXX wait JPEG codec */    
   config_jpeg_capture_path(capture_para);
   return 0;
    
}   /* config_camera_capture_jpeg_data_path_6238_series() */

/*****************************************************************************
 * FUNCTION
 *  close_camera_preview_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_capture_jpeg_data_path_6238_series(void)
{         
   /*disable all HW module*/
   /*preview*/
   RESET_CRZ();    
   STOP_OVL();           
   RESET_PRZ;       
   STOP_IBW2();    
   DISABLE_IRT1();  
   DISABLE_IMGPROC_HW_IPP();
   DISABLE_IPP_Y2R0();    
   /*JPEG encode*/
   STOP_IMGDMA_JPEG();
   /*thumbnail*/
   DISABLE_Y2R1();
   STOP_DRZ();
   STOP_IBW1();
   /*JEPG codec*/
   /*XXXXX*/
   
}   /* close_camera_capture_jpeg_data_path_6238_series() */
// 6238 camera capture to JPEG end
kal_uint8 config_camera_capture_mem_data_path_6238_series(                
            MMDI_SCENERIO_ID scenario_id,                     
            camera_capture_mem_data_path_struct *capture_para)

{    
   /*check onwer id*/
    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_CAMERA_CAPTURE_MEM_ID)
    {
        ASSERT(0);
    }

    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

    {            
       /* config CRZ */      
       RESZ_CRZ_STRUCT crz_struct;
     
       memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
       
       crz_struct.image_src = RESZ_SOURCE_ISP;            
       crz_struct.output_to_OVL = KAL_TRUE;
       crz_struct.output_to_IPP1 = KAL_FALSE;            
       crz_struct.output_to_Y2R1 = KAL_FALSE;      
       crz_struct.dedicate_memory = KAL_TRUE;
       crz_struct.work_mem_line = 4; 
       crz_struct.work_mem_addr = 0x40000000;            
       crz_struct.continous = KAL_FALSE;          
       crz_struct.int_en = KAL_FALSE;      
       crz_struct.src_width = capture_para->image_src_width;
       crz_struct.src_height = capture_para->image_src_height;      
       crz_struct.tar_width = capture_para->image_capture_width;
       crz_struct.tar_height = capture_para->image_capture_height;            
       crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
       
       RESZ_CRZConfig(&crz_struct);            
    }  
    
    {
      /* config OVL */
      IMGDMA_OVL_STRUCT ovl_struct;
      
      memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
      
      ovl_struct.int_en = KAL_FALSE;      
      ovl_struct.restart = KAL_FALSE;
      ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
      
      ovl_struct.ouput_jpeg = KAL_FALSE;
      ovl_struct.ouput_drz = KAL_FALSE;
      ovl_struct.output_vdoenc = KAL_FALSE;
      ovl_struct.ouput_y2r0 = KAL_FALSE;
      ovl_struct.ouput_prz = KAL_TRUE;
      
      ovl_struct.overlay_frame_mode = capture_para->overlay_frame_mode;
      
      if (KAL_TRUE == ovl_struct.overlay_frame_mode)
      {
         ovl_struct.overlay_frame_buffer_address = capture_para->overlay_frame_buffer_address;
         ovl_struct.overlay_frame_width = capture_para->overlay_frame_width;
         ovl_struct.overlay_frame_height = capture_para->overlay_frame_height;
         ovl_struct.overlay_frame_target_width = capture_para->image_capture_width;
         ovl_struct.overlay_frame_target_height = capture_para->image_capture_width;
         ovl_struct.overlay_color_depth = capture_para->overlay_color_depth;
         ovl_struct.overlay_frame_source_key = capture_para->overlay_frame_source_key;
      }
      
      IMGDMA_OVLConfig(&ovl_struct);
    }
    
           
    /* config PRZ */
    {
       RESZ_PRZ_STRUCT prz_struct;
       
       memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
       
       prz_struct.image_src = RESZ_SOURCE_IBW4;
       prz_struct.dedicate_memory = KAL_FALSE;       
       prz_struct.continous = KAL_FALSE;          
       prz_struct.int_en = KAL_FALSE;          
       prz_struct.output_to_CRZ = KAL_FALSE;
       prz_struct.output_to_IPP1 = KAL_TRUE;
       prz_struct.output_to_Y2R1 = KAL_FALSE;
       
       prz_struct.coarse_en = KAL_FALSE;
       prz_struct.src_width = capture_para->image_capture_width;
       prz_struct.src_height = capture_para->image_capture_height;
       prz_struct.tar_width = capture_para->image_capture_width;
       prz_struct.tar_height = capture_para->image_capture_height;
       
       prz_struct.work_mem_line = 4;
       
       if((prz_struct.tar_width%2)==0)
           prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, prz_struct.tar_width);
       else
           prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, (prz_struct.tar_width+1));
                          
       RESZ_PRZConfig(&prz_struct);
     }
     /* config IPP1 */
     {
        SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                            IMGPROC_IPP_IO_IPP2_TO_IBW2);
                                  
     }  
     /* config IBW2 */
     {
        IMGDMA_IBW2_STRUCT ibw2_struct;
        
        memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
        
        ibw2_struct.lcd_trigger = KAL_FALSE;                         
        ibw2_struct.direct_couple = KAL_FALSE;                       
        ibw2_struct.int_en = KAL_FALSE;                              
        ibw2_struct.pan = KAL_FALSE;                                         
        ibw2_struct.restart = KAL_FALSE;
        ibw2_struct.output_IRT1=KAL_TRUE;                                                                                                    
        ibw2_struct.width = capture_para->image_capture_width;              
        ibw2_struct.height = capture_para->image_capture_height;            
                                                                     
        ibw2_struct.clip_left = 0;                                   
        ibw2_struct.clip_right = capture_para->image_capture_width;         
        ibw2_struct.clip_top = 0;
        ibw2_struct.clip_bottom = capture_para->image_capture_height;
              
        IMGDMA_IBW2Config(&ibw2_struct);
     }
     /*?????, need to add new interface to MMI*/
     /*IRT1 config*/
       /* config IRT1 */
    {
      IMGDMA_IRT1_STRUCT irt1_struct;
      kal_uint32 bpp;
        
      memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
        
      switch (capture_para->image_data_format)
      {
      case IMGDMA_IBW_OUTPUT_RGB565:
        irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
        bpp = 2;
        break;
          
      case IMGDMA_IBW_OUTPUT_RGB888:
        irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
        bpp = 3;
        break;        
      default:
        ASSERT(0);
        break;
      }
        
      irt1_struct.pitch_enable = capture_para->image_pitch_mode;
        
      if (KAL_TRUE == irt1_struct.pitch_enable)
      {
        irt1_struct.buf1_line_pitch = capture_para->image_pitch_bytes;
        irt1_struct.buf2_line_pitch = capture_para->image_pitch_bytes;
      }
      
      irt1_struct.frame1_base_addr = capture_para->frame_buffer_address;
      irt1_struct.frame2_base_addr = capture_para->frame_buffer_address;
        
      irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
      if (IRT1_ROT_180 == irt1_struct.rotate)
      {
        /* frame_pitch register is only dependent on whether performing
         * rotation by 180 degree or not.
         */
        /* buf1 frame pitch */
        irt1_struct.buf1_frame_pitch =
          (capture_para->image_capture_width * capture_para->image_capture_height) * bpp;
          
        /* buf2 frame pitch */
        irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
      }
      else
      {
        irt1_struct.buf1_frame_pitch = 0;
        irt1_struct.buf2_frame_pitch = 0;
      }
        
      irt1_struct.int_en = KAL_FALSE;
      irt1_struct.cb = NULL;      
      irt1_struct.restart = KAL_FALSE;    
      irt1_struct.flip = KAL_FALSE;
      irt1_struct.trigger_lcd = KAL_TRUE;
        
      irt1_struct.width = capture_para->image_capture_width;
      irt1_struct.height = capture_para->image_capture_height;
        
      irt1_struct.alpha = 0;
        
      irt1_struct.fifo_len = 8;
        
      /* allocate working memory for IRT1. */
      if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
          ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
      {
        irt1_struct.fifo_base_addr = 0;
      }
      else
      {
        irt1_struct.fifo_base_addr =
          IMGDMA_IRT1GetWorkingMem(KAL_TRUE,
                                   capture_para->image_capture_width,
                                   bpp,
                                   irt1_struct.fifo_len);
      }
      
      IMGDMA_IRT1Config(&irt1_struct);
    }               
   /*enable all HW module*/
   ENABLE_IRT1();  
   START_IBW2();    
   ENABLE_IMGPROC_HW_IPP();
   ENABLE_IPP_Y2R0();                              
   ENABLE_PRZ();
   if (KAL_TRUE == capture_para->overlay_frame_mode)       
       START_OVL();                   
   ENABLE_CRZ();    
   
   return 0;
    
}   /* config_camera_capture_mem_data_path() */
void close_camera_capture_mem_data_path_6238_series(void)
{         
   /*disable all HW module*/
   /*preview*/
   RESET_CRZ();    
   STOP_OVL();           
   RESET_PRZ;       
   STOP_IBW2();    
   DISABLE_IRT1();  
   DISABLE_IMGPROC_HW_IPP();
   DISABLE_IPP_Y2R0();          
}   /* close_camera_capture_mem_data_path() */
// 6238 camera capture to memory end
/*****************************************************************************
 * FUNCTION
 *  config_RGB2YUV420_data_path
 * DESCRIPTION
 *  This function is to translate RGB to YUV 
 * PARAMETERS
 *  scenario_id: scenario id
 *  rgb2yuv420_struct: 
 * RETURNS
 *  None
 *****************************************************************************/
/*translate RGB888/565 to YUV 420*/
void config_RGB2YUV420_data_path_6238_series(MMDI_SCENERIO_ID scenario_id, RGB2YUV420_struct  *rgb2yuv420_struct)
{ 
  /* config IBR1 */
  {
     IMGDMA_IBR1_STRUCT ibr1_struct;
     
     memset(&ibr1_struct, 0, sizeof(IMGDMA_IBR1_STRUCT));
     
     ibr1_struct.base_addr = rgb2yuv420_struct->src_address;
     ibr1_struct.pixel_number = (rgb2yuv420_struct->src_width * rgb2yuv420_struct->src_height);
     ibr1_struct.data_type = rgb2yuv420_struct->type;
     ibr1_struct.data_order = rgb2yuv420_struct->order;
     ibr1_struct.int_en = KAL_FALSE;
     
     IMGDMA_IBR1Config(&ibr1_struct);
  }
  {
    /* config R2Y0 */
    SET_IMGPROC_R2Y0_SRC(IMGPROC_R2Y0_IO_IBR1_TO_R2Y0 | 
                         IMGPROC_R2Y0_IO_R2Y0_TO_PRZ);
	/* config IPP1 */
    SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                        IMGPROC_IPP_IO_IPP1_TO_OVL);	                         
                         
  }
  /* config PRZ */
  {
     RESZ_PRZ_STRUCT prz_struct;
     
     memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
     
     prz_struct.image_src = RESZ_SOURCE_R2Y;
     prz_struct.dedicate_memory = KAL_TRUE;       
     prz_struct.continous = KAL_FALSE;          
     prz_struct.int_en = KAL_FALSE;          
     prz_struct.output_to_CRZ = KAL_FALSE;
     prz_struct.output_to_IPP1 = KAL_TRUE;
     prz_struct.output_to_Y2R1 = KAL_FALSE;
     
     prz_struct.coarse_en = KAL_FALSE;
     prz_struct.src_width = rgb2yuv420_struct->src_width;
     prz_struct.src_height = rgb2yuv420_struct->src_height;
     prz_struct.tar_width = rgb2yuv420_struct->src_width;
     prz_struct.tar_height = rgb2yuv420_struct->src_height;
     
     prz_struct.work_mem_line = 4;          
     prz_struct.work_mem_addr = 0x40000000;
     
                        
     RESZ_PRZConfig(&prz_struct);
  }       
  /* config IPP1 */
  {
     SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                         IMGPROC_IPP_IO_IPP1_TO_OVL);
                               
  } 
  {
     /* config OVL */
     IMGDMA_OVL_STRUCT ovl_struct;
     
     memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
     
     ovl_struct.int_en = KAL_FALSE;
     ovl_struct.restart = KAL_FALSE;
     ovl_struct.pixel_engine = PIXEL_ENGINE_IPP1;
     
     ovl_struct.ouput_jpeg = KAL_FALSE;
     ovl_struct.ouput_drz = KAL_FALSE;
     ovl_struct.output_vdoenc = KAL_TRUE;
     ovl_struct.ouput_y2r0 = KAL_FALSE;
     ovl_struct.ouput_prz = KAL_FALSE;    
     ovl_struct.overlay_frame_mode = KAL_FALSE;
             
     IMGDMA_OVLConfig(&ovl_struct);
  } 
  /* config video encode DMA Write */
  {
     IMGDMA_VIDEO_ENCODE_STRUCT video_encode_dma_struct;
     
     memset(&video_encode_dma_struct, 0, sizeof(IMGDMA_VIDEO_ENCODE_STRUCT));
     
     video_encode_dma_struct.restart = KAL_FALSE;
     video_encode_dma_struct.w_trigger_r = KAL_FALSE;
     video_encode_dma_struct.read_done_int = KAL_FALSE;
     video_encode_dma_struct.wrtie_done_int = KAL_FALSE;
     
     video_encode_dma_struct.y_base_addr1 = (kal_uint32) rgb2yuv420_struct->tar_address;
     video_encode_dma_struct.u_base_addr1 = (kal_uint32) rgb2yuv420_struct->tar_address +
                                             rgb2yuv420_struct->src_width * rgb2yuv420_struct->src_height;
     video_encode_dma_struct.v_base_addr1 = (kal_uint32) rgb2yuv420_struct->tar_address +
                                            ((rgb2yuv420_struct->src_width * rgb2yuv420_struct->src_height * 5) >> 2);
     
     video_encode_dma_struct.encode_width = rgb2yuv420_struct->src_width;
     video_encode_dma_struct.encode_height = rgb2yuv420_struct->src_height;
     
     IMGDMA_VIDEOENCODE_DMAConfig(&video_encode_dma_struct);
  }
   /*enable all HW module*/
   START_IMGDMA_VIDEO_ENCODE();       
   ENABLE_R2Y0();
   ENABLE_IMGPROC_HW_R2Y0();              
   ENABLE_PRZ();  
   ENABLE_IMGPROC_HW_IPP();            
   START_IBR1();                        
                        
  /*wait until video Encode DMA finish moving data*/
  while (IMGDMA_VIDEO_ENCODE_W_IS_BUSY)
  {
      kal_sleep_task(1);
  };         
}   

/*****************************************************************************
 * FUNCTION
 *  stop_RGB2YUV420_data_path
 * DESCRIPTION
 *  This function is to stop translating RGB to YUV 
 * PARAMETERS
 *  scenario_id: scenario id
 *  rgb2yuv420_struct: 
 * RETURNS
 *  None
 *****************************************************************************/
void stop_RGB2YUV420_data_path_6238_series(void)
{    
   /*disable all HW module*/
   STOP_IMGDMA_VIDEO_ENCODE();       
   DISABLE_R2Y0();
   DISABLE_IMGPROC_HW_R2Y0();              
   RESET_PRZ;  
   DISABLE_IMGPROC_HW_IPP();
   STOP_OVL();            
   STOP_IBR1(); 
}   

/*bar code*/

/*****************************************************************************
 * FUNCTION
 *  config_camera_capture_barcode_data_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  scenario_id         [IN]
 *  capture_para        [?]
 * RETURNS
 *
 *****************************************************************************/
 kal_uint8 config_camera_capture_barcode_data_path_6238_series(MMDI_SCENERIO_ID scenario_id, camera_capture_barcode_data_path_struct *capture_para)
{

    if (current_image_data_path_owner != scenario_id)
    {
        ASSERT(0);
    }
    if (scenario_id != SCENARIO_CAMERA_CAPTURE_BARCODE_ID)
    {
        ASSERT(0);
    }

    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);
   {            
      /* config CRZ */      
      RESZ_CRZ_STRUCT crz_struct;
    
      memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
      
      crz_struct.image_src = RESZ_SOURCE_ISP;            
      crz_struct.output_to_OVL = KAL_TRUE;
      crz_struct.output_to_IPP1 = KAL_FALSE;            
      crz_struct.output_to_Y2R1 = KAL_FALSE;      
      crz_struct.dedicate_memory = KAL_TRUE;
      crz_struct.work_mem_line = 4; 
      crz_struct.work_mem_addr = 0x40000000;     
      crz_struct.continous = KAL_TRUE;
      crz_struct.int_en = KAL_FALSE;      
      crz_struct.src_width = capture_para->image_src_width;
      crz_struct.src_height = capture_para->image_src_height;      
      crz_struct.tar_width = capture_para->barcode_image_width;
      crz_struct.tar_height = capture_para->barcode_image_height;            
      crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
      
      RESZ_CRZConfig(&crz_struct);            
   }  
   
   {
     /* config OVL */
     IMGDMA_OVL_STRUCT ovl_struct;
     
     memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
     
     ovl_struct.int_en = KAL_FALSE;
     ovl_struct.restart = KAL_TRUE;
     ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
     
     ovl_struct.ouput_jpeg = KAL_FALSE;
     ovl_struct.ouput_drz = KAL_TRUE;
     ovl_struct.output_vdoenc = KAL_FALSE;
     ovl_struct.ouput_y2r0 = KAL_FALSE;
     ovl_struct.ouput_prz = KAL_TRUE;
     
     ovl_struct.overlay_frame_mode = KAL_FALSE;//not need overlay function          
     IMGDMA_OVLConfig(&ovl_struct);
  }
   /* config PRZ */
  {
     RESZ_PRZ_STRUCT prz_struct;
     
     memset(&prz_struct, 0, sizeof(RESZ_PRZ_STRUCT));
     
     prz_struct.image_src = RESZ_SOURCE_IBW4;
     prz_struct.dedicate_memory = KAL_FALSE;
     prz_struct.continous = KAL_TRUE;
     prz_struct.int_en = KAL_FALSE;
     
     prz_struct.output_to_CRZ = KAL_FALSE;
     prz_struct.output_to_IPP1 = KAL_TRUE;
     prz_struct.output_to_Y2R1 = KAL_FALSE;
     
     prz_struct.coarse_en = KAL_FALSE;
     prz_struct.src_width = capture_para->barcode_image_width;
     prz_struct.src_height = capture_para->barcode_image_height;
     prz_struct.tar_width = capture_para->display_width;
     prz_struct.tar_height = capture_para->display_height;
     
     prz_struct.work_mem_line = 4;
     
     if((prz_struct.tar_width%2)==0)
         prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, prz_struct.tar_width);
     else
         prz_struct.work_mem_addr=(kal_uint32)RESZ_PRZGetWorkingMem(KAL_TRUE, (prz_struct.tar_width+1));
                        
     RESZ_PRZConfig(&prz_struct);
   }
   /* config IPP1 */
   {
      SET_IMGPROC_IPP_SRC(IMGPROC_IPP_IO_PRZ_TO_IPP1 |
                          IMGPROC_IPP_IO_IPP2_TO_IBW2);
                                
   }  
   /* config IBW2 */
   {
      IMGDMA_IBW2_STRUCT ibw2_struct;
      
      memset(&ibw2_struct, 0, sizeof(IMGDMA_IBW2_STRUCT));
      
      ibw2_struct.lcd_trigger = KAL_FALSE;                         
      ibw2_struct.direct_couple = KAL_FALSE;                       
      ibw2_struct.int_en = KAL_FALSE;                              
      ibw2_struct.pan = KAL_FALSE;                                 
      ibw2_struct.restart = KAL_TRUE;                             
      ibw2_struct.output_IRT1=KAL_TRUE;                            
                                                                   
      ibw2_struct.width = capture_para->display_width;              
      ibw2_struct.height = capture_para->display_height;            
                                                                   
      ibw2_struct.clip_left = 0;                                   
      ibw2_struct.clip_right = capture_para->display_width;         
      ibw2_struct.clip_top = 0;
      ibw2_struct.clip_bottom = capture_para->display_height;
            
      IMGDMA_IBW2Config(&ibw2_struct);
   }
   /*?????, need to add new interface to MMI*/
   /*IRT1 config*/
     /* config IRT1 */
  {
    IMGDMA_IRT1_STRUCT irt1_struct;
    kal_uint32 bpp;
      
    memset(&irt1_struct, 0, sizeof(IMGDMA_IRT1_STRUCT));
      
    switch (capture_para->image_data_format)
    {
    case IMGDMA_IBW_OUTPUT_RGB565:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB565;
      bpp = 2;
      break;
        
    case IMGDMA_IBW_OUTPUT_RGB888:
      irt1_struct.fmt = IRT1_OUTPUT_FMT_RGB888;
      bpp = 3;
      break;        
    default:
      ASSERT(0);
      break;
    }
      
    irt1_struct.pitch_enable = capture_para->image_pitch_mode;
      
    if (KAL_TRUE == irt1_struct.pitch_enable)
    {
      irt1_struct.buf1_line_pitch = capture_para->image_pitch_bytes;
      irt1_struct.buf2_line_pitch = capture_para->image_pitch_bytes;
    }
    
    irt1_struct.frame1_base_addr = capture_para->frame_buffer_address;
    irt1_struct.frame2_base_addr = capture_para->frame_buffer_address1;
      
    irt1_struct.rotate = IRT1_ROT_OFF; /* rotate direction */
    if (IRT1_ROT_180 == irt1_struct.rotate)
    {
      /* frame_pitch register is only dependent on whether performing
       * rotation by 180 degree or not.
       */
      /* buf1 frame pitch */
      irt1_struct.buf1_frame_pitch =
        (capture_para->display_width * capture_para->display_height) * bpp;
        
      /* buf2 frame pitch */
      irt1_struct.buf2_frame_pitch = irt1_struct.buf1_frame_pitch;
    }
    else
    {
      irt1_struct.buf1_frame_pitch = 0;
      irt1_struct.buf2_frame_pitch = 0;
    }
      
    irt1_struct.int_en = KAL_FALSE;
    irt1_struct.cb = NULL;
    irt1_struct.restart = KAL_TRUE;
    irt1_struct.flip = KAL_FALSE;
    irt1_struct.trigger_lcd = KAL_TRUE;
      
    irt1_struct.width = capture_para->display_width;
    irt1_struct.height = capture_para->display_height;
      
    irt1_struct.alpha = 0;
      
    irt1_struct.fifo_len = 8;
      
    /* allocate working memory for IRT1. */
    if (((IRT1_ROT_OFF == irt1_struct.rotate) && (KAL_FALSE == irt1_struct.flip)) ||
        ((IRT1_ROT_180 == irt1_struct.rotate) && (KAL_TRUE == irt1_struct.flip)))
    {
      irt1_struct.fifo_base_addr = 0;
    }
    else
    {
      irt1_struct.fifo_base_addr =
        IMGDMA_IRT1GetWorkingMem(KAL_TRUE,
                                 capture_para->display_width,
                                 bpp,
                                 irt1_struct.fifo_len);
    }
    
    IMGDMA_IRT1Config(&irt1_struct);
    // thumbnail for bar code
  }      
    /* config DRZ */
    {
      RESZ_DRZ_STRUCT drz_struct;
    
      memset(&drz_struct, 0, sizeof(RESZ_DRZ_STRUCT));
    
      drz_struct.image_src = RESZ_SOURCE_IBW3;
      drz_struct.auto_restart = KAL_TRUE;
      drz_struct.int_en = KAL_FALSE;
      drz_struct.src_width = capture_para->barcode_image_width;
      drz_struct.src_height = capture_para->barcode_image_height;      
      drz_struct.tar_width = capture_para->barcode_image_width;
      drz_struct.tar_height = capture_para->barcode_image_height;
    
      RESZ_DRZConfig(&drz_struct);
    }
    
    /* config Y2R1 */
    {
      SET_IMGPROC_Y2R1_SRC(IMGPROC_Y2R1_IO_DRZ_TO_Y2R1 |
                           IMGPROC_Y2R1_IO_Y2R1_TO_IBW1);
    }
    
    /* config IBW1 */
    {
      IMGDMA_IBW1_STRUCT ibw1_struct;
      
      memset(&ibw1_struct, 0, sizeof(IMGDMA_IBW1_STRUCT));
      
      ibw1_struct.int_enable = KAL_FALSE;
      ibw1_struct.output_format = IMGDMA_IBW1_OUTPUT_TYPE_RGB565;
      ibw1_struct.base1_addr = (kal_uint32)(capture_para->barcode_buffer_address);
      ibw1_struct.base2_addr = (kal_uint32)(capture_para->barcode_buffer_address);
      ibw1_struct.width = capture_para->barcode_image_width ;
      ibw1_struct.height = capture_para->barcode_image_height ;
      ibw1_struct.lcd_trigger = KAL_FALSE;
      ibw1_struct.auto_restart = KAL_TRUE;
      ibw1_struct.dc_couple = KAL_FALSE; 
      ibw1_struct.pan = KAL_FALSE; 
      ibw1_struct.pitch_enable = KAL_FALSE;
      ibw1_struct.alpha = 0;
      
      IMGDMA_IBW1Config(&ibw1_struct);
   }
  
   /*enable all HW module*/
   //preview
   ENABLE_IRT1();  
   START_IBW2();    
   ENABLE_IMGPROC_HW_IPP();
   ENABLE_IPP_Y2R0();                              
   ENABLE_PRZ();                     
   ENABLE_CRZ();                     
   //thumbnail
   ENABLE_Y2R1();
   ENABLE_IMGPROC_HW_Y2R1();
   START_DRZ();
   START_IBW1();

   return 0;
}   /* config_camera_capture_barcode_data_path_6238_series() */

volatile kal_bool ibw4_complete_flag=KAL_FALSE;
volatile kal_bool wait_ibw4_complete=KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  get_barcode_image_6238_series
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void get_barcode_image_6238_series(void)
{  
    //????? necessary  
}//get_barcode_image_6238_series
/*****************************************************************************
 * FUNCTION
 *  close_camera_capture_barcode_data_path_6238_series
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void close_camera_capture_barcode_data_path_6238_series(void)
{
   /*camera preview*/
   /*reset video encode write DMA call back function*/
   vid_enc_w_cb = NULL;      
   /*disable all HW module*/
   RESET_CRZ();    
   STOP_OVL();    
   STOP_IMGDMA_VIDEO_ENCODE();    
   RESET_PRZ;       
   STOP_IBW2();    
   DISABLE_IRT1();  
   DISABLE_IMGPROC_HW_IPP();
   DISABLE_IPP_Y2R0();   
   /*thumbnail*/
   DISABLE_Y2R1();
   STOP_DRZ();
   STOP_IBW1();
    
}   /* close_camera_capture_barcode_data_path_6238_series() */

/*****************************************************************************
 * FUNCTION
 *  mpeg4_vid_enc_w_cb
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mpeg4_vid_enc_w_cb(void)
{
    #ifdef TV_OUT_SUPPORT
    if (tv_output_owner == TV_OUT_OWNER_VID_DMA_W)
    {
        if (tv_out_current_fb == 0)
                tv_fb_update(TV_OUT_OWNER_VID_DMA_W, video_encode_config_data.tv_output_buffer1_address);
        else
            tv_fb_update(TV_OUT_OWNER_VID_DMA_W, video_encode_config_data.tv_output_buffer2_address);
        tv_out_current_fb++;
        tv_out_current_fb &= 0x01;
    }
    #endif/*#ifdef TV_OUT_SUPPORT */
}   /* mpeg4_vid_enc_w_cb() */


kal_uint8 config_camera_usbvideo_jpeg_data_path_6238_series(
  MMDI_SCENERIO_ID scenario_id,
  camera_capture_jpeg_data_path_struct *capture_para)
{
    kal_uint8 thumbnail_ratio_w, thumbnail_ratio_h;    

   /*check onwer id*/
    if (current_image_data_path_owner != scenario_id)
        ASSERT(0);
    if (scenario_id != SCENARIO_USBVIDEO_CAPTURE_JPEG_ID)
        ASSERT(0);   
        
    intmem_init((kal_uint32*) capture_para->intmem_start_address, capture_para->intmem_size);
    extmem_init((kal_uint32*) capture_para->extmem_start_address, capture_para->extmem_size);

    {            
       /* config CRZ */      
       RESZ_CRZ_STRUCT crz_struct;
     
       memset(&crz_struct, 0, sizeof(RESZ_CRZ_STRUCT));
       
       crz_struct.image_src = RESZ_SOURCE_ISP;            
       crz_struct.output_to_OVL = KAL_TRUE;
       crz_struct.output_to_IPP1 = KAL_FALSE;            
       crz_struct.output_to_Y2R1 = KAL_FALSE;      
       crz_struct.dedicate_memory = KAL_TRUE;
       crz_struct.work_mem_line = 4; 
       crz_struct.work_mem_addr = 0x40000000;            
       crz_struct.continous = KAL_FALSE;          
       crz_struct.int_en = KAL_FALSE;      
       crz_struct.src_width = capture_para->image_src_width;
       crz_struct.src_height = capture_para->image_src_height;      
       crz_struct.tar_width = capture_para->image_capture_width;
       crz_struct.tar_height = capture_para->image_capture_height;            
       crz_struct.lbmax = (2048 / crz_struct.tar_width) * 6;
       
       RESZ_CRZConfig(&crz_struct);            
    }  
    
    {
      /* config OVL */
      IMGDMA_OVL_STRUCT ovl_struct;
      
      memset(&ovl_struct, 0, sizeof(IMGDMA_OVL_STRUCT));
      
      ovl_struct.int_en = KAL_FALSE;      
      ovl_struct.restart = KAL_FALSE;
      ovl_struct.pixel_engine = PIXEL_ENGINE_CRZ;
      
      ovl_struct.ouput_jpeg = KAL_TRUE;
      ovl_struct.ouput_drz = KAL_FALSE;
      ovl_struct.output_vdoenc = KAL_FALSE;
      ovl_struct.ouput_y2r0 = KAL_FALSE;            
      ovl_struct.ouput_prz = KAL_FALSE;      
      ovl_struct.overlay_frame_mode = KAL_FALSE;                  
      IMGDMA_OVLConfig(&ovl_struct);
    }
        
     /*JPEG encode*/
     {
        IMGDMA_JPEG_DMA_STRUCT jpeg_dma_struct;
        
        memset(&jpeg_dma_struct, 0, sizeof(IMGDMA_JPEG_DMA_STRUCT));
        if (capture_para->snapshot_number > 1)
           jpeg_dma_struct.restart = KAL_TRUE;
        else
           jpeg_dma_struct.restart = KAL_FALSE;
           
        jpeg_dma_struct.int_enable = KAL_FALSE;
        
        jpeg_dma_struct.target_width = capture_para->image_capture_width;
        jpeg_dma_struct.target_height = capture_para->image_capture_height;
        
        jpeg_dma_struct.jpeg_file_buffer_address = IMGDMA_JPEGDMAGetWorkingMem(KAL_FALSE,
                                                   capture_para->jpeg_yuv_mode,
                                                   capture_para->image_capture_width);
        
        /* YUV420, YUV422 or Gray mode */
        switch (capture_para->jpeg_yuv_mode)
        {
        case JPEG_FORMAT_GRAY:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_GRAY;
          break;
          
        case JPEG_FORMAT_YUV422:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV422;
          break;
          
        case JPEG_FORMAT_YUV420:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV420;
          break;
          
        case JPEG_FORMAT_YUV411:
          jpeg_dma_struct.jpeg_yuv_mode = IMGDMA_JPEG_FORMAT_YUV411;
          break;
          
        default:
          ASSERT(0);
          break;
        }
        
        IMGDMA_JPEGDMAConfig(&jpeg_dma_struct);
     }        
    
   /*enable all HW module*/      
   //START_OVL();                   
   ENABLE_CRZ();    
   START_IMGDMA_JPEG();   
    
   /*XXXXX wait JPEG codec */    
   config_jpeg_usbvideo_path(capture_para);
   return 0;
    
}	  
#endif
