/************************************************************************************************
*
*
*         (C) Copyright Telegent Systems, Inc. 2006 All right reserved.
*               Confidential Information
* 
*         TLG1100  DEVICE ID: 0x2c
*
*         Description: TLG1100 I2C timing sample code,code need to OPTIMIZE 
*                          
*         Author:        Zeng Hai
*
*         Last modification : 2006. 05. 22
*************************************************************************************************/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "task_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"
#include "system_inc.h"
#include "uart_sw.h"
#include "stdarg.h"

#include "custom_equipment.h" 
#include "l1audio.h" 
#include "timerevents.h"

#include "gpio_sw.h"

#include "device.h" 
#include "tlg1100i2c.h"
#include "tlg1100.h"


/******************************************************************************************
*              Prototypes
*******************************************************************************************/
/*  2009.06.01 added by hongzhe.liu for tlg1100 gpio/gpo set +*/
extern const char gpio_tlg1100_power_en;
extern const char gpio_tlg1100_reset_pin;
extern const char gpio_tlg1100_i2c_scl;
extern const char gpio_tlg1100_i2c_sda;
/*  2009.06.01 added by hongzhe.liu for tlg1100 gpio/gpo set -*/


void i2c_delay(unsigned int time);
void set_i2c_pin(unsigned char  pin);
void clr_i2c_pin(unsigned char  pin);
unsigned char get_i2c_pin(unsigned char  pin);

void i2c_begin(void);
void i2c_end(void);
void i2c_write_ask(unsigned char flag);
int i2c_read_ack(void);
unsigned char  i2c_read_byte(void);
int i2c_write_byte(unsigned char data);

int gpio_config_bit_as_output( unsigned char pin );
int gpio_config_bit_as_input(unsigned char pin);

/******************************************************************************************
*              Macros
*******************************************************************************************/
int gpio_config_bit_as_output( unsigned char pin )
{
	GPIO_InitIO(1, pin);
	GPIO_ModeSetup( pin, 0 );
	return 0;
}

int gpio_config_bit_as_input(unsigned char pin)
{
	GPIO_InitIO(0, pin);
	GPIO_ModeSetup( pin, 0);
	return 0;
}

/******************************************************************************************
*              Functions
*******************************************************************************************/

void i2c_delay(unsigned int time)
{
/*
	for (time =0; time<64; time++)
		{ asm "nop"}
*/
	int i;
	for( i = 0; i <64* time; i++ );

}

void set_i2c_pin(unsigned char pin)
{
	GPIO_WriteIO( 1, pin );
	//KY_AI_SetBit(pin);
	//KY_AI_EnableBit(pin);
	 //*( ( volatile unsigned short * ) ARMIO_OUT ) |= ( ( unsigned short )( 1 << pin ) );
}
void clr_i2c_pin(unsigned char pin)
{
	GPIO_WriteIO( 0, pin );
	
	//KY_AI_ResetBit(pin);
	//*( ( volatile unsigned short * ) ARMIO_OUT ) &= ~( ( unsigned short )( 1 << pin ) );
}

unsigned char get_i2c_pin(unsigned char pin)
{
	unsigned char ret = 0;
	unsigned int value;

/*	value =	*(volatile unsigned short *)(ARMIO_IN);
	if ((value & pin) == 0)
		ret	= 0;
	else
		ret	= 1;
*/
//	ret = KY_AI_ReadBit(pin);

	ret = GPIO_ReadIO( pin );
	
	return ret;
}

void i2c_begin(void)
{

	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_output(gpio_tlg1100_i2c_sda);

	i2c_delay(I2C_DELAY_UNIT << 0);
	set_i2c_pin(gpio_tlg1100_i2c_sda);	
	i2c_delay(I2C_DELAY_UNIT << 0);
	set_i2c_pin(gpio_tlg1100_i2c_scl);
	i2c_delay(I2C_DELAY_UNIT << 0);
	clr_i2c_pin(gpio_tlg1100_i2c_sda);	
	i2c_delay(I2C_DELAY_UNIT << 0);
	clr_i2c_pin(gpio_tlg1100_i2c_scl);
	i2c_delay(I2C_DELAY_UNIT << 0);
}

void i2c_end(void)
{

	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_output(gpio_tlg1100_i2c_sda);

	i2c_delay(I2C_DELAY_UNIT << 2);
	clr_i2c_pin(gpio_tlg1100_i2c_sda);
	i2c_delay(I2C_DELAY_UNIT << 2);
	set_i2c_pin(gpio_tlg1100_i2c_scl);
	i2c_delay(I2C_DELAY_UNIT << 3);
	set_i2c_pin(gpio_tlg1100_i2c_sda);
	i2c_delay(I2C_DELAY_UNIT << 4);
}

void i2c_write_ack(unsigned char flag)
{
	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_output(gpio_tlg1100_i2c_sda);
	
	if(flag)
		set_i2c_pin(gpio_tlg1100_i2c_sda);
	else
		clr_i2c_pin(gpio_tlg1100_i2c_sda);
	i2c_delay(I2C_DELAY_UNIT << 0);
	set_i2c_pin(gpio_tlg1100_i2c_scl);
	i2c_delay(I2C_DELAY_UNIT << 0);
	clr_i2c_pin(gpio_tlg1100_i2c_scl);
	i2c_delay(I2C_DELAY_UNIT << 0);
}


int i2c_read_ack(void)
{	
	int ret= 0;
	int retry=0;

	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_input(gpio_tlg1100_i2c_sda);

	i2c_delay(I2C_DELAY_UNIT << 0);
	set_i2c_pin(gpio_tlg1100_i2c_scl);
	i2c_delay(I2C_DELAY_UNIT << 0);
	
#if 0
	if (!get_i2c_pin(gpio_tlg1100_i2c_sda))
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
#else
	while(++retry < 10 )
	{
		
		if( !get_i2c_pin(gpio_tlg1100_i2c_sda) )
		{
			ret = 1;
			break;
		}

		
		i2c_delay( I2C_DELAY_UNIT/2 );
	}
#endif

	i2c_delay(I2C_DELAY_UNIT << 0);
	clr_i2c_pin(gpio_tlg1100_i2c_scl);
       i2c_delay(I2C_DELAY_UNIT << 0);

#if 1
	//Huyanwei Add it For Reset Inited I2C For fix leakage
	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl) ;
	clr_i2c_pin(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_output(gpio_tlg1100_i2c_sda);
	clr_i2c_pin(gpio_tlg1100_i2c_sda);
#endif

	return ret;
}

unsigned char i2c_read_byte(void)
{
	unsigned char i;
	unsigned char ret;
	unsigned char temp;

	ret	= 0;	

	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_input(gpio_tlg1100_i2c_sda);

	
	for	(i=0; i<8; i++)
	{			
		i2c_delay(I2C_DELAY_UNIT << 0);
		set_i2c_pin(gpio_tlg1100_i2c_scl);	
		i2c_delay(I2C_DELAY_UNIT << 0);
		ret	= ret<<1;
		temp = get_i2c_pin(gpio_tlg1100_i2c_sda);
		if (1 == temp)
			ret |= 1;
		
		i2c_delay(I2C_DELAY_UNIT << 0);
		clr_i2c_pin(gpio_tlg1100_i2c_scl);
	       i2c_delay(I2C_DELAY_UNIT << 0);
	}

	return ret;
}

int i2c_write_byte(unsigned char data)
{
	unsigned char i;

	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_output(gpio_tlg1100_i2c_sda);

	for	(i=0; i<8; i++)
	{
		i2c_delay(I2C_DELAY_UNIT << 0);
		if (data & 0x80)
			set_i2c_pin(gpio_tlg1100_i2c_sda);
		else
			clr_i2c_pin(gpio_tlg1100_i2c_sda);
		data <<= 1;

		i2c_delay(I2C_DELAY_UNIT << 0);
		set_i2c_pin(gpio_tlg1100_i2c_scl);
		i2c_delay(I2C_DELAY_UNIT << 0);
		clr_i2c_pin(gpio_tlg1100_i2c_scl);
	}

	return i2c_read_ack();
}

void i2c_init(void)
{/*
	unsigned int value;
	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_input(gpio_tlg1100_i2c_sda);
	*/
}

/*************************************************************************************
*
*   Parameter Description:
*                                    dab:device Id =0x58/0x59
*                                    rab: register address
*                                    data: dump into register
*                                    size:  8 bits
**************************************************************************************/
int i2c_write_data(unsigned char dab, unsigned char rab, unsigned char *data, unsigned char size)
{
	unsigned char i;

	i2c_begin();
	if (!i2c_write_byte(dab))
	{
		i2c_end();
		return 0;
	}
	if (!i2c_write_byte(rab))
	{
		i2c_end();
		return 0;
	}

	for	(i=0; i<size; i++)
	{
		if (!i2c_write_byte(*data))
		{
			i2c_end();
			return 0;
		}
		data++;
	}
	i2c_end();
	return 0;
	
}

int i2c_write_data2(unsigned char dab, unsigned char *data, unsigned char size)
{
	unsigned char i;

	i2c_begin();
	if (!i2c_write_byte(dab))
	{
		i2c_end();
		return 0;
	}

	for	(i=0; i<size; i++)
	{
		if (!i2c_write_byte(data[i]))
		{
			i2c_end();
			return 0;
		}
	}

	i2c_end();
	return 0;
}


int i2c_read_data(unsigned char dab, unsigned char rab, unsigned char *data, unsigned char size)
{
	unsigned char i;

	i2c_begin();
	if (!i2c_write_byte(dab))
	{
		i2c_end();
		return 0;
	}
	if (!i2c_write_byte(rab))
	{
		i2c_end();
		return 0;
	}

	i2c_begin();

	if (!i2c_write_byte((unsigned char)(dab | 1)))
	{
		i2c_end();
		return 0;
	}
	for(i=0; i<size; i++)
	{
		*data = i2c_read_byte();
		(i<size-1)?i2c_write_ack(0):i2c_write_ack(1);
		data++;
	}

	i2c_end();
	return 0;
}


int i2c_read_data2(unsigned char dab, unsigned char *data, unsigned char size)
{
	unsigned char i;

	i2c_begin();

	if (!i2c_write_byte((unsigned char)(dab | 1)))
	{
		i2c_end();
		return 0;
	}
	for(i=0; i<size; i++)
	{
		data[i] = i2c_read_byte();
		(i<size-1)?i2c_write_ack(0):i2c_write_ack(1);
	}

	i2c_end();
	
	return 0;
}

int TLGI2C_Init(const char *DlpDllPath)
{
	gpio_config_bit_as_output(gpio_tlg1100_i2c_scl);
	gpio_config_bit_as_input(gpio_tlg1100_i2c_sda);

	return 0;
}

int TLGI2C_ReadBurst(unsigned i2c_addr, unsigned start_addr, int length, unsigned short * data)
{

		return 0;

}

int TLGI2C_WriteBurst(unsigned i2c_addr, unsigned start_addr, int length, unsigned short * data)
{
	return 0;

}

/***************************************************************************
*
*
*    IIC Write data for Tlg1100
*                                    dab:device Id =0x2c
*                                    rab: register address
*                                    data: dump into register
*
****************************************************************************/

int  TLGI2C_WriteReg(unsigned  dab, unsigned  rab, unsigned short data)
{

#if 0
	//int i2c_write_data(unsigned char dab, unsigned char rab, unsigned char *data, unsigned char size)
	return i2c_write_data( dab<<1, rab,  (unsigned char*)&data, 2);	

#else

	unsigned char i;
	unsigned char tmpData = 0;
	
	i2c_begin();
	if (!i2c_write_byte(dab<<1))
	{
		i2c_end();
		return 0;
	}
	/* write 16bits register */
      tmpData = ((rab & 0x7f00) >> 8);

	if (!i2c_write_byte(tmpData))
	{
		i2c_end();
		return 0;
	}

	tmpData = (rab & 0x00ff);
	if (!i2c_write_byte(tmpData))
	{
		i2c_end();
		return 0;
	}
    /* write 16bits data */
	tmpData = (((data) & 0xff00) >> 8);
	if (!i2c_write_byte(tmpData))
	{
		i2c_end();
		return 0;
	}
	//data++;
	
	tmpData = ((data) & 0x00ff);
	if (!i2c_write_byte(tmpData))
	{
		i2c_end();
		return 0;
	}

	i2c_end();
	return 1; //0;
#endif

}

/***************************************************************************
*
*
*    IIC Read data for Tlg1100
*                                    dab:device Id =0x2c
*                                    rab: register address
*                                    data: dump into register
*
****************************************************************************/
int TLGI2C_ReadReg(unsigned  dab, unsigned  rab, unsigned short *data)
{

#if 0
//int i2c_read_data(unsigned char dab, unsigned char rab, unsigned char *data, unsigned char size)

	return i2c_read_data( dab<<1, rab, (unsigned char *) data, 2 );

#else
	unsigned char i;
	unsigned char tmpData = 0;

	i2c_begin();
	if ( !i2c_write_byte(dab<<1) )
	{
		i2c_end();
		return 0;
	}
	/* set MSB 1 */
	tmpData = (((rab | 0x8000) & 0xff00) >> 8); 
	if (!i2c_write_byte(tmpData))
	{
		i2c_end();
		return 0;
	}
	tmpData = ((rab & 0x00ff)); 
	if (!i2c_write_byte(tmpData))
	{
		i2c_end();
		return 0;
	}

#if 1	
       /* write any data into this register */
	if (!i2c_write_byte(0xff))
	{
		i2c_end();
		return 0;
	}
	if (!i2c_write_byte(0xff))
	{
		i2c_end();
		return 0;
	}
	i2c_end();  /* stop bit */
#endif

	/* start again */
	i2c_begin();

	if (!i2c_write_byte((unsigned char)(dab<<1 | 1)))
	{
		i2c_end();
		return 0;
	}

#if 1 
	*data = i2c_read_byte();
	i2c_write_ack(0);
	
	*data = i2c_read_byte();
	i2c_write_ack(0);
#endif

      tmpData = i2c_read_byte();
      i2c_write_ack(0);
    
      *data = (tmpData << 8) & 0xff00;
    	
      tmpData = i2c_read_byte();
      i2c_write_ack(1);	                 /* can not send ACK,must send NAck */
     
      *data |= tmpData;

	i2c_end();
	return 1; //0;

#endif

}



unsigned int  TLGI2C_GetAddress( )
{
	unsigned int  tlg_i2c_addr;
	unsigned short data;
	unsigned rab = 0;
	
	TLGI2C_Init( 0 );

	tlg_i2c_addr =  TLGI2C_DEFAULT_BASE_ADDR;
	
	if ( TLGI2C_ReadReg(tlg_i2c_addr,  rab, &data) )
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rTLGI2C_GETADDRESS RETURN 1:> Get i2c addr is %d\n", TLGI2C_DEFAULT_BASE_ADDR);
#endif
		return tlg_i2c_addr;
	}
	

	tlg_i2c_addr = TLGI2C_ALTERNATE_BASE_ADDR;
	if ( TLGI2C_ReadReg(tlg_i2c_addr,  rab, &data) )
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\rrTLGI2C_GETADDRESS RETURN 2:> Get i2c addr is %d\n", TLGI2C_ALTERNATE_BASE_ADDR);
#endif
		return tlg_i2c_addr;
	}


	return TLGI2C_DEFAULT_BASE_ADDR;
	
}

/* end of file */
