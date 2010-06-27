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
 * mp4_parser.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser
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

#include "mp4_parser.h"

#define SHOW_4_HEX(str, data)             \
   printf("%s:%x%x%x%x(hex)\n", str, (data[0]), (data[1]), (data[2]), (data[3]));

#define SHOW_4_CHAR(str, data)               \
   printf("%s:%c%c%c%c(char)\n", str, (data[0]), (data[1]), (data[2]), (data[3]));


        
/*
DESCRIPTION
   Parse the base class Box.
   The file pointer advances after the base class Box.
OUTPUT
   *size: The size of the box excluding Box
   *type: The type of the box
RETURN
   MP4_PARSER_OK: Successful
   MP4_PARSER_64BIT_NOT_SUPPORT: We do not support 64-bit integers
   MP4_PARSER_LARGER_31BIT_NOT_SUPPORT: We do not support numbers larger than 31 bits
*/
MP4_Parser_Status mp4_parse_box(STMp4Parser *pstMp4Parser, kal_uint32 *size, kal_uint32 *type)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(size!=NULL);
   MP4_PARSER_CHECK_ARG(type!=NULL);

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, type))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   #if MP4_PARSER_VERBOSE
   printf("type=%c%c%c%c size=%u\n",
      (*type>>24) & 0xFF, (*type>>16) & 0xFF, (*type>>8) & 0xFF, *type & 0xFF, *size);
   #endif
   if(*size==1) { /* large size indication */
      /* do not support large size */
      /* res = fread(&largesize, 8, 1, fpMp4);
         if(res!=1) break; */
      return MP4_PARSER_64BIT_NOT_SUPPORT;
   } else if (*size==0) {
      kal_uint32 cur_pos;
      // box extends to end of file
      if ((pstMp4Parser->eFSALErr = FSAL_GetFileSize(pstMp4Parser->pstFSAL, size)) != FSAL_OK )
         return MP4_PARSER_FILE_ACCESS_ERROR;
      
      if ((pstMp4Parser->eFSALErr = FSAL_GetCurPos(pstMp4Parser->pstFSAL, &cur_pos)) != FSAL_OK )
         return MP4_PARSER_FILE_ACCESS_ERROR;
      
      if( *size <= cur_pos )
         return MP4_PARSER_PARSE_ERROR;
      *size -= cur_pos;
      *size += 8;             // add back the sizes of chunk ID and chunk size fields
   }
/*
   if (type == BOX_TYPE_UUID) {
      unsigned char usertype[16];
      res = fread(&usertype, 16, 1, fpMp4);
      if(res!=1) break;
   } */
   /* Do not support size larger than 31 bits */
   if((*size)&0x80000000)
      return MP4_PARSER_LARGER_31BIT_NOT_SUPPORT;
   *size -= 8;
   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Seek to the specified atom in the specified range.
   The file pointer advances after the base class Box.
INPUT
   uBoxType: The type of box to look for
   uRange: Search inside the following uRange bytes
OUTPUT
   *uSizeBox: The size of the box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: refer to mp4_parse_box
*/

MP4_Parser_Status mp4_seek_atom(STMp4Parser *pstMp4Parser, kal_uint32 uBoxType, kal_uint32 uRange, kal_uint32 *uSizeBox)
{
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(uSizeBox!=NULL);

   while(uRange > 0) {
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      uRange -= 8;

      if(type==uBoxType) {
         *uSizeBox = size;
         return MP4_PARSER_OK;
      }
      else { /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      uRange -= size;
   }
   if (uRange!=0)
      return MP4_PARSER_PARSE_ERROR;
   return MP4_PARSER_ATOM_NOT_FOUND;
}

/*
DESCRIPTION
   Parse the base descriptor. (Refer to ISO 14496-1)
OUTPUT
   *type: The type of the box
   *size: The size of the box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/
static MP4_Parser_Status mp4_parse_base_descriptor(STMp4Parser *pstMp4Parser, kal_uint8 *tag, kal_uint32 *size)
{
   kal_uint8 tmp;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(tag!=NULL);
   MP4_PARSER_CHECK_ARG(size!=NULL);

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, tag, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &tmp, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   *size = (tmp & 0x7F);
   while(tmp&0x80) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &tmp, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      *size = ((*size) << 7) + (tmp & 0x7F);
   }
   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the File Type Box.
INPUT
   size: The size of File Type Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_ftyp(STMp4Parser *pstMp4Parser, kal_int32 ftyp_size)
{
   /* File Type Box is a leaf node. */
   kal_uint8 major_brand[4];
   kal_uint8 minor_version[4];
   /// kal_uint8 compatible_brand[4];

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if (ftyp_size<8)
      return MP4_PARSER_PARSE_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, major_brand, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   
   if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, minor_version, 4))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   ftyp_size -= 8;
#if MP4_PARSER_VERBOSE
   SHOW_4_CHAR("major_brand", major_brand);
   SHOW_4_HEX("minor_version", minor_version);
#endif

/// Rey: Directly skip the compatible brand to avoid long response time if the size of ftyp is corrupted.
/*
   for (i=0; i<ftyp_size/4; i++) {
      if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, compatible_brand, 4))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;     
#if MP4_PARSER_VERBOSE
      SHOW_4_CHAR("compatible_brand", compatible_brand);
#endif
      ftyp_size -= 4;
   }
*/

   if ((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, ftyp_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Movie Header Box.
INPUT
   size: The size of Movie Header Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   MP4_PARSER_PARSE_ERROR: Parse error
*/

static MP4_Parser_Status mp4_parse_mvhd(STMp4Parser *pstMp4Parser, kal_int32 mvhd_size)
{
   /* Move Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(mvhd_size<100)
      return MP4_PARSER_PARSE_ERROR;
 
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(version==1) /* We do not support 64 bit values. */
      return MP4_PARSER_64BIT_NOT_SUPPORT;

   /* creation_time */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   /* modification_time */
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &(pstMp4Parser->timescale)))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &(pstMp4Parser->duration)))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 76))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &(pstMp4Parser->next_track_ID)))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   mvhd_size -= 100;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mvhd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->bHasMVHD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Track Header Box.
INPUT
   size: The size of Track Header Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_tkhd(STMp4Parser *pstMp4Parser, kal_int32 tkhd_size)
{
   /* Track Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 creation_time;
   kal_uint32 modification_time;
   kal_uint32 track_ID;
   kal_uint32 duration;
   kal_uint32 width;
   kal_uint32 height;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(tkhd_size<84)
      return MP4_PARSER_PARSE_ERROR;
 
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if(version==1) /* We do not support 64 bit values. */
      return MP4_PARSER_64BIT_NOT_SUPPORT;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &creation_time))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &modification_time))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &track_ID))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &duration))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 52))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &width))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &height))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
#if MP4_PARSER_VERBOSE
   printf("track_ID=%u, width=%u, height=%u\n", track_ID, width>>16, height>>16);
#endif
   tkhd_size -= 84;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, tkhd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasTKHD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Media Header Box.
INPUT
   size: The size of Media Header Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_mdhd(STMp4Parser *pstMp4Parser, kal_int32 mdhd_size)
{
   /* Media Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 uTimeScale;
   kal_uint32 uDuration;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if (mdhd_size<24)
      return MP4_PARSER_PARSE_ERROR;
   
   if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if (version==1) /* We do not support 64 bit values. */
      return MP4_PARSER_64BIT_NOT_SUPPORT;

   /* creation_time */
   if ((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   /* modification_time */
   if ((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   
   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uTimeScale))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uDuration))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uMediaTimeScale = uTimeScale;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uMediaDuration = uDuration;

   /* ISO-639-2/T language code */
   if ((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   mdhd_size -= 24;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mdhd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMDHD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Handler Reference Box.
INPUT
   size: The size of Handler Reference Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_hdlr(STMp4Parser *pstMp4Parser, kal_int32 hdlr_size)
{
   /* Handler Reference Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 *puHandlerType;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(hdlr_size<24)
      return MP4_PARSER_PARSE_ERROR;
 
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   
   MP4_PARSER_ASSERT(pstMp4Parser->bCurTrack < MP4_NUM_TRACKS);

   puHandlerType = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].handler_type);

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puHandlerType))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   if (HDLR_TYPE_SOUN == *puHandlerType) {
      pstMp4Parser->bAudioTrack = pstMp4Parser->bCurTrack;
   } else if (HDLR_TYPE_VIDE == *puHandlerType) {
      pstMp4Parser->bVideoTrack = pstMp4Parser->bCurTrack;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 12))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   hdlr_size -= 24;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, hdlr_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasHDLR = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse Elementary Stream Descriptor(ESD) Box.
   Refer to 14496-14 and 14496-1.
INPUT
   size: The size of ESD Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_esds(STMp4Parser *pstMp4Parser, kal_int32 esds_size)
{
   /* ESD Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];

   /* ES Descriptor */
   kal_uint16 ES_ID;
   kal_uint8 flag;

   /* Decoder COnfig Descriptor */
   kal_uint8 objectTypeIndication;
   kal_uint8 streamType;
   kal_uint32 bufferSizeDB;
   kal_uint32 maxBitrate;
   kal_uint32 avgBitrate;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
  
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   esds_size -= 4;

   /* ES_Descriptor */
   {
      MP4_Parser_Status ret;
      kal_uint8 tag;
      kal_uint32 size;
      kal_uint32 pos1, pos2;

      MP4_PARSER_FILE_GET_CUR_POS(pos1);
      if((ret=mp4_parse_base_descriptor(pstMp4Parser, &tag, &size))!=MP4_PARSER_OK)
         return ret;
      MP4_PARSER_FILE_GET_CUR_POS(pos2);
      esds_size -= pos2-pos1;

      if(tag!=0x03) /* ES_DescrTag */
         return MP4_PARSER_ES_DESCR_TAG_EXPECTED;

      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &ES_ID))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &flag, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      esds_size -= 3;
   }

   /* DecoderConfigDescription */
   {
      MP4_Parser_Status ret;
      kal_uint8 tag;
      kal_uint32 size;
      kal_uint32 pos1, pos2;

      MP4_PARSER_FILE_GET_CUR_POS(pos1);
      if((ret=mp4_parse_base_descriptor(pstMp4Parser, &tag, &size))!=MP4_PARSER_OK)
         return ret;
      MP4_PARSER_FILE_GET_CUR_POS(pos2);
      esds_size -= (pos2-pos1);
      if(tag!=0x04) /* DecoderConfigDescrTag */
         return MP4_PARSER_PARSE_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &objectTypeIndication, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &streamType, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      streamType = (unsigned char)(streamType >> 2);

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, (kal_uint8*)&bufferSizeDB, 3))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      
      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &maxBitrate))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR; 
    
      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &avgBitrate))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR; 

      esds_size -= 13;
   }

   /* DecoderSpecificInfo */
   {
      MP4_Parser_Status ret;
      kal_uint8 tag;
      kal_uint32 size;
      kal_uint32 pos1, pos2;

      MP4_PARSER_FILE_GET_CUR_POS(pos1);
      if ((ret=mp4_parse_base_descriptor(pstMp4Parser, &tag, &size))!=MP4_PARSER_OK)
         return ret;
      MP4_PARSER_FILE_GET_CUR_POS(pos2);
      esds_size -= pos2-pos1;
      if (tag!=0x05) /* DecSpecificInfoTag */
         return MP4_PARSER_PARSE_ERROR;
      if (0x05==streamType) { /* streamType == Audio Stream */
         if (0x40==objectTypeIndication) {
            /* objectType == 14496-3 */
            mp4_parse_decoder_config_14496_3(pstMp4Parser, size);
            esds_size -= size;
            pstMp4Parser->bAudioType = MP4_AUDIO_AAC;
            pstMp4Parser->uAudioMaxBitrate = maxBitrate;
            pstMp4Parser->uAudioAvgBitrate = avgBitrate;
         } else if (objectTypeIndication==0xD0) {
            /* amr produced by PacketVideo Author, not standard */
         }
      } else if (0x04==streamType) { /* streamType == Visual Stream */
         if (0x20==objectTypeIndication) { 
            /* objectType == 14496-2 */
            /* for video, the following is video-object-sequence */
            pstMp4Parser->bVideoType = MP4_VIDEO_MPEG4;
            MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uVOSOffset);
            pstMp4Parser->uVOSSize = size;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         }
      }

   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, esds_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample Description Box.
INPUT
   size: The size of Sample Description Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stsd(STMp4Parser *pstMp4Parser, kal_int32 stsd_size)
{
   /* Sample Description Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &entry_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   stsd_size -= 8;

   if(entry_count>1)
      return MP4_PARSER_EXTERNAL_DATA_REFERENCE;
   else if(entry_count==1) {
      /* The following may be Audio Sample Entry or Visual Sample Entry */
      MP4_Parser_Status ret;
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;

      stsd_size -= 8;

      switch(type) {
      case SAMPLE_FMT_MP4V:
         if((ret=mp4_parse_mp4v(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case SAMPLE_FMT_MP4A:
         pstMp4Parser->uMP4A_FMT_size = size + 8 ;
         MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uMP4A_FMT_offset);
         if((ret=mp4_parse_mp4a(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case SAMPLE_FMT_SAMR:
         pstMp4Parser->bAudioType = MP4_AUDIO_AMR;
         if((ret=mp4_parse_samr(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case SAMPLE_FMT_SAWB:
         pstMp4Parser->bAudioType = MP4_AUDIO_AMR_WB;
         if((ret=mp4_parse_samr(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case SAMPLE_FMT_S263:
         pstMp4Parser->bVideoType = MP4_VIDEO_H263;
         if((ret=mp4_parse_s263(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      default:
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_PARSE_ERROR;
      }
      stsd_size -= size;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stsd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTSD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Decoding Time To Sample Box.
INPUT
   size: The size of Decoding Time To Sample Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_stts(STMp4Parser *pstMp4Parser, kal_int32 stts_size)
{
   /* Decoding Time To Sample Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &entry_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uTimeToSampleTableEntryCount = entry_count;
   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uOffsetTimeToSampleTable);
   stts_size-=8;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, entry_count*8))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   stts_size -= (entry_count*8);

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stts_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTTS = KAL_TRUE;
   
   /* Initilize STTS cache table */
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSTTSCacheTableEntryCount = 0;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSTTSCacheTableStepSize = 0;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].pSTTSCacheTable = NULL;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample To Chunk Box.
INPUT
   size: The size of Sample To Chunk Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_stsc(STMp4Parser *pstMp4Parser, kal_int32 stsc_size)
{
   /* Sample To Chunk Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   /* entry_count */
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &entry_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSampleToChunkEntryCount = entry_count;
   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uOffsetSampleToChunkTable);
   stsc_size-=8;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, entry_count*12))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   stsc_size -= (entry_count*12);

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stsc_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTSC = KAL_TRUE;
   
   /* Initilize STSC cache table */
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSTSCCacheTableEntryCount = 0;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSTSCCacheTableStepSize = 0;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].pSTSCCacheTable = NULL;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample Sizes Box.
INPUT
   size: The size of Sample Sizes Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stsz(STMp4Parser *pstMp4Parser, kal_int32 stsz_size)
{
   /* Sample Sizes Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 sample_size;
   kal_uint32 sample_count;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   /* sample_size */
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &sample_size))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 
   
   if(sample_size!=0) {
     pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uConstantSampleSize = sample_size;
   } else {
     pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uConstantSampleSize = 0;
   }

   /* sample_count */
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &sample_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSampleCount = sample_count;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bSampleCountUpdated = KAL_FALSE;

   stsz_size-=12;

   if(sample_size==0) {
      MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uOffsetSampleSizeTable);
      if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, sample_count*4))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR;
      stsz_size -= (sample_count*4);
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stsz_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Chunk Offset Box.
INPUT
   size: The size of Chunk Offset Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stco(STMp4Parser *pstMp4Parser, kal_int32 stco_size)
{
   /* Chunk Offset Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   /* entry_count */
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &entry_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uChunkCount = entry_count;

   stco_size-=8;

   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uOffsetChunkOffsetTable);
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, entry_count*4))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   stco_size-=(entry_count*4);

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stco_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTCO = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sync Sample Table Box.
INPUT
   size: The size of Sync Sample Table Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_stss(STMp4Parser *pstMp4Parser, kal_int32 stss_size)
{
   /* Sync Sample Table Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   
   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &entry_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR; 

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSyncCount = entry_count;

   stss_size-=8;

   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uOffsetSyncSampleTable);
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, entry_count*4))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   stss_size-=(entry_count*4);

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stss_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
      
   /* Initilize STSS cache table */
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSTSSCacheTableEntryCount = 0;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].uSTSSCacheTableStepSize = 0;
   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].pSTSSCacheTable = NULL;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTSS = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample Table Box.
INPUT
   size: The size of Sample Table Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stbl(STMp4Parser *pstMp4Parser, kal_int32 stbl_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* look for possible nodes of stbl's direct childs */
   while(stbl_size>0) {
      MP4_Parser_Status ret;
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      stbl_size-=8;

      switch(type) {
      case BOX_TYPE_STSD:
         if((ret=mp4_parse_stsd(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_STTS:
         if((ret=mp4_parse_stts(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_STSC:
         if((ret=mp4_parse_stsc(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_STSZ:
         if((ret=mp4_parse_stsz(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_STCO:
         if((ret=mp4_parse_stco(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_STSS:
         if((ret=mp4_parse_stss(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      stbl_size-=size;
   }
   
   if (stbl_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTBL = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Media Information Box.
INPUT
   size: The size of Media Information Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_minf(STMp4Parser *pstMp4Parser, kal_int32 minf_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* look for possible nodes of minf's direct childs */
   while(minf_size>0) {
      MP4_Parser_Status ret;
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      minf_size-=8;

      switch(type) {
      case BOX_TYPE_STBL:
         if((ret=mp4_parse_stbl(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      minf_size -= size;
   }

   if (minf_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMINF = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Media Box.
INPUT
   size: The size of Media Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Parse error
*/

static MP4_Parser_Status mp4_parse_mdia(STMp4Parser *pstMp4Parser, kal_int32 mdia_size)
{
   MP4_Parser_Status ret;
   kal_uint32 uCurPos;
   kal_uint32 uSizeHdlr;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* Look for hdlr first.
   It's because some boxes under minf may depend on the hdlr,
   however, hdlr does not always come before minf.
   It also let us recognize the type of the track (video or audio)
   before we encounter sample table.
   */

   MP4_PARSER_FILE_GET_CUR_POS(uCurPos);
   if((ret=mp4_seek_atom(pstMp4Parser, BOX_TYPE_HDLR, mdia_size, &uSizeHdlr))!=MP4_PARSER_OK)
      return ret;
   if((ret=mp4_parse_hdlr(pstMp4Parser, uSizeHdlr))!=MP4_PARSER_OK)
      return ret;
   if((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uCurPos))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   /* Look for possible nodes of mdia's direct childs */
   while(mdia_size > 0) {
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      mdia_size -= 8;

      switch(type) {
      case BOX_TYPE_MDHD:
         if((ret=mp4_parse_mdhd(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_HDLR:
         if((ret=mp4_parse_hdlr(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_MINF:
         if((ret=mp4_parse_minf(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      mdia_size -= size;
   }
   
   if (mdia_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMDIA = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Track Box.
INPUT
   size: The size of Track Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Parse error
*/

static MP4_Parser_Status mp4_parse_trak(STMp4Parser *pstMp4Parser, kal_int32 trak_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* look for possible nodes of trak's direct childs */

   /* Initialize Track Structure of Current Track */
   kal_mem_set(&(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]), 0, sizeof(STMp4Track));

   while(trak_size > 0) {
      MP4_Parser_Status ret;
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      trak_size -= 8;

      switch(type) {
      case BOX_TYPE_TKHD:
         if((ret=mp4_parse_tkhd(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_MDIA:
         if((ret=mp4_parse_mdia(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      trak_size -= size;
   }

   if (trak_size!=0)
      return MP4_PARSER_PARSE_TRAK_ERROR;

   /* Check the existence of mandatory atoms */
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasTKHD != KAL_TRUE)
      return MP4_PARSER_NO_TKHD;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMDIA != KAL_TRUE)
      return MP4_PARSER_NO_MDIA;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMDHD != KAL_TRUE)
      return MP4_PARSER_NO_MDHD;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasHDLR != KAL_TRUE)
      return MP4_PARSER_NO_HDLR;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMINF != KAL_TRUE)
      return MP4_PARSER_NO_MINF;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTBL != KAL_TRUE)
      return MP4_PARSER_NO_STBL;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTSD != KAL_TRUE)
      return MP4_PARSER_NO_STSD;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTTS != KAL_TRUE)
      return MP4_PARSER_NO_STTS;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTSC != KAL_TRUE)
      return MP4_PARSER_NO_STSC;
   if (pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTCO != KAL_TRUE)
      return MP4_PARSER_NO_STCO; 

   {
      kal_uint32 uHandlerType = pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].handler_type;
      if (HDLR_TYPE_SOUN == uHandlerType || HDLR_TYPE_VIDE == uHandlerType) {
         pstMp4Parser->bCurTrack++;
         if(pstMp4Parser->bCurTrack>=MP4_NUM_TRACKS)
            return MP4_PARSER_TOO_MANY_TRACKS;
      }
   }

   pstMp4Parser->bHasTRAK = KAL_TRUE;
   
   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Movie Box.
INPUT
   size: The size of Movie Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_moov(STMp4Parser *pstMp4Parser, kal_int32 moov_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uMOOVOffset);

   /* look for possible nodes of moov's direct childs */
   while(moov_size > 0) {
      MP4_Parser_Status ret;
      kal_uint32 size;
      kal_uint32 type;

      if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      moov_size -= 8;

      switch(type) {
      case BOX_TYPE_MVHD:
         if((ret=mp4_parse_mvhd(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_TRAK:
         if((ret=mp4_parse_trak(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
/*    case BOX_TYPE_MVEX:
         break; */
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      moov_size -= size;
   }

   if (moov_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->bHasMOOV = KAL_TRUE;

   return MP4_PARSER_OK;
}



static MP4_Parser_Status post_processing(STMp4Parser *pstMp4Parser)
{
   MP4_Parser_Status ret;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /// Check the existence of mandatory atoms
   if (pstMp4Parser->bHasMOOV != KAL_TRUE)
      return MP4_PARSER_NO_MOOV;
   if (pstMp4Parser->bHasMVHD != KAL_TRUE)
      return MP4_PARSER_NO_MVHD;
   if (pstMp4Parser->bHasTRAK != KAL_TRUE)
      return MP4_PARSER_NO_TRAK;

   /// Prepare AAC frame header if necessary
   if ((ret=prepareAACFrameHeader(pstMp4Parser))!=MP4_PARSER_OK)
      return ret;
      
   return MP4_PARSER_OK;
}

/*--------- Public Functions ---------*/

/* 
DESCRIPTION
   Parse a MP4/3GPP file.
RETURN
   MP4_PARSER_OK: Successful
   other values: Not a correct MP4/3GPP file
*/
MP4_Parser_Status MP4_Parse(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret=MP4_PARSER_OK;
   kal_int32 iFileLeftLen;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   /* Initialize Structure */
   pstMp4Parser->bCurTrack = 0;
   pstMp4Parser->bAudioTrack = MP4_RESERVED_TRACK_NO;
   pstMp4Parser->bVideoTrack = MP4_RESERVED_TRACK_NO;
   pstMp4Parser->bAudioType = MP4_AUDIO_NONE;
   pstMp4Parser->bVideoType = MP4_VIDEO_NONE;
   pstMp4Parser->bHasMOOV = KAL_FALSE;
   pstMp4Parser->bHasMVHD = KAL_FALSE;
   pstMp4Parser->bHasTRAK = KAL_FALSE;
   pstMp4Parser->bAddADTSFrameHeader = KAL_FALSE;
   pstMp4Parser->bAddADIFFrameHeader = KAL_FALSE;

   pstMp4Parser->pstFSAL = pstFSAL;
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   
   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&iFileLeftLen))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   while(iFileLeftLen > 7) {  // iFileLeftLen should >= 8 to guarantee the existence of chunk ID and chunk zise
      kal_uint32 size;
      kal_uint32 type;

      if ((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      iFileLeftLen -= 8;

      switch (type) {
      case BOX_TYPE_FTYP: {
         if ((ret=mp4_parse_ftyp(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      }
      case BOX_TYPE_MOOV: {
         if ((ret=mp4_parse_moov(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      }
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      if ((kal_uint32)iFileLeftLen < size)
         break;
      iFileLeftLen -= size;
#if MP4_PARSER_VERBOSE
      printf("iFileLeftLen=%d\n", iFileLeftLen);
#endif
   }
   if ((ret = post_processing(pstMp4Parser)) != MP4_PARSER_OK)
      return ret;

   if (iFileLeftLen != 0)
      return MP4_PARSER_WARNING_TRAILING_GARBAGE;

#if defined(MP4_CODEC)
   if (pstMp4Parser->bAudioType == MP4_AUDIO_AAC) {
      if (0 == Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(MEDIA_FORMAT_AAC,
                                                 pstMp4Parser->bAudioSamplingFreqIndex)) {
         pstMp4Parser->bAudioType = MP4_AUDIO_NONE;
         pstMp4Parser->bAudioTrack = MP4_RESERVED_TRACK_NO;

      }
   }
#endif // #if defined(MP4_CODEC)

   return MP4_PARSER_OK;
}

MP4_Parser_Status MP4_MetaHasAudioTrack(STMp4Parser *pstMp4Parser, kal_bool *pfAudTrack)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(pstMp4Parser->bAudioTrack == MP4_RESERVED_TRACK_NO)
      *pfAudTrack = KAL_FALSE;
   else
      *pfAudTrack = KAL_TRUE;
      
   return MP4_PARSER_OK;

}

MP4_Parser_Status MP4_MetaHasVideoTrack(STMp4Parser *pstMp4Parser, kal_bool *pfVidTrack)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(pstMp4Parser->bVideoTrack == MP4_RESERVED_TRACK_NO)
      *pfVidTrack = KAL_FALSE;
   else
      *pfVidTrack = KAL_TRUE;
   
   return MP4_PARSER_OK;

}

void MP4_Parser_Clone(STMp4Parser *pstMp4Parser_Src, STMp4Parser *pstMp4Parser_Dst, STFSAL *pstFSAL_Dst)
{
   MP4_PARSER_ASSERT_NO_RET_VAL(pstMp4Parser_Src!=NULL);
   MP4_PARSER_ASSERT_NO_RET_VAL(pstMp4Parser_Dst!=NULL);
   MP4_PARSER_ASSERT_NO_RET_VAL(pstFSAL_Dst!=NULL);
   kal_mem_cpy(pstMp4Parser_Dst, pstMp4Parser_Src, sizeof(STMp4Parser));
   pstMp4Parser_Dst->pstFSAL = pstFSAL_Dst;
}

MP4_Parser_Status MP4_GetMdatBoxOffset(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, kal_uint32 *puMetaOffset)
{
   MP4_Parser_Status ret=MP4_PARSER_OK;
   kal_int32 iFileLeftLen;
   kal_uint32 uSizeTmp;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   pstMp4Parser->pstFSAL = pstFSAL;
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   
   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&iFileLeftLen))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   uSizeTmp = 0;
   while(iFileLeftLen > 7) {  // iFileLeftLen should >= 8 to guarantee the existence of chunk ID and chunk zise
      kal_uint32 size;
      kal_uint32 type;

      if ((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      iFileLeftLen -= 8;

      switch (type) {
      case BOX_TYPE_FTYP: {
         if ((ret=mp4_parse_ftyp(pstMp4Parser, size))!=MP4_PARSER_OK)
            return ret;
         break;
      }
      case BOX_TYPE_MOOV: {		 
         MP4_PARSER_FILE_GET_CUR_POS(uSizeTmp);
		 uSizeTmp += size;
		 *puMetaOffset = uSizeTmp;
         return MP4_PARSER_OK;
      }
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      if ((kal_uint32)iFileLeftLen < size)
         break;
      iFileLeftLen -= size;
   }
   return MP4_PARSER_NO_MOOV;
}

MP4_Parser_Status MP4_IsPDProfile(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, kal_bool *pfPD)
{
   MP4_Parser_Status ret=MP4_PARSER_OK;
   kal_int32 iFileLeftLen;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_CHECK_ARG(pstFSAL!=NULL);

   pstMp4Parser->pstFSAL = pstFSAL;
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   
   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&iFileLeftLen))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   while(iFileLeftLen > 7) {  // iFileLeftLen should >= 8 to guarantee the existence of chunk ID and chunk zise
      kal_uint32 size;
      kal_uint32 type;

      if ((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
         return ret;
      iFileLeftLen -= 8;

      switch (type) {
      case BOX_TYPE_FTYP: {
         kal_uint32 major_brand;

         if (size<8)
            return MP4_PARSER_PARSE_ERROR;

         if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, (kal_uint8 *)&major_brand, 4))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;

		 if(major_brand == 0x36726733) // "3gr6"
            *pfPD = KAL_TRUE;
		 else
			*pfPD = KAL_FALSE;

         return MP4_PARSER_OK;
      }

      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      if ((kal_uint32)iFileLeftLen < size)
         break;
      iFileLeftLen -= size;
   }
   return MP4_PARSER_PARSE_ERROR;
}