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
 *	m12195.c
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   Setup RF Ramp
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

#define  SETUP_SR1()  \
   int  event_idx;  \
   int  data_idx;  \
   event_idx = l1d_rf.cwin_idx*2+0;  \
   data_idx  = l1d_rf.cwin_idx*(SX1_DATA_COUNT+SX3_DATA_COUNT)+0;

#define  SETUP_SR3()  \
   int  event_idx;  \
   int  data_idx;  \
   event_idx = l1d_rf.cwin_idx*2+1;  \
   data_idx  = l1d_rf.cwin_idx*(SX1_DATA_COUNT+SX3_DATA_COUNT)+SX1_DATA_COUNT;

#define  SETUP_SR2()  \
   int  event_idx;  \
   int  data_idx;  \
   event_idx = AGCIDX( l1d_rf.rtxwin_idx );  \
   data_idx  = AGCDTIDX( l1d_rf.rtxwin_idx );

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
#define  SETUP_ST2B_ST2M() \
   int  event_idx;  \
   int  data_idx;  \
   event_idx = l1d_rf.rtxwin_idx+16;  \
   data_idx  = ST2B_ST2M_IDX( l1d_rf.rtxwin_idx );
#endif

#define  SETUP_ST1()  SETUP_SR1()
#define  SETUP_ST2()  SETUP_SR2()
#define  SETUP_ST3()  SETUP_SR3()

#define  HWRITE_1_SDATA( ctrl1, data1 )  \
{  HW_WRITE_BSI_DATA_1( data_idx, ((ctrl1)|event_idx), (data1) );  \
}

#define  HWRITE_2_SDATA( ctrl1, data1, ctrl2, data2 )  \
{  HW_WRITE_BSI_DATA_2( data_idx, ((ctrl1)|event_idx), (data1),  \
                                  ((ctrl2)|event_idx), (data2) );  \
}

#define  HWRITE_3_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3 )  \
{  HW_WRITE_BSI_DATA_3( data_idx, ((ctrl1)|event_idx), (data1),  \
                                  ((ctrl2)|event_idx), (data2),  \
                                  ((ctrl3)|event_idx), (data3) );  \
}

#define  HWRITE_4_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4 )  \
{  HW_WRITE_BSI_DATA_4( data_idx, ((ctrl1)|event_idx), (data1),  \
                                  ((ctrl2)|event_idx), (data2),  \
                                  ((ctrl3)|event_idx), (data3),  \
                                  ((ctrl4)|event_idx), (data4) );  \
}

#define  HWRITE_5_SDATA( ctrl1, data1, ctrl2, data2, ctrl3, data3, ctrl4, data4, ctrl5, data5 )  \
{  HW_WRITE_BSI_DATA_5( data_idx, ((ctrl1)|event_idx), (data1),  \
                                  ((ctrl2)|event_idx), (data2),  \
                                  ((ctrl3)|event_idx), (data3),  \
                                  ((ctrl4)|event_idx), (data4),  \
                                  ((ctrl5)|event_idx), (data5) );  \
}
/*---------------------------------------------------------------------------*/

void  L1D_RF_SetPData_PR( void )
{  APBADDR      _reg;
   const short *_d16p;

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_RX ];
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
#if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
   _d16p++;
   _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
   HW_WRITE( _reg, *_d16p );
#endif   
}

#if  !(IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION)
void  L1D_RF_SetPData_PT( void )
{  APBADDR      _reg;
   const short *_d16p;

   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_TX ];
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
   HW_WRITE( _reg, *_d16p );
#if  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ {  int idx = l1d_rf.rx_slots<=11 ? 0 : 1;
/*MT6218~*/    _reg  = PDATA_PT2B_REG_TABLE[idx][ l1d_rf.cwin_idx ];
/*MT6218~*/    _d16p = PDATA_TABLE2[ l1d_rf.band ][ RF_TX ];
/*MT6218~*/    HW_WRITE( _reg, *_d16p );
/*MT6218~*/ }
#endif
}

#else
void  L1D_RF_SetPData_PT( void )
{  APBADDR      _reg;
   const short *_d16p;
   
   _reg  = PDATA_REG_TABLE[ l1d_rf.cwin_idx ];
   _d16p = PDATA_TABLE[ l1d_rf.band ][ RF_TX ];
   if ( (l1d_rf.tx_mod_type) & (1<<l1d_rf.modidx) ) 
   {  
      HW_WRITE( _reg, ((*_d16p)|(PDATA_8PSK)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(PDATA_8PSK)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(PDATA_8PSK)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, (*_d16p) );//PT3 is end, doesn't need to | PDATA_8PSK
      /* PT3A */
      _d16p++;
      _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
      HW_WRITE( _reg, (*_d16p) );      
   }
   else
   {  
      HW_WRITE( _reg, ((*_d16p)|(PDATA_GMSK)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(PDATA_GMSK)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, ((*_d16p)|(PDATA_GMSK)) );   _reg+=2;   _d16p++;
      HW_WRITE( _reg, (*_d16p) );//PT3 is end, doesn't need to | PDATA_GMSK
      /* PT3A */
      _d16p++;
      _reg = PDATA_REG_TABLE2[ l1d_rf.cwin_idx ];
      HW_WRITE( _reg, (*_d16p) );
   }   
   }
#endif

void  L1D_RF_SetPData_PR2M( void )
{
#if  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6218~*/ APBADDR      _reg;
/*MT6218~*/ const short *_d16p;
/*MT6218~*/
/*MT6218~*/ _reg  = PDATA_PR2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6218~*/ _d16p = PDATA_TABLE2[ l1d_rf.band ][ RF_RX ];
/*MT6218~*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6218~*/ HW_WRITE( _reg, *_d16p );

#elif IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229*/ APBADDR      _reg;
/*MT6229*/ const short *_d16p;
/*MT6229*/   
/*MT6229*/ _reg  = PDATA_PR2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6229*/ _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_RX ];
/*MT6229*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229*/ HW_WRITE( _reg, *_d16p );
#endif
}

#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6229~*/#if IS_EPSK_TX_SUPPORT
/*MT6229~*//*EGPRS*/void  L1D_RF_SetPData_PT2M( void )
/*MT6229~*//*EGPRS*/{   
/*MT6229~*//*EGPRS*/   APBADDR      _reg;
/*MT6229~*//*EGPRS*/   const short *_d16p;
/*MT6229~*//*EGPRS*/   short _d16p2;
/*MT6229~*//*EGPRS*/   
/*MT6229~*//*EGPRS*/   _reg  = PDATA_PT2M_REG_TABLE[ l1d_rf.rtxwin_idx ];
/*MT6229~*//*EGPRS*/   _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_TX ];
/*MT6229~*//*EGPRS*/   _d16p2 = PDATA_TABLE[ l1d_rf.band ][ RF_TX ][2]; //PDATA of PT2B, so PT2B must later than PT2
/*MT6229~*//*EGPRS*/   //now 8PSK
/*MT6229~*//*EGPRS*/   if ((l1d_rf.tx_mod_type)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/   {  //change, g-->8
/*MT6229~*//*EGPRS*/      if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/      {  
/*MT6229~*//*EGPRS*/         /*Set M1*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/         /*Set M2*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/         /*Set M3*/ HW_WRITE( _reg, *_d16p );
/*MT6229~*//*EGPRS*/      }
/*MT6229~*//*EGPRS*/      //no change
/*MT6229~*//*EGPRS*/      else
/*MT6229~*//*EGPRS*/      {  HW_WRITE( _reg, ((_d16p2)|(PDATA_8PSK)) );   _reg+=2;
/*MT6229~*//*EGPRS*/         HW_WRITE( _reg, ((_d16p2)|(PDATA_8PSK)) );   _reg+=2;
/*MT6229~*//*EGPRS*/         HW_WRITE( _reg, ((_d16p2)|(PDATA_8PSK)) );
/*MT6229~*//*EGPRS*/      }
/*MT6229~*//*EGPRS*/   }
/*MT6229~*//*EGPRS*/   //now GMSK
/*MT6229~*//*EGPRS*/   else
/*MT6229~*//*EGPRS*/   {  //change, 8-->g
/*MT6229~*//*EGPRS*/      _d16p = PDATA_TABLE3[ l1d_rf.band ][ RF_TX_8G];
/*MT6229~*//*EGPRS*/      if ((l1d_rf.change)&(1<<l1d_rf.rtxwin_idx))
/*MT6229~*//*EGPRS*/      {  
/*MT6229~*//*EGPRS*/         /*Set M1*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/         /*Set M2*/ HW_WRITE( _reg, *_d16p );   _reg+=2;   _d16p++;
/*MT6229~*//*EGPRS*/         /*Set M3*/ HW_WRITE( _reg, *_d16p );
/*MT6229~*//*EGPRS*/      }
/*MT6229~*//*EGPRS*/      //no change
/*MT6229~*//*EGPRS*/      else
/*MT6229~*//*EGPRS*/      {  HW_WRITE( _reg, ((_d16p2)|(PDATA_GMSK)) );   _reg+=2;
/*MT6229~*//*EGPRS*/         HW_WRITE( _reg, ((_d16p2)|(PDATA_GMSK)) );   _reg+=2;
/*MT6229~*//*EGPRS*/         HW_WRITE( _reg, ((_d16p2)|(PDATA_GMSK)) );
/*MT6229~*//*EGPRS*/      }
/*MT6229~*//*EGPRS*/   }
/*MT6229~*//*EGPRS*/   
/*MT6229~*//*EGPRS*/}
/*MT6229~*/#else
/*MT6229~*/void  L1D_RF_SetPData_PT2M( void )
/*MT6229~*/{
/*MT6229~*/}
/*MT6229~*/#endif /*End of IS_EPSK_TX_SUPPORT*/
#else
/*mt6218~*/void  L1D_RF_SetPData_PT2M( void )
/*mt6218~*/{
/*mt6218~*/}
#endif
/*---------------------------------------------------------------------------*/

#if  IS_RF_BRIGHT2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #if  IS_FPGA_TARGET
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #endif
/*BRIGHT2*/ #if  IS_CHIP_TARGET
/* under construction !*/
/* under construction !*/
/*BRIGHT2*/ #endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_BRIGHT4
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
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_BRIGHT5P
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT5P*/ #endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_AERO
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_AERO1PLUS
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_POLARIS1
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
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_SKY74117
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
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_SKY74400
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
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6119
/*MT6119*/
/*MT6119*/ /*..........................................................*/
/*MT6119*/ /*  Define Alias and Table                                  */
/*MT6119*/ /*..........................................................*/
/*MT6119*/
/*MT6119*/ #define  SCTRL_PLL                    SCTRL_WORD(0,23)
/*MT6119*/ #define  SCTRL_AGC                    SCTRL_WORD(0,23)
/*MT6119*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,23)
/*MT6119*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,23) /* CW4 */
/*MT6119*/
/*MT6119*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6119*/ {
/*MT6119*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6119*/    {       0L,       0L },  /* FrequencyBand850 (not support)  */
/*MT6119*/    { 0x08802L, 0x18802L },  /* FrequencyBand900                */
/*MT6119*/    { 0x09002L, 0x19002L },  /* FrequencyBand1800               */
/*MT6119*/    { 0x09802L, 0x19802L },  /* FrequencyBand1900               */
/*MT6119*/ };
/*MT6119*/ const unsigned long SDATA_TXLPFGAIN_TABLE[5]=
/*MT6119*/ {
/*MT6119*/      0x13D504,  /* FrequencyBand400 (not support)  */
/*MT6119*/      0x13D504,  /* FrequencyBand850 (not support)  */
/*MT6119*/      0x13D504,  /* FrequencyBand900                */
/*MT6119*/      0x13DF04,  /* FrequencyBand1800               */
/*MT6119*/      0x13DF04   /* FrequencyBand1900               */
/*MT6119*/ };
/*MT6119*/
/*MT6119*/ /*..........................................................*/
/*MT6119*/ /* Serial Interface Implement                               */
/*MT6119*/ /*..........................................................*/
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_SR1( void )
/*MT6119*/ {
/*MT6119*/    SETUP_SR1();
/*MT6119*/    HWRITE_2_SDATA( SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6119*/                    SCTRL_RESERVED, 0 );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_SR2( void )
/*MT6119*/ {
/*MT6119*/    SETUP_SR2();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_SR3( void )
/*MT6119*/ {
/*MT6119*/    SETUP_SR3();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_ST1( void )
/*MT6119*/ {
/*MT6119*/    SETUP_ST1();
/*MT6119*/    HWRITE_2_SDATA( SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6119*/                    SCTRL_TXLPFGAIN, SDATA_TXLPFGAIN_TABLE[l1d_rf.band] );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_ST2( void )
/*MT6119*/ {  extern char mt6119_d_flag;
/*MT6119*/    SETUP_ST2();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6119*/ }
/*MT6119*/
/*MT6119*/ void  L1D_RF_SetSData_ST3( void )
/*MT6119*/ {
/*MT6119*/    SETUP_ST3();
/*MT6119*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119*/ }
/*MT6119*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6119C
/*MT6119C*/
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/ /*  Define Alias and Table                                  */
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/
/*MT6119C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,23)
/*MT6119C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,23)
/*MT6119C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,23)
/*MT6119C*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,23) /* CW4 */
/*MT6119C*/
/*MT6119C*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6119C*/ {
/*MT6119C*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6119C*/    {       0L,       0L },  /* FrequencyBand850 (not support)  */
/*MT6119C*/    {0x128992L,0x138992L },  /* FrequencyBand900                */
/*MT6119C*/    {0x129192L,0x139192L },  /* FrequencyBand1800               */
/*MT6119C*/    {0x129992L,0x139992L },  /* FrequencyBand1900               */
/*MT6119C*/ };
/*MT6119C*/ const unsigned long SDATA_TXLPFGAIN_TABLE[5]=
/*MT6119C*/ {
/*MT6119C*/      0x13D504,  /* FrequencyBand400 (not support)  */
/*MT6119C*/      0x13D504,  /* FrequencyBand850 (not support)  */
/*MT6119C*/      0x13D504,  /* FrequencyBand900                */
/*MT6119C*/      0x13DF04,  /* FrequencyBand1800               */
/*MT6119C*/      0x13DF04   /* FrequencyBand1900               */
/*MT6119C*/ };
/*MT6119C*/
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/ /* Serial Interface Implement                               */
/*MT6119C*/ /*..........................................................*/
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_SR1();
/*MT6119C*/    HWRITE_3_SDATA( SCTRL_WARM,     SDATA_WARM,
/*MT6119C*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6119C*/                    SCTRL_RESERVED, 0 );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_SR2( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_SR2();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_SR3( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_SR3();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_ST1();
/*MT6119C*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM,
/*MT6119C*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6119C*/                    SCTRL_TXLPFGAIN, SDATA_TXLPFGAIN_TABLE[l1d_rf.band] );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6119C*/ {  extern char mt6119_d_flag;
/*MT6119C*/    SETUP_ST2();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6119C*/ }
/*MT6119C*/
/*MT6119C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6119C*/ {
/*MT6119C*/    SETUP_ST3();
/*MT6119C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6119C*/ }
/*MT6119C*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6129A
/*MT6129A*/
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/ /*  Define Alias and Table                                  */
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/
/*MT6129A*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129A*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129A*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129A*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,24) /* CW4 */
/*MT6129A*/
/*MT6129A*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129A*/ {
/*MT6129A*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129A*/    {       0L,       0L },  /* FrequencyBand850 (not support)  */
/*MT6129A*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129A*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129A*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129A*/ };
/*MT6129A*/ const unsigned long SDATA_TXVCOBAND_TABLE[5]=
/*MT6129A*/ {
/*MT6129A*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129A*/           0x0,  /* FrequencyBand850 (not support)  */
/*MT6129A*/      0x124982,  /* FrequencyBand900                */
/*MT6129A*/      0x125182,  /* FrequencyBand1800               */
/*MT6129A*/      0x125982   /* FrequencyBand1900               */
/*MT6129A*/ };
/*MT6129A*/
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/ /* Serial Interface Implement                               */
/*MT6129A*/ /*..........................................................*/
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_SR1();
/*MT6129A*/    HWRITE_2_SDATA( SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129A*/                    SCTRL_RESERVED, 0 );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_SR2();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_SR3();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_ST1();
/*MT6129A*/    HWRITE_2_SDATA( SCTRL_TXBAND,   SDATA_TXVCOBAND_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129A*/                    SCTRL_PLL,       l1d_rf.RFN_data);
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129A*/ {  extern char mt6119_d_flag;
/*MT6129A*/    SETUP_ST2();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129A*/ }
/*MT6129A*/
/*MT6129A*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129A*/ {
/*MT6129A*/    SETUP_ST3();
/*MT6129A*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129A*/ }
/*MT6129A*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6129B
/*MT6129B*/
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/ /*  Define Alias and Table                                  */
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/
/*MT6129B*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129B*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129B*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129B*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,24) /* CW4 */
/*MT6129B*/
/*MT6129B*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129B*/ {
/*MT6129B*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129B*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129B*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129B*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129B*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129B*/ };
/*MT6129B*/ const unsigned long SDATA_TXVCOBAND_TABLE[5]=
/*MT6129B*/ {
/*MT6129B*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129B*/      0x124182,  /* FrequencyBand850                */
/*MT6129B*/      0x124982,  /* FrequencyBand900                */
/*MT6129B*/      0x125182,  /* FrequencyBand1800               */
/*MT6129B*/      0x125982   /* FrequencyBand1900               */
/*MT6129B*/ };
/*MT6129B*/ const unsigned long SDATA_TXLPFGAIN_TABLE[5]=
/*MT6129B*/ {
/*MT6129B*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129B*/      0x2AA824,  /* FrequencyBand850                */
/*MT6129B*/      0x2AA824,  /* FrequencyBand900                */
/*MT6129B*/      0x22A824,  /* FrequencyBand1800               */
/*MT6129B*/      0x2AA824   /* FrequencyBand1900               */
/*MT6129B*/ };
/*MT6129B*/
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/ /* Serial Interface Implement                               */
/*MT6129B*/ /*..........................................................*/
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_SR1();
/*MT6129B*/    HWRITE_3_SDATA( SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129B*/                    SCTRL_RESERVED, 0,
/*MT6129B*/                    SCTRL_RESERVED, 0 );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_SR2();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_SR3();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_ST1();
/*MT6129B*/    HWRITE_3_SDATA( SCTRL_TXBAND,    SDATA_TXVCOBAND_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129B*/                    SCTRL_TXLPFGAIN, SDATA_TXLPFGAIN_TABLE[l1d_rf.band],
/*MT6129B*/                    SCTRL_PLL,       l1d_rf.RFN_data);
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129B*/ {  extern char mt6119_d_flag;
/*MT6129B*/    SETUP_ST2();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129B*/ }
/*MT6129B*/
/*MT6129B*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129B*/ {
/*MT6129B*/    SETUP_ST3();
/*MT6129B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129B*/ }
/*MT6129B*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6129C
/*MT6129C*/
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/ /*  Define Alias and Table                                  */
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/
/*MT6129C*/ #define  SCTRL_WARM                   SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129C*/ #define  SCTRL_TXLPFGAIN              SCTRL_WORD(0,24) /* CW4 */
/*MT6129C*/
/*MT6129C*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129C*/ {
/*MT6129C*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129C*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129C*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129C*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129C*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129C*/ };
/*MT6129C*/ const unsigned long SDATA_WARM_TABLE[5]=
/*MT6129C*/ {
/*MT6129C*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129C*/      0x122182,  /* FrequencyBand850                */
/*MT6129C*/      0x122982,  /* FrequencyBand900                */
/*MT6129C*/      0x123182,  /* FrequencyBand1800               */
/*MT6129C*/      0x123982   /* FrequencyBand1900               */
/*MT6129C*/ };
/*MT6129C*/
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/ /* Serial Interface Implement                               */
/*MT6129C*/ /*..........................................................*/
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_SR1();
/*MT6129C*/    HWRITE_3_SDATA( SCTRL_WARM,     SDATA_WARM_TABLE[l1d_rf.band],
/*MT6129C*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129C*/                    SCTRL_RESERVED, 0 );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_SR2();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_SR3();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_ST1();
/*MT6129C*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129C*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6129C*/                    SCTRL_RESERVED, 0);
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129C*/ {  extern char mt6119_d_flag;
/*MT6129C*/    SETUP_ST2();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129C*/ }
/*MT6129C*/
/*MT6129C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129C*/ {
/*MT6129C*/    SETUP_ST3();
/*MT6129C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129C*/ }
/*MT6129C*/
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6129D
/*MT6129D*/
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/ /*  Define Alias and Table                                  */
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/
/*MT6129D*/ #define  SCTRL_WARM                   SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_PLL                    SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_AGC                    SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,24)
/*MT6129D*/ #define  SCTRL_TXIAC                  SCTRL_WORD(0,24) /* CW4 */
/*MT6129D*/
/*MT6129D*/ const unsigned long SDATA_TXBAND_TABLE[5][2] =
/*MT6129D*/ {
/*MT6129D*/    {       0L,       0L },  /* FrequencyBand400 (not support)  */
/*MT6129D*/    {0x128182L,0x138182L },  /* FrequencyBand850                */
/*MT6129D*/    {0x128982L,0x138982L },  /* FrequencyBand900                */
/*MT6129D*/    {0x129182L,0x139182L },  /* FrequencyBand1800               */
/*MT6129D*/    {0x129982L,0x139982L },  /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/ // For case of GSM850 in GSM900 path
/*MT6129D*/ const unsigned long SDATA_WARM_TABLE_RX_GSM850in900[5]=           
/*MT6129D*/ {                                                     
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */ 
/*MT6129D*/      0x122982,  /* FrequencyBand850 (Get GSM850 signal from GSM900 input pins) */
/*MT6129D*/      0x122182,  /* FrequencyBand900 (Get GSM900 signal from GSM850 input pins, just avoid to camp on GSM900 network, not swap*/
/*MT6129D*/      0x123182,  /* FrequencyBand1800               */
/*MT6129D*/      0x123982   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/ const unsigned long SDATA_WARM_TABLE[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x122182,  /* FrequencyBand850                */
/*MT6129D*/      0x122982,  /* FrequencyBand900                */
/*MT6129D*/      0x123182,  /* FrequencyBand1800               */
/*MT6129D*/      0x123982   /* FrequencyBand1900               */
/*MT6129D*/ };

/*MT6129D*/ const unsigned long SDATA_TXIAC_TABLE[5]=
/*MT6129D*/ {
/*MT6129D*/           0x0,  /* FrequencyBand400 (not support)  */
/*MT6129D*/      0x342854,  /* FrequencyBand850                */
/*MT6129D*/      0x342854,  /* FrequencyBand900                */
/*MT6129D*/      0x14A854,  /* FrequencyBand1800               */
/*MT6129D*/      0x14A854   /* FrequencyBand1900               */
/*MT6129D*/ };
/*MT6129D*/
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/ /* Serial Interface Implement                               */
/*MT6129D*/ /*..........................................................*/
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR1( void )
/*MT6129D*/ {  unsigned long sdata_warm;
/*MT6129D*/ 
/*MT6129D*/    SETUP_SR1();
/*MT6129D*/ 
/*MT6129D*/    if( BBTXParameters.bbrx_gsm850_gsm900_swap )
/*MT6129D*/    {   sdata_warm = SDATA_WARM_TABLE_RX_GSM850in900[l1d_rf.band];
/*MT6129D*/    }else
/*MT6129D*/    {   sdata_warm = SDATA_WARM_TABLE[l1d_rf.band];
/*MT6129D*/    }
/*MT6129D*/    				
/*MT6129D*/    HWRITE_3_SDATA( SCTRL_WARM,     sdata_warm,
/*MT6129D*/                    SCTRL_PLL,      l1d_rf.RFN_data,
/*MT6129D*/                    SCTRL_RESERVED, 0 );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR2( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_SR2();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_AGC, l1d_rf.AGC_data );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_SR3( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_SR3();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST1( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_ST1();
/*MT6129D*/    HWRITE_3_SDATA( SCTRL_WARM,      SDATA_WARM_TABLE[l1d_rf.band],  /*Band information for TXVCO*/
/*MT6129D*/                    SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6129D*/                    SCTRL_TXIAC,     SDATA_TXIAC_TABLE[l1d_rf.band]);
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST2( void )
/*MT6129D*/ {  extern char mt6119_d_flag;
/*MT6129D*/    SETUP_ST2();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_TXBAND, SDATA_TXBAND_TABLE[l1d_rf.band][mt6119_d_flag] );
/*MT6129D*/ }
/*MT6129D*/
/*MT6129D*/ void  L1D_RF_SetSData_ST3( void )
/*MT6129D*/ {
/*MT6129D*/    SETUP_ST3();
/*MT6129D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6129D*/ }
/*MT6129D*/
#endif

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6139B
/*MT6139B*/
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/ /*  Define Alias and Table                                  */
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/
/*MT6139B*/
/*MT6139B*/ #define  SCTRL_WARM                    SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_PLL                    SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_AGC                    SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,25)
/*MT6139B*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,25) /* CW10 */
/*MT6139B*/
/*MT6139B*/ const unsigned long SDATA_WARM = 0x0000402L;
/*MT6139B*/ const unsigned long SDATA_TXMODE = 0x0001002L;
                     unsigned long mode = 0x0001800;
/*MT6139B*//// const unsigned long SDATA_AMCODE = 0x008080AL;   /*temporarily*/
/*MT6139B*//// const unsigned long SDATA_ACODE   = 0x1040002L;   /*temporarily*/
/*MT6139B*//// const unsigned long SDATA_AMCODE_TABLE[5]=
/*MT6139B*//// {
/*MT6139B*////    {        0L},  /* FrequencyBand400 (not support)  */
/*MT6139B*////    {0x000042AL},  /* FrequencyBand850                */
/*MT6139B*////    {0x0000A4AL},  /* FrequencyBand900                */
/*MT6139B*////    {0x00FFFFAL},  /* FrequencyBand1800               */
/*MT6139B*////    {0x0080FFAL},  /* FrequencyBand1900               */
/*MT6139B*//// };
/*MT6139B*//// const unsigned long SDATA_ACODE_TABLE[5]=
/*MT6139B*//// {
/*MT6139B*////    {        0L},  /* FrequencyBand400 (not support)  */
/*MT6139B*////    {0x13C6002L},  /* FrequencyBand850                */
/*MT6139B*////    {0x133E002L},  /* FrequencyBand900                */
/*MT6139B*////    {0x0C36002L},  /* FrequencyBand1800               */
/*MT6139B*////    {0x0FB6002L},  /* FrequencyBand1900               */
/*MT6139B*//// };
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/ /* Serial Interface Implement                               */
/*MT6139B*/ /*..........................................................*/
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_SR1();
/*MT6139B*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139B*/	              SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139B*/	              SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_SR2( void )                  /*MJ | rxamcalmode  |   mode description       */
/*MT6139B*/ {                                                  /*MJ |      0       |   mode(110) get A code   */
/*MT6139B*/    SETUP_SR2();                                    /*MJ |      1       |   mode(011) get B&C code */
/*MT6139B*/    if(!RFSpecialCoef.rx.mt6139ip2.rxamcalmode)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_AGC,    ((l1d_rf.AGC_data & 0xFFFE3FF)|mode)|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<13) );
/*MT6139B*/    }
/*MT6139B*/    else
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<13) );
/*MT6139B*/    }
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6139B*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6139B*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) get B&C code */
/*MT6139B*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode !=0x0002 )/*MJ |      2       |   mode(011) normal mode  */
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6139B*/    }
/*MT6139B*/    else
/*MT6139B*/    {
/*MT6139B*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139B*/    }
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_ST1();
/*MT6139B*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6139B*/	                                  SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6139B*/	                                  SCTRL_RESERVED, 0                       );
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_ST2();
/*MT6139B*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139B*/ }
/*MT6139B*/
/*MT6139B*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139B*/ {
/*MT6139B*/    SETUP_ST3();
/*MT6139B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139B*/ }
/*MT6139B*/
#endif

/*---------------------------------------------------------------------------*/


#if  IS_RF_MT6139C
/*MT6139C*/
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/ /*  Define Alias and Table                                  */
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/
/*MT6139C*/
/*MT6139C*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6139C*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6139C*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6139C*/
/*MT6139C*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6139C*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6139C*/ const unsigned long CW5_RF[5]={0x0,             //450
/*MT6139C*/                                       0x00103F5,     //850   0x00101F5,  //850
/*MT6139C*/                                       0x00103F5,     //900   0x00101F5,  //900
/*MT6139C*/                                       0x00101F5,     //1800
/*MT6139C*/                                       0x00101F5 };   //1900
/*MT6139C*/ unsigned long cali_mode = 0x0001800; //mode(110) for AM calibraton
/*MT6139C*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/ /* Serial Interface Implement                               */
/*MT6139C*/ /*..........................................................*/
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_SR1();
/*MT6139C*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139C*/	              SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139C*/	              SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6139C*/ {                                                      /*MJ |        0     |   mode(110) get A code   */
/*MT6139C*/    SETUP_SR2();                                        /*MJ |        1     |   mode(011) Fix BC PM    */
/*MT6139C*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |        2     |   mode(011) normal mode  */
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_AGC,    ((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6139C*/    }
/*MT6139C*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6139C*/    }
/*MT6139C*/    else
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6139C*/    }
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6139C*/ {                                                      /*MJ |        0     |   mode(110) get A code, not return IDLE */
/*MT6139C*/    SETUP_SR3();                                        /*MJ |        1     |   mode(011) Fix BC PM, return IDLE      */
/*MT6139C*/    if( RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0 )   /*MJ |        2     |   mode(011) normal mode, return IDLE    */
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6139C*/    }
/*MT6139C*/    else
/*MT6139C*/    {
/*MT6139C*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139C*/    }
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_ST1();
/*MT6139C*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6139C*/	              SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6139C*/	              SCTRL_TXDIV_GC,  CW5_RF[l1d_rf.band]  );
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_ST2();
/*MT6139C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139C*/ }
/*MT6139C*/
/*MT6139C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139C*/ {
/*MT6139C*/    SETUP_ST3();
/*MT6139C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139C*/ }
/*MT6139C*/
void L1D_RF_SetSData_ST2B( void )
{
}

void L1D_RF_SetSData_ST2M( void )
{
}
#endif

/*---------------------------------------------------------------------------*/


#if  IS_RF_MT6139E
/*MT6139E*/
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/ /*  Define Alias and Table                                  */
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/
/*MT6139E*/
/*MT6139E*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6139E*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6139E*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6139E*/
/*MT6139E*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6139E*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6139E*/ unsigned long CW11_RF[5]={0x0000000,     //450   not support
/*MT6139E*/                           0x1B4C7FB,     //850   Low current DIV_GC=00 TXMODGAIN=000 
/*MT6139E*/                           0x1B4C7FB,     //900   Low current DIV_GC=00 TXMODGAIN=000 
/*MT6139E*/                           0x1B4E7FB,     //1800  Default DIV_GC=01 TXMODGAIN=100 
/*MT6139E*/                           0x1B4E7FB };   //1900  Default DIV_GC=01 TXMODGAIN=100
/*MT6139E*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/ /* Serial Interface Implement                               */
/*MT6139E*/ /*..........................................................*/
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR1( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_SR1();
/*MT6139E*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6139E*/	              SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6139E*/	              SCTRL_RESERVED, 0);
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR2( void )                      
/*MT6139E*/ {                                                      
/*MT6139E*/    SETUP_SR2();                                       
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|auto_cal);
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_SR3( void )                      
/*MT6139E*/ {                                                      
/*MT6139E*/    SETUP_SR3();                                        
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );    
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST1( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST1();
/*MT6139E*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6139E*/	              SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6139E*/	              SCTRL_TXDIV_GC,  CW11_RF[l1d_rf.band]  );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST2( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST2();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void  L1D_RF_SetSData_ST3( void )
/*MT6139E*/ {
/*MT6139E*/    SETUP_ST3();
/*MT6139E*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void L1D_RF_SetSData_ST2B( void )
/*MT6139E*/ {
/*MT6139E*/ }
/*MT6139E*/
/*MT6139E*/ void L1D_RF_SetSData_ST2M( void )
/*MT6139E*/ {
/*MT6139E*/ }
#endif
/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6140A
/*MT6140A*/
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/ /*  Define Alias and Table                                  */
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/
/*MT6140A*/
/*MT6140A*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140A*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140A*/ #define  SCTRL_TXDIV_GC               SCTRL_WORD(0,26) /* CW11 */
/*MT6140A*/
/*MT6140A*/ const unsigned long SDATA_WARM   = 0x0000402L;
/*MT6140A*/ const unsigned long SDATA_TXMODE = 0x0003002L;
/*MT6140A*/ const unsigned long CW11_TXDIV_GC[5]={0x0,        //450
/*MT6140A*/                                       0x3B4E7FB,  //850   0x2B4E7FB,  //850
/*MT6140A*/                                       0x3B4E7FB,  //900   0x2B4E7FB,  //900
/*MT6140A*/                                       0x1B4E7FB,  //1800
/*MT6140A*/                                       0x1B4E7FB };//1900
/*MT6140A*/ unsigned long cali_mode = 0x0001800; //mode(110) for AM calibraton
/*MT6140A*/ unsigned long auto_cal  = 0x0002000; //turn on auto calibrate
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/ /* Serial Interface Implement                               */
/*MT6140A*/ /*..........................................................*/
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_SR1();
/*MT6140A*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140A*/	              SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140A*/	              SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140A*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6140A*/    SETUP_SR2();                                        /*MJ |      1       |   mode(011) Fix BC PM    */
/*MT6140A*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_AGC,    ((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140A*/    }
/*MT6140A*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140A*/    }
/*MT6140A*/    else
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140A*/    }
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140A*/ {                                                      /*MJ |      0       |   mode(110) get A code, not return IDLE */
/*MT6140A*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) Fix BC PM, return IDLE      */
/*MT6140A*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode, return IDLE    */
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6140A*/    }
/*MT6140A*/    else
/*MT6140A*/    {
/*MT6140A*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6140A*/    }
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_ST1();
/*MT6140A*/    HWRITE_3_SDATA(SCTRL_WARM,      SDATA_WARM,
/*MT6140A*/	              SCTRL_PLL,       l1d_rf.RFN_data,
/*MT6140A*/	              SCTRL_TXDIV_GC,  CW11_TXDIV_GC[l1d_rf.band]  );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_ST2();
/*MT6140A*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140A*/ {
/*MT6140A*/    SETUP_ST3();
/*MT6140A*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6140A*/ }
/*MT6140A*/
/*MT6140A*/ void L1D_RF_SetSData_ST2B( void )
/*MT6140A*/ {
/*MT6140A*/ }
/*MT6140A*/ 
/*MT6140A*/ void L1D_RF_SetSData_ST2M( void )
/*MT6140A*/ {
/*MT6140A*/ }
#endif

/*---------------------------------------------------------------------------*/

#if  IS_RF_MT6140B
/*MT6140B*/
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/ /*  Define Alias and Table                                  */
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/
/*MT6140B*/
/*MT6140B*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140B*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140B*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140B*/
/*MT6140B*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140B*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140B*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140B*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140B*/ const unsigned long cali_mode = 0x0001800L; //mode(110) for AM calibraton
/*MT6140B*/ const unsigned long auto_cal  = 0x0002000L; //turn on auto calibrate
/*MT6140B*/ const unsigned long CW11_TXCW[5]={0x0,        //450
/*MT6140B*/                                   0x101FFFB,  //850   
/*MT6140B*/                                   0x101FFFB,  //900   
/*MT6140B*/                                   0x105DFFB,  //1800
/*MT6140B*/                                   0x105DFFB };//1900
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/ /* Serial Interface Implement                               */
/*MT6140B*/ /*..........................................................*/
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_SR1();
/*MT6140B*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140B*/	              SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140B*/	              SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140B*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6140B*/    SETUP_SR2();                                        /*MJ |      1       |   mode(011) Fix BC PM    */
/*MT6140B*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_AGC,    ((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140B*/    }
/*MT6140B*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140B*/    }
/*MT6140B*/    else
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_AGC,    l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140B*/    }
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140B*/ {                                                      /*MJ |      0       |   mode(110) get A code, not return IDLE */
/*MT6140B*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) Fix BC PM, return IDLE      */
/*MT6140B*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode, return IDLE    */
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6140B*/    }
/*MT6140B*/    else
/*MT6140B*/    {
/*MT6140B*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_IDLE );
/*MT6140B*/    }
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST1();
/*MT6140B*/    HWRITE_3_SDATA(
/*MT6140B*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140B*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140B*/                   SCTRL_TXCW,         CW11_TXCW[l1d_rf.band]);
/*MT6140B*/#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140B*/   if(l1d_rf.d2c_txiqconfig==0)
/*MT6140B*/  {
/*MT6140B*/        L1D_BFE_SetTxIQ_Config();
/*MT6140B*/  }
/*MT6140B*/#endif
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST2();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_RESERVED,   0 );
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST3();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140B*/ }
/*MT6140B*/
/*MT6140B*/ void L1D_RF_SetSData_ST2B( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST2B_ST2M();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE | (((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot ) & 0x1)<<10));
/*MT6140B*/ }
/*MT6140B*/ 
/*MT6140B*/ void L1D_RF_SetSData_ST2M( void )
/*MT6140B*/ {
/*MT6140B*/    SETUP_ST2B_ST2M();
/*MT6140B*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE | (((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot ) & 0x1)<<10));
/*MT6140B*/ }
#endif
/*---------------------------------------------------------------------------*/
#if  IS_RF_MT6140C
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/ /*  Define Alias and Table                                  */
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/
/*MT6140C*/
/*MT6140C*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140C*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140C*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140C*/
/*MT6140C*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140C*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140C*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140C*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140C*/ const unsigned long cali_mode = 0x0001800L; //mode(110) for AM calibraton
/*MT6140C*/  unsigned long auto_cal  = 0x0002000L; //turn on auto calibrate
/*MT6140C*/  unsigned  PA_DAC  = 0x0; 
/*MT6140C*//*A2*/  unsigned long TXCW[2][5]={{0x0,         //450   /* GMSK */
/*MT6140C*//*A2*/                             0x200080B,   //850   
/*MT6140C*//*A2*/                             0x200480B,   //900   
/*MT6140C*//*A2*/                             0x200000B,   //1800
/*MT6140C*//*A2*/                             0x200000B }, //1900
/*MT6140C*//*A2*/                            {0x0,         //450  /* EPSK */ 
/*MT6140C*//*A2*/                             0x200B86B,   //850   
/*MT6140C*//*A2*/                             0x200F86B,   //900   
/*MT6140C*//*A2*/                             0x200B04B,   //1800
/*MT6140C*//*A2*/                             0x200B04B }};//1900
/*MT6140C*//*A6*///  unsigned long TXCW[2][5]={{0x0,         //450   /* GMSK */
/*MT6140C*//*A6*///                             0x200000B,   //850   
/*MT6140C*//*A6*///                             0x200400B,   //900   
/*MT6140C*//*A6*///                             0x200000B,   //1800
/*MT6140C*//*A6*///                             0x200000B }, //1900
/*MT6140C*//*A6*///                            {0x0,         //450  /* EPSK */ 
/*MT6140C*//*A6*///                             0x201307B,   //1800
/*MT6140C*//*A6*///                             0x201307B }};//1900
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/ /* Serial Interface Implement                               */
/*MT6140C*/ /*..........................................................*/
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_SR1();
/*MT6140C*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140C*/	              SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140C*/	              SCTRL_AMCODE,  RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].amcode<<4|(0x000000A));
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_SR2( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140C*/ {                                                      /*MJ |      0       |   mode(110) get A code   */
/*MT6140C*/    SETUP_SR2();                                        /*MJ |      1       |   mode(011) Fix BC PM    */
/*MT6140C*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode  */
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|((l1d_rf.AGC_data&0xFFFE3FF)|cali_mode)|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/    else if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 1)
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/    else
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_SR3( void )                      /*MJ | rxamcalmode  |   mode description       */
/*MT6140C*/ {                                                      /*MJ |      0       |   mode(110) get A code, not return IDLE */
/*MT6140C*/    SETUP_SR3();                                        /*MJ |      1       |   mode(011) Fix BC PM, return IDLE      */
/*MT6140C*/    if(RFSpecialCoef.rx.mt6139ip2.rxamcalmode == 0)     /*MJ |      2       |   mode(011) normal mode, return IDLE    */
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_RESERVED, 0 );
/*MT6140C*/    }
/*MT6140C*/    else
/*MT6140C*/    {
/*MT6140C*/       HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP|l1d_rf.AGC_data|auto_cal|(RFSpecialCoef.rx.mt6139ip2.data[l1d_rf.band].acode<<14) );
/*MT6140C*/    }
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST1();
/*MT6140C*/    HWRITE_3_SDATA(
/*MT6140C*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140C*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140C*/                   SCTRL_RESERVED,         0);
/*MT6140C*/
/*MT6140C*/#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140C*/   if(l1d_rf.d2c_txiqconfig==0)
/*MT6140C*/  {
/*MT6140C*/        L1D_BFE_SetTxIQ_Config();
/*MT6140C*/  }
/*MT6140C*/#endif
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST2();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST3();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140C*/ }
/*MT6140C*/
/*MT6140C*/ void L1D_RF_SetSData_ST2B( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST2B_ST2M();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   TXCW[((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)][l1d_rf.band]|(PA_DAC<<8));
/*MT6140C*/ }
/*MT6140C*/ 
/*MT6140C*/ void L1D_RF_SetSData_ST2M( void )
/*MT6140C*/ {
/*MT6140C*/    SETUP_ST2B_ST2M();
/*MT6140C*/    HWRITE_1_SDATA( SCTRL_TXBAND,   TXCW[((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)][l1d_rf.band]|(PA_DAC<<8));
/*MT6140C*/ }
#endif
/*---------------------------------------------------------------------------*/
#if  IS_RF_MT6140D
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/ /*  Define Alias and Table                                  */
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/
/*MT6140D*/
/*MT6140D*/ #define  SCTRL_STANDBY                SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_WARM                   SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_PLL                    SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_AGC                    SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_TXBAND                 SCTRL_WORD(0,26)
/*MT6140D*/ #define  SCTRL_AMCODE                 SCTRL_WORD(0,26) /* CW10 */
/*MT6140D*/ #define  SCTRL_TXCW                   SCTRL_WORD(0,26) /* CW11 */
/*MT6140D*/
/*MT6140D*/ const unsigned long SDATA_SLEEP   = 0x0000002L; // Sleep mode
/*MT6140D*/ const unsigned long SDATA_WARM    = 0x20827E2L; // Warm up mode
/*MT6140D*/ const unsigned long SDATA_TXMODE  = 0x0003002L; // GMSK 0x0003002L;
/*MT6140D*/ const unsigned long SDATA_RXMODE  = 0x0000C02L; // RX mode
/*MT6140D*/ unsigned long auto_cal  = 0x0002000L; //turn on auto calibrate
/*MT6140D*/ unsigned short LB_CW_High_Idx  = (19-12);  //PCL12 =Idx(19-12)
/*MT6140D*/ unsigned short HB_CW_High_Idx  = (15- 6);  //PCL 6 =Idx(15- 6)
/*MT6140D*/ const unsigned long  TXCW[2][2][5]=
/*MT6140D*/{
/*MT6140D*/ {              // High PCL
/*MT6140D*/  {0x0,         //450  /* GMSK */
/*MT6140D*/   0x20A480B,   //850   
/*MT6140D*/   0x21A480B,   //900   
/*MT6140D*/   0x202400B,   //1800
/*MT6140D*/   0x202400B }, //1900
/*MT6140D*/  {0x0,	       //450  /* EPSK */ 
/*MT6140D*/   0x200F89B,   //850   
/*MT6140D*/   0x208F89B,   //900   
/*MT6140D*/   0x200F07B,   //1800
/*MT6140D*/   0x200F07B }, //1900     
/*MT6140D*/ },
/*MT6140D*/ {              // Low PCL
/*MT6140D*/  {0x0,         //450  /* GMSK */
/*MT6140D*/   0x20A480B,   //850   
/*MT6140D*/   0x21A480B,   //900   
/*MT6140D*/   0x202400B,   //1800
/*MT6140D*/   0x202400B }, //1900
/*MT6140D*/  {0x0,         //450  /* EPSK */ 
/*MT6140D*/   0x214F89B,   //850   
/*MT6140D*/   0x21CF89B,   //900   
/*MT6140D*/   0x201E07B,   //1800
/*MT6140D*/   0x201E07B }, //1900
/*MT6140D*/ },
/*MT6140D*/};
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/ /* Serial Interface Implement                               */
/*MT6140D*/ /*..........................................................*/
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR1( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_SR1();
/*MT6140D*/    HWRITE_3_SDATA(SCTRL_WARM,    SDATA_WARM,
/*MT6140D*/	                  SCTRL_PLL,     l1d_rf.RFN_data,
/*MT6140D*/	                  SCTRL_RESERVED, 0 );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR2( void )                      
/*MT6140D*/ {                                                      
/*MT6140D*/    SETUP_SR2();                                        
/*MT6140D*/    
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_AGC,    SDATA_RXMODE|l1d_rf.AGC_data|auto_cal);
/*MT6140D*/    
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_SR3( void )                     
/*MT6140D*/ {                                                     
/*MT6140D*/    SETUP_SR3();                                       
/*MT6140D*/   
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP);
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST1( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST1();
/*MT6140D*/    HWRITE_3_SDATA(
/*MT6140D*/                   SCTRL_WARM,         SDATA_WARM,
/*MT6140D*/                   SCTRL_PLL,          l1d_rf.RFN_data,
/*MT6140D*/                   SCTRL_RESERVED,         0);
/*MT6140D*/
/*MT6140D*/#if  IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/   if(l1d_rf.d2c_txiqconfig==0)
/*MT6140D*/  {
/*MT6140D*/        L1D_BFE_SetTxIQ_Config();
/*MT6140D*/  }
/*MT6140D*/#endif
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST2( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_TXBAND,   SDATA_TXMODE );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ void  L1D_RF_SetSData_ST3( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST3();
/*MT6140D*/    HWRITE_1_SDATA( SCTRL_IDLE, SDATA_SLEEP );
/*MT6140D*/ }
/*MT6140D*/
/*MT6140D*/ #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*/ void L1D_RF_SetSData_ST2B( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2B_ST2M();
/*MT6140D*/    {
/*MT6140D*/ #if defined(__EPSK_TX__)
/*MT6140D*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*MT6140D*/       {
/*MT6140D*/ 	  unsigned short   cw_idx;
/*MT6140D*/          cw_idx=L1D_RF_GetTxPAVBias_TxITC(LB_CW_High_Idx, HB_CW_High_Idx);
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND,	TXCW[(cw_idx>>4)&0x1][1][l1d_rf.band]|((cw_idx&0x7)<<8));
/*MT6140D*/       }       
/*MT6140D*/       else 
/*MT6140D*/ #endif	
/*MT6140D*/       {        
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND,	TXCW[0][0][l1d_rf.band]);
/*MT6140D*/       }
/*MT6140D*/    }  
/*MT6140D*/ }
/*MT6140D*/ void L1D_RF_SetSData_ST2M( void )
/*MT6140D*/ {
/*MT6140D*/    SETUP_ST2B_ST2M();
/*MT6140D*/    {
/*MT6140D*/ #if defined(__EPSK_TX__)
/*MT6140D*/       if((l1d_rf.tx_mod_type2>>l1d_rf.cur_slot)&0x1)
/*MT6140D*/       {       
/*MT6140D*/ 	  unsigned short   cw_idx;
/*MT6140D*/          cw_idx=L1D_RF_GetTxPAVBias_TxITC(LB_CW_High_Idx, HB_CW_High_Idx);
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND,	TXCW[(cw_idx>>4)&0x1][1][l1d_rf.band]|((cw_idx&0x7)<<8));
/*MT6140D*/       }       
/*MT6140D*/       else 
/*MT6140D*/ #endif	
/*MT6140D*/       {        
/*MT6140D*/          HWRITE_1_SDATA( SCTRL_TXBAND,	TXCW[0][0][l1d_rf.band]);
/*MT6140D*/       }
/*MT6140D*/    }  
/*MT6140D*/ }
/*MT6140D*/ #endif
#endif
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
#if  IS_RF_SKY74045
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
/*SKY74045*/    #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/    #else
/* under construction !*/
/* under construction !*/
/*SKY74045*/    #endif
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
/*SKY74045*/    #if IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*SKY74045*/    #else
/* under construction !*/
/* under construction !*/
/*SKY74045*/    #endif
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
#endif
/*---------------------------------------------------------------------------*/
#if  IS_RF_AERO2
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
#endif

/*---------------------------------------------------------------------------*/
#if  IS_RF_SKY74137
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
#endif
/*---------------------------------------------------------------------------*/

#if IS_RF_GRF6201
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
#endif
/*---------------------------------------------------------------------------*/
#if  IS_RF_IRFS3001
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*---------------------------------------------------------------------------*/
