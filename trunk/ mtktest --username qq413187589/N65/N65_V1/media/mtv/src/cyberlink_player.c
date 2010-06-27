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
 *   cyberlink_player.c
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

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "med_global.h"

#if defined(__MED_MTV_MOD__) && defined(WIN32)

#include "med_struct.h"		/* message struct */
#include "med_utility.h"

#include "cyberlink_player.h"
#include "cyberlink_dec.h"

static mtv_dec_t* cyberlink_player_create_decoder(mtv_codec_type_t codec_type)
{
    mtv_dec_t* dec = NULL;

    switch (codec_type)
    {
    case MTV_CODEC_H264:
        {
            cyberlink_video_dec_t* cl_vdec = (cyberlink_video_dec_t*) med_alloc_ext_mem(sizeof(cyberlink_video_dec_t));
            ASSERT(cl_vdec);
            construct_cyberlink_video_dec(cl_vdec);
            dec = &cl_vdec->itf;
        }
        break;

    case MTV_CODEC_MPEG4:
        break;

    case MTV_CODEC_BSAC:
    case MTV_CODEC_AAC:
    case MTV_CODEC_MUSICAM:
        {
            cyberlink_audio_dec_t* cl_adec = (cyberlink_audio_dec_t*) med_alloc_ext_mem(sizeof(cyberlink_audio_dec_t));
            ASSERT(cl_adec);
            construct_cyberlink_audio_dec(cl_adec);
            dec = &cl_adec->itf;
        }
        break;

    case MTV_CODEC_MOT:
        break;

    case MTV_CODEC_TPEG:
        break;

    case MTV_CODEC_NONE:
        /* do nothing */
        break;

    default:
        NOT_REACHED("Unsupported codec!");
        break;
    }

    return dec;
}

static mtv_result_t cyberlink_player_start(
    mtv_player_t* player,
    mtv_spi_service_info_t* info,
    media_config_audio_struct* audio_config,
    media_config_video_struct* video_config,
    mtv_player_client_t* client)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);

    mtv_result_t ret = MTV_E_FAIL;
    kal_int32 i;

    if (pthis->state != MTV_PLAYER_STATE_STOPPED) {
        return MTV_S_FALSE;
    }

    for (i = 0; i < ARRAY_SIZE(info->components); i++)
    {
        mtv_spi_component_info_t* comp = &info->components[i];
        mtv_dec_t* dec;

        if ((comp->flags & MTV_SPI_COMPONENT_PRIMARY) == 0) {
            continue; /* ignore non-primary service */
        }

        dec = cyberlink_player_create_decoder(comp->dec_config.codec);
        if (dec)
        {
            ret = dec->open(dec, &comp->dec_config);
            if (ret >= 0)
            {
                pthis->audio_dec_config = &comp->dec_config;

                if (comp->type == MTV_SPI_COMPONENT_VIDEO)
                {
                    ret = dec->set_param(dec, MTV_CODEC_PARAM_VIDEO_OUTPUT, (kal_uint32) video_config);
                    if (ret >= 0)
                    {
                        pthis->video_dec = dec;
                    }
                    else
                    {
                        dec->close(dec);
                    }
                }
                else if (comp->type == MTV_SPI_COMPONENT_AUDIO)
                {
                    ret = dec->set_param(dec, MTV_CODEC_PARAM_AUDIO_OUTPUT, (kal_uint32) audio_config);
                    if (ret >= 0)
                    {
                        pthis->audio_dec = dec;
                    }
                    else
                    {
                        dec->close(dec);
                    }
                }
                else if (comp->type == MTV_SPI_COMPONENT_DATA)
                {
                    pthis->data_dec = dec;
                }
                else
                {
                    NOT_REACHED("Unhandled component type!");
                }
            }
        }
    }

    ASSERT(pthis->video_dec || pthis->audio_dec || pthis->data_dec); /* at least one codec is set */

    pthis->client = client;
    pthis->state = MTV_PLAYER_STATE_STARTED;
    pthis->client->on_state_change(pthis->client, pthis->state);

#ifdef _DUMP_AUDIO_TIMESTAMP
    pthis->audio_packet_count = 0;
#endif

    return ret;
}

static mtv_result_t cyberlink_player_deliver_au(mtv_player_t* player, mtv_stream_type_t st, mtv_packet_t* au)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);

    ASSERT(pthis->state == MTV_PLAYER_STATE_STARTED);

    if (st == MTV_STREAM_AUDIO)
    {
#ifdef _DUMP_AUDIO_TIMESTAMP
        if (pthis->audio_packet_count++ > 0)
        {
            kal_uint32 duration = au->timestamp - pthis->last_audio_ts;
            printf("audio frame #%d, timestamp = %d, duration = %d\n", pthis->audio_packet_count, au->timestamp, duration);
        }
        else
        {
            printf("audio frame #%d, timestamp = %d\n", pthis->audio_packet_count, au->timestamp);
        }
        pthis->last_audio_ts = au->timestamp;
#endif

        ASSERT(pthis->audio_dec);
        return pthis->audio_dec->send(pthis->audio_dec, au);
    }
    else if (st == MTV_STREAM_VIDEO)
    {
        ASSERT(pthis->video_dec);
        return pthis->video_dec->send(pthis->video_dec, au);
    }
    else if (st == MTV_STREAM_DATA)
    {
        ASSERT(pthis->data_dec);
        return pthis->data_dec->send(pthis->data_dec, au);
    }

    NOT_REACHED("Unhandled stream type!");
    return MTV_E_INVALID_PARAM;
}

static mtv_result_t cyberlink_player_stop(mtv_player_t* player)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);
    mtv_result_t ret;

    if (pthis->state != MTV_PLAYER_STATE_STARTED) {
        return MTV_E_FAIL;
    }

    /*
     * KLUDGE: currently cyberlink decoder has some problem to restart again. Therefore,
     * just return and return no error.
     */
    return MTV_S_OK;

    if (pthis->audio_dec)
    {
        ret = pthis->audio_dec->close(pthis->audio_dec);
        ASSERT(ret >= 0);
        pthis->audio_dec = NULL;
    }

    if (pthis->video_dec)
    {
        ret = pthis->video_dec->close(pthis->video_dec);
        ASSERT(ret >= 0);
        pthis->video_dec = NULL;
    }

    if (pthis->data_dec)
    {
        ret = pthis->data_dec->close(pthis->data_dec);
        ASSERT(ret >= 0);
        pthis->data_dec = NULL;
    }

    pthis->state = MTV_PLAYER_STATE_STOPPED;
    pthis->client->on_state_change(pthis->client, pthis->state);

    return MTV_S_OK;
}

static mtv_result_t cyberlink_player_get_control(mtv_player_t* player, mtv_control_t control_id, void** control)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);

    if (control_id == MTV_CONTROL_VIDEO)
    {
        *control = &pthis->video_ctrl;
        return MTV_S_OK;
    }
    else if (control_id == MTV_CONTROL_VOLUME)
    {
        *control = &pthis->volume_ctrl;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_player_state_t cyberlink_player_get_state(mtv_player_t* player)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);

    return pthis->state;
}

static mtv_player_buffer_level_t cyberlink_player_get_buffer_level(mtv_player_t* player, mtv_stream_type_t st)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);

    UNUSED(st);

    return MTV_PLAYER_BUFFER_LEVEL_LOW;
}

static void cyberlink_player_destroy(mtv_player_t* player)
{
    cyberlink_player_t* pthis = PTHIS(player, cyberlink_player_t, itf);

    med_free_ext_mem((void**) &pthis);
}

static mtv_result_t cyberlink_player_set_visible(mtv_control_video_t* control, kal_bool visible)
{
	UNUSED(control);
    UNUSED(visible);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_get_visible(mtv_control_video_t* control, kal_bool* visible)
{
	UNUSED(control);
    UNUSED(visible);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_set_brightness(mtv_control_video_t* control, kal_int32 brightness)
{
	UNUSED(control);
    UNUSED(brightness);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_get_brightness(mtv_control_video_t* control, kal_int32* brightness)
{
	UNUSED(control);
    UNUSED(brightness);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_set_contrast(mtv_control_video_t* control, kal_int32 contrast)
{
	UNUSED(control);
    UNUSED(contrast);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_get_contrast(mtv_control_video_t* control, kal_int32* contrast)
{
	UNUSED(control);
    UNUSED(contrast);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_set_gamma(mtv_control_video_t* control, kal_int32 gamma)
{
	UNUSED(control);
    UNUSED(gamma);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_get_gamma(mtv_control_video_t* control, kal_int32* gamma)
{
	UNUSED(control);
    UNUSED(gamma);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_set_mute(mtv_control_volume_t* control, kal_bool mute)
{
	UNUSED(control);
    UNUSED(mute);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_get_mute(mtv_control_volume_t* control, kal_bool* mute)
{
	UNUSED(control);
    UNUSED(mute);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_set_level(mtv_control_volume_t* control, kal_int32 level)
{
	UNUSED(control);
    UNUSED(level);
    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t cyberlink_player_get_level(mtv_control_volume_t* control, kal_int32* level)
{
	UNUSED(control);
    UNUSED(level);
    return MTV_E_NOT_IMPLEMENTED;
}

mtv_player_t* construct_cyberlink_player()
{
    cyberlink_player_t* pthis = (cyberlink_player_t*) med_alloc_ext_mem(sizeof(cyberlink_player_t));
    ASSERT(pthis != NULL);

    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->itf.start = cyberlink_player_start;
    pthis->itf.get_control = cyberlink_player_get_control;
    pthis->itf.deliver_au = cyberlink_player_deliver_au;
    pthis->itf.get_state = cyberlink_player_get_state;
    pthis->itf.get_buffer_level = cyberlink_player_get_buffer_level;
    pthis->itf.stop = cyberlink_player_stop;
    pthis->itf.destroy = cyberlink_player_destroy;

    pthis->video_ctrl.set_visible = cyberlink_player_set_visible;
    pthis->video_ctrl.get_visible = cyberlink_player_get_visible;
    pthis->video_ctrl.set_brightness = cyberlink_player_set_brightness;
    pthis->video_ctrl.get_brightness = cyberlink_player_get_brightness;
    pthis->video_ctrl.set_contrast = cyberlink_player_set_contrast;
    pthis->video_ctrl.get_contrast = cyberlink_player_get_contrast;
    pthis->video_ctrl.set_gamma = cyberlink_player_set_gamma;
    pthis->video_ctrl.get_gamma = cyberlink_player_get_gamma;

    pthis->volume_ctrl.set_mute = cyberlink_player_set_mute;
    pthis->volume_ctrl.get_mute = cyberlink_player_get_mute;
    pthis->volume_ctrl.set_level = cyberlink_player_set_level;
    pthis->volume_ctrl.get_level = cyberlink_player_get_level;

    return &pthis->itf;
}

#endif /* defined(__MED_MTV_MOD__) && defined(WIN32) */
