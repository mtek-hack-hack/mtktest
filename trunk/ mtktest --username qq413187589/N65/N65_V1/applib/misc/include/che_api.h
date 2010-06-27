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
 *    che_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Cipher/Hash Engine API.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CHE_API_H
#define _CHE_API_H

#include "kal_release.h"
#include "fsal.h"


typedef struct _STCHE_{
#if defined(__HW_CHE__)

    kal_uint8           cheCKey[36]; 
    kal_uint8           cheDataAddr[120]; 

    kal_uint8           *cheKey;
    kal_uint8           *cheIV;
    kal_uint32           cheKeyLength;
    kal_uint32           cheIVLength;
    
    kal_bool            cheResetKeyFlag;
    kal_bool            cheResetIVFlag;
    kal_bool            cheFirstFlag;

#else
    
    kal_uint8           cheLastBlock[16];  
    kal_uint8           cheLastReminder[16];
    kal_uint8           cheKeySchedule[128]; 
    kal_uint32          cheLastLength;
    kal_uint8           *cheLastDstAddr;
     
    kal_uint8           *cheKey;
    kal_uint8           *cheIV;
    kal_uint32           cheKeyLength;
    kal_uint32           cheIVLength;
    
    kal_bool            cheFirstFlag;
	//RSA
    kal_uint8           *modulusN;
    kal_uint32           modulusNLen;
	  kal_uint8           *pubExp;
	  kal_uint32           pubExpLen;
	  kal_uint8           *privExpD;
	  kal_uint32           privExpDLen;
	  kal_uint8           *primeP;
	  kal_uint32           primePLen;
	  kal_uint8           *primeQ;
	  kal_uint32           primeQLen;
	  kal_uint8           *dModPm1;
	  kal_uint32           dModPm1Len;
	  kal_uint8           *dModQm1;
	  kal_uint32           dModQm1Len;
	  kal_uint8           *qInvModP;
	  kal_uint32           qInvModPLen;
    
    //Certicom temporary solution
/*    sb_GlobalCtx sbGloCtx;  
    sb_Context  sbCtx;                
    sb_YieldCtx yieldCtx;                 
    sb_RNGCtx rngCtx;                    

    sb_Params sbParams;          
    sb_Context sbContext;        
    sb_Key sbKey; 
*/
#endif 
/** The structure STCHE is defined to record and maintain the context of CHE */
} STCHE;
/** The structure STCHE is defined to record and maintain the context of CHE */

/** CHE_TYPE define the cipher and hash function algorithm type */
typedef enum {
   CHE_MD5,/**<  */
   CHE_SHA1,/**<  */
   CHE_DES,/**<  */
   CHE_3DES,/**<  */
   CHE_AES,/**<  */

   CHE_MD4,/**<  */
   CHE_MAC_MD5,/**<  */
   CHE_MAC_SHA1,/**<  */
   CHE_RC4,/**<  */

   CHE_RSA/**<  */
} CHE_TYPE;

/** CHE_OPERATION_MODE define the cipher function mode. For hash function, it could be set CHE_MODE_NULL */
typedef enum {
   CHE_MODE_NULL = 0,/**<  */
   CHE_ECB,/**<  */
   CHE_CBC,/**<  */
   CHE_CTR,/**<  */
   CHE_EAX,/**<  */
   CHE_F8,/**<  */
   CHE_SKIP,/**<  */
   CHE_KEY_WRAP,/**<  */
   CHE_KEY_UNWRAP/**<  */
} CHE_OPERATION_MODE;

/** CHE_ACTION define this CHE process should run hash, encipher or decipher */
typedef enum {
   CHE_HASH,/**<  */
   CHE_ENC,/**<  */
   CHE_DEC,/**<  */
   CHE_MAC_HASH,/**<  */

   RSA_PUBLIC_ENC,/**<  */
   RSA_PUBLIC_DEC,/**<  */
   RSA_PRIVATE_ENC,/**<  */
   RSA_PRIVATE_DEC/**<  */
} CHE_ACTION;

/** CHE_KEY_ACTION define the CHE Key process */
typedef enum {
   CHE_GEN_KEY,/**<  */
   CHE_SET_KEY,/**<  */
   CHE_GET_KEY,/**<  */
   CHE_DEL_KEY,/**<  */

   CHE_SET_RSA_N,/**<  */
   CHE_SET_RSA_E,/**<  */
   CHE_SET_RSA_D,/**<  */
   CHE_SET_RSA_P,/**<  */
   CHE_SET_RSA_Q,/**<  */
   CHE_SET_RSA_dModPm1,/**<  */
   CHE_SET_RSA_dModQm1,/**<  */
   CHE_SET_RSA_qInvModP/**<  */

} CHE_KEY_ACTION;






/** DESCRIPTION :
 *     Initialize the CHE_CONTEXT data structure created from AP \n
 *  @param[in] STCHE* che_context one context created from CHE AP
 *  @return None
 */
 
 
void che_init(STCHE* che_context);



/** DESCRIPTION :
 *     Generate, set, get, and destroy key of the specified length \n
 *  @param[in] che_context one context created from CHE AP
 *  @param[in] key_act generate, set, get, and destroy. For RSA, user also could use CHE_SET_RSA_ to set the eight factors to generate the public and private key.
 *  @param[in] key input for generate, set and destroy key. The input has to be 4-byte alignment on ARM platform. Output for get key.
 *  @param[in] key_len original key length
 *  @return None
 */
 
void che_key_action(STCHE* che_context, CHE_KEY_ACTION key_act, kal_uint8 *key, kal_int32 key_len);

/** DESCRIPTION :
 *     Set initial vector for CBC or CTR mode \n
 *  @param[in] che_context one context created from CHE AP
 *  @param[in] iv the original iv, the input has to be 4-byte alignment on ARM platform.
 *  @param[in] iv_len original iv length
 *  @return None
 */
void che_set_iv(STCHE* che_context, kal_uint8 *iv, kal_uint32 iv_len);


/** DESCRIPTION :
 *     Execute cipher and hash process function \n
 *  @param[in] che_context one context created from CHE AP
 *  @param[in] type  CHE_TYPE
 *  @param[in] mode  CHE_OPERATION_MODE
 *  @param[in] act CHE_ACTION
 *  @param[in] source input data source
 *  @param[out] source output dest data
 *  @param[in] source_length input data source length
 *  @param[in] isLastBlock KAL_TRUE is last block. KAL_FLASE is none.
 *  @return  KAL_TRUE  if CHE process successful
 *           KAL_FLASE  if CHE process fail 
 */

kal_bool che_process(STCHE* che_context, 
                     CHE_TYPE type, CHE_OPERATION_MODE mode, CHE_ACTION act,
                     kal_uint8 *source, kal_uint8 *dest, kal_uint32 source_length, kal_bool last_block);


/** DESCRIPTION :
 *     Execute cipher and hash process function \n
 *  @param[in] che_context one context created from CHE AP
 *  @param[in] type  CHE_TYPE
 *  @param[in] mode  CHE_OPERATION_MODE
 *  @param[in] act CHE_ACTION
 *  @param[in] source input STFSAL
 *  @param[out] source output dest data
 *  @return  KAL_TRUE  if CHE process successful
 *           KAL_FLASE  if CHE process fail 
 */
kal_bool che_process_from_file (STCHE *che_context, CHE_TYPE type, CHE_OPERATION_MODE mode, CHE_ACTION act, 
								                 STFSAL *pstFSAL, kal_uint8 *dest);






#endif /* _CHE_API_H */  


/** @}*/
/** @}*/

/*! \page CHE Function Usage Example
1) Using AES to encipher all data at one time:\n\n
 
   SRCHE che_context1;\n\n
   
   che_ init (&che_context1);\n
   che_key_action(&che_context1, CHE_SET_ KEY,  key, key_len);\n
   che_set_iv(&che_context1, iv, iv_len);\n
   che_process(&che_context1, CHE_AES, CHE_ECB, CHE_ENC,  source, dest, source_length, kal_TRUE);\n\n\n\n
 
2) Using AES to encipher 1000 bytes data with separated block:\n\n
   STCHE che_context2;\n\n
   
   che_ init (&che_context2); \n
   che_key_action(&che_context2, CHE_SET_KEY  key2, key_len); \n
   che_set_iv(&che_context2, iv, iv_len);\n
   che_process(&che_context2, CHE_AES, CHE_ECB, CHE_ENC,  source1, dest, 320, kal_FALSE);\n
   che_process(&che_context2, CHE_AES, CHE_ECB, CHE_ENC,  source2, des+320, 200, kal_FALSE);\n
   che_process(&che_context2, CHE_AES, CHE_ECB, CHE_ENC,  source3, dest+520, 280, kal_FALSE); \n
   che_process(&che_context2, CHE_AES, CHE_ECB, CHE_ENC,  source4, dest+800, 200, kal_TRUE);\n\n\n\n
  
3) Using MAC_MD5 to hash two plaintext, each plaintext data with separated block:\n\n
   STCHE che_context3;\n\n
   
   che_ init (&che_context3); \n
   che_key_action(&che_context3, CHE_SET_KEY,  key3, key_len);\n\n
   
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source1, dest1, 320, kal_FALSE);\n
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source1, dest1, 200, kal_FALSE);\n
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source1, dest1, 280, kal_FALSE);\n
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source1, dest1, 200, kal_TRUE);\n
   
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source2, dest2, 320, kal_FALSE);\n
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source2, dest2, 200, kal_FALSE);\n
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source2, dest2, 280, kal_FALSE);\n
   che_process(&che_context3, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,  source2, dest2, 200, kal_TRUE);\n\n\n\n

4) Using AES F8 mode for SRTP package encryption:\n\n
   
   STCHE che_context4, che_context5;\n\n
   
   che_init(&che_context4);\n
   che_key_action(&che_context4, CHE_SET_KEY, key_or_mask, 16);\n
   che_process(&che_context4, CHE_AES, CHE_ECB , CHE_ENC, IV, IV2, 16, KAL_TRUE);\n\n
      
   che_init(&che_context5);\n
   che_key_action(&che_context5, CHE_SET_KEY, aes_session_key, 16);\n
   che_set_iv(&che_str5, IV2, 16);\n
   che_process(&che_str5, CHE_AES, CHE_F8, CHE_ENC, AES_f8_plainText, data_out1, 39, KAL_TRUE);\n\n\n\n
   
   
5) Using RSA for private key decryption:\n\n
   
   STCHE che_context6;\n\n

   che_init(&che_context6);\n\n
   
   che_key_action(&che_context6, CHE_SET_RSA_N, modulusN, 64);\n
   che_key_action(&che_context6, CHE_SET_RSA_E, pubExp, 3);\n
   che_key_action(&che_context6, CHE_SET_RSA_D, privExpD, 64);\n
   che_key_action(&che_context6, CHE_SET_RSA_P, primeP, 32);\n
   che_key_action(&che_context6, CHE_SET_RSA_Q, primeQ, 32);\n
   che_key_action(&che_context6, CHE_SET_RSA_dModPm1, dModPm1, 32);\n
   che_key_action(&che_context6, CHE_SET_RSA_dModQm1, dModQm1, 32);\n\n
   
   che_key_action(&che_context6, CHE_SET_RSA_qInvModP, qInvModP, 32); \n\n

   che_process(&che_str, CHE_RSA, CHE_MODE_NULL, RSA_PRIVATE_DEC, datasrc, data_out1, 64, KAL_TRUE);\n\n\n\n


6) Using STFSAL to set input from file for MD5 hash:\n\n
     
   STFSAL pstFSAL;\n
   kal_uint8 pbBuf[512], output[16];\n
   char * filename = "D:\\temp\\md5inputtest.txt";\n\n
	 

   FSAL_Open(&pstFSAL, filename, FSAL_READ);\n\n

   FSAL_SetBuffer(&pstFSAL, 512, pbBuf);\n\n

   che_init(&che_str);\n
   che_process_from_file(&che_str, CHE_MD5, CHE_MODE_NULL, CHE_HASH,  &pstFSAL, output, KAL_TRUE);\n\n
   
   FSAL_Close(&pstFSAL);\n\n


*/

/*! \page page2 CHE Function Performance
 <div class="che_performance_table">
 <table>
 
 <tr>
 <td>Conditions:\n\n
 1.Time tick precision = 1/32K = 31.25us\n
 2.Test data length is 1024 bytes       \n
 3.Blue color data below are speeded up with HW
 </td>
 </tr>
 
 <tr>
 <th>Functions/Platform</th>
 <th>MT6228
 <th>MT6229
 </th>
 </tr> 
<tr><td>DES ECB mode	                                       </td><td>  <span style="color: rgb(0, 0, 255);">138.28us	  <td><span style="color: rgb(0, 0, 0);">2800.32us		</td></tr>	
<tr><td>DES CBC mode	                                       </td><td>  <span style="color: rgb(0, 0, 255);">139.56us	  <td><span style="color: rgb(0, 0, 0);">2872.19us		</td></tr>
<tr><td>3DES ECB mode	                                       </td><td>  <span style="color: rgb(0, 0, 255);">225.19us	  <td><span style="color: rgb(0, 0, 0);">8194.38us   </td></tr>
<tr><td>3DES CBC mode	                                       </td><td>  <span style="color: rgb(0, 0, 255);">227.03us	  <td><span style="color: rgb(0, 0, 0);">8259.37us   </td></tr>
<tr><td>AES ECB mode 128 Key length	                         </td><td>  <span style="color: rgb(0, 0, 255);">149.47us	  <td><span style="color: rgb(0, 0, 0);">1459.51us		</td></tr>	
<tr><td>AES ECB mode 192 Key length	                         </td><td>  <span style="color: rgb(0, 0, 255);">160.09us	  <td><span style="color: rgb(0, 0, 0);">1694.87us		</td></tr>	
<tr><td>AES ECB mode 256 Key length	                         </td><td>  <span style="color: rgb(0, 0, 255);">170.41us	  <td><span style="color: rgb(0, 0, 0);">1940.63us	  </td></tr>
<tr><td>AES CBC mode 128 Key length	                         </td><td>  <span style="color: rgb(0, 0, 255);">155.56us	  <td><span style="color: rgb(0, 0, 0);">1514.31us		</td></tr>	
<tr><td>AES CBC mode 192 Key length	                         </td><td>  <span style="color: rgb(0, 0, 255);">165.91us	  <td><span style="color: rgb(0, 0, 0);">1750.03us		</td></tr>	
<tr><td>AES CBC mode 256 Key length	                         </td><td>  <span style="color: rgb(0, 0, 255);">176.5us    <td><span style="color: rgb(0, 0, 0);">1996.03us	  </td></tr>
<tr><td>AES CTR mode 128 Key length	                         </td><td>  1990.46us		<td>1990.46us		</td></tr>	
<tr><td>AES CTR mode 192 Key length	                         </td><td>  2007.72us		<td>2007.72us		</td></tr>	
<tr><td>AES CTR mode 256 Key length	                         </td><td>  2243.63us		<td>2243.63us		</td></tr>
<tr><td>AES KeyWrap mode 128 Key length                      </td><td>	1846.87us		<td>1846.87us		</td></tr>
<tr><td>AES KeyWrap mode 192 Key length                      </td><td>	2021.87us		<td>2021.87us		</td></tr>	
<tr><td>AES KeyWrap mode 256 Key length                      </td><td>	2365.63us 	<td>2365.63us   </td></tr>
<tr><td>AES F8 mode	                                         </td><td>  2245.57us		<td>2245.57us		</td></tr>
<tr><td>RC4 Nomal mode	                                     </td><td>  1011.38us		<td>1011.38us		</td></tr>	
<tr><td>RC4 SKIP mode	                                       </td><td>  1194.81us		<td>1194.81us		</td></tr>
<tr><td>MD4	                                                 </td><td>  258.34us		<td>258.34us		</td></tr>	
<tr><td>MD5	                                                 </td><td>  <span style="color: rgb(0, 0, 255);">94.375us	  <td><span style="color: rgb(0, 0, 0);">265.37us		</td></tr>	
<tr><td>HMAC MD5		                                         </td><td>  401.44us    <td>401.44us		</td></tr>	
<tr><td>SHA_1	                                               </td><td>  <span style="color: rgb(0, 0, 255);">100.38us	  <td><span style="color: rgb(0, 0, 0);">1011.75us		</td></tr>
<tr><td>HMAC SHA_1	                                         </td><td>  1366.79us	  <td>1366.79us   </td></tr>
<tr><td>RSA	                                                 </td><td>  14143.75us	<td>14143.75us  </td></tr>
 </table>
 </div>
 */



/*! \page page3 Reference

1)	FEDERAL INFORMATION PROCESSING STANDARDS PUBLICATION U.S. DEPARTMENT OF COMMERCE/national Institute of Standards and Technology 46-3 : DATA ENCRYPTION STANDARD (DES)\n
2)	FEDERAL INFORMATION  PROCESSING STANDARDS PUBLICATION 197 : ADVANCED ENCRYPTION STANDARD (AES)\n
3)	FEDERAL INFORMATION  PROCESSING STANDARDS PUBLICATION 180-2 SECURE HASH STANDARD (SHA)\n
4)	MIT Laboratory for Computer Science and RSA Data Security, Inc. : The MD5 Message-Digest Algorithm\n

*/

