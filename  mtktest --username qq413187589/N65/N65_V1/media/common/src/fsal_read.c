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
 * fsal_read.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   File System Abstraction Layer, read-accessing functions.
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
  * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "fsal.h"



FSAL_Status FSAL_Read_Bytes(STFSAL *pstFSAL, kal_uint8 *pbData, kal_uint32 uLen)
{
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
	FSAL_CHECK_ARG(pbData!=NULL);

   if((ret=FSAL_Read(pstFSAL, pbData, uLen))!=FSAL_OK) {
		return ret;
   }

	return FSAL_OK;
}



FSAL_Status FSAL_Read_Bits(STFSAL *pstFSAL, kal_uint32 *puBitCnt, kal_uint8 *pbValue, kal_uint32 uBitLen)
{
	static kal_uint8 bCurByte;
   FSAL_Status ret;
	kal_uint8 bMask;
	kal_uint32 uCurBitPos;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(puBitCnt!=NULL);
   FSAL_CHECK_ARG(pbValue!=NULL);
	FSAL_ASSERT(uBitLen>=1 && uBitLen<=8);
	uCurBitPos = *puBitCnt % 8;

	if(uCurBitPos==0) {
      if((ret=FSAL_Read_Bytes(pstFSAL, &bCurByte, 1))!=FSAL_OK)
         return ret;
	}

	if(uCurBitPos+uBitLen<=8) {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		*pbValue = (unsigned char)((bCurByte&bMask) >> (8-(uCurBitPos+uBitLen)));
	} else {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		*pbValue = (unsigned char)((bCurByte&bMask) << (uBitLen-(8-uCurBitPos)));
      if((ret=FSAL_Read_Bytes(pstFSAL, &bCurByte, 1))!=FSAL_OK)
         return ret;
		*pbValue |= bCurByte>>(16-uBitLen-uCurBitPos);
	}
	*puBitCnt += uBitLen;

	return FSAL_OK;
}



FSAL_Status FSAL_Read_UINT(STFSAL *pstFSAL, kal_uint32 *puValue)
{
	kal_uint8 data[4];
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
	FSAL_CHECK_ARG(puValue!=NULL);

   if((ret=FSAL_Read_Bytes(pstFSAL, data, 4))!=FSAL_OK)
      return ret;

	*puValue = (kal_uint32)((data[0]<<24) + (data[1]<<16) + (data[2]<<8) + (data[3]));

	return FSAL_OK;
}



FSAL_Status FSAL_Read_UINT24(STFSAL *pstFSAL, kal_uint32 *puValue)
{
	kal_uint8 data[3];
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
	FSAL_CHECK_ARG(puValue!=NULL);

   if((ret=FSAL_Read_Bytes(pstFSAL, data, 3))!=FSAL_OK)
      return ret;

	*puValue = (kal_uint32)((data[0]<<16) + (data[1]<<8) + (data[2]));

	return FSAL_OK;
}



FSAL_Status FSAL_Read_UINT16(STFSAL *pstFSAL, kal_uint16 *pwValue)
{
	kal_uint8 data[2];
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
	FSAL_CHECK_ARG(pwValue!=NULL);

   if((ret=FSAL_Read_Bytes(pstFSAL, data, 2))!=FSAL_OK)
      return ret;

	*pwValue = (kal_uint16)((data[0]<<8) + (data[1]));

	return FSAL_OK;
}



FSAL_Status FSAL_Skip_Bytes(STFSAL *pstFSAL, kal_uint32 uLen)
{
   kal_uint32 uCurPos;
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);

   if ((ret=FSAL_GetCurPos(pstFSAL, &uCurPos))!=FSAL_OK)
      return ret;

   if ((ret=FSAL_Seek(pstFSAL, uCurPos+uLen))!=FSAL_OK)
      return ret;

	return FSAL_OK;
}


FSAL_Status FSAL_Peek_Bytes(STFSAL *pstFSAL, kal_uint8 *pbValue, kal_uint32 uLen)
{
   kal_uint32 uCurPos;
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(pbValue!=NULL);

   if ((ret=FSAL_GetCurPos(pstFSAL, &uCurPos))!=FSAL_OK)
      return ret;

   if ((ret=FSAL_Read_Bytes(pstFSAL, pbValue, uLen))!=FSAL_OK) {
      if (ret == FSAL_READ_OVER_EOF) {
         FSAL_Seek(pstFSAL, uCurPos);
      }
      return ret;
   }

   if ((ret=FSAL_Seek(pstFSAL, uCurPos))!=FSAL_OK)
      return ret;

	return FSAL_OK;
}



FSAL_Status FSAL_Peek_UINT(STFSAL *pstFSAL, kal_uint32 *puValue)
{
   kal_uint32 uCurPos;
   FSAL_Status ret;

   FSAL_CHECK_ARG(pstFSAL!=NULL);
   FSAL_CHECK_ARG(puValue!=NULL);

   if ((ret=FSAL_GetCurPos(pstFSAL, &uCurPos))!=FSAL_OK)
      return ret;
   
	if((ret=FSAL_Read_UINT(pstFSAL, puValue))!=FSAL_OK)
		return ret;
   
   if((ret=FSAL_Seek(pstFSAL, uCurPos))!=FSAL_OK) 
      return ret;

	return FSAL_OK;
}


