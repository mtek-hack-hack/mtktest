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
*  DataMgr.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   A generic mechanism for data store/retrieve to/from file
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_DATA_STORE__
#include "FileMgr.h"
#include "DataMgr.h"

#include "UCS2Prot.h"

/*
 * bit operation macro define
 */
#define MARK_BIT_ON(a,b) ((b) |= (1<<(a)))
#define MARK_BIT_OFF(a,b) ((b) &= ~(1<<(a)))
#define IS_BIT_ON(a,b) ((b) & (1<<(a)))

/*
 * a record stored in file:
 *   (1 byte:is valid)(the rest of bytes are data bytes, its = record_size)
 */
#ifdef WIN32
static mmi_data_record_store_type unit_test_record_store;


/*****************************************************************************
 * FUNCTION
 *  mmi_data_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_data_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 record_id;
    U8 data[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* test init file */
    result = mmi_data_init_record_store(&unit_test_record_store, (S8*) L"D:\\db_file.dat", 128);
    /*
     * // add records
     * mmi_ucs2cpy( (S8*)data, (S8*)L"data record store:(1) add a record done!" );
     * result = mmi_data_add_record( &unit_test_record_store, &record_id, data );
     * mmi_ucs2cpy( (S8*)data, (S8*)L"data record store:(2) add a record done!" );
     * result = mmi_data_add_record( &unit_test_record_store, &record_id, data );
     * mmi_ucs2cpy( (S8*)data, (S8*)L"data record store:(3) add a record done!" );
     * result = mmi_data_add_record( &unit_test_record_store, &record_id, data );
     * mmi_ucs2cpy( (S8*)data, (S8*)L"data record store:(4) add a record done!" );
     * result = mmi_data_add_record( &unit_test_record_store, &record_id, data );
     * 
     * // get records
     * memset( data, 0, 128 );
     * result = mmi_data_get_record( &unit_test_record_store, record_id, data );
     */
    /* set records */
    record_id = 0;
    mmi_ucs2cpy((S8*) data, (S8*) L"data record store:(01) set a record done!");
    result = mmi_data_set_record(&unit_test_record_store, record_id, data, TRUE);
    record_id = 1;
    mmi_ucs2cpy((S8*) data, (S8*) L"data record store:(02) set a record done!");
    result = mmi_data_set_record(&unit_test_record_store, record_id, data, TRUE);
    record_id = 2;
    mmi_ucs2cpy((S8*) data, (S8*) L"data record store:(03) set a record done!");
    result = mmi_data_set_record(&unit_test_record_store, record_id, data, TRUE);
    record_id = 3;
    mmi_ucs2cpy((S8*) data, (S8*) L"data record store:(04) set a record done!");
    result = mmi_data_set_record(&unit_test_record_store, record_id, data, TRUE);

    /* delete the record */
    record_id = 0;
    result = mmi_data_delete_record(&unit_test_record_store, record_id);
    record_id = 1;
    result = mmi_data_delete_record(&unit_test_record_store, record_id);
    record_id = 2;
    result = mmi_data_delete_record(&unit_test_record_store, record_id);
    record_id = 3;
    result = mmi_data_delete_record(&unit_test_record_store, record_id);
}
#endif /* WIN32 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_data_scan_db_file
 * DESCRIPTION
 *  scan db file to update status from
 * PARAMETERS
 *  context     [?]     
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_data_scan_db_file(mmi_data_record_store_type *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open the db file */
    if ((fd = FS_Open(context->db_file, FS_CREATE | FS_ATTR_HIDDEN)) >= 0)
    {
        U32 size;
        U16 i;

        /* reset record_num, max_record_num, and bitset */
        context->record_num = 0;
        context->max_record_num = 0;
        memset(context->bitset, 0, MAX_RECORD_BITSET_SIZE);

        /* since we can open the db file, so set is_active = 1 */
        context->is_active = 1;

        /* loop through all records in the db file until it is end of file or up to the MAX_RECORD_SIZE-th record */
        for (i = 0; i < MAX_RECORD_SIZE && FS_Read(fd, context->buff, context->record_size + 1, &size) == FS_NO_ERROR;
             i++)
        {
            if (size < (U32) (context->record_size + 1))
            {
                break;  /* end of file */
            }
            /* check the first byte to know if it is a valid record */
            if (context->buff[0])
            {
                MARK_BIT_ON(i & 7, context->bitset[i >> 3]);
                context->record_num++;
            }
            else
            {
                MARK_BIT_OFF(i & 7, context->bitset[i >> 3]);
            }

            /* increment max_record_num */
            context->max_record_num++;
        }
        FS_Close(fd);
        return 0;
    }
    else
    {
        /* can't open the db file, something wrong with it, so set it as inactive */
        context->is_active = 0;
        return (S32) fd;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_init_record_store
 * DESCRIPTION
 *  init database status
 * PARAMETERS
 *  context         [?]         
 *  db_file         [?]         
 *  record_size     [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_init_record_store(mmi_data_record_store_type *context, S8 *db_file, S32 record_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if record_size is out of limit bcoz our read/write buff size is MAX_RECORD_SIZE */
    if (record_size > MAX_RECORD_SIZE)
    {
        return DB_OUT_OF_LIMIT;
    }

    mmi_ucs2ncpy((S8*) context->db_file, (S8*) db_file, FMGR_MAX_PATH_LEN);
    context->db_file[FMGR_MAX_PATH_LEN] = 0;    /* make sure it is null terminated even if the source db_file is longer than FMGR_MAX_PATH_LEN */
    context->record_size = record_size;

    /* perform a db file scan */
    return mmi_data_scan_db_file(context);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_add_record
 * DESCRIPTION
 *  add a record
 * PARAMETERS
 *  context         [?]     
 *  record_id       [?]     
 *  data            [?]     
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_add_record(mmi_data_record_store_type *context, U16 *record_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, offset;
    U32 size;
    FS_HANDLE fd;
    U16 index = 0, i, j = 0, k;
    U8 b, t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    /* check if record_num runs out of limit bcoz our bitset can only track MAX_RECORD_NUM records */
    if (context->record_num >= MAX_RECORD_NUM)
    {
        return DB_OUT_OF_LIMIT;
    }

    /* check if we need to expand the db file for new records */
    if (context->record_num == context->max_record_num)
    {
        index = context->max_record_num;
        i = index >> 3; /* indicate the i-th byte in bitset */
        j = index & 7;  /* indicate the j-th bit in the i-th byte */
    }
    else
    {
        BOOL is_found = FALSE;  /* for debug, it should always find an unused slot */

        for (i = 0; !is_found && i < MAX_RECORD_BITSET_SIZE; i++)
        {
            k = i << 3;
            /* check the i-th byte in bitset to know if it contains a zero bit */
            if ((t = ~(context->bitset[i])) != 0)
            {
                for (j = 0, b = 1; j < 8; j++, b <<= 1)
                {
                    /* check if the j-th bit is zero (we use inverse mask here) */
                    if (b & t)
                    {
                        index = k + j;
                        is_found = TRUE;    /* for debug */
                        goto finish_search_unused_slot;
                    }
                }
            }
        }
      finish_search_unused_slot:
        MMI_ASSERT(is_found);   /* for debug */
    }

    /* open the db file */
    if ((fd = FS_Open(context->db_file, FS_READ_WRITE)) < 0)
    {
        /* can't open the db file, something wrong with it, so set it as inactive */
        context->is_active = 0;
        return (S32) fd;
    }

    /* seek to the index-th record in db file */
    offset = (S32) index *(context->record_size + 1);

    if ((result = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        // if we can't seek to the right position,
        // the db file maybe be not sync with our in-memory status or it's not accessible in the meantime
        if (result == offset)
        {
            /* set the valid byte */
            context->buff[0] = 1;
            /* copy the data */
            memcpy(context->buff + 1, data, context->record_size);
            /* write to db file */
            if ((result = FS_Write(fd, context->buff, context->record_size + 1, &size)) == FS_NO_ERROR)
            {
                *record_id = index;
                MARK_BIT_ON(j, context->bitset[i]);
                /* update record_num */
                context->record_num++;
                /* if we expand db file, update max_record_num, too */
                if (context->record_num > context->max_record_num)
                {
                    context->max_record_num++;
                }
                MMI_ASSERT(context->record_num <= context->max_record_num);     /* for debug */
            }
        }
        else
        {
            result = DB_FS_SEEK_FAIL;
        }
    }

    FS_Close(fd);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_get_record
 * DESCRIPTION
 *  get a record
 * PARAMETERS
 *  context         [?]         
 *  record_id       [IN]        
 *  data            [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_get_record(mmi_data_record_store_type *context, U16 record_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset, result;
    U32 size;
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    /* check if the record_id is out of range */
    if (context->record_num == 0 || context->max_record_num <= record_id)
    {
        return DB_RECORD_NOT_FOUND;
    }

    /* check if it is valid */
    if (!IS_BIT_ON(record_id & 7, context->bitset[record_id >> 3]))
    {
        return DB_RECORD_NOT_FOUND;
    }

    /* open the db file */
    if ((fd = FS_Open(context->db_file, FS_READ_WRITE)) < 0)
    {
        /* can't open the db file, something wrong with it, so set it as inactive */
        context->is_active = 0;
        return (S32) fd;
    }

    /* seek to the record_id-th record in db file */
    offset = (S32) record_id *(context->record_size + 1);

    if ((result = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        // if we can't seek to the right position,
        // the db file maybe be not sync with our in-memory status or it's not accessible in the meantime
        if (result != offset)
        {
            result = DB_FS_SEEK_FAIL;
        }
        else if ((result = FS_Read(fd, context->buff, context->record_size + 1, &size)) == FS_NO_ERROR)
        {
            if (size < (U32) (context->record_size + 1) || !context->buff[0])
            {
                /* not sync, file is modified off-line, so we need to adjust in-memory status for it */
                MARK_BIT_OFF(record_id & 7, context->bitset[record_id >> 3]);
                context->record_num--;
                result = DB_RECORD_NOT_FOUND;
            }
            else
            {
                memcpy(data, context->buff + 1, context->record_size);
            }
        }
    }

    FS_Close(fd);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_set_record
 * DESCRIPTION
 *  set a record
 * PARAMETERS
 *  context         [?]         
 *  record_id       [IN]        
 *  data            [?]         BOOL alway_create
 *  always_add      [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_set_record(mmi_data_record_store_type *context, U16 record_id, void *data, BOOL always_add)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, offset;
    U32 size;
    FS_HANDLE fd;
    U16 i = record_id & 7;
    U16 j = record_id >> 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    if (always_add)
    {
        if (record_id >= MAX_RECORD_NUM)
        {
            return DB_OUT_OF_LIMIT;
        }
    }
    else
    {
        /* check if the record_id is out of range */
        if (context->record_num == 0 || context->max_record_num <= record_id)
        {
            return DB_RECORD_NOT_FOUND;
        }

        /* check if it is valid */
        if (!IS_BIT_ON(i, context->bitset[j]))
        {
            return DB_RECORD_NOT_FOUND;
        }
    }

    /* open the db file */
    if ((fd = FS_Open(context->db_file, FS_READ_WRITE)) < 0)
    {
        /* can't open the db file, something wrong with it, so set it as inactive */
        context->is_active = 0;
        return (S32) fd;
    }

    /* seek to the record_id-th record in db file */
    offset = (S32) record_id *(context->record_size + 1);

    if ((result = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        // if we can't seek to the right position,
        // the db file maybe be not sync with our in-memory status or it's not accessible in the meantime
        if (result == offset)
        {
            /* set the valid byte */
            context->buff[0] = 1;
            /* copy the data */
            memcpy(context->buff + 1, data, context->record_size);
            /* write to db file */
            result = FS_Write(fd, context->buff, context->record_size + 1, &size);
            /* If IS_BIT_ON is false and it reach here, always_add must be ON!! */
            if (!IS_BIT_ON(i, context->bitset[j]))
            {
                MARK_BIT_ON(i, context->bitset[j]);
                context->record_num++;
                if (record_id >= context->max_record_num)
                {
                    context->max_record_num = record_id + 1;
                }
            }
        }
        else
        {
            result = DB_FS_SEEK_FAIL;
        }
    }

    FS_Close(fd);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_delete_record
 * DESCRIPTION
 *  delete a record
 * PARAMETERS
 *  context         [?]         
 *  record_id       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_delete_record(mmi_data_record_store_type *context, U16 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, offset;
    U32 size;
    FS_HANDLE fd;
    U16 last_record_index = 0, k;
    S16 i, j;
    U8 b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    /* check if the record_id is out of range */
    if (context->record_num == 0 || context->max_record_num <= record_id)
    {
        return DB_RECORD_NOT_FOUND;
    }

    /* check if it is valid */
    if (!IS_BIT_ON(record_id & 7, context->bitset[record_id >> 3]))
    {
        return DB_RECORD_NOT_FOUND;
    }

    /* open the db file */
    if ((fd = FS_Open(context->db_file, FS_READ_WRITE)) < 0)
    {
        /* can't open the db file, something wrong with it, so set it as inactive */
        context->is_active = 0;
        return (S32) fd;
    }

    /* seek to the record_id-th record in db file */
    offset = (S32) record_id *(context->record_size + 1);

    if ((result = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        // if we can't seek to the right position,
        // the db file maybe be not sync with our in-memory status or it's not accessible in the meantime
        if (result == offset)
        {
            /* set the valid byte */
            context->buff[0] = 0;
            /* zero the data part */
            memset(context->buff + 1, 0, context->record_size);
            /* write to db file */
            if ((result = FS_Write(fd, context->buff, context->record_size + 1, &size)) == FS_NO_ERROR)
            {
                MARK_BIT_OFF(record_id & 7, context->bitset[record_id >> 3]);
                context->record_num--;
                /* if it is the last record, we can truncate the db file */
                if (record_id == context->max_record_num - 1)
                {
                    // truncate the db file up to the new last-record
                    // so we try to find the new last-record here
                    // use backward loop through bitset
                    BOOL is_found = FALSE;

                    for (i = MAX_RECORD_BITSET_SIZE - 1; i >= 0; i--)
                    {
                        k = (U16) i << 3;
                        if (context->bitset[i])
                        {
                            for (j = 7, b = 0x80; j >= 0; j--, b >>= 1)
                            {
                                if (b & context->bitset[i])
                                {
                                    last_record_index = k + j;
                                    is_found = TRUE;    /* for debug */
                                    goto finish_find_last_used_slot;
                                }
                            }
                        }
                    }
                  finish_find_last_used_slot:
                    /* if the new last valid record is not found, it means we can truncate the entire db_file */
                    if (is_found)
                    {
                        offset = (S32) (last_record_index + 1) * (context->record_size + 1);
                    }
                    else
                    {
                        offset = 0;
                    }
                    if ((result = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
                    {
                        if (result == offset)
                        {
                            if (FS_Truncate(fd) == FS_NO_ERROR)
                            {
                                context->max_record_num = ((offset == 0) ? 0 : last_record_index + 1);
                            }
                        }
                    }
                    result = 0; /* we don't care if the truncate succeed or not, so set result = 0 */
                }
            }
        }
        else
        {
            result = DB_FS_SEEK_FAIL;
        }
    }

    FS_Close(fd);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_check_record
 * DESCRIPTION
 *  check a record
 * PARAMETERS
 *  context             [?]         
 *  record_id           [IN]        
 *  check_db_file       [IN]        <-- use FALSE for a quick check
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_check_record(mmi_data_record_store_type *context, U16 record_id, BOOL check_db_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset, result;
    U32 size;
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    /* check if the record_id is out of range */
    if (context->record_num == 0 || context->max_record_num <= record_id)
    {
        return DB_RECORD_NOT_FOUND;
    }

    /* check if it is valid */
    if (!IS_BIT_ON(record_id & 7, context->bitset[record_id >> 3]))
    {
        return DB_RECORD_NOT_FOUND;
    }

    // if check_db_file is on, it has to do exactly what get_record does with file operations, like seek and read, to make sure
    // that file is there and the record location and space are also right with valid data marker
    if (check_db_file)
    {
        /* open the db file */
        if ((fd = FS_Open(context->db_file, FS_READ_WRITE)) < 0)
        {
            /* can't open the db file, something wrong with it, so set it as inactive */
            context->is_active = 0;
            return (S32) fd;
        }

        /* seek to the record_id-th record in db file */
        offset = (S32) record_id *(context->record_size + 1);

        if ((result = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
        {
            // if we can't seek to the right position,
            // the db file maybe be not sync with our in-memory status or it's not accessible in the meantime
            if (result != offset)
            {
                result = DB_FS_SEEK_FAIL;
            }
            else if ((result = FS_Read(fd, context->buff, context->record_size + 1, &size)) == FS_NO_ERROR)
            {
                if (size < (U32) (context->record_size + 1) || !context->buff[0])
                {
                    /* not sync, file is modified off-line, so we need to adjust in-memory status for it */
                    MARK_BIT_OFF(record_id & 7, context->bitset[record_id >> 3]);
                    context->record_num--;
                    result = DB_RECORD_NOT_FOUND;
                }
            }
        }

        FS_Close(fd);
    }
    else
    {
        result = 0;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_check_space_for_set_record
 * DESCRIPTION
 *  check if available free disk space for set record by given id
 * PARAMETERS
 *  context         [?]         
 *  record_id       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_check_space_for_set_record(mmi_data_record_store_type *context, U16 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset, result;
    FS_DiskInfo disc_info;
    U16 dir[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    /* check if the record_id is inside range */
    if (context->record_num > 0 && context->max_record_num > record_id)
    {
        return 0;
    }

    if (record_id >= MAX_RECORD_NUM)
    {
        return DB_OUT_OF_LIMIT;
    }

    offset = (S32) (record_id - context->max_record_num) * context->record_size;
    mmi_ucs2ncpy((S8*) dir, (const S8*)context->db_file, 3);     /* copy "X:\" */

    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (result > 0 && (result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE)))
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) <= (U32) offset)
        {
            return FS_DISK_FULL;
        }
        else
        {
            return 0;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_data_check_space_for_add_record
 * DESCRIPTION
 *  check if available free disk space for add a new record
 * PARAMETERS
 *  context     [?]     
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_data_check_space_for_add_record(mmi_data_record_store_type *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset, result;
    FS_DiskInfo disc_info;
    U16 dir[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if it is active, otherwise perform a db file scan */
    if (!context->is_active)
    {
        if ((result = mmi_data_scan_db_file(context)) != 0)
        {
            return result;
        }
    }

    /* check if record_num runs out of limit bcoz our bitset can only track MAX_RECORD_NUM records */
    if (context->record_num >= MAX_RECORD_NUM)
    {
        return DB_OUT_OF_LIMIT;
    }

    /* check if we need to expand the db file for new records */
    if (context->record_num == context->max_record_num) /* full */
    {
        offset = (S32) context->record_size;
    }
    else
    {
        return 0;
    }

    mmi_ucs2ncpy((S8*) dir, (const S8*)context->db_file, 3);     /* copy "X:\" */

    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (result > 0 && (result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE)))
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) <= (U32) offset)
        {
            return FS_DISK_FULL;
        }
        else
        {
            return 0;
        }
    }

    return result;
}
#endif /* __MMI_DATA_STORE__ */ 

