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
 * nvram_drval_fat.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is Driver adaption level functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _NVRAM_DRVAL_FAT_H
#define _NVRAM_DRVAL_FAT_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
/***************************************************************************** 
* Define
*****************************************************************************/

#ifdef __FS_ASCII__
#define TCHAR kal_char
#else 
#define TCHAR unsigned short
#endif 

#define NVRAM_MAX_PATH_LEN                   32
#define NVRAM_FS_DATATIEM_FILENAME_TPLT      "MT01_000.TMP"
#define NVRAM_FS_FOLDER_NAME                 L"NVRAM\0"
#define NVRAM_FS_ROOT_PATH                   "Z:\\NVRAM\0"
#define NVRAM_FS_DATAITEM_PATH               "Z:\\NVRAM\\NVD_DATA\0"
#define NVRAM_FS_DSP_EXCEP_FILENAME          "Z:\\DSP_EX.BIN\0"
#define NVRAM_FS_USER_PATH                   "Z:\\@USER\0"
#define NVRAM_SWCHANGE_REPORT_FILE           "Z:\\@USER\\SWCHANGE\0"
#define NVRAM_SWCHANGE_REPORT_FILE_TXT       "Z:\\@USER\\SWCHANGE.TXT\0"
#define NVRAM_SWFORCEUPGRADE_FILE            "Z:\\@USER\\SWFORCEUPGRADE\0"

typedef kal_int32 nvram_drv_status_enum;
#define  NVRAM_DRV_OK                  0x00
#define  NVRAM_DRV_UNFORMATTED         0x01
#define  NVRAM_DRV_CHECKSUM_ERROR      0x02
#define  NVRAM_DRV_INVALID_RECORD_ID   0x03
#define  NVRAM_DRV_NOT_ENOUGH_SPACE    0x04
#define  NVRAM_DRV_EMPTY_RECORD        0x05
#define  NVRAM_DRV_FATAL_ERROR         0x06
#define  NVRAM_DRV_ERASE_BUSY          0x07
#define  NVRAM_DRV_DRIVE_BROKEN        0x08
#define  NVRAM_DRV_DRIVE_VNOERR        0x10

    /* marco to form absolute path and filename */
#ifdef __FS_ASCII__

    /* ascii */
#define NVRAM_FS_MAKE_LID_PATH_FILENAME_1( buf, name )   \
   kal_sprintf( buf, "%s\\%s", NVRAM_FS_DATAITEM_PATH, name)

#define NVRAM_FS_MAKE_CUST_LID_PATH_FILENAME( buf, c )     \
   kal_sprintf( buf, "%s\\%s%03d", NVRAM_FS_DATAITEM_PATH, \
                              NVRAM_FS_DATAITEM_PREFIX, c )

#define NVRAM_FS_MAKE_ROOT_PATH(buf)  \
   kal_sprintf( buf, "%s", NVRAM_FS_ROOT_PATH )

#define NVRAM_FS_MAKE_DATAITEM_PATH(buf)  \
   kal_sprintf( buf, "%s", NVRAM_FS_DATAITEM_PATH )

#define NVRAM_FS_MAKE_DSP_EXCEP_FILENAME(buf)  \
   kal_sprintf( buf, "%s", NVRAM_FS_DSP_EXCEP_FILENAME )

#define NVRAM_FS_GET_FULL_PATH_LEN \
   (strlen(NVRAM_FS_DATAITEM_PATH) + strlen(NVRAM_FS_DATATIEM_FILENAME_TPLT) + 1)

#define NVRAM_FS_MAKE_USER_PATH(buf)  \
   kal_sprintf( buf, "%s", NVRAM_FS_USER_PATH )

#else /* __FS_ASCII__ */ 

    /* File System with wide character interface */
#define NVRAM_FS_MAKE_LID_PATH_FILENAME_1( buf, name )   \
   kal_wsprintf( buf, "%s\\%s", NVRAM_FS_DATAITEM_PATH, name)

#define NVRAM_FS_MAKE_CUST_LID_PATH_FILENAME( buf, c )      \
   kal_wsprintf( buf, "%s\\%s%03d", NVRAM_FS_DATAITEM_PATH, \
                              NVRAM_FS_DATAITEM_PREFIX, c )

#define NVRAM_FS_MAKE_ROOT_PATH(buf)  \
   kal_wsprintf( buf, "%s", NVRAM_FS_ROOT_PATH )

#define NVRAM_FS_MAKE_DATAITEM_PATH(buf)  \
   kal_wsprintf( buf, "%s", NVRAM_FS_DATAITEM_PATH )

#define NVRAM_FS_MAKE_DSP_EXCEP_FILENAME(buf)  \
   kal_wsprintf( buf, "%s", NVRAM_FS_DSP_EXCEP_FILENAME )

#define NVRAM_FS_GET_FULL_PATH_LEN \
   (strlen(NVRAM_FS_DATAITEM_PATH) + strlen(NVRAM_FS_DATATIEM_FILENAME_TPLT) + 1)

#define NVRAM_FS_MAKE_USER_PATH(buf)  \
   kal_wsprintf( buf, "%s", NVRAM_FS_USER_PATH )

#endif /* __FS_ASCII__ */ 
#define NVRAM_CHKSUM_SIZE 2
/***************************************************************************** 
             
* Extern Global 
Function                                                                    
*****************************************************************************/
    extern nvram_drv_status_enum nvram_drv_fat_init(void);
    extern void nvram_drv_fat_set_max_record_number(kal_uint8 RecordNumber);
    extern void nvram_drv_fat_format(void);
    extern nvram_drv_status_enum nvram_drv_fat_write(
                                    kal_uint8 *buffer,
                                    kal_char *nvramname,
                                    kal_uint16 section_number,
                                    kal_uint16 size,
                                    kal_bool ismsp,
                                    kal_bool initialize);
    extern nvram_drv_status_enum nvram_drv_fat_read(
                                    kal_char *nvramname,
                                    kal_uint16 section_number,
                                    kal_uint16 amount,
                                    kal_uint8 *buffer, /* size*amount */ 
                                    kal_uint16 size, /* size of one record */ 
                                    kal_bool ismsp);
    extern nvram_drv_status_enum nvram_drv_fat_read_composed(
                                    kal_char *nvramname,
                                    kal_uint16 section_number,
                                    kal_uint8 *buffer,
                                    kal_uint16 size,
                                    kal_uint16 whole_size,
                                    kal_uint16 startAddr);
    extern nvram_drv_status_enum nvram_drv_fat_write_composed(
                                    kal_char *nvramname,
                                    kal_uint16 section_number,
                                    kal_uint8 *buffer,
                                    kal_uint16 size,
                                    kal_uint16 whole_size,
                                    kal_uint16 startAddr,
                                    kal_bool initialize);

    extern void nvram_drv_fat_delete(kal_char *nvramname);
    extern kal_int32 nvram_drv_fat_get_record_size(kal_char *nvramname, void *hint);

    extern nvram_drv_status_enum nvram_read_exception_item(
                                    kal_uint8 *buffer,
                                    kal_char *nvramname,
                                    kal_uint16 section_number,
                                    kal_uint16 size,
                                    kal_uint16 readsize);

    extern void nvram_drval_caculate_checksum(kal_uint16 *checksum, kal_uint8 *buf, kal_uint16 size);

#ifdef __cplusplus
}
#endif 

#endif /* _NVRAM_DRVAL_FAT_H */ 

