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
 * customer_data_account.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for include file of PS customization parameters. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_DATA_ACCOUNT_H
#define _CUSTOM_DATA_ACCOUNT_H

#include "custom_mmi_default_value.h"

#define CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM  (10)
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else
#define MAX_GPRS_PROFILE_NUM (10)
#endif

/*
 * we only support 10 profiles per bearer due to following reasons
 * 1) max control buffer size is 2K
 * 2) default profile name string only define for 1~10.
 */
#if (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM > 10)
#error currently, we only support 10 CSD profiles for each bearer
#endif

extern kal_uint8 custom_get_gprs_profile_num(void);
extern kal_uint8 custom_get_csd_profile_num(void);
extern kal_int32 custom_get_gprs_profile_size(void);

#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_POC_DTCNT_ID    CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else  
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_POC_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_POC_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else  
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_DM_DTCNT_ID      -1
#else
#define CUSTOM_DEFAULT_DM_DTCNT_ID      -1
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __MMI_OP01_GPRS_DATACFG__ */

#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else  
#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else  /* __MMI_GPRS_FEATURES__ */
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_SYNCML_DTCNT_ID    0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */
#endif
 
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_VOIP_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_VOIP_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_IMPS_DTCNT_ID    CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else  
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_IMPS_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_IMPS_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __MMI_GPRS_FEATURES__
#define CUSTOM_DEFAULT_STREAM_DTCNT_ID    CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM
#else  
#ifdef __MMI_WLAN_FEATURES__
#define CUSTOM_DEFAULT_STREAM_DTCNT_ID    (CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM + MAX_GPRS_PROFILE_NUM)
#else
#define CUSTOM_DEFAULT_STREAM_DTCNT_ID     0
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_GPRS_DATACFG__ */

// Huyanwei Modify It 
#if defined(GPRS_TH_SUPPORT)

/*
By hongzhe.Liu : 
    Thai as default
    1. dtas wap
    2. ais wap
    3. true move wap
    4. vinaphone wap
    5. mobiphone wap
    
    6. dtas mms
    7. ais mms
    8. true move mms
    9. vinaphone mms
   10. mobiphone mms

*/

#define GPRS_DATA_ACCOUNT_WAP_TURE_MOVE             (10)
#define GPRS_DATA_ACCOUNT_WAP_DTAS                       (11)
#define GPRS_DATA_ACCOUNT_WAP_AIS                          (12)
#define GPRS_DATA_ACCOUNT_WAP_VINAPHONE             (13)
#define GPRS_DATA_ACCOUNT_WAP_MOBIFONE               (14)

#define GPRS_DATA_ACCOUNT_MMS_TRUE_MOVE              (15)
#define GPRS_DATA_ACCOUNT_MMS_DTAS                         (16)
#define GPRS_DATA_ACCOUNT_MMS_AIS                           (17)
#define GPRS_DATA_ACCOUNT_MMS_VINAPHONE             (18)
#define GPRS_DATA_ACCOUNT_MMS_MOBIFONE               (19)

#define CUSTOM_DEFAULT_WAP_PROFILE1     	    GPRS_DATA_ACCOUNT_WAP_TURE_MOVE
#define CUSTOM_DEFAULT_WAP_PROFILE2     	    GPRS_DATA_ACCOUNT_WAP_DTAS
#define CUSTOM_DEFAULT_WAP_PROFILE3     	    GPRS_DATA_ACCOUNT_WAP_AIS
#define CUSTOM_DEFAULT_WAP_PROFILE4     	    GPRS_DATA_ACCOUNT_WAP_VINAPHONE
#define CUSTOM_DEFAULT_WAP_PROFILE5     	    GPRS_DATA_ACCOUNT_WAP_MOBIFONE
#define CUSTOM_DEFAULT_WAP_PROFILE_EMPTY  CUSTOM_DEFAULT_WAP_PROFILE1

#define CUSTOM_DEFAULT_MMS_PROFILE1     	    GPRS_DATA_ACCOUNT_MMS_TRUE_MOVE
#define CUSTOM_DEFAULT_MMS_PROFILE2     	    GPRS_DATA_ACCOUNT_MMS_DTAS 
#define CUSTOM_DEFAULT_MMS_PROFILE3     	    GPRS_DATA_ACCOUNT_MMS_AIS
#define CUSTOM_DEFAULT_MMS_PROFILE4     	    GPRS_DATA_ACCOUNT_MMS_VINAPHONE
#define CUSTOM_DEFAULT_MMS_PROFILE5     	    GPRS_DATA_ACCOUNT_MMS_MOBIFONE
#define CUSTOM_DEFAULT_MMS_PROFILE_EMPTY  CUSTOM_DEFAULT_MMS_PROFILE1

#elif defined(GPRS_SM_SUPPORT)
/*
By hongzhe.Liu : 
    China as default
    1. china mobile
    2. china unicom

    3. dtas wap
    4. ais wap
    5. true move wap
    6. dtas mms
    7. ais mms
    8. true move mms
*/
#define GPRS_DATA_ACCOUNT_CHINA_MOBILE                  (10)
#define GPRS_DATA_ACCOUNT_CHINA_UNICOM                 (11)

/*
By Hongzhe.Liu :
     Use chinese as default:
     1. china mobile mms
     2. china unicom mms

   3. dtac wap gprs
   4. ais wap gprs
   5. true move gprs
*/

#define CUSTOM_DEFAULT_WAP_PROFILE1     	    GPRS_DATA_ACCOUNT_CHINA_MOBILE
#define CUSTOM_DEFAULT_WAP_PROFILE2     	    GPRS_DATA_ACCOUNT_CHINA_UNICOM

/*
By Hongzhe.Liu :
     Use chinese as default:
     1. china mobile mms
     2. china unicom mms

   3. dtac mms gprs
   4. ais mms gprs
   5. true move gprs
*/

#define CUSTOM_DEFAULT_MMS_PROFILE1     	    GPRS_DATA_ACCOUNT_CHINA_MOBILE
#define CUSTOM_DEFAULT_MMS_PROFILE2     	    GPRS_DATA_ACCOUNT_CHINA_UNICOM

#elif defined(GPRS_SM_TH_SUPPORT)
/*
    By hongzhe.Liu : 
    China as default
    1. china mobile
    2. china unicom

    3. dtas wap
    4. ais wap
    5. true move wap
    6. dtas mms
    7. ais mms
    8. true move mms
*/
#define GPRS_DATA_ACCOUNT_CHINA_MOBILE                  (10)
#define GPRS_DATA_ACCOUNT_CHINA_UNICOM                 (11)

#define GPRS_DATA_ACCOUNT_WAP_DTAS                       (12)
#define GPRS_DATA_ACCOUNT_WAP_AIS                          (13)
#define GPRS_DATA_ACCOUNT_WAP_TURE_MOVE             (14)

#define GPRS_DATA_ACCOUNT_MMS_DTAS                         (15)
#define GPRS_DATA_ACCOUNT_MMS_AIS                           (16)
#define GPRS_DATA_ACCOUNT_MMS_TRUE_MOVE              (17)

/*
By Hongzhe.Liu :
     Use chinese as default:
     1. china mobile mms
     2. china unicom mms

   3. dtac wap gprs
   4. ais wap gprs
   5. true move gprs
*/

#define CUSTOM_DEFAULT_WAP_PROFILE1     	    GPRS_DATA_ACCOUNT_CHINA_MOBILE
#define CUSTOM_DEFAULT_WAP_PROFILE2     	    GPRS_DATA_ACCOUNT_CHINA_UNICOM
#define CUSTOM_DEFAULT_WAP_PROFILE3     	    GPRS_DATA_ACCOUNT_WAP_DTAS
#define CUSTOM_DEFAULT_WAP_PROFILE4     	    GPRS_DATA_ACCOUNT_WAP_AIS
#define CUSTOM_DEFAULT_WAP_PROFILE5     	    GPRS_DATA_ACCOUNT_WAP_TURE_MOVE
#define CUSTOM_DEFAULT_WAP_PROFILE_EMPTY  CUSTOM_DEFAULT_WAP_PROFILE1

/*
By Hongzhe.Liu :
     Use chinese as default:
     1. china mobile mms
     2. china unicom mms

   3. dtac mms gprs
   4. ais mms gprs
   5. true move gprs
*/

#define CUSTOM_DEFAULT_MMS_PROFILE1     	    GPRS_DATA_ACCOUNT_CHINA_MOBILE
#define CUSTOM_DEFAULT_MMS_PROFILE2     	    GPRS_DATA_ACCOUNT_CHINA_UNICOM
#define CUSTOM_DEFAULT_MMS_PROFILE3     	    GPRS_DATA_ACCOUNT_MMS_DTAS
#define CUSTOM_DEFAULT_MMS_PROFILE4     	    GPRS_DATA_ACCOUNT_MMS_AIS
#define CUSTOM_DEFAULT_MMS_PROFILE5     	    GPRS_DATA_ACCOUNT_MMS_TRUE_MOVE
#define CUSTOM_DEFAULT_MMS_PROFILE_EMPTY  CUSTOM_DEFAULT_MMS_PROFILE1

#elif defined(GPRS_DEFAULT_SUPPORT)

 /*
    By hongzhe.Liu : 
    China as default
    1. china mobile
    2. china unicom

    3. dtas wap
    4. ais wap
    5. true move wap
    6. dtas mms
    7. ais mms
    8. true move mms
*/

#define GPRS_DATA_ACCOUNT_WAP_FET                     	 (10)
#define GPRS_DATA_ACCOUNT_WAP_CHT                    	 (11)
#define GPRS_DATA_ACCOUNT_WAP_TAIWAN		  	 (12)
#define GPRS_DATA_ACCOUNT_CHINA_MOBILE                  (13)
#define GPRS_DATA_ACCOUNT_WAP_AIS                           (14)
#define GPRS_DATA_ACCOUNT_WAP_DTAS                        (15)
#define GPRS_DATA_ACCOUNT_WAP_TURE_MOVE              (16)


#define GPRS_DATA_ACCOUNT_MMS_FET                     	 (10)
#define GPRS_DATA_ACCOUNT_MMS_CHT                    	 (11)
#define GPRS_DATA_ACCOUNT_MMS_TAIWAN		  	 (12)
#define GPRS_DATA_ACCOUNT_CHINA_MOBILE                  (13)
#define GPRS_DATA_ACCOUNT_MMS_AIS                           (17)
#define GPRS_DATA_ACCOUNT_MMS_DTAS                        (18)
#define GPRS_DATA_ACCOUNT_MMS_TURE_MOVE              (19)

/*
By Hongzhe.Liu :
     Use chinese as default:
     1. china mobile mms
     2. china unicom mms

   3. dtac wap gprs
   4. ais wap gprs
   5. true move gprs
*/

#define CUSTOM_DEFAULT_WAP_PROFILE1     	    GPRS_DATA_ACCOUNT_WAP_FET
#define CUSTOM_DEFAULT_WAP_PROFILE2     	    GPRS_DATA_ACCOUNT_WAP_CHT
#define CUSTOM_DEFAULT_WAP_PROFILE3     	    GPRS_DATA_ACCOUNT_WAP_TAIWAN
#define CUSTOM_DEFAULT_WAP_PROFILE4     	    GPRS_DATA_ACCOUNT_CHINA_MOBILE
#define CUSTOM_DEFAULT_WAP_PROFILE5     	    GPRS_DATA_ACCOUNT_WAP_AIS
#define CUSTOM_DEFAULT_WAP_PROFILE6		    GPRS_DATA_ACCOUNT_WAP_DTAS
#define CUSTOM_DEFAULT_WAP_PROFILE7		    GPRS_DATA_ACCOUNT_WAP_TURE_MOVE
#define CUSTOM_DEFAULT_WAP_PROFILE_EMPTY  CUSTOM_DEFAULT_WAP_PROFILE1

/*
By Hongzhe.Liu :
     Use chinese as default:
     1. china mobile mms
     2. china unicom mms

   3. dtac mms gprs
   4. ais mms gprs
   5. true move gprs
*/

#define CUSTOM_DEFAULT_MMS_PROFILE1     	    GPRS_DATA_ACCOUNT_MMS_FET
#define CUSTOM_DEFAULT_MMS_PROFILE2     	    GPRS_DATA_ACCOUNT_MMS_CHT
#define CUSTOM_DEFAULT_MMS_PROFILE3     	    GPRS_DATA_ACCOUNT_MMS_TAIWAN
#define CUSTOM_DEFAULT_MMS_PROFILE4     	    GPRS_DATA_ACCOUNT_CHINA_MOBILE
#define CUSTOM_DEFAULT_MMS_PROFILE5     	    GPRS_DATA_ACCOUNT_MMS_AIS
#define CUSTOM_DEFAULT_MMS_PROFILE6     	    GPRS_DATA_ACCOUNT_MMS_DTAS
#define CUSTOM_DEFAULT_MMS_PROFILE7		    GPRS_DATA_ACCOUNT_MMS_TURE_MOVE
#define CUSTOM_DEFAULT_MMS_PROFILE_EMPTY  CUSTOM_DEFAULT_MMS_PROFILE1

#endif


#endif /*  ENDIF __MMI_OP01_GPRS_DATACFG__ */

#ifndef __L1_STANDALONE__

extern nvram_ef_abm_gprs_profile_struct  abm_gprs_profile[];
extern kal_uint8 abm_gprs_state[];
extern kal_uint8 abm_gprs_bearer_id[];   

#ifdef __TCPIP__
extern nvram_ef_csd_profile_struct  csd_prof[CUSTOM_DEFINED_MAX_CSD_PROFILE_NUM];
#endif /* __TCPIP__ */

#endif /* __L1_STANDALONE__ */

#endif /* _CUSTOM_DATA_ACCOUNT_H */

