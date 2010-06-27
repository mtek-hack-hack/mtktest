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
 * BT_loopback.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 * BT PCM loopback function
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
 
/*****************************************************************************
*                     C O M P I L E R   F L A G S
******************************************************************************
*/ 
 

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/ 

#include "l1audio.h"
#include "med_utility.h"
#include "fsal.h"
#include "PCMRB.h"
#include "pcm4way.h"

#ifndef __L1_STANDALONE__ // avoid link error
#ifdef BT_Loopback_Test


/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define AUTOREC_MEDIA_BUF_SIZE          (20 * 1024)
#define AUTOSPK_MEDIA_BUF_SIZE          (20 * 1024)
//#define AUTOREC_MEDIA_BUF_SIZE          (200 * 1024)
//#define AUTOSPK_MEDIA_BUF_SIZE          3840

#define PCM2WAY_FRAME_TIME              20
#define PCM2WAY_SAMPLE_PER_MSEC         8
#define PCM2WAY_FRAME_SIZE              (PCM2WAY_FRAME_TIME*PCM2WAY_SAMPLE_PER_MSEC)

#define EVENT_NONE                  0
#define EVENT_DATA_REQUEST          1
#define EVENT_DATA_NOTIFY           2
#define EVENT_STOP                  3


#define DIR_UL                      0
#define DIR_DL                      1

#define AUTO_SPK_IDLE1                  1
#define AUTO_SPK_IDLE2                  2
#define AUTO_SPK_START                  3
#define AUTO_SPK_STOP                   4

#define INIT_FILL_SILENCE  4
#define END_FILL_SILENCE   1

//#define BT_DEBUG

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/
typedef uint32                          BT_STATUS;
typedef uint32                          BT_EVENT;
typedef void (*BT_CALLBACK)( void *host_data, BT_EVENT event );


static struct wav_header 
{
   char                 riff_chunk[4];
   unsigned int         riff_size;
   char                 riff_type[4];
   char                 fmt_chunk[4];
   unsigned int         fmt_size;
   short                fmt_codec;
   short                channels;
   unsigned int         fs;
   unsigned int         bytes_per_sec;
   short                block_align;
   short                bits_per_sample;
   char                 data_chunk[4];
   unsigned int         data_size;
}wav_hdr = {
   { 'R', 'I', 'F', 'F' },
   0,
   { 'W', 'A', 'V', 'E' },
   { 'f', 'm', 't', (char)0x20 },
   16,
   1, // linear PCM
   1, // 2-CH
   8000,
   8000*2,
   2,
   16,
   { 'd', 'a', 't', 'a' },
   0
}; 


typedef struct BTHandleStruct BT_HANDLE;
struct BTHandleStruct {
   kal_uint32         dir;
   PCMRB              rb;
   BT_CALLBACK   callback;
   void                  *host_data;
};

static struct {
   BT_HANDLE     *bt_handle;   	
   STFSAL            fAutoRec; 
   kal_uint32        sample_consume;   
   kal_uint16        *pAutoRecBuffer;
   kal_int16          *mic_buffer;     
   kal_char       filename[40];   
   kal_bool            waiting;               
} auto_record;


static struct {
   BT_HANDLE      *bt_handle;   	
   STFSAL            fAutoSpeak;
   kal_uint32        sample_elapsed;
   kal_uint16        *pAutoSpeakBuffer;
   kal_int16          *spk_buffer;   
   kal_char      filename[40];
   kal_bool           waiting;    
   struct wav_header stWavHdr;   
} auto_speak;


static struct{
   void                      (*callback)( void );    	
   kal_uint32		     init_state;
   kal_uint32             stop_loopback;  
   kal_bool   	          playfile_eof;	    
   kal_bool          		FSRemDrive; 
	
}BT_Manager;



/*****************************************************************************
*                        P U B L I C   D A T A
******************************************************************************
*/



/*****************************************************************************
*                       P R I V A T E   D A T A
******************************************************************************
*/

#ifdef BT_DEBUG
static kal_int32  num_spk_sample=0;
static kal_int32  num_rec_sample=0;
#endif
/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/


/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/


static void BT_Loopback_Stop(void);

extern kal_uint16 L1Audio_GetDebugInfo( kal_uint8 index );

/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/

static void free_pcm2way_buffer( void )
{
   free_ctrl_buffer( auto_record.mic_buffer );

   auto_record.mic_buffer = NULL;
   auto_speak.spk_buffer = NULL;
}

static void get_pcm2way_buffer( void )
{
   uint8 *buffer = (uint8 *)get_ctrl_buffer(2*PCM2WAY_FRAME_SIZE*sizeof(int16)); 
   ASSERT( buffer!=NULL );	  
      
   memset( buffer, 0, 2*PCM2WAY_FRAME_SIZE*sizeof(int16) ); 
   auto_record.mic_buffer = (int16 *)buffer;	
        
   buffer += PCM2WAY_FRAME_SIZE*sizeof(int16);
   auto_speak.spk_buffer = (int16 *)buffer;  
}



static void bt_loopback_hisr( void )
{
//    kal_int16 *test_ptr = auto_speak.spk_buffer;
//    int32 I;  
/*Initial Fill Silence*/
   if(BT_Manager.init_state < INIT_FILL_SILENCE )
   { 
      memset( auto_speak.spk_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );  
      PCM2WAY_PutToSpk( (uint16 *)auto_speak.spk_buffer ); 	
      BT_Manager.init_state++;
/*      
		  for(I=0;I<160;I++)
		  {
		  	if(*test_ptr != 0){
		  		kal_prompt_trace(MOD_L1SP, "ASSERT MCU Put nonzero data");		  			
		  	}
		  	test_ptr++; 		
		  }
*/
   }
   
/*Stop Loopback*/	
   if(BT_Manager.playfile_eof == true && BT_Manager.stop_loopback == END_FILL_SILENCE){	
		if( auto_record.bt_handle->callback!=NULL ){
			auto_record.bt_handle->callback( auto_record.bt_handle->host_data, EVENT_STOP ); 
			return;
      }
   }

/*Finish Consuming all data in the RB of speak , then End Fill Silence*/
   if(BT_Manager.stop_loopback < END_FILL_SILENCE && 
         PCMRB_GetDataCount( &auto_speak.bt_handle->rb )==0 && 
         BT_Manager.playfile_eof == true){
      memset( auto_speak.spk_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );   
	   PCM2WAY_PutToSpk( (uint16 *)auto_speak.spk_buffer );     
     	BT_Manager.stop_loopback ++;	         
   } 

/*Handle Play EOF , consume all data in the RB of speak*/
   if (BT_Manager.playfile_eof == true && 
               BT_Manager.stop_loopback == 0 /*&& BT_Manager.init_state == INIT_FILL_SILENCE*/){
                  
      if(PCMRB_GetDataCount( &auto_speak.bt_handle->rb )!=0){
         
         memset( auto_speak.spk_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );   
         if(NULL!=auto_speak.bt_handle){  	
				
            BT_HANDLE *dl= auto_speak.bt_handle;		
					
            if( PCMRB_GetDataCount( &dl->rb )>=PCM2WAY_FRAME_SIZE ){ 
               PCMRB_Read( &dl->rb , auto_speak.spk_buffer , PCM2WAY_FRAME_SIZE );			
            }
            else{
               kal_int32 read_len;
               read_len =  PCMRB_GetDataCount( &dl->rb );
               PCMRB_Read( &dl->rb , auto_speak.spk_buffer , read_len );
               BT_Manager.stop_loopback ++;	
		         kal_prompt_trace(MOD_L1SP, "Consume all data in spk buf R1");                				   
            }
            PCM2WAY_PutToSpk( (uint16 *)auto_speak.spk_buffer );             
	      }   	
      }  	   
   }
  

/*Regular playing*/
   if (BT_Manager.playfile_eof == false && BT_Manager.stop_loopback==0 
         && BT_Manager.init_state == INIT_FILL_SILENCE)	
   {
	   memset( auto_speak.spk_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );      
//	   if(NULL!=auto_speak.bt_handle)
		 {   		
	      BT_HANDLE *dl= auto_speak.bt_handle;
      
	      if( PCMRB_GetDataCount( &dl->rb )>=PCM2WAY_FRAME_SIZE ){ 				
	   	  PCMRB_Read( &dl->rb , auto_speak.spk_buffer , PCM2WAY_FRAME_SIZE );				  
	      }
			
	      if( dl->callback!=NULL )
	         dl->callback( dl->host_data, EVENT_DATA_REQUEST );
                   
	      PCM2WAY_PutToSpk( (uint16 *)auto_speak.spk_buffer );             
			
	   }
   } 

/*Regular recording*/ 

	if(BT_Manager.init_state >= INIT_FILL_SILENCE)
	{	
	   memset( auto_record.mic_buffer, 0, PCM2WAY_FRAME_SIZE*sizeof(int16) );    

//	   if(NULL!=auto_record.bt_handle)
		{  		
    	  BT_HANDLE *ul = auto_record.bt_handle;        
  	       
		  	PCM2WAY_GetFromMic( (uint16 *)auto_record.mic_buffer );  
	
    	  if( PCMRB_GetFreeSpace( &ul->rb )>=PCM2WAY_FRAME_SIZE ){ 			
      	   PCMRB_Write( &ul->rb , auto_record.mic_buffer, PCM2WAY_FRAME_SIZE );				
   	   }
		
    	  if( ul->callback!=NULL )
      	   ul->callback( ul->host_data, EVENT_DATA_NOTIFY );          
		}   
  }
    
   return;     
}


BT_HANDLE *BT_GetHandle ( uint32 dir, uint8 *buffer, int32 buffer_size )
{
   BT_HANDLE *handle;

   ASSERT( (dir==DIR_UL) || (dir==DIR_DL) );
   ASSERT( buffer!=NULL );
   ASSERT( buffer_size>PCM2WAY_FRAME_SIZE*sizeof(int16) );

   handle = (BT_HANDLE *)get_ctrl_buffer( sizeof(BT_HANDLE) );
   if( NULL==handle )
      return NULL;

   memset( handle, 0, sizeof(BT_HANDLE) );
   handle->dir = dir;
   if( false==PCMRB_Init( &handle->rb, (int16 *)buffer, buffer_size/sizeof(int16) ) )
   {
      free_ctrl_buffer( handle );
      return NULL;
   }
   return handle;
}

static int AutoSpeak_open_file(void)
{
   kal_wchar filename[40];	

   kal_int16 drv_letter;



   if(BT_Manager.FSRemDrive)
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
   else
      drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
  
   kal_wsprintf( filename, "%c:\\%s", drv_letter, auto_speak.filename );



   if( FSAL_OK != FSAL_Open( &auto_speak.fAutoSpeak, filename, FSAL_READ ) )
   {
      kal_prompt_trace(MOD_L1SP, "autospeak: source file can't open\n");
//      ASSERT(0);		
      return 1;
   }

   FSAL_Read( &auto_speak.fAutoSpeak, (kal_uint8 *)&auto_speak.stWavHdr, sizeof(struct wav_header) );
	
   if( 
         (strncmp(auto_speak.stWavHdr.riff_chunk, "RIFF", 4) != 0) &&
         (strncmp(auto_speak.stWavHdr.riff_type, "WAVE",4) != 0 ) &&
         (strncmp(auto_speak.stWavHdr.data_chunk, "data",4) != 0 ) &&	      
         (auto_speak.stWavHdr.fmt_size != wav_hdr.fmt_size) 	   &&           // chunk size : 16 
         (auto_speak.stWavHdr.fmt_codec != wav_hdr.fmt_codec) &&               // 1 : linear pcm
         (auto_speak.stWavHdr.fs != wav_hdr.fs) && 	                         // sample rate : 8000
         (auto_speak.stWavHdr.bits_per_sample != wav_hdr.bits_per_sample) 	    // bits_per_sample : 16
      )
      ASSERT(0);      
	
   auto_speak.sample_elapsed = auto_speak.stWavHdr.data_size >> 1;


   return 0;
}



static void AutoSpeak_GetDataFromFileToRB(kal_uint32 arg1, void *arg2)
{
   kal_int16 *write_ptr;
   kal_int32 write_len;
   kal_int32 count;
   PCMRB *rb = &auto_speak.bt_handle->rb;

   (void)arg1;
   (void)arg2;

   write_len = PCMRB_GetFreeSpace( rb );
   
#ifdef BT_DEBUG   
   {
      kal_int32 diff_RB;              
      num_spk_sample += write_len;  
      diff_RB = num_spk_sample - num_rec_sample;   
      kal_prompt_trace(MOD_L1SP, "write_len      K1 =%d", write_len);    
      kal_prompt_trace(MOD_L1SP, "num_spk_sample K2 =%d", num_spk_sample);    
      kal_prompt_trace(MOD_L1SP, "diff_spk_and_rec_Spk_callcack K3 =%d", diff_RB);    
   }   
#endif   
   
   while( write_len > 0 )
   {      
      PCMRB_GetWriteBlock( rb, &write_ptr, &count );
      if( auto_speak.sample_elapsed == 0 )
      {
         break;                
      }
      else
      {
         if( auto_speak.sample_elapsed < count )
            count = auto_speak.sample_elapsed;

         ASSERT( FSAL_OK == FSAL_Read( &auto_speak.fAutoSpeak, (kal_uint8 *)write_ptr, count << 1 ) );
         auto_speak.sample_elapsed -= count;
      }
      PCMRB_ShiftWritePointer(rb, count);
      write_len -= count;

		if (write_len == 0)
			break;      
      
   }
   
   auto_speak.waiting = false;
    
   if( auto_speak.sample_elapsed == 0 )
   {
	   BT_Manager.playfile_eof=true;   
   }     
    
}



static void AutoSpeakCallback( void *host_data, BT_EVENT event )
{
   if (auto_speak.waiting)
      return;   	

   if( PCMRB_GetFreeSpace( &auto_speak.bt_handle->rb ) >= 1024 ){
      auto_speak.waiting = true;
      L1Audio_InProcCall( AutoSpeak_GetDataFromFileToRB, 0, 0 );
   }
}


static void AutoRec_GetDataFromRBToFile( kal_uint32 arg1, void *arg2 )
{
   kal_int16 *read_ptr;
   kal_int32 read_len;
   kal_int32 count;
   PCMRB *rb = &auto_record.bt_handle->rb;
   BT_EVENT *event = (BT_EVENT *)arg2;   

   (void)arg1;
//   (void)arg2; 

	if(*event == EVENT_STOP)
	   PCM2WAY_Stop(2);
   
   read_len = PCMRB_GetDataCount( rb );
   
#ifdef BT_DEBUG	    
   {
      kal_int32 diff_RB;      

      num_rec_sample += read_len;   
      diff_RB = num_spk_sample - num_rec_sample;          
      kal_prompt_trace(MOD_L1SP, "read_len       T1 =%d", read_len);       
      kal_prompt_trace(MOD_L1SP, "num_rec_sample T2 =%d", num_rec_sample);   
      kal_prompt_trace(MOD_L1SP, "diff_spk_and_rec_Rec_callcack T3 =%d", diff_RB);    
   }
#endif   
  
   auto_record.sample_consume += read_len<<1;   
      
   while( read_len > 0 )
   {
      PCMRB_GetReadBlock( rb , &read_ptr , &count );	
     	ASSERT( FSAL_OK == FSAL_Write( &auto_record.fAutoRec , (kal_uint8 *)read_ptr , count << 1 ) );		
      PCMRB_ShiftReadPointer( rb , count );		
      read_len -= count;      
      
		if (read_len == 0)
			break;		      
               
   }  

	if(*event == EVENT_STOP)
		BT_Loopback_Stop();    
	
	auto_record.waiting = false; 
    
}


static void AutoRecCallback( void *host_data, BT_EVENT event )
{   
   if (auto_record.waiting)
      return;
   if(event == EVENT_STOP){
      auto_record.waiting = true;  	   		
      L1Audio_InProcCall( AutoRec_GetDataFromRBToFile, 0, (void *)&event );      
   }      	   
   

   if( PCMRB_GetDataCount( &auto_record.bt_handle->rb ) >= 1024 ){      
      auto_record.waiting = true;
      L1Audio_InProcCall( AutoRec_GetDataFromRBToFile, 0, 0 );       

   }   
}




static int AutoRec_open_file(void)
{
   kal_wchar filename[40];
   kal_int16 drv_letter;


   if(BT_Manager.FSRemDrive)
      drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );
   else
      drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);    
	  
   kal_wsprintf( filename, "%c:\\%s", drv_letter, auto_record.filename );



   if( FSAL_OK != FSAL_Open( &auto_record.fAutoRec, filename, FSAL_WRITE ) )
   {
      kal_prompt_trace(MOD_L1SP, "Autorec: source file can't open\n");
//      ASSERT(0);		
      return 1;
   }
  return 0;
}


static void AutoRec_WriteFileHeader(void)
{
   if( auto_record.pAutoRecBuffer==NULL ){      
      return;
   }      
  
   wav_hdr.riff_size   = auto_record.sample_consume+36 ;      
   wav_hdr.data_size   = auto_record.sample_consume  ;    
  
   ASSERT( FSAL_OK == FSAL_Seek( &auto_record.fAutoRec, 0 ) );
   ASSERT( FSAL_OK == FSAL_Write( &auto_record.fAutoRec, (kal_uint8 *) (&wav_hdr), sizeof(wav_hdr) ) );   

}

static void Write_Init_Parameter(void)
{


   if (L1Audio_GetDebugInfo(5)==0)
   {   
	   BT_Manager.FSRemDrive = KAL_TRUE;    // SD Card 
   }
	else
	{
	   BT_Manager.FSRemDrive = KAL_FALSE;    // Phone memory 	
	}
	
   BT_Manager.init_state = 0;      
   auto_record.waiting = false;   
   auto_speak.waiting = false;     
   BT_Manager.playfile_eof = false;
   BT_Manager.stop_loopback = 0;   

	
   auto_record.sample_consume = 0;   
   wav_hdr.riff_size   = 0  ;      
   wav_hdr.data_size   = 0  ;    
   
#ifdef BT_DEBUG
   num_spk_sample=0;
   num_rec_sample=0;   
#endif
}


static void Loopback_Start_InMed(kal_uint32 arg1, void* arg2)
{
   kal_uint32 spk_buf_len = AUTOSPK_MEDIA_BUF_SIZE+1024;
   kal_uint32 rec_buf_len = AUTOREC_MEDIA_BUF_SIZE + 1024;

   (void)arg1;
   (void)arg2;

   Write_Init_Parameter(); 

   auto_speak.pAutoSpeakBuffer = (kal_uint16 *)med_alloc_ext_mem(spk_buf_len*sizeof(int16));   
   if( auto_speak.pAutoSpeakBuffer==NULL )
      return;
   
   if( 0 != AutoSpeak_open_file() )
      return;

   spk_buf_len -= 1024;   
   FSAL_SetBuffer( &auto_speak.fAutoSpeak, 1024, (kal_uint8 *)&auto_speak.pAutoSpeakBuffer[spk_buf_len] );   
   spk_buf_len -= AUTOSPK_MEDIA_BUF_SIZE;  
   auto_speak.bt_handle = BT_GetHandle( DIR_DL, (uint8 *)&auto_speak.pAutoSpeakBuffer[spk_buf_len], AUTOSPK_MEDIA_BUF_SIZE );
   auto_speak.bt_handle->callback = AutoSpeakCallback;
   auto_speak.bt_handle->host_data = 0;

/*Initial get data form file to RB*/
//   Init_GetDataFromFileToRB();
   AutoSpeak_GetDataFromFileToRB(0,0);

	  
   auto_record.pAutoRecBuffer = (kal_uint16 *)med_alloc_ext_mem(rec_buf_len*sizeof(int16));   
  	if( auto_record.pAutoRecBuffer==NULL ){
      return;
  	}      
   
   if( 0 != AutoRec_open_file() )
  	   return;   
  
   rec_buf_len -= 1024;
   FSAL_SetBuffer( &auto_record.fAutoRec, 1024, (kal_uint8 *)&auto_record.pAutoRecBuffer[rec_buf_len] );
   rec_buf_len -= AUTOREC_MEDIA_BUF_SIZE;
   auto_record.bt_handle = BT_GetHandle( DIR_UL, (uint8 *)&auto_record.pAutoRecBuffer[rec_buf_len], AUTOREC_MEDIA_BUF_SIZE );
   auto_record.bt_handle->callback = AutoRecCallback;
   auto_record.bt_handle->host_data = 0;
  

   get_pcm2way_buffer();  
   
   PCM2WAY_Start( bt_loopback_hisr, 2 );        
}


//uint32 BT_Loopback_Start(void(*callback)( void ) , kal_wchar *play_filename , kal_wchar *record_filename)
uint32 BT_Loopback_Start(void(*callback)( void ) , kal_char *play_filename , kal_char *record_filename)	
{
   BT_Manager.callback = callback;

//   kal_wstrcpy( auto_speak.filename, play_filename);   
//   kal_wstrcpy( auto_record.filename, record_filename); 

	strcpy(auto_speak.filename, play_filename);
	strcpy(auto_record.filename, record_filename);	
	
   L1Audio_InProcCall(Loopback_Start_InMed,0,0); 

   return 1;      
}



static void BT_Loopback_Stop()
{
   kal_int32  write_len;
   kal_int32  read_len;


#ifdef BT_DEBUG   
   kal_prompt_trace(MOD_L1SP, "BT_Loopback_Stop P1");      
#endif  	
  
//   PCM2WAY_Stop(2);   
    
#ifdef BT_DEBUG 
   write_len = PCMRB_GetFreeSpace( &auto_speak.bt_handle->rb ); 
   read_len = PCMRB_GetDataCount( &auto_speak.bt_handle->rb ); 
   kal_prompt_trace(MOD_L1SP, "auto_speak PCMRB_GetFreeSpace A1 =%d", write_len);      
   kal_prompt_trace(MOD_L1SP, "auto_speak PCMRB_GetDataCount A2 =%d", read_len);      
#endif   



   while(PCMRB_GetDataCount( &auto_record.bt_handle->rb ) > 0)	
  	{  
      BT_Manager.stop_loopback=0; 
	  
#ifdef BT_DEBUG       
      read_len = PCMRB_GetDataCount( &auto_record.bt_handle->rb ); 
      kal_prompt_trace(MOD_L1SP, "PCMRB_GetDataCount A5 =%d", read_len); 	
#endif
      
  	}

   //AutoRec_WriteFileHeader(); 
   free_ctrl_buffer( auto_record.bt_handle );
  	med_free_ext_mem( (void **)&auto_record.pAutoRecBuffer );		



   free_ctrl_buffer( auto_speak.bt_handle );
   med_free_ext_mem( (void **)&auto_speak.pAutoSpeakBuffer );



   free_pcm2way_buffer();   

   ASSERT( FSAL_OK == FSAL_Close( &auto_speak.fAutoSpeak ) );
  	ASSERT( FSAL_OK == FSAL_Close( &auto_record.fAutoRec ) );

	
   BT_Manager.callback();   

#ifdef BT_DEBUG   
   kal_prompt_trace(MOD_L1SP, "BT_Loopback_Stop P2");      
#endif 
}

#endif 
#endif 


