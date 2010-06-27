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
 * Midi.c
 *
 * Project:
 * --------
 *  MediaTeck GSM
 *
 * Description:
 * ------------
 *  This Module defines the OTA to Midi file conversion.
 *
 * Author:
 * -------
 * -------
 * -------
 *             
 *
 * HISTORY
 * -------
 * Created On 16 September 2004
*******************************************************************************/

/* --------------------  Include files ------------------------------------------------ */
#include "MMI_include.h"

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

#include "SMRTRingToneConverter.h"
#include "picmsgapitoothers.h"



static const int smrt_bpm_encoding[] = {25, 28, 31, 35, 40, 45, 50, 56, 63, 70, 80, 90, 100,
    112, 125, 140, 160, 180, 200, 225, 250, 285, 320, 355,
    400, 450, 500, 565, 635, 715, 800, 900
};

/* --------------------------------------------------------------------------------------- */

/* Start : JP for tracker Issue 178 : 20050602 */
/* -----------------------------------Start - Defines-------------------------------------- */

#define  OTA_VERSION    (0x30)
#define BYTE         (8)
#define  FOUR_BYTES     (4 * BYTE)

/* -----------------------------------End - Defines-------------------------------------- */
/* End : JP for tracker Issue 178 : 20050602 */

/* ------------ Functions ----------------------------------------------------------- */
U32 mmi_smrt_write_varlen(U32 value);
void PlayAudioMidiStream(U8 *audioBuffer, U16 length, U8 style);

/* ---------------------------------------------------------------------------------- */


/*****************************************************************************
 * FUNCTION
 *  mmi_smrt_midi_handler
 * DESCRIPTION
 *  convert OTA Data to Midi format
 *  
 *  This is the main function of SMRT
 * PARAMETERS
 *  OTAdata                 [?]         
 *  g_smrt_midiarray        [?]         
 *  Midi(?)                 [OUT]       File pointer
 *  OTA(?)                  [IN]        Data buffer
 * RETURNS
 *  TRUE : If it converts succesfully OTA to midi
 *  FALSE: If not
 *****************************************************************************/
BOOL mmi_smrt_midi_handler(U8 *OTAdata, U8 *g_smrt_midiarray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 command_length, first_command, second_command, song_type;        /* commands */
    U8 song_titlelength;        /* song title length */
    U8 *song_title;             /* pointer to song name */
    U8 song_sequence_length;    /* number of tracks */
    U8 pattern_header;          /* song pattern header */
    U8 pattern_id;              /* instruction ID */
    U8 loop_value;              /* pattern repeatation rate */
    U8 pattern_specifier;       /* number of pattern */
    U32 midi_division_index;    /* index to midi_division in Midi file */
    U32 midi_filelen_index;     /* index to file length in Midi file */

    U32 pattern_data;           /* instruction ID decoding */
    U32 tmp_count;              /* temporary counter */
    U32 temp_note_duration;     /* temporary note duration variable */
    U32 midi_division = 480;    /* default midi_tempo (delta time) */
    U32 midi_tempo;             /* midi tempo */
    U8 note_value;              /* note hex value */
    U8 note_duration;           /* note duration */
    U8 note_dur_specifier;      /* note duraion type */
    U32 div_written = 1;        /* flag to saved the tempo in header */
    U32 midi_scale = 2;         /* note scale */
    U32 midi_style = 0;         /* play style */
    U32 buffer;                 /* to be used with tempo */
    U16 file_index = 0;         /* OTA file buffer index */
    U32 midifilelength = 0;     /* length of midi file */
    U32 g_smrt_index = 0;       /* midi file pointer */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // if(mmi_pmsg_string_search((S8*)RING_TONE_MELODY_SIGNATURE,(S8*)OTAdata)>=0)  /* For format other than Smart ringtone */
    if (mmi_pmsg_string_search((S8*) "MELODY:", (S8*) OTAdata) >= 0)  /* For format other than Smart ringtone */
    {
        return FALSE;
    }

#if (0)
/* under construction !*/
#endif /* (0) */ 

    /* Start : JP for tracker Issue 178 : 20050602 */
    {
        U8 tmp = 0;

        tmp = *(OTAdata);
        if (OTA_VERSION == tmp)
        {
            file_index += FOUR_BYTES;   /* !!! Hack : Skip 32 bits.May need to skip more bytes if text is present !!! */
        }
    }
    /* End : JP for tracker Issue 178 : 20050602 */

    command_length = mmi_pmsg_get_n_bits(OTAdata, file_index, 8);       /* number of command */
    file_index += 8;

    if (command_length != 2)
    {
        return FALSE;
    }

    first_command = mmi_pmsg_get_n_bits(OTAdata, file_index, 8);        /* get div_written command */
    file_index += 8;

    if (first_command != RINGTONEPROGRAMING_COMMAND)
    {
        return FALSE;
    }

    second_command = mmi_pmsg_get_n_bits(OTAdata, file_index, 7);       /* get second command */
    file_index += 7;

    if (second_command != SOUND_COMMAND)
    {
        return FALSE;
    }

    song_type = mmi_pmsg_get_n_bits(OTAdata, file_index, 3);    /* get song type */
    file_index += 3;    /* normally it comes as basic type (01) */

    song_titlelength = mmi_pmsg_get_n_bits(OTAdata, file_index, 4);     /* get song title length */
    file_index += 4;

    if (song_titlelength)   /* if there is song name... retreive the same */
    {                       /* allocate the memory */
        song_title = (U8*) OslMalloc(sizeof(U8) * song_titlelength);
        memset(song_title, '\0', sizeof(U8) * song_titlelength);
        /* copy the song title in the array to be dumped in Midi later ON */
        for (tmp_count = 0; tmp_count < song_titlelength; tmp_count++)
        {
            *(song_title + tmp_count) = mmi_pmsg_get_n_bits(OTAdata, file_index, 8);
            file_index += 8;
        }
    }

    song_sequence_length = mmi_pmsg_get_n_bits(OTAdata, file_index, 8); /* number of songs */
    file_index += 8;

    pattern_header = mmi_pmsg_get_n_bits(OTAdata, file_index, 3);       /* nth song */
    file_index += 3;

    pattern_id = mmi_pmsg_get_n_bits(OTAdata, file_index, 2);   /* Pattern ID */
    file_index += 2;

    loop_value = mmi_pmsg_get_n_bits(OTAdata, file_index, 4);   /* Loop value */
    file_index += 4;

    pattern_specifier = mmi_pmsg_get_n_bits(OTAdata, file_index, 8);    /* number of instructions */
    file_index += 8;

    g_smrt_index = 0;   /* make index to zero to (start making the MIDI file) */
    /* Header of Midi file (4 bytes) */
    g_smrt_midiarray[g_smrt_index++] = 'M';
    g_smrt_midiarray[g_smrt_index++] = 'T';
    g_smrt_midiarray[g_smrt_index++] = 'h';
    g_smrt_midiarray[g_smrt_index++] = 'd';

    /* Length of Header (4 bytes). Note: length is always 6 bytes */
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x6;

    // Format of Midi files (2 bytes). Note: 0 - single track, 1 - multiple tracks being played 
    // simultaneously, 2 - multiple tracks played independently 
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x0; /* NOTE: default value of 0 */

    /* number of tracks (2 bytes) */
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x1;

    /* Division (2 bytes). This value represents delta time */
    midi_division_index = g_smrt_index;         /* Saved to update the delta time from tempo later ON */
    g_smrt_midiarray[g_smrt_index++] = 0x01;
    g_smrt_midiarray[g_smrt_index++] = 0xE0;    /* NOTE: loaded default value of 125 BPM.will be changed later ON */

    /* Track Header of Midi file (4 bytes) */
    g_smrt_midiarray[g_smrt_index++] = 'M';
    g_smrt_midiarray[g_smrt_index++] = 'T';
    g_smrt_midiarray[g_smrt_index++] = 'r';
    g_smrt_midiarray[g_smrt_index++] = 'k';

    /* Length of track in bytes (4 bytes) */
    midi_filelen_index = g_smrt_index;          /* saved to update later ON */
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x0;
    g_smrt_midiarray[g_smrt_index++] = 0x77;    /* default value */

    /* Write the song title. command is FF03 */
    g_smrt_midiarray[g_smrt_index++] = 0x0;                 /* event delta time */
    g_smrt_midiarray[g_smrt_index++] = 0xFF;                /* command for track title name (2 bytes) */
    g_smrt_midiarray[g_smrt_index++] = 0x03;
    g_smrt_midiarray[g_smrt_index++] = song_titlelength;    /* get the song title length */

    for (tmp_count = 0; tmp_count < song_titlelength; tmp_count++)
    {
        g_smrt_midiarray[g_smrt_index++] = *(song_title + tmp_count);   /* copy the song title name */
    }

    OslMfree(song_title);   /* deallocate the memory sustained by song title. */

    for (tmp_count = 0; tmp_count < pattern_specifier; tmp_count++)     /* get the Note, scale, style , tempo, vol variables */
    {   /* 3 bits each */
        pattern_data = mmi_pmsg_get_n_bits(OTAdata, file_index, 3);
        file_index += 3;
        switch (pattern_data)
        {

            case 0: /* pattern ID. NOTE: Ignored if it comes in between */
                break;

            case 1: /* Get Note pattern_data */
                note_value = mmi_pmsg_get_n_bits(OTAdata, file_index, 4);       /* Note Value */
                file_index += 4;
                note_duration = mmi_pmsg_get_n_bits(OTAdata, file_index, 3);    /* Note Duration */
                file_index += 3;
                note_dur_specifier = mmi_pmsg_get_n_bits(OTAdata, file_index, 2);       /* Actual tone duration */
                file_index += 2;

                /* Calculate the note duration with tempo value, default is 480 */
                switch (note_duration)
                {
                    case 0:
                        temp_note_duration = midi_division * 4;
                        break;  /* full note */

                    case 1:
                        temp_note_duration = midi_division * 2;
                        break;  /* 1/2 note */

                    case 2:
                        temp_note_duration = midi_division;
                        break;  /* 1/4 note */

                    case 3:
                        temp_note_duration = midi_division / 2;
                        break;  /* 1/8 note */

                    case 4:
                        temp_note_duration = midi_division / 4;
                        break;  /* 1/16 note */

                    case 5:
                        temp_note_duration = midi_division / 8;
                        break;  /* 1/32 note */

                    case 6: /* reserved */
                    case 7: /* reserved */

                    default:    /* default is 1/4 note */
                        temp_note_duration = midi_division;
                        break;
                }

                /* Actual Note duration considering the duration specifier */
                switch (note_dur_specifier)
                {
                    case 0: /* No special duration */
                        break;

                    case 1: /* Dotted Note */
                        temp_note_duration = (temp_note_duration * 3) / 2;
                        break;

                    case 2: /* Double dotted note */
                        temp_note_duration = (temp_note_duration * 7) / 4;
                        break;

                    case 3: /* 2/3 length */
                        temp_note_duration = (temp_note_duration * 2) / 3;
                        break;

                    default:    /* NO special duration */
                        break;
                }
                /* Command for Note ON 90 */
                g_smrt_midiarray[g_smrt_index++] = 0x00;    /* delta event time */
                g_smrt_midiarray[g_smrt_index++] = 0x90;    /* note ON */

                if (note_value == 0)    /* Note value is Pause */
                {
                    g_smrt_midiarray[g_smrt_index++] = 0x00;
                }
                else
                {   /* Have note values as per scale pattern_data. Only 4 octaves are considered */
                    switch (midi_scale)
                    {
                        case 0: /* 440 Hz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x29;
                            break;

                        case 1: /* 880 Hz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x3B;
                            break;

                        case 2: /* 1.76 KHz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x47;
                            break;

                        case 3: /* 3.52 KHz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x53;
                            break;

                        default:    /* 1.76 KHz is taken as default */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x47;
                            break;
                    }
                }
                g_smrt_midiarray[g_smrt_index++] = 0x64;    /* velocity taken as default: 64 */

                /* Note ON duration is written as per style */
                switch (midi_style)
                {
                    case 0: /* normal ON */
                    case 1:
                        /* currently not using any style as it creats problem with some sites */
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
                #endif /* 0 */ 
                    case 2:     /* Staccato style currently taken as Normal */
                        //            mmi_smrt_write_varlen(temp_note_duration);
                        //            break;
                    default:    /* Normal ON */
                        buffer = mmi_smrt_write_varlen(temp_note_duration);
                        while (1)
                        {
                            g_smrt_midiarray[g_smrt_index++] = (U8) buffer;
                            if (buffer & 0x80)
                            {
                                buffer >>= 8;
                            }
                            else
                            {
                                break;
                            }
                        }
                        break;
                }

                /* Command for Note OFF 80 */
                g_smrt_midiarray[g_smrt_index++] = 0x80;    /* note OFF */

                if (note_value == 0)    /* Pause Note */
                {
                    g_smrt_midiarray[g_smrt_index++] = 0x00;
                }
                else
                {
                    /* Have note values as per scale pattern_data. Only 4 octaves are considered */
                    switch (midi_scale)
                    {
                        case 0: /* 440 Hz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x29;
                            break;

                        case 1: /* 880 Hz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x3B;
                            break;

                        case 2: /* 1.76 KHz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x47;
                            break;

                        case 3: /* 3.52 KHz */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x53;
                            break;

                        default:    /* 1.76 KHz is taken as default */
                            g_smrt_midiarray[g_smrt_index++] = note_value + 0x47;
                            break;
                    }
                }
                g_smrt_midiarray[g_smrt_index++] = 0x64;    /* Note velocity is taken as 64 default */
                break;

            case 2: /* scale value */
                midi_scale = mmi_pmsg_get_n_bits(OTAdata, file_index, 2);
                file_index += 2;
                break;

            case 3: /* style value */
                midi_style = mmi_pmsg_get_n_bits(OTAdata, file_index, 2);
                file_index += 2;
                break;

            case 4: /* tempo */
                midi_tempo = mmi_pmsg_get_n_bits(OTAdata, file_index, 5);
                file_index += 5;
                midi_tempo = smrt_bpm_encoding[midi_tempo];
                midi_tempo = (60 * 1000000) / midi_tempo;

                g_smrt_midiarray[g_smrt_index++] = 0x00;    /* event delta time */

                g_smrt_midiarray[g_smrt_index++] = 0xFF;    /* tempo (3 bytes) */
                g_smrt_midiarray[g_smrt_index++] = 0x51;
                g_smrt_midiarray[g_smrt_index++] = 0x03;

                g_smrt_midiarray[g_smrt_index++] = (U8) ((midi_tempo & 0xFF0000) >> 16);        /* div_written 0x07; */
                g_smrt_midiarray[g_smrt_index++] = (U8) ((midi_tempo & 0x00FF00) >> 8); /* second 0x53; */
                g_smrt_midiarray[g_smrt_index++] = (U8) (midi_tempo & 0x00FF);  /* third 00 */

                midi_tempo = midi_tempo / 1000; /* calculating the midi_division */

                if (div_written)
                {   /* update the divion at the start of Midi file */
                    g_smrt_midiarray[midi_division_index++] = (U8) ((midi_tempo & 0xFF00) >> 8);
                    g_smrt_midiarray[midi_division_index] = (U8) ((midi_tempo & 0x00FF));
                    div_written = 0;
                }   /* else it is updated in between the midi file */
                break;

            case 5: /* volume value is ignored */
                file_index += 4;
                break;

            default:
                break;
        }
    }
    /* Midi file end command */
    g_smrt_midiarray[g_smrt_index++] = 0x00;    /* event delta time */
    g_smrt_midiarray[g_smrt_index++] = 0xFF;    /* End of Midi file command (3 bytes) */
    g_smrt_midiarray[g_smrt_index++] = 0x2F;
    g_smrt_midiarray[g_smrt_index] = 0x00;

    /* update the Midi file track length (4 bytes) */
    midifilelength = g_smrt_index - MIDIHEADERLENGTH;

    g_smrt_midiarray[midi_filelen_index++] = (U8) ((midifilelength & 0xFF000000) >> 24);
    g_smrt_midiarray[midi_filelen_index++] = (U8) ((midifilelength & 0x00FF0000) >> 16);
    g_smrt_midiarray[midi_filelen_index++] = (U8) ((midifilelength & 0x0000FF00) >> 8);
    g_smrt_midiarray[midi_filelen_index] = (U8) ((midifilelength & 0x000000FF));

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_smrt_write_varlen
 * DESCRIPTION
 *  convert the value in variable length as per midi format
 * PARAMETERS
 *  value           [IN]        To be converted into variable length
 *  nothing(?)      [OUT]       
 * RETURNS
 *  variable length value
 *****************************************************************************/
U32 mmi_smrt_write_varlen(U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = value & 0x7F;

    while ((value >>= 7))
    {
        buffer <<= 8;
        buffer |= ((value & 0x7F) | 0x80);
    }
    return buffer;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_smrt_midi_file_size
 * DESCRIPTION
 *  This return the total midi file size including the header.
 *  In midi file only track length is taken into consideration
 *  and not header. SO this function adds that track length + header
 *  to give complete midi file size.
 * PARAMETERS
 *  midifile        [?]         
 *  pointer(?)      [IN]        To midifile
 *  nothing(?)      [OUT]       
 * RETURNS
 *  size fo file
 *****************************************************************************/
U32 mmi_smrt_midi_file_size(U8 *midifile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* length of midi file will be from location 18 to 24. */
    U32 midiFileLength;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    midiFileLength = (midifile[MIDIFILELENGTHOFFSET] << 24);
    midiFileLength = (midiFileLength | (midifile[MIDIFILELENGTHOFFSET + 1] << 16));
    midiFileLength = (midiFileLength | (midifile[MIDIFILELENGTHOFFSET + 2] << 8));
    midiFileLength = (midiFileLength | midifile[MIDIFILELENGTHOFFSET + 3]);

    return (midiFileLength + MIDIHEADERLENGTH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_smrt_midi_track_name
 * DESCRIPTION
 *  This return pointer midi file track title.
 *  
 *  application should free this memory after computation
 * PARAMETERS
 *  midifile        [?]         
 *  pointer(?)      [IN]        To midifile
 *  nothing(?)      [OUT]       
 * RETURNS
 *  pointer to midi file track title.
 *****************************************************************************/
U8 *mmi_smrt_midi_track_name(U8 *midifile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *trackTItle = NULL;
    U8 titleLength, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    titleLength = midifile[MIDITRACKTITLEOFFSET];
    if (titleLength > 0)
    {
        trackTItle = (U8*) OslMalloc(titleLength + 1);
        memset(trackTItle, '\0', titleLength + 1);
        for (i = 0; i < titleLength; i++)
        {
            trackTItle[i] = midifile[MIDITRACKTITLEOFFSET + i];
        }
        trackTItle[++i] = '\0';
    }
    return trackTItle;
}
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
/* ---------------------end of SMRTRingToneConverter.c-------------------------------------- */

