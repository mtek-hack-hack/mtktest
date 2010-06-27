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
 * mp4_parser_video.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser, for handling visual-related boxes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "mp4_parser.h"

/*
DESCRIPTION
	Parse Bitrate Box.
INPUT
	size: The size of Bitrate Box excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

static MP4_Parser_Status mp4_parse_bitr(STMp4Parser *pstMp4Parser, long bitr_size)
{
   kal_uint32 uAvgBitrate;
   kal_uint32 uMaxBitrate;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

	if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uAvgBitrate))!=FSAL_OK)
		return MP4_PARSER_FILE_READ_ERROR;

	if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uMaxBitrate))!=FSAL_OK)
		return MP4_PARSER_FILE_READ_ERROR;

   bitr_size -= 8;

	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, bitr_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
	Parse H263 Specific Box.
INPUT
	size: The size of H263 Specific Box excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

static MP4_Parser_Status mp4_parse_d263(STMp4Parser *pstMp4Parser, long d263_size)
{
   MP4_Parser_Status ret;
	kal_uint8 bH263Level;
	kal_uint8 bH263Profile;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

	/* H263 Decoder Specific Structure */
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 5))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &bH263Level, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &bH263Profile, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   
	d263_size-=7;

   if(d263_size==0)
      return MP4_PARSER_OK;

   /* optional Specific bitrate information */
	{
		kal_uint32 size;
		kal_uint32 type;

		if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
			return ret;

		if(BOX_TYPE_BITR==type) {
			if((ret=mp4_parse_bitr(pstMp4Parser, size))!=MP4_PARSER_OK)
				return ret;
		} else
			return MP4_PARSER_BITR_BOX_EXPECTED;
	}

	return MP4_PARSER_OK;
}



/*
DESCRIPTION
	Parse Sample Entry H263.
INPUT
	size: The size of Sample Entry H263 excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

MP4_Parser_Status mp4_parse_s263(STMp4Parser *pstMp4Parser, long s263_size)
{
   MP4_Parser_Status ret;
	kal_uint16 width, height;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

	/* Sample Entry */
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
	s263_size-=8;

	/* Visual Sample Entry */
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 16))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &width))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &height))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 50))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

	s263_size-=56;
#if MP4_PARSER_VERBOSE
	printf("width=%u, height=%u\n", width, height);
#endif

	/* H263 Specific Box */
	{
		kal_uint32 size;
		kal_uint32 type;

		if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
			return ret;
		if(BOX_TYPE_D263==type) {
			if((ret=mp4_parse_d263(pstMp4Parser, size))!=MP4_PARSER_OK)
				return ret;
		} else
			return MP4_PARSER_D263_BOX_EXPECTED;
	}

	return MP4_PARSER_OK;
}



/*
DESCRIPTION
	Parse Sample Entry MP4V.
INPUT
	size: The size of Sample Entry MP4V excluding Box
RETURN
	MP4_PARSER_OK: Successful
	other values: Error
*/

MP4_Parser_Status mp4_parse_mp4v(STMp4Parser *pstMp4Parser, long mp4v_size)
{
   MP4_Parser_Status ret;
	kal_uint16 width, height;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

	/* Sample Entry */
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
	mp4v_size-=8;

	/* Visual Sample Entry */
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 16))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &width))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &height))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 50))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

	mp4v_size-=70;
#if MP4_PARSER_VERBOSE
	printf("width=%u, height=%u\n", width, height);
#endif

	/* ESDBox */
	{
		kal_uint32 size, type;

		if((ret=mp4_parse_box(pstMp4Parser, &size, &type))!=MP4_PARSER_OK)
			return ret;

		mp4v_size-=8;
		if(type==BOX_TYPE_ESDS) {
			if((ret=mp4_parse_esds(pstMp4Parser, size))!=MP4_PARSER_OK)
				return ret;
		} else
			return MP4_PARSER_PARSE_ERROR;

		mp4v_size-=size;
	}

    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mp4v_size))!=FSAL_OK)
       return MP4_PARSER_FILE_SEEK_ERROR;

	return MP4_PARSER_OK;
}

#if 0
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
#if MP4_PARSER_VERBOSE
/* under construction !*/
#endif
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
#if MP4_PARSER_VERBOSE
/* under construction !*/
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
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
#if MP4_PARSER_VERBOSE
/* under construction !*/
#endif
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


