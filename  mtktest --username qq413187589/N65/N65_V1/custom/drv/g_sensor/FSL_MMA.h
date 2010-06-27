/*********************************************************************
 
  (c) copyright Freescale Semiconductor Ltd. 2008
  ALL RIGHTS RESERVED

********************************************************************
*	example:
*
*	VINT8 DX8, DY8, DZ8;
*	mma745x_init();
*	mma745x_IICWrite(0x16, 0x45); // Enable measurment mode
*	DX8 = mma745x_IICRead(0x06); // Read X
*	DY8 = mma745x_IICRead(0x07); // Read Y
*	DZ8 = mma745x_IICRead(0x08); // Read Z
*	mma745x_ReadXYZ8(&DX8, &DY8, &DZ8);
*
* 
********************************************************************
 Ver 0	Initial release
********************************************************************/
#include "FSL_data.h"

void mma745x_init();										// IIC hardware init
void mma745x_IICWrite(VUINT8 RegAdd, VUINT8 Data);			// Write 1 byte
VINT8 mma745x_IICRead(VUINT8 RegAdd);						// Read 1 byte
void mma745x_ReadXYZ8(VINT8 *X, VINT8 *Y, VINT8 *Z);		// Read 8bit XYZ 
//void mma745x_ReadXYZ10(VINT8 *X, VINT8 *Y, VINT8 *Z);		// Read 10bit XYZ
void MMA745x_Testing_SCL_Waveform(void);					// Hardware check on SCL line (dump square wave to SCL line)
void MMA745x_Testing_SDA_Waveform(void);					// Hardware check on SDA line (dump square wave to SDA line)
void mma745x_ReadXYZ10(VINT16 *X, VINT16 *Y, VINT16 *Z);

