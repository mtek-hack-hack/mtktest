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
 *    sim_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for SIM driver.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SIM_HW_H
#define _SIM_HW_H

//#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
#if !defined(DRV_SIM_REG_6208_SERIES) && !defined(DRV_SIM_REG_6205B_SERIES)
/*MT6218B || MT6219 || MT6217 || MT6226 || MT6227 || MT6228 || MT6229*/
   #define 	ACK_NULL_CHAR		0x60
   
   #define 	SIM_CTRL		   (SIM_base+0x0)
   #define 	SIM_CONF		   (SIM_base+0x4)
   #define 	SIM_BRR			(SIM_base+0x8)
   #define 	SIM_IRQEN		(SIM_base+0x10)
   #define 	SIM_STS			(SIM_base+0x14)
   
   #define 	SIM_RETRY		(SIM_base+0x20)
   #define 	SIM_TIDE	   	(SIM_base+0x24)
  
   #define 	SIM_DATA		   (SIM_base+0x30)
   #define 	SIM_COUNT		(SIM_base+0x34)
   
   #define 	SIM_ATIME		(SIM_base+0x40)
   #define 	SIM_DTIME		(SIM_base+0x44)
   #define 	SIM_TOUT		   (SIM_base+0x48)
   
   #define 	SIM_INS  		(SIM_base+0x60)
   #define 	SIM_IMP3  		(SIM_base+0x64)
   #define 	SIM_SW1  		(SIM_base+0x68)
   #define 	SIM_SW2  		(SIM_base+0x6c)
   #define 	SIM_STATUS		(SIM_base+0x74)
   
   //SIM_CTRL
   #define 	SIM_CTRL_SIMON		   0x0001
   #define 	SIM_CTRL_HALT		   0x0002   /* Enable Clk stop mode or disable */
   #define	SIM_CTRL_WRST			0x0004	/* Trigger a warm reset */
   
   //SIM_CONF
   #define 	SIM_CONF_RXHSK		   0x0001
   #define 	SIM_CONF_TXHSK		   0x0002
   #define 	SIM_CONF_CLKPO		   0x0004
   #define 	SIM_CONF_SINV		   0x0008
   #define 	SIM_CONF_SDIR		   0x0010
   #define 	SIM_CONF_ODDPARITY	0x0020
   #define 	SIM_CONF_SIMSEL		0x0040
   #define 	SIM_CONF_TOUTEN		0x0080
   #define 	SIM_CONF_T0EN		   0x0200
   #define 	SIM_CONF_HFEN		   0x0400
   #define 	SIM_CONF_T1EN		   0x0100
   
   #define  SIM_CONF_Direct		0x0000
   #define  SIM_CONF_InDirect	   0x0038
   
   //SIM_BRR
   #define 	SIM_BRR_CLKMSK		      0x0003
   #define 	SIM_BRR_CLK_Div2	      0x0000
   #define 	SIM_BRR_CLK_Div4	      0x0001
   #define 	SIM_BRR_CLK_Div8	      0x0002
   #define 	SIM_BRR_CLK_Div12	      0x0003
   
   #define 	SIM_BRR_BAUDMSK			0x000C
//#if ( (defined(MT6218B)) || (defined(MT6219)))
#if defined(DRV_SIM_REG_BAUD_6218B_SERIES)
   #define 	SIM_BRR_BAUD_Div372		(0x16<<2)		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		(0x03<<2)		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		(0x01<<2)		//F=512, D=16
#else /*!Mt6218B,MT6219*/
   #define 	SIM_BRR_BAUD_Div372		(372<<2)		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		(64<<2)		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		(32<<2)		//F=512, D=16
#endif   /*MT6218B,MT6219*/
   
   //SIM_IRQEN
   #define 	SIM_IRQEN_TX		      0x0001
   #define 	SIM_IRQEN_RX		      0x0002
   #define 	SIM_IRQEN_OV		      0x0004
   #define 	SIM_IRQEN_TOUT		      0x0008
   #define 	SIM_IRQEN_TXERR		   0x0010
   #define 	SIM_IRQEN_NATR		      0x0020
   #define 	SIM_IRQEN_SIMOFF        0x0040
   #define 	SIM_IRQEN_T0END         0x0080
   #define 	SIM_IRQEN_RXERR         0x0100
   
   #define 	SIM_IRQEN_ALL		      0x01bf
   #define 	SIM_IRQEN_ALLOFF	      0x0000
   /* SIM_IRQEN_TXErr, SIM_IRQEN_NATR, SIM_IRQEN_TOUT,SIM_IRQEN_OV,SIM_IRQEN_RX*/
   #define 	SIM_IRQEN_Normal	      0x013e
   /*SIM_IRQEN_T0END,SIM_IRQEN_TXErr,SIM_IRQEN_TOUT*/		
   #define 	SIM_IRQEN_CMDNormal	   0x019e
   /*#define 	SIM_IRQEN_CMDNormal	   0x019c*/
   #define 	SIM_IRQEN_CMDDMANormal	   0x019c
   #define	USIM_IRQEN_ATR				(SIM_IRQEN_RX|SIM_IRQEN_NATR)
   #define 	USIM_IRQEN_NORMAL			(SIM_STS_RX|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_TXERR|SIM_STS_RXERR)
   #define 	USIM_IRQEN_CMD_T1			(SIM_STS_EDCERR|SIM_STS_T1END|SIM_STS_RXERR| \
   											SIM_STS_OV|SIM_STS_TOUT)
   #define 	USIM_IRQEN_CMD_T1_RX		(SIM_STS_EDCERR|SIM_STS_T1END|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_RX)   
   #define 	USIM_IRQEN_CMD_T1_TX		(SIM_STS_T1END)
   
   //SIM_STS
   #define 	SIM_STS_TX		         0x0001
   #define 	SIM_STS_RX		         0x0002
   #define 	SIM_STS_OV		         0x0004
   #define 	SIM_STS_TOUT		      0x0008
   #define 	SIM_STS_TXERR		      0x0010
   #define 	SIM_STS_NATR		      0x0020
   #define 	SIM_STS_SIMOFF		      0x0040
   #define 	SIM_STS_T0END           0x0080
   #define 	SIM_STS_RXERR           0x0100
   #define 	SIM_STS_T1END				0x0200
   #define	SIM_STS_EDCERR				0x0400
   
   //SIM_TOUT
   #define 	SIM_TOUT_MSK		      0x3fff
   
   //SIM_RETRY
   #define 	SIM_RETRY_RXMASK	      0x0007
   #define 	SIM_RETRY_TXMASK	      0x0700
   
   //SIM_TIDE
   #define 	SIM_TIDE_RXMASK		   0x000f
   #define 	SIM_TIDE_TXMASK		   0x0f00
   
   //SIM_COUNT
   #define 	SIM_COUNT_MASK		      0x000f
   
   //SIM_INS
   #define 	SIM_INS_MASK  		      0x00ff
   #define 	SIM_INS_INSD  		      0x0100
   
   //SIM_IMP3
   #define  SIM_IMP3_MASK           0x01ff

	// SIM_STATUS
	#define	SIM_STATUS_EDC				0x40
	#define	SIM_STATUS_ACK				0x20
	#define 	SIM_STATUS_NACK			0x10
	#define	SIM_STATUS_IDLE			0x01
	#define	SIM_STATUS_INS				0x02
	#define	SIM_STATUS_SW1				0x04
	#define	SIM_STATUS_SW2				0x08

	#define SIM_TX_DELAY_LEN			0x4
	#define SIM_TX_DELAY_LOOP			4000
#endif   /*MT6218B*/

//#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
#if defined(DRV_SIM_REG_6205B_SERIES)
   #define 	ACK_NULL_CHAR		0x60
   
   #define 	SIM_CTRL		   (SIM_base+0x0)
   #define 	SIM_CONF		   (SIM_base+0x4)
   #define 	SIM_BRR			(SIM_base+0x8)
   #define 	SIM_IRQEN		(SIM_base+0xc)
   #define 	SIM_STS			(SIM_base+0x10)
   #define 	SIM_DATA		   (SIM_base+0x14)
   #define 	SIM_TOUT		   (SIM_base+0x18)
   #define 	SIM_RETRY		(SIM_base+0x1c)
   #define 	SIM_TIDE	   	(SIM_base+0x20)
   #define 	SIM_COUNT		(SIM_base+0x24)
   #define 	SIM_ATIME		(SIM_base+0x28)
   #define 	SIM_DTIME		(SIM_base+0x2C)
   #define 	SIM_INS  		(SIM_base+0x30)
   #define 	SIM_IMP3  		(SIM_base+0x34)
   #define 	SIM_SW1  		(SIM_base+0x38)
   #define 	SIM_SW2  		(SIM_base+0x3c)
   
   
   //SIM_CTRL
   #define 	SIM_CTRL_SIMON		   0x0001
   #define 	SIM_CTRL_HALT		   0x0002   /* Enable Clk stop mode or disable */
   #define	SIM_CTRL_WRST			0x0004	/* Trigger a warm reset */
   
   //SIM_CONF
   #define 	SIM_CONF_RXHSK		   0x0001
   #define 	SIM_CONF_TXHSK		   0x0002
   #define 	SIM_CONF_CLKPO		   0x0004
   #define 	SIM_CONF_SINV		   0x0008
   #define 	SIM_CONF_SDIR		   0x0010
   #define 	SIM_CONF_ODDPARITY	0x0020
   #define 	SIM_CONF_SIMSEL		0x0040
   #define 	SIM_CONF_TOUTEN		0x0080
   #define 	SIM_CONF_HALTEN		0x0100
   #define 	SIM_CONF_T0EN		   0x0200
   #define 	SIM_CONF_HFEN		   0x0400
   
   #define  SIM_CONF_Direct		0x0000
   #define  SIM_CONF_InDirect	   0x0038
   
   //SIM_BRR
   #define 	SIM_BRR_CLKMSK		      0x0003
   #define 	SIM_BRR_CLK_Div2	      0x0000
   #define 	SIM_BRR_CLK_Div4	      0x0001
   #define 	SIM_BRR_CLK_Div8	      0x0002
   #define 	SIM_BRR_CLK_Div12	      0x0003
   
   #define 	SIM_BRR_BAUDMSK			0x000C
//#ifdef MT6205B
#if defined(DRV_SIM_REG_BAUD_6205B)
   #define 	SIM_BRR_BAUD_Div372		0x000c		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div368		0x0000		//F=368, D=1
#else /*!MT6205B*/
   #define 	SIM_BRR_BAUD_Div372		0x0000		//F=372, D=1
#endif   /*MT6205B*/
   #define 	SIM_BRR_BAUD_Div64		0x0004		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		0x0008		//F=512, D=16
   
   //SIM_IRQEN
   #define 	SIM_IRQEN_TX		      0x0001
   #define 	SIM_IRQEN_RX		      0x0002
   #define 	SIM_IRQEN_OV		      0x0004
   #define 	SIM_IRQEN_TOUT		      0x0008
   #define 	SIM_IRQEN_TXERR		   0x0010
   #define 	SIM_IRQEN_NATR		      0x0020
   #define 	SIM_IRQEN_SIMOFF        0x0040
   #define 	SIM_IRQEN_T0END         0x0080
   #define 	SIM_IRQEN_RXERR         0x0100
   
   #define 	SIM_IRQEN_ALL		      0x01bf
   #define 	SIM_IRQEN_ALLOFF	      0x0000
   /* SIM_IRQEN_TXErr, SIM_IRQEN_NATR, SIM_IRQEN_TOUT,SIM_IRQEN_OV,SIM_IRQEN_RX*/
   #define 	SIM_IRQEN_Normal	      0x013e
   /*SIM_IRQEN_T0END,SIM_IRQEN_TXErr,SIM_IRQEN_TOUT*/		
   #define 	SIM_IRQEN_CMDNormal	   0x019e
   /*#define 	SIM_IRQEN_CMDNormal	   0x019c*/
   #define 	SIM_IRQEN_CMDDMANormal	   0x019c
   
   //SIM_STS
   #define 	SIM_STS_TX		         0x0001
   #define 	SIM_STS_RX		         0x0002
   #define 	SIM_STS_OV		         0x0004
   #define 	SIM_STS_TOUT		      0x0008
   #define 	SIM_STS_TXERR		      0x0010
   #define 	SIM_STS_NATR		      0x0020
   #define 	SIM_STS_SIMOFF		      0x0040
   #define 	SIM_STS_T0END           0x0080
   #define 	SIM_STS_RXERR           0x0100
   
   //SIM_TOUT
   #define 	SIM_TOUT_MSK		      0x3fff
   
   //SIM_RETRY
   #define 	SIM_RETRY_RXMASK	      0x0007
   #define 	SIM_RETRY_TXMASK	      0x0700
   
   //SIM_TIDE
   #define 	SIM_TIDE_RXMASK		   0x000f
   #define 	SIM_TIDE_TXMASK		   0x0f00
   
   //SIM_COUNT
   #define 	SIM_COUNT_MASK		      0x000f
   
   //SIM_INS
   #define 	SIM_INS_MASK  		      0x00ff
   #define 	SIM_INS_INSD  		      0x0100
   
   //SIM_IMP3
   #define  SIM_IMP3_MASK           0x01ff
#endif /*(MT6205,MT6205B,MT6218)*/

//#if ( (defined(MT6208)) || (defined(FPGA)) )
#if defined(DRV_SIM_MT6208_SERIES)
   #define 	MAX_FIFO_SIZE		31
   #define 	ACK_NULL_CHAR		0x60
   
   #define 	LISR_COMPLETE		0x80
   
   #define 	SIM_CTRL		(SIM_base+0x0)
   #define 	SIM_CONF		(SIM_base+0x4)
   #define 	SIM_BRR			(SIM_base+0x8)
   #define 	SIM_IRQEN		(SIM_base+0xc)
   #define 	SIM_STS			(SIM_base+0x10)
   #define 	SIM_DATA		(SIM_base+0x14)
   #define 	SIM_TOUT		(SIM_base+0x18)
   #define 	SIM_RETRY		(SIM_base+0x1c)
   #define 	SIM_TIDE		(SIM_base+0x20)
   #define 	SIM_COUNT		(SIM_base+0x24)
   #define 	SIM_ATIME		(SIM_base+0x28)
   #define 	SIM_DTIME		(SIM_base+0x2C)
   
   
   //SIM_CTRL
   #define 	SIM_CTRL_SIMON		   0x0001
   #define 	SIM_CTRL_HALT		   0x0002   /* Enable Clk stop mode or disable */
   
   //SIM_CONF
   #define 	SIM_CONF_RXHSK		   0x0001
   #define 	SIM_CONF_TXHSK		   0x0002
   #define 	SIM_CONF_CLKPO		   0x0004
   #define 	SIM_CONF_SINV		   0x0008
   #define 	SIM_CONF_SDIR		   0x0010
   #define 	SIM_CONF_ODDPARITY	0x0020
   #define 	SIM_CONF_SIMSEL		0x0040
   #define 	SIM_CONF_TOUTEN		0x0080
   
   #define         SIM_CONF_Direct		0x0000
   #define         SIM_CONF_InDirect	0x0038
   
   //SIM_BRR
   #define 	SIM_BRR_CLKMSK		0x0003
   #define 	SIM_BRR_CLK_Div2	0x0000
   #define 	SIM_BRR_CLK_Div4	0x0001
   #define 	SIM_BRR_CLK_Div8	0x0002
   #define 	SIM_BRR_CLK_Div12	0x0003
   
   #define 	SIM_BRR_BAUDMSK			0x000C
   #define 	SIM_BRR_BAUD_Div372		0x0000		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		0x0004		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		0x0008		//F=512, D=16
   
   //SIM_IRQEN
   #define 	SIM_IRQEN_TX		0x0001
   #define 	SIM_IRQEN_RX		0x0002
   #define 	SIM_IRQEN_OV		0x0004
   #define 	SIM_IRQEN_TOUT		0x0008
   #define 	SIM_IRQEN_TXERR   0x0010
   #define 	SIM_IRQEN_NATR		0x0020
   #define 	SIM_IRQEN_SIMOFF	0x0040
   
   #define 	SIM_IRQEN_ALL		      0x01bf
   #define 	SIM_IRQEN_ALLOFF	      0x0000
   /* SIM_IRQEN_TXErr, SIM_IRQEN_NATR, SIM_IRQEN_TOUT,SIM_IRQEN_OV,SIM_IRQEN_RX*/
   #define 	SIM_IRQEN_Normal	      0x03e
   
   //SIM_STS
   
   #define 	SIM_STS_TX		   0x0001
   #define 	SIM_STS_RX		   0x0002
   #define 	SIM_STS_OV		   0x0004
   #define 	SIM_STS_TOUT		0x0008
   #define 	SIM_STS_TXERR		0x0010
   #define 	SIM_STS_NATR		0x0020
   #define 	SIM_STS_SIMOFF		0x0040
   
   //SIM_DATA
   #define 	SIM_DATA_DATAMSK	   0x00ff
   #define 	SIM_DATA_PARITY		0x0100
   
   //SIM_TOUT
   #define 	SIM_TOUT_MSK		0x3fff
   
   //SIM_RETRY
   #define 	SIM_RETRY_RXMASK	0x0007
   #define 	SIM_RETRY_TXMASK	0x0700
   
   //SIM_TIDE
   #define 	SIM_TIDE_RXMASK		0x001f
   #define 	SIM_TIDE_TXMASK		0x1f00
   
   //SIM_TXCNT
   #define 	SIM_COUNT_MASK		0x001f
#endif   /*(MT6208,FPGA)*/

#endif   /*_SIM_HW_H*/

