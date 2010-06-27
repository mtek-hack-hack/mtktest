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
 *	ems_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes of .
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _EMS_DEFS_H
#define _EMS_DEFS_H


#define EMS_CNTX(X) (ems_cntx_g.X)

#ifdef __PRODUCTION_RELEASE__
#define EMS_ASSERT(x)
#define EMS_EXT_ASSERT(a,b,c,d)
#else
   #ifdef  EMS_UT
   #define ASSERT(expr) if(!(expr)) { printf("\nAssert fail: %s %d\n", basename(__FILE__), __LINE__); while(1); }
   #define EXT_ASSERT(expr, e1, e2, e3) if(!(expr)) { printf("\nAssert fail: %s %d\n", basename(__FILE__), __LINE__); while(1); }
   #endif
#define EMS_ASSERT(x)               ASSERT(x)
#ifdef EMS_ON_WIN32
#define EMS_EXT_ASSERT(a,b,c,d)     ASSERT(a)
#else
#define EMS_EXT_ASSERT(a,b,c,d)     EXT_ASSERT(a,b,c,d)
#endif
#endif


#define EMS_P(x,y) (x->y)
#define EMS_R(x)   (x)

#if defined(__MTK_TARGET__) || defined(MMI_ON_WIN32) /* target and PC simulator */
#define EMS_DBG_(x) 
#else  /* specific for MoDIs */
#define EMS_DBG_(x) x
#endif

#ifdef EMS_UT

#ifndef __MTK_TARGET__
/* UT && WIN23 */
#define EMS_PRINT printf  
#define EMS_PRINT_STR printf  

#else

/* UT && Target */
#define EMS_PRINT(fmt, arg) /* empty */
#define EMS_PRINT_STR(str)  kal_print(str)   

#endif/* (__MTK_TARGET__)*/

#else

/* NOT UT */
#define EMS_PRINT(fmt, arg) /* empty */
#define EMS_PRINT_STR(str)  /* empty */  

#endif /* EMS_UT */

#define EMS_ONE_MSG_OCTET      (140)
#define EMS_ONE_MSG_LEN        (160)

/* #define EMS_HDR_SEPTETS_NUM    (7) */
/* #define EMS_CONC_HDR_LEN (5)       */

#define EMS_UDHL_HDR_LEN_OCTET        (1)
#define EMS_8BIT_CONC_HDR_LEN_OCTET   (5)
#define EMS_16BIT_CONC_HDR_LEN_OCTET  (6)
#define EMS_PORT_HDR_LEN_OCTET        (6)


/*------------------------------------
 * Information Element Identifier
 *------------------------------------*/
#define EMS_CONC8_MSG_IEI     (0x00)
#define EMS_CONC16_MSG_IEI    (0x08)

/* MISC */
#define EMS_APP_PORT8_IEI      (0x04)   /* application port - 8 bit */
#define EMS_APP_PORT16_IEI     (0x05)   /* application port - 16 bit */

/* EMS */
#define EMS_TEXT_FORMAT_IEI    (0x0a)   /* Text Formating */
#define EMS_PREDEF_SND_IEI     (0x0b)   /* Predefined Sound */
#define EMS_USER_DEF_SND_IEI   (0x0c)   /* User Defined Sound */
#define EMS_PREDEF_ANM_IEI     (0x0d)   /* Predefined Animation */
#define EMS_LARGE_ANM_IEI      (0x0e)   /* Large Animation */
#define EMS_SMALL_ANM_IEI      (0x0f)   /* Small Animation */
#define EMS_LARGE_PIC_IEI      (0x10)   /* Large Picture */
#define EMS_SMALL_PIC_IEI      (0x11)   /* Small Picture */
#define EMS_VAR_PIC_IEI        (0x12)   /* Variable Picture */

#define EMS_EXT_OBJ_IEI        (0x14)   /* Extended Object */
#define EMS_REUSED_EXT_OBJ_IEI (0x15)   /* Reused Extended Object */
#define EMS_COMPRESSED_IEI     (0x16)   /* Compression Control */
#define EMS_OBJ_DIST_IND_IEI   (0x17)   /* Object Distribution Indicator */

/* Type of extended object */
#define EMS_EXT_PREDEF_SND     (0x00)   /* Predefined Sound */
#define EMS_EXT_USER_DEF_SND   (0x01)   /* User Defined Sound */
#define EMS_EXT_BW_PIC         (0x02)   /* B&W Picture */
#define EMS_EXT_2BIT_PIC       (0x03)   /* 2-bit greyscale Picture */
#define EMS_EXT_6BIT_PIC       (0x04)   /* 6-bit greyscale Picture */
#define EMS_EXT_PREDEF_ANM     (0x05)   /* Predefined Animation */
#define EMS_EXT_BW_ANM         (0x06)   /* B&W Animation */
#define EMS_EXT_2BIT_ANM       (0x07)   /* 2-bit greyscale Animation */
#define EMS_EXT_6BIT_ANM       (0x08)   /* 6-bit greyscale Animation */
#define EMS_EXT_VCARD          (0x09)   /* vCard */
#define EMS_EXT_VCALENDAR      (0x0a)   /* vCalendar */
#define EMS_EXT_POLY_SND       (0x0c)   /* Polyphonic melody */

/* #define EMS_TXTFMT_IEDL            (4) */
#define EMS_TXTFMT_IEDL            (3)

#define EMS_PREDEF_IEDL            (2)  /* IE Data length of Predefined obj */

#define EMS_TYPE_OBJ_DIST_IND      (99)  /* for object distribute indicator */
                                         /* EMS library internal use. */


#define EMS_MAX_SEG_NUM  (EMS_CNTX(max_seg_num)) 
#define EMS_MAX_OBJECT   (EMS_CNTX(max_obj_num)) 
#define EMS_MAX_EMS_DATA   (2)
#define EMS_MAX_TEXT_BUF_SIZE   (EMS_CNTX(max_seg_num) * 153 *2 +4)

#ifdef __EMS_REL5__
#define EMS_ASM_MALLOC(size) EMS_asm_malloc(size)
#define EMS_ASM_MFREE(ptr)   EMS_asm_mfree(ptr)
#endif

#define EMS_MALLOC(size) EMS_malloc(size)
#define EMS_MFREE(ptr)   EMS_mfree(ptr)
#define EMS_BUFF_FOOTPRINT   0xF2F2F2F2


/*================================
 * Macros 
 *================================*/

#define IS_EMS_DATA_NEED(type) ((type == EMS_TYPE_PREDEF_ANM || type ==EMS_TYPE_PREDEF_SND) ? \
                                 KAL_FALSE : KAL_TRUE)

#define IS_EMS_DATA_NEED_IEI(iei) ((iei == EMS_PREDEF_SND_IEI || iei ==EMS_PREDEF_ANM_IEI ) ? \
                                 KAL_FALSE : KAL_TRUE)

#define IS_EMS_DATA_NEED_EXT_TYPE(type) ((type == EMS_EXT_PREDEF_SND || type ==EMS_EXT_PREDEF_ANM ) ? \
                                 KAL_FALSE : KAL_TRUE)

#define EXT_OBJ_INFO_P(_obj, _var)  (((EMSExtObjInfo *)((kal_uint8*)_obj+sizeof(EMSObject)))->_var)

#define EMS_INIT_CHECK if(EMS_CNTX(isInit) == KAL_FALSE) return EMS_NOT_INITIALIZED
#define IS_EMS_INIT EMS_CNTX(isInit) 

#define SET_ACTIVE_EMS_ID(id) EMS_CNTX(activeEMSDataID) = id
#define IS_EMS_DATA_VALID(emsData) ((emsData->id < EMS_MAX_EMS_DATA && \
                                    EMS_CNTX(isEMSDataUsed[emsData->id]) == KAL_TRUE) \
                                    ? KAL_TRUE : KAL_FALSE)

#define EMS_DATA_CHECK(emsData) {EMS_INIT_CHECK; \
                                 if(IS_EMS_DATA_VALID(emsData) == KAL_FALSE) \
                                    return EMS_INVALID_EMS_DATA;}


#define GetTxtLenInChar(dcs,numOfOctet) ((dcs == SMSAL_UCS2_DCS) ? numOfOctet : (numOfOctet >> 1))
#define GetTxtLenInOctet(dcs,numOfChar) ((dcs == SMSAL_UCS2_DCS) ? numOfChar : (numOfChar << 1 ))

#define EMS_RELEASE_NOT_FINISH_OBJ(_internal_) if((_internal_)->notFinishedObject != NULL) \
                                               { ReleaseEMSObject((_internal_)->notFinishedObject); \
                                               (_internal_)->notFinishedObject = NULL; }

#define is_TPUD_avail(int_d, udh_len, txt_len, len_n)  ((((udh_len) + (txt_len) + (len_n)) > \
                                                        (int_d)->MaxLenPerSeg) \
                                                         ? KAL_FALSE : KAL_TRUE)

#define IS_FOLLOW_EMS_TXT_FMT(txt_offset_,txt_fmt_obj) ((txt_offset_ == txt_fmt_obj->OffsetToText+ \
                                             EMS_P(txt_fmt_obj->data,text_format.textLength)) \
                                             ? KAL_TRUE : KAL_FALSE)

#define BETWEEN_EMS_TXT_FMT(txt_offset_,txt_fmt_obj) ((txt_offset_ < txt_fmt_obj->OffsetToText+ \
                                            EMS_P(txt_fmt_obj->data,text_format.textLength)) \
                                            ? KAL_TRUE : KAL_FALSE)

#define SWITCH_TO_NEXT_EMS_OBJ(emsData) if(emsData->CurrentPosition.Object->next != NULL && \
   emsData->CurrentPosition.Object->next->OffsetToText < emsData->CurrentPosition.OffsetToText) \
                  emsData->CurrentPosition.Object = emsData->CurrentPosition.Object->next;             

#define IS_CURRENT_OBJ_PRESENT(emsData) ((emsData->CurrentPosition.Object == NULL) \
                                          ? KAL_FALSE : KAL_TRUE)

#define CURR_OBJ_OFFSET(emsData) (emsData->CurrentPosition.Object->OffsetToText)
#define CURR_TXT_OFFSET(emsData) (emsData->CurrentPosition.OffsetToText)
#define EMS_OBJ_OFFSET(object) (object->OffsetToText)

#define TXT_FMT_LEN(obj) (obj->data->text_format.textLength)
#define IS_TXT_FMT_OBJ(obj) ((obj->Type==EMS_TYPE_TEXT_FORMAT)?KAL_TRUE:KAL_FALSE)
#define IS_CURR_POS_AT_HEAD(emsData) (((emsData->CurrentPosition.Object == NULL) &&\
                                       (emsData->CurrentTextFormatObj == NULL) &&\
                                       (emsData->CurrentPosition.OffsetToText == 0)) \
                                       ? KAL_TRUE : KAL_FALSE)
#define IS_CURR_POS_AT_END(emsData) ((((kal_uint32*)emsData->CurrentPosition.Object ==\
                                                    (kal_uint32*)emsData->listTail) &&\
                                    (emsData->CurrentPosition.OffsetToText == emsData->textLength)) \
                                    ? KAL_TRUE : KAL_FALSE)

#define TXT_FMT_OBJ_END(obj) (EMS_OBJ_OFFSET(obj)+TXT_FMT_LEN(obj))

#define GET_PREV_TXT_FMT_OBJ(tf_obj) while(tf_obj != NULL && IS_TXT_FMT_OBJ(tf_obj) == KAL_FALSE) \
                                            tf_obj = tf_obj->prev
#define GET_NEXT_TXT_FMT_OBJ(tf_obj) while(tf_obj != NULL && IS_TXT_FMT_OBJ(tf_obj) == KAL_FALSE) \
                                            tf_obj = tf_obj->next

//#define IS_OBJ_BEYOND_CURR_POS(emsData) ((emsData->CurrentPosition.Object->OffsetToText > emsData->CurrentPosition.OffsetToText) ? KAL_TRUE : KAL_FALSE)



#endif /* _EMS_DEFS_H */


