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
 *
 * Filename:
 * ---------
 *   video_dec_frame_buffer_manager.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video frame buffer management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef MP4_CODEC
#include "drv_comm.h"
#include "med_status.h"
#include "visual_comm.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "lcd_if.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#include "stack_common.h"
#include "syscomp_config.h" /*MOD_BMT*/
#include "stack_msgs.h"
#include "app_ltlcom.h"     /* Task message communiction */
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /*Timer*/
#include "app_buff_alloc.h" /*buffer*/
#include "task_config.h"    /* Task creation */
#include "stack_ltlcom.h"   /*msg_send_ext_queue.....definitions*/
#include "intrCtrl.h"
#include "video_hw.h"
#include "img_comm.h"

#ifdef DRV_MP4_V1

/* No frame buffer for mpeg4 internal operation */
/* The API provide for video player is the same as with frame buffer */

static MPEG4_FRAME_BUFFER_MODE g_mpeg4_frame_buffer_mode;
static kal_uint32 g_mpeg4_display_addr;

/* Config frame buffer mode.  
* @param frame_buffer_mode MPEG4_FRAME_BUFFER_MODE(normal and memory mode)
* @return None
*/
void mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_MODE frame_buffer_mode, kal_uint32 prev_display_addr)
{
    g_mpeg4_frame_buffer_mode = frame_buffer_mode;
}

/* Set current display frame address. 
* @param frame buffer start address
* @return None
*/
void  mpeg4_dec_set_display_frame_addr(kal_uint32 frame_addr)
{
    g_mpeg4_display_addr = frame_addr;
}

/* Get current display frame address. 
* @param None
* @return frame buffer start address
*/
kal_uint32 mpeg4_dec_get_display_frame_addr(void)
{
    return g_mpeg4_display_addr;
}

/* Get previous display frame address. 
* @param None
* @return frame buffer start address
*/
kal_uint32 mpeg4_dec_get_prev_display_frame_addr(void)
{
    /* Note that this is only supported in memory mode */
    //if(g_mpeg4_frame_buffer_mode == MPEG4_FRAME_BUFFER_NORMAL_MODE)
    //{
    //   ASSERT(0);
    //}
    
    return g_mpeg4_display_addr;
}

#else  /*!DRV_MP4_V1*/

static MPEG4_FRAME_BUFFER_CTRL_STRUCT g_mpeg4_frame_buffer_info;

static void mpeg4_dec_frame_buffer_reset(void);
static void mpeg4_dec_reduce_frame_buffer(kal_uint32 prev_display_addr);
static void mpeg4_dec_recover_frame_buffer(void);


/* Reset frame buffer and set to hardware register
* @param None
* @return None
*/
static void mpeg4_dec_frame_buffer_reset(void)
{
    //These sequence must be correct.
    kal_uint32 pdn_reg;
    kal_uint32 savedMask;

    /* default reconstrcut is index 2*/
    g_mpeg4_frame_buffer_info.rec_frame_index = 2;
    savedMask = SaveAndSetIRQMask();
    pdn_reg = DRV_Reg(DRVPDN_CON3);
    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
	
    /* Set to hardware register */
    DRV_WriteReg32(MP4_DEC_REC_ADDR,
                   g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index]);
    DRV_WriteReg32(MP4_DEC_REF_ADDR,
                   g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                               + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                                              % g_mpeg4_frame_buffer_info.max_frame_buffer_count]);
    DRV_WriteReg32(MP4_DEC_DEBLOCK_ADDR,
                   g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                               + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                              % g_mpeg4_frame_buffer_info.max_frame_buffer_count]);
    DRV_WriteReg(DRVPDN_CON3, pdn_reg);
    RestoreIRQMask(savedMask);
}


/* Init frame buffer.
* @param max_width  frame buffer width
* @param max_height  frame buffer height
* @return None
*/
void mpeg4_dec_frame_buffer_init(kal_uint16 max_width, kal_uint16 max_height)
{
    kal_uint8 index;
    kal_uint32 frame_buffer_size;
    kal_uint8 *dec_frame_buffer_memory;

#ifdef DRV_MP4_V2_ENHANCE
    /* YUV420 */
    frame_buffer_size = (max_width * max_height * 3 / 2) + 8;

    /* Get frame buffer memory */
    dec_frame_buffer_memory = (kal_uint8 *)extmem_get_buffer( frame_buffer_size * MPEG4_FRAME_BUFFER_COUNT);
    /* frame buffer must be 8 bytes aligned */
    dec_frame_buffer_memory = (kal_uint8 *)(((kal_uint32)dec_frame_buffer_memory + 8) & 0xfffffff8);
#else
    /* YUV420 */
    frame_buffer_size = max_width * max_height * 3 / 2;

    /* Get frame buffer memory */
    dec_frame_buffer_memory = (kal_uint8 *)extmem_get_buffer( frame_buffer_size * MPEG4_FRAME_BUFFER_COUNT);
#endif

    //memset(dec_frame_buffer_memory, 0, frame_buffer_size * MPEG4_FRAME_BUFFER_COUNT); // Do this will cause green-screen when full-screen TV-out mode is selected.

    /* init setting*/
    g_mpeg4_frame_buffer_info.max_frame_buffer_count = MPEG4_FRAME_BUFFER_COUNT;
    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        g_mpeg4_frame_buffer_info.frame_buffer_addr[index] = (kal_uint32)dec_frame_buffer_memory + (frame_buffer_size * index);
    }
    g_mpeg4_frame_buffer_info.frame_buffer_size = frame_buffer_size;

    /* init frame buffer setting to hardware register*/
    mpeg4_dec_frame_buffer_reset();
}


/* Init frame buffer memory as zero 
* @param None
* @return None
*/
void mpeg4_dec_frame_buffer_init_value(void)
{
    kal_uint32 index;

    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        kal_mem_set((kal_uint8 *)g_mpeg4_frame_buffer_info.frame_buffer_addr[index], 0,
                    g_mpeg4_frame_buffer_info.frame_buffer_size);
    }
}


/* Get next frame buffer setting according to current rec frame index
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
void mpeg4_dec_frame_buffer_next(MPEG4_FRAME_BUFFER_ADDR * frame_buffer)
{
    /* increment rec frame index */
    g_mpeg4_frame_buffer_info.rec_frame_index = (g_mpeg4_frame_buffer_info.rec_frame_index + 1)
                                                               % g_mpeg4_frame_buffer_info.max_frame_buffer_count;

    frame_buffer->rec_addr
        = g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index];
    frame_buffer->ref_addr
        = g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                      + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                                     % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
    frame_buffer->deblock_addr =
        g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                    + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                   % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
}


/* Get curernt frame buffer setting according to current rec frame index
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
void mpeg4_dec_frame_buffer_current(MPEG4_FRAME_BUFFER_ADDR * frame_buffer)
{
    frame_buffer->rec_addr
        = g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index];

    frame_buffer->ref_addr
        = g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                      + g_mpeg4_frame_buffer_info.max_frame_buffer_count- 1)
                                                                     % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
    frame_buffer->deblock_addr =
        g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                    + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                   % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
}


/* Get previous frame buffer setting according to current index
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
void mpeg4_dec_frame_buffer_prev(MPEG4_FRAME_BUFFER_ADDR * frame_buffer)
{
     /* decrement rec frame index */
    g_mpeg4_frame_buffer_info.rec_frame_index = (g_mpeg4_frame_buffer_info.rec_frame_index
                                                                + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                               % g_mpeg4_frame_buffer_info.max_frame_buffer_count;

    frame_buffer->rec_addr
        = g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index];
    frame_buffer->ref_addr
        = g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                      + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                                     % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
    frame_buffer->deblock_addr =
        g_mpeg4_frame_buffer_info.frame_buffer_addr[(g_mpeg4_frame_buffer_info.rec_frame_index
                                                                    + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                   % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
}


/* Sort frame buffer according to the rec_addr input
* @param rec_addr  sort according to the rec address
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
void mpeg4_dec_sort_frame_buffer(kal_uint32 rec_addr, MPEG4_FRAME_BUFFER_ADDR * frame_buffer)
{
    kal_uint8 index;
    kal_uint8 temp_index = 0;

    /* Find the reconstrcut addres maps to which frame buffer index */
    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        if (rec_addr == g_mpeg4_frame_buffer_info.frame_buffer_addr[index])
        {
            temp_index = index;
            break;
        }
    }
    /* assert when not matches to any frame buffer */
    if(temp_index>=g_mpeg4_frame_buffer_info.max_frame_buffer_count)
        EXT_ASSERT(0, temp_index, g_mpeg4_frame_buffer_info.max_frame_buffer_count, 0);

    /* constrcut according to the previous result */
    frame_buffer->rec_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[temp_index];
    frame_buffer->ref_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[(temp_index
                                                                                         + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                                                        % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
    frame_buffer->deblock_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[(temp_index
                                                                                             + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                                            % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
}


/* Sort frame buffer according to the rec_addr input, and get next frame buffer setting.
* @param rec_addr  sort according to the rec address
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
void mpeg4_dec_sort_frame_buffer_next(kal_uint32 rec_addr, MPEG4_FRAME_BUFFER_ADDR * frame_buffer)
{
    kal_uint8 index;
    kal_uint8 temp_index = 0;

    /* Find the reconstrcut addres maps to which frame buffer index */
    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        if (rec_addr == g_mpeg4_frame_buffer_info.frame_buffer_addr[index])
        {
            temp_index = index;
            break;
        }
    }
    /* assert when not matches to any frame buffer */
    if(temp_index>=g_mpeg4_frame_buffer_info.max_frame_buffer_count)
        EXT_ASSERT(0, temp_index, g_mpeg4_frame_buffer_info.max_frame_buffer_count, 0);


     /* increment rec frame index */
    temp_index = (temp_index + 1) % g_mpeg4_frame_buffer_info.max_frame_buffer_count;

    frame_buffer->rec_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[temp_index];
    frame_buffer->ref_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[(temp_index
                                                                                         + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                                                        % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
    frame_buffer->deblock_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[(temp_index
                                                                                             + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                                            % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
}


/* Sort frame buffer according to the rec_addr input, and get previous frame buffer setting.
* @param rec_addr  sort according to the rec address
* @param frame_buffer  MPEG4_FRAME_BUFFER_ADDR
* @return None
*/
void mpeg4_dec_sort_frame_buffer_prev(kal_uint32 rec_addr, MPEG4_FRAME_BUFFER_ADDR * frame_buffer)
{
    kal_uint8 index;
    kal_uint8 temp_index = 0;

    /* Find the reconstrcut addres maps to which frame buffer index */
    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        if (rec_addr == g_mpeg4_frame_buffer_info.frame_buffer_addr[index])
        {
            temp_index = index;
            break;
        }
    }
    /* assert when not matches to any frame buffer */
    if(temp_index>=g_mpeg4_frame_buffer_info.max_frame_buffer_count)
        EXT_ASSERT(0, temp_index, g_mpeg4_frame_buffer_info.max_frame_buffer_count, 0);

     /* decrement rec frame index */
    temp_index = (temp_index + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                     % g_mpeg4_frame_buffer_info.max_frame_buffer_count;

    frame_buffer->rec_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[temp_index];
    frame_buffer->ref_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[(temp_index
                                                                                         + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 1)
                                                                                        % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
    frame_buffer->deblock_addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[(temp_index
                                                                                             + g_mpeg4_frame_buffer_info.max_frame_buffer_count - 2)
                                                                                            % g_mpeg4_frame_buffer_info.max_frame_buffer_count];
}


/* Reduce one frame buffer. The reduced one is used for TV out display.
*   It is used memory display mode.
* @param None
* @return None
*/
static void mpeg4_dec_reduce_frame_buffer(kal_uint32 prev_display_addr)
{
    kal_uint8 index;
    kal_uint8 temp_index = 0;

    /* Find the reconstrcut addres maps to which frame buffer index */
    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        if (DRV_Reg32(MP4_DEC_REC_ADDR) == g_mpeg4_frame_buffer_info.frame_buffer_addr[index])
        {
            temp_index = index;
            break;
        }
    }
    /* assert when not matches to any frame buffer */
    if(temp_index>=g_mpeg4_frame_buffer_info.max_frame_buffer_count)
        EXT_ASSERT(0, temp_index, g_mpeg4_frame_buffer_info.max_frame_buffer_count, 0);
            
    if(prev_display_addr!=0)
    {
        /* copy previous addr to unused one */
        if(temp_index == 1)
        {
            kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[2],
                            (void *)prev_display_addr,
                             g_mpeg4_frame_buffer_info.frame_buffer_size); 
        }
        else
        {
            kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[1],
                            (void *)prev_display_addr,
                             g_mpeg4_frame_buffer_info.frame_buffer_size); 
        }
    }

    /* copy rec to the last and first one and set rec index to the first one */
    kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[0],
                        (void *)DRV_Reg32(MP4_DEC_REC_ADDR),
                         g_mpeg4_frame_buffer_info.frame_buffer_size);
    kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 1],
                        (void *)DRV_Reg32(MP4_DEC_REC_ADDR),
                         g_mpeg4_frame_buffer_info.frame_buffer_size);      
    g_mpeg4_frame_buffer_info.rec_frame_index = 0;                     

    /* copy previous addr to the one before the last one */
     if(prev_display_addr!=0)
    {
        if(temp_index == 1)
        {
            kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 2],
                            (void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[2],
                             g_mpeg4_frame_buffer_info.frame_buffer_size); 
        }
        else
        {
            kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 2],
                            (void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[1],
                             g_mpeg4_frame_buffer_info.frame_buffer_size); 
        }
    }
    else
    {
        kal_mem_cpy((void *)g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 2],
                        (void *)DRV_Reg32(MP4_DEC_REC_ADDR),
                         g_mpeg4_frame_buffer_info.frame_buffer_size); 
    }

    if (g_mpeg4_frame_buffer_info.max_frame_buffer_count == MPEG4_FRAME_BUFFER_COUNT)
    {   
        g_mpeg4_frame_buffer_info.max_frame_buffer_count--;
        if(g_mpeg4_frame_buffer_info.max_frame_buffer_count != (MPEG4_FRAME_BUFFER_COUNT - 1))
        	EXT_ASSERT(0, g_mpeg4_frame_buffer_info.max_frame_buffer_count, MPEG4_FRAME_BUFFER_COUNT, 0);
    }
    
    /* let next time sort frame number correct*/
    DRV_WriteReg32(MP4_DEC_REC_ADDR,
                   g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index]);
}
    
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

/* Recover one frame buffer. 
*   It is used in normal decode display mode.
* @param None
* @return None
*/
static void mpeg4_dec_recover_frame_buffer(void)
{
    if (g_mpeg4_frame_buffer_info.max_frame_buffer_count < MPEG4_FRAME_BUFFER_COUNT)
    {
        /* only need to add frame buffer count by 1. The original setting in hardware register is fit to use*/
        ASSERT(g_mpeg4_frame_buffer_info.max_frame_buffer_count == (MPEG4_FRAME_BUFFER_COUNT - 1));
        g_mpeg4_frame_buffer_info.max_frame_buffer_count++;
    }
}


/* Config frame buffer mode.  
* @param frame_buffer_mode MPEG4_FRAME_BUFFER_MODE(normal and memory mode)
* @return None
*/
void mpeg4_dec_config_frame_buffer_mode(MPEG4_FRAME_BUFFER_MODE frame_buffer_mode, kal_uint32 prev_display_addr)
{
    g_mpeg4_frame_buffer_info.frame_buffer_mode = frame_buffer_mode;
    if(g_mpeg4_frame_buffer_info.frame_buffer_mode == MPEG4_FRAME_BUFFER_NORMAL_MODE)
    {
        /* recover in normal mode */
        mpeg4_dec_recover_frame_buffer();
    }
    else
    {
        /* reduce in memory mode */
        mpeg4_dec_reduce_frame_buffer(prev_display_addr);
    }
}


/* Get current display frame address. 
* @param None
* @return frame buffer start address
*/
kal_uint32 mpeg4_dec_get_display_frame_addr(void)
{
    if(g_mpeg4_frame_buffer_info.frame_buffer_mode == MPEG4_FRAME_BUFFER_NORMAL_MODE)
    {
#ifdef DRV_MP4_V2_ENHANCE    
        return DRV_Reg32(MP4_DEC_REC_ADDR);
#else
        /* In normal mode, show deblock or reconstrcu frame buffer */
        if (DRV_Reg32(MP4_DEC_DEBLOCK_ADDR) == 0)
        {
            return DRV_Reg32(MP4_DEC_REC_ADDR);
        }
        else
        {
            return DRV_Reg32(MP4_DEC_DEBLOCK_ADDR);
        }
#endif
    }
    else
    {
        /* In memory mode, show the last frame buffer */
        /* When reduce to memory mode, the displayed frame has copied to the last frame buffer*/
        return g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 1];
    }
}


/* Get previous display frame address. 
* @param None
* @return frame buffer start address
*/
kal_uint32 mpeg4_dec_get_prev_display_frame_addr(void)
{
    /* Note that this is only supported in memory mode */
    //if(g_mpeg4_frame_buffer_info.frame_buffer_mode == MPEG4_FRAME_BUFFER_NORMAL_MODE)
    //{
    //    ASSERT(0);
    //}

    return g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 2];
}


kal_uint32 mpeg4_dec_get_ref_frame_addr(void)
{
    return DRV_Reg32(MP4_DEC_REF_ADDR);
}

#ifdef STREAM_SUPPORT
void mpeg4_dec_clear_frame_buffer(kal_int32 width, kal_int32 height)
{
    kal_int32 index;
    for (index = 0; index < g_mpeg4_frame_buffer_info.max_frame_buffer_count; index++)
    {
        ASSERT(g_mpeg4_frame_buffer_info.frame_buffer_addr[index] != 0);
        kal_mem_set((void*)g_mpeg4_frame_buffer_info.frame_buffer_addr[index], 0, width*height);
        kal_mem_set((void*)(g_mpeg4_frame_buffer_info.frame_buffer_addr[index]+width*height), 128, (width*height)>>1);
    }
    REG_IMGDMA_VIDEO_DECODE_Y_BASE_ADDR1 = g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index];
    REG_IMGDMA_VIDEO_DECODE_U_BASE_ADDR1 = g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index]+(width*height);
    REG_IMGDMA_VIDEO_DECODE_V_BASE_ADDR1 = g_mpeg4_frame_buffer_info.frame_buffer_addr[g_mpeg4_frame_buffer_info.rec_frame_index]+(width*height*5/4);
}

void mpeg4_dec_clear_last_frame(kal_int32 width, kal_int32 height)
{
    kal_uint32 addr;
	
    addr = DRV_Reg32(MP4_DEC_REC_ADDR);
    ASSERT(addr != 0);
    kal_mem_set((void*)addr, 0, width*height);
    kal_mem_set((void*)(addr+width*height), 128, (width*height)>>1);
#ifdef DRV_MP4_V2_ENHANCE      
#else    
    addr = DRV_Reg32(MP4_DEC_DEBLOCK_ADDR);
    ASSERT(addr != 0);
    kal_mem_set((void*)addr, 0, width*height);
    kal_mem_set((void*)(addr+width*height), 128, (width*height)>>1);
#endif
    addr = g_mpeg4_frame_buffer_info.frame_buffer_addr[MPEG4_FRAME_BUFFER_COUNT - 1];
    ASSERT(addr != 0);
    kal_mem_set((void*)addr, 0, width*height);
    kal_mem_set((void*)(addr+width*height), 128, (width*height)>>1);
}
#endif
#endif /*DRV_MP4_V1*/

#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
