/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   cyberlink_dec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "med_global.h"

#if defined(__MED_MTV_MOD__) && defined(WIN32)

#include "windows.h"
#include "cyberlink_dec.h"
#include "CodecInterface.h"

static mtv_result_t cyberlink_video_dec_open(mtv_dec_t* dec, mtv_dec_config_t* config)
{
    cyberlink_video_dec_t* pthis = PTHIS(dec, cyberlink_video_dec_t, itf);
    CL_StreamInfo* info = (CL_StreamInfo*) config->private_init;
    CL_Status ret;

    ASSERT(info->codec_type == CL_VIDEO_STREAM);
    ret = vdec_format_change(info);
    if (ret == CL_OK)
    {
        pthis->opened = KAL_TRUE;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t cyberlink_video_dec_send(mtv_dec_t* dec, mtv_packet_t* au)
{
    cyberlink_video_dec_t* pthis = PTHIS(dec, cyberlink_video_dec_t, itf);
    CL_Packet pkt;
    int remaining;
    CL_Status ret;

    ASSERT(pthis->opened);

#ifdef WIN32
    {
        MSG msg;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
#endif

    /*
     * KLUDGE: CL H.264 decoder need the first 4 bytes to be H.264 start code
     * Therefore, patch the first NAL length field as start code!!!
     */
    ASSERT(au->size >= 4);
    *((kal_uint32*)au->data) = H264_START_CODE;

    pkt.data = au->data;
    pkt.pts = au->timestamp;
    pkt.size = au->size;
    pkt.stream_id = 0; /* does it really matter? */

    ret = decode_video_packet(&pkt, &remaining);

    return MTV_S_OK;
}

static mtv_result_t cyberlink_video_dec_set_param(mtv_dec_t* dec, kal_uint32 id, kal_uint32 value)
{
    cyberlink_video_dec_t* pthis = PTHIS(dec, cyberlink_video_dec_t, itf);

    ASSERT(pthis->opened);

    switch (id)
    {
    case MTV_CODEC_PARAM_VIDEO_OUTPUT:
        UNUSED(value);
        return S_OK;

    default:
        break;
    }

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_video_dec_get_param(mtv_dec_t* dec, kal_uint32 id, kal_uint32* value)
{
    cyberlink_video_dec_t* pthis = PTHIS(dec, cyberlink_video_dec_t, itf);

	ASSERT(pthis->opened);

	UNUSED(id);
	UNUSED(value);

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_video_dec_reset(mtv_dec_t* dec)
{
    cyberlink_video_dec_t* pthis = PTHIS(dec, cyberlink_video_dec_t, itf);

	ASSERT(pthis->opened);

    Reset();

    return MTV_S_OK;
}

static mtv_result_t cyberlink_video_dec_close(mtv_dec_t* dec)
{
    cyberlink_video_dec_t* pthis = PTHIS(dec, cyberlink_video_dec_t, itf);

    Reset();

    pthis->opened = KAL_FALSE;

    return MTV_S_OK;
}

mtv_result_t construct_cyberlink_video_dec(cyberlink_video_dec_t* pthis)
{
	pthis->itf.open = cyberlink_video_dec_open;
	pthis->itf.send = cyberlink_video_dec_send;
	pthis->itf.set_param = cyberlink_video_dec_set_param;
	pthis->itf.get_param = cyberlink_video_dec_get_param;
	pthis->itf.reset = cyberlink_video_dec_reset;
	pthis->itf.close = cyberlink_video_dec_close;

	return MTV_S_OK;
}

/*---------------------------------------------------------------------------*/

static mtv_result_t cyberlink_audio_dec_open(mtv_dec_t* dec, mtv_dec_config_t* config)
{
    cyberlink_audio_dec_t* pthis = PTHIS(dec, cyberlink_audio_dec_t, itf);
    CL_StreamInfo* info = (CL_StreamInfo*) config->private_init;
    CL_Status ret;

    ASSERT(info->codec_type == CL_AUDIO_STREAM);
    ret = adec_format_change(info);
    if (ret == CL_OK)
    {
        pthis->config = config;
        pthis->opened = KAL_TRUE;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t cyberlink_audio_dec_send(mtv_dec_t* dec, mtv_packet_t* au)
{
    cyberlink_audio_dec_t* pthis = PTHIS(dec, cyberlink_audio_dec_t, itf);
    CL_Packet pkt;
	int remaining;
	CL_Status ret;

    ASSERT(pthis->opened);

    pkt.data = au->data;
    pkt.pts = au->timestamp;
    pkt.size = au->size;
    pkt.stream_id = 0; /* does it really matter? */

    if (pthis->config->codec == MTV_CODEC_AAC)
    {
        kal_uint32 frame_size;

        /* verify the correctness of ADTS header */
        frame_size = ((au->data[3] & 0x03) << 11) | (au->data[4] << 3) | ((au->data[5] >> 5) & 0x7);
        ASSERT(frame_size == au->size);
    }

    ret = decode_audio_packet(&pkt, &remaining);

    return MTV_S_OK;
}

static mtv_result_t cyberlink_audio_dec_set_param(mtv_dec_t* dec, kal_uint32 id, kal_uint32 value)
{
    cyberlink_audio_dec_t* pthis = PTHIS(dec, cyberlink_audio_dec_t, itf);

	ASSERT(pthis->opened);

    switch (id)
    {
    case MTV_CODEC_PARAM_AUDIO_OUTPUT:
        UNUSED(value);
        return S_OK;

    default:
        break;
    }

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_audio_dec_get_param(mtv_dec_t* dec, kal_uint32 id, kal_uint32* value)
{
    cyberlink_audio_dec_t* pthis = PTHIS(dec, cyberlink_audio_dec_t, itf);

	ASSERT(pthis->opened);

	UNUSED(id);
	UNUSED(value);

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_audio_dec_reset(mtv_dec_t* dec)
{
	UNUSED(dec);

    return MTV_S_OK;
}

static mtv_result_t cyberlink_audio_dec_close(mtv_dec_t* dec)
{
    cyberlink_audio_dec_t* pthis = PTHIS(dec, cyberlink_audio_dec_t, itf);

    pthis->opened = KAL_FALSE;

    return MTV_S_OK;
}

mtv_result_t construct_cyberlink_audio_dec(cyberlink_audio_dec_t* pthis)
{
	pthis->itf.open = cyberlink_audio_dec_open;
	pthis->itf.send = cyberlink_audio_dec_send;
	pthis->itf.set_param = cyberlink_audio_dec_set_param;
	pthis->itf.get_param = cyberlink_audio_dec_get_param;
	pthis->itf.reset = cyberlink_audio_dec_reset;
	pthis->itf.close = cyberlink_audio_dec_close;

	return MTV_S_OK;
}

#endif /* defined(__MED_MTV_MOD__) && defined(WIN32) */