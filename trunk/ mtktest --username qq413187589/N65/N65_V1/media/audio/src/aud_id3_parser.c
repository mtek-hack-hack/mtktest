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
*  aud_id3_parser.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   id3 parsing process: id3v1, id3v2.2, id3v2.3, and id3v2.4 are all supported.
*   to save code size and processing time, we get only what we want from id3 tags:
*   (1) title (2) artist (3) album (4) year (5) genre
*   it's flexible to add more fields in the future when applications need more.
*   decryption, decompression are not supported so
*   if a v2 tag frame is encrpyted or compressed, we skip the single frame, and continue to parse next frame.
*   if a entire id3v2 tag is encrypted or compressed, we skip the v2 tag parsing, and continue to parse v1 tag.   
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef MED_NOT_PRESENT

#include "med_global.h"

#ifdef __RICH_AUDIO_PROFILE__

#include "aud_id3_parser.h"

/* import from other files */
extern kal_int32 mmi_chset_text_to_ucs2(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);        /* from conversions.c */
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);  /* from med_utility.c */

id3_tag_struct id3_tag;

/* id3 tag v2 frame id -- title, artist, album, genre, year */
const char *id3_tag_v2_2_frame_id_list[NUM_OF_ID3_FRAME] = { "TT2", "TP1", "TAL", "TCO", "TYE", "WCP" };
const char *id3_tag_v2_3_frame_id_list[NUM_OF_ID3_FRAME] = { "TIT2", "TPE1", "TALB", "TCON", "TYER", "TCOP" };
const char *id3_tag_v2_4_frame_id_list[NUM_OF_ID3_FRAME] = { "TIT2", "TPE1", "TALB", "TCON", "TDRC", "TCOP" };
const id3_tag_v1_field_struct id3_tag_v1_field_list[NUM_OF_ID3_FRAME] =
    { {3, 30}, {33, 30}, {63, 30}, {127, 1}, {93, 4}, {0, 0} };
const char *id3_tag_genres[] = 
{
    "Blues",
    "Classic Rock",
    "Country",
    "Dance",
    "Disco",
    "Funk",
    "Grunge",
    "Hip-Hop",
    "Jazz",
    "Metal",
    "New Age",
    "Oldies",
    "Other",
    "Pop",
    "R&B",
    "Rap",
    "Reggae",
    "Rock",
    "Techno",
    "Industrial",
    "Alternative",
    "Ska",
    "Death Metal",
    "Pranks",
    "Soundtrack",
    "Euro-Techno",
    "Ambient",
    "Trip-Hop",
    "Vocal",
    "Jazz+Funk",
    "Fusion",
    "Trance",
    "Classical",
    "Instrumental",
    "Acid",
    "House",
    "Game",
    "Sound Clip",
    "Gospel",
    "Noise",
    "Alt",
    "Bass",
    "Soul",
    "Punk",
    "Space",
    "Meditative",
    "Instrumental Pop",
    "Instrumental Rock",
    "Ethnic",
    "Gothic",
    "Darkwave",
    "Techno-Industrial",
    "Electronic",
    "Pop-Folk",
    "Eurodance",
    "Dream",
    "Southern Rock",
    "Comedy",
    "Cult",
    "Gangsta Rap",
    "Top 40",
    "Christian Rap",
    "Pop/Funk",
    "Jungle",
    "Native American",
    "Cabaret",
    "New Wave",
    "Psychedelic",
    "Rave",
    "Showtunes",
    "Trailer",
    "Lo-Fi",
    "Tribal",
    "Acid Punk",
    "Acid Jazz",
    "Polka",
    "Retro",
    "Musical",
    "Rock & Roll",
    "Hard Rock",
    "Folk",
    "Folk/Rock",
    "National Folk",
    "Swing",
    "Fast-Fusion",
    "Bebob",
    "Latin",
    "Revival",
    "Celtic",
    "Bluegrass",
    "Avantgarde",
    "Gothic Rock",
    "Progressive Rock",
    "Psychedelic Rock",
    "Symphonic Rock",
    "Slow Rock",
    "Big Band",
    "Chorus",
    "Easy Listening",
    "Acoustic",
    "Humour",
    "Speech",
    "Chanson",
    "Opera",
    "Chamber Music",
    "Sonata",
    "Symphony",
    "Booty Bass",
    "Primus",
    "Porn Groove",
    "Satire",
    "Slow Jam",
    "Club",
    "Tango",
    "Samba",
    "Folklore",
    "Ballad",
    "Power Ballad",
    "Rhythmic Soul",
    "Freestyle",
    "Duet",
    "Punk Rock",
    "Drum Solo",
    "A Cappella",
    "Euro-House",
    "Dance Hall",
    "Goa",
    "Drum & Bass",
    "Club-House",
    "Hardcore",
    "Terror",
    "Indie",
    "BritPop",
    "Negerpunk",
    "Polsk Punk",
    "Beat",
    "Christian Gangsta Rap",
    "Heavy Metal",
    "Black Metal",
    "Crossover",
    "Contemporary Christian",
    "Christian Rock",
    "Merengue",
    "Salsa",
    "Thrash Metal",
    "Anime",
    "JPop",
    "Synthpop"
};


/*****************************************************************************
 * FUNCTION
 *  id3_tag_utf16_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  byte_order      [IN]        
 *  dest            [?]         
 *  dest_size       [IN]        (>=4)
 *  src             [?]         
 *  src_size        [IN]        (>=1)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 id3_tag_utf16_to_ucs2(
            kal_uint8 byte_order,
            kal_uint8 *dest,
            kal_uint32 dest_size,
            kal_uint8 *src,
            kal_uint32 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 utf16;
    kal_uint32 dest_count = 0;
    kal_uint32 src_count = 0;   /* src_size is used to prevent from infinte loop when src data are not utf16 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (byte_order == ID3_UTF16_UNKNOWN_BYTE_ORDER)
    {
        /* check BOM */
        if (src[0] == 0xFF && src[1] == 0xFE)
        {
            byte_order = ID3_UTF16_LE;
        }
        else if (src[0] == 0xFE && src[1] == 0xFF)
        {
            byte_order = ID3_UTF16_BE;
        }
        src += 2;
        src_count += 2;
    }

    if (byte_order != ID3_UTF16_UNKNOWN_BYTE_ORDER)
    {
        dest_size -= ((dest_size % 2) + 2); /* make it a even number + null terminator */
        /* ID3_UTF16_BE = 0, ID3_UTF16_LE = 1 */
        while (dest_count < dest_size && src_count < src_size &&
               (utf16 = ((kal_uint16) src[byte_order] << 8) | ((kal_uint16) src[1 - byte_order])))
        {
            if (utf16 < 0xD800 || utf16 > 0xDFFF)
            {
                dest[dest_count] = (kal_uint8) (utf16 & 0xFF);
                dest[dest_count + 1] = (kal_uint8) (utf16 >> 8);
                dest_count += 2;
            }
            src += 2;
            src_count += 2;
        }
    }
    dest[dest_count] = 0;
    dest[dest_count + 1] = 0;
    return dest_count + 2;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [?]         UCS2 and its format is *((0-9)+)*, i.e. (12) or (123), ....etc.
 *  text_size       [IN]        (word)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 id3_tag_parse_number(kal_wchar *text, kal_uint32 text_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (val = -1; text_size != 0; text_size--, text++)
    {
        if (*text >= L'0' && *text <= L'9')
        {
            if (val < 0)    /* check if it's the first time */
            {
                val = 0;
            }
            val = val * 10 + (kal_int32) (*text - L'0');
        }
        else if (*text == L'(' || *text == L')')
        {
            if (val >= 0)
            {
                break;  /* finish */
            }
        }
    }
    return val;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_get_unsync_uint32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  size        [IN]        
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 id3_tag_get_unsync_uint32(kal_uint8 *data, kal_uint8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size > 4)   /* size should never exceed 5 */
    {
        num = *data++;
        size--;
    }
    for (; size > 0; size--)
    {
        num = (num << 7) | (*data++);
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_get_uint32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  size        [IN]        
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 id3_tag_get_uint32(kal_uint8 *data, kal_uint8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (num = 0; size > 0; size--) /* size should never exceed 4 */
    {
        num = (num << 8) | (*data++);
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  id3_text_pool_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id3_text_pool       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void id3_text_pool_init(id3_tag_text_pool_struct *id3_text_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id3_text_pool->next_p = id3_text_pool->text;
    id3_text_pool->available_words = ID3_TAG_POOL_SIZE/2;
}


/*****************************************************************************
 * FUNCTION
 *  id3_text_pool_consume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id3_text_pool       [?]         
 *  num_of_words        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void id3_text_pool_consume(id3_tag_text_pool_struct *id3_text_pool, kal_uint32 num_of_words)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id3_text_pool->next_p += num_of_words;
    id3_text_pool->available_words -= num_of_words;
}


/*****************************************************************************
 * FUNCTION
 *  id3_frame_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id3_frame       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void id3_frame_init(id3_tag_frame_struct *id3_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id3_frame->text = NULL;
    id3_frame->size = 0;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id3_tag     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void id3_tag_init(id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init frames */
    for (i = 0; i < NUM_OF_ID3_FRAME; i++)
    {
        id3_frame_init(&id3_tag->frames[i]);
    }

    /* init text_pool */
    id3_text_pool_init(&id3_tag->text_pool);
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v2_tag_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 *  id3_tag     [?]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool id3_tag_parse_v2_tag_header(kal_uint8 *data, id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 flags, version;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check id3v2 magic word -- "ID3" */
    if (!(data[0] == 'I' && data[1] == 'D' && data[2] == '3'))
    {
        return KAL_FALSE;
    }

    version = data[3];
    if (data[4] != 0)
    {
        return KAL_FALSE;
    }
    flags = data[5];

    /* init flags */
    id3_tag->v2_major_ver = version;
    id3_tag->v2_unsync = KAL_FALSE;
    id3_tag->v2_exthdr = KAL_FALSE;
    id3_tag->v2_footer = KAL_FALSE;

    switch (version)
    {
        case 4:
            if (flags & 0x0F)
            {
                return KAL_FALSE;
            }
            if (flags & 0x10)   /* check footer flag */
            {
                id3_tag->v2_footer = KAL_TRUE;
            }
        case 3:
            if (flags & 0x1F)
            {
                return KAL_FALSE;
            }
            if (flags & 0x20)   /* check extended header flag */
            {
                id3_tag->v2_exthdr = KAL_TRUE;
            }
            break;
        case 2:
            if (flags & 0x3F)
            {
                return KAL_FALSE;
            }
            if (flags & 0x40)   /* check compression flag, if it is set, ignore this tag */
            {
                return KAL_FALSE;
            }
            break;
        default:
            return KAL_FALSE;
    }
    if (flags & 0x80)   /* check unsynchronisation flag */
    {
        id3_tag->v2_unsync = KAL_TRUE;
    }

    /* get tag size */
    id3_tag->v2_size = id3_tag_get_unsync_uint32(data + 6, 4);  /* 6, 7, 8, 9 */

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_reverse_unsync_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]         
 *  size        [IN]        
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 id3_tag_reverse_unsync_process(kal_uint8 *data, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *output = data + 1;
    kal_uint8 *ptr = data;
    kal_uint8 prev_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        return 0;
    }
    for (prev_value = *ptr++, size--; size != 0; size--)
    {
        if (!(prev_value == 0xFF && *ptr == 0x00))
        {
            *output++ = *ptr;
        }
        prev_value = *ptr++;
    }

    return (kal_uint32) output - (kal_uint32) data;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v2_tag_extended_header
 * DESCRIPTION
 *  
 * IMPACT
 *  we assume id3 tag read buffer >= 14 bytes
 * PARAMETERS
 *  data                [?]         
 *  id3_tag             [?]         Kal_bool data_full_load;
 *  data_full_load      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool id3_tag_parse_v2_tag_extended_header(kal_uint8 *data, id3_tag_struct *id3_tag, kal_bool data_full_load)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 extended_header_size;
    kal_uint32 tag_size;
    kal_uint32 padding_size;
    kal_uint32 crc_data_size;
    kal_uint32 crc_data;
    kal_uint8 *crc_data_start;
    kal_uint8 flags;
    kal_bool crc_data_present;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id3_tag->v2_unsync)
    {
        tag_size = id3_tag->v2_reverse_unsync_size;
    }
    else
    {
        tag_size = id3_tag->v2_size;
    }
    switch (id3_tag->v2_major_ver)
    {
        case 4:
            extended_header_size = id3_tag_get_unsync_uint32(data, 4);  /* 0, 1, 2, 3 */
            /* check size */
            if (extended_header_size >= tag_size)
            {
                return KAL_FALSE;
            }
            if (data[4] != 0x01)    /* flag bytes must be 1 */
            {
                return KAL_FALSE;
            }
            flags = data[5];
            if (flags & 0x8F)   /* check unset flags */
            {
                return KAL_FALSE;
            }
            if (flags & 0x20)   /* check CRC data present flag */
            {
                crc_data_present = KAL_TRUE;
                if (data[6] != 0x05)    /* flag data length must be 5 */
                {
                    return KAL_FALSE;
                }
                crc_data = id3_tag_get_unsync_uint32(data + 7, 5);      /* 7, 8, 9, 10, 11 */
                crc_data_start = data + 12;
                crc_data_size = tag_size - extended_header_size;
            }
            else
            {
                crc_data_present = KAL_FALSE;
            }
            break;
        case 3:
            extended_header_size = id3_tag_get_uint32(data, 4); /* 0, 1, 2, 3 */
            if (data[5] != 0)   /* 2nd flag must be all unset */
            {
                return KAL_FALSE;
            }
            padding_size = id3_tag_get_uint32(data + 6, 4); /* 6, 7, 8, 9 */
            /* check size */
            if (extended_header_size + padding_size >= tag_size)
            {
                return KAL_FALSE;
            }
            flags = data[4];
            if (flags & 0x80)   /* check CRC data present flag */
            {
                crc_data_present = KAL_TRUE;
                crc_data = id3_tag_get_uint32(data + 10, 4);    /* 10, 11, 12, 13 */
                crc_data_start = data + 14;
                crc_data_size = tag_size - extended_header_size - padding_size;
            }
            else
            {
                crc_data_present = KAL_FALSE;
            }
            break;
        default:
            return KAL_FALSE;
    }

    if (crc_data_present && data_full_load) /* if tag is larger than our buffer size, we skip CRC check process */
    {
        if (med_crc_calculate((kal_uint8 const*)crc_data_start, crc_data_size) != crc_data)
        {
            return KAL_FALSE;
        }
    }

    /* get extended header size */
    id3_tag->v2_exthdr_size = extended_header_size;
    id3_tag->v2_crc = crc_data_present;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v2_frame_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]         
 *  size                [IN]        
 *  frame_header        [?]         
 *  id3_tag             [?]         
 * RETURNS
 *  kal_int8: PARSE_ID3_FRAME_NO_SPACE (-1) -> no space
 *  PARSE_ID3_FRAME_SUCCESS (0) -> success
 *  PARSE_ID3_FRAME_ABORT (1) -> abort
 *****************************************************************************/
kal_int8 id3_tag_parse_v2_frame_header(
            kal_uint8 *data,
            kal_int32 size,
            id3_tag_frame_header_struct *frame_header,
            id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 flags;
    kal_uint32 data_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (id3_tag->v2_major_ver)
    {
        case 4:
            if (size < 10)
            {
                return PARSE_ID3_FRAME_NO_SPACE;
            }
            memcpy(frame_header->id, data, 4);  /* 0, 1, 2, 3 */
            frame_header->size = id3_tag_get_unsync_uint32(data + 4, 4);        /* 4, 5, 6, 7 */
            frame_header->size += 10;
            data_offset = 10;

            /* get status flags */
            flags = data[8];
            if (flags & 0x80)   /* check unset flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }
            if (flags & 0x60)   /* check file and tag alter perservation flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            /* get format flags */
            flags = data[9];

            if (flags & 0xB0)   /* check unset flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            if (flags & 0x0C)   /* check compress and encrypt flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            if (flags & 0x40)   /* check group id flag */
            {
                data_offset++;
            }

            if (flags & 0x20)   /* check unsyncrhonisation flag */
            {
                frame_header->unsync = KAL_TRUE;
            }
            else
            {
                frame_header->unsync = KAL_FALSE;
            }

            if (flags & 0x01)   /* check data length indicator flag */
            {
                id3_tag_get_unsync_uint32(data + 10, 4);    /* 10, 11, 12, 13 */
                data_offset += 4;
            }
            break;

        case 3:
            if (size < 10)
            {
                return PARSE_ID3_FRAME_NO_SPACE;
            }
            memcpy(frame_header->id, data, 4);  /* 0, 1, 2, 3 */
            frame_header->size = id3_tag_get_uint32(data + 4, 4);       /* 4, 5, 6, 7 */
            frame_header->size += 10;
            data_offset = 10;

            /* get status flags */
            flags = data[8];

            if (flags & 0x1F)   /* check unset flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            if (flags & 0xC0)   /* check file and tag alter perservation flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            /* get format flags */
            flags = data[9];

            if (flags & 0x1F)   /* check unset flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            if (flags & 0xC0)   /* check compress and encrypt flags */
            {
                return PARSE_ID3_FRAME_ABORT;
            }

            if (flags & 0x20)   /* check group id flag */
            {
                data_offset++;
            }
            break;

        case 2:
            if (size < 6)
            {
                return PARSE_ID3_FRAME_NO_SPACE;
            }
            memcpy(frame_header->id, data, 3);  /* 0, 1, 2 */
            frame_header->size = id3_tag_get_uint32(data + 3, 3);       /* 3, 4, 5 */
            frame_header->size += 6;
            data_offset = 6;
            break;

        default:
            data_offset = 0;
            ASSERT(0);
    }

    if (size <= (kal_int32) data_offset)    /* check buffer size */
    {
        return PARSE_ID3_FRAME_NO_SPACE;
    }
    else if (frame_header->size <= data_offset) /* frame size */
    {
        return PARSE_ID3_FRAME_ABORT;
    }

    frame_header->data_offset = data_offset;
    frame_header->data_size = frame_header->size - data_offset;

    return PARSE_ID3_FRAME_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_match_v2_frame_id_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id          [?]         Const char* id_list[]
 *  id_list     [IN]        
 *  size        [IN]        
 * RETURNS
 *  kal_int8
 *****************************************************************************/
kal_int8 id3_tag_match_v2_frame_id_from_list(kal_uint8 *id, const char *id_list[], kal_uint8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUM_OF_ID3_FRAME; i++)
    {
        if (memcmp(id, id_list[i], size) == 0)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v2_frame_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]     
 *  frame_header        [?]     
 *  id3_tag             [?]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool id3_tag_parse_v2_frame_data(
            kal_uint8 *data,
            id3_tag_frame_header_struct *frame_header,
            id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 frame_id_index;
    kal_uint8 text_encoding;
    kal_uint8 *ptr, *src;
    kal_uint32 text_size, i, count; /* number of bytes */
    kal_uint32 max_text_size;
    kal_int32 genre_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_encoding = data[0];
    switch (id3_tag->v2_major_ver)
    {
        case 4:
            if (text_encoding > 3)
            {
                return KAL_FALSE;
            }
            frame_id_index = id3_tag_match_v2_frame_id_from_list((kal_uint8*) frame_header->id, id3_tag_v2_4_frame_id_list, 4);
            break;
        case 3:
            if (text_encoding > 1)
            {
                return KAL_FALSE;
            }
            frame_id_index = id3_tag_match_v2_frame_id_from_list((kal_uint8*) frame_header->id, id3_tag_v2_3_frame_id_list, 4);
            break;
        case 2:
            if (text_encoding > 1)
            {
                return KAL_FALSE;
            }
            frame_id_index = id3_tag_match_v2_frame_id_from_list((kal_uint8*) frame_header->id, id3_tag_v2_2_frame_id_list, 3);
            break;
        default:
            frame_id_index = -1;
            ASSERT(0);
    }

    if (frame_id_index < 0) /* quit if it's not our wanted frame */
    {
        return KAL_FALSE;
    }

    ptr = (kal_uint8*) id3_tag->text_pool.next_p;
    max_text_size = id3_tag->text_pool.available_words << 1;
    if (max_text_size < 4)
    {
        return KAL_FALSE;
    }
    /* limit each text field size */
    if (max_text_size > (ID3_TAG_POOL_SIZE>>3))
        max_text_size = (ID3_TAG_POOL_SIZE>>3);
    text_size = frame_header->data_size - 1;    /* src text size */
    src = data + 1;

    switch (text_encoding)
    {
        case ID3_FRAME_TEXT_ENCODING_ISO_8859_1:
            /* limit our dest text size if there is no null terminator in src */
            count = 2;  /* UCS2 null terminator */
            for (i = 0; src[i] && i < text_size; i++)
            {
                if (src[i] > 0x7F)
                {
                    i++;
                }
                count += 2;
            }
            if (max_text_size > count)
            {
                max_text_size = count;
            }
            text_size = (kal_uint32) mmi_chset_text_to_ucs2(ptr, max_text_size, src);
            break;
        case ID3_FRAME_TEXT_ENCODING_UTF16:
            text_size = id3_tag_utf16_to_ucs2(ID3_UTF16_UNKNOWN_BYTE_ORDER, ptr, max_text_size, src, text_size);
            break;
        case ID3_FRAME_TEXT_ENCODING_UTF16_BE:
            text_size = id3_tag_utf16_to_ucs2(ID3_UTF16_BE, ptr, max_text_size, src, text_size);
            break;
        case ID3_FRAME_TEXT_ENCODING_UTF8:
            text_size = med_util_utf8_to_ucs2(ptr, max_text_size, src, text_size);
            break;
    }

    if (text_size <= 2) /* check if more than null terminator chars */
    {
        return KAL_FALSE;
    }

    if (frame_id_index == ID3_FRAME_GENRE)
    {
        if (kal_wstrcmp((const kal_wchar*)ptr, L"RX") == 0)
        {
            if (id3_tag->text_pool.available_words >= 6)    /* check available space in pool */
            {
                kal_wstrcpy((kal_wchar*) ptr, L"Remix");
                text_size = 12; /* include UCS2 null terminator */
            }
        }
        else if (kal_wstrcmp((const kal_wchar*)ptr, L"CR") == 0)
        {
            if (id3_tag->text_pool.available_words >= 6)    /* check available space in pool */
            {
                kal_wstrcpy((kal_wchar*) ptr, L"Cover");
                text_size = 12; /* include UCS2 null terminator */
            }
        }
        else
        {
            genre_index = id3_tag_parse_number((kal_wchar*) ptr, text_size / 2);       /* get genre number (index) */
            if (genre_index >= 0 && genre_index < ID3_TAG_GENRE_NUM)    /* check if the index is valid */
            {
                ptr = (kal_uint8*) id3_tag_genres[genre_index];        /* get genre string from list */
                max_text_size = (kal_uint32) (strlen((const char*)ptr) + 1) * 2;       /* include UCS2 null terminator */
                if (max_text_size <= (id3_tag->text_pool.available_words << 1)) /* check available space in pool */
                {
                    text_size =
                        (kal_uint32) mmi_chset_text_to_ucs2(
                                        (kal_uint8*) id3_tag->text_pool.next_p,
                                        max_text_size,
                                        ptr);
                }
            }
        }
    }
    id3_tag->frames[frame_id_index].text = id3_tag->text_pool.next_p;
    id3_tag->frames[frame_id_index].size = text_size;
    id3_text_pool_consume(&id3_tag->text_pool, (text_size + 1) >> 1);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v2_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]     
 *  id3_tag             [?]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool id3_tag_parse_v2_tag(audio_input_stream_struct *input_stream, id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool data_full_load;
    kal_uint8 parse_result;
    kal_uint8 *frame_data_ptr, *ptr;
    kal_uint32 frame_size, frame_data_size;
    kal_int32 target_size, buf_size;
    kal_int32 v2_tag_size, offset;
    id3_tag_frame_header_struct frame_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audio_input_stream_read(input_stream, 10) != 10)
    {
        return KAL_FALSE;
    }
    offset = (kal_int32) input_stream->total_load;
    buf_size = (kal_int32) input_stream->buf_size;
    ptr = input_stream->buf;

    /*
     * check id3v2 magic word -- "ID3"
     * and parse header and set the following 4 fields in id3_tag:
     * (1) v2_size // not include header & footer size
     * (2) v2_unsync
     * (3) v2_exthdr
     * (4) v2_footer
     */
    if (id3_tag_parse_v2_tag_header(ptr, id3_tag))
    {
        /* check if tag size <= our read buffer size */
        if ((v2_tag_size = (kal_int32) id3_tag->v2_size) > buf_size)
        {
            data_full_load = KAL_FALSE;
            /* read partial data of the tag to read buffer */
            if (audio_input_stream_read(input_stream, buf_size) != buf_size)
            {
                return KAL_FALSE;
            }
        }
        else
        {
            data_full_load = KAL_TRUE;
            /* read the whole tag header to read buffer (not include footer) */
            if (audio_input_stream_read(input_stream, v2_tag_size) != v2_tag_size)
            {
                return KAL_FALSE;
            }
        }

        /* reverse unsynchronisation process */
        if (id3_tag->v2_unsync)
        {
            if (!data_full_load)    /* if the tag is larger than our buffer size, we can't do reverse unsync process */
            {
                return KAL_TRUE;    /* but we still return TRUE */
            }
            v2_tag_size = id3_tag->v2_reverse_unsync_size =
                (kal_int32) id3_tag_reverse_unsync_process(ptr, v2_tag_size);
        }

        /* target size (v2_tag_size) not including 10 bytes v2 tag header */
        target_size = v2_tag_size;
        if (id3_tag->v2_exthdr)
        {
            /*
             * parse extended header and set the following 2 fields in id3_tag:
             * (1) v2_exthdr_size
             * (2) v2_crc
             */
            if (!id3_tag_parse_v2_tag_extended_header(ptr, id3_tag, data_full_load))
            {
                return KAL_FALSE;
            }

            /* point to frame start position */
            offset += id3_tag->v2_exthdr_size;
            ptr += id3_tag->v2_exthdr_size;
            target_size -= id3_tag->v2_exthdr_size;
        }

        /* parse frames */
        for (frame_size = 0; target_size > 0 && ptr + 15 <= input_stream->tail &&       /* 15 is the maximal frame header size */
             (parse_result = id3_tag_parse_v2_frame_header(ptr, target_size, &frame_header, id3_tag)) != PARSE_ID3_FRAME_NO_SPACE;
             ptr += frame_size, target_size -= frame_size)
        {
            /* check if frame id is invalid or frame size too large */
            if (frame_header.id[0] == 0 || frame_header.size > (kal_uint32) target_size)
            {
                break;
            }
            offset += frame_size;   /* offset always point to frame start position */
            frame_size = frame_header.size;
            if (parse_result != PARSE_ID3_FRAME_ABORT)
            {
                // we need to check if the frame boundary is within buffer
                // otherwise, we need to skip processing the frame data & move to next frame
                if (ptr + frame_size <= input_stream->tail)
                {
                    frame_data_ptr = ptr + frame_header.data_offset;

                    /* check unsync flag & reverse unsynchronisation process in a frame */
                    if (!id3_tag->v2_unsync && frame_header.unsync)
                    {
                        frame_header.data_size = id3_tag_reverse_unsync_process(frame_data_ptr, frame_header.data_size);
                    }

                    /* parse frame data */
                    if (frame_header.data_size > 1)
                    {
                        id3_tag_parse_v2_frame_data(frame_data_ptr, &frame_header, id3_tag);
                    }
                }
            }
        }

        // when data_full_load is FALSE, we can't finish parsing it in buffer in last step
        // so we keep loading data & parse frames
        if (!data_full_load)
        {
            target_size += frame_size;
            ptr = input_stream->buf;
            do
            {
                /* seek to the frame header start position */
                audio_input_stream_seek(input_stream, offset);

                /* we assume buf is >= 15 bytes, and read 15 bytes for parsing header */
                if (audio_input_stream_read(input_stream, 15) != 15)    /* 15 is the maximal frame header size */
                {
                    break;
                }

                parse_result = id3_tag_parse_v2_frame_header(ptr, target_size, &frame_header, id3_tag);
                if (parse_result == PARSE_ID3_FRAME_NO_SPACE)
                {
                    break;
                }
                /* check if frame id is invalid or frame size too large */
                if (frame_header.id[0] == 0 || frame_header.size > (kal_uint32) target_size)
                {
                    break;
                }

                frame_data_size = frame_header.data_size;

                // if it's our wanted frame, we need to check if the frame data size <= buf_size
                // otherwise, we need to skip processing the frame data & seek to next frame
                if (parse_result != PARSE_ID3_FRAME_ABORT && (kal_int32) frame_data_size <= buf_size)
                {
                    /* seek to the frame data start position */
                    audio_input_stream_seek(input_stream, offset + frame_header.data_offset);

                    /* read data bytes */
                    if ((kal_uint32) audio_input_stream_read(input_stream, frame_data_size) != frame_data_size)
                    {
                        break;
                    }

                    /* check unsync flag & reverse unsynchronisation process in a frame */
                    if (!id3_tag->v2_unsync && frame_header.unsync)
                    {
                        frame_data_size = frame_header.data_size = id3_tag_reverse_unsync_process(ptr, frame_data_size);
                    }

                    /* parse frame data */
                    if (frame_header.data_size > 1)
                    {
                        id3_tag_parse_v2_frame_data(ptr, &frame_header, id3_tag);
                    }
                }

                frame_size = frame_header.size;
                target_size -= frame_size;
                offset += frame_size;
            } while (target_size > 0);
        }

        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v1_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]     
 *  id3_tag             [?]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool id3_tag_parse_v1_tag(audio_input_stream_struct *input_stream, id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool need_alloc_pool;
    kal_uint8 i;
    kal_uint8 *data, *ptr;
    id3_tag_frame_struct *frame_p;
    kal_uint32 len, j, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audio_input_stream_read(input_stream, 128) != 128)
    {
        return KAL_FALSE;
    }
    data = input_stream->buf;

    /*
     * check id3v1 magic word -- "TAG"
     * and parse header and set the following 5 frames in id3_tag:
     * (1) title
     * (2) artist
     * (3) album
     * (4) year
     * (5) genre
     */
    if (!(data[0] == 'T' && data[1] == 'A' && data[2] == 'G'))
    {
        return KAL_FALSE;
    }

    for (i = 0; i < NUM_OF_ID3_FRAME; i++)
    {
        frame_p = &id3_tag->frames[i];
        if (frame_p->text != NULL)  /* check if the same frame in v2 exist */
        {
            continue;
        }

        ptr = data + id3_tag_v1_field_list[i].offset;
        size = (kal_uint32) id3_tag_v1_field_list[i].size;
        
        if (0 == size)
        {
            continue;
        }

        if (i == ID3_FRAME_GENRE)
        {
            if (*ptr < ID3_TAG_GENRE_NUM)
            {
                ptr = (kal_uint8*) id3_tag_genres[*ptr];
                size = 0xFFFF;  /* we know none string length in id3_tag_genres exceed this number */
            }
            else
            {
                continue;
            }
        }
        /* measure the string len with limited size boundary */
        len = 2;    /* UCS2 null terminator */
        for (j = 0; ptr[j] && j < size; j++)
        {
            if (ptr[j] > 0x7F)
            {
                j++;
                if (j == size)  /* if it's not ASCII and it's the last char, we discard it */
                {
                    break;
                }
            }
            len += 2;
        }

        /* check previous frame data from pool. we would like to reuse memory in pool as many as possible */
        if (frame_p->text == NULL || frame_p->size < len)
        {
            /* check available space in pool */
            if (id3_tag->text_pool.available_words << 1 >= len)
            {
                /* alloc space from pool */
                frame_p->text = id3_tag->text_pool.next_p;
                need_alloc_pool = KAL_TRUE;
            }
            else
            {
                continue;
            }
        }
        else
        {
            need_alloc_pool = KAL_FALSE;
        }

        /* transalte text to UCS2 and copy to dest space */
        len = (kal_uint32) mmi_chset_text_to_ucs2((kal_uint8*) frame_p->text, len, ptr);
        frame_p->size = len;
        if (need_alloc_pool)
        {
            id3_text_pool_consume(&id3_tag->text_pool, (len + 1) >> 1);
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]     
 *  id3_tag             [?]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool id3_tag_parse(audio_input_stream_struct *input_stream, id3_tag_struct *id3_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 data_size;
    kal_bool v2_result = KAL_FALSE;
    kal_bool v1_result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init id3 tag data structure */
    id3_tag_init(id3_tag);

    audio_input_stream_seek(input_stream, 0);
    /*
     * check id3v2 magic word -- "ID3"
     * and parse & save data to frames
     */
    v2_result = id3_tag_parse_v2_tag(input_stream, id3_tag);

    if ((data_size = audio_input_stream_get_data_size(input_stream)) >= 128)
    {
        /* move to last 128 bytes before file end for checking id3v1 tag */
        audio_input_stream_seek(input_stream, data_size - 128);

        /*
         * check id3v1 magic word -- "TAG"
         * and parse & save data to frames
         */
        v1_result = id3_tag_parse_v1_tag(input_stream, id3_tag);
    }
    else
    {
        v1_result = KAL_FALSE;
    }

    return v1_result || v2_result;
}


/*****************************************************************************
 * FUNCTION
 *  id3_tag_parse_v2_tag_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 id3_tag_parse_v2_tag_size(kal_uint8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 flags, version;
    kal_bool footer = KAL_FALSE;
    kal_int32 tag_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check id3v2 magic word -- "ID3" */
    if (!(data[0] == 'I' && data[1] == 'D' && data[2] == '3'))
    {
        return -1;
    }

    version = data[3];
    if (data[4] != 0)
    {
        return -1;
    }
    flags = data[5];

    switch (version)
    {
        case 4:
            if (flags & 0x0F)   /* check unset bits */
            {
                return -1;
            }
            if (flags & 0x10)   /* check footer flag */
            {
                footer = KAL_TRUE;
            }
        case 3:
            if (flags & 0x1F)   /* check unset bits */
            {
                return -1;
            }
            break;
        case 2:
            if (flags & 0x3F)   /* check unset bits */
            {
                return -1;
            }
            break;
        default:
            return -1;
    }

    /* get tag size */
    tag_size = (kal_int32) id3_tag_get_unsync_uint32(data + 6, 4) + 10; /* 6, 7, 8, 9 */
    if (footer)
    {
        tag_size += 10;
    }

    return tag_size;
}

#endif /* __RICH_AUDIO_PROFILE__ */ 

#endif /* MED_NOT_PRESENT */ 

