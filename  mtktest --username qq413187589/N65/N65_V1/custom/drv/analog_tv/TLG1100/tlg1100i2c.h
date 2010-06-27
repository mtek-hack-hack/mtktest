#ifndef  __TLG1100I2C_H_
#define __TLG1100I2C_H_
/****************************************************************************/
/*!@file  tlg1100i2c.h
 *
 * @brief Customizable i2c access routines for TLG1100
 *
 * < Detailed description of subsystem >
 *
 * \sa <optional links to relevant .h files>
 *
 ****************************************************************************/
/* Revision Information:
 *
 * $Id: tlg1100i2c.h,v 1.4 2006/07/07 00:22:10 tozz Exp $
 *
 * $Revision: 1.4 $
 *
 * (c) 2006 Telegent Systems
 ****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/** Default Base Address for TLG1100
 */
#define TLGI2C_DEFAULT_BASE_ADDR            (0x002c)

/** Alternate I2C Address for TLG1100
 */
#define TLGI2C_ALTERNATE_BASE_ADDR          (0x002d)

//#define int                            int         //__declspec(dllimport)

/** Initialize I2C
 *
 * @fn int TLGI2C_Init(const char *DlpDllPath);
 *
 * This is a customer-written procedure that represents initializing their I2c
 * driver subsystem. It is not called by the TLG API and it is assumed the
 * customer code will call this direclty as part of their startup procedures.
 * It may have whatever calling conventions or format that is needed.
 */
int TLGI2C_Init(const char *DlpDllPath);

/** Write a block of registers to TLG1100
 *
 * @fn int TLGI2C_WriteBurst(unsigned i2c_addr, unsigned start_addr, int length, unsigned short * data);
 *
 * This is a customer-supplied function that writes a block of registers starting 
 * at the specified register address on the TLG1100. IT IS CURRENTLY NOT CALLED
 * BY THE TLG API.
 *
 * @param i2c_addr      I2c address for TLG1100 chip.
 * @param start_addr    Starting address of registers to write.
 * @param length        Number of registers to write.
 * @param data          Address of block of register values to write.
 *
 * @returns 
 * @todo returns
 */
int TLGI2C_WriteBurst(unsigned i2c_addr, unsigned start_addr, int length, unsigned short * data);
 
/** Read a contiguous block of registers from the TLG1100.
 *
 * @fn int TLGI2C_ReadBurst(unsigned i2c_addr, unsigned start_addr, int length, unsigned short * data);
 *
 * This is a customer-supplied procedure that reads a block of registers starting 
 * at the specified register address on the TLG1100. IT IS CURRENTLY NOT CALLED
 * BY THE TLG API.
 *
 * @param i2c_addr      I2c address for TLG1100 chip.
 * @param start_addr    Starting address of registers to write.
 * @param length        Number of registers to read.
 * @param data          Address of block of register values to write.
 * 
 */
int TLGI2C_ReadBurst(unsigned i2c_addr, unsigned start_addr, int length, unsigned short * data);
 
/** Write a register value to the TLG1100.
 *
 * @fn int TLGI2C_WriteReg(unsigned i2c_addr, unsigned reg_addr, unsigned short data);
 *
 * This customer-supplied procedure writes the specified register value at the 
 * specified register address on the TLG1100. 
 *
 * @param i2c_addr      I2c address for TLG1100 chip.
 * @param reg_addr      Address of register to write.
 * @param data          Register value to write.
 * 
 */
int TLGI2C_WriteReg(unsigned i2c_addr, unsigned reg_addr, unsigned short data);

/** Read a register value from the TLG1100.
 *
 * @fn int TLGI2C_ReadReg(unsigned i2c_addr, unsigned reg_addr, unsigned short * data);
 *
 * This customer-supplied procedure will retrieve a register value direclty 
 * from the TLG1100. 
 *
 * @param i2c_addr      I2c address for TLG1100 chip.
 * @param reg_addr      Register Address to retrieve.
 * @param data          Returned register value.
 * 
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
int TLGI2C_ReadReg(unsigned i2c_addr, unsigned reg_addr, unsigned short * data);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* __TLG1100I2C_H_ */

