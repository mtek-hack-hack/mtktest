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
 *   img_comm_6238_sw_block_filter.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "drv_comm.h"

#if defined(DRV_IDP_6238_SERIES)

#include "imgproc.h"
#include "kal_non_specific_general_types.h"

extern void read_image(ipp_effect_struct * const ipp_para);
extern void write_image(ipp_effect_struct * const ipp_para);
extern void mask_norm();
extern kal_uint8 round(double src);
extern void linear_lpf(ipp_effect_struct * const ipp_para);
extern void linear_hpf(ipp_effect_struct * const ipp_para);
extern void linear_hpf_scale(ipp_effect_struct * const ipp_para);
extern kal_uint8 conv();
extern kal_uint8 conv_scl();
extern void init_a();
extern void init_mask();
extern void blur7(ipp_effect_struct * const ipp_para);
extern void blur5(ipp_effect_struct * const ipp_para);
extern void rankflt(kal_int32 order, ipp_effect_struct * const ipp_para);
extern kal_uint8 selectflt(kal_int32 order);
extern void unsharp(ipp_effect_struct * const ipp_para);
extern kal_uint8 conv_unsharp();

static kal_int32 ipp_round;
static kal_int32 ipp_mask11;
static kal_int32 ipp_mask12;
static kal_int32 ipp_mask13;
static kal_int32 ipp_mask21;
static kal_int32 ipp_mask22;
static kal_int32 ipp_mask23;
static kal_int32 ipp_mask31;
static kal_int32 ipp_mask32;
static kal_int32 ipp_mask33;
static kal_int32 ipp_mask_scale;
static kal_int32 ipp_dummy; 

static kal_uint8 rin[4095][4095];
static kal_uint8 gin[4095][4095];
static kal_uint8 bin[4095][4095];
static kal_uint8 rout[4095][4095];
static kal_uint8 gout[4095][4095];
static kal_uint8 bout[4095][4095];

static kal_int32 a[3][3];
static kal_int32 mask[3][3];
static kal_int32 arrin[9];  
static kal_int32 factor;  

int
sw_block_filter_6238_series(ipp_effect_struct *ipp_para)
{
  ipp_round = 1;
	ipp_mask11 = 1;
	ipp_mask12 = 2;
	ipp_mask13 = 1;
	ipp_mask21 = 2;
	ipp_mask22 = 4;
	ipp_mask23 = 2;
	ipp_mask31 = 1;
	ipp_mask32 = 2;
	ipp_mask33 = 1;
	ipp_mask_scale = 1;
	ipp_dummy = 0;
  
  // read image 2 rgb array
  read_image(ipp_para);
  
	// 2's complement to signed integer
	mask_norm();
  
  // filtering effect
  switch (ipp_para->filter_mode)
  {
  case IPP_FILTER_LINEAR_LP: // Linear LPF
    linear_lpf(ipp_para);
    break;
    
  case IPP_FILTER_LINEAR_HP: // Linear HPF
    linear_hpf(ipp_para);
    break;
    
  case IPP_FILTER_LINEAR_HP_SCALE_DOWN: // Linear HPF with scale down
    linear_hpf_scale(ipp_para);
    break;
    
  case IPP_FILTER_BLUR: // 5x5 blur effect
    blur5(ipp_para);
    break;
    
  case IPP_FILTER_MORE_BLUR:    // 7x7 blur effect
    blur7(ipp_para);
    break;
    
  case IPP_FILTER_UNSHARP:    // 'Un-sharp' effect enable (minus low-freq)
    unsharp(ipp_para);
    break;
    
  case IPP_FILTER_MAXIMUM_RANKING:    // Max ranking filter (dilation)
    rankflt(0, ipp_para);
    break;
    
  case IPP_FILTER_MEDIAN_RANKING:    // Med ranking filter
    rankflt(4, ipp_para);
    break;
    
  case IPP_FILTER_MINIMUM_RANKING:    // Min ranking filter (erosion)
    rankflt(8, ipp_para);
    break;
    
  default:
    ASSERT(0 && "Mask mode error!\n");        
    break;
  }
    
  write_image(ipp_para);
  
  return 1;
}  

void
read_image(ipp_effect_struct * const ipp_para)
{
  kal_int32 i, j;
	kal_int32 src1, src2;
  
  if (IPP_COLOR_RGB888 == ipp_para->src_color_mode)  
  {
    kal_uint8 *addr = (kal_uint8 *)(ipp_para->src_address);
    
    for (i = 0; i < ipp_para->src_height; ++i)
    {
      for (j = 0; j < ipp_para->src_width; ++j)
      {
        bin[i][j] = *addr;
        ++addr;
        
        gin[i][j] = *addr;
        ++addr;
        
        rin[i][j] = *addr;
        ++addr;
      }
    }
  }
  else
  {
    for (i = 0; i < ipp_para->src_height; ++i)
    {
      for (j = 0; j < ipp_para->src_width; ++j)
      {
        src1 = *((kal_uint32 *)(ipp_para->src_address));
        ++((kal_uint32 *)(ipp_para->src_address));
        
        src2 = *((kal_uint32 *)(ipp_para->src_address));
        ++((kal_uint32 *)(ipp_para->src_address));
        
        rin[i][j] = src2 & 0xf8;
        gin[i][j] = (((src2 & 0x07) << 3) + ((src1 & 0xe0) >> 5)) << 2;
        bin[i][j] = (src1 & 0x1f) << 3;
      }
    }
  }
}

void
write_image(ipp_effect_struct * const ipp_para)
{
  kal_int32 i, j;
  kal_int32 src1, src2;
  
  if (IPP_COLOR_RGB888 == ipp_para->dest_color_mode)  
  {
    kal_uint8 *addr = (kal_uint8 *)(ipp_para->dest_address);
    
    for (i = 0; i < ipp_para->src_height; ++i)
    {
      for (j = 0; j < ipp_para->src_width; ++j)
      {
        *addr = bout[i][j];
        ++addr;
        
        *addr = gout[i][j];
        ++addr;
        
        *addr = rout[i][j];
        ++addr;
      }
    }
  }
  else
  {
    for (i = 0; i < ipp_para->src_height; ++i)
    {
      for (j = 0; j < ipp_para->src_width; ++j)
      {
        src1 = (int)((gout[i][j] & 0x1c) << 3) + (bout[i][j] >> 3);
        src2 = (int)(rout[i][j] & 0xf8) + ((gout[i][j] & 0xe0) >> 5);
        
        *((kal_uint32 *)(ipp_para->dest_address)) = src1;
        ++((kal_uint32 *)(ipp_para->dest_address));
        
        *((kal_uint32 *)(ipp_para->dest_address)) = src2;
        ++((kal_uint32 *)(ipp_para->dest_address));
      }
    }
  }
}

void mask_norm()
{
  ipp_mask11 = (ipp_mask11>15)? (ipp_mask11-32):ipp_mask11;
  ipp_mask12 = (ipp_mask12>15)? (ipp_mask12-32):ipp_mask12;
  ipp_mask13 = (ipp_mask13>15)? (ipp_mask13-32):ipp_mask13;
  ipp_mask21 = (ipp_mask21>15)? (ipp_mask21-32):ipp_mask21;
  ipp_mask22 = (ipp_mask22>15)? (ipp_mask22-32):ipp_mask22;
  ipp_mask23 = (ipp_mask23>15)? (ipp_mask23-32):ipp_mask23;
  ipp_mask31 = (ipp_mask31>15)? (ipp_mask31-32):ipp_mask31;
  ipp_mask32 = (ipp_mask32>15)? (ipp_mask32-32):ipp_mask32;
  ipp_mask33 = (ipp_mask33>15)? (ipp_mask33-32):ipp_mask33;
}

void
linear_lpf(ipp_effect_struct * const ipp_para)
{
  kal_int32 i,j;
  double tmp1, tmp2, tmp3;
  
	for (i = 0; i < ipp_para->src_height; i++) 
	{
		for (j = 0; j < ipp_para->src_width; j++) 
		{
			if(i==0 && j==0) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i+1][j] * ipp_mask32 + 
				                 rin[i][j+1] * ipp_mask23 + 
				                 rin[i+1][j+1] * ipp_mask33) / 
                (ipp_mask22+ipp_mask32+ipp_mask23+ipp_mask33));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i+1][j] * ipp_mask32 + 
				                 gin[i][j+1] * ipp_mask23 + 
				                 gin[i+1][j+1] * ipp_mask33) / 
                (ipp_mask22+ipp_mask32+ipp_mask23+ipp_mask33));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i+1][j] * ipp_mask32 + 
				                 bin[i][j+1] * ipp_mask23 + 
				                 bin[i+1][j+1] * ipp_mask33) / 
                (ipp_mask22+ipp_mask32+ipp_mask23+ipp_mask33));
			} 
			else if(i==0 && j==ipp_para->src_width-1) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i+1][j] * ipp_mask32 +  
				                 rin[i][j-1] * ipp_mask21 + 
				                 rin[i+1][j-1] * ipp_mask31) / 
                (ipp_mask22+ipp_mask32+ipp_mask21+ipp_mask31));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i+1][j] * ipp_mask32 + 
				                 gin[i][j-1] * ipp_mask21 + 
				                 gin[i+1][j-1] * ipp_mask31) / 
                (ipp_mask22+ipp_mask32+ipp_mask21+ipp_mask31));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i+1][j] * ipp_mask32 + 
				                 bin[i][j-1] * ipp_mask21 + 
				                 bin[i+1][j-1] * ipp_mask31) /(ipp_mask22+ipp_mask32+ipp_mask21+ipp_mask31));
			} 
			else if(i==0) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i+1][j] * ipp_mask32 + 
				                 rin[i][j-1] * ipp_mask21 + 
				                 rin[i+1][j-1] * ipp_mask31 + 
                         rin[i][j+1] * ipp_mask23 + 
                         rin[i+1][j+1] * ipp_mask33) /
                (ipp_mask22+ipp_mask32+ipp_mask21+
                 ipp_mask31+ipp_mask23+ipp_mask33));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i+1][j] * ipp_mask32 + 
				                 gin[i][j-1] * ipp_mask21 + 
				                 gin[i+1][j-1] * ipp_mask31 + 
                         gin[i][j+1] * ipp_mask23 + 
                         gin[i+1][j+1] * ipp_mask33) / 
                (ipp_mask22+ipp_mask32+ipp_mask21+
                 ipp_mask31+ipp_mask23+ipp_mask33)); 
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i+1][j] * ipp_mask32 + 
				                 bin[i][j-1] * ipp_mask21 + 
				                 bin[i+1][j-1] * ipp_mask31 + 
                         bin[i][j+1] * ipp_mask23 + 
                         bin[i+1][j+1] * ipp_mask33) / 
                (ipp_mask22+ipp_mask32+ipp_mask21+
                 ipp_mask31+ipp_mask23+ipp_mask33));
			} 
			else if(i==ipp_para->src_height-1 && j==0) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i-1][j] * ipp_mask12 + 
				                 rin[i][j+1] * ipp_mask23 + 
				                 rin[i-1][j+1] * ipp_mask13) / 
                (ipp_mask22+ipp_mask12+ipp_mask23+ipp_mask13));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i-1][j] * ipp_mask12 + 
				                 gin[i][j+1] * ipp_mask23 + 
				                 gin[i-1][j+1] * ipp_mask13) /
                (ipp_mask22+ipp_mask12+ipp_mask23+ipp_mask13));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i-1][j] * ipp_mask12 + 
				                 bin[i][j+1] * ipp_mask23 + 
				                 bin[i-1][j+1] * ipp_mask13) /
                (ipp_mask22+ipp_mask12+ipp_mask23+ipp_mask13));
			} 
			else if(i==ipp_para->src_height-1 && j==ipp_para->src_width-1) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i-1][j] * ipp_mask12 + 
				                 rin[i][j-1] * ipp_mask21 + 
				                 rin[i-1][j-1] * ipp_mask11) /
                (ipp_mask22+ipp_mask12+ipp_mask21+ipp_mask11));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i-1][j] * ipp_mask12 + 
				                 gin[i][j-1] * ipp_mask21 + 
				                 gin[i-1][j-1] * ipp_mask11) /
                (ipp_mask22+ipp_mask12+ipp_mask21+ipp_mask11));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i-1][j] * ipp_mask12 + 
				                 bin[i][j-1] * ipp_mask21 + 
				                 bin[i-1][j-1] * ipp_mask11) / 
                (ipp_mask22+ipp_mask12+ipp_mask21+ipp_mask11));
			} 
			else if(i==ipp_para->src_height-1) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i-1][j] * ipp_mask12 + 
				                 rin[i][j-1] * ipp_mask21 + 
				                 rin[i-1][j-1] * ipp_mask11 + 
                         rin[i][j+1] * ipp_mask23 + 
                         rin[i-1][j+1] * ipp_mask13) /
                (ipp_mask22+ipp_mask12+ipp_mask21+
                 ipp_mask11+ipp_mask23+ipp_mask13));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i-1][j] * ipp_mask12 + 
				                 gin[i][j-1] * ipp_mask21 + 
				                 gin[i-1][j-1] * ipp_mask11 + 
                         gin[i][j+1] * ipp_mask23 + 
                         gin[i-1][j+1] * ipp_mask13) / 
                (ipp_mask22+ipp_mask12+ipp_mask21+
                 ipp_mask11+ipp_mask23+ipp_mask13));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i-1][j] * ipp_mask12 + 
				                 bin[i][j-1] * ipp_mask21 + 
				                 bin[i-1][j-1] * ipp_mask11 + 
                         bin[i][j+1] * ipp_mask23 + 
                         bin[i-1][j+1] * ipp_mask13) / 
                (ipp_mask22+ipp_mask12+ipp_mask21+
                 ipp_mask11+ipp_mask23+ipp_mask13));
			} 
			else if(j==0) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i-1][j] * ipp_mask12 + 
				                 rin[i+1][j] * ipp_mask32 + 
				                 rin[i][j+1] * ipp_mask23 + 
                         rin[i-1][j+1] * ipp_mask13 + 
                         rin[i+1][j+1] * ipp_mask33)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask23+ipp_mask13+ipp_mask33));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i-1][j] * ipp_mask12 + 
				                 gin[i+1][j] * ipp_mask32 + 
				                 gin[i][j+1] * ipp_mask23 + 
                         gin[i-1][j+1] * ipp_mask13 + 
                         gin[i+1][j+1] * ipp_mask33)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask23+ipp_mask13+ipp_mask33));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i-1][j] * ipp_mask12 + 
				                 bin[i+1][j] * ipp_mask32 + 
				                 bin[i][j+1] * ipp_mask23 + 
                         bin[i-1][j+1] * ipp_mask13 + 
                         bin[i+1][j+1] * ipp_mask33)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask23+ipp_mask13+ipp_mask33));
			} 
			else if(j==ipp_para->src_width-1) 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i-1][j] * ipp_mask12 + 
				                 rin[i+1][j] * ipp_mask32 + 
				                 rin[i][j-1] * ipp_mask21 + 
                         rin[i-1][j-1] * ipp_mask11 + 
                         rin[i+1][j-1] * ipp_mask31)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask21+ipp_mask11+ipp_mask31));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i-1][j] * ipp_mask12 + 
				                 gin[i+1][j] * ipp_mask32 + 
				                 gin[i][j-1] * ipp_mask21 + 
                         gin[i-1][j-1] * ipp_mask11 + 
                         gin[i+1][j-1] * ipp_mask31)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask21+ipp_mask11+ipp_mask31));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i-1][j] * ipp_mask12 + 
				                 bin[i+1][j] * ipp_mask32 + 
				                 bin[i][j-1] * ipp_mask21 + 
                         bin[i-1][j-1] * ipp_mask11 + 
                         bin[i+1][j-1] * ipp_mask31)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask21+ipp_mask11+ipp_mask31));
			} 
			else 
			{
				tmp1 = ((double)(rin[i][j] * ipp_mask22 + 
				                 rin[i-1][j] * ipp_mask12 + 
				                 rin[i+1][j] * ipp_mask32 + 
				                 rin[i][j-1] * ipp_mask21 + 
                         rin[i-1][j-1] * ipp_mask11 + 
                         rin[i+1][j-1] * ipp_mask31 + 
                         rin[i][j+1] * ipp_mask23 + 
                         rin[i-1][j+1] * ipp_mask13 + 
                         rin[i+1][j+1] * ipp_mask33)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask21+ipp_mask11+ipp_mask31+
                 ipp_mask23+ipp_mask13+ipp_mask33));
				tmp2 = ((double)(gin[i][j] * ipp_mask22 + 
				                 gin[i-1][j] * ipp_mask12 + 
				                 gin[i+1][j] * ipp_mask32 + 
				                 gin[i][j-1] * ipp_mask21 + 
                         gin[i-1][j-1] * ipp_mask11 + 
                         gin[i+1][j-1] * ipp_mask31 + 
                         gin[i][j+1] * ipp_mask23 + 
                         gin[i-1][j+1] * ipp_mask13 + 
                         gin[i+1][j+1] * ipp_mask33)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask21+ipp_mask11+ipp_mask31+
                 ipp_mask23+ipp_mask13+ipp_mask33));
				tmp3 = ((double)(bin[i][j] * ipp_mask22 + 
				                 bin[i-1][j] * ipp_mask12 + 
				                 bin[i+1][j] * ipp_mask32 + 
				                 bin[i][j-1] * ipp_mask21 + 
                         bin[i-1][j-1] * ipp_mask11 + 
                         bin[i+1][j-1] * ipp_mask31 + 
                         bin[i][j+1] * ipp_mask23 + 
                         bin[i-1][j+1] * ipp_mask13 + 
                         bin[i+1][j+1] * ipp_mask33)/
                (ipp_mask22+ipp_mask12+ipp_mask32+
                 ipp_mask21+ipp_mask11+ipp_mask31+
                 ipp_mask23+ipp_mask13+ipp_mask33));
			}
			
			// rounding
      rout[i][j] = round(tmp1);
      gout[i][j] = round(tmp2);
      bout[i][j] = round(tmp3);
		}
	}
}

kal_uint8 round(double src)
{
	kal_int32 dig;
	double res;
	
	dig = (int) src;
	
	if(ipp_round)
    if((src - (double)dig) >= 0.5)
      dig += 1;
    
	res = (int) dig;	
	res = (res>255)?255:res;
	return (kal_uint8)res;
}

void linear_hpf(ipp_effect_struct * const ipp_para)
{
  kal_int32 i,j;
    
  init_mask();
    
	for(i = 0; i < ipp_para->src_height; i++) 
	{
		for(j = 0; j < ipp_para->src_width; j++) 
		{
			if(i==0 && j==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; 
				a[1][2] = rin[i][j+1]; a[2][2] = rin[i+1][j+1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; 
				a[1][2] = gin[i][j+1]; a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; 
				a[1][2] = bin[i][j+1]; a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv();
			} 
			else if(i==0 && j==ipp_para->src_width-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; 
				a[1][0] = rin[i][j-1]; a[2][0] = rin[i+1][j-1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; 
				a[1][0] = gin[i][j-1]; a[2][0] = gin[i+1][j-1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; 
				a[1][0] = bin[i][j-1]; a[2][0] = bin[i+1][j-1];
				bout[i][j] = conv();
			} 
			else if(i==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; 
				a[1][0] = rin[i][j-1]; a[2][0] = rin[i+1][j-1]; 
				a[1][2] = rin[i][j+1]; a[2][2] = rin[i+1][j+1];
				rout[i][j] =conv() ;
				init_a();
				a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; 
				a[1][0] = gin[i][j-1]; a[2][0] = gin[i+1][j-1]; 
				a[1][2] = gin[i][j+1]; a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv(); 
				init_a();
				a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; 
				a[1][0] = bin[i][j-1]; a[2][0] = bin[i+1][j-1]; 
				a[1][2] = bin[i][j+1]; a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv();
			} 
			else if(i==ipp_para->src_height-1 && j==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1];
				bout[i][j] = conv();
			} 
			else if(i==ipp_para->src_height-1 && j==ipp_para->src_width-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1];
				bout[i][j] = conv();
			} 
			else if(i==ipp_para->src_height-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1]; 
				a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1]; 
				a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1]; 
				a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1];
				bout[i][j] = conv();
			} 
			else if(j==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[2][1] = rin[i+1][j]; a[1][2] = rin[i][j+1]; 
				a[0][2] = rin[i-1][j+1]; a[2][2] = rin[i+1][j+1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[2][1] = gin[i+1][j]; a[1][2] = gin[i][j+1]; 
				a[0][2] = gin[i-1][j+1]; a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[2][1] = bin[i+1][j]; a[1][2] = bin[i][j+1]; 
				a[0][2] = bin[i-1][j+1]; a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv();
			} 
			else if(j==ipp_para->src_width-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; 
				a[0][0] = rin[i-1][j-1]; a[2][0] = rin[i+1][j-1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; 
				a[0][0] = gin[i-1][j-1]; a[2][0] = gin[i+1][j-1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; 
				a[0][0] = bin[i-1][j-1]; a[2][0] = bin[i+1][j-1];
				bout[i][j] = conv();
			} 
			else 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; 
				a[0][0] = rin[i-1][j-1]; a[2][0] = rin[i+1][j-1]; 
				a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
				a[2][2] = rin[i+1][j+1];
				rout[i][j] = conv();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; 
				a[0][0] = gin[i-1][j-1]; a[2][0] = gin[i+1][j-1]; 
				a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1]; 
				a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; 
				a[0][0] = bin[i-1][j-1]; a[2][0] = bin[i+1][j-1]; 
				a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1]; 
				a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv();
			}
		}
	}    
}

kal_uint8 conv()
{
	kal_int32 sum;
	kal_int32 i, j;
	
	sum = 0;
	// convolution
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			sum += (a[i][j] * mask[i][j]);
		
  // clipping
	if(sum <= 0)    sum = 0;	
	else if(sum > 255)  sum = 255;
		    	
	return (kal_uint8)sum;
}

void init_a()
{
	kal_int32 i, j;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++) 
			a[i][j] = 0;
}

void init_mask()
{
  mask[0][0] = ipp_mask11;
  mask[0][1] = ipp_mask12;
  mask[0][2] = ipp_mask13;
  mask[1][0] = ipp_mask21;
  mask[1][1] = ipp_mask22;
  mask[1][2] = ipp_mask23;
  mask[2][0] = ipp_mask31;
  mask[2][1] = ipp_mask32;
  mask[2][2] = ipp_mask33;
}

void linear_hpf_scale(ipp_effect_struct * const ipp_para)
{
  kal_int32 i,j;
    
  init_mask();
    
	for(i = 0; i < ipp_para->src_height; i++) 
	{
		for(j = 0; j < ipp_para->src_width; j++) 
		{
			if(i==0 && j==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; 
				a[1][2] = rin[i][j+1]; a[2][2] = rin[i+1][j+1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; 
				a[1][2] = gin[i][j+1]; a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; 
				a[1][2] = bin[i][j+1]; a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv_scl();
			} 
			else if(i==0 && j==ipp_para->src_width-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; 
				a[1][0] = rin[i][j-1]; a[2][0] = rin[i+1][j-1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; 
				a[1][0] = gin[i][j-1]; a[2][0] = gin[i+1][j-1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; 
				a[1][0] = bin[i][j-1]; a[2][0] = bin[i+1][j-1];
				bout[i][j] = conv_scl();
			} 
			else if(i==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; 
				a[1][0] = rin[i][j-1]; a[2][0] = rin[i+1][j-1]; 
				a[1][2] = rin[i][j+1]; a[2][2] = rin[i+1][j+1];
				rout[i][j] = round(conv_scl()) ;
				init_a();
				a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; 
				a[1][0] = gin[i][j-1]; a[2][0] = gin[i+1][j-1]; 
				a[1][2] = gin[i][j+1]; a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv_scl(); 
				init_a();
				a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; 
				a[1][0] = bin[i][j-1]; a[2][0] = bin[i+1][j-1]; 
				a[1][2] = bin[i][j+1]; a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv_scl();
			} 
			else if(i==ipp_para->src_height-1 && j==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1];
				bout[i][j] = conv_scl();
			} 
			else if(i==ipp_para->src_height-1 && j==ipp_para->src_width-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1];
				bout[i][j] = conv_scl();
			} 
			else if(i==ipp_para->src_height-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1]; 
				a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1]; 
				a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1]; 
				a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1];
				bout[i][j] = conv_scl();
			} 
			else if(j==0) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[2][1] = rin[i+1][j]; a[1][2] = rin[i][j+1]; 
				a[0][2] = rin[i-1][j+1]; a[2][2] = rin[i+1][j+1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[2][1] = gin[i+1][j]; a[1][2] = gin[i][j+1]; 
				a[0][2] = gin[i-1][j+1]; a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[2][1] = bin[i+1][j]; a[1][2] = bin[i][j+1]; 
				a[0][2] = bin[i-1][j+1]; a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv_scl();
			} 
			else if(j==ipp_para->src_width-1) 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; 
				a[0][0] = rin[i-1][j-1]; a[2][0] = rin[i+1][j-1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; 
				a[0][0] = gin[i-1][j-1]; a[2][0] = gin[i+1][j-1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; 
				a[0][0] = bin[i-1][j-1]; a[2][0] = bin[i+1][j-1];
				bout[i][j] = conv_scl();
			} 
			else 
			{
				init_a();
				a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; 
				a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; 
				a[0][0] = rin[i-1][j-1]; a[2][0] = rin[i+1][j-1]; 
				a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
				a[2][2] = rin[i+1][j+1];
				rout[i][j] = conv_scl();
				init_a();
				a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; 
				a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; 
				a[0][0] = gin[i-1][j-1]; a[2][0] = gin[i+1][j-1]; 
				a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1]; 
				a[2][2] = gin[i+1][j+1];
				gout[i][j] = conv_scl();
				init_a();
				a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; 
				a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; 
				a[0][0] = bin[i-1][j-1]; a[2][0] = bin[i+1][j-1]; 
				a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1]; 
				a[2][2] = bin[i+1][j+1];
				bout[i][j] = conv_scl();
			}
		}
	}    
}

kal_uint8 conv_scl()
{
	double sum;
	double tmp1;
	kal_int32 i, j;
	
	sum = 0;
	// convolution
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			sum += (a[i][j] * mask[i][j]);
	
	sum = sum / ipp_mask_scale;
	
	if(ipp_round)
	{
    tmp1 = (int)sum;
    if((sum - tmp1) >= 0.5)
      sum += 1;
	}
		
	// clipping
	if(sum <= 0)    sum = 0;	
	else if(sum > 255)  sum = 255;
		    	
	return (kal_uint8)sum;
}

void blur5(ipp_effect_struct * const ipp_para)
{
  kal_int32 i,j,m,n,div;
  double tmp1, tmp2, tmp3;
    
	for(i = 0; i < ipp_para->src_height; i++) 
	{
		for(j = 0; j < ipp_para->src_width; j++) 
		{
			tmp1 = 0;
			tmp2 = 0;
			tmp3 = 0;
			if(i==0 && j==0) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i+m][j+n];
						tmp2 = tmp2 + gin[i+m][j+n];
						tmp3 = tmp3 + bin[i+m][j+n];
						div = 9;
					}
				}
			} 
			else if(i==0 && j==(ipp_para->src_width-1)) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i+m][j-n];
						tmp2 = tmp2 + gin[i+m][j-n];
						tmp3 = tmp3 + bin[i+m][j-n];
						div = 9;
					}
				}
			} 
			else if(i==0 && j==1) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i+m][j+n-1];
						tmp2 = tmp2 + gin[i+m][j+n-1];
						tmp3 = tmp3 + bin[i+m][j+n-1];
						div = 12;
					}
				}
			} 
			else if(i==0 && j==(ipp_para->src_width-2)) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i+m][j+1-n];
						tmp2 = tmp2 + gin[i+m][j+1-n];
						tmp3 = tmp3 + bin[i+m][j+1-n];
						div = 12;
					}
				}
			} 
			else if(i==0) 
			{
				for(m = 0; m <= 2; m++)
				{
					for(n = 0; n <= 4; n++) 
					{  
						tmp1 = tmp1 + rin[i+m][j+n-2];
						tmp2 = tmp2 + gin[i+m][j+n-2];
						tmp3 = tmp3 + bin[i+m][j+n-2];
						div = 15;
					}
				}
			} 
			else if(i==(ipp_para->src_height-1) && j==0) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i-m][j+n];
						tmp2 = tmp2 + gin[i-m][j+n];
						tmp3 = tmp3 + bin[i-m][j+n];
						div = 9;
					}
				}
			} 
			else if(i==(ipp_para->src_height-1) && j==(ipp_para->src_width-1)) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i-m][j-n];
						tmp2 = tmp2 + gin[i-m][j-n];
						tmp3 = tmp3 + bin[i-m][j-n];
						div = 9;
					}
				}
			} 
			else if(i==(ipp_para->src_height-1) && j==1) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i-m][j+n-1];
						tmp2 = tmp2 + gin[i-m][j+n-1];
						tmp3 = tmp3 + bin[i-m][j+n-1];
						div = 12;
					}
				}
			} 
			else if(i==(ipp_para->src_height-1) && j==(ipp_para->src_width-2)) 
			{
				for(m = 0; m <= 2; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i-m][j-n+1];
						tmp2 = tmp2 + gin[i-m][j-n+1];
						tmp3 = tmp3 + bin[i-m][j-n+1];
						div = 12;
					}
				}
			} 
			else if(i==(ipp_para->src_height-1)) 
			{
				for(m = 0; m <= 2; m++)
				{
					for(n = 0; n <= 4; n++) 
					{  
						tmp1 = tmp1 + rin[i-m][j+n-2];
						tmp2 = tmp2 + gin[i-m][j+n-2];
						tmp3 = tmp3 + bin[i-m][j+n-2];
						div = 15;
					}
				}
			} 
			else if(i==1 && j==0) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-1][j+n];
						tmp2 = tmp2 + gin[i+m-1][j+n];
						tmp3 = tmp3 + bin[i+m-1][j+n];
						div = 12;
					}
				}
			} 
			else if(i==1 && j==(ipp_para->src_width-1)) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-1][j-n];
						tmp2 = tmp2 + gin[i+m-1][j-n];
						tmp3 = tmp3 + bin[i+m-1][j-n];
						div = 12;
					}
				}
			} 
			else if(i==1 && j==1) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-1][j+n-1];
						tmp2 = tmp2 + gin[i+m-1][j+n-1];
						tmp3 = tmp3 + bin[i+m-1][j+n-1];
						div = 16;
					}
				}
			} 
			else if(i==1 && j==(ipp_para->src_width-2)) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-1][j+1-n];
						tmp2 = tmp2 + gin[i+m-1][j+1-n];
						tmp3 = tmp3 + bin[i+m-1][j+1-n];
						div = 16;
					}
				}
			} 
			else if(i==1) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 4; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-1][j+n-2];
						tmp2 = tmp2 + gin[i+m-1][j+n-2];
						tmp3 = tmp3 + bin[i+m-1][j+n-2];
						div = 20;
					}
				}
			} 
			else if(i==(ipp_para->src_height-2) && j==0) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i-m+1][j+n];
						tmp2 = tmp2 + gin[i-m+1][j+n];
						tmp3 = tmp3 + bin[i-m+1][j+n];
						div = 12;
					}
				}
			} 
			else if(i==(ipp_para->src_height-2) && j==(ipp_para->src_width-1)) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i-m+1][j-n];
						tmp2 = tmp2 + gin[i-m+1][j-n];
						tmp3 = tmp3 + bin[i-m+1][j-n];
						div = 12;
					}
				}
			} 
			else if(i==(ipp_para->src_height-2) && j==1) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i-m+1][j+n-1];
						tmp2 = tmp2 + gin[i-m+1][j+n-1];
						tmp3 = tmp3 + bin[i-m+1][j+n-1];
						div = 16;
					}
				}
			} 
			else if(i==(ipp_para->src_height-2) && j==(ipp_para->src_width-2)) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 3; n++) 
					{  
						tmp1 = tmp1 + rin[i-m+1][j+1-n];
						tmp2 = tmp2 + gin[i-m+1][j+1-n];
						tmp3 = tmp3 + bin[i-m+1][j+1-n];
						div = 16;
					}
				}
			} 			
			else if(i==(ipp_para->src_height-2)) 
			{
				for(m = 0; m <= 3; m++) 
				{
					for(n = 0; n <= 4; n++) 
					{  
						tmp1 = tmp1 + rin[i-m+1][j+n-2];
						tmp2 = tmp2 + gin[i-m+1][j+n-2];
						tmp3 = tmp3 + bin[i-m+1][j+n-2];
						div = 20;
					}
				}
			} 
			else if(j==0) 
			{
				for(m = 0; m <= 4; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-2][j+n];
						tmp2 = tmp2 + gin[i+m-2][j+n];
						tmp3 = tmp3 + bin[i+m-2][j+n];
						div = 15;
					}
				}
			} 
			else if(j==(ipp_para->src_width-1)) 
			{
				for(m = 0; m <= 4; m++) 
				{
					for(n = 0; n <= 2; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-2][j-n];
						tmp2 = tmp2 + gin[i+m-2][j-n];
						tmp3 = tmp3 + bin[i+m-2][j-n];
						div = 15;
					}
				}
			} 
			else if(j==1) {
				for(m = 0; m <= 4; m++) 
				{
					for(n = 0; n <= 3; n++)
					{  
						tmp1 = tmp1 + rin[i+m-2][j+n-1];
						tmp2 = tmp2 + gin[i+m-2][j+n-1];
						tmp3 = tmp3 + bin[i+m-2][j+n-1];
						div = 20;
					}
				}
			} 
			else if(j==(ipp_para->src_width-2)) 
			{
				for(m = 0; m <= 4; m++) 
				{
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+1-n];
						tmp2 = tmp2 + gin[i+m-2][j+1-n];
						tmp3 = tmp3 + bin[i+m-2][j+1-n];
						div = 20;
					}
				}
			} 
			else 
			{
				for(m = 0; m <= 4; m++) 
				{
					for(n = 0; n <= 4; n++) 
					{  
						tmp1 = tmp1 + rin[i+m-2][j+n-2];
						tmp2 = tmp2 + gin[i+m-2][j+n-2];
						tmp3 = tmp3 + bin[i+m-2][j+n-2];
						div = 25;
					}
				}
			}
			rout[i][j] = round(tmp1/div);
			gout[i][j] = round(tmp2/div);
			bout[i][j] = round(tmp3/div);
    }
  }
}

void blur7(ipp_effect_struct * const ipp_para)
{
  kal_int32 i,j,m,n,div;
  double tmp1, tmp2, tmp3;

	for(i = 0; i < ipp_para->src_height; i++) {
		for(j = 0; j < ipp_para->src_width; j++) {
			tmp1 = 0;
			tmp2 = 0;
			tmp3 = 0;
			if(i==0 && j==0) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m][j+n];
						tmp2 = tmp2 + gin[i+m][j+n];
						tmp3 = tmp3 + bin[i+m][j+n];
						div = 16;
					}
				}
			} else if(i==0 && j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m][j-n];
						tmp2 = tmp2 + gin[i+m][j-n];
						tmp3 = tmp3 + bin[i+m][j-n];
						div = 16;
					}
				}
			} else if(i==0 && j==1) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m][j+n-1];
						tmp2 = tmp2 + gin[i+m][j+n-1];
						tmp3 = tmp3 + bin[i+m][j+n-1];
						div = 20;
					}
				}
			} else if(i==0 && j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m][j+1-n];
						tmp2 = tmp2 + gin[i+m][j+1-n];
						tmp3 = tmp3 + bin[i+m][j+1-n];
						div = 20;
					}
				}
			} else if(i==0 && j==2) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m][j+n-2];
						tmp2 = tmp2 + gin[i+m][j+n-2];
						tmp3 = tmp3 + bin[i+m][j+n-2];
						div = 24;
					}
				}
			} else if(i==0 && j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m][j+2-n];
						tmp2 = tmp2 + gin[i+m][j+2-n];
						tmp3 = tmp3 + bin[i+m][j+2-n];
						div = 24;
					}
				}
			} else if(i==0) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i+m][j+n-3];
						tmp2 = tmp2 + gin[i+m][j+n-3];
						tmp3 = tmp3 + bin[i+m][j+n-3];
						div = 28;
					}
				}
			} else if(i==(ipp_para->src_height-1) && j==0) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i-m][j+n];
						tmp2 = tmp2 + gin[i-m][j+n];
						tmp3 = tmp3 + bin[i-m][j+n];
						div = 16;
					}
				}
			} else if(i==(ipp_para->src_height-1) && j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i-m][j-n];
						tmp2 = tmp2 + gin[i-m][j-n];
						tmp3 = tmp3 + bin[i-m][j-n];
						div = 16;
					}
				}
			} else if(i==(ipp_para->src_height-1) && j==1) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i-m][j+n-1];
						tmp2 = tmp2 + gin[i-m][j+n-1];
						tmp3 = tmp3 + bin[i-m][j+n-1];
						div = 20;
					}
				}
			} else if(i==(ipp_para->src_height-1) && j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i-m][j-n+1];
						tmp2 = tmp2 + gin[i-m][j-n+1];
						tmp3 = tmp3 + bin[i-m][j-n+1];
						div = 20;
					}
				}
			} else if(i==(ipp_para->src_height-1) && j==2) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i-m][j+n-2];
						tmp2 = tmp2 + gin[i-m][j+n-2];
						tmp3 = tmp3 + bin[i-m][j+n-2];
						div = 24;
					}
				}
			} else if(i==(ipp_para->src_height-1) && j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i-m][j-n+2];
						tmp2 = tmp2 + gin[i-m][j-n+2];
						tmp3 = tmp3 + bin[i-m][j-n+2];
						div = 24;
					}
				}
			} else if(i==(ipp_para->src_height-1)) {
				for(m = 0; m <= 3; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i-m][j+n-3];
						tmp2 = tmp2 + gin[i-m][j+n-3];
						tmp3 = tmp3 + bin[i-m][j+n-3];
						div = 28;
					}
				}
			} else if(i==1 && j==0) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j+n];
						tmp2 = tmp2 + gin[i+m-1][j+n];
						tmp3 = tmp3 + bin[i+m-1][j+n];
						div = 20;
					}
				}
			} else if(i==1 && j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j-n];
						tmp2 = tmp2 + gin[i+m-1][j-n];
						tmp3 = tmp3 + bin[i+m-1][j-n];
						div = 20;
					}
				}
			} else if(i==1 && j==1) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j+n-1];
						tmp2 = tmp2 + gin[i+m-1][j+n-1];
						tmp3 = tmp3 + bin[i+m-1][j+n-1];
						div = 25;
					}
				}
			} else if(i==1 && j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j+1-n];
						tmp2 = tmp2 + gin[i+m-1][j+1-n];
						tmp3 = tmp3 + bin[i+m-1][j+1-n];
						div = 25;
					}
				}
			} else if(i==1 && j==2) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j+n-2];
						tmp2 = tmp2 + gin[i+m-1][j+n-2];
						tmp3 = tmp3 + bin[i+m-1][j+n-2];
						div = 30;
					}
				}
			} else if(i==1 && j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j+2-n];
						tmp2 = tmp2 + gin[i+m-1][j+2-n];
						tmp3 = tmp3 + bin[i+m-1][j+2-n];
						div = 30;
					}
				}
			} else if(i==1) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i+m-1][j+n-3];
						tmp2 = tmp2 + gin[i+m-1][j+n-3];
						tmp3 = tmp3 + bin[i+m-1][j+n-3];
						div = 35;
					}
				}
			} else if(i==(ipp_para->src_height-2) && j==0) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j+n];
						tmp2 = tmp2 + gin[i-m+1][j+n];
						tmp3 = tmp3 + bin[i-m+1][j+n];
						div = 20;
					}
				}
			} else if(i==(ipp_para->src_height-2) && j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j-n];
						tmp2 = tmp2 + gin[i-m+1][j-n];
						tmp3 = tmp3 + bin[i-m+1][j-n];
						div = 20;
					}
				}
			} else if(i==(ipp_para->src_height-2) && j==1) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j+n-1];
						tmp2 = tmp2 + gin[i-m+1][j+n-1];
						tmp3 = tmp3 + bin[i-m+1][j+n-1];
						div = 25;
					}
				}
			} else if(i==(ipp_para->src_height-2) && j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j+1-n];
						tmp2 = tmp2 + gin[i-m+1][j+1-n];
						tmp3 = tmp3 + bin[i-m+1][j+1-n];
						div = 25;
					}
				}
			} else if(i==(ipp_para->src_height-2) && j==2) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j+n-2];
						tmp2 = tmp2 + gin[i-m+1][j+n-2];
						tmp3 = tmp3 + bin[i-m+1][j+n-2];
						div = 30;
					}
				}
			} else if(i==(ipp_para->src_height-2) && j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j+2-n];
						tmp2 = tmp2 + gin[i-m+1][j+2-n];
						tmp3 = tmp3 + bin[i-m+1][j+2-n];
						div = 30;
					}
				}
			} else if(i==(ipp_para->src_height-2)) {
				for(m = 0; m <= 4; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i-m+1][j+n-3];
						tmp2 = tmp2 + gin[i-m+1][j+n-3];
						tmp3 = tmp3 + bin[i-m+1][j+n-3];
						div = 35;
					}
				}
			} else if(i==2 && j==0) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+n];
						tmp2 = tmp2 + gin[i+m-2][j+n];
						tmp3 = tmp3 + bin[i+m-2][j+n];
						div = 24;
					}
				}
			} else if(i==2 && j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j-n];
						tmp2 = tmp2 + gin[i+m-2][j-n];
						tmp3 = tmp3 + bin[i+m-2][j-n];
						div = 24;
					}
				}
			} else if(i==2 && j==1) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+n-1];
						tmp2 = tmp2 + gin[i+m-2][j+n-1];
						tmp3 = tmp3 + bin[i+m-2][j+n-1];
						div = 30;
					}
				}
			} else if(i==2 && j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+1-n];
						tmp2 = tmp2 + gin[i+m-2][j+1-n];
						tmp3 = tmp3 + bin[i+m-2][j+1-n];
						div = 30;
					}
				}
			} else if(i==2 && j==2) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+n-2];
						tmp2 = tmp2 + gin[i+m-2][j+n-2];
						tmp3 = tmp3 + bin[i+m-2][j+n-2];
						div = 36;
					}
				}
			} else if(i==2 && j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+2-n];
						tmp2 = tmp2 + gin[i+m-2][j+2-n];
						tmp3 = tmp3 + bin[i+m-2][j+2-n];
						div = 36;
					}
				}
			} else if(i==2) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i+m-2][j+n-3];
						tmp2 = tmp2 + gin[i+m-2][j+n-3];
						tmp3 = tmp3 + bin[i+m-2][j+n-3];
						div = 42;
					}
				}
			} else if(i==(ipp_para->src_height-3) && j==0) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j+n];
						tmp2 = tmp2 + gin[i-m+2][j+n];
						tmp3 = tmp3 + bin[i-m+2][j+n];
						div = 24;
					}
				}
			} else if(i==(ipp_para->src_height-3) && j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j-n];
						tmp2 = tmp2 + gin[i-m+2][j-n];
						tmp3 = tmp3 + bin[i-m+2][j-n];
						div = 24;
					}
				}
			} else if(i==(ipp_para->src_height-3) && j==1) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j+n-1];
						tmp2 = tmp2 + gin[i-m+2][j+n-1];
						tmp3 = tmp3 + bin[i-m+2][j+n-1];
						div = 30;
					}
				}
			} else if(i==(ipp_para->src_height-3) && j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j+1-n];
						tmp2 = tmp2 + gin[i-m+2][j+1-n];
						tmp3 = tmp3 + bin[i-m+2][j+1-n];
						div = 30;
					}
				}
			} else if(i==(ipp_para->src_height-3) && j==2) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j+n-2];
						tmp2 = tmp2 + gin[i-m+2][j+n-2];
						tmp3 = tmp3 + bin[i-m+2][j+n-2];
						div = 36;
					}
				}
			} else if(i==(ipp_para->src_height-3) && j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j+2-n];
						tmp2 = tmp2 + gin[i-m+2][j+2-n];
						tmp3 = tmp3 + bin[i-m+2][j+2-n];
						div = 36;
					}
				}
			} else if(i==(ipp_para->src_height-3)) {
				for(m = 0; m <= 5; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i-m+2][j+n-3];
						tmp2 = tmp2 + gin[i-m+2][j+n-3];
						tmp3 = tmp3 + bin[i-m+2][j+n-3];
						div = 42;
					}
				}
			} else if(j==0) {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j+n];
						tmp2 = tmp2 + gin[i+m-3][j+n];
						tmp3 = tmp3 + bin[i+m-3][j+n];
						div = 28;
					}
				}
			} else if(j==(ipp_para->src_width-1)) {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 3; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j-n];
						tmp2 = tmp2 + gin[i+m-3][j-n];
						tmp3 = tmp3 + bin[i+m-3][j-n];
						div = 28;
					}
				}
			} else if(j==1) {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j+n-1];
						tmp2 = tmp2 + gin[i+m-3][j+n-1];
						tmp3 = tmp3 + bin[i+m-3][j+n-1];
						div = 35;
					}
				}
			} else if(j==(ipp_para->src_width-2)) {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 4; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j+1-n];
						tmp2 = tmp2 + gin[i+m-3][j+1-n];
						tmp3 = tmp3 + bin[i+m-3][j+1-n];
						div = 35;
					}
				}
			} else if(j==2) {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j+n-2];
						tmp2 = tmp2 + gin[i+m-3][j+n-2];
						tmp3 = tmp3 + bin[i+m-3][j+n-2];
						div = 42;
					}
				}
			} else if(j==(ipp_para->src_width-3)) {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 5; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j+2-n];
						tmp2 = tmp2 + gin[i+m-3][j+2-n];
						tmp3 = tmp3 + bin[i+m-3][j+2-n];
						div = 42;
					}
				}
			} else {
				for(m = 0; m <= 6; m++) {
					for(n = 0; n <= 6; n++) {  
						tmp1 = tmp1 + rin[i+m-3][j+n-3];
						tmp2 = tmp2 + gin[i+m-3][j+n-3];
						tmp3 = tmp3 + bin[i+m-3][j+n-3];
						div = 49;
					}
				}
			}
			rout[i][j] = round(tmp1/div);
			gout[i][j] = round(tmp2/div);
			bout[i][j] = round(tmp3/div);
    }
  }
}

void rankflt(kal_int32 order, ipp_effect_struct * const ipp_para)
{
  kal_int32 i,j;
    
	for(i = 0; i < ipp_para->src_height; i++) 
	{
		for(j = 0; j < ipp_para->src_width; j++) 
		{
			if(i==0 && j==0) 
			{
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = rin[i][j]; 
				arrin[6] = rin[i+1][j]; arrin[7] = rin[i][j+1]; arrin[8] = rin[i+1][j+1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = gin[i][j]; 
				arrin[6] = gin[i+1][j]; arrin[7] = gin[i][j+1]; arrin[8] = gin[i+1][j+1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = bin[i][j]; 
				arrin[6] = bin[i+1][j]; arrin[7] = bin[i][j+1]; arrin[8] = bin[i+1][j+1];
				bout[i][j] = selectflt(order);
			} else if(i==0 && j==ipp_para->src_width-1) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = rin[i][j]; 
				arrin[6] = rin[i+1][j]; arrin[7] = rin[i][j-1]; arrin[8] = rin[i+1][j-1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = gin[i][j]; 
				arrin[6] = gin[i+1][j]; arrin[7] = gin[i][j-1]; arrin[8] = gin[i+1][j-1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = bin[i][j]; 
				arrin[6] = bin[i+1][j]; arrin[7] = bin[i][j-1]; arrin[8] = bin[i+1][j-1];
				bout[i][j] = selectflt(order);
			} else if(i==0) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = rin[i][j]; arrin[4] = rin[i+1][j]; arrin[5] = rin[i][j-1]; 
				arrin[6] = rin[i+1][j-1]; arrin[7] = rin[i][j+1]; arrin[8] = rin[i+1][j+1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = gin[i][j]; arrin[4] = gin[i+1][j]; arrin[5] = gin[i][j-1]; 
				arrin[6] = gin[i+1][j-1]; arrin[7] = gin[i][j+1]; arrin[8] = gin[i+1][j+1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = bin[i][j]; arrin[4] = bin[i+1][j]; arrin[5] = bin[i][j-1]; 
				arrin[6] = bin[i+1][j-1]; arrin[7] = bin[i][j+1]; arrin[8] = bin[i+1][j+1];
				bout[i][j] = selectflt(order);
			} else if(i==ipp_para->src_height-1 && j==0) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = rin[i][j];
				arrin[6] = rin[i-1][j]; arrin[7] = rin[i][j+1]; arrin[8] = rin[i-1][j+1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = gin[i][j];
				arrin[6] = gin[i-1][j]; arrin[7] = gin[i][j+1]; arrin[8] = gin[i-1][j+1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = bin[i][j];
				arrin[6] = bin[i-1][j]; arrin[7] = bin[i][j+1]; arrin[8] = bin[i-1][j+1];
				bout[i][j] = selectflt(order);
			} else if(i==ipp_para->src_height-1 && j==ipp_para->src_width-1) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = rin[i][j];
				arrin[6] = rin[i-1][j]; arrin[7] = rin[i][j-1]; arrin[8] = rin[i-1][j-1];
				rout[i][j] = selectflt(order); 
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = gin[i][j];
				arrin[6] = gin[i-1][j]; arrin[7] = gin[i][j-1]; arrin[8] = gin[i-1][j-1];
				gout[i][j] = selectflt(order); 
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = 0; arrin[4] = 0; arrin[5] = bin[i][j];
				arrin[6] = bin[i-1][j]; arrin[7] = bin[i][j-1]; arrin[8] = bin[i-1][j-1];
				bout[i][j] = selectflt(order); 
			} else if(i==ipp_para->src_height-1) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = rin[i][j]; arrin[4] = rin[i-1][j]; arrin[5] = rin[i][j-1];
				arrin[6] = rin[i-1][j-1]; arrin[7] = rin[i][j+1]; arrin[8] = rin[i-1][j+1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = gin[i][j]; arrin[4] = gin[i-1][j]; arrin[5] = gin[i][j-1];
				arrin[6] = gin[i-1][j-1]; arrin[7] = gin[i][j+1]; arrin[8] = gin[i-1][j+1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = bin[i][j]; arrin[4] = bin[i-1][j]; arrin[5] = bin[i][j-1];
				arrin[6] = bin[i-1][j-1]; arrin[7] = bin[i][j+1]; arrin[8] = bin[i-1][j+1];
				bout[i][j] = selectflt(order);
			} else if(j==0) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = rin[i][j]; arrin[4] = rin[i-1][j]; arrin[5] = rin[i+1][j];
				arrin[6] = rin[i][j+1]; arrin[7] = rin[i-1][j+1]; arrin[8] = rin[i+1][j+1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = gin[i][j]; arrin[4] = gin[i-1][j]; arrin[5] = gin[i+1][j];
				arrin[6] = gin[i][j+1]; arrin[7] = gin[i-1][j+1]; arrin[8] = gin[i+1][j+1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = bin[i][j]; arrin[4] = bin[i-1][j]; arrin[5] = bin[i+1][j];
				arrin[6] = bin[i][j+1]; arrin[7] = bin[i-1][j+1]; arrin[8] = bin[i+1][j+1];
				bout[i][j] = selectflt(order);
			} else if(j==ipp_para->src_width-1) {
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = rin[i][j]; arrin[4] = rin[i-1][j]; arrin[5] = rin[i+1][j];
				arrin[6] = rin[i][j-1]; arrin[7] = rin[i-1][j-1]; arrin[8] = rin[i+1][j-1];
				rout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = gin[i][j]; arrin[4] = gin[i-1][j]; arrin[5] = gin[i+1][j];
				arrin[6] = gin[i][j-1]; arrin[7] = gin[i-1][j-1]; arrin[8] = gin[i+1][j-1];
				gout[i][j] = selectflt(order);
				arrin[0] = 0; arrin[1] = 0; arrin[2] = 0; arrin[3] = bin[i][j]; arrin[4] = bin[i-1][j]; arrin[5] = bin[i+1][j];
				arrin[6] = bin[i][j-1]; arrin[7] = bin[i-1][j-1]; arrin[8] = bin[i+1][j-1];
				bout[i][j] = selectflt(order);
			} else {
				arrin[0] = rin[i][j]; arrin[1] = rin[i-1][j]; arrin[2] = rin[i+1][j]; arrin[3] = rin[i][j-1]; arrin[4] = rin[i-1][j-1];
				arrin[5] = rin[i+1][j-1]; arrin[6] = rin[i][j+1]; arrin[7] = rin[i-1][j+1]; arrin[8] = rin[i+1][j+1];
				rout[i][j] = selectflt(order);
				arrin[0] = gin[i][j]; arrin[1] = gin[i-1][j]; arrin[2] = gin[i+1][j]; arrin[3] = gin[i][j-1]; arrin[4] = gin[i-1][j-1];
				arrin[5] = gin[i+1][j-1]; arrin[6] = gin[i][j+1]; arrin[7] = gin[i-1][j+1]; arrin[8] = gin[i+1][j+1];
				gout[i][j] = selectflt(order);
				arrin[0] = bin[i][j]; arrin[1] = bin[i-1][j]; arrin[2] = bin[i+1][j]; arrin[3] = bin[i][j-1]; arrin[4] = bin[i-1][j-1];
				arrin[5] = bin[i+1][j-1]; arrin[6] = bin[i][j+1]; arrin[7] = bin[i-1][j+1]; arrin[8] = bin[i+1][j+1];
				bout[i][j] = selectflt(order);
			}
		}
	}    
}

kal_uint8 selectflt(kal_int32 order)
{
	kal_int32 res;
	kal_int32 tmp[9];
	kal_int32 ent;
	kal_int32 i, j;
	for(i=0; i<9; i++) {
		tmp[i] = arrin[i];
		for(j=i+1; j<9; j++) {
			if(tmp[i] < arrin[j]) {
				ent = tmp[i];
				tmp[i] = arrin[j];
				arrin[j] = ent;
			}
		}
	}
	res = tmp[order];
	return (kal_uint8)res;
}

void unsharp(ipp_effect_struct * const ipp_para)
{  
  kal_int32 i,j;
  
  init_mask();
  
  for(i = 0; i < ipp_para->src_height; i++) 
  {
    for(j = 0; j < ipp_para->src_width; j++) 
    {
      if(i==0 && j==0) 
      {
        factor = 4;
        init_a();
        a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; a[1][2] = rin[i][j+1]; a[2][2] = rin[i+1][j+1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; a[1][2] = gin[i][j+1]; a[2][2] = gin[i+1][j+1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; a[1][2] = bin[i][j+1]; a[2][2] = bin[i+1][j+1];
        bout[i][j] = conv_unsharp();
      } 
      else if(i==0 && j==ipp_para->src_width-1) 
      {
        factor = 4;
        init_a();
        a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; a[2][0] = rin[i+1][j-1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; a[2][0] = gin[i+1][j-1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; a[2][0] = bin[i+1][j-1];
        bout[i][j] = conv_unsharp();
      } 
      else if(i==0) 
      {
        factor = 6;
        init_a();
        a[1][1] = rin[i][j]; a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; a[2][0] = rin[i+1][j-1]; a[1][2] = rin[i][j+1]; a[2][2] = rin[i+1][j+1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; a[2][0] = gin[i+1][j-1]; a[1][2] = gin[i][j+1]; a[2][2] = gin[i+1][j+1];
        gout[i][j] = conv_unsharp(); 
        init_a();
        a[1][1] = bin[i][j]; a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; a[2][0] = bin[i+1][j-1]; a[1][2] = bin[i][j+1]; a[2][2] = bin[i+1][j+1];
        bout[i][j] = conv_unsharp();
      } 
      else if(i==ipp_para->src_height-1 && j==0) 
      {
        factor = 4;
        init_a();
        a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1];
        bout[i][j] = conv_unsharp();
      } 
      else if(i==ipp_para->src_height-1 && j==ipp_para->src_width-1) 
      {
        factor = 4;
        init_a();
        a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1];
        bout[i][j] = conv_unsharp();
      } 
      else if(i==ipp_para->src_height-1) 
      {
        factor = 6;
        init_a();
        a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1]; a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1]; a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1]; a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1];
        bout[i][j] = conv_unsharp();
      } 
      else if(j==0) 
      {
        factor = 6;
        init_a();
        a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; a[2][1] = rin[i+1][j]; a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1]; a[2][2] = rin[i+1][j+1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; a[2][1] = gin[i+1][j]; a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1]; a[2][2] = gin[i+1][j+1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; a[2][1] = bin[i+1][j]; a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1]; a[2][2] = bin[i+1][j+1];
        bout[i][j] = conv_unsharp();
      } 
      else if(j==ipp_para->src_width-1) 
      {
        factor = 6;
        init_a();
        a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1]; a[2][0] = rin[i+1][j-1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1]; a[2][0] = gin[i+1][j-1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1]; a[2][0] = bin[i+1][j-1];
        bout[i][j] = conv_unsharp();
      } 
      else 
      {
        factor = 9;
        init_a();
        a[1][1] = rin[i][j]; a[0][1] = rin[i-1][j]; a[2][1] = rin[i+1][j]; a[1][0] = rin[i][j-1]; a[0][0] = rin[i-1][j-1]; a[2][0] = rin[i+1][j-1]; a[1][2] = rin[i][j+1]; a[0][2] = rin[i-1][j+1]; a[2][2] = rin[i+1][j+1];
        rout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = gin[i][j]; a[0][1] = gin[i-1][j]; a[2][1] = gin[i+1][j]; a[1][0] = gin[i][j-1]; a[0][0] = gin[i-1][j-1]; a[2][0] = gin[i+1][j-1]; a[1][2] = gin[i][j+1]; a[0][2] = gin[i-1][j+1]; a[2][2] = gin[i+1][j+1];
        gout[i][j] = conv_unsharp();
        init_a();
        a[1][1] = bin[i][j]; a[0][1] = bin[i-1][j]; a[2][1] = bin[i+1][j]; a[1][0] = bin[i][j-1]; a[0][0] = bin[i-1][j-1]; a[2][0] = bin[i+1][j-1]; a[1][2] = bin[i][j+1]; a[0][2] = bin[i-1][j+1]; a[2][2] = bin[i+1][j+1];
        bout[i][j] = conv_unsharp();
      }
    }
  }

}  



kal_uint8 conv_unsharp()
{
  kal_int32 sum = 0;
  kal_int32 i, j;
  double tmp;
  kal_int32 norm;

  // matrix operation
  for(i=0; i<3; i++)
    for(j=0; j<3; j++)
      sum += (a[i][j] * mask[i][j]);

  // clipping on negative value
  if(sum <= 0)
    sum = 0;

  // division and rounding
  tmp = ((double)sum / factor);
  sum = (int)tmp;
  if((tmp - (double)sum) >= 0.5)
    sum += 1;

  // clipping on top
  if(sum >= 255)
    sum = 255;

  // unsharp operation
  norm = (a[1][1])* 2; 
  sum = norm - sum;

  // clipping on top and negative value
  
  if(sum >= 255) 
    sum = 255;
  else if(sum <= 0)
    sum = 0;
  
  return (kal_uint8)sum;
}

#endif
