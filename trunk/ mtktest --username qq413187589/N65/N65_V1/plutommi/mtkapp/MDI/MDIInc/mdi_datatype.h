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
 * mdi_datatype.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Audio interfce header file
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_DATATYPE_H_
#define _MDI_DATATYPE_H_

#include "kal_non_specific_general_types.h"     /* include this for kal data type */
#include "MMIDataType.h"
#include "lcd_if.h" 


typedef U16 mdi_state;
typedef S32 mdi_handle;
typedef S32 mdi_result;
typedef void (*mdi_callback) (mdi_result result);
typedef void (*mdi_bt_callback) (U8 profile, mdi_result result);
typedef BOOL(*mdi_bg_callback) (mdi_result result);
typedef void (*mdi_mma_callback) (kal_int32 handle, kal_int32 result);

typedef U16 jdi_state;
typedef S32 jdi_handle;
typedef S32 jdi_result;
typedef void (*jdi_callback) (jdi_result result);
typedef BOOL(*jdi_bg_callback) (jdi_result result);
typedef void (*jdi_mma_callback) (kal_int32 handle, kal_int32 event);

typedef struct 
{
    U16 lcd_start_x;
    U16 lcd_start_y;
    U16 lcd_end_x;
    U16 lcd_end_y;
    U16 display_width;
    U16 display_height;
    U16 roi_offset_x;
    U16 roi_offset_y;
    U8 *image_buffer_p;
    U32 image_buffer_size;
    U16 lcd_rotate;
    MMI_BOOL tv_output;
    U16 tv_output_width;
    U16 tv_output_height;
    U16 tv_output_offset_x;
    U16 tv_output_offset_y;
    U32 tv_output_buffer_size;
    U8 *tv_output_buffer1_address;
    U8 *tv_output_buffer2_address;
} mdi_blt_para_struct;

#define MDI_HANDLE   mdi_handle
#define MDI_RESULT   mdi_result

#define JDI_HANDLE   jdi_handle
#define JDI_RESULT   jdi_result

/* camera 1000 */
#define MDI_RES_CAMERA_SUCCEED                        0
#define MDI_RES_CAMERA_XENONFLASH_CHARGING            1001
#define MDI_RES_CAMERA_ERR_FAILED                     -1001
#define MDI_RES_CAMERA_ERR_DISK_FULL                  -1002
#define MDI_RES_CAMERA_ERR_WRITE_PROTECTION           -1003
#define MDI_RES_CAMERA_ERR_NO_DISK                    -1004
#define MDI_RES_CAMERA_ERR_HW_NOT_READY               -1005
#define MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH          -1006
#define MDI_RES_CAMERA_ERR_PREVIEW_FAILED             -1007
#define MDI_RES_CAMERA_ERR_CAPTURE_FAILED             -1008
#define MDI_RES_CAMERA_ERR_ROOT_DIR_FULL              -1009
#define MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT         -1010
#define MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY     -1011


/* video recorder 2000 */
#define MDI_RES_VDOREC_SUCCEED                        0
#define MDI_RES_VDOREC_DISK_FULL                      2001
#define MDI_RES_VDOREC_REACH_SIZE_LIMIT               2002
#define MDI_RES_VDOREC_RECORD_ALREADY_STOP            2003
#define MDI_RES_VDOREC_ERR_FAILED                     -2001
#define MDI_RES_VDOREC_ERR_DISK_FULL                  -2002
#define MDI_RES_VDOREC_ERR_WRITE_PROTECTION           -2003
#define MDI_RES_VDOREC_ERR_NO_DISK                    -2004
#define MDI_RES_VDOREC_ERR_HW_NOT_READY               -2005
#define MDI_RES_VDOREC_ERR_PREVIEW_FAILED             -2006
#define MDI_RES_VDOREC_ERR_RESUME_FAILED              -2007
#define MDI_RES_VDOREC_ERR_PAUSE_FAILED               -2008
#define MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED           -2009
#define MDI_RES_VDOREC_ERR_POWER_ON_FAILED            -2010
#define MDI_RES_VDOREC_ERR_RECORD_FAILED              -2011
#define MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW           -2012
/* hongzhe.liu add start */
#define MDI_RES_TV_INITIALIZED_ERROR                  -2013
/* hongzhe.liu add end */

/* vdioe player 3000 */
#define MDI_RES_VDOPLY_SUCCEED                        0
#define MDI_RES_VDOPLY_SEEK_PARTIAL_DONE              3001
#define MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH    3002
#define MDI_RES_VDOPLY_REACH_STOP_TIME                3003
#define MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW         3004
#define MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW        3005
#define MDI_RES_VDOPLY_ERR_FAILED                     -3001
#define MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED           -3002
#define MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED            -3003
#define MDI_RES_VDOPLY_ERR_PLAY_FAILED                -3004
#define MDI_RES_VDOPLY_ERR_SEEK_FAILED                -3005
#define MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL         -3006
#define MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION  -3007
#define MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK           -3008
#define MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL     -3009
#define MDI_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED      -3010
#define MDI_RES_VDOPLY_ERR_INVALID_RESOULTION         -3011
#define MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT         -3012
#define MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT         -3013
#define MDI_RES_VDOPLY_ERR_DRM_PROHIBITED             -3014     /* no rights */
#define MDI_RES_VDOPLY_ERR_DRM_DURATION_USED          -3015

/* vdioe telephony 3500 */
#define MDI_RES_VDOTEL_SUCCEED                        0
#define MDI_RES_VDOTEL_ERR_FAILED                    -3501


/* swflash 4000 */
#define MDI_RES_SWFLASH_SUCCEED                        0

#define MDI_RES_SWFLASH_ERR_FAILED                     -4001
#define MDI_RES_SWFLASH_ERR_CREATE_HCIMFILE            -4002
#define MDI_RES_SWFLASH_ERR_GET_CIM_BUFFER             -4003
#define MDI_RES_SWFLASH_ERR_SET_CIM_BUFFER             -4004
#define MDI_RES_SWFLASH_BUSY                           -4005
#define MDI_RES_SWFLASH_ERR_FILE_ERROR                 -4006
#define MDI_RES_SWFLASH_ERR_ENGINE_ERROR               -4007
#define MDI_RES_SWFLASH_ERR_NETWORK_ERROR              -4008

#define MDI_RES_SWFLASH_PARTIAL_CMP                    -4010

#define MDI_RES_SWFLASH_ERR_OPEN_FILE                  -4011
#define MDI_RES_SWFLASH_ERR_GET_FILE_SIZE              -4012
#define MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE            -4013
#define MDI_RES_SWFLASH_ERR_GET_MED_MEM                -4014
#define MDI_RES_SWFLASH_ERR_READ_FILE                  -4015
#define MDI_RES_SWFLASH_ERR_WRITE_FILE                 -4016
#define MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL          -4017
#define MDI_RES_SWFLASH_ERR_WRITE_FILE_PARTIAL         -4018

/* reserve 10 spaces for following */
#define MDI_RES_SWFLASH_ERR_CREATE_CIM                 -4020

#define MDI_RES_SWFLASH_CIM_NULL                       -4030
#define MDI_RES_SWFLASH_OPEN_FAIL                      -4031
#define MDI_RES_SWFLASH_CLOSE_FAIL                     -4032
#define MDI_RES_SWFLASH_PLAY_FAIL                      -4033
#define MDI_RES_SWFLASH_STOP_FAIL                      -4034
#define MDI_RES_SWFLASH_PAUSE_FAIL                     -4035
#define MDI_RES_SWFLASH_RESUME_FAIL                    -4036
#define MDI_RES_SWFLASH_ERR_DECIPHER	               -4037
#define MDI_RES_SWFLASH_ERR_CREATE_INSTANCE	           -4038
#define MDI_RES_SWFLASH_ERR_LOAD	                   -4039
#define MDI_RES_SWFLASH_ERR_ENGINE_FILE_PARSE	       -4040

/* barcode reader 5000 */
#define MDI_RES_BARCODEREADER_DECODE_OK               0
#define MDI_RES_BARCODEREADER_IMAGE_ERROR               -5001
#define MDI_RES_BARCODEREADER_MODULE_ERROR              -5002
#define MDI_RES_BARCODEREADER_OUT_OF_MEMORY             -5003
#define MDI_RES_BARCODEREADER_OVER_VERSION              -5004
#define MDI_RES_BARCODEREADER_DECODE_TIMEOUT            -5005
#define MDI_RES_BARCODEREADER_ERROR_CODE_TYPE                -5006

/* Mobile TV 6000 */
#define MDI_RES_MTV_COMPLETE_SAVING                 6001

#define MDI_RES_MTV_SUCCEED                             0
#define MDI_RES_MTV_COMMON_ERROR                        -6001

#define MDI_RES_MTV_ERR_FAILED                     -6201
#define MDI_RES_MTV_ERR_DISK_FULL                  -6202
#define MDI_RES_MTV_ERR_WRITE_PROTECTION           -6203
#define MDI_RES_MTV_ERR_NO_DISK                    -6204
#define MDI_RES_MTV_ERR_HW_NOT_READY               -6205
#define MDI_RES_MTV_ERR_PREVIEW_FAILED             -6206
#define MDI_RES_MTV_ERR_RESUME_FAILED              -6207
#define MDI_RES_MTV_ERR_PAUSE_FAILED               -6208
#define MDI_RES_MTV_ERR_SAVE_FILE_FAILED           -6209
#define MDI_RES_MTV_ERR_POWER_ON_FAILED            -6210
#define MDI_RES_MTV_ERR_RECORD_FAILED              -6211
#define MDI_RES_MTV_ERR_STORAGE_TOO_SLOW           -6212

#define MDI_RES_MTV_ERR_CORRUPT_FAT         (-6301)
#define MDI_RES_MTV_ERR_PHONE_DISK_FULL     (-6302)
#define MDI_RES_MTV_ERR_CARD_DISK_FULL      (-6303)
#define MDI_RES_MTV_ERR_ROOT_DIR_FULL       (-6304)


#define MDI_RES_MTV_UNSAVE_RECORDING_IND                -6100

#ifdef LCD_LAYER_ROTATE_NORMAL
#define MDI_LCD_ROTATE_0              LCD_LAYER_ROTATE_NORMAL
#define MDI_LCD_ROTATE_90             LCD_LAYER_ROTATE_90
#define MDI_LCD_ROTATE_180            LCD_LAYER_ROTATE_180
#define MDI_LCD_ROTATE_270            LCD_LAYER_ROTATE_270
#define MDI_LCD_ROTATE_0_MIRROR       LCD_LAYER_MIRROR
#define MDI_LCD_ROTATE_90_MIRROR      LCD_LAYER_MIRROR_ROTATE_90
#define MDI_LCD_ROTATE_180_MIRROR     LCD_LAYER_MIRROR_ROTATE_180
#define MDI_LCD_ROTATE_270_MIRROR     LCD_LAYER_MIRROR_ROTATE_270
#else
/* driver not defined */
#define MDI_LCD_ROTATE_0              0
#define MDI_LCD_ROTATE_90             1
#define MDI_LCD_ROTATE_180            2
#define MDI_LCD_ROTATE_270            3
#define MDI_LCD_ROTATE_0_MIRROR       4
#define MDI_LCD_ROTATE_90_MIRROR      5
#define MDI_LCD_ROTATE_180_MIRROR     6
#define MDI_LCD_ROTATE_270_MIRROR     7
#endif 

/* UART port 6000 */
#define MDI_RES_GPS_UART_SUCCEED                            0
#define MDI_RES_GPS_UART_ERR_PORT_ALREADY_OPEN              -7001
#define MDI_RES_GPS_UART_ERR_PORT_NUMBER_WRONG              -7002
#define MDI_RES_GPS_UART_ERR_PARAM_ERROR                    -7003
#define MDI_RES_GPS_UART_ERR_PORT_ALREADY_CLOSED            -7004
#define MDI_RES_GPS_UART_ERR_PORT_ERR_UNKNOW                -7005
#define MDI_RES_GPS_UART_ERR_PORT_ERR_NOT_OPEN                -7006


#endif /* _MDI_DATATYPE_H_ */ 

