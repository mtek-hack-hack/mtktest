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
 *   bl_loader.h
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   Bootloader header, loading related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _BOOTLOADER_LOADER_H
#define _BOOTLOADER_LOADER_H


typedef enum 
{
   NFI_SUCCESS                =  0,      
   NFI_ECC_1BIT_CORRECT       =  1,   
   NFI_ZERO_POINTER           = -1,   
   NFI_READ_DATA_TIMEOUT      = -2,
   NFI_READ_SPARE_TIMEOUT     = -3,
   DMA_TRANSFER_DATA_TIMEOUT  = -4,
   DMA_TRANSFER_SPARE_TIMEOUT = -5,
   NFI_ECC_2BITS_ERR          = -6
} _RET_CODE;


/* Data Structures */
typedef struct _NFIType
{
   kal_uint16  IOInterface;     /* IO_8BITS or IO_16BITS */
   kal_uint16  pageSize;        /* 512, 2048 */
   kal_uint16  addressCycle;
   kal_uint16  pageShift;
} NFI_MENU;


typedef struct _BOOTLHeader_
{
   kal_char    ID1[12];
   kal_char    version[4];
   kal_uint32  length;
   kal_uint32  startAddr;
   kal_uint32  checksum;
   kal_char    ID2[8];
   NFI_MENU    NFIinfo;
   kal_uint16  pagesPerBlock;   
   kal_uint16  totalBlocks;
   kal_uint16  blockShift;
   kal_uint16  linkAddr[6];
   kal_uint16  lastBlock;
} BOOTL_HEADER;


typedef struct {
	kal_uint32  m_load_addr;   /* destination address at shadow RAM */
	kal_uint32  m_length;      /* length of certain image */
	kal_uint32  m_start_block; /* the started block number */
	kal_uint32  m_reserved;
} Nand_ImageInfo_S;


typedef struct {
	Nand_ImageInfo_S	m_image[10];
	kal_uint32        m_image_count;
} Nand_ImageList_S;


typedef struct _NFIAccess
{
   kal_uint32  readAddr1;
   kal_uint32  readAddr2;
} NFI_ACCESS;
           
                  
#endif
