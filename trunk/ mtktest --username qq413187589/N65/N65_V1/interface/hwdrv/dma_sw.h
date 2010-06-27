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
 *    dma_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for DMA driver.
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
#ifndef _DMA_SW_H
#define _DMA_SW_H

#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6208)) || (defined(FPGA)) )
   typedef enum 
   {
   	cbyte,
   	chword,
   	cword
   }DMAsize;
   
   typedef enum 
   {
   	sw_hsk,
   	hw_hsk
   }DMAhsk;
   
   typedef enum 
   {
   	mode1,
   	mode7
   }DMAtmode;
   
   typedef enum 
   {
   	USBmas,
   	UARTmas
   }DMAmas;
   
   typedef struct 
   {
   	void (*dma1_func)(void);
   	void (*dma2_func)(void); 
   }dma_func;
   
   
#define DMA1_Start() *(volatile kal_uint16 *)DMA1_START = DMA_START_BIT
#define DMA2_Start() *(volatile kal_uint16 *)DMA2_START = DMA_START_BIT
#define DMA1_Stop()  *(volatile kal_uint16 *)DMA1_START = DMA_STOP_BIT
#define DMA2_Stop()  *(volatile kal_uint16 *)DMA2_START = DMA_STOP_BIT
#define DMA1_GetCount() *(volatile kal_uint16 *)DMA1_COUNT
#define DMA2_GetCount() *(volatile kal_uint16 *)DMA2_COUNT
#define DMA1_ACKI()  *(volatile kal_uint16 *)DMA1_ACKINT = DMA_ACKINT_BIT
#define DMA2_ACKI()  *(volatile kal_uint16 *)DMA2_ACKINT = DMA_ACKINT_BIT
   
extern kal_bool DMA1_CheckRunStat(void);
extern kal_bool DMA1_CheckITStat(void);
extern void DMA1_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void));
extern kal_bool DMA2_CheckRunStat(void);
extern kal_bool DMA2_CheckITStat(void);
extern void DMA2_Init(kal_uint32 src, kal_uint32 dst, kal_uint16 count,void func(void));
extern void UART_DMA_ENABLE(void);
extern kal_bool USBDMA_Ini(kal_bool Tx);
extern kal_bool UART1DMA_Ini(kal_bool Tx);
extern kal_bool UART2DMA_Ini(kal_bool Tx);
extern void DMA_LISR(void);
   
#else /*MT6205,MT6208,MT6205B,FPGA*/

#ifdef MT6218
#define DMA_MAX_CHANNEL          11
#elif defined(MT6218B) || defined(MT6217)
#define DMA_MAX_CHANNEL          9
#elif defined(MT6223) || defined(MT6223P)
#define DMA_MAX_CHANNEL          6
#else
#define DMA_MAX_CHANNEL          10
#endif

#if defined(MT6223) || defined(MT6223P)
#define DMA_MAX_FULL_CHANNEL     1
#else
#define DMA_MAX_FULL_CHANNEL     3
#endif

typedef enum {
    DMA_SIM=0,
	DMA_MSDC,
	DMA_IRDATX,
	DMA_IRDARX,
#if defined(MT6238)	

	DMA_RESERVED_1,
	DMA_RESERVED_2,
	DMA_RESERVED_3,
	DMA_RESERVED_4,
	
#else

	DMA_USB1TX, 
	DMA_USB1RX,
	DMA_USB2TX,
	DMA_USB2RX,
#endif	// #if defined(MT6238)	
	DMA_UART1TX,
	DMA_UART1RX,
	DMA_UART2TX,
	DMA_UART2RX,
	DMA_UART3TX,
	DMA_UART3RX,
	DMA_IDMA,
#if ( !defined(MT6218B) && !defined(MT6217) )
	DMA_NFITX,
	DMA_NFIRX,
#endif


#if defined(MT6238)
	DMA_DSPDMA2,
	DMA_I2CTX,
	DMA_I2CRX,
	DMA_MSDC2,	
	DMA_SIM2,
#endif
	DMA_SW,
	DMA_IDLE
} DMA_Master;

typedef enum {
    DMA_BYTE=0,
    DMA_SHORT,
    DMA_LONG
} DMA_TranSize;

typedef enum {
    DMA_HWTX,          /*use DMA_HWMENU*/  /*from RAM to register, 4~11*/
    DMA_HWRX,          /*use DMA_HWMENU*/ /*from register to RAM, 4~11*/
    DMA_SWCOPY,        /*use DMA_SWCOPYMENU*/  /*from RAM to RAM, 1~3*/
    DMA_HWTX_RINGBUFF, /*use DMA_HWRINGBUFF_MENU*/   /*from RAM to register, 4~11*/
    DMA_HWRX_RINGBUFF  /*use DMA_HWRINGBUFF_MENU*/  /*from register to RAM, 4~11*/
} DMA_Type;

typedef struct
{
    kal_bool  burst_mode; /*burst mode = 0 ==> single mode*/
    kal_uint8 cycle;      /*active only when (burst_mode == TRUE)*/
}DMA_TMODE;              /*only active when hw management*/

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     addr;
    void           *WPPT; /*if ring buffer support, ==NULL==> not supprot*/
    void           *WPTO; /*if ring buffer support, ==NULL==> not supprot*/
}DMA_HWRINGBUFF_MENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     addr;
}DMA_HWMENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     source;
    kal_uint32     destination;
    void           *WPPT; /*if ring buffer support, ==NULL==> not supprot*/
    void           *WPTO; /*if ring buffer support, ==NULL==> not supprot*/
}DMA_FULLSIZE_HWRINGBUFF_MENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     source;
    kal_uint32     destination;
}DMA_FULLSIZE_HWMENU;

typedef struct
{
    kal_uint32     srcaddr;
    kal_uint32     dstaddr;
}DMA_SWCOPYMENU;

typedef union
{
    DMA_HWMENU                    menu_hw;
    DMA_HWRINGBUFF_MENU           menu_hw_ringbuff;
    DMA_SWCOPYMENU                menu_swcopy;
    DMA_FULLSIZE_HWMENU           menu_fullsize_hw;
    DMA_FULLSIZE_HWRINGBUFF_MENU  menu_fullsize_hw_ringbuff;
} DMA_MENU;

typedef struct
{
    DMA_Type       type;
    DMA_TranSize   size;
    kal_uint32     count;
    void           *menu;      /*DMA_HWMENU,DMA_HWRINGBUFF_MENU,DMA_SWCOPYMENU,or DMA_SWCOPY_RINGBUFF_MENU*/
    void           (*callback)(void);      /*if callback == NULL, interrupt disable*/
}DMA_INPUT;

typedef struct
{
    kal_uint32   sleepDisable;      
    //kal_uint8    DMA_ChanCount;
} DMA_PWRCTRL;

typedef kal_uint8 DMA_GBL_CLASS;
typedef kal_int8 DMA_GBL_HANDLE;

typedef struct
{
    kal_uint8 lower;
    kal_uint8 upper;
    kal_uint8 bank; 
} DMA_GBL_PRIORITY_BANK;

#define DMA_MAX_GBL_CLASS 4
#define DMA_GBL_CLASS0 0
#define DMA_GBL_CLASS1 1
#define DMA_GBL_CLASS2 2
#define DMA_GBL_CLASS3 3
#define DMA_GBL_CLASS4 4
#define DMA_INVALID_GBL_HANDLE -1
#define DMA_GBL_TOTAL_PRIORITY_BANK 8
                                                                                              
#define DMA_GBL_PRIORITY_2_BL(priority_bank, dma_gbl) (((priority_bank) * (dma_gbl)) >> 3)

#define DMA_Start(_n)                  DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#define DMA_Stop_Now(_n)               DRV_WriteReg32(DMA_START(_n),DMA_STOP_BIT)
#define DMA_GetCount(_n)               DRV_Reg32(DMA_COUNT(_n))
#define DMA_ACKI(_n)                   DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
#define DMA_CheckRunStat(_n)           ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_RUN(_n))!=0)
#define DMA_CheckITStat(_n)            ((DRV_Reg32(DMA_GLBSTA) & DMA_GLBSTA_IT(_n))!=0)
#define DMA_WaitUntilRdy(_n)           while(DMA_CheckRunStat(_n))

extern void DMA_Stop(kal_uint8 channel);
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
extern void DMA_FreeChannel(kal_uint8 handle);
extern kal_uint8 DMA_FullSize_GetChannel(DMA_Master DMA_CODE);
extern void DMA_FullSize_FreeChannel(kal_uint8 handle);
extern void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start);
extern DMA_GBL_HANDLE DMA_SetGBL(DMA_GBL_CLASS dma_gbl_class);
extern void DMA_RestoreGBL(DMA_GBL_HANDLE dma_gbl_handle);

#define DMA_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, KAL_FALSE, 0, start)
#define DMA_FullSize_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_TRUE, KAL_FALSE, 0, start)
#define DMA_Config_B2W(dma_no, dma_menu, start, b2w) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, b2w, 0, start)
#endif   /* MT6218, MT6218B, MT6219 */

#if ( !defined(MT6205B) && !defined(MT6208) )
#if defined(MT6218B) || defined(MT6217)
   typedef enum {
      VDMA_UART1RX_CH = 10,
      VDMA_UART1TX_CH = 12,
      VDMA_UART2RX_CH = 11,
      VDMA_UART2TX_CH = 13,
      VDMA_UART3RX_CH = 0,
      VDMA_UART3TX_CH = 0
   } DMA_VFIFO_UART;  
#else
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
  typedef enum {
      VDMA_UART1RX_CH = 11,
      VDMA_UART1TX_CH = 12,
      VDMA_UART2RX_CH = 0,
      VDMA_UART2TX_CH = 0,
      VDMA_UART3RX_CH = 13,
      VDMA_UART3TX_CH = 14
      } DMA_VFIFO_UART;  
#endif  
#endif      
#endif

#ifdef __DMA_UART_VIRTUAL_FIFO__

#if ( !defined(MT6205B) && !defined(MT6208) ) 

extern void DMA_Vfifo_init(void);
extern void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx );
extern void DMA_Vfifo_Flush(DMA_VFIFO_UART ch);
   
#endif
   
#endif   /* __DMA_UART_VIRTUAL_FIFO__ */
  
#endif   /*_DMA_SW_H*/


