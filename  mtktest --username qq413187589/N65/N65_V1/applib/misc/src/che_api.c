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
 *    che_api.c
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
#include "che_api.h"
#include "che_sw_driver.h"
#include "app_buff_alloc.h"

static kal_mutexid che_mutex;

void che_init(STCHE* che_context){
  
   //STCHE* che_context = (STCHE*) (che_context->context);
   
   ASSERT(che_context != NULL);
  
    #if defined(__HW_CHE__)
        che_context->cheKey = NULL;         
        che_context->cheIVLength = 0;   
        che_context->cheIV = NULL;   
        che_context->cheKeyLength = 0;    
                          
        che_context->cheResetKeyFlag = KAL_FALSE;  
        che_context->cheResetIVFlag  = KAL_FALSE;     
        che_context->cheFirstFlag = KAL_TRUE; 
    #else
        che_context->cheKey = NULL;         
        che_context->cheIVLength = 0;   
        che_context->cheIV = NULL;     
        che_context->cheKeyLength = 0;    
        che_context->cheLastLength = 0;
        che_context->cheFirstFlag = KAL_TRUE; 
        che_context->cheLastDstAddr = NULL;
    #endif
}



void che_key_action(STCHE* che_context, CHE_KEY_ACTION key_act, kal_uint8 *key, kal_int32 key_len){  
    kal_int32 i;    

    ASSERT((che_context != NULL) && (key != NULL));
    
    
    switch (key_act){
       case CHE_GEN_KEY :
          for(i = (key_len-1); i >= 0; i--){
		          key[i] = rand() % 256;
          }
          che_context->cheKey = key;
          che_context->cheKeyLength = key_len;
       break;

       case CHE_SET_KEY :
          che_context->cheKey = key;
          che_context->cheKeyLength = key_len;
       break;

       case CHE_GET_KEY :
          key = che_context->cheKey; 
          key_len = che_context->cheKeyLength ;
       break;

       case CHE_DEL_KEY :
          che_context->cheKey = NULL;
          che_context->cheKeyLength = 0;
       break;
#ifndef __HW_CHE__
	   case CHE_SET_RSA_N :
           che_context->modulusN = key;
           che_context->modulusNLen = key_len;
       break;

	   case CHE_SET_RSA_E :
           che_context->pubExp = key;
           che_context->pubExpLen = key_len;
       break;
	   
	   case CHE_SET_RSA_D :
           che_context->privExpD = key;
           che_context->privExpDLen = key_len;
       break;
	   
	   case CHE_SET_RSA_P :
           che_context->primeP = key;
           che_context->primePLen = key_len;
       break;
	   
	   case CHE_SET_RSA_Q :
           che_context->primeQ = key;
           che_context->primeQLen = key_len;
       break;
	   
	   case CHE_SET_RSA_dModPm1 :
           che_context->dModPm1 = key;
           che_context->dModPm1Len = key_len;
       break;

	   case CHE_SET_RSA_dModQm1 :
           che_context->dModQm1 = key;
           che_context->dModQm1Len = key_len;
       break;
	   
	   case CHE_SET_RSA_qInvModP :
           che_context->qInvModP = key;
           che_context->qInvModPLen = key_len;
#endif
       break;
       default:
          ASSERT(0);
		  break;
    }


    #if defined(__HW_CHE__)
        che_context->cheResetKeyFlag = KAL_TRUE;  
    #endif
  
}


void che_set_iv(STCHE* che_context, kal_uint8 *iv, kal_uint32 iv_len){
    
    //STCHE* che_context = (STCHE*) che_context->context;
    
    ASSERT((che_context != NULL) && (iv != NULL));
    
    che_context->cheIV = iv;
    che_context->cheIVLength = iv_len;

    #if defined(__HW_CHE__)       
       che_context->cheResetIVFlag = KAL_TRUE;     
    #endif  
  
}


kal_bool che_process(STCHE* che_context, 
                     CHE_TYPE type, CHE_OPERATION_MODE mode, CHE_ACTION act,
                     kal_uint8 *source, kal_uint8 *dest, kal_uint32 source_length,  kal_bool last_block)
{
  
  //STCHE* che_context = (STCHE*) che_context->context;
  kal_bool rtnValue = KAL_TRUE;
  
  ASSERT( (che_context != NULL) && (source != NULL) && (dest != NULL) );
//move to case AES(4-bytes alignment) and HW input???  ASSERT( 0 == (((kal_uint32)source) & 0x03));

  #if defined(__HW_CHE__)
     if (!che_mutex){
        che_mutex = kal_create_mutex("che_mutex");
     }
  #endif
  
  switch (type){

//DES            
     case CHE_DES: 

        #if defined(__HW_CHE__)
            kal_take_mutex(che_mutex);
        
           //set key//
           if(che_context->cheResetKeyFlag == KAL_TRUE){
              convert_des_Key(che_context->cheKey, che_context->cheCKey);
              che_context->cheResetKeyFlag = KAL_FALSE;
           }
           
           //set iv//
           if(mode == CHE_CBC){ 
              if (che_context->cheResetIVFlag == KAL_TRUE){ 
                 des_set_iv(che_context->cheIV);
                 che_context->cheResetIVFlag = KAL_FALSE;
              }
           }
           // HW DES processes //
           rtnValue = che_hw_des(che_context, source, dest, source_length, type, mode, act, last_block);                   
           
           kal_give_mutex(che_mutex);
        #else
           // SW DES processes //
           rtnValue = che_sw_des(che_context, type, mode, act, source, dest, source_length, last_block);
        #endif  
         
     break;
        
         
//3DES            
     case CHE_3DES:
      
        #if defined(__HW_CHE__)
           kal_take_mutex(che_mutex);
        
           //set key//
           if(che_context->cheResetKeyFlag==KAL_TRUE){
              convert_3des_Key(che_context->cheKey, che_context->cheCKey);
              che_context->cheResetKeyFlag = KAL_FALSE;
           }
           
           //set iv//
           if(mode == CHE_CBC){ 
              if (che_context->cheResetIVFlag==KAL_TRUE){ 
                 des_set_iv(che_context->cheIV);
                 che_context->cheResetIVFlag = KAL_FALSE;
              }
           }
           
           // HW DES processes //
           rtnValue = che_hw_des(che_context, source, dest, source_length, type, mode, act, last_block);                   
           
           kal_give_mutex(che_mutex);     
        #else
           // HW DES processes //
           rtnValue = che_sw_des(che_context, type, mode, act, source, dest, source_length, last_block);
        #endif  
        
     break; 

//AES            
     case CHE_AES:  
     	  ASSERT( 0 == (((kal_uint32)source) & 0x03));
        #if defined(__HW_CHE__)
           kal_take_mutex(che_mutex);
        
           //set key//
           if(che_context->cheResetKeyFlag == KAL_TRUE){
              if (che_context->cheKeyLength == 16){
                 convert_aes_128_key(che_context->cheKey, che_context->cheCKey);}
              else if (che_context->cheKeyLength == 24){
                 convert_aes_192_key(che_context->cheKey, che_context->cheCKey);}
              else if (che_context->cheKeyLength == 32){
                 convert_aes_256_key(che_context->cheKey, che_context->cheCKey);}
              else{
                 return KAL_FALSE;}
                
                che_context->cheResetKeyFlag = KAL_FALSE;
              }
           
           //set iv//
           if(mode == CHE_CBC){ 
              if (che_context->cheResetIVFlag == KAL_TRUE){ 
                 aes_set_iv(che_context->cheIV);
                 che_context->cheResetIVFlag = KAL_FALSE;
              }
           }
           // HW AES processes //

           che_hw_aes(che_context, source, dest, source_length, mode, act, last_block);
           
           kal_give_mutex(che_mutex);
        #else
           // SW AES processes //
           rtnValue = che_sw_aes(che_context, mode, act, source, dest, source_length, last_block);
        #endif

     break; 
     

//MD5
     case CHE_MD5:
         #if defined(__HW_CHE__)
            kal_take_mutex(che_mutex);
            
            // HW hash processes //
            che_hw_hash(che_context, type, source, dest, source_length, last_block);
            
            kal_give_mutex(che_mutex);
         #else
            // HW hash processes //
            rtnValue = che_sw_md5(che_context, source, dest, source_length, last_block);   
         #endif      
                  
     break;
        
//SHA_1
     case CHE_SHA1:
         #if defined(__HW_CHE__)
            kal_take_mutex(che_mutex);
            
            // HW hash processes //
            che_hw_hash(che_context, type, source, dest, source_length, last_block);
            
            kal_give_mutex(che_mutex);
         #else
            // SW hash processes //
            rtnValue = che_sw_sha_1(che_context, source, dest, source_length, last_block);
         #endif  
               
     break;   

//RC4
#ifndef __HW_CHE__
     case CHE_RC4: 
         rtnValue = che_sw_rc4(che_context, mode, source, dest, source_length, last_block);   
     break;   
      
//MD4
     case CHE_MD4: 
         rtnValue = che_sw_md4(che_context, source, dest, source_length, last_block);        
     break;

//MAC_MD5
     case CHE_MAC_MD5: 
         rtnValue = che_sw_mac_md5(che_context, source, dest, source_length, last_block);    
     break;

//MAC_SHA1 
     case CHE_MAC_SHA1: 
         rtnValue = che_sw_mac_sha1(che_context, source, dest, source_length, last_block);   
     break;

//RSA 
     case CHE_RSA: 
         rtnValue = che_sw_rsa(che_context, act, source, dest, source_length, last_block);  
     break;
#endif
                        
     default:
       rtnValue = KAL_FALSE;
            
   }//switch (type)

   if(last_block==KAL_TRUE){

      #if defined(__HW_CHE__)                          
        che_context->cheResetKeyFlag = KAL_FALSE;  
        che_context->cheResetIVFlag  = KAL_FALSE;     
        che_context->cheFirstFlag = KAL_TRUE; 
      #else        
        che_context->cheLastLength = 0;
        che_context->cheFirstFlag = KAL_TRUE; 
        che_context->cheLastDstAddr = NULL;

        //Certicom temporary solution
        /*che_context->sbGloCtx = NULL; 
        che_context->sbCtx = NULL;                
        che_context->yieldCtx = NULL;                 
        che_context->rngCtx = NULL;                     
        che_context->sbParams = NULL;          
        che_context->sbContext = NULL;       
        che_context->sbKey = NULL; */

    #endif
   }
   
   return rtnValue;
   
}//che_process()


kal_bool che_process_from_file(STCHE *che_context, 
                               CHE_TYPE type, CHE_OPERATION_MODE mode, CHE_ACTION act, 
							                 STFSAL *pstFSAL, kal_uint8 *dest){
    
   #define BUFFER_SIZE 2048
    
   kal_uint32  fileSize;
   kal_uint8*  pu8Buffer;
   kal_bool    bRtnVal;
    	
	 pu8Buffer = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * BUFFER_SIZE);
	  
   FSAL_GetFileSize(pstFSAL, &fileSize);

   while(fileSize >= BUFFER_SIZE){
    
	    FSAL_Read(pstFSAL, pu8Buffer, BUFFER_SIZE);
      
      if ((bRtnVal = che_process(che_context, type, mode, act, pu8Buffer, dest, BUFFER_SIZE, KAL_FALSE)) == KAL_FALSE){
         goto CHE_EXIT;
      }

      fileSize -= BUFFER_SIZE;
   }

   FSAL_Read(pstFSAL, pu8Buffer, fileSize);  
   bRtnVal = che_process(che_context, type, mode, act, pu8Buffer, dest, fileSize, KAL_TRUE);

CHE_EXIT:
    free_ctrl_buffer(pu8Buffer);
    return bRtnVal;
}
