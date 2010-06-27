/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtv_error.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_ERROR_H
#define _MTV_ERROR_H

#ifndef _FS_ERRNO_H
#include "fs_errcode.h"
#endif

typedef enum mtv_result_t
{
    /* success code */

    MTV_S_OK                = 0,
    MTV_S_FALSE             = 1,

    /* generic errors */

    MTV_E_FAIL              = -1,
    MTV_E_WRONG_STATE       = -2,
    MTV_E_INVALID_PARAM     = -3,
    MTV_E_RESOURCE_CONFLICT = -4,
    MTV_E_NOT_IMPLEMENTED   = -5,
    MTV_E_OVER_LIMIT        = -6,
    MTV_E_OUT_OF_MEMORY     = -7,
    MTV_E_BUSY              = -8,
    MTV_E_ABORTED           = -9,

    /* SPI errors */

    MTV_SPI_E_INTERNAL_ERROR  = -200,          /**< Internal error of SPI */
    MTV_SPI_E_NO_MORE_SERVICE = -201,          /**< No more service is allowed to start */
    MTV_SPI_E_INVALID_SERVICE = -202,          /**< Invalid service is specified */
    MTV_SPI_E_ALREADY_STARTED = -203,          /**< The service is already started */
    MTV_SPI_E_UNSUPPORTED_SERVICE_TYPE = -204, /**< Unsupported service type */

    /* Decoder errors */

    MTV_DEC_E_VIDEO           = -300,   /**< generic video decoder error */
    MTV_DEC_E_AUDIO           = -301,   /**< generic audio decoder error */
    MTV_DEC_E_INVALID_CONFIG  = -302,
    MTV_DEC_E_INVALID_AU      = -303,

    /* I/O errors = MTV_IO_E_BASE + fs_error */

    MTV_IO_E_BASE           = -1000,
    MTV_IO_E_DISK_FULL      = MTV_IO_E_BASE + FS_DISK_FULL

} mtv_result_t;

#endif /* _MTV_ERROR_H */
