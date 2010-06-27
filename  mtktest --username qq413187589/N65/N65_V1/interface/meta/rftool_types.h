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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   rftool_types.h
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   Public interface of RF Tool on Mobile
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef rftool_types_h
#define rftool_types_h

#ifndef _MPH_CNST_H
 #error "Please inlcude mph_cnst.h for input value of bands"
#endif

/* --- Type define ---------------------------------------------------------- */
typedef void (* rfTool_gsm_pwr_scan_ptr)(kal_int16 arfcn[20], kal_int16 power[20]);


/* --- Consts --------------------------------------------------------------- */
#define ARFCN_REPRESENT_ALL_CHANNEL_INBAND (9999)


/* --- Enums ---------------------------------------------------------------- */
typedef enum
{
   RFTOOL_NB_TX_RANDOM_WITH_TSC,
   RFTOOL_NB_TX_ALL_ONES_WITHOUT_TSC,
   RFTOOL_AB_TX_RANDOM_WITH_SYNC_SEQ,
   RFTOOL_CONT_TX_ALL_ZEROS,
   RFTOOL_CONT_TX_ALL_ONES,
   RFTOOL_CONT_TX_ALTERNATE_BITS,
   RFTOOL_CONT_TX_PSEUDO_RANDOM
} RFToolGSMTxPattern;

typedef enum
{
   	RFTOOL_NB_RX_CONTINUE,
	RFTOOL_NB_RX_BURST
} RFToolGSMRxPattern;

typedef enum
{
	NORMAL_MODE,
	RFTOOL_MODE
} L1D_MODE;

/* --- General API --------------------------------------------------------- */
void RFTool_GSM_Stop( void );


/* --- GSM Test API -------------------------------------------------------- */
void RFTool_GSM_TxTest( kal_uint8 band, kal_int16 arfcn, kal_int8 tsc, kal_int8 pcl, 
                        kal_int16 afc, RFToolGSMTxPattern pattern );
                        
void RFTool_GSM_RxTest( kal_uint8 band, kal_int16 arfcn, kal_int16 gain, RFToolGSMRxPattern pattern );

void RFTool_GSM_PowerScan( kal_uint8 band, kal_int16 arfcn, 
                           void (* callback) (kal_int16 arfcn[20], kal_int16 power[20]) );
void DeInit_RFTool_GSM(void);


#endif
