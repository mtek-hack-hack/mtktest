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
 *  gdi_image_gif_codec.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI low-level font library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef GDI_IMAGE_GIF_CODEC
#error "You should define GDI_IMAGE_GIF_CODEC"
#endif 

#undef GDI_RESIZER_PUT
#undef GDI_RESIZER_PUT_PIXEL
#undef GDI_RESIZER_INCREASE_DEST

#ifndef GDI_IMAGE_GIF_USING_RESIZER
#if GDI_IMAGE_GIF_CODEC_COLOR_FORMAT == GDI_COLOR_FORMAT_8
#define GDI_RESIZER_PUT_PIXEL(COLOR)         *((U8*)GDI_RESIZER.dest) = (U8)COLOR
#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest ++
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_GIF_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_16
#define GDI_RESIZER_PUT_PIXEL(COLOR)         *((U16*)GDI_RESIZER.dest) = (U16)COLOR
#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest +=2
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_GIF_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_24
#define GDI_RESIZER_PUT_PIXEL(COLOR)                       \
         do                                                      \
         {                                                       \
            U32 *ptr = (U32*)(GDI_RESIZER.dest);                 \
            switch(((U32)ptr)&0x3)                               \
            {                                                    \
            case 0:                                              \
               *ptr = (*ptr&0xff000000)|(COLOR&0x00ffffff);      \
               break;                                            \
            case 1:                                              \
               ptr= (U32*)(((U32)ptr)&(~0x3));                   \
               *ptr = (*ptr&0x000000ff)|(COLOR<<8);              \
               break;                                            \
            case 2:                                              \
               ptr= (U32*)(((U32)ptr)&(~0x3));                   \
               *ptr = (*ptr&0x0000ffff)|(COLOR<<16); ptr++;      \
               *ptr = (*ptr&0xffffff00)|((COLOR&0x00ff0000)>>16);\
               break;                                            \
            default:                                             \
               ptr= (U32*)(((U32)ptr)&(~0x3));                   \
               *ptr = (*ptr&0x00ffffff)|(COLOR<<24); ptr++;      \
               *ptr = (*ptr&0xffff0000)|((COLOR&0x00ffff00)>>8); \
            }                                                    \
         }while(0)

#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest +=3
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_GIF_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_32
#define GDI_RESIZER_PUT_PIXEL(COLOR)         *((U32*)GDI_RESIZER.dest) = (U32)COLOR
#define GDI_RESIZER_INCREASE_DEST            GDI_RESIZER.dest +=4
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_GIF_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_MAINLCD
#define GDI_RESIZER_PUT_PIXEL(COLOR)         DRV_MAINLCD_SET_BUFFER_PIXEL((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
#define GDI_RESIZER_INCREASE_DEST
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#elif GDI_IMAGE_GIF_CODEC_COLOR_FORMAT==GDI_COLOR_FORMAT_SUBLCD
#define GDI_RESIZER_PUT_PIXEL(COLOR)         DRV_SUBLCD_SET_BUFFER_PIXEL((GDI_RESIZER.offset_dx + GDI_RESIZER.want_sx),(GDI_RESIZER.offset_dy + GDI_RESIZER.want_sy),COLOR)
#define GDI_RESIZER_INCREASE_DEST
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     GDI_NON_RESIZER_PUT_X(COLOR,WANT_DRAW)
#else 
#error "WE didn't support this color format "
#endif 

#else /* GDI_IMAGE_GIF_USING_RESIZER */ 
#define GDI_RESIZER_PUT(COLOR,WANT_DRAW)     gdi_resizer_put(COLOR,WANT_DRAW)
#endif /* GDI_IMAGE_GIF_USING_RESIZER */ 



#if defined(__MTK_TARGET__)
#ifdef GDI_IMAGE_GIF_USING_INTERRAM
#pragma arm section code = "INTERNCODE"
#endif 
#endif

/*****************************************************************************
 * FUNCTION
 *  GDI_IMAGE_GIF_CODEC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  GIF_ox                  [IN]        
 *  GIF_oy                  [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  transparent_index       [IN]        
 *  cache                   [IN]        
 *  transparent_enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline void GDI_IMAGE_GIF_CODEC(
                S32 GIF_ox,
                S32 GIF_oy,
                S32 resized_width,
                S32 resized_height,
                U16 transparent_index,
                gdi_image_gif_struct *cache,
                S32 frame_counter,
                BOOL transparent_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 src_clipx1, src_clipy1, src_clipx2, src_clipy2;
    int image_rows;
    int image_cols;
    // gdi_color gdi_gif_local_palette[256];
    BOOL is_interlace;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {

        GET_U16(src_clipx1);    /* x */
        GET_U16(src_clipy1);    /* y */

        GET_U16(image_cols);
        GET_U16(image_rows);

        src_clipx2 = src_clipx1 + image_cols - 1;
        src_clipy2 = src_clipy1 + image_rows - 1;

        // If need not to draw, still need to decode to get correct next frame position
        gdi_resizer_init(
            cache->image_width,
            cache->image_height,
            src_clipx1,
            src_clipy1,
            src_clipx2,
            src_clipy2,
            GIF_ox,
            GIF_oy,
            GIF_ox + resized_width - 1,
            GIF_oy + resized_height - 1);
        
        cache->last_frame_x1 = (S16) GDI_RESIZER.want_dx1;
        cache->last_frame_y1 = (S16) GDI_RESIZER.want_dy1;
        cache->last_frame_x2 = (S16) GDI_RESIZER.want_dx2;
        cache->last_frame_y2 = (S16) GDI_RESIZER.want_dy2;
    }
    {
        S32 n;

        GET_U8(n);
        /* W05.39 Fix n value will be changed and the interlace attribute may be incorrect */
        if (n & 0x40)
        {
            is_interlace = TRUE;
        }
        else
        {
            is_interlace = FALSE;
        }
        if (n & 0x80)
        {
            gd_color_from_rgb_func palette_color_from_rgb;
            S32 i;

            n = 1 << ((n & 0x7) + 1);

            current_palette = gdi_gif_local_palette;

            if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
            {
                palette_color_from_rgb = GDI_PALETTE_COLOR_FROM_RGB;
            }
            else
            {
                palette_color_from_rgb = gdi_act_color_from_rgb;
            }

            /* Read the local color palette */
            gdi_image_gif_palette_size = n;
            for (i = 0; i < n; i++)
            {
                U8 R, G, B;

                GET_U8(R);
                GET_U8(G);
                GET_U8(B);
                current_palette[i] = palette_color_from_rgb(0xFF, R, G, B);
                if ((gdi_act_layer_info->source_key_enable && current_palette[i] == gdi_act_layer_info->source_key)
                    || (gdi_image_gif_decoder_is_bypass_color &&
                        current_palette[i] == gdi_image_gif_decoder_bypass_color))
                {
                    current_palette[i] ^= 1;
                }
            }

            /* current layer is index color layer */
            if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
                for (i = 0; i < (S32) n; i++)
                {
                    gdi_layer_set_palette((U8) i, current_palette[i]);
                    current_palette[i] = i;
                }
        }
        else    /* use global palette */
        {
            current_palette = cache->palette;
        }
    }
    {
#define MaxStackSize  4096
#define NullCode  (~0)

        int offset, y;
        register int x;
        register unsigned char *c;
        register unsigned int datum;

        short *prefix;
        int count;
        unsigned char *packet, *pixel_stack, *suffix, *top_stack;
        unsigned int available, bits, clear, code,
            code_mask, code_size, data_size, first, end_of_information, in_code, old_code, pass;

        /* allocate decoder tables */
        {
            U8 *mem = (U8*) GDI_TREE_BUFFER;

            prefix = (short*)mem;
            mem += MaxStackSize * sizeof(*prefix);
            suffix = (unsigned char*)mem;
            mem += MaxStackSize;
            pixel_stack = (unsigned char*)mem;  /* use MaxStackSize+1  bytes; */
        }

        /* Initialize GIF data stream decoder. */

        GET_U8(data_size);
        if (data_size > 8)
        {
            MMI_TRACE(GDI_TRC, GDI_TRC_42,//"GDI_RAISE GDI_IMAGE_GIF_CODEC %d",
                                data_size);
  
            GDI_RAISE(1);   /* CorruptImage */
        }

        clear = 1 << data_size;
        end_of_information = clear + 1;
        available = clear + 2;
        old_code = NullCode;
        code_size = data_size + 1;
        code_mask = (1 << code_size) - 1;
        for (code = 0; code < clear; code++)
        {
            prefix[code] = 0;
            suffix[code] = (unsigned char)code;
        }

        /* decode gif pixel stream */
        datum = 0;
        bits = 0;
        c = 0;
        count = 0;
        first = 0;
        offset = 0;
        pass = 0;
        top_stack = pixel_stack;
        for (y = src_clipy1; y <= src_clipy2; y++)
        {
            if(!gdi_image_progress_callback()) 
                GDI_RAISE(GDI_IMAGE_ERR_DECODE_TIME_OUT);

            /* move to 0,offset */
            for (x = src_clipx1; x <= src_clipx2;)
            {
                if (top_stack == pixel_stack)
                {
                    if (bits < code_size)
                    {
                        /* Load bytes until there is enough bits for a code. */
                        if (count == 0)
                        {
                            /* Read a new data block. */
                            GET_U8(count);
                            if (count == 0)
                            {
                                break;
                            }
                            packet = (unsigned char*)gdi_gif_stack;    /* this will only use 256 bytes */
                            GETS(c, packet, count);
                        }
                        datum += ((unsigned int)(*c)) << bits;
                        bits += 8;
                        c++;
                        count--;
                        continue;
                    }

                    /* Get the next code. */
                    code = datum & code_mask;
                    datum >>= code_size;
                    bits -= code_size;

                    /* Interpret the code */
                    if ((code > available) || (code == end_of_information))
                    {
                        break;
                    }

                    if (code == clear)
                    {
                        /* Reset decoder. */
                        code_size = data_size + 1;
                        code_mask = (1 << code_size) - 1;
                        available = clear + 2;
                        old_code = NullCode;
                        continue;
                    }

                    if (old_code == NullCode)
                    {
                        *top_stack++ = suffix[code];
                        old_code = code;
                        first = code;
                        continue;
                    }
                    in_code = code;
                    if (code >= available)
                    {
                        *top_stack++ = (unsigned char)first;
                        code = old_code;
                    }

                    while (code >= clear)
                    {
                        if ((top_stack - pixel_stack) >= MaxStackSize)
                        {
                            break;
                        }
                        *top_stack++ = suffix[code];
                        code = (unsigned int)prefix[code];
                    }
                    first = (unsigned int)suffix[code];

                    /* Add a new string to the string table, */

                    if ((top_stack - pixel_stack) >= MaxStackSize)
                    {
                        break;
                    }

                    if (available >= MaxStackSize)
                    {
                        break;
                    }

                    *top_stack++ = (unsigned char)first;
                    prefix[available] = (short)old_code;
                    suffix[available] = (unsigned char)first;
                    available++;

                    if (((available & code_mask) == 0) && (available < MaxStackSize))
                    {
                        code_size++;
                        code_mask += available;
                    }
                    old_code = in_code;
                }

                /* Pop a pixel off the pixel stack. */

                top_stack--;

                if (IS_GDI_RESIZER_WANT_DRAW(x, src_clipy1 + offset))
                {
                    U32 index = (U32) * top_stack;

                    /* W06.01 Support transparent enable for color overlay index */
                    if (transparent_enable)
                    {
                        GDI_RESIZER_PUT((gdi_color) current_palette[index], (BOOL) (transparent_index != index));
                    }
                    else
                    {
                        GDI_RESIZER_PUT((gdi_color) current_palette[index], (BOOL) (1));
                    }
                }
                x++;
            }   /* x loop */

            if (gdi_image_gif_progress_callback)
                if (gdi_image_gif_progress_callback(x - GIF_ox, y - GIF_oy))
                {
                    MMI_TRACE(GDI_TRC, GDI_TRC_43//"GDI_RAISE gdi_image_gif_progress_callback"
                                         );
  
                    GDI_RAISE(1);
                }
            if (!is_interlace)
            {
                offset++;
            }
            else
            {
                switch (pass)
                {
                    case 0:
                    default:
                    {
                        offset += 8;
                        if (offset >= image_rows)
                        {
                            pass++;
                            offset = 4;
                        }
                        break;
                    }
                    case 1:
                    {
                        offset += 8;
                        if (offset >= image_rows)
                        {
                            pass++;
                            offset = 2;
                        }
                        break;
                    }
                    case 2:
                    {
                        offset += 4;
                        if (offset >= image_rows)
                        {
                            pass++;
                            offset = 1;
                        }
                        break;
                    }
                    case 3:
                    {
                        offset += 2;
                        break;
                    }
                }
                gdi_resizer_set_want_sy(src_clipy1 + offset);
            }
            if (x <= src_clipx2)
            {
                break;
            }
        }   /* y loop */
        if (y <= src_clipy2)
        {
            MMI_TRACE(GDI_TRC, GDI_TRC_44//"GDI_RAISE y <= src_clipy2"
                     );
              
            GDI_RAISE(1);
        }
    }   /* codec block */
}


/*****************************************************************************
 * FUNCTION
 *  GDI_IMAGE_GIF_DRAW_INTERNAL
 * DESCRIPTION
 *  Displays a given frame of the GIF file
 * PARAMETERS
 *  ox                      [IN]        Position at which the GIF image is to be displayed
 *  oy                      [IN]        Position at which the GIF image is to be displayed
 *  is_resized              [IN]        
 *  resized_width           [IN]        
 *  resized_height          [IN]        
 *  src                     [?]         
 *  size                    [IN]        
 *  cache_id                [IN]        
 *  frame_number            [IN]        Frame number to load for animated GIF.
 *  use_disposal_method     [IN]        
 *  transparent_enable      [IN]        
 *  file(?)                 [IN]        The GIF file in bytestream format
 *  color_depth(?)          [IN]        Output color depth.
 * RETURNS
 *  0  if GIF_load failed (invalid GIF image)
 *  1  if GIF_load is successful
 *****************************************************************************/
GDI_RESULT GDI_IMAGE_GIF_DRAW_INTERNAL(
            S32 ox,
            S32 oy,
            BOOL is_resized,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            U32 cache_id,
            U16 frame_number,
            BOOL use_disposal_method,
            BOOL transparent_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 gif_done;
    S32 frame_counter = 0;
    U16 transparent_index = 256;
    S32 n;
    S16 lcd_idx;
	S8 gif_is_hit_cache = 0;
    gdi_image_gif_struct *cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    INIT_SRC(src, size);

    // try to hit the cache and initialize the cache item
    {
        S32 offset;

        if (gdi_image_gif_hit_cache(cache_id, ox,oy, frame_number, &lcd_idx, &frame_counter, &offset, TRUE))
        {
			gif_is_hit_cache = 1;
            SEEK(offset);
            MMI_TRACE(GDI_TRC, GDI_TRC_45,//"GIF(sw) hit cache fn=%d, lcd=%d, frame_count = %d, offset = %d",
                                                frame_number,lcd_idx,frame_counter,offset);
        }
		else // first draw , we should keep 1 pixels background color for later used.
		{
            S32 x1,y1;
            x1=ox;
            y1=oy;

			if(x1<gdi_act_layer->clipx1) x1 = gdi_act_layer->clipx1;
			if(y1<gdi_act_layer->clipy1) y1 = gdi_act_layer->clipy1;
            
			gdi_gif_cache[lcd_idx].original_background = gdi_act_get_pixel(x1,y1);

            MMI_TRACE(GDI_TRC, GDI_TRC_46,//"GIF(sw) NOT hit cache background color (%d,%d) =%x", 
                                                x1,y1,gdi_gif_cache[lcd_idx].original_background);
		}
        cache = &gdi_gif_cache[lcd_idx];
    }

    // /////////////////////////////////////////////////////////
    // read the GIF file signature 
    if (frame_counter == 0)
    {
        U32 header;

        GET_U24(header);
        if (header != 0x464947) /* 'GIF' */
        {
            return GDI_FAILED;
        }

        ///////////////////////////////////////////////////////////
        // read the GIF dimension 
        FLUSH(3);
        GET_U16(gdi_image_gif_width);
        GET_U16(gdi_image_gif_height);

        cache->image_width = gdi_image_gif_width;
        cache->image_height = gdi_image_gif_height;

        /*
         * Check the validity of clipping 
         */
        if (ox > GDI_LAYER.clipx2 || oy > GDI_LAYER.clipy2 ||
            ox + gdi_image_gif_width - 1 < GDI_LAYER.clipx1 || oy + gdi_image_gif_height - 1 < GDI_LAYER.clipy1)
        {
            return GDI_SUCCEED;
        }

        /* ///////////////////////////////////////////////////////// */
        /*
         * Read the global color palette 
         */
        GET_U8(n);
        FLUSH(1);//GET_U8(cache->bg_color_idx);
        FLUSH(1);

        cache->has_gct = (n & 0x80) > 0 ? TRUE : FALSE;

        if (cache->has_gct)
        {
            S32 i;
            gd_color_from_rgb_func palette_color_from_rgb;

            n = 1 << ((n & 0x7) + 1);

            if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
            {
                palette_color_from_rgb = GDI_PALETTE_COLOR_FROM_RGB;
            }
            else
            {
                palette_color_from_rgb = gdi_act_color_from_rgb;
            }

            /* Read the global color palette */
            gdi_image_gif_palette_size = n;
            for (i = 0; i < n; i++)
            {
                U8 R, G, B;

                GET_U8(R);
                GET_U8(G);
                GET_U8(B);
                cache->palette[i] = palette_color_from_rgb(0xFF, R, G, B);
                if ((gdi_act_layer_info->source_key_enable && cache->palette[i] == gdi_act_layer_info->source_key) 
                ||  (gdi_image_gif_decoder_is_bypass_color && cache->palette[i] == gdi_image_gif_decoder_bypass_color))
                    cache->palette[i] ^= 1;
            }

            /* current layer is index color layer */
            if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
                for (i = 0; i < (S32) n; i++)
                {
                    gdi_layer_set_palette((U8) i, cache->palette[i]);
                    cache->palette[i] = i;
                }
        }
    }

    /* If resized width > original width or resized height > original height, do not resize */
    if (!is_resized 
    || resized_width > cache->image_width 
    || resized_height > cache->image_height)
    {
        resized_width = cache->image_width;
        resized_height = cache->image_height;
    }
    MMI_TRACE(GDI_TRC, GDI_TRC_47,//"resized width x height = %dx %d",
                            resized_width,resized_height);

    /* don't process resized_width/resized_height == 0*/
    if (resized_width == 0 || resized_height == 0)
        return (GDI_SUCCEED);

    // /////////////////////////////////////////////////////////
    // start decoding
    gif_done = 0;

    do
    {
        U8 tag;

        GET_U8(tag);
        switch (tag)
        {
            case '!':   /* Process the GIF extension block */
                GET_U8(tag) 
                if (tag == 0xf9)
                {
                    U8 byte_1, byte_2, byte_3, byte_4;
                    U32 a;

                    FLUSH(1);
                    GET_U8(byte_1);
                    GET_U8(byte_2);
                    GET_U8(byte_3);
                    GET_U8(byte_4);

                    /*
                     * if diposal method is 2 (restore bg) or 3 (restore previous) and has gct,
                     * we will set restore bg flag on.
                     * We do not has enought memory to implement method 3, sepc recommand us to
                     * use method 2 to replace method 3.
                     */

                    a = (U32)((byte_1 >> 2) & 0x03);
					if(a==2 || a==3)
                        cache->disposal_method = a;
                    else
                        cache->disposal_method = 0;

                    if (byte_1 & 0x01)
                    {
                        transparent_index = byte_4;
                    }
                    gdi_anim_set_delay((((U32) (byte_3 << 8)) | (U32) (byte_2)) * 10);
                    FLUSH(1);
                }
                else
                {
                    S32 offset;

                    while (1)
                    {
                        GET_U8(offset);
                        if (offset == 0)
                        {
                            break;
                        }
                        FLUSH(offset);
                    }
                }
                break;
            case ',':   /* Image descriptor (0x2C) */

                /* restore background color */
				if (use_disposal_method)
                if (gif_is_hit_cache)
                {
                    if(cache->last_disposal_method)
                    {
						gdi_color c;
						//if(cache->bg_color_idx == transparent_index)
							c = cache-> original_background;
						//else
						//	c = cache->palette[cache->bg_color_idx];

                        MMI_TRACE(GDI_TRC, GDI_TRC_14,//"sw disposal method: restore background(%d,%d)-(%d,%d) clip=(%d,%d)-(%d,%d) color=%x",
                                            cache->last_frame_x1,
                                            cache->last_frame_y1,
                                            cache->last_frame_x2,
                                            cache->last_frame_y2,
                                            gdi_act_layer->clipx1,
                                            gdi_act_layer->clipy1,
                                            gdi_act_layer->clipx2,
                                            gdi_act_layer->clipy2,
                                            c);
                    gdi_draw_solid_rect(
                            cache->last_frame_x1,
                            cache->last_frame_y1,
                            cache->last_frame_x2,
                            cache->last_frame_y2,
                            c);
                    }
                }

                GDI_IMAGE_GIF_CODEC(
                    ox,
                    oy,
                    resized_width,
                    resized_height,
                    transparent_index,
                    cache,
                    frame_counter,
                    transparent_enable
                    );
                gdi_image_gif_progress_callback = NULL;

                if (frame_counter >= frame_number)
                    gif_done = 1;

				gif_is_hit_cache = TRUE; // second pass should be in cache
                frame_counter++;
                if (frame_counter < MAX_GIF_FRAME_SUM)
                {
                    cache->cache[frame_counter] = TELL();
                }
                else
                {
                    cache->cache[MAX_GIF_FRAME_SUM] = TELL();
                    cache->latest_frame = frame_counter;
                }
                cache->last_disposal_method = cache->disposal_method;

                /* peek if is last frame */
                {
                    U8 a, b;

                    PEEK_U8(a);
                    PEEK_U8_N(b, 1);
                    if (a == '\0' && b == ';')
                    {
                        if (gif_done)
                        {
                            return GDI_SUCCEED;
                        }
                        else
                        {
                            return GDI_FAILED;
                        }
                    }
                }
                break;
            case '\0':
                if (IS_EOF())   /* Some pictures do not have trailer */
                {
                    if (gif_done)   /* had rendered this frame */
                    {
                        return GDI_SUCCEED;
                    }
                    else
                    {
                        return GDI_FAILED;
                    }
                }
                break;
            case ';':   /* Trailer */
               {
                if (gif_done)   /* had rendered this frame */
                    return GDI_SUCCEED;
                else
                    return GDI_FAILED;
                }
                break;
        }
    }
    while (!gif_done && !IS_EOF());

    gdi_image_gif_transparent_index = transparent_index;

	if(gif_done)
		return GDI_SUCCEED;
	else
		return GDI_FAILED;
}

#if defined(__MTK_TARGET__)
#ifdef GDI_IMAGE_GIF_USING_INTERRAM
#pragma arm section code
#endif 
#endif /* defined(__MTK_TARGET__) */ 

#ifdef GDI_IMAGE_GIF_GET_DIMENSION_INTERNAL


/*****************************************************************************
 * FUNCTION
 *  GDI_IMAGE_GIF_GET_DIMENSION_INTERNAL
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [?]         
 *  size        [IN]        
 *  width       [?]         
 *  height      [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT GDI_IMAGE_GIF_GET_DIMENSION_INTERNAL(U8 *src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    INIT_SRC(src, size);

    GET_U24(header);
    if (header != 0x464947) /* 'GIF' */
    {
        *width = 0;
        *height = 0;
        return GDI_FAILED;
    }
    /*
     * read the GIF dimention 
     */
    FLUSH(3);
    GET_U16(*width);
    GET_U16(*height);

    return GDI_SUCCEED;
}
#endif /* GDI_IMAGE_GIF_GET_DIMENSION_INTERNAL */ 

