#if defined(HORSERACE_SUPPORT)
#include "kal_release.h"
#include "device.h"
kal_bool  tv_fm_camera_is_power_on = KAL_FALSE;
unsigned short NVRAM_HORSERACE_DATA = 0 ;
extern const char gpio_horserace_power_en_pin;
extern const char gpio_horserace_clk_pin	     ;
extern const char gpio_horserace_sdin_pin        ;
extern const char gpio_horserace_latch_pin	     ;
extern void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern void GPO_WriteIO(char data,char port);


#define KEY_BACKLIGHT_MASK                            (0x000003F0)       /* out6,7, 8,9,10,11 */
#define KEY_ENTER_BACKLIGHT_MASK                (0x0000000F)      /* out12, 13, 14, 15 */
#define CAMERA_FLASHLIGHT_MASK                   (0x00000400)       /* out5 */
#define HORSE_RACE_MASK                                 (0x0000F800)      /* out0,1,2,3,4 */
#define nor __asm{NOP};
static int noke_drv_pre_light_parameter = 0x00000000;

void noke_drv_horse_race_io_delay(int times)
{
	int i = times;
	while(i--)
	{
		nor;
	}
}

void noke_drv_horse_race_set( int para )
{
/*
  *   @para :
  *    out0   ~   out15
  *    bit15  ~    bit0
  *   @out sequence : out15-> out0
  */
	int i = 0;
	int v = 0;
	//noke_dbg_printf("\r Hongzhe.liu: noke_drv_horse_race_set = 0x%04x \n", para);
	noke_drv_horse_race_io_delay(20);
	GPIO_WriteIO(0, gpio_horserace_latch_pin);
	GPIO_WriteIO(0, gpio_horserace_clk_pin);
	GPIO_WriteIO(0, gpio_horserace_sdin_pin);
	for( i=0; i<=15; i++)
	{
		v = para & 0x0000FFFF  & ( 0x0001<<i );
		if( v!=0 )
		{
			GPIO_WriteIO(1, gpio_horserace_sdin_pin);
		}else{
			GPIO_WriteIO(0, gpio_horserace_sdin_pin);
		}
		noke_drv_horse_race_io_delay(14);
		GPIO_WriteIO(1, gpio_horserace_clk_pin);
		noke_drv_horse_race_io_delay(2);
		GPIO_WriteIO(0, gpio_horserace_clk_pin);
		noke_drv_horse_race_io_delay(14);
	}
	noke_drv_horse_race_io_delay(4);
	GPIO_WriteIO(1, gpio_horserace_latch_pin);
	noke_drv_horse_race_io_delay(8);
	GPIO_WriteIO(0, gpio_horserace_latch_pin);
	noke_drv_horse_race_io_delay(14);

	noke_drv_pre_light_parameter = para;
}


void noke_drv_horse_race_light(int lights)
{
	int para = ( lights & HORSE_RACE_MASK )| ( noke_drv_pre_light_parameter & (~HORSE_RACE_MASK));
	//noke_dbg_printf("\r Hongzhe.liu: noke_drv_horse_race_light = 0x%04x \n", lights);
	if( (lights != 0x0000 && para != 0x0000 ) || (lights == 0x0000 && para == 0x0000 ))
		noke_drv_horse_race_set(  para  );
	kal_sleep_task(10);
}

void noke_drv_horse_race_keypad_backlight(int lights)
{
	int para = ( lights & KEY_BACKLIGHT_MASK )| ( noke_drv_pre_light_parameter & (~KEY_BACKLIGHT_MASK));
	//noke_dbg_printf("\r Hongzhe.liu: noke_drv_horse_race_keypad_backlight = 0x%04x \n", lights);
	noke_drv_horse_race_set(  para  );
}

void noke_drv_horse_race_keyenter_backlight(int lights)
{
	int para = ( lights & KEY_ENTER_BACKLIGHT_MASK )| ( noke_drv_pre_light_parameter & (~KEY_ENTER_BACKLIGHT_MASK));
	//noke_dbg_printf("\r Hongzhe.liu: noke_drv_horse_race_keyenter_backlight = 0x%04x \n", lights);
	noke_drv_horse_race_set(  para  );
}

void noke_drv_horse_race_camera_flashlight(int lights)
{
	int para = ( lights & CAMERA_FLASHLIGHT_MASK )| ( noke_drv_pre_light_parameter & (~CAMERA_FLASHLIGHT_MASK));
	//noke_dbg_printf("\r Hongzhe.liu: noke_drv_horse_race_camera_flashlight = 0x%04x \n", lights);
	noke_drv_horse_race_set(  para  );
}


extern void PowerOnForDevices(void);
extern void PowerOffForDevices(void);	

void PowerOnForDevices(void)
{
	//noke_dbg_printf("\r Hongzhe.liu : PowerOnForDevices  \n");
	if( tv_fm_camera_is_power_on == KAL_FALSE )
	{
		GPO_ModeSetup(gpio_horserace_power_en_pin, 0);
		GPO_WriteIO(1, gpio_horserace_power_en_pin);  
	}
}

void PowerOffForDevices(void)
{
	//noke_dbg_printf("\r Hongzhe.liu : PowerOffForDevices  \n");
	if( tv_fm_camera_is_power_on == KAL_FALSE )
	{
		GPO_ModeSetup(gpio_horserace_power_en_pin, 0);
		GPO_WriteIO(0, gpio_horserace_power_en_pin);  
	}
}



void HorseRace_PowerOn(void) 
{ 
        GPIO_ModeSetup(gpio_horserace_latch_pin,0); 
        GPIO_ModeSetup(gpio_horserace_sdin_pin, 0); 
        GPIO_ModeSetup(gpio_horserace_clk_pin, 0); 

        GPIO_InitIO(1, gpio_horserace_latch_pin); 
        GPIO_InitIO(1, gpio_horserace_sdin_pin); 
        GPIO_InitIO(1, gpio_horserace_clk_pin); 

        GPIO_WriteIO(0, gpio_horserace_latch_pin);/*锁存*/ 
        GPIO_WriteIO(0, gpio_horserace_sdin_pin);/*输入数据*/ 
        GPIO_WriteIO(0, gpio_horserace_clk_pin);/*时钟*/ 
} 

void HorseRace_PowerOff(void) 
{ 
        GPIO_ModeSetup(gpio_horserace_latch_pin,0); 
        GPIO_ModeSetup(gpio_horserace_sdin_pin, 0); 
        GPIO_ModeSetup(gpio_horserace_clk_pin, 0); 

        GPIO_InitIO(1, gpio_horserace_latch_pin); 
        GPIO_InitIO(1, gpio_horserace_sdin_pin); 
        GPIO_InitIO(1, gpio_horserace_clk_pin); 

        GPIO_WriteIO(0, gpio_horserace_sdin_pin);/*输入数据*/ 
        GPIO_WriteIO(0, gpio_horserace_clk_pin);/*时钟*/ 
        GPIO_WriteIO(0, gpio_horserace_latch_pin);/*锁存*/     
} 

void HorseRace_OpenLED(void)
{
	PowerOnForDevices();
	kal_sleep_task(4); 
	HorseRace_PowerOn();
 }

void HorseRace_CloseLED(void)
{
	noke_drv_horse_race_set(0);
}

char  HorseRace_PowerIsOpen(void)
{
	char flags = 0 ;
	flags=  GPO_ReturnDout(gpio_horserace_power_en_pin);
	if( flags == 1)	
		return 1;
	else
		return 0;
}

void HorseRace_CloseLedPower(void)
{
	 HorseRace_PowerOff();
	  PowerOffForDevices();
}


#ifdef __MAIN_CAMERA_WITH_FLASH__
/*****************************************************************************
 * FUNCTION
 *  noke_drv_horse_race_camera_flash_light_on
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void noke_drv_horse_race_camera_flash_light_on(kal_bool light_on)
{
/*
 *  因为跑马灯芯片和camera 、 TV 共用LDO， 所以拍照闪光时不能关LDO
 */
	if( light_on )
	{
		PowerOnForDevices();
		noke_drv_horse_race_camera_flashlight(0x0400); 
	}else{
		PowerOnForDevices();
		noke_drv_horse_race_camera_flashlight(0x0000);
	}
}
#endif  /* __MAIN_CAMERA_WITH_FLASH__ */

#ifdef KEY_ENTER_BACKLIGHT_SUPPORT
#define HORSE_RASE_TMR_HANDLE (0x12)
/*****************************************************************************
 * FUNCTION
 *  noke_drv_horse_race_camera_flash_light_on_timer
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int f_lights_index = 0;
int enter_key_style_array[]={
	0x000F, /* out12, 13, 14, 15 */
	0x0007, /* out12, 13, 15 */
	0x0003, /* out12, 13 */
	0x0002, /* out12 */
	0x0000, 
	0x0008, /* out12 */
	0x0004, /* out13 */
	0x0001, /* out15 */
	0x0002, /* out14 */
	0x0000
	};

void noke_drv_horse_race_keyenter_round_light_on_timer_handler(void * index)
{
	kal_uint8 horse_race_tmr_handle = HORSE_RASE_TMR_HANDLE;
	kal_bool ret = KAL_FALSE;
	int lights = enter_key_style_array[*((int *)index)];
	kal_uint16 horse_race_tmr_repeat = 10; /*30ms :  1s = 100ticks, 0.1s = 10ticks */
	GPTI_StopItem(horse_race_tmr_handle);

	noke_drv_horse_race_keyenter_backlight( lights );

	f_lights_index++;

	if( f_lights_index >= sizeof(enter_key_style_array)/sizeof(int) )
	{
		f_lights_index = 0;
		return;
	}

	do{
       	ret = GPTI_StartItem(horse_race_tmr_handle,
                  horse_race_tmr_repeat,
                  noke_drv_horse_race_keyenter_round_light_on_timer_handler,
                  (void *)(&f_lights_index));
	}while( ret== KAL_FALSE );
}


/*****************************************************************************
 * FUNCTION
 *  noke_drv_horse_race_camera_flash_light_on
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void noke_drv_horse_race_keyenter_round_light_on(gpio_device_keyenter_backlight_typedef style)
{
	PowerOnForDevices();
	switch( style )
	{
	case KEY_ENTER_BK_LIGHT_ALL_OFF:
		noke_drv_horse_race_keyenter_backlight(0x0000);  
		break;
	case KEY_ENTER_BK_LIGHT_ALL_ON:
		noke_drv_horse_race_keyenter_backlight(0x000F); // out12, 13, 14, 15
		break;
	case KEY_ENTER_BK_LIGHT_CIRCLE:
		f_lights_index = 0;
		noke_drv_horse_race_keyenter_round_light_on_timer_handler((void *)&f_lights_index);
		#if 0
		noke_drv_horse_race_keyenter_backlight(0x000F); // out12, 13, 14, 15
		noke_drv_horse_race_keyenter_backlight(0x0007); // out12, 13, 14, 15
		noke_drv_horse_race_keyenter_backlight(0x0003); // out12, 13, 14, 15
		noke_drv_horse_race_keyenter_backlight(0x0002); // out12, 13, 14, 15
		noke_drv_horse_race_keyenter_backlight(0x0000); 
		noke_drv_horse_race_keyenter_backlight(0x0008); // out12
		noke_drv_horse_race_keyenter_backlight(0x0004); // out13
		noke_drv_horse_race_keyenter_backlight(0x0001); // out15
		noke_drv_horse_race_keyenter_backlight(0x0002); // out14
		noke_drv_horse_race_keyenter_backlight(0x0000);  
		#endif
		break;
	default:
		noke_drv_horse_race_keyenter_backlight(0x0000);  
		break;
	}


	//PowerOffForDevices();
}
#endif /* KEY_ENTER_BACKLIGHT_SUPPORT */

void HorseRace_KeyPadBackLightOn(void)
{
      PowerOnForDevices();
	noke_drv_horse_race_keypad_backlight(0x0300);  //D7, D8(out6, out7) key backlight
}
void HorseRace_KeyPadBackLightOff(void)
{
	noke_drv_horse_race_keypad_backlight(0x0000);
	PowerOffForDevices();	
}


/***************  效果*****************/
/* ***********循环亮 ************ */
void HorseRace_Circle(void)
{
	/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off

       noke_drv_horse_race_light(0x0800);  //D5
	noke_drv_horse_race_light(0x1000);  //D4
	noke_drv_horse_race_light(0x2000);  //D3
	noke_drv_horse_race_light(0x4000);  //D2
	noke_drv_horse_race_light(0x8000);  //D1

       noke_drv_horse_race_light(0x0600);  //D6,D7
       noke_drv_horse_race_light(0x0140);  //D10,D8
       noke_drv_horse_race_light(0x0030);  //D11,D12
       noke_drv_horse_race_light(0x0088);  //D9,D13

	noke_drv_horse_race_light(0x0000); //all off
	
       noke_drv_horse_race_light(0x0800);  //D5
	noke_drv_horse_race_light(0x1000);  //D4
	noke_drv_horse_race_light(0x2000);  //D3
	noke_drv_horse_race_light(0x4000);  //D2
	noke_drv_horse_race_light(0x8000);  //D1

       noke_drv_horse_race_light(0x0600);  //D6,D7
       noke_drv_horse_race_light(0x0140);  //D10,D8
       noke_drv_horse_race_light(0x0030);  //D11,D12
       noke_drv_horse_race_light(0x0088);  //D9,D13
	
	noke_drv_horse_race_light(0x0000); //all off	   

	noke_drv_horse_race_light(0x0000);
}

/**************  跟着亮 ****************/
// 2 On +1 Off 

void HorseRace_Follow (void)
{
	static int State = 0 ; // State = 0,1,2,3,4,5 count six LED

	/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off

	noke_drv_horse_race_light(0x8000);  //D1
	noke_drv_horse_race_light(0xC000);  //D2
	noke_drv_horse_race_light(0xE000);  //D3
	noke_drv_horse_race_light(0xF000);  //D4
	noke_drv_horse_race_light(0xF800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);

	noke_drv_horse_race_light(0x0000); //all off

	noke_drv_horse_race_light(0x8000);  //D1
	noke_drv_horse_race_light(0xC000);  //D2
	noke_drv_horse_race_light(0xE000);  //D3
	noke_drv_horse_race_light(0xF000);  //D4
	noke_drv_horse_race_light(0xF800);  //D5

	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);
	
	noke_drv_horse_race_light(0x0000);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	State = (State+1) % 5 ;	

}


//Flash Effect 
void HorseRace_Flash (void)
{
	static int State = 0 ; // State = 0,1,2,3,4,5 count six LED

	/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8000);  //D1
	noke_drv_horse_race_light(0xC000);  //D2
	noke_drv_horse_race_light(0xE000);  //D3
	noke_drv_horse_race_light(0xF000);  //D4
	noke_drv_horse_race_light(0xF800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off

	noke_drv_horse_race_light(0xF800);  //D5
	noke_drv_horse_race_light(0xF000);  //D4
	noke_drv_horse_race_light(0xE000);  //D3
	noke_drv_horse_race_light(0xC000);  //D2
	noke_drv_horse_race_light(0x8000);  //D1

	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);
	
	noke_drv_horse_race_light(0x0000);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	State = (State+1) % 4 ;		
}

// 双边同步，单灯走动
void HorseRace_WalkWithBack(void)
{

	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8000);  //D1
	noke_drv_horse_race_light(0x4000);  //D2
	noke_drv_horse_race_light(0x2000);  //D3
	noke_drv_horse_race_light(0x1000);  //D4
	noke_drv_horse_race_light(0x0800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8000);
	noke_drv_horse_race_light(0x4000);
	noke_drv_horse_race_light(0x2000);
	noke_drv_horse_race_light(0x1000);
	noke_drv_horse_race_light(0x0800);

	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	noke_drv_horse_race_light(0x0000);
}

void HorseRace_Walk(void)
{
	noke_drv_horse_race_light(0x0000);   //all off

	noke_drv_horse_race_light(0xC000);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x1800);  //D4
	noke_drv_horse_race_light(0x0800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0xC000);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x1800);  //D4
	noke_drv_horse_race_light(0x0800);  //D5

	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);
	
	noke_drv_horse_race_light(0x0000);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
}



// 爬楼梯
void HorseRace_Step(void)
{
	static int State = 0 ; // State = 0,1,2,3,4,5 count six LED

		/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off

       noke_drv_horse_race_light(0x0800);  //D5
	noke_drv_horse_race_light(0x1000);  //D4
	noke_drv_horse_race_light(0x2000);  //D3
	noke_drv_horse_race_light(0x4000);  //D2
	noke_drv_horse_race_light(0x8000);  //D1

       noke_drv_horse_race_light(0x0600);  //D6,D7
       noke_drv_horse_race_light(0x0140);  //D10,D8
       noke_drv_horse_race_light(0x0030);  //D11,D12
       noke_drv_horse_race_light(0x0088);  //D9,D13

	noke_drv_horse_race_light(0x0000); //all off
	
       noke_drv_horse_race_light(0x0800);  //D5
	noke_drv_horse_race_light(0x1000);  //D4
	noke_drv_horse_race_light(0x2000);  //D3
	noke_drv_horse_race_light(0x4000);  //D2
	noke_drv_horse_race_light(0x8000);  //D1

       noke_drv_horse_race_light(0x0600);  //D6,D7
       noke_drv_horse_race_light(0x0140);  //D10,D8
       noke_drv_horse_race_light(0x0030);  //D11,D12
       noke_drv_horse_race_light(0x0088);  //D9,D13

	noke_drv_horse_race_light(0x0000); //all off	   

	State = (State+1) % 12 ;	
}


// 两边交叉走
void HorseRace_CrossWalk(void)
{
/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}


// 两边三灯走同向
void HorseRace_TriWalkWithBack(void)
{
/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);
	
	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	noke_drv_horse_race_light(0x0000);
}

// 两边三灯走同向
void HorseRace_TriWalk(void)
{
/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}


// 两边三灯走相向
void HorseRace_TriOppWalkWithBack(void)
{
/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}

// 两边三灯走相向
void HorseRace_TriOppWalk(void)
{
/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)

	noke_drv_horse_race_light(0x0000);
}


// 两路线
void HorseRace_TwoLine(void)
{
/*第一个灯亮0.2s*/
	noke_drv_horse_race_light(0x0000);   //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	//noke_drv_horse_race_light(0x0800);
	//noke_drv_horse_race_light(0x0400);
	
	noke_drv_horse_race_light(0x0000); //all off
	
	noke_drv_horse_race_light(0x8800);  //D1
	noke_drv_horse_race_light(0x6000);  //D2
	noke_drv_horse_race_light(0x3000);  //D3
	noke_drv_horse_race_light(0x6000);  //D4
	noke_drv_horse_race_light(0x8800);  //D5
	
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}

void HorseRace_Music_StepOne(void)
{
	noke_drv_horse_race_light(0x8000);  //D1
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
	
}

void HorseRace_Music_StepTwo(void)
{
	noke_drv_horse_race_light(0xc000);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}

void HorseRace_Music_StepThree(void)
{
	noke_drv_horse_race_light(0xE000);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}

void HorseRace_Music_StepFour(void)
{
	noke_drv_horse_race_light(0xF000);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
}

void HorseRace_Music_StepFive(void)
{
	noke_drv_horse_race_light(0xF800);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0008);
	
	noke_drv_horse_race_light(0x0004);
	
	noke_drv_horse_race_light(0x0008);
	noke_drv_horse_race_light(0x0010);
	noke_drv_horse_race_light(0x0020);
	noke_drv_horse_race_light(0x0040);
	noke_drv_horse_race_light(0x0080);
	noke_drv_horse_race_light(0x0100);

	noke_drv_horse_race_light(0x0008); //D13(out12)
       noke_drv_horse_race_light(0x0004); //D14(out13)
	noke_drv_horse_race_light(0x0002); //D15(out14)
	noke_drv_horse_race_light(0x0001); //D16(out15)
	
	noke_drv_horse_race_light(0x0000);
} 

void HorseRace_Music_StepSix(void)
{
	noke_drv_horse_race_light(0xFFFF);
}

  


#endif
