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
 *   bl_NFI.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   NANDFlash driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include <kal_release.h>
#include <bl_loader.h>
#include <bl_NFI.h>

      //------------------------------------------------------- 
		// 512 page size spare area definition                    
		//------------------------------------------------------- 
		//                                                        
		// |... PAGE DATA ...|...SPARE...|E0|NG|CHK|              
		//                                                        
		//  We store the ECC parity, next good block address and  
		//  spare checksum in the last 2 DWORDs of spare data.    
		//                                                        
		//  E0 -> 4 bytes block-0 ECC parity. (PARITY 6~7)        
		//  NG -> 2 bytes row addr point to next good block.      
		//  CHK -> 2 bytes (16bits) checksum.                     
		//                             
		//------------------------------------------------------- 
		// 2048 page size spare area definition                   
		//------------------------------------------------------- 
		//                                                        
		// |... PAGE DATA ...|...SPARE...|E0|E1|E2|E3|NG|CHK|     
		//                                                        
		//  We store the ECC parity, next good block address and  
		//  spare checksum in the last 5 DWORDs of spare data.    
		//                                                        
		//  E0 -> 4 bytes block-0 ECC parity. (PARITY 0~1)        
		//  E1 -> 4 bytes block-1 ECC parity. (PARITY 2~3)        
		//  E2 -> 4 bytes block-2 ECC parity. (PARITY 4~5)        
		//  E3 -> 4 bytes block-3 ECC parity. (PARITY 6~7)        
		//  NG -> 2 bytes row addr point to next good block.      
		//  CHK -> 2 bytes 16bits checksum.                       
		//                                                                  

typedef union 
{
	kal_uint8  	d8[4];
	kal_uint16  d16[2];
	kal_uint32  d32;
} UnionData_U;


#ifdef BIT_ERROR_TEST

extern BOOTL_HEADER  BLHeader;   

void EmulateBitError(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize)
{
	kal_uint8 BitNo, status, Sector, Mask;
	kal_uint32 Offset, MagicNum;
	kal_bool EmulatedBitError;
	kal_uint8 *Ptr = (kal_uint8 *)destination;


	NFI_PageRead(destination, parity, pageSize, addr_no, addr1, addr2, pageSize, KAL_TRUE, KAL_FALSE);
	status = NFI_ParityCheck(destination, parity, addr_no, addr1, addr2, \
								pageSize, BLHeader.NFIinfo.IOInterface, \
								BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          
	if (status != NFI_SUCCESS) {
		dbg_print(" Original data has error. No need to emulate bit error. status=%x \n\r", status);
		return;
	}

	for(Sector=0; Sector<(pageSize/0x200); Sector++) {
		EmulatedBitError = KAL_FALSE;
		if(pageSize < 1024) {
			MagicNum = (addr1>>16) ^ (addr1>>8);
		} else {
			MagicNum = (addr1>>16) ^ (addr1>>24);
		}
		for(Offset=(MagicNum & 0x1ff); Offset<0x200; Offset++) {
			Mask = 0x01;
			for(BitNo=0; BitNo<8; BitNo++) {
				if(Ptr[Sector*0x200+Offset] & Mask) {
					dbg_print("***[Emulate] Offset = %x, Original data = %x", addr1+(Sector*0x200)+Offset, Ptr[Sector*0x200+Offset]);
					Ptr[Sector*0x200+Offset] = Ptr[Sector*0x200+Offset] & (~Mask);
					dbg_print(" New data  = %x \n\r", Ptr[Sector*0x200+Offset]);
					EmulatedBitError = KAL_TRUE;
					break;
				}
				Mask = Mask << 1;
			}
			if(EmulatedBitError==KAL_TRUE) {
				break;
			}
		}
	}

	*NFI_FIFOCON = RESET;
	*NFI_CON = 0;
	if(pageSize<1024) {
		*NFI_CMD = RD_1ST_CMD;             // Set poiner to 0.
		while (*NFI_PSTA & STATUS_CMD);
		*NFI_OPCON = 0;
		while (*NFI_PSTA & STATUS_CMD);
		*NFI_FIFOCON = RESET;			
	}
	*NFI_CMD = INPUT_DATA_CMD;                  // Issue data input command
	while (*NFI_PSTA & STATUS_CMD);
	*NFI_ADDRL = addr1;
	if (addr_no == 5)
	    *NFI_ADDRM = addr2;
	*NFI_ADDNOB = addr_no;  // no. of bytes for address
	while (*NFI_PSTA & STATUS_ADDR);

	*NFI_OPCON = BURST_WR;                      // set burst write

	*NFI_CON = DMA_WR_EN;

	*(volatile kal_uint32 *)(0x80030118) = 0x0000;
	*(volatile kal_uint32 *)(0x80030100) = (kal_uint32)destination;
	*(volatile kal_uint32 *)(0x80030104) = (kal_uint32)NFI_DATAW;
	*(volatile kal_uint32 *)(0x80030110) = pageSize>>2;
	*(volatile kal_uint32 *)(0x80030114) = 0x01000016;
	*(volatile kal_uint32 *)(0x80030128) = 0;
	*(volatile kal_uint32 *)(0x80030118) = 0x8000;

	while ( ((*(volatile kal_uint32 *)(0x80030000)&0x03)==0x01) ); 

	*NFI_CMD = PROG_DATA_CMD;       // Issue program command
	while (*NFI_PSTA & STATUS_CMD);

	while (*NFI_PSTA & STATUS_BUSY);
	*NFI_OPCON = 0;

	return;
} 

#endif

/**********************************************************
Description : NUTL_ECC_Correction
Input       : .......
Output      : _RET_CODE
***********************************************************/            
_RET_CODE  NUTL_ECC_Correction(kal_uint32 *dataPtr, kal_uint32 *parityPtr, kal_uint32 *sparePtr, \
                               kal_uint16 pageSize, kal_uint32 blockSize)	
{
   kal_uint8   update_data;
   kal_uint32  i;
	kal_uint32  error_bit_address;
	kal_uint32  error_bit_offset;
	kal_uint8   *p_data8 = (kal_uint8 *)dataPtr;		
	kal_uint32  ecc_parity_from_spare[5] = {0,0,0,0,0};	
	kal_uint32  *ecc_parity_from_reg = parityPtr;
	UnionData_U	xor_ecc_parity[4];
	kal_uint8   status = NFI_SUCCESS;
	

   if ( pageSize==512 )
   {
      ecc_parity_from_spare[0] = *(sparePtr + 2);
   }
   else
   {
      ecc_parity_from_spare[0] = *(sparePtr + 11);
      ecc_parity_from_spare[1] = *(sparePtr + 12);
      ecc_parity_from_spare[2] = *(sparePtr + 13);
      ecc_parity_from_spare[3] = *(sparePtr + 14);
   }
   
	// XOR two ECC parity bit strings 
	// ecc_parity_from_reg[4]: current ECC parity generated by reading whole page 
	// ecc_parity_from_spare[4]: original ECC parity stored in spare area 
	xor_ecc_parity[0].d32 = (ecc_parity_from_reg[0]^ecc_parity_from_spare[0])&0x0FFF0FFF;
	xor_ecc_parity[1].d32 = (ecc_parity_from_reg[1]^ecc_parity_from_spare[1])&0x0FFF0FFF;
	xor_ecc_parity[2].d32 = (ecc_parity_from_reg[2]^ecc_parity_from_spare[2])&0x0FFF0FFF;
	xor_ecc_parity[3].d32 = (ecc_parity_from_reg[3]^ecc_parity_from_spare[3])&0x0FFF0FFF;

	// compare ECC parity between reg and spare 
	for(i=0; i<(pageSize/0x200); i++) 
	{
		if( 0 != xor_ecc_parity[i].d32 ) 
		{
			if( 0x0FFF == ((xor_ecc_parity[i].d16[0]^xor_ecc_parity[i].d16[1])&0x0FFF) ) 
			{
				// one-bit correctable error 
				error_bit_address = xor_ecc_parity[i].d16[1]&(~xor_ecc_parity[i].d16[0]);
				error_bit_offset = 0x200*i + (error_bit_address>>3);
				update_data = p_data8[error_bit_offset];
				update_data = update_data^(1<<(kal_uint8)(error_bit_address&0x0007));
#ifdef BIT_ERROR_TEST
				dbg_print(" ECC error address=%x error bit=%x Original=%x corrected data=%x \n\r", 
					error_bit_offset, error_bit_address & 0x07, p_data8[error_bit_offset], update_data);				
#endif
				p_data8[error_bit_offset] = update_data;

				if(status==NFI_SUCCESS) {
					status = NFI_ECC_1BIT_CORRECT;
				}
			} 
			else 
			{
				kal_uint32 iIndex=0,iEccsum=0;

				for(iIndex = 0; iIndex < 12; iIndex++)
				{
				   iEccsum += ((xor_ecc_parity[i].d16[0] >> iIndex) & 0x01);
				   iEccsum += ((xor_ecc_parity[i].d16[1] >> iIndex) & 0x01);
				}
				if(iEccsum ==1)
				{
				   // ECC code error.
				   dbg_print(" ECC code error... \n\r");
				   continue;
				}

/*				dbg_print(" ECC error ... \n\r");
				dbg_print(" Register %x \n\r", ecc_parity_from_reg[i]);
				dbg_print(" Spare %x \n\r", ecc_parity_from_spare[i]);*/
				if(status!=NFI_ECC_2BITS_ERR) {
					status = NFI_ECC_2BITS_ERR;
				}
			}
		}
	}

	return status;
}

/**********************************************************
Description : NFI_PageRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                       kal_bool ECC, kal_bool continous)
{
   kal_int16   timeout=0xfff;
   kal_uint32  *parity_ptr = parity;
   
   *NFI_OPCON = 0x00;   
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = 0x30;                  // Flushing FIFO

   if ( pageSize<1024 )
   {
	   *NFI_CMD = RD_1ST_CMD;             // read command 
	   while (*NFI_PSTA & STATUS_CMD);	   
	   *NFI_ADDRL = addr1;
	   if ( addr_no>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = addr_no;	           // number of bytes for address	   
	   while (*NFI_PSTA & STATUS_ADDR);	   
	}
	else
	{
	   *NFI_CMD = RD_1ST_CMD;	           // Issue data input command
	   while (*NFI_PSTA & STATUS_CMD);	   
	   *NFI_ADDRL = addr1;
	   if ( addr_no>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = addr_no;	           // no. of bytes for address	
	   while (*NFI_PSTA & STATUS_ADDR);	   
	   *NFI_CMD = RD_2ND_CYCLE_CMD;
	   while (*NFI_PSTA & STATUS_CMD);	   
	}

   *NFI_OPCON = BURST_RD | NOB_DWORD;    // set burst read
   
   while( *NFI_PSTA & STATUS_DATAR );
   
   NFI_Wait_Ready(timeout);
   
   if ( timeout==0 )
      return KAL_FALSE;

   // Activating DMA transfer
   if ( ECC )
      *NFI_CON = (DMA_RD_EN | AUTOECC_DEC_EN);
   else
      *NFI_CON = DMA_RD_EN;
   
   *(volatile kal_uint32 *)(0x80030118) = 0x0000;
   *(volatile kal_uint32 *)(0x80030100) = (kal_uint32)NFI_DATAR;
   *(volatile kal_uint32 *)(0x80030104) = (kal_uint32)destination;
   *(volatile kal_uint32 *)(0x80030110) = length>>2;
   *(volatile kal_uint32 *)(0x80030114) = 0x00f4001a;
   *(volatile kal_uint32 *)(0x80030128) = 0;
   *(volatile kal_uint32 *)(0x80030118) = 0x8000;
   
   timeout = 0xfff;
   
   while ( ((*(volatile kal_uint32 *)(0x80030000)&0x03)==0x01) && (timeout--) ); 
   
   if ( timeout==0 )
	   return DMA_TRANSFER_DATA_TIMEOUT;
         
//   while (!(*NFI_FIFOCON & RD_EMPTY_MASK) || (*NFI_PSTA & STATUS_DATAR));
   while (*NFI_PSTA & STATUS_BUSY);   

   if ( ECC )
   {
		if ( parity==NULL )
			return NFI_ZERO_POINTER;
		 
		if ( pageSize<1024 )
		{
			parity_ptr[0] = *NFI_PAR6;
			parity_ptr[0] |= (*NFI_PAR7) << 16;         
		}
		else
		{
			parity_ptr[0] = *NFI_PAR0;
			parity_ptr[0] |= (*NFI_PAR1) << 16;
			parity_ptr[1] = *NFI_PAR2;
			parity_ptr[1] |= (*NFI_PAR3) << 16;
			parity_ptr[2] = *NFI_PAR4;
			parity_ptr[2] |= (*NFI_PAR5) << 16;
			parity_ptr[3] = *NFI_PAR6;
			parity_ptr[3] |= (*NFI_PAR7) << 16;
		}         
   }
   
   // Caution: This line must not omitted!
   *NFI_OPCON = 0x0;
   
   if ( timeout )
	   return NFI_SUCCESS;
	else 
	   return NFI_READ_DATA_TIMEOUT;
}

/**********************************************************
Description : NFI_SpareRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be spare area aligned
***********************************************************/
_RET_CODE NFI_SpareRead(kal_uint32 *spare, kal_uint16 addr_no, kal_uint32 addr1, \
                        kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO)
{
	kal_int16 timeout=0xfff, size, i;
	  
	*NFI_OPCON = 0x00;
	*NFI_CON = 0x00;        
	*NFI_FIFOCON = 0x30;                  // Flushing FIFO

	if ( pageSize<1024 )
	{
		size = 16;
		*NFI_CON = SW_PROGSPARE_EN;        // program/read spare area enable
		*NFI_CMD = RD_SPARE_CMD;			  // reading spare command	   
		while (*NFI_PSTA & STATUS_CMD);	  
		*NFI_ADDRL = (addr1&0xffffff00);	 
		*NFI_ADDRM = 0;
		*NFI_ADDNOB = addr_no;             // number of bytes for address
		while (*NFI_PSTA & STATUS_ADDR);	 
	}
	else
	{
		size = 64;
		*NFI_CON = SW_PROGSPARE_EN;        // program spare area enable
		*NFI_CMD = RD_1ST_CMD;             // read spare command
		while (*NFI_PSTA & STATUS_CMD);	  
		if ( IO==IO_16BITS )
		{
			// addr1 >>= 1;	   
			addr1 = addr1 + (2048/2);
		}
		else 
		{
			addr1 = addr1 + 2048;
		}
		*NFI_ADDRL = addr1;
		if ( addr_no>4 )
			*NFI_ADDRM = addr2;
		*NFI_ADDNOB = addr_no;             // number of bytes for address
		while (*NFI_PSTA & STATUS_ADDR);	   
		*NFI_CMD = RD_2ND_CYCLE_CMD;            
		while (*NFI_PSTA & STATUS_CMD);	   
	}	   

	//	*NFI_OPCON = BURST_RD | NOB_WORD;     // set burst read	
	*NFI_OPCON = BURST_RD | NOB_DWORD;     // set burst read	

	while( *NFI_PSTA & STATUS_DATAR );

	NFI_Wait_Ready(timeout);

	if ( timeout==0 )
	  return NFI_READ_SPARE_TIMEOUT;


	/*   *NFI_CON |= DMA_RD_EN;
	*(volatile kal_uint32 *)(0x80030118) = 0x0000;
	*(volatile kal_uint32 *)(0x80030100) = (kal_uint32)NFI_DATAR;
	*(volatile kal_uint32 *)(0x80030104) = (kal_uint32)spare;
	*(volatile kal_uint32 *)(0x80030110) = size>>2;
	*(volatile kal_uint32 *)(0x80030114) = 0x00f4001a;
	*(volatile kal_uint32 *)(0x80030128) = 0;
	*(volatile kal_uint32 *)(0x80030118) = 0x8000;

	timeout = 0xfff;

	while ( ((*(volatile kal_uint32 *)(0x80030000)&0x03)==0x01) && (timeout--) ); */


	for (i=0; i<(size/4); i++)
	{
		while ((*NFI_FIFOCON & RD_EMPTY_MASK));
		spare[i] = *NFI_DATAR;
	}   

/*	dbg_print("Spare area = ");
	for(i=0; i<(size/4); i++) {
	     dbg_print("%x ", spare[i]);
	}
	dbg_print("\n\r");*/


	//   while (*NFI_PSTA & STATUS_DATAR);
	// Caution: This line must not omitted!
	*NFI_OPCON = 0x0;
	while (*NFI_PSTA & STATUS_BUSY);   

	if ( timeout )
	   return NFI_SUCCESS;
	else 
	   return DMA_TRANSFER_SPARE_TIMEOUT;
}

/**********************************************************
Description : NFI_ParityCheck
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment.
***********************************************************/
_RET_CODE NFI_ParityCheck(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, \
                          kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, kal_uint16 IO, \
                          kal_uint32 blockSize)
{
   _RET_CODE  status;
   kal_uint32 spare[64>>2];
   
   status = NFI_SpareRead(&spare[0], addr_no, addr1, addr2, pageSize, IO);
   
   if ( status!=NFI_SUCCESS )
      return status;
  
   if ( pageSize<1024 )
      status = NUTL_ECC_Correction(destination, parity, &spare[0], 512, blockSize);
   else
      status = NUTL_ECC_Correction(destination, parity, &spare[0], 2048, blockSize);
   
   return status;
}
                  
/**********************************************************
Description : NFI_CheckGoodBlock
Input       : NFI_MENU, baseaddr must be page alignment
Output      : U32 return data
              512B/page, 8-bits interface, 0x????FF??
              otherwise, 0x????FFFF or 0x??????FF
              for good page
              2: Read error
***********************************************************/ 
static kal_uint32 NFI_CheckGoodBlock(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2)
{
   kal_uint32 rb_data[4];
   kal_int16  timeout=0xfff, size;
   
   rb_data[0]= 0;
   rb_data[1]= 0;
   rb_data[2]= 0;
   rb_data[3]= 0;
   
   *NFI_OPCON = 0x00;
   *NFI_CON = 0x00;        
   *NFI_FIFOCON = 0x30;                  // Flushing FIFO
   
   if ( input->pageSize<1024 )
   {
      *NFI_CON = SW_PROGSPARE_EN;        // program/read spare area enable
	   *NFI_CMD = RD_SPARE_CMD;			  // reading spare command	   
	   while (*NFI_PSTA & STATUS_CMD);	  
	   *NFI_ADDRL = (addr1&0xffffff00);	 
	   *NFI_ADDRM = 0;
	   *NFI_ADDNOB = input->addressCycle; // number of bytes for address
	   while (*NFI_PSTA & STATUS_ADDR);	 
	}
	else
	{
	   *NFI_CON = SW_PROGSPARE_EN;        // program spare area enable
	   *NFI_CMD = RD_1ST_CMD;             // read spare command
	   while (*NFI_PSTA & STATUS_CMD);	  
	   if ( input->IOInterface == IO_8BITS )
	      *NFI_ADDRL = addr1 + 2048;
	   else
	      *NFI_ADDRL = addr1 + 1024;
	   if ( input->addressCycle>4 )
	      *NFI_ADDRM = addr2;
	   *NFI_ADDNOB = input->addressCycle; // number of bytes for address
	   while (*NFI_PSTA & STATUS_ADDR);	   
      *NFI_CMD = RD_2ND_CYCLE_CMD;            
      while (*NFI_PSTA & STATUS_CMD);	   
	}	   

	*NFI_OPCON = BURST_RD | NOB_WORD;  // set burst read	
	
	while( *NFI_PSTA & STATUS_DATAR );
	
   NFI_Wait_Ready(timeout);
   
   if ( timeout==0 )
      return 2;
   
   size = 0;
   timeout=0xfff;
   
   while ( (size<4) && timeout>0 )
 	{
	   if ( !(*NFI_FIFOCON&RD_EMPTY_MASK) )
	   {
         rb_data[size] = *NFI_DATAR;
         size ++;
      }
      else 
         timeout--;
   }
   
   if ( timeout<=0 )
      return 2;
      
   // Caution: This line must not omitted!
   *NFI_OPCON = 0x0;
      
   if ( input->pageSize<1024 )
   {
      if ( input->IOInterface == IO_8BITS )
         return ( (kal_uint32)((rb_data[1]&0xff00)>>8) );
      else
         return ( ((kal_uint32)(rb_data[0]&0xff) | (rb_data[1]&0xff00)) );
   }
   else
   {
      if ( input->IOInterface == IO_8BITS )
         return ( (kal_uint32)(rb_data[0]&0xff) );
      else
         return ( (kal_uint32)(rb_data[0]&0xffff) );
   }
}


/**********************************************************
Description : NFIReconfigure
Input       : NO
Output      : NO
***********************************************************/
void NFIReconfigure(void)
{
	*NFI_FIFOCON = 0x30;                  // Flushing FIFO
	*NFI_OPCON = 0x00;
	*NFI_CON = 0x00;     
	// Force 512Bytes ECC block size for both 2KB and 512B NAND-flash
	*NFI_PAGEFMT |= 0x20;
	*NFI_ACCCON = 0x7FF;
}


/**********************************************************
Description : GoodBlockChecking
Input       : NFI_MENU, NFIReadPtr must be page alignment
Output      : TRUE, good block, FALSE, bad block
***********************************************************/
kal_bool GoodBlockChecking(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2)
{
   kal_uint32 marking, i;
      
   for (i=0; i<2; i++)
   {
      // Read the bad block marking from the first page
      marking = NFI_CheckGoodBlock(input, addr1, addr2);
      if ( (marking!=0xff) && (marking!=0xffff) )
         return KAL_FALSE;
      addr1 = addr1 + (1<<input->pageShift);
   }
         
   return KAL_TRUE;
}

