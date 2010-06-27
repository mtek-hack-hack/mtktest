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
 *    che_hw_driver.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Cipher/Hash Engine hardware driver.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * Power done CHE_PDN,CHE_PDN_ENABLE(0), when exit che_hw_init()
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *    Rev 1.1   Aug 18 2005 22:34:58   mtk00288
 * revise prototype
 * Resolution for 12288: [Video][Add feature]Support non-16x width file
 *
 *    Rev 1.0   Jun 06 2005 12:57:30   BM
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifdef __HW_CHE__

#include "drv_comm.h"
#include "che_api.h"
#include "che_hw.h"
#include "intrCtrl.h"
#include "drv_hisr.h"

typedef struct {
   kal_uint32  che_hw_status[(CHE_HW_STATUS_SIZE+3)/4];
   kal_bool    che_last_block;      /*check ciphter/cipher_next*/
   CHE_TYPE    che_type;            /*Current cipher type*/
   kal_bool    keep_dst_addr;       /*UPDS*/
   kal_uint32  keep_dst_addr_value; /*UPDS address*/
   kal_uint32  total_length;
   kal_uint8   che_last_handle;     /*Previous latest finish handle*/
}CHE_GLB_DATA_STRUCT;



typedef struct {
      kal_uint32  len;
      kal_uint32  duration;
}che_waste_time;
che_waste_time    record_time[2048];
kal_uint32        record_time_index;
kal_uint32        min_length=0xffffffff;

kal_uint32           che_hw_setting[MAX_CHE_HW_SETTING];
CHE_GLB_DATA_STRUCT  che_glb_data[CHE_MAX_CHANNEL];
CHE_CB_DATA_STRUCT   che_cb;



static void CHE_TurnOnClock(kal_bool clockOn){
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();

   if (clockOn){
      DRV_WriteReg(CHE_PDN_CLR,CHE_PDN_BIT);
      #ifndef __MAUI_BASIC__
         L1SM_SleepDisable(che_cb.che_sm_handle);
      #endif
   }
   else{
      DRV_WriteReg(CHE_PDN_SET,CHE_PDN_BIT);
      #ifndef __MAUI_BASIC__
          L1SM_SleepEnable(che_cb.che_sm_handle);
      #endif
   }
   RestoreIRQMask(savedMask);
}



void CHE_HISR(void)
{
   kal_uint32 status;
   status = DRV_Reg32(CHE_INTSTA);

   if (status == CHE_INTSTA_OK)
   {
      kal_set_eg_events(che_cb.event,1,KAL_OR);
   }
   else
   {
      ASSERT(0);
   }
}

void CHE_RESUME_LISR(void)
{
   IRQMask(IRQ_CHE_CODE);
   drv_active_hisr(DRV_CHE_HISR_ID);
}

void CHE_DONE_LISR(void)
{
   IRQMask(IRQ_CHE_CODE);
   drv_active_hisr(DRV_CHE_HISR_ID);
}

void che_enable_done_intr(void)
{
   kal_set_eg_events(che_cb.event,0,KAL_AND);  //2: NU_AND
   IRQ_Register_LISR(IRQ_CHE_CODE, CHE_DONE_LISR,"CHEdone");
   IRQUnmask(IRQ_CHE_CODE);
}

void che_enable_resume_intr(void)
{
   kal_set_eg_events(che_cb.event,0,KAL_AND);  //2: NU_AND
   IRQ_Register_LISR(IRQ_CHE_CODE, CHE_RESUME_LISR,"CHEdone");
   IRQUnmask(IRQ_CHE_CODE);
}

void che_wait_status_complete(kal_uint32 data_length, kal_bool is_done_status)
{
   kal_uint32 event_group;
   kal_uint32 aaa_time1;
   kal_uint32 aaa_time2;
   kal_uint32 aaa_time3;

   if(data_length > ISR_ENABLE_DATA_LENGTH)
   {
      che_enable_done_intr();
      kal_retrieve_eg_events(che_cb.event,1,KAL_OR_CONSUME
            ,&event_group,KAL_SUSPEND);
   }
   else
   {
      aaa_time1 = drv_get_current_time();
      if (is_done_status)
      {
         CHE_WAIT_STAT_OK();
      }
      else
      {
         CHE_WAIT_STAT_RESUME();
      }

      aaa_time2 = drv_get_current_time();


      aaa_time3=drv_get_duration_tick(aaa_time1,aaa_time2);
      if (aaa_time3 > 32*2)
      {
         if (data_length < min_length)
         {
            min_length = data_length;
         }
      }
   }
}


static kal_mutexid app_che_mutex;

void che_hw_init(void)
{
   che_cb.che_lastest_finish_handle=0xff;
#ifndef __MAUI_BASIC__
   che_cb.che_sm_handle = L1SM_GetHandle();
#endif
   che_cb.che_machie_running = KAL_FALSE;
   che_cb.che_glb_handle = 0;

   if (che_cb.event == NULL)
      che_cb.event = kal_create_event_group("CHEEVT");

   DRV_Register_HISR(DRV_CHE_HISR_ID, CHE_HISR);

   CHE_TurnOnClock(KAL_TRUE);
   CHE_REGSET_START(CHE_START_CLEAR);
   CHE_REGSET_START(CHE_START_DONE);
   CHE_REGSET_INTEN((CHE_INTEN_OK|CHE_INTEN_FAIL));
   CHE_TurnOnClock(KAL_FALSE);
   IRQ_Register_LISR(IRQ_CHE_CODE, CHE_DONE_LISR,"CHEdone");
   IRQSensitivity(IRQ_CHE_CODE,LEVEL_SENSITIVE);

    //Julie 01/23
    app_che_mutex = kal_create_mutex("che_mutex");
}


void che_update_key0_1(kal_uint32 key0, kal_uint32 key1)
{
   CHE_REGSET_KEY0(key0);
   CHE_REGSET_KEY1(key1);
   CHE_REGSET_START(CHE_START_UPK01);
   CHE_REGSET_START(CHE_START_DONE);
}

void che_update_key0_3(kal_uint32 key0, kal_uint32 key1, kal_uint32 key2, kal_uint32 key3)
{
   CHE_REGSET_KEY0(key0);
   CHE_REGSET_KEY1(key1);
   CHE_REGSET_KEY2(key2);
   CHE_REGSET_KEY3(key3);
   CHE_REGSET_START((CHE_START_UPK01|CHE_START_UPK23));
   CHE_REGSET_START(CHE_START_DONE);
}

void che_update_key4_5(kal_uint32 key4, kal_uint32 key5)
{
   CHE_REGSET_KEY4(key4);
   CHE_REGSET_KEY5(key5);
   CHE_REGSET_START(CHE_START_UPK45);
   CHE_REGSET_START(CHE_START_DONE);
}

void che_update_key4_7(kal_uint32 key4, kal_uint32 key5, kal_uint32 key6, kal_uint32 key7)
{
   CHE_REGSET_KEY4(key4);
   CHE_REGSET_KEY5(key5);
   CHE_REGSET_KEY6(key6);
   CHE_REGSET_KEY7(key7);
   CHE_REGSET_START((CHE_START_UPK45|CHE_START_UPK67));
   CHE_REGSET_START(CHE_START_DONE);
}

void che_generate_ckey(kal_uint32 ckey_addr)
{
   CHE_REGSET_CKEY(ckey_addr);
   CHE_REGSET_START((CHE_START_WKEY|CHE_START_STUD));
   che_wait_status_complete(0,KAL_TRUE);
   CHE_REGSET_START(CHE_START_DONE);
}

void che_retrieve_ckey(kal_uint32 ckey_addr)
{
   CHE_REGSET_CKEY(ckey_addr);
   CHE_REGSET_START((CHE_START_RKEY|CHE_START_STUD));
   che_wait_status_complete(0,KAL_TRUE);
   CHE_REGSET_START(CHE_START_DONE);
}

void che_slowdown(void)
{
   DRV_WriteReg32(CHE_SDRAT, 200);
}

void che_recover(void)
{
   DRV_WriteReg32(CHE_SDRAT, 0);
}


void convert_des_Key(kal_uint8 *key, kal_uint32 *ckey){

    CHE_TurnOnClock(KAL_TRUE);

    CHE_REGSET_START(CHE_START_CLEAR);
    CHE_REGSET_START(CHE_START_DONE);

    if ((((kal_uint32)key)&0x03)==0){
        che_update_key0_1(*(kal_uint32 *)(key+0x0), *(kal_uint32 *)(key+0x4) );
    }
    else{
        che_update_key0_1(( (*(key+0x0)) | (*(key+0x1)<<8) | (*(key+0x2)<<16) | (*(key+0x3)<<24) ),
                         ( (*(key+0x4)) | (*(key+0x5)<<8) | (*(key+0x6)<<16) | (*(key+0x7)<<24) ) );

    }

    che_generate_ckey((kal_uint32)ckey);  /*ckey*/
    CHE_TurnOnClock(KAL_FALSE);
}




void convert_3des_Key(kal_uint8 *key, kal_uint32 *ckey){

    CHE_TurnOnClock(KAL_TRUE);

    CHE_REGSET_START(CHE_START_CLEAR);
    CHE_REGSET_START(CHE_START_DONE);

    if ((((kal_uint32)key)&0x03)==0){
        che_update_key0_3(*(kal_uint32 *)(key+0x0),
                          *(kal_uint32 *)(key+0x4),
                          *(kal_uint32 *)(key+0x8),
                          *(kal_uint32 *)(key+0xc) );
        che_update_key4_5(*(kal_uint32 *)(key+0x10),
                          *(kal_uint32 *)(key+0x14) );
    }
    else{
        che_update_key0_3(( (*(key+0x0)) | (*(key+0x1)<<8) | (*(key+0x2)<<16) | (*(key+0x3)<<24) ),
                          ( (*(key+0x4)) | (*(key+0x5)<<8) | (*(key+0x6)<<16) | (*(key+0x7)<<24) ),
                          ( (*(key+0x8)) | (*(key+0x9)<<8) | (*(key+0xa)<<16) | (*(key+0xb)<<24) ),
                          ( (*(key+0xc)) | (*(key+0xd)<<8) | (*(key+0xe)<<16) | (*(key+0xf)<<24) ) );
        che_update_key4_5(( (*(key+0x10)) | (*(key+0x11)<<8) | (*(key+0x12)<<16) | (*(key+0x13)<<24) ),
                          ( (*(key+0x14)) | (*(key+0x15)<<8) | (*(key+0x16)<<16) | (*(key+0x17)<<24) ) );
    }
    che_generate_ckey((kal_uint32)ckey);  /*ckey*/
    CHE_TurnOnClock(KAL_FALSE);
}

void convert_aes_Key(kal_uint8 *key, kal_uint8 *ckey){

    CHE_TurnOnClock(KAL_TRUE);

    CHE_REGSET_START(CHE_START_CLEAR);
    CHE_REGSET_START(CHE_START_DONE);


    if ((((kal_uint32)key)&0x03)==0){
        che_update_key0_3(*(kal_uint32 *)(key+0x0),
                          *(kal_uint32 *)(key+0x4),
                          *(kal_uint32 *)(key+0x8),
                          *(kal_uint32 *)(key+0xc) );
     }
     else{
        che_update_key0_3(( (*(key+0x0)) | (*(key+0x1)<<8) | (*(key+0x2)<<16) | (*(key+0x3)<<24) ),
                          ( (*(key+0x4)) | (*(key+0x5)<<8) | (*(key+0x6)<<16) | (*(key+0x7)<<24) ),
                          ( (*(key+0x8)) | (*(key+0x9)<<8) | (*(key+0xa)<<16) | (*(key+0xb)<<24) ),
                          ( (*(key+0xc)) | (*(key+0xd)<<8) | (*(key+0xe)<<16) | (*(key+0xf)<<24) ) );
    }
    che_generate_ckey((kal_uint32)ckey);  /*ckey*/
    CHE_TurnOnClock(KAL_FALSE);
}

void convert_aes_128_key(kal_uint8 *key, kal_uint8 *ckey){

    CHE_TurnOnClock(KAL_TRUE);

    CHE_REGSET_START(CHE_START_CLEAR);
    CHE_REGSET_START(CHE_START_DONE);

    if ((((kal_uint32)key)&0x03)==0){
        che_update_key0_3(*(kal_uint32 *)(key+0x0),
                          *(kal_uint32 *)(key+0x4),
                          *(kal_uint32 *)(key+0x8),
                          *(kal_uint32 *)(key+0xc) );
     }
     else{
        che_update_key0_3(( (*(key+0x0)) | (*(key+0x1)<<8) | (*(key+0x2)<<16) | (*(key+0x3)<<24) ),
                          ( (*(key+0x4)) | (*(key+0x5)<<8) | (*(key+0x6)<<16) | (*(key+0x7)<<24) ),
                          ( (*(key+0x8)) | (*(key+0x9)<<8) | (*(key+0xa)<<16) | (*(key+0xb)<<24) ),
                          ( (*(key+0xc)) | (*(key+0xd)<<8) | (*(key+0xe)<<16) | (*(key+0xf)<<24) ) );
     }
    che_generate_ckey((kal_uint32)ckey);  /*ckey*/
    CHE_TurnOnClock(KAL_FALSE);
}

void convert_aes_192_key(kal_uint8 *key, kal_uint8 *ckey){

    CHE_TurnOnClock(KAL_TRUE);

    CHE_REGSET_START(CHE_START_CLEAR);
    CHE_REGSET_START(CHE_START_DONE);


    if ((((kal_uint32)key)&0x03)==0){
        che_update_key0_3(*(kal_uint32 *)(key+0x0),
                          *(kal_uint32 *)(key+0x4),
                          *(kal_uint32 *)(key+0x8),
                          *(kal_uint32 *)(key+0xc) );
        che_update_key4_5(*(kal_uint32 *)(key+0x10),
                          *(kal_uint32 *)(key+0x14) );
    }
    else{
        che_update_key0_3(( (*(key+0x0)) | (*(key+0x1)<<8) | (*(key+0x2)<<16) | (*(key+0x3)<<24) ),
                          ( (*(key+0x4)) | (*(key+0x5)<<8) | (*(key+0x6)<<16) | (*(key+0x7)<<24) ),
                          ( (*(key+0x8)) | (*(key+0x9)<<8) | (*(key+0xa)<<16) | (*(key+0xb)<<24) ),
                          ( (*(key+0xc)) | (*(key+0xd)<<8) | (*(key+0xe)<<16) | (*(key+0xf)<<24) ) );
        che_update_key4_5(( (*(key+0x10)) | (*(key+0x11)<<8) | (*(key+0x12)<<16) | (*(key+0x13)<<24) ),
                          ( (*(key+0x14)) | (*(key+0x15)<<8) | (*(key+0x16)<<16) | (*(key+0x17)<<24) ) );
    }
    che_generate_ckey((kal_uint32)ckey);  /*ckey*/
    CHE_TurnOnClock(KAL_FALSE);
}


void convert_aes_256_key(kal_uint8 *key, kal_uint8 *ckey){

    CHE_TurnOnClock(KAL_TRUE);

    CHE_REGSET_START(CHE_START_CLEAR);
    CHE_REGSET_START(CHE_START_DONE);


    if ((((kal_uint32)key)&0x03)==0){
        che_update_key0_3(*(kal_uint32 *)(key+0x0),
                          *(kal_uint32 *)(key+0x4),
                          *(kal_uint32 *)(key+0x8),
                          *(kal_uint32 *)(key+0xc) );
        che_update_key4_7(*(kal_uint32 *)(key+0x10),
                          *(kal_uint32 *)(key+0x14),
                          *(kal_uint32 *)(key+0x18),
                          *(kal_uint32 *)(key+0x1c));
     }
     else{
        che_update_key0_3(( (*(key+0x0)) | (*(key+0x1)<<8) | (*(key+0x2)<<16) | (*(key+0x3)<<24) ),
                          ( (*(key+0x4)) | (*(key+0x5)<<8) | (*(key+0x6)<<16) | (*(key+0x7)<<24) ),
                          ( (*(key+0x8)) | (*(key+0x9)<<8) | (*(key+0xa)<<16) | (*(key+0xb)<<24) ),
                          ( (*(key+0xc)) | (*(key+0xd)<<8) | (*(key+0xe)<<16) | (*(key+0xf)<<24) ) );
        che_update_key4_7(( (*(key+0x10)) | (*(key+0x11)<<8) | (*(key+0x12)<<16) | (*(key+0x13)<<24) ),
                          ( (*(key+0x14)) | (*(key+0x15)<<8) | (*(key+0x16)<<16) | (*(key+0x17)<<24) ),
                          ( (*(key+0x18)) | (*(key+0x19)<<8) | (*(key+0x1a)<<16) | (*(key+0x1b)<<24) ),
                          ( (*(key+0x1c)) | (*(key+0x1d)<<8) | (*(key+0x1e)<<16) | (*(key+0x1f)<<24) ));
     }
    che_generate_ckey((kal_uint32)ckey);  /*ckey*/
    CHE_TurnOnClock(KAL_FALSE);
}


void aes_set_iv(kal_uint8 *cheIV)
{
   if ( (((kal_uint32)cheIV)&0x03) == 0)
   {
      CHE_REGSET_IV0(*(kal_uint32 *)(cheIV+0x0));
      CHE_REGSET_IV1(*(kal_uint32 *)(cheIV+0x4));
      CHE_REGSET_IV2(*(kal_uint32 *)(cheIV+0x8));
      CHE_REGSET_IV3(*(kal_uint32 *)(cheIV+0xc));
   }
   else
   {
      CHE_REGSET_IV0(( (*(cheIV+0x0)) | (*(cheIV+0x1)<<8) | (*(cheIV+0x2)<<16) | (*(cheIV+0x3)<<24) ));
      CHE_REGSET_IV1(( (*(cheIV+0x4)) | (*(cheIV+0x5)<<8) | (*(cheIV+0x6)<<16) | (*(cheIV+0x7)<<24) ));
      CHE_REGSET_IV2(( (*(cheIV+0x8)) | (*(cheIV+0x9)<<8) | (*(cheIV+0xa)<<16) | (*(cheIV+0xb)<<24) ));
      CHE_REGSET_IV3(( (*(cheIV+0xc)) | (*(cheIV+0xd)<<8) | (*(cheIV+0xe)<<16) | (*(cheIV+0xf)<<24) ));
   }

   CHE_REGSET_START((CHE_START_UPIV01|CHE_START_UPIV23));
   CHE_REGSET_START(CHE_START_DONE);
}

void des_set_iv(kal_uint8 *cheIV)
{
   if ( (((kal_uint32)cheIV)&0x03) == 0)
   {
      CHE_REGSET_IV0(*(kal_uint32 *)(cheIV+0x0));
      CHE_REGSET_IV1(*(kal_uint32 *)(cheIV+0x4));
   }
   else
   {
      CHE_REGSET_IV0(( (*(cheIV+0x0)) | (*(cheIV+0x1)<<8) | (*(cheIV+0x2)<<16) | (*(cheIV+0x3)<<24) ));
      CHE_REGSET_IV1(( (*(cheIV+0x4)) | (*(cheIV+0x5)<<8) | (*(cheIV+0x6)<<16) | (*(cheIV+0x7)<<24) ));
   }

   CHE_REGSET_START(CHE_START_UPIV01);
   CHE_REGSET_START(CHE_START_DONE);
}



kal_bool che_hw_des( STCHE* che_context,
                     kal_uint8 *srcData, kal_uint8 *encryptedData, kal_uint32 data_length,
                     CHE_TYPE type, CHE_OPERATION_MODE mode, CHE_ACTION act, kal_bool last_block)
{

   ASSERT(encryptedData != NULL);
   CHE_TurnOnClock(KAL_TRUE);

   ASSERT((((kal_uint32)che_context->cheCKey )&0x03)==0);

   CHE_REGSET_START(CHE_START_CLEAR);
   CHE_REGSET_START(CHE_START_DONE);

   if(type == CHE_DES){
       if (mode == CHE_ECB)
          if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_DES|CHE_CON_CIPHER|CHE_CON_SMODE_ECB) );
          }
          else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_DES|CHE_CON_DECIPHER|CHE_CON_SMODE_ECB) );
          }
       else if (mode == CHE_CBC){
          if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_DES|CHE_CON_CIPHER|CHE_CON_SMODE_CBC) );
            des_set_iv(che_context->cheIV);
          }
          else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_DES|CHE_CON_DECIPHER|CHE_CON_SMODE_CBC) );
            des_set_iv(che_context->cheIV);
          }
       }
    }
    else if(type == CHE_3DES){
       if (mode == CHE_ECB)
          if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_3DES|CHE_CON_CIPHER|CHE_CON_SMODE_ECB) );
          }
          else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_3DES|CHE_CON_DECIPHER|CHE_CON_SMODE_ECB) );
          }
      else if (mode == CHE_CBC){
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_3DES|CHE_CON_CIPHER|CHE_CON_SMODE_CBC) );
            des_set_iv(che_context->cheIV);
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_3DES|CHE_CON_DECIPHER|CHE_CON_SMODE_CBC) );
            des_set_iv(che_context->cheIV);
         }
      }
    }
    else{
        ASSERT(0);
    }

    /*Read the ckey to des engine*/
   che_retrieve_ckey((kal_uint32)che_context->cheCKey);

   /*Detail src/dst/length*/
   CHE_REGSET_SRC((kal_uint32)srcData);
   CHE_REGSET_LEN((kal_uint32)data_length);
   CHE_REGSET_DST((kal_uint32)encryptedData);
   CHE_REGSET_SADDR((kal_uint32)che_context->cheDataAddr);

   if(che_context->cheFirstFlag == KAL_TRUE){
        if (last_block){
            CHE_REGSET_START((CHE_START_STUD|CHE_START_LAST|CHE_START_UPDES));
            che_wait_status_complete(data_length, KAL_TRUE);
            che_context->cheFirstFlag = KAL_TRUE;
        }
        else{
            CHE_REGSET_START((CHE_START_WSTAT|CHE_START_STUD|CHE_START_UPDES));
            che_wait_status_complete(data_length, KAL_FALSE);
        }

        che_context->cheFirstFlag = KAL_FALSE;
   }
   else{
        if (last_block){
            CHE_REGSET_START((CHE_START_RSTAT|CHE_START_STUD|CHE_START_LAST|CHE_START_UPDES));
            che_wait_status_complete(data_length,KAL_TRUE);
            che_context->cheFirstFlag = KAL_TRUE;
        }
        else{
           CHE_REGSET_START((CHE_START_RSTAT|CHE_START_WSTAT|CHE_START_STUD|CHE_START_UPDES));
           che_wait_status_complete(data_length,KAL_FALSE );
        }
   }


   CHE_REGSET_START(CHE_START_DONE);

   CHE_TurnOnClock(KAL_FALSE);


   return KAL_TRUE;
}



kal_bool che_hw_aes(STCHE* che_context,
                    kal_uint8 *srcData, kal_uint8 *encryptedData, kal_uint32 data_length,
                    CHE_OPERATION_MODE mode, CHE_ACTION act, kal_bool last_block)
{
   kal_uint32 aes_length;
   aes_length = che_context->cheKeyLength;
   ASSERT(encryptedData != NULL);
   CHE_TurnOnClock(KAL_TRUE);
   ASSERT((((kal_uint32)che_context->cheCKey )&0x03)==0);


   CHE_REGSET_START(CHE_START_CLEAR);
   CHE_REGSET_START(CHE_START_DONE);

   if(aes_length == 16){
      if (mode == CHE_ECB)
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_128|CHE_CON_CIPHER|CHE_CON_SMODE_ECB) );
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_128|CHE_CON_DECIPHER|CHE_CON_SMODE_ECB) );
         }
      else if (mode == CHE_CBC){
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_128|CHE_CON_CIPHER|CHE_CON_SMODE_CBC) );
            aes_set_iv(che_context->cheIV);
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_128|CHE_CON_DECIPHER|CHE_CON_SMODE_CBC) );
            aes_set_iv(che_context->cheIV);
         }
      }
   }
   else if(aes_length == 24){
      if (mode == CHE_ECB)
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_192|CHE_CON_CIPHER|CHE_CON_SMODE_ECB) );
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_192|CHE_CON_DECIPHER|CHE_CON_SMODE_ECB) );
         }
      else if (mode == CHE_CBC){
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_192|CHE_CON_CIPHER|CHE_CON_SMODE_CBC) );
            aes_set_iv(che_context->cheIV);
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_192|CHE_CON_DECIPHER|CHE_CON_SMODE_CBC) );
            aes_set_iv(che_context->cheIV);
         }
      }
    }
    else if(aes_length == 32){
      if (mode == CHE_ECB)
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_256|CHE_CON_CIPHER|CHE_CON_SMODE_ECB) );
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_256|CHE_CON_DECIPHER|CHE_CON_SMODE_ECB) );
         }
      else if (mode == CHE_CBC){
         if(act == CHE_ENC){
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_256|CHE_CON_CIPHER|CHE_CON_SMODE_CBC) );
            aes_set_iv(che_context->cheIV);
         }
         else{
            CHE_REGSET_CON( (CHE_CON_ATYPE_AES_256|CHE_CON_DECIPHER|CHE_CON_SMODE_CBC) );
            aes_set_iv(che_context->cheIV);
         }
      }
    }
    else{
        ASSERT(0);
    }


    /*Read the ckey to aes engine*/
   che_retrieve_ckey ((kal_uint32)che_context->cheCKey);

   /*Detail src/dst/length*/
   CHE_REGSET_SRC((kal_uint32)srcData);      /*src*/
   CHE_REGSET_DST((kal_uint32)encryptedData);   /*dst*/
   CHE_REGSET_LEN((kal_uint32)data_length);     /*length*/
   CHE_REGSET_SADDR((kal_uint32)che_context->cheDataAddr);


   if(che_context->cheFirstFlag == KAL_TRUE){

        if (last_block){
            CHE_REGSET_START((CHE_START_STUD|CHE_START_LAST|CHE_START_UPDES));
            che_wait_status_complete(data_length, KAL_TRUE );
            che_context->cheFirstFlag = KAL_TRUE;
        }
        else{
            CHE_REGSET_START((CHE_START_WSTAT|CHE_START_STUD|CHE_START_UPDES));
            che_wait_status_complete(data_length, KAL_FALSE );
        }

        che_context->cheFirstFlag = KAL_FALSE;
   }
   else{
        if (last_block){
            CHE_REGSET_START((CHE_START_RSTAT|CHE_START_STUD|CHE_START_LAST|CHE_START_UPDES));
            che_wait_status_complete(data_length,KAL_TRUE );
            che_context->cheFirstFlag = KAL_TRUE;
        }
        else{
           CHE_REGSET_START((CHE_START_RSTAT|CHE_START_WSTAT|CHE_START_STUD|CHE_START_UPDES));
           che_wait_status_complete(data_length,KAL_FALSE );
        }
   }


   CHE_REGSET_START(CHE_START_DONE);

   CHE_TurnOnClock(KAL_FALSE);

   return KAL_TRUE;
}


kal_uint32 che_hw_hash( STCHE* che_context, CHE_TYPE type, //kal_uint8 *cheDataAddr, kal_bool first_flag,
                        kal_uint8 *srcData, kal_uint8 *output_data,  kal_uint32 data_length, kal_bool last_block)
{
   kal_uint32 hash_bytes;
   ASSERT(output_data != NULL);

   CHE_TurnOnClock(KAL_TRUE);


   CHE_REGSET_START(CHE_START_CLEAR);
   CHE_REGSET_START(CHE_START_DONE);

   switch(type)
   {
      case CHE_MD5:
         CHE_REGSET_CON((CHE_CON_ATYPE_MD5));
         break;

      case CHE_SHA1:
         CHE_REGSET_CON((CHE_CON_ATYPE_SHA1));
         break;
      default:
         ASSERT(0);
   }

   /*Detail src/dst/length*/
   CHE_REGSET_SRC((kal_uint32)srcData);      /*src*/
   CHE_REGSET_DST((kal_uint32)output_data);   /*dst*/
   CHE_REGSET_LEN((kal_uint32)data_length);     /*length*/
   CHE_REGSET_SADDR((kal_uint32)che_context->cheDataAddr);


   if(che_context->cheFirstFlag == KAL_TRUE){

        if (last_block){
            CHE_REGSET_START((CHE_START_STUD|CHE_START_LAST|CHE_START_UPDES));
            che_wait_status_complete(data_length, KAL_TRUE );
            che_context->cheFirstFlag = KAL_TRUE;
        }
        else{
            CHE_REGSET_START((CHE_START_WSTAT|CHE_START_STUD|CHE_START_UPDES));
            che_wait_status_complete(data_length, KAL_FALSE );
        }

        che_context->cheFirstFlag = KAL_FALSE;
   }
   else{
        if (last_block){
            CHE_REGSET_START((CHE_START_RSTAT|CHE_START_STUD|CHE_START_LAST|CHE_START_UPDES));
            che_wait_status_complete(data_length,KAL_TRUE );
            che_context->cheFirstFlag = KAL_TRUE;
        }
        else{
           CHE_REGSET_START((CHE_START_RSTAT|CHE_START_WSTAT|CHE_START_STUD|CHE_START_UPDES));
           che_wait_status_complete(data_length,KAL_FALSE );
        }
   }


   CHE_REGSET_START(CHE_START_DONE);


   hash_bytes = DRV_Reg32(CHE_CDES) - (kal_uint32)output_data;

   CHE_TurnOnClock(KAL_FALSE);

   return hash_bytes;
}



#else /*__HW_CHE__*/



void che_hw_init(void)
{
}
void che_slowdown(void)
{
}
void che_recover(void)
{
}
#endif



#ifdef UNIT_TEST_CHE

random

hw_
sw_


#endif



