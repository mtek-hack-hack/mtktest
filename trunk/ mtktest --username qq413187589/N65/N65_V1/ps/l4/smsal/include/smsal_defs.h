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
 *	smsal_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains constant and MACRO definitions for SMSAL module.
 *
 * Author:
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/



#ifndef _SMSAL_DEFS_H
#define _SMSAL_DEFS_H

#ifdef __PRODUCTION_RELEASE__
#define SMSAL_ASSERT(x)
#define SMSAL_EXT_ASSERT(a,b,c,d)
#else
#define SMSAL_ASSERT(x)               ASSERT(x)
#define SMSAL_EXT_ASSERT(a,b,c,d)     EXT_ASSERT(a,b,c,d)
#endif

#define SMSAL_MAX_MSG_NUM           (SMSAL_PTR->msg_box_num)
#define SMSLA_MAX_START_UP_MSG_NUM  (4)

#define SMSAL_MAX_PENDING_ACT    (5)  /* 1 for request from L4C to SMSAL, 
                                       * 1 for request from L4C to CB,
                                       * 3 for message received from nwk */

#define SMSAL_MULTI_REC_READ_NUM (10)

#define SMSAL_MAX_PENDING_CNMI   (2)

#define SMSAL_INVALID_RECORD_NO  (0)
#define SMSAL_PROFILE_NAME_LEN   (L4_MAX_NAME)
#define SMSAL_MAILBOX_NAME_LEN   (10)
#define SMSAL_MAX_PROFILE_NUM    (4)

#define SMSAL_HDR_SEPTETS_NUM    (7)
#define SMSAL_CONC_HDR_LEN       (6)
#define SMSAL_ONE_SEG_LEN        (153) /* exclude the user data header 
                                        * for concatenated msg IE */
#define SMSAL_ONE_MSG_OCTET      (140)

/* for CB queueing */
#define SMSAL_CB_ONE_PAGE_SIZE    (93)

#ifdef LOW_COST_SUPPORT
#define SMSAL_CB_MAX_SESSION      (1)
#else
#define SMSAL_CB_MAX_SESSION      (2)
#endif

#define SMSAL_CB_UNUSED_PAGE      (0xff)
#define SMSAL_CB_UNUSED_BLK       (0xff)
#define SMSAL_CB_MISS_SEG_DELIMIT "(.....)"
#define SMSAL_CB_MISS_SEG_DELIMIT_LEN (7) /* not include null char */

/*------------------------------ 
 * Default parameters 
 *------------------------------*/
#define SMSAL_DEFAULT_VP         (71)     /* default validity period:
                                             6 hours */
#define SMSAL_VP_FORMAT          (0x02)   /* Only relative format 
                                             is supported */

#define SMSAL_DEFAULT_ADDR_TYPE  (0x80)   /* TON, NPI=unknow */

#define SMSAL_FO_SR_BITS         (0x20)   /* Status Report request in First Octet */
#define SMSAL_FO_RP_BITS         (0x80)   /* Reply Path request in First Octet */
#define SMSAL_FO_VPF_BITS        (0x18)   /* validation period format */

/*------------------------------
 * Length of SIM EF
 *------------------------------*/
#define SMSAL_SMS_STATUS_LEN     (2)   /* length of a EFsmss */
#define SMSAL_SMS_LEN            (176) /* length of a SIM EFsms record */
#define SMSAL_SMS_ME_LEN         (184) /* length of a ME EFsms record +7 byte SCT +1 pad */
#define SMSAL_SMSP_LEN           (28)  /* length of a EFsmsp record */
#ifdef __CPHS__
#define SMSAL_MWF_LEN            (1)
#endif
#define SMSAL_MAILBOX_NUM_LEN    (14)

/*------------------------------
 * Status byte in SMS
 * RFU shall be set to zero !!
 * 12/27/2002 Kevin 
 *------------------------------*/
#define SMSAL_UNUSED_MSG              (0x00)

/* MT: Receive from network */
#define SMSAL_UNREAD_MSG              (0x03)
#define SMSAL_READ_MSG                (0x01)

/* MO: Sent to network */
#define SMSAL_UNSENT_MSG              (0x07)
#define SMSAL_SENT_NO_SRR             (0x05)
#define SMSAL_SENT_SRR_NOT_RECV       (0x0d)
#define SMSAL_SENT_SRR_RECV_NOT_STO   (0x15)
#define SMSAL_SENT_SRR_RECV_STO       (0x1d)

#define SMSAL_DRAFT_MSG               (0x27)

/*------------------------------
 * Protocol Identifier (PID)
 *------------------------------*/
#define SMSAL_PID_TYPE_0            (0x40)
#define SMSAL_PID_REP_TYPE_1        (0x41)   /* Replace Type 1 */
#define SMSAL_PID_REP_TYPE_2        (0x42)   /* Replace Type 2 */
#define SMSAL_PID_REP_TYPE_3        (0x43)   /* Replace Type 3 */
#define SMSAL_PID_REP_TYPE_4        (0x44)   /* Replace Type 4 */
#define SMSAL_PID_REP_TYPE_5        (0x45)   /* Replace Type 5 */
#define SMSAL_PID_REP_TYPE_6        (0x46)   /* Replace Type 6 */
#define SMSAL_PID_REP_TYPE_7        (0x47)   /* Replace Type 7 */ 
#define SMSAL_PID_RCM               (0x5f)   /* Return Call Message */
#define SMSAL_PID_ANSI_136_RDATA    (0x7c)   /* ANSI-136 R-DATA */
#define SMSAL_PID_ME_DOWNLOAD       (0x7d)   /* ME Data Download */
#define SMSAL_PID_ME_DE_PERSONAL    (0x7e)   /* ME De-personalization */
#define SMSAL_PID_SIM_DOWNLOAD      (0x7f)   /* SIM Data Download */

#define SMSAL_PID_CHECK             (0xC0)
#define SMSAL_PID_MASK              (0xE0)
#define SMSAL_PID_RESERVED          (0x80)

/*------------------------------------
 * Data Coding Scheme (DCS) Checking
 *------------------------------------*/
#define SMSAL_DCS_CODING1         (0xc0)
#define SMSAL_DCS_CODING2         (0xf0)
#define SMSAL_DCS_RESERVE_BIT     (0x08)
#define SMSAL_DCS_ALPHABET_CHECK  (0x0c)
#define SMSAL_DCS_COMPRESS_CHECK  (0x20)

/*---------------------------
 * For other checking
 *---------------------------*/
#define SMSAL_VPF_CHECK           (0x18)

/*------------------------------------
 * Information Element Identifier
 *------------------------------------*/
#define SMSAL_CONC8_MSG_IEI         (0x00)
#define SMSAL_CONC16_MSG_IEI        (0x08)
#define SMSAL_SPECIAL_MSG_IND_IEI   (0x01)

/* EMS */
#define SMSAL_EMS_TEXT_FORMAT_IEI   (0x0a)   /* Text Formating */
#define SMSAL_EMS_PREDEF_SND_IEI    (0x0b)   /* Predefined Sound */
#define SMSAL_EMS_USER_DEF_SND_IEI  (0x0c)   /* User Defined Sound */
#define SMSAL_EMS_PREDEF_ANM_IEI    (0x0d)   /* Predefined Animation */
#define SMSAL_EMS_LARGE_ANM_IEI     (0x0e)   /* Large Animation */
#define SMSAL_EMS_SMALL_ANM_IEI     (0x0f)   /* Small Animation */
#define SMSAL_EMS_LARGE_PIC_IEI     (0x10)   /* Large Picture */
#define SMSAL_EMS_SMALL_PIC_IEI     (0x11)   /* Small Picture */
#define SMSAL_EMS_VAR_PIC_IEI       (0x12)   /* Variable Picture */

/* MISC */
#define SMSAL_APP_PORT8_IEI         (0x04)   /* application port - 8 bit */
#define SMSAL_APP_PORT16_IEI        (0x05)   /* application port - 16 bit */

/*--------------------------------------------
 * Length of SMS peer message header (part)
 *--------------------------------------------*/

/* fo(1), pid(1), dcs(1), scts(7), udl(1), oa_len(1), oa_type(1) */
#define PART_OF_DELIVER_HEADER_LEN     (13)

/* fo(1), mr(1), pid(1), dcs(1), udl(1), da_len(1), da_type(1) */           
#define PART_OF_SUBMIT_HEADER_LEN      (7)     

/* fo(1), mr(1), ra_len(1), ra_type(1), scts(7), dt(7) */           
#define PART_OF_REPORT_HEADER_LEN      (18)
       
/*---------------------------------------------------
 * Internal STATUS representation,
 * bitwise-OR is allowed
 *
 * the lower 4 bits indicate read/unread/sent/unsent
 * the higher 4 bits for other information, 
 * eg. status report request or not
 *---------------------------------------------------*/
#define SMSAL_STATUS_UNREAD   (0x01)       /* received unread */
#define SMSAL_STATUS_READ     (0x02)       /* received read */
#define SMSAL_STATUS_UNSENT   (0x04)       /* stored unsent */
#define SMSAL_STATUS_SENT     (0x08)       /* stored sent */

#define SMSAL_STATUS_INBOX    (0x03)       /* inbox */
#define SMSAL_STATUS_OUTBOX   (0x0c)       /* outbox */
#define SMSAL_STATUS_ALL      (0x0f)       /* all */  

#define SMSAL_STATUS_SRR_NOT_RECV (0x10)   /* status report request, 
                                              not (yet) receive */
#define SMSAL_STATUS_SRR_RECV_NOT_STO   (0x20)   /* status report request, 
                                                    received, but not stored */
#define SMSAL_STATUS_SRR_RECV_STO       (0x30)   /* status report request, 
                                                    received, and stored */

#define SMSAL_STATUS_DRAFT    (0x40)       /* stored draft */

#define SMSAL_MTI_BITS        (0x03)

 /* Information in NMI table  */
 /* table 1 : store and CNMA */
#define SMSAL_MSG_STORE_BITS  (0x01)
#define SMSAL_MSG_CNMA_BITS   (0x02)

 /* table 2 : LMI indication */
 /* table 3 : RMI indication */
#define SMSAL_INDEX_NMI_BITS  (0x01)
#define SMSAL_MSG_NMI_BITS    (0x02)
#define SMSAL_MSG_WAIT_BITS   (0x04)

#define SMSAL_SMSP_DA_BITS    (0xfe)
#define SMSAL_SMSP_SCA_BITS   (0xfd)
#define SMSAL_SMSP_PID_BITS   (0xfb)
#define SMSAL_SMSP_DCS_BITS   (0xf7)
#define SMSAL_SMSP_VP_BITS    (0xef)

#if defined (__CPHS__) /* NEW */
/*-------------------------------------
 * For CPHS Voice Mail Indication
 *-------------------------------------*/
#define SMSAL_CPHS_VM_ADDR_TYPE  (0xd0) 
#define SMSAL_CPHS_VM_SET_BITS   (0x01)
#define SMSAL_CPHS_VM_IND_BITS   (0x0e)
#define SMSAL_CPHS_VM_LINE_BITS  (0x80)
#endif

/*-------------------------------------
 * Timers
 *-------------------------------------*/
                                    
#if defined(__CB__) 
#define SMSAL_CB_TIMER_ITEM  SMSAL_CB_MAX_SESSION 
#else
#define SMSAL_CB_TIMER_ITEM  0
#endif

#define SMSAL_MAX_TIMER_ITEM   (2+SMSAL_CB_TIMER_ITEM) /* 2 for cnma timer  */                                  

                                    
#define SMSAL_CNMA_TIMEOUT_TICK (KAL_TICKS_5_SEC+KAL_TICKS_5_SEC)/* 10 secs */
#define SMSAL_CB_TIMEOUT_TICK   (KAL_TICKS_1_MIN )            /* 1 mins */


/*-------------------------------
 * mem exceed flag values
 *-------------------------------*/
#define SMSAL_MEM_EXCEED         (0xfe)
#define SMSAL_MEM_AVAILABLE      (0xff)

/*---------------------------------------
 * For extracting fields from NVRAM data
 *---------------------------------------*/
#define SMSAL_NVM_MEM1_BITS      (0x07)
#define SMSAL_NVM_MEM2_BITS      (0x38)
#define SMSAL_NVM_BEARER_BITS    (0x03)
#define SMSAL_NVM_CONC_BITS      (0x04)
#define SMSAL_NVM_DISPLAY_BITS   (0x08)
#define SMSAL_NVM_SR_BITS        (0x10)
#define SMSAL_NVM_RP_BITS        (0x20)
#define SMSAL_NVM_CB_BITS        (0x40)
#define SMSAL_NVM_CB_ALL_LANG_BITS (0x80)
#define SMSAL_NVM_RMI_PFILE_ID_BITS (0x18)

#define TP_ADDR2_L4_ADDR_LEN(x)  (((x+1)/2)+1)

#define SMSAL_INVALID_PORT_NUM  (-1)
#define SMSAL_MAX_REG_PORT_NUM  (10)

#if defined(__SMS_ME_STORAGE__)
#define SMSAL_MAX_CONCAT_MSG_SAVE (4)
#endif

#ifdef __MCD__
/*=====================================
 * MCD pack/uppack/alloc/dealloc
 *=====================================*/

#define SMSAL_P(MSG_PTR, FIELD, SUBFIELD) (MSG_PTR->FIELD->SUBFIELD)
#define SMSAL_R(VAR) (VAR)

#define SMSAL_ASN_ALLOC(ALLOC_FUNC, STRUCT, MSG_PTR)

#define SMSAL_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR) {\
   MSG_PTR = (STRUCT*)l4_pun_src_buff; \
   mcd_pseudo_alloc(STRUCTID, l4_pun_src_buff ,sizeof(l4_pun_src_buff)); }

#define SMSAL_DEALLOC(DEALLOC_FUNC, MSG_PTR) 

#define SMSAL_PACK(PACK_FUNC, BITS_FUNC, STRUCTID, MSG_PTR, PEER_BUFF, HDR_SIZE, TLR_SIZE) \
  smsal_mcd_pack(STRUCTID, \
                (kal_uint8*)MSG_PTR, \
                PEER_BUFF, \
                HDR_SIZE, \
                TLR_SIZE);

#define SMSAL_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF,RET_VAL) { \
   MSG_PTR = (STRUCT*)l4_pun_dest_buff; \
   RET_VAL = smsal_mcd_unpack(STRUCTID, PEER_BUFF); }
#else

/*=====================================
 * ASN pack/uppack/alloc/dealloc
 *=====================================*/

typedef unsigned int (*smsal_pack_func_t)(kal_uint8 *, 
                                          void *, 
                                          unsigned int);

typedef unsigned int (smsal_unpack_func_t)(void *, 
                                           kal_uint8 *,
                                           unsigned int, 
                                           unsigned int, 
                                           void *);


#define SMSAL_P(MSG_PTR, FIELD, SUBFIELD) (MSG_PTR->FIELD.SUBFIELD)
#define SMSAL_R(VAR) (&VAR)

#define SMSAL_ASN_ALLOC(ALLOC_FUNC, STRUCT, MSG_PTR) {\
 MSG_PTR = get_ctrl_buffer(sizeof(STRUCT)); \
 ALLOC_FUNC(MSG_PTR); } 


#define SMSAL_ALLOC(ALLOC_FUNC, STRUCTID, STRUCT, MSG_PTR) { \
MSG_PTR = get_ctrl_buffer(sizeof(STRUCT)); \
ALLOC_FUNC((STRUCT*)MSG_PTR); } 

#define SMSAL_DEALLOC(DEALLOC_FUNC, MSG_PTR) { \
   DEALLOC_FUNC(MSG_PTR); \
   free_ctrl_buffer(MSG_PTR); }

#define SMSAL_PACK(PACK_FUNC, BITS_FUNC, STRUCTID, MSG_PTR, PEER_BUFF, HDR_SIZE, TLR_SIZE) \
   smsal_asn_pack(PACK_FUNC, \
                  MSG_PTR, \
                  (kal_uint16)((BITS_FUNC(MSG_PTR)+7)/8), \
                  PEER_BUFF, \
                  HDR_SIZE, \
                  TLR_SIZE);

#define SMSAL_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF) \
smsal_asn_unpack(UNPACK_FUNC, MSG_PTR, PEER_BUFF)             

#endif /* __MCD__ */

#endif /* _SMSAL_DEFS_H */


