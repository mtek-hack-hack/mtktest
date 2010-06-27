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
 * ddload.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Dynamic Download for DSP(MT6218 and later)
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
 *******************************************************************************/
#ifndef  _DDLOAD_H_
#define  _DDLOAD_H_

/* ------------------------------------------------------------------------- */
#define DPCHIP_BASE_MT61XX          defined(MT6217) || defined(MT6218)  || defined(MT6219)

#define DPCHIP_BASE_MT6227          defined(MT6226) || defined(MT6226M) ||  \
                                    defined(MT6227) || defined(MT6227D) || defined(MT6226D)

#define DPCHIP_BASE_MT6228          defined(MT6228) || defined(MT6225)

#define DPCHIP_BASE_MT6229          defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6235) ||defined(MT6238)

#define DPCHIP_DUAL_DSP             DPCHIP_BASE_MT6229

#define DPCHIP_FUNC_IDMA_LOAD_PM !( defined(MT6205B)    || DPCHIP_BASE_MT61XX )

#define DPCHIP_IDMA_AUDIOHEADER   (                                                                                 \
                                   ( (DPCHIP_BASE_MT6228) && !( defined(MT6228_S00) || defined(MT6228_S01)  ) )  || \
                                   ( (DPCHIP_BASE_MT6229) && !( defined(MT6229_S00) || defined(MT6230_S00)  ) )     \
                                  )

#define DPCHIP_IDMA_LOAD_PM5      ( DPCHIP_BASE_MT6227  )

#define DPCHIP_IDMA_LOAD_PM3      ( DPCHIP_BASE_MT6228 || DPCHIP_BASE_MT6229 )

#define DPCHIP_CHK_DUPLI_DDL      ( DPCHIP_BASE_MT61XX || DPCHIP_BASE_MT6227  )

#define DPCHIP_DDL_AMR            ( DPCHIP_BASE_MT61XX  ||                         \
                                    defined(MT6226_S00) || defined(MT6226M_S00) || \
                                    defined(MT6227_S00) || defined(MT6228_S00)  || \
                                    defined(MT6228_S01) )

#define DPCHIP_DDL_AMRSBC         (                                                                                       \
                                    DPCHIP_BASE_MT6227                                                                 || \
                                   ( (DPCHIP_BASE_MT6228) && !( defined(MT6228_S00) || defined(MT6228_S01)         ) ) || \
                                   ( (DPCHIP_BASE_MT6229) && !( defined(MT6229_S00) || defined(MT6230_S00)         ) )    \
                                  )

#define DPCHIP_DDL_AWB            ( DPCHIP_BASE_MT6228 || DPCHIP_BASE_MT6229 )

#define DPCHIP_DDL_TCH            ( DPCHIP_BASE_MT6228 || DPCHIP_BASE_MT6229 )
                               
#define DPCHIP_DDL_VR             ( DPCHIP_BASE_MT6227 || DPCHIP_BASE_MT6228 || \
                                    DPCHIP_BASE_MT6229 )

#define DPCHIP_DDL_WMA_V1         ( defined(MT6228_S00) || defined(MT6228_S01) || \
                                    defined(MT6229_S00) )

#define DPCHIP_DDL_WMA_V2         (                                                                                                   \
                                   ( (DPCHIP_BASE_MT6228) && !( defined(MT6228_S00) || defined(MT6228_S01) || defined(MT6225)  ) ) || \
                                   ( (DPCHIP_BASE_MT6229) && !( defined(MT6229_S00) || defined(MT6230_S00)                     ) )    \
                                  )
                               
#define DPCHIP_DDL_DAF_PM5        (                                                                                                       \
                                   ( (DPCHIP_BASE_MT6227) && !( defined(MT6226_S00) || defined(MT6226M_S00) || defined(MT6227_S00) ) )    \
                                  )

#define DPCHIP_DDL_WT_PM          DPCHIP_BASE_MT6229

#define DPCHIP_DDL_BSAC           ( defined(MT6238) || defined(MT6229_S02) || defined(MT6230_S02) || defined(MT6228_S02) )

/* ------------------------------------------------------------------------- */

#if ( DPCHIP_BASE_MT6228 || DPCHIP_BASE_MT6229 )
  #define CM_PAGE   4
#else
  #define CM_PAGE   0
#endif

/* ------------------------------------------------------------------------- */
#define  DDID_NONE                      0

#define  DDID_DAF                       1


#if defined( DSP_WT_SYN )
  #define  DDID_WAVETABLE               3
#endif

#define  DDID_AMR_CC_SCHEDULE           4
#define  DDID_AAC                       5
#define  DDID_HEADER                    6
#define  DDID_AMRSBC                   14

#if DPCHIP_BASE_MT6228 || DPCHIP_BASE_MT6229
  #define  DDID_EES                     7
  #define  DDID_AEC                     7
  #define  DDID_NR                      7
  #define  DDID_SBSD                    7
  #define  DDID_AWB                    11

  #if DPCHIP_DDL_WMA_V2
    #define  DDID_WMA_16OB_HighRate    12
    #define  DDID_WMA_44OB             13
    #define  DDID_WMA_44QB_HighRate    15
    #define  DDID_WMA_16OB_LowRate     16
    #define  DDID_WMA_44QB_LowRate     17
  #elif DPCHIP_DDL_WMA_V1
    #define  DDID_WMA                  12
    #define  DDID_WMA_48k              13
  #endif

  #if defined(VR_ITRI)
    #define  DDID_VR                    9
  #endif   

#else
  #define  DDID_NR                      2
  #define  DDID_EES                     2
  #define  DDID_AEC                     2
  #define  DDID_SBSD                    2
  #if DPCHIP_BASE_MT6227
    /// DSP RAM code for ITRI VR. It uses the same ddload entry as DDID_NOISE_REDUCTION
    #if defined(VR_ITRI)
    #define  DDID_VR                    7
    #endif   
  #else
    /// DSP RAM code for ITRI VR. It uses the same ddload entry as DDID_NOISE_REDUCTION
    #if defined(VR_ITRI)
    #define  DDID_VR                    2
    #endif   
  #endif
#endif  

#define DDID_AAC_PLUS                   8
#define DDID_AAC_PLUS_PS               18
#define DDID_NOISE_REDUCTION          DDID_NR
#define DDID_AWBDEC                    19
#define DDID_MUSICAM                   20
#define DDID_AWB_PLUS                  21
#define DDID_BSAC                      22
#define DDID_SBC                       23

/* ------------------------------------------------------------------------- */

void _idma_load_pm(unsigned short int page, unsigned short int addr, unsigned int len, const unsigned char *image);
// for WMA L2 support
void DSP_DynamicDownload_Init( void );
void DSP_DynamicDownload( int dsp_fw_id );
void DSP_DynamicDownload_MT6223( int dsp_fw_id );
/* ------------------------------------------------------------------------- */

#endif  /*_DDLOAD_H_ */


