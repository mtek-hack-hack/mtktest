/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MT6226_NVRAMStatistic/src/nvram_auto_gen.c,v 1.2 2007/06/01 05:35:02 bw Exp $
*
* $Id: nvram_auto_gen.c,v 1.2 2007/06/01 05:35:02 bw Exp $
*
* $Date: 2007/06/01 05:35:02 $
*
* $Name: 1.2 $
*
* $Locker$
*
* $Revision: 1.2 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: nvram_auto_gen.c,v $
* Revision 1.2  2007/06/01 05:35:02  bw
* P_U25U26_06B_V30_M31_bw_0002 MTKÉý¼¶Èí¼þV30 TO V36
*
* Revision 1.1  2007/05/17 07:24:47  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_auto_gen.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for generating NVRAM information.
 *
 * Author:
 * -------
 * Cylen Yao (mtk00911)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * ~Log$
 *
 * Sep 25 2006 mtk00911
 * [MAUI_00332144] [NVRAM] To fix the shadow problem on MoDIS
 * 
 *
 * Jul 16 2006 mtk00911
 * [MAUI_00210759] [SMU][New Feature] NEW SIM-ME Lock Feature
 * 
 *
 * Jun 20 2006 mtk00911
 * [MAUI_00204148] [NVRAM] Fix nvram_lid_statistic.h including problem
 * 
 *
 * Jun 20 2006 mtk00911
 * [MAUI_00204148] [NVRAM] Fix nvram_lid_statistic.h including problem
 * 
 *
 * Jun 18 2006 mtk00911
 * [MAUI_00015709] [1] Fatal Error (424): kal_set_eg_events() failed - MMI
 * 
 *
 * Jun 16 2006 mtk00911
 * [MAUI_00203168] [NVRAM] CustPack 06A
 * 
 *
 * Jun 5 2006 mtk00911
 * [MAUI_00199983] [NVRAM] Fix NVRAM Multiple default problem
 * 
 *
 * Apr 21 2006 mtk00911
 * [MAUI_00188983] [NVRAM] Revise customization process
 * Tool to auto gen NVRAM statistics
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "nvram_auto_gen.h"
#include "nvram_user_defs.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define BytesPerCluster 1024

/***************************************************************************** 
* Local Variable
*****************************************************************************/
kal_uint32 shadow_total_to_verify = 0; 
kal_uint32 shadow_size_to_verify = (2 * 2);
kal_uint32 nvram_disk_size = 0;
kal_uint16 custpack_total_to_verify = 0;
kal_uint32 otp_total_to_verify = 0;
kal_uint32 otp_size_to_verify = 0;
kal_uint32 max_shadow_rec = 0;
custpack_nvram_header custpack_nvram_header_p;
custpack_nvram_header *custpack_nvram_header_ptr = &custpack_nvram_header_p;

/*****************************************************************************
* FUNCTION
*  nvram_output_statistic
* DESCRIPTION
*  Output NVRAM Statistic Information.
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
void nvram_output_statistic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i, j = 0, custpack_idx = 0;
    kal_uint8 record_ID, position = 0;
    ltable_entry_struct* ltable_entry;
	kal_uint32 onefilesize = 0; 
	FILE* logOfSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	logOfSize = fopen("..\\..\\..\\~nvram_lid_size.log","w+");
    fprintf(logOfSize, "-----------------------------------------------------------\n");
    
    
	for (i = 0; i < NVRAM_TOTAL_LID; ++i)
	{
		/*Construct the traditional lookup tables*/
		if (i < NVRAM_EF_LAST_LID_CORE)
		{
			position = logical_data_item_table_core[i].LID;
			logical_data_item_table[position] = (ltable_entry_struct*) &logical_data_item_table_core[i];
		}
		else if((i >= NVRAM_EF_LAST_LID_CORE) && (i < NVRAM_LAST_COMMAPP_LID))
		{
			position = logical_data_item_table_comm_app[i - NVRAM_EF_LAST_LID_CORE].LID;
			logical_data_item_table[position] = (ltable_entry_struct*) &logical_data_item_table_comm_app[i - NVRAM_EF_LAST_LID_CORE];
		}
		else if(( i >= NVRAM_LAST_COMMAPP_LID) && (i < NVRAM_TOTAL_LID))
		{
		    /* Here could be some redundant data items; place to correct position */
			position = logical_data_item_table_cust[i- NVRAM_LAST_COMMAPP_LID].LID;
			logical_data_item_table[position] = (ltable_entry_struct*)&logical_data_item_table_cust[i- NVRAM_LAST_COMMAPP_LID];
		}
		
	#if defined(__SHADOW_NVRAM__)
		/* Calc SHADOW Total and Size */
	    #if defined(__SHADOW_SUPPORT_MS__)
		if(logical_data_item_table[position]->category&NVRAM_CATEGORY_SHADOW_MS)
        #elif defined(__SHADOW_SUPPORT_SB__)
		if(logical_data_item_table[position]->category&NVRAM_CATEGORY_SHADOW)
        #endif
		{
            /* shadow items count*/
			shadow_total_to_verify++;
            
			/* shadow size */
			shadow_size_to_verify += logical_data_item_table[position]->size * logical_data_item_table[position]->total_records;

            /* max shadow record size */
            if (max_shadow_rec < logical_data_item_table[position]->total_records)
                max_shadow_rec = logical_data_item_table[position]->total_records;
                
			/* shadow table index */
			logical_data_item_table[position]->record_ID = j++;
		}
	#endif			

	        /* Output data item size */
	        onefilesize = logical_data_item_table[position]->size * logical_data_item_table[position]->total_records;
	        if(onefilesize)
	        {
	            fprintf(logOfSize, "%4d%20d                    %s\n", logical_data_item_table[position]->LID, onefilesize, logical_data_item_table[position]->description);
	
	            if (NVRAM_IS_ATTR_MULTIPLE(logical_data_item_table[position]->attr))
	                    fprintf(logOfSize, "%4d%20d                    %s\n", logical_data_item_table[position]->LID, onefilesize, logical_data_item_table[position]->description);
	
	        }
	
	        if (logical_data_item_table[position]->category & NVRAM_CATEGORY_CUSTPACK)
	        {
	            custpack_total_to_verify++;
	        }

		if (logical_data_item_table[position]->attr & NVRAM_ATTR_OTP)
		{
		    otp_total_to_verify++;
		    otp_size_to_verify += logical_data_item_table[position]->size * logical_data_item_table[position]->total_records;
		}
	}
	
	
	
    fprintf(logOfSize, "-----------------------------------------------------------\n");
    fclose(logOfSize);

}

/*****************************************************************************
* FUNCTION
*  main
* DESCRIPTION
*  main function.
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
int main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FILE* outputHeader;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	nvram_output_statistic();

	outputHeader=fopen("..\\..\\..\\custom\\common\\nvram_lid_statistics.h","w+");
	fprintf(outputHeader,"/*****************************************************************************\n"\
	"*  Copyright Statement:\n"\
	"*  --------------------\n"\
	"*  This software is protected by Copyright and the information contained\n"\
	"*  herein is confidential. The software may not be copied and the information\n"\
	"*  contained herein may not be used or disclosed except with the written\n"\
	"*  permission of MediaTek Inc. (C) 2006\n"\
	"*\n"\
	"*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES\n"\
	"*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS (\"MEDIATEK SOFTWARE\")\n"\
	"*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON\n"\
	"*  AN \"AS-IS\" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,\n"\
	"*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF\n"\
	"*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.\n"\
	"*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE\n"\
	"*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR\n"\
	"*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH\n"\
	"*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO\n"\
	"*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S\n"\
	"*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.\n"\
	"*\n"\
	"*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE\n"\
	"*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,\n"\
	"*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,\n"\
	"*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO\n"\
	"*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. \n"\
	"*\n"\
	"*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE\n"\
	"*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF\n"\
	"*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND\n"\
	"*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER\n"\
	"*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).\n"\
	"*\n"\
	"*****************************************************************************/\n"\
	"\n"\
	"/*****************************************************************************\n"\
	" *\n"\
	" * Filename:\n"\
	" * ---------\n"\
	" * nvram_lid_statistics.h\n"\
	" *\n"\
	" * Project:\n"\
	" * --------\n"\
	" *   MAUI\n"\
	" *\n"\
	" * Description:\n"\
	" * ------------\n"\
	" *   This file is intends for NVRAM auto gen statistics\n"\
	" *\n"\
	" * Author:\n"\
	" * -------\n"\
	" * Cylen Yao (mtk00911)\n"\
	" *\n"\
	" *============================================================================\n"\
	" *\n"\
	" * This file is automatically generated by the nvram gen procedure\n"\
	" *\n"\
	" ****************************************************************************/\n"\
	"#ifndef NVRAM_LID_STATISTIC_H\n#define NVRAM_LID_STATISTIC_H\n");		

    fprintf(outputHeader,"#ifdef __MTK_TARGET__\n");
    fprintf(outputHeader,"#define NVRAM_SHADOW_SIZE   %d\n", shadow_size_to_verify);
    fprintf(outputHeader,"#else\n");
    fprintf(outputHeader,"#define NVRAM_SHADOW_SIZE   %d + 1024\n", shadow_size_to_verify);            
    fprintf(outputHeader,"#endif /* __MTK_TARGET__ */\n");    
    fprintf(outputHeader,"#define NVRAM_SHADOW_TOTAL  %d\n", shadow_total_to_verify);    
    
    fprintf(outputHeader, "#define NVRAM_OTP_SIZE    %d\n", otp_size_to_verify);
    fprintf(outputHeader, "#define NVRAM_OTP_TOTAL   %d\n", otp_total_to_verify);
	
    fprintf(outputHeader, "#define NVRAM_CUSTPACK_TOTAL  %d\n", custpack_total_to_verify - 1); /* -CustPack verion */
    fprintf(outputHeader,"#define NVRAM_MAX_SHADOW_REC %d /* max_shadow_rec = %d */ \n", ((max_shadow_rec/32) + ((max_shadow_rec%32)?1:0)), max_shadow_rec);
    fprintf(outputHeader,"\n#endif /* NVRAM_LID_STATISTIC_H */\n\n");
    fclose(outputHeader);


}
