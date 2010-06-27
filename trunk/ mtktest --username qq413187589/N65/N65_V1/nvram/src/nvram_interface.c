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
 * nvram_interface.c
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/
#include "kal_release.h"        /* Basic data type */

#include <stdio.h>

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "stack_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */

#include "nvram.h"

/* Prerequisite of nvram_context.h */
#include "custom_nvram_sec.h"
#include "nvram_defs.h"
#include "nvram_context.h"

/* Drvier Interface */
#include "nvram_enums.h"

#include "nvram_ltable.h"
#include "nvram_drval_fat.h"

#include "Fat_fs.h"

#if (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__)
/* Obtain NVRAM_EF_TST_FILTER_LID */
#include "nvram_data_items.h"
#include "nvram_enums.h"
#include "uart_sw.h"    /* UART_PORT type */

#ifdef __TST_MODULE__
#include "tst.h"        /* TST extern functions */
#endif
#endif /* (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__) */
#include "swdbg_sw.h"

#include "nvram_io.h"
#include "nvram_main.h"

#include "nvram_user_defs.h"
#include "custom_nvram_extra.h" /* for shutdown callback */

#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif

#ifdef __SHADOW_SUPPORT_SB__
#include <IntrCtrl.h>
#endif

/*****************************************************************************
* Define
*****************************************************************************/
#define NVRAM_SPACE_MARGIN 10

/*****************************************************************************
* Local Variable
*****************************************************************************/
static kal_uint8 nvram_exception_buffer[NVRAM_EF_SYS_EXCEPTION_SIZE];
static kal_uint8 CTI_UART_PORT = 0;
static UART_baudrate CTI_BAUD_RATE = 0;

/*****************************************************************************
* Global Variable
*****************************************************************************/
kal_bool High_Speed_SIM = KAL_FALSE;

/* global variable to record UART Power setting */
kal_uint8 UART_POWER_SETTING = 0;

/*****************************************************************************
* External Variable
*****************************************************************************/
extern kal_uint8 nvram_sec_key[256];

#ifdef __TST_MODULE__
extern UART_PORT TST_PORT;
extern UART_baudrate TST_BAUDRATE;

extern UART_PORT TST_PORT_L1;
extern UART_baudrate TST_BAUDRATE_L1;

#ifndef L4_NOT_PRESENT
extern UART_PORT PS_UART_PORT;
extern UART_baudrate PS_BAUDRATE;
#endif /* L4_NOT_PRESENT */
#endif /* __TST_MODULE__ */
extern kal_uint8 SWDBG_Profile;
extern kal_uint32 BytesPerCluster;  /* will be set to exact value in nvram_get_disk_file_info */

/*****************************************************************************
* External Function
*****************************************************************************/
#ifdef __MULTI_BOOT__
extern kal_uint16 INT_BootMode(void);
#endif

#if defined(__SHADOW_SUPPORT_SB__) && defined(__MTK_TARGET__)
extern void DisableIRQ(void);
extern void IRQDirectMaskAll(void);
#endif
extern nvram_drval_write_dsp_exception(kal_uint16 length, kal_uint8 *record);
extern void nvram_get_code_file_size(kal_uint32 *CodeFileSizeTotal);
extern void nvram_pre_init(void);

extern kal_bool INT_USBBoot(void);
extern kal_bool stack_update_sys_statistics(stack_statistics_struct *prev_stats);

#ifdef __IRDA_SUPPORT__
extern void IRDA_Open(void);
extern void init_ircomm_module(void);
#endif /* __IRDA_SUPPORT__ */

extern void UART_TurnOnPower(UART_PORT port, kal_bool enable);

extern void L1sim_Enable_Enhanced_Speed(kal_bool enable);

/*****************************************************************************
 * FUNCTION
 *  nvram_get_info
 * DESCRIPTION
 *  This is nvram_get_info() function of NVRAM module.
 * PARAMETERS
 *  LID         [IN]
 *  total       [?]
 *  size        [?]
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
nvram_errno_enum nvram_get_info(kal_uint8 LID, kal_uint16 *total, kal_uint16 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((nvram_ptr->state != NVRAM_STATE_READY) && !INT_USBBoot())
    {
        return NVRAM_ERRNO_FAIL;
    }

    nvram_pre_init();

    if (!NVRAM_IS_LID_VALID(LID))
    {
        return NVRAM_ERRNO_INVALID;
    }

    nvram_get_data_item(ldi, LID);

    *total = ldi->total_records;
    *size = ldi->size;

    return NVRAM_ERRNO_SUCCESS;
}   /* end of nvram_get_info function */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_exception
 * DESCRIPTION
 *
 * PARAMETERS
 *  length      [IN]
 *  ex_data     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_write_exception(kal_uint16 length, long *ex_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 prev_num = 0;

    nvram_drv_status_enum result;
    ltable_entry_struct *ldi;

    EX_LOG_T *exception_ptr = (EX_LOG_T*) nvram_exception_buffer;
    EX_HEADER_T exception_header;

    NVRAM_FILE_NAME nvramname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SHADOW_SUPPORT_SB__
    FS_LockFAT(FS_LOCK_BLOCK_ENUM);
    nvram_ptr->state = NVRAM_STATE_NOT_READY;
#endif /* __SHADOW_SUPPORT_SB__ */

    if (ex_data == NULL)
    {
        kal_print("nvram_write_exception(): ex_data == NULL\n");
    }

    /* Length must be equal to NVRAM_EF_SYS_EXCEPTION_SIZE */
    if (length != NVRAM_EF_SYS_EXCEPTION_SIZE)
    {
        return;
    }

    /* Exception could happen even when no task is initialized */
    if (nvram_ptr->state == NVRAM_STATE_NULL)
    {
        nvram_init(INDX_NIL);
    }

   /**
    * Now linear searching for a free record such that ex_data could be
    * written.
    *
    * Note that if value of ex_nvram field of a exception record
    * is NOT 0xFF, then it is a valid record; otherwise it is a free
    * record.
    * Furthermore, update of exception records cannot exceeds
    * the capacity, ie, number of exception records defined in NVRAM.
    * Once the storage is full, no more exception record can be dumped.
    * Hence, as long as a free record is found, then that record and
    * other records after it could be all assumed to be free.
    */

    nvram_get_data_item(ldi, NVRAM_EF_SYS_EXCEPTION_LID);

    /*
     * To be more sure that the exception record will be written successfully, do
     * *  1. Unlock all devices (and thus release RTFLock) to prevent from suspension
     * *  2. Shutdown the file system: The ensuing write operation will mount the flash drive
     * *      again, which will clean up, if any, drive level fatal errors.
     */

    /* unlock all devices (and thus release RTFLock) to prevent from suspension */
    FS_UnlockAll();
    FS_ShutDown();

    NVRAM_MAKE_LID_FILENAME(nvramname, ldi->fileprefix, '_', ldi->fileverno);

    for (i = 1; i <= NVRAM_EF_SYS_EXCEPTION_TOTAL; ++i)
    {
        result = nvram_read_exception_item(
                    (kal_uint8*) & exception_header,
                    nvramname,
                    i,
                    ldi->size,
                    sizeof(exception_header));
        /* Ok, now determine whether it is a free record */
        if ((result == NVRAM_DRV_OK) || (result == NVRAM_DRV_EMPTY_RECORD))
        {
            if ((exception_header.ex_nvram == (kal_uint8) NVRAM_INVALID_VALUE) || (exception_header.ex_serial_num < prev_num))  /* Found! */
            {
                break;
            }
            else
            {
                prev_num = exception_header.ex_serial_num;
            }
        }
        else    /* Error, read fail!? How come?.....Dunno what to do.. */
        {
            kal_char szBuf[64];

            sprintf(szBuf, "nvram_write_exception(): Read Exception [%d] Error!\n", i);
            kal_print(szBuf);
            return;
        }
    }

    if (i >= NVRAM_EF_SYS_EXCEPTION_TOTAL + 1)
    {
        i = 1;
    }

    prev_num += 1;
    if (prev_num == 0xFFFF)
    {
        prev_num = 1;   /* wrap around to 1 if it reaches 65535 */
    }

   /**
    *
    * Hence the first record is the free record. Increment the serial number
    * of the last record and take it as the new serial number for free record.
    */
    exception_ptr = (EX_LOG_T*) ex_data;
    exception_ptr->header.ex_nvram = KAL_TRUE;
    exception_ptr->header.ex_serial_num = prev_num;

    nvram_write_data_item(ldi, i, (kal_uint8*) ex_data, KAL_FALSE);

    /* Save the current statistics */
    {
        stack_statistics_struct statistic;

        ASSERT(sizeof(stack_statistics_struct) < MAX_NVRAM_RECORD_SIZE);
        kal_mem_set(&statistic, 0, NVRAM_EF_SYS_STATISTICS_SIZE);

        nvram_get_data_item(ldi, NVRAM_EF_SYS_STATISTICS_LID);
        nvram_read_data_item(ldi, 1, 1, (kal_uint8*) & statistic, sizeof(statistic));

        if (stack_update_sys_statistics(&statistic))
        {
            nvram_write_data_item(ldi, 1, (kal_uint8*) & statistic, KAL_FALSE);
        }
    }
}   /* end of nvram_write_exception function */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_dsp_exception
 * DESCRIPTION
 *
 * PARAMETERS
 *  length      [IN]
 *  record      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_write_dsp_exception(kal_uint16 length, kal_uint8 *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_drval_write_dsp_exception(length, record);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_imei_value
 * DESCRIPTION
 *  System service invoke this function to use IMEI_IMEISV as a seed
 *  to randomize its random generator.
 *
 *  Note: Currently, size of NVRAM_EF_IMEI_IMEISV_LID is 10 bytes.
 *  If given by length smaller than 10, then only first `length' bytes are read into `imei_buf'.
 * PARAMETERS
 *  length          [IN]        Length of imei_buf, in byte
 *  imei_buf        [?]         Where NVRAM_EF_IMEI_IMEISV_LID will be copied
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
kal_bool nvram_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum result;
    ltable_entry_struct *ldi;

    kal_uint8 buffer[NVRAM_EF_IMEI_IMEISV_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only after NVRAM is initialized could NVRAM_EF_IMEI_IMEISV_LID could be accessed */
    if (nvram_ptr->state == NVRAM_STATE_NULL)
    {
        return KAL_FALSE;
    }

    /* Now read NVRAM_EF_IMEI_IMEISV_LID */
    nvram_get_data_item(ldi, NVRAM_EF_IMEI_IMEISV_LID);

    result = nvram_read_data_item(ldi, 1, 1, buffer, NVRAM_EF_IMEI_IMEISV_SIZE);        /* multi-rec read support */

    /* Ok, now determine whether it is a free record */
    if ((result == NVRAM_IO_ERRNO_OK) || (result == NVRAM_IO_ERRNO_INIT))
    {
        kal_uint8 len;

        len = (length < NVRAM_EF_IMEI_IMEISV_SIZE) ? length : NVRAM_EF_IMEI_IMEISV_SIZE;

        /* Copy max(length, NVRAM_EF_IMEI_IMEISV_SIZE) into buffer */
        kal_mem_cpy(imei_buf, buffer, len);
    }

    /* Error, read fail!? How come?.....Dunno what to do.. */
    else
    {
        ASSERT(KAL_FALSE);
        return KAL_FALSE;
    }

    return KAL_TRUE;

}   /* end of nvram_get_imei_value function */


/*****************************************************************************
 * FUNCTION
 *  nvram_set_imei_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  length          [IN]
 *  imei_buf        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_set_imei_value(kal_uint8 length, kal_uint8 *imei_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_errno_enum result;
    ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only after NVRAM is initialized could NVRAM_EF_IMEI_IMEISV_LID could be accessed */
    if (nvram_ptr->state == NVRAM_STATE_NULL)
    {
        return;
    }

    /* Invaild buffer size, unsafe action! */
    if (length < NVRAM_EF_IMEI_IMEISV_SIZE)
    {
        return;
    }

    /* Now write NVRAM_EF_IMEI_IMEISV_LID */
    nvram_get_data_item(ldi, NVRAM_EF_IMEI_IMEISV_LID);

    result = nvram_write_data_item(ldi, 1, imei_buf, KAL_FALSE);

    /* Error, write fail!? How come?.....Dunno what to do.. */
    if (result != NVRAM_IO_ERRNO_OK)
    {
        ASSERT(KAL_FALSE);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_external_read_data
 * DESCRIPTION
 *  This function is used to get data items for external modules.
 * PARAMETERS
 *  LID             [IN]
 *  rec_index       [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 *  .(?)
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
kal_bool nvram_external_read_data(kal_uint8 LID, kal_uint8 rec_index, kal_uint8 *buffer, kal_uint16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi = NULL;
    nvram_errno_enum result = NVRAM_IO_ERRNO_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_pre_init();

    nvram_get_data_item(ldi, LID);

    if ((ldi == NULL) || (buffer_size != ldi->size))
    {
        return KAL_FALSE;
    }

#if defined(__SHADOW_SUPPORT_MS__)
    if (USBMS_BOOT == stack_query_boot_mode() && ldi->category & NVRAM_CATEGORY_SHADOW_MS)
    {

            shadow_ltable_struct *shadow_entry = &shadow_ltable[ldi->record_ID];

            if (buffer_size != ldi->size)
                return KAL_FALSE;

            kal_mem_cpy(
                buffer,
                shadow_entry->offset + (rec_index * ldi->size),
                ldi->size);
    }
    else
#endif
    {
        /* handle by nvram_io layer */
        result = nvram_read_data_item(ldi, rec_index, 1, buffer, buffer_size);
    }



    if (result != NVRAM_IO_ERRNO_OK)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  nvram_usb_read_data
 * DESCRIPTION
 *  This function is used to get bmt calibration data ONLY when USB power on.
 * PARAMETERS
 *  LID             [IN]
 *  buffer          [?]
 *  buffer_size     [IN]
 *  .(?)
 * RETURNS
 *  NVRAM_ERRNO_SUCCESS if succeed, NVRAM_ERRNO_INVALID otherwise (ie, invalid LID).
 *****************************************************************************/
kal_bool nvram_usb_read_data(kal_uint8 LID, kal_uint8 *buffer, kal_uint16 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!INT_USBBoot()) /* ONLY FOR USB MASS STROAGE MODE */
    {
        return KAL_FALSE;
    }

    return nvram_external_read_data(LID, 1, buffer, buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  nvram_software_change_status
 * DESCRIPTION
 *  Tell application software change or not
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_TRUE for software, KAL_FALSE otherwise
 *****************************************************************************/
kal_uint32 nvram_software_change_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_ptr->software_change_status;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_shutdown_handler
 * DESCRIPTION
 *  Disable all interrupts, change NVRAM state, change FS command mode, and flush
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_shutdown_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__L1_STANDALONE__)    
    /* to handle shutdown callback */
    for (i = 0; ;i++)
    {
        if (nvram_shutdown_cb_table[i].LID == 0 && nvram_shutdown_cb_table[i].get_data == NULL)  
        {
            break;
        }
        
        if (NVRAM_IS_LID_VALID(nvram_shutdown_cb_table[i].LID) && nvram_shutdown_cb_table[i].get_data)
        {
            kal_uint8 *data;
            ltable_entry_struct *ldi;

            nvram_get_data_item(ldi, nvram_shutdown_cb_table[i].LID);
            data = (kal_uint8 *)get_ctrl_buffer(ldi->size);
            if (nvram_shutdown_cb_table[i].get_data(data, ldi->size))
            {
                /* doesn't support linear-fix */
                nvram_write_data_item(ldi, 1, data, KAL_FALSE);
            }
            free_ctrl_buffer(data);
        }


    }
#endif /* !__L1_STANDALONE__ */
#ifdef __SHADOW_NVRAM__
#ifdef __SHADOW_SUPPORT_SB__
    if (NORMAL_BOOT == stack_query_boot_mode())
#else /* __SHADOW_SUPPORT_MS__ */
    if (USBMS_BOOT == stack_query_boot_mode())
#endif
    {
    #ifdef __SHADOW_SUPPORT_SB__
    #if defined(__MTK_TARGET__)
        /* Very important note, interrupt disable routine is allowed at this special point only! */
        DisableIRQ();
        IRQDirectMaskAll();
    #endif /*__MTK_TARGET__*/
        FS_LockFAT(FS_LOCK_BLOCK_ENUM);
    #endif /* __SHADOW_SUPPORT_SB__ */
        nvram_ptr->state = NVRAM_STATE_NOT_READY;
        nvram_flush_shadow();
    }
    nvram_ptr->state = NVRAM_STATE_READY;
#endif /* __SHADOW_NVRAM__ */
}


#ifdef __SHADOW_NVRAM__
/*****************************************************************************
 * FUNCTION
 *  nvram_get_shadow_buffer
 * DESCRIPTION
 *  To get the shadow buffer of given LID
 * PARAMETERS
 *  LID     [IN]        LID
 *  size    [OUT]       size of the shadow buffer
 *  buffer  [OUT]       address of the shadow buffer
 * RETURNS
 *  nvram_errno_enum    NVRAM_IO_ERRNO_INVALID_RECORD/NVRAM_IO_ERRNO_OK
 *****************************************************************************/
nvram_errno_enum nvram_get_shadow_buffer(nvram_lid_enum LID, kal_uint16 *size, kal_uint8 **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    shadow_ltable_struct *shadow_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_get_data_item(ldi, LID);

    if(!(ldi->category & NVRAM_CATEGORY_COMPOSED))
        return NVRAM_IO_ERRNO_INVALID_RECORD;

    shadow_entry = &shadow_ltable[ldi->record_ID];

    *buffer = shadow_entry->offset + GUARD_PATTERN_SIZE;
    *size = ldi->size - (GUARD_PATTERN_SIZE * 2);

    ASSERT(*(*buffer - GUARD_PATTERN_SIZE) == 0x00 &&
           *(*buffer - GUARD_PATTERN_SIZE + 1) == 0x00 &&
           *(*buffer + (*size)) == 0x00 &&
           *(*buffer + (*size) + 1) == 0x00 );

    /* Add guard pattern */
    kal_mem_set(*buffer - GUARD_PATTERN_SIZE, 0xF1,  GUARD_PATTERN_SIZE);
    kal_mem_set(*buffer + (*size) , 0xF2,  GUARD_PATTERN_SIZE);

    /* disable flush of this buffer, by resetting the dirty mask */
    kal_mem_set(shadow_entry->dirty_records, 0x00, sizeof(kal_uint32) * NVRAM_MAX_SHADOW_REC);

    return NVRAM_IO_ERRNO_OK;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_free_shadow_buffer
 * DESCRIPTION
 *  To free the shadow buffer of given LID
 * PARAMETERS
 *  LID     [IN]        LID
 * RETURNS
 *  void
 *****************************************************************************/
nvram_io_errno_enum nvram_free_shadow_buffer(nvram_lid_enum LID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ltable_entry_struct *ldi;
    shadow_ltable_struct *shadow_entry;
    kal_uint8 *buffer, *list = NULL;
    kal_uint16 size;
    kal_uint32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_get_data_item(ldi, LID);

    if(!(ldi->category & NVRAM_CATEGORY_COMPOSED))
        return NVRAM_IO_ERRNO_INVALID_RECORD;

    shadow_entry = &shadow_ltable[ldi->record_ID];

    buffer = shadow_entry->offset + GUARD_PATTERN_SIZE;
    size = ldi->size - (GUARD_PATTERN_SIZE * 2);

    ASSERT(*(buffer - GUARD_PATTERN_SIZE) == 0xF1 &&
           *(buffer - GUARD_PATTERN_SIZE + 1) == 0xF1 &&
           *(buffer + size) == 0xF2 &&
           *(buffer + size + 1) == 0xF2 );

    /* release guard pattern */
    kal_mem_set((buffer - GUARD_PATTERN_SIZE), 0x00,  GUARD_PATTERN_SIZE);
    kal_mem_set((buffer + size) , 0x00,  GUARD_PATTERN_SIZE);

    /* search dirty list first, if ldi not exist, adding it */

    nvram_get_dirty_list(list);
    for (i = 0, j = nvram_get_next_flush_lid(); i < nvram_get_total_dirty(); ++i)
    {
        if (ldi->LID == list[j++])
            return NVRAM_IO_ERRNO_OK;

        if (++j >= shadow_item_total)
        {
            j = 0;
        }
    }

    nvram_add_shadow_request(ldi, 1, shadow_entry->offset);
    kal_mem_set(shadow_entry->dirty_records, 0xFF, sizeof(kal_uint32) * NVRAM_MAX_SHADOW_REC);
    shadow_entry->dirty_records[0] &= 0xFFFE; /* Always start from record 1 */
    nvram_flush_shadow();

    return NVRAM_IO_ERRNO_OK;
}
#endif /* __SHADOW_NVRAM__ */


/*****************************************************************************
 * FUNCTION
 *  nvram_config_com_port
 * DESCRIPTION
 *  To init COM port setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_config_com_port(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buffer = NULL;
    ltable_entry_struct *ldi;
    nvram_errno_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_data_item(ldi, NVRAM_EF_PORT_SETTING_LID);
    buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);

    if (buffer)
    {
        port_setting_struct *port_setting;

        result = nvram_read_data_item(ldi, 1, 1, buffer, ldi->size);    /* multi-rec read support */
        /* Ok, now config UART/IrCOMM ports for L4 and TST, and filters to TST */
        if ((result == NVRAM_IO_ERRNO_OK) || (result == NVRAM_IO_ERRNO_INIT))
        {
            port_setting = (port_setting_struct*) buffer;

        #ifdef __TST_MODULE__

        #ifdef __IRDA_SUPPORT__
            if ( (uart_port_irda == (UART_PORT) port_setting->tst_port_ps) ||
                 (uart_port_irda == (UART_PORT) port_setting->tst_port_l1))
            {
                init_ircomm_module();
                IRDA_Open();
            }
        #endif /* __IRDA_SUPPORT__ */
            TST_PORT = (UART_PORT) port_setting->tst_port_ps;
            TST_BAUDRATE = port_setting->tst_baudrate_ps;

            TST_PORT_L1 = (UART_PORT) port_setting->tst_port_l1;
            TST_BAUDRATE_L1 = port_setting->tst_baudrate_l1;

        #ifndef L4_NOT_PRESENT
            PS_UART_PORT = (UART_PORT) port_setting->ps_port;
            PS_BAUDRATE = port_setting->ps_baudrate;
        #endif /* L4_NOT_PRESENT */
        #endif /* __TST_MODULE__ */

            High_Speed_SIM = port_setting->High_Speed_SIM_Enabled;

            if (High_Speed_SIM)
            {
                L1sim_Enable_Enhanced_Speed(High_Speed_SIM);
            }

            SWDBG_Profile = port_setting->swdbg;
            UART_POWER_SETTING = port_setting->uart_power_setting;
            CTI_UART_PORT = port_setting->cti_uart_port;
            CTI_BAUD_RATE = port_setting->cti_baudrate;

        #if defined(__SWDBG_SUPPORT__)
            swdbg_config(SWDBG_Profile);
        #endif

        #ifdef __MTK_TARGET__
        #ifndef __L1_STANDALONE__
            /* To determine if in META mode */
            if (FACTORY_BOOT != stack_query_boot_mode())
            {
                kal_bool enable;

                enable = (UART_POWER_SETTING & (0x01 << uart_port1)) ? KAL_TRUE : KAL_FALSE;
                UART_TurnOnPower(uart_port1, enable);

                enable = (UART_POWER_SETTING & (0x01 << uart_port2)) ? KAL_TRUE : KAL_FALSE;
                UART_TurnOnPower(uart_port2, enable);

                enable = (UART_POWER_SETTING & (0x01 << uart_port3)) ? KAL_TRUE : KAL_FALSE;
                UART_TurnOnPower(uart_port3, enable);
            }
            else    /* In META Mode, Turn on every UART power */
        #endif /* __L1_STANDALONE__ */
            {
                UART_TurnOnPower(uart_port1, KAL_TRUE);
                UART_TurnOnPower(uart_port2, KAL_TRUE);
                UART_TurnOnPower(uart_port3, KAL_TRUE);
            }
        #endif /* __MTK_TARGET__ */

        }

        free_ctrl_buffer(buffer);
    }

    buffer = NULL;

#if (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__)
    /* If L4 or TST exist */

    /* Ok, now send data to TST */
    nvram_get_data_item(ldi, NVRAM_EF_TST_FILTER_LID);

    buffer = (kal_uint8*) get_ctrl_buffer(ldi->size);

    if (buffer != NULL)
    {
        result = nvram_read_data_item(ldi, 1, 1, buffer, ldi->size);    /* multi-rec read support */

        /* Ok, now config UART/IrCOMM ports for L4 and TST, and filters to TST */
        if ((result == NVRAM_IO_ERRNO_OK) || (result == NVRAM_IO_ERRNO_INIT))
        {
        #ifdef __TST_MODULE__
            tst_init_filters((kal_char*) buffer, ldi->size);
        #endif
        }

        free_ctrl_buffer(buffer);
    }

#endif /* (!defined(L4_NOT_PRESENT)) || defined(__TST_MODULE__) */
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_cti
 * DESCRIPTION
 *  To get CTI_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_cti(kal_uint8 *port, kal_uint32 *baudrate)
{
    *port = CTI_UART_PORT;
    *baudrate = (kal_uint32) CTI_BAUD_RATE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_tst
 * DESCRIPTION
 *  To get TST_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_tst(kal_uint8 *port, kal_uint32 *baudrate)
{
#ifdef __TST_MODULE__
    *port = TST_PORT;
    *baudrate = (kal_uint32) TST_BAUDRATE;
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_tst
 * DESCRIPTION
 *  To get nvram_get_tst_l1
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_tst_l1(kal_uint8 *port, kal_uint32 *baudrate)
{
#ifdef __TST_MODULE__
    *port = TST_PORT_L1;
    *baudrate = (kal_uint32) TST_BAUDRATE_L1;
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_get_ps
 * DESCRIPTION
 *  To get PS_UART_PORT
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   CTI
 *****************************************************************************/
void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate)
{
#ifdef __TST_MODULE__
#ifndef L4_NOT_PRESENT
    *port = PS_UART_PORT;
    *baudrate = (kal_uint32) PS_BAUDRATE;
#else
    *port = NULL;
    *baudrate = (kal_uint32) NULL;
#endif /* L4_NOT_PRESENT */
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_swdbg
 * DESCRIPTION
 *  To get SWDBG_Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8   [OUT]   swdbg_profile
 *****************************************************************************/
void nvram_get_swdbg(kal_uint8 *swdbg_profile)
{
    	*swdbg_profile = SWDBG_Profile;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_space_reserve
 * DESCRIPTION
 *  To perform software upgrade.
 * PARAMETERS
 *  SpecialName         [?]
 *  StillNeed           [?]
 *  sysrecord(?)        [IN]        Sysrecord
 * RETURNS
 *  Success or Fail(?)
 *****************************************************************************/
void nvram_space_reserve(kal_uint32 *size_from_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 CodeFileSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* assume that BytesPerCluster still not initialized if BytesPerCluster==0 */
    if (BytesPerCluster == 0)
    {
        BytesPerCluster = FS_GetClusterSize('Z');
    }

    nvram_pre_init();

    nvram_get_code_file_size(&CodeFileSize);

    *size_from_code = (CodeFileSize / BytesPerCluster) + ((CodeFileSize / BytesPerCluster)? 1 : 0) + NVRAM_SPACE_MARGIN;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_space_reserve
 * DESCRIPTION
 *  To perform software upgrade.
 * PARAMETERS
 *  SpecialName         [?]
 *  StillNeed           [?]
 *  sysrecord(?)        [IN]        Sysrecord
 * RETURNS
 *  Success or Fail(?)
 *****************************************************************************/
void nvram_get_folder_name(WCHAR *nvram_folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wstrcpy(nvram_folder_name, NVRAM_FS_FOLDER_NAME);
}

