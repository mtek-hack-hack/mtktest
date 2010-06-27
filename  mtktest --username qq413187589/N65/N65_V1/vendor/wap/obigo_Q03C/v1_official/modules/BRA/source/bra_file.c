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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2003.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
#include "kal_release.h"
#include "bra_cfg.h"
#include "bra_file.h"
#include "bra_main.h"
#include "bra_sig.h"

#include "msf_file.h"
#include "msf_dcvt.h"
#include "msf_lib.h"
#include "msf_log.h"

/*************************************************
* Defines
**************************************************/

#define BRA_FILE_MIN_BLOCK_SIZE         4
#define BRA_FILE_BLOCK_USED_TOKEN       0xFF
#define BRA_FILE_BLOCK_NOT_USED_TOKEN   0xFE
#define BRA_FILE_MAX_N_PENDING_OP       10

/*************************************************
* Types
**************************************************/

typedef struct block_item_s
{
  int idx;
  int start;
  int size;
  struct block_item_s *next; 
}bra_file_block_item_t;

typedef struct
{
  int idx;
  unsigned char* block;
  int size;
  bra_file_op_callback_t callback;
} bra_file_defragment_t;

typedef struct
{
  int max_size;
  int size;
  int defragment_limit;
  int size_increment;
  int bytes_free;
  int block_index;
  char *file;
  bra_file_defragment_t *defrag;
  bra_file_init_callback_t callback;
  bra_file_block_item_t *free_list;
  bra_file_block_item_t *used_list;
}bra_file_handle_t;


typedef struct 
{
  bra_file_handle_t *handle;
  int file_handle;
  int event_type;
  int pos;
  int size;
  unsigned char* block;
  bra_file_op_callback_t callback;
} bra_file_op_item_t;

static int bra_file_last_op;             /*Index to first free select item*/
static int bra_file_current_op;          /*Index to current pending select item*/
static int bra_file_pending_op;          /*1 if there is a pending selsec, else 0*/

static bra_file_op_item_t bra_file_op_item_queue[BRA_FILE_MAX_N_PENDING_OP];

/*************************************************
* Function Prototypes
**************************************************/


static int
alloc_block (bra_file_handle_t *handle, unsigned char* block, int size, bra_file_op_callback_t callback);

static int
dealloc_block (bra_file_handle_t *handle, int idx, bra_file_op_callback_t callback);

static void
add_item (bra_file_block_item_t** list, bra_file_block_item_t *new_item);

static bra_file_block_item_t*
get_item_by_size (bra_file_block_item_t** list, int size);

/******************************************************************************************************************
  Internal interface functions
******************************************************************************************************************/

/*
 * This function performs one file task. if there are mor pending tasks the function
 * will send a signal to it self to continue with the next task. If a file operation was
 * delayed this function should be called when the select notification arrives.
 *
 * Parameters:
 *
 *
 * RETURN           : void
 */
void
bra_file_execute_file_task (void)
{
  int error;

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_DBBD6993CBA963B644D6045EDB352709, "BRA:Enter Execute, bra_file_current_op = %i bra_file_last_op = %i\n", bra_file_current_op,bra_file_last_op));

  if (bra_file_current_op == bra_file_last_op)
  {
    /*We have no pending selects*/
    return;
  }

  if (bra_file_op_item_queue[bra_file_current_op].file_handle < 0)
  {
    bra_file_op_item_queue[bra_file_current_op].file_handle = MSF_FILE_OPEN(MSF_MODID_BRA, bra_file_op_item_queue[bra_file_current_op].handle->file, MSF_FILE_SET_CREATE | MSF_FILE_SET_RDWR | HDI_FILE_SET_CUSTOM_BLOCKING,0);
  }

  MSF_FILE_SEEK(bra_file_op_item_queue[bra_file_current_op].file_handle, bra_file_op_item_queue[bra_file_current_op].pos, MSF_FILE_SEEK_SET);

  if (bra_file_op_item_queue[bra_file_current_op].event_type == MSF_FILE_EVENT_WRITE)
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_72E8FB129EA2A3529D5D230BB60ACC65, "BRA:Write File, size = %i\n", bra_file_op_item_queue[bra_file_current_op].size));

    error = MSF_FILE_WRITE(bra_file_op_item_queue[bra_file_current_op].file_handle,
                           bra_file_op_item_queue[bra_file_current_op].block,
                           bra_file_op_item_queue[bra_file_current_op].size );
  }
  else
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_527F88DA55F5289F9D726115A13C21C3, "BRA:Read File, size = %i\n", bra_file_op_item_queue[bra_file_current_op].size));

    error = MSF_FILE_READ(bra_file_op_item_queue[bra_file_current_op].file_handle,
                          bra_file_op_item_queue[bra_file_current_op].block,
                          bra_file_op_item_queue[bra_file_current_op].size );
  }

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_403348AAEA7C8FA55F9E1CC826421726, "BRA:Error = %i\n", error));


  if (error < 0)
  {
    /*check for select*/
    if (error == HDI_FILE_ERROR_DELAYED)
    {
      MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_C0199E8126BED6026C0CF4AD5CB27578, "BRA:File op delayed file_handle = %i, event = %i\n",bra_file_op_item_queue[bra_file_current_op].file_handle, bra_file_op_item_queue[bra_file_current_op].event_type));

      MSF_FILE_SELECT(bra_file_op_item_queue[bra_file_current_op].file_handle,
                      bra_file_op_item_queue[bra_file_current_op].event_type);
      return;
    }
  }

  /*Create new write task if error < size*/
  if (error != bra_file_op_item_queue[bra_file_current_op].size)
  {
    ASSERT(0)
  }
  else
  {
    /*Finished*/
    /*Call callback*/
    MSF_FILE_CLOSE (bra_file_op_item_queue[bra_file_current_op].file_handle);
    
    if (bra_file_op_item_queue[bra_file_current_op].event_type == MSF_FILE_EVENT_WRITE)
    {
      if (bra_file_op_item_queue[bra_file_current_op].callback != NULL)
        bra_file_op_item_queue[bra_file_current_op].callback(1);
      BRA_FREE (bra_file_op_item_queue[bra_file_current_op].block);
    }
    else
    {
      if (bra_file_op_item_queue[bra_file_current_op].callback != NULL)
        bra_file_op_item_queue[bra_file_current_op].callback(bra_file_op_item_queue[bra_file_current_op].handle, bra_file_op_item_queue[bra_file_current_op].block, bra_file_op_item_queue[bra_file_current_op].size);
      else
        BRA_FREE (bra_file_op_item_queue[bra_file_current_op].block);
    }
    
  }

  /*Step current*/
  bra_file_current_op++;

  if (bra_file_current_op == BRA_FILE_MAX_N_PENDING_OP)
    bra_file_current_op = 0;

  if (bra_file_current_op != bra_file_last_op)
  {
    /*If there are more file ops send signal to continue*/
    BRA_SIGNAL_SENDTO(W_SIG_DST_BRA_MAIN, BRA_MAIN_SIG_CONT_FILE_TASK);
  
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_C06A247BA521224C9F581CD3A9DC4271, "BRA:Continue Signal sent.\n"));
  }
  else
  {
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_6C7940F28892C70B94D5BDC163A7C9C1, "BRA:No more pending file ops.\n"));

    bra_file_pending_op = 0;
  }
}

void
new_file_task (bra_file_handle_t *handle, int event_type, int pos, unsigned char* block, int size, bra_file_op_callback_t callback)
{
  int file_handle;
  
  /*Open file*/
  if (bra_file_pending_op == 0)
    file_handle = MSF_FILE_OPEN(MSF_MODID_BRA, handle->file, MSF_FILE_SET_CREATE | MSF_FILE_SET_RDWR | HDI_FILE_SET_CUSTOM_BLOCKING,0);
  else
    file_handle = -1; /*Do not open file if there is a pending file op.*/
  
  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_8E891A1C3637921F450857427C6373B4, "BRA: file_handle = %i\n", file_handle));
  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_B363C60FA9A3D556ED672151C9F2A4AD, "BRA: event_type = %i\n", event_type));
  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_9EE7EED9F842355E581F5B16DB6C9F12, "BRA: pos = %i\n", pos));
  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_8366797BF1B50F439ACFA6A11FE871BC, "BRA: size = %i\n", size));
  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_0671B83188332A05172A972D172291A9, "BRA: handle->file = %s\n", handle->file));

  /*Add to list of waiting selects*/
  bra_file_op_item_queue[bra_file_last_op].handle = handle;
  bra_file_op_item_queue[bra_file_last_op].file_handle = file_handle;
  bra_file_op_item_queue[bra_file_last_op].event_type  = event_type;
  bra_file_op_item_queue[bra_file_last_op].pos = pos; 
  bra_file_op_item_queue[bra_file_last_op].size = size; 
  bra_file_op_item_queue[bra_file_last_op].block = block;
  bra_file_op_item_queue[bra_file_last_op].callback   = callback;
  
  bra_file_last_op++;

  if(bra_file_last_op >= BRA_FILE_MAX_N_PENDING_OP)
    bra_file_last_op = 0;

  if (bra_file_last_op == bra_file_current_op)
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA, BRA_FILE_6F757C620692A0927E3A80E7A2FBCFF9, "BRA: ERROR, Select queue to large\n"));
  
  if (bra_file_pending_op == 0)
  {
    bra_file_pending_op = 1;
    bra_file_execute_file_task ();
  } 
}

void
parse_index (bra_file_handle_t *handle, unsigned char* block, int size)
{
  int end = size;
  msf_dcvt_t    cvt_obj;
  unsigned short  us;
  unsigned char   uc;
  bra_file_block_item_t *new_item;
  bra_file_block_item_t **list;

  handle->bytes_free = 0;
  
  msf_dcvt_init (&cvt_obj, MSF_DCVT_DECODE, block, size , 0);

  while (cvt_obj.pos < end)
  {
    if (!msf_dcvt_uint8 (&cvt_obj, &uc))
    {
      return;
    }

    if (uc == BRA_FILE_BLOCK_USED_TOKEN)
    {
      list = &handle->used_list;
    }
    else if (uc == BRA_FILE_BLOCK_NOT_USED_TOKEN)
    {
      list = &handle->free_list;      
    }
    else
      continue;

    if (!msf_dcvt_uint16 (&cvt_obj, &us))
    {
      return;
    }

    if (uc == BRA_FILE_BLOCK_NOT_USED_TOKEN)
      handle->bytes_free += us;

    new_item = BRA_ALLOCTYPE (bra_file_block_item_t);

if(new_item)/*kevin*/
{

    new_item->idx = handle->block_index++;
    new_item->start = cvt_obj.pos - BRA_FILE_BLOCK_HEADER_SIZE;
    new_item->size = us + BRA_FILE_BLOCK_HEADER_SIZE;
    new_item->next = NULL;
    add_item (list, new_item);
    
    if ((handle->callback != NULL) && (uc == BRA_FILE_BLOCK_USED_TOKEN))
    {
      handle->callback (new_item->idx, 0, (block + cvt_obj.pos), us);
    }
}

    /*Check if current possion + length of current block is larger than total block size
      (typically the case with the last block in the file)*/
    if (cvt_obj.length > cvt_obj.pos + us)
      msf_dcvt_change_pos (&cvt_obj, us);
    else
      break; /*Finished*/
  }

  if (handle->callback != NULL)
  {
    handle->callback (0, 1, NULL, 0);
  }

  BRA_FREE (block);
}

int
read_index (char* file, bra_file_handle_t *handle)
{
  unsigned char* block;
  long size;

  size = MSF_FILE_GETSIZE (file);

  if ( size <= 0)
  {
    return 0;    
  }

  handle->size = size;
  block = BRA_ALLOC (size);
  new_file_task (handle, MSF_FILE_EVENT_READ, 0, block, size, parse_index);

  return 1;
}

/***************************
 *
 *  List functions
 *
 ****************************/
/* 
 * Insert new items using insertion sort on the index to attain the effect that free blocks in 
 * the begining of the file are used first, keeping the filesize as small as possible. The list is 
 * also already sorted when the file should be defragmented
*/
static void
add_item (bra_file_block_item_t** list, bra_file_block_item_t *new_item)
{
  bra_file_block_item_t *item;
  
  item = *list;

  if (item == NULL)
  {
    /*Only one element in list*/
    *list = new_item;
    return;
  }
  else if (new_item->start < item->start)
  {
    /*Insert first*/
    new_item->next = *list;
    *list = new_item;
    return;
  }
  else
  {
    while (item->next !=  NULL)
    {
      if (new_item->start < item->next->start)
      {
        /*Insert after item*/
        new_item->next = item->next;
        item->next = new_item;
        return;
      }
      item = item->next;
    }
    /*Insert last*/
    item->next = new_item;
  }
}

static void
destroy_list (bra_file_block_item_t** list)
{
  bra_file_block_item_t *remove;

  while (*list != NULL)
  {
    remove = *list;
    *list   = (*list)->next;
    BRA_FREE (remove);
  }
}

void
commit_alloc_block (bra_file_handle_t *handle, bra_file_block_item_t  *p, unsigned char* block, int size, bra_file_op_callback_t callback);

/*
 * Functions for finding a block, which is at least of the size Size in the free list
 * and to split the block in two (one of size Size and the other of the remaining).
 * The new bolocks are put in the Free and Used lists respectively. 
 */
static void
defrag_items_response (bra_file_handle_t *handle, unsigned char* block, int size)
{
  bra_file_block_item_t *item;
  bra_file_block_item_t  *p;
  int pos = 0;
  size = size;

  item = handle->used_list;

  while (item != NULL)
  {
    if (item->start != pos)
    {
      memmove(&block[pos], &block[item->start], item->size);
      item->start = pos;
    }
    pos += item->size;
    item = item->next;
  }
  if (pos == 0)
    return;

  block[pos    ] = 0xFE;
  block[pos + 1] = (unsigned char)(((handle->bytes_free - BRA_FILE_BLOCK_HEADER_SIZE) & 0xFF00) >> 8);
  block[pos + 2] = (unsigned char)(((handle->bytes_free - BRA_FILE_BLOCK_HEADER_SIZE) & 0x00FF));

  /*Remove old file*/
  MSF_FILE_REMOVE (handle->file);

  /*Write new*/
  new_file_task (handle, MSF_FILE_EVENT_WRITE, 0, block, pos, NULL);

  /*Remove old Free list and add the new item*/
  destroy_list (&handle->free_list);
  item = BRA_ALLOCTYPE (bra_file_block_item_t);
  item->idx = 0;
  item->start = pos;
  item->size =  handle->size - pos - BRA_FILE_BLOCK_HEADER_SIZE;
  item->next = NULL;
  add_item (&handle->free_list, item);

  p = get_item_by_size (&handle->free_list, handle->defrag->size + BRA_FILE_BLOCK_HEADER_SIZE);

  if (p == NULL)
    MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_747812D92132E462A9D33D9A5DE9AA14, "BRA:ERROR: defragment failed.\n"));

  commit_alloc_block (handle, p, handle->defrag->block, handle->defrag->size, handle->defrag->callback);

  BRA_FREE (handle->defrag);
  handle->defrag = NULL;
}

static void
defragment_items (bra_file_handle_t *handle)
{
  unsigned char* block;
  int size;
  handle = handle;

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_B074871957D9FF9DCBCE187279ECC0B7, "BRA:BRA:\nDefragment.....\n"));

  size = MSF_FILE_GETSIZE (handle->file);
  
  if ( size < 0)
  {
    return;
  }

  block = BRA_ALLOC (size);
  new_file_task (handle, MSF_FILE_EVENT_READ, 0, block, size, defrag_items_response);

  return;
}


static bra_file_block_item_t*
get_item_by_size (bra_file_block_item_t** list, int size)
{
  bra_file_block_item_t *remove;
  bra_file_block_item_t *previous;

  if (list == NULL)
    return NULL;

  remove = *list;
  previous = *list;

  while (remove != NULL)
  {
    if (remove->size >= size)
    {
      if (remove == *list)
        *list = remove->next;
      else
        previous->next = remove->next;

      return remove;
    }
    previous = remove;
    remove = remove->next;
  }
  return NULL;
}

static int
alloc_block (bra_file_handle_t *handle, unsigned char* block, int size, bra_file_op_callback_t callback)
{
  bra_file_block_item_t  *p;
  int idx;
  int block_size;

  idx = handle->block_index++;
  block_size = size + BRA_FILE_BLOCK_HEADER_SIZE;

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_008F5D37DEED01F1BBB70F96B1E084FD, "BRA:BRA:Alloc Block, size = %i\n", block_size));

  if (block_size > handle->size_increment)
    return -1;

  p = get_item_by_size (&handle->free_list, block_size);

  if (p == NULL)
  {
    /*There was no free block big enough*/
    if ((handle->size >= handle->defragment_limit) && (handle->bytes_free >= block_size))
    {
      handle->defrag = BRA_ALLOCTYPE (bra_file_defragment_t);
      handle->defrag->block    = block;
      handle->defrag->idx      = idx;
      handle->defrag->callback = callback;
      handle->defrag->size     = size;
      defragment_items (handle);
      return idx;
    }
    else if ((handle->size + handle->size_increment) < handle->max_size)
    {
      p = BRA_ALLOCTYPE (bra_file_block_item_t);
      p->idx = idx;
      p->start = handle->size;
      p->size = handle->size_increment;
      p->next = NULL;
  
      handle->bytes_free += handle->size_increment;
      handle->size += handle->size_increment;     
    }
    else
    {
      MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_794D3172B896070AC1B9FE7CFF36881C, "BRA:Alloc Block, FAILED! Max size reached\n\n"));
      return -1;
    }
 }

  p->idx = idx;
  commit_alloc_block (handle, p, block, size, callback);

  return idx;
}
void
commit_alloc_block (bra_file_handle_t *handle, bra_file_block_item_t  *p, unsigned char* block, int size, bra_file_op_callback_t callback)
{
  bra_file_block_item_t  *new_item = NULL;
  unsigned char *new_block;
  msf_dcvt_t     cvt_obj;
  unsigned char  uc1;
  unsigned char  uc2;
  unsigned short us;
  unsigned short us_size;
  int            alloc_size;
  int            block_size;

  alloc_size = size + 2 * BRA_FILE_BLOCK_HEADER_SIZE;
  block_size = size + BRA_FILE_BLOCK_HEADER_SIZE;

  /*Allocate new item*/
  new_block = BRA_ALLOC (alloc_size);
  
  if (p->size > block_size + BRA_FILE_MIN_BLOCK_SIZE)
  {
    new_item = BRA_ALLOCTYPE (bra_file_block_item_t);
    new_item->idx = 0;
    new_item->start = p->start + block_size;
    new_item->size = p->size - block_size;
    new_item->next = NULL;
    add_item (&handle->free_list, new_item);
    /*Change old item*/
    p->size = block_size;
  }
  else
  {
    /*If new block is to small do not include a header int the write op*/
    alloc_size -= BRA_FILE_BLOCK_HEADER_SIZE;
  }
  p->next = NULL;
  add_item (&handle->used_list, p);

  /*Copy block, header, and a header for the new free block. Then write to file*/
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, new_block, alloc_size , 0);
  uc1 = BRA_FILE_BLOCK_USED_TOKEN;
  uc2 = BRA_FILE_BLOCK_NOT_USED_TOKEN;
  us_size = (unsigned short) size;
  if (!msf_dcvt_uint8 (&cvt_obj, &uc1 )||
      !msf_dcvt_uint16 (&cvt_obj, &us_size) ||
      !msf_dcvt_uchar_vector (&cvt_obj, size, &block)) {
      return;
  }

  if (new_item != NULL)
  {
    us = (unsigned short)(new_item->size - BRA_FILE_BLOCK_HEADER_SIZE);
    /*Write new heder for the following block*/
    if (!msf_dcvt_uint8 (&cvt_obj, &uc2 )||
        !msf_dcvt_uint16 (&cvt_obj, &us))
    {
      return;
    }
  }

  new_file_task (handle, MSF_FILE_EVENT_WRITE, p->start, new_block, alloc_size, callback);

  /*Change total free size*/
  handle->bytes_free -= block_size;

#ifdef DEBUG
print_handle (handle);
#endif

  return;
}


static bra_file_block_item_t*
get_item_by_idx (bra_file_block_item_t** list, int idx)
{
  bra_file_block_item_t *remove;
  bra_file_block_item_t *previous;

  if (*list == NULL)
    return NULL;

  remove = *list;
  previous = *list;

  while (remove != NULL)
  {
    if (remove->idx == idx)
    {
      if (remove == *list)
        *list = remove->next;
      else
        previous->next = remove->next;

      return remove;
    }
    previous = remove;
    remove = remove->next;
  }
  return NULL;

}

static bra_file_block_item_t*
get_prev_item (bra_file_handle_t *handle, int pos)
{
  bra_file_block_item_t *item;

  item = handle->free_list;

  while (item != NULL)
  {
    if ((item->start + item->size) == pos)
      return item;

    item   = item->next;
  }

  return NULL;
}

static bra_file_block_item_t*
get_next_item (bra_file_handle_t *handle, int pos)
{
  bra_file_block_item_t *remove;
  bra_file_block_item_t *previous;

  remove = handle->free_list;
  previous = remove;

  while (remove != NULL)
  {
    if (remove->start == pos)
    {
      if (remove == handle->free_list)
        handle->free_list = remove->next;
      else
        previous->next = remove->next;

      return remove;
    }
    previous = remove;
    remove = remove->next;
  }
  return NULL;
}

static bra_file_block_item_t*
get_item_by_idx2 (bra_file_block_item_t* list, int idx)
{
  bra_file_block_item_t *item;

  if (list == NULL)
    return NULL;

  item = list;

  while (item != NULL)
  {
    if (item->idx == idx)
    {
      return item;
    }
    item = item->next;
  }

  return NULL;
}

static int
dealloc_block (bra_file_handle_t *handle, int idx, bra_file_op_callback_t callback)
{
  bra_file_block_item_t *p;
  bra_file_block_item_t *t;
  int           r_value;
  int           pos;
  int           size = 0;
  unsigned char b;
  msf_dcvt_t    cvt_obj;
  unsigned char *h;
  unsigned short us_size;

  MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_HIGH, MSF_MODID_BRA,BRA_FILE_7C6F1D4B92C2B3710320677F934CFBC3, "BRA:Dealloc Block, idx = %i\n", idx));

  p = get_item_by_idx (&handle->used_list, idx);

  if (p == NULL)
  {
    /*No block is allocated with bra_file_block_index = idx*/
    return -1;
  }

  /*Remember start possition and return this if nothing else happens*/
  r_value = p->start;

  /*Change total free size*/
  handle->bytes_free += p->size;

  /*
   * Before returning block see if the block preceding or following this block is in 
   * the free list. if so, merge the blocks together
   */
  size = p->size - BRA_FILE_BLOCK_HEADER_SIZE;
  pos  = p->start;
  t = get_next_item (handle, p->start + p->size);

  if (t != NULL)
  {
    /*Merge Blocks*/
    p->size += t->size;
    size = p->size - BRA_FILE_BLOCK_HEADER_SIZE;
    BRA_FREE (t);
  }
 
  t = get_prev_item (handle, p->start);

  if (t != NULL)
  {
    /*Merge Blocks*/
    t->size += p->size;
    size = t->size - BRA_FILE_BLOCK_HEADER_SIZE;
    pos  = t->start;
    BRA_FREE (p);
  }
  else
  {
    p->next = NULL;
      add_item (&handle->free_list, p);
  }
  
  h = BRA_ALLOC (BRA_FILE_BLOCK_HEADER_SIZE);
  msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, h, BRA_FILE_BLOCK_HEADER_SIZE , 0);
  b = BRA_FILE_BLOCK_NOT_USED_TOKEN;
  us_size = (unsigned short)size;
  if (!msf_dcvt_uint8 (&cvt_obj, &b )||
      !msf_dcvt_uint16 (&cvt_obj, &us_size))
      return 0;
  
  new_file_task (handle, MSF_FILE_EVENT_WRITE, pos, h, BRA_FILE_BLOCK_HEADER_SIZE, callback);

#ifdef DEBUG
print_handle (handle);
#endif

  return r_value;
}
/******************************************************************************************************************
  External interface functions
******************************************************************************************************************/

/*
 * This function initializes file stuff.
 *
 * Parameters:
 *
 * RETURN           : void
 */
void
bra_file_start (void)
{
  bra_file_last_op = 0;
  bra_file_current_op = 0;
  bra_file_pending_op = 0;
}

/*
 * This function initializes a db file, if no file is found a new file is created
 * with the size initial_size. If a file exist the file is read and handle is 
 * initialized. If the available bytes in a db is less than an allocate request
 * the file grows with size_increment bytes until max_size is reached. If the 
 * defrag_limit is specified to be less than max_size the file is defragmented 
 * when the file reaches this size.
 *
 * Parameters:
 *
 * file             : DB file path. folders in path must exist.
 * handle           : Pointer to handle struct. A new struct is allocated.
 * max_size         : Max file size.
 * initial_size     : The initial file size.
 * defragment_limit : The DB is defragmented when this limit is reached.
 * size_increment   : the number of bytes the file shall grow in each step.
 *
 * Note! max_size must be a multiple of size_increment.
 *
 * RETURN           : void
 */
void
bra_file_init (char* file, 
               void **handle, 
               int max_size, 
               int initial_size, 
               int defragment_limit, 
               int size_increment,
               bra_file_init_callback_t callback)
{
  bra_file_block_item_t *new_item;
  bra_file_handle_t **p = (bra_file_handle_t **)handle;  

  *p = BRA_ALLOCTYPE (bra_file_handle_t);

  (*p)->max_size = max_size;
  (*p)->defragment_limit = defragment_limit;
  (*p)->size_increment = size_increment;
  (*p)->file      = file;
  (*p)->block_index = 0;
  (*p)->callback  = callback;
  (*p)->free_list = NULL;
  (*p)->used_list = NULL;
  (*p)->defrag    = NULL;

  if (read_index (file, *p) == 0)
  {
    /*No such file exists, initialize new*/
    (*p)->bytes_free = initial_size;
    (*p)->size = initial_size;
    new_item = BRA_ALLOCTYPE (bra_file_block_item_t);
    new_item->idx = (*p)->block_index++;
    new_item->start = 0;
    new_item->size = initial_size;
    new_item->next = NULL;
    add_item (&(*p)->free_list, new_item);

    if (callback != NULL)
    {
      callback (0, 1, NULL, 0);
    }
  }
}

/*
 * This function closes and deallocates the resources used by the db
 * specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 *
 * RETURN           : void
 */
void
bra_file_close (void *handle) 
{
  bra_file_handle_t *p = (bra_file_handle_t *)handle;
  
  destroy_list (&(p)->free_list);
  destroy_list (&(p)->used_list);
  
  BRA_FREE (handle);

}

/*
 * This function reads a block of bytes from the DB specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 * block_index      : Index of block to read.
 * callback         : function to return the read block to.
 *
 * RETURN           : void
 */
void
bra_file_read_block (void *handle, int block_index, bra_file_op_callback_t callback)
{
  bra_file_handle_t *p = (bra_file_handle_t *)handle;
  bra_file_block_item_t  *item;
  unsigned char *block;

  item = get_item_by_idx2 (p->used_list, block_index);

  if (item == NULL)
    return;

  block = BRA_ALLOC (item->size - BRA_FILE_BLOCK_HEADER_SIZE);

  new_file_task (p, MSF_FILE_EVENT_READ ,item->start + BRA_FILE_BLOCK_HEADER_SIZE , block, item->size - BRA_FILE_BLOCK_HEADER_SIZE, callback);
}

/*
 * This function writes a block of bytes to the DB specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 * block            : Pointer to block of bytes to write to DB. 
 * size             : Size of block to write.
 * callback         : Called when the write is finished
 *
 * NOTE!: It is not allowed to allocate blocks larger than the size_increment parameter
 *
 * RETURN           : index to the written block
 */
int
bra_file_write_block (void *handle, unsigned char* block, int size, bra_file_op_callback_t callback)
{
  return alloc_block ((bra_file_handle_t *)handle, block, size, callback);
}


/*
 * This function deletes a block from the DB specified by handle.
 *
 * Parameters:
 *
 * handle           : Pointer DB handle struct.
 * index            : Index of block to be deleted.
 * callback         : Called when the delete is finished
 *
 * RETURN           : void
 */
void
bra_file_delete_block (void *handle, int block_index, bra_file_op_callback_t callback)
{
  int pos;

  if ((pos = dealloc_block((bra_file_handle_t *)handle, block_index, callback)) < 0)
   return;

}


