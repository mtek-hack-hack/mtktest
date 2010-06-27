/*********************************************************************
 
  (c) copyright Freescale Semiconductor Ltd. 2008
  ALL RIGHTS RESERVED
 
 ********************************************************************
 Ver 0	Initial release
 ********************************************************************/
#if 1 //#if defined(MOTION_SENSOR_SUPPORT)
#include "drv_comm.h"
#include "reg_base.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
#include "gpio_drv.h"

#include "FSL_MMA.h"

extern const char gpio_G_i2c_sda_pin;
extern const char gpio_G_i2c_scl_pin;

#define ACC_SENSOR_SCK gpio_G_i2c_scl_pin
#define ACC_SENSOR_SDA gpio_G_i2c_sda_pin

#define SET_I2C_CLK_OUTPUT \
		{\
			GPIO_ModeSetup(gpio_G_i2c_scl_pin,0);\
			GPIO_InitIO(1,gpio_G_i2c_scl_pin);\
		}
				
#define SET_I2C_DATA_OUTPUT \
		{\
			GPIO_ModeSetup(gpio_G_i2c_sda_pin,0);\
			GPIO_InitIO(1,gpio_G_i2c_sda_pin);\
		}

#define SET_I2C_DATA_INPUT \
		{\
			GPIO_ModeSetup(gpio_G_i2c_sda_pin,0);\
			GPIO_InitIO(0,gpio_G_i2c_sda_pin);\
		}



	
#define SET_I2C_CLK_HIGH		  GPIO_WriteIO(1,gpio_G_i2c_scl_pin)
#define SET_I2C_CLK_LOW		  GPIO_WriteIO(0,gpio_G_i2c_scl_pin)
#define SET_I2C_DATA_HIGH		  GPIO_WriteIO(1,gpio_G_i2c_sda_pin)
#define SET_I2C_DATA_LOW		  GPIO_WriteIO(0,gpio_G_i2c_sda_pin)
#define GET_I2C_DATA_BIT              GPIO_ReadIO( gpio_G_i2c_sda_pin ) 

extern prompt_trace(VINT16 mode, VUINT8 *text);		//Debug mode dump trace code

#define MMA745xL_AddW 0x3A          //MMA7455 Address for Writing
#define MMA745xL_AddR 0x3B          //MMA7455 Address for Reading

#define Delay20us 	10000             //Loop times to delay 20uS (Need to change according to system clock)
#define Delay10us 	5000              //Loop times to delay 45uS (Need to change according to system clock)
#define Delay5us	  2500              //Loop times to delay 21uS (Need to change according to system clock)
#define Delay2p5us	1250             //Loop times to delay 2.5uS (Need to change according to system clock)//ghw111

void mma745x_init() {                     //MMA7455 Initialize
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);   //Set I2C CLK pin as GPIO   
	SET_I2C_CLK_OUTPUT;                     //Set I2C CLK pin as output
	SET_I2C_CLK_HIGH;                       //I2C CLK pin output high(1)

	GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);   //Set I2C DATA pin as GPIO
	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output
	SET_I2C_DATA_HIGH;                      //I2C DATA pin output high(1)
}

void mma_delay(VUINT8 time) {             //Time delay function
	VUINT8 i;
	for (i=0; i<time; i++) ;                //Software loop for time delay
}

void IIC_Start(void) {                    //I2C Start signal generation: Data pin falls down when clock is high
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);   //Set I2C CLK pin as GPIO
	SET_I2C_CLK_OUTPUT;                     //Set I2C CLK pin as output
	GPIO_ModeSetup(ACC_SENSOR_SDA, 0x00);   //Set I2C DATA pin as GPIO
	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output

	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
	mma_delay(Delay20us);                   //Delay 20uS
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS
}

void IIC_Stop (void) {                    //I2C Stop signal generation: Data pin rises up when clock in is high
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
}

void IIC_RepeatedStart(void) {            //I2C Repeat Start signal generation: Data pin falls down when clock is high
	mma_delay(Delay20us);                   //Delay 20uS
	mma_delay(Delay20us);                   //Delay 20uS
	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
	mma_delay(Delay20us);                   //Delay 20uS
	mma_delay(Delay20us);                   //Delay 20uS
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
	mma_delay(Delay10us);                   //Delay 10uS	
}

void IIC_OneClk(void) {                   //I2C CLK pin output one clock: CLK pin rises up before falls down
	mma_delay(Delay5us);
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)		
	mma_delay(Delay10us);                   //Delay 10uS
	SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
	mma_delay(Delay5us);	
}

void IIC_SendByte(VUINT8 sData) {         //I2C send one byte out
	VINT8 i;
	for (i=7; i>=0; i--) {                  //Loop 8 times to send 8 bits
		if ((sData>>i)&0x01) {                //Judge output 1 or 0
			SET_I2C_DATA_HIGH;	                //I2C DATA pin output high(1) if output 1
		} else { 
			SET_I2C_DATA_LOW;                   //I2C DATA pin output low(0) if output 0
			}
		IIC_OneClk();                         //Output one clock pulse after data pin is ready
	}		
}

VUINT8  IIC_ChkAck(void) {                //Check I2C Acknowledgement signal
	SET_I2C_DATA_INPUT;                     //Set I2C DATA pin as input
	mma_delay(Delay5us);                    //Delay 5uS
	SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)		
	mma_delay(Delay5us);                    //Delay 5uS again
	if (GET_I2C_DATA_BIT) {                 //Read I2C DATA pin
		mma_delay(Delay5us);                  //Delay 5uS
		SET_I2C_CLK_LOW;                      //I2C CLK pin output low(0)
		mma_delay(Delay5us);                  //Delay 5us again
		SET_I2C_DATA_OUTPUT;                  //Set I2C DATA pin as output
		SET_I2C_DATA_LOW;                     //I2C DATA pin output low(0)
		return 1;                             //Return 1 if read 1 from I2C DATA pin
		} else {                              //If I2C DATA pin is invalid for acknowledgement signal
		mma_delay(Delay5us);                  //Delay 5uS
		SET_I2C_CLK_LOW;                      //I2C CLK pin output low(0)
		mma_delay(Delay5us);                  //Delay 5uS again
		SET_I2C_DATA_OUTPUT;                  //Set I2C DATA pin as output
		SET_I2C_DATA_LOW;                     //I2C DATA pin output low(0)
		return 0;                             //Return 0 if read 0 from I2C DATA pin
		}			
}

VUINT8 IIC_ReadByteACK(void) {            //Read one byte and send an acknowledgement signal
	VINT8 i;
	VUINT8 data;

	SET_I2C_DATA_INPUT;                     //Set I2C DATA pin as input
	data = 0;                               //Prepare to receive data
	for (i=7; i>=0; i--) {                  //Loop 8 times to receive 8 bits
		if (GET_I2C_DATA_BIT) data |= (0x01<<i);    //If read a 1, set to data bit
		IIC_OneClk();
		}			                                //Output one clock pulse after a bit is read

	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0): the acknowledgement signal
	IIC_OneClk();                           //Output one clock pulse after data pin is ready

	return data;                            //Return eceived data
}

VUINT8 IIC_ReadByteNCK(void) {            //Read one byte but do not send acknowledgement signal
	VINT8 i;
	VUINT8 data;

	SET_I2C_DATA_INPUT;                     //Set I2C DATA pin as input
	data = 0;                               //Prepare to receive data
	for (i=7; i>=0; i--) {                  //Loop 8 times to receive 8 bits
		if (GET_I2C_DATA_BIT) data |= (0x01<<i);    //If read a 1, set to data bit
		IIC_OneClk();
		}			                                //Output one clock pulse after a bit is read

	SET_I2C_DATA_OUTPUT;                    //Set I2C DATA pin as output
	SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1): no acknowledge
	IIC_OneClk();                           //Output one clock pulse after data pin is ready
	SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)

	return data;                            //Return received data
}


// Master Write
void mma745x_IICWrite(VUINT8 RegAdd, VUINT8 Data) {   //Write one byte to a MMA7455 register via I2C
	//Start
	IIC_Start();                                        //Output a START signal

	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send one byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal
   	#ifdef ACC_DEBUG	                                //Only for debug
		//prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");   //Print error information

	#endif

	
		IIC_Stop();	                                      //Output a STOP signal
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read                         
	IIC_SendByte(RegAdd);                               //Send one byte of register address in MMA7455
	if (IIC_ChkAck()) {                                 //Check acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug

	//prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");   //Print error information

	#endif                                              
		IIC_Stop();                                       //Output a STOP signal
		return;    	                                      //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Data to send
	IIC_SendByte(Data);                                 //Send one byte of data
	if (IIC_ChkAck()) {                                 //Check acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug
		//prompt_trace(MOD_MMA, "# MMA7455L Data NACK #\r\n");    //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Stop	
	IIC_Stop();	                                        //Output a STOP signal	

}

// Master Read
VINT8 mma745x_IICRead(VUINT8 RegAdd) {                //Read a byte from MMA7455 register via I2C
	VINT8 Data;

	//Start
	IIC_Start();                                        //Output a START signal
                                                      
	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send a byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		//prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");   //Print error information

	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return 0;                                         //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read
	IIC_SendByte(RegAdd);                               //Send one byte of register address in MMA7455
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return 0;                                         //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Repeated Start
	IIC_RepeatedStart();                                //Output a REPEAT START signal
	
	// Device hardware address                          
	IIC_SendByte(MMA745xL_AddR);                        //Send a MMA7455 address for reading
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		//prompt_trace(MOD_MMA, "# MMA7455L Device Read Address Error #\r\n");    //Print error information

	#endif
		}                                                 //If acknowledgement signal is read as 1, do nothing
                                                      //If acknowledgement signal is read as 0, then go to next step
	Data = IIC_ReadByteNCK();                           //Read one byte but do not output acknowledgement
   	#ifdef ACC_DEBUG	                                //Only for debug
		//prompt_trace(MOD_MMA, "# MMA7455L Read Data = %d #\r\n", Data);   //Print received data

	#endif

	// Stop	
	IIC_Stop();	                                        //Output a STOP signal

	return Data;                                        //Return received data
}

// Read XYZ 8bit Registers
void mma745x_ReadXYZ8(VINT8 *X, VINT8 *Y, VINT8 *Z) { //Read 3 continous bytes of X, Y and Z 8-bit data, start from address 0x06 on MMA7455
	//Start
	IIC_Start();                                        //Output a START signal

	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send a byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug
		//prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");   //Print error information

	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read
	IIC_SendByte(0x06);                                 //Send the start address to read
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");

	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;
		}

	// Repeated Start
	IIC_RepeatedStart();                                //Output a REPEAT START signal
	
	// Device hardware address
	IIC_SendByte(MMA745xL_AddR);                        //Send a MMA7455 address for reading
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Device Read Address Error #\r\n");

	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	*X = IIC_ReadByteACK();                             //Read one byte and output an acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read X Data = %d #\r\n", *X);   //Print read value of X data
	#endif

	*Y = IIC_ReadByteACK();                             //Read one byte and output an acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Y Data = %d #\r\n", *Y);   //Print read value of Y data
	#endif

	*Z = IIC_ReadByteNCK();                             //Read one byte and output an acknowledgement signal
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Z Data = %d #\r\n", *Z);   //Print read value of Z data
	#endif

	// Stop	
	IIC_Stop();	                                        //Output a STOP signal


}

// Read XYZ 10bit Registers
void mma745x_ReadXYZ10(VINT16 *X, VINT16 *Y, VINT16 *Z) { //Read 6 continous bytes of X, Y and Z 10-bit data, start from address 0x00 on MMA7455
	VINT16 temp;
	//Start
	IIC_Start();                                        //Output a START signal

	// Device hardware address
	IIC_SendByte(MMA745xL_AddW);                        //Send a byte of MMA7455 address for writing
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Device Write Address Error #\r\n");
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Register address to read
	IIC_SendByte(0x00);                                 //Send the start address to read
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Reg Address NACK #\r\n");   //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	// Repeated Start
	IIC_RepeatedStart();                                //Output a REPEAT START signal
	
	// Device hardware address
	IIC_SendByte(MMA745xL_AddR);                        //Send a MMA7455 address for reading
	if (IIC_ChkAck()) {                                 //Check acknowledge signal 
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Device Read Address Error #\r\n");    //Print error information
	#endif
		IIC_Stop();	                                      //Output a STOP signal	
		return;                                           //If acknowledgement signal is read as 1, then return to end
		}
                                                      //If acknowledgement signal is read as 0, then go to next step
	*X = (VINT16)IIC_ReadByteACK();                     //Read one byte (lower 8 bits of 10-bit data) and store in a 16-bit address
	temp = (VINT16)IIC_ReadByteACK();                   //Read the next byte (higher 2 bits of 10-bit data)
	*X += (temp<<8);                                    //Combine them to a 10-bit data
	if (*X&0x0200) *X |= 0xfc00;	                      //Change the 10-bit data into a 16-bit signed data
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read X Data = %d #\r\n", *X);   //Print the read data
	#endif

	*Y = (VINT16)IIC_ReadByteACK();                     //Read one byte (lower 8 bits of 10-bit data) and store in a 16-bit address
	temp = (VINT16)IIC_ReadByteACK();                   //Read the next byte (higher 2 bits of 10-bit data)
	*Y += (temp<<8);                                    //Combine them to a 10-bit data
	if (*Y&0x0200) *Y |= 0xfc00;                        //Change the 10-bit data into a 16-bit signed data
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Y Data = %d #\r\n", *Y);
	#endif

	*Z = (VINT16)IIC_ReadByteACK();                     //Read one byte (lower 8 bits of 10-bit data) and store in a 16-bit address
	temp = (VINT16)IIC_ReadByteNCK();                   //Read the next byte (higher 2 bits of 10-bit data)
	*Z += (temp<<8);                                    //Combine them to a 10-bit data
	if (*Z&0x0200) *Z |= 0xfc00;                        //Change the 10-bit data into a 16-bit signed data
   	#ifdef ACC_DEBUG	                                //Only for debug	
		prompt_trace(MOD_MMA, "# MMA7455L Read Z Data = %d #\r\n", *Z);
	#endif
	// Stop	
	IIC_Stop();	                                        //Output a STOP signal	

}


void MMA745x_Testing_SCL_Waveform(void) {   //Function used to test waveforms on I2C CLK pin
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);     //Set I2C CLK pin as GPIO
	SET_I2C_CLK_OUTPUT;

	while (1) {
		SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
		mma_delay(Delay20us);                   //Delay 20uS
		SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
		mma_delay(Delay20us);                   //Delay 20uS

		SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
		mma_delay(Delay10us);                   //Delay 10uS
		SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
		mma_delay(Delay10us);                   //Delay 10uS

		SET_I2C_CLK_HIGH;		                    //I2C CLK pin output high(1)
		mma_delay(Delay5us);                    //Delay 5uS
		SET_I2C_CLK_LOW;                        //I2C CLK pin output low(0)
		mma_delay(Delay5us);                    //Delay 5uS
	}                                         //Infinite loop

}

void MMA745x_Testing_SDA_Waveform(void) {   //Function used to test waveforms on I2C DATA pin
	GPIO_ModeSetup(ACC_SENSOR_SCK, 0x00);     //Set I2C CLK pin as GPIO
	SET_I2C_DATA_OUTPUT;                      //Set I2C DATA pin as output

	while (1) {
		SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
		mma_delay(Delay20us);                   //Delay 20uS
		SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
		mma_delay(Delay20us);                   //Delay 20uS

		SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
		mma_delay(Delay10us);                   //Delay 10uS
		SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
		mma_delay(Delay10us);                   //Delay 10uS

		SET_I2C_DATA_HIGH;	                    //I2C DATA pin output high(1)
		mma_delay(Delay5us);                    //Delay 5uS
		SET_I2C_DATA_LOW;                       //I2C DATA pin output low(0)
		mma_delay(Delay5us);                    //Delay 5uS
	}                                         //Infinite loop

}

#endif


