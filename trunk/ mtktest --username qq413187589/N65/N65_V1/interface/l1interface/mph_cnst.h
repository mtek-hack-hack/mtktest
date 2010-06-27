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
 * mph_cnst.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer 1 related constant and enum definitions for MediaTek GSM/GPRS software
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MPH_CNST_H
#define _MPH_CNST_H


/* --- ARFCN --------------------------------------------------------------- */

#define L1_PGSM900 0x01 /* PGSM900 1..124 */
#define L1_EGSM900 0x02 /* EGSM900 0..124, 975..1023 */
#define L1_RGSM900 0x04 /* RGSM900 0..124, 955..1023 */
#define L1_DCS1800 0x08 /* DCS1800 512..885 */
#define L1_PCS1900 0x10 /* PCS1900 512..810 */
#define L1_GSM450  0x20 /* GSM450  259..293 */
#define L1_GSM480  0x40 /* GSM480  306..340 */
#define L1_GSM850  0x80 /* GSM850  128..251 */

#if defined( __GSM450__ ) || defined( __GSM480__ )
#error "L1C and L1D need support the GSM450/GSM480 band(s)!"
#endif

/* this one defines which bands are supported by the layer1 */

#ifdef __PGSM900__
  #define TEMP_PGSM900 L1_PGSM900
#else
  #define TEMP_PGSM900 0
#endif
#ifdef __EGSM900__
  #define TEMP_EGSM900 (L1_PGSM900|L1_EGSM900)
#else
  #define TEMP_EGSM900 0
#endif
#ifdef __RGSM900__
  #define TEMP_RGSM900 (L1_PGSM900|L1_EGSM900|L1_RGSM900)
#else
  #define TEMP_RGSM900 0
#endif
#ifdef __DCS1800__
  #define TEMP_DCS1800 L1_DCS1800
#else
  #define TEMP_DCS1800 0
#endif
#ifdef __PCS1900__
  #define TEMP_PCS1900 L1_PCS1900
#else
  #define TEMP_PCS1900 0
#endif
#ifdef __GSM450__
  #define TEMP_GSM450 L1_GSM450
#else
  #define TEMP_GSM450 0
#endif
#ifdef __GSM480__
  #define TEMP_GSM480 L1_GSM480
#else
  #define TEMP_GSM480 0
#endif
#ifdef __GSM850__
  #define TEMP_GSM850 L1_GSM850
#else
  #define TEMP_GSM850 0
#endif
#define L1_AVAILABLE_BANDS (TEMP_PGSM900|TEMP_EGSM900|TEMP_RGSM900|TEMP_DCS1800|TEMP_PCS1900|TEMP_GSM450|TEMP_GSM480|TEMP_GSM850)

#define L1_ARFCNRANGE_0_0      0x0001
#define L1_ARFCNRANGE_1_124    0x0002
#define L1_ARFCNRANGE_975_1023 0x0004  /*EGSM*/
#define L1_ARFCNRANGE_955_974  0x0008  /*RGSM*/
#define L1_ARFCNRANGE_128_251  0x0010
#define L1_ARFCNRANGE_259_293  0x0020
#define L1_ARFCNRANGE_306_340  0x0040
#define L1_ARFCNRANGE_512_810  0x0080
#define L1_ARFCNRANGE_811_885  0x0100
#define L1_ARFCNRANGE_1536_1834 0x0200 /*PCS*/

#define L1_BANDS_TO_ARFCN_RANGES(bands) \
( \
   ( (bands) & L1_PGSM900 ? L1_ARFCNRANGE_1_124 : 0 ) | \
   ( (bands) & L1_EGSM900 ? L1_ARFCNRANGE_0_0|L1_ARFCNRANGE_1_124|L1_ARFCNRANGE_975_1023 : 0 ) | \
   ( (bands) & L1_RGSM900 ? L1_ARFCNRANGE_0_0|L1_ARFCNRANGE_1_124|L1_ARFCNRANGE_955_974|L1_ARFCNRANGE_975_1023 : 0 ) | \
   ( (bands) & L1_DCS1800 ? L1_ARFCNRANGE_512_810|L1_ARFCNRANGE_811_885 : 0 ) | \
   ( (bands) & L1_PCS1900 ? L1_ARFCNRANGE_1536_1834 : 0 ) | \
   ( (bands) & L1_GSM450  ? L1_ARFCNRANGE_259_293 : 0 ) | \
   ( (bands) & L1_GSM480  ? L1_ARFCNRANGE_306_340 : 0 ) | \
   ( (bands) & L1_GSM850  ? L1_ARFCNRANGE_128_251 : 0 ) \
)

#define L1_AVAILABLE_ARFCNS L1_BANDS_TO_ARFCN_RANGES(L1_AVAILABLE_BANDS)

#define ARFCN_COUNT \
( \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_0_0      ?   1 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_1_124    ? 124 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_128_251  ? 124 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_259_293  ?  35 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_306_340  ?  35 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_512_810  ? 299 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_811_885  ?  75 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_955_974  ?  20 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_975_1023 ?  49 : 0 ) + \
   ( L1_AVAILABLE_ARFCNS & L1_ARFCNRANGE_1536_1834 ?  299 : 0 ) \
)


/* --- USF ----------------------------------------------------------------- */

#define USF_FREE    7
#define USF_INVALID ((USF)-1)

/* --- timing advance ------------------------------------------------------ */

#define TimingAdvance_INVALID        255
#define TimingAdvance_SAME_AS_BEFORE 254

/* --- frame number -------------------------------------------------------- */

#define FRAME_NUMBER_INVALID 0x7fffffff

#endif /* _MPH_CNST_H */

