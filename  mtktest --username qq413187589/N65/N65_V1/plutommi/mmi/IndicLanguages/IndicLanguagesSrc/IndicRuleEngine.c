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
 *   IndicRuleEngine.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C file for Indic language Engine API's
 *
 * Author:
 *   Pramod (pmt00110)
 *   Pawanjeet (pmt00112)
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
/* PMT START MAUI_00027829 */
#include "MMI_include.h"
#if defined (__MMI_INDIC_ALG__)
/* PMT END MAUI_00027829 */ 
#include "gui.h"
#include "UCS2Prot.h"
#include "IndicRuleEngine.h"

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
#endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) */ 

/************        EXTERN DEFINITION       ********************************/

extern const ire_indic_languages_table_struct indic_lang_char_info_table[];
extern const ire_indic_languages_table_struct indic_lang_ligature_info_table[];

struct ire_g_context_struct g_indic_rule_engine_cntx;

/************        API'S DEFINITION       ********************************/


/*****************************************************************************
 * FUNCTION
 *  ire_get_current_cluster
 * DESCRIPTION			This method will find the current cluster and
 *						copy it into the output buffer
 * PARAMETERS
 *  previous_cursor_p       [IN]        Previous cursor pointer to start with
 *  current_cursor_p        [IN]        Current cursor pointer
 *  output_buffer           [IN]        Output buffer
 *  RETURNS           true or false(?)(?)
 *****************************************************************************/
S32 ire_get_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, PU16 output_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;
    U16 glyphoutput[G_MAX];
    PU8 move_cursor_p = previous_cursor_p;
/* PMT START IRE CODE REVIEW */
    U16 n_glyphoutput =0;
/* PMT END IRE CODE REVIEW */

    g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = current_cursor_p;
    /* initialize the local buffer */
    memset(glyphoutput, '\0', G_MAX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n[ IRE MODULE ] ire_get_current_cluster()\n");

#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(move_cursor_p)))
        {
            output_buffer[0] = (U16) '?';
            /* terminate the output buffer string with NULL character */
            output_buffer[1] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
            return TRUE;
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);

        while (move_cursor_p != current_cursor_p)
        {
            /* start forming cluster */
            cluster_len = ire_get_cluster(output_buffer);
            /* update the prev cursor pointer by incrementing it */
            move_cursor_p += (cluster_len * 2);
            if (cluster_len == 0)
            {
                break;
            }
        }
        /* PMT START IRE CODE REVIEW */
        /* Code Removed */
        /* PMT END IRE CODE REVIEW */
        /* apply language rules on the cluster recently formed */
        ire_language_rules(glyphoutput, output_buffer, g_indic_rule_engine_cntx.g_display_buffer_len);
        /* copy the glyph output into output buffer */
        /* PMT START IRE CODE REVIEW */
        n_glyphoutput = mmi_ucs2strlen((const S8*)glyphoutput);
        memcpy(output_buffer, glyphoutput, n_glyphoutput * 2);
        /* terminate the output buffer string with NULL character */
        output_buffer[n_glyphoutput] = (U16) NULL;
        /* PMT END IRE CODE REVIEW */

    }
    else
    {
        output_buffer[0] = (U16) (IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p));
        /* terminate the output buffer string with NULL character */
        output_buffer[1] = (U16) NULL;
    }
    g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_next_cluster_p
 * DESCRIPTION				This method will search for the next cluster and returns
 *							the pointer to the begining of the cluster
 * PARAMETERS
 *  previous_cursor_p       [IN]        Previous cursor pointer to start with
 *  current_cursor_p        [IN]        Current cursor pointer
 *  RETURNS                    pointer to the begining of next cluster(?)(?)
 *****************************************************************************/
PU8 ire_get_next_cluster_p(PU8 previous_cursor_p, PU8 current_cursor_p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;        /* store the length of the cluster */
    U16 cluster_buffer[G_MAX];  /* temporary buffer used to find out the cluster length */
    PU8 curr_cursor_p = previous_cursor_p;

    /* initialize the local buffer */
    memset(cluster_buffer, '\0', G_MAX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ] ire_get_next_cluster_p() \n");

#ifdef __MMI_BIDI_ALG__
/* PMT START MAUI_00027731 */
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(curr_cursor_p)))
        {
            return (previous_cursor_p + TWO);
        }
    }
#endif

   if(previous_cursor_p==current_cursor_p)
   {
       return previous_cursor_p; 

   }
    /* Is there any character present or not */
	if (IRE_LANG_ID_CONVERT_U8_U16(previous_cursor_p) == (U16) NULL)
    {
        return previous_cursor_p;
    }
    else if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_NEXT_VAL_U8_U16(previous_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);
        /* start forming cluster */
        cluster_len = ire_get_cluster(cluster_buffer);
        /* update the cursor pointer by incrementing it with cluster length */
        curr_cursor_p += (cluster_len * 2);
        return curr_cursor_p;
    }
    else
    {
        return (previous_cursor_p + TWO);
    }
/* PMT END MAUI_00027731 */
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_prev_cluster_p
 * DESCRIPTION					This method will search the previous cluster
 *								and returns the pointer to the begining of cluster
 * PARAMETERS
 *  text_p          [IN]        Pointer to a text to start with
 *  cursor_p        [IN]        Pointer to a current cursor position
 *  RETURNS                 pointer to the begining of previous cluster if exists(?)(?)
 *****************************************************************************/
PU8 ire_get_prev_cluster_p(PU8 text_p, PU8 cursor_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;
    U16 cluster_buffer[G_MAX];
    PU8 current_cursor_p = text_p;
    PU8 prev_cursor_p = text_p;
    PU8 cursor_pointer = cursor_p;

    /* initialize the local buffer */
    memset(cluster_buffer, '\0', G_MAX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor_pointer -= TWO;
    /* PMT START MAUI_00027731 */
	PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ] ire_get_prev_cluster_p() \n");
    /* PMT END MAUI_00027731 */

#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(cursor_pointer)))
        {
            return (cursor_pointer);
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    /* Is previous character belongs to Indic range */
    if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(cursor_pointer)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(text_p);
        ire_init_cluster_end_p(cursor_p);

        while (current_cursor_p != cursor_p)
        {
            /* find the length of cluster */
            cluster_len = ire_get_cluster(cluster_buffer);
            /* store the value of previous pointer */
            prev_cursor_p = current_cursor_p;
            /* update the temporary cursor pointer */
            current_cursor_p += (cluster_len * 2);
            if (cluster_len == 0)
            {
                break;
            }
        }
        return prev_cursor_p;
    }
    else
    {
        return cursor_pointer;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_size_of_current_cluster
 * DESCRIPTION					This method will return the size of cluster
 *								in numbers of pixels
 * PARAMETERS
 *  previous_cursor_p       [IN]        
 *  current_cursor_p        [IN]        
 *  cursor                  [IN]        Pointer
 *  text_p(?)               [IN]        Text pointer to start with(?)
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_size_of_current_cluster(PU8 previous_cursor_p, PU8 current_cursor_p, U16 cursor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cluster_len = 0;
    S32 pixel_size = 0;
    U16 cluster_buffer[G_MAX];
    U16 glyphoutput[G_MAX];
    PU8 move_cursor_p = previous_cursor_p;

    /* initialize the local buffer */
    memset(glyphoutput, '\0', G_MAX);
    memset(cluster_buffer, '\0', G_MAX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ] ire_size_of_current_cluster() \n");

#ifdef __MMI_BIDI_ALG__
    if (g_indic_rule_engine_cntx.g_ire_arabic_language_character_count)
    {
        if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(move_cursor_p)))
        {
            pixel_size = gui_get_character_width((U16) '?');
            g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
            return pixel_size;
        }
    }
#endif /* __MMI_BIDI_ALG__ */ 

    /* Is cursor pointing to NULL character */
    if (previous_cursor_p == current_cursor_p)
    {
        return 0;
    }
    /* Is this character belongs to Indic language range */
    if (IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p)))
    {
        /* set the start and end pointer */
        ire_init_cluster_start_p(previous_cursor_p);
        ire_init_cluster_end_p(current_cursor_p);

        while (move_cursor_p != current_cursor_p)
        {
            /* start forming cluster */
            cluster_len = ire_get_cluster(cluster_buffer);
            /* update the prev cursor pointer by incrementing it with cluster length */
            move_cursor_p += (cluster_len * 2);
            if (cluster_len == 0)
            {
                break;
            }
        }
        ire_language_rules(glyphoutput, cluster_buffer, g_indic_rule_engine_cntx.g_display_buffer_len);
        /* find the length in terms of number of pixels */
        pixel_size = ire_get_string_width_height(glyphoutput);
    }
    else
    {
        /* find the length in terms of number of pixels */
        pixel_size = gui_get_character_width((U16) IRE_LANG_ID_CONVERT_PREVIOUS_VAL_U8_U16(current_cursor_p));
    }
    g_indic_rule_engine_cntx.g_cursor_end_curr_cluster_p = NULL;
    return pixel_size;
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_character_lang_id
 * DESCRIPTION			This method checks the input unicode value 
 *						and returns the correponding language Id
 * PARAMETERS
 *  character       [IN]        Input character (unicode value of a character)
 * RETURNS
 *  U32 Language Id of the input character
 *****************************************************************************/
U32 ire_get_character_lang_id(U16 character)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* proprietery unicode range */
    if ((character & 0xE000) || (character & 0xF000))
    {
        switch (character & 0xFF00)
        {
        /* PMT START MAUI_00419974 */
        #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
        /* PMT END MAUI_00419974 */
            case 0xE900:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_HINDI unicode val \n");
                return IRE_LANGUAGE_ID_HINDI;
        /* PMT START MAUI_00419974 */
        #endif        
        #if defined(__MMI_LANG_GUJRATI__)
        /* PMT END MAUI_00419974 */
            case 0xE9D0:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_TELUGU unicode val \n");
                return IRE_LANGUAGE_ID_GUJRATI;
                /* 7.24 PMT  END TELUGU & PUNJABI */
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_BENGALI__)
        /* PMT END MAUI_00419974 */		
            case 0xEA00:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_BENGALI unicode val \n");
                return IRE_LANGUAGE_ID_BENGALI;
       /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_PUNJABI__)
        /* PMT END MAUI_00419974 */		
            case 0xEB00:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_PUNJABI unicode val \n");
                return IRE_LANGUAGE_ID_PUNJABI;
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_KANNADA__)
         /* PMT END MAUI_00419974 */		
            case 0xFB20:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_KANNADA unicode val \n");
                return IRE_LANGUAGE_ID_KANNADA;
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_MALAYALM__)
        /* PMT END MAUI_00419974 */
            case 0xFB90:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_MALAYALAM unicode val \n");
                return IRE_LANGUAGE_ID_MALAYALAM;
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_SINHALA__)
        /* PMT END MAUI_00419974 */		 
            case 0xFBC0:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_SINHALA unicode val \n");
                return IRE_LANGUAGE_ID_SINHALA;
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_TELUGU__)
        /* PMT END MAUI_00419974 */		 
            case 0xEC00:
                /* 7.24 PMT  START TELUGU & PUNJABI */
            case 0xED00:
                /* 7.24 PMT  END TELUGU & PUNJABI */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_GUJRATI unicode val \n");
                return IRE_LANGUAGE_ID_TELUGU;
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_ORIYA__)	
        /* PMT END MAUI_00419974 */	
            case 0xED50:
                /* 7.24 PMT  END TELUGU & PUNJABI */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_ORIYA unicode val \n");
                return IRE_LANGUAGE_ID_ORIYA;
        /* PMT START MAUI_00419974 */
        #endif
        #if defined(__MMI_LANG_TAMIL__)	
        /* PMT END MAUI_00419974 */	
            case 0xEE00:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_TAMIL unicode val \n");
                return IRE_LANGUAGE_ID_TAMIL;
        /* PMT START MAUI_00419974 */
        #endif	
        /* PMT END MAUI_00419974 */			
            default:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  IRE_LANGUAGE_ID_INVALID unicode val \n");
                return IRE_LANGUAGE_ID_INVALID;
        }
    }
    else    /* standard unicode range */
    {

        switch (character & 0x0F00)
        {
        /* PMT START MAUI_00419974 */
        #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__)
        
            case 0x0900:
            #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
                if (!(character & 0x0080))
                    return IRE_LANGUAGE_ID_HINDI;
            #endif
            #if defined(__MMI_LANG_BENGALI__)
                if (character & 0x0080)
                    return IRE_LANGUAGE_ID_BENGALI;
	     #endif		
                return IRE_LANGUAGE_ID_INVALID;
        #endif
        #if defined(__MMI_LANG_PUNJABI__) || defined(__MMI_LANG_GUJRATII__)
            case 0x0A00:
            #if defined(__MMI_LANG_PUNJABI__)
                if (!(character & 0x0080))
                    return IRE_LANGUAGE_ID_PUNJABI;
            #endif
            #if defined(__MMI_LANG_GUJRATII__)
                if (character & 0x0080)
                    return IRE_LANGUAGE_ID_GUJRATI;
	     #endif		
                return IRE_LANGUAGE_ID_INVALID;
        #endif
        #if defined(__MMI_LANG_ORIYA__) || defined(__MMI_LANG_TAMIL__)
            case 0x0B00:
            #if defined(__MMI_LANG_ORIYA__)
                if (!(character & 0x0080))
                    return IRE_LANGUAGE_ID_ORIYA;
            #endif
            #if defined(__MMI_LANG_TAMIL__)
                if (character & 0x0080)
                    return IRE_LANGUAGE_ID_TAMIL;
	     #endif		
                return IRE_LANGUAGE_ID_INVALID;
        #endif
        #if defined(__MMI_LANG_KANNADA__) || defined(__MMI_LANG_TELUGU__)		
            case 0x0C00:
            #if defined(__MMI_LANG_TELUGU__)
                if (!(character & 0x0080))
                    return IRE_LANGUAGE_ID_TELUGU;
            #endif
            #if defined(__MMI_LANG_KANNADA__)
                if (character & 0x0080)
                    return IRE_LANGUAGE_ID_KANNADA;
	     #endif		
                return IRE_LANGUAGE_ID_INVALID;
        #endif
        #if defined(__MMI_LANG_SINHALA__) || defined(__MMI_LANG_MALAYALAM__)		
            case 0x0D00:
            #if defined(__MMI_LANG_MALAYALAM__)
                if (!(character & 0x0080))
                    return IRE_LANGUAGE_ID_MALAYALAM;
            #endif
            #if defined(__MMI_LANG_SINHALA__)
                if (character & 0x0080)
                    return IRE_LANGUAGE_ID_SINHALA;
	     #endif			     		
                return IRE_LANGUAGE_ID_INVALID;
        #endif
        /* PMT END MAUI_00419974 */				
            default:
                return IRE_LANGUAGE_ID_INVALID;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_cluster
 * DESCRIPTION			This method will identifies the characters which will 
 *                      participate in cluster formation 
 * PARAMETERS
 *  cluster     [IN]    Buffer to be filled with characters(which will participate in cluster formation)
 * RETURNS
 *  S32 The number of characters which will form cluster
 *****************************************************************************/
S32 ire_get_cluster(PU16 cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFill = 0;                  /* no. of elements filled in the cluster */
    S32 j = 0;                      /* loop counter */
    S32 i = 0;                      /* loop counter */
    S32 ch_index = 0;
    S32 size = 0;
    S32 nsize = 0;
    U32 langIdIndex = 0;            /* to store the value of language Id of input character */
    U32 mCharacterStatusFlag = 0;
    U16 startRange = 0;             /* to store the starting range of language of input character */
    U16 endRange = 0;               /* to store the end range of language of input character */
    U16 temp = 0;                   /* temporary local variable to hold unicode value during runtime */
    PU16 start_cluster = cluster;   /* pointer to the begining of the buffer */
    PU8 start_char = g_indic_rule_engine_cntx.g_cluster_start_p;        /* pointer to the text pointer which is under consideration for cluster formation */
    U8 isValidRuleEntryExist = MMI_FALSE;
    U8 is_first_entry_ra_cons = MMI_FALSE;
    U8 is_first_entry_small_cons = MMI_FALSE;
    U8 temp_small_cons_halant_flag = 0;

    const ire_glyph_info_table_struct *char_table_p;        /* pointer to character table containing ligature info   of that character */
    const ire_character_info_table_struct *char_status_flag_p;  /* pointer to a character info structure */
    const ire_main_glyph_table_struct *main_glyph_table_base_address_p;
    ire_indic_languages_table_struct indic_lang_table_info; /* store the Indic language table entry,(i.e structure info) */
    ire_main_glyph_table_struct ind_table;                  /* main table containing full character table info */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_indic_rule_engine_cntx.g_display_buffer_len = 0;
    IRE_RESET_SMALL_CONS_HALANT_FLAG();
    IRE_RESET_SMALL_CONSONANT_FLAG();

    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_cluster() \n");

    /* Is this a valid unicode value */
    if (!IRE_LANG_ID_CONVERT_U8_U16(start_char))
    {
        return 0;
    }
    /* Is this character belongs to Indic language range or not */
    if (!IRE_INDIC_LANGUAGE_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char)))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_cluster().... Non Indic Character\n");
        IRE_LANG_ID_FILL_CLUSTER();
        start_cluster[nFill] = (U16) NULL;
        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
        return nFill;
    }
    /* store the language Id of input character  */
    langIdIndex = ire_get_character_lang_id((U16) IRE_LANG_ID_CONVERT_U8_U16(start_char));
    /* get Indic language array index   */
    indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
    /* store start range of Indic language table */
    startRange = indic_lang_table_info.start_range;
    /* store end range of Indic language ligature   */
    endRange = indic_lang_table_info.end_range;
    /* get the pointer to the begining of the array of structures  */
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    if (NULL == char_status_flag_p)
    {
        IRE_LANG_ID_FILL_CLUSTER();
        start_cluster[nFill] = (U16) NULL;
        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
        return nFill;
    }
    /* Identify the charcater based on character flag and update the g flag */
    IRE_IDENTIFY_CHARACTER(
        IRE_LANG_ID_CONVERT_U8_U16(start_char),
        char_status_flag_p,
        startRange,
        mCharacterStatusFlag);

    nFill = 0;

    switch (mCharacterStatusFlag)
    {
        case NORMAL_CON:    /* 0x00000001 */
        case RA_CON:        /* 0x00000002 */
        case SMALL_CON:     /* 0x00000003 */
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                 "\n [ IRE MODULE ]  ire_get_cluster().... Indic char type Consonant\n");
            if ((!(mCharacterStatusFlag ^ RA_CON)))
            {
                is_first_entry_ra_cons = MMI_TRUE;
            }
            else if ((!(mCharacterStatusFlag ^ SMALL_CON)))
            {
                is_first_entry_small_cons = MMI_TRUE;
                IRE_SET_SMALL_CONSONANT_FLAG();
            }

            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);

            MMI_ASSERT(!(nFill > G_MAX));
            /* Is the next character belongs to the language of current character   */
            IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                start_cluster,
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                startRange,
                endRange,
                nFill);
            /* Identify next character and update character flag  */
            IRE_IDENTIFY_CHARACTER(
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                char_status_flag_p,
                startRange,
                mCharacterStatusFlag);

            if (!(mCharacterStatusFlag ^ HALANT))   /* Con + Halant */
            {
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_get_cluster().... Indic char type Halant Sign\n");
                IRE_LANG_ID_FILL_CLUSTER();
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);

                MMI_ASSERT(!(nFill > G_MAX));
                /* Is the next character belongs to the language of current character   */
                IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                    start_cluster,
                    IRE_LANG_ID_CONVERT_U8_U16(start_char),
                    startRange,
                    endRange,
                    nFill);
                /* Identify next character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlag);
                /* loop for Con + hal + Con + hal + con .....sequence */
                while ((mCharacterStatusFlag & ALL_CONSONANT_TYPE))
                {
                    if (is_first_entry_small_cons == MMI_FALSE)
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                    }
                    else
                    {
                        /* START PMT PUNJABI TELUGU */
                        //ch_index            = IRE_LANG_ID_CONVERT_U8_U16(start_char) - startRange;  /* find the index of character in main table */
                        //ind_table           = main_glyph_table_base_address_p[ch_index - 1];    /* gets the individual charactr's table in main table */
                        //char_table_p        = ind_table.glyph_info_p;                                                       /* holds the add. of individual character */
                        //start_cluster[nFill] = (U16)(*(char_table_p[1].output_buffer_glyph));
                        temp_small_cons_halant_flag = 1;
                        IRE_LANG_ID_FILL_CLUSTER();
                        /* END PMT PUNJABI TELUGU */
                    }
                    /* PMT START MAUI_00027731 */
                    /* PMT START MAUI_00028960 */
                    if( start_char == g_indic_rule_engine_cntx.g_cluster_end_p)
                    {
                        break;
                    }
                    /* PMT END MAUI_00028960 */
                    /* PMT END MAUI_00027731 */
                    /* Is the next character belongs to the language of current character   */
                    if ((!IRE_CHECK_CHARACTER_LANG_RANGE(IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange))
                        || (nFill > G_MAX))
                    {
                        break;
                    }
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
                    if (mCharacterStatusFlag & HALANT)
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        /* PMT START MAUI_00027731 */
                        /* PMT START MAUI_00028960 */
                        if( start_char == g_indic_rule_engine_cntx.g_cluster_end_p)
                        {
                           break;
                        }
                        /* PMT END MAUI_00028960 */
                        /* PMT END MAUI_00027731 */
                        /* Is the next character belongs to the language of current character   */
                        if ((!IRE_CHECK_CHARACTER_LANG_RANGE
                             (IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange)) || (nFill == (G_MAX - 2)))
                        {
                            break;
                        }
                        /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);
                    }
                    else
                    {
                        break;
                    }
                }
                /* START PMT PUNJABI TELUGU */
                if (temp_small_cons_halant_flag)
                {
                    if (IRE_IS_CHAR_TYPE_HALANT(cluster[nFill - 1]))
                    {
                        /* reorder put halant after first Cons treat halant as post base matra */
                        IRE_REORDER_SMALL_CON_POST_BASE_MATRA(nFill, j, temp, i);

                        IRE_SET_SMALL_CONS_HALANT_FLAG();
                    }
                    else
                    {
                        IRE_DOUBLE_SET_SMALL_CONS_HALANT_FLAG();
                    }

                }
                /* END PMT PUNJABI TELUGU */
                if ((is_first_entry_small_cons == MMI_TRUE) && (nFill & 1))
                {
                    /* START PMT PUNJABI TELUGU */
                    //do rendering
                    //IRE_REORDER_SMALL_CONS_HAL_CONS(nFill,j,temp);
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                    {
                        /* START PMT PUNJABI TELUGU */
                        IRE_SET_SMALL_CONS_HALANT_FLAG();
                        /* END PUNJABI TELUGU */
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_REORDER_SMALL_CON_POST_BASE_MATRA(nFill, j, temp, i);
                    }

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(start_cluster, IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange, nFill);    /* Identify next character and update character flag  */
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }

                }
                else if ((is_first_entry_small_cons == MMI_TRUE) && (nFill % 2))
                {
                    IRE_REORDER_SMALL_CON_POST_BASE_MATRA(nFill, j, temp, i);
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                }
                /* END PMT PUNJABI TELUGU */
                if (is_first_entry_ra_cons == MMI_TRUE)
                {
                    if (nFill % 2)
                    {
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);

                        if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                        {
                            IRE_LANG_ID_FILL_CLUSTER();
                        }
                        /* PMT START MAUI_00028370 */
                        else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))        /* Con + Halant + Ra + halant + Postbase matra/sign */
                        {
                            /* centre base handling */
                            ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1;     /* find the index of character in main table */
                            ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                            char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
                            IRE_REORDER_RA_HALANT_CONS_SEQUENCE(nFill, j, temp, i);
                            IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, nFill, char_table_p, temp, size, j);
                            g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                            /* Identify next character and update character flag  */
                            IRE_IDENTIFY_CHARACTER(
                               (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
				               char_status_flag_p,
				               startRange,
				               mCharacterStatusFlag);
                            if (!(mCharacterStatusFlag ^ NORMALSIGN))
                            {
                                start_cluster[nFill+1] = IRE_LANG_ID_CONVERT_U8_U16(start_char);
                                ++nFill;
                                start_char+=2;
                                g_indic_rule_engine_cntx.g_display_buffer_len++;
                                start_cluster[nFill + 1] = (U16) NULL;
                                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                                return nFill;
                            }
                            else
                            {
                                start_cluster[nFill + 1] = (U16) NULL;
                                g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                                return nFill;
                            }
                        }
                        /* PMT END MAUI_00028370 */

                        IRE_REORDER_RA_HALANT_CONS_SEQUENCE(nFill, j, temp, i);

                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        MMI_ASSERT(!(nFill > G_MAX));
                        /* Is the next character belongs to the language of current character   */
                        IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(start_cluster, IRE_LANG_ID_CONVERT_U8_U16(start_char), startRange, endRange, nFill);        /* Identify next character and update character flag  */
                        /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);

                        if (!(mCharacterStatusFlag ^ NORMALSIGN))
                        {
                            IRE_LANG_ID_FILL_CLUSTER();
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                    }
                    else
                    {
                        IRE_REORDER_RA_HALANT_CONS_HALANT_SEQUENCE(nFill, j, temp, i);
                    }

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                }   /* End of if statement if(is_first_entry_ra_cons == MMI_TRUE) */

                /* Is the next character belongs to the language of current character   */
                IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                    start_cluster,
                    IRE_LANG_ID_CONVERT_U8_U16(start_char),
                    startRange,
                    endRange,
                    nFill);
                /* Identify next character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlag);

                if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))        /* Con + Halant + Ra + Prebase matra */
                {
                    IRE_LANG_ID_FILL_CLUSTER();

                    IRE_REORDER_PREBASE_MATRA(nFill, j, temp);

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))   /* Con + Halant + Ra + halant + Prebase matra + Sign */
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
                else if ((!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL)) || (!(mCharacterStatusFlag ^ NORMALSIGN)))      /* Con + Halant + Ra +  Postbase matra/sign */
                {
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))   /* Con + Halant + Ra + halant + Postbase matra+ sign */
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
                else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))        /* Con + Halant + Ra + Centrebase matra/sign */
                {
                    /* centre base handling */
                    ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1;     /* find the index of character in main table */
                    ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                    char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                    /* START PMT PATCH04052007 */
                    IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, nFill, char_table_p, temp, size, j);
                    /* END PMT PATCH04052007 */

                    g_indic_rule_engine_cntx.g_display_buffer_len += 2;
                    /* PMT START MAUI_00029051 */		
		    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                       (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
				       char_status_flag_p,
				       startRange,
				       mCharacterStatusFlag);
                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        start_cluster[nFill+1] = IRE_LANG_ID_CONVERT_U8_U16(start_char);
                        ++nFill;
                        start_char+=2;
                        g_indic_rule_engine_cntx.g_display_buffer_len++;
                        start_cluster[nFill + 1] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                    else
                    {
                    /* PMT END MAUI_00029051 */
                    start_cluster[nFill + 1] = (U16) NULL;
                    g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                    return nFill;
                }
                /* PMT START MAUI_00029051 */
                }
                /* PMT END MAUI_00029051 */
            }   /*  End of Halant  */
            else if (!(mCharacterStatusFlag ^ TAMIL_HALANT_SIGN))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_get_cluster().... Indic char type Tamil Halant Sign\n");
                IRE_LANG_ID_FILL_CLUSTER();
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);

                MMI_ASSERT(!(nFill > G_MAX));
                /* Is the next character belongs to the language of current character   */
                IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                    start_cluster,
                    IRE_LANG_ID_CONVERT_U8_U16(start_char),
                    startRange,
                    endRange,
                    nFill);
                /* Identify next character and update character flag  */
                IRE_IDENTIFY_CHARACTER(
                    (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                    char_status_flag_p,
                    startRange,
                    mCharacterStatusFlag);

                if (!(mCharacterStatusFlag ^ NORMAL_CON))
                {
                    /* get the char pointer of first entries of cluster buffer */
                    ch_index = ((start_cluster[0]) - startRange) - 1;   /* find the index of character in main table */
                    ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                    char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
                    nsize = ind_table.nsize;                /* get no. of entries inside array */

                    /* get the max. length of input buffer */
                    if (ind_table.max_input_glyph_size > 2)
                    {
                        IRE_LANG_ID_FILL_CLUSTER();

                        MMI_ASSERT(!(nFill > G_MAX));
                        /* Identify next character and update character flag  */
                        IRE_IDENTIFY_CHARACTER(
                            (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                            char_status_flag_p,
                            startRange,
                            mCharacterStatusFlag);

                        if ((!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL)) || (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))) /* con + halant + con + Prebase matra */
                        {
                            IRE_LANG_ID_FILL_CLUSTER();

                        }

                        do
                        {
                            nsize--;
                            /* check the entries inside the rule table */
                            if (memcmp
                                (char_table_p[nsize].input_buffer_glyph, start_cluster,
                                 char_table_p[nsize].input_buffer_len * 2) == 0)
                            {
                                isValidRuleEntryExist = MMI_TRUE;
                                break;
                            }

                        } while (char_table_p[nsize].input_buffer_len > 2);

                        /* if the entry does not exists and total number of entries are three */
                        if ((nFill == 3) && (MMI_FALSE == isValidRuleEntryExist))
                        {
                            start_cluster[nFill - 1] = (U16) NULL;
                            nFill--;
                            start_char -= 2;
                            g_indic_rule_engine_cntx.g_display_buffer_len--;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            return nFill;
                        }
                        /* if the entry does not exists and total number of entries are four */
                        else if ((nFill == 4) && (MMI_FALSE == isValidRuleEntryExist))
                        {
                            start_cluster[nFill - 1] = (U16) NULL;
                            start_cluster[nFill - 2] = (U16) NULL;
                            nFill -= 2;
                            start_char -= 4;
                            g_indic_rule_engine_cntx.g_display_buffer_len -= 2;
                            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                            return nFill;
                        }

                        if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                        {
                            IRE_LANG_ID_FILL_CLUSTER();
                            IRE_REORDER_PREBASE_MATRA(nFill, j, temp);
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                        else if (!(mCharacterStatusFlag ^ TAMIL_HALANT_SIGN))
                        {
                            IRE_LANG_ID_FILL_CLUSTER();
                            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                        }
                    }   /* End of if(length of input buffer) */
                }       /* End of if(Normal consonant) */
            }           /* End of tamil halant sign */
            else
            {
                /* Con + Pre base Matra */
                if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                {
                    IRE_LANG_ID_FILL_CLUSTER();

                    IRE_REORDER_PREBASE_MATRA(nFill, j, temp);

                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
                else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))        /* Con + Halant + Ra + halant + Postbase matra/sign */
                {
                    /* centre base handling */
                    ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1;     /* find the index of character in main table */
                    ind_table = main_glyph_table_base_address_p[ch_index];      /* gets the individual charactr's table in main table */
                    char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                    /* START PMT PATCH04052007 */
                    IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, nFill, char_table_p, temp, size, j);
                    /* END PMT PATCH04052007 */

                    g_indic_rule_engine_cntx.g_display_buffer_len += 2;
/* PMT START MAUI_00028021 */
					/* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);
                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        start_cluster[nFill+1] = IRE_LANG_ID_CONVERT_U8_U16(start_char);
						++nFill;
						start_char+=2;
						g_indic_rule_engine_cntx.g_display_buffer_len++;
                        start_cluster[nFill + 1] = (U16) NULL;
						g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
						return nFill;
                    }
					else
					{
/* PMT END MAUI_00028021 */
                    start_cluster[nFill + 1] = (U16) NULL;
                    g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                    return nFill;
/* PMT START MAUI_00028021 */
					}
/* PMT END MAUI_00028021 */
                }
                else if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))  /* Con + Post base Matra */
                {
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
                else if (!(mCharacterStatusFlag ^ NORMALSIGN))  /* Con + Sign */
                {
                    IRE_LANG_ID_FILL_CLUSTER();
                    IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    MMI_ASSERT(!(nFill > G_MAX));
                    /* Is the next character belongs to the language of current character   */
                    IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                        start_cluster,
                        IRE_LANG_ID_CONVERT_U8_U16(start_char),
                        startRange,
                        endRange,
                        nFill);
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!(mCharacterStatusFlag ^ POST_BASE_DEPVOWEL))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                    else if (!(mCharacterStatusFlag ^ PRE_BASE_DEPVOWEL))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();

                        IRE_REORDER_PREBASE_MATRA(nFill, j, temp);

                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                    else if (!(mCharacterStatusFlag ^ CENTER_BASE_DEPVOWEL))    /* Con + Halant + Ra + halant + Postbase matra/sign */
                    {
                        /* centre base handling */
                        ch_index = ((IRE_LANG_ID_CONVERT_U8_U16(start_char)) - startRange) - 1; /* find the index of character in main table */
                        ind_table = main_glyph_table_base_address_p[ch_index];  /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */

                        /* START PMT PATCH04052007 */
                        IRE_REORDER_CENTER_BASE_DEP_VOWEL(start_cluster, nFill, char_table_p, temp, size, j);
                        /* END PMT PATCH04052007 */

                        g_indic_rule_engine_cntx.g_display_buffer_len += 2;

                        start_cluster[nFill + 1] = (U16) NULL;
                        g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
                        return nFill;
                    }
                    /* Identify next character and update character flag  */
                    IRE_IDENTIFY_CHARACTER(
                        (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                        char_status_flag_p,
                        startRange,
                        mCharacterStatusFlag);

                    if (!((mCharacterStatusFlag) ^ NORMALSIGN))
                    {
                        IRE_LANG_ID_FILL_CLUSTER();
                        IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
                    }
                }
            }   /* End of Con + Pre/Post base Matra */
            start_cluster[nFill] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }       /* End of case statement Normal Consonant */

        case INDEPVOWEL:    /* Independent Vowel *//* 0x00000040: */
        {
            IRE_LANG_ID_FILL_CLUSTER();
            IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            MMI_ASSERT(!(nFill > G_MAX));
            /* PMT START MAUI_00028467 */
            IRE_CHECK_NEXT_CHARACTER_LANG_RANGE(
                start_cluster,
                IRE_LANG_ID_CONVERT_U8_U16(start_char),
                startRange,
                endRange,
                nFill);
            /* PMT END MAUI_00028467 */
            /* Identify next character and update character flag  */
            IRE_IDENTIFY_CHARACTER(
                (IRE_LANG_ID_CONVERT_U8_U16(start_char)),
                char_status_flag_p,
                startRange,
                mCharacterStatusFlag);
            if (!(mCharacterStatusFlag ^ NORMALSIGN))
            {
                IRE_LANG_ID_FILL_CLUSTER();
                IRE_LANG_ID_END_CLUSTER(start_cluster, start_char, nFill);
            }
            start_cluster[nFill] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }
            /* Dependent Vowel Range */
        case PRE_BASE_DEPVOWEL:     /* 0x00000008 */
        case POST_BASE_DEPVOWEL:    /* 0x00000010 */
        case BELOW_BASE_DEPVOWEL:   /* 0x00000018 */
        case ABOVE_BASE_DEPVOWEL:   /* 0x00000020 */
        case CENTER_BASE_DEPVOWEL:  /* 0x00000028 */
        case NORMALSIGN:            /* 0x00000100; */
        default:
        {
            IRE_LANG_ID_FILL_CLUSTER();
            start_cluster[nFill] = (U16) NULL;
            g_indic_rule_engine_cntx.g_cluster_start_p += (nFill * 2);
            return nFill;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_multitap_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [?]
 *  current_character       [IN]        
 *  Char_Range              [IN]        
 *  check_char              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_multitap_text_x(S32 *ptext_x, U16 current_character, S32 Char_Range, S32 check_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 prev_char_mtext_x = 0;
    static S32 prev_char_mdwidth = 0;
    S32 character_height = 0;
    S32 text_x = 0;
    S32 mtext_gap = 5;
    U32 mCharacterStatusFlag = 0;
    U32 langIdIndex = 0;    /* to store the value of language Id of input character */
    U16 startRange = 0;     /* to store the starting range of language of input character */

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_multitap_text_x().... \n");

    text_x = *ptext_x;
    if (!(check_char))
    {
        switch (Char_Range)
        {
            case 1:
                *ptext_x = 59;
                break;
            case 2:
                *ptext_x = 54;
                break;
            case 3:
                *ptext_x = 49;
                break;
            case 4:
                *ptext_x = 44;
                break;
            case 5:
                *ptext_x = 39;
                break;
            case 6:
                *ptext_x = 35;
                break;
            case 7:
                *ptext_x = 30;
                break;
            case 8:
                *ptext_x = 25;
                break;
            case 9:
                *ptext_x = 20;
                break;
            case 10:
                *ptext_x = 15;
                break;
            case 11:
                *ptext_x = 10;
                break;
            case 12:
            case 13:
            case 14:
                *ptext_x = 7;
                break;
            default:
                *ptext_x = 3;
                break;
        }
        prev_char_mtext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &prev_char_mdwidth, &character_height);
        return;
    }
    /* store the language Id of input character  */
    langIdIndex = ire_get_character_lang_id(current_character);
    /* get Indic language array index   */
    indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
    /* store start range of Indic language table */
    startRange = indic_lang_table_info.start_range;
    /* get the pointer to the begining of the array of structures  */
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    if (NULL != char_status_flag_p)
    {

        IRE_IDENTIFY_CHARACTER(current_character, char_status_flag_p, startRange, mCharacterStatusFlag);

        if ((!((mCharacterStatusFlag) ^ PRE_BASE_DEPVOWEL)) ||
            (!((mCharacterStatusFlag) ^ CENTER_BASE_DEPVOWEL)) ||
            (!((mCharacterStatusFlag) ^ NORMALSIGN)) || (!((mCharacterStatusFlag) ^ POST_BASE_DEPVOWEL)))
        {
            text_x = prev_char_mdwidth + prev_char_mtext_x + mtext_gap;
        }
        else
        {
            text_x = prev_char_mdwidth + prev_char_mtext_x;
        }
    }
    else
    {
        text_x = prev_char_mdwidth + prev_char_mtext_x;
    }

    Get_CharWidthHeight(current_character, &prev_char_mdwidth, &character_height);
    prev_char_mtext_x = text_x;

    /* TBD under consideration...need to be fixed */
    if (current_character == 0x940) /* DV_II */
    {
        *ptext_x = text_x + mtext_gap;
    }
    else
    {
        *ptext_x = text_x;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_text_x
 * DESCRIPTION				This method will calculate the width, dwidth based 
 *							upon the type of input characters
 * PARAMETERS
 *  ptext_x                 [?]         
 *  current_character       [IN]        
 *  text_y                  [IN]        
 *  d_width                 [IN]        
 *  width                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_text_x(S32 *ptext_x, U16 current_character, S32 text_y, U16 d_width, U16 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0;
    U8 is_Indic = 1;

    const ire_character_info_table_struct *char_status_flag_p = NULL;
    const ire_character_info_table_struct *pLangFlag;
    ire_indic_languages_table_struct indic_lang_table_info;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;
    /* PMT START IRE CODE REVIEW */
    U32 character_type=0;
    /* PMT END IRE CODE REVIEW */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_text_x().... \n");
    /* PMT START MAUI_00419974 */
    langIdIndex = ire_get_character_lang_id(current_character);
    /* PMT END MAUI_00419974 */
    /* If above API returns NULL, the character is not Indic Range */
    /* PMT START IRE CODE REVIEW */
    if ( current_character >= 0x0E01 && current_character <= 0x0E7F)
    /* PMT END IRE CODE REVIEW */
    {
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        if (IsThaiAboveLineChar(current_character))
        {
            g_indic_rule_engine_cntx.g_prev_char_dwidth = 0;
            g_indic_rule_engine_cntx.g_prev_char_width = 0;
        }
        g_indic_rule_engine_cntx.g_prev_character = current_character;
        return;
    }

    /* PMT START MAUI_00419974 */
    if (!langIdIndex)
    /* PMT END MAUI_00419974 */
    {
        d_width = width;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = g_indic_rule_engine_cntx.g_prev_char_width;
        is_Indic = 0;
        if (r2lMMIFlag)
        {
            return;
        }
    }
    if (!(g_indic_rule_engine_cntx.g_new_line))
    {
        g_indic_rule_engine_cntx.g_new_line = 1;
    /* PMT START MAUI_00419974 */
       if (langIdIndex)
    /* PMT END MAUI_00419974 */
        {
            *ptext_x = *ptext_x - g_indic_rule_engine_cntx.g_indic_padding;
        }
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        g_indic_rule_engine_cntx.g_prev_character = current_character;
        return;
    }
    /* PMT START MAUI_00419974 */
    if (langIdIndex)
    /* PMT END MAUI_00419974 */
    {
        /* get language index   */
    /* PMT START MAUI_00419974 */
    /* Code Removed */ 		 
    /* PMT END MAUI_00419974 */		
        /* if not ligature range */
        if (!(current_character & 0xE000))
        {
            /* get Indic language array index   */
            indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
            /* start range of Indic language */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures  */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }
        else
        {
            /* get Indic language ligature array index   */
            indic_lang_table_info = indic_lang_ligature_info_table[langIdIndex];
            /* start range of Indic language ligature */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }

        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((current_character - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
    }

    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    /* START PMT PUNJABI TELUGU */
    /* PMT START IRE CODE REVIEW */
    character_type = ire_identify_char_small_consonant_family(current_character);
    if (NULL != char_status_flag_p)
    {
        if (IRE_GET_SMALL_CONSONANT_FLAG() && (character_type==IRE_CHAR_TYPE_SIGN_CONSONANT))
        {
                /* PMT START MAUI_00027833 */
                if(g_indic_rule_engine_cntx.error_correction_for_rendering && (current_character & 0xE000)
                    && (IRE_IS_CHAR_TYPE_CONSONANT(current_character) 
                    || IRE_IS_CHAR_TYPE_LIGATURE(g_indic_rule_engine_cntx.g_prev_character)
                    || IRE_IS_CHAR_TYPE_SIGN(g_indic_rule_engine_cntx.g_prev_character) ))
                {
                   
                    U8 correction = g_indic_rule_engine_cntx.error_correction_for_rendering;
                    *ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x + correction;              
                    g_indic_rule_engine_cntx.g_prev_char_dwidth = correction + d_width;
                    g_indic_rule_engine_cntx.g_prev_char_width = correction + width;
                    g_indic_rule_engine_cntx.error_correction_for_rendering = 0;
                }
                else
                {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x;
                    IRE_RESET_RENDERING_CORRECTION();
                }
           /* PMT END MAUI_00027833 */
            
            IRE_RESET_SMALL_CONSONANT_FLAG();
        }
        else if ((!((mCharStatusFlag & 0x0000F000) ^ IS_VALID_SIGN) || !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE))
                 && (!(character_type==IRE_CHAR_TYPE_SIGN_CONSONANT)))
/* PMT END IRE CODE REVIEW */
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_text_x;
            if ((mCharStatusFlag & 0x0000F000) == BELOW_BASE)
            {
                IRE_RESET_SMALL_CONSONANT_FLAG();
            }
        }
        else
        {
            if (is_Indic)
            {
                if (!(IRE_INDIC_CHARACTER_UCS2_RANGE(g_indic_rule_engine_cntx.g_prev_character)))
                {
                    g_indic_rule_engine_cntx.g_prev_char_text_x -= g_indic_rule_engine_cntx.g_indic_padding;
                }
            }
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_dwidth + g_indic_rule_engine_cntx.g_prev_char_text_x;
            /* PMT START MAUI_00027833 */
            IRE_RESET_RENDERING_CORRECTION();
            /* PMT END MAUI_00027833 */
            g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
            g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
            g_indic_rule_engine_cntx.g_prev_char_width = width;
            if (IRE_GET_SMALL_CONSONANT_FLAG() && ((mCharStatusFlag & 0x0000000F) == NORMAL_CON))
            {
                IRE_RESET_SMALL_CONSONANT_FLAG();
                /* PMT START MAUI_00027833 */
                IRE_RESET_RENDERING_CORRECTION();
                /* PMT END MAUI_00027833 */
            }

        }
    }
    else
    {
        if (is_Indic)
        {
            if (!(IRE_INDIC_CHARACTER_UCS2_RANGE(g_indic_rule_engine_cntx.g_prev_character)))
            {
                g_indic_rule_engine_cntx.g_prev_char_text_x -= g_indic_rule_engine_cntx.g_indic_padding;
            }
        }
        *ptext_x = g_indic_rule_engine_cntx.g_prev_char_dwidth + g_indic_rule_engine_cntx.g_prev_char_text_x;
        g_indic_rule_engine_cntx.g_prev_char_text_x = *ptext_x;
        g_indic_rule_engine_cntx.g_prev_char_dwidth = d_width;
        g_indic_rule_engine_cntx.g_prev_char_width = width;
        /* PMT START MAUI_00027833 */
        IRE_RESET_RENDERING_CORRECTION();
        /* PMT END MAUI_00027833 */
        if (IRE_GET_SMALL_CONSONANT_FLAG())
        {
            /* PMT START MAUI_00027833 */
            IRE_RESET_RENDERING_CORRECTION();
            /* PMT END MAUI_00027833 */
            IRE_RESET_SMALL_CONSONANT_FLAG();
        }

    }
    g_indic_rule_engine_cntx.g_prev_character = current_character;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_bordered_text_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptext_x                 [?]         
 *  current_character       [IN]        
 *  text_y                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_bordered_text_x(S32 *ptext_x, U16 current_character, S32 text_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height = 0;
    U32 langIdIndex = 0;
    U16 startRange = 0;

    const ire_character_info_table_struct *char_status_flag_p;
    const ire_character_info_table_struct *pLangFlag;
    ire_indic_languages_table_struct indic_lang_table_info;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;
/* PMT START IRE CODE REVIEW */
    U32 character_type=0;
/* PMT END IRE CODE REVIEW */

    char_status_flag_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_bordered_text_x().... \n");

    /* PMT START IRE CODE REVIEW */
    langIdIndex = ire_get_character_lang_id(current_character);
    /* PMT END IRE CODE REVIEW */
    if (g_indic_rule_engine_cntx.g_new_bline)
    {
        g_indic_rule_engine_cntx.g_new_bline = 0;
        g_indic_rule_engine_cntx.g_prev_char_btext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &(g_indic_rule_engine_cntx.g_prev_char_bdwidth), &character_height);
        return;
    }
    if (langIdIndex)
    {
        /* if not ligature range */
        if (!(current_character & 0xE000))
        {
            /* get Indic language array index   */
            indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
            /* start range of Indic language */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures  */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }
        else
        {
            /* get Indic language ligature array index   */
            indic_lang_table_info = indic_lang_ligature_info_table[langIdIndex];
            /* start range of Indic language ligature */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((current_character - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
    }
    /*
     * As char might belong to indic range, but our product doesn't support that language
     * In that case, just fill the char as such, it could be in the form of square box.
     * so this check is required
     */
    /* START PMT PUNJABI TELUGU */
/* PMT START IRE CODE REVIEW */
    character_type = ire_identify_char_small_consonant_family(current_character);
    if (NULL != char_status_flag_p)
    {
        if (IRE_GET_SMALL_CONSONANT_FLAG() && (character_type==IRE_CHAR_TYPE_SIGN_CONSONANT))
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_btext_x;
            g_indic_rule_engine_cntx.g_prev_char_bdwidth = g_indic_rule_engine_cntx.g_prev_char_bdwidth;
            IRE_RESET_SMALL_CONSONANT_FLAG();
        }
        else if ((!((mCharStatusFlag & 0x0000F000) ^ IS_VALID_SIGN) || !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE))
                 && (!(character_type==IRE_CHAR_TYPE_SIGN_CONSONANT)))
/* PMT END IRE CODE REVIEW */
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_btext_x;
            g_indic_rule_engine_cntx.g_prev_char_bdwidth = g_indic_rule_engine_cntx.g_prev_char_bdwidth;
            if ((mCharStatusFlag & 0x0000F000) == BELOW_BASE)
            {
                IRE_RESET_SMALL_CONSONANT_FLAG();
            }

        }
        else
        {
            *ptext_x = g_indic_rule_engine_cntx.g_prev_char_bdwidth + g_indic_rule_engine_cntx.g_prev_char_btext_x;
            g_indic_rule_engine_cntx.g_prev_char_btext_x = *ptext_x;
            Get_CharWidthHeight(current_character, &(g_indic_rule_engine_cntx.g_prev_char_bdwidth), &character_height);
            if (IRE_GET_SMALL_CONSONANT_FLAG() && ((mCharStatusFlag & 0x0000000F) == NORMAL_CON))
            {
                IRE_RESET_SMALL_CONSONANT_FLAG();
            }

        }
    }
    else
    {
        *ptext_x = g_indic_rule_engine_cntx.g_prev_char_bdwidth + g_indic_rule_engine_cntx.g_prev_char_btext_x;
        g_indic_rule_engine_cntx.g_prev_char_btext_x = *ptext_x;
        Get_CharWidthHeight(current_character, &(g_indic_rule_engine_cntx.g_prev_char_bdwidth), &character_height);
        if (IRE_GET_SMALL_CONSONANT_FLAG())
        {
            IRE_RESET_SMALL_CONSONANT_FLAG();
        }

        /* END PMT PUNJABI TELUGU */
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  indic_whether_conjunct
 * DESCRIPTION
 *  This method will check whether the current glyph output participate in conjunct form or not
 * PARAMETERS
 *  conjunct        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL indic_whether_conjunct(U16 conjunct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  indic_whether_conjunct().... \n");

    switch (conjunct)
    {

    #if defined (__MMI_LANG_HINDI__)
        case HINDI_L_KSHA:
        case HINDI_L_TRA:
        case HINDI_L_SHRA:
        case HINDI_L_TTTA:
            return TRUE;
    #endif /* defined (__MMI_LANG_HINDI__) */ 

    #if defined (__MMI_LANG_TAMIL__)
        case TAMIL_L_KSHA:
            return TRUE;
    #endif /* defined (__MMI_LANG_TAMIL__) */ 

        default:
            return FALSE;
    }
}

/* END */


/*****************************************************************************
 * FUNCTION
 *  ire_language_rules
 * DESCRIPTION			This method will apply grammer rules on the input cluster buffer
 *						and copy the output buffer i.e glyphoutput
 * PARAMETERS
 *  glyphoutput     [IN]        
 *  cluster         [IN]        
 *  nentry          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_language_rules(PU16 glyphoutput, PU16 cluster, S32 nentry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 noutglyph = 0;      /* no. of entries in output cluster to be given to renderer */
    S32 matched = FALSE;
    S32 input = nentry;
    S32 tomatch = nentry;   /* nentries--no. of elements in the cluster */
    U32 langIdIndex = 0;    /* to store the value of language Id of input character */
    U32 mCharStatusFlag = 0;
    U32 mCharStatusFlagNext = 0;
    U16 startRange = 0;     /* to store the starting range of language of input character */
    U16 is_input_buffer_cpy = MMI_FALSE;
    S32 temp = 0;
    /* PMT START MAUI_00029464 */        
    /* Code Removed */
    /* PMT END MAUI_00029464 */
    U8 telugu_check = 0;
    /* PMT START MAUI_00029464 */        
    U8 rendering_error_flag = 0;
    /* PMT END MAUI_00029464 */
    /* PMT START MAUI_00027829 */
    #if defined(__MMI_LANG_TELUGU__)
    U8 check_seq_KA_hal_SSA = MMI_FALSE;
    PU16 pglyphoutput = NULL;
    /* PMT START MAUI_00029464 */        
    /* Code Removed */
    /* PMT END MAUI_00029464 */
    #endif
    /* PMT END MAUI_00027829 */


    const ire_main_glyph_table_struct *main_glyph_table_base_address_p;
    const ire_character_info_table_struct *char_status_flag_p = NULL;
    const ire_glyph_info_table_struct *char_table_p;    /* pointer to character table containing ligature info   of that character */
    ire_main_glyph_table_struct ind_table;              /* main table containing full character table info */
    ire_indic_languages_table_struct indic_lang_table_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_language_rules().... \n");

    /* get language index   */
    langIdIndex = ire_get_character_lang_id((*cluster));
    /* get Indic language array index   */
    indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
    /* start range of Indic language */
    startRange = indic_lang_table_info.start_range;
    /* get the pointer to the begining of the array of structures  */
    char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;

    main_glyph_table_base_address_p = indic_lang_table_info.indic_main_info_table_p;

    if (IRE_INDIC_LANGUAGE_RANGE(*cluster))
    {
        /*  if number of entries are single  */
        if (nentry == 1)
        {
            glyphoutput[nentry - 1] = *cluster;
            glyphoutput[nentry] = (U16) NULL;
            return nentry;
        }
        /* more than one entries   */
        while (nentry)
        {
            /* START PMT PUNJABI TELUGU */
            if ((!telugu_check) && (IRE_GET_SMALL_CONS_HALANT_FLAG() == 2))
            {
                telugu_check = 1;
                /* PMT START MAUI_00027829 */
                #if defined (__MMI_LANG_TELUGU__)
                if( nentry > 2 && cluster[0] == TELUGU_C_KA && cluster[2] == TELUGU_C_SSA)
                {
                 check_seq_KA_hal_SSA = MMI_TRUE;
                 pglyphoutput = glyphoutput;
                }
                #endif    
                /* PMT END MAUI_00027829 */             
                /* PMT START MAUI_00027833 */
                if(!rendering_error_flag)
                {
                    rendering_error_flag++;
                    ire_small_con_rendering_correction(cluster[0]);

                }
                /* PMT END MAUI_00027833 */
                glyphoutput[0] = *cluster;
                glyphoutput[1] = (U16) NULL;
                glyphoutput++;
                cluster++;
                nentry--;
                /* PMT START MAUI_00028077 */
                noutglyph++;
                /* PMT END MAUI_00028077 */ 
            }
            /* PMT START MAUI_00027833 */
            if(!rendering_error_flag && (IRE_GET_SMALL_CONS_HALANT_FLAG() == 1))
            {
                rendering_error_flag++;
                ire_small_con_rendering_correction(cluster[0]);

            }
            /* PMT END MAUI_00027833 */

            /* PMT START MAUI_00027829 */
            #if defined (__MMI_LANG_TELUGU__)
            if(cluster[0] == TELUGU_C_KA && (IRE_GET_SMALL_CONS_HALANT_FLAG() == 1))
            {
                check_seq_KA_hal_SSA = MMI_TRUE;
                pglyphoutput = glyphoutput;
            }
            #endif
            /* PMT END MAUI_00027829 */

            /* END PMT PUNJABI TELUGU */
            /* START PMT PUNJABI TELUGU */
            temp = (S32) (*cluster) - startRange - 1;
            /*PMT START MAUI_00027066 */
            //code removed
            /*PMT END MAUI_00027066 */
            ind_table = main_glyph_table_base_address_p[temp];  /* gets the individual charactr's table in main table */
            /* END PMT PUNJABI TELUGU */
            /*PMT START MAUI_00027066 */          
            if( ( temp<0) || (ind_table.glyph_info_p == NULL) )
            {
                glyphoutput[nentry - 1] = *cluster;
                glyphoutput[nentry] = (U16) NULL;
                return nentry;
            }
            /*PMT END MAUI_00027066 */
            char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
            size = ind_table.nsize;
            matched = FALSE;
            while (size)
            {
                size--;
                if ((tomatch != char_table_p[size].input_buffer_len) || ((char_table_p[size].rule_language) &&
                                                                         (char_table_p[size].rule_language !=
                                                                          hf_rules_current_set_language)))
                {
                    continue;
                }
                else if (memcmp(char_table_p[size].input_buffer_glyph, cluster, char_table_p[size].input_buffer_len * 2)
                         == 0)
                {
                    IRE_IDENTIFY_CHARACTER((*cluster), char_status_flag_p, startRange, mCharStatusFlag);

                    switch (mCharStatusFlag)
                    {
                        case RA_CON:
                        {
                            IRE_IDENTIFY_CHARACTER(*(cluster - 1), char_status_flag_p, startRange, mCharStatusFlag);

                            IRE_IDENTIFY_CHARACTER(*(cluster + 1), char_status_flag_p, startRange, mCharStatusFlagNext);

                            if ((input >= 3) &&
                                ((!(mCharStatusFlag ^ NORMAL_CON)) ||
                                 (!(mCharStatusFlag ^ RA_CON)) ||
                                 (!(mCharStatusFlag ^ POST_BASE_DEPVOWEL))) && ((mCharStatusFlag ^ PRE_BASE_DEPVOWEL)))
                            {
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].output_buffer_glyph,
                                    char_table_p[size].output_buffer_len * 2);
                                glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                                break;
                            }
                            else if (!(mCharStatusFlagNext ^ HALANT))
                            {
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].input_buffer_glyph,
                                    char_table_p[size].input_buffer_len * 2);
                                glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
                                glyphoutput++;                                
                                noutglyph++;
                                break;
                            }
                            memcpy(
                                glyphoutput,
                                char_table_p[size].output_buffer_glyph,
                                char_table_p[size].output_buffer_len * 2);
                            glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                            break;
                        }   /* End of case RA statement */
                        default:
                        {
                            IRE_IDENTIFY_CHARACTER(*(cluster + 1), char_status_flag_p, startRange, mCharStatusFlag);

                            if ((!((mCharStatusFlag) ^ HALANT)) && (*(cluster + 2) == (U16) NULL))
                            {
                                if (char_table_p[size].is_con_hal_ligature == 0)
                                {
                                    memcpy(
                                        glyphoutput,
                                        char_table_p[size].input_buffer_glyph,
                                        char_table_p[size].input_buffer_len * 2);
                                    glyphoutput[char_table_p[size].input_buffer_len] = (U16) NULL;
                                    is_input_buffer_cpy = MMI_TRUE;
                                }
                                else
                                {
                                    memcpy(
                                        glyphoutput,
                                        char_table_p[size].output_buffer_glyph,
                                        char_table_p[size].output_buffer_len * 2);
                                    glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                                }
                            }
                            else
                            {
                                memcpy(
                                    glyphoutput,
                                    char_table_p[size].output_buffer_glyph,
                                    char_table_p[size].output_buffer_len * 2);
                                glyphoutput[char_table_p[size].output_buffer_len] = (U16) NULL;
                            }
                            break;
                        }   /* End of default statement */
                    }       /* End of switch case   */

                    nentry -= char_table_p[size].input_buffer_len;
                    cluster += char_table_p[size].input_buffer_len;

                    if (is_input_buffer_cpy)
                    {
                        glyphoutput += char_table_p[size].input_buffer_len;
                        noutglyph += char_table_p[size].input_buffer_len;
                        is_input_buffer_cpy = MMI_FALSE;
                    }
                    else
                    {
                        glyphoutput += char_table_p[size].output_buffer_len;
                        noutglyph += char_table_p[size].output_buffer_len;
                    }
                    matched = TRUE;

                    IRE_IDENTIFY_CHARACTER(*cluster, char_status_flag_p, startRange, mCharStatusFlag);

                    if (indic_whether_conjunct(*(glyphoutput - 1)) && (!((mCharStatusFlag) ^ HALANT)))
                    {
                        IRE_IDENTIFY_CHARACTER(*(cluster + 1), char_status_flag_p, startRange, mCharStatusFlag);

                    #if defined (__MMI_LANG_HINDI__)
                        if ((!(mCharStatusFlag ^ RA_CON)) || (!(mCharStatusFlag ^ NORMAL_CON)))
                        {
                            switch (*(glyphoutput - 1))
                            {
                                case HINDI_L_KSHA:
                                    *(glyphoutput - 1) = HINDI_H_KHSA;
                                    break;
                                case HINDI_L_TRA:
                                    *(glyphoutput - 1) = HINDI_H_TRA;
                                    break;
                                case HINDI_L_SHRA:
                                    *(glyphoutput - 1) = HINDI_H_SHRA;
                                    break;
                                case HINDI_L_TTTA:
                                    *(glyphoutput - 1) = HINDI_H_TTA;
                                    break;

                                default:
                                    break;
                            }
                            *glyphoutput = (U16) NULL;
                            nentry -= 1;
                            cluster += 1;
                            noutglyph += 1;
                            matched = TRUE;
                            break;
                        }
                    #endif /* defined (__MMI_LANG_HINDI__) */ 
                    }   /* End of if statement */
                #if defined (__MMI_LANG_TAMIL__)
                    else if (indic_whether_conjunct(*(glyphoutput - 1)) &&
                             (!((mCharStatusFlag) ^ CENTER_BASE_DEPVOWEL)))
                    {
                        /* centre base handling */
                        ind_table = main_glyph_table_base_address_p[((*cluster) - startRange) - 1];     /* gets the individual charactr's table in main table */
                        char_table_p = ind_table.glyph_info_p;  /* holds the add. of individual character */
                        switch (*(glyphoutput - 1))
                        {
                            case TAMIL_L_KSHA:
                            {
                                *(glyphoutput - 1) = char_table_p[0].output_buffer_glyph[0];
                                *(glyphoutput) = TAMIL_L_KSHA;
                                *(glyphoutput + 1) = char_table_p[0].output_buffer_glyph[1];
                                break;
                            }
                            default:
                                break;
                        }
                        *(glyphoutput + 2) = (U16) NULL;
                        nentry -= 1;
                        cluster += 1;
                        noutglyph += 2;
                        matched = TRUE;
                        break;
                    }   /* End of else if statement */
                #endif /* defined (__MMI_LANG_TAMIL__) */ 
                    break;
                }
            }   /*   End of inner while loop */
            /*PMT START MAUI_00027066 */
            if (matched != TRUE && tomatch)
            /*PMT END MAUI_00027066 */
            {
                --tomatch;
            }
            else
            {
                tomatch = nentry;
            }
        }   /* End of outer while loop */
        PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                             "\n [ IRE MODULE ]  ire_language_rules()....noutglyph = %d, \t glyphoutput buffer = %s \n",
                             noutglyph, glyphoutput);
        /* PMT START MAUI_00027829 */
        #if defined (__MMI_LANG_TELUGU__)
        /* PMT START IRE CODE REVIEW */
        if(check_seq_KA_hal_SSA) 
        {
           U8 index = 0;
           while(pglyphoutput[index] != (U16) NULL)
           {
                if(pglyphoutput[index] == (U16) TELUGU_L_SMALL_SSA)
                {                  
                    pglyphoutput[index] = (U16) TELUGU_L_KSHA_HALANT;
                    break;
                }
                index++;
           }             
            
        }
        /* PMT END IRE CODE REVIEW */
        #endif
        /* PMT END MAUI_00027829 */
        return noutglyph;
    }       /* End of if statement */
    else
    {
        glyphoutput[nentry - 1] = *cluster;
        glyphoutput[nentry] = (U16) NULL;
        return nentry;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_indic_rules_for_whole_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_get_indic_rules_for_whole_string(PU8 String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 Len;
    S32 cluster_length;
    U16 unicode = 0;
    U16 Fill = 0;
    U16 clFill = 0;
    U16 cluster_fill[G_MAX];
    U16 glyph_output[G_MAX];
    /* PMT START IRE CODE REVIEW */
    U16 indic_present = 0;
    /* PMT END IRE CODE REVIEW */
    U8 StringArray[2048];
    U8 *temp_string = String;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_indic_rules_for_whole_string().... \n");
    /* PMT START IRE CODE REVIEW */
    while ((temp_string[clFill] != '\0' || temp_string[clFill + 1] != '\0') && !indic_present)
    {
        unicode = temp_string[clFill];
        unicode |= (temp_string[clFill + 1] << 8);
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
        {
            indic_present = 1;
        }
        clFill += 2;
    }
    if (indic_present)
    {
        ire_init_cluster_start_p(String);
	ire_init_cluster_end_p(String + (2 * mmi_ucs2strlen((const char*)String)));
    /* PMT END IRE CODE REVIEW */
        while (temp_string[0] != '\0' || temp_string[1] != '\0')
        {
            clFill = 0;
            unicode = temp_string[0];
            unicode |= (temp_string[1] << 8);
            cluster_length = ire_get_cluster(cluster_fill);

            if (IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
            {
                Len = ire_language_rules(glyph_output, cluster_fill, g_indic_rule_engine_cntx.g_display_buffer_len);
                temp_string += cluster_length * 2;
                while (glyph_output[clFill] != '\0')
                {
                    StringArray[Fill++] = (U8) (glyph_output[clFill] & 0x00ff);
                    StringArray[Fill++] = (U8) (glyph_output[clFill++] >> 8) & 0x00ff;
                }
            }
            else
            {
                StringArray[Fill++] = temp_string[0];
                StringArray[Fill++] = temp_string[1];
                temp_string += 2;
            }
        }
        StringArray[Fill++] = '\0';
        StringArray[Fill++] = '\0';
        memcpy(String, StringArray, Fill);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ire_get_string_width_height
 * DESCRIPTION		This method will calculate the width and height
 *					of the the input text
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_get_string_width_height(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_get_string_width_height().... \n");

    ire_disable_indic_rules_parsing();
    gui_measure_string(text, &w, &h);
    ire_enable_indic_rules_parsing();
    return (w);
}


/*****************************************************************************
 * FUNCTION
 *  ire_identify_character_type
 * DESCRIPTION
 * PARAMETERS
 *  start_cluster       [?]  pointer to a cluster buffer       
 *  start_char          [?]  pointer to a start character       
 *  nentry              [IN] number of entries in the cluster       
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_identify_character_type(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    U32 mCharStatusFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_identify_character_type().... \n");

    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        langIdIndex = ire_get_character_lang_id(currentCharacter);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
            /* start range of Indic language */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures  */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }
        else
        {
            /* get Indic language ligature array index   */
            indic_lang_table_info = indic_lang_ligature_info_table[langIdIndex];
            /* start range of Indic language ligature */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        /* Identify next character and update character flag  */
        IRE_IDENTIFY_CHARACTER(currentCharacter, char_status_flag_p, startRange, mCharStatusFlag);

        switch (mCharStatusFlag)
        {
            case NORMAL_CON:    /* 0x00000001 */
            case SMALL_CON:     /* 0x00000003 */
            case RA_CON:        /* 0x00000002 */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_CON");
                return IRE_CHAR_TYPE_CON;

            case INDEPVOWEL:    /* 0x00000040 */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_INDEPVOWEL");
                return IRE_CHAR_TYPE_INDEPVOWEL;

            case PRE_BASE_DEPVOWEL:     /* 0x00000008 */
            case POST_BASE_DEPVOWEL:    /* 0x00000010 */
            case CENTER_BASE_DEPVOWEL:  /* 0x00000028 */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_DEPVOWEL");
                return IRE_CHAR_TYPE_DEPVOWEL;

            case NORMALSIGN:    /* 0x00000100; */
            /* MTI START MAUI_00032507 */	
            case TAMIL_HALANT_SIGN:	
            /* MTI END MAUI_00032507 */	
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_SIGN");
                return IRE_CHAR_TYPE_SIGN;

            case HALANT:    /* 0x00000080 */
            /* MTI START MAUI_00032507 */	
            /* Code Moved */	
            /* MTI END MAUI_00032507 */	
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_HALANT");
                return IRE_CHAR_TYPE_HALANT;

            case LIGATURE:  /* 0x00000200 */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_LIGATURE");
                return IRE_CHAR_TYPE_LIGATURE;

            case DIGITS:    /* 0x00000800 */
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_DIGIT");
                return IRE_CHAR_TYPE_DIGIT;

            default:
                PRINT_INFORMATION_2(MMI_TRACE_G7_MISC,
                                     "\n [ IRE MODULE ]  ire_identify_character_type() char type = %d\n,IRE_CHAR_TYPE_INVALID");
                return IRE_CHAR_TYPE_INVALID;
        }
    }
    return IRE_CHAR_TYPE_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  ire_identify_sign_range
 * DESCRIPTION
 * PARAMETERS
 *  start_cluster       [?]  pointer to a cluster buffer       
 *  start_char          [?]  pointer to a start character       
 *  nentry              [IN] number of entries in the cluster       
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_identify_sign_range(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    const ire_character_info_table_struct *pLangFlag;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_identify_sign_range().... \n");

    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        langIdIndex = ire_get_character_lang_id(currentCharacter);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
            /* start range of Indic language */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures  */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }
        else
        {
            /* get Indic language ligature array index   */
            indic_lang_table_info = indic_lang_ligature_info_table[langIdIndex];
            /* start range of Indic language ligature */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((currentCharacter - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
        /* START PMT PUNJABI TELUGU */
        if (!((mCharStatusFlag & 0x0000F000) ^ IS_VALID_SIGN) || !((mCharStatusFlag & 0x0000F000) ^ BELOW_BASE))
        {
            return 1;
        }
        /* END PMT PUNJABI TELUGU */
    }
    return 0;
}

/* START PMT PUNJABI TELUGU */
/*****************************************************************************
 * FUNCTION
 *  ire_identify_char_small_consonant_family
 * DESCRIPTION
 * PARAMETERS
 *  start_cluster       [?]  pointer to a cluster buffer       
 *  start_char          [?]  pointer to a start character       
 *  nentry              [IN] number of entries in the cluster       
 * RETURNS
 *  
 *****************************************************************************/
S32 ire_identify_char_small_consonant_family(U16 currentCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 langIdIndex = 0;
    U16 startRange = 0;

    ire_indic_languages_table_struct indic_lang_table_info;
    const ire_character_info_table_struct *char_status_flag_p;

    const ire_character_info_table_struct *pLangFlag;

    U32 *mchar_status_flag_p = NULL;
    U32 mCharStatusFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "\n [ IRE MODULE ]  ire_identify_sign_range().... \n");

    if (IRE_INDIC_CHARACTER_UCS2_RANGE(currentCharacter))
    {
        /* get language index   */
        langIdIndex = ire_get_character_lang_id(currentCharacter);

        /* if not ligature range */
        if (!(currentCharacter & 0xE000))
        {
            /* get Indic language array index   */
            indic_lang_table_info = indic_lang_char_info_table[langIdIndex];
            /* start range of Indic language */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures  */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }
        else
        {
            /* get Indic language ligature array index   */
            indic_lang_table_info = indic_lang_ligature_info_table[langIdIndex];
            /* start range of Indic language ligature */
            startRange = indic_lang_table_info.start_range;
            /* get the pointer to the begining of the array of structures */
            char_status_flag_p = indic_lang_table_info.indic_char_info_flag_p;
        }

        /*
         * As char might belong to indic range, but our product doesn't support that language
         * In that case, just fill the char as such, it could be in the form of square box.
         * so this check is required
         */
        if (NULL == char_status_flag_p)
        {
            return 0;
        }
        /* get pointer of the character flag which is nothing but pointer to a structure */
        pLangFlag = (char_status_flag_p + ((currentCharacter - startRange) - 1));
        /* store the charater flag information by ORing and shifting bits */
        mchar_status_flag_p = (U32*) pLangFlag;

        mCharStatusFlag = *mchar_status_flag_p;
        if ((mCharStatusFlag & 0x0000F000) == BELOW_BASE)
            return IRE_CHAR_TYPE_SPECIAL_SIGN;
        else if (mCharStatusFlag == ABOVE_BASE_NORMAL_CON)
            return IRE_CHAR_TYPE_SIGN_CONSONANT;
        else if ((mCharStatusFlag & 0x0000000F) == NORMAL_CON)
            return IRE_CHAR_TYPE_NORMAL_CONSONANT;

    }
    return 0;

}

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
/*****************************************************************************
 * FUNCTION
 *  set_current_language_for_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void set_current_language_for_hindi_rules(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U8 temp_str1[30];
    U8 temp_str2[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) temp_str1, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);
    for (index = 0; index < (sizeof(HRLangSSC) / sizeof(HRLangSSC[0])); index++)
    {
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) HRLangSSC[index].ssc_string);
        if (mmi_ucs2cmp((const S8*)temp_str1, (const S8*)temp_str2) == 0)
        {
            hf_rules_current_set_language = HRLangSSC[index].language_enum;
            hf_rules_prefered_set_language = hf_rules_current_set_language;
            return;
        }
    }
    hf_rules_current_set_language = HRLangSSC[0].language_enum;
    hf_rules_prefered_set_language = hf_rules_current_set_language;

}


/*****************************************************************************
 * FUNCTION
 *  overwrite_current_language_for_hindi_rules_based_on_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void overwrite_current_language_for_hindi_rules_based_on_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MULTITAP_MARATHI__)
    if (MMI_current_input_mode == INPUT_MODE_MULTITAP_MARATHI)
    {
        hf_rules_current_set_language = MMI_MARATHI_LANG;
    }
#endif /* defined (__MMI_MULTITAP_MARATHI__) */ 
#if defined (__MMI_MULTITAP_HINDI__)
    if (MMI_current_input_mode == INPUT_MODE_MULTITAP_HINDI)
    {
        hf_rules_current_set_language = MMI_HINDI_LANG;
    }

#endif /* defined (__MMI_MULTITAP_HINDI__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  restore_current_language_for_hindi_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_current_language_for_hindi_rules(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hf_rules_current_set_language = hf_rules_prefered_set_language;
}
#endif /* defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) */ 

/* PMT START MAUI_00025413 */
/* PMT START IRE CODE REVIEW */
/*****************************************************************************
 * FUNCTION
 *  ire_is_character_ext_consonant_capable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prevCharacter       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ire_is_character_ext_consonant_capable(U16 prevCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        switch (prevCharacter)
        {
        #if defined(__MMI_LANG_HINDI__)
            case HINDI_C_KA:
            case HINDI_C_KHA:
            case HINDI_C_GA:
            case HINDI_C_JA:
            case HINDI_C_DDA:
            case HINDI_C_DDHA:
            case HINDI_C_NA:
            case HINDI_C_PHA:
            case HINDI_C_YA:
            case HINDI_C_RA:
            case HINDI_C_LLA:
                return 1;
        #endif /* defined(__MMI_LANG_HINDI__) */ 
            default:
             break; 
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ire_is_character_nukta
 * DESCRIPTION
 *  
 * PARAMETERS
 *  currCharacter       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ire_is_character_nukta(U16 currCharacter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(currCharacter)
        {
        #if defined(__MMI_LANG_HINDI__)
        case HINDI_S_NUKTA:
                return 1;
        #endif /* defined(__MMI_LANG_HINDI__) */ 
        default:
            break;
        }
            return 0;
    }
/* PMT END IRE CODE REVIEW */
/* PMT END MAUI_00025413 */
/* PMT START MAUI_00027833 */
/*****************************************************************************
 * FUNCTION
 *  ire_small_con_rendering_correction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  previous_unicode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ire_small_con_rendering_correction(U16 previous_unicode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     switch(previous_unicode)
    {
        #if defined(__MMI_LANG_TELUGU__)
        case TELUGU_C_KHA: 
        case TELUGU_C_DDHA :            
        case TELUGU_C_THA :            
        case TELUGU_C_DHA :
        case TELUGU_C_BHA : 
        case TELUGU_C_PHA :
            g_indic_rule_engine_cntx.error_correction_for_rendering = 7;
            break ;
        case TELUGU_C_GHA:
            g_indic_rule_engine_cntx.error_correction_for_rendering = 6;
           break ;       
        case TELUGU_C_CHA:
            g_indic_rule_engine_cntx.error_correction_for_rendering = 8;
            break ;
        case TELUGU_C_JHA:
            g_indic_rule_engine_cntx.error_correction_for_rendering = 12;
            break ;   

        case TELUGU_C_SSA:
           g_indic_rule_engine_cntx.error_correction_for_rendering = 10;
            break ; 
        #endif
        default:
            g_indic_rule_engine_cntx.error_correction_for_rendering = 0;
            break ;
    }
    return ;
}
/* PMT START MAUI_00031694 */
#if defined(__MMI_ZI_HINDI__) || defined(__MMI_ZI_MARATHI__) || defined(__MMI_ZI_BENGALI__) || defined(__MMI_ZI_PUNJABI__) || defined(__MMI_ZI_TAMIL__) || defined(__MMI_ZI_TELUGU__)

/*****************************************************************************
 * FUNCTION
 *  ire_IsValidInput
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Unicode         [IN]        
 *          
 * RETURNS
 *  U8              [OUT]
 *****************************************************************************/
 U8 ire_IsValidInput(U16* Unicode, U8 strlen)
 {
     
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     U16 previous_char = 0;
     U8 current_char_type = 0;
     U8 previous_char_type = 0;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     
     switch(ire_current_input_box_type())
     {
         case 1:
             previous_char = gui_multi_line_current_character(&MMI_multiline_inputbox);
             break;
         case 2:
             previous_char = gui_single_line_current_character(&MMI_singleline_inputbox);
             break;
         case 3:
             previous_char = gui_single_line_current_character(&MMI_inline_singleline_inputbox);
             break;
         default:
             previous_char = gui_EMS_current_character(&MMI_EMS_inputbox);
             break;
     }
     
     current_char_type = ire_identify_character_type(Unicode[0]);
     
     if((!previous_char) || (strlen == 1))
     {
         switch(current_char_type)
         {
             case IRE_CHAR_TYPE_HALANT:        	
             case IRE_CHAR_TYPE_DEPVOWEL:        	
             case IRE_CHAR_TYPE_SIGN:
                 return MMI_FALSE;
                 break;       
             default:
                 break;
         }
     }
     else
     {
         previous_char_type = ire_identify_character_type(previous_char);
         switch(current_char_type)
         {
             case IRE_CHAR_TYPE_HALANT: 
             case IRE_CHAR_TYPE_DEPVOWEL:    
                 if((previous_char_type != IRE_CHAR_TYPE_CON) 
                     || (!IRE_IS_PREV_CURR_SAME_LANG(previous_char,Unicode[0])))
                 {
                     return MMI_FALSE;
                 }
                 break;
             case IRE_CHAR_TYPE_SIGN:
                 switch(previous_char_type)
                 {
                     case IRE_CHAR_TYPE_CON:
                     case IRE_CHAR_TYPE_INDEPVOWEL:
                     case IRE_CHAR_TYPE_DEPVOWEL:
                         if(!IRE_IS_PREV_CURR_SAME_LANG(previous_char,Unicode[0]))
                         {
                             return MMI_FALSE;
                         }
                     break;
                     default:
                         return MMI_FALSE;
                 }
                 break;       
         }
     }
     return MMI_TRUE; 
}
#endif
/* PMT END MAUI_00031694 */

/* PMT END MAUI_00027833 */

/* PMT START MAUI_00027829 */
#endif
/* PMT END MAUI_00027829 */