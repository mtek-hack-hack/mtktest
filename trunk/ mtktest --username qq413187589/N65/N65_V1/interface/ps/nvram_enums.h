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
 * nvram_enums.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef NVRAM_ENUMS_H
#define NVRAM_ENUMS_H

typedef enum
{
    NVRAM_POWERON_NORMAL,
    NVRAM_POWERON_CHARGER,
    NVRAM_POWERON_ALARM,
    NVRAM_POWERON_INVALID
} nvram_poweron_mode_enum;

typedef enum
{
    NVRAM_LOCK_DISABLE,
    NVRAM_LOCK_ENABLE,
    NVRAM_LOCK_TEMP_DISABLE,
    NVRAM_LOCK_OTP,
    NVRAM_LOCK_INVALID
} nvram_lock_state_enum;

typedef enum
{
    NVRAM_RESET_ALL,
    NVRAM_RESET_USER,
    NVRAM_RESET_SYSTEM,
    NVRAM_RESET_CERTAIN,
    NVRAM_RESET_FACTORY,
    NVRAM_RESET_DIFFERENCE,
    NVRAM_RESET_CUSTPACK,
    NVRAM_RESET_BRANCH,
    NVRAM_RESET_SHADOW,
    NVRAM_RESET_INVALID
} nvram_reset_category_enum;

typedef enum
{
    /* NVRAM generic error code */
    NVRAM_ERRNO_SUCCESS,
    NVRAM_ERRNO_FAIL,
    NVRAM_ERRNO_INVALID,

    /* NVRAM driver error code */
    NVRAM_IO_ERRNO_OK = NVRAM_ERRNO_SUCCESS,
    NVRAM_IO_ERRNO_INVALID_LID,
    NVRAM_IO_ERRNO_INVALID_SIZE,
    NVRAM_IO_ERRNO_INVALID_RECORD,
    NVRAM_IO_ERRNO_UNINIT,
    NVRAM_IO_ERRNO_INIT,
    NVRAM_IO_ERRNO_CHK,
    NVRAM_IO_ERRNO_BUSY,
    NVRAM_IO_ERRNO_LOCKED,
    NVRAM_IO_ERRNO_WRONG_RINGLID,
    
    /* OTP */
    NVRAM_ERRNO_OTP_UNKNOW,    /* FS_FLASH_OTP_UNKNOWERR -123 */
    NVRAM_ERRNO_OTP_OVERSCOPE, /* FS_FLASH_OTP_OVERSCOPE -124 */
    NVRAM_ERRNO_OTP_WRITEFAIL, /* FS_FLASH_OTP_WRITEFAIL -125 */
    NVRAM_ERRNO_OTP_LOCKED,    /* FS_FLASH_OTP_LOCK_ALREADY -125 */
    NVRAM_ERRNO_OTP_INVALID_INPUT,
    NVRAM_ERRNO_OTP_INVALID_RANGE,
    NVRAM_ERRNO_OTP_WRITETWICE,

    
    NVRAM_ERRNO_MAX
} nvram_errno_enum;

typedef nvram_errno_enum nvram_io_errno_enum;

typedef kal_uint32 nvram_software_change_status_enum;

#define NVRAM_SOFTWARE_CHANGE   0x01
#define NVRAM_BRANCH_CHANGE     0x02
#define NVRAM_CUSTPACK_CHANGE   0x04
#define NVRAM_EMPTY_FAT         0x08

#endif /* NVRAM_ENUMS_H */ 

