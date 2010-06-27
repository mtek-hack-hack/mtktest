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
 *   w32_dummy_drv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Driver dummy functions for WIN32 environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <windows.h>
#include <math.h>
#include "time.h"

#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"

#include "stacklib.h"
#include "stack_timer.h"

#include "syscomp_config.h"
#include "task_config.h"

#include "device.h"
//#include "w32_timers.h"
#include "rtc_sw.h"
#include "l4a.h"
#include "uart_sw.h"
#include "drvsignals.h"
//#include "l1audio.h"

#include "alerter_sw.h"
#include "init.h"

#include "lcd_if.h"
#include "pmu_sw.h"
#include "gpio_sw.h"

ALterNoteStruct ALterNote;
//This function is to set Alerter output is pdm or pwm
void ALERTER_Output(kal_uint8 outtype)
{
}
/*
* FUNCTION
*  ALERTER_Config
*
* DESCRIPTION
*     Alerter initial function
*
* CALLS
*  It is called before access the alerter.
*
* PARAMETERS
*  mode: m1,m2,m3
*  Clock:   c13_1MHZ,
*     c13_2MHZ,
*     c13_4MHZ,
*     c13_8MHZ
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void ALERTER_Config(ALMode mode, ALClock Clock)
{
}

void ppp_frame_decode_hw(){}
void ppp_frame_encode_hw(){}

void GPT_init(kal_uint8 timerNum, void (*GPT_Callback)(void))
{
}

void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload)
{

}

void UART_SleepOnTx_Enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag)
{
}

/*
* FUNCTION
*	GPTI_GetHandle
*
* DESCRIPTION
*   	GPT handle function, each module should get handle once(only one).
*
* CALLS
*
*
* PARAMETERS
*	*handle = handle value
*
* RETURNS
*	KAL_TRUE, Action is ok.
*  KAL_FALSE, Action is failed.
*
* GLOBALS AFFECTED
*   external_global
*/
/*actual value = 0~31*/
kal_uint8 GPTI_GetHandle(kal_uint8 *handle){return 0;}
char GPIO_ReturnDir(char port){return 0;}
char GPIO_ReturnDout(char port){return 0;}
char GPO_ReturnDout(char port){return 0;}
char GPIO_ReturnMode(char port){return 0;}
char GPO_ReturnMode(char port){return 0;}
void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada){}
void GPIO_SetClkOut(char clk_num, gpio_clk_mode mode){}
void GPIO_SetDebugMode(kal_bool enable){}


/* LCD extern variable */
volatile LCD_OPERATION_STATE_ENUM main_lcd_operation_state;
lcd_frame_update_struct main_lcd_fb_update_para;

volatile LCD_OPERATION_STATE_ENUM sub_lcd_operation_state;
lcd_frame_update_struct sub_lcd_fb_update_para;
kal_uint8 wait_lcd_config_flag=KAL_FALSE;
#ifdef __SYNC_LCM_SUPPORT__
   kal_uint8 wait_lcd_restore_config_flag;   
   kal_uint8 sync_lcm_channel_number;
   kal_bool sync_lcm_enable_mode;
   kal_timerid sync_lcm_timer_handle = 0;
   kal_uint8 sync_lcm_delay_flag;
#endif

/* LCD dummy functions */
void assert_lcd_fb_update(){}
void reset_lcd_if(){}
void lcd_sleep_in(){}
void lcd_sleep_out(){}
void lcd_power_on(){}
void lcd_bright_level(){}

kal_uint8 lcd_get_parameter(kal_uint8 lcd_id,lcd_func_type type){}
void lcd_set_bias(){}
void lcd_set_contrast(){}
void lcd_set_linerate(){}
void lcd_set_temp_compensate(){}
void lcd_screen_on(kal_uint8 lcd_id, kal_bool on){}
void LCD_preview(kal_uint32 layer, kal_uint32 buffer1, kal_uint32 buffer2 ){}
void LCD_recode_preview(kal_uint32 layer, kal_uint32 buffer){}
void LCD_config_fw_layer_address(kal_uint32 addr){}
void lcd_reset_preview(void){}
void LCD_config_fullvideo_layer_address(kal_uint32 layer, kal_uint32 addr){}

kal_bool lcd_is_busy(void)
{
    return KAL_FALSE;
}
void lcd_power_ctrl(kal_bool enable){}

kal_uint8 get_lcd_hw_layer_rotate_value(kal_uint32 hw_layer)
{ return 0;
}
kal_bool lcd_ESD_check(void) { return KAL_TRUE; }
void lcd_stop_jpeg_video_play(kal_uint8 lcd_id){}
void lcd_jpeg_video_play(kal_bool display_jpeg, lcd_frame_update_struct *lcd_para){}
void lcd_start_jpeg_video_play(lcd_frame_update_struct *lcd_para){}

void PWM2_Init(void)
{
}
void PWM_Init(void)
{
}


void Modify_PowerOn_Type(kal_uint8 power_type)/*TY add 0218*/
{
}

kal_bool INT_USBBoot(void){return 0;}


void DRVPDN_Disable(kal_uint32 addr,kal_uint16 code,kal_uint8 handle){}
void DRVPDN_Enable(kal_uint32 addr,kal_uint16 code,kal_uint8 handle){}

extern void w32_audio_init(void);

kal_bool w32_is_poweron=KAL_FALSE;
static time_t poweron_time;
static time_t poweron_now;

void mcd_dump_max_buffer_size(void );

void DRV_POWEROFF(void )
{
}
void DRV_POWERON(void)
{
	t_rtc rtctime;
	struct tm when;

	w32_is_poweron = KAL_TRUE;

	time(&poweron_time);
	when = *localtime(&poweron_time);

	rtctime.rtc_sec = when.tm_sec;
	rtctime.rtc_min = when.tm_min;
	rtctime.rtc_hour = when.tm_hour;
	rtctime.rtc_day = when.tm_mday;
	rtctime.rtc_mon = when.tm_mon+1;
	rtctime.rtc_wday = when.tm_wday+1;
	rtctime.rtc_year = when.tm_year-100;

	RTC_InitTC_Time(&rtctime);
	w32_audio_init();
//	mcd_dump_max_buffer_size();
}
void DRV_RESET(void)
{

}
void RTC_GetALTime(t_rtc *rtctime)
{
}
void RTC_SetAlarm(t_rtc *rtctime)
{
}
void RTC_Config(kal_uint8 AL_EN,kal_uint8 TC_EN)
{
}
void RTC_InitTC_Time(t_rtc *rtctime)
{
	struct tm when;

	when.tm_sec     = rtctime->rtc_sec  ;
	when.tm_min     = rtctime->rtc_min  ;
	when.tm_hour    = rtctime->rtc_hour ;
	when.tm_mday    = rtctime->rtc_day  ;
	when.tm_mon     = rtctime->rtc_mon  -1;
	when.tm_wday    = rtctime->rtc_wday -1;
	when.tm_year    = rtctime->rtc_year +100;

	poweron_time = mktime(&when);
	time(&poweron_now);
}
void RTC_init(void (*RTC_TCCallback)(void),void (*RTC_ALCallback)(void))
{
}
void GPIO_WriteIO(char data,char port)
{
}
void GPO_WriteIO(char data,char port)
{
}
void GPIO_InitIO_FAST(char direction, char port)
{
}
char GPIO_ReadIO_FAST(char port)
{
   return 0;
}
void GPIO_WriteIO_FAST(char data, char port)
{
}
// main lcd backlight
extern int		mainlcd_backlight_level;
extern void w32_light_black_draw_mmi(void);
void PWM_level(kal_uint8 level)
{
	mainlcd_backlight_level = level +4; // from 4 ~ 9
	w32_light_black_draw_mmi();
//	w32_lcd_update(MAIN_LCD,gdi_w32_lcd_buffer[0]);
//	w32_lcd_update(SUB_LCD,gdi_w32_lcd_buffer[1]);
}
void PWM2_level(kal_uint8 level)
{
}
void Alter_level(kal_uint8 level)
{
}
kal_uint8 PWM1_GetCurrentLevel(void)
{
	return 0;
}
kal_uint8 PWM2_GetCurrentLevel(void)
{
	return 0;
}
kal_uint8 Alter_GetCurrentLevel(void)
{
	return 0;
}

kal_uint8 adc_sche_create_object(module_type ownerid, kal_uint8 adc_channel,kal_uint32 period, kal_uint8 evaluate_count, kal_bool send_primitive)
{
	return 0;
}


void RTC_GetTime(t_rtc *rtctime )
{
	struct tm when;
	time_t now;

	time(&now);
	now = (now-poweron_now) + poweron_time;
	when = *localtime(&now);

	rtctime->rtc_sec = when.tm_sec;
	rtctime->rtc_min = when.tm_min;
	rtctime->rtc_hour = when.tm_hour;
	rtctime->rtc_day = when.tm_mday;
	rtctime->rtc_mon = when.tm_mon+1;
	rtctime->rtc_wday = when.tm_wday+1;

	rtctime->rtc_year = when.tm_year-100;
}

void CALLBACK RTC_TCintr(HWND hwnd,UINT uMsg,UINT idEvent, DWORD dwTime)
{
	ilm_struct *RTC_ilm;
	RTC_Primitive *RTC_Prim;

	if(!w32_is_poweron) return;


	RTC_ilm = allocate_ilm(MOD_RTC_HISR);
	RTC_Prim = (RTC_Primitive*)
				construct_local_para(sizeof(RTC_Primitive), TD_CTRL);
	RTC_Prim->rtc_ind = RTC_TC_IND;
	RTC_ilm->src_mod_id = MOD_RTC_HISR;
	RTC_ilm->dest_mod_id = MOD_UEM;
	RTC_ilm->sap_id = DRIVER_PS_SAP;
	RTC_ilm->msg_id = MSG_ID_DRVUEM_RTC_PERIOD_IND;
	RTC_ilm->local_para_ptr = (local_para_struct *)RTC_Prim;
	RTC_ilm->peer_buff_ptr = NULL;
	msg_send_ext_queue(RTC_ilm);
}


/*
void mcd_dump_max_buffer_size(void )
{
	static kal_uint32 XXX[10240];
	int i,size;
	kal_uint8 *name;
	mcd_init();
	for(i=0;i<MCD_TABLE_SIZE;i++)
	if((name = mcd_get_structure_name(i))!=NULL)
	{
		size = mcd_pseudo_alloc(i,XXX,sizeof(XXX));
		printf("%10d %s\n",size/8,name);
	}
	exit(0);
}*/
void init_sccb(void){}
void sccb_write(kal_uint8 cmd, kal_uint8 parameter){}
kal_uint8 sccb_read(kal_uint8 cmd){return 0;}
void MSDC_GetCardStatus(void){}
void sccb_setDelay(kal_uint32 delay) {}
//int L1sim_Get_CardSpeedType(void){return 0;}
void GPIO_InitIO(char direction, char port){}
char GPIO_ReadIO(char port){return 0;}
boot_mode_type system_boot_mode=NORMAL_BOOT;
kal_int32 volt2temp(kal_int32 _volt){return 0;}

//void L1sim_Enable_Enhanced_Speed(kal_bool enable){}


typedef struct {int x;}NOR_MTD_Driver;
NOR_MTD_Driver NORFlashMtd;



void sccb_cont_write    (void){}
void sccb_getMode    (void){}
void sccb_cont_read    (void){}

void UPLL_Enable(void){}
void UPLL_Disable(void){}

void WDT_Restart2(void)
{

}

/* also define in custom_em_dummyDrv.c, must remove either one
void Alter_Start(void)
{

}
void Alter_Configure(kal_uint32 freq, kal_uint8 duty){}

void Alter_Stop(void)
{
}


void PWM1_Start(void)
{
}
void PWM1_Stop(void)
{

}
void PWM1_Configure(void)
{
}


void PWM2_Start(void)
{

}
void PWM2_Stop(void)
{

}
void PWM2_Configure(void)
{
}
*/
/* system service */
void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask){}
void INT_QueryMemoryInfo(kal_uint32 *ext_start, kal_uint32 *ext_len, kal_uint32 *int_start, kal_uint32 *int_len){}
void INT_GetSysMemoryInfo(kal_uint32 **info, kal_uint16* count ) {}
void INT_QueryPowerDownStatus(CONFIG_PDN_TYPE* PDN_ptr){}
void INT_SetPowerDownStatus(CONFIG_PDN_TYPE* PDN_ptr){}
void SLA_RetreiveLoggingBuffer(void){}
//void DMA_GetChannel    (void){}
//void DMA_Config        (void){}
void IRQUnmask         (void){}
void IRQSensitivity    (void){}

void IRQ_Register_LISR (void){}
//void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(void), char* description)
//void OSC_Register_ISR (osc_enum_isr_src  src_idx, osc_type_func_ptr isr_func );

void IRQMask           (void){}
void IRQClearInt       (void){}
//void INT_ExceptionSaveToFlash(void){}
//void INT_ExceptionRecordDump(void){}
//void INT_ExceptionSaveInfo(void){}
//char  INT_Exception_PosY=0;
//kal_error_param error_param_g;
kal_uint32  INT_MemoryDumpFlag=0x00;

//void INT_ExceptionHWReset(void){}
#ifdef NEPTUNE_MMI
/* Prabhjot MoDIS Integration - Uncommented */
void IRQDirectMaskAll(void){}
#endif
//void INT_ExceptionSwitchSP(void){}
//void WDT_Enable(void){}
void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity){}
void EINT_Mask(kal_uint8 eintno){}
void EINT_UnMask(kal_uint8 eintno){}
kal_bool SST_AdvRAMTest(void){return 0;}
kal_bool custom_ifLPSDRAM(void){return 0;}
kal_uint16 lcd_cmd_period_count;
kal_uint8 INT_Exception_Enter = 0;

void INT_VersionNumbers(version_struct * ptr_version)
{
   ptr_version->bb_chip = (kal_char*)"MoDIS";
   ptr_version->dsp_fw = (kal_char*)L"";
   ptr_version->dsp_ptch = (kal_char*)L"";
   ptr_version->mcu_sw = (kal_char*)release_verno();
   ptr_version->mcu_sw_branch = (kal_char*)release_branch();
   ptr_version->bb_board = (kal_char*)release_hw_ver();
}

void tp_task_create(void){}
void tp_task_main(void){}
kal_uint32 Lock2WaysForMPEG4(void)	{return 0;}
void Unlock2WaysForMPEG4(kal_uint32 val) {}

kal_uint32 drv_get_current_time(void)
{
	return 0;
}

kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
	return 0;
}

kal_uint32 drv_get_duration_ms(kal_uint32 previous_time)
{
	return 0;
}/* Max tmp patch */
void DMA_Config_Internal(kal_uint8 dma_no, void *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start){}
void DMA_Stop(kal_uint8 channel){}
kal_uint8 DMA_GetChannel(kal_uint32 DMA_CODE){return 0;}
kal_uint16 GPT_return_current_count(void){return 0;}
void GPT_Start(kal_uint8 timerNum){}
void GPT_Stop(kal_uint8 timerNum){}
void FMR_EvaluateRSSIThreshold(void){}
void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value){}

void pmic_init(void){}
kal_uint8 pmic_chr_status(pmic_chr_stat status)
{
   return 0;
}
kal_uint8 pmic_ldo_status(pmic_ldo ldo)
{
   return 0;
}
void pmic_usb_current_ctrl(usb_current current){}
void pmic_ac_currnet_ctrl(ac_current current){}
void pmic_usb_regulator_enable(kal_bool enable){}
void pmic_speaker_gain(kal_uint8 gain){}
void pmic_chr_enable(kal_bool enable){}
void pmic_chr_pump_enable(kal_bool enable){}
void pmic_vasw_enable(kal_bool enable){}
void pmic_vd_sel(vd_sel sel){}
void pmic_vb_sel(vb_vol sel){}
void pmic_vmc_enable(kal_bool enable){}
void pmic_vsim_sel(sim_vol vol){}
void pmic_speker_enable(kal_bool enable){}
void pmic_vibrator_enable(kal_bool enable){}
void pmic_charge_current_offset(kal_int8 current){}
void pmic_rgb_dim_clk_setting(kal_uint32 clk){}
void pmic_led_enable(pmic_led_type type, kal_bool enable){}
void pmic_led_config(pmic_led_struct *led_conf){}
kal_bool pmic_is_chr_det(chr_type type)
{
   return 0;
}
kal_bool pmic_is_chr_valid(void)
{
   return 0;
}
void pmic_write_to_register_save(kal_uint8 data, kal_uint16 register_index){}
void PMIC_ChrDet_Registration(chr_type type, void (*Callback)(void)){}
void PMIC_HISR(void){}
void pmic_charge_pump_init(kal_uint8 value){}
void pmic_adc_measure_div2(kal_bool enable){}
void pmic_clear_ov(void){}
void pmic_pump_delay(charge_pumpdelay_enum delay){}
void pmic_sim_leveltype(kal_bool enable){}
void pmic_sw_sel(vasw_a_sel_enum value){}
void pmic_vibrator_sel(vibrator_sel_enum value){}
void pmic_usb_chr_enable(kal_bool enable){}
void pmic_customization_init(void){}
void pmic_adc_measure_sel(adc_type sel){}
void pmic_bl_div_bypass(kal_bool enable){}
void pmic_bl_dim_clk_setting(kal_uint32 clk){}
void pmic_chr_pump_current_level(kal_uint32 level){}


kal_uint8 pmic_get_LED_stat(pmic_led_type type)
{
   return 0;
}
kal_uint8 pmic_get_speaker_gain(void)
{
   return 0;
}
kal_uint8 pmic_get_speaker_stat(void)
{
   return 0;
}
kal_uint8 pmic_reg_read(kal_uint16 register_index)
{
   return 0;
}
void pmic_get_BL_dim(kal_bool *div_enable, kal_uint32 *clk){}
void pmic_get_misc_ldo_stat(pmic_misc_stat type, kal_bool *enable){}
void pmic_reg_write(kal_uint8 data, kal_uint16 register_index){}
void pmic_speaker_enable(kal_bool enable){}
void pmic_charging_currnet_ctrl(pmic_charging_current current){}
void pmic_get_rgb_dim(kal_bool   *pump_enable, kal_uint32 *pump_current, kal_uint32 *clk){}
void pmic_get_LED_config(pmic_led_type    type, kal_uint8 *duty,  kal_uint32 *current){}
void pmic_get_ac_usb_status(chr_type   type, kal_bool   *chr_enable, kal_uint32 *current){}
void pmic_vmc_sel(vmc_sel_enum sel){}

void pmic_pwm_level(kal_uint8 level){}
kal_uint8 pmic_pwm_current_level(void)
{
   return 0;
}
void pmic_pwm_configure(kal_uint32 freq, kal_uint8 duty){}
void pmic_pwm_start(void){}

/* Dummy function for Driver using DCM relative API */
kal_uint8 DCM_GetHandle( void )
{
	return 0;
}
void DCM_Enable( kal_uint8 handle )
{

}
void DCM_Disable( kal_uint8 handle )
{

}
/* Dummy function for Driver using DCM relative API */

/* Dummy function for Driver using PMU relative API */
void pmu_init(void){}
pmu_chr_cur_level pmu_ret_chr_current(void)
{
   return 0;
}
kal_bool pmu_get_vrf_status(void)
{
   return 0;
}
void pmu_set_vrf(kal_bool enable){}
void pmu_set_vrf_force(kal_bool enable){}
void pmu_set_vrf_plnmos_dis(kal_bool enable){}
void pmu_set_icalrf(pmu_icalrf_code code){}
void pmu_set_vrf_cal(kal_uint8 value){}
void pmu_set_tpsel(kal_uint8 value){}
void pmu_set_vcore_force(kal_bool enable){}
void pmu_set_icalcore(pmu_icalcore_code code){}
void pmu_set_vcore_sel(kal_uint8 value){}
void pmu_set_vcore_cal(kal_uint8 value){}
void pmu_set_vtcxo_pwrsave(kal_bool enable){}
void pmu_set_vrf_pwrsave(kal_bool enable){}
kal_bool pmu_get_vrtc_staus(void)
{
   return 0;
}
void pmu_set_vrtc_force(kal_bool enable){}
kal_bool pmu_get_vio_status(void)
{
   return 0;
}
kal_bool pmu_get_vm_status(void)
{
   return 0;
}
void pmu_set_vio_force(kal_bool enable){}
void pmu_set_icalio(pmu_icalio_code code){}
void pmu_set_antiudsh_io_dn(kal_bool enable){}
void pmu_set_vio_cal(kal_uint8 value){}
void pmu_set_vm_force(kal_bool enable){}
void pmu_set_icalm(pmu_icalm_code code){}
void pmu_set_antiudsh_m_dn(kal_bool enable){}
void pmu_set_vm_cal(kal_uint8 value){}
kal_bool pmu_get_vsim_status(void)
{
   return 0;
}
void pmu_set_vsim_force(kal_bool enable){}
void pmu_set_icalsim(pmu_icalsim_code code){}
void pmu_set_antiudsh_sim_dn(kal_bool enable){}
void pmu_set_vsim_plnmos_dis(kal_bool enable){}
void pmu_set_vsim_cal(kal_uint8 value){}
void pmu_set_vrtc_step1_cal(kal_uint8 value){}
void pmu_set_vrtc_step2_cal(kal_uint8 value){}
kal_bool pmu_get_vtcxo_status(void)
{
   return 0;
}
void pmu_set_vtcxo_force(kal_bool enable){}
void pmu_set_vtcxo(kal_bool enable){}
void pmu_set_vtcxo_plnmos_dis(kal_bool enable){}
void pmu_set_vtcxo_cal(kal_uint8 value){}
kal_bool pmu_get_va_status(void)
{
   return 0;
}
void pmu_set_va_force(kal_bool enable){}
void pmu_set_va(kal_bool enable){}
void pmu_set_va_cal(kal_uint8 value){}
void pmu_set_vrtc_cal_latch(kal_bool enable){}
void pmu_set_vibr(kal_bool enable){}
void pmu_set_kpled(kal_bool enable){}
void pmu_set_rled(kal_bool enable){}
void pmu_set_gled(kal_bool enable){}
void pmu_set_bled(kal_bool enable){}
void pmu_set_vsim(kal_bool enable){}
void pmu_set_vsim_sel(pmu_vsim_volt  volt){}
kal_bool pmu_is_ovp_occurred(void)
{
   return 0;
}
kal_bool pmu_is_chr_det(void)
{
   return 0;
}
kal_bool pmu_is_bat_on(void)
{
   return 0;
}
kal_bool pmu_is_cv_mode(void)
{
   return 0;
}
void pmu_set_adc_meas_on(kal_bool enable){}
void pmu_set_chron(kal_bool enable){}
void pmu_set_chr_cur_offset(pmu_chr_cur_offset offset){}
void pmu_set_chr_cur_level(pmu_chr_cur_level level){}
void pmu_set_chron_force(kal_bool enable){}
void pmu_set_chr_thermal_thres(pmu_chr_thermal_thres thres){}
void pmu_set_chr_ref_volt(pmu_ref_volt_step step){}
void pmu_set_chr_cv_volt(pmu_vbg_volt volt){}
void pmu_set_uv_sel(pmu_uvlo_volt volt){}
void pmu_set_rbgsel(pmu_rbgsel sel){}
void pmu_set_ibgsel(pmu_ibgsel sel){}
void pmu_set_osc(kal_bool enable){}
void pmu_set_cksel(pmu_cksel sel){}
void pmu_set_vbssel(pmu_vbssel sel){}
void pmu_reset_drv(kal_bool reset){}
void pmu_set_ov_hys_enb(pmu_ov_hys_enb value){}
void pmu_set_ov_thfreeze(pmu_ov_thfreeze value){}
kal_bool pmu_is_pwrkey_deb_disable(void)
{
   return 0;
}
void pmu_vrf_on_enable(kal_bool enable){}
void pmu_set_adc_in_edge(kal_bool positive){}
void pmu_set_fast_slow(kal_bool fast){}
void pmu_set_pwmb_resol(kal_bool four_bits){}
void pmu_set_acc_out_init(kal_uint8 value){}
void pmu_set_cv_rt(kal_uint8 value){}
void pmu_set_mtv_enable(kal_bool enable){}
void pmu_set_gpio_drv(pmu_gpio_drv_strength strength){}
void pmu_set_bias_gen_force(kal_bool enable){}
void pmu_set_sdm_order(pmu_sdm_order order){}
void pmu_set_pid_gain_p(pmu_pid_gain_p gain){}
void pmu_set_pid_gain(pmu_pid_gain gain){}
void pmu_set_pid_gain_d(pmu_pid_gain_d gain){}
void pmu_set_duty_init(kal_uint8 value){}
void pmu_set_vcore_volt(pmu_vcore_volt volt){}
void pmu_set_sdm_fb_en(kal_bool enable){}
void pmu_set_vfbadj(kal_uint8 value){}
void pmu_set_direct_ctrl_en(kal_bool enable){}
void pmu_set_dcv_ck(pmu_dcv_ck clk){}
void pmu_set_isel(pmu_isel sel){}
void pmu_set_adjcksel(kal_uint8 value){}
void pmu_set_manual_mode(pmu_mode_set mode){}
void pmu_set_auto_mode_en(kal_bool enable){}
void pmu_set_mode_cmp(pmu_mode_cmp cmp){}
void pmu_set_ave_current_mode(pmu_mode_ave_current mode){}
void pmu_set_dcv_test_en(kal_bool enable){}
void pmu_set_pfm_max_current(kal_uint8 value){}
void pmu_set_pfm_resistor(kal_uint8 value){}
void pmu_set_ndc_offset(pmu_ndc_offset offset){}
void pmu_set_dcv_trim(kal_uint8 value){}
void pmu_set_iasel(pmu_iasel volt){}
void pmu_set_rsel(pmu_rsel sel){}
kal_bool pmu_get_vusb_status(void)
{
   return 0;
}
void pmu_set_vusb_en_force(kal_bool enable){}
void pmu_set_vusb_en(kal_bool enable){}
void pmu_set_icalusb(pmu_icalusb_code code){}
void pmu_set_antiudsh_usb_dn(kal_bool enable){}
void pmu_set_vusb_plnmos_dis(kal_bool enable){}
void pmu_set_vusb_cal(kal_uint8 value){}
void pmu_set_vfbadj_slp(kal_uint8 value){}
kal_bool pmu_get_vsim2_status(void)
{
   return 0;
}
void pmu_set_vsim2_en_force(kal_bool enable){}
void pmu_set_icalsim2(pmu_icalsim2_code code){}
void pmu_set_antiudsh_sim2_dn(kal_bool enable){}
void pmu_set_vsim2_plnmos_dis(kal_bool enable){}
void pmu_set_vsim2_cal(kal_uint8 value){}
void pmu_set_clk_source_sel(pmu_clk_src_sel source){}
void pmu_set_vtcxo_on_sel(pmu_vtcxo_on_sel sel){}
void pmu_set_vsim_pwr_saving_en(kal_bool enable){}
void pmu_set_vsim2_en(kal_bool enable){}
void pmu_set_vsim2_sel(pmu_vsim_volt volt){}
kal_bool pmu_get_vmc_status(void)
{
   return 0;
}
void pmu_set_vmc_en_force(kal_bool enable){}
void pmu_set_icalmc(pmu_icalmc_code code){}
void pmu_set_antiudsh_mc_dn(kal_bool enable){}
void pmu_set_vmc_plnmos_dis(kal_bool enable){}
void pmu_set_vmc_cal(kal_uint8 value){}
void pmu_set_vmc_en(kal_bool enable){}
void pmu_set_vmc_sel(pmu_vmc_volt volt){}
kal_bool pmu_get_vcamera_status(void)
{
   return 0;
}
void pmu_set_vcamera_en_force(kal_bool enable){}
void pmu_set_icalcamera(pmu_icalcamera_code code){}
void pmu_set_antiudsh_camera_dn(kal_bool enable){}
void pmu_set_vcamera_plnmos_dis(kal_bool enable){}
void pmu_set_vcamera_cal(kal_uint8 value){}
void pmu_set_dcv_slew_ctrl(kal_uint8 value){}
void pmu_set_vcamera_en(kal_bool enable){}
void pmu_set_vcamera_sel(pmu_vcamera_volt volt){}
kal_bool pmu_get_vsw_a_status(void)
{
   return 0;
}
void pmu_set_vsw_a_en_force(kal_bool enable){}
void pmu_set_icalsw(pmu_icalsw_code code){}
void pmu_set_vsw_a_sel(pmu_vsw_a_volt volt){}
void pmu_set_vsw_a_cal(kal_uint8 value){}
void pmu_set_icala(pmu_icala_code code){}
void pmu_set_icaltcxo(pmu_icaltcxo_code code){}
void pmu_set_vsw_a_en(kal_bool enable){}
void pmu_set_oc_fold_en(kal_bool enable){}
void pmu_set_vref_bg(pmu_vref_bg value){}
void pmu_set_thr_sel(pmu_thr_sel value){}
void pmu_set_ldo_soft_st_dis(kal_bool disable){}
void pmu_set_tpsel_led(kal_uint8 value){}
void pmu_set_isense_out_en(kal_bool enable){}
void pmu_set_vbat_out_en(kal_bool enable){}



/* Dummy function for using buffer push and pop */
void Buff_Push(BUFFER_INFO *Buf,kal_uint8 *pushData){}
void Buff_Pop(BUFFER_INFO *Buf,kal_uint8 *popData){}
