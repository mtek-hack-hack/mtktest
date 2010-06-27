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
 *	dt_common_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DT common enum.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#ifndef DT_COMMON_ENUM_H
#define DT_COMMON_ENUM_H

#define DT_DOWNLOAD_ERROR_TIMER  100 /* 10 sec */
#define DT_DOWNLOAD_SLEEP_TIMER 5 /* 0.5 sec */  
#define DT_MAX_ARG_NUM		      16
#define DT_MAX_ERROR_NUM          160

#define DT_VALIDATOR_ERROR        255
#define DT_DEF_VALUE              0

#define DT_MAX_DATA_QUEUE_LENGTH                      512
#define DT_MAX_DATA_OUTPUT_QUEUE_LENGTH       512
#define DT_MAX_DATA_INPUT_QUEUE_LENGTH          1024

#define DT_MAX_UART_LENGTH             128
#define DT_SHORT_RSP_LEN          80

#define DT_DOWNLOAD_SIZE        200 /*AT will read 200 bytes row data form FS, and transfer to 400 bits hex string then print to PC*/
#define DT_UPLOAD_SIZE             400 /*Tool will give 800 bits hexstring, and AT transfer to 400 bytes row data then write to FS*/


typedef enum
{
   DT_SIMPLE_ERROR,
   DT_NUMERIC_ERROR,
   DT_TEXT_ERROR
} dt_error_report_mode_enum;

typedef enum
{
   DT_NUM_PARTIAL_HEAD_TAIL,
   DT_VERBOSE_FULL_HEAD_TAIL
} dt_result_code_format;

typedef enum
{
   DT_FS_OPEN,
   DT_FS_CLOSE,
   DT_FS_READ,
   DT_FS_WRITE,
   DT_FS_DELETE,
   DT_FS_DIR,
   DT_FS_CREATEDIR,
   DT_FS_DELETEDIR,
   DT_FS_RENAME
} dt_fs_opcode_enum;

typedef enum
{
   DT_IMELODY,
   DT_SOUND_OTHER,
   DT_IMAGE,
   DT_APP_UNKNOWN,
   DT_NO_APP_TYPE = 0xff
} dt_app_type_enum;

typedef enum
{

   DT_NO_ERR,/*0*/
   DT_ERR_SYNTEX_ERROR,/*1*/
   DT_ERR_UNSPECIFIED,/*2*/
   DT_ERR_OPEN_FILE_FAILURE,/*3*/
   DT_ERR_READ_FILE_FAILURE,/*4*/
   DT_ERR_GET_DRIVE_FAILURE,/*5*/
   DT_ERR_USER_ABORT,/*6*/
   DT_ERR_USB_PLUGOUT,/*7*/
   DT_ERR_OPERATION_NOT_ALLOWED_ERR,/*8*/
   DT_ERR_OPERATION_NOT_SUPPORTED,/*9*/
   DT_ERR_TEXT_ERRSTRING_TOO_LONG_ERR,/*10*/
   DT_ERR_INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR,/*11*/
   DT_ERR_UNKNOWN,/*12*/
   DT_ERR_INVALID_CMD,/*13*/
   DT_ERR_FILE_PATH_EXCEEDED,/*14*/
   DT_ERR_FOLDER_NOT_FOUND/*15*/ 
} dt_err_id_enum;

typedef enum
{
   DT_RCODE_OK,
   DT_RCODE_ERROR

} dt_rsp_type_enum;

typedef enum
{
   DT_EFSR,
   DT_EMDY,
   DT_EIMG,
   DT_EFSW,
   DT_NO_TRANSFER_TYPE = 0xff
   
} dt_transfer_type_enum;

typedef enum
{
   DT_SPACE                 = ' ',
   DT_EQUAL                 = '=',
   DT_COMMA                 = ',',
   DT_SEMICOLON             = ';',
   DT_COLON                 = ':',
   DT_HAT                   = '^',
   DT_DOUBLE_QUOTE          = '"',
   DT_QUESTION_MARK         = '?',
   DT_FORWARD_SLASH         = '/',
   DT_L_ANGLE_BRACKET       = '<',
   DT_R_ANGLE_BRACKET       = '>',
   DT_L_SQ_BRACKET          = '[',
   DT_R_SQ_BRACKET          = ']',
   DT_CHAR_STAR             = '*',
   DT_CHAR_POUND            = '#',
   DT_CHAR_PERCENT          = '%',
   DT_CHAR_PLUS             = '+',
   DT_CHAR_MINUS            = '-',
   DT_CHAR_DOT              = '.',
   DT_CHAR_ULINE				='_',
   DT_END_OF_STRING_CHAR    = '\0',
   DT_CHAR_0                = '0',
   DT_CHAR_9                = '9',
   DT_CHAR_A                = 'A',
   DT_CHAR_F                = 'F',
   DT_CHAR_T                = 'T',
   DT_CHAR_Z                = 'Z',
   dt_char_a                = 'a',
   dt_char_c                = 'c',
   dt_char_d                = 'd',
   dt_char_f                = 'f',
   dt_char_t                = 't',
   dt_char_u                = 'u',
   dt_char_z                = 'z'
} dt_char_enum;

typedef enum
{
   DT_WRONG_MODE,
   DT_SET_OR_EXECUTE_MODE,
   DT_READ_MODE,
   DT_TEST_MODE,
   DT_ACTIVE_MODE
} dt_cmd_mode_enum;


typedef enum
{
   DT_PARSE_OK,
   DT_PARSE_ERROR, //out of range
   DT_PARSE_NOT_FOUND,
   DT_PARSE_TEXT_TOO_LONG
} dt_validator_cause_enum;

typedef enum
{
   DT_CHSET_IRA,
   DT_CHSET_HEX,
   DT_CHSET_GSM,
   DT_CHSET_UCS2
} dt_chset_enum;

typedef enum
{
   DT_IDLE_STATE,
   DT_UPLOAD_STATE,
   DT_DOWNLOAD_STATE,
   DT_FILELIST_STATE  
} dt_transfer_state_enum;


#endif /*DT_COMMON_ENUM_H*/

