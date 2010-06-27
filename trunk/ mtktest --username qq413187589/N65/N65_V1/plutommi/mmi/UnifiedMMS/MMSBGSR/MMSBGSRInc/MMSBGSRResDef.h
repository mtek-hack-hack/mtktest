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
 * MMSBGSRResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Defintion for MMS Applicaiton.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMS_BGSR_DEFS_H
#define _MMS_BGSR_DEFS_H


#include "MMIDataType.h"


/*******************************************************************************
 * Include
 *******************************************************************************/

/*******************************************************************************
 * Define
 *******************************************************************************/

/*******************************************************************************
 * Typedef
 *******************************************************************************/

typedef enum
{
    STR_ID_BGSR_NOT_USED = (MMS_BGSR_BASE+1),
    STR_ID_BGSR_RESULT_OK,
    STR_ID_BGSR_RESULT_FAIL_INCALL,
    STR_ID_BGSR_RESULT_FAIL_NOT_READY,
    STR_ID_BGSR_RESULT_FAIL_BUSY,                 
    STR_ID_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY,        
    STR_ID_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE,       
    STR_ID_BGSR_RESULT_FAIL_FILE_NOT_FOUND,             
    STR_ID_BGSR_RESULT_FAIL_FILE_CORRUPTED,            
    STR_ID_BGSR_RESULT_FAIL_FILE_IN_USE,               
    STR_ID_BGSR_RESULT_FAIL_FILE_IO,                
    STR_ID_BGSR_RESULT_FAIL_FOLDER_NOT_FOUND,   
    STR_ID_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT,          
    STR_ID_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT,     
    STR_ID_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR,          
    STR_ID_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR,         
    STR_ID_BGSR_RESULT_FAIL_COMM_SERVER_ERROR,          
    STR_ID_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT,        
    STR_ID_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED,        
    STR_ID_BGSR_RESULT_FAIL_COMM_UNKNOWN_APN,           
    STR_ID_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED,          
    STR_ID_BGSR_RESULT_FAIL_USER_CANCEL,                
    STR_ID_BGSR_RESULT_FAIL_INVALID_PARAMETER,      
    STR_ID_BGSR_RESULT_FAIL_INVALID_MSGID,              
    STR_ID_BGSR_RESULT_FAIL_INVALID_FOLDER,         
    STR_ID_BGSR_RESULT_FAIL_QUEUE_FULL,                
    STR_ID_BGSR_RESULT_FAIL_MSGID_IS_USING,        
    STR_ID_BGSR_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED,    
    STR_ID_BGSR_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM,
    STR_ID_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE,    
    STR_ID_BGSR_RESULT_FAIL,
    STR_ID_BGSR_MESSAGE_IS_TRANSMITTING,
    STR_ID_BGSR_SEND_FAIL_RESEND,
    STR_ID_BGSR_TOTAL                                
} STR_ID_BGSR_LIST;

/*******************************************************************************
 * Global Function
 *******************************************************************************/

#endif /* _MMS_BGSR_DEFS_H */ 

