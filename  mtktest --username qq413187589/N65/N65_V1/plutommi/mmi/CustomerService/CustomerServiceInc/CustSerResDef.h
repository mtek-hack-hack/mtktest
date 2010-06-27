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
 * Filename:
 * ---------
 * OptrSerResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines enum values of Customer Service applications.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**************************************************************

   FILENAME : CustSerResDef.h

   PURPOSE     : Customer Service application 

   REMARKS     : nil

   AUTHOR      : Lili Fan

   DATE     : May 10,07

**************************************************************/

#ifndef _MMI_CUSTOMER_SERVICE_RES_H_
#define _MMI_CUSTOMER_SERVICE_RES_H_

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_CUSTOMER_SERVICE__

#include "MMIDataType.h"

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    SCR_ID_CUSTSER_LIST = CUSTOMER_SERVICE_BASE + 1,
    SCR_ID_CUSTSER_TEXTVIEWER,
    SCR_ID_CUSTSER_MYMONWAP,
    SCR_ID_CUSTSER_SETTING_LIST,
    SCR_ID_CUSTSER_SETTING_HOTLINE,
    SCR_ID_CUSTSER_SETTING_MANAGER,
    SCR_ID_CUSTSER_SETTING_MANAGER_NAME,
    SCR_ID_CUSTSER_SETTING_MANAGER_NAME_OPTION,
    SCR_ID_CUSTSER_END
} SCREENID_LIST_CUSTSER_SERVICE;

typedef enum
{
    STR_ID_CUSTSER_TITLE = CUSTOMER_SERVICE_BASE + 1,
    STR_ID_CUSTSER_GUIDELINE,
    STR_ID_CUSTSER_GUIDELINE_CONTENT,
    STR_ID_CUSTSER_SALE,
    STR_ID_CUSTSER_HOTLINE,
    STR_ID_CUSTSER_MANAGER,
    STR_ID_CUSTSER_MYMONWAP,
    STR_ID_CUSTSER_MYMONWAP_CONTENT,
    STR_ID_CUSTSER_MONWAP,
    STR_ID_CUSTSER_MONWAP_SMS,
    STR_ID_CUSTSER_MONWAP_SMS_CONTENT,
    STR_ID_CUSTSER_MONWAP_MMS,
    STR_ID_CUSTSER_MONWAP_MMS_CONTENT,
    STR_ID_CUSTSER_SETTING,
    STR_ID_CUSTSER_SETTING_HOTLINE,
    STR_ID_CUSTSER_SETTING_MANAGER,
    STR_ID_CUSTSER_SETTING_MANAGER_NAME,
    STR_ID_CUSTSER_SETTING_MANAGER_NUM,
    STR_ID_CUSTSER_END
} STRINGID_LIST_CUSTSER_SERVICE;

typedef enum
{
    IMG_ID_CUSTSER_GUIDELINE = CUSTOMER_SERVICE_BASE + 1,
    IMG_ID_CUSTSER_SALE,
    IMG_ID_CUSTSER_HOTLINE,
    IMG_ID_CUSTSER_MANAGER,
    IMG_ID_CUSTSER_MYMONWAP,
    IMG_ID_CUSTSER_SETTING,
    IMG_ID_CUSTSER_END
} IMAGEID_LIST_CUSTSER_SERVICE;

#endif /* __MMI_CUSTOMER_SERVICE__ */ 

#endif /* _MMI_CUSTOMER_SERVICE_RES_H_ */ 

