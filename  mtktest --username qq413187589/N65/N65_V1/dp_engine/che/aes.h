/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    aes.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   aes software function.
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

#ifndef __AES_H__
#define __AES_H__



#if defined(_MSC_VER)
   #define SWAP(x) (_lrotl(x, 8) & 0x00ff00ff | _lrotr(x, 8) & 0xff00ff00)
   #define GETU32(p) SWAP(*((u32 *)(p)))
   #define PUTU32(ct, st) { *((u32 *)(ct)) = SWAP((st)); }
#else
   #define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
   #define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
#endif

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;

#define MAXKC   (256/32)
#define MAXKB   (256/8)
#define MAXNR   14


#undef FULL_UNROLL



#define AES_ENCRYPT	1
#define AES_DECRYPT	0



#define AES_MAXNR 14
#define AES_BLOCK_SIZE 16

struct aes_key_st {
    unsigned long rd_key[4 *(AES_MAXNR + 1)];
    int rounds;
};
typedef struct aes_key_st AES_KEY;

kal_int32 CHE_AES_block_encrypt(kal_uint8 *ivec, AES_KEY *cipher, kal_uint8 *input, kal_uint32 uInputLen, kal_uint8 *outBuffer, kal_bool first_flag);

kal_int32 CHE_AES_block_decrypt(kal_uint8 *ivec, AES_KEY *cipher, kal_uint8 *input, kal_uint32 uInputLen, kal_uint8 *outBuffer, kal_bool first_flag);


void CHE_AES_unit_encrypt(const kal_uint32 rk[], kal_int32 Nr, const kal_uint8 pt[16], kal_uint8 ct[16]);

void CHE_AES_unit_decrypt(const kal_uint32 rk[], int Nr, const kal_uint8 ct[16], kal_uint8 pt[16]);


void CHE_AES_unit_encrypt(const kal_uint32 rk[], kal_int32 Nr, const kal_uint8 pt[16], kal_uint8 ct[16]);

void CHE_AES_unit_decrypt(const kal_uint32 rk[], int Nr, const kal_uint8 ct[16], kal_uint8 pt[16]);


kal_int32 CHE_AES_ctr_encrypt( unsigned char *nonce, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag);

kal_int32 CHE_AES_ctr_encrypt( unsigned char *nonce, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag);

kal_int32 CHE_AES_f8_encrypt( unsigned char *IV, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag);

kal_int32 CHE_AES_f8_decrypt( unsigned char *IV, AES_KEY *key, unsigned char *data, unsigned long data_len, unsigned char *output, kal_bool first_flag);

#endif /* __AES_H__ */
