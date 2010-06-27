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
 * str_merge.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Merge multi-language string table, and generate string resource files.
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <tchar.h>

#include "PixtelDataTypes.h"
#include "MMI_features.h"
#include "FontRes.h"
#include "CustDataRes.h"
#include "CustResDef.h"

/* #define __TIME_CONSUME for calculating execution time */
#ifdef __TIME_CONSUME
#include <time.h>
#endif

/* max string length for each language */
#define MAX_LENGTH      512
/* string length for temp buffer */
#define TMP_BUF_LENGTH  1024

#define ref_file        "..\\custresource\\ref_list.txt"
#ifndef __OPTR_NONE__
/* max SSC length */
#define SSC_LENGTH      16
/* ref_list.txt customized for operator */
#define optr_ref_file   "operator_ref_list.txt"
#endif

/* this marker indicates using English as string translation */
#define NO_TRANSLATION_MARKER   19

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define ENFB_STRING_DATA_FILENAME  "..\\..\\Customer\\CustResource\\CustENFBStrData"
#define ENFB_STRING_HEADER_FILENAME  "..\\..\\Customer\\CustResource\\CustENFBStr.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

typedef struct StrRes
{
    wchar_t **Str;      /* pointer array of lists to store Strings */
    int *StrRef;        /* pointers of Reference id in hash table of each string */
    int MaxID;          /* Maximum number of string ids */
    int MaxNum;         /* Maximum number of strings */
    int TotalLength;
} StrRes;

typedef struct StrResSet
{
    struct StrRes *strres;
    int iLang;
} StrResSet;

typedef struct HashItem
{
    int pointer;        /* index in string array */
    struct HashItem *next;
} HashItem;

extern U8 StrIsPopulate[MAX_STRING_MAP_SIZE];
extern U8 *StrEnum[MAX_STRING_MAP_SIZE];
extern U8 *Str[MAX_STRING_MAP_SIZE];
extern U16 CurrMaxStringId;

/* get fontres data */
extern const U16 mtk_gMaxDeployedLangs;
extern const sLanguageDetails mtk_gLanguageArray[];

static const wchar_t *DELIMETER = L"\t";
static const wchar_t *EOS = L"\n";

static int *mtk_gLanguageFlag;

static U16 StrLine[MAX_STRING_MAP_SIZE];
static U16 *StrID = NULL;
static U32 g_line_buf_length = 0;
static wchar_t *ref_all = NULL;
static wchar_t *ref_ssc = NULL;
static wchar_t *ref_tmp = NULL;
static int nLang = 0;


/*****************************************************************************
 * FUNCTION
 *  UCS2ASCII
 * DESCRIPTION
 *  Convert wide character to ASCII character
 * PARAMETERS
 *  w_in    [IN]
 *  a_out   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void UCS2ASCII(char *w_in, char *a_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (w_in[i * 2] != '\0' || w_in[i * 2 + 1] != '\0')
    {
        a_out[i] = w_in[i * 2];
        i += 1;
    }
    a_out[i] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  GetItem
 * DESCRIPTION
 *  Get token between index and index+1 DELIMETER
 * PARAMETERS
 *  string  [IN]
 *  index   [IN]
 *  buf     [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void GetItem(wchar_t *string, int index, wchar_t *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wchar_t *p1 = string;
    wchar_t *p2 = wcsstr(string, DELIMETER);
    int n = p2 - p1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (index > 0)
    {
        p1 = p2 + 1;
        p2 = wcsstr(p1, DELIMETER);
        n = p2 - p1;
        index--;
        if (p2 == NULL)
            break;
    }

    if (index > 0)
    {
        buf[0] = L'\0';
    }
    else if (p2 == NULL)
    {
        wcscpy(buf, p1);
        n = wcsstr(p1, EOS) - p1;
        buf[n] = L'\0';
        buf[n - 1] = L'\0';
    }
    else
    {
        wcsncpy(buf, p1, n);
        buf[n] = L'\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  OutputFixColumns
 * DESCRIPTION
 *  Output content of fix columns to temp buffer
 * PARAMETERS
 *  linebuf     [IN]
 *  token_id    [IN OUT]
 *  itembuf     [IN]
 *  log_output  [OUT]
 *  ref_output  [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void OutputFixColumns(wchar_t *linebuf, int *token_id, wchar_t *itembuf, 
                             wchar_t *log_output, wchar_t *ref_output)
{
    GetItem(linebuf, (*token_id)++, itembuf);
    wcscat(log_output, L"\t");
    wcscat(log_output, itembuf);            /* print out Module Name */

    GetItem(linebuf, (*token_id)++, itembuf);
    wcscat(log_output, L"\t");
    wcscat(log_output, itembuf);            /* print out Max String Length */

    /* will copy back to reference string table */
    wcscpy(ref_output, log_output);

    GetItem(linebuf, (*token_id)++, itembuf);
    wcscat(log_output, L"\t");
    wcscat(log_output, L"No Translation");  /* print out description */

    /* will copy back to reference string table */
    wcscat(ref_output, L"\t");
    wcscat(ref_output, itembuf);
}

/*****************************************************************************
 * FUNCTION
 *  MergeStrRes
 * DESCRIPTION
 *  Find string ID in ref_list.txt, generate string content table
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 0 on success, otherwise, return -1
 *****************************************************************************/
int MergeStrRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *ref = NULL;
    FILE *fail = NULL;
    wchar_t *tmp_line;
    wchar_t *end_line;
    wchar_t buf_src[TMP_BUF_LENGTH];
    wchar_t buf_ref[TMP_BUF_LENGTH];
    wchar_t tmp_buf[TMP_BUF_LENGTH];
    int token_id = 0, gIndex = 0;
    char buf_asc[512];
    int found = 0, i = 0, StrNotTranslated = 1, missLanguage = 0;

    U16 nStrId;
    wchar_t marker[2] = {NO_TRANSLATION_MARKER, 0};

    /* operator support */
#ifndef __OPTR_NONE__
    FILE *optr_ref = NULL;
    char *optr_path;
    int optr_lang;
    U32 optr_line_buf_length;
    U16 *optr_lang_mask = NULL;
    wchar_t (*ref_ssc_list)[SSC_LENGTH] = NULL;
    wchar_t *optr_ref_all = NULL;
    wchar_t *optr_ref_ssc = NULL;
    wchar_t *optr_tmp_line;
    wchar_t *optr_end_line;
    int optr_found;
    int optr_ref_cnt = 0;
    int optr_new_cnt = 0;
    int optr_search_cnt = 0;
    int optr_search_index = 0;
#endif /* __OPTR_NONE__ */

#ifdef __TIME_CONSUME
    time_t start_time, end_time;
#endif
    int ref_cnt = 0;
    int search_cnt = 0;
    int search_index = 0;
    int j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ref = fopen(ref_file, "rb");
    if (ref == NULL)
    {
        printf("Invalid reference filename\n");
        return -1;
    }
    /* operator support */
#ifndef __OPTR_NONE__
    optr_path = (char *)tmp_buf;
    strcpy(tmp_buf, CUST_OPERATOR_STR_PATH);
    strcat(tmp_buf, "\\");
    strcat(tmp_buf, optr_ref_file);

    optr_ref = fopen(optr_path, "rb");
    if (optr_ref == NULL)
    {
        printf("Invalid operator reference filename\n");
        goto ERR_RET;
    }
#endif /* __OPTR_NONE__ */
    fail = fopen("NoTranslation.txt", "w");
    if (fail == NULL)
    {
        printf("NoTranslation.txt Open Fail!!\n");
        goto ERR_RET;
    }
    fclose(fail);
    fail = fopen("NoTranslation.txt", "a");

#ifdef __TIME_CONSUME
    start_time = time(NULL);
#endif

    fgetws(tmp_buf, TMP_BUF_LENGTH, ref); /* Number of Language */
    GetItem(tmp_buf, 1, buf_ref);
    nLang = _wtoi(buf_ref);

    /* operator support */
#ifndef __OPTR_NONE__
    fgetws(tmp_buf, TMP_BUF_LENGTH, optr_ref);
    GetItem(tmp_buf, 1, buf_ref);
    optr_lang = _wtoi(buf_ref);
#endif /* __OPTR_NONE__ */

    /* 
     * calculate line buffer size 
     * here +2 for Description, and (Max String Length, MODULE, ENUM)
     */
    g_line_buf_length = (nLang + 2) * MAX_LENGTH;
    ref_tmp = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_tmp == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }

    token_id = 0;
    fgetws(ref_tmp, TMP_BUF_LENGTH, ref);   /* Title list */
    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* Enum Value */
    fprintf(fail, "%s", buf_asc);           /* print out to NoTranslation.txt */

    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* MODULE NAME */
    fprintf(fail, "\t%s", buf_asc);         /* print out to NoTranslation.txt */

    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* Max String Length */
    fprintf(fail, "\t%s", buf_asc);         /* print out to NoTranslation.txt */

    GetItem(ref_tmp, token_id++, buf_src);
    UCS2ASCII((char*)buf_src, buf_asc);     /* Description */
    fprintf(fail, "\t%s", buf_asc);         /* print out to NoTranslation.txt */

    for (i = 0; i < nLang; i++)
    {
        GetItem(ref_tmp, token_id + i, buf_ref);
        UCS2ASCII((char*)buf_ref, buf_asc); /* Language */
        fprintf(fail, "\t%s", buf_asc);     /* print out to NoTranslation.txt */
    }
    fprintf(fail, "\n");

    ref_ssc = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t));
    if (ref_ssc == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }
    fgetws(ref_ssc, g_line_buf_length, ref); /* SSC STRING */

    /* operator support */
#ifndef __OPTR_NONE__
    optr_line_buf_length = (optr_lang + 2) * MAX_LENGTH;
    optr_ref_ssc = (wchar_t *)malloc(optr_line_buf_length * sizeof(wchar_t));
    if (optr_ref_ssc == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }

    fgetws(ref_tmp, optr_line_buf_length, optr_ref);
    fgetws(optr_ref_ssc, optr_line_buf_length, optr_ref);

    /* allocate mask for languages in operator_ref_list.txt */
    optr_lang_mask = (U16 *)malloc(nLang * sizeof(U16));
    if (optr_lang_mask == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }
    memset(optr_lang_mask, 0, nLang * sizeof(U16));
    ref_ssc_list = (wchar_t (*)[SSC_LENGTH])malloc(sizeof(wchar_t[SSC_LENGTH]) * nLang);
    if (ref_ssc_list == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }

    /* read each SSC into ref_ssc_list */
    token_id = 0;
    GetItem(ref_ssc, token_id++, buf_ref);
    GetItem(ref_ssc, token_id++, buf_ref);
    GetItem(ref_ssc, token_id++, buf_ref);
    GetItem(ref_ssc, token_id++, buf_ref);
    for (i = 0; i < nLang; i++)
    {
        GetItem(ref_ssc, token_id++, buf_ref);
        wcscpy(ref_ssc_list[i], buf_ref);
    }
    /* 
     * try to match each SSC in operator_ref_list.txt 
     * within ref_ssc_list
     */
    token_id = 0;
    GetItem(optr_ref_ssc, token_id++, buf_ref);
    GetItem(optr_ref_ssc, token_id++, buf_ref);
    GetItem(optr_ref_ssc, token_id++, buf_ref);
    GetItem(optr_ref_ssc, token_id++, buf_ref);
    for (i = 0; i < optr_lang; i++)
    {
        GetItem(optr_ref_ssc, token_id++, buf_ref);
        for (j = 0; j < nLang; j++)
        {
            if (!wcscmp(buf_ref, ref_ssc_list[j]))
            {
                /* 
                 * language column j is found in operator_ref_list.txt, 
                 * and matching to language column i
                 */
                optr_lang_mask[j] = i + 1;
                break;
            }
        }
    }
    free(ref_ssc_list);
    ref_ssc_list = NULL;

    fgetws(ref_tmp, optr_line_buf_length, optr_ref);
    while (!feof(optr_ref))
    {
        optr_ref_cnt++;
        fgetws(ref_tmp, optr_line_buf_length, optr_ref);
    }

    if (optr_ref_cnt != 0)
    {
        optr_ref_all = (wchar_t *)malloc(optr_line_buf_length * sizeof(wchar_t) * optr_ref_cnt);
        if (optr_ref_all == NULL)
        {
            printf("memory is not available\n");
            goto ERR_RET;
        }
        rewind(optr_ref);
        fgetws(ref_tmp, optr_line_buf_length, optr_ref);
        fgetws(ref_tmp, optr_line_buf_length, optr_ref);
        fgetws(ref_tmp, optr_line_buf_length, optr_ref);
        optr_tmp_line = optr_ref_all;
        for (j = 0; j < optr_ref_cnt; j++)
        {
            fgetws(optr_tmp_line, optr_line_buf_length, optr_ref);
            optr_tmp_line += optr_line_buf_length;
        }
        optr_end_line = optr_tmp_line - optr_line_buf_length;
    }
#endif /* __OPTR_NONE__ */

    /* calculate the number of entries and read them to the buffer */
    fgetws(ref_tmp, g_line_buf_length, ref);
    while (!feof(ref))
    {
        ref_cnt++;
        fgetws(ref_tmp, g_line_buf_length, ref);
    }

    /* operator support */
#ifndef __OPTR_NONE__
    ref_all = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t) * (ref_cnt + optr_ref_cnt));
#else
    ref_all = (wchar_t *)malloc(g_line_buf_length * sizeof(wchar_t) * ref_cnt);
#endif
    if (ref_all == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }
    rewind(ref);
    fgetws(ref_tmp, g_line_buf_length, ref);
    fgetws(ref_tmp, g_line_buf_length, ref);
    fgetws(ref_tmp, g_line_buf_length, ref);
    tmp_line = ref_all;
    for (j = 0; j < ref_cnt; j++)
    {
        fgetws(tmp_line, g_line_buf_length, ref);
        tmp_line += g_line_buf_length;
    }
    end_line = tmp_line - g_line_buf_length;

    /* String ID array without empty slot */
    StrID = (U16 *)malloc(sizeof(U16) * CurrMaxStringId);
    if (StrID == NULL)
    {
        printf("memory is not available\n");
        goto ERR_RET;
    }

    nStrId = 0;
    while (nStrId < MAX_STRING_MAP_SIZE)
    {
        if (StrIsPopulate[nStrId] == 0)
        {
            nStrId++;
            continue;
        }
        *(StrID + gIndex) = nStrId;

        /* operator support */
#ifndef __OPTR_NONE__
        optr_found = 0;
        if (optr_ref_cnt != 0)
        {
            optr_tmp_line = optr_ref_all + optr_search_index * optr_line_buf_length;
            while (optr_search_cnt < optr_ref_cnt)
            {
                token_id = 0;
                GetItem(optr_tmp_line, token_id++, buf_ref);
                if (!wcscmp((wchar_t *)StrEnum[nStrId], buf_ref))
                {
                    optr_found = 1;
                    break;
                }
                optr_search_cnt++;
                optr_search_index++;
                if (optr_search_index >= optr_ref_cnt)
                    optr_search_index = 0;
                optr_tmp_line += optr_line_buf_length;
                if (optr_tmp_line > optr_end_line)
                    optr_tmp_line = optr_ref_all;
            }
        }
#endif /* __OPTR_NONE__ */

        found = 0;
        tmp_line = ref_all + search_index * g_line_buf_length;
        while ((search_cnt < ref_cnt) && !found)
        {
            token_id = 0;
            GetItem(tmp_line, token_id++, buf_ref);
            if (!wcscmp((wchar_t *)StrEnum[nStrId], buf_ref))
            {
                found = 1;
                StrLine[nStrId] = search_index + 1;

                wcscpy(tmp_buf, (wchar_t *)StrEnum[nStrId]); /* print out Enum Values */

                /* output content of fix columns */
                OutputFixColumns(tmp_line, &token_id, buf_src, tmp_buf, ref_tmp);

                missLanguage = 0;
                for (i = 0; i < nLang; i++)
                {
                    GetItem(tmp_line, i + token_id, buf_ref);

                    /* operator support */
#ifndef __OPTR_NONE__
                    if (optr_found == 1 && optr_lang_mask[i])
                    {
                        int optr_token_id = 0;

                        /* use string translation in operator_ref_list.txt */
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);

                        for (j = 0; j < optr_lang_mask[i]; j++)
                            GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                    }
#endif /* __OPTR_NONE__ */

                    if (buf_ref[0] == '\0')
                    {
                        /* if there is no corresponding string translation, use English */
                        missLanguage = 1;
                        wcscat(tmp_buf, L"\tV");

                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, marker);
                    }
                    else
                    {
                        wcscat(tmp_buf, L"\t");

                        /* for possible missing language translation */
                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, buf_ref);
                    }
                }
                if (missLanguage == 1)
                {
                    wcscat(tmp_buf, L"\n");
                    UCS2ASCII((char*)tmp_buf, buf_asc);
                    fprintf(fail, "%s", buf_asc);

                    /* replace string content */
                    wcscpy(tmp_line, ref_tmp);
                }
#ifndef __OPTR_NONE__
                else if (optr_found == 1)
                {
                    /* replace string content */
                    wcscpy(tmp_line, ref_tmp);
                }
#endif /* __OPTR_NONE__ */
            }
            if (!found)
            {
                search_cnt++;
            }
            search_index++;
            if (search_index >= ref_cnt)
                search_index = 0;
            tmp_line += g_line_buf_length;
            if (tmp_line > end_line)
                tmp_line = ref_all;
        }
        if (!found)
        {
#ifndef __OPTR_NONE__
            if (optr_found == 1)
            {
                /* for strings only in operator_ref_list.txt */
                int optr_token_id = 0;

                GetItem(optr_tmp_line, optr_token_id++, buf_src);
                wcscpy(tmp_buf, (wchar_t *)buf_src); /* print out Enum Values */

                /* output content of fix columns */
                OutputFixColumns(optr_tmp_line, &optr_token_id, buf_src, tmp_buf, ref_tmp);

                missLanguage = 0;
                for (i = 0; i < nLang; i++)
                {
                    buf_ref[0] = '\0';

                    if (optr_lang_mask[i])
                    {
                        int optr_token_id = 0;

                        /* use string translation in operator_ref_list.txt */
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                        GetItem(optr_tmp_line, optr_token_id++, buf_ref);

                        for (j = 0; j < optr_lang_mask[i]; j++)
                            GetItem(optr_tmp_line, optr_token_id++, buf_ref);
                    }

                    if (buf_ref[0] == '\0')
                    {
                        /* if there is no corresponding string translation, use English */
                        missLanguage = 1;
                        wcscat(tmp_buf, L"\tV");

                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, marker);
                    }
                    else
                    {
                        wcscat(tmp_buf, L"\t");

                        /* will copy back to reference string table */
                        wcscat(ref_tmp, L"\t");
                        wcscat(ref_tmp, buf_ref);
                    }
                }

                if (missLanguage == 1)
                {
                    wcscat(tmp_buf, L"\n");
                    UCS2ASCII((char*)tmp_buf, buf_asc);
                    fprintf(fail, "%s", buf_asc);
                }

                /* copy back to reference string table */
                optr_new_cnt++;
                StrLine[nStrId] = ref_cnt + optr_new_cnt;
                wcscpy((end_line + optr_new_cnt * g_line_buf_length), ref_tmp);
            }
            else
#endif
            {
                /* didn't find any match */
                StrNotTranslated = 0;
                UCS2ASCII((char*)StrEnum[nStrId], buf_asc);
                fprintf(fail, "%s\t\t\tEmpty\n", buf_asc);
            }
        }

        gIndex++;
        nStrId++;
        search_cnt = 0;
        /* operator support */
#ifndef __OPTR_NONE__
        optr_search_cnt = 0;
#endif
    }

#ifdef __TIME_CONSUME
    end_time = time(NULL);
    printf("elapsed time = %d\n", end_time - start_time);
#endif /* __TIME_CONSUME */

    /* operator support */
#ifndef __OPTR_NONE__
    if (optr_lang_mask)
        free(optr_lang_mask);
    if (optr_ref_ssc)
        free(optr_ref_ssc);
    if (optr_ref_all)
        free(optr_ref_all);
    if (optr_ref)
        fclose(optr_ref);
#endif /* __OPTR_NONE__ */

    fclose(ref);
    fclose(fail);
    if (StrNotTranslated == 0)
    {
        printf("Please see NoTranslation.txt to see the result...\n");
    }

    return 0;

ERR_RET:
    if (ref_tmp)
        free(ref_tmp);
    if (ref_ssc)
        free(ref_ssc);
    if (ref_all)
        free(ref_all);
    /* operator support */
#ifndef __OPTR_NONE__
    if (optr_lang_mask)
        free(optr_lang_mask);
    if (ref_ssc_list)
        free(ref_ssc_list);
    if (optr_ref_ssc)
        free(optr_ref_ssc);
    if (optr_ref_all)
        free(optr_ref_all);
    if (optr_ref)
        fclose(optr_ref);
#endif /* __OPTR_NONE__ */

    if (ref)
        fclose(ref);
    if (fail)
        fclose(fail);
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mask_length
 * DESCRIPTION
 *  Get token between index and index+1 DELIMETER
 * PARAMETERS
 *  val     [IN]
 * RETURNS
 *  Return the mask bit count
 *****************************************************************************/
static int mask_length(int val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int l = 0, v;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    v = val / 2;
    while (v >= 1)
    {
        l++;
        v = v / 2;
    }
    return l;
}


/*****************************************************************************
 * FUNCTION
 *  pow
 * DESCRIPTION
 *  Calculate base raised to the power of index
 * PARAMETERS
 *  base    [IN]
 *  index   [IN]
 * RETURNS
 *  Return the value: base raised to the power of index
 *****************************************************************************/
static int pow(int base, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, ret = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < index; i++)
        ret = ret * base;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  fmod
 * DESCRIPTION
 *  Calculate the remainder
 * PARAMETERS
 *  denominator [IN]
 *  numerator   [IN]
 * RETURNS
 *  Return the remainder of denominator / numerator
 *****************************************************************************/
static int fmod(int denominator, int numerator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = denominator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (ret >= numerator)
        ret = ret - numerator;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  GetHashValue
 * DESCRIPTION
 *  Calculate the hash value of input string
 * PARAMETERS
 *  string      [IN]
 *  hash_range  [IN]
 * RETURNS
 *  Return the hash value
 *****************************************************************************/
static int GetHashValue(wchar_t *string, int hash_range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int length = mask_length(hash_range);
    int mask = (int)pow(2, length) - 1;
    int i = 0;
    long val = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (int)wcslen(string); i++)
    {
        val += ((string[i] + val * 37) & mask);
    }
    val = fmod(val, hash_range);
    return (int)val;
}


/*****************************************************************************
 * FUNCTION
 *  Trans
 * DESCRIPTION
 *  Transform UCS2-encoding "\","n" to "\n"
 * PARAMETERS
 *  string  [IN]
 *  buf     [OUT]
 * RETURNS
 *  Return 1 if transformed, otherwise, return 0
 *****************************************************************************/
static int Trans(wchar_t *string, wchar_t *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int l = 0, ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < wcslen(string); i++)
    {
        if (string[i] == L'\\' && string[i + 1] == L'n')
        {
            buf[l] = '\n';
            i++;
            ret = 1;
        }
        else
            buf[l] = string[i];
        l++;
    }
    buf[l] = L'\0';
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  UCS2ASCII_CR
 * DESCRIPTION
 *  Convert wide character to ASCII character, removing charcters after CR
 * PARAMETERS
 *  w_in    [IN]
 *  a_out   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void UCS2ASCII_CR(char *w_in, char *a_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (w_in[i] != '\0' || w_in[i + 1] != '\0')
    {
        a_out[i >> 1] = w_in[i];
        i += 2;
    }
    a_out[i >> 1] = '\0';
    i = i >> 1;
    i--;
    while (i >= 0)
    {
        if (a_out[i] == 0x0D)
        {
            a_out[i] = '\0';
            break;
        }
        else
            i--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ifLanguageUsed
 * DESCRIPTION
 *  Decide if the translated language should be used for string resource, 
 *  according to SSC string
 * PARAMETERS
 *  ssc_ref [IN]
 * RETURNS
 *  Return -1 if the language is not used, otherwise, return non-negative index
 *****************************************************************************/
static int ifLanguageUsed(wchar_t *ssc_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    char ascii_ssc[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UCS2ASCII_CR((char *)ssc_ref, ascii_ssc);
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        if (strcmp(mtk_gLanguageArray[i].aLangSSC, ascii_ssc) == 0)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetStrResList
 * DESCRIPTION
 *  Generate a non-duplicate string list from input file, using hash table
 * PARAMETERS
 *  result  [OUT]
 * RETURNS
 *  Return number of all populated string IDs
 *****************************************************************************/
static int GetStrResList(StrResSet *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct HashItem **ht = NULL, *extra = NULL, *temp = NULL;
    struct StrRes *strres = NULL;
    wchar_t *tok = NULL;
    int i = 0, j = 0, k = 0, h = 0, l = 0;
    int LangIndex = 0;
    int hash_range = 0;

    U16 nStrId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strres = malloc(sizeof(struct StrRes) * mtk_gMaxDeployedLangs);
    ht = malloc(sizeof(struct HashItem *) * mtk_gMaxDeployedLangs);

    mtk_gLanguageFlag = malloc(sizeof(int) * mtk_gMaxDeployedLangs);
    for (h = 0; h < mtk_gMaxDeployedLangs; h++)
    {
        mtk_gLanguageFlag[h] = 0;
    }

    for (j = 0; j < nLang; j++)
    {
        wcscpy(ref_tmp, ref_ssc);
        tok = wcstok(ref_tmp, DELIMETER);   /* ENUM */
        tok = wcstok(NULL, DELIMETER);      /* MODULE NAME */
        tok = wcstok(NULL, DELIMETER);      /* MAX LENGTH */
        tok = wcstok(NULL, DELIMETER);      /* DESCRIPTION */

        /* change to corresponding language column according to j */
        for (k = 0; k < j + 1; k++)
        {
            tok = wcstok(NULL, DELIMETER);
        }
        LangIndex = ifLanguageUsed(tok);

        if (LangIndex < 0) /* the language is not used in font resource */
            continue;

        mtk_gLanguageFlag[LangIndex] = 1;

        strres[LangIndex].Str = (wchar_t **)malloc(sizeof(wchar_t *) * CurrMaxStringId);
        strres[LangIndex].StrRef = (int *)malloc(sizeof(int) * CurrMaxStringId);
        /* set default value */
        for (l = 0; l < CurrMaxStringId; l++)
        {
            strres[LangIndex].StrRef[l] = -1;
            strres[LangIndex].TotalLength = 0;
        }

        /* set hash_range as maximum id times 1.1(Can be changed) */
        hash_range = (int)(CurrMaxStringId * 1.1);

        /* initialize hash table */
        ht[LangIndex] = (struct HashItem *)malloc(sizeof(struct HashItem) * hash_range);
        for (k = 0; k < hash_range; k++)
        {
            ht[LangIndex][k].next = NULL;
            ht[LangIndex][k].pointer = -1;
        }

        k = 0;
        i = 0;  /* number of Ref(non-duplicate strings, excluding NULL) */
        l = -1; /* number of ID (all strings) */

        while (l < CurrMaxStringId - 1)
        {
            l++;
            nStrId = StrID[l];

            /* check if ID already found in ref_list.txt */
            if (StrLine[nStrId] != 0)
            {
                wcscpy(ref_tmp, ref_all + (StrLine[nStrId] - 1) * g_line_buf_length);
                tok = wcstok(ref_tmp, DELIMETER);
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Module Name */
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Max String Length */
                tok = wcstok(NULL, DELIMETER);  /* skip originally existing Description */
                /* change to corresponding language column according to j */
                for (k = 0; k < j + 1; k++)
                {
                    tok = wcstok(NULL, DELIMETER);

                    /* here possible case for tok to be NULL? */

                    if (tok != NULL && tok[wcslen(tok) - 1] == (wchar_t)'\n')
                    {
                        /* remove carriage-return */
                        tok[wcslen(tok) - 2] = '\0';
                    }
                }
            }
            else
            {
                /* no corresponding line in ref_list.txt */
                tok = (wchar_t *)Str[nStrId];
            }

            /* decise if the read-in string is " " (blank) */
            if (tok != NULL && tok[0] == 20 && tok[1] == 0)
                tok = NULL;
            /* handling NULL read-in string, it's Ref is default value -1 */
            if (tok == NULL)
            {
                /* nothing to be done */
            }
            else if (tok[0] == NO_TRANSLATION_MARKER && tok[1] == 0)
            {
                /* no translation for current language */
                tok = (wchar_t *)Str[nStrId];
            }

            if (tok != NULL)
            {
                /* transform "\""n" */
                Trans(tok, tok);

                /* calculate hash value */
                h = GetHashValue(tok, hash_range);
                if (ht[LangIndex][h].pointer == -1)
                {
                    /* no duplicate hash value */
                    ht[LangIndex][h].pointer = i;
                    ht[LangIndex][h].next = NULL;
                    strres[LangIndex].Str[i] = (wchar_t *)malloc(wcslen(tok) * 2 + 2);
                    wcscpy(strres[LangIndex].Str[i], tok);
                    /* insert the string into the list */
                    strres[LangIndex].StrRef[l] = i;
                    strres[LangIndex].TotalLength += wcslen(tok) + 1;
                    i++;
                }
                else
                {
                    /* 
                     * there are duplicate hash value, check if the string 
                     * is really the same with that has the same hash value
                     */
                    int found = 0;
                    if (wcscmp(tok, strres[LangIndex].Str[ht[LangIndex][h].pointer]) == 0)
                    {
                        /* the two string is the same */
                        strres[LangIndex].StrRef[l] = ht[LangIndex][h].pointer;
                        /* read in next string */
                        continue;
                    }

                    /* 
                     * although the two strings have the same hash value, 
                     * but they are different
                     * compare the strings in linked list...
                     */
                    temp = &ht[LangIndex][h];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                        if (wcscmp(tok, strres[LangIndex].Str[temp->pointer]) == 0)
                        {
                            /* find a identical string in linked list, set the flag on */
                            found = 1;
                            strres[LangIndex].StrRef[l] = temp->pointer;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        /* 
                         * the input string is different with all other 
                         * strings in hash table, add the string in linked 
                         * list
                         */
                        extra = (struct HashItem *)malloc(sizeof(struct HashItem));
                        extra->next = NULL;
                        extra->pointer = i;
                        temp->next = extra;
                        strres[LangIndex].Str[i] = malloc(wcslen(tok) * 2 + 2);
                        wcscpy(strres[LangIndex].Str[i], tok);
                        strres[LangIndex].StrRef[l] = i;
                        strres[LangIndex].TotalLength += wcslen(tok) + 1;
                        i++;
                    }
                    else
                        found = 0; /* reset the flag */
                }
            }
        }

        strres[LangIndex].MaxID = l + 1;
        strres[LangIndex].MaxNum = i;
    }
    result->iLang = mtk_gMaxDeployedLangs;
    result->strres = strres;

    return CurrMaxStringId;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateStrResFile
 * DESCRIPTION
 *  Generate string resource C files
 * PARAMETERS
 *  void
 * RETURNS
 *  Return 0 on success, otherwise, return -1
 *****************************************************************************/
int GenerateStrResFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fout_res = NULL;
    FILE *fout_map = NULL;
    int i = 0, MaxID = 0, str_res_id = 0;
    unsigned short z = 0;
    int start = 0, index_map = 0, index = 0, num_map_search = 0;
    int min_id = 0, max_id = 0;
    struct StrRes *strres = NULL;
    struct StrResSet Strresset;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    FILE *fout_enfb = NULL;
    U32 enfb_size = 0, enfb_offset = 0;
    U32 enfb_str_mem_size, enfb_max_mem_size = 0;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get string table */
    MaxID = GetStrResList(&Strresset);

    /* open output file */
    fout_res = fopen("CustStrRes.c", "wb");
    fout_map = fopen("CustStrMap.c", "wb");
    strres = Strresset.strres;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    fout_enfb = fopen(ENFB_STRING_DATA_FILENAME, "wb");
    if (fout_enfb == NULL)
    {
        printf("File open error (%s) ...!\n", ENFB_STRING_DATA_FILENAME);
        return -1;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* print output file header */
    fprintf(fout_res, "#include \"CustDataRes.h\"\n");
    fprintf(fout_res, "#include \"FontDCl.h\"\n\n\n");
    fprintf(fout_res, "#if (!defined (__MTK_TARGET__))\n\t#define __align(x)\n#endif\n\n\n");
    fprintf(fout_map, "#include \"CustDataRes.h\"\n");

    /* output string resource file */
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        int old_i = i;
        unsigned long nTotalLen = 0;

        if (mtk_gLanguageFlag[i] == 0)
        {
            printf("!!! Please provide translated strings of %s in ref_list.txt !!!\n", mtk_gLanguageArray[i].aLangSSC);
            i = 0;
        }

        /* output language structure title */
        fprintf(fout_res, "__align(4) const CUSTOM_STRING StrRes_%d[] = {\n", old_i + 1);
        fprintf(fout_map, "const CUSTOM_STRING_MAP StrMap_%d[] = {\n", old_i + 1);

    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfb_size = 0;
        enfb_str_mem_size = 0;
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        /* output string resource header */
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        fputc(0, fout_enfb);
        fputc(0, fout_enfb);
        enfb_size += 2;
    #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        fputs("0x00, 0x00,\n", fout_res);
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        /* output CustStrRes.c */
        for (str_res_id = 0; str_res_id < strres[i].MaxNum; str_res_id++)
        {
            unsigned short nStringLen = 0;

        #ifndef __UCS2_ENCODING
            fprintf(fout_res, "\"%s\",\n", strres[i].Str[str_res_id]);
        #else /* __UCS2_ENCODING */
            nStringLen = wcslen(strres[i].Str[str_res_id]);

            for (z = 0; z < nStringLen * 2; ++z)
            {
                unsigned char *abc = (unsigned char*)strres[i].Str[str_res_id];

            #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
                fputc(abc[z], fout_enfb);
                enfb_size++;
            #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
                fprintf(fout_res, "0x%X, ", abc[z]);
            #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            }

        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            fputc(0, fout_enfb);
            fputc(0, fout_enfb);
            enfb_size += 2;
        #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            fputs("0x00, 0x00,\n", fout_res);
        #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    #endif /* __UCS2_ENCODING */
        }

        /* output ENFB string resource header */
    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        fprintf(fout_res,
                "\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
                (U8)255,    /* type */
                (U8)0,      /* reserved */
                (U8)0,      /* reserved */
                (U8)0,      /* reserved */
                (U8)(enfb_offset & 0xFF),
                (U8)((enfb_offset >> 8) & 0xFF),
                (U8)((enfb_offset >> 16) & 0xFF),
                (U8)((enfb_offset >> 24) & 0xFF),
                (U8)(enfb_size & 0xFF),
                (U8)((enfb_size >> 8) & 0xFF),
                (U8)((enfb_size >> 16) & 0xFF),
                (U8)((enfb_size >> 24) & 0xFF));
        enfb_offset += enfb_size;
        enfb_str_mem_size += enfb_size;
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        enfb_size = 0;
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        /* output CustStrMap.c */
        for (str_res_id = 0; str_res_id < strres[i].MaxID; str_res_id++)
        {
            unsigned int nStringLen = 0;
            int iterator = 0;
            wchar_t *wcString;

            if (strres[i].StrRef[str_res_id] == -1)
            {
                nTotalLen = 0;
            }
            else
            {
                nTotalLen = 2;
            }

            for (iterator = 0; iterator < strres[i].StrRef[str_res_id]; iterator++)
            {
                nStringLen = 0;
                nStringLen = wcslen(strres[i].Str[iterator]);
                wcString = NULL;
                nTotalLen += ((nStringLen + 1) * 2);
            }

        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            fputc(((nTotalLen / 2) & 0xFF), fout_enfb);
            fputc((((nTotalLen / 2) >> 8) & 0xFF), fout_enfb);
            fputc((((nTotalLen / 2) >> 16) & 0xFF), fout_enfb);
            fputc((((nTotalLen / 2) >> 24) & 0xFF), fout_enfb);
            enfb_size += 4;
        #else /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            fprintf(fout_map, "\t%ld,\n", nTotalLen / 2);
        #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
        }

    #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
        fprintf(fout_map, "\t%d, %d\n", enfb_offset, enfb_size);
        enfb_offset += enfb_size;
        enfb_str_mem_size += enfb_size;
        if (enfb_str_mem_size > enfb_max_mem_size)
        {
            enfb_max_mem_size = enfb_str_mem_size;
        }
    #endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

        fprintf(fout_res, "};\n");
        fprintf(fout_map, "};\n");
        fprintf(fout_res, "extern const CUSTOM_STRING_MAP StrMap_%d[];\n", old_i + 1);

        i = old_i;
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    {   /* output ENFB string resource header for RESMEM */
        FILE *fp = fopen(ENFB_STRING_HEADER_FILENAME, "w");

        if (fp == NULL)
        {
            printf("File open error (%s) ...!\n", ENFB_STRING_HEADER_FILENAME);
            return -1;
        }
        fprintf(fp, "\n#ifdef __MMI_RESOURCE_ENFB_SUPPORT__\n");
        fprintf(fp, "#define MaxENFBStringSize\t%d\n", enfb_max_mem_size);
        fprintf(fp, "#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */\n\n");
        fclose(fp);
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* output STRMAP_SEARCH array */
    fprintf(fout_res, "const CUSTOM_STRMAP_SEARCH StrMapSearch[] = {\n");
    if (CurrMaxStringId > 0)
    {
        for (str_res_id = 0; str_res_id < MAX_STRING_MAP_SIZE; str_res_id++)
        {
            if (index_map == (int)CurrMaxStringId - 1)
            {
                if (start == 1)
                {
                    /* done */
                    fprintf(fout_res, "\t{%d, %d, %d},\n", min_id, max_id, index);
                    break;
                }
            }

            if (start == 1)
            {
                if (StrID[index_map + 1] == StrID[index_map] + 1)
                {
                    max_id += 1;
                    index_map += 1;
                }
                else
                {
                    start = 0;
                    fprintf(fout_res, "\t{%d, %d, %d},\n", min_id, max_id, index);
                    index_map += 1;
                    index = index_map;
                }
            }
            else
            {
                if (str_res_id == StrID[index_map])
                {
                    start = 1;
                    num_map_search += 1;
                    min_id = str_res_id;
                    max_id = str_res_id;
                }
            }
        }
    }
    fprintf(fout_res, "};\n");

    /* output language list array */
    fprintf(fout_res, "const StringResList mtk_gStringList[] = {\n");
    for (i = 0; i < mtk_gMaxDeployedLangs; i++)
    {
        int old_i = i;

        if (mtk_gLanguageFlag[i] == 0)
        {
            i = 0;
        }

        fprintf(fout_res, "{(CUSTOM_STRING*)StrRes_%d, %d, (CUSTOM_STRING_MAP*)StrMap_%d, %d, (CUSTOM_STRMAP_SEARCH *)StrMapSearch, %d},\n", old_i + 1, strres[i].MaxNum + 1, old_i + 1, strres[i].MaxID + 1, num_map_search);

        i = old_i;
    }
    fprintf(fout_res, "};\n");

    fclose(fout_res);
    fclose(fout_map);
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    fclose(fout_enfb);
#endif

    return 0;
}

