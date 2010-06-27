/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	l1d_custom_rf.h
 *
 *
 *******************************************************************************/

/****************
***
***  所有关于 RFPA 的宏定义 已经放到文件 UNIRISE25_GEMINI_GPRS.mak 上边。
***  NOKE_RFPA_MODULE = RF7168
***  更改RF7168 为你自己的型号
***
**************************/

/*MT6139E*/ /*MT6205*/ //#define TQM6M4003  //king 0618 for EV5210
/*MT6139E*/ /*MT6205*/ //#define TQM6M4038  //king 0618 for EV5210

#ifndef  _L1D_CUSTOM_RF_H_
#define  _L1D_CUSTOM_RF_H_
/* ------------------------------------------------------------------------- */
#if !defined(MT6139E_RF)
   #error "rf files mismatch with compile option!"
#endif

/*MT6139E*/
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*   Event Timing Define                                  */
/*MT6139E*/ /*--------------------------------------------------------*/
/*MT6139E*/
/*MT6139E*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*/ /*MT6225~*/ #define  QB_RX_FENA_2_FSYNC          48   /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6225~*/ #define  QB_RX_FSYNC_2_FENA          0
/*MT6139E*/ /*MT6225~*/ #define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6225~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6139E*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6139E*/ /*MT6218~*/ #define  QB_RX_FENA_2_FSYNC          40   /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6218~*/ #define  QB_RX_FSYNC_2_FENA          0
/*MT6139E*/ /*MT6218~*/ #define  QB_TX_FENA_2_FSYNC          152  /* this value shall be 4N+0 */
/*MT6139E*/ /*MT6218~*/ #define  QB_TX_FSYNC_2_FENA          30
/*MT6139E*/ #else
/*MT6139E*/ /*OTHERS*/ #define  QB_RX_FENA_2_FSYNC           35   /* this value shall be 4N+3 */
/*MT6139E*/ /*OTHERS*/ #define  QB_RX_FSYNC_2_FENA           0
/*MT6139E*/ /*OTHERS*/ #define  QB_TX_FENA_2_FSYNC           149  /* this value shall be 4N+1 */
/*MT6139E*/ /*OTHERS*/ #define  QB_TX_FSYNC_2_FENA           30
/*MT6139E*/ #endif
/*MT6139E*/                                           /*           |--(N:SR3 data number)                     */
/*MT6139E*/ #define  QB_SR1                      212  /* Let the 6*N + 4(QB) distance exist between SR1 & SR3 */
/*MT6139E*/ #define  QB_SR2                      65
/*MT6139E*/ #define  QB_SR2M                     44
/*MT6139E*/ #define  QB_SR3                      0
/*MT6139E*/ #define  QB_PR1                      243
/*MT6139E*/ #define  QB_PR2                      25
/*MT6139E*/ #define  QB_PR3                      6
/*MT6139E*/ #define  QB_ST1                      304
/*MT6139E*/ #define  QB_ST2                      140
/*MT6139E*/ #define  QB_ST3                      23
/*MT6139E*/ #define  QB_PT2B                     335 
/*MT6139E*/ #define  QB_PT1                      136
/*MT6139E*/ #define  QB_PT2                      4/*8*/	
/*MT6139E*/ #define  QB_PT3                      25
/*MT6139E*/ #if IS_CHIP_MT6225_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
/*MT6139E*/ #define  QB_APCON                    17
/*MT6139E*/ #define  QB_APCMID                   22
/*MT6139E*/ #define  QB_APCOFF                   9
/*MT6139E*/ #else
/*MT6139E*/ #define  QB_APCON                    21
/*MT6139E*/ #define  QB_APCMID                   26
/*MT6139E*/ #define  QB_APCOFF                   5
/*MT6139E*/ #endif
/*MT6139E*/ #define  QB_APCDACON                 99
/*MT6139E*/
/*MT6139E*/ #if IS_SAIC_CHIP_MT6223_AND_LATTER_VERSION
/*MT6139E*//*MT6223~*/ #define  TX_PROPAGATION_DELAY         43
/*MT6139E*/ #elif IS_CHIP_MT6225_AND_LATTER_VERSION||IS_CHIP_MT6229||IS_CHIP_MT6268T
/*MT6139E*//*MT6225~*/ #define  TX_PROPAGATION_DELAY         45
/*MT6139E*/ #elif  IS_CHIP_MT6218_AND_LATTER_VERSION
/*MT6139E*//*MT6218~*/ #define  TX_PROPAGATION_DELAY         37
/*MT6139E*/ #else
/*MT6139E*//*OTHERS*/  #define  TX_PROPAGATION_DELAY         36
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ #if  IS_CHIP_MT6208
/*MT6139E*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6208*/ /*   define  BPI data (shall be modified by real case)    */
/*MT6139E*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6208*/ /*    PRCB : bit   pin                                    */
/*MT6139E*/ /*MT6208*/ /*            0    HB_TX                                  */
/*MT6139E*/ /*MT6208*/ /*            1   *PCS_CTRL                               */
/*MT6139E*/ /*MT6208*/ /*            2    TX_EN                                  */
/*MT6139E*/ /*MT6208*/ /*            3   *GSM_BANDSW*                            */
/*MT6139E*/ /*MT6208*/ /*            4    LB_TX                                  */
/*MT6139E*/ /*MT6208*/ /*            5    DCS_BANDSW*                            */
/*MT6139E*/ /*MT6208*/ /*            6    PCS_RCTRL                              */
/*MT6139E*/ /*MT6208*/ /*            7    not used                               */
/*MT6139E*/ /*MT6208*/ /*--------------------------------------------------------*/
/*MT6139E*/ /*MT6208*/
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PR1  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PR2  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PR3  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PT1  0x08
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PT2  0x1C
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM850_PT3  0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PR1     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PR2     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PR3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PT1     0x08
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PT2     0x1C
/*MT6139E*/ /*MT6208*/ #define  PDATA_GSM_PT3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PR1     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PR2     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PR3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PT1     0x20
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PT2     0x25
/*MT6139E*/ /*MT6208*/ #define  PDATA_DCS_PT3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PR1     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PR2     0x40
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PR3     0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PT1     0x60
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PT2     0x25
/*MT6139E*/ /*MT6208*/ #define  PDATA_PCS_PT3     0x00
/*MT6139E*/ /*MT6208*/
/*MT6139E*/ /*MT6208*/ #define  PDATA_INIT        0x00
/*MT6139E*/ /*MT6208*/ #define  PDATA_IDLE        0x00
/*MT6139E*/ #endif
/*MT6139E*/

                                                
/*MT6139E*/ #if  IS_CHIP_MT6218_AND_LATTER_VERSION || IS_EDGE_CHIP_MT6229_AND_LATTER_VERSION
				#ifdef  TQM6M4003
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*   define  BPI data for FOUNTAIN2 (shall be modified by real case)    */
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*    PRCB : bit   pin                                    	*/
/*MT6129D*/ /*MT6205*/ /*            0    TQM6M4003 VBS1                       		*/
/*MT6129D*/ /*MT6205*/ /*            1    TQM6M4003 VBS2                       		*/
/*MT6129D*/ /*MT6205*/ /*            2    not used                              	*/
/*MT6129D*/ /*MT6205*/ /*            3    not used                            		*/
/*MT6129D*/ /*MT6205*/ /*            4    TQM6M4003 VTX                         	*/
/*MT6129D*/ /*MT6205*/ /*            5    not used                              	*/
/*MT6129D*/ /*MT6205*/ /*            6    not used                               	*/
/*MT6129D*/ /*MT6205*/ /*            7    not used                               	*/
/*MT6129D*/ /*MT6205*/ /*            9    VCO Enable                             	*/
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------	*/
/*MT6129D*/ /*MT6205*/
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR1  0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR2  0x203
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR3  0x000
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT1  0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT2  0x210
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT3  0x000
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR1     0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR2     0x200 
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR3     0x000
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT1     0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT2     0x210 
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT3     0x000

/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR1     0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR2     0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR3     0x000
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT1     0x200 
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT2     0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT3     0x000

/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR1     0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR2     0x202
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR3     0x000
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT1     0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT2     0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT3     0x000
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_INIT        0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_IDLE        0x00
/*MT6129D*/ /*MT6205*/ #endif   // #ifdef  TQM6M4003
/*MT6129D*/ /*MT6205*/ #ifdef  TQM6M4038
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*   define  BPI data for FOUNTAIN2 (shall be modified by real case)    */
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*    PRCB : bit   pin                                    	*/
/*MT6129D*/ /*MT6205*/ /*            0    TQM6M4003 VMODE                      		*/
/*MT6129D*/ /*MT6205*/ /*            1    TQM6M4003 VTX                       		*/
/*MT6129D*/ /*MT6205*/ /*            2    not used                              	*/
/*MT6129D*/ /*MT6205*/ /*            3    not used                            		*/
/*MT6129D*/ /*MT6205*/ /*            4    TQM6M4003 VBS                         	*/
/*MT6129D*/ /*MT6205*/ /*            5    not used                              	*/
/*MT6129D*/ /*MT6205*/ /*            6    not used                               	*/
/*MT6129D*/ /*MT6205*/ /*            7    not used                               	*/
/*MT6129D*/ /*MT6205*/ /*            9    VCO Enable                             	*/
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------	*/
/*MT6129D*/ /*MT6205*/
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR1  0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR2  0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR3  0x001
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT1  0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT2  0x202
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT3  0x001
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR1     0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR2     0x201 
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR3     0x001
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT1     0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT2     0x202 
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT3     0x001

/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR1     0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR2     0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR3     0x001
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT1     0x210 
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT2     0x212
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT3     0x001

/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR1     0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR2     0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR3     0x001
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT1     0x210
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT2     0x212
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT3     0x001
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_INIT        0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_IDLE        0x00
/*MT6129D*/ /*MT6205*/	#endif  //#ifdefTQM6M4038
/*MT6129D*/ /*MT6205*/ #ifdef  RF7168
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*   define  BPI data for FOUNTAIN2 (shall be modified by real case)    */
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------*/
/*MT6129D*/ /*MT6205*/ /*    PRCB : bit   pin                                    	*/
/*MT6129D*/ /*MT6205*/ /*            0    RF7168 HB_TX(GPCTRL1)                      		*/
/*MT6129D*/ /*MT6205*/ /*            1    RF7168 LB_TX(GPCTRL0)                      		*/
/*MT6129D*/ /*MT6205*/ /*            2    RF7168 900_RX                              	*/
/*MT6129D*/ /*MT6205*/ /*            3    RF7168 PCS_RX                           		*/
/*MT6129D*/ /*MT6205*/ /*            4    RF7168 PA_EN(TX_EN)                         	*/
/*MT6129D*/ /*MT6205*/ /*            5    NC_BANDSW_DCS                              	*/
/*MT6129D*/ /*MT6205*/ /*            6    not used                               	*/
/*MT6129D*/ /*MT6205*/ /*            7    not used                               	*/
/*MT6129D*/ /*MT6205*/ /*            9    VCO Enable                             	*/
/*MT6129D*/ /*MT6205*/ /*--------------------------------------------------------	*/
/*MT6129D*/ /*MT6205*/
//ok
/*  900_RX    PCS_RX               */
/*   1          0     1900,850 rx   */       
/*   0           1    1800,900 rx   */
/*
/*
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR1  0x205
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR2  0x205
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PR3  0x000//0x205
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT1  0x201
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT2  0x211
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM850_PT3  0x000
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR1     0x209
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR2     0x209 
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PR3     0x000//0x205
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT1     0x201//0x200
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT2     0x211 //0x211 
/*MT6129D*/ /*MT6205*/ #define  PDATA_GSM_PT3     0x000//0x205

/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR1     0x20B
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR2     0x20B
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PR3     0x000
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT1     0x20B 
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT2     0x21B
/*MT6129D*/ /*MT6205*/ #define  PDATA_DCS_PT3     0x000

/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR1     0x207
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR2     0x207
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PR3     0x000
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT1     0x207
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT2     0x217
/*MT6129D*/ /*MT6205*/ #define  PDATA_PCS_PT3     0x000
//ok
/*MT6129D*/ /*MT6205*/ #define  PDATA_INIT        0x00
/*MT6129D*/ /*MT6205*/ #define  PDATA_IDLE        0x00
/*MT6129D*/ /*MT6205*/	#endif  //#ifdefRF7168
/*MT6139E*/
/*MT6139E*/ #endif
/*MT6139E*/
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/ /*   APC Compensate Thresholds                  */
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/
/*MT6139E*/ #define    SECONDS2FRAME(n)        ((int)((n)*1000/4.165))
/*MT6139E*/ #define    VOLT2UVOLT(n)           ((int)((n)*1000000))
/*MT6139E*/ #define    TEMP2MTEMP(n)           ((int)((n)*1000))
/*MT6139E*/
/*MT6139E*/ #define    BAT_VOLTAGE_SAMPLE_PERIOD            SECONDS2FRAME(180)
/*MT6139E*/ #define    BAT_VOLTAGE_AVERAGE_COUNT            1
/*MT6139E*/ #define    BAT_LOW_VOLTAGE                      VOLT2UVOLT(3.5)
/*MT6139E*/ #define    BAT_HIGH_VOLTAGE                     VOLT2UVOLT(4.0)
/*MT6139E*/
/*MT6139E*/ #define    BAT_TEMPERATURE_SAMPLE_PERIOD        SECONDS2FRAME(180)
/*MT6139E*/ #define    BAT_TEMPERATURE_AVERAGE_COUNT        1
/*MT6139E*/ #define    BAT_LOW_TEMPERATURE                  TEMP2MTEMP(0)
/*MT6139E*/ #define    BAT_HIGH_TEMPERATURE                 TEMP2MTEMP(50)
/*MT6139E*/
/*MT6139E*/
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/ /*   Crystal parameter                          */
/*MT6139E*/ /*----------------------------------------------*/
/*MT6139E*/ #define Custom_RF_XO_CapID  22
/*MT6139E*/
/*MT6139E*/
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*//*   0:GSM850 Signal go through GSM850, GSM900 Signal go through GSM900  (default)         */
/*MT6139E*//*   1:GSM850 Signal go through GSM900, GSM900 Signal go through GSM850  (default)         */
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*/#define GSM850_GSM900_SWAP  0
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*//*   0:DCS1800 Signal go through DCS1800, PCS1900 Signal go through PCS1900(default)         */
/*MT6139E*//*   1:DCS1800 Signal go through PCS1900, PCS1900 Signal go through DCS1800                  */
/*MT6139E*//*----------------------------------------------*/
/*MT6139E*/#define DCS1800_PCS1900_SWAP    0
/*MT6139E*/
/*============================================================================== */

#endif










