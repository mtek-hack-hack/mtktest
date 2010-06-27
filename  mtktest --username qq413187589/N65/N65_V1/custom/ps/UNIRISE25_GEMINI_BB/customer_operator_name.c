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
 * Filename:
 * ---------
 * Custom_operator_name.c
 *
 * Description:
 * ------------
 *   This file is intends for Customer to define the operator name for AT command such as +COPS, +CPOL, +COPN
 *
 * Author:
 * -------
 * -------
 *
*****************************************************************************/

#include "kal_non_specific_general_types.h"
#include "string.h"


/* -------------PLEASE ADJUST HERE to define the number of entries---------- */
/* please match RMMI_PLMN_NAME_ENTRIES with the entries in the table:               */
/* increase the number if new operator name is added to the table                       */
#define RMMI_PLMN_NAME_ENTRIES    30

/* -----------PLEASE ADJUST HERE to define operator names -----------------  */
/* ----- NOTE:   LONG alphanumeric format can only up to 16 characters -------   */
/* ------------SHORT alphanumeric format can only up to 8 charactors  -------- */
char* rmmi_plmn_table[RMMI_PLMN_NAME_ENTRIES][3] = {


						{"Bharti Cellular", 	"AIRTL",	"40410"},	/* India */
						{"Hutchison Max", 	"MAXTCH","40420"},
						{"Usha Martin", 	"COMMAND",	"40430"},
						{"Hutchison Essar", 	"ESSAR",	"40411"},							
						{"Hong Kong CSL", 	"HKTCSL",	"45400"}, /* Hong Kong */
						{"Smartone Mobile", 	"HKSMC",	"45406"},
						{"Hutchison", 		"Orange",	"45404"},
						{"Mandarin Comm.", 	"MCL",		"45416"},
						{"Peoples", 		"PEOPLES",	"45412"},
						{"New World PCS", 	"NWPCS",	"45410"},							
						{"China Telecom", 	"CT-GSM",	"46000"}, /* China */
						{"China Unicom", 	"CU-GSM",	"46001"},							
						{"Pacific Cellular",	"TWN", 		"46697"}, /* Taiwan */
						{"KG Telecom Co.",	"KGT",		"46688"},
						{"Far EasTone",		"FET",		"46601"},
						{"Chunghwa Telecom", 	"Chunghwa",	"46692"},
						{"MoBitai Telecom", 	"MOBITAI",	"46693"},
						{"TransAsia", 		"TransAsia",	"46699"},						
						{"Time Wireless", 	"ADAM",		"50217"},/* Malaysia */
						{"Cellular Coms.", 	"CELCOM",	"50219"},	
						{"Binariang Coms.", 	"MAXIS",	"50212"},
						{"DIGI Telcom", 	"DIGI1800",	"50216"},							
						{"Isla Coms.", 		"ISLA",		"51501"},/* Philippinen */
						{"Globe Telecom", 	"GLOBE",	"51502"},						
						{"Thailand AIS", 	"TH AIS",	"52001"},	/* Thailand */
						{"Total Access", 	"WP 1800",	"52018"},							
						{"Mobile One Asia", 	"M1-GSM",	"52503"}, /* Singapore */
						{"Singapore Telcom", 	"STGSM",	"52501"},
						{"SingTel Mobile", 	"GSM 180",	"52502"},
						
						{"","",""}	/* default: "" indicate the last one */
};



/*------ Please do not change below functions ------------------*/
kal_uint16 rmmi_get_max_oper_count(void);
kal_bool rmmi_translate_oper_name(kal_uint8 format1, kal_uint8 *oper_str1, kal_uint8 format2, kal_uint8 *oper_str2);				
void rmmi_get_oper_name(kal_uint8 i, kal_uint8 * oper_numeric, kal_uint8 * oper_short, kal_uint8 * oper_long);								


/*****************************************************************************
* FUNCTION
*  rmmi_get_max_oper_count
* DESCRIPTION
*   This function returns RMMI_PLMN_NAME_ENTRIES defined by customer
*
* PARAMETERS
*   
* RETURNS
*  kal_uint16
*
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 rmmi_get_max_oper_count(void)
{
   return (RMMI_PLMN_NAME_ENTRIES);
}

/*****************************************************************************
* FUNCTION
*  rmmi_translate_oper_name
* DESCRIPTION
*   This function convert oper_str1 (format1) to oper_str2(format2)
*
* PARAMETERS
*   IN: format1
*   IN: oper_str1
*   IN: format2
*   OUT: oper_str2
*   
* RETURNS
*  kal_bool 
*	KAL_TRUE: Success
*	KAL_FALSE: oper_str1 not found
*
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool rmmi_translate_oper_name(kal_uint8 format1, kal_uint8 *oper_str1, kal_uint8 format2, kal_uint8 *oper_str2)
{
	kal_uint8 i;
   if(format1==format2)
   {
   	strcpy((char *)oper_str2,(char *)oper_str1);
   	return KAL_TRUE;
   }
   else
   {
	   for(i=0;i<RMMI_PLMN_NAME_ENTRIES;i++)
	   {
				if(strcmp((char *)oper_str1, (char *)rmmi_plmn_table[i][format1])== 0)
				{
					/* found entry in the table */
					strcpy((char *)oper_str2,(char *)rmmi_plmn_table[i][format2]);
					return KAL_TRUE;
				}				
	   }		

	   /* cannot found in the table */
		if(format1==2) 	// 2: numeric
   	 	strcpy((char *)oper_str2,(char *)oper_str1);
	   else 
	   	strcpy((char *)oper_str2,"");
	   return KAL_FALSE;
   }
}

/*****************************************************************************
* FUNCTION
*  rmmi_get_oper_name
* DESCRIPTION
*  This function gives the numeric, short alphanumeric, and long alphanumeric
*  strings for the specified entry.
*
* PARAMETERS
*  IN	i : specified the i-th entry
*  OUT	oper_numeric
*  OUT  oper_short_str
*  OUT 	oper_long_str
*  
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void rmmi_get_oper_name(kal_uint8    i, kal_uint8 * oper_numeric, kal_uint8 * oper_short, kal_uint8 * oper_long)
{
   oper_numeric[0]='\0';
	oper_short[0]='\0';
	oper_long[0]='\0';
	
	if( i >= RMMI_PLMN_NAME_ENTRIES)
		return;
	
	if(strlen((char *)rmmi_plmn_table[i][0])>0)
	{
		strcpy((char *)oper_numeric,(char *)rmmi_plmn_table[i][2]);
		strcpy((char *)oper_short,(char *)rmmi_plmn_table[i][1]);
		strcpy((char *)oper_long,(char *)rmmi_plmn_table[i][0]);
	}
	return;
}


