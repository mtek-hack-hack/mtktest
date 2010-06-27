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
 *
 * Filename:
 * ---------
 * cpr_protection.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Used for copyright protection
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "aac_drv.h"
#include "mp4_parser.h"

/* ID3v2 */

#define INVALID_VER_NUM          0xFF   // Version and revision will never be 0xFF
#define FLAG_MASK                0x1F
#define MSB_MASK                 0x80

//The ID3v2 tag size is encoded with four bytes
//where the most significant bit (bit 7) is set to zero in every byte

/* DAF */
#define FRAME_SYNC               0xFF
#define SR_MASK                  0xF0
#define BR_MASK                  0x0C
#define INVALID_SMP_RATE         0xF0
#define INVALID_BIT_RATE         0x0C
#define LAYER_DESC_MASK          0xE6
#define LAYER_3                  0xE2
#define MPEG_AUDIO_VER_ID_MASK   0x18
#define INVALID_VER_ID           0x08

#ifdef __P_PROPRIETARY_COPYRIGHT__
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
#endif
/*******************************************************************************************************
Function:
 media_get_codec_type
Description:
 Get  video and audio codec of file.
Parameters:
 p_filename(In)    : Point to absolute patch of file coded unicode and
the max length of buf is 260*2+2=522.
 media_format(In)  : file format
 p_video_codec(Out): Point to video codec of input file
 p_audio_codec(Out): Point to audio codec og input file
Return value:
 Result of the check.
   MEDIA_FORMAT_CHECK_SUCCESS  if successful.
   MEDIA_FORMAT_CHECK_BAD_FILE if error happens when access file
   MEDIA_FORMAT_CHECK_FAIL     otherwise
*******************************************************************************************************/
Media_Format_Check_Result media_get_codec_type( void *p_filename, Media_Check_Format media_format,
                         Media_Check_Video_Codec *p_video_codec, Media_Check_Audio_Codec *p_audio_codec)
{
   MHdl *hdl;
   aacMediaHdl *ihdl;
   MP4_Audio_Type eAudioType;
   MP4_Video_Type eVideoType;
   STFSAL *pstFSAL = NULL;

   *p_audio_codec = MEDIA_AUDIO_CODEC_UNKNOWN;
   *p_video_codec = MEDIA_VIDEO_CODEC_UNKNOWN;

   pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   if(pstFSAL == NULL)
      return MEDIA_FORMAT_CHECK_INTERNAL_ERROR;
   memset(pstFSAL, 0, sizeof(STFSAL));

   if( FSAL_OK != FSAL_Open(pstFSAL, p_filename, FSAL_READ)){
      free_ctrl_buffer( pstFSAL );
      return MEDIA_FORMAT_CHECK_INTERNAL_ERROR;
   }

   switch(media_format){
      case MEDIA_Check_FORMAT_3GPP:
      case MEDIA_Check_FORMAT_M4A:
      case MEDIA_Check_FORMAT_MP4:
         {
            ihdl = (aacMediaHdl*)get_ctrl_buffer( sizeof(aacMediaHdl) );
            memset(ihdl, 0, sizeof(aacMediaHdl));
            hdl = (MHdl *) ihdl;
            ihdl->pstFSAL = pstFSAL;

            ihdl->pstMp4Parser_M4A = (STMp4Parser *)get_ctrl_buffer( sizeof(STMp4Parser) );
            if(ihdl->pstMp4Parser_M4A == NULL){
               free_ctrl_buffer( pstFSAL );
               free_ctrl_buffer( ihdl );
               return MEDIA_FORMAT_CHECK_INTERNAL_ERROR;
            }

            {
               MP4_Parser_Status eMp4ParserRet;
               eMp4ParserRet = MP4_Parse(ihdl->pstMp4Parser_M4A, ihdl->pstFSAL);
               if(eMp4ParserRet!=MP4_PARSER_OK && eMp4ParserRet!=MP4_PARSER_WARNING_TRAILING_GARBAGE){
                  free_ctrl_buffer( ihdl->pstMp4Parser_M4A );
                  free_ctrl_buffer( ihdl );
                  free_ctrl_buffer( pstFSAL );
                  return MEDIA_FORMAT_CHECK_BAD_FILE;
               }
            }

            eAudioType = MP4_GetAudioType(ihdl->pstMp4Parser_M4A);
            eVideoType = MP4_GetVideoType(ihdl->pstMp4Parser_M4A);

            switch(eAudioType){
               case MP4_AUDIO_AAC:
                  *p_audio_codec = MEDIA_AUDIO_CODEC_AAC;
               case MP4_AUDIO_AMR:
                  *p_audio_codec = MEDIA_AUDIO_CODEC_AMR;
               case MP4_AUDIO_AMR_WB:
                  *p_audio_codec = MEDIA_AUDIO_CODEC_AWB;
               default:
                  *p_audio_codec = MEDIA_AUDIO_CODEC_UNKNOWN;
            }

            switch(eVideoType){
               case MP4_VIDEO_MPEG4:
                  *p_video_codec = MEDIA_VIDEO_CODEC_MPEG4;
               case MP4_VIDEO_H263:
                  *p_video_codec = MEDIA_VIDEO_CODEC_H263;
               default:
                  *p_video_codec = MEDIA_VIDEO_CODEC_UNKNOWN;
            }

            free_ctrl_buffer( ihdl->pstMp4Parser_M4A );
            free_ctrl_buffer( ihdl );
            
            if(MEDIA_AUDIO_CODEC_AAC == *p_audio_codec){
               if( KAL_FALSE == M4A_IsPPSupport( pstFSAL ))
                  *p_audio_codec = MEDIA_AUDIO_CODEC_AAC_PLUS;
            }
        }
        break;

     case MEDIA_Check_FORMAT_MP3:
        {
           kal_uint8 *pBuf;
           pBuf = (kal_uint8 *) get_ctrl_buffer( sizeof(kal_uint8) * 256);
           if(FSAL_Read_Bytes( pstFSAL, pBuf, 256) != FSAL_OK)
              return MEDIA_FORMAT_CHECK_FAIL;

           /* ID3v2 tag */

           if( pBuf[0] == 'I' && pBuf[1] == 'D' && pBuf[2] == '3' &&
           	 pBuf[3] != INVALID_VER_NUM && pBuf[4] != INVALID_VER_NUM &&
           	(pBuf[5] & FLAG_MASK) == 0 && (pBuf[6] & MSB_MASK) == 0 && (pBuf[7] & MSB_MASK) == 0
           	&& (pBuf[8] & MSB_MASK) == 0 && (pBuf[9] & MSB_MASK) == 0 )
           {
           	  *p_audio_codec = MEDIA_AUDIO_CODEC_MP3;
           }

           /* DAF header */

           if( pBuf[0] == FRAME_SYNC && (pBuf[1] & LAYER_DESC_MASK) == LAYER_3
               && (pBuf[1] & MPEG_AUDIO_VER_ID_MASK) != INVALID_VER_ID
               && (pBuf[2] & SR_MASK) != INVALID_SMP_RATE
               && (pBuf[2] & BR_MASK) != INVALID_BIT_RATE )
           {
              *p_audio_codec = MEDIA_AUDIO_CODEC_MP3;
           }
           free_ctrl_buffer( pBuf );
        }
        break;

     case MEDIA_Check_FORMAT_AAC:
        {
           kal_uint8 *pBuf;
           pBuf = (kal_uint8 *) get_ctrl_buffer( sizeof(kal_uint8) * 256);
           if(FSAL_Read_Bytes( pstFSAL, pBuf, 256) != FSAL_OK)
              return MEDIA_FORMAT_CHECK_FAIL;

           if( pBuf[0] == 'I' && pBuf[1] == 'D' && pBuf[2] == '3' &&
           	 pBuf[3] != INVALID_VER_NUM && pBuf[4] != INVALID_VER_NUM &&
           	(pBuf[5] & FLAG_MASK) == 0 && (pBuf[6] & MSB_MASK) == 0 && (pBuf[7] & MSB_MASK) == 0
           	&& (pBuf[8] & MSB_MASK) == 0 && (pBuf[9] & MSB_MASK) == 0 ){
           }else if ((pBuf[0] == 'A') && (pBuf[1] == 'D') && (pBuf[2] == 'I') && (pBuf[3] == 'F')){
           }else if( pBuf[0] == FRAME_SYNC && (pBuf[1] & 0xF0) == 0xF0
                 && (pBuf[1] & 0x06) == 0x00 ){    /* ADTS */
           }else{
               free_ctrl_buffer( pBuf );
               break;
           }

           free_ctrl_buffer( pBuf );

           if( KAL_FALSE == AAC_IsPPSupport(pstFSAL) )
              *p_audio_codec = MEDIA_AUDIO_CODEC_AAC_PLUS;
           else
              *p_audio_codec = MEDIA_AUDIO_CODEC_AAC;

        }
        break;

     case MEDIA_Check_FORMAT_AMR:
     case MEDIA_Check_FORMAT_AWB:
        {
           kal_uint8 AMR_Header[9];
           if(FSAL_Read_Bytes( pstFSAL, AMR_Header, 9) != FSAL_OK)
              return MEDIA_FORMAT_CHECK_FAIL;
           if(memcmp(AMR_Header, "#!AMR-WB\n", 9)!=0){
              if(memcmp(AMR_Header, "#!AMR\n", 6)!=0)
                 break;
              *p_audio_codec = MEDIA_AUDIO_CODEC_AMR;
           }else{
               *p_audio_codec = MEDIA_AUDIO_CODEC_AWB;
            }
        }
        break;
     case MEDIA_Check_FORMAT_WMA:
        {
           kal_uint8 *pBuf;
           pBuf = (kal_uint8 *) get_ctrl_buffer( sizeof(kal_uint8) * 256);
           if(FSAL_Read_Bytes( pstFSAL, pBuf, 256) != FSAL_OK)
              return MEDIA_FORMAT_CHECK_FAIL;

           /* WMA header */

           if( pBuf[0] == 0x30 && pBuf[1] == 0x26 && pBuf[2] == 0xb2 && pBuf[3] == 0x75 &&
               pBuf[4] == 0x8e && pBuf[5] == 0x66 && pBuf[6] == 0xcf && pBuf[7] == 0x11 &&
               pBuf[8] == 0xa6 && pBuf[9] == 0xd9 && pBuf[10] == 0x00 && pBuf[11] == 0xaa &&
               pBuf[12] == 0x00 && pBuf[13] == 0x62 && pBuf[14] == 0xce && pBuf[15] == 0x6c
               && pBuf[28] == 0x01
               && pBuf[29] == 0x02 )
           {
              *p_audio_codec = MEDIA_AUDIO_CODEC_WMA;
           }

           free_ctrl_buffer( pBuf );
        }
        break;

     case MEDIA_Check_FORMAT_WAVE:
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        break;

     case MEDIA_Check_FORMAT_MIDI:
     case MEDIA_Check_FORMAT_SPMIDI:
// UNSUPPORTED FORMAT
     case MEDIA_Check_FORMAT_WMV:
     case MEDIA_Check_FORMAT_ASF:
     case MEDIA_Check_FORMAT_DCF:
        break;
     default:
        free_ctrl_buffer( pstFSAL );
        return MEDIA_FORMAT_CHECK_FAIL;
   }
   free_ctrl_buffer( pstFSAL );
   return MEDIA_FORMAT_CHECK_SUCCESS;
}

/*******************************************************************************************************
Function:
 media_format_type
Description:
 Get format type of file.
Parameters:
 p_filename(In)      : Point to absolute patch of file coded unicode
and the max length of buf is 260*2+2=522.
 p_media_format(Out) : File format
Return value:
 Result of the check.
   MEDIA_FORMAT_CHECK_SUCCESS  if successful.
   MEDIA_FORMAT_CHECK_BAD_FILE if error happens when access file
   MEDIA_FORMAT_CHECK_FAIL     otherwise
*******************************************************************************************************/
Media_Format_Check_Result media_get_format_type( void *file_name, Media_Check_Format *p_media_format)
{
   kal_wchar *p;
   kal_wchar temp[6];
   kal_uint8 i;

   p = (kal_wchar *)file_name + kal_wstrlen((kal_wchar *)file_name) - 5;
   kal_mem_cpy(temp, p, 2 * 6);

   for(i = 0; i < 5; i++){
      if(temp[i] >= 97 /* 'a' */  && temp[i] <= 122 /* 'z' */ ){
         temp[i] -= 32 /* ('a'-'A') */ ;
      }
   }

   p = &temp[1];
   if(kal_wstrcmp(p, L".IMY") == 0){
      *p_media_format = MEDIA_Check_FORMAT_IMY;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".MID") == 0){
      *p_media_format = MEDIA_Check_FORMAT_MIDI;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".WAV") == 0){
      *p_media_format = MEDIA_Check_FORMAT_WAVE;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".MP3") == 0){
      *p_media_format = MEDIA_Check_FORMAT_MP3;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".AMR") == 0){
      *p_media_format = MEDIA_Check_FORMAT_AMR;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".AWB") == 0){
      *p_media_format = MEDIA_Check_FORMAT_AWB;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".AAC") == 0){
      *p_media_format = MEDIA_Check_FORMAT_AAC;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".M4A") == 0){
      *p_media_format = MEDIA_Check_FORMAT_M4A;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".MP4") == 0){
      *p_media_format = MEDIA_Check_FORMAT_MP4;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".3GP") == 0){
      *p_media_format = MEDIA_Check_FORMAT_3GPP;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }
   if(kal_wstrcmp(p, L".WMA") == 0){
      *p_media_format = MEDIA_Check_FORMAT_WMA;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }

   p = &temp[0];
   if(kal_wstrcmp(p, L".MIDI") == 0){
      *p_media_format = MEDIA_Check_FORMAT_SPMIDI;
      return MEDIA_FORMAT_CHECK_SUCCESS;
   }

   *p_media_format = MEDIA_Check_FORMAT_UNKNOWN;
   return MEDIA_FORMAT_CHECK_FAIL;

}

/*******************************************************************************************************
Function:
 media_codec_type_check
Description:
 Check if audio codec and video codec of file , is identical to we
supposed.
Parameters:
 p_filename(In)      : Point to absolute patch of file coded unicode
and the max length of buf is 260*2+2=522.
 video_codec(In)     : video codec we supposed
 audio_codec(In)     : audio codec we supposed
Return value:
 Result of the check.
   TRUE   if identical.
   FALSE  not identical.

*******************************************************************************************************/
kal_bool media_codec_type_check ( void *p_filename, Media_Check_Video_Codec video_codec, Media_Check_Audio_Codec audio_codec)
{
   Media_Check_Format eMediaFormat;
   Media_Check_Video_Codec eVidCodec;
   Media_Check_Audio_Codec eAudCodec;

   if(MEDIA_FORMAT_CHECK_SUCCESS != media_get_format_type(p_filename, &eMediaFormat))
      return KAL_FALSE;

   if(MEDIA_FORMAT_CHECK_SUCCESS != media_get_codec_type( p_filename, eMediaFormat, &eVidCodec, &eAudCodec))
      return KAL_FALSE;

   if((eVidCodec == video_codec) && (eAudCodec == audio_codec)){
      return KAL_TRUE;
   }else{
      return KAL_FALSE;
   }
}
