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
 * EbookFramework.c
 *
 * Project:
 * --------MMI_CARD_DRV
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
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Ebook Application implementation *********************/

/**************************************************************

   FILENAME : EbookFramework.c

   PURPOSE     : Framework Application Functions

   REMARKS     : nil

   AUTHOR      : Rajat Kumar

   DATE     : 

**************************************************************/
#include "MMI_include.h"

#ifdef __MMI_EBOOK_READER__
#include "gpioInc.h"
#include "EbookDefs.h"
#include "CommonScreens.h"
#include "FileMgr.h"
#include "EbookManager.h"
#include "EbookProt.h"
#include "FileManagerDef.h"
#include "Conversions.h"
#include "FileManagerGProt.h"
#include "fmt_struct.h"
#include "PhoneSetupGprots.h"
#include "CallManagementGprot.h"
/*PMT IRE START*/
#if defined ( __MMI_INDIC_ALG__)
#include "IndicEngineGprot.h"
#endif
/*PMT IRE END*/
#ifdef __MMI_BPP_SUPPORT__
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#endif /* __MMI_BPP_SUPPORT__ */ 
g_current_book_context g_curr_bk_cntx;
g_current_book_context *g_curr_book_cntx_p = &g_curr_bk_cntx;
S8 *HW_itoa(S32 value, S8 *s, S32 radix);
S32 HW_atoi(const S8 *s);

#define MAX_FAILURE_RETRIES     5
#define MAX_RECORD_CONVERT_EACH_RECURSION    8
#define WHITE_SPACE 0x20

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_open_book_create_nfo_file_pdb
 * DESCRIPTION
 *  Create Nfo File for PDB
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
ebr_frm_nfo_create_type_errors_enum ebr_frm_open_book_create_nfo_file_pdb(U8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    FS_HANDLE file_hnd, nfo_hnd;
    S32 write_result;
    U8 ebook_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    ebr_frm_database_hdr_type file_header;
    S32 local_nfo_id = -1, compare_type = 0, isValidNfo = 0;

    S32 offset;
    S32 create_nfo_file = 0;
    ebr_frm_nfo_create_type_errors_enum return_value = EBR_FRM_NFO_CREATE_SUCCESS;
    doc_record0 rec0;
    S32 attr = 0;
    U32 nfo_file_size, book_file_size;
	pBOOL is_read_only = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) ebook_file_name,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) ebook_file_name, (PS8) filename);
    attr = FS_GetAttributes((const WCHAR*)ebook_file_name);
    if (attr & FS_ATTR_READ_ONLY)
    {
        is_read_only = TRUE;
        FS_SetAttributes((const WCHAR*)ebook_file_name, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
    }
    file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_WRITE);
    if (!file_hnd)
    {
        return EBR_FRM_NFO_CREATE_FAILURE;
    }
    if (FS_Read(file_hnd, &file_header, EBR_FRM_DATABASE_HEADER_SIZE, &size) == FS_NO_ERROR)
    {
        if (file_header.modification_date > 32768)
        {
            create_nfo_file = 1;
        }
        else
        {   /* Check that the cerrseponding nfo file exists or not if not then change the header information */
            nfo_hnd = FS_Open((const WCHAR*)ebr_frm_get_nfo_file_name((S32) file_header.modification_date), FS_READ_ONLY);
            if (nfo_hnd <= 0)
            {
                create_nfo_file = 1;
            }
            else
            {
                FS_Read(
                    nfo_hnd,
                    &g_curr_book_cntx_p->g_nfo_book_struct,
                    sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
                    &size);
                FS_GetFileSize(nfo_hnd, &nfo_file_size);
                isValidNfo = strncmp(
                                (const S8*)g_curr_book_cntx_p->g_nfo_book_struct.checksum,
                                (const S8*)EBR_TXT_FOOTER_START,
                                TXT_FOOTER_START_SIZE);
                compare_type = mmi_ucs2cmp(
                                (const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
                                (const S8*)g_curr_book_cntx_p->nfo_name);
                if ((compare_type != 0) || (isValidNfo != 0) ||
                    (nfo_file_size != sizeof(g_curr_book_cntx_p->g_nfo_book_struct)))
                {
                    create_nfo_file = 1;
                }
                FS_Close(nfo_hnd);
            }
        }
    }
    if (create_nfo_file)
    {
        if (memcmp(file_header.type, DOC_TYPE, strlen((PS8) DOC_TYPE)) == 0)
        {
            if (FS_Read(file_hnd, &offset, 4, &size) == FS_NO_ERROR)
            {
                offset = ntohl(offset);
            }
            FS_GetFileSize(file_hnd, &book_file_size);
            /* If header of file is invalid, FS may be corrupted by FS_Seek */
            if (offset < book_file_size) 
            {
                FS_Seek(file_hnd, offset, FS_FILE_BEGIN);   
                if (FS_Read(file_hnd, &rec0, sizeof rec0, &size) == FS_NO_ERROR)
                {
                    g_curr_book_cntx_p->num_records = ntohs(rec0.num_records);
                    g_curr_book_cntx_p->g_nfo_book_struct.book_size = ntohl(rec0.doc_size);
                    if (ebr_frm_is_empty_file(file_hnd, EBR_FRM_FILE_TYPE_PDB))
                    {
                        create_nfo_file = 1;
                        return_value = EBR_FRM_EMPTY_BOOK;
                        memset(g_curr_book_cntx_p->nfo_path, 0, sizeof(g_curr_book_cntx_p->nfo_path));
                        FS_Close(file_hnd);
                        return return_value;
                    }
                }
                mmi_ucs2cpy(
                    (S8*) ebook_file_name,
                    (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
                local_nfo_id = ebr_frm_create_nfo_file(file_header.name, ebook_file_name, filename);
            }                                    
            if (local_nfo_id >= 0)
            {
                file_header.modification_date = local_nfo_id;
                if (g_curr_book_cntx_p->src_application == EBR_FRM_SRC_APP_FMGR)
                {   /* Means it is from file manager */
                    ebr_frm_fmgr_set_nfo_id(local_nfo_id);
                }
                FS_Seek(file_hnd, 0, FS_FILE_BEGIN);
                write_result = FS_Write(file_hnd, &file_header, EBR_FRM_DATABASE_HEADER_SIZE, (U32*) & size);
                return_value = EBR_FRM_NFO_CREATE_SUCCESS;
            }
            else
            {
                return_value = EBR_FRM_NFO_CREATE_FAILURE;
            }
        }
        else
        {
            return_value = EBR_FRM_NFO_CREATE_FILE_TYPE_NOT_SUPPORTED;
        }

    }
    FS_Close(file_hnd);
    mmi_ucs2cpy(
        (S8*) ebook_file_name,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) ebook_file_name, (PS8) filename);
    attr = FS_GetAttributes((const WCHAR*)ebook_file_name);
	if(is_read_only)
	{
		FS_SetAttributes((const WCHAR*)ebook_file_name, (U8) (attr | (FS_ATTR_READ_ONLY)));	
	}
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_open_book_create_nfo_file_txt
 * DESCRIPTION
 *  Create Nfo File for TXT
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
ebr_frm_nfo_create_type_errors_enum ebr_frm_open_book_create_nfo_file_txt(U8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    FS_HANDLE file_hnd, nfo_hnd;
    S8 tmp_str[MAX_EBOOK_NAME_LENGTH];
    U8 ebook_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    U8 display_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    S32 create_nfo_file = 0, compare_type = 0, isValidNfo = 0, size_check = 0;
    S32 local_nfo_id;
    U32 strlength = 0;
    ebr_frm_nfo_create_type_errors_enum return_value = EBR_FRM_NFO_CREATE_SUCCESS;
    S32 attr = 0;
    U32 nfo_file_size, book_file_size;
	pBOOL is_read_only = FALSE;
	S16 error, previous_nfo_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) ebook_file_name,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) ebook_file_name, (S8*) filename);
    attr = FS_GetAttributes((const WCHAR*)ebook_file_name);
    if (attr & FS_ATTR_READ_ONLY)
    {
        is_read_only = TRUE;
        FS_SetAttributes((const WCHAR*)ebook_file_name, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
    }
    file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_WRITE);
    if (file_hnd > 0)
    {
        FS_GetFileSize(file_hnd, &g_curr_book_cntx_p->g_nfo_book_struct.book_size);
		book_file_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
        /* g_curr_book_cntx_p->g_nfo_book_struct.book_size=g_curr_book_cntx_p->g_nfo_book_struct.book_size-TXT_FOOTER_END_SIZE-MAX_EBOOK_NAME_LENGTH-TXT_FOOTER_START_SIZE; */
        if (ebr_frm_is_empty_file(file_hnd, EBR_FRM_FILE_TYPE_TXT))
        {
            create_nfo_file = 1;
            return_value = EBR_FRM_EMPTY_BOOK;
            memset(g_curr_book_cntx_p->nfo_path, 0, sizeof(g_curr_book_cntx_p->nfo_path));
            goto end;
        }
            FS_Close(file_hnd);
            local_nfo_id = ebr_fmgr_get_nfo_id_for_txt_file(g_curr_book_cntx_p->memory_type_selected, (PS8) filename);
        file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_WRITE);
        if (local_nfo_id != 0)
        {
            nfo_hnd = FS_Open((const WCHAR*)ebr_frm_get_nfo_file_name((S32) local_nfo_id), FS_READ_ONLY);
            if (nfo_hnd <= 0)
            {
                create_nfo_file = 1;
                FS_Seek(file_hnd, -TXT_FOOTER_START_SIZE - TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH, FS_FILE_END);
                g_curr_book_cntx_p->g_nfo_book_struct.book_size =
                            g_curr_book_cntx_p->g_nfo_book_struct.book_size + (-TXT_FOOTER_START_SIZE -
                                                                       TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH);
                FS_Truncate(file_hnd);
            }
            else
            {
                FS_Read(
                    nfo_hnd,
                    &g_curr_book_cntx_p->g_nfo_book_struct,
                    sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
                    &size);
                FS_GetFileSize(nfo_hnd, &nfo_file_size);
                isValidNfo = strncmp(
                                (const S8*)g_curr_book_cntx_p->g_nfo_book_struct.checksum,
                                (const S8*)EBR_TXT_FOOTER_START,
                                TXT_FOOTER_START_SIZE);
                compare_type = mmi_ucs2cmp(
                                (const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
                                (const S8*)g_curr_book_cntx_p->nfo_name);

                if (g_curr_book_cntx_p->g_nfo_book_struct.fs_file_size != book_file_size)
                {
                    size_check =  1;                    
                }                
                if ((compare_type != 0) || (isValidNfo != 0) || (size_check != 0) || 
                    (nfo_file_size != sizeof(g_curr_book_cntx_p->g_nfo_book_struct)))
                {
					book_file_size =
                                book_file_size + (-TXT_FOOTER_START_SIZE -
                                TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH);
					g_curr_book_cntx_p->g_nfo_book_struct.book_size = book_file_size;
                    create_nfo_file = 1;	
					FS_Seek(file_hnd, -TXT_FOOTER_START_SIZE - TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH, FS_FILE_END);                
					FS_Truncate(file_hnd);					
					/*Reset previous nfo file */
                    ReadValue(NVRAM_EBOOK_NFO_LID, (void*)&previous_nfo_id, DS_SHORT, &error);
                    if (local_nfo_id == previous_nfo_id)
                    {
                        previous_nfo_id = 0;
                        WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&previous_nfo_id, DS_SHORT, &error);
                    }
                }
                else
                {
                    return_value = EBR_FRM_NFO_CREATE_SUCCESS;
                }
                FS_Close(nfo_hnd);
            }
        }
        else
        {
            create_nfo_file = 1;
        }
    }
    else
    {
        return_value = EBR_FRM_NFO_CREATE_FAILURE;
    }
    if (create_nfo_file)
    {
        strlength = mmi_ucs2strlen((const S8*)filename);
        mmi_ucs2ncpy((S8*) display_name, (S8*) filename, strlength - EBR_EXTENSION_NAME_LENGTH - 1);
        local_nfo_id = ebr_frm_create_nfo_file(display_name, ebook_file_name, filename);
        if (local_nfo_id >= 0)
        {
            memset(tmp_str, 0, MAX_EBOOK_NAME_LENGTH);
            if (g_curr_book_cntx_p->src_application == EBR_FRM_SRC_APP_FMGR)
            {   /* Means it is from file manager */
                ebr_frm_fmgr_set_nfo_id(local_nfo_id);
            }
            HW_itoa(g_curr_book_cntx_p->g_last_nfo_id_allocated, (S8*) tmp_str, 10);
            FS_Seek(file_hnd, 0, FS_FILE_END);
            FS_Write(file_hnd, EBR_TXT_FOOTER_START, TXT_FOOTER_START_SIZE, &size);
            FS_Write(file_hnd, tmp_str, MAX_EBOOK_NAME_LENGTH, &size);
            FS_Write(file_hnd, EBR_TXT_FOOTER_END, TXT_FOOTER_END_SIZE, &size);
            return_value = EBR_FRM_NFO_CREATE_SUCCESS;
        }
        else
        {
            return_value = EBR_FRM_NFO_CREATE_FAILURE;
        }
    }
  end:
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->book_name_path, (PS8) ebook_file_name);
    FS_Close(file_hnd);
	attr = FS_GetAttributes((const WCHAR*)ebook_file_name);
	if(is_read_only)
	{
		FS_SetAttributes((const WCHAR*)ebook_file_name, (U8) (attr | (FS_ATTR_READ_ONLY)));
	}
    return return_value;
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_is_empty_file
 * DESCRIPTION
 *  Check if it is an empty file
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL ebr_frm_is_empty_file(FS_HANDLE file_hnd, ebr_frm_filetype_enum type)
{
    U32 filesize, size, offset;
    S8 file_header[TXT_FOOTER_START_SIZE];
    S8 UCS2empty[2] = {0xFF, 0xFE};
    S8 UCS2BEempty[2] = {0xFE, 0xFF};
    S8 UTF8empty[3] = {0xEF, 0xBB, 0xBF};   

    memset(&file_header, 0, TXT_FOOTER_START_SIZE);
    
    if (type == EBR_FRM_FILE_TYPE_TXT)
    {               
        FS_GetFileSize(file_hnd, &filesize);
        FS_Read(file_hnd, &file_header, TXT_FOOTER_START_SIZE, &size);
        
        /* g_curr_book_cntx_p->g_nfo_book_struct.book_size=g_curr_book_cntx_p->g_nfo_book_struct.book_size-TXT_FOOTER_END_SIZE-MAX_EBOOK_NAME_LENGTH-TXT_FOOTER_START_SIZE; */
        if (filesize == 0)
        {
            return MMI_TRUE;
        }
        else if (strlen(file_header) == 0)
        {
            return MMI_TRUE;
        }
        else if (mmi_ucs2strlen(file_header) == 1 && (strncmp(file_header, UCS2empty, 2) == 0 || strncmp(file_header, UCS2BEempty, 2) == 0))
        {
            return MMI_TRUE;
        }
        else if (strlen(file_header) == 3 && strncmp(file_header, UTF8empty, 3) == 0)
        {
            return MMI_TRUE;
        }
        else if(strncmp((S8*)file_header, (S8*) EBR_TXT_FOOTER_START, (U32)TXT_FOOTER_START_SIZE) == 0
                && filesize == (TXT_FOOTER_START_SIZE + TXT_FOOTER_END_SIZE + MAX_EBOOK_NAME_LENGTH))
        {
            return MMI_TRUE;
        }
        return MMI_FALSE;
    }
    else
    {
        if (g_curr_book_cntx_p->g_nfo_book_struct.book_size == 0)
        {
            return TRUE;
        }
        else if (g_curr_book_cntx_p->g_nfo_book_struct.book_size == 1)
        {
            SEEK_REC_ENTRY(file_hnd, 1);
            if (FS_Read(file_hnd, &offset, 4, (U32*) & size) == FS_NO_ERROR)
            {
                offset = ntohl(offset);
            }        
            if (FS_Seek(file_hnd, offset, FS_FILE_BEGIN) != FS_INVALID_FILE_POS)
            {
                FS_Read(file_hnd, file_header, TXT_FOOTER_START_SIZE, (U32*) &size);
            }
            if (file_header[0] == 0x20)
            {
                return TRUE;
            }
        }
        else /*The book size is not 0, but there's no content in the file (MAUI_00234787)*/
        {
            FS_GetFileSize(file_hnd, &filesize);

            FS_Seek(file_hnd, EBR_FRM_DATABASE_HEADER_SIZE, FS_FILE_BEGIN);
            if (FS_Read(file_hnd, &offset, 4, (U32*) & size) == FS_NO_ERROR)
            {
                offset = ntohl(offset);
            }    
            size = offset + sizeof(doc_record0);
            if (filesize <= size)
            {
                return TRUE;
            }
        }
        return FALSE;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_nfo_file_name
 * DESCRIPTION
 *  Get Nfo File Name.
 * PARAMETERS
 *  local_nfo_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 *ebr_frm_get_nfo_file_name(S32 local_nfo_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 nfo_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    static S32 prev_local_nfo_id = -1;
    S8 nfo_file_name_prefix_ascii[MAX_EBOOK_NAME_LENGTH - 3];   /* Extension length subtracted */
    S8 nfo_file_name_prefix_ucs2[(MAX_EBOOK_NAME_LENGTH - 3) * ENCODING_LENGTH];
    UI_string_type temp_str[MAX_EBOOK_NAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((prev_local_nfo_id == local_nfo_id) && (mmi_ucs2ncmp((S8*)nfo_file_name,(S8*)&(g_curr_book_cntx_p->memory_type_selected), 1) == 0))
    {
        return nfo_file_name;
    }
    mmi_ucs2cpy(
        (S8*) nfo_file_name,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    sprintf(nfo_file_name_prefix_ascii, "%08d", local_nfo_id);
    mmi_asc_to_ucs2((PS8) nfo_file_name_prefix_ucs2, (PS8) nfo_file_name_prefix_ascii);
    mmi_ucs2cat((PS8) nfo_file_name, nfo_file_name_prefix_ucs2);
    mmi_asc_to_ucs2((PS8) temp_str, (PS8) EBR_EBOOK_NFO_FILE_EXT);
    mmi_ucs2cat((PS8) nfo_file_name, (PS8) temp_str);
    prev_local_nfo_id = local_nfo_id;
    return nfo_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_create_nfo_file
 * DESCRIPTION
 *  Create Nfo File for TXT and PDB
 * PARAMETERS
 *  display_name                    [IN]        
 *  ebook_file_name_with_path       [IN]        
 *  ebook_file_name                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_create_nfo_file(U8 *display_name, U8 *ebook_file_name_with_path, U8 *ebook_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;

    S32 return_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_find_next_nfo_id();
    file_hnd = FS_Open(
                (const WCHAR*)ebr_frm_get_nfo_file_name(++g_curr_book_cntx_p->g_last_nfo_id_allocated),
                FS_CREATE | FS_ATTR_HIDDEN);
    if (file_hnd != 0)
    {
        return_val = ebr_frm_fill_nfo_file(file_hnd, display_name, (U8*) ebook_file_name);
        FS_Close(file_hnd);
        if (return_val == 0)
        {
            FS_Delete((const WCHAR*)
                      ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
            return -1;
        }
        else
        {
            return g_curr_book_cntx_p->g_last_nfo_id_allocated;
        }
    }
    else
    {
        return -1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fill_nfo_file
 * DESCRIPTION
 *  Fill the NFO file
 * PARAMETERS
 *  file_hnd            [IN]        
 *  display_name        [IN]        
 *  ebook_file_name     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 ebr_frm_fill_nfo_file(FS_HANDLE file_hnd, U8 *display_name, U8 *ebook_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ebr_frm_book_struct book_struct;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;
    U8 i;
    U32 size;
    S16 error;
    S32 write_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) book_struct.e_book_name, (PS8) ebook_file_name);
    mmi_ucs2cpy((PS8) book_struct.display_name, (PS8) display_name);
    book_struct.book_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
    book_struct.fs_file_size = book_struct.book_size +
    (TXT_FOOTER_START_SIZE + TXT_FOOTER_END_SIZE + MAX_EBOOK_NAME_LENGTH);
    book_struct.temp_book_size = 0;
    book_struct.temp_encoding_file_format = '\0';
    book_struct.current_page_id = 0;
    book_struct.offset = 0;
    book_struct.jump_offset = 0;
    book_struct.last_showed_percentage = 0;
    book_struct.last_text_offset_y = 0;
    book_struct.is_short = g_curr_book_cntx_p->is_short;
    for (i = 0; i < EBR_FRM_MAX_NO_OF_BOOKMARKS; i++)
    {
        book_struct.book_marks[i].offset = 0;
        book_struct.book_marks[i].page_id = 0;
        mmi_ucs2cpy((PS8) book_struct.book_marks[i].bookmark_name, (PS8) NULL);
        book_struct.book_marks[i].percentage_associated_with_book_mark = 0;
    }
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
    book_struct.settings = g_setting_list->common_settings;
    strcpy((char*)book_struct.checksum, (const char*)EBR_TXT_FOOTER_START);
    if ((write_result = FS_Write(file_hnd, &book_struct, sizeof(ebr_frm_book_struct), (U32*) & size)) == FS_NO_ERROR)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_nfo_id_from_file_name
 * DESCRIPTION
 *  Get the next NFO from File
 * PARAMETERS
 *  file_name_without_path      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_get_nfo_id_from_file_name(U8 *file_name_without_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 previous_file_name[MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH];
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (file_name_without_path[i * 2] != '.')
    {
        previous_file_name[i] = file_name_without_path[i * 2];
        i++;
    }
    previous_file_name[i] = 0;
    return HW_atoi((const S8*)previous_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_find_next_nfo_id
 * DESCRIPTION
 *  Get the next NFO id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_find_next_nfo_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    S32 file_attr = 0;
    S16 nfo_id_from_middle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nfo_id_from_middle == 0)
    {
        count++;
        file_attr = FS_GetAttributes((const WCHAR*)ebr_frm_get_nfo_file_name(count));
        if (file_attr == FS_FILE_NOT_FOUND)
        {
            nfo_id_from_middle = 1;
        }
    }
    g_curr_book_cntx_p->g_last_nfo_id_allocated = --count;    
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_delete_unused_nfo_file
 * DESCRIPTION
 *  Delete invalid NFO files.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_delete_unused_nfo_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    U8 filename[MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_NFO));
    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
    {
        do
        {
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                ebr_frm_open_nfo_file_and_delete_unused_nfo(filename);
            }
        } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                  FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_open_nfo_file_and_delete_unused_nfo
 * DESCRIPTION
 *  Delete invalid NFO files.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_open_nfo_file_and_delete_unused_nfo(U8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];
    S8 file_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH + ENCODING_LENGTH];
    FS_HANDLE nfo_hnd, file_hnd;
    U32 size, nfo_file_size;
    S32 nfo_id, strlen_file_name;
    pBOOL isValidNfo = FALSE;
    S32 local_nfo_id;
    S8 nfo_file_name[NFO_FILE_NAME_LENGTH] = {0};
    S8 nfo_file[NFO_FILE_NAME_VALUE] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) nfo_file_name, (S8*) filename);
    strncpy((S8*) nfo_file, (S8*) nfo_file_name, NFO_FILE_NAME_VALUE - 1);
    nfo_file[NFO_FILE_NAME_VALUE-1] = '\0';
    local_nfo_id = HW_atoi((const S8*)nfo_file);
    mmi_ucs2cpy(
        (S8*) nfo_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) nfo_path, (S8*) filename);
    nfo_hnd = FS_Open((const WCHAR*)nfo_path, FS_READ_ONLY);
    FS_Read(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
    FS_GetFileSize(nfo_hnd, &nfo_file_size);
    if ((!strncmp
         ((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.checksum, (const S8*)EBR_TXT_FOOTER_START,
          TXT_FOOTER_START_SIZE)) && (nfo_file_size == sizeof(g_curr_book_cntx_p->g_nfo_book_struct)))
    {
        isValidNfo = TRUE;
    }
    else
    {
        isValidNfo = FALSE;
    }
    FS_Close(nfo_hnd);
    if (isValidNfo)
    {
    strlen_file_name = mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);

    if ((g_curr_book_cntx_p->g_nfo_book_struct.e_book_name[strlen_file_name * 2 - 6] == 'p') ||
        (g_curr_book_cntx_p->g_nfo_book_struct.e_book_name[strlen_file_name * 2 - 6] == 'P'))
    {
        g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_PDB;
    }
    else
    {
        g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_TXT;
    }
        mmi_ucs2ncpy(
            (S8*) file_path,
            (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT),
            MAX_DWNL_EBK_PATH_LEN);
        mmi_ucs2ncat(
        (S8*) file_path,
            (S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
            MAX_DWNL_EBK_PATH_LEN - mmi_ucs2strlen((S8*) file_path));
    file_hnd = FS_Open((const WCHAR*)file_path, FS_READ_ONLY);
    if (file_hnd <= 0)
    {

            mmi_ucs2ncpy(
                (S8*) file_path,
                (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT),
                MAX_DWNL_EBK_PATH_LEN);
            mmi_ucs2ncat(
            (S8*) file_path,
                (S8*) g_curr_book_cntx_p->g_nfo_book_struct.temp_file_name,
                MAX_DWNL_EBK_PATH_LEN - mmi_ucs2strlen((S8*) file_path));
        file_hnd = FS_Open((const WCHAR*)file_path, FS_READ_ONLY);
        if (file_hnd >= 0)
        {
            FS_Close(file_hnd);
            FS_Delete((const WCHAR*)file_path);
        }
        FS_Delete((const WCHAR*)nfo_path);

    }
    else
    {
        FS_Close(file_hnd);
        if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT)
        {
            nfo_id = ebr_fmgr_get_nfo_id_for_txt_file(
                        g_curr_book_cntx_p->memory_type_selected,
                        (S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
        }
        else
        {
            nfo_id = ebr_fmgr_get_nfo_id_for_pdb_file(
                        g_curr_book_cntx_p->memory_type_selected,
                        (S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
        }
            if (nfo_id <= 0 || (nfo_id != local_nfo_id))
        {
            FS_Delete((const WCHAR*)nfo_path);
        }
    }
    }
    else
    {
        FS_Delete((const WCHAR*)nfo_path);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_entry_refresh_book_shelf
 * DESCRIPTION
 *  Refresh the book Shelf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_entry_refresh_book_shelf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_delete_unused_nfo_file();
    g_curr_book_cntx_p->ebr_frm_end_book_flag = 1;
    g_curr_book_cntx_p->ebr_search_strlen = 0;
    g_curr_book_cntx_p->highlight_string_flag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_total_countof_nfo_file
 * DESCRIPTION
 *  Get the total count for nfo files
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 count
 *****************************************************************************/
S32 ebr_frm_get_total_countof_nfo_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    UI_character_type filename[MAX_EBOOK_NAME_LENGTH];
    U8 count = 0;
    S8 path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_PDB));

    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
    {
        do
        {

            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                count++;
                break;
            }
        } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                  FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }
    if (count > 0)
    {
        return count;
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) path,
            (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_TXT));
        if ((fh_cur = FS_FindFirst(
                        (const WCHAR*)path,
                        0,
                        0,
                        &file_info,
                        (U16*) filename,
                        MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
        {
            do
            {

                if (!(file_info.Attributes & FS_ATTR_DIR))
                {
                    count++;
                    break;
                }
            } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                      FS_NO_ERROR));
            FS_FindClose(fh_cur);
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_file_path
 * DESCRIPTION
 *  Get the file path
 * PARAMETERS
 *  memory_type_selected        [IN]        
 *  search_type_path            [IN]        
 * RETURNS
 *  S32 count
 *****************************************************************************/
S8 *ebr_frm_get_file_path(S8 memory_type_selected, ebr_frm_search_type_enum search_type_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_path_in_ascii[MAX_DWNL_EBK_PATH_LEN];
    static S8 file_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    static ebr_frm_search_type_enum prev_search_type_path = EBR_FRM_SEARCH_MAX;    
    static S8 prev_memory_type_selected = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prev_memory_type_selected == memory_type_selected && prev_search_type_path == search_type_path)
    {
        return file_path;
    }

    switch (search_type_path)
    {
        case EBR_FRM_SEARCH_NFO:
            sprintf((char*)file_path_in_ascii, "%c%s%s", memory_type_selected, EBR_DOWNLOADED_EBOOK_PATH, EBR_EBOOK_SEARCH_NFO_STR);
            break;
        case EBR_FRM_SEARCH_PDB:
            sprintf((char*)file_path_in_ascii, "%c%s%s", memory_type_selected, EBR_DOWNLOADED_EBOOK_PATH, EBR_EBOOK_SEARCH_PDB_STR);
            break;
        case EBR_FRM_SEARCH_TXT:
            sprintf((char*)file_path_in_ascii, "%c%s%s", memory_type_selected, EBR_DOWNLOADED_EBOOK_PATH, EBR_EBOOK_SEARCH_TXT_STR);
            break;
        case EBR_FRM_SEARCH_TXZ:
            sprintf((char*)file_path_in_ascii, "%c%s%s", memory_type_selected, EBR_DOWNLOADED_EBOOK_PATH, EBR_EBOOK_SEARCH_TXZ_STR);
            break;
        case EBR_FRM_SEARCH_PBZ:
            sprintf((char*)file_path_in_ascii, "%c%s%s", memory_type_selected, EBR_DOWNLOADED_EBOOK_PATH, EBR_EBOOK_SEARCH_PBZ_STR);
            break;
        default:
            sprintf((char*)file_path_in_ascii, "%c%s", memory_type_selected, EBR_DOWNLOADED_EBOOK_PATH);
            break;

    }
    mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);
    prev_memory_type_selected = memory_type_selected;
    prev_search_type_path = search_type_path;
    return file_path;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_path_for_bookshelf
 * DESCRIPTION
 *  Get the book shelf path
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 count
 *****************************************************************************/
S8 *ebr_frm_get_path_for_bookshelf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_number_of_records
 * DESCRIPTION
 *  Set number of records
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_number_of_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.book_size % EBR_RECORD_SIZE_MAX == 0)
    {
        g_curr_book_cntx_p->num_records = g_curr_book_cntx_p->g_nfo_book_struct.book_size / EBR_RECORD_SIZE_MAX;
    }
    else
    {
        g_curr_book_cntx_p->num_records = g_curr_book_cntx_p->g_nfo_book_struct.book_size / EBR_RECORD_SIZE_MAX + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_temp_number_of_records
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_temp_number_of_records(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size % EBR_RECORD_SIZE_MAX == 0)
    {
        g_curr_book_cntx_p->num_records = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size / EBR_RECORD_SIZE_MAX;
    }
    else
    {
        g_curr_book_cntx_p->num_records =
            g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size / EBR_RECORD_SIZE_MAX + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_record_in_passed_buffer
 * DESCRIPTION
 *  Copy the data in previous buffer
 * PARAMETERS
 *  file_hnd            [IN]        
 *  record_id           [IN]        
 *  output_buffer       [IN]        
 *  input_buffer        [IN]        
 *  size                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void copy_record_in_passed_buffer(FS_HANDLE file_hnd, S32 record_id, U8 *output_buffer, U8 *input_buffer, U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size;
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        rec_size = ebr_frm_get_record_size_txt(record_id);

        if (record_id >= 1) /* first record */
        {
            record_id -= 1;
        }
        FS_Seek(file_hnd, (record_id) * EBR_RECORD_SIZE_MAX, FS_FILE_BEGIN);
        FS_Read(file_hnd, g_curr_book_cntx_p->buffer, rec_size, size);
    }
    else
    {
        SEEK_REC_ENTRY(file_hnd, record_id);
        if (FS_Read(file_hnd, &offset, 4, size) == FS_NO_ERROR)
        {
            offset = ntohl(offset);
        }
        rec_size = ebr_frm_get_record_size_pdb(file_hnd, offset, record_id);
        FS_Seek(file_hnd, offset, FS_FILE_BEGIN);
        FS_Read(file_hnd, input_buffer, rec_size, size);
        ebr_frm_start_decompression(output_buffer, input_buffer, size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_record_in_buffer
 * DESCRIPTION
 *  Copy the data in current buffer
 * PARAMETERS
 *  file_hnd        [IN]        
 *  record_id       [IN]        
 *  copy_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void copy_record_in_buffer(FS_HANDLE file_hnd, S32 record_id, ebr_frm_copy_type_enum copy_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size;
    S32 offset;
    S32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT || g_curr_book_cntx_p->pdb_converted_to_text)
    {
        switch (copy_type)
        {
            case EBR_FRM_COPY_TYPE_FIRST:
                memset(g_curr_book_cntx_p->start, 0, EBR_RECORD_SIZE_MAX * 2);
                offset = 0;
                break;
            case EBR_FRM_COPY_TYPE_SECOND:
                memset(g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, 0, EBR_RECORD_SIZE_MAX);
                offset = EBR_RECORD_SIZE_MAX;
                break;
            case EBR_FRM_COPY_TYPE_NEXT:
                memcpy(g_curr_book_cntx_p->start, g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, EBR_RECORD_SIZE_MAX);
                /* mmi_ucs2cpy((PS8)g_curr_book_cntx_p->start,(PS8)g_curr_book_cntx_p->start+EBR_RECORD_SIZE_MAX); */
                memset(g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, 0, EBR_RECORD_SIZE_MAX);
                offset = EBR_RECORD_SIZE_MAX;
                break;
            case EBR_FRM_COPY_TYPE_PREVIOUS:
                memcpy(g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, g_curr_book_cntx_p->start, EBR_RECORD_SIZE_MAX);
                memset(g_curr_book_cntx_p->start, 0, EBR_RECORD_SIZE_MAX);
                offset = 0;
                break;
        }
        rec_size = ebr_frm_get_record_size_txt(record_id);
        FS_Seek(file_hnd, (record_id - 1) * EBR_RECORD_SIZE_MAX, FS_FILE_BEGIN);
        FS_Read(file_hnd, g_curr_book_cntx_p->start + offset, rec_size, (U32*) & size);
    }
    else
    {
        SEEK_REC_ENTRY(file_hnd, record_id);
        if (FS_Read(file_hnd, &offset, 4, (U32*) & size) == FS_NO_ERROR)
        {
            offset = ntohl(offset);
        }
        rec_size = ebr_frm_get_record_size_pdb(file_hnd, offset, record_id);
        if (rec_size < 0 || (rec_size > EBR_RECORD_SIZE_MAX))
        {
            g_curr_book_cntx_p->is_in_valid = TRUE;
        }
        else
        {
            if (FS_Seek(file_hnd, offset, FS_FILE_BEGIN) != FS_INVALID_FILE_POS)
            {
        FS_Read(file_hnd, &g_curr_book_cntx_p->buffer, rec_size, (U32*) & size);
        ebr_frm_decompress_pdb((U8*) g_curr_book_cntx_p->buffer, (U32*) & size, copy_type);
    }
            else
            {
                g_curr_book_cntx_p->is_in_valid = TRUE;
                g_curr_book_cntx_p->gcurrent_record_id = g_curr_book_cntx_p->num_records;
            }
        }
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_data_during_scrolling
 * DESCRIPTION
 *  Copy the data in buffer_local during scrolling
 * PARAMETERS
 *  page_id             [IN]        
 *  buffer_local        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_data_during_scrolling(S32 percentage_val,PU8 buffer_local)
{
	S8 display_name[(MAX_EBOOK_NAME_LENGTH + 1) * ENCODING_LENGTH];
	gui_page_info_app ebook_frm_setting;
	if(percentage_val==100)
	{
		ebr_frm_jump_to_record(0,EBR_JUMP_END); 
		/* Here 0 is being passed as percentage value reason being ,Ebook application consider jump to end case 
		 when percentage value is 0 : During dragging of scrollbar to reach to end of the book,it is being added*/
	}
    else if (percentage_val == 0)
    {
        ebr_frm_jump_to_record(0,EBR_JUMP_BEGIN); 
    }
	else
	{
	ebr_frm_jump_to_record(percentage_val,EBR_JUMP_PERCENTAGE);
	}
	ebr_frm_get_data_to_open_book(&ebook_frm_setting,buffer_local, display_name);
	wgui_paging_set_page_info(&ebook_frm_setting);
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_decode_header
 * DESCRIPTION
 *  Get the File Header for PDB and Footer for TXT file
 * PARAMETERS
 *  ebook_file_name     [IN]        
 * RETURNS
 *  S16 error_type
 *****************************************************************************/
S16 ebr_frm_decode_header(U8 *ebook_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    S16 ebr_page_size;
    S32 book_size = 0;

    //      FS_DiskInfo disk_info;
    //      S32 fs_ret;
    S8 file_path_in_ascii[5];
    S8 file_path[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      U64 disk_free_space;
    //  U64 disk_total_space;
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }
    file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
    if (file_hnd <= 0)
    {
        return file_hnd;
    }
    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        /* Create a new file in Unicode and change the book_size */
        S32 status;

        sprintf((char*)file_path_in_ascii, "%c", g_curr_book_cntx_p->memory_type_selected);
        strcat((char*)file_path_in_ascii, ":\\");
        mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);
        status = ebr_frm_create_temp_file_in_ucs2(file_hnd);

        if (status == 0)
        {
            FS_Close(file_hnd);
            return 0;
        }
        else if (status == 1)
        {
            return 1;
        }
        else if (status == 2)
        {
            ebr_frm_set_temp_number_of_records();
            FS_Close(file_hnd);
            file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_ONLY);
			book_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size;
        }
    }
    else
    {
        ebr_frm_set_number_of_records();
        ebr_frm_delete_temp_file();
		book_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
    }

    if (!g_curr_book_cntx_p->ebr_frm_end_book_flag ||
        (g_curr_book_cntx_p->g_nfo_book_struct.current_page_id + 4) * ebr_page_size >= (U32) book_size)
    {
        if (book_size > EBR_RECORD_SIZE_MAX)
        {
            g_curr_book_cntx_p->gcurrent_record_id = g_curr_book_cntx_p->num_records - 1;
            g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;
        }
        else
        {
            g_curr_book_cntx_p->gcurrent_record_id =
                g_curr_book_cntx_p->g_start_id / (EBR_RECORD_SIZE_MAX / ebr_page_size) + 1;
            g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;

        }
    }
    else
    {
        g_curr_book_cntx_p->gcurrent_record_id =
            g_curr_book_cntx_p->g_start_id / (EBR_RECORD_SIZE_MAX / ebr_page_size) + 1;
        g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;
    }

    copy_record_in_buffer(file_hnd, g_curr_book_cntx_p->gcurrent_record_id, EBR_FRM_COPY_TYPE_FIRST);
	if(g_curr_book_cntx_p->book_is_in_other_encoding_format)
	{
		if(g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size>EBR_RECORD_SIZE_MAX)
		{
			copy_record_in_buffer(file_hnd, g_curr_book_cntx_p->gnext_record_id, EBR_FRM_COPY_TYPE_SECOND);
		}
	}
	else
	{
	if(g_curr_book_cntx_p->g_nfo_book_struct.book_size>EBR_RECORD_SIZE_MAX)
	{
    copy_record_in_buffer(file_hnd, g_curr_book_cntx_p->gnext_record_id, EBR_FRM_COPY_TYPE_SECOND);
	}
	}
    FS_Close(file_hnd);
    if (g_curr_book_cntx_p->is_in_valid)
    {
        g_curr_book_cntx_p->is_in_valid = FALSE;
        return 2;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_delete_temp_file
 * DESCRIPTION
 *  Get the record size for text file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_delete_temp_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL is_temp_file_present;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_create_temp_file_path();
    is_temp_file_present = ebr_frm_check_if_file_exists_or_not();
    if (is_temp_file_present)
    {
        FS_Delete((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path);
    }
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_current_recursive_conversion_state
 * DESCRIPTION
 *  Get the current conversion state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_get_current_recursive_conversion_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_curr_book_cntx_p->state_recursive_conversion;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_current_recursive_conversion_state
 * DESCRIPTION
 *  Set the current conversion state.
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_current_recursive_conversion_state(S32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->state_recursive_conversion = state;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_register_recursive_callback_fn
 * DESCRIPTION
 *  Reister Function for Recursive callback
 * PARAMETERS
 *  fn      [IN]        
 *  void (*fn)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_register_recursive_callback_fn(void (*fn) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->g_recursive_callback_fn = fn;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_stop_recursion
 * DESCRIPTION
 *  Stop the timer for Recursive callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_stop_recursion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EBOOK_RECURSIVE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_convert_record
 * DESCRIPTION
 *  Convert the record and write in temp file
 * PARAMETERS
 *  file_hnd            [IN]        
 *  new_file_hnd        [IN]        
 *  record_id           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_convert_record(FS_HANDLE file_hnd, FS_HANDLE new_file_hnd, S32 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size = 0;
    S32 total_bytes_converted = 0;
    S32 offset = 0;
    S32 size = 0;
    U32 static over_the_record_border = 0;
    S32 converted_str_len;
    U8 mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
    U32 src_using_size;
    U32 src_end_pos;
	static U8* tempArray[5];
	U8* buffer_start;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_id == 1)
    {
        over_the_record_border = 0;
    }
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT)
    {
        rec_size = ebr_frm_create_temp_file_txt(record_id) - over_the_record_border;
        if (rec_size > EBR_RECORD_SIZE_MAX)
        {
            rec_size = EBR_RECORD_SIZE_MAX;
            over_the_record_border = 0;
        }
        memset(g_curr_book_cntx_p->buffer, 0, sizeof(g_curr_book_cntx_p->buffer));
        FS_Read(file_hnd, g_curr_book_cntx_p->buffer, rec_size, (U32*) & size);
        memset(g_curr_book_cntx_p->start, 0, sizeof(g_curr_book_cntx_p->start));
        mmi_chset_use_space_for_unknown_character();
        switch (mmiEncoding)
        {
        #if defined(__MMI_CHSET_BIG5__)
            case MMI_CHSET_BIG5:
                total_bytes_converted = ebr_frm_mmi_chset_text_to_ucs2_str(
                                            file_hnd,
                                            (U8*) g_curr_book_cntx_p->start,
                                            EBR_RECORD_SIZE_MAX * 2 + 10,
                                            (U8*) g_curr_book_cntx_p->buffer,
                                            (S16) size,
                                            BIG_5_ENCODING_TYPE,
                                            &over_the_record_border);
                break;
        #endif /* defined(__MMI_CHSET_BIG5__) */ 
        #if defined(__MMI_CHSET_GB2312__)
            case MMI_CHSET_GB2312:
                total_bytes_converted = ebr_frm_mmi_chset_text_to_ucs2_str(
                                            file_hnd,
                                            (U8*) g_curr_book_cntx_p->start,
                                            EBR_RECORD_SIZE_MAX * 2 + 10,
                                            (U8*) g_curr_book_cntx_p->buffer,
                                            (S16) size,
                                            GB2312_ENCODING_TYPE,
                                            &over_the_record_border);
                break;
        #endif /* defined(__MMI_CHSET_GB2312__) */ 
            case MMI_CHSET_UTF8:
                total_bytes_converted = ebr_frm_mmi_chset_utf8_to_ucs2_string(
                                            file_hnd,
                                            (U8*) g_curr_book_cntx_p->start,
                                            EBR_RECORD_SIZE_MAX * 2 + 10,
                                            (U8*) g_curr_book_cntx_p->buffer,
                                            (S16) size,
                                            &over_the_record_border);
                break;
            default:
                total_bytes_converted = mmi_chset_convert(
                                            (mmi_chset_enum) mmiEncoding,
                                            MMI_CHSET_UCS2,
                                            (S8*) g_curr_book_cntx_p->buffer,
                                            (S8*) g_curr_book_cntx_p->start,
                                            EBR_RECORD_SIZE_MAX * 2 + 10);
                break;
        }
        mmi_chset_do_not_use_space_for_unknown_character();
        converted_str_len = mmi_ucs2strlen((S8*) g_curr_book_cntx_p->start);
        if (converted_str_len != (total_bytes_converted - 2) / 2)
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
        else if (mmiEncoding == MMI_CHSET_UTF8 && (total_bytes_converted - 2) < (size / 2))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
    #ifdef __MMI_CHSET_BIG5__
        else if (mmiEncoding == MMI_CHSET_BIG5 && (total_bytes_converted - 2) < (size))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
    #endif /* __MMI_CHSET_BIG5__ */ 
    #ifdef __MMI_CHSET_GB2312__
        else if (mmiEncoding == MMI_CHSET_GB2312 && (total_bytes_converted - 2) < (size))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
    #endif /* __MMI_CHSET_GB2312__ */ 
        else if (record_id == g_curr_book_cntx_p->num_records)
        {
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, total_bytes_converted, (U32*) & size);
        }
        else
        {
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, total_bytes_converted - 2, (U32*) & size);
        }

    }
    else
    {
        memset(g_curr_book_cntx_p->start, 0, sizeof(g_curr_book_cntx_p->start));
        src_end_pos = (U32)g_curr_book_cntx_p->buffer;
        g_curr_book_cntx_p->pdb_converted_to_text = TRUE;
        SEEK_REC_ENTRY(file_hnd, record_id);
        if (FS_Read(file_hnd, &offset, 4, (U32*) & size) == FS_NO_ERROR)
        {
            offset = ntohl(offset);
        }
        rec_size = ebr_frm_get_record_size_pdb(file_hnd, offset, record_id);
        if (rec_size < 0 || (rec_size > EBR_RECORD_SIZE_MAX))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            return;
        }
        if (FS_Seek(file_hnd, offset, FS_FILE_BEGIN) != FS_INVALID_FILE_POS)
        {
        FS_Read(file_hnd, g_curr_book_cntx_p->for_unicode_buffer, rec_size, (U32*) & size);
        }
        else
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            return;
        }
        if (size <= 0)
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            return;
        }
		if (over_the_record_border > 0)
		{
			memcpy(g_curr_book_cntx_p->buffer, tempArray, over_the_record_border);
		}
		buffer_start = g_curr_book_cntx_p->buffer + over_the_record_border;
        ebr_frm_start_decompression(buffer_start, g_curr_book_cntx_p->for_unicode_buffer, (U32*) & size);
        mmi_chset_use_space_for_unknown_character();
        total_bytes_converted = mmi_chset_convert_ex(
                                    (mmi_chset_enum) mmiEncoding,
                                    MMI_CHSET_UCS2,
                                    (char*)g_curr_book_cntx_p->buffer,
                                    (char*)g_curr_book_cntx_p->start,
                                    EBR_RECORD_SIZE_MAX * 2 + 10,
                                    &src_end_pos);
        src_using_size = src_end_pos - (U32)(g_curr_book_cntx_p->buffer);
        if (src_using_size < size + over_the_record_border)
        {
            /* some content doesn't convert from src buffer, we seek the file pointer */
			over_the_record_border = (over_the_record_border + size) - src_using_size;
            if (over_the_record_border <= EBR_MAX_OVER_THE_RECORD_BORDER)
            {
			    memcpy (tempArray, g_curr_book_cntx_p->buffer + src_using_size, over_the_record_border);			
            }
        }
		else
		{
			over_the_record_border = 0;
		}
        mmi_chset_do_not_use_space_for_unknown_character();
        converted_str_len = mmi_ucs2strlen((S8*) g_curr_book_cntx_p->start);
        if (converted_str_len != (total_bytes_converted - 2) / 2)
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
        else if (mmiEncoding == MMI_CHSET_UTF8 && (total_bytes_converted - 2) < (size / 2))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
    #ifdef __MMI_CHSET_BIG5__
        else if (mmiEncoding == MMI_CHSET_BIG5 && (total_bytes_converted - 2) < (size))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
    #endif /* __MMI_CHSET_BIG5__ */ 
    #ifdef __MMI_CHSET_GB2312__
        else if (mmiEncoding == MMI_CHSET_GB2312 && (total_bytes_converted - 2) < (size))
        {
            g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, (converted_str_len * 2) + 2, (U32*) & size);
        }
    #endif /* __MMI_CHSET_GB2312__ */ 
        if (record_id == g_curr_book_cntx_p->num_records)
        {
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, total_bytes_converted, (U32*) & size);
        }
        else
        {
            memset(g_curr_book_cntx_p->buffer, 0, sizeof(g_curr_book_cntx_p->buffer));
            FS_Write(new_file_hnd, g_curr_book_cntx_p->start, total_bytes_converted - 2, (U32*) & size);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_convert_record_record_recursively
 * DESCRIPTION
 *  Convert record recursively
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_convert_record_record_recursively(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    static U32 failure_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EBOOK_RECURSIVE_TIMER);
    if (g_curr_book_cntx_p->g_record_id <= g_curr_book_cntx_p->num_records)
    {
        FS_HANDLE file_hnd, new_file_hnd;
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
        if (g_curr_book_cntx_p->g_record_id == 1)
        {
            new_file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
            failure_count = 0;
        }
        else
        {
            new_file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_WRITE);
            if (file_hnd > 0)
            {
                FS_Seek(file_hnd, g_curr_book_cntx_p->g_file_hnd_offset, FS_FILE_BEGIN);
            }
            if (new_file_hnd > 0)
            {
                FS_Seek(new_file_hnd, 0, FS_FILE_END);
            }
        }
        if (new_file_hnd > 0 && file_hnd > 0)
        {
            S32 count = 0;

            while (count < MAX_RECORD_CONVERT_EACH_RECURSION)
            {
                ebr_frm_convert_record(file_hnd, new_file_hnd, g_curr_book_cntx_p->g_record_id);
                g_curr_book_cntx_p->g_record_id++;
                count++;
                if (g_curr_book_cntx_p->g_record_id > g_curr_book_cntx_p->num_records)
                {
                    break;
                }
            }
            g_curr_book_cntx_p->g_file_hnd_offset = FS_Seek(file_hnd, 0, FS_FILE_CURRENT);
            failure_count = 0;
        }
        else
        {
            failure_count++;
            if (failure_count == MAX_FAILURE_RETRIES)
            {
                g_curr_book_cntx_p->g_record_id = g_curr_book_cntx_p->num_records;
            }
        }
        if (file_hnd > 0)
        {
            FS_Close(file_hnd);
        }
        if (new_file_hnd > 0)
        {
            FS_Close(new_file_hnd);
        }
		if(file_hnd>0)
		{
            /* If ebook ecoding processure is in background, the priority should be reduced */
            if (GetExitScrnID() == SCR_ID_EBOOK_WAITSCREEN)
            {
                StartTimer(EBOOK_RECURSIVE_TIMER, 10, ebr_frm_convert_record_record_recursively);
            }
            else
            {
                StartTimer(EBOOK_RECURSIVE_TIMER, 3000, ebr_frm_convert_record_record_recursively);
            }

        }
        else
        {
            g_curr_book_cntx_p->state_recursive_conversion = EBR_FRM_NFO_CONVERSION_COMPLETED;
            if (GetExitScrnID() == SCR_ID_EBOOK_WAITSCREEN)
        	{
            	g_curr_book_cntx_p->g_recursive_callback_fn();
        	}
        	else
        	{
            	return;
        	}                    
        }
    }
    else
    {
        FS_HANDLE nfo_handle, new_file_hnd = 0;
        U8 nfo_extension_name[MAX_EBOOK_NAME_LENGTH];
        new_file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_WRITE);
        FS_Seek(new_file_hnd, 0, FS_FILE_END);
        nfo_handle = ebr_frm_get_nfo_handle();
        FS_Seek(nfo_handle, 0, FS_FILE_BEGIN);
        g_curr_book_cntx_p->g_nfo_book_struct.temp_encoding_file_format = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
        memset(g_curr_book_cntx_p->g_nfo_book_struct.temp_file_name, 0, MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH);
        mmi_ucs2ncat(
            (PS8) g_curr_book_cntx_p->g_nfo_book_struct.temp_file_name,
            (const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
            mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name) - 4);
        if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT)
        {
            mmi_asc_to_ucs2((S8*) nfo_extension_name, (S8*) TXT_TEMP_EXT_STR);
        }
        else
        {
            mmi_asc_to_ucs2((S8*) nfo_extension_name, (S8*) PDB_TEMP_EXT_STR);
        }
        mmi_ucs2cat((PS8) g_curr_book_cntx_p->g_nfo_book_struct.temp_file_name, (PS8) nfo_extension_name);
        FS_GetFileSize(new_file_hnd, &g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size);
        FS_Write(
            nfo_handle,
            &g_curr_book_cntx_p->g_nfo_book_struct,
            sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
            &size);

        FS_Close(nfo_handle);
        FS_Close(new_file_hnd);
        ebr_frm_set_temp_number_of_records();
        g_curr_book_cntx_p->state_recursive_conversion = EBR_FRM_NFO_CONVERSION_COMPLETED;
		if (GetExitScrnID() == SCR_ID_EBOOK_WAITSCREEN)
        {
            g_curr_book_cntx_p->g_recursive_callback_fn();
        }
        else
        {
            return;
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_create_temp_file_in_ucs2
 * DESCRIPTION
 *  Get the record size for text file.
 * PARAMETERS
 *  file_hnd        [IN]        
 * RETURNS
 *  S16 error_type
 *****************************************************************************/
S32 ebr_frm_create_temp_file_in_ucs2(FS_HANDLE file_hnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL is_temp_file_present = FALSE;
    FS_DiskInfo disk_info;
    U64 disk_free_space;
    U64 disk_total_space;
    S32 fs_ret;
    S8 file_path_in_ascii[5];
    S8 file_path[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_create_temp_file_path();
    /* NEERAJ START */
    FS_Seek(file_hnd, 0, FS_FILE_BEGIN);

    /* Check wether the file with this encoding exists before or not. */
    is_temp_file_present = ebr_frm_check_if_file_exists_or_not();

    if (!is_temp_file_present)
    {
        sprintf((char*)file_path_in_ascii, "%c", g_curr_book_cntx_p->memory_type_selected);
        strcat((char*)file_path_in_ascii, ":\\");
        mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);
        fs_ret = FS_GetDiskInfo((PU16) file_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

        disk_free_space = 0;
        disk_total_space = 0;
        if (fs_ret >= 0)
        {
            disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            if (disk_free_space <= g_curr_book_cntx_p->g_nfo_book_struct.book_size * 2)
            {
                //     ebr_app_dispaly_less_memory_pop_up();
                //     FS_Close(file_hnd);
                return 0;
            }
        }
        FS_Close(file_hnd);
        g_curr_book_cntx_p->g_record_id = 1;
        g_curr_book_cntx_p->state_recursive_conversion = EBR_FRM_CONVERSION_UNDERWAY;
        ebr_frm_convert_record_record_recursively();
    }
    else
    {
        if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_PDB)
        {
            g_curr_book_cntx_p->pdb_converted_to_text = TRUE;
        }
        return 2;
    }
    return 1;
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_if_file_exists_or_not
 * DESCRIPTION
 *  Get the record size for text file.
 * PARAMETERS
 *  void
 * RETURNS
 *  S16 error_type
 *****************************************************************************/
pBOOL ebr_frm_check_if_file_exists_or_not(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmiEncoding;
    FS_HANDLE fh_cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
    if (mmiEncoding == g_curr_book_cntx_p->g_nfo_book_struct.temp_encoding_file_format)
    {
        fh_cur = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_ONLY);
        if (fh_cur == 0 || fh_cur < 0)
        {
            FS_Close(fh_cur);
            return FALSE;
        }
        else
        {
            FS_Close(fh_cur);
            return TRUE;
        }
    }
    else
    {
        FS_Delete((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path);
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_create_temp_file_path
 * DESCRIPTION
 *  Get the record size for text file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_create_temp_file_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nfo_extension_name[MAX_EBOOK_NAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) g_curr_book_cntx_p->temp_book_name_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2ncat(
        (PS8) g_curr_book_cntx_p->temp_book_name_path,
        (PS8) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
        mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name) - 4);
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT)
    {
        mmi_asc_to_ucs2((S8*) nfo_extension_name, (S8*) TXT_TEMP_EXT_STR);
    }
    else
    {
        mmi_asc_to_ucs2((S8*) nfo_extension_name, (S8*) PDB_TEMP_EXT_STR);
    }
    mmi_ucs2cat((PS8) g_curr_book_cntx_p->temp_book_name_path, (PS8) nfo_extension_name);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_create_temp_file_txt
 * DESCRIPTION
 *  Get the record size for text file.
 * PARAMETERS
 *  rec_num     [IN]        
 * RETURNS
 *  S16 error_type
 *****************************************************************************/
S32 ebr_frm_create_temp_file_txt(S32 rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rec_num < g_curr_book_cntx_p->num_records)
    {
        rec_size = EBR_RECORD_SIZE_MAX;
    }
    else
    {
        rec_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size % EBR_RECORD_SIZE_MAX;
        if (rec_size == 0 && g_curr_book_cntx_p->g_nfo_book_struct.book_size > 0)
        {
            rec_size = EBR_RECORD_SIZE_MAX;
        }
    }
    return rec_size;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_record_size_txt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ebr_frm_get_record_size_txt(S32 rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rec_num < g_curr_book_cntx_p->num_records)
    {
        rec_size = EBR_RECORD_SIZE_MAX;
    }
    else
    {
        if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
        {
            rec_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size % EBR_RECORD_SIZE_MAX;
            if (rec_size == 0 && g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size > 0)
            {
                rec_size = EBR_RECORD_SIZE_MAX;
            }
        }
        else
        {
            rec_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size % EBR_RECORD_SIZE_MAX;
            if (rec_size == 0 && g_curr_book_cntx_p->g_nfo_book_struct.book_size > 0)
            {
                rec_size = EBR_RECORD_SIZE_MAX;
            }
        }
    }
    return rec_size;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_record_size_pdb
 * DESCRIPTION
 *  Get the offset for the current record to be displayed
 * PARAMETERS
 *  file_hnd        [IN]        
 *  offset          [IN]        
 *  rec_num         [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ebr_frm_get_record_size_pdb(FS_HANDLE file_hnd, S32 offset, S32 rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size, rec_size;
    U32 next_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rec_num < g_curr_book_cntx_p->num_records)
    {
        SEEK_REC_ENTRY(file_hnd, rec_num + 1);
        if (FS_Read(file_hnd, &next_offset, 4, (U32*) & size) == FS_NO_ERROR)
        {
            next_offset = ntohl(next_offset);
        }
        rec_size = next_offset - offset;
    }
    else
    {
        rec_size = EBR_RECORD_SIZE_MAX;
    }
    return rec_size;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_start_decompression
 * DESCRIPTION
 *  Start decompression
 * PARAMETERS
 *  decompressed_buffer     [IN]        
 *  compressed_buffer       [IN]        
 *  size                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_start_decompression(U8 *decompressed_buffer, U8 *compressed_buffer, U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < *size;)
    {
        unsigned c = compressed_buffer[i++];

        if (c >= 1 && c <= 8)
            while (c--)
                /* copy 'c' bytes */
            {
                if (j >= EBR_RECORD_SIZE_MAX)
                {
                    goto end;
                }
                decompressed_buffer[j++] = compressed_buffer[i++];
            }

        else if (c <= 0x7F)
            /* 0,09-7F = self */
        {
            if (j >= EBR_RECORD_SIZE_MAX)
            {
                goto end;
            }
            decompressed_buffer[j++] = c;
        }

        else if (c >= 0xC0) /* space + ASCII char */
        {
            if (j >= EBR_RECORD_SIZE_MAX - 1)
            {
                goto end;
            }
            decompressed_buffer[j++] = ' ', decompressed_buffer[j++] = c ^ 0x80;
        }

        else
        {   /* 80-BF = sequences */
            S32 di, n;

            c = (c << 8) + compressed_buffer[i++];
            di = (c & 0x3FFF) >> COUNT_BITS;
            for (n = (c & ((1 << COUNT_BITS) - 1)) + 3; n--; ++j)
            {
                if (j >= EBR_RECORD_SIZE_MAX)
                {
                    goto end;
                }
                decompressed_buffer[j] = decompressed_buffer[j - di];
            }
        }
    }
  end:
    *size = j;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_decompress_pdb
 * DESCRIPTION
 *  Decompress the PDB record
 * PARAMETERS
 *  b               [IN]        
 *  size            [IN]        
 *  copy_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_decompress_pdb(U8 *b, U32 *size, ebr_frm_copy_type_enum copy_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (copy_type)
    {
        case EBR_FRM_COPY_TYPE_FIRST:
            memset(g_curr_book_cntx_p->start, 0, EBR_RECORD_SIZE_MAX * 2);
            offset = 0;
            break;
        case EBR_FRM_COPY_TYPE_SECOND:
            memset(g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, 0, EBR_RECORD_SIZE_MAX);
            offset = EBR_RECORD_SIZE_MAX;
            break;
        case EBR_FRM_COPY_TYPE_NEXT:
            memcpy(g_curr_book_cntx_p->start, g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, EBR_RECORD_SIZE_MAX);
            memset(g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, 0, EBR_RECORD_SIZE_MAX);
            offset = EBR_RECORD_SIZE_MAX;
            break;
        case EBR_FRM_COPY_TYPE_PREVIOUS:
            memcpy(g_curr_book_cntx_p->start + EBR_RECORD_SIZE_MAX, g_curr_book_cntx_p->start, EBR_RECORD_SIZE_MAX);
            memset(g_curr_book_cntx_p->start, 0, EBR_RECORD_SIZE_MAX);
            offset = 0;
            break;
    }

    ebr_frm_start_decompression(g_curr_book_cntx_p->start + offset, b, size);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_data_to_open_book
 * DESCRIPTION
 *  Get the g_curr_book_cntx_p->buffer
 * PARAMETERS
 *  ebook_frm_setting       [IN]        
 *  buffer_data             [IN]        
 *  book_display_name       [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
S16 ebr_frm_get_data_to_open_book(gui_page_info_app *ebook_frm_setting, U8 *buffer_data, S8 *book_display_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd_local;
    S32 start_id, end_id;
    U8 mmiEncoding = 0;
    S16 returnval;
    S32 buffer_length, book_size = 0, valid_size;
    S16 ebr_page_size;
	S16 buffer_size;
    U32 strlength = 0;
    U8* buffer_start;
    U8 UCS2headerle[] = {0xFF,0xFE};
    U8 UCS2headerbe[] = {0xFE,0xFF};
    U8 tmp_path_buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check here if the call is from file manager or not */
    memset(ebook_frm_setting, 0, sizeof(ebook_frm_setting));
    /* g_curr_book_cntx_p->g_nfo_book_struct.book_size = 0; */
    nfo_hnd_local = ebr_frm_get_nfo_handle();
    if (nfo_hnd_local <= 0)
    {
        return -1;
    }
    FS_Close(nfo_hnd_local);
    ebr_frm_get_book_encoding_type();
    memset(g_curr_book_cntx_p->start, 0, sizeof(g_curr_book_cntx_p->start));
    memset(g_curr_book_cntx_p->buffer, 0, sizeof(g_curr_book_cntx_p->buffer));
    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        book_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size;
        if (book_size < 0)
        {
            return 3;
        }
    }
    else
    {
        book_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
        if (book_size < 0)
        {
            return 3;
        }
        ebr_frm_set_number_of_records();
    }
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format ||
        g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
		ebr_frm_set_number_of_records();
    }
	if(g_curr_book_cntx_p->book_is_in_other_encoding_format)
	{
		ebr_frm_create_temp_file_path();
		if(ebr_frm_check_if_file_exists_or_not())
		{
		ebr_frm_set_temp_number_of_records();
	}
		else
		{
			ebr_frm_set_number_of_records();
		}
	}
    g_curr_book_cntx_p->g_start_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id;
    g_curr_book_cntx_p->prev_end_id = g_curr_book_cntx_p->g_start_id;
    g_curr_book_cntx_p->g_offset = g_curr_book_cntx_p->g_nfo_book_struct.offset;
    if (g_curr_book_cntx_p->num_records == 0 && !g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        return 2;
    }
    if (g_curr_book_cntx_p->g_start_id != 0)
    {
        if (!g_curr_book_cntx_p->ebr_frm_end_book_flag ||
            ((g_curr_book_cntx_p->g_nfo_book_struct.current_page_id + 4) * ebr_page_size >= (U32) book_size ||
             (g_curr_book_cntx_p->g_nfo_book_struct.offset > (U32) ebr_page_size * 3 ||
              g_curr_book_cntx_p->g_nfo_book_struct.jump_offset > (U32) ebr_page_size * 3)) &&
            (!g_curr_book_cntx_p->search_flag_is_on))
        {
            start_id = (g_curr_book_cntx_p->g_start_id) % (EBR_RECORD_SIZE_MAX / ebr_page_size);
            if ((start_id + EBR_RECORD_SIZE_MAX / ebr_page_size + 3) <= (EBR_RECORD_SIZE_MAX / ebr_page_size) * 2 - 1)
            {
                start_id += EBR_RECORD_SIZE_MAX / ebr_page_size;
            }
            else if (g_curr_book_cntx_p->g_start_id / (EBR_RECORD_SIZE_MAX / ebr_page_size) == g_curr_book_cntx_p->num_records - 1)
            {
                start_id += (EBR_RECORD_SIZE_MAX / ebr_page_size - start_id);    
            }
            if (book_size < EBR_RECORD_SIZE_MAX)
            {
                start_id = g_curr_book_cntx_p->g_start_id;
            }
        }
        else
        {
            start_id = g_curr_book_cntx_p->g_start_id % (EBR_RECORD_SIZE_MAX / ebr_page_size);
            /* This check si required when the end page id to jump at is the last page id and it may come in
               first record */
            if (g_curr_book_cntx_p->g_start_id / (EBR_RECORD_SIZE_MAX / ebr_page_size) + 2 >
                g_curr_book_cntx_p->num_records)
            {
                start_id -= EBR_RECORD_SIZE_MAX / ebr_page_size;
            }
            if (book_size <= EBR_RECORD_SIZE_MAX)
            {
                start_id = g_curr_book_cntx_p->g_start_id;
            }
        }
    }
    else
    {
        start_id = 0;
    }
    if (start_id < 0)
    {
        g_curr_book_cntx_p->g_start_id =
            g_curr_book_cntx_p->g_nfo_book_struct.current_page_id - EBR_RECORD_SIZE_MAX / ebr_page_size;
        if (g_curr_book_cntx_p->g_start_id < 0)
        {
            g_curr_book_cntx_p->g_start_id = 0;
        }
    }
    g_curr_book_cntx_p->g_end_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id + 3;
    returnval = ebr_frm_decode_header((U8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
    if (returnval == 0)
    {
        return 0;
    }
    else if (returnval == 2)
    {
        return 3;
    }
    else if (returnval < 0)
    {
        return returnval;
    }
    if (g_curr_book_cntx_p->state_recursive_conversion == EBR_FRM_CONVERSION_UNDERWAY)
    {
        return 1;
    }
    if (start_id < 0)
    {
        if (start_id == -1)
        {
            start_id += EBR_RECORD_SIZE_MAX / ebr_page_size;
        }
        else
        {
            start_id += (EBR_RECORD_SIZE_MAX / ebr_page_size * 2);
        }
        if (g_curr_book_cntx_p->is_book_in_unicode)
        {
            if (start_id > 5)
            {
                //start_id = 5;
                start_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id % (EBR_RECORD_SIZE_MAX / ebr_page_size) + (EBR_RECORD_SIZE_MAX / ebr_page_size);
            }
        }
        if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
        {
			if (start_id >= 4 && (g_curr_book_cntx_p->g_nfo_book_struct.current_page_id >4))
            {
				if(g_curr_book_cntx_p->search_flag_is_on)
				{
				
				}
				else
				{
                start_id = 4;
            }
            }
			else
			{
				if(g_curr_book_cntx_p->g_nfo_book_struct.current_page_id<=4)
                    {
				start_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id;
                    }
			}
        }
    }
    end_id = start_id + 3;
    memset(g_curr_book_cntx_p->buffer, 0, ebr_page_size * 4);
    memcpy(g_curr_book_cntx_p->buffer, g_curr_book_cntx_p->start + ebr_page_size * start_id, ebr_page_size * 4);
    buffer_length = mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->buffer);
    mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
    if ((mmiEncoding == MMI_CHSET_UCS2 || g_curr_book_cntx_p->book_is_in_other_encoding_format) && g_curr_book_cntx_p->g_start_id == 0)    
    {
        buffer_start = g_curr_book_cntx_p->buffer;
        
        while (!mmi_ucs2ncmp((S8*)buffer_start, (S8*)UCS2headerle,1))
        {
            buffer_start[0] = WHITE_SPACE;
            buffer_start[1] = 0;
            buffer_start += 2;
        }

        while (!mmi_ucs2ncmp((S8*)buffer_start, (S8*)UCS2headerbe,1))
        {
            buffer_start[0] = WHITE_SPACE;
            buffer_start[1] = 0;
            buffer_start += 2;
        }
    }
    
    switch (mmiEncoding)
    {
        case MMI_CHSET_UCS2:
            mmi_ucs2ncpy(
                (PS8) buffer_data,
                (PS8) g_curr_book_cntx_p->buffer,
                (EBR_RECORD_SIZE_MAX + GUI_SHARED_BYTES) / 2);
            break;
        case MMI_CHSET_WESTERN_WIN:
            returnval = mmi_asc_n_to_ucs2(
                            (PS8) buffer_data,
                            (PS8) g_curr_book_cntx_p->buffer,
                            (EBR_RECORD_SIZE_MAX + GUI_SHARED_BYTES) / 2);
            break;
        default:
            mmi_ucs2ncpy(
                (PS8) buffer_data,
                (PS8) g_curr_book_cntx_p->buffer,
                (EBR_RECORD_SIZE_MAX + GUI_SHARED_BYTES) / 2);
            break;
    }
    if (g_curr_book_cntx_p->is_book_in_unicode)
    {
        ebook_frm_setting->doc_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size / 2;
    }
    else
    {
        if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
        {
            ebook_frm_setting->doc_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size / 2;
        }
        else
        {
            ebook_frm_setting->doc_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
        }
    }
    
    /* If the encoding type is incorrect, the doc size should be modified to prevent scroll bar from getting wrong information */
    buffer_size = mmi_ucs2strlen((const S8*)buffer_data);
	/* doc_size contains the terminates 0x00 00 */
    valid_size = (g_curr_book_cntx_p->g_nfo_book_struct.current_page_id * EBR_PAGE_SIZE) + buffer_size - (ebook_frm_setting->doc_size - 1);
	if (buffer_size < EBR_RECORD_SIZE_MAX / 2 && valid_size < 0)
    {
        ebook_frm_setting->doc_size = buffer_size + g_curr_book_cntx_p->g_start_id * EBR_PAGE_SIZE;
		if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
		{
			g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size = ebook_frm_setting->doc_size * 2;
		}
		else if (g_curr_book_cntx_p->is_book_in_unicode)
		{
			g_curr_book_cntx_p->g_nfo_book_struct.book_size = ebook_frm_setting->doc_size * 2;
		}
		else
		{
			g_curr_book_cntx_p->g_nfo_book_struct.book_size = ebook_frm_setting->doc_size;
		}
		if (g_curr_book_cntx_p->g_nfo_book_struct.jump_offset > buffer_size)
		{
			g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = buffer_size -1;
		}
    }

    if (ebook_frm_setting->doc_size < EBR_PAGE_SIZE * 4)
    {
        ebook_frm_setting->end_id = ebook_frm_setting->doc_size / EBR_PAGE_SIZE - 1;
        if (ebook_frm_setting->doc_size % EBR_PAGE_SIZE != 0)
        {
            ebook_frm_setting->end_id = ebook_frm_setting->end_id + 1;
        }
        if (ebook_frm_setting->doc_size <= EBR_PAGE_SIZE)
        {
            ebook_frm_setting->end_id = 0;
        ebook_frm_setting->start_id = 0;
        }
        else
        {
            ebook_frm_setting->start_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id;
        }
    }
    else
    {
        ebook_frm_setting->start_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id;    /* -reduce_start_id_by; */
        if ((book_size - g_curr_book_cntx_p->g_nfo_book_struct.current_page_id * EBR_PAGE_SIZE) < EBR_RECORD_SIZE_MAX)
        {
            if (book_size - g_curr_book_cntx_p->g_nfo_book_struct.current_page_id * EBR_PAGE_SIZE > EBR_PAGE_SIZE * 3)
            {
                ebook_frm_setting->end_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id + 3;
            }
            else
            {
                if (ebook_frm_setting->doc_size % EBR_PAGE_SIZE == 0)
                {
                    ebook_frm_setting->end_id = ebook_frm_setting->doc_size / EBR_PAGE_SIZE - 1;
                }
                else
                {
                    ebook_frm_setting->end_id = ebook_frm_setting->doc_size / EBR_PAGE_SIZE;
                }
            }
        }
        else
        {
            ebook_frm_setting->end_id = g_curr_book_cntx_p->g_nfo_book_struct.current_page_id + 3;
        }
    }

    ebook_frm_setting->font_style = g_curr_book_cntx_p->g_nfo_book_struct.settings.font_style;
    ebook_frm_setting->font_size = g_curr_book_cntx_p->g_nfo_book_struct.settings.font_size;
    ebook_frm_setting->scroll_speed =
        g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_speed + 1;
    ebook_frm_setting->scroll_type = g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_type;
    ebook_frm_setting->text_offset = g_curr_book_cntx_p->g_nfo_book_struct.offset;
    ebook_frm_setting->jump_offset_from_app = g_curr_book_cntx_p->g_nfo_book_struct.jump_offset;
    ebook_frm_setting->scroll_flag = g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag;
    ebook_frm_setting->jump_to_end = g_curr_book_cntx_p->ebr_frm_end_book_flag;
    ebook_frm_setting->search_str_len = g_curr_book_cntx_p->ebr_search_strlen;
    ebook_frm_setting->highlight_string = g_curr_book_cntx_p->highlight_string_flag;
    ebook_frm_setting->search_flag_is_on = g_curr_book_cntx_p->search_flag_is_on;
    ebook_frm_setting->last_text_offset_y = g_curr_book_cntx_p->g_nfo_book_struct.last_text_offset_y;
#ifdef __MMI_TOUCH_SCREEN__
    ebook_frm_setting->get_data_during_scrolling = ebr_frm_get_data_during_scrolling;
#endif 
    if (g_curr_book_cntx_p->search_flag_is_on == 0)
    {
        ebook_frm_setting->last_showed_percentage = g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage;
    }
    else
    {
        ebook_frm_setting->last_showed_percentage = 0;
    }
    g_curr_book_cntx_p->highlight_string_flag = 0;
    g_curr_book_cntx_p->search_flag_is_on = 0;
    g_curr_book_cntx_p->ebr_frm_end_book_flag = 1;
    strlength = mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
    
    if (g_curr_book_cntx_p->is_short)
    {
            memset(tmp_path_buf, 0, (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            mmi_chset_mixed_text_to_ucs2_str(
                        (U8*) tmp_path_buf,
                        (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
                        (U8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
                        g_chset_text_encoding);            
            mmi_ucs2ncpy(
            (S8*) book_display_name,
            (S8*) tmp_path_buf,
            strlength - EBR_EXTENSION_NAME_LENGTH - 1);
	}
	else
	{
		mmi_ucs2ncpy(
            (S8*) book_display_name,
            (S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
            strlength - EBR_EXTENSION_NAME_LENGTH - 1);
	}               
    ebook_frm_setting->get_page_cb = ebr_frm_paging_multiline_input_box_get_page;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_book_encoding_type
 * DESCRIPTION
 *  Get encoding type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_book_encoding_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmiEncoding = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
    if (mmiEncoding != MMI_CHSET_WESTERN_WIN)
    {
        if ((mmiEncoding == MMI_CHSET_UCS2))
        {
            g_curr_book_cntx_p->is_book_in_unicode = TRUE;
            g_curr_book_cntx_p->book_is_in_other_encoding_format = FALSE;
        }
        else
        {
            g_curr_book_cntx_p->is_book_in_unicode = FALSE;
            g_curr_book_cntx_p->book_is_in_other_encoding_format = TRUE;
        }
    }
    else
    {
        g_curr_book_cntx_p->is_book_in_unicode = FALSE;
        g_curr_book_cntx_p->book_is_in_other_encoding_format = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_encoded_data
 * DESCRIPTION
 *  Get the encoding format
 * PARAMETERS
 *  inBuffer        [IN]        
 *  outBuffer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_encoded_data(S8 *inBuffer, S8 *outBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmiEncoding = 0;
    S16 length = mmi_ucs2strlen((const S8*)outBuffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
    switch (mmiEncoding)
    {
        case MMI_CHSET_UCS2:
            mmi_ucs2ncpy((PS8) inBuffer, (PS8) outBuffer, (length) * 2);
            break;
        case MMI_CHSET_WESTERN_WIN:
            mmi_asc_n_to_ucs2((PS8) inBuffer, (PS8) outBuffer, (length) * 2);
            break;
        default:
            mmi_chset_convert(
                (mmi_chset_enum) mmiEncoding,
                MMI_CHSET_UCS2,
                (char*)outBuffer,
                (char*)inBuffer,
                length * 2);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_record
 * DESCRIPTION
 *  Get the record data
 * PARAMETERS
 *  end_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_record(S32 end_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 record_id_to_be_fetched;

    /* U8 nfo_path[MAX_DWNL_EBK_PATH_LEN*ENCODING_LENGTH]={0}; */
    FS_HANDLE file_hnd;
    S16 ebr_page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      mmi_ucs2cpy((S8*)nfo_path  ,(S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected,EBR_FRM_SEARCH_DEFAULT));
    //      mmi_ucs2cat((PS8)nfo_path, (PS8)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_ONLY);
    }
    else
    {
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
    }
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }
    if (g_curr_book_cntx_p->prev_end_id >= end_id)
    {

        record_id_to_be_fetched = (end_id - 2) / (EBR_RECORD_SIZE_MAX / ebr_page_size) + 1;
        if (record_id_to_be_fetched <= g_curr_book_cntx_p->num_records)
        {
            if ((record_id_to_be_fetched != g_curr_book_cntx_p->gcurrent_record_id) &&
                (record_id_to_be_fetched != g_curr_book_cntx_p->gnext_record_id))
            {
                copy_record_in_buffer(file_hnd, record_id_to_be_fetched, EBR_FRM_COPY_TYPE_PREVIOUS);
                g_curr_book_cntx_p->gcurrent_record_id = record_id_to_be_fetched;
                g_curr_book_cntx_p->gnext_record_id = record_id_to_be_fetched + 1;
            }
        }
    }
    else
    {
        record_id_to_be_fetched = (end_id + 2) / (EBR_RECORD_SIZE_MAX / ebr_page_size) + 1;
        if (record_id_to_be_fetched <= g_curr_book_cntx_p->num_records)
        {
            if ((record_id_to_be_fetched != g_curr_book_cntx_p->gcurrent_record_id) &&
                (record_id_to_be_fetched != g_curr_book_cntx_p->gnext_record_id))
            {
                copy_record_in_buffer(file_hnd, record_id_to_be_fetched, EBR_FRM_COPY_TYPE_NEXT);
                g_curr_book_cntx_p->gcurrent_record_id = record_id_to_be_fetched - 1;
                g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;
            }
        }
    }
    g_curr_book_cntx_p->prev_end_id = end_id;
    FS_Close(file_hnd);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_jump_to_record
 * DESCRIPTION
 *  Jump to a record
 * PARAMETERS
 *  percantage_val      [IN]        
 *  jump_type           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_jump_to_record(U32 percantage_val, ebr_jump_type_enum jump_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ebr_page_size;
    S32 book_size = 0;
    S16 jump_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->g_jump_offset = 0;
    //      if(g_curr_book_cntx_p->is_book_in_unicode||g_curr_book_cntx_p->book_is_in_other_encoding_format)
    //              ebr_page_size  = EBR_PAGE_SIZE*2;
    //      else
    ebr_page_size = EBR_PAGE_SIZE;
    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        book_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size;
    }
    else
    {
        book_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
    }
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        book_size /= 2;
    }

    if (jump_type == EBR_JUMP_MIDDLE && percantage_val == 0)
    {
        percantage_val = 50;
    }
    if (percantage_val == 1)
    {
        jump_type = EBR_JUMP_BEGIN;
        percantage_val = 0;
    }
    if (percantage_val == 0)
    {
        switch (jump_type)
        {
            case EBR_JUMP_BEGIN:
                g_curr_book_cntx_p->g_start_id = 0;
                g_curr_book_cntx_p->g_end_id = 3;
                g_curr_book_cntx_p->g_jump_offset = 0;
                g_curr_book_cntx_p->gcurrent_record_id = 1;
                g_curr_book_cntx_p->gnext_record_id = 2;
                break;
            case EBR_JUMP_END:
                g_curr_book_cntx_p->ebr_frm_end_book_flag = 0;
                if (book_size % ebr_page_size == 0)
                {
                    g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size - 1;
                }
                else
                {
                    if (book_size < ebr_page_size * 4)
                    {						                        
                        g_curr_book_cntx_p->g_start_id = 0;
                        g_curr_book_cntx_p->g_end_id = 3;                        
                    }
                    else
                    {
                        g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size;
                    }
                }
                g_curr_book_cntx_p->g_start_id = g_curr_book_cntx_p->g_end_id - 3;
                if (g_curr_book_cntx_p->g_start_id < 0)
                {
                    g_curr_book_cntx_p->g_start_id = 0;
                }
                /* Set the offset to the last word */    
                jump_offset = book_size - (g_curr_book_cntx_p->g_start_id * EBR_PAGE_SIZE) - 1;
                if (jump_offset < 0)
                {
                    g_curr_book_cntx_p->g_jump_offset = 0;
                }
                else
                {
                    g_curr_book_cntx_p->g_jump_offset = jump_offset;
                }
                break;
        }
    }
    else
    {
        float num;
        int size_offset;
        float actual_size_offset;
        float actual_jump_offset;
        int jump_offset = 0;

        num = percantage_val / (float)100.0;
        actual_size_offset = book_size * num;
        if (percantage_val == 100)
        {
            /* percantage_val--; */
            num = (percantage_val - 1) / (float)100.0;
            num = (float)(num + 0.008);
            size_offset = (int)(book_size * num);
            actual_size_offset = ((float)book_size) * num;
        }
        else
        {
            size_offset = (int)(book_size * num);
        }
        if (actual_size_offset - (float)size_offset > 0)
        {
            size_offset++;
        }

        if (percantage_val == 100)
        {            
            g_curr_book_cntx_p->ebr_frm_end_book_flag = 0;
			if (book_size % ebr_page_size == 0)
			{
				g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size - 1;
			}
			else
			{
				g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size;
			}			
			g_curr_book_cntx_p->g_start_id = g_curr_book_cntx_p->g_end_id - 3;  
			if (g_curr_book_cntx_p->g_start_id < 0)
			{
				g_curr_book_cntx_p->g_start_id = 0;
			}
            g_curr_book_cntx_p->g_jump_offset = size_offset - g_curr_book_cntx_p->g_start_id * EBR_PAGE_SIZE;
        }
        else if ((book_size - size_offset) <= EBR_PAGE_SIZE)
        {
            if (book_size % ebr_page_size == 0)
            {
                g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size - 1;
                g_curr_book_cntx_p->g_start_id = g_curr_book_cntx_p->g_end_id - 3;
                if (g_curr_book_cntx_p->g_start_id < 0)
                {
                    g_curr_book_cntx_p->g_start_id = 0;
                }
                g_curr_book_cntx_p->g_jump_offset =
                            size_offset - g_curr_book_cntx_p->g_start_id * EBR_PAGE_SIZE;
            }
            else
            {
                if (book_size <= ebr_page_size * 4)
                {
                    actual_jump_offset = (float)(book_size) * (float)((float)(percantage_val) / (float)100.0);
                    g_curr_book_cntx_p->g_jump_offset = (U16) actual_jump_offset;
                    if (actual_jump_offset - (float)g_curr_book_cntx_p->g_jump_offset > 0.5)
                    {
                        g_curr_book_cntx_p->g_jump_offset++;
                    }
                    if (g_curr_book_cntx_p->g_jump_offset == book_size)
                    {
                        g_curr_book_cntx_p->g_jump_offset--;
                    }
                    g_curr_book_cntx_p->g_start_id = 0;
                    g_curr_book_cntx_p->g_end_id = g_curr_book_cntx_p->g_start_id + 3;
                }
                else
                {
                    if (book_size < EBR_RECORD_SIZE_MAX)
                    {
                        actual_jump_offset = (float)(book_size) * (float)((float)(percantage_val) / (float)100.0);
                        g_curr_book_cntx_p->g_jump_offset = (U16) actual_jump_offset;
                        if (actual_jump_offset - (float)g_curr_book_cntx_p->g_jump_offset > 0.5)
                        {
                            g_curr_book_cntx_p->g_jump_offset++;
                        }
                        if (g_curr_book_cntx_p->g_jump_offset == book_size)
                        {
                            g_curr_book_cntx_p->g_jump_offset--;
                        }
                        jump_offset = (int)g_curr_book_cntx_p->g_jump_offset;
                        /* while(jump_offset>0)
                           jump_offset = jump_offset - EBR_PAGE_SIZE; */

                        /* g_curr_book_cntx_p->g_jump_offset = jump_offset + EBR_PAGE_SIZE+EBR_PAGE_SIZE; */
                        g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size;
                        if (g_curr_book_cntx_p->g_start_id < 0)
                        {
                            g_curr_book_cntx_p->g_start_id = 0;
                        }
                        g_curr_book_cntx_p->g_start_id = g_curr_book_cntx_p->g_end_id - 3;
                        g_curr_book_cntx_p->g_jump_offset =
                            g_curr_book_cntx_p->g_jump_offset - g_curr_book_cntx_p->g_start_id * EBR_PAGE_SIZE;

                    }
                    else
                    {
						g_curr_book_cntx_p->g_end_id = book_size / ebr_page_size;
                        if (g_curr_book_cntx_p->g_start_id < 0)
                        {
                            g_curr_book_cntx_p->g_start_id = 0;
                        }
                        g_curr_book_cntx_p->g_start_id = g_curr_book_cntx_p->g_end_id - 3;
                        g_curr_book_cntx_p->g_jump_offset =
                            size_offset - g_curr_book_cntx_p->g_start_id * EBR_PAGE_SIZE;

                    }
                }
            }

        }
        else
        {
            if (book_size <= EBR_PAGE_SIZE * 4)
            {
                g_curr_book_cntx_p->g_start_id = 0;
                g_curr_book_cntx_p->g_end_id = g_curr_book_cntx_p->g_start_id + 3;
                g_curr_book_cntx_p->g_jump_offset =
                    (U32) (((float)book_size) * (float)((float)(percantage_val) / (float)100.0));
            }
            else
            {
                if (book_size < EBR_RECORD_SIZE_MAX)
                {
                    actual_jump_offset = (float)(book_size) * (float)((float)(percantage_val) / (float)100.0);
                    g_curr_book_cntx_p->g_jump_offset = (U16) actual_jump_offset;
                    if (actual_jump_offset - (float)g_curr_book_cntx_p->g_jump_offset > 0.5)
                    {
                        g_curr_book_cntx_p->g_jump_offset++;
                    }
                    if (g_curr_book_cntx_p->g_jump_offset == book_size)
                    {
                        g_curr_book_cntx_p->g_jump_offset--;
                    }
                    jump_offset = (int)g_curr_book_cntx_p->g_jump_offset;
                    size_offset = jump_offset;
                    while (jump_offset > 0)
                    {
                        jump_offset = jump_offset - EBR_PAGE_SIZE;
                    }
                    if (size_offset % ebr_page_size != 0)
                    {
                        g_curr_book_cntx_p->g_jump_offset = jump_offset + EBR_PAGE_SIZE;
                        g_curr_book_cntx_p->g_start_id = size_offset / ebr_page_size;
                    }
                    else
                    {
                        /* offset could not be 0 */
                        g_curr_book_cntx_p->g_jump_offset = EBR_PAGE_SIZE;
                        g_curr_book_cntx_p->g_start_id = size_offset / ebr_page_size - 1;
                    }
                    if (g_curr_book_cntx_p->g_start_id < 0)
                    {
                        g_curr_book_cntx_p->g_start_id = 0;
                    }
                    g_curr_book_cntx_p->g_end_id = g_curr_book_cntx_p->g_start_id + 3;
                }
                else
                {
                    g_curr_book_cntx_p->g_jump_offset = size_offset % EBR_PAGE_SIZE + EBR_PAGE_SIZE;
                    if (percantage_val == 100)
                    {
                        g_curr_book_cntx_p->g_start_id = (size_offset / ebr_page_size);
                    }
                    else
                    {
                        g_curr_book_cntx_p->g_start_id = (size_offset / ebr_page_size) - 1;
                    }
					if (g_curr_book_cntx_p->g_start_id < 0)
					{
						g_curr_book_cntx_p->g_start_id = 0;
						g_curr_book_cntx_p->g_jump_offset -= EBR_PAGE_SIZE;
					}
                    g_curr_book_cntx_p->g_end_id = g_curr_book_cntx_p->g_start_id + 3;
                }
            }
        }
    }
    if (percantage_val != g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage)
    {
        g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = 0;
    }
    g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = g_curr_book_cntx_p->g_start_id;
    g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
    g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = g_curr_book_cntx_p->g_jump_offset;
    ebr_frm_save_settings_in_nfo_file();
    g_curr_book_cntx_p->ebr_last_offset_string = -1;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_remove_bookmark
 * DESCRIPTION
 *  Create the linked list
 * PARAMETERS
 *  bookmark_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_remove_bookmark(U32 bookmark_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    U32 size;
    S32 retval;
    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[bookmark_index].bookmark_name, (PS8) NULL);
    if (g_curr_book_cntx_p->g_nfo_book_struct.book_marks[bookmark_index + 1].bookmark_name[0] != 0 || g_curr_book_cntx_p->g_nfo_book_struct.book_marks[bookmark_index + 1].bookmark_name[1] != 0)
    {
        count = bookmark_index + 1;
        while ((g_curr_book_cntx_p->g_nfo_book_struct.book_marks[count].bookmark_name[0] != 0 || g_curr_book_cntx_p->g_nfo_book_struct.book_marks[count].bookmark_name[1] != 0)
            && count < EBR_FRM_MAX_NO_OF_BOOKMARKS)
        {
            memcpy(
                (PS8) &(g_curr_book_cntx_p->g_nfo_book_struct.book_marks[count - 1]),
                (PS8) &(g_curr_book_cntx_p->g_nfo_book_struct.book_marks[count]), sizeof(ebr_frm_bookmark_struct));
            count++;
        }
        count--;
        mmi_ucs2cpy((PS8) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[count].bookmark_name, (PS8) NULL);
    }

    nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
    FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
    retval = FS_Write(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
    FS_Close(nfo_hnd);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_add_book_mark_pre_entry
 * DESCRIPTION
 *  Pre entry Screen for Add book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_add_book_mark_pre_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, duplicate = 0;
    U8 bookMarkName[EBR_FRM_MAX_BOOKMARK_NAME_SIZE * ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) bookMarkName, (S8*) ebr_get_book_mark_name());
    while (g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name[0] != 0 || g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name[1] != 0)
    {
        if (!mmi_ucs2cmp
            ((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name, (const S8*)bookMarkName))
        {
            duplicate = 1;
            entry_duplicate_book_mark_pop_up();
        }
        i++;
    }
    if (duplicate == 0)
    {
        ebr_frm_add_book_mark();
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_add_book_mark
 * DESCRIPTION
 *  Entry function for Add book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_add_book_mark()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U8 bookMarkName[EBR_FRM_MAX_BOOKMARK_NAME_SIZE * ENCODING_LENGTH] = {0};
    U32 size;
    S32 retval, text_offset_local = 0;
    FS_HANDLE nfo_hnd;
    U32 page_id;
    S32 text_offset;
    U8 shared_bytes;
    U8 last_showed_percentage;
    S32 last_text_offset_y;
    S8 *book_mark_name;
    S16 ebr_page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }
    ebr_frm_get_page_info(
        &page_id,
        &text_offset,
        &shared_bytes,
        &last_showed_percentage,
        &last_text_offset_y);
    text_offset_local = text_offset;

    book_mark_name = ebr_get_book_mark_name();
    mmi_ucs2cpy((S8*) bookMarkName, (S8*) book_mark_name);
    if (book_mark_name[0] == 0 && book_mark_name[1] == 0)
    {
        ebr_app_display_pop_up_book_mark_name_empty();
        DeleteUptoScrID(EBOOK_ADD_BOOK_MARK_SCREEN_ID);
        return;
    }
    i = 0;
    while (g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name[0] != 0 || g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name[1] != 0)
    {
        if (!mmi_ucs2cmp
            ((const S8*)g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name, (const S8*)bookMarkName))
        {
            break;
        }
        i++;
    }
    if (i == EBR_FRM_MAX_NO_OF_BOOKMARKS)
    {
        /* Display Pop up that no more BookMarks can be added */
        ebr_app_display_pop_up_maximum_book_marks();

    }
    else
    {
        mmi_ucs2cpy((PS8) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name, (PS8) bookMarkName);
        g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].page_id = page_id;
        g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].offset = text_offset_local;
        g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].shared_bytes = shared_bytes;
        g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].percentage_associated_with_book_mark =
            last_showed_percentage;
        nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
        FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
        retval = FS_Write(
                    nfo_hnd,
                    &g_curr_book_cntx_p->g_nfo_book_struct,
                    sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
                    &size);
        FS_Close(nfo_hnd);

        ebr_app_display_pop_up_book_mark_sucessfully_added();

    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_record_for_bookmark
 * DESCRIPTION
 *  Get record for BookMArk
 * PARAMETERS
 *  selected_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_record_for_bookmark(U32 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 filesize;
    S32 page_id = 0, offset = 0, record_id = 0, shared_bytes = 0, book_size;
    S16 ebr_page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        book_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size;
    }
    else
    {
        book_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size;
    }

    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }

    filesize = book_size;
    page_id = g_curr_book_cntx_p->g_nfo_book_struct.book_marks[selected_index].page_id;
    offset = g_curr_book_cntx_p->g_nfo_book_struct.book_marks[selected_index].offset;
    shared_bytes = g_curr_book_cntx_p->g_nfo_book_struct.book_marks[selected_index].shared_bytes;
    record_id = (ebr_page_size * page_id) / EBR_RECORD_SIZE_MAX;
    record_id++;
    if ((page_id % (EBR_RECORD_SIZE_MAX / ebr_page_size) > 2) &&
        page_id % (EBR_RECORD_SIZE_MAX / ebr_page_size) <= (EBR_RECORD_SIZE_MAX / ebr_page_size) - 2)
    {
        if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_PDB)
        {
            if ((g_curr_book_cntx_p->num_records == record_id - 1) || (g_curr_book_cntx_p->num_records == record_id))
            {
                g_curr_book_cntx_p->gcurrent_record_id = g_curr_book_cntx_p->num_records - 1;
                g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;
            }
            else
            {
                g_curr_book_cntx_p->gcurrent_record_id = record_id;
                g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;
            }

        }
        else
        {

            g_curr_book_cntx_p->gcurrent_record_id = record_id;
            if (page_id * ebr_page_size + EBR_RECORD_SIZE_MAX > (S32) (book_size))
            {
                g_curr_book_cntx_p->gcurrent_record_id--;
            }
            g_curr_book_cntx_p->gnext_record_id = g_curr_book_cntx_p->gcurrent_record_id + 1;
        }

    }
    else
    {
    }
    if (page_id == 0)
    {
        g_curr_book_cntx_p->gcurrent_record_id = 1;
        g_curr_book_cntx_p->gnext_record_id = 2;
    }
    g_curr_book_cntx_p->g_start_id = page_id;
    g_curr_book_cntx_p->g_end_id = g_curr_book_cntx_p->g_start_id + 3;
    g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = g_curr_book_cntx_p->g_start_id;

	g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
    g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = g_curr_book_cntx_p->g_nfo_book_struct.book_marks[selected_index].offset;        
    g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage =
        g_curr_book_cntx_p->g_nfo_book_struct.book_marks[selected_index].percentage_associated_with_book_mark;
    ebr_frm_save_settings_in_nfo_file();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_convert_page_id_to_record_id
 * DESCRIPTION
 *  Get the record number on basis of page id
 * PARAMETERS
 *  page_id             [IN]        
 *  text_offset         [IN]        
 *  shared_bytes        [IN]        
 *  record_id           [IN]        
 *  record_offset       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_convert_page_id_to_record_id(
        S32 page_id,
        S32 text_offset,
        S32 shared_bytes,
        S32 *record_id,
        S32 *record_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ebr_page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }
    text_offset = text_offset - shared_bytes;
    *record_id = (page_id / (EBR_RECORD_SIZE_MAX / ebr_page_size)) + 1;
    *record_offset =
        ((page_id - ((*record_id - 1) * EBR_RECORD_SIZE_MAX / ebr_page_size)) * EBR_PAGE_SIZE + text_offset) - 1;
    if (*record_offset > EBR_RECORD_SIZE_MAX / 2 && *record_id < g_curr_book_cntx_p->num_records)
    {
        ++(*record_id);
        *record_offset = *record_offset % (EBR_RECORD_SIZE_MAX / 2);
    }
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_start_search_timer
 * DESCRIPTION
 *  Timer handler to continue searching
 * PARAMETERS
 *  search_type                 [IN]        
 *  ebr_search_string_input     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_start_search_timer(void)
{
    MMI_BOOL status;

    StopTimer(EBR_SEARCH_BLOCK_TIMER);

    /* if Ebook application is exited */
    if (!IsScreenPresent(EBOOK_OPEN_SCREENID))
    {
        return;
    }
    status = ebr_frm_search_string_algo(
                        (ebr_app_search_type_enum) g_curr_book_cntx_p->ebr_last_search_type,
                        (S8*) g_curr_book_cntx_p->ebr_last_search_string_input,
                        MMI_TRUE);

    /* search not complete */
    if (status == 0xFF || GetExitScrnID() != SCR_ID_EBOOK_WAITSCREEN)
    {
        return;
    }
    /* string has been found */    
    else if (status == 1)
    {
        if (!ebr_frm_get_auto_scroll_status())
        {
            gui_paging_reset_auto_scroll();
        }
        ebr_app_search_result_successful(g_curr_book_cntx_p->ebr_last_search_type);
        ebr_app_delete_upto_open_book_screen_id();
        GoBackHistory();
        ebr_frm_set_data_for_display();
    }
    /* string has been  */
    else
    {
		if(status==2)
		{
			ebr_app_search_result_invalid();
		}
		else
		{
                   ebr_app_search_result_unsucessfull();
              }
    }
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_search_string_algo
 * DESCRIPTION
 *  String search algo
 * PARAMETERS
 *  search_type                 [IN]        
 *  ebr_search_string_input     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL ebr_frm_search_string_algo(ebr_app_search_type_enum search_type, S8 *ebr_search_string_input, MMI_BOOL timeout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd_local;
    FS_HANDLE file_hnd;
    S32 ebr_search_from_offset = -1;
    S32 search_record_id = -1,search_from_record_id;
    U8 mmiEncoding = 0;
    U32 page_id;
    S32 text_offset, last_text_offset_y;
    S8 search_string_input[(EBR_MAX_STR_SEARCH_LENGTH + 1) * ENCODING_LENGTH], string_length = mmi_ucs2strlen((const S8*)ebr_search_string_input);
    U8 shared_bytes;
    U8 last_showed_percentage;
    pBOOL search_status = 0;
    U32 size, count = 0;
    S16 ebr_page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }
    /* Need the file handle over here to open the boook and search in it */
    memset((void*)g_curr_book_cntx_p->start, 0, EBR_RECORD_SIZE_MAX * 2);
    mmi_ucs2cpy(search_string_input, ebr_search_string_input);
    ebr_frm_get_page_info(
        &page_id,
        &text_offset,
        &shared_bytes,
        &last_showed_percentage,
        &last_text_offset_y);
    /* continue searching for previous stop */
    if (timeout == MMI_TRUE)
    {
        search_record_id = g_curr_book_cntx_p->ebr_last_search_record_id;
        ebr_search_from_offset = g_curr_book_cntx_p->ebr_last_offset_string;
    }
    else if (g_curr_book_cntx_p->ebr_last_offset_string == -1)
    {
        ebr_frm_convert_page_id_to_record_id(
            page_id,
            text_offset,
            shared_bytes,
            &search_record_id,
            &ebr_search_from_offset);
    }
    else if (mmi_ucs2cmp(ebr_search_string_input, g_curr_book_cntx_p->ebr_last_search_string_input) != 0 ||
             g_curr_book_cntx_p->ebr_last_search_type != search_type)
    {
        ebr_frm_convert_page_id_to_record_id(
            page_id,
            text_offset,
            shared_bytes,
            &search_record_id,
            &ebr_search_from_offset);
        g_curr_book_cntx_p->find_next_first_flag = 0;
        g_curr_book_cntx_p->search_found_flag = 0;
        g_curr_book_cntx_p->search_string_count = 0;
    }
    else if (page_id != g_curr_book_cntx_p->ebr_last_page_id || g_curr_book_cntx_p->ebr_last_text_offset != text_offset)
    {
        ebr_frm_convert_page_id_to_record_id(
            page_id,
            text_offset,
            shared_bytes,
            &search_record_id,
            &ebr_search_from_offset);
    }
    else
    {
        search_record_id = g_curr_book_cntx_p->ebr_last_search_record_id;
        ebr_search_from_offset = g_curr_book_cntx_p->ebr_last_offset_string;

    }
    if (g_curr_book_cntx_p->find_next_first_flag == 0)
    {
        g_curr_book_cntx_p->find_next_first_flag = 1;
        g_curr_book_cntx_p->search_record_id_first = search_record_id;
        g_curr_book_cntx_p->ebr_search_from_offset_first = ebr_search_from_offset;
    }
    nfo_hnd_local = ebr_frm_get_nfo_handle();

    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_ONLY);
    }
    else
    {
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
    }
	search_from_record_id = search_record_id;
    while (search_record_id <= g_curr_book_cntx_p->num_records)
    {
        /* Since MMI will be hung on Ebook searching process if the file size is too large, we search for some records and start a timer to continue. */
        count++;
        if (count > EBR_FRM_SEARCH_BLOCK)
        {
            g_curr_book_cntx_p->ebr_last_offset_string = -1;
            g_curr_book_cntx_p->ebr_last_search_record_id = search_record_id;
            g_curr_book_cntx_p->ebr_last_search_type = search_type;
            g_curr_book_cntx_p->ebr_search_from_offset_first = ebr_search_from_offset;
            mmi_ucs2cpy(g_curr_book_cntx_p->ebr_last_search_string_input, ebr_search_string_input);
			FS_Close(nfo_hnd_local);
			FS_Close(file_hnd);
            
            StartTimer(EBR_SEARCH_BLOCK_TIMER, EBR_FRM_SEARCH_BREAK_TIMER, ebr_frm_start_search_timer);
            /* Search not complete */
            return 0xFF;
        }
        
        if (string_length == 0)
        {
            search_status = 0;
            break;
        }
        memset((void*)g_curr_book_cntx_p->start, 0, EBR_RECORD_SIZE_MAX * 2);
        memset((void*)g_curr_book_cntx_p->buffer, 0, EBR_RECORD_SIZE_MAX);
        copy_record_in_passed_buffer(
            file_hnd,
            search_record_id,
            (U8*) g_curr_book_cntx_p->buffer,
            (U8*) g_curr_book_cntx_p->start,
            &size);
        mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);
        switch (mmiEncoding)
        {
            case MMI_CHSET_UCS2:
                mmi_ucs2ncpy(
                    (PS8) g_curr_book_cntx_p->start,
                    (PS8) g_curr_book_cntx_p->buffer,
                    EBR_RECORD_SIZE_MAX);
                break;
            case MMI_CHSET_WESTERN_WIN:
                mmi_asc_n_to_ucs2(
                    (PS8) g_curr_book_cntx_p->start,
                    (PS8) g_curr_book_cntx_p->buffer,
                    EBR_RECORD_SIZE_MAX);
                break;
            default:
                mmi_ucs2ncpy(
                    (PS8) g_curr_book_cntx_p->start,
                    (PS8) g_curr_book_cntx_p->buffer,
                    EBR_RECORD_SIZE_MAX);
                /* mmi_chset_convert ((mmi_chset_enum)mmiEncoding,MMI_CHSET_UCS2, (char*)g_curr_book_cntx_p->start, (char*)g_curr_book_cntx_p->buffer, EBR_RECORD_SIZE_MAX); */
                break;
        }
        if (search_type == EBR_APP_CASE_IN_SENSITIVE)
        {
            ebr_frm_convert_to_upper((S16*) g_curr_book_cntx_p->start);
            ebr_frm_convert_to_upper((S16*) search_string_input);
        }
        //   if(ebr_search_from_offset==0)
        //        ebr_search_from_offset=-1;
        search_status = ebr_frm_bm_search((S16*) g_curr_book_cntx_p->start, (S16*) search_string_input, &ebr_search_from_offset,size);
		if(search_status==2)
		{
			FS_Close(nfo_hnd_local);
			FS_Close(file_hnd);
            break;
		}
        if (search_status == 0)
        {
            /* If setting of encoding type is incorrect, the book size may less than record even it is not in last record */
            if (mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->start)  < EBR_RECORD_SIZE_MAX/2 && search_record_id < g_curr_book_cntx_p->num_records)
            {
                g_curr_book_cntx_p->last_record_flag = 0;
                break;
            }
            
            if (g_curr_book_cntx_p->search_record_id_first == search_record_id &&
                g_curr_book_cntx_p->last_record_flag == 1 && g_curr_book_cntx_p->search_found_flag == 0)
            {
                g_curr_book_cntx_p->last_record_flag = 0;
                /* g_curr_book_cntx_p->find_next_first_flag=0; */
                break;
            }

            search_record_id++;
			/* When the total record of the file is 1, and search offset is not 0, we should still search from beginning of first record. */
			if((search_from_record_id==1) && (search_record_id == g_curr_book_cntx_p->num_records + 1) && (ebr_search_from_offset == -1))
			{
				ebr_search_from_offset = 0;
				g_curr_book_cntx_p->last_record_flag = 0;
				break;
			}
            if (search_record_id == g_curr_book_cntx_p->num_records + 1)
            {
                search_record_id = 1;
				search_from_record_id = search_record_id;
                g_curr_book_cntx_p->last_record_flag = 1;
				ebr_search_from_offset = -1;
				g_curr_book_cntx_p->ebr_last_offset_string = -1;
            }
            else
            {
                ebr_search_from_offset = 0;
            }

        }
        else
        {
            g_curr_book_cntx_p->search_found_flag = 1;

            if (g_curr_book_cntx_p->ebr_last_search_record_id == search_record_id &&
                g_curr_book_cntx_p->ebr_last_offset_string == ebr_search_from_offset &&
                g_curr_book_cntx_p->ebr_last_search_type == search_type &&
                string_length == g_curr_book_cntx_p->ebr_search_strlen &&
                page_id == g_curr_book_cntx_p->ebr_last_page_id &&
                g_curr_book_cntx_p->ebr_last_text_offset == text_offset)
            {
                search_status = 0;
                g_curr_book_cntx_p->last_record_flag = 0;
                g_curr_book_cntx_p->search_found_flag = 0;
                g_curr_book_cntx_p->search_string_count = 0;
            }
            else
            {
                g_curr_book_cntx_p->search_string_count++;
                /* if(g_curr_book_cntx_p->search_record_id_first==search_record_id && g_curr_book_cntx_p->last_record_flag==1 && ebr_search_from_offset > g_curr_book_cntx_p->ebr_search_from_offset_first)
                   {
                   g_curr_book_cntx_p->search_string_count=1;
                   g_curr_book_cntx_p->last_record_flag=0;
                   } */
            }

            break;
        }
    }
    if (search_status == 1)
    {
        g_curr_book_cntx_p->g_nfo_book_struct.current_page_id =
            (search_record_id - 1) * EBR_RECORD_SIZE_MAX / ebr_page_size + ((ebr_search_from_offset) / EBR_PAGE_SIZE);
        if (g_curr_book_cntx_p->g_nfo_book_struct.current_page_id == 0)
        {
            g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = ebr_search_from_offset;
        }
        else
        {
            g_curr_book_cntx_p->g_nfo_book_struct.current_page_id--;
            g_curr_book_cntx_p->g_nfo_book_struct.jump_offset =
                (ebr_search_from_offset) % EBR_PAGE_SIZE + EBR_PAGE_SIZE;

        }
        g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
        FS_Seek(nfo_hnd_local, 0, FS_FILE_BEGIN);
        FS_Write(
            nfo_hnd_local,
            &g_curr_book_cntx_p->g_nfo_book_struct,
            sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
            &size);
        g_curr_book_cntx_p->ebr_search_strlen = mmi_ucs2strlen((const S8*)ebr_search_string_input);
        g_curr_book_cntx_p->highlight_string_flag = 1;
        g_curr_book_cntx_p->ebr_last_search_record_id = search_record_id;
        g_curr_book_cntx_p->ebr_last_search_type = search_type;
        g_curr_book_cntx_p->ebr_last_offset_string = ebr_search_from_offset;
        g_curr_book_cntx_p->ebr_last_page_id = page_id;
        g_curr_book_cntx_p->ebr_last_text_offset = text_offset;
        mmi_ucs2cpy(g_curr_book_cntx_p->ebr_last_search_string_input, ebr_search_string_input);
        g_curr_book_cntx_p->search_flag_is_on = 1;
        /* g_curr_book_cntx_p->search_found_flag=0; */
    }
    else
    {
        g_curr_book_cntx_p->ebr_last_offset_string = -1;
        /* g_curr_book_cntx_p->ebr_last_offset_string=ebr_search_from_offset; */
        g_curr_book_cntx_p->ebr_last_page_id = page_id;
        g_curr_book_cntx_p->ebr_last_text_offset = text_offset;
        g_curr_book_cntx_p->ebr_last_search_type = search_type;
        mmi_ucs2cpy(g_curr_book_cntx_p->ebr_last_search_string_input, ebr_search_string_input);
        g_curr_book_cntx_p->search_flag_is_on = 0;
        /* g_curr_book_cntx_p->search_found_flag=0; */
    }

    FS_Close(nfo_hnd_local);
    FS_Close(file_hnd);
    return search_status;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_search_string_algo_find_next
 * DESCRIPTION
 *  String search algo for find next
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL ebr_frm_search_string_algo_find_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL search_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->find_next_flag = TRUE;
    search_status = ebr_frm_search_string_algo(
                        (ebr_app_search_type_enum) g_curr_book_cntx_p->ebr_last_search_type,
                        (S8*) g_curr_book_cntx_p->ebr_last_search_string_input,
                        MMI_FALSE);
    g_curr_book_cntx_p->find_next_flag = FALSE;
    return search_status;
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_last_search_string
 * DESCRIPTION
 *  get last search string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_last_search_string(S8 **last_search_string)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *last_search_string = g_curr_book_cntx_p->ebr_last_search_string_input;
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_data_for_display
 * DESCRIPTION
 *  get the current position from GUI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_data_for_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 shared_bytes;

    S32 last_text_offset_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_paging_multiline_get_current_page(
        &g_curr_book_cntx_p->last_displayed_page_id,
        &g_curr_book_cntx_p->last_displayed_offset,
        &shared_bytes,
        &g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage,
        &last_text_offset_y);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_reset_for_new_book
 * DESCRIPTION
 *  Reset the values for a new file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
ebr_frm_nfo_create_type_errors_enum ebr_frm_reset_for_new_book(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ebr_frm_nfo_create_type_errors_enum error_type = EBR_FRM_NFO_CREATE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->ebr_frm_end_book_flag = 1;
    g_curr_book_cntx_p->is_book_in_unicode = FALSE;
    g_curr_book_cntx_p->book_is_in_other_encoding_format = FALSE;
    g_curr_book_cntx_p->pdb_converted_to_text = FALSE;
    ebr_frm_reset_find_next_data();
    ebr_frm_set_file_type();
    
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_PDB)
    {
        error_type = ebr_frm_open_book_create_nfo_file_pdb(g_curr_book_cntx_p->nfo_name);
    }
    else
    {
        error_type = ebr_frm_open_book_create_nfo_file_txt(g_curr_book_cntx_p->nfo_name);
    }
        
    if (!g_curr_book_cntx_p->src_application)
    {
        g_curr_book_cntx_p->src_application = EBR_FRM_SRC_APP_EBOOK;
    }

    return error_type;

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_file_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 strlen_file_name = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen_file_name = mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->nfo_name);
    if ((g_curr_book_cntx_p->nfo_name[strlen_file_name * 2 - 6] == 't') ||
        (g_curr_book_cntx_p->nfo_name[strlen_file_name * 2 - 6] == 'T'))
    {
        g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_TXT;
    }
    else
    {
        g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_PDB;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_convert_to_upper
 * DESCRIPTION
 *  CCase Conversion
 * PARAMETERS
 *  decoded_buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_convert_to_upper(S16 *decoded_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen((const S8*)decoded_buffer);
    for (i = 0; i < length; i++)
    {
        if ((decoded_buffer[i] >= 97) && (decoded_buffer[i] <= 122))
        {
            decoded_buffer[i] = decoded_buffer[i] - 32;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_bm_search
 * DESCRIPTION
 *  Search Algo
 * PARAMETERS
 *  text_in_UCS2        [IN]        
 *  pat                 [IN]        
 *  start_pos           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 ebr_frm_bm_search(S16 *text_in_UCS2, S16 *pat, S32 *start_pos,U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S32 len = mmi_ucs2strlen((const S8*)pat);
    S32 temp, temp1, temp2, buffer_length = mmi_ucs2strlen((const S8*)text_in_UCS2);
    S32 start = len - 1 + (*start_pos + 1);
    S16 pos_array[32] = {0};
    S16 char_position_in_UCS2, char_position_in_ascii;
    S32 clus_len = 1;
	S32 s_size = size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Remove '\0' */
    for(s_size = s_size/2 - 1; s_size >= 0; s_size--)
    {
        if (text_in_UCS2[s_size] != 0)
        {
            break;
        }
    }	
	/* Set length of text */
	if (buffer_length < len)
	{
		return 0;
	}
    for (i = 0; i < len; i++)
    {
        pos_array[i] = len - ((i) + 1);
    }
    temp = len - 1; /* it is taken to remove the need of table */
    temp2 = temp1 = len - 2;
    while (temp >= 0)
    {
        while (temp1 >= 0)
        {
            if (pat[temp] != pat[temp1])
            {
                temp1--;
            }
            else
            {
                pos_array[temp1] = pos_array[temp];
                temp1--;
            }
        }
        temp1 = temp2 - 1;
        temp--;
    }
    while (start < buffer_length)
    {
        S32 count = 0, prev_start = 0;

        while (count < len)
        {
            if (text_in_UCS2[start - count] != pat[(len - 1) - count])
            {
                break;
            }
            else
            {
                count++;
            }
        }
    #ifdef  __MMI_INDIC_ALG__
        if (count == len)
        {
            U16 cluster_buffer[EBR_MAX_STR_SEARCH_LENGTH];  /* just to fill the cluster for the purpose of getting its length */

            clus_len = 0;
            ire_init_cluster_start_p((PU8) (text_in_UCS2 + start));
            ire_init_cluster_end_p((PU8) (text_in_UCS2 + (EBR_MAX_STR_SEARCH_LENGTH / 2)));
			clus_len = ire_get_cluster(cluster_buffer);
        }
    #endif /*  __MMI_INDIC_ALG__ */ 
        if (count == len && clus_len == 1)
        {
            *start_pos = (start - count + 1);
            break;
        }
        else
        {
            char_position_in_UCS2 = 0;
            char_position_in_ascii = 0;
            prev_start = start;
            while (char_position_in_ascii < len && (text_in_UCS2[start - count] != pat[char_position_in_UCS2] || start - count < (*start_pos) + len))
            {
                char_position_in_UCS2++;
                char_position_in_ascii++;
            }
            if (text_in_UCS2[start - count] == pat[char_position_in_UCS2])
            {
                if (pos_array[char_position_in_ascii] - count < 0)
                {
                    start++;
                }
                else
                {
                    start += (pos_array[char_position_in_ascii] - count);
                }
            }
            else
            {
				start += (len - count);
            }
            if (prev_start == start)
            {
                start += len;
            }
        }

    }
    if (start >= buffer_length)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_multiline_input_box_get_page
 * DESCRIPTION
 *  Create the linked list
 * PARAMETERS
 *  start_id            [IN]        
 *  end_id              [IN]        
 *  buffer_local        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_paging_multiline_input_box_get_page(U32 start_id, U32 end_id, PU8 buffer_local)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Code Implementation to get the next page */
    U8 mmiEncoding = 0;
    S32 buffer_length;
    S16 ebr_page_size;
    U8* buffer_start;
	U8 UCS2headerle[] = {0xFF,0xFE};
    U8 UCS2headerbe[] = {0xFE,0xFF};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->g_start_id = start_id;
    g_curr_book_cntx_p->g_end_id = end_id;

    ebr_frm_get_record(end_id);
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        ebr_page_size = EBR_PAGE_SIZE * 2;
    }
    else
    {
        ebr_page_size = EBR_PAGE_SIZE;
    }
    end_id -= (EBR_RECORD_SIZE_MAX / (ebr_page_size)) * (g_curr_book_cntx_p->gcurrent_record_id - 1);

    memset(g_curr_book_cntx_p->buffer, 0, EBR_RECORD_SIZE_MAX);

    memcpy(g_curr_book_cntx_p->buffer, g_curr_book_cntx_p->start + ebr_page_size * (end_id), ebr_page_size);

    mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);

    if ((mmiEncoding == MMI_CHSET_UCS2 || g_curr_book_cntx_p->book_is_in_other_encoding_format) && g_curr_book_cntx_p->g_start_id == 0)    
    {
        buffer_start = g_curr_book_cntx_p->buffer;
        
        while (!mmi_ucs2ncmp((S8*)buffer_start, (S8*)UCS2headerle,1))
        {
            buffer_start[0] = WHITE_SPACE;
            buffer_start[1] = 0;
            buffer_start += 2;
        }

        while (!mmi_ucs2ncmp((S8*)buffer_start, (S8*)UCS2headerbe,1))
        {
            buffer_start[0] = WHITE_SPACE;
            buffer_start[1] = 0;
            buffer_start += 2;
        }
    }

    memset(buffer_local, 0, EBR_PAGE_SIZE * 2);
    switch (mmiEncoding)
    {
        case MMI_CHSET_UCS2:
            if (g_curr_book_cntx_p->is_book_in_unicode)
            {
                memcpy(buffer_local, g_curr_book_cntx_p->buffer, ebr_page_size);
            }
            else
            {
                mmi_ucs2ncpy((PS8) buffer_local, (PS8) g_curr_book_cntx_p->buffer, ebr_page_size);
            }
            break;
        case MMI_CHSET_WESTERN_WIN:
            mmi_asc_n_to_ucs2((PS8) buffer_local, (PS8) g_curr_book_cntx_p->buffer, ebr_page_size);
            break;
        default:
            if (g_curr_book_cntx_p->is_book_in_unicode)
            {
                /* memset(g_curr_book_cntx_p->page_buffer,0,EBR_PAGE_SIZE*2); */
                buffer_length = mmi_chset_convert(
                                    (mmi_chset_enum) mmiEncoding,
                                    MMI_CHSET_UCS2,
                                    (char*)g_curr_book_cntx_p->buffer,
                                    (char*)buffer_local,
                                    ebr_page_size);
                /* memcpy(buffer_local,g_curr_book_cntx_p->page_buffer,buffer_length); */
            }
            else
                //mmi_asc_n_to_ucs2((PS8)buffer_local,(PS8)g_curr_book_cntx_p->buffer,ebr_page_size);
                //mmi_ucs2ncpy((PS8)buffer_local,(PS8)g_curr_book_cntx_p->buffer,ebr_page_size);
            {
                memcpy(buffer_local, g_curr_book_cntx_p->buffer, ebr_page_size);
                /* mmi_ucs2ncpy((PS8) buffer_local, (PS8) g_curr_book_cntx_p->buffer, ebr_page_size); */
            }

            break;
    }
    buffer_length = mmi_ucs2strlen((const S8*)buffer_local);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebook_util_get_chset
 * DESCRIPTION
 *  Get the encoding scheme
 * PARAMETERS
 *  src_chset       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_ebook_util_get_chset(U8 src_chset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (src_chset)
    {
        case EBOOK_UCS:
            return MMI_CHSET_UCS2;
        case EBOOK_UTF8:
            return MMI_CHSET_UTF8;
    #ifdef __MMI_CHSET_BIG5__
        case EBOOK_BIG5:
            return MMI_CHSET_BIG5;
    #endif /* __MMI_CHSET_BIG5__ */ 
    #ifdef __MMI_CHSET_GB2312__
        case EBOOK_GB2312:
            return MMI_CHSET_GB2312;
    #endif /* __MMI_CHSET_GB2312__ */ 

    #ifdef __MMI_CHSET_ARABIC_ISO__
        case EBOOK_ARABIC_ISO:
            return MMI_CHSET_ARABIC_ISO;
    #endif /* __MMI_CHSET_ARABIC_ISO__ */ 
    #ifdef __MMI_CHSET_ARABIC_WIN__
        case EBOOK_ARABIC_WINDOWS:
            return MMI_CHSET_ARABIC_WIN;
    #endif /* __MMI_CHSET_ARABIC_WIN__ */ 
    #ifdef __MMI_CHSET_BALTIC_ISO__
        case EBOOK_BALTIC_ISO:
            return MMI_CHSET_BALTIC_ISO;
    #endif /* __MMI_CHSET_BALTIC_ISO__ */ 
    #ifdef __MMI_CHSET_BALTIC_WIN__
        case EBOOK_BALTIC_WINDOWS:
            return MMI_CHSET_BALTIC_WIN;
    #endif /* __MMI_CHSET_BALTIC_WIN__ */ 
    #ifdef __MMI_CHSET_CEURO_ISO__
        case EBOOK_CENTRAL_EUROPEAN_ISO:
            return MMI_CHSET_CEURO_ISO;
    #endif /* __MMI_CHSET_CEURO_ISO__ */ 
    #ifdef __MMI_CHSET_CEURO_WIN__
        case EBOOK_CENTRAL_EUROPEAN_WINDOWS:
            return MMI_CHSET_CEURO_WIN;
    #endif /* __MMI_CHSET_CEURO_WIN__ */ 
    #ifdef __MMI_CHSET_GREEK_ISO__
        case EBOOK_GREEK_ISO:
            return MMI_CHSET_GREEK_ISO;
    #endif /* __MMI_CHSET_GREEK_ISO__ */ 
    #ifdef __MMI_CHSET_GREEK_WIN__
        case EBOOK_GREEK_WINDOWS:
            return MMI_CHSET_GREEK_WIN;
    #endif /* __MMI_CHSET_GREEK_WIN__ */ 
    #ifdef __MMI_CHSET_HEBREW_ISO__
        case EBOOK_HEBREW_ISO:
            return MMI_CHSET_HEBREW_ISO;
    #endif /* __MMI_CHSET_HEBREW_ISO__ */ 
    #ifdef __MMI_CHSET_HEBREW_WIN__
        case EBOOK_HEBREW_WINDOWS:
            return MMI_CHSET_HEBREW_WIN;
    #endif /* __MMI_CHSET_HEBREW_WIN__ */ 
    #ifdef __MMI_CHSET_LATIN_ISO__
        case EBOOK_LATIN_ISO:
            return MMI_CHSET_LATIN_ISO;
    #endif /* __MMI_CHSET_LATIN_ISO__ */ 
    #ifdef __MMI_CHSET_NORDIC_ISO__
        case EBOOK_NORDIC_ISO:
            return MMI_CHSET_NORDIC_ISO;
    #endif /* __MMI_CHSET_NORDIC_ISO__ */ 
    #ifdef __MMI_CHSET_SEURO_ISO__
        case EBOOK_SOURTH_EUROPEAN_ISO:
            return MMI_CHSET_SEURO_ISO;
    #endif /* __MMI_CHSET_SEURO_ISO__ */ 
    #ifdef __MMI_CHSET_TURKISH_ISO__
        case EBOOK_TURKISH_ISO:
            return MMI_CHSET_TURKISH_ISO;
    #endif /* __MMI_CHSET_TURKISH_ISO__ */ 
    #ifdef __MMI_CHSET_TURKISH_WIN__
        case EBOOK_TURKISH_WINDOWS:
            return MMI_CHSET_TURKISH_WIN;
    #endif /* __MMI_CHSET_TURKISH_WIN__ */ 
    #ifdef __MMI_CHSET_WESTERN_ISO__
        case EBOOK_WESTERN_ISO:
            return MMI_CHSET_WESTERN_ISO;
    #endif /* __MMI_CHSET_WESTERN_ISO__ */ 
    #ifdef __MMI_CHSET_WESTERN_WIN__
        case EBOOK_WESTERN_WINDOWS:
            return MMI_CHSET_WESTERN_WIN;
    #endif /* __MMI_CHSET_WESTERN_WIN__ */ 
    #ifdef __MMI_CHSET_GB18030__
        case EBOOK_GB18030:
            return MMI_CHSET_GB18030;
    #endif /* __MMI_CHSET_GB18030__ */ 
        default:
            return MMI_CHSET_TOTAL; /* unsupported charset */
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_delete_ebook
 * DESCRIPTION
 *  Delete the book.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_delete_ebook()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    S32 retval_book,retval_nfo = 0;
    S32 local_nfo_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete PDB/TXT File */
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_PDB)
    {
        local_nfo_id = ebr_fmgr_get_nfo_id_for_pdb_file(
                        g_curr_book_cntx_p->memory_type_selected,
                        (PS8) g_curr_book_cntx_p->nfo_name);
    }
    else
    {
        local_nfo_id = ebr_fmgr_get_nfo_id_for_txt_file(
                        g_curr_book_cntx_p->memory_type_selected,
                        (PS8) g_curr_book_cntx_p->nfo_name);
    }

    if (local_nfo_id > 0)
    {
        mmi_ucs2cpy((S8*) nfo_path, (PS8) ebr_frm_get_nfo_file_name(local_nfo_id));
    }
    retval_nfo = FS_Delete((const WCHAR*)nfo_path);

    mmi_ucs2cpy(
        (S8*) nfo_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) nfo_path, (PS8) g_curr_book_cntx_p->nfo_name);
    retval_book = FS_Delete((const WCHAR*)nfo_path);
	return retval_book;

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_save_settings_in_nfo_file
 * DESCRIPTION
 *  Save settings in Nfo file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_save_settings_in_nfo_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    S32 retval;

    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);

    FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
    retval = FS_Write(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
    FS_Close(nfo_hnd);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_close_the_ebook
 * DESCRIPTION
 *  Variable set before closing the book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 ebr_frm_close_ebook = 0;
void ebr_frm_close_the_ebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_close_ebook = 1;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_ebook_exit
 * DESCRIPTION
 *  Close the book and exit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL ebr_frm_ebook_exit(ebr_frm_exit_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 local_nfo_id;
    S16 highlight_id;
    U32 size;
    U32 page_id;
    S32 text_offset;
    U8 shared_bytes;
    U8 last_showed_percentage;
    S32 last_text_offset_y;
    S32 retval;
    FS_HANDLE nfo_hnd;
    S16 error;
    static pBOOL is_src_app_file_manager = FALSE;

    S16 ebr_page_size, auto_scroll_staus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_src_app_file_manager = FALSE;
    if (g_curr_book_cntx_p->state_recursive_conversion != EBR_FRM_NFO_CONVERSION_COMPLETED)
    {
        auto_scroll_staus = ebr_frm_get_auto_scroll_flag_status();
        if (auto_scroll_staus)
        {
            TurnOffBacklight();
        }

        if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
        {
            ebr_page_size = EBR_PAGE_SIZE * 2;
        }
        else
        {
            ebr_page_size = EBR_PAGE_SIZE;
        }
        if (type == EBR_FRM_EXIT_BY_GOBACK_TO_BOOKSHELF)
        {
            if (g_curr_book_cntx_p->state_recursive_conversion != EBR_FRM_CONVERSION_UNDERWAY)
            {
                wgui_paging_multiline_get_current_page(
                    &page_id,
                    &text_offset,
                    &shared_bytes,
                    &last_showed_percentage,
                    &last_text_offset_y);
                ebr_frm_set_page_info(page_id, text_offset, shared_bytes, last_showed_percentage, last_text_offset_y);
                g_curr_book_cntx_p->g_nfo_book_struct.offset = text_offset;
                g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = page_id;
                if (g_curr_book_cntx_p->reset_last_display_info == MMI_TRUE)
                {
                    g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = 0;
                    g_curr_book_cntx_p->reset_last_display_info = MMI_FALSE;
                }
                else
                {
                    g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = last_showed_percentage;
                }
                g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = 0;
                g_curr_book_cntx_p->g_nfo_book_struct.last_text_offset_y = last_text_offset_y;
            }
            else
            {
                g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
                g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = 0;
                g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = 0;
                g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = 0;
                g_curr_book_cntx_p->g_nfo_book_struct.last_text_offset_y = 0;
            }
        }
        g_curr_book_cntx_p->src_application = ebr_frm_fmgr_get_application_type();
        if (g_curr_book_cntx_p->src_application != EBR_FRM_SRC_APP_FMGR)
        {
            g_curr_book_cntx_p->g_last_nfo_id_allocated = 0;

            ReadValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
            if (local_nfo_id > 0)
            {
                if (ebr_frm_close_ebook)
                {
                    local_nfo_id = 0;
                    highlight_id = 0;
                    WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
                    WriteValue(
                        NVRAM_EBOOK_LAST_HIGHLIGHT_ID,
                        (void*)&g_curr_book_cntx_p->current_highlight_book_id,
                        DS_SHORT,
                        &error);
                    ebr_frm_close_ebook = 0;
                }
                else
                {
                    WriteValue(
                        NVRAM_EBOOK_LAST_HIGHLIGHT_ID,
                        (void*)&g_curr_book_cntx_p->current_highlight_book_id,
                        DS_SHORT,
                        &error);
                }
            }
            else
            {
                local_nfo_id = 0;
                WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);

            }
        }
        else
        {
            is_src_app_file_manager = TRUE;
        }
        nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
        if (nfo_hnd > 0)
        {
        FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
        retval = FS_Write(
                    nfo_hnd,
                    &g_curr_book_cntx_p->g_nfo_book_struct,
                    sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
                    &size);
        FS_Close(nfo_hnd);
    }
    }
    else
    {
        if (g_curr_book_cntx_p->src_application != EBR_FRM_SRC_APP_FMGR)
        {
            is_src_app_file_manager = FALSE;
        }
        else
        {
            is_src_app_file_manager = TRUE;
        }

    }
    return is_src_app_file_manager;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_find_next_flag
 * DESCRIPTION
 *  Clears flags for find next on scrolling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_find_next_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->status_for_resetting_find_next_data = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_book_type
 * DESCRIPTION
 *  Gets the type of the book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 *ebr_frm_get_book_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 type[EBR_DISPLAY_INFO_DATA * ENCODING_LENGTH];
    S32 strlen_file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen_file_name = mmi_ucs2strlen((const S8*)g_curr_book_cntx_p->nfo_name);
    if (g_curr_book_cntx_p->nfo_name[strlen_file_name * 2 - 6] == 'p' ||
        g_curr_book_cntx_p->nfo_name[strlen_file_name * 2 - 6] == 'P')
    {
        g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_PDB;
    }
    else
    {
        g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_TXT;
    }

    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_PDB)
    {
        strcpy((char*)type, (const char*)"PDB");
    }
    else
    {
        strcpy((char*)type, (const char*)"TXT");
    }

    return type;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_read_from_nvram
 * DESCRIPTION
 *  Get the default value from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ebr_frm_read_from_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 local_nfo_id;
    S16 error;
    MMI_BOOL status;
    FS_HANDLE nfo_hnd_local;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);

    status = mmi_fmgr_is_drive_letter_valid(g_setting_list->memory_type);

    if (status && FS_GetDevStatus((UINT)g_setting_list->memory_type, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        status = MMI_FALSE;
    }

    if (status == MMI_TRUE)
    {
        g_curr_book_cntx_p->memory_type_selected = g_setting_list->memory_type;
    }
    else
    {
       g_curr_book_cntx_p->memory_type_selected = (U8)MMI_PUBLIC_DRV; 
       local_nfo_id = 0;
       WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
    }
    mmi_ucs2cpy((S8*) g_curr_book_cntx_p->nfo_path, (PS8) ebr_frm_get_nfo_file_name(local_nfo_id));
    nfo_hnd_local = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
    if (nfo_hnd_local < 0)
    {
        local_nfo_id = 0;
        WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
    }
    FS_Close(nfo_hnd_local);
    return local_nfo_id;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_rwrite_into_nvram
 * DESCRIPTION
 *  Write Nfo id in NVRAM
 * PARAMETERS
 *  local_nfo_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_rwrite_into_nvram(S16 local_nfo_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_write_settings_in_nvram
 * DESCRIPTION
 *  Write settings in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_write_settings_in_nvram()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_list->common_settings = g_curr_book_cntx_p->g_nfo_book_struct.settings;
    g_setting_list->memory_type = g_curr_book_cntx_p->g_nfo_book_struct.memory_type;
    WriteRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_default_settings_value
 * DESCRIPTION
 *  get the default settings value
 * PARAMETERS
 *  g_ebookset_cntx_p               [IN]        
 *  ebr_set_local_setting_flag      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_default_settings_value(EBOOKSET_CNTX *g_ebookset_cntx_p, S16 ebr_set_local_setting_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ebr_set_local_setting_flag == 1)
    {
        g_ebookset_cntx_p->inlineHighligtItemFontStyle = g_curr_book_cntx_p->g_nfo_book_struct.settings.font_style;
        g_ebookset_cntx_p->inlineHighligtItemFontSize = g_curr_book_cntx_p->g_nfo_book_struct.settings.font_size;
        g_ebookset_cntx_p->inlineHighligtItemScrollBy =
            g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_type;
        g_ebookset_cntx_p->inlineHighligtItemAutoScroll =
            g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag;
        g_ebookset_cntx_p->inlineHighligtItemScrollSpeed =
            g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_speed;
        g_ebookset_cntx_p->inlineHighligtItemFulScreenMode = g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode;
        g_ebookset_cntx_p->inlineHighligtItemEncodingFormat =
            g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format;
    }
    else
    {
        ebr_frm_setting_struct g_setting;
        ebr_frm_setting_struct *g_setting_list = &g_setting;

        ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
        g_ebookset_cntx_p->inlineHighligtItemEncodingFormat = g_setting_list->common_settings.encoding_format;
        g_ebookset_cntx_p->inlineHighligtItemFontSize = g_setting_list->common_settings.font_size;
        g_ebookset_cntx_p->inlineHighligtItemFontStyle = g_setting_list->common_settings.font_style;
         
        g_ebookset_cntx_p->inlineHighligtItemFulScreenMode = g_setting_list->common_settings.screen_mode;
        g_ebookset_cntx_p->inlineHighligtItemAutoScroll =
            g_setting_list->common_settings.auto_scroll_settings.scroll_flag;
        g_ebookset_cntx_p->inlineHighligtItemScrollSpeed =
            g_setting_list->common_settings.auto_scroll_settings.scroll_speed;
        g_ebookset_cntx_p->inlineHighligtItemScrollBy =
            g_setting_list->common_settings.auto_scroll_settings.scroll_type;

		/* memory type */
		status = mmi_fmgr_is_drive_letter_valid(g_setting_list->memory_type);
        if (status && FS_GetDevStatus((UINT)g_setting_list->memory_type, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
        {
            status = MMI_FALSE;
        }

        if (status == MMI_TRUE && g_curr_book_cntx_p->memory_type_selected == g_setting_list->memory_type)
        {
            g_ebookset_cntx_p->inlineHighligtItemSelectMemory = g_setting_list->memory_type;
        }
        else
        {
           g_ebookset_cntx_p->inlineHighligtItemSelectMemory = (U8)MMI_PUBLIC_DRV; 
        }       

    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_save_settings_screen_mode
 * DESCRIPTION
 *  save the screen mode in NFO
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_save_settings_screen_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    S32 retval;
    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode == 0)
    {
        g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode = 1;
    }
    else
    {
        g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode = 0;
    }
    g_curr_book_cntx_p->reset_last_display_info = MMI_TRUE;
    nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
    FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
    retval = FS_Write(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
    FS_Close(nfo_hnd);
    return g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_save_settings_scroll
 * DESCRIPTION
 *  save the scroll settings in NFO
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_save_settings_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    S32 retval;
    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag == 0)
    {
        g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag = 1;
    }
    else
    {
        g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag = 0;
    }
    nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
    FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
    retval = FS_Write(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
    FS_Close(nfo_hnd);
    return g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_nfo_id_for_txt_file
 * DESCRIPTION
 *  Ge the nfo id for Text File
 * PARAMETERS
 *  drive_type      [IN]        
 *  file_name       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ebr_fmgr_get_nfo_id_for_txt_file(S8 drive_type, PS8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U32 size;
    U8 ebook_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    U8 tmp_str[MAX_EBOOK_NAME_LENGTH] = {0};
    U8 end_footer_buffer[TXT_FOOTER_END_SIZE];
    U8 start_footer_buffer[TXT_FOOTER_START_SIZE];
    S32 local_nfo_id = 0;
    S32 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->memory_type_selected = drive_type;
    mmi_ucs2cpy((S8*) ebook_file_name, (S8*) ebr_frm_get_file_path(drive_type, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) ebook_file_name, (PS8) file_name);
    file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_ONLY);
    FS_GetFileSize(file_hnd, (U32*) & file_size);
    if (file_hnd > 0)
    {
        if (FS_Seek(file_hnd, -TXT_FOOTER_END_SIZE, FS_FILE_END) != FS_INVALID_FILE_POS)
        {
        FS_Read(file_hnd, end_footer_buffer, TXT_FOOTER_END_SIZE, &size);
        }
        else
        {
            memset(end_footer_buffer, 0, sizeof(end_footer_buffer));
        }
        if (FS_Seek(file_hnd, -TXT_FOOTER_START_SIZE - TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH, FS_FILE_END) !=
            FS_INVALID_FILE_POS)
            {
            FS_Read(file_hnd, start_footer_buffer, TXT_FOOTER_START_SIZE, &size);
            }
            else
            {
            memset(start_footer_buffer, 0, sizeof(start_footer_buffer));
            }
        if (strncmp((PS8) end_footer_buffer, (PS8) EBR_TXT_FOOTER_END, TXT_FOOTER_END_SIZE) == 0 &&
            strncmp((PS8) start_footer_buffer, (PS8) EBR_TXT_FOOTER_START, TXT_FOOTER_START_SIZE) == 0)
            {
            FS_Read(file_hnd, tmp_str, MAX_EBOOK_NAME_LENGTH, &size);
            local_nfo_id = atoi((const char*)tmp_str);
        }
        FS_Close(file_hnd);
        return local_nfo_id;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_nfo_id_for_pdb_file
 * DESCRIPTION
 *  Ge the nfo id for PDB File
 * PARAMETERS
 *  drive_type      [IN]        
 *  file_name       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ebr_fmgr_get_nfo_id_for_pdb_file(S8 drive_type, PS8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U32 size;
    ebr_frm_database_hdr_type file_header;
    U8 ebook_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->memory_type_selected = drive_type;
    mmi_ucs2cpy((S8*) ebook_file_name, (S8*) ebr_frm_get_file_path(drive_type, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) ebook_file_name, (PS8) file_name);
    file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_ONLY);
    if (file_hnd > 0)
    {
        if (FS_Read(file_hnd, &file_header, EBR_FRM_DATABASE_HEADER_SIZE, &size) == FS_NO_ERROR)
        {
            FS_Close(file_hnd);
            if (file_header.modification_date > 32768)
            {
                return 0;
            }
            else
            {
                return file_header.modification_date;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_remove_nfo_id_info_from_file
 * DESCRIPTION
 *  Remove the nfo id info from the file
 * PARAMETERS
 *  drive_type                      [IN]        
 *  full_path_with_file_name        [IN]        
 *  book_type                       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_remove_nfo_id_info_from_file(S32 drive_type, PS8 full_path_with_file_name, ebr_frm_filetype_enum book_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U32 size;
    ebr_frm_database_hdr_type file_header;
    S32 offset = 0;
    doc_record0 rec0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->memory_type_selected = drive_type;
    //      mmi_ucs2cpy((S8*)ebook_file_name ,(S8*) ebr_frm_get_file_path(drive_type,EBR_FRM_SEARCH_DEFAULT));
    //      mmi_ucs2cat((PS8)ebook_file_name, (PS8)file_name);
    file_hnd = FS_Open((const WCHAR*)full_path_with_file_name, FS_READ_WRITE);
    if (file_hnd > 0)
    {
        if (book_type == EBR_FRM_FILE_TYPE_TXT)
        {
            FS_Seek(file_hnd, -TXT_FOOTER_START_SIZE - TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH, FS_FILE_END);
            FS_Truncate(file_hnd);
        }
        else
        {
            if (FS_Read(file_hnd, &file_header, EBR_FRM_DATABASE_HEADER_SIZE, &size) == FS_NO_ERROR)
            {
                SEEK_REC_ENTRY(file_hnd, 0);
                if (FS_Read(file_hnd, &offset, 4, &size) == FS_NO_ERROR)
                {
                    offset = ntohl(offset);
                }
                FS_Seek(file_hnd, offset, FS_FILE_BEGIN);
                FS_Read(file_hnd, &rec0, sizeof rec0, &size);
                file_header.modification_date = 32769;
                FS_Seek(file_hnd, 0, FS_FILE_BEGIN);
                FS_Write(file_hnd, &file_header, sizeof(ebr_frm_database_hdr_type), &size);
            }
        }

        FS_Close(file_hnd);

    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_add_to_book_shelf
 * DESCRIPTION
 *  Add file to bookshelf.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
ebr_frm_nfo_create_type_errors_enum ebr_frm_add_to_book_shelf()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ebr_frm_nfo_create_type_errors_enum nfo_create_type_error = EBR_FRM_NFO_CREATE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->src_application = ebr_frm_fmgr_get_application_type();
    if (g_curr_book_cntx_p->g_fmgr_book_type == EBR_FRM_FILE_TYPE_PDB)  /* Means PDB file */
    {
        nfo_create_type_error = ebr_frm_open_book_create_nfo_file_pdb(g_curr_book_cntx_p->nfo_name);
    }
    else
    {
        nfo_create_type_error = ebr_frm_open_book_create_nfo_file_txt(g_curr_book_cntx_p->nfo_name);
    }
    return nfo_create_type_error;

}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_delete_from_ebook
 * DESCRIPTION
 *  Delete file from File manager
 * PARAMETERS
 *  drive_type      [IN]        
 *  file_name       [IN]        
 *  book_type       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 ebr_fmgr_delete_from_ebook(S16 drive_type, S8 *file_name, ebr_frm_filetype_enum book_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ebook_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    S32 retval = -1;
    S16 local_nfo_id;
    ebr_frm_database_hdr_type file_header;
    FS_HANDLE file_hnd;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check for the type of file .. delete the cerrseponding NFO file also. */
    mmi_ucs2cpy(
        (S8*) ebook_file_name,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) ebook_file_name, (PS8) file_name);
    file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_ONLY);
    g_curr_book_cntx_p->g_fmgr_book_type = book_type;
    if (g_curr_book_cntx_p->g_fmgr_book_type == EBR_FRM_FILE_TYPE_PDB)  /* Means PDB file */
    {
        if (FS_Read(file_hnd, &file_header, EBR_FRM_DATABASE_HEADER_SIZE, &size) == FS_NO_ERROR)
        {
            if (file_header.modification_date > 32768)  /* Means no nfo file has been created. */
            {
                FS_Close(file_hnd);
                retval = FS_Delete((const WCHAR*)ebook_file_name);
                return retval;
            }
            else
            {
                local_nfo_id = (S16) file_header.modification_date;
                FS_Close(file_hnd);
                retval = FS_Delete((const WCHAR*)ebook_file_name);

                FS_Delete((const WCHAR*)ebr_frm_get_nfo_file_name(local_nfo_id));
                return retval;

            }
        }
    }
    else
    {   /* this is a text file. Delete the text as well as the cerresponding nfo file if it exists */
        FS_Close(file_hnd);
        local_nfo_id = ebr_fmgr_get_nfo_id_for_txt_file((S8)drive_type, file_name);
        if (local_nfo_id <= 0)
        {
            /* Nfo file doenot exist . delete the file only. */
            retval = FS_Delete((const WCHAR*)ebook_file_name);
            return retval;
        }
        else
        {
            FS_Close(file_hnd);
            retval = FS_Delete((const WCHAR*)ebook_file_name);
            retval = FS_Delete((const WCHAR*)ebr_frm_get_nfo_file_name(local_nfo_id));
            return retval;
        }
    }
    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_set_drive_type
 * DESCRIPTION
 *  Get the drive type
 * PARAMETERS
 *  drive_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_fmgr_set_drive_type(ebr_memory_type_enum drive_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->memory_type_selected = drive_type;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_nfo_handle
 * DESCRIPTION
 *  Get the NFO handle
 * PARAMETERS
 *  void
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE ebr_frm_get_nfo_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    FS_HANDLE nfo_hnd_local;
    S16 local_nfo_id = 0;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->src_application = ebr_frm_fmgr_get_application_type();
    if (g_curr_book_cntx_p->src_application == EBR_FRM_SRC_APP_FMGR)
    {   /* Means it is from file manager */
        local_nfo_id = ebr_frm_fmgr_get_nfo_id();
        if (ebr_frm_get_drive_type() == *g_curr_book_cntx_p->fmgr_file_path) 
        {            
            WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
        }
    }
    else
    {
        /* Write the nfo name in NVRAM */
        ReadValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
        if (local_nfo_id == 0)
        {
            if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_PDB)
            {
                local_nfo_id = ebr_fmgr_get_nfo_id_for_pdb_file(
                                g_curr_book_cntx_p->memory_type_selected,
                                (PS8) g_curr_book_cntx_p->nfo_name);
            }
            else
            {
                local_nfo_id = ebr_fmgr_get_nfo_id_for_txt_file(
                                g_curr_book_cntx_p->memory_type_selected,
                                (PS8) g_curr_book_cntx_p->nfo_name);
            }
            WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
        }
    }
    mmi_ucs2cpy((S8*) g_curr_book_cntx_p->nfo_path, (PS8) ebr_frm_get_nfo_file_name(local_nfo_id));
    nfo_hnd_local = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
    if (nfo_hnd_local < 0)
    {
        return nfo_hnd_local;
    }
    FS_Seek(nfo_hnd_local, 0, FS_FILE_BEGIN);
    FS_Read(nfo_hnd_local, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(ebr_frm_book_struct), &size);
    mmi_ucs2cpy(
        (S8*) g_curr_book_cntx_p->book_name_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) g_curr_book_cntx_p->book_name_path, (PS8) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
    return nfo_hnd_local;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_get_drive_type
 * DESCRIPTION
 *  Get the drive type selected
 * PARAMETERS
 *  void
 * RETURNS
 *  S16
 *****************************************************************************/
S16 ebr_get_drive_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_curr_book_cntx_p->memory_type_selected;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_settings_and_save
 * DESCRIPTION
 *  Save the settings in nfo file
 * PARAMETERS
 *  g_ebookset_cntx_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_settings_and_save(EBOOKSET_CNTX *g_ebookset_cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ebr_frm_setting_struct g_setting;
    S16 error;
    S16 i;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->pdb_converted_to_text = FALSE;
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
	if(g_curr_book_cntx_p->g_nfo_book_struct.settings.font_size!=g_ebookset_cntx_p->inlineHighligtItemFontSize)
	{
		g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = g_curr_book_cntx_p->g_nfo_book_struct.offset;
		g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
	}
    g_curr_book_cntx_p->g_nfo_book_struct.settings.font_size = g_ebookset_cntx_p->inlineHighligtItemFontSize;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.font_style = g_ebookset_cntx_p->inlineHighligtItemFontStyle;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag =
        g_ebookset_cntx_p->inlineHighligtItemAutoScroll;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_speed =
        g_ebookset_cntx_p->inlineHighligtItemScrollSpeed;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_type =
        g_ebookset_cntx_p->inlineHighligtItemScrollBy;
    if (g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format ==
        g_ebookset_cntx_p->inlineHighligtItemEncodingFormat)
    {
        g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format =
            g_ebookset_cntx_p->inlineHighligtItemEncodingFormat;
    }
    else
    {
        g_curr_book_cntx_p->g_nfo_book_struct.temp_encoding_file_format = '\0';
        for (i = 0; i < EBR_FRM_MAX_NO_OF_BOOKMARKS; i++)
        {
            g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].offset = 0;
            g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].page_id = 0;
            mmi_ucs2cpy((PS8) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name, (PS8) NULL);
            g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].percentage_associated_with_book_mark = 0;
        }
        g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = 0;
        g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
        g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = 0;
        g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = 0;
        /* g_curr_book_cntx_p->g_nfo_book_struct.settings = g_setting_list->common_settings; */
        g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format =
            g_ebookset_cntx_p->inlineHighligtItemEncodingFormat;
        g_curr_book_cntx_p->g_nfo_book_struct.last_text_offset_y = 0;
        ebr_frm_recalc_book_size();
        ebr_frm_reset_find_next_data();

    }
    g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode = g_ebookset_cntx_p->inlineHighligtItemFulScreenMode;

    ebr_frm_save_settings_in_nfo_file();
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_recalc_book_size
 * DESCRIPTION
 *  Re calculate book size
 * PARAMETERS
 *  g_ebookset_cntx_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_recalc_book_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U32 book_size, size;
    S32 offset;
	U8 ebook_file_name[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    doc_record0 rec0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT)
    {
	mmi_ucs2cpy(
        (S8*) ebook_file_name,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) ebook_file_name, (S8*) g_curr_book_cntx_p->nfo_name);
    file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_WRITE);
    FS_GetFileSize(file_hnd, &book_size);
    FS_Close(file_hnd);
    
    g_curr_book_cntx_p->g_nfo_book_struct.book_size = 
        book_size + (-TXT_FOOTER_START_SIZE -TXT_FOOTER_END_SIZE - MAX_EBOOK_NAME_LENGTH);
    }
    else
    {
        file_hnd = FS_Open((const WCHAR*)ebook_file_name, FS_READ_WRITE);
        FS_Seek(file_hnd, EBR_FRM_DATABASE_HEADER_SIZE, FS_FILE_BEGIN);
        if (FS_Read(file_hnd, &offset, 4, &size) == FS_NO_ERROR)
            {
                offset = ntohl(offset);
            }
            FS_Seek(file_hnd, offset, FS_FILE_BEGIN);
            if (FS_Read(file_hnd, &rec0, sizeof rec0, &size) == FS_NO_ERROR)
            {
                g_curr_book_cntx_p->g_nfo_book_struct.book_size = ntohl(rec0.doc_size);
            }
    }

	ebr_frm_save_settings_in_nfo_file();
    
}
/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_settings_and_save_in_nvram
 * DESCRIPTION
 *  Save the settings in NVRAM
 * PARAMETERS
 *  g_ebookset_cntx_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_settings_and_save_in_nvram(EBOOKSET_CNTX *g_ebookset_cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->g_nfo_book_struct.settings.font_size = g_ebookset_cntx_p->inlineHighligtItemFontSize;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.font_style = g_ebookset_cntx_p->inlineHighligtItemFontStyle;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag =
        g_ebookset_cntx_p->inlineHighligtItemAutoScroll;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_speed =
        g_ebookset_cntx_p->inlineHighligtItemScrollSpeed;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_type =
        g_ebookset_cntx_p->inlineHighligtItemScrollBy;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format =
        g_ebookset_cntx_p->inlineHighligtItemEncodingFormat;
    g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode = g_ebookset_cntx_p->inlineHighligtItemFulScreenMode;
    g_curr_book_cntx_p->g_nfo_book_struct.memory_type = g_ebookset_cntx_p->inlineHighligtItemSelectMemory;
    ebr_frm_write_settings_in_nvram();
	g_curr_book_cntx_p->memory_type_selected = g_curr_book_cntx_p->g_nfo_book_struct.memory_type;
}

/*****************************************************************************
 * FUNCTION
 *  ebr_is_memory_type_changed
 * DESCRIPTION
 *  Used to check if memory type is changed by user setting.
 * PARAMETERS
 *  g_ebookset_cntx_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL ebr_is_memory_type_changed(EBOOKSET_CNTX *g_ebookset_cntx_p)
{
    if (g_curr_book_cntx_p->memory_type_selected != g_ebookset_cntx_p->inlineHighligtItemSelectMemory)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  ebr_get_book_mark_name_list
 * DESCRIPTION
 *  Call back to get the book mark names
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [IN]        
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL ebr_get_book_mark_name_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) str_buff,
        (S8*) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[item_index].bookmark_name);
    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_default_name_of_book_marks
 * DESCRIPTION
 *  Get default bookmark string
 * PARAMETERS
 *  void
 * RETURNS
 *  S16
 *****************************************************************************/
void ebr_frm_get_default_name_of_book_marks(S8* bookmark_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 no_of_book_marks = 0;
    S16 counter = 0;
    S8 counter_ancii [EBR_FRM_MAX_BOOKMARK_NAME_SIZE + 1];
    S8 counter_ucs2 [(EBR_FRM_MAX_BOOKMARK_NAME_SIZE + 1) *ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) bookmark_name, GetString((U16)STR_EBOOK_DEFAULT_BOOKMARK));    

	gui_itoa(counter, (UI_string_type) counter_ancii, EBR_FRM_MAX_NO_OF_BOOKMARKS);
    mmi_asc_to_ucs2((S8*) counter_ucs2, (S8*) counter_ancii);
    mmi_ucs2cat(bookmark_name, counter_ucs2);
        
    while (g_curr_book_cntx_p->g_nfo_book_struct.book_marks[no_of_book_marks].bookmark_name[0] != 0 && (no_of_book_marks<EBR_FRM_MAX_NO_OF_BOOKMARKS))
    {        
        if(mmi_ucs2cmp(bookmark_name, (S8*)g_curr_book_cntx_p->g_nfo_book_struct.book_marks[no_of_book_marks].bookmark_name) != 0)
        {
            no_of_book_marks++;
        }
        else
        {
            no_of_book_marks = 0;
            counter++;
            mmi_ucs2cpy((S8*) bookmark_name, GetString((U16)STR_EBOOK_DEFAULT_BOOKMARK));
            gui_itoa(counter, (UI_string_type) counter_ancii, EBR_FRM_MAX_NO_OF_BOOKMARKS);
            mmi_asc_to_ucs2((S8*) counter_ucs2, (S8*) counter_ancii);
            mmi_ucs2cat(bookmark_name, counter_ucs2);
            
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_count_of_book_marks
 * DESCRIPTION
 *  Count the number of book marks present
 * PARAMETERS
 *  void
 * RETURNS
 *  S16
 *****************************************************************************/
S16 ebr_frm_get_count_of_book_marks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 no_of_book_marks = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((g_curr_book_cntx_p->g_nfo_book_struct.book_marks[no_of_book_marks].bookmark_name[0] != 0 || g_curr_book_cntx_p->g_nfo_book_struct.book_marks[no_of_book_marks].bookmark_name[1] != 0)
        && (no_of_book_marks<EBR_FRM_MAX_NO_OF_BOOKMARKS))
    {
        no_of_book_marks++;
    }
    return no_of_book_marks;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_full_screen_flag_status
 * DESCRIPTION
 *  Get the status of full screen flag
 * PARAMETERS
 *  void
 * RETURNS
 *  S16
 *****************************************************************************/
S16 ebr_frm_get_full_screen_flag_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_auto_scroll_flag_status
 * DESCRIPTION
 *  Get the status of full screen flag
 * PARAMETERS
 *  void
 * RETURNS
 *  S16
 *****************************************************************************/
S16 ebr_frm_get_auto_scroll_flag_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_create_new_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_create_new_file_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 memory_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&memory_type, g_curr_book_cntx_p->fmgr_file_path, 1);
    memset(g_curr_book_cntx_p->fmgr_file_path, 0, sizeof(g_curr_book_cntx_p->fmgr_file_path));
    g_curr_book_cntx_p->memory_type_selected = memory_type;
    mmi_ucs2cpy(
            (S8*) g_curr_book_cntx_p->fmgr_file_path,
            (S8*) ebr_frm_get_file_path(memory_type, EBR_FRM_SEARCH_DEFAULT));
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_is_book_shelf_path
 * DESCRIPTION
 *  Check whetther the path is for bookshelf
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 ebr_fmgr_is_book_shelf_path(PS8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    U8 fmgr_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};

    U32 driveCount = 0;
    S8 driveLatter[FMGR_TOTAL_STORAGE];    
    U8 driveNum;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(driveLatter, 0, FMGR_TOTAL_STORAGE);
    mmi_fmgr_get_exist_drive_letter(driveLatter, &driveNum);
    memcpy(fmgr_path, path, MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH);
        
    while (driveLatter[driveCount] != 0)
    {
        mmi_ucs2cpy((S8*) nfo_path, (S8*) ebr_frm_get_file_path(driveLatter[driveCount], EBR_FRM_SEARCH_DEFAULT));
        ebr_frm_convert_to_upper((S16*) nfo_path);
        ebr_frm_convert_to_upper((S16*) fmgr_path);    
        if (!mmi_ucs2cmp((S8*) nfo_path, (S8*) fmgr_path))
        {
    		g_curr_book_cntx_p->memory_type_selected = driveLatter[driveCount];
            return driveLatter[driveCount];             
        }
		driveCount++;
    }
    return -1;
        
}




/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *ebr_fmgr_get_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) g_curr_book_cntx_p->book_name_path;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_set_file_type
 * DESCRIPTION
 *  Set the file type
 * PARAMETERS
 *  file_name       [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_set_file_type(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 strlen_file_name = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen_file_name = mmi_ucs2strlen((const S8*)file_name);
    if ((g_curr_book_cntx_p->nfo_name[strlen_file_name * 2 - 6] == 't') ||
        (g_curr_book_cntx_p->nfo_name[strlen_file_name * 2 - 6] == 'T'))
    {
        g_curr_book_cntx_p->g_fmgr_book_type = EBR_FRM_FILE_TYPE_TXT;
    }
    else
    {
        g_curr_book_cntx_p->g_fmgr_book_type = EBR_FRM_FILE_TYPE_PDB;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_set_file_name
 * DESCRIPTION
 *  Sets the File name for File manager
 * PARAMETERS
 *  fmgr_file_name      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_set_file_name(PS8 fmgr_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) g_curr_book_cntx_p->book_name_path, (S8*) fmgr_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_set_selected_file_name
 * DESCRIPTION
 *  Gets the name of the selected book
 * PARAMETERS
 *  file_info       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_set_selected_file_name(FMGR_FILE_INFO_STRUCT *file_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cpy((S8*) g_curr_book_cntx_p->nfo_name, (S8*) file_info->file_name);
    g_curr_book_cntx_p->is_short = file_info->is_short;

}


/*****************************************************************************
 * FUNCTION
 *  ebr_get_selected_file_name
 * DESCRIPTION
 *  Gets the name of the selected book
 * PARAMETERS
 *  void
 * RETURNS
 *  S8*
 *****************************************************************************/
U8 *ebr_get_selected_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) g_curr_book_cntx_p->nfo_name;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_book_size
 * DESCRIPTION
 *  Gets the Size of the ebook
 * PARAMETERS
 *  void
 * RETURNS
 *  S8*
 *****************************************************************************/
S32 ebr_frm_get_book_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U32 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_create_book_path();
    file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
    FS_GetFileSize(file_hnd, (U32*) & file_size);
    FS_Close(file_hnd);
    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_create_book_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_create_book_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) g_curr_book_cntx_p->book_name_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((PS8) g_curr_book_cntx_p->book_name_path, (PS8) g_curr_book_cntx_p->nfo_name);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_book_name
 * DESCRIPTION
 *  Gets the Name of the Ebook
 * PARAMETERS
 *  void
 * RETURNS
 *  S8*
 *****************************************************************************/
S8 *ebr_frm_get_book_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) g_curr_book_cntx_p->nfo_name;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_restore_default_book_shelf_settings
 * DESCRIPTION
 *  Restores the default settings for Book shelf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_restore_default_book_shelf_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
    /* ebr_app_display_pop_up_default_settings_restored(); */
    ebr_frm_restore_default_settings_for_each_book(g_setting_list);
    return 1;
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_restore_default_nvram
 * DESCRIPTION
 *  Restores Factory Default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_restore_default_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
    g_setting_list->common_settings.encoding_format = EBOOK_WESTERN_WINDOWS;
    g_setting_list->common_settings.font_size = EBR_FONT_SIZE_MEDIUM;
    g_setting_list->common_settings.font_style = EBR_FONT_STYLE_NORMAL;
    g_setting_list->memory_type = (S8)MMI_PUBLIC_DRV;
    g_setting_list->common_settings.screen_mode = EBR_FULL_SCREEN_OFF;
    g_setting_list->common_settings.auto_scroll_settings.scroll_flag = EBR_SCROLL_OFF;
    g_setting_list->common_settings.auto_scroll_settings.scroll_speed = EBR_AUTO_SCROLL_SPEED_1;
    g_setting_list->common_settings.auto_scroll_settings.scroll_type = EBR_SCROLL_BY_PAGE;
    WriteRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_restore_default_settings_for_each_book
 * DESCRIPTION
 *  Restores the default settings for Book shelf
 * PARAMETERS
 *  g_setting_list      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_restore_default_settings_for_each_book(ebr_frm_setting_struct *g_setting_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    U8 filename[MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH];
    U32 driveCount = 0;
    S8 driveLatter[FMGR_TOTAL_STORAGE];
    U8 driveNum;
    S8 memory_type = g_curr_book_cntx_p->memory_type_selected;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(driveLatter, 0, FMGR_TOTAL_STORAGE);
    mmi_fmgr_get_exist_drive_letter(driveLatter, &driveNum);
    
    while (driveLatter[driveCount] != 0)
    {
        g_curr_book_cntx_p->memory_type_selected = driveLatter[driveCount];
        mmi_ucs2cpy(
            (S8*) path,
            (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_NFO));

        if ((fh_cur = FS_FindFirst(
                        (const WCHAR*)path,
                        0,
                        0,
                        &file_info,
                        (U16*) filename,
                        MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
        {
            do
            {
                if (!(file_info.Attributes & FS_ATTR_DIR))
                {
                    ebr_frm_open_nfo_file_and_restore_default(
                        g_curr_book_cntx_p->memory_type_selected,
                        filename,
                        g_setting_list);
                }
            } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                      FS_NO_ERROR));
            FS_FindClose(fh_cur);
        }
        driveCount++;
    }
    g_curr_book_cntx_p->memory_type_selected = memory_type;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_open_nfo_file_and_restore_default
 * DESCRIPTION
 *  Restores the default settings for each book
 * PARAMETERS
 *  memory_type_selected        [IN]        
 *  filename                    [IN]        
 *  g_setting_list              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_open_nfo_file_and_restore_default(
        S32 memory_type_selected,
        U8 *filename,
        ebr_frm_setting_struct *g_setting_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd;
    S8 path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    U32 size;
    S32 retval;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) path, (S8*) ebr_frm_get_file_path(memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) path, (S8*) filename);

    nfo_hnd = FS_Open((const WCHAR*)path, FS_READ_WRITE);
    if (nfo_hnd > 0)
    {
        FS_Read(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
        g_curr_book_cntx_p->g_nfo_book_struct.settings.font_size = g_setting_list->common_settings.font_size;
        g_curr_book_cntx_p->g_nfo_book_struct.settings.font_style = g_setting_list->common_settings.font_style;
        g_curr_book_cntx_p->g_nfo_book_struct.settings.screen_mode = g_setting_list->common_settings.screen_mode;
        g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format =
            g_setting_list->common_settings.encoding_format;
        g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag =
            g_setting_list->common_settings.auto_scroll_settings.scroll_flag;
        g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_speed =
            g_setting_list->common_settings.auto_scroll_settings.scroll_speed;
        g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_type =
            g_setting_list->common_settings.auto_scroll_settings.scroll_type;
        if (g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format != g_setting_list->common_settings.encoding_format)
        {
            g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format =
                g_setting_list->common_settings.encoding_format;
        FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
        retval = FS_Write(
                    nfo_hnd,
                    &g_curr_book_cntx_p->g_nfo_book_struct,
                    sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
                    &size);
        FS_Close(nfo_hnd);
        }
        else
        {            
            g_curr_book_cntx_p->g_nfo_book_struct.temp_encoding_file_format = '\0';
            for (i = 0; i < EBR_FRM_MAX_NO_OF_BOOKMARKS; i++)
            {
                g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].offset = 0;
                g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].page_id = 0;
                mmi_ucs2cpy((PS8) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name, (PS8) NULL);
                g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].percentage_associated_with_book_mark = 0;
            }
            g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = 0;
            g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
            g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = 0;
            g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = 0;
            /* g_curr_book_cntx_p->g_nfo_book_struct.settings = g_setting_list->common_settings; */
            g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format =
                g_setting_list->common_settings.encoding_format;                
            g_curr_book_cntx_p->g_nfo_book_struct.last_text_offset_y = 0;

            mmi_ucs2cpy((PS8) g_curr_book_cntx_p->nfo_name, (PS8)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
            mmi_ucs2cpy(
                (S8*) g_curr_book_cntx_p->nfo_path,
                (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
            mmi_ucs2cat((PS8) g_curr_book_cntx_p->nfo_path, (PS8)filename);            
            if (mmi_ucs2str((PS8)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name, (PS8)L".txt") != NULL)
            {
                g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_TXT;
            }
            else
            {
                g_curr_book_cntx_p->gbook_type = EBR_FRM_FILE_TYPE_PDB;
            }
            FS_Close(nfo_hnd);
            ebr_frm_recalc_book_size();

            ebr_frm_reset_find_next_data();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_delete_all_from_book_shelf
 * DESCRIPTION
 *  Delete all books from Book Shelf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_delete_all_from_book_shelf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    S8 ebook_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    WCHAR filename[MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH];
    S16 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_NFO));
    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
    {
        do
        {
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                mmi_ucs2cpy(
                    (S8*) ebook_path,
                    (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
                mmi_ucs2cat((S8*) ebook_path, (S8*) filename);
                retval = FS_Delete((const WCHAR*)ebook_path);
            }

        } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                  FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }
    mmi_ucs2cpy(
        (S8*) path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_PDB));
    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
    {

        do
        {
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                mmi_ucs2cpy(
                    (S8*) ebook_path,
                    (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
                mmi_ucs2cat((S8*) ebook_path, (S8*) filename);
                retval = FS_Delete((const WCHAR*)ebook_path);
            }

        } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                  FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }
    mmi_ucs2cpy(
        (S8*) path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_TXT));
    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
    {

        do
        {
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                mmi_ucs2cpy(
                    (S8*) ebook_path,
                    (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
                mmi_ucs2cat((S8*) ebook_path, (S8*) filename);
                retval = FS_Delete((const WCHAR*)ebook_path);
            }

        } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                  FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_restore_default_book_settings
 * DESCRIPTION
 *  Restore default settings for Book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_restore_default_book_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S16 retval;
    U32 size;
    FS_HANDLE nfo_hnd_local;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset pdb convertion flag */
    g_curr_book_cntx_p->pdb_converted_to_text = FALSE;

    nfo_hnd_local = ebr_frm_get_nfo_handle();
    if (nfo_hnd_local <= 0)
    {
        FS_Close(nfo_hnd_local);
        return 0;
    }
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
	if (g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format != g_setting_list->common_settings.encoding_format)
	{
		g_curr_book_cntx_p->g_nfo_book_struct.temp_encoding_file_format = '\0';
		for (i = 0; i < EBR_FRM_MAX_NO_OF_BOOKMARKS; i++)
		{
			g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].offset = 0;
			g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].page_id = 0;
			mmi_ucs2cpy((PS8) g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].bookmark_name, (PS8) NULL);
			g_curr_book_cntx_p->g_nfo_book_struct.book_marks[i].percentage_associated_with_book_mark = 0;
		}
		g_curr_book_cntx_p->g_nfo_book_struct.current_page_id = 0;
		g_curr_book_cntx_p->g_nfo_book_struct.offset = 0;
		g_curr_book_cntx_p->g_nfo_book_struct.jump_offset = 0;
		g_curr_book_cntx_p->g_nfo_book_struct.last_showed_percentage = 0;
		/* g_curr_book_cntx_p->g_nfo_book_struct.settings = g_setting_list->common_settings; */			
		g_curr_book_cntx_p->g_nfo_book_struct.last_text_offset_y = 0;
            ebr_frm_recalc_book_size();
	}
    g_curr_book_cntx_p->g_nfo_book_struct.settings = g_setting_list->common_settings;
    FS_Seek(nfo_hnd_local, 0, FS_FILE_BEGIN);
    retval = FS_Write(
                nfo_hnd_local,
                &g_curr_book_cntx_p->g_nfo_book_struct,
                sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
                &size);
    FS_Close(nfo_hnd_local);
    return !retval;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_memory_type_selected
 * DESCRIPTION
 *  Get memory type selected
 * PARAMETERS
 *  void
 * RETURNS
 *  ebr_memory_type_enum
 *****************************************************************************/
ebr_memory_type_enum ebr_frm_get_memory_type_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;
    S16 error;
	MMI_BOOL status;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
	g_curr_book_cntx_p->memory_type_selected = g_setting_list->memory_type;    
	status = mmi_fmgr_is_drive_letter_valid(g_curr_book_cntx_p->memory_type_selected);
	if (status && FS_GetDevStatus(g_curr_book_cntx_p->memory_type_selected, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
	{
			return g_curr_book_cntx_p->memory_type_selected;
	}
	else
	{		
		g_setting_list->memory_type = MMI_PUBLIC_DRV;
        WriteRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
    }        
    g_curr_book_cntx_p->memory_type_selected = g_setting_list->memory_type;    
    return g_curr_book_cntx_p->memory_type_selected;
    
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_get_nfo_handle
 * DESCRIPTION
 *  Get nfo handle for File manager
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE ebr_frm_fmgr_get_nfo_handle(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH] = {0};
    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) nfo_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) nfo_path, (S8*) file_name);
    nfo_hnd = FS_Open((const WCHAR*)nfo_path, FS_READ_WRITE);
    return nfo_hnd;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_write_default_value_for_nfo_id_in_nvram
 * DESCRIPTION
 *  Write default value for NFO in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_write_default_value_for_nfo_id_in_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 local_nfo_id = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&local_nfo_id, DS_SHORT, &error);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_file_name_call_back
 * DESCRIPTION
 *  Get the file name
 * PARAMETERS
 *  fmgr_file_name      [IN]        
 *  file_name           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_get_file_name_call_back(S8 *fmgr_file_name, S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    ebr_frm_book_struct nfo_struct;
    U32 size;
    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->memory_type_selected = ebr_get_drive_type();
    mmi_ucs2cpy(
        (S8*) nfo_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));

    mmi_ucs2cat((S8*) nfo_path, fmgr_file_name);
    nfo_hnd = FS_Open((const WCHAR*)nfo_path, FS_READ_ONLY);
    if (nfo_hnd > 0)
    {
        FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
        FS_Read(nfo_hnd, &nfo_struct, sizeof(ebr_frm_book_struct), &size);
    }

    FS_Close(nfo_hnd);
    mmi_ucs2cpy((S8*) file_name, (S8*) nfo_struct.e_book_name);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_display_name_call_back
 * DESCRIPTION
 *  Get the display file name
 * PARAMETERS
 *  fmgr_file_name      [IN]        
 *  book_type           [IN]        
 *  file_name           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_get_display_name_call_back(S8 *fmgr_file_name, ebr_frm_filetype_enum book_type, S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    FS_HANDLE file_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->memory_type_selected = ebr_get_drive_type();
    mmi_ucs2cpy(
        (S8*) nfo_path,
        (S8*) ebr_frm_get_file_path(g_curr_book_cntx_p->memory_type_selected, EBR_FRM_SEARCH_DEFAULT));

    mmi_ucs2cat((S8*) nfo_path, fmgr_file_name);
    file_hnd = FS_Open((const WCHAR*)nfo_path, FS_READ_ONLY);

    if (book_type == EBR_FRM_FILE_TYPE_PDB)
    {
        mmi_ucs2ncpy((S8*) file_name, (S8*) fmgr_file_name, mmi_ucs2strlen((const S8*)fmgr_file_name) - 4);
    }
    else
    {
        mmi_ucs2ncpy((S8*) file_name, (S8*) fmgr_file_name, mmi_ucs2strlen((const S8*)fmgr_file_name) - 4);
    }

    FS_Close(file_hnd);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_file_size_and_name
 * DESCRIPTION
 *  Get the file name and size
 * PARAMETERS
 *  fmgr_file_name      [IN]        
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
S8 *ebr_fmgr_get_file_size_and_name(S8 *fmgr_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd;
    ebr_frm_book_struct book_struct;
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfo_hnd = ebr_frm_fmgr_get_nfo_handle(fmgr_file_name);
    FS_Read(nfo_hnd, &book_struct, sizeof(ebr_frm_book_struct), &size);
    FS_Close(nfo_hnd);
    return (S8*) book_struct.e_book_name;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_file_size
 * DESCRIPTION
 *  Get the file size
 * PARAMETERS
 *  fmgr_file_name      [IN]        
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
U32 ebr_fmgr_get_file_size(S8 *fmgr_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U8 file_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    U32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) file_path,
        (S8*) (ebr_frm_get_file_path(ebr_frm_get_memory_type_selected(), EBR_FRM_SEARCH_DEFAULT)));
    mmi_ucs2cat((S8*) file_path, (const S8*)fmgr_file_name);
    file_hnd = FS_Open((const WCHAR*)file_path, FS_READ_ONLY);
    FS_GetFileSize(file_hnd, &size);
    FS_Close(file_hnd);
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_pre_entry_open_book
 * DESCRIPTION
 *  Pre entry function for Open book
 * PARAMETERS
 *  file_name       [IN]        
 *  file_path       [IN]        
 *  file_ext        [IN]        
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
S32 ebr_frm_fmgr_pre_entry_open_book(S8 *file_name, S8 *file_path, S8 *file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_extension_name[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    S8 file_extension_name_ansii[FMGR_MAX_FILE_LEN * ENCODING_LENGTH];
    S32 nfo_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat((S8*) file_path, (S8*) file_name);
    mmi_ucs2cpy((S8*) file_extension_name, (S8*) file_ext);
    ebr_frm_convert_to_upper((S16*) file_extension_name);
    mmi_ucs2_to_asc((S8*) file_extension_name_ansii, (S8*) file_extension_name);

    if (mmi_fmgr_is_drive_letter_valid(g_curr_book_cntx_p->memory_type_selected))
    {
        if (!strcmp(file_extension_name_ansii, EBR_FILE_TYPE_TXT))
        {
            g_curr_book_cntx_p->g_fmgr_book_type = EBR_FRM_FILE_TYPE_TXT;
            nfo_id = ebr_fmgr_get_nfo_id_for_txt_file(g_curr_book_cntx_p->memory_type_selected, file_name);
            return nfo_id;
        }
        else
        {
            g_curr_book_cntx_p->g_fmgr_book_type = EBR_FRM_FILE_TYPE_PDB;
            nfo_id = ebr_fmgr_get_nfo_id_for_pdb_file(g_curr_book_cntx_p->memory_type_selected, file_name);
            return nfo_id;
        }
    }
    else
    {
        if (!strcmp(file_extension_name_ansii, EBR_FILE_TYPE_TXT))
        {
            g_curr_book_cntx_p->g_fmgr_book_type = EBR_FRM_FILE_TYPE_TXT;
        }
        else
        {
            g_curr_book_cntx_p->g_fmgr_book_type = EBR_FRM_FILE_TYPE_PDB;
        }
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_is_ebook_folder_created
 * DESCRIPTION
 *  Is Ebook Folder created
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_check_is_ebook_folder_created(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_str[MAX_DWNL_EBK_PATH_LEN];
    S8 ebook_folder_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(tmp_str, "%c%s", MMI_CARD_DRV, EBR_DOWNLOADED_EBOOK_PATH);
    mmi_asc_to_ucs2((S8*) ebook_folder_path, (S8*) tmp_str);
    FS_CreateDir((PU16) ebook_folder_path);
    sprintf(tmp_str, "%c%s", MMI_PUBLIC_DRV, EBR_DOWNLOADED_EBOOK_PATH);
    mmi_asc_to_ucs2((S8*) ebook_folder_path, (S8*) tmp_str);
    FS_CreateDir((PU16) ebook_folder_path);

}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->state_recursive_conversion = EBR_FRM_NO_CONVERSION;
    ebr_frm_check_is_ebook_folder_created();
    ebr_frm_get_memory_type_selected();

}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_drive_type
 * DESCRIPTION
 *  Get drive type
 * PARAMETERS
 *  void
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
ebr_memory_type_enum ebr_frm_get_drive_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
    return g_setting_list->memory_type;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_change_drive_type
 * DESCRIPTION
 *  Change the drive type and write in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
S16 ebr_frm_change_drive_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    ebr_frm_setting_struct g_setting;
    ebr_frm_setting_struct *g_setting_list = &g_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_setting_list->memory_type = (U8) g_curr_book_cntx_p->memory_type_selected;
    WriteRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)(g_setting_list), NVRAM_EF_EBOOK_SETTING_SIZE, &error);
    return error;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_drive_status
 * DESCRIPTION
 *  Get drive status
 * PARAMETERS
 *  void
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
int ebr_frm_get_drive_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int drive, status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    status = FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM);
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  gui_paging_reset_auto_scroll
 * DESCRIPTION
 *  Reset auto scroll, called by mulitiline category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_paging_reset_auto_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(EBR_SEARCH_BLOCK_TIMER, 10, ebr_frm_timer_launch_popup);
    ebr_frm_reset_auto_scroll();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_reset_auto_scroll
 * DESCRIPTION
 *  Reset auto scroll, called by string searched
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_reset_auto_scroll(void)/*[MAUI_00230894]*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd;
    U32 size;
    int retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfo_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->nfo_path, FS_READ_WRITE);
    g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag = 0;
    FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
    retval = FS_Write(nfo_hnd, &g_curr_book_cntx_p->g_nfo_book_struct, sizeof(g_curr_book_cntx_p->g_nfo_book_struct), &size);
    retval = FS_Close(nfo_hnd);
    TurnOffBacklight();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_timer_launch_popup
 * DESCRIPTION
 *  timer callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_timer_launch_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EBR_SEARCH_BLOCK_TIMER);
    if(GetExitScrnID() == EBOOK_OPEN_SCREENID)
        ebr_app_display_pop_up_changed_auto_scroll(0);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_auto_scroll_status
 * DESCRIPTION
 *  Get auto scroll status
 * PARAMETERS
 *  void
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
pBOOL ebr_frm_get_auto_scroll_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->g_nfo_book_struct.settings.auto_scroll_settings.scroll_flag == 1)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_highlight_id_from_nvram
 * DESCRIPTION
 *  Get auto scroll status
 * PARAMETERS
 *  void
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
S16 get_highlight_id_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 highlight_id = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_EBOOK_LAST_HIGHLIGHT_ID, (void*)&highlight_id, DS_SHORT, &error);
    return highlight_id;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_current_highlight_id
 * DESCRIPTION
 *  Get highlight id
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_current_highlight_id(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->current_highlight_book_id = index;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_book_size_from_nfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 ebr_frm_get_book_size_from_nfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_curr_book_cntx_p->g_nfo_book_struct.book_size;
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_book_temp_size_from_nfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 ebr_frm_get_book_temp_size_from_nfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        return g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size;
    }
    else
    {
        return g_curr_book_cntx_p->g_nfo_book_struct.book_size;
    }
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_page_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 ebr_frm_get_page_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        return EBR_PAGE_SIZE * 2;
    }
    else
    {
        return EBR_PAGE_SIZE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_get_nfo_id
 * DESCRIPTION
 *  Get nfo id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_frm_fmgr_get_nfo_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_curr_book_cntx_p->nfo_id;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_set_nfo_id
 * DESCRIPTION
 *  Set nfo id
 * PARAMETERS
 *  local_nfo_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_fmgr_set_nfo_id(S32 local_nfo_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->nfo_id = local_nfo_id;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_get_book_type
 * DESCRIPTION
 *  Get book type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S16 ebr_fmgr_get_book_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_curr_book_cntx_p->ebr_fmgr_book_type;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_get_application_type
 * DESCRIPTION
 *  Get application type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S16 ebr_frm_fmgr_get_application_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_curr_book_cntx_p->src_application;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_set_application_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_fmgr_set_application_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->src_application = EBR_FRM_SRC_APP_FMGR;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_src_application_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_src_application_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_curr_book_cntx_p->nfo_name, 0, sizeof(g_curr_book_cntx_p->nfo_name));
    g_curr_book_cntx_p->src_application = EBR_FRM_SRC_APP_EBOOK;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_nfo_file_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nfo_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 ebr_frm_check_nfo_file_present(S32 nfo_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_handle;
    U32 size;
    S32 compare_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfo_handle = ebr_frm_get_nfo_handle();

    if (nfo_handle > 0)
    {
        FS_Read(
            nfo_handle,
            &g_curr_book_cntx_p->g_nfo_book_struct,
            sizeof(g_curr_book_cntx_p->g_nfo_book_struct),
            &size);
        FS_Close(nfo_handle);
        compare_type = mmi_ucs2cmp(
                        (const S8*)g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
                        (const S8*)g_curr_book_cntx_p->nfo_name);
        if (compare_type != 0)
        {
            return 0;
        }
        else
        {
            return nfo_id;
        }

    }
    else
    {
        FS_Close(nfo_handle);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_set_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_fmgr_set_file_type(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) g_curr_book_cntx_p->nfo_name, (S8*) file_name);

    ebr_frm_set_file_type();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nfo_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_file_name(S32 nfo_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfo_hnd = ebr_frm_get_nfo_handle();
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->nfo_name, (PS8) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
    FS_Close(nfo_hnd);
    g_curr_book_cntx_p->is_short = (BOOL)g_curr_book_cntx_p->g_nfo_book_struct.is_short;                
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_move_ebook_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_fmgr_move_ebook_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 create_result;
    FS_HANDLE file_handle;
	U8 name[FMGR_MAX_FILE_LEN*ENCODING_LENGTH];
    U8 tmp_path_buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat((S8*) g_curr_book_cntx_p->fmgr_file_path, (S8*) g_curr_book_cntx_p->fmgr_file_name);
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2cat((PS8) g_curr_book_cntx_p->fmgr_file_path, (PS8) g_curr_book_cntx_p->fmgr_file_extension);
#endif 
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->old_file_path, (PS8) g_curr_book_cntx_p->fmgr_file_path);

    /* short file name src file should be renamed to long file name */
    if (g_curr_book_cntx_p->is_short == TRUE)
    {
        PS8 temp, temp1;

        temp = mmi_fmgr_extract_file_name((PS8) g_curr_book_cntx_p->fmgr_file_path);
        temp1 = mmi_fmgr_extract_file_name((PS8) g_curr_book_cntx_p->old_file_path);
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) temp1,
            (MAX_SUBMENU_CHARACTERS - 1) * ENCODING_LENGTH,
            (U8*) temp,
            PhnsetGetDefEncodingType());
        file_handle = FS_Rename((PU16) g_curr_book_cntx_p->fmgr_file_path, (PU16) g_curr_book_cntx_p->old_file_path);
        if (file_handle < 0)
        {
            ebr_display_error_pop_up(file_handle);
            return;
        }
    }
    mmi_fmgr_remove_last_dir((PS8) g_curr_book_cntx_p->fmgr_file_path);
	mmi_ucs2cpy((PS8) name, (PS8) FMGR_DEFAULT_FOLDER_EBOOKS);
	mmi_fmgr_append_file_name((PS8) g_curr_book_cntx_p->fmgr_file_path, (PS8) name);
	ebr_fmgr_is_book_shelf_path(g_curr_book_cntx_p->fmgr_file_path);
	mmi_fmgr_remove_last_dir((PS8) g_curr_book_cntx_p->fmgr_file_path);
        ebr_frm_create_new_file_path();
    file_handle = FS_Open((U16*) g_curr_book_cntx_p->fmgr_file_path, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        create_result = 0;
    }
    else
    {
    #ifdef __MMI_MY_FAVORITE__    
        mmi_fmgr_remove_last_dir((PS8) g_curr_book_cntx_p->fmgr_file_path);
        file_handle = FS_Open((U16*) g_curr_book_cntx_p->fmgr_file_path, FS_OPEN_DIR | FS_READ_ONLY);
        if (file_handle < 0)
        {
            create_result = FS_CreateDir((PU16) g_curr_book_cntx_p->fmgr_file_path);
            if (create_result < 0)
            {
                ebr_display_error_pop_up(create_result);
                return;
            }
        }
        else
        {
            FS_Close(file_handle);
        }
        ebr_frm_create_new_file_path();
        create_result = FS_CreateDir((PU16) g_curr_book_cntx_p->fmgr_file_path);
    #else
        create_result = FS_CreateDir((PU16) g_curr_book_cntx_p->fmgr_file_path);
    #endif        
        if (create_result < 0)
        {
            ebr_display_error_pop_up(create_result);
            return;
        }
        mmi_ucs2cpy((PS8) g_curr_book_cntx_p->gebook_folder_path, (PS8) g_curr_book_cntx_p->fmgr_file_path);
        g_curr_book_cntx_p->g_isEbook_folder_created = TRUE;
    }

    if (mmi_fmgr_append_file_name((PS8) g_curr_book_cntx_p->fmgr_file_path, (PS8) g_curr_book_cntx_p->fmgr_file_name) ==
        TRUE)
    {
        if (g_curr_book_cntx_p->is_short)
        {
            memset(tmp_path_buf, 0, (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            mmi_chset_mixed_text_to_ucs2_str(
                        (U8*) tmp_path_buf,
                        (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
                        (U8*) g_curr_book_cntx_p->fmgr_file_path,
                        g_chset_text_encoding);
            mmi_ucs2cpy((S8*) g_curr_book_cntx_p->fmgr_file_path, (S8*) tmp_path_buf);
            memset(tmp_path_buf, 0, (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            mmi_chset_mixed_text_to_ucs2_str(
                    (U8*) tmp_path_buf,
                    (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
                    (U8*) g_curr_book_cntx_p->nfo_name,
                    g_chset_text_encoding);
            mmi_ucs2cpy((S8*) g_curr_book_cntx_p->nfo_name, (S8*) tmp_path_buf);
            
            g_curr_book_cntx_p->is_short = MMI_FALSE;
        }

        ebr_frm_delete_unused_nfo_file();
        mmi_fmgr_send_copy_req(
                FMGR_ACTION_MOVE,
                (PU8) g_curr_book_cntx_p->old_file_path,
                (PU8) g_curr_book_cntx_p->fmgr_file_path,
                (PsFuncPtr) fmgr_ebook_move_rsp);
        g_curr_book_cntx_p->is_moving_file = MMI_TRUE;
        ebr_file_move_wait_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_ebook_move_rsp
 * DESCRIPTION
 *  Move response handler
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void fmgr_ebook_move_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_fmt_copy_rsp_strcut *msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;
    g_curr_book_cntx_p->is_moving_file = MMI_FALSE;
    if (msgPtr->result >= 0)
    {
        ebr_fmgr_set_file_type((S8*) g_curr_book_cntx_p->fmgr_file_name);
        mmi_fmgr_remove_last_dir((PS8) g_curr_book_cntx_p->old_file_path);
        mmi_fmgr_copy_new_file_path_after_app_move(g_curr_book_cntx_p->old_file_path);
        DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); /* From file manager */
        DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION); /* From APP */
        DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION); /* From Download agent */        
        ebr_app_add_to_book_shelf();
        DeleteScreenIfPresent(SCR_ID_EBOOK_FILE_MOVE_WAITSCREEN); /* Delete moving screen */
    }
    else
    {
        if (!isInCall())
        {
            ebr_display_error_pop_up(msgPtr->result);
        }
	   DeleteScreenIfPresent(SCR_ID_EBOOK_FILE_MOVE_WAITSCREEN); /* Delete moving screen */
    }
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_fmgr_is_moving_file
 * DESCRIPTION
 *  Check if it is moving file now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 ebr_frm_fmgr_is_moving_file(void)
{
    return g_curr_book_cntx_p->is_moving_file;
}
/*****************************************************************************
 * FUNCTION
 *  ebr_app_change_drive_type
 * DESCRIPTION
 *  Change drive type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_change_drive_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = ebr_frm_change_drive_type();
    ebr_app_get_nfo_id_from_fmgr(
        g_curr_book_cntx_p->fmgr_file_name,
        g_curr_book_cntx_p->fmgr_file_path,
        g_curr_book_cntx_p->fmgr_file_extension,
        g_curr_book_cntx_p->is_short);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_entry_open
 * DESCRIPTION
 *  Entry open book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_entry_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_app_get_nfo_id_from_fmgr(
        g_curr_book_cntx_p->fmgr_file_name,
        g_curr_book_cntx_p->fmgr_file_path,
        g_curr_book_cntx_p->fmgr_file_extension,
        g_curr_book_cntx_p->is_short);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_move_to_ebook_folder
 * DESCRIPTION
 *  Move to ebook folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_move_to_ebook_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_app_clear_all_key_handlers();
    ebr_frm_fmgr_move_ebook_file();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_file_validity
 * DESCRIPTION
 *  Move to ebook folder
 * PARAMETERS
 *  file_path       [?]     
 *  file_name       [?]    
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL ebr_frm_check_file_validity(S8 *file_path, S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    U32 size;
    ebr_frm_database_hdr_type file_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT)
    {
        return TRUE;
    }
    mmi_ucs2cat((S8*) file_path, (S8*) file_name);
    file_hnd = FS_Open((const WCHAR*)file_path, FS_READ_ONLY);
    if (file_hnd > 0)
    {
        if (FS_Read(file_hnd, &file_header, EBR_FRM_DATABASE_HEADER_SIZE, &size) == FS_NO_ERROR)
        {
            if (memcmp(file_header.type, DOC_TYPE, strlen((PS8) DOC_TYPE)) == 0)
            {
                FS_Close(file_hnd);
                return TRUE;
            }
            else
            {
                FS_Close(file_hnd);
                return FALSE;
            }
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_file_info_from_fmgr
 * DESCRIPTION
 *  Move to ebook folder
 * PARAMETERS
 *  file_name       [IN]        
 *  file_path       [IN]        
 *  file_ext        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_file_info_from_fmgr(S8 *file_name, S8 *file_path, S8 *file_ext, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->fmgr_file_name, (PS8) file_name);
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->fmgr_file_path, (PS8) file_path);
    mmi_ucs2cpy((PS8) g_curr_book_cntx_p->fmgr_file_extension, (PS8) file_ext);
    g_curr_book_cntx_p->is_short = is_short;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_delete_all_unused_nfo_file
 * DESCRIPTION
 *  Move to ebook folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_delete_all_unused_nfo_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    U8 filename[MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH];
    U32 driveCount = 0;
    S8 driveLatter[FMGR_TOTAL_STORAGE];
    U8 driveNum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(driveLatter, 0, FMGR_TOTAL_STORAGE);
    mmi_fmgr_get_exist_drive_letter(driveLatter, &driveNum);
            
    while (driveLatter[driveCount] != 0)
    {
        memset((char*)path, 0, MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH);
        
        mmi_ucs2cpy((S8*) path, (S8*) ebr_frm_get_file_path(driveLatter[driveCount], EBR_FRM_SEARCH_NFO));
            if ((fh_cur = FS_FindFirst(
                            (const WCHAR*)path,
                            0,
                            0,
                            &file_info,
                            (U16*) filename,
                            MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH)) >= 0)
            {
                do
                {
                    if (!(file_info.Attributes & FS_ATTR_DIR))
                    {
                        ebr_frm_open_nfo_file_and_delete_all_unused_nfo(driveLatter[driveCount], filename);
                    }
                } while ((FS_FindNext(fh_cur, &file_info, (U16*) filename, MAX_EBOOK_NAME_LENGTH * ENCODING_LENGTH) ==
                          FS_NO_ERROR));
                FS_FindClose(fh_cur);
            }
        driveCount++;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_open_nfo_file_and_delete_all_unused_nfo
 * DESCRIPTION
 *  Move to ebook folder
 * PARAMETERS
 *  memory_type     [IN]        
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_open_nfo_file_and_delete_all_unused_nfo(S8 memory_type, U8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 nfo_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    S8 file_path[MAX_DWNL_EBK_PATH_LEN * ENCODING_LENGTH];
    FS_HANDLE nfo_hnd, file_hnd;
    U32 size;
    S32 nfo_id, strlen_file_name;
    ebr_frm_book_struct book_struct;
    ebr_frm_filetype_enum book_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) nfo_path, (S8*) ebr_frm_get_file_path(memory_type, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) nfo_path, (S8*) filename);
    nfo_hnd = FS_Open((const WCHAR*)nfo_path, FS_READ_ONLY);
    FS_Read(nfo_hnd, &book_struct, sizeof(book_struct), &size);
    FS_Close(nfo_hnd);

    strlen_file_name = mmi_ucs2strlen((const S8*)book_struct.e_book_name);

    if (book_struct.e_book_name[strlen_file_name * 2 - 6] == 'p')
    {
        book_type = EBR_FRM_FILE_TYPE_PDB;
    }
    else
    {
        book_type = EBR_FRM_FILE_TYPE_TXT;
    }

    mmi_ucs2cpy((S8*) file_path, (S8*) ebr_frm_get_file_path(memory_type, EBR_FRM_SEARCH_DEFAULT));
    mmi_ucs2cat((S8*) file_path, (S8*) book_struct.e_book_name);
    file_hnd = FS_Open((const WCHAR*)file_path, FS_READ_ONLY);
    if (file_hnd <= 0)
    {
        FS_Delete((const WCHAR*)nfo_path);
    }
    else
    {
        FS_Close(file_hnd);
        if (book_type == EBR_FRM_FILE_TYPE_TXT)
        {
            nfo_id = ebr_fmgr_get_nfo_id_for_txt_file(memory_type, (S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
        }
        else
        {
            nfo_id = ebr_fmgr_get_nfo_id_for_pdb_file(memory_type, (S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name);
        }
        if (nfo_id <= 0)
        {
            FS_Delete((const WCHAR*)nfo_path);
        }
    }
}

#if (defined(__MMI_CHSET_BIG5__) || defined(__MMI_CHSET_GB2312__))
extern const key_index_t *g_chset_encode_to_ucs2_key_LSB_index[NO_OF_TEXT_ENCODING];
extern const kal_uint8 *g_chset_encode_to_ucs2_key_MSB[NO_OF_TEXT_ENCODING];
extern const kal_uint16 *g_chset_encode_to_ucs2_table[NO_OF_TEXT_ENCODING];

extern const kal_uint16 *g_chset_unknown_encode_char;


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_mmi_chset_text_to_ucs2_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_hnd                    [IN]        
 *  dest                        [IN]        
 *  dest_size                   [IN]        
 *  src                         [IN]        
 *  src_size                    [IN]        
 *  encoding                    [IN]        
 *  over_the_record_border      [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 ebr_frm_mmi_chset_text_to_ucs2_str(
        FS_HANDLE file_hnd,
        U8 *dest,
        S16 dest_size,
        U8 *src,
        S16 src_size,
        TextEncodingEnum encoding,
        U32 *over_the_record_border)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const key_index_t *key_LSB_index_table = g_chset_encode_to_ucs2_key_LSB_index[encoding];
    const kal_uint8 *key_MSB_table = g_chset_encode_to_ucs2_key_MSB[encoding];
    const kal_uint16 *ucs2_table = g_chset_encode_to_ucs2_table[encoding];
    U8 key_LSB;
    U8 key_MSB;
    S16 start;
    S16 end;
    S16 pos = 0;
    S16 index;
    S16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *over_the_record_border = 0;
    while (*(src) != 0) /* I do not know how we assume that this is end of data.. Currently we are taking only chinese encodings for
                           the optimized algo so we can take it as 2 bytes */
    {
        if (*(src) <= 0x7f)
        {
            *(dest + pos) = *src;
            pos++;
            *(dest + pos) = 0;
            pos++;
            src += 1;
            count += 1;
        }
        else
        {
            key_LSB = (U8) (*(src));
            count += 1;
            start = key_LSB_index_table[key_LSB].start;
            if (start < 0)
            {
                dest[pos] = (U8) g_chset_unknown_encode_char[encoding];
                dest[pos + 1] = (U8) (g_chset_unknown_encode_char[encoding] >> 8);
                src += 1;
            }
            else
            {
                if (count >= src_size)
                {
                    U32 temp_size;

                    FS_Read(file_hnd, &key_MSB, 1, &temp_size);
                    if (temp_size != 1)
                    {
                        key_MSB = 0;
                    }
                    else
                    {
                        *over_the_record_border = 1;
                    }
                }
                else
                {
                    key_MSB = (U8) (*(src + 1));
                }
                count += 1;
                end = key_LSB_index_table[key_LSB].end;
                if ((index = ebr_frm_mmi_chset_binary_search(key_MSB, key_MSB_table, start, end)) < 0)  /* key MSB not found */
                {
                    dest[pos] = (U8) g_chset_unknown_encode_char[encoding];
                    dest[pos + 1] = (U8) (g_chset_unknown_encode_char[encoding] >> 8);
                }
                else
                {
                    dest[pos] = (U8) ucs2_table[index];
                    dest[pos + 1] = (U8) (ucs2_table[index] >> 8);

                }
                src += 2;
            }
            pos += 2;
        }
        if (pos >= dest_size - 2)
        {
            break;
        }
    }
    dest[pos] = 0;
    dest[pos + 1] = 0;
    return pos + 2;
}

/* dest_size must be >= 4 */


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_mmi_chset_binary_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key                 [IN]        
 *  lookup_table        [IN]        
 *  start               [IN]        
 *  end                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 ebr_frm_mmi_chset_binary_search(const kal_uint8 key, const kal_uint8 *lookup_table, kal_int16 start, kal_int16 end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (start <= end)
    {
        kal_int16 mid = (start + end) / 2;

        if (key > lookup_table[mid])
        {
            start = mid + 1;
        }
        else if (key < lookup_table[mid])
        {
            end = mid - 1;
        }
        else    /* key == target */
        {
            return mid;
        }
    }

    return -1;
}

#endif /* (defined(__MMI_CHSET_BIG5__) || defined(__MMI_CHSET_GB2312__)) */

const kal_uint8 g_ebr_frm_cheset_utf8_bytes_per_char[16] = 
{
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 2, 2, 3, 4  /* we don't support UCS4 */
};
extern kal_int32 mmi_chset_utf8_to_ucs2(kal_uint8 *dest, kal_uint8 *utf8);



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_mmi_chset_utf8_to_ucs2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_hnd                    [IN]        
 *  dest                        [IN]        
 *  dest_size                   [IN]        
 *  src                         [IN]        
 *  src_size                    [IN]        
 *  over_the_record_border      [IN]         
 * RETURNS
 *  
 *****************************************************************************/
S32 ebr_frm_mmi_chset_utf8_to_ucs2_string(
        FS_HANDLE file_hnd,
        U8 *dest,
        S16 dest_size,
        U8 *src,
        S16 src_size,
        U32 *over_the_record_border)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos = 0;
    S32 cnt;
    S32 src_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *over_the_record_border = 0;
    while (*src && pos < dest_size - 2)
    {
        cnt = g_ebr_frm_cheset_utf8_bytes_per_char[(*src) >> 4];
        if (src_count + cnt > src_size)
        {
            S32 i = 0;
            U8 utf8_char[4];
            U8 bytes_in_buffer;
            U32 size;

            *over_the_record_border = (src_count + cnt) - src_size;
            bytes_in_buffer = cnt - *over_the_record_border;
            for (i = 0; i < bytes_in_buffer; i++)
            {
                utf8_char[i] = *src;
                src += 1;
            }
            FS_Read(file_hnd, &utf8_char[bytes_in_buffer], *over_the_record_border, &size);
            if (size != *over_the_record_border)
            {
                break;
            }
            else
            {
                cnt = mmi_chset_utf8_to_ucs2(dest + pos, utf8_char);
            }
        }
        else
        {
            cnt = mmi_chset_utf8_to_ucs2(dest + pos, src);
        }
        if (cnt == 0)   /* abnormal case */
        {
            break;
        }
        else if (cnt == 4)
        {
            src += cnt;
        }
        else    /* normal case */
        {
            src += cnt;
            pos += 2;
        }
        src_count += cnt;
    }
    dest[pos] = 0;
    dest[pos + 1] = 0;
    return pos + 2;
}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_reset_find_next_data
 * DESCRIPTION
 *  Clears flags for find next on shortcut keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_reset_find_next_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->ebr_last_offset_string = -1;
    g_curr_book_cntx_p->search_found_flag = FALSE;
    g_curr_book_cntx_p->search_string_count = 0;
    g_curr_book_cntx_p->find_next_first_flag = 0;
    g_curr_book_cntx_p->last_record_flag = 0;
    g_curr_book_cntx_p->ebr_last_text_offset = 0;
    g_curr_book_cntx_p->ebr_last_page_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_and_set_current_page_values
 * DESCRIPTION
 *  Sets current page values in case of Exit category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_and_set_current_page_values(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 page_id;
    S32 text_offset;
    U8 shared_bytes;
    U8 last_showed_percentage;

    S32 last_text_offset_y;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_paging_multiline_get_current_page(
        &page_id,
        &text_offset,
        &shared_bytes,
        &last_showed_percentage,
        &last_text_offset_y);
    g_curr_book_cntx_p->ebr_last_text_offset = text_offset;
    g_curr_book_cntx_p->ebr_last_page_id = page_id;
}

#ifdef __MMI_LANG_HINDI__


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_for_full_characters
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL ebr_frm_check_for_full_characters(S16 *pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pattern[mmi_ucs2strlen((const S8*)pattern) - 1] == 2381)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

#endif /* __MMI_LANG_HINDI__ */ 


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_drive_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL ebr_frm_check_drive_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_path_in_ascii[5];
    S8 file_path[10];
    U64 disk_free_space;
    U64 disk_total_space;
    S32 fs_ret;
    FS_DiskInfo disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)file_path_in_ascii, "%c", g_curr_book_cntx_p->memory_type_selected);
    strcat((char*)file_path_in_ascii, ":\\");
    mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);
    fs_ret = FS_GetDiskInfo((PU16) file_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    disk_free_space = 0;
    disk_total_space = 0;
    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (disk_free_space <= g_curr_book_cntx_p->g_nfo_book_struct.book_size)
        {
            return FALSE;
        }
        else
        {
            return TRUE;
        }
    }
    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_nfo_file_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
pBOOL ebr_frm_check_nfo_file_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_path_in_ascii[5];
    S8 file_path[10];
    U64 disk_free_space;
    U64 disk_total_space;
    S32 fs_ret;
    FS_DiskInfo disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf((char*)file_path_in_ascii, "%c", g_curr_book_cntx_p->memory_type_selected);
    strcat((char*)file_path_in_ascii, ":\\");
    mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);
    fs_ret = FS_GetDiskInfo((PU16) file_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    disk_free_space = 0;
    disk_total_space = 0;
    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (disk_free_space <= sizeof(g_curr_book_cntx_p->g_nfo_book_struct))
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  ebr_fmgr_kernel_hide_ext_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_buf_ptr     [?]     
 *  info_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fmgr_kernel_hide_ext_name(S8 *str_buf_ptr, FMGR_FILE_INFO_STRUCT *info_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    S32 ext_str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen((PS8) str_buf_ptr);
    ext_str_len = mmi_ucs2strlen((PS8) info_ptr->file_ext);
    if (ext_str_len > 0)
    {
        ext_str_len += 1;
    }

    if (!(info_ptr->attribute & FS_ATTR_DIR))   /* not folder */
    {
        memset(&str_buf_ptr[(str_len - ext_str_len) * ENCODING_LENGTH], 0, ext_str_len * ENCODING_LENGTH);
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_remove_last_directory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_remove_last_directory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_remove_last_dir((PS8) g_curr_book_cntx_p->book_name_path);
    mmi_fmgr_copy_new_file_path_after_app_move((S8*) g_curr_book_cntx_p->book_name_path);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_is_nfo_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nfo_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_check_is_nfo_file_exist(S16 nfo_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE nfo_hnd;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfo_hnd = FS_Open((const WCHAR*)ebr_frm_get_nfo_file_name((S32) nfo_id), FS_READ_ONLY);
    if (nfo_hnd <= 0)
    {
        nfo_id = 0;
        WriteValue(NVRAM_EBOOK_NFO_LID, (void*)&nfo_id, DS_SHORT, &error);
    }
    FS_Close(nfo_hnd);

}

/*****************************************************************************
 * FUNCTION
 *  ebr_frm_check_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL ebr_frm_check_file_exist(void)
{
	FS_HANDLE file_hnd;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
    {
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_ONLY);
    }
    else
    {
        file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
    }
	if(file_hnd<=0)
		return FALSE;
	else
	{
		FS_Close(file_hnd);
		return TRUE;
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_is_memory_type_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ebr_is_memory_type_changed(S8 memoryType)
{
    if (g_curr_book_cntx_p->memory_type_selected == memoryType)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_is_short_file_name
 * DESCRIPTION
 *  Get if current file use short name to display
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ebr_is_short_file_name(void)
{
    return g_curr_book_cntx_p->is_short;    
}
#ifdef __MMI_BPP_SUPPORT__
static S32 bpp_record_id = 0;


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_bpp_convert_record
 * DESCRIPTION
 *  Convert the record and write in temp file
 * PARAMETERS
 *  file_hnd            [IN]        
 *  new_file_hnd        [IN]        
 *  record_id           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_bpp_convert_record(FS_HANDLE file_hnd, S32 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size = 0;
    S32 total_bytes_converted = 0;
    S32 offset = 0;
    S32 size = 0;
    U32 static over_the_record_border = 0;
    U8* tmp_buffer;
    S8 break_line[] = {0x0A,0x0A,0x0A,0x00};

    //U8 buffer[EBR_RECORD_SIZE_MAX + EBR_MAX_STR_SEARCH_LENGTH];
    //U8 utf8_buffer[EBR_RECORD_SIZE_MAX + EBR_MAX_STR_SEARCH_LENGTH];
    //U8 for_unicode_buffer[EBR_RECORD_SIZE_MAX];
    U8 mmiEncoding = mmi_ebook_util_get_chset(g_curr_book_cntx_p->g_nfo_book_struct.settings.encoding_format);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_id == 1)
    {
        over_the_record_border = 0;
    }
    if (g_curr_book_cntx_p->gbook_type == EBR_FRM_FILE_TYPE_TXT ||
		(g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format))
    {
		if (record_id < g_curr_book_cntx_p->num_records)
		{
			rec_size = EBR_RECORD_SIZE_MAX;
		}
		else
		{
			if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
			{
				rec_size = g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size % EBR_RECORD_SIZE_MAX;
                if (rec_size == 0 && g_curr_book_cntx_p->g_nfo_book_struct.temp_book_size > 0)
                {
                    rec_size = EBR_RECORD_SIZE_MAX;
                }
			}
			else
			{
				rec_size = g_curr_book_cntx_p->g_nfo_book_struct.book_size % EBR_RECORD_SIZE_MAX;
                if (rec_size == 0 && g_curr_book_cntx_p->g_nfo_book_struct.book_size > 0)
                {
                    rec_size = EBR_RECORD_SIZE_MAX;
                }
			}
		}        
        if (rec_size > EBR_RECORD_SIZE_MAX)
        {
            rec_size = EBR_RECORD_SIZE_MAX;
            over_the_record_border = 0;
        }
        memset(g_curr_book_cntx_p->buffer, 0, sizeof(g_curr_book_cntx_p->buffer));
        FS_Read(file_hnd, g_curr_book_cntx_p->buffer, rec_size, (U32*) & size);
        memset(g_curr_book_cntx_p->start, 0, sizeof(g_curr_book_cntx_p->start));
        mmi_chset_use_space_for_unknown_character();

        tmp_buffer = (U8*)mmi_frm_scrmem_alloc(EBR_RECORD_SIZE_MAX * 2 + 10);
        memset(tmp_buffer, 0, sizeof(tmp_buffer));
        
		if (g_curr_book_cntx_p->is_book_in_unicode || g_curr_book_cntx_p->book_is_in_other_encoding_format)
		{
			total_bytes_converted = mmi_chset_convert(
                                    MMI_CHSET_UCS2,
                                    MMI_CHSET_UTF8,
                                    (S8*) g_curr_book_cntx_p->buffer,
                                    (S8*) g_curr_book_cntx_p->start,
                                    EBR_RECORD_SIZE_MAX * 2 + 10);         
		}
		else
		{
			total_bytes_converted = mmi_chset_convert(
                                    (mmi_chset_enum) mmiEncoding,
                                    MMI_CHSET_UCS2,
                                    (S8*) g_curr_book_cntx_p->buffer,
                                    (S8*) tmp_buffer,
                                    EBR_RECORD_SIZE_MAX * 2 + 10);
			total_bytes_converted = mmi_chset_convert(
                                    MMI_CHSET_UCS2,
                                    MMI_CHSET_UTF8,
                                    (S8*) tmp_buffer,
                                    (S8*) g_curr_book_cntx_p->start,
                                    EBR_RECORD_SIZE_MAX * 2 + 10);         
		}
        
                                                                       

        mmi_frm_scrmem_free((void*)tmp_buffer);

        mmi_chset_do_not_use_space_for_unknown_character();


    }
    else
    {
        memset(g_curr_book_cntx_p->start, 0, sizeof(g_curr_book_cntx_p->start));
        g_curr_book_cntx_p->pdb_converted_to_text = TRUE;
        SEEK_REC_ENTRY(file_hnd, record_id);
        if (FS_Read(file_hnd, &offset, 4, (U32*) & size) == FS_NO_ERROR)
        {
            offset = ntohl(offset);
        }
        rec_size = ebr_frm_get_record_size_pdb(file_hnd, offset, record_id);
        if (rec_size < 0 || (rec_size > EBR_RECORD_SIZE_MAX))
        {
            /* Todo: Error handling */
            return;
        }
        if (FS_Seek(file_hnd, offset, FS_FILE_BEGIN) != FS_INVALID_FILE_POS)
        {
            FS_Read(file_hnd, g_curr_book_cntx_p->for_unicode_buffer, rec_size, (U32*) & size);
        }
        else
        {
            /* Todo: Error handling */
            return;
        }
        if (size <= 0)
        {
            /* Todo: Error handling */
            return;
        }
        ebr_frm_start_decompression(g_curr_book_cntx_p->buffer, g_curr_book_cntx_p->for_unicode_buffer, (U32*) & size);
        mmi_chset_use_space_for_unknown_character();
		
		tmp_buffer = (U8*)mmi_frm_scrmem_alloc(EBR_RECORD_SIZE_MAX * 2 + 10);
        memset(tmp_buffer, 0, sizeof(tmp_buffer));        

		total_bytes_converted = mmi_chset_convert(
                                    (mmi_chset_enum) mmiEncoding,
                                    MMI_CHSET_UCS2,
                                    (S8*) g_curr_book_cntx_p->buffer,
                                    (S8*) tmp_buffer,
                                    EBR_RECORD_SIZE_MAX * 2 + 10);

        total_bytes_converted = mmi_chset_convert(
                                    (mmi_chset_enum) MMI_CHSET_UCS2,
                                    MMI_CHSET_UTF8,
                                    (char*)tmp_buffer,
                                    (char*)g_curr_book_cntx_p->start,
                                    EBR_RECORD_SIZE_MAX * 2 + 10);
        mmi_chset_do_not_use_space_for_unknown_character();
		mmi_frm_scrmem_free((void*)tmp_buffer);

    }

    if (record_id == g_curr_book_cntx_p->num_records) 
    {
    	size = strlen((S8*)g_curr_book_cntx_p->start);
		strcat((S8*)g_curr_book_cntx_p->start, break_line);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_bpp_convert_record_record_recursively
 * DESCRIPTION
 *  Convert record recursively
 * PARAMETERS
 *  file_path       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 ebr_frm_bpp_convert_record_record_recursively(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EBOOK_RECURSIVE_TIMER);
    if (bpp_record_id <= g_curr_book_cntx_p->num_records)
    {
        FS_HANDLE file_hnd;

		if (g_curr_book_cntx_p->book_is_in_other_encoding_format)
		{
			file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->temp_book_name_path, FS_READ_ONLY);
		}
		else
		{
			file_hnd = FS_Open((const WCHAR*)g_curr_book_cntx_p->book_name_path, FS_READ_ONLY);
		}        
        
            if (file_hnd > 0)
            {
                FS_Seek(file_hnd, g_curr_book_cntx_p->g_file_hnd_offset, FS_FILE_BEGIN);
            }
            
        if (file_hnd > 0)
        {
            ebr_frm_bpp_convert_record(file_hnd, bpp_record_id);
			g_curr_book_cntx_p->g_file_hnd_offset = FS_Seek(file_hnd, 0, FS_FILE_CURRENT);
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
        #endif /* 0 */ 
            /* g_curr_book_cntx_p->g_file_hnd_offset = FS_Seek(file_hnd, 0, FS_FILE_CURRENT); */
        }
        if (file_hnd > 0)
        {
            FS_Close(file_hnd);
        }             
        return MMI_TRUE;
    }
    else
    {
        /* Finish the composer */
        return MMI_FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  ebr_frm_bpp_xhtml_table_constructer
 * DESCRIPTION
 *  construct bpp xhtml table
 * PARAMETERS
 *  void
 *  new_file_hnd(?)     [IN]        
 *  record_id(?)        [IN]        
 *  file_hnd(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_bpp_xhtml_table_constructer(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;
    mmi_bpp_xhtml_table_css_struct *tab_css;
    mmi_bpp_xhtml_style_class_struct *cell_css;
    mmi_bpp_xhtml_data_element_struct *data;
    U8 ebook_caption[(MAX_EBOOK_NAME_LENGTH + 1) * ENCODING_LENGTH];
    U8 err_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
	{    	
		return;
	}
	
	bpp_record_id = 1;
	g_curr_book_cntx_p->g_file_hnd_offset = 0;
    /* config table css */
    tab_css = (mmi_bpp_xhtml_table_css_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_table_css_struct));

    /* the attributes should be set as 0 if not used */
    memset(tab_css, 0, sizeof(mmi_bpp_xhtml_table_css_struct));
    /* set css */
    tab_css->caption_side = MMI_BPP_XHTML_ALIGN_TOP;
    tab_css->text_align = MMI_BPP_XHTML_ALIGN_CENTER;
    tab_css->text_color = MMI_BPP_XHTML_COLOR_BLACK;
	tab_css->caption_margin = 3;
    tab_css->table_width = 87;

    rsp = app_config_table_css(tab_css);
    free_ctrl_buffer(tab_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* config cell css */
    cell_css = (mmi_bpp_xhtml_style_class_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_style_class_struct));
    /* the attributes should be set as 0 if not used */
    memset(cell_css, 0, sizeof(mmi_bpp_xhtml_style_class_struct));

    /* prepare style class name name[] */
    sprintf((S8*)cell_css->class_name, "ebook-css");

    /* set css */
    cell_css->txt_v_align = MMI_BPP_XHTML_ALIGN_TOP;
    cell_css->txt_h_align = MMI_BPP_XHTML_ALIGN_LEFT;
    cell_css->text_color = MMI_BPP_XHTML_COLOR_BLACK;
    cell_css->width = 87;

    rsp = app_config_style_class(cell_css);
    free_ctrl_buffer(cell_css);
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* inline e-book data from file */
    rsp = app_compose_xhtml_file_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* prepare caption[] */
    mmi_chset_convert(
        (mmi_chset_enum) MMI_CHSET_UCS2,
        MMI_CHSET_UTF8,
		(S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name,
        (S8*) ebook_caption,        
        mmi_ucs2strlen((S8*) g_curr_book_cntx_p->g_nfo_book_struct.e_book_name) * 2);

    rsp = app_compose_xhtml_table_element_start(ebook_caption, strlen((S8*)ebook_caption));  /* utf-8(ascii) encoded */
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    rsp = app_compose_xhtml_row_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    rsp = app_compose_xhtml_data_element_start();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }

    /* compose data element structure */
    data = (mmi_bpp_xhtml_data_element_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));
    /* the attributes should be set as 0 if not used */
    memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));

    /* set task_css attributes */
    sprintf((S8*)data->class_name, "ebook-css");
    data->name_len = strlen((S8*) data->class_name);

    /* prepare the data buffer */
    err_code = ebr_frm_bpp_convert_record_record_recursively();
    if (err_code == MMI_FALSE)
    {
        app_compose_xhtml_file_failed();
        free_ctrl_buffer(data);
        g_curr_book_cntx_p->pdb_converted_to_text = FALSE;
        return;
    }
    data->data_element = g_curr_book_cntx_p->start;
    data->obj_len = strlen((S8*)g_curr_book_cntx_p->start);
    data->app_callback = ebr_frm_bpp_compose_callback;
    data->type = MMI_BPP_XHTML_TYPE_TXT;

    do
    {
        rsp = app_compose_xhtml_data_element_from_buff(data);
        switch (rsp)
        {
            case MMI_BPP_XHTML_RSP_DONE:
                bpp_record_id++;
                break;
            case MMI_BPP_XHTML_RSP_WRITING:
                free_ctrl_buffer(data);
                return;
            default:
                free_ctrl_buffer(data);
                return;
        }
    } while (ebr_frm_bpp_convert_record_record_recursively());

    free_ctrl_buffer(data);

    g_curr_book_cntx_p->pdb_converted_to_text = FALSE;
    rsp = app_compose_xhtml_data_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_row_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_table_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_file_end();
    return;
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
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_bpp_compose_callback
 * DESCRIPTION
 *  callback function of bpp, it will be executed after
 * PARAMETERS
 *  rsp_code            [IN]        
 *  new_file_hnd(?)     [IN]        
 *  record_id(?)        [IN]        
 *  file_hnd(?)         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_bpp_compose_callback(mmi_bpp_xhtml_rsp_enum rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bpp_xhtml_rsp_enum rsp;
    mmi_bpp_xhtml_data_element_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_code != MMI_BPP_XHTML_RSP_DONE)
    {
    	return;
    }
    
    /* Read next record of ebook file */
    bpp_record_id++;

    /* compose data element structure */
    data = (mmi_bpp_xhtml_data_element_struct*) get_ctrl_buffer(sizeof(mmi_bpp_xhtml_data_element_struct));

    /* the attributes should be set as 0 if not used */
    memset(data, 0, sizeof(mmi_bpp_xhtml_data_element_struct));

    /* set task_css attributes */
    /*sprintf((S8*)data->class_name, "ebook-css");
    data->name_len = strlen((S8*) data->class_name);*/

    /* prepare the data buffer */

/* Sophie test start */	
    data->app_callback = ebr_frm_bpp_compose_callback;
    data->type = MMI_BPP_XHTML_TYPE_TXT;


	while (ebr_frm_bpp_convert_record_record_recursively())
    {
		data->data_element = g_curr_book_cntx_p->start;
		data->obj_len = strlen((S8*)g_curr_book_cntx_p->start);
        rsp = app_compose_xhtml_data_element_from_buff(data);        
        switch (rsp)
        {
            case MMI_BPP_XHTML_RSP_DONE:
                bpp_record_id++;
                break;
            case MMI_BPP_XHTML_RSP_WRITING:
                free_ctrl_buffer(data);
                return;
            default:
                free_ctrl_buffer(data);
                return;
        }
    } 
/* Sophie test end */
/*
    ebr_frm_bpp_convert_record_record_recursively(file_path);
    data->data_element = g_curr_book_cntx_p->start;
    data->obj_len = strlen((S8*)g_curr_book_cntx_p->start);
    data->app_callback = ebr_frm_bpp_compose_callback;
    data->type = MMI_BPP_XHTML_TYPE_TXT;

    do
    {
        rsp = app_compose_xhtml_data_element_from_buff(data);        
        switch (rsp)
        {
            case MMI_BPP_XHTML_RSP_DONE:
                bpp_record_id++;
                break;
            case MMI_BPP_XHTML_RSP_WRITING:
                free_ctrl_buffer(data);
                return;
            default:
                free_ctrl_buffer(data);
                return;
        }
    } while (ebr_frm_bpp_convert_record_record_recursively(file_path));
*/
    free_ctrl_buffer(data);

    g_curr_book_cntx_p->pdb_converted_to_text = FALSE;
    rsp = app_compose_xhtml_data_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_row_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_table_element_end();
    if (rsp != MMI_BPP_XHTML_RSP_DONE)
    {
        return;
    }
    rsp = app_compose_xhtml_file_end();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_bpp_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_bpp_reset_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_BPP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_page_info
 * DESCRIPTION
 *  to save current page information to global variables 
 * PARAMETERS
 *  page_id       [IN]
 *  text_offset       [IN]
 *  shared_bytes       [IN]
 *  last_showed_percentage       [IN]
 *  last_text_offset_y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_page_info(U32 page_id, S32 text_offset, U8 shared_bytes, U8 last_showed_percentage, S32 last_text_offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_book_cntx_p->page_info_struct.page_id = page_id;
    g_curr_book_cntx_p->page_info_struct.text_offset = text_offset;
    g_curr_book_cntx_p->page_info_struct.shared_bytes = shared_bytes;
    g_curr_book_cntx_p->page_info_struct.last_showed_percentage = last_showed_percentage;
    g_curr_book_cntx_p->page_info_struct.last_text_offset_y = last_text_offset_y;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_get_page_info
 * DESCRIPTION
 *  to get current page information from global variables 
 * PARAMETERS
 *  page_id       [OUT]
 *  text_offset       [OUT]
 *  shared_bytes       [OUT]
 *  last_showed_percentage       [OUT]
 *  last_text_offset_y       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_get_page_info(PU32 page_id, PS32 text_offset, PU8 shared_bytes, PU8 last_showed_percentage, PS32 last_text_offset_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *page_id = g_curr_book_cntx_p->page_info_struct.page_id;
    *text_offset = g_curr_book_cntx_p->page_info_struct.text_offset;
    *shared_bytes = g_curr_book_cntx_p->page_info_struct.shared_bytes;
    *last_showed_percentage = g_curr_book_cntx_p->page_info_struct.last_showed_percentage;
    *last_text_offset_y = g_curr_book_cntx_p->page_info_struct.last_text_offset_y;
}

#endif /* __MMI_EBOOK_READER__ */ 
