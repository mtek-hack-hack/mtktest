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
 *	m12194.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *
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
#include "m12190.h"
#include "m12193.h"
#include "l1d_custom_rf.h"
#include "l1d_rf.h"

/*---------------------------------------------------------------------*/
/* remind: this is the type definition copy from another header file.  */
/*         If the type definition is changed in the original file,     */
/*         these copy shall be updated !!!                             */
/*---------------------------------------------------------------------*/
#ifndef  l1_generic_l1_const_h
   #define RSSI_RESOLUTION_BITS     3 /* 0.125 dB resolution */
   #define RSSI_FACTOR              (1<<RSSI_RESOLUTION_BITS)
#endif
#ifndef _MPH_TYPES_H
   typedef  short  Power;
#endif
#ifndef l1_generic_l1_types_h
   typedef  signed short int  int16;
   typedef  signed int   intx;
   typedef  short  Gain;
   typedef struct
   {
      Power defaultPower;
      Power bestPower;
      Power underflowPower;
      Power overflowPower;
      Gain  underflowReportPower;
      Gain  overflowReportPower;
   } AGCParams;
#endif
/*---------------------------------------------------------------------*/

#if (IS_FPGA_TARGET||IS_CHIP_MT6208)
#define RXADC_NoiseFlow          8
#define RXADC_Saturation         3
#define RXADC_MAX_DBd            60
#endif

#if IS_CHIP_MT6205A
#define RXADC_NoiseFlow          8
#define RXADC_Saturation         0
#define RXADC_MAX_DBd            60
#endif

#if IS_CHIP_MT6205B
   #if (IS_RF_BRIGHT2)||(IS_RF_BRIGHT4)||(IS_RF_AERO)||(IS_RF_AERO1PLUS)||(IS_RF_AERO2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   #if (IS_RF_MT6116)||(IS_RF_MT6119)||(IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         3
      #define RXADC_MAX_DBd            60
   #endif

   #if (IS_RF_POLARIS1)   /* RFMD: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74117)   /* SKY74117: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74400)   /* SKY74400: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6139B)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6139C)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            74
   #endif 
   #if (IS_RF_MT6139E)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            60
   #endif 
   #if (IS_RF_SKY74045)   /* SKY74045: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74137)   /* SKY74137: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_GRF6201)   /* temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
   #if (IS_RF_MT6140C)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            60
   #endif   
   #if (IS_RF_MT6140D)   /* temporary parameter, not verify*/
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            60
   #endif     
#endif

#if IS_EDGE_SAIC_CHIP_MT6238_AND_LATTER_VERSION
/*MT6238*/   #if (IS_RF_MT6140D)   
/*MT6238*/      #define RXADC_NoiseFlow          13
/*MT6238*/      #define RXADC_Saturation          3
/*MT6238*/      #define RXADC_MAX_DBd            76
/*MT6238*/   #endif   
/*MT6238*/   #if (IS_RF_MT6139E)   
/*MT6238*/      #define RXADC_NoiseFlow          15
/*MT6238*/      #define RXADC_Saturation          0   /* measured with MT6223*/
/*MT6238*/      #define RXADC_MAX_DBd            76  /* measured with MT6223*/
/*MT6238*/   #endif
/*MT6238*/   #if (IS_RF_AERO2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6238*/   #endif 
/*MT6238*/   #if (IS_RF_SKY74137)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/*MT6238*/   #endif 
#elif IS_CHIP_MT6218A || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
   #if (IS_RF_BRIGHT2)||(IS_RF_BRIGHT4)||(IS_RF_AERO)||(IS_RF_AERO1PLUS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6116)||(IS_RF_MT6119)||(IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)
      #define RXADC_NoiseFlow          31
      #define RXADC_Saturation         3
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_POLARIS1)   /* RFMD: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74117)   /* SKY74117: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74400)   /* SKY74400: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6139B)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140A)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140B)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140C)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140D)   
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            76
   #endif   
   #if (IS_RF_MT6139C)   
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            76
   #endif        
   #if (IS_RF_MT6139E)   
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0   /* measured with MT6223*/
      #define RXADC_MAX_DBd            76  /* measured with MT6223*/
   #endif
   #if (IS_RF_SKY74045)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_AERO2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
   #if (IS_RF_SKY74137)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
   #if (IS_RF_GRF6201)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
#endif

#if IS_CHIP_MT6225_AND_LATTER_VERSION
   #if (IS_RF_BRIGHT2)||(IS_RF_BRIGHT4)||(IS_RF_AERO)||(IS_RF_AERO1PLUS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6116)||(IS_RF_MT6119)||(IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)
      #define RXADC_NoiseFlow          29
      #define RXADC_Saturation         3
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_POLARIS1)   /* RFMD: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74117)   /* SKY74117: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74400)   /* SKY74400: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6139B)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6139C)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6139E)   
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140A)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140B)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140C)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_MT6140D)   
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            76
   #endif
   #if (IS_RF_SKY74045)   /* SKY74045: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
    #if (IS_RF_BRIGHT5P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_AERO2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
   #if (IS_RF_SKY74137)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_GRF6201)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
#elif IS_CHIP_MT6218B_AND_LATTER_VERSION
   #if (IS_RF_BRIGHT2)||(IS_RF_BRIGHT4)||(IS_RF_AERO)||(IS_RF_AERO1PLUS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6116)||(IS_RF_MT6119)||(IS_RF_MT6119C)||(IS_RF_MT6129A)||(IS_RF_MT6129B)||(IS_RF_MT6129C)||(IS_RF_MT6129D)
      #define RXADC_NoiseFlow          29
      #define RXADC_Saturation         3
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_POLARIS1)   /* RFMD: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74117)   /* SKY74117: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_SKY74400)   /* SKY74400: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_MT6139B)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6139C)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6139E)   
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation          0
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6140A)   /* temporary parameter */
      #define RXADC_NoiseFlow          0
      #define RXADC_Saturation         0
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6140B)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6140C)   /* */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            74
   #endif
   #if (IS_RF_MT6140D)   /* temporary parameter */
      #define RXADC_NoiseFlow          15
      #define RXADC_Saturation         5
      #define RXADC_MAX_DBd            74
   #endif   
   #if (IS_RF_SKY74045)   /* SKY74045: temporary parameter */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
    #if (IS_RF_BRIGHT5P)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_AERO2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
   #if (IS_RF_SKY74137)
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_GRF6201)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
   #if (IS_RF_IRFS3001)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

#endif

#define PM_MAGIC_VALUE           ( DSP_MAGIC_VALUE * RSSI_FACTOR)
#define PM_SETPOINT              ( PM_MAGIC_VALUE + DSP_SETPOINT * RSSI_FACTOR )
#define PM_UnderFlow             ( PM_MAGIC_VALUE + RXADC_NoiseFlow * RSSI_FACTOR )
#define PM_OverFlow              ( PM_MAGIC_VALUE + (RXADC_MAX_DBd-RXADC_Saturation) * RSSI_FACTOR )
#define PM_UnderFlowReport       ( PM_UnderFlow - PM_OverFlow + PM_SETPOINT )
#define PM_OverFlowReport        ( PM_OverFlow + PM_SETPOINT - PM_UnderFlow )

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif /* __MTK_TARGET__ */

const AGCParams agcParams[ FrequencyBandCount ] =
{/*          default,            best,        under,        over,  underReport,   overReport */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand400  */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand850  */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand900  */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand1800 */
   { -76*RSSI_FACTOR, PM_SETPOINT, PM_UnderFlow, PM_OverFlow, PM_UnderFlowReport, PM_OverFlowReport }, /* FrequencyBand1900 */
};

#if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION 
   const unsigned short  RXADC_NoiseFlow_mul_64 = RXADC_NoiseFlow * 64;  /* Noise floor(dBd)*64 */
#endif

intx afc_inv_slope = C_PSI_STA;
int16 afc_dac_default = PSI_EE;
int16 onek_hz_dac = (int16)((1200*C_PSI_STA)/0x1000);

Power agc_gainoffset_h2l = SETPOINT_GAIN_OFFSET * RSSI_FACTOR;
Power agc_gprs_gainoffset = GPRS_SETPOINT_GAIN_OFFSET * RSSI_FACTOR; 
#if IS_EGPRS
Power agc_edge_gainoffset = EDGE_SETPOINT_GAIN_OFFSET * RSSI_FACTOR; 
#endif


#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */

void L1I_SetAFcData(int16 calibrated_dac_default, intx calibrated_int_slope)
{
   afc_dac_default = calibrated_dac_default;
   afc_inv_slope   = calibrated_int_slope;   
   onek_hz_dac     = (int16)((1200*calibrated_int_slope)/0x1000); 
}
/*---------------------------------------------------------------------------*/


