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
 *    che_sw_driver.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Cipher/Hash Engine software driver.
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


#ifndef __HW_CHE__


#include "che_sw_driver.h"
#include "che_api.h"


/*
*************************************************************************
* SW DES processes
*************************************************************************
*/

#define DES_BLOCK_SIZE    8

// src XOR pIV 64bits to dst //
#define DES_BLOCK_XOR( dst, src, pIV )                                                                                                \
do {                                                                                                                                  \
    *((kal_uint32*)((kal_uint32)(dst) + 0)) = (*((kal_uint32*)((kal_uint32)(src) + 0))) ^ (*((kal_uint32*)((kal_uint32)(pIV) + 0)));  \
    *((kal_uint32*)((kal_uint32)(dst) + 4)) = (*((kal_uint32*)((kal_uint32)(src) + 4))) ^ (*((kal_uint32*)((kal_uint32)(pIV) + 4)));  \
} while(0)                                                                                                    


// copy 64bits from addr src to dst //
#define DES_BLOCK_ASSIGN( dst, src )                                                  \
do {                                                                                  \
    *((kal_uint32*)((kal_uint32)(dst) + 0)) = *((kal_uint32*)((kal_uint32)(src) + 0));\
    *((kal_uint32*)((kal_uint32)(dst) + 4)) = *((kal_uint32*)((kal_uint32)(src) + 4));\
} while(0)                                                                          

   
// for CBC mode, before encipher, plain text have to XOR with IV //
#define ENC_XOR_IV(dst, src)                                                        \
do {                                                                                \
   if (act == CHE_ENC){                                                             \
        if(che_context->cheFirstFlag==KAL_TRUE){                                    \
           pIV = che_context->cheIV;                                                \
           che_context->cheFirstFlag = KAL_FALSE;                                   \
        }                                                                           \
        else{                                                                       \
          pIV = pLastAddr;                                                          \
          pLastAddr += DES_BLOCK_SIZE;                                              \
        }                                                                           \
        DES_BLOCK_XOR(dst, src, pIV);                                               \
   }                                                                                \
} while(0)                                                                          
                                                                                    

// for CBC mode, after decipher, encrypted data have to XOR with IV //                                                                                    
#define DEC_XOR_IV(encryptedData)                                                   \
do {                                                                                \
   if (act == CHE_DEC){                                                             \
       if(che_context->cheFirstFlag==KAL_TRUE) {                                    \
          pIV = che_context->cheIV;                                                 \
          che_context->cheFirstFlag = KAL_FALSE;                                    \
       }                                                                            \
       else{                                                                        \
          pIV = che_context->cheLastBlock;                                          \
       }                                                                            \
       DES_BLOCK_XOR(pLastAddr, pLastAddr, pIV);                                    \
       DES_BLOCK_ASSIGN(che_context->cheLastBlock, encryptedData );                 \
       pLastAddr += DES_BLOCK_SIZE;                                                 \
   }                                                                                \
} while(0)                                                                          
                                                    

// for 3DES, have to execute DES encipher->decipher->encipher triple times//
#define TriDES(plaintextTriDes)                                                                                                      \
do {                                                                                    \
    if(act==CHE_ENC){                                                                   \
      CHE_des_key_sched((C_Block *)test_key1,ks);                                       \
      CHE_des_ecb_encrypt((C_Block *)plaintextTriDes, (C_Block *)data_dst, ks, DES_ENCRYPT);                                         \
      CHE_des_key_sched((C_Block *)test_key2,ks);                                       \
      CHE_des_ecb_encrypt((C_Block *)data_dst, (C_Block *)pTemp, ks, DES_DECRYPT);      \
      CHE_des_key_sched((C_Block *)test_key3,ks);                                       \
      CHE_des_ecb_encrypt((C_Block *)pTemp, (C_Block *)data_dst, ks, DES_ENCRYPT);      \
    }                                                                                   \
    else{                                                                               \
      CHE_des_key_sched((C_Block *)test_key3,ks);                                       \
      CHE_des_ecb_encrypt((C_Block *)plaintextTriDes, (C_Block *)data_dst, ks, DES_DECRYPT);                                         \
      CHE_des_key_sched((C_Block *)test_key2,ks);                                       \
      CHE_des_ecb_encrypt((C_Block *)data_dst, (C_Block *)pTemp, ks, DES_ENCRYPT);      \
      CHE_des_key_sched((C_Block *)test_key1,ks);                                       \
      CHE_des_ecb_encrypt((C_Block *)pTemp, (C_Block *)data_dst, ks, DES_DECRYPT);      \
    }                                                                                   \
} while(0)                                                                          



// DES kernel processes, including DES/3DES type,  ECB/CBC mode  //
#define DESKernel(plaintext)                                                              \
do {                                                                                      \
   if (type == CHE_DES){                                                                  \
       CHE_des_key_sched((C_Block *)che_context->cheKey,ks);                              \
       if(mode == CHE_ECB){                                                               \
          if (che_context->cheFirstFlag) che_context->cheFirstFlag = KAL_FALSE;           \
          CHE_des_ecb_encrypt((C_Block *)plaintext, (C_Block *)data_dst, ks, DES_CIPHER); \
          pLastAddr += DES_BLOCK_SIZE;                                                    \
       }                                                                                  \
       else{                                                                              \
          if ( CHE_ENC == act ){                                                          \
             kal_uint8 desTemp[8];                                                        \
             ENC_XOR_IV(desTemp, plaintext) ;                                             \
             CHE_des_ecb_encrypt((C_Block *)desTemp, (C_Block *)data_dst, ks, DES_CIPHER);\
          }                                                                               \
          else{                                                                           \
             CHE_des_ecb_encrypt((C_Block *)plaintext, (C_Block *)data_dst, ks, DES_CIPHER); \
             DEC_XOR_IV(plaintext);                                                       \
         }                                                                                \
       }                                                                                  \
    }                                                                                     \
    else{                                                                                 \
       if(mode == CHE_ECB){                                                               \
          if (che_context->cheFirstFlag) che_context->cheFirstFlag = KAL_FALSE;           \
          TriDES(plaintext);                                                              \
          pLastAddr += DES_BLOCK_SIZE;                                                                                              \
       }                                                                                  \
       else{                                                                              \
          if ( CHE_ENC == act ){                                                          \
             kal_uint8 desTemp[8];                                                        \
             ENC_XOR_IV(desTemp, plaintext) ;                                             \
             TriDES(desTemp);                                                                                                       \
          }                                                                               \
          else{                                                                           \
             TriDES(plaintext);                                                                                                     \
             DEC_XOR_IV(plaintext);                                                       \
         }                                                                                \
       }                                                                                  \
    }                                                                                     \
    data_dst += DES_BLOCK_SIZE;                                                           \
} while(0)                                                                                
                                                                                      


/*****************************************************************************
 * FUNCTION
 *   che_sw_des
 *
 * DESCRIPTION
 *   Execute DES/3DES ECB/CBC function.
 *
 * PARAMETERS
 *   che_context              [IN] : one context created from CHE AP
 *   type                [IN] : type for DES/3DES/AES/MD5/SHA1
 *   mode                [IN] : mode for ECB/CBC/CTR 
 *   aes_length          [IN] : CHE_KEY_LENGTH_NULL
 *   act                 [IN] : action for HASH/Encipher/Decipher
 *   data_src            [IN] : input data source
 *   data_dst            [OUT] : output dest data
 *   length              [IN] : input data source length
 *   last_block          [IN] : KAL_TRUE is last block. KAL_FLASE is none.
 *
 * RETURNS
 *   KAL_TRUE : if DES process successful
 *   KAL_FLASE : if DES process fail.
 *****************************************************************************/
kal_bool che_sw_des(STCHE* che_context, CHE_TYPE type, CHE_OPERATION_MODE mode, CHE_ACTION act,
                    kal_uint8 *data_src, kal_uint8 *data_dst, kal_int32 length, kal_bool last_block){
                                                                                                      
  kal_uint8 test_key1[8], test_key2[8], test_key3[8];  
  kal_uint8  pTemp[8];                               
  des_key_schedule *ks;//, ks1, ks2, ks3;                                                 
  
  kal_uint8 *pIV, *pLastRemider, *pLastBlock, *pLastAddr; // get array ptr for using in for loop //
  kal_int32  i, DES_CIPHER; 
  kal_uint32  fill_length;
  
  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
  
  (des_key_schedule*) ks = (des_key_schedule*) che_context->cheKeySchedule;
  
  // 3DES Key scheduling //
  if (type == CHE_3DES){
     // get three keys for triple DES //
        memcpy((&(test_key1[0])), (&(che_context->cheKey[0])), 8);
        memcpy((&(test_key2[0])), (&(che_context->cheKey[8])), 8);
        memcpy((&(test_key3[0])), (&(che_context->cheKey[16])), 8);
  }
  
  // for unify DES kernal process function interface //
  if(act==CHE_ENC) DES_CIPHER = DES_ENCRYPT;
  else if(act==CHE_DEC) DES_CIPHER = DES_DECRYPT;
  else return KAL_FALSE;
  
  // If it's first block, initialize the last destination address as the output address //
  if(che_context->cheFirstFlag==KAL_TRUE){
     che_context->cheLastDstAddr = data_dst;
  }

  pLastAddr = che_context->cheLastDstAddr;
  pLastBlock = che_context->cheLastBlock;

  // Two conditions to fill out remider block //
  // Either there are remider in last block, or the length of this inupt source is less then DES one block //
  if((che_context->cheLastLength > 0) || (length < DES_BLOCK_SIZE)){
    
     // decide the total filled length //
     fill_length = (che_context->cheLastLength + length <= DES_BLOCK_SIZE) ? length : (DES_BLOCK_SIZE - che_context->cheLastLength);
         
     pLastRemider = &(che_context->cheLastReminder[che_context->cheLastLength]);

     for( i = fill_length; i > 0; i--){
        *pLastRemider++ = *data_src++;
     }
     
     che_context->cheLastLength += fill_length; // last length for reminder block add fill_length // 
     
     // If it's last block, padding the block, then encrypt/decrypt DES processes //
     if((last_block == KAL_TRUE) && (che_context->cheLastLength < DES_BLOCK_SIZE)){
     
       fill_length = DES_BLOCK_SIZE - che_context->cheLastLength;
       for(i=fill_length; i>0; i--){
         *pLastRemider++ = fill_length;
       }
     
       DESKernel(che_context->cheLastReminder); 
       return KAL_TRUE;
     }
     
     length -= fill_length;                // current input data length sub fill_length //
  }

  


 

  // if the reminder block is not filled out, return //
  // else, encrypt this block                        //
  if(che_context->cheLastLength){
    if(che_context->cheLastLength < DES_BLOCK_SIZE){
      return KAL_TRUE;
    }
    DESKernel(che_context->cheLastReminder);    
  }
  
  // while loop, encrypt/decrypt DES processes block by block //
  while(length >= DES_BLOCK_SIZE){
     DESKernel(data_src);    
     data_src += DES_BLOCK_SIZE;
     length -= DES_BLOCK_SIZE;
  }

  // after while loop DES processes, fill out the units to reminder block for next input data DES processes //
  pLastRemider = che_context->cheLastReminder;
  for(i = length; i > 0; i--){
    *pLastRemider++ = *data_src++;
  }       
  
  // If it's last block, padding the block, then encrypt/decrypt DES processes //
  if(last_block == KAL_TRUE){

    fill_length = DES_BLOCK_SIZE - length;
    for(i=fill_length; i>0; i--){
      *pLastRemider++ = fill_length;
    }

    DESKernel(che_context->cheLastReminder); 
  }

  // record the last output address, and the number of reminder units //
  che_context->cheLastDstAddr = pLastAddr; 
  che_context->cheLastLength = length;

  return KAL_TRUE;    
  
}


/*
*************************************************************************
* SW AES processes
*************************************************************************
*/
#define AES_BLOCK_SIZE    16

// AES kernel processes, including AES128/192/256 type,  ECB/CBC mode  //
#define AESKernel(plaintext, cipher_length)                                                                                                \
do {                                                                                                                        \
   if (mode == CHE_ECB) che_context->cheIV = NULL;                                                                               \
   if(act==CHE_ENC){                                                                                                        \
      aes_decryption_key.rounds = CHE_AES_setup_enc_key((kal_uint32* ) aes_decryption_key.rd_key, che_context->cheKey, che_context->cheKeyLength*8);    \
      if (CHE_CTR == mode){                                                                                                                             \
         CHE_AES_ctr_encrypt(che_context->cheIV, &aes_decryption_key, plaintext, cipher_length, data_dst, che_context->cheFirstFlag);                   \
      }                                                                                                                     \
      else if(CHE_F8 == mode) {                                                                                                                         \
         CHE_AES_f8_encrypt(che_context->cheIV, &aes_decryption_key, plaintext, cipher_length, data_dst, che_context->cheFirstFlag);                    \
      }                                                                                                                                                 \
      else{                                                                                                                 \
         CHE_AES_block_encrypt(che_context->cheIV, &aes_decryption_key, plaintext, cipher_length, data_dst, che_context->cheFirstFlag);                       \
      }                                                                                                                     \
   }                                                                                                                        \
   else if(act==CHE_DEC){                                                                                                   \
      if (CHE_CTR == mode){                                                                                                                             \
	     aes_decryption_key.rounds = CHE_AES_setup_enc_key((kal_uint32* ) aes_decryption_key.rd_key, che_context->cheKey, che_context->cheKeyLength*8); \
         CHE_AES_ctr_decrypt(che_context->cheIV, &aes_decryption_key, plaintext, cipher_length, data_dst, che_context->cheFirstFlag);                   \
      }                                                                                                                                                 \
      else if(CHE_F8 == mode) {                                                                                                                         \
	      aes_decryption_key.rounds = CHE_AES_setup_enc_key((kal_uint32 *) aes_decryption_key.rd_key, che_context->cheKey, che_context->cheKeyLength*8);\
          CHE_AES_f8_decrypt(che_context->cheIV, &aes_decryption_key, plaintext, cipher_length, data_dst, che_context->cheFirstFlag);                   \
      }                                                                                                                     \
      else{                                                                                                                 \
         aes_decryption_key.rounds = CHE_AES_setup_dec_key((kal_uint32 *) aes_decryption_key.rd_key, che_context->cheKey, che_context->cheKeyLength*8); \
         CHE_AES_block_decrypt(che_context->cheIV, &aes_decryption_key, plaintext, cipher_length, data_dst, che_context->cheFirstFlag);                       \
      }                                                                                                                     \
   }                                                                                                                        \
   if (che_context->cheFirstFlag) che_context->cheFirstFlag = KAL_FALSE;                                                              \
   pLastAddr += cipher_length;                                                                                             \
   data_dst += cipher_length;                                                           \
} while(0)                                                                                                                  



/*****************************************************************************
 * FUNCTION
 *   che_sw_aes
 *
 * DESCRIPTION
 *   Execute AES128/192/256 ECB/CBC function.
 *
 * PARAMETERS
 *   che_context              [IN] : one context created from CHE AP
 *   type                [IN] : type for DES/3DES/AES/MD5/SHA1
 *   mode                [IN] : mode for ECB/CBC/CTR 
 *   aes_length          [IN] : aes key length sequence for 128/192/256
 *   act                 [IN] : action for HASH/Encipher/Decipher
 *   data_src            [IN] : input data source
 *   data_dst            [OUT] : output dest data
 *   length              [IN] : input data source length
 *   last_block          [IN] : KAL_TRUE is last block. KAL_FLASE is none.
 *
 * RETURNS
 *   KAL_TRUE : if DES process successful
 *   KAL_FLASE : if DES process fail.
 *****************************************************************************/
kal_bool che_sw_aes(STCHE* che_context, CHE_OPERATION_MODE mode, CHE_ACTION act, 
                    kal_uint8 *data_src, kal_uint8 *data_dst, kal_int32 length, kal_bool last_block){
  
  AES_KEY aes_decryption_key;
  
  kal_uint8 *pIV, *pLastRemider, *pLastBlock, *pLastAddr;  // get array ptr for using in for loop //
  kal_uint32  fill_length, cipher_length;
  kal_int32 i; 
  
  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
  
  
   // If it's first block, initialize the last destination address as the output address //
  if(che_context->cheFirstFlag==KAL_TRUE){
     che_context->cheLastDstAddr = data_dst;
  }
  
  pLastAddr = che_context->cheLastDstAddr; 
  pLastBlock = che_context->cheLastBlock; 
  if((CHE_F8 == mode)||(CHE_CTR == mode)){
	  if (last_block == KAL_FALSE){
          return KAL_FALSE;
	  }

    AESKernel(data_src, length);
	  return KAL_TRUE; 
  }
  if(CHE_KEY_WRAP == mode){
     if (last_block == KAL_FALSE){
          return KAL_FALSE;
	   }
	   aes_decryption_key.rounds = CHE_AES_setup_enc_key((kal_uint32* ) aes_decryption_key.rd_key, che_context->cheKey,  che_context->cheKeyLength*8);
     CHE_AES_WRAP(&aes_decryption_key,  length/8, data_src, data_dst);	
     return KAL_TRUE; 
  }   
  if(CHE_KEY_UNWRAP == mode){
	   if (last_block == KAL_FALSE){
          return KAL_FALSE;
	   }
     aes_decryption_key.rounds = CHE_AES_setup_dec_key((kal_uint32* ) aes_decryption_key.rd_key, che_context->cheKey,  che_context->cheKeyLength*8);
     CHE_AES_UNWRAP(&aes_decryption_key,  (length-8)/8, data_src, data_dst);	
	   return KAL_TRUE; 
  }   
  // Two conditions to fill out remider block //
  // Either there are remider in last block, or the length of this inupt source is less then AES one block //
  if((che_context->cheLastLength > 0) || (length < AES_BLOCK_SIZE)){
    
     // decide the total filled length //
     fill_length = (che_context->cheLastLength + length <= AES_BLOCK_SIZE) ? length : (AES_BLOCK_SIZE - che_context->cheLastLength);
     
     pLastRemider = &(che_context->cheLastReminder[che_context->cheLastLength]);
     
     for( i = fill_length; i > 0; i--){
        *pLastRemider++ = *data_src++;
     }
     
     che_context->cheLastLength += fill_length; // last length for reminder block add fill_length // 
     
     // If it's last block, padding the block, then encrypt/decrypt DES processes //
     if((last_block == KAL_TRUE) && (che_context->cheLastLength < AES_BLOCK_SIZE)){
     
       fill_length = AES_BLOCK_SIZE - che_context->cheLastLength;
       for(i=fill_length; i>0; i--){
         *pLastRemider++ = fill_length;
       }
     
       AESKernel(che_context->cheLastReminder, AES_BLOCK_SIZE); 
       
       
       return KAL_TRUE;
     }
     
     length -= fill_length;                // current input data length sub fill_length //  
  }
  
  

   

  // if the reminder block is not filled out, return //
  // else, encrypt this block                        //
  if(che_context->cheLastLength){
    if(che_context->cheLastLength < AES_BLOCK_SIZE){
      return KAL_TRUE;
    }
    AESKernel(che_context->cheLastReminder, AES_BLOCK_SIZE);  
    
  }
  

  // while loop, encrypt/decrypt AES processes block by block //
//  while(length >= AES_BLOCK_SIZE){
     if(length >= AES_BLOCK_SIZE){  //instead of whileloop//
        fill_length = length - ( length % 16 );
        AESKernel(data_src, fill_length);    
     }
     data_src += AES_BLOCK_SIZE;
     //length -= AES_BLOCK_SIZE;
     length -= fill_length;
  

  
  // after AES processes, fill out the units to reminder block for next input data AES processes //
  pLastRemider = che_context->cheLastReminder;
  for(i = length; i > 0; i--){
    *pLastRemider++ = *data_src++;
  }       
  
  // If it's last block, padding the block, then encrypt/decrypt AES processes //
  if(last_block == KAL_TRUE){

    fill_length = AES_BLOCK_SIZE - length;
    for(i=fill_length; i>0; i--){
      *pLastRemider++ = fill_length;
    }

    AESKernel(che_context->cheLastReminder, AES_BLOCK_SIZE);   

    
  }

  // record the last output address, and the number of reminder units //
  che_context->cheLastDstAddr = pLastAddr; 
  che_context->cheLastLength = length;

  return KAL_TRUE;    
  

}


/*****************************************************************************
 * FUNCTION
 *   che_sw_md5
 *
 * DESCRIPTION
 *   Execute MD5 hash function.
 *
 * PARAMETERS
 *   che_context              [IN] : one context created from CHE AP
 *   data_src            [IN] : input data source
 *   data_dst            [OUT] : output dest data
 *   length              [IN] : input data source length
 *   last_block          [IN] : KAL_TRUE is last block. KAL_FLASE is none.
 *
 * RETURNS
 *   KAL_TRUE : if DES process successful
 *   KAL_FLASE : if DES process fail.
 *****************************************************************************/



kal_bool che_sw_md5(STCHE* che_context, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block) 
{
  static md5_context md5_str;

  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
  
  if (che_context->cheFirstFlag == KAL_TRUE){
     CHE_md5_init(&md5_str);
     che_context->cheFirstFlag = KAL_FALSE;
  }
  
  CHE_md5_append(&md5_str, data_src, length);
  
  if(last_block == KAL_TRUE){
    CHE_md5_finish(&md5_str, data_dst);
  }  
  return KAL_TRUE;
}


kal_bool che_sw_mac_md5(STCHE* che_context, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block){
  static md5_context mac_md5_str;
  kal_uint8 k_ipad[64], k_opad[64], tmpbuf[20];
  kal_int32 i;

  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
    if(che_context->cheKeyLength>64){

     CHE_md5_init(&mac_md5_str);
     CHE_md5_append( &mac_md5_str, che_context->cheKey, che_context->cheKeyLength );
     CHE_md5_finish( &mac_md5_str, tmpbuf );
     
	 che_context->cheKey=tmpbuf;
	 che_context->cheKeyLength = 16;

  }
  if (che_context->cheFirstFlag == KAL_TRUE){
     memset( k_ipad, 0x36, 64 );
     for( i = 0; i < che_context->cheKeyLength; i++ ){
        k_ipad[i] ^= che_context->cheKey[i];
     }
     CHE_md5_init( &mac_md5_str );
     CHE_md5_append( &mac_md5_str, k_ipad, 64 );
     che_context->cheFirstFlag = KAL_FALSE;
  }
  CHE_md5_append( &mac_md5_str, data_src, length );
  if(last_block == KAL_TRUE){
     memset( k_opad, 0x5C, 64 );
     for( i = 0; i < che_context->cheKeyLength; i++ ){
        k_opad[i] ^= che_context->cheKey[i];
     }
     CHE_md5_finish( &mac_md5_str, tmpbuf );
     CHE_md5_init( &mac_md5_str );
     CHE_md5_append( &mac_md5_str, k_opad, 64 );
     CHE_md5_append( &mac_md5_str, tmpbuf, 16 );
     CHE_md5_finish( &mac_md5_str, data_dst );
     memset( k_ipad, 0, 64 );
     memset( k_opad, 0, 64 );
     memset( tmpbuf, 0, 16 );
     memset( &mac_md5_str, 0, sizeof( md5_context ) );
  }
  return KAL_TRUE;
}
kal_bool che_sw_md4(STCHE* che_context, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block){
  static md4_context md4_str;
  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
  if (che_context->cheFirstFlag == KAL_TRUE){
     CHE_md4_init( &md4_str );
     che_context->cheFirstFlag = KAL_FALSE;
  }
  CHE_md4_append( &md4_str, data_src, length );
  if(last_block == KAL_TRUE){
    CHE_md4_finish(&md4_str, data_dst);
  }  
  return KAL_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *   che_sw_sha_1
 *
 * DESCRIPTION
 *   Execute SHA_1 hash function.
 *
 * PARAMETERS
 *   che_context              [IN] : one context created from CHE AP
 *   data_src            [IN] : input data source
 *   data_dst            [OUT] : output dest data
 *   length              [IN] : input data source length
 *   last_block          [IN] : KAL_TRUE is last block. KAL_FLASE is none.
 *
 * RETURNS
 *   KAL_TRUE : if DES process successful
 *   KAL_FLASE : if DES process fail.
 *****************************************************************************/


kal_bool che_sw_sha_1(STCHE* che_context, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block) 
{
  static sha1_context sha1_str;
  
  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
  
  if (che_context->cheFirstFlag == KAL_TRUE){
     CHE_sha1_Init(&sha1_str);
     che_context->cheFirstFlag = KAL_FALSE;
  }
  
  CHE_sha1_append(&sha1_str, data_src, length);
  
  if(last_block == KAL_TRUE){
     CHE_sha1_finish(&sha1_str, data_dst);
  }
  return KAL_TRUE;
}
kal_bool che_sw_mac_sha1(STCHE* che_context, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block){
  static sha1_context mac_sha1_str;
  kal_uint8 k_ipad[64], k_opad[64], tmpbuf[20];
  kal_int32 i;
  ASSERT((che_context != NULL) && (data_src != NULL) && (data_dst != NULL));
  if(che_context->cheKeyLength>64){

     CHE_sha1_Init(&mac_sha1_str);
     CHE_sha1_append( &mac_sha1_str, che_context->cheKey, che_context->cheKeyLength );
     CHE_sha1_finish( &mac_sha1_str, tmpbuf );
     
	 che_context->cheKey=tmpbuf;
	 che_context->cheKeyLength = 20;

  }
  if (che_context->cheFirstFlag == KAL_TRUE){
     memset( k_ipad, 0x36, 64 );
     for( i = 0; i < che_context->cheKeyLength; i++ ){
        k_ipad[i] ^= che_context->cheKey[i];
     }
     CHE_sha1_Init( &mac_sha1_str );
     CHE_sha1_append( &mac_sha1_str, k_ipad, 64 );
     che_context->cheFirstFlag = KAL_FALSE;
  }
  CHE_sha1_append( &mac_sha1_str, data_src, length );
  if(last_block == KAL_TRUE){
     memset( k_opad, 0x5C, 64 );
     for( i = 0; i < che_context->cheKeyLength; i++ ){
        k_opad[i] ^= che_context->cheKey[i];
     }
     CHE_sha1_finish( &mac_sha1_str, tmpbuf );
     CHE_sha1_Init( &mac_sha1_str );
     CHE_sha1_append( &mac_sha1_str, k_opad, 64 );
     CHE_sha1_append( &mac_sha1_str, tmpbuf, 20 );
     CHE_sha1_finish( &mac_sha1_str, data_dst );
     memset( k_ipad, 0, 64 );
     memset( k_opad, 0, 64 );
     memset( tmpbuf, 0, 20 );
     memset( &mac_sha1_str, 0, sizeof( sha1_context ) );
  }
  return KAL_TRUE;
}
kal_bool che_sw_rc4(STCHE* che_context, CHE_OPERATION_MODE mode, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block){
    che_rc4(data_src, length, che_context->cheKey, che_context->cheKeyLength, mode, data_dst);
    return KAL_TRUE;
}
kal_bool che_sw_rsa(STCHE* che_context, CHE_ACTION act, kal_uint8* data_src, kal_uint8* data_dst, kal_int32 length, kal_bool last_block){
	rsa_context rsa;
    memset( &rsa, 0, sizeof( rsa ) );
    rsa.len = length;
    mpi_read( &rsa.N , che_context->modulusN, 16, che_context->modulusNLen );
    mpi_read( &rsa.E , che_context->pubExp, 16, che_context->pubExpLen );
    mpi_read( &rsa.D , che_context->privExpD, 16, che_context->privExpDLen );
    mpi_read( &rsa.P , che_context->primeP, 16, che_context->primePLen );
    mpi_read( &rsa.Q , che_context->primeQ, 16,che_context->primeQLen );
    mpi_read( &rsa.DP, che_context->dModPm1, 16,che_context->dModPm1Len );
    mpi_read( &rsa.DQ, che_context->dModQm1, 16,che_context->dModQm1Len );
    mpi_read( &rsa.QP, che_context->qInvModP, 16,che_context->qInvModPLen );
	if( rsa_check_pubkey(  &rsa ) != 0 || rsa_check_privkey( &rsa ) != 0 ){
	    ASSERT(0);
	}
	switch (act){
       case RSA_PUBLIC_ENC: 
         if( rsa_public_encrypt( &rsa, data_src, length, data_dst, length ) != 0 ){
             ASSERT(0);
		     }
       break;
       case RSA_PUBLIC_DEC: 
         if( rsa_public_decrypt( &rsa, data_src, length, data_dst, length ) != 0 ){
             ASSERT(0);
		 }
       break;
       case RSA_PRIVATE_ENC: 
         if( rsa_private_encrypt( &rsa, data_src, length, data_dst, length ) != 0 ){
             ASSERT(0);
		 }
       break;
	   case RSA_PRIVATE_DEC: 
         if( rsa_private_decrypt( &rsa, data_src, length, data_dst, length ) != 0 ){
             ASSERT(0);
		 }
	   break;
       default:
         return KAL_FALSE;
    }
    return KAL_TRUE;
}
#endif /* __HW_CHE__ */ 