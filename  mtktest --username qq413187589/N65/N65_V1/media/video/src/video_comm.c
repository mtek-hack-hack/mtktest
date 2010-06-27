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
 *    video_comm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines video common part API for video driver
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
#include "reg_base.h"
#include "video_hw.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#include "app_buff_alloc.h" /*buffer*/

/* video encode/ decode parameter */
VIDEO_DEC_STRUCT *g_video_dec_info_ptr;
VIDEO_ENC_STRUCT *g_video_enc_info_ptr;

VIDEO_DEC_STATUS_STRUCT g_video_dec_status;
VIDEO_ENC_STATUS_STRUCT g_video_enc_status;

VIDEO_EDITOR_STRUCT        VIDEO_EDITOR_DATA;
	
#ifdef __VIDEO_GET_YUV_DATA__
VIDEO_YUV_DATA_STRUCT      video_yuv;
#endif   /*__VIDEO_GET_YUV_DATA__*/
	
/* video debug info */
static kal_uint32 VIDEO_ERROR_LINE[MAX_VIDEO_ERROR_LINE];
static kal_uint8 VIDEO_ERROR_LINE_INDEX;
static VIDEO_DBG_STRUCT VIDEO_DBG_INFO_DATA;

///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Hardware control functions                                  //
//////////////////////////////////////////////////////////////////

 /* Mpeg4 reset function for V1 series.
 * @param None
 * @return None                                                        
 */
void mp4_reset(void)
{
    kal_uint32 savedMask;

    volatile kal_uint32 pdn_reg;

    savedMask = SaveAndSetIRQMask();
    pdn_reg = DRV_Reg(DRVPDN_CON3);
#ifdef DRV_MP4_V1
    {
        kal_uint8 index;

        //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
        *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);


        DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_ReSeT);

        for (index = 0; index < 5; index++)
            ;

        DRV_WriteReg32(MP4_CODEC_COMD, 0);
    }
#else  /*!DRV_MP4_V1*/

   ASSERT(0);
#endif /*DRV_MP4_V1*/

    DRV_WriteReg(DRVPDN_CON3, pdn_reg);
    RestoreIRQMask(savedMask);
}


 /* Mpeg4 decode reset function.
 * @param None
 * @return None                                                        
 */
void mpeg4_dec_reset(void)
{
#ifdef DRV_MP4_V1

    mp4_reset();
#else /*!DRV_MP4_V1*/

    kal_uint32 savedMask;
    volatile kal_uint32 pdn_reg;
    kal_uint8 index;
    kal_uint32 rec_addr;
    kal_uint32 ref_addr;
    kal_uint32 deblock_addr;

    rec_addr = DRV_Reg32(MP4_DEC_REC_ADDR);
    ref_addr = DRV_Reg32(MP4_DEC_REF_ADDR);
    deblock_addr = DRV_Reg32(MP4_DEC_DEBLOCK_ADDR);

    savedMask = SaveAndSetIRQMask();
    pdn_reg = DRV_Reg(DRVPDN_CON3);

    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);


    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_DEC_RST);

    for (index = 0; index < 20; index++)
        ;

    DRV_WriteReg32(MP4_CODEC_COMD, 0);

    DRV_WriteReg(DRVPDN_CON3, pdn_reg);
    RestoreIRQMask(savedMask);

    DRV_WriteReg32(MP4_DEC_REC_ADDR, rec_addr);
    DRV_WriteReg32(MP4_DEC_REF_ADDR, ref_addr);
    DRV_WriteReg32(MP4_DEC_DEBLOCK_ADDR, deblock_addr);
#endif /*DRV_MP4_V1*/

}


 /* Mpeg4 encode reset function.
 * @param None
 * @return None                                                        
 */
void mpeg4_enc_reset(void)
{
#ifdef DRV_MP4_V1

   mp4_reset();
#else /*!DRV_MP4_V1*/

    kal_uint32 savedMask;
    volatile kal_uint32 pdn_reg;
    kal_uint8 index;

    savedMask = SaveAndSetIRQMask();
    pdn_reg = DRV_Reg(DRVPDN_CON3);

    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);

    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_ENC_RST);

    for (index = 0; index < 20; index++)
        ;

    DRV_WriteReg32(MP4_CODEC_COMD, 0);

    DRV_WriteReg(DRVPDN_CON3, pdn_reg);
    RestoreIRQMask(savedMask);
#endif /*DRV_MP4_V1*/

}


 /* Mpeg4 core reset function for V2 series.
 * @param None
 * @return None                                                        
 */
void mpeg4_core_reset(void)
{
#ifdef DRV_MP4_V2
    kal_uint32 savedMask;

    volatile kal_uint32 pdn_reg;
    kal_uint8 index;

    savedMask = SaveAndSetIRQMask();
    pdn_reg = DRV_Reg(DRVPDN_CON3);

    //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
    *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);

    DRV_WriteReg32(MP4_CODEC_COMD, MP4_CODEC_COMD_CORE_RST);

    for (index = 0; index < 20; index++)
        ;

    DRV_WriteReg32(MP4_CODEC_COMD, 0);

    DRV_WriteReg(DRVPDN_CON3, pdn_reg);
    RestoreIRQMask(savedMask);
#endif /*DRV_MP4_V2*/

}
 

 /* Mpeg4 wait done function for V1 series.
 * @param None
 * @return None                                                        
 */
void mpeg4_wait_done(void)
{
#ifdef DRV_MP4_V1

    kal_uint32 prev_vlc_word;

    kal_uint32 curr_vlc_word;
    kal_uint16 index;

    prev_vlc_word = DRV_Reg32(MP4_VLC_WORD);

    for (index = 0; index < 75; index++)
    {
        kal_sleep_task(2);

        curr_vlc_word = DRV_Reg32(MP4_VLC_WORD);
        if (prev_vlc_word == curr_vlc_word)
            break;
        else
            prev_vlc_word = curr_vlc_word;
    }
#else  /*!DRV_MP4_V1*/
   ASSERT(0);
#endif /*DRV_MP4_V1*/

}


 /* Mpeg4 decode wait done function.
 * @param None
 * @return None                                                        
 */
void mpeg4_dec_wait_done(void)
{
#ifdef DRV_MP4_V1
    /*For future development*/ 
    mpeg4_wait_done();
#else /*!DRV_MP4_V1*/

    kal_uint32 prev_vlc_word;
    kal_uint32 curr_vlc_word;
    kal_uint32 vop1_value;
    kal_uint16 index;

    prev_vlc_word = DRV_Reg32(MP4_DEC_VLC_WORD);
    vop1_value = DRV_Reg32(MP4_DEC_VOP_STRUC1);	

    for (index = 0; index < 75; index++)
    {
        kal_sleep_task(2);

        curr_vlc_word = DRV_Reg32(MP4_DEC_VLC_WORD);
        if ( ((curr_vlc_word != 0) && (prev_vlc_word == curr_vlc_word) ) || (vop1_value == 0))
            break;
        else
            prev_vlc_word = curr_vlc_word;
    }
#endif /*DRV_MP4_V1*/

}


 /* Mpeg4 encode wait done function.
 * @param None
 * @return None                                                        
 */
void mpeg4_enc_wait_done(void)
{
#ifdef DRV_MP4_V1
    /*For future development*/
    mpeg4_wait_done();
#else /*!DRV_MP4_V1*/

    kal_uint32 prev_vlc_word;
    kal_uint32 curr_vlc_word;
    kal_uint16 index;

    prev_vlc_word = DRV_Reg32(MP4_ENC_VLC_WORD);

    for (index = 0; index < 75; index++)
    {
        kal_sleep_task(2);

        curr_vlc_word = DRV_Reg32(MP4_ENC_VLC_WORD);
        if ((prev_vlc_word == curr_vlc_word) && (curr_vlc_word != 0))
            break;
        else
            prev_vlc_word = curr_vlc_word;
    }
#endif /*DRV_MP4_V1*/

}


 /* Mpeg4 check hardware complete function.
 * @param None
 * @return None                                                        
 */
kal_bool mpeg4_dec_check_complete(void)
{
    if(DRV_Reg32(MP4_DEC_STS) == 1)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Timing information functions                                 //
//////////////////////////////////////////////////////////////////

 /* Get current time function. (32K resolution)
 * @param None
 * @return None                                                        
 */
kal_uint32 video_get_current_time(void)
{
    return drv_get_current_time();
}


 /* Get duration time. (32K resolution)
 * @param previous_time. The previous time get from 32K ticks
 * @param current_time. The current time get from 32K ticks
 * @return time difference. (calculate limit)                                                       
 */
kal_uint32 video_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
    return drv_get_duration_tick(previous_time, current_time);
}


/* Get duration time. (ms)
 * @param previous_time. The previous time get from 32K ticks
 * @return time difference from previous to current time. (calculate limit, and translate to ms)                                                       
 */
kal_uint32 video_get_duration_ms(kal_uint32 previous_time)
{
    return drv_get_duration_ms(previous_time);
}


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              Error and debug functions                                   //
//////////////////////////////////////////////////////////////////

/* This function will obtain the current video status.
 * @param None.
 * @return Media status, which is based MED_STATUS structure.                                                
 */
MED_STATUS VIDEO_GetLastError(void)
{
    kal_int32 result;

    if (g_video_dec_status.running != KAL_FALSE)
    {
        if (g_video_dec_status.VIDEO_STATUS != VIDEO_DEC_OK)
        {
            result = g_video_dec_status.VIDEO_STATUS;

            g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_OK;
            return result;
        }

        if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
        {
            result = g_video_dec_status.FSAL_STATUS;

            g_video_dec_status.FSAL_STATUS = FSAL_OK;
            result = (kal_int32)FSAL_GetLastError(g_video_dec_status.FSAL_ERROR_FILE);
            return result;
        }
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
            result = g_video_dec_status.PARSE_STATUS;

            g_video_dec_status.PARSE_STATUS = MP4_PARSER_OK;
            return result;
        }
    }

    if (g_video_enc_status.VIDEO_STATUS != VIDEO_ENC_OK)
    {
        result = g_video_enc_status.VIDEO_STATUS;

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_OK;
        return result;
    }

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        result = g_video_enc_status.FSAL_STATUS;

        g_video_enc_status.FSAL_STATUS = FSAL_OK;
        result = (kal_int32)FSAL_GetLastError(g_video_enc_status.FSAL_ERROR_FILE);
        return result;
    }

    if (g_video_enc_status.FS_STATUS < 0)
    {
        result = g_video_enc_status.FS_STATUS;

        g_video_enc_status.FS_STATUS = 0;
        return result;
    }

    return MED_STAT_NO_ERROR;
}


 /* Video assert debug function.
 * @param   line      file line number
 * @return  None                                         
 */
void video_assert(kal_uint32 line)
{
    VIDEO_ERROR_LINE[VIDEO_ERROR_LINE_INDEX&(MAX_VIDEO_ERROR_LINE - 1)] = line;

    VIDEO_ERROR_LINE_INDEX++;
}


 /* This function add debug trace information to memory
 * @param  index  VIDEO debug id.
 * @param  time   Time stamp.
 * @return None
 */
void video_dbg_trace(VIDEO_DBG_ID index, kal_uint32 time)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();

    {
        VIDEO_DBG_INFO_DATA.dbg_data[VIDEO_DBG_INFO_DATA.dbg_data_idx&(MAX_VISIAL_DBG_INFO_SIZE - 1)].tag = index;

        VIDEO_DBG_INFO_DATA.dbg_data[VIDEO_DBG_INFO_DATA.dbg_data_idx&(MAX_VISIAL_DBG_INFO_SIZE - 1)].time = time;
        VIDEO_DBG_INFO_DATA.dbg_data_idx++;
    }

    RestoreIRQMask(savedMask);
}
 

/* This function will obtain the debug information of video driver.
 * @param  data1  video debug information1
 * @param  data2  video debug information2
 * @param  data3  video debug information3
 * @param  data4  video debug information4
 * @param  data_index  video debug information index
 * @return None
 */
void VIDEO_DbgInfo(kal_uint32 * data1, kal_uint32 * data2, kal_uint32 * data3, kal_uint32 * data4,
                   kal_uint32 * data_index)
{
    *data1 = VIDEO_ERROR_LINE[0];

    *data2 = VIDEO_ERROR_LINE[1];
    *data3 = VIDEO_ERROR_LINE[2];
    *data4 = VIDEO_ERROR_LINE[3];
    *data_index = VIDEO_ERROR_LINE_INDEX;
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#include "reg_base.h"
#include "video_hw.h"
void mp4_reset(void)
{
#ifdef DRV_MP4_V1
   kal_uint32 savedMask;
   volatile kal_uint32 pdn_reg;
   kal_uint8 index;
   
   savedMask = SaveAndSetIRQMask();
   pdn_reg = DRV_Reg(DRVPDN_CON3);
   
   //DRV_Reg(DRVPDN_CON3) &= ~(DRVPDN_CON3_MP4|DRVPDN_CON3_DCT|DRVPDN_CON3_JPEG);
   *PDN_CLR3 = (kal_uint16)(DRVPDN_CON3_MP4 | DRVPDN_CON3_DCT | DRVPDN_CON3_JPEG);
   
   DRV_WriteReg32(MP4_CODEC_COMD,MP4_CODEC_COMD_ReSeT);
   for(index=0;index<5;index++);
   DRV_WriteReg32(MP4_CODEC_COMD,0);
   
   DRV_WriteReg(DRVPDN_CON3,pdn_reg);
   RestoreIRQMask(savedMask);
#else /*!DRV_MP4_V1*/
   ASSERT(0);
#endif   /*DRV_MP4_V1*/
}
#endif /*MP4_CODEC*/
