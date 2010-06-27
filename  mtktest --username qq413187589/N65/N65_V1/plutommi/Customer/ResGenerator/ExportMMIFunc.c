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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: ExportMMIFunc.c

  	PURPOSE		: Functions From MMI

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-26-2003

**************************************************************/

#include "Unicodedef.h"
#include "Unicodexdcl.h"
#include "Unicodedcl.h"		/* define the string function pointer */
#include "ExportMMIFunc.h"
#include "CustResdef.h"

#ifndef __POPULATE_ENGINE_
HWND hWnd;
#endif
S8 CustImgPath[]=CUST_IMG_PATH;
S8 CustAdoPath[]=CUST_ADO_PATH;/*101205 audio resource Calvin Add */

void InitUnicodeSupport(void)
{

	pfnUnicodeToEncodingScheme = UnicodeToUCS2Encoding;
	pfnEncodingSchemeToUnicode = UCS2EncodingToUnicode;
	pfnUnicodeStrlen  = UCS2Strlen;
	pfnUnicodeStrcpy  = UCS2Strcpy;
	pfnUnicodeStrcmp  = UCS2Strcmp;
	pfnUnicodeStrncpy = UCS2Strncpy;
	pfnUnicodeStrncmp = UCS2Strncmp;
	pfnUnicodeStrcat  = UCS2Strcat;

}
void ShutdownSystemOperation(void)
{
}

void set_MMI_theme(MMI_theme *t){}
void MMI_apply_current_theme(void){}
S8* GetImageFileSystem(U16 ImageId){return 0;}
void PhnsetReinitHomeCityIdx(void){}

