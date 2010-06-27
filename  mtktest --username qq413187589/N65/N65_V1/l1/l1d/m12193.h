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
 * m12193.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   AFC DAC and RX ADC configuration
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *******************************************************************************/

#ifndef  _M12193_H_
#define  _M12193_H_

#include "l1d_cid.h"
/* Parameter read from Flash or EEPROM */

/*  Bit width of AFC DAC:                           */
/*                     Default     Option           */
/*  1)MT6208,FPGA      10-bit      13-bit           */
/*  2)MT6205           13-bit        X              */

//#define AFC_13bit     /* used to turn on 13-bit AFC DAC for MT6208 or FPGA */
//#define RX_ADC_14bit
#ifdef __MTK_TARGET__
   #if  (!defined(FPGA))&&(!defined(MT6208))
   /*MT6205~*/ #ifndef  AFC_13bit
   /*MT6205~*/ #define  AFC_13bit
   /*MT6205~*/ #endif
   #endif
#endif

#ifdef AFC_13bit
   /* Due to 13bits DAC */
   #define  PSI_EE               (4100)             /* DAC initial value */
   #define  AFC_DP_MIN           (0)
   #define  AFC_DP_MAX           (8191)
#else
   /* Due to 10bits DAC */
   #define  PSI_EE               (517)             /* DAC initial value */
   #define  AFC_DP_MIN           (0)
   #define  AFC_DP_MAX           (1023)
#endif

#if IS_RF_BRIGHT2
/*BRIGHT2*/ #ifdef AFC_13bit
/* under construction !*/
/*BRIGHT2*/ #else
/* under construction !*/
/*BRIGHT2*/ #endif
/* under construction !*/
/*BRIGHT2*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*BRIGHT2*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*BRIGHT2*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*BRIGHT2*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_BRIGHT4
/*BRIGHT4*/ #ifdef AFC_13bit
/* under construction !*/
/*BRIGHT4*/ #else
/* under construction !*/
/*BRIGHT4*/ #endif
/*BRIGHT4*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT4*/ #endif
#endif

#if IS_RF_BRIGHT5P
/*BRIGHT5P*/ #ifdef AFC_13bit
/* under construction !*/
/*BRIGHT5P*/ #else
/* under construction !*/
/*BRIGHT5P*/ #endif
/*BRIGHT5P*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT5P*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT5P*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*BRIGHT5P*/ #endif
#endif

#if IS_RF_AERO
/*AERO*/ #ifdef AFC_13bit
/* under construction !*/
/*AERO*/ #else
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/*AERO*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*AERO*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*AERO*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*AERO*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_AERO1PLUS
/*AERO1+*/ #ifdef AFC_13bit
/* under construction !*/
/*AERO1+*/ #else
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/*AERO1+*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*AERO1+*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*AERO1+*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*AERO1+*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#if IS_RF_POLARIS1    /*The value is temporary used*/
/*RFMD*/ #ifdef AFC_13bit
/* under construction !*/
/*RFMD*/ #else
/* under construction !*/
/*RFMD*/ #endif
/* under construction !*/
/*RFMD*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*RFMD*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*RFMD*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*RFMD*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_SKY74117
/*SKY74117*/ #ifdef AFC_13bit
/* under construction !*/
/*SKY74117*/ #else
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/*SKY74117*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*SKY74117*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*SKY74117*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*SKY74117*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_SKY74400
/*SKY74400*/ #ifdef AFC_13bit
/* under construction !*/
/*SKY74400*/ #else
/* under construction !*/
/*SKY74400*/ #endif
/* under construction !*/
/*SKY74400*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*SKY74400*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*SKY74400*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*SKY74400*/ #endif
/* under construction !*/
/* under construction !*/
#endif


#if (IS_RF_MT6119)||(IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)
/*MT6119/C,MT6129A/B/C/D*/ #ifdef AFC_13bit
/*MT6119/C,MT6129A/B/C/D*/    #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6119/C,MT6129A/B/C/D*/ #else
/*MT6119/C,MT6129A/B/C/D*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6119/C,MT6129A/B/C/D*/ #endif
/*MT6119/C,MT6129A/B/C/D*/
/*MT6119/C,MT6129A/B/C/D*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION   /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6119/C,MT6129A/B/C/D*//*MT6218B~*/ #define  DSP_SETPOINT  (56)
/*MT6119/C,MT6129A/B/C/D*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION           /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6119/C,MT6129A/B/C/D*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6119/C,MT6129A/B/C/D*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6119/C,MT6129A/B/C/D*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6119/C,MT6129A/B/C/D*/ #endif
/*MT6119/C,MT6129A/B/C/D*//* Note that setpoint and edge_setpoint cannot be nonzero simulataneously */
/*MT6119/C,MT6129A/B/C/D*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6119/C,MT6129A/B/C/D*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6139B /*The value is temporary used*/
/*MT6139B*/ #ifdef AFC_13bit
/*MT6139B*/    #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6139B*/ #else
/*MT6139B*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6139B*/ #endif
/*MT6139B*/
/*MT6139B*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6139B*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6139B*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6139B*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6139B*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6139B*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6139B*/ #endif
/*MT6139B*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6139B*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif  

#if IS_RF_MT6139C || IS_RF_MT6140A /*The value is temporary used*/
/*MT6139C*/ #ifdef AFC_13bit
/*MT6139C*/    #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6139C*/ #else
/*MT6139C*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6139C*/ #endif
/*MT6139C*/
/*MT6139C*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6139C*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6139C*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6139C*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6139C*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6139C*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6139C*/ #endif
/*MT6139C*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6139C*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif


#if IS_RF_MT6139E
/*MT6139E*/ #ifdef AFC_13bit
/*MT6139E*/    #define  C_PSI_STA      (630)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=7    */
/*MT6139E*/ #else
/*MT6139E*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ #if    IS_CHIP_MT6225_AND_LATTER_VERSION||IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*//*MT6225~*/  #define  DSP_SETPOINT  (51)
/*MT6139E*/ #elif  IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6139E*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*MT6139E*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6139E*//*MT6218A*/  #define  DSP_SETPOINT  (51)
/*MT6139E*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6139E*//*OTHERS*/   #define  DSP_SETPOINT  (40)
/*MT6139E*/ #endif
/*MT6139E*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6139E*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6140A /*The value is temporary used*/
/*MT6140A*/ #ifdef AFC_13bit
/*MT6140A*/    #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6140A*/ #else
/*MT6140A*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140A*/ #endif
/*MT6140A*/
/*MT6140A*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140A*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6140A*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140A*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6140A*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140A*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6140A*/ #endif
/*MT6140A*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140A*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6140B /*The value is temporary used*/
/*MT6140B*/ #ifdef AFC_13bit
/*MT6140B*/    #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6140B*/ #else
/*MT6140B*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140B*/ #endif
/*MT6140B*/
/*MT6140B*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140B*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6140B*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140B*//*MT6218A*/  #define  DSP_SETPOINT  (58)
/*MT6140B*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140B*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6140B*/ #endif
/*MT6140B*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140B*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_MT6140C /*The value is temporary used*/
/*MT6140C*/ #ifdef AFC_13bit
/*MT6140C*/    #define  C_PSI_STA     (1280)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=3.2  */
/*MT6140C*/ #else
/*MT6140C*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140C*/ #endif
/*MT6140C*/
/*MT6140C*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140C*//*MT6218B~*/ #define  DSP_SETPOINT  (42)
/*MT6140C*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION                     /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140C*//*MT6218A*/  #define  DSP_SETPOINT  (45)
/*MT6140C*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140C*//*OTHERS*/   #define  DSP_SETPOINT  (42)
/*MT6140C*/ #endif
/*MT6140C*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140C*/ #define  EDGE_SETPOINT_GAIN_OFFSET 5
#endif

#if IS_RF_MT6140D /*The value is temporary used*/
/*MT6140D*/ #ifdef AFC_13bit
/*MT6140D*/    #define  C_PSI_STA     (585)  /* C_PSI_STA= sta^(-1)  * (2^12), sta=7    */
/*MT6140D*/ #else
/*MT6140D*/    #define  C_PSI_STA     (146)   /* C_PSI_STA= sta^(-1)  * (2^12), sta=28.05  */
/*MT6140D*/ #endif
/*MT6140D*/
/*MT6140D*/ #if    IS_CHIP_MT6238
/*MT6140D*//*MT6238~*/  #define  DSP_SETPOINT  (48)
/*MT6140D*/ #elif  IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6140D*//*MT6225~*/  #define  DSP_SETPOINT  (51)
/*MT6140D*/ #elif    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/*MT6140D*//*MT6218B~*/ #define  DSP_SETPOINT  (49)
/*MT6140D*/ #elif  IS_CHIP_MT6218A                      /* single-end peak2peak:  1.12V <-> 6912 */
/*MT6140D*//*MT6218A*/  #define  DSP_SETPOINT  (51)
/*MT6140D*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/*MT6140D*//*OTHERS*/   #define  DSP_SETPOINT  (40)
/*MT6140D*/ #endif
/*MT6140D*/ #define  SETPOINT_GAIN_OFFSET 0
/*MT6140D*/ #define  EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#if IS_RF_SKY74045    /*The value is temporary used*/
/*SKY74045*/ #ifdef AFC_13bit
/* under construction !*/
/*SKY74045*/ #else
/* under construction !*/
/*SKY74045*/ #endif
/* under construction !*/
/*SKY74045*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION/* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*SKY74045*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*SKY74045*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*SKY74045*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#if IS_RF_AERO2
/*AERO2*/ #ifdef AFC_13bit
/* under construction !*/
/*AERO2*/ #else
/* under construction !*/
/*AERO2*/ #endif
/* under construction !*/
/*AERO2*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*AERO2*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*AERO2*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*AERO2*/ #endif
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_SKY74137
/*SKY74137*/ #ifdef AFC_13bit
/* under construction !*/
/*SKY74137*/ #else
/* under construction !*/
/*SKY74137*/ #endif
/* under construction !*/
/*SKY74137*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION/* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*SKY74137*/ #elif  IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*SKY74137*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*SKY74137*/ #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_GRF6201
/*GRF6201*/ #ifdef AFC_13bit
/* under construction !*/
/*GRF6201*/ #else
/* under construction !*/
/*GRF6201*/ #endif
/* under construction !*/
/*GRF6201*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*GRF6201*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*GRF6201*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*GRF6201*/ #endif
/* under construction !*/
/* under construction !*/
#endif

#if IS_RF_IRFS3001
/*IRFS3001*/ #ifdef AFC_13bit
/* under construction !*/
/*IRFS3001*/ #else
/* under construction !*/
/*IRFS3001*/ #endif
/* under construction !*/
/*IRFS3001*/ #if    IS_CHIP_MT6218B_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION  /* single-end peak2peak:  1.12V <-> 5184 */
/* under construction !*/
/*IRFS3001*/ #elif  IS_CHIP_MT6218A                     /* single-end peak2peak:  1.12V <-> 6912 */
/* under construction !*/
/*IRFS3001*/ #else                                      /* single-end peak2peak:  1.25V <-> 1024 */
/* under construction !*/
/*IRFS3001*/ #endif
/* under construction !*/
/* under construction !*/
#endif

#ifndef GPRS_SETPOINT_GAIN_OFFSET
#define GPRS_SETPOINT_GAIN_OFFSET 0
#endif

#ifndef EDGE_SETPOINT_GAIN_OFFSET
#define EDGE_SETPOINT_GAIN_OFFSET 0
#endif

#endif







































