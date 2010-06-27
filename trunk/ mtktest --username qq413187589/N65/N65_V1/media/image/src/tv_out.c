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
 *   tv_out.c
 *
 * Project:
 * --------
 *		MT6228, MT6229, MT6230, MT6238
 *
 * Description:
 * ------------
 *   MT6228, MT6229 tv output control function
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef TV_OUT_SUPPORT

#include "reg_base.h"
#include "drv_comm.h"
#include "drv_features.h"
#include "tv_out_controller_hw.h"
#include "tv_out_encoder_hw.h"
#include "tv_out.h"
#include "tv_custom.h"
#include "upll_ctrl.h"

extern kal_bool custom_ifLPSDRAM(void);
kal_bool tv_out_format_change_flag=KAL_FALSE;
kal_bool tv_src_size_set_flag=KAL_FALSE;
kal_uint16 tv_target_width,tv_target_height;
kal_uint16 tv_src_width, tv_src_height;
tv_output_para_struct tv_output_config_data;/*to keep tv out config parameter*/
kal_uint8 tv_operation_state=TV_IDLE_STATE;/*tv out global state*/

kal_uint8 tv_out_current_fb=0;/*tv out update count, change this variable in lcd and img_comm*/
kal_uint8 tv_output_owner=TV_OUT_OWNER_NONE; /*tv out update owner*/

/*sleep mode function*/
extern kal_uint8 L1SM_GetHandle(void);
extern void L1SM_SleepEnable(kal_uint8 handle);
extern void L1SM_SleepDisable(kal_uint8 handle);
kal_uint8 tv_sleep_mode_handler=0xFF;

/*start of internal use*/
static void tv_turn_on_prefetchDMA(kal_uint32 buf_addr, kal_uint32 src_w, kal_uint32 src_h, TV_OUT_SRC_FMT_ENUM fmt)
{      
   #if defined(DRV_TVOUT_6238_SERIES)
      /*prefetch DMA setting*/	   
      if(TV_DATA_RGB565==fmt)
      {
         DRV_WriteReg32(TV_CON_PFH_DMA_Y_ADDR_SRC_REG,buf_addr);      
         DRV_WriteReg32(TV_CON_PFH_DMA_LINE_OFFSSET_REG,src_w*2);	   
      }  
      else
      {
         DRV_WriteReg32(TV_CON_PFH_DMA_U_ADDR_SRC_REG,buf_addr+src_w*src_h);
         DRV_WriteReg32(TV_CON_PFH_DMA_V_ADDR_SRC_REG,buf_addr+(src_w*src_h*5)>>2);   
         DRV_WriteReg32(TV_CON_PFH_DMA_LINE_OFFSSET_REG,src_w);	   
      }   
        
      DRV_WriteReg32(TV_CON_PFH_DMA_FIFO_LEN_REG,8);
      ENABLE_TV_CTRL_PREFETCH;
   #endif //DRV_TVOUT_6238_SERIES
}   

static void tv_turn_off_prefetchDMA(void)
{
   #if defined(DRV_TVOUT_6238_SERIES)
      DISABLE_TV_CTRL_PREFETCH;
   #endif //DRV_TVOUT_6238_SERIES
}   

static void tv_power_on(void)
{
	kal_uint32 save_irq_mask;

   /// Turn off TV PLL clock
	#if defined(DRV_TVOUT_6228_SERIES)
	DRV_Reg(DRVPDN_CON0_CLR) = DRVPDN_CON0_TPLL;
	#elif defined(DRV_TVOUT_6238_SERIES)
	   //KKKKK
	DRV_WriteReg(TPLL,0xe0);	   	   	   	   
	DRV_WriteReg(TPLL2,0x0);	   	   	   	   	   
	#endif
	
	/// Power on TV module
	DRV_Reg(DRVPDN_CON3_CLR) = DRVPDN_CON3_TV;

	save_irq_mask=SaveAndSetIRQMask();
	UPLL_Enable(UPLL_OWNER_TV);
	RestoreIRQMask(save_irq_mask);
	tv_operation_state=TV_DETECTION_STATE;

	/* turn on TV DAC */
	ENABLE_TV_HALF_BIAS_POWER;
	ENABLE_TV_DAC2_POWER;
	ENABLE_TV_DAC1_POWER;
	ENABLE_TV_DAC0_POWER;
	ENABLE_TV_BGVREF_POWER;
	ENABLE_TV_DAC_POWER;
	ENABLE_TV_ENCODER;
}	/* tv_power_on() */

static void tv_power_off(void)
{
	kal_uint32 save_irq_mask;

	/* turn off TV DAC */
	DISABLE_TV_HALF_BIAS_POWER;
	DISABLE_TV_DAC2_POWER;
	DISABLE_TV_DAC1_POWER;
	DISABLE_TV_DAC0_POWER;
	DISABLE_TV_BGVREF_POWER;
	DISABLE_TV_DAC_POWER;

	DISABLE_TV_ENCODER;
	DISABLE_TV_CONTROLLER;
	RESET_TV_CONTROLLER;
	tv_src_width=0;
	tv_src_height=0;

   /// Turn off TV PLL clock
	#if defined(DRV_TVOUT_6228_SERIES)
	DRV_Reg(DRVPDN_CON0_SET) = DRVPDN_CON0_TPLL;
	#elif defined(DRV_TVOUT_6238_SERIES)
	   //KKKKK
	   DRV_WriteReg(TPLL2,0x1);	   	   	   	   
	#endif
	/// Power off TV module
	DRV_Reg(DRVPDN_CON3_SET) = DRVPDN_CON3_TV;

	save_irq_mask=SaveAndSetIRQMask();
	UPLL_Disable(UPLL_OWNER_TV);
	RestoreIRQMask(save_irq_mask);

	tv_operation_state=TV_IDLE_STATE;
}	/* tv_power_off() */
/*end of internal use*/


/**
 * To initialize TV out module
 *
 * @param None.
 *
 * @return None.
 */
void init_tv(void)
{
	tv_power_on();
	tv_output_owner=TV_OUT_OWNER_MMI;
	tv_output_config_data.tv_output_mode=0;/*TV_FORMAT_NTSCTV_OUTPUT_DISABLE*/
	tv_output_config_data.tv_output_format=0;/*TV_FORMAT_NTSC*/
	tv_output_config_data.tv_output_offset_x=0;
	tv_output_config_data.tv_output_offset_y=0;

	/* configure TV encoder mode */
	/*?????=> don't change*/
	DISABLE_TV_UV_SWAP;
	DISABLE_TV_BLACKER_MODE;
	DISABLE_TV_HORIZONTAL_SLEW;
	SET_TV_SYDELAY_BIT;
	SET_TV_Y_DELAY(2);
	DISABLE_TV_CHROMA_UP_SAMPLE;
	DISABLE_TV_LUMA_LPF;
	ENABLE_TV_CHROMA_LPF;
	SET_TV_CHROMA_LPF0;

	SET_TV_ENC_SCALE_BLANK(4);

	/* configure TV controller contorl register */
	/*?????*/
	SET_TV_CON_WRITE_SINGLE_BUFFER;
	DISABLE_TV_CON_BURST_MODE;
	#if defined(DRV_TVOUT_6228_SERIES)
	ENABLE_TV_CON_DEEPER_BUFFER;
	#elif defined(DRV_TVOUT_6238_SERIES)
	   //KKKKK, need to confirm with designer
	   ENABLE_TV_CON_HIGHER_BUS_PRIORITY;  
	   ENABLE_TV_CTRL_HANDSHAKE_WTITH_VIDEC; 
	   DISABLE_TV_CTRL_PREFETCH;
	   SET_TV_CON_READ_ACTIVE_BUFFER;
	   ENABLE_TV_CTRL_AVG_MODE;
	   ENABLE_TV_CTRL_CLIP_MODE;
	   DISABLE_TV_CTRL_CHKLINE_INT_MODE;
	   DISABLE_TV_CTRL_OVR_INT_MODE;
	   /*TVC slow control, may need to fine tune*/	   	   
	   DRV_WriteReg32(TV_CON_SLOW_CTRL_REG,(4<<24)|(4<<20)|(2<<16)|(400));	   	   	   	   
	
	#endif
	
	ENABLE_TV_CON_FILL_BLACK_PIXEL;
	if (custom_ifLPSDRAM()==KAL_TRUE)
	{
	ENABLE_TV_CON_VERTICAL_INTERPOLATION;
	}
	else
	{
		DISABLE_TV_CON_VERTICAL_INTERPOLATION;
	}
	SET_TV_CON_READ_WRITE_BUFFER;
	/*可讓邊緣不sharp*/
	#if defined(DRV_TVOUT_6228_SERIES)
			ENABLE_TV_CON_MAGIC_SWITCH;
	#elif defined(DRV_TVOUT_6238_SERIES)
	   //KKKKK, need to confirm with DE			
	   //this resiger doesn't exist anymore   
	#endif		
	/*enable handshake between tv out and mpeg4*/
	ENABLE_TV_CTRL_HANDSHAKE_WTITH_VIDEC;	
	ENABLE_TV_DAC_MAGIC_SWITCH;		
   /*sleep mode*/
   if (tv_sleep_mode_handler==0xFF)
   	tv_sleep_mode_handler=L1SM_GetHandle();
   L1SM_SleepDisable(tv_sleep_mode_handler);
   
}	/* init_tv() */

/**
 * To deinitialize TV out module
 *
 * @param None.
 *
 * @return KAL_TRUE, initialize successfully.
 */
void deinit_tv(void)
{
	tv_power_off();
   L1SM_SleepEnable(tv_sleep_mode_handler);
}	/* deinit_tv() */

/**
 * To start TV out detection
 *
 * @param None.
 *
 * @return KAL_TRUE, TV connects. KAL_FALSE, TV not connects
 */
kal_bool tv_set_detection(void)
{
	tv_operation_state=TV_STANDBY_STATE;
	return KAL_TRUE;
#if 0	/*XXXXX too many HW issues, not turn on it*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}	/* tv_set_detection() */

/**
 * To set TV out format
 *
 * @param data_format  TV_DATA_RGB565 or TV_DATA_YUV420
 *
 * @return None
 */
void set_tv_output_data_format(TV_OUT_SRC_FMT_ENUM data_format)
{
	#if defined(DRV_TVOUT_6228_SERIES)
	if (data_format==TV_DATA_YUV420)
	{
		SET_TV_CON_SRC_YUV420;
		tv_output_config_data.tv_output_data_format=TV_DATA_YUV420;
	}
	else if (data_format==TV_DATA_RGB565)
	{
		SET_TV_CON_SRC_RGB565;
		tv_output_config_data.tv_output_data_format=TV_DATA_RGB565;
	}
	#elif defined(DRV_TVOUT_6238_SERIES)
	//KKKKK, inform MMI
	   switch(data_format)
	   {
	      case TV_DATA_RGB565:
	         SET_TV_CON_SRC_RGB565;
	         tv_output_config_data.tv_output_data_format=TV_DATA_RGB565;      	         
	         break;
	      case TV_DATA_YUV420:
	      case TV_DATA_MP4_YUV420:/*KKKKK in E2 version, this format won't exist again*/
	         SET_TV_CON_SRC_MP4_YUV420;
	         tv_output_config_data.tv_output_data_format=TV_DATA_MP4_YUV420;      
	         break;   
	      case TV_DATA_H264_YUV420:
	         SET_TV_CON_SRC_H264_YUV420;
	         tv_output_config_data.tv_output_data_format=TV_DATA_H264_YUV420;      	         
	         break;
	      default :
	         break;   
	   }   	
	#endif
}	/* set_tv_output_data_format() */

/**
 * To set TV output mode
 *
 * @param tv_para  TV out structure
 *
 * @return None
 */
void set_tv_output_mode(tv_output_para_struct *tv_para)
{
	volatile kal_uint32 i;
   kal_uint16 target_width,target_height,offset_x,offset_y;

   /*????? why keep this variable and check it in set_tv_src_size()==> to sync with source size*/
	if (tv_output_config_data.tv_output_format==tv_para->tv_output_format)
		tv_out_format_change_flag=KAL_FALSE;
	else
		tv_out_format_change_flag=KAL_TRUE;
		
	/*tv_output_data_format, tv_output_src_width, tv_output_src_height 
	  are set in set_tv_src_size() and set_tv_output_data_format(); 
	  img_comm.c or lcd_update.c may call these two functions.	
	*/			
	tv_output_config_data.tv_output_mode=tv_para->tv_output_mode;
	tv_output_config_data.tv_output_format=tv_para->tv_output_format;
	tv_output_config_data.tv_output_offset_x=tv_para->tv_output_offset_x;
	tv_output_config_data.tv_output_offset_y=tv_para->tv_output_offset_y;

	SET_TV_TYPE(tv_output_config_data.tv_output_format);

   /*XXXXX use set_tv_parameter(TV_OUT_Y_COMP,tv_gamma_table_sel) instead*/
	/* configure TV encoder gamma table */
	SET_TV_ENC_GAMMA0_COEFF(tv_gamma_table[tv_gamma_table_sel][0]);
	SET_TV_ENC_GAMMA1_COEFF(tv_gamma_table[tv_gamma_table_sel][1]);
	SET_TV_ENC_GAMMA2_COEFF(tv_gamma_table[tv_gamma_table_sel][2]);
	SET_TV_ENC_GAMMA3_COEFF(tv_gamma_table[tv_gamma_table_sel][3]);
	SET_TV_ENC_GAMMA4_COEFF(tv_gamma_table[tv_gamma_table_sel][4]);
	SET_TV_ENC_GAMMA5_COEFF(tv_gamma_table[tv_gamma_table_sel][5]);
	SET_TV_ENC_GAMMA6_COEFF(tv_gamma_table[tv_gamma_table_sel][6]);
	SET_TV_ENC_GAMMA7_COEFF(tv_gamma_table[tv_gamma_table_sel][7]);
	SET_TV_ENC_GAMMA8_COEFF(tv_gamma_table[tv_gamma_table_sel][8]);

	if (tv_output_config_data.tv_output_format==TV_FORMAT_NTSC)
	{
	   /*????? how to decide these parameters*/
		DISABLE_TV_7_5_IRE_SETUP;
		target_width=TV_OUTPUT_NTSC_WIDTH;/*640, 實驗得知*/
		target_height=TV_OUTPUT_NTSC_HEIGHT;/*442*/
		offset_x=TV_OUTPUT_NTSC_OFFSET_X;/*30, 實驗得知*/
		offset_y=TV_OUTPUT_NTSC_OFFSET_Y;/*31*/		
		DRV_WriteReg32(TV_ENC_COLOR_FREQ_CTRL_REG,((3535<<16)|271));
		if (tv_eng_mode==KAL_FALSE)
		{
			SET_TV_ENC_V_SCALE(tv_v_scale_ntsc);/*ini value is for 標準*/
			SET_TV_ENC_U_SCALE(tv_u_scale_ntsc);
		}
		else
		{
			SET_TV_ENC_V_SCALE(tv_engmode_v_scale);
			SET_TV_ENC_U_SCALE(tv_engmode_u_scale);
		}
		REG_TV_ENC_BURST_LEVEL_CTRL=0x3d;
	}
	else
	{
	   /*????? how to decide these parameters*/
		DISABLE_TV_7_5_IRE_SETUP;
		target_width=TV_OUTPUT_PAL_WIDTH;/*640, 實驗得知*/
		target_height=TV_OUTPUT_PAL_HEIGHT;/*534*/
		offset_x=TV_OUTPUT_PAL_OFFSET_X;/*30, 實驗得知*/
		offset_y=TV_OUTPUT_PAL_OFFSET_Y;/*32*/
		DRV_WriteReg32(TV_ENC_COLOR_FREQ_CTRL_REG,((2061<<16)|336));
		if (tv_eng_mode==KAL_FALSE)
		{
			SET_TV_ENC_V_SCALE(tv_v_scale_pal);
			SET_TV_ENC_U_SCALE(tv_u_scale_pal);
		}
		else
		{
			SET_TV_ENC_V_SCALE(tv_engmode_v_scale);
			SET_TV_ENC_U_SCALE(tv_engmode_u_scale);
		}
		REG_TV_ENC_BURST_LEVEL_CTRL=0x3d;
	}
	/*?????, necessary*/
	for (i=0;i<0x60000;i++);
}	/* set_tv_output_mode() */
/*return current tvout buff addr*/

/**
 * To get current Y buffer address
 *
 * @param None
 *
 * @return current Y buffer address
 */
kal_uint32 get_current_tv_output_buffer(void)
{
	return DRV_Reg32(TV_CON_Y_DATA_ADDR_REG);
}	/* get_current_tv_output_buffer() */

/**
 * To enable tv out controller
 *
 * @param tv_on  KAL_TRUE or KAL_FALSE
 *
 * @return None.
 */
void enable_tv_output(kal_uint8 tv_on)
{
	if (tv_on==KAL_TRUE)
	{	/* start TV output */
		ENABLE_TV_CONTROLLER;
		tv_operation_state=TV_UPDATE_STATE;
	}
	else if (tv_on==KAL_FALSE)
	{	/* stop TV output */
		DISABLE_TV_CONTROLLER;
		tv_operation_state=TV_STANDBY_STATE;
	}
	UPDATE_TV_CON_REGISTER;
}	/* enable_tv_output() */

/**
 * To enable tv out interpolation
 *
 * @param tv_on  KAL_TRUE or KAL_FALSE
 *
 * @return None.
 */
void enable_tv_vertical_interpolation(kal_uint8 on)
{
   /*this is BW issue hence we should not turn 
     on vertical interpolation if we use DRAM*/
	if (custom_ifLPSDRAM()==KAL_TRUE)
	{
	if (on==KAL_TRUE)
	{
		ENABLE_TV_CON_VERTICAL_INTERPOLATION;
	}
	else if (on==KAL_FALSE)
	{
		DISABLE_TV_CON_VERTICAL_INTERPOLATION;
	}
	UPDATE_TV_CON_REGISTER;
	}
}	/* enable_tv_vertical_interpolation() */

/**
 * To enable tv out encoder
 *
 * @param tv_on  KAL_TRUE or KAL_FALSE
 *
 * @return None.
 */
/*called by auxmain.c when cable is in*/
kal_uint32 temp_tv_dac_value,temp_tv_enc_mode_value;
void enable_tv_encoder(kal_bool tv_on)
{
	if (tv_on==KAL_TRUE)
	{	/* start TV output */

		temp_tv_enc_mode_value=REG_TV_ENC_MODE;
		/*?????==> set for detection*/
		REG_TV_ENC_MODE=0x100001;
		REG_TV_ENC_THRESHOLD=0xC0;
		REG_TV_ENC_DAC_CTRL_REG |= TV_ENC_DAC_TV_PLUG_IN_DETECT_BIT;

		temp_tv_dac_value = REG_TV_ENC_DAC_CTRL_REG;
		REG_TV_ENC_DAC_CTRL_REG |= 0x3F;
	}
	else if (tv_on==KAL_FALSE)
	{	/* stop TV output */
		REG_TV_ENC_DAC_CTRL_REG &= ~TV_ENC_DAC_TV_PLUG_IN_DETECT_BIT;
		REG_TV_ENC_MODE=temp_tv_enc_mode_value;
		REG_TV_ENC_THRESHOLD=0;
		REG_TV_ENC_DAC_CTRL_REG=temp_tv_dac_value;
	}
}	/* enable_tv_encoder() */

/**
 * To enable tv out source width and height
 *
 * @param tv_update_id  update owner id
 * @param src_width     source width
 * @param src_height    source height
 *
 * @return None.
 */
void set_tv_src_size(TV_OUT_OWNER_ENUM tv_update_id, kal_uint16 src_width,kal_uint16 src_height)
{
	volatile kal_uint32 i=0;
   kal_uint16 hcoefx=0,hcoefy=0,vcoefx=0,vcoefy=0;
   kal_uint16 target_width=0,target_height=0;
   kal_uint16 offset_x=0,offset_y=0;
   kal_uint16 real_width=0,real_height=0;
   kal_bool enable_pan=KAL_FALSE;

	if (tv_output_owner!=tv_update_id)
		ASSERT(0);

   if (tv_output_config_data.tv_output_data_format==TV_DATA_YUV420)
   {
   real_width=src_width;
   real_height=src_height;
      
   if(0==(src_width%16))
   {
	tv_output_config_data.tv_output_src_width=src_width;
   }
   else
   {
      tv_output_config_data.tv_output_src_width=(src_width/16)*16+16;
      src_width=tv_output_config_data.tv_output_src_width;
      enable_pan=KAL_TRUE;
   }   
   if(0==(src_height%16))
   {	
	tv_output_config_data.tv_output_src_height=src_height;
	}
	else
	{
	   tv_output_config_data.tv_output_src_height=(src_height/16)*16+16;
	   src_height=tv_output_config_data.tv_output_src_height;
	   enable_pan=KAL_TRUE;
	}      
	}
	else
	{
	   //KKKKKK, this limit still exists in 6238?   
	   ASSERT(((src_width%8)==0));	   
	}      

   if (tv_output_config_data.tv_output_format==TV_FORMAT_NTSC)
   {
   	target_width=TV_OUTPUT_NTSC_WIDTH;
   	target_height=TV_OUTPUT_NTSC_HEIGHT;
		offset_x=TV_OUTPUT_NTSC_OFFSET_X;
		offset_y=TV_OUTPUT_NTSC_OFFSET_Y;
   }
   else
	{
		target_width=TV_OUTPUT_PAL_WIDTH;
		target_height=TV_OUTPUT_PAL_HEIGHT;
		offset_x=TV_OUTPUT_PAL_OFFSET_X;
		offset_y=TV_OUTPUT_PAL_OFFSET_Y;
	}
   /*limit the max resize ratio(2)*/
   #if defined(DRV_TVOUT_6228_SERIES)
	if ((target_width>(src_width<<1))&&(target_height>(src_height<<1)))
	{
		target_width=src_width<<1;
		target_height=src_height<<1;
	}
	#elif defined(DRV_TVOUT_6238_SERIES)
	//KKKKK, OK, we should not have this limit in 6238
	#endif
	
   /*only scale up*/
	if ((src_width>target_width)||(src_height>target_height))
		ASSERT(0);
   /*????? formula????, not sure now*/
	if ((src_width*target_height)> (src_height*target_width))
	{	/* X dominate */
		target_height=src_height*target_width/src_width;
		if (tv_output_config_data.tv_output_format==TV_FORMAT_NTSC)
		{
			if ((target_height * 105/100)>=TV_OUTPUT_NTSC_HEIGHT)
				target_height = TV_OUTPUT_NTSC_HEIGHT;
		}
		else if (tv_output_config_data.tv_output_format==TV_FORMAT_PAL)
		{
			if ((target_height * 105/100)>=TV_OUTPUT_PAL_HEIGHT)
				target_height = TV_OUTPUT_PAL_HEIGHT;
		}
	}
	else
	{	/* Y dominate */
		target_width=src_width*target_height/src_height;
	   if (tv_output_config_data.tv_output_format==TV_FORMAT_NTSC)
	   {
	   	if ((target_width*12/10)> TV_OUTPUT_NTSC_WIDTH)
	   		target_width=TV_OUTPUT_NTSC_WIDTH;
	   	else
	   		target_width=target_width*12/10;
	   }
	}

   /*????? formula????*/
	/* centerize TV output, put the video in the center of TV set*/
   if (tv_output_config_data.tv_output_format==TV_FORMAT_NTSC)
   {
   	offset_x += ((TV_OUTPUT_NTSC_WIDTH-target_width)>>1);
   	offset_y += ((TV_OUTPUT_NTSC_HEIGHT-target_height)>>2); /* interlace and centerlize */
   }
   else
	{
   	offset_x += ((TV_OUTPUT_PAL_WIDTH-target_width)>>1);
   	offset_y += ((TV_OUTPUT_PAL_HEIGHT-target_height)>>2);
	}

	offset_x &= 0xFFFE;

	hcoefx = 256*(src_width-1)/(target_width-1);
	hcoefy = 256*(src_width-1)%(target_width-1);;
	vcoefx = 256*(src_height-1)/(target_height-1);
	vcoefy = 256*(src_height-1)%(target_height-1);
	
	/*configure HW register*/
	if ((tv_src_width!=src_width)||(tv_src_height!=src_height)||(tv_out_format_change_flag==KAL_TRUE))
	{
		tv_out_format_change_flag=KAL_FALSE;

	tv_src_width=src_width;
	tv_src_height=src_height;
	tv_target_width=target_width;
	tv_target_height=target_height;

	tv_src_size_set_flag=KAL_TRUE;
	DISABLE_TV_CONTROLLER;
	   /*start point (x,y offset)*/
		DRV_WriteReg32(TV_CON_START_POINT_REG,((offset_x<<16)|offset_y));
	#if defined(DRV_TVOUT_6228_SERIES)
		DRV_WriteReg(TV_CON_H_SCALE_COEFF_X_REG,hcoefx);
		DRV_WriteReg(TV_CON_H_SCALE_COEFF_Y_REG,hcoefy);
		DRV_WriteReg(TV_CON_V_SCALE_COEFF_X_REG,vcoefx);
		DRV_WriteReg(TV_CON_V_SCALE_COEFF_Y_REG,vcoefy);
	#elif defined(DRV_TVOUT_6238_SERIES)
	      //KKKKK, OK	      
	   	DRV_WriteReg(TV_CON_H_SCALE_COEFF_XY_REG,(hcoefy<<16|hcoefx));	
	      DRV_WriteReg(TV_CON_V_SCALE_COEFF_XY_REG,(vcoefy<<16|vcoefx));					
	      /*define line offset according to different format*/
	      if (TV_DATA_RGB565==tv_output_config_data.tv_output_data_format)
	      {	         
	         SET_TV_CON_LINE_OFFSET((tv_src_width*2));
	         ASSERT((((tv_src_width*2)/4)%4==0));
   	   }  
   	   else//YUV format
   	   {   	         	      
   	      SET_TV_CON_LINE_OFFSET((tv_src_width));
   	      ASSERT((((tv_src_width)/4)%4==0));
   	   }    	      
	#endif
	DRV_WriteReg(TV_CON_SRC_WIDTH_REG,tv_src_width);
	DRV_WriteReg(TV_CON_SRC_HEIGHT_REG,tv_src_height);
	   if(enable_pan==KAL_FALSE)
	   {
	DRV_WriteReg(TV_CON_TARGET_WIDTH_REG,tv_target_width);
	DRV_WriteReg(TV_CON_TARGET_HEIGHT_REG,tv_target_height);
	      /*KKKKKK,to display full video*/
	      #if defined(DRV_TVOUT_6238_SERIES)
	         DRV_WriteReg32(TV_CON_STOP_POINT_REG,(((offset_x+tv_target_width)<<16)|(offset_y+tv_target_height/2)));   
	      #endif
	   }
	   else
	   {
	      DRV_WriteReg(TV_CON_TARGET_WIDTH_REG,((real_width*tv_target_width)/src_width));
	      DRV_WriteReg(TV_CON_TARGET_HEIGHT_REG,((real_height*tv_target_height)/src_height));
	      /*KKKKKK,to display full video*/
	      #if defined(DRV_TVOUT_6238_SERIES)
	         DRV_WriteReg32(TV_CON_STOP_POINT_REG,(((offset_x+((real_width*tv_target_width)/src_width))<<16)
	                                               |(offset_y+((real_height*tv_target_height)/src_height)/2)));   
	      #endif
	   }   
	   //KKKKK, wait new interface
	   //tv_turn_on_prefetchDMA(0x40000000, src_width, src_height, TV_DATA_RGB565);
	      
	UPDATE_TV_CON_REGISTER;
	   /*?????, why*/
	for (i=0;i<0x30000;i++);
	}

}	/* set_tv_src_size() */

/**
 * To configure rgb/yuv buffer address
 *
 * @param tv_update_id  TV_DATA_RGB565 or TV_DATA_YUV420
 * @param tv_output_buffer_address   rgb or y buffer address 
 *
 * @return None.
 */
void tv_fb_update(TV_OUT_OWNER_ENUM tv_update_id, kal_uint32 tv_output_buffer_address)
{
	if (tv_output_owner!=tv_update_id)
		ASSERT(0);

	if (tv_src_size_set_flag==KAL_TRUE)
	{
		ENABLE_TV_CONTROLLER;
		tv_src_size_set_flag = KAL_FALSE;
	}

	if (tv_output_config_data.tv_output_data_format==TV_DATA_YUV420)
	{
		DRV_WriteReg32(TV_CON_Y_DATA_ADDR_REG,tv_output_buffer_address);
		DRV_WriteReg32(TV_CON_U_DATA_ADDR_REG,tv_output_buffer_address+
							tv_output_config_data.tv_output_src_width*tv_output_config_data.tv_output_src_height);
		DRV_WriteReg32(TV_CON_V_DATA_ADDR_REG,tv_output_buffer_address+((tv_output_config_data.tv_output_src_width*
							tv_output_config_data.tv_output_src_height*5)>>2));
	}
	else if (tv_output_config_data.tv_output_data_format==TV_DATA_RGB565)
	{
		DRV_WriteReg32(TV_CON_Y_DATA_ADDR_REG,tv_output_buffer_address);
	}

	UPDATE_TV_CON_REGISTER;
}	/* tv_fb_update() */

/**
 * To configure yuv buffer address
 *
 * @param tv_update_id  TV_DATA_RGB565 or TV_DATA_YUV420
 * @param tv_y_buffer   y buffer address
 * @param tv_u_buffer   u buffer address
 * @param tv_v_buffer   v buffer address
 *
 * @return None.
 */
void tv_fb_update_yuv420(TV_OUT_OWNER_ENUM tv_update_id, kal_uint32 tv_y_buffer,kal_uint32 tv_u_buffer,kal_uint32 tv_v_buffer)
{
	if (tv_output_owner!=tv_update_id)
		ASSERT(0);
	if (tv_output_config_data.tv_output_data_format!=TV_DATA_YUV420)
		ASSERT(0);

	if (tv_src_size_set_flag==KAL_TRUE)
	{
		ENABLE_TV_CONTROLLER;
                tv_src_size_set_flag = KAL_FALSE;
	}

	DRV_WriteReg32(TV_CON_Y_DATA_ADDR_REG,tv_y_buffer);
	DRV_WriteReg32(TV_CON_U_DATA_ADDR_REG,tv_u_buffer);
	DRV_WriteReg32(TV_CON_V_DATA_ADDR_REG,tv_v_buffer);

	UPDATE_TV_CON_REGISTER;
}	/* tv_fb_update_yuv420() */
#endif /* TV_OUT_SUPPORT*/

