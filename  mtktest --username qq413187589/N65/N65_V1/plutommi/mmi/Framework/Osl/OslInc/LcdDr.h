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

/*******************************************************************************
 * Filename:
 * ---------
 * L4Dr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This Module defines the LCD driver Hardware Addresses and Software MACROS.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _LCDDR_H_
#define  _LCDDR_H_

/***************************************************************************** 
* Define
*****************************************************************************/

/* -----------------------------------------------------------------------------
   Following are the Hardware Addresses and LCD commands  
   ------------------------------------------------------------------------------ */

/* LCD Addresses --------------------------------------------------------------- */
#define LCDrDUMMYADDR      (0x80170010)
#define LCDrCTRLAddr    (0x30000000)    /* Control Command LCD Address */
#define LCDrDATAAddr    (0x3000000f)    /* Data LCD Address */

// LCD Dimensions --------------------------------------------------------------
//------- Variables
#define LCDrWIDTH          120  /* X axis */
#define LCDrHEIGHT         160  /* Y Axis */
#define MAXROWS         LCDrHEIGHT
#define MAXCOL          LCDrWIDTH

/* LCD Command Words -----------LCDr------------------------------------------------ */
#define  LCDrDISON          0xaf        /* Display ON */
#define  LCDrDISOFF         0xae        /* Display OFF */
#define  LCDrDISNOR         0xa6        /* Display Normal */
#define  LCDrDISINV         0xa7        /* Display Inverse */
#define  LCDrCOMSCN         0xbb        /* Comman Scan Direction */
#define  LCDrDISCTL         0xca        /* Display Control */
#define  LCDrSLPIN          0x95        /* Sleep IN */
#define  LCDrSLPOUT         0x94        /* Sleep Out */
#define  LCDrPASET          0x75        /* Page Address Set */
#define  LCDrCASET          0x15        /* Column Address Set */
#define  LCDrDATCTL         0xbc        /* Data Control */
#define  LCDrDATALL         0xbd        /* Data ALL */
#define  LCDrDATCAN         0xbe        /* Data ALL Cancel */
#define  LCDrRGBSET8        0xce        /* 8 bit colour mode */
#define  LCDrRAMWR          0x5c        /* RAM Write */
#define  LCDrRAMRD          0x5d        /* RAM Read */
#define  LCDrPTLIN          0xa8        /* Partial IN */
#define  LCDrPTLOUT         0xa9        /* Partiel Out */
#define  LCDrRMWIN          0xe0        /* Read Modify IN */
#define  LCDrRMWOUT         0xee        /* Read Modify Out */
#define  LCDrASCSET         0xaa        /* Area Scroll Set */
#define  LCDrSCSTART        0xab        /* Scroll Start */
#define  LCDrOSCON          0xd1        /* Oscillator ON */
#define  LCDrOSCOFF         0xd2        /* Oscillator OFF */
#define  LCDrPWRCTR         0x20        /* Power Control */
#define  LCDrVOLCTR         0x81        /* Voltage Control */
#define  LCDrTMPGRD         0x82        /* Temperature Gradiant */

#define  LCDrVOLUP          0xd6        /* Voltage Increment */
#define  LCDrVOLDOWN        0xd7        /* Voltage Decrement */
#define  LCDrEPCTIN         0xcd        /* EEPROM Control */
#define  LCDrEPCOUT         0xcc        /* Cancel EEPROM Command */
#define  LCDrEPMWR          0xfc        /* EEPROM Write */
#define  LCDrEPMRD          0xfd        /* EEPROM Read */
#define  LCDrEPSRRD1        0x7c        /* Read Register */
#define  LCDrEPSRRD2        0x7d        /* Read Register */
#define  LCDrNOP            0x25        /* No Operation */

/* -----------------------------------------------------------------------------
   Following are the Software MACROS and Routines  
   ------------------------------------------------------------------------------ */

/***************************************************************************** 
* Define
*****************************************************************************/
#define  LCDrDISCTL_128DUTY      0x1f
#define  LCDrDISCTL_160DUTY      0x27
#define  LCDrDISCTL_11H          0x0a
#define  LCDrDISCTL_13H          0x0c
#define  LCDrCENTERSCROLL        0x00
#define  LCDrTOPSCROLL           0x01
#define  LCDrBOTTOMSCROLL        0x02
#define  LCDrALLSCROLL           0x03

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short int uint16;
typedef signed short int int16;
typedef unsigned int uint32;
typedef signed int int32;

/***************************************************************************** 
* Define
*****************************************************************************/
#define LCDrdelay()                          \
{                                            \
   uint16 _stat;                             \
   _stat = *(volatile uint16 *)LCDrDUMMYADDR;\
   _stat = *(volatile uint16 *)LCDrDUMMYADDR;\
   _stat = *(volatile uint16 *)LCDrDUMMYADDR;\
   _stat = *(volatile uint16 *)LCDrDUMMYADDR;\
}

#define LCDrCtrlWrite(_data)                \
{                                           \
   *(volatile uint16 *)LCDrCTRLAddr = _data;\
   LCDrdelay();                             \
}

#define LCDrDataWrite(_data)                \
{                                           \
   *(volatile uint16 *)LCDrDATAAddr = _data;\
   LCDrdelay();                             \
}

#define LCDrRAMWrite(_data)                 \
{                                           \
   *(volatile uint16 *)LCDrDATAAddr = _data;\
   LCDrdelay();                             \
}

#define LCDrRAMRead(_data)                  \
{                                           \
   _data = *(volatile uint16 *)LCDrDATAAddr;\
   LCDrdelay();                             \
}

#define LCDrDISPON()       LCDrCtrlWrite(LCDrDISON)
#define LCDrDISPOFF()      LCDrCtrlWrite(LCDrDISOFF)
#define LCDrNORMAL()       LCDrCtrlWrite(LCDrDISNOR)
#define LCDrINVERSE()      LCDrCtrlWrite(LCDrDISINV)

#define LCDrGENSLPIN()     LCDrCtrlWrite(LCDrSLPIN)
#define LCDrGENSLPOUT()    LCDrCtrlWrite(LCDrSLPOUT)

#define LCDrSetDATALL()      \
{                            \
   LCDrCtrlWrite(LCDrDATALL);\
   LCDrDataWrite(0x01);      \
}
#define LCDrCancelDATALL() LCDrCtrlWrite(LCDrDATCAN)

#define LCDrWrStart()      LCDrCtrlWrite(LCDrRAMWR)
#define LCDrRdStart()      LCDrCtrlWrite(LCDrRAMRD)

#define LCDrCtrlVOLUP()    LCDrCtrlWrite(LCDrVOLUP)
#define LCDrCtrlVOLDOWN()  LCDrCtrlWrite(LCDrVOLDOWN)

#define LCDrCTRLOSCON()    LCDrCtrlWrite(LCDrOSCON)
#define LCDrCTRLOSCOFF()   LCDrCtrlWrite(LCDrOSCOFF)

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void LCDrINIT(void);
extern void LCDrSETCOMSCAN(void);
extern void LCDrDISCONTROL(void);
extern void LCDrSetDATANORCTL(void);
extern void LCDrVOLTLEVEL(uint8 voltage);
extern void LCDrTEMPERATUREGRAD(void);
extern void LCDrPOWERCNTL(uint8 data);

extern void LCDrSetPageAddr(uint8 startPage, uint8 endPage);
extern void LCDrSetColAddr(uint8 startColumn, uint8 endColumn);

extern void LCDrDISPartial(uint8 startBlock, uint8 endBlock);
extern void LCDrDISPartialExit(void);

extern void LCDrConfAREAScroll(uint8 topBlock, uint8 bottomBlock, uint8 noOfBlocks, uint8 areaMode);
extern void LCDrScrollStart(uint8 startBlock);

extern void LCDrClearAll(void);
extern void LCDrblockClear(uint16 x1, uint16 y1, uint16 x2, uint16 y2);
extern void LCDrblockRead(uint16 x1, uint16 y1, uint16 x2, uint16 y2);
extern void LCDrBlockWrite(uint16 x1, uint16 y1, uint16 x2, uint16 y2);

extern void LCDrDrawRectangle(uint16 x1, uint16 y1, uint16 x2, uint16 y2, uint16 data);

extern void LCDrSize(uint16 *outLCDWidth, uint16 *outLCDHeight);

extern void LCDrTest(void);
extern void LCDrTestColours(void);

/*----------------------------------------------------------------------------------------
                        End of File LcdDr.h  
-----------------------------------------------------------------------------------------*/
#endif /* _LCDDR_H_ */ 

