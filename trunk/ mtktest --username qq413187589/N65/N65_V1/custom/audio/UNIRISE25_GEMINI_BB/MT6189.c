/*******************************************************************************
 *
 * Filename:
 * ---------
 * MT6189.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *      MT6189 I2C/3-wire Interface
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "l1audio_def.h"

#if (defined(MT6189A1) || defined(MT6189A2))

void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPIO_InitIO(char direction, char port);
void GPIO_WriteIO(char data,char port);
char GPIO_ReadIO(char port);
void GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
void GPO_WriteIO(char data, char port);

/* GPIO definition */
/// The following GPIO should be customized according to different platforms.
#define CRYCLK 12       /// GPIO #12:  32.768 kHz clock
#define LE     4        /// GPIO #4:  LE pin
#define SDA    9        /// GPIO #9: I2C data pin
#define SCL    8        /// GPIO #8: I2C clock pin

#if defined(MT6205B) || defined(MT6208)
#define FM_SWITCH   3   /// GPIO #3:  external switch for FM/speech
#define FM_PATH     0
#define SPEECH_PATH 1

void ExtSwitchInit(void) {
   GPIO_ModeSetup(FM_SWITCH, 0);
   GPIO_InitIO(1, FM_SWITCH);
   GPIO_WriteIO(FM_SWITCH, SPEECH_PATH);
}

void SwitchExtFMPath(uint8 if_on) {
   if (if_on) GPIO_WriteIO(FM_SWITCH, FM_PATH);
   else GPIO_WriteIO(FM_SWITCH, SPEECH_PATH);
}

#endif

#define USE_I2C

uint16  i2c_dummy_cnt;
#define I2C_DUMMY_DELAY(_delay) for (i2c_dummy_cnt = _delay; i2c_dummy_cnt!=0; i2c_dummy_cnt--)

uint8 const FM_RADIO_INPUT_LEVEL_THRESHOLD = 5;

void SerialCommCryClkOn(void)
{
#if !defined( MT6205B ) && !defined( MT6208 )
   GPIO_ModeSetup(CRYCLK,3); /* 32.768kHz reference frequency */
#else
   /// Config SRCLKENA as GPO2 and set the output to 1 to keep 26M clock alive.
   GPO_WriteIO(1, 2);
   GPO_ModeSetup(2, 0);
#endif
}

void SerialCommCryClkOff(void)
{
#if !defined( MT6205B ) && !defined( MT6208 )
   GPIO_ModeSetup(CRYCLK,0);
#else
   /// Config GPO2 as SRCLKENA.
   GPO_ModeSetup(2, 1);
#endif
}


#ifdef USE_3_WIRE
void SerialCommInit(void)
{
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   GPIO_ModeSetup(LE,0);
   GPIO_InitIO(1,SCL);
   GPIO_InitIO(1,LE);
   GPIO_WriteIO(1,SCL);
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(0,LE);
}

void SerialCommRelease(void)
{
   GPIO_WriteIO(0,SCL);
   GPIO_WriteIO(0,SDA);
   GPIO_WriteIO(0,LE);
}

uint8 SerialCommTxByte(uint8 addr, uint8 data)
{
   int16 i;
   GPIO_WriteIO(1, LE);
   GPIO_InitIO(1,SDA);
   for(i=8; --i>=0;){
      GPIO_WriteIO( 0, SCL);
      GPIO_WriteIO(data&0x01, SDA);
      data >>= 1;
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL);
      I2C_DUMMY_DELAY(5);
   }
   for(i=8; --i>=0;){
      GPIO_WriteIO( 0, SCL);
      GPIO_WriteIO(addr&0x01, SDA);
      addr >>= 1;
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL);
      I2C_DUMMY_DELAY(5);
   }
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(0, LE);
   I2C_DUMMY_DELAY(10);
}

uint8 SerialCommRxByte(uint8 addr, uint8 *data)
{
   int16 i;
   uint16 dataRead=0;
   *data = 0;
   GPIO_WriteIO(1, LE);
   GPIO_InitIO(1,SDA);
   for(i=8; --i>=0;){
      GPIO_WriteIO( 0, SCL);
      GPIO_WriteIO(addr&0x01, SDA);
      GPIO_WriteIO(1, SCL);
      addr >>= 1;
      I2C_DUMMY_DELAY(5);
   }
   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(0, LE);
   for(i=0; i<8; i++){
      GPIO_WriteIO( 0, SCL);
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL);
      dataRead = GPIO_ReadIO(SDA);
      *data |= (dataRead << i);
   }
   I2C_DUMMY_DELAY(10);
}

#elif defined USE_I2C

void SerialCommInit(void)
{
   GPIO_ModeSetup(SCL,0);
   GPIO_ModeSetup(SDA,0);
   GPIO_InitIO(1,SCL);
}

void SerialCommRelease(void)
{
   GPIO_WriteIO(1,SCL);
   GPIO_WriteIO(1,SDA);
}

/* Start sequence of I2C

   SDA ¢w¢w¢{
           ¢|¢w¢w
   SCL ¢w¢w¢w¢{
             ¢|¢w¢w
*/
void SerialCommStart(void) /* Prepare the SDA and SCL for sending/receiving */
{   
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(1,SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1,SCL);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(0,SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(0,SCL);
   I2C_DUMMY_DELAY(5);
}

/* Stop sequence of I2C

   SDA       ¢z¢w¢w
       ¢w¢w¢w¢}
   SCL     ¢z¢w¢w¢w
       ¢w¢w¢}
*/

void SerialCommStop(void)
{
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(0,SCL);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(0,SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1,SCL);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1,SDA);
   I2C_DUMMY_DELAY(5);
}

uint8 SerialCommTxByte(uint8 data) /* return 0 --> ack */
{
   int16 i, ack;
   GPIO_InitIO(1,SDA);
   for(i=8; --i>0;){
      GPIO_WriteIO((data>>i)&0x01, SDA);
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 1, SCL); /* high */
      I2C_DUMMY_DELAY(5);
      GPIO_WriteIO( 0, SCL); /* low */
      I2C_DUMMY_DELAY(5);
   }
   GPIO_WriteIO((data>>i)&0x01, SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO( 1, SCL); /* high */
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO( 0, SCL); /* low */

   GPIO_InitIO(0,SDA);
   GPIO_WriteIO(1, SCL);
   I2C_DUMMY_DELAY(5);
   ack = GPIO_ReadIO(SDA); /// ack
   GPIO_WriteIO(0, SCL);
}

void SerialCommRxByte(uint8 *data, uint8 ack)
{
   int16 i;
   uint32 dataCache;
   dataCache = 0;
   GPIO_InitIO(0,SDA);
   for(i=8; --i>=0;){
      dataCache <<= 1;
      GPIO_WriteIO(1, SCL);
      I2C_DUMMY_DELAY(5);
      dataCache |= GPIO_ReadIO(SDA);
      GPIO_WriteIO(0, SCL);
      I2C_DUMMY_DELAY(5);
   }
   GPIO_InitIO(1,SDA);
   GPIO_WriteIO(ack, SDA);
   I2C_DUMMY_DELAY(5);
   GPIO_WriteIO(1, SCL);
   *data = (uint8)dataCache;
   GPIO_WriteIO(0, SCL);
}
#else
#error "Must define USE_I2C or USE_3_WIRE"
#endif

#endif