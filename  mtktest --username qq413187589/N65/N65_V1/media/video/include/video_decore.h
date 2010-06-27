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
 *   video_decore.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video decode core definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VIDEO_DECORE_H
#define VIDEO_DECORE_H

#ifdef DRV_MP4_V1

// Allow the maximum decoded frame width, this is software definition
#define DEC_MAX_FRAME_WIDTH            176
// Allow the maximum decoded frame height, this is software definition
#define DEC_MAX_FRAME_HEIGHT           144
// Allow the maximum decoded frame width, this is chip limitation
#define CHIP_DEC_MAX_FRAME_WIDTH       352
// Allow the maximum decoded frame height, this is chip limitation
#define CHIP_DEC_MAX_FRAME_HEIGHT      288
// Maximum working memory for Mpeg4 hardware engine.
#define DEC_MAX_WORK_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)            (3*_FRAME_WIDTH*_FRAME_HEIGHT+2048+(((_FRAME_WIDTH*_FRAME_HEIGHT+255)/256)*32))
// Total HW buffer memory size
#define HW_BUFFER_REGISTER_SIZE        0x80

#else /*!DRV_MP4_V1*/

// Allow the maximum decoded frame width, this is software definition
#define DEC_MAX_FRAME_WIDTH            352 
// Allow the maximum decoded frame height, this is software definition
#define DEC_MAX_FRAME_HEIGHT           288
// Allow the maximum decoded frame width, this is chip limitation
#define CHIP_DEC_MAX_FRAME_WIDTH       640
// Allow the maximum decoded frame height, this is chip limitation
#define CHIP_DEC_MAX_FRAME_HEIGHT      480
#ifdef DRV_MP4_V2_ENHANCE
#define DEC_QS_WORK_SIZE(_FRAME_WIDTH,_FRAME_HEIGHT)               (((_FRAME_WIDTH/16)+3)>>2)*4*(_FRAME_HEIGHT/16)
#define DEC_MAX_WORK_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)            (4096+(((_FRAME_WIDTH*_FRAME_HEIGHT+255)/256)*32)+328 + DEC_QS_WORK_SIZE(_FRAME_WIDTH, _FRAME_HEIGHT))
// Total HW buffer memory size
#define HW_BUFFER_REGISTER_SIZE        0x84
#else
// Maximum working memory for Mpeg4 hardware engine.
#define DEC_MAX_WORK_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)            (4096+(((_FRAME_WIDTH*_FRAME_HEIGHT+255)/256)*32)+328)
// Total HW buffer memory size
#define HW_BUFFER_REGISTER_SIZE        0x80
#endif

#ifdef STREAM_SUPPORT
#define STREAM_MAX_FRAME_WIDTH			352
#define STREAM_MAX_FRAME_HEIGHT			288
#endif
#endif /*DRV_MP4_V1*/

/* Video decode state */
typedef enum
{
    // Unknown state
    MPEG4_DEC_STATE_UNKOWN = 0,
    // Normal state
    MPEG4_DEC_STATE_NORMAL,
    // Seek state
    MPEG4_DEC_STATE_SEEK,
    MAX_MPEG4_DEC_STATE
}MPEG4_DEC_STATE;

/* these information is obtained from bitstream parser */
typedef struct
{
    // Frame width
    kal_uint16 width;
    // Frame height
    kal_uint16 height;
    // This is an 8-bit integer used to signal the profile and level identification
    kal_uint8 version;
    // 0: intra coded(I), 01: predictive-coded (P)
    kal_uint8 vop_coding_type;
    // Used inverse quantisation type to inverse quantisation of the DCT coefficients.
    kal_uint8 quant_type;
    // '1' indicates that the macroblock data is rearranged differently, specifically, 
    // motion vector data is separated from the texture data (i.e., DCT coefficients)
    kal_uint8 data_partitioned;
    // '1' indicates that the reversible variable length tables 
    // (Table B?23, Table B?24 and Table B?25) should be used
    kal_uint8 resversible_vlc;
    // H.263 or not
    kal_uint8 H263;
    // H.263 or not
    kal_uint8 short_video_header;
    // vop_fcode_forward, values from 1 to 7; the value of zero is forbidden. 
    // It is used in decoding of motion vectors.
    kal_uint8 fcode;
    // Signals the value of the parameter rounding_control used for pixel 
    // value interpolation in motion compensation for P-VOPs. 
    kal_uint8 rounding_code;
    // Specify the absolute value of quantiser scale to be used for inverse quantising the
    // macroblock until updated by any subsequent dquant, dbquant, or quant_scale.
    kal_uint8 vop_quant;
    // The value of this internal flag is set to 1 when the values of intra_dc_thr 
    // and the DCT quantiser indicate the usage of the intra DC VLCs as shown in Table 6?21.
    // Otherwise, the value of this flag is set to 0.
    kal_uint8 intra_dc_vlc_thr;
    // vop_time_increment_resolution, indicates the number of evenly spaced subintervals, 
    // called ticks, within one modulo time. One modulo time represents the fixed interval 
    // of one second. The value zero is forbidden.
    kal_uint16 time_increment_resolution;
    // This value represents the absolute vop_time_increment from the 
    // synchronization point marked by the modulo_time_base measured 
    // in the number of clock ticks. It can take a value in the range
    // of [0,vop_time_increment_resolution)
    kal_uint16 vop_time_increment;
    // old value of vop time increment
    kal_uint16 old_vop_time_increment;	
    // when set to '0' indicates that no subsequent data exists for the VOP
    kal_uint8 vop_coded;
    // time base
    kal_uint8 time_base;
    // temp temp base
    kal_uint8 old_time_base;
    // 1' indicates that there is no resync_marker in coded VOPs
    kal_uint8 resync_marker_disable;
    // =1, may contain interlaced video. =0, are non-interlanced video.
    kal_uint8 interlaced;
    // The value of this internal flag is set to 1 when the values of intra_dc_thr 
    // and the DCT quantiser indicate the usage of the intra DC VLCs as shown in Table 6?21. 
    // Otherwise, the value of this flag is set to 0. 
    kal_uint8 use_intra_dc_vlc;
    // =log2(hdr.height * hdr.width/(16*16)) 
    kal_uint8 mblength;
    // =Log2(vop_time_increment)
    kal_uint8 time_increment_length;
    kal_bool b_fixed_vop_rate;	
    kal_uint32 fixed_vop_time_increment;	
    kal_uint32 time_increment;	

    kal_uint32 temporal_reference;
    kal_uint32 old_temporal_reference;
} m4v_dec_im;

/* The decore parameters */
typedef struct
{
    kal_uint32 *hardware_register;
    kal_uint8 *working_memory;
    kal_bool b_check_reentry;

    void (*dec_callback)(kal_uint8 event);	

    /* spec related param */
    // Store the VOS data
    MP4VIDEO_VOS_STRUCT VOS_DATA;	
    
    kal_bool b_h263;	

    kal_bool b_parsed_vol;
    kal_bool b_init_refref_buffer;	
	
    // data partitioned bistream? This value will be obtained from VOS parse.
    kal_uint8 data_partitioned;
    // Support RVLC. This value will be obtained from VOS parse.
    kal_uint8 resversible_vlc;
    // Time increment value. This value will be obtained from VOS parse.
    kal_uint16 time_increment_resolution;
    // Resync marker disable?? This value will be obtain from VOS parse.
    kal_uint8 resync_marker_disable;
    // Interlanced bitstream? This value will be obtain from VOS parse.
    kal_uint8 interlaced;
    // Visual version, we only support version 1.
    // This variable is for debugging.
    kal_uint8 visual_version;	
    // is non-coded frame??
    kal_bool is_non_coded;	

    kal_uint16 width;
    kal_uint16 height;	
    kal_uint16 real_width;
    kal_uint16 real_height;	


    /* frame numbers */	
    // total frames in media file
    kal_uint32 total_frames_in_file;
    // Task prepare frame number.
    kal_uint32 prepare_frames_no;
    // Hisr decode frame number.
    kal_uint32 hdr_parse_frames_no;
    kal_uint32 seek_frame_no;
    kal_uint32 stop_frame_no;	
    // LISR decode frame number.
    kal_uint32 dec_frames_no;
    // start to recover?
    kal_bool recover_start;
    // start frame when recover
    kal_uint32 recover_start_frame;	
    kal_bool b_dec_complete;	
	
    /* control status */
    // DECODE state
    MPEG4_DEC_STATE dec_state;	
    // play speed, unit = x/100; for example play_speed = 50  
    // ==> The result speed will be(50/100 = 0.5)*normal speed.
    kal_uint16 play_speed;	
    // Video callback function, which is register by MED task.
    void (*video_dec_callback)(kal_uint8 event);	
    // skip frames, exception recover 
    kal_uint32 skip_frames;
    // total lost frames, exception recover
    kal_uint32 lost_frames;
    // prepare to recover
    kal_bool prepare_recover;
    // skip isr stutus check, exception recover
    kal_bool skip_check_isr_status;
    // Total decode error frame count in high speed
    kal_uint8 decode_error_frame_count_in_high_speed;  
    // set KAL_TRUE to send primitve to notify upper layer
    kal_bool isr_error_event_happen;
    // force disable deblock function or not
    kal_bool force_deblock_disable;
    kal_uint64 play_time;	
    kal_uint64 tmp_play_time;
    kal_bool b_dummy_isr;
    kal_bool b_dummy_end;

    /* record information*/
    // performance evaluation, lost frame information
    kal_uint32 check_error_count;  // Can not decode done during frame duration
    kal_uint32 check_data_empty_count;  // Task can't prepare the enough buffer		
    kal_bool b_check_log; // check whether to print log or not, LISR can not pront log
} MPEG4_DECODE_STRUCT;


extern MPEG4_DECODE_STRUCT *g_mpeg4_dec_info_ptr;

/* This function read the bits from <"data address"+bitcnt> to <"data address"+bitcnt+num>
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  num read bit number.
 * @return the value that it read.
 */
extern kal_int32 mpeg4_util_show_bits(kal_uint8 * data, kal_int32 bitcnt, kal_int32 num);

/* This function read the bits from <"data address"+bitcnt> to <"data address"+bitcnt+num>, and add bitcnt of num
 * @param  data start address
 * @param  bitcnt start bit count
 * @param  num read bit number.
 * @return the value that it read.
 */
extern kal_int32 mpeg4_util_get_bits(kal_uint8 * data, kal_int32 *bitcnt, kal_int32 num);

/* This function get a long word(4 bytes) from a specific address
 * @param  a input data address
 * @return a long word are casted by *a,*(a+1),*(a+2),*(a+3)
 */
extern kal_int32 mpeg4_util_show_word(kal_uint8 * a);

/* This function implement log2(arg)
 * @param  arg input data
 * @return log2(arg)
 */
extern kal_int32 mpeg4_util_log2ceil(kal_int32 arg);

/* This function decode the VOS bitstream.
 * @param  hdr bistream header information structure
 * @param  data bistream start address
 * @param  bitcnt start bit count
 * @param  max_parse_data_size maximum parse data size
 * @return the bit count that it read.
 */
extern kal_int32 mpeg4_read_header_imformation(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt, kal_uint32 max_parse_data_size);

/* This function decode the VOP bitstream.
 * @param  hdr bistream header information structure
 * @param  data   VOP start address
 * @param  bitcnt_init  start bit count 
 * @param  result Media status, which is based MEDIA_STATUS_CODE structure.
 * @return the total bit count that this function has parsed.
 */
extern kal_int32 mpeg4_read_VOP_header(m4v_dec_im * hdr, kal_uint8 * data, kal_int32 bitcnt_init, MEDIA_STATUS_CODE * result);

/* This function write HW register from HW register buffer.
 * @param None
 * @return None
 */
extern void mpeg4_decode_write_register(void);

/* This function get the max width that the decoder supports 
 * @param None
 * @return width 
 */
//extern kal_uint32 mpeg4_decode_get_max_width(void);

/* This function get the max height that the decoder supports 
 * @param None
 * @return height 
 */
//extern kal_uint32 mpeg4_decode_get_max_height(void);

/* This function will obtain current frame duration. This function is only called in driver. (internal use)
 * @param None
 * @return The duration of current frame.
 */
extern kal_uint32 mpeg4_dec_get_curr_frame_duration(void);

/* Initialize decode resource. (Include hardware working memory and frame memory )
 * @param None
 * @return None 
 */
//extern void mpeg4_decode_init(kal_uint32 max_width, kal_uint32 max_height, kal_bool work_mem_ext);

/* This function decode the first frame bitstream, and store the related info to HW register buffer.
 * @param  vos_ptr VOS start address
 * @param  is_h263 is h.263/mpeg4 bistream
 * @param  vop_ptr VOP frame start address
 * @param  frame_length VOP frame length
 * @param  init_recref_buffer    initialize REC/REF buffer or not
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
//extern MEDIA_STATUS_CODE mpeg4_decode_start(kal_uint8 * vos_ptr, kal_bool is_h263,
//                                     kal_uint8 * vop_ptr, kal_uint32 frame_length, kal_bool init_refref_buffer);

/* Prepare decoder HW control signal
 * @param  frame_addr input vop address(input)
 * @param  frame_length input frame length(input)
 * @param  prev_frame_duration the previous frame duration
 * @return Media status, which is based MEDIA_STATUS_CODE structure.     
 */
extern MEDIA_STATUS_CODE mpeg4_decode_main(kal_uint8 * frame_addr, kal_uint32 frame_length, kal_uint32 prev_frame_duration, kal_bool b_first);

#ifdef  __3G_VIDEO_CALL__
/* under construction !*/
#endif

#endif /*VIDEO_DECORE_H*/
