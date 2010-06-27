#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

#define PLMN_CREATOR_MAX_SUPPORT_LANGUAGES 50
#define PLMN_CREATOR_MAX_SUPPORT_RECORDS   700
#define PLMN_CREATOR_MAX_OPNAME_LENGTH     512
#define PLMN_CREATOR_MAX_MCCMNC_LENGTH     512

#define MAX_LENGTH_DISPLAY_NAME            20 /* need to sync with the target definition */

typedef struct
{
    char *opname;
    char *mccmnc;
    char *extname[PLMN_CREATOR_MAX_SUPPORT_LANGUAGES];
} plmn_record_in_unicode;

unsigned char *res_buffer;
unsigned int plmn_num = 0;
unsigned int total_language = 0;
unsigned char language_title[PLMN_CREATOR_MAX_SUPPORT_LANGUAGES][40];   /* 50 languages, 20 words */
plmn_record_in_unicode plmn_array[PLMN_CREATOR_MAX_SUPPORT_RECORDS];


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_unicode_2_ansii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pOutBuffer      [OUT]     
 *  pInBuffer       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
unsigned short plmn_creator_unicode_2_ansii(unsigned char *pOutBuffer, unsigned char *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!((*pInBuffer == 0) && (*(pInBuffer + 1) == 0)))
    {
        *pOutBuffer = *(pInBuffer);
        pInBuffer += 2;
        pOutBuffer++;
        count++;
    }
    *pOutBuffer = 0;
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_find_keyword
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_buffer     [IN]         
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
unsigned long plmn_creator_find_keyword(unsigned char *file_buffer, unsigned long buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *keyword = "plmncreate.exe:";
    char *done = "/* DONE */";
    unsigned long i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < buffer_size - strlen(keyword); i++)
    {
        if (memcmp(file_buffer + i, keyword, strlen(keyword)) == 0)
        {
            for (j = 0;; j++)
            {
                if (*(file_buffer + i + j) == 0x0D && *(file_buffer + i + j + 1) == 0x0A)
                {
                    break;
                }
            }

            /* Avoid to re-add resources */
            if (memcmp(file_buffer + i + j + 2, done, strlen(done)) == 0)
            {
                return 0;
            }
            else
            {
                return i + j + 2;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_netset_plmn_str_2_bcd_short
 * DESCRIPTION
 *  
 * PARAMETERS
 *  plmn        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
unsigned long mmi_netset_plmn_str_2_bcd_short(unsigned char *plmn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned long b1 = 0, b2 = 0, b3 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b1 = (*plmn - 0x30) + ((*(plmn + 1) - 0x30) << 4);
    b2 = (*(plmn + 2) - 0x30) + (*(plmn + 5) == 0 ? 0xF0 : ((*(plmn + 5) - 0x30) << 4));
    b3 = (*(plmn + 3) - 0x30) + ((*(plmn + 4) - 0x30) << 4);
    return b1 + (b2 << 8) + (b3 << 16);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_unicode_strlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  unicode_string      [IN]     
 * RETURNS
 *  
 *****************************************************************************/
unsigned short plmn_creator_unicode_strlen(unsigned char *unicode_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!(*(unicode_string + i) == 0 && *(unicode_string + i + 1) == 0))
    {
        i += 2;
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_CustResDef_h
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_CustResDef_h(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, read_size, insert_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    /* if( (fptr = fopen("..\\CustomerInc\\CustResDef.h", "rb")) == NULL) */
    if ((fptr = fopen("..\\..\\MMI\\MiscFramework\\MiscFrameworkInc\\PlmnEnum.h", "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    insert_pos = plmn_creator_find_keyword(read_file, read_size);

    if (insert_pos == 0)
    {
        return;
    }

    /* update file */
    /* fptr = fopen("..\\CustomerInc\\CustResDef.h", "wb"); */
    fptr = fopen("..\\..\\MMI\\MiscFramework\\MiscFrameworkInc\\PlmnEnum.h", "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    fprintf(fptr, "/* DONE */\n");

    for (i = 0; i < plmn_num; i++)
    {
        if (i == 0)
        {
            fprintf(fptr, "   STR_PLMN_NAME_%d = SIM_DETECTION_BASE + 300,\n", i + 1);
        }
        else if (i == plmn_num - 1)
        {
            fprintf(fptr, "   STR_PLMN_NAME_%d\n", i + 1);
        }
        else
        {
            fprintf(fptr, "   STR_PLMN_NAME_%d,\n", i + 1);
        }
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_Res_MiscFramework_c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_Res_MiscFramework_c(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, read_size, insert_pos;
    unsigned char des_opname[PLMN_CREATOR_MAX_OPNAME_LENGTH], des_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen("..\\Res_MMI\\Res_MiscFramework.c", "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    insert_pos = plmn_creator_find_keyword(read_file, read_size);

    if (insert_pos == 0)
    {
        return;
    }

    /* update file */
    fptr = fopen("..\\Res_MMI\\Res_MiscFramework.c", "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    fprintf(fptr, "/* DONE */\n");

    for (i = 0; i < plmn_num; i++)
    {
        plmn_creator_unicode_2_ansii(des_opname, plmn_array[i].opname);
        plmn_creator_unicode_2_ansii(des_mccmnc, plmn_array[i].mccmnc);
        fprintf(
            fptr,
            "   ADD_APPLICATION_STRING2(STR_PLMN_NAME_%d,\"%s\",\"PLMN Name %s.\");\n",
            i + 1,
            des_opname,
            des_mccmnc);
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_CustMiscData_c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_CustMiscData_c(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j = 0, k = 0, read_size, insert_pos;
    unsigned char des_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH];
    unsigned short separator_template[] = {0x002C, 0x0020};
    unsigned short ending_template[] = {0x0000};
    unsigned char tmp_mccmnc[PLMN_CREATOR_MAX_MCCMNC_LENGTH * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    /* if( (fptr = fopen("..\\CustResource\\CustMiscData.c", "rb")) == NULL) */
    if ((fptr = fopen("..\\..\\MMI\\MiscFramework\\MiscFrameworkSrc\\PlmnName.c", "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    insert_pos = plmn_creator_find_keyword(read_file, read_size);

    if (insert_pos == 0)
    {
        return;
    }

    /* update file */
    /* fptr = fopen("..\\CustResource\\CustMiscData.c", "wb"); */
    fptr = fopen("..\\..\\MMI\\MiscFramework\\MiscFrameworkSrc\\PlmnName.c", "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    fprintf(fptr, "/* DONE */\n");

    for (i = 0; i < plmn_num; i++)
    {
        for (j = 0;; j += 2)
        {
            if (memcmp((void*)ending_template, plmn_array[i].mccmnc + j, 2) == 0)
            {
                break;
            }
            if (memcmp((void*)separator_template, plmn_array[i].mccmnc + j, 4) != 0)
            {
                tmp_mccmnc[k] = plmn_array[i].mccmnc[j];
                tmp_mccmnc[k + 1] = plmn_array[i].mccmnc[j + 1];
                k += 2;
            }
            else
            {
                tmp_mccmnc[k] = 0;
                tmp_mccmnc[k + 1] = 0;
                plmn_creator_unicode_2_ansii(des_mccmnc, tmp_mccmnc);
                fprintf(fptr, "   {0x%06x, %d},\n", mmi_netset_plmn_str_2_bcd_short(des_mccmnc), i);
                k = 0;
                j += 2;
            }
        }
        tmp_mccmnc[k] = 0;
        tmp_mccmnc[k + 1] = 0;
        plmn_creator_unicode_2_ansii(des_mccmnc, tmp_mccmnc);
        fprintf(fptr, "   {0x%06x, %d},\n", mmi_netset_plmn_str_2_bcd_short(des_mccmnc), i);
        k = 0;
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_modify_Ref_list_txt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_modify_Ref_list_txt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j = 0, read_size, insert_pos;
    char *keyword = (char*)L"##number";
    unsigned short tab_template[] = {0x0009};
    unsigned short new_line_template[] = {0x000D, 0x000A};
    unsigned short max_display_lenght = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen("..\\CustResource\\Ref_list.txt", "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* find keyword to insert strings in next line */
    /* insert_pos = plmn_creator_find_keyword(read_file, read_size); */
    for (i = 0; i < read_size - strlen("##number") * 2; i++)
    {
        if (memcmp(read_file + i, keyword, strlen("##number") * 2) == 0)
        {
            insert_pos = i;
            break;
        }
    }

    /* update file */
    fptr = fopen("..\\CustResource\\Ref_list.txt", "wb");
    fwrite(read_file, 1, insert_pos, fptr);

    for (i = 0; i < plmn_num; i++)
    {
        /* fwprintf(fptr, L"STR_PLMN_NAME_%d    Undefined       %d      PLMN Name %s    ", i+1, plmn_creator_unicode_strlen(plmn_array[i].opname)/2, plmn_array[i].mccmnc); */
        fwprintf(
            fptr,
            L"STR_PLMN_NAME_%d	Undefined	%d	PLMN Name %c%c%c%c%c	",
            i + 1,
            plmn_creator_unicode_strlen(plmn_array[i].opname) / 2,
            *plmn_array[i].mccmnc,
            *(plmn_array[i].mccmnc + 2),
            *(plmn_array[i].mccmnc + 4),
            *(plmn_array[i].mccmnc + 6),
            *(plmn_array[i].mccmnc + 8));

        max_display_lenght =
            (plmn_creator_unicode_strlen(plmn_array[i].opname) / 2 >= MAX_LENGTH_DISPLAY_NAME)
            ? MAX_LENGTH_DISPLAY_NAME - 1
            : plmn_creator_unicode_strlen(plmn_array[i].opname) / 2;
        fwrite((void*)plmn_array[i].opname, 1, max_display_lenght * 2, fptr);

        for (j = 0; j < total_language; j++)
        {
            fwrite((void*)tab_template, 1, sizeof(tab_template), fptr);
            if (plmn_array[i].extname[j] == NULL)
            {
                max_display_lenght =
                    (plmn_creator_unicode_strlen(plmn_array[i].opname) / 2 >= MAX_LENGTH_DISPLAY_NAME)
                    ? MAX_LENGTH_DISPLAY_NAME - 1
                    : plmn_creator_unicode_strlen(plmn_array[i].opname) / 2;
                fwrite((void*)plmn_array[i].opname, 1, max_display_lenght * 2, fptr);
            }
            else
            {
                max_display_lenght =
                    (plmn_creator_unicode_strlen(plmn_array[i].extname[j]) / 2 >= MAX_LENGTH_DISPLAY_NAME) 
                    ? MAX_LENGTH_DISPLAY_NAME - 1
                    : plmn_creator_unicode_strlen(plmn_array[i].extname[j]) / 2;
                fwrite((void*)plmn_array[i].extname[j], 1, max_display_lenght * 2, fptr);
            }
        }
        fwrite((void*)tab_template, 1, sizeof(tab_template), fptr);
        fwrite((void*)new_line_template, 1, sizeof(new_line_template), fptr);
    }

    fwrite(read_file + insert_pos, 1, read_size - insert_pos, fptr);
    fclose(fptr);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_read_op_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_read_op_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char tmp_buffer[PLMN_CREATOR_MAX_OPNAME_LENGTH];
    unsigned long res_size, count = 0, i, j;
    unsigned short opname_template[] = {0x006F, 0x0070, 0x006E, 0x0061, 0x006D, 0x0065, 0x003D};
    unsigned short mccmnc_template[] = {0x006D, 0x0063, 0x0063, 0x006D, 0x006E, 0x0063, 0x003D};
    unsigned short area_template[] = {0x0061, 0x0072, 0x0065, 0x0061, 0x003D};
    unsigned short new_line_template[] = {0x000D, 0x000A};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen("..\\CustResource\\plmnlist.txt", "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    res_size = ftell(fptr);
    res_buffer = malloc(res_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(res_buffer, 1, res_size, fptr);
    fclose(fptr);

    /* skip unicode file header */
    res_buffer += 2;
    res_size -= 2;

    do
    {
        /* read one line */
        for (i = 0;; i++)
        {
            if (memcmp((void*)new_line_template, res_buffer + count + i, 4) != 0)
            {
                *(tmp_buffer + i) = *(res_buffer + count + i);
            }
            else
            {
                memset(res_buffer + count + i, 0, 4);
                break;
            }
        }

        if (i == 0)
        {
            count += 4;
            continue;
        }

        if (memcmp(area_template, tmp_buffer, sizeof(area_template)) == 0)
        {
            count += (i + 4);
            continue;
        }
        if (memcmp(opname_template, tmp_buffer, sizeof(opname_template)) == 0)
        {
            plmn_num++;
            plmn_array[plmn_num - 1].opname = res_buffer + count + sizeof(opname_template);
        }
        else if (memcmp(mccmnc_template, tmp_buffer, sizeof(mccmnc_template)) == 0)
        {
            plmn_array[plmn_num - 1].mccmnc = res_buffer + count + sizeof(mccmnc_template);
        }
        else
        {
            for (j = 0; j < total_language; j++)
            {
                if (memcmp(language_title[j], tmp_buffer, plmn_creator_unicode_strlen(language_title[j])) == 0)
                {
                    plmn_array[plmn_num - 1].extname[j] =
                        res_buffer + count + plmn_creator_unicode_strlen(language_title[j]) + 2;
                    break;
                }
            }
        }

        count += (i + 4);
    } while (count < res_size);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_get_supported_languages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_get_supported_languages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fptr;
    unsigned char *read_file;
    unsigned long i = 0, j = 0, k = 0, read_size;
    unsigned short new_line_template[] = {0x000D, 0x000A};
    unsigned short tab_template[] = {0x0009};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    if ((fptr = fopen("..\\CustResource\\Ref_list.txt", "rb")) == NULL)
    {
        return;
    }

    /* get file size */
    fseek(fptr, 0, SEEK_END);
    read_size = ftell(fptr);
    read_file = malloc(read_size);

    /* read it to the buffer */
    fseek(fptr, 0, SEEK_SET);
    fread(read_file, 1, read_size, fptr);
    fclose(fptr);

    /* get total languages */
    for (i = 0;; i++)
    {
        if (memcmp((void*)new_line_template, read_file + i, 4) == 0)
        {
            i += 4;
            break;
        }
    }

    do
    {
        if (memcmp((void*)tab_template, read_file + i, 2) == 0)
        {
            j++;
        }
        /* else */
        i++;
    }
    while (j < 5);  /* skip Enum Value, Module Name, Max String Length, Description, English */

    i += 1;
    j = 0;

    do
    {
        if (memcmp((void*)tab_template, read_file + i, 2) == 0)
        {
            memset(language_title[j] + k, 0, 2);
            j++;
            k = 0;
            total_language++;
        }
        else
        {
            memcpy(language_title[j] + k, read_file + i, 2);
            k += 2;
        }
        i += 2;
    }
    while (memcmp((void*)new_line_template, read_file + i, 4) != 0);

    free(read_file);
}


/*****************************************************************************
 * FUNCTION
 *  plmn_creator_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plmn_creator_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < PLMN_CREATOR_MAX_SUPPORT_RECORDS; i++)
    {
        for (j = 0; j < PLMN_CREATOR_MAX_SUPPORT_LANGUAGES; j++)
        {
            plmn_array[i].extname[j] = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    printf("plmn create");

    plmn_creator_init();
    plmn_creator_get_supported_languages();
    plmn_creator_read_op_resource();

    plmn_creator_modify_CustResDef_h();
    printf("..");
    plmn_creator_modify_Res_MiscFramework_c();
    printf("..");
    plmn_creator_modify_CustMiscData_c();
    printf("..");
    plmn_creator_modify_Ref_list_txt();

    free(res_buffer - 2);
    printf("done!\n");
}

