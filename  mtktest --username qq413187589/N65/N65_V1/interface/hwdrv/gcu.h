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
 *    gcu.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for gcu driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef GCU_H
#define GCU_H

#include "drv_features.h"

#if defined(DRV_GCU_REG_32BITS)
/*Must include drv_comm.h*/
	#define GCU_CTRL	         (GCU_base+0x0)
	#define GCU_STAT	         (GCU_base+0x4)
	#define GCU_KC0			   (GCU_base+0x8)
	#define GCU_KC1			   (GCU_base+0xc)
	#define GCU_INPUT		      (GCU_base+0x10)
	#define GCU_AVADATA		   (GCU_base+0x14)
   
	#define GCU_CTRL_GEA2		0x0001
	
   #if defined(DRV_GCU_GEA3)
	#define GCU_CTRL_GEA3		0x0002
	#define GCU_CTRL_DIR		   0x0004
	#define GCU_CTRL_SINIT     0x0008
	#define GCU_CTRL_KSMASK    0x0030
	#else
	#define GCU_CTRL_DIR		   0x0002
	#define GCU_CTRL_SINIT     0x0004
	#define GCU_CTRL_KSMASK    0x0018
	#endif
   #if defined(DRV_GCU_GEA3)
	   #define GCU_CTRL_RBO    0x0040		
   #else
	   #define GCU_CTRL_RBO    0x0020
   #endif

   
   #if defined(DRV_GCU_GEA3)
   //32 bits, gea1 algorithm, and DIR = 0
   #define GCU_CTRL_NORMAL		0x0020
   #else
	//32 bits, gea1 algorithm, and DIR = 0
	#define GCU_CTRL_NORMAL		0x0010
   #endif 

	#define GCU_STAT_INIT		0x0002
	#define GCU_STAT_BUZY		0x0004
	#define GCU_STAT_STATMASK	0xe000
	#define GCU_STAT_KEYMASK	0x0006

	typedef struct __gcu_input
	{
		kal_uint16 SK0;
		kal_uint16 SK1;
		kal_uint16 SK2;
		kal_uint16 SK3;
		
		kal_uint16 MK0;
		kal_uint16 MK1;
		kal_bool   DIRECTION;   /*=1 or = 0*/
	} gcu_input;

	#define GCU_GEA1Start()  	(DRV_Reg32(GCU_CTRL) |= GCU_CTRL_SINIT)
	#define GCU_GEA2Start() 	(DRV_Reg32(GCU_CTRL) |= (GCU_CTRL_GEA2|GCU_CTRL_SINIT))
	#if defined(DRV_GCU_GEA3)
	#define GCU_GEA3Start() 	(DRV_Reg32(GCU_CTRL) |= (GCU_CTRL_GEA3|GCU_CTRL_SINIT))	
   #endif
	#define GCU_ReadKey(_data) \
	{\
		while(DRV_Reg32(GCU_STAT) & GCU_STAT_KEYMASK);\
		_data = DRV_Reg32(GCU_AVADATA);\
	}

	//

	extern kal_bool GCU_isBUZY(void);
	extern void GCU_InputData(gcu_input *data);
	//extern kal_uint32 GCU_ReadKey(void);
#else
	/*Must include drv_comm.h*/
	#define GCU_CTRL	         (GCU_base+0x0)
	#define GCU_STAT	         (GCU_base+0x4)
	#define GCU_KC0		      (GCU_base+0x8)
	#define GCU_KC1		      (GCU_base+0xc)
	#define GCU_KC2		      (GCU_base+0x10)
	#define GCU_KC3		      (GCU_base+0x14)
	#define GCU_INPUT0	      (GCU_base+0x18)
	#define GCU_INPUT1	      (GCU_base+0x1c)
	#define GCU_AVADATA	      0x78000000

	#define GCU_CTRL_GEA2		0x0001
	#define GCU_CTRL_DIR		   0x0002
	#define GCU_CTRL_SINIT     0x0004
	#define GCU_CTRL_KSMASK    0x0018

	//32 bits, gea1 algorithm, and DIR = 0
	#define GCU_CTRL_NORMAL		0x0010


	#define GCU_STAT_INIT		0x0002
	#define GCU_STAT_BUZY		0x0004
	#define GCU_STAT_STATMASK	0xe000
	#define GCU_STAT_KEYMASK	0x0006

	typedef struct __gcu_input
	{
		kal_uint16 SK0;
		kal_uint16 SK1;
		kal_uint16 SK2;
		kal_uint16 SK3;
		
		kal_uint16 MK0;
		kal_uint16 MK1;
		kal_bool   DIRECTION;   /*=1 or = 0*/
	} gcu_input;

	#define GCU_GEA1Start()  	(DRV_Reg(GCU_CTRL) |= GCU_CTRL_SINIT)
	#define GCU_GEA2Start() 	(DRV_Reg(GCU_CTRL) |= (GCU_CTRL_GEA2|GCU_CTRL_SINIT))


	#define GCU_ReadKey(_data) \
	{\
		while(DRV_Reg(GCU_STAT) & GCU_STAT_KEYMASK);\
		_data = DRV_Reg32(GCU_AVADATA);\
	}

	//

	extern kal_bool GCU_isBUZY(void);
	extern void GCU_InputData(gcu_input *data);
	//extern kal_uint32 GCU_ReadKey(void);
#endif	/*DRV_GCU_REG_32BITS*/

extern kal_bool gea_cidecipher (kal_uint8 *src_buff_ptr,
	   kal_uint8 *dest_buff_ptr,	
	   kal_uint16 buff_len,
	   kal_uint8 cipher_algo,	   
	   kal_bool direction,
	   kal_uint8 *input_sk,
	   kal_uint32 input_mk);

#endif


