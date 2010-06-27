/* 2009.04.14 added by hongzhe.liu for motion sensor + */
#if defined(__DIRECTION_SENSOR_SUPPORT__)
#include 	"kal_release.h"
#include 	"stack_common.h"  
#include 	"stack_msgs.h"
#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"stacklib.h"
#include    "stack_timer.h"      /*stack_timer_struct....definitions*/
#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "adc.h"
#include    "drvsignals.h"
#include    "eint.h"
#include    "batvalue.h"
#include     "afe.h"
#include     "intrctrl.h"
#include     "uart_sw.h"
#include     "bmt.h"
#include "stack_ltlcom.h"

extern const unsigned char MOTION_SENSOR_EINT_NO1 ;
extern const unsigned char MOTION_SENSOR_EINT_NO2 ;
kal_uint8  gMotionSensor_EINT_NO1 = EINT_CHANNEL_NOT_EXIST;
kal_uint8  gMotionSensor_EINT_NO2 = EINT_CHANNEL_NOT_EXIST;
unsigned char DIRECTION_SENSOR_H_EINT_NO ;
unsigned char DIRECTION_SENSOR_V_EINT_NO ;
void Direct_Sensor_H_EINT_HISR(void);
void Direct_Sensor_V_EINT_HISR(void);
kal_bool               direct_sensor_h_state=LEVEL_HIGH;
kal_bool               direct_sensor_v_state=LEVEL_HIGH;
kal_bool               direct_sensor_h_inturrupt_priority = LEVEL_LOW;
kal_bool               direct_sensor_v_inturrupt_priority = LEVEL_LOW;


#define DIRECT_SENSOR_DEBOUNCE_TIME (20)
#define MSG_ID_DIRECT_SENSOR (MSG_ID_END + 1)

#define DIRECTION_SENSOR_TMR_HANDLE (0x10)

#define MYQUEUE         ilm_struct
#define oslSrcId        src_mod_id
#define oslDestId       dest_mod_id
#define oslMsgId        msg_id
#define oslSapId        sap_id
#define oslDataPtr      local_para_ptr
#define oslPeerBuffPtr  peer_buff_ptr

typedef enum _direct_sensor_state_en
{
    DIRECT_SENSOR_STATE_0,
    DIRECT_SENSOR_STATE_90,
    DIRECT_SENSOR_STATE_180,
    DIRECT_SENSOR_STATE_270
} direct_sensor_state_en;

direct_sensor_state_en g_dirct_sensor_state;


void Direction_sensor_sleep_in_handler()
{
	//EINT_DISABLE(DIRECTION_SENSOR_H_EINT_NO);
	//EINT_DISABLE(DIRECTION_SENSOR_V_EINT_NO);
}

void Direction_sensor_sleep_out_handler()
{
	//EINT_ENABLE(DIRECTION_SENSOR_H_EINT_NO);
	//EINT_ENABLE(DIRECTION_SENSOR_V_EINT_NO);
}
direct_sensor_state_en Direct_Sensor_Get_Sensor_State(void)
{
    return g_dirct_sensor_state;
}

extern void OslIntMsgSendExtQueue(MYQUEUE *Message);
void Direct_Sensor_Set_Sensor_State(void)
{
/*

                                        V
                                        high
                                         |
              H     high <------+-------->   low
                                         |
                                         low

V               H
low            high                 normal left             180
                 low                  normal right           0
high           high                 convert left            90
                 low                  convert right          270


*/


	MYQUEUE Message;	

	if(direct_sensor_h_state && direct_sensor_v_state)
	{
		g_dirct_sensor_state = DIRECT_SENSOR_STATE_90;
		Message.oslMsgId = MSG_ID_MSENSOR_DIRECTION_90;
		//noke_dbg("====>  Sensor direction : 90 \n\r");
	}

	else if(direct_sensor_h_state && !direct_sensor_v_state)
	{
		g_dirct_sensor_state = DIRECT_SENSOR_STATE_180;
		Message.oslMsgId = MSG_ID_MSENSOR_DIRECTION_180;
		//noke_dbg("====>  Sensor direction : 180 \n\r");
	}

	else if(!direct_sensor_h_state && direct_sensor_v_state)
	{
		g_dirct_sensor_state = DIRECT_SENSOR_STATE_270;
		Message.oslMsgId = MSG_ID_MSENSOR_DIRECTION_270;
		//noke_dbg("====>  Sensor direction : 270 \n\r");
	}

	else if(!direct_sensor_h_state && !direct_sensor_v_state)
	{
		g_dirct_sensor_state = DIRECT_SENSOR_STATE_0;
		Message.oslMsgId = MSG_ID_MSENSOR_DIRECTION_0;
		//noke_dbg("====>  Sensor direction : 0 \n\r");
	}   

	else
	{
		// Nothing here !!!
	}

	Message.oslSrcId = MOD_MMI;
	Message.oslDestId =MOD_MMI;
	Message.oslDataPtr = NULL;
	Message.oslPeerBuffPtr = NULL;

	OslIntMsgSendExtQueue(&Message);
}

void Direction_Sensor_state_Filter()
{
	kal_uint8 direction_sensor_tmr_handle = DIRECTION_SENSOR_TMR_HANDLE;
	kal_uint16 direction_sensor_tmr_repeat = 50; /* 1s = 100ticks, 0.1s = 10ticks */
	kal_bool ret = KAL_FALSE;
	//noke_dbg_printf("\rHongzhe.Liu : Direction_Sensor_state_Filter ... \n");
	
	GPTI_StopItem(direction_sensor_tmr_handle);

	kal_sleep_task(100);
	do{
       	ret = GPTI_StartItem(direction_sensor_tmr_handle,
                  direction_sensor_tmr_repeat,
                  Direct_Sensor_Set_Sensor_State,
                  NULL);
		//noke_dbg_printf("\rHongzhe.Liu : Direction_Sensor_state_Filter : start ret=%d... \n", ret);
	}while( ret== KAL_FALSE );
}
void Direct_Sensor_H_EINT_HISR(void)
{
	if (direct_sensor_h_inturrupt_priority == LEVEL_LOW)
	{
		direct_sensor_h_state = LEVEL_LOW;
		//noke_dbg(" Interrupt: Direct_Sensor_H Level_LOW \n\r");
	}
	else
	{
		direct_sensor_h_state = LEVEL_HIGH;
		//noke_dbg(" Interrupt: Direct_Sensor_H Level_HIGH \n\r");
	}
	//noke_dbg(" \rInterrupt: Direct_Sensor_H  \n");

	Direction_Sensor_state_Filter();


	//EINT_SW_Debounce_Modify(DIRECTION_SENSOR_H_EINT_NO,DIRECT_SENSOR_DEBOUNCE_TIME);
	direct_sensor_h_inturrupt_priority = !direct_sensor_h_inturrupt_priority;
	EINT_Set_Polarity(DIRECTION_SENSOR_H_EINT_NO,  direct_sensor_h_inturrupt_priority);
}

void Direct_Sensor_V_EINT_HISR(void)
{

	if (direct_sensor_v_inturrupt_priority == LEVEL_LOW)
	{
		direct_sensor_v_state = LEVEL_LOW;
		//noke_dbg(" Interrupt: Direct_Sensor_v Level_LOW \n\r");
	}
	else
	{
		direct_sensor_v_state = LEVEL_HIGH;
		//noke_dbg(" Interrupt: Direct_Sensor_v Level_HIGH \n\r");
	}
	//noke_dbg(" \rInterrupt: Direct_Sensor_V  \n");

	Direction_Sensor_state_Filter();

	
	//EINT_SW_Debounce_Modify(DIRECTION_SENSOR_V_EINT_NO,DIRECT_SENSOR_DEBOUNCE_TIME);
	direct_sensor_v_inturrupt_priority = !direct_sensor_v_inturrupt_priority;
	EINT_Set_Polarity(DIRECTION_SENSOR_V_EINT_NO,  direct_sensor_v_inturrupt_priority);
}

void EINT_Motion_Sensor_Registration()
{
	if( gMotionSensor_EINT_NO1 !=EINT_CHANNEL_NOT_EXIST )
	{
		DIRECTION_SENSOR_V_EINT_NO = gMotionSensor_EINT_NO1;
	}else{
	 	DIRECTION_SENSOR_V_EINT_NO = MOTION_SENSOR_EINT_NO1;
	}

	if( gMotionSensor_EINT_NO2 !=EINT_CHANNEL_NOT_EXIST )
		DIRECTION_SENSOR_H_EINT_NO = gMotionSensor_EINT_NO2;
	else
		DIRECTION_SENSOR_H_EINT_NO = MOTION_SENSOR_EINT_NO2;

	  EINT_Registration(DIRECTION_SENSOR_H_EINT_NO,KAL_TRUE,direct_sensor_h_inturrupt_priority,Direct_Sensor_H_EINT_HISR, KAL_TRUE);
	  EINT_Registration(DIRECTION_SENSOR_V_EINT_NO,KAL_TRUE,direct_sensor_v_inturrupt_priority,Direct_Sensor_V_EINT_HISR, KAL_TRUE);
}

#endif
/* 2009.04.14 added by hongzhe.liu for motion sensor - */
