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
 * usb_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file intends for usb hardware register definitions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USB_HW_H
#define USB_HW_H


#if (defined(DRV_USB_IP_V3))
#define USB_base		0x60000000
#else
#define USB_base		0x70000000
#endif


#if (defined(DRV_USB_IP_V3))

#define USB_FADDR		(USB_base+0x00)	/* RW */
#define USB_POWER		(USB_base+0x01)
#define USB_INTRTX		(USB_base+0x02)	/* 16-bit, status, read only */
#define USB_INTRRX		(USB_base+0x04) 	/* 16-bit, status, read only */
#define USB_INTRTXE		(USB_base+0x06)	/* 16-bit, RW */
#define USB_INTRRXE		(USB_base+0x08) 	/* 16-bit, RW */
#define USB_INTRUSB		(USB_base+0x0A) 	/* 8-bit, status, read only*/
#define USB_INTRUSBE	(USB_base+0x0B)	/* 8-bit, RW */
#define USB_FRAME		(USB_base+0x0C)	/* 16-bit, read only */ /*Max Frame length = 11 bits*/
#define USB_INDEX		(USB_base+0x0E) /* RW, 4bit available*/
#define USB_TESTMODE	(USB_base+0x0F) /* RW, 8-bit  */

#define USB_CSR0		(USB_base+0x12) /* 16-bit */
#define USB_COUNT0		(USB_base+0x18)	/* RO, EP0 only*/
#define USB_NAKLIMIT0	(USB_base+0x1B)	/* RW, host mode only*/
#define USB_TXMAXP		(USB_base+0x10)	/* 16-bit, RW*/
#define USB_TXCSR		(USB_base+0x12)
#define USB_RXMAXP		(USB_base+0x14)	/* 16-bit, RW*/
#define USB_RXCSR		(USB_base+0x16)
#define USB_RXCOUNT	(USB_base+0x18)	/* RO, 14bits */
#define USB_TXTYPE		(USB_base+0x1A)	/* RW, host mode only */
#define USB_TXINTERVAL	(USB_base+0x1B)	/* RW, host mode only */
#define USB_RXTYPE		(USB_base+0x1C)	/* RW, host mode only */
#define USB_RXINTERVAL	(USB_base+0x1D)	/* RW, host mode only */

#define USB_EP0			(USB_base+0x20)	/* 4 byte as 1 queue */

#define USB_DEVCTL		(USB_base+0x60) /* 8-bit  */
#define USB_PWRUPCNT	(USB_base+0x61) /* RW */
#define USB_TXFIFOSZ	(USB_base+0x62) /* RW */
#define USB_RXFIFOSZ	(USB_base+0x63) /* RW */
#define USB_TXFIFOADD	(USB_base+0x64) /* RW */
#define USB_RXFIFOADD	(USB_base+0x66) /* RW */
#define USB_SWRST		(USB_base+0x70) /* RW */
#define USB_VPLEN		(USB_base+0x7B) /* RW, 8-bits */
#define USB_RSTINFO		(USB_base+0x7F) /* RW */


#define USB_DMAINTR			(USB_base+0x200) 				/* 8-bits, W0C */
#define USB_DMALIMITER			(USB_base+0x210) 				/* 8-bits, RW */
#define USB_DMACNTL(_n) 		(USB_base+0x1F4+(0x10*(_n))) 	/* RW, _n = 1~6 */
#define USB_DMAADDR(_n)		(USB_base+0x1F8+(0x10*(_n))) 	/* RW, _n = 1~6 */
#define USB_DMACNT(_n)			(USB_base+0x1FC+(0x10*(_n))) 	/* RW, _n = 1~6 */
#define USB_DMAPPCNTL(_n)		(USB_base+0x274+(0x10*(_n))) 	/* RW, _n = 1~6 */
#define USB_DMAPPADDR(_n)		(USB_base+0x278+(0x10*(_n))) 	/* RW, _n = 1~6 */
#define USB_DMAPPCNT(_n)		(USB_base+0x27C+(0x10*(_n))) 	/* RW, _n = 1~6 */

#define USB_RQPKTCOUNT(_n)		(USB_base+0x300+(0x02*(_n))) 	/* RW, 16bits,  _n = 1~3, host mode RX ep only */

#define USB_DMA_REALCNT(_n)		(USB_base+0x3F0+(0x10*(_n))) 	/* RO, _n = 1~6, 32bits  */
#define USB_DMA_PP_REALCNT(_n)	(USB_base+0x3F4+(0x10*(_n))) 	/* RO, _n = 1~6, 32bits  */
#define USB_DMA_TIMER(_n)			(USB_base+0x3F8+(0x10*(_n))) 	/* RW, _n = 1~6, 16bits */
#define USB_PHY_CON1				(USB_base+0x600) /* RW */
#define USB_PHY_CON2				(USB_base+0x604) /* RW */
#define USB_PHY_CON3				(USB_base+0x608) /* RW */
#define USB_PHY_CON4				(USB_base+0x60C) /* RW */
#define USB_PHY_CON5				(USB_base+0x610) /* RW */
#define USB_PHY_INTF1				(USB_base+0x614) /* RW */
#define USB_PHY_INTF2				(USB_base+0x618) /* RW */


/* USB_POWER */
#define USB_POWER_ENABLESUSPENDM	(0x01)   /* RW */
#define USB_POWER_SUSPENDMODE		(0x02)   /* P: RO ; H: WO */ /*Read clear by the intr. register*/
#define USB_POWER_RESUME				(0x04)   /* RW */
#define USB_POWER_RESET				(0x08)   /* P: RO ; H: RW */
#define USB_POWER_HSMODE				(0x10)   /* RO */
#define USB_POWER_HSENAB				(0x20)   /* RW */
#define USB_POWER_SOFTCONN			(0x40)   /* RW */
#define USB_POWER_ISOUPDATE			(0x80)   /* RW */

/* USB_INTRTX */
#define USB_INTRTX_EP0			(0x01)   /*RO*/
#define USB_INTRTX_EP1			(0x02)   /*RO*/
#define USB_INTRTX_EP2			(0x04)   /*RO*/
#define USB_INTRTX_EP3			(0x08)   /*RO*/
#define USB_INTRTX_EP4			(0x10)   /*RO*/

/* USB_INTRRX */
#define USB_INTRRX_EP1			(0x02)   /*RO*/
#define USB_INTRRX_EP2			(0x04)   /*RO*/
#define USB_INTRRX_EP3			(0x08)   /*RO*/

/* USB_INTRTXE & USB_INTRRXE */
#define USB_INTRE_EPEN			(0x01)   /* RW */
#define USB_INTRE_EPDIS			(0x00)   /* RW */

/* USB_INTRUSB */
#define USB_INTRUSB_SUSPEND	(0x01)   /*RO*/
#define USB_INTRUSB_RESUME	(0x02)   /*RO*/
#define USB_INTRUSB_RESET		(0x04)   /*RO*/
#define USB_INTRUSB_BABBLE		(0x04)   /*RO*/
#define USB_INTRUSB_SOF		(0x08)   /*RO*/
#define USB_INTRUSB_CONN		(0x10)   /*RO*/
#define USB_INTRUSB_DISCON		(0x20)   /*RO*/
#define USB_INTRUSB_SESSREQ	(0x40)   /*RO*/
#define USB_INTRUSB_VBUSERROR	(0x80)   /*RO*/

/* USB_INTRUSBE */
#define USB_INTRUSBE_SUSPEND	(0x01)   /*RW*/
#define USB_INTRUSBE_RESUME	(0x02)   /*RW*/
#define USB_INTRUSBE_RESET		(0x04)   /*RW*/
#define USB_INTRUSBE_BABBLE	(0x04)   /*RW*/
#define USB_INTRUSBE_SOF		(0x08)   /*RW*/
#define USB_INTRUSBE_CONN		(0x10)   /*RW*/
#define USB_INTRUSBE_DISCON	(0x20)   /*RW*/
#define USB_INTRUSBE_SESSREQ	(0x40)   /*RW*/
#define USB_INTRUSBE_VBUSERROR (0x80)   /*RW*/

/* USB_TESTMODE */
#define USB_TESTMODE_TESTSE0NAK 	(0x01)	/* RW */
#define USB_TESTMODE_TESTJ 		(0x02)	/* RW */
#define USB_TESTMODE_TESTK 		(0x04)	/* RW */
#define USB_TESTMODE_TESTPACKET 	(0x08)	/* RW */
#define USB_TESTMODE_FORCEHS 		(0x10)	/* RW */
#define USB_TESTMODE_FORCEFS 		(0x20)	/* RW */
#define USB_TESTMODE_FIFOACCESS 	(0x40)	/* WO, AC */
#define USB_TESTMODE_FORCEHOST 	(0x80)	/* RW */

/* USB_DEVCTL */
#define USB_DEVCTL_SESSION			(0x01)	 /* RW */ 
#define USB_DEVCTL_HOSTREQ		(0x02)	 /* RW */ 
#define USB_DEVCTL_HOSTMODE		(0x04)	 /* RO */ 
#define USB_DEVCTL_VBUS			(0x18)	 /* RO */ 
#define USB_DEVCTL_LSDEV			(0x20)	 /* RO */ 
#define USB_DEVCTL_FSDEV			(0x40)	 /* RO */ 
#define USB_DEVCTL_BDEVICE			(0x80)	 /* RO */ 

/* USB_CSR0 */
#define USB_CSR0_RXPKTRDY				(0x0001)   /* RO */
#define USB_CSR0_TXPKTRDY				(0x0002)   /* RW, AC */
#define USB_CSR0_SENTSTALL				(0x0004)   /* RC */
#define USB_CSR0_DATAEND				(0x0008)   /* WO, AC */
#define USB_CSR0_SETUPEND				(0x0010)   /* RO */
#define USB_CSR0_SENDSTALL				(0x0020)   /* WO, AC */
#define USB_CSR0_SERVICEDRXPKTRDY		(0x0040)   /* WO, AC */
#define USB_CSR0_SERVICEDSETUPEND		(0x0080)   /* WO, AC */
#define USB_CSR0_FLUSHFIFO				(0x0100)   /* WO, AC */
/* in Host mode */
#define USB_CSR0_RXSTALL				(0x0004)  
#define USB_CSR0_SETUPPKT				(0x0008)   
#define USB_CSR0_ERROR					(0x0010)  
#define USB_CSR0_REQPKT				(0x0020)  
#define USB_CSR0_STATUSPKT				(0x0040)   
#define USB_CSR0_NAKTIMEOUT			(0x0080) 
#define USB_CSR0_FLUSHFIFO				(0x0100)  
#define USB_CSR0_DISPING				(0x0800)  

/* USB_TXMAXP */
#define USB_TXMAXP_MAXPAYLOAD_MASK	(0x07FF)
#define USB_TXMAXP_HIGHSPEED_MASK	(0xF800)

/* USB_TXCSR */
#define USB_TXCSR_TXPKTRDY				(0x0001)   /* RW */
#define USB_TXCSR_FIFONOTEMPTY		(0x0002)   /* RO */
#define USB_TXCSR_UNDERRUN			(0x0004)   /* RW */
#define USB_TXCSR_FLUSHFIFO			(0x0008)   /* WO */
#define USB_TXCSR_SENDSTALL			(0x0010)   /* RW */
#define USB_TXCSR_SENTSTALL			(0x0020)   /* RC */
#define USB_TXCSR_CLRDATATOG			(0x0040)   /* WO */
#define USB_TXCSR_INCOMPTX				(0x0080)   /* RC */
#define USB_TXCSR_AUTOSET_SPKT		(0x0200)   /* RW */
#define USB_TXCSR_DMAREQMODE			(0x0400)   /* RW */
#define USB_TXCSR_FRCDATATOG			(0x0800)   /* RW */
#define USB_TXCSR_DMAREQENAB			(0x1000)   /* RW */
#define USB_TXCSR_MODE					(0x2000)   /* RW */
#define USB_TXCSR_ISO					(0x4000)   /* RW */
#define USB_TXCSR_AUTOSET				(0x8000)   /* RW */
/* in Host mode */
#define USB_TXCSR_ERROR				(0x0004)   
#define USB_TXCSR_RXSTALL				(0x0020)   
#define USB_TXCSR_NAKTIMEOUT			(0x0080)

/* USB_RXMAXP */
#define USB_RXMAXP_MAXPAYLOAD_MASK	(0x07FF)
#define USB_RXMAXP_HIGHSPEED_MASK	(0xF800)

/* USB_RXCSR */
#define USB_RXCSR_RXPKTRDY				(0x0001)   /* RC */
#define USB_RXCSR_FIFOFULL				(0x0002)   /* RO, AC */
#define USB_RXCSR_OVERRUN				(0x0004)   /* RC */
#define USB_RXCSR_DATAERROR			(0x0008)   /* RO */
#define USB_RXCSR_FLUSHFIFO			(0x0010)   /* WO, AC */
#define USB_RXCSR_SENDSTALL			(0x0020)   /* RW */
#define USB_RXCSR_SENTSTALL			(0x0040)   /* RC */
#define USB_RXCSR_CLRDATATOG			(0x0080)   /* WO */
#define USB_RXCSR_INCOMPRX				(0x0100)	  /* RC */
#define USB_RXCSR_INCOMPRXINTREN		(0x0200)	  /* RC */
#define USB_RXCSR_AUTOCLREN_SPKT		(0x0400)	  /* RC */
#define USB_RXCSR_DMAREQMODE			(0x0800)   /* RW */
#define USB_RXCSR_DISNYET				(0x1000)   /* RW */
#define USB_RXCSR_PIDERROR				(0x1000)   /* RO */
#define USB_RXCSR_DMAREQENAB			(0x2000)   /* RW */
#define USB_RXCSR_ISO					(0x4000)   /* RW */
#define USB_RXCSR_AUTOCLEAR			(0x8000)   /* RW */
/* in Host mode */
#define USB_RXCSR_ERROR				(0x0004) 
#define USB_RXCSR_NAKTIMEOUT			(0x0008) 
#define USB_RXCSR_REQPKT				(0x0020) 
#define USB_RXCSR_RXSTALL				(0x0040)
#define USB_RXCSR_AUTOREQ				(0x4000)

/* USB_TXTYPE */
#define USB_TXTYPE_EPNUM_MASK		(0x0f)
#define USB_TXTYPE_ISO					(0x10)
#define USB_TXTYPE_BULK				(0x20)
#define USB_TXTYPE_INTR				(0x30)
#define USB_TXTYPE_PROTOCOL_MASK		(0x30)

/* USB_RXTYPE */
#define USB_RXTYPE_EPNUM_MASK		(0x0f)
#define USB_RXTYPE_ISO					(0x10)
#define USB_RXTYPE_BULK				(0x20)
#define USB_RXTYPE_INTR				(0x30)
#define USB_RXTYPE_PROTOCOL_MASK		(0x30)

/* USB_PWRUPCNT */
#define USB_PWRUPCNT_MASK				(0x0f)

/* USB_FIFOSZ */
#define USB_FIFOSZ_SIZE_MASK			(0x0F)
#define USB_FIFOSZ_DPB					(0x10)
#define USB_FIFOSZ_SIZE_8				(0x00)
#define USB_FIFOSZ_SIZE_16				(0x01)
#define USB_FIFOSZ_SIZE_32				(0x02)
#define USB_FIFOSZ_SIZE_64				(0x03)
#define USB_FIFOSZ_SIZE_128			(0x04)
#define USB_FIFOSZ_SIZE_256			(0x05)
#define USB_FIFOSZ_SIZE_512			(0x06)
#define USB_FIFOSZ_SIZE_1024			(0x07)
#define USB_FIFOSZ_SIZE_2048			(0x08)
#define USB_FIFOSZ_SIZE_4096			(0x09)

/* USB_FIFOADD */
#define USB_FIFOADD_MASK				(0x1FFF)

/* USB_RXFIFOADD */
#define USB_RXFIFOADD_DATAERRINTREN   (0x8000)
#define USB_RXFIFOADD_OVERRUNINTREN   (0x4000)

/* USB_FIFO2ADD */
#define USB_FIFO2ADD_MASK				(0x1FFF)
#define USB_FIFO2ADD_EN				(0x8000)

/* USB_SWRST */
#define USB_SWRST_DISUSBRESET			(0x0001)
#define USB_SWRST_SWRST				(0x0002)
#define USB_SWRST_FRC_VBUSVALID		(0x0004)
#define USB_SWRST_UNDO_SRPFIX			(0x0008)
#define USB_SWRST_REDUCE_DLY			(0x0010)


/* USB_RSTINFO */
#define USB_RSTINFO_WTFSSE0			(0x00F0)
#define USB_RSTINFO_WTCHRP			(0x000F)

/* USB_DMAINTR */
#define USB_DMA_INTR_MASK				0xFFFFFF00
#define USB_DMA_LIMITER_MASK			0xFFFF00FF
#define USB_DMA_PPFINISH_MASK 		0x0000FFFF

/* USB_DMAPPINTR */
#define USB_PPA_FINISH1				(0x01)   /*RO*/
#define USB_PPB_FINISH1					(0x02)   /*RO*/
#define USB_PPA_FINISH2				(0x04)   /*RO*/
#define USB_PPB_FINISH2					(0x08)   /*RO*/
#define USB_PPA_FINISH3				(0x10)   /*RO*/
#define USB_PPB_FINISH3					(0x20)   /*RO*/
#define USB_PPA_FINISH4				(0x40)   /*RO*/
#define USB_PPB_FINISH4					(0x80)   /*RO*/

/* USB_DMACNTL */
#define USB_DMACNTL_DMAEN				(0x0001)
#define USB_DMACNTL_DMADIR			(0x0002)
#define USB_DMACNTL_DMAMODE			(0x0004)
#define USB_DMACNTL_INTEN				(0x0008)
#define USB_DMACNTL_EP_MASK			(0x00F0)
#define USB_DMACNTL_BUSERR			(0x0100)
//#define USB_DMACNTL_BURSTMODE_MASK	(0x0600)
#define USB_DMACNTL_BURSTMODE_MASK	(0x0000)
#define USB_DMACNTL_PPEN				(0x0800)
#define USB_DMACNTL_PPRST				(0x1000)
#define USB_DMACNTL_ENDMAMODE2		(0x2000)

/* USB_DMAPPCNTL */
#define USB_DMAPPCNTL_DMAEN			(0x0001)

/* USB_DMA_TIMER */
#define USB_DMA_TIMER_ENTIMER				(0x0080)
#define USB_DMA_TIMER_TIMEOUT_MASK		(0x007F)
#define USB_DMA_TIMER_TIMEOUT_STATUS	(0x0100)

/* USB_PHY_CON1 */
#define USB_PHY_CON1_PLL_EN				(0x0080)

/* USB_PHY_CON5 */
#define USB_PHY_CON5_FORCE_SUSPENDM		(0x040000)
#define USB_PHY_CON5_FORCE_IDPULLUP		(0x800000)

/* USB_PHY_INTF1 */
#define USB_PHY_INTF1_IDPULLUP			(0x01)

/* descriptor setting limitation */
#define USB_FIFO_START_ADDRESS		512

#define USB_BULK_FIFO_UNIT_SIZE		512
#ifdef  __ISO_HB__
#define USB_ISO_FIFO_UNIT_SIZE			3072
#else
#define USB_ISO_FIFO_UNIT_SIZE			1024
#endif


#ifdef  __INTR_HB__
#define USB_INTR_FIFO_UNIT_SIZE			3072
#else
#define USB_INTR_FIFO_UNIT_SIZE			1024
#endif


#elif (defined(DRV_USB_IP_V2))

#define OTG_INT_STAT				(USB_base+0x10)
#define OTG_INT_EN					(USB_base+0x14)
#define OTG_STATUS					(USB_base+0x18)
#define OTG_CTRL					(USB_base+0x1c)

#define USB_FM_PKT_NUML				(USB_base+0x20)
#define USB_FM_PKT_NUMH				(USB_base+0x24)
#define USB_FM_ERR_STAT				(USB_base+0x28)
#define USB_FM_CTL					(USB_base+0x2c)
#define USB_FM_PKT_CNTL				(USB_base+0x30)
#define USB_FM_PKT_CNTH				(USB_base+0x34)
#define USB_FM_TIMEOUT				(USB_base+0x38)
#define USB_FM_STATUS				(USB_base+0x3c)
#define USB_FM_ADDITNL_STAT			(USB_base+0x50)
#define USB_FM_ENDPT				(USB_base+0x68)
#define USB_FM_INT_MASK				(USB_base+0x6c)
#define USB_PHY_EXTRA				(USB_base+0x70)

#define USB_INT_STAT				(USB_base+0x80)
#define USB_INT_ENB					(USB_base+0x84)
#define USB_ERR_STAT				(USB_base+0x88)
#define USB_ERR_ENB					(USB_base+0x8c)
#define USB_STAT					(USB_base+0x90)
#define USB_CTL						(USB_base+0x94)
#define USB_ADDR					(USB_base+0x98)
#define USB_BDT_PAGE_01				(USB_base+0x9c)
#define USB_BDT_PAGE_02				(USB_base+0xb0)
#define USB_BDT_PAGE_03				(USB_base+0xb4)
#define USB_FRM_NUML				(USB_base+0xa0)
#define USB_FRM_NUMH				(USB_base+0xa4)
#define USB_TOKEN					(USB_base+0xa8)
#define USB_SOF_THLD				(USB_base+0xac)
#define USB_ENDPT_CTL_BASE			(USB_base+0xc0)
#define USB_ENDPT_CTL(n)			(USB_ENDPT_CTL_BASE+4*n)	

#define USB_DMA_ENB					(USB_base+0x410)
#define USB_DMA_DIS					(USB_base+0x414)
#define USB_DMA_ADDR_CNTER_CLR		(USB_base+0x418)
#define USB_DMA_FM_SELECT			(USB_base+0x41c)
#define USB_SOFT_RST				(USB_base+0x420)
#define USB_PHY_CTL					(USB_base+0x450)

#define USB_FIFO_RX0_EVEN			(USB_base+0x200)
#define USB_FIFO_RX0_ODD			(USB_base+0x208)
#define USB_FIFO_TX0_EVEN			(USB_base+0x210)
#define USB_FIFO_TX0_ODD			(USB_base+0x218)
#define USB_FIFO_RX1				(USB_base+0x220)
#define USB_FIFO_TX1				(USB_base+0x260)
#define USB_FIFO_RX2				(USB_base+0x2a0)
#define USB_FIFO_TX2				(USB_base+0x2e0)
#define USB_FIFO_RX3				(USB_base+0x320)
#define USB_FIFO_TX3				(USB_base+0x328)


#define USB_BDT_RX0_EVEN			(USB_base+0x330)
#define USB_BDT_RX0_ODD				(USB_base+0x338)
#define USB_BDT_TX0_EVEN			(USB_base+0x340)
#define USB_BDT_TX0_ODD				(USB_base+0x348)
#define USB_BDT_RX1					(USB_base+0x350)
#define USB_BDT_TX1					(USB_base+0x358)
#define USB_BDT_RX2					(USB_base+0x360)
#define USB_BDT_TX2					(USB_base+0x368)
#define USB_BDT_RX3					(USB_base+0x370)
#define USB_BDT_TX3					(USB_base+0x378)

/* VUSB Endpoint control register masks */
/* Define the bits within the endpoint control register */
#define VUSB_ENDPT_HSHK_BIT			(0x01)
#define VUSB_ENDPT_STALL_BIT 		(0x02)
#define VUSB_ENDPT_TX_EN_BIT		(0x04)
#define VUSB_ENDPT_RX_EN_BIT		(0x08)
#define VUSB_ENDPT_CTL_EP_CTL_DIS	(0x10)
#define VUSB_ENDPT_CTL_RETRY_DIS	(0x40)
#define VUSB_ENDPT_CTL_HOST_WO_HUB	(0x80)

#define VUSB_ENDPT_DISABLE			(0x00)
#define VUSB_ENDPT_CONTROL			(VUSB_ENDPT_HSHK_BIT | VUSB_ENDPT_TX_EN_BIT | \
										VUSB_ENDPT_RX_EN_BIT | VUSB_ENDPT_CTL_RETRY_DIS)
#define VUSB_ENDPT_BULK_RX			(VUSB_ENDPT_HSHK_BIT | VUSB_ENDPT_RX_EN_BIT | \
										VUSB_ENDPT_CTL_EP_CTL_DIS | VUSB_ENDPT_CTL_RETRY_DIS)
#define VUSB_ENDPT_BULK_TX			(VUSB_ENDPT_HSHK_BIT | VUSB_ENDPT_TX_EN_BIT | \
										VUSB_ENDPT_CTL_EP_CTL_DIS | VUSB_ENDPT_CTL_RETRY_DIS)
#define VUSB_ENDPT_BULK_BIDIR		(VUSB_ENDPT_HSHK_BIT | VUSB_ENDPT_TX_EN_BIT | \
										VUSB_ENDPT_RX_EN_BIT | VUSB_ENDPT_CTL_EP_CTL_DIS | VUSB_ENDPT_CTL_RETRY_DIS)
#define VUSB_ENDPT_ISO_RX			(VUSB_ENDPT_RX_EN_BIT | VUSB_ENDPT_CTL_EP_CTL_DIS | \
										VUSB_ENDPT_CTL_RETRY_DIS)
#define VUSB_ENDPT_ISO_TX			(VUSB_ENDPT_TX_EN_BIT | VUSB_ENDPT_CTL_EP_CTL_DIS | \
										VUSB_ENDPT_CTL_RETRY_DIS)
#define VUSB_ENDPT_ISO_BIDIR		(VUSB_ENDPT_RX_EN_BIT | VUSB_ENDPT_TX_EN_BIT | \
										VUSB_ENDPT_CTL_EP_CTL_DIS | VUSB_ENDPT_CTL_RETRY_DIS)										

/* VUSB Control register masks */
#define  VUSB_CTL_USB_EN			(0x01)
#define  VUSB_CTL_SOF_EN			(0x01)
#define  VUSB_CTL_ODD_RST			(0x02)
#define  VUSB_CTL_RESUME			(0x04)
#define  VUSB_CTL_HOST_MODE_EN		(0x08)
#define  VUSB_CTL_RESET				(0x10)
#define  VUSB_CTL_TOKEN_BUSY		(0x20)
#define  VUSB_CTL_TXD_SUSPEND		(0x20)
#define  VUSB_CTL_SINGLE_ENDED_0	(0x40)
#define  VUSB_CTL_JSTATE			(0x80)

/* VUSB Interrupt status register masks */
#define VUSB_INT_STAT_RESET			(0x01)
#define VUSB_INT_STAT_ERROR			(0x02)
#define VUSB_INT_STAT_SOF			(0x04)
#define VUSB_INT_STAT_TOKEN_DONE	(0x08)
#define VUSB_INT_STAT_SLEEP			(0x10)
#define VUSB_INT_STAT_RESUME		(0x20)
#define VUSB_INT_STAT_ATTACH		(0x40)
#define VUSB_INT_STAT_STALL			(0x80)

/* VUSB Interrupt enable register masks*/
#define VUSB_INT_ENB_RESET			(0x01)
#define VUSB_INT_ENB_ERROR			(0x02)
#define VUSB_INT_ENB_SOF			(0x04)
#define VUSB_INT_ENB_TOKEN_DONE		(0x08)
#define VUSB_INT_ENB_SLEEP			(0x10)
#define VUSB_INT_ENB_RESUME			(0x20)
#define VUSB_INT_ENB_ATTACH			(0x40)
#define VUSB_INT_ENB_STALL			(0x80)

/* VUSB Fast mode error status register masks */
#define USB_FM_ERR_STA_OVR_FLW		(0x80)
#define VUSB_FM_ERR_STAT_TOKEN_DONE	(0x40)
#define VUSB_FM_ERR_SUC_ERR			(0x04)
#define VUSB_FM_ERR_NAK_ERR			(0x02)
#define VUSB_FM_ERR_SHORT_ERR		(0x01)

/* VUSB Fast mode control register masks */
#define VUSB_FM_CTL_FMENB			(0x1)
#define VUSB_FM_CTL_SUCERREN		(0x8)
#define VUSB_FM_CTL_EP_RX_ODD_SHIFT		1
#define VUSB_FM_CTL_EP_TX_ODD_SHIFT		2
#define VUSB_FM_CTL_EP_TOG_BIT_SHIFT	6

/* VUSB Fast mode endpoint register masks*/
#define VUSB_FM_EP_TX				(0x10)
#define VUSB_FM_EP_TX_RES			(0x80)
#define VUSB_FM_EP_ENDPT_MASK		(0x0f)

/* VUSB FM DMA index */
#define VUSB_FM_DMA_RX1				0
#define VUSB_FM_DMA_TX1				1
#define VUSB_FM_DMA_RX2				2
#define VUSB_FM_DMA_TX2				3

/* VUSB EXTRA register masks*/
#define VUSB_PHY_RESUME_INT			(0x80)	
#define VUSB_PHY_RESUME_INT_ENB		(0x04)
#define VUSB_PHY_SUSPEND			(0x02)

/* VUSB SOFT RST register masks*/
#define VUSB_SOFT_RST_EN			(0x01)

/* VUSB BDT masks */
#define VUSB_BDT_OWNS_BIT			(1 << 7)
#define VUSB_BDT_DATA01_BIT			(1 << 6)
#define VUSB_BDT_KEEP_BIT			(1 << 5)
#define VUSB_BDT_NINC_BIT			(1 << 4)
#define VUSB_BDT_DTS_BIT			(1 << 3)
#define VUSB_BDT_STALL_BIT			(1 << 2)
#define VUSB_BDT_BC_SHIFT			16
#define VUSB_BDT_DATA01_SHIFT		6
#define VUSB_BDT_BC_MASK			0x03ff0000
             
#define VUSB_BDT_PID_MASKS			(0x3C)
#define VUSB_BDT_NAK_PID			(0x28)
#define VUSB_BDT_ERROR_PID			(0x3c)
#define VUSB_BDT_STALL_PID			(0x38)
#define VUSB_BDT_BUS_TIMEOUT_PID	(0x00)


/* OTG Interrupt Status Register Bit Masks */
#define  OTG_INT_STATUS_A_VBUS				(0x01)
#define  OTG_INT_STATUS_B_SESS_END			(0x04)
#define  OTG_INT_STATUS_SESS_VLD			(0x08)
#define  OTG_INT_STATUS_LINE_STATE_CHANGE	(0x20)
#define  OTG_INT_STATUS_1_MSEC				(0x40)
#define  OTG_INT_STATUS_ID					(0x80)

/* OTG Interrupt Enable Register Bit Masks */
#define  OTG_INT_ENABLE_A_VBUS				(0x01)
#define  OTG_INT_ENABLE_B_SESS_END			(0x04)
#define  OTG_INT_ENABLE_SESS_VLD			(0x08)
#define  OTG_INT_ENABLE_1_MSEC				(0x40)
#define  OTG_INT_ENABLE_ID					(0x80)

/*OTG Status register masks*/
#define  OTG_STATUS_A_VBUS					(0x01)
#define  OTG_STATUS_B_SESS_END				(0x04)
#define  OTG_STATUS_SESS_VLD				(0x08)
#define  OTG_STATUS_LINE_STATE_CHANGE		(0x20)
#define  OTG_STATUS_1_MSEC					(0x40)
#define  OTG_STATUS_ID						(0x80)

/*OTG Control register masks*/
#define  OTG_CTL_VBUS_DSCHG					(0x01)
#define  OTG_CTL_VBUS_CHG					(0x02)
#define  OTG_CTL_OTG_ENABLE					(0x04)
#define  OTG_CTL_VBUS_ON					(0x08)
#define  OTG_CTL_DM_LOW						(0x10)
#define  OTG_CTL_DP_LOW						(0x20)
#define  OTG_CTL_DM_HIGH					(0x40)
#define  OTG_CTL_DP_HIGH					(0x80)


/* Token register masks */
#define  VUSB_TOKEN_ENDPT					(0x0f)
#define  VUSB_TOKEN_PID						(0xf0)
#define  VUSB_TOKEN_OUT						(0x10)
#define  VUSB_TOKEN_IN						(0x90)
#define  VUSB_TOKEN_SETUP					(0xd0)

#elif (defined(DRV_USB_IP_V1))

#define USB_FADDR		(USB_base+0x0)
#define USB_POWER		(USB_base+0x1)
#define USB_INTRIN1		(USB_base+0x2)	/*status, read only*/
#define USB_INTRIN2		(USB_base+0x3) 	/*status, read only*/
#define USB_INTROUT1	(USB_base+0x4) 	/*status, read only*/
#define USB_INTROUT2	(USB_base+0x5) 	/*status, read only*/
#define USB_INTRUSB		(USB_base+0x6) 	/*status, read only*/
#define USB_INTRIN1E	(USB_base+0x7)
#define USB_INTRIN2E	(USB_base+0x8)
#define USB_INTROUT1E	(USB_base+0x9)
#define USB_INTROUT2E	(USB_base+0xa)
#define USB_INTRUSBE	(USB_base+0xb)
#define USB_FRAME1		(USB_base+0xc)	/*read only*/
#define USB_FRAME2		(USB_base+0xd)	/*read only*/ /*Max Frame length = 11 bits*/
#define USB_INDEX		(USB_base+0xe)	/*RW, 4bit available*/
#define USB_RSTCTRL		(USB_base+0xf)

#define USB_INMAXP		(USB_base+0x10)	/*RW*/
#define USB_CSR0		(USB_base+0x11)
#define USB_INCSR1		(USB_base+0x11)
#define USB_INCSR2		(USB_base+0x12)
#define USB_OUTMAXP		(USB_base+0x13)	/*RW*/
#define USB_OUTCSR1		(USB_base+0x14)
#define USB_OUTCSR2		(USB_base+0x15)
#define USB_COUNT0		(USB_base+0x16)	/*RO, EP0 only*/
#define USB_OUTCOUNT1	(USB_base+0x16)   
#define USB_OUTCOUNT2	(USB_base+0x17)	/*RO,11bits*/

#define USB_EP0			(USB_base+0x20)	/*4 byte as 1 queue*/

#define USB_ENABLE		(USB_base+0x230)

/*USB_FADDR*/
#define USB_FADDR_ADDRMASK		(0x7f)   /*RO*/
#define USB_FADDR_UPDATE		(0x80)   /*RW*/

/*USB_POWER*/
#define USB_POWER_SETSUSPEND	(0x01)   /*RW*/
#define USB_POWER_SUSPENDSTAT	(0x02)   /*RO*/ /*Read clear by the intr. register*/
#define USB_POWER_RESUME		(0x04)   /*RW*/
#define USB_POWER_RESET			(0x08)   /*RO*/
#define USB_POWER_SWRSTENAB		(0x10)   /*RW*/
#define USB_POWER_ISOUPDATE		(0x80)   /*RW*/

/*USB_RSTCTRL*/
#define USB_RSTCTRL_SWRST		(0x80)	 /*RW*/ 

/*USB_INTRIN1, USB_INTRIN2 is not needed*/   
#define USB_INTRIN1_EP0			(0x01)   /*RO*/
#define USB_INTRIN1_EP1			(0x02)   /*RO*/
#define USB_INTRIN1_EP2			(0x04)   /*RO*/
#define USB_INTRIN1_EP3			(0x08)   /*RO*/

/*USB_INTROUT1, USB_INTROUT2 is not needed*/
#define USB_INTROUT1_EP1		(0x02)   /*RO*/
#define USB_INTROUT1_EP2		(0x04)   /*RO*/

/*USB_INTRUSB*/
#define USB_INTRUSB_SUSPEND		(0x01)   /*RO*/
#define USB_INTRUSB_RESUME		(0x02)   /*RO*/
#define USB_INTRUSB_RESET		(0x04)   /*RO*/
#define USB_INTRUSB_SOF			(0x08)   /*RO*/

/*USB_INTRIN1E, USB_INTRIN2E is not needed*/
#define USB_INTRIN1E_EPEN		(0x01)   /*RW*/

/*USB_INTROUT1E, USB_INTROUT2E is not needed*/
#define USB_INTROUT1E_EP0		(0x01)   /*RW*/
#define USB_INTROUT1E_EP1		(0x02)   /*RW*/
#define USB_INTROUT1E_EP2		(0x04)   /*RW*/

/*USB_INTRUSBE*/
#define USB_INTRUSBE_SUSPEND	(0x01)   /*RW*/
#define USB_INTRUSBE_RESUME		(0x02)   /*RW*/
#define USB_INTRUSBE_RESET		(0x04)   /*RW*/
#define USB_INTRUSBE_SOF		(0x08)   /*RW*/

/*USB_INMAXP*/
#define USB_INMAXP_MASK			(0xff)   /*RW*/

/*USB_OUTMAXP*/
#define USB_OUTMAXP_MASK		(0xff)   /*RW*/

/*USB_CSR0*/
#define USB_CSR0_OUTPKTRDY				(0x01)   /*RO*/
#define USB_CSR0_INPKTRDY				(0x02)   /*RW,AC*/
#define USB_CSR0_SENTSTALL				(0x04)   /*RC*/
#define USB_CSR0_DATAEND				(0x08)   /*WO,AC*/
#define USB_CSR0_SETUPEND				(0x10)   /*RO*/
#define USB_CSR0_SENDSTALL				(0x20)   /*WO,AC*/
#define USB_CSR0_SERVICEDOUTPKTRDY		(0x40)   /*WO,AC*/
#define USB_CSR0_SERVICESETUPEND		(0x80)   /*WO,AC*/

/*USB_INCSR1*/
#define USB_INCSR1_INPKTRDY				(0x01)   /*RW*/
#define USB_INCSR1_FIFONOTEMPTY			(0x02)   /*RC*/
#define USB_INCSR1_UNDERRUN				(0x04)   /*RC*/
#define USB_INCSR1_FLUSHFIFO			(0x08)   /*WO*/
#define USB_INCSR1_SENDSTALL			(0x10)   /*RW*/
#define USB_INCSR1_SENTSTALL			(0x20)   /*RC*/
#define USB_INCSR1_CLRDATATOG			(0x40)   /*WO*/

/*USB_INCSR2*/
#define USB_INCSR2_FRCDATATOG			(0x08)   /*RW*/
#define USB_INCSR2_DMAENAB				(0x10)   /*RW*/
#define USB_INCSR2_MODE					(0x20)   /*RW*/
#define USB_INCSR2_ISO					(0x40)   /*RW*/
#define USB_INCSR2_AUTOSET				(0x80)   /*RW*/

/*USB_OUTCSR1*/
#define USB_OUTCSR1_OUTPKTRDY			(0x01)   /*RC*/
#define USB_OUTCSR1_FIFOFULL			(0x02)   /*R,AC*/
#define USB_OUTCSR1_OVERRUN				(0x04)   /*RC*/
#define USB_OUTCSR1_DATAERROR			(0x08)   /*RO*/
#define USB_OUTCSR1_FLUSHFIFO			(0x10)   /*WO,AC*/
#define USB_OUTCSR1_SENDSTALL			(0x20)   /*RW*/
#define USB_OUTCSR1_SENTSTALL			(0x40)   /*RC*/
#define USB_OUTCSR1_CLRDATATOG			(0x80)   /*WO*/

/*USB_OUTCSR2*/
#define USB_OUTCSR2_DMAMODE				(0x10)   /*RW*/
#define USB_OUTCSR2_DMAENAB				(0x20)   /*RW*/
#define USB_OUTCSR2_ISO					(0x40)   /*RW*/
#define USB_OUTCSR2_AUTOCLEAR			(0x80)   /*RW*/

/*USB_ENABLE*/
#define USB_ENABLE_EN					(0x1)   /*WO*/
#define USB_ENABLE_DIS					(0x0)   /*WO*/

#endif

#endif  /* USB_HW_H */               

