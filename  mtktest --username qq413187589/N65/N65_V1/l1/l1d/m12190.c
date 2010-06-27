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
 *
 * Filename:
 * ---------
 *	m12190.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Initialize RF components
 *
 * Author:
 * -------
 * -------
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *******************************************************************************/

#include "l1d_cid.h"
#include "l1d_reg.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"
#include "l1d_data.h"
#include "m12190.h"

/*---------------------------------------------------------------------------*/

sRFSETTING l1d_rf;

/*---------------------------------------------------------------------------*/

/*----------------------------------------*/
/* RFSpecialCoef Calibration data         */
/*----------------------------------------*/
sRFSpecialCoef RFSpecialCoef;

/*---------------------------------------------------------------------------*/

static void L1D_RF_Init_Data( void )
{
   l1d_rf.cwin_idx  = 0;
/* l1d_rf.band      = 0; */
/* l1d_rf.rtxwin_idx = 0; */
   l1d_rf.cur_slot = 0;
   l1d_rf.rx_slots  = 0;
   l1d_rf.tx_slots  = 0;
   l1d_rf.apc_dc_offset = 0;
/* l1d.is_init;        */
/* l1d.bb_tx_autocal;  */
/* l1d.bat_volt;       */
/* l1d.bat_temp;       */
/* l1d_rf.AFC_data  = AFC_Init_Value; */
/* l1d_rf.RFN_data  = 0; */
/* l1d_rf.IFN_data  = 0; */
/* l1d_rf.AGC_data  = 0; */
}
/*-----------------------------------*/

static void L1D_RF_Init_GPIO( void )
{
#ifndef  L1D_SIM
   unsigned short d16,d16and,d16or,i;
   d16    = 0;
   d16and = 0;
   d16or  = 0;
   
   #if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   for(i=0; i<FrequencyBandCount; i++)
   {
      d16|=PDATA_TABLE[i][RF_RX][0];   /* PR1 */
      d16|=PDATA_TABLE[i][RF_RX][1];   /* PR2 */
      d16|=PDATA_TABLE[i][RF_RX][2];   /* PR2B*/
      d16|=PDATA_TABLE[i][RF_RX][3];   /* PR3 */
      d16|=PDATA_TABLE[i][RF_RX][4];   /* PR3A */
      d16|=PDATA_TABLE[i][RF_TX][0];   /* PT1 */
      d16|=PDATA_TABLE[i][RF_TX][1];   /* PT2 */
      d16|=PDATA_TABLE[i][RF_TX][2];   /* PT2B*/
      d16|=PDATA_TABLE[i][RF_TX][3];   /* PT3 */
      d16|=PDATA_TABLE[i][RF_TX][4];   /* PT3A */
      d16|=PDATA_TABLE3[i][RF_RX][0];  /* PR2M1 */
      d16|=PDATA_TABLE3[i][RF_RX][1];  /* PR2M2 */
      d16|=PDATA_TABLE3[i][RF_RX][2];  /* PR2M3 */
      d16|=PDATA_TABLE3[i][RF_TX][0];  /* PT2M1 */
      d16|=PDATA_TABLE3[i][RF_TX][1];  /* PT2M3 */
      d16|=PDATA_TABLE3[i][RF_TX][2];  /* PT2M3 */
      d16|=PDATA_TABLE3[i][RF_TX_8G][0];  /* PT2M1 */
      d16|=PDATA_TABLE3[i][RF_TX_8G][1];  /* PT2M2 */
      d16|=PDATA_TABLE3[i][RF_TX_8G][2];  /* PT2M3 */
      
      d16|=PDATA_GMSK;
      d16|=PDATA_8PSK;
   }
   #else
   for(i=0; i<FrequencyBandCount; i++)
   {
      d16|=PDATA_TABLE[i][RF_RX][0];   /* PR1 */
      d16|=PDATA_TABLE[i][RF_RX][1];   /* PR2 */
      d16|=PDATA_TABLE[i][RF_RX][2];   /* PR3 */
      d16|=PDATA_TABLE[i][RF_TX][0];   /* PT1 */
      d16|=PDATA_TABLE[i][RF_TX][1];   /* PT2 */
      d16|=PDATA_TABLE[i][RF_TX][2];   /* PT3 */
      #if  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ d16|=PDATA_TABLE2[i][RF_RX][0];  /* PR2M1 */
/*MT6218~*/ d16|=PDATA_TABLE2[i][RF_RX][1];  /* PR2M2 */
/*MT6218~*/ d16|=PDATA_TABLE2[i][RF_TX][0];  /* PT2B  */
      #endif
   }
   #endif

   #if  IS_CHIP_MT6208
   /*MT6208*/ #ifndef __CUST_NEW__
   /*MT6208*/ /* All GPIO config is set by L1D in MT6208 */
   /*MT6208*/ /* config GPIO_MODE2[3:2]=1 to set GPIO9=BSI_CS1 */
   /*MT6208*/ HW_WRITE( GPIO_MODE1, 0x00AA );
   /*MT6208*/ HW_WRITE( GPIO_MODE2, 0x0004 );
   /*MT6208*/ HW_WRITE( GPIO_MODE3, 0x4001 );
   /*MT6208*/
   /*MT6208*/ d16 = HW_READ( GPIO_DIR );
   /*MT6208*/ d16 &= ~0x020F;
   /*MT6208*/ d16 |=  0xFFF9;
   /*MT6208*/ HW_WRITE( GPIO_DIR, d16 );
   /*MT6208*/ #endif /* __CUST_NEW__*/
   /*MT6208*/
   /*MT6208*/ d16 = HW_READ( PDN_CON1 );
   /*MT6208*/ d16 &= ~0x0004;
   /*MT6208*/ HW_WRITE( PDN_CON1, d16 );
   /*MT6208*/
   /*MT6208*/ /*--------------------------------*/
   /*MT6208*/ /* Turn on RF Main Power -- PSAVE */
   /*MT6208*/ /*--------------------------------*/
   /*MT6208*/ {void GPO_WriteIO(char ,char );
   /*MT6208*/ #ifdef __CUST_NEW__
   /*MT6208*/ extern const char gpio_rf_control2_pin;
   /*MT6208*/ GPO_WriteIO( 1, gpio_rf_control2_pin); /* ( val, bit ) */
   /*MT6208*/ #else
   /*MT6208*/ GPO_WriteIO( 1, 1 ); /* ( val, bit ) */
   /*MT6208*/ #endif
   /*MT6208*/ }
   #endif

   #if  IS_CHIP_MT6205
   /*MT6205*/ /* if needed to config GPIO_MODE1[9:8]=1 to set GPIO4=BPI_BUS4 */
   /*MT6205*/ /* if needed to config GPIO_MODE1[B:A]=1 to set GPIO5=BPI_BUS5 */
   /*MT6205*/ /* if needed to config GPIO_MODE1[D:C]=1 to set GPIO6=BPI_BUS6 */
   /*MT6205*/ /* if needed to config GPIO_MODE1[F:E]=1 to set GPIO7=BPI_BUS7 */
   /*MT6205*/
   /*MT6205*/ #ifndef __CUST_NEW__
   /*MT6205*/ for(i=4; i<8; i++)             /* only check BPI4~7 */
   /*MT6205*/ {
   /*MT6205*/    if(d16>>i & 0x0001)         /* if this BPI needed */
   /*MT6205*/    {
   /*MT6205*/      d16and |= 0x0003<<(i*2);  /* only set this needed pin as BPI */
   /*MT6205*/      d16or  |= 0x0001<<(i*2);
   /*MT6205*/    }
   /*MT6205*/ }
   /*MT6205*/
   /*MT6205*/ d16 = HW_READ( GPIO_MODE1 );
   /*MT6205*/ d16 &= ~d16and;
   /*MT6205*/ d16 |=  d16or;
   /*MT6205*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6205*/
   /*MT6205*/ #if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6205*/ #endif
   /*MT6205*/
   /*MT6205*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)||(IS_RF_MT6139E)||(IS_RF_MT6140D)
   /*MT6205*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6205*//*MT6119C*/ /* config GPIO_MODE1[F:E]=0 to set GPIO7=GPO7 */
   /*MT6205*//*MT6119C*/ d16 = HW_READ( GPIO_MODE1 );
   /*MT6205*//*MT6119C*/ d16 &= ~0xC000;
   /*MT6205*//*MT6119C*/ HW_WRITE( GPIO_MODE1, d16 );
   /*MT6205*//*MT6119C*/ d16 = HW_READ( GPIO_DIR1 );
   /*MT6205*//*MT6119C*/ d16 |=  0x0080;
   /*MT6205*//*MT6119C*/ HW_WRITE( GPIO_DIR1, d16 );
   /*MT6205*/     #endif
   /*MT6205*/ #endif
   /*MT6205*/ #endif /* __CUST_NEW__ */
   #endif

   #if  IS_CHIP_MT6218A
   /*MT6218A*/ /* if needed to config GPIO_MODE2[1:0]=1 to set GPIO8=BPI_BUS7 */
   /*MT6218A*/ /* if needed to config GPIO_MODE2[3:2]=1 to set GPIO9=BPI_BUS8 */
   /*MT6218A*/ /* if needed to config GPIO_MODE2[5:4]=1 to set GPIOA=BPI_BUS9 */
   /*MT6218A*/
   /*MT6218A*/ #ifndef __CUST_NEW__
   /*MT6218A*/ for(i=7; i<10; i++)                /* only check BPI7~9 */
   /*MT6218A*/ {
   /*MT6218A*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6218A*/    {
   /*MT6218A*/      d16and |= 0x0003<<((i-7)*2);  /* only set this needed pin as BPI */
   /*MT6218A*/      d16or  |= 0x0001<<((i-7)*2);
   /*MT6218A*/    }
   /*MT6218A*/ }
   /*MT6218A*/
   /*MT6218A*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218A*/ d16 &= ~d16and;
   /*MT6218A*/ d16 |=  d16or;
   /*MT6218A*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218A*/
   /*MT6218A*/ #if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6218A*/ #endif
   /*MT6218A*/
   /*MT6218A*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6218A*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6218A*//*MT6119C*/ /* config GPIO_MODE2[5:4]=0 to set GPIOA=GPOA */
   /*MT6218A*//*MT6119C*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218A*//*MT6119C*/ d16 &= ~0x0030;
   /*MT6218A*//*MT6119C*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218A*//*MT6119C*/ d16 = HW_READ( GPIO_DIR1 );
   /*MT6218A*//*MT6119C*/ d16 |=  0x0400;
   /*MT6218A*//*MT6119C*/ HW_WRITE( GPIO_DIR1, d16 );
   /*MT6218A*/     #endif
   /*MT6218A*/ #endif
   /*MT6218A*/ #endif /* __CUST_NEW__ */
   #endif

   #if  IS_CHIP_MT6218B || IS_CHIP_MT6219 || IS_CHIP_MT6227
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[5:4]=1 to set GPIOA=BPI_BUS6 */
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[7:6]=1 to set GPIOB=BPI_BUS7 */
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[9:8]=1 to set GPIOC=BPI_BUS8 */
   /*MT6218B~*/ /* if needed to config GPIO_MODE2[11:10]=1 to set GPIOD=BPI_BUS9 */
   /*MT6218B~*/
   /*MT6218B~*/ #ifndef __CUST_NEW__
   /*MT6218B~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6218B~*/ {
   /*MT6218B~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6218B~*/    {
   /*MT6218B~*/      d16and |= 0x0003<<((i-4)*2);  /* only set this needed pin as BPI */
   /*MT6218B~*/      d16or  |= 0x0001<<((i-4)*2);
   /*MT6218B~*/    }
   /*MT6218B~*/ }
   /*MT6218B~*/
   /*MT6218B~*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218B~*/ d16 &= ~d16and;
   /*MT6218B~*/ d16 |=  d16or;
   /*MT6218B~*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218B~*/
   /*MT6218B~*/ #if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6218B~*/ #endif
   /*MT6218B~*/
   /*MT6218B~*/ #if  IS_RF_SKY74117
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6218B~*/ #endif
   /*MT6218B~*/
   /*MT6218B~*/  #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6218B~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6218B~*//*MT6119C*/ /* config GPIO_MODE2[11:10]=0 to set GPIOD=GPOD */
   /*MT6218B~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6218B~*//*MT6119C*/ d16 &= ~0x0C00;
   /*MT6218B~*//*MT6119C*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6218B~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR1 );
   /*MT6218B~*//*MT6119C*/ d16 |=  0x2000;
   /*MT6218B~*//*MT6119C*/ HW_WRITE( GPIO_DIR1, d16 );
   /*MT6218B~*/     #endif
   /*MT6218B~*/ #endif
   /*MT6218B~*/ #endif /* __CUST_NEW__ */
   #endif

   #if  IS_CHIP_MT6228
   /*MT6228~*/ /* if needed to config GPIO_MODE3[1:0]=1 to set GPIOA=BPI_BUS6 */
   /*MT6228~*/ /* if needed to config GPIO_MODE3[3:2]=1 to set GPIOB=BPI_BUS7 */
   /*MT6228~*/ /* if needed to config GPIO_MODE3[5:4]=1 to set GPIOC=BPI_BUS8 */
   /*MT6228~*/ /* if needed to config GPIO_MODE3[7:6]=1 to set GPIOD=BPI_BUS9 */
   /*MT6228~*/
   /*MT6228~*/ #ifndef __CUST_NEW__
   /*MT6228~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6228~*/ {
   /*MT6228~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6228~*/    {
   /*MT6228~*/      d16and |= 0x0003<<((i-6)*2);  /* only set this needed pin as BPI */
   /*MT6228~*/      d16or  |= 0x0001<<((i-6)*2);
   /*MT6228~*/    }
   /*MT6228~*/ }
   /*MT6228~*/
   /*MT6228~*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6228~*/ d16 &= ~d16and;
   /*MT6228~*/ d16 |=  d16or;
   /*MT6228~*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6228~*/
   /*MT6228~*/ #if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6228~*/ #endif
   /*MT6228~*/
   /*MT6228~*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6228~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6228~*//*MT6119C*/ /* config GPIO_MODE2[11:10]=0 to set GPIOD=GPOD */
   /*MT6228~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6228~*//*MT6119C*/ d16 &= ~0x00C0;
   /*MT6228~*//*MT6119C*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6228~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR2 );
   /*MT6228~*//*MT6119C*/ d16 |=  0x0008;
   /*MT6228~*//*MT6119C*/ HW_WRITE( GPIO_DIR2, d16 );
   /*MT6228~*/     #endif
   /*MT6228~*/ #endif
   /*MT6228~*/ #endif /* __CUST_NEW__ */
   #endif
   
   #if  IS_CHIP_MT6225_AND_LATTER_VERSION
   /*MT6225~*/ /* if needed to config GPIO_MODE4[3:2]=1 to set GPIO25=BPI_BUS6 */
   /*MT6225~*/ /* if needed to config GPIO_MODE4[5:4]=1 to set GPIO26=BPI_BUS7 */
   /*MT6225~*/ /* if needed to config GPIO_MODE4[7:6]=1 to set GPIO27=BPI_BUS8 */
   /*MT6225~*/ /* if needed to config GPIO_MODE4[9:8]=1 to set GPIO28=BPI_BUS9 */
   /*MT6225~*/
   /*MT6225~*/ #ifndef __CUST_NEW__
   /*MT6225~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6225~*/ {
   /*MT6225~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6225~*/    {
   /*MT6225~*/      d16and |= 0x0003<<((i-5)*2);  /* only set this needed pin as BPI */
   /*MT6225~*/      d16or  |= 0x0001<<((i-5)*2);
   /*MT6225~*/    }
   /*MT6225~*/ }
   /*MT6225~*/
   /*MT6225~*/ d16 = HW_READ( GPIO_MODE4 );
   /*MT6225~*/ d16 &= ~d16and;
   /*MT6225~*/ d16 |=  d16or;
   /*MT6225~*/ HW_WRITE( GPIO_MODE4, d16 );
   /*MT6225~*/
   /*MT6225~*/ #if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6225~*/ #endif
   /*MT6225~*/
   /*MT6225~*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6225~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6225~*//*MT6119C*/ /* config GPIO_MODE4[9:8]=0 to set GPIO28=GPO28 */
   /*MT6225~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE4 );
   /*MT6225~*//*MT6119C*/ d16 &= ~0x0300;
   /*MT6225~*//*MT6119C*/ HW_WRITE( GPIO_MODE4, d16 );
   /*MT6225~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR2 );
   /*MT6225~*//*MT6119C*/ d16 |=  0x1000;
   /*MT6225~*//*MT6119C*/ HW_WRITE( GPIO_DIR2, d16 );
   /*MT6225~*/    #endif
   /*MT6225~*/ #endif
   /*MT6225~*/ #endif /* __CUST_NEW__ */
   #endif

   #if IS_CHIP_MT6229||IS_CHIP_MT6268T
   /*MT6229~*/ /* if needed to config GPIO_MODE2[5:4]=1 to set GPIOA=BPI_BUS6 */
   /*MT6229~*/ /* if needed to config GPIO_MODE2[7:6]=1 to set GPIOB=BPI_BUS7 */
   /*MT6229~*/ /* if needed to config GPIO_MODE2[9:8]=1 to set GPIOC=BPI_BUS8 */
   /*MT6229~*/ /* if needed to config GPIO_MODE2[11:10]=1 to set GPIOD=BPI_BUS9 */
   /*MT6229~*/
   /*MT6229~*/ #ifndef __CUST_NEW__
   /*MT6229~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6229~*/ {
   /*MT6229~*/    if(d16>>i & 0x0001)             /* if this BPI needed */
   /*MT6229~*/    {
   /*MT6229~*/      d16and |= 0x0003<<((i-6)*2);  /* only set this needed pin as BPI */
   /*MT6229~*/      d16or  |= 0x0001<<((i-6)*2);
   /*MT6229~*/    }
   /*MT6229~*/ }
   /*MT6229~*/
   /*MT6229~*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6229~*/ d16 &= ~d16and;
   /*MT6229~*/ d16 |=  d16or;
   /*MT6229~*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6229~*/
   /*MT6229~*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6229~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6229~*//*MT6119C*/ /* config GPIO_MODE2[11:10]=0 to set GPIOD=GPOD */
   /*MT6229~*//*MT6119C*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6229~*//*MT6119C*/ d16 &= ~0x00C0;
   /*MT6229~*//*MT6119C*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6229~*//*MT6119C*/ d16 = HW_READ( GPIO_DIR2 );
   /*MT6229~*//*MT6119C*/ d16 |=  0x0008;
   /*MT6229~*//*MT6119C*/ HW_WRITE( GPIO_DIR2, d16 );
   /*MT6229~*/     #endif
   /*MT6229~*/ #endif
   /*MT6229~*/ #endif /* __CUST_NEW__ */  
   /*MT6229~*/   
   #endif

   #if IS_CHIP_MT6223
   /*MT6223~*/ /* if needed to config GPIO_MODE3[ 9: 8]=1 to set GPIO20=BPI_BUS6 */
   /*MT6223~*/ /* if needed to config GPIO_MODE3[11:10]=1 to set GPIO21=BPI_BUS7 */
   /*MT6223~*/ /* if needed to config GPIO_MODE3[13:12]=1 to set GPIO22=BPI_BUS8 */
   /*MT6223~*/ /* if needed to config GPIO_MODE3[15:14]=1 to set GPIO23=BPI_BUS9 */
   /*MT6223~*/
   /*MT6223~*/ #ifndef __CUST_NEW__
   /*MT6223~*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6223~*/ {
   /*MT6223~*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6223~*/    {
   /*MT6223~*/      d16and |= 0x0003<<((i-2)*2);  /* only set this needed pin as BPI */
   /*MT6223~*/      d16or  |= 0x0001<<((i-2)*2);
   /*MT6223~*/    }
   /*MT6223~*/ }
   /*MT6223~*/
   /*MT6223~*/ d16 = HW_READ( GPIO_MODE3 );
   /*MT6223~*/ d16 &= ~d16and;
   /*MT6223~*/ d16 |=  d16or;
   /*MT6223~*/ HW_WRITE( GPIO_MODE3, d16 );
   /*MT6223~*/
   /*MT6223~*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6223~*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6223~*/       /* config GPIO_MODE3[15:14]=0 to set GPIO23(BPI9) as GPIO function */
   /*MT6223~*/       d16 = HW_READ( GPIO_MODE3 );
   /*MT6223~*/       d16 &= ~0xC000;
   /*MT6223~*/       HW_WRITE( GPIO_MODE3, d16 );
   /*MT6223~*/       /* config GPIO_DIR2[7]=1 to set GPIO23 as output */
   /*MT6223~*/       d16 = HW_READ( GPIO_DIR2 );
   /*MT6223~*/       d16 |=  0x0080;
   /*MT6223~*/       HW_WRITE( GPIO_DIR2, d16 );
   /*MT6223~*/    #endif /* End of "RFVCO_SW_CONTROL" */
   /*MT6223~*/ #endif
   /*MT6223~*/ #endif /* __CUST_NEW__ */  
   /*MT6223~*/   
   #endif
   
   #if IS_CHIP_MT6238
   /*MT6238*/ /* if needed to config GPIO_MODE2[ 5: 4]=1 to set GPIO10=BPI_BUS6 */
   /*MT6238*/ /* if needed to config GPIO_MODE2[ 7: 6]=1 to set GPIO11=BPI_BUS7 */
   /*MT6238*/ /* if needed to config GPIO_MODE2[ 9: 8]=1 to set GPIO12=BPI_BUS8 */
   /*MT6238*/ /* if needed to config GPIO_MODE2[11:10]=1 to set GPIO13=BPI_BUS9 */
   /*MT6238*/
   /*MT6238*/ #ifndef __CUST_NEW__
   /*MT6238*/ for(i=6; i<10; i++)                /* only check BPI6~9 */
   /*MT6238*/ {
   /*MT6238*/    if( (d16>>i) & 0x0001)          /* if this BPI needed */
   /*MT6238*/    {
   /*MT6238*/      d16and |= 0x0003<<((i-4)*2);  /* only set this needed pin as BPI */
   /*MT6238*/      d16or  |= 0x0001<<((i-4)*2);
   /*MT6238*/    }
   /*MT6238*/ }
   /*MT6238*/
   /*MT6238*/ d16 = HW_READ( GPIO_MODE2 );
   /*MT6238*/ d16 &= ~d16and;
   /*MT6238*/ d16 |=  d16or;
   /*MT6238*/ HW_WRITE( GPIO_MODE2, d16 );
   /*MT6238*/
   /*MT6238*/ #if  (IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)||(IS_RF_MT6139B)||(IS_RF_MT6139C)||(IS_RF_MT6140A)||(IS_RF_MT6140B)
   /*MT6238*/    #ifndef RFVCO_SW_CONTROL /* HW control */
   /*MT6238*/       /* config GPIO_MODE2[11:10]=0 to set GPIO13(BPI9) as GPIO function */
   /*MT6238*/       d16 = HW_READ( GPIO_MODE2 );
   /*MT6238*/       d16 &= ~0x0C00;
   /*MT6238*/       HW_WRITE( GPIO_MODE3, d16 );
   /*MT6238*/       /* config GPIO_DIR1[13]=1 to set GPIO13 as output */
   /*MT6238*/       d16  = HW_READ( GPIO_DIR1 );
   /*MT6238*/       d16 |=  0x2000;
   /*MT6238*/       HW_WRITE( GPIO_DIR1, d16 );
   /*MT6238*/    #endif /* End of "RFVCO_SW_CONTROL" */
   /*MT6238*/ #endif
   /*MT6238*/ #endif /* __CUST_NEW__ */  
   /*MT6238*/   
   #endif   


#endif
}
/*-----------------------------------*/

static void L1D_RF_Init_BSI( void )
{  int   i;
   unsigned short d16;

   d16 = HW_READ( BSI_CON );
   d16 &= (unsigned short)(~0x0100);                 /* clear BSI write buffer */
   HW_WRITE( BSI_CON , d16 );

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   for(i=0; i<40; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   for(i=0; i<BSI_DATA_COUNT-40; i++)
   {  HW_WRITE( BSI_Dn_CON_2(i), SCTRL_RESERVED );   /* set BSI ID = reserved */
   }
#else
   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
#endif   

   d16 |= (unsigned short)(0x0100);                  /* clear BSI active buffer */
   HW_WRITE( BSI_CON , d16 );

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   for(i=0; i<40; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
   for(i=0; i<BSI_DATA_COUNT-40; i++)
   {  HW_WRITE( BSI_Dn_CON_2(i), SCTRL_RESERVED );   /* set BSI ID = reserved */
   }
#else
   for(i=0; i<BSI_DATA_COUNT; i++)
   {  HW_WRITE( BSI_Dn_CON(i), SCTRL_RESERVED );     /* set BSI ID = reserved */
   }
#endif


  
   HW_WRITE( BSI_CON, SCTRL_MAIN );                  /* Initialize BSI_CON */
   
#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( BSI_PAIR_NUM, 0x002c );                 /* set BSI pair number */
#endif
}
/*-----------------------------------*/

static void L1D_RF_Init_BPI( void )
{
}
/*-----------------------------------*/

static void L1D_RF_Init_APC( void )
{  int  i;
   HW_WRITE(APC_CON, 0x0000);
   for(i=0; i<FrequencyBandCount; i++)
   {  L1D_RF_InitRampTable( i );
   }
}
/*-----------------------------------*/

static void L1D_RF_Init_AFC( void )
{
#if  IS_CHIP_MT6208
/*MT6208*/ HW_WRITE( IDN_SEL, 0x0003 );     /* to slove the AFC bug of H/W, don't let this register is zero */
#endif

   HW_WRITE( AFC_CON, AFC_EVENT_TRIGGER);
#if  IS_CHIP_MT6205_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6205~*/   HW_WRITE( AFC_PUPER, TQ_AFC_CHARGE_IN_IDLE );
#endif
}
/*-----------------------------------*/

static void L1D_RF_Init_DLUL( void )
{
   HW_WRITE( TDMA_BDLCON , bdlcon_data  );
   HW_WRITE( TDMA_BULCON1, bulcon1_data );
   HW_WRITE( TDMA_BULCON2, bulcon2_data );
   HW_WRITE( TDMA_DTXCON , 0x0000       );
}
/*-----------------------------------*/

static void L1D_RF_Init_BFE( void )
{  BFERXSET  bferxset;
   BFETXSET  bfetxset;

   HW_READ_BFERXSET( bferxset );
   bferxset.field.swap          = bbrx_iq_swap;
   bferxset.field.gain          = bbrx_gain_double;
   bferxset.field.isel          = 0;
   bferxset.field.qsel          = 0;
   bferxset.field.calbias       = 0;
   bferxset.field.blpen         = 0;   
#if (IS_CHIP_MT6225_AND_LATTER_VERSION) || (IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION)
   bferxset.field.ph_roen_w     = 0;
   bferxset.field.ph_roen_n     = 0;
   bferxset.field.igainsel      = 0;
   bferxset.field.pwrshftno     = 0;
   bferxset.field.firtpno       = 21;
   bferxset.field.dithdis       = 1; /*1: Turn off Dither figure*/
   bferxset.field.RXID_PWR_OFF  = 17;
   bferxset.field.RXID_PWR_PER  = 135;
   bferxset.field.ST_A_NCOF_SEL = 0;
   bferxset.field.ST_B_NCOF_SEL = 2;
   bferxset.field.ST_B_WCOF_SEL = 3;
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   bferxset.field.ph_roen_w     = 0;
   bferxset.field.ph_roen_n     = 0;
   bferxset.field.igainsel      = 0;
   bferxset.field.pwrshftno     = 0;
   bferxset.field.firtpno       = 21;
   bferxset.field.RXID_PWR_OFF  = 17;
   bferxset.field.RXID_PWR_PER  = 135;
   bferxset.field.ST_A_NCOF_SEL = 0;
   bferxset.field.ST_B_NCOF_SEL = 2;
   bferxset.field.ST_B_WCOF_SEL = 3;
#endif

   HW_WRITE_BFERXSET( bferxset );

   HW_READ_BFETXSET( bfetxset );
   bfetxset.field.trimi         = bbtx_trim_i;
   bfetxset.field.trimq         = bbtx_trim_q;
   bfetxset.field.offi          = bbtx_offset_i;
   bfetxset.field.offq          = bbtx_offset_q;
   bfetxset.field.calbias       = bbtx_calbias;
   bfetxset.field.iqswap        = bbtx_iq_swap;
   bfetxset.field.cmv           = bbtx_common_mode_voltage;
   bfetxset.field.gain          = bbtx_gain;
   bfetxset.field.calrcsel      = bbtx_calrcsel;
#if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_CHIP_MT6223
   bfetxset.field.phsel         = bbtx_phsel;
   bfetxset.field.mdbyp         = 0;
   bfetxset.field.sgen          = 0;
   bfetxset.field.dccoarsei     = bbtx_dccoarse_i;
   bfetxset.field.dccoarseq     = bbtx_dccoarse_q;
#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   bfetxset.field.phsel         = bbtx_phsel;
   bfetxset.field.rpsel         = bbtx_rpsel;
   bfetxset.field.inten         = bbtx_inten;
   bfetxset.field.mdbyp         = 0;
   bfetxset.field.sgen          = 0;
   bfetxset.field.sw_qbcnt      = bbtx_sw_qbcnt;
   #if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
   bfetxset.field.dccoarsei     = bbtx_dccoarse_i;
   bfetxset.field.dccoarseq     = bbtx_dccoarse_q;
   #endif
#endif

#if IS_CHIP_MT6227
   bfetxset.field.iqswap_onfly  = bbtx_iqswap_onfly;
#endif   
   HW_WRITE_BFETXSET( bfetxset );

   HW_WRITE( BFE_CON, 0x0000 );  /* disable cipher */


/* setting for different analog chip: C63216 or D63216 */
#if IS_CHIP_MT6228 || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   {  unsigned short d16;
      d16 = HW_READ( ACIF_AC_HW_VER );
      if (d16 == 0x8C01)       //C63216
      {  d16 = HW_READ( AFC_AC_CON );
         d16 &= 0xFFF0;
         HW_WRITE( AFC_AC_CON, d16 );
      }
      else if (d16 == 0x8D00)  //D63216
      {  d16 = HW_READ( AFC_AC_CON );
         d16 &= 0xFFF0;
         HW_WRITE( AFC_AC_CON, d16 );
      }
   }
#endif
}
/*-----------------------------------*/

void L1D_RF_Init_FIR( void )
{  int  i;
   const short *d16p;
   long  addr;

   addr = (long)RX_FIR_COEF(0);
   d16p = FIR_COEF;
   for( i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }

#if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION   
   addr = (long)RX_NBFIR_COEF(0);
   d16p = NB_FIR_COEF;
   for(i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }
#endif
}

/*-----------------------------------*/
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION || IS_CHIP_MT6225_AND_LATTER_VERSION   
void L1D_RF_init_FIR_SwitchNB( int wider )
{  int  i;
   const short *d16p;
   long  addr;

   if(wider == 1)
      d16p = NB_FIR_COEF_WIDER;
   else
      d16p = NB_FIR_COEF;
   
   addr = (long)RX_NBFIR_COEF(0);
   for(i=*d16p++; i!=0; i-- )
   {  HW_WRITE( (APBADDR)addr, *d16p );
      addr += 4;
      d16p++;
   }

}
#endif
/*-----------------------------------*/
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229*/ void L1D_RF_Set_FB_FIR( void )
/*MT6229*/ {  int  i;
/*MT6229*/    const short *d16p;
/*MT6229*/    long  addr;
/*MT6229*/
/*MT6229*/    addr = (long)RX_FIR_COEF(0); //0020h
/*MT6229*/    d16p = WIDE_FB_FIR_COEF;
/*MT6229*/    for( i=*d16p++; i!=0; i-- )
/*MT6229*/    {  HW_WRITE( (APBADDR)addr, *d16p );
/*MT6229*/       addr += 4;
/*MT6229*/       d16p++;
/*MT6229*/    }
/*MT6229*/
/*MT6229*/    addr = (long)RX_NBFIR_COEF(0); //0070h
/*MT6229*/    d16p = NARROW_FB_FIR_COEF;
/*MT6229*/    for(i=*d16p++; i!=0; i-- )
/*MT6229*/    {  HW_WRITE( (APBADDR)addr, *d16p );
/*MT6229*/       addr += 4;
/*MT6229*/       d16p++;
/*MT6229*/    }
/*MT6229*/ }
#endif
/*-----------------------------------*/

static void L1D_RF_Init_ChipOptimizeSetting( void )
{
#ifndef  L1D_SIM
   #if  IS_CHIP_MT6205A
   /*MT6205A*/ {  unsigned short  d16;
   /*MT6205A*/    d16 = HW_READ(RX_CON);
   /*MT6205A*/    d16 &= ~0x001F;
   /*MT6205A*/    d16 |= 0x0008;
   /*MT6205A*/    HW_WRITE( RX_CON, d16 );
   /*MT6205A*/    d16 = HW_READ(AFC_CALIBIAS);
   /*MT6205A*/    d16 &= ~0x001F;
   /*MT6205A*/    d16 |= 0x000F;
   /*MT6205A*/    HW_WRITE( AFC_CALIBIAS, d16 );
   /*MT6205A*/ }
   #endif

   #if  IS_CHIP_MT6205B
   /*MT6205B*/ {  unsigned short  d16;
   /*MT6205B*/    d16 = HW_READ(RX_CON);
   /*MT6205B*/    d16 &= ~0x001F;
   /*MT6205B*/    d16 |= 0x0007;
   /*MT6205B*/    HW_WRITE( RX_CON, d16 );
   /*MT6205B*/    d16 = HW_READ(AFC_CALIBIAS);
   /*MT6205B*/    d16 &= ~0x001F;
   /*MT6205B*/    d16 |= 0x0006;
   /*MT6205B*/    HW_WRITE( AFC_CALIBIAS, d16 );
   /*MT6205B*/    d16 = HW_READ(TX_CFG);  /* appending bits enable, setting this bit to 1 In order to             */
   /*MT6205B*/    d16 |= 0x0080;          /* let GMSK modulation only out DC(not sinewace) after Frame Enable on. */
   /*MT6205B*/    HW_WRITE( TX_CFG, d16 );
   /*MT6205B*/ }
   #endif

   #if  IS_CHIP_MT6218B
      #if  !(IS_CHIP_MT6218B_AN2DN)
         #if  !(IS_CHIP_MT6218B_EN)
         /*MT6218B_FN~*/ {  unsigned short  d16;
         /*MT6218B_FN~*/    d16 = HW_READ(AFC_CALIBIAS);
         /*MT6218B_FN~*/    d16 &= ~0x001F;
         /*MT6218B_FN~*/    d16 |= 0x000F;
         /*MT6218B_FN~*/    HW_WRITE( AFC_CALIBIAS, d16 );
         /*MT6218B_FN~*/ }
         #endif
      #endif
   #endif

   #if  IS_CHIP_MT6219
      #if  !(IS_CHIP_MT6219_AV)
      /*MT6219BV~*/ {  unsigned short  d16;
      /*MT6219BV~*/    d16 = HW_READ(AFC_CALIBIAS);
      /*MT6219BV~*/    d16 &= ~0x001F;
      /*MT6219BV~*/    d16 |= 0x000F;
      /*MT6219BV~*/    HW_WRITE( AFC_CALIBIAS, d16 );
      /*MT6219BV~*/ }
      #endif
   #endif
   
   #if  IS_CHIP_MT6229
         /*MT6229~*/ {  unsigned short  d16;
         /*MT6229~*/    d16 = HW_READ(AFC_CALIBIAS);
         /*MT6229~*/    d16 &= ~0x001F;
         /*MT6229~*/    d16 |= 0x000F;
         /*MT6229~*/    HW_WRITE( AFC_CALIBIAS, d16 );
         /*MT6229~*/ }
   #endif
#endif
}

/*-----------------------------------*/

void  L1D_RF_Init_SpecialCoef( void )
{

#if IS_RF_MT6139B || IS_RF_MT6139C  || IS_RF_MT6140A || IS_RF_MT6140B

   RFSpecialCoef.rx.mt6139ip2.data[0].acode  = 0;
   RFSpecialCoef.rx.mt6139ip2.data[0].amcode = 0;
   RFSpecialCoef.rx.mt6139ip2.data[1].acode   = ACODE850;
   RFSpecialCoef.rx.mt6139ip2.data[1].amcode  = AMCODE850;
   RFSpecialCoef.rx.mt6139ip2.data[2].acode   = ACODE900;
   RFSpecialCoef.rx.mt6139ip2.data[2].amcode  = AMCODE900;
   RFSpecialCoef.rx.mt6139ip2.data[3].acode   = ACODE1800;
   RFSpecialCoef.rx.mt6139ip2.data[3].amcode  = AMCODE1800;
   RFSpecialCoef.rx.mt6139ip2.data[4].acode   = ACODE1900;
   RFSpecialCoef.rx.mt6139ip2.data[4].amcode  = AMCODE1900;
   RFSpecialCoef.rx.mt6139ip2.rxamcalmode = 2; //normal mode
#elif IS_RF_MT6139E 

   extern signed short  dcs_tx_gain_setting;
   extern signed short  pcs_tx_gain_setting;
   extern unsigned long CW11_RF[5];
   
   if     (dcs_tx_gain_setting == 1) 
      CW11_RF[3]=0x0B4D7FB; /* TXDIVGC:00; TXMODGAIN: 010 (0.5dB and 40kHz) */
   else if(dcs_tx_gain_setting == 2) 
   	  CW11_RF[3]=0x0B4E7FB; /* TXDIVGC:00; TXMODGAIN: 100 (1.5dB and 40kHz) */
   else                              
   	  CW11_RF[3]=0x1B4E7FB; /* TXDIVGC:01; TXMODGAIN: 100                   */ 
   
   if     (pcs_tx_gain_setting == 1) 
      CW11_RF[4]=0x0B4D7FB; /* TXDIVGC:00; TXMODGAIN: 010 (0.5dB and 40kHz) */
   else if(pcs_tx_gain_setting == 2) 
   	  CW11_RF[4]=0x0B4E7FB; /* TXDIVGC:00; TXMODGAIN: 100 (1.5dB and 40kHz) */
   else                              
   	  CW11_RF[4]=0x1B4E7FB; /* TXDIVGC:01; TXMODGAIN: 100                   */
   	
#elif IS_RF_MT6140D
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[0].pcl_index=6;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[0].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[1].pcl_index=8;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[1].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[2].pcl_index=10;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[2].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[3].pcl_index=12;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[3].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[4].pcl_index=14;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[4].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[5].pcl_index=16;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[5].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[6].pcl_index=18;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[6].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[7].pcl_index=19;
   RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias[7].pa_vbias=7;
   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[0].pcl_index=6;  
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[0].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[1].pcl_index=8;  
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[1].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[2].pcl_index=10; 
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[2].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[3].pcl_index=12; 
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[3].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[4].pcl_index=14; 
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[4].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[5].pcl_index=16; 
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[5].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[6].pcl_index=18; 
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[6].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[7].pcl_index=19; 
   RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias[7].pa_vbias=7;   

   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[0].pcl_index=2;  
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[0].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[1].pcl_index=4;  
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[1].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[2].pcl_index=6;  
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[2].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[3].pcl_index=8;  
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[3].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[4].pcl_index=10; 
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[4].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[5].pcl_index=12; 
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[5].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[6].pcl_index=14; 
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[6].pa_vbias=7;   
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[7].pcl_index=15; 
   RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias[7].pa_vbias=7;   
   
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[0].pcl_index=2;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[0].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[1].pcl_index=4;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[1].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[2].pcl_index=6;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[2].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[3].pcl_index=8;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[3].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[4].pcl_index=10;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[4].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[5].pcl_index=12;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[5].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[6].pcl_index=14;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[6].pa_vbias=7;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[7].pcl_index=15;
   RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias[7].pa_vbias=7;
      
#elif IS_RF_SKY74117 || IS_RF_SKY74400 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_SKY74045
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif IS_RF_BRIGHT5P
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*-----------------------------------*/

void  L1D_RF_Init( void )
{
   L1D_RF_Init_Data();
   L1D_RF_Init_GPIO();
   L1D_RF_Init_BSI();
   L1D_RF_Init_BPI();
   L1D_RF_Init_APC();
   L1D_RF_Init_AFC();
   L1D_RF_Init_DLUL();
   L1D_RF_Init_BFE();
   L1D_RF_Init_FIR();
   L1D_RF_Init_ChipOptimizeSetting();
   L1D_RF_Init_SpecialCoef();

   l1d_rf.is_init = 1;
   L1D_RF_PowerOn();
   l1d_rf.is_init = 0;
   l1d_rf.bb_tx_autocal = 0;

#if  (IS_CHIP_MT6205B)||(IS_CHIP_MT6218A)
   #if !(IS_RF_AERO)   /* apply bb_tx_autocal for All RF except AERO */
   // #if !(IS_RF_AERO1PLUS)
   l1d_rf.bb_tx_autocal = 1;
   // #endif
   #endif
#endif

#if  IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   l1d_rf.bb_tx_autocal = 1;
#endif
}
/*================================================================================================*/
void  L1D_RF_SetFixGainEnable( unsigned char enable )
{
   /* For 74137 to pass 14.18.5 */
#if IS_RF_SKY74137
/* under construction !*/
#endif
}

/*================================================================================================*/

void  L1D_RF_SetPathLossTable( int rf_band, void* table )
{  unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(AGC_PATHLOSS_TABLE[rf_band]);
   if(dst==0)  return;
   for( n=sizeof(sAGCGAINOFFSET)*PLTABLE_SIZE; n>0; n--)
   {   *dst++ = *src++;
   }
}
/*===============================================================================================*/

void  L1D_RF_SetRampApcLevel( int rf_band, int power_in_dBm, int apc_dac )
{
   sRAMPDATA*  ramp;
   int     idx;

   ramp = RampData[rf_band];
   idx = (power_in_dBm-LOWEST_TX_POWER[rf_band])/2;
   ramp->power[idx] = apc_dac;
}

/*===============================================================================================*/
#if IS_EPSK_TX_SUPPORT
/*EPSK*/void  L1D_RF_SetRampApcLevelEPSK( int rf_band, int power_in_dBm, int apc_dac )
/*EPSK*/{
/*EPSK*/   sRAMPDATA*  ramp;
/*EPSK*/   int     idx;
/*EPSK*/
/*EPSK*/   ramp = RampData_EPSK[rf_band];
/*EPSK*/   idx = (power_in_dBm-LOWEST_TX_POWER[rf_band])/2;
/*EPSK*/   ramp->power[idx] = apc_dac;
/*EPSK*/}
#endif
/*===============================================================================================*/

void  L1D_RF_SetRampTable( int rf_band, void* table )
{  unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(RampData[rf_band]);

   if(dst==0)  return;

   for( n=sizeof(sRAMPDATA); n>0; n--)
   {   *dst++ = *src++;
   }
   L1D_RF_InitRampTable( rf_band );
}

/*===============================================================================================*/
#if IS_EPSK_TX_SUPPORT
/*EPSK*/void  L1D_RF_SetRampTableEPSK( int rf_band, void* table )
/*EPSK*/{  unsigned char *src, *dst;
/*EPSK*/   int  n;
/*EPSK*/
/*EPSK*/   src = (unsigned char*)table;
/*EPSK*/   dst = (unsigned char*)(RampData_EPSK[rf_band]);
/*EPSK*/
/*EPSK*/   if(dst==0)  return;
/*EPSK*/
/*EPSK*/   for( n=sizeof(sRAMPDATA); n>0; n--)
/*EPSK*/   {   *dst++ = *src++;
/*EPSK*/   }
/*EPSK*/   L1D_RF_InitRampTableEPSK( rf_band );
/*EPSK*/}
#endif

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void  L1D_RF_InitRampTable( int rf_band )
{  int  n;
   sARFCN_SECTION *arfcn_weight_ptr;

   if( RampData[rf_band]==0 )  return;

   arfcn_weight_ptr = &(RampData[rf_band]->arfcn_weight[0]);
   for(n=ARFCN_SECTION_NUM-1; n>=0; n--)
   {  if(arfcn_weight_ptr->max_arfcn<0) break;
      arfcn_weight_ptr++;
   }
   for(    ; n>=0; n--)
   {  arfcn_weight_ptr->max_arfcn = 0x7FFF;
      arfcn_weight_ptr++;
   }

   l1d_rf.apc_dc_offset = (RampData[rf_band]->lowest_power>>8)&0x0000FFFF;
   /*  RampData[rf_band]->lowest_power &= 0x000000FF;  */

   /*shine*/
   /* (short)RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level  */
   /* is stored the afc dac offset data for TX              */
   {  extern  short AFC_Dac_TRx_Offset[5];
#if  defined(AFC_VCXO)
/*VCXO*/    AFC_Dac_TRx_Offset[rf_band] = (short)(RampData[rf_band]->arfcn_weight[ARFCN_SECTION_NUM-1].mid_level);
#else
/*VCTCXO*/  AFC_Dac_TRx_Offset[rf_band] = 0;
#endif
   }
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#if IS_EPSK_TX_SUPPORT
/*EPSK*/void  L1D_RF_InitRampTableEPSK( int rf_band )
/*EPSK*/{
/*EPSK*/   int  n;
/*EPSK*/   sARFCN_SECTION *arfcn_weight_ptr;
/*EPSK*/
/*EPSK*/   if( RampData_EPSK[rf_band]==0 )  return;
/*EPSK*/
/*EPSK*/   arfcn_weight_ptr = &(RampData_EPSK[rf_band]->arfcn_weight[0]);
/*EPSK*/      for(n=ARFCN_SECTION_NUM-1; n>=0; n--)
/*EPSK*/      {  if(arfcn_weight_ptr->max_arfcn<0) break;
/*EPSK*/         arfcn_weight_ptr++;
/*EPSK*/      }
/*EPSK*/      for(    ; n>=0; n--)
/*EPSK*/      {  arfcn_weight_ptr->max_arfcn = 0x7FFF;
/*EPSK*/         arfcn_weight_ptr++;
/*EPSK*/      }
/*EPSK*/}
#endif
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void  L1D_RF_SetInterSlotRampTable( int rf_band, void* table )
{
#if  IS_GPRS
/*GPRS*/ unsigned char *src, *dst;
/*GPRS*/ int  n;
/*GPRS*/
/*GPRS*/ src = (unsigned char*)table;
/*GPRS*/ dst = (unsigned char*)(InterRampData[rf_band]);
/*GPRS*/
/*GPRS*/ if(dst==0)  return;
/*GPRS*/
/*GPRS*/ for( n=16; n>0; n--)
/*GPRS*/ {   *dst++ = *src++;
/*GPRS*/ }
#endif
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#if IS_EPSK_TX_SUPPORT
void  L1D_RF_EPSK_SetInterSlotRampTable( int rf_band, int _8G_mode, void* table )
{
   #if  IS_GPRS
/*GPRS*/ unsigned char *src, *dst;
/*GPRS*/ int  n;
/*GPRS*/
/*GPRS*/ src = (unsigned char*)table;
/*GPRS*/ dst = (unsigned char*)(*(EPSK_InterRampData[rf_band])[_8G_mode]);
/*GPRS*/ 
/*GPRS*/ if(dst==0)  return;
/*GPRS*/
/*GPRS*/ for( n=16; n>0; n--)
/*GPRS*/ {   *dst++ = *src++;
/*GPRS*/ }
   #endif
}
#endif
/*===============================================================================================*/
void  L1D_RF_SetBBTXParameters(void* table )
{  unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(&BBTXParameters);

   for( n=sizeof(sBBTXParameters); n>0; n--)
   {  *dst++ = *src++;
   }

   /*************************************************************
    Note That BBTXParameters is same with the settings
    on the BFE register only when the bbtx_isCalibrated == 0xBF.
    Else, the settings on the BFE register is set from the GCM.
    *************************************************************/
   if( BBTXParameters.bbtx_isCalibrated == 0xBF )
   {
      extern void L1D_GCMachine_Stop( void );

      L1D_GCMachine_Stop();
   }
}
/*===============================================================================================*/

void  L1D_RF_SetCrystalCap( int  cap_no )
{
//#ifdef   AFC_SC
#if  1  // because it has no effect when use VCTCXO, so enable this activity
/*SC*/ XO_CapID = cap_no;
/*SC*/ L1D_RF_PowerOn();
#endif
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void  L1D_RF_SetCrystalAFCData( void* table )
{
#ifdef   AFC_SC
/*SC*/ unsigned char *src, *dst;
/*SC*/ int  n;
/*SC*/
/*SC*/ src = (unsigned char*)table;
/*SC*/ dst = (unsigned char*)(XO_SlopeAreaData);
/*SC*/ for( n=sizeof(XO_SLOPE_AREA_DATA)*XO_SlopeArea_Num; n>0; n--)
/*SC*/ {  *dst++ = *src++;
/*SC*/ }
/*SC*/ {  void  XO_Initialize( void );
/*SC*/    XO_Initialize();
/*SC*/ }
#endif
}

/*===============================================================================================*/
void  L1D_RF_SetRFSpecialCoef(void* table )
{
   unsigned char *src, *dst;
   int  n;

   src = (unsigned char*)table;
   dst = (unsigned char*)(&RFSpecialCoef);
   for( n=sizeof(sRFSpecialCoef); n>0; n--)
   {  *dst++ = *src++;
   }
}

unsigned long  L1D_RF_GetID(void)
{
#if IS_RF_BRIGHT2
/* under construction !*/
#endif

#if IS_RF_BRIGHT4
/* under construction !*/
#endif

#if IS_RF_BRIGHT5P
/* under construction !*/
#endif

#if IS_RF_AERO
/* under construction !*/
#endif

#if IS_RF_AERO1PLUS
/* under construction !*/
#endif

#if IS_RF_POLARIS1
/* under construction !*/
#endif

#if IS_RF_POLARIS2
    return RF_ID_POLARIS2;
#endif

#if IS_RF_SKY74045
/* under construction !*/
#endif

#if IS_RF_SKY74117
/* under construction !*/
#endif

#if IS_RF_SKY74400
/* under construction !*/
#endif

#if IS_RF_MT6119C
    return RF_ID_MT6119C;
#endif

#if IS_RF_MT6129D
    return RF_ID_MT6129D;
#endif

#if IS_RF_MT6139B
    return RF_ID_MT6139B;
#endif

#if IS_RF_MT6139C
    return RF_ID_MT6139C;
#endif

#if IS_RF_MT6139E
    return RF_ID_MT6139E;
#endif
#if IS_RF_MT6140A
    return RF_ID_MT6140A;
#endif

#if IS_RF_MT6140B
    return RF_ID_MT6140B;
#endif

#if IS_RF_MT6140C
    return RF_ID_MT6140C;
#endif

#if IS_RF_MT6140D
    return RF_ID_MT6140D;
#endif    

#if IS_RF_AERO2
/* under construction !*/
#endif

#if IS_RF_SKY74137
/* under construction !*/
#endif

#if IS_RF_GRF6201
/* under construction !*/
#endif

#if IS_RF_IRFS3001
/* under construction !*/
#endif
}

void  L1D_RF_SetImmediateBSI(unsigned long bsidata)
{
#if  IS_RF_MT6139B
 /*MT6139B*/    IMM_MODE_BEGIN( IMMMASK_ALL );
 /*MT6139B*/    IMM_SEND_BSI( SCTRL_IMOD(0,25), bsidata);
 /*MT6139B*/    IMM_MODE_END(  );
#endif
#if  IS_RF_MT6139C || IS_RF_MT6139E || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D
 /*MT6139C&MT6140A*/    IMM_MODE_BEGIN( IMMMASK_ALL );
 /*MT6139C&MT6140A*/    IMM_SEND_BSI( SCTRL_IMOD(0,26), bsidata);
 /*MT6139C&MT6140A*/    IMM_MODE_END(  );
#endif
#if  IS_RF_SKY74117
/* under construction !*/
 /*SKY74117*/    #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
 /*SKY74117*/    #else
/* under construction !*/
 /*SKY74117*/    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if  IS_RF_SKY74400
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  

#if  IS_RF_BRIGHT5P
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

void  L1D_RF_GetImmediateBSI( unsigned long bsi_addr, unsigned long *bsi_data  )
{
    #if IS_RF_MT6139B
    IMM_MODE_BEGIN( IMMMASK_ALL );
    IMM_RECEIVE_BSI(SCTRL_IMOD(0,25), bsi_addr ,SCTRL_IMOD(0,21), bsi_data);
    ///IMM_SEND_BSI( SCTRL_IMOD(0,25), SDATA_IDLE ); /* Back to idle after read back*/
    IMM_MODE_END(  );
    #endif

    #if IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6140C 
    IMM_MODE_BEGIN( IMMMASK_ALL );
    IMM_RECEIVE_BSI(SCTRL_IMOD(0,26), bsi_addr ,SCTRL_IMOD(0,22), bsi_data);
    IMM_MODE_END(  );
    #endif
}

/*===============================================================================================*/

void  WAIT_TIME_QB( short time_qb )
{
#ifndef  L1D_SIM
   unsigned short  last_qb, cur_qb;
   short  qb_diff, qb_remain;


   qb_remain = time_qb;
   last_qb = HW_READ( TDMA_TQCNT );
   while( qb_remain>0 )
   {  cur_qb = HW_READ( TDMA_TQCNT );
      qb_diff = cur_qb-last_qb;
      qb_remain -= (qb_diff<0) ? 1 : qb_diff;
      last_qb = cur_qb;
   }
#endif
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

static void IMM_MODE_AFC_BEGIN( void )
{
   HW_WRITE( AFC_DAT(0), l1d_rf.AFC_data );
   HW_WRITE( AFC_CON   , AFC_FORCE_POWER_ON );
}
/*-----------------------------------*/

static void IMM_MODE_AFC_END( void )
{
}
/*-----------------------------------*/

#ifdef __CUST_NEW__
   #ifndef  L1D_SIM
      #if  IS_CHIP_MT6205
   /*MT6205*/ #if  (IS_RF_AERO)||(IS_RF_AERO1PLUS)||(IS_RF_AERO2)
/* under construction !*/
   /*MT6205*/ #endif
      #endif
   #endif
#endif /*__CUST_NEW__*/

static void IMM_MODE_BPI_BEGIN( void )
{
   HW_WRITE( BPI_CON, PCTRL_INITIAL );
#ifndef  L1D_SIM
   #if  IS_CHIP_MT6205
/*MT6205*/ #if  (IS_RF_AERO)||(IS_RF_AERO1PLUS)||(IS_RF_AERO2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/    #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/    #else /*__CUST_NEW__*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/    #endif /*__CUST_NEW__*/
/* under construction !*/
/*MT6205*/ #endif
   #endif
#endif
}
/*-----------------------------------*/

static void IMM_MODE_BPI_END( void )
{
   HW_WRITE( BPI_CON, PCTRL_MAIN );
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
      HW_WRITE( BPI_ENA    , 0xFFFF );
      HW_WRITE( BPI_ENA1   , 0xFFFF );
      HW_WRITE( BPI_ENA2   , 0x3FFF );
#elif IS_CHIP_MT6227 || IS_CHIP_MT6225_AND_LATTER_VERSION
   HW_WRITE( BPI_ENA    , 0xFFFF );
   HW_WRITE( BPI_ENA1   , 0x03FF );
#elif  IS_CHIP_MT6217 || IS_CHIP_MT6218 || IS_CHIP_MT6219 || IS_CHIP_MT6228
   HW_WRITE( BPI_ENA    , 0xFFFF );
   HW_WRITE( BPI_ENA1   , 0x003F );
#else
   HW_WRITE( BPI_ENA    , 0xFFFF );
#endif

#ifndef  L1D_SIM
   #if  IS_CHIP_MT6205
/*MT6205*/ #if  (IS_RF_AERO)||(IS_RF_AERO1PLUS)|| (IS_RF_AERO2)
/* under construction !*/
/*MT6205*//*AERO*/ #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6205*//*AERO*/ #else /*__CUST_NEW__*/
/* under construction !*/
/*MT6205*//*AERO*/ #endif /*__CUST_NEW__*/
/*MT6205*/ #endif
   #endif
#endif
}
/*-----------------------------------*/

static void IMM_MODE_BSI_BEGIN( void )
{
}
/*-----------------------------------*/

static void IMM_MODE_BSI_END( void )
{
   HW_WRITE( BSI_CON, SCTRL_MAIN );
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( BSI_ENA, 0xFFFF );
   HW_WRITE( BSI_ENA1, 0x000F );
#else
   HW_WRITE( BSI_ENA, 0xFFFF );
#endif
}
/*-----------------------------------*/

void IMM_MODE_BEGIN( unsigned short imm_mask )
{
#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION   

   unsigned short pdn_con2 = 0x0000;

   if( imm_mask&IMMMASK_AFC )
   {  IMM_MODE_AFC_BEGIN();
      pdn_con2 |= 0x0010;         /* power on AFC  */      
   }

   if( imm_mask&IMMMASK_BPI )
   {  IMM_MODE_BPI_BEGIN();
      pdn_con2 |= 0x0008;         /* power on BPI  */
   }

   if( imm_mask&IMMMASK_BSI )
   {  IMM_MODE_BSI_BEGIN();
      pdn_con2 |= 0x0004;         /* power on BSI  */
   }

   /* pdn_con2 &= ~0x0001;  */    /* power on TDMA */
   HW_WRITE( PDN_CLR2, pdn_con2 );
   #if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   HW_WRITE( PDN_CLR4, pdn_con2 );
   #endif

#else

   unsigned short pdn_con2 = HW_READ( PDN_CON2 );

   if( imm_mask&IMMMASK_AFC )
   {  IMM_MODE_AFC_BEGIN();
      pdn_con2 &= ~0x0010;      /* power on AFC  */
   }

   if( imm_mask&IMMMASK_BPI )
   {  IMM_MODE_BPI_BEGIN();
      pdn_con2 &= ~0x0008;      /* power on BPI  */
   }

   if( imm_mask&IMMMASK_BSI )
   {  IMM_MODE_BSI_BEGIN();
      pdn_con2 &= ~0x0004;      /* power on BSI  */
   }

/* pdn_con2 &= ~0x0001;  */     /* power on TDMA */
   HW_WRITE( PDN_CON2, pdn_con2 );
   #if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218*/   HW_WRITE( PDN_CON4, pdn_con2 );
   #endif
#endif
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void  IMM_MODE_END( void )
{
   IMM_MODE_BSI_END();
   IMM_MODE_BPI_END();
   IMM_MODE_AFC_END();
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void  IMM_SEND_BPI( unsigned short  data )
{
#ifndef  L1D_SIM
   #if  IS_CHIP_MT6205
   /*MT6205*/ #if  (IS_RF_AERO)||(IS_RF_AERO1PLUS)|| (IS_RF_AERO2)
/* under construction !*/
   /*MT6205*//*AERO*/ #ifndef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6205*//*AERO*/ #else /*__CUST_NEW__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   /*MT6205*//*AERO*/ #endif /*__CUST_NEW__*/
   /*MT6205*/ #endif
   #endif
#endif

#if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6218*/  HW_WRITE( BPI_DATIMM, data );
#endif
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void  IMM_SEND_BSI( unsigned short ctrl, unsigned long data )
{  volatile long  addr;
   HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN);
   addr = (long)BSI_Dn_CON(0);
   HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
   HW_WRITE_BSI_DATA( addr, data );
   HW_WRITE( BSI_CON, SCTRL_IMOD_SEND);
   WAIT_TIME_QB(16); /*Max Safe Time: EX:1QB = 13/12 BSI_CLK=13/6 -> 1QB = 2BSI bit, 16QB = 32BSI bit*/
}

/*===============================================================================================*/

/*===============================================================================*/
/* short  L1D_RF_SetTxPowerLevel( int rf_band, int arfcn, short power_dbm )      */
/*===============================================================================*/
/* rf_band   : RF Band. (3:GSM, 4:DCS, 5:PCS)                                    */
/* arfcn     : ARFCN number                                                      */
/* power_dbm : Request TX power level in dBm                                     */
/* mod_type  : 0:GMSK 1:EPSK                                                     */
/* return    : Txpower level in DAC value                                        */
/* ----------------------------------------------------------------------------- */

short  L1D_RF_SetTxPowerLevel( int rf_band, int arfcn, short power_dbm, short mod_type )
{  static char  lowest_dbm;
   static char  weight_idx;
   static const sRAMPDATA*  band;
   static short apc_dcoffset_threshold = 0;
   static short apc_dcoffset_low = 0;
   static short apc_dcoffset_high = 0;
   static short first_apc_dcoffset = 0;
   short cur_apc_dcoffset;
   const sARFCN_SECTION* weight;
   short  power_dac;
   int    n;

   if(IS_1ST_TX_SLOT())
   {
      band = RampData[(int)rf_band];
      lowest_dbm = LOWEST_TX_POWER[(int)rf_band];
      // apply the 1'st burst DC offset for whole frame
      apc_dcoffset_threshold = band->lowest_power&0xFF;
      apc_dcoffset_high = ((band->lowest_power)>>8)&0x3FF;
      apc_dcoffset_low = ((band->lowest_power)>>18)&0x3FF;
      if(power_dbm<apc_dcoffset_threshold)
         first_apc_dcoffset = apc_dcoffset_low;
      else
         first_apc_dcoffset = apc_dcoffset_high;
      l1d_rf.apc_dc_offset = first_apc_dcoffset;
      HW_WRITE( APC_OFFSET, first_apc_dcoffset );

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   } /* to simplify the code, we look-up table each burst depends on its modulation type */

   #if IS_EPSK_TX_SUPPORT
   /*EPSK*/if(mod_type)
   /*EPSK*/{
   /*EPSK*/   band = RampData_EPSK[(int)rf_band];
   /*EPSK*/}
   /*EPSK*/else
   #endif     
        {
           band = RampData[(int)rf_band];
        }
#endif
      
      weight = band->arfcn_weight;
      /* Get ARFCN section */
      if(arfcn<=weight[5].max_arfcn)
      {  if(arfcn<=weight[2].max_arfcn)
         {  if(arfcn<=weight[1].max_arfcn)
            {  weight_idx = (arfcn<=weight[0].max_arfcn) ? 0 : 1;  }
            else
            {  weight_idx = 2; }
         }
         else
         {  if(arfcn<=weight[4].max_arfcn)
            {  weight_idx = (arfcn<=weight[3].max_arfcn) ? 3 : 4;  }
            else
            {  weight_idx = 5; }
         }
      }
      else
      {  if(arfcn<=weight[8].max_arfcn)
         {  if(arfcn<=weight[7].max_arfcn)
            {  weight_idx = (arfcn<=weight[6].max_arfcn) ? 6 : 7;  }
            else
            {  weight_idx = 8; }
         }
         else
         {  if(arfcn<=weight[10].max_arfcn)
            {  weight_idx = (arfcn<=weight[9].max_arfcn) ? 9 : 10;   }
            else
            {  weight_idx = 11; }
         }
      }
#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* Do nothing */
#else
   }
#endif   

   weight = &(band->arfcn_weight[weight_idx]);
   if(power_dbm>weight->mid_level)
   {  n = weight->hi_weight;  }
   else
   {  n = weight->low_weight;  }

   power_dac = (short)((band->power[(power_dbm-lowest_dbm)/2]*n)>>14);  /* power : dBm --> DAC */
   power_dac = (short)((power_dac*band->battery_compensate[l1d_rf.bat_volt][l1d_rf.bat_temp])>>14);

   if(power_dbm<apc_dcoffset_threshold)
      cur_apc_dcoffset = apc_dcoffset_low;
   else
      cur_apc_dcoffset = apc_dcoffset_high;
   // compensate the difference of H/L DC offset
   power_dac -= (first_apc_dcoffset-cur_apc_dcoffset);

   if(power_dac > 1023)  /* saturation to 10 bit DAC max. */
   {  power_dac = 1023; }

   return( power_dac );
}
/*===============================================================================================*/
#if IS_EPSK_TX_SUPPORT
short L1D_RF_SetInterslotPowerLevel(int rf_band, int arfcn, short mod_type)
{
   static char  weight_idx;
   static const sRAMPDATA*  band;
   const sARFCN_SECTION* weight;
   short  power_dac, interslot_lowest_dac;
   int    n;

   if(mod_type)
   {
      band = RampData_EPSK[(int)rf_band];
   }
   else
   {
      band = RampData[(int)rf_band];
   }

   weight = band->arfcn_weight;
   /* Get ARFCN section */
   if(arfcn<=weight[5].max_arfcn)
   {  if(arfcn<=weight[2].max_arfcn)
      {  if(arfcn<=weight[1].max_arfcn)
         {  weight_idx = (arfcn<=weight[0].max_arfcn) ? 0 : 1;  }
         else
         {  weight_idx = 2; }
      }
      else
      {  if(arfcn<=weight[4].max_arfcn)
         {  weight_idx = (arfcn<=weight[3].max_arfcn) ? 3 : 4;  }
         else
         {  weight_idx = 5; }
      }
   }
   else
   {  if(arfcn<=weight[8].max_arfcn)
      {  if(arfcn<=weight[7].max_arfcn)
         {  weight_idx = (arfcn<=weight[6].max_arfcn) ? 6 : 7;  }
         else
         {  weight_idx = 8; }
      }
      else
      {  if(arfcn<=weight[10].max_arfcn)
         {  weight_idx = (arfcn<=weight[9].max_arfcn) ? 9 : 10;   }
         else
         {  weight_idx = 11; }
      }
   }

   weight = &(band->arfcn_weight[weight_idx]);
   n = weight->low_weight;
   
   band = RampData_EPSK[(int)rf_band];
   interslot_lowest_dac = ((band->lowest_power)>>18)&0xFF;
   power_dac = (short)((interslot_lowest_dac*n)>>14);  //weight
   power_dac = (short)((power_dac*band->battery_compensate[l1d_rf.bat_volt][l1d_rf.bat_temp])>>14);  //battery compensate

   if(power_dac > 1023)  /* saturation to 10 bit DAC max. */
   {  power_dac = 1023; }

   return( power_dac );
}
#endif
/*===============================================================================*/
/* short  L1D_RF_GetRxPathLoss( int rf_band, int arfcn, short request_gain )     */
/*===============================================================================*/
/* rf_band      : RF Band. (3:GSM, 4:DCS, 5:PCS)                                 */
/* arfcn        : ARFCN number                                                   */
/* request_gain : Request Gain. the unit is 0.125 dBm                            */
/* return       : The path loss . the unit is 0.125 dBm.                         */
/* ----------------------------------------------------------------------------- */

short  L1D_RF_GetRxPathLoss( int rf_band, int arfcn, short request_gain )
{  const  sAGCGAINOFFSET*  ofs_ptr;
   short  loss_gain;

   /* Get ARFCN section */
   ofs_ptr = AGC_PATHLOSS_TABLE[rf_band];
   while( ofs_ptr->max_arfcn>=0 )
   {  if((arfcn)<=ofs_ptr->max_arfcn)
      {  break;
      }
      ofs_ptr++;
   }
   loss_gain = ofs_ptr->gain_offset;
   return( loss_gain );
}
/*===============================================================================================*/

/*===============================================================================*/
/* void  L1D_RF_NotifyBatteryVoltage( int  micro_volt )                          */
/*===============================================================================*/
/* micro_volt : The battery voltage with unit 0.0000001V                         */
/* ----------------------------------------------------------------------------- */
/* PS: The measurement period T and average sample n are set in l1d_custom_rf.h  */
/*     #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME( T )        */
/*     #define    BAT_VOLTAGE_AVERAGE_COUNT            n                         */
/* ----------------------------------------------------------------------------- */

void  L1D_RF_NotifyBatteryVoltage( int  micro_volt )
{
}

/*===============================================================================*/
/* Crystal solution parameter definition                        */
/*===============================================================================*/

#ifndef  Custom_RF_XO_CapID
long  XO_CapID = 31;
#else
long  XO_CapID = Custom_RF_XO_CapID;
#endif
/*===============================================================================================*/

/*===============================================================================*/
/* void  L1D_RF_NotifyBatteryTemperature( int  mili_degree )                     */
/*===============================================================================*/
/* mili_degree : The battery temperature with unit 0.001 degree centigrade       */
/* ----------------------------------------------------------------------------- */
/* PS: The measurement period T and average sample n are set in l1d_custom_rf.h  */
/*     #define    BAT_TEMPERATURE_SAMPLE_PERIOD            SECONDS2FRAME( T )    */
/*     #define    BAT_TEMPERATURE_AVERAGE_COUNT            n                     */
/* ----------------------------------------------------------------------------- */

void  L1D_RF_NotifyBatteryTemperature( int  mili_degree )
{
}
/*===============================================================================================*/

#ifdef __MTK_TARGET__

#if IS_RF_MT6139C  || IS_RF_MT6140A || IS_RF_MT6140B || IS_RF_MT6140C 
#if  IS_CHIP_MT6227_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  HW_BSI_DOUT_CTRL(clk, cs, data) (*(BSI_DOUT) = ((clk&0x1)|((cs<<1)&0x2)|((data<<2)&0x4)))
#define  GPIO_BSI_DIN_PORT   1 /* Use GPIO1 as BSI DATA input port       */
#define  GPIO_BSI_DIN_MODE   1 /* mode 1 : BSI RF calibration data input */
#define  GPIO_BSI_DIN_DIR    0 /* input                                  */

void  IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA    )
{
   unsigned short saved_data[2];
   short  tx_bit_cnt, rx_bit_cnt, n;
   unsigned long  rx_data;

   tx_bit_cnt = ((ADD_Ctrl>>8)&0x7F)+1;
   rx_bit_cnt = ((DATA_Ctrl>>8)&0x7F)+1;
   rx_data  = 0;

   // set GPIO_MODE
   saved_data[0] =GPIO_ReturnMode(GPIO_BSI_DIN_PORT);
   GPIO_ModeSetup(GPIO_BSI_DIN_PORT, GPIO_BSI_DIN_MODE);
   // set GPIO_DIR as input
   #ifndef __CUST_NEW__
   saved_data[1] =GPIO_ReturnDir(GPIO_BSI_DIN_PORT);
   GPIO_InitIO(GPIO_BSI_DIN_DIR, GPIO_BSI_DIN_PORT);
   #endif /*__CUST_NEW__ */   
 // BSI IO mode control register

 #if IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D
HW_WRITE( BSI_IO_CON, 0x3); //MJ 3-wire BSI SW control
#else
HW_WRITE( BSI_IO_CON, 0x7); //MJ 4-wire BSI SW control
#endif
   // Initial BSI DOUT
   HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */
   /* BSI TX begin: Send AUXOUT command */
   for( n=tx_bit_cnt-1; n>=0; n--)   
   {
      static unsigned short BSI_DOUT_DATA;
      BSI_DOUT_DATA=(ADD>>n)&0x0001;  
      HW_BSI_DOUT_CTRL(0, 0, BSI_DOUT_DATA); /*input: CLK, CS, DATA */
      HW_BSI_DOUT_CTRL(1, 0, BSI_DOUT_DATA); /*input: CLK, CS, DATA */
   }
   HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */
#if IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D
  HW_WRITE( BSI_IO_CON, 0x1); //MJ 3-wire BSI read back control
#endif
   WAIT_TIME_QB(3); 
   /* BSI TX end: Send AUXOUT command */
   /* BSI RX begin: Receive AUXOUT DATA */
   for( n=rx_bit_cnt; n>=0; n--) 
   {
      HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */
      WAIT_TIME_QB(3); 
      //latch AUXOUT Data
      if( HW_READ(BSI_DINT) & 0x1 )  // DAT=1
         rx_data |= 1;
      rx_data <<=1;
      HW_BSI_DOUT_CTRL(1, 1, 0); /*input: CLK, CS, DATA */
   }
   /* BSI RX end: Receive AUXOUT DATA */
   HW_BSI_DOUT_CTRL(0, 1, 0); /*input: CLK, CS, DATA */   
   WAIT_TIME_QB(3);
   HW_BSI_DOUT_CTRL(0, 0, 0); /*input: CLK, CS, DATA */  

   GPIO_ModeSetup(GPIO_BSI_DIN_PORT, saved_data[0]);
   #ifndef __CUST_NEW__
   GPIO_InitIO(saved_data[1] , GPIO_BSI_DIN_PORT);
   #endif /*__CUST_NEW__ */

   // BSI IO mode control register
   HW_WRITE( BSI_IO_CON, 0x2);  //BSI return HW control
   *DATA = rx_data>>1;
}

#elif IS_CHIP_MT6205_AND_LATTER_VERSION
#ifdef __CUST_NEW__
   extern const char gpio_rf_control2_pin;
   #define  GPIO_BSI_DIN_PORT   gpio_rf_control2_pin /* Use GPIO as BSI DATA input port */
#else /* __CUST_NEW__ */
#define  GPIO_BSI_DIN_PORT   1 /* Use GPIO1 as BSI DATA input port */
#endif /* __CUST_NEW__ */
#define  GPIO_BSI_DIN_MODE   0 /* mode 0 : GPIO                    */
#define  GPIO_BSI_DIN_DIR    0 /* input                            */

#if IS_CHIP_MT6205

   #ifdef __CUST_NEW__
      extern const char gpio_rf_control3_pin;
      #define  GPIO_BSI_CLK_PORT   gpio_rf_control3_pin /* Use GPIO as BSI CLK output port*/
   #else /* __CUST_NEW__ */
#define  GPIO_BSI_CLK_PORT  6 /* Use GPIO6(BPI6) as BSI CLK output port*/
   #endif /* __CUST_NEW__ */
#define  GPIO_BSI_CLK_MODE   0 /* mode 0 : GPIO                    */
#define  GPIO_BSI_CLK_DIR    1 /* output                           */

#else /* IS_CHIP_MT6205 */

   #ifdef __CUST_NEW__
      extern const char gpio_rf_control3_pin;
      #define  GPIO_BSI_CLK_PORT   gpio_rf_control3_pin /* Use GPIO as BSI CLK output port*/
   #else /* __CUST_NEW__ */
#define  GPIO_BSI_CLK_PORT  10 /* Use GPIO10(BPI6) as BSI CLK output port*/
   #endif /* __CUST_NEW__ */
#define  GPIO_BSI_CLK_MODE   0 /* mode 0 : GPIO                    */
#define  GPIO_BSI_CLK_DIR    1 /* output                           */

#endif /* IS_CHIP_MT6205 */

void  IMM_RECEIVE_BSI( unsigned short ADD_Ctrl, unsigned long ADD, unsigned short DATA_Ctrl, unsigned long *DATA    )
{
   unsigned short saved_data[4];
   short  n, rx_bit_cnt;
   unsigned long  rx_data;

   rx_bit_cnt = ((DATA_Ctrl>>8)&0x7F)+1;
   rx_data  = 0;
   
   // set GPIO_MODE as BSI read back CLK
   saved_data[0] =GPIO_ReturnMode(GPIO_BSI_CLK_PORT);
   GPIO_ModeSetup(GPIO_BSI_DIN_PORT, GPIO_BSI_CLK_MODE);
   // set GPIO_DIR as input to avoid interfering with BSI CLK
   saved_data[1] =GPIO_ReturnDir(GPIO_BSI_CLK_PORT);
   GPIO_InitIO(~GPIO_BSI_CLK_DIR, GPIO_BSI_CLK_PORT);
   // set GPIO_MODE as BSI read back DATA_IN
   saved_data[2] =GPIO_ReturnMode(GPIO_BSI_DIN_PORT);
   GPIO_ModeSetup(GPIO_BSI_DIN_PORT, GPIO_BSI_DIN_MODE);
   // set GPIO_DIR as input
   saved_data[3] =GPIO_ReturnDir(GPIO_BSI_DIN_PORT);
   GPIO_InitIO(GPIO_BSI_DIN_DIR, GPIO_BSI_DIN_PORT);
   
   {  volatile unsigned long  addr;
      HW_WRITE( BSI_CON, SCTRL_IMOD_RX_MAIN );
      addr = (long)BSI_Dn_CON(0);
      HW_WRITE( (APBADDR)addr, ADD_Ctrl );  addr += 4;
      HW_WRITE_BSI_DATA( addr, ADD );
      HW_WRITE( BSI_CON, SCTRL_IMOD_RX_SEND );  // send AUXOUT commend
      WAIT_TIME_QB(64);
   }
   GPIO_InitIO(GPIO_BSI_CLK_DIR, GPIO_BSI_CLK_PORT);// set GPIO_DIR as output to generate BSI read back CLK
   
   GPIO_WriteIO(0, GPIO_BSI_CLK_PORT);   // set GPIO_CLK_DOUT = 0
   for( n=rx_bit_cnt; n>=0; n--)
   {
      GPIO_WriteIO(1, GPIO_BSI_CLK_PORT);    // set GPIO_CLK_DOUT = 1
      //latch AUXOUT Data
      if( GPIO_ReadIO(GPIO_BSI_DIN_PORT) & 0x1 )  // DAT=1
         rx_data |= 1;
      rx_data <<=1;  
      GPIO_WriteIO(0, GPIO_BSI_CLK_PORT);   // set GPIO_CLK_DOUT = 0
   }
   rx_data >>=1;
   GPIO_ModeSetup(GPIO_BSI_DIN_PORT, saved_data[0] );
   GPIO_InitIO(  saved_data[1] , GPIO_BSI_CLK_PORT);
   GPIO_ModeSetup(GPIO_BSI_DIN_PORT, saved_data[2] );
   GPIO_InitIO(saved_data[3] , GPIO_BSI_DIN_PORT);
   *DATA = rx_data;
}

#endif
#endif /*IS_RF_MT6139C || IS_RF_MT6140A || IS_RF_MT6140B*/
#endif //#ifdef __MTK_TARGET__ 

/*===============================================================================================*/
void L1D_RF_TXIQ_Dynamic_Swap()
{
#if BBTX_IQSWAP_ONFLY //BBTx has double buffer design for TXIQSWAP
	l1d_rf.d2c_txiqswap = 0;
#elif IS_RF_SKY74117 || IS_RF_SKY74400
/* under construction !*/
#else
   l1d_rf.d2c_txiqswap = 0;
#endif
}

void L1D_BFE_SetTxIQSwap()
{
   BFETXSET  bfetxset;   
   HW_READ_BFETXSET( bfetxset );
      
   if(l1d_rf.inj)   
      bfetxset.field.iqswap = 1;
   else
      bfetxset.field.iqswap = 0;
 
   HW_WRITE_BFETXSET( bfetxset );
}

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
void L1D_RF_TXIQ_Dynamic_Config()
{
   #if IS_RF_MT6140B || IS_RF_MT6140C || IS_RF_MT6140D
   l1d_rf.d2c_txiqconfig = 1;
   #else
   l1d_rf.d2c_txiqconfig = 0;
   #endif
}

void L1D_BFE_SetTxIQ_Config()
{
   BFETXSET  bfetxset;

   HW_READ_BFETXSET( bfetxset );

   if(l1d_rf.band<=2) //Low band
   {
      bfetxset.field.trimi    = BBTXParameters.bbtx_trimI;
      bfetxset.field.trimq    = BBTXParameters.bbtx_trimQ;
      bfetxset.field.offi     = BBTXParameters.bbtx_offsetI;
      bfetxset.field.offq     = BBTXParameters.bbtx_offsetQ;
      bfetxset.field.gain     = BBTXParameters.bbtx_gain;
      bfetxset.field.cmv      = BBTXParameters.bbtx_common_mode_voltage;
      bfetxset.field.calrcsel = BBTXParameters.bbtx_calrcsel;
      bfetxset.field.phsel    = BBTXParameters.bbtx_phsel;
   #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION // 23 may use MT6140D
      bfetxset.field.dccoarsei= BBTXParameters.bbtx_dccoarseI;
      bfetxset.field.dccoarseq= BBTXParameters.bbtx_dccoarseQ;
   #endif
   }
   else   //High band
   {
      bfetxset.field.trimi    = BBTXParameters.bbtx_trimI_h;
      bfetxset.field.trimq    = BBTXParameters.bbtx_trimQ_h;
      bfetxset.field.offi     = BBTXParameters.bbtx_offsetI_h;
      bfetxset.field.offq     = BBTXParameters.bbtx_offsetQ_h;
      bfetxset.field.gain     = BBTXParameters.bbtx_gain_h;
      bfetxset.field.cmv      = BBTXParameters.bbtx_common_mode_voltage_h;
      bfetxset.field.calrcsel = BBTXParameters.bbtx_calrcsel_h;
      bfetxset.field.phsel    = BBTXParameters.bbtx_phsel_h;
   #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION // 23 may use MT6140D
      bfetxset.field.dccoarsei= BBTXParameters.bbtx_dccoarseI_h;
      bfetxset.field.dccoarseq= BBTXParameters.bbtx_dccoarseQ_h;
   #endif
   }
   HW_WRITE_BFETXSET( bfetxset );
   l1d_rf.old_band=l1d_rf.band;

}
#endif

/* ------------------------------------------------------------------------- */

void L1D_AFCDAC_On( void )			
{  
#if defined(AFC_VCXO)	
   unsigned short d16;
   
   HW_WRITE( AFC_PUPER, TQ_Afc_ChargeInIdle );
   d16 = HW_READ( AFC_CON );
   d16 |= AFC_FORCE_POWER_ON;							
   HW_WRITE( AFC_CON, d16 );		   
#endif
}
/* ------------------------------------------------------------------------- */

void L1D_AFCDAC_Off( void )
{
#if defined(AFC_VCXO)	
   unsigned short d16;
   
   d16 = HW_READ( AFC_CON );
   d16 &= ~AFC_FORCE_POWER_ON;          		
   HW_WRITE( AFC_CON, d16 );
   HW_WRITE( AFC_PUPER, 0 );			/* For AFC SW power down bit PDN_CON2[4]/PDN_CON4[4] is malfunction */
   										/* This HW bug is fixed in MT6227 and MT6225 */
#endif
}

unsigned long  L1D_RF_GetITC_PCL(void) /*For META 2 range PCL calibration*/
{
#if defined(__EPSK_TX__)	
   #if IS_RF_MT6140D
   extern unsigned short LB_CW_High_Idx;
   extern unsigned short HB_CW_High_Idx;
   return (((15-HB_CW_High_Idx) <<16)|(19-LB_CW_High_Idx));
   #else
   return 0xFFFFFFFF;
   #endif
#endif
}

/*=======================================================================================================*/
/* short  L1D_RF_GetTxPAVBias_TxITC(  unsigned short lb_cw_high_idx, unsigned short hb_cw_high_idx )     */
/*=======================================================================================================*/
/* lb_cw_high_idx      : Low  band PCL switch point                                                      */
/* hb_cw_high_idx      : High band PCL switch point                                                      */
/* return              : PA Vbias                                                                        */
/* ----------------------------------------------------------------------------------------------------- */

unsigned short  L1D_RF_GetTxPAVBias_TxITC( unsigned short lb_cw_high_idx, unsigned short hb_cw_high_idx)
{  
#if defined(__EPSK_TX__)
   #if IS_RF_MT6140D
   const  pa_vbias*  ofs_ptr;
   unsigned short  pcl2idx;
   unsigned char  pa_vbias, is_new_cw;
   unsigned short idx;   
   idx = (l1d_rf.tx_power[l1d_rf.cur_slot]-LOWEST_TX_POWER[l1d_rf.band])/2;
   /* Get PCL index section */
   if(l1d_rf.band>2)
   {
      ofs_ptr = (l1d_rf.band==3)? RFSpecialCoef.tx.mt6140tx.data.DCS1800_pa_vbias : RFSpecialCoef.tx.mt6140tx.data.PCS1900_pa_vbias;
      is_new_cw=(idx<hb_cw_high_idx)? 1:0;	
      pcl2idx=15;	  
   }	 
   else
   {
      ofs_ptr = (l1d_rf.band==1)?RFSpecialCoef.tx.mt6140tx.data.GSM850_pa_vbias : RFSpecialCoef.tx.mt6140tx.data.GSM900_pa_vbias;	
      is_new_cw=(idx<lb_cw_high_idx)? 1:0;
      pcl2idx=19;	  
   }	
   while( (ofs_ptr->pcl_index>=0))
   {  if((idx)>=(pcl2idx-ofs_ptr->pcl_index))
      {  break;
      }
      ofs_ptr++;
   }
   pa_vbias = ofs_ptr->pa_vbias;
   return( (pa_vbias&0x7)|((is_new_cw)&0x1)<<4 );
   #endif
#endif
}

