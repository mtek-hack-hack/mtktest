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
 * nvram_interface.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   These are interface functions of NVRAM module.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_INTERFACE_H
#define NVRAM_INTERFACE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _STACK_LTLCOM_H
#error "stack_ltlcom.h should be included"
#endif 
#ifndef NVRAM_ENUMS_H
#error "nvram_enums.h should be included"
#endif 

    extern nvram_errno_enum nvram_get_info(kal_uint8 LID, kal_uint16 *total, kal_uint16 *size);

    /* Functions below are for system service */
    extern void nvram_pre_init(void);
    extern void nvram_write_exception(kal_uint16 length, long *ex_data);
    extern kal_bool nvram_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf);
    extern kal_bool nvram_set_imei_value(kal_uint8 length, kal_uint8 *imei_buf);
    extern kal_bool nvram_test_lock(void);
    extern kal_bool nvram_get_disk_file_info(kal_uint32 *diskfilesize, kal_uint32 *freespace, kal_uint32 *overhead);
    extern void nvram_space_reserve(WCHAR *SpecialName, kal_uint32 *StillNeed);
    extern kal_bool nvram_external_read_data(
                        kal_uint8 LID,
                        kal_uint8 rec_index,
                        kal_uint8 *buffer,
                        kal_uint16 buffer_size);
    extern kal_bool nvram_usb_read_data(kal_uint8 LID, kal_uint8 *buffer, kal_uint16 buffer_size);
    extern kal_uint32 nvram_software_change_status(void);
    extern void nvram_shutdown_handler(void);
    extern void nvram_config_com_port(void);
    extern void nvram_get_cti(kal_uint8 *port, kal_uint32 *baudrate);
    extern void nvram_get_tst(kal_uint8 *port, kal_uint32 *baudrate);
    extern void nvram_get_tst_l1(kal_uint8 *port, kal_uint32 *baudrate);
    extern void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
    extern void nvram_get_swdbg(kal_uint8 *swdbg_profile);
#ifdef __SHADOW_NVRAM__
    extern nvram_errno_enum nvram_get_shadow_buffer(nvram_lid_enum LID, kal_uint16 *size, kal_uint8 **buffer);
    extern nvram_io_errno_enum nvram_free_shadow_buffer(nvram_lid_enum LID);
#endif /* __SHADOW_NVRAM__ */
#ifdef __cplusplus
}
#endif 

#endif /* NVRAM_INTERFACE_H */ 

