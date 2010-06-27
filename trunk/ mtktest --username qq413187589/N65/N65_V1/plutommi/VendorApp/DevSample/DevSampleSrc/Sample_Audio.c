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
 *  Sample_Audio.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for audio (mdi_audio interface)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"

#include "Gui.h"        /* UI timer */

#include "AudioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

typedef struct
{
    MDI_HANDLE aud_handle;
    S32 resource_id;

    MDI_HANDLE dummy_midi_bg;
    MDI_HANDLE wave_1_handle;
    MDI_HANDLE wave_2_handle;
    MDI_HANDLE midi_1_handle;
} mmi_sample_audio_cntx_struct;

mmi_sample_audio_cntx_struct g_sample_audio_cntx;
mmi_sample_audio_cntx_struct *sample_audio_p = &g_sample_audio_cntx;

/****************************************************************************
*
*  [Sample]
*
*  Play an audio from pre-generated resource ID. 
*  It will play for 10 sec and stopped if it is not finished.
*
*****************************************************************************/
void mmi_sample_audio_play_from_id_timeout(void);
void mmi_sample_audio_play_from_id_hdlr(MDI_RESULT res);


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_from_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_from_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: to get resource ID */

    mdi_audio_play_id(
        sample_audio_p->resource_id,            /* audio_id */
        DEVICE_AUDIO_PLAY_ONCE,                 /* play_style */
        &sample_audio_p->aud_handle,            /* handle_p */
        mmi_sample_audio_play_from_id_hdlr);    /* handler */

    gui_start_timer(10000, mmi_sample_audio_play_from_id_timeout);      /* 10 sec */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_from_id_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_from_id_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if audio is still playing, stop audio after 10 sec */
    mdi_audio_stop_id(sample_audio_p->resource_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_from_id_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_from_id_hdlr(MDI_RESULT res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res == MDI_AUDIO_END_OF_FILE)
    {
        /* play finished */
    }
    else if (res == MDI_AUDIO_TERMINATED)
    {
        /* teminate by other audio playing */
    }
    else
    {
        /* failed case */

    }
}

/****************************************************************************
*
*  [Sample]
*
*  Play an audio from string (raw data - data must align to 2 byte boundry)
*  with audio datapath defined.
*  It will play for 10 sec and stopped if it is not finished.
*
*****************************************************************************/
void mmi_sample_audio_play_from_string_timeout(void);
void mmi_sample_audio_play_from_string_hdlr(MDI_RESULT res);


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_from_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_from_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *audio_data = NULL;
    U32 audio_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: to get audio data and audio len */

    mdi_audio_play_string_with_vol_path(
        audio_data,                             /* audio_data */
        audio_len,                              /* len */
        MDI_FORMAT_WAV,                         /* format */
        DEVICE_AUDIO_PLAY_ONCE,                 /* play_style */
        &sample_audio_p->aud_handle,            /* handle_p */
        mmi_sample_audio_play_from_string_hdlr, /* handler */
        5,                                      /* volume */
        MDI_DEVICE_SPEAKER2);                   /* path */

    gui_start_timer(10000, mmi_sample_audio_play_from_string_timeout);  /* 10 sec */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_from_string_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_from_string_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if audio is still playing, stop audio after 10 sec */
    mdi_audio_stop_string();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_from_file_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_from_file_hdlr(MDI_RESULT res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res == MDI_AUDIO_END_OF_FILE)
    {
        /* play finished */
    }
    else if (res == MDI_AUDIO_TERMINATED)
    {
        /* teminate by other audio playing */
    }
    else
    {
        /* failed case */

    }
}

/****************************************************************************
*
*  [Sample]
*
*  MMA interface. May play multiple audio's at same time
*
*****************************************************************************/
__align(2)
     const U8 mmi_sample_dummy_bg[94] = 
     {
         0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x03, 0xC0, 0x4D, 0x54,
         0x72, 0x6B, 0x00, 0x00, 0x00, 0x48, 0x00, 0xFF, 0x02, 0x16, 0x43, 0x6F, 0x70, 0x79, 0x72, 0x69,
         0x67, 0x68, 0x74, 0x20, 0x63, 0x20, 0x32, 0x30, 0x30, 0x35, 0x20, 0x62, 0x79, 0x20, 0x43, 0x43,
         0x00, 0xFF, 0x01, 0x02, 0x43, 0x43, 0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xFF,
         0x59, 0x02, 0x00, 0x00, 0x00, 0xFF, 0x51, 0x03, 0x09, 0x27, 0xC0, 0x00, 0xC0, 0x00, 0x00, 0xB0,
         0x07, 0x00, 0x00, 0x90, 0x32, 0x01, 0x9E, 0x00, 0x32, 0x00, 0x00, 0xFF, 0x2F, 0x00
     };

void mmi_sample_audio_play_mma_replay(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_mma(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *wave_1_data = NULL;
    void *wave_2_data = NULL;
    void *midi_1_data = NULL;
    U32 wave_1_len = 0;
    U32 wave_2_len = 0;
    U32 midi_1_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: to get wave and midi's data and length */

    /* 
     * Open and play a dummy midi at backgroup. 
     * This will keep dsp wake up and will have smaller latency when play other audio
     */
    sample_audio_p->dummy_midi_bg = mdi_audio_mma_open_midi((void*)mmi_sample_dummy_bg, 94, 0, NULL);

    mdi_audio_mma_play_midi(sample_audio_p->dummy_midi_bg);

    /* open audio */
    sample_audio_p->wave_1_handle = mdi_audio_mma_open_wav(
                                        (void*)wave_1_data, /* audio_data */
                                        (U32) wave_1_len,   /* len */
                                        1,                  /* repeats */
                                        NULL);              /* handler */

    sample_audio_p->wave_2_handle = mdi_audio_mma_open_wav(
                                        (void*)wave_2_data, /* audio_data */
                                        (U32) wave_2_len,   /* len */
                                        1,                  /* repeats */
                                        NULL);              /* handler */

    sample_audio_p->midi_1_handle = mdi_audio_mma_open_midi(
                                        (void*)midi_1_data, /* audio_data */
                                        (U32) midi_1_len,   /* len */
                                        0,                  /* repeats */
                                        NULL);              /* handler */

    /* play */
    mdi_audio_mma_play_wav(sample_audio_p->wave_1_handle);
    mdi_audio_mma_play_wav(sample_audio_p->wave_2_handle);
    mdi_audio_mma_play_wav(sample_audio_p->midi_1_handle);

    gui_start_timer(10000, mmi_sample_audio_play_mma_replay);   /* 10 sec */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_stop_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_stop_mma(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop first, avoid prevois play is not finished */
    mdi_audio_mma_stop_wav(sample_audio_p->wave_1_handle);
    mdi_audio_mma_stop_wav(sample_audio_p->wave_2_handle);
    mdi_audio_mma_stop_midi(sample_audio_p->midi_1_handle);

    /* close */
    mdi_audio_mma_close_wav(sample_audio_p->wave_1_handle);
    mdi_audio_mma_close_wav(sample_audio_p->wave_2_handle);
    mdi_audio_mma_close_midi(sample_audio_p->midi_1_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_audio_play_mma_replay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_audio_play_mma_replay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop first, avoid prevois play is not finished */
    mdi_audio_mma_stop_wav(sample_audio_p->wave_1_handle);
    mdi_audio_mma_play_wav(sample_audio_p->wave_1_handle);

    mdi_audio_mma_stop_wav(sample_audio_p->wave_2_handle);
    mdi_audio_mma_stop_wav(sample_audio_p->wave_1_handle);
}

