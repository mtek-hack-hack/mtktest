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
 * nvram_data_items.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM. 
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef __MAUI_BASIC__

#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_release.h"

#include "nvram_defs.h"
#include "nvram_data_items.h"
#include "tst.h"

/* Add for L1 Category */
#include "m12190.h"
#include "m12193.h"
#if defined(__WCDMA_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
#endif /* __WCDMA_RAT__ && __MTK_UL1_FDD__ */

#include "l1cal.h"
#if defined(__WIFI_SUPPORT__)
#include "wndrv_cal.h"
#endif

#include "nvram_editor_data_item.h"
#undef _FILE_CODE_
#define _FILE_CODE_ _NVRAM_DATA_ITEMS_C_


/**
 * Padding. 
 * Size MUST be CODED_PADDING_SIZE. 
 * First byte MUST be '\0', so that CODED_DATA_VERSION is always zero-terminated.
 * Be as random as possible.. though that is impossible... >=P 
 */
kal_uint8* CODED_PADDING = (kal_uint8*)"\x00\xDD\xC5\xB9";

/**
 * Hardcoded secret key. Always 8 bytes.
 * Note that this key will be used to decrypt LOCK_PATTERN.
 */
/* kal_uint8* CODED_SECRET_KEY = (kal_uint8*)"12abcdef"; */

kal_uint8 coded_version_lock[NVRAM_EF_SYS_SIZE];

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_lid_core_enum' in 
 *    nvram_data_items.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_data_items.h
 * 3> Define default value of that new logical data item.
 * 4> Define attributes of that new logical data item into 
 *    `logical_data_item_table_core'
 * 5> Change NVRAM_TOTAL_LID_VENDOR in nvram_user_defs.h
 * 6> Add structure defination in nvram_editor_data_item.h
 * 7> Add bit-level description in nvram_editor_data_item.h
 * 8> Change version number CODED_DATA_VERSION in nvram_user_config.c
 *
 * Note that multiple copied attribute DOES NOT support for 
 * near fixed logical data items.
 */

/**
 * Step 3:
 * Define necessary default values for each logical data item.
 */

kal_uint8 const NVRAM_EF_ZERO_DEFAULT[] = { 0x00 };
kal_uint8 const NVRAM_EF_FF_DEFAULT[] = { 0xFF };

static kal_uint8 const NVRAM_EF_CFU_FLAG_DEFAULT[] = {
                  0x55, 0x55
};

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add it For g sensor
kal_uint8 const NVRAM_GSENSOR_DEFAULT[]=
{
	//16,0,40,0,82,0 //Old
	0x32,0x00,0x12,0x00,0x14,0x00 //New
};
#endif

static kal_uint8 const NVRAM_EF_MM_EQPLMN_LOCIGPRS_DEFAULT[] = {
	0x00, //rplmn_rat
	0x00, //num_of_eq_plmn
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[0]
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[1]
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[2]
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[3]
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[4]
	0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[5]
	0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //nvram_locigprs
};

#ifdef __CTM_SUPPORT__
/*CTM */
static kal_uint8 const NVRAM_EF_CTM_DEFAULT_SETTINGS_DEFAULT[] = {
	0x00, /* is_turn_on */
	0x01, /* ctm_interface, 0: CTM_DIRECT_MODE, 1: CTM_BAUDOT_MODE */
        0x05, 0x00, /* kal_int16 cprm_tone_demod_down_samp */
        0x80, 0x80 /* input_vol, output_vol */
};
#endif

static kal_uint8 const NVRAM_EF_CLASSMARK_RACAP_DEFAULT[] = {
       /*---BYTE 1 to BYTE 6 : From MS CLASSMARK3 -------------------------*/  
       /* Claire 030922 change : Support multiband compile option */
#if defined( __EGSM900__) && defined( __DCS1800__)
                  0x60,  /* MS supports E-GSM and DCS band */
                  0x14,  /* E-GSM power class 4, DCS power class 1 */  
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x14,  /* P-GSM power class 4, DCS power class 1 */  
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x04,  /* E-GSM power class 4 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x04,  /* P-GSM power class 4 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x01,  /* DCS power class 1 */
#else 
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,       
#endif
                   
                  0x01,  /* HSCSD multislot cap not present, UCS2 =1 */   
                  /* Claire 030922 change : Support multiband compile option */

#if defined( __GSM450__) || defined( __GSM480__)
                  0x81,
#else
                  0x80,  /* Extended Measurement cap =1 */ 
#endif


#if !defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                  0x00,  /* GSM 400 and GSM 850 are not suported */ 
#elif defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                 0x90,  /* GSM 450 is supported with power class 4*/
#elif !defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0x50,  /* GSM 480 is supported with power class 4*/
#elif !defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x02,  /* GSM 850 is supported*/
#elif defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0xd0,  /* GSM 450 and 480 are supported with power class 4*/ 
#elif defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x92,  /* GSM 450 with power class 4 and GSM 850 are supported*/ 
#elif !defined( __GSM450__) && defined( __GSM480__) && defined( __GSM850__)
                 0x52,  /* GSM 450 with power class 4 and GSM 850 are supported*/ 
#else
                 0xd2,   /* GSM 450, 480 with power class 4 and 850 are supported*/
#endif


#if defined( __GSM850__) && defined( __PCS1900__)
                  0x91,  /* GSM 850 is power class 4 ,PCS 1900 is suportedwith power class 1*/
#elif  defined( __PCS1900__)
                  0x11,  /* PCS 1900 is suported , power class 1 */       
#elif  defined( __GSM850__)
                  0x80,  /* GSM 850 is power class 4 */ 
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

                  
       /*---BYTE 7 to BYTE 9 : From MS CLASSMARK2 -----------  */  
                  0x30,  /* ES_IND =1, Revision level =01, A51 algo supported---*/
                  0x58,  /* PS cap =1, SS sreen indicator =01, SM cap =1 */
             
#if defined( MT6208) || defined( MT6205) || defined( MT6218) || defined( MT6219) || \
    defined( MT6217) || defined( MT6227) || defined( MT6226) || defined( MT6228) || \
    defined(MT6205B) || defined(MT6226M) || defined(MT6218B)
       /*The chip doesn't support A5/3*/
	#ifdef __DISABLE_A5_2__ 
		  0x84,
	#else
		  0x85,
	#endif // __DISABLE_A5_2__ 
#else // The chip support A5/3
	#ifdef __DISABLE_A5_2__
 		  0x86,
	#else
		  0x87,
	#endif //__DISABLE_A5_2__
#endif
       /*---BYTE 10 to BYTE 12 : From MS RA capability and MS network capability --*/

                           /* BYTE 10:
                            * bit 8: multislot capability present, 
                            * bit 7 ~ 3: mutlislot capability, 
                            * bit 2: GPRS extended Dynamic Allocation cap =1  
                            * bit 1 : RL indicator = 0 => R98 MS, 1 => R99 MS */ 
#ifdef __R99__
   #ifdef EDGE_CARD_CLASS_10
                  0xab,   /* Default GPRS multislot class 10, ext DA support, R99 */
   #else
                  0xb3,  /* Default GPRS multislot class 12, ext DA support, R99 */
   #endif                  
#else /* __R99__*/
   #ifdef EDGE_CARD_CLASS_10
                  0xaa,   /* Default GPRS multislot class 10, ext DA support, R98 */
   #else
                  0xb2,  /* Default GPRS multislot class 12, ext DA support, R98 */
   #endif                  
#endif /* __R99__ */

                           /* BYTE 11:
                            * bit 8 : GEA1
                            * bit 7 : GEA2
                            * bit 6 : GEA3
                            * bit 5 : GEA4
                            * bit 4 : GEA5
                            * bit 3 : GEA6
                            * bit 2 : GEA7
                            * bit 1 : SM cap in GPRS =1 */

#if defined( MT6208) || defined( MT6205) || defined( MT6218) || defined( MT6219) || \
    defined( MT6217) || defined( MT6227) || defined( MT6226) || defined( MT6228) || \
    defined(MT6205B) || defined(MT6226M) || defined(MT6218B)
                  0xc1, /* GEA1, 2 and SM cap support */ 
#else // The chip support A5/3(GEA/3)
	0xe1, /* GEA1, 2, 3 and SM cap support */
#endif

                           /* BYTE 12: Lanslo 20060215: for selecting GPRS or EGPRS capability
                             * bit 8: PFC mode = 0b
                             * bit 7: EDGE multislot class present / EDGE support = 1b
                             * bit 6 ~ 2: EDGE multislot capability = 01100b
                             * bit 1: EDGE extended dynamic allocation capability = 1b 
                             * Old value 0x80, new 0xd9(PFC on), 0x59 (PFC off) */
#ifdef __EGPRS_MODE__
   #ifdef EDGE_CARD_CLASS_10
                  0x55   /* PFC off, EGPRS multislot class 10, Ext DA support */
   #else
                  0x59   /* PFC off, EGPRS multislot class 12, Ext DA support */
   #endif                  
#else /* __EGPRS_MODE__ */
                  0x00   /* PFC off */
#endif /* __EGPRS_MODE__ */

                  };

#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WCDMA_RAT__ */

/**
 * Step 4:
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 * 
 * The last LID in the MT reign now is MT1k
 */
ltable_entry_struct logical_data_item_table_core[] = 
{
	{
		NVRAM_EF_SYS_LID,
		NVRAM_EF_SYS_SIZE,
		NVRAM_EF_SYS_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER,
		"MT00", 
		"000", 
		"SYSTEM Record\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_BRANCH_VERNO_LID,
		NVRAM_EF_BRANCH_VERNO_SIZE,
		NVRAM_EF_BRANCH_VERNO_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER,
		"MT01", 
		"000", 
		"Branch verno\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_CUSTPACK_VERNO_LID,
		NVRAM_EF_CUSTPACK_VERNO_SIZE,
		NVRAM_EF_CUSTPACK_VERNO_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_WRITEPROTECT,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"MT02", 
		"000",
		"Cust Pack Bin Ver\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_SYS_EXCEPTION_LID,
		NVRAM_EF_SYS_EXCEPTION_SIZE,
		NVRAM_EF_SYS_EXCEPTION_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MT03", 
		VER(NVRAM_EF_SYS_EXCEPTION_LID), 
		"Exception Record\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_SYS_STATISTICS_LID,
		NVRAM_EF_SYS_STATISTICS_SIZE,
		NVRAM_EF_SYS_STATISTICS_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT04", 
		VER(NVRAM_EF_SYS_STATISTICS_LID), 
		"SYS Stat\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_AGCPATHLOSS_LID,
		NVRAM_EF_L1_AGCPATHLOSS_SIZE,
		NVRAM_EF_L1_AGCPATHLOSS_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT05", 
		VER(NVRAM_EF_L1_AGCPATHLOSS_LID), 
		"AGC\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_RAMPTABLE_GSM850_LID,
		NVRAM_EF_L1_RAMPTABLE_GSM850_SIZE,
		NVRAM_EF_L1_RAMPTABLE_GSM850_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT06",
		VER(NVRAM_EF_L1_RAMPTABLE_GSM850_LID), 
		"RAMP GSM850\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
		NVRAM_EF_L1_RAMPTABLE_GSM900_SIZE,
		NVRAM_EF_L1_RAMPTABLE_GSM900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT07", 
		VER(NVRAM_EF_L1_RAMPTABLE_GSM900_LID), 
		"RAMP GSM900\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_RAMPTABLE_DCS1800_LID,
		NVRAM_EF_L1_RAMPTABLE_DCS1800_SIZE,
		NVRAM_EF_L1_RAMPTABLE_DCS1800_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT08", 
		VER(NVRAM_EF_L1_RAMPTABLE_DCS1800_LID), 
		"RAMP DCS1800\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_RAMPTABLE_PCS1900_LID,
		NVRAM_EF_L1_RAMPTABLE_PCS1900_SIZE,
		NVRAM_EF_L1_RAMPTABLE_PCS1900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT09", 
		VER(NVRAM_EF_L1_RAMPTABLE_PCS1900_LID), 
		"RAMP PCS1900\0",
		NVRAM_RESERVED_VALUE
	}
#if defined(__EPSK_TX__)
	,{                                                                   
		NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID,
		NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_SIZE,
		NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0a",
		VER(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM850_LID),
		"EPSK RAMP GSM850\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID,
		NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_SIZE,
		NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0b",
		VER(NVRAM_EF_L1_EPSK_RAMPTABLE_GSM900_LID),
		"EPSK RAMP GSM900\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID,
		NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_SIZE,
		NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0c",
		VER(NVRAM_EF_L1_EPSK_RAMPTABLE_DCS1800_LID),
		"EPSK RAMP DCS1800\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID,
		NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_SIZE,
		NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0d",
		VER(NVRAM_EF_L1_EPSK_RAMPTABLE_PCS1900_LID),
		"EPSK RAMP PCS1900\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID,
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_SIZE,
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0e",
		VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM850_LID),
		"IS EPSK INTERSLOT RAMP GSM850\0",
		NVRAM_RESERVED_VALUE
   }
	,{                                                                   
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_SIZE,
        NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_TOTAL,
        NVRAM_EF_FF_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
        "MT0f",
        VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_GSM900_LID),
        "IS EPSK INTERSLOT RAMP GSM900\0",
        NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID,
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_SIZE,
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_TOTAL,
		NVRAM_EF_FF_DEFAULT,
      NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0g",
		VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_DCS1800_LID),
		"IS INTERSLOT EPSK RAMP DCS1800\0",
		NVRAM_RESERVED_VALUE
   }
	,{                                                                   
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID,
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_SIZE,
		NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0h",
		VER(NVRAM_EF_L1_EPSK_INTERSLOT_RAMP_PCS1900_LID),
		"IS INTERSLOT EPSK RAMP PCS1900\0",
		NVRAM_RESERVED_VALUE
   }

#endif/*__EPSK_TX__*/
	,{                                                                   
		NVRAM_EF_L1_AFCDATA_LID,
		NVRAM_EF_L1_AFCDATA_SIZE,
		NVRAM_EF_L1_AFCDATA_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0i", 
		VER(NVRAM_EF_L1_AFCDATA_LID), 
		"AFC Data\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_TXIQ_LID,
		NVRAM_EF_L1_TXIQ_SIZE,
		NVRAM_EF_L1_TXIQ_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"MT0j", 
		VER(NVRAM_EF_L1_TXIQ_LID), 
		"TXIQ\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_RFSPECIALCOEF_LID,
		NVRAM_EF_L1_RFSPECIALCOEF_SIZE,
		NVRAM_EF_L1_RFSPECIALCOEF_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0k", 
		VER(NVRAM_EF_L1_RFSPECIALCOEF_LID), 
		"RFSPECIALCOEF\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID,
		NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_SIZE,
		NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0l", 
		VER(NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID), 
		"IS RAMP GSM850\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID,
		NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_SIZE,
		NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0m", 
		VER(NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID), 
		"IS RAMP GSM900\0",
		NVRAM_RESERVED_VALUE
	}                     
	,{                                                                   
		NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID,
		NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_SIZE,
		NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0n", 
		VER(NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID), 
		"IS RAMP DCS1800\0",
		NVRAM_RESERVED_VALUE
	}                     
	,{                                                                   
		NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID,
		NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_SIZE,
		NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0o", 
		VER(NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID), 
		"IS RAMP PCS1900\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_L1_CRYSTAL_AFCDATA_LID,
		NVRAM_EF_L1_CRYSTAL_AFCDATA_SIZE,
		NVRAM_EF_L1_CRYSTAL_AFCDATA_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0p", 
		VER(NVRAM_EF_L1_CRYSTAL_AFCDATA_LID), 
		"CRYSTAL AFC Data\0",
		NVRAM_RESERVED_VALUE
	}                     
	,{                                                                   
		NVRAM_EF_L1_CRYSTAL_CAPDATA_LID,
		NVRAM_EF_L1_CRYSTAL_CAPDATA_SIZE,
		NVRAM_EF_L1_CRYSTAL_CAPDATA_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_BRANCH,
		"MT0q", 
		VER(NVRAM_EF_L1_CRYSTAL_CAPDATA_LID), 
		"CRYSTAL CAP Data\0",
		NVRAM_RESERVED_VALUE
	}              
#if defined(__WCDMA_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WCDMA_RAT__ && __MTK_UL1_FDD__*/	
#if defined(__WIFI_SUPPORT__)
	,{                                                                   
		NVRAM_EF_WNDRV_MAC_ADDRESS_LID,
		NVRAM_EF_WNDRV_MAC_ADDRESS_SIZE,
		NVRAM_EF_WNDRV_MAC_ADDRESS_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"WIFI",
		VER(NVRAM_EF_WNDRV_MAC_ADDRESS_LID),
		"WNDRV MAC ADDR\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_WNDRV_TX_POWER_2400M_LID,
		NVRAM_EF_WNDRV_TX_POWER_2400M_SIZE,
		NVRAM_EF_WNDRV_TX_POWER_2400M_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"WIFI",
		VER(NVRAM_EF_WNDRV_TX_POWER_2400M_LID),
		"WNDRV 2.4G TXPWR\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                         
		NVRAM_EF_WNDRV_TX_POWER_5000M_LID,
		NVRAM_EF_WNDRV_TX_POWER_5000M_SIZE,
		NVRAM_EF_WNDRV_TX_POWER_5000M_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"WIFI",
		VER(NVRAM_EF_WNDRV_TX_POWER_5000M_LID),
		"WNDRV 5.0G TXPWR\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                         
		NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID,
		NVRAM_EF_WNDRV_DAC_DC_OFFSET_SIZE,
		NVRAM_EF_WNDRV_DAC_DC_OFFSET_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"WIFI",
		VER(NVRAM_EF_WNDRV_DAC_DC_OFFSET_LID),
		"WNDRV DAC DC OFFSET\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                         
		NVRAM_EF_WNDRV_TX_ALC_POWER_LID,
		NVRAM_EF_WNDRV_TX_ALC_POWER_SIZE,
		NVRAM_EF_WNDRV_TX_ALC_POWER_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"WIFI",
		VER(NVRAM_EF_WNDRV_TX_ALC_POWER_LID),
		"WNDRV TX ALC POWER\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                         
		NVRAM_EF_WNDRV_ALC_SLOPE_LID,
		NVRAM_EF_WNDRV_ALC_SLOPE_SIZE,
		NVRAM_EF_WNDRV_ALC_SLOPE_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_BRANCH,
		"WIFI",
		VER(NVRAM_EF_WNDRV_ALC_SLOPE_LID),
		"WNDRV ALC SLOPE\0",
		NVRAM_RESERVED_VALUE
	}
#endif /*__WIFI_SUPPORT__*/	
	,{
		NVRAM_EF_EXTBCCH_LID,
		NVRAM_EF_EXTBCCH_SIZE,
		NVRAM_EF_EXTBCCH_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT0v", 
		VER(NVRAM_EF_EXTBCCH_LID), 
		"EXTBCCH\0",
		NVRAM_RESERVED_VALUE
	}
#ifdef __R99__
	,{
		NVRAM_EF_EQ_PLMN_LID,
		NVRAM_EF_EQ_PLMN_SIZE,
		NVRAM_EF_EQ_PLMN_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT0w", 
		VER(NVRAM_EF_EQ_PLMN_LID), 
		"EQ PLMN\0",
		NVRAM_RESERVED_VALUE
	}
#endif/*__R99__*/
	,{
		NVRAM_EF_BAND_INFO_LID,
		NVRAM_EF_BAND_INFO_SIZE,
		NVRAM_EF_BAND_INFO_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT0x", 
		VER(NVRAM_EF_BAND_INFO_LID), 
		"BAND INFO\0",
		NVRAM_RESERVED_VALUE
	}
	,{                                                                   
		NVRAM_EF_TST_FILTER_LID,
		NVRAM_EF_TST_FILTER_SIZE,
		NVRAM_EF_TST_FILTER_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_SHADOW,
		"MT0y", 
		VER(NVRAM_EF_TST_FILTER_LID), 
		"TST Filter\0",
		NVRAM_RESERVED_VALUE
	}
    ,{
		NVRAM_EF_CB_CH_INFO_LID,
		NVRAM_EF_CB_CH_INFO_SIZE,
		NVRAM_EF_CB_CH_INFO_TOTAL,
		NVRAM_EF_FF_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT0z", 
		VER(NVRAM_EF_CB_CH_INFO_LID), 
		"CB Channel Info\0",
		NVRAM_RESERVED_VALUE
	} 
 	,{
		NVRAM_EF_SMSAL_MWIS_LID,
		NVRAM_EF_SMSAL_MWIS_SIZE,
		NVRAM_EF_SMSAL_MWIS_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_SHADOW,
		"MT10",
		VER(NVRAM_EF_SMSAL_MWIS_LID),
		"SMSAL MWIS\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_TCM_STATISTICS_LID,
		NVRAM_EF_TCM_STATISTICS_SIZE,
		NVRAM_EF_TCM_STATISTICS_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT11", 
		VER(NVRAM_EF_TCM_STATISTICS_LID), 
		"TCM Stats\0",
		NVRAM_RESERVED_VALUE
	} 
	,{
		NVRAM_EF_CFU_FLAG_LID,
		NVRAM_EF_CFU_FLAG_SIZE,
		NVRAM_EF_CFU_FLAG_TOTAL,
		NVRAM_EF_CFU_FLAG_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER| NVRAM_CATEGORY_SHADOW,
		"MT12", 
		VER(NVRAM_EF_CFU_FLAG_LID), 
		"CFU Flag\0",
		NVRAM_RESERVED_VALUE
	}
#ifdef __PS_SERVICE__
    ,{
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_SIZE,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_TOTAL,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_DEFAULT,
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MT13",
        VER(NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID),
        "MM EQPLMN_LOCIGPRS\0",
        NVRAM_RESERVED_VALUE
    }
#endif/*__PS_SERVICE__*/
#ifdef __CTM_SUPPORT__
	,{
		NVRAM_EF_CTM_DEFAULT_SETTINGS_LID,
		NVRAM_EF_CTM_DEFAULT_SETTINGS_SIZE,
		NVRAM_EF_CTM_DEFAULT_SETTINGS_TOTAL,
		NVRAM_EF_CTM_DEFAULT_SETTINGS_DEFAULT, 
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER,
		"MT14", 
		VER(NVRAM_EF_CTM_DEFAULT_SETTINGS_LID), 
		"CTM Default Settings\0",
		NVRAM_RESERVED_VALUE
	}
#endif/*__CTM_SUPPORT__*/
#if defined (__CPHS__)	|| defined (__CCM_NO_RESET__)
    ,{
		NVRAM_EF_ALS_LINE_ID_LID,
		NVRAM_EF_ALS_LINE_ID_SIZE,
		NVRAM_EF_ALS_LINE_ID_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK | NVRAM_CATEGORY_SHADOW,
		"MT15",
		VER(NVRAM_EF_ALS_LINE_ID_LID),
		"ALS Line\0",
		NVRAM_RESERVED_VALUE
	}
#endif/* (__CPHS__) || (__CCM_NO_RESET__)*/
	,{                                                                   
		NVRAM_EF_MSCAP_LID,
		NVRAM_EF_MSCAP_SIZE,
		NVRAM_EF_MSCAP_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
		"MT16",
		VER(NVRAM_EF_MSCAP_LID),
		"MSCAP\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_CLASSMARK_RACAP_LID,
		NVRAM_EF_CLASSMARK_RACAP_SIZE,
		NVRAM_EF_CLASSMARK_RACAP_TOTAL,
		NVRAM_EF_CLASSMARK_RACAP_DEFAULT,
		NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
		NVRAM_CATEGORY_USER,
		"MT17",
		VER(NVRAM_EF_CLASSMARK_RACAP_LID),
		"CLASSMARK RACAP\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_SIM_ASSERT_LID,
		NVRAM_EF_SIM_ASSERT_SIZE,
		NVRAM_EF_SIM_ASSERT_TOTAL,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_RING,
		NVRAM_CATEGORY_SHADOW,
		"MT18",
		VER(NVRAM_EF_SIM_ASSERT_LID),
		"SIM Assert Log\0",
		NVRAM_RESERVED_VALUE
	}
	,{
		NVRAM_EF_RTC_DATA_LID,
		sizeof(nvram_ef_rtc_calibration),
		1,
		NVRAM_EF_ZERO_DEFAULT,
		NVRAM_ATTR_AVERAGE,
		NVRAM_CATEGORY_SHADOW,
		"MT19",
		VER(NVRAM_EF_RTC_DATA_LID),
		"RTC Calibration\0",
		NVRAM_RESERVED_VALUE
	}
#ifdef __WCDMA_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __PRODUCTION_RELEASE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __PRODUCTION_RELEASE__ */
#endif /* __WCDMA_RAT__ */
#if defined(__MA_L1__) || defined(__WCDMA_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if !defined(__PRODUCTION_RELEASE__) && defined(__FLC2__)
    ,{
        NVRAM_EF_FLC_STATISTICS_LID,
        NVRAM_EF_FLC_STATISTICS_SIZE,
        NVRAM_EF_FLC_STATISTICS_TOTAL,
        NVRAM_EF_ZERO_DEFAULT,
        NVRAM_ATTR_AVERAGE,
        NVRAM_CATEGORY_USER,
        "MT1b",
        VER(NVRAM_EF_FLC_STATISTICS_LID),
        "FLC Statistics\0",
        NVRAM_RESERVED_VALUE
    }
#endif /* !__PRODUCTION_RELEASE__ && __FLC2__ */

   /* Watch out! There is no comma after last element! */
    ,{ 0xF1F2 }
};

#endif /*__MAUI_BASIC__*/
