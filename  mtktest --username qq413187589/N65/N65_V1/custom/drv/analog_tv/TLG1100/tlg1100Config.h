#ifndef _TLG1100_CONFIG_H_
#define _TLG1100_CONFIG_H_
/****************************************************************************/
/*!@file  tlg1100Config.h
 *
 * @brief Compile-time configuration declarations for the TLG API.
 *
 * This file contains the compile time declarations for the TLG1100 Ultra Low 
 * Power NTSC/PAL Tuner/Decoder chip support library.
 *
 *
 ****************************************************************************/
/* Revision Information:
 *
 * $Revision: 1.4 $
 *
 * (c) 2007 Telegent Systems
 ****************************************************************************/

#ifdef TLG_USE_DLL
    #ifdef TLG1100DLL_EXPORTS
        #define TLG1100DLL_API __declspec(dllexport)
    #else
        #define TLG1100DLL_API __declspec(dllimport)
    #endif /* TLG1100DLL_EXPORTS */
#else /* !TLG_USE_DLL */
    #define TLG1100DLL_API
#endif /* TLG_USE_DLL */


#ifdef __cplusplus
extern "C"  {
#endif

/** Enable/Disable the use of Shadow Registers.
 * 
 * If this is defined, it creates a shadow register array that is used to read
 * from the TLG1100 to save access time. Note that the array must be populated
 * first by doing TLG_ReadRegNS() from TLG_MIN_REG_ADDR to TLG_MAX_REG_ADDR
 * to get the correct values into the shadow. 
 */
#define TLG_USE_SHADOW_REGISTERS        (1)

/** Enable/Disable built in error checking. 
 * 
 * If this is defined the TLG API will perform NULL pointer and bounds 
 * checking on its parameters. 
 */
#define TLG_DO_ERROR_CHECKING           (1)

/** Enable/Disable informative logging facility.
 *
 * If this is defined the TLG API will perform informative logging on exception
 * conditions. Note that for this to be enabled, a user must supply a 
 * custom routine TLG_WriteLog(char *str), to support the logging facility.
 */
//#define TLG_DO_REG_LOGGING              (1)

/** Enable/Disable the use of embedded timers in the channel change procedures.
 *
 * The portable TLG1100 software provides both synchronous and asynchronous 
 * versions of many of its API calls. The synchronous calls require the use
 * of a timer facility TLG_Delay() (this is a customer-supplied procedure) to 
 * operate. This define turns on the use of the embedded timer facility. If
 * only the asynchronous calls are used, this feature should be turned off.
 */
#define TLG_EMBEDDED_TIMERS             (1) 

/** Use new faster lock detection algorithm.
 */
//#define TLG_USE_FAST_LOCK_DETECT        (1)

/** Select which Tracking Filter Dcycle Algorithm to use.
 *
 * this define switches between two tracking filter dcycle calculation
 * methods. This define should only be changed on the advice of a
 * Telegent Field Engineer.
 */
#define TLG_TF_CALC_DCYCLE_BY_HZ        (1)

/** Enable I2C Register Qualification Tests.
 * 
 * This define compiles in the TLG I2C register access qualification tests.
 *
 * @sa TLG_TestDefRegs
 * @sa TLG_TestWriteRegs
 */
//#define TLG_ENABLE_I2C_QUAL_TESTS       (1)

/** Define word size of compiler.
 *
 * These defines define the word size for the compiler. For now only the "int"
 * type is managed. If the default "int" size for the compiler used to build
 * this code is 32, then leave TLG_INT_32BIT defined. If the default "int" 
 * size for the compiler is 16 then remove the define for TLG_INT_32BIT and
 * enable the define for TLG_INT_16BIT.
 */
#define TLG_INT_32BIT                   (1)
#define xTLG_INT_16BIT                   (1)

#if defined(TLG_INT_32BIT) && defined(TLG_INT_16BIT)
ERROR! Both TLG_INT32BIT and TLG_INT_16BIT may not be defined at the same time.
#endif

/** Define status of vertical screen lock.
 *
 * If defined, VSYNC signals are expected to arrive at exact intervals, hence
 * improving screen's vertical stability. However, not all Media Processors 
 * require this to be defined.
 */
//#define TLG_VSCREEN_LOCK				(1)

/** Define if SSI/Signal Strength status is read by a polling program.
 *
 * SSI readout is strongly recommended to be performed during TLG operation.
 * This Define is recommended to leave as is.
 */
//#define xTLG_NO_SSI_READOUT             (1)

/*****************************************************************************
* CHIP CONFIG CONSTANTS
*
* The following are chip version configuration constants and should not be
* changed.
*****************************************************************************/
#define TLG_CHIP_TYPE_TLG1100_1     (0x0001)

#define TLG_CHIP_REV_1              (0x00000001)
#define TLG_CHIP_REV_2              (0x00000002)
#define TLG_CHIP_REV_3              (0x00000003)

/****************************************************************************
* CHIP VERSION CONFIGURATION
*
* These two constants should be set to the latest revision of TLG1100 chip
* supported. Current valid chip versions are:
*
*   TLG_CHIP_TYPE       
*   - TLG_CHIP_TYPE_TLG1100_1
*
*   TLG_CHIP_REV
*   - TLG_CHIP_REV_1        TLG1100 1.1 chip
*   - TLG_CHIP_REV_2        TLG1100 1.2 chip
*   - TLG_CHIP_REV_3        TLG1100 1.3 chip
*****************************************************************************/

#define TLG_CHIP_TYPE               TLG_CHIP_TYPE_TLG1100_1
#define TLG_CHIP_REV                TLG_CHIP_REV_3

/*
 * Code Configuration Section
 *
 * The TLG API supports two modes of operation for multi-version chip support.
 * 1) Runtime chip support
 *      With this option all code for all versions of the chip is compiled
 *      into the TLG API and runtime checks are made to determine which code
 *      is to be executed based on chip version. This mode is enabled by
 *      the #define TLG_SUPPORT_RUNTIME_CHECK statement.
 *
 * 2) Compile-time chip support
 *      With this option only the code for the currently defined chip version
 *      (see TLG_CHIP_TYPE and TLG_CHIP_REV) is compiled into TLG API. This
 *      mode is enabled by NOT adding the TLG_SUPPORT_RUNTIME_CHECK statement.
 *
 * By default the TLG API is setup to support the Runtime chip support mode.
 * This is good for early development and while transitioning from one version
 * of chip to another. However, there is a small execution and codespace
 * savings for using the Compile-time mode, so this can be used for 
 * the production version of code if desired.
 */
/** Support Runtime determination of which chip to support.
* Remove this define to enable compile-time chip support.
*/
//#define TLG_SUPPORT_RUNTIME_CHECK 1


#ifdef __cplusplus
};
#endif

#endif /* _TLG1100_CONFIG_H_ */
