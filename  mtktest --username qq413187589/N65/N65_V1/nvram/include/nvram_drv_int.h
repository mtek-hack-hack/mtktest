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
 * nvram_drv_int.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is init() function of PHB module; should be called by task init function.
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_DRV_INT_H
#define NVRAM_DRV_INT_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _KAL_RELEASE_H
#error "kal_release.h should be included"
#endif 

typedef kal_int32 nvram_drv_status_enum;
#define  NVRAM_DRV_OK                  0x00
#define  NVRAM_DRV_UNFORMATTED         0x01
#define  NVRAM_DRV_CHECKSUM_ERROR      0x02
#define  NVRAM_DRV_INVALID_RECORD_ID   0x03
#define  NVRAM_DRV_NOT_ENOUGH_SPACE    0x04
#define  NVRAM_DRV_EMPTY_RECORD        0x05
#define  NVRAM_DRV_FATAL_ERROR         0x06
#define  NVRAM_DRV_ERASE_BUSY          0x07

    typedef struct
    {
    #ifndef __FS_ON__
        /* FDM */
        nvram_drv_status_enum(*drv_init) (void);
        void (*drv_set_max_record_size) (kal_uint16 RecordSize);
        void (*drv_format) (void);
          nvram_drv_status_enum(*drv_write) (kal_uint8 *buffer, kal_char *nvramname, kal_uint16 section_number,
                                             kal_uint16 size, kal_bool ismsp, kal_bool initialize);
          nvram_drv_status_enum(*drv_read) (kal_uint8 *buffer, kal_char *nvramname, kal_uint16 section_number,
                                            kal_uint16 size, kal_bool ismsp);
        void (*fd_delete) (kal_char *nvramname);
          kal_uint8(*drv_get_record_number) (void);
    #else /* __FS_ON__ */ 
        /* FAT */
          nvram_drv_status_enum(*drv_init) (void);
        void (*drv_set_max_record_number) (kal_uint8 RecordNumber);
        void (*drv_format) (void);
        nvram_drv_status_enum(*drv_write) (kal_uint8 *buffer, 
                                           kal_char *nvramname, 
                                           kal_uint16 section_number,
                                           kal_uint16 size, 
                                           kal_bool ismsp,
                                           kal_bool initialize);
        
        nvram_drv_status_enum(*drv_read) (kal_char *nvramname, 
                                          kal_uint16 section_number, 
                                          kal_uint16 amount,
                                          kal_uint8 *buffer, /* size*amount */ 
                                          kal_uint16 size, /* size of one record */ 
                                          kal_bool ismsp);
        
          nvram_drv_status_enum(*drv_write_composed) (kal_char *nvramname, kal_uint16 section_number,
                                                      kal_uint8 *buffer, kal_uint16 size, kal_uint16 whole_size,
                                                      kal_uint16 startAddr, kal_bool initialize);
          nvram_drv_status_enum(*drv_read_composed) (kal_char *nvramname, kal_uint16 section_number,
                                                     kal_uint8 *buffer, kal_uint16 size, kal_uint16 whole_size,
                                                     kal_uint16 startAddr);
        void (*fd_delete) (kal_char *nvramname);
          kal_int32(*drv_get_record_size) (kal_char *nvramname, void *hint);
    #endif /* __FS_ON__ */ 
    } driver_entry_type;

    /* This function initialize all the context variables required for NVRAM Layer */
    extern void nvram_drv_construct(driver_entry_type *driver);

#ifdef __cplusplus
}
#endif 

#endif /* NVRAM_DRV_INT_H */ 

